#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_GENERATE_MIPMAP
#define GL_GENERATE_MIPMAP 0x8191
#endif
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
    static GLubyte base[64*64*4];
    int x,y;
    for (y=0;y<64;y++) for (x=0;x<64;x++) {
        GLubyte *p = base + (y*64+x)*4;
        if (x<32) { p[0]=255;p[1]=0;p[2]=0;p[3]=255; } else { p[0]=0;p[1]=0;p[2]=255;p[3]=255; }
    }
    GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
    glTexParameteri(GL_TEXTURE_2D, GL_GENERATE_MIPMAP, GL_TRUE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA8,64,64,0,GL_RGBA,GL_UNSIGNED_BYTE,base);
    static GLubyte lvl1[32*32*4];
    glGetTexImage(GL_TEXTURE_2D, 1, GL_RGBA, GL_UNSIGNED_BYTE, lvl1);
    printf("mip level 1 row 16, texels 13..18 (boundary should be near x=16): ");
    int xx; for (xx=13;xx<=18;xx++) { GLubyte *p=lvl1+(16*32+xx)*4; printf("(%d,%d,%d) ", p[0],p[1],p[2]); }
    printf("\n");
    static GLubyte lvl2[16*16*4];
    glGetTexImage(GL_TEXTURE_2D, 2, GL_RGBA, GL_UNSIGNED_BYTE, lvl2);
    printf("mip level 2 row 8, texels 6..9: ");
    for (xx=6;xx<=9;xx++) { GLubyte *p=lvl2+(8*16+xx)*4; printf("(%d,%d,%d) ", p[0],p[1],p[2]); }
    printf("\n");
    return 0;
}
