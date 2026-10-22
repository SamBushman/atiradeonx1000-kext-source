#include "decls.h"

/* _glGetFramebufferAttachmentParameterivEXT @ 0x92f43fc8 (148 bytes) */
int _glGetFramebufferAttachmentParameterivEXT(target, attachment, pname, params, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 attachment;
  undefined4 pname;
  undefined4 params;
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
                    
                    
  (*(code *)glContext[0x2a9])(*glContext,target,attachment,pname,params);
  return;
}

/* _glGenerateMipmapEXT @ 0x92f4405c (124 bytes) */
int _glGenerateMipmapEXT(target, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
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
                    
                    
  (*(code *)glContext[0x2aa])(*glContext,target);
  return;
}

/* _glEnableVertexAttribAPPLE @ 0x92f440d8 (132 bytes) */
int _glEnableVertexAttribAPPLE(indexArg, pname, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 pname;
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
                    
                    
  (*(code *)glContext[0x216])(*glContext,indexArg,pname);
  return;
}

/* _glDisableVertexAttribAPPLE @ 0x92f4415c (132 bytes) */
int _glDisableVertexAttribAPPLE(indexArg, pname, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 pname;
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
                    
                    
  (*(code *)glContext[0x217])(*glContext,indexArg,pname);
  return;
}

/* _glIsVertexAttribEnabledAPPLE @ 0x92f441e0 (136 bytes) */
int _glIsVertexAttribEnabledAPPLE(indexArg, pname, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 indexArg;
  undefined4 pname;
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
  return (*(code *)glContext[0x218])(*glContext,indexArg,pname);
}

/* _glMapVertexAttrib1dAPPLE @ 0x92f44268 (192 bytes) */
void _glMapVertexAttrib1dAPPLE(undefined4 indexArg,undefined4 size,undefined4 u1ShadowHi,undefined4 u1ShadowLo,undefined4 u2ShadowHi,undefined4 u2ShadowLo,undefined4 stride,undefined4 order,double u1,double u2)
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
  (*(code *)glContext[0x219])(u1,u2,*glContext,indexArg,size);
  return;
}

/* _glMapVertexAttrib1fAPPLE @ 0x92f44328 (188 bytes) */
void _glMapVertexAttrib1fAPPLE(undefined4 indexArg,undefined4 size,undefined4 u1Shadow,undefined4 u2Shadow,undefined4 stride,undefined4 order,undefined4 points,double u1,double u2)
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
                    
                    
  (*(code *)glContext[0x21a])(u1,u2,*glContext,indexArg,size);
  return;
}

/* _glMapVertexAttrib2dAPPLE @ 0x92f443e4 (200 bytes) */
void _glMapVertexAttrib2dAPPLE(undefined4 indexArg,undefined4 size,undefined4 u1ShadowHi,undefined4 u1ShadowLo,undefined4 u2ShadowHi,undefined4 u2ShadowLo,undefined4 ustride,undefined4 uorder,double u1,double u2,double v1,double v2)
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffff60)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffff60);
  }
  (*(code *)glContext[0x21b])(u1,u2,v1,v2,*glContext,indexArg,size);
  return;
}

/* _glMapVertexAttrib2fAPPLE @ 0x92f444ac (200 bytes) */
void _glMapVertexAttrib2fAPPLE(undefined4 indexArg,undefined4 size,undefined4 u1Shadow,undefined4 u2Shadow,undefined4 ustride,undefined4 uorder,double u1,double u2,double v1,double v2)
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
  (*(code *)glContext[0x21c])(u1,u2,v1,v2,*glContext,indexArg,size);
  return;
}

/* _glGetTexParameterPointervAPPLE @ 0x92f44574 (140 bytes) */
int _glGetTexParameterPointervAPPLE(target, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
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
                    
                    
  (*(code *)glContext[0x1ca])(*glContext,target,pname,params);
  return;
}

/* _glGenFencesAPPLE @ 0x92f44600 (132 bytes) */
int _glGenFencesAPPLE(n, fences, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 n;
  undefined4 fences;
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
                    
                    
  (*(code *)glContext[0x1d0])(*glContext,n,fences);
  return;
}

