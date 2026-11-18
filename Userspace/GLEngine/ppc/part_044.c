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
void _LFSStreamChunkListGetStream(param_1, param_2, param_3, forwardedArg4)
  int *param_1;
  int param_2;
  int *param_3;
  undefined4 forwardedArg4;
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
    _LFSStreamChunkGetStream(iVar4,forwardedArg4,&local_30,0);
    *param_3 = *param_3 + local_30;
  }
  if ((param_2 != 0) && (iVar4 = *param_1, iVar4 != 0)) {
    iVar3 = 0;
    do {
      uVar1 = _LFSStreamChunkGetStream(iVar4,forwardedArg4,&local_30,0);
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
            uVar1 = _LFSStreamChunkGetStream(iVar4,forwardedArg4,auStack_2c,uVar5);
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
void _gleFPChanged(glContext)
  int glContext;
{
  undefined *setClipInterpFunc;
  
  _gleSelectVertexSubmitFunc(glContext);
  setClipInterpFunc = PTR__gleSetClipInterpFunc_00112038;
  *(undefined **)(glContext + 0x49c8) = PTR__gleSetEyeInterpFunc_0011203c;
  *(undefined **)(glContext + 0x49cc) = setClipInterpFunc;
  return;
}

/* _gleFPEnable @ 0xd22dc (64 bytes) */
void _gleFPEnable(glContext)
  int glContext;
{
  ((void (*)())_gleFPChanged)(glContext);
  _gleSelectVertexSubmitFunc(glContext);
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x1000000;
  return;
}

/* _gleFPDisable @ 0xd231c (64 bytes) */
void _gleFPDisable(glContext)
  int glContext;
{
  ((void (*)())_gleFPChanged)(glContext);
  _gleSelectVertexSubmitFunc(glContext);
  *(uint *)(glContext + 0x31c) = *(uint *)(glContext + 0x31c) | 0x1000000;
  return;
}

/* _zeroTargetExtractor @ 0xd235c (8 bytes) */
int _zeroTargetExtractor()
{
  return 0;
}

/* _gleGetHashMachineObjectNameTargetPairs @ 0xd2364 (400 bytes) */
void _gleGetHashMachineObjectNameTargetPairs(glContext, param_2, param_3, valuePtr)
  int glContext;
  int *param_2;
  int param_3;
  int *valuePtr;
{
  undefined *zeroTargetExtractor;
  int *piVar2;
  undefined4 uVar3;
  int a2;
  int *a3;
  undefined4 incomingR7;
  undefined4 incomingR8;
  int *piVar4;
  int a6;
  code *pcVar5;
  int iVar6;
  
  zeroTargetExtractor = PTR__zeroTargetExtractor_00110e30;
  iVar6 = 0;
  a2 = param_3;
  a3 = valuePtr;
  if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
    _pthread_mutex_lock(*(int *)(glContext + 0x5148) + 0x8028);
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
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
    }
    *valuePtr = 0;
  }
  else {
    piVar2 = (int *)_malloc(iVar6 * 8 + 4);
    *piVar2 = iVar6;
    *valuePtr = (int)piVar2;
    pcVar5 = (code *)PTR__gleTextureTargetExtractor_0011215c;
    if ((param_3 != 2) &&
       (pcVar5 = (code *)PTR__glePipelineProgramTargetExtactor_00112158, param_3 != 4)) {
      pcVar5 = (code *)zeroTargetExtractor;
    }
    iVar6 = 0;
    piVar2 = param_2;
    do {
      piVar4 = piVar2 + 1;
      for (piVar2 = (int *)*piVar2; piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
        a6 = *valuePtr;
        *(int *)((iVar6 + 1) * 4 + a6) = piVar2[1];
        iVar6 = iVar6 + 2;
        uVar3 = (*pcVar5)(glContext,piVar2,a2,a3,incomingR7,incomingR8,a6);
        *(undefined4 *)(iVar6 * 4 + *valuePtr) = uVar3;
      }
      piVar2 = piVar4;
    } while (piVar4 <= param_2 + 0x3ff);
    if (*(char *)(*(int *)(glContext + 0x5148) + 0x8024) != '\0') {
      _pthread_mutex_unlock(*(int *)(glContext + 0x5148) + 0x8028);
      return;
    }
  }
  return;
}

/* _gleImagingTexFormatToInternal @ 0xd24f4 (560 bytes) */
int _gleImagingTexFormatToInternal(internalformat)
  uint internalformat;
{
  bool bVar1;
  uint uVar2;
  
  if (internalformat < 0x805c) {
    if (0x8054 < internalformat) {
      return 0x1908;
    }
    if (0x803e < internalformat) {
      if (internalformat == 0x8049) {
        return 0x8049;
      }
      if (internalformat < 0x804a) {
        if (0x8042 < internalformat) {
          return 0x190a;
        }
        return 0x1909;
      }
      if (internalformat < 0x804e) {
        return 0x8049;
      }
      if (internalformat < 0x804f) {
        return 0;
      }
      return 0x1907;
    }
    if (0x803a < internalformat) {
      return 0x1906;
    }
    if (internalformat == 4) {
      return 0x1908;
    }
    if (internalformat < 5) {
      if (internalformat == 2) {
        return 0x190a;
      }
      if (internalformat < 3) {
        if (internalformat != 1) {
          return 0;
        }
        return 0x1909;
      }
      return 0x1907;
    }
    if (internalformat < 0x1906) {
      return 0;
    }
    if (internalformat < 0x190b) {
      return internalformat;
    }
    bVar1 = internalformat == 0x2a10;
  }
  else {
    if (internalformat == 0x8817) {
      return 0x8049;
    }
    if (internalformat < 0x8818) {
      if (internalformat == 0x84ed) {
        return 0x1907;
      }
      if (internalformat < 0x84ee) {
        if (internalformat == 0x84ea) {
          return 0x1909;
        }
        if (0x84ea < internalformat) {
          if (internalformat == 0x84eb) {
            return 0x190a;
          }
          if (internalformat != 0x84ec) {
            return 0;
          }
          return 0x8049;
        }
        uVar2 = 0x84e9;
      }
      else {
        if (internalformat == 0x8814) {
          return 0x1908;
        }
        if (internalformat < 0x8815) {
          if (internalformat == 0x84ee) {
            return 0x1908;
          }
          return 0;
        }
        if (internalformat == 0x8815) {
          return 0x1907;
        }
        uVar2 = 0x8816;
      }
      if (internalformat == uVar2) {
        return 0x1906;
      }
      return 0;
    }
    if (internalformat == 0x881c) {
      return 0x1906;
    }
    if (0x881c < internalformat) {
      if (internalformat == 0x881e) {
        return 0x1909;
      }
      if (0x881d < internalformat) {
        if ((internalformat != 0x881f) && (internalformat != 0x8837)) {
          return 0;
        }
        return 0x190a;
      }
      return 0x8049;
    }
    if (internalformat == 0x8819) {
      return 0x190a;
    }
    if (internalformat < 0x8819) {
      return 0x1909;
    }
    if (internalformat == 0x881a) {
      return 0x1908;
    }
    bVar1 = internalformat == 0x881b;
  }
  if (bVar1) {
    return 0x1907;
  }
  return 0;
}

/* _gleImagingUnpackData @ 0xd2724 (316 bytes) */
void _gleImagingUnpackData(param_1, param_2, height, format, param_5, param_6, type, param_8, filterData)
  int param_1;
  int param_2;
  undefined4 height;
  undefined4 format;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 type;
  int param_8;
  undefined4 filterData;
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
  uVar3 = height;
  _glePixelPackSettings
            (param_1,param_6,type,param_2,height,iVar4,puVar5,piVar6,&local_50,auStack_4c,
             auStack_48,auStack_44);
  _glgConvertType(format,param_5,auStack_b8,auStack_b4,uVar3,iVar4,puVar5,piVar6);
  puVar1 = auStack_a8;
  puVar2 = auStack_a4;
  _glgConvertType(param_6,type,puVar1,puVar2,uVar3,iVar4,puVar5,piVar6);
  local_c0 = param_8 + local_3c[0];
  local_98 = 5;
  local_bc = local_50;
  local_a0 = 2;
  local_b0 = filterData;
  local_9c = 0;
  local_94 = param_2;
  local_90 = height;
  local_ac = _glePixelBytes(param_6,type);
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
void _gleImagingPackData(param_1, rowWidth, param_3, format, type, param_6, param_7, filterData, param_9)
  int param_1;
  int rowWidth;
  undefined4 param_3;
  undefined4 format;
  undefined4 type;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 filterData;
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
            (param_1,format,type,rowWidth,param_3,iVar4,puVar5,piVar6,&local_50,auStack_4c,
             auStack_48,auStack_44);
  _glgConvertType(format,type,auStack_b8,auStack_b4,uVar3,iVar4,puVar5,piVar6);
  puVar1 = auStack_a8;
  puVar2 = auStack_a4;
  _glgConvertType(param_6,param_7,puVar1,puVar2,uVar3,iVar4,puVar5,piVar6);
  local_c0 = filterData;
  local_bc = _glePixelBytes(format,type);
  local_bc = rowWidth * local_bc;
  local_b0 = param_9 + local_3c[0];
  local_98 = 5;
  local_a0 = 2;
  local_ac = local_50;
  local_54 = 0;
  local_9c = (uint)(*(char *)(param_1 + 0x31c8) != '\0');
  if (*(char *)(param_1 + 0x31c9) != '\0') {
    local_9c = local_9c | 4;
  }
  local_94 = rowWidth;
  local_90 = param_3;
  _glgProcessPixels(param_1 + 0x31a8,&local_c0,puVar1,puVar2,uVar3,iVar4,0,piVar6);
  return;
}

/* _gleImagingScaleAndBias @ 0xd2998 (936 bytes) */
void _gleImagingScaleAndBias(unusedArg1, scaleBias, pixels, format, startPixel, pixelCount, clamp)
  undefined4 unusedArg1;
  float *scaleBias;
  int pixels;
  undefined4 format;
  int startPixel;
  int pixelCount;
  int clamp;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int componentCount;
  int pixelIndex;
  float *pixelPtr;
  
  if (((((*scaleBias != FLOAT_00108e54) || (scaleBias[2] != FLOAT_00108e54)) ||
       (scaleBias[4] != FLOAT_00108e54)) ||
      ((scaleBias[6] != FLOAT_00108e54 || (scaleBias[1] != FLOAT_00108e50)))) ||
     ((scaleBias[3] != FLOAT_00108e50 ||
      ((scaleBias[5] != FLOAT_00108e50 || (scaleBias[7] != FLOAT_00108e50)))))) {
    componentCount = _gleComponents(format);
    pixelIndex = 0;
    pixelPtr = (float *)(pixels + startPixel * componentCount * 4);
    if (0 < pixelCount) {
      do {
        switch(format) {
        case 0x1906:
          fVar1 = *pixelPtr * scaleBias[6] + scaleBias[7];
          if ((clamp != 0) &&
             ((fVar2 = FLOAT_00108e50, !(FLOAT_00108e50 < fVar1) ||
              (fVar2 = FLOAT_00108e54, FLOAT_00108e54 < fVar1)))) {
            fVar1 = fVar2;
          }
          *pixelPtr = fVar1;
          break;
        case 0x1907:
          fVar1 = *pixelPtr * *scaleBias + scaleBias[1];
          fVar2 = pixelPtr[1] * scaleBias[2] + scaleBias[3];
          fVar3 = pixelPtr[2] * scaleBias[4] + scaleBias[5];
          if (clamp != 0) {
            fVar5 = FLOAT_00108e50;
            if ((!(FLOAT_00108e50 < fVar1)) || (fVar5 = FLOAT_00108e54, FLOAT_00108e54 < fVar1)) {
              fVar1 = fVar5;
            }
            fVar5 = FLOAT_00108e50;
            if ((!(FLOAT_00108e50 < fVar2)) || (fVar5 = FLOAT_00108e54, FLOAT_00108e54 < fVar2)) {
              fVar2 = fVar5;
            }
            fVar5 = FLOAT_00108e50;
            if ((!(FLOAT_00108e50 < fVar3)) || (fVar5 = FLOAT_00108e54, FLOAT_00108e54 < fVar3)) {
              fVar3 = fVar5;
            }
          }
          *pixelPtr = fVar1;
          pixelPtr[1] = fVar2;
          pixelPtr = pixelPtr + 2;
          *pixelPtr = fVar3;
          break;
        case 0x1908:
          fVar1 = *pixelPtr * *scaleBias + scaleBias[1];
          fVar3 = pixelPtr[1] * scaleBias[2] + scaleBias[3];
          fVar5 = pixelPtr[2] * scaleBias[4] + scaleBias[5];
          fVar2 = pixelPtr[3] * scaleBias[6] + scaleBias[7];
          if (clamp != 0) {
            fVar4 = FLOAT_00108e50;
            if ((!(FLOAT_00108e50 < fVar1)) || (fVar4 = FLOAT_00108e54, FLOAT_00108e54 < fVar1)) {
              fVar1 = fVar4;
            }
            fVar4 = FLOAT_00108e50;
            if ((!(FLOAT_00108e50 < fVar3)) || (fVar4 = FLOAT_00108e54, FLOAT_00108e54 < fVar3)) {
              fVar3 = fVar4;
            }
            fVar4 = FLOAT_00108e50;
            if ((!(FLOAT_00108e50 < fVar5)) || (fVar4 = FLOAT_00108e54, FLOAT_00108e54 < fVar5)) {
              fVar5 = fVar4;
            }
            fVar4 = FLOAT_00108e50;
            if ((!(FLOAT_00108e50 < fVar2)) || (fVar4 = FLOAT_00108e54, FLOAT_00108e54 < fVar2)) {
              fVar2 = fVar4;
            }
          }
          *pixelPtr = fVar1;
          pixelPtr[1] = fVar3;
          pixelPtr = pixelPtr + 2;
          *pixelPtr = fVar5;
          goto LAB_000d2d2c;
        case 0x1909:
          fVar1 = *pixelPtr * *scaleBias + scaleBias[1];
          if ((clamp != 0) &&
             ((fVar2 = FLOAT_00108e50, !(FLOAT_00108e50 < fVar1) ||
              (fVar2 = FLOAT_00108e54, FLOAT_00108e54 < fVar1)))) {
            fVar1 = fVar2;
          }
          *pixelPtr = fVar1;
          break;
        case 0x190a:
          fVar1 = *pixelPtr * *scaleBias + scaleBias[1];
          fVar2 = pixelPtr[1] * scaleBias[6] + scaleBias[7];
          if (clamp != 0) {
            fVar3 = FLOAT_00108e50;
            if ((!(FLOAT_00108e50 < fVar1)) || (fVar3 = FLOAT_00108e54, FLOAT_00108e54 < fVar1)) {
              fVar1 = fVar3;
            }
            fVar3 = FLOAT_00108e50;
            if ((!(FLOAT_00108e50 < fVar2)) || (fVar3 = FLOAT_00108e54, FLOAT_00108e54 < fVar2)) {
              fVar2 = fVar3;
            }
          }
          *pixelPtr = fVar1;
LAB_000d2d2c:
          pixelPtr = pixelPtr + 1;
          *pixelPtr = fVar2;
          break;
        default:
          goto switchD_000d2a7c_default;
        }
        pixelPtr = pixelPtr + 1;
switchD_000d2a7c_default:
        pixelIndex = pixelIndex + 1;
      } while (pixelIndex < pixelCount);
    }
  }
  return;
}

