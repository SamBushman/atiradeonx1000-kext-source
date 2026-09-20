#include "decls.h"

/* _glGetFramebufferAttachmentParameterivEXT @ 0x92f43fc8 (148 bytes) */
int _glGetFramebufferAttachmentParameterivEXT(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x2a9])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glGenerateMipmapEXT @ 0x92f4405c (124 bytes) */
int _glGenerateMipmapEXT(param_1)
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
                    
                    
  (*(code *)puVar2[0x2aa])(*puVar2,param_1);
  return;
}

/* _glEnableVertexAttribAPPLE @ 0x92f440d8 (132 bytes) */
int _glEnableVertexAttribAPPLE(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x216])(*puVar2,param_1,param_2);
  return;
}

/* _glDisableVertexAttribAPPLE @ 0x92f4415c (132 bytes) */
int _glDisableVertexAttribAPPLE(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x217])(*puVar2,param_1,param_2);
  return;
}

/* _glIsVertexAttribEnabledAPPLE @ 0x92f441e0 (136 bytes) */
int _glIsVertexAttribEnabledAPPLE(param_1, param_2)
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
  (*(code *)puVar2[0x218])(*puVar2,param_1,param_2);
  return;
}

/* _glMapVertexAttrib1dAPPLE @ 0x92f44268 (192 bytes) */
int _glMapVertexAttrib1dAPPLE(param_1, param_2, param_3, param_4)
  undefined8 param_1;
  undefined8 param_2;
  undefined4 param_3;
  undefined4 param_4;
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
  (*(code *)puVar2[0x219])(param_1,param_2,*puVar2,param_3,param_4);
  return;
}

/* _glMapVertexAttrib1fAPPLE @ 0x92f44328 (188 bytes) */
int _glMapVertexAttrib1fAPPLE(param_1, param_2, param_3, param_4)
  undefined8 param_1;
  undefined8 param_2;
  undefined4 param_3;
  undefined4 param_4;
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
                    
                    
  (*(code *)puVar2[0x21a])(param_1,param_2,*puVar2,param_3,param_4);
  return;
}

/* _glMapVertexAttrib2dAPPLE @ 0x92f443e4 (200 bytes) */
int _glMapVertexAttrib2dAPPLE(param_1, param_2, param_3, param_4)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 extraout_r4;
  undefined4 *puVar3;
  undefined8 extraout_f1;
  
  uVar2 = FUN_92f27fc8();
  puVar1 = PTR__gll_cc_a2f27020;
  puVar3 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar3[0x2ac] ^ (uint)&STACKARG(0xffffff60)) & 0xfffff000) != 0) {
    puVar3 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar3;
    puVar3[0x2ac] = &STACKARG(0xffffff60);
  }
  (*(code *)puVar3[0x21b])(extraout_f1,param_2,param_3,param_4,*puVar3,uVar2,extraout_r4);
  return;
}

/* _glMapVertexAttrib2fAPPLE @ 0x92f444ac (200 bytes) */
int _glMapVertexAttrib2fAPPLE(param_1, param_2, param_3, param_4)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
{
  undefined *puVar1;
  undefined4 uVar2;
  undefined4 extraout_r4;
  undefined4 *puVar3;
  undefined8 extraout_f1;
  
  uVar2 = FUN_92f27fc8();
  puVar1 = PTR__gll_cc_a2f27020;
  puVar3 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar3[0x2ac] ^ (uint)&STACKARG(0xffffff70)) & 0xfffff000) != 0) {
    puVar3 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar3;
    puVar3[0x2ac] = &STACKARG(0xffffff70);
  }
  (*(code *)puVar3[0x21c])(extraout_f1,param_2,param_3,param_4,*puVar3,uVar2,extraout_r4);
  return;
}

/* _glGetTexParameterPointervAPPLE @ 0x92f44574 (140 bytes) */
int _glGetTexParameterPointervAPPLE(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x1ca])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGenFencesAPPLE @ 0x92f44600 (132 bytes) */
int _glGenFencesAPPLE(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x1d0])(*puVar2,param_1,param_2);
  return;
}

/* _glDeleteFencesAPPLE @ 0x92f44684 (132 bytes) */
int _glDeleteFencesAPPLE(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x1d1])(*puVar2,param_1,param_2);
  return;
}

/* _glSetFenceAPPLE @ 0x92f44708 (124 bytes) */
int _glSetFenceAPPLE(param_1)
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
                    
                    
  (*(code *)puVar2[0x1d2])(*puVar2,param_1);
  return;
}

