/* diag_spheremap.c - #216 follow-up: GL_SPHERE_MAP texgen through the fixed-function vertex program (ffvpEmitSphereMapCoord) must sample the texture at the sphere-map
 * coordinate (a gradient texture makes the sampled colour = (s,t)). Prints the centre pixel for several surface normals; stock is the reference. */
#include <stdio.h>
#include <math.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#define W 64
#define H 64
int main(void) {
    CGLPixelFormatObj pf; GLint npix = 0; CGLContextObj ctx; CGLPBufferObj pbuf; GLubyte tex[32*32*4]; int i, j, k;
    CGLPixelFormatAttribute attrs[] = { kCGLPFAPBuffer, kCGLPFAAccelerated, kCGLPFANoRecovery, kCGLPFAColorSize, 32, (CGLPixelFormatAttribute)0 };
    if (CGLChoosePixelFormat(attrs, &pf, &npix) || !pf) return 1;
    CGLCreateContext(pf, NULL, &ctx); CGLDestroyPixelFormat(pf); CGLCreatePBuffer(W, H, GL_TEXTURE_2D, GL_RGBA, 0, &pbuf);
    CGLSetCurrentContext(ctx); CGLSetPBuffer(ctx, pbuf, 0, 0, 0);
    for (j = 0; j < 32; j++) for (i = 0; i < 32; i++) { GLubyte *p = tex + (j*32+i)*4; p[0] = i*8; p[1] = j*8; p[2] = 0; p[3] = 255; }
    glBindTexture(GL_TEXTURE_2D, 1); glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, 32, 32, 0, GL_RGBA, GL_UNSIGNED_BYTE, tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); glEnable(GL_TEXTURE_2D);
    glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP); glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP); glEnable(GL_TEXTURE_GEN_S); glEnable(GL_TEXTURE_GEN_T);
    glViewport(0,0,W,H); glMatrixMode(GL_PROJECTION); glLoadIdentity(); glFrustum(-0.2,0.2,-0.2,0.2,1,10); glMatrixMode(GL_MODELVIEW); glLoadIdentity(); glDisable(GL_DEPTH_TEST);
    { float nrm[][3] = { {0,0,1}, {0.5f,0,0.866f}, {-0.5f,0,0.866f}, {0,0.5f,0.866f}, {0,-0.5f,0.866f}, {0.6f,0.6f,0.529f}, {-0.6f,0.3f,0.742f}, {0.8f,-0.4f,0.447f} };
      for (k = 0; k < 8; k++) { GLubyte c[4]; GLenum e;
        glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_QUADS); glNormal3fv(nrm[k]); glVertex3f(-0.05f,-0.05f,-2); glVertex3f(0.05f,-0.05f,-2); glVertex3f(0.05f,0.05f,-2); glVertex3f(-0.05f,0.05f,-2); glEnd();
        glFinish(); glReadPixels(W/2, H/2, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, c); e = glGetError();
        printf("n=(%.2f,%.2f,%.2f) centre rgba=%3d,%3d,%3d,%3d err=0x%x\n", nrm[k][0], nrm[k][1], nrm[k][2], c[0], c[1], c[2], c[3], e); } }
    return 0;
}