/* _gleGetHistogram @ 0xd2d54 (3104 bytes) */
void _gleGetHistogram(glContext, unusedArg2, reset, format, type, values)
  int glContext;
  undefined4 unusedArg2;
  int reset;
  uint format;
  uint type;
  int values;
{
  bool formatIsAbgr;
  bool formatIsBgr;
  bool formatIsBgra;
  bool formatIsRed;
  bool formatIsNotGreen;
  bool formatIsAlpha;
  bool formatIsRgb;
  bool swapBytes;
  bool formatIsRgba;
  bool formatIsLuminance;
  bool formatIsBlue;
  bool formatIsLuminanceAlpha;
  bool formatAboveRgba;
  bool formatAboveBlue;
  bool formatAboveAbgr;
  double uintToDoubleBias;
  undefined1 uVar18;
  ushort uVar17;
  int iVar19;
  int binsRemaining;
  int packAlignment;
  int pixelBytes;
  int binByteOffset;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float *pfVar25;
  float *dstCursor;
  int binCountThenRemaining;
  float *histogramTable;
  float *binCursor;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  
  histogramTable = *(float **)(glContext + 0x3384);
  binCountThenRemaining = *(int *)(glContext + 0x3388);
  pixelBytes = _glePixelBytes(format,type);
  uintToDoubleBias = DOUBLE_00108d58;
  packAlignment = *(int *)(glContext + 0x31c4);
  dstCursor = (float *)(values + pixelBytes * *(int *)(glContext + 0x31bc));
  if (packAlignment == 4) {
    if (((uint)dstCursor & 3) != 0) {
      dstCursor = (float *)((uint)(dstCursor + 1) & 0xfffffffc);
    }
  }
  else if (packAlignment < 5) {
    if ((packAlignment == 2) && (((uint)dstCursor & 1) != 0)) {
      dstCursor = (float *)((int)dstCursor + 1);
    }
  }
  else if ((packAlignment == 8) && (((uint)dstCursor & 7) != 0)) {
    dstCursor = (float *)((uint)(dstCursor + 2) & 0xfffffff8);
  }
  if (0 < binCountThenRemaining) {
    formatAboveBlue = 0x1905 < format;
    formatIsAbgr = format == 0x8000;
    formatIsRed = format == 0x1903;
    formatIsNotGreen = format != 0x1904;
    formatIsBgr = format == 0x80e0;
    formatIsBgra = format == 0x80e1;
    formatIsAlpha = format == 0x1906;
    formatIsRgb = format == 0x1907;
    swapBytes = *(char *)(glContext + 0x31c8) != '\0';
    formatAboveAbgr = 0x8000 < format;
    formatIsRgba = format == 0x1908;
    formatIsLuminance = format == 0x1909;
    formatAboveRgba = 0x1908 < format;
    formatIsBlue = format == 0x1905;
    formatIsLuminanceAlpha = format == 0x190a;
    binCursor = histogramTable;
    binsRemaining = binCountThenRemaining;
    do {
      if (type == 0x1406) {
        fVar21 = (float)((double)CONCAT44(0x43300000,-*binCursor) - uintToDoubleBias);
        fVar22 = (float)((double)CONCAT44(0x43300000,-binCursor[1]) - uintToDoubleBias);
        fVar23 = (float)((double)CONCAT44(0x43300000,-binCursor[2]) - uintToDoubleBias);
        fVar24 = (float)((double)CONCAT44(0x43300000,-binCursor[3]) - uintToDoubleBias);
        if (swapBytes) {
          fVar21 = GH_U2F((unsigned int)(((uint)GH_F2U(fVar21) >> 0x18 | (uint)GH_F2U(fVar21) >> 8 & 0xff00 |
                           ((uint)GH_F2U(fVar21) & 0xff00) << 8 | (int)GH_F2U(fVar21) << 0x18)));
          fVar22 = GH_U2F((unsigned int)(((uint)GH_F2U(fVar22) >> 0x18 | (uint)GH_F2U(fVar22) >> 8 & 0xff00 |
                           ((uint)GH_F2U(fVar22) & 0xff00) << 8 | (int)GH_F2U(fVar22) << 0x18)));
          fVar23 = GH_U2F((unsigned int)(((uint)GH_F2U(fVar23) >> 0x18 | (uint)GH_F2U(fVar23) >> 8 & 0xff00 |
                           ((uint)GH_F2U(fVar23) & 0xff00) << 8 | (int)GH_F2U(fVar23) << 0x18)));
          fVar24 = GH_U2F((unsigned int)(((uint)GH_F2U(fVar24) >> 0x18 | (uint)GH_F2U(fVar24) >> 8 & 0xff00 |
                           ((uint)GH_F2U(fVar24) & 0xff00) << 8 | (int)GH_F2U(fVar24) << 0x18)));
        }
        if (formatIsRgba) {
          *dstCursor = fVar21;
          dstCursor[1] = fVar22;
          dstCursor = dstCursor + 2;
          *dstCursor = fVar23;
          goto LAB_000d372c;
        }
        if (formatAboveRgba) {
          if (!formatIsAbgr) {
            if (formatAboveAbgr) {
              if (formatIsBgr) {
                *dstCursor = fVar23;
                goto LAB_000d3714;
              }
              if (formatIsBgra) {
                *dstCursor = fVar23;
                dstCursor[1] = fVar22;
                dstCursor = dstCursor + 2;
                *dstCursor = fVar21;
                goto LAB_000d372c;
              }
            }
            else {
              if (formatIsLuminance) goto LAB_000d3720;
              if (formatIsLuminanceAlpha) {
                *dstCursor = fVar21;
LAB_000d372c:
                dstCursor = dstCursor + 1;
                *dstCursor = fVar24;
                goto LAB_000d3730;
              }
            }
            goto LAB_000d3734;
          }
          *dstCursor = fVar24;
          dstCursor = dstCursor + 1;
          *dstCursor = fVar23;
LAB_000d3714:
          dstCursor[1] = fVar22;
          dstCursor = dstCursor + 2;
          *dstCursor = fVar21;
        }
        else if (formatIsBlue) {
          *dstCursor = fVar23;
        }
        else if (formatAboveBlue) {
          if (formatIsAlpha) {
            *dstCursor = fVar24;
          }
          else {
            if (!formatIsRgb) goto LAB_000d3734;
            *dstCursor = fVar21;
            dstCursor[1] = fVar22;
            dstCursor = dstCursor + 2;
            *dstCursor = fVar23;
          }
        }
        else if (formatIsRed) {
LAB_000d3720:
          *dstCursor = fVar21;
        }
        else {
          if (formatIsNotGreen) goto LAB_000d3734;
          *dstCursor = fVar22;
        }
LAB_000d3730:
        dstCursor = dstCursor + 1;
        goto LAB_000d3734;
      }
      if (0x1406 < type) goto LAB_000d3734;
      if (type != 0x1402) {
        if (type < 0x1403) {
          if (type == 0x1400) {
            if (formatIsRgba) {
LAB_000d3048:
              *(undefined1 *)dstCursor = *(undefined1 *)((int)binCursor + 3);
              *(undefined1 *)((int)dstCursor + 1) = *(undefined1 *)((int)binCursor + 7);
              uVar18 = *(undefined1 *)((int)binCursor + 0xb);
LAB_000d3074:
              dstCursor = (float *)((int)dstCursor + 2);
              *(undefined1 *)dstCursor = uVar18;
LAB_000d30ac:
              uVar18 = *(undefined1 *)((int)binCursor + 0xf);
            }
            else {
              if (!formatAboveRgba) {
                if (!formatIsBlue) goto LAB_000d2f78;
LAB_000d3020:
                uVar18 = *(undefined1 *)((int)binCursor + 0xb);
                goto LAB_000d2f38;
              }
LAB_000d2fc4:
              if (!formatIsAbgr) {
                if (formatAboveAbgr) {
                  if (formatIsBgr) {
                    *(undefined1 *)dstCursor = *(undefined1 *)((int)binCursor + 0xb);
                    *(undefined1 *)((int)dstCursor + 1) = *(undefined1 *)((int)binCursor + 7);
                    uVar18 = *(undefined1 *)((int)binCursor + 3);
LAB_000d2f54:
                    dstCursor = (float *)((int)dstCursor + 2);
                    *(undefined1 *)dstCursor = uVar18;
                    goto LAB_000d30b4;
                  }
                  if (!formatIsBgra) goto LAB_000d3734;
                  *(undefined1 *)dstCursor = *(undefined1 *)((int)binCursor + 0xb);
                  *(undefined1 *)((int)dstCursor + 1) = *(undefined1 *)((int)binCursor + 7);
                  uVar18 = *(undefined1 *)((int)binCursor + 3);
                  goto LAB_000d3074;
                }
                if (formatIsLuminance) {
LAB_000d309c:
                  uVar18 = *(undefined1 *)((int)binCursor + 3);
                  goto LAB_000d2f38;
                }
                if (!formatIsLuminanceAlpha) goto LAB_000d3734;
                *(undefined1 *)dstCursor = *(undefined1 *)((int)binCursor + 3);
                goto LAB_000d30ac;
              }
              *(undefined1 *)dstCursor = *(undefined1 *)((int)binCursor + 0xf);
              *(undefined1 *)((int)dstCursor + 1) = *(undefined1 *)((int)binCursor + 0xb);
              dstCursor = (float *)((int)dstCursor + 2);
              *(undefined1 *)dstCursor = *(undefined1 *)((int)binCursor + 7);
              uVar18 = *(undefined1 *)((int)binCursor + 3);
            }
            dstCursor = (float *)((int)dstCursor + 1);
            *(undefined1 *)dstCursor = uVar18;
          }
          else {
            if (type != 0x1401) goto LAB_000d3734;
            if (formatIsRgba) goto LAB_000d3048;
            if (formatAboveRgba) goto LAB_000d2fc4;
            if (formatIsBlue) goto LAB_000d3020;
LAB_000d2f78:
            if (formatAboveBlue) {
              if (!formatIsAlpha) {
                if (!formatIsRgb) goto LAB_000d3734;
                *(undefined1 *)dstCursor = *(undefined1 *)((int)binCursor + 3);
                *(undefined1 *)((int)dstCursor + 1) = *(undefined1 *)((int)binCursor + 7);
                uVar18 = *(undefined1 *)((int)binCursor + 0xb);
                goto LAB_000d2f54;
              }
              uVar18 = *(undefined1 *)((int)binCursor + 0xf);
            }
            else {
              if (formatIsRed) goto LAB_000d309c;
              if (formatIsNotGreen) goto LAB_000d3734;
              uVar18 = *(undefined1 *)((int)binCursor + 7);
            }
LAB_000d2f38:
            *(undefined1 *)dstCursor = uVar18;
          }
LAB_000d30b4:
          dstCursor = (float *)((int)dstCursor + 1);
          goto LAB_000d3734;
        }
        if ((type == 0x1404) || (0x1404 < type)) {
          local_80 = GH_F2U(*binCursor);
          local_7c = GH_F2U(binCursor[1]);
          local_78 = GH_F2U(binCursor[2]);
          local_74 = GH_F2U(binCursor[3]);
          if (swapBytes) {
            fVar24 = *binCursor;
            fVar23 = binCursor[1];
            fVar22 = binCursor[2];
            fVar21 = binCursor[3];
            local_80 = ((unsigned int)(((int)GH_F2U(fVar24) >> 0x18 | (uint)GH_F2U(fVar24) >> 8 & 0xff00 |
                               ((uint)GH_F2U(fVar24) & 0xff00) << 8 | (int)GH_F2U(fVar24) << 0x18)));
            local_7c = ((unsigned int)(((int)GH_F2U(fVar23) >> 0x18 | (uint)GH_F2U(fVar23) >> 8 & 0xff00 |
                               ((uint)GH_F2U(fVar23) & 0xff00) << 8 | (int)GH_F2U(fVar23) << 0x18)));
            local_78 = ((unsigned int)(((int)GH_F2U(fVar22) >> 0x18 | (uint)GH_F2U(fVar22) >> 8 & 0xff00 |
                               ((uint)GH_F2U(fVar22) & 0xff00) << 8 | (int)GH_F2U(fVar22) << 0x18)));
            local_74 = ((unsigned int)(((int)GH_F2U(fVar21) >> 0x18 | (uint)GH_F2U(fVar21) >> 8 & 0xff00 |
                               ((uint)GH_F2U(fVar21) & 0xff00) << 8 | (int)GH_F2U(fVar21) << 0x18)));
          }
          if (formatIsRgba) {
            *(unsigned int *)dstCursor = local_80;
            ((unsigned int *)dstCursor)[1] = local_7c;
            local_80 = local_78;
LAB_000d32f4:
            dstCursor = dstCursor + 2;
            *(unsigned int *)dstCursor = local_80;
            local_80 = local_74;
          }
          else {
            if (!formatAboveRgba) {
              fVar21 = GH_U2F(local_78);
              if (!formatIsBlue) {
                if (formatAboveBlue) {
                  fVar21 = GH_U2F(local_74);
                  if (formatIsAlpha) goto LAB_000d32bc;
                  if (formatIsRgb) {
                    *(unsigned int *)dstCursor = local_80;
                    ((unsigned int *)dstCursor)[1] = local_7c;
                    goto LAB_000d32d8;
                  }
                }
                else {
                  fVar21 = GH_U2F(local_80);
                  if ((formatIsRed) || (fVar21 = GH_U2F(local_7c), !formatIsNotGreen)) goto LAB_000d32bc;
                }
                goto LAB_000d3734;
              }
LAB_000d32bc:
              *dstCursor = fVar21;
              goto LAB_000d3730;
            }
            if (!formatIsAbgr) {
              if (formatAboveAbgr) {
                if (formatIsBgr) {
                  *(unsigned int *)dstCursor = local_78;
                  ((unsigned int *)dstCursor)[1] = local_7c;
                  local_78 = local_80;
LAB_000d32d8:
                  dstCursor = dstCursor + 2;
                  *(unsigned int *)dstCursor = local_78;
                  goto LAB_000d3730;
                }
                if (formatIsBgra) {
                  *(unsigned int *)dstCursor = local_78;
                  ((unsigned int *)dstCursor)[1] = local_7c;
                  goto LAB_000d32f4;
                }
              }
              else {
                fVar21 = GH_U2F(local_80);
                if (formatIsLuminance) goto LAB_000d32bc;
                if (formatIsLuminanceAlpha) {
                  *(unsigned int *)dstCursor = local_80;
                  local_80 = local_74;
                  goto LAB_000d32fc;
                }
              }
              goto LAB_000d3734;
            }
            *(unsigned int *)dstCursor = local_74;
            ((unsigned int *)dstCursor)[1] = local_78;
            dstCursor = dstCursor + 2;
            *(unsigned int *)dstCursor = local_7c;
          }
LAB_000d32fc:
          dstCursor = dstCursor + 1;
          *(unsigned int *)dstCursor = local_80;
          goto LAB_000d3730;
        }
      }
      (*(unsigned short *)((unsigned char *)&(local_80) + 2)) = SUB42(*binCursor,0);
      (*(unsigned short *)((unsigned char *)&(local_7c) + 2)) = SUB42(binCursor[1],0);
      (*(unsigned short *)((unsigned char *)&(local_78) + 2)) = SUB42(binCursor[2],0);
      (*(unsigned short *)((unsigned char *)&(local_74) + 2)) = SUB42(binCursor[3],0);
      if (swapBytes) {
        (*(unsigned short *)((unsigned char *)&(local_80) + 2)) =
             (ushort)(((uint)GH_F2U(*binCursor) & 0xff) << 8) | (ushort)((uint)GH_F2U(*binCursor) >> 8) & 0xff;
        (*(unsigned short *)((unsigned char *)&(local_7c) + 2)) =
             (ushort)(((uint)GH_F2U(binCursor[1]) & 0xff) << 8) | (ushort)((uint)GH_F2U(binCursor[1]) >> 8) & 0xff;
        (*(unsigned short *)((unsigned char *)&(local_78) + 2)) =
             (ushort)(((uint)GH_F2U(binCursor[2]) & 0xff) << 8) | (ushort)((uint)GH_F2U(binCursor[2]) >> 8) & 0xff;
        (*(unsigned short *)((unsigned char *)&(local_74) + 2)) =
             (ushort)(((uint)GH_F2U(binCursor[3]) & 0xff) << 8) | (ushort)((uint)GH_F2U(binCursor[3]) >> 8) & 0xff;
      }
      if (formatIsRgba) {
        *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(local_80) + 2));
        *(ushort *)((int)dstCursor + 2) = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
        (*(unsigned short *)((unsigned char *)&(local_80) + 2)) = (*(unsigned short *)((unsigned char *)&(local_78) + 2));
LAB_000d3270:
        dstCursor = dstCursor + 1;
        *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(local_80) + 2));
        (*(unsigned short *)((unsigned char *)&(local_80) + 2)) = (*(unsigned short *)((unsigned char *)&(local_74) + 2));
LAB_000d32ac:
        dstCursor = (float *)((int)dstCursor + 2);
        *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(local_80) + 2));
LAB_000d32b0:
        dstCursor = (float *)((int)dstCursor + 2);
      }
      else if (formatAboveRgba) {
        if (formatIsAbgr) {
          *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(local_74) + 2));
          *(ushort *)((int)dstCursor + 2) = (*(unsigned short *)((unsigned char *)&(local_78) + 2));
          dstCursor = dstCursor + 1;
          *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
          goto LAB_000d32ac;
        }
        if (formatAboveAbgr) {
          if (formatIsBgr) {
            *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(local_78) + 2));
            *(ushort *)((int)dstCursor + 2) = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
            (*(unsigned short *)((unsigned char *)&(local_78) + 2)) = (*(unsigned short *)((unsigned char *)&(local_80) + 2));
LAB_000d30dc:
            dstCursor = dstCursor + 1;
            *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(local_78) + 2));
            goto LAB_000d32b0;
          }
          if (formatIsBgra) {
            *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(local_78) + 2));
            *(ushort *)((int)dstCursor + 2) = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
            goto LAB_000d3270;
          }
        }
        else {
          uVar17 = (*(unsigned short *)((unsigned char *)&(local_80) + 2));
          if (formatIsLuminance) goto LAB_000d30c0;
          if (formatIsLuminanceAlpha) {
            *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(local_80) + 2));
            (*(unsigned short *)((unsigned char *)&(local_80) + 2)) = (*(unsigned short *)((unsigned char *)&(local_74) + 2));
            goto LAB_000d32ac;
          }
        }
      }
      else {
        uVar17 = (*(unsigned short *)((unsigned char *)&(local_78) + 2));
        if (formatIsBlue) {
LAB_000d30c0:
          *(ushort *)dstCursor = uVar17;
          goto LAB_000d32b0;
        }
        if (formatAboveBlue) {
          uVar17 = (*(unsigned short *)((unsigned char *)&(local_74) + 2));
          if (formatIsAlpha) goto LAB_000d30c0;
          if (formatIsRgb) {
            *(ushort *)dstCursor = (*(unsigned short *)((unsigned char *)&(local_80) + 2));
            *(ushort *)((int)dstCursor + 2) = (*(unsigned short *)((unsigned char *)&(local_7c) + 2));
            goto LAB_000d30dc;
          }
        }
        else {
          uVar17 = (*(unsigned short *)((unsigned char *)&(local_80) + 2));
          if ((formatIsRed) || (uVar17 = (*(unsigned short *)((unsigned char *)&(local_7c) + 2)), !formatIsNotGreen)) goto LAB_000d30c0;
        }
      }
LAB_000d3734:
      binCursor = binCursor + 4;
      binsRemaining = binsRemaining + -1;
    } while (binsRemaining != 0);
  }
  if ((reset != 0) && (iVar19 = 0, 0 < binCountThenRemaining)) {
    pfVar25 = histogramTable;
    do {
      if (format == 0x8032) goto LAB_000d3938;
      if (format < 0x8033) {
        if (format == 0x1906) {
LAB_000d3920:
          pfVar25[3] = 0.0;
        }
        else if (format < 0x1907) {
          if (format == 0x1904) {
            pfVar25[1] = 0.0;
          }
          else if (format < 0x1905) {
            if (format == 0x1903) {
LAB_000d3904:
              *pfVar25 = 0.0;
            }
          }
          else {
            pfVar25[2] = 0.0;
          }
        }
        else {
          if (format == 0x1908) goto LAB_000d3928;
          if (format < 0x1908) goto LAB_000d3938;
          if (format == 0x1909) goto LAB_000d3904;
          if (format == 0x190a) {
            *pfVar25 = 0.0;
            goto LAB_000d3920;
          }
        }
      }
      else {
        if (format == 0x80e1) {
LAB_000d3928:
          binByteOffset = iVar19 * 0x10;
          histogramTable[iVar19 * 4 + 3] = 0.0;
        }
        else {
          if (0x80e1 < format) {
            if (0x8361 < format) {
              if (format < 0x8365) goto LAB_000d3938;
              if (format < 0x8369) goto LAB_000d3928;
            }
            goto LAB_000d394c;
          }
          if (format < 0x8037) goto LAB_000d3928;
          if (format != 0x80e0) goto LAB_000d394c;
LAB_000d3938:
          binByteOffset = iVar19 << 4;
        }
        *(undefined4 *)((int)histogramTable + binByteOffset) = 0;
        *(undefined4 *)((int)histogramTable + binByteOffset + 8) = 0;
        *(undefined4 *)((int)histogramTable + binByteOffset + 4) = 0;
      }
LAB_000d394c:
      iVar19 = iVar19 + 1;
      pfVar25 = pfVar25 + 4;
      binCountThenRemaining = binCountThenRemaining + -1;
    } while (binCountThenRemaining != 0);
  }
  return;
}

/* _gleGetMinmax @ 0xd3974 (628 bytes) */
void _gleGetMinmax(glContext, unusedArg2, reset, format, type, values)
  int glContext;
  undefined4 unusedArg2;
  int reset;
  uint format;
  undefined4 type;
  int values;
{
  float fVar1;
  double dVar2;
  int pixelBytes;
  code *insertFunc;
  undefined4 *minmaxTable;
  undefined1 auStack_80 [4];
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  
  minmaxTable = *(undefined4 **)(glContext + 0x337c);
  pixelBytes = _glePixelBytes(format,type);
  insertFunc = (code *)_gleSelectPixelInsertFunc(format,type);
  local_7c = *minmaxTable;
  local_78 = minmaxTable[1];
  local_74 = minmaxTable[2];
  local_70 = minmaxTable[3];
  (*insertFunc)(auStack_80,values);
  local_7c = minmaxTable[4];
  local_78 = minmaxTable[5];
  local_74 = minmaxTable[6];
  local_70 = minmaxTable[7];
  (*insertFunc)(auStack_80,values + pixelBytes);
  if (reset == 0) {
    return;
  }
  if (format == 0x8032) goto LAB_000d3b98;
  if (format < 0x8033) {
    if (format == 0x1906) {
      minmaxTable[3] = 0x3f800000;
      minmaxTable[7] = 0;
      return;
    }
    if (format < 0x1907) {
      if (format == 0x1904) {
        minmaxTable[1] = 0x3f800000;
        minmaxTable[5] = 0;
        return;
      }
      if (0x1904 < format) {
        minmaxTable[2] = 0x3f800000;
        minmaxTable[6] = 0;
        return;
      }
      if (format != 0x1903) {
        return;
      }
LAB_000d3af4:
      *minmaxTable = 0x3f800000;
      minmaxTable[4] = (float)(4503601774854144.0 - DOUBLE_00108d58);
      return;
    }
    if (format != 0x1908) {
      if (format < 0x1908) goto LAB_000d3b98;
      if (format != 0x1909) {
        if (format != 0x190a) {
          return;
        }
        minmaxTable[3] = 0x3f800000;
        *minmaxTable = 0x3f800000;
        minmaxTable[7] = 0;
        minmaxTable[4] = 0;
        return;
      }
      goto LAB_000d3af4;
    }
  }
  else if (format != 0x80e1) {
    if (format < 0x80e2) {
      if (0x8036 < format) {
        if (format != 0x80e0) {
          return;
        }
        goto LAB_000d3b98;
      }
    }
    else {
      if (format < 0x8362) {
        return;
      }
      if (format < 0x8365) goto LAB_000d3b98;
      if (0x8368 < format) {
        return;
      }
    }
  }
  minmaxTable[3] = 0x3f800000;
  minmaxTable[7] = (float)(4503601774854144.0 - DOUBLE_00108d58);
LAB_000d3b98:
  *minmaxTable = 0x3f800000;
  dVar2 = DOUBLE_00108d58;
  minmaxTable[2] = 0x3f800000;
  minmaxTable[1] = 0x3f800000;
  fVar1 = (float)(4503601774854144.0 - dVar2);
  minmaxTable[6] = fVar1;
  minmaxTable[4] = fVar1;
  minmaxTable[5] = fVar1;
  return;
}

/* _gleConvolutionFilter1D @ 0xd3be8 (224 bytes) */
void _gleConvolutionFilter1D(glContext, unusedArg2, internalformat, width, format, type, image)
  int glContext;
  undefined4 unusedArg2;
  undefined4 internalformat;
  int width;
  undefined4 format;
  undefined4 type;
  undefined4 image;
{
  int bytesPerPixel;
  undefined4 filterData;
  
  if (*(int *)(glContext + 0x32cc) != 0) {
    _free(*(int *)(glContext + 0x32cc));
  }
  *(undefined4 *)(glContext + 0x32d4) = 1;
  *(int *)(glContext + 0x32d0) = width;
  if (width == 0) {
    *(undefined4 *)(glContext + 0x32cc) = 0;
    return;
  }
  bytesPerPixel = _glePixelBytes(internalformat,0x1406);
  filterData = _malloc(width * bytesPerPixel);
  *(undefined4 *)(glContext + 0x32cc) = filterData;
  *(short *)(glContext + 0x32ca) = (short)internalformat;
  ((void (*)())_gleImagingUnpackData)(glContext,width,1,format,type,internalformat,0x1406,image,filterData);
  ((void (*)())_gleImagingScaleAndBias)(glContext,glContext + 0x32a8,*(undefined4 *)(glContext + 0x32cc),
             (uint)*(ushort *)(glContext + 0x32ca),0,width,0);
  return;
}

/* _gleConvolutionFilter2D @ 0xd3cc8 (240 bytes) */
void _gleConvolutionFilter2D(glContext, unusedArg2, internalformat, width, height, format, type, image)
  int glContext;
  undefined4 unusedArg2;
  undefined4 internalformat;
  int width;
  int height;
  undefined4 format;
  undefined4 type;
  undefined4 image;
{
  int bytesPerPixel;
  undefined4 filterData;
  
  if (*(int *)(glContext + 0x330c) != 0) {
    _free(*(int *)(glContext + 0x330c));
  }
  *(int *)(glContext + 0x3310) = width;
  *(int *)(glContext + 0x3314) = height;
  if ((width != 0) && (height != 0)) {
    bytesPerPixel = _glePixelBytes(internalformat,0x1406);
    filterData = _malloc(width * height * bytesPerPixel);
    *(undefined4 *)(glContext + 0x330c) = filterData;
    *(short *)(glContext + 0x330a) = (short)internalformat;
    ((void (*)())_gleImagingUnpackData)(glContext,width,height,format,type,internalformat,0x1406,image,filterData);
    ((void (*)())_gleImagingScaleAndBias)(glContext,glContext + 0x32e8,*(undefined4 *)(glContext + 0x330c),
               (uint)*(ushort *)(glContext + 0x330a),0,width * height,0);
    return;
  }
  *(undefined4 *)(glContext + 0x330c) = 0;
  return;
}

