#include "decls.h"

/* _LFSStreamChunkListCreate @ 0xd1854 (12 bytes) */
int _LFSStreamChunkListCreate()
{
  undefined4 uVar1;
  
  uVar1 = _calloc(0xc,1);
  return uVar1;
}

/* _LFSStreamChunkListCreateFromChunkList @ 0xd1860 (96 bytes) */
int _LFSStreamChunkListCreateFromChunkList(param_1)
  int *param_1;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = ((int (*)())_LFSStreamChunkListCreate)();
  for (iVar3 = *param_1; iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x4c)) {
    uVar2 = _LFSStreamChunkCreateFromChunk(iVar3);
    ((void (*)())_LFSStreamChunkListAddChunk)(uVar1,uVar2);
  }
  return uVar1;
}

/* _LFSStreamChunkListFree @ 0xd18c0 (80 bytes) */
void _LFSStreamChunkListFree(param_1)
  int *param_1;
{
  int iVar1;
  
  iVar1 = *param_1;
  while (iVar1 != 0) {
    ((void (*)())_LFSStreamChunkListRemoveChunk)(param_1,iVar1);
    iVar1 = *param_1;
  }
  _free(param_1);
  return;
}

/* _LFSStreamChunkListAddChunk @ 0xd1910 (64 bytes) */
void _LFSStreamChunkListAddChunk(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *param_1;
  if (*param_1 == 0) {
    iVar1 = param_2;
  }
  *param_1 = iVar1;
  if (param_1[1] != 0) {
    *(int *)(param_1[1] + 0x4c) = param_2;
    *(int *)(param_2 + 0x48) = param_1[1];
  }
  param_1[1] = param_2;
  param_1[2] = param_1[2] + 1;
  return;
}

/* _LFSStreamChunkListRemoveChunk @ 0xd1950 (120 bytes) */
void _LFSStreamChunkListRemoveChunk(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x48);
  if (iVar1 == 0) {
    *param_1 = *(undefined4 *)(param_2 + 0x4c);
    iVar1 = *(int *)(param_2 + 0x48);
  }
  else {
    *(undefined4 *)(iVar1 + 0x4c) = *(undefined4 *)(param_2 + 0x4c);
  }
  if (*(int *)(param_2 + 0x4c) == 0) {
    param_1[1] = iVar1;
  }
  else {
    *(int *)(*(int *)(param_2 + 0x4c) + 0x48) = iVar1;
  }
  _LFSStreamChunkFree(param_2);
  param_1[2] = param_1[2] + -1;
  return;
}

/* _LFSStreamChunkListGetStream @ 0xd19c8 (280 bytes) */
void _LFSStreamChunkListGetStream(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int *param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint local_30;
  undefined1 auStack_2c [12];
  
  iVar2 = 0;
  *param_3 = 0;
  for (iVar4 = *param_1; iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x4c)) {
    _LFSStreamChunkGetStream(iVar4,param_4,&local_30,0);
    *param_3 = *param_3 + local_30;
  }
  if ((param_2 != 0) && (iVar4 = *param_1, iVar4 != 0)) {
    iVar3 = 0;
    do {
      uVar1 = _LFSStreamChunkGetStream(iVar4,param_4,&local_30,0);
      iVar2 = iVar2 + 1;
      *(undefined4 *)(iVar3 + param_2) = uVar1;
      iVar3 = iVar3 + 4;
      if (1 < local_30) {
        local_30 = local_30 - 1;
        uVar5 = 0;
        if (local_30 != 0) {
          puVar6 = (undefined4 *)(iVar2 * 4 + param_2);
          do {
            uVar5 = uVar5 + 1;
            iVar2 = iVar2 + 1;
            uVar1 = _LFSStreamChunkGetStream(iVar4,param_4,auStack_2c,uVar5);
            iVar3 = iVar3 + 4;
            *puVar6 = uVar1;
            puVar6 = puVar6 + 1;
          } while (uVar5 < local_30);
        }
      }
      iVar4 = *(int *)(iVar4 + 0x4c);
    } while (iVar4 != 0);
  }
  return;
}

/* _LFSStreamChunkListCompare @ 0xd1b0c (132 bytes) */
int _LFSStreamChunkListCompare(param_1, param_2)
  int *param_1;
  int *param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_1;
  uVar1 = 1;
  iVar4 = *param_2;
  if (param_1[2] == param_2[2]) {
    for (; (iVar3 != 0 && (iVar4 != 0)); iVar4 = *(int *)(iVar4 + 0x4c)) {
      iVar2 = _LFSStreamChunkCompare(iVar3,iVar4);
      if (iVar2 != 0) {
        return 1;
      }
      iVar3 = *(int *)(iVar3 + 0x4c);
    }
    uVar1 = 0;
  }
  return uVar1;
}

/* _LFSStreamChunkListOutputDebugInfo @ 0xd1b90 (68 bytes) */
void _LFSStreamChunkListOutputDebugInfo(param_1)
  int *param_1;
{
  int iVar1;
  
  for (iVar1 = *param_1; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x4c)) {
    _LFSStreamChunkOutputDebugInfo(iVar1);
  }
  return;
}

/* _LFSStreamCreate @ 0xd1bd4 (104 bytes) */
int _LFSStreamCreate()
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)_calloc(0x18,1);
  uVar2 = ((int (*)())_LFSStreamChunkListCreate)();
  *puVar1 = uVar2;
  uVar2 = ((int (*)())_LFSStreamChunkListCreate)();
  puVar1[1] = uVar2;
  uVar2 = ((int (*)())_LFSStreamChunkListCreate)();
  puVar1[2] = uVar2;
  uVar2 = ((int (*)())_LFSStreamChunkListCreate)();
  puVar1[3] = uVar2;
  uVar2 = ((int (*)())_LFSStreamChunkListCreate)();
  puVar1[4] = uVar2;
  uVar2 = ((int (*)())_LFSStreamChunkListCreate)();
  puVar1[5] = uVar2;
  return puVar1;
}

/* _LFSStreamFree @ 0xd1c3c (92 bytes) */
void _LFSStreamFree(param_1)
  undefined4 *param_1;
{
  ((void (*)())_LFSStreamChunkListFree)(*param_1);
  ((void (*)())_LFSStreamChunkListFree)(param_1[1]);
  ((void (*)())_LFSStreamChunkListFree)(param_1[2]);
  ((void (*)())_LFSStreamChunkListFree)(param_1[3]);
  ((void (*)())_LFSStreamChunkListFree)(param_1[4]);
  ((void (*)())_LFSStreamChunkListFree)(param_1[5]);
  _free(param_1);
  return;
}

/* _LFSStreamAddConstantBinding @ 0xd1c98 (104 bytes) */
void _LFSStreamAddConstantBinding(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar2 = (undefined1 *)_LFSStreamChunkCreate();
  *puVar2 = 3;
  uVar1 = param_2[1];
  uVar3 = param_2[2];
  uVar4 = param_2[3];
  *(undefined4 *)(puVar2 + 4) = *param_2;
  *(undefined4 *)(puVar2 + 8) = uVar1;
  *(undefined4 *)(puVar2 + 0xc) = uVar3;
  *(undefined4 *)(puVar2 + 0x10) = uVar4;
  *(undefined4 *)(puVar2 + 0x14) = param_2[4];
  ((void (*)())_LFSStreamChunkListAddChunk)(*param_1,puVar2);
  return;
}

/* _LFSStreamAddPreliminaryPassRegisterInit @ 0xd1d00 (104 bytes) */
void _LFSStreamAddPreliminaryPassRegisterInit(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar2 = (undefined1 *)_LFSStreamChunkCreate();
  *puVar2 = 1;
  uVar1 = param_2[1];
  uVar3 = param_2[2];
  uVar4 = param_2[3];
  *(undefined4 *)(puVar2 + 4) = *param_2;
  *(undefined4 *)(puVar2 + 8) = uVar1;
  *(undefined4 *)(puVar2 + 0xc) = uVar3;
  *(undefined4 *)(puVar2 + 0x10) = uVar4;
  *(undefined4 *)(puVar2 + 0x14) = param_2[4];
  ((void (*)())_LFSStreamChunkListAddChunk)(*(undefined4 *)(param_1 + 4),puVar2);
  return;
}

/* _LFSStreamAddPreliminaryPassOperation @ 0xd1d68 (84 bytes) */
void _LFSStreamAddPreliminaryPassOperation(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)_LFSStreamChunkCreate();
  *puVar1 = 2;
  _memcpy(puVar1 + 4,param_2,0x44);
  ((void (*)())_LFSStreamChunkListAddChunk)(*(undefined4 *)(param_1 + 8),puVar1);
  return;
}

/* _LFSStreamAddOutputPassRegisterInit @ 0xd1dbc (104 bytes) */
void _LFSStreamAddOutputPassRegisterInit(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  puVar2 = (undefined1 *)_LFSStreamChunkCreate();
  *puVar2 = 1;
  uVar1 = param_2[1];
  uVar3 = param_2[2];
  uVar4 = param_2[3];
  *(undefined4 *)(puVar2 + 4) = *param_2;
  *(undefined4 *)(puVar2 + 8) = uVar1;
  *(undefined4 *)(puVar2 + 0xc) = uVar3;
  *(undefined4 *)(puVar2 + 0x10) = uVar4;
  *(undefined4 *)(puVar2 + 0x14) = param_2[4];
  ((void (*)())_LFSStreamChunkListAddChunk)(*(undefined4 *)(param_1 + 0xc),puVar2);
  return;
}

/* _LFSStreamAddOutputPassOperation @ 0xd1e24 (84 bytes) */
void _LFSStreamAddOutputPassOperation(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)_LFSStreamChunkCreate();
  *puVar1 = 2;
  _memcpy(puVar1 + 4,param_2,0x44);
  ((void (*)())_LFSStreamChunkListAddChunk)(*(undefined4 *)(param_1 + 0x10),puVar1);
  return;
}

/* _LFSStreamAddConstant @ 0xd1e78 (84 bytes) */
void _LFSStreamAddConstant(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)_LFSStreamChunkCreate();
  *puVar1 = 4;
  _memmove(puVar1 + 4,param_2,0x10);
  ((void (*)())_LFSStreamChunkListAddChunk)(*(undefined4 *)(param_1 + 0x14),puVar1);
  return;
}

/* _LFSStreamGetStream @ 0xd1ecc (628 bytes) */
void _LFSStreamGetStream(param_1, param_2, param_3)
  int *param_1;
  uint *param_2;
  int *param_3;
{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int local_30 [7];
  
  ((void (*)())_LFSStreamChunkListGetStream)(*param_1,0,local_30,param_1);
  iVar2 = local_30[0];
  ((void (*)())_LFSStreamChunkListGetStream)(param_1[1],0,local_30,param_1);
  iVar2 = iVar2 + local_30[0];
  ((void (*)())_LFSStreamChunkListGetStream)(param_1[2],0,local_30,param_1);
  iVar2 = iVar2 + local_30[0];
  ((void (*)())_LFSStreamChunkListGetStream)(param_1[3],0,local_30,param_1);
  iVar2 = iVar2 + local_30[0];
  ((void (*)())_LFSStreamChunkListGetStream)(param_1[4],0,local_30,param_1);
  iVar2 = iVar2 + local_30[0];
  ((void (*)())_LFSStreamChunkListGetStream)(param_1[5],0,local_30,param_1);
  iVar2 = iVar2 + local_30[0];
  *param_3 = (iVar2 - (iVar2 + 6U & 3)) + 10;
  if (param_2 != (uint *)0x0) {
    *param_2 = *(int *)(*param_1 + 8) << 0x10 | 0x10000006;
    ((void (*)())_LFSStreamChunkListGetStream)(*param_1,param_2 + 6,local_30,param_1);
    uVar3 = local_30[0] + 6;
    param_2[1] = *(int *)(param_1[1] + 8) << 0x10 | uVar3 | 0x10000000;
    ((void (*)())_LFSStreamChunkListGetStream)(param_1[1],param_2 + uVar3,local_30,param_1);
    uVar3 = uVar3 + local_30[0];
    param_2[2] = *(int *)(param_1[2] + 8) << 0x10 | uVar3 | 0x10000000;
    ((void (*)())_LFSStreamChunkListGetStream)(param_1[2],param_2 + uVar3,local_30,param_1);
    uVar3 = uVar3 + local_30[0];
    param_2[3] = *(int *)(param_1[3] + 8) << 0x10 | uVar3 | 0x10000000;
    ((void (*)())_LFSStreamChunkListGetStream)(param_1[3],param_2 + uVar3,local_30,param_1);
    uVar3 = uVar3 + local_30[0];
    param_2[4] = *(int *)(param_1[4] + 8) << 0x10 | uVar3 | 0x10000000;
    ((void (*)())_LFSStreamChunkListGetStream)(param_1[4],param_2 + uVar3,local_30,param_1);
    uVar4 = uVar3 + local_30[0] + 1;
    param_2[uVar3 + local_30[0]] = 0;
    if ((uVar4 & 3) != 0) {
      puVar1 = param_2 + uVar4;
      do {
        uVar4 = uVar4 + 1;
        *puVar1 = 0x50000000;
        puVar1 = puVar1 + 1;
      } while ((uVar4 & 3) != 0);
    }
    param_2[5] = *(int *)(param_1[5] + 8) << 0x10 | uVar4 | 0x10000000;
    ((void (*)())_LFSStreamChunkListGetStream)(param_1[5],param_2 + uVar4,local_30,param_1);
  }
  return;
}

/* _LFSStreamCompare @ 0xd2148 (164 bytes) */
int _LFSStreamCompare(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  bool bVar2;
  
  iVar1 = ((int (*)())_LFSStreamChunkListCompare)(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_2 + 4));
  bVar2 = true;
  if (iVar1 == 0) {
    iVar1 = ((int (*)())_LFSStreamChunkListCompare)(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_2 + 8));
    bVar2 = true;
    if (iVar1 == 0) {
      iVar1 = ((int (*)())_LFSStreamChunkListCompare)(*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_2 + 0xc));
      bVar2 = true;
      if (iVar1 == 0) {
        iVar1 = ((int (*)())_LFSStreamChunkListCompare)(*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_2 + 0x10));
        bVar2 = true;
        if (iVar1 == 0) {
          iVar1 = ((int (*)())_LFSStreamChunkListCompare)(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_2 + 0x14));
          bVar2 = iVar1 != 0;
        }
      }
    }
  }
  return bVar2;
}

/* _LFSStreamOutputDebugInfo @ 0xd21ec (164 bytes) */
void _LFSStreamOutputDebugInfo(param_1)
  undefined4 *param_1;
{
  _puts("LFSStream {");
  ((void (*)())_LFSStreamChunkListOutputDebugInfo)(*param_1);
  _puts("   preliminarypass {");
  ((void (*)())_LFSStreamChunkListOutputDebugInfo)(param_1[1]);
  ((void (*)())_LFSStreamChunkListOutputDebugInfo)(param_1[2]);
  _puts("   };");
  _puts("   outputpass {");
  ((void (*)())_LFSStreamChunkListOutputDebugInfo)(param_1[3]);
  ((void (*)())_LFSStreamChunkListOutputDebugInfo)(param_1[4]);
  _puts("   };");
  ((void (*)())_LFSStreamChunkListOutputDebugInfo)(param_1[5]);
  _puts("};");
  return;
}

