#include "decls.h"

/* _glMultTransposeMatrixd @ 0x92f35b0c (124 bytes) */
int _glMultTransposeMatrixd(param_1)
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
                    
                    
  (*(code *)puVar2[0x17a])(*puVar2,param_1);
  return;
}

/* _glMultTransposeMatrixf @ 0x92f35b88 (124 bytes) */
int _glMultTransposeMatrixf(param_1)
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
                    
                    
  (*(code *)puVar2[0x17b])(*puVar2,param_1);
  return;
}

/* _glCompressedTexImage3D @ 0x92f35c04 (192 bytes) */
int _glCompressedTexImage3D(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
  undefined8 param_5;
  undefined8 param_6;
  undefined8 param_7;
  undefined4 param_8;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 in_stack_00000038;
  undefined1 *local_80 [14];
  undefined4 local_48;
  undefined4 local_44;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_80[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_80) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_80;
  }
  local_44 = in_stack_00000038;
  local_48 = param_8;
  (*(code *)puVar2[0x17c])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glCompressedTexImage2D @ 0x92f35cc4 (184 bytes) */
int _glCompressedTexImage2D(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
  undefined8 param_5;
  undefined8 param_6;
  undefined8 param_7;
  undefined4 param_8;
{
  undefined *puVar1;
  undefined4 *puVar2;
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
  local_48 = param_8;
  (*(code *)puVar2[0x17d])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glCompressedTexImage1D @ 0x92f35d7c (172 bytes) */
int _glCompressedTexImage1D(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
  undefined8 param_5;
  undefined8 param_6;
  undefined8 param_7;
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
                    
                    
  (*(code *)puVar2[0x17e])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glCompressedTexSubImage3D @ 0x92f35e28 (208 bytes) */
int _glCompressedTexSubImage3D(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
  undefined8 param_5;
  undefined8 param_6;
  undefined8 param_7;
  undefined4 param_8;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  undefined4 in_stack_00000040;
  undefined1 *local_80 [14];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_80[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_80) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_80;
  }
  local_44 = in_stack_00000038;
  local_3c = in_stack_00000040;
  local_40 = in_stack_0000003c;
  local_48 = param_8;
  (*(code *)puVar2[0x17f])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glCompressedTexSubImage2D @ 0x92f35ef8 (192 bytes) */
int _glCompressedTexSubImage2D(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
  undefined8 param_5;
  undefined8 param_6;
  undefined8 param_7;
  undefined4 param_8;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined4 in_stack_00000038;
  undefined1 *local_80 [14];
  undefined4 local_48;
  undefined4 local_44;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_80[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_80) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_80;
  }
  local_44 = in_stack_00000038;
  local_48 = param_8;
  (*(code *)puVar2[0x180])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glCompressedTexSubImage1D @ 0x92f35fb8 (172 bytes) */
int _glCompressedTexSubImage1D(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
  undefined8 param_5;
  undefined8 param_6;
  undefined8 param_7;
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
                    
                    
  (*(code *)puVar2[0x181])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glGetCompressedTexImage @ 0x92f36064 (140 bytes) */
int _glGetCompressedTexImage(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x182])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glSampleCoverage @ 0x92f360f0 (136 bytes) */
int _glSampleCoverage(param_1)
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
                    
                    
  (*(code *)puVar2[0x1cc])(param_1,*puVar2);
  return;
}

/* _glSamplePass @ 0x92f36178 (124 bytes) */
int _glSamplePass(param_1)
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
                    
                    
  (*(code *)puVar2[0x1cd])(*puVar2,param_1);
  return;
}

/* _glFogCoordf @ 0x92f361f4 (128 bytes) */
int _glFogCoordf(param_1)
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
                    
                    
  (*(code *)puVar2[0x221])(param_1,*puVar2);
  return;
}

/* _glFogCoordfv @ 0x92f36274 (124 bytes) */
int _glFogCoordfv(param_1)
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
                    
                    
  (*(code *)puVar2[0x222])(*puVar2,param_1);
  return;
}

/* _glFogCoordd @ 0x92f362f0 (128 bytes) */
int _glFogCoordd(param_1)
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
                    
                    
  (*(code *)puVar2[0x223])(param_1,*puVar2);
  return;
}

