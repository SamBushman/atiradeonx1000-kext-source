/* cfwarm.c: per fresh pbuffer context, time K successive (glClear+glFlush) and K (100-tri draw + glFlush); report median per ordinal. */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#define W 256
#define H 256
#define K 6
static double now_us(void){struct timeval tv;gettimeofday(&tv,NULL);return tv.tv_sec*1e6+tv.tv_usec;}
static int cmp(const void*a,const void*b){double x=*(double*)a,y=*(double*)b;return x<y?-1:x>y;}
int main(int argc,char**argv){
  int N=argc>1?atoi(argv[1]):500; int i,k,q;
  static double tc[K][4000], td[K][4000];
  CGLPixelFormatAttribute attrs[]={kCGLPFAPBuffer,kCGLPFAAccelerated,kCGLPFANoRecovery,kCGLPFAColorSize,32,0};
  for(i=0;i<N;i++){
    CGLPixelFormatObj pf; GLint np; CGLContextObj ctx; CGLPBufferObj pb;
    CGLChoosePixelFormat(attrs,&pf,&np); CGLCreateContext(pf,NULL,&ctx); CGLDestroyPixelFormat(pf);
    CGLCreatePBuffer(W,H,GL_TEXTURE_RECTANGLE_EXT,GL_RGBA,0,&pb); CGLSetCurrentContext(ctx); CGLSetPBuffer(ctx,pb,0,0,0);
    glViewport(0,0,W,H);
    for(k=0;k<K;k++){ double t0=now_us(); glClearColor(0.25f,0.5f,0.75f,1.0f); glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); glFlush(); tc[k][i]=now_us()-t0; }
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-1,1,-1,1,-1,1); glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    for(k=0;k<K;k++){ double t0=now_us();
      for(q=0;q<100;q++){ glBegin(GL_TRIANGLES); glColor3f(1,0,0); glVertex2f(-0.8f,-0.8f); glColor3f(0,1,0); glVertex2f(0.8f,-0.8f); glColor3f(0,0,1); glVertex2f(0.0f,0.8f); glEnd(); }
      glFlush(); td[k][i]=now_us()-t0; }
    CGLSetCurrentContext(NULL); CGLDestroyContext(ctx); CGLDestroyPBuffer(pb);
  }
  for(k=0;k<K;k++){ qsort(tc[k],N,sizeof(double),cmp); printf("clear+flush #%d median %.0f us\n",k+1,tc[k][N/2]); }
  for(k=0;k<K;k++){ qsort(td[k],N,sizeof(double),cmp); printf("draw100+flush #%d median %.0f us\n",k+1,td[k][N/2]); }
  return 0; }
