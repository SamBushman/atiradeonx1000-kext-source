#include "decls.h"

/* _gldCreateTextureLevel @ 0x8e10 (76 bytes) */
int _gldCreateTextureLevel(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  uint param_5;
{
  *(byte *)(param_2 + 0x39) = param_3 | *(byte *)(param_2 + 0x39);
  if ((param_3 & 1) != 0) {
    *(undefined1 *)(param_2 + 0x38) = 0;
  }
  if ((param_3 & 7) != 0) {
    param_2 = param_4 * 2 + param_2;
    *(ushort *)(param_2 + 0x24) = (ushort)(1 << (param_5 & 0x3f)) | *(ushort *)(param_2 + 0x24);
  }
  return 0;
}

/* _gldModifyTexture @ 0x8e60 (20 bytes) */
int _gldModifyTexture(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  *(byte *)(param_2 + 0x39) = param_3 | *(byte *)(param_2 + 0x39);
  return 0;
}

/* _gldModifyTextureLevel @ 0x8e80 (204 bytes) */
int _gldModifyTextureLevel(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0x34);
  if (param_4 == 0xffffffff) {
    *(byte *)(param_2 + 0x39) = *(byte *)(param_2 + 0x39) | 0x40;
  }
  else {
    iVar2 = param_3 * 2 + param_2;
    uVar1 = *(ushort *)(iVar2 + 0x24);
    *(byte *)(param_2 + 0x39) = *(byte *)(param_2 + 0x39) | 4;
    *(ushort *)(iVar2 + 0x24) = (ushort)(1 << (param_4 & 0x3f)) | uVar1;
  }
  if ((iVar3 != 0) && ((byte)(*(char *)(iVar3 + 0x16) - 6U) < 2)) {
    if (0x1ffff < *(int *)(iVar3 + 0x10)) {
      _gldFlush(param_1);
    }
    ((int (*)())FUN_0000aaf0)(param_1,param_2);
  }
  return 0;
}

/* _gldGetTextureLevelInfo @ 0x8f60 (520 bytes) */
int _gldGetTextureLevelInfo(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined *param_5;
  uint *param_6;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  byte local_34;
  
  FUN_00030f60();
  if ((**(ushort **)(param_2 + 0x30) & 0x100) != 0) {
    uVar1 = ((int (*)())FUN_0000a9f0)(param_1,param_2);
    iVar3 = param_1;
    do {
      if (*(int *)(iVar3 + 0x18c) != 0) {
        iVar2 = ((int (*)())FUN_0000a9f0)(param_1);
        uVar1 = uVar1 + iVar2;
      }
      iVar3 = iVar3 + 4;
    } while (param_1 + 0x40 != iVar3);
    if (*(uint *)(param_1 + 0x28) < uVar1) {
      *param_6 = 0;
      return ((unsigned char *)0x00002720);
    }
  }
  if (param_5 == (undefined *)0x805f) {
    *param_6 = local_48;
    return (undefined *)0x0;
  }
  if (param_5 < (undefined *)0x8060) {
    if (param_5 == (undefined *)0x805c) {
      *param_6 = local_54;
      return (undefined *)0x0;
    }
    if (param_5 < (undefined *)0x805d) {
      if (param_5 == ((unsigned char *)0x00001003)) {
        *param_6 = local_58;
        return (undefined *)0x0;
      }
    }
    else {
      if (param_5 == (undefined *)0x805d) {
        *param_6 = local_50;
        return (undefined *)0x0;
      }
      if (param_5 == (undefined *)0x805e) {
        *param_6 = local_4c;
        return (undefined *)0x0;
      }
    }
  }
  else {
    if (param_5 == (undefined *)0x86a0) {
      *param_6 = local_38;
      return (undefined *)0x0;
    }
    if (param_5 < (undefined *)0x86a1) {
      if (param_5 == (undefined *)0x8060) {
        *param_6 = local_44;
        return (undefined *)0x0;
      }
      if (param_5 == (undefined *)0x8061) {
        *param_6 = local_40;
        return (undefined *)0x0;
      }
    }
    else {
      if (param_5 == (undefined *)0x86a1) {
        *param_6 = (uint)local_34;
        return (undefined *)0x0;
      }
      if (param_5 == (undefined *)0x884a) {
        *param_6 = local_3c;
        return (undefined *)0x0;
      }
    }
  }
  return (undefined *)0x0;
}

/* _gldDeleteTextureLevel @ 0x9180 (264 bytes) */
int _gldDeleteTextureLevel(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  
  if (param_4 == 0xffffffff) {
    *(byte *)(param_2 + 0x39) = *(byte *)(param_2 + 0x39) | 0x43;
  }
  else {
    iVar5 = param_3 * 2 + param_2;
    uVar1 = *(ushort *)(iVar5 + 0x24);
    *(byte *)(param_2 + 0x39) = *(byte *)(param_2 + 0x39) | 7;
    *(ushort *)(iVar5 + 0x24) = (ushort)(1 << (param_4 & 0x3f)) | uVar1;
  }
  iVar5 = *(int *)(param_2 + 0x34);
  if ((iVar5 != 0) && ((byte)(*(char *)(iVar5 + 0x16) - 6U) < 2)) {
    if (0x1ffff < *(int *)(iVar5 + 0x10)) {
      _gldFlush(param_1);
    }
    piVar3 = (int *)(iVar5 + 0x10);
    do {
      iVar4 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar2 = storeWordConditionalIndexed(iVar4 + -0x10000,0,piVar3);
        *piVar3 = iVar2;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar4 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar5,1,0,0);
    }
    *(undefined4 *)(param_2 + 0x34) = 0;
  }
  return 0;
}

/* _gldReclaimTexture @ 0x9290 (396 bytes) */
int _gldReclaimTexture(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  char in_RESERVE;
  byte in_cr0;
  
  iVar5 = 0;
  iVar6 = param_1;
  do {
    if (param_2 == *(int *)(iVar6 + 0x18c)) {
      *(undefined4 *)(iVar6 + 0x18c) = 0;
      FUN_000307a0(param_1,iVar5);
    }
    bVar1 = iVar5 != 0xf;
    iVar6 = iVar6 + 4;
    iVar5 = iVar5 + 1;
  } while (bVar1);
  iVar6 = *(int *)(param_2 + 0x34);
  if (iVar6 != 0) {
    if ((0x1ffff < (int)*(uint *)(iVar6 + 0x10)) || ((*(uint *)(iVar6 + 0x10) & 0xffff) != 0)) {
      _gldFlush(param_1);
    }
    ((int (*)())FUN_0000aaf0)(param_1,param_2);
    piVar3 = (int *)(iVar6 + 0x10);
    do {
      iVar5 = *piVar3;
      if (in_RESERVE != '\0') {
        iVar2 = storeWordConditionalIndexed(iVar5 + -0x10000,0,piVar3);
        *piVar3 = iVar2;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar5 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar6,1,0,0);
    }
    *(undefined4 *)(param_2 + 0x34) = 0;
  }
  while( true ) {
    piVar3 = *(int **)(param_2 + 0x18);
    if (*piVar3 == 0) break;
    piVar4 = (int *)piVar3[1];
    *piVar4 = *piVar3;
    iVar6 = *piVar3;
    *piVar3 = 0;
    *(int **)(iVar6 + 4) = piVar4;
    piVar3[1] = 0;
    if (piVar3 == (int *)0x0) break;
    iVar6 = piVar3[4];
    piVar4 = (int *)(iVar6 + 0x10);
    do {
      iVar5 = *piVar4;
      if (in_RESERVE != '\0') {
        iVar2 = storeWordConditionalIndexed(iVar5 + -0x10000,0,piVar4);
        *piVar4 = iVar2;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar5 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar6,1,0,0);
    }
    piVar3[4] = 0;
    _free(piVar3);
  }
  *(undefined1 *)(param_2 + 0x39) = 0x23;
  return;
}

/* _gldDeleteTexture @ 0x9420 (56 bytes) */
int _gldDeleteTexture(param_1, param_2)
  undefined4 param_1;
  void *param_2;
{
  ((int (*)())_gldReclaimTexture)();
  _free(param_2);
  return 0;
}

/* _gldCreatePipelineProgram @ 0x9460 (80 bytes) */
int _gldCreatePipelineProgram(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = _calloc(1,0x40);
  *param_2 = puVar1;
  *puVar1 = param_3;
  puVar1[0xf] = 3;
  return 0;
}

/* _gldModifyPipelineProgram @ 0x94b0 (48 bytes) */
int _gldModifyPipelineProgram(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  uint param_3;
{
  *(uint *)(param_2 + 0x3c) = param_3 | *(uint *)(param_2 + 0x3c);
  FUN_00024fd0();
  return 0;
}

/* _gldRelatePipelineProgram @ 0x94e0 (84 bytes) */
int _gldRelatePipelineProgram(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 *param_3;
  int param_4;
{
  if (*(short *)*param_3 == -0x74d0) {
    if (param_4 == 0) {
      param_3 = (undefined4 *)0x0;
    }
    *(undefined4 **)(param_2 + 8) = param_3;
  }
  else if (*(short *)*param_3 == -0x74cf) {
    if (param_4 == 0) {
      param_3 = (undefined4 *)0x0;
    }
    *(undefined4 **)(param_2 + 4) = param_3;
  }
  return 0;
}

/* _gldGetPipelineProgramInfo @ 0x9540 (36 bytes) */
int _gldGetPipelineProgramInfo()
{
  FUN_000269a0();
  return 0;
}

/* _gldDestroyPipelineProgram @ 0x9570 (104 bytes) */
int _gldDestroyPipelineProgram(param_1, param_2)
  int param_1;
  void *param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar2 = param_1;
  do {
    if (param_2 == *(void **)(iVar2 + 0x1cc)) {
      *(undefined4 *)(iVar2 + 0x1cc) = 0;
    }
    bVar1 = iVar3 != 1;
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + 1;
  } while (bVar1);
  FUN_00025bf0(param_1,param_2);
  _free(param_2);
  return 0;
}

/* FUN_000095e0 @ 0x95e0 (192 bytes) */
int FUN_000095e0(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar3 = 0;
  iVar4 = param_1;
  do {
    iVar2 = iVar3 * 4 + *(int *)(param_1 + 0x18);
    piVar5 = *(int **)(iVar2 + 0x198);
    if (piVar5 == (int *)0x0) {
      if (((unsigned char *)0x00004304)[iVar3 * 8 + *(int *)(param_1 + 0x10)] != '\0') {
        piVar5 = *(int **)(iVar2 + 0x18c);
        goto LAB_00009640;
      }
      *(undefined4 *)(iVar4 + 0x1cc) = 0;
    }
    else {
LAB_00009640:
      if ((*(int *)(*piVar5 + 4) == 0) || (iVar2 = FUN_00026650(param_1,piVar5), iVar2 == 0)) {
        *(undefined4 *)(iVar4 + 0x1cc) = 0;
      }
      else {
        *(int **)(iVar4 + 0x1cc) = piVar5;
      }
    }
    bVar1 = iVar3 == 1;
    iVar4 = iVar4 + 4;
    iVar3 = iVar3 + 1;
    if (bVar1) {
      return;
    }
  } while( true );
}

/* FUN_00009b70 @ 0x9b70 (88 bytes) */
int FUN_00009b70(param_1)
  int param_1;
{
  undefined *puVar1;
  void *pvVar2;
  
  pvVar2 = _calloc(1,0x18);
  puVar1 = ((unsigned char *)0x00002720);
  *(void **)(param_1 + 0x234) = pvVar2;
  if (pvVar2 != (void *)0x0) {
    puVar1 = (undefined *)0x0;
  }
  return puVar1;
}

/* FUN_00009bd0 @ 0x9bd0 (164 bytes) */
int FUN_00009bd0(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar2 = **(int **)(param_1 + 0x234);
  if (iVar2 != 0) {
    if ((0x1ffff < (int)*(uint *)(iVar2 + 0x10)) || ((*(uint *)(iVar2 + 0x10) & 0xffff) != 0)) {
      _gldFlush();
    }
    iVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar2 + 8));
    if (iVar1 == 0) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,iVar2 + 8,1,0,0);
      return;
    }
  }
  return;
}

/* _gldDestroyQuery @ 0x9c80 (76 bytes) */
int _gldDestroyQuery(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *param_2 >> 3 & 0x1ffffffc;
  uVar1 = *param_2 & 0x1f;
  *(uint *)(uVar2 + *(int *)(param_1 + 0x22c)) =
       (-2 << uVar1 | 0xfffffffeU >> 0x20 - uVar1) & *(uint *)(uVar2 + *(int *)(param_1 + 0x22c));
  _free(param_2);
  return 0;
}

/* FUN_00009cd0 @ 0x9cd0 (152 bytes) */
int FUN_00009cd0(param_1)
  int param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  
  iVar4 = **(int **)(param_1 + 0x234);
  if (iVar4 != 0) {
    ((int (*)())FUN_00009bd0)();
    piVar2 = (int *)(iVar4 + 0x10);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -0x10000,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar4,1,0,0);
      **(undefined4 **)(param_1 + 0x234) = 0;
    }
  }
  return 0;
}

/* FUN_00009d70 @ 0x9d70 (248 bytes) */
int FUN_00009d70(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_28;
  undefined1 auStack_24 [4];
  int local_20;
  
  param_2[2] = param_3;
  param_2[3] = param_4;
  param_2[1] = 6;
  param_2[4] = param_5;
  iVar4 = *param_2;
  *param_2 = 0;
  local_28 = 8;
  iVar3 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,auStack_24,&local_28);
  if (iVar3 == 0) {
    *param_2 = local_20;
    piVar2 = (int *)(local_20 + 0x10);
    do {
      if (in_RESERVE != '\0') {
        iVar3 = storeWordConditionalIndexed(*piVar2 + 0x10000,0,piVar2);
        *piVar2 = iVar3;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    *(undefined1 *)(local_20 + 0x14) = 1;
  }
  if (iVar4 != 0) {
    piVar2 = (int *)(iVar4 + 0x10);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -0x10000,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar4,1,0,0);
    }
  }
  return 1;
}