/* _gleGetConvolutionFilter @ 0xd3db8 (100 bytes) */
void _gleGetConvolutionFilter(glContext, target, format, type, image)
  int glContext;
  int target;
  undefined4 format;
  undefined4 type;
  undefined4 image;
{
  int iVar1;
  
  iVar1 = glContext + 0x3298;
  if (target != 0x8010) {
    iVar1 = glContext + 0x32d8;
  }
  if (*(int *)(iVar1 + 0x34) != 0) {
    ((void (*)())_gleImagingPackData)(glContext,*(undefined4 *)(iVar1 + 0x38),*(undefined4 *)(iVar1 + 0x3c),
                        (uint)*(ushort *)(iVar1 + 0x32),0x1406,format,type,
                        *(int *)(iVar1 + 0x34),image);
  }
  return;
}

/* _gleSeparableFilter2D @ 0xd3e1c (340 bytes) */
void _gleSeparableFilter2D(glContext, unusedArg2, internalformat, width, height, format, type, row, column)
  int glContext;
  undefined4 unusedArg2;
  undefined4 internalformat;
  int width;
  int height;
  undefined4 format;
  undefined4 type;
  undefined4 row;
  undefined4 column;
{
  int iVar1;
  int filterData;
  
  iVar1 = _glePixelBytes(internalformat,0x1406);
  if (*(int *)(glContext + 0x334c) != 0) {
    _free(*(int *)(glContext + 0x334c));
  }
  *(int *)(glContext + 0x3350) = width;
  *(int *)(glContext + 0x3354) = height;
  if ((width != 0) && (height != 0)) {
    filterData = _malloc((width + height) * iVar1);
    *(int *)(glContext + 0x334c) = filterData;
    *(short *)(glContext + 0x334a) = (short)internalformat;
    *(int *)(glContext + 0x3350) = width;
    *(int *)(glContext + 0x3354) = height;
    iVar1 = filterData + width * iVar1;
    ((void (*)())_gleImagingUnpackData)(glContext,width,1,format,type,internalformat,0x1406,row,filterData);
    ((void (*)())_gleImagingUnpackData)(glContext,height,1,format,type,internalformat,0x1406,column,iVar1);
    ((void (*)())_gleImagingScaleAndBias)(glContext,glContext + 0x3328,*(undefined4 *)(glContext + 0x334c),
               (uint)*(ushort *)(glContext + 0x334a),0,width,0);
    ((void (*)())_gleImagingScaleAndBias)(glContext,glContext + 0x3328,iVar1,(uint)*(ushort *)(glContext + 0x334a),0,height,0);
    return;
  }
  *(undefined4 *)(glContext + 0x334c) = 0;
  return;
}

/* _gleGetSeparableFilter @ 0xd3f70 (164 bytes) */
void _gleGetSeparableFilter(glContext, unusedArg2, format, type, row, column)
  int glContext;
  undefined4 unusedArg2;
  undefined4 format;
  undefined4 type;
  undefined4 row;
  undefined4 column;
{
  int bytesPerPixel;
  int rowWidth;
  int filterData;
  
  bytesPerPixel = _glePixelBytes((uint)*(ushort *)(glContext + 0x334a),0x1406);
  rowWidth = *(int *)(glContext + 0x3350);
  filterData = *(int *)(glContext + 0x334c);
  ((void (*)())_gleImagingPackData)(glContext,rowWidth,1,(uint)*(ushort *)(glContext + 0x334a),0x1406,format,type,
                      filterData,row);
  ((void (*)())_gleImagingPackData)(glContext,*(undefined4 *)(glContext + 0x3354),1,
                      (uint)*(ushort *)(glContext + 0x334a),0x1406,format,type,
                      filterData + rowWidth * bytesPerPixel,column);
  return;
}

/* _gleColorTable @ 0xd4014 (128 bytes) */
void _gleColorTable(glContext, scaleBias, param_3, param_4, format, type, table)
  undefined4 glContext;
  undefined4 scaleBias;
  int param_3;
  undefined4 param_4;
  undefined4 format;
  undefined4 type;
  undefined4 table;
{
  ((void (*)())_gleImagingUnpackData)(glContext,param_4,1,format,type,(uint)*(ushort *)(param_3 + 0x10),
             (uint)*(ushort *)(param_3 + 0x12),table,*(undefined4 *)(param_3 + 0x14));
  ((void (*)())_gleImagingScaleAndBias)(glContext,scaleBias,*(undefined4 *)(param_3 + 0x14),(uint)*(ushort *)(param_3 + 0x10),0,
             param_4,1);
  return;
}

/* _gleColorSubTable @ 0xd4094 (160 bytes) */
void _gleColorSubTable(glContext, scaleBias, param_3, param_4, pixelCount, format, type, data)
  undefined4 glContext;
  undefined4 scaleBias;
  int param_3;
  int param_4;
  undefined4 pixelCount;
  undefined4 format;
  undefined4 type;
  undefined4 data;
{
  int iVar1;
  
  iVar1 = _glePixelBytes((uint)*(ushort *)(param_3 + 0x10),(uint)*(ushort *)(param_3 + 0x12));
  ((void (*)())_gleImagingUnpackData)(glContext,pixelCount,1,format,type,(uint)*(ushort *)(param_3 + 0x10),
             (uint)*(ushort *)(param_3 + 0x12),data,*(int *)(param_3 + 0x14) + iVar1 * param_4);
  ((void (*)())_gleImagingScaleAndBias)(glContext,scaleBias,*(undefined4 *)(param_3 + 0x14),(uint)*(ushort *)(param_3 + 0x10),
             param_4,pixelCount,1);
  return;
}

/* _gleTransformLightDirection @ 0xd4134 (296 bytes) */
void _gleTransformLightDirection(int glContext,int param_2,double fparam_1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  bool bVar8;
  
  iVar7 = glContext + param_2 * 0x80;
  fVar1 = *(float *)(iVar7 + 0x2860);
  fVar2 = *(float *)(iVar7 + 0x2864);
  fVar3 = *(float *)(iVar7 + 0x2868);
  if ((*(uint *)(glContext + 0x50b0) & 0x10) != 0) {
    fparam_1 = ((double (*)())_gleModelMatInvert)(glContext);
  }
  bVar8 = *(float *)(iVar7 + 0x285c) != FLOAT_00108e50;
  fVar6 = fVar3 * *(float *)(glContext + 0x22e0) +
          (fVar1 * *(float *)(glContext + 0x22c0) + fVar2 * *(float *)(glContext + 0x22d0));
  *(float *)(iVar7 + 0x2860) = fVar6;
  fVar5 = fVar3 * *(float *)(glContext + 0x22e4) +
          (fVar1 * *(float *)(glContext + 0x22c4) + fVar2 * *(float *)(glContext + 0x22d4));
  *(float *)(iVar7 + 0x2864) = fVar5;
  fVar4 = fVar3 * *(float *)(glContext + 0x22e8) +
          (fVar1 * *(float *)(glContext + 0x22c8) + fVar2 * *(float *)(glContext + 0x22d8));
  *(float *)(iVar7 + 0x2868) = fVar4;
  if (bVar8) {
    fVar1 = -(fVar3 * *(float *)(iVar7 + 0x2858) +
             (fVar1 * *(float *)(iVar7 + 0x2850) + fVar2 * *(float *)(iVar7 + 0x2854))) /
            *(float *)(iVar7 + 0x285c);
    *(float *)(iVar7 + 0x2860) = fVar1 * *(float *)(glContext + 0x22f0) + fVar6;
    *(float *)(iVar7 + 0x2864) = fVar1 * *(float *)(glContext + 0x22f4) + fVar5;
    *(float *)(iVar7 + 0x2868) = fVar1 * *(float *)(glContext + 0x22f8) + fVar4;
  }
  ((void (*)())_gleUpdateLightDirection)(glContext,param_2,fparam_1);
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
void _gleSetAddVertexMaterialFunc(glContext)
  int glContext;
{
  char cVar1;
  undefined *puVar2;
  
  puVar2 = PTR__gleAddVertexMaterialNoop_00110e40;
  if (*(int *)(glContext + 0x4e1c) == 0x1c00) {
    if ((*(char *)(glContext + 0x30aa) == '\0') || (*(char *)(glContext + 0x7580) != '\0'))
    goto LAB_000d43fc;
    cVar1 = *(char *)(glContext + 0x30ac);
    puVar2 = PTR__gleAddVertexMaterial_00110e3c;
  }
  else {
    if (*(int *)(glContext + 0x4e1c) != 0x1c01) goto LAB_000d43fc;
    cVar1 = *(char *)(glContext + 0x30aa);
  }
  if (cVar1 != '\0') {
    puVar2 = PTR__gleAddVertexMaterial2Sided_00110e38;
  }
LAB_000d43fc:
  *(undefined **)(glContext + 0x4de4) = puVar2;
                    
                    
  (**(int ( **)(int))(glContext + 0x4de4))(glContext);
  return;
}

/* _glePopMaterials @ 0xd440c (124 bytes) */
void _glePopMaterials(glContext)
  int glContext;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = glContext + 0x2c20;
  piVar4 = (int *)(glContext + 0x4dd0);
  iVar2 = 1;
  do {
    iVar5 = *piVar4;
    piVar4 = piVar4 + 1;
    iVar7 = *(int *)(iVar5 + 0x23c);
    if (iVar7 != 0) {
      if (*(int *)(iVar7 + 0x23c) != 0) {
        iVar1 = *(int *)(glContext + 0x4dd8);
        iVar3 = *(int *)(iVar6 + 0x238);
        *(int *)(iVar3 + 0x23c) = iVar1;
        if (iVar1 != 0) {
          *(int *)(iVar1 + 0x238) = iVar3;
        }
        *(int *)(glContext + 0x4dd8) = iVar7;
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
double _gleMaterialShinePow(undefined4 unusedArg1,int param_2,float floatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  uint uVar1;
  float fVar2;
  int iVar3;
  float dVar4;
  float dVar5;
  
  dVar4 = (double)FLOAT_00108e54;
  if ((double)dVar4 < floatArg1) {
    return (double)((floatArg1 - dVar4) * *(float *)(param_2 + 0x1c) + dVar4);
  }
  if (floatArg1 <= (double)*(float *)(param_2 + 0x10)) {
    return (double)(floatArg1 * *(float *)(param_2 + 0x18));
  }
  fVar2 = (floatArg1 - *(float *)(param_2 + 0x10)) * *(float *)(param_2 + 0x14);
  uVar1 = (uint)(int)fVar2;
  iVar3 = uVar1 * 4 + param_2;
  dVar5 = (double)(fVar2 - (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - DOUBLE_00108d58
                                  ));
  return (double)((dVar4 - dVar5) * *(float *)(iVar3 + 0x20) +
                 (dVar5 * *(float *)(iVar3 + 0x24)));
}

/* _gleLightExponentPow @ 0xd4538 (176 bytes) */
double _gleLightExponentPow(undefined4 unusedArg1,int param_2,float floatArg1,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  uint uVar1;
  float fVar2;
  int iVar3;
  float dVar4;
  float dVar5;
  
  dVar4 = (double)FLOAT_00108e54;
  if ((double)dVar4 < floatArg1) {
    return (double)((floatArg1 - dVar4) * *(float *)(param_2 + 0x34) + dVar4);
  }
  if (floatArg1 <= (double)*(float *)(param_2 + 0x28)) {
    return (double)(floatArg1 * *(float *)(param_2 + 0x30));
  }
  fVar2 = (floatArg1 - *(float *)(param_2 + 0x28)) * *(float *)(param_2 + 0x2c);
  uVar1 = (uint)(int)fVar2;
  iVar3 = uVar1 * 4 + param_2;
  dVar5 = (double)(fVar2 - (float)((double)CONCAT44(0x43300000,uVar1 ^ 0x80000000) - DOUBLE_00108d58
                                  ));
  return (double)((dVar4 - dVar5) * *(float *)(iVar3 + 0x38) +
                 (dVar5 * *(float *)(iVar3 + 0x3c)));
}

/* _gleVtxLightRGBAFront_body @ 0xd45ec (1180 bytes) */
void _gleVtxLightRGBAFront_body(int glContext,int vertex,int vertexCount,double fparam_1)
{
  float fVar1;
  float inverseW;
  undefined4 colorAlpha;
  undefined *vectorNormalize;
  int iVar4;
  int extraout_r3;
  int r3AfterCall1;
  uint enabledLightMask;
  int vertexIndex;
  float *eyePosition;
  uint lightIndex;
  int lightParams;
  int material;
  int lightParams2;
  int lightProducts;
  int lightRecord;
  double extraout_f1;
  double f1AfterCall1;
  double dVar14;
  double floatZero;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  float floatOne;
  float lightContributionG;
  float lightContributionR;
  float lightContributionB;
  float colorB;
  float colorG;
  float colorR;
  float lightAttenuation;
  double incomingStack_fffffee8;
  double incomingStack_fffffef0;
  double incomingStack_fffffef8;
  double incomingStack_ffffff00;
  double incomingStack_ffffff08;
  float eyeX;
  float eyeY;
  float eyeZ;
  float toLightX;
  float toLightY;
  float toLightZ;
  float halfX;
  float halfY;
  float halfZ;
  uint localViewer;
  float *local_ac;
  
  vertexIndex = 0;
  localViewer = (uint)*(byte *)(glContext + 0x30ad);
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  iVar4 = glContext;
  if (vertexCount < 1) {
    return;
  }
LAB_000d462c:
  if ((*(byte *)(vertex + 0x7e) & 2) != 0) {
    material = *(int *)(vertex + 0x74);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfd;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,0);
          }
    vectorNormalize = PTR__gleVectorNormalize_00112064;
    eyePosition = (float *)(vertex + 0x20);
    if (*(float *)(vertex + 0x2c) != FLOAT_00108e54) {
      inverseW = FLOAT_00108e54 / *(float *)(vertex + 0x2c);
      eyePosition = &eyeX;
      eyeZ = *(float *)(vertex + 0x28) * inverseW;
      eyeX = *(float *)(vertex + 0x20) * inverseW;
      eyeY = *(float *)(vertex + 0x24) * inverseW;
    }
    colorR = (double)*(float *)(material + 0x1d0);
    colorG = (double)*(float *)(material + 0x1d4);
    lightIndex = 0;
    colorB = (double)*(float *)(material + 0x1d8);
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    local_ac = &FLOAT_00108e80;
    floatOne = (double)FLOAT_00108e54;
    lightParams = glContext;
    lightParams2 = glContext;
    lightProducts = material;
    lightRecord = glContext;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d4a5c;
      }
      else if (*(char *)(lightRecord + 0x4ad8) == '\0') {
        if (*(char *)(lightRecord + 0x4ad9) == '\0') {
          toLightX = *(float *)(lightRecord + 0x4a70) - *eyePosition;
          toLightY = *(float *)(lightRecord + 0x4a74) - eyePosition[1];
          toLightZ = *(float *)(lightRecord + 0x4a78) - eyePosition[2];
          f1AfterCall1 = ((double (*)())(*(code **)vectorNormalize))(glContext,&toLightX,&toLightX);
          if ((*(char *)(lightRecord + 0x4adb) != '\0') || (f1AfterCall1 < (double)*local_ac)) {
            lightAttenuation = (double)*(float *)(lightRecord + 0x4ad4);
          }
          else {
            fVar1 = (float)((double)floatOne / f1AfterCall1);
            lightAttenuation = (double)(floatOne / (*(float *)(lightParams2 + 0x2878) * fVar1 * fVar1 +
                                                      (*(float *)(lightParams2 + 0x2874) * fVar1 +
                                                      *(float *)(lightParams2 + 0x2870))));
          }
        }
        else {
          lightAttenuation = (double)FLOAT_00108e54;
          toLightX = *(float *)(lightRecord + 0x4a7c);
          toLightY = *(float *)(lightRecord + 0x4a80);
          toLightZ = *(float *)(lightRecord + 0x4a84);
        }
        if (*(char *)(lightRecord + 0x4ada) != '\0') {
          fparam_1 = -(double)(toLightZ * *(float *)(lightRecord + 0x4a90) +
                              (toLightX * *(float *)(lightRecord + 0x4a88) +
                              toLightY * *(float *)(lightRecord + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(lightParams2 + 0x286c)) goto LAB_000d4a44;
          dVar14 = ((double (*)())_gleLightExponentPow)(iVar4,lightRecord + 0x4a70,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
                              incomingFpr8,incomingStack_fffffee8,incomingStack_fffffef0,incomingStack_fffffef8,
                              incomingStack_ffffff00,incomingStack_ffffff08);
          lightAttenuation = (double)(float)((double)lightAttenuation * dVar14);
        }
        if (localViewer == 0) {
          halfZ = (toLightZ + floatOne);
          halfX = toLightX;
          halfY = toLightY;
        }
        else {
          halfX = -*eyePosition;
          halfY = -eyePosition[1];
          halfZ = -eyePosition[2];
          (**(code **)vectorNormalize)(glContext,&halfX,&halfX);
          halfX = halfX + toLightX;
          halfY = halfY + toLightY;
          halfZ = halfZ + toLightZ;
        }
        f1AfterCall2 = ((double (*)())(*(code **)vectorNormalize))(glContext,&halfX,&halfX);
        floatZero = (double)FLOAT_00108e50;
        fparam_1 = f1AfterCall2;
        if ((double)lightAttenuation != floatZero) {
          incomingFpr8 = (double)*(float *)(vertex + 0x40);
          incomingFpr7 = (double)*(float *)(vertex + 0x48);
          lightContributionR = (double)*(float *)(lightProducts + 0x50);
          lightContributionG = (double)*(float *)(lightProducts + 0x54);
          lightContributionB = (double)*(float *)(lightProducts + 0x58);
          fparam_1 = (double)(float)(incomingFpr7 * (double)toLightZ +
                                    (double)(float)(incomingFpr8 * (double)toLightX +
                                                   (double)(*(float *)(vertex + 0x44) * toLightY)))
          ;
          if (floatZero < fparam_1) {
            lightContributionB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x68) + (double)lightContributionB);
            lightContributionR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x60) + (double)lightContributionR);
            lightContributionG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 100) + (double)lightContributionG);
            fparam_1 = (double)(float)(incomingFpr7 * (double)halfZ +
                                      (double)(float)(incomingFpr8 * (double)halfX +
                                                     (double)(*(float *)(vertex + 0x44) * halfY)
                                                     ));
            if (floatZero < fparam_1) {
              incomingFpr2 = (double)*(float *)(material + 0x40);
              dVar14 = _pow(fparam_1,incomingFpr2);
              fparam_1 = (double)(float)dVar14;
              lightContributionB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)lightContributionB);
              lightContributionR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)lightContributionR);
              lightContributionG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)lightContributionG);
              iVar4 = r3AfterCall1;
            }
          }
          if ((double)lightAttenuation == (double)floatOne) {
            colorR = (double)(colorR + lightContributionR);
            colorG = (double)(colorG + lightContributionG);
            colorB = (double)(colorB + lightContributionB);
          }
          else {
            colorB = (double)(lightAttenuation * lightContributionB + colorB);
            colorR = (double)(lightAttenuation * lightContributionR + colorR);
            colorG = (double)(lightAttenuation * lightContributionG + colorG);
          }
        }
      }
      else {
        incomingFpr8 = (double)*(float *)(vertex + 0x48);
        incomingFpr7 = (double)FLOAT_00108e50;
        fparam_1 = (double)(float)(incomingFpr8 * (double)*(float *)(lightRecord + 0x4a84) +
                                  (double)(*(float *)(vertex + 0x40) * *(float *)(lightRecord + 0x4a7c)
                                          + *(float *)(vertex + 0x44) * *(float *)(lightRecord + 0x4a80)
                                          ));
        colorR = (double)(colorR + *(float *)(lightProducts + 0x50));
        colorG = (double)(colorG + *(float *)(lightProducts + 0x54));
        colorB = (double)(colorB + *(float *)(lightProducts + 0x58));
        if (incomingFpr7 < fparam_1) {
          colorR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x60) + (double)colorR);
          colorG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 100) + (double)colorG);
          colorB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x68) + (double)colorB);
          fparam_1 = (double)(float)(incomingFpr8 * (double)*(float *)(lightParams + 0x2888) +
                                    (double)(*(float *)(vertex + 0x40) * *(float *)(lightParams + 0x2880)
                                            + *(float *)(vertex + 0x44) *
                                              *(float *)(lightParams + 0x2884)));
          if (incomingFpr7 < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar4,material + 0x1e8,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
                                  incomingFpr8,incomingStack_fffffee8,incomingStack_fffffef0,incomingStack_fffffef8,
                                  incomingStack_ffffff00,incomingStack_ffffff08);
            colorB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)colorB);
            colorR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)colorR);
            colorG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)colorG);
            iVar4 = iVar4;
          }
        }
      }
