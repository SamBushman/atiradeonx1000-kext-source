#include "decls.h"

/* _glTexCoord3d @ 0x92f317b4 (160 bytes) */
void _glTexCoord3d(double s,double t,double r)
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
                    
                    
  (*(code *)glContext[0x112])(s,t,r,*glContext);
  return;
}

/* _glTexCoord3dv @ 0x92f31854 (124 bytes) */
int _glTexCoord3dv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x113])(*glContext,v);
  return;
}

/* _glTexCoord3fv @ 0x92f318d0 (124 bytes) */
int _glTexCoord3fv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x115])(*glContext,v);
  return;
}

/* _glTexCoord3i @ 0x92f3194c (140 bytes) */
int _glTexCoord3i(s, t, r, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 s;
  undefined4 t;
  undefined4 r;
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
                    
                    
  (*(code *)glContext[0x116])(*glContext,s,t,r);
  return;
}

/* _glTexCoord3iv @ 0x92f319d8 (124 bytes) */
int _glTexCoord3iv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x117])(*glContext,v);
  return;
}

/* _glTexCoord3s @ 0x92f31a54 (140 bytes) */
int _glTexCoord3s(s, t, r, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 s;
  undefined4 t;
  undefined4 r;
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
                    
                    
  (*(code *)glContext[0x118])(*glContext,s,t,r);
  return;
}

/* _glTexCoord3sv @ 0x92f31ae0 (124 bytes) */
int _glTexCoord3sv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x119])(*glContext,v);
  return;
}

/* _glTexCoord4d @ 0x92f31b5c (140 bytes) */
void _glTexCoord4d(double s,double t,double r,double q)
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
  (*(code *)glContext[0x11a])(s,t,r,q,*glContext);
  return;
}

/* _glTexCoord4dv @ 0x92f31be8 (124 bytes) */
int _glTexCoord4dv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x11b])(*glContext,v);
  return;
}

/* _glTexCoord4f @ 0x92f31c64 (160 bytes) */
void _glTexCoord4f(double s,double t,double r,double q)
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
                    
                    
  (*(code *)glContext[0x11c])(s,t,r,q,*glContext);
  return;
}

/* _glTexCoord4fv @ 0x92f31d04 (124 bytes) */
int _glTexCoord4fv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x11d])(*glContext,v);
  return;
}

/* _glTexCoord4i @ 0x92f31d80 (148 bytes) */
int _glTexCoord4i(s, t, r, q, fwdReg5, fwdReg6, fwdReg7)
  undefined4 s;
  undefined4 t;
  undefined4 r;
  undefined4 q;
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
                    
                    
  (*(code *)glContext[0x11e])(*glContext,s,t,r,q);
  return;
}

/* _glTexCoord4iv @ 0x92f31e14 (124 bytes) */
int _glTexCoord4iv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x11f])(*glContext,v);
  return;
}

/* _glTexCoord4s @ 0x92f31e90 (148 bytes) */
int _glTexCoord4s(s, t, r, q, fwdReg5, fwdReg6, fwdReg7)
  undefined4 s;
  undefined4 t;
  undefined4 r;
  undefined4 q;
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
                    
                    
  (*(code *)glContext[0x120])(*glContext,s,t,r,q);
  return;
}

/* _glTexCoord4sv @ 0x92f31f24 (124 bytes) */
int _glTexCoord4sv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x121])(*glContext,v);
  return;
}

/* _glTexEnvfv @ 0x92f31fa0 (140 bytes) */
int _glTexEnvfv(target, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
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
                    
                    
  (*(code *)glContext[0x124])(*glContext,target,pname,params);
  return;
}

/* _glTexEnviv @ 0x92f3202c (140 bytes) */
int _glTexEnviv(target, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
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
                    
                    
  (*(code *)glContext[0x126])(*glContext,target,pname,params);
  return;
}

