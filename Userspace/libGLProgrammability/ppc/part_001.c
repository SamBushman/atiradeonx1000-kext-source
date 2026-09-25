#include "decls.h"

/* _GetChunkAllocationSize @ 0x97b825bc (124 bytes) */
int _GetChunkAllocationSize(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  switch(param_1) {
  case 0:
  case 3:
  case 10:
    return 0x10;
  case 1:
    return 4;
  case 2:
  case 4:
  case 5:
  case 6:
  case 7:
  case 9:
    return 8;
  case 8:
    break;
  case 0xb:
    if (param_2 != 0) {
      return param_2 + 9;
    }
    return 8;
  default:
    return 0;
  }
  if (param_2 != 0) {
    return param_2 + 0x39;
  }
  return 0x38;
}

/* _PPStreamChunkListSort @ 0x97b82668 (156 bytes) */
int _PPStreamChunkListSort(param_1)
  int *param_1;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *param_1;
  if (iVar2 == 0) {
    return;
  }
  while( true ) {
    bVar1 = false;
    if (iVar2 == 0) {
      return;
    }
    while (iVar4 = iVar2, iVar2 = *(int *)(iVar4 + 8), iVar2 != 0) {
      if (*(ushort *)(iVar2 + 0x12) < *(ushort *)(iVar4 + 0x12)) {
        if (*(int *)(iVar2 + 8) == 0) {
          param_1[1] = iVar4;
        }
        else {
          *(int *)(*(int *)(iVar2 + 8) + 4) = iVar4;
        }
        iVar3 = *(int *)(iVar4 + 4);
        if (iVar3 == 0) {
          *param_1 = iVar2;
          iVar3 = *(int *)(iVar4 + 4);
        }
        else {
          *(int *)(iVar3 + 8) = iVar2;
        }
        bVar1 = true;
        *(int *)(iVar2 + 4) = iVar3;
        *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar2 + 8);
        *(int *)(iVar4 + 4) = iVar2;
        *(int *)(iVar2 + 8) = iVar4;
      }
    }
    if (!bVar1) break;
    iVar2 = *param_1;
  }
  return;
}

/* _PPStreamAttachOperationsChunkList @ 0x97b82704 (56 bytes) */
int _PPStreamAttachOperationsChunkList(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(param_1 + 0x20));
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return;
}

/* _PPStreamChunkListFree @ 0x97b8273c (84 bytes) */
int _PPStreamChunkListFree(param_1)
  undefined4 *param_1;
{
  int iVar1;
  void *pvVar2;
  void *pvVar3;
  
  iVar1 = param_1[2];
  pvVar2 = (void *)*param_1;
  if (0 < iVar1) {
    do {
      pvVar3 = *(void **)((int)pvVar2 + 8);
      _free(pvVar2);
      iVar1 = iVar1 + -1;
      pvVar2 = pvVar3;
    } while (iVar1 != 0);
  }
  _free(param_1);
  return;
}

/* _PPStreamChunkListRemoveChunk @ 0x97b82790 (120 bytes) */
int _PPStreamChunkListRemoveChunk(param_1, param_2)
  undefined4 *param_1;
  void *param_2;
{
  undefined4 extraout_r3;
  int iVar1;
  
  iVar1 = *(int *)((int)param_2 + 4);
  if (iVar1 == 0) {
    *param_1 = *(undefined4 *)((int)param_2 + 8);
    iVar1 = *(int *)((int)param_2 + 4);
  }
  else {
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)((int)param_2 + 8);
  }
  if (*(int *)((int)param_2 + 8) == 0) {
    param_1[1] = iVar1;
  }
  else {
    *(int *)(*(int *)((int)param_2 + 8) + 4) = iVar1;
  }
  _free(param_2);
  param_1[2] = param_1[2] + -1;
  return extraout_r3;
}

/* _PPStreamAttachParamBindingsChunkList @ 0x97b82808 (56 bytes) */
int _PPStreamAttachParamBindingsChunkList(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return;
}

/* _PPStreamAttachParamBindingArraysChunkList @ 0x97b82840 (56 bytes) */
int _PPStreamAttachParamBindingArraysChunkList(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)(param_1 + 0x14));
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}

/* _PPStreamGetStream @ 0x97b82878 (964 bytes) */
int _PPStreamGetStream(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 *param_2;
  int *param_3;
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int local_30 [7];
  
  _PPStreamChunkListGetStream(param_1[1],0,local_30,param_1);
  iVar2 = local_30[0];
  _PPStreamChunkListGetStream(param_1[6],0,local_30,param_1);
  iVar2 = iVar2 + local_30[0];
  _PPStreamChunkListGetStream(param_1[4],0,local_30,param_1);
  iVar2 = iVar2 + local_30[0];
  _PPStreamChunkListGetStream(param_1[7],0,local_30,param_1);
  iVar2 = iVar2 + local_30[0];
  _PPStreamChunkListGetStream(param_1[5],0,local_30,param_1);
  iVar2 = iVar2 + local_30[0];
  _PPStreamChunkListGetStream(param_1[2],0,local_30,param_1);
  iVar2 = iVar2 + local_30[0];
  _PPStreamChunkListGetStream(param_1[0xc],0,local_30,param_1);
  iVar2 = iVar2 + local_30[0];
  _PPStreamChunkListGetStream(param_1[8],0,local_30,param_1);
  iVar2 = iVar2 + local_30[0];
  _PPStreamChunkListGetStream(param_1[10],0,local_30,param_1);
  iVar2 = iVar2 + local_30[0];
  _PPStreamChunkListGetStream(param_1[0xb],0,local_30,param_1);
  iVar2 = (iVar2 - (iVar2 + 0xeU & 1)) + 0x10 + local_30[0];
  *param_3 = iVar2;
  if (param_2 != (undefined4 *)0x0) {
    _memset(param_2,0,iVar2 * 8);
    *param_2 = *param_1;
    param_2[2] = *param_3;
    if (*(int *)(param_1[3] + 8) == 0) {
      param_2[6] = 0;
    }
    else {
      iVar2 = ((int (*)())_PPStreamChunkListGetMaxIndex)(param_1[3]);
      param_2[6] = iVar2 + 1;
    }
    uVar1 = *(undefined4 *)(param_1[1] + 8);
    param_2[5] = 0xe;
    param_2[4] = uVar1;
    _PPStreamChunkListGetStream(param_1[1],param_2 + 0x1c,local_30,param_1);
    iVar2 = local_30[0] + 0xe;
    param_2[8] = *(undefined4 *)(param_1[6] + 8);
    param_2[9] = iVar2;
    _PPStreamChunkListGetStream(param_1[6],param_2 + iVar2 * 2,local_30,param_1);
    iVar2 = iVar2 + local_30[0];
    param_2[10] = *(undefined4 *)(param_1[4] + 8);
    param_2[0xb] = iVar2;
    _PPStreamChunkListGetStream(param_1[4],param_2 + iVar2 * 2,local_30,param_1);
    iVar2 = iVar2 + local_30[0];
    param_2[0xc] = *(undefined4 *)(param_1[7] + 8);
    param_2[0xd] = iVar2;
    _PPStreamChunkListGetStream(param_1[7],param_2 + iVar2 * 2,local_30,param_1);
    iVar2 = iVar2 + local_30[0];
    param_2[0xe] = *(undefined4 *)(param_1[5] + 8);
    param_2[0xf] = iVar2;
    _PPStreamChunkListGetStream(param_1[5],param_2 + iVar2 * 2,local_30,param_1);
    iVar2 = iVar2 + local_30[0];
    param_2[0x10] = *(undefined4 *)(param_1[2] + 8);
    param_2[0x11] = iVar2;
    _PPStreamChunkListGetStream(param_1[2],param_2 + iVar2 * 2,local_30,param_1);
    iVar2 = iVar2 + local_30[0];
    param_2[0x12] = *(undefined4 *)(param_1[0xc] + 8);
    param_2[0x13] = iVar2;
    _PPStreamChunkListGetStream(param_1[0xc],param_2 + iVar2 * 2,local_30,param_1);
    uVar1 = *(undefined4 *)(param_1[8] + 8);
    iVar2 = iVar2 + local_30[0];
    param_2[0x15] = iVar2;
    param_2[0x14] = uVar1;
    _PPStreamChunkListGetStream(param_1[8],param_2 + iVar2 * 2,local_30,param_1);
    iVar2 = iVar2 + local_30[0];
    if (local_30[0] != 0) {
      param_2[iVar2 * 2] =
           *(uint *)(*(int *)(param_1[8] + 4) + 0xc) >> 3 & 0x1c000000 |
           param_2[iVar2 * 2] & 0xe3ffffff;
    }
    uVar1 = *(undefined4 *)(param_1[10] + 8);
    param_2[0x19] = iVar2;
    param_2[0x18] = uVar1;
    _PPStreamChunkListGetStream(param_1[10],param_2 + iVar2 * 2,local_30,param_1);
    uVar3 = iVar2 + local_30[0];
    param_2[0x16] = 0;
    param_2[0x17] = uVar3;
    iVar2 = (uVar3 - (uVar3 & 1)) + 2;
    param_2[0x1a] = *(undefined4 *)(param_1[0xb] + 8);
    param_2[0x1b] = iVar2;
    _PPStreamChunkListGetStream(param_1[0xb],param_2 + iVar2 * 2,local_30,param_1);
  }
  return;
}

/* _PPStreamChunkListGetMaxIndex @ 0x97b82c3c (164 bytes) */
int _PPStreamChunkListGetMaxIndex(param_1)
  undefined4 *param_1;
{
  uint uVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar2 = (undefined1 *)*param_1;
  uVar3 = 0;
  uVar4 = 1;
  do {
    if (puVar2 == (undefined1 *)0x0) {
      return uVar3;
    }
    switch(*puVar2) {
    case 0:
    case 2:
    case 3:
    case 4:
      uVar1 = (uint)*(ushort *)(puVar2 + 0x12);
      break;
    case 1:
      uVar1 = *(uint *)(puVar2 + 0xc);
      break;
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
      if (uVar3 < uVar4) {
        uVar3 = uVar4;
      }
      goto switchD_97b82c84_default;
    case 8:
      uVar1 = *(uint *)(puVar2 + 0xc) & 0x3ffff;
      break;
    case 0xb:
      return 0;
    default:
      goto switchD_97b82c84_default;
    }
    if (uVar3 < uVar1) {
      uVar3 = uVar1;
    }
switchD_97b82c84_default:
    puVar2 = *(undefined1 **)(puVar2 + 8);
    uVar4 = uVar4 + 1;
  } while( true );
}