LAB_000d4a44:
      lightIndex = lightIndex + 1;
      lightRecord = lightRecord + 0x6c;
      lightProducts = lightProducts + 0x30;
      lightParams = lightParams + 0x80;
      lightParams2 = lightParams2 + 0x80;
    } while( true );
  }
  goto LAB_000d4a6c;
LAB_000d4a5c:
  *(float *)(vertex + 0x30) = (float)(double)colorR;
  *(float *)(vertex + 0x34) = (float)(double)colorG;
  *(float *)(vertex + 0x38) = (float)(double)colorB;
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
LAB_000d4a6c:
  vertexIndex = vertexIndex + 1;
  vertex = vertex + 0x100;
  if (vertexCount <= vertexIndex) {
    return;
  }
  goto LAB_000d462c;
}

/* _gleVtxLightRGBABack_body @ 0xd4a8c (1188 bytes) */
void _gleVtxLightRGBABack_body(int glContext,int vertex,int vertexCount,double fparam_1,double fparam_2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double fparam_7,double fparam_8,double unusedFloatArg9)
{
  float fVar1;
  float inverseW;
  undefined4 colorAlpha;
  undefined *vectorNormalize;
  int iVar4;
  int extraout_r3;
  int r3AfterCall1;
  uint enabledLightMask;
  int vertexIndex;
  float *eyePosition;
  uint lightIndex;
  int lightParams;
  int material;
  int lightParams2;
  int lightProducts;
  int lightRecord;
  double extraout_f1;
  double f1AfterCall1;
  double dVar14;
  double f1AfterCall2;
  float dVar15;
  float lightAttenuation;
  float floatOne;
  float lightContributionG;
  float lightContributionR;
  float lightContributionB;
  float colorB;
  float colorG;
  float colorR;
  double incomingStack_fffffee8;
  double incomingStack_fffffef0;
  double incomingStack_fffffef8;
  double incomingStack_ffffff00;
  double incomingStack_ffffff08;
  float eyeX;
  float eyeY;
  float eyeZ;
  float toLightX;
  float toLightY;
  float toLightZ;
  float halfX;
  float halfY;
  float halfZ;
  uint localViewer;
  float *local_ac;
  
  vertexIndex = 0;
  localViewer = (uint)*(byte *)(glContext + 0x30ad);
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  iVar4 = glContext;
  if (vertexCount < 1) {
    return;
  }
LAB_000d4acc:
  if ((*(byte *)(vertex + 0x7e) & 4) != 0) {
    material = *(int *)(vertex + 0x78);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfb;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,1);
          }
    vectorNormalize = PTR__gleVectorNormalize_00112064;
    eyePosition = (float *)(vertex + 0x20);
    if (*(float *)(vertex + 0x2c) != FLOAT_00108e54) {
      inverseW = FLOAT_00108e54 / *(float *)(vertex + 0x2c);
      eyePosition = &eyeX;
      eyeZ = *(float *)(vertex + 0x28) * inverseW;
      eyeX = *(float *)(vertex + 0x20) * inverseW;
      eyeY = *(float *)(vertex + 0x24) * inverseW;
    }
    colorR = (double)*(float *)(material + 0x1d0);
    colorG = (double)*(float *)(material + 0x1d4);
    lightIndex = 0;
    colorB = (double)*(float *)(material + 0x1d8);
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    local_ac = &FLOAT_00108e80;
    floatOne = (double)FLOAT_00108e54;
    lightParams = glContext;
    lightParams2 = glContext;
    lightProducts = material;
    lightRecord = glContext;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d4f04;
      }
      else if (*(char *)(lightRecord + 0x4ad8) == '\0') {
        if (*(char *)(lightRecord + 0x4ad9) == '\0') {
          toLightX = *(float *)(lightRecord + 0x4a70) - *eyePosition;
          toLightY = *(float *)(lightRecord + 0x4a74) - eyePosition[1];
          toLightZ = *(float *)(lightRecord + 0x4a78) - eyePosition[2];
          f1AfterCall1 = ((double (*)())(*(code **)vectorNormalize))(glContext,&toLightX,&toLightX);
          if ((*(char *)(lightRecord + 0x4adb) != '\0') || (f1AfterCall1 < (double)*local_ac)) {
            lightAttenuation = (double)*(float *)(lightRecord + 0x4ad4);
          }
          else {
            fVar1 = (float)((double)floatOne / f1AfterCall1);
            lightAttenuation = (double)(floatOne / (*(float *)(lightParams2 + 0x2878) * fVar1 * fVar1 +
                                                      (*(float *)(lightParams2 + 0x2874) * fVar1 +
                                                      *(float *)(lightParams2 + 0x2870))));
          }
        }
        else {
          lightAttenuation = (double)FLOAT_00108e54;
          toLightX = *(float *)(lightRecord + 0x4a7c);
          toLightY = *(float *)(lightRecord + 0x4a80);
          toLightZ = *(float *)(lightRecord + 0x4a84);
        }
        if (*(char *)(lightRecord + 0x4ada) != '\0') {
          fparam_1 = -(double)(toLightZ * *(float *)(lightRecord + 0x4a90) +
                              (toLightX * *(float *)(lightRecord + 0x4a88) +
                              toLightY * *(float *)(lightRecord + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(lightParams2 + 0x286c)) goto LAB_000d4eec;
          dVar14 = ((double (*)())_gleLightExponentPow)(iVar4,lightRecord + 0x4a70,fparam_1,fparam_2,floatArg3,floatArg4,floatArg5,
                              floatArg6,fparam_7,fparam_8,incomingStack_fffffee8,incomingStack_fffffef0,
                              incomingStack_fffffef8,incomingStack_ffffff00,incomingStack_ffffff08);
          lightAttenuation = (double)(float)((double)lightAttenuation * dVar14);
        }
        if (localViewer == 0) {
          halfZ = (toLightZ + floatOne);
          halfX = toLightX;
          halfY = toLightY;
        }
        else {
          halfX = -*eyePosition;
          halfY = -eyePosition[1];
          halfZ = -eyePosition[2];
          (**(code **)vectorNormalize)(glContext,&halfX,&halfX);
          halfX = halfX + toLightX;
          halfY = halfY + toLightY;
          halfZ = halfZ + toLightZ;
        }
        f1AfterCall2 = ((double (*)())(*(code **)vectorNormalize))(glContext,&halfX,&halfX);
        fparam_8 = (double)FLOAT_00108e50;
        fparam_1 = f1AfterCall2;
        if ((double)lightAttenuation != fparam_8) {
          fparam_7 = (double)*(float *)(vertex + 0x48);
          lightContributionR = (double)*(float *)(lightProducts + 0x50);
          lightContributionG = (double)*(float *)(lightProducts + 0x54);
          lightContributionB = (double)*(float *)(lightProducts + 0x58);
          dVar14 = (double)(float)(fparam_7 * (double)toLightZ +
                                  (double)(*(float *)(vertex + 0x40) * toLightX +
                                          *(float *)(vertex + 0x44) * toLightY));
          fparam_1 = -dVar14;
          if (fparam_8 < fparam_1) {
            lightContributionR = -(double)(float)(dVar14 * (double)*(float *)(lightProducts + 0x60) - (double)lightContributionR);
            lightContributionB = -(double)(float)(dVar14 * (double)*(float *)(lightProducts + 0x68) - (double)lightContributionB);
            fparam_1 = -(double)(float)(fparam_7 * (double)halfZ +
                                       (double)(*(float *)(vertex + 0x40) * halfX +
                                               *(float *)(vertex + 0x44) * halfY));
            lightContributionG = -(double)(float)(dVar14 * (double)*(float *)(lightProducts + 100) - (double)lightContributionG);
            if (fparam_8 < fparam_1) {
              fparam_2 = (double)*(float *)(material + 0x40);
              dVar14 = _pow(fparam_1,fparam_2);
              fparam_1 = (double)(float)dVar14;
              lightContributionB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)lightContributionB);
              lightContributionR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)lightContributionR);
              lightContributionG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)lightContributionG);
              iVar4 = r3AfterCall1;
            }
          }
          if ((double)lightAttenuation == (double)floatOne) {
            colorR = (double)(colorR + lightContributionR);
            colorG = (double)(colorG + lightContributionG);
            colorB = (double)(colorB + lightContributionB);
          }
          else {
            colorB = (double)(lightAttenuation * lightContributionB + colorB);
            colorR = (double)(lightAttenuation * lightContributionR + colorR);
            colorG = (double)(lightAttenuation * lightContributionG + colorG);
          }
        }
      }
      else {
        fparam_8 = (double)*(float *)(vertex + 0x48);
        fparam_7 = (double)FLOAT_00108e50;
        dVar15 = (double)(float)(fparam_8 * (double)*(float *)(lightRecord + 0x4a84) +
                                (double)(*(float *)(vertex + 0x40) * *(float *)(lightRecord + 0x4a7c) +
                                        *(float *)(vertex + 0x44) * *(float *)(lightRecord + 0x4a80)));
        colorR = (double)(colorR + *(float *)(lightProducts + 0x50));
        colorG = (double)(colorG + *(float *)(lightProducts + 0x54));
        fparam_1 = -(double)dVar15;
        colorB = (double)(colorB + *(float *)(lightProducts + 0x58));
        if (fparam_7 < fparam_1) {
          colorR = -(double)(dVar15 * *(float *)(lightProducts + 0x60) - colorR);
          colorG = -(double)(dVar15 * *(float *)(lightProducts + 100) - colorG);
          fparam_1 = -(double)(float)(fparam_8 * (double)*(float *)(lightParams + 0x2888) +
                                     (double)(*(float *)(vertex + 0x40) *
                                              *(float *)(lightParams + 0x2880) +
                                             *(float *)(vertex + 0x44) * *(float *)(lightParams + 0x2884)
                                             ));
          colorB = -(double)(dVar15 * *(float *)(lightProducts + 0x68) - colorB);
          if (fparam_7 < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar4,material + 0x1e8,fparam_1,fparam_2,floatArg3,floatArg4,floatArg5,
                                  floatArg6,fparam_7,fparam_8,incomingStack_fffffee8,incomingStack_fffffef0,
                                  incomingStack_fffffef8,incomingStack_ffffff00,incomingStack_ffffff08);
            colorB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)colorB);
            colorR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)colorR);
            colorG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)colorG);
            iVar4 = iVar4;
          }
        }
      }
LAB_000d4eec:
      lightIndex = lightIndex + 1;
      lightRecord = lightRecord + 0x6c;
      lightProducts = lightProducts + 0x30;
      lightParams = lightParams + 0x80;
      lightParams2 = lightParams2 + 0x80;
    } while( true );
  }
  goto LAB_000d4f14;
LAB_000d4f04:
  *(float *)(vertex + 0x30) = (float)(double)colorR;
  *(float *)(vertex + 0x34) = (float)(double)colorG;
  *(float *)(vertex + 0x38) = (float)(double)colorB;
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
LAB_000d4f14:
  vertexIndex = vertexIndex + 1;
  vertex = vertex + 0x100;
  if (vertexCount <= vertexIndex) {
    return;
  }
  goto LAB_000d4acc;
}

/* _gleVtxLightSpecRGBAFront @ 0xd4f30 (1632 bytes) */
void _gleVtxLightSpecRGBAFront(int glContext,int vertex,int vertexCount,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
{
  float fVar1;
  float inverseW;
  float fVar2;
  float fVar3;
  undefined4 colorAlpha;
  undefined *vectorNormalize;
  int iVar6;
  int extraout_r3;
  int extraout_r3_00;
  int r3AfterCall2;
  uint enabledLightMask;
  int vertexIndex;
  float *eyePosition;
  uint lightIndex;
  int lightParams;
  int lightParams2;
  int material;
  int lightProducts;
  int lightRecord;
  double extraout_f1;
  double f1AfterCall1;
  double f1AfterCall2;
  double f1AfterCall3;
  double dVar16;
  float dVar17;
  float lightContributionB;
  double dVar18;
  double lightAttenuation;
  float floatOne;
  float dVar20;
  float dVar21;
  float floatZero;
  float dVar23;
  float lightContributionG;
  float lightContributionR;
  float dVar26;
  float colorB;
  float colorG;
  float colorR;
  int iStack00000020;
  double incomingStack_fffffea8;
  double incomingStack_fffffeb0;
  double incomingStack_fffffeb8;
  double incomingStack_fffffec0;
  double incomingStack_fffffec8;
  float eyeX;
  float eyeY;
  float eyeZ;
  float halfX;
  float halfY;
  float halfZ;
  float local_100;
  float local_fc;
  float toLightY;
  float local_f8;
  float toLightZ;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e0;
  float local_dc;
  float local_d8;
  uint localViewer;
  
  vertexIndex = 0;
  localViewer = (uint)*(byte *)(glContext + 0x30ad);
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  iVar6 = glContext;
  iStack00000020 = vertexCount;
  if (vertexCount < 1) {
    return;
  }
LAB_000d4f74:
  if ((*(byte *)(vertex + 0x7e) & 2) != 0) {
    material = *(int *)(vertex + 0x74);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfd;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,0);
          }
    eyePosition = (float *)(vertex + 0x20);
    if (*(float *)(vertex + 0x2c) != FLOAT_00108e54) {
      inverseW = FLOAT_00108e54 / *(float *)(vertex + 0x2c);
      eyePosition = &eyeX;
      eyeZ = *(float *)(vertex + 0x28) * inverseW;
      eyeX = *(float *)(vertex + 0x20) * inverseW;
      eyeY = *(float *)(vertex + 0x24) * inverseW;
    }
    if (*(char *)(glContext + 0x30ae) != '\0') {
      if ((localViewer == 0) || (*(int *)(glContext + 0x4ddc) == 0)) {
        halfY = 0.0;
        halfZ = 1.0;
        halfX = 0.0;
      }
      else {
        halfX = -*eyePosition;
        halfY = -eyePosition[1];
        halfZ = -eyePosition[2];
        f1AfterCall1 = ((double (*)())(*(code **)PTR__gleVectorNormalize_00112064))(glContext,&halfX,&halfX);
        fparam_1 = f1AfterCall1;
      }
    }
    vectorNormalize = PTR__gleVectorNormalize_00112064;
    floatZero = (double)FLOAT_00108e50;
    colorR = (double)*(float *)(material + 0x1d0);
    lightIndex = 0;
    colorG = (double)*(float *)(material + 0x1d4);
    colorB = (double)*(float *)(material + 0x1d8);
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    floatOne = (double)FLOAT_00108e54;
    lightParams = glContext;
    lightParams2 = glContext;
    lightProducts = material;
    lightRecord = glContext;
    dVar20 = (double)floatZero;
    dVar21 = (double)floatZero;
    dVar23 = (double)floatZero;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d5530;
      }
      else if (*(char *)(lightRecord + 0x4ad8) == '\0') {
        if (*(char *)(lightRecord + 0x4ad9) == '\0') {
          local_100 = *(float *)(lightRecord + 0x4a70) - *eyePosition;
          toLightY = *(float *)(lightRecord + 0x4a74) - eyePosition[1];
          toLightZ = *(float *)(lightRecord + 0x4a78) - eyePosition[2];
          f1AfterCall2 = ((double (*)())(*(code **)vectorNormalize))(glContext,&local_100,&local_100);
          if ((*(char *)(lightRecord + 0x4adb) != '\0') || (f1AfterCall2 < (double)FLOAT_00108e80)) {
            lightAttenuation = (double)*(float *)(lightRecord + 0x4ad4);
            fparam_1 = f1AfterCall2;
          }
          else {
            fparam_1 = (double)(float)((double)floatOne / f1AfterCall2);
            lightAttenuation = (double)(floatOne / (float)((double)(float)((double)*(float *)(
                                                  lightParams2 + 0x2878) * fparam_1) * fparam_1 +
                                                  (double)(float)((double)*(float *)(lightParams2 + 0x2874
                                                                                    ) * fparam_1 +
                                                                 (double)*(float *)(lightParams2 + 0x2870)
                                                                 )));
          }
        }
        else {
          lightAttenuation = (double)FLOAT_00108e54;
          local_100 = *(float *)(lightRecord + 0x4a7c);
          toLightY = *(float *)(lightRecord + 0x4a80);
          toLightZ = *(float *)(lightRecord + 0x4a84);
        }
        if (*(char *)(lightRecord + 0x4ada) != '\0') {
          fparam_1 = -(double)(toLightZ * *(float *)(lightRecord + 0x4a90) +
                              (local_100 * *(float *)(lightRecord + 0x4a88) +
                              toLightY * *(float *)(lightRecord + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(lightParams2 + 0x286c)) goto LAB_000d5518;
          fparam_1 = ((double (*)())_gleLightExponentPow)(iVar6,lightRecord + 0x4a70,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                                fparam_6,fparam_7,fparam_8,incomingStack_fffffea8,incomingStack_fffffeb0,
                                incomingStack_fffffeb8,incomingStack_fffffec0,incomingStack_fffffec8);
          lightAttenuation = (double)(float)(lightAttenuation * fparam_1);
          iVar6 = iVar6;
        }
        if (*(char *)(glContext + 0x30ae) == '\0') {
          if (localViewer == 0) {
            halfZ = (toLightZ + floatOne);
            halfX = local_100;
            halfY = toLightY;
          }
          else {
            halfX = -*eyePosition;
            halfY = -eyePosition[1];
            halfZ = -eyePosition[2];
            (**(code **)vectorNormalize)(glContext,&halfX,&halfX);
            halfX = halfX + local_100;
            halfY = halfY + toLightY;
            halfZ = halfZ + toLightZ;
          }
          f1AfterCall3 = ((double (*)())(*(code **)vectorNormalize))(glContext,&halfX,&halfX);
          fparam_1 = f1AfterCall3;
        }
        if (lightAttenuation != (double)FLOAT_00108e50) {
          fparam_4 = (double)*(float *)(vertex + 0x44);
          dVar26 = (double)toLightY;
          fparam_5 = (double)*(float *)(vertex + 0x40);
          fparam_3 = (double)local_100;
          fparam_6 = (double)*(float *)(vertex + 0x48);
          fparam_2 = (double)toLightZ;
          lightContributionR = (double)*(float *)(lightProducts + 0x50);
          lightContributionG = (double)*(float *)(lightProducts + 0x54);
          lightContributionB = (double)*(float *)(lightProducts + 0x58);
          dVar16 = (double)(float)(fparam_6 * fparam_2 +
                                  (double)(float)(fparam_5 * fparam_3 +
                                                 (double)(float)(fparam_4 * (double)dVar26)));
          if ((double)FLOAT_00108e50 < dVar16) {
            lightContributionR = (double)(float)(dVar16 * (double)*(float *)(lightProducts + 0x60) + (double)lightContributionR);
            lightContributionG = (double)(float)(dVar16 * (double)*(float *)(lightProducts + 100) + (double)lightContributionG);
            lightContributionB = (double)(float)(dVar16 * (double)*(float *)(lightProducts + 0x68) + (double)lightContributionB);
            if (*(char *)(glContext + 0x30ae) == '\0') {
              fVar1 = (float)(fparam_6 * (double)halfZ +
                             (double)(float)(fparam_5 * (double)halfX +
                                            (double)(float)(fparam_4 * (double)halfY)));
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
              fVar1 = local_d8 * halfZ + (local_e0 * halfX + local_dc * halfY);
            }
            if (!((double)floatZero < (double)fVar1)) goto LAB_000d54cc;
            fparam_2 = (double)*(float *)(material + 0x40);
            dVar16 = _pow((double)fVar1,fparam_2);
            fVar1 = (float)dVar16;
            dVar26 = (double)(fVar1 * *(float *)(lightProducts + 0x78));
            iVar6 = r3AfterCall2;
            fparam_1 = (double)(fVar1 * *(float *)(lightProducts + 0x74));
            dVar16 = (double)(fVar1 * *(float *)(lightProducts + 0x70));
          }
          else {
LAB_000d54cc:
            dVar26 = (double)FLOAT_00108e50;
            fparam_1 = (double)dVar26;
            dVar16 = (double)dVar26;
          }
          if (lightAttenuation == (double)floatOne) {
            colorR = (double)(colorR + lightContributionR);
            colorG = (double)(colorG + lightContributionG);
            colorB = (double)(colorB + lightContributionB);
            dVar23 = (double)(float)((double)dVar23 + dVar16);
            dVar21 = (double)(float)((double)dVar21 + fparam_1);
            dVar20 = (double)(dVar20 + dVar26);
          }
          else {
            dVar20 = (double)(float)(lightAttenuation * (double)dVar26 + (double)dVar20);
            colorR = (double)(float)(lightAttenuation * (double)lightContributionR + (double)colorR);
            colorG = (double)(float)(lightAttenuation * (double)lightContributionG + (double)colorG);
            colorB = (double)(float)(lightAttenuation * (double)lightContributionB + (double)colorB);
            dVar23 = (double)(float)(lightAttenuation * dVar16 + (double)dVar23);
            dVar21 = (double)(float)(lightAttenuation * fparam_1 + (double)dVar21);
          }
        }
      }
      else {
        dVar16 = (double)*(float *)(vertex + 0x44);
        fparam_7 = (double)*(float *)(lightRecord + 0x4a80);
        fparam_8 = (double)*(float *)(vertex + 0x40);
        dVar17 = (double)*(float *)(vertex + 0x48);
        dVar18 = (double)*(float *)(lightRecord + 0x4a84);
        colorR = (double)(colorR + *(float *)(lightProducts + 0x50));
        fparam_1 = (double)(float)((double)dVar17 * dVar18 +
                                  (double)(float)(fparam_8 * (double)*(float *)(lightRecord + 0x4a7c) +
                                                 (double)(float)(dVar16 * fparam_7)));
        colorG = (double)(colorG + *(float *)(lightProducts + 0x54));
        colorB = (double)(colorB + *(float *)(lightProducts + 0x58));
        if ((double)floatZero < fparam_1) {
          colorR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x60) + (double)colorR);
          colorG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 100) + (double)colorG);
          colorB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x68) + (double)colorB);
          if (*(char *)(glContext + 0x30ae) == '\0') {
            dVar18 = (double)dVar17 * (double)*(float *)(lightParams + 0x2888) +
                     (double)(float)(fparam_8 * (double)*(float *)(lightParams + 0x2880) +
                                    (double)(float)(dVar16 * (double)*(float *)(lightParams + 0x2884)));
          }
          else {
            local_f8 = *(float *)(lightRecord + 0x4a84);
            local_100 = (float)(dVar16 * dVar18 - (double)(float)((double)dVar17 * fparam_7));
            local_fc = (dVar17 * *(float *)(lightRecord + 0x4a7c) - (float)(fparam_8 * dVar18));
            fVar1 = (float)(fparam_8 * (double)local_fc -
                           (double)(float)(dVar16 * (double)local_100));
            dVar18 = (double)(fVar1 + fVar1) + dVar18;
          }
          fparam_1 = (double)(float)dVar18;
          if ((double)floatZero < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar6,material + 0x1e8,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                                  fparam_6,fparam_7,fparam_8,incomingStack_fffffea8,incomingStack_fffffeb0,
                                  incomingStack_fffffeb8,incomingStack_fffffec0,incomingStack_fffffec8);
            dVar20 = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)dVar20);
            dVar23 = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)dVar23);
            dVar21 = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)dVar21);
            iVar6 = iVar6;
          }
        }
      }
