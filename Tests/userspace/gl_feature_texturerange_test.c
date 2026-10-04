/* gl_feature_texturerange_test.c - APPLE_texture_range + APPLE_client_storage: a "zero-copy" texture upload
 * hint (glTextureRangeAPPLE + GL_UNPACK_CLIENT_STORAGE_APPLE + GL_STORAGE_CACHED/SHARED_APPLE). This is a
 * performance hint with no required behavioral difference per spec - the correctness check is simply that
 * the resulting texture samples IDENTICALLY to the same upload without the hint. Never checked before. */
#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_TEXTURE_STORAGE_HINT_APPLE
#define GL_TEXTURE_STORAGE_HINT_APPLE 0x85BC
#endif
#ifndef GL_STORAGE_CACHED_APPLE
#define GL_STORAGE_CACHED_APPLE 0x85BE
#endif
#ifndef GL_UNPACK_CLIENT_STORAGE_APPLE
#define GL_UNPACK_CLIENT_STORAGE_APPLE 0x85B2
#endif

static void die(const char *what, CGLError e) { fprintf(stderr, "FAIL %s: %s\n", what, CGLErrorString(e)); }
#define W 32
#define H 32

static void sample(GLuint tex, GLubyte *out) {
    glBindTexture(GL_TEXTURE_2D, tex);
    glEnable(GL_TEXTURE_2D);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glColor3f(1,1,1);
    glClearColor(0,0,0,1); glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    glTexCoord2f(0,0); glVertex2f(-1,-1); glTexCoord2f(1,0); glVertex2f(1,-1);
    glTexCoord2f(1,1); glVertex2f(1,1); glTexCoord2f(0,1); glVertex2f(-1,1);
    glEnd();
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

    /* page-aligned-ish client buffer, kept alive for the texture's lifetime as APPLE_client_storage requires */
    static GLubyte clientData[4*4*4];
    int i; for (i=0;i<4*4;i++) { clientData[i*4]=12; clientData[i*4+1]=200; clientData[i*4+2]=77; clientData[i*4+3]=255; }

    GLuint t1; glGenTextures(1,&t1); glBindTexture(GL_TEXTURE_2D,t1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,4,4,0,GL_RGBA,GL_UNSIGNED_BYTE,clientData);
    GLubyte normal[3]; sample(t1, normal);

    GLuint t2; glGenTextures(1,&t2); glBindTexture(GL_TEXTURE_2D,t2);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTextureRangeAPPLE(GL_TEXTURE_2D, sizeof(clientData), clientData);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_STORAGE_HINT_APPLE, GL_STORAGE_CACHED_APPLE);
    glPixelStorei(GL_UNPACK_CLIENT_STORAGE_APPLE, GL_TRUE);
    GLenum e1 = glGetError();
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,4,4,0,GL_RGBA,GL_UNSIGNED_BYTE,clientData);
    GLenum e2 = glGetError();
    glPixelStorei(GL_UNPACK_CLIENT_STORAGE_APPLE, GL_FALSE);
    GLubyte zerocopy[3]; sample(t2, zerocopy);

    int ok = (normal[0]==zerocopy[0] && normal[1]==zerocopy[1] && normal[2]==zerocopy[2]) && e1==GL_NO_ERROR && e2==GL_NO_ERROR;
    printf("TextureRange+client_storage vs normal upload: normal=%d,%d,%d zerocopy=%d,%d,%d err1=0x%04x err2=0x%04x %s\n",
           normal[0],normal[1],normal[2], zerocopy[0],zerocopy[1],zerocopy[2], (unsigned)e1, (unsigned)e2, ok?"OK":"MISMATCH");

    printf("RESULT: %s\n", ok?"PASS":"FAIL");
    return ok?0:1;
}
