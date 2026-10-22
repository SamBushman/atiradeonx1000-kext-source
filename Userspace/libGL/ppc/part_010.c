#include "decls.h"

/* _glVertexAttrib3fARB @ 0x92f3bc98 (172 bytes) */
void _glVertexAttrib3fARB(undefined4 indexArg,undefined4 xShadow,undefined4 yShadow,undefined4 zShadow,undefined4 fwdReg5,undefined4 fwdReg6,undefined4 fwdReg7,double x,double y,double z)
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)glContext[0x1e3])(x,y,z,*glContext,indexArg);
  return;
}

/* _glVertexAttrib3dARB @ 0x92f3bd44 (172 bytes) */
void _glVertexAttrib3dARB(undefined4 indexArg,undefined4 xShadowHi,undefined4 xShadowLo,undefined4 yShadowHi,undefined4 yShadowLo,undefined4 zShadowHi,undefined4 zShadowLo,double x,double y,double z)
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)glContext[0x1e4])(x,y,z,*glContext,indexArg);
  return;
}

/* _glVertexAttrib4sARB @ 0x92f3bdf0 (156 bytes) */
int _glVertexAttrib4sARB(indexArg, x, y, z, w, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 x;
  undefined4 y;
  undefined4 z;
  undefined4 w;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)glContext[0x1e5])(*glContext,indexArg,x,y,z,w);
  return;
}

/* _glVertexAttrib4fARB @ 0x92f3be8c (172 bytes) */
void _glVertexAttrib4fARB(undefined4 indexArg,undefined4 xShadow,undefined4 yShadow,undefined4 zShadow,undefined4 wShadow,undefined4 fwdReg6,undefined4 fwdReg7,double x,double y,double z,double w)
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff80)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff80);
  }
                    
                    
  (*(code *)glContext[0x1e6])(x,y,z,w,*glContext,indexArg);
  return;
}

/* _glVertexAttrib4dARB @ 0x92f3bf38 (152 bytes) */
void _glVertexAttrib4dARB(undefined4 indexArg,undefined4 xShadowHi,undefined4 xShadowLo,undefined4 yShadowHi,undefined4 yShadowLo,undefined4 zShadowHi,undefined4 zShadowLo,double x,double y,double z,double w)
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff80)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff80);
  }
  (*(code *)glContext[0x1e7])(x,y,z,w,*glContext,indexArg);
  return;
}

/* _glVertexAttrib4NubARB @ 0x92f3bfd0 (156 bytes) */
int _glVertexAttrib4NubARB(indexArg, x, y, z, w, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 x;
  undefined4 y;
  undefined4 z;
  undefined4 w;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)glContext[0x1e8])(*glContext,indexArg,x,y,z,w);
  return;
}

/* _glVertexAttrib1svARB @ 0x92f3c06c (132 bytes) */
int _glVertexAttrib1svARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1e9])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib1fvARB @ 0x92f3c0f0 (132 bytes) */
int _glVertexAttrib1fvARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1ea])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib1dvARB @ 0x92f3c174 (132 bytes) */
int _glVertexAttrib1dvARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1eb])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib2svARB @ 0x92f3c1f8 (132 bytes) */
int _glVertexAttrib2svARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1ec])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib2fvARB @ 0x92f3c27c (132 bytes) */
int _glVertexAttrib2fvARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1ed])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib2dvARB @ 0x92f3c300 (132 bytes) */
int _glVertexAttrib2dvARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1ee])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib3svARB @ 0x92f3c384 (132 bytes) */
int _glVertexAttrib3svARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1ef])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib3fvARB @ 0x92f3c408 (132 bytes) */
int _glVertexAttrib3fvARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1f0])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib3dvARB @ 0x92f3c48c (132 bytes) */
int _glVertexAttrib3dvARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1f1])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib4bvARB @ 0x92f3c510 (132 bytes) */
int _glVertexAttrib4bvARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1f2])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib4svARB @ 0x92f3c594 (132 bytes) */
int _glVertexAttrib4svARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[499])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib4ivARB @ 0x92f3c618 (132 bytes) */
int _glVertexAttrib4ivARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[500])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib4ubvARB @ 0x92f3c69c (132 bytes) */
int _glVertexAttrib4ubvARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1f5])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib4usvARB @ 0x92f3c720 (132 bytes) */
int _glVertexAttrib4usvARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1f6])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib4uivARB @ 0x92f3c7a4 (132 bytes) */
int _glVertexAttrib4uivARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1f7])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib4fvARB @ 0x92f3c828 (132 bytes) */
int _glVertexAttrib4fvARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1f8])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib4dvARB @ 0x92f3c8ac (132 bytes) */
int _glVertexAttrib4dvARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1f9])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib4NbvARB @ 0x92f3c930 (132 bytes) */
int _glVertexAttrib4NbvARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1fa])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib4NsvARB @ 0x92f3c9b4 (132 bytes) */
int _glVertexAttrib4NsvARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1fb])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib4NivARB @ 0x92f3ca38 (132 bytes) */
int _glVertexAttrib4NivARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1fc])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib4NubvARB @ 0x92f3cabc (132 bytes) */
int _glVertexAttrib4NubvARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1fd])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib4NusvARB @ 0x92f3cb40 (132 bytes) */
int _glVertexAttrib4NusvARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1fe])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttrib4NuivARB @ 0x92f3cbc4 (132 bytes) */
int _glVertexAttrib4NuivARB(indexArg, v, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 v;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x1ff])(*glContext,indexArg,v);
  return;
}