/* _gleFPChanged @ 0xd2290 (76 bytes) */
void _gleFPChanged(param_1)
  int param_1;
{
  undefined *puVar1;
  
  _gleSelectVertexSubmitFunc(param_1);
  puVar1 = PTR__gleSetClipInterpFunc_00112038;
  *(undefined **)(param_1 + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
  *(undefined **)(param_1 + 0x49cc) = puVar1;
  return;
}

/* _gleFPEnable @ 0xd22dc (64 bytes) */
void _gleFPEnable(param_1)
  int param_1;
{
  ((void (*)())_gleFPChanged)(param_1);
  _gleSelectVertexSubmitFunc(param_1);
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x1000000;
  return;
}

/* _gleFPDisable @ 0xd231c (64 bytes) */
void _gleFPDisable(param_1)
  int param_1;
{
  ((void (*)())_gleFPChanged)(param_1);
  _gleSelectVertexSubmitFunc(param_1);
  *(uint *)(param_1 + 0x31c) = *(uint *)(param_1 + 0x31c) | 0x1000000;
  return;
}

/* _zeroTargetExtractor @ 0xd235c (8 bytes) */
int _zeroTargetExtractor()
{
  return 0;
}

/* _gleGetHashMachineObjectNameTargetPairs @ 0xd2364 (400 bytes) */
void _gleGetHashMachineObjectNameTargetPairs(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int param_3;
  int *param_4;
{
  undefined *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int a2;
  int *a3;
  undefined4 in_r7;
  undefined4 in_r8;
  int *piVar4;
  int a6;
  code *pcVar5;
  int iVar6;
  
  puVar1 = PTR__zeroTargetExtractor_00110e30;
  iVar6 = 0;
  a2 = param_3;
  a3 = param_4;
  if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
    _pthread_mutex_lock(*(int *)(param_1 + 0x5148) + 0x8028);
  }
  piVar2 = param_2;
  do {
    piVar4 = piVar2 + 1;
    for (piVar2 = (int *)*piVar2; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
      iVar6 = iVar6 + 1;
    }
    piVar2 = piVar4;
  } while (piVar4 <= param_2 + 0x3ff);
  if (iVar6 == 0) {
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
    }
    *param_4 = 0;
  }
  else {
    piVar2 = (int *)_malloc(iVar6 * 8 + 4);
    *piVar2 = iVar6;
    *param_4 = (int)piVar2;
    pcVar5 = (code *)PTR__gleTextureTargetExtractor_0011215c;
    if ((param_3 != 2) &&
       (pcVar5 = (code *)PTR__glePipelineProgramTargetExtactor_00112158, param_3 != 4)) {
      pcVar5 = (code *)puVar1;
    }
    iVar6 = 0;
    piVar2 = param_2;
    do {
      piVar4 = piVar2 + 1;
      for (piVar2 = (int *)*piVar2; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
        a6 = *param_4;
        *(int *)((iVar6 + 1) * 4 + a6) = piVar2[1];
        iVar6 = iVar6 + 2;
        uVar3 = (*pcVar5)(param_1,piVar2,a2,a3,in_r7,in_r8,a6);
        *(undefined4 *)(iVar6 * 4 + *param_4) = uVar3;
      }
      piVar2 = piVar4;
    } while (piVar4 <= param_2 + 0x3ff);
    if (*(char *)(*(int *)(param_1 + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(param_1 + 0x5148) + 0x8028);
      return;
    }
  }
  return;
}

/* _gleImagingTexFormatToInternal @ 0xd24f4 (560 bytes) */
int _gleImagingTexFormatToInternal(param_1)
  uint param_1;
{
  bool bVar1;
  uint uVar2;
  
  if (param_1 < 0x805c) {
    if (0x8054 < param_1) {
      return 0x1908;
    }
    if (0x803e < param_1) {
      if (param_1 == 0x8049) {
        return 0x8049;
      }
      if (param_1 < 0x804a) {
        if (0x8042 < param_1) {
          return 0x190a;
        }
        return 0x1909;
      }
      if (param_1 < 0x804e) {
        return 0x8049;
      }
      if (param_1 < 0x804f) {
        return 0;
      }
      return 0x1907;
    }
    if (0x803a < param_1) {
      return 0x1906;
    }
    if (param_1 == 4) {
      return 0x1908;
    }
    if (param_1 < 5) {
      if (param_1 == 2) {
        return 0x190a;
      }
      if (param_1 < 3) {
        if (param_1 != 1) {
          return 0;
        }
        return 0x1909;
      }
      return 0x1907;
    }
    if (param_1 < 0x1906) {
      return 0;
    }
    if (param_1 < 0x190b) {
      return param_1;
    }
    bVar1 = param_1 == 0x2a10;
  }
  else {
    if (param_1 == 0x8817) {
      return 0x8049;
    }
    if (param_1 < 0x8818) {
      if (param_1 == 0x84ed) {
        return 0x1907;
      }
      if (param_1 < 0x84ee) {
        if (param_1 == 0x84ea) {
          return 0x1909;
        }
        if (0x84ea < param_1) {
          if (param_1 == 0x84eb) {
            return 0x190a;
          }
          if (param_1 != 0x84ec) {
            return 0;
          }
          return 0x8049;
        }
        uVar2 = 0x84e9;
      }
      else {
        if (param_1 == 0x8814) {
          return 0x1908;
        }
        if (param_1 < 0x8815) {
          if (param_1 == 0x84ee) {
            return 0x1908;
          }
          return 0;
        }
        if (param_1 == 0x8815) {
          return 0x1907;
        }
        uVar2 = 0x8816;
      }
      if (param_1 == uVar2) {
        return 0x1906;
      }
      return 0;
    }
    if (param_1 == 0x881c) {
      return 0x1906;
    }
    if (0x881c < param_1) {
      if (param_1 == 0x881e) {
        return 0x1909;
      }
      if (0x881d < param_1) {
        if ((param_1 != 0x881f) && (param_1 != 0x8837)) {
          return 0;
        }
        return 0x190a;
      }
      return 0x8049;
    }
    if (param_1 == 0x8819) {
      return 0x190a;
    }
    if (param_1 < 0x8819) {
      return 0x1909;
    }
    if (param_1 == 0x881a) {
      return 0x1908;
    }
    bVar1 = param_1 == 0x881b;
  }
  if (bVar1) {
    return 0x1907;
  }
  return 0;
}

/* _gleImagingUnpackData @ 0xd2724 (316 bytes) */
void _gleImagingUnpackData(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  int param_8;
  undefined4 param_9;
{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  int *piVar6;
  int local_c0;
  undefined4 local_bc;
  undefined1 auStack_b8 [4];
  undefined1 auStack_b4 [4];
  undefined4 local_b0;
  int local_ac;
  undefined1 auStack_a8 [4];
  undefined1 auStack_a4 [4];
  undefined4 local_a0;
  uint local_9c;
  undefined4 local_98;
  int local_94;
  undefined4 local_90;
  undefined1 local_54;
  undefined4 local_50;
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [4];
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [4];
  int local_3c [6];
  
  iVar4 = param_1 + 0x31cc;
  puVar5 = auStack_40;
  piVar6 = local_3c;
  uVar3 = param_3;
  _glePixelPackSettings
            (param_1,param_6,param_7,param_2,param_3,iVar4,puVar5,piVar6,&local_50,auStack_4c,
             auStack_48,auStack_44);
  _glgConvertType(param_4,param_5,auStack_b8,auStack_b4,uVar3,iVar4,puVar5,piVar6);
  puVar1 = auStack_a8;
  puVar2 = auStack_a4;
  _glgConvertType(param_6,param_7,puVar1,puVar2,uVar3,iVar4,puVar5,piVar6);
  local_c0 = param_8 + local_3c[0];
  local_98 = 5;
  local_bc = local_50;
  local_a0 = 2;
  local_b0 = param_9;
  local_9c = 0;
  local_94 = param_2;
  local_90 = param_3;
  local_ac = _glePixelBytes(param_6,param_7);
  local_ac = param_2 * local_ac;
  local_54 = 0;
  if (*(char *)(param_1 + 0x31e4) != '\0') {
    local_9c = local_9c | 1;
  }
  if (*(char *)(param_1 + 0x31e5) != '\0') {
    local_9c = local_9c | 4;
  }
  _glgProcessPixels(param_1 + 0x31a8,&local_c0,puVar1,puVar2,uVar3,iVar4,puVar5,piVar6);
  return;
}

/* _gleImagingPackData @ 0xd2860 (312 bytes) */
void _gleImagingPackData(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  int param_9;
{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 *puVar5;
  int *piVar6;
  undefined4 local_c0;
  int local_bc;
  undefined1 auStack_b8 [4];
  undefined1 auStack_b4 [4];
  int local_b0;
  undefined4 local_ac;
  undefined1 auStack_a8 [4];
  undefined1 auStack_a4 [4];
  undefined4 local_a0;
  uint local_9c;
  undefined4 local_98;
  int local_94;
  undefined4 local_90;
  undefined1 local_54;
  undefined4 local_50;
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [4];
  undefined1 auStack_44 [4];
  undefined1 auStack_40 [4];
  int local_3c [6];
  
  iVar4 = param_1 + 0x31b0;
  puVar5 = auStack_40;
  piVar6 = local_3c;
  uVar3 = param_3;
  _glePixelPackSettings
            (param_1,param_4,param_5,param_2,param_3,iVar4,puVar5,piVar6,&local_50,auStack_4c,
             auStack_48,auStack_44);
  _glgConvertType(param_4,param_5,auStack_b8,auStack_b4,uVar3,iVar4,puVar5,piVar6);
  puVar1 = auStack_a8;
  puVar2 = auStack_a4;
  _glgConvertType(param_6,param_7,puVar1,puVar2,uVar3,iVar4,puVar5,piVar6);
  local_c0 = param_8;
  local_bc = _glePixelBytes(param_4,param_5);
  local_bc = param_2 * local_bc;
  local_b0 = param_9 + local_3c[0];
  local_98 = 5;
  local_a0 = 2;
  local_ac = local_50;
  local_54 = 0;
  local_9c = (uint)(*(char *)(param_1 + 0x31c8) != '\0');
  if (*(char *)(param_1 + 0x31c9) != '\0') {
    local_9c = local_9c | 4;
  }
  local_94 = param_2;
  local_90 = param_3;
  _glgProcessPixels(param_1 + 0x31a8,&local_c0,puVar1,puVar2,uVar3,iVar4,0,piVar6);
  return;
}

/* _gleImagingScaleAndBias @ 0xd2998 (936 bytes) */
void _gleImagingScaleAndBias(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  float *param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
  int param_7;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  
  if (((((*param_2 != FLOAT_00108e54) || (param_2[2] != FLOAT_00108e54)) ||
       (param_2[4] != FLOAT_00108e54)) ||
      ((param_2[6] != FLOAT_00108e54 || (param_2[1] != FLOAT_00108e50)))) ||
     ((param_2[3] != FLOAT_00108e50 ||
      ((param_2[5] != FLOAT_00108e50 || (param_2[7] != FLOAT_00108e50)))))) {
    iVar6 = _gleComponents(param_4);
    iVar7 = 0;
    pfVar8 = (float *)(param_3 + param_5 * iVar6 * 4);
    if (0 < param_6) {
      do {
        switch(param_4) {
        case 0x1906:
          fVar1 = *pfVar8 * param_2[6] + param_2[7];
          if ((param_7 != 0) &&
             ((fVar2 = FLOAT_00108e50, fVar1 <= FLOAT_00108e50 ||
              (fVar2 = FLOAT_00108e54, FLOAT_00108e54 < fVar1)))) {
            fVar1 = fVar2;
          }
          *pfVar8 = fVar1;
          break;
        case 0x1907:
          fVar1 = *pfVar8 * *param_2 + param_2[1];
          fVar2 = pfVar8[1] * param_2[2] + param_2[3];
          fVar3 = pfVar8[2] * param_2[4] + param_2[5];
          if (param_7 != 0) {
            fVar5 = FLOAT_00108e50;
            if ((fVar1 <= FLOAT_00108e50) || (fVar5 = FLOAT_00108e54, FLOAT_00108e54 < fVar1)) {
              fVar1 = fVar5;
            }
            fVar5 = FLOAT_00108e50;
            if ((fVar2 <= FLOAT_00108e50) || (fVar5 = FLOAT_00108e54, FLOAT_00108e54 < fVar2)) {
              fVar2 = fVar5;
            }
            fVar5 = FLOAT_00108e50;
            if ((fVar3 <= FLOAT_00108e50) || (fVar5 = FLOAT_00108e54, FLOAT_00108e54 < fVar3)) {
              fVar3 = fVar5;
            }
          }
          *pfVar8 = fVar1;
          pfVar8[1] = fVar2;
          pfVar8 = pfVar8 + 2;
          *pfVar8 = fVar3;
          break;
        case 0x1908:
          fVar1 = *pfVar8 * *param_2 + param_2[1];
          fVar3 = pfVar8[1] * param_2[2] + param_2[3];
          fVar5 = pfVar8[2] * param_2[4] + param_2[5];
          fVar2 = pfVar8[3] * param_2[6] + param_2[7];
          if (param_7 != 0) {
            fVar4 = FLOAT_00108e50;
            if ((fVar1 <= FLOAT_00108e50) || (fVar4 = FLOAT_00108e54, FLOAT_00108e54 < fVar1)) {
              fVar1 = fVar4;
            }
            fVar4 = FLOAT_00108e50;
            if ((fVar3 <= FLOAT_00108e50) || (fVar4 = FLOAT_00108e54, FLOAT_00108e54 < fVar3)) {
              fVar3 = fVar4;
            }
            fVar4 = FLOAT_00108e50;
            if ((fVar5 <= FLOAT_00108e50) || (fVar4 = FLOAT_00108e54, FLOAT_00108e54 < fVar5)) {
              fVar5 = fVar4;
            }
            fVar4 = FLOAT_00108e50;
            if ((fVar2 <= FLOAT_00108e50) || (fVar4 = FLOAT_00108e54, FLOAT_00108e54 < fVar2)) {
              fVar2 = fVar4;
            }
          }
          *pfVar8 = fVar1;
          pfVar8[1] = fVar3;
          pfVar8 = pfVar8 + 2;
          *pfVar8 = fVar5;
          goto LAB_000d2d2c;
        case 0x1909:
          fVar1 = *pfVar8 * *param_2 + param_2[1];
          if ((param_7 != 0) &&
             ((fVar2 = FLOAT_00108e50, fVar1 <= FLOAT_00108e50 ||
              (fVar2 = FLOAT_00108e54, FLOAT_00108e54 < fVar1)))) {
            fVar1 = fVar2;
          }
          *pfVar8 = fVar1;
          break;
        case 0x190a:
          fVar1 = *pfVar8 * *param_2 + param_2[1];
          fVar2 = pfVar8[1] * param_2[6] + param_2[7];
          if (param_7 != 0) {
            fVar3 = FLOAT_00108e50;
            if ((fVar1 <= FLOAT_00108e50) || (fVar3 = FLOAT_00108e54, FLOAT_00108e54 < fVar1)) {
              fVar1 = fVar3;
            }
            fVar3 = FLOAT_00108e50;
            if ((fVar2 <= FLOAT_00108e50) || (fVar3 = FLOAT_00108e54, FLOAT_00108e54 < fVar2)) {
              fVar2 = fVar3;
            }
          }
          *pfVar8 = fVar1;
LAB_000d2d2c:
          pfVar8 = pfVar8 + 1;
          *pfVar8 = fVar2;
          break;
        default:
          goto switchD_000d2a7c_default;
        }
        pfVar8 = pfVar8 + 1;
switchD_000d2a7c_default:
        iVar7 = iVar7 + 1;
      } while (iVar7 < param_6);
    }
  }
  return;
}

/* _gleGetHistogram @ 0xd2d54 (3104 bytes) */
void _gleGetHistogram(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  int param_3;
  uint param_4;
  uint param_5;
  int param_6;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  double dVar16;
  undefined1 uVar18;
  ushort uVar17;
  int iVar19;
  int iVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float *pfVar25;
  int iVar26;
  float *pfVar27;
  float *pfVar28;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  
  pfVar27 = *(float **)(param_1 + 0x3384);
  iVar26 = *(int *)(param_1 + 0x3388);
  iVar20 = _glePixelBytes(param_4,param_5);
  dVar16 = DOUBLE_00108d58;
  iVar19 = *(int *)(param_1 + 0x31c4);
  pfVar25 = (float *)(param_6 + iVar20 * *(int *)(param_1 + 0x31bc));
  if (iVar19 == 4) {
    if (((uint)pfVar25 & 3) != 0) {
      pfVar25 = (float *)((uint)(pfVar25 + 1) & 0xfffffffc);
    }
  }
  else if (iVar19 < 5) {
    if ((iVar19 == 2) && (((uint)pfVar25 & 1) != 0)) {
      pfVar25 = (float *)((int)pfVar25 + 1);
    }
  }
  else if ((iVar19 == 8) && (((uint)pfVar25 & 7) != 0)) {
    pfVar25 = (float *)((uint)(pfVar25 + 2) & 0xfffffff8);
  }
  if (0 < iVar26) {
    bVar14 = 0x1905 < param_4;
    bVar1 = param_4 == 0x8000;
    bVar4 = param_4 == 0x1903;
    bVar5 = param_4 != 0x1904;
    bVar2 = param_4 == 0x80e0;
    bVar3 = param_4 == 0x80e1;
    bVar6 = param_4 == 0x1906;
    bVar7 = param_4 == 0x1907;
    bVar8 = *(char *)(param_1 + 0x31c8) != '\0';
    bVar15 = 0x8000 < param_4;
    bVar9 = param_4 == 0x1908;
    bVar10 = param_4 == 0x1909;
    bVar13 = 0x1908 < param_4;
    bVar11 = param_4 == 0x1905;
    bVar12 = param_4 == 0x190a;
    pfVar28 = pfVar27;
    iVar19 = iVar26;
    do {
      if (param_5 == 0x1406) {
        fVar21 = (float)((double)CONCAT44(0x43300000,-*pfVar28) - dVar16);
        fVar22 = (float)((double)CONCAT44(0x43300000,-pfVar28[1]) - dVar16);
        fVar23 = (float)((double)CONCAT44(0x43300000,-pfVar28[2]) - dVar16);
        fVar24 = (float)((double)CONCAT44(0x43300000,-pfVar28[3]) - dVar16);
        if (bVar8) {
          fVar21 = GH_U2F((unsigned int)(((uint)GH_F2U(fVar21) >> 0x18 | (uint)GH_F2U(fVar21) >> 8 & 0xff00 |
                           ((uint)GH_F2U(fVar21) & 0xff00) << 8 | (int)GH_F2U(fVar21) << 0x18)));
          fVar22 = GH_U2F((unsigned int)(((uint)GH_F2U(fVar22) >> 0x18 | (uint)GH_F2U(fVar22) >> 8 & 0xff00 |
                           ((uint)GH_F2U(fVar22) & 0xff00) << 8 | (int)GH_F2U(fVar22) << 0x18)));
          fVar23 = GH_U2F((unsigned int)(((uint)GH_F2U(fVar23) >> 0x18 | (uint)GH_F2U(fVar23) >> 8 & 0xff00 |
                           ((uint)GH_F2U(fVar23) & 0xff00) << 8 | (int)GH_F2U(fVar23) << 0x18)));
          fVar24 = GH_U2F((unsigned int)(((uint)GH_F2U(fVar24) >> 0x18 | (uint)GH_F2U(fVar24) >> 8 & 0xff00 |
                           ((uint)GH_F2U(fVar24) & 0xff00) << 8 | (int)GH_F2U(fVar24) << 0x18)));
        }
        if (bVar9) {
          *pfVar25 = fVar21;
          pfVar25[1] = fVar22;
          pfVar25 = pfVar25 + 2;
          *pfVar25 = fVar23;
          goto LAB_000d372c;
        }
        if (bVar13) {
          if (!bVar1) {
            if (bVar15) {
              if (bVar2) {
                *pfVar25 = fVar23;
                goto LAB_000d3714;
              }
              if (bVar3) {
                *pfVar25 = fVar23;
                pfVar25[1] = fVar22;
                pfVar25 = pfVar25 + 2;
                *pfVar25 = fVar21;
                goto LAB_000d372c;
              }
            }
            else {
              if (bVar10) goto LAB_000d3720;
              if (bVar12) {
                *pfVar25 = fVar21;
LAB_000d372c:
                pfVar25 = pfVar25 + 1;
                *pfVar25 = fVar24;
                goto LAB_000d3730;
              }
            }
            goto LAB_000d3734;
          }
          *pfVar25 = fVar24;
          pfVar25 = pfVar25 + 1;
          *pfVar25 = fVar23;
LAB_000d3714:
          pfVar25[1] = fVar22;
          pfVar25 = pfVar25 + 2;
          *pfVar25 = fVar21;
        }
        else if (bVar11) {
          *pfVar25 = fVar23;
        }
        else if (bVar14) {
          if (bVar6) {
            *pfVar25 = fVar24;
          }
          else {
            if (!bVar7) goto LAB_000d3734;
            *pfVar25 = fVar21;
            pfVar25[1] = fVar22;
            pfVar25 = pfVar25 + 2;
            *pfVar25 = fVar23;
          }
        }
        else if (bVar4) {
LAB_000d3720:
          *pfVar25 = fVar21;
        }
        else {
          if (bVar5) goto LAB_000d3734;
          *pfVar25 = fVar22;
        }
LAB_000d3730:
        pfVar25 = pfVar25 + 1;
        goto LAB_000d3734;
      }
      if (0x1406 < param_5) goto LAB_000d3734;
      if (param_5 != 0x1402) {
        if (param_5 < 0x1403) {
          if (param_5 == 0x1400) {
            if (bVar9) {
LAB_000d3048:
              *(undefined1 *)pfVar25 = *(undefined1 *)((int)pfVar28 + 3);
              *(undefined1 *)((int)pfVar25 + 1) = *(undefined1 *)((int)pfVar28 + 7);
              uVar18 = *(undefined1 *)((int)pfVar28 + 0xb);
LAB_000d3074:
              pfVar25 = (float *)((int)pfVar25 + 2);
              *(undefined1 *)pfVar25 = uVar18;
LAB_000d30ac:
              uVar18 = *(undefined1 *)((int)pfVar28 + 0xf);
            }
            else {
              if (!bVar13) {
                if (!bVar11) goto LAB_000d2f78;
LAB_000d3020:
                uVar18 = *(undefined1 *)((int)pfVar28 + 0xb);
                goto LAB_000d2f38;
              }
LAB_000d2fc4:
              if (!bVar1) {
                if (bVar15) {
                  if (bVar2) {
                    *(undefined1 *)pfVar25 = *(undefined1 *)((int)pfVar28 + 0xb);
                    *(undefined1 *)((int)pfVar25 + 1) = *(undefined1 *)((int)pfVar28 + 7);
                    uVar18 = *(undefined1 *)((int)pfVar28 + 3);
LAB_000d2f54:
                    pfVar25 = (float *)((int)pfVar25 + 2);
                    *(undefined1 *)pfVar25 = uVar18;
                    goto LAB_000d30b4;
                  }
                  if (!bVar3) goto LAB_000d3734;
                  *(undefined1 *)pfVar25 = *(undefined1 *)((int)pfVar28 + 0xb);
                  *(undefined1 *)((int)pfVar25 + 1) = *(undefined1 *)((int)pfVar28 + 7);
                  uVar18 = *(undefined1 *)((int)pfVar28 + 3);
                  goto LAB_000d3074;
                }
                if (bVar10) {
LAB_000d309c:
                  uVar18 = *(undefined1 *)((int)pfVar28 + 3);
                  goto LAB_000d2f38;
                }
                if (!bVar12) goto LAB_000d3734;
                *(undefined1 *)pfVar25 = *(undefined1 *)((int)pfVar28 + 3);
                goto LAB_000d30ac;
              }
              *(undefined1 *)pfVar25 = *(undefined1 *)((int)pfVar28 + 0xf);
              *(undefined1 *)((int)pfVar25 + 1) = *(undefined1 *)((int)pfVar28 + 0xb);
              pfVar25 = (float *)((int)pfVar25 + 2);
              *(undefined1 *)pfVar25 = *(undefined1 *)((int)pfVar28 + 7);
              uVar18 = *(undefined1 *)((int)pfVar28 + 3);
            }
            pfVar25 = (float *)((int)pfVar25 + 1);
            *(undefined1 *)pfVar25 = uVar18;
          }
          else {
            if (param_5 != 0x1401) goto LAB_000d3734;
            if (bVar9) goto LAB_000d3048;
            if (bVar13) goto LAB_000d2fc4;
            if (bVar11) goto LAB_000d3020;
LAB_000d2f78:
            if (bVar14) {
              if (!bVar6) {
                if (!bVar7) goto LAB_000d3734;
                *(undefined1 *)pfVar25 = *(undefined1 *)((int)pfVar28 + 3);
                *(undefined1 *)((int)pfVar25 + 1) = *(undefined1 *)((int)pfVar28 + 7);
                uVar18 = *(undefined1 *)((int)pfVar28 + 0xb);
                goto LAB_000d2f54;
              }
              uVar18 = *(undefined1 *)((int)pfVar28 + 0xf);
            }
            else {
              if (bVar4) goto LAB_000d309c;
              if (bVar5) goto LAB_000d3734;
              uVar18 = *(undefined1 *)((int)pfVar28 + 7);
            }
LAB_000d2f38:
            *(undefined1 *)pfVar25 = uVar18;
          }
LAB_000d30b4:
          pfVar25 = (float *)((int)pfVar25 + 1);
          goto LAB_000d3734;
        }
        if ((param_5 == 0x1404) || (0x1404 < param_5)) {
          local_80 = *pfVar28;
          local_7c = pfVar28[1];
          local_78 = pfVar28[2];
          local_74 = pfVar28[3];
          if (bVar8) {
            fVar24 = *pfVar28;
            fVar23 = pfVar28[1];
            fVar22 = pfVar28[2];
            fVar21 = pfVar28[3];
            local_80 = GH_U2F((unsigned int)(((int)GH_F2U(fVar24) >> 0x18 | (uint)GH_F2U(fVar24) >> 8 & 0xff00 |
                               ((uint)GH_F2U(fVar24) & 0xff00) << 8 | (int)GH_F2U(fVar24) << 0x18)));
            local_7c = GH_U2F((unsigned int)(((int)GH_F2U(fVar23) >> 0x18 | (uint)GH_F2U(fVar23) >> 8 & 0xff00 |
                               ((uint)GH_F2U(fVar23) & 0xff00) << 8 | (int)GH_F2U(fVar23) << 0x18)));
            local_78 = GH_U2F((unsigned int)(((int)GH_F2U(fVar22) >> 0x18 | (uint)GH_F2U(fVar22) >> 8 & 0xff00 |
                               ((uint)GH_F2U(fVar22) & 0xff00) << 8 | (int)GH_F2U(fVar22) << 0x18)));
            local_74 = GH_U2F((unsigned int)(((int)GH_F2U(fVar21) >> 0x18 | (uint)GH_F2U(fVar21) >> 8 & 0xff00 |
                               ((uint)GH_F2U(fVar21) & 0xff00) << 8 | (int)GH_F2U(fVar21) << 0x18)));
          }
          if (bVar9) {
            *pfVar25 = local_80;
            pfVar25[1] = local_7c;
            local_80 = local_78;
LAB_000d32f4:
            pfVar25 = pfVar25 + 2;
            *pfVar25 = local_80;
            local_80 = local_74;
          }
          else {
            if (!bVar13) {
              fVar21 = local_78;
              if (!bVar11) {
                if (bVar14) {
                  fVar21 = local_74;
                  if (bVar6) goto LAB_000d32bc;
                  if (bVar7) {
                    *pfVar25 = local_80;
                    pfVar25[1] = local_7c;
                    goto LAB_000d32d8;
                  }
                }
                else {
                  fVar21 = local_80;
                  if ((bVar4) || (fVar21 = local_7c, !bVar5)) goto LAB_000d32bc;
                }
                goto LAB_000d3734;
              }
LAB_000d32bc:
              *pfVar25 = fVar21;
              goto LAB_000d3730;
            }
            if (!bVar1) {
              if (bVar15) {
                if (bVar2) {
                  *pfVar25 = local_78;
                  pfVar25[1] = local_7c;
                  local_78 = local_80;
LAB_000d32d8:
                  pfVar25 = pfVar25 + 2;
                  *pfVar25 = local_78;
                  goto LAB_000d3730;
                }
                if (bVar3) {
                  *pfVar25 = local_78;
                  pfVar25[1] = local_7c;
                  goto LAB_000d32f4;
                }
              }
              else {
                fVar21 = local_80;
                if (bVar10) goto LAB_000d32bc;
                if (bVar12) {
                  *pfVar25 = local_80;
                  local_80 = local_74;
                  goto LAB_000d32fc;
                }
              }
              goto LAB_000d3734;
            }
            *pfVar25 = local_74;
            pfVar25[1] = local_78;
            pfVar25 = pfVar25 + 2;
            *pfVar25 = local_7c;
          }
LAB_000d32fc:
          pfVar25 = pfVar25 + 1;
          *pfVar25 = local_80;
          goto LAB_000d3730;
        }
      }
      (*(unsigned short *)((unsigned char *)&(local_80) + 2)) = SUB42(*pfVar28,0);
      (*(unsigned short *)((unsigned char *)&(local_7c) + 2)) = SUB42(pfVar28[1],0);
      (*(unsigned short *)((unsigned char *)&(local_78) + 2)) = SUB42(pfVar28[2],0);
      (*(unsigned short *)((unsigned char *)&(local_74) + 2)) = SUB42(pfVar28[3],0);
      if (bVar8) {
        (*(unsigned short *)((unsigned char *)&(local_80) + 2)) =
             (ushort)(((uint)GH_F2U(*pfVar28) & 0xff) << 8) | (ushort)((uint)GH_F2U(*pfVar28) >> 8) & 0xff;
        (*(unsigned short *)((unsigned char *)&(local_7c) + 2)) =
             (ushort)(((uint)GH_F2U(pfVar28[1]) & 0xff) << 8) | (ushort)((uint)GH_F2U(pfVar28[1]) >> 8) & 0xff;
        (*(unsigned short *)((unsigned char *)&(local_78) + 2)) =
             (ushort)(((uint)GH_F2U(pfVar28[2]) & 0xff) << 8) | (ushort)((uint)GH_F2U(pfVar28[2]) >> 8) & 0xff;
        (*(unsigned short *)((unsigned char *)&(local_74) + 2)) =
             (ushort)(((uint)GH_F2U(pfVar28[3]) & 0xff) << 8) | (ushort)((uint)GH_F2U(pfVar28[3]) >> 8) & 0xff;
      }
      if (bVar9) {
        *(ushort *)pfVar25 = (*(unsigned short *)((unsigned char *)&(local_80) + 2));
        *(ushort *)((int)pfVar25 + 2) = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
        (*(unsigned short *)((unsigned char *)&(local_80) + 2)) = (*(unsigned short *)((unsigned char *)&(local_78) + 2));
LAB_000d3270:
        pfVar25 = pfVar25 + 1;
        *(ushort *)pfVar25 = (*(unsigned short *)((unsigned char *)&(local_80) + 2));
        (*(unsigned short *)((unsigned char *)&(local_80) + 2)) = (*(unsigned short *)((unsigned char *)&(local_74) + 2));
LAB_000d32ac:
        pfVar25 = (float *)((int)pfVar25 + 2);
        *(ushort *)pfVar25 = (*(unsigned short *)((unsigned char *)&(local_80) + 2));
LAB_000d32b0:
        pfVar25 = (float *)((int)pfVar25 + 2);
      }
      else if (bVar13) {
        if (bVar1) {
          *(ushort *)pfVar25 = (*(unsigned short *)((unsigned char *)&(local_74) + 2));
          *(ushort *)((int)pfVar25 + 2) = (*(unsigned short *)((unsigned char *)&(local_78) + 2));
          pfVar25 = pfVar25 + 1;
          *(ushort *)pfVar25 = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
          goto LAB_000d32ac;
        }
        if (bVar15) {
          if (bVar2) {
            *(ushort *)pfVar25 = (*(unsigned short *)((unsigned char *)&(local_78) + 2));
            *(ushort *)((int)pfVar25 + 2) = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
            (*(unsigned short *)((unsigned char *)&(local_78) + 2)) = (*(unsigned short *)((unsigned char *)&(local_80) + 2));
LAB_000d30dc:
            pfVar25 = pfVar25 + 1;
            *(ushort *)pfVar25 = (*(unsigned short *)((unsigned char *)&(local_78) + 2));
            goto LAB_000d32b0;
          }
          if (bVar3) {
            *(ushort *)pfVar25 = (*(unsigned short *)((unsigned char *)&(local_78) + 2));
            *(ushort *)((int)pfVar25 + 2) = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
            goto LAB_000d3270;
          }
        }
        else {
          uVar17 = (*(unsigned short *)((unsigned char *)&(local_80) + 2));
          if (bVar10) goto LAB_000d30c0;
          if (bVar12) {
            *(ushort *)pfVar25 = (*(unsigned short *)((unsigned char *)&(local_80) + 2));
            (*(unsigned short *)((unsigned char *)&(local_80) + 2)) = (*(unsigned short *)((unsigned char *)&(local_74) + 2));
            goto LAB_000d32ac;
          }
        }
      }
      else {
        uVar17 = (*(unsigned short *)((unsigned char *)&(local_78) + 2));
        if (bVar11) {
LAB_000d30c0:
          *(ushort *)pfVar25 = uVar17;
          goto LAB_000d32b0;
        }
        if (bVar14) {
          uVar17 = (*(unsigned short *)((unsigned char *)&(local_74) + 2));
          if (bVar6) goto LAB_000d30c0;
          if (bVar7) {
            *(ushort *)pfVar25 = (*(unsigned short *)((unsigned char *)&(local_80) + 2));
            *(ushort *)((int)pfVar25 + 2) = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
            goto LAB_000d30dc;
          }
        }
        else {
          uVar17 = (*(unsigned short *)((unsigned char *)&(local_80) + 2));
          if ((bVar4) || (uVar17 = (*(unsigned short *)((unsigned char *)&(local_7c) + 2)), !bVar5)) goto LAB_000d30c0;
        }
      }
LAB_000d3734:
      pfVar28 = pfVar28 + 4;
      iVar19 = iVar19 + -1;
    } while (iVar19 != 0);
  }
  if ((param_3 != 0) && (iVar19 = 0, 0 < iVar26)) {
    pfVar25 = pfVar27;
    do {
      if (param_4 == 0x8032) goto LAB_000d3938;
      if (param_4 < 0x8033) {
        if (param_4 == 0x1906) {
LAB_000d3920:
          pfVar25[3] = 0.0;
        }
        else if (param_4 < 0x1907) {
          if (param_4 == 0x1904) {
            pfVar25[1] = 0.0;
          }
          else if (param_4 < 0x1905) {
            if (param_4 == 0x1903) {
LAB_000d3904:
              *pfVar25 = 0.0;
            }
          }
          else {
            pfVar25[2] = 0.0;
          }
        }
        else {
          if (param_4 == 0x1908) goto LAB_000d3928;
          if (param_4 < 0x1908) goto LAB_000d3938;
          if (param_4 == 0x1909) goto LAB_000d3904;
          if (param_4 == 0x190a) {
            *pfVar25 = 0.0;
            goto LAB_000d3920;
          }
        }
      }
      else {
        if (param_4 == 0x80e1) {
LAB_000d3928:
          iVar20 = iVar19 * 0x10;
          pfVar27[iVar19 * 4 + 3] = 0.0;
        }
        else {
          if (0x80e1 < param_4) {
            if (0x8361 < param_4) {
              if (param_4 < 0x8365) goto LAB_000d3938;
              if (param_4 < 0x8369) goto LAB_000d3928;
            }
            goto LAB_000d394c;
          }
          if (param_4 < 0x8037) goto LAB_000d3928;
          if (param_4 != 0x80e0) goto LAB_000d394c;
LAB_000d3938:
          iVar20 = iVar19 << 4;
        }
        *(undefined4 *)((int)pfVar27 + iVar20) = 0;
        *(undefined4 *)((int)pfVar27 + iVar20 + 8) = 0;
        *(undefined4 *)((int)pfVar27 + iVar20 + 4) = 0;
      }
LAB_000d394c:
      iVar19 = iVar19 + 1;
      pfVar25 = pfVar25 + 4;
      iVar26 = iVar26 + -1;
    } while (iVar26 != 0);
  }
  return;
}

/* _gleGetMinmax @ 0xd3974 (628 bytes) */
void _gleGetMinmax(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  int param_3;
  uint param_4;
  undefined4 param_5;
  int param_6;
{
  float fVar1;
  double dVar2;
  int iVar3;
  code *pcVar4;
  undefined4 *puVar5;
  undefined1 auStack_80 [4];
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  
  puVar5 = *(undefined4 **)(param_1 + 0x337c);
  iVar3 = _glePixelBytes(param_4,param_5);
  pcVar4 = (code *)_gleSelectPixelInsertFunc(param_4,param_5);
  local_7c = *puVar5;
  local_78 = puVar5[1];
  local_74 = puVar5[2];
  local_70 = puVar5[3];
  (*pcVar4)(auStack_80,param_6);
  local_7c = puVar5[4];
  local_78 = puVar5[5];
  local_74 = puVar5[6];
  local_70 = puVar5[7];
  (*pcVar4)(auStack_80,param_6 + iVar3);
  if (param_3 == 0) {
    return;
  }
  if (param_4 == 0x8032) goto LAB_000d3b98;
  if (param_4 < 0x8033) {
    if (param_4 == 0x1906) {
      puVar5[3] = 0x3f800000;
      puVar5[7] = 0;
      return;
    }
    if (param_4 < 0x1907) {
      if (param_4 == 0x1904) {
        puVar5[1] = 0x3f800000;
        puVar5[5] = 0;
        return;
      }
      if (0x1904 < param_4) {
        puVar5[2] = 0x3f800000;
        puVar5[6] = 0;
        return;
      }
      if (param_4 != 0x1903) {
        return;
      }
LAB_000d3af4:
      *puVar5 = 0x3f800000;
      puVar5[4] = (float)(4503601774854144.0 - DOUBLE_00108d58);
      return;
    }
    if (param_4 != 0x1908) {
      if (param_4 < 0x1908) goto LAB_000d3b98;
      if (param_4 != 0x1909) {
        if (param_4 != 0x190a) {
          return;
        }
        puVar5[3] = 0x3f800000;
        *puVar5 = 0x3f800000;
        puVar5[7] = 0;
        puVar5[4] = 0;
        return;
      }
      goto LAB_000d3af4;
    }
  }
  else if (param_4 != 0x80e1) {
    if (param_4 < 0x80e2) {
      if (0x8036 < param_4) {
        if (param_4 != 0x80e0) {
          return;
        }
        goto LAB_000d3b98;
      }
    }
    else {
      if (param_4 < 0x8362) {
        return;
      }
      if (param_4 < 0x8365) goto LAB_000d3b98;
      if (0x8368 < param_4) {
        return;
      }
    }
  }
  puVar5[3] = 0x3f800000;
  puVar5[7] = (float)(4503601774854144.0 - DOUBLE_00108d58);
LAB_000d3b98:
  *puVar5 = 0x3f800000;
  dVar2 = DOUBLE_00108d58;
  puVar5[2] = 0x3f800000;
  puVar5[1] = 0x3f800000;
  fVar1 = (float)(4503601774854144.0 - dVar2);
  puVar5[6] = fVar1;
  puVar5[4] = fVar1;
  puVar5[5] = fVar1;
  return;
}

/* _gleConvolutionFilter1D @ 0xd3be8 (224 bytes) */
void _gleConvolutionFilter1D(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x32cc) != 0) {
    _free(*(int *)(param_1 + 0x32cc));
  }
  *(undefined4 *)(param_1 + 0x32d4) = 1;
  *(int *)(param_1 + 0x32d0) = param_4;
  if (param_4 == 0) {
    *(undefined4 *)(param_1 + 0x32cc) = 0;
    return;
  }
  iVar1 = _glePixelBytes(param_3,0x1406);
  uVar2 = _malloc(param_4 * iVar1);
  *(undefined4 *)(param_1 + 0x32cc) = uVar2;
  *(short *)(param_1 + 0x32ca) = (short)param_3;
  ((void (*)())_gleImagingUnpackData)(param_1,param_4,1,param_5,param_6,param_3,0x1406,param_7,uVar2);
  ((void (*)())_gleImagingScaleAndBias)(param_1,param_1 + 0x32a8,*(undefined4 *)(param_1 + 0x32cc),
             (uint)*(ushort *)(param_1 + 0x32ca),0,param_4,0);
  return;
}

/* _gleConvolutionFilter2D @ 0xd3cc8 (240 bytes) */
void _gleConvolutionFilter2D(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x330c) != 0) {
    _free(*(int *)(param_1 + 0x330c));
  }
  *(int *)(param_1 + 0x3310) = param_4;
  *(int *)(param_1 + 0x3314) = param_5;
  if ((param_4 != 0) && (param_5 != 0)) {
    iVar1 = _glePixelBytes(param_3,0x1406);
    uVar2 = _malloc(param_4 * param_5 * iVar1);
    *(undefined4 *)(param_1 + 0x330c) = uVar2;
    *(short *)(param_1 + 0x330a) = (short)param_3;
    ((void (*)())_gleImagingUnpackData)(param_1,param_4,param_5,param_6,param_7,param_3,0x1406,param_8,uVar2);
    ((void (*)())_gleImagingScaleAndBias)(param_1,param_1 + 0x32e8,*(undefined4 *)(param_1 + 0x330c),
               (uint)*(ushort *)(param_1 + 0x330a),0,param_4 * param_5,0);
    return;
  }
  *(undefined4 *)(param_1 + 0x330c) = 0;
  return;
}

