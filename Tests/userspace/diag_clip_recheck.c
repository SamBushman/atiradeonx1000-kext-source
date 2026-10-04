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
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    GLfloat black[4]={0,0,0,1}, white_mat[4]={1,1,1,1};
    glMaterialfv(GL_FRONT, GL_AMBIENT, black);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white_mat);
    glMaterialfv(GL_FRONT, GL_SPECULAR, black);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, black);
    glEnable(GL_LIGHT0);
    GLfloat lpos[4] = {0,0,2,0};
    GLfloat ldiff[4] = {1,1,1,1};
    glLightfv(GL_LIGHT0, GL_POSITION, lpos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, ldiff);
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_SPECULAR, black);

    /* EXACT original failing config: glOrtho(-1,1,-1,1,0.1,100), quad at z=0 (modelview identity) -
     * z=0 is a distance of 0 in front of the eye, which is OUTSIDE the near=0.1..far=100 clip range -
     * the quad should be NEAR-PLANE CLIPPED AWAY ENTIRELY, which would also explain a black result with
     * NO relation to lighting at all. Testing this theory directly. */
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-1,1,-1,1,0.1,100);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glClearColor(0.2f,0.2f,0.2f,1); glClear(GL_COLOR_BUFFER_BIT);   /* nonzero clear so "clipped away" is visually distinct from "black due to no light" */
    glBegin(GL_QUADS); glNormal3f(0,0,1);
    glVertex3f(-1,-1,0); glVertex3f(1,-1,0); glVertex3f(1,1,0); glVertex3f(-1,1,0);
    glEnd();
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;
    printf("original config, quad at z=0 (outside near=0.1..far=100): center=%d,%d,%d (clear was 51,51,51 - if still clear color, quad was clipped, not unlit)\n", p[0],p[1],p[2]);

    /* now move the SAME quad to z=-3, inside the clip volume, everything else identical */
    glClearColor(0.2f,0.2f,0.2f,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glNormal3f(0,0,1);
    glVertex3f(-1,-1,-3); glVertex3f(1,-1,-3); glVertex3f(1,1,-3); glVertex3f(-1,1,-3);
    glEnd();
    glFinish();
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p2 = buf + (H/2*W+W/2)*4;
    printf("same config, quad moved to z=-3 (inside near=0.1..far=100): center=%d,%d,%d\n", p2[0],p2[1],p2[2]);

    return 0;
}