/* _PPStreamAddTempUsage @ 0x97b82d10 (108 bytes) */
int _PPStreamAddTempUsage(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  puVar1 = _calloc(0x1c,1);
  uVar3 = param_2[3];
  uVar2 = *(undefined4 *)(param_1 + 4);
  uVar4 = *param_2;
  uVar6 = param_2[1];
  uVar5 = param_2[2];
  *puVar1 = 0;
  *(undefined4 *)(puVar1 + 0xc) = uVar4;
  *(undefined4 *)(puVar1 + 0x10) = uVar6;
  *(undefined4 *)(puVar1 + 0x14) = uVar5;
  *(undefined4 *)(puVar1 + 0x18) = uVar3;
  _PPStreamChunkListAddChunk(uVar2,puVar1);
  return;
}

/* _PPEmulatorProgramCreate @ 0x97b82d7c (72 bytes) */
int _PPEmulatorProgramCreate()
{
  undefined4 uVar1;
  void *pvVar2;
  
  pvVar2 = _calloc(0x128,1);
  uVar1 = DAT_a7b7bda4;
  *(undefined4 *)((int)pvVar2 + 0xc) = DAT_a7b7bda4;
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  return;
}

/* _PPEmulatorProgramInitialiseHandleBanks @ 0x97b82dc4 (288 bytes) */
int _PPEmulatorProgramInitialiseHandleBanks(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  do {
    if (*(void **)(param_1 + 0x80) != (void *)0x0) {
      _free(*(void **)(param_1 + 0x80));
    }
    *(undefined4 *)(param_1 + 0x80) = 0;
    *(undefined4 *)(param_1 + 0x84) = 0;
    *(undefined4 *)(param_1 + 0x88) = 0;
    iVar1 = param_3;
    if (((((uVar4 == 1) || (iVar1 = param_2, uVar4 == 0)) || (iVar1 = param_4, uVar4 == 2)) ||
        (iVar1 = param_5, uVar4 == 3)) && (iVar1 != 0)) {
      iVar5 = 0x20;
      do {
        if (iVar1 << (0x20U - iVar5 & 0x3f) < 0) {
          if (iVar5 != 0) {
            uVar2 = *(uint *)(param_1 + 0x88);
            do {
              uVar2 = uVar2 << 1 | 1;
              iVar5 = iVar5 + -1;
            } while (iVar5 != 0);
            *(uint *)(param_1 + 0x88) = uVar2;
          }
          break;
        }
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      uVar2 = iVar1 << 1 & ~*(uint *)(param_1 + 0x88);
      *(uint *)(param_1 + 0x84) = uVar2;
      pvVar3 = _malloc(uVar2 << 4);
      *(void **)(param_1 + 0x80) = pvVar3;
      _memset(pvVar3,0,*(int *)(param_1 + 0x84) << 4);
    }
    uVar4 = uVar4 + 1;
    param_1 = param_1 + 0xc;
    if (3 < uVar4) {
      return;
    }
  } while( true );
}

/* _PPEmulatorProgramConvertFromPPStream @ 0x97b82ee4 (2768 bytes) */
int _PPEmulatorProgramConvertFromPPStream(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  ushort uVar1;
  byte bVar4;
  uint uVar2;
  uint uVar3;
  int *piVar5;
  int iVar6;
  int iVar7;
  void *pvVar8;
  uint *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int *piVar13;
  uint uVar14;
  uint uVar15;
  int *piVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  int iVar19;
  uint uVar20;
  size_t sVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  int iVar25;
  int iVar26;
  int *piVar27;
  uint *puVar28;
  
  uVar24 = 0;
  uVar20 = 0xf;
  param_1[0xe] = *param_2;
  piVar27 = (int *)param_2[8];
  iVar19 = param_2[6];
  piVar5 = (int *)param_2[0xc];
  piVar16 = (int *)param_2[10];
  uVar17 = param_2[7];
  uVar18 = param_2[4];
  piVar13 = (int *)param_2[0xb];
  sVar21 = piVar27[2];
  param_1[0xd] = 0;
  param_1[0x2f] = *(int *)(iVar19 + 8) << 4;
  iVar6 = *piVar5;
  for (iVar26 = piVar5[2]; iVar26 != 0; iVar26 = iVar26 + -1) {
    if (*(char *)(iVar6 + 0xf) == '\x06') {
      param_1[0xb] = 1;
    }
    else if (*(char *)(iVar6 + 0xf) == '\a') {
      param_1[0xc] = 1;
    }
    iVar6 = *(int *)(iVar6 + 8);
  }
  if ((param_1[0xc] != 0) || (*(int *)PTR_DAT_a7b7c100 == 0)) {
    uVar20 = 7;
  }
  if ((param_1[0xb] != 0) ||
     ((*(int *)PTR_DAT_a7b7c100 == 0 && ((param_1[0xe] - 0x8b30 < 2 || (param_1[0xe] == 0x8804))))))
  {
    uVar20 = uVar20 & 0xfffffffd;
  }
  iVar26 = piVar13[2];
  iVar6 = *piVar13;
  if (iVar26 != 0) {
    iVar22 = 0;
    pvVar8 = _malloc(iVar26 << 4);
    param_1[0x2c] = pvVar8;
    for (; iVar26 != 0; iVar26 = iVar26 + -1) {
      iVar25 = iVar22 * 0x10;
      uVar10 = *(undefined4 *)(iVar6 + 0x18);
      iVar22 = iVar22 + 1;
      uVar12 = *(undefined4 *)(iVar6 + 0x10);
      uVar11 = *(undefined4 *)(iVar6 + 0x14);
      iVar7 = iVar25 + param_1[0x2c];
      *(undefined4 *)(iVar25 + param_1[0x2c]) = *(undefined4 *)(iVar6 + 0xc);
      *(undefined4 *)(iVar7 + 0xc) = uVar10;
      *(undefined4 *)(iVar7 + 4) = uVar12;
      *(undefined4 *)(iVar7 + 8) = uVar11;
      iVar6 = *(int *)(iVar6 + 8);
    }
  }
  if (sVar21 != 0) {
    puVar9 = _calloc(0x11c,sVar21);
    uVar23 = 0;
    *param_1 = puVar9;
    param_1[1] = puVar9 + sVar21 * 0x47 + -0x47;
    iVar26 = *piVar27;
    param_1[0x48] = puVar9;
    if (sVar21 != 0) {
      do {
        puVar28 = (uint *)(iVar26 + 0xc);
        *puVar9 = *(uint *)(iVar26 + 0xc) >> 0x12 & 0xff;
        *(byte *)(puVar9 + 1) = (byte)(*(uint *)(iVar26 + 0x10) >> 0x14) & 1;
        if (param_1[0xe] - 0x8b30 < 2) {
          *(byte *)((int)puVar9 + 5) =
               ((byte)((uint)*(undefined4 *)(iVar26 + 0x10) >> 0x1a) & 3) + 1;
        }
        else {
          *(undefined1 *)((int)puVar9 + 5) = 4;
        }
        *(byte *)((int)puVar9 + 6) = (byte)(*(uint *)(iVar26 + 0x10) >> 0x16) & 1;
        puVar9[2] = *(uint *)(iVar26 + 0x10) & 0x3ffff;
        puVar9[0x45] = *(uint *)(iVar26 + 0x3c);
        if ((*puVar28 & 0x3ffff) == 0) {
          param_1[0x48] = puVar9;
        }
        uVar14 = *puVar9;
        switch(uVar14) {
        default:
          goto switchD_97b83138_caseD_0;
        case 1:
        case 0x11:
        case 0x13:
        case 0x14:
        case 0x2b:
        case 0x38:
        case 0x41:
          uVar14 = param_1[0xd] | 0x40;
          break;
        case 0x48:
          uVar14 = param_1[0xd] | 0x200;
        }
        param_1[0xd] = uVar14;
        uVar14 = *puVar9;
switchD_97b83138_caseD_0:
        switch(uVar14) {
        case 4:
        case 5:
        case 0x11:
        case 0x42:
        case 0x43:
        case 0x48:
          uVar14 = param_1[0xd] | 0x400;
          break;
        default:
          goto switchD_97b832a0_caseD_6;
        case 0x4b:
        case 0x4c:
        case 0x55:
        case 0x56:
        case 0x57:
        case 0x58:
        case 0x59:
        case 0x5a:
        case 0x5b:
          uVar14 = param_1[0xd] | 0x800;
          break;
        case 0x4f:
          uVar14 = param_1[0xd] | 0x8000;
        }
        param_1[0xd] = uVar14;
        uVar14 = *puVar9;
switchD_97b832a0_caseD_6:
        if (uVar14 == 0x4e) {
          *puVar9 = 0x22;
        }
        uVar14 = *(uint *)(iVar26 + 0x14) >> 0x11 & 7;
        if (uVar14 == 1) {
          *(undefined2 *)(puVar9 + 7) = 0;
          param_1[0xd] = param_1[0xd] | 1;
          uVar24 = param_1[0x20] + (uint)*(ushort *)(iVar26 + 0x1a) * 0x10;
        }
        else if (uVar14 == 3) {
          iVar6 = ((int (*)())_PPStreamChunkListChunkAtIndex)(uVar17,(uint)*(ushort *)(iVar26 + 0x1a));
          if ((*(uint *)(iVar6 + 0xc) >> 0x10 & 0xf) == 7) {
            param_1[0xd] = param_1[0xd] | 0x2000;
            *(undefined2 *)(puVar9 + 7) = 9;
          }
          else {
            *(undefined2 *)(puVar9 + 7) = 1;
          }
          param_1[0xd] = param_1[0xd] | 2;
          uVar24 = param_1[0x23] + (uint)*(ushort *)(iVar6 + 0x12) * 0x10;
        }
        puVar9[3] = uVar24;
        if (*(int *)(iVar26 + 0x18) < 0) {
          *(undefined1 *)((int)puVar9 + 0x1f) = 1;
          *(short *)(puVar9 + 6) = (short)(char)((uint)(*(int *)(iVar26 + 0x18) << 4) >> 0x18);
        }
        *(undefined1 *)((int)puVar9 + 0x1e) = 0;
        if (param_1[0xe] - 0x8b30 < 2) {
          *(byte *)(puVar9 + 5) = (byte)((uint)*(undefined4 *)(iVar26 + 0x14) >> 8) & 3;
          *(byte *)((int)puVar9 + 0x15) = (byte)(*(uint *)(iVar26 + 0x14) >> 6) & 3;
          *(byte *)((int)puVar9 + 0x16) = (byte)(*(uint *)(iVar26 + 0x14) >> 4) & 3;
          *(byte *)((int)puVar9 + 0x17) = (byte)(*(uint *)(iVar26 + 0x14) >> 2) & 3;
        }
        else {
          *(undefined1 *)(puVar9 + 5) = 0;
          *(undefined1 *)((int)puVar9 + 0x15) = 1;
          *(undefined1 *)((int)puVar9 + 0x16) = 2;
          *(undefined1 *)((int)puVar9 + 0x17) = 3;
        }
        if (*(short *)(puVar9 + 7) == 9) {
          bVar4 = 4;
LAB_97b835e0:
          *(byte *)(puVar9 + 10) = bVar4;
        }
        else {
          *(undefined1 *)(puVar9 + 10) = 0xf;
          uVar14 = *(uint *)(iVar26 + 0x14);
          if ((uVar14 & 0x2000) == 0) {
            *(undefined1 *)(puVar9 + 10) = 0xe;
            uVar14 = *(uint *)(iVar26 + 0x14);
          }
          if ((uVar14 & 0x4000) == 0) {
            *(byte *)(puVar9 + 10) = *(byte *)(puVar9 + 10) & 0xfd;
            uVar14 = *(uint *)(iVar26 + 0x14);
          }
          if ((uVar14 & 0x8000) == 0) {
            *(byte *)(puVar9 + 10) = *(byte *)(puVar9 + 10) & 0xfb;
            uVar14 = *(uint *)(iVar26 + 0x14);
          }
          if ((uVar14 & 0x10000) == 0) {
            bVar4 = *(byte *)(puVar9 + 10) & 0xf7;
            goto LAB_97b835e0;
          }
        }
        if (param_1[0xe] - 0x8b30 < 2) {
          *(byte *)(puVar9 + 8) = (byte)(*(uint *)(iVar26 + 0x14) >> 0xc) & 1;
          *(byte *)((int)puVar9 + 0x21) = ((byte)(*(uint *)(iVar26 + 0x14) >> 10) & 3) + 1;
          uVar14 = *(uint *)(iVar26 + 0x10) >> 0x17 & 7;
        }
        else {
          *(undefined1 *)(puVar9 + 8) = 0;
          uVar14 = 1;
          *(undefined1 *)((int)puVar9 + 0x21) = 4;
        }
        puVar9[9] = uVar14;
        uVar15 = *puVar9;
        *(byte *)((int)puVar9 + 0x29) = (byte)((uint)*(undefined4 *)(iVar26 + 0x14) >> 0x1c) & 7;
        *(byte *)((int)puVar9 + 0x2a) = (byte)((uint)*(undefined4 *)(iVar26 + 0x14) >> 0x1a) & 3;
        *(byte *)((int)puVar9 + 0x2b) = (byte)((uint)*(undefined4 *)(iVar26 + 0x14) >> 0x18) & 3;
        *(byte *)(puVar9 + 0xb) = (byte)(*(uint *)(iVar26 + 0x14) >> 0x16) & 3;
        *(byte *)((int)puVar9 + 0x2d) = (byte)(*(uint *)(iVar26 + 0x14) >> 0x14) & 3;
        uVar14 = *puVar28 >> 0x1d;
        puVar9[0xc] = uVar14;
        if (uVar15 == 0x41) {
          uVar2 = 1;
LAB_97b83714:
          puVar9[0xc] = uVar2;
        }
        else if (uVar15 == 0x6d) {
          uVar14 = 3;
          puVar9[0xc] = 3;
          uVar15 = *(uint *)(iVar26 + 0x18);
          uVar2 = *(uint *)(iVar26 + 0x14);
          *(uint *)(iVar26 + 0x2c) = uVar15 & 0x80000000 | *(uint *)(iVar26 + 0x2c) & 0x7fffffff;
          *(char *)(iVar26 + 0x2f) = (char)(uVar15 >> 0x14);
          *(short *)(iVar26 + 0x32) = (short)uVar15;
          *(uint *)(iVar26 + 0x2c) =
               (uVar2 >> 10 & 3) << 0xc |
               (uVar2 >> 0xc & 1) << 0xe |
               (uVar2 >> 0x11 & 7) << 0x17 | *(uint *)(iVar26 + 0x2c) & 0xfc080fff | 0xd8000;
          uVar15 = *puVar9;
        }
        else if (uVar15 - 0x42 < 4) {
          uVar2 = uVar14 - 1;
          goto LAB_97b83714;
        }
        uVar2 = 0;
        iVar6 = 0;
        if (uVar14 != 0) {
          do {
            if (uVar15 == 0x41) {
              if (uVar2 != 1) goto LAB_97b837e4;
              *(byte *)(puVar9 + iVar6 * 9 + 0xf) = (byte)(*(uint *)(iVar26 + 0x24) >> 0xc) & 0xf;
              *(byte *)((int)puVar9 + iVar6 * 0x24 + 0x3d) =
                   (byte)((uint)*(undefined4 *)(iVar26 + 0x24) >> 8) & 0xf;
              *(byte *)((int)puVar9 + iVar6 * 0x24 + 0x3e) =
                   (byte)(*(uint *)(iVar26 + 0x24) >> 4) & 0xf;
              *(byte *)((int)puVar9 + iVar6 * 0x24 + 0x3f) =
                   (byte)*(undefined4 *)(iVar26 + 0x24) & 0xf;
              goto LAB_97b83af4;
            }
            if ((0x40 < uVar15) && (uVar15 < 0x46)) {
              if (1 < param_1[0xe] - 0x8b30) {
                if (uVar2 == 1) {
                  puVar9[0x44] = *(uint *)(iVar26 + 0x24) >> 5 & 7;
                  uVar3 = *(uint *)(iVar26 + 0x24);
                  goto LAB_97b83794;
                }
                goto LAB_97b837e4;
              }
              if (uVar2 != 2) goto LAB_97b837e4;
              puVar9[0x44] = *(uint *)(iVar26 + 0x2c) >> 5 & 7;
              uVar3 = *(uint *)(iVar26 + 0x2c);
LAB_97b83794:
              iVar6 = iVar6 + -1;
              puVar9[0x43] = uVar3 & 0x1f;
              goto LAB_97b83af8;
            }
LAB_97b837e4:
            iVar25 = iVar6 * 0x24;
            iVar22 = uVar2 * 8;
            puVar9[iVar6 * 9 + 0x13] = 1;
            uVar15 = puVar28[uVar2 * 2 + 4] >> 0x17 & 7;
            if (uVar15 == 1) {
              *(undefined2 *)(puVar9 + iVar6 * 9 + 0x11) = 0;
              iVar7 = param_1[0x20];
              param_1[0xd] = param_1[0xd] | 1;
              uVar1 = *(ushort *)((int)puVar28 + iVar22 + 0x16);
              puVar9[iVar6 * 9 + 0xe] = 0;
              uVar24 = iVar7 + (uint)uVar1 * 0x10;
              goto LAB_97b839f4;
            }
            if (1 < uVar15) {
              if (uVar15 == 2) {
                iVar22 = ((int (*)())_PPStreamChunkListChunkAtIndex)(uVar18,(uint)*(ushort *)((int)puVar28 + iVar22 + 0x16));
                uVar24 = *(uint *)(iVar22 + 0xc) >> 0x10 & 0x1f;
                if (uVar24 == 1) {
                  *(undefined2 *)(puVar9 + iVar6 * 9 + 0x11) = 5;
                  iVar7 = param_1[0x29];
                  uVar24 = param_1[0xd] | 0x20;
                }
                else if (uVar24 == 0x11) {
                  *(undefined2 *)(puVar9 + iVar6 * 9 + 0x11) = 3;
                  iVar7 = param_1[0x29];
                  uVar24 = param_1[0xd] | 8;
                }
                else {
                  *(undefined2 *)(puVar9 + iVar6 * 9 + 0x11) = 4;
                  iVar7 = param_1[0x29];
                  uVar24 = param_1[0xd] | 0x10;
                }
                param_1[0xd] = uVar24;
                uVar24 = iVar7 + (uint)*(ushort *)(iVar22 + 0x12) * 0x10;
                puVar9[iVar6 * 9 + 0xe] = 3;
                puVar9[iVar6 * 9 + 0x13] = *(uint *)(iVar22 + 0xc) >> 0x1a & 7;
              }
              goto LAB_97b839f4;
            }
            if (uVar15 != 0) goto LAB_97b839f4;
            iVar22 = ((int (*)())_PPStreamChunkListChunkAtIndex)(iVar19,(uint)*(ushort *)((int)puVar28 + iVar22 + 0x16));
            *(undefined2 *)(puVar9 + iVar6 * 9 + 0x11) = 2;
            switch(*(uint *)(iVar22 + 0xc) >> 0x10 & 0xf) {
            default:
              goto switchD_97b83930_caseD_0;
            case 1:
              uVar24 = param_1[0xd] | 0x10080;
              break;
            case 2:
              uVar24 = param_1[0xd] | 0x20000;
              break;
            case 3:
              uVar24 = param_1[0xd] | 0x40000;
              break;
            case 5:
              uVar24 = param_1[0xd] | 0x80000;
              break;
            case 7:
              param_1[0xd] = param_1[0xd] | 1 << (*(uint *)(iVar22 + 0xc) & 0x1f) + 0x14;
              goto switchD_97b83930_caseD_0;
            case 9:
              if ((*(uint *)(iVar22 + 0xc) & 0x1f) == 0) {
                uVar24 = param_1[0xd] | 0x100;
                break;
              }
              goto switchD_97b83930_caseD_0;
            }
            param_1[0xd] = uVar24;
switchD_97b83930_caseD_0:
            iVar7 = param_1[0x26];
            param_1[0xd] = param_1[0xd] | 4;
            uVar1 = *(ushort *)(iVar22 + 0x12);
            puVar9[iVar6 * 9 + 0xe] = 2;
            uVar24 = iVar7 + (uint)uVar1 * 0x10;
LAB_97b839f4:
            puVar9[iVar6 * 9 + 0xd] = uVar24;
            uVar15 = puVar28[uVar2 * 2 + 4];
            if ((int)uVar15 < 0) {
              *(undefined1 *)((int)puVar9 + iVar25 + 0x47) = 1;
              *(short *)(puVar9 + iVar6 * 9 + 0x10) = (short)(char)puVar28[uVar2 * 2 + 4];
              uVar15 = puVar28[uVar2 * 2 + 4];
            }
            *(byte *)((int)puVar9 + iVar25 + 0x46) = (byte)(uVar15 >> 0x1b) & 1;
            *(undefined1 *)(puVar9 + iVar6 * 9 + 0x14) = 0xf;
            if (param_1[0xe] - 0x8b30 < 2) {
              *(byte *)(puVar9 + iVar6 * 9 + 0x12) = (byte)(puVar28[uVar2 * 2 + 4] >> 0xe) & 1;
              *(byte *)((int)puVar9 + iVar25 + 0x49) =
                   ((byte)(puVar28[uVar2 * 2 + 4] >> 0xc) & 3) + 1;
            }
            else {
              *(undefined1 *)((int)puVar9 + iVar25 + 0x49) = 4;
              *(undefined1 *)(puVar9 + iVar6 * 9 + 0x12) = 0;
            }
            if (*(char *)((int)puVar9 + iVar25 + 0x49) == '\x01') {
              *(byte *)(puVar9 + iVar6 * 9 + 0xf) = (byte)(puVar28[uVar2 * 2 + 4] >> 0x15) & 3;
              *(byte *)((int)puVar9 + iVar25 + 0x3d) = (byte)(puVar28[uVar2 * 2 + 4] >> 0x15) & 3;
              *(byte *)((int)puVar9 + iVar25 + 0x3e) = (byte)(puVar28[uVar2 * 2 + 4] >> 0x15) & 3;
              bVar4 = (byte)(puVar28[uVar2 * 2 + 4] >> 0x15);
            }
            else {
              *(byte *)(puVar9 + iVar6 * 9 + 0xf) = (byte)(puVar28[uVar2 * 2 + 4] >> 0x15) & 3;
              *(byte *)((int)puVar9 + iVar25 + 0x3d) = (byte)(puVar28[uVar2 * 2 + 4] >> 0x13) & 3;
              *(byte *)((int)puVar9 + iVar25 + 0x3e) = (byte)(puVar28[uVar2 * 2 + 4] >> 0x11) & 3;
              bVar4 = (byte)(puVar28[uVar2 * 2 + 4] >> 0xf);
            }
            *(byte *)((int)puVar9 + iVar25 + 0x3f) = bVar4 & 3;
LAB_97b83af4:
            uVar15 = *puVar9;
LAB_97b83af8:
            uVar2 = uVar2 + 1;
            iVar6 = iVar6 + 1;
          } while (uVar2 < uVar14);
        }
        if (uVar20 != 0) {
          switch(uVar15) {
          case 0xf:
          case 0x1b:
          case 0x1c:
          case 0x1d:
          case 0x1e:
          case 0x4a:
          case 0x4c:
          case 0x4f:
          case 0x56:
          case 0x57:
          case 0x5a:
          case 0x5b:
            uVar20 = uVar20 & 0xfffffffd;
          }
        }
        switch(uVar15) {
        case 0x4a:
        case 0x56:
        case 0x57:
        case 0x5a:
        case 0x5b:
          uVar20 = 0;
        }
        puVar28 = puVar9 + 0x47;
        iVar26 = *(int *)(iVar26 + 8);
        if (puVar9 == (uint *)param_1[1]) {
          puVar28 = (uint *)0x0;
        }
        uVar23 = uVar23 + 1;
        puVar9 = puVar28;
      } while (uVar23 < sVar21);
    }
    if ((param_1[0xe] == 0x8804) || (param_1[0xe] == 0x8b30)) {
      iVar6 = *piVar16;
      for (iVar26 = piVar16[2]; iVar26 != 0; iVar26 = iVar26 + -1) {
        param_1[0xf] = param_1[0xf] | 1 << (*(uint *)(iVar6 + 0xc) >> 0x18 & 7);
        uVar24 = *(uint *)(iVar6 + 0xc) >> 0x18 & 7;
        if (uVar24 == 2) {
          uVar24 = param_1[0xd] | 0x1000;
LAB_97b83d90:
          param_1[0xd] = uVar24;
        }
        else if (uVar24 == 1) {
          uVar24 = param_1[0xd] | 0x4000;
          goto LAB_97b83d90;
        }
        uVar23 = *(uint *)(iVar6 + 0xc);
        uVar24 = uVar23 >> 0x15 & 0x38;
        *(undefined4 *)((int)param_1 + uVar24 + 0x44) = *(undefined4 *)(iVar6 + 0x10);
        *(uint *)((int)param_1 + uVar24 + 0x40) = uVar23;
        iVar6 = *(int *)(iVar6 + 8);
      }
    }
    if ((param_1[0xd] & 0x800) != 0) {
      uVar20 = uVar20 & 0xfffffffb;
    }
    param_1[0x49] = uVar20;
  }
  return;
}

/* _PPStreamChunkListChunkAtIndex @ 0x97b83ddc (152 bytes) */
int _PPStreamChunkListChunkAtIndex(param_1, param_2)
  undefined4 *param_1;
  uint param_2;
{
  uint uVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  for (puVar2 = (undefined1 *)*param_1; puVar2 != (undefined1 *)0x0;
      puVar2 = *(undefined1 **)(puVar2 + 8)) {
    switch(*puVar2) {
    case 0:
    case 2:
    case 3:
    case 4:
      uVar1 = (uint)*(ushort *)(puVar2 + 0x12);
      break;
    case 1:
      uVar1 = *(uint *)(puVar2 + 0xc);
      break;
    case 5:
    case 6:
    case 7:
    case 9:
    case 10:
      uVar1 = uVar3;
      break;
    case 8:
      uVar1 = *(uint *)(puVar2 + 0xc) & 0x3ffff;
      break;
    case 0xb:
      goto LAB_97b83e9c;
    default:
      goto switchD_97b83e20_default;
    }
    if (uVar1 == param_2) {
      return puVar2;
    }
switchD_97b83e20_default:
    uVar3 = uVar3 + 1;
  }
LAB_97b83e9c:
  return (undefined1 *)0x0;
}

/* _PPParserFree @ 0x97b83ea4 (48 bytes) */
int _PPParserFree(param_1)
  void *param_1;
{
  ((int (*)())_PPParserShutdown)(param_1);
  _free(param_1);
  return;
}

/* _PPParserShutdown @ 0x97b83ed4 (88 bytes) */
int _PPParserShutdown(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x448);
  while (iVar1 != 0) {
    ((int (*)())_PPParserRemoveScope)(param_1,iVar1);
    iVar1 = *(int *)(param_1 + 0x448);
  }
  uVar2 = _PPParserAttachString(param_1,0,0);
  return uVar2;
}

