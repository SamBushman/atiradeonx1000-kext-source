/*
 * diag_lighting_pervertex.c - re-test of the #134 (two-sided), #135 (spot cutoff) and #136
 * (positional light "dimming") findings with geometry that does NOT confound them.
 *
 * The fixed-function lighting pipeline of the GLDriver is a generated VERTEX program
 * (ffvpEmitLight / ffvpEmitDirectionalLight, part_014.c), so every colour is computed per vertex
 * and Gouraud-interpolated.  The earlier diag_orthoscale / diag_posdim / diag_spot* tests lit a big
 * quad whose four corners are all off-axis, so the "centre" pixel is just the corner colour:
 *   #136: corner N.L = 2/sqrt(1+1+4) = 0.8165 -> 255*0.8165 = 208.2  (observed 208)
 *   #135: corner N.L = h/sqrt(128+h*h): h=5 -> 0.4042 (66.2 deg), h=2 -> 0.1741 (79.97 deg)
 *         so cutoff 70 lights h=5 (66.2<70) but not h=2 (79.97>70); cutoff 80 lights h=2.
 *   #134: the quad was wound counter-clockwise = FRONT facing, so two-sided lighting (which only
 *         changes BACK faces) correctly leaves it on the front material with N.L = -1 -> black.
 * Here: tiny (+-0.05) quads for #136/#134 (corner colour == centre colour to < 0.1%), a +-0.5 quad
 * for the spot sweep (corner 19.5 deg off-axis at h=2, 8.05 deg at h=5), and a clockwise
 * (back-facing) quad for two-sided lighting.
 *
 * Expected on a correct implementation (values +-2):
 *   posdim w=1 atten(1,0,0)           : 255
 *   posdim w=0                        : 255
 *   spot h=5 cutoff 90/70/60/15/10    : lit(~252) for all five (corner 8.05 deg < 10)
 *   spot h=5 cutoff 5                 : dark (0)
 *   spot h=2 cutoff 90/70/20          : lit(~240) x3
 *   spot h=2 cutoff 10                : dark (corner 19.5 deg > 10)
 *   two-side OFF, CW quad, n=(0,0,-1) : 0,0,0     (back face uses front material, N.L=-1)
 *   two-side ON,  CW quad, n=(0,0,-1) : 153,0,0   (back material, normal negated: N.L=+1)
 *   two-side ON,  CCW quad,n=(0,0,-1) : 0,0,0     (front face, N.L=-1)
 */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
static void die(const char *w, CGLError e){fprintf(stderr,"FAIL %s: %s\n",w,CGLErrorString(e));}
#define W 32
#define H 32
static void center(const char *label){
    static GLubyte buf[W*H*4];
    glFinish();
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;
    printf("%-44s center=%d,%d,%d\n", label, p[0],p[1],p[2]);
}
/* quad of half-size s in the z=0 plane, optionally clockwise */
static void quad(float nz, int cw, float s){
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS); glNormal3f(0,0,nz);
    if (!cw) { glVertex3f(-s,-s,0); glVertex3f(s,-s,0); glVertex3f(s,s,0); glVertex3f(-s,s,0); }
    else     { glVertex3f(-s,-s,0); glVertex3f(-s,s,0); glVertex3f(s,s,0); glVertex3f(s,-s,0); }
    glEnd();
}
static void setup_light(float x,float y,float z,float w){
    GLfloat black[4]={0,0,0,1}, white[4]={1,1,1,1}, pos[4]; pos[0]=x;pos[1]=y;pos[2]=z;pos[3]=w;
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, black);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, white);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, black);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, black);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, pos);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_AMBIENT, black);
    glLightfv(GL_LIGHT0, GL_SPECULAR, black);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 1.0f);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.0f);
    glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0f);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180.0f);
}
static void spot(float h, float cutoff){
    GLfloat ldir[3]={0,0,-1}; char l[64];
    setup_light(0,0,h,1);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, ldir);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, cutoff);
    glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 0.0f);
    quad(1,0,0.5f);
    sprintf(l,"spot height=%.0f cutoff=%.0f",h,cutoff);
    center(l);
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
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);

    /* #136: positional vs directional, no attenuation */
    setup_light(0,0,2,1); quad(1,0,.05f); center("posdim w=1 atten(1,0,0)");
    setup_light(0,0,1,0); quad(1,0,.05f); center("posdim w=0");

    /* #135: spot cutoff sweep with quads small enough that the corner is ~on-axis */
    spot(5,90); spot(5,70); spot(5,60); spot(5,15); spot(5,10); spot(5,5);
    spot(2,90); spot(2,70); spot(2,20); spot(2,10);

    /* #134: two-sided lighting; light is directional, +z */
    setup_light(0,0,1,0);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
    quad(-1,1,.05f); center("two-side OFF, CW (back) quad, n=(0,0,-1)");
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);
    { GLfloat red[4]={0.6f,0,0,1}; glMaterialfv(GL_BACK, GL_DIFFUSE, red); }
    quad(-1,1,.05f); center("two-side ON,  CW (back) quad, n=(0,0,-1)");
    quad(-1,0,.05f); center("two-side ON,  CCW (front) quad, n=(0,0,-1)");
    return 0;
}
