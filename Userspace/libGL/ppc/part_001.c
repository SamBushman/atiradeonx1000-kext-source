#include "decls.h"

/* _glPopAttrib @ 0x92f2984c (112 bytes) */
int _glPopAttrib()
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
                    
                    
  (*(code *)puVar2[0xcc])(*puVar2);
  return;
}

/* _glTexEnvf @ 0x92f298bc (148 bytes) */
void _glTexEnvf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1)
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
                    
                    
  (*(code *)puVar2[0x123])(fparam_1,*puVar2,param_1,param_2);
  return;
}

/* _glAlphaFunc @ 0x92f29950 (140 bytes) */
void _glAlphaFunc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1)
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
                    
                    
  (*(code *)puVar2[2])(fparam_1,*puVar2,param_1);
  return;
}

/* _glEnableClientState @ 0x92f299dc (124 bytes) */
int _glEnableClientState(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x4a])(*puVar2,param_1);
  return;
}

/* _glGetError @ 0x92f29a58 (112 bytes) */
int _glGetError()
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
                    
                    
  (*(code *)puVar2[0x67])(*puVar2);
  return;
}

/* _glFlush @ 0x92f29ac8 (112 bytes) */
int _glFlush()
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
                    
                    
  (*(code *)puVar2[0x5b])(*puVar2);
  return;
}

/* _glScissor @ 0x92f29b38 (148 bytes) */
int _glScissor(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0xfc])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glGetDoublev @ 0x92f29bcc (132 bytes) */
int _glGetDoublev(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x66])(*puVar2,param_1,param_2);
  return;
}

/* _glRectd @ 0x92f29c50 (140 bytes) */
void _glRectd(double fparam_1,double fparam_2,double fparam_3,double fparam_4)
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
  (*(code *)puVar2[0xef])(fparam_1,fparam_2,fparam_3,fparam_4,*puVar2);
  return;
}

/* _glColorPointer @ 0x92f29cdc (148 bytes) */
int _glColorPointer(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x34])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glVertexPointer @ 0x92f29d70 (148 bytes) */
int _glVertexPointer(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x14f])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glTexCoordPointer @ 0x92f29e04 (148 bytes) */
int _glTexCoordPointer(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x122])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glDrawArrays @ 0x92f29e98 (140 bytes) */
int _glDrawArrays(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x42])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glPrioritizeTextures @ 0x92f29f24 (140 bytes) */
int _glPrioritizeTextures(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0xd0])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glTexImage2D @ 0x92f29fb0 (192 bytes) */
int _glTexImage2D(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
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
  (*(code *)puVar2[0x12e])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glFrustum @ 0x92f2a070 (156 bytes) */
void _glFrustum(double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6)
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar1 = PTR__gll_cc_a2f27020;
  puVar2 = *(undefined4 **)PTR__gll_cc_a2f27020;
  if (((puVar2[0x2ac] ^ (uint)&STACKARG(0xffffff60)) & 0xfffff000) != 0) {
    puVar2 = _pthread_getspecific(*(pthread_key_t *)PTR__gll_pkey_a2f2701c);
    *(undefined4 **)puVar1 = puVar2;
    puVar2[0x2ac] = &STACKARG(0xffffff60);
  }
  (*(code *)puVar2[0x61])(fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,*puVar2);
  FUN_92f27b4c();
  return;
}

/* _glLoadMatrixf @ 0x92f2a10c (124 bytes) */
int _glLoadMatrixf(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0xa0])(*puVar2,param_1);
  return;
}

/* _glPassThrough @ 0x92f2a188 (128 bytes) */
void _glPassThrough(double fparam_1)
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
                    
                    
  (*(code *)puVar2[0xbf])(fparam_1,*puVar2);
  return;
}

/* _glActiveTextureARB @ 0x92f2a208 (124 bytes) */
int _glActiveTextureARB(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x157])(*puVar2,param_1);
  return;
}

/* _glVertex2f @ 0x92f2a284 (144 bytes) */
void _glVertex2f(double fparam_1,double fparam_2)
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
                    
                    
  (*(code *)puVar2[0x139])(fparam_1,fparam_2,*puVar2);
  return;
}

/* _glMultiTexCoord2f @ 0x92f2a314 (156 bytes) */
void _glMultiTexCoord2f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2)
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
                    
                    
  (*(code *)puVar2[0x162])(fparam_1,fparam_2,*puVar2,param_1);
  return;
}

/* _glDeleteTextures @ 0x92f2a3b0 (132 bytes) */
int _glDeleteTextures(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x3c])(*puVar2,param_1,param_2);
  return;
}

/* _glFeedbackBuffer @ 0x92f2a434 (140 bytes) */
int _glFeedbackBuffer(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x59])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glRenderMode @ 0x92f2a4c0 (124 bytes) */
int _glRenderMode(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0xf7])(*puVar2,param_1);
  return;
}

/* _glFogi @ 0x92f2a53c (132 bytes) */
int _glFogi(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x5e])(*puVar2,param_1,param_2);
  return;
}

/* _glFogfv @ 0x92f2a5c0 (132 bytes) */
int _glFogfv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x5d])(*puVar2,param_1,param_2);
  return;
}

/* _glFogf @ 0x92f2a644 (140 bytes) */
void _glFogf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1)
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
                    
                    
  (*(code *)puVar2[0x5c])(fparam_1,*puVar2,param_1);
  return;
}

