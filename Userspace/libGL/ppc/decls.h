#include "ghidra_c.h"

extern int _CGLSetCurrentContext();
extern int dyld_stub_binding_helper();
extern int _CGLGetCurrentContext();
extern int FUN_92f27b4c();
extern int _glGetIntegerv();
extern int _glGetBooleanv();
extern int _glGetString();
extern int _glViewport();
extern int _glMatrixMode();
extern int _glLoadIdentity();
extern int _glShadeModel();
extern void _glClearColor(double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int FUN_92f27fc0();
extern int FUN_92f27fc8();
extern void _glClearDepth(double fparam_1);
extern int _glEnable();
extern int _glDepthFunc();
extern int _glHint();
extern int _glBlendFunc();
extern int _glLightfv();
extern int _glDisable();
extern int _glClear();
extern void _glTranslatef(double fparam_1,double fparam_2,double fparam_3);
extern int _glPolygonMode();
extern void _glRotatef(double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern void _glScalef(double fparam_1,double fparam_2,double fparam_3);
extern int _glMaterialfv();
extern int _glPushMatrix();
extern int _glPopMatrix();
extern int _glGenLists();
extern int _glNewList();
extern int _glCullFace();
extern int _glLoadName();
extern void _glColor4f(double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int _glBegin();
extern void _glVertex3d(double fparam_1,double fparam_2,double fparam_3);
extern int _glEnd();
extern void _glLineWidth(double fparam_1);
extern int _glStencilFunc();
extern int _glStencilOp();
extern int _glColorMask();
extern int _glDepthMask();
extern void _glNormal3f(double fparam_1,double fparam_2,double fparam_3);
extern void _glVertex3f(double fparam_1,double fparam_2,double fparam_3);
extern int _glEndList();
extern int _glDeleteLists();
extern void _glTranslated(double fparam_1,double fparam_2,double fparam_3);
extern void _glRotated(double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int _glCallList();
extern int _glReadBuffer();
extern int _glReadPixels();
extern int _glPixelStorei();
extern int _glGenTextures();
extern int _glBindTexture();
extern int _glTexParameteri();
extern void _glTexCoord2f(double fparam_1,double fparam_2);
extern int _glLightModeli();
extern int _glPushAttrib();
extern int _glTexEnvi();
extern void _glMaterialf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glPopAttrib();
extern void _glTexEnvf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern void _glAlphaFunc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glEnableClientState();
extern int _glGetError();
extern int _glFlush();
extern int _glScissor();
extern int _glGetDoublev();
extern void _glRectd(double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int _glColorPointer();
extern int _glVertexPointer();
extern int _glTexCoordPointer();
extern int _glDrawArrays();
extern int _glPrioritizeTextures();
extern int _glTexImage2D();
extern void _glFrustum(double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,
               double fparam_6);
extern int _glLoadMatrixf();
extern void _glPassThrough(double fparam_1);
extern int _glActiveTextureARB();
extern void _glVertex2f(double fparam_1,double fparam_2);
extern void _glMultiTexCoord2f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                       double fparam_2);
extern int _glDeleteTextures();
extern int _glFeedbackBuffer();
extern int _glRenderMode();
extern int _glFogi();
extern int _glFogfv();
extern void _glFogf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glFrontFace();
extern void _glTexParameterf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glGetTexLevelParameteriv();
extern int _glGetFloatv();
extern int _glTexSubImage2D();
extern void _glTexCoord3f(double fparam_1,double fparam_2,double fparam_3);
extern int _glTextureRangeAPPLE();
extern int __dyld_func_lookup();
extern int ___initialize_Cplusplus();
extern int FUN_92f2ab64();
extern void _glAccum(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glAreTexturesResident();
extern int _glArrayElement();
extern void _glBitmap(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
              double fparam_2,double fparam_3,double fparam_4);
extern int _glCallLists();
extern void _glClearAccum(double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern void _glClearIndex(double fparam_1);
extern int _glClearStencil();
extern int _glClipPlane();
extern int _glColor3b();
extern int _glColor3bv();
extern void _glColor3d(double fparam_1,double fparam_2,double fparam_3);
extern int _glColor3dv();
extern void _glColor3f(double fparam_1,double fparam_2,double fparam_3);
extern int _glColor3fv();
extern int _glColor3i();
extern int _glColor3iv();
extern int _glColor3s();
extern int _glColor3sv();
extern int _glColor3ub();
extern int _glColor3ubv();
extern int _glColor3ui();
extern int _glColor3uiv();
extern int _glColor3us();
extern int _glColor3usv();
extern int _glColor4b();
extern int _glColor4bv();
extern void _glColor4d(double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int _glColor4dv();
extern int _glColor4fv();
extern int _glColor4i();
extern int _glColor4iv();
extern int _glColor4s();
extern int _glColor4sv();
extern int _glColor4ub();
extern int _glColor4ubv();
extern int _glColor4ui();
extern int _glColor4uiv();
extern int _glColor4us();
extern int _glColor4usv();
extern int _glColorMaterial();
extern int _glCopyPixels();
extern int _glCopyTexImage1D();
extern int _glCopyTexImage2D();
extern int _glCopyTexSubImage1D();
extern int _glCopyTexSubImage2D();
extern void _glDepthRange(double fparam_1,double fparam_2);
extern int _glDisableClientState();
extern int _glDrawBuffer();
extern int _glDrawElements();
extern int _glDrawPixels();
extern int _glEdgeFlag();
extern int _glEdgeFlagPointer();
extern int _glEdgeFlagv();
extern void _glEvalCoord1d(double fparam_1);
extern int _glEvalCoord1dv();
extern void _glEvalCoord1f(double fparam_1);
extern int _glEvalCoord1fv();
extern void _glEvalCoord2d(double fparam_1,double fparam_2);
extern int _glEvalCoord2dv();
extern void _glEvalCoord2f(double fparam_1,double fparam_2);
extern int _glEvalCoord2fv();
extern int _glEvalMesh1();
extern int _glEvalMesh2();
extern int _glEvalPoint1();
extern int _glEvalPoint2();
extern int _glFinish();
extern int _glFogiv();
extern int _glGetClipPlane();
extern int _glGetLightfv();
extern int _glGetLightiv();
extern int _glGetMapdv();
extern int _glGetMapfv();
extern int _glGetMapiv();
extern int _glGetMaterialfv();
extern int _glGetMaterialiv();
extern int _glGetPixelMapfv();
extern int _glGetPixelMapuiv();
extern int _glGetPixelMapusv();
extern int _glGetPointerv();
extern int _glGetPolygonStipple();
extern int _glGetTexEnvfv();
extern int _glGetTexEnviv();
extern int _glGetTexGendv();
extern int _glGetTexGenfv();
extern int _glGetTexGeniv();
extern int _glGetTexImage();
extern int _glGetTexLevelParameterfv();
extern int _glGetTexParameterfv();
extern int _glGetTexParameteriv();
extern int _glIndexMask();
extern int _glIndexPointer();
extern void _glIndexd(double fparam_1);
extern int _glIndexdv();
extern void _glIndexf(double fparam_1);
extern int _glIndexfv();
extern int _glIndexi();
extern int _glIndexiv();
extern int _glIndexs();
extern int _glIndexsv();
extern int _glIndexub();
extern int _glIndexubv();
extern int _glInitNames();
extern int _glInterleavedArrays();
extern int _glIsEnabled();
extern int _glIsList();
extern int _glIsTexture();
extern void _glLightModelf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glLightModelfv();
extern int _glLightModeliv();
extern void _glLightf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glLighti();
extern int _glLightiv();
extern int _glLineStipple();
extern int _glListBase();
extern int _glLoadMatrixd();
extern int _glLogicOp();
extern void _glMap1d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
             double fparam_1,double fparam_2);
extern void _glMap1f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
             double fparam_2);
extern void _glMap2d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
             double fparam_2,double fparam_3,double fparam_4);
extern void _glMap2f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
             double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern void _glMapGrid1d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                 double fparam_2);
extern void _glMapGrid1f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                 double fparam_2);
extern void _glMapGrid2d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                 double fparam_2,double fparam_3,double fparam_4);
extern void _glMapGrid2f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                 double fparam_2,double fparam_3,double fparam_4);
extern int _glMateriali();
extern int _glMaterialiv();
extern int _glMultMatrixd();
extern int _glMultMatrixf();
extern int _glNormal3b();
extern int _glNormal3bv();
extern void _glNormal3d(double fparam_1,double fparam_2,double fparam_3);
extern int _glNormal3dv();
extern int _glNormal3fv();
extern int _glNormal3i();
extern int _glNormal3iv();
extern int _glNormal3s();
extern int _glNormal3sv();
extern int _glNormalPointer();
extern void _glOrtho(double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,
             double fparam_6);