LAB_000d5518:
      lightIndex = lightIndex + 1;
      lightRecord = lightRecord + 0x6c;
      lightProducts = lightProducts + 0x30;
      lightParams = lightParams + 0x80;
      lightParams2 = lightParams2 + 0x80;
    } while( true );
  }
  goto LAB_000d5570;
LAB_000d5530:
  if (*(short *)(glContext + 0x30a8) == -0x7e06) {
    *(float *)(vertex + 0x50) = (float)(double)dVar23;
    *(float *)(vertex + 0x54) = (float)(double)dVar21;
    *(float *)(vertex + 0x58) = (float)(double)dVar20;
  }
  else {
    colorR = (double)(colorR + dVar23);
    colorG = (double)(colorG + dVar21);
    colorB = (double)(colorB + dVar20);
  }
  *(float *)(vertex + 0x30) = (float)(double)colorR;
  *(float *)(vertex + 0x34) = (float)(double)colorG;
  *(float *)(vertex + 0x38) = (float)(double)colorB;
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
LAB_000d5570:
  vertexIndex = vertexIndex + 1;
  vertex = vertex + 0x100;
  if (iStack00000020 <= vertexIndex) {
    return;
  }
  goto LAB_000d4f74;
}

/* _gleVtxLightSpecRGBABack @ 0xd5590 (1640 bytes) */
void _gleVtxLightSpecRGBABack(int glContext,int vertex,int vertexCount,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11)
{
  float fVar1;
  float inverseW;
  float fVar2;
  float fVar3;
  undefined4 colorAlpha;
  undefined *vectorNormalize;
  int iVar6;
  int extraout_r3;
  int extraout_r3_00;
  int r3AfterCall2;
  uint enabledLightMask;
  int vertexIndex;
  float *eyePosition;
  uint lightIndex;
  int lightParams;
  int lightParams2;
  int material;
  int lightProducts;
  int lightRecord;
  double extraout_f1;
  double f1AfterCall1;
  double f1AfterCall2;
  double f1AfterCall3;
  float dVar16;
  float lightAttenuation;
  double dVar17;
  float dVar18;
  float lightContributionB;
  float floatOne;
  float dVar20;
  float dVar21;
  float floatZero;
  float dVar23;
  float lightContributionG;
  float lightContributionR;
  float dVar26;
  float colorB;
  float colorG;
  float colorR;
  int iStack00000020;
  double incomingStack_fffffea8;
  double incomingStack_fffffeb0;
  double incomingStack_fffffeb8;
  double incomingStack_fffffec0;
  double incomingStack_fffffec8;
  float eyeX;
  float eyeY;
  float eyeZ;
  float halfX;
  float halfY;
  float halfZ;
  float local_100;
  float local_fc;
  float toLightY;
  float local_f8;
  float toLightZ;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e0;
  float local_dc;
  float local_d8;
  uint localViewer;
  
  vertexIndex = 0;
  localViewer = (uint)*(byte *)(glContext + 0x30ad);
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  iVar6 = glContext;
  iStack00000020 = vertexCount;
  if (vertexCount < 1) {
    return;
  }
LAB_000d55d4:
  if ((*(byte *)(vertex + 0x7e) & 4) != 0) {
    material = *(int *)(vertex + 0x78);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfb;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,1);
          }
    eyePosition = (float *)(vertex + 0x20);
    if (*(float *)(vertex + 0x2c) != FLOAT_00108e54) {
      inverseW = FLOAT_00108e54 / *(float *)(vertex + 0x2c);
      eyePosition = &eyeX;
      eyeZ = *(float *)(vertex + 0x28) * inverseW;
      eyeX = *(float *)(vertex + 0x20) * inverseW;
      eyeY = *(float *)(vertex + 0x24) * inverseW;
    }
    if (*(char *)(glContext + 0x30ae) != '\0') {
      if ((localViewer == 0) || (*(int *)(glContext + 0x4ddc) == 0)) {
        halfY = 0.0;
        halfZ = 1.0;
        halfX = 0.0;
      }
      else {
        halfX = -*eyePosition;
        halfY = -eyePosition[1];
        halfZ = -eyePosition[2];
        f1AfterCall1 = ((double (*)())(*(code **)PTR__gleVectorNormalize_00112064))(glContext,&halfX,&halfX);
        fparam_1 = f1AfterCall1;
      }
    }
    vectorNormalize = PTR__gleVectorNormalize_00112064;
    floatZero = (double)FLOAT_00108e50;
    colorR = (double)*(float *)(material + 0x1d0);
    lightIndex = 0;
    colorG = (double)*(float *)(material + 0x1d4);
    colorB = (double)*(float *)(material + 0x1d8);
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    floatOne = (double)FLOAT_00108e54;
    lightParams = glContext;
    lightParams2 = glContext;
    lightProducts = material;
    lightRecord = glContext;
    dVar20 = (double)floatZero;
    dVar21 = (double)floatZero;
    dVar23 = (double)floatZero;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d5b98;
      }
      else if (*(char *)(lightRecord + 0x4ad8) == '\0') {
        if (*(char *)(lightRecord + 0x4ad9) == '\0') {
          local_100 = *(float *)(lightRecord + 0x4a70) - *eyePosition;
          toLightY = *(float *)(lightRecord + 0x4a74) - eyePosition[1];
          toLightZ = *(float *)(lightRecord + 0x4a78) - eyePosition[2];
          f1AfterCall2 = ((double (*)())(*(code **)vectorNormalize))(glContext,&local_100,&local_100);
          if ((*(char *)(lightRecord + 0x4adb) != '\0') || (f1AfterCall2 < (double)FLOAT_00108e80)) {
            lightAttenuation = (double)*(float *)(lightRecord + 0x4ad4);
            fparam_1 = f1AfterCall2;
          }
          else {
            fparam_1 = (double)(float)((double)floatOne / f1AfterCall2);
            lightAttenuation = (double)(floatOne / (float)((double)(float)((double)*(float *)(
                                                  lightParams2 + 0x2878) * fparam_1) * fparam_1 +
                                                  (double)(float)((double)*(float *)(lightParams2 + 0x2874
                                                                                    ) * fparam_1 +
                                                                 (double)*(float *)(lightParams2 + 0x2870)
                                                                 )));
          }
        }
        else {
          lightAttenuation = (double)FLOAT_00108e54;
          local_100 = *(float *)(lightRecord + 0x4a7c);
          toLightY = *(float *)(lightRecord + 0x4a80);
          toLightZ = *(float *)(lightRecord + 0x4a84);
        }
        if (*(char *)(lightRecord + 0x4ada) != '\0') {
          fparam_1 = -(double)(toLightZ * *(float *)(lightRecord + 0x4a90) +
                              (local_100 * *(float *)(lightRecord + 0x4a88) +
                              toLightY * *(float *)(lightRecord + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(lightParams2 + 0x286c)) goto LAB_000d5b80;
          fparam_1 = ((double (*)())_gleLightExponentPow)(iVar6,lightRecord + 0x4a70,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                                fparam_6,fparam_7,fparam_8,incomingStack_fffffea8,incomingStack_fffffeb0,
                                incomingStack_fffffeb8,incomingStack_fffffec0,incomingStack_fffffec8);
          lightAttenuation = (double)(float)((double)lightAttenuation * fparam_1);
          iVar6 = iVar6;
        }
        if (*(char *)(glContext + 0x30ae) == '\0') {
          if (localViewer == 0) {
            halfZ = (toLightZ + floatOne);
            halfX = local_100;
            halfY = toLightY;
          }
          else {
            halfX = -*eyePosition;
            halfY = -eyePosition[1];
            halfZ = -eyePosition[2];
            (**(code **)vectorNormalize)(glContext,&halfX,&halfX);
            halfX = halfX + local_100;
            halfY = halfY + toLightY;
            halfZ = halfZ + toLightZ;
          }
          f1AfterCall3 = ((double (*)())(*(code **)vectorNormalize))(glContext,&halfX,&halfX);
          fparam_1 = f1AfterCall3;
        }
        if ((double)lightAttenuation != (double)FLOAT_00108e50) {
          fparam_4 = (double)*(float *)(vertex + 0x44);
          dVar26 = (double)toLightY;
          fparam_5 = (double)*(float *)(vertex + 0x40);
          fparam_3 = (double)local_100;
          fparam_6 = (double)*(float *)(vertex + 0x48);
          fparam_2 = (double)toLightZ;
          lightContributionR = (double)*(float *)(lightProducts + 0x50);
          lightContributionG = (double)*(float *)(lightProducts + 0x54);
          lightContributionB = (double)*(float *)(lightProducts + 0x58);
          dVar17 = (double)(float)(fparam_6 * fparam_2 +
                                  (double)(float)(fparam_5 * fparam_3 +
                                                 (double)(float)(fparam_4 * (double)dVar26)));
          if ((double)FLOAT_00108e50 < -dVar17) {
            lightContributionR = -(double)(float)(dVar17 * (double)*(float *)(lightProducts + 0x60) - (double)lightContributionR);
            lightContributionG = -(double)(float)(dVar17 * (double)*(float *)(lightProducts + 100) - (double)lightContributionG);
            lightContributionB = -(double)(float)(dVar17 * (double)*(float *)(lightProducts + 0x68) - (double)lightContributionB);
            if (*(char *)(glContext + 0x30ae) == '\0') {
              dVar17 = -(double)(float)(fparam_6 * (double)halfZ +
                                       (double)(float)(fparam_5 * (double)halfX +
                                                      (double)(float)(fparam_4 * (double)halfY))
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
              dVar17 = (double)(local_d8 * halfZ + (local_e0 * halfX + local_dc * halfY));
            }
            if (!((double)floatZero < dVar17)) goto LAB_000d5b34;
            fparam_2 = (double)*(float *)(material + 0x40);
            dVar17 = _pow(dVar17,fparam_2);
            fVar1 = (float)dVar17;
            dVar26 = (double)(fVar1 * *(float *)(lightProducts + 0x78));
            iVar6 = r3AfterCall2;
            fparam_1 = (double)(fVar1 * *(float *)(lightProducts + 0x74));
            dVar17 = (double)(fVar1 * *(float *)(lightProducts + 0x70));
          }
          else {
LAB_000d5b34:
            dVar26 = (double)FLOAT_00108e50;
            fparam_1 = (double)dVar26;
            dVar17 = (double)dVar26;
          }
          if ((double)lightAttenuation == (double)floatOne) {
            colorR = (double)(colorR + lightContributionR);
            colorG = (double)(colorG + lightContributionG);
            colorB = (double)(colorB + lightContributionB);
            dVar23 = (double)(float)((double)dVar23 + dVar17);
            dVar21 = (double)(float)((double)dVar21 + fparam_1);
            dVar20 = (double)(dVar20 + dVar26);
          }
          else {
            dVar20 = (double)(lightAttenuation * dVar26 + dVar20);
            colorR = (double)(lightAttenuation * lightContributionR + colorR);
            colorG = (double)(lightAttenuation * lightContributionG + colorG);
            colorB = (double)(lightAttenuation * lightContributionB + colorB);
            dVar23 = (double)(float)((double)lightAttenuation * dVar17 + (double)dVar23);
            dVar21 = (double)(float)((double)lightAttenuation * fparam_1 + (double)dVar21);
          }
        }
      }
      else {
        fparam_7 = (double)*(float *)(vertex + 0x44);
        fparam_6 = (double)*(float *)(lightRecord + 0x4a80);
        fparam_8 = (double)*(float *)(vertex + 0x40);
        dVar16 = (double)*(float *)(vertex + 0x48);
        dVar17 = (double)*(float *)(lightRecord + 0x4a84);
        colorR = (double)(colorR + *(float *)(lightProducts + 0x50));
        dVar18 = (double)(float)((double)dVar16 * dVar17 +
                                (double)(float)(fparam_8 * (double)*(float *)(lightRecord + 0x4a7c) +
                                               (double)(float)(fparam_7 * fparam_6)));
        colorG = (double)(colorG + *(float *)(lightProducts + 0x54));
        colorB = (double)(colorB + *(float *)(lightProducts + 0x58));
        fparam_1 = -(double)dVar18;
        if ((double)floatZero < fparam_1) {
          colorR = -(double)(dVar18 * *(float *)(lightProducts + 0x60) - colorR);
          colorG = -(double)(dVar18 * *(float *)(lightProducts + 100) - colorG);
          colorB = -(double)(dVar18 * *(float *)(lightProducts + 0x68) - colorB);
          if (*(char *)(glContext + 0x30ae) == '\0') {
            fparam_1 = -(double)(dVar16 * *(float *)(lightParams + 0x2888) + (float)(fparam_8 *
                                                       (double)*(float *)(lightParams + 0x2880) +
                                                      (double)(float)(fparam_7 *
                                                                     (double)*(float *)(lightParams + 
                                                  0x2884))));
          }
          else {
            local_f8 = *(float *)(lightRecord + 0x4a84);
            local_100 = (float)((double)dVar16 * fparam_6 - (double)(float)(fparam_7 * dVar17));
            local_fc = (float)(fparam_8 * dVar17 -
                              (double)(dVar16 * *(float *)(lightRecord + 0x4a7c)));
            fVar1 = (float)(fparam_7 * (double)local_100 -
                           (double)(float)(fparam_8 * (double)local_fc));
            fparam_1 = (double)(float)((double)(fVar1 + fVar1) + dVar17);
          }
          if ((double)floatZero < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar6,material + 0x1e8,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,
                                  fparam_6,fparam_7,fparam_8,incomingStack_fffffea8,incomingStack_fffffeb0,
                                  incomingStack_fffffeb8,incomingStack_fffffec0,incomingStack_fffffec8);
            colorB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)colorB);
            colorR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)colorR);
            colorG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)colorG);
            iVar6 = iVar6;
          }
        }
      }
LAB_000d5b80:
      lightIndex = lightIndex + 1;
      lightRecord = lightRecord + 0x6c;
      lightProducts = lightProducts + 0x30;
      lightParams = lightParams + 0x80;
      lightParams2 = lightParams2 + 0x80;
    } while( true );
  }
  goto LAB_000d5bd8;
LAB_000d5b98:
  if (*(short *)(glContext + 0x30a8) == -0x7e06) {
    *(float *)(vertex + 0x50) = (float)(double)dVar23;
    *(float *)(vertex + 0x54) = (float)(double)dVar21;
    *(float *)(vertex + 0x58) = (float)(double)dVar20;
  }
  else {
    colorR = (double)(colorR + dVar23);
    colorG = (double)(colorG + dVar21);
    colorB = (double)(colorB + dVar20);
  }
  *(float *)(vertex + 0x30) = (float)(double)colorR;
  *(float *)(vertex + 0x34) = (float)(double)colorG;
  *(float *)(vertex + 0x38) = (float)(double)colorB;
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
LAB_000d5bd8:
  vertexIndex = vertexIndex + 1;
  vertex = vertex + 0x100;
  if (iStack00000020 <= vertexIndex) {
    return;
  }
  goto LAB_000d55d4;
}

/* _gleVtxLightFastRGBAFront @ 0xd5bf8 (372 bytes) */
void _gleVtxLightFastRGBAFront(int glContext,int vertex,int vertexCount,double unusedFloatArg1)
{
  undefined4 colorAlpha;
  int iVar2;
  int extraout_r3;
  int vertexIndex;
  uint enabledLightMask;
  uint lightIndex;
  int lightParams;
  int iVar7;
  int material;
  int iVar9;
  double dVar10;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double floatZero;
  double fparam_8;
  float dVar11;
  float dVar12;
  float dVar13;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  double incomingStack_ffffff98;
  
  vertexIndex = 0;
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  iVar2 = glContext;
  if (vertexCount < 1) {
LAB_000d5d60:
    return;
  }
LAB_000d5c2c:
  if ((*(byte *)(vertex + 0x7e) & 2) != 0) {
    material = *(int *)(vertex + 0x74);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfd;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,0);
    }
    dVar13 = (double)*(float *)(material + 0x1e8);
    iVar7 = material + 0x50;
    dVar12 = (double)*(float *)(material + 0x1ec);
    dVar11 = (double)*(float *)(material + 0x1f0);
    lightIndex = 0;
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    lightParams = glContext + 0x2820;
    iVar9 = glContext + 0x4a70;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d5d40;
      }
      else {
        fparam_8 = (double)*(float *)(vertex + 0x48);
        floatZero = (double)FLOAT_00108e50;
        dVar10 = (double)(float)(fparam_8 * (double)*(float *)(iVar9 + 0x14) +
                                (double)(*(float *)(vertex + 0x40) * *(float *)(iVar9 + 0xc) +
                                        *(float *)(vertex + 0x44) * *(float *)(iVar9 + 0x10)));
        if (floatZero < dVar10) {
          dVar12 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x14) + (double)dVar12);
          dVar11 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x18) + (double)dVar11);
          dVar13 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x10) + (double)dVar13);
          dVar10 = (double)(float)(fparam_8 * (double)*(float *)(lightParams + 0x68) +
                                  (double)(*(float *)(vertex + 0x40) * *(float *)(lightParams + 0x60) +
                                          *(float *)(vertex + 0x44) * *(float *)(lightParams + 100)));
          if (floatZero < dVar10) {
            dVar10 = ((double (*)())_gleMaterialShinePow)(iVar2,material + 0x1e8,dVar10,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,floatZero,
                                fparam_8,incomingStack_ffffff78,incomingStack_ffffff80,incomingStack_ffffff88,
                                incomingStack_ffffff90,incomingStack_ffffff98);
            dVar13 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x20) + (double)dVar13);
            dVar12 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x24) + (double)dVar12);
            dVar11 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x28) + (double)dVar11);
            iVar2 = iVar2;
          }
        }
      }
      lightIndex = lightIndex + 1;
      iVar9 = iVar9 + 0x6c;
      iVar7 = iVar7 + 0x30;
      lightParams = lightParams + 0x80;
    } while( true );
  }
  goto LAB_000d5d50;
LAB_000d5d40:
  *(float *)(vertex + 0x30) = (float)(double)dVar13;
  *(float *)(vertex + 0x34) = (float)(double)dVar12;
  *(float *)(vertex + 0x38) = (float)(double)dVar11;
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
LAB_000d5d50:
  vertexIndex = vertexIndex + 1;
  vertex = vertex + 0x100;
  if (vertexCount <= vertexIndex) goto LAB_000d5d60;
  goto LAB_000d5c2c;
}