/* _gleGetConvolutionFilter @ 0xd3db8 (100 bytes) */
void _gleGetConvolutionFilter(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  
  iVar1 = param_1 + 0x3298;
  if (param_2 != 0x8010) {
    iVar1 = param_1 + 0x32d8;
  }
  if (*(int *)(iVar1 + 0x34) != 0) {
    ((void (*)())_gleImagingPackData)(param_1,*(undefined4 *)(iVar1 + 0x38),*(undefined4 *)(iVar1 + 0x3c),
                        (uint)*(ushort *)(iVar1 + 0x32),0x1406,param_3,param_4,
                        *(int *)(iVar1 + 0x34),param_5);
  }
  return;
}

/* _gleSeparableFilter2D @ 0xd3e1c (340 bytes) */
void _gleSeparableFilter2D(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
{
  int iVar1;
  int iVar2;
  
  iVar1 = _glePixelBytes(param_3,0x1406);
  if (*(int *)(param_1 + 0x334c) != 0) {
    _free(*(int *)(param_1 + 0x334c));
  }
  *(int *)(param_1 + 0x3350) = param_4;
  *(int *)(param_1 + 0x3354) = param_5;
  if ((param_4 != 0) && (param_5 != 0)) {
    iVar2 = _malloc((param_4 + param_5) * iVar1);
    *(int *)(param_1 + 0x334c) = iVar2;
    *(short *)(param_1 + 0x334a) = (short)param_3;
    *(int *)(param_1 + 0x3350) = param_4;
    *(int *)(param_1 + 0x3354) = param_5;
    iVar1 = iVar2 + param_4 * iVar1;
    ((void (*)())_gleImagingUnpackData)(param_1,param_4,1,param_6,param_7,param_3,0x1406,param_8,iVar2);
    ((void (*)())_gleImagingUnpackData)(param_1,param_5,1,param_6,param_7,param_3,0x1406,param_9,iVar1);
    ((void (*)())_gleImagingScaleAndBias)(param_1,param_1 + 0x3328,*(undefined4 *)(param_1 + 0x334c),
               (uint)*(ushort *)(param_1 + 0x334a),0,param_4,0);
    ((void (*)())_gleImagingScaleAndBias)(param_1,param_1 + 0x3328,iVar1,(uint)*(ushort *)(param_1 + 0x334a),0,param_5,0);
    return;
  }
  *(undefined4 *)(param_1 + 0x334c) = 0;
  return;
}

/* _gleGetSeparableFilter @ 0xd3f70 (164 bytes) */
void _gleGetSeparableFilter(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = _glePixelBytes((uint)*(ushort *)(param_1 + 0x334a),0x1406);
  iVar2 = *(int *)(param_1 + 0x3350);
  iVar3 = *(int *)(param_1 + 0x334c);
  ((void (*)())_gleImagingPackData)(param_1,iVar2,1,(uint)*(ushort *)(param_1 + 0x334a),0x1406,param_3,param_4,
                      iVar3,param_5);
  ((void (*)())_gleImagingPackData)(param_1,*(undefined4 *)(param_1 + 0x3354),1,
                      (uint)*(ushort *)(param_1 + 0x334a),0x1406,param_3,param_4,
                      iVar3 + iVar2 * iVar1,param_6);
  return;
}

/* _gleColorTable @ 0xd4014 (128 bytes) */
void _gleColorTable(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  ((void (*)())_gleImagingUnpackData)(param_1,param_4,1,param_5,param_6,(uint)*(ushort *)(param_3 + 0x10),
             (uint)*(ushort *)(param_3 + 0x12),param_7,*(undefined4 *)(param_3 + 0x14));
  ((void (*)())_gleImagingScaleAndBias)(param_1,param_2,*(undefined4 *)(param_3 + 0x14),(uint)*(ushort *)(param_3 + 0x10),0,
             param_4,1);
  return;
}

/* _gleColorSubTable @ 0xd4094 (160 bytes) */
void _gleColorSubTable(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int iVar1;
  
  iVar1 = _glePixelBytes((uint)*(ushort *)(param_3 + 0x10),(uint)*(ushort *)(param_3 + 0x12));
  ((void (*)())_gleImagingUnpackData)(param_1,param_5,1,param_6,param_7,(uint)*(ushort *)(param_3 + 0x10),
             (uint)*(ushort *)(param_3 + 0x12),param_8,*(int *)(param_3 + 0x14) + iVar1 * param_4);
  ((void (*)())_gleImagingScaleAndBias)(param_1,param_2,*(undefined4 *)(param_3 + 0x14),(uint)*(ushort *)(param_3 + 0x10),
             param_4,param_5,1);
  return;
}

/* _gleTransformLightDirection @ 0xd4134 (296 bytes) */
void _gleTransformLightDirection(int param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  bool bVar8;
  
  iVar7 = param_1 + param_2 * 0x80;
  fVar1 = *(float *)(iVar7 + 0x2860);
  fVar2 = *(float *)(iVar7 + 0x2864);
  fVar3 = *(float *)(iVar7 + 0x2868);
  if ((*(uint *)(param_1 + 0x50b0) & 0x10) != 0) {
    fparam_1 = ((double (*)())_gleModelMatInvert)(param_1);
  }
  bVar8 = *(float *)(iVar7 + 0x285c) != FLOAT_00108e50;
  fVar6 = fVar3 * *(float *)(param_1 + 0x22e0) +
          (fVar1 * *(float *)(param_1 + 0x22c0) + fVar2 * *(float *)(param_1 + 0x22d0));
  *(float *)(iVar7 + 0x2860) = fVar6;
  fVar5 = fVar3 * *(float *)(param_1 + 0x22e4) +
          (fVar1 * *(float *)(param_1 + 0x22c4) + fVar2 * *(float *)(param_1 + 0x22d4));
  *(float *)(iVar7 + 0x2864) = fVar5;
  fVar4 = fVar3 * *(float *)(param_1 + 0x22e8) +
          (fVar1 * *(float *)(param_1 + 0x22c8) + fVar2 * *(float *)(param_1 + 0x22d8));
  *(float *)(iVar7 + 0x2868) = fVar4;
  if (bVar8) {
    fVar1 = -(fVar3 * *(float *)(iVar7 + 0x2858) +
             (fVar1 * *(float *)(iVar7 + 0x2850) + fVar2 * *(float *)(iVar7 + 0x2854))) /
            *(float *)(iVar7 + 0x285c);
    *(float *)(iVar7 + 0x2860) = fVar1 * *(float *)(param_1 + 0x22f0) + fVar6;
    *(float *)(iVar7 + 0x2864) = fVar1 * *(float *)(param_1 + 0x22f4) + fVar5;
    *(float *)(iVar7 + 0x2868) = fVar1 * *(float *)(param_1 + 0x22f8) + fVar4;
  }
  ((void (*)())_gleUpdateLightDirection)(param_1,param_2,fparam_1);
  return;
}

/* _gleAddVertexMaterialNoop @ 0xd425c (4 bytes) */
void _gleAddVertexMaterialNoop()
{
  return;
}

/* _gleAddVertexMaterial @ 0xd4260 (132 bytes) */
void _gleAddVertexMaterial(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_2 + 0x74);
  *(undefined4 *)(iVar2 + 0x1e0) = 1;
  if (iVar2 == param_1 + 0x2c20) {
    return;
  }
  if (iVar2 == *(int *)(param_1 + 0x4dd0)) {
    return;
  }
  iVar1 = *(int *)(iVar2 + 0x23c);
  iVar3 = *(int *)(iVar2 + 0x238);
  if (iVar2 == *(int *)(param_1 + 0x4dd8)) {
    *(int *)(param_1 + 0x4dd8) = iVar1;
  }
  else {
    *(int *)(iVar3 + 0x23c) = iVar1;
  }
  if (iVar1 != 0) {
    *(int *)(iVar1 + 0x238) = iVar3;
  }
  iVar3 = *(int *)(param_1 + 0x4dd0);
  iVar1 = *(int *)(iVar3 + 0x23c);
  *(int *)(iVar2 + 0x238) = iVar3;
  *(int *)(iVar2 + 0x23c) = iVar1;
  *(int *)(iVar3 + 0x23c) = iVar2;
  if (iVar1 != 0) {
    *(int *)(iVar1 + 0x238) = iVar2;
  }
  *(undefined1 *)(iVar3 + 0x236) = 1;
  *(undefined1 *)(iVar3 + 0x235) = 0x1f;
  return;
}

/* _gleAddVertexMaterial2Sided @ 0xd42e4 (160 bytes) */
void _gleAddVertexMaterial2Sided(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  piVar2 = (int *)(param_2 + 0x74);
  piVar6 = (int *)(param_1 + 0x4dd0);
  iVar4 = param_1 + 0x2c20;
  iVar3 = 1;
  do {
    iVar1 = *piVar2;
    piVar2 = piVar2 + 1;
    *(undefined4 *)(iVar1 + 0x1e0) = 1;
    if ((iVar1 != iVar4) && (iVar1 != *piVar6)) {
      iVar5 = *(int *)(iVar1 + 0x23c);
      iVar7 = *(int *)(iVar1 + 0x238);
      if (iVar1 == *(int *)(param_1 + 0x4dd8)) {
        *(int *)(param_1 + 0x4dd8) = iVar5;
      }
      else {
        *(int *)(iVar7 + 0x23c) = iVar5;
      }
      if (iVar5 != 0) {
        *(int *)(iVar5 + 0x238) = iVar7;
      }
      iVar7 = *piVar6;
      iVar5 = *(int *)(iVar7 + 0x23c);
      *(int *)(iVar1 + 0x238) = iVar7;
      *(int *)(iVar1 + 0x23c) = iVar5;
      *(int *)(iVar7 + 0x23c) = iVar1;
      if (iVar5 != 0) {
        *(int *)(iVar5 + 0x238) = iVar1;
      }
      *(undefined1 *)(iVar7 + 0x236) = 1;
      *(undefined1 *)(iVar7 + 0x235) = 0x1f;
    }
    iVar3 = iVar3 + -1;
    iVar4 = iVar4 + 0x240;
    piVar6 = piVar6 + 1;
  } while (-1 < iVar3);
  return;
}

/* _gleSetAddVertexMaterialFunc @ 0xd4384 (136 bytes) */
void _gleSetAddVertexMaterialFunc(param_1)
  int param_1;
{
  char cVar1;
  undefined *puVar2;
  
  puVar2 = PTR__gleAddVertexMaterialNoop_00110e40;
  if (*(int *)(param_1 + 0x4e1c) == 0x1c00) {
    if ((*(char *)(param_1 + 0x30aa) == '\0') || (*(char *)(param_1 + 0x7580) != '\0'))
    goto LAB_000d43fc;
    cVar1 = *(char *)(param_1 + 0x30ac);
    puVar2 = PTR__gleAddVertexMaterial_00110e3c;
  }
  else {
    if (*(int *)(param_1 + 0x4e1c) != 0x1c01) goto LAB_000d43fc;
    cVar1 = *(char *)(param_1 + 0x30aa);
  }
  if (cVar1 != '\0') {
    puVar2 = PTR__gleAddVertexMaterial2Sided_00110e38;
  }
LAB_000d43fc:
  *(undefined **)(param_1 + 0x4de4) = puVar2;
                    
                    
  (**(int ( **)(int))(param_1 + 0x4de4))(param_1);
  return;
}

/* _glePopMaterials @ 0xd440c (124 bytes) */
void _glePopMaterials(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = param_1 + 0x2c20;
  piVar4 = (int *)(param_1 + 0x4dd0);
  iVar2 = 1;
  do {
    iVar5 = *piVar4;
    piVar4 = piVar4 + 1;
    iVar7 = *(int *)(iVar5 + 0x23c);
    if (iVar7 != 0) {
      if (*(int *)(iVar7 + 0x23c) != 0) {
        iVar1 = *(int *)(param_1 + 0x4dd8);
        iVar3 = *(int *)(iVar6 + 0x238);
        *(int *)(iVar3 + 0x23c) = iVar1;
        if (iVar1 != 0) {
          *(int *)(iVar1 + 0x238) = iVar3;
        }
        *(int *)(param_1 + 0x4dd8) = iVar7;
        *(int *)(iVar6 + 0x238) = iVar5;
        *(int *)(iVar5 + 0x23c) = iVar6;
      }
      *(undefined1 *)(iVar6 + 0x236) = 1;
    }
    iVar2 = iVar2 + -1;
    *(undefined1 *)(iVar5 + 0x236) = 0;
    *(undefined4 *)(iVar5 + 0x1e0) = 0;
    iVar6 = iVar6 + 0x240;
    *(undefined1 *)(iVar5 + 0x235) = 0;
  } while (-1 < iVar2);
  return;
}

/* _gleMaterialShinePow @ 0xd4488 (176 bytes) */
double _gleMaterialShinePow(undefined4 param_1,int param_2,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  uint uVar1;
  float fVar2;
  int iVar3;
  float dVar4;
  float dVar5;
  
  dVar4 = (double)FLOAT_00108e54;
  if ((double)dVar4 < fparam_1) {
    return (double)((fparam_1 - dVar4) * *(float *)(param_2 + 0x1c) + dVar4);
  }
  if (fparam_1 <= (double)*(float *)(param_2 + 0x10)) {
    return (double)(fparam_1 * *(float *)(param_2 + 0x18));
  }
  fVar2 = (fparam_1 - *(float *)(param_2 + 0x10)) * *(float *)(param_2 + 0x14);
  uVar1 = (uint)(int)fVar2;
  iVar3 = uVar1 * 4 + param_2;
  dVar5 = (double)(fVar2 - (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - DOUBLE_00108d58
                                  ));
  return (double)((dVar4 - dVar5) * *(float *)(iVar3 + 0x20) +
                 (dVar5 * *(float *)(iVar3 + 0x24)));
}

/* _gleLightExponentPow @ 0xd4538 (176 bytes) */
double _gleLightExponentPow(undefined4 param_1,int param_2,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  uint uVar1;
  float fVar2;
  int iVar3;
  float dVar4;
  float dVar5;
  
  dVar4 = (double)FLOAT_00108e54;
  if ((double)dVar4 < fparam_1) {
    return (double)((fparam_1 - dVar4) * *(float *)(param_2 + 0x34) + dVar4);
  }
  if (fparam_1 <= (double)*(float *)(param_2 + 0x28)) {
    return (double)(fparam_1 * *(float *)(param_2 + 0x30));
  }
  fVar2 = (fparam_1 - *(float *)(param_2 + 0x28)) * *(float *)(param_2 + 0x2c);
  uVar1 = (uint)(int)fVar2;
  iVar3 = uVar1 * 4 + param_2;
  dVar5 = (double)(fVar2 - (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - DOUBLE_00108d58
                                  ));
  return (double)((dVar4 - dVar5) * *(float *)(iVar3 + 0x38) +
                 (dVar5 * *(float *)(iVar3 + 0x3c)));
}

