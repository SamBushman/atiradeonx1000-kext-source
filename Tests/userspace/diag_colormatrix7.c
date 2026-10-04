#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
static void die(const char *w, CGLError e){fprintf(stderr,"FAIL %s: %s\n",w,CGLErrorString(e));}
int main(void){
    setvbuf(stdout,NULL,_IONBF,0);
    CGLPixelFormatObj pf; GLint npix=0;
    CGLPixelFormatAttribute attrs[]={kCGLPFAPBuffer,kCGLPFAAccelerated,kCGLPFANoRecovery,kCGLPFAColorSize,32,(CGLPixelFormatAttribute)0};
    CGLError err=CGLChoosePixelFormat(attrs,&pf,&npix); if(err||npix==0||!pf){die("CPF",err);return 1;}
    CGLContextObj ctx=NULL; err=CGLCreateContext(pf,NULL,&ctx); if(err){die("CC",err);return 1;}
    CGLDestroyPixelFormat(pf);
    CGLPBufferObj pbuf=NULL; err=CGLCreatePBuffer(32,32,GL_TEXTURE_RECTANGLE_EXT,GL_RGBA,0,&pbuf); if(err){die("CP",err);return 1;}
    err=CGLSetCurrentContext(ctx); if(err){die("SC",err);return 1;}
    err=CGLSetPBuffer(ctx,pbuf,0,0,0); if(err){die("SP",err);return 1;}
    GLfloat m[16] = { 0,1,0,0, 1,0,0,0, 0,0,0,0, 0,0,0,1 };
    glMatrixMode(GL_COLOR); glLoadMatrixf(m);
    GLenum e = glGetError();
    GLfloat rb[16]; glGetFloatv(GL_COLOR_MATRIX, rb);
    printf("glGetError after LoadMatrixf under GL_COLOR = 0x%04x\n", (unsigned)e);
    printf("readback: %.1f %.1f %.1f %.1f / %.1f %.1f %.1f %.1f / %.1f %.1f %.1f %.1f / %.1f %.1f %.1f %.1f\n",
           rb[0],rb[1],rb[2],rb[3], rb[4],rb[5],rb[6],rb[7], rb[8],rb[9],rb[10],rb[11], rb[12],rb[13],rb[14],rb[15]);
    GLint mode; glGetIntegerv(GL_MATRIX_MODE, &mode);
    printf("current matrix mode = 0x%04x (GL_COLOR=0x1800)\n", (unsigned)mode);
    return 0;
}
