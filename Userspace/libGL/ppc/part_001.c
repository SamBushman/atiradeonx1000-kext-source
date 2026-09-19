#include "decls.h"

/* _glPopAttrib @ 0x92f2984c (112 bytes) */
int _glPopAttrib()
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
                    
                    
  (*(code *)puVar2[0xcc])(*puVar2);
  return;
}

/* _glTexEnvf @ 0x92f298bc (148 bytes) */
int _glTexEnvf(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x123])(param_1,*puVar2,param_2,param_3);
  return;
}

/* _glAlphaFunc @ 0x92f29950 (140 bytes) */
int _glAlphaFunc(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[2])(param_1,*puVar2,param_2);
  return;
}

/* _glEnableClientState @ 0x92f299dc (124 bytes) */
int _glEnableClientState(param_1)
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
                    
                    
  (*(code *)puVar2[0x4a])(*puVar2,param_1);
  return;
}

/* _glGetError @ 0x92f29a58 (112 bytes) */
int _glGetError()
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
                    
                    
  (*(code *)puVar2[0x67])(*puVar2);
  return;
}

/* _glFlush @ 0x92f29ac8 (112 bytes) */
int _glFlush()
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
                    
                    
  (*(code *)puVar2[0x5b])(*puVar2);
  return;
}

/* _glScissor @ 0x92f29b38 (148 bytes) */
int _glScissor(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0xfc])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glGetDoublev @ 0x92f29bcc (132 bytes) */
int _glGetDoublev(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x66])(*puVar2,param_1,param_2);
  return;
}

/* _glRectd @ 0x92f29c50 (140 bytes) */
int _glRectd(param_1, param_2, param_3, param_4)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined1 *local_80 [32];
  
  uVar3 = FUN_92f27fc8();
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_80[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_80) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_80;
  }
  (*(code *)puVar2[0xef])(uVar3,param_2,param_3,param_4,*puVar2);
  return;
}

/* _glColorPointer @ 0x92f29cdc (148 bytes) */
int _glColorPointer(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x34])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glVertexPointer @ 0x92f29d70 (148 bytes) */
int _glVertexPointer(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x14f])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glTexCoordPointer @ 0x92f29e04 (148 bytes) */
int _glTexCoordPointer(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x122])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glDrawArrays @ 0x92f29e98 (140 bytes) */
int _glDrawArrays(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x42])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glPrioritizeTextures @ 0x92f29f24 (140 bytes) */
int _glPrioritizeTextures(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0xd0])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glTexImage2D @ 0x92f29fb0 (192 bytes) */
int _glTexImage2D(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
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
  (*(code *)puVar2[0x12e])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glFrustum @ 0x92f2a070 (156 bytes) */
int _glFrustum(param_1, param_2, param_3, param_4, param_5, param_6)
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
  (*(code *)puVar2[0x61])(uVar3,param_2,param_3,param_4,param_5,param_6,*puVar2);
  FUN_92f27b4c();
  return;
}

/* _glLoadMatrixf @ 0x92f2a10c (124 bytes) */
int _glLoadMatrixf(param_1)
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
                    
                    
  (*(code *)puVar2[0xa0])(*puVar2,param_1);
  return;
}

/* _glPassThrough @ 0x92f2a188 (128 bytes) */
int _glPassThrough(param_1)
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
                    
                    
  (*(code *)puVar2[0xbf])(param_1,*puVar2);
  return;
}

/* _glActiveTextureARB @ 0x92f2a208 (124 bytes) */
int _glActiveTextureARB(param_1)
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
                    
                    
  (*(code *)puVar2[0x157])(*puVar2,param_1);
  return;
}

/* _glVertex2f @ 0x92f2a284 (144 bytes) */
int _glVertex2f(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x139])(param_1,param_2,*puVar2);
  return;
}

/* _glMultiTexCoord2f @ 0x92f2a314 (156 bytes) */
int _glMultiTexCoord2f(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x162])(param_1,param_2,*puVar2,param_3);
  return;
}

/* _glDeleteTextures @ 0x92f2a3b0 (132 bytes) */
int _glDeleteTextures(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x3c])(*puVar2,param_1,param_2);
  return;
}

/* _glFeedbackBuffer @ 0x92f2a434 (140 bytes) */
int _glFeedbackBuffer(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x59])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glRenderMode @ 0x92f2a4c0 (124 bytes) */
int _glRenderMode(param_1)
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
                    
                    
  (*(code *)puVar2[0xf7])(*puVar2,param_1);
  return;
}

/* _glFogi @ 0x92f2a53c (132 bytes) */
int _glFogi(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x5e])(*puVar2,param_1,param_2);
  return;
}

/* _glFogfv @ 0x92f2a5c0 (132 bytes) */
int _glFogfv(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x5d])(*puVar2,param_1,param_2);
  return;
}

/* _glFogf @ 0x92f2a644 (140 bytes) */
int _glFogf(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x5c])(param_1,*puVar2,param_2);
  return;
}

/* _glFrontFace @ 0x92f2a6d0 (124 bytes) */
int _glFrontFace(param_1)
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
                    
                    
  (*(code *)puVar2[0x60])(*puVar2,param_1);
  return;
}

/* _glTexParameterf @ 0x92f2a74c (148 bytes) */
int _glTexParameterf(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x12f])(param_1,*puVar2,param_2,param_3);
  return;
}

/* _glGetTexLevelParameteriv @ 0x92f2a7e0 (148 bytes) */
int _glGetTexLevelParameteriv(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x7e])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glGetFloatv @ 0x92f2a874 (132 bytes) */
int _glGetFloatv(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x68])(*puVar2,param_1,param_2);
  return;
}