/* _PPParserRemoveScope @ 0x97b83f2c (68 bytes) */
int _PPParserRemoveScope(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x1c);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x448) = *(undefined4 *)(param_2 + 0x20);
    iVar1 = *(int *)(param_2 + 0x1c);
  }
  else {
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
  }
  if (*(int *)(param_2 + 0x20) == 0) {
    *(int *)(param_1 + 0x44c) = iVar1;
  }
  else {
    *(int *)(*(int *)(param_2 + 0x20) + 0x1c) = iVar1;
  }
  ((int (*)())_PPParserScopeFree)(param_2);
  return;
}

/* _PPParserScopeFree @ 0x97b83f70 (116 bytes) */
int _PPParserScopeFree(param_1)
  int *param_1;
{
  int iVar1;
  
  iVar1 = *param_1;
  while (iVar1 != 0) {
    ((int (*)())_PPParserScopeRemoveIdentifier)(param_1,iVar1);
    iVar1 = *param_1;
  }
  iVar1 = param_1[2];
  while (iVar1 != 0) {
    ((int (*)())_PPParserScopeRemoveMacro)(param_1,iVar1);
    iVar1 = param_1[2];
  }
  _free(param_1);
  return;
}

/* _PPParserScopeRemoveIdentifier @ 0x97b83fe4 (68 bytes) */
int _PPParserScopeRemoveIdentifier(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x1c);
  if (iVar1 == 0) {
    *param_1 = *(undefined4 *)(param_2 + 0x20);
    iVar1 = *(int *)(param_2 + 0x1c);
  }
  else {
    *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(param_2 + 0x20);
  }
  if (*(int *)(param_2 + 0x20) == 0) {
    param_1[1] = iVar1;
  }
  else {
    *(int *)(*(int *)(param_2 + 0x20) + 0x1c) = iVar1;
  }
  ((int (*)())_PPParserIdentifierFree)(param_2);
  return;
}