/* _glTexGend @ 0x92f320b8 (148 bytes) */
void _glTexGend(undefined4 coord,undefined4 pname,undefined4 paramShadowHi,undefined4 paramShadowLo,undefined4 fwdReg5,undefined4 fwdReg6,undefined4 fwdReg7,double param)
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
                    
                    
  (*(code *)glContext[0x127])(param,*glContext,coord,pname);
  return;
}

/* _glTexGendv @ 0x92f3214c (140 bytes) */
int _glTexGendv(coord, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 coord;
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
                    
                    
  (*(code *)glContext[0x128])(*glContext,coord,pname,params);
  return;
}

/* _glTexGenf @ 0x92f321d8 (148 bytes) */
void _glTexGenf(undefined4 coord,undefined4 pname,undefined4 paramShadow,undefined4 fwdReg4,undefined4 fwdReg5,undefined4 fwdReg6,undefined4 fwdReg7,double param)
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
                    
                    
  (*(code *)glContext[0x129])(param,*glContext,coord,pname);
  return;
}

/* _glTexGenfv @ 0x92f3226c (140 bytes) */
int _glTexGenfv(coord, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 coord;
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
                    
                    
  (*(code *)glContext[0x12a])(*glContext,coord,pname,params);
  return;
}

/* _glTexGeni @ 0x92f322f8 (140 bytes) */
int _glTexGeni(coord, pname, param, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 coord;
  undefined4 pname;
  undefined4 param;
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
                    
                    
  (*(code *)glContext[299])(*glContext,coord,pname,param);
  return;
}

/* _glTexGeniv @ 0x92f32384 (140 bytes) */
int _glTexGeniv(coord, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 coord;
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
                    
                    
  (*(code *)glContext[300])(*glContext,coord,pname,params);
  return;
}

/* _glTexImage1D @ 0x92f32410 (184 bytes) */
int _glTexImage1D(target, level, internalFormat, width, border, format, type, pixels)
  undefined4 target;
  undefined4 level;
  undefined4 internalFormat;
  undefined4 width;
  undefined4 border;
  undefined4 format;
  undefined4 type;
  undefined4 pixels;
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
  return (*(code *)glContext[0x12d])(*glContext,target,level,internalFormat,width,border,format,type);
}

/* _glTexParameterfv @ 0x92f324c8 (140 bytes) */
int _glTexParameterfv(target, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
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
                    
                    
  (*(code *)glContext[0x130])(*glContext,target,pname,params);
  return;
}

/* _glTexParameteriv @ 0x92f32554 (140 bytes) */
int _glTexParameteriv(target, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
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
                    
                    
  (*(code *)glContext[0x132])(*glContext,target,pname,params);
  return;
}

/* _glTexSubImage1D @ 0x92f325e0 (172 bytes) */
int _glTexSubImage1D(target, level, xoffset, width, format, type, pixels)
  undefined4 target;
  undefined4 level;
  undefined4 xoffset;
  undefined4 width;
  undefined4 format;
  undefined4 type;
  undefined4 pixels;
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
                    
                    
  (*(code *)glContext[0x133])(*glContext,target,level,xoffset,width,format,type,pixels);
  return;
}

/* _glVertex2d @ 0x92f3268c (144 bytes) */
void _glVertex2d(double x,double y)
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
                    
                    
  (*(code *)glContext[0x137])(x,y,*glContext);
  return;
}

/* _glVertex2dv @ 0x92f3271c (124 bytes) */
int _glVertex2dv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x138])(*glContext,v);
  return;
}

/* _glVertex2fv @ 0x92f32798 (124 bytes) */
int _glVertex2fv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x13a])(*glContext,v);
  return;
}

/* _glVertex2i @ 0x92f32814 (132 bytes) */
int _glVertex2i(x, y, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 x;
  undefined4 y;
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
                    
                    
  (*(code *)glContext[0x13b])(*glContext,x,y);
  return;
}

