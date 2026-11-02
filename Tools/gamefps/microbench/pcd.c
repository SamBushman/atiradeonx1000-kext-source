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
    RUN("arrays 3tri", 20000, glDrawArrays(GL_TRIANGLES,0,9));
    RUN("arrays 100tri", 5000, glDrawArrays(GL_TRIANGLES,0,300));
    RUN("elements 300idx ushort", 5000, glDrawElements(GL_TRIANGLES,300,GL_UNSIGNED_SHORT,idx));
    RUN("elements 900idx ushort", 3000, glDrawElements(GL_TRIANGLES,900,GL_UNSIGNED_SHORT,idx));
    glEnableClientState(GL_COLOR_ARRAY); glColorPointer(4,GL_FLOAT,0,cols);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY); glTexCoordPointer(2,GL_FLOAT,0,tcs); glEnable(GL_TEXTURE_2D);
    RUN("elements col+tex 300", 5000, glDrawElements(GL_TRIANGLES,300,GL_UNSIGNED_SHORT,idx));
    { int k=0; RUN("tex rebind each draw", 5000, (glBindTexture(GL_TEXTURE_2D,tex[(k++)&1]), glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_SHORT,idx))); }
    { int k=0; glEnable(GL_BLEND); RUN("blend toggle + draw", 5000, (glBlendFunc((k&1)?GL_ONE:GL_SRC_ALPHA,(k&1)?GL_ONE:GL_ONE_MINUS_SRC_ALPHA), k++, glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_SHORT,idx))); glDisable(GL_BLEND); }
    glDisableClientState(GL_COLOR_ARRAY); glDisableClientState(GL_TEXTURE_COORD_ARRAY); glDisable(GL_TEXTURE_2D);
    { float p[4]={1,1,1,0}; int k=0; glEnable(GL_LIGHTING); glEnable(GL_LIGHT0); glEnableClientState(GL_NORMAL_ARRAY); glNormalPointer(GL_FLOAT,0,verts);
      RUN("lighting move light", 3000, (p[0]=(k++&7)*0.1f+0.2f, glLightfv(GL_LIGHT0,GL_POSITION,p), glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_SHORT,idx)));
      glDisable(GL_LIGHTING); glDisableClientState(GL_NORMAL_ARRAY); }
    { int k=0; RUN("matrix change + draw", 5000, (glMatrixMode(GL_MODELVIEW), glLoadIdentity(), glRotatef((k++&63),0,0,1), glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_SHORT,idx))); glLoadIdentity(); }
    RUN("immediate quad", 20000, (glBegin(GL_QUADS), glVertex2f(-.5f,-.5f), glVertex2f(.5f,-.5f), glVertex2f(.5f,.5f), glVertex2f(-.5f,.5f), glEnd()));
    { const char *vp="!!ARBvp1.0\nPARAM c=program.env[0];\nPARAM m[4]={state.matrix.mvp};\nDP4 result.position.x,m[0],vertex.position;\nDP4 result.position.y,m[1],vertex.position;\nDP4 result.position.z,m[2],vertex.position;\nDP4 result.position.w,m[3],vertex.position;\nMOV result.color,c;\nEND\n";
      const char *fp="!!ARBfp1.0\nPARAM c=program.env[1];\nMUL result.color,fragment.color,c;\nEND\n";
      GLuint ids[2]; glGenProgramsARB(2,ids);
      glBindProgramARB(GL_VERTEX_PROGRAM_ARB,ids[0]); glProgramStringARB(GL_VERTEX_PROGRAM_ARB,GL_PROGRAM_FORMAT_ASCII_ARB,strlen(vp),vp);
      glBindProgramARB(GL_FRAGMENT_PROGRAM_ARB,ids[1]); glProgramStringARB(GL_FRAGMENT_PROGRAM_ARB,GL_PROGRAM_FORMAT_ASCII_ARB,strlen(fp),fp);
      glEnable(GL_VERTEX_PROGRAM_ARB); glEnable(GL_FRAGMENT_PROGRAM_ARB); int k=0;
      RUN("arb prog env param change", 5000, (glProgramEnvParameter4fARB(GL_VERTEX_PROGRAM_ARB,0,(k&3)*0.25f,1,1,1), glProgramEnvParameter4fARB(GL_FRAGMENT_PROGRAM_ARB,1,1,(k++&3)*.25f,1,1), glDrawElements(GL_TRIANGLES,30,GL_UNSIGNED_SHORT,idx)));
      glDisable(GL_VERTEX_PROGRAM_ARB); glDisable(GL_FRAGMENT_PROGRAM_ARB); }
    return 0;
}
