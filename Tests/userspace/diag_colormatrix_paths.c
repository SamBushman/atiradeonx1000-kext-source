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
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);

    /* render a known flat-color quad (gray 76,76,76) with NO color matrix active, then apply a 2x-R-only
     * color matrix during ReadPixels (color matrix applies to ReadPixels per ARB_imaging spec too) */
    glColor3f(76.0f/255.0f,76.0f/255.0f,76.0f/255.0f);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
    glFinish();

    GLfloat m[16] = {2,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,1};
    glMatrixMode(GL_COLOR); glLoadMatrixf(m); glMatrixMode(GL_MODELVIEW);

    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;
    printf("ReadPixels with 2x-R color matrix on a gray(76,76,76) quad: got %d,%d,%d (want ~152,0,0 if matrix applies correctly to ReadPixels, or saturated/wrong per quirk 24 if the same bug reproduces here)\n", p[0],p[1],p[2]);

    /* CopyPixels: copy the SAME rendered region to another spot, with the color matrix still active */
    glMatrixMode(GL_COLOR); glLoadIdentity(); glMatrixMode(GL_MODELVIEW);   /* reset first, draw unaffected source */
    glRasterPos2i(0,0);
    glMatrixMode(GL_COLOR); glLoadMatrixf(m); glMatrixMode(GL_MODELVIEW);  /* matrix active for the COPY itself */
    glCopyPixels(0,0,4,4,GL_COLOR);
    glFinish();
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p2 = buf + (H/2*W+W/2)*4;
    printf("CopyPixels with 2x-R color matrix active: got %d,%d,%d\n", p2[0],p2[1],p2[2]);

    return 0;
}
