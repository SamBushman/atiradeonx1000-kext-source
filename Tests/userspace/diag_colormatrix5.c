#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_POST_COLOR_MATRIX_RED_SCALE
#define GL_POST_COLOR_MATRIX_RED_SCALE 0x80B4
#endif
#ifndef GL_POST_COLOR_MATRIX_RED_BIAS
#define GL_POST_COLOR_MATRIX_RED_BIAS 0x80B8
#endif
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
    GLfloat scale=-999, bias=-999;
    glGetFloatv(GL_POST_COLOR_MATRIX_RED_SCALE, &scale);
    glGetFloatv(GL_POST_COLOR_MATRIX_RED_BIAS, &bias);
    printf("default POST_COLOR_MATRIX_RED_SCALE=%.3f BIAS=%.3f (want 1.0, 0.0)\n", scale, bias);
    GLfloat m[16]; glGetFloatv(GL_COLOR_MATRIX, m);
    printf("default GL_COLOR_MATRIX: %.2f %.2f %.2f %.2f / %.2f %.2f %.2f %.2f / %.2f %.2f %.2f %.2f / %.2f %.2f %.2f %.2f\n",
           m[0],m[1],m[2],m[3], m[4],m[5],m[6],m[7], m[8],m[9],m[10],m[11], m[12],m[13],m[14],m[15]);
    return 0;
}
