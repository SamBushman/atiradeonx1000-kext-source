#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI
#define GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI 0x8837
#endif
static void die(const char *w, CGLError e){fprintf(stderr,"FAIL %s: %s\n",w,CGLErrorString(e));}
static void try1(int w, int h, int sz) {
    GLubyte block[64]; int i; for (i=0;i<64;i++) block[i]=0xff;
    GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
    while(glGetError()!=GL_NO_ERROR){}
    glCompressedTexImage2D(GL_TEXTURE_2D, 0, GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI, w, h, 0, sz, block);
    printf("%dx%d imageSize=%d: error=0x%04x\n", w, h, sz, (unsigned)glGetError());
    glDeleteTextures(1,&t);
}
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
    try1(4,4,8);
    try1(4,4,16);
    try1(8,8,16);
    try1(8,8,32);
    try1(16,16,32);
    try1(16,16,64);
    return 0;
}