/* _PPParserIdentifierFree @ 0x97b84028 (52 bytes) */
int _PPParserIdentifierFree(param_1)
  void *param_1;
{
  _PPParserIdentifierSetName(param_1,0);
  _free(param_1);
  return;
}

/* _PPParserScopeRemoveMacro @ 0x97b8405c (68 bytes) */
int _PPParserScopeRemoveMacro(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 0x18);
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_2 + 0x1c);
    iVar1 = *(int *)(param_2 + 0x18);
  }
  else {
    *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
  }
  if (*(int *)(param_2 + 0x1c) == 0) {
    *(int *)(param_1 + 0xc) = iVar1;
  }
  else {
    *(int *)(*(int *)(param_2 + 0x1c) + 0x18) = iVar1;
  }
  ((int (*)())_PPParserMacroFree)(param_2);
  return;
}

/* _PPParserMacroFree @ 0x97b840a0 (144 bytes) */
int _PPParserMacroFree(param_1)
  undefined4 *param_1;
{
  uint uVar1;
  void *pvVar2;
  void *pvVar3;
  uint uVar4;
  
  uVar4 = 0;
  _free((void *)*param_1);
  _free((void *)param_1[1]);
  uVar1 = param_1[2];
  if (uVar1 == 0) {
    pvVar3 = (void *)param_1[3];
  }
  else {
    pvVar3 = (void *)param_1[3];
    do {
      pvVar2 = *(void **)(uVar4 * 4 + (int)pvVar3);
      if (pvVar2 != (void *)0x0) {
        _free(pvVar2);
        uVar1 = param_1[2];
        pvVar3 = (void *)param_1[3];
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
  }
  if (pvVar3 != (void *)0x0) {
    _free(pvVar3);
  }
  _free(param_1);
  return;
}

/* _PPParserGetScalars @ 0x97b84130 (200 bytes) */
int _PPParserGetScalars(param_1, param_2, param_3)
  undefined4 param_1;
  float *param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  double dVar3;
  char local_130 [256];
  char *local_30 [5];
  
  iVar2 = 0;
  while( true ) {
    iVar1 = _PPParserGetPart(param_1,local_130,1);
    if (iVar1 == 0) {
      return 0x2d;
    }
    dVar3 = (double)((double (*)())_glp_strtod)(local_130,local_30);
    *param_2 = (float)dVar3;
    if (local_30[0] != local_130 + iVar1) {
      return 0x15;
    }
    iVar2 = iVar2 + 1;
    param_2 = param_2 + 1;
    if (iVar2 == param_3) {
      return 0;
    }
    iVar1 = _PPParserGetPart(param_1,local_130,0);
    if (iVar1 == 0) break;
    if (local_130[0] != ',') {
      _PPParserReturnPart(param_1);
      return 0;
    }
  }
  return 0x2d;
}

/* _PPStreamAddConstant @ 0x97b841f8 (108 bytes) */
int _PPStreamAddConstant(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  
  puVar5 = _calloc(0x1c,1);
  uVar1 = param_2[3];
  uVar6 = *(undefined4 *)(param_1 + 0x2c);
  uVar2 = *param_2;
  uVar3 = param_2[1];
  uVar4 = param_2[2];
  *puVar5 = 10;
  *(undefined4 *)(puVar5 + 0xc) = uVar2;
  *(undefined4 *)(puVar5 + 0x10) = uVar3;
  *(undefined4 *)(puVar5 + 0x14) = uVar4;
  *(undefined4 *)(puVar5 + 0x18) = uVar1;
  _PPStreamChunkListAddChunk(uVar6,puVar5);
  return;
}

/* _PPParserParseTempDeclaration @ 0x97b84264 (468 bytes) */
int _PPParserParseTempDeclaration(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char local_140 [256];
  int local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30 [6];
  
  local_30[0] = 0;
  uVar3 = 0;
  do {
    iVar1 = _PPParserGetPart(param_1,local_140,0);
    if (iVar1 == 0) {
      return 0x2d;
    }
    iVar1 = _PPParserValidateName(param_1,local_140);
    if (iVar1 != 0) {
      return 0x12;
    }
    iVar1 = _PPParserIdentifierCreate();
    _PPParserIdentifierSetName(iVar1,local_140);
    *(undefined4 *)(iVar1 + 0xc) = 1;
    *(int *)(iVar1 + 0x14) = param_2;
    *(uint *)(iVar1 + 8) = *(int *)(*(int *)(param_1 + 0x44c) + 0x14) + uVar3;
    iVar2 = _PPParserScopeAddIdentifier(*(undefined4 *)(param_1 + 0x44c),iVar1);
    if (iVar2 != 0) {
      ((int (*)())_PPParserIdentifierFree)(iVar1);
      return 0x1c;
    }
    iVar2 = _PPParserGetPart(param_1,local_140,0);
    if (iVar2 == 0) {
      return 0x2d;
    }
    if (local_140[0] == '[') {
      _PPParserReturnPart(param_1);
      iVar2 = _PPParserParseArray(param_1,local_30);
      if (iVar2 != 0) {
        return iVar2;
      }
      *(undefined1 *)(iVar1 + 0x10) = 1;
      *(undefined4 *)(iVar1 + 4) = local_30[0];
      iVar2 = _PPParserGetPart(param_1,local_140,0);
      if (iVar2 == 0) {
        return 0x2d;
      }
    }
    uVar3 = uVar3 + *(int *)(iVar1 + 4);
    if (local_140[0] == ';') {
      iVar1 = *(int *)(param_1 + 0x44c);
      if (*(uint *)(param_1 + 0x460) < *(int *)(iVar1 + 0x14) + uVar3) {
        return 0x33;
      }
      uVar4 = 0;
      if (uVar3 != 0) {
        while( true ) {
          uVar4 = uVar4 + 1;
          local_34 = 0;
          local_38 = 0;
          local_40 = param_2 << 0x1d;
          local_3c = (uint)*(ushort *)(iVar1 + 0x16);
          ((int (*)())_PPStreamAddTempUsage)(*(undefined4 *)(param_1 + 0x1c),&local_40);
          *(int *)(*(int *)(param_1 + 0x44c) + 0x14) =
               *(int *)(*(int *)(param_1 + 0x44c) + 0x14) + 1;
          if (uVar3 <= uVar4) break;
          iVar1 = *(int *)(param_1 + 0x44c);
        }
      }
      return 0;
    }
  } while (local_140[0] == ',');
  return 0x1f;
}

/* _PPParserParseSourceSwizzle @ 0x97b84438 (396 bytes) */
int _PPParserParseSourceSwizzle(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 *param_3;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined1 local_110 [256];
  
  iVar4 = _PPParserGetPart(param_1,local_110,0);
  uVar6 = 0;
  uVar1 = 0x2d;
  if (iVar4 != 0) {
    if (iVar4 != 1) {
      if (iVar4 != 4) {
        return 0xd;
      }
    }
    else {
      *param_3 = 1;
    }
    uVar7 = 0;
    iVar5 = 0;
    do {
      switch(local_110[iVar5]) {
      case 0x61:
        uVar6 = uVar6 | 2;
        break;
      case 0x62:
        uVar6 = uVar6 | 2;
        goto LAB_97b84574;
      default:
        goto switchD_97b844cc_caseD_63;
      case 0x67:
        uVar6 = uVar6 | 2;
        goto LAB_97b84568;
      case 0x72:
        uVar6 = uVar6 | 2;
        goto LAB_97b8455c;
      case 0x77:
        uVar6 = uVar6 | 1;
        break;
      case 0x78:
        uVar6 = uVar6 | 1;
LAB_97b8455c:
        iVar3 = 0;
        goto LAB_97b84584;
      case 0x79:
        uVar6 = uVar6 | 1;
LAB_97b84568:
        iVar3 = 1;
        goto LAB_97b84584;
      case 0x7a:
        uVar6 = uVar6 | 1;
LAB_97b84574:
        iVar3 = 2;
        goto LAB_97b84584;
      }
      iVar3 = 3;
LAB_97b84584:
      if (uVar7 == 1) {
        uVar2 = iVar3 << 0x13 | *param_2 & 0xffe7ffff;
LAB_97b845d4:
        *param_2 = uVar2;
      }
      else {
        if (uVar7 == 0) {
          uVar2 = iVar3 << 0x15 | *param_2 & 0xff9fffff;
          goto LAB_97b845d4;
        }
        if (uVar7 == 2) {
          uVar2 = iVar3 << 0x11 | *param_2 & 0xfff9ffff;
          goto LAB_97b845d4;
        }
        if (uVar7 == 3) {
          uVar2 = iVar3 << 0xf | *param_2 & 0xfffe7fff;
          goto LAB_97b845d4;
        }
      }
      if (iVar4 != 1) {
        iVar5 = iVar5 + 1;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < 4);
    if ((uVar6 == 3) || ((uVar6 == 2 && ((*(uint *)(param_1 + 0x48c) & 2) == 0)))) {
switchD_97b844cc_caseD_63:
      uVar1 = 0xd;
    }
    else {
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* _PPParserParseDestinationMask @ 0x97b8462c (412 bytes) */
int _PPParserParseDestinationMask(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 local_110 [260];
  
  uVar2 = _PPParserGetPart(param_1,local_110,0);
  uVar5 = 0;
  uVar3 = 0x2d;
  if (uVar2 != 0) {
    uVar4 = 0;
    *param_2 = *param_2 & 0xfffe1fff;
    if (uVar2 != 0) {
      do {
        switch(local_110[uVar4]) {
        case 0x61:
          if ((*param_2 & 0x10000) != 0) {
            return 0xc;
          }
          uVar1 = *param_2 | 0x10000;
          break;
        case 0x62:
          if ((*param_2 & 0x8000) != 0) {
            return 0xc;
          }
          uVar1 = *param_2 | 0x8000;
          break;
        default:
          goto LAB_97b8481c;
        case 0x67:
          if ((*param_2 & 0x4000) != 0) {
            return 0xc;
          }
          uVar1 = *param_2 | 0x4000;
          break;
        case 0x72:
          if ((*param_2 & 0x2000) != 0) {
            return 0xc;
          }
          uVar1 = *param_2 | 0x2000;
          break;
        case 0x77:
          if ((*param_2 & 0x10000) != 0) {
            return 0xc;
          }
          uVar1 = *param_2 | 0x10000;
          goto LAB_97b84778;
        case 0x78:
          if ((*param_2 & 0x2000) != 0) {
            return 0xc;
          }
          uVar1 = *param_2 | 0x2000;
          goto LAB_97b84778;
        case 0x79:
          if ((*param_2 & 0x4000) != 0) {
            return 0xc;
          }
          uVar1 = *param_2 | 0x4000;
          goto LAB_97b84778;
        case 0x7a:
          if ((*param_2 & 0x8000) != 0) {
            return 0xc;
          }
          uVar1 = *param_2 | 0x8000;
LAB_97b84778:
          *param_2 = uVar1;
          uVar5 = uVar5 | 1;
          goto LAB_97b847e8;
        }
        *param_2 = uVar1;
        uVar5 = uVar5 | 2;
LAB_97b847e8:
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar2);
      if ((uVar5 == 3) || ((uVar5 == 2 && ((*(uint *)(param_1 + 0x48c) & 2) == 0)))) {
LAB_97b8481c:
        return 0xc;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}

/* _PPParserParseTextureSourceVar @ 0x97b84830 (704 bytes) */
int _PPParserParseTextureSourceVar(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint extraout_r4;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  char local_140 [256];
  uint local_40 [6];
  
  iVar2 = _PPParserGetPart(param_1,local_140,0);
  iVar3 = 0x2d;
  if (iVar2 != 0) {
    iVar2 = _memcmp(local_140,"texture",8);
    iVar3 = 0xe;
    if (iVar2 == 0) {
      iVar2 = _PPParserGetPart(param_1,local_140,0);
      iVar3 = 0x2d;
      if (iVar2 != 0) {
        if (local_140[0] == '[') {
          _PPParserReturnPart(param_1);
          iVar2 = _PPParserParseArray(param_1,local_40);
          if (iVar2 != 0) {
            return iVar2;
          }
          if (*(uint *)(param_1 + 0x474) <= local_40[0]) {
            return 0x38;
          }
          iVar2 = _PPParserGetPart(param_1,local_140,0);
          if (iVar2 == 0) {
            return 0x2d;
          }
        }
        else {
          local_40[0] = 0;
        }
        iVar3 = 0x1f;
        if (local_140[0] == ',') {
          iVar2 = _PPParserGetPart(param_1,local_140,0);
          uVar1 = local_40[0];
          iVar3 = 0x2d;
          if (iVar2 != 0) {
            uVar4 = *(uint *)(param_1 + 0x34);
            uVar5 = *(uint *)(param_1 + 0x38);
            ((int (*)())___lshrdi3)(uVar4,uVar5,local_40[0] << 2);
            iVar2 = _memcmp(local_140,"CUBE",5);
            uVar6 = 0;
            if (iVar2 != 0) {
              iVar2 = _memcmp(local_140,"3D",3);
              uVar6 = 1;
              if (iVar2 != 0) {
                iVar2 = _memcmp(local_140,"RECT",5);
                uVar6 = 2;
                if (iVar2 != 0) {
                  iVar2 = _memcmp(local_140,"2D",3);
                  uVar6 = 3;
                  if (iVar2 != 0) {
                    iVar2 = _memcmp(local_140,"1D",3);
                    uVar6 = 4;
                    if (iVar2 != 0) {
                      iVar2 = _memcmp(local_140,"SHADOWRECT",0xb);
                      uVar6 = 5;
                      if (iVar2 != 0) {
                        iVar2 = _memcmp(local_140,"SHADOW2D",9);
                        uVar6 = 6;
                        if (iVar2 != 0) {
                          iVar2 = _memcmp(local_140,"SHADOW1D",9);
                          uVar6 = 7;
                          if (iVar2 != 0) {
                            return 0xe;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            if ((extraout_r4 & 0xf) == 0xf) {
              iVar2 = uVar1 << 2;
              uVar7 = ((int (*)())___ashldi3)(0,0xf,iVar2);
              uVar4 = uVar4 & ~(uint)((ulonglong)uVar7 >> 0x20);
              uVar5 = uVar5 & ~(uint)uVar7;
              *(uint *)(param_1 + 0x34) = uVar4;
              *(uint *)(param_1 + 0x38) = uVar5;
              uVar7 = ((int (*)())___ashldi3)(0,uVar6,iVar2);
              *(uint *)(param_1 + 0x34) = uVar4 | (uint)((ulonglong)uVar7 >> 0x20);
              *(uint *)(param_1 + 0x38) = uVar5 | (uint)uVar7;
            }
            else if ((extraout_r4 & 0xf) != uVar6) {
              return 0x28;
            }
            iVar3 = 0;
            *param_2 = uVar1 & 0x1f | uVar6 << 5 | *param_2 & 0xffffff00;
          }
        }
      }
    }
  }
  return iVar3;
}

/* ___lshrdi3 @ 0x97b84af0 (96 bytes) */
undefined8 ___lshrdi3(param_1, param_2, param_3)
  uint param_1;
  uint param_2;
  uint param_3;
{
  uint uVar1;
  undefined4 uStack_30;
  
  if (param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  uVar1 = 0x20 - param_3;
  if ((int)uVar1 < 1) {
    uVar1 = param_1 >> (-uVar1 & 0x3f);
    uStack_30 = 0;
  }
  else {
    uStack_30 = param_1 >> (param_3 & 0x3f);
    uVar1 = param_2 >> (param_3 & 0x3f) | param_1 << (uVar1 & 0x3f);
  }
  return CONCAT44(uVar1,uStack_30);
}

/* ___ashldi3 @ 0x97b84b50 (96 bytes) */
undefined8 ___ashldi3(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
  uint uVar1;
  undefined4 uStack_2c;
  
  if (param_3 == 0) {
    return CONCAT44(param_2,param_1);
  }
  uVar1 = 0x20 - param_3;
  if ((int)uVar1 < 1) {
    uVar1 = param_2 << (-uVar1 & 0x3f);
    uStack_2c = 0;
  }
  else {
    uStack_2c = param_2 << (param_3 & 0x3f);
    uVar1 = param_1 << (param_3 & 0x3f) | param_2 >> (uVar1 & 0x3f);
  }
  return CONCAT44(uStack_2c,uVar1);
}

/* _PPStreamGetTexOperationCount @ 0x97b84bb0 (60 bytes) */
int _PPStreamGetTexOperationCount(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = **(int **)(param_1 + 0x20);
  if (iVar2 != 0) {
    do {
      if ((*(uint *)(iVar2 + 0xc) >> 0x12 & 0xff) - 0x42 < 3) {
        iVar1 = iVar1 + 1;
      }
      iVar2 = *(int *)(iVar2 + 8);
    } while (iVar2 != 0);
    return iVar1;
  }
  return iVar1;
}

/* _PPEmulatorFree @ 0x97b84bec (60 bytes) */
int _PPEmulatorFree(param_1)
  void *param_1;
{
  _InterpreterFree(*(undefined4 *)((int)param_1 + 0xdf0));
  _free(*(void **)((int)param_1 + 0xd84));
  _free(param_1);
  return;
}

/* _PPStreamFree @ 0x97b84c28 (140 bytes) */
int _PPStreamFree(param_1)
  void *param_1;
{
  undefined4 extraout_r3;
  
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)((int)param_1 + 4));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)((int)param_1 + 8));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)((int)param_1 + 0xc));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)((int)param_1 + 0x10));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)((int)param_1 + 0x14));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)((int)param_1 + 0x18));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)((int)param_1 + 0x1c));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)((int)param_1 + 0x20));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)((int)param_1 + 0x24));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)((int)param_1 + 0x2c));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)((int)param_1 + 0x28));
  ((int (*)())_PPStreamChunkListFree)(*(undefined4 *)((int)param_1 + 0x30));
  _free(param_1);
  return extraout_r3;
}

