/* gl_feature_floattex_test.c - ATI_texture_float / APPLE_float_pixels: a float-format texture should hold
 * values OUTSIDE [0,1] without clamping on upload (the defining feature vs. a normal fixed-point texture).
 * Checked by uploading a texel with a value > 1.0 and sampling it back via a shader (so the value is read
 * before any final framebuffer clamp) to confirm it wasn't silently clamped to 1.0 at upload/storage time.
 * Never checked before. */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_RGBA_FLOAT32_ATI
#define GL_RGBA_FLOAT32_ATI 0x8814
#endif

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

static GLuint build(const char *fsrc) {
    const char *vsrc = "#version 110\nvoid main() { gl_Position = gl_Vertex; gl_TexCoord[0] = gl_MultiTexCoord0; }\n";
    GLuint vs = glCreateShader(GL_VERTEX_SHADER); glShaderSource(vs, 1, &vsrc, NULL); glCompileShader(vs);
    GLuint fs = glCreateShader(GL_FRAGMENT_SHADER); glShaderSource(fs, 1, &fsrc, NULL); glCompileShader(fs);
    GLuint prog = glCreateProgram();
    glAttachShader(prog, vs); glAttachShader(prog, fs);
    glLinkProgram(prog);
    GLint ok; glGetProgramiv(prog, GL_LINK_STATUS, &ok);
    if (!ok) { char log[1024]; glGetProgramInfoLog(prog, sizeof log, NULL, log); fprintf(stderr, "LINK FAIL: %s\n", log); return 0; }
    return prog;
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

    /* value 2.75, well outside [0,1] */
    GLfloat texel[4] = {2.75f, 0.0f, 0.0f, 1.0f};
    GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_RECTANGLE_ARB,t);
    glTexParameteri(GL_TEXTURE_RECTANGLE_ARB, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_RECTANGLE_ARB, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    while (glGetError() != GL_NO_ERROR) {}
    glTexImage2D(GL_TEXTURE_RECTANGLE_ARB,0,GL_RGBA_FLOAT32_ATI,1,1,0,GL_RGBA,GL_FLOAT,texel);
    GLenum e = glGetError();
    printf("float texture upload (value 2.75): glGetError=0x%04x\n", (unsigned)e);
    if (e != GL_NO_ERROR) { printf("RESULT: FAIL (upload errored)\n"); return 1; }

    const char *fsrc = "#version 110\n#extension GL_ARB_texture_rectangle : enable\nuniform sampler2DRect tex;\n"
                        "void main() { float v = texture2DRect(tex, vec2(0.5,0.5)).r; gl_FragColor = vec4(v > 2.0 ? 1.0 : 0.0, 0.0, 0.0, 1.0); }\n";
    GLuint prog = build(fsrc);
    if (!prog) return 1;
    glUseProgram(prog);
    glUniform1i(glGetUniformLocation(prog, "tex"), 0);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_RECTANGLE_ARB, t);

    GLfloat verts[] = {-1,-1, 1,-1, 1,1, -1,1};
    glVertexPointer(2, GL_FLOAT, 0, verts);
    glEnableClientState(GL_VERTEX_ARRAY);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_QUADS, 0, 4);
    glFinish();
    static GLubyte buf[W*H*4];
    glReadPixels(0,0,W,H,GL_RGBA,GL_UNSIGNED_BYTE,buf);
    GLubyte *p = buf + (H/2*W+W/2)*4;
    int ok = (p[0] > 200);
    printf("sampled float texel in shader (checked value > 2.0, i.e. not clamped to 1.0 at upload): got R=%d %s\n", p[0], ok?"OK (value survived > 1.0)":"MISMATCH (value may have been clamped)");

    printf("RESULT: %s\n", ok?"PASS":"FAIL");
    return ok?0:1;
}
