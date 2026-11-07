/* Tools/userspace/dxt_reach_probe.c - which GL calls reach GLDriver dxtCompressImage? Run the program under a copy of the GLD image whose dxtCompressImage entry is
 * patched to exit(77): bytes 38 00 00 01 38 60 00 4d 44 00 00 02 (li r0,1; li r3,77; sc) at the nm offset (file offset == vm address in this image), through gld_redirect
 * (GLD_REDIRECT_FROM/TO, DYLD_INSERT_LIBRARIES). It prints a REACHED line per variant that exits 77. Positive control: patch gldTextureMakeResident the same way (85 lines).
 * Result of Nov 6 (issue #226): dxtCompressImage is reached by none of the ~300 variants. Build: gcc -arch ppc -w -std=gnu99 -o dxt_reach_probe dxt_reach_probe.c -framework OpenGL -framework ApplicationServices */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
static void draw(void){ glEnable(GL_TEXTURE_2D); glTexEnvi(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE); glBegin(GL_QUADS);
 glTexCoord2f(0,0);glVertex2f(-1,-1);glTexCoord2f(1,0);glVertex2f(1,-1);glTexCoord2f(1,1);glVertex2f(1,1);glTexCoord2f(0,1);glVertex2f(-1,1);glEnd(); glFinish(); }
int main(void){
 GLenum ifm[]={0x83F0,0x83F1,0x83F2,0x83F3,0x84ED,0x84EE}; const char*in[]={"DXT1","DXT1A","DXT3","DXT5","COMPRESSED_RGB_ARB","COMPRESSED_RGBA_ARB"};
 GLenum sf[]={GL_RGBA,GL_RGB,GL_BGRA,GL_BGR,GL_LUMINANCE,GL_ALPHA}; const char*sn[]={"RGBA","RGB","BGRA","BGR","LUM","ALPHA"};
 GLenum st[]={GL_UNSIGNED_BYTE,GL_UNSIGNED_SHORT_5_6_5,GL_UNSIGNED_SHORT_4_4_4_4,GL_FLOAT}; const char*tn[]={"UBYTE","565","4444","FLOAT"};
 static unsigned char px[64*64*16]; int a,b,c,mode,i;
 for(i=0;i<(int)sizeof px;i++) px[i]=rand()>>7;
 setvbuf(stdout,0,_IONBF,0);
 for(mode=0;mode<5;mode++) for(a=0;a<6;a++) for(b=0;b<6;b++) for(c=0;c<4;c++){
   const char*md[]={"TexImage","TexImage+mip(GENERATE_MIPMAP)","TexImage+draw","TexSubImage","CopyTexImage"};
   pid_t p; int s;
   if((mode>=1&&mode<=2&&c>0)||(mode>=3&&(b>0||c>0))) continue;
   fflush(stdout); p=fork();
   if(p==0){
     CGLPixelFormatObj pf; GLint n; CGLContextObj ctx; CGLPBufferObj pb; GLuint t;
     CGLPixelFormatAttribute at[]={kCGLPFAPBuffer,kCGLPFAAccelerated,kCGLPFANoRecovery,kCGLPFAColorSize,32,0};
     CGLChoosePixelFormat(at,&pf,&n); CGLCreateContext(pf,0,&ctx); CGLCreatePBuffer(32,32,GL_TEXTURE_RECTANGLE_EXT,GL_RGBA,0,&pb); CGLSetCurrentContext(ctx); CGLSetPBuffer(ctx,pb,0,0,0);
     glViewport(0,0,32,32); glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
     glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
     if(mode==1) glTexParameteri(GL_TEXTURE_2D,GL_GENERATE_MIPMAP,GL_TRUE);
     if(mode==4){ glClearColor(.3f,.6f,.9f,1); glClear(GL_COLOR_BUFFER_BIT); glCopyTexImage2D(GL_TEXTURE_2D,0,ifm[a],0,0,16,16,0); }
     else if(mode==3){ glTexImage2D(GL_TEXTURE_2D,0,ifm[a],16,16,0,GL_RGBA,GL_UNSIGNED_BYTE,px); glTexSubImage2D(GL_TEXTURE_2D,0,4,4,8,8,sf[b],GL_UNSIGNED_BYTE,px); }
     else glTexImage2D(GL_TEXTURE_2D,0,ifm[a],16,16,0,sf[b],st[c],px);
     if(mode==2||mode==3||mode==4||mode==1) draw();
     glFinish(); _exit(0);
   }
   waitpid(p,&s,0);
   if(WIFEXITED(s)&&WEXITSTATUS(s)==77) printf("REACHED: %s internal=%s src=%s type=%s\n",md[mode],in[a],sn[b],tn[c]);
 }
 printf("done\n"); return 0; }