extern int _glPixelMapfv();
extern int _glPixelMapuiv();
extern int _glPixelMapusv();
extern void _glPixelStoref(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern void _glPixelTransferf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glPixelTransferi();
extern void _glPixelZoom(double fparam_1,double fparam_2);
extern void _glPointSize(double fparam_1);
extern void _glPolygonOffset(double fparam_1,double fparam_2);
extern int _glPolygonStipple();
extern int _glPopClientAttrib();
extern int _glPopName();
extern int _glPushClientAttrib();
extern int _glPushName();
extern void _glRasterPos2d(double fparam_1,double fparam_2);
extern int _glRasterPos2dv();
extern void _glRasterPos2f(double fparam_1,double fparam_2);
extern int _glRasterPos2fv();
extern int _glRasterPos2i();
extern int _glRasterPos2iv();
extern int _glRasterPos2s();
extern int _glRasterPos2sv();
extern void _glRasterPos3d(double fparam_1,double fparam_2,double fparam_3);
extern int _glRasterPos3dv();
extern void _glRasterPos3f(double fparam_1,double fparam_2,double fparam_3);
extern int _glRasterPos3fv();
extern int _glRasterPos3i();
extern int _glRasterPos3iv();
extern int _glRasterPos3s();
extern int _glRasterPos3sv();
extern void _glRasterPos4d(double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int _glRasterPos4dv();
extern void _glRasterPos4f(double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int _glRasterPos4fv();
extern int _glRasterPos4i();
extern int _glRasterPos4iv();
extern int _glRasterPos4s();
extern int _glRasterPos4sv();
extern int _glRectdv();
extern void _glRectf(double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int _glRectfv();
extern int _glRecti();
extern int _glRectiv();
extern int _glRects();
extern int _glRectsv();
extern void _glScaled(double fparam_1,double fparam_2,double fparam_3);
extern int _glSelectBuffer();
extern int _glStencilMask();
extern void _glTexCoord1d(double fparam_1);
extern int _glTexCoord1dv();
extern void _glTexCoord1f(double fparam_1);
extern int _glTexCoord1fv();
extern int _glTexCoord1i();
extern int _glTexCoord1iv();
extern int _glTexCoord1s();
extern int _glTexCoord1sv();
extern void _glTexCoord2d(double fparam_1,double fparam_2);
extern int _glTexCoord2dv();
extern int _glTexCoord2fv();
extern int _glTexCoord2i();
extern int _glTexCoord2iv();
extern int _glTexCoord2s();
extern int _glTexCoord2sv();
extern void _glTexCoord3d(double fparam_1,double fparam_2,double fparam_3);
extern int _glTexCoord3dv();
extern int _glTexCoord3fv();
extern int _glTexCoord3i();
extern int _glTexCoord3iv();
extern int _glTexCoord3s();
extern int _glTexCoord3sv();
extern void _glTexCoord4d(double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int _glTexCoord4dv();
extern void _glTexCoord4f(double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int _glTexCoord4fv();
extern int _glTexCoord4i();
extern int _glTexCoord4iv();
extern int _glTexCoord4s();
extern int _glTexCoord4sv();
extern int _glTexEnvfv();
extern int _glTexEnviv();
extern void _glTexGend(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glTexGendv();
extern void _glTexGenf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glTexGenfv();
extern int _glTexGeni();
extern int _glTexGeniv();
extern int _glTexImage1D();
extern int _glTexParameterfv();
extern int _glTexParameteriv();
extern int _glTexSubImage1D();
extern void _glVertex2d(double fparam_1,double fparam_2);
extern int _glVertex2dv();
extern int _glVertex2fv();
extern int _glVertex2i();
extern int _glVertex2iv();
extern int _glVertex2s();
extern int _glVertex2sv();
extern int _glVertex3dv();
extern int _glVertex3fv();
extern int _glVertex3i();
extern int _glVertex3iv();
extern int _glVertex3s();
extern int _glVertex3sv();
extern void _glVertex4d(double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int _glVertex4dv();
extern void _glVertex4f(double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int _glVertex4fv();
extern int _glVertex4i();
extern int _glVertex4iv();
extern int _glVertex4s();
extern int _glVertex4sv();
extern void _glBlendColor(double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int _glBlendEquation();
extern int _glDrawRangeElements();
extern int _glTexImage3D();
extern int _glTexSubImage3D();
extern int _glCopyTexSubImage3D();
extern int _glColorTable();
extern int _glColorTableParameterfv();
extern int _glColorTableParameteriv();
extern int _glCopyColorTable();
extern int _glGetColorTable();
extern int _glGetColorTableParameterfv();
extern int _glGetColorTableParameteriv();
extern int _glColorSubTable();
extern int _glCopyColorSubTable();
extern int _glConvolutionFilter1D();
extern int _glConvolutionFilter2D();
extern void _glConvolutionParameterf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glConvolutionParameterfv();
extern int _glConvolutionParameteri();
extern int _glConvolutionParameteriv();
extern int _glCopyConvolutionFilter1D();
extern int _glCopyConvolutionFilter2D();
extern int _glGetConvolutionFilter();
extern int _glGetConvolutionParameterfv();
extern int _glGetConvolutionParameteriv();
extern int _glGetSeparableFilter();
extern int _glSeparableFilter2D();
extern int _glGetHistogram();
extern int _glGetHistogramParameterfv();
extern int _glGetHistogramParameteriv();
extern int _glGetMinmax();
extern int _glGetMinmaxParameterfv();
extern int _glGetMinmaxParameteriv();
extern int _glHistogram();
extern int _glMinmax();
extern int _glResetHistogram();
extern int _glResetMinmax();
extern int _glClientActiveTexture();
extern int _glActiveTexture();
extern void _glMultiTexCoord1d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glMultiTexCoord1dv();
extern void _glMultiTexCoord1f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glMultiTexCoord1fv();
extern int _glMultiTexCoord1i();
extern int _glMultiTexCoord1iv();
extern int _glMultiTexCoord1s();
extern int _glMultiTexCoord1sv();
extern void _glMultiTexCoord2d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                       double fparam_2);
extern int _glMultiTexCoord2dv();
extern int _glMultiTexCoord2fv();
extern int _glMultiTexCoord2i();
extern int _glMultiTexCoord2iv();
extern int _glMultiTexCoord2s();
extern int _glMultiTexCoord2sv();
extern void _glMultiTexCoord3d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                       double fparam_2,double fparam_3);
extern int _glMultiTexCoord3dv();
extern void _glMultiTexCoord3f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                       double fparam_2,double fparam_3);
extern int _glMultiTexCoord3fv();
extern int _glMultiTexCoord3i();
extern int _glMultiTexCoord3iv();
extern int _glMultiTexCoord3s();
extern int _glMultiTexCoord3sv();
extern void _glMultiTexCoord4d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                       double fparam_2,double fparam_3,double fparam_4);
extern int _glMultiTexCoord4dv();
extern void _glMultiTexCoord4f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                       double fparam_2,double fparam_3,double fparam_4);
extern int _glMultiTexCoord4fv();
extern int _glMultiTexCoord4i();
extern int _glMultiTexCoord4iv();
extern int _glMultiTexCoord4s();
extern int _glMultiTexCoord4sv();
extern int _glLoadTransposeMatrixd();
extern int _glLoadTransposeMatrixf();
extern int _glMultTransposeMatrixd();
extern int _glMultTransposeMatrixf();
extern int _glCompressedTexImage3D();
extern int _glCompressedTexImage2D();
extern int _glCompressedTexImage1D();
extern int _glCompressedTexSubImage3D();
extern int _glCompressedTexSubImage2D();
extern int _glCompressedTexSubImage1D();
extern int _glGetCompressedTexImage();
extern void _glSampleCoverage(undefined4 param_1,undefined4 param_2,double fparam_1);
extern int _glSamplePass();
extern void _glFogCoordf(double fparam_1);
extern int _glFogCoordfv();
extern void _glFogCoordd(double fparam_1);
extern int _glFogCoorddv();
extern int _glFogCoordPointer();
extern int _glSecondaryColor3b();
extern int _glSecondaryColor3bv();
extern void _glSecondaryColor3d(double fparam_1,double fparam_2,double fparam_3);
extern int _glSecondaryColor3dv();
extern void _glSecondaryColor3f(double fparam_1,double fparam_2,double fparam_3);
extern int _glSecondaryColor3fv();
extern int _glSecondaryColor3i();
extern int _glSecondaryColor3iv();
extern int _glSecondaryColor3s();
extern int _glSecondaryColor3sv();
extern int _glSecondaryColor3ub();
extern int _glSecondaryColor3ubv();
extern int _glSecondaryColor3ui();
extern int _glSecondaryColor3uiv();
extern int _glSecondaryColor3us();
extern int _glSecondaryColor3usv();
extern int _glSecondaryColorPointer();
extern void _glPointParameterf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glPointParameterfv();
extern int _glPointParameteri();
extern int _glPointParameteriv();
extern int _glBlendFuncSeparate();
extern int _glMultiDrawArrays();
extern int _glMultiDrawElements();
extern void _glWindowPos2d(double fparam_1,double fparam_2);
extern int _glWindowPos2dv();
extern void _glWindowPos2f(double fparam_1,double fparam_2);
extern int _glWindowPos2fv();
extern int _glWindowPos2i();
extern int _glWindowPos2iv();
extern int _glWindowPos2s();
extern int _glWindowPos2sv();
extern void _glWindowPos3d(double fparam_1,double fparam_2,double fparam_3);
extern int _glWindowPos3dv();
extern void _glWindowPos3f(double fparam_1,double fparam_2,double fparam_3);
extern int _glWindowPos3fv();
extern int _glWindowPos3i();
extern int _glWindowPos3iv();
extern int _glWindowPos3s();
extern int _glWindowPos3sv();
extern int _glGenQueries();
extern int _glDeleteQueries();
extern int _glIsQuery();
extern int _glBeginQuery();
extern int _glEndQuery();
extern int _glGetQueryiv();
extern int _glGetQueryObjectiv();
extern int _glGetQueryObjectuiv();
extern int _glBindBuffer();
extern int _glDeleteBuffers();
extern int _glGenBuffers();
extern int _glIsBuffer();
extern int _glBufferData();
extern int _glBufferSubData();
extern int _glGetBufferSubData();
extern int _glMapBuffer();
extern int _glUnmapBuffer();
extern int _glGetBufferParameteriv();
extern int _glGetBufferPointerv();
extern int _glDrawBuffers();
extern void _glVertexAttrib1d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glVertexAttrib1dv();
extern void _glVertexAttrib1f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glVertexAttrib1fv();
extern int _glVertexAttrib1s();
extern int _glVertexAttrib1sv();
extern void _glVertexAttrib2d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                      double fparam_2);
extern int _glVertexAttrib2dv();
extern void _glVertexAttrib2f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                      double fparam_2);
extern int _glVertexAttrib2fv();
extern int _glVertexAttrib2s();
extern int _glVertexAttrib2sv();
extern void _glVertexAttrib3d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                      double fparam_2,double fparam_3);
extern int _glVertexAttrib3dv();
extern void _glVertexAttrib3f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                      double fparam_2,double fparam_3);
extern int _glVertexAttrib3fv();
extern int _glVertexAttrib3s();
extern int _glVertexAttrib3sv();
extern int _glVertexAttrib4Nbv();
extern int _glVertexAttrib4Niv();
extern int _glVertexAttrib4Nsv();
extern int _glVertexAttrib4Nub();
extern int _glVertexAttrib4Nubv();
extern int _glVertexAttrib4Nuiv();
extern int _glVertexAttrib4Nusv();
extern int _glVertexAttrib4bv();
extern void _glVertexAttrib4d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                      double fparam_2,double fparam_3,double fparam_4);
extern int _glVertexAttrib4dv();
extern void _glVertexAttrib4f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                      double fparam_2,double fparam_3,double fparam_4);
extern int _glVertexAttrib4fv();
extern int _glVertexAttrib4iv();
extern int _glVertexAttrib4s();
extern int _glVertexAttrib4sv();
extern int _glVertexAttrib4ubv();
extern int _glVertexAttrib4uiv();
extern int _glVertexAttrib4usv();
extern int _glVertexAttribPointer();
extern int _glEnableVertexAttribArray();
extern int _glDisableVertexAttribArray();
extern int _glGetVertexAttribdv();
extern int _glGetVertexAttribfv();
extern int _glGetVertexAttribiv();
extern int _glGetVertexAttribPointerv();
extern int _glDeleteShader();
extern int _glDetachShader();
extern int _glCreateShader();
extern int _glShaderSource();
extern int _glCompileShader();
extern int _glCreateProgram();
extern int _glAttachShader();
extern int _glLinkProgram();
extern int _glUseProgram();
extern int _glDeleteProgram();
extern int _glValidateProgram();
extern void _glUniform1f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern void _glUniform2f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                 double fparam_2);
extern void _glUniform3f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                 double fparam_2,double fparam_3);
extern void _glUniform4f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                 double fparam_2,double fparam_3,double fparam_4);
extern int _glUniform1i();
extern int _glUniform2i();
extern int _glUniform3i();
extern int _glUniform4i();
extern int _glUniform1fv();
extern int _glUniform2fv();
extern int _glUniform3fv();
extern int _glUniform4fv();
extern int _glUniform1iv();
extern int _glUniform2iv();
extern int _glUniform3iv();
extern int _glUniform4iv();
extern int _glUniformMatrix2fv();
extern int _glUniformMatrix3fv();
extern int _glUniformMatrix4fv();
extern int _glIsShader();
extern int _glIsProgram();
extern int _glGetShaderiv();
extern int _glGetProgramiv();
extern int _glGetAttachedShaders();
extern int _glGetShaderInfoLog();
extern int _glGetProgramInfoLog();
extern int _glGetUniformLocation();
extern int _glGetActiveUniform();
extern int _glGetUniformfv();
extern int _glGetUniformiv();
extern int _glGetShaderSource();
extern int _glBindAttribLocation();
extern int _glGetActiveAttrib();
extern int _glGetAttribLocation();
extern int _glStencilFuncSeparate();
extern int _glStencilOpSeparate();
extern int _glStencilMaskSeparate();
extern int _glBlendEquationSeparate();
extern int _glBindProgramARB();
extern int _glDeleteProgramsARB();
extern int _glGenProgramsARB();
extern int _glIsProgramARB();
extern int _glVertexAttrib1sARB();
extern void _glVertexAttrib1fARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern void _glVertexAttrib1dARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glVertexAttrib2sARB();
extern void _glVertexAttrib2fARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
               double fparam_2);