/* FUN_000d45ec @ 0xd45ec (1180 bytes) */
void FUN_000d45ec(int param_1,int param_2,int param_3,double fparam_1)
{
  float fVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  int extraout_r3;
  int extraout_r3_00;
  uint uVar5;
  int iVar6;
  float *pfVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  double extraout_f1;
  double extraout_f1_00;
  double dVar14;
  double extraout_f1_01;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  float dVar15;
  float dVar16;
  float dVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  double in_stack_fffffee8;
  double in_stack_fffffef0;
  double in_stack_fffffef8;
  double in_stack_ffffff00;
  double in_stack_ffffff08;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c0;
  float local_bc;
  float local_b8;
  uint local_b0;
  float *local_ac;
  
  iVar6 = 0;
  local_b0 = (uint)*(byte *)(param_1 + 0x30ad);
  uVar5 = *(uint *)(param_1 + 0x30a0);
  iVar4 = param_1;
  if (param_3 < 1) {
    return;
  }
LAB_000d462c:
  if ((*(byte *)(param_2 + 0x7e) & 2) != 0) {
    iVar10 = *(int *)(param_2 + 0x74);
    *(byte *)(param_2 + 0x7e) = *(byte *)(param_2 + 0x7e) & 0xfd;
    if (*(char *)(iVar10 + 0x234) != '\0') {
      iVar4 = _gleUpdateLightRGBASums(param_1,iVar10,0);
      fparam_1 = extraout_f1;
    }
    puVar3 = PTR__gleVectorNormalize_00112064;
    pfVar7 = (float *)(param_2 + 0x20);
    if (*(float *)(param_2 + 0x2c) != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / *(float *)(param_2 + 0x2c);
      pfVar7 = &local_e0;
      local_d8 = *(float *)(param_2 + 0x28) * fVar1;
      local_e0 = *(float *)(param_2 + 0x20) * fVar1;
      local_dc = *(float *)(param_2 + 0x24) * fVar1;
    }
    dVar21 = (double)*(float *)(iVar10 + 0x1d0);
    dVar20 = (double)*(float *)(iVar10 + 0x1d4);
    uVar8 = 0;
    dVar19 = (double)*(float *)(iVar10 + 0x1d8);
    uVar2 = *(undefined4 *)(iVar10 + 0x1dc);
    local_ac = &FLOAT_00108e80;
    dVar15 = (double)FLOAT_00108e54;
    iVar9 = param_1;
    iVar11 = param_1;
    iVar12 = iVar10;
    iVar13 = param_1;
    do {
      if ((uVar5 & 1 << (uVar8 & 0x3f)) == 0) {
        if (uVar5 >> (uVar8 & 0x3f) == 0) goto LAB_000d4a5c;
      }
      else if (*(char *)(iVar13 + 0x4ad8) == '\0') {
        if (*(char *)(iVar13 + 0x4ad9) == '\0') {
          local_d0 = *(float *)(iVar13 + 0x4a70) - *pfVar7;
          local_cc = *(float *)(iVar13 + 0x4a74) - pfVar7[1];
          local_c8 = *(float *)(iVar13 + 0x4a78) - pfVar7[2];
          iVar4 = (**(code **)puVar3)(fparam_1,param_1,&local_d0,&local_d0);
          if ((*(char *)(iVar13 + 0x4adb) != '\0') || (extraout_f1_00 < (double)*local_ac)) {
            dVar22 = (double)*(float *)(iVar13 + 0x4ad4);
          }
          else {
            fVar1 = (float)((double)dVar15 / extraout_f1_00);
            dVar22 = (double)(dVar15 / (*(float *)(iVar11 + 0x2878) * fVar1 * fVar1 +
                                                      (*(float *)(iVar11 + 0x2874) * fVar1 +
                                                      *(float *)(iVar11 + 0x2870))));
          }
        }
        else {
          dVar22 = (double)FLOAT_00108e54;
          local_d0 = *(float *)(iVar13 + 0x4a7c);
          local_cc = *(float *)(iVar13 + 0x4a80);
          local_c8 = *(float *)(iVar13 + 0x4a84);
        }
        if (*(char *)(iVar13 + 0x4ada) != '\0') {
          fparam_1 = -(double)(local_c8 * *(float *)(iVar13 + 0x4a90) +
                              (local_d0 * *(float *)(iVar13 + 0x4a88) +
                              local_cc * *(float *)(iVar13 + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(iVar11 + 0x286c)) goto LAB_000d4a44;
          dVar14 = ((double (*)())_gleLightExponentPow)(iVar4,iVar13 + 0x4a70,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,
                              in_f8,in_stack_fffffee8,in_stack_fffffef0,in_stack_fffffef8,
                              in_stack_ffffff00,in_stack_ffffff08);
          dVar22 = (double)(float)((double)dVar22 * dVar14);
        }
        if (local_b0 == 0) {
          local_b8 = (local_c8 + dVar15);
          local_c0 = local_d0;
          local_bc = local_cc;
        }
        else {
          local_c0 = -*pfVar7;
          local_bc = -pfVar7[1];
          local_b8 = -pfVar7[2];
          (**(code **)puVar3)(param_1,&local_c0,&local_c0);
          local_c0 = local_c0 + local_d0;
          local_bc = local_bc + local_cc;
          local_b8 = local_b8 + local_c8;
        }
        iVar4 = (**(code **)puVar3)(param_1,&local_c0,&local_c0);
        dVar14 = (double)FLOAT_00108e50;
        fparam_1 = extraout_f1_01;
        if ((double)dVar22 != dVar14) {
          in_f8 = (double)*(float *)(param_2 + 0x40);
          in_f7 = (double)*(float *)(param_2 + 0x48);
          dVar17 = (double)*(float *)(iVar12 + 0x50);
          dVar16 = (double)*(float *)(iVar12 + 0x54);
          dVar18 = (double)*(float *)(iVar12 + 0x58);
          fparam_1 = (double)(float)(in_f7 * (double)local_c8 +
                                    (double)(float)(in_f8 * (double)local_d0 +
                                                   (double)(*(float *)(param_2 + 0x44) * local_cc)))
          ;
          if (dVar14 < fparam_1) {
            dVar18 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x68) + (double)dVar18);
            dVar17 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x60) + (double)dVar17);
            dVar16 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 100) + (double)dVar16);
            fparam_1 = (double)(float)(in_f7 * (double)local_b8 +
                                      (double)(float)(in_f8 * (double)local_c0 +
                                                     (double)(*(float *)(param_2 + 0x44) * local_bc)
                                                     ));
            if (dVar14 < fparam_1) {
              in_f2 = (double)*(float *)(iVar10 + 0x40);
              dVar14 = _pow(fparam_1,in_f2);
              fparam_1 = (double)(float)dVar14;
              dVar18 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x78) + (double)dVar18);
              dVar17 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x70) + (double)dVar17);
              dVar16 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x74) + (double)dVar16);
              iVar4 = extraout_r3_00;
            }
          }
          if ((double)dVar22 == (double)dVar15) {
            dVar21 = (double)(dVar21 + dVar17);
            dVar20 = (double)(dVar20 + dVar16);
            dVar19 = (double)(dVar19 + dVar18);
          }
          else {
            dVar19 = (double)(dVar22 * dVar18 + dVar19);
            dVar21 = (double)(dVar22 * dVar17 + dVar21);
            dVar20 = (double)(dVar22 * dVar16 + dVar20);
          }
        }
      }
      else {
        in_f8 = (double)*(float *)(param_2 + 0x48);
        in_f7 = (double)FLOAT_00108e50;
        fparam_1 = (double)(float)(in_f8 * (double)*(float *)(iVar13 + 0x4a84) +
                                  (double)(*(float *)(param_2 + 0x40) * *(float *)(iVar13 + 0x4a7c)
                                          + *(float *)(param_2 + 0x44) * *(float *)(iVar13 + 0x4a80)
                                          ));
        dVar21 = (double)(dVar21 + *(float *)(iVar12 + 0x50));
        dVar20 = (double)(dVar20 + *(float *)(iVar12 + 0x54));
        dVar19 = (double)(dVar19 + *(float *)(iVar12 + 0x58));
        if (in_f7 < fparam_1) {
          dVar21 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x60) + (double)dVar21);
          dVar20 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 100) + (double)dVar20);
          dVar19 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x68) + (double)dVar19);
          fparam_1 = (double)(float)(in_f8 * (double)*(float *)(iVar9 + 0x2888) +
                                    (double)(*(float *)(param_2 + 0x40) * *(float *)(iVar9 + 0x2880)
                                            + *(float *)(param_2 + 0x44) *
                                              *(float *)(iVar9 + 0x2884)));
          if (in_f7 < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar4,iVar10 + 0x1e8,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,
                                  in_f8,in_stack_fffffee8,in_stack_fffffef0,in_stack_fffffef8,
                                  in_stack_ffffff00,in_stack_ffffff08);
            dVar19 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x78) + (double)dVar19);
            dVar21 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x70) + (double)dVar21);
            dVar20 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x74) + (double)dVar20);
            iVar4 = iVar4;
          }
        }
      }
LAB_000d4a44:
      uVar8 = uVar8 + 1;
      iVar13 = iVar13 + 0x6c;
      iVar12 = iVar12 + 0x30;
      iVar9 = iVar9 + 0x80;
      iVar11 = iVar11 + 0x80;
    } while( true );
  }
  goto LAB_000d4a6c;
LAB_000d4a5c:
  *(float *)(param_2 + 0x30) = (float)(double)dVar21;
  *(float *)(param_2 + 0x34) = (float)(double)dVar20;
  *(float *)(param_2 + 0x38) = (float)(double)dVar19;
  *(undefined4 *)(param_2 + 0x3c) = uVar2;
LAB_000d4a6c:
  iVar6 = iVar6 + 1;
  param_2 = param_2 + 0x100;
  if (param_3 <= iVar6) {
    return;
  }
  goto LAB_000d462c;
}

/* FUN_000d4a8c @ 0xd4a8c (1188 bytes) */
void FUN_000d4a8c(int param_1,int param_2,int param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  float fVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  int extraout_r3;
  int extraout_r3_00;
  uint uVar5;
  int iVar6;
  float *pfVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  double extraout_f1;
  double extraout_f1_00;
  double dVar14;
  double extraout_f1_01;
  float dVar15;
  float dVar16;
  float dVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  double in_stack_fffffee8;
  double in_stack_fffffef0;
  double in_stack_fffffef8;
  double in_stack_ffffff00;
  double in_stack_ffffff08;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c0;
  float local_bc;
  float local_b8;
  uint local_b0;
  float *local_ac;
  
  iVar6 = 0;
  local_b0 = (uint)*(byte *)(param_1 + 0x30ad);
  uVar5 = *(uint *)(param_1 + 0x30a0);
  iVar4 = param_1;
  if (param_3 < 1) {
    return;
  }
LAB_000d4acc:
  if ((*(byte *)(param_2 + 0x7e) & 4) != 0) {
    iVar10 = *(int *)(param_2 + 0x78);
    *(byte *)(param_2 + 0x7e) = *(byte *)(param_2 + 0x7e) & 0xfb;
    if (*(char *)(iVar10 + 0x234) != '\0') {
      iVar4 = _gleUpdateLightRGBASums(param_1,iVar10,1);
      fparam_1 = extraout_f1;
    }
    puVar3 = PTR__gleVectorNormalize_00112064;
    pfVar7 = (float *)(param_2 + 0x20);
    if (*(float *)(param_2 + 0x2c) != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / *(float *)(param_2 + 0x2c);
      pfVar7 = &local_e0;
      local_d8 = *(float *)(param_2 + 0x28) * fVar1;
      local_e0 = *(float *)(param_2 + 0x20) * fVar1;
      local_dc = *(float *)(param_2 + 0x24) * fVar1;
    }
    dVar22 = (double)*(float *)(iVar10 + 0x1d0);
    dVar21 = (double)*(float *)(iVar10 + 0x1d4);
    uVar8 = 0;
    dVar20 = (double)*(float *)(iVar10 + 0x1d8);
    uVar2 = *(undefined4 *)(iVar10 + 0x1dc);
    local_ac = &FLOAT_00108e80;
    dVar16 = (double)FLOAT_00108e54;
    iVar9 = param_1;
    iVar11 = param_1;
    iVar12 = iVar10;
    iVar13 = param_1;
    do {
      if ((uVar5 & 1 << (uVar8 & 0x3f)) == 0) {
        if (uVar5 >> (uVar8 & 0x3f) == 0) goto LAB_000d4f04;
      }
      else if (*(char *)(iVar13 + 0x4ad8) == '\0') {
        if (*(char *)(iVar13 + 0x4ad9) == '\0') {
          local_d0 = *(float *)(iVar13 + 0x4a70) - *pfVar7;
          local_cc = *(float *)(iVar13 + 0x4a74) - pfVar7[1];
          local_c8 = *(float *)(iVar13 + 0x4a78) - pfVar7[2];
          iVar4 = (**(code **)puVar3)(fparam_1,param_1,&local_d0,&local_d0);
          if ((*(char *)(iVar13 + 0x4adb) != '\0') || (extraout_f1_00 < (double)*local_ac)) {
            dVar15 = (double)*(float *)(iVar13 + 0x4ad4);
          }
          else {
            fVar1 = (float)((double)dVar16 / extraout_f1_00);
            dVar15 = (double)(dVar16 / (*(float *)(iVar11 + 0x2878) * fVar1 * fVar1 +
                                                      (*(float *)(iVar11 + 0x2874) * fVar1 +
                                                      *(float *)(iVar11 + 0x2870))));
          }
        }
        else {
          dVar15 = (double)FLOAT_00108e54;
          local_d0 = *(float *)(iVar13 + 0x4a7c);
          local_cc = *(float *)(iVar13 + 0x4a80);
          local_c8 = *(float *)(iVar13 + 0x4a84);
        }
        if (*(char *)(iVar13 + 0x4ada) != '\0') {
          fparam_1 = -(double)(local_c8 * *(float *)(iVar13 + 0x4a90) +
                              (local_d0 * *(float *)(iVar13 + 0x4a88) +
                              local_cc * *(float *)(iVar13 + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(iVar11 + 0x286c)) goto LAB_000d4eec;
          dVar14 = ((double (*)())_gleLightExponentPow)(iVar4,iVar13 + 0x4a70,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                              fparam_6,fparam_7,fparam_8,in_stack_fffffee8,in_stack_fffffef0,
                              in_stack_fffffef8,in_stack_ffffff00,in_stack_ffffff08);
          dVar15 = (double)(float)((double)dVar15 * dVar14);
        }
        if (local_b0 == 0) {
          local_b8 = (local_c8 + dVar16);
          local_c0 = local_d0;
          local_bc = local_cc;
        }
        else {
          local_c0 = -*pfVar7;
          local_bc = -pfVar7[1];
          local_b8 = -pfVar7[2];
          (**(code **)puVar3)(param_1,&local_c0,&local_c0);
          local_c0 = local_c0 + local_d0;
          local_bc = local_bc + local_cc;
          local_b8 = local_b8 + local_c8;
        }
        iVar4 = (**(code **)puVar3)(param_1,&local_c0,&local_c0);
        fparam_8 = (double)FLOAT_00108e50;
        fparam_1 = extraout_f1_01;
        if ((double)dVar15 != fparam_8) {
          fparam_7 = (double)*(float *)(param_2 + 0x48);
          dVar18 = (double)*(float *)(iVar12 + 0x50);
          dVar17 = (double)*(float *)(iVar12 + 0x54);
          dVar19 = (double)*(float *)(iVar12 + 0x58);
          dVar14 = (double)(float)(fparam_7 * (double)local_c8 +
                                  (double)(*(float *)(param_2 + 0x40) * local_d0 +
                                          *(float *)(param_2 + 0x44) * local_cc));
          fparam_1 = -dVar14;
          if (fparam_8 < fparam_1) {
            dVar18 = -(double)(float)(dVar14 * (double)*(float *)(iVar12 + 0x60) - (double)dVar18);
            dVar19 = -(double)(float)(dVar14 * (double)*(float *)(iVar12 + 0x68) - (double)dVar19);
            fparam_1 = -(double)(float)(fparam_7 * (double)local_b8 +
                                       (double)(*(float *)(param_2 + 0x40) * local_c0 +
                                               *(float *)(param_2 + 0x44) * local_bc));
            dVar17 = -(double)(float)(dVar14 * (double)*(float *)(iVar12 + 100) - (double)dVar17);
            if (fparam_8 < fparam_1) {
              fparam_2 = (double)*(float *)(iVar10 + 0x40);
              dVar14 = _pow(fparam_1,fparam_2);
              fparam_1 = (double)(float)dVar14;
              dVar19 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x78) + (double)dVar19);
              dVar18 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x70) + (double)dVar18);
              dVar17 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x74) + (double)dVar17);
              iVar4 = extraout_r3_00;
            }
          }
          if ((double)dVar15 == (double)dVar16) {
            dVar22 = (double)(dVar22 + dVar18);
            dVar21 = (double)(dVar21 + dVar17);
            dVar20 = (double)(dVar20 + dVar19);
          }
          else {
            dVar20 = (double)(dVar15 * dVar19 + dVar20);
            dVar22 = (double)(dVar15 * dVar18 + dVar22);
            dVar21 = (double)(dVar15 * dVar17 + dVar21);
          }
        }
      }
      else {
        fparam_8 = (double)*(float *)(param_2 + 0x48);
        fparam_7 = (double)FLOAT_00108e50;
        dVar15 = (double)(float)(fparam_8 * (double)*(float *)(iVar13 + 0x4a84) +
                                (double)(*(float *)(param_2 + 0x40) * *(float *)(iVar13 + 0x4a7c) +
                                        *(float *)(param_2 + 0x44) * *(float *)(iVar13 + 0x4a80)));
        dVar22 = (double)(dVar22 + *(float *)(iVar12 + 0x50));
        dVar21 = (double)(dVar21 + *(float *)(iVar12 + 0x54));
        fparam_1 = -(double)dVar15;
        dVar20 = (double)(dVar20 + *(float *)(iVar12 + 0x58));
        if (fparam_7 < fparam_1) {
          dVar22 = -(double)(dVar15 * *(float *)(iVar12 + 0x60) - dVar22);
          dVar21 = -(double)(dVar15 * *(float *)(iVar12 + 100) - dVar21);
          fparam_1 = -(double)(float)(fparam_8 * (double)*(float *)(iVar9 + 0x2888) +
                                     (double)(*(float *)(param_2 + 0x40) *
                                              *(float *)(iVar9 + 0x2880) +
                                             *(float *)(param_2 + 0x44) * *(float *)(iVar9 + 0x2884)
                                             ));
          dVar20 = -(double)(dVar15 * *(float *)(iVar12 + 0x68) - dVar20);
          if (fparam_7 < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar4,iVar10 + 0x1e8,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                                  fparam_6,fparam_7,fparam_8,in_stack_fffffee8,in_stack_fffffef0,
                                  in_stack_fffffef8,in_stack_ffffff00,in_stack_ffffff08);
            dVar20 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x78) + (double)dVar20);
            dVar22 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x70) + (double)dVar22);
            dVar21 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x74) + (double)dVar21);
            iVar4 = iVar4;
          }
        }
      }
LAB_000d4eec:
      uVar8 = uVar8 + 1;
      iVar13 = iVar13 + 0x6c;
      iVar12 = iVar12 + 0x30;
      iVar9 = iVar9 + 0x80;
      iVar11 = iVar11 + 0x80;
    } while( true );
  }
  goto LAB_000d4f14;
LAB_000d4f04:
  *(float *)(param_2 + 0x30) = (float)(double)dVar22;
  *(float *)(param_2 + 0x34) = (float)(double)dVar21;
  *(float *)(param_2 + 0x38) = (float)(double)dVar20;
  *(undefined4 *)(param_2 + 0x3c) = uVar2;
LAB_000d4f14:
  iVar6 = iVar6 + 1;
  param_2 = param_2 + 0x100;
  if (param_3 <= iVar6) {
    return;
  }
  goto LAB_000d4acc;
}

