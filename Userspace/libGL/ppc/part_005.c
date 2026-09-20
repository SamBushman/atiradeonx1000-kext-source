#include "decls.h"

/* _glTexCoord3d @ 0x92f317b4 (160 bytes) */
int _glTexCoord3d(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
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
                    
                    
  (*(code *)puVar2[0x112])(param_1,param_2,param_3,*puVar2);
  return;
}

/* _glTexCoord3dv @ 0x92f31854 (124 bytes) */
int _glTexCoord3dv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x113])(*puVar2,param_1);
  return;
}

/* _glTexCoord3fv @ 0x92f318d0 (124 bytes) */
int _glTexCoord3fv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x115])(*puVar2,param_1);
  return;
}

/* _glTexCoord3i @ 0x92f3194c (140 bytes) */
int _glTexCoord3i(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
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
                    
                    
  (*(code *)puVar2[0x116])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glTexCoord3iv @ 0x92f319d8 (124 bytes) */
int _glTexCoord3iv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x117])(*puVar2,param_1);
  return;
}

/* _glTexCoord3s @ 0x92f31a54 (140 bytes) */
int _glTexCoord3s(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
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
                    
                    
  (*(code *)puVar2[0x118])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glTexCoord3sv @ 0x92f31ae0 (124 bytes) */
int _glTexCoord3sv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x119])(*puVar2,param_1);
  return;
}

/* _glTexCoord4d @ 0x92f31b5c (140 bytes) */
int _glTexCoord4d(param_1, param_2, param_3, param_4)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_92f27fc8();
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff80)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff80);
  }
  (*(code *)puVar2[0x11a])(uVar3,param_2,param_3,param_4,*puVar2);
  return;
}

/* _glTexCoord4dv @ 0x92f31be8 (124 bytes) */
int _glTexCoord4dv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x11b])(*puVar2,param_1);
  return;
}

/* _glTexCoord4f @ 0x92f31c64 (160 bytes) */
int _glTexCoord4f(param_1, param_2, param_3, param_4)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_92f27fc8();
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)puVar2[0x11c])(uVar3,param_2,param_3,param_4,*puVar2);
  return;
}

/* _glTexCoord4fv @ 0x92f31d04 (124 bytes) */
int _glTexCoord4fv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x11d])(*puVar2,param_1);
  return;
}

/* _glTexCoord4i @ 0x92f31d80 (148 bytes) */
int _glTexCoord4i(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
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
                    
                    
  (*(code *)puVar2[0x11e])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glTexCoord4iv @ 0x92f31e14 (124 bytes) */
int _glTexCoord4iv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x11f])(*puVar2,param_1);
  return;
}

/* _glTexCoord4s @ 0x92f31e90 (148 bytes) */
int _glTexCoord4s(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
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
                    
                    
  (*(code *)puVar2[0x120])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glTexCoord4sv @ 0x92f31f24 (124 bytes) */
int _glTexCoord4sv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x121])(*puVar2,param_1);
  return;
}

/* _glTexEnvfv @ 0x92f31fa0 (140 bytes) */
int _glTexEnvfv(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
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
                    
                    
  (*(code *)puVar2[0x124])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glTexEnviv @ 0x92f3202c (140 bytes) */
int _glTexEnviv(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
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
                    
                    
  (*(code *)puVar2[0x126])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glTexGend @ 0x92f320b8 (148 bytes) */
int _glTexGend(param_1, param_2, param_3)
  undefined8 param_1;
  undefined4 param_2;
  undefined4 param_3;
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
                    
                    
  (*(code *)puVar2[0x127])(param_1,*puVar2,param_2,param_3);
  return;
}

/* _glTexGendv @ 0x92f3214c (140 bytes) */
int _glTexGendv(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
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
                    
                    
  (*(code *)puVar2[0x128])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glTexGenf @ 0x92f321d8 (148 bytes) */
int _glTexGenf(param_1, param_2, param_3)
  undefined8 param_1;
  undefined4 param_2;
  undefined4 param_3;
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
                    
                    
  (*(code *)puVar2[0x129])(param_1,*puVar2,param_2,param_3);
  return;
}

/* _glTexGenfv @ 0x92f3226c (140 bytes) */
int _glTexGenfv(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
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
                    
                    
  (*(code *)puVar2[0x12a])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glTexGeni @ 0x92f322f8 (140 bytes) */
int _glTexGeni(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
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
                    
                    
  (*(code *)puVar2[299])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glTexGeniv @ 0x92f32384 (140 bytes) */
int _glTexGeniv(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
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
                    
                    
  (*(code *)puVar2[300])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glTexImage1D @ 0x92f32410 (184 bytes) */
int _glTexImage1D(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff80)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff80);
  }
  (*(code *)puVar2[0x12d])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glTexParameterfv @ 0x92f324c8 (140 bytes) */
int _glTexParameterfv(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
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
                    
                    
  (*(code *)puVar2[0x130])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glTexParameteriv @ 0x92f32554 (140 bytes) */
int _glTexParameteriv(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
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
                    
                    
  (*(code *)puVar2[0x132])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glTexSubImage1D @ 0x92f325e0 (172 bytes) */
int _glTexSubImage1D(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x133])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glVertex2d @ 0x92f3268c (144 bytes) */
int _glVertex2d(param_1, param_2)
  undefined8 param_1;
  undefined8 param_2;
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
                    
                    
  (*(code *)puVar2[0x137])(param_1,param_2,*puVar2);
  return;
}

/* _glVertex2dv @ 0x92f3271c (124 bytes) */
int _glVertex2dv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x138])(*puVar2,param_1);
  return;
}