/* _gldCreateQuery @ 0x9e70 (532 bytes) */
int _gldCreateQuery(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  int iVar1;
  int *piVar2;
  undefined *puVar3;
  void *pvVar4;
  int iVar5;
  size_t sVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  
  piVar2 = _malloc(4);
  *piVar2 = 0;
  do {
    uVar11 = *(uint *)(param_1 + 0x230) >> 5;
    if (uVar11 != 0) {
      puVar7 = *(uint **)(param_1 + 0x22c);
      uVar8 = *puVar7;
      if (uVar8 != 0xffffffff) {
        iVar1 = 0;
        iVar5 = 0;
LAB_0000a030:
        iVar12 = 0x20;
        uVar11 = 0;
        break;
      }
      iVar1 = 0;
      puVar9 = puVar7;
      while( true ) {
        iVar1 = iVar1 + 1;
        puVar9 = puVar9 + 1;
        uVar11 = uVar11 - 1;
        if (uVar11 == 0) break;
        uVar8 = *puVar9;
        iVar5 = iVar1 * 4;
        if (uVar8 != 0xffffffff) goto LAB_0000a030;
      }
    }
    if ((*(int *)(param_1 + 0x234) == 0) &&
       (puVar3 = (undefined *)((int (*)())FUN_00009b70)(param_1), puVar3 == ((unsigned char *)0x00002720))) {
LAB_0000a010:
      _free(piVar2);
      *param_2 = 0;
      return ((unsigned char *)0x00002720);
    }
    if (*(int *)(param_1 + 0x228) == 0) {
      *(undefined4 *)(param_1 + 0x230) = 0x20;
      *(undefined4 *)(param_1 + 0x228) = 0x610;
      pvVar4 = _malloc(0x610);
      *(void **)(param_1 + 0x224) = pvVar4;
      _memset(pvVar4,0,*(size_t *)(param_1 + 0x228));
    }
    else {
      if (**(int **)(param_1 + 0x234) != 0) {
        ((int (*)())FUN_00009cd0)(param_1);
      }
      sVar6 = *(int *)(param_1 + 0x230) * 0x40 + 0x210;
      *(int *)(param_1 + 0x230) = *(int *)(param_1 + 0x230) << 1;
      *(size_t *)(param_1 + 0x228) = sVar6;
      pvVar4 = _realloc(*(void **)(param_1 + 0x224),sVar6);
      *(void **)(param_1 + 0x224) = pvVar4;
      if (pvVar4 == (void *)0x0) goto LAB_0000a010;
    }
    iVar5 = ((int (*)())FUN_00009d70)(param_1,*(undefined4 *)(param_1 + 0x234),*(undefined4 *)(param_1 + 0x224),
                         *(undefined4 *)(param_1 + 0x224),*(undefined4 *)(param_1 + 0x228));
    if (iVar5 != 1) goto LAB_0000a010;
    FUN_0002b3b0(param_1);
    uVar8 = *(uint *)(param_1 + 0x230);
    uVar11 = uVar8 >> 3;
    if (*(void **)(param_1 + 0x22c) == (void *)0x0) {
      pvVar4 = _malloc(uVar11);
      *(void **)(param_1 + 0x22c) = pvVar4;
      _memset(pvVar4,0,uVar11);
    }
    else {
      pvVar4 = _realloc(*(void **)(param_1 + 0x22c),uVar11);
      uVar8 = uVar8 >> 4;
      *(void **)(param_1 + 0x22c) = pvVar4;
      _memset((void *)((int)pvVar4 + uVar8),0,uVar8);
    }
  } while( true );
  while( true ) {
    uVar10 = uVar11 + 1;
    iVar12 = iVar12 + -1;
    uVar11 = uVar10;
    if (iVar12 == 0) break;
    uVar10 = uVar11;
    if ((uVar8 >> (uVar11 & 0x3f) & 1) == 0) goto LAB_0000a05c;
  }
  uVar11 = 0x20;
LAB_0000a05c:
  *(uint *)((int)puVar7 + iVar5) = 1 << (uVar11 & 0x3f) | *(uint *)((int)puVar7 + iVar5);
  *param_2 = piVar2;
  *piVar2 = uVar10 + iVar1 * 0x20;
  return (undefined *)0x0;
}

/* FUN_0000a0f0 @ 0xa0f0 (48 bytes) */
int FUN_0000a0f0(param_1)
  uint param_1;
{
  if ((param_1 & 0x1000) != 0) {
    return 0x20;
  }
  if ((param_1 & 0x800) != 0) {
    return 0x18;
  }
  if ((param_1 & 0x400) != 0) {
    return 0x10;
  }
  return param_1 >> 4 & 8;
}

/* FUN_0000a120 @ 0xa120 (92 bytes) */
int FUN_0000a120(param_1)
  uint param_1;
{
  if ((param_1 & 0x400) != 0) {
    return 1;
  }
  if ((param_1 & 0x40000) != 0) {
    return 2;
  }
  if ((param_1 & 0x80) != 0) {
    return 4;
  }
  if ((param_1 & 0x9a928) != 0) {
    return 8;
  }
  if ((param_1 & 0x200000) != 0) {
    return 0xc;
  }
  if ((param_1 & 0x2800000) != 0) {
    return 0x10;
  }
  return param_1 >> 0x16 & 0x20;
}

/* FUN_0000a180 @ 0xa180 (344 bytes) */
int FUN_0000a180(param_1, param_2)
  uint param_1;
  undefined2 *param_2;
{
  undefined2 uVar1;
  
  *param_2 = 0;
  param_2[4] = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  if ((param_1 & 0x3c) == 0) {
    if ((param_1 & 0x1c0) == 0) {
      if ((param_1 & 0xe00) == 0) {
        if ((param_1 & 0x3000) == 0) {
          if ((param_1 & 0x1c000) == 0) {
            if ((param_1 & 0xe0000) == 0) {
              if ((param_1 & 0x300000) == 0) {
                if ((param_1 & 0x2c00000) == 0) {
                  if ((param_1 & 0x8000000) == 0) {
                    return 0;
                  }
                  param_2[2] = 0x20;
                  *param_2 = 0x20;
                  param_2[1] = 0x20;
                }
                else {
                  param_2[2] = 0x10;
                  *param_2 = 0x10;
                  param_2[1] = 0x10;
                }
              }
              else {
                param_2[2] = 0xc;
                *param_2 = 0xc;
                param_2[1] = 0xc;
              }
            }
            else {
              param_2[2] = 10;
              *param_2 = 10;
              param_2[1] = 10;
            }
          }
          else {
            param_2[2] = 8;
            *param_2 = 8;
            param_2[1] = 8;
          }
        }
        else {
          param_2[2] = 5;
          param_2[1] = 6;
          *param_2 = 5;
        }
      }
      else {
        param_2[2] = 5;
        *param_2 = 5;
        param_2[1] = 5;
      }
    }
    else {
      param_2[2] = 4;
      *param_2 = 4;
      param_2[1] = 4;
    }
  }
  else {
    param_2[1] = 3;
    param_2[2] = 2;
    *param_2 = 3;
  }
  uVar1 = ((int (*)())FUN_0000a120)();
  param_2[3] = uVar1;
  return 1;
}

/* FUN_0000a2f0 @ 0xa2f0 (184 bytes) */
int FUN_0000a2f0(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  switch(param_1) {
  case 0x400:
  case 0x404:
  case 0x406:
    goto switchD_0000a324_caseD_400;
  case 0x401:
  case 0x407:
    if ((param_2 & 0x10) == 0) {
      return 1;
    }
    return 3;
  case 0x403:
    if ((param_2 & 0x400) == 0) {
      return 1;
    }
    if ((param_2 & 0x10) == 0) {
      return 0;
    }
    return 2;
  case 0x409:
    if (0xff < (param_2 & 0x300)) {
      return 7;
    }
    break;
  case 0x40a:
    if (0x1ff < (param_2 & 0x300)) {
      return 8;
    }
    break;
  case 0x40b:
    if (0x2ff < (param_2 & 0x300)) {
      return 9;
    }
  }
  if ((param_2 & 0x400) != 0) {
    return 0;
  }
switchD_0000a324_caseD_400:
  return 1;
}

/* FUN_0000a3f0 @ 0xa3f0 (592 bytes) */
int FUN_0000a3f0(param_1, param_2)
  uint param_1;
  undefined *param_2;
{
  if (param_2 == (undefined *)0x1a00) {
    return 1;
  }
  if (param_2 < (undefined *)0x1a01) {
    if (((unsigned char *)0x00001403) < param_2) {
      if (param_2 < ((unsigned char *)0x00001407)) {
        if (param_1 == 0x1909) {
          return 4;
        }
        if (param_1 < 0x190a) {
          if (0x18ff < param_1) {
            if (param_1 < 0x1907) {
              return 4;
            }
            if (param_1 == 0x1907) {
              return 0xc;
            }
          }
          return 0x10;
        }
        if (param_1 == 0x8049) {
          return 4;
        }
        if (param_1 < 0x804a) {
          if (param_1 == 0x190a) {
            return 8;
          }
          return 0x10;
        }
        if (param_1 == 0x80e0) {
          return 0xc;
        }
        if (param_1 == 0x85b9) {
          return 8;
        }
        return 0x10;
      }
      if (param_2 != ((unsigned char *)0x0000140b)) {
        return 4;
      }
    }
    else if (param_2 < ((unsigned char *)0x00001402)) {
      if (param_2 == (undefined *)0x0) {
        if (1 < param_1 - 0x83f0) {
          return 0x10;
        }
        return 8;
      }
      if (param_2 <= ((unsigned char *)0x000013ff)) {
        return 4;
      }
      if (param_1 == 0x1909) {
        return 1;
      }
      if (param_1 < 0x190a) {
        if (param_1 < 0x1900) {
          return 4;
        }
        if (0x1906 < param_1) {
          if (param_1 != 0x1907) {
            return 4;
          }
          return 3;
        }
        return 1;
      }
      if (param_1 == 0x8049) {
        return 1;
      }
      if (param_1 < 0x804a) {
        if (param_1 == 0x190a) {
          return 2;
        }
        return 4;
      }
      if (param_1 == 0x80e0) {
        return 3;
      }
      if (param_1 == 0x85b9) {
        return 2;
      }
      return 4;
    }
    if (param_1 != 0x1909) {
      if (param_1 < 0x190a) {
        if (0x18ff < param_1) {
          if (param_1 < 0x1907) {
            return 2;
          }
          if (param_1 == 0x1907) {
            return 6;
          }
        }
        return 8;
      }
      if (param_1 != 0x8049) {
        if (param_1 < 0x804a) {
          if (param_1 != 0x190a) {
            return 8;
          }
        }
        else {
          if (param_1 == 0x80e0) {
            return 6;
          }
          if (param_1 != 0x85b9) {
            return 8;
          }
        }
        return 4;
      }
    }
  }
  else {
    if (param_2 == (undefined *)0x8362) {
      return 1;
    }
    if (param_2 < (undefined *)0x8363) {
      if (param_2 == (undefined *)0x8032) {
        return 1;
      }
      if (param_2 < (undefined *)0x8032) {
        return 4;
      }
      if ((undefined *)0x8034 < param_2) {
        return 4;
      }
    }
    else if (((undefined *)0x8366 < param_2) && ((undefined *)0x1 < param_2 + -0x85ba)) {
      return 4;
    }
  }
  return 2;
}

/* FUN_0000a670 @ 0xa670 (100 bytes) */
int FUN_0000a670(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = ((int (*)())FUN_0000a3f0)();
    iVar1 = iVar1 * (param_3 + 3 >> 2) >> 2;
  }
  else if (param_2 == 0x1a00) {
    iVar1 = param_3 + 7 >> 3;
  }
  else {
    iVar1 = ((int (*)())FUN_0000a3f0)();
    iVar1 = iVar1 * param_3;
  }
  return iVar1;
}

/* FUN_0000a6e0 @ 0xa6e0 (292 bytes) */
int FUN_0000a6e0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  uint *param_6;
  int *param_7;
  int *param_8;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *in_stack_00000038;
  
  iVar2 = ((int (*)())FUN_0000a3f0)(param_2,param_3);
  *param_7 = iVar2;
  if (in_stack_00000038 == (int *)0x0) {
    *param_8 = 0;
    uVar3 = ((int (*)())FUN_0000a670)(param_2,param_3,param_4);
    *param_6 = uVar3;
  }
  else {
    iVar4 = *in_stack_00000038;
    if (iVar4 < 1) {
      uVar3 = ((int (*)())FUN_0000a670)(param_2,param_3,param_4);
    }
    else if (param_3 == 0x1a00) {
      uVar3 = iVar4 + 7 >> 3;
    }
    else {
      uVar3 = iVar2 * iVar4;
    }
    uVar1 = in_stack_00000038[5];
    iVar4 = uVar3 - (uVar3 / uVar1) * uVar1;
    if (iVar4 != 0) {
      uVar3 = uVar3 + (uVar1 - iVar4);
    }
    *param_6 = uVar3;
    iVar4 = in_stack_00000038[1];
    if (in_stack_00000038[1] < 1) {
      iVar4 = param_5;
    }
    if (param_3 == 0x1a00) {
      iVar2 = in_stack_00000038[3] >> 3;
    }
    else {
      iVar2 = iVar2 * in_stack_00000038[3];
    }
    *param_8 = iVar2 + uVar3 * in_stack_00000038[2] + uVar3 * iVar4 * in_stack_00000038[4];
  }
  return;
}