/* _gleVtxLightSpecRGBAFront @ 0xd4f30 (1632 bytes) */
void _gleVtxLightSpecRGBAFront(int param_1,int param_2,int param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11)
{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int iVar6;
  int extraout_r3;
  int extraout_r3_00;
  int extraout_r3_01;
  uint uVar7;
  int iVar8;
  float *pfVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  double dVar16;
  float dVar17;
  double dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  float dVar23;
  float dVar24;
  float dVar25;
  float dVar26;
  float dVar27;
  float dVar28;
  float dVar29;
  int iStack00000020;
  double in_stack_fffffea8;
  double in_stack_fffffeb0;
  double in_stack_fffffeb8;
  double in_stack_fffffec0;
  double in_stack_fffffec8;
  float local_120;
  float local_11c;
  float local_118;
  float local_110;
  float local_10c;
  float local_108;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e0;
  float local_dc;
  float local_d8;
  uint local_d0;
  
  iVar8 = 0;
  local_d0 = (uint)*(byte *)(param_1 + 0x30ad);
  uVar7 = *(uint *)(param_1 + 0x30a0);
  iVar6 = param_1;
  iStack00000020 = param_3;
  if (param_3 < 1) {
    return;
  }
LAB_000d4f74:
  if ((*(byte *)(param_2 + 0x7e) & 2) != 0) {
    iVar13 = *(int *)(param_2 + 0x74);
    *(byte *)(param_2 + 0x7e) = *(byte *)(param_2 + 0x7e) & 0xfd;
    if (*(char *)(iVar13 + 0x234) != '\0') {
      iVar6 = _gleUpdateLightRGBASums(param_1,iVar13,0);
      fparam_1 = extraout_f1;
    }
    pfVar9 = (float *)(param_2 + 0x20);
    if (*(float *)(param_2 + 0x2c) != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / *(float *)(param_2 + 0x2c);
      pfVar9 = &local_120;
      local_118 = *(float *)(param_2 + 0x28) * fVar1;
      local_120 = *(float *)(param_2 + 0x20) * fVar1;
      local_11c = *(float *)(param_2 + 0x24) * fVar1;
    }
    if (*(char *)(param_1 + 0x30ae) != '\0') {
      if ((local_d0 == 0) || (*(int *)(param_1 + 0x4ddc) == 0)) {
        local_10c = 0.0;
        local_108 = 1.0;
        local_110 = 0.0;
      }
      else {
        local_110 = -*pfVar9;
        local_10c = -pfVar9[1];
        local_108 = -pfVar9[2];
        iVar6 = (**(code **)PTR__gleVectorNormalize_00112064)
                          (fparam_1,param_1,&local_110,&local_110);
        fparam_1 = extraout_f1_00;
      }
    }
    puVar5 = PTR__gleVectorNormalize_00112064;
    dVar22 = (double)FLOAT_00108e50;
    dVar29 = (double)*(float *)(iVar13 + 0x1d0);
    uVar10 = 0;
    dVar28 = (double)*(float *)(iVar13 + 0x1d4);
    dVar27 = (double)*(float *)(iVar13 + 0x1d8);
    uVar4 = *(undefined4 *)(iVar13 + 0x1dc);
    dVar19 = (double)FLOAT_00108e54;
    iVar11 = param_1;
    iVar12 = param_1;
    iVar14 = iVar13;
    iVar15 = param_1;
    dVar20 = (double)dVar22;
    dVar21 = (double)dVar22;
    dVar23 = (double)dVar22;
    do {
      if ((uVar7 & 1 << (uVar10 & 0x3f)) == 0) {
        if (uVar7 >> (uVar10 & 0x3f) == 0) goto LAB_000d5530;
      }
      else if (*(char *)(iVar15 + 0x4ad8) == '\0') {
        if (*(char *)(iVar15 + 0x4ad9) == '\0') {
          local_100 = *(float *)(iVar15 + 0x4a70) - *pfVar9;
          local_fc = *(float *)(iVar15 + 0x4a74) - pfVar9[1];
          local_f8 = *(float *)(iVar15 + 0x4a78) - pfVar9[2];
          iVar6 = (**(code **)puVar5)(param_1,&local_100,&local_100);
          if ((*(char *)(iVar15 + 0x4adb) != '\0') || (extraout_f1_01 < (double)FLOAT_00108e80)) {
            dVar18 = (double)*(float *)(iVar15 + 0x4ad4);
            fparam_1 = extraout_f1_01;
          }
          else {
            fparam_1 = (double)(float)((double)dVar19 / extraout_f1_01);
            dVar18 = (double)(dVar19 / (float)((double)(float)((double)*(float *)(
                                                  iVar12 + 0x2878) * fparam_1) * fparam_1 +
                                                  (double)(float)((double)*(float *)(iVar12 + 0x2874
                                                                                    ) * fparam_1 +
                                                                 (double)*(float *)(iVar12 + 0x2870)
                                                                 )));
          }
        }
        else {
          dVar18 = (double)FLOAT_00108e54;
          local_100 = *(float *)(iVar15 + 0x4a7c);
          local_fc = *(float *)(iVar15 + 0x4a80);
          local_f8 = *(float *)(iVar15 + 0x4a84);
        }
        if (*(char *)(iVar15 + 0x4ada) != '\0') {
          fparam_1 = -(double)(local_f8 * *(float *)(iVar15 + 0x4a90) +
                              (local_100 * *(float *)(iVar15 + 0x4a88) +
                              local_fc * *(float *)(iVar15 + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(iVar12 + 0x286c)) goto LAB_000d5518;
          fparam_1 = ((double (*)())_gleLightExponentPow)(iVar6,iVar15 + 0x4a70,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                                fparam_6,fparam_7,fparam_8,in_stack_fffffea8,in_stack_fffffeb0,
                                in_stack_fffffeb8,in_stack_fffffec0,in_stack_fffffec8);
          dVar18 = (double)(float)(dVar18 * fparam_1);
          iVar6 = iVar6;
        }
        if (*(char *)(param_1 + 0x30ae) == '\0') {
          if (local_d0 == 0) {
            local_108 = (local_f8 + dVar19);
            local_110 = local_100;
            local_10c = local_fc;
          }
          else {
            local_110 = -*pfVar9;
            local_10c = -pfVar9[1];
            local_108 = -pfVar9[2];
            (**(code **)puVar5)(param_1,&local_110,&local_110);
            local_110 = local_110 + local_100;
            local_10c = local_10c + local_fc;
            local_108 = local_108 + local_f8;
          }
          iVar6 = (**(code **)puVar5)(param_1,&local_110,&local_110);
          fparam_1 = extraout_f1_02;
        }
        if (dVar18 != (double)FLOAT_00108e50) {
          fparam_4 = (double)*(float *)(param_2 + 0x44);
          dVar26 = (double)local_fc;
          fparam_5 = (double)*(float *)(param_2 + 0x40);
          fparam_3 = (double)local_100;
          fparam_6 = (double)*(float *)(param_2 + 0x48);
          fparam_2 = (double)local_f8;
          dVar25 = (double)*(float *)(iVar14 + 0x50);
          dVar24 = (double)*(float *)(iVar14 + 0x54);
          dVar17 = (double)*(float *)(iVar14 + 0x58);
          dVar16 = (double)(float)(fparam_6 * fparam_2 +
                                  (double)(float)(fparam_5 * fparam_3 +
                                                 (double)(float)(fparam_4 * (double)dVar26)));
          if (dVar16 <= (double)FLOAT_00108e50) {
LAB_000d54cc:
            dVar26 = (double)FLOAT_00108e50;
            fparam_1 = (double)dVar26;
            dVar16 = (double)dVar26;
          }
          else {
            dVar25 = (double)(float)(dVar16 * (double)*(float *)(iVar14 + 0x60) + (double)dVar25);
            dVar24 = (double)(float)(dVar16 * (double)*(float *)(iVar14 + 100) + (double)dVar24);
            dVar17 = (double)(float)(dVar16 * (double)*(float *)(iVar14 + 0x68) + (double)dVar17);
            if (*(char *)(param_1 + 0x30ae) == '\0') {
              fVar1 = (float)(fparam_6 * (double)local_108 +
                             (double)(float)(fparam_5 * (double)local_110 +
                                            (double)(float)(fparam_4 * (double)local_10c)));
            }
            else {
              local_e8 = (float)(fparam_5 * (double)dVar26 - (double)(float)(fparam_4 * fparam_3));
              fparam_7 = (double)local_e8;
              local_f0 = (float)(fparam_4 * fparam_2 - (double)(float)(fparam_6 * (double)dVar26));
              dVar16 = (double)local_f0;
              local_ec = (float)(fparam_6 * fparam_3 - (double)(float)(fparam_5 * fparam_2));
              fparam_8 = (double)local_ec;
              fVar1 = (float)(fparam_6 * dVar16 - (double)(float)(fparam_5 * fparam_7));
              fVar2 = (float)(fparam_5 * fparam_8 - (double)(float)(fparam_4 * dVar16));
              fVar3 = (float)(fparam_4 * fparam_7 - (double)(float)(fparam_6 * fparam_8));
              local_dc = ((fVar1 + fVar1) + dVar26);
              local_d8 = (float)((double)(fVar2 + fVar2) + fparam_2);
              local_e0 = (float)((double)(fVar3 + fVar3) + fparam_3);
              fVar1 = local_d8 * local_108 + (local_e0 * local_110 + local_dc * local_10c);
            }
            if ((double)fVar1 <= (double)dVar22) goto LAB_000d54cc;
            fparam_2 = (double)*(float *)(iVar13 + 0x40);
            dVar16 = _pow((double)fVar1,fparam_2);
            fVar1 = (float)dVar16;
            dVar26 = (double)(fVar1 * *(float *)(iVar14 + 0x78));
            iVar6 = extraout_r3_01;
            fparam_1 = (double)(fVar1 * *(float *)(iVar14 + 0x74));
            dVar16 = (double)(fVar1 * *(float *)(iVar14 + 0x70));
          }
          if (dVar18 == (double)dVar19) {
            dVar29 = (double)(dVar29 + dVar25);
            dVar28 = (double)(dVar28 + dVar24);
            dVar27 = (double)(dVar27 + dVar17);
            dVar23 = (double)(float)((double)dVar23 + dVar16);
            dVar21 = (double)(float)((double)dVar21 + fparam_1);
            dVar20 = (double)(dVar20 + dVar26);
          }
          else {
            dVar20 = (double)(float)(dVar18 * (double)dVar26 + (double)dVar20);
            dVar29 = (double)(float)(dVar18 * (double)dVar25 + (double)dVar29);
            dVar28 = (double)(float)(dVar18 * (double)dVar24 + (double)dVar28);
            dVar27 = (double)(float)(dVar18 * (double)dVar17 + (double)dVar27);
            dVar23 = (double)(float)(dVar18 * dVar16 + (double)dVar23);
            dVar21 = (double)(float)(dVar18 * fparam_1 + (double)dVar21);
          }
        }
      }
      else {
        dVar16 = (double)*(float *)(param_2 + 0x44);
        fparam_7 = (double)*(float *)(iVar15 + 0x4a80);
        fparam_8 = (double)*(float *)(param_2 + 0x40);
        dVar17 = (double)*(float *)(param_2 + 0x48);
        dVar18 = (double)*(float *)(iVar15 + 0x4a84);
        dVar29 = (double)(dVar29 + *(float *)(iVar14 + 0x50));
        fparam_1 = (double)(float)((double)dVar17 * dVar18 +
                                  (double)(float)(fparam_8 * (double)*(float *)(iVar15 + 0x4a7c) +
                                                 (double)(float)(dVar16 * fparam_7)));
        dVar28 = (double)(dVar28 + *(float *)(iVar14 + 0x54));
        dVar27 = (double)(dVar27 + *(float *)(iVar14 + 0x58));
        if ((double)dVar22 < fparam_1) {
          dVar29 = (double)(float)(fparam_1 * (double)*(float *)(iVar14 + 0x60) + (double)dVar29);
          dVar28 = (double)(float)(fparam_1 * (double)*(float *)(iVar14 + 100) + (double)dVar28);
          dVar27 = (double)(float)(fparam_1 * (double)*(float *)(iVar14 + 0x68) + (double)dVar27);
          if (*(char *)(param_1 + 0x30ae) == '\0') {
            dVar18 = (double)dVar17 * (double)*(float *)(iVar11 + 0x2888) +
                     (double)(float)(fparam_8 * (double)*(float *)(iVar11 + 0x2880) +
                                    (double)(float)(dVar16 * (double)*(float *)(iVar11 + 0x2884)));
          }
          else {
            local_f8 = *(float *)(iVar15 + 0x4a84);
            local_100 = (float)(dVar16 * dVar18 - (double)(float)((double)dVar17 * fparam_7));
            local_fc = (dVar17 * *(float *)(iVar15 + 0x4a7c) - (float)(fparam_8 * dVar18));
            fVar1 = (float)(fparam_8 * (double)local_fc -
                           (double)(float)(dVar16 * (double)local_100));
            dVar18 = (double)(fVar1 + fVar1) + dVar18;
          }
          fparam_1 = (double)(float)dVar18;
          if ((double)dVar22 < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar6,iVar13 + 0x1e8,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                                  fparam_6,fparam_7,fparam_8,in_stack_fffffea8,in_stack_fffffeb0,
                                  in_stack_fffffeb8,in_stack_fffffec0,in_stack_fffffec8);
            dVar20 = (double)(float)(fparam_1 * (double)*(float *)(iVar14 + 0x78) + (double)dVar20);
            dVar23 = (double)(float)(fparam_1 * (double)*(float *)(iVar14 + 0x70) + (double)dVar23);
            dVar21 = (double)(float)(fparam_1 * (double)*(float *)(iVar14 + 0x74) + (double)dVar21);
            iVar6 = iVar6;
          }
        }
      }
LAB_000d5518:
      uVar10 = uVar10 + 1;
      iVar15 = iVar15 + 0x6c;
      iVar14 = iVar14 + 0x30;
      iVar11 = iVar11 + 0x80;
      iVar12 = iVar12 + 0x80;
    } while( true );
  }
  goto LAB_000d5570;
LAB_000d5530:
  if (*(short *)(param_1 + 0x30a8) == -0x7e06) {
    *(float *)(param_2 + 0x50) = (float)(double)dVar23;
    *(float *)(param_2 + 0x54) = (float)(double)dVar21;
    *(float *)(param_2 + 0x58) = (float)(double)dVar20;
  }
  else {
    dVar29 = (double)(dVar29 + dVar23);
    dVar28 = (double)(dVar28 + dVar21);
    dVar27 = (double)(dVar27 + dVar20);
  }
  *(float *)(param_2 + 0x30) = (float)(double)dVar29;
  *(float *)(param_2 + 0x34) = (float)(double)dVar28;
  *(float *)(param_2 + 0x38) = (float)(double)dVar27;
  *(undefined4 *)(param_2 + 0x3c) = uVar4;
LAB_000d5570:
  iVar8 = iVar8 + 1;
  param_2 = param_2 + 0x100;
  if (iStack00000020 <= iVar8) {
    return;
  }
  goto LAB_000d4f74;
}

/* _gleVtxLightSpecRGBABack @ 0xd5590 (1640 bytes) */
void _gleVtxLightSpecRGBABack(int param_1,int param_2,int param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11)
{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  undefined *puVar5;
  int iVar6;
  int extraout_r3;
  int extraout_r3_00;
  int extraout_r3_01;
  uint uVar7;
  int iVar8;
  float *pfVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  float dVar16;
  double dVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  float dVar23;
  float dVar24;
  float dVar25;
  float dVar26;
  float dVar27;
  float dVar28;
  float dVar29;
  int iStack00000020;
  double in_stack_fffffea8;
  double in_stack_fffffeb0;
  double in_stack_fffffeb8;
  double in_stack_fffffec0;
  double in_stack_fffffec8;
  float local_120;
  float local_11c;
  float local_118;
  float local_110;
  float local_10c;
  float local_108;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e0;
  float local_dc;
  float local_d8;
  uint local_d0;
  
  iVar8 = 0;
  local_d0 = (uint)*(byte *)(param_1 + 0x30ad);
  uVar7 = *(uint *)(param_1 + 0x30a0);
  iVar6 = param_1;
  iStack00000020 = param_3;
  if (param_3 < 1) {
    return;
  }
LAB_000d55d4:
  if ((*(byte *)(param_2 + 0x7e) & 4) != 0) {
    iVar13 = *(int *)(param_2 + 0x78);
    *(byte *)(param_2 + 0x7e) = *(byte *)(param_2 + 0x7e) & 0xfb;
    if (*(char *)(iVar13 + 0x234) != '\0') {
      iVar6 = _gleUpdateLightRGBASums(param_1,iVar13,1);
      fparam_1 = extraout_f1;
    }
    pfVar9 = (float *)(param_2 + 0x20);
    if (*(float *)(param_2 + 0x2c) != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / *(float *)(param_2 + 0x2c);
      pfVar9 = &local_120;
      local_118 = *(float *)(param_2 + 0x28) * fVar1;
      local_120 = *(float *)(param_2 + 0x20) * fVar1;
      local_11c = *(float *)(param_2 + 0x24) * fVar1;
    }
    if (*(char *)(param_1 + 0x30ae) != '\0') {
      if ((local_d0 == 0) || (*(int *)(param_1 + 0x4ddc) == 0)) {
        local_10c = 0.0;
        local_108 = 1.0;
        local_110 = 0.0;
      }
      else {
        local_110 = -*pfVar9;
        local_10c = -pfVar9[1];
        local_108 = -pfVar9[2];
        iVar6 = (**(code **)PTR__gleVectorNormalize_00112064)
                          (fparam_1,param_1,&local_110,&local_110);
        fparam_1 = extraout_f1_00;
      }
    }
    puVar5 = PTR__gleVectorNormalize_00112064;
    dVar22 = (double)FLOAT_00108e50;
    dVar29 = (double)*(float *)(iVar13 + 0x1d0);
    uVar10 = 0;
    dVar28 = (double)*(float *)(iVar13 + 0x1d4);
    dVar27 = (double)*(float *)(iVar13 + 0x1d8);
    uVar4 = *(undefined4 *)(iVar13 + 0x1dc);
    dVar19 = (double)FLOAT_00108e54;
    iVar11 = param_1;
    iVar12 = param_1;
    iVar14 = iVar13;
    iVar15 = param_1;
    dVar20 = (double)dVar22;
    dVar21 = (double)dVar22;
    dVar23 = (double)dVar22;
    do {
      if ((uVar7 & 1 << (uVar10 & 0x3f)) == 0) {
        if (uVar7 >> (uVar10 & 0x3f) == 0) goto LAB_000d5b98;
      }
      else if (*(char *)(iVar15 + 0x4ad8) == '\0') {
        if (*(char *)(iVar15 + 0x4ad9) == '\0') {
          local_100 = *(float *)(iVar15 + 0x4a70) - *pfVar9;
          local_fc = *(float *)(iVar15 + 0x4a74) - pfVar9[1];
          local_f8 = *(float *)(iVar15 + 0x4a78) - pfVar9[2];
          iVar6 = (**(code **)puVar5)(param_1,&local_100,&local_100);
          if ((*(char *)(iVar15 + 0x4adb) != '\0') || (extraout_f1_01 < (double)FLOAT_00108e80)) {
            dVar16 = (double)*(float *)(iVar15 + 0x4ad4);
            fparam_1 = extraout_f1_01;
          }
          else {
            fparam_1 = (double)(float)((double)dVar19 / extraout_f1_01);
            dVar16 = (double)(dVar19 / (float)((double)(float)((double)*(float *)(
                                                  iVar12 + 0x2878) * fparam_1) * fparam_1 +
                                                  (double)(float)((double)*(float *)(iVar12 + 0x2874
                                                                                    ) * fparam_1 +
                                                                 (double)*(float *)(iVar12 + 0x2870)
                                                                 )));
          }
        }
        else {
          dVar16 = (double)FLOAT_00108e54;
          local_100 = *(float *)(iVar15 + 0x4a7c);
          local_fc = *(float *)(iVar15 + 0x4a80);
          local_f8 = *(float *)(iVar15 + 0x4a84);
        }
        if (*(char *)(iVar15 + 0x4ada) != '\0') {
          fparam_1 = -(double)(local_f8 * *(float *)(iVar15 + 0x4a90) +
                              (local_100 * *(float *)(iVar15 + 0x4a88) +
                              local_fc * *(float *)(iVar15 + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(iVar12 + 0x286c)) goto LAB_000d5b80;
          fparam_1 = ((double (*)())_gleLightExponentPow)(iVar6,iVar15 + 0x4a70,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                                fparam_6,fparam_7,fparam_8,in_stack_fffffea8,in_stack_fffffeb0,
                                in_stack_fffffeb8,in_stack_fffffec0,in_stack_fffffec8);
          dVar16 = (double)(float)((double)dVar16 * fparam_1);
          iVar6 = iVar6;
        }
        if (*(char *)(param_1 + 0x30ae) == '\0') {
          if (local_d0 == 0) {
            local_108 = (local_f8 + dVar19);
            local_110 = local_100;
            local_10c = local_fc;
          }
          else {
            local_110 = -*pfVar9;
            local_10c = -pfVar9[1];
            local_108 = -pfVar9[2];
            (**(code **)puVar5)(param_1,&local_110,&local_110);
            local_110 = local_110 + local_100;
            local_10c = local_10c + local_fc;
            local_108 = local_108 + local_f8;
          }
          iVar6 = (**(code **)puVar5)(param_1,&local_110,&local_110);
          fparam_1 = extraout_f1_02;
        }
        if ((double)dVar16 != (double)FLOAT_00108e50) {
          fparam_4 = (double)*(float *)(param_2 + 0x44);
          dVar26 = (double)local_fc;
          fparam_5 = (double)*(float *)(param_2 + 0x40);
          fparam_3 = (double)local_100;
          fparam_6 = (double)*(float *)(param_2 + 0x48);
          fparam_2 = (double)local_f8;
          dVar25 = (double)*(float *)(iVar14 + 0x50);
          dVar24 = (double)*(float *)(iVar14 + 0x54);
          dVar18 = (double)*(float *)(iVar14 + 0x58);
          dVar17 = (double)(float)(fparam_6 * fparam_2 +
                                  (double)(float)(fparam_5 * fparam_3 +
                                                 (double)(float)(fparam_4 * (double)dVar26)));
          if (-dVar17 <= (double)FLOAT_00108e50) {
LAB_000d5b34:
            dVar26 = (double)FLOAT_00108e50;
            fparam_1 = (double)dVar26;
            dVar17 = (double)dVar26;
          }
          else {
            dVar25 = -(double)(float)(dVar17 * (double)*(float *)(iVar14 + 0x60) - (double)dVar25);
            dVar24 = -(double)(float)(dVar17 * (double)*(float *)(iVar14 + 100) - (double)dVar24);
            dVar18 = -(double)(float)(dVar17 * (double)*(float *)(iVar14 + 0x68) - (double)dVar18);
            if (*(char *)(param_1 + 0x30ae) == '\0') {
              dVar17 = -(double)(float)(fparam_6 * (double)local_108 +
                                       (double)(float)(fparam_5 * (double)local_110 +
                                                      (double)(float)(fparam_4 * (double)local_10c))
                                       );
            }
            else {
              local_f0 = (float)(fparam_6 * (double)dVar26 - (double)(float)(fparam_4 * fparam_2));
              dVar17 = (double)local_f0;
              local_e8 = (float)(fparam_4 * fparam_3 - (double)(float)(fparam_5 * (double)dVar26));
              fparam_7 = (double)local_e8;
              local_ec = (float)(fparam_5 * fparam_2 - (double)(float)(fparam_6 * fparam_3));
              fparam_8 = (double)local_ec;
              fVar1 = (float)(fparam_5 * fparam_7 - (double)(float)(fparam_6 * dVar17));
              fVar2 = (float)(fparam_6 * fparam_8 - (double)(float)(fparam_4 * fparam_7));
              fVar3 = (float)(fparam_4 * dVar17 - (double)(float)(fparam_5 * fparam_8));
              local_dc = ((fVar1 + fVar1) + dVar26);
              local_e0 = (float)((double)(fVar2 + fVar2) + fparam_3);
              local_d8 = (float)((double)(fVar3 + fVar3) + fparam_2);
              dVar17 = (double)(local_d8 * local_108 + (local_e0 * local_110 + local_dc * local_10c));
            }
            if (dVar17 <= (double)dVar22) goto LAB_000d5b34;
            fparam_2 = (double)*(float *)(iVar13 + 0x40);
            dVar17 = _pow(dVar17,fparam_2);
            fVar1 = (float)dVar17;
            dVar26 = (double)(fVar1 * *(float *)(iVar14 + 0x78));
            iVar6 = extraout_r3_01;
            fparam_1 = (double)(fVar1 * *(float *)(iVar14 + 0x74));
            dVar17 = (double)(fVar1 * *(float *)(iVar14 + 0x70));
          }
          if ((double)dVar16 == (double)dVar19) {
            dVar29 = (double)(dVar29 + dVar25);
            dVar28 = (double)(dVar28 + dVar24);
            dVar27 = (double)(dVar27 + dVar18);
            dVar23 = (double)(float)((double)dVar23 + dVar17);
            dVar21 = (double)(float)((double)dVar21 + fparam_1);
            dVar20 = (double)(dVar20 + dVar26);
          }
          else {
            dVar20 = (double)(dVar16 * dVar26 + dVar20);
            dVar29 = (double)(dVar16 * dVar25 + dVar29);
            dVar28 = (double)(dVar16 * dVar24 + dVar28);
            dVar27 = (double)(dVar16 * dVar18 + dVar27);
            dVar23 = (double)(float)((double)dVar16 * dVar17 + (double)dVar23);
            dVar21 = (double)(float)((double)dVar16 * fparam_1 + (double)dVar21);
          }
        }
      }
      else {
        fparam_7 = (double)*(float *)(param_2 + 0x44);
        fparam_6 = (double)*(float *)(iVar15 + 0x4a80);
        fparam_8 = (double)*(float *)(param_2 + 0x40);
        dVar16 = (double)*(float *)(param_2 + 0x48);
        dVar17 = (double)*(float *)(iVar15 + 0x4a84);
        dVar29 = (double)(dVar29 + *(float *)(iVar14 + 0x50));
        dVar18 = (double)(float)((double)dVar16 * dVar17 +
                                (double)(float)(fparam_8 * (double)*(float *)(iVar15 + 0x4a7c) +
                                               (double)(float)(fparam_7 * fparam_6)));
        dVar28 = (double)(dVar28 + *(float *)(iVar14 + 0x54));
        dVar27 = (double)(dVar27 + *(float *)(iVar14 + 0x58));
        fparam_1 = -(double)dVar18;
        if ((double)dVar22 < fparam_1) {
          dVar29 = -(double)(dVar18 * *(float *)(iVar14 + 0x60) - dVar29);
          dVar28 = -(double)(dVar18 * *(float *)(iVar14 + 100) - dVar28);
          dVar27 = -(double)(dVar18 * *(float *)(iVar14 + 0x68) - dVar27);
          if (*(char *)(param_1 + 0x30ae) == '\0') {
            fparam_1 = -(double)(dVar16 * *(float *)(iVar11 + 0x2888) + (float)(fparam_8 *
                                                       (double)*(float *)(iVar11 + 0x2880) +
                                                      (double)(float)(fparam_7 *
                                                                     (double)*(float *)(iVar11 + 
                                                  0x2884))));
          }
          else {
            local_f8 = *(float *)(iVar15 + 0x4a84);
            local_100 = (float)((double)dVar16 * fparam_6 - (double)(float)(fparam_7 * dVar17));
            local_fc = (float)(fparam_8 * dVar17 -
                              (double)(dVar16 * *(float *)(iVar15 + 0x4a7c)));
            fVar1 = (float)(fparam_7 * (double)local_100 -
                           (double)(float)(fparam_8 * (double)local_fc));
            fparam_1 = (double)(float)((double)(fVar1 + fVar1) + dVar17);
          }
          if ((double)dVar22 < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar6,iVar13 + 0x1e8,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                                  fparam_6,fparam_7,fparam_8,in_stack_fffffea8,in_stack_fffffeb0,
                                  in_stack_fffffeb8,in_stack_fffffec0,in_stack_fffffec8);
            dVar27 = (double)(float)(fparam_1 * (double)*(float *)(iVar14 + 0x78) + (double)dVar27);
            dVar29 = (double)(float)(fparam_1 * (double)*(float *)(iVar14 + 0x70) + (double)dVar29);
            dVar28 = (double)(float)(fparam_1 * (double)*(float *)(iVar14 + 0x74) + (double)dVar28);
            iVar6 = iVar6;
          }
        }
      }
LAB_000d5b80:
      uVar10 = uVar10 + 1;
      iVar15 = iVar15 + 0x6c;
      iVar14 = iVar14 + 0x30;
      iVar11 = iVar11 + 0x80;
      iVar12 = iVar12 + 0x80;
    } while( true );
  }
  goto LAB_000d5bd8;
LAB_000d5b98:
  if (*(short *)(param_1 + 0x30a8) == -0x7e06) {
    *(float *)(param_2 + 0x50) = (float)(double)dVar23;
    *(float *)(param_2 + 0x54) = (float)(double)dVar21;
    *(float *)(param_2 + 0x58) = (float)(double)dVar20;
  }
  else {
    dVar29 = (double)(dVar29 + dVar23);
    dVar28 = (double)(dVar28 + dVar21);
    dVar27 = (double)(dVar27 + dVar20);
  }
  *(float *)(param_2 + 0x30) = (float)(double)dVar29;
  *(float *)(param_2 + 0x34) = (float)(double)dVar28;
  *(float *)(param_2 + 0x38) = (float)(double)dVar27;
  *(undefined4 *)(param_2 + 0x3c) = uVar4;
LAB_000d5bd8:
  iVar8 = iVar8 + 1;
  param_2 = param_2 + 0x100;
  if (iStack00000020 <= iVar8) {
    return;
  }
  goto LAB_000d55d4;
}

/* _gleVtxLightFastRGBAFront @ 0xd5bf8 (372 bytes) */
void _gleVtxLightFastRGBAFront(int param_1,int param_2,int param_3,double fparam_1)
{
  undefined4 uVar1;
  int iVar2;
  int extraout_r3;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  double dVar10;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double fparam_7;
  double fparam_8;
  float dVar11;
  float dVar12;
  float dVar13;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  double in_stack_ffffff88;
  double in_stack_ffffff90;
  double in_stack_ffffff98;
  
  iVar3 = 0;
  uVar4 = *(uint *)(param_1 + 0x30a0);
  iVar2 = param_1;
  if (param_3 < 1) {
LAB_000d5d60:
    FUN_00008b68();
    return;
  }
LAB_000d5c2c:
  if ((*(byte *)(param_2 + 0x7e) & 2) != 0) {
    iVar8 = *(int *)(param_2 + 0x74);
    *(byte *)(param_2 + 0x7e) = *(byte *)(param_2 + 0x7e) & 0xfd;
    if (*(char *)(iVar8 + 0x234) != '\0') {
      iVar2 = _gleUpdateLightRGBASums(param_1,iVar8,0);
    }
    dVar13 = (double)*(float *)(iVar8 + 0x1e8);
    iVar7 = iVar8 + 0x50;
    dVar12 = (double)*(float *)(iVar8 + 0x1ec);
    dVar11 = (double)*(float *)(iVar8 + 0x1f0);
    uVar5 = 0;
    uVar1 = *(undefined4 *)(iVar8 + 0x1dc);
    iVar6 = param_1 + 0x2820;
    iVar9 = param_1 + 0x4a70;
    do {
      if ((uVar4 & 1 << (uVar5 & 0x3f)) == 0) {
        if (uVar4 >> (uVar5 & 0x3f) == 0) goto LAB_000d5d40;
      }
      else {
        fparam_8 = (double)*(float *)(param_2 + 0x48);
        fparam_7 = (double)FLOAT_00108e50;
        dVar10 = (double)(float)(fparam_8 * (double)*(float *)(iVar9 + 0x14) +
                                (double)(*(float *)(param_2 + 0x40) * *(float *)(iVar9 + 0xc) +
                                        *(float *)(param_2 + 0x44) * *(float *)(iVar9 + 0x10)));
        if (fparam_7 < dVar10) {
          dVar12 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x14) + (double)dVar12);
          dVar11 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x18) + (double)dVar11);
          dVar13 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x10) + (double)dVar13);
          dVar10 = (double)(float)(fparam_8 * (double)*(float *)(iVar6 + 0x68) +
                                  (double)(*(float *)(param_2 + 0x40) * *(float *)(iVar6 + 0x60) +
                                          *(float *)(param_2 + 0x44) * *(float *)(iVar6 + 100)));
          if (fparam_7 < dVar10) {
            dVar10 = ((double (*)())_gleMaterialShinePow)(iVar2,iVar8 + 0x1e8,dVar10,in_f2,in_f3,in_f4,in_f5,in_f6,fparam_7,
                                fparam_8,in_stack_ffffff78,in_stack_ffffff80,in_stack_ffffff88,
                                in_stack_ffffff90,in_stack_ffffff98);
            dVar13 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x20) + (double)dVar13);
            dVar12 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x24) + (double)dVar12);
            dVar11 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x28) + (double)dVar11);
            iVar2 = iVar2;
          }
        }
      }
      uVar5 = uVar5 + 1;
      iVar9 = iVar9 + 0x6c;
      iVar7 = iVar7 + 0x30;
      iVar6 = iVar6 + 0x80;
    } while( true );
  }
  goto LAB_000d5d50;
