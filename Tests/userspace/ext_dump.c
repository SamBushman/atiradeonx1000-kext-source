#include <stdio.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
int main(void){
    CGLPixelFormatObj pf; GLint npix=0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize,32, (CGLPixelFormatAttribute)0 };
    CGLChoosePixelFormat(attrs,&pf,&npix);
    CGLContextObj ctx=NULL; CGLCreateContext(pf,NULL,&ctx);
    CGLDestroyPixelFormat(pf);
    CGLPBufferObj pbuf=NULL; CGLCreatePBuffer(32,32,GL_TEXTURE_RECTANGLE_EXT,GL_RGBA,0,&pbuf);
    CGLSetCurrentContext(ctx); CGLSetPBuffer(ctx,pbuf,0,0,0);
    const char *e = (const char*)glGetString(GL_EXTENSIONS);
    printf("%s\n", e);
    return 0;
}
