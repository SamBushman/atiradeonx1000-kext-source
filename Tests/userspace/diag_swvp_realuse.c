/* diag_swvp_realuse.c - #78: does REAL GL usage reach libGLProgrammability's PPEmulatorBuild/JIT (software vertex programs)? Creates a CGL context on the Apple generic float
 * (software) renderer, runs an ARB vertex program that is not on the interpreter blacklist (DP4 transform + colour pass-through), draws a triangle and reads it back.
 * Prints GL_RENDERER and the centre pixel; a crash here would be the #78 path, a clean run means a live driver never reaches the bad dispatch with that program. */
#include <stdio.h>
#include <string.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#include <stdlib.h>
#define W 64
#define H 64
#ifndef GL_VERTEX_PROGRAM_ARB
#define GL_VERTEX_PROGRAM_ARB 0x8620
#define GL_PROGRAM_FORMAT_ASCII_ARB 0x8875
#endif
typedef void (*PFNGENP)(GLsizei, GLuint *); typedef void (*PFNBINDP)(GLenum, GLuint); typedef void (*PFNPSTR)(GLenum, GLenum, GLsizei, const void *);
int main(int argc, char **argv) {
    CGLPixelFormatObj pf; GLint npix = 0; CGLContextObj ctx; void *mem = malloc(W * H * 4); GLubyte px[4]; GLuint prog; int sw = 1;
    const char *vp = "!!ARBvp1.0\nPARAM mvp[4] = { state.matrix.mvp };\nDP4 result.position.x, mvp[0], vertex.position;\nDP4 result.position.y, mvp[1], vertex.position;\n"
                     "DP4 result.position.z, mvp[2], vertex.position;\nDP4 result.position.w, mvp[3], vertex.position;\nMUL result.color, vertex.color, { 1, 0.5, 1, 1 };\nEND\n";
    CGLPixelFormatAttribute attrs[] = { kCGLPFAOffScreen, kCGLPFARendererID, (CGLPixelFormatAttribute)0x00020400, kCGLPFAColorSize, 32, (CGLPixelFormatAttribute)0 };
    setvbuf(stdout, NULL, _IONBF, 0);
    if (argc > 1) { sw = 0; attrs[2] = (CGLPixelFormatAttribute)0; attrs[1] = kCGLPFAAccelerated; attrs[0] = kCGLPFAOffScreen; }
    if (CGLChoosePixelFormat(attrs, &pf, &npix) || !pf) { printf("no pixel format\n"); return 1; }
    CGLCreateContext(pf, NULL, &ctx); CGLDestroyPixelFormat(pf);
    CGLSetCurrentContext(ctx);
    if (CGLSetOffScreen(ctx, W, H, W * 4, mem)) { printf("CGLSetOffScreen failed\n"); return 1; }
    printf("GL_RENDERER: %s\nGL_VERSION: %s\nvertex program ext: %s\n", glGetString(GL_RENDERER), glGetString(GL_VERSION), strstr((const char *)glGetString(GL_EXTENSIONS), "GL_ARB_vertex_program") ? "yes" : "NO");
    glViewport(0, 0, W, H); glMatrixMode(GL_PROJECTION); glLoadIdentity(); glMatrixMode(GL_MODELVIEW); glLoadIdentity(); glDisable(GL_DEPTH_TEST);
    glClearColor(0, 0, 0, 1); glClear(GL_COLOR_BUFFER_BIT);
    { void (*gen)(GLsizei, GLuint *) = (void *)glGenProgramsARB; (void)gen; }
    glGenProgramsARB(1, &prog); glBindProgramARB(GL_VERTEX_PROGRAM_ARB, prog);
    glProgramStringARB(GL_VERTEX_PROGRAM_ARB, GL_PROGRAM_FORMAT_ASCII_ARB, (GLsizei)strlen(vp), vp);
    printf("program error: 0x%x\n", glGetError());
    glEnable(GL_VERTEX_PROGRAM_ARB);
    glBegin(GL_TRIANGLES); glColor3f(0, 1, 0); glVertex3f(-1, -1, 0); glColor3f(0, 1, 0); glVertex3f(3, -1, 0); glColor3f(0, 1, 0); glVertex3f(-1, 3, 0); glEnd();
    glFinish();
    glReadPixels(W / 2, H / 2, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, px);
    printf("centre pixel: %d,%d,%d,%d (vertex colour 0,1,0 x program {1,0.5,1} = 0,127,0 when the program ran, 0,255,0 when it was ignored) %s\n", px[0], px[1], px[2], px[3], px[1] > 100 && px[1] < 160 ? "program executed" : "program NOT applied");
    return 0;
}