extern void _glVertexAttrib2dARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
               double fparam_2);
extern int _glVertexAttrib3sARB();
extern void _glVertexAttrib3fARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
               double fparam_2,double fparam_3);
extern void _glVertexAttrib3dARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
               double fparam_2,double fparam_3);
extern int _glVertexAttrib4sARB();
extern void _glVertexAttrib4fARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
               double fparam_2,double fparam_3,double fparam_4);
extern void _glVertexAttrib4dARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
               double fparam_2,double fparam_3,double fparam_4);
extern int _glVertexAttrib4NubARB();
extern int _glVertexAttrib1svARB();
extern int _glVertexAttrib1fvARB();
extern int _glVertexAttrib1dvARB();
extern int _glVertexAttrib2svARB();
extern int _glVertexAttrib2fvARB();
extern int _glVertexAttrib2dvARB();
extern int _glVertexAttrib3svARB();
extern int _glVertexAttrib3fvARB();
extern int _glVertexAttrib3dvARB();
extern int _glVertexAttrib4bvARB();
extern int _glVertexAttrib4svARB();
extern int _glVertexAttrib4ivARB();
extern int _glVertexAttrib4ubvARB();
extern int _glVertexAttrib4usvARB();
extern int _glVertexAttrib4uivARB();
extern int _glVertexAttrib4fvARB();
extern int _glVertexAttrib4dvARB();
extern int _glVertexAttrib4NbvARB();
extern int _glVertexAttrib4NsvARB();
extern int _glVertexAttrib4NivARB();
extern int _glVertexAttrib4NubvARB();
extern int _glVertexAttrib4NusvARB();
extern int _glVertexAttrib4NuivARB();
extern int _glVertexAttribPointerARB();
extern int _glEnableVertexAttribArrayARB();
extern int _glDisableVertexAttribArrayARB();
extern int _glGetVertexAttribdvARB();
extern int _glGetVertexAttribfvARB();
extern int _glGetVertexAttribivARB();
extern int _glGetVertexAttribPointervARB();
extern void _glProgramEnvParameter4dARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
               double fparam_2,double fparam_3,double fparam_4);
