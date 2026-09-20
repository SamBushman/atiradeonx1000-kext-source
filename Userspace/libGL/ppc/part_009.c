#include "decls.h"

/* _glDeleteShader @ 0x92f39bb0 (124 bytes) */
int _glDeleteShader(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x250])(*puVar2,param_1);
  return;
}

/* _glDetachShader @ 0x92f39c2c (132 bytes) */
int _glDetachShader(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x252])(*puVar2,param_1,param_2);
  return;
}

/* _glCreateShader @ 0x92f39cb0 (124 bytes) */
int _glCreateShader(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x253])(*puVar2,param_1);
  return;
}

/* _glShaderSource @ 0x92f39d2c (148 bytes) */
int _glShaderSource(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x254])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glCompileShader @ 0x92f39dc0 (124 bytes) */
int _glCompileShader(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x255])(*puVar2,param_1);
  return;
}

/* _glCreateProgram @ 0x92f39e3c (112 bytes) */
int _glCreateProgram()
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
                    
                    
  (*(code *)puVar2[0x256])(*puVar2);
  return;
}

/* _glAttachShader @ 0x92f39eac (132 bytes) */
int _glAttachShader(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[599])(*puVar2,param_1,param_2);
  return;
}

/* _glLinkProgram @ 0x92f39f30 (124 bytes) */
int _glLinkProgram(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[600])(*puVar2,param_1);
  return;
}

/* _glUseProgram @ 0x92f39fac (124 bytes) */
int _glUseProgram(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x259])(*puVar2,param_1);
  return;
}

/* _glDeleteProgram @ 0x92f3a028 (124 bytes) */
int _glDeleteProgram(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x250])(*puVar2,param_1);
  return;
}

/* _glValidateProgram @ 0x92f3a0a4 (124 bytes) */
int _glValidateProgram(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x25a])(*puVar2,param_1);
  return;
}

/* _glUniform1f @ 0x92f3a120 (140 bytes) */
void _glUniform1f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
                    
                    
  (*(code *)puVar2[0x25b])(fparam_1,*puVar2,param_1);
  return;
}

/* _glUniform2f @ 0x92f3a1ac (156 bytes) */
void _glUniform2f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
                    
                    
  (*(code *)puVar2[0x25c])(fparam_1,fparam_2,*puVar2,param_1);
  return;
}

/* _glUniform3f @ 0x92f3a248 (172 bytes) */
void _glUniform3f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
                    
                    
  (*(code *)puVar2[0x25d])(fparam_1,fparam_2,fparam_3,*puVar2,param_1);
  return;
}

/* _glUniform4f @ 0x92f3a2f4 (172 bytes) */
void _glUniform4f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
                    
                    
  (*(code *)puVar2[0x25e])(fparam_1,fparam_2,fparam_3,fparam_4,*puVar2,param_1);
  return;
}

/* _glUniform1i @ 0x92f3a3a0 (132 bytes) */
int _glUniform1i(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x25f])(*puVar2,param_1,param_2);
  return;
}

/* _glUniform2i @ 0x92f3a424 (140 bytes) */
int _glUniform2i(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x260])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glUniform3i @ 0x92f3a4b0 (148 bytes) */
int _glUniform3i(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x261])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glUniform4i @ 0x92f3a544 (156 bytes) */
int _glUniform4i(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x262])(*puVar2,param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glUniform1fv @ 0x92f3a5e0 (140 bytes) */
int _glUniform1fv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x263])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glUniform2fv @ 0x92f3a66c (140 bytes) */
int _glUniform2fv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x264])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glUniform3fv @ 0x92f3a6f8 (140 bytes) */
int _glUniform3fv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x265])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glUniform4fv @ 0x92f3a784 (140 bytes) */
int _glUniform4fv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x266])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glUniform1iv @ 0x92f3a810 (140 bytes) */
int _glUniform1iv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x267])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glUniform2iv @ 0x92f3a89c (140 bytes) */
int _glUniform2iv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x268])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glUniform3iv @ 0x92f3a928 (140 bytes) */
int _glUniform3iv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x269])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glUniform4iv @ 0x92f3a9b4 (140 bytes) */
int _glUniform4iv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x26a])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glUniformMatrix2fv @ 0x92f3aa40 (148 bytes) */
int _glUniformMatrix2fv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x26b])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glUniformMatrix3fv @ 0x92f3aad4 (148 bytes) */
int _glUniformMatrix3fv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x26c])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glUniformMatrix4fv @ 0x92f3ab68 (148 bytes) */
int _glUniformMatrix4fv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x26d])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glIsShader @ 0x92f3abfc (128 bytes) */
int _glIsShader(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
  (*(code *)puVar2[0x290])(*puVar2,param_1);
  return;
}

