#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
static void die(const char *w, CGLError e){fprintf(stderr,"FAIL %s: %s\n",w,CGLErrorString(e));}
#define W 32
#define H 32
int main(void){
    setvbuf(stdout,NULL,_IONBF,0);
    CGLPixelFormatObj pf; GLint npix=0;
    CGLPixelFormatAttribute attrs[]={kCGLPFAPBuffer,kCGLPFAAccelerated,kCGLPFANoRecovery,kCGLPFAColorSize,32,(CGLPixelFormatAttribute)0};
    CGLError err=CGLChoosePixelFormat(attrs,&pf,&npix); if(err||npix==0||!pf){die("CPF",err);return 1;}
    CGLContextObj ctx=NULL; err=CGLCreateContext(pf,NULL,&ctx); if(err){die("CC",err);return 1;}
    CGLDestroyPixelFormat(pf);
    CGLPBufferObj pbuf=NULL; err=CGLCreatePBuffer(W,H,GL_TEXTURE_RECTANGLE_EXT,GL_RGBA,0,&pbuf); if(err){die("CP",err);return 1;}
    err=CGLSetCurrentContext(ctx); if(err){die("SC",err);return 1;}
    err=CGLSetPBuffer(ctx,pbuf,0,0,0); if(err){die("SP",err);return 1;}
    glViewport(0,0,W,H);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    GLubyte tex[8*4];
    int i; for(i=0;i<8;i++){tex[i*4]=255*(7-i)/7; tex[i*4+1]=255*i/7; tex[i*4+2]=0; tex[i*4+3]=255;}
    GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_1D,t);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage1D(GL_TEXTURE_1D,0,GL_RGBA8,8,0,GL_RGBA,GL_UNSIGNED_BYTE,tex);
    glEnable(GL_TEXTURE_1D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    GLfloat plane[4] = {0.5f,0,0,0.5f};
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
    glTexGenfv(GL_S, GL_EYE_PLANE, plane);
    glEnable(GL_TEXTURE_GEN_S);
    glColor3f(1,1,1);

    /* no translate */
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p1 = buf + (H/2*W+W/2)*4;
    printf("no translate, center: %d,%d,%d\n", p1[0],p1[1],p1[2]);

    /* translate the object 5 units in +X in the MODELVIEW, AFTER the eye plane was fixed */
    glMatrixMode(GL_MODELVIEW); glLoadIdentity(); glTranslatef(5,0,0);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
    glFinish();
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p2 = buf + (H/2*W+W/2)*4;
    printf("translated +5 X, center: %d,%d,%d (want DIFFERENT from above - eye-space x shifted by 5)\n", p2[0],p2[1],p2[2]);
    return 0;
}