/* _PPEmulatorProgramFree @ 0x97b84cb4 (180 bytes) */
int _PPEmulatorProgramFree(param_1)
  undefined4 *param_1;
{
  if (param_1[7] != 0) {
    _glpDCBFree(param_1[7]);
  }
  if (param_1[8] != 0) {
    _glpDCBFree(param_1[8]);
  }
  if (param_1[5] != 0) {
    _glpDCBFree(param_1[5]);
  }
  if (param_1[6] != 0) {
    _glpDCBFree(param_1[6]);
  }
  if ((void *)*param_1 != (void *)0x0) {
    _free((void *)*param_1);
    *param_1 = 0;
  }
  if ((void *)param_1[0x2c] != (void *)0x0) {
    _free((void *)param_1[0x2c]);
    param_1[0x2c] = 0;
  }
  ((int (*)())_PPEmulatorProgramInitialiseHandleBanks)(param_1,0,0,0,0);
  _free(param_1);
  return;
}

/* _PPParserParseAliasDeclaration @ 0x97b84d68 (368 bytes) */
int _PPParserParseAliasDeclaration(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  char local_130 [256];
  undefined4 local_30;
  undefined4 local_2c;
  
  iVar2 = _PPParserGetPart(param_1,local_130,0);
  uVar1 = 0x2d;
  if (iVar2 != 0) {
    uVar3 = _PPParserMacroCreate();
    _PPParserMacroSetSearchString(param_1,uVar3,local_130,iVar2);
    iVar2 = _PPParserGetPart(param_1,local_130,0);
    uVar1 = 0x2d;
    if ((iVar2 != 0) && (uVar1 = 10, local_130[0] == '=')) {
      local_30 = *(undefined4 *)(param_1 + 0xc);
      iVar2 = 0;
      local_2c = *(undefined4 *)(param_1 + 0x10);
      while( true ) {
        iVar4 = _PPParserGetPart(param_1,local_130,0);
        uVar1 = 0x2d;
        if (iVar4 == 0) break;
        if (local_130[0] == ';') {
          if (iVar2 == 0) {
            return 10;
          }
          *(undefined4 *)(param_1 + 0x10) = local_2c;
          *(undefined4 *)(param_1 + 0xc) = local_30;
          pvVar5 = _malloc(iVar2 + 2);
          iVar2 = 0;
          while( true ) {
            iVar4 = _PPParserGetPart(param_1,(int)pvVar5 + iVar2,0);
            if (iVar4 == 0) {
              return 0x2d;
            }
            if (*(char *)((int)pvVar5 + iVar2) == ';') break;
            *(undefined1 *)((int)pvVar5 + iVar2 + iVar4) = 0x20;
            iVar2 = iVar2 + iVar4 + 1;
          }
          *(undefined1 *)((int)pvVar5 + iVar2) = 0;
          ((int (*)())_PPParserMacroSetReplaceString)(param_1,uVar3,pvVar5);
          _PPParserScopeAddMacro(*(undefined4 *)(param_1 + 0x44c),uVar3);
          return 0;
        }
        iVar2 = iVar2 + iVar4 + 1;
      }
    }
  }
  return uVar1;
}

