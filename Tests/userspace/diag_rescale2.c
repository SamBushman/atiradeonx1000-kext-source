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
    glEnable(GL_LIGHTING);
    GLfloat black[4]={0,0,0,1}, white_mat[4]={1,1,1,1};
    glMaterialfv(GL_FRONT, GL_AMBIENT, black);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white_mat);
    glMaterialfv(GL_FRONT, GL_SPECULAR, black);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, black);
    glEnable(GL_LIGHT0);
    GLfloat lpos[4]={0,0,1,0}, ldiff[4]={1,1,1,1};
    glLightfv(GL_LIGHT0, GL_POSITION, lpos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, ldiff);
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_SPECULAR, black);
    glDisable(GL_NORMALIZE); glDisable(GL_RESCALE_NORMAL);

    /* use a normal that is NOT perfectly aligned with the light (so a wrong-magnitude normal changes N.L, not just scales a dot that was already 1.0 and clamps to the same 1.0 either way) */
    glMatrixMode(GL_MODELVIEW); glLoadIdentity(); glScalef(10.0f,10.0f,10.0f);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glNormal3f(0,0,0.3f);   /* short normal: magnitude 0.3, will be scaled by modelview to 3.0 */
    glVertex2f(-0.1f,-0.1f); glVertex2f(0.1f,-0.1f); glVertex2f(0.1f,0.1f); glVertex2f(-0.1f,0.1f);
    glEnd();
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;
    printf("scale=10, normal mag=0.3 (effective mag after scale=3.0), no correction: %d,%d,%d (want NOT 255 if the long normal truly over-drives N.L and gets clamped high, OR want darker if under-driven)\n", p[0],p[1],p[2]);
    return 0;
}