/* _glFogCoorddv @ 0x92f36370 (124 bytes) */
int _glFogCoorddv(param_1)
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
                    
                    
  (*(code *)puVar2[0x224])(*puVar2,param_1);
  return;
}

/* _glFogCoordPointer @ 0x92f363ec (140 bytes) */
int _glFogCoordPointer(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x225])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glSecondaryColor3b @ 0x92f36478 (140 bytes) */
int _glSecondaryColor3b(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x183])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glSecondaryColor3bv @ 0x92f36504 (124 bytes) */
int _glSecondaryColor3bv(param_1)
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
                    
                    
  (*(code *)puVar2[0x184])(*puVar2,param_1);
  return;
}

/* _glSecondaryColor3d @ 0x92f36580 (160 bytes) */
int _glSecondaryColor3d(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x185])(param_1,param_2,param_3,*puVar2);
  return;
}

/* _glSecondaryColor3dv @ 0x92f36620 (124 bytes) */
int _glSecondaryColor3dv(param_1)
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
                    
                    
  (*(code *)puVar2[0x186])(*puVar2,param_1);
  return;
}

/* _glSecondaryColor3f @ 0x92f3669c (160 bytes) */
int _glSecondaryColor3f(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x187])(param_1,param_2,param_3,*puVar2);
  return;
}

/* _glSecondaryColor3fv @ 0x92f3673c (124 bytes) */
int _glSecondaryColor3fv(param_1)
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
                    
                    
  (*(code *)puVar2[0x188])(*puVar2,param_1);
  return;
}

/* _glSecondaryColor3i @ 0x92f367b8 (140 bytes) */
int _glSecondaryColor3i(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x189])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glSecondaryColor3iv @ 0x92f36844 (124 bytes) */
int _glSecondaryColor3iv(param_1)
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
                    
                    
  (*(code *)puVar2[0x18a])(*puVar2,param_1);
  return;
}

/* _glSecondaryColor3s @ 0x92f368c0 (140 bytes) */
int _glSecondaryColor3s(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x18b])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glSecondaryColor3sv @ 0x92f3694c (124 bytes) */
int _glSecondaryColor3sv(param_1)
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
                    
                    
  (*(code *)puVar2[0x18c])(*puVar2,param_1);
  return;
}

/* _glSecondaryColor3ub @ 0x92f369c8 (140 bytes) */
int _glSecondaryColor3ub(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x18d])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glSecondaryColor3ubv @ 0x92f36a54 (124 bytes) */
int _glSecondaryColor3ubv(param_1)
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
                    
                    
  (*(code *)puVar2[0x18e])(*puVar2,param_1);
  return;
}

/* _glSecondaryColor3ui @ 0x92f36ad0 (140 bytes) */
int _glSecondaryColor3ui(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[399])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glSecondaryColor3uiv @ 0x92f36b5c (124 bytes) */
int _glSecondaryColor3uiv(param_1)
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
                    
                    
  (*(code *)puVar2[400])(*puVar2,param_1);
  return;
}

/* _glSecondaryColor3us @ 0x92f36bd8 (140 bytes) */
int _glSecondaryColor3us(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x191])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glSecondaryColor3usv @ 0x92f36c64 (124 bytes) */
int _glSecondaryColor3usv(param_1)
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
                    
                    
  (*(code *)puVar2[0x192])(*puVar2,param_1);
  return;
}

/* _glSecondaryColorPointer @ 0x92f36ce0 (148 bytes) */
int _glSecondaryColorPointer(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x193])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glPointParameterf @ 0x92f36d74 (140 bytes) */
int _glPointParameterf(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x21d])(param_1,*puVar2,param_2);
  return;
}

/* _glPointParameterfv @ 0x92f36e00 (132 bytes) */
int _glPointParameterfv(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x21e])(*puVar2,param_1,param_2);
  return;
}

/* _glPointParameteri @ 0x92f36e84 (132 bytes) */
int _glPointParameteri(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x21f])(*puVar2,param_1,param_2);
  return;
}

/* _glPointParameteriv @ 0x92f36f08 (132 bytes) */
int _glPointParameteriv(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x220])(*puVar2,param_1,param_2);
  return;
}