/* _glVertexAttribPointerARB @ 0x92f3cc48 (164 bytes) */
int _glVertexAttribPointerARB(indexArg, size, type, normalized, stride, pointer, fwdReg7)
  undefined4 indexArg;
  undefined4 size;
  undefined4 type;
  undefined4 normalized;
  undefined4 stride;
  undefined4 pointer;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)glContext[0x200])(*glContext,indexArg,size,type,normalized,stride,pointer);
  return;
}

/* _glEnableVertexAttribArrayARB @ 0x92f3ccec (124 bytes) */
int _glEnableVertexAttribArrayARB(indexArg, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 fwdReg2;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x201])(*glContext,indexArg);
  return;
}

/* _glDisableVertexAttribArrayARB @ 0x92f3cd68 (124 bytes) */
int _glDisableVertexAttribArrayARB(indexArg, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 fwdReg2;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x202])(*glContext,indexArg);
  return;
}

/* _glGetVertexAttribdvARB @ 0x92f3cde4 (140 bytes) */
int _glGetVertexAttribdvARB(indexArg, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 pname;
  undefined4 params;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x203])(*glContext,indexArg,pname,params);
  return;
}

/* _glGetVertexAttribfvARB @ 0x92f3ce70 (140 bytes) */
int _glGetVertexAttribfvARB(indexArg, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 pname;
  undefined4 params;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x204])(*glContext,indexArg,pname,params);
  return;
}

/* _glGetVertexAttribivARB @ 0x92f3cefc (140 bytes) */
int _glGetVertexAttribivARB(indexArg, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 pname;
  undefined4 params;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x205])(*glContext,indexArg,pname,params);
  return;
}

/* _glGetVertexAttribPointervARB @ 0x92f3cf88 (140 bytes) */
int _glGetVertexAttribPointervARB(indexArg, pname, pointer, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 pname;
  undefined4 pointer;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x206])(*glContext,indexArg,pname,pointer);
  return;
}

/* _glProgramEnvParameter4dARB @ 0x92f3d014 (160 bytes) */
void _glProgramEnvParameter4dARB(undefined4 target,undefined4 indexArg,undefined4 xShadowHi,undefined4 xShadowLo,undefined4 yShadowHi,undefined4 yShadowLo,undefined4 zShadowHi,double x,double y,double z,double w)
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff70)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff70);
  }
  (*(code *)glContext[0x207])(x,y,z,w,*glContext,target,indexArg);
  return;
}

/* _glProgramEnvParameter4dvARB @ 0x92f3d0b4 (140 bytes) */
int _glProgramEnvParameter4dvARB(target, indexArg, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 indexArg;
  undefined4 params;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x208])(*glContext,target,indexArg,params);
  return;
}

/* _glProgramEnvParameter4fARB @ 0x92f3d140 (180 bytes) */
void _glProgramEnvParameter4fARB(undefined4 target,undefined4 indexArg,undefined4 xShadow,undefined4 yShadow,undefined4 zShadow,undefined4 wShadow,undefined4 fwdReg7,double x,double y,double z,double w)
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff80)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff80);
  }
                    
                    
  (*(code *)glContext[0x209])(x,y,z,w,*glContext,target,indexArg);
  return;
}

/* _glProgramEnvParameter4fvARB @ 0x92f3d1f4 (140 bytes) */
int _glProgramEnvParameter4fvARB(target, indexArg, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 indexArg;
  undefined4 params;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x20a])(*glContext,target,indexArg,params);
  return;
}

/* _glProgramLocalParameter4dARB @ 0x92f3d280 (160 bytes) */
void _glProgramLocalParameter4dARB(undefined4 target,undefined4 indexArg,undefined4 xShadowHi,undefined4 xShadowLo,undefined4 yShadowHi,undefined4 yShadowLo,undefined4 zShadowHi,double x,double y,double z,double w)
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff70)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff70);
  }
  (*(code *)glContext[0x20b])(x,y,z,w,*glContext,target,indexArg);
  return;
}

/* _glProgramLocalParameter4dvARB @ 0x92f3d320 (140 bytes) */
int _glProgramLocalParameter4dvARB(target, indexArg, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 indexArg;
  undefined4 params;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x20c])(*glContext,target,indexArg,params);
  return;
}