/* _PPParserMacroSetReplaceString @ 0x97b84ed8 (64 bytes) */
int _PPParserMacroSetReplaceString(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
{
  if (*(void **)(param_2 + 4) != (void *)0x0) {
    _free(*(void **)(param_2 + 4));
  }
  *(undefined4 *)(param_2 + 4) = param_3;
  return;
}

/* _PPParserMacroGetReplaceString @ 0x97b84f18 (320 bytes) */
int _PPParserMacroGetReplaceString(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  char cVar1;
  int iVar2;
  size_t sVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  uint uVar8;
  size_t sVar9;
  
  iVar5 = 0;
  cVar1 = **(char **)(param_1 + 4);
  pcVar6 = *(char **)(param_1 + 4);
  do {
    if (cVar1 == '\0') {
      if (param_4 != 0) {
        *(undefined1 *)(param_4 + iVar5) = 0;
      }
      return iVar5;
    }
    for (sVar9 = 0; (cVar1 = pcVar6[sVar9], cVar1 != ' ' && (cVar1 != '\n')); sVar9 = sVar9 + 1) {
    }
    uVar8 = 0;
    pcVar7 = pcVar6 + sVar9 + 1;
    if (*(int *)(param_1 + 8) != 0) {
      do {
        iVar2 = uVar8 * 4;
        sVar3 = _strlen(*(char **)(iVar2 + *(int *)(param_1 + 0xc)));
        if ((sVar9 == sVar3) &&
           (iVar4 = _strncmp(pcVar6,*(char **)(iVar2 + *(int *)(param_1 + 0xc)),sVar9), iVar4 == 0))
        {
          pcVar6 = *(char **)(iVar2 + param_3);
          sVar9 = _strlen(pcVar6);
          break;
        }
        uVar8 = uVar8 + 1;
      } while (uVar8 < *(uint *)(param_1 + 8));
    }
    if (param_4 != 0) {
      _memmove((void *)(param_4 + iVar5),pcVar6,sVar9 + 1);
      *(char *)(param_4 + iVar5 + sVar9) = cVar1;
    }
    iVar5 = iVar5 + sVar9 + 1;
    cVar1 = *pcVar7;
    pcVar6 = pcVar7;
  } while( true );
}

/* _PPParserParseSwizzleCode @ 0x97b85058 (620 bytes) */
int _PPParserParseSwizzleCode(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char local_120;
  char local_11f;
  
  uVar3 = 0;
  iVar4 = 0;
  do {
    uVar1 = _PPParserGetPart(param_1,&local_120,0);
    iVar5 = 0;
    if (uVar1 == 0) {
      return 0x2d;
    }
    if (2 < uVar1) {
      return 0xf;
    }
    if (local_120 == '+') {
LAB_97b850c8:
      if (uVar1 == 2) {
        local_120 = local_11f;
      }
      else {
        iVar2 = _PPParserGetPart(param_1,&local_120,0);
        if (iVar2 == 0) {
          return 0x2d;
        }
        if (iVar2 != 1) {
          return 0xf;
        }
      }
    }
    else {
      if (local_120 == '-') {
        iVar5 = 1;
        goto LAB_97b850c8;
      }
      if (uVar1 == 2) {
        return 0xf;
      }
    }
    switch(local_120) {
    case '0':
      uVar1 = 9;
      break;
    case '1':
      uVar1 = 10;
      if (iVar5 == 0) {
        uVar1 = 8;
      }
      break;
    default:
      return 0xf;
    case 'a':
      uVar3 = uVar3 | 2;
      goto LAB_97b85300;
    case 'b':
      uVar3 = uVar3 | 2;
      goto LAB_97b852e8;
    case 'g':
      uVar3 = uVar3 | 2;
      goto LAB_97b852d0;
    case 'r':
      uVar3 = uVar3 | 2;
      goto LAB_97b852c0;
    case 'w':
      uVar3 = uVar3 | 1;
LAB_97b85300:
      uVar1 = 7;
      if (iVar5 == 0) {
        uVar1 = 3;
      }
      break;
    case 'x':
      uVar3 = uVar3 | 1;
LAB_97b852c0:
      uVar1 = iVar5 << 2;
      break;
    case 'y':
      uVar3 = uVar3 | 1;
LAB_97b852d0:
      uVar1 = 5;
      if (iVar5 == 0) {
        uVar1 = 1;
      }
      break;
    case 'z':
      uVar3 = uVar3 | 1;
LAB_97b852e8:
      uVar1 = 6;
      if (iVar5 == 0) {
        uVar1 = 2;
      }
    }
    if ((uVar3 == 3) || ((uVar3 == 2 && ((*(uint *)(param_1 + 0x48c) & 2) == 0)))) {
      return 0xd;
    }
    if (iVar4 == 1) {
      uVar1 = uVar1 << 8 | *param_2 & 0xfffff0ff;
LAB_97b85380:
      *param_2 = uVar1;
LAB_97b85398:
      if (iVar4 == 3) {
        return 0;
      }
    }
    else {
      if (iVar4 == 0) {
        uVar1 = uVar1 << 0xc | *param_2 & 0xffff0fff;
        goto LAB_97b85380;
      }
      if (iVar4 == 2) {
        uVar1 = uVar1 << 4 | *param_2 & 0xffffff0f;
        goto LAB_97b85380;
      }
      if (iVar4 == 3) {
        *param_2 = uVar1 | *param_2 & 0xfffffff0;
        goto LAB_97b85398;
      }
    }
    iVar5 = _PPParserGetPart(param_1,&local_120,0);
    if (iVar5 == 0) {
      return 0x2d;
    }
    iVar4 = iVar4 + 1;
    if (local_120 != ',') {
      return 0xf;
    }
  } while( true );
}

/* __dyld_func_lookup @ 0x97b853f8 (32 bytes) */
int __dyld_func_lookup()
{
  undefined4 uVar1;
  
                    
                    
  uVar1 = (*dyld_func_lookup_pointer)();
  return uVar1;
}

/* ___initialize_Cplusplus @ 0x97b85418 (88 bytes) */
int ___initialize_Cplusplus()
{
  undefined4 uStack_28;
  
  ((int (*)())__dyld_func_lookup)();
  if ((void *)uStack_28 != (void *)0) {
    ((int (*)())uStack_28)(PTR___mh_dylib_header_a7b7c0a0);
  }
  return;
}

/* FUN_97b85470 @ 0x97b85470 (32 bytes) */
int FUN_97b85470()
{
  ((int (*)())__dyld_func_lookup)();
  return;
}

/* InitProcess @ 0x97b85490 (36 bytes) */
int InitProcess()
{
  InitializeGlobalPools();
  return 1;
}

/* DetachProcess @ 0x97b854b4 (36 bytes) */
int DetachProcess()
{
  FreeGlobalPools();
  return 1;
}

/* _InitStringTable @ 0x97b854d8 (84 bytes) */
int _InitStringTable(param_1)
  undefined4 *param_1;
{
  void *pvVar1;
  
  pvVar1 = _malloc(0x4000);
  *param_1 = pvVar1;
  if (pvVar1 != (void *)0x0) {
    param_1[2] = 0x4000;
    param_1[1] = 1;
  }
  return (uint)(pvVar1 != (void *)0x0);
}

/* _FreeStringTable @ 0x97b8552c (72 bytes) */
int _FreeStringTable(param_1)
  undefined4 *param_1;
{
  undefined4 extraout_r3;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((void *)*param_1 != (void *)0x0) {
    _free((void *)*param_1);
    uVar1 = extraout_r3;
  }
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  return uVar1;
}

/* _HashString @ 0x97b85574 (68 bytes) */
int _HashString(param_1)
  char *param_1;
{
  char cVar1;
  uint uVar2;
  
  uVar2 = 0;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    param_1 = param_1 + 1;
    uVar2 = uVar2 * 0x34c3 + cVar1 * 0xc5 ^ (int)uVar2 >> 2;
    cVar1 = *param_1;
  }
  return uVar2 & 0x7fffffff;
}

