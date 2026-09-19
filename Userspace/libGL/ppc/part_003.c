#include "decls.h"

/* _glGetTexGenfv @ 0x92f2d898 (140 bytes) */
int _glGetTexGenfv(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x7a])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetTexGeniv @ 0x92f2d924 (140 bytes) */
int _glGetTexGeniv(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x7b])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetTexImage @ 0x92f2d9b0 (156 bytes) */
int _glGetTexImage(param_1, param_2, param_3, param_4, param_5)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
  undefined8 param_5;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_70 [28];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_70[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_70) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_70;
  }
                    
                    
  (*(code *)puVar2[0x7c])(*puVar2,param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glGetTexLevelParameterfv @ 0x92f2da4c (148 bytes) */
int _glGetTexLevelParameterfv(param_1, param_2, param_3, param_4)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x7d])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glGetTexParameterfv @ 0x92f2dae0 (140 bytes) */
int _glGetTexParameterfv(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x7f])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetTexParameteriv @ 0x92f2db6c (140 bytes) */
int _glGetTexParameteriv(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x80])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glIndexMask @ 0x92f2dbf8 (124 bytes) */
int _glIndexMask(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x82])(*puVar2,param_1);
  return;
}

/* _glIndexPointer @ 0x92f2dc74 (140 bytes) */
int _glIndexPointer(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x83])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glIndexd @ 0x92f2dd00 (128 bytes) */
int _glIndexd(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x84])(param_1,*puVar2);
  return;
}

/* _glIndexdv @ 0x92f2dd80 (124 bytes) */
int _glIndexdv(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x85])(*puVar2,param_1);
  return;
}

/* _glIndexf @ 0x92f2ddfc (128 bytes) */
int _glIndexf(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x86])(param_1,*puVar2);
  return;
}

/* _glIndexfv @ 0x92f2de7c (124 bytes) */
int _glIndexfv(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x87])(*puVar2,param_1);
  return;
}

/* _glIndexi @ 0x92f2def8 (124 bytes) */
int _glIndexi(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x88])(*puVar2,param_1);
  return;
}

/* _glIndexiv @ 0x92f2df74 (124 bytes) */
int _glIndexiv(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x89])(*puVar2,param_1);
  return;
}

/* _glIndexs @ 0x92f2dff0 (124 bytes) */
int _glIndexs(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x8a])(*puVar2,param_1);
  return;
}

/* _glIndexsv @ 0x92f2e06c (124 bytes) */
int _glIndexsv(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x8b])(*puVar2,param_1);
  return;
}

/* _glIndexub @ 0x92f2e0e8 (124 bytes) */
int _glIndexub(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x8c])(*puVar2,param_1);
  return;
}

/* _glIndexubv @ 0x92f2e164 (124 bytes) */
int _glIndexubv(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x8d])(*puVar2,param_1);
  return;
}

/* _glInitNames @ 0x92f2e1e0 (112 bytes) */
int _glInitNames()
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_50 [20];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_50[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_50) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_50;
  }
                    
                    
  (*(code *)puVar2[0x8e])(*puVar2);
  return;
}

/* _glInterleavedArrays @ 0x92f2e250 (140 bytes) */
int _glInterleavedArrays(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x8f])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glIsEnabled @ 0x92f2e2dc (128 bytes) */
int _glIsEnabled(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_50 [20];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_50[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_50) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_50;
  }
  (*(code *)puVar2[0x90])(*puVar2,param_1);
  return;
}

/* _glIsList @ 0x92f2e35c (128 bytes) */
int _glIsList(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_50 [20];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_50[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_50) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_50;
  }
  (*(code *)puVar2[0x91])(*puVar2,param_1);
  return;
}

/* _glIsTexture @ 0x92f2e3dc (128 bytes) */
int _glIsTexture(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_50 [20];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_50[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_50) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_50;
  }
  (*(code *)puVar2[0x92])(*puVar2,param_1);
  return;
}

/* _glLightModelf @ 0x92f2e45c (140 bytes) */
int _glLightModelf(param_1, param_2)
  undefined8 param_1;
  undefined8 param_2;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x93])(param_1,*puVar2,param_2);
  return;
}

/* _glLightModelfv @ 0x92f2e4e8 (132 bytes) */
int _glLightModelfv(param_1, param_2)
  undefined8 param_1;
  undefined8 param_2;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x94])(*puVar2,param_1,param_2);
  return;
}

/* _glLightModeliv @ 0x92f2e56c (132 bytes) */
int _glLightModeliv(param_1, param_2)
  undefined8 param_1;
  undefined8 param_2;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x96])(*puVar2,param_1,param_2);
  return;
}