/* _glProgramLocalParameter4fARB @ 0x92f3d3ac (180 bytes) */
void _glProgramLocalParameter4fARB(undefined4 target,undefined4 indexArg,undefined4 xShadow,undefined4 yShadow,undefined4 zShadow,undefined4 wShadow,undefined4 fwdReg7,double x,double y,double z,double w)
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff80)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff80);
  }
                    
                    
  (*(code *)glContext[0x20d])(x,y,z,w,*glContext,target,indexArg);
  return;
}

/* _glProgramLocalParameter4fvARB @ 0x92f3d460 (140 bytes) */
int _glProgramLocalParameter4fvARB(target, indexArg, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 indexArg;
  undefined4 params;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x20e])(*glContext,target,indexArg,params);
  return;
}

/* _glGetProgramEnvParameterdvARB @ 0x92f3d4ec (140 bytes) */
int _glGetProgramEnvParameterdvARB(target, indexArg, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 indexArg;
  undefined4 params;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x20f])(*glContext,target,indexArg,params);
  return;
}

/* _glGetProgramEnvParameterfvARB @ 0x92f3d578 (140 bytes) */
int _glGetProgramEnvParameterfvARB(target, indexArg, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 indexArg;
  undefined4 params;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x210])(*glContext,target,indexArg,params);
  return;
}

/* _glGetProgramLocalParameterdvARB @ 0x92f3d604 (140 bytes) */
int _glGetProgramLocalParameterdvARB(target, indexArg, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 indexArg;
  undefined4 params;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x211])(*glContext,target,indexArg,params);
  return;
}

/* _glGetProgramLocalParameterfvARB @ 0x92f3d690 (140 bytes) */
int _glGetProgramLocalParameterfvARB(target, indexArg, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 indexArg;
  undefined4 params;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x212])(*glContext,target,indexArg,params);
  return;
}

/* _glProgramStringARB @ 0x92f3d71c (148 bytes) */
int _glProgramStringARB(target, format, len, string, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 format;
  undefined4 len;
  undefined4 string;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x213])(*glContext,target,format,len,string);
  return;
}

/* _glGetProgramStringARB @ 0x92f3d7b0 (140 bytes) */
int _glGetProgramStringARB(target, pname, string, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 pname;
  undefined4 string;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x214])(*glContext,target,pname,string);
  return;
}

/* _glGetProgramivARB @ 0x92f3d83c (140 bytes) */
int _glGetProgramivARB(target, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 pname;
  undefined4 params;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x215])(*glContext,target,pname,params);
  return;
}

/* _glWeightbvARB @ 0x92f3d8c8 (132 bytes) */
int _glWeightbvARB(size, weights, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 size;
  undefined4 weights;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x22e])(*glContext,size,weights);
  return;
}

/* _glWeightsvARB @ 0x92f3d94c (132 bytes) */
int _glWeightsvARB(size, weights, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 size;
  undefined4 weights;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x22f])(*glContext,size,weights);
  return;
}

/* _glWeightivARB @ 0x92f3d9d0 (132 bytes) */
int _glWeightivARB(size, weights, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 size;
  undefined4 weights;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x230])(*glContext,size,weights);
  return;
}

/* _glWeightfvARB @ 0x92f3da54 (132 bytes) */
int _glWeightfvARB(size, weights, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 size;
  undefined4 weights;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x231])(*glContext,size,weights);
  return;
}

/* _glWeightdvARB @ 0x92f3dad8 (132 bytes) */
int _glWeightdvARB(size, weights, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 size;
  undefined4 weights;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x232])(*glContext,size,weights);
  return;
}

/* _glWeightubvARB @ 0x92f3db5c (132 bytes) */
int _glWeightubvARB(size, weights, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 size;
  undefined4 weights;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x233])(*glContext,size,weights);
  return;
}

/* _glWeightusvARB @ 0x92f3dbe0 (132 bytes) */
int _glWeightusvARB(size, weights, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 size;
  undefined4 weights;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x234])(*glContext,size,weights);
  return;
}

/* _glWeightuivARB @ 0x92f3dc64 (132 bytes) */
int _glWeightuivARB(size, weights, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 size;
  undefined4 weights;
  undefined4 fwdReg3;
  undefined4 fwdReg4;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x235])(*glContext,size,weights);
  return;
}

/* _glWeightPointerARB @ 0x92f3dce8 (148 bytes) */
int _glWeightPointerARB(size, type, stride, pointer, fwdReg5, fwdReg6, fwdReg7)
  undefined4 size;
  undefined4 type;
  undefined4 stride;
  undefined4 pointer;
  undefined4 fwdReg5;
  undefined4 fwdReg6;
  undefined4 fwdReg7;
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)glContext[0x236])(*glContext,size,type,stride,pointer);
  return;
}