/* _gleVtxLightFastRGBABack @ 0xd5d6c (376 bytes) */
void _gleVtxLightFastRGBABack(int glContext,int vertex,int vertexCount,double unusedFloatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9)
{
  undefined4 colorAlpha;
  int iVar2;
  int extraout_r3;
  int vertexIndex;
  uint enabledLightMask;
  uint lightIndex;
  int lightParams;
  int iVar7;
  int material;
  int iVar9;
  double fparam_1_00;
  double dVar10;
  double fparam_8_00;
  float dVar11;
  float dVar12;
  float dVar13;
  float dVar14;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  double incomingStack_ffffff88;
  double incomingStack_ffffff90;
  double incomingStack_ffffff98;
  
  vertexIndex = 0;
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  iVar2 = glContext;
  if (vertexCount < 1) {
LAB_000d5ed8:
    return;
  }
LAB_000d5da0:
  if ((*(byte *)(vertex + 0x7e) & 4) != 0) {
    material = *(int *)(vertex + 0x78);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfb;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,1);
    }
    dVar14 = (double)*(float *)(material + 0x1e8);
    iVar7 = material + 0x50;
    dVar13 = (double)*(float *)(material + 0x1ec);
    dVar12 = (double)*(float *)(material + 0x1f0);
    lightIndex = 0;
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    lightParams = glContext + 0x2820;
    iVar9 = glContext + 0x4a70;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d5eb8;
      }
      else {
        fparam_8_00 = (double)*(float *)(vertex + 0x48);
        dVar10 = (double)FLOAT_00108e50;
        dVar11 = (double)(float)(fparam_8_00 * (double)*(float *)(iVar9 + 0x14) +
                                (double)(*(float *)(vertex + 0x40) * *(float *)(iVar9 + 0xc) +
                                        *(float *)(vertex + 0x44) * *(float *)(iVar9 + 0x10)));
        if (dVar10 < -(double)dVar11) {
          dVar14 = -(double)(dVar11 * *(float *)(iVar7 + 0x10) - dVar14);
          dVar13 = -(double)(dVar11 * *(float *)(iVar7 + 0x14) - dVar13);
          fparam_1_00 = -(double)(float)(fparam_8_00 * (double)*(float *)(lightParams + 0x68) +
                                        (double)(*(float *)(vertex + 0x40) *
                                                 *(float *)(lightParams + 0x60) +
                                                *(float *)(vertex + 0x44) * *(float *)(lightParams + 100)
                                                ));
          dVar12 = -(double)(dVar11 * *(float *)(iVar7 + 0x18) - dVar12);
          if (dVar10 < fparam_1_00) {
            dVar10 = ((double (*)())_gleMaterialShinePow)(iVar2,material + 0x1e8,fparam_1_00,floatArg2,floatArg3,floatArg4,floatArg5,
                                floatArg6,dVar10,fparam_8_00,incomingStack_ffffff78,incomingStack_ffffff80,
                                incomingStack_ffffff88,incomingStack_ffffff90,incomingStack_ffffff98);
            dVar14 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x20) + (double)dVar14);
            dVar13 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x24) + (double)dVar13);
            dVar12 = (double)(float)(dVar10 * (double)*(float *)(iVar7 + 0x28) + (double)dVar12);
            iVar2 = iVar2;
          }
        }
      }
      lightIndex = lightIndex + 1;
      iVar9 = iVar9 + 0x6c;
      iVar7 = iVar7 + 0x30;
      lightParams = lightParams + 0x80;
    } while( true );
  }
  goto LAB_000d5ec8;
LAB_000d5eb8:
  *(float *)(vertex + 0x30) = (float)(double)dVar14;
  *(float *)(vertex + 0x34) = (float)(double)dVar13;
  *(float *)(vertex + 0x38) = (float)(double)dVar12;
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
LAB_000d5ec8:
  vertexIndex = vertexIndex + 1;
  vertex = vertex + 0x100;
  if (vertexCount <= vertexIndex) goto LAB_000d5ed8;
  goto LAB_000d5da0;
}

/* _gleVtxLightRGBAFrontPtr @ 0xd5ee4 (1192 bytes) */
void _gleVtxLightRGBAFrontPtr(int glContext,int *vertexPtrCursor,int vertexCount,double fparam_1)
{
  float fVar1;
  undefined4 colorAlpha;
  undefined *vectorNormalize;
  int iVar4;
  int extraout_r3;
  int r3AfterCall1;
  uint enabledLightMask;
  int vertexIndex;
  float *pfVar7;
  uint lightIndex;
  int lightParams;
  int material;
  int lightParams2;
  int lightProducts;
  int lightRecord;
  int iVar14;
  double extraout_f1;
  double f1AfterCall1;
  double dVar15;
  double floatZero;
  double f1AfterCall2;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  float floatOne;
  float lightContributionG;
  float lightContributionR;
  float lightContributionB;
  float colorB;
  float colorG;
  float colorR;
  float lightAttenuation;
  int iStack00000020;
  double incomingStack_fffffee8;
  double incomingStack_fffffef0;
  double incomingStack_fffffef8;
  double incomingStack_ffffff00;
  double incomingStack_ffffff08;
  float local_e0;
  float local_dc;
  float local_d8;
  float toLightX;
  float toLightY;
  float toLightZ;
  float halfX;
  float halfY;
  float halfZ;
  uint localViewer;
  float *local_ac;
  
  vertexIndex = 0;
  localViewer = (uint)*(byte *)(glContext + 0x30ad);
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  iVar4 = glContext;
  iStack00000020 = vertexCount;
  if (vertexCount < 1) {
    return;
  }
LAB_000d5f28:
  iVar14 = *vertexPtrCursor;
  vertexPtrCursor = vertexPtrCursor + 1;
  if ((*(byte *)(iVar14 + 0x7e) & 2) != 0) {
    material = *(int *)(iVar14 + 0x74);
    *(byte *)(iVar14 + 0x7e) = *(byte *)(iVar14 + 0x7e) & 0xfd;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,0);
          }
    vectorNormalize = PTR__gleVectorNormalize_00112064;
    pfVar7 = (float *)(iVar14 + 0x20);
    if (*(float *)(iVar14 + 0x2c) != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / *(float *)(iVar14 + 0x2c);
      pfVar7 = &local_e0;
      local_d8 = *(float *)(iVar14 + 0x28) * fVar1;
      local_e0 = *(float *)(iVar14 + 0x20) * fVar1;
      local_dc = *(float *)(iVar14 + 0x24) * fVar1;
    }
    colorR = (double)*(float *)(material + 0x1d0);
    colorG = (double)*(float *)(material + 0x1d4);
    lightIndex = 0;
    colorB = (double)*(float *)(material + 0x1d8);
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    local_ac = &FLOAT_00108e80;
    floatOne = (double)FLOAT_00108e54;
    lightParams = glContext;
    lightParams2 = glContext;
    lightProducts = material;
    lightRecord = glContext;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d6360;
      }
      else if (*(char *)(lightRecord + 0x4ad8) == '\0') {
        if (*(char *)(lightRecord + 0x4ad9) == '\0') {
          toLightX = *(float *)(lightRecord + 0x4a70) - *pfVar7;
          toLightY = *(float *)(lightRecord + 0x4a74) - pfVar7[1];
          toLightZ = *(float *)(lightRecord + 0x4a78) - pfVar7[2];
          f1AfterCall1 = ((double (*)())(*(code **)vectorNormalize))(glContext,&toLightX,&toLightX);
          if ((*(char *)(lightRecord + 0x4adb) != '\0') || (f1AfterCall1 < (double)*local_ac)) {
            lightAttenuation = (double)*(float *)(lightRecord + 0x4ad4);
          }
          else {
            fVar1 = (float)((double)floatOne / f1AfterCall1);
            lightAttenuation = (double)(floatOne / (*(float *)(lightParams2 + 0x2878) * fVar1 * fVar1 +
                                                      (*(float *)(lightParams2 + 0x2874) * fVar1 +
                                                      *(float *)(lightParams2 + 0x2870))));
          }
        }
        else {
          lightAttenuation = (double)FLOAT_00108e54;
          toLightX = *(float *)(lightRecord + 0x4a7c);
          toLightY = *(float *)(lightRecord + 0x4a80);
          toLightZ = *(float *)(lightRecord + 0x4a84);
        }
        if (*(char *)(lightRecord + 0x4ada) != '\0') {
          fparam_1 = -(double)(toLightZ * *(float *)(lightRecord + 0x4a90) +
                              (toLightX * *(float *)(lightRecord + 0x4a88) +
                              toLightY * *(float *)(lightRecord + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(lightParams2 + 0x286c)) goto LAB_000d6348;
          dVar15 = ((double (*)())_gleLightExponentPow)(iVar4,lightRecord + 0x4a70,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
                              incomingFpr8,incomingStack_fffffee8,incomingStack_fffffef0,incomingStack_fffffef8,
                              incomingStack_ffffff00,incomingStack_ffffff08);
          lightAttenuation = (double)(float)((double)lightAttenuation * dVar15);
        }
        if (localViewer == 0) {
          halfZ = (toLightZ + floatOne);
          halfX = toLightX;
          halfY = toLightY;
        }
        else {
          halfX = -*pfVar7;
          halfY = -pfVar7[1];
          halfZ = -pfVar7[2];
          (**(code **)vectorNormalize)(glContext,&halfX,&halfX);
          halfX = halfX + toLightX;
          halfY = halfY + toLightY;
          halfZ = halfZ + toLightZ;
        }
        f1AfterCall2 = ((double (*)())(*(code **)vectorNormalize))(glContext,&halfX,&halfX);
        floatZero = (double)FLOAT_00108e50;
        fparam_1 = f1AfterCall2;
        if ((double)lightAttenuation != floatZero) {
          incomingFpr8 = (double)*(float *)(iVar14 + 0x40);
          incomingFpr7 = (double)*(float *)(iVar14 + 0x48);
          lightContributionR = (double)*(float *)(lightProducts + 0x50);
          lightContributionG = (double)*(float *)(lightProducts + 0x54);
          lightContributionB = (double)*(float *)(lightProducts + 0x58);
          fparam_1 = (double)(float)(incomingFpr7 * (double)toLightZ +
                                    (double)(float)(incomingFpr8 * (double)toLightX +
                                                   (double)(*(float *)(iVar14 + 0x44) * toLightY)));
          if (floatZero < fparam_1) {
            lightContributionB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x68) + (double)lightContributionB);
            lightContributionR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x60) + (double)lightContributionR);
            lightContributionG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 100) + (double)lightContributionG);
            fparam_1 = (double)(float)(incomingFpr7 * (double)halfZ +
                                      (double)(float)(incomingFpr8 * (double)halfX +
                                                     (double)(*(float *)(iVar14 + 0x44) * halfY))
                                      );
            if (floatZero < fparam_1) {
              incomingFpr2 = (double)*(float *)(material + 0x40);
              dVar15 = _pow(fparam_1,incomingFpr2);
              fparam_1 = (double)(float)dVar15;
              lightContributionB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)lightContributionB);
              lightContributionR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)lightContributionR);
              lightContributionG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)lightContributionG);
              iVar4 = r3AfterCall1;
            }
          }
          if ((double)lightAttenuation == (double)floatOne) {
            colorR = (double)(colorR + lightContributionR);
            colorG = (double)(colorG + lightContributionG);
            colorB = (double)(colorB + lightContributionB);
          }
          else {
            colorB = (double)(lightAttenuation * lightContributionB + colorB);
            colorR = (double)(lightAttenuation * lightContributionR + colorR);
            colorG = (double)(lightAttenuation * lightContributionG + colorG);
          }
        }
      }
      else {
        incomingFpr8 = (double)*(float *)(iVar14 + 0x48);
        incomingFpr7 = (double)FLOAT_00108e50;
        fparam_1 = (double)(float)(incomingFpr8 * (double)*(float *)(lightRecord + 0x4a84) +
                                  (double)(*(float *)(iVar14 + 0x40) * *(float *)(lightRecord + 0x4a7c) +
                                          *(float *)(iVar14 + 0x44) * *(float *)(lightRecord + 0x4a80)));
        colorR = (double)(colorR + *(float *)(lightProducts + 0x50));
        colorG = (double)(colorG + *(float *)(lightProducts + 0x54));
        colorB = (double)(colorB + *(float *)(lightProducts + 0x58));
        if (incomingFpr7 < fparam_1) {
          colorR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x60) + (double)colorR);
          colorG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 100) + (double)colorG);
          colorB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x68) + (double)colorB);
          fparam_1 = (double)(float)(incomingFpr8 * (double)*(float *)(lightParams + 0x2888) +
                                    (double)(*(float *)(iVar14 + 0x40) * *(float *)(lightParams + 0x2880)
                                            + *(float *)(iVar14 + 0x44) * *(float *)(lightParams + 0x2884)
                                            ));
          if (incomingFpr7 < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar4,material + 0x1e8,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,
                                  incomingFpr8,incomingStack_fffffee8,incomingStack_fffffef0,incomingStack_fffffef8,
                                  incomingStack_ffffff00,incomingStack_ffffff08);
            colorB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)colorB);
            colorR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)colorR);
            colorG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)colorG);
            iVar4 = iVar4;
          }
        }
      }
LAB_000d6348:
      lightIndex = lightIndex + 1;
      lightRecord = lightRecord + 0x6c;
      lightProducts = lightProducts + 0x30;
      lightParams = lightParams + 0x80;
      lightParams2 = lightParams2 + 0x80;
    } while( true );
  }
  goto LAB_000d6370;
LAB_000d6360:
  *(undefined4 *)(iVar14 + 0x3c) = colorAlpha;
  *(float *)(iVar14 + 0x30) = (float)(double)colorR;
  *(float *)(iVar14 + 0x34) = (float)(double)colorG;
  *(float *)(iVar14 + 0x38) = (float)(double)colorB;
LAB_000d6370:
  vertexIndex = vertexIndex + 1;
  if (iStack00000020 <= vertexIndex) {
    return;
  }
  goto LAB_000d5f28;
}

/* _gleVtxLightRGBABackPtr @ 0xd638c (1200 bytes) */
void _gleVtxLightRGBABackPtr(int glContext,int *vertexPtrCursor,int vertexCount,double fparam_1,double fparam_2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double fparam_7,double fparam_8,double unusedFloatArg9)
{
  float fVar1;
  undefined4 colorAlpha;
  undefined *vectorNormalize;
  int iVar4;
  int extraout_r3;
  int r3AfterCall1;
  uint enabledLightMask;
  int vertexIndex;
  float *pfVar7;
  uint lightIndex;
  int lightParams;
  int material;
  int lightParams2;
  int lightProducts;
  int lightRecord;
  int iVar14;
  double extraout_f1;
  double f1AfterCall1;
  double dVar15;
  double f1AfterCall2;
  float dVar16;
  float lightAttenuation;
  float floatOne;
  float lightContributionG;
  float lightContributionR;
  float lightContributionB;
  float colorB;
  float colorG;
  float colorR;
  int iStack00000020;
  double incomingStack_fffffee8;
  double incomingStack_fffffef0;
  double incomingStack_fffffef8;
  double incomingStack_ffffff00;
  double incomingStack_ffffff08;
  float local_e0;
  float local_dc;
  float local_d8;
  float toLightX;
  float toLightY;
  float toLightZ;
  float halfX;
  float halfY;
  float halfZ;
  uint localViewer;
  float *local_ac;
  
  vertexIndex = 0;
  localViewer = (uint)*(byte *)(glContext + 0x30ad);
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  iVar4 = glContext;
  iStack00000020 = vertexCount;
  if (vertexCount < 1) {
    return;
  }
LAB_000d63d0:
  iVar14 = *vertexPtrCursor;
  vertexPtrCursor = vertexPtrCursor + 1;
  if ((*(byte *)(iVar14 + 0x7e) & 4) != 0) {
    material = *(int *)(iVar14 + 0x78);
    *(byte *)(iVar14 + 0x7e) = *(byte *)(iVar14 + 0x7e) & 0xfb;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,1);
          }
    vectorNormalize = PTR__gleVectorNormalize_00112064;
    pfVar7 = (float *)(iVar14 + 0x20);
    if (*(float *)(iVar14 + 0x2c) != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / *(float *)(iVar14 + 0x2c);
      pfVar7 = &local_e0;
      local_d8 = *(float *)(iVar14 + 0x28) * fVar1;
      local_e0 = *(float *)(iVar14 + 0x20) * fVar1;
      local_dc = *(float *)(iVar14 + 0x24) * fVar1;
    }
    colorR = (double)*(float *)(material + 0x1d0);
    colorG = (double)*(float *)(material + 0x1d4);
    lightIndex = 0;
    colorB = (double)*(float *)(material + 0x1d8);
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    local_ac = &FLOAT_00108e80;
    floatOne = (double)FLOAT_00108e54;
    lightParams = glContext;
    lightParams2 = glContext;
    lightProducts = material;
    lightRecord = glContext;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d6810;
      }
      else if (*(char *)(lightRecord + 0x4ad8) == '\0') {
        if (*(char *)(lightRecord + 0x4ad9) == '\0') {
          toLightX = *(float *)(lightRecord + 0x4a70) - *pfVar7;
          toLightY = *(float *)(lightRecord + 0x4a74) - pfVar7[1];
          toLightZ = *(float *)(lightRecord + 0x4a78) - pfVar7[2];
          f1AfterCall1 = ((double (*)())(*(code **)vectorNormalize))(glContext,&toLightX,&toLightX);
          if ((*(char *)(lightRecord + 0x4adb) != '\0') || (f1AfterCall1 < (double)*local_ac)) {
            lightAttenuation = (double)*(float *)(lightRecord + 0x4ad4);
          }
          else {
            fVar1 = (float)((double)floatOne / f1AfterCall1);
            lightAttenuation = (double)(floatOne / (*(float *)(lightParams2 + 0x2878) * fVar1 * fVar1 +
                                                      (*(float *)(lightParams2 + 0x2874) * fVar1 +
                                                      *(float *)(lightParams2 + 0x2870))));
          }
        }
        else {
          lightAttenuation = (double)FLOAT_00108e54;
          toLightX = *(float *)(lightRecord + 0x4a7c);
          toLightY = *(float *)(lightRecord + 0x4a80);
          toLightZ = *(float *)(lightRecord + 0x4a84);
        }
        if (*(char *)(lightRecord + 0x4ada) != '\0') {
          fparam_1 = -(double)(toLightZ * *(float *)(lightRecord + 0x4a90) +
                              (toLightX * *(float *)(lightRecord + 0x4a88) +
                              toLightY * *(float *)(lightRecord + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(lightParams2 + 0x286c)) goto LAB_000d67f8;
          dVar15 = ((double (*)())_gleLightExponentPow)(iVar4,lightRecord + 0x4a70,fparam_1,fparam_2,floatArg3,floatArg4,floatArg5,
                              floatArg6,fparam_7,fparam_8,incomingStack_fffffee8,incomingStack_fffffef0,
                              incomingStack_fffffef8,incomingStack_ffffff00,incomingStack_ffffff08);
          lightAttenuation = (double)(float)((double)lightAttenuation * dVar15);
        }
        if (localViewer == 0) {
          halfZ = (toLightZ + floatOne);
          halfX = toLightX;
          halfY = toLightY;
        }
        else {
          halfX = -*pfVar7;
          halfY = -pfVar7[1];
          halfZ = -pfVar7[2];
          (**(code **)vectorNormalize)(glContext,&halfX,&halfX);
          halfX = halfX + toLightX;
          halfY = halfY + toLightY;
          halfZ = halfZ + toLightZ;
        }
        f1AfterCall2 = ((double (*)())(*(code **)vectorNormalize))(glContext,&halfX,&halfX);
        fparam_8 = (double)FLOAT_00108e50;
        fparam_1 = f1AfterCall2;
        if ((double)lightAttenuation != fparam_8) {
          fparam_7 = (double)*(float *)(iVar14 + 0x48);
          lightContributionR = (double)*(float *)(lightProducts + 0x50);
          lightContributionG = (double)*(float *)(lightProducts + 0x54);
          lightContributionB = (double)*(float *)(lightProducts + 0x58);
          dVar15 = (double)(float)(fparam_7 * (double)toLightZ +
                                  (double)(*(float *)(iVar14 + 0x40) * toLightX +
                                          *(float *)(iVar14 + 0x44) * toLightY));
          fparam_1 = -dVar15;
          if (fparam_8 < fparam_1) {
            lightContributionR = -(double)(float)(dVar15 * (double)*(float *)(lightProducts + 0x60) - (double)lightContributionR);
            lightContributionB = -(double)(float)(dVar15 * (double)*(float *)(lightProducts + 0x68) - (double)lightContributionB);
            fparam_1 = -(double)(float)(fparam_7 * (double)halfZ +
                                       (double)(*(float *)(iVar14 + 0x40) * halfX +
                                               *(float *)(iVar14 + 0x44) * halfY));
            lightContributionG = -(double)(float)(dVar15 * (double)*(float *)(lightProducts + 100) - (double)lightContributionG);
            if (fparam_8 < fparam_1) {
              fparam_2 = (double)*(float *)(material + 0x40);
              dVar15 = _pow(fparam_1,fparam_2);
              fparam_1 = (double)(float)dVar15;
              lightContributionB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)lightContributionB);
              lightContributionR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)lightContributionR);
              lightContributionG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)lightContributionG);
              iVar4 = r3AfterCall1;
            }
          }
          if ((double)lightAttenuation == (double)floatOne) {
            colorR = (double)(colorR + lightContributionR);
            colorG = (double)(colorG + lightContributionG);
            colorB = (double)(colorB + lightContributionB);
          }
          else {
            colorB = (double)(lightAttenuation * lightContributionB + colorB);
            colorR = (double)(lightAttenuation * lightContributionR + colorR);
            colorG = (double)(lightAttenuation * lightContributionG + colorG);
          }
        }
      }
      else {
        fparam_8 = (double)*(float *)(iVar14 + 0x48);
        fparam_7 = (double)FLOAT_00108e50;
        dVar16 = (double)(float)(fparam_8 * (double)*(float *)(lightRecord + 0x4a84) +
                                (double)(*(float *)(iVar14 + 0x40) * *(float *)(lightRecord + 0x4a7c) +
                                        *(float *)(iVar14 + 0x44) * *(float *)(lightRecord + 0x4a80)));
        colorR = (double)(colorR + *(float *)(lightProducts + 0x50));
        colorG = (double)(colorG + *(float *)(lightProducts + 0x54));
        fparam_1 = -(double)dVar16;
        colorB = (double)(colorB + *(float *)(lightProducts + 0x58));
        if (fparam_7 < fparam_1) {
          colorR = -(double)(dVar16 * *(float *)(lightProducts + 0x60) - colorR);
          colorG = -(double)(dVar16 * *(float *)(lightProducts + 100) - colorG);
          fparam_1 = -(double)(float)(fparam_8 * (double)*(float *)(lightParams + 0x2888) +
                                     (double)(*(float *)(iVar14 + 0x40) * *(float *)(lightParams + 0x2880)
                                             + *(float *)(iVar14 + 0x44) *
                                               *(float *)(lightParams + 0x2884)));
          colorB = -(double)(dVar16 * *(float *)(lightProducts + 0x68) - colorB);
          if (fparam_7 < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar4,material + 0x1e8,fparam_1,fparam_2,floatArg3,floatArg4,floatArg5,
                                  floatArg6,fparam_7,fparam_8,incomingStack_fffffee8,incomingStack_fffffef0,
                                  incomingStack_fffffef8,incomingStack_ffffff00,incomingStack_ffffff08);
            colorB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)colorB);
            colorR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)colorR);
            colorG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)colorG);
            iVar4 = iVar4;
          }
        }
      }
