#include "decls.h"

/* _glWindowPos3iARB @ 0x92f3ff60 (140 bytes) */
int _glWindowPos3iARB(param_1, param_2, param_3)
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

/* _glWindowPos3ivARB @ 0x92f3ffec (124 bytes) */
int _glWindowPos3ivARB(param_1)
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

/* _glWindowPos3sARB @ 0x92f40068 (140 bytes) */
int _glWindowPos3sARB(param_1, param_2, param_3)
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

/* _glWindowPos3svARB @ 0x92f400f4 (124 bytes) */
int _glWindowPos3svARB(param_1)
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

/* _glGenQueriesARB @ 0x92f40170 (132 bytes) */
int _glGenQueriesARB(param_1, param_2)
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

/* _glDeleteQueriesARB @ 0x92f401f4 (132 bytes) */
int _glDeleteQueriesARB(param_1, param_2)
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

/* _glIsQueryARB @ 0x92f40278 (128 bytes) */
int _glIsQueryARB(param_1)
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

/* _glBeginQueryARB @ 0x92f402f8 (132 bytes) */
int _glBeginQueryARB(param_1, param_2)
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

/* _glEndQueryARB @ 0x92f4037c (124 bytes) */
int _glEndQueryARB(param_1)
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
                    
                    
  (*(code *)puVar2[0x27f])(*puVar2,param_1);
  return;
}

/* _glGetQueryivARB @ 0x92f403f8 (140 bytes) */
int _glGetQueryivARB(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x280])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetQueryObjectivARB @ 0x92f40484 (140 bytes) */
int _glGetQueryObjectivARB(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x281])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetQueryObjectuivARB @ 0x92f40510 (140 bytes) */
int _glGetQueryObjectuivARB(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x282])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glBindBufferARB @ 0x92f4059c (132 bytes) */
int _glBindBufferARB(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x283])(*puVar2,param_1,param_2);
  return;
}

/* _glDeleteBuffersARB @ 0x92f40620 (132 bytes) */
int _glDeleteBuffersARB(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x284])(*puVar2,param_1,param_2);
  return;
}

/* _glGenBuffersARB @ 0x92f406a4 (132 bytes) */
int _glGenBuffersARB(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x285])(*puVar2,param_1,param_2);
  return;
}

/* _glIsBufferARB @ 0x92f40728 (128 bytes) */
int _glIsBufferARB(param_1)
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
  (*(code *)puVar2[0x286])(*puVar2,param_1);
  return;
}

/* _glBufferDataARB @ 0x92f407a8 (148 bytes) */
int _glBufferDataARB(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x287])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glBufferSubDataARB @ 0x92f4083c (148 bytes) */
int _glBufferSubDataARB(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x288])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glGetBufferSubDataARB @ 0x92f408d0 (148 bytes) */
int _glGetBufferSubDataARB(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x289])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glMapBufferARB @ 0x92f40964 (132 bytes) */
int _glMapBufferARB(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x28a])(*puVar2,param_1,param_2);
  return;
}

/* _glUnmapBufferARB @ 0x92f409e8 (128 bytes) */
int _glUnmapBufferARB(param_1)
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
  (*(code *)puVar2[0x28b])(*puVar2,param_1);
  return;
}

/* _glGetBufferParameterivARB @ 0x92f40a68 (140 bytes) */
int _glGetBufferParameterivARB(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x28c])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetBufferPointervARB @ 0x92f40af4 (140 bytes) */
int _glGetBufferPointervARB(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x28d])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glDeleteObjectARB @ 0x92f40b80 (124 bytes) */
int _glDeleteObjectARB(param_1)
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
                    
                    
  (*(code *)puVar2[0x250])(*puVar2,param_1);
  return;
}

/* _glGetHandleARB @ 0x92f40bfc (124 bytes) */
int _glGetHandleARB(param_1)
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
                    
                    
  (*(code *)puVar2[0x251])(*puVar2,param_1);
  return;
}

/* _glDetachObjectARB @ 0x92f40c78 (132 bytes) */
int _glDetachObjectARB(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x252])(*puVar2,param_1,param_2);
  return;
}

/* _glCreateShaderObjectARB @ 0x92f40cfc (124 bytes) */
int _glCreateShaderObjectARB(param_1)
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
                    
                    
  (*(code *)puVar2[0x253])(*puVar2,param_1);
  return;
}

/* _glShaderSourceARB @ 0x92f40d78 (148 bytes) */
int _glShaderSourceARB(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x254])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glCompileShaderARB @ 0x92f40e0c (124 bytes) */
int _glCompileShaderARB(param_1)
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
                    
                    
  (*(code *)puVar2[0x255])(*puVar2,param_1);
  return;
}

/* _glCreateProgramObjectARB @ 0x92f40e88 (112 bytes) */
int _glCreateProgramObjectARB()
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
                    
                    
  (*(code *)puVar2[0x256])(*puVar2);
  return;
}

/* _glAttachObjectARB @ 0x92f40ef8 (132 bytes) */
int _glAttachObjectARB(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[599])(*puVar2,param_1,param_2);
  return;
}