/* _glVertex2iv @ 0x92f32898 (124 bytes) */
int _glVertex2iv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x13c])(*glContext,v);
  return;
}

/* _glVertex2s @ 0x92f32914 (132 bytes) */
int _glVertex2s(x, y, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 x;
  undefined4 y;
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
                    
                    
  (*(code *)glContext[0x13d])(*glContext,x,y);
  return;
}

/* _glVertex2sv @ 0x92f32998 (124 bytes) */
int _glVertex2sv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x13e])(*glContext,v);
  return;
}

/* _glVertex3dv @ 0x92f32a14 (124 bytes) */
int _glVertex3dv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x140])(*glContext,v);
  return;
}

/* _glVertex3fv @ 0x92f32a90 (124 bytes) */
int _glVertex3fv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x142])(*glContext,v);
  return;
}

/* _glVertex3i @ 0x92f32b0c (140 bytes) */
int _glVertex3i(x, y, z, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 x;
  undefined4 y;
  undefined4 z;
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
                    
                    
  (*(code *)glContext[0x143])(*glContext,x,y,z);
  return;
}

/* _glVertex3iv @ 0x92f32b98 (124 bytes) */
int _glVertex3iv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x144])(*glContext,v);
  return;
}

/* _glVertex3s @ 0x92f32c14 (140 bytes) */
int _glVertex3s(x, y, z, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 x;
  undefined4 y;
  undefined4 z;
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
                    
                    
  (*(code *)glContext[0x145])(*glContext,x,y,z);
  return;
}

/* _glVertex3sv @ 0x92f32ca0 (124 bytes) */
int _glVertex3sv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x146])(*glContext,v);
  return;
}

/* _glVertex4d @ 0x92f32d1c (140 bytes) */
void _glVertex4d(double x,double y,double z,double w)
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
  (*(code *)glContext[0x147])(x,y,z,w,*glContext);
  return;
}

/* _glVertex4dv @ 0x92f32da8 (124 bytes) */
int _glVertex4dv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x148])(*glContext,v);
  return;
}

/* _glVertex4f @ 0x92f32e24 (160 bytes) */
void _glVertex4f(double x,double y,double z,double w)
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
                    
                    
  (*(code *)glContext[0x149])(x,y,z,w,*glContext);
  return;
}

/* _glVertex4fv @ 0x92f32ec4 (124 bytes) */
int _glVertex4fv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x14a])(*glContext,v);
  return;
}

/* _glVertex4i @ 0x92f32f40 (148 bytes) */
int _glVertex4i(x, y, z, w, fwdReg5, fwdReg6, fwdReg7)
  undefined4 x;
  undefined4 y;
  undefined4 z;
  undefined4 w;
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
                    
                    
  (*(code *)glContext[0x14b])(*glContext,x,y,z,w);
  return;
}

/* _glVertex4iv @ 0x92f32fd4 (124 bytes) */
int _glVertex4iv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x14c])(*glContext,v);
  return;
}

/* _glVertex4s @ 0x92f33050 (148 bytes) */
int _glVertex4s(x, y, z, w, fwdReg5, fwdReg6, fwdReg7)
  undefined4 x;
  undefined4 y;
  undefined4 z;
  undefined4 w;
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
                    
                    
  (*(code *)glContext[0x14d])(*glContext,x,y,z,w);
  return;
}

/* _glVertex4sv @ 0x92f330e4 (124 bytes) */
int _glVertex4sv(v, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 v;
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
                    
                    
  (*(code *)glContext[0x14e])(*glContext,v);
  return;
}

/* _glBlendColor @ 0x92f33160 (160 bytes) */
void _glBlendColor(double red,double green,double blue,double alpha)
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
                    
                    
  (*(code *)glContext[0x152])(red,green,blue,alpha,*glContext);
  return;
}