LAB_000d67f8:
      lightIndex = lightIndex + 1;
      lightRecord = lightRecord + 0x6c;
      lightProducts = lightProducts + 0x30;
      lightParams = lightParams + 0x80;
      lightParams2 = lightParams2 + 0x80;
    } while( true );
  }
  goto LAB_000d6820;
LAB_000d6810:
  *(undefined4 *)(iVar14 + 0x3c) = colorAlpha;
  *(float *)(iVar14 + 0x30) = (float)(double)colorR;
  *(float *)(iVar14 + 0x34) = (float)(double)colorG;
  *(float *)(iVar14 + 0x38) = (float)(double)colorB;
LAB_000d6820:
  vertexIndex = vertexIndex + 1;
  if (iStack00000020 <= vertexIndex) {
    return;
  }
  goto LAB_000d63d0;
}

/* _gleVtxLightSpecRGBAFrontPtr @ 0xd683c (1680 bytes) */
void _gleVtxLightSpecRGBAFrontPtr(int glContext,int param_2,int vertexCount,double fparam_1,double fparam_2,double floatArg3,double floatArg4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  float fVar1;
  undefined4 colorAlpha;
  undefined *vectorNormalize;
  int iVar4;
  int extraout_r3;
  int extraout_r3_00;
  int r3AfterCall2;
  uint enabledLightMask;
  int vertexIndex;
  float *pfVar7;
  uint lightIndex;
  int lightParams;
  int lightParams2;
  int material;
  int lightProducts;
  int lightRecord;
  int vertex;
  double extraout_f1;
  double f1AfterCall1;
  double f1AfterCall2;
  double f1AfterCall3;
  double dVar15;
  double dVar16;
  double lightAttenuation;
  float dVar17;
  float dVar18;
  float floatOne;
  float dVar20;
  float dVar21;
  float floatZero;
  float dVar23;
  float lightContributionB;
  float lightContributionG;
  float lightContributionR;
  float colorB;
  float colorG;
  float colorR;
  int iStack0000001c;
  double incomingStack_fffffea8;
  double incomingStack_fffffeb0;
  double incomingStack_fffffeb8;
  double incomingStack_fffffec0;
  double incomingStack_fffffec8;
  float local_120;
  float local_11c;
  float local_118;
  float halfX;
  float halfY;
  float halfZ;
  float local_100;
  float local_fc;
  float toLightY;
  float local_f8;
  float toLightZ;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e0;
  float local_dc;
  float local_d8;
  uint localViewer;
  float *local_cc;
  
  vertexIndex = 0;
  localViewer = (uint)*(byte *)(glContext + 0x30ad);
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  iVar4 = glContext;
  iStack0000001c = param_2;
  if (vertexCount < 1) {
    return;
  }
LAB_000d6880:
  vertex = *(int *)(iStack0000001c + vertexIndex * 4);
  if ((*(byte *)(vertex + 0x7e) & 2) != 0) {
    material = *(int *)(vertex + 0x74);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfd;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,0);
          }
    pfVar7 = (float *)(vertex + 0x20);
    if (*(float *)(vertex + 0x2c) != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / *(float *)(vertex + 0x2c);
      pfVar7 = &local_120;
      local_118 = *(float *)(vertex + 0x28) * fVar1;
      local_120 = *(float *)(vertex + 0x20) * fVar1;
      local_11c = *(float *)(vertex + 0x24) * fVar1;
    }
    if (*(char *)(glContext + 0x30ae) != '\0') {
      if ((localViewer == 0) || (*(int *)(glContext + 0x4ddc) == 0)) {
        halfY = 0.0;
        halfZ = 1.0;
        halfX = 0.0;
      }
      else {
        halfX = -*pfVar7;
        halfY = -pfVar7[1];
        halfZ = -pfVar7[2];
        f1AfterCall1 = ((double (*)())(*(code **)PTR__gleVectorNormalize_00112064))(glContext,&halfX,&halfX);
        fparam_1 = f1AfterCall1;
      }
    }
    vectorNormalize = PTR__gleVectorNormalize_00112064;
    floatZero = (double)FLOAT_00108e50;
    colorR = (double)*(float *)(material + 0x1d0);
    lightIndex = 0;
    colorG = (double)*(float *)(material + 0x1d4);
    colorB = (double)*(float *)(material + 0x1d8);
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    local_cc = &FLOAT_00108e80;
    floatOne = (double)FLOAT_00108e54;
    lightParams = glContext;
    lightParams2 = glContext;
    lightProducts = material;
    lightRecord = glContext;
    dVar20 = (double)floatZero;
    dVar21 = (double)floatZero;
    dVar23 = (double)floatZero;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d6e74;
      }
      else if (*(char *)(lightRecord + 0x4ad8) == '\0') {
        if (*(char *)(lightRecord + 0x4ad9) == '\0') {
          local_100 = *(float *)(lightRecord + 0x4a70) - *pfVar7;
          toLightY = *(float *)(lightRecord + 0x4a74) - pfVar7[1];
          toLightZ = *(float *)(lightRecord + 0x4a78) - pfVar7[2];
          f1AfterCall2 = ((double (*)())(*(code **)vectorNormalize))(glContext,&local_100,&local_100);
          if ((*(char *)(lightRecord + 0x4adb) != '\0') || (f1AfterCall2 < (double)*local_cc)) {
            lightAttenuation = (double)*(float *)(lightRecord + 0x4ad4);
            fparam_1 = f1AfterCall2;
          }
          else {
            fparam_1 = (double)(float)((double)floatOne / f1AfterCall2);
            lightAttenuation = (double)(floatOne / (float)((double)(float)((double)*(float *)(
                                                  lightParams2 + 0x2878) * fparam_1) * fparam_1 +
                                                  (double)(float)((double)*(float *)(lightParams2 + 0x2874
                                                                                    ) * fparam_1 +
                                                                 (double)*(float *)(lightParams2 + 0x2870)
                                                                 )));
          }
        }
        else {
          lightAttenuation = (double)FLOAT_00108e54;
          local_100 = *(float *)(lightRecord + 0x4a7c);
          toLightY = *(float *)(lightRecord + 0x4a80);
          toLightZ = *(float *)(lightRecord + 0x4a84);
        }
        if (*(char *)(lightRecord + 0x4ada) != '\0') {
          fparam_1 = -(double)(toLightZ * *(float *)(lightRecord + 0x4a90) +
                              (local_100 * *(float *)(lightRecord + 0x4a88) +
                              toLightY * *(float *)(lightRecord + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(lightParams2 + 0x286c)) goto LAB_000d6e5c;
          fparam_1 = ((double (*)())_gleLightExponentPow)(iVar4,lightRecord + 0x4a70,fparam_1,fparam_2,floatArg3,floatArg4,fparam_5,
                                fparam_6,fparam_7,fparam_8,incomingStack_fffffea8,incomingStack_fffffeb0,
                                incomingStack_fffffeb8,incomingStack_fffffec0,incomingStack_fffffec8);
          lightAttenuation = (double)(float)(lightAttenuation * fparam_1);
          iVar4 = iVar4;
        }
        if (*(char *)(glContext + 0x30ae) == '\0') {
          if (localViewer == 0) {
            halfZ = (toLightZ + floatOne);
            halfX = local_100;
            halfY = toLightY;
          }
          else {
            halfX = -*pfVar7;
            halfY = -pfVar7[1];
            halfZ = -pfVar7[2];
            (**(code **)vectorNormalize)(glContext,&halfX,&halfX);
            halfX = halfX + local_100;
            halfY = halfY + toLightY;
            halfZ = halfZ + toLightZ;
          }
          f1AfterCall3 = ((double (*)())(*(code **)vectorNormalize))(glContext,&halfX,&halfX);
          fparam_1 = f1AfterCall3;
        }
        if (lightAttenuation != (double)FLOAT_00108e50) {
          dVar18 = (double)*(float *)(vertex + 0x44);
          fparam_6 = (double)toLightY;
          fparam_7 = (double)local_100;
          dVar17 = (double)*(float *)(vertex + 0x48);
          fparam_5 = (double)toLightZ;
          lightContributionR = (double)*(float *)(lightProducts + 0x50);
          lightContributionG = (double)*(float *)(lightProducts + 0x54);
          lightContributionB = (double)*(float *)(lightProducts + 0x58);
          dVar15 = (double)(float)((double)dVar17 * fparam_5 +
                                  (double)(float)((double)*(float *)(vertex + 0x40) * fparam_7 +
                                                 (double)(float)((double)dVar18 * fparam_6)));
          if ((double)FLOAT_00108e50 < dVar15) {
            lightContributionR = (double)(float)(dVar15 * (double)*(float *)(lightProducts + 0x60) + (double)lightContributionR);
            lightContributionG = (double)(float)(dVar15 * (double)*(float *)(lightProducts + 100) + (double)lightContributionG);
            lightContributionB = (double)(float)(dVar15 * (double)*(float *)(lightProducts + 0x68) + (double)lightContributionB);
            if (*(char *)(glContext + 0x30ae) == '\0') {
              fVar1 = (dVar17 * halfZ + (*(float *)(vertex + 0x40) * halfX + (dVar18 * halfY)));
            }
            else {
              local_f0 = (float)((double)dVar18 * fparam_5 - (double)(float)((double)dVar17 * fparam_6));
              fparam_8 = (double)local_f0;
              local_ec = (float)((double)dVar17 * fparam_7 -
                                (double)(float)((double)*(float *)(vertex + 0x40) * fparam_5));
              dVar15 = (double)local_ec;
              local_e8 = (float)((double)*(float *)(vertex + 0x40) * fparam_6 -
                                (double)(float)((double)*(float *)(vertex + 0x44) * fparam_7));
              dVar17 = (double)local_e8;
              fVar1 = (*(float *)(vertex + 0x44) * dVar17 - (float)((double)*(float *)(vertex + 0x48) * dVar15));
              local_e0 = (float)((double)(fVar1 + fVar1) + fparam_7);
              fVar1 = (float)((double)*(float *)(vertex + 0x48) * fparam_8 -
                             (double)(*(float *)(vertex + 0x40) * dVar17));
              local_dc = (float)((double)(fVar1 + fVar1) + fparam_6);
              fVar1 = (float)((double)*(float *)(vertex + 0x40) * dVar15 -
                             (double)(float)((double)*(float *)(vertex + 0x44) * fparam_8));
              local_d8 = (float)((double)(fVar1 + fVar1) + fparam_5);
              fVar1 = local_d8 * halfZ + (local_e0 * halfX + local_dc * halfY);
            }
            if (!((double)floatZero < (double)fVar1)) goto LAB_000d6e10;
            fparam_2 = (double)*(float *)(material + 0x40);
            dVar15 = _pow((double)fVar1,fparam_2);
            fVar1 = (float)dVar15;
            dVar17 = (double)(fVar1 * *(float *)(lightProducts + 0x78));
            iVar4 = r3AfterCall2;
            fparam_1 = (double)(fVar1 * *(float *)(lightProducts + 0x74));
            dVar15 = (double)(fVar1 * *(float *)(lightProducts + 0x70));
          }
          else {
LAB_000d6e10:
            dVar17 = (double)FLOAT_00108e50;
            fparam_1 = (double)dVar17;
            dVar15 = (double)dVar17;
          }
          if (lightAttenuation == (double)floatOne) {
            colorR = (double)(colorR + lightContributionR);
            colorG = (double)(colorG + lightContributionG);
            colorB = (double)(colorB + lightContributionB);
            dVar23 = (double)(float)((double)dVar23 + dVar15);
            dVar21 = (double)(float)((double)dVar21 + fparam_1);
            dVar20 = (double)(dVar20 + dVar17);
          }
          else {
            dVar20 = (double)(float)(lightAttenuation * (double)dVar17 + (double)dVar20);
            colorR = (double)(float)(lightAttenuation * (double)lightContributionR + (double)colorR);
            colorG = (double)(float)(lightAttenuation * (double)lightContributionG + (double)colorG);
            colorB = (double)(float)(lightAttenuation * (double)lightContributionB + (double)colorB);
            dVar23 = (double)(float)(lightAttenuation * dVar15 + (double)dVar23);
            dVar21 = (double)(float)(lightAttenuation * fparam_1 + (double)dVar21);
          }
        }
      }
      else {
        fparam_8 = (double)*(float *)(vertex + 0x44);
        fparam_7 = (double)*(float *)(lightRecord + 0x4a80);
        dVar16 = (double)*(float *)(lightRecord + 0x4a84);
        colorR = (double)(colorR + *(float *)(lightProducts + 0x50));
        fparam_1 = (double)(float)((double)*(float *)(vertex + 0x48) * dVar16 +
                                  (double)(*(float *)(vertex + 0x40) * *(float *)(lightRecord + 0x4a7c) +
                                          (float)(fparam_8 * fparam_7)));
        colorG = (double)(colorG + *(float *)(lightProducts + 0x54));
        colorB = (double)(colorB + *(float *)(lightProducts + 0x58));
        if ((double)floatZero < fparam_1) {
          colorR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x60) + (double)colorR);
          colorG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 100) + (double)colorG);
          colorB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x68) + (double)colorB);
          if (*(char *)(glContext + 0x30ae) == '\0') {
            dVar16 = (double)*(float *)(vertex + 0x48) * (double)*(float *)(lightParams + 0x2888) +
                     (double)(*(float *)(vertex + 0x40) * *(float *)(lightParams + 0x2880) +
                             (float)(fparam_8 * (double)*(float *)(lightParams + 0x2884)));
          }
          else {
            local_f8 = *(float *)(lightRecord + 0x4a84);
            local_100 = (float)(fparam_8 * dVar16 -
                               (double)(float)((double)*(float *)(vertex + 0x48) * fparam_7));
            local_fc = (*(float *)(vertex + 0x48) * *(float *)(lightRecord + 0x4a7c) - (float)((double)*(float *)(vertex + 0x40) * dVar16));
            fVar1 = (*(float *)(vertex + 0x40) * local_fc - (*(float *)(vertex + 0x44) * local_100));
            dVar16 = (double)(fVar1 + fVar1) + dVar16;
          }
          fparam_1 = (double)(float)dVar16;
          if ((double)floatZero < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar4,material + 0x1e8,fparam_1,fparam_2,floatArg3,floatArg4,fparam_5,
                                  fparam_6,fparam_7,fparam_8,incomingStack_fffffea8,incomingStack_fffffeb0,
                                  incomingStack_fffffeb8,incomingStack_fffffec0,incomingStack_fffffec8);
            colorB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)colorB);
            colorR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)colorR);
            colorG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)colorG);
            iVar4 = iVar4;
          }
        }
      }
LAB_000d6e5c:
      lightIndex = lightIndex + 1;
      lightRecord = lightRecord + 0x6c;
      lightProducts = lightProducts + 0x30;
      lightParams = lightParams + 0x80;
      lightParams2 = lightParams2 + 0x80;
    } while( true );
  }
  goto LAB_000d6eb4;
LAB_000d6e74:
  if (*(short *)(glContext + 0x30a8) == -0x7e06) {
    *(float *)(vertex + 0x50) = (float)(double)dVar23;
    *(float *)(vertex + 0x54) = (float)(double)dVar21;
    *(float *)(vertex + 0x58) = (float)(double)dVar20;
  }
  else {
    colorR = (double)(colorR + dVar23);
    colorG = (double)(colorG + dVar21);
    colorB = (double)(colorB + dVar20);
  }
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
  *(float *)(vertex + 0x30) = (float)(double)colorR;
  *(float *)(vertex + 0x34) = (float)(double)colorG;
  *(float *)(vertex + 0x38) = (float)(double)colorB;
LAB_000d6eb4:
  vertexIndex = vertexIndex + 1;
  if (vertexCount <= vertexIndex) {
    return;
  }
  goto LAB_000d6880;
}

