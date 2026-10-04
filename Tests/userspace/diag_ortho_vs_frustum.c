#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
static void die(const char *w, CGLError e){fprintf(stderr,"FAIL %s: %s\n",w,CGLErrorString(e));}
#define W 32
#define H 32
static void setup_light(void){
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    GLfloat black[4]={0,0,0,1}, white_mat[4]={1,1,1,1};
    glMaterialfv(GL_FRONT, GL_AMBIENT, black);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white_mat);
    glMaterialfv(GL_FRONT, GL_SPECULAR, black);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, black);
    glEnable(GL_LIGHT0);
    GLfloat lpos[4] = {0,0,1,0};
    GLfloat ldiff[4] = {1,1,1,1};
    glLightfv(GL_LIGHT0, GL_POSITION, lpos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, ldiff);
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_SPECULAR, black);
}
static void draw_and_report(const char *label){
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glNormal3f(0,0,1);
    glVertex3f(-0.3f,-0.3f,0); glVertex3f(0.3f,-0.3f,0); glVertex3f(0.3f,0.3f,0); glVertex3f(-0.3f,0.3f,0);
    glEnd();
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;
    printf("%-55s center=%d,%d,%d\n", label, p[0],p[1],p[2]);
}
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
    setup_light();

    /* same near/far pair (0.5, 1000 - ratio 2000, the ratio where frustum WORKED) applied to ortho */
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-1,1,-1,1,0.5,1000);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity(); glTranslatef(0,0,-3);
    draw_and_report("glOrtho near=0.5 far=1000 ratio2000 (frustum worked at this ratio)");

    /* same near/far pair (0.1,100 - ratio 1000) that broke the original ortho test */
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-1,1,-1,1,0.1,100);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity(); glTranslatef(0,0,-3);
    draw_and_report("glOrtho near=0.1 far=100 ratio1000 (original breaking case)");

    /* very mild asymmetry: near=1, far=3 (ratio 3) */
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-1,1,-1,1,1,3);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity(); glTranslatef(0,0,-2);
    draw_and_report("glOrtho near=1 far=3 ratio3 (very mild asymmetry)");

    /* near=1, far=1.01 (barely asymmetric at all) */
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(-1,1,-1,1,1,1.01f);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity(); glTranslatef(0,0,-1.005f);
    draw_and_report("glOrtho near=1 far=1.01 ratio1.01 (barely asymmetric)");

    return 0;
}
