#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
int main(void){
    CGLPixelFormatObj pf; GLint npix=0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize,32,
        kCGLPFASampleBuffers, 1, kCGLPFASamples, 4, (CGLPixelFormatAttribute)0 };
    CGLError err = CGLChoosePixelFormat(attrs,&pf,&npix);
    printf("ChoosePixelFormat err=%s npix=%d\n", CGLErrorString(err), npix);
    if (!pf) return 1;
    long sb=-1, s=-1, accel=-1;
    CGLDescribePixelFormat(pf, 0, kCGLPFASampleBuffers, (GLint*)&sb);
    CGLDescribePixelFormat(pf, 0, kCGLPFASamples, (GLint*)&s);
    CGLDescribePixelFormat(pf, 0, kCGLPFAAccelerated, (GLint*)&accel);
    printf("chosen pixel format: sampleBuffers=%ld samples=%ld accelerated=%ld\n", sb, s, accel);
    return 0;
}