LAB_000d5d40:
  *(float *)(param_2 + 0x30) = (float)(double)dVar13;
  *(float *)(param_2 + 0x34) = (float)(double)dVar12;
  *(float *)(param_2 + 0x38) = (float)(double)dVar11;
  *(undefined4 *)(param_2 + 0x3c) = uVar1;
LAB_000d5d50:
  iVar3 = iVar3 + 1;
  param_2 = param_2 + 0x100;
  if (param_3 <= iVar3) goto LAB_000d5d60;
  goto LAB_000d5c2c;
}

/* _gleVtxLightFastRGBABack @ 0xd5d6c (376 bytes) */
void _gleVtxLightFastRGBABack(int param_1,int param_2,int param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 uVar1;
  int iVar2;
  int extraout_r3;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  double fparam_1_00;
  double dVar10;
  double fparam_8_00;
  float dVar11;
  float dVar12;
  float dVar13;
  float dVar14;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  double in_stack_ffffff88;
  double in_stack_ffffff90;
  double in_stack_ffffff98;
  
  iVar3 = 0;
  uVar4 = *(uint *)(param_1 + 0x30a0);
  iVar2 = param_1;
  if (param_3 < 1) {
LAB_000d5ed8:
    FUN_00008b68();
    return;
  }
LAB_000d5da0:
  if ((*(byte *)(param_2 + 0x7e) & 4) != 0) {
    iVar8 = *(int *)(param_2 + 0x78);
    *(byte *)(param_2 + 0x7e) = *(byte *)(param_2 + 0x7e) & 0xfb;
    if (*(char *)(iVar8 + 0x234) != '\0') {
      iVar2 = _gleUpdateLightRGBASums(param_1,iVar8,1);
    }
    dVar14 = (double)*(float *)(iVar8 + 0x1e8);
    iVar7 = iVar8 + 0x50;
    dVar13 = (double)*(float *)(iVar8 + 0x1ec);
    dVar12 = (double)*(float *)(iVar8 + 0x1f0);
    uVar5 = 0;
    uVar1 = *(undefined4 *)(iVar8 + 0x1dc);
    iVar6 = param_1 + 0x2820;
    iVar9 = param_1 + 0x4a70;
    do {
      if ((uVar4 & 1 << (uVar5 & 0x3f)) == 0) {
        if (uVar4 >> (uVar5 & 0x3f) == 0) goto LAB_000d5eb8;
      }
      else {
        fparam_8_00 = (double)*(float *)(param_2 + 0x48);
        dVar10 = (double)FLOAT_00108e50;
        dVar11 = (double)(float)(fparam_8_00 * (double)*(float *)(iVar9 + 0x14) +
                                (double)(*(float *)(param_2 + 0x40) * *(float *)(iVar9 + 0xc) +
                                        *(float *)(param_2 + 0x44) * *(float *)(iVar9 + 0x10)));
        if (dVar10 < -(double)dVar11) {
          dVar14 = -(double)(dVar11 * *(float *)(iVar7 + 0x10) - dVar14);
          dVar13 = -(double)(dVar11 * *(float *)(iVar7 + 0x14) - dVar13);
          fparam_1_00 = -(double)(float)(fparam_8_00 * (double)*(float *)(iVar6 + 0x68) +
                                        (double)(*(float *)(param_2 + 0x40) *
                                                 *(float *)(iVar6 + 0x60) +
                                                *(float *)(param_2 + 0x44) * *(float *)(iVar6 + 100)
                                                ));
          dVar12 = -(double)(dVar11 * *(float *)(iVar7 + 0x18) - dVar12);
          if (dVar10 < fparam_1_00) {
            dVar10 = ((double (*)())_gleMaterialShinePow)(iVar2,iVar8 + 0x1e8,fparam_1_00,fparam_2,fparam_3,fparam_4,fparam_5,
                                fparam_6,dVar10,fparam_8_00,in_stack_ffffff78,in_stack_ffffff80,
                                in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98);
            dVar14 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x20) + (double)dVar14);
            dVar13 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x24) + (double)dVar13);
            dVar12 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x28) + (double)dVar12);
            iVar2 = iVar2;
          }
        }
      }
      uVar5 = uVar5 + 1;
      iVar9 = iVar9 + 0x6c;
      iVar7 = iVar7 + 0x30;
      iVar6 = iVar6 + 0x80;
    } while( true );
  }
  goto LAB_000d5ec8;
LAB_000d5eb8:
  *(float *)(param_2 + 0x30) = (float)(double)dVar14;
  *(float *)(param_2 + 0x34) = (float)(double)dVar13;
  *(float *)(param_2 + 0x38) = (float)(double)dVar12;
  *(undefined4 *)(param_2 + 0x3c) = uVar1;
LAB_000d5ec8:
  iVar3 = iVar3 + 1;
  param_2 = param_2 + 0x100;
  if (param_3 <= iVar3) goto LAB_000d5ed8;
  goto LAB_000d5da0;
}

/* _gleVtxLightRGBAFrontPtr @ 0xd5ee4 (1192 bytes) */
void _gleVtxLightRGBAFrontPtr(int param_1,int *param_2,int param_3,double fparam_1)
{
  float fVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  int extraout_r3;
  int extraout_r3_00;
  uint uVar5;
  int iVar6;
  float *pfVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  double extraout_f1;
  double extraout_f1_00;
  double dVar15;
  double extraout_f1_01;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  float dVar16;
  float dVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  float dVar23;
  int iStack00000020;
  double in_stack_fffffee8;
  double in_stack_fffffef0;
  double in_stack_fffffef8;
  double in_stack_ffffff00;
  double in_stack_ffffff08;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c0;
  float local_bc;
  float local_b8;
  uint local_b0;
  float *local_ac;
  
  iVar6 = 0;
  local_b0 = (uint)*(byte *)(param_1 + 0x30ad);
  uVar5 = *(uint *)(param_1 + 0x30a0);
  iVar4 = param_1;
  iStack00000020 = param_3;
  if (param_3 < 1) {
    return;
  }
LAB_000d5f28:
  iVar14 = *param_2;
  param_2 = param_2 + 1;
  if ((*(byte *)(iVar14 + 0x7e) & 2) != 0) {
    iVar10 = *(int *)(iVar14 + 0x74);
    *(byte *)(iVar14 + 0x7e) = *(byte *)(iVar14 + 0x7e) & 0xfd;
    if (*(char *)(iVar10 + 0x234) != '\0') {
      iVar4 = _gleUpdateLightRGBASums(param_1,iVar10,0);
      fparam_1 = extraout_f1;
    }
    puVar3 = PTR__gleVectorNormalize_00112064;
    pfVar7 = (float *)(iVar14 + 0x20);
    if (*(float *)(iVar14 + 0x2c) != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / *(float *)(iVar14 + 0x2c);
      pfVar7 = &local_e0;
      local_d8 = *(float *)(iVar14 + 0x28) * fVar1;
      local_e0 = *(float *)(iVar14 + 0x20) * fVar1;
      local_dc = *(float *)(iVar14 + 0x24) * fVar1;
    }
    dVar22 = (double)*(float *)(iVar10 + 0x1d0);
    dVar21 = (double)*(float *)(iVar10 + 0x1d4);
    uVar8 = 0;
    dVar20 = (double)*(float *)(iVar10 + 0x1d8);
    uVar2 = *(undefined4 *)(iVar10 + 0x1dc);
    local_ac = &FLOAT_00108e80;
    dVar16 = (double)FLOAT_00108e54;
    iVar9 = param_1;
    iVar11 = param_1;
    iVar12 = iVar10;
    iVar13 = param_1;
    do {
      if ((uVar5 & 1 << (uVar8 & 0x3f)) == 0) {
        if (uVar5 >> (uVar8 & 0x3f) == 0) goto LAB_000d6360;
      }
      else if (*(char *)(iVar13 + 0x4ad8) == '\0') {
        if (*(char *)(iVar13 + 0x4ad9) == '\0') {
          local_d0 = *(float *)(iVar13 + 0x4a70) - *pfVar7;
          local_cc = *(float *)(iVar13 + 0x4a74) - pfVar7[1];
          local_c8 = *(float *)(iVar13 + 0x4a78) - pfVar7[2];
          iVar4 = (**(code **)puVar3)(fparam_1,param_1,&local_d0,&local_d0);
          if ((*(char *)(iVar13 + 0x4adb) != '\0') || (extraout_f1_00 < (double)*local_ac)) {
            dVar23 = (double)*(float *)(iVar13 + 0x4ad4);
          }
          else {
            fVar1 = (float)((double)dVar16 / extraout_f1_00);
            dVar23 = (double)(dVar16 / (*(float *)(iVar11 + 0x2878) * fVar1 * fVar1 +
                                                      (*(float *)(iVar11 + 0x2874) * fVar1 +
                                                      *(float *)(iVar11 + 0x2870))));
          }
        }
        else {
          dVar23 = (double)FLOAT_00108e54;
          local_d0 = *(float *)(iVar13 + 0x4a7c);
          local_cc = *(float *)(iVar13 + 0x4a80);
          local_c8 = *(float *)(iVar13 + 0x4a84);
        }
        if (*(char *)(iVar13 + 0x4ada) != '\0') {
          fparam_1 = -(double)(local_c8 * *(float *)(iVar13 + 0x4a90) +
                              (local_d0 * *(float *)(iVar13 + 0x4a88) +
                              local_cc * *(float *)(iVar13 + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(iVar11 + 0x286c)) goto LAB_000d6348;
          dVar15 = ((double (*)())_gleLightExponentPow)(iVar4,iVar13 + 0x4a70,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,
                              in_f8,in_stack_fffffee8,in_stack_fffffef0,in_stack_fffffef8,
                              in_stack_ffffff00,in_stack_ffffff08);
          dVar23 = (double)(float)((double)dVar23 * dVar15);
        }
        if (local_b0 == 0) {
          local_b8 = (local_c8 + dVar16);
          local_c0 = local_d0;
          local_bc = local_cc;
        }
        else {
          local_c0 = -*pfVar7;
          local_bc = -pfVar7[1];
          local_b8 = -pfVar7[2];
          (**(code **)puVar3)(param_1,&local_c0,&local_c0);
          local_c0 = local_c0 + local_d0;
          local_bc = local_bc + local_cc;
          local_b8 = local_b8 + local_c8;
        }
        iVar4 = (**(code **)puVar3)(param_1,&local_c0,&local_c0);
        dVar15 = (double)FLOAT_00108e50;
        fparam_1 = extraout_f1_01;
        if ((double)dVar23 != dVar15) {
          in_f8 = (double)*(float *)(iVar14 + 0x40);
          in_f7 = (double)*(float *)(iVar14 + 0x48);
          dVar18 = (double)*(float *)(iVar12 + 0x50);
          dVar17 = (double)*(float *)(iVar12 + 0x54);
          dVar19 = (double)*(float *)(iVar12 + 0x58);
          fparam_1 = (double)(float)(in_f7 * (double)local_c8 +
                                    (double)(float)(in_f8 * (double)local_d0 +
                                                   (double)(*(float *)(iVar14 + 0x44) * local_cc)));
          if (dVar15 < fparam_1) {
            dVar19 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x68) + (double)dVar19);
            dVar18 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x60) + (double)dVar18);
            dVar17 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 100) + (double)dVar17);
            fparam_1 = (double)(float)(in_f7 * (double)local_b8 +
                                      (double)(float)(in_f8 * (double)local_c0 +
                                                     (double)(*(float *)(iVar14 + 0x44) * local_bc))
                                      );
            if (dVar15 < fparam_1) {
              in_f2 = (double)*(float *)(iVar10 + 0x40);
              dVar15 = _pow(fparam_1,in_f2);
              fparam_1 = (double)(float)dVar15;
              dVar19 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x78) + (double)dVar19);
              dVar18 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x70) + (double)dVar18);
              dVar17 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x74) + (double)dVar17);
              iVar4 = extraout_r3_00;
            }
          }
          if ((double)dVar23 == (double)dVar16) {
            dVar22 = (double)(dVar22 + dVar18);
            dVar21 = (double)(dVar21 + dVar17);
            dVar20 = (double)(dVar20 + dVar19);
          }
          else {
            dVar20 = (double)(dVar23 * dVar19 + dVar20);
            dVar22 = (double)(dVar23 * dVar18 + dVar22);
            dVar21 = (double)(dVar23 * dVar17 + dVar21);
          }
        }
      }
      else {
        in_f8 = (double)*(float *)(iVar14 + 0x48);
        in_f7 = (double)FLOAT_00108e50;
        fparam_1 = (double)(float)(in_f8 * (double)*(float *)(iVar13 + 0x4a84) +
                                  (double)(*(float *)(iVar14 + 0x40) * *(float *)(iVar13 + 0x4a7c) +
                                          *(float *)(iVar14 + 0x44) * *(float *)(iVar13 + 0x4a80)));
        dVar22 = (double)(dVar22 + *(float *)(iVar12 + 0x50));
        dVar21 = (double)(dVar21 + *(float *)(iVar12 + 0x54));
        dVar20 = (double)(dVar20 + *(float *)(iVar12 + 0x58));
        if (in_f7 < fparam_1) {
          dVar22 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x60) + (double)dVar22);
          dVar21 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 100) + (double)dVar21);
          dVar20 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x68) + (double)dVar20);
          fparam_1 = (double)(float)(in_f8 * (double)*(float *)(iVar9 + 0x2888) +
                                    (double)(*(float *)(iVar14 + 0x40) * *(float *)(iVar9 + 0x2880)
                                            + *(float *)(iVar14 + 0x44) * *(float *)(iVar9 + 0x2884)
                                            ));
          if (in_f7 < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar4,iVar10 + 0x1e8,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,
                                  in_f8,in_stack_fffffee8,in_stack_fffffef0,in_stack_fffffef8,
                                  in_stack_ffffff00,in_stack_ffffff08);
            dVar20 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x78) + (double)dVar20);
            dVar22 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x70) + (double)dVar22);
            dVar21 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x74) + (double)dVar21);
            iVar4 = iVar4;
          }
        }
      }
LAB_000d6348:
      uVar8 = uVar8 + 1;
      iVar13 = iVar13 + 0x6c;
      iVar12 = iVar12 + 0x30;
      iVar9 = iVar9 + 0x80;
      iVar11 = iVar11 + 0x80;
    } while( true );
  }
  goto LAB_000d6370;
LAB_000d6360:
  *(undefined4 *)(iVar14 + 0x3c) = uVar2;
  *(float *)(iVar14 + 0x30) = (float)(double)dVar22;
  *(float *)(iVar14 + 0x34) = (float)(double)dVar21;
  *(float *)(iVar14 + 0x38) = (float)(double)dVar20;
LAB_000d6370:
  iVar6 = iVar6 + 1;
  if (iStack00000020 <= iVar6) {
    return;
  }
  goto LAB_000d5f28;
}

