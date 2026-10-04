#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
static void die(const char *w, CGLError e){fprintf(stderr,"FAIL %s: %s\n",w,CGLErrorString(e));}
#define W 64
#define H 64
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
    static GLubyte lvl[64*64*4];
    int i;
    GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
    for (i=0;i<64*64;i++) { lvl[i*4]=255; lvl[i*4+1]=0; lvl[i*4+2]=0; lvl[i*4+3]=255; }
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,64,64,0,GL_RGBA,GL_UNSIGNED_BYTE,lvl);
    { int lv, sz=32; for (lv=1; lv<=6; lv++, sz/=2) {
        for (i=0;i<sz*sz;i++) { lvl[i*4]=0; lvl[i*4+1]=255; lvl[i*4+2]=0; lvl[i*4+3]=255; }
        glTexImage2D(GL_TEXTURE_2D,lv,GL_RGBA8,sz,sz,0,GL_RGBA,GL_UNSIGNED_BYTE,lvl);
    } }
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    /* MIN_LOD=6 should force the sampler to NEVER go finer than level 6, even for a FULL-SIZE (64px)
     * footprint that would normally pick level 0 */
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_LOD, 6.0f);
    GLfloat rb=-999; glGetTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_MIN_LOD, &rb);
    printf("TEXTURE_MIN_LOD readback = %.2f (want 6.0)\n", rb);
    GLenum e = glGetError();
    printf("glGetError after set = 0x%04x\n", (unsigned)e);
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
    printf("MIN_LOD=6, FULL-SIZE footprint (normally picks level0=red): got %d,%d,%d (want green=level6 if clamp applied)\n", p[0],p[1],p[2]);
    return 0;
}