/* _glBlendEquation @ 0x92f33200 (124 bytes) */
int _glBlendEquation(mode, fwdReg2, fwdReg3, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
  undefined4 mode;
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
                    
                    
  (*(code *)glContext[0x153])(*glContext,mode);
  return;
}

/* _glDrawRangeElements @ 0x92f3327c (164 bytes) */
int _glDrawRangeElements(mode, start, end, count, type, indices, fwdReg7)
  undefined4 mode;
  undefined4 start;
  undefined4 end;
  undefined4 count;
  undefined4 type;
  undefined4 indices;
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
                    
                    
  (*(code *)glContext[0x196])(*glContext,mode,start,end,count,type,indices);
  return;
}

/* _glTexImage3D @ 0x92f33320 (200 bytes) */
int _glTexImage3D(target, level, internalFormat, width, height, depth, border, format)
  undefined4 target;
  undefined4 level;
  undefined4 internalFormat;
  undefined4 width;
  undefined4 height;
  undefined4 depth;
  undefined4 border;
  undefined4 format;
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
  return (*(code *)glContext[0x1b7])(*glContext,target,level,internalFormat,width,height,depth,border);
}

/* _glTexSubImage3D @ 0x92f333e8 (208 bytes) */
int _glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth)
  undefined4 target;
  undefined4 level;
  undefined4 xoffset;
  undefined4 yoffset;
  undefined4 zoffset;
  undefined4 width;
  undefined4 height;
  undefined4 depth;
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
  return (*(code *)glContext[0x1b8])(*glContext,target,level,xoffset,yoffset,zoffset,width,height);
}

/* _glCopyTexSubImage3D @ 0x92f334b8 (192 bytes) */
int _glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width)
  undefined4 target;
  undefined4 level;
  undefined4 xoffset;
  undefined4 yoffset;
  undefined4 zoffset;
  undefined4 x;
  undefined4 y;
  undefined4 width;
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
  return (*(code *)glContext[0x1b9])(*glContext,target,level,xoffset,yoffset,zoffset,x,y);
}

/* _glColorTable @ 0x92f33578 (164 bytes) */
int _glColorTable(target, internalformat, width, format, type, table, fwdReg7)
  undefined4 target;
  undefined4 internalformat;
  undefined4 width;
  undefined4 format;
  undefined4 type;
  undefined4 table;
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
                    
                    
  (*(code *)glContext[0x197])(*glContext,target,internalformat,width,format,type,table);
  return;
}

/* _glColorTableParameterfv @ 0x92f3361c (140 bytes) */
int _glColorTableParameterfv(target, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
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
                    
                    
  (*(code *)glContext[0x198])(*glContext,target,pname,params);
  return;
}

/* _glColorTableParameteriv @ 0x92f336a8 (140 bytes) */
int _glColorTableParameteriv(target, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
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
                    
                    
  (*(code *)glContext[0x199])(*glContext,target,pname,params);
  return;
}

/* _glCopyColorTable @ 0x92f33734 (156 bytes) */
int _glCopyColorTable(target, internalformat, x, y, width, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 internalformat;
  undefined4 x;
  undefined4 y;
  undefined4 width;
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
                    
                    
  (*(code *)glContext[0x19a])(*glContext,target,internalformat,x,y,width);
  return;
}

/* _glGetColorTable @ 0x92f337d0 (148 bytes) */
int _glGetColorTable(target, format, type, table, fwdReg5, fwdReg6, fwdReg7)
  undefined4 target;
  undefined4 format;
  undefined4 type;
  undefined4 table;
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
                    
                    
  (*(code *)glContext[0x19b])(*glContext,target,format,type,table);
  return;
}

/* _glGetColorTableParameterfv @ 0x92f33864 (140 bytes) */
int _glGetColorTableParameterfv(target, pname, params, fwdReg4, fwdReg5, fwdReg6, fwdReg7)
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
                    
                    
  (*(code *)glContext[0x19c])(*glContext,target,pname,params);
  return;
}

