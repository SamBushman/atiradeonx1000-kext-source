/* pcd.c - CPU cost of GL draw paths (no per-draw glFinish): total wall time of N draws, GPU kept trivial (64x64 pbuffer). Build: gcc -arch ppc -std=gnu99 -w -o pcd pcd.c -framework OpenGL */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mach/mach_time.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glext.h>
static double tk;
static double now_us(void) { return (double)mach_absolute_time() * tk; }
static int cmpd(const void *a, const void *b) { double x=*(const double*)a, y=*(const double*)b; return x<y?-1:x>y; }
static float verts[300*3]; static float cols[300*4]; static float tcs[300*2]; static unsigned short idx[900];
static const char *only; static int reps=7, mul=1;
#define REPS 40
#define RUN(NAME, N, BODY) if(!only||strstr(NAME,only)) do { double s[REPS]; int r,i; for (r=-1;r<reps;r++){ double t0=now_us(); for(i=0;i<(N)*mul;i++){ BODY; } double t1=now_us(); glFinish(); if(r>=0) s[r]=(t1-t0)/((N)*mul); } qsort(s,reps,sizeof(double),cmpd); printf("PCD %-28s median %.3f us/draw  min %.3f max %.3f\n", NAME, s[reps/2], s[0], s[reps-1]); } while(0)
static void mips_c(int F,int N,unsigned char *big){ int L; for(L=0;L<N;L++){ int sz=(N==11?1024:512)>>L; if(sz<4) sz=4; glCompressedTexImage2DARB(GL_TEXTURE_2D,L,F,sz,sz,0,(F==0x83F0?sz*sz/2:sz*sz),big);} }
int main(void) {
    only=getenv("PCD_ONLY"); if(getenv("PCD_REPS")) reps=atoi(getenv("PCD_REPS")); if(getenv("PCD_MUL")) mul=atoi(getenv("PCD_MUL"));
    mach_timebase_info_data_t tb; mach_timebase_info(&tb); tk = (double)tb.numer/tb.denom/1000.0;
    setvbuf(stdout,NULL,_IONBF,0);
    CGLPixelFormatObj pf; GLint np=0;
    CGLPixelFormatAttribute at[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize,32, kCGLPFADepthSize,16, kCGLPFAStencilSize,8, (CGLPixelFormatAttribute)0 };
    if (CGLChoosePixelFormat(at,&pf,&np)||!pf) return 1;
    CGLContextObj ctx; if (CGLCreateContext(pf,NULL,&ctx)) return 1;
    CGLPBufferObj pb; if (CGLCreatePBuffer(64,64,GL_TEXTURE_RECTANGLE_EXT,GL_RGBA,0,&pb)) return 1;
    CGLSetCurrentContext(ctx); CGLSetPBuffer(ctx,pb,0,0,0);
    glViewport(0,0,64,64); glDisable(GL_DEPTH_TEST);
    int i; for (i=0;i<300;i++){ verts[i*3]=-0.9f+(i%30)*0.06f; verts[i*3+1]=-0.9f+(i/30)*0.18f; verts[i*3+2]=0; cols[i*4]=cols[i*4+1]=cols[i*4+2]=cols[i*4+3]=1; tcs[i*2]=(i%30)/30.0f; tcs[i*2+1]=(i/30)/10.0f; }
    for (i=0;i<900;i++) idx[i]=(i*7)%300;
    GLuint tex[2]; glGenTextures(2,tex); unsigned char px[16*16*4]; memset(px,200,sizeof px);
    for (i=0;i<2;i++){ glBindTexture(GL_TEXTURE_2D,tex[i]); glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,16,16,0,GL_RGBA,GL_UNSIGNED_BYTE,px); glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); }
    glEnableClientState(GL_VERTEX_ARRAY); glVertexPointer(3,GL_FLOAT,0,verts);
    glColor4f(1,1,1,1);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY); glTexCoordPointer(2,GL_FLOAT,0,tcs); glEnable(GL_TEXTURE_2D);
    { static unsigned char big[256*256*4]; memset(big,77,sizeof big); GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
      RUN("texImage2D 256 new", 400, (glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,256,256,0,GL_RGBA,GL_UNSIGNED_BYTE,big), glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_SHORT,idx)));
      RUN("texSubImage2D 256", 400, (glTexSubImage2D(GL_TEXTURE_2D,0,0,0,256,256,GL_RGBA,GL_UNSIGNED_BYTE,big), glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_SHORT,idx)));
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
      RUN("texImage2D 256 mipgen", 100, (glTexParameteri(GL_TEXTURE_2D,GL_GENERATE_MIPMAP,GL_TRUE), glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,256,256,0,GL_RGBA,GL_UNSIGNED_BYTE,big), glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_SHORT,idx)));
      glTexParameteri(GL_TEXTURE_2D,GL_GENERATE_MIPMAP,GL_FALSE);
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
      RUN("gen+upload+delete tex", 300, (glGenTextures(1,&t), glBindTexture(GL_TEXTURE_2D,t), glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR), glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,64,64,0,GL_RGBA,GL_UNSIGNED_BYTE,big), glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_SHORT,idx), glDeleteTextures(1,&t)));
    }
    glDisable(GL_TEXTURE_2D); glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    glEnable(GL_TEXTURE_2D); glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    { static unsigned char big[2048*2048*4]; int j; for(j=0;j<(int)sizeof big;j++) big[j]=(unsigned char)(j*7+(j>>8)); GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
      glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR); glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAX_ANISOTROPY_EXT,8);
      int L;
      #define MIPS_C(F,BYTES0,N) mips_c(F,N,big)
      RUN("DXT1 1024 mip chain draw", 40, (MIPS_C(0x83F0,0,11), glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_SHORT,idx)));
      RUN("DXT5 1024 mip chain draw", 40, (MIPS_C(0x83F3,0,11), glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_SHORT,idx)));
      RUN("DXT1 2048 base only", 20, (glCompressedTexImage2DARB(GL_TEXTURE_2D,0,0x83F0,2048,2048,0,2048*2048/2,big), glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_SHORT,idx)));
      RUN("RGBA 1024 base only", 20, (glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,1024,1024,0,GL_RGBA,GL_UNSIGNED_BYTE,big), glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_SHORT,idx)));
      RUN("BGRA rev 1024 base only", 20, (glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,1024,1024,0,GL_BGRA,GL_UNSIGNED_INT_8_8_8_8_REV,big), glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_SHORT,idx)));
      RUN("texSub RGBA 1024", 20, (glTexSubImage2D(GL_TEXTURE_2D,0,0,0,1024,1024,GL_RGBA,GL_UNSIGNED_BYTE,big), glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_SHORT,idx)));
      RUN("gen+DXT1 512 chain+del", 40, (glGenTextures(1,&t), glBindTexture(GL_TEXTURE_2D,t), glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR), MIPS_C(0x83F0,0,10), glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_SHORT,idx), glDeleteTextures(1,&t)));
    }
    return 0;
}