/* _glDeleteFencesAPPLE @ 0x92f44684 (132 bytes) */
int _glDeleteFencesAPPLE(n, fences, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 n;
  undefined4 fences;
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
                    
                    
  (*(code *)glContext[0x1d1])(*glContext,n,fences);
  return;
}

/* _glSetFenceAPPLE @ 0x92f44708 (124 bytes) */
int _glSetFenceAPPLE(fence, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 fence;
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
                    
                    
  (*(code *)glContext[0x1d2])(*glContext,fence);
  return;
}

/* _glIsFenceAPPLE @ 0x92f44784 (128 bytes) */
int _glIsFenceAPPLE(fence, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 fence;
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
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffb0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffb0);
  }
  return (*(code *)glContext[0x1d3])(*glContext,fence);
}

/* _glTestFenceAPPLE @ 0x92f44804 (128 bytes) */
int _glTestFenceAPPLE(fence, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 fence;
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
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffb0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffb0);
  }
  return (*(code *)glContext[0x1d4])(*glContext,fence);
}

/* _glFinishFenceAPPLE @ 0x92f44884 (124 bytes) */
int _glFinishFenceAPPLE(fence, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 fence;
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
                    
                    
  (*(code *)glContext[0x1d5])(*glContext,fence);
  return;
}

/* _glTestObjectAPPLE @ 0x92f44900 (136 bytes) */
int _glTestObjectAPPLE(object, name, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 object;
  undefined4 name;
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
  return (*(code *)glContext[0x1d6])(*glContext,object,name);
}

/* _glFinishObjectAPPLE @ 0x92f44988 (132 bytes) */
int _glFinishObjectAPPLE(object, name, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 object;
  undefined4 name;
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
                    
                    
  (*(code *)glContext[0x1d7])(*glContext,object,name);
  return;
}

/* _glVertexArrayRangeAPPLE @ 0x92f44a0c (132 bytes) */
int _glVertexArrayRangeAPPLE(length, pointer, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 length;
  undefined4 pointer;
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
                    
                    
  (*(code *)glContext[0x194])(*glContext,length,pointer);
  return;
}

/* _glFlushVertexArrayRangeAPPLE @ 0x92f44a90 (132 bytes) */
int _glFlushVertexArrayRangeAPPLE(length, pointer, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 length;
  undefined4 pointer;
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
                    
                    
  (*(code *)glContext[0x195])(*glContext,length,pointer);
  return;
}

/* _glVertexArrayParameteriAPPLE @ 0x92f44b14 (132 bytes) */
int _glVertexArrayParameteriAPPLE(pname, param, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 pname;
  undefined4 param;
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
                    
                    
  (*(code *)glContext[0x226])(*glContext,pname,param);
  return;
}

/* _glBindVertexArrayAPPLE @ 0x92f44b98 (124 bytes) */
int _glBindVertexArrayAPPLE(id, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 id;
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
                    
                    
  (*(code *)glContext[0x227])(*glContext,id);
  return;
}

/* _glDeleteVertexArraysAPPLE @ 0x92f44c14 (132 bytes) */
int _glDeleteVertexArraysAPPLE(n, ids, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 n;
  undefined4 ids;
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
                    
                    
  (*(code *)glContext[0x228])(*glContext,n,ids);
  return;
}

/* _glGenVertexArraysAPPLE @ 0x92f44c98 (132 bytes) */
int _glGenVertexArraysAPPLE(n, ids, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 n;
  undefined4 ids;
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
                    
                    
  (*(code *)glContext[0x229])(*glContext,n,ids);
  return;
}

/* _glIsVertexArrayAPPLE @ 0x92f44d1c (128 bytes) */
int _glIsVertexArrayAPPLE(id, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 id;
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
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffb0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffb0);
  }
  return (*(code *)glContext[0x22a])(*glContext,id);
}