/* _glIsProgram @ 0x92f3ac7c (128 bytes) */
int _glIsProgram(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
  (*(code *)puVar2[0x291])(*puVar2,param_1);
  return;
}

/* _glGetShaderiv @ 0x92f3acfc (140 bytes) */
int _glGetShaderiv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x292])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetProgramiv @ 0x92f3ad88 (140 bytes) */
int _glGetProgramiv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x293])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetAttachedShaders @ 0x92f3ae14 (148 bytes) */
int _glGetAttachedShaders(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x271])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glGetShaderInfoLog @ 0x92f3aea8 (148 bytes) */
int _glGetShaderInfoLog(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x294])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glGetProgramInfoLog @ 0x92f3af3c (148 bytes) */
int _glGetProgramInfoLog(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x295])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glGetUniformLocation @ 0x92f3afd0 (132 bytes) */
int _glGetUniformLocation(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x272])(*puVar2,param_1,param_2);
  return;
}

/* _glGetActiveUniform @ 0x92f3b054 (172 bytes) */
int _glGetActiveUniform(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x273])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glGetUniformfv @ 0x92f3b100 (140 bytes) */
int _glGetUniformfv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x274])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetUniformiv @ 0x92f3b18c (140 bytes) */
int _glGetUniformiv(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x275])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetShaderSource @ 0x92f3b218 (148 bytes) */
int _glGetShaderSource(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x276])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glBindAttribLocation @ 0x92f3b2ac (140 bytes) */
int _glBindAttribLocation(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x277])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetActiveAttrib @ 0x92f3b338 (172 bytes) */
int _glGetActiveAttrib(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x278])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glGetAttribLocation @ 0x92f3b3e4 (132 bytes) */
int _glGetAttribLocation(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x279])(*puVar2,param_1,param_2);
  return;
}

/* _glStencilFuncSeparate @ 0x92f3b468 (148 bytes) */
int _glStencilFuncSeparate(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x296])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glStencilOpSeparate @ 0x92f3b4fc (148 bytes) */
int _glStencilOpSeparate(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x24b])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glStencilMaskSeparate @ 0x92f3b590 (132 bytes) */
int _glStencilMaskSeparate(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x297])(*puVar2,param_1,param_2);
  return;
}

/* _glBlendEquationSeparate @ 0x92f3b614 (132 bytes) */
int _glBlendEquationSeparate(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x1cb])(*puVar2,param_1,param_2);
  return;
}

/* _glBindProgramARB @ 0x92f3b698 (132 bytes) */
int _glBindProgramARB(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x1d8])(*puVar2,param_1,param_2);
  return;
}

/* _glDeleteProgramsARB @ 0x92f3b71c (132 bytes) */
int _glDeleteProgramsARB(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x1d9])(*puVar2,param_1,param_2);
  return;
}

/* _glGenProgramsARB @ 0x92f3b7a0 (132 bytes) */
int _glGenProgramsARB(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x1da])(*puVar2,param_1,param_2);
  return;
}

/* _glIsProgramARB @ 0x92f3b824 (128 bytes) */
int _glIsProgramARB(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
  (*(code *)puVar2[0x1db])(*puVar2,param_1);
  return;
}

/* _glVertexAttrib1sARB @ 0x92f3b8a4 (132 bytes) */
int _glVertexAttrib1sARB(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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

/* _glVertexAttrib1fARB @ 0x92f3b928 (140 bytes) */
void _glVertexAttrib1fARB
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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

/* _glVertexAttrib1dARB @ 0x92f3b9b4 (140 bytes) */
void _glVertexAttrib1dARB
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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

/* _glVertexAttrib2sARB @ 0x92f3ba40 (140 bytes) */
int _glVertexAttrib2sARB(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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

/* _glVertexAttrib2fARB @ 0x92f3bacc (156 bytes) */
void _glVertexAttrib2fARB
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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

/* _glVertexAttrib2dARB @ 0x92f3bb68 (156 bytes) */
void _glVertexAttrib2dARB
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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

/* _glVertexAttrib3sARB @ 0x92f3bc04 (148 bytes) */
int _glVertexAttrib3sARB(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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