/* _gleVtxLightSpecRGBABackPtr @ 0xd6ecc (1688 bytes) */
void _gleVtxLightSpecRGBABackPtr(int glContext,int param_2,int vertexCount,double fparam_1,double fparam_2,double floatArg3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double unusedFloatArg9,double unusedFloatArg10)
{
  float fVar1;
  float fVar2;
  undefined4 colorAlpha;
  undefined *vectorNormalize;
  int iVar5;
  int extraout_r3;
  int extraout_r3_00;
  int r3AfterCall2;
  uint enabledLightMask;
  int vertexIndex;
  float *pfVar8;
  uint lightIndex;
  int lightParams;
  int lightParams2;
  int material;
  int lightProducts;
  int lightRecord;
  int vertex;
  double extraout_f1;
  double f1AfterCall1;
  double f1AfterCall2;
  double f1AfterCall3;
  float dVar16;
  float lightAttenuation;
  double dVar17;
  float dVar18;
  float dVar19;
  float floatOne;
  float dVar21;
  float dVar22;
  float floatZero;
  float dVar24;
  float lightContributionB;
  float lightContributionG;
  float lightContributionR;
  float colorB;
  float colorG;
  float colorR;
  int iStack0000001c;
  int iStack00000020;
  double incomingStack_fffffea8;
  double incomingStack_fffffeb0;
  double incomingStack_fffffeb8;
  double incomingStack_fffffec0;
  double incomingStack_fffffec8;
  float local_120;
  float local_11c;
  float local_118;
  float halfX;
  float halfY;
  float halfZ;
  float local_100;
  float local_fc;
  float toLightY;
  float local_f8;
  float toLightZ;
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e0;
  float local_dc;
  float local_d8;
  uint localViewer;
  
  vertexIndex = 0;
  localViewer = (uint)*(byte *)(glContext + 0x30ad);
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  iVar5 = glContext;
  iStack0000001c = param_2;
  iStack00000020 = vertexCount;
  if (vertexCount < 1) {
    return;
  }
LAB_000d6f10:
  vertex = *(int *)(iStack0000001c + vertexIndex * 4);
  if ((*(byte *)(vertex + 0x7e) & 4) != 0) {
    material = *(int *)(vertex + 0x78);
    *(byte *)(vertex + 0x7e) = *(byte *)(vertex + 0x7e) & 0xfb;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,1);
          }
    pfVar8 = (float *)(vertex + 0x20);
    if (*(float *)(vertex + 0x2c) != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / *(float *)(vertex + 0x2c);
      pfVar8 = &local_120;
      local_118 = *(float *)(vertex + 0x28) * fVar1;
      local_120 = *(float *)(vertex + 0x20) * fVar1;
      local_11c = *(float *)(vertex + 0x24) * fVar1;
    }
    if (*(char *)(glContext + 0x30ae) != '\0') {
      if ((localViewer == 0) || (*(int *)(glContext + 0x4ddc) == 0)) {
        halfY = 0.0;
        halfZ = 1.0;
        halfX = 0.0;
      }
      else {
        halfX = -*pfVar8;
        halfY = -pfVar8[1];
        halfZ = -pfVar8[2];
        f1AfterCall1 = ((double (*)())(*(code **)PTR__gleVectorNormalize_00112064))(glContext,&halfX,&halfX);
        fparam_1 = f1AfterCall1;
      }
    }
    vectorNormalize = PTR__gleVectorNormalize_00112064;
    floatZero = (double)FLOAT_00108e50;
    colorR = (double)*(float *)(material + 0x1d0);
    lightIndex = 0;
    colorG = (double)*(float *)(material + 0x1d4);
    colorB = (double)*(float *)(material + 0x1d8);
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    floatOne = (double)FLOAT_00108e54;
    lightParams = glContext;
    lightParams2 = glContext;
    lightProducts = material;
    lightRecord = glContext;
    dVar21 = (double)floatZero;
    dVar22 = (double)floatZero;
    dVar24 = (double)floatZero;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d7508;
      }
      else if (*(char *)(lightRecord + 0x4ad8) == '\0') {
        if (*(char *)(lightRecord + 0x4ad9) == '\0') {
          local_100 = *(float *)(lightRecord + 0x4a70) - *pfVar8;
          toLightY = *(float *)(lightRecord + 0x4a74) - pfVar8[1];
          toLightZ = *(float *)(lightRecord + 0x4a78) - pfVar8[2];
          f1AfterCall2 = ((double (*)())(*(code **)vectorNormalize))(glContext,&local_100,&local_100);
          if ((*(char *)(lightRecord + 0x4adb) != '\0') || (f1AfterCall2 < (double)FLOAT_00108e80)) {
            lightAttenuation = (double)*(float *)(lightRecord + 0x4ad4);
            fparam_1 = f1AfterCall2;
          }
          else {
            fparam_1 = (double)(float)((double)floatOne / f1AfterCall2);
            lightAttenuation = (double)(floatOne / (float)((double)(float)((double)*(float *)(
                                                  lightParams2 + 0x2878) * fparam_1) * fparam_1 +
                                                  (double)(float)((double)*(float *)(lightParams2 + 0x2874
                                                                                    ) * fparam_1 +
                                                                 (double)*(float *)(lightParams2 + 0x2870)
                                                                 )));
          }
        }
        else {
          lightAttenuation = (double)FLOAT_00108e54;
          local_100 = *(float *)(lightRecord + 0x4a7c);
          toLightY = *(float *)(lightRecord + 0x4a80);
          toLightZ = *(float *)(lightRecord + 0x4a84);
        }
        if (*(char *)(lightRecord + 0x4ada) != '\0') {
          fparam_1 = -(double)(toLightZ * *(float *)(lightRecord + 0x4a90) +
                              (local_100 * *(float *)(lightRecord + 0x4a88) +
                              toLightY * *(float *)(lightRecord + 0x4a8c)));
          if (fparam_1 < (double)*(float *)(lightParams2 + 0x286c)) goto LAB_000d74f0;
          fparam_1 = ((double (*)())_gleLightExponentPow)(iVar5,lightRecord + 0x4a70,fparam_1,fparam_2,floatArg3,fparam_4,fparam_5,
                                fparam_6,fparam_7,fparam_8,incomingStack_fffffea8,incomingStack_fffffeb0,
                                incomingStack_fffffeb8,incomingStack_fffffec0,incomingStack_fffffec8);
          lightAttenuation = (double)(float)((double)lightAttenuation * fparam_1);
          iVar5 = iVar5;
        }
        if (*(char *)(glContext + 0x30ae) == '\0') {
          if (localViewer == 0) {
            halfZ = (toLightZ + floatOne);
            halfX = local_100;
            halfY = toLightY;
          }
          else {
            halfX = -*pfVar8;
            halfY = -pfVar8[1];
            halfZ = -pfVar8[2];
            (**(code **)vectorNormalize)(glContext,&halfX,&halfX);
            halfX = halfX + local_100;
            halfY = halfY + toLightY;
            halfZ = halfZ + toLightZ;
          }
          f1AfterCall3 = ((double (*)())(*(code **)vectorNormalize))(glContext,&halfX,&halfX);
          fparam_1 = f1AfterCall3;
        }
        if ((double)lightAttenuation != (double)FLOAT_00108e50) {
          dVar17 = (double)*(float *)(vertex + 0x44);
          fparam_5 = (double)toLightY;
          fparam_4 = (double)*(float *)(vertex + 0x40);
          fparam_7 = (double)local_100;
          fparam_8 = (double)*(float *)(vertex + 0x48);
          fparam_6 = (double)toLightZ;
          lightContributionR = (double)*(float *)(lightProducts + 0x50);
          lightContributionG = (double)*(float *)(lightProducts + 0x54);
          lightContributionB = (double)*(float *)(lightProducts + 0x58);
          dVar19 = (double)(float)(fparam_8 * fparam_6 +
                                  (double)(float)(fparam_4 * fparam_7 +
                                                 (double)(float)(dVar17 * fparam_5)));
          if ((double)FLOAT_00108e50 < -(double)dVar19) {
            lightContributionR = -(double)(dVar19 * *(float *)(lightProducts + 0x60) - lightContributionR);
            lightContributionG = -(double)(dVar19 * *(float *)(lightProducts + 100) - lightContributionG);
            lightContributionB = -(double)(dVar19 * *(float *)(lightProducts + 0x68) - lightContributionB);
            if (*(char *)(glContext + 0x30ae) == '\0') {
              dVar17 = -(double)(float)(fparam_8 * (double)halfZ +
                                       (double)(float)(fparam_4 * (double)halfX +
                                                      (double)(float)(dVar17 * (double)halfY)));
            }
            else {
              local_f0 = (float)(fparam_8 * fparam_5 - (double)(float)(dVar17 * fparam_6));
              dVar19 = (double)local_f0;
              local_ec = (float)((double)*(float *)(vertex + 0x40) * fparam_6 -
                                (double)(float)(fparam_8 * fparam_7));
              dVar18 = (double)local_ec;
              local_e8 = (float)((double)*(float *)(vertex + 0x44) * fparam_7 -
                                (double)(float)((double)*(float *)(vertex + 0x40) * fparam_5));
              dVar17 = (double)local_e8;
              fVar1 = (*(float *)(vertex + 0x48) * dVar18 - (float)((double)*(float *)(vertex + 0x44) * dVar17));
              fVar2 = (float)((double)*(float *)(vertex + 0x40) * dVar17 -
                             (double)(*(float *)(vertex + 0x48) * dVar19));
              local_e0 = (float)((double)(fVar1 + fVar1) + fparam_7);
              local_dc = (float)((double)(fVar2 + fVar2) + fparam_5);
              fVar1 = (*(float *)(vertex + 0x44) * dVar19 - (*(float *)(vertex + 0x40) * dVar18));
              local_d8 = (float)((double)(fVar1 + fVar1) + fparam_6);
              dVar17 = (double)(local_d8 * halfZ + (local_e0 * halfX + local_dc * halfY));
            }
            if (!((double)floatZero < dVar17)) goto LAB_000d74a4;
            fparam_2 = (double)*(float *)(material + 0x40);
            dVar17 = _pow(dVar17,fparam_2);
            fVar1 = (float)dVar17;
            dVar19 = (double)(fVar1 * *(float *)(lightProducts + 0x78));
            iVar5 = r3AfterCall2;
            fparam_1 = (double)(fVar1 * *(float *)(lightProducts + 0x74));
            dVar17 = (double)(fVar1 * *(float *)(lightProducts + 0x70));
          }
          else {
LAB_000d74a4:
            dVar19 = (double)FLOAT_00108e50;
            fparam_1 = (double)dVar19;
            dVar17 = (double)dVar19;
          }
          if ((double)lightAttenuation == (double)floatOne) {
            colorR = (double)(colorR + lightContributionR);
            colorG = (double)(colorG + lightContributionG);
            colorB = (double)(colorB + lightContributionB);
            dVar24 = (double)(float)((double)dVar24 + dVar17);
            dVar22 = (double)(float)((double)dVar22 + fparam_1);
            dVar21 = (double)(dVar21 + dVar19);
          }
          else {
            dVar21 = (double)(lightAttenuation * dVar19 + dVar21);
            colorR = (double)(lightAttenuation * lightContributionR + colorR);
            colorG = (double)(lightAttenuation * lightContributionG + colorG);
            colorB = (double)(lightAttenuation * lightContributionB + colorB);
            dVar24 = (double)(float)((double)lightAttenuation * dVar17 + (double)dVar24);
            dVar22 = (double)(float)((double)lightAttenuation * fparam_1 + (double)dVar22);
          }
        }
      }
      else {
        dVar19 = (double)*(float *)(vertex + 0x44);
        fparam_6 = (double)*(float *)(lightRecord + 0x4a80);
        fparam_7 = (double)*(float *)(vertex + 0x40);
        fparam_8 = (double)*(float *)(vertex + 0x48);
        dVar16 = (double)*(float *)(lightRecord + 0x4a84);
        colorR = (double)(colorR + *(float *)(lightProducts + 0x50));
        dVar17 = (double)(float)(fparam_8 * (double)dVar16 +
                                (double)(float)(fparam_7 * (double)*(float *)(lightRecord + 0x4a7c) +
                                               (double)(float)((double)dVar19 * fparam_6)));
        colorG = (double)(colorG + *(float *)(lightProducts + 0x54));
        colorB = (double)(colorB + *(float *)(lightProducts + 0x58));
        fparam_1 = -dVar17;
        if ((double)floatZero < fparam_1) {
          colorR = -(double)(float)(dVar17 * (double)*(float *)(lightProducts + 0x60) - (double)colorR);
          colorG = -(double)(float)(dVar17 * (double)*(float *)(lightProducts + 100) - (double)colorG);
          colorB = -(double)(float)(dVar17 * (double)*(float *)(lightProducts + 0x68) - (double)colorB);
          if (*(char *)(glContext + 0x30ae) == '\0') {
            fparam_1 = -(double)(float)(fparam_8 * (double)*(float *)(lightParams + 0x2888) +
                                       (double)(float)(fparam_7 *
                                                       (double)*(float *)(lightParams + 0x2880) +
                                                      (double)(dVar19 * *(float *)(
                                                  lightParams + 0x2884))));
          }
          else {
            local_f8 = *(float *)(lightRecord + 0x4a84);
            local_100 = (float)((double)*(float *)(vertex + 0x48) * fparam_6 -
                               (double)(dVar19 * dVar16));
            local_fc = (*(float *)(vertex + 0x40) * dVar16 - (*(float *)(vertex + 0x48) * *(float *)(lightRecord + 0x4a7c)));
            fVar1 = *(float *)(vertex + 0x44) * local_100 -
                    (*(float *)(vertex + 0x40) * local_fc);
            fparam_1 = (double)((fVar1 + fVar1) + dVar16);
          }
          if ((double)floatZero < fparam_1) {
            fparam_1 = ((double (*)())_gleMaterialShinePow)(iVar5,material + 0x1e8,fparam_1,fparam_2,floatArg3,fparam_4,fparam_5,
                                  fparam_6,fparam_7,fparam_8,incomingStack_fffffea8,incomingStack_fffffeb0,
                                  incomingStack_fffffeb8,incomingStack_fffffec0,incomingStack_fffffec8);
            colorB = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x78) + (double)colorB);
            colorR = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x70) + (double)colorR);
            colorG = (double)(float)(fparam_1 * (double)*(float *)(lightProducts + 0x74) + (double)colorG);
            iVar5 = iVar5;
          }
        }
      }
LAB_000d74f0:
      lightIndex = lightIndex + 1;
      lightRecord = lightRecord + 0x6c;
      lightProducts = lightProducts + 0x30;
      lightParams = lightParams + 0x80;
      lightParams2 = lightParams2 + 0x80;
    } while( true );
  }
  goto LAB_000d7548;
LAB_000d7508:
  if (*(short *)(glContext + 0x30a8) == -0x7e06) {
    *(float *)(vertex + 0x50) = (float)(double)dVar24;
    *(float *)(vertex + 0x54) = (float)(double)dVar22;
    *(float *)(vertex + 0x58) = (float)(double)dVar21;
  }
  else {
    colorR = (double)(colorR + dVar24);
    colorG = (double)(colorG + dVar22);
    colorB = (double)(colorB + dVar21);
  }
  *(undefined4 *)(vertex + 0x3c) = colorAlpha;
  *(float *)(vertex + 0x30) = (float)(double)colorR;
  *(float *)(vertex + 0x34) = (float)(double)colorG;
  *(float *)(vertex + 0x38) = (float)(double)colorB;
LAB_000d7548:
  vertexIndex = vertexIndex + 1;
  if (iStack00000020 <= vertexIndex) {
    return;
  }
  goto LAB_000d6f10;
}

/* _gleVtxLightFastRGBAFrontPtr @ 0xd7564 (376 bytes) */
void _gleVtxLightFastRGBAFrontPtr(int glContext,int *vertexPtrCursor,int vertexCount,double unusedFloatArg1)
{
  undefined4 colorAlpha;
  int iVar2;
  int extraout_r3;
  int vertexIndex;
  uint enabledLightMask;
  uint lightIndex;
  int lightParams;
  int iVar7;
  int iVar8;
  int material;
  int iVar10;
  double dVar11;
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double floatZero;
  double fparam_8;
  float dVar12;
  float dVar13;
  float dVar14;
  double incomingStack_ffffff68;
  double incomingStack_ffffff70;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  double incomingStack_ffffff88;
  
  vertexIndex = 0;
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  iVar2 = glContext;
  if (vertexCount < 1) {
LAB_000d76d0:
    return;
  }
LAB_000d7598:
  iVar7 = *vertexPtrCursor;
  vertexPtrCursor = vertexPtrCursor + 1;
  if ((*(byte *)(iVar7 + 0x7e) & 2) != 0) {
    material = *(int *)(iVar7 + 0x74);
    *(byte *)(iVar7 + 0x7e) = *(byte *)(iVar7 + 0x7e) & 0xfd;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,0);
    }
    dVar14 = (double)*(float *)(material + 0x1e8);
    iVar8 = material + 0x50;
    dVar13 = (double)*(float *)(material + 0x1ec);
    dVar12 = (double)*(float *)(material + 0x1f0);
    lightIndex = 0;
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    lightParams = glContext + 0x2820;
    iVar10 = glContext + 0x4a70;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d76b4;
      }
      else {
        fparam_8 = (double)*(float *)(iVar7 + 0x48);
        floatZero = (double)FLOAT_00108e50;
        dVar11 = (double)(float)(fparam_8 * (double)*(float *)(iVar10 + 0x14) +
                                (double)(*(float *)(iVar7 + 0x40) * *(float *)(iVar10 + 0xc) +
                                        *(float *)(iVar7 + 0x44) * *(float *)(iVar10 + 0x10)));
        if (floatZero < dVar11) {
          dVar13 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x14) + (double)dVar13);
          dVar12 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x18) + (double)dVar12);
          dVar14 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x10) + (double)dVar14);
          dVar11 = (double)(float)(fparam_8 * (double)*(float *)(lightParams + 0x68) +
                                  (double)(*(float *)(iVar7 + 0x40) * *(float *)(lightParams + 0x60) +
                                          *(float *)(iVar7 + 0x44) * *(float *)(lightParams + 100)));
          if (floatZero < dVar11) {
            dVar11 = ((double (*)())_gleMaterialShinePow)(iVar2,material + 0x1e8,dVar11,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,floatZero,
                                fparam_8,incomingStack_ffffff68,incomingStack_ffffff70,incomingStack_ffffff78,
                                incomingStack_ffffff80,incomingStack_ffffff88);
            dVar14 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x20) + (double)dVar14);
            dVar13 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x24) + (double)dVar13);
            dVar12 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x28) + (double)dVar12);
            iVar2 = iVar2;
          }
        }
      }
      lightIndex = lightIndex + 1;
      iVar10 = iVar10 + 0x6c;
      iVar8 = iVar8 + 0x30;
      lightParams = lightParams + 0x80;
    } while( true );
  }
  goto LAB_000d76c4;
LAB_000d76b4:
  *(undefined4 *)(iVar7 + 0x3c) = colorAlpha;
  *(float *)(iVar7 + 0x30) = (float)(double)dVar14;
  *(float *)(iVar7 + 0x34) = (float)(double)dVar13;
  *(float *)(iVar7 + 0x38) = (float)(double)dVar12;
LAB_000d76c4:
  vertexIndex = vertexIndex + 1;
  if (vertexCount <= vertexIndex) goto LAB_000d76d0;
  goto LAB_000d7598;
}

/* _gleVtxLightFastRGBABackPtr @ 0xd76dc (380 bytes) */
void _gleVtxLightFastRGBABackPtr(int glContext,int *vertexPtrCursor,int vertexCount,double unusedFloatArg1,double floatArg2,double floatArg3,double floatArg4,double floatArg5,double floatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9)
{
  undefined4 colorAlpha;
  int iVar2;
  int extraout_r3;
  int vertexIndex;
  uint enabledLightMask;
  uint lightIndex;
  int lightParams;
  int iVar7;
  int iVar8;
  int material;
  int iVar10;
  double fparam_1_00;
  double dVar11;
  double fparam_8_00;
  float dVar12;
  float dVar13;
  float dVar14;
  float dVar15;
  double incomingStack_ffffff68;
  double incomingStack_ffffff70;
  double incomingStack_ffffff78;
  double incomingStack_ffffff80;
  double incomingStack_ffffff88;
  
  vertexIndex = 0;
  enabledLightMask = *(uint *)(glContext + 0x30a0);
  iVar2 = glContext;
  if (vertexCount < 1) {
LAB_000d784c:
    return;
  }
LAB_000d7710:
  iVar7 = *vertexPtrCursor;
  vertexPtrCursor = vertexPtrCursor + 1;
  if ((*(byte *)(iVar7 + 0x7e) & 4) != 0) {
    material = *(int *)(iVar7 + 0x78);
    *(byte *)(iVar7 + 0x7e) = *(byte *)(iVar7 + 0x7e) & 0xfb;
    if (*(char *)(material + 0x234) != '\0') {
      _gleUpdateLightRGBASums(glContext,material,1);
    }
    dVar15 = (double)*(float *)(material + 0x1e8);
    iVar8 = material + 0x50;
    dVar14 = (double)*(float *)(material + 0x1ec);
    dVar13 = (double)*(float *)(material + 0x1f0);
    lightIndex = 0;
    colorAlpha = *(undefined4 *)(material + 0x1dc);
    lightParams = glContext + 0x2820;
    iVar10 = glContext + 0x4a70;
    do {
      if ((enabledLightMask & 1 << (lightIndex & 0x3f)) == 0) {
        if (enabledLightMask >> (lightIndex & 0x3f) == 0) goto LAB_000d7830;
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
          fparam_1_00 = -(double)(float)(fparam_8_00 * (double)*(float *)(lightParams + 0x68) +
                                        (double)(*(float *)(iVar7 + 0x40) * *(float *)(lightParams + 0x60)
                                                + *(float *)(iVar7 + 0x44) * *(float *)(lightParams + 100)
                                                ));
          dVar13 = -(double)(dVar12 * *(float *)(iVar8 + 0x18) - dVar13);
          if (dVar11 < fparam_1_00) {
            dVar11 = ((double (*)())_gleMaterialShinePow)(iVar2,material + 0x1e8,fparam_1_00,floatArg2,floatArg3,floatArg4,floatArg5,
                                floatArg6,dVar11,fparam_8_00,incomingStack_ffffff68,incomingStack_ffffff70,
                                incomingStack_ffffff78,incomingStack_ffffff80,incomingStack_ffffff88);
            dVar15 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x20) + (double)dVar15);
            dVar14 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x24) + (double)dVar14);
            dVar13 = (double)(float)(dVar11 * (double)*(float *)(iVar8 + 0x28) + (double)dVar13);
            iVar2 = iVar2;
          }
        }
      }
      lightIndex = lightIndex + 1;
      iVar10 = iVar10 + 0x6c;
      iVar8 = iVar8 + 0x30;
      lightParams = lightParams + 0x80;
    } while( true );
  }
  goto LAB_000d7840;
LAB_000d7830:
  *(undefined4 *)(iVar7 + 0x3c) = colorAlpha;
  *(float *)(iVar7 + 0x30) = (float)(double)dVar15;
  *(float *)(iVar7 + 0x34) = (float)(double)dVar14;
  *(float *)(iVar7 + 0x38) = (float)(double)dVar13;
LAB_000d7840:
  vertexIndex = vertexIndex + 1;
  if (vertexCount <= vertexIndex) goto LAB_000d784c;
  goto LAB_000d7710;
}

/* _gleBeginLinesRenderSmooth @ 0xd7858 (52 bytes) */
void _gleBeginLinesRenderSmooth(glContext)
  int glContext;
{
  undefined *flushAtomicFunc;
  
  flushAtomicFunc = PTR__gleFlushAtomicFunc_00112224;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushAtomicFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderSmoothLinesFunc_00112220;
  return;
}

/* _gleBeginLinesRenderFlat @ 0xd788c (52 bytes) */
void _gleBeginLinesRenderFlat(glContext)
  int glContext;
{
  undefined *flushAtomicFunc;
  
  flushAtomicFunc = PTR__gleFlushAtomicFunc_00112224;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushAtomicFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderFlatLinesFunc_0011221c;
  return;
}

/* _gleBeginLinesRenderTCL @ 0xd78c0 (52 bytes) */
void _gleBeginLinesRenderTCL(glContext)
  int glContext;
{
  undefined *flushAtomicTCLFunc;
  
  flushAtomicTCLFunc = PTR__gleFlushAtomicTCLFunc_00112218;
  *(undefined4 *)(glContext + 0x4858) = *(undefined4 *)(glContext + 0x4854);
  *(undefined **)(glContext + 0x4a0c) = flushAtomicTCLFunc;
  *(undefined **)(glContext + 0x4a08) = PTR__gleRenderLinesTCLFunc_00112214;
  return;
}

