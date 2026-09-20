#include "decls.h"

/* _glBeginQuery @ 0x92f37b38 (132 bytes) */
int _glBeginQuery(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x27e])(*puVar2,param_1,param_2);
  return;
}

/* _glEndQuery @ 0x92f37bbc (124 bytes) */
int _glEndQuery(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x27f])(*puVar2,param_1);
  return;
}

/* _glGetQueryiv @ 0x92f37c38 (140 bytes) */
int _glGetQueryiv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x280])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetQueryObjectiv @ 0x92f37cc4 (140 bytes) */
int _glGetQueryObjectiv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x281])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetQueryObjectuiv @ 0x92f37d50 (140 bytes) */
int _glGetQueryObjectuiv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x282])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glBindBuffer @ 0x92f37ddc (132 bytes) */
int _glBindBuffer(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x283])(*puVar2,param_1,param_2);
  return;
}

/* _glDeleteBuffers @ 0x92f37e60 (132 bytes) */
int _glDeleteBuffers(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x284])(*puVar2,param_1,param_2);
  return;
}

/* _glGenBuffers @ 0x92f37ee4 (132 bytes) */
int _glGenBuffers(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x285])(*puVar2,param_1,param_2);
  return;
}

/* _glIsBuffer @ 0x92f37f68 (128 bytes) */
int _glIsBuffer(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffb0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffb0);
  }
  (*(code *)puVar2[0x286])(*puVar2,param_1);
  return;
}

/* _glBufferData @ 0x92f37fe8 (148 bytes) */
int _glBufferData(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x287])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glBufferSubData @ 0x92f3807c (148 bytes) */
int _glBufferSubData(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x288])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glGetBufferSubData @ 0x92f38110 (148 bytes) */
int _glGetBufferSubData(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x289])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glMapBuffer @ 0x92f381a4 (132 bytes) */
int _glMapBuffer(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x28a])(*puVar2,param_1,param_2);
  return;
}

/* _glUnmapBuffer @ 0x92f38228 (128 bytes) */
int _glUnmapBuffer(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffb0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffb0);
  }
  (*(code *)puVar2[0x28b])(*puVar2,param_1);
  return;
}

/* _glGetBufferParameteriv @ 0x92f382a8 (140 bytes) */
int _glGetBufferParameteriv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x28c])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetBufferPointerv @ 0x92f38334 (140 bytes) */
int _glGetBufferPointerv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x28d])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glDrawBuffers @ 0x92f383c0 (132 bytes) */
int _glDrawBuffers(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x28f])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib1d @ 0x92f38444 (140 bytes) */
void _glVertexAttrib1d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1de])(fparam_1,*puVar2,param_1);
  return;
}

/* _glVertexAttrib1dv @ 0x92f384d0 (132 bytes) */
int _glVertexAttrib1dv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1eb])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib1f @ 0x92f38554 (140 bytes) */
void _glVertexAttrib1f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1dd])(fparam_1,*puVar2,param_1);
  return;
}

/* _glVertexAttrib1fv @ 0x92f385e0 (132 bytes) */
int _glVertexAttrib1fv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1ea])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib1s @ 0x92f38664 (132 bytes) */
int _glVertexAttrib1s(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1dc])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib1sv @ 0x92f386e8 (132 bytes) */
int _glVertexAttrib1sv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1e9])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib2d @ 0x92f3876c (156 bytes) */
void _glVertexAttrib2d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                      double fparam_2)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)puVar2[0x1e1])(fparam_1,fparam_2,*puVar2,param_1);
  return;
}

/* _glVertexAttrib2dv @ 0x92f38808 (132 bytes) */
int _glVertexAttrib2dv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1ee])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib2f @ 0x92f3888c (156 bytes) */
void _glVertexAttrib2f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                      double fparam_2)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)puVar2[0x1e0])(fparam_1,fparam_2,*puVar2,param_1);
  return;
}

/* _glVertexAttrib2fv @ 0x92f38928 (132 bytes) */
int _glVertexAttrib2fv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1ed])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib2s @ 0x92f389ac (140 bytes) */
int _glVertexAttrib2s(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1df])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glVertexAttrib2sv @ 0x92f38a38 (132 bytes) */
int _glVertexAttrib2sv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1ec])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib3d @ 0x92f38abc (172 bytes) */
void _glVertexAttrib3d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                      double fparam_2,double fparam_3)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)puVar2[0x1e4])(fparam_1,fparam_2,fparam_3,*puVar2,param_1);
  return;
}