/* _glBlendFuncSeparate @ 0x92f36f8c (148 bytes) */
int _glBlendFuncSeparate(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x151])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glMultiDrawArrays @ 0x92f37020 (148 bytes) */
int _glMultiDrawArrays(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x238])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glMultiDrawElements @ 0x92f370b4 (156 bytes) */
int _glMultiDrawElements(param_1, param_2, param_3, param_4, param_5)
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
                    
                    
  (*(code *)puVar2[0x239])(*puVar2,param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glWindowPos2d @ 0x92f37150 (144 bytes) */
int _glWindowPos2d(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x23a])(param_1,param_2,*puVar2);
  return;
}

/* _glWindowPos2dv @ 0x92f371e0 (124 bytes) */
int _glWindowPos2dv(param_1)
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
                    
                    
  (*(code *)puVar2[0x23b])(*puVar2,param_1);
  return;
}

/* _glWindowPos2f @ 0x92f3725c (144 bytes) */
int _glWindowPos2f(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x23c])(param_1,param_2,*puVar2);
  return;
}

/* _glWindowPos2fv @ 0x92f372ec (124 bytes) */
int _glWindowPos2fv(param_1)
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
                    
                    
  (*(code *)puVar2[0x23d])(*puVar2,param_1);
  return;
}

/* _glWindowPos2i @ 0x92f37368 (132 bytes) */
int _glWindowPos2i(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x23e])(*puVar2,param_1,param_2);
  return;
}

/* _glWindowPos2iv @ 0x92f373ec (124 bytes) */
int _glWindowPos2iv(param_1)
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
                    
                    
  (*(code *)puVar2[0x23f])(*puVar2,param_1);
  return;
}

/* _glWindowPos2s @ 0x92f37468 (132 bytes) */
int _glWindowPos2s(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x240])(*puVar2,param_1,param_2);
  return;
}

/* _glWindowPos2sv @ 0x92f374ec (124 bytes) */
int _glWindowPos2sv(param_1)
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
                    
                    
  (*(code *)puVar2[0x241])(*puVar2,param_1);
  return;
}

/* _glWindowPos3d @ 0x92f37568 (160 bytes) */
int _glWindowPos3d(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x242])(param_1,param_2,param_3,*puVar2);
  return;
}

/* _glWindowPos3dv @ 0x92f37608 (124 bytes) */
int _glWindowPos3dv(param_1)
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
                    
                    
  (*(code *)puVar2[0x243])(*puVar2,param_1);
  return;
}

/* _glWindowPos3f @ 0x92f37684 (160 bytes) */
int _glWindowPos3f(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x244])(param_1,param_2,param_3,*puVar2);
  return;
}

/* _glWindowPos3fv @ 0x92f37724 (124 bytes) */
int _glWindowPos3fv(param_1)
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
                    
                    
  (*(code *)puVar2[0x245])(*puVar2,param_1);
  return;
}

/* _glWindowPos3i @ 0x92f377a0 (140 bytes) */
int _glWindowPos3i(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x246])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glWindowPos3iv @ 0x92f3782c (124 bytes) */
int _glWindowPos3iv(param_1)
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
                    
                    
  (*(code *)puVar2[0x247])(*puVar2,param_1);
  return;
}

/* _glWindowPos3s @ 0x92f378a8 (140 bytes) */
int _glWindowPos3s(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x248])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glWindowPos3sv @ 0x92f37934 (124 bytes) */
int _glWindowPos3sv(param_1)
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
                    
                    
  (*(code *)puVar2[0x249])(*puVar2,param_1);
  return;
}

/* _glGenQueries @ 0x92f379b0 (132 bytes) */
int _glGenQueries(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x27b])(*puVar2,param_1,param_2);
  return;
}

/* _glDeleteQueries @ 0x92f37a34 (132 bytes) */
int _glDeleteQueries(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x27c])(*puVar2,param_1,param_2);
  return;
}

/* _glIsQuery @ 0x92f37ab8 (128 bytes) */
int _glIsQuery(param_1)
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
  (*(code *)puVar2[0x27d])(*puVar2,param_1);
  return;
}

/* _glBeginQuery @ 0x92f37b38 (132 bytes) */
int _glBeginQuery(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x27e])(*puVar2,param_1,param_2);
  return;
}