/* _glTexSubImage2D @ 0x92f2a8f8 (192 bytes) */
int _glTexSubImage2D(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
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
  (*(code *)puVar2[0x134])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glTexCoord3f @ 0x92f2a9b8 (160 bytes) */
int _glTexCoord3f(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x114])(param_1,param_2,param_3,*puVar2);
  return;
}

/* _glTextureRangeAPPLE @ 0x92f2aa58 (140 bytes) */
int _glTextureRangeAPPLE(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x1c9])(*puVar2,param_1,param_2,param_3);
  return;
}

/* __dyld_func_lookup @ 0x92f2aaec (32 bytes) */
int __dyld_func_lookup()
{
                    
                    
  (*dyld_func_lookup_pointer)();
  return;
}

/* ___initialize_Cplusplus @ 0x92f2ab0c (88 bytes) */
int ___initialize_Cplusplus()
{
  code *apcStack_28 [10];
  
  ((int (*)())__dyld_func_lookup)("__dyld_call_module_initializers_for_dylib",apcStack_28);
  if (apcStack_28[0] != (code *)0x0) {
    (*apcStack_28[0])(PTR___mh_dylib_header_a2f27018);
  }
  return;
}

/* FUN_92f2ab64 @ 0x92f2ab64 (32 bytes) */
int FUN_92f2ab64()
{
  ((int (*)())__dyld_func_lookup)();
  return;
}

/* _glAccum @ 0x92f2ab84 (140 bytes) */
int _glAccum(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[1])(param_1,*puVar2,param_2);
  return;
}

/* _glAreTexturesResident @ 0x92f2ac10 (144 bytes) */
int _glAreTexturesResident(param_1, param_2, param_3)
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
  (*(code *)puVar2[3])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glArrayElement @ 0x92f2aca0 (124 bytes) */
int _glArrayElement(param_1)
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
                    
                    
  (*(code *)puVar2[4])(*puVar2,param_1);
  return;
}

/* _glBitmap @ 0x92f2ad1c (188 bytes) */
int _glBitmap(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
  undefined8 param_5;
  undefined8 param_6;
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
                    
                    
  (*(code *)puVar3[7])(uVar4,param_2,param_3,param_4,*puVar3,uVar2,param_6);
  return;
}

/* _glCallLists @ 0x92f2add8 (140 bytes) */
int _glCallLists(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[10])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glClearAccum @ 0x92f2ae64 (160 bytes) */
int _glClearAccum(param_1, param_2, param_3, param_4)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
{
  undefined *puVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined1 *local_70 [28];
  
  uVar3 = FUN_92f27fc8();
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  local_70[0] = (undefined1 *)((unsigned int)__builtin_frame_address(0));
  if (((puVar2[0x2ac] ^ (uint)local_70) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = local_70;
  }
                    
                    
  (*(code *)puVar2[0xc])(uVar3,param_2,param_3,param_4,*puVar2);
  return;
}

/* _glClearIndex @ 0x92f2af04 (128 bytes) */
int _glClearIndex(param_1)
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
                    
                    
  (*(code *)puVar2[0xf])(param_1,*puVar2);
  return;
}

/* _glClearStencil @ 0x92f2af84 (124 bytes) */
int _glClearStencil(param_1)
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
                    
                    
  (*(code *)puVar2[0x10])(*puVar2,param_1);
  return;
}

/* _glClipPlane @ 0x92f2b000 (132 bytes) */
int _glClipPlane(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x11])(*puVar2,param_1,param_2);
  return;
}

/* _glColor3b @ 0x92f2b084 (140 bytes) */
int _glColor3b(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x12])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glColor3bv @ 0x92f2b110 (124 bytes) */
int _glColor3bv(param_1)
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
                    
                    
  (*(code *)puVar2[0x13])(*puVar2,param_1);
  return;
}

/* _glColor3d @ 0x92f2b18c (160 bytes) */
int _glColor3d(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x14])(param_1,param_2,param_3,*puVar2);
  return;
}

/* _glColor3dv @ 0x92f2b22c (124 bytes) */
int _glColor3dv(param_1)
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
                    
                    
  (*(code *)puVar2[0x15])(*puVar2,param_1);
  return;
}

/* _glColor3f @ 0x92f2b2a8 (160 bytes) */
int _glColor3f(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x16])(param_1,param_2,param_3,*puVar2);
  return;
}

/* _glColor3fv @ 0x92f2b348 (124 bytes) */
int _glColor3fv(param_1)
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
                    
                    
  (*(code *)puVar2[0x17])(*puVar2,param_1);
  return;
}

/* _glColor3i @ 0x92f2b3c4 (140 bytes) */
int _glColor3i(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x18])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glColor3iv @ 0x92f2b450 (124 bytes) */
int _glColor3iv(param_1)
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
                    
                    
  (*(code *)puVar2[0x19])(*puVar2,param_1);
  return;
}

/* _glColor3s @ 0x92f2b4cc (140 bytes) */
int _glColor3s(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x1a])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glColor3sv @ 0x92f2b558 (124 bytes) */
int _glColor3sv(param_1)
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
                    
                    
  (*(code *)puVar2[0x1b])(*puVar2,param_1);
  return;
}

/* _glColor3ub @ 0x92f2b5d4 (140 bytes) */
int _glColor3ub(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x1c])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glColor3ubv @ 0x92f2b660 (124 bytes) */
int _glColor3ubv(param_1)
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
                    
                    
  (*(code *)puVar2[0x1d])(*puVar2,param_1);
  return;
}

/* _glColor3ui @ 0x92f2b6dc (140 bytes) */
int _glColor3ui(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x1e])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glColor3uiv @ 0x92f2b768 (124 bytes) */
int _glColor3uiv(param_1)
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
                    
                    
  (*(code *)puVar2[0x1f])(*puVar2,param_1);
  return;
}