/* _glVertexAttrib3dv @ 0x92f38b68 (132 bytes) */
int _glVertexAttrib3dv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1f1])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib3f @ 0x92f38bec (172 bytes) */
void _glVertexAttrib3f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                      double fparam_2,double fparam_3)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)puVar2[0x1e3])(fparam_1,fparam_2,fparam_3,*puVar2,param_1);
  return;
}

/* _glVertexAttrib3fv @ 0x92f38c98 (132 bytes) */
int _glVertexAttrib3fv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1f0])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib3s @ 0x92f38d1c (148 bytes) */
int _glVertexAttrib3s(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1e2])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glVertexAttrib3sv @ 0x92f38db0 (132 bytes) */
int _glVertexAttrib3sv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1ef])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib4Nbv @ 0x92f38e34 (132 bytes) */
int _glVertexAttrib4Nbv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1fa])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib4Niv @ 0x92f38eb8 (132 bytes) */
int _glVertexAttrib4Niv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1fc])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib4Nsv @ 0x92f38f3c (132 bytes) */
int _glVertexAttrib4Nsv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1fb])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib4Nub @ 0x92f38fc0 (152 bytes) */
int _glVertexAttrib4Nub(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1e8])(*puVar2,param_1,param_2,param_3,param_2,param_5);
  return;
}

/* _glVertexAttrib4Nubv @ 0x92f39058 (132 bytes) */
int _glVertexAttrib4Nubv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1f5])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib4Nuiv @ 0x92f390dc (132 bytes) */
int _glVertexAttrib4Nuiv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1ff])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib4Nusv @ 0x92f39160 (132 bytes) */
int _glVertexAttrib4Nusv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1fe])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib4bv @ 0x92f391e4 (132 bytes) */
int _glVertexAttrib4bv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1f2])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib4d @ 0x92f39268 (152 bytes) */
void _glVertexAttrib4d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                      double fparam_2,double fparam_3,double fparam_4)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff80)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff80);
  }
  (*(code *)puVar2[0x1e7])(fparam_1,fparam_2,fparam_3,fparam_4,*puVar2,param_1);
  return;
}

/* _glVertexAttrib4dv @ 0x92f39300 (132 bytes) */
int _glVertexAttrib4dv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1f9])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib4f @ 0x92f39384 (172 bytes) */
void _glVertexAttrib4f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,
                      double fparam_2,double fparam_3,double fparam_4)

{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff80)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff80);
  }
                    
                    
  (*(code *)puVar2[0x1e6])(fparam_1,fparam_2,fparam_3,fparam_4,*puVar2,param_1);
  return;
}

/* _glVertexAttrib4fv @ 0x92f39430 (132 bytes) */
int _glVertexAttrib4fv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1f8])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib4iv @ 0x92f394b4 (132 bytes) */
int _glVertexAttrib4iv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[500])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib4s @ 0x92f39538 (156 bytes) */
int _glVertexAttrib4s(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)puVar2[0x1e5])(*puVar2,param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glVertexAttrib4sv @ 0x92f395d4 (132 bytes) */
int _glVertexAttrib4sv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[499])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib4ubv @ 0x92f39658 (132 bytes) */
int _glVertexAttrib4ubv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1f5])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib4uiv @ 0x92f396dc (132 bytes) */
int _glVertexAttrib4uiv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1f7])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttrib4usv @ 0x92f39760 (132 bytes) */
int _glVertexAttrib4usv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x1f6])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexAttribPointer @ 0x92f397e4 (164 bytes) */
int _glVertexAttribPointer(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)puVar2[0x200])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

/* _glEnableVertexAttribArray @ 0x92f39888 (124 bytes) */
int _glEnableVertexAttribArray(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x201])(*puVar2,param_1);
  return;
}

/* _glDisableVertexAttribArray @ 0x92f39904 (124 bytes) */
int _glDisableVertexAttribArray(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x202])(*puVar2,param_1);
  return;
}

/* _glGetVertexAttribdv @ 0x92f39980 (140 bytes) */
int _glGetVertexAttribdv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x203])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetVertexAttribfv @ 0x92f39a0c (140 bytes) */
int _glGetVertexAttribfv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x204])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetVertexAttribiv @ 0x92f39a98 (140 bytes) */
int _glGetVertexAttribiv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x205])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetVertexAttribPointerv @ 0x92f39b24 (140 bytes) */
int _glGetVertexAttribPointerv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffffa0)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffffa0);
  }
                    
                    
  (*(code *)puVar2[0x206])(*puVar2,param_1,param_2,param_3);
  return;
}