extern int _glProgramEnvParameter4dvARB();
extern void _glProgramEnvParameter4fARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
               double fparam_2,double fparam_3,double fparam_4);
extern int _glProgramEnvParameter4fvARB();
extern void _glProgramLocalParameter4dARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
               double fparam_2,double fparam_3,double fparam_4);
extern int _glProgramLocalParameter4dvARB();
extern void _glProgramLocalParameter4fARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
               double fparam_2,double fparam_3,double fparam_4);
extern int _glProgramLocalParameter4fvARB();
extern int _glGetProgramEnvParameterdvARB();
extern int _glGetProgramEnvParameterfvARB();
extern int _glGetProgramLocalParameterdvARB();
extern int _glGetProgramLocalParameterfvARB();
extern int _glProgramStringARB();
extern int _glGetProgramStringARB();
extern int _glGetProgramivARB();
extern int _glWeightbvARB();
extern int _glWeightsvARB();
extern int _glWeightivARB();
extern int _glWeightfvARB();
extern int _glWeightdvARB();
extern int _glWeightubvARB();
extern int _glWeightusvARB();
extern int _glWeightuivARB();
extern int _glWeightPointerARB();
extern int _glVertexBlendARB();
extern int _glClientActiveTextureARB();
extern void _glMultiTexCoord1dARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glMultiTexCoord1dvARB();
extern void _glMultiTexCoord1fARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glMultiTexCoord1fvARB();
extern int _glMultiTexCoord1iARB();
extern int _glMultiTexCoord1ivARB();
extern int _glMultiTexCoord1sARB();
extern int _glMultiTexCoord1svARB();
extern void _glMultiTexCoord2dARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
               double fparam_2);