/* _glLinkProgramARB @ 0x92f40f7c (124 bytes) */
int _glLinkProgramARB(param_1)
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
                    
                    
  (*(code *)puVar2[600])(*puVar2,param_1);
  return;
}

/* _glUseProgramObjectARB @ 0x92f40ff8 (124 bytes) */
int _glUseProgramObjectARB(param_1)
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
                    
                    
  (*(code *)puVar2[0x259])(*puVar2,param_1);
  return;
}

/* _glValidateProgramARB @ 0x92f41074 (124 bytes) */
int _glValidateProgramARB(param_1)
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
                    
                    
  (*(code *)puVar2[0x25a])(*puVar2,param_1);
  return;
}

/* _glUniform1fARB @ 0x92f410f0 (140 bytes) */
int _glUniform1fARB(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x25b])(param_1,*puVar2,param_2);
  return;
}

/* _glUniform2fARB @ 0x92f4117c (156 bytes) */
int _glUniform2fARB(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x25c])(param_1,param_2,*puVar2,param_3);
  return;
}

/* _glUniform3fARB @ 0x92f41218 (172 bytes) */
int _glUniform3fARB(param_1, param_2, param_3, param_4)
  undefined8 param_1;
  undefined8 param_2;
  undefined8 param_3;
  undefined8 param_4;
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
                    
                    
  (*(code *)puVar2[0x25d])(param_1,param_2,param_3,*puVar2,param_4);
  return;
}

/* _glUniform4fARB @ 0x92f412c4 (172 bytes) */
int _glUniform4fARB(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar3[0x25e])(uVar4,param_2,param_3,param_4,*puVar3,uVar2);
  return;
}

/* _glUniform1iARB @ 0x92f41370 (132 bytes) */
int _glUniform1iARB(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x25f])(*puVar2,param_1,param_2);
  return;
}

/* _glUniform2iARB @ 0x92f413f4 (140 bytes) */
int _glUniform2iARB(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x260])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glUniform3iARB @ 0x92f41480 (148 bytes) */
int _glUniform3iARB(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x261])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glUniform4iARB @ 0x92f41514 (156 bytes) */
int _glUniform4iARB(param_1, param_2, param_3, param_4, param_5)
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
                    
                    
  (*(code *)puVar2[0x262])(*puVar2,param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glUniform1fvARB @ 0x92f415b0 (140 bytes) */
int _glUniform1fvARB(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x263])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glUniform2fvARB @ 0x92f4163c (140 bytes) */
int _glUniform2fvARB(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x264])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glUniform3fvARB @ 0x92f416c8 (140 bytes) */
int _glUniform3fvARB(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x265])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glUniform4fvARB @ 0x92f41754 (140 bytes) */
int _glUniform4fvARB(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x266])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glUniform1ivARB @ 0x92f417e0 (140 bytes) */
int _glUniform1ivARB(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x267])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glUniform2ivARB @ 0x92f4186c (140 bytes) */
int _glUniform2ivARB(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x268])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glUniform3ivARB @ 0x92f418f8 (140 bytes) */
int _glUniform3ivARB(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x269])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glUniform4ivARB @ 0x92f41984 (140 bytes) */
int _glUniform4ivARB(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x26a])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glUniformMatrix2fvARB @ 0x92f41a10 (148 bytes) */
int _glUniformMatrix2fvARB(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x26b])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glUniformMatrix3fvARB @ 0x92f41aa4 (148 bytes) */
int _glUniformMatrix3fvARB(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x26c])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glUniformMatrix4fvARB @ 0x92f41b38 (148 bytes) */
int _glUniformMatrix4fvARB(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x26d])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glGetObjectParameterfvARB @ 0x92f41bcc (140 bytes) */
int _glGetObjectParameterfvARB(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x26e])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetObjectParameterivARB @ 0x92f41c58 (140 bytes) */
int _glGetObjectParameterivARB(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x26f])(*puVar2,param_1,param_2,param_3);
  return;
}

/* _glGetInfoLogARB @ 0x92f41ce4 (148 bytes) */
int _glGetInfoLogARB(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x270])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glGetAttachedObjectsARB @ 0x92f41d78 (148 bytes) */
int _glGetAttachedObjectsARB(param_1, param_2, param_3, param_4)
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
                    
                    
  (*(code *)puVar2[0x271])(*puVar2,param_1,param_2,param_3,param_4);
  return;
}

/* _glGetUniformLocationARB @ 0x92f41e0c (132 bytes) */
int _glGetUniformLocationARB(param_1, param_2)
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
                    
                    
  (*(code *)puVar2[0x272])(*puVar2,param_1,param_2);
  return;
}

/* _glGetActiveUniformARB @ 0x92f41e90 (172 bytes) */
int _glGetActiveUniformARB(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
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
                    
                    
  (*(code *)puVar2[0x273])(*puVar2,param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glGetUniformfvARB @ 0x92f41f3c (140 bytes) */
int _glGetUniformfvARB(param_1, param_2, param_3)
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
                    
                    
  (*(code *)puVar2[0x274])(*puVar2,param_1,param_2,param_3);
  return;
}

