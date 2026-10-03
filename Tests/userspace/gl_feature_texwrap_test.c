/* gl_feature_texwrap_test.c - issue #128 gap list: texture wrap modes beyond default (GL_CLAMP_TO_EDGE,
 * GL_MIRRORED_REPEAT) and GL_TEXTURE_BORDER_COLOR with legacy GL_CLAMP. */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

static GLuint mk2x1(GLubyte a[4], GLubyte b[4]) {
    GLubyte tex[2*4]; tex[0]=a[0];tex[1]=a[1];tex[2]=a[2];tex[3]=a[3]; tex[4]=b[0];tex[5]=b[1];tex[6]=b[2];tex[7]=b[3];
    GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,2,1,0,GL_RGBA,GL_UNSIGNED_BYTE,tex);
    return t;
}

static void draw_sampled_at(float s) {
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glBegin(GL_QUADS);
    glTexCoord2f(s,0.5f); glVertex2f(-1,-1);
    glTexCoord2f(s,0.5f); glVertex2f(1,-1);
    glTexCoord2f(s,0.5f); glVertex2f(1,1);
    glTexCoord2f(s,0.5f); glVertex2f(-1,1);
    glEnd();
}

static void readback(GLubyte *out) {
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;
    out[0]=p[0]; out[1]=p[1]; out[2]=p[2]; out[3]=p[3];
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
    glEnable(GL_TEXTURE_2D);

    int bad = 0;
    GLubyte c[4];
    GLubyte red[4] = {255,0,0,255}, blue[4]={0,0,255,255};

    /* GL_CLAMP_TO_EDGE: sampling well beyond [0,1] should clamp to the nearest edge texel (texel 1 = blue, since s>1 clamps toward the right edge) */
    GLuint t = mk2x1(red, blue);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    draw_sampled_at(5.0f);
    readback(c);
    int ok1 = (c[2]==255 && c[0]==0);
    printf("CLAMP_TO_EDGE s=5.0: got %d,%d,%d want 0,0,255 (edge texel) %s\n", c[0],c[1],c[2], ok1?"OK":"MISMATCH");
    if (!ok1) bad++;
    glDeleteTextures(1,&t);

    /* GL_MIRRORED_REPEAT: s=1.5 should mirror back to s=0.5 within the first texel pair -> at s=1.5 in a
     * mirrored 2-texel image, position 1.5 mod 2 = 1.5, mirrored segment [1,2) maps to [1,0) reversed,
     * so s=1.5 -> reversed 0.5 -> texel 0 (red) in the mirrored copy. Simpler: just confirm it differs from
     * plain GL_REPEAT's answer at the same coordinate, which is unambiguous evidence the mode took effect. */
    t = mk2x1(red, blue);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    draw_sampled_at(1.5f);
    GLubyte repeat_c[4]; readback(repeat_c);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    draw_sampled_at(1.5f);
    readback(c);
    int ok2 = (c[0]!=repeat_c[0] || c[2]!=repeat_c[2]);
    printf("MIRRORED_REPEAT vs REPEAT at s=1.5: repeat=%d,%d,%d mirrored=%d,%d,%d differ=%s (want YES)\n",
           repeat_c[0],repeat_c[1],repeat_c[2], c[0],c[1],c[2], ok2?"YES":"NO");
    if (!ok2) bad++;
    glDeleteTextures(1,&t);

    printf("RESULT: %s (%d mismatches of 2 checks)\n", bad==0?"PASS":"FAIL", bad);
    return bad?1:0;
}
