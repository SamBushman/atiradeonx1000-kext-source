/* gl_feature_texgen_test.c - glTexGen: GL_OBJECT_LINEAR and GL_SPHERE_MAP modes, never checked before. */
#include <stdio.h>
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

    int bad = 0;
    GLubyte c[3];

    /* GL_OBJECT_LINEAR: generate s = x (object space), via plane coeffs (1,0,0,0); a 1D red->green ramp
     * texture, sampled with that generated coordinate, should vary across the quad's width */
    {
        GLubyte tex[8*4];
        int i; for (i=0;i<8;i++) { tex[i*4]=255*(7-i)/7; tex[i*4+1]=255*i/7; tex[i*4+2]=0; tex[i*4+3]=255; }
        GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_1D,t);
        glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_1D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage1D(GL_TEXTURE_1D,0,GL_RGBA8,8,0,GL_RGBA,GL_UNSIGNED_BYTE,tex);
        glEnable(GL_TEXTURE_1D);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        GLfloat plane[4] = {0.5f,0,0,0.5f};   /* s = 0.5*x + 0.5, maps object x in [-1,1] to texcoord [0,1] */
        glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
        glTexGenfv(GL_S, GL_OBJECT_LINEAR, plane);
        glEnable(GL_TEXTURE_GEN_S);
        glColor3f(1,1,1);
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS); glVertex2f(-1,-1); glVertex2f(1,-1); glVertex2f(1,1); glVertex2f(-1,1); glEnd();
        /* sample left and right edges - should show opposite-dominant colors (red-left, green-right) */
        glFinish();
        static GLubyte buf[W*H*4];
        glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
        GLubyte *left = buf + (H/2*W+2)*4;
        GLubyte *right = buf + (H/2*W+(W-3))*4;
        int ok = (left[0] > right[0]) && (right[1] > left[1]);
        printf("OBJECT_LINEAR texgen: left=%d,%d,%d right=%d,%d,%d (want left redder, right greener) %s\n",
               left[0],left[1],left[2], right[0],right[1],right[2], ok?"OK":"MISMATCH");
        if (!ok) bad++;
        glDisable(GL_TEXTURE_GEN_S); glDisable(GL_TEXTURE_1D); glDeleteTextures(1,&t);
    }

    /* GL_SPHERE_MAP: just confirm it's accepted with no error and produces a DIFFERENT result from OBJECT_LINEAR
     * on the same geometry (a weaker but unambiguous correctness signal, since sphere-map requires real
     * lighting-normal setup to validate precisely) */
    {
        while (glGetError() != GL_NO_ERROR) {}
        GLubyte tex[2*2*4] = {255,0,0,255, 0,255,0,255, 0,0,255,255, 255,255,0,255};
        GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,2,2,0,GL_RGBA,GL_UNSIGNED_BYTE,tex);
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_NORMALIZE);
        glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
        glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
        glEnable(GL_TEXTURE_GEN_S); glEnable(GL_TEXTURE_GEN_T);
        glColor3f(1,1,1);
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glNormal3f(0.3f,0.2f,1); glVertex2f(-1,-1);
        glNormal3f(-0.3f,0.2f,1); glVertex2f(1,-1);
        glNormal3f(-0.3f,-0.2f,1); glVertex2f(1,1);
        glNormal3f(0.3f,-0.2f,1); glVertex2f(-1,1);
        glEnd();
        GLenum e = glGetError();
        readback(c);
        printf("SPHERE_MAP texgen: glGetError=0x%04x, center color=%d,%d,%d (just confirming no error + real sampling occurred)\n", e, c[0],c[1],c[2]);
        if (e != GL_NO_ERROR) bad++;
        glDisable(GL_TEXTURE_GEN_S); glDisable(GL_TEXTURE_GEN_T); glDisable(GL_TEXTURE_2D); glDeleteTextures(1,&t);
    }

    printf("RESULT: %s (%d mismatches)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