/* _glElementPointerAPPLE @ 0x92f44d9c (132 bytes) */
int _glElementPointerAPPLE(type, pointer, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 type;
  undefined4 pointer;
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
                    
                    
  (*(code *)glContext[0x22b])(*glContext,type,pointer);
  return;
}

/* _glDrawElementArrayAPPLE @ 0x92f44e20 (140 bytes) */
int _glDrawElementArrayAPPLE(mode, first, count, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 mode;
  undefined4 first;
  undefined4 count;
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
                    
                    
  (*(code *)glContext[0x22c])(*glContext,mode,first,count);
  return;
}

/* _glDrawRangeElementArrayAPPLE @ 0x92f44eac (156 bytes) */
int _glDrawRangeElementArrayAPPLE(mode, start, end, first, count, fwdReg6, fwdReg7)
  undefined4 mode;
  undefined4 start;
  undefined4 end;
  undefined4 first;
  undefined4 count;
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
                    
                    
  (*(code *)glContext[0x22d])(*glContext,mode,start,end,first,count);
  return;
}

/* _glMultiDrawElementArrayAPPLE @ 0x92f44f48 (148 bytes) */
int _glMultiDrawElementArrayAPPLE(mode, first, count, primcount, fwdReg5, fwdReg6, fwdReg7)
  undefined4 mode;
  undefined4 first;
  undefined4 count;
  undefined4 primcount;
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
                    
                    
  (*(code *)glContext[0x298])(*glContext,mode,first,count,primcount);
  return;
}

/* _glMultiDrawRangeElementArrayAPPLE @ 0x92f44fdc (164 bytes) */
int _glMultiDrawRangeElementArrayAPPLE(mode, start, end, first, count, primcount, fwdReg7)
  undefined4 mode;
  undefined4 start;
  undefined4 end;
  undefined4 first;
  undefined4 count;
  undefined4 primcount;
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
                    
                    
  (*(code *)glContext[0x299])(*glContext,mode,start,end,first,count,primcount);
  return;
}

/* _glFlushRenderAPPLE @ 0x92f45080 (112 bytes) */
int _glFlushRenderAPPLE()
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffb0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffb0);
  }
                    
                    
  (*(code *)glContext[0x24d])(*glContext);
  return;
}

/* _glFinishRenderAPPLE @ 0x92f450f0 (112 bytes) */
int _glFinishRenderAPPLE()
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffb0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffb0);
  }
                    
                    
  (*(code *)glContext[0x24e])(*glContext);
  return;
}

/* _glSwapAPPLE @ 0x92f45160 (112 bytes) */
int _glSwapAPPLE()
{
  undefined *currentContextSlot;
  undefined4 *glContext;
  
  currentContextSlot = PTR__gll_cc_a2f27020;
  glContext = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((glContext[0x2ac] ^ (uint)&STACKARG(0xffffffb0)) & 0xfffff000) != 0) {
    glContext = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)currentContextSlot = glContext;
    glContext[0x2ac] = &STACKARG(0xffffffb0);
  }
                    
                    
  (*(code *)glContext[0x24f])(*glContext);
  return;
}

/* _glBlendEquationSeparateATI @ 0x92f451d0 (132 bytes) */
int _glBlendEquationSeparateATI(modeRGB, modeA, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 modeRGB;
  undefined4 modeA;
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
                    
                    
  (*(code *)glContext[0x1cb])(*glContext,modeRGB,modeA);
  return;
}

/* _glStencilOpSeparateATI @ 0x92f45254 (148 bytes) */
int _glStencilOpSeparateATI(face, sfail, dpfail, dppass, fwdReg5, fwdReg6, fwdReg7)
  undefined4 face;
  undefined4 sfail;
  undefined4 dpfail;
  undefined4 dppass;
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
                    
                    
  (*(code *)glContext[0x24b])(*glContext,face,sfail,dpfail,dppass);
  return;
}