/* _glFrontFace @ 0x92f2a6d0 (124 bytes) */
int _glFrontFace(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x60])(*puVar2,param_1);
  return;
}

/* _glTexParameterf @ 0x92f2a74c (148 bytes) */
void _glTexParameterf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1)
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
                    
                    
  (*(code *)puVar2[0x12f])(fparam_1,*puVar2,param_1,param_2);
  return;
}

/* _glGetTexLevelParameteriv @ 0x92f2a7e0 (148 bytes) */
int _glGetTexLevelParameteriv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x7e])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glGetFloatv @ 0x92f2a874 (132 bytes) */
int _glGetFloatv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x68])(*puVar2,param_1,param_2);
  return;
}

/* _glTexSubImage2D @ 0x92f2a8f8 (192 bytes) */
int _glTexSubImage2D(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
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
  (*(code *)puVar2[0x134])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glTexCoord3f @ 0x92f2a9b8 (160 bytes) */
void _glTexCoord3f(double fparam_1,double fparam_2,double fparam_3)
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
                    
                    
  (*(code *)puVar2[0x114])(fparam_1,fparam_2,fparam_3,*puVar2);
  return;
}

/* _glTextureRangeAPPLE @ 0x92f2aa58 (140 bytes) */
int _glTextureRangeAPPLE(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
  code *local_28 [9];
  
  ((int (*)())__dyld_func_lookup)("__dyld_call_module_initializers_for_dylib",local_28);
  if (local_28[0] != (code *)0x0) {
    (*local_28[0])(PTR___mh_dylib_header_a2f27018);
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
void _glAccum(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1)
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
                    
                    
  (*(code *)puVar2[1])(fparam_1,*puVar2,param_1);
  return;
}

/* _glAreTexturesResident @ 0x92f2ac10 (144 bytes) */
int _glAreTexturesResident(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
  (*(code *)puVar2[3])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glArrayElement @ 0x92f2aca0 (124 bytes) */
int _glArrayElement(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[4])(*puVar2,param_1);
  return;
}

/* _glBitmap @ 0x92f2ad1c (188 bytes) */
void _glBitmap(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
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
                    
                    
  (*(code *)puVar2[7])(fparam_1,fparam_2,fparam_3,fparam_4,*puVar2,param_1,param_2);
  return;
}

/* _glCallLists @ 0x92f2add8 (140 bytes) */
int _glCallLists(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[10])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glClearAccum @ 0x92f2ae64 (160 bytes) */
void _glClearAccum(double fparam_1,double fparam_2,double fparam_3,double fparam_4)
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
                    
                    
  (*(code *)puVar2[0xc])(fparam_1,fparam_2,fparam_3,fparam_4,*puVar2);
  return;
}

/* _glClearIndex @ 0x92f2af04 (128 bytes) */
void _glClearIndex(double fparam_1)
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
                    
                    
  (*(code *)puVar2[0xf])(fparam_1,*puVar2);
  return;
}

/* _glClearStencil @ 0x92f2af84 (124 bytes) */
int _glClearStencil(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x10])(*puVar2,param_1);
  return;
}

/* _glClipPlane @ 0x92f2b000 (132 bytes) */
int _glClipPlane(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x11])(*puVar2,param_1,param_2);
  return;
}

/* _glColor3b @ 0x92f2b084 (140 bytes) */
int _glColor3b(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x12])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glColor3bv @ 0x92f2b110 (124 bytes) */
int _glColor3bv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x13])(*puVar2,param_1);
  return;
}

/* _glColor3d @ 0x92f2b18c (160 bytes) */
void _glColor3d(double fparam_1,double fparam_2,double fparam_3)
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
                    
                    
  (*(code *)puVar2[0x14])(fparam_1,fparam_2,fparam_3,*puVar2);
  return;
}

/* _glColor3dv @ 0x92f2b22c (124 bytes) */
int _glColor3dv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x15])(*puVar2,param_1);
  return;
}

/* _glColor3f @ 0x92f2b2a8 (160 bytes) */
void _glColor3f(double fparam_1,double fparam_2,double fparam_3)
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
                    
                    
  (*(code *)puVar2[0x16])(fparam_1,fparam_2,fparam_3,*puVar2);
  return;
}

/* _glColor3fv @ 0x92f2b348 (124 bytes) */
int _glColor3fv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x17])(*puVar2,param_1);
  return;
}

/* _glColor3i @ 0x92f2b3c4 (140 bytes) */
int _glColor3i(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x18])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glColor3iv @ 0x92f2b450 (124 bytes) */
int _glColor3iv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x19])(*puVar2,param_1);
  return;
}

/* _glColor3s @ 0x92f2b4cc (140 bytes) */
int _glColor3s(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x1a])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glColor3sv @ 0x92f2b558 (124 bytes) */
int _glColor3sv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x1b])(*puVar2,param_1);
  return;
}

/* _glColor3ub @ 0x92f2b5d4 (140 bytes) */
int _glColor3ub(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x1c])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glColor3ubv @ 0x92f2b660 (124 bytes) */
int _glColor3ubv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x1d])(*puVar2,param_1);
  return;
}

/* _glColor3ui @ 0x92f2b6dc (140 bytes) */
int _glColor3ui(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x1e])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glColor3uiv @ 0x92f2b768 (124 bytes) */
int _glColor3uiv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x1f])(*puVar2,param_1);
  return;
}

