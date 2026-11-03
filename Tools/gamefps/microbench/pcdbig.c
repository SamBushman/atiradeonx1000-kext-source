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
#define NV 30000
static float verts[NV*3]; static float cols[NV*4]; static unsigned char ucols[NV*4]; static float tcs[NV*2]; static float tcs2[NV*2]; static float nrm[NV*3]; static unsigned short idx[NV*3];
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
    int i; for (i=0;i<NV;i++){ verts[i*3]=5.0f+(i%30)*0.001f; verts[i*3+1]=5.0f+(i/30%30)*0.001f; verts[i*3+2]=0; cols[i*4]=cols[i*4+1]=cols[i*4+2]=cols[i*4+3]=1; ucols[i*4]=ucols[i*4+1]=ucols[i*4+2]=ucols[i*4+3]=255; tcs[i*2]=(i%30)/30.0f; tcs[i*2+1]=(i/30%30)/30.0f; tcs2[i*2]=tcs[i*2]; tcs2[i*2+1]=tcs[i*2+1]; nrm[i*3]=0; nrm[i*3+1]=0; nrm[i*3+2]=1; }
    for (i=0;i<NV*3 && i<65535;i++) idx[i]=i%NV;
    GLuint tex[2]; glGenTextures(2,tex); unsigned char px[16*16*4]; memset(px,200,sizeof px);
    for (i=0;i<2;i++){ glBindTexture(GL_TEXTURE_2D,tex[i]); glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,16,16,0,GL_RGBA,GL_UNSIGNED_BYTE,px); glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); }
    glEnable(GL_TEXTURE_2D);
    glEnableClientState(GL_VERTEX_ARRAY); glVertexPointer(3,GL_FLOAT,0,verts);
    int sizes[3]={300,3000,30000};
    int si;
    for (si=0;si<3;si++){ int n=sizes[si]; int calls=(si==0?4000:(si==1?800:80));
      char nm[64];
      sprintf(nm,"pos only drre %d",n); RUN(nm, calls, glDrawRangeElements(GL_TRIANGLES,0,n-1,n/3*3,GL_UNSIGNED_SHORT,idx));
      glEnableClientState(GL_COLOR_ARRAY); glColorPointer(4,GL_UNSIGNED_BYTE,0,ucols);
      glEnableClientState(GL_TEXTURE_COORD_ARRAY); glTexCoordPointer(2,GL_FLOAT,0,tcs);
      sprintf(nm,"pos+ubyte col+tex drre %d",n); RUN(nm, calls, glDrawRangeElements(GL_TRIANGLES,0,n-1,n/3*3,GL_UNSIGNED_SHORT,idx));
      glColorPointer(4,GL_FLOAT,0,cols);
      sprintf(nm,"pos+float col+tex drre %d",n); RUN(nm, calls, glDrawRangeElements(GL_TRIANGLES,0,n-1,n/3*3,GL_UNSIGNED_SHORT,idx));
      glDisableClientState(GL_COLOR_ARRAY);
      glEnableClientState(GL_NORMAL_ARRAY); glNormalPointer(GL_FLOAT,0,nrm);
      glClientActiveTexture(GL_TEXTURE1); glEnableClientState(GL_TEXTURE_COORD_ARRAY); glTexCoordPointer(2,GL_FLOAT,0,tcs2); glClientActiveTexture(GL_TEXTURE0);
      sprintf(nm,"pos+nrm+tex0+tex1 drre %d",n); RUN(nm, calls, glDrawRangeElements(GL_TRIANGLES,0,n-1,n/3*3,GL_UNSIGNED_SHORT,idx));
      glClientActiveTexture(GL_TEXTURE1); glDisableClientState(GL_TEXTURE_COORD_ARRAY); glClientActiveTexture(GL_TEXTURE0);
      glDisableClientState(GL_NORMAL_ARRAY); glDisableClientState(GL_TEXTURE_COORD_ARRAY);
    }
    return 0;
}