/* FUN_0000a820 @ 0xa820 (452 bytes) */
int FUN_0000a820(param_1, param_2)
  int param_1;
  uint param_2;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar6 = *(int *)(param_1 + 0x18);
  piVar5 = *(int **)(iVar6 + 0x19c);
  if ((piVar5 == (int *)0x0) &&
     (((((unsigned char *)0x0000430c)[*(int *)(param_1 + 0x10)] == '\0' ||
       (*(undefined4 **)(iVar6 + 400) == (undefined4 *)0x0)) ||
      (*(short *)**(undefined4 **)(iVar6 + 400) != -0x77fc)))) {
    uVar7 = 0;
    uVar8 = 0;
    bVar2 = true;
  }
  else {
    bVar2 = false;
    if (piVar5 == (int *)0x0) {
      param_2 = 0xffffffff;
      uVar7 = *(uint *)(**(int **)(iVar6 + 400) + 8);
      uVar8 = *(uint *)(**(int **)(iVar6 + 400) + 0xc);
    }
    else {
      param_2 = 0xffffffff;
      uVar7 = *(uint *)(*piVar5 + 8);
      uVar8 = *(uint *)(*piVar5 + 0xc);
    }
  }
  iVar11 = 0;
  iVar9 = 0;
  iVar10 = 0;
  iVar6 = param_1;
  do {
    if ((param_2 & 1) != 0) {
      if (bVar2) {
        uVar3 = 0;
        iVar12 = 5;
        do {
          if ((*(uint *)(((unsigned char *)0x000031d4) + iVar10 + *(int *)(param_1 + 0x10)) & 1 << (uVar3 & 0x3f))
              != 0) goto LAB_0000a96c;
          uVar3 = uVar3 + 1;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
LAB_0000a924:
        iVar12 = 0;
      }
      else {
        uVar3 = iVar11 * 4 - 0x20;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar7 << 1) << (iVar11 * -4 + 0x1fU & 0x3f) | uVar8 >> (iVar11 * 4 & 0x3cU);
        }
        else {
          uVar3 = uVar7 >> (uVar3 & 0x3f);
        }
        uVar3 = uVar3 & 0xf;
        if (4 < uVar3) goto LAB_0000a924;
LAB_0000a96c:
        iVar12 = *(int *)(iVar9 + *(int *)(param_1 + 0x18) + uVar3 * 4);
        if ((*(short *)(*(int *)(iVar12 + 0x30) + 0x5c) == 0) ||
           (((*(byte *)(iVar12 + 0x39) & 0x87) != 0 &&
            (iVar4 = FUN_00032100(param_1,iVar12), iVar4 == 0)))) goto LAB_0000a924;
      }
      *(int *)(iVar6 + 0x18c) = iVar12;
    }
    bVar1 = iVar11 == 0xf;
    iVar10 = iVar10 + 0x7c;
    iVar9 = iVar9 + 0x14;
    param_2 = param_2 >> 1;
    iVar6 = iVar6 + 4;
    iVar11 = iVar11 + 1;
    if (bVar1) {
      return;
    }
  } while( true );
}

/* FUN_0000a9f0 @ 0xa9f0 (244 bytes) */
int FUN_0000a9f0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar3 = *(int *)(param_2 + 0x30);
  iVar6 = 0xc;
  uVar1 = (uint)*(byte *)(iVar3 + 0xaa);
  uVar5 = (uint)*(ushort *)(iVar3 + 0xa4) + uVar1 * -2;
  uVar4 = (uint)*(ushort *)(iVar3 + 0xa6) - uVar1 * *(byte *)(iVar3 + 0x6e);
  uVar1 = (uint)*(ushort *)(iVar3 + 0xa8) - uVar1 * *(byte *)(iVar3 + 0x6f);
  iVar2 = uVar1 * uVar5 * uVar4;
  do {
    if ((((uVar5 == 1) && (uVar4 == 1)) && (uVar1 == 1)) || (*(ushort *)(iVar3 + 0x5c) < 0x2602))
    break;
    uVar5 = uVar5 >> 1;
    if (uVar5 == 0) {
      uVar5 = 1;
    }
    uVar4 = uVar4 >> 1;
    if (uVar4 == 0) {
      uVar4 = 1;
    }
    uVar1 = uVar1 >> 1;
    if (uVar1 == 0) {
      uVar1 = 1;
    }
    iVar2 = iVar2 + uVar1 * uVar5 * uVar4;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  uVar5 = (uint)*(byte *)(iVar3 + 0x6c) * iVar2;
  iVar2 = FUN_00030f00();
  if (iVar2 < 0) {
    uVar5 = uVar5 / (uint)-iVar2;
  }
  else {
    uVar5 = uVar5 * iVar2;
  }
  return uVar5;
}

/* FUN_0000aaf0 @ 0xaaf0 (244 bytes) */
int FUN_0000aaf0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0x34);
  if (iVar3 != 0) {
    if (*(char *)(iVar3 + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(iVar3 + 0x10)) {
        _gldFlush();
      }
      iVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar3 + 8));
      if (iVar1 == 0) {
        uVar2 = *(undefined4 *)(param_1 + 4);
        iVar3 = iVar3 + 8;
LAB_0000abac:
        _io_connect_method_scalarI_structureI(uVar2,9,iVar3,1,0,0);
        return;
      }
    }
    else if (*(char *)(iVar3 + 0x16) == '\a') {
      if (0x1ffff < *(int *)(iVar3 + 0x10)) {
        _gldFlush();
      }
      iVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar3 + 0xc));
      if (iVar1 == 0) {
        uVar2 = *(undefined4 *)(param_1 + 4);
        iVar3 = iVar3 + 0xc;
        goto LAB_0000abac;
      }
    }
  }
  return;
}

/* FUN_0000abf0 @ 0xabf0 (184 bytes) */
int FUN_0000abf0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x34);
  if (iVar2 != 0) {
    if (*(char *)(iVar2 + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(iVar2 + 0x10)) {
        _gldFlush();
      }
      uVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar2 + 8));
      return uVar1;
    }
    if (*(char *)(iVar2 + 0x16) == '\a') {
      if (0x1ffff < *(int *)(iVar2 + 0x10)) {
        _gldFlush();
      }
      uVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar2 + 0xc));
      return uVar1;
    }
  }
  return 1;
}

/* FUN_0000acb0 @ 0xacb0 (568 bytes) */
int FUN_0000acb0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  ushort *puVar2;
  ushort *puVar3;
  ushort *puVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  
  iVar10 = param_2[0xd];
  if ((((iVar10 == 0) || (*(char *)(iVar10 + 0x16) != '\x03')) || (param_3 != param_2[2])) ||
     (param_4 != param_2[3])) {
LAB_0000adc0:
    *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) | 1;
    if (iVar10 != 0) {
      piVar5 = (int *)(iVar10 + 0x10);
      do {
        iVar9 = *piVar5;
        if (in_RESERVE != '\0') {
          iVar7 = storeWordConditionalIndexed(iVar9 + -0x10000,0,piVar5);
          *piVar5 = iVar7;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar9 == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar10,1,0,0);
      }
      param_2[0xd] = 0;
    }
    param_2[2] = param_3;
    param_2[3] = param_4;
    param_2[1] = 3;
    local_38 = 8;
    iVar10 = _io_connect_method_structureI_structureO
                       (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,&local_34,&local_38);
    uVar8 = 0;
    if (iVar10 == 0) {
      param_2[0xd] = local_30;
      piVar5 = (int *)(local_30 + 0x10);
      do {
        if (in_RESERVE != '\0') {
          iVar10 = storeWordConditionalIndexed(*piVar5 + 0x10000,0,piVar5);
          *piVar5 = iVar10;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      uVar8 = 1;
      *param_2 = local_34;
      *(undefined1 *)(local_30 + 0x14) = 1;
    }
  }
  else {
    iVar9 = param_2[0xc];
    if (0x1ffff < *(int *)(iVar10 + 0x10)) {
      _gldFlush();
    }
    uVar6 = (uint)*(byte *)(iVar9 + 0x6c);
    if (uVar6 == 0) {
LAB_0000ad38:
      iVar9 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar10 + 0xc));
      if (iVar9 == 0) goto LAB_0000adc0;
    }
    else {
      if ((ushort)((*(ushort *)(iVar10 + 0x1c) | *(ushort *)(iVar10 + 0x28)) &
                  ~*(ushort *)(iVar9 + 0x7c)) == 0) {
        in_cr0 = 2;
        iVar7 = iVar10;
        if (uVar6 == 0) {
          uVar6 = 1;
        }
        do {
          uVar6 = uVar6 - 1;
          if (uVar6 == 0) goto LAB_0000ad38;
          puVar2 = (ushort *)(iVar7 + 0x2a);
          puVar3 = (ushort *)(iVar7 + 0x1e);
          iVar7 = iVar7 + 2;
          puVar4 = (ushort *)(iVar9 + 0x7e);
          iVar9 = iVar9 + 2;
          bVar1 = (ushort)((*puVar3 | *puVar2) & ~*puVar4) == 0;
          in_cr0 = bVar1 << 1;
        } while (bVar1);
      }
      iVar9 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar10 + 0xc));
      if (iVar9 == 0) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,iVar10 + 0xc,1,0,0);
      }
    }
    uVar8 = 1;
    *(undefined1 *)(iVar10 + 0x14) = 1;
  }
  return uVar8;
}

/* FUN_0000b150 @ 0xb150 (280 bytes) */
int FUN_0000b150(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_38;
  undefined1 auStack_34 [4];
  int local_30;
  
  uVar4 = 0;
  param_2[2] = param_3;
  param_2[3] = param_4;
  param_2[1] = 6;
  param_2[4] = param_5;
  *param_2 = 0;
  iVar5 = param_2[0xd];
  param_2[0xd] = 0;
  local_38 = 8;
  iVar3 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,auStack_34,&local_38);
  if (iVar3 == 0) {
    param_2[0xd] = local_30;
    piVar2 = (int *)(local_30 + 0x10);
    do {
      if (in_RESERVE != '\0') {
        iVar3 = storeWordConditionalIndexed(*piVar2 + 0x10000,0,piVar2);
        *piVar2 = iVar3;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    uVar4 = 1;
    *(undefined1 *)(local_30 + 0x14) = 1;
    if (iVar5 != local_30) {
      *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) | 1;
    }
  }
  if (iVar5 != 0) {
    piVar2 = (int *)(iVar5 + 0x10);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -0x10000,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar5,1,0,0);
    }
  }
  return uVar4;
}

/* FUN_0000b270 @ 0xb270 (296 bytes) */
int FUN_0000b270(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  
  uVar4 = 0;
  param_2[2] = param_3;
  param_2[3] = param_4;
  param_2[1] = 7;
  param_2[4] = param_5;
  param_2[5] = param_6;
  *param_2 = 0;
  iVar5 = param_2[0xd];
  param_2[0xd] = 0;
  local_38 = 8;
  iVar3 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,&local_34,&local_38);
  if (iVar3 == 0) {
    param_2[0xd] = local_30;
    piVar2 = (int *)(local_30 + 0x10);
    do {
      if (in_RESERVE != '\0') {
        iVar3 = storeWordConditionalIndexed(*piVar2 + 0x10000,0,piVar2);
        *piVar2 = iVar3;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    uVar4 = 1;
    *(byte *)(local_30 + 0x14) = *(byte *)(local_30 + 0x14) | 1;
    *param_2 = local_34;
    if (iVar5 != local_30) {
      *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) | 1;
    }
  }
  if (iVar5 != 0) {
    piVar2 = (int *)(iVar5 + 0x10);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -0x10000,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar5,1,0,0);
    }
  }
  return uVar4;
}

/* FUN_0000b3a0 @ 0xb3a0 (332 bytes) */
int FUN_0000b3a0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_38;
  undefined1 auStack_34 [4];
  int local_30;
  
  iVar4 = param_2[0xd];
  if ((((iVar4 == 0) || (*(char *)(iVar4 + 0x16) != '\0')) || (param_3 != param_2[2])) ||
     ((param_4 != param_2[3] || (uVar2 = 1, param_5 != param_2[4])))) {
    *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) | 1;
    if (iVar4 != 0) {
      piVar3 = (int *)(iVar4 + 0x10);
      do {
        iVar5 = *piVar3;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar5 + -0x10000,0,piVar3);
          *piVar3 = iVar1;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar5 == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar4,1,0,0);
      }
      param_2[0xd] = 0;
    }
    param_2[2] = param_3;
    param_2[3] = param_4;
    param_2[4] = param_5;
    param_2[1] = 0;
    local_38 = 8;
    iVar4 = _io_connect_method_structureI_structureO
                      (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,auStack_34,&local_38);
    uVar2 = 0;
    if (iVar4 == 0) {
      param_2[0xd] = local_30;
      piVar3 = (int *)(local_30 + 0x10);
      if (in_RESERVE != '\0') {
        iVar4 = storeWordConditionalIndexed(*piVar3 + 0x10000,0,piVar3);
        *piVar3 = iVar4;
      }
      *param_2 = 0;
      uVar2 = 1;
    }
  }
  return uVar2;
}