/* _glLightf @ 0x92f2e5f0 (148 bytes) */
int _glLightf(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x97])(param_1,*puVar2,param_2,param_3);
  return;
}

/* _glLighti @ 0x92f2e684 (140 bytes) */
int _glLighti(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x99])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glLightiv @ 0x92f2e710 (140 bytes) */
int _glLightiv(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x9a])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glLineStipple @ 0x92f2e79c (132 bytes) */
int _glLineStipple(param_1, param_2)
  undefined8 param_1;
  undefined8 param_2;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x9b])(*puVar2,param_1,param_2);
  return;
}

/* _glListBase @ 0x92f2e820 (124 bytes) */
int _glListBase(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x9d])(*puVar2,param_1);
  return;
}

/* _glLoadMatrixd @ 0x92f2e89c (124 bytes) */
int _glLoadMatrixd(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0x9f])(*puVar2,param_1);
  return;
}

/* _glLogicOp @ 0x92f2e918 (124 bytes) */
int _glLogicOp(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0xa2])(*puVar2,param_1);
  return;
}

/* _glMap1d @ 0x92f2e994 (184 bytes) */
int _glMap1d(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 in_r10;
  undefined1 *local_80 [14];
  undefined4 local_48;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_80[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_80) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_80;
  }
  local_48 = in_r10;
  (*(code *)puVar2[0xa3])(param_1,param_2,*puVar2,param_3);
  return;
}

/* _glMap1f @ 0x92f2ea4c (180 bytes) */
int _glMap1f(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_70 [28];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_70[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_70) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_70;
  }
                    
                    
  (*(code *)puVar2[0xa4])(param_1,param_2,*puVar2,param_3);
  return;
}

/* _glMap2d @ 0x92f2eb00 (192 bytes) */
int _glMap2d(param_1, param_2, param_3, param_4)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
{
  undefined *puVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  undefined8 extraout_f1;
  undefined8 uVar4;
  undefined4 in_stack_00000044;
  undefined4 in_stack_00000048;
  undefined4 in_stack_0000004c;
  undefined1 *local_a0 [18];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  
  uVar2 = FUN_92f27fc8();
  puVar1 = PTR__gll_cc_a2f27020;
  puVar3 = *(undefined4 **)PTR__gll_cc_a2f27020;
  uVar4 = extraout_f1;
  local_a0[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar3[0x2ac] ^ (uint)local_a0) & 0xfffff000) != 0) {
    puVar3 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar3;
    puVar3[0x2ac] = local_a0;
  }
  local_58 = in_stack_00000044;
  local_54 = in_stack_00000048;
  local_50 = in_stack_0000004c;
  (*(code *)puVar3[0xa5])(uVar4,param_2,param_3,param_4,*puVar3,uVar2);
  return;
}

/* _glMap2f @ 0x92f2ebc0 (192 bytes) */
int _glMap2f(param_1, param_2, param_3, param_4)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
{
  undefined *puVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  undefined4 in_r10;
  undefined8 extraout_f1;
  undefined8 uVar4;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  undefined1 *local_90 [14];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  
  local_58 = in_r10;
  uVar2 = FUN_92f27fc8();
  puVar1 = PTR__gll_cc_a2f27020;
  puVar3 = *(undefined4 **)PTR__gll_cc_a2f27020;
  uVar4 = extraout_f1;
  local_90[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar3[0x2ac] ^ (uint)local_90) & 0xfffff000) != 0) {
    puVar3 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar3;
    puVar3[0x2ac] = local_90;
  }
  local_54 = in_stack_00000038;
  local_50 = in_stack_0000003c;
  (*(code *)puVar3[0xa6])(uVar4,param_2,param_3,param_4,*puVar3,uVar2);
  return;
}

/* _glMapGrid1d @ 0x92f2ec80 (156 bytes) */
int _glMapGrid1d(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_70 [28];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_70[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_70) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_70;
  }
                    
                    
  (*(code *)puVar2[0xa7])(param_1,param_2,*puVar2,param_3);
  return;
}

/* _glMapGrid1f @ 0x92f2ed1c (156 bytes) */
int _glMapGrid1f(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_70 [28];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_70[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_70) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_70;
  }
                    
                    
  (*(code *)puVar2[0xa8])(param_1,param_2,*puVar2,param_3);
  return;
}