/* _glIsFenceAPPLE @ 0x92f44784 (128 bytes) */
int _glIsFenceAPPLE(param_1)
  undefined4 param_1;
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
  (*(code *)puVar2[0x1d3])(*puVar2,param_1);
  return;
}

/* _glTestFenceAPPLE @ 0x92f44804 (128 bytes) */
int _glTestFenceAPPLE(param_1)
  undefined4 param_1;
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
  (*(code *)puVar2[0x1d4])(*puVar2,param_1);
  return;
}

/* _glFinishFenceAPPLE @ 0x92f44884 (124 bytes) */
int _glFinishFenceAPPLE(param_1)
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
                    
                    
  (*(code *)puVar2[0x1d5])(*puVar2,param_1);
  return;
}

/* _glTestObjectAPPLE @ 0x92f44900 (136 bytes) */
int _glTestObjectAPPLE(param_1, param_2)
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
  (*(code *)puVar2[0x1d6])(*puVar2,param_1,param_2);
  return;
}

/* _glFinishObjectAPPLE @ 0x92f44988 (132 bytes) */
int _glFinishObjectAPPLE(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x1d7])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexArrayRangeAPPLE @ 0x92f44a0c (132 bytes) */
int _glVertexArrayRangeAPPLE(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x194])(*puVar2,param_1,param_2);
  return;
}

/* _glFlushVertexArrayRangeAPPLE @ 0x92f44a90 (132 bytes) */
int _glFlushVertexArrayRangeAPPLE(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x195])(*puVar2,param_1,param_2);
  return;
}

/* _glVertexArrayParameteriAPPLE @ 0x92f44b14 (132 bytes) */
int _glVertexArrayParameteriAPPLE(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x226])(*puVar2,param_1,param_2);
  return;
}

/* _glBindVertexArrayAPPLE @ 0x92f44b98 (124 bytes) */
int _glBindVertexArrayAPPLE(param_1)
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
                    
                    
  (*(code *)puVar2[0x227])(*puVar2,param_1);
  return;
}

/* _glDeleteVertexArraysAPPLE @ 0x92f44c14 (132 bytes) */
int _glDeleteVertexArraysAPPLE(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x228])(*puVar2,param_1,param_2);
  return;
}

/* _glGenVertexArraysAPPLE @ 0x92f44c98 (132 bytes) */
int _glGenVertexArraysAPPLE(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x229])(*puVar2,param_1,param_2);
  return;
}

/* _glIsVertexArrayAPPLE @ 0x92f44d1c (128 bytes) */
int _glIsVertexArrayAPPLE(param_1)
  undefined4 param_1;
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
  (*(code *)puVar2[0x22a])(*puVar2,param_1);
  return;
}

/* _glElementPointerAPPLE @ 0x92f44d9c (132 bytes) */
int _glElementPointerAPPLE(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x22b])(*puVar2,param_1,param_2);
  return;
}

/* _glDrawElementArrayAPPLE @ 0x92f44e20 (140 bytes) */
int _glDrawElementArrayAPPLE(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x22c])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glDrawRangeElementArrayAPPLE @ 0x92f44eac (156 bytes) */
int _glDrawRangeElementArrayAPPLE(param_1, param_2, param_3, param_4, param_5)
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
                    
                    
  (*(code *)puVar2[0x22d])(*puVar2,param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glMultiDrawElementArrayAPPLE @ 0x92f44f48 (148 bytes) */
int _glMultiDrawElementArrayAPPLE(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x298])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glMultiDrawRangeElementArrayAPPLE @ 0x92f44fdc (164 bytes) */
int _glMultiDrawRangeElementArrayAPPLE(param_1, param_2, param_3, param_4, param_5, param_6)
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
                    
                    
  (*(code *)puVar2[0x299])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

/* _glFlushRenderAPPLE @ 0x92f45080 (112 bytes) */
int _glFlushRenderAPPLE()
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
                    
                    
  (*(code *)puVar2[0x24d])(*puVar2);
  return;
}

/* _glFinishRenderAPPLE @ 0x92f450f0 (112 bytes) */
int _glFinishRenderAPPLE()
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
                    
                    
  (*(code *)puVar2[0x24e])(*puVar2);
  return;
}

/* _glSwapAPPLE @ 0x92f45160 (112 bytes) */
int _glSwapAPPLE()
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
                    
                    
  (*(code *)puVar2[0x24f])(*puVar2);
  return;
}

/* _glBlendEquationSeparateATI @ 0x92f451d0 (132 bytes) */
int _glBlendEquationSeparateATI(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x1cb])(*puVar2,param_1,param_2);
  return;
}