extern int _glMultiTexCoord2dvARB();
extern void _glMultiTexCoord2fARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
               double fparam_2);
extern int _glMultiTexCoord2fvARB();
extern int _glMultiTexCoord2iARB();
extern int _glMultiTexCoord2ivARB();
extern int _glMultiTexCoord2sARB();
extern int _glMultiTexCoord2svARB();
extern void _glMultiTexCoord3dARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
               double fparam_2,double fparam_3);
extern int _glMultiTexCoord3dvARB();
extern void _glMultiTexCoord3fARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
               double fparam_2,double fparam_3);
extern int _glMultiTexCoord3fvARB();
extern int _glMultiTexCoord3iARB();
extern int _glMultiTexCoord3ivARB();
extern int _glMultiTexCoord3sARB();
extern int _glMultiTexCoord3svARB();
extern void _glMultiTexCoord4dARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
               double fparam_2,double fparam_3,double fparam_4);
extern int _glMultiTexCoord4dvARB();
extern void _glMultiTexCoord4fARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
               double fparam_2,double fparam_3,double fparam_4);
extern int _glMultiTexCoord4fvARB();
extern int _glMultiTexCoord4iARB();
extern int _glMultiTexCoord4ivARB();
extern int _glMultiTexCoord4sARB();
extern int _glMultiTexCoord4svARB();
extern int _glLoadTransposeMatrixdARB();
extern int _glLoadTransposeMatrixfARB();
extern int _glMultTransposeMatrixdARB();
extern int _glMultTransposeMatrixfARB();
extern int _glCompressedTexImage3DARB();
extern int _glCompressedTexImage2DARB();
extern int _glCompressedTexImage1DARB();
extern int _glCompressedTexSubImage3DARB();
extern int _glCompressedTexSubImage2DARB();
extern int _glCompressedTexSubImage1DARB();
extern int _glGetCompressedTexImageARB();
extern void _glSampleCoverageARB(undefined4 param_1,undefined4 param_2,double fparam_1);
extern int _glSamplePassARB();
extern void _glPointParameterfARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glPointParameterfvARB();
extern void _glWindowPos2dARB(double fparam_1,double fparam_2);
extern int _glWindowPos2dvARB();
extern void _glWindowPos2fARB(double fparam_1,double fparam_2);
extern int _glWindowPos2fvARB();
extern int _glWindowPos2iARB();
extern int _glWindowPos2ivARB();
extern int _glWindowPos2sARB();
extern int _glWindowPos2svARB();
extern void _glWindowPos3dARB(double fparam_1,double fparam_2,double fparam_3);
extern int _glWindowPos3dvARB();
extern void _glWindowPos3fARB(double fparam_1,double fparam_2,double fparam_3);
extern int _glWindowPos3fvARB();
extern int _glWindowPos3iARB();
extern int _glWindowPos3ivARB();
extern int _glWindowPos3sARB();
extern int _glWindowPos3svARB();
extern int _glGenQueriesARB();
extern int _glDeleteQueriesARB();
extern int _glIsQueryARB();
extern int _glBeginQueryARB();
extern int _glEndQueryARB();
extern int _glGetQueryivARB();
extern int _glGetQueryObjectivARB();
extern int _glGetQueryObjectuivARB();
extern int _glBindBufferARB();
extern int _glDeleteBuffersARB();
extern int _glGenBuffersARB();
extern int _glIsBufferARB();
extern int _glBufferDataARB();
extern int _glBufferSubDataARB();
extern int _glGetBufferSubDataARB();
extern int _glMapBufferARB();
extern int _glUnmapBufferARB();
extern int _glGetBufferParameterivARB();
extern int _glGetBufferPointervARB();
extern int _glDeleteObjectARB();
extern int _glGetHandleARB();
extern int _glDetachObjectARB();
extern int _glCreateShaderObjectARB();
extern int _glShaderSourceARB();
extern int _glCompileShaderARB();
extern int _glCreateProgramObjectARB();
extern int _glAttachObjectARB();
extern int _glLinkProgramARB();
extern int _glUseProgramObjectARB();
extern int _glValidateProgramARB();
extern void _glUniform1fARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern void _glUniform2fARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                    double fparam_2);
extern void _glUniform3fARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                    double fparam_2,double fparam_3);
extern void _glUniform4fARB(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                    double fparam_2,double fparam_3,double fparam_4);
extern int _glUniform1iARB();
extern int _glUniform2iARB();
extern int _glUniform3iARB();
extern int _glUniform4iARB();
extern int _glUniform1fvARB();
extern int _glUniform2fvARB();
extern int _glUniform3fvARB();
extern int _glUniform4fvARB();
extern int _glUniform1ivARB();
extern int _glUniform2ivARB();
extern int _glUniform3ivARB();
extern int _glUniform4ivARB();
extern int _glUniformMatrix2fvARB();
extern int _glUniformMatrix3fvARB();
extern int _glUniformMatrix4fvARB();
extern int _glGetObjectParameterfvARB();
extern int _glGetObjectParameterivARB();
extern int _glGetInfoLogARB();
extern int _glGetAttachedObjectsARB();
extern int _glGetUniformLocationARB();
extern int _glGetActiveUniformARB();
extern int _glGetUniformfvARB();
extern int _glGetUniformivARB();
extern int _glGetShaderSourceARB();
extern int _glBindAttribLocationARB();
extern int _glGetActiveAttribARB();
extern int _glGetAttribLocationARB();
extern int _glDrawBuffersARB();
extern int _glLockArraysEXT();
extern int _glUnlockArraysEXT();
extern int _glActiveStencilFaceEXT();
extern void _glDepthBoundsEXT(double fparam_1,double fparam_2);
extern int _glColorTableEXT();
extern int _glColorSubTableEXT();
extern int _glGetColorTableEXT();
extern int _glGetColorTableParameterfvEXT();
extern int _glGetColorTableParameterivEXT();
extern int _glSecondaryColor3bEXT();
extern int _glSecondaryColor3bvEXT();
extern void _glSecondaryColor3dEXT(double fparam_1,double fparam_2,double fparam_3);
extern int _glSecondaryColor3dvEXT();
extern void _glSecondaryColor3fEXT(double fparam_1,double fparam_2,double fparam_3);
extern int _glSecondaryColor3fvEXT();
extern int _glSecondaryColor3iEXT();
extern int _glSecondaryColor3ivEXT();
extern int _glSecondaryColor3sEXT();
extern int _glSecondaryColor3svEXT();
extern int _glSecondaryColor3ubEXT();
extern int _glSecondaryColor3ubvEXT();
extern int _glSecondaryColor3uiEXT();
extern int _glSecondaryColor3uivEXT();
extern int _glSecondaryColor3usEXT();
extern int _glSecondaryColor3usvEXT();
extern int _glSecondaryColorPointerEXT();
extern void _glFogCoordfEXT(double fparam_1);
extern int _glFogCoordfvEXT();
extern void _glFogCoorddEXT(double fparam_1);
extern int _glFogCoorddvEXT();
extern int _glFogCoordPointerEXT();
extern int _glDrawRangeElementsEXT();
extern int _glBlendFuncSeparateEXT();
extern int _glMultiDrawArraysEXT();
extern int _glMultiDrawElementsEXT();
extern void _glBlendColorEXT(double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern int _glBlendEquationEXT();
extern int _glBlendEquationSeparateEXT();
extern int _glIsRenderbufferEXT();
extern int _glBindRenderbufferEXT();
extern int _glDeleteRenderbuffersEXT();
extern int _glGenRenderbuffersEXT();
extern int _glRenderbufferStorageEXT();
extern int _glGetRenderbufferParameterivEXT();
extern int _glIsFramebufferEXT();
extern int _glBindFramebufferEXT();
extern int _glDeleteFramebuffersEXT();
extern int _glGenFramebuffersEXT();
extern int _glCheckFramebufferStatusEXT();
extern int _glFramebufferTexture1DEXT();
extern int _glFramebufferTexture2DEXT();
extern int _glFramebufferTexture3DEXT();
extern int _glFramebufferRenderbufferEXT();
extern int _glGetFramebufferAttachmentParameterivEXT();
extern int _glGenerateMipmapEXT();
extern int _glEnableVertexAttribAPPLE();
extern int _glDisableVertexAttribAPPLE();
extern int _glIsVertexAttribEnabledAPPLE();
extern void _glMapVertexAttrib1dAPPLE(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               double fparam_1,double fparam_2);
extern void _glMapVertexAttrib1fAPPLE(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
               double fparam_2);
extern void _glMapVertexAttrib2dAPPLE(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
               double fparam_1,double fparam_2,double fparam_3,double fparam_4);
extern void _glMapVertexAttrib2fAPPLE(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3
               ,double fparam_4);
extern int _glGetTexParameterPointervAPPLE();
extern int _glGenFencesAPPLE();
extern int _glDeleteFencesAPPLE();
extern int _glSetFenceAPPLE();
extern int _glIsFenceAPPLE();
extern int _glTestFenceAPPLE();
extern int _glFinishFenceAPPLE();
extern int _glTestObjectAPPLE();
extern int _glFinishObjectAPPLE();
extern int _glVertexArrayRangeAPPLE();
extern int _glFlushVertexArrayRangeAPPLE();
extern int _glVertexArrayParameteriAPPLE();
extern int _glBindVertexArrayAPPLE();
extern int _glDeleteVertexArraysAPPLE();
extern int _glGenVertexArraysAPPLE();
extern int _glIsVertexArrayAPPLE();
extern int _glElementPointerAPPLE();
extern int _glDrawElementArrayAPPLE();
extern int _glDrawRangeElementArrayAPPLE();
extern int _glMultiDrawElementArrayAPPLE();
extern int _glMultiDrawRangeElementArrayAPPLE();
extern int _glFlushRenderAPPLE();
extern int _glFinishRenderAPPLE();
extern int _glSwapAPPLE();
extern int _glBlendEquationSeparateATI();
extern int _glStencilOpSeparateATI();
extern int _glStencilFuncSeparateATI();
extern int _glPNTrianglesiATI();
extern void _glPNTrianglesfATI(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                       undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glPNTrianglesiATIX();
extern void _glPNTrianglesfATIX(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        ,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glPointParameteriNV();
extern int _glPointParameterivNV();
extern int _glCombinerParameterfvNV();
extern void _glCombinerParameterfNV(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1);
extern int _glCombinerParameterivNV();
extern int _glCombinerParameteriNV();
extern int _glCombinerInputNV();
extern int _glCombinerOutputNV();
extern int _glFinalCombinerInputNV();
extern int _glGetCombinerInputParameterfvNV();
extern int _glGetCombinerInputParameterivNV();
extern int _glGetCombinerOutputParameterfvNV();
extern int _glGetCombinerOutputParameterivNV();
extern int _glGetFinalCombinerInputParameterfvNV();
extern int _glGetFinalCombinerInputParameterivNV();
extern int _glCombinerStageParameterfvNV();
extern int _glGetCombinerStageParameterfvNV();
extern int _pthread_getspecific();
extern int _pthread_setspecific();
extern unsigned char PTR___mh_dylib_header_a2f27018;
extern unsigned char PTR__gll_cc_a2f27020;
extern unsigned char PTR__gll_pkey_a2f2701c;
#include "extra_decls.h"