/* _HashString2 @ 0x97b855b8 (64 bytes) */
int _HashString2(param_1)
  char *param_1;
{
  int iVar1;
  uint uVar2;
  char cVar3;
  
  cVar3 = *param_1;
  uVar2 = 0;
  if (cVar3 != '\0') {
    do {
      iVar1 = (int)cVar3;
      param_1 = param_1 + 1;
      cVar3 = *param_1;
      uVar2 = uVar2 * 0x2d9 + iVar1 * 0x25 ^ (int)uVar2 >> 1;
    } while (cVar3 != '\0');
    return uVar2;
  }
  return uVar2;
}

/* _AddString @ 0x97b855f8 (156 bytes) */
int _AddString(param_1, param_2)
  int *param_1;
  char *param_2;
{
  size_t sVar1;
  void *pvVar2;
  int iVar3;
  
  sVar1 = _strlen(param_2);
  iVar3 = param_1[1];
  if (param_1[2] <= (int)(iVar3 + sVar1 + 1)) {
    pvVar2 = _malloc(param_1[2] << 1);
    _memcpy(pvVar2,(void *)*param_1,param_1[2]);
    _free((void *)*param_1);
    iVar3 = param_1[1];
    *param_1 = (int)pvVar2;
  }
  _strcpy((char *)(*param_1 + iVar3),param_2);
  param_1[1] = param_1[1] + sVar1 + 1;
  return iVar3;
}