/* _glMapGrid2d @ 0x92f2edb8 (160 bytes) */
int _glMapGrid2d(param_1, param_2, param_3, param_4)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
{
  undefined *puVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  undefined8 extraout_f1;
  undefined8 uVar4;
  undefined1 *local_90 [36];
  
  uVar2 = FUN_92f27fc8();
  puVar1 = PTR__gll_cc_a2f27020;
  puVar3 = *(undefined4 **)PTR__gll_cc_a2f27020;
  uVar4 = extraout_f1;
  local_90[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar3[0x2ac] ^ (uint)local_90) & 0xfffff000) != 0) {
    puVar3 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar3;
    puVar3[0x2ac] = local_90;
  }
  (*(code *)puVar3[0xa9])(uVar4,param_2,param_3,param_4,*puVar3,uVar2);
  return;
}

/* _glMapGrid2f @ 0x92f2ee58 (180 bytes) */
int _glMapGrid2f(param_1, param_2, param_3, param_4)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
{
  undefined *puVar1;
  undefined8 uVar2;
  undefined4 *puVar3;
  undefined8 extraout_f1;
  undefined8 uVar4;
  undefined1 *local_80 [32];
  
  uVar2 = FUN_92f27fc8();
  puVar1 = PTR__gll_cc_a2f27020;
  puVar3 = *(undefined4 **)PTR__gll_cc_a2f27020;
  uVar4 = extraout_f1;
  local_80[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar3[0x2ac] ^ (uint)local_80) & 0xfffff000) != 0) {
    puVar3 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar3;
    puVar3[0x2ac] = local_80;
  }
                    
                    
  (*(code *)puVar3[0xaa])(uVar4,param_2,param_3,param_4,*puVar3,uVar2);
  return;
}

/* _glMateriali @ 0x92f2ef0c (140 bytes) */
int _glMateriali(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0xad])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glMaterialiv @ 0x92f2ef98 (140 bytes) */
int _glMaterialiv(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0xae])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glMultMatrixd @ 0x92f2f024 (124 bytes) */
int _glMultMatrixd(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0xb0])(*puVar2,param_1);
  return;
}

/* _glMultMatrixf @ 0x92f2f0a0 (124 bytes) */
int _glMultMatrixf(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0xb1])(*puVar2,param_1);
  return;
}

/* _glNormal3b @ 0x92f2f11c (140 bytes) */
int _glNormal3b(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0xb3])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glNormal3bv @ 0x92f2f1a8 (124 bytes) */
int _glNormal3bv(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0xb4])(*puVar2,param_1);
  return;
}

/* _glNormal3d @ 0x92f2f224 (160 bytes) */
int _glNormal3d(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_70 [28];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_70[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_70) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_70;
  }
                    
                    
  (*(code *)puVar2[0xb5])(param_1,param_2,param_3,*puVar2);
  return;
}

/* _glNormal3dv @ 0x92f2f2c4 (124 bytes) */
int _glNormal3dv(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0xb6])(*puVar2,param_1);
  return;
}

/* _glNormal3fv @ 0x92f2f340 (124 bytes) */
int _glNormal3fv(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0xb8])(*puVar2,param_1);
  return;
}

/* _glNormal3i @ 0x92f2f3bc (140 bytes) */
int _glNormal3i(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0xb9])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glNormal3iv @ 0x92f2f448 (124 bytes) */
int _glNormal3iv(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0xba])(*puVar2,param_1);
  return;
}

/* _glNormal3s @ 0x92f2f4c4 (140 bytes) */
int _glNormal3s(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0xbb])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glNormal3sv @ 0x92f2f550 (124 bytes) */
int _glNormal3sv(param_1)
  undefined8 param_1;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0xbc])(*puVar2,param_1);
  return;
}

/* _glNormalPointer @ 0x92f2f5cc (140 bytes) */
int _glNormalPointer(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0xbd])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glOrtho @ 0x92f2f658 (156 bytes) */
int _glOrtho(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
  undefined8 param_5;
  undefined8 param_6;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined1 *local_a0 [40];
  
  uVar3 = FUN_92f27fc0();
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_a0[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_a0) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_a0;
  }
  (*(code *)puVar2[0xbe])(uVar3,param_2,param_3,param_4,param_5,param_6,*puVar2);
  FUN_92f27b4c();
  return;
}

/* _glPixelMapfv @ 0x92f2f6f4 (140 bytes) */
int _glPixelMapfv(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0xc0])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glPixelMapuiv @ 0x92f2f780 (140 bytes) */
int _glPixelMapuiv(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0xc1])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glPixelMapusv @ 0x92f2f80c (140 bytes) */
int _glPixelMapusv(param_1, param_2, param_3)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0xc2])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glPixelStoref @ 0x92f2f898 (140 bytes) */
int _glPixelStoref(param_1, param_2)
  undefined8 param_1;
  undefined8 param_2;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined1 *local_60 [24];
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_60[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_60) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_60;
  }
                    
                    
  (*(code *)puVar2[0xc3])(param_1,*puVar2,param_2);
  return;
}