/* _glVertex2fv @ 0x92f32798 (124 bytes) */
int _glVertex2fv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x13a])(*puVar2,param_1);
  return;
}

/* _glVertex2i @ 0x92f32814 (132 bytes) */
int _glVertex2i(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
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
                    
                    
  (*(code *)puVar2[0x13b])(*puVar2,param_1,param_2);
  return;
}

/* _glVertex2iv @ 0x92f32898 (124 bytes) */
int _glVertex2iv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x13c])(*puVar2,param_1);
  return;
}

/* _glVertex2s @ 0x92f32914 (132 bytes) */
int _glVertex2s(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
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
                    
                    
  (*(code *)puVar2[0x13d])(*puVar2,param_1,param_2);
  return;
}

/* _glVertex2sv @ 0x92f32998 (124 bytes) */
int _glVertex2sv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x13e])(*puVar2,param_1);
  return;
}

/* _glVertex3dv @ 0x92f32a14 (124 bytes) */
int _glVertex3dv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x140])(*puVar2,param_1);
  return;
}

/* _glVertex3fv @ 0x92f32a90 (124 bytes) */
int _glVertex3fv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x142])(*puVar2,param_1);
  return;
}

/* _glVertex3i @ 0x92f32b0c (140 bytes) */
int _glVertex3i(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
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
                    
                    
  (*(code *)puVar2[0x143])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glVertex3iv @ 0x92f32b98 (124 bytes) */
int _glVertex3iv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x144])(*puVar2,param_1);
  return;
}

/* _glVertex3s @ 0x92f32c14 (140 bytes) */
int _glVertex3s(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
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
                    
                    
  (*(code *)puVar2[0x145])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glVertex3sv @ 0x92f32ca0 (124 bytes) */
int _glVertex3sv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x146])(*puVar2,param_1);
  return;
}

/* _glVertex4d @ 0x92f32d1c (140 bytes) */
int _glVertex4d(param_1, param_2, param_3, param_4)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_92f27fc8();
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff80)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff80);
  }
  (*(code *)puVar2[0x147])(uVar3,param_2,param_3,param_4,*puVar2);
  return;
}

/* _glVertex4dv @ 0x92f32da8 (124 bytes) */
int _glVertex4dv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x148])(*puVar2,param_1);
  return;
}

/* _glVertex4f @ 0x92f32e24 (160 bytes) */
int _glVertex4f(param_1, param_2, param_3, param_4)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_92f27fc8();
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)puVar2[0x149])(uVar3,param_2,param_3,param_4,*puVar2);
  return;
}

/* _glVertex4fv @ 0x92f32ec4 (124 bytes) */
int _glVertex4fv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x14a])(*puVar2,param_1);
  return;
}

/* _glVertex4i @ 0x92f32f40 (148 bytes) */
int _glVertex4i(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
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
                    
                    
  (*(code *)puVar2[0x14b])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glVertex4iv @ 0x92f32fd4 (124 bytes) */
int _glVertex4iv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x14c])(*puVar2,param_1);
  return;
}

/* _glVertex4s @ 0x92f33050 (148 bytes) */
int _glVertex4s(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
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
                    
                    
  (*(code *)puVar2[0x14d])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glVertex4sv @ 0x92f330e4 (124 bytes) */
int _glVertex4sv(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x14e])(*puVar2,param_1);
  return;
}

/* _glBlendColor @ 0x92f33160 (160 bytes) */
int _glBlendColor(param_1, param_2, param_3, param_4)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  
  uVar3 = FUN_92f27fc8();
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff90)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff90);
  }
                    
                    
  (*(code *)puVar2[0x152])(uVar3,param_2,param_3,param_4,*puVar2);
  return;
}

/* _glBlendEquation @ 0x92f33200 (124 bytes) */
int _glBlendEquation(param_1)
  undefined4 param_1;
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
                    
                    
  (*(code *)puVar2[0x153])(*puVar2,param_1);
  return;
}

/* _glDrawRangeElements @ 0x92f3327c (164 bytes) */
int _glDrawRangeElements(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
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
                    
                    
  (*(code *)puVar2[0x196])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

/* _glTexImage3D @ 0x92f33320 (200 bytes) */
int _glTexImage3D(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff80)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff80);
  }
  (*(code *)puVar2[0x1b7])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glTexSubImage3D @ 0x92f333e8 (208 bytes) */
int _glTexSubImage3D(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff80)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff80);
  }
  (*(code *)puVar2[0x1b8])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glCopyTexSubImage3D @ 0x92f334b8 (192 bytes) */
int _glCopyTexSubImage3D(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff80)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff80);
  }
  (*(code *)puVar2[0x1b9])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glColorTable @ 0x92f33578 (164 bytes) */
int _glColorTable(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
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
                    
                    
  (*(code *)puVar2[0x197])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

/* _glColorTableParameterfv @ 0x92f3361c (140 bytes) */
int _glColorTableParameterfv(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
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
                    
                    
  (*(code *)puVar2[0x198])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glColorTableParameteriv @ 0x92f336a8 (140 bytes) */
int _glColorTableParameteriv(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
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
                    
                    
  (*(code *)puVar2[0x199])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glCopyColorTable @ 0x92f33734 (156 bytes) */
int _glCopyColorTable(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
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
                    
                    
  (*(code *)puVar2[0x19a])(*puVar2,param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glGetColorTable @ 0x92f337d0 (148 bytes) */
int _glGetColorTable(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
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
                    
                    
  (*(code *)puVar2[0x19b])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glGetColorTableParameterfv @ 0x92f33864 (140 bytes) */
int _glGetColorTableParameterfv(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
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
                    
                    
  (*(code *)puVar2[0x19c])(*puVar2,param_1,param_2,param_3);
  return;
}

