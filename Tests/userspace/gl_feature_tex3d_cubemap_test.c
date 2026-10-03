/* gl_feature_tex3d_cubemap_test.c - issue #128: GL 1.5 feature-completeness check for 3D textures (GL_TEXTURE_3D, core
 * since 1.2) and cube maps (GL_TEXTURE_CUBE_MAP, core since 1.3), against an exact-texel sampling check: upload a small
 * texture with distinct, known colours per slice/face, sample at a coordinate that should land exactly on one of them
 * (GL_NEAREST, no filtering ambiguity), and check the readback is exactly that texel's colour. */
#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

#define W 64
#define H 64

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }

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
    glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(0, W, 0, H, -1, 1);
    glMatrixMode(GL_MODELVIEW); glLoadIdentity();
    glDisable(GL_DEPTH_TEST); glDisable(GL_LIGHTING);
    static GLubyte buf[W * H * 4];
    int bad = 0;

    /* 3D texture: 2x2x2, each of the 8 texels a distinct primary-ish colour; sample the texel at (0,0,1) exactly */
    {
        GLubyte vol[2 * 2 * 2 * 3];
        int i;
        GLubyte colours[8][3] = {
            {255,0,0},{0,255,0},{0,0,255},{255,255,0},
            {255,0,255},{0,255,255},{128,128,128},{255,255,255}
        };
        for (i = 0; i < 8; i++) { vol[i*3]=colours[i][0]; vol[i*3+1]=colours[i][1]; vol[i*3+2]=colours[i][2]; }
        GLuint tex; glGenTextures(1, &tex); glBindTexture(GL_TEXTURE_3D, tex);
        glTexImage3D(GL_TEXTURE_3D, 0, GL_RGB, 2, 2, 2, 0, GL_RGB, GL_UNSIGNED_BYTE, vol);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP);
        glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP);
        glEnable(GL_TEXTURE_3D);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glColor3f(1,1,1);
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        /* texel index (x=0,y=0,z=1) -> colours[4] = {255,0,255}; sample at the texel centre: s=0.25,t=0.25,r=0.75 */
        float sc = 0.25f, tc = 0.25f, rc = 0.75f;
        glBegin(GL_QUADS);
        glTexCoord3f(sc,tc,rc); glVertex2f(0,0);
        glTexCoord3f(sc,tc,rc); glVertex2f(W,0);
        glTexCoord3f(sc,tc,rc); glVertex2f(W,H);
        glTexCoord3f(sc,tc,rc); glVertex2f(0,H);
        glEnd();
        glFinish(); glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);
        GLubyte *p = buf + (H/2*W+W/2)*4;
        int ok = p[0]==255 && p[1]==0 && p[2]==255;
        printf("3D texture sample  got %d,%d,%d want 255,0,255 %s\n", p[0], p[1], p[2], ok ? "OK" : "MISMATCH");
        if (!ok) bad++;
        glDisable(GL_TEXTURE_3D);
    }

    /* cube map: 6 faces, each 1x1, a distinct colour; sample straight down +X */
    {
        GLuint tex; glGenTextures(1, &tex); glBindTexture(GL_TEXTURE_CUBE_MAP, tex);
        struct { GLenum face; GLubyte c[3]; } faces[6] = {
            {GL_TEXTURE_CUBE_MAP_POSITIVE_X, {255,0,0}}, {GL_TEXTURE_CUBE_MAP_NEGATIVE_X, {0,255,255}},
            {GL_TEXTURE_CUBE_MAP_POSITIVE_Y, {0,255,0}}, {GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, {255,0,255}},
            {GL_TEXTURE_CUBE_MAP_POSITIVE_Z, {0,0,255}}, {GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, {255,255,0}},
        };
        int i;
        for (i = 0; i < 6; i++) glTexImage2D(faces[i].face, 0, GL_RGB, 1, 1, 0, GL_RGB, GL_UNSIGNED_BYTE, faces[i].c);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glEnable(GL_TEXTURE_CUBE_MAP);
        glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
        glColor3f(1,1,1);
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS);
        glTexCoord3f(1,0,0); glVertex2f(0,0);
        glTexCoord3f(1,0,0); glVertex2f(W,0);
        glTexCoord3f(1,0,0); glVertex2f(W,H);
        glTexCoord3f(1,0,0); glVertex2f(0,H);
        glEnd();
        glFinish(); glReadPixels(0, 0, W, H, GL_RGBA, GL_UNSIGNED_BYTE, buf);
        GLubyte *p = buf + (H/2*W+W/2)*4;
        int ok = p[0]==255 && p[1]==0 && p[2]==0;
        printf("cube map +X face   got %d,%d,%d want 255,0,0 %s\n", p[0], p[1], p[2], ok ? "OK" : "MISMATCH");
        if (!ok) bad++;
    }

    printf("RESULT: %s (%d mismatches of 2 cases)\n", bad == 0 ? "PASS" : "FAIL", bad);
    return bad ? 1 : 0;
}