/* _glStencilFuncSeparateATI @ 0x92f452e8 (148 bytes) */
int _glStencilFuncSeparateATI(frontfunc, backfunc, ref, mask, fwdReg5, fwdReg6, fwdReg7)
  undefined4 frontfunc;
  undefined4 backfunc;
  undefined4 ref;
  undefined4 mask;
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
                    
                    
  (*(code *)glContext[0x24c])(*glContext,frontfunc,backfunc,ref,mask);
  return;
}

/* _glPNTrianglesiATI @ 0x92f4537c (132 bytes) */
int _glPNTrianglesiATI(pname, param, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 pname;
  undefined4 param;
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
                    
                    
  (*(code *)glContext[0x1ce])(*glContext,pname,param);
  return;
}

/* _glPNTrianglesfATI @ 0x92f45400 (140 bytes) */
void _glPNTrianglesfATI(undefined4 pname,undefined4 paramShadow,undefined4 fwdReg3,undefined4 fwdReg4,undefined4 fwdReg5,undefined4 fwdReg6,undefined4 fwdReg7,double param)
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
                    
                    
  (*(code *)glContext[0x1cf])(param,*glContext,pname);
  return;
}

/* _glPNTrianglesiATIX @ 0x92f4548c (132 bytes) */
int _glPNTrianglesiATIX(pname, param, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 pname;
  undefined4 param;
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
                    
                    
  (*(code *)glContext[0x1ce])(*glContext,pname,param);
  return;
}

/* _glPNTrianglesfATIX @ 0x92f45510 (140 bytes) */
void _glPNTrianglesfATIX(undefined4 pname,undefined4 paramShadow,undefined4 fwdReg3,undefined4 fwdReg4,undefined4 fwdReg5,undefined4 fwdReg6,undefined4 fwdReg7,double param)
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
                    
                    
  (*(code *)glContext[0x1cf])(param,*glContext,pname);
  return;
}

/* _glPointParameteriNV @ 0x92f4559c (132 bytes) */
int _glPointParameteriNV(pname, param, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 pname;
  undefined4 param;
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
                    
                    
  (*(code *)glContext[0x21f])(*glContext,pname,param);
  return;
}

/* _glPointParameterivNV @ 0x92f45620 (132 bytes) */
int _glPointParameterivNV(pname, params, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 pname;
  undefined4 params;
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
                    
                    
  (*(code *)glContext[0x220])(*glContext,pname,params);
  return;
}

/* _glCombinerParameterfvNV @ 0x92f456a4 (132 bytes) */
int _glCombinerParameterfvNV(pname, params, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 pname;
  undefined4 params;
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
                    
                    
  (*(code *)glContext[0x1ba])(*glContext,pname,params);
  return;
}

/* _glCombinerParameterfNV @ 0x92f45728 (140 bytes) */
void _glCombinerParameterfNV(undefined4 pname,undefined4 paramShadow,undefined4 fwdReg3,undefined4 fwdReg4,undefined4 fwdReg5,undefined4 fwdReg6,undefined4 fwdReg7,double param)
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
                    
                    
  (*(code *)glContext[0x1bb])(param,*glContext,pname);
  return;
}

/* _glCombinerParameterivNV @ 0x92f457b4 (132 bytes) */
int _glCombinerParameterivNV(pname, params, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 pname;
  undefined4 params;
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
                    
                    
  (*(code *)glContext[0x1bc])(*glContext,pname,params);
  return;
}

/* _glCombinerParameteriNV @ 0x92f45838 (132 bytes) */
int _glCombinerParameteriNV(pname, param, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 pname;
  undefined4 param;
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
                    
                    
  (*(code *)glContext[0x1bd])(*glContext,pname,param);
  return;
}

/* _glCombinerInputNV @ 0x92f458bc (164 bytes) */
int _glCombinerInputNV(stage, portion, variable, input, mapping, componentUsage, fwdReg7)
  undefined4 stage;
  undefined4 portion;
  undefined4 variable;
  undefined4 input;
  undefined4 mapping;
  undefined4 componentUsage;
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
                    
                    
  (*(code *)glContext[0x1be])(*glContext,stage,portion,variable,input,mapping,componentUsage);
  return;
}

