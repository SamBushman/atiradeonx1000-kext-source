/* diag_tex3d.c - isolating the 3D-texture NEAREST-sampling anomaly from gl_feature_tex3d_cubemap_test.c (issue #128):
 * samples each axis's two texels INDEPENDENTLY at unambiguous (not texel-centre-boundary) coordinates, to find the
 * REAL index mapping rather than guessing a formula. A 2x2x2 volume where only ONE colour channel distinguishes each
 * axis: red varies with x, green with y, blue with z - so the sampled colour directly reveals which texel each axis
 * coordinate actually selected, independent of any assumption about memory layout order. */
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
    CGLPixelFormatObj pf; GLint npix = 0;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize, 32, (CGLPixelFormatAttribute)0 };
    CGLError err = CGLChoosePixelFormat(attrs, &pf, &npix);
    if (err || npix == 0 || !pf) { die("ChoosePixelFormat", err); return 1; }
    CGLContextObj ctx = NULL;
    err = CGLCreateContext(pf, NULL, &ctx);
    if (err) { die("CreateContext", err); return 1; }
    CGLDestroyPixelFormat(pf);
    CGLPBufferObj pbuf = NULL;
    err = CGLCreatePBuffer(W, H, GL_TEXTURE_RECTANGLE_EXT, GL_RGBA, 0, &pbuf);
    if (err) { die("CreatePBuffer", err); return 1; }
    err = CGLSetCurrentContext(ctx);
    if (err) { die("SetCurrentContext", err); return 1; }
    long vscreen = 0;
    err = CGLSetPBuffer(ctx, pbuf, 0, 0, vscreen);
    if (err) { die("SetPBuffer", err); return 1; }
    glViewport(0, 0, W, H);
    glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST); glDisable(GL_LIGHTING);

    /* 2x2x2 volume: vol[x][y][z] = (x?200:20, y?200:20, z?200:20) - standard x-fastest, then y, then z memory order */
    GLubyte vol[2*2*2*3];
    int x, y, z;
    for (z = 0; z < 2; z++) for (y = 0; y < 2; y++) for (x = 0; x < 2; x++) {
        int idx = x + y*2 + z*4;
        vol[idx*3+0] = x ? 200 : 20;
        vol[idx*3+1] = y ? 200 : 20;
        vol[idx*3+2] = z ? 200 : 20;
    }
    GLuint tex; glGenTextures(1, &tex); glBindTexture(GL_TEXTURE_3D, tex);
    glTexImage3D(GL_TEXTURE_3D, 0, GL_RGB, 2, 2, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, vol);
    glFinish();   /* lesson from the FBO diagnostic: this driver can need an explicit barrier between an upload and a dependent sample */
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP);
    glEnable(GL_TEXTURE_3D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glColor3f(1,1,1);

    static GLubyte buf[W*H*4];
    int sx, sy, sz;
    /* sample at 0.1/0.9 (well inside each texel, nowhere near a boundary) for every one of the 8 corners */
    for (sz = 0; sz < 2; sz++) for (sy = 0; sy < 2; sy++) for (sx = 0; sx < 2; sx++) {
        float s = sx ? 0.9f : 0.1f, t = sy ? 0.9f : 0.1f, r = sz ? 0.9f : 0.1f;
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glTexCoord3f(s,t,r); glVertex2f(-1,-1);
        glTexCoord3f(s,t,r); glVertex2f(1,-1);
        glTexCoord3f(s,t,r); glVertex2f(1,1);
        glTexCoord3f(s,t,r); glVertex2f(-1,1);
        glEnd();
        glFinish();
        glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);
        GLubyte *p = buf + (H/2*W+W/2)*4;
        printf("coord s=%.1f t=%.1f r=%.1f (asking for x=%d,y=%d,z=%d) -> sampled r,g,b=%3d,%3d,%3d -> real x=%d y=%d z=%d\n",
               s, t, r, sx, sy, sz, p[0], p[1], p[2], p[0]>100, p[1]>100, p[2]>100);
    }
    return 0;
}
