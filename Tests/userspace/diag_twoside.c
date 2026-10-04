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
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    GLfloat black[4]={0,0,0,1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, black);
    glEnable(GL_LIGHT0);
    GLfloat lpos[4]={0,0,1,0}, ldiff[4]={1,1,1,1};
    glLightfv(GL_LIGHT0, GL_POSITION, lpos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, ldiff);
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_SPECULAR, black);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, black);
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, black);
    GLfloat red_diff[4] = {0.6f,0,0,1};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, red_diff);

    printf("LIGHT_MODEL_TWO_SIDE default value: %d\n", (int)({GLint v; glGetIntegerv(GL_LIGHT_MODEL_TWO_SIDE,&v); v;}));

    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    GLint readback; glGetIntegerv(GL_LIGHT_MODEL_TWO_SIDE, &readback);
    printf("after LightModeli(TWO_SIDE,TRUE): readback=%d\n", readback);

    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glNormal3f(0,0,-1);
    glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1);
    glEnd();
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;
    printf("TWO_SIDE on, back-facing normal (0,0,-1), light at (0,0,1,0): center=%d,%d,%d\n", p[0],p[1],p[2]);

    /* also check GL_BACK material to see if the back face uses a DIFFERENT (possibly default/black) material */
    GLfloat back_diff[4]={0,0,0,1};
    glGetMaterialfv(GL_BACK, GL_DIFFUSE, back_diff);
    printf("GL_BACK GL_DIFFUSE material (FRONT_AND_BACK should have set both): %.2f,%.2f,%.2f\n", back_diff[0],back_diff[1],back_diff[2]);
    return 0;
}
