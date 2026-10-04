/* gl_feature_windowpos_test.c - ARB_window_pos: glWindowPos2i places the raster position directly in
 * WINDOW coordinates, bypassing the ModelView/Projection transform entirely (unlike glRasterPos, which
 * transforms like any vertex - the thing that bit gl_feature_pixelops_test.c earlier in this project).
 * Never checked before. */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatObj pf; GLint npix=0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize,32, (CGLPixelFormatAttribute)0 };
    CGLError err = CGLChoosePixelFormat(attrs,&pf,&npix);
    if (err||npix==0||!pf) { die("ChoosePixelFormat",err); return 1; }
    CGLContextObj ctx=NULL; err=CGLCreateContext(pf,NULL,&ctx);
    if (err) { die("CreateContext",err); return 1; }
    CGLDestroyPixelFormat(pf);
    CGLPBufferObj pbuf=NULL; err=CGLCreatePBuffer(W,H,GL_TEXTURE_RECTANGLE_EXT,GL_RGBA,0,&pbuf);
    if (err) { die("CreatePBuffer",err); return 1; }
    err=CGLSetCurrentContext(ctx); if (err) { die("SetCurrentContext",err); return 1; }
    err=CGLSetPBuffer(ctx,pbuf,0,0,0); if (err) { die("SetPBuffer",err); return 1; }
    glViewport(0,0,W,H);
    /* deliberately a WEIRD, non-pixel-space projection/modelview - the whole point of glWindowPos is that
     * it should be immune to this, unlike glRasterPos */
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-500,500,-500,500,-1,1);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity(); glTranslatef(123,456,0);
    glDisable(GL_DEPTH_TEST);

    GLubyte block[8*8*4];
    int i; for (i=0;i<8*8;i++) { block[i*4]=255; block[i*4+1]=128; block[i*4+2]=0; block[i*4+3]=255; }
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glWindowPos2iARB(4,4);
    GLenum e = glGetError();
    glDrawPixels(8,8,GL_RGBA,GL_UNSIGNED_BYTE,block);
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (8*W+8)*4;
    int ok = (p[0]==255 && p[1]==128 && p[2]==0) && e==GL_NO_ERROR;
    printf("glWindowPos2i(4,4) + DrawPixels, despite a weird ortho+translate MODELVIEW/PROJECTION: got %d,%d,%d glGetError=0x%04x %s\n",
           p[0],p[1],p[2], (unsigned)e, ok?"OK (window-space, immune to MVP)":"MISMATCH");

    printf("RESULT: %s\n", ok?"PASS":"FAIL");
    return ok?0:1;
}