/* _InitHashTable @ 0x97b85694 (160 bytes) */
int _InitHashTable(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  undefined4 uVar4;
  int iVar5;
  
  pvVar3 = _malloc(param_2 << 3);
  *param_1 = (int)pvVar3;
  uVar4 = 0;
  if (pvVar3 != (void *)0x0) {
    iVar5 = 0;
    param_1[1] = param_2;
    if (0 < param_2) {
      do {
        iVar1 = iVar5 * 8;
        iVar5 = iVar5 + 1;
        *(undefined4 *)(iVar1 + *param_1) = 0;
        *(undefined4 *)(iVar1 + *param_1 + 4) = 0;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
    iVar5 = 4;
    param_1[2] = 0;
    piVar2 = param_1 + 3;
    do {
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    uVar4 = 1;
  }
  return uVar4;
}

/* _FreeHashTable @ 0x97b85734 (72 bytes) */
int _FreeHashTable(param_1)
  undefined4 *param_1;
{
  if ((void *)*param_1 != (void *)0x0) {
    _free((void *)*param_1);
  }
  param_1[2] = 0;
  *param_1 = 0;
  param_1[1] = 0;
  return;
}

/* _GrowAtomTable @ 0x97b8577c (256 bytes) */
int _GrowAtomTable(param_1, param_2)
  int param_1;
  int param_2;
{
  void *pvVar1;
  void *pvVar2;
  
  if (*(int *)(param_1 + 0x34) < param_2) {
    if (*(void **)(param_1 + 0x28) == (void *)0x0) {
      pvVar1 = _malloc(param_2 << 2);
      pvVar2 = _malloc(param_2 << 2);
      *(undefined4 *)(param_1 + 0x34) = 0;
    }
    else {
      pvVar1 = _realloc(*(void **)(param_1 + 0x28),param_2 << 2);
      pvVar2 = _realloc(*(void **)(param_1 + 0x2c),param_2 << 2);
    }
    if ((pvVar1 == (void *)0x0) || (pvVar2 == (void *)0x0)) {
      if (pvVar1 != (void *)0x0) {
        *(void **)(param_1 + 0x28) = pvVar1;
      }
      if (pvVar2 != (void *)0x0) {
        *(void **)(param_1 + 0x28) = pvVar2;
      }
      return 0xffffffff;
    }
    _memset((void *)(*(int *)(param_1 + 0x34) * 4 + (int)pvVar1),0,
            (param_2 - *(int *)(param_1 + 0x34)) * 4);
    _memset((void *)(*(int *)(param_1 + 0x34) * 4 + (int)pvVar2),0,
            (param_2 - *(int *)(param_1 + 0x34)) * 4);
    *(int *)(param_1 + 0x34) = param_2;
    *(void **)(param_1 + 0x28) = pvVar1;
    *(void **)(param_1 + 0x2c) = pvVar2;
  }
  return 0;
}

/* _lReverse @ 0x97b8587c (64 bytes) */
int _lReverse(param_1)
  uint param_1;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = 0;
  if (param_1 != 0) {
    do {
      uVar1 = param_1 & 1;
      param_1 = param_1 >> 1;
      iVar3 = iVar3 + 1;
      uVar2 = uVar2 << 1 | uVar1;
    } while (param_1 != 0);
    if (0x13 < iVar3) {
      return uVar2;
    }
  }
  return uVar2 << (0x14U - iVar3 & 0x3f);
}

/* _AllocateAtom @ 0x97b858bc (120 bytes) */
int _AllocateAtom(param_1)
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (*(int *)(param_1 + 0x34) <= iVar1) {
    ((int (*)())_GrowAtomTable)(param_1,iVar1 << 1);
    iVar1 = *(int *)(param_1 + 0x30);
  }
  *(undefined4 *)(iVar1 * 4 + *(int *)(param_1 + 0x28)) = 0xffffffff;
  uVar2 = ((int (*)())_lReverse)(*(undefined4 *)(param_1 + 0x30));
  *(undefined4 *)(*(int *)(param_1 + 0x30) * 4 + *(int *)(param_1 + 0x2c)) = uVar2;
  iVar1 = *(int *)(param_1 + 0x30);
  *(int *)(param_1 + 0x30) = iVar1 + 1;
  return iVar1;
}

/* _SetAtomValue @ 0x97b85934 (40 bytes) */
int _SetAtomValue(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined4 *)(param_2 * 4 + *(int *)(param_1 + 0x28)) =
       *(undefined4 *)(param_3 * 8 + *(int *)(param_1 + 0xc));
  *(int *)(param_3 * 8 + *(int *)(param_1 + 0xc) + 4) = param_2;
  return;
}

/* _FindHashLoc @ 0x97b8595c (264 bytes) */
int _FindHashLoc(param_1, param_2)
  int *param_1;
  char *param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int local_30;
  int local_2c [4];
  
  iVar4 = ((int (*)())_HashString)(param_2);
  iVar4 = iVar4 - (iVar4 / param_1[4]) * param_1[4];
  iVar2 = *(int *)(iVar4 * 8 + param_1[3]);
  if ((iVar2 != 0) && (iVar2 = _strcmp(param_2,(char *)(*param_1 + iVar2)), iVar2 != 0)) {
    iVar6 = 0;
    iVar2 = ((int (*)())_HashString2)(param_2);
    piVar5 = &local_30;
    local_30 = iVar4;
    do {
      uVar1 = iVar4 + iVar2 & 0x7fffffff;
      iVar4 = uVar1 - ((int)uVar1 / param_1[4]) * param_1[4];
      iVar3 = *(int *)(iVar4 * 8 + param_1[3]);
      if (iVar3 == 0) {
        param_1[iVar6 + 6] = param_1[iVar6 + 6] + 1;
        return iVar4;
      }
      iVar3 = _strcmp(param_2,(char *)(*param_1 + iVar3));
      if (iVar3 == 0) {
        return iVar4;
      }
      iVar6 = iVar6 + 1;
      piVar5 = piVar5 + 1;
      *piVar5 = iVar4;
    } while (iVar6 < 3);
    iVar4 = -1;
  }
  return iVar4;
}

/* _IncreaseHashTableSize @ 0x97b85a64 (192 bytes) */
int _IncreaseHashTableSize(param_1)
  void *param_1;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int local_50 [3];
  int local_44;
  int local_40;
  int local_28;
  int local_20;
  
  _memcpy(local_50,param_1,0x38);
  iVar1 = _InitAtomTable(param_1,local_40 * 2 + 1);
  uVar2 = 0;
  if (iVar1 != 0) {
    iVar1 = *(int *)((int)param_1 + 0x30);
    if (iVar1 < local_20) {
      do {
        iVar4 = local_50[0] + *(int *)(iVar1 * 4 + local_28);
        iVar3 = ((int (*)())_FindHashLoc)(local_50,iVar4);
        _AddAtomFixed(param_1,iVar4,*(undefined4 *)(iVar3 * 8 + local_44 + 4));
        iVar1 = iVar1 + 1;
      } while (iVar1 < local_20);
    }
    _FreeAtomTable(local_50);
    uVar2 = 1;
  }
  return uVar2;
}

/* _LookUpAddStringHash @ 0x97b85b24 (144 bytes) */
int _LookUpAddStringHash(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  while( true ) {
    iVar2 = ((int (*)())_FindHashLoc)(param_1,param_2);
    if (-1 < iVar2) break;
    ((int (*)())_IncreaseHashTableSize)(param_1);
  }
  iVar1 = iVar2 * 8;
  if (*(int *)(iVar1 + *(int *)(param_1 + 0xc)) == 0) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
    uVar3 = ((int (*)())_AddString)(param_1,param_2);
    *(undefined4 *)(iVar1 + *(int *)(param_1 + 0xc)) = uVar3;
    *(undefined4 *)(iVar1 + *(int *)(param_1 + 0xc) + 4) = 0;
  }
  return iVar2;
}

/* _LookUpAddString @ 0x97b85bb4 (104 bytes) */
int _LookUpAddString(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  int iVar2;
  
  iVar1 = ((int (*)())_LookUpAddStringHash)(param_1,param_2);
  iVar2 = *(int *)(iVar1 * 8 + *(int *)(param_1 + 0xc) + 4);
  if (iVar2 == 0) {
    iVar2 = ((int (*)())_AllocateAtom)(param_1);
    ((int (*)())_SetAtomValue)(param_1,iVar2,iVar1);
  }
  return iVar2;
}

/* _GetAtomString @ 0x97b85c1c (144 bytes) */
int _GetAtomString(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  
  if ((0 < param_2) && (param_2 < param_1[0xc])) {
    iVar1 = *(int *)(param_2 * 4 + param_1[10]);
    if ((0 < iVar1) && (iVar1 < param_1[1])) {
      return (char *)(*param_1 + iVar1);
    }
    return "<internal error: bad soffset>";
  }
  if (param_2 == 0) {
    return "<null atom>";
  }
  if (param_2 == -1) {
    return "<EOF>";
  }
  return "<invalid atom>";
}

/* _GetReversedAtom @ 0x97b85cac (44 bytes) */
int _GetReversedAtom(param_1, param_2)
  int param_1;
  int param_2;
{
  if ((0 < param_2) && (param_2 < *(int *)(param_1 + 0x30))) {
    return *(undefined4 *)(param_2 * 4 + *(int *)(param_1 + 0x2c));
  }
  return 0;
}