/* _glCombinerOutputNV @ 0x92f45960 (200 bytes) */
int _glCombinerOutputNV(stage, portion, abOutput, cdOutput, sumOutput, scale, bias, abDotProduct)
  undefined4 stage;
  undefined4 portion;
  undefined4 abOutput;
  undefined4 cdOutput;
  undefined4 sumOutput;
  undefined4 scale;
  undefined4 bias;
  undefined4 abDotProduct;
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
  return (*(code *)glContext[0x1bf])(*glContext,stage,portion,abOutput,cdOutput,sumOutput,scale,bias);
}

/* _glFinalCombinerInputNV @ 0x92f45a28 (148 bytes) */
int _glFinalCombinerInputNV(variable, input, mapping, componentUsage, fwdReg5, fwdReg6, fwdReg7)
  undefined4 variable;
  undefined4 input;
  undefined4 mapping;
  undefined4 componentUsage;
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
                    
                    
  (*(code *)glContext[0x1c0])(*glContext,variable,input,mapping,componentUsage);
  return;
}

/* _glGetCombinerInputParameterfvNV @ 0x92f45abc (156 bytes) */
int _glGetCombinerInputParameterfvNV(stage, portion, variable, pname, params, fwdReg6, fwdReg7)
  undefined4 stage;
  undefined4 portion;
  undefined4 variable;
  undefined4 pname;
  undefined4 params;
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
                    
                    
  (*(code *)glContext[0x1c1])(*glContext,stage,portion,variable,pname,params);
  return;
}

/* _glGetCombinerInputParameterivNV @ 0x92f45b58 (156 bytes) */
int _glGetCombinerInputParameterivNV(stage, portion, variable, pname, params, fwdReg6, fwdReg7)
  undefined4 stage;
  undefined4 portion;
  undefined4 variable;
  undefined4 pname;
  undefined4 params;
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
                    
                    
  (*(code *)glContext[0x1c2])(*glContext,stage,portion,variable,pname,params);
  return;
}

/* _glGetCombinerOutputParameterfvNV @ 0x92f45bf4 (148 bytes) */
int _glGetCombinerOutputParameterfvNV(stage, portion, pname, params, fwdReg5, fwdReg6, fwdReg7)
  undefined4 stage;
  undefined4 portion;
  undefined4 pname;
  undefined4 params;
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
                    
                    
  (*(code *)glContext[0x1c3])(*glContext,stage,portion,pname,params);
  return;
}

/* _glGetCombinerOutputParameterivNV @ 0x92f45c88 (148 bytes) */
int _glGetCombinerOutputParameterivNV(stage, portion, pname, params, fwdReg5, fwdReg6, fwdReg7)
  undefined4 stage;
  undefined4 portion;
  undefined4 pname;
  undefined4 params;
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
                    
                    
  (*(code *)glContext[0x1c4])(*glContext,stage,portion,pname,params);
  return;
}

/* _glGetFinalCombinerInputParameterfvNV @ 0x92f45d1c (140 bytes) */
int _glGetFinalCombinerInputParameterfvNV(variable, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 variable;
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
                    
                    
  (*(code *)glContext[0x1c5])(*glContext,variable,pname,params);
  return;
}

/* _glGetFinalCombinerInputParameterivNV @ 0x92f45da8 (140 bytes) */
int _glGetFinalCombinerInputParameterivNV(variable, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 variable;
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
                    
                    
  (*(code *)glContext[0x1c6])(*glContext,variable,pname,params);
  return;
}

/* _glCombinerStageParameterfvNV @ 0x92f45e34 (140 bytes) */
int _glCombinerStageParameterfvNV(stage, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 stage;
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
                    
                    
  (*(code *)glContext[0x1c7])(*glContext,stage,pname,params);
  return;
}

/* _glGetCombinerStageParameterfvNV @ 0x92f45ec0 (140 bytes) */
int _glGetCombinerStageParameterfvNV(stage, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 stage;
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
                    
                    
  (*(code *)glContext[0x1c8])(*glContext,stage,pname,params);
  return;
}