/* _glStencilOpSeparateATI @ 0x92f45254 (148 bytes) */
int _glStencilOpSeparateATI(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x24b])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glStencilFuncSeparateATI @ 0x92f452e8 (148 bytes) */
int _glStencilFuncSeparateATI(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x24c])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glPNTrianglesiATI @ 0x92f4537c (132 bytes) */
int _glPNTrianglesiATI(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x1ce])(*puVar2,param_1,param_2);
  return;
}

/* _glPNTrianglesfATI @ 0x92f45400 (140 bytes) */
int _glPNTrianglesfATI(param_1, param_2)
  undefined8 param_1;
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
                    
                    
  (*(code *)puVar2[0x1cf])(param_1,*puVar2,param_2);
  return;
}

/* _glPNTrianglesiATIX @ 0x92f4548c (132 bytes) */
int _glPNTrianglesiATIX(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x1ce])(*puVar2,param_1,param_2);
  return;
}

/* _glPNTrianglesfATIX @ 0x92f45510 (140 bytes) */
int _glPNTrianglesfATIX(param_1, param_2)
  undefined8 param_1;
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
                    
                    
  (*(code *)puVar2[0x1cf])(param_1,*puVar2,param_2);
  return;
}

/* _glPointParameteriNV @ 0x92f4559c (132 bytes) */
int _glPointParameteriNV(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x21f])(*puVar2,param_1,param_2);
  return;
}

/* _glPointParameterivNV @ 0x92f45620 (132 bytes) */
int _glPointParameterivNV(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x220])(*puVar2,param_1,param_2);
  return;
}

/* _glCombinerParameterfvNV @ 0x92f456a4 (132 bytes) */
int _glCombinerParameterfvNV(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x1ba])(*puVar2,param_1,param_2);
  return;
}

/* _glCombinerParameterfNV @ 0x92f45728 (140 bytes) */
int _glCombinerParameterfNV(param_1, param_2)
  undefined8 param_1;
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
                    
                    
  (*(code *)puVar2[0x1bb])(param_1,*puVar2,param_2);
  return;
}

/* _glCombinerParameterivNV @ 0x92f457b4 (132 bytes) */
int _glCombinerParameterivNV(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x1bc])(*puVar2,param_1,param_2);
  return;
}

/* _glCombinerParameteriNV @ 0x92f45838 (132 bytes) */
int _glCombinerParameteriNV(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x1bd])(*puVar2,param_1,param_2);
  return;
}

/* _glCombinerInputNV @ 0x92f458bc (164 bytes) */
int _glCombinerInputNV(param_1, param_2, param_3, param_4, param_5, param_6)
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
                    
                    
  (*(code *)puVar2[0x1be])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}

/* _glCombinerOutputNV @ 0x92f45960 (200 bytes) */
int _glCombinerOutputNV(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff70)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff70);
  }
  (*(code *)puVar2[0x1bf])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glFinalCombinerInputNV @ 0x92f45a28 (148 bytes) */
int _glFinalCombinerInputNV(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x1c0])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glGetCombinerInputParameterfvNV @ 0x92f45abc (156 bytes) */
int _glGetCombinerInputParameterfvNV(param_1, param_2, param_3, param_4, param_5)
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
                    
                    
  (*(code *)puVar2[0x1c1])(*puVar2,param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glGetCombinerInputParameterivNV @ 0x92f45b58 (156 bytes) */
int _glGetCombinerInputParameterivNV(param_1, param_2, param_3, param_4, param_5)
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
                    
                    
  (*(code *)puVar2[0x1c2])(*puVar2,param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glGetCombinerOutputParameterfvNV @ 0x92f45bf4 (148 bytes) */
int _glGetCombinerOutputParameterfvNV(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x1c3])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glGetCombinerOutputParameterivNV @ 0x92f45c88 (148 bytes) */
int _glGetCombinerOutputParameterivNV(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x1c4])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glGetFinalCombinerInputParameterfvNV @ 0x92f45d1c (140 bytes) */
int _glGetFinalCombinerInputParameterfvNV(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x1c5])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetFinalCombinerInputParameterivNV @ 0x92f45da8 (140 bytes) */
int _glGetFinalCombinerInputParameterivNV(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x1c6])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glCombinerStageParameterfvNV @ 0x92f45e34 (140 bytes) */
int _glCombinerStageParameterfvNV(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x1c7])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetCombinerStageParameterfvNV @ 0x92f45ec0 (140 bytes) */
int _glGetCombinerStageParameterfvNV(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x1c8])(*puVar2,param_1,param_2,param_3);
  return;
}

