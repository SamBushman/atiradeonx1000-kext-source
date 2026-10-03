/* gl_feature_multilight_test.c - issue #128 gap list: multiple simultaneous light sources (only single-light
 * was exercised by the earlier specular test). Two directional lights with different diffuse colors hitting
 * a flat white surface head-on should sum additively (clamped to 1.0), per the GL lighting spec. */
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

static void readback(GLubyte *out) {
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;
    out[0]=p[0]; out[1]=p[1]; out[2]=p[2];
}

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
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);

    GLfloat black[4] = {0,0,0,1};
    GLfloat white_mat[4] = {1,1,1,1};
    glMaterialfv(GL_FRONT, GL_AMBIENT, black);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, white_mat);
    glMaterialfv(GL_FRONT, GL_SPECULAR, black);
    GLfloat global_amb[4] = {0,0,0,1};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_amb);

    int bad = 0;
    GLubyte c[3];

    /* light 0 alone: directional, diffuse red 0.4, pointing straight at the surface (dir (0,0,1) light pos w=0) */
    GLfloat l0pos[4] = {0,0,1,0};
    GLfloat l0diff[4] = {0.4f,0,0,1};
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, l0pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, l0diff);
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_SPECULAR, black);
    glDisable(GL_LIGHT1);

    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glNormal3f(0,0,1);
    glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1);
    glEnd();
    readback(c);
    printf("LIGHT0 alone (diffuse 0.4 red): got %d,%d,%d (want ~102,0,0)\n", c[0],c[1],c[2]);
    GLubyte light0_only[3] = {c[0],c[1],c[2]};

    /* light 1 alone: directional, diffuse green 0.3 */
    GLfloat l1pos[4] = {0,0,1,0};
    GLfloat l1diff[4] = {0,0.3f,0,1};
    glDisable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glLightfv(GL_LIGHT1, GL_POSITION, l1pos);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, l1diff);
    glLightfv(GL_LIGHT1, GL_AMBIENT, black);
    glLightfv(GL_LIGHT1, GL_SPECULAR, black);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glNormal3f(0,0,1);
    glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1);
    glEnd();
    readback(c);
    printf("LIGHT1 alone (diffuse 0.3 green): got %d,%d,%d (want ~0,76,0)\n", c[0],c[1],c[2]);
    GLubyte light1_only[3] = {c[0],c[1],c[2]};

    /* both lights together: should be the additive sum (clamped), i.e. (red0+red1, green0+green1, ...) */
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glNormal3f(0,0,1);
    glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1);
    glEnd();
    readback(c);
    int wantR = light0_only[0]+light1_only[0] > 255 ? 255 : light0_only[0]+light1_only[0];
    int wantG = light0_only[1]+light1_only[1] > 255 ? 255 : light0_only[1]+light1_only[1];
    int wantB = light0_only[2]+light1_only[2] > 255 ? 255 : light0_only[2]+light1_only[2];
    int ok = abs((int)c[0]-wantR)<=3 && abs((int)c[1]-wantG)<=3 && abs((int)c[2]-wantB)<=3;
    printf("LIGHT0+LIGHT1 together: got %d,%d,%d want (sum, clamped) %d,%d,%d %s\n", c[0],c[1],c[2], wantR,wantG,wantB, ok?"OK":"MISMATCH");
    if (!ok) bad++;

    printf("RESULT: %s (%d mismatches)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