/* _gleVtxLightRGBABackPtr @ 0xd638c (1200 bytes) */
void _gleVtxLightRGBABackPtr(int param_1,int *param_2,int param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  float fVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  int extraout_r3;
  int extraout_r3_00;
  uint uVar5;
  int iVar6;
  float *pfVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  double extraout_f1;
  double extraout_f1_00;
  double dVar15;
  double extraout_f1_01;
  float dVar16;
  float dVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  float dVar23;
  int iStack00000020;
  double in_stack_fffffee8;
  double in_stack_fffffef0;
  double in_stack_fffffef8;
  double in_stack_ffffff00;
  double in_stack_ffffff08;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c0;
  float local_bc;
  float local_b8;
  uint local_b0;
  float *local_ac;
  
  iVar6 = 0;
  local_b0 = (uint)*(byte *)(param_1 + 0x30ad);
  uVar5 = *(uint *)(param_1 + 0x30a0);
  iVar4 = param_1;
  iStack00000020 = param_3;
  if (param_3 < 1) {
    return;
  }
LAB_000d63d0:
  iVar14 = *param_2;
  param_2 = param_2 + 1;
  if ((*(byte *)(iVar14 + 0x7e) & 4) != 0) {
    iVar10 = *(int *)(iVar14 + 0x78);
    *(byte *)(iVar14 + 0x7e) = *(byte *)(iVar14 + 0x7e) & 0xfb;
    if (*(char *)(iVar10 + 0x234) != '\0') {
      iVar4 = _gleUpdateLightRGBASums(param_1,iVar10,1);
      fparam_1 = extraout_f1;
    }
    puVar3 = PTR__gleVectorNormalize_00112064;
    pfVar7 = (float *)(iVar14 + 0x20);
    if (*(float *)(iVar14 + 0x2c) != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / *(float *)(iVar14 + 0x2c);
      pfVar7 = &local_e0;
      local_d8 = *(float *)(iVar14 + 0x28) * fVar1;
      local_e0 = *(float *)(iVar14 + 0x20) * fVar1;
      local_dc = *(float *)(iVar14 + 0x24) * fVar1;
    }
    dVar23 = (double)*(float *)(iVar10 + 0x1d0);
    dVar22 = (double)*(float *)(iVar10 + 0x1d4);
    uVar8 = 0;
    dVar21 = (double)*(float *)(iVar10 + 0x1d8);
    uVar2 = *(undefined4 *)(iVar10 + 0x1dc);
    local_ac = &FLOAT_00108e80;
    dVar17 = (double)FLOAT_00108e54;
    iVar9 = param_1;
    iVar11 = param_1;
    iVar12 = iVar10;
    iVar13 = param_1;
    do {
      if ((uVar5 & 1 << (uVar8 & 0x3f)) == 0) {
        if (uVar5 >> (uVar8 & 0x3f) == 0) goto LAB_000d6810;
      }
      else if (*(char *)(iVar13 + 0x4ad8) == '\0') {
        if (*(char *)(iVar13 + 0x4ad9) == '\0') {
          local_d0 = *(float *)(iVar13 + 0x4a70) - *pfVar7;
          local_cc = *(float *)(iVar13 + 0x4a74) - pfVar7[1];
          local_c8 = *(float *)(iVar13 + 0x4a78) - pfVar7[2];
          iVar4 = (**(code **)puVar3)(fparam_1,param_1,&local_d0,&local_d0);
          if ((*(char *)(iVar13 + 0x4adb) != '\0') || (extraout_f1_00 < (double)*local_ac)) {
            dVar16 = (double)*(float *)(iVar13 + 0x4ad4);
          }
          else {
            fVar1 = (float)((double)dVar17 / extraout_f1_00);
            dVar16 = (double)(dVar17 / (*(float *)(iVar11 + 0x2878) * fVar1 * fVar1 +
                                                      (*(float *)(iVar11 + 0x2874) * fVar1 +
                                                      *(float *)(iVar11 + 0x2870))));
          }
        }
        else {
          dVar16 = (double)FLOAT_00108e54;
          local_d0 = *(float *)(iVar13 + 0x4a7c);
          local_cc = *(float *)(iVar13 + 0x4a80);
          local_c8 = *(float *)(iVar13 + 0x4a84);
        }
        if (*(char *)(iVar13 + 0x4ada) != '\0') {
          fparam_1 = -(double)(local_c8 * *(float *)(iVar13 + 0x4a90) +
                              (local_d0 * *(float *)(iVar13 + 0x4a88) +
                              local_cc * *(float *)(iVar13 + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(iVar11 + 0x286c)) goto LAB_000d67f8;
          dVar15 = ((double (*)())_gleLightExponentPow)(iVar4,iVar13 + 0x4a70,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                              fparam_6,fparam_7,fparam_8,in_stack_fffffee8,in_stack_fffffef0,
                              in_stack_fffffef8,in_stack_ffffff00,in_stack_ffffff08);
          dVar16 = (double)(float)((double)dVar16 * dVar15);
        }
        if (local_b0 == 0) {
          local_b8 = (local_c8 + dVar17);
          local_c0 = local_d0;
          local_bc = local_cc;
        }
        else {
          local_c0 = -*pfVar7;
          local_bc = -pfVar7[1];
          local_b8 = -pfVar7[2];
          (**(code **)puVar3)(param_1,&local_c0,&local_c0);
          local_c0 = local_c0 + local_d0;
          local_bc = local_bc + local_cc;
          local_b8 = local_b8 + local_c8;
        }
        iVar4 = (**(code **)puVar3)(param_1,&local_c0,&local_c0);
        fparam_8 = (double)FLOAT_00108e50;
        fparam_1 = extraout_f1_01;
        if ((double)dVar16 != fparam_8) {
          fparam_7 = (double)*(float *)(iVar14 + 0x48);
          dVar19 = (double)*(float *)(iVar12 + 0x50);
          dVar18 = (double)*(float *)(iVar12 + 0x54);
          dVar20 = (double)*(float *)(iVar12 + 0x58);
          dVar15 = (double)(float)(fparam_7 * (double)local_c8 +
                                  (double)(*(float *)(iVar14 + 0x40) * local_d0 +
                                          *(float *)(iVar14 + 0x44) * local_cc));
          fparam_1 = -dVar15;
          if (fparam_8 < fparam_1) {
            dVar19 = -(double)(float)(dVar15 * (double)*(float *)(iVar12 + 0x60) - (double)dVar19);
            dVar20 = -(double)(float)(dVar15 * (double)*(float *)(iVar12 + 0x68) - (double)dVar20);
            fparam_1 = -(double)(float)(fparam_7 * (double)local_b8 +
                                       (double)(*(float *)(iVar14 + 0x40) * local_c0 +
                                               *(float *)(iVar14 + 0x44) * local_bc));
            dVar18 = -(double)(float)(dVar15 * (double)*(float *)(iVar12 + 100) - (double)dVar18);
            if (fparam_8 < fparam_1) {
              fparam_2 = (double)*(float *)(iVar10 + 0x40);
              dVar15 = _pow(fparam_1,fparam_2);
              fparam_1 = (double)(float)dVar15;
              dVar20 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x78) + (double)dVar20);
              dVar19 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x70) + (double)dVar19);
              dVar18 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x74) + (double)dVar18);
              iVar4 = extraout_r3_00;
            }
          }
          if ((double)dVar16 == (double)dVar17) {
            dVar23 = (double)(dVar23 + dVar19);
            dVar22 = (double)(dVar22 + dVar18);
            dVar21 = (double)(dVar21 + dVar20);
          }
          else {
            dVar21 = (double)(dVar16 * dVar20 + dVar21);
            dVar23 = (double)(dVar16 * dVar19 + dVar23);
            dVar22 = (double)(dVar16 * dVar18 + dVar22);
          }
        }
      }
      else {
        fparam_8 = (double)*(float *)(iVar14 + 0x48);
        fparam_7 = (double)FLOAT_00108e50;
        dVar16 = (double)(float)(fparam_8 * (double)*(float *)(iVar13 + 0x4a84) +
                                (double)(*(float *)(iVar14 + 0x40) * *(float *)(iVar13 + 0x4a7c) +
                                        *(float *)(iVar14 + 0x44) * *(float *)(iVar13 + 0x4a80)));
        dVar23 = (double)(dVar23 + *(float *)(iVar12 + 0x50));
        dVar22 = (double)(dVar22 + *(float *)(iVar12 + 0x54));
        fparam_1 = -(double)dVar16;
        dVar21 = (double)(dVar21 + *(float *)(iVar12 + 0x58));
        if (fparam_7 < fparam_1) {
          dVar23 = -(double)(dVar16 * *(float *)(iVar12 + 0x60) - dVar23);
          dVar22 = -(double)(dVar16 * *(float *)(iVar12 + 100) - dVar22);
          fparam_1 = -(double)(float)(fparam_8 * (double)*(float *)(iVar9 + 0x2888) +
                                     (double)(*(float *)(iVar14 + 0x40) * *(float *)(iVar9 + 0x2880)
                                             + *(float *)(iVar14 + 0x44) *
                                               *(float *)(iVar9 + 0x2884)));
          dVar21 = -(double)(dVar16 * *(float *)(iVar12 + 0x68) - dVar21);
          if (fparam_7 < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar4,iVar10 + 0x1e8,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                                  fparam_6,fparam_7,fparam_8,in_stack_fffffee8,in_stack_fffffef0,
                                  in_stack_fffffef8,in_stack_ffffff00,in_stack_ffffff08);
            dVar21 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x78) + (double)dVar21);
            dVar23 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x70) + (double)dVar23);
            dVar22 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x74) + (double)dVar22);
            iVar4 = iVar4;
          }
        }
      }
LAB_000d67f8:
      uVar8 = uVar8 + 1;
      iVar13 = iVar13 + 0x6c;
      iVar12 = iVar12 + 0x30;
      iVar9 = iVar9 + 0x80;
      iVar11 = iVar11 + 0x80;
    } while( true );
  }
  goto LAB_000d6820;
LAB_000d6810:
  *(undefined4 *)(iVar14 + 0x3c) = uVar2;
  *(float *)(iVar14 + 0x30) = (float)(double)dVar23;
  *(float *)(iVar14 + 0x34) = (float)(double)dVar22;
  *(float *)(iVar14 + 0x38) = (float)(double)dVar21;
LAB_000d6820:
  iVar6 = iVar6 + 1;
  if (iStack00000020 <= iVar6) {
    return;
  }
  goto LAB_000d63d0;
}

/* _gleVtxLightSpecRGBAFrontPtr @ 0xd683c (1680 bytes) */
void _gleVtxLightSpecRGBAFrontPtr(int param_1,int param_2,int param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  float fVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  int extraout_r3;
  int extraout_r3_00;
  int extraout_r3_01;
  uint uVar5;
  int iVar6;
  float *pfVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  double dVar15;
  double dVar16;
  float dVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  float dVar23;
  float dVar24;
  float dVar25;
  float dVar26;
  float dVar27;
  float dVar28;
  float dVar29;
  int iStack0000001c;
  double in_stack_fffffea8;
  double in_stack_fffffeb0;
  double in_stack_fffffeb8;
  double in_stack_fffffec0;
  double in_stack_fffffec8;
  float local_120;
  float local_11c;
  float local_118;
  float local_110;
  float local_10c;
  float local_108;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e0;
  float local_dc;
  float local_d8;
  uint local_d0;
  float *local_cc;
  
  iVar6 = 0;
  local_d0 = (uint)*(byte *)(param_1 + 0x30ad);
  uVar5 = *(uint *)(param_1 + 0x30a0);
  iVar4 = param_1;
  iStack0000001c = param_2;
  if (param_3 < 1) {
    return;
  }
LAB_000d6880:
  iVar14 = *(int *)(iStack0000001c + iVar6 * 4);
  if ((*(byte *)(iVar14 + 0x7e) & 2) != 0) {
    iVar11 = *(int *)(iVar14 + 0x74);
    *(byte *)(iVar14 + 0x7e) = *(byte *)(iVar14 + 0x7e) & 0xfd;
    if (*(char *)(iVar11 + 0x234) != '\0') {
      iVar4 = _gleUpdateLightRGBASums(param_1,iVar11,0);
      fparam_1 = extraout_f1;
    }
    pfVar7 = (float *)(iVar14 + 0x20);
    if (*(float *)(iVar14 + 0x2c) != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / *(float *)(iVar14 + 0x2c);
      pfVar7 = &local_120;
      local_118 = *(float *)(iVar14 + 0x28) * fVar1;
      local_120 = *(float *)(iVar14 + 0x20) * fVar1;
      local_11c = *(float *)(iVar14 + 0x24) * fVar1;
    }
    if (*(char *)(param_1 + 0x30ae) != '\0') {
      if ((local_d0 == 0) || (*(int *)(param_1 + 0x4ddc) == 0)) {
        local_10c = 0.0;
        local_108 = 1.0;
        local_110 = 0.0;
      }
      else {
        local_110 = -*pfVar7;
        local_10c = -pfVar7[1];
        local_108 = -pfVar7[2];
        iVar4 = (**(code **)PTR__gleVectorNormalize_00112064)
                          (fparam_1,param_1,&local_110,&local_110);
        fparam_1 = extraout_f1_00;
      }
    }
    puVar3 = PTR__gleVectorNormalize_00112064;
    dVar22 = (double)FLOAT_00108e50;
    dVar29 = (double)*(float *)(iVar11 + 0x1d0);
    uVar8 = 0;
    dVar28 = (double)*(float *)(iVar11 + 0x1d4);
    dVar27 = (double)*(float *)(iVar11 + 0x1d8);
    uVar2 = *(undefined4 *)(iVar11 + 0x1dc);
    local_cc = &FLOAT_00108e80;
    dVar19 = (double)FLOAT_00108e54;
    iVar9 = param_1;
    iVar10 = param_1;
    iVar12 = iVar11;
    iVar13 = param_1;
    dVar20 = (double)dVar22;
    dVar21 = (double)dVar22;
    dVar23 = (double)dVar22;
    do {
      if ((uVar5 & 1 << (uVar8 & 0x3f)) == 0) {
        if (uVar5 >> (uVar8 & 0x3f) == 0) goto LAB_000d6e74;
      }
      else if (*(char *)(iVar13 + 0x4ad8) == '\0') {
        if (*(char *)(iVar13 + 0x4ad9) == '\0') {
          local_100 = *(float *)(iVar13 + 0x4a70) - *pfVar7;
          local_fc = *(float *)(iVar13 + 0x4a74) - pfVar7[1];
          local_f8 = *(float *)(iVar13 + 0x4a78) - pfVar7[2];
          iVar4 = (**(code **)puVar3)(param_1,&local_100,&local_100);
          if ((*(char *)(iVar13 + 0x4adb) != '\0') || (extraout_f1_01 < (double)*local_cc)) {
            dVar16 = (double)*(float *)(iVar13 + 0x4ad4);
            fparam_1 = extraout_f1_01;
          }
          else {
            fparam_1 = (double)(float)((double)dVar19 / extraout_f1_01);
            dVar16 = (double)(dVar19 / (float)((double)(float)((double)*(float *)(
                                                  iVar10 + 0x2878) * fparam_1) * fparam_1 +
                                                  (double)(float)((double)*(float *)(iVar10 + 0x2874
                                                                                    ) * fparam_1 +
                                                                 (double)*(float *)(iVar10 + 0x2870)
                                                                 )));
          }
        }
        else {
          dVar16 = (double)FLOAT_00108e54;
          local_100 = *(float *)(iVar13 + 0x4a7c);
          local_fc = *(float *)(iVar13 + 0x4a80);
          local_f8 = *(float *)(iVar13 + 0x4a84);
        }
        if (*(char *)(iVar13 + 0x4ada) != '\0') {
          fparam_1 = -(double)(local_f8 * *(float *)(iVar13 + 0x4a90) +
                              (local_100 * *(float *)(iVar13 + 0x4a88) +
                              local_fc * *(float *)(iVar13 + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(iVar10 + 0x286c)) goto LAB_000d6e5c;
          fparam_1 = ((double (*)())_gleLightExponentPow)(iVar4,iVar13 + 0x4a70,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                                fparam_6,fparam_7,fparam_8,in_stack_fffffea8,in_stack_fffffeb0,
                                in_stack_fffffeb8,in_stack_fffffec0,in_stack_fffffec8);
          dVar16 = (double)(float)(dVar16 * fparam_1);
          iVar4 = iVar4;
        }
        if (*(char *)(param_1 + 0x30ae) == '\0') {
          if (local_d0 == 0) {
            local_108 = (local_f8 + dVar19);
            local_110 = local_100;
            local_10c = local_fc;
          }
          else {
            local_110 = -*pfVar7;
            local_10c = -pfVar7[1];
            local_108 = -pfVar7[2];
            (**(code **)puVar3)(param_1,&local_110,&local_110);
            local_110 = local_110 + local_100;
            local_10c = local_10c + local_fc;
            local_108 = local_108 + local_f8;
          }
          iVar4 = (**(code **)puVar3)(param_1,&local_110,&local_110);
          fparam_1 = extraout_f1_02;
        }
        if (dVar16 != (double)FLOAT_00108e50) {
          dVar18 = (double)*(float *)(iVar14 + 0x44);
          fparam_6 = (double)local_fc;
          fparam_7 = (double)local_100;
          dVar17 = (double)*(float *)(iVar14 + 0x48);
          fparam_5 = (double)local_f8;
          dVar26 = (double)*(float *)(iVar12 + 0x50);
          dVar25 = (double)*(float *)(iVar12 + 0x54);
          dVar24 = (double)*(float *)(iVar12 + 0x58);
          dVar15 = (double)(float)((double)dVar17 * fparam_5 +
                                  (double)(float)((double)*(float *)(iVar14 + 0x40) * fparam_7 +
                                                 (double)(float)((double)dVar18 * fparam_6)));
          if (dVar15 <= (double)FLOAT_00108e50) {
LAB_000d6e10:
            dVar17 = (double)FLOAT_00108e50;
            fparam_1 = (double)dVar17;
            dVar15 = (double)dVar17;
          }
          else {
            dVar26 = (double)(float)(dVar15 * (double)*(float *)(iVar12 + 0x60) + (double)dVar26);
            dVar25 = (double)(float)(dVar15 * (double)*(float *)(iVar12 + 100) + (double)dVar25);
            dVar24 = (double)(float)(dVar15 * (double)*(float *)(iVar12 + 0x68) + (double)dVar24);
            if (*(char *)(param_1 + 0x30ae) == '\0') {
              fVar1 = (dVar17 * local_108 + (*(float *)(iVar14 + 0x40) * local_110 + (dVar18 * local_10c)));
            }
            else {
              local_f0 = (float)((double)dVar18 * fparam_5 - (double)(float)((double)dVar17 * fparam_6));
              fparam_8 = (double)local_f0;
              local_ec = (float)((double)dVar17 * fparam_7 -
                                (double)(float)((double)*(float *)(iVar14 + 0x40) * fparam_5));
              dVar15 = (double)local_ec;
              local_e8 = (float)((double)*(float *)(iVar14 + 0x40) * fparam_6 -
                                (double)(float)((double)*(float *)(iVar14 + 0x44) * fparam_7));
              dVar17 = (double)local_e8;
              fVar1 = (*(float *)(iVar14 + 0x44) * dVar17 - (float)((double)*(float *)(iVar14 + 0x48) * dVar15));
              local_e0 = (float)((double)(fVar1 + fVar1) + fparam_7);
              fVar1 = (float)((double)*(float *)(iVar14 + 0x48) * fparam_8 -
                             (double)(*(float *)(iVar14 + 0x40) * dVar17));
              local_dc = (float)((double)(fVar1 + fVar1) + fparam_6);
              fVar1 = (float)((double)*(float *)(iVar14 + 0x40) * dVar15 -
                             (double)(float)((double)*(float *)(iVar14 + 0x44) * fparam_8));
              local_d8 = (float)((double)(fVar1 + fVar1) + fparam_5);
              fVar1 = local_d8 * local_108 + (local_e0 * local_110 + local_dc * local_10c);
            }
            if ((double)fVar1 <= (double)dVar22) goto LAB_000d6e10;
            fparam_2 = (double)*(float *)(iVar11 + 0x40);
            dVar15 = _pow((double)fVar1,fparam_2);
            fVar1 = (float)dVar15;
            dVar17 = (double)(fVar1 * *(float *)(iVar12 + 0x78));
            iVar4 = extraout_r3_01;
            fparam_1 = (double)(fVar1 * *(float *)(iVar12 + 0x74));
            dVar15 = (double)(fVar1 * *(float *)(iVar12 + 0x70));
          }
          if (dVar16 == (double)dVar19) {
            dVar29 = (double)(dVar29 + dVar26);
            dVar28 = (double)(dVar28 + dVar25);
            dVar27 = (double)(dVar27 + dVar24);
            dVar23 = (double)(float)((double)dVar23 + dVar15);
            dVar21 = (double)(float)((double)dVar21 + fparam_1);
            dVar20 = (double)(dVar20 + dVar17);
          }
          else {
            dVar20 = (double)(float)(dVar16 * (double)dVar17 + (double)dVar20);
            dVar29 = (double)(float)(dVar16 * (double)dVar26 + (double)dVar29);
            dVar28 = (double)(float)(dVar16 * (double)dVar25 + (double)dVar28);
            dVar27 = (double)(float)(dVar16 * (double)dVar24 + (double)dVar27);
            dVar23 = (double)(float)(dVar16 * dVar15 + (double)dVar23);
            dVar21 = (double)(float)(dVar16 * fparam_1 + (double)dVar21);
          }
        }
      }
      else {
        fparam_8 = (double)*(float *)(iVar14 + 0x44);
        fparam_7 = (double)*(float *)(iVar13 + 0x4a80);
        dVar16 = (double)*(float *)(iVar13 + 0x4a84);
        dVar29 = (double)(dVar29 + *(float *)(iVar12 + 0x50));
        fparam_1 = (double)(float)((double)*(float *)(iVar14 + 0x48) * dVar16 +
                                  (double)(*(float *)(iVar14 + 0x40) * *(float *)(iVar13 + 0x4a7c) +
                                          (float)(fparam_8 * fparam_7)));
        dVar28 = (double)(dVar28 + *(float *)(iVar12 + 0x54));
        dVar27 = (double)(dVar27 + *(float *)(iVar12 + 0x58));
        if ((double)dVar22 < fparam_1) {
          dVar29 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x60) + (double)dVar29);
          dVar28 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 100) + (double)dVar28);
          dVar27 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x68) + (double)dVar27);
          if (*(char *)(param_1 + 0x30ae) == '\0') {
            dVar16 = (double)*(float *)(iVar14 + 0x48) * (double)*(float *)(iVar9 + 0x2888) +
                     (double)(*(float *)(iVar14 + 0x40) * *(float *)(iVar9 + 0x2880) +
                             (float)(fparam_8 * (double)*(float *)(iVar9 + 0x2884)));
          }
          else {
            local_f8 = *(float *)(iVar13 + 0x4a84);
            local_100 = (float)(fparam_8 * dVar16 -
                               (double)(float)((double)*(float *)(iVar14 + 0x48) * fparam_7));
            local_fc = (*(float *)(iVar14 + 0x48) * *(float *)(iVar13 + 0x4a7c) - (float)((double)*(float *)(iVar14 + 0x40) * dVar16));
            fVar1 = (*(float *)(iVar14 + 0x40) * local_fc - (*(float *)(iVar14 + 0x44) * local_100));
            dVar16 = (double)(fVar1 + fVar1) + dVar16;
          }
          fparam_1 = (double)(float)dVar16;
          if ((double)dVar22 < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar4,iVar11 + 0x1e8,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                                  fparam_6,fparam_7,fparam_8,in_stack_fffffea8,in_stack_fffffeb0,
                                  in_stack_fffffeb8,in_stack_fffffec0,in_stack_fffffec8);
            dVar27 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x78) + (double)dVar27);
            dVar29 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x70) + (double)dVar29);
            dVar28 = (double)(float)(fparam_1 * (double)*(float *)(iVar12 + 0x74) + (double)dVar28);
            iVar4 = iVar4;
          }
        }
      }
LAB_000d6e5c:
      uVar8 = uVar8 + 1;
      iVar13 = iVar13 + 0x6c;
      iVar12 = iVar12 + 0x30;
      iVar9 = iVar9 + 0x80;
      iVar10 = iVar10 + 0x80;
    } while( true );
  }
  goto LAB_000d6eb4;
LAB_000d6e74:
  if (*(short *)(param_1 + 0x30a8) == -0x7e06) {
    *(float *)(iVar14 + 0x50) = (float)(double)dVar23;
    *(float *)(iVar14 + 0x54) = (float)(double)dVar21;
    *(float *)(iVar14 + 0x58) = (float)(double)dVar20;
  }
  else {
    dVar29 = (double)(dVar29 + dVar23);
    dVar28 = (double)(dVar28 + dVar21);
    dVar27 = (double)(dVar27 + dVar20);
  }
  *(undefined4 *)(iVar14 + 0x3c) = uVar2;
  *(float *)(iVar14 + 0x30) = (float)(double)dVar29;
  *(float *)(iVar14 + 0x34) = (float)(double)dVar28;
  *(float *)(iVar14 + 0x38) = (float)(double)dVar27;
LAB_000d6eb4:
  iVar6 = iVar6 + 1;
  if (param_3 <= iVar6) {
    return;
  }
  goto LAB_000d6880;
}

