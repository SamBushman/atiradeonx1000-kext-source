#include <stdio.h>
#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>
#ifndef GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI
#define GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI 0x8837
#endif
static void die(const char *w, CGLError e){fprintf(stderr,"FAIL %s: %s\n",w,CGLErrorString(e));}
int main(void){
    setvbuf(stdout,NULL,_IONBF,0);
    CGLPixelFormatObj pf; GLint npix=0;
    CGLPixelFormatAttribute attrs[]={kCGLPFAPBuffer,kCGLPFAAccelerated,kCGLPFANoRecovery,kCGLPFAColorSize,32,(CGLPixelFormatAttribute)0};
    CGLError err=CGLChoosePixelFormat(attrs,&pf,&npix); if(err||npix==0||!pf){die("CPF",err);return 1;}
    CGLContextObj ctx=NULL; err=CGLCreateContext(pf,NULL,&ctx); if(err){die("CC",err);return 1;}
    CGLDestroyPixelFormat(pf);
    CGLPBufferObj pbuf=NULL; err=CGLCreatePBuffer(32,32,GL_TEXTURE_RECTANGLE_EXT,GL_RGBA,0,&pbuf); if(err){die("CP",err);return 1;}
    err=CGLSetCurrentContext(ctx); if(err){die("SC",err);return 1;}
    err=CGLSetPBuffer(ctx,pbuf,0,0,0); if(err){die("SP",err);return 1;}
    GLubyte block[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
    GLuint t; glGenTextures(1,&t); glBindTexture(GL_TEXTURE_2D,t);
    while(glGetError()!=GL_NO_ERROR){}
    /* try with every size the format might require: 4x4 (standard block), and query compressed size API first */
    GLint fmts=0; glGetIntegerv(GL_NUM_COMPRESSED_TEXTURE_FORMATS, &fmts);
    printf("num compressed formats = %d\n", (int)fmts);
    GLint list[64]; glGetIntegerv(GL_COMPRESSED_TEXTURE_FORMATS, list);
    int i; int found=0;
    for (i=0;i<fmts;i++) { printf("  format[%d] = 0x%04x\n", i, (unsigned)list[i]); if ((unsigned)list[i]==GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI) found=1; }
    printf("GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI (0x8837) present in list = %d\n", found);
    glCompressedTexImage2D(GL_TEXTURE_2D, 0, GL_COMPRESSED_LUMINANCE_ALPHA_3DC_ATI, 4, 4, 0, 8, block);
    printf("4x4 upload error = 0x%04x\n", (unsigned)glGetError());
    return 0;
}