/* FUN_0000b4f0 @ 0xb4f0 (292 bytes) */
int FUN_0000b4f0(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  int param_3;
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_28;
  undefined1 auStack_24 [4];
  int local_20;
  
  iVar4 = param_2[0xd];
  if (((iVar4 == 0) || (*(char *)(iVar4 + 0x16) != '\x01')) || (uVar2 = 1, param_3 != param_2[2])) {
    *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) | 1;
    if (iVar4 != 0) {
      piVar3 = (int *)(iVar4 + 0x10);
      do {
        iVar5 = *piVar3;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar5 + -0x10000,0,piVar3);
          *piVar3 = iVar1;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar5 == 0x10000) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar4,1,0,0);
      }
      param_2[0xd] = 0;
    }
    param_2[2] = param_3;
    param_2[1] = 1;
    local_28 = 8;
    iVar4 = _io_connect_method_structureI_structureO
                      (*(undefined4 *)(param_1 + 4),10,param_2 + 1,0x14,auStack_24,&local_28);
    uVar2 = 0;
    if (iVar4 == 0) {
      param_2[0xd] = local_20;
      piVar3 = (int *)(local_20 + 0x10);
      if (in_RESERVE != '\0') {
        iVar4 = storeWordConditionalIndexed(*piVar3 + 0x10000,0,piVar3);
        *piVar3 = iVar4;
      }
      *param_2 = 0;
      uVar2 = 1;
    }
  }
  return uVar2;
}

/* FUN_0000b620 @ 0xb620 (72 bytes) */
int FUN_0000b620(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)*(byte *)(param_1 + 8);
  iVar1 = 0;
  iVar2 = (param_2 & uVar3 - 1) + (param_3 - uVar3);
  if (0 < iVar2) {
    do {
      dataCacheBlockStore((-uVar3 & param_2) + iVar1);
      iVar1 = iVar1 + uVar3;
    } while (iVar1 < iVar2);
  }
  dataCacheBlockFlush((-uVar3 & param_2) + iVar1);
  return;
}

/* FUN_0000b670 @ 0xb670 (80 bytes) */
int FUN_0000b670(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)*(byte *)(param_1 + 8);
  iVar1 = 0;
  iVar2 = ((param_2 & uVar3 - 1) + param_3) - uVar3;
  if (0 < iVar2) {
    do {
      dataCacheBlockFlush((-uVar3 & param_2) + iVar1);
      iVar1 = iVar1 + uVar3;
    } while (iVar1 < iVar2);
  }
  dataCacheBlockFlush((-uVar3 & param_2) + iVar1);
  sync(0);
  instructionSynchronize();
  return;
}

/* _gldCreateVertexArray @ 0xb6c0 (80 bytes) */
int _gldCreateVertexArray(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  
  puVar1 = _calloc(1,0x244);
  *param_2 = puVar1;
  *puVar1 = param_3;
  puVar1[1] = param_4;
  return 0;
}

/* _gldFlushVertexArray @ 0xb710 (56 bytes) */
int _gldFlushVertexArray(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  if (param_5 != 0) {
    ((int (*)())FUN_0000b620)(param_1,param_4);
  }
  return param_5 != 0;
}

/* FUN_0000b750 @ 0xb750 (276 bytes) */
int FUN_0000b750(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)(param_1 + 0x1d4);
  piVar3 = *(int **)(*(int *)(param_1 + 0x18) + 0x194);
  iVar1 = *piVar3;
  if ((*(uint *)(iVar1 + 0x308) & *(uint *)(iVar1 + 0x300)) == 0 &&
      (*(uint *)(iVar1 + 0x30c) & *(uint *)(iVar1 + 0x304)) == 0) {
    if ((((unsigned char *)0x000042fc)[*(int *)(param_1 + 0x10)] != '\0') ||
       (*(short *)(iVar1 + 0x312) != -0x7a4c)) {
      if (*(int *)(piVar3[1] + 0x84) == 0 && *(int *)(piVar3[1] + 0x88) == 0) goto LAB_0000b830;
      iVar1 = FUN_0001dc10(param_1,piVar3);
      goto joined_r0x0000b814;
    }
  }
  else {
    if (*(int *)(piVar3[1] + 0x84) == 0 && *(int *)(piVar3[1] + 0x88) == 0) goto LAB_0000b830;
    iVar1 = FUN_0001e730(param_1,piVar3);
joined_r0x0000b814:
    if (iVar1 != 0) goto LAB_0000b830;
  }
  piVar3 = (int *)0x0;
LAB_0000b830:
  *(int **)(param_1 + 0x1d4) = piVar3;
  if ((iVar2 != 0) && (piVar3 == (int *)0x0)) {
    FUN_0001dff0(param_1);
    return;
  }
  return;
}

/* FUN_0000b880 @ 0xb880 (244 bytes) */
int FUN_0000b880(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_2 + 0x228);
  if (iVar3 != 0) {
    if (*(char *)(iVar3 + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(iVar3 + 0x10)) {
        _gldFlush();
      }
      iVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar3 + 8));
      if (iVar1 == 0) {
        uVar2 = *(undefined4 *)(param_1 + 4);
        iVar3 = iVar3 + 8;
LAB_0000b93c:
        _io_connect_method_scalarI_structureI(uVar2,9,iVar3,1,0,0);
        return;
      }
    }
    else if (*(char *)(iVar3 + 0x16) == '\a') {
      if (0x1ffff < *(int *)(iVar3 + 0x10)) {
        _gldFlush();
      }
      iVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar3 + 0xc));
      if (iVar1 == 0) {
        uVar2 = *(undefined4 *)(param_1 + 4);
        iVar3 = iVar3 + 0xc;
        goto LAB_0000b93c;
      }
    }
  }
  return;
}

/* FUN_0000b980 @ 0xb980 (184 bytes) */
int FUN_0000b980(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 0x228);
  if (iVar2 != 0) {
    if (*(char *)(iVar2 + 0x16) == '\x06') {
      if (0x1ffff < *(int *)(iVar2 + 0x10)) {
        _gldFlush();
      }
      uVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar2 + 8));
      return uVar1;
    }
    if (*(char *)(iVar2 + 0x16) == '\a') {
      if (0x1ffff < *(int *)(iVar2 + 0x10)) {
        _gldFlush();
      }
      uVar1 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar2 + 0xc));
      return uVar1;
    }
  }
  return 1;
}

/* _gldModifyVertexArray @ 0xba40 (248 bytes) */
int _gldModifyVertexArray(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  char in_RESERVE;
  
  _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
  iVar5 = param_2[0x8a];
  if (iVar5 != 0) {
    bVar1 = ((*(uint *)(param_2[1] + 0x88) ^ 1) & 1) == 0;
    if (!bVar1) {
      if (*(short *)(*param_2 + 0x312) == -0x7a42) {
        uVar3 = param_2[0x8c] ^ 7;
      }
      else {
        uVar3 = param_2[0x8c] ^ 6;
      }
      if (uVar3 == 0) goto LAB_0000bb18;
    }
    piVar4 = (int *)(iVar5 + 0x10);
    do {
      iVar6 = *piVar4;
      if (in_RESERVE != '\0') {
        iVar2 = storeWordConditionalIndexed(iVar6 + -0x10000,0,piVar4);
        *piVar4 = iVar2;
        bVar1 = true;
      }
    } while (!bVar1);
    if (iVar6 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar5,1,0,0);
    }
    param_2[0x8a] = 0;
  }
LAB_0000bb18:
  _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
  return 0;
}

/* _gldReclaimVertexArray @ 0xbb40 (220 bytes) */
int _gldReclaimVertexArray(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  
  if (*(int *)(param_1 + 0x1d4) == param_2) {
    *(undefined4 *)(param_1 + 0x1d4) = 0;
    FUN_0001dff0();
  }
  iVar4 = *(int *)(param_2 + 0x228);
  if (iVar4 != 0) {
    if ((0x1ffff < (int)*(uint *)(iVar4 + 0x10)) || ((*(uint *)(iVar4 + 0x10) & 0xffff) != 0)) {
      _gldFlush(param_1);
    }
    ((int (*)())FUN_0000b880)(param_1,param_2);
    piVar2 = (int *)(iVar4 + 0x10);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -0x10000,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar4,1,0,0);
    }
    *(undefined4 *)(param_2 + 0x228) = 0;
  }
  return;
}

/* _gldDestroyVertexArray @ 0xbc20 (56 bytes) */
int _gldDestroyVertexArray(param_1, param_2)
  undefined4 param_1;
  void *param_2;
{
  ((int (*)())_gldReclaimVertexArray)();
  _free(param_2);
  return 0;
}

/* FUN_0000bc60 @ 0xbc60 (248 bytes) */
int FUN_0000bc60(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_38;
  undefined1 auStack_34 [4];
  int local_30;
  
  uVar4 = 0;
  *(undefined4 *)(param_2 + 0x234) = param_3;
  *(undefined4 *)(param_2 + 0x238) = param_4;
  *(undefined4 *)(param_2 + 0x230) = 6;
  *(undefined4 *)(param_2 + 0x23c) = param_5;
  *(undefined4 *)(param_2 + 0x22c) = 0;
  iVar5 = *(int *)(param_2 + 0x228);
  *(undefined4 *)(param_2 + 0x228) = 0;
  local_38 = 8;
  iVar3 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 0x230,0x14,auStack_34,&local_38);
  if (iVar3 == 0) {
    *(int *)(param_2 + 0x228) = local_30;
    piVar2 = (int *)(local_30 + 0x10);
    do {
      if (in_RESERVE != '\0') {
        iVar3 = storeWordConditionalIndexed(*piVar2 + 0x10000,0,piVar2);
        *piVar2 = iVar3;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    uVar4 = 1;
    *(undefined1 *)(local_30 + 0x14) = 1;
  }
  if (iVar5 != 0) {
    piVar2 = (int *)(iVar5 + 0x10);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -0x10000,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar5,1,0,0);
    }
  }
  return uVar4;
}

/* FUN_0000bd60 @ 0xbd60 (264 bytes) */
int FUN_0000bd60(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  
  uVar4 = 0;
  *(undefined4 *)(param_2 + 0x234) = param_3;
  *(undefined4 *)(param_2 + 0x238) = param_4;
  *(undefined4 *)(param_2 + 0x230) = 7;
  *(undefined4 *)(param_2 + 0x23c) = param_5;
  *(undefined4 *)(param_2 + 0x240) = param_6;
  *(undefined4 *)(param_2 + 0x22c) = 0;
  iVar5 = *(int *)(param_2 + 0x228);
  *(undefined4 *)(param_2 + 0x228) = 0;
  local_38 = 8;
  iVar3 = _io_connect_method_structureI_structureO
                    (*(undefined4 *)(param_1 + 4),10,param_2 + 0x230,0x14,&local_34,&local_38);
  if (iVar3 == 0) {
    *(int *)(param_2 + 0x228) = local_30;
    piVar2 = (int *)(local_30 + 0x10);
    do {
      if (in_RESERVE != '\0') {
        iVar3 = storeWordConditionalIndexed(*piVar2 + 0x10000,0,piVar2);
        *piVar2 = iVar3;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    uVar4 = 1;
    *(undefined1 *)(local_30 + 0x14) = 1;
    *(undefined4 *)(param_2 + 0x22c) = local_34;
  }
  if (iVar5 != 0) {
    piVar2 = (int *)(iVar5 + 0x10);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -0x10000,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 == 0x10000) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xb,iVar5,1,0,0);
    }
  }
  return uVar4;
}

/* FUN_0000be70 @ 0xbe70 (272 bytes) */
double FUN_0000be70(int param_1)