/* _gleVtxLightSpecRGBABackPtr @ 0xd6ecc (1688 bytes) */
void _gleVtxLightSpecRGBABackPtr(int param_1,int param_2,int param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10)
{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined *puVar4;
  int iVar5;
  int extraout_r3;
  int extraout_r3_00;
  int extraout_r3_01;
  uint uVar6;
  int iVar7;
  float *pfVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  float dVar16;
  double dVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  float dVar23;
  float dVar24;
  float dVar25;
  float dVar26;
  float dVar27;
  float dVar28;
  float dVar29;
  float dVar30;
  int iStack0000001c;
  int iStack00000020;
  double in_stack_fffffea8;
  double in_stack_fffffeb0;
  double in_stack_fffffeb8;
  double in_stack_fffffec0;
  double in_stack_fffffec8;
  float local_120;
  float local_11c;
  float local_118;
  float local_110;
  float local_10c;
  float local_108;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e0;
  float local_dc;
  float local_d8;
  uint local_d0;
  
  iVar7 = 0;
  local_d0 = (uint)*(byte *)(param_1 + 0x30ad);
  uVar6 = *(uint *)(param_1 + 0x30a0);
  iVar5 = param_1;
  iStack0000001c = param_2;
  iStack00000020 = param_3;
  if (param_3 < 1) {
    return;
  }
LAB_000d6f10:
  iVar15 = *(int *)(iStack0000001c + iVar7 * 4);
  if ((*(byte *)(iVar15 + 0x7e) & 4) != 0) {
    iVar12 = *(int *)(iVar15 + 0x78);
    *(byte *)(iVar15 + 0x7e) = *(byte *)(iVar15 + 0x7e) & 0xfb;
    if (*(char *)(iVar12 + 0x234) != '\0') {
      iVar5 = _gleUpdateLightRGBASums(param_1,iVar12,1);
      fparam_1 = extraout_f1;
    }
    pfVar8 = (float *)(iVar15 + 0x20);
    if (*(float *)(iVar15 + 0x2c) != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / *(float *)(iVar15 + 0x2c);
      pfVar8 = &local_120;
      local_118 = *(float *)(iVar15 + 0x28) * fVar1;
      local_120 = *(float *)(iVar15 + 0x20) * fVar1;
      local_11c = *(float *)(iVar15 + 0x24) * fVar1;
    }
    if (*(char *)(param_1 + 0x30ae) != '\0') {
      if ((local_d0 == 0) || (*(int *)(param_1 + 0x4ddc) == 0)) {
        local_10c = 0.0;
        local_108 = 1.0;
        local_110 = 0.0;
      }
      else {
        local_110 = -*pfVar8;
        local_10c = -pfVar8[1];
        local_108 = -pfVar8[2];
        iVar5 = (**(code **)PTR__gleVectorNormalize_00112064)
                          (fparam_1,param_1,&local_110,&local_110);
        fparam_1 = extraout_f1_00;
      }
    }
    puVar4 = PTR__gleVectorNormalize_00112064;
    dVar23 = (double)FLOAT_00108e50;
    dVar30 = (double)*(float *)(iVar12 + 0x1d0);
    uVar9 = 0;
    dVar29 = (double)*(float *)(iVar12 + 0x1d4);
    dVar28 = (double)*(float *)(iVar12 + 0x1d8);
    uVar3 = *(undefined4 *)(iVar12 + 0x1dc);
    dVar20 = (double)FLOAT_00108e54;
    iVar10 = param_1;
    iVar11 = param_1;
    iVar13 = iVar12;
    iVar14 = param_1;
    dVar21 = (double)dVar23;
    dVar22 = (double)dVar23;
    dVar24 = (double)dVar23;
    do {
      if ((uVar6 & 1 << (uVar9 & 0x3f)) == 0) {
        if (uVar6 >> (uVar9 & 0x3f) == 0) goto LAB_000d7508;
      }
      else if (*(char *)(iVar14 + 0x4ad8) == '\0') {
        if (*(char *)(iVar14 + 0x4ad9) == '\0') {
          local_100 = *(float *)(iVar14 + 0x4a70) - *pfVar8;
          local_fc = *(float *)(iVar14 + 0x4a74) - pfVar8[1];
          local_f8 = *(float *)(iVar14 + 0x4a78) - pfVar8[2];
          iVar5 = (**(code **)puVar4)(param_1,&local_100,&local_100);
          if ((*(char *)(iVar14 + 0x4adb) != '\0') || (extraout_f1_01 < (double)FLOAT_00108e80)) {
            dVar16 = (double)*(float *)(iVar14 + 0x4ad4);
            fparam_1 = extraout_f1_01;
          }
          else {
            fparam_1 = (double)(float)((double)dVar20 / extraout_f1_01);
            dVar16 = (double)(dVar20 / (float)((double)(float)((double)*(float *)(
                                                  iVar11 + 0x2878) * fparam_1) * fparam_1 +
                                                  (double)(float)((double)*(float *)(iVar11 + 0x2874
                                                                                    ) * fparam_1 +
                                                                 (double)*(float *)(iVar11 + 0x2870)
                                                                 )));
          }
        }
        else {
          dVar16 = (double)FLOAT_00108e54;
          local_100 = *(float *)(iVar14 + 0x4a7c);
          local_fc = *(float *)(iVar14 + 0x4a80);
          local_f8 = *(float *)(iVar14 + 0x4a84);
        }
        if (*(char *)(iVar14 + 0x4ada) != '\0') {
          fparam_1 = -(double)(local_f8 * *(float *)(iVar14 + 0x4a90) +
                              (local_100 * *(float *)(iVar14 + 0x4a88) +
                              local_fc * *(float *)(iVar14 + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(iVar11 + 0x286c)) goto LAB_000d74f0;
          fparam_1 = ((double (*)())_gleLightExponentPow)(iVar5,iVar14 + 0x4a70,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                                fparam_6,fparam_7,fparam_8,in_stack_fffffea8,in_stack_fffffeb0,
                                in_stack_fffffeb8,in_stack_fffffec0,in_stack_fffffec8);
          dVar16 = (double)(float)((double)dVar16 * fparam_1);
          iVar5 = iVar5;
        }
        if (*(char *)(param_1 + 0x30ae) == '\0') {
          if (local_d0 == 0) {
            local_108 = (local_f8 + dVar20);
            local_110 = local_100;
            local_10c = local_fc;
          }
          else {
            local_110 = -*pfVar8;
            local_10c = -pfVar8[1];
            local_108 = -pfVar8[2];
            (**(code **)puVar4)(param_1,&local_110,&local_110);
            local_110 = local_110 + local_100;
            local_10c = local_10c + local_fc;
            local_108 = local_108 + local_f8;
          }
          iVar5 = (**(code **)puVar4)(param_1,&local_110,&local_110);
          fparam_1 = extraout_f1_02;
        }
        if ((double)dVar16 != (double)FLOAT_00108e50) {
          dVar17 = (double)*(float *)(iVar15 + 0x44);
          fparam_5 = (double)local_fc;
          fparam_4 = (double)*(float *)(iVar15 + 0x40);
          fparam_7 = (double)local_100;
          fparam_8 = (double)*(float *)(iVar15 + 0x48);
          fparam_6 = (double)local_f8;
          dVar27 = (double)*(float *)(iVar13 + 0x50);
          dVar26 = (double)*(float *)(iVar13 + 0x54);
          dVar25 = (double)*(float *)(iVar13 + 0x58);
          dVar19 = (double)(float)(fparam_8 * fparam_6 +
                                  (double)(float)(fparam_4 * fparam_7 +
                                                 (double)(float)(dVar17 * fparam_5)));
          if (-(double)dVar19 <= (double)FLOAT_00108e50) {
LAB_000d74a4:
            dVar19 = (double)FLOAT_00108e50;
            fparam_1 = (double)dVar19;
            dVar17 = (double)dVar19;
          }
          else {
            dVar27 = -(double)(dVar19 * *(float *)(iVar13 + 0x60) - dVar27);
            dVar26 = -(double)(dVar19 * *(float *)(iVar13 + 100) - dVar26);
            dVar25 = -(double)(dVar19 * *(float *)(iVar13 + 0x68) - dVar25);
            if (*(char *)(param_1 + 0x30ae) == '\0') {
              dVar17 = -(double)(float)(fparam_8 * (double)local_108 +
                                       (double)(float)(fparam_4 * (double)local_110 +
                                                      (double)(float)(dVar17 * (double)local_10c)));
            }
            else {
              local_f0 = (float)(fparam_8 * fparam_5 - (double)(float)(dVar17 * fparam_6));
              dVar19 = (double)local_f0;
              local_ec = (float)((double)*(float *)(iVar15 + 0x40) * fparam_6 -
                                (double)(float)(fparam_8 * fparam_7));
              dVar18 = (double)local_ec;
              local_e8 = (float)((double)*(float *)(iVar15 + 0x44) * fparam_7 -
                                (double)(float)((double)*(float *)(iVar15 + 0x40) * fparam_5));
              dVar17 = (double)local_e8;
              fVar1 = (*(float *)(iVar15 + 0x48) * dVar18 - (float)((double)*(float *)(iVar15 + 0x44) * dVar17));
              fVar2 = (float)((double)*(float *)(iVar15 + 0x40) * dVar17 -
                             (double)(*(float *)(iVar15 + 0x48) * dVar19));
              local_e0 = (float)((double)(fVar1 + fVar1) + fparam_7);
              local_dc = (float)((double)(fVar2 + fVar2) + fparam_5);
              fVar1 = (*(float *)(iVar15 + 0x44) * dVar19 - (*(float *)(iVar15 + 0x40) * dVar18));
              local_d8 = (float)((double)(fVar1 + fVar1) + fparam_6);
              dVar17 = (double)(local_d8 * local_108 + (local_e0 * local_110 + local_dc * local_10c));
            }
            if (dVar17 <= (double)dVar23) goto LAB_000d74a4;
            fparam_2 = (double)*(float *)(iVar12 + 0x40);
            dVar17 = _pow(dVar17,fparam_2);
            fVar1 = (float)dVar17;
            dVar19 = (double)(fVar1 * *(float *)(iVar13 + 0x78));
            iVar5 = extraout_r3_01;
            fparam_1 = (double)(fVar1 * *(float *)(iVar13 + 0x74));
            dVar17 = (double)(fVar1 * *(float *)(iVar13 + 0x70));
          }
          if ((double)dVar16 == (double)dVar20) {
            dVar30 = (double)(dVar30 + dVar27);
            dVar29 = (double)(dVar29 + dVar26);
            dVar28 = (double)(dVar28 + dVar25);
            dVar24 = (double)(float)((double)dVar24 + dVar17);
            dVar22 = (double)(float)((double)dVar22 + fparam_1);
            dVar21 = (double)(dVar21 + dVar19);
          }
          else {
            dVar21 = (double)(dVar16 * dVar19 + dVar21);
            dVar30 = (double)(dVar16 * dVar27 + dVar30);
            dVar29 = (double)(dVar16 * dVar26 + dVar29);
            dVar28 = (double)(dVar16 * dVar25 + dVar28);
            dVar24 = (double)(float)((double)dVar16 * dVar17 + (double)dVar24);
            dVar22 = (double)(float)((double)dVar16 * fparam_1 + (double)dVar22);
          }
        }
      }
      else {
        dVar19 = (double)*(float *)(iVar15 + 0x44);
        fparam_6 = (double)*(float *)(iVar14 + 0x4a80);
        fparam_7 = (double)*(float *)(iVar15 + 0x40);
        fparam_8 = (double)*(float *)(iVar15 + 0x48);
        dVar16 = (double)*(float *)(iVar14 + 0x4a84);
        dVar30 = (double)(dVar30 + *(float *)(iVar13 + 0x50));
        dVar17 = (double)(float)(fparam_8 * (double)dVar16 +
                                (double)(float)(fparam_7 * (double)*(float *)(iVar14 + 0x4a7c) +
                                               (double)(float)((double)dVar19 * fparam_6)));
        dVar29 = (double)(dVar29 + *(float *)(iVar13 + 0x54));
        dVar28 = (double)(dVar28 + *(float *)(iVar13 + 0x58));
        fparam_1 = -dVar17;
        if ((double)dVar23 < fparam_1) {
          dVar30 = -(double)(float)(dVar17 * (double)*(float *)(iVar13 + 0x60) - (double)dVar30);
          dVar29 = -(double)(float)(dVar17 * (double)*(float *)(iVar13 + 100) - (double)dVar29);
          dVar28 = -(double)(float)(dVar17 * (double)*(float *)(iVar13 + 0x68) - (double)dVar28);
          if (*(char *)(param_1 + 0x30ae) == '\0') {
            fparam_1 = -(double)(float)(fparam_8 * (double)*(float *)(iVar10 + 0x2888) +
                                       (double)(float)(fparam_7 *
                                                       (double)*(float *)(iVar10 + 0x2880) +
                                                      (double)(dVar19 * *(float *)(
                                                  iVar10 + 0x2884))));
          }
          else {
            local_f8 = *(float *)(iVar14 + 0x4a84);
            local_100 = (float)((double)*(float *)(iVar15 + 0x48) * fparam_6 -
                               (double)(dVar19 * dVar16));
            local_fc = (*(float *)(iVar15 + 0x40) * dVar16 - (*(float *)(iVar15 + 0x48) * *(float *)(iVar14 + 0x4a7c)));
            fVar1 = *(float *)(iVar15 + 0x44) * local_100 -
                    (*(float *)(iVar15 + 0x40) * local_fc);
            fparam_1 = (double)((fVar1 + fVar1) + dVar16);
          }
          if ((double)dVar23 < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar5,iVar12 + 0x1e8,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                                  fparam_6,fparam_7,fparam_8,in_stack_fffffea8,in_stack_fffffeb0,
                                  in_stack_fffffeb8,in_stack_fffffec0,in_stack_fffffec8);
            dVar28 = (double)(float)(fparam_1 * (double)*(float *)(iVar13 + 0x78) + (double)dVar28);
            dVar30 = (double)(float)(fparam_1 * (double)*(float *)(iVar13 + 0x70) + (double)dVar30);
            dVar29 = (double)(float)(fparam_1 * (double)*(float *)(iVar13 + 0x74) + (double)dVar29);
            iVar5 = iVar5;
          }
        }
      }
LAB_000d74f0:
      uVar9 = uVar9 + 1;
      iVar14 = iVar14 + 0x6c;
      iVar13 = iVar13 + 0x30;
      iVar10 = iVar10 + 0x80;
      iVar11 = iVar11 + 0x80;
    } while( true );
  }
  goto LAB_000d7548;
LAB_000d7508:
  if (*(short *)(param_1 + 0x30a8) == -0x7e06) {
    *(float *)(iVar15 + 0x50) = (float)(double)dVar24;
    *(float *)(iVar15 + 0x54) = (float)(double)dVar22;
    *(float *)(iVar15 + 0x58) = (float)(double)dVar21;
  }
  else {
    dVar30 = (double)(dVar30 + dVar24);
    dVar29 = (double)(dVar29 + dVar22);
    dVar28 = (double)(dVar28 + dVar21);
  }
  *(undefined4 *)(iVar15 + 0x3c) = uVar3;
  *(float *)(iVar15 + 0x30) = (float)(double)dVar30;
  *(float *)(iVar15 + 0x34) = (float)(double)dVar29;
  *(float *)(iVar15 + 0x38) = (float)(double)dVar28;
LAB_000d7548:
  iVar7 = iVar7 + 1;
  if (iStack00000020 <= iVar7) {
    return;
  }
  goto LAB_000d6f10;
}

/* _gleVtxLightFastRGBAFrontPtr @ 0xd7564 (376 bytes) */
void _gleVtxLightFastRGBAFrontPtr(int param_1,int *param_2,int param_3,double fparam_1)
{
  undefined4 uVar1;
  int iVar2;
  int extraout_r3;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  double dVar11;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double fparam_7;
  double fparam_8;
  float dVar12;
  float dVar13;
  float dVar14;
  double in_stack_ffffff68;
  double in_stack_ffffff70;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  double in_stack_ffffff88;
  
  iVar3 = 0;
  uVar4 = *(uint *)(param_1 + 0x30a0);
  iVar2 = param_1;
  if (param_3 < 1) {
LAB_000d76d0:
    FUN_00008b68();
    return;
  }
LAB_000d7598:
  iVar7 = *param_2;
  param_2 = param_2 + 1;
  if ((*(byte *)(iVar7 + 0x7e) & 2) != 0) {
    iVar9 = *(int *)(iVar7 + 0x74);
    *(byte *)(iVar7 + 0x7e) = *(byte *)(iVar7 + 0x7e) & 0xfd;
    if (*(char *)(iVar9 + 0x234) != '\0') {
      iVar2 = _gleUpdateLightRGBASums(param_1,iVar9,0);
    }
    dVar14 = (double)*(float *)(iVar9 + 0x1e8);
    iVar8 = iVar9 + 0x50;
    dVar13 = (double)*(float *)(iVar9 + 0x1ec);
    dVar12 = (double)*(float *)(iVar9 + 0x1f0);
    uVar5 = 0;
    uVar1 = *(undefined4 *)(iVar9 + 0x1dc);
    iVar6 = param_1 + 0x2820;
    iVar10 = param_1 + 0x4a70;
    do {
      if ((uVar4 & 1 << (uVar5 & 0x3f)) == 0) {
        if (uVar4 >> (uVar5 & 0x3f) == 0) goto LAB_000d76b4;
      }
      else {
        fparam_8 = (double)*(float *)(iVar7 + 0x48);
        fparam_7 = (double)FLOAT_00108e50;
        dVar11 = (double)(float)(fparam_8 * (double)*(float *)(iVar10 + 0x14) +
                                (double)(*(float *)(iVar7 + 0x40) * *(float *)(iVar10 + 0xc) +
                                        *(float *)(iVar7 + 0x44) * *(float *)(iVar10 + 0x10)));
        if (fparam_7 < dVar11) {
          dVar13 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x14) + (double)dVar13);
          dVar12 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x18) + (double)dVar12);
          dVar14 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x10) + (double)dVar14);
          dVar11 = (double)(float)(fparam_8 * (double)*(float *)(iVar6 + 0x68) +
                                  (double)(*(float *)(iVar7 + 0x40) * *(float *)(iVar6 + 0x60) +
                                          *(float *)(iVar7 + 0x44) * *(float *)(iVar6 + 100)));
          if (fparam_7 < dVar11) {
            dVar11 = ((double (*)())_gleMaterialShinePow)(iVar2,iVar9 + 0x1e8,dVar11,in_f2,in_f3,in_f4,in_f5,in_f6,fparam_7,
                                fparam_8,in_stack_ffffff68,in_stack_ffffff70,in_stack_ffffff78,
                                in_stack_ffffff80,in_stack_ffffff88);
            dVar14 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x20) + (double)dVar14);
            dVar13 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x24) + (double)dVar13);
            dVar12 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x28) + (double)dVar12);
            iVar2 = iVar2;
          }
        }
      }
      uVar5 = uVar5 + 1;
      iVar10 = iVar10 + 0x6c;
      iVar8 = iVar8 + 0x30;
      iVar6 = iVar6 + 0x80;
    } while( true );
  }
  goto LAB_000d76c4;
LAB_000d76b4:
  *(undefined4 *)(iVar7 + 0x3c) = uVar1;
  *(float *)(iVar7 + 0x30) = (float)(double)dVar14;
  *(float *)(iVar7 + 0x34) = (float)(double)dVar13;
  *(float *)(iVar7 + 0x38) = (float)(double)dVar12;
LAB_000d76c4:
  iVar3 = iVar3 + 1;
  if (param_3 <= iVar3) goto LAB_000d76d0;
  goto LAB_000d7598;
}

/* _gleVtxLightFastRGBABackPtr @ 0xd76dc (380 bytes) */
void _gleVtxLightFastRGBABackPtr(int param_1,int *param_2,int param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 uVar1;
  int iVar2;
  int extraout_r3;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  double fparam_1_00;
  double dVar11;
  double fparam_8_00;
  float dVar12;
  float dVar13;
  float dVar14;
  float dVar15;
  double in_stack_ffffff68;
  double in_stack_ffffff70;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  double in_stack_ffffff88;
  
  iVar3 = 0;
  uVar4 = *(uint *)(param_1 + 0x30a0);
  iVar2 = param_1;
  if (param_3 < 1) {
LAB_000d784c:
    FUN_00008b68();
    return;
  }
LAB_000d7710:
  iVar7 = *param_2;
  param_2 = param_2 + 1;
  if ((*(byte *)(iVar7 + 0x7e) & 4) != 0) {
    iVar9 = *(int *)(iVar7 + 0x78);
    *(byte *)(iVar7 + 0x7e) = *(byte *)(iVar7 + 0x7e) & 0xfb;
    if (*(char *)(iVar9 + 0x234) != '\0') {
      iVar2 = _gleUpdateLightRGBASums(param_1,iVar9,1);
    }
    dVar15 = (double)*(float *)(iVar9 + 0x1e8);
    iVar8 = iVar9 + 0x50;
    dVar14 = (double)*(float *)(iVar9 + 0x1ec);
    dVar13 = (double)*(float *)(iVar9 + 0x1f0);
    uVar5 = 0;
    uVar1 = *(undefined4 *)(iVar9 + 0x1dc);
    iVar6 = param_1 + 0x2820;
    iVar10 = param_1 + 0x4a70;
    do {
      if ((uVar4 & 1 << (uVar5 & 0x3f)) == 0) {
        if (uVar4 >> (uVar5 & 0x3f) == 0) goto LAB_000d7830;
      }
      else {
        fparam_8_00 = (double)*(float *)(iVar7 + 0x48);
        dVar11 = (double)FLOAT_00108e50;
        dVar12 = (double)(float)(fparam_8_00 * (double)*(float *)(iVar10 + 0x14) +
                                (double)(*(float *)(iVar7 + 0x40) * *(float *)(iVar10 + 0xc) +
                                        *(float *)(iVar7 + 0x44) * *(float *)(iVar10 + 0x10)));
        if (dVar11 < -(double)dVar12) {
          dVar15 = -(double)(dVar12 * *(float *)(iVar8 + 0x10) - dVar15);
          dVar14 = -(double)(dVar12 * *(float *)(iVar8 + 0x14) - dVar14);
          fparam_1_00 = -(double)(float)(fparam_8_00 * (double)*(float *)(iVar6 + 0x68) +
                                        (double)(*(float *)(iVar7 + 0x40) * *(float *)(iVar6 + 0x60)
                                                + *(float *)(iVar7 + 0x44) * *(float *)(iVar6 + 100)
                                                ));
          dVar13 = -(double)(dVar12 * *(float *)(iVar8 + 0x18) - dVar13);
          if (dVar11 < fparam_1_00) {
            dVar11 = ((double (*)())_gleMaterialShinePow)(iVar2,iVar9 + 0x1e8,fparam_1_00,fparam_2,fparam_3,fparam_4,fparam_5,
                                fparam_6,dVar11,fparam_8_00,in_stack_ffffff68,in_stack_ffffff70,
                                in_stack_ffffff78,in_stack_ffffff80,in_stack_ffffff88);
            dVar15 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x20) + (double)dVar15);
            dVar14 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x24) + (double)dVar14);
            dVar13 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x28) + (double)dVar13);
            iVar2 = iVar2;
          }
        }
      }
      uVar5 = uVar5 + 1;
      iVar10 = iVar10 + 0x6c;
      iVar8 = iVar8 + 0x30;
      iVar6 = iVar6 + 0x80;
    } while( true );
  }
  goto LAB_000d7840;
LAB_000d7830:
  *(undefined4 *)(iVar7 + 0x3c) = uVar1;
  *(float *)(iVar7 + 0x30) = (float)(double)dVar15;
  *(float *)(iVar7 + 0x34) = (float)(double)dVar14;
  *(float *)(iVar7 + 0x38) = (float)(double)dVar13;
LAB_000d7840:
  iVar3 = iVar3 + 1;
  if (param_3 <= iVar3) goto LAB_000d784c;
  goto LAB_000d7710;
}

/* _gleBeginLinesRenderSmooth @ 0xd7858 (52 bytes) */
void _gleBeginLinesRenderSmooth(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushAtomicFunc_00112224;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderSmoothLinesFunc_00112220;
  return;
}

/* _gleBeginLinesRenderFlat @ 0xd788c (52 bytes) */
void _gleBeginLinesRenderFlat(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushAtomicFunc_00112224;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderFlatLinesFunc_0011221c;
  return;
}

/* _gleBeginLinesRenderTCL @ 0xd78c0 (52 bytes) */
void _gleBeginLinesRenderTCL(param_1)
  int param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR__gleFlushAtomicTCLFunc_00112218;
  *(undefined4 *)(param_1 + 0x4858) = *(undefined4 *)(param_1 + 0x4854);
  *(undefined **)(param_1 + 0x4a0c) = puVar1;
  *(undefined **)(param_1 + 0x4a08) = PTR__gleRenderLinesTCLFunc_00112214;
  return;
}