{
  int iVar1;
  double dVar2;
  
  if (0 < param_1) {
    dVar2 = DOUBLE_001aa200;
    if (0x20 < param_1) {
      iVar1 = (param_1 - 0x21U >> 5) + 1;
      if (param_1 + -0x20 < 1) {
        iVar1 = 1;
      }
      do {
        dVar2 = dVar2 * DOUBLE_001aa1f8;
        param_1 = param_1 + -0x20;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    return dVar2 * *(double *)(&DAT_001aa3a8 + param_1 * 8);
  }
  if (-1 < param_1) {
    return DOUBLE_001aa200;
  }
  dVar2 = DOUBLE_001aa200;
  if (param_1 < -0x20) {
    iVar1 = (~(param_1 + 0x20U) >> 5) + 1;
    if (-1 < (int)(param_1 + 0x20U)) {
      iVar1 = 1;
    }
    do {
      dVar2 = dVar2 * DOUBLE_001aa1f0;
      param_1 = param_1 + 0x20;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return dVar2 * (DOUBLE_001aa2a8)[-param_1];
}

/* FUN_0000bfa0 @ 0xbfa0 (1332 bytes) */
char * FUN_0000bfa0(undefined8 param_1,double param_2,undefined4 param_3,undefined4 param_4,
                   char *param_5,uint param_6)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_r4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  double dVar9;
  double extraout_f1;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  uint local_78 [4];
  undefined4 local_68;
  uint uStack_64;
  longlong local_60;
  longlong local_58;
  longlong local_50;
  
  pcVar6 = param_5 + param_6;
  uVar4 = FUN_001a3264();
  if (param_2 <= DOUBLE_001aa228) {
    param_2 = DOUBLE_001aa208;
  }
  if (param_6 < 2) {
    return (char *)0x0;
  }
  pcVar7 = param_5;
  dVar12 = extraout_f1;
  if (extraout_f1 < DOUBLE_001aa228) {
    dVar12 = -extraout_f1;
    pcVar7 = param_5 + 1;
    *param_5 = '-';
  }
  dVar10 = dVar12;
  if (dVar12 <= DOUBLE_001aa228) {
    local_78[0] = 0;
    dVar11 = param_2 * DOUBLE_001aa240;
  }
  else {
    if ((dVar12 < DOUBLE_001aa210) || (DOUBLE_001aa230 < dVar12)) {
      _frexp(dVar12,uVar4,extraout_r4,local_78);
      local_68 = 0x43300000;
      uStack_64 = local_78[0] ^ 0x80000000;
      dVar10 = (double)_round(((double)CONCAT44(0x43300000,uStack_64) - DOUBLE_001aa1e0) *
                              DOUBLE_001aa218);
      local_78[0] = (uint)dVar10;
      local_60 = (longlong)(int)local_78[0];
      dVar11 = (double)((double (*)())FUN_0000be70)(local_78[0]);
      dVar10 = (double)((double (*)())FUN_0000be70)(-local_78[0]);
      dVar10 = dVar12 * dVar10;
      dVar13 = param_2 * dVar11;
    }
    else {
      local_78[0] = 0;
      dVar13 = param_2;
    }
    dVar11 = param_2 * DOUBLE_001aa240;
    for (; dVar9 = dVar11 + dVar10, DOUBLE_001aa238 <= dVar9; dVar10 = dVar10 * DOUBLE_001aa220) {
      local_78[0] = local_78[0] + 1;
      dVar13 = dVar13 * DOUBLE_001aa238;
    }
    while (dVar9 < DOUBLE_001aa200) {
      dVar10 = dVar10 * DOUBLE_001aa238;
      local_78[0] = local_78[0] - 1;
      dVar13 = dVar13 * DOUBLE_001aa220;
      dVar9 = dVar11 + dVar10;
    }
    if ((int)(((int)local_78[0] >> 0x1f ^ local_78[0]) - ((int)local_78[0] >> 0x1f)) < 4) {
      local_78[0] = 0;
      dVar11 = dVar13 * DOUBLE_001aa240;
      param_2 = dVar13;
      dVar10 = dVar12;
    }
  }
  dVar13 = (double)_floor(dVar10 + dVar11);
  pcVar8 = pcVar7;
  dVar12 = dVar13;
  if (dVar13 <= param_2) {
LAB_0000c240:
    *pcVar8 = '0';
    pcVar8 = pcVar8 + 1;
  }
  else {
    do {
      if (pcVar8 == pcVar6) {
        return (char *)0x0;
      }
      dVar9 = dVar12 * DOUBLE_001aa220;
      dVar12 = (double)_floor(dVar9);
      iVar3 = (int)((dVar9 - dVar12) * DOUBLE_001aa238);
      local_58 = (longlong)iVar3;
      *pcVar8 = (char)iVar3 + '0';
      pcVar8 = pcVar8 + 1;
    } while (param_2 < dVar12);
    if (pcVar8 <= pcVar7) goto LAB_0000c240;
    iVar3 = (int)pcVar8 - (int)pcVar7;
    if (1 < iVar3) {
      iVar2 = ((uint)(pcVar7 + (iVar3 * 2 - (int)pcVar8) + -2) >> 1) + 1;
      pcVar5 = pcVar8;
      if ((int)(pcVar7 + (iVar3 * 2 - (int)pcVar8) + -2) < 0) {
        iVar2 = 1;
      }
      do {
        pcVar5 = pcVar5 + -1;
        cVar1 = *pcVar5;
        *pcVar5 = *pcVar7;
        *pcVar7 = cVar1;
        pcVar7 = pcVar7 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  dVar13 = (dVar10 + dVar11) - dVar13;
  if (dVar13 <= param_2) {
    if (local_78[0] == 0) {
      if ((int)pcVar6 - (int)pcVar8 < 2) {
        return (char *)0x0;
      }
      *pcVar8 = '.';
      pcVar8[1] = '0';
      pcVar8 = pcVar8 + 2;
      goto LAB_0000c31c;
    }
  }
  else {
    if (pcVar8 == pcVar6) {
      return (char *)0x0;
    }
    *pcVar8 = '.';
    dVar12 = DOUBLE_001aa238;
    pcVar8 = pcVar8 + 1;
    do {
      if (pcVar6 == pcVar8) {
        return (char *)0x0;
      }
      dVar13 = dVar13 * dVar12;
      param_2 = param_2 * dVar12;
      dVar10 = (double)_floor(dVar13);
      local_50 = (longlong)(int)dVar10;
      dVar13 = dVar13 - dVar10;
      *pcVar8 = (char)(int)dVar10 + '0';
      pcVar8 = pcVar8 + 1;
    } while (param_2 < dVar13);
LAB_0000c31c:
    if (local_78[0] == 0) goto LAB_0000c440;
  }
  if ((int)pcVar6 - (int)pcVar8 < 3) {
    return (char *)0x0;
  }
  pcVar7 = pcVar8 + 1;
  *pcVar8 = 'e';
  if ((int)local_78[0] < 0) {
    pcVar7 = pcVar8 + 2;
    pcVar8[1] = '-';
    local_78[0] = -local_78[0];
  }
  pcVar8 = pcVar7;
  if (0 < (int)local_78[0]) {
    if (pcVar7 == pcVar6) {
      return (char *)0x0;
    }
    iVar3 = (int)pcVar6 - (int)pcVar7;
    while( true ) {
      *pcVar8 = (char)local_78[0] + (char)((int)local_78[0] / 10) * -10 + '0';
      pcVar8 = pcVar8 + 1;
      local_78[0] = (int)local_78[0] / 10;
      if ((int)local_78[0] < 1) break;
      iVar3 = iVar3 + -1;
      if (iVar3 == 0) {
        return (char *)0x0;
      }
    }
    if (1 < (int)pcVar8 - (int)pcVar7) {
      iVar3 = ((uint)(pcVar7 + (((int)pcVar8 - (int)pcVar7) * 2 - (int)pcVar8) + -2) >> 1) + 1;
      pcVar5 = pcVar8;
      if ((int)(pcVar7 + (((int)pcVar8 - (int)pcVar7) * 2 - (int)pcVar8) + -2) < 0) {
        iVar3 = 1;
      }
      do {
        pcVar5 = pcVar5 + -1;
        cVar1 = *pcVar5;
        *pcVar5 = *pcVar7;
        *pcVar7 = cVar1;
        pcVar7 = pcVar7 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
LAB_0000c440:
  if (pcVar8 == pcVar6) {
    return (char *)0x0;
  }
  *pcVar8 = '\0';
  return pcVar8;
}

/* FUN_0000c8a0 @ 0xc8a0 (136 bytes) */
int FUN_0000c8a0(param_1, param_2, param_3)
  size_t *param_1;
  int *param_2;
  int *param_3;
{
  int iVar1;
  void *pvVar2;
  size_t sVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = *param_3;
  uVar5 = 1;
  iVar1 = *param_2;
  if ((int)(*param_1 - (iVar4 - iVar1)) < 0x100) {
    sVar3 = *param_1 + 0x800;
    *param_1 = sVar3;
    pvVar2 = _realloc((void *)*param_2,sVar3);
    uVar5 = 0;
    *param_3 = (int)pvVar2;
    if (pvVar2 != (void *)0x0) {
      *param_2 = (int)pvVar2;
      uVar5 = 1;
      *param_3 = (int)pvVar2 + (iVar4 - iVar1);
    }
  }
  return uVar5;
}

/* FUN_0000c930 @ 0xc930 (284 bytes) */
int FUN_0000c930(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  if (param_2 != 0) {
    iVar3 = 0;
    if (s_C_001a4428[0] != '\0') {
      pcVar2 = "C";
      iVar3 = 0;
      cVar1 = s_C_001a4428[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(param_1 + iVar3) = cVar1;
        iVar3 = iVar3 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    param_1 = param_1 + iVar3;
    if (0 < param_3) {
      iVar3 = 0;
      if (s_1_001a442c[0] != '\0') {
        pcVar2 = "1";
        cVar1 = s_1_001a442c[0];
        do {
          pcVar2 = pcVar2 + 1;
          *(char *)(param_1 + iVar3) = cVar1;
          iVar3 = iVar3 + 1;
          cVar1 = *pcVar2;
        } while (cVar1 != '\0');
      }
      param_1 = param_1 + iVar3;
    }
  }
  if (param_4 != 0) {
    iVar3 = 0;
    if (s__SAT_001a4430[0] != '\0') {
      pcVar2 = "_SAT";
      cVar1 = s__SAT_001a4430[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(param_1 + iVar3) = cVar1;
        iVar3 = iVar3 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    return param_1 + iVar3;
  }
  return param_1;
}

/* FUN_0000ca50 @ 0xca50 (312 bytes) */
int FUN_0000ca50(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  if (param_2 == 2) {
    iVar3 = 0;
    if (s_H_001a443c[0] != '\0') {
      pcVar2 = "H";
      iVar3 = 0;
      cVar1 = s_H_001a443c[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(param_1 + iVar3) = cVar1;
        iVar3 = iVar3 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
  }
  else {
    if (param_2 == 3) {
      iVar3 = 0;
      if (s_X_001a4440[0] != '\0') {
        pcVar2 = "X";
        iVar3 = 0;
        cVar1 = s_X_001a4440[0];
        do {
          pcVar2 = pcVar2 + 1;
          *(char *)(param_1 + iVar3) = cVar1;
          iVar3 = iVar3 + 1;
          cVar1 = *pcVar2;
        } while (cVar1 != '\0');
      }
      return param_1 + iVar3;
    }
    if (param_2 != 1) {
      return param_1;
    }
    iVar3 = 0;
    if (s_R_001a4438[0] != '\0') {
      pcVar2 = "R";
      iVar3 = 0;
      cVar1 = s_R_001a4438[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(param_1 + iVar3) = cVar1;
        iVar3 = iVar3 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
  }
  return param_1 + iVar3;
}

/* FUN_0000cb90 @ 0xcb90 (572 bytes) */
int FUN_0000cb90(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char *pcVar10;
  
  iVar1 = param_2 / 10;
  if (iVar1 == 0) {
    pcVar10 = (char *)*param_1;
  }
  else {
    iVar2 = iVar1 / 10;
    if (iVar2 == 0) {
      pcVar10 = (char *)*param_1;
    }
    else {
      iVar3 = iVar2 / 10;
      if (iVar3 == 0) {
        pcVar10 = (char *)*param_1;
      }
      else {
        iVar4 = iVar3 / 10;
        if (iVar4 == 0) {
          pcVar10 = (char *)*param_1;
        }
        else {
          iVar5 = iVar4 / 10;
          if (iVar5 == 0) {
            pcVar10 = (char *)*param_1;
          }
          else {
            iVar6 = iVar5 / 10;
            if (iVar6 == 0) {
              pcVar10 = (char *)*param_1;
            }
            else {
              iVar7 = iVar6 / 10;
              if (iVar7 == 0) {
                pcVar10 = (char *)*param_1;
              }
              else {
                iVar8 = iVar7 / 10;
                if (iVar8 == 0) {
                  pcVar10 = (char *)*param_1;
                }
                else {
                  iVar9 = iVar8 / 10;
                  if (iVar9 != 0) {
                    ((int (*)())FUN_0000cb90)(param_1,iVar9);
                  }
                  *(char *)*param_1 = (char)iVar8 + (char)iVar9 * -10 + '0';
                  pcVar10 = (char *)(*param_1 + 1);
                  *param_1 = (int)pcVar10;
                }
                *pcVar10 = (char)iVar7 + (char)iVar8 * -10 + '0';
                pcVar10 = (char *)(*param_1 + 1);
                *param_1 = (int)pcVar10;
              }
              *pcVar10 = (char)iVar6 + (char)iVar7 * -10 + '0';
              pcVar10 = (char *)(*param_1 + 1);
              *param_1 = (int)pcVar10;
            }
            *pcVar10 = (char)iVar5 + (char)iVar6 * -10 + '0';
            pcVar10 = (char *)(*param_1 + 1);
            *param_1 = (int)pcVar10;
          }
          *pcVar10 = (char)iVar4 + (char)iVar5 * -10 + '0';
          pcVar10 = (char *)(*param_1 + 1);
          *param_1 = (int)pcVar10;
        }
        *pcVar10 = (char)iVar3 + (char)iVar4 * -10 + '0';
        pcVar10 = (char *)(*param_1 + 1);
        *param_1 = (int)pcVar10;
      }
      *pcVar10 = (char)iVar2 + (char)iVar3 * -10 + '0';
      pcVar10 = (char *)(*param_1 + 1);
      *param_1 = (int)pcVar10;
    }
    *pcVar10 = (char)iVar1 + (char)iVar2 * -10 + '0';
    pcVar10 = (char *)(*param_1 + 1);
    *param_1 = (int)pcVar10;
  }
  *pcVar10 = (char)param_2 + (char)iVar1 * -10 + '0';
  *param_1 = *param_1 + 1;
  return;
}

/* FUN_0000cdf0 @ 0xcdf0 (156 bytes) */
int FUN_0000cdf0(param_1, param_2)
  char *param_1;
  int param_2;
{
  int iVar1;
  char *local_28 [6];
  
  local_28[0] = param_1;
  if (param_2 < 0) {
    local_28[0] = param_1 + 1;
    param_2 = -param_2;
    *param_1 = '-';
  }
  iVar1 = param_2 / 10;
  if (iVar1 != 0) {
    ((int (*)())FUN_0000cb90)(local_28,iVar1);
  }
  *local_28[0] = (char)param_2 + (char)iVar1 * -10 + '0';
  return local_28[0] + (1 - (int)param_1);
}

/* FUN_0000ce90 @ 0xce90 (924 bytes) */
int FUN_0000ce90(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  
  cVar7 = s___001a4444[0];
  bVar1 = s___001a4444[0] != '\0';
  if (bVar1) {
    pcVar3 = ":";
    iVar4 = 0;
    cVar2 = s___001a4444[0];
    do {
      pcVar3 = pcVar3 + 1;
      *(char *)(param_1 + iVar4) = cVar2;
      iVar4 = iVar4 + 1;
      cVar2 = *pcVar3;
    } while (cVar2 != '\0');
  }
  else {
    iVar4 = 0;
  }
  iVar5 = ((int (*)())FUN_0000cdf0)(param_1 + iVar4,param_2 + 1);
  iVar5 = param_1 + iVar4 + iVar5;
  if (param_3 == 1) {
    if (bVar1) {
      pcVar3 = ":";
      iVar4 = 0;
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
    else {
      iVar4 = 0;
    }
    iVar6 = ((int (*)())FUN_0000cdf0)(iVar5 + iVar4,param_2 + 1);
    iVar5 = iVar5 + iVar4 + iVar6;
  }
  if (param_4 == 2) {
    iVar4 = 0;
    if (s_X_001a4440[0] != '\0') {
      pcVar3 = "X";
      cVar7 = s_X_001a4440[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  else if (param_4 < 3) {
    if (param_4 != 1) goto LAB_0000d0e4;
    iVar4 = 0;
    if (s_F_001a4448[0] != '\0') {
      pcVar3 = "F";
      cVar7 = s_F_001a4448[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  else if (param_4 == 3) {
    iVar4 = 0;
    if (s_I_001a444c[0] != '\0') {
      pcVar3 = "I";
      cVar7 = s_I_001a444c[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  else {
    if (param_4 != 4) goto LAB_0000d0e4;
    iVar4 = 0;
    if (s_B_001a4450[0] != '\0') {
      pcVar3 = "B";
      cVar7 = s_B_001a4450[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  iVar5 = iVar5 + iVar4;
LAB_0000d0e4:
  if (param_5 == 2) {
    iVar4 = 0;
    if (s_16_001a4458[0] != '\0') {
      pcVar3 = "16";
      cVar7 = s_16_001a4458[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  else if (param_5 == 3) {
    iVar4 = 0;
    if (s_12_001a445c[0] != '\0') {
      pcVar3 = "12";
      cVar7 = s_12_001a445c[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  else {
    if (param_5 != 1) {
      return iVar5;
    }
    iVar4 = 0;
    if (s_32_001a4454[0] != '\0') {
      pcVar3 = "32";
      cVar7 = s_32_001a4454[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  return iVar5 + iVar4;
}

/* FUN_0000d240 @ 0xd240 (308 bytes) */
int FUN_0000d240(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  
  cVar6 = s___001a4444[0];
  if ((param_2 != 3) || (param_3 == 1)) {
    bVar1 = s___001a4444[0] != '\0';
    if (bVar1) {
      pcVar3 = ":";
      iVar4 = 0;
      cVar2 = s___001a4444[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(param_1 + iVar4) = cVar2;
        iVar4 = iVar4 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    else {
      iVar4 = 0;
    }
    iVar5 = ((int (*)())FUN_0000cdf0)(param_1 + iVar4,param_2 + 1);
    param_1 = param_1 + iVar4 + iVar5;
    if (param_3 == 1) {
      if (bVar1) {
        pcVar3 = ":";
        iVar4 = 0;
        do {
          pcVar3 = pcVar3 + 1;
          *(char *)(param_1 + iVar4) = cVar6;
          iVar4 = iVar4 + 1;
          cVar6 = *pcVar3;
        } while (cVar6 != '\0');
      }
      else {
        iVar4 = 0;
      }
      iVar5 = ((int (*)())FUN_0000cdf0)(param_1 + iVar4,param_2 + 1);
      param_1 = param_1 + iVar4 + iVar5;
    }
  }
  return param_1;
}

/* FUN_0000d380 @ 0xd380 (2976 bytes) */
int FUN_0000d380(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined1 *param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  uint uVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  
  puVar7 = (uint *)(param_5 * 8 + param_1);
  uVar1 = *(uint *)(param_5 * 8 + param_1) >> 0x11 & 7;
  if (uVar1 == 1) {
    iVar6 = 0;
    if (s_tmp_001a4460[0] != '\0') {
      pcVar3 = "tmp";
      iVar6 = 0;
      cVar2 = s_tmp_001a4460[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    param_2 = param_2 + iVar6;
    if ((param_6 == 0) || (param_3 == 0)) {
      iVar6 = ((int (*)())FUN_0000cdf0)(param_2,*(undefined2 *)((int)puVar7 + 6));
      param_2 = param_2 + iVar6;
      goto LAB_0000d5c0;
    }
    iVar6 = ((int (*)())FUN_0000cdf0)(param_2,*(undefined4 *)(param_3 + (uint)*(ushort *)((int)puVar7 + 6) * 4));
    param_2 = param_2 + iVar6;
    if (param_4 == 0) goto LAB_0000d5c4;
    uVar1 = puVar7[1];
    if (-1 < (int)uVar1) {
      uVar5 = (uint)*(ushort *)((int)puVar7 + 6);
      if (*(int *)(param_4 + uVar5 * 4) != -1) {
        iVar6 = 0;
        if (s___001a4464[0] != '\0') {
          pcVar3 = "[";
          iVar6 = 0;
          cVar2 = s___001a4464[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          uVar5 = (uint)*(ushort *)((int)puVar7 + 6);
        }
        param_2 = param_2 + iVar6;
        iVar6 = ((int (*)())FUN_0000cdf0)(param_2,*(undefined4 *)(param_4 + uVar5 * 4));
        iVar4 = 0;
        if (s___001a4468[0] != '\0') {
          pcVar3 = "]";
          iVar4 = 0;
          cVar2 = s___001a4468[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar4 + iVar6] = cVar2;
            iVar4 = iVar4 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        uVar1 = puVar7[1];
        param_2 = param_2 + iVar4 + iVar6;
      }
      goto LAB_0000d5c8;
    }
LAB_0000d5d0:
    iVar6 = 0;
    if (s__adr_001a4470[0] != '\0') {
      pcVar3 = "[adr";
      iVar6 = 0;
      cVar2 = s__adr_001a4470[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      uVar1 = puVar7[1];
    }
    iVar4 = ((int (*)())FUN_0000cdf0)(param_2 + iVar6,uVar1 >> 0x1e & 1);
    uVar5 = puVar7[1];
    param_2 = param_2 + iVar6 + iVar4;
    uVar1 = uVar5 >> 0x1c & 3;
    if (uVar1 == 1) {
      iVar6 = 0;
      if (s__y_001a447c[0] != '\0') {
        pcVar3 = ".y";
        cVar2 = s__y_001a447c[0];
        do {
          pcVar3 = pcVar3 + 1;
          param_2[iVar6] = cVar2;
          iVar6 = iVar6 + 1;
          cVar2 = *pcVar3;
        } while (cVar2 != '\0');
        goto LAB_0000d794;
      }
LAB_0000d798:
      param_2 = param_2 + iVar6;
    }
    else {
      if (1 < uVar1) {
        if (uVar1 == 2) {
          iVar6 = 0;
          if (s__z_001a4480[0] != '\0') {
            pcVar3 = ".z";
            cVar2 = s__z_001a4480[0];
            do {
              pcVar3 = pcVar3 + 1;
              param_2[iVar6] = cVar2;
              iVar6 = iVar6 + 1;
              cVar2 = *pcVar3;
            } while (cVar2 != '\0');
LAB_0000d794:
            uVar5 = puVar7[1];
          }
        }
        else {
          if (uVar1 != 3) goto LAB_0000d79c;
          iVar6 = 0;
          if (s__w_001a4484[0] != '\0') {
            pcVar3 = ".w";
            cVar2 = s__w_001a4484[0];
            do {
              pcVar3 = pcVar3 + 1;
              param_2[iVar6] = cVar2;
              iVar6 = iVar6 + 1;
              cVar2 = *pcVar3;
            } while (cVar2 != '\0');
            goto LAB_0000d794;
          }
        }
        goto LAB_0000d798;
      }
      if (uVar1 == 0) {
        iVar6 = 0;
        if (s__x_001a4478[0] != '\0') {
          pcVar3 = ".x";
          cVar2 = s__x_001a4478[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          goto LAB_0000d794;
        }
        goto LAB_0000d798;
      }
    }
LAB_0000d79c:
    if ((((*puVar7 & 0xe0000) != 0x20000) || (param_4 == 0)) ||
       (iVar6 = *(int *)(param_4 + (uint)*(ushort *)((int)puVar7 + 6) * 4), iVar6 == -1)) {
      iVar6 = 0;
    }
    iVar6 = iVar6 + ((int)(uVar5 << 4 | uVar5 >> 0x1c) >> 0x18);
    if (iVar6 != 0) {
      if (0 < iVar6) {
        iVar6 = 0;
        if (s___001a4488[0] != '\0') {
          pcVar3 = "+";
          cVar2 = s___001a4488[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        param_2 = param_2 + iVar6;
      }
      iVar6 = ((int (*)())FUN_0000cdf0)(param_2);
      param_2 = param_2 + iVar6;
    }
    iVar6 = 0;
    if (s___001a4468[0] != '\0') {
      pcVar3 = "]";
      iVar6 = 0;
      cVar2 = s___001a4468[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    param_2 = param_2 + iVar6;
LAB_0000d89c:
    iVar6 = 0;
    if (s___001a448c[0] != '\0') {
      pcVar3 = ".";
      iVar6 = 0;
      cVar2 = s___001a448c[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    if ((*puVar7 & 0x2000) == 0) {
      param_2[iVar6] = 0x5f;
    }
    else {
      param_2[iVar6] = (((byte)(*puVar7 >> 8) & 3) + 1 & 3) + 0x77;
    }
    pcVar3 = param_2 + iVar6 + 1;
    uVar1 = *puVar7;
    if ((uVar1 & 0xc00) != 0) {
      if ((uVar1 & 0x4000) == 0) {
        *pcVar3 = '_';
        pcVar3 = param_2 + iVar6 + 2;
        uVar1 = *puVar7;
      }
      else {
        *pcVar3 = (((byte)(uVar1 >> 6) & 3) + 1 & 3) + 0x77;
        pcVar3 = param_2 + iVar6 + 2;
        uVar1 = *puVar7;
      }
    }
    if (1 < (uVar1 >> 10 & 3)) {
      if ((uVar1 & 0x8000) == 0) {
        *pcVar3 = '_';
        pcVar3 = pcVar3 + 1;
        uVar1 = *puVar7;
      }
      else {
        *pcVar3 = (((byte)(uVar1 >> 4) & 3) + 1 & 3) + 0x77;
        pcVar3 = pcVar3 + 1;
        uVar1 = *puVar7;
      }
    }
    if (2 < (uVar1 >> 10 & 3)) {
      if ((uVar1 & 0x10000) == 0) {
        *pcVar3 = '_';
        pcVar3 = pcVar3 + 1;
        uVar1 = *puVar7;
      }
      else {
        *pcVar3 = (((byte)(uVar1 >> 2) & 3) + 1 & 3) + 0x77;
        pcVar3 = pcVar3 + 1;
        uVar1 = *puVar7;
      }
    }
    param_2 = (undefined1 *)((int (*)())FUN_0000d240)(pcVar3,uVar1 >> 10 & 3,uVar1 >> 0xc & 1);
    uVar1 = *puVar7;
  }
  else {
    if (uVar1 == 3) {
      iVar6 = 0;
      if (s_res_001a446c[0] != '\0') {
        pcVar3 = "res";
        iVar6 = 0;
        cVar2 = s_res_001a446c[0];
        do {
          pcVar3 = pcVar3 + 1;
          param_2[iVar6] = cVar2;
          iVar6 = iVar6 + 1;
          cVar2 = *pcVar3;
        } while (cVar2 != '\0');
      }
      iVar4 = ((int (*)())FUN_0000cdf0)(param_2 + iVar6,*(undefined2 *)((int)puVar7 + 6));
      param_2 = param_2 + iVar6 + iVar4;
    }
LAB_0000d5c0:
    if (param_6 != 0) {
LAB_0000d5c4:
      uVar1 = puVar7[1];
LAB_0000d5c8:
      if ((int)uVar1 < 0) goto LAB_0000d5d0;
      goto LAB_0000d89c;
    }
    uVar1 = *puVar7;
    if ((uVar1 & 0x1e000) != 0x1e000) {
      iVar6 = 0;
      if (s___001a448c[0] != '\0') {
        pcVar3 = ".";
        cVar2 = s___001a448c[0];
        do {
          pcVar3 = pcVar3 + 1;
          param_2[iVar6] = cVar2;
          iVar6 = iVar6 + 1;
          cVar2 = *pcVar3;
        } while (cVar2 != '\0');
        uVar1 = *puVar7;
      }
      param_2 = param_2 + iVar6;
      if ((uVar1 & 0x2000) != 0) {
        iVar6 = 0;
        if (s_x_001a4490[0] != '\0') {
          pcVar3 = "x";
          cVar2 = s_x_001a4490[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          uVar1 = *puVar7;
        }
        param_2 = param_2 + iVar6;
      }
      if ((uVar1 & 0x4000) != 0) {
        iVar6 = 0;
        if (s_y_001a4494[0] != '\0') {
          pcVar3 = "y";
          cVar2 = s_y_001a4494[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          uVar1 = *puVar7;
        }
        param_2 = param_2 + iVar6;
      }
      if ((uVar1 & 0x8000) != 0) {
        iVar6 = 0;
        if (s_z_001a4498[0] != '\0') {
          pcVar3 = "z";
          cVar2 = s_z_001a4498[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          uVar1 = *puVar7;
        }
        param_2 = param_2 + iVar6;
      }
      if ((uVar1 & 0x10000) != 0) {
        iVar6 = 0;
        if (s_w_001a449c[0] != '\0') {
          pcVar3 = "w";
          cVar2 = s_w_001a449c[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar6] = cVar2;
            iVar6 = iVar6 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          uVar1 = *puVar7;
        }
        param_2 = param_2 + iVar6;
      }
    }
  }
  if ((uVar1 & 0x70000000) == 0) {
    return param_2;
  }
  switch(uVar1 >> 0x1c & 7) {
  case 0:
    iVar6 = 0;
    if (s__TR_001a44a0[0] != '\0') {
      pcVar3 = " (TR";
      cVar2 = s__TR_001a44a0[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
LAB_0000de9c:
      uVar1 = *puVar7;
    }
    break;
  case 1:
    iVar6 = 0;
    if (s__EQ_001a44a8[0] != '\0') {
      pcVar3 = " (EQ";
      cVar2 = s__EQ_001a44a8[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      goto LAB_0000de9c;
    }
    break;
  case 2:
    iVar6 = 0;
    if (s__GE_001a44b0[0] != '\0') {
      pcVar3 = " (GE";
      cVar2 = s__GE_001a44b0[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      goto LAB_0000de9c;
    }
    break;
  case 3:
    iVar6 = 0;
    if (s__GT_001a44b8[0] != '\0') {
      pcVar3 = " (GT";
      cVar2 = s__GT_001a44b8[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      goto LAB_0000de9c;
    }
    break;
  case 4:
    iVar6 = 0;
    if (s__LE_001a44c0[0] != '\0') {
      pcVar3 = " (LE";
      cVar2 = s__LE_001a44c0[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      goto LAB_0000de9c;
    }
    break;
  case 5:
    iVar6 = 0;
    if (s__LT_001a44c8[0] != '\0') {
      pcVar3 = " (LT";
      cVar2 = s__LT_001a44c8[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      goto LAB_0000de9c;
    }
    break;
  case 6:
    iVar6 = 0;
    if (s__NE_001a44d0[0] != '\0') {
      pcVar3 = " (NE";
      cVar2 = s__NE_001a44d0[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      goto LAB_0000de9c;
    }
    break;
  case 7:
    iVar6 = 0;
    if (s__FL_001a44d8[0] != '\0') {
      pcVar3 = " (FL";
      cVar2 = s__FL_001a44d8[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar6] = cVar2;
        iVar6 = iVar6 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      goto LAB_0000de9c;
    }
    break;
  default:
    goto switchD_0000dc3c_default;
  }
  param_2 = param_2 + iVar6;
switchD_0000dc3c_default:
  if ((int)uVar1 < 0) {
    *param_2 = 0x31;
    param_2 = param_2 + 1;
  }
  *param_2 = 0x2e;
  param_2[1] = (((byte)(*puVar7 >> 0x1a) & 3) + 1 & 3) + 0x77;
  param_2[2] = (*(char *)puVar7 + 1U & 3) + 0x77;
  param_2[3] = (((byte)(*puVar7 >> 0x16) & 3) + 1 & 3) + 0x77;
  uVar1 = *puVar7;
  param_2[5] = 0x29;
  param_2[4] = (((byte)(uVar1 >> 0x14) & 3) + 1 & 3) + 0x77;
  return param_2 + 6;
}

/* FUN_0000df50 @ 0xdf50 (648 bytes) */
int FUN_0000df50(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char cVar7;
  
  cVar7 = s___001a4444[0];
  bVar1 = s___001a4444[0] != '\0';
  if (bVar1) {
    pcVar3 = ":";
    iVar4 = 0;
    cVar2 = s___001a4444[0];
    do {
      pcVar3 = pcVar3 + 1;
      *(char *)(param_1 + iVar4) = cVar2;
      iVar4 = iVar4 + 1;
      cVar2 = *pcVar3;
    } while (cVar2 != '\0');
  }
  else {
    iVar4 = 0;
  }
  iVar5 = ((int (*)())FUN_0000cdf0)(param_1 + iVar4,param_2 + 1);
  iVar5 = param_1 + iVar4 + iVar5;
  if (param_3 != 0) {
    if (bVar1) {
      pcVar3 = ":";
      iVar4 = 0;
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
    else {
      iVar4 = 0;
    }
    iVar6 = ((int (*)())FUN_0000cdf0)(iVar5 + iVar4,param_2 + 1);
    iVar5 = iVar5 + iVar4 + iVar6;
  }
  if (param_4 == 2) {
    iVar4 = 0;
    if (s_X_001a4440[0] != '\0') {
      pcVar3 = "X";
      cVar7 = s_X_001a4440[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  else if (param_4 < 3) {
    if (param_4 != 1) {
      return iVar5;
    }
    iVar4 = 0;
    if (s_F_001a4448[0] != '\0') {
      pcVar3 = "F";
      cVar7 = s_F_001a4448[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  else if (param_4 == 3) {
    iVar4 = 0;
    if (s_I_001a444c[0] != '\0') {
      pcVar3 = "I";
      cVar7 = s_I_001a444c[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  else {
    if (param_4 != 4) {
      return iVar5;
    }
    iVar4 = 0;
    if (s_B_001a4450[0] != '\0') {
      pcVar3 = "B";
      cVar7 = s_B_001a4450[0];
      do {
        pcVar3 = pcVar3 + 1;
        *(char *)(iVar5 + iVar4) = cVar7;
        iVar4 = iVar4 + 1;
        cVar7 = *pcVar3;
      } while (cVar7 != '\0');
    }
  }
  return iVar5 + iVar4;
}

/* FUN_0000e1f0 @ 0xe1f0 (4068 bytes) */
int FUN_0000e1f0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  char *param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  int in_stack_00000038;
  
  puVar9 = (uint *)(param_7 * 8 + param_1);
  if ((*(uint *)(param_1 + param_7 * 8) & 0x8000000) != 0) {
    iVar4 = 0;
    if (s___001a44e0[0] != '\0') {
      pcVar3 = "-";
      iVar4 = 0;
      cVar2 = s___001a44e0[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar4] = cVar2;
        iVar4 = iVar4 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    param_2 = param_2 + iVar4;
  }
  uVar6 = *puVar9;
  if ((uVar6 & 0x4000000) != 0) {
    iVar4 = 0;
    if (s___001a44e4[0] != '\0') {
      pcVar3 = "|";
      cVar2 = s___001a44e4[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar4] = cVar2;
        iVar4 = iVar4 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      uVar6 = *puVar9;
    }
    param_2 = param_2 + iVar4;
  }
  switch(uVar6 >> 0x17 & 7) {
  case 0:
    iVar4 = 0;
    if (s_att_001a44e8[0] != '\0') {
      pcVar3 = "att";
      iVar4 = 0;
      cVar2 = s_att_001a44e8[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar4] = cVar2;
        iVar4 = iVar4 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    break;
  case 1:
    iVar4 = 0;
    if (s_tmp_001a4460[0] != '\0') {
      pcVar3 = "tmp";
      iVar4 = 0;
      cVar2 = s_tmp_001a4460[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar4] = cVar2;
        iVar4 = iVar4 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    param_2 = param_2 + iVar4;
    if (param_5 == 0) {
      iVar4 = ((int (*)())FUN_0000cdf0)(param_2,*(undefined2 *)((int)puVar9 + 6));
    }
    else {
      iVar4 = ((int (*)())FUN_0000cdf0)(param_2,*(undefined4 *)(param_5 + (uint)*(ushort *)((int)puVar9 + 6) * 4)
                          );
    }
    param_2 = param_2 + iVar4;
    if (param_6 == 0) {
      uVar6 = *puVar9;
    }
    else {
      uVar6 = *puVar9;
      if ((int)uVar6 < 0) goto LAB_0000e6e8;
      uVar7 = (uint)*(ushort *)((int)puVar9 + 6);
      if (*(int *)(param_6 + uVar7 * 4) != -1) {
        iVar4 = 0;
        if (s___001a4464[0] != '\0') {
          pcVar3 = "[";
          iVar4 = 0;
          cVar2 = s___001a4464[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar4] = cVar2;
            iVar4 = iVar4 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          uVar7 = (uint)*(ushort *)((int)puVar9 + 6);
        }
        iVar5 = ((int (*)())FUN_0000cdf0)(param_2 + iVar4,*(undefined4 *)(param_6 + uVar7 * 4));
        param_2 = param_2 + iVar4 + iVar5;
        iVar4 = 0;
        if (s___001a4468[0] != '\0') {
          pcVar3 = "]";
          iVar4 = 0;
          cVar2 = s___001a4468[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar4] = cVar2;
            iVar4 = iVar4 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        goto LAB_0000e610;
      }
    }
    goto switchD_0000e310_default;
  case 2:
    iVar4 = 0;
    if (s_prm_001a44ec[0] != '\0') {
      pcVar3 = "prm";
      iVar4 = 0;
      cVar2 = s_prm_001a44ec[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar4] = cVar2;
        iVar4 = iVar4 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    iVar5 = ((int (*)())FUN_0000cdf0)(param_2 + iVar4,
                         *(undefined4 *)(param_3 + (uint)*(ushort *)((int)puVar9 + 6) * 4));
    uVar6 = *puVar9;
    param_2 = param_2 + iVar4 + iVar5;
    if (-1 < (int)uVar6) {
      uVar7 = (uint)*(ushort *)((int)puVar9 + 6);
      if (*(int *)(param_4 + uVar7 * 4) != -1) {
        iVar4 = 0;
        if (s___001a4464[0] != '\0') {
          pcVar3 = "[";
          iVar4 = 0;
          cVar2 = s___001a4464[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar4] = cVar2;
            iVar4 = iVar4 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          uVar7 = (uint)*(ushort *)((int)puVar9 + 6);
        }
        iVar5 = ((int (*)())FUN_0000cdf0)(param_2 + iVar4,*(undefined4 *)(param_4 + uVar7 * 4));
        param_2 = param_2 + iVar4 + iVar5;
        iVar4 = 0;
        if (s___001a4468[0] != '\0') {
          pcVar3 = "]";
          iVar4 = 0;
          cVar2 = s___001a4468[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar4] = cVar2;
            iVar4 = iVar4 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
LAB_0000e610:
        uVar6 = *puVar9;
        param_2 = param_2 + iVar4;
      }
      goto switchD_0000e310_default;
    }
    goto LAB_0000e6e8;
  case 3:
    iVar4 = 0;
    if (s_res_001a446c[0] != '\0') {
      pcVar3 = "res";
      iVar4 = 0;
      cVar2 = s_res_001a446c[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar4] = cVar2;
        iVar4 = iVar4 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    break;
  case 4:
    iVar4 = 0;
    if (s_adr_001a44f0[0] != '\0') {
      pcVar3 = "adr";
      iVar4 = 0;
      cVar2 = s_adr_001a44f0[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar4] = cVar2;
        iVar4 = iVar4 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    break;
  default:
    goto switchD_0000e310_default;
  }
  iVar5 = ((int (*)())FUN_0000cdf0)(param_2 + iVar4,*(undefined2 *)((int)puVar9 + 6));
  uVar6 = *puVar9;
  param_2 = param_2 + iVar4 + iVar5;
switchD_0000e310_default:
  if ((int)uVar6 < 0) {
LAB_0000e6e8:
    iVar4 = 0;
    if (s__adr_001a4470[0] != '\0') {
      pcVar3 = "[adr";
      cVar2 = s__adr_001a4470[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar4] = cVar2;
        iVar4 = iVar4 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      uVar6 = *puVar9;
    }
    iVar5 = ((int (*)())FUN_0000cdf0)(param_2 + iVar4,uVar6 >> 0x1e & 1);
    uVar7 = *puVar9;
    param_2 = param_2 + iVar4 + iVar5;
    uVar6 = uVar7 >> 0x1c & 3;
    if (uVar6 == 1) {
      iVar4 = 0;
      if (s__y_001a447c[0] != '\0') {
        pcVar3 = ".y";
        cVar2 = s__y_001a447c[0];
        do {
          pcVar3 = pcVar3 + 1;
          param_2[iVar4] = cVar2;
          iVar4 = iVar4 + 1;
          cVar2 = *pcVar3;
        } while (cVar2 != '\0');
        goto LAB_0000e89c;
      }
LAB_0000e8a0:
      param_2 = param_2 + iVar4;
    }
    else {
      if (1 < uVar6) {
        if (uVar6 == 2) {
          iVar4 = 0;
          if (s__z_001a4480[0] != '\0') {
            pcVar3 = ".z";
            cVar2 = s__z_001a4480[0];
            do {
              pcVar3 = pcVar3 + 1;
              param_2[iVar4] = cVar2;
              iVar4 = iVar4 + 1;
              cVar2 = *pcVar3;
            } while (cVar2 != '\0');
LAB_0000e89c:
            uVar7 = *puVar9;
          }
        }
        else {
          if (uVar6 != 3) goto LAB_0000e8a4;
          iVar4 = 0;
          if (s__w_001a4484[0] != '\0') {
            pcVar3 = ".w";
            cVar2 = s__w_001a4484[0];
            do {
              pcVar3 = pcVar3 + 1;
              param_2[iVar4] = cVar2;
              iVar4 = iVar4 + 1;
              cVar2 = *pcVar3;
            } while (cVar2 != '\0');
            goto LAB_0000e89c;
          }
        }
        goto LAB_0000e8a0;
      }
      if (uVar6 == 0) {
        iVar4 = 0;
        if (s__x_001a4478[0] != '\0') {
          pcVar3 = ".x";
          cVar2 = s__x_001a4478[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar4] = cVar2;
            iVar4 = iVar4 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          goto LAB_0000e89c;
        }
        goto LAB_0000e8a0;
      }
    }
LAB_0000e8a4:
    if ((uVar7 & 0x3800000) == 0x800000) {
      if (param_6 == 0) goto LAB_0000e908;
      iVar4 = *(int *)(param_6 + (uint)*(ushort *)((int)puVar9 + 6) * 4);
joined_r0x0000e904:
      if (iVar4 == -1) goto LAB_0000e908;
    }
    else {
      if (((uVar7 & 0x3800000) == 0x1000000) && (param_4 != 0)) {
        iVar4 = *(int *)(param_4 + (uint)*(ushort *)((int)puVar9 + 6) * 4);
        goto joined_r0x0000e904;
      }
LAB_0000e908:
      iVar4 = 0;
    }
    iVar4 = iVar4 + (char)*puVar9;
    if (iVar4 != 0) {
      if (0 < iVar4) {
        iVar4 = 0;
        if (s___001a4488[0] != '\0') {
          pcVar3 = "+";
          cVar2 = s___001a4488[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar4] = cVar2;
            iVar4 = iVar4 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        param_2 = param_2 + iVar4;
      }
      iVar4 = ((int (*)())FUN_0000cdf0)(param_2);
      param_2 = param_2 + iVar4;
    }
    iVar4 = 0;
    if (s___001a4468[0] != '\0') {
      pcVar3 = "]";
      iVar4 = 0;
      cVar2 = s___001a4468[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar4] = cVar2;
        iVar4 = iVar4 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    uVar6 = *puVar9;
    param_2 = param_2 + iVar4;
  }
  if ((uVar6 & 0x3800000) == 0x2000000) {
LAB_0000efb4:
    if (param_8 == 0) goto LAB_0000f0bc;
  }
  else {
    if (in_stack_00000038 != 0) {
      puVar8 = (uint *)(param_1 + (param_7 + 1) * 8);
LAB_0000e9fc:
      uVar6 = *puVar8 >> 0xc & 0xf;
      if (s___001a44f4[0] == '\0') {
        iVar4 = 0;
      }
      else {
        pcVar3 = ", ";
        iVar4 = 0;
        cVar2 = s___001a44f4[0];
        do {
          pcVar3 = pcVar3 + 1;
          param_2[iVar4] = cVar2;
          iVar4 = iVar4 + 1;
          cVar2 = *pcVar3;
        } while (cVar2 != '\0');
      }
      param_2 = param_2 + iVar4;
      iVar4 = 0;
LAB_0000ebd8:
      switch(uVar6) {
      case 0:
        iVar5 = 0;
        if (s_x_001a4490[0] != '\0') {
          pcVar3 = "x";
          cVar2 = s_x_001a4490[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 1:
        iVar5 = 0;
        if (s_y_001a4494[0] != '\0') {
          pcVar3 = "y";
          cVar2 = s_y_001a4494[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 2:
        iVar5 = 0;
        if (s_z_001a4498[0] != '\0') {
          pcVar3 = "z";
          cVar2 = s_z_001a4498[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 3:
        iVar5 = 0;
        if (s_w_001a449c[0] != '\0') {
          pcVar3 = "w";
          cVar2 = s_w_001a449c[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 4:
        iVar5 = 0;
        if (s__x_001a44fc[0] != '\0') {
          pcVar3 = "-x";
          cVar2 = s__x_001a44fc[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 5:
        iVar5 = 0;
        if (s__y_001a4500[0] != '\0') {
          pcVar3 = "-y";
          cVar2 = s__y_001a4500[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 6:
        iVar5 = 0;
        if (s__z_001a4504[0] != '\0') {
          pcVar3 = "-z";
          cVar2 = s__z_001a4504[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 7:
        iVar5 = 0;
        if (s__w_001a4508[0] != '\0') {
          pcVar3 = "-w";
          cVar2 = s__w_001a4508[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 8:
        iVar5 = 0;
        if (s_1_001a442c[0] != '\0') {
          pcVar3 = "1";
          cVar2 = s_1_001a442c[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 9:
        iVar5 = 0;
        if (s_0_001a450c[0] != '\0') {
          pcVar3 = "0";
          cVar2 = s_0_001a450c[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      case 10:
        iVar5 = 0;
        if (s__1_001a4510[0] != '\0') {
          pcVar3 = "-1";
          cVar2 = s__1_001a4510[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
        break;
      default:
        goto switchD_0000ebf8_default;
      }
      param_2 = param_2 + iVar5;
switchD_0000ebf8_default:
      bVar1 = iVar4 == 3;
      iVar4 = iVar4 + 1;
      if (bVar1) {
        uVar6 = *puVar9;
        goto LAB_0000efb4;
      }
      if (iVar4 == 1) {
        iVar5 = 0;
        uVar6 = *puVar8 >> 8 & 0xf;
        if (s___001a44f8[0] != '\0') {
          pcVar3 = ",";
          iVar5 = 0;
          cVar2 = s___001a44f8[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
      }
      else {
        if (iVar4 < 2) {
          if (iVar4 == 0) goto LAB_0000e9fc;
          goto LAB_0000ebd8;
        }
        if (iVar4 == 2) {
          iVar5 = 0;
          uVar6 = *puVar8 >> 4 & 0xf;
          if (s___001a44f8[0] != '\0') {
            pcVar3 = ",";
            iVar5 = 0;
            cVar2 = s___001a44f8[0];
            do {
              pcVar3 = pcVar3 + 1;
              param_2[iVar5] = cVar2;
              iVar5 = iVar5 + 1;
              cVar2 = *pcVar3;
            } while (cVar2 != '\0');
          }
          goto LAB_0000ebd4;
        }
        if (iVar4 != 3) goto LAB_0000ebd8;
        iVar5 = 0;
        uVar6 = *puVar8 & 0xf;
        if (s___001a44f8[0] != '\0') {
          pcVar3 = ",";
          iVar5 = 0;
          cVar2 = s___001a44f8[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar5] = cVar2;
            iVar5 = iVar5 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
        }
      }
LAB_0000ebd4:
      param_2 = param_2 + iVar5;
      goto LAB_0000ebd8;
    }
    if (param_8 == 0) {
      if ((uVar6 & 0x7f8000) != 0xd8000) {
        iVar4 = 0;
        if (s___001a448c[0] != '\0') {
          pcVar3 = ".";
          iVar4 = 0;
          cVar2 = s___001a448c[0];
          do {
            pcVar3 = pcVar3 + 1;
            param_2[iVar4] = cVar2;
            iVar4 = iVar4 + 1;
            cVar2 = *pcVar3;
          } while (cVar2 != '\0');
          uVar6 = *puVar9;
        }
        uVar7 = uVar6 >> 0x15 & 3;
        pcVar3 = param_2 + iVar4;
        if (((uVar7 == (uVar6 >> 0x13 & 3)) && (uVar7 == (uVar6 >> 0x11 & 3))) &&
           (uVar7 == (uVar6 >> 0xf & 3))) {
          param_2[iVar4] = ((char)uVar7 + 1U & 3) + 0x77;
          param_2 = pcVar3 + 1;
          uVar6 = *puVar9;
        }
        else {
          param_2 = pcVar3 + 4;
          *pcVar3 = ((char)uVar7 + 1U & 3) + 0x77;
          pcVar3[1] = (((byte)(*puVar9 >> 0x13) & 3) + 1 & 3) + 0x77;
          pcVar3[2] = (((byte)(*puVar9 >> 0x11) & 3) + 1 & 3) + 0x77;
          pcVar3[3] = (((byte)(*puVar9 >> 0xf) & 3) + 1 & 3) + 0x77;
          uVar6 = *puVar9;
        }
      }
      goto LAB_0000f0bc;
    }
    iVar4 = 0;
    if (s___001a448c[0] != '\0') {
      pcVar3 = ".";
      iVar4 = 0;
      cVar2 = s___001a448c[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar4] = cVar2;
        iVar4 = iVar4 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
      uVar6 = *puVar9;
    }
    param_2[iVar4] = (((byte)(uVar6 >> 0x15) & 3) + 1 & 3) + 0x77;
    iVar5 = iVar4 + 1;
    uVar6 = *puVar9;
    if ((uVar6 & 0x3000) != 0) {
      iVar5 = iVar4 + 2;
      param_2[iVar4 + 1] = (((byte)(uVar6 >> 0x13) & 3) + 1 & 3) + 0x77;
      uVar6 = *puVar9;
    }
    param_2 = param_2 + iVar5;
    if (1 < (uVar6 >> 0xc & 3)) {
      *param_2 = (((byte)(uVar6 >> 0x11) & 3) + 1 & 3) + 0x77;
      param_2 = param_2 + 1;
      uVar6 = *puVar9;
    }
    if (2 < (uVar6 >> 0xc & 3)) {
      *param_2 = (((byte)(uVar6 >> 0xf) & 3) + 1 & 3) + 0x77;
      param_2 = param_2 + 1;
      uVar6 = *puVar9;
    }
  }
  param_2 = (char *)((int (*)())FUN_0000d240)(param_2,uVar6 >> 0xc & 3,uVar6 >> 0xe & 1);
  uVar6 = *puVar9;
LAB_0000f0bc:
  if ((uVar6 & 0x4000000) != 0) {
    iVar4 = 0;
    if (s___001a44e4[0] != '\0') {
      pcVar3 = "|";
      cVar2 = s___001a44e4[0];
      do {
        pcVar3 = pcVar3 + 1;
        param_2[iVar4] = cVar2;
        iVar4 = iVar4 + 1;
        cVar2 = *pcVar3;
      } while (cVar2 != '\0');
    }
    param_2 = param_2 + iVar4;
  }
  return param_2;
}

/* FUN_0000f250 @ 0xf250 (932 bytes) */
int FUN_0000f250(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int in_r9;
  int in_r10;
  
  iVar3 = 0;
  if (s_texture__001a4514[0] != '\0') {
    pcVar2 = "texture[";
    iVar3 = 0;
    cVar1 = s_texture__001a4514[0];
    do {
      pcVar2 = pcVar2 + 1;
      *(char *)(param_2 + iVar3) = cVar1;
      iVar3 = iVar3 + 1;
      cVar1 = *pcVar2;
    } while (cVar1 != '\0');
  }
  param_2 = param_2 + iVar3;
  if (in_r10 == 0) {
    in_r9 = in_r9 * 8;
    iVar3 = ((int (*)())FUN_0000cdf0)(param_2,*(uint *)(in_r9 + param_1) & 0x1f);
    param_2 = param_2 + iVar3;
  }
  else {
    in_r9 = (in_r9 + 1) * 8;
    param_2 = ((int (*)())FUN_0000e1f0)(param_1,param_2);
  }
  iVar3 = 0;
  if (s____001a4520[0] != '\0') {
    pcVar2 = "], ";
    iVar3 = 0;
    cVar1 = s____001a4520[0];
    do {
      pcVar2 = pcVar2 + 1;
      *(char *)(param_2 + iVar3) = cVar1;
      iVar3 = iVar3 + 1;
      cVar1 = *pcVar2;
    } while (cVar1 != '\0');
  }
  param_2 = param_2 + iVar3;
  switch(*(uint *)(in_r9 + param_1) >> 5 & 7) {
  case 0:
    iVar3 = 0;
    if (s_CUBE_001a4530[0] != '\0') {
      pcVar2 = "CUBE";
      cVar1 = s_CUBE_001a4530[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(param_2 + iVar3) = cVar1;
        iVar3 = iVar3 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    break;
  case 1:
    iVar3 = 0;
    if (s_3D_001a452c[0] != '\0') {
      pcVar2 = "3D";
      cVar1 = s_3D_001a452c[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(param_2 + iVar3) = cVar1;
        iVar3 = iVar3 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    break;
  case 2:
    iVar3 = 0;
    if (s_RECT_001a4538[0] != '\0') {
      pcVar2 = "RECT";
      cVar1 = s_RECT_001a4538[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(iVar3 + param_2) = cVar1;
        iVar3 = iVar3 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    break;
  case 3:
    iVar3 = 0;
    if (s_2D_001a4528[0] != '\0') {
      pcVar2 = "2D";
      cVar1 = s_2D_001a4528[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(iVar3 + param_2) = cVar1;
        iVar3 = iVar3 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    break;
  case 4:
    iVar3 = 0;
    if (s_1D_001a4524[0] != '\0') {
      pcVar2 = "1D";
      cVar1 = s_1D_001a4524[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(param_2 + iVar3) = cVar1;
        iVar3 = iVar3 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    break;
  case 5:
    iVar3 = 0;
    if (s_SHADOWRECT_001a4540[0] != '\0') {
      pcVar2 = "SHADOWRECT";
      cVar1 = s_SHADOWRECT_001a4540[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(param_2 + iVar3) = cVar1;
        iVar3 = iVar3 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    break;
  case 6:
    iVar3 = 0;
    if (s_SHADOW2D_001a454c[0] != '\0') {
      pcVar2 = "SHADOW2D";
      cVar1 = s_SHADOW2D_001a454c[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(param_2 + iVar3) = cVar1;
        iVar3 = iVar3 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    break;
  case 7:
    iVar3 = 0;
    if (s_SHADOW1D_001a4558[0] != '\0') {
      pcVar2 = "SHADOW1D";
      cVar1 = s_SHADOW1D_001a4558[0];
      do {
        pcVar2 = pcVar2 + 1;
        *(char *)(param_2 + iVar3) = cVar1;
        iVar3 = iVar3 + 1;
        cVar1 = *pcVar2;
      } while (cVar1 != '\0');
    }
    break;
  default:
    goto switchD_0000f394_default;
  }
  param_2 = param_2 + iVar3;
switchD_0000f394_default:
  return param_2;
}

