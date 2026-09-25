#include "decls.h"

/* FUN_000f4ddc @ 0xf4ddc (512 bytes) */
int FUN_000f4ddc(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  int iVar10;
  uint *puVar11;
  int *piVar12;
  int iVar13;
  uint local_1d8 [4];
  undefined4 local_1c8 [4];
  undefined4 local_1b8 [24];
  int aiStack_158 [75];
  int aiStack_2c [3];
  
  _memcpy(aiStack_158,&DAT_001aa87c,300);
  cVar1 = *(char *)(param_3 + 0x15c);
  puVar9 = local_1b8;
  puVar11 = local_1d8;
  uVar4 = 0;
  iVar13 = 4;
  puVar5 = puVar11;
  puVar8 = puVar9;
  iVar10 = param_3;
  do {
    uVar2 = uVar4 & 0x3f;
    uVar7 = *(undefined4 *)(iVar10 + 0x20);
    *puVar8 = *(undefined4 *)(iVar10 + 0x1c);
    uVar4 = uVar4 + 1;
    puVar8[1] = uVar7;
    iVar10 = iVar10 + 0x18;
    *puVar5 = (int)cVar1 >> uVar2 & 1;
    puVar8 = puVar8 + 6;
    puVar5 = puVar5 + 1;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  local_1c8[0] = *(undefined4 *)(param_1 + 8);
  local_1c8[1] = *(undefined4 *)(param_1 + 0xc);
  local_1c8[2] = *(undefined4 *)(param_1 + 0x10);
  local_1c8[3] = *(undefined4 *)(param_1 + 0x14);
  if (*(int *)(&DAT_001aa86c + (4 - param_2) * 4) < 0xf) {
    piVar12 = aiStack_158 + *(int *)(&DAT_001aa86c + (4 - param_2) * 4) * 5;
    do {
      iVar13 = 4;
      uVar4 = 0;
      piVar6 = piVar12;
      iVar10 = param_3;
      do {
        iVar3 = piVar6[1];
        if (iVar3 < 0) {
          *(undefined4 *)(iVar10 + 0x1c) = 0;
          *(undefined4 *)(iVar10 + 0x20) = 0;
          *(byte *)(param_3 + 0x15c) = *(byte *)(param_3 + 0x15c) & ~(byte)(1 << (uVar4 & 0x3f));
        }
        else {
          uVar7 = local_1b8[iVar3 * 6];
          *(undefined4 *)(iVar10 + 0x20) = local_1b8[iVar3 * 6 + 1];
          *(undefined4 *)(iVar10 + 0x1c) = uVar7;
          *(byte *)(param_3 + 0x15c) = (byte)(1 << (uVar4 & 0x3f)) | *(byte *)(param_3 + 0x15c);
        }
        uVar4 = uVar4 + 1;
        piVar6 = piVar6 + 1;
        iVar10 = iVar10 + 0x18;
        iVar13 = iVar13 + -1;
      } while (iVar13 != 0);
      iVar10 = *piVar12;
      piVar12 = piVar12 + 5;
      FUN_00194d44(local_1c8[iVar10],param_3);
    } while (piVar12 != aiStack_2c);
  }
  iVar13 = 4;
  uVar4 = 0;
  iVar10 = param_3;
  do {
    uVar7 = puVar9[1];
    *(undefined4 *)(iVar10 + 0x1c) = *puVar9;
    *(undefined4 *)(iVar10 + 0x20) = uVar7;
    uVar2 = *puVar11;
    puVar11 = puVar11 + 1;
    if (uVar2 == 0) {
      *(byte *)(param_3 + 0x15c) = *(byte *)(param_3 + 0x15c) & ~(byte)(1 << (uVar4 & 0x3f));
    }
    else {
      *(byte *)(param_3 + 0x15c) = (byte)(1 << (uVar4 & 0x3f)) | *(byte *)(param_3 + 0x15c);
    }
    uVar4 = uVar4 + 1;
    puVar9 = puVar9 + 6;
    iVar10 = iVar10 + 0x18;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  return;
}

/* FUN_000f4fdc @ 0xf4fdc (352 bytes) */
int FUN_000f4fdc(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  int aiStack_9c [4];
  int local_8c;
  undefined4 local_88 [29];
  
  aiStack_9c[1] = param_1[2];
  aiStack_9c[2] = param_1[3];
  iVar9 = 4;
  iVar7 = 0;
  uVar8 = 0;
  local_88[0] = param_3;
  local_88[1] = param_4;
  aiStack_9c[3] = param_1[4];
  local_8c = param_1[5];
  puVar6 = local_88;
  do {
    if ((int)uVar8 < param_2) {
      *(byte *)(param_1[10] + 0x15c) = (byte)(1 << (uVar8 & 0x3f)) | *(byte *)(param_1[10] + 0x15c);
      uVar1 = *(undefined4 *)((int)puVar6 + iVar7);
      iVar2 = iVar7 + 0x10 + param_1[10];
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)((int)local_88 + iVar7 + 4);
      *(undefined4 *)(iVar2 + 0xc) = uVar1;
    }
    else {
      *(byte *)(param_1[10] + 0x15c) = *(byte *)(param_1[10] + 0x15c) & ~(byte)(1 << (uVar8 & 0x3f))
      ;
    }
    uVar8 = uVar8 + 1;
    iVar7 = iVar7 + 0x18;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  puVar3 = (undefined4 *)FUN_00194834(aiStack_9c[param_2],param_1[10]);
  if (puVar3 == (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(*param_1 + 0x374);
    puVar4 = (undefined4 *)FUN_00193e18(uVar1,0x168);
    *puVar4 = uVar1;
    puVar3 = puVar4 + 1;
    FUN_00109938(puVar3,*param_1);
    if ((*(uint *)(*(int *)(*param_1 + 0x6c4) + 0x30) & 0x10000) == 0) {
      uVar1 = FUN_000f4a5c(param_1);
      puVar4[0x26] = uVar1;
      puVar4[0x27] = 0xc;
    }
    else {
      uVar1 = FUN_000f4a84(param_1,local_88[0],0,puVar6,iVar7,uVar8,*param_1);
      puVar4[0x26] = uVar1;
      puVar4[0x27] = 0xc;
    }
    uVar8 = 0;
    iVar9 = 4;
    puVar6 = puVar4 + 5;
    iVar7 = 0;
    do {
      if ((int)uVar8 < param_2) {
        *(byte *)(puVar4 + 0x58) = (byte)(1 << (uVar8 & 0x3f)) | *(byte *)(puVar4 + 0x58);
        uVar1 = *(undefined4 *)((int)local_88 + iVar7);
        puVar6[4] = *(undefined4 *)((int)local_88 + iVar7 + 4);
        puVar6[3] = uVar1;
      }
      else {
        *(byte *)(puVar4 + 0x58) = *(byte *)(puVar4 + 0x58) & ~(byte)(1 << (uVar8 & 0x3f));
      }
      uVar8 = uVar8 + 1;
      iVar7 = iVar7 + 0x18;
      puVar6 = puVar6 + 6;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    piVar5 = *(int **)(*(int *)(*param_1 + 0x6c4) + 0x3a0);
    (**(code **)(*piVar5 + 0xc))(piVar5,puVar3);
    ((int (*)())FUN_000f4ddc)(param_1,param_2,puVar3);
  }
  return puVar3;
}

/* FUN_000f5248 @ 0xf5248 (376 bytes) */
int FUN_000f5248(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  uVar1 = ((int (*)())FUN_000f4fdc)(param_1,4,param_2,param_3,param_4,param_5,param_6,param_7);
  return uVar1;
}

/* FUN_000f53c0 @ 0xf53c0 (396 bytes) */
int FUN_000f53c0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  ((int (*)())FUN_000f4fdc)(param_1,3,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* FUN_000f554c @ 0xf554c (352 bytes) */
int FUN_000f554c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  ((int (*)())FUN_000f4fdc)(param_1,2,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* FUN_000f56ac @ 0xf56ac (324 bytes) */
int FUN_000f56ac(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  ((int (*)())FUN_000f4fdc)(param_1,1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* FUN_000f57f0 @ 0xf57f0 (540 bytes) */
int FUN_000f57f0(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  char *param_3;
  undefined4 param_4;
{
  bool bVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  int iVar11;
  undefined4 local_38 [8];
  
  if (param_1[7] != 0) {
    uVar8 = 0;
    do {
      puVar9 = (uint *)param_1[8];
      if (uVar8 < *puVar9) {
        uVar4 = puVar9[1];
        if (uVar4 <= uVar8) {
          _memset((void *)(uVar4 * 4 + puVar9[2]),0,(uVar8 - uVar4) * 4 + 4);
          puVar9[1] = uVar8 + 1;
        }
        piVar5 = (int *)(uVar8 * 4 + puVar9[2]);
      }
      else {
        piVar5 = (int *)FUN_0019423c(puVar9,uVar8);
      }
      iVar10 = *piVar5;
      iVar6 = 0;
      pcVar7 = param_3;
      do {
        if (*pcVar7 != '\x04') {
          uVar4 = 0;
          iVar11 = 4;
          iVar3 = iVar10;
          while (((((int)*(char *)(iVar10 + 0x15c) >> (uVar4 & 0x3f) & 1U) == 0 ||
                  (*(int *)(iVar3 + 0x1c) != 2)) ||
                 (*(float *)(iVar3 + 0x20) != *(float *)(param_2 + iVar6)))) {
            uVar4 = uVar4 + 1;
            iVar3 = iVar3 + 0x18;
            iVar11 = iVar11 + -1;
            if (iVar11 == 0) goto LAB_000f59bc;
          }
        }
        bVar1 = iVar6 != 0xc;
        pcVar7 = pcVar7 + 1;
        iVar6 = iVar6 + 4;
      } while (bVar1);
      iVar6 = 0;
      local_38[0] = *(undefined4 *)param_3;
      pcVar7 = param_3;
      do {
        uVar4 = (uint)*(byte *)((int)local_38 + iVar6);
        if (((uVar4 != 4) && (((int)*(char *)(iVar10 + 0x15c) >> (uVar4 & 0x3f) & 1U) != 0)) &&
           (fVar2 = *(float *)(param_2 + iVar6 * 4),
           *(float *)(uVar4 * 0x18 + iVar10 + 0x20) != fVar2)) {
          iVar11 = 4;
          uVar4 = 0;
          iVar3 = iVar10;
          do {
            if (((((int)*(char *)(iVar10 + 0x15c) >> (uVar4 & 0x3f) & 1U) != 0) &&
                (*(int *)(iVar3 + 0x1c) == 2)) && (*(float *)(iVar3 + 0x20) == fVar2)) {
              *pcVar7 = (char)uVar4;
              break;
            }
            uVar4 = uVar4 + 1;
            iVar3 = iVar3 + 0x18;
            iVar11 = iVar11 + -1;
          } while (iVar11 != 0);
        }
        bVar1 = iVar6 != 3;
        pcVar7 = pcVar7 + 1;
        iVar6 = iVar6 + 1;
      } while (bVar1);
      iVar6 = (**(code **)(**(int **)(*param_1 + 0x30c) + 0x100))
                        (*(int **)(*param_1 + 0x30c),param_3);
      if (iVar6 != 0) {
        *(undefined4 *)(iVar10 + 0x9c) = DAT_001aa860;
        return iVar10;
      }
LAB_000f59bc:
      uVar8 = uVar8 + 1;
    } while (uVar8 < (uint)param_1[7]);
  }
  return 0;
}

/* FUN_000f5a0c @ 0xf5a0c (512 bytes) */
int FUN_000f5a0c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  double dVar9;
  
  iVar3 = FUN_0011379c(*(undefined4 *)(param_4 + 8),param_3);
  if (iVar3 == 0) goto LAB_000f5a8c;
  uVar2 = *(uint *)(param_2 * 0x18 + param_1 + 0xa0) & 1;
  FUN_001054ec(param_3,0);
  iVar3 = FUN_00105594(param_1,param_2);
  iVar3 = *(int *)(iVar3 + 0x98);
  if (iVar3 == 0xc) {
LAB_000f5b30:
    iVar3 = FUN_00105594(param_1,param_2);
    piVar7 = *(int **)(*(int *)(param_4 + 8) + 0x30c);
    iVar8 = 0;
    do {
      iVar5 = FUN_001054ec(param_3,0);
      if (*(char *)(iVar8 + iVar5 + 0x10) != '\x01') {
        iVar5 = FUN_001054ec(param_1,param_2);
        uVar6 = (uint)*(byte *)(iVar8 + iVar5 + 0x10);
        if (uVar6 != 4) {
          if (((int)*(char *)(iVar3 + 0x15c) >> (uVar6 & 0x3f) & 1U) == 0) goto LAB_000f5a8c;
          if (uVar2 == 0) {
            dVar9 = (double)*(float *)(uVar6 * 0x18 + iVar3 + 0x20);
          }
          else {
            dVar9 = -(double)*(float *)(uVar6 * 0x18 + iVar3 + 0x20);
          }
          iVar5 = (**(code **)(*piVar7 + 0xf0))(dVar9,piVar7);
          if (iVar5 == 0) goto LAB_000f5a8c;
        }
      }
      bVar1 = iVar8 != 3;
      iVar8 = iVar8 + 1;
    } while (bVar1);
LAB_000f5b28:
    uVar4 = 1;
  }
  else {
    if (iVar3 == 0x33) {
      if (uVar2 == 0) {
        iVar3 = FUN_00105594(param_1,param_2);
        iVar8 = 0;
        piVar7 = *(int **)(*(int *)(param_4 + 8) + 0x30c);
        do {
          iVar5 = FUN_001054ec(param_3,0);
          if (*(char *)(iVar8 + iVar5 + 0x10) != '\x01') {
            iVar5 = FUN_001054ec(param_1,param_2);
            uVar2 = (uint)*(byte *)(iVar8 + iVar5 + 0x10);
            if ((uVar2 != 4) &&
               (iVar5 = (**(code **)(*piVar7 + 0xf0))
                                  ((double)*(float *)(uVar2 * 0x18 + iVar3 + 0x20),piVar7),
               iVar5 == 0)) goto LAB_000f5a8c;
          }
          bVar1 = iVar8 != 3;
          iVar8 = iVar8 + 1;
        } while (bVar1);
        goto LAB_000f5b28;
      }
    }
    else if (iVar3 == 2) goto LAB_000f5b30;
LAB_000f5a8c:
    uVar4 = 0;
  }
  return uVar4;
}

/* FUN_000f5c0c @ 0xf5c0c (228 bytes) */
int FUN_000f5c0c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int *param_4;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uStack00000020;
  undefined4 local_38 [9];
  
  uStack00000020 = param_3;
  piVar2 = (int *)FUN_00105594(param_1,param_2);
  iVar3 = (**(code **)(*piVar2 + 0x48))();
  if (iVar3 == 0) {
LAB_000f5cd8:
    uVar4 = 0;
  }
  else {
    iVar3 = FUN_001054ec(param_1,param_2);
    iVar5 = 0;
    pcVar6 = (char *)&STACKARG(0x20);
    local_38[0] = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = 4;
    do {
      if (((*pcVar6 == '\0') && (uVar1 = (uint)*(byte *)((int)local_38 + iVar5), uVar1 < 4)) &&
         ((((int)*(char *)(piVar2 + 0x57) >> (uVar1 & 0x3f) & 1U) == 0 ||
          (piVar2[uVar1 * 6 + 8] != *param_4)))) goto LAB_000f5cd8;
      iVar5 = iVar5 + 1;
      pcVar6 = pcVar6 + 1;
      param_4 = param_4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    uVar4 = 1;
  }
  return uVar4;
}

/* FUN_000f5cf0 @ 0xf5cf0 (412 bytes) */
int FUN_000f5cf0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int *param_4;
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  undefined4 uStack00000020;
  undefined4 local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  
  uStack00000020 = param_3;
  piVar2 = (int *)FUN_00105594(param_1,param_2);
  iVar3 = (**(code **)(*piVar2 + 0x48))();
  if (iVar3 != 0) {
    iVar3 = FUN_001054ec(param_1,param_2);
    bVar1 = false;
    iVar4 = 0;
    pcVar5 = (char *)&STACKARG(0x20);
    local_48 = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = 4;
    do {
      if ((*pcVar5 == '\0') && (uVar6 = (uint)*(byte *)((int)&local_48 + iVar4), uVar6 < 4)) {
        local_40 = piVar2[uVar6 * 6 + 8];
        local_3c = piVar2[uVar6 * 6 + 9];
        local_38 = piVar2[uVar6 * 6 + 10];
        local_44 = piVar2[uVar6 * 6 + 7];
        local_30 = piVar2[uVar6 * 6 + 0xc];
        local_34 = piVar2[uVar6 * 6 + 0xb];
        if (piVar2[uVar6 * 6 + 7] != 2) {
          return 0;
        }
        if (((int)*(char *)(piVar2 + 0x57) >> (uVar6 & 0x3f) & 1U) == 0) {
          return 0;
        }
        if (bVar1) {
          if (*param_4 != 2) {
            return 0;
          }
          if (local_40 != param_4[1]) {
            return 0;
          }
          bVar1 = true;
        }
        else {
          bVar1 = true;
          *param_4 = 2;
          param_4[1] = local_40;
        }
      }
      iVar4 = iVar4 + 1;
      pcVar5 = pcVar5 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    if (bVar1) {
      if (((*(uint *)(param_2 * 0x18 + param_1 + 0xa0) & 2) != 0) &&
         ((float)param_4[1] < FLOAT_001aa0d4)) {
        param_4[1] = (int)-(float)param_4[1];
      }
      if ((*(uint *)(param_2 * 0x18 + param_1 + 0xa0) & 1) != 0) {
        param_4[1] = (int)-(float)param_4[1];
        return 1;
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_000f5e8c @ 0xf5e8c (264 bytes) */
int FUN_000f5e8c(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 local_38;
  int local_34;
  float local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  
  piVar1 = (int *)FUN_00105594(param_1,param_2);
  iVar2 = (**(code **)(*piVar1 + 0x48))();
  if (iVar2 == 0) {
LAB_000f5f7c:
    uVar3 = 0;
  }
  else {
    iVar2 = FUN_001054ec(param_1,param_2);
    iVar4 = 0;
    local_38 = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = 4;
    do {
      uVar5 = (uint)*(byte *)((int)&local_38 + iVar4);
      if (uVar5 < 4) {
        local_30 = (float)piVar1[uVar5 * 6 + 8];
        local_2c = piVar1[uVar5 * 6 + 9];
        local_28 = piVar1[uVar5 * 6 + 10];
        local_34 = piVar1[uVar5 * 6 + 7];
        local_20 = piVar1[uVar5 * 6 + 0xc];
        local_24 = piVar1[uVar5 * 6 + 0xb];
        if (((piVar1[uVar5 * 6 + 7] != 2) ||
            (((int)*(char *)(piVar1 + 0x57) >> (uVar5 & 0x3f) & 1U) == 0)) ||
           ((float)piVar1[uVar5 * 6 + 8] < FLOAT_001aa0d4)) goto LAB_000f5f7c;
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    uVar3 = 1;
  }
  return uVar3;
}

/* FUN_000f5f94 @ 0xf5f94 (304 bytes) */
int FUN_000f5f94(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  byte *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  uint *puVar8;
  int iVar9;
  
  if (*(int *)(param_1 + 0x1c) != 0) {
    uVar7 = 0;
    do {
      puVar8 = *(uint **)(param_1 + 0x20);
      if (uVar7 < *puVar8) {
        uVar1 = puVar8[1];
        if (uVar1 <= uVar7) {
          _memset((void *)(uVar1 * 4 + puVar8[2]),0,(uVar7 - uVar1) * 4 + 4);
          puVar8[1] = uVar7 + 1;
        }
        piVar2 = (int *)(uVar7 * 4 + puVar8[2]);
      }
      else {
        piVar2 = (int *)FUN_0019423c(puVar8,uVar7);
      }
      iVar3 = *piVar2;
      iVar9 = 4;
      iVar5 = 0;
      pbVar6 = param_3;
      while ((uVar1 = (uint)*pbVar6, uVar1 == 4 ||
             (((((int)*(char *)(iVar3 + 0x15c) >> (uVar1 & 0x3f) & 1U) != 0 &&
               (iVar4 = uVar1 * 0x18 + iVar3, *(int *)(iVar4 + 0x1c) == 2)) &&
              (*(float *)(iVar4 + 0x20) == *(float *)(iVar5 + param_2)))))) {
        pbVar6 = pbVar6 + 1;
        iVar5 = iVar5 + 4;
        iVar9 = iVar9 + -1;
        if (iVar9 == 0) {
          *(undefined4 *)(iVar3 + 0x9c) = DAT_001aa860;
          return iVar3;
        }
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < *(uint *)(param_1 + 0x1c));
  }
  return 0;
}

/* FUN_000f60c4 @ 0xf60c4 (388 bytes) */
int FUN_000f60c4(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined1 *puVar6;
  uint uVar7;
  char *pcVar8;
  undefined4 in_r9;
  undefined4 in_r10;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  undefined1 auStack_b8 [148];
  
  puVar10 = *(uint **)(param_1 + 0x3c8);
  uVar2 = puVar10[1];
  uVar7 = 0;
  if (uVar2 != 0) {
    do {
      if (uVar7 < *puVar10) {
        if (uVar2 <= uVar7) {
          _memset((void *)(uVar2 * 4 + puVar10[2]),0,(uVar7 - uVar2) * 4 + 4);
          puVar10[1] = uVar7 + 1;
        }
        piVar3 = (int *)(uVar7 * 4 + puVar10[2]);
      }
      else {
        piVar3 = (int *)FUN_0019423c(puVar10,uVar7);
      }
      uVar9 = uVar7 + 1;
      iVar11 = *piVar3;
      if ((((*(uint *)(iVar11 + 0x14) & 1) != 0) && ((*(byte *)(iVar11 + 0x15c) & 1) != 0)) &&
         (*(int *)(iVar11 + 0x98) == 0xc)) {
        uVar2 = 0;
        uVar4 = (**(code **)(**(int **)(param_2 + 0x30c) + 0x158))
                          (*(int **)(param_2 + 0x30c),*(undefined4 *)(iVar11 + 0x94),
                           *(undefined4 *)(iVar11 + 0x1c),0,param_2);
        iVar5 = FUN_001054ec(iVar11,0);
        *(undefined4 *)(iVar5 + 8) = uVar4;
        puVar6 = *(undefined1 **)(iVar11 + 0x14c);
        uVar4 = *(undefined4 *)(iVar11 + 0x94);
        pcVar8 = "k";
        FUN_000e0e0c(param_2,"(%d)  %d, regnum = %s[%d]: ",puVar6,uVar7,"k",uVar4,in_r9,in_r10);
        do {
          if (((int)*(char *)(iVar11 + 0x15c) >> (uVar2 & 0x3f) & 1U) == 0) break;
          puVar6 = auStack_b8;
          FUN_000e0e0c(param_2,"  %s ",puVar6,uVar7,pcVar8,uVar4,in_r9,in_r10);
          bVar1 = uVar2 != 3;
          uVar2 = uVar2 + 1;
        } while (bVar1);
        FUN_000e0e0c(param_2,"\n",puVar6,uVar7,pcVar8,uVar4,in_r9,in_r10);
      }
      uVar2 = puVar10[1];
      uVar7 = uVar9;
    } while (uVar9 < uVar2);
  }
  return;
}

/* FUN_000f6248 @ 0xf6248 (532 bytes) */
int FUN_000f6248(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  undefined4 auStack_8c [4];
  undefined4 local_7c;
  undefined4 local_78 [26];
  
  auStack_8c[1] = *(undefined4 *)(param_1 + 8);
  auStack_8c[2] = *(undefined4 *)(param_1 + 0xc);
  iVar7 = 4;
  iVar4 = 0;
  uVar5 = 0;
  local_78[0] = param_3;
  local_78[1] = param_4;
  auStack_8c[3] = *(undefined4 *)(param_1 + 0x10);
  local_7c = *(undefined4 *)(param_1 + 0x14);
  do {
    if ((int)uVar5 < param_2) {
      *(byte *)(*(int *)(param_1 + 0x28) + 0x15c) =
           (byte)(1 << (uVar5 & 0x3f)) | *(byte *)(*(int *)(param_1 + 0x28) + 0x15c);
      uVar1 = *(undefined4 *)((int)local_78 + iVar4);
      iVar2 = iVar4 + 0x10 + *(int *)(param_1 + 0x28);
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)((int)local_78 + iVar4 + 4);
      *(undefined4 *)(iVar2 + 0xc) = uVar1;
    }
    else {
      *(byte *)(*(int *)(param_1 + 0x28) + 0x15c) =
           *(byte *)(*(int *)(param_1 + 0x28) + 0x15c) & ~(byte)(1 << (uVar5 & 0x3f));
    }
    uVar5 = uVar5 + 1;
    iVar4 = iVar4 + 0x18;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  iVar4 = FUN_00194834(auStack_8c[param_2],*(undefined4 *)(param_1 + 0x28));
  if (iVar4 == 0) {
    uVar1 = FUN_000f4a5c(param_1);
    iVar4 = FUN_001275a0(param_1,0xc,uVar1,0);
    piVar3 = *(int **)(iVar4 + 0x18);
    if (*piVar3 == 0) {
      piVar3 = (int *)FUN_0019423c(piVar3,0);
    }
    else {
      if (piVar3[1] == 0) {
        *(undefined4 *)piVar3[2] = 0;
        piVar3[1] = 1;
      }
      piVar3 = (int *)piVar3[2];
    }
    iVar7 = *piVar3;
    iVar8 = 4;
    uVar5 = 0;
    iVar6 = iVar7 + 0x10;
    iVar2 = 0;
    do {
      if ((int)uVar5 < param_2) {
        *(byte *)(iVar7 + 0x15c) = (byte)(1 << (uVar5 & 0x3f)) | *(byte *)(iVar7 + 0x15c);
        uVar1 = *(undefined4 *)((int)local_78 + iVar2);
        *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)((int)local_78 + iVar2 + 4);
        *(undefined4 *)(iVar6 + 0xc) = uVar1;
      }
      else {
        *(byte *)(iVar7 + 0x15c) = *(byte *)(iVar7 + 0x15c) & ~(byte)(1 << (uVar5 & 0x3f));
      }
      uVar5 = uVar5 + 1;
      iVar2 = iVar2 + 0x18;
      iVar6 = iVar6 + 0x18;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    ((int (*)())FUN_000f4ddc)(param_1,param_2,iVar7);
  }
  else {
    iVar4 = *(int *)(iVar4 + 0x8c);
  }
  return iVar4;
}

/* FUN_000f645c @ 0xf645c (376 bytes) */
int FUN_000f645c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  uVar1 = ((int (*)())FUN_000f6248)(param_1,4,param_2,param_3,param_4,param_5,param_6,param_7);
  return uVar1;
}

/* FUN_000f65d4 @ 0xf65d4 (396 bytes) */
int FUN_000f65d4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  ((int (*)())FUN_000f6248)(param_1,3,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* FUN_000f6760 @ 0xf6760 (352 bytes) */
int FUN_000f6760(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  ((int (*)())FUN_000f6248)(param_1,2,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* FUN_000f68c0 @ 0xf68c0 (324 bytes) */
int FUN_000f68c0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  ((int (*)())FUN_000f6248)(param_1,1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* FUN_000f6a04 @ 0xf6a04 (588 bytes) */
int FUN_000f6a04(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 uVar12;
  uint uVar13;
  uint *puVar14;
  undefined4 uStack00000020;
  int local_98;
  int local_94 [30];
  
  puVar10 = (undefined4 *)0x0;
  iVar9 = *(int *)(param_1 + 8);
  uStack00000020 = param_3;
  iVar2 = (**(code **)(**(int **)(iVar9 + 0x30c) + 0xe8))
                    (*(int **)(iVar9 + 0x30c),param_2,&local_98,param_3,iVar9);
  if (iVar2 != 0) {
    FUN_000f4a24(param_2,local_94);
    iVar2 = *(int *)(param_1 + 0x3ac);
    uVar13 = 0;
    uVar11 = *(uint *)(*(int *)(iVar2 + 0x18) + 4);
    if (0 < (int)uVar11) {
      while( true ) {
        puVar14 = *(uint **)(iVar2 + 0x18);
        if (uVar13 < *puVar14) {
          uVar3 = puVar14[1];
          if (uVar3 <= uVar13) {
            _memset((void *)(uVar3 * 4 + puVar14[2]),0,(uVar13 - uVar3) * 4 + 4);
            puVar14[1] = uVar13 + 1;
          }
          piVar5 = (int *)(uVar13 * 4 + puVar14[2]);
        }
        else {
          piVar5 = (int *)FUN_0019423c(puVar14,uVar13);
        }
        puVar10 = (undefined4 *)*piVar5;
        if (puVar10[0x4b] == local_98) {
          pcVar7 = (char *)&STACKARG(0x20);
          puVar6 = puVar10 + 4;
          iVar8 = 0;
          iVar2 = 4;
          while ((*pcVar7 == '\x04' ||
                 ((puVar6[3] == *(int *)((int)local_94 + iVar8) &&
                  (puVar6[4] == *(int *)((int)local_94 + iVar8 + 4)))))) {
            iVar2 = iVar2 + -1;
            iVar8 = iVar8 + 0x18;
            puVar6 = puVar6 + 6;
            pcVar7 = pcVar7 + 1;
            if (iVar2 == 0) {
              if (puVar10 != (undefined4 *)0x0) {
                return puVar10;
              }
              goto LAB_000f6b68;
            }
          }
        }
        uVar13 = uVar13 + 1;
        if (uVar11 == uVar13) break;
        iVar2 = *(int *)(param_1 + 0x3ac);
      }
    }
LAB_000f6b68:
    if ((*(uint *)(param_1 + 0x30) & 8) == 0) {
      uVar12 = *(undefined4 *)(param_1 + 0x3ac);
      uVar4 = FUN_000f4a5c(uVar12);
      iVar2 = FUN_001275a0(uVar12,0x33,uVar4,0);
      piVar5 = *(int **)(iVar2 + 0x18);
      if (*piVar5 == 0) {
        piVar5 = (int *)FUN_0019423c(piVar5,0);
      }
      else {
        if (piVar5[1] == 0) {
          *(undefined4 *)piVar5[2] = 0;
          piVar5[1] = 1;
        }
        piVar5 = (int *)piVar5[2];
      }
      puVar10 = (undefined4 *)*piVar5;
    }
    else {
      uVar4 = *(undefined4 *)(iVar9 + 0x374);
      puVar6 = (undefined4 *)FUN_00193e18(uVar4,0x168);
      *puVar6 = uVar4;
      puVar10 = puVar6 + 1;
      FUN_00109938(puVar10,*(undefined4 *)(param_1 + 8));
      uVar4 = FUN_000f4a5c(*(undefined4 *)(param_1 + 0x3ac));
      puVar6[0x26] = uVar4;
      puVar6[0x27] = 0x33;
      (**(code **)(**(int **)(param_1 + 0x3a0) + 0xc))(*(int **)(param_1 + 0x3a0),puVar10);
    }
    puVar10[0x4b] = local_98;
    puVar14 = *(uint **)(*(int *)(param_1 + 0x3ac) + 0x18);
    uVar11 = puVar14[1];
    if (uVar11 < *puVar14) {
      _memset((void *)(uVar11 * 4 + puVar14[2]),0,4);
      piVar5 = (int *)(uVar11 * 4 + puVar14[2]);
      puVar14[1] = uVar11 + 1;
    }
    else {
      piVar5 = (int *)FUN_0019423c(puVar14,uVar11);
    }
    *piVar5 = (int)puVar10;
    iVar9 = 4;
    uVar11 = 0;
    puVar6 = puVar10 + 4;
    iVar2 = 0;
    do {
      puVar1 = (undefined4 *)((int)local_94 + iVar2);
      uVar4 = *(undefined4 *)((int)local_94 + iVar2 + 4);
      iVar2 = iVar2 + 0x18;
      puVar6[3] = *puVar1;
      puVar6[4] = uVar4;
      uVar13 = uVar11 & 0x3f;
      uVar11 = uVar11 + 1;
      puVar6 = puVar6 + 6;
      *(byte *)(puVar10 + 0x57) = (byte)(1 << uVar13) | *(byte *)(puVar10 + 0x57);
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  return puVar10;
}

/* FUN_000f6d14 @ 0xf6d14 (2568 bytes) */
int FUN_000f6d14(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13, param_14, param_15, param_16, param_17, param_18, param_19, param_20, param_21, param_22)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  int param_10;
  undefined4 param_11;
  undefined4 param_12;
  undefined4 param_13;
  undefined4 param_14;
  undefined4 param_15;
  int param_16;
  undefined4 param_17;
  undefined4 param_18;
  undefined4 param_19;
  undefined4 param_20;
  undefined4 param_21;
  int param_22;
{
  undefined1 uVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  int **ppiVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  uint *puVar10;
  int iVar11;
  uint *puVar12;
  undefined4 uVar13;
  bool bVar14;
  int iVar15;
  undefined4 uStack00000020;
  int iStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  int local_288;
  undefined1 auStack_284 [4];
  undefined4 local_280;
  undefined4 local_27c;
  undefined4 local_278;
  int *local_274;
  int *local_270 [11];
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  undefined4 local_21c;
  undefined4 local_218;
  undefined4 local_214;
  undefined4 local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  undefined4 local_1dc;
  undefined4 local_1d8;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  undefined4 local_1c4;
  undefined4 local_1c0;
  undefined4 local_1bc;
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  undefined4 local_190;
  undefined4 local_18c;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  undefined4 local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  
  uVar13 = *(undefined4 *)(param_2 + 8);
  uStack00000020 = param_3;
  iStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  if ((((param_4 == 2) && (param_10 == 2)) && (param_16 == 2)) && (param_22 == 2)) {
    iVar15 = 4;
    ppiVar5 = local_270 + 7;
    do {
      *ppiVar5 = (int *)0x7ffffffe;
      ppiVar5 = ppiVar5 + 1;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
    local_270[8] = (int *)param_11;
    local_270[9] = (int *)param_17;
    local_270[7] = (int *)param_5;
    iVar15 = ((int (*)())FUN_000f6a04)(param_2,local_270 + 7,DAT_001aa868);
    if (iVar15 != 0) {
      if ((*(uint *)(param_2 + 0x30) & 8) == 0) {
        FUN_001046c8(param_1,uStack00000020,*(undefined4 *)(iVar15 + 0x8c));
      }
      else {
        FUN_00106004(param_1,uStack00000020,iVar15,*(uint *)(param_2 + 0x30) >> 7 & 1,uVar13);
      }
      iVar6 = FUN_001054ec(iVar15,0);
      local_288 = *(int *)(iVar6 + 0x10);
      if (local_288 != DAT_001aa860) {
        iVar6 = 0;
        do {
          iVar7 = FUN_001054ec(param_1,uStack00000020);
          if (*(byte *)(iVar6 + iVar7 + 0x10) < 4) {
            iVar7 = FUN_001054ec(param_1,uStack00000020);
            uVar3 = (uint)*(byte *)(iVar6 + iVar7 + 0x10);
            auStack_284[uVar3 - 4] = 0;
            *(byte *)(iVar15 + uVar3 + 0xc) =
                 (byte)(1 << (uVar3 & 0x3f)) | *(byte *)(iVar15 + uVar3 + 0xc);
          }
          bVar14 = iVar6 != 3;
          iVar6 = iVar6 + 1;
        } while (bVar14);
        *(int *)(iVar15 + 0x9c) = local_288;
      }
      return;
    }
  }
  piVar9 = &STACKARG(0x24);
  local_27c = DAT_001aa868;
  local_270[0] = &param_10;
  ppiVar5 = &local_274;
  iVar15 = 0;
  local_270[1] = &param_16;
  local_270[2] = &param_22;
  local_270[6] = (int *)PTR_DAT_001e8b70;
  local_274 = piVar9;
  local_270[3] = (int *)PTR_DAT_001e8b70;
  local_270[4] = (int *)PTR_DAT_001e8b70;
  local_270[5] = (int *)PTR_DAT_001e8b70;
  iVar6 = 0;
LAB_000f6f18:
  do {
    iVar7 = iVar6;
    *(char *)((int)&local_27c + iVar15) = (char)iVar7;
    iVar6 = iVar7 + 1;
    local_270[iVar7 + 3] = piVar9;
LAB_000f6f58:
    iVar4 = 4 - iVar15;
    do {
      iVar11 = iVar15;
      iVar15 = iVar11 + 1;
      ppiVar5 = ppiVar5 + 1;
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) {
        local_278 = DAT_001aa868;
        if (0 < iVar6) {
          do {
            iVar11 = iVar7 + 1;
            iVar4 = 0;
            iVar15 = 0;
            ppiVar5 = local_270 + 4;
            if (iVar7 < 0) {
              iVar11 = 1;
            }
            while (iVar11 = iVar11 + -1, iVar11 != 0) {
              puVar12 = (uint *)ppiVar5[-1];
              puVar10 = (uint *)*ppiVar5;
              uVar3 = *puVar12;
              if (uVar3 == *puVar10) {
                if (uVar3 == 2) {
                  bVar14 = (float)puVar12[1] < (float)puVar10[1];
                }
                else {
                  bVar14 = puVar12[1] < puVar10[1];
                }
              }
              else {
                bVar14 = uVar3 < *puVar10;
              }
              if (bVar14) {
                uVar2 = *(undefined1 *)((int)&local_278 + iVar4);
                uVar1 = *(undefined1 *)((int)&local_278 + iVar15 + 1);
                *ppiVar5 = (int *)puVar12;
                *(undefined1 *)((int)&local_278 + iVar15 + 1) = uVar2;
                ppiVar5[-1] = (int *)puVar10;
                *(undefined1 *)((int)&local_278 + iVar4) = uVar1;
              }
              iVar4 = iVar4 + 1;
              ppiVar5 = ppiVar5 + 1;
              iVar15 = iVar15 + 1;
            }
            bVar14 = 0 < iVar7;
            iVar7 = iVar7 + -1;
          } while (bVar14);
          iVar7 = 0;
          iVar15 = iVar6;
          do {
            auStack_284[*(byte *)((int)&local_278 + iVar7)] = (char)iVar7;
            iVar7 = iVar7 + 1;
            iVar15 = iVar15 + -1;
          } while (iVar15 != 0);
        }
        iVar15 = 0;
        iVar7 = 4;
        do {
          *(undefined1 *)((int)&local_280 + iVar15) =
               auStack_284[*(byte *)((int)&local_27c + iVar15)];
          iVar15 = iVar15 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        uVar3 = *(uint *)(param_2 + 0x30);
        if ((uVar3 & 8) == 0) {
          if (iVar6 == 2) {
            local_244 = *local_270[3];
            local_240 = local_270[3][1];
            local_23c = local_270[3][2];
            local_238 = local_270[3][3];
            local_230 = local_270[3][5];
            local_234 = local_270[3][4];
            local_7c = *local_270[4];
            local_78 = local_270[4][1];
            local_74 = local_270[4][2];
            local_70 = local_270[4][3];
            local_68 = local_270[4][5];
            local_6c = local_270[4][4];
            uVar13 = ((int (*)())FUN_000f6760)(*(undefined4 *)(param_2 + 0x3ac),local_244,local_240,local_23c,
                                  local_238,local_234,local_230,local_7c);
          }
          else if (iVar6 < 3) {
            if (iVar6 == 1) {
              local_22c = *local_270[3];
              local_228 = local_270[3][1];
              local_224 = local_270[3][2];
              local_220 = local_270[3][3];
              local_218 = local_270[3][5];
              local_21c = local_270[3][4];
              uVar13 = ((int (*)())FUN_000f68c0)(*(undefined4 *)(param_2 + 0x3ac),local_22c,local_228,local_224,
                                    local_220,local_21c,local_218);
            }
            else {
LAB_000f73f0:
              uVar13 = 0;
            }
          }
          else if (iVar6 == 3) {
            local_94 = *local_270[3];
            local_90 = local_270[3][1];
            local_8c = local_270[3][2];
            local_88 = local_270[3][3];
            local_80 = local_270[3][5];
            local_84 = local_270[3][4];
            local_a8 = local_270[4][1];
            local_a4 = local_270[4][2];
            local_a0 = local_270[4][3];
            local_ac = *local_270[4];
            local_98 = local_270[4][5];
            local_9c = local_270[4][4];
            local_bc = local_270[5][2];
            local_b8 = local_270[5][3];
            local_c4 = *local_270[5];
            local_c0 = local_270[5][1];
            local_b0 = local_270[5][5];
            local_b4 = local_270[5][4];
            uVar13 = ((int (*)())FUN_000f65d4)(*(undefined4 *)(param_2 + 0x3ac),local_94,local_90,local_8c,
                                  local_88,local_84,local_80,local_ac);
          }
          else {
            if (iVar6 != 4) goto LAB_000f73f0;
            local_dc = *local_270[3];
            local_d8 = local_270[3][1];
            local_d4 = local_270[3][2];
            local_d0 = local_270[3][3];
            local_c8 = local_270[3][5];
            local_cc = local_270[3][4];
            local_f0 = local_270[4][1];
            local_ec = local_270[4][2];
            local_e8 = local_270[4][3];
            local_f4 = *local_270[4];
            local_e0 = local_270[4][5];
            local_e4 = local_270[4][4];
            local_104 = local_270[5][2];
            local_100 = local_270[5][3];
            local_10c = *local_270[5];
            local_108 = local_270[5][1];
            local_f8 = local_270[5][5];
            local_fc = local_270[5][4];
            local_1b4 = *local_270[6];
            local_1b0 = local_270[6][1];
            local_1ac = local_270[6][2];
            local_1a8 = local_270[6][3];
            local_1a0 = local_270[6][5];
            local_1a4 = local_270[6][4];
            uVar13 = ((int (*)())FUN_000f645c)(*(undefined4 *)(param_2 + 0x3ac),local_dc,local_d8,local_d4,
                                  local_d0,local_cc,local_c8,local_f4);
          }
          FUN_001046c8(param_1,uStack00000020,uVar13);
          goto LAB_000f76c8;
        }
        if (iVar6 == 2) {
          local_14c = local_270[3][2];
          local_154 = *local_270[3];
          local_150 = local_270[3][1];
          local_148 = local_270[3][3];
          local_140 = local_270[3][5];
          local_144 = local_270[3][4];
          local_16c = *local_270[4];
          local_168 = local_270[4][1];
          local_164 = local_270[4][2];
          local_160 = local_270[4][3];
          local_158 = local_270[4][5];
          local_15c = local_270[4][4];
          uVar8 = ((int (*)())FUN_000f554c)(*(undefined4 *)(param_2 + 0x3ac),local_154,local_150,local_14c,
                               local_148,local_144,local_140,local_16c);
          uVar3 = *(uint *)(param_2 + 0x30);
        }
        else if (iVar6 < 3) {
          if (iVar6 == 1) {
            local_134 = local_270[3][2];
            local_13c = *local_270[3];
            local_138 = local_270[3][1];
            local_130 = local_270[3][3];
            local_128 = local_270[3][5];
            local_12c = local_270[3][4];
            uVar8 = ((int (*)())FUN_000f56ac)(*(undefined4 *)(param_2 + 0x3ac),local_13c,local_138,local_134,
                                 local_130,local_12c,local_128);
            uVar3 = *(uint *)(param_2 + 0x30);
          }
          else {
LAB_000f70d4:
            uVar8 = 0;
          }
        }
        else if (iVar6 == 3) {
          local_17c = local_270[3][2];
          local_184 = *local_270[3];
          local_180 = local_270[3][1];
          local_178 = local_270[3][3];
          local_170 = local_270[3][5];
          local_174 = local_270[3][4];
          local_198 = local_270[4][1];
          local_19c = *local_270[4];
          local_194 = local_270[4][2];
          local_190 = local_270[4][3];
          local_188 = local_270[4][5];
          local_18c = local_270[4][4];
          local_124 = *local_270[5];
          local_11c = local_270[5][2];
          local_118 = local_270[5][3];
          local_120 = local_270[5][1];
          local_110 = local_270[5][5];
          local_114 = local_270[5][4];
          uVar8 = ((int (*)())FUN_000f53c0)(*(undefined4 *)(param_2 + 0x3ac),local_184,local_180,local_17c,
                               local_178,local_174,local_170,local_19c);
          uVar3 = *(uint *)(param_2 + 0x30);
        }
        else {
          if (iVar6 != 4) goto LAB_000f70d4;
          local_1c4 = local_270[3][2];
          local_1cc = *local_270[3];
          local_1c8 = local_270[3][1];
          local_1c0 = local_270[3][3];
          local_1b8 = local_270[3][5];
          local_1bc = local_270[3][4];
          local_1e0 = local_270[4][1];
          local_1e4 = *local_270[4];
          local_1dc = local_270[4][2];
          local_1d8 = local_270[4][3];
          local_1d0 = local_270[4][5];
          local_1d4 = local_270[4][4];
          local_1fc = *local_270[5];
          local_1f4 = local_270[5][2];
          local_1f0 = local_270[5][3];
          local_1f8 = local_270[5][1];
          local_1e8 = local_270[5][5];
          local_1ec = local_270[5][4];
          local_214 = *local_270[6];
          local_210 = local_270[6][1];
          local_20c = local_270[6][2];
          local_208 = local_270[6][3];
          local_200 = local_270[6][5];
          local_204 = local_270[6][4];
          uVar8 = ((int (*)())FUN_000f5248)(*(undefined4 *)(param_2 + 0x3ac),local_1cc,local_1c8,local_1c4,
                               local_1c0,local_1bc,local_1b8,local_1e4);
          uVar3 = *(uint *)(param_2 + 0x30);
        }
        FUN_00106004(param_1,uStack00000020,uVar8,uVar3 >> 7 & 1,uVar13);
LAB_000f76c8:
        iVar15 = FUN_001054ec(param_1,uStack00000020);
        *(undefined4 *)(iVar15 + 0x10) = local_280;
        return;
      }
    } while (iVar6 < 0);
    if (iVar6 != 0) {
      piVar9 = *ppiVar5;
      iVar4 = 0;
      while ((*local_270[iVar4 + 3] != *piVar9 || (local_270[iVar4 + 3][1] != piVar9[1]))) {
        iVar4 = iVar4 + 1;
        if (iVar6 < iVar4) goto LAB_000f6f58;
        if (iVar4 == iVar6) goto LAB_000f6f18;
      }
      *(char *)((int)&local_27c + iVar11 + 1) = (char)iVar4;
      goto LAB_000f6f58;
    }
    piVar9 = *ppiVar5;
  } while( true );
}

/* FUN_000f771c @ 0xf771c (340 bytes) */
int FUN_000f771c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  
  ((int (*)())FUN_000f6d14)(param_1,param_2,param_3,1,param_4,local_b0,local_ac,local_a8,local_a4,1,param_5,
               local_98,local_94,local_90,local_8c,1,param_6,local_80,local_7c,local_78,local_74,1);
  return;
}

/* FUN_000f7870 @ 0xf7870 (340 bytes) */
int FUN_000f7870(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  
  ((int (*)())FUN_000f6d14)(param_1,param_2,param_3,3,param_4,local_b0,local_ac,local_a8,local_a4,3,param_5,
               local_98,local_94,local_90,local_8c,3,param_6,local_80,local_7c,local_78,local_74,3);
  return;
}

/* FUN_000f79c4 @ 0xf79c4 (332 bytes) */
void FUN_000f79c4(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  
  ((int (*)())FUN_000f6d14)(param_1,param_2,param_3,2,(float)fparam_1,local_a0,local_9c,local_98,local_94,2,
               (float)fparam_2,local_88,local_84,local_80,local_7c,2,(float)fparam_3,local_70,
               local_6c,local_68,local_64,2);
  return;
}

/* FUN_000f7b10 @ 0xf7b10 (228 bytes) */
int FUN_000f7b10(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  uint *param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iStack0000001c;
  int iStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  
  uVar2 = 0;
  if (param_1[1] != 0) {
    uVar3 = 0;
    uVar2 = param_1[1];
    iStack0000001c = param_2;
    iStack00000020 = param_3;
    uStack00000024 = param_4;
    uStack00000028 = param_5;
    uStack0000002c = param_6;
    uStack00000030 = param_7;
    do {
      if (uVar3 < *param_1) {
        if (uVar2 <= uVar3) {
          _memset((void *)(uVar2 * 4 + param_1[2]),0,(uVar3 - uVar2) * 4 + 4);
          param_1[1] = uVar3 + 1;
        }
        puVar1 = (undefined4 *)(uVar3 * 4 + param_1[2]);
      }
      else {
        puVar1 = (undefined4 *)FUN_0019423c(param_1,uVar3);
      }
      if ((*(int *)*puVar1 == param_2) && (((int *)*puVar1)[1] == param_3)) {
        return uVar3;
      }
      uVar2 = param_1[1];
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return uVar2;
}

/* FUN_000f7bf4 @ 0xf7bf4 (228 bytes) */
int FUN_000f7bf4(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  param_1[8] = param_2;
  iVar1 = FUN_00194034(param_2 + 0x37c);
  param_1[7] = iVar1;
  iVar3 = *(int *)(param_1[8] + 8);
  iVar1 = iVar1 * 4 + 4;
  param_1[9] = iVar3;
  uVar2 = FUN_00193e18(*(undefined4 *)(iVar3 + 0x378),iVar1);
  param_1[2] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  param_1[1] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  param_1[4] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  param_1[3] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  *param_1 = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),param_1[7] * 4 + 4);
  param_1[6] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),param_1[7] * 4 + 4);
  param_1[5] = uVar2;
  return;
}

/* FUN_000f7cd8 @ 0xf7cd8 (228 bytes) */
int FUN_000f7cd8(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  param_1[8] = param_2;
  iVar1 = FUN_00194034(param_2 + 0x37c);
  param_1[7] = iVar1;
  iVar3 = *(int *)(param_1[8] + 8);
  iVar1 = iVar1 * 4 + 4;
  param_1[9] = iVar3;
  uVar2 = FUN_00193e18(*(undefined4 *)(iVar3 + 0x378),iVar1);
  param_1[2] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  param_1[1] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  param_1[4] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  param_1[3] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),iVar1);
  *param_1 = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),param_1[7] * 4 + 4);
  param_1[6] = uVar2;
  uVar2 = FUN_00193e18(*(undefined4 *)(param_1[9] + 0x378),param_1[7] * 4 + 4);
  param_1[5] = uVar2;
  return;
}

/* FUN_000f7dbc @ 0xf7dbc (352 bytes) */
int FUN_000f7dbc(param_1)
  int param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  
  piVar2 = (int *)FUN_000ec5b8(*(undefined4 *)(param_1 + 0x20));
  if (*(int *)(param_1 + 0x1c) != 0) {
    uVar4 = 1;
    do {
      piVar2 = piVar2 + 1;
      iVar6 = *piVar2;
      iVar5 = *(int *)(iVar6 + 0xe4);
      iVar7 = 0;
      for (uVar9 = 1; uVar9 <= *(uint *)(*(int *)(iVar6 + 0xd0) + 4); uVar9 = uVar9 + 1) {
        iVar3 = *(int *)(iVar7 + *(int *)(*(int *)(iVar6 + 0xd0) + 8));
        if ((iVar3 != 0) && (iVar5 != *(int *)(*(int *)(iVar3 + 0xe4) * 4 + *(int *)(param_1 + 8))))
        {
          FUN_000e910c(iVar6,iVar3);
        }
        iVar7 = iVar7 + 4;
      }
      iVar7 = 0;
      for (uVar9 = 1; uVar9 <= *(uint *)(*(int *)(iVar6 + 0xf4) + 4); uVar9 = uVar9 + 1) {
        iVar8 = 0;
        iVar3 = *(int *)(iVar7 + *(int *)(*(int *)(iVar6 + 0xf4) + 8));
        for (uVar10 = 1; iVar1 = *(int *)(iVar3 + 0xf8), uVar10 <= *(uint *)(iVar1 + 4);
            uVar10 = uVar10 + 1) {
          iVar1 = *(int *)(iVar8 + *(int *)(iVar1 + 8));
          if (iVar5 != *(int *)(*(int *)(iVar1 + 0xe4) * 4 + *(int *)(param_1 + 8))) {
            FUN_000e910c(iVar6,iVar1);
          }
          iVar8 = iVar8 + 4;
        }
        iVar7 = iVar7 + 4;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 <= *(uint *)(param_1 + 0x1c));
  }
  return;
}

/* FUN_000f7f1c @ 0xf7f1c (296 bytes) */
int FUN_000f7f1c(param_1)
  undefined4 *param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  iVar3 = param_1[5];
  do {
    iVar1 = uVar4 * 4;
    iVar2 = *(int *)(iVar1 + iVar3);
    while ((iVar2 != 0 && (iVar5 = *(int *)(iVar2 + 4), iVar5 != 0))) {
      FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
      *(int *)(iVar1 + param_1[5]) = iVar5;
      iVar3 = param_1[5];
      iVar2 = *(int *)(iVar1 + iVar3);
    }
    iVar1 = *(int *)(iVar1 + iVar3);
    if (iVar1 != 0) {
      FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
      iVar3 = param_1[5];
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 <= (uint)param_1[7]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),iVar3);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[6]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),*param_1);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[3]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[4]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[1]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[2]);
  param_1[6] = 0;
  return;
}

/* FUN_000f8044 @ 0xf8044 (296 bytes) */
int FUN_000f8044(param_1)
  undefined4 *param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  iVar3 = param_1[5];
  do {
    iVar1 = uVar4 * 4;
    iVar2 = *(int *)(iVar1 + iVar3);
    while ((iVar2 != 0 && (iVar5 = *(int *)(iVar2 + 4), iVar5 != 0))) {
      FUN_00193cc0(*(undefined4 *)(iVar2 + -4),iVar2 + -4);
      *(int *)(iVar1 + param_1[5]) = iVar5;
      iVar3 = param_1[5];
      iVar2 = *(int *)(iVar1 + iVar3);
    }
    iVar1 = *(int *)(iVar1 + iVar3);
    if (iVar1 != 0) {
      FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
      iVar3 = param_1[5];
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 <= (uint)param_1[7]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),iVar3);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[6]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),*param_1);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[3]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[4]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[1]);
  FUN_00193cc0(*(undefined4 *)(param_1[9] + 0x378),param_1[2]);
  param_1[6] = 0;
  return;
}

/* FUN_000f816c @ 0xf816c (236 bytes) */
int FUN_000f816c(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  
  *(int *)(param_1[8] + 0x474) = *(int *)(param_1[8] + 0x474) + 1;
  iVar6 = *(int *)(param_1[9] + 0x378);
  piVar2 = (int *)FUN_00193e18(iVar6,0x14);
  puVar5 = (uint *)(piVar2 + 1);
  *piVar2 = iVar6;
  piVar2[1] = 2;
  piVar2[4] = iVar6;
  piVar2[2] = 0;
  iVar6 = FUN_00193e18(iVar6,8);
  piVar2[3] = iVar6;
  *(undefined4 *)(param_2 + 0xe4) = 1;
  *(undefined4 *)(*param_1 + 4) = 0;
  *(int *)(*(int *)(param_2 + 0xe4) * 4 + param_1[6]) = param_2;
  uVar7 = piVar2[2];
  if (uVar7 < (uint)piVar2[1]) {
    _memset((void *)(uVar7 * 4 + piVar2[3]),0,4);
    piVar2[2] = uVar7 + 1;
    piVar3 = (int *)(uVar7 * 4 + piVar2[3]);
  }
  else {
    piVar3 = (int *)FUN_0019423c(puVar5,uVar7);
  }
  *piVar3 = param_2;
  iVar6 = 2;
  *(int *)(*(int *)(param_2 + 0xe4) * 4 + param_1[1]) = *(int *)(param_2 + 0xe4);
  *(int *)(*(int *)(param_2 + 0xe4) * 4 + param_1[4]) = *(int *)(param_2 + 0xe4);
  while( true ) {
    while( true ) {
      iVar4 = FUN_000e80cc(param_2,*(undefined4 *)(param_1[8] + 0x474));
      if (iVar4 == 0) break;
      uVar7 = piVar2[2];
      if (uVar7 < *puVar5) {
        _memset((void *)(uVar7 * 4 + piVar2[3]),0,4);
        piVar2[2] = uVar7 + 1;
        piVar3 = (int *)(uVar7 * 4 + piVar2[3]);
      }
      else {
        piVar3 = (int *)FUN_0019423c(puVar5,uVar7);
      }
      *piVar3 = iVar4;
      iVar1 = iVar6 * 4;
      *(int *)(iVar4 + 0xe4) = iVar6;
      iVar6 = iVar6 + 1;
      *(undefined4 *)(iVar1 + *param_1) = *(undefined4 *)(param_2 + 0xe4);
      *(int *)(*(int *)(iVar4 + 0xe4) * 4 + param_1[6]) = iVar4;
      *(undefined4 *)(iVar4 + 0x118) = *(undefined4 *)(param_1[8] + 0x474);
      *(int *)(*(int *)(iVar4 + 0xe4) * 4 + param_1[1]) = *(int *)(iVar4 + 0xe4);
      *(int *)(*(int *)(iVar4 + 0xe4) * 4 + param_1[4]) = *(int *)(iVar4 + 0xe4);
      param_2 = iVar4;
    }
    uVar7 = piVar2[2];
    if (uVar7 == 0) break;
    piVar3 = (int *)0x0;
    if (uVar7 - 1 < uVar7) {
      piVar3 = (int *)((uVar7 - 1) * 4 + piVar2[3]);
    }
    param_2 = *piVar3;
    FUN_00194208(puVar5,uVar7 - 1);
  }
  if (puVar5 != (uint *)0x0) {
    FUN_00193cc0(piVar2[4],piVar2[3]);
    iVar6 = *piVar2;
    if ((*(int *)(iVar6 + 0x28) != 0) && (piVar3 = *(int **)(iVar6 + 0x14), piVar3 == piVar2)) {
      _memset(piVar3,0,*(int *)(iVar6 + 8) - (int)piVar3);
      *(undefined4 *)(iVar6 + 8) = *(undefined4 *)(iVar6 + 0x14);
    }
    return;
  }
  return;
}

/* FUN_000f83cc @ 0xf83cc (100 bytes) */
int FUN_000f83cc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  int iVar9;
  
  iVar9 = *(int *)(*(int *)(param_1 + 0x24) + 0x378);
  piVar3 = (int *)FUN_00193e18(iVar9,0x14);
  puVar8 = (uint *)(piVar3 + 1);
  *piVar3 = iVar9;
  piVar3[1] = 2;
  piVar3[2] = 0;
  piVar3[4] = iVar9;
  iVar9 = FUN_00193e18(iVar9,8);
  piVar3[3] = iVar9;
  iVar9 = *(int *)(param_1 + 0xc);
  while (*(int *)(*(int *)(param_2 * 4 + iVar9) * 4 + iVar9) != 0) {
    uVar2 = piVar3[2];
    if (uVar2 < *puVar8) {
      _memset((void *)(uVar2 * 4 + piVar3[3]),0,4);
      piVar4 = (int *)(uVar2 * 4 + piVar3[3]);
      piVar3[2] = uVar2 + 1;
    }
    else {
      piVar4 = (int *)FUN_0019423c(puVar8,uVar2);
    }
    *piVar4 = param_2;
    iVar9 = *(int *)(param_1 + 0xc);
    param_2 = *(int *)(param_2 * 4 + iVar9);
  }
  while (piVar3[2] != 0) {
    uVar2 = piVar3[2] - 1;
    piVar4 = (int *)0x0;
    if (uVar2 < (uint)piVar3[2]) {
      piVar4 = (int *)(uVar2 * 4 + piVar3[3]);
    }
    iVar9 = *piVar4;
    FUN_00194208(puVar8,piVar3[2] - 1);
    iVar6 = *(int *)(param_1 + 0xc);
    iVar9 = iVar9 * 4;
    iVar7 = *(int *)(param_1 + 0x10);
    iVar1 = *(int *)(iVar6 + iVar9) * 4;
    iVar5 = *(int *)(iVar7 + iVar1);
    if (*(uint *)(iVar5 * 4 + *(int *)(param_1 + 4)) <
        *(uint *)(*(int *)(iVar9 + iVar7) * 4 + *(int *)(param_1 + 4))) {
      *(int *)(iVar9 + iVar7) = iVar5;
      iVar6 = *(int *)(param_1 + 0xc);
    }
    *(undefined4 *)(iVar9 + iVar6) = *(undefined4 *)(iVar1 + iVar6);
  }
  if (puVar8 == (uint *)0x0) {
    return;
  }
  FUN_00193cc0(piVar3[4],piVar3[3]);
  iVar9 = *piVar3;
  if ((*(int *)(iVar9 + 0x28) != 0) && (piVar4 = *(int **)(iVar9 + 0x14), piVar4 == piVar3)) {
    _memset(piVar4,0,*(int *)(iVar9 + 8) - (int)piVar4);
    *(undefined4 *)(iVar9 + 8) = *(undefined4 *)(iVar9 + 0x14);
  }
  return;
}

/* FUN_000f8588 @ 0xf8588 (72 bytes) */
int FUN_000f8588(param_1, param_2)
  int param_1;
  int param_2;
{
  if (*(int *)(*(int *)(param_1 + 0xc) + param_2 * 4) != 0) {
    ((int (*)())FUN_000f83cc)(param_1,param_2);
  }
  return *(undefined4 *)(param_2 * 4 + *(int *)(param_1 + 0x10));
}

/* FUN_000f85d0 @ 0xf85d0 (740 bytes) */
int FUN_000f85d0(param_1)
  int *param_1;
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  int *piVar12;
  
  iVar5 = *(int *)(param_1[8] + 0x3a0);
  if (*(int *)(iVar5 + 0xe4) == 0) {
    iVar4 = *(int *)(param_1[8] + 900);
    for (iVar7 = *(int *)(iVar4 + 8); iVar7 != 0; iVar7 = *(int *)(iVar7 + 8)) {
      *(undefined4 *)(iVar4 + 0xe8) = *(undefined4 *)(iVar4 + 0xe4);
      iVar4 = iVar7;
    }
  }
  ((int (*)())FUN_000f816c)(param_1,iVar5);
  FUN_000ec468(param_1[8],param_1[6],param_1[7]);
  uVar6 = param_1[7];
  if (1 < uVar6) {
    iVar4 = uVar6 << 2;
    do {
      iVar8 = 0;
      iVar7 = *(int *)(param_1[6] + iVar4);
      for (uVar11 = 1; iVar2 = *(int *)(iVar7 + 0xd4), uVar11 <= *(uint *)(iVar2 + 4);
          uVar11 = uVar11 + 1) {
        iVar2 = *(int *)(iVar8 + *(int *)(iVar2 + 8));
        if (iVar2 != 0) {
          iVar9 = param_1[1];
          iVar2 = ((int (*)())FUN_000f8588)(param_1,*(undefined4 *)(iVar2 + 0xe4));
          uVar1 = *(uint *)(iVar2 * 4 + iVar9);
          if (uVar1 < *(uint *)(iVar4 + param_1[1])) {
            *(uint *)(iVar4 + param_1[1]) = uVar1;
          }
        }
        iVar8 = iVar8 + 4;
      }
      uVar10 = *(undefined4 *)(param_1[9] + 0x378);
      puVar3 = (undefined4 *)FUN_00193e18(uVar10,0xc);
      *puVar3 = uVar10;
      puVar3[1] = uVar6;
      puVar3[2] = 0;
      puVar3[2] = *(undefined4 *)(*(int *)(iVar4 + param_1[1]) * 4 + param_1[5]);
      *(undefined4 **)(*(int *)(iVar4 + param_1[1]) * 4 + param_1[5]) = puVar3 + 1;
      *(undefined4 *)(iVar4 + param_1[3]) = *(undefined4 *)(iVar4 + *param_1);
      for (piVar12 = *(int **)(*(int *)(iVar4 + *param_1) * 4 + param_1[5]); piVar12 != (int *)0x0;
          piVar12 = (int *)piVar12[1]) {
        iVar7 = *piVar12 * 4;
        iVar8 = ((int (*)())FUN_000f8588)(param_1,*piVar12);
        iVar2 = *(int *)(param_1[1] + iVar7);
        if (iVar2 == *(int *)(iVar8 * 4 + param_1[1])) {
          *(int *)(iVar7 + param_1[2]) = iVar2;
        }
        else {
          *(int *)(iVar7 + param_1[2]) = iVar8;
        }
      }
      uVar6 = uVar6 - 1;
      iVar4 = iVar4 + -4;
    } while (1 < uVar6);
  }
  *(undefined4 *)(param_1[2] + 4) = 0;
  uVar6 = param_1[7];
  if (1 < uVar6) {
    uVar11 = 2;
    do {
      iVar4 = uVar11 * 4;
      iVar7 = param_1[2];
      if (*(int *)(iVar4 + iVar7) != *(int *)(iVar4 + param_1[1])) {
        *(undefined4 *)(iVar4 + iVar7) = *(undefined4 *)(*(int *)(iVar4 + iVar7) * 4 + iVar7);
        uVar6 = param_1[7];
      }
      uVar11 = uVar11 + 1;
    } while (uVar11 <= uVar6);
  }
  if (uVar6 != 0) {
    iVar8 = param_1[6];
    iVar7 = 0;
    uVar6 = 1;
    iVar4 = 4;
    while( true ) {
      iVar4 = *(int *)(iVar4 + iVar8);
      *(int *)(iVar4 + 0xf0) = iVar7;
      if (iVar7 != 0) {
        FUN_000e8ce4(iVar7,iVar4);
      }
      uVar6 = uVar6 + 1;
      if ((uint)param_1[7] < uVar6) break;
      if (uVar6 == 1) {
        iVar8 = param_1[6];
        iVar7 = 0;
        iVar4 = 4;
      }
      else {
        iVar4 = uVar6 * 4;
        iVar8 = param_1[6];
        iVar7 = *(int *)(*(int *)(iVar4 + param_1[2]) * 4 + iVar8);
      }
    }
  }
  ((int (*)())FUN_000f7dbc)(param_1);
  if (*(int *)(iVar5 + 0xe8) == 0) {
    iVar5 = *(int *)(param_1[8] + 900);
    for (iVar4 = *(int *)(*(int *)(param_1[8] + 900) + 8); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8))
    {
      *(undefined4 *)(iVar5 + 0xe4) = *(undefined4 *)(iVar5 + 0xe8);
      iVar5 = iVar4;
    }
  }
  return;
}

/* FUN_000f88b4 @ 0xf88b4 (104 bytes) */
int FUN_000f88b4(param_1)
  int param_1;
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 0x378);
  piVar1 = (int *)FUN_00193e18(iVar3,0x2c);
  *piVar1 = iVar3;
  piVar2 = piVar1 + 1;
  ((int (*)())FUN_000f7cd8)(piVar2,param_1);
  ((int (*)())FUN_000f85d0)(piVar2);
  if (piVar2 == (int *)0x0) {
    return;
  }
  ((int (*)())FUN_000f8044)(piVar2);
  iVar3 = *piVar1;
  if ((*(int *)(iVar3 + 0x28) != 0) && (piVar2 = *(int **)(iVar3 + 0x14), piVar2 == piVar1)) {
    _memset(piVar2,0,*(int *)(iVar3 + 8) - (int)piVar2);
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 0x14);
  }
  return;
}

/* FUN_000f8960 @ 0xf8960 (16 bytes) */
int FUN_000f8960(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_1 * 0x24 + param_2 + 8);
}

/* FUN_000f8970 @ 0xf8970 (16 bytes) */
int FUN_000f8970(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_1 * 0x24 + param_2 + 4);
}

/* FUN_000f8980 @ 0xf8980 (20 bytes) */
int FUN_000f8980(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  return *(undefined1 *)(param_2 + param_1 * 0x24 + param_3 + 0x1c);
}

/* FUN_000f8994 @ 0xf8994 (16 bytes) */
int FUN_000f8994(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_1 * 0x24 + param_2 + 0xc);
}

/* FUN_000f89a4 @ 0xf89a4 (16 bytes) */
int FUN_000f89a4(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined4 *)(param_1 * 0x24 + param_2 + 0x10);
}

/* FUN_000f89b8 @ 0xf89b8 (48 bytes) */
int FUN_000f89b8(param_1)
  int param_1;
{
  byte in_cr7;
  
  if ((bool)(in_cr7 >> 2 & 1)) {
    return 8;
  }
  return *(undefined4 *)(PTR_DAT_001e8b84 + param_1 * 4);
}

/* FUN_000f89e8 @ 0xf89e8 (36 bytes) */
int FUN_000f89e8(param_1)
  int param_1;
{
  if (param_1 == 1) {
    return 0;
  }
  return 2 - (uint)(param_1 == 2);
}

/* FUN_000f8a0c @ 0xf8a0c (36 bytes) */
int FUN_000f8a0c(param_1)
  int param_1;
{
  if (param_1 == 1) {
    return 0;
  }
  if (param_1 == 2) {
    return 1;
  }
  return 3;
}

/* FUN_000f8a30 @ 0xf8a30 (112 bytes) */
double FUN_000f8a30(int param_1,int param_2,int param_3,int param_4)
{
  undefined *puVar1;
  double dVar2;
  
  puVar1 = PTR_DAT_001e8bb8;
  if (param_1 == 4) {
    dVar2 = (double)FLOAT_001aa0d4;
    *(undefined1 *)(param_3 + param_2) = 0;
    return dVar2;
  }
  if (param_1 == 5) {
    dVar2 = (double)FLOAT_001aa0e8;
    *(undefined1 *)(param_3 + param_2) = 0;
    return dVar2;
  }
  *(undefined1 *)(param_3 + param_2) = 1;
  dVar2 = (double)FLOAT_001aa0d4;
  *(char *)(param_4 + param_2) = (char)*(undefined4 *)(puVar1 + param_1 * 4);
  return dVar2;
}

/* FUN_000f8aa0 @ 0xf8aa0 (488 bytes) */
int FUN_000f8aa0(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  uint *param_2;
  uint *param_3;
  int param_4;
  int *param_5;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  char local_38 [32];
  
  local_38[0] = '\0';
  local_38[1] = 1;
  local_38[2] = 2;
  local_38[3] = 3;
  uVar3 = *param_2;
  if (param_3 != (uint *)0x0) {
    uVar2 = *param_3;
    if ((uVar2 & 0x400000) != 0) {
      uVar1 = param_3[1];
      if ((uVar1 >> 3 & 1 & uVar1 >> 7 & 1 & uVar1 >> 0xb & 1 & uVar1 >> 0xf & 1) != 0) {
        FUN_00103d50(param_5 + param_4 * 6 + 0x23,1,param_5[param_4 * 6 + 0x28] & 1U ^ 1);
        uVar2 = *param_3;
      }
    }
    if (((uVar2 & 0x400000) != 0) && ((param_3[1] & 0x100000) != 0)) {
      FUN_00103d50(param_5 + param_4 * 6 + 0x23,2,1);
    }
    local_38[0] = FUN_0019e9fc(param_3,0);
    local_38[1] = FUN_0019e9fc(param_3,1);
    local_38[2] = FUN_0019e9fc(param_3,2);
    local_38[3] = FUN_0019e9fc(param_3,3);
  }
  (**(code **)(*param_5 + 0x88))(param_5,param_4,0,(int)local_38[uVar3 >> 0x18]);
  (**(code **)(*param_5 + 0x88))(param_5,param_4,1,(int)local_38[uVar3 >> 0x10 & 0xff]);
  (**(code **)(*param_5 + 0x88))(param_5,param_4,2,(int)local_38[uVar3 >> 8 & 0xff]);
  (**(code **)(*param_5 + 0x88))(param_5,param_4,3,(int)local_38[uVar3 & 0xff]);
  *param_2 = DAT_001aa9a8;
  return;
}

/* FUN_000f8c88 @ 0xf8c88 (64 bytes) */
int FUN_000f8c88(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = param_1 + -0x30;
  if ((1 < iVar1) && (iVar1 = 2, param_1 != 0x5f)) {
    iVar1 = param_1 + -0x74;
  }
  return *(undefined4 *)(&DAT_001aa9e4 + iVar1 * 4);
}

/* FUN_000f8ccc @ 0xf8ccc (132 bytes) */
int FUN_000f8ccc(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0xdc))(*(int **)(param_2 + 0x30c));
  if (iVar1 == 0) {
    puVar2 = (PTR_DAT_001e9f7c)[param_1 * 3];
  }
  else if (param_3 == 0) {
    puVar2 = (PTR_DAT_001e9f80)[param_1 * 3];
  }
  else {
    puVar2 = (PTR_DAT_001e9f78)[param_1 * 3];
  }
  return puVar2;
}

/* FUN_000f8d50 @ 0xf8d50 (568 bytes) */
int FUN_000f8d50(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  uint *param_4;
  undefined4 param_5;
  int param_6;
  int param_7;
{
  undefined *puVar1;
  undefined1 uVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 *puVar7;
  char *pcVar8;
  code *pcVar9;
  undefined4 uVar10;
  int *piVar11;
  int iVar12;
  undefined4 uStack00000020;
  char local_38 [28];
  
  uStack00000020 = param_3;
  local_38[0] = '\0';
  local_38[1] = '\0';
  local_38[2] = '\0';
  local_38[3] = '\0';
  if (param_4 != (uint *)0x0) {
    uVar6 = *param_4;
    if ((uVar6 & 0x1800000) == 0x800000) {
      if (*(int *)(param_1 + 0x3e4) == 0) {
        *(undefined4 *)(param_1 + 0x3f4) = *(undefined4 *)(param_6 + 0x98);
        *(undefined4 *)(param_1 + 0x3e4) = 1;
      }
      uVar5 = *(undefined4 *)(param_1 + 0x3ac);
      uVar10 = *(undefined4 *)(param_6 + 0x94);
      iVar4 = *(int *)(*(int *)(param_1 + 8) + 0x3c0) + 1;
      *(int *)(*(int *)(param_1 + 8) + 0x3c0) = iVar4;
      iVar4 = FUN_00127608(uVar5,0x2a,iVar4,0);
      *(undefined4 *)(iVar4 + 0x30) = uVar10;
      FUN_001046c8(param_6,0,iVar4);
      uVar6 = *param_4;
    }
    if (((uVar6 & 0x400000) != 0) && ((param_4[1] & 0x100) != 0)) {
      piVar11 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
      pcVar9 = *(code **)(*piVar11 + 0x78);
      uVar5 = FUN_000ec208(param_1,uVar6 >> 0x10 & 0x3f);
      iVar4 = (*pcVar9)(piVar11,uVar5);
      if (iVar4 == 0) {
        iVar4 = FUN_000ec208(param_1,*param_4 >> 0x10 & 0x3f);
        if (iVar4 != 9) {
          FUN_000ec208(param_1,*param_4 >> 0x10 & 0x3f);
        }
      }
      else {
        *(undefined4 *)(param_6 + 0x120) = 1;
      }
    }
    iVar4 = FUN_0019e990(param_4,0);
    puVar1 = PTR_DAT_001e8bc8;
    local_38[0] = (char)*(undefined4 *)(PTR_DAT_001e8bc8 + iVar4 * 4);
    iVar4 = FUN_0019e990(param_4,1);
    local_38[1] = (char)*(undefined4 *)(puVar1 + iVar4 * 4);
    iVar4 = FUN_0019e990(param_4,2);
    local_38[2] = (char)*(undefined4 *)(puVar1 + iVar4 * 4);
    iVar4 = FUN_0019e990(param_4,3);
    local_38[3] = (char)*(undefined4 *)(puVar1 + iVar4 * 4);
  }
  if (param_7 == 0) {
    iVar12 = 4;
    iVar4 = 0;
    pcVar8 = (char *)&STACKARG(0x20);
    do {
      cVar3 = local_38[iVar4];
      if (*pcVar8 != '\0') {
        cVar3 = *pcVar8;
      }
      *(char *)(param_6 + 0x9c) = cVar3;
      iVar4 = iVar4 + 1;
      pcVar8 = pcVar8 + 1;
      param_6 = param_6 + 1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  else {
    iVar12 = 4;
    iVar4 = 0;
    puVar7 = (undefined1 *)&STACKARG(0x20);
    do {
      uVar2 = 1;
      if (local_38[iVar4] != '\x01') {
        uVar2 = *puVar7;
      }
      *(undefined1 *)(param_6 + 0x9c) = uVar2;
      iVar4 = iVar4 + 1;
      puVar7 = puVar7 + 1;
      param_6 = param_6 + 1;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  return;
}

/* FUN_000f8f88 @ 0xf8f88 (176 bytes) */
int FUN_000f8f88(param_1, param_2)
  uint *param_1;
  int *param_2;
{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  
  puVar2 = PTR_DAT_001e8bb8;
  iVar4 = 0;
  do {
    iVar3 = FUN_0019e9fc(param_1,iVar4);
    (**(code **)(*param_2 + 0x88))(param_2,1,iVar4,*(undefined4 *)(puVar2 + iVar3 * 4));
    bVar1 = iVar4 != 3;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  if ((*param_1 & 0x400000) != 0) {
    param_1[1] = param_1[1] & 0xffff8888 | 0x3210;
  }
  return;
}

/* FUN_000f9038 @ 0xf9038 (264 bytes) */
int FUN_000f9038(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  int iVar2;
  double dVar3;
  
  uVar1 = FUN_001043f0(0x17,*(undefined4 *)(param_1 + 8));
  iVar2 = FUN_001054ec(uVar1,0);
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 8) = param_2;
  iVar2 = FUN_001054ec(uVar1,1);
  dVar3 = (double)FLOAT_001aa0d4;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 8) = param_2;
  ((void (*)())FUN_000f79c4)(uVar1,param_1,2,dVar3,dVar3,dVar3,dVar3);
  FUN_00193f64(param_3,uVar1);
  uVar1 = FUN_001043f0(0x19,*(undefined4 *)(param_1 + 8));
  iVar2 = FUN_001054ec(uVar1,0);
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 8) = param_2;
  iVar2 = FUN_001054ec(uVar1,1);
  dVar3 = (double)FLOAT_001aa0e8;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 8) = param_2;
  ((void (*)())FUN_000f79c4)(uVar1,param_1,2,dVar3,dVar3,dVar3,dVar3);
  FUN_00193f64(param_3,uVar1);
  return uVar1;
}

/* FUN_000f9140 @ 0xf9140 (284 bytes) */
int FUN_000f9140(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0xc);
  iVar3 = (**(code **)(param_2 * 0x24 + iVar3 + 0x14))
                    (*(undefined4 *)(param_2 * 0x24 + iVar3),*(int *)(param_1 + 8));
  if ((param_3 != 0) &&
     (iVar1 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0xb0))(), iVar1 != 0)) {
    switch(param_2) {
    case 0x22:
      uVar2 = FUN_00112f54(0xdf);
      *(undefined4 *)(iVar3 + 0x88) = uVar2;
      break;
    case 0x23:
      uVar2 = FUN_00112f54(0xde);
      *(undefined4 *)(iVar3 + 0x88) = uVar2;
      break;
    case 0x40:
      uVar2 = FUN_00112f54(0xf0);
      *(undefined4 *)(iVar3 + 0x88) = uVar2;
      break;
    case 0x41:
      uVar2 = FUN_00112f54(0xb7);
      *(undefined4 *)(iVar3 + 0x88) = uVar2;
      break;
    case 0x44:
      uVar2 = FUN_00112f54(0xb8);
      *(undefined4 *)(iVar3 + 0x88) = uVar2;
      break;
    case 0x49:
      uVar2 = FUN_00112f54(0xb6);
      *(undefined4 *)(iVar3 + 0x88) = uVar2;
    }
  }
  return iVar3;
}

/* FUN_000f92fc @ 0xf92fc (480 bytes) */
int FUN_000f92fc(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  undefined4 param_3;
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar2 = (**(code **)(*param_2 + 0x30))(param_2);
  if ((iVar2 != 0) &&
     (piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x30c),
     iVar2 = (**(code **)(*piVar3 + 0x168))(piVar3,param_1,param_2), iVar2 != 0)) {
    uVar4 = FUN_001043f0(0x13,*(undefined4 *)(param_1 + 8));
    iVar5 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar5;
    iVar2 = FUN_001054ec(uVar4,0);
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(int *)(iVar2 + 8) = iVar5;
    uVar1 = param_2[0x4d];
    ((int (*)())FUN_000f771c)(uVar4,param_1,1,uVar1 & 0xffff | 0x60000,uVar1 & 0xffff | 0x70000,
                 uVar1 & 0xffff | 0x70000,uVar1 & 0xffff | 0x70000);
    iVar6 = param_2[0x2b];
    iVar8 = param_2[0x2c];
    iVar2 = FUN_001054ec(uVar4,2);
    *(int *)(iVar2 + 0xc) = iVar8;
    *(int *)(iVar2 + 8) = iVar6;
    ((int (*)())FUN_000f92fc)(param_1,(int *)uVar4,param_3);
    iVar2 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar6 = FUN_001054ec(iVar2,0);
    *(undefined4 *)(iVar6 + 0xc) = 0;
    uVar4 = DAT_001aaa20;
    *(int *)(iVar6 + 8) = iVar5;
    *(undefined4 *)(iVar2 + 0x9c) = uVar4;
    iVar8 = param_2[0x2b];
    iVar7 = param_2[0x2c];
    iVar6 = FUN_001054ec(iVar2,1);
    *(int *)(iVar6 + 8) = iVar8;
    *(int *)(iVar6 + 0xc) = iVar7;
    ((int (*)())FUN_000f92fc)(param_1,(int *)iVar2,param_3);
    iVar2 = FUN_001054ec(param_2,1);
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(int *)(iVar2 + 8) = iVar5;
  }
  FUN_000e7688(param_3,param_2);
  FUN_000ed63c(param_1,param_2);
                    
                    
  (**(code **)(*param_2 + 8))(param_2,*(undefined4 *)(param_1 + 8));
  return;
}

/* FUN_000f94dc @ 0xf94dc (968 bytes) */
int FUN_000f94dc(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  uint *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  uint uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 local_68 [4];
  undefined4 local_58 [4];
  
  if (*(int *)(param_1 + 0x374) == 0) {
    uVar9 = 0;
    switch(param_7) {
    case 0:
      uVar9 = 1;
      break;
    case 1:
      uVar9 = 2;
      break;
    case 2:
      uVar9 = 3;
      break;
    case 3:
      uVar9 = 4;
      break;
    case 4:
      uVar9 = 6;
    }
    FUN_000e79d0(*(undefined4 *)(param_1 + 0x3a0));
    uVar2 = FUN_000e920c(*(undefined4 *)(param_1 + 0x3a0),0);
    uVar14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
    puVar3 = (undefined4 *)FUN_00193e18(uVar14,0x168);
    *puVar3 = uVar14;
    puVar12 = puVar3 + 1;
    FUN_00109cfc(puVar12,0x83,*(undefined4 *)(param_1 + 8));
    iVar4 = FUN_001054ec(puVar12,0);
    *(undefined4 *)(iVar4 + 0xc) = 0x39;
    *(undefined4 *)(iVar4 + 8) = 0;
    uVar1 = uVar9;
    if (3 < uVar9) {
      uVar1 = 3;
    }
    puVar3[0x22] = uVar1;
    puVar10 = (undefined4 *)0x0;
    if (uVar9 != 0) {
      uVar1 = 0;
      iVar4 = 1;
      iVar11 = -2;
      do {
        iVar13 = uVar1 + 2;
        iVar5 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        FUN_00130478(param_1,iVar13);
        iVar6 = FUN_001054ec(iVar5,0);
        uVar14 = DAT_001aa9d0;
        *(int *)(iVar6 + 8) = iVar13;
        *(undefined4 *)(iVar6 + 0xc) = 0x10;
        *(undefined4 *)(iVar5 + 0x9c) = uVar14;
        FUN_00130444(param_1,iVar13);
        FUN_00130bd4(param_1,iVar13);
        piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
        uVar14 = (**(code **)(*piVar7 + 0x9c))(piVar7,uVar1);
        iVar6 = FUN_001054ec(iVar5,1);
        *(undefined4 *)(iVar6 + 8) = uVar14;
        *(undefined4 *)(iVar6 + 0xc) = 0x1f;
        piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
        (**(code **)(*piVar7 + 0xa0))(local_58,piVar7,uVar1);
        uVar14 = local_58[0];
        iVar6 = FUN_001054ec(iVar5,1);
        *(undefined4 *)(iVar6 + 0x10) = uVar14;
        ((int (*)())FUN_000f92fc)(param_1,iVar5,uVar2);
        if ((int)uVar1 < 3) {
          FUN_001046c8(puVar12,iVar4,*(undefined4 *)(iVar5 + 0x8c));
          uVar14 = DAT_001aa9cc;
          if (iVar4 == 0) {
            puVar3[0x28] = DAT_001aa9cc;
          }
          else {
            iVar5 = FUN_001054ec(puVar12,iVar4);
            *(undefined4 *)(iVar5 + 0x10) = uVar14;
          }
        }
        else {
          if (puVar10 == (undefined4 *)0x0) {
            uVar14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
            puVar8 = (undefined4 *)FUN_00193e18(uVar14,0x168);
            *puVar8 = uVar14;
            puVar10 = puVar8 + 1;
            FUN_00109cfc(puVar10,0x83,*(undefined4 *)(param_1 + 8));
            iVar6 = FUN_001054ec(puVar10,0);
            *(undefined4 *)(iVar6 + 0xc) = 0x39;
            uVar14 = 4;
            *(undefined4 *)(iVar6 + 8) = 1;
            if (uVar9 == 4) {
              uVar14 = 2;
            }
            puVar8[0x22] = uVar14;
          }
          FUN_001046c8(puVar10,iVar11,*(undefined4 *)(iVar5 + 0x8c));
          uVar14 = DAT_001aa9cc;
          if (iVar11 == 0) {
            puVar10[0x27] = DAT_001aa9cc;
          }
          else {
            iVar5 = FUN_001054ec(puVar10,iVar11);
            *(undefined4 *)(iVar5 + 0x10) = uVar14;
          }
        }
        uVar14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar8 = (undefined4 *)FUN_00193e18(uVar14,0x168);
        *puVar8 = uVar14;
        puVar8 = puVar8 + 1;
        FUN_00109428(puVar8,0x7a,*(undefined4 *)(param_1 + 8));
        iVar5 = FUN_001054ec(puVar8,0);
        *(undefined4 *)(iVar5 + 0xc) = 0x10;
        uVar1 = uVar1 + 1;
        *(int *)(iVar5 + 8) = iVar13;
        iVar4 = iVar4 + 1;
        iVar11 = iVar11 + 1;
        ((int (*)())FUN_000f92fc)(param_1,puVar8,*(undefined4 *)(param_1 + 0x3a0));
      } while (uVar9 != uVar1);
    }
    ((int (*)())FUN_000f92fc)(param_1,puVar12,uVar2);
    if (puVar10 == (undefined4 *)0x0) {
      *(undefined4 **)(param_1 + 0x374) = puVar12;
    }
    else {
      uVar14 = 2;
      if (uVar9 != 4) {
        uVar14 = 4;
      }
      FUN_001046c8(puVar10,uVar14,puVar3[0x24]);
      ((int (*)())FUN_000f92fc)(param_1,puVar10,uVar2);
      *(undefined4 **)(param_1 + 0x374) = puVar10;
    }
  }
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  puVar3 = (undefined4 *)FUN_00193e18(uVar2,0x168);
  *puVar3 = uVar2;
  puVar12 = puVar3 + 1;
  FUN_00109e28(puVar12,0x84,*(undefined4 *)(param_1 + 8));
  iVar5 = *(int *)(*(int *)(param_1 + 8) + 0x3b4) + 1;
  *(int *)(*(int *)(param_1 + 8) + 0x3b4) = iVar5;
  iVar4 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x3a,iVar5,0);
  *(undefined4 *)(iVar4 + 0x30) = 2;
  FUN_001046c8(puVar12,0,iVar4);
  uVar9 = *param_3;
  uVar2 = FUN_000ec208(param_1,*param_3 >> 0x10 & 0x3f);
  iVar4 = FUN_001054ec(puVar12,1);
  local_68[0] = DAT_001aa9a8;
  *(undefined4 *)(iVar4 + 0xc) = uVar2;
  *(uint *)(iVar4 + 8) = (uint)(ushort)uVar9;
  ((int (*)())FUN_000f8aa0)(param_1,local_68,param_3,1,puVar12);
  puVar3[0x4d] = 1;
  FUN_00193f64(param_2,puVar12);
  iVar4 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
  uVar14 = FUN_000ec208(param_1,param_6);
  iVar11 = FUN_001054ec(iVar4,0);
  uVar2 = DAT_001aa9d0;
  *(undefined4 *)(iVar11 + 0xc) = uVar14;
  *(undefined4 *)(iVar11 + 8) = param_5;
  *(undefined4 *)(iVar4 + 0x9c) = uVar2;
  iVar11 = FUN_001054ec(iVar4,1);
  *(undefined4 *)(iVar11 + 0xc) = 0x3a;
  *(int *)(iVar11 + 8) = iVar5;
  FUN_001049e8(iVar4,*(undefined4 *)(*(int *)(param_1 + 0x374) + 0x8c));
  FUN_00193f64(param_2,iVar4);
  return;
}

/* FUN_000f9a58 @ 0xf9a58 (2736 bytes) */
int FUN_000f9a58(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  uint *param_3;
  undefined4 param_4;
  int param_5;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  code *pcVar13;
  uint uVar14;
  undefined4 uVar15;
  uint uVar16;
  int *piVar17;
  undefined4 uVar18;
  int iVar19;
  undefined4 *puVar20;
  int iVar21;
  double dVar22;
  undefined4 local_68;
  undefined4 local_64 [7];
  
  iVar7 = (int)(short)*param_3;
  uVar9 = *param_3 >> 0x10 & 0x3f;
  if (((*param_3 & 0x400000) == 0) || (uVar12 = param_3[1] >> 9 & 0xf, uVar12 == 0)) {
    iVar3 = 0;
    iVar19 = 0;
  }
  else {
    iVar19 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar19;
    *(short *)((int)param_3 + 2) = (short)iVar19;
    *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    iVar3 = FUN_001043f0(0x13,*(undefined4 *)(param_1 + 8));
    iVar4 = FUN_001054ec(iVar3,0);
    *(undefined4 *)(iVar4 + 0xc) = 0;
    *(int *)(iVar4 + 8) = iVar19;
    iVar4 = FUN_001054ec(iVar3,1);
    *(undefined4 *)(iVar4 + 0xc) = 0;
    dVar22 = (double)*(float *)(&DAT_001aa9fc + uVar12 * 4);
    *(int *)(iVar4 + 8) = iVar19;
    ((void (*)())FUN_000f79c4)(iVar3,param_1,2,dVar22,dVar22,dVar22,dVar22);
    FUN_00193f64(param_2,iVar3);
  }
  uVar12 = 0;
  uVar16 = 0;
  do {
    iVar4 = FUN_0019e990(param_3,uVar16);
    bVar1 = uVar16 != 3;
    uVar12 = uVar12 | (uint)(iVar4 == 2) << (uVar16 & 0x3f);
    uVar16 = uVar16 + 1;
  } while (bVar1);
  if (uVar12 != 0) {
    if (iVar3 == 0) {
      iVar19 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar19;
      *(short *)((int)param_3 + 2) = (short)iVar19;
      *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    }
    iVar3 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar4 = FUN_001054ec(iVar3,0);
    dVar22 = (double)FLOAT_001aa0d4;
    *(undefined4 *)(iVar4 + 0xc) = 0;
    *(int *)(iVar4 + 8) = iVar19;
    ((void (*)())FUN_000f79c4)(iVar3,param_1,1,dVar22,dVar22,dVar22,dVar22);
    iVar21 = 4;
    uVar16 = 0;
    iVar4 = iVar3;
    do {
      if (((int)uVar12 >> (uVar16 & 0x3f) & 1U) == 0) {
        *(undefined1 *)(iVar4 + 0x9c) = 1;
      }
      else {
        *(undefined1 *)(iVar4 + 0x9c) = 0;
      }
      uVar16 = uVar16 + 1;
      iVar4 = iVar4 + 1;
      iVar21 = iVar21 + -1;
    } while (iVar21 != 0);
    FUN_00193f64(param_2,iVar3);
  }
  uVar12 = 0;
  uVar16 = 0;
  do {
    iVar4 = FUN_0019e990(param_3,uVar16);
    bVar1 = uVar16 != 3;
    uVar12 = uVar12 | (uint)(iVar4 == 3) << (uVar16 & 0x3f);
    uVar16 = uVar16 + 1;
  } while (bVar1);
  if (uVar12 != 0) {
    if (iVar3 == 0) {
      iVar19 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar19;
      *(short *)((int)param_3 + 2) = (short)iVar19;
      *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    }
    iVar3 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar4 = FUN_001054ec(iVar3,0);
    dVar22 = (double)FLOAT_001aa0e8;
    *(undefined4 *)(iVar4 + 0xc) = 0;
    *(int *)(iVar4 + 8) = iVar19;
    ((void (*)())FUN_000f79c4)(iVar3,param_1,1,dVar22,dVar22,dVar22,dVar22);
    iVar21 = 4;
    uVar16 = 0;
    iVar4 = iVar3;
    do {
      if (((int)uVar12 >> (uVar16 & 0x3f) & 1U) == 0) {
        *(undefined1 *)(iVar4 + 0x9c) = 1;
      }
      else {
        *(undefined1 *)(iVar4 + 0x9c) = 0;
      }
      uVar16 = uVar16 + 1;
      iVar4 = iVar4 + 1;
      iVar21 = iVar21 + -1;
    } while (iVar21 != 0);
    FUN_00193f64(param_2,iVar3);
  }
  uVar12 = DAT_001aa9dc;
  if ((*param_3 & 0x400000) != 0) {
    uVar12 = param_3[1];
    uVar12 = (uint)((uVar12 & 0xc0) == 0) |
             (uint)((uVar12 & 0x30) == 0) << 8 |
             (uint)((uVar12 & 0xc) == 0) << 0x10 | (uint)((uVar12 & 3) == 0) << 0x18;
  }
  iVar4 = FUN_0019eb30(param_3);
  if (iVar4 != 0) {
    iVar3 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar4 = FUN_001054ec(iVar3,0);
    *(undefined4 *)(iVar4 + 0xc) = 0;
    *(int *)(iVar4 + 8) = iVar19;
    iVar4 = FUN_001054ec(iVar3,1);
    *(undefined4 *)(iVar4 + 0xc) = 0;
    *(int *)(iVar4 + 8) = iVar19;
    FUN_00193f64(param_2,iVar3);
  }
  uVar16 = *param_3;
  if (((uVar16 & 0x400000) == 0) || ((param_3[1] & 0x100) == 0)) {
LAB_000f9f08:
    bVar1 = false;
  }
  else {
    piVar17 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
    pcVar13 = *(code **)(*piVar17 + 0x78);
    uVar5 = FUN_000ec208(param_1,uVar9);
    iVar4 = (*pcVar13)(piVar17,uVar5);
    if (iVar4 == 0) {
      iVar19 = FUN_000ec208(param_1,*param_3 >> 0x10 & 0x3f);
      if (iVar19 == 9) {
        uVar16 = *param_3;
        goto LAB_000f9f08;
      }
      FUN_000ec208(param_1,*param_3 >> 0x10 & 0x3f);
      uVar16 = *param_3;
      bVar1 = false;
    }
    else {
      iVar4 = (**(code **)(**(int **)(*(int *)(param_1 + 8) + 0x30c) + 0x80))();
      if (iVar4 == 0) {
        if (iVar3 == 0) {
          iVar19 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar19;
          *(short *)((int)param_3 + 2) = (short)iVar19;
          *param_3 = *param_3 & 0xffc0ffff | 0x40000;
        }
        iVar3 = ((int (*)())FUN_000f9038)(param_1,iVar19,param_2);
        uVar16 = *param_3;
        if ((uVar16 & 0x400000) == 0) goto LAB_000f9f08;
        bVar1 = false;
        param_3[1] = param_3[1] & 0xfffffeff;
      }
      else {
        uVar16 = *param_3;
        bVar1 = true;
      }
    }
  }
  if (iVar3 != 0) {
    if ((uVar16 & 0x1800000) == 0x800000) {
      if (*(int *)(param_1 + 0x3e4) == 0) {
        *(undefined4 *)(param_1 + 0x3e4) = 1;
        uVar5 = FUN_000ec208(param_1,uVar9);
        *(undefined4 *)(param_1 + 0x3f4) = uVar5;
      }
      else {
        FUN_000ec208(param_1,uVar9);
      }
      uVar5 = *(undefined4 *)(param_1 + 0x3ac);
      iVar19 = *(int *)(*(int *)(param_1 + 8) + 0x3c0) + 1;
      *(int *)(*(int *)(param_1 + 8) + 0x3c0) = iVar19;
      iVar19 = FUN_00127608(uVar5,0x2a,iVar19,0);
      *(int *)(iVar19 + 0x30) = iVar7;
      FUN_001046c8(iVar3,0,iVar19);
      *param_3 = *param_3 & 0xfe7fffff;
    }
    else {
      uVar5 = FUN_000ec208(param_1,uVar9);
      iVar19 = FUN_001054ec(iVar3,0);
      *(undefined4 *)(iVar19 + 0xc) = uVar5;
      *(int *)(iVar19 + 8) = iVar7;
    }
    if (bVar1) {
      *(undefined4 *)(iVar3 + 0x120) = 1;
    }
    if ((*param_3 & 0x400000) != 0) {
      param_3[1] = param_3[1] & 0xfffffeff;
    }
    iVar19 = 0;
    do {
      iVar4 = FUN_0019e990(param_3,iVar19);
      if (iVar4 == 0) {
        *(undefined1 *)(iVar3 + 0x9c) = 1;
      }
      else {
        *(undefined1 *)(iVar3 + 0x9c) = 0;
      }
      bVar1 = iVar19 != 3;
      iVar3 = iVar3 + 1;
      iVar19 = iVar19 + 1;
    } while (bVar1);
    uVar16 = *param_3;
    if ((uVar16 & 0x400000) != 0) {
      param_3[1] = param_3[1] & 0xffffff00 | 0x55;
    }
  }
  if ((uVar9 != 0x1f) || ((*(uint *)(param_1 + 0x30) & 0x4000) == 0)) {
    bVar1 = false;
    bVar2 = false;
  }
  else {
    bVar1 = true;
    bVar2 = true;
  }
  if (((undefined4 *)(uVar16 & 0x3f0000) != &DAT_001b0000) && (!bVar1)) goto LAB_000fa744;
  iVar3 = 1;
  iVar19 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar19;
  uVar16 = *param_3;
  uVar11 = (uint)(ushort)*param_3;
  uVar10 = uVar16 >> 0x10 & 0x3f;
  if ((int)uVar16 < 0) {
    iVar3 = 2;
    uVar11 = uVar11 | param_3[1] << 0x10;
  }
  if ((uVar16 & 0x400000) != 0) {
    iVar3 = iVar3 + 1;
  }
  if ((uVar16 & 0x1800000) == 0x1000000) {
    puVar8 = param_3 + iVar3;
    if (!bVar2) {
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar6 = (undefined4 *)FUN_00193e18(uVar5,0x168);
      *puVar6 = uVar5;
      puVar20 = puVar6 + 1;
      FUN_001071fc(puVar20,0xfc,*(undefined4 *)(param_1 + 8));
      uVar5 = FUN_000ec208(param_1,uVar10);
      iVar4 = FUN_001054ec(puVar20,0);
      *(undefined4 *)(iVar4 + 0xc) = uVar5;
      *(uint *)(iVar4 + 8) = uVar11;
      uVar5 = FUN_000ec208(param_1,4);
      iVar4 = FUN_001054ec(puVar20,1);
      puVar6[0x28] = uVar12;
      *(undefined4 *)(iVar4 + 0xc) = uVar5;
      *(int *)(iVar4 + 8) = iVar19;
      if ((*param_3 & 0x4000000) == 0) goto LAB_000fa1bc;
      iVar4 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar4;
      uVar16 = param_3[iVar3 + 2];
      uVar5 = FUN_001043f0(0xc6,*(undefined4 *)(param_1 + 8));
      uVar15 = FUN_000ec208(param_1,4);
      iVar3 = FUN_001054ec(uVar5,0);
      *(undefined4 *)(iVar3 + 0xc) = uVar15;
      *(int *)(iVar3 + 8) = iVar4;
      uVar12 = *puVar8;
      uVar15 = FUN_000ec208(param_1,*puVar8 >> 0x10 & 0x3f);
      iVar3 = FUN_001054ec(uVar5,1);
      *(undefined4 *)(iVar3 + 0xc) = uVar15;
      *(uint *)(iVar3 + 8) = (uint)(ushort)uVar12;
      ((int (*)())FUN_000f7870)(uVar5,param_1,2,uVar16,uVar16,uVar16,uVar16);
      FUN_00193f64(param_2,uVar5);
      uVar5 = FUN_000ec208(param_1,4);
      iVar3 = FUN_001054ec(puVar20,2);
      *(undefined4 *)(iVar3 + 0xc) = uVar5;
      *(int *)(iVar3 + 8) = iVar4;
    }
    else {
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar6 = (undefined4 *)FUN_00193e18(uVar5,0x168);
      *puVar6 = uVar5;
      puVar20 = puVar6 + 1;
      FUN_00108a50(puVar20,0xf9,*(undefined4 *)(param_1 + 8));
      puVar6[0x28] = uVar12;
      puVar6[0x22] = 2;
      if ((*param_3 & 0x4000000) != 0) {
        uVar11 = uVar11 + param_3[iVar3 + 2];
      }
      puVar6[0x51] = uVar11;
      puVar6[0x50] = 0x24;
      uVar5 = FUN_00127608(*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x6c4) + 0x3ac),0x2c,0,0
                          );
      FUN_001046c8(puVar20,0,uVar5);
      iVar3 = FUN_001054ec(puVar20,1);
      *(undefined4 *)(iVar3 + 0xc) = 0;
      *(int *)(iVar3 + 8) = iVar19;
LAB_000fa1bc:
      uVar12 = *puVar8;
      uVar5 = FUN_000ec208(param_1,*puVar8 >> 0x10 & 0x3f);
      iVar3 = FUN_001054ec(puVar20,2);
      *(undefined4 *)(iVar3 + 0xc) = uVar5;
      *(uint *)(iVar3 + 8) = (uint)(ushort)uVar12;
      if (bVar2) goto LAB_000fa4f8;
    }
    uVar5 = FUN_000ec208(param_1,uVar10);
    iVar3 = FUN_001054ec(puVar20,3);
    local_64[0] = DAT_001aa9a8;
    *(undefined4 *)(iVar3 + 0xc) = uVar5;
    *(uint *)(iVar3 + 8) = uVar11;
    ((int (*)())FUN_000f8aa0)(param_1,local_64,puVar8,2,puVar20);
  }
  else if ((uVar16 & 0x1800000) == 0) {
    uVar14 = 0;
    if ((uVar16 & 0x4000000) != 0) {
      uVar14 = param_3[iVar3];
    }
    if (bVar2) {
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar6 = (undefined4 *)FUN_00193e18(uVar5,0x168);
      *puVar6 = uVar5;
      puVar20 = puVar6 + 1;
      FUN_00108770(puVar20,*(undefined4 *)(param_1 + 8));
      puVar6[0x28] = uVar12;
      puVar6[0x50] = 0x24;
      puVar6[0x51] = uVar11;
      uVar5 = FUN_00127608(*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x6c4) + 0x3ac),0x2c,0,0
                          );
      FUN_001046c8(puVar20,0,uVar5);
      iVar3 = FUN_001054ec(puVar20,1);
      *(undefined4 *)(iVar3 + 0xc) = 0;
      *(int *)(iVar3 + 8) = iVar19;
    }
    else {
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar6 = (undefined4 *)FUN_00193e18(uVar5,0x168);
      *puVar6 = uVar5;
      puVar20 = puVar6 + 1;
      FUN_001071fc(puVar20,0xfc,*(undefined4 *)(param_1 + 8));
      uVar5 = FUN_000ec208(param_1,uVar10);
      iVar3 = FUN_001054ec(puVar20,0);
      *(undefined4 *)(iVar3 + 0xc) = uVar5;
      *(uint *)(iVar3 + 8) = uVar11;
      uVar5 = FUN_000ec208(param_1,4);
      iVar3 = FUN_001054ec(puVar20,1);
      *(undefined4 *)(iVar3 + 0xc) = uVar5;
      *(int *)(iVar3 + 8) = iVar19;
      ((int (*)())FUN_000f7870)(puVar20,param_1,2,uVar14,uVar14,uVar14,uVar14);
      puVar6[0x28] = uVar12;
    }
  }
  else {
    puVar20 = (undefined4 *)0x0;
  }
LAB_000fa4f8:
  iVar3 = FUN_001054ec(puVar20,2);
  local_68 = *(undefined4 *)(iVar3 + 0x10);
  piVar17 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
  iVar3 = (**(code **)(*piVar17 + 0x104))(piVar17,puVar20,2,&local_68,0);
  if (iVar3 == 0) {
    iVar4 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar4;
    uVar5 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    uVar18 = puVar20[0x32];
    uVar15 = puVar20[0x31];
    iVar3 = FUN_001054ec(uVar5,1);
    *(undefined4 *)(iVar3 + 0xc) = uVar18;
    *(undefined4 *)(iVar3 + 8) = uVar15;
    uVar15 = FUN_000ec208(param_1,4);
    iVar3 = FUN_001054ec(uVar5,0);
    *(undefined4 *)(iVar3 + 0xc) = uVar15;
    *(int *)(iVar3 + 8) = iVar4;
    iVar3 = FUN_001054ec(puVar20,2);
    uVar15 = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = FUN_001054ec(uVar5,1);
    *(undefined4 *)(iVar3 + 0x10) = uVar15;
    FUN_00193f64(param_2,uVar5);
    uVar5 = FUN_000ec208(param_1,4);
    iVar3 = FUN_001054ec(puVar20,2);
    *(undefined4 *)(iVar3 + 0xc) = uVar5;
    *(int *)(iVar3 + 8) = iVar4;
    uVar5 = DAT_001aa9cc;
    iVar3 = FUN_001054ec(puVar20,2);
    *(undefined4 *)(iVar3 + 0x10) = uVar5;
  }
  if ((!bVar2) &&
     (piVar17 = *(int **)(*(int *)(param_1 + 8) + 0x30c),
     iVar3 = (**(code **)(*piVar17 + 0x104))(piVar17,puVar20,1,&local_68,0), iVar3 == 0)) {
    iVar4 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar4;
    uVar5 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    uVar18 = puVar20[0x2c];
    uVar15 = puVar20[0x2b];
    iVar3 = FUN_001054ec(uVar5,1);
    *(undefined4 *)(iVar3 + 0xc) = uVar18;
    *(undefined4 *)(iVar3 + 8) = uVar15;
    uVar15 = FUN_000ec208(param_1,4);
    iVar3 = FUN_001054ec(uVar5,0);
    *(undefined4 *)(iVar3 + 0xc) = uVar15;
    *(int *)(iVar3 + 8) = iVar4;
    iVar3 = FUN_001054ec(puVar20,1);
    uVar15 = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = FUN_001054ec(uVar5,1);
    *(undefined4 *)(iVar3 + 0x10) = uVar15;
    FUN_00193f64(param_2,uVar5);
    uVar5 = FUN_000ec208(param_1,4);
    iVar3 = FUN_001054ec(puVar20,1);
    *(undefined4 *)(iVar3 + 0xc) = uVar5;
    *(int *)(iVar3 + 8) = iVar4;
    uVar5 = DAT_001aa9a8;
    iVar3 = FUN_001054ec(puVar20,1);
    *(undefined4 *)(iVar3 + 0x10) = uVar5;
  }
  FUN_00193f64(param_2,puVar20);
  *param_3 = *param_3 & 0xffc0ffff | 0x40000;
  *(short *)((int)param_3 + 2) = (short)iVar19;
LAB_000fa744:
  if ((uVar9 == 0x1f) && ((*(uint *)(param_1 + 0x30) & 0x200000) != 0)) {
    iVar19 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar19;
    iVar4 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar4;
    uVar15 = FUN_001043f0(0xcc,*(undefined4 *)(param_1 + 8));
    iVar3 = FUN_001054ec(uVar15,0);
    *(undefined4 *)(iVar3 + 0xc) = 0;
    *(int *)(iVar3 + 8) = iVar4;
    iVar3 = FUN_001054ec(uVar15,1);
    *(undefined4 *)(iVar3 + 8) = 0;
    *(undefined4 *)(iVar3 + 0xc) = 0x1f;
    uVar5 = UNK_001aa9b0;
    iVar3 = FUN_001054ec(uVar15,1);
    *(undefined4 *)(iVar3 + 0x10) = uVar5;
    if (param_5 == 1) {
      ((int (*)())FUN_000f7870)(uVar15,param_1,2,1,1,1,1);
    }
    else if (param_5 < 2) {
      if (param_5 == 0) {
        ((int (*)())FUN_000f7870)(uVar15,param_1,2,0,0,0,0);
      }
    }
    else if (param_5 == 2) {
      ((int (*)())FUN_000f7870)(uVar15,param_1,2,2,2,2,2);
    }
    else if (param_5 == 3) {
      ((int (*)())FUN_000f7870)(uVar15,param_1,2,3,3,3,3);
    }
    FUN_00193f64(param_2,uVar15);
    uVar5 = FUN_001043f0(0x24,*(undefined4 *)(param_1 + 8));
    uVar15 = FUN_000ec208(param_1,0x1f);
    iVar3 = FUN_001054ec(uVar5,0);
    *(undefined4 *)(iVar3 + 0xc) = uVar15;
    *(int *)(iVar3 + 8) = iVar7;
    iVar3 = FUN_001054ec(uVar5,1);
    *(undefined4 *)(iVar3 + 0xc) = 0;
    *(int *)(iVar3 + 8) = iVar4;
    uVar15 = FUN_000ec208(param_1,4);
    iVar3 = FUN_001054ec(uVar5,2);
    *(undefined4 *)(iVar3 + 0xc) = uVar15;
    *(int *)(iVar3 + 8) = iVar19;
    uVar15 = FUN_000ec208(param_1,0x1f);
    iVar3 = FUN_001054ec(uVar5,3);
    *(undefined4 *)(iVar3 + 0xc) = uVar15;
    *(int *)(iVar3 + 8) = iVar7;
    FUN_00193f64(param_2,uVar5);
    *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    *(short *)((int)param_3 + 2) = (short)iVar19;
  }
  return;
}

/* FUN_000fa958 @ 0xfa958 (1132 bytes) */
int FUN_000fa958(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint *puVar10;
  uint uVar11;
  undefined4 local_48;
  undefined4 local_44;
  
  uVar11 = *(uint *)(PTR_DAT_001e8b88 + param_2 * 4);
  if (param_3 != 0) {
    uVar8 = uVar11 >> 0x1c & 1;
LAB_000fabd8:
    if (uVar8 == 0) {
      puVar5 = *(uint **)(((uVar11 >> 0x17 & 7) * 5 + (uVar11 >> 0x1d)) * 4 +
                         *(int *)(param_4 + 0x6c));
      puVar10 = puVar5;
    }
    else {
      puVar5 = (uint *)0x0;
      puVar10 = *(uint **)(((uVar11 >> 0x17 & 7) * 5 + (uVar11 >> 0x1d)) * 4 +
                          *(int *)(param_4 + 100));
      local_44 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_44) + 0)),(short)*puVar10);
      local_44 = *puVar10 & 0x1800000 | *puVar10 & 0x3f0000 | local_44 & 0xfe40ffff;
      puVar10 = &local_44;
    }
    uVar8 = *puVar10 >> 0x10 & 0x3f;
    iVar3 = *(int *)(param_1 + 8);
    if ((((*puVar10 & 0x3f0000) == 0x100000) && (iVar3 != 0)) &&
       ((*(uint *)(*(int *)(iVar3 + 0x30c) + 8) & 0x80) != 0)) {
      iVar7 = 0xf;
    }
    else {
      iVar7 = (int)(short)*puVar10;
    }
    if ((uVar8 == 0x12) && ((uVar11 & 0x3800000) != 0)) {
      iVar7 = 0;
      uVar8 = 0x13;
    }
    if (((uVar11 >> 0x1b & 1) == 0) && ((uVar8 == 1 || (uVar8 == 0x22)))) {
      iVar1 = *(int *)(iVar3 + 0x3ac) + -1;
      *(int *)(iVar3 + 0x3ac) = iVar1;
      uVar2 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      iVar3 = FUN_001054ec(uVar2,0);
      *(undefined4 *)(iVar3 + 0xc) = 0;
      *(int *)(iVar3 + 8) = iVar1;
      uVar9 = FUN_000ec208(param_1,uVar8);
      iVar3 = FUN_001054ec(uVar2,1);
      *(undefined4 *)(iVar3 + 0xc) = uVar9;
      *(int *)(iVar3 + 8) = iVar7;
      ((int (*)())FUN_000f8aa0)(param_1,param_8,puVar10,param_3,uVar2);
      ((int (*)())FUN_000f92fc)(param_1,uVar2,param_11);
      uVar8 = 4;
      *puVar10 = *puVar10 & 0xfe3fffff;
      *(short *)((int)puVar10 + 2) = (short)iVar1;
      *puVar10 = *puVar10 & 0xffc0ffff | 0x40000;
      iVar7 = iVar1;
    }
    else {
      ((int (*)())FUN_000f8aa0)(param_1,param_8,puVar5,param_3,param_5);
    }
    uVar2 = FUN_000ec208(param_1,uVar8);
    iVar3 = FUN_001054ec(param_5,param_3);
    *(undefined4 *)(iVar3 + 0xc) = uVar2;
    *(int *)(iVar3 + 8) = iVar7;
    return 0;
  }
  uVar8 = 0;
  if ((uVar11 >> 0x1c & 1) == 0) goto LAB_000fabd8;
  puVar10 = *(uint **)(((uVar11 >> 0x17 & 7) * 5 + (uVar11 >> 0x1d)) * 4 + *(int *)(param_4 + 100));
  iVar7 = (int)(short)*puVar10;
  uVar8 = *puVar10 >> 0x10 & 0x3f;
  uVar2 = FUN_000ec208(param_1,uVar8);
  iVar3 = FUN_001054ec(param_5,0);
  *(undefined4 *)(iVar3 + 0xc) = uVar2;
  uVar2 = 0;
  *(int *)(iVar3 + 8) = iVar7;
  iVar3 = param_5;
  ((int (*)())FUN_000f8d50)(param_1,param_9,param_7,puVar10,0,param_5,param_10);
  iVar3 = FUN_00113734(*(undefined4 *)(param_1 + 8),param_5,param_7,puVar10,uVar2,iVar3,param_10);
  if (iVar3 != 0) {
    iVar4 = FUN_001054ec(param_5,0);
    iVar6 = 0;
    iVar3 = 0;
    iVar1 = 0;
    local_48 = *(undefined4 *)(iVar4 + 0x10);
    iVar4 = 4;
    do {
      if (*(char *)((int)&local_48 + iVar1) == '\0') {
        iVar6 = iVar6 + 1;
        iVar3 = iVar1;
      }
      iVar1 = iVar1 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (1 < iVar6) {
      local_44 = DAT_001aa9e0;
      *(undefined1 *)((int)&local_44 + iVar3) = 0;
      uVar9 = *(undefined4 *)(iVar3 * 4 + 0x1dc7bc);
      iVar3 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      uVar2 = FUN_000ec208(param_1,uVar8);
      iVar1 = FUN_001054ec(iVar3,0);
      *(undefined4 *)(iVar1 + 0xc) = uVar2;
      *(int *)(iVar1 + 8) = iVar7;
      *(undefined4 *)(iVar3 + 0x9c) = local_48;
      uVar2 = FUN_000ec208(param_1,uVar8);
      iVar1 = FUN_001054ec(iVar3,1);
      *(undefined4 *)(iVar1 + 0xc) = uVar2;
      *(int *)(iVar1 + 8) = iVar7;
      iVar1 = FUN_001054ec(iVar3,1);
      *(undefined4 *)(iVar1 + 0x10) = uVar9;
      *(uint *)(param_5 + 0x9c) = local_44;
      goto LAB_000fab1c;
    }
  }
  iVar3 = 0;
LAB_000fab1c:
  if ((uVar11 >> 0x1a & 1) != 0) {
    return iVar3;
  }
  iVar4 = FUN_001054ec(param_5,0);
  iVar1 = DAT_001aa9dc;
  if (*(int *)(iVar4 + 0x10) == DAT_001aa9dc) {
    return iVar3;
  }
  iVar3 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
  iVar6 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar6;
  uVar2 = FUN_000ec208(param_1,uVar8);
  iVar4 = FUN_001054ec(iVar3,0);
  *(undefined4 *)(iVar4 + 0xc) = uVar2;
  *(int *)(iVar4 + 8) = iVar7;
  iVar7 = FUN_001054ec(iVar3,1);
  *(undefined4 *)(iVar7 + 0xc) = 0;
  *(int *)(iVar7 + 8) = iVar6;
  iVar7 = FUN_001054ec(param_5,0);
  *(undefined4 *)(iVar7 + 0xc) = 0;
  *(int *)(iVar7 + 8) = iVar6;
  iVar7 = FUN_001054ec(param_5,0);
  *(undefined4 *)(iVar3 + 0x9c) = *(undefined4 *)(iVar7 + 0x10);
  *(int *)(param_5 + 0x9c) = iVar1;
  return iVar3;
}

/* FUN_000fadc4 @ 0xfadc4 (240 bytes) */
int FUN_000fadc4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  uint *param_5;
  int param_6;
  undefined4 param_7;
{
  undefined1 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  undefined4 local_48 [8];
  
  uVar7 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  puVar3 = (undefined4 *)FUN_00193e18(uVar7,0x15c);
  *puVar3 = uVar7;
  puVar6 = puVar3 + 1;
  FUN_000ea6d0(puVar6,param_2,param_4,0,*(undefined4 *)(param_1 + 8));
  FUN_000e78c0(puVar6,param_3);
  local_48[0] = DAT_001aa9a8;
  ((int (*)())FUN_000fa958)(param_1,5,1,param_7,param_2,1,DAT_001aa9dc,local_48,param_6,1,puVar6);
  iVar4 = FUN_001054ec(param_2,1);
  iVar2 = 0;
  iVar9 = 4;
  (*(unsigned char *)((unsigned char *)&(local_48[0]) + 0)) = (undefined1)((uint)*(undefined4 *)(iVar4 + 0x10) >> 0x18);
  uVar1 = (*(unsigned char *)((unsigned char *)&(local_48[0]) + 0));
  local_48[0] = *(undefined4 *)(iVar4 + 0x10);
  do {
    *(undefined1 *)((int)local_48 + iVar2) = uVar1;
    uVar7 = local_48[0];
    iVar2 = iVar2 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  iVar2 = FUN_001054ec(param_2,1);
  *(undefined4 *)(iVar2 + 0x10) = uVar7;
  FUN_000ed63c(param_1,param_2);
  uVar8 = 0;
  if (param_5[1] != 0) {
    puVar3[0x53] = 0;
    uVar8 = param_5[1];
  }
  if (uVar8 < *param_5) {
    _memset((void *)(uVar8 * 4 + param_5[2]),0,4);
    piVar5 = (int *)(uVar8 * 4 + param_5[2]);
    param_5[1] = uVar8 + 1;
  }
  else {
    piVar5 = (int *)FUN_0019423c(param_5,uVar8);
  }
  *piVar5 = (int)puVar6;
  uVar8 = *(uint *)(param_6 + 4);
  if (uVar8 != 0) {
    piVar5 = (int *)0x0;
    if (uVar8 - 1 < uVar8) {
      piVar5 = (int *)((uVar8 - 1) * 4 + *(int *)(param_6 + 8));
    }
    *(int *)(*piVar5 + 300) = *(int *)(*piVar5 + 300) + 1;
  }
  return puVar6;
}

/* FUN_000fafa4 @ 0xfafa4 (652 bytes) */
int FUN_000fafa4(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  undefined4 *param_5;
{
  uint uVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint *puVar7;
  undefined4 uVar8;
  uint uVar9;
  
  uVar8 = *(undefined4 *)(param_1 + 0x3ac);
  uVar3 = FUN_000ec208(param_1,param_2);
  iVar4 = FUN_00127608(uVar8,uVar3,param_3,0);
  piVar5 = *(int **)(iVar4 + 0x18);
  if (*piVar5 == 0) {
    piVar5 = (int *)FUN_0019423c(piVar5,0);
  }
  else {
    if (piVar5[1] == 0) {
      *(undefined4 *)piVar5[2] = 0;
      piVar5[1] = 1;
    }
    piVar5 = (int *)piVar5[2];
  }
  iVar4 = *(int *)(param_1 + 0x3ac);
  iVar6 = *piVar5;
  puVar7 = *(uint **)(iVar4 + 0x20);
  uVar9 = puVar7[1];
  if (uVar9 < *puVar7) {
    _memset((void *)(uVar9 * 4 + puVar7[2]),0,4);
    piVar5 = (int *)(uVar9 * 4 + puVar7[2]);
    puVar7[1] = uVar9 + 1;
  }
  else {
    piVar5 = (int *)FUN_0019423c(puVar7,uVar9);
  }
  *piVar5 = iVar6;
  *(int *)(iVar4 + 0x1c) = *(int *)(iVar4 + 0x1c) + 1;
  if (param_2 == 1) {
    if (0 < param_4) {
      uVar9 = 0;
      iVar4 = iVar6;
      do {
        uVar3 = param_5[uVar9];
        *(undefined4 *)(iVar4 + 0x1c) = 2;
        *(undefined4 *)(iVar4 + 0x20) = uVar3;
        uVar1 = uVar9 & 0x3f;
        uVar9 = uVar9 + 1;
        iVar4 = iVar4 + 0x18;
        *(byte *)(iVar6 + 0x15c) = (byte)(1 << uVar1) | *(byte *)(iVar6 + 0x15c);
        param_4 = param_4 + -1;
      } while (param_4 != 0);
    }
  }
  else if (param_2 < 2) {
    if (param_2 == 0) {
      if (param_4 < 1) {
        bVar2 = *(byte *)(iVar6 + 0x15c);
      }
      else {
        uVar9 = 0;
        iVar4 = iVar6;
        do {
          uVar3 = *param_5;
          *(undefined4 *)(iVar4 + 0x1c) = 4;
          *(undefined4 *)(iVar4 + 0x20) = uVar3;
          uVar1 = uVar9 & 0x3f;
          uVar9 = uVar9 + 1;
          iVar4 = iVar4 + 0x18;
          bVar2 = (byte)(1 << uVar1) | *(byte *)(iVar6 + 0x15c);
          *(byte *)(iVar6 + 0x15c) = bVar2;
          param_4 = param_4 + -1;
        } while (param_4 != 0);
      }
      uVar3 = *(undefined4 *)(iVar6 + 0x20);
      *(undefined4 *)(iVar6 + 100) = 4;
      *(byte *)(iVar6 + 0x15c) = bVar2 | 0xe;
      *(undefined4 *)(iVar6 + 0x68) = uVar3;
      *(undefined4 *)(iVar6 + 0x38) = uVar3;
      *(undefined4 *)(iVar6 + 0x50) = uVar3;
      *(undefined4 *)(iVar6 + 0x34) = 4;
      *(undefined4 *)(iVar6 + 0x4c) = 4;
    }
  }
  else if (param_2 == 2) {
    if (0 < param_4) {
      uVar9 = 0;
      iVar4 = iVar6;
      do {
        uVar3 = param_5[uVar9];
        *(undefined4 *)(iVar4 + 0x1c) = 3;
        *(undefined4 *)(iVar4 + 0x20) = uVar3;
        uVar1 = uVar9 & 0x3f;
        uVar9 = uVar9 + 1;
        iVar4 = iVar4 + 0x18;
        *(byte *)(iVar6 + 0x15c) = (byte)(1 << uVar1) | *(byte *)(iVar6 + 0x15c);
        param_4 = param_4 + -1;
      } while (param_4 != 0);
    }
  }
  else if ((param_2 == 0x1d) && (0 < param_4)) {
    uVar9 = 0;
    iVar4 = iVar6;
    do {
      uVar3 = param_5[uVar9];
      *(undefined4 *)(iVar4 + 0x1c) = 3;
      *(undefined4 *)(iVar4 + 0x20) = uVar3;
      uVar1 = uVar9 & 0x3f;
      uVar9 = uVar9 + 1;
      iVar4 = iVar4 + 0x18;
      *(byte *)(iVar6 + 0x15c) = (byte)(1 << uVar1) | *(byte *)(iVar6 + 0x15c);
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return;
}

/* FUN_000fb230 @ 0xfb230 (420 bytes) */
int FUN_000fb230(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  
  uVar2 = *(uint *)(param_1 + 0x30) & 1 | *(uint *)(param_1 + 0x30) >> 0xe & 1;
  iVar1 = FUN_000d9fc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2);
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      FUN_000da070(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2,iVar4,1,&local_48);
      FUN_000e4724(param_2,iVar4,(uint)(local_48 != 0));
      iVar3 = iVar4 + 1;
      ((int (*)())FUN_000fafa4)(param_1,0,iVar4,1,&local_48);
      iVar4 = iVar3;
    } while (iVar1 != iVar3);
  }
  iVar1 = FUN_000d9fa0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2);
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      FUN_000da028(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2,iVar4,4,&local_48);
      FUN_000e4450(param_2,iVar4,local_48,local_44,local_40,local_3c);
      iVar3 = iVar4 + 1;
      ((int (*)())FUN_000fafa4)(param_1,2,iVar4,4,&local_48);
      iVar4 = iVar3;
    } while (iVar1 != iVar3);
  }
  iVar1 = FUN_000d9f80(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2);
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      FUN_000d9fe0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2,iVar4,4,&local_38);
      ((void (*)())FUN_000e4780)(param_2,iVar4,(double)local_38,(double)local_34,(double)local_30,(double)local_2c
                  );
      iVar3 = iVar4 + 1;
      ((int (*)())FUN_000fafa4)(param_1,1,iVar4,4,&local_38);
      iVar4 = iVar3;
    } while (iVar1 != iVar3);
  }
  return;
}

/* FUN_000fb3d4 @ 0xfb3d4 (2560 bytes) */
int FUN_000fb3d4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  dword *param_3;
  dword *param_4;
  dword *param_5;
  dword *param_6;
  int param_7;
{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  dword dVar4;
  undefined *puVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  undefined4 extraout_r4_08;
  undefined4 extraout_r4_09;
  undefined4 extraout_r4_10;
  undefined4 extraout_r4_11;
  undefined4 extraout_r4_12;
  undefined4 extraout_r4_13;
  undefined4 extraout_r4_14;
  undefined4 extraout_r4_15;
  undefined4 extraout_r4_16;
  dword *pdVar16;
  dword *pdVar17;
  uint uVar18;
  int iVar19;
  undefined1 *puVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  dword *pdVar24;
  dword *pdVar25;
  dword *pdVar26;
  dword *pdVar27;
  dword *pdVar28;
  dword *pdVar29;
  dword *pdVar30;
  dword *pdVar31;
  undefined4 *puVar32;
  uint uVar33;
  undefined4 uVar34;
  code *pcVar35;
  undefined4 uVar36;
  uint *puVar37;
  double dVar38;
  double fparam_2;
  double fparam_3;
  double fparam_4;
  undefined8 uVar39;
  uint local_98;
  uint local_94 [3];
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  
  uVar21 = *param_4;
  uVar22 = uVar21 >> 0x16 & 1;
  iVar19 = *(int *)(param_1 + 8);
  if ((((uVar21 & 0x3f0000) == 0x100000) && (iVar19 != 0)) &&
     ((*(uint *)(*(int *)(iVar19 + 0x30c) + 8) & 0x80) != 0)) {
    pdVar24 = (dword *)((int)&MACH_HEADER.filetype + 3);
  }
  else {
    pdVar24 = (dword *)(int)(short)*param_4;
  }
  uVar23 = uVar21 >> 0x10 & 0x3f;
  uVar8 = param_2;
  pdVar16 = param_3;
  pdVar17 = param_4;
  pdVar31 = param_6;
  pdVar30 = pdVar24;
  if ((uVar21 & 0x1800000) == 0x800000) {
    iVar6 = 8;
    if (uVar22 == 0) {
      iVar6 = 4;
    }
    uVar21 = *(uint *)(iVar6 + (int)param_4);
    uVar1 = *(ushort *)((int)param_4 + iVar6 + 2);
    if ((uVar21 & 0x10000) == 0) {
      pdVar30 = (dword *)(*(int *)(iVar19 + 0x3b4) + 1);
      *(dword **)(iVar19 + 0x3b4) = pdVar30;
      iVar19 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x26,pdVar30,0);
      *(dword **)(iVar19 + 0x30) = pdVar24;
      uVar8 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar9 = (undefined4 *)FUN_00193e18(uVar8,0x168);
      *puVar9 = uVar8;
      puVar32 = puVar9 + 1;
      FUN_00109e28(puVar32,0x84,*(undefined4 *)(param_1 + 8));
      FUN_001046c8(puVar32,0,iVar19);
      pdVar17 = (dword *)0x0;
      uVar23 = 0x22;
      pdVar24 = (dword *)FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x25,(uint)uVar1,0);
      pdVar16 = pdVar24;
      FUN_001046c8(puVar32,1,pdVar24);
      uVar8 = *(undefined4 *)(PTR_DAT_001e8b8c + (uVar21 >> 0x11 & 7) * 4);
      iVar19 = FUN_001054ec(puVar32,1);
      *(undefined4 *)(iVar19 + 0x10) = uVar8;
      puVar9[0x4c] = pdVar24[0xc];
      FUN_00193f64(param_2,puVar32);
      uVar8 = extraout_r4_01;
    }
    else {
      piVar7 = (int *)0x0;
      uVar21 = param_5[1] - 1;
      if (uVar21 < param_5[1]) {
        piVar7 = (int *)(uVar21 * 4 + param_5[2]);
      }
      iVar19 = *piVar7;
      *(undefined4 *)(iVar19 + 0x140) = 1;
      uVar8 = FUN_000e7d5c(iVar19);
      uVar8 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x27,uVar8,0);
      if (uVar23 == 1) {
        pdVar17 = (dword *)0x0;
        pdVar30 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3b8) + 1);
        *(dword **)(*(int *)(param_1 + 8) + 0x3b8) = pdVar30;
        iVar6 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x28,pdVar30,0);
        *(dword **)(iVar6 + 0x30) = pdVar24;
        uVar34 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar9 = (undefined4 *)FUN_00193e18(uVar34,0x168);
        *puVar9 = uVar34;
        pdVar16 = puVar9 + 1;
        FUN_0010502c(pdVar16,0x82,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(pdVar16,0,iVar6);
        FUN_001046c8(pdVar16,1,uVar8);
        uVar23 = 0x23;
        FUN_000e7688(iVar19,pdVar16);
        FUN_0012306c(iVar6,pdVar16);
        FUN_001236e4(uVar8,1,pdVar16);
        uVar8 = extraout_r4;
      }
      else {
        if ((*(uint *)(param_1 + 0x30) & 1) == 0) {
          if ((*(uint *)(param_1 + 0x30) & 0x2000) != 0) {
            if (*(int *)(param_1 + 0x3e4) == 0) {
              *(undefined4 *)(param_1 + 0x3e4) = 1;
              uVar34 = FUN_000ec208(param_1,uVar23);
              *(undefined4 *)(param_1 + 0x3f4) = uVar34;
            }
            else {
              FUN_000ec208(param_1,uVar23);
            }
          }
        }
        else {
          *(undefined4 *)(param_1 + 0x3d4) = 1;
        }
        pdVar30 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3bc) + 1);
        *(dword **)(*(int *)(param_1 + 8) + 0x3bc) = pdVar30;
        uVar36 = *(undefined4 *)(param_1 + 0x3ac);
        uVar34 = FUN_000ec208(param_1,0x24);
        pdVar17 = (dword *)0x0;
        iVar6 = FUN_00127608(uVar36,uVar34,pdVar30,0);
        *(dword **)(iVar6 + 0x30) = pdVar24;
        uVar34 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar9 = (undefined4 *)FUN_00193e18(uVar34,0x168);
        *puVar9 = uVar34;
        pdVar16 = puVar9 + 1;
        FUN_0010502c(pdVar16,0x82,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(pdVar16,0,iVar6);
        FUN_001046c8(pdVar16,1,uVar8);
        uVar23 = 0x24;
        FUN_000e7688(iVar19,pdVar16);
        FUN_0012306c(iVar6,pdVar16);
        FUN_001236e4(uVar8,1,pdVar16);
        uVar8 = extraout_r4_00;
      }
    }
    uVar21 = *param_4 & 0xfe7fffff;
    *param_4 = uVar21;
  }
  if (((uVar21 & 0x3f0000) == 0x1c0000) &&
     ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 8) == 0)) {
    *param_4 = uVar21 & 0xffc0ffff | 0x10000;
    pdVar24 = param_4;
    if ((uVar21 & 0x400000) != 0) {
      pdVar24 = param_4 + 1;
    }
    bVar3 = false;
    *(short *)((int)param_4 + 2) = (short)pdVar24[1];
    uVar21 = *param_4 & 0xfbffffff;
    *param_4 = uVar21;
  }
  else {
    bVar3 = true;
  }
  if ((uVar23 == 0x20) && (bVar2 = true, (uVar21 & 0x1800000) == 0x1000000)) {
LAB_000fb800:
    pdVar24 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1);
    *(dword **)(*(int *)(param_1 + 8) + 0x3ac) = pdVar24;
    uVar21 = *param_4;
    uVar33 = uVar21 >> 0x10 & 0x3f;
    if (!bVar2) {
      uVar8 = 0xfe;
      if (uVar33 != 0x1c) {
        uVar8 = 0xfb;
      }
    }
    else {
      uVar8 = 0x10b;
    }
    iVar19 = 1;
    pdVar17 = pdVar30;
    if ((int)uVar21 < 0) {
      iVar19 = 2;
      pdVar17 = (dword *)((uint)pdVar30 | param_4[1] << 0x10);
    }
    if ((uVar21 & 0x400000) != 0) {
      iVar19 = iVar19 + 1;
    }
    if ((uVar21 & 0x1800000) == 0x1000000) {
      pdVar28 = param_4 + iVar19;
      if (!bVar2) {
        uVar34 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar9 = (undefined4 *)FUN_00193e18(uVar34,0x168);
        *puVar9 = uVar34;
        puVar9 = puVar9 + 1;
        FUN_00107980(puVar9,uVar8,*(undefined4 *)(param_1 + 8));
        uVar8 = FUN_000ec208(param_1,uVar33);
        pdVar16 = (dword *)((int)&MACH_HEADER.magic + 2);
        iVar6 = FUN_001054ec(puVar9,1);
        *(undefined4 *)(iVar6 + 0xc) = uVar8;
        *(dword **)(iVar6 + 8) = pdVar17;
      }
      else {
        pdVar16 = (dword *)((int)&MACH_HEADER.magic + 1);
        puVar9 = (undefined4 *)FUN_001043f0(uVar8,*(undefined4 *)(param_1 + 8));
        uVar21 = DAT_001aa9a8;
        puVar9[0x27] = DAT_001aa9dc;
        puVar9[0x50] = uVar21;
        puVar9[0x21] = 2;
        uVar8 = FUN_000ec208(param_1,uVar33);
        iVar6 = FUN_001054ec(puVar9,2);
        *(undefined4 *)(iVar6 + 0xc) = uVar8;
        *(undefined4 *)(iVar6 + 8) = 0xffffffff;
      }
      uVar8 = FUN_000ec208(param_1,4);
      iVar6 = FUN_001054ec(puVar9,0);
      *(undefined4 *)(iVar6 + 0xc) = uVar8;
      *(dword **)(iVar6 + 8) = pdVar24;
      if ((*param_4 & 0x4000000) == 0) {
        dVar4 = *pdVar28;
        uVar8 = FUN_000ec208(param_1,*pdVar28 >> 0x10 & 0x3f);
        iVar19 = FUN_001054ec(puVar9,pdVar16);
        *(undefined4 *)(iVar19 + 0xc) = uVar8;
        *(uint *)(iVar19 + 8) = (uint)(ushort)dVar4;
      }
      else {
        pdVar31 = (dword *)param_4[iVar19 + 2];
        uVar8 = FUN_001043f0(0xc6,*(undefined4 *)(param_1 + 8));
        uVar34 = FUN_000ec208(param_1,4);
        iVar19 = FUN_001054ec(uVar8,0);
        *(undefined4 *)(iVar19 + 0xc) = uVar34;
        *(dword **)(iVar19 + 8) = pdVar24;
        dVar4 = *pdVar28;
        uVar34 = FUN_000ec208(param_1,*pdVar28 >> 0x10 & 0x3f);
        iVar19 = FUN_001054ec(uVar8,1);
        *(undefined4 *)(iVar19 + 0xc) = uVar34;
        *(uint *)(iVar19 + 8) = (uint)(ushort)dVar4;
        ((int (*)())FUN_000f7870)(uVar8,param_1,2,pdVar31,pdVar31,pdVar31,pdVar31);
        FUN_00193f64(param_2,uVar8);
        uVar8 = FUN_000ec208(param_1,4);
        iVar19 = FUN_001054ec(puVar9,pdVar16);
        *(undefined4 *)(iVar19 + 0xc) = uVar8;
        *(dword **)(iVar19 + 8) = pdVar24;
      }
      local_98 = DAT_001aa9a8;
      ((int (*)())FUN_000f8aa0)(param_1,&local_98,pdVar28,pdVar16,puVar9);
    }
    else if ((uVar21 & 0x1800000) == 0) {
      pdVar31 = (dword *)param_4[iVar19];
      uVar34 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar9 = (undefined4 *)FUN_00193e18(uVar34,0x168);
      *puVar9 = uVar34;
      puVar9 = puVar9 + 1;
      FUN_00107980(puVar9,uVar8,*(undefined4 *)(param_1 + 8));
      uVar8 = FUN_000ec208(param_1,4);
      iVar19 = FUN_001054ec(puVar9,0);
      *(undefined4 *)(iVar19 + 0xc) = uVar8;
      *(dword **)(iVar19 + 8) = pdVar24;
      uVar8 = FUN_000ec208(param_1,uVar33);
      iVar19 = FUN_001054ec(puVar9,1);
      *(undefined4 *)(iVar19 + 0xc) = uVar8;
      *(dword **)(iVar19 + 8) = pdVar17;
      ((int (*)())FUN_000f7870)(puVar9,param_1,2,pdVar31,pdVar31,pdVar31,pdVar31);
      pdVar16 = (dword *)((int)&MACH_HEADER.magic + 1);
    }
    else {
      puVar9 = (undefined4 *)0x0;
      pdVar16 = (dword *)((int)&MACH_HEADER.magic + 1);
    }
    iVar19 = FUN_001054ec(puVar9,pdVar16);
    local_94[0] = *(uint *)(iVar19 + 0x10);
    pdVar17 = local_94;
    param_5 = (dword *)0x0;
    piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
    iVar19 = (**(code **)(*piVar7 + 0x104))(piVar7,puVar9);
    if (iVar19 == 0) {
      iVar6 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar6;
      uVar8 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      uVar36 = puVar9[0x32];
      uVar34 = puVar9[0x31];
      iVar19 = FUN_001054ec(uVar8,1);
      *(undefined4 *)(iVar19 + 0xc) = uVar36;
      *(undefined4 *)(iVar19 + 8) = uVar34;
      uVar34 = FUN_000ec208(param_1,4);
      iVar19 = FUN_001054ec(uVar8,0);
      *(undefined4 *)(iVar19 + 0xc) = uVar34;
      *(int *)(iVar19 + 8) = iVar6;
      iVar19 = FUN_001054ec(puVar9,2);
      uVar34 = *(undefined4 *)(iVar19 + 0x10);
      iVar19 = FUN_001054ec(uVar8,1);
      *(undefined4 *)(iVar19 + 0x10) = uVar34;
      FUN_00193f64(param_2,uVar8);
      uVar8 = FUN_000ec208(param_1,4);
      iVar19 = FUN_001054ec(puVar9,2);
      *(undefined4 *)(iVar19 + 0xc) = uVar8;
      *(int *)(iVar19 + 8) = iVar6;
      uVar8 = DAT_001aa9cc;
      iVar19 = FUN_001054ec(puVar9,2);
      *(undefined4 *)(iVar19 + 0x10) = uVar8;
    }
    FUN_00193f64(param_2,puVar9);
    bVar3 = false;
    *param_4 = *param_4 & 0xffc0ffff | 0x40000;
    *(short *)((int)param_4 + 2) = (short)pdVar24;
    uVar8 = extraout_r4_02;
  }
  else {
    if (((undefined4 *)(uVar21 & 0x3f0000) == (undefined4 *)0x1c0000) ||
       ((undefined4 *)(uVar21 & 0x3f0000) == &DAT_001b0000)) {
      bVar2 = false;
      goto LAB_000fb800;
    }
    pdVar24 = (dword *)0x0;
    if ((uVar21 & 0x2000000) != 0) {
      pdVar24 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1);
      *(dword **)(*(int *)(param_1 + 8) + 0x3ac) = pdVar24;
      uVar21 = *param_4;
      if ((uVar21 & 0x400000) == 0) {
        pdVar31 = (dword *)((int)&MACH_HEADER.magic + 1);
        pdVar28 = (dword *)((int)&MACH_HEADER.magic + 1);
        param_5 = (dword *)((int)&MACH_HEADER.magic + 2);
      }
      else {
        pdVar31 = (dword *)((int)&MACH_HEADER.magic + 2);
        pdVar28 = (dword *)((int)&MACH_HEADER.magic + 2);
        param_5 = (dword *)((int)&MACH_HEADER.magic + 3);
      }
      if ((uVar21 & 0x1800000) == 0x1000000) {
        pdVar16 = param_4 + (int)pdVar28;
        pdVar17 = param_4 + (int)param_5;
        pdVar28 = (dword *)((int)pdVar31 + 2);
        if ((uVar21 & 0x4000000) == 0) {
          param_5 = (dword *)((int)pdVar31 + 3);
          pdVar25 = pdVar28;
        }
        else {
          pdVar28 = (dword *)((int)pdVar31 + 3);
          param_5 = pdVar31 + 1;
          pdVar25 = pdVar28;
        }
      }
      else {
        pdVar16 = (dword *)0x0;
        pdVar17 = (dword *)0x0;
        pdVar25 = pdVar31;
      }
      if ((param_4[(int)pdVar28] & 0x1800000) == 0x1000000) {
        pdVar29 = param_4 + (int)param_5;
        pdVar27 = (dword *)0x0;
        pdVar26 = param_4 + (int)((int)pdVar25 + 2);
        if ((param_4[(int)pdVar28] & 0x4000000) != 0) {
          pdVar27 = param_4 + (int)((int)pdVar25 + 3);
        }
      }
      else {
        pdVar29 = (dword *)0x0;
        pdVar26 = (dword *)0x0;
        pdVar27 = (dword *)0x0;
      }
      if (pdVar16 == (dword *)0x0) {
        if (pdVar29 != (dword *)0x0) {
          if ((pdVar17 != (dword *)0x0) || (pdVar26 == (dword *)0x0)) goto LAB_000fc43c;
          pdVar16 = (dword *)FUN_001043f0(0xe6,*(undefined4 *)(param_1 + 8));
          dVar4 = *param_4;
          piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
          uVar8 = (**(code **)(*piVar7 + 0x9c))(piVar7,(short)dVar4);
          piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
          (**(code **)(*piVar7 + 0xa0))(&local_84,piVar7,(short)dVar4);
          uVar34 = FUN_000ec208(param_1,4);
          iVar19 = FUN_001054ec(pdVar16,0);
          pdVar31 = &MACH_HEADER.cputype;
          *(undefined4 *)(iVar19 + 0xc) = uVar34;
          *(dword **)(iVar19 + 8) = pdVar24;
          ((int (*)())FUN_000f7870)(pdVar16,param_1,1,4,4,4,4);
          dVar4 = *pdVar29;
          uVar34 = FUN_000ec208(param_1,*pdVar29 >> 0x10 & 0x3f);
          iVar19 = FUN_001054ec(pdVar16,2);
          local_98 = DAT_001aa9a8;
          *(undefined4 *)(iVar19 + 0xc) = uVar34;
          *(uint *)(iVar19 + 8) = (uint)(ushort)dVar4;
          pdVar17 = (dword *)((int)&MACH_HEADER.magic + 2);
          param_5 = pdVar16;
          ((int (*)())FUN_000f8aa0)(param_1,&local_98,pdVar29,2,pdVar16);
          FUN_00193f64(param_2,pdVar16);
          if ((pdVar27 != (dword *)0x0) && (*pdVar27 != 0)) {
            uVar34 = FUN_001043f0(0xc6,*(undefined4 *)(param_1 + 8));
            uVar36 = FUN_000ec208(param_1,4);
            iVar19 = FUN_001054ec(uVar34,0);
            *(undefined4 *)(iVar19 + 0xc) = uVar36;
            *(dword **)(iVar19 + 8) = pdVar24;
            uVar36 = FUN_000ec208(param_1,4);
            iVar19 = FUN_001054ec(uVar34,1);
            *(undefined4 *)(iVar19 + 0xc) = uVar36;
            pdVar29 = (dword *)((int)&MACH_HEADER.magic + 2);
            *(dword **)(iVar19 + 8) = pdVar24;
            pdVar17 = (dword *)(*pdVar27 << 2);
            param_5 = pdVar17;
            pdVar31 = pdVar17;
            ((int (*)())FUN_000f7870)(uVar34,param_1,2,pdVar17,pdVar17,pdVar17,pdVar17);
            iVar19 = FUN_001054ec(uVar34,2);
            *(undefined4 *)(iVar19 + 0x10) = local_84;
            FUN_00193f64(param_2,uVar34);
          }
          uVar34 = FUN_001043f0(0xc6,*(undefined4 *)(param_1 + 8));
          uVar36 = FUN_000ec208(param_1,4);
          iVar19 = FUN_001054ec(uVar34,0);
          *(undefined4 *)(iVar19 + 0xc) = uVar36;
          *(dword **)(iVar19 + 8) = pdVar24;
          uVar36 = FUN_000ec208(param_1,4);
          iVar19 = FUN_001054ec(uVar34,1);
          *(undefined4 *)(iVar19 + 0xc) = uVar36;
          *(dword **)(iVar19 + 8) = pdVar24;
          iVar19 = FUN_001054ec(uVar34,2);
          *(undefined4 *)(iVar19 + 0xc) = 0x1f;
          *(undefined4 *)(iVar19 + 8) = uVar8;
          iVar19 = FUN_001054ec(uVar34,2);
          *(undefined4 *)(iVar19 + 0x10) = local_84;
          FUN_00193f64(param_2,uVar34);
          iVar19 = FUN_001043f0(0x68,*(undefined4 *)(param_1 + 8));
          uVar8 = FUN_000ec208(param_1,4);
          iVar6 = FUN_001054ec(iVar19,0);
          uVar21 = DAT_001aa9a8;
          *(undefined4 *)(iVar6 + 0xc) = uVar8;
          *(dword **)(iVar6 + 8) = pdVar24;
          *(undefined4 *)(iVar19 + 0x130) = 0;
          pdVar16 = pdVar29;
LAB_000fc3f4:
          *(uint *)(iVar19 + 0x140) = uVar21;
          uVar34 = FUN_000ec208(param_1,4);
          iVar6 = FUN_001054ec(iVar19,1);
          uVar8 = DAT_001aa9cc;
          *(undefined4 *)(iVar6 + 0xc) = uVar34;
          *(dword **)(iVar6 + 8) = pdVar24;
          iVar13 = FUN_001054ec(iVar19,1);
          iVar6 = 0;
          *(undefined4 *)(iVar13 + 0x10) = uVar8;
          goto LAB_000fc74c;
        }
        uVar21 = (uint)*(ushort *)((int)param_4 + (int)pdVar28 * 4 + 2);
        pdVar28 = (dword *)(uint)(ushort)*param_4;
        if ((*(uint *)(param_1 + 0x30) & 0x40000) == 0) {
          iVar6 = 0;
          iVar19 = FUN_001043f0(0x68,*(undefined4 *)(param_1 + 8));
          uVar8 = FUN_000ec208(param_1,4);
          iVar13 = FUN_001054ec(iVar19,0);
          uVar33 = DAT_001aa9a8;
          *(undefined4 *)(iVar13 + 0xc) = uVar8;
          *(dword **)(iVar13 + 8) = pdVar24;
          *(uint *)(iVar19 + 0x140) = uVar33;
          *(uint *)(iVar19 + 0x130) = uVar21;
          piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
          uVar8 = (**(code **)(*piVar7 + 0x9c))(piVar7,pdVar28);
          pdVar17 = *(dword **)(param_1 + 8);
          (**(code **)(*(*(int * *)(pdVar17 + (0xc3))) + 0xa0))(&local_88);
          iVar13 = FUN_001054ec(iVar19,1);
          *(undefined4 *)(iVar13 + 8) = uVar8;
          *(undefined4 *)(iVar13 + 0xc) = 0x1f;
          iVar13 = FUN_001054ec(iVar19,1);
          *(undefined4 *)(iVar13 + 0x10) = local_88;
          pdVar16 = pdVar28;
          if (uVar21 == *param_6) {
            pdVar16 = *(dword **)(param_1 + 8);
            uVar8 = (**(code **)(*(*(int * *)(pdVar16 + (0xc3))) + 0xa8))((*(int * *)(pdVar16 + (0xc3))),&local_98);
            iVar6 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
            uVar34 = FUN_000ec208(param_1,4);
            iVar13 = FUN_001054ec(iVar6,0);
            *(undefined4 *)(iVar13 + 0xc) = uVar34;
            *(dword **)(iVar13 + 8) = pdVar24;
            *(dword *)(iVar6 + 0x9c) = param_6[1];
            iVar13 = FUN_001054ec(iVar6,1);
            uVar21 = local_98;
            *(undefined4 *)(iVar13 + 0xc) = 0x1f;
            *(undefined4 *)(iVar13 + 8) = uVar8;
            iVar13 = FUN_001054ec(iVar6,1);
            *(uint *)(iVar13 + 0x10) = uVar21;
          }
          goto LAB_000fc74c;
        }
        iVar19 = (int)pdVar28 * 4;
        puVar37 = *(uint **)(iVar19 + param_7);
        if (puVar37 == (uint *)0x0) {
          uVar8 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
          puVar9 = (undefined4 *)FUN_00193e18(uVar8,0x14);
          puVar37 = puVar9 + 1;
          *puVar9 = uVar8;
          puVar9[1] = 2;
          puVar9[2] = 0;
          puVar9[4] = uVar8;
          uVar39 = FUN_00193e18(uVar8,8);
          uVar8 = (undefined4)uVar39;
          puVar9[3] = (int)((ulonglong)uVar39 >> 0x20);
          *(uint **)(iVar19 + param_7) = puVar37;
        }
        if (uVar21 < *puVar37) {
          uVar33 = puVar37[1];
          if (uVar33 <= uVar21) {
            pdVar16 = (dword *)((uVar21 - uVar33) * 4 + 4);
            _memset((void *)(uVar33 * 4 + puVar37[2]),0,(size_t)pdVar16);
            puVar37[1] = uVar21 + 1;
            uVar8 = extraout_r4_03;
          }
          uVar39 = CONCAT44(uVar21 * 4 + puVar37[2],uVar8);
        }
        else {
          uVar39 = FUN_0019423c(puVar37,uVar21);
        }
        uVar8 = (undefined4)uVar39;
        if (*(int *)((ulonglong)uVar39 >> 0x20) == 0) {
          iVar6 = FUN_00109810(0xa4,*(undefined4 *)(param_1 + 8));
          *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) & 0xffff7fff;
          iVar14 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar14;
          iVar13 = FUN_001054ec(iVar6,0);
          *(int *)(iVar13 + 8) = iVar14;
          *(undefined4 *)(iVar13 + 0xc) = 0;
          *(dword **)(iVar6 + 0x130) = pdVar28;
          *(uint *)(iVar6 + 300) = uVar21;
          pdVar16 = *(dword **)(param_1 + 0x3a0);
          ((int (*)())FUN_000f92fc)(param_1,iVar6,pdVar16);
          puVar37 = *(uint **)(iVar19 + param_7);
          if (uVar21 < *puVar37) {
            uVar33 = puVar37[1];
            uVar8 = extraout_r4_04;
            if (uVar33 <= uVar21) {
              pdVar16 = (dword *)((uVar21 - uVar33) * 4 + 4);
              _memset((void *)(uVar33 * 4 + puVar37[2]),0,(size_t)pdVar16);
              puVar37[1] = uVar21 + 1;
              uVar8 = extraout_r4_05;
            }
            uVar39 = CONCAT44(uVar21 * 4 + puVar37[2],uVar8);
          }
          else {
            uVar39 = FUN_0019423c(puVar37,uVar21);
          }
          uVar8 = (undefined4)uVar39;
          *(int *)((ulonglong)uVar39 >> 0x20) = iVar6;
        }
        puVar37 = *(uint **)(iVar19 + param_7);
        if (uVar21 < *puVar37) {
          uVar33 = puVar37[1];
          if (uVar33 <= uVar21) {
            pdVar16 = (dword *)((uVar21 - uVar33) * 4 + 4);
            _memset((void *)(uVar33 * 4 + puVar37[2]),0,(size_t)pdVar16);
            puVar37[1] = uVar21 + 1;
            uVar8 = extraout_r4_06;
          }
          uVar39 = CONCAT44(uVar21 * 4 + puVar37[2],uVar8);
        }
        else {
          uVar39 = FUN_0019423c(puVar37,uVar21);
        }
        uVar8 = (undefined4)uVar39;
        pdVar24 = *(dword **)(*(int *)((ulonglong)uVar39 >> 0x20) + 0x94);
      }
      else {
        if (((pdVar17 != (dword *)0x0) && (pdVar29 == (dword *)0x0)) && (pdVar26 == (dword *)0x0)) {
          pdVar31 = &MACH_HEADER.cputype;
          param_5 = pdVar24;
          ((int (*)())FUN_000f94dc)(param_1,param_2,pdVar16,pdVar17,pdVar24,4,*(undefined4 *)(param_1 + 0x400));
          uVar1 = *(ushort *)((int)param_4 + (int)pdVar28 * 4 + 2);
          iVar19 = FUN_001043f0(0x68,*(undefined4 *)(param_1 + 8));
          uVar8 = FUN_000ec208(param_1,4);
          iVar6 = FUN_001054ec(iVar19,0);
          uVar21 = DAT_001aa9a8;
          *(undefined4 *)(iVar6 + 0xc) = uVar8;
          *(dword **)(iVar6 + 8) = pdVar24;
          *(uint *)(iVar19 + 0x130) = (uint)uVar1;
          goto LAB_000fc3f4;
        }
LAB_000fc43c:
        ((int (*)())FUN_000f94dc)(param_1,param_2,pdVar16,pdVar17,pdVar24,4,*(undefined4 *)(param_1 + 0x400));
        uVar33 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) - 1;
        *(uint *)(*(int *)(param_1 + 8) + 0x3ac) = uVar33;
        uVar21 = (uint)(ushort)*pdVar29;
        if (pdVar27 != (dword *)0x0) {
          iVar19 = FUN_001043f0(0xc6,*(undefined4 *)(param_1 + 8));
          uVar8 = FUN_000ec208(param_1,4);
          iVar6 = FUN_001054ec(iVar19,0);
          uVar18 = DAT_001aa9d0;
          *(undefined4 *)(iVar6 + 0xc) = uVar8;
          *(uint *)(iVar19 + 0x9c) = uVar18;
          *(uint *)(iVar6 + 8) = uVar33;
          uVar18 = *pdVar27;
          ((int (*)())FUN_000f7870)(iVar19,param_1,1,uVar18,uVar18,uVar18,uVar18);
          uVar8 = FUN_000ec208(param_1,*pdVar29 >> 0x10 & 0x3f);
          iVar6 = FUN_001054ec(iVar19,2);
          local_94[0] = DAT_001aa9a8;
          *(undefined4 *)(iVar6 + 0xc) = uVar8;
          *(uint *)(iVar6 + 8) = uVar21;
          ((int (*)())FUN_000f8aa0)(param_1,local_94,pdVar29,2,iVar19);
          FUN_00193f64(param_2,iVar19);
          *pdVar29 = *pdVar29 & 0xffc0ffff | 0x40000;
          uVar21 = uVar33;
        }
        pdVar28 = (dword *)FUN_001043f0(0xe6,*(undefined4 *)(param_1 + 8));
        uVar8 = FUN_000ec208(param_1,4);
        iVar19 = FUN_001054ec(pdVar28,0);
        uVar18 = DAT_001aa9d0;
        *(undefined4 *)(iVar19 + 0xc) = uVar8;
        pdVar16 = (dword *)((int)&MACH_HEADER.magic + 1);
        pdVar28[0x27] = uVar18;
        pdVar17 = &MACH_HEADER.cputype;
        param_5 = &MACH_HEADER.cputype;
        pdVar31 = &MACH_HEADER.cputype;
        *(uint *)(iVar19 + 8) = uVar33;
        ((int (*)())FUN_000f7870)(pdVar28,param_1,1,4,4,4,4);
        uVar8 = FUN_000ec208(param_1,*pdVar29 >> 0x10 & 0x3f);
        iVar19 = FUN_001054ec(pdVar28,2);
        local_98 = DAT_001aa9a8;
        *(undefined4 *)(iVar19 + 0xc) = uVar8;
        *(uint *)(iVar19 + 8) = uVar21;
        uVar8 = DAT_001aa9cc;
        if (pdVar27 == (dword *)0x0) {
          pdVar17 = (dword *)((int)&MACH_HEADER.magic + 2);
          param_5 = pdVar28;
          ((int (*)())FUN_000f8aa0)(param_1,&local_98,pdVar29,2,pdVar28);
          pdVar16 = pdVar29;
        }
        else {
          iVar19 = FUN_001054ec(pdVar28,2);
          *(undefined4 *)(iVar19 + 0x10) = uVar8;
        }
        FUN_00193f64(param_2,pdVar28);
        iVar19 = FUN_001043f0(0xc6,*(undefined4 *)(param_1 + 8));
        *(uint *)(iVar19 + 0x9c) = DAT_001aa9d0;
        uVar8 = FUN_000ec208(param_1,4);
        iVar6 = FUN_001054ec(iVar19,0);
        *(undefined4 *)(iVar6 + 0xc) = uVar8;
        *(dword **)(iVar6 + 8) = pdVar24;
        uVar8 = FUN_000ec208(param_1,4);
        iVar6 = FUN_001054ec(iVar19,1);
        *(undefined4 *)(iVar6 + 0xc) = uVar8;
        *(dword **)(iVar6 + 8) = pdVar24;
        uVar8 = FUN_000ec208(param_1,4);
        iVar6 = FUN_001054ec(iVar19,2);
        *(undefined4 *)(iVar6 + 0xc) = uVar8;
        *(uint *)(iVar6 + 8) = uVar33;
        uVar8 = DAT_001aa9cc;
        iVar13 = FUN_001054ec(iVar19,1);
        iVar6 = 0;
        *(undefined4 *)(iVar13 + 0x10) = uVar8;
        iVar13 = FUN_001054ec(iVar19,2);
        *(undefined4 *)(iVar13 + 0x10) = uVar8;
        FUN_00193f64(param_2,iVar19);
        iVar19 = FUN_001043f0(0x68,*(undefined4 *)(param_1 + 8));
        uVar34 = FUN_000ec208(param_1,4);
        iVar13 = FUN_001054ec(iVar19,0);
        uVar21 = DAT_001aa9a8;
        *(undefined4 *)(iVar13 + 0xc) = uVar34;
        *(dword **)(iVar13 + 8) = pdVar24;
        *(undefined4 *)(iVar19 + 0x130) = 0;
        *(uint *)(iVar19 + 0x140) = uVar21;
        uVar34 = FUN_000ec208(param_1,4);
        iVar13 = FUN_001054ec(iVar19,1);
        *(undefined4 *)(iVar13 + 0xc) = uVar34;
        *(dword **)(iVar13 + 8) = pdVar24;
        iVar13 = FUN_001054ec(iVar19,1);
        *(undefined4 *)(iVar13 + 0x10) = uVar8;
LAB_000fc74c:
        FUN_00193f64(param_2,iVar19);
        uVar8 = extraout_r4_07;
        if (iVar6 != 0) {
          FUN_00193f64(param_2,iVar6);
          uVar8 = extraout_r4_08;
        }
      }
      bVar3 = false;
      *param_4 = *param_4 & 0xffc0ffff | 0x40000;
      *(short *)((int)param_4 + 2) = (short)pdVar24;
    }
  }
  if (uVar22 == 0) goto code_r0x000fd490;
  uVar21 = *param_4;
  if (((uVar21 & 0x400000) == 0) || ((param_4[1] & 0x4444) == 0)) {
    bVar2 = false;
  }
  else {
    uVar8 = FUN_0019e9fc(param_4,0);
    uVar34 = FUN_0019e9fc(param_4,1);
    uVar36 = FUN_0019e9fc(param_4,2);
    uVar10 = FUN_0019e9fc(param_4,3);
    pdVar17 = local_94;
    pdVar24 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1);
    *(dword **)(*(int *)(param_1 + 8) + 0x3ac) = pdVar24;
    uVar11 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar19 = FUN_001054ec(uVar11,0);
    *(undefined4 *)(iVar19 + 0xc) = 0;
    *(dword **)(iVar19 + 8) = pdVar24;
    uVar12 = FUN_000ec208(param_1,uVar23);
    iVar19 = FUN_001054ec(uVar11,1);
    local_94[0] = DAT_001aa9a8;
    *(undefined4 *)(iVar19 + 0xc) = uVar12;
    *(dword **)(iVar19 + 8) = pdVar30;
    dVar38 = (double)((double (*)())FUN_000f8a30)(uVar8,0,&local_98,pdVar17);
    fparam_2 = (double)((double (*)())FUN_000f8a30)(uVar34,1,&local_98,pdVar17);
    fparam_3 = (double)((double (*)())FUN_000f8a30)(uVar36,2,&local_98,pdVar17);
    fparam_4 = (double)((double (*)())FUN_000f8a30)(uVar10,3,&local_98,pdVar17);
    uVar21 = local_94[0];
    iVar19 = FUN_001054ec(uVar11,1);
    *(uint *)(iVar19 + 0x10) = uVar21;
    FUN_00193f64(param_2,uVar11);
    iVar19 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar6 = FUN_001054ec(iVar19,0);
    *(undefined4 *)(iVar6 + 0xc) = 0;
    *(dword **)(iVar6 + 8) = pdVar24;
    pdVar16 = (dword *)((int)&MACH_HEADER.magic + 1);
    ((void (*)())FUN_000f79c4)(iVar19,param_1,1,dVar38,fparam_2,fparam_3,fparam_4);
    *(uint *)(iVar19 + 0x9c) = local_98;
    FUN_00193f64(param_2,iVar19);
    uVar21 = *param_4;
    uVar8 = extraout_r4_09;
    pdVar30 = pdVar24;
    if ((uVar21 & 0x400000) == 0) {
      uVar23 = 4;
      bVar2 = true;
    }
    else {
      uVar23 = 4;
      bVar2 = true;
      param_4[1] = param_4[1] & 0xffff8888 | 0x3210;
    }
  }
  if ((uVar21 & 0x400000) == 0) goto code_r0x000fd490;
  puVar20 = (undefined1 *)param_4[1];
  pdVar28 = param_4 + 1;
  if (((uint)puVar20 & 0xffff8888) == 0) goto code_r0x000fd490;
  pdVar25 = pdVar30;
  if (((ushort)*param_3 - 0x8e < 0x10) && (((uint)puVar20 & 0x8888) != 0)) {
    param_4[1] = (uint)puVar20 & 0xffff7777;
    pdVar25 = pdVar24;
    if (!bVar2) {
      puVar20 = *(undefined1 **)(param_1 + 8);
      pdVar25 = (dword *)(*(int *)(puVar20 + 0x3ac) + -1);
      *(dword **)(puVar20 + 0x3ac) = pdVar25;
    }
    bVar2 = true;
    uVar8 = FUN_001043f0(0xcb,*(undefined4 *)(param_1 + 8));
    iVar19 = FUN_001054ec(uVar8,0);
    dVar38 = (double)FLOAT_001aa0d4;
    pdVar16 = (dword *)((int)&MACH_HEADER.magic + 2);
    *(undefined4 *)(iVar19 + 0xc) = 0;
    *(dword **)(iVar19 + 8) = pdVar25;
    ((void (*)())FUN_000f79c4)(uVar8,param_1,2,dVar38,dVar38,dVar38,dVar38);
    uVar34 = FUN_000ec208(param_1,uVar23);
    iVar19 = FUN_001054ec(uVar8,1);
    *(dword **)(iVar19 + 8) = pdVar30;
    *(undefined4 *)(iVar19 + 0xc) = uVar34;
    FUN_00193f64(param_2,uVar8);
    uVar21 = *param_4;
    uVar8 = extraout_r4_10;
    uVar23 = 4;
    pdVar24 = pdVar25;
  }
  pdVar30 = pdVar25;
  if (((uVar21 & 0x400000) != 0) && ((*pdVar28 & 0x10000) != 0)) {
    pdVar30 = pdVar24;
    if (!bVar2) {
      puVar20 = *(undefined1 **)(param_1 + 8);
      pdVar30 = (dword *)(*(int *)(puVar20 + 0x3ac) + -1);
      *(dword **)(puVar20 + 0x3ac) = pdVar30;
    }
    iVar19 = FUN_001043f0(0x12,*(undefined4 *)(param_1 + 8));
    iVar6 = FUN_001054ec(iVar19,0);
    *(undefined4 *)(iVar6 + 0xc) = 0;
    *(dword **)(iVar6 + 8) = pdVar30;
    uVar8 = FUN_000ec208(param_1,uVar23);
    iVar6 = FUN_001054ec(iVar19,1);
    *(undefined4 *)(iVar6 + 0xc) = uVar8;
    *(dword **)(iVar6 + 8) = pdVar25;
    FUN_00103d50(iVar19 + 0xa4,1,1);
    if (!bVar2) {
      ((int (*)())FUN_000f8f88)(param_4,iVar19);
    }
    pdVar16 = (dword *)((int)&MACH_HEADER.magic + 2);
    dVar38 = (double)FLOAT_001aa0e8;
    uVar23 = 4;
    bVar2 = true;
    ((void (*)())FUN_000f79c4)(iVar19,param_1,2,dVar38,dVar38,dVar38,dVar38);
    FUN_00193f64(param_2,iVar19);
    uVar21 = *param_4;
    uVar8 = extraout_r4_11;
    pdVar24 = pdVar30;
  }
  if ((((uVar21 & 0x400000) == 0) || ((*pdVar28 & 0x20000) == 0)) || ((*pdVar28 & 0x40000) == 0)) {
    if (((uVar21 & 0x400000) == 0) || ((*pdVar28 & 0x20000) == 0)) {
      if (((uVar21 & 0x400000) == 0) || ((*pdVar28 & 0x40000) == 0)) goto code_r0x000fcda8;
      if (!bVar2) {
        puVar20 = *(undefined1 **)(param_1 + 8);
        pdVar24 = (dword *)(*(int *)(puVar20 + 0x3ac) + -1);
        *(dword **)(puVar20 + 0x3ac) = pdVar24;
      }
      iVar6 = FUN_001043f0(0x13,*(undefined4 *)(param_1 + 8));
      iVar19 = FUN_001054ec(iVar6,0);
      *(undefined4 *)(iVar19 + 0xc) = 0;
      *(dword **)(iVar19 + 8) = pdVar24;
      uVar8 = FUN_000ec208(param_1,uVar23);
      iVar19 = FUN_001054ec(iVar6,1);
      *(undefined4 *)(iVar19 + 0xc) = uVar8;
      *(dword **)(iVar19 + 8) = pdVar30;
      if (!bVar2) {
        ((int (*)())FUN_000f8f88)(param_4,iVar6);
      }
      pdVar16 = (dword *)((int)&MACH_HEADER.magic + 2);
      dVar38 = (double)FLOAT_001aa108;
      ((void (*)())FUN_000f79c4)(iVar6,param_1,2,dVar38,dVar38,dVar38,dVar38);
      pdVar30 = pdVar24;
    }
    else {
      if (!bVar2) {
        puVar20 = *(undefined1 **)(param_1 + 8);
        pdVar24 = (dword *)(*(int *)(puVar20 + 0x3ac) + -1);
        *(dword **)(puVar20 + 0x3ac) = pdVar24;
      }
      iVar6 = FUN_001043f0(0x12,*(undefined4 *)(param_1 + 8));
      iVar19 = FUN_001054ec(iVar6,0);
      *(undefined4 *)(iVar19 + 0xc) = 0;
      *(dword **)(iVar19 + 8) = pdVar24;
      uVar8 = FUN_000ec208(param_1,uVar23);
      iVar19 = FUN_001054ec(iVar6,1);
      *(undefined4 *)(iVar19 + 0xc) = uVar8;
      *(dword **)(iVar19 + 8) = pdVar30;
      if (!bVar2) {
        ((int (*)())FUN_000f8f88)(param_4,iVar6);
      }
      dVar38 = (double)FLOAT_001aa10c;
      ((void (*)())FUN_000f79c4)(iVar6,param_1,2,dVar38,dVar38,dVar38,dVar38);
      pdVar16 = (dword *)((int)&MACH_HEADER.magic + 1);
      FUN_00103d50(iVar6 + 0xbc,1,1);
      pdVar30 = pdVar24;
    }
    FUN_00193f64(param_2,iVar6);
    uVar21 = *param_4;
    uVar23 = 4;
    bVar2 = true;
    uVar8 = extraout_r4_13;
    pdVar24 = pdVar30;
  }
  else {
    if (!bVar2) {
      puVar20 = *(undefined1 **)(param_1 + 8);
      pdVar24 = (dword *)(*(int *)(puVar20 + 0x3ac) + -1);
      *(dword **)(puVar20 + 0x3ac) = pdVar24;
    }
    iVar19 = FUN_001043f0(0x14,*(undefined4 *)(param_1 + 8));
    iVar6 = FUN_001054ec(iVar19,0);
    *(undefined4 *)(iVar6 + 0xc) = 0;
    *(dword **)(iVar6 + 8) = pdVar24;
    uVar8 = FUN_000ec208(param_1,uVar23);
    iVar6 = FUN_001054ec(iVar19,1);
    *(undefined4 *)(iVar6 + 0xc) = uVar8;
    *(dword **)(iVar6 + 8) = pdVar30;
    if (!bVar2) {
      ((int (*)())FUN_000f8f88)(param_4,iVar19);
    }
    dVar38 = (double)FLOAT_001aa108;
    uVar23 = 4;
    bVar2 = true;
    ((void (*)())FUN_000f79c4)(iVar19,param_1,2,dVar38,dVar38,dVar38,dVar38);
    dVar38 = (double)FLOAT_001aa0e8;
    ((void (*)())FUN_000f79c4)(iVar19,param_1,3,dVar38,dVar38,dVar38,dVar38);
    pdVar16 = (dword *)((int)&MACH_HEADER.magic + 1);
    FUN_00103d50(iVar19 + 0xd4,1,1);
    FUN_00193f64(param_2,iVar19);
    uVar21 = *param_4;
    uVar8 = extraout_r4_12;
    pdVar30 = pdVar24;
  }
code_r0x000fcda8:
  pdVar25 = pdVar30;
  if (((uVar21 & 0x400000) != 0) && ((*pdVar28 & 0x80000) != 0)) {
    puVar20 = *(undefined1 **)(param_1 + 8);
    pdVar25 = (dword *)(*(int *)(puVar20 + 0x3ac) + -1);
    *(dword **)(puVar20 + 0x3ac) = pdVar25;
    uVar8 = FUN_001043f0(0x26,*(undefined4 *)(param_1 + 8));
    iVar19 = FUN_001054ec(uVar8,0);
    *(undefined4 *)(iVar19 + 0xc) = 0;
    *(dword **)(iVar19 + 8) = pdVar25;
    uVar34 = FUN_000ec208(param_1,uVar23);
    iVar19 = FUN_001054ec(uVar8,1);
    dVar38 = (double)FLOAT_001aa0e8;
    *(undefined4 *)(iVar19 + 0xc) = uVar34;
    *(dword **)(iVar19 + 8) = pdVar30;
    ((void (*)())FUN_000f79c4)(uVar8,param_1,2,dVar38,dVar38,dVar38,dVar38);
    uVar34 = FUN_000ec208(param_1,uVar23);
    iVar19 = FUN_001054ec(uVar8,3);
    *(undefined4 *)(iVar19 + 0xc) = uVar34;
    *(dword **)(iVar19 + 8) = pdVar30;
    if (!bVar2) {
      ((int (*)())FUN_000f8f88)(param_4,uVar8);
      iVar19 = FUN_001054ec(uVar8,1);
      uVar34 = *(undefined4 *)(iVar19 + 0x10);
      iVar19 = FUN_001054ec(uVar8,3);
      *(undefined4 *)(iVar19 + 0x10) = uVar34;
    }
    FUN_00193f64(param_2,uVar8);
    iVar19 = FUN_001043f0(0x25,*(undefined4 *)(param_1 + 8));
    iVar6 = FUN_001054ec(iVar19,0);
    *(undefined4 *)(iVar6 + 0xc) = 0;
    *(dword **)(iVar6 + 8) = pdVar25;
    iVar6 = FUN_001054ec(iVar19,1);
    *(undefined4 *)(iVar6 + 0xc) = 0;
    uVar23 = 4;
    *(dword **)(iVar6 + 8) = pdVar25;
    iVar6 = FUN_001054ec(iVar19,2);
    dVar38 = (double)FLOAT_001aa0e8;
    *(undefined4 *)(iVar6 + 0xc) = 0;
    *(dword **)(iVar6 + 8) = pdVar25;
    bVar2 = true;
    ((void (*)())FUN_000f79c4)(iVar19,param_1,3,dVar38,dVar38,dVar38,dVar38);
    pdVar16 = (dword *)((int)&MACH_HEADER.magic + 1);
    FUN_00103d50(iVar19 + 0xd4,1,1);
    FUN_00193f64(param_2,iVar19);
    uVar21 = *param_4;
    uVar8 = extraout_r4_14;
    pdVar24 = pdVar25;
  }
  pdVar26 = pdVar25;
  if (((uVar21 & 0x400000) != 0) && (uVar22 = *pdVar28 >> 0x15 & 7, uVar22 != 0)) {
    puVar20 = (undefined1 *)**(undefined4 **)(*(int *)(param_1 + 8) + 0x30c);
    uVar39 = (**(code **)(puVar20 + 0xb4))();
    uVar8 = (undefined4)uVar39;
    if (((int)((ulonglong)uVar39 >> 0x20) == 0) ||
       ((pdVar16 = (dword *)(uint)(ushort)*param_3,
        (uint *)((int)&(*(GhidraMachOSection *)0x00000098).size + 2) < pdVar16 ||
        (pdVar16 != (dword *)((*(GhidraMachOSection *)0x00000054).sectname + 9))))) {
      if (uVar22 == 4) {
code_r0x000fd284:
        uVar21 = *param_4;
      }
      else {
        if (uVar22 == 1) {
          iVar19 = 1;
          uVar8 = UNK_001aaa28;
          uVar21 = DAT_001aa9d0;
        }
        else if (uVar22 == 2) {
          iVar19 = 2;
          uVar8 = DAT_001aaa20;
          uVar21 = UNK_001aaa24;
        }
        else {
          if (uVar22 != 3) goto code_r0x000fd284;
          iVar19 = 3;
          uVar8 = UNK_001aaa18;
          uVar21 = UNK_001aaa1c;
        }
        iVar6 = FUN_001043f0(0x40,*(undefined4 *)(param_1 + 8));
        pdVar26 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1);
        *(dword **)(*(int *)(param_1 + 8) + 0x3ac) = pdVar26;
        iVar13 = FUN_001054ec(iVar6,0);
        uVar34 = UNK_001aa9bc;
        *(undefined4 *)(iVar13 + 0xc) = 0;
        *(undefined4 *)(iVar6 + 0x9c) = uVar34;
        *(dword **)(iVar13 + 8) = pdVar26;
        uVar34 = FUN_000ec208(param_1,uVar23);
        iVar13 = FUN_001054ec(iVar6,1);
        *(undefined4 *)(iVar13 + 0xc) = uVar34;
        *(dword **)(iVar13 + 8) = pdVar25;
        iVar13 = FUN_001043f0(0x13,*(undefined4 *)(param_1 + 8));
        iVar14 = FUN_001054ec(iVar13,0);
        *(undefined4 *)(iVar14 + 0xc) = 0;
        *(dword **)(iVar14 + 8) = pdVar26;
        uVar34 = FUN_000ec208(param_1,uVar23);
        iVar14 = FUN_001054ec(iVar13,1);
        *(undefined4 *)(iVar14 + 0xc) = uVar34;
        *(dword **)(iVar14 + 8) = pdVar25;
        iVar14 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        iVar15 = FUN_001054ec(iVar14,0);
        *(undefined4 *)(iVar15 + 0xc) = 0;
        *(dword **)(iVar15 + 8) = pdVar26;
        uVar34 = FUN_000ec208(param_1,uVar23);
        iVar15 = FUN_001054ec(iVar14,1);
        *(undefined4 *)(iVar15 + 0xc) = uVar34;
        *(dword **)(iVar15 + 8) = pdVar25;
        if (!bVar2) {
          ((int (*)())FUN_000f8f88)(param_4,iVar13);
          iVar15 = FUN_001054ec(iVar13,1);
          uVar34 = *(undefined4 *)(iVar15 + 0x10);
          iVar15 = FUN_001054ec(iVar14,1);
          *(undefined4 *)(iVar15 + 0x10) = uVar34;
        }
        iVar15 = FUN_001054ec(iVar13,2);
        puVar5 = PTR_DAT_001e8b8c;
        *(undefined4 *)(iVar15 + 0xc) = 0;
        uVar34 = *(undefined4 *)(puVar5 + 0xc);
        uVar23 = 4;
        *(dword **)(iVar15 + 8) = pdVar26;
        iVar15 = FUN_001054ec(iVar13,2);
        *(undefined4 *)(iVar15 + 0x10) = uVar34;
        iVar15 = FUN_001054ec(iVar13,1);
        puVar20 = &STACKARG(0xffffff30) + iVar19;
        local_80 = *(undefined4 *)(iVar15 + 0x10);
        bVar2 = true;
        uVar34 = *(undefined4 *)(puVar5 + (uint)*(byte *)((int)&local_80 + iVar19) * 4);
        iVar19 = FUN_001054ec(iVar6,1);
        *(undefined4 *)(iVar19 + 0x10) = uVar34;
        *(uint *)(iVar13 + 0x9c) = uVar21;
        *(undefined4 *)(iVar14 + 0x9c) = uVar8;
        FUN_00193f64(param_2,iVar6);
        FUN_00193f64(param_2,iVar13);
        FUN_00193f64(param_2,iVar14);
        uVar21 = *param_4;
        uVar8 = extraout_r4_16;
        pdVar24 = pdVar26;
      }
    }
    else if (uVar22 == 3) {
      *(undefined4 *)(param_1 + 0x47c) = 1;
      uVar21 = *param_4;
    }
    else {
      if (uVar22 != 2) goto code_r0x000fd284;
      puVar20 = *(undefined1 **)(param_1 + 8);
      *(undefined4 *)(param_1 + 0x47c) = 1;
      bVar2 = true;
      pdVar26 = (dword *)(*(int *)(puVar20 + 0x3ac) + -1);
      *(dword **)(puVar20 + 0x3ac) = pdVar26;
      piVar7 = (int *)FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      iVar19 = FUN_001054ec(piVar7,0);
      *(undefined4 *)(iVar19 + 0xc) = 0;
      *(dword **)(iVar19 + 8) = pdVar26;
      uVar8 = FUN_000ec208(param_1,uVar23);
      iVar19 = FUN_001054ec(piVar7,1);
      *(undefined4 *)(iVar19 + 0xc) = uVar8;
      *(dword **)(iVar19 + 8) = pdVar25;
      ((int (*)())FUN_000f8f88)(param_4,piVar7);
      pcVar35 = *(code **)(*piVar7 + 0x88);
      iVar19 = FUN_001054ec(piVar7,1);
      pdVar17 = (dword *)(uint)*(byte *)(iVar19 + 0x12);
      pdVar16 = (dword *)((int)&MACH_HEADER.magic + 3);
      (*pcVar35)(piVar7,1);
      FUN_00193f64(param_2,piVar7);
      uVar21 = *param_4;
      uVar8 = extraout_r4_15;
      uVar23 = 4;
      pdVar24 = pdVar26;
    }
  }
  pdVar30 = pdVar26;
  if (((((uVar21 & 0x400000) != 0) && ((*pdVar28 & 0x8888) != 0)) &&
      (uVar21 = FUN_0019eaa4(param_4,uVar8,pdVar16,pdVar17,param_5,pdVar31,puVar20), uVar21 != 0))
     && (uVar21 != 0x8888)) {
    pdVar30 = pdVar24;
    if (!bVar2) {
      pdVar30 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1);
      *(dword **)(*(int *)(param_1 + 8) + 0x3ac) = pdVar30;
    }
    iVar19 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar6 = FUN_001054ec(iVar19,0);
    *(dword **)(iVar6 + 8) = pdVar30;
    *(undefined4 *)(iVar6 + 0xc) = 0;
    uVar8 = FUN_000ec208(param_1,uVar23);
    iVar6 = FUN_001054ec(iVar19,1);
    *(undefined4 *)(iVar6 + 0xc) = uVar8;
    *(dword **)(iVar6 + 8) = pdVar26;
    if (!bVar2) {
      ((int (*)())FUN_000f8f88)(param_4,iVar19);
    }
    if (((*param_4 & 0x400000) != 0) && ((*pdVar28 & 0x100000) != 0)) {
      FUN_00103d50(iVar19 + 0xa4,2,1);
    }
    FUN_00193f64(param_2,iVar19);
    iVar19 = FUN_001054ec(iVar19,1);
    uVar34 = *(undefined4 *)(iVar19 + 0x10);
    iVar19 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar6 = FUN_001054ec(iVar19,0);
    *(undefined4 *)(iVar6 + 0xc) = 0;
    *(dword **)(iVar6 + 8) = pdVar30;
    uVar8 = FUN_000ec208(param_1,uVar23);
    iVar6 = FUN_001054ec(iVar19,1);
    *(undefined4 *)(iVar6 + 0xc) = uVar8;
    *(dword **)(iVar6 + 8) = pdVar26;
    if (!bVar2) {
      iVar6 = FUN_001054ec(iVar19,1);
      *(undefined4 *)(iVar6 + 0x10) = uVar34;
    }
    FUN_00103d50(iVar19 + 0xa4,1,1);
    if ((((*param_4 & 0x400000) != 0) && ((*pdVar28 & 0x100000) != 0)) &&
       (FUN_00103d50(iVar19 + 0xa4,2,1), (*param_4 & 0x400000) != 0)) {
      *pdVar28 = *pdVar28 & 0xffefffff;
    }
    *(uint *)(iVar19 + 0x9c) =
         uVar21 >> 0xf & 1 ^ 1 |
         (uVar21 >> 0xb & 1 ^ 1) << 8 |
         (uVar21 >> 7 & 1 ^ 1) << 0x10 | (uVar21 >> 3 & 1 ^ 1) << 0x18;
    FUN_00193f64(param_2,iVar19);
    if ((*param_4 & 0x400000) != 0) {
      *pdVar28 = *pdVar28 & 0xffff7777;
    }
    uVar23 = 4;
  }
code_r0x000fd490:
  if (bVar3) {
    *(short *)((int)param_4 + 2) = (short)pdVar30;
    *param_4 = uVar23 << 0x10 | *param_4 & 0xffc0ffff;
  }
  return;
}

/* FUN_000fd50c @ 0xfd50c (188 bytes) */
int FUN_000fd50c(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 *param_3;
  undefined4 param_4;
  undefined4 param_5;
  uint *param_6;
{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar4,0x10);
  *puVar1 = uVar4;
  puVar1[1] = param_2;
  uVar4 = *param_3;
  puVar1[3] = param_4;
  puVar1[2] = uVar4;
  uVar3 = param_6[1];
  if (uVar3 < *param_6) {
    _memset((void *)(uVar3 * 4 + param_6[2]),0,4);
    piVar2 = (int *)(uVar3 * 4 + param_6[2]);
    param_6[1] = uVar3 + 1;
  }
  else {
    piVar2 = (int *)FUN_0019423c(param_6,uVar3);
  }
  *piVar2 = (int)(puVar1 + 1);
  *param_3 = 0xffffffff;
  return param_5;
}

/* FUN_000fd5c8 @ 0xfd5c8 (408 bytes) */
int FUN_000fd5c8(param_1, param_2)
  int param_1;
  uint ******param_2;
{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  float fVar5;
  short sVar6;
  ushort uVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined1 uVar10;
  uint uVar11;
  uint ******ppppppuVar12;
  uint *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  uint *****pppppuVar16;
  uint uVar17;
  int *piVar18;
  uint ******ppppppuVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int iVar23;
  undefined4 *puVar24;
  int iVar25;
  undefined2 *puVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined2 uVar33;
  undefined4 *puVar30;
  undefined4 *puVar31;
  uint ****ppppuVar32;
  undefined4 *puVar34;
  uint ******in_r6;
  uint ******in_r7;
  uint ******in_r8;
  uint ***pppuVar35;
  int iVar36;
  uint *puVar37;
  int *piVar38;
  uint ******ppppppuVar39;
  uint ******ppppppuVar40;
  uint *****pppppuVar41;
  uint ******ppppppuVar42;
  uint *****pppppuVar43;
  uint ***pppuVar44;
  int iVar45;
  uint uVar46;
  uint ****ppppuVar47;
  undefined4 uVar48;
  int iVar49;
  uint ******ppppppuVar50;
  uint ******ppppppuVar51;
  undefined4 uVar52;
  uint ****ppppuVar53;
  uint *****pppppuVar54;
  undefined1 *puVar55;
  double dVar56;
  uint ****local_188;
  uint *****local_184;
  uint *****local_180;
  int *local_17c;
  undefined4 local_178;
  uint ****local_174;
  uint *****local_170;
  undefined1 auStack_16c [8];
  int local_164;
  undefined1 auStack_154 [8];
  int local_14c;
  uint *local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  undefined4 local_12c;
  undefined4 local_128;
  undefined4 local_124;
  int local_11c;
  uint *****local_118;
  undefined4 local_104;
  int local_100;
  undefined4 local_d8;
  uint ****local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  uint local_c4;
  uint *****local_c0;
  int local_bc;
  int local_b8;
  undefined4 local_b4;
  uint *local_b0;
  int local_ac;
  uint *****local_a8;
  uint *****local_a4;
  undefined4 *local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint local_90;
  uint local_8c;
  uint *****local_88;
  uint *****local_84;
  uint local_80;
  uint ****local_7c;
  undefined *local_78;
  int local_74;
  undefined4 *local_70;
  undefined1 *local_6c;
  undefined1 *local_68;
  int local_64;
  undefined *local_60;
  undefined *local_5c;
  uint ****local_58;
  
  iVar36 = *(int *)(*(int *)(param_1 + 8) + 0x30c);
  local_9c = 0;
  local_98 = 0;
  *(uint *)(iVar36 + 8) = *(uint *)(iVar36 + 8) & 0xffffffdf;
  local_94 = 0;
  uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  iVar36 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0x50);
  uVar11 = iVar36 + 0x1fU >> 5;
  puVar14 = (undefined4 *)FUN_00193e18(uVar48,uVar11 * 4 + 0xc);
  local_a0 = puVar14 + 1;
  *puVar14 = uVar48;
  puVar14[1] = uVar11;
  puVar14[2] = iVar36;
  local_90 = 0;
  local_8c = 0;
  local_88 = (uint *****)0x0;
  local_84 = (uint *****)0x0;
  local_80 = 0;
  if (uVar11 != 0) {
    puVar14 = local_a0;
    if (uVar11 == 0) {
      uVar11 = 1;
    }
    do {
      uVar11 = uVar11 - 1;
      puVar14[2] = 0;
      puVar14 = puVar14 + 1;
    } while (uVar11 != 0);
  }
  uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar14 = (undefined4 *)FUN_00193e18(uVar48,0x14);
  ppppppuVar39 = (uint ******)(puVar14 + 1);
  *puVar14 = uVar48;
  puVar14[1] = 2;
  puVar14[4] = uVar48;
  puVar14[2] = 0;
  uVar48 = FUN_00193e18(uVar48,8);
  puVar14[3] = uVar48;
  local_188 = (uint ****)0x0;
  uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar15 = (undefined4 *)FUN_00193e18(uVar48,0x14);
  local_a8 = (uint *****)(puVar15 + 1);
  *puVar15 = uVar48;
  puVar15[1] = 2;
  puVar15[4] = uVar48;
  puVar15[2] = 0;
  pppppuVar16 = (uint *****)FUN_00193e18(uVar48,8);
  local_a8[2] = (uint ****)pppppuVar16;
  uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar15 = (undefined4 *)FUN_00193e18(uVar48,0x14);
  local_b0 = puVar15 + 1;
  *puVar15 = uVar48;
  puVar15[1] = 2;
  puVar15[2] = 0;
  puVar15[4] = uVar48;
  uVar11 = FUN_00193e18(uVar48,8);
  local_b0[2] = uVar11;
  uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar15 = (undefined4 *)FUN_00193e18(uVar48,0x14);
  puVar15[1] = 2;
  *puVar15 = uVar48;
  puVar15[2] = 0;
  puVar15[4] = uVar48;
  uVar48 = FUN_00193e18(uVar48,8);
  puVar15[3] = uVar48;
  *(undefined4 **)(param_1 + 0x414) = puVar15 + 1;
  uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar15 = (undefined4 *)FUN_00193e18(uVar48,0x14);
  puVar15[1] = 2;
  *puVar15 = uVar48;
  puVar15[2] = 0;
  puVar15[4] = uVar48;
  uVar48 = FUN_00193e18(uVar48,8);
  puVar15[3] = uVar48;
  local_5c = &DAT_001ad5d8;
  local_184 = *(uint ******)(param_1 + 0x3a0);
  local_128 = 0;
  local_170 = (uint *****)DAT_001aa9e0;
  local_174 = (uint ****)0xffffffff;
  local_138 = 0;
  local_134 = 0;
  local_130 = 0;
  local_12c = 0;
  uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  local_13c = puVar15 + 1;
  puVar15 = (undefined4 *)FUN_00193e18(uVar48,0x130);
  *puVar15 = uVar48;
  ppppppuVar51 = (uint ******)(puVar15 + 1);
  FUN_000ea020(ppppppuVar51,*(undefined4 *)(param_1 + 8));
  local_180 = (uint *****)ppppppuVar51;
  FUN_000ec3ac(param_1,local_184,ppppppuVar51);
  local_6c = auStack_16c;
  FUN_000e8e4c(local_184,local_180);
  local_68 = auStack_154;
  local_184 = local_180;
  FUN_001940a8(local_6c);
  FUN_001940a8(local_68);
  *(undefined4 *)(param_1 + 0x3d4) = 0;
  *(undefined4 *)(param_1 + 0x3e4) = 0;
  ((int (*)())FUN_000fb230)(param_1,param_2);
  local_a4 = (uint *****)0x0;
  local_ac = 0;
switchD_000fdaf0_caseD_2:
  iVar36 = FUN_000e5e70(param_2);
  if (iVar36 == 0) {
code_r0x00103c40:
    FUN_000ec728(param_1);
    FUN_000e8e4c(local_180,*(undefined4 *)(param_1 + 0x3a8));
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 2;
    FUN_0012e8c0(param_1,*(undefined4 *)(param_1 + 0x3a0),*(undefined4 *)(param_1 + 0x3a8));
    if ((uint ******)local_a8 != (uint ******)0x0) {
      FUN_00193cc0(local_a8[3],local_a8[2]);
      FUN_00193cc0(local_a8[-1],local_a8 + -1);
    }
    if (ppppppuVar39 != (uint ******)0x0) {
      FUN_00193cc0(puVar14[4],puVar14[3]);
      FUN_00193cc0(*puVar14,puVar14);
    }
    if (local_a0 != (undefined4 *)0x0) {
      FUN_00193cc0(local_a0[-1],local_a0 + -1);
    }
    FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),*(undefined4 *)(param_1 + 0x78));
    FUN_0011e894(param_1);
    return;
  }
  iVar36 = FUN_000e43ec(param_2);
  if (iVar36 != 0) {
    iVar36 = *(int *)(param_1 + 0x3c4);
    iVar45 = 0;
    local_17c = (int *)0x0;
    for (uVar11 = 1; uVar11 <= *(uint *)(iVar36 + 4); uVar11 = uVar11 + 1) {
      local_17c = *(int **)(iVar45 + *(int *)(iVar36 + 8));
      if ((local_17c[5] & 1U) != 0) {
        (**(code **)(*local_17c + 0x68))(local_17c);
        piVar18 = local_17c;
        uVar48 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(uVar48,1,local_17c[0x29]);
        puVar13 = local_13c;
        uVar46 = piVar18[0x50];
        if (uVar46 < *local_13c) {
          uVar17 = local_13c[1];
          if (uVar17 <= uVar46) {
            _memset((void *)(uVar17 * 4 + local_13c[2]),0,(uVar46 - uVar17) * 4 + 4);
            puVar13[1] = uVar46 + 1;
          }
          puVar15 = (undefined4 *)(uVar46 * 4 + puVar13[2]);
        }
        else {
          puVar15 = (undefined4 *)FUN_0019423c(local_13c,uVar46);
        }
        *puVar15 = uVar48;
        iVar36 = *(int *)(param_1 + 0x3c4);
      }
      iVar45 = iVar45 + 4;
    }
    piVar18 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
    (**(code **)(*piVar18 + 0x17c))(piVar18,param_1);
    FUN_000e5e70(param_2);
  }
  ppppppuVar51 = param_2 + 0x23;
  *(undefined4 *)(param_1 + 0x47c) = 0;
  iVar36 = FUN_000e4408(param_2);
  if (iVar36 == 0x52) {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x100;
  }
  else if (((iVar36 == 0x84) && ((*(uint *)(param_1 + 0x30) & 0x40000) != 0)) &&
          ((*(uint *)(param_1 + 0x30) & 0x200000) == 0)) goto code_r0x00103c40;
  iVar45 = *(int *)(param_1 + 8);
  piVar18 = *(int **)(iVar45 + 0x30c);
  iVar49 = piVar18[3];
  uVar48 = ((int (*)())FUN_000f89a4)(iVar36,iVar49);
  switch(uVar48) {
  case 0:
  case 1:
    switch(iVar36) {
    case 0x14:
      if ((*(uint *)(param_1 + 0x30) & 0x4000) == 0) {
        ppppuVar47 = *param_2[0x1b];
        iVar36 = FUN_000ec208(param_1,(uint)*ppppuVar47 >> 0x10 & 0x3f);
        iVar45 = *(int *)(param_1 + 8);
        if (((((uint)*ppppuVar47 & 0x3f0000) == 0x100000) && (iVar45 != 0)) &&
           ((*(uint *)(*(int *)(iVar45 + 0x30c) + 8) & 0x80) != 0)) {
          iVar49 = 0xf;
        }
        else {
          iVar49 = (int)*(short *)((int)ppppuVar47 + 2);
        }
        if (((((uint)*param_2[0x1b][1] & 0x3f0000) == 0x100000) && (iVar45 != 0)) &&
           ((*(uint *)(*(int *)(iVar45 + 0x30c) + 8) & 0x80) != 0)) {
          iVar45 = 0xf;
        }
        else {
          iVar45 = (int)*(short *)((int)param_2[0x1b][1] + 2);
        }
        if (iVar36 == 0x15) {
code_r0x000fed00:
          if ((*(uint *)(param_1 + 0x30) & 0x4000) == 0) {
            *(int *)(param_1 + 1000) = iVar49;
            *(undefined4 *)(param_1 + 0x3e4) = 1;
            *(int *)(param_1 + 0x3ec) = iVar45 + 1;
            *(int *)(param_1 + 0x3f4) = iVar36;
            if (((*(uint *)(param_1 + 0x30) & 1) != 0) && (iVar49 < iVar45 + 1)) {
              do {
                in_r6 = (uint ******)0x0;
                FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),iVar36,iVar49,0);
                iVar49 = iVar49 + 1;
              } while (iVar49 < *(int *)(param_1 + 0x3ec));
            }
          }
          goto switchD_000fdaf0_caseD_2;
        }
        if (iVar36 < 0x16) {
          if (iVar36 != 0x14) goto switchD_000fdaf0_caseD_2;
        }
        else if (iVar36 != 0x1a) {
          if (iVar36 == 0x24) goto code_r0x000fed00;
          goto switchD_000fdaf0_caseD_2;
        }
        *(int *)(param_1 + 1000) = iVar49;
        *(undefined4 *)(param_1 + 0x3e4) = 1;
        *(int *)(param_1 + 0x3ec) = iVar45 + 1;
        *(int *)(param_1 + 0x3f4) = iVar36;
        if (((*(uint *)(param_1 + 0x30) & 1) != 0) && (iVar49 < iVar45 + 1)) {
          do {
            in_r6 = (uint ******)0x0;
            FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),iVar36,iVar49,0);
            iVar49 = iVar49 + 1;
          } while (iVar49 < *(int *)(param_1 + 0x3ec));
        }
      }
    default:
      goto switchD_000fdaf0_caseD_2;
    case 0x16:
    case 0x18:
      if ((*(uint *)(*(int *)(iVar45 + 0x6c4) + 0x30) & 0x2000) != 0) {
        pppuVar44 = **param_2[0x19];
        uVar11 = (uint)pppuVar44 >> 0x10 & 0x3f;
        if (((((uint)pppuVar44 & 0x3f0000) == 0x100000) && (iVar45 != 0)) &&
           ((piVar18[2] & 0x80U) != 0)) {
          ppppppuVar19 = (uint ******)((int)&MACH_HEADER.filetype + 3);
        }
        else {
          ppppppuVar19 = (uint ******)(int)*(short *)((int)*param_2[0x19] + 2);
        }
        uVar48 = FUN_000ec208(param_1,uVar11);
        in_r6 = (uint ******)FUN_000ec2a0(param_1,uVar11);
        iVar36 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),uVar48,ppppppuVar19,0);
        iVar36 = *(int *)(iVar36 + 0x38);
        FUN_001041d0(iVar36,0,(uint)*ppppppuVar51 >> 0x10 & 3,in_r6,ppppppuVar19);
        FUN_001041d0(iVar36,1,(uint)*ppppppuVar51 >> 0x12 & 3,in_r6,ppppppuVar19);
        FUN_001041d0(iVar36,2,(uint)*ppppppuVar51 >> 0x14 & 3,in_r6,ppppppuVar19);
        in_r7 = ppppppuVar19;
        FUN_001041d0(iVar36,3,(uint)*ppppppuVar51 >> 0x16 & 3,in_r6,ppppppuVar19);
        pppppuVar16 = *ppppppuVar51;
        if (((uint)pppppuVar16 & 0x1000000) != 0) {
          *(uint *)(iVar36 + 0x13c) = *(uint *)(iVar36 + 0x13c) | 1;
          pppppuVar16 = *ppppppuVar51;
        }
        *(uint *******)(iVar36 + 0x148) = ppppppuVar19;
        *(uint *)(iVar36 + 0x140) = (uint)pppppuVar16 >> 0x19 & 1;
        *(undefined4 *)(iVar36 + 0x144) = uVar48;
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x17:
      ppppppuVar19 = (uint ******)FUN_000ec27c(param_1,(uint)*ppppppuVar51 >> 0x10 & 0x1f);
      ppppppuVar40 = (uint ******)((uint)*ppppppuVar51 >> 0x15 & 0xff);
      if ((int)*ppppppuVar51 < 0) {
        pppppuVar16 = param_2[0x24];
        uVar17 = (uint)pppppuVar16 >> 9 & 1;
        uVar11 = (uint)pppppuVar16 >> 8 & 1;
        uVar46 = (uint)pppppuVar16 >> 10 & 1;
        local_178 = (uint ******)
                    (CONCAT31(CONCAT21(CONCAT11((char)pppppuVar16,(char)((uint)pppppuVar16 >> 2)),
                                       (char)((uint)pppppuVar16 >> 4)),
                              (char)((uint)pppppuVar16 >> 6)) & 0x3030303);
      }
      else {
        uVar11 = 0;
        uVar46 = 0;
        uVar17 = 0;
        local_178 = (uint ******)0x3030303;
      }
      iVar45 = (int)*(short *)((int)*param_2[0x19] + 2);
      uVar48 = FUN_000ec208(param_1,(uint)**param_2[0x19] >> 0x10 & 0x3f);
      iVar36 = *(int *)(param_1 + 1000);
      if (iVar45 <= *(int *)(param_1 + 1000)) {
        iVar36 = iVar45;
      }
      iVar49 = *(int *)(param_1 + 0x3ec);
      *(int *)(param_1 + 1000) = iVar36;
      if (iVar49 <= iVar45) {
        iVar49 = iVar45 + 1;
      }
      *(int *)(param_1 + 0x3ec) = iVar49;
      *(undefined4 *)(param_1 + 0x3f4) = 0x24;
      in_r6 = (uint ******)0x0;
      iVar36 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),uVar48,iVar45,0);
      iVar36 = *(int *)(iVar36 + 0x38);
      if (uVar11 == 0) {
        *(uint *)(iVar36 + 0x13c) = *(uint *)(iVar36 + 0x13c) | 1;
      }
      if (uVar46 != 0) {
        *(uint *)(iVar36 + 0x13c) = *(uint *)(iVar36 + 0x13c) | 4;
      }
      if (uVar17 != 0) {
        *(uint *)(iVar36 + 0x13c) = *(uint *)(iVar36 + 0x13c) | 2;
      }
      local_70 = &local_178;
      iVar45 = 0;
      do {
        if (*(byte *)(iVar45 + (int)local_70) != 0) {
          in_r6 = ppppppuVar19;
          in_r7 = ppppppuVar40;
          FUN_001041d0(iVar36,iVar45,(uint)*(byte *)(iVar45 + (int)local_70),ppppppuVar19,
                       ppppppuVar40);
        }
        bVar1 = iVar45 != 3;
        iVar45 = iVar45 + 1;
      } while (bVar1);
      goto switchD_000fdaf0_caseD_2;
    case 0x19:
      bVar4 = *(byte *)((int)param_2 + 0x8d);
      pppppuVar16 = *ppppppuVar51;
      iVar36 = (uint)bVar4 * 0xc;
      *(uint *)(*(int *)(param_1 + 0x78) + iVar36) = (uint)pppppuVar16 >> 0x1b & 3;
      if (*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0x50) < (int)(uint)bVar4) {
        FUN_000e1534(*(int *)(param_1 + 8),7);
      }
      uVar11 = bVar4 >> 3 & 0x1c;
      *(uint *)((int)local_a0 + uVar11 + 8) =
           1 << (bVar4 & 0x1f) | *(uint *)((int)local_a0 + uVar11 + 8);
      *(uint *)(iVar36 + *(int *)(param_1 + 0x78) + 8) = (uint)*ppppppuVar51 >> 0x1d & 1;
      piVar18 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
      iVar45 = (**(code **)(*piVar18 + 0x48))(piVar18,param_1,(uint)pppppuVar16 >> 0x18 & 7);
      if (iVar45 != 0) {
        *(int *)(iVar36 + *(int *)(param_1 + 0x78) + 4) = iVar45;
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x1a:
      FUN_001940a8(&local_124);
      pppppuVar16 = *ppppppuVar51;
      uVar11 = 0;
      in_r7 = UNK_001aa9c8;
      if ((int)pppppuVar16 < 0) {
        pppppuVar54 = param_2[0x24];
        bVar1 = ((uint)pppppuVar54 & 3) != 0;
        in_r7 = *(uint *******)(local_5c + -0x2bf8);
        if (bVar1) {
          in_r7 = (uint ******)((uint)in_r7 & 0xffffff | 0x4000000);
        }
        uVar11 = (uint)bVar1;
        if (((uint)pppppuVar54 & 0xc) != 0) {
          iVar36 = uVar11 + 4;
          uVar11 = uVar11 + 1;
          in_r7 = (uint ******)(iVar36 * 0x10000 | (uint)in_r7 & 0xff00ffff);
        }
        if (((uint)pppppuVar54 & 0x30) != 0) {
          iVar36 = uVar11 + 4;
          uVar11 = uVar11 + 1;
          in_r7 = (uint ******)(iVar36 * 0x100 | (uint)in_r7 & 0xffff00ff);
        }
        if (((uint)pppppuVar54 & 0xc0) != 0) {
          uVar46 = uVar11 + 4;
          uVar11 = uVar11 + 1;
          in_r7 = (uint ******)(uVar46 | (uint)in_r7 & 0xffffff00);
        }
      }
      in_r6 = (uint ******)*param_2[0x19];
      if (((uint)*in_r6 & 0x400000) != 0) {
        in_r7 = *(uint *******)(local_5c + -0x2bf8);
        iVar36 = FUN_0019e990(in_r6,0);
        puVar8 = PTR_DAT_001e8bc8;
        if (*(int *)(PTR_DAT_001e8bc8 + iVar36 * 4) == 0) {
          iVar36 = uVar11 + 4;
          uVar11 = uVar11 + 1;
          in_r7 = (uint ******)(iVar36 * 0x1000000 | (uint)in_r7 & 0xffffff);
        }
        iVar36 = FUN_0019e990(in_r6,1);
        if (*(int *)(puVar8 + iVar36 * 4) == 0) {
          iVar36 = uVar11 + 4;
          uVar11 = uVar11 + 1;
          in_r7 = (uint ******)(iVar36 * 0x10000 | (uint)in_r7 & 0xff00ffff);
        }
        iVar36 = FUN_0019e990(in_r6,2);
        if (*(int *)(puVar8 + iVar36 * 4) == 0) {
          iVar36 = uVar11 + 4;
          uVar11 = uVar11 + 1;
          in_r7 = (uint ******)(iVar36 * 0x100 | (uint)in_r7 & 0xffff00ff);
        }
        iVar36 = FUN_0019e990(in_r6,3);
        if (*(int *)(puVar8 + iVar36 * 4) == 0) {
          in_r7 = (uint ******)(uVar11 + 4 | (uint)in_r7 & 0xffffff00);
        }
      }
      iVar45 = (int)*(short *)((int)in_r6 + 2);
      iVar36 = *(int *)(param_1 + 0x3d8);
      if (iVar45 <= *(int *)(param_1 + 0x3d8)) {
        iVar36 = iVar45;
      }
      iVar49 = *(int *)(param_1 + 0x3dc);
      *(int *)(param_1 + 0x3d8) = iVar36;
      if (iVar49 <= iVar45) {
        iVar49 = iVar45 + 1;
      }
      *(int *)(param_1 + 0x3dc) = iVar49;
      piVar18 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
      in_r8 = *(uint *******)(param_1 + 0x3a0);
      (**(code **)(*piVar18 + 0x4c))(piVar18,param_1,(uint)pppppuVar16 >> 0x10 & 0x3f);
      iVar45 = *(int *)(local_11c + 8);
      iVar36 = local_11c;
      while (iVar49 = iVar45, iVar49 != 0) {
        FUN_0019401c(iVar36);
        ((int (*)())FUN_000f92fc)(param_1,iVar36,local_180);
        iVar36 = iVar49;
        iVar45 = *(int *)(iVar49 + 8);
      }
      local_124 = (uint ******)(PTR_DAT_001e8b48 + 8);
      local_118 = (uint *****)local_124;
      goto switchD_000fdaf0_caseD_2;
    case 0x1b:
      iVar36 = FUN_000ec27c(param_1,(uint)*ppppppuVar51 >> 0x10 & 0x1f);
      ppppppuVar19 = (uint ******)((uint)*ppppppuVar51 >> 0x15 & 0xff);
      local_178 = DAT_001aa9dc;
      if ((int)*ppppppuVar51 < 0) {
        pppppuVar16 = param_2[0x24];
        (*(unsigned short *)((unsigned char *)&(local_178) + 2)) =
             (ushort)(((uint)(byte)((((uint)pppppuVar16 & 0xc0) == 0) << 1) << 0x14) >> 0x15);
        local_178 = (uint ******)
                    CONCAT13(((uint)pppppuVar16 & 3) == 0,
                             CONCAT12(((uint)pppppuVar16 & 0xc) == 0,(*(unsigned short *)((unsigned char *)&(local_178) + 2))));
        (*(unsigned short *)((unsigned char *)&(local_178) + 2)) = CONCAT11(((uint)pppppuVar16 & 0x30) == 0,(undefined1)local_178);
      }
      iVar45 = (int)*(short *)((int)*param_2[0x19] + 2);
      uVar48 = FUN_000ec208(param_1,(uint)**param_2[0x19] >> 0x10 & 0x3f);
      if (iVar36 == 0) {
        *(int *)(*(int *)(param_1 + 0x3ac) + 0x44) = iVar45;
      }
      else if (iVar36 == 1) {
        *(int *)(*(int *)(param_1 + 0x3ac) + 0x48) = iVar45;
      }
      iVar49 = *(int *)(param_1 + 1000);
      if (iVar45 <= *(int *)(param_1 + 1000)) {
        iVar49 = iVar45;
      }
      iVar20 = *(int *)(param_1 + 0x3ec);
      *(int *)(param_1 + 1000) = iVar49;
      if (iVar20 <= iVar45) {
        iVar20 = iVar45 + 1;
      }
      *(int *)(param_1 + 0x3ec) = iVar20;
      *(undefined4 *)(param_1 + 0x3f4) = 0x24;
      in_r6 = (uint ******)0x0;
      piVar18 = (int *)FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),uVar48,iVar45,0);
      uVar48 = (**(code **)(*piVar18 + 0x2c))();
      local_70 = &local_178;
      iVar45 = 0;
      do {
        if (*(char *)(iVar45 + (int)local_70) == '\0') {
          in_r6 = ppppppuVar19;
          FUN_00104104(uVar48,iVar45,iVar36,ppppppuVar19);
        }
        bVar1 = iVar45 != 3;
        iVar45 = iVar45 + 1;
      } while (bVar1);
      goto switchD_000fdaf0_caseD_2;
    case 0x1c:
    case 0x1d:
    case 0x79:
      in_r6 = (uint ******)param_2[0x17];
      pppuVar44 = **param_2[0x19];
      sVar6 = *(short *)((int)*param_2[0x19] + 2);
      if ((int)in_r6 < 1) {
        in_r6 = (uint ******)0x0;
      }
      else {
        puVar13 = &local_124;
        ppppppuVar19 = param_2 + (int)param_2[0x16] + 0x23;
        ppppppuVar51 = in_r6;
        do {
          pppppuVar16 = *ppppppuVar19;
          ppppppuVar19 = ppppppuVar19 + 1;
          *puVar13 = (uint)pppppuVar16;
          puVar13 = puVar13 + 1;
          ppppppuVar51 = (uint ******)((int)ppppppuVar51 - 1);
        } while (ppppppuVar51 != (uint ******)0x0);
      }
      in_r7 = (uint ******)&local_124;
      ((int (*)())FUN_000fafa4)(param_1,(uint)pppuVar44 >> 0x10 & 0x3f,(int)sVar6,in_r6,in_r7);
      goto switchD_000fdaf0_caseD_2;
    case 0x42:
      uVar48 = *(undefined4 *)(iVar45 + 0x374);
      puVar15 = (undefined4 *)FUN_00193e18(uVar48,0x168);
      *puVar15 = uVar48;
      piVar18 = puVar15 + 1;
      FUN_0010502c(piVar18,0x94,*(undefined4 *)(param_1 + 8));
      uVar48 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x2f,0,0);
      FUN_001046c8(piVar18,0,uVar48);
      puVar15[0x4c] = 0;
      ((int (*)())FUN_000f92fc)(param_1,piVar18,local_180);
      bVar1 = local_ac != 0;
      if (bVar1) {
        (**(code **)(*piVar18 + 0x90))(piVar18,uVar48);
      }
      pppppuVar16 = *ppppppuVar51;
      in_r6 = (uint ******)((uint)pppppuVar16 >> 0x17 & 0x3f);
      if (&MACH_HEADER.cputype < in_r6) {
        in_r6 = (uint ******)0x0;
      }
      ppppuVar47 = *param_2[0x1b];
      sVar6 = *(short *)((int)ppppuVar47 + 2);
      uVar52 = FUN_000ec208(param_1,(uint)*ppppuVar47 >> 0x10 & 0x3f);
      pppuVar44 = *param_2[0x1b][1];
      if (((((uint)pppuVar44 & 0x3f0000) == 0x100000) && (*(int *)(param_1 + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar36 = 0xf;
      }
      else {
        iVar36 = (int)*(short *)((int)param_2[0x1b][1] + 2);
      }
      uVar27 = FUN_000ec208(param_1,(uint)pppuVar44 >> 0x10 & 0x3f);
      uVar28 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x2b,0,0);
      piVar18 = (int *)FUN_001043f0(0x14,*(undefined4 *)(param_1 + 8));
      iVar45 = FUN_001054ec(piVar18,1);
      *(undefined4 *)(iVar45 + 0xc) = uVar52;
      local_178 = DAT_001aa9a8;
      *(int *)(iVar45 + 8) = (int)sVar6;
      ((int (*)())FUN_000f8aa0)(param_1,&local_178,ppppuVar47,1,piVar18);
      uVar52 = DAT_001aa9cc;
      iVar45 = FUN_001054ec(piVar18,1);
      *(undefined4 *)(iVar45 + 0x10) = uVar52;
      dVar56 = (double)FLOAT_001aa0d4;
      ((void (*)())FUN_000f79c4)(piVar18,param_1,2,dVar56,(double)FLOAT_001aa0e8,dVar56,dVar56);
      local_8c = (uint)(short)((ushort)((uint)pppppuVar16 >> 0x10) & 0x3f);
      local_80 = local_8c | 0x120000;
      in_r8 = (uint ******)(local_8c | 0x100000);
      in_r7 = (uint ******)(local_8c | 0x110000);
      local_8c = local_8c | 0xf0000;
      local_88 = (uint *****)in_r8;
      local_84 = (uint *****)in_r7;
      ((int (*)())FUN_000f771c)(piVar18,param_1,3,local_80,in_r7,in_r8,local_8c);
      iVar45 = FUN_001054ec(piVar18,0);
      *(undefined4 *)(iVar45 + 0xc) = 0x2b;
      *(undefined4 *)(iVar45 + 8) = 0;
      ((int (*)())FUN_000f92fc)(param_1,piVar18,local_180);
      (**(code **)(*piVar18 + 0x90))(piVar18,uVar48);
      if (bVar1) {
        (**(code **)(*piVar18 + 0x90))(piVar18,uVar28);
      }
      FUN_0010469c(piVar18,param_1,0x2b,0);
      piVar18[0x20] = 1;
      piVar18 = (int *)FUN_001084b8(0x31,*(undefined4 *)(param_1 + 8));
      iVar45 = FUN_001054ec(piVar18,0);
      *(uint *******)(iVar45 + 8) = in_r6;
      *(undefined4 *)(iVar45 + 0xc) = 0x2c;
      iVar45 = FUN_001054ec(piVar18,1);
      *(undefined4 *)(iVar45 + 0xc) = uVar27;
      *(int *)(iVar45 + 8) = iVar36;
      (**(code **)(*piVar18 + 0x90))(piVar18,uVar28);
      ((int (*)())FUN_000f92fc)(param_1,piVar18,local_180);
      FUN_0010469c(piVar18,param_1,0x2c,in_r6);
      local_ac = 1;
      goto switchD_000fdaf0_caseD_2;
    case 0x43:
      pppppuVar16 = *ppppppuVar51;
      in_r6 = (uint ******)*param_2[0x19];
      in_r7 = UNK_001aa9c8;
      if (((uint)*in_r6 & 0x400000) != 0) {
        in_r7 = *(uint *******)(local_5c + -0x2bf8);
        iVar36 = FUN_0019e990(in_r6,0);
        if (*(int *)(PTR_DAT_001e8bc8 + iVar36 * 4) == 0) {
          in_r7 = (uint ******)((uint)in_r7 & 0xffffff | 0x4000000);
        }
        uVar11 = (uint)(*(int *)(PTR_DAT_001e8bc8 + iVar36 * 4) == 0);
        iVar36 = FUN_0019e990(in_r6,1);
        puVar8 = PTR_DAT_001e8bc8;
        if (*(int *)(PTR_DAT_001e8bc8 + iVar36 * 4) == 0) {
          iVar36 = uVar11 + 4;
          uVar11 = uVar11 + 1;
          in_r7 = (uint ******)(iVar36 * 0x10000 | (uint)in_r7 & 0xff00ffff);
        }
        iVar36 = FUN_0019e990(in_r6,2);
        if (*(int *)(puVar8 + iVar36 * 4) == 0) {
          iVar36 = uVar11 + 4;
          uVar11 = uVar11 + 1;
          in_r7 = (uint ******)(iVar36 * 0x100 | (uint)in_r7 & 0xffff00ff);
        }
        iVar36 = FUN_0019e990(in_r6,3);
        if (*(int *)(puVar8 + iVar36 * 4) == 0) {
          iVar45 = *(int *)(param_1 + 8);
          in_r7 = (uint ******)(uVar11 + 4 | (uint)in_r7 & 0xffffff00);
        }
        else {
          iVar45 = *(int *)(param_1 + 8);
        }
      }
      in_r8 = (uint ******)local_180;
      (**(code **)(**(int **)(iVar45 + 0x30c) + 0x4c))
                (*(int **)(iVar45 + 0x30c),param_1,(uint)pppppuVar16 >> 0x10 & 0x3f);
      goto switchD_000fdaf0_caseD_2;
    case 0x6e:
      uVar48 = *(undefined4 *)(iVar45 + 0x374);
      pppppuVar16 = param_2[(int)param_2[0x16] + 0x23];
      puVar15 = (undefined4 *)FUN_00193e18(uVar48,0x134);
      *puVar15 = uVar48;
      pppppuVar54 = (uint *****)(puVar15 + 1);
      FUN_000ea148(pppppuVar54,*(undefined4 *)(param_1 + 8));
      puVar15[0x4c] = pppppuVar16;
      puVar15[1] = PTR_DAT_001e8bd0 + 8;
      local_180 = pppppuVar54;
      FUN_000ec3ac(param_1,local_184,pppppuVar54);
      FUN_000e8e4c(local_184,local_180);
      local_184 = local_180;
      uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar15 = (undefined4 *)FUN_00193e18(uVar48,0x130);
      *puVar15 = uVar48;
      ppppppuVar51 = (uint ******)(puVar15 + 1);
      FUN_000ea020(ppppppuVar51,*(undefined4 *)(param_1 + 8));
      local_180 = (uint *****)ppppppuVar51;
      FUN_000ec3ac(param_1,local_184,ppppppuVar51);
      FUN_000e8e4c(local_184,local_180);
      local_184 = local_180;
      goto switchD_000fdaf0_caseD_2;
    case 0x72:
      piVar18 = (int *)FUN_00193e18(*(undefined4 *)(iVar45 + 0x378),0xc);
      piVar18[1] = 0;
      piVar18[2] = 0;
      ppppppuVar19 = (uint ******)FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      iVar45 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar45;
      *piVar18 = iVar45;
      iVar36 = FUN_001054ec(ppppppuVar19,0);
      *(undefined4 *)(iVar36 + 0xc) = 0;
      *(int *)(iVar36 + 8) = iVar45;
      local_178 = DAT_001aa9a8;
      in_r8 = (uint ******)&local_174;
      ((int (*)())FUN_000fb3d4)(param_1,local_68,ppppppuVar51,*param_2[0x1b],ppppppuVar39,in_r8,&local_13c);
      pppuVar44 = **param_2[0x1b];
      if (((((uint)pppuVar44 & 0x3f0000) == 0x100000) && (*(int *)(param_1 + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar36 = 0xf;
      }
      else {
        iVar36 = (int)*(short *)((int)*param_2[0x1b] + 2);
      }
      uVar48 = FUN_000ec208(param_1,(uint)pppuVar44 >> 0x10 & 0x3f);
      iVar45 = FUN_001054ec(ppppppuVar19,1);
      *(undefined4 *)(iVar45 + 0xc) = uVar48;
      *(int *)(iVar45 + 8) = iVar36;
      in_r6 = (uint ******)((int)&MACH_HEADER.magic + 1);
      in_r7 = ppppppuVar19;
      ((int (*)())FUN_000f8aa0)(param_1,&local_178,*param_2[0x1b],1,ppppppuVar19);
      iVar45 = *(int *)(local_14c + 8);
      iVar36 = local_14c;
      while (iVar49 = iVar45, iVar49 != 0) {
        FUN_0019401c(iVar36);
        ((int (*)())FUN_000f92fc)(param_1,iVar36,local_180);
        iVar36 = iVar49;
        iVar45 = *(int *)(iVar49 + 8);
      }
      ((int (*)())FUN_000f92fc)(param_1,ppppppuVar19,local_180);
      uVar11 = local_b0[1];
      if (uVar11 < *local_b0) {
        _memset((void *)(uVar11 * 4 + local_b0[2]),0,4);
        local_b0[1] = uVar11 + 1;
        piVar38 = (int *)(uVar11 * 4 + local_b0[2]);
      }
      else {
        piVar38 = (int *)FUN_0019423c(local_b0,uVar11);
      }
      goto code_r0x000febe0;
    case 0x73:
      uVar48 = *(undefined4 *)(iVar45 + 0x374);
      puVar15 = (undefined4 *)FUN_00193e18(uVar48,0x168);
      *puVar15 = uVar48;
      piVar18 = puVar15 + 1;
      FUN_0010502c(piVar18,0xf8,*(undefined4 *)(param_1 + 8));
      puVar15[0x4c] = param_2[(int)param_2[0x16] + 0x23];
      ((int (*)())FUN_000f92fc)(param_1,piVar18,local_180);
      break;
    case 0x76:
    case 0x77:
      if ((iVar36 == 0x76) && ((int)*ppppppuVar51 < 0)) {
        pppppuVar54 = param_2[10];
        in_r6 = (uint ******)0x0;
        pppppuVar16 = param_2[(int)param_2[0x16] + 0x23];
        uVar48 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x43,0xffffffff,0);
        iVar36 = FUN_00109b74(0x10a,*(undefined4 *)(param_1 + 8));
        *(int *)(param_1 + 0x354) = iVar36;
        FUN_001046c8(iVar36,0,uVar48);
        *(uint ******)(iVar36 + 300) = pppppuVar54 + (int)pppppuVar16;
        FUN_000e7688(*(undefined4 *)(param_1 + 0x3a0),iVar36);
      }
      else {
        iVar36 = 1;
        ppppuVar47 = *param_2[0x1b];
        uVar46 = (uint)*(ushort *)((int)ppppuVar47 + 2);
        uVar11 = (uint)*ppppuVar47 >> 0x10 & 0x3f;
        if ((int)*ppppuVar47 < 0) {
          iVar36 = 2;
          uVar46 = uVar46 | (int)ppppuVar47[1] << 0x10;
        }
        pppuVar44 = ppppuVar47[iVar36];
        if (uVar11 == 0x1c) {
          puVar13 = *(uint **)(param_1 + 0x90);
          if (puVar13 == (uint *)0x0) {
            uVar48 = *(undefined4 *)(iVar45 + 0x374);
            puVar15 = (undefined4 *)FUN_00193e18(uVar48,0x14);
            puVar13 = puVar15 + 1;
            *puVar15 = uVar48;
            puVar15[1] = 2;
            puVar15[2] = 0;
            puVar15[4] = uVar48;
            uVar48 = FUN_00193e18(uVar48,8);
            puVar15[3] = uVar48;
            *(uint **)(param_1 + 0x90) = puVar13;
          }
        }
        else {
          puVar13 = *(uint **)(param_1 + 0x8c);
          if (puVar13 == (uint *)0x0) {
            uVar48 = *(undefined4 *)(iVar45 + 0x374);
            puVar15 = (undefined4 *)FUN_00193e18(uVar48,0x14);
            puVar13 = puVar15 + 1;
            *puVar15 = uVar48;
            puVar15[1] = 2;
            puVar15[2] = 0;
            puVar15[4] = uVar48;
            uVar48 = FUN_00193e18(uVar48,8);
            puVar15[3] = uVar48;
            *(uint **)(param_1 + 0x8c) = puVar13;
          }
        }
        if (uVar46 < *puVar13) {
          uVar17 = puVar13[1];
          if (uVar17 <= uVar46) {
            _memset((void *)(uVar17 * 4 + puVar13[2]),0,(uVar46 - uVar17) * 4 + 4);
            puVar13[1] = uVar46 + 1;
          }
          puVar13 = (uint *)(uVar46 * 4 + puVar13[2]);
        }
        else {
          puVar13 = (uint *)FUN_0019423c(puVar13,uVar46);
        }
        *puVar13 = (uint)pppuVar44;
        iVar36 = (uVar46 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x434);
        *(uint *)(iVar36 + 8) = 1 << (uVar46 & 0x1f) | *(uint *)(iVar36 + 8);
        if ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 8) != 0) {
          uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
          puVar15 = (undefined4 *)FUN_00193e18(uVar48,0x168);
          *puVar15 = uVar48;
          puVar24 = puVar15 + 1;
          FUN_00109a80(puVar24,0xfa,*(undefined4 *)(param_1 + 8));
          uVar48 = FUN_000ec208(param_1,uVar11);
          iVar36 = FUN_001054ec(puVar24,0);
          *(undefined4 *)(iVar36 + 0xc) = uVar48;
          *(uint *)(iVar36 + 8) = uVar46;
          puVar15[0x4c] = pppuVar44;
          ((int (*)())FUN_000f92fc)(param_1,puVar24,*(undefined4 *)(param_1 + 0x3a0));
        }
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x78:
      *(uint *)(param_1 + 0x400) = (uint)*ppppppuVar51 >> 0x10 & 0x3fff;
      goto switchD_000fdaf0_caseD_2;
    case 0x7a:
      *(uint *)(param_1 + 0x3f8) = (uint)*ppppppuVar51 >> 0x10 & 0x3fff;
      goto switchD_000fdaf0_caseD_2;
    case 0x7c:
      *(uint *)(param_1 + 0x3fc) = (uint)*ppppppuVar51 >> 0x10 & 0x3fff;
      goto switchD_000fdaf0_caseD_2;
    case 0x7d:
      ppppuVar47 = *param_2[0x19];
      if ((*(uint *)(param_1 + 0x30) & 0x4000) == 0) {
        if ((*(uint *)(param_1 + 0x30) & 1) != 0) {
          local_178 = DAT_001aa9dc;
          ppppppuVar19 = (uint ******)(int)*(short *)((int)ppppuVar47 + 2);
          uVar48 = FUN_000ec208(param_1,(uint)*ppppuVar47 >> 0x10 & 0x3f);
          iVar36 = FUN_000ec27c(param_1,(uint)*ppppppuVar51 >> 0x10 & 0x3fff);
          if (iVar36 == 0) {
            *(uint *******)(*(int *)(param_1 + 0x3ac) + 0x44) = ppppppuVar19;
          }
          else if (iVar36 == 1) {
            *(uint *******)(*(int *)(param_1 + 0x3ac) + 0x48) = ppppppuVar19;
          }
          ppppppuVar51 = *(uint *******)(param_1 + 1000);
          if ((int)ppppppuVar19 <= (int)*(uint *******)(param_1 + 1000)) {
            ppppppuVar51 = ppppppuVar19;
          }
          puVar55 = *(undefined1 **)(param_1 + 0x3ec);
          *(uint *******)(param_1 + 1000) = ppppppuVar51;
          if ((int)puVar55 <= (int)ppppppuVar19) {
            puVar55 = (undefined1 *)((int)ppppppuVar19 + 1);
          }
          *(undefined1 **)(param_1 + 0x3ec) = puVar55;
          *(undefined4 *)(param_1 + 0x3f4) = 0x24;
          if (iVar36 == 0xd) {
            iVar45 = *(int *)(param_1 + 0x3ac);
            if (*(int *)(iVar45 + 0x4c) == -1) {
              *(uint *******)(iVar45 + 0x4c) = ppppppuVar19;
            }
            else {
              *(uint *******)(iVar45 + 0x54) = ppppppuVar19;
            }
          }
          else if (iVar36 == 0xe) {
            iVar45 = *(int *)(param_1 + 0x3ac);
            if (*(int *)(iVar45 + 0x50) == -1) {
              *(uint *******)(iVar45 + 0x50) = ppppppuVar19;
            }
            else {
              *(uint *******)(iVar45 + 0x58) = ppppppuVar19;
            }
          }
          else if (iVar36 == 0xb) {
            *(uint *******)(*(int *)(param_1 + 0x3ac) + 0x5c) = ppppppuVar19;
          }
          else if (iVar36 == 0xc) {
            *(uint *******)(*(int *)(param_1 + 0x3ac) + 0x60) = ppppppuVar19;
          }
          else if (iVar36 == 0xf) {
            *(uint *******)(*(int *)(param_1 + 0x3ac) + 100) = ppppppuVar19;
          }
          in_r6 = (uint ******)0x0;
          piVar18 = (int *)FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),uVar48,ppppppuVar19,0);
          iVar45 = (**(code **)(*piVar18 + 0x2c))();
          local_70 = &local_178;
          *(uint *******)(iVar45 + 0x140) = ppppppuVar19;
          iVar49 = 0;
          do {
            if (*(char *)(iVar49 + (int)local_70) == '\0') {
              in_r6 = ppppppuVar19;
              FUN_00104104(iVar45,iVar49,iVar36,ppppppuVar19);
            }
            bVar1 = iVar49 != 3;
            iVar49 = iVar49 + 1;
          } while (bVar1);
        }
      }
      else {
        in_r6 = (uint ******)(uint)*(ushort *)((int)ppppuVar47 + 2);
        in_r8 = (uint ******)0x0;
        in_r7 = DAT_001aa9a8;
        (**(code **)(*piVar18 + 0x54))(piVar18,in_r6,(uint)*ppppppuVar51 >> 0x10 & 0x3fff);
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x7e:
      uVar46 = (uint)*ppppppuVar51 >> 0xe & 0x1f;
      ppppppuVar19 = (uint ******)FUN_000ec27c(param_1,uVar46);
      uVar11 = (uint)*ppppppuVar51 >> 0x13 & 7;
      if (uVar11 == 3) {
        bVar1 = true;
        bVar3 = false;
        bVar2 = false;
      }
      else if (uVar11 < 4) {
        if (uVar11 == 1) {
          bVar1 = false;
          bVar3 = false;
          bVar2 = true;
        }
        else {
code_r0x000feeb8:
          bVar1 = false;
          bVar3 = false;
          bVar2 = false;
        }
      }
      else if (uVar11 == 4) {
        bVar1 = false;
        bVar3 = true;
        bVar2 = false;
      }
      else {
        if (uVar11 != 5) goto code_r0x000feeb8;
        bVar1 = true;
        bVar3 = true;
        bVar2 = false;
      }
      ppppppuVar51 = (uint ******)*param_2[0x19];
      pppppuVar16 = *ppppppuVar51;
      if (((uint)pppppuVar16 & 0x400000) == 0) {
        if (((uint)pppppuVar16 & 0x2000000) == 0) {
          ppppppuVar42 = (uint ******)0x0;
          ppppppuVar40 = (uint ******)0x0;
        }
        else {
          ppppppuVar42 = ppppppuVar51 + 1;
          ppppppuVar40 = (uint ******)0x0;
        }
      }
      else {
        ppppppuVar40 = ppppppuVar51 + 1;
        ppppppuVar42 = (uint ******)0x0;
        if (((uint)pppppuVar16 & 0x2000000) != 0) {
          ppppppuVar42 = ppppppuVar51 + 2;
        }
      }
      if (((*(uint *)(param_1 + 0x30) & 1) == 0) && ((*(uint *)(param_1 + 0x30) & 0x2000) == 0)) {
        if (uVar46 == 10) {
          local_174 = (uint ****)(uint)*(ushort *)((int)ppppppuVar42 + 2);
          local_178 = (uint ******)DAT_001aa9d0;
          puVar13 = &local_178;
          if (((uint)*ppppppuVar40 & 3) == 1) {
            puVar13 = (uint *)&DAT_001aa9d0;
          }
          puVar37 = &local_178;
          local_178 = (uint ******)*puVar13;
          if (((uint)*ppppppuVar40 & 0xc) == 4) {
            puVar37 = &UNK_001aa9c4;
          }
          puVar13 = &local_178;
          local_178 = (uint ******)*puVar37;
          if (((uint)*ppppppuVar40 & 0x30) == 0x10) {
            puVar13 = &UNK_001aa9c0;
          }
          puVar37 = &local_178;
          local_178 = (uint ******)*puVar13;
          if (((uint)*ppppppuVar40 & 0xc0) == 0x40) {
            puVar37 = (uint *)&UNK_001aa9bc;
          }
          local_178 = (uint ******)*puVar37;
          local_170 = (uint *****)local_178;
        }
      }
      else {
        uVar11 = (uint)pppppuVar16 >> 0x10 & 0x3f;
        ppppppuVar50 = (uint ******)(uint)*(ushort *)((int)ppppppuVar51 + 2);
        uVar48 = FUN_000ec208(param_1,uVar11);
        puVar13 = local_13c;
        ppppppuVar40 = *(uint *******)(param_1 + 1000);
        if ((int)ppppppuVar50 <= (int)*(uint *******)(param_1 + 1000)) {
          ppppppuVar40 = ppppppuVar50;
        }
        puVar55 = *(undefined1 **)(param_1 + 0x3ec);
        *(uint *******)(param_1 + 1000) = ppppppuVar40;
        if ((int)puVar55 <= (int)ppppppuVar50) {
          puVar55 = (undefined1 *)((int)ppppppuVar50 + 1);
        }
        *(undefined1 **)(param_1 + 0x3ec) = puVar55;
        *(undefined4 *)(param_1 + 0x3f4) = 0x24;
        if ((*(uint *)(param_1 + 0x30) & 1) == 0) {
          iVar36 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),uVar48,ppppppuVar50,0);
          iVar36 = *(int *)(iVar36 + 0x38);
          if (!bVar1) {
            *(uint *)(iVar36 + 0x13c) = *(uint *)(iVar36 + 0x13c) | 1;
          }
          if (bVar3) {
            *(uint *)(iVar36 + 0x13c) = *(uint *)(iVar36 + 0x13c) | 4;
          }
          if (bVar2) {
            *(uint *)(iVar36 + 0x13c) = *(uint *)(iVar36 + 0x13c) | 2;
          }
          iVar45 = 0;
          do {
            in_r6 = ppppppuVar19;
            in_r7 = ppppppuVar50;
            FUN_001041d0(iVar36,iVar45,1,ppppppuVar19,ppppppuVar50);
            bVar1 = iVar45 != 3;
            iVar45 = iVar45 + 1;
          } while (bVar1);
        }
        else {
          in_r7 = UNK_001aa9c8;
          if ((*(uint *)(param_1 + 0x30) & 0x40000) == 0) {
            in_r8 = *(uint *******)(param_1 + 0x3a0);
            piVar18 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
            (**(code **)(*piVar18 + 0x4c))(piVar18,param_1,ppppppuVar50);
            in_r6 = ppppppuVar51;
          }
          else if (uVar11 != 9) {
            uVar11 = (uint)*(ushort *)((int)ppppppuVar42 + 2);
            if (uVar11 < *local_13c) {
              uVar46 = local_13c[1];
              if (uVar46 <= uVar11) {
                _memset((void *)(uVar46 * 4 + local_13c[2]),0,(uVar11 - uVar46) * 4 + 4);
                puVar13[1] = uVar11 + 1;
              }
              puVar13 = (uint *)(uVar11 * 4 + puVar13[2]);
            }
            else {
              puVar13 = (uint *)FUN_0019423c(local_13c,uVar11);
            }
            ppppppuVar51 = (uint ******)*puVar13;
            in_r6 = (uint ******)0x0;
            iVar36 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
            *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar36;
            uVar48 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0,iVar36,0);
            FUN_001046c8(ppppppuVar51,0,uVar48);
            goto code_r0x000ff070;
          }
        }
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x80:
      bVar4 = *(byte *)((int)param_2 + 0x8d);
      uVar11 = (uint)*ppppppuVar51 >> 0x18 & 0xf;
      if (piVar18[0x14] < (int)(uint)bVar4) {
        FUN_000e1534(iVar45,7);
      }
      uVar46 = bVar4 >> 3 & 0x1c;
      iVar36 = (uint)bVar4 * 0xc;
      *(uint *)((int)local_a0 + uVar46 + 8) =
           1 << (bVar4 & 0x1f) | *(uint *)((int)local_a0 + uVar46 + 8);
      *(undefined4 *)(*(int *)(param_1 + 0x78) + iVar36) = 1;
      if (uVar11 != 0) {
        *(uint *)(iVar36 + *(int *)(param_1 + 0x78) + 4) = uVar11;
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x81:
    case 0x84:
    case 0x85:
      local_a4 = (uint *****)((int)local_a4 + 1);
      if ((*(uint *)(param_1 + 0x30) & 0x40000) == 0) {
        if (puVar14[2] != 0) {
          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x180000;
        }
        if ((uint *****)local_a8[1] != (uint *****)0x0) {
          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x80000;
        }
        iVar36 = FUN_001043f0(*(undefined4 *)
                               (iVar36 * 0x24 + *(int *)(*(int *)(iVar45 + 0x30c) + 0xc)),iVar45);
        iVar45 = FUN_001054ec(iVar36,0);
        pppppuVar16 = DAT_001aa9d0;
        *(undefined4 *)(iVar45 + 0xc) = 0x2c;
        *(undefined4 *)(iVar45 + 8) = 0;
        *(uint ******)(iVar36 + 0x9c) = pppppuVar16;
        iVar45 = FUN_001054ec(iVar36,1);
        *(undefined4 *)(iVar45 + 0xc) = 0x2c;
        *(undefined4 *)(iVar45 + 8) = 0;
        uVar48 = DAT_001aa9cc;
        iVar45 = FUN_001054ec(iVar36,1);
        *(undefined4 *)(iVar45 + 0x10) = uVar48;
        ((int (*)())FUN_000f92fc)(param_1,iVar36,local_180);
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x87:
      uVar11 = (uint)*(byte *)((int)param_2 + 0x8d);
      pppppuVar16 = *ppppppuVar51;
      if (*(int *)(param_1 + 0x7c) < (int)uVar11) {
        *(uint *)(param_1 + 0x7c) = uVar11;
      }
      ppppppuVar51 = DAT_001aa9a8;
      *(uint *)(param_1 + 0x84) = 1 << (uVar11 & 0x3f) | *(uint *)(param_1 + 0x84);
      ppppppuVar19 = DAT_001aa9dc;
      local_178 = ppppppuVar51;
      uVar48 = *(undefined4 *)(param_1 + 0x3ac);
      iVar36 = *(int *)(iVar45 + 0x3ac) + -1;
      *(int *)(iVar45 + 0x3ac) = iVar36;
      uVar48 = FUN_00127608(uVar48,0,iVar36,0);
      uVar52 = *(undefined4 *)(param_1 + 0x3ac);
      iVar36 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar36;
      uVar52 = FUN_00127608(uVar52,0,iVar36,0);
      uVar27 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      FUN_001046c8(uVar27,0,uVar52);
      local_70 = &local_178;
      ((int (*)())FUN_000fa958)(param_1,5,1,param_2,uVar27,1,ppppppuVar19,local_70);
      ((int (*)())FUN_000f92fc)(param_1,uVar27,local_180);
      iVar36 = FUN_001043f0(0x109,*(undefined4 *)(param_1 + 8));
      *(uint *)(iVar36 + 0x134) = uVar11;
      FUN_001046c8(iVar36,0,uVar48);
      FUN_001046c8(iVar36,1,uVar52);
      ((int (*)())FUN_000f92fc)(param_1,iVar36,local_180);
      puVar9 = PTR_DAT_001e8b8c;
      puVar8 = PTR_DAT_001e8b64;
      local_178 = ppppppuVar51;
      if (((uint)pppppuVar16 & 0x1f000000) != 0x1000000) {
        iVar36 = 0;
        do {
          iVar45 = FUN_001043f0(0xe1,*(undefined4 *)(param_1 + 8));
          FUN_001046c8(iVar45,0,uVar48);
          FUN_001046c8(iVar45,1,uVar48);
          uVar52 = *(undefined4 *)(puVar9 + iVar36);
          *(undefined4 *)(iVar45 + 0x9c) = *(undefined4 *)(puVar8 + iVar36);
          iVar49 = FUN_001054ec(iVar45,1);
          *(undefined4 *)(iVar49 + 0x10) = uVar52;
          ((int (*)())FUN_000f92fc)(param_1,iVar45,local_180);
          bVar1 = iVar36 != 0xc;
          iVar36 = iVar36 + 4;
        } while (bVar1);
      }
      ppppppuVar51 = (uint ******)FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      in_r8 = (uint ******)((int)&MACH_HEADER.magic + 1);
      in_r6 = param_2;
      in_r7 = ppppppuVar51;
      ((int (*)())FUN_000fa958)(param_1,0,0,param_2,ppppppuVar51,1,ppppppuVar19,local_70);
      FUN_001046c8(ppppppuVar51,1,uVar48);
code_r0x000ff070:
      ((int (*)())FUN_000f92fc)(param_1,ppppppuVar51,local_180);
      goto switchD_000fdaf0_caseD_2;
    case 0xbe:
      uVar48 = *(undefined4 *)(iVar45 + 0x374);
      puVar15 = (undefined4 *)FUN_00193e18(uVar48,0x168);
      *puVar15 = uVar48;
      ppppppuVar19 = (uint ******)(puVar15 + 1);
      FUN_0010502c(ppppppuVar19,0xb4,*(undefined4 *)(param_1 + 8));
      if (((uint)*ppppppuVar51 & 0x3fff0000) != 0) {
        puVar15[0x4c] = 1;
      }
      in_r8 = (uint ******)&local_174;
      ((int (*)())FUN_000fb3d4)(param_1,local_68,ppppppuVar51,*param_2[0x1b],ppppppuVar39,in_r8,&local_13c);
      pppuVar44 = **param_2[0x1b];
      if (((((uint)pppuVar44 & 0x3f0000) == 0x100000) && (*(int *)(param_1 + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar36 = 0xf;
      }
      else {
        iVar36 = (int)*(short *)((int)*param_2[0x1b] + 2);
      }
      uVar11 = (uint)pppuVar44 >> 0x10 & 0x3f;
      iVar45 = FUN_00127534(*(undefined4 *)(param_1 + 0x3ac),0x2c,0,0);
      if (iVar45 == 0) {
        uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar15 = (undefined4 *)FUN_00193e18(uVar48,0x168);
        *puVar15 = uVar48;
        puVar24 = puVar15 + 1;
        FUN_00108918(puVar24,*(undefined4 *)(param_1 + 8));
        ppppppuVar51 = DAT_001aa9dc;
        puVar15[6] = puVar15[6] | 0x10000;
        *(undefined4 **)(param_1 + 0x350) = puVar24;
        puVar15[0x28] = ppppppuVar51;
        iVar45 = FUN_001275a0(*(undefined4 *)(param_1 + 0x3ac),0x2c,0,0);
        FUN_001046c8(puVar24,0,iVar45);
        FUN_001046c8(puVar24,1,iVar45);
        ppppppuVar51 = DAT_001aa9a8;
        iVar49 = FUN_001054ec(puVar24,1);
        *(uint *******)(iVar49 + 0x10) = ppppppuVar51;
        FUN_000e7688(*(undefined4 *)(param_1 + 0x3a8),puVar24);
        FUN_0012306c(iVar45,puVar24);
        FUN_001236e4(iVar45,1,puVar24);
      }
      FUN_001046c8(ppppppuVar19,0,iVar45);
      uVar48 = FUN_000ec208(param_1,uVar11);
      iVar45 = FUN_001054ec(ppppppuVar19,1);
      *(undefined4 *)(iVar45 + 0xc) = uVar48;
      *(int *)(iVar45 + 8) = iVar36;
      uVar48 = FUN_000ec208(param_1,uVar11);
      iVar45 = FUN_001054ec(ppppppuVar19,2);
      *(undefined4 *)(iVar45 + 0xc) = uVar48;
      *(int *)(iVar45 + 8) = iVar36;
      uVar48 = FUN_000ec208(param_1,uVar11);
      iVar45 = FUN_001054ec(ppppppuVar19,3);
      *(undefined4 *)(iVar45 + 0xc) = uVar48;
      ppppppuVar51 = DAT_001aa9a8;
      local_70 = &local_178;
      *(int *)(iVar45 + 8) = iVar36;
      (*(unsigned char *)((unsigned char *)&(local_178) + 1)) = (undefined1)((uint)ppppppuVar51 >> 0x10);
      uVar10 = (*(unsigned char *)((unsigned char *)&(local_178) + 1));
      (*(unsigned short *)((unsigned char *)&(local_178) + 0)) = (undefined2)((uint)ppppppuVar51 >> 0x10);
      (*(unsigned short *)((unsigned char *)&(local_178) + 2)) = CONCAT11(uVar10,uVar10);
      ((int (*)())FUN_000f8aa0)(param_1,local_70,*param_2[0x1b],1,ppppppuVar19);
      local_178 = (uint ******)UNK_001aa9d8;
      ((int (*)())FUN_000f8aa0)(param_1,local_70,*param_2[0x1b],2,ppppppuVar19);
      in_r6 = (uint ******)((int)&MACH_HEADER.magic + 3);
      local_178 = UNK_001aa9d4;
      in_r7 = ppppppuVar19;
      ((int (*)())FUN_000f8aa0)(param_1,local_70,*param_2[0x1b],3,ppppppuVar19);
      iVar45 = *(int *)(local_14c + 8);
      iVar36 = local_14c;
      while (iVar49 = iVar45, iVar49 != 0) {
        FUN_0019401c(iVar36);
        ((int (*)())FUN_000f92fc)(param_1,iVar36,local_180);
        iVar36 = iVar49;
        iVar45 = *(int *)(iVar49 + 8);
      }
      ((int (*)())FUN_000f92fc)(param_1,ppppppuVar19,local_180);
      goto switchD_000fdaf0_caseD_2;
    case 0xe3:
      uVar48 = *(undefined4 *)(iVar45 + 0x374);
      puVar15 = (undefined4 *)FUN_00193e18(uVar48,0x168);
      *puVar15 = uVar48;
      piVar18 = puVar15 + 1;
      FUN_0010502c(piVar18,0x106,*(undefined4 *)(param_1 + 8));
      ((int (*)())FUN_000f92fc)(param_1,piVar18,local_180);
    }
    puVar13 = *(uint **)(param_1 + 0x414);
    uVar11 = puVar13[1];
    if (uVar11 < *puVar13) {
      _memset((void *)(uVar11 * 4 + puVar13[2]),0,4);
      piVar38 = (int *)(uVar11 * 4 + puVar13[2]);
      puVar13[1] = uVar11 + 1;
    }
    else {
      piVar38 = (int *)FUN_0019423c(puVar13,uVar11);
    }
code_r0x000febe0:
    *piVar38 = (int)piVar18;
    goto switchD_000fdaf0_caseD_2;
  default:
    goto switchD_000fdaf0_caseD_2;
  case 4:
    bVar1 = false;
    break;
  case 5:
    local_78 = &DAT_001ad5d8;
    local_60 = &DAT_001ad5d8;
    iVar49 = *(int *)(iVar36 * 0x24 + iVar49 + 0x18);
    local_124 = DAT_001aa9dc;
    local_178 = DAT_001aa9a8;
    uVar48 = *(undefined4 *)(iVar45 + 0x378);
    puVar15 = (undefined4 *)FUN_00193e18(uVar48,0x14);
    puVar13 = puVar15 + 1;
    *puVar15 = uVar48;
    puVar15[1] = 2;
    puVar15[2] = 0;
    puVar15[4] = uVar48;
    uVar48 = FUN_00193e18(uVar48,8);
    puVar15[3] = uVar48;
    uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
    puVar24 = (undefined4 *)FUN_00193e18(uVar48,0x14);
    ppppppuVar19 = (uint ******)(puVar24 + 1);
    *puVar24 = uVar48;
    puVar24[1] = 2;
    puVar24[2] = 0;
    puVar24[4] = uVar48;
    uVar48 = FUN_00193e18(uVar48,8);
    puVar24[3] = uVar48;
    local_17c = (int *)0x0;
    _memcpy(&local_104,&UNK_001aaa2c,0x24);
    iVar20 = *(int *)(param_1 + 8);
    ppppppuVar40 = (uint ******)0x0;
    uVar48 = *(undefined4 *)(*(int *)(iVar20 + 0x30c) + 0xc);
    local_c0 = (uint *****)((int (*)())FUN_000f8960)(iVar36,uVar48);
    iVar45 = ((int (*)())FUN_000f8970)(iVar36,uVar48);
    if (0 < (int)local_c0) {
      do {
        iVar21 = (int)ppppppuVar40 << 2;
        for (iVar22 = 0;
            iVar23 = ((int (*)())FUN_000f8980)(iVar36,ppppppuVar40,
                                  *(undefined4 *)(*(int *)(iVar20 + 0x30c) + 0xc)), iVar22 <= iVar23
            ; iVar22 = iVar22 + 1) {
          in_r6 = ppppppuVar39;
          in_r7 = (uint ******)local_a4;
          ((int (*)())FUN_000f9a58)(param_1,local_6c,*(undefined4 *)((int)param_2[0x19] + iVar21),ppppppuVar39,
                       local_a4);
          iVar20 = *(int *)(param_1 + 8);
          iVar21 = iVar21 + 0x14;
        }
        ppppppuVar40 = (uint ******)((int)ppppppuVar40 + 1);
      } while ((uint ******)local_c0 != ppppppuVar40);
    }
    iVar21 = 0;
    if (0 < iVar45) {
      do {
        iVar22 = iVar21 << 2;
        puVar55 = (undefined1 *)((int)local_c0 + iVar21);
        for (iVar23 = 0;
            iVar25 = ((int (*)())FUN_000f8980)(iVar36,puVar55,*(undefined4 *)(*(int *)(iVar20 + 0x30c) + 0xc)),
            iVar23 <= iVar25; iVar23 = iVar23 + 1) {
          in_r6 = *(uint *******)((int)param_2[0x1b] + iVar22);
          in_r8 = (uint ******)&local_174;
          in_r7 = ppppppuVar39;
          ((int (*)())FUN_000fb3d4)(param_1,local_68,ppppppuVar51,in_r6,ppppppuVar39,in_r8,&local_13c);
          iVar20 = *(int *)(param_1 + 8);
          iVar22 = iVar22 + 0x14;
        }
        iVar21 = iVar21 + 1;
      } while (iVar45 != iVar21);
    }
    iVar20 = *(int *)(local_14c + 8);
    iVar45 = local_14c;
    while (iVar21 = iVar20, iVar21 != 0) {
      FUN_0019401c(iVar45);
      ((int (*)())FUN_000f92fc)(param_1,iVar45,local_180);
      iVar45 = iVar21;
      iVar20 = *(int *)(iVar21 + 8);
    }
    local_b4 = 0;
    ppppppuVar40 = (uint ******)0x0;
    ppppppuVar42 = (uint ******)0x0;
code_r0x001005f4:
    ppppppuVar12 = (uint ******)local_180;
    ppppppuVar50 = (uint ******)PTR_DAT_001e8bd4;
    uVar11 = *(uint *)(iVar49 + (int)local_17c * 4);
    if (0x71 < uVar11) goto switchD_0010061c_caseD_0;
    switch(uVar11) {
    default:
      goto switchD_0010061c_caseD_0;
    case 1:
    case 0x13:
    case 0x33:
    case 0x39:
    case 0x3b:
    case 0x3c:
    case 0x3e:
    case 0x40:
    case 0x4c:
    case 0x5e:
      goto switchD_0010061c_caseD_1;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
    case 0x10:
    case 0x11:
      in_r6 = param_2;
      in_r7 = ppppppuVar40;
      in_r8 = (uint ******)local_c0;
      iVar45 = ((int (*)())FUN_000fa958)(param_1,uVar11 - 2,ppppppuVar42,param_2,ppppppuVar40,local_c0,local_124,
                            &local_178);
      if (iVar45 != 0) {
        FUN_00193f94(local_6c,iVar45);
      }
      goto code_r0x001025c0;
    case 0x12:
      FUN_00103d50(ppppppuVar40 + (int)ppppppuVar42 * 6 + 0x23,2,1);
      goto code_r0x00101d1c;
    case 0x14:
    case 0x15:
    case 0x16:
      uVar46 = (uint)*ppppppuVar51 >> 0x10 & 0x3fff;
      if (uVar11 == 0x14) {
        in_r7 = (uint ******)(PTR_DAT_001dc78c)[uVar46];
      }
      else if (uVar11 == 0x15) {
        in_r7 = (uint ******)(PTR_DAT_001dc77c)[uVar46];
      }
      else {
        in_r7 = (uint ******)(PTR_DAT_001dc76c)[uVar46];
      }
      goto code_r0x001022b4;
    case 0x17:
      iVar45 = FUN_000e47f4(param_2);
      if ((iVar45 == 0x3e) || (iVar45 = FUN_000e47f4(param_2), iVar45 == 0x71)) {
        uVar11 = puVar14[2];
        if (uVar11 != 0) {
          piVar18 = (int *)0x0;
          if (uVar11 - 1 < uVar11) {
            piVar18 = (int *)((uVar11 - 1) * 4 + puVar14[3]);
          }
          iVar45 = *piVar18;
          pppppuVar16 = (uint *****)local_a8[1];
          ppppppuVar50 = (uint ******)PTR_DAT_001e8bbc;
          if (pppppuVar16 != (uint *****)0x0) {
            pppppuVar54 = (uint *****)0x0;
            if ((uint *****)((int)pppppuVar16 - 1U) < pppppuVar16) {
              pppppuVar54 = (uint *****)(local_a8[2] + (int)((int)pppppuVar16 - 1U));
            }
            if ((int)local_188 <= (int)(*pppppuVar54)[0x2e]) {
              uVar48 = *(undefined4 *)(iVar45 + 0x154);
              uVar52 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
              puVar34 = (undefined4 *)FUN_00193e18(uVar52,0x138);
              *puVar34 = uVar52;
              ppppppuVar50 = (uint ******)(puVar34 + 1);
              in_r6 = *(uint *******)(param_1 + 8);
              FUN_000ec0c8(ppppppuVar50,iVar45,*(undefined4 *)(iVar45 + 300),in_r6);
              puVar34[0x2f] = local_188;
              FUN_000ec3ac(param_1,local_184,ppppppuVar50);
              FUN_000e8e4c(local_184,ppppppuVar50);
              FUN_000e8e4c(ppppppuVar50,uVar48);
              local_bc = 0;
              *(int *)(iVar45 + 0x138) = *(int *)(iVar45 + 0x138) + 1;
              local_184 = (uint *****)ppppppuVar50;
              break;
            }
          }
          goto code_r0x00103718;
        }
      }
      else {
        iVar45 = FUN_000e47f4(param_2);
        ppppppuVar50 = (uint ******)PTR_DAT_001e8bb4;
        if (iVar45 == 0x72) {
          piVar18 = (int *)0x0;
          uVar11 = local_b0[1] - 1;
          if (uVar11 < local_b0[1]) {
            piVar18 = (int *)(uVar11 * 4 + local_b0[2]);
          }
          *(int *)(*piVar18 + 4) = *(int *)(*piVar18 + 4) + 1;
code_r0x00103718:
          in_r6 = (uint ******)0x0;
          in_r8 = ppppppuVar19;
          iVar49 = ((int (*)())FUN_000fd50c)(param_1,iVar49,&local_17c,0,ppppppuVar50,ppppppuVar19);
          in_r7 = ppppppuVar50;
          goto code_r0x0010372c;
        }
      }
      goto switchD_0010061c_caseD_1;
    case 0x1f:
      local_17c = (int *)((int)local_17c + 1);
      uVar11 = *(uint *)(iVar49 + (int)local_17c * 4);
      local_178 = (uint ******)
                  (uVar11 << 0x18 | (uVar11 & 0xff00) << 8 | uVar11 >> 8 & 0xff00 | uVar11 >> 0x18);
      local_bc = 0;
      break;
    case 0x20:
      local_17c = (int *)((int)local_17c + 1);
      uVar11 = *(uint *)(iVar49 + (int)local_17c * 4);
      in_r7 = (uint ******)&local_124;
      local_124 = (uint ******)
                  (uVar11 << 0x18 | (uVar11 & 0xff00) << 8 | uVar11 >> 8 & 0xff00 | uVar11 >> 0x18);
      local_bc = 0;
      break;
    case 0x21:
      ppppppuVar50 = (uint ******)0x0;
      switch((uint)*ppppppuVar51 >> 0x10 & 7) {
      case 0:
        ppppppuVar50 = (uint ******)PTR_DAT_001e8b80;
        break;
      case 1:
        ppppppuVar50 = (uint ******)PTR_DAT_001e8bac;
        break;
      case 2:
        ppppppuVar50 = (uint ******)PTR_DAT_001e8ba8;
        break;
      case 3:
        ppppppuVar50 = (uint ******)PTR_DAT_001e8bcc;
        break;
      case 4:
        ppppppuVar50 = (uint ******)PTR_DAT_001e8b94;
        break;
      case 5:
        ppppppuVar50 = (uint ******)PTR_DAT_001e8b74;
      }
      goto switchD_00102044_default;
    case 0x22:
      uVar11 = (uint)*ppppppuVar51 >> 0x16 & 7;
      if (uVar11 == 0) goto switchD_0010061c_caseD_1;
      ppppppuVar50 = (uint ******)FUN_001043f0(0x12,*(undefined4 *)(param_1 + 8));
      if (local_100 == 0) {
        local_100 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = local_100;
      }
      iVar45 = local_100;
      iVar20 = FUN_001054ec(ppppppuVar50,0);
      *(int *)(iVar20 + 8) = iVar45;
      *(undefined4 *)(iVar20 + 0xc) = 0;
      pppuVar44 = **param_2[0x1b];
      if (((((uint)pppuVar44 & 0x3f0000) == 0x100000) && (*(int *)(param_1 + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar20 = 0xf;
      }
      else {
        iVar20 = (int)*(short *)((int)*param_2[0x1b] + 2);
      }
      uVar48 = FUN_000ec208(param_1,(uint)pppuVar44 >> 0x10 & 0x3f);
      iVar21 = FUN_001054ec(ppppppuVar50,1);
      *(undefined4 *)(iVar21 + 0xc) = uVar48;
      *(int *)(iVar21 + 8) = iVar20;
      in_r6 = ppppppuVar42;
      in_r7 = ppppppuVar50;
      ((int (*)())FUN_000f8aa0)(param_1,&local_178,*param_2[0x1b],ppppppuVar42,ppppppuVar50);
      fVar5 = FLOAT_001aa0e8;
      if (uVar11 == 2) {
code_r0x001021c0:
        dVar56 = (double)fVar5;
        ((void (*)())FUN_000f79c4)(ppppppuVar50,param_1,2,dVar56,dVar56,dVar56,dVar56);
        FUN_00103d50(ppppppuVar50 + 0x2f,1,1);
      }
      else if (uVar11 < 3) {
        fVar5 = FLOAT_001aa10c;
        if (uVar11 == 1) goto code_r0x001021c0;
      }
      else {
        fVar5 = FLOAT_001aa10c;
        if ((uVar11 == 3) || (fVar5 = FLOAT_001aa0e8, uVar11 == 4)) {
          dVar56 = (double)fVar5;
          ((void (*)())FUN_000f79c4)(ppppppuVar50,param_1,2,dVar56,dVar56,dVar56,dVar56);
        }
      }
      ((int (*)())FUN_000f92fc)(param_1,ppppppuVar50,local_180);
      iVar20 = FUN_001054ec(ppppppuVar40,ppppppuVar42);
      *(int *)(iVar20 + 8) = iVar45;
      *(undefined4 *)(iVar20 + 0xc) = 0;
      ppppppuVar42 = (uint ******)((int)ppppppuVar42 + 1);
      local_bc = 0;
      local_17c = (int *)((int)local_17c + 1);
      break;
    case 0x23:
      ppppppuVar50 = (uint ******)0x0;
      switch((uint)*ppppppuVar51 >> 0x10 & 7) {
      case 0:
        ppppppuVar50 = (uint ******)PTR_DAT_001e8bc0;
        break;
      case 1:
        ppppppuVar50 = (uint ******)PTR_DAT_001e8b7c;
        break;
      case 2:
        ppppppuVar50 = (uint ******)PTR_DAT_001e8ba4;
        break;
      case 3:
        ppppppuVar50 = (uint ******)PTR_DAT_001e8b90;
        break;
      case 4:
        ppppppuVar50 = (uint ******)PTR_DAT_001e8bc4;
        break;
      case 5:
        ppppppuVar50 = (uint ******)PTR_DAT_001e8ba0;
      }
      goto switchD_00102044_default;
    case 0x24:
      if (puVar14[2] != 0) {
        pppppuVar16 = (uint *****)local_a8[1];
        ppppppuVar50 = (uint ******)PTR_DAT_001e8b78;
        if (pppppuVar16 != (uint *****)0x0) {
          pppppuVar54 = (uint *****)0x0;
          if ((uint *****)((int)pppppuVar16 - 1U) < pppppuVar16) {
            pppppuVar54 = (uint *****)(local_a8[2] + (int)((int)pppppuVar16 - 1U));
          }
          if ((int)local_188 <= (int)(*pppppuVar54)[0x2e]) {
            uVar11 = puVar14[2] - 1;
            piVar18 = (int *)0x0;
            if (uVar11 < (uint)puVar14[2]) {
              piVar18 = (int *)(uVar11 * 4 + puVar14[3]);
            }
            iVar45 = *piVar18;
            uVar52 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
            uVar48 = *(undefined4 *)(iVar45 + 0x150);
            puVar34 = (undefined4 *)FUN_00193e18(uVar52,0x138);
            *puVar34 = uVar52;
            ppppppuVar50 = (uint ******)(puVar34 + 1);
            in_r6 = *(uint *******)(param_1 + 8);
            FUN_000ec178(ppppppuVar50,iVar45,*(undefined4 *)(iVar45 + 300),in_r6);
            puVar34[0x2f] = local_188;
            FUN_000ec3ac(param_1,local_184,ppppppuVar50);
            FUN_000e8e4c(local_184,ppppppuVar50);
            FUN_000e8e4c(ppppppuVar50,uVar48);
            local_bc = 0;
            *(undefined4 *)(iVar45 + 0x13c) = 1;
            local_184 = (uint *****)ppppppuVar50;
            break;
          }
        }
        goto code_r0x00103718;
      }
      goto switchD_0010061c_caseD_1;
    case 0x26:
      puVar34 = (undefined4 *)0x0;
      uVar11 = puVar15[2] - 1;
      if (uVar11 < (uint)puVar15[2]) {
        puVar34 = (undefined4 *)(uVar11 * 4 + puVar15[3]);
      }
      if (*(int *)*puVar34 == 0) goto switchD_0010061c_caseD_1;
      piVar18 = (int *)((int)local_17c * 4 + iVar49);
      do {
        piVar38 = local_17c;
        if (*piVar18 == 0x37) {
          piVar38 = (int *)((int)local_17c + 1);
          piVar18 = piVar18 + 1;
        }
        local_17c = (int *)((int)piVar38 + 1);
        piVar18 = piVar18 + 1;
      } while (*piVar18 != 0x28);
      local_bc = 0;
      local_17c = piVar38;
      break;
    case 0x27:
      pppppuVar54 = (uint *****)0x0;
      pppppuVar16 = (uint *****)((int)local_a8[1] - 1);
      if (pppppuVar16 < local_a8[1]) {
        pppppuVar54 = (uint *****)(local_a8[2] + (int)pppppuVar16);
      }
      ppppuVar47 = *pppppuVar54;
      uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar34 = (undefined4 *)FUN_00193e18(uVar48,0x130);
      *puVar34 = uVar48;
      ppppppuVar50 = (uint ******)(puVar34 + 1);
      FUN_000ea020(ppppppuVar50,*(undefined4 *)(param_1 + 8));
      puVar34[0x2f] = local_188;
      ppppuVar47[0x4e] = (uint ***)ppppppuVar50;
      local_180 = (uint *****)ppppppuVar50;
      FUN_000e8e4c(ppppuVar47,ppppppuVar50);
      FUN_000ec3ac(param_1,local_184,local_180);
      goto code_r0x00103300;
    case 0x28:
      uVar11 = puVar15[2];
      piVar18 = (int *)0x0;
      if (uVar11 - 1 < uVar11) {
        piVar18 = (int *)((uVar11 - 1) * 4 + puVar15[3]);
      }
      piVar18 = (int *)*piVar18;
      FUN_00194208(puVar13,uVar11 - 1);
joined_r0x00103afc:
      if (piVar18 != (int *)0x0) {
        FUN_00193cc0(piVar18[-1],piVar18 + -1);
        goto code_r0x00101d1c;
      }
      goto switchD_0010061c_caseD_1;
    case 0x29:
      pppppuVar54 = (uint *****)0x0;
      pppppuVar16 = (uint *****)((int)local_a8[1] - 1);
      if (pppppuVar16 < local_a8[1]) {
        pppppuVar54 = (uint *****)(local_a8[2] + (int)pppppuVar16);
      }
      ppppuVar47 = *pppppuVar54;
      pppuVar44 = ppppuVar47[0x4f];
      pppuVar44[0x2e] = (uint **)local_188;
      FUN_000ec3ac(param_1,local_184,pppuVar44);
      piVar18 = (int *)FUN_000e7b9c(ppppuVar47);
      piVar18[0x2e] = (int)local_188;
      iVar45 = (**(code **)(*piVar18 + 0x38))();
      if ((iVar45 == 0) && (iVar45 = (**(code **)(*piVar18 + 0x3c))(piVar18), iVar45 == 0)) {
        FUN_000e8e4c(piVar18,pppuVar44);
      }
      ppppuVar32 = (uint ****)FUN_000e7a9c(ppppuVar47);
      ppppuVar32[0x2e] = (uint ***)local_188;
      ppppuVar53 = ppppuVar32;
      if (ppppuVar32 == ppppuVar47) {
        uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar34 = (undefined4 *)FUN_00193e18(uVar48,0x130);
        *puVar34 = uVar48;
        ppppuVar53 = (uint ****)(puVar34 + 1);
        FUN_000ea020(ppppuVar53,*(undefined4 *)(param_1 + 8));
        puVar34[0x2f] = local_188;
        ppppuVar32[0x4e] = (uint ***)ppppuVar53;
        FUN_000e8e4c(ppppuVar32,ppppuVar53);
        FUN_000ec3ac(param_1,local_184,ppppuVar53);
      }
      iVar45 = (*(code *)(*ppppuVar53)[0xe])(ppppuVar53);
      if ((iVar45 == 0) && (iVar45 = (*(code *)(*ppppuVar53)[0xf])(ppppuVar53), iVar45 == 0)) {
        FUN_000e8e4c(ppppuVar53,pppuVar44);
      }
      uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar34 = (undefined4 *)FUN_00193e18(uVar48,0x130);
      *puVar34 = uVar48;
      ppppppuVar50 = (uint ******)(puVar34 + 1);
      FUN_000ea020(ppppppuVar50,*(undefined4 *)(param_1 + 8));
      puVar34[0x2f] = local_188;
      local_180 = (uint *****)ppppppuVar50;
      FUN_000ec3ac(param_1,pppuVar44,ppppppuVar50);
      FUN_000e8e4c(pppuVar44,local_180);
      local_184 = local_180;
      FUN_00194208(local_a8,(int)local_a8[1] - 1);
      uVar11 = puVar14[2];
      if (uVar11 == 0) goto switchD_0010061c_caseD_1;
      piVar18 = (int *)0x0;
      if (uVar11 - 1 < uVar11) {
        piVar18 = (int *)((uVar11 - 1) * 4 + puVar14[3]);
      }
      local_bc = 0;
      *(int *)(*piVar18 + 300) = *(int *)(*piVar18 + 300) + -1;
      break;
    case 0x2a:
      uVar11 = puVar24[2];
      if (uVar11 != 0) {
        puVar34 = (undefined4 *)0x0;
        if (uVar11 - 1 < uVar11) {
          puVar34 = (undefined4 *)((uVar11 - 1) * 4 + puVar24[3]);
        }
        piVar18 = (int *)*puVar34;
        FUN_00194208(ppppppuVar19,uVar11 - 1);
        if ((uint ******)piVar18[2] != (uint ******)0x0) {
          local_180 = (uint *****)piVar18[2];
        }
        local_17c = (int *)piVar18[1];
        iVar49 = *piVar18;
        goto joined_r0x00103afc;
      }
      goto switchD_0010061c_caseD_0;
    case 0x2c:
      local_74 = 0x1dd5d8;
      if ((UNK_001dc660 == 0) || (iVar36 == UNK_001dc660)) {
code_r0x00101020:
        local_64 = 0;
      }
      else {
        piVar18 = &UNK_001dc66c;
        local_64 = 0;
        do {
          iVar45 = *piVar18;
          local_64 = local_64 + 1;
          if (iVar45 == 0) goto code_r0x00101020;
          piVar18 = piVar18 + 3;
        } while (iVar36 != iVar45);
      }
      local_64 = local_64 * 0xc;
      uVar11 = *(uint *)(local_64 + 0x1dc664);
      if ((uVar11 & 0x80) == 0) {
        uVar17 = (uint)*(byte *)((int)param_2 + 0x8d);
        uVar46 = uVar17;
      }
      else {
        uVar17 = (uint)*ppppppuVar51 >> 0x18 & 0x1f;
        uVar46 = (uint)*(byte *)((int)param_2 + 0x8d);
      }
      if (*(int *)(param_1 + 0x7c) < (int)uVar46) {
        *(uint *)(param_1 + 0x7c) = uVar46;
      }
      *(uint *)(param_1 + 0x84) = 1 << (uVar46 & 0x3f) | *(uint *)(param_1 + 0x84);
      puVar26 = (undefined2 *)FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),0x24);
      _memset(puVar26,0,0x24);
      puVar26[6] = 3;
      puVar26[4] = 7;
      puVar26[9] = 1;
      puVar26[10] = 0;
      *(uint *)(puVar26 + 0x10) = uVar17;
      *puVar26 = 3;
      puVar26[1] = 3;
      puVar26[2] = 3;
      puVar26[3] = 7;
      puVar26[5] = 3;
      puVar26[7] = 1;
      puVar26[8] = 0;
      puVar26[0xb] = 0;
      puVar26[0xc] = 0;
      puVar26[0xd] = 0;
      puVar26[0xe] = 0;
      if ((int)*ppppppuVar51 < 0) {
        uVar33 = ((int (*)())FUN_000f8a0c)((uint)param_2[0x25] & 7);
        *puVar26 = uVar33;
        uVar33 = ((int (*)())FUN_000f8a0c)((uint)param_2[0x25] >> 3 & 7);
        puVar26[1] = uVar33;
        uVar33 = ((int (*)())FUN_000f8a0c)((uint)param_2[0x25] >> 0xc & 7);
        puVar26[2] = uVar33;
        uVar33 = ((int (*)())FUN_000f8a0c)((uint)param_2[0x25] >> 6 & 7);
        puVar26[5] = uVar33;
        uVar33 = ((int (*)())FUN_000f8a0c)((uint)param_2[0x25] >> 9 & 7);
        puVar26[6] = uVar33;
        uVar33 = ((int (*)())FUN_000f8a0c)((uint)param_2[0x25] >> 0xf & 7);
        puVar26[3] = uVar33;
        puVar26[0xb] = (ushort)((uint)param_2[0x25] >> 0x12) & 0x7f;
        if ((uVar11 & 4) != 0) {
          puVar26[8] = ((ushort)((uint)param_2[0x25] >> 0x19) & 1) + 1;
        }
      }
      if (param_2[0x18] != (uint *****)0x0) {
        pppppuVar16 = param_2[0x24];
        puVar26[0xc] = (ushort)pppppuVar16 & 0xff;
        puVar26[0xd] = (ushort)((uint)pppppuVar16 >> 8) & 0xff;
        puVar26[0xe] = (ushort)((uint)pppppuVar16 >> 0x10) & 0xff;
      }
      bVar3 = (uVar11 & 1) != 0;
      local_c4 = (uint)*ppppppuVar51 >> 0x18 & 1;
      puVar26[9] = (ushort)local_c4 ^ 1;
      bVar1 = ((uint)*ppppppuVar51 >> 0x19 & 1) == 0;
      puVar26[7] = (ushort)bVar1;
      if (bVar3) {
        puVar26[8] = (ushort)(iVar36 != 0x5f);
      }
      uVar48 = *(undefined4 *)(param_1 + 0x3ac);
      iVar45 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar45;
      local_c8 = FUN_00127608(uVar48,0,iVar45,0);
      local_178 = *(uint *******)(local_60 + -0x2c30);
      local_124 = *(uint *******)(local_78 + -0x2bfc);
      uVar48 = *(undefined4 *)(param_1 + 0x3ac);
      iVar45 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar45;
      uVar48 = FUN_00127608(uVar48,0,iVar45,0);
      uVar52 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      FUN_001046c8(uVar52,0,uVar48);
      local_70 = &local_178;
      ((int (*)())FUN_000fa958)(param_1,5,1,param_2,uVar52,1,local_124,local_70);
      ((int (*)())FUN_000f92fc)(param_1,uVar52,local_180);
      if (bVar3) {
        uVar52 = *(undefined4 *)(param_1 + 0x3ac);
        iVar45 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar45;
        local_cc = FUN_00127608(uVar52,0,iVar45,0);
        uVar52 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(uVar52,0,local_cc);
        ((int (*)())FUN_000fa958)(param_1,10,1,param_2,uVar52,1,local_124,local_70);
        ((int (*)())FUN_000f92fc)(param_1,uVar52,local_180);
      }
      else {
        local_cc = 0;
      }
      bVar2 = (uVar11 >> 3 & 1) != 0;
      if (bVar2) {
        uVar52 = *(undefined4 *)(param_1 + 0x3ac);
        iVar45 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar45;
        local_d0 = FUN_00127608(uVar52,0,iVar45,0);
        uVar52 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(uVar52,0,local_d0);
        ((int (*)())FUN_000fa958)(param_1,0xe,1,param_2,uVar52,1,local_124,local_70);
        ((int (*)())FUN_000f92fc)(param_1,uVar52,local_180);
      }
      else {
        local_d0 = 0;
      }
      if ((uVar11 & 0x40) != 0) {
        iVar45 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(iVar45,0,uVar48);
        FUN_001046c8(iVar45,1,local_cc);
        uVar52 = DAT_001aa9cc;
        iVar20 = FUN_001054ec(iVar45,1);
        *(undefined4 *)(iVar20 + 0x10) = uVar52;
        *(uint ******)(iVar45 + 0x9c) = UNK_001aa9bc;
        ((int (*)())FUN_000f92fc)(param_1,iVar45,local_180);
      }
      iVar20 = uVar46 * 0xc;
      iVar45 = *(int *)(*(int *)(param_1 + 0x78) + iVar20 + 4);
      if ((iVar45 == 4) || (uVar52 = uVar48, iVar45 == 0xb)) {
        uVar52 = *(undefined4 *)(param_1 + 0x3ac);
        iVar45 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar45;
        uVar52 = FUN_00127608(uVar52,0,iVar45,0);
        uVar27 = FUN_001043f0(0x1b,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(uVar27,0,uVar52);
        FUN_001046c8(uVar27,1,uVar48);
        local_178 = (uint ******)0x2020001;
        iVar45 = FUN_001054ec(uVar27,1);
        *(undefined4 *)(iVar45 + 0x10) = 0x2020001;
        FUN_001046c8(uVar27,2,uVar48);
        local_178 = (uint ******)0x1000202;
        iVar45 = FUN_001054ec(uVar27,2);
        *(undefined4 *)(iVar45 + 0x10) = 0x1000202;
        ((int (*)())FUN_000f92fc)(param_1,uVar27,local_180);
        iVar45 = FUN_001043f0(0x40,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(iVar45,0,uVar52);
        *(undefined4 *)(iVar45 + 0x9c) = UNK_001aa9b4;
        FUN_001046c8(iVar45,1,uVar52);
        FUN_00103d50(iVar45 + 0xa4,2,1);
        pppppuVar16 = UNK_001aa9d8;
        iVar21 = FUN_001054ec(iVar45,1);
        *(uint ******)(iVar21 + 0x10) = pppppuVar16;
        ((int (*)())FUN_000f92fc)(param_1,iVar45,local_180);
        iVar45 = FUN_001043f0(0x14,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(iVar45,0,uVar52);
        *(undefined1 *)(iVar45 + 0x9c) = 0;
        *(undefined1 *)(iVar45 + 0x9d) = 0;
        *(undefined1 *)(iVar45 + 0x9e) = 1;
        *(undefined1 *)(iVar45 + 0x9f) = 1;
        FUN_001046c8(iVar45,1,uVar52);
        FUN_001046c8(iVar45,2,uVar52);
        iVar21 = FUN_001054ec(iVar45,2);
        *(uint ******)(iVar21 + 0x10) = pppppuVar16;
        dVar56 = (double)FLOAT_001aa128;
        ((void (*)())FUN_000f79c4)(iVar45,param_1,3,dVar56,dVar56,dVar56,dVar56);
        ((int (*)())FUN_000f92fc)(param_1,iVar45,local_180);
        piVar18 = (int *)FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(piVar18,0,uVar52);
        FUN_001046c8(piVar18,1,uVar52);
        (**(code **)(*piVar18 + 0x88))(piVar18,1,0,1);
        (**(code **)(*piVar18 + 0x88))(piVar18,1,1,0);
        (**(code **)(*piVar18 + 0x88))(piVar18,1,2,3);
        (**(code **)(*piVar18 + 0x88))(piVar18,1,3,0);
        ((int (*)())FUN_000f92fc)(param_1,piVar18,local_180);
        if (iVar36 == 0x8b) {
          iVar45 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
          FUN_001046c8(iVar45,0,uVar52);
          *(undefined1 *)(iVar45 + 0x9e) = 1;
          *(undefined1 *)(iVar45 + 0x9f) = 0;
          *(undefined1 *)(iVar45 + 0x9c) = 1;
          *(undefined1 *)(iVar45 + 0x9d) = 1;
          FUN_001046c8(iVar45,1,uVar48);
          ((int (*)())FUN_000f92fc)(param_1,iVar45,local_180);
        }
        piVar18 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
        (**(code **)(*piVar18 + 0x5c))(piVar18,uVar46);
      }
      if (bVar2) {
        uVar48 = FUN_001043f0(0x73,*(undefined4 *)(param_1 + 8));
        piVar18 = (int *)FUN_001043f0(0x72,*(undefined4 *)(param_1 + 8));
        uVar27 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x1e,0,0);
        FUN_001046c8(uVar48,0,uVar27);
        FUN_001046c8(uVar48,1,local_cc);
        FUN_001046c8(piVar18,0,uVar27);
        FUN_001046c8(piVar18,1,local_d0);
        (**(code **)(*piVar18 + 0x90))(piVar18,uVar27);
        ((int (*)())FUN_000f92fc)(param_1,uVar48,local_180);
        ((int (*)())FUN_000f92fc)(param_1,piVar18,local_180);
      }
      else {
        uVar27 = 0;
      }
      uVar48 = uVar52;
      if (bVar3) {
        bVar3 = (uVar11 >> 2 & 1) == 0;
        if (!bVar3) {
          uVar48 = *(undefined4 *)(param_1 + 0x3ac);
          iVar45 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar45;
          uVar48 = FUN_00127608(uVar48,0,iVar45,0);
          iVar45 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
          FUN_001046c8(iVar45,0,uVar48);
          *(uint ******)(iVar45 + 0x9c) = UNK_001aa9b8;
          FUN_001046c8(iVar45,1,uVar52);
          ((int (*)())FUN_000f92fc)(param_1,iVar45,local_180);
          iVar45 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
          FUN_001046c8(iVar45,0,uVar48);
          *(uint ******)(iVar45 + 0x9c) = UNK_001aa9bc;
          FUN_001046c8(iVar45,1,local_cc);
          ((int (*)())FUN_000f92fc)(param_1,iVar45,local_180);
        }
      }
      else {
        bVar3 = (uVar11 >> 2 & 1) == 0;
      }
      iVar45 = *(int *)(local_64 + local_74 + -0xf70);
      if ((bVar3) || (bVar1)) {
        if ((iVar45 != 0xff) || (*(int *)(iVar20 + *(int *)(param_1 + 0x78) + 4) != 7))
        goto code_r0x001019bc;
        iVar45 = FUN_001043f0(0x104,*(undefined4 *)(param_1 + 8));
        *(uint *)(iVar45 + 0x130) = uVar46;
        *(undefined4 *)(iVar45 + 0x140) = *(undefined4 *)(local_60 + -0x2c30);
        FUN_001046c8(iVar45,0,local_c8);
        FUN_001046c8(iVar45,1,uVar48);
        ((int (*)())FUN_000f92fc)(param_1,iVar45,local_180);
      }
      else {
        iVar45 = 0xae;
code_r0x001019bc:
        piVar18 = (int *)FUN_001043f0(iVar45,*(undefined4 *)(param_1 + 8));
        piVar18[0x4f] = (int)puVar26;
        piVar18[0x4d] = uVar46;
        FUN_001046c8(piVar18,0,local_c8);
        FUN_001046c8(piVar18,1,uVar48);
        if (bVar2) {
          (**(code **)(*piVar18 + 0x90))(piVar18,uVar27);
        }
        iVar45 = *(int *)(param_1 + 0x78);
        if (*(int *)(iVar20 + iVar45 + 4) == 8) {
          (**(code **)(*piVar18 + 0x88))(piVar18,1,2,1);
          iVar45 = FUN_001043f0(0xbe,*(undefined4 *)(param_1 + 8));
          iVar22 = piVar18[0x2b];
          iVar23 = piVar18[0x2c];
          iVar21 = FUN_001054ec(iVar45,0);
          *(int *)(iVar21 + 0xc) = iVar23;
          *(int *)(iVar21 + 8) = iVar22;
          iVar22 = piVar18[0x2b];
          iVar23 = piVar18[0x2c];
          iVar21 = FUN_001054ec(iVar45,1);
          *(int *)(iVar21 + 0xc) = iVar23;
          *(int *)(iVar21 + 8) = iVar22;
          uVar48 = UNK_001aa9b0;
          iVar21 = FUN_001054ec(iVar45,1);
          *(undefined4 *)(iVar21 + 0x10) = uVar48;
          *(undefined4 *)(iVar45 + 0x9c) = UNK_001aa9ac;
          ((int (*)())FUN_000f92fc)(param_1,iVar45,local_180);
          iVar45 = *(int *)(param_1 + 0x78);
        }
        if (*(int *)(iVar20 + iVar45 + 4) == 9) {
          iVar45 = FUN_001043f0(0xbe,*(undefined4 *)(param_1 + 8));
          iVar22 = piVar18[0x2b];
          iVar23 = piVar18[0x2c];
          iVar21 = FUN_001054ec(iVar45,0);
          *(int *)(iVar21 + 0xc) = iVar23;
          *(int *)(iVar21 + 8) = iVar22;
          iVar22 = piVar18[0x2b];
          iVar23 = piVar18[0x2c];
          iVar21 = FUN_001054ec(iVar45,1);
          *(int *)(iVar21 + 0xc) = iVar23;
          *(int *)(iVar21 + 8) = iVar22;
          pppppuVar16 = UNK_001aa9d8;
          iVar21 = FUN_001054ec(iVar45,1);
          *(uint ******)(iVar21 + 0x10) = pppppuVar16;
          *(undefined4 *)(iVar45 + 0x9c) = UNK_001aa9b4;
          ((int (*)())FUN_000f92fc)(param_1,iVar45,local_180);
          iVar45 = *(int *)(param_1 + 0x78);
        }
        iVar45 = ((int (*)())FUN_000f89e8)(*(undefined4 *)(iVar20 + iVar45));
        piVar18[0x4e] = iVar45;
        *(short *)(piVar18[0x4f] + 0x12) = (short)local_c4;
        ((int (*)())FUN_000f92fc)(param_1,piVar18,local_180);
        if (*(int *)(iVar20 + *(int *)(param_1 + 0x78) + 8) != 0) {
          uVar48 = FUN_001043f0(0x13,*(undefined4 *)(param_1 + 8));
          iVar20 = piVar18[0x25];
          iVar21 = piVar18[0x26];
          iVar45 = FUN_001054ec(uVar48,0);
          *(int *)(iVar45 + 0xc) = iVar21;
          *(int *)(iVar45 + 8) = iVar20;
          iVar20 = piVar18[0x26];
          iVar21 = piVar18[0x25];
          iVar45 = FUN_001054ec(uVar48,1);
          local_98 = (uint)(short)uVar46;
          *(int *)(iVar45 + 0xc) = iVar20;
          local_90 = local_98 | 0x130000;
          local_94 = local_98 | 0x130000;
          local_9c = local_98 | 0x130000;
          local_98 = local_98 | 0x130000;
          *(int *)(iVar45 + 8) = iVar21;
          ((int (*)())FUN_000f771c)(uVar48,param_1,2,local_90,local_94,local_98,local_9c);
          ((int (*)())FUN_000f92fc)(param_1,uVar48,local_180);
        }
      }
      local_178 = *(uint *******)(local_60 + -0x2c30);
      local_124 = *(uint *******)(local_78 + -0x2bfc);
      ppppppuVar40 = (uint ******)FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      in_r8 = (uint ******)((int)&MACH_HEADER.magic + 1);
      in_r6 = param_2;
      in_r7 = ppppppuVar40;
      ((int (*)())FUN_000fa958)(param_1,0,0,param_2,ppppppuVar40,1,local_124,local_70);
      FUN_001046c8(ppppppuVar40,1,local_c8);
      goto code_r0x00101cbc;
    case 0x2d:
    case 0x2e:
      pppppuVar43 = (uint *****)(uint)*(byte *)((int)param_2 + 0x8d);
      pppppuVar54 = (uint *****)FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),0x24);
      _memset(pppppuVar54,0,0x24);
      *(undefined2 *)((int)pppppuVar54 + 0x12) = 1;
      *(undefined2 *)((int)pppppuVar54 + 0xe) = 1;
      *(undefined2 *)(pppppuVar54 + 5) = 0;
      *(undefined2 *)(pppppuVar54 + 4) = 0;
      *(undefined2 *)((int)pppppuVar54 + 0x16) = 0;
      *(undefined2 *)(pppppuVar54 + 6) = 0;
      *(undefined2 *)((int)pppppuVar54 + 0x1a) = 0;
      *(undefined2 *)(pppppuVar54 + 7) = 0;
      *(undefined2 *)(pppppuVar54 + 2) = 7;
      *(undefined2 *)(pppppuVar54 + 3) = 3;
      *(undefined2 *)pppppuVar54 = 3;
      *(undefined2 *)((int)pppppuVar54 + 2) = 3;
      *(undefined2 *)(pppppuVar54 + 1) = 3;
      *(undefined2 *)((int)pppppuVar54 + 6) = 7;
      *(undefined2 *)((int)pppppuVar54 + 10) = 3;
      *(ushort *)((int)pppppuVar54 + 0x12) =
           (ushort)(((uint)(byte)((((uint)*ppppppuVar51 & 0x1000000) == 0) << 1) << 0x1c) >> 0x1d);
      bVar1 = ((uint)*ppppppuVar51 >> 0x19 & 1) == 0;
      *(ushort *)((int)pppppuVar54 + 0xe) = (ushort)bVar1;
      uVar48 = *(undefined4 *)(param_1 + 0x3ac);
      iVar45 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar45;
      uVar48 = FUN_00127608(uVar48,0,iVar45,0);
      pppppuVar16 = UNK_001aa9b8;
      local_124 = (uint ******)UNK_001aa9b8;
      pppppuVar41 = *(uint ******)(local_60 + -0x2c30);
      local_178 = (uint ******)pppppuVar41;
      iVar45 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      FUN_001046c8(iVar45,0,uVar48);
      *(uint ******)(iVar45 + 0x9c) = pppppuVar16;
      local_70 = &local_178;
      ((int (*)())FUN_000fa958)(param_1,5,1,param_2,iVar45,1,local_124,local_70);
      ((int (*)())FUN_000f92fc)(param_1,iVar45,local_180);
      pppppuVar16 = UNK_001aa9bc;
      local_124 = (uint ******)UNK_001aa9bc;
      local_178 = (uint ******)pppppuVar41;
      ppppppuVar40 = (uint ******)FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      FUN_001046c8(ppppppuVar40,0,uVar48);
      ppppppuVar40[0x27] = pppppuVar16;
      ((int (*)())FUN_000fa958)(param_1,10,1,param_2,ppppppuVar40,1,local_124,local_70);
      ((int (*)())FUN_000f92fc)(param_1,ppppppuVar40,local_180);
      if (bVar1) {
        uVar52 = 0x76;
      }
      else {
        uVar52 = 0xae;
        if (uVar11 == 0x2d) {
          FUN_000e1534(*(undefined4 *)(param_1 + 8),0xf);
          uVar52 = 0xae;
        }
      }
      local_124 = *(uint *******)(local_78 + -0x2bfc);
      ppppppuVar12 = *(uint *******)(local_60 + -0x2c30);
      local_178 = ppppppuVar12;
      ppppppuVar50 = (uint ******)FUN_001043f0(uVar52,*(undefined4 *)(param_1 + 8));
      ppppppuVar50[0x4f] = pppppuVar54;
      ppppppuVar50[0x4d] = pppppuVar43;
      if (*(int *)(param_1 + 0x7c) < (int)pppppuVar43) {
        *(uint ******)(param_1 + 0x7c) = pppppuVar43;
      }
      *(uint *)(param_1 + 0x84) = 1 << ((uint)pppppuVar43 & 0x3f) | *(uint *)(param_1 + 0x84);
      pppppuVar16 = (uint *****)
                    ((int (*)())FUN_000f89e8)(*(undefined4 *)(*(int *)(param_1 + 0x78) + (int)pppppuVar43 * 0xc))
      ;
      ppppppuVar50[0x4c] = pppppuVar43;
      ppppppuVar50[0x4e] = pppppuVar16;
      in_r8 = (uint ******)((int)&MACH_HEADER.magic + 1);
      in_r6 = param_2;
      in_r7 = ppppppuVar50;
      iVar45 = ((int (*)())FUN_000fa958)(param_1,4,0,param_2,ppppppuVar50,1,local_124,local_70);
      if (iVar45 != 0) {
        FUN_00193f94(local_6c,iVar45);
      }
      FUN_001046c8(ppppppuVar50,1,uVar48);
      iVar45 = FUN_001054ec(ppppppuVar50,1);
      *(uint *******)(iVar45 + 0x10) = ppppppuVar12;
      pppppuVar16 = (uint *****)
                    ((int (*)())FUN_000f89e8)(*(undefined4 *)((int)pppppuVar43 * 0xc + *(int *)(param_1 + 0x78)))
      ;
      ppppppuVar50[0x4e] = pppppuVar16;
      ((int (*)())FUN_000f92fc)(param_1,ppppppuVar50,local_180);
      goto code_r0x00101d1c;
    case 0x2f:
      uVar11 = (uint)*(byte *)((int)param_2 + 0x8d);
      puVar26 = (undefined2 *)FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),0x24);
      _memset(puVar26,0,0x24);
      puVar26[9] = 1;
      puVar26[6] = 3;
      puVar26[7] = 1;
      *puVar26 = 3;
      puVar26[1] = 3;
      puVar26[2] = 3;
      puVar26[5] = 3;
      puVar26[4] = 7;
      puVar26[10] = 0;
      puVar26[3] = 7;
      puVar26[8] = 0;
      puVar26[0xb] = 0;
      puVar26[0xc] = 0;
      puVar26[0xd] = 0;
      puVar26[0xe] = 0;
      uVar7 = (byte)((uint)*ppppppuVar51 >> 0x18) & 1;
      puVar26[9] = uVar7 ^ 1;
      puVar26[7] = (ushort)(((uint)(byte)((((uint)*ppppppuVar51 & 0x2000000) == 0) << 1) << 0x1c) >>
                           0x1d);
      uVar48 = *(undefined4 *)(param_1 + 0x3ac);
      iVar45 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar45;
      uVar52 = FUN_00127608(uVar48,0,iVar45,0);
      local_178 = *(uint *******)(local_60 + -0x2c30);
      local_124 = *(uint *******)(local_78 + -0x2bfc);
      uVar48 = *(undefined4 *)(param_1 + 0x3ac);
      iVar45 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar45;
      uVar27 = FUN_00127608(uVar48,0,iVar45,0);
      uVar48 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      FUN_001046c8(uVar48,0,uVar27);
      local_70 = &local_178;
      ((int (*)())FUN_000fa958)(param_1,5,1,param_2,uVar48,1,local_124,local_70);
      ((int (*)())FUN_000f92fc)(param_1,uVar48,local_180);
      uVar48 = 0;
      if (iVar36 == 0x5f) {
        uVar48 = *(undefined4 *)(param_1 + 0x3ac);
        iVar45 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar45;
        uVar48 = FUN_00127608(uVar48,0,iVar45,0);
        uVar28 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(uVar28,0,uVar48);
        ((int (*)())FUN_000fa958)(param_1,10,1,param_2,uVar28,1,local_124,local_70);
        ((int (*)())FUN_000f92fc)(param_1,uVar28,local_180);
        uVar28 = *(undefined4 *)(param_1 + 0x3ac);
        iVar45 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar45;
        uVar28 = FUN_00127608(uVar28,0,iVar45,0);
        uVar29 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(uVar29,0,uVar28);
        ((int (*)())FUN_000fa958)(param_1,0xe,1,param_2,uVar29,1,local_124,local_70);
        ((int (*)())FUN_000f92fc)(param_1,uVar29,local_180);
      }
      else {
        uVar28 = 0;
      }
      iVar45 = FUN_001043f0(0x78,*(undefined4 *)(param_1 + 8));
      *(undefined2 **)(iVar45 + 0x13c) = puVar26;
      FUN_001046c8(iVar45,0,uVar52);
      FUN_001046c8(iVar45,1,uVar27);
      if (iVar36 == 0x5f) {
        FUN_001046c8(iVar45,2,uVar48);
        FUN_001046c8(iVar45,3,uVar28);
      }
      *(uint *)(iVar45 + 0x134) = uVar11;
      if (*(int *)(param_1 + 0x7c) < (int)uVar11) {
        *(uint *)(param_1 + 0x7c) = uVar11;
      }
      *(uint *)(param_1 + 0x84) = 1 << (uVar11 & 0x3f) | *(uint *)(param_1 + 0x84);
      uVar48 = ((int (*)())FUN_000f89e8)(*(undefined4 *)(uVar11 * 0xc + *(int *)(param_1 + 0x78)));
      *(undefined4 *)(iVar45 + 0x138) = uVar48;
      *(uint *)(iVar45 + 0x130) = uVar11;
      *(ushort *)(*(int *)(iVar45 + 0x13c) + 0x12) = uVar7;
      ((int (*)())FUN_000f92fc)(param_1,iVar45,local_180);
      local_178 = *(uint *******)(local_60 + -0x2c30);
      local_124 = *(uint *******)(local_78 + -0x2bfc);
      ppppppuVar40 = (uint ******)FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      in_r8 = (uint ******)((int)&MACH_HEADER.magic + 1);
      in_r6 = param_2;
      in_r7 = ppppppuVar40;
      ((int (*)())FUN_000fa958)(param_1,0,0,param_2,ppppppuVar40,1,local_124,local_70);
      FUN_001046c8(ppppppuVar40,1,uVar52);
code_r0x00101cbc:
      ((int (*)())FUN_000f92fc)(param_1,ppppppuVar40,local_180);
      goto code_r0x00101d1c;
    case 0x30:
      iVar45 = iVar49 + (int)local_17c * 4;
      ((void (*)())FUN_000f79c4)(ppppppuVar40,param_1,ppppppuVar42,(double)*(float *)(iVar45 + 4),
                   (double)*(float *)(iVar45 + 8),(double)*(float *)(iVar45 + 0xc),
                   (double)*(float *)(iVar45 + 0x10));
      iVar45 = FUN_001054ec(ppppppuVar40,ppppppuVar42);
      FUN_000f2bdc(&local_d8,*(undefined4 *)(iVar45 + 0x10),local_178);
      uVar48 = local_d8;
      iVar45 = FUN_001054ec(ppppppuVar40,ppppppuVar42);
      *(undefined4 *)(iVar45 + 0x10) = uVar48;
      ppppppuVar42 = (uint ******)((int)ppppppuVar42 + 1);
      local_bc = 0;
      local_17c = local_17c + 1;
      break;
    case 0x31:
      uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
      puVar34 = (undefined4 *)FUN_00193e18(uVar48,0x10);
      *puVar34 = uVar48;
      puVar37 = puVar34 + 1;
      local_17c = (int *)((int)local_17c + 1);
      switch(*(undefined4 *)(iVar49 + (int)local_17c * 4)) {
      case 0x3f:
        *puVar37 = (uint)*ppppppuVar51 >> 0x12 & 1;
        break;
      default:
        *puVar37 = 0;
        break;
      case 0x5f:
        *puVar37 = (uint)*ppppppuVar51 >> 0x18 & 1;
        break;
      case 0x67:
        *puVar37 = 1;
      }
      uVar11 = puVar15[2];
      if (uVar11 < *puVar13) {
        _memset((void *)(uVar11 * 4 + puVar15[3]),0,4);
        puVar15[2] = uVar11 + 1;
        puVar34 = (undefined4 *)(uVar11 * 4 + puVar15[3]);
      }
      else {
        puVar34 = (undefined4 *)FUN_0019423c(puVar13,uVar11);
      }
      local_bc = 0;
      *puVar34 = puVar37;
      break;
    case 0x32:
      ppppppuVar50 = (uint ******)0x0;
      pppppuVar16 = (uint *****)local_a8[1];
      if (pppppuVar16 != (uint *****)0x0) {
        pppppuVar54 = (uint *****)0x0;
        if ((uint *****)((int)pppppuVar16 - 1U) < pppppuVar16) {
          pppppuVar54 = (uint *****)(local_a8[2] + (int)((int)pppppuVar16 - 1U));
        }
        ppppppuVar50 = (uint ******)*pppppuVar54;
        ppppppuVar50[0x51] = (uint *****)0x0;
      }
      local_17c = (int *)((int)local_17c + 1);
      switch(*(undefined4 *)(iVar49 + (int)local_17c * 4)) {
      case 0x62:
        iVar45 = FUN_001043f0(0x8b,*(undefined4 *)(param_1 + 8));
        dVar56 = (double)FLOAT_001aa0e8;
        ((void (*)())FUN_000f79c4)(iVar45,param_1,1,dVar56,dVar56,dVar56,dVar56);
        dVar56 = (double)FLOAT_001aa0e8;
        ((void (*)())FUN_000f79c4)(iVar45,param_1,2,dVar56,dVar56,dVar56,dVar56);
        *(undefined4 *)(iVar45 + 300) = 0;
        uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar34 = (undefined4 *)FUN_00193e18(uVar48,0x15c);
        *puVar34 = uVar48;
        pppppuVar16 = (uint *****)(puVar34 + 1);
        in_r6 = (uint ******)0x0;
        in_r7 = *(uint *******)(param_1 + 8);
        FUN_000ea6d0(pppppuVar16,iVar45,ppppppuVar50,0,in_r7);
        break;
      case 99:
        iVar45 = *(int *)(param_1 + 8);
        pppuVar44 = **param_2[0x1b];
        if (((((uint)pppuVar44 & 0x3f0000) == 0x100000) && (iVar45 != 0)) &&
           ((*(uint *)(*(int *)(iVar45 + 0x30c) + 8) & 0x80) != 0)) {
          iVar20 = 0xf;
        }
        else {
          iVar20 = (int)*(short *)((int)*param_2[0x1b] + 2);
        }
        iVar45 = FUN_001043f0(0x8d,iVar45);
        uVar48 = FUN_000ec208(param_1,(uint)pppuVar44 >> 0x10 & 0x3f);
        iVar21 = FUN_001054ec(iVar45,1);
        *(undefined4 *)(iVar21 + 0xc) = uVar48;
        puVar8 = PTR_DAT_001e8b84;
        *(int *)(iVar21 + 8) = iVar20;
        *(undefined4 *)(iVar45 + 300) = *(undefined4 *)puVar8;
        uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar34 = (undefined4 *)FUN_00193e18(uVar48,0x15c);
        *puVar34 = uVar48;
        pppppuVar16 = (uint *****)(puVar34 + 1);
        in_r6 = *(uint *******)(param_1 + 8);
        FUN_000ebac8(pppppuVar16,iVar45,ppppppuVar50,in_r6);
        FUN_000e78c0(pppppuVar16,local_188);
        FUN_000ed63c(param_1,iVar45);
        pppppuVar54 = (uint *****)0x0;
        if ((uint *****)local_a8[1] != (uint *****)0x0) {
          puVar34[0x53] = 0;
          pppppuVar54 = (uint *****)local_a8[1];
        }
        if (pppppuVar54 < *local_a8) {
          _memset(local_a8[2] + (int)pppppuVar54,0,4);
          local_a8[1] = (uint ****)((int)pppppuVar54 + 1);
          pppppuVar54 = (uint *****)(local_a8[2] + (int)pppppuVar54);
        }
        else {
          pppppuVar54 = (uint *****)FUN_0019423c(local_a8,pppppuVar54);
        }
        *pppppuVar54 = (uint ****)pppppuVar16;
        uVar11 = puVar14[2];
        if (uVar11 == 0) goto code_r0x00103240;
        goto code_r0x00103214;
      case 100:
        ppppuVar47 = *param_2[0x1b];
        pppuVar44 = *ppppuVar47;
        iVar45 = *(int *)(param_1 + 8);
        if ((((uint)pppuVar44 & 0x3f0000) == 0x100000) && (iVar45 != 0)) {
          piVar18 = *(int **)(iVar45 + 0x30c);
          if ((piVar18[2] & 0x80U) == 0) goto code_r0x00100810;
          iVar20 = 0xf;
        }
        else {
          piVar18 = *(int **)(iVar45 + 0x30c);
code_r0x00100810:
          iVar20 = (int)*(short *)((int)ppppuVar47 + 2);
        }
        ppppuVar47 = param_2[0x1b][1];
        pppuVar35 = *ppppuVar47;
        if (((((uint)pppuVar35 & 0x3f0000) == 0x100000) && (iVar45 != 0)) &&
           ((piVar18[2] & 0x80U) != 0)) {
          iVar45 = 0xf;
        }
        else {
          iVar45 = (int)*(short *)((int)ppppuVar47 + 2);
        }
        in_r8 = (uint ******)((uint)pppuVar35 >> 0x10 & 0x3f);
        iVar45 = (**(code **)(*piVar18 + 0x24))
                           (piVar18,(uint)*ppppppuVar51 >> 0x10 & 7,iVar20,
                            (uint)pppuVar44 >> 0x10 & 0x3f,iVar45,in_r8,local_178,param_2);
        uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar34 = (undefined4 *)FUN_00193e18(uVar48,0x15c);
        *puVar34 = uVar48;
        pppppuVar16 = (uint *****)(puVar34 + 1);
        in_r6 = (uint ******)0x0;
        in_r7 = *(uint *******)(param_1 + 8);
        FUN_000ea6d0(pppppuVar16,iVar45,ppppppuVar50,0,in_r7);
        break;
      case 0x65:
        uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar34 = (undefined4 *)FUN_00193e18(uVar48,0x168);
        *puVar34 = uVar48;
        puVar34 = puVar34 + 1;
        FUN_0010502c(puVar34,0x8c,*(undefined4 *)(param_1 + 8));
        uVar48 = 6;
        goto code_r0x00102c90;
      case 0x66:
        uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar34 = (undefined4 *)FUN_00193e18(uVar48,0x168);
        *puVar34 = uVar48;
        puVar34 = puVar34 + 1;
        FUN_0010502c(puVar34,0x8c,*(undefined4 *)(param_1 + 8));
        uVar48 = 7;
code_r0x00102c90:
        puVar34[0x4b] = uVar48;
        in_r7 = (uint ******)local_a8;
        in_r8 = ppppppuVar39;
        pppppuVar16 = (uint *****)
                      ((int (*)())FUN_000fadc4)(param_1,puVar34,local_188,ppppppuVar50,local_a8,ppppppuVar39,
                                   param_2);
        in_r6 = ppppppuVar50;
        goto code_r0x00103240;
      default:
        pppppuVar16 = (uint *****)0x0;
        goto code_r0x00103240;
      case 0x6f:
        uVar11 = local_b0[1] - 1;
        puVar34 = (undefined4 *)0x0;
        if (uVar11 < local_b0[1]) {
          puVar34 = (undefined4 *)(uVar11 * 4 + local_b0[2]);
        }
        piVar18 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
        in_r8 = local_178;
        uVar48 = (**(code **)(*piVar18 + 0x28))
                           (piVar18,1,*(undefined4 *)*puVar34,4,param_2[(int)param_2[0x16] + 0x23],
                            local_178,param_2,local_180);
        uVar52 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar34 = (undefined4 *)FUN_00193e18(uVar52,0x15c);
        *puVar34 = uVar52;
        pppppuVar16 = (uint *****)(puVar34 + 1);
        in_r6 = (uint ******)0x0;
        in_r7 = *(uint *******)(param_1 + 8);
        FUN_000ea6d0(pppppuVar16,uVar48,ppppppuVar50,0,in_r7);
        uVar11 = local_b0[1] - 1;
        if (uVar11 < local_b0[1]) {
          piVar18 = (int *)(uVar11 * 4 + local_b0[2]);
        }
        else {
          piVar18 = (int *)0x0;
        }
        iVar45 = *piVar18;
        FUN_000e77f4(pppppuVar16,*(undefined4 *)(iVar45 + 8));
        *(uint ******)(iVar45 + 8) = pppppuVar16;
        FUN_000e78c0(pppppuVar16,local_188);
        FUN_000ed63c(param_1,uVar48);
        goto code_r0x0010319c;
      case 0x72:
        iVar45 = *(int *)(param_1 + 8);
        pppuVar44 = **param_2[0x1b];
        if ((((uint)pppuVar44 & 0x3f0000) == 0x100000) && (iVar45 != 0)) {
          piVar18 = *(int **)(iVar45 + 0x30c);
          if ((piVar18[2] & 0x80U) == 0) goto code_r0x0010082c;
          iVar45 = 0xf;
        }
        else {
          piVar18 = *(int **)(iVar45 + 0x30c);
code_r0x0010082c:
          iVar45 = (int)*(short *)((int)*param_2[0x1b] + 2);
        }
        in_r8 = local_178;
        iVar45 = (**(code **)(*piVar18 + 0x28))
                           (piVar18,iVar36 == 0x6f,iVar45,(uint)pppuVar44 >> 0x10 & 0x3f,0,local_178
                            ,param_2,local_180);
        uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar34 = (undefined4 *)FUN_00193e18(uVar48,0x15c);
        *puVar34 = uVar48;
        pppppuVar16 = (uint *****)(puVar34 + 1);
        in_r6 = (uint ******)0x0;
        in_r7 = *(uint *******)(param_1 + 8);
        FUN_000ea6d0(pppppuVar16,iVar45,ppppppuVar50,0,in_r7);
      }
      FUN_000e78c0(pppppuVar16,local_188);
      FUN_000ed63c(param_1,iVar45);
code_r0x0010319c:
      pppppuVar54 = (uint *****)0x0;
      if ((uint *****)local_a8[1] != (uint *****)0x0) {
        pppppuVar16[0x52] = (uint ****)0x0;
        pppppuVar54 = (uint *****)local_a8[1];
      }
      if (pppppuVar54 < *local_a8) {
        _memset(local_a8[2] + (int)pppppuVar54,0,4);
        local_a8[1] = (uint ****)((int)pppppuVar54 + 1);
        pppppuVar54 = (uint *****)(local_a8[2] + (int)pppppuVar54);
      }
      else {
        pppppuVar54 = (uint *****)FUN_0019423c(local_a8,pppppuVar54);
      }
      *pppppuVar54 = (uint ****)pppppuVar16;
      uVar11 = puVar14[2];
      if (uVar11 != 0) {
code_r0x00103214:
        piVar18 = (int *)0x0;
        if (uVar11 - 1 < uVar11) {
          piVar18 = (int *)((uVar11 - 1) * 4 + puVar14[3]);
        }
        *(int *)(*piVar18 + 300) = *(int *)(*piVar18 + 300) + 1;
      }
code_r0x00103240:
      FUN_000ec3ac(param_1,local_184,pppppuVar16);
      FUN_000e8e4c(local_184,pppppuVar16);
      local_180 = (uint *****)pppppuVar16[0x4d];
      local_184 = pppppuVar16;
      FUN_000ec3ac(param_1,pppppuVar16,local_180);
code_r0x00103300:
      local_bc = 0;
      local_184 = local_180;
      break;
    case 0x34:
      iVar45 = FUN_001054ec(ppppppuVar40,ppppppuVar42);
      local_bc = 0;
      ppppppuVar42 = (uint ******)((int)ppppppuVar42 + 1);
      *(undefined4 *)(iVar45 + 8) = 0;
      *(undefined4 *)(iVar45 + 0xc) = 0x21;
      break;
    case 0x35:
      piVar18 = (int *)0x0;
      uVar11 = puVar14[2] - 1;
      if (uVar11 < (uint)puVar14[2]) {
        piVar18 = (int *)(uVar11 * 4 + puVar14[3]);
      }
      iVar20 = *piVar18;
      iVar45 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),3);
      if ((iVar45 == 0) || (iVar45 = FUN_0012c2dc(param_1,iVar20), iVar45 == 0)) {
        in_r6 = &local_184;
        in_r7 = &local_180;
        in_r8 = (uint ******)&local_188;
        iVar45 = FUN_0012f0f8(param_1,ppppppuVar39,iVar20,in_r6,in_r7,in_r8);
        if (iVar45 != 0) goto switchD_0010061c_caseD_1;
        if (*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0x4c) < (int)local_188) {
          FUN_000e1534(*(int *)(param_1 + 8),8);
        }
        iVar21 = *(int *)(iVar20 + 0x150);
        FUN_000ec3ac(param_1,local_184,iVar21);
        iVar45 = (*(code *)(*local_184)[0xe])();
        if ((iVar45 == 0) && (iVar45 = (*(code *)(*local_184)[0xf])(), iVar45 == 0)) {
          FUN_000e8e4c(local_184,iVar21);
        }
        uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar34 = (undefined4 *)FUN_00193e18(uVar48,0x130);
        *puVar34 = uVar48;
        puVar31 = puVar34 + 1;
        FUN_000ea020(puVar31,*(undefined4 *)(param_1 + 8));
        FUN_000e8e4c(iVar20,puVar31);
        FUN_000ec3ac(param_1,iVar21,puVar31);
        iVar45 = *(int *)(iVar20 + 0x154);
        FUN_000e8e4c(puVar31,iVar45);
        FUN_000ec3ac(param_1,puVar31,iVar45);
        uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar31 = (undefined4 *)FUN_00193e18(uVar48,0x130);
        *puVar31 = uVar48;
        ppppppuVar50 = (uint ******)(puVar31 + 1);
        FUN_000ea020(ppppppuVar50,*(undefined4 *)(param_1 + 8));
        local_180 = (uint *****)ppppppuVar50;
        FUN_000ec3ac(param_1,iVar45,ppppppuVar50);
        FUN_000e8e4c(iVar45,local_180);
        local_184 = local_180;
        FUN_00194208(ppppppuVar39,puVar14[2] + -1);
        local_bc = 0;
        *(uint *****)(iVar21 + 0xb8) = local_188;
        local_188 = (uint ****)((int)local_188 - 1);
        *(uint *****)(iVar45 + 0xb8) = local_188;
        puVar34[0x2f] = local_188;
        local_180[0x2e] = local_188;
      }
      else {
        local_184 = (uint *****)FUN_000e7e90(iVar20);
        if (*(int **)(iVar20 + 0x150) != (int *)0x0) {
          (**(code **)(**(int **)(iVar20 + 0x150) + 4))();
        }
        if (*(int **)(iVar20 + 0x154) != (int *)0x0) {
          (**(code **)(**(int **)(iVar20 + 0x154) + 4))();
        }
        FUN_00194374(local_184[0x34],iVar20);
        do {
          ppppppuVar50 = (uint ******)local_184[2];
          pppppuVar16 = ppppppuVar50[0x26];
          for (pppppuVar54 = (uint *****)ppppppuVar50[0x26][2]; pppppuVar54 != (uint *****)0x0;
              pppppuVar54 = (uint *****)pppppuVar54[2]) {
            if (((uint)pppppuVar16[5] & 1) != 0) {
              pppppuVar16[5] = (uint ****)((uint)pppppuVar16[5] & 0xfffffffe);
            }
            pppppuVar16 = pppppuVar54;
          }
          FUN_00193fa4(ppppppuVar50 + 0x24);
          FUN_0019401c(ppppppuVar50);
          if (ppppppuVar50 != (uint ******)0x0) {
            (*(code *)(*ppppppuVar50)[1])(ppppppuVar50);
          }
        } while (ppppppuVar50 != (uint ******)local_180);
        local_bc = 0;
        local_188 = (uint ****)((int)local_188 - 1);
        local_180 = local_184;
      }
      break;
    case 0x36:
      uVar11 = puVar14[2];
      uVar48 = 0;
      if (uVar11 != 0) {
        puVar34 = (undefined4 *)0x0;
        if (uVar11 - 1 < uVar11) {
          puVar34 = (undefined4 *)((uVar11 - 1) * 4 + puVar14[3]);
        }
        uVar48 = *puVar34;
      }
      in_r6 = (uint ******)(uint)(iVar36 == 0x71);
      if (in_r6 == (uint ******)0x0) {
        uVar11 = (uint)*(ushort *)((int)*param_2[0x1b] + 2);
      }
      else {
        uVar11 = 0;
      }
      uVar52 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar34 = (undefined4 *)FUN_00193e18(uVar52,0x15c);
      *puVar34 = uVar52;
      puVar31 = puVar34 + 1;
      in_r7 = *(uint *******)(param_1 + 8);
      FUN_000ea828(puVar31,uVar11,uVar48,in_r6,in_r7);
      puVar34[0x2f] = local_188;
      if (((uint)*ppppppuVar51 & 0x10000) != 0) {
        puVar34[0x4e] = 1;
      }
      FUN_000ed63c(param_1,puVar34[0x53]);
      pppppuVar16 = (uint *****)puVar14[2];
      if (pppppuVar16 < *ppppppuVar39) {
        _memset((void *)((int)pppppuVar16 * 4 + puVar14[3]),0,4);
        puVar14[2] = (int)pppppuVar16 + 1;
        puVar30 = (undefined4 *)((int)pppppuVar16 * 4 + puVar14[3]);
      }
      else {
        puVar30 = (undefined4 *)FUN_0019423c(ppppppuVar39,pppppuVar16);
      }
      *puVar30 = puVar31;
      local_188 = (uint ****)((int)local_188 + 1);
      FUN_000ec3ac(param_1,local_184,puVar31);
      FUN_000e8e4c(local_184,puVar31);
      uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar30 = (undefined4 *)FUN_00193e18(uVar48,0x130);
      *puVar30 = uVar48;
      ppppppuVar50 = (uint ******)(puVar30 + 1);
      FUN_000ea020(ppppppuVar50,*(undefined4 *)(param_1 + 8));
      puVar30[0x2f] = local_188;
      local_180 = (uint *****)ppppppuVar50;
      FUN_000ec3ac(param_1,puVar31,ppppppuVar50);
      FUN_000e8e4c(puVar31,local_180);
      local_184 = local_180;
      local_bc = 0;
      puVar34[0x4d] = *(undefined4 *)(*(int *)(param_1 + 8) + 0x324);
      break;
    case 0x37:
      local_17c = (int *)((int)local_17c + 1);
      uVar48 = *(undefined4 *)(iVar49 + (int)local_17c * 4);
      if (*(int *)(param_1 + 0x47c) != 0) {
        uVar48 = 0x75;
      }
      ppppppuVar40 = (uint ******)FUN_001043f0(uVar48,*(undefined4 *)(param_1 + 8));
      local_bc = 0;
      break;
    case 0x38:
      local_b4 = 1;
      goto code_r0x00101d1c;
    case 0x3a:
      local_bc = 0;
      ppppppuVar40[0x48] = (uint *****)0x1;
      goto code_r0x00103b3c;
    case 0x3d:
      FUN_00103d50(ppppppuVar40 + (int)ppppppuVar42 * 6 + 0x23,1,
                   (uint)ppppppuVar40[(int)ppppppuVar42 * 6 + 0x28] & 1 ^ 1);
      goto code_r0x00101d1c;
    case 0x42:
      local_17c = (int *)((int)local_17c + 1);
      dVar56 = (double)*(float *)(iVar49 + (int)local_17c * 4);
      ((void (*)())FUN_000f79c4)(ppppppuVar40,param_1,ppppppuVar42,dVar56,dVar56,dVar56,dVar56);
      goto code_r0x001025c0;
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
      ppppppuVar50 = (uint ******)
                     (PTR_s_IF_b_001dc2cc)[uVar11 * 4 + ((uint)*ppppppuVar51 >> 0x10 & 0x3fff)];
      goto switchD_00102044_default;
    case 0x4a:
      ppppppuVar50 = *(uint *******)((int)&PTR_DAT_001dc75c + ((uint)*ppppppuVar51 >> 0xe & 0xc));
switchD_00102044_default:
      in_r6 = (uint ******)local_180;
      in_r8 = ppppppuVar19;
      iVar49 = ((int (*)())FUN_000fd50c)(param_1,iVar49,&local_17c,local_180,ppppppuVar50,ppppppuVar19);
      in_r7 = ppppppuVar50;
code_r0x0010372c:
      local_bc = 0;
      break;
    case 0x4b:
      if ((((uint)*ppppppuVar51 & 0x10000) == 0) ||
         (bVar1 = true, (*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x40) != 0)) {
        bVar1 = false;
      }
      in_r7 = (uint ******)PTR_DAT_001e8b98;
      if (bVar1) {
        in_r7 = (uint ******)PTR_DAT_001e8b9c;
      }
code_r0x001022b4:
      in_r6 = (uint ******)local_180;
      in_r8 = ppppppuVar19;
      iVar49 = ((int (*)())FUN_000fd50c)(param_1,iVar49,&local_17c,local_180,in_r7,ppppppuVar19);
      goto code_r0x0010372c;
    case 0x4d:
      local_bc = 0;
      *(ushort *)((int)ppppppuVar40[0x4f] + 0x12) = (byte)((uint)*ppppppuVar51 >> 0x18) & 1;
      break;
    case 0x4e:
      ppppppuVar50 = (uint ******)
                     ((int (*)())FUN_000f8ccc)((uint)*ppppppuVar51 >> 0x10 & 7,*(undefined4 *)(param_1 + 8),0);
      goto code_r0x00101f74;
    case 0x4f:
      local_17c = (int *)((int)local_17c + 1);
      ((void (*)())FUN_001048d4)(ppppppuVar40,(double)*(float *)(iVar49 + (int)local_17c * 4));
      goto code_r0x00101d1c;
    case 0x50:
      local_17c = (int *)((int)local_17c + 1);
      ((void (*)())FUN_0010490c)(ppppppuVar40,(double)*(float *)(iVar49 + (int)local_17c * 4));
      goto code_r0x00101d1c;
    case 0x51:
      bVar4 = *(byte *)((int)param_2 + 0x8d);
      pppppuVar16 = (uint *****)(uint)bVar4;
      if ((*(uint *)((int)local_a0 + (bVar4 >> 3 & 0x1c) + 8) >> (bVar4 & 0x1f) & 1) == 0) {
        FUN_000e0e0c(*(undefined4 *)(param_1 + 8),"TextureStage %d misses DCLPT\n",pppppuVar16,in_r6
                     ,in_r7,in_r8,bVar4 & 0x1f,0);
      }
      pppppuVar54 = *(uint ******)(param_1 + 0x7c);
      if ((int)*(uint ******)(param_1 + 0x7c) < (int)pppppuVar16) {
        pppppuVar54 = pppppuVar16;
      }
      *(uint ******)(param_1 + 0x7c) = pppppuVar54;
      *(uint *)(param_1 + 0x84) = 1 << ((uint)pppppuVar16 & 0x3f) | *(uint *)(param_1 + 0x84);
      ppppppuVar40[0x4d] = pppppuVar16;
      ppppppuVar40[0x4c] = pppppuVar16;
      local_bc = 0;
      pppppuVar16 = (uint *****)
                    ((int (*)())FUN_000f89e8)(*(undefined4 *)((int)pppppuVar16 * 0xc + *(int *)(param_1 + 0x78)))
      ;
      ppppppuVar40[0x4e] = pppppuVar16;
      break;
    case 0x52:
      local_bc = 0;
      ppppppuVar40[0x4d] = (uint *****)(uint)*(byte *)((int)param_2 + 0x8d);
      ppppppuVar40[0x4c] = (uint *****)(uint)*(byte *)((int)param_2 + 0x8d);
      break;
    case 0x53:
      ppppppuVar50 = (uint ******)
                     ((int (*)())FUN_000f8ccc)((uint)*ppppppuVar51 >> 0x10 & 7,*(undefined4 *)(param_1 + 8),1);
code_r0x00101f74:
      if (ppppppuVar50 != (uint ******)0x0) goto switchD_00102044_default;
      goto switchD_0010061c_caseD_1;
    case 0x54:
      pppppuVar16 = *ppppppuVar51;
      sVar6 = *(short *)((int)*param_2[0x19] + 2);
      uVar11 = (uint)**param_2[0x19] >> 0x10 & 0x3f;
      FUN_000ec208(param_1,uVar11);
      uVar52 = *(undefined4 *)(param_1 + 0x3ac);
      uVar48 = FUN_000ec208(param_1,uVar11);
      in_r6 = (uint ******)0x0;
      iVar45 = FUN_00127608(uVar52,uVar48,(int)sVar6,0);
      if (((uint)pppppuVar16 >> 0x10 & 0x3fff) == 0) goto switchD_0010061c_caseD_1;
      local_bc = 0;
      *(undefined4 *)(iVar45 + 0x30) = 1;
      break;
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5a:
    case 0x5b:
    case 0x5c:
    case 0x5d:
      iVar45 = (&local_104)[uVar11 - 0x55];
      if (iVar45 == 0) {
        iVar45 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar45;
        (&local_104)[uVar11 - 0x55] = iVar45;
      }
      iVar20 = FUN_001054ec(ppppppuVar40,ppppppuVar42);
      *(undefined4 *)(iVar20 + 0xc) = 0;
      *(int *)(iVar20 + 8) = iVar45;
      if (ppppppuVar42 == (uint ******)0x0) {
        in_r6 = (uint ******)0x0;
        in_r7 = (uint ******)0x0;
        in_r8 = ppppppuVar40;
        ((int (*)())FUN_000f8d50)(param_1,ppppppuVar39,local_124,0,0,ppppppuVar40,0);
      }
      else {
        in_r6 = ppppppuVar42;
        in_r7 = ppppppuVar40;
        ((int (*)())FUN_000f8aa0)(param_1,&local_178,0,ppppppuVar42,ppppppuVar40);
      }
      goto code_r0x001025c0;
    case 0x60:
      puVar34 = (undefined4 *)0x0;
      uVar11 = puVar15[2] - 1;
      if (uVar11 < (uint)puVar15[2]) {
        puVar34 = (undefined4 *)(uVar11 * 4 + puVar15[3]);
      }
      if (*(int *)*puVar34 != 0) goto switchD_0010061c_caseD_1;
      piVar18 = (int *)((int)local_17c * 4 + iVar49);
      do {
        piVar38 = local_17c;
        if (*piVar18 == 0x37) {
          piVar38 = (int *)((int)local_17c + 1);
          piVar18 = piVar18 + 1;
        }
        local_17c = (int *)((int)piVar38 + 1);
        piVar18 = piVar18 + 1;
      } while (*piVar18 != 0x26);
      local_bc = 0;
      local_17c = piVar38;
      break;
    case 0x6a:
      FUN_000e1534(*(undefined4 *)(param_1 + 8),0xf);
      goto code_r0x00101d1c;
    case 0x6b:
      iVar45 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),4);
      in_r7 = (uint ******)PTR_DAT_001e8bd8;
      if (iVar45 != 0) {
        in_r7 = (uint ******)PTR_DAT_001e8bb0;
      }
      in_r8 = ppppppuVar19;
      iVar49 = ((int (*)())FUN_000fd50c)(param_1,iVar49,&local_17c,ppppppuVar12,in_r7,ppppppuVar19);
      in_r6 = ppppppuVar12;
      goto code_r0x0010372c;
    case 0x6c:
      (*(code *)(*ppppppuVar40)[9])(ppppppuVar40);
      local_bc = 0;
      ppppppuVar40[0x4b] = (uint *****)0x1;
      goto code_r0x00103b3c;
    case 0x6d:
      iVar45 = FUN_001054ec(ppppppuVar40,1);
      iVar20 = *(int *)(iVar45 + 0x10);
      iVar45 = *(int *)(local_60 + -0x2c30);
      if (iVar20 != iVar45) {
        uVar48 = *(undefined4 *)(param_1 + 0x3ac);
        in_r6 = (uint ******)0x0;
        iVar21 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar21;
        uVar48 = FUN_00127608(uVar48,0,iVar21,0);
        iVar21 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(iVar21,1,uVar48);
        pppppuVar54 = ppppppuVar40[0x25];
        pppppuVar16 = ppppppuVar40[0x26];
        iVar22 = FUN_001054ec(iVar21,0);
        *(uint ******)(iVar22 + 0xc) = pppppuVar16;
        *(uint ******)(iVar22 + 8) = pppppuVar54;
        iVar22 = FUN_001054ec(iVar21,1);
        *(int *)(iVar22 + 0x10) = iVar20;
        iVar22 = FUN_001054ec(ppppppuVar40,0);
        *(undefined4 *)(iVar21 + 0x9c) = *(undefined4 *)(iVar22 + 0x10);
        FUN_001046c8(ppppppuVar40,0,uVar48);
        FUN_000f32cc(&local_d4,iVar20);
        ppppppuVar40[0x27] = (uint *****)local_d4;
        iVar20 = FUN_001054ec(ppppppuVar40,1);
        *(int *)(iVar20 + 0x10) = iVar45;
        FUN_00193f94(local_6c,iVar21);
        goto code_r0x00101d1c;
      }
switchD_0010061c_caseD_1:
      local_bc = 0;
      break;
    case 0x6e:
      local_17c = (int *)((int)local_17c + 1);
      in_r6 = *(uint *******)(iVar49 + (int)local_17c * 4);
      in_r7 = in_r6;
      in_r8 = in_r6;
      ((int (*)())FUN_000f7870)(ppppppuVar40,param_1,ppppppuVar42,in_r6,in_r6,in_r6,in_r6);
code_r0x001025c0:
      ppppppuVar42 = (uint ******)((int)ppppppuVar42 + 1);
      local_bc = 0;
      break;
    case 0x70:
      uVar11 = local_b0[1];
      piVar18 = (int *)0x0;
      if (uVar11 - 1 < uVar11) {
        piVar18 = (int *)((uVar11 - 1) * 4 + local_b0[2]);
      }
      if (*(int *)(*piVar18 + 4) == 0) {
        puVar34 = (undefined4 *)0x0;
        uVar48 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
        if (uVar11 - 1 < local_b0[1]) {
          puVar34 = (undefined4 *)((uVar11 - 1) * 4 + local_b0[2]);
        }
        uVar52 = *puVar34;
        FUN_00194208(local_b0,local_b0[1] - 1);
        FUN_00193cc0(uVar48,uVar52);
      }
      else {
        piVar18 = (int *)0x0;
        if (uVar11 - 1 < local_b0[1]) {
          piVar18 = (int *)((uVar11 - 1) * 4 + local_b0[2]);
        }
        in_r6 = (uint ******)0x0;
        *(int *)(*piVar18 + 4) = *(int *)(*piVar18 + 4) + -1;
        local_17c = (int *)((int)local_17c + -1);
        in_r8 = ppppppuVar19;
        iVar49 = ((int (*)())FUN_000fd50c)(param_1,iVar49,&local_17c,0,ppppppuVar50,ppppppuVar19);
        in_r7 = ppppppuVar50;
      }
code_r0x00101d1c:
      local_bc = 0;
      break;
    case 0x71:
      local_bc = 0;
      ppppppuVar40[0x50] = *(uint ******)(iVar49 + ((int)local_17c + 1) * 4);
      local_17c = (int *)((int)local_17c + 1);
    }
    goto code_r0x00103b34;
  case 7:
    bVar1 = true;
  }
  ppppppuVar19 = (uint ******)((int (*)())FUN_000f9140)(param_1,iVar36,(uint)*ppppppuVar51 >> 0x10 & 0x3fff);
  ((int (*)())FUN_000f9a58)(param_1,local_6c,*param_2[0x19],ppppppuVar39,local_a4);
  sVar6 = *(short *)((int)*param_2[0x19] + 2);
  uVar48 = FUN_000ec208(param_1,(uint)**param_2[0x19] >> 0x10 & 0x3f);
  iVar45 = FUN_001054ec(ppppppuVar19,0);
  *(undefined4 *)(iVar45 + 0xc) = uVar48;
  *(int *)(iVar45 + 8) = (int)sVar6;
  in_r7 = (uint ******)0x0;
  in_r6 = (uint ******)*param_2[0x19];
  in_r8 = ppppppuVar19;
  ((int (*)())FUN_000f8d50)(param_1,ppppppuVar39,DAT_001aa9dc,in_r6,0,ppppppuVar19,0);
  iVar45 = ((int (*)())FUN_000f8970)(iVar36,*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0xc));
  ppppppuVar40 = (uint ******)(iVar45 + 1);
  if (1 < (int)ppppppuVar40) {
    ppppppuVar42 = (uint ******)((int)&MACH_HEADER.magic + 1);
    iVar45 = 0;
    local_60 = &DAT_001ad5d8;
    do {
      local_178 = *(uint *******)(local_60 + -0x2c30);
      in_r8 = (uint ******)&local_174;
      ((int (*)())FUN_000fb3d4)(param_1,local_68,ppppppuVar51,*(undefined4 *)(iVar45 + (int)param_2[0x1b]),
                   ppppppuVar39,&local_174,&local_13c);
      uVar11 = **(uint **)(iVar45 + (int)param_2[0x1b]);
      if ((((uVar11 & 0x3f0000) == 0x100000) && (*(int *)(param_1 + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar49 = 0xf;
      }
      else {
        iVar49 = (int)(short)**(uint **)(iVar45 + (int)param_2[0x1b]);
      }
      uVar48 = FUN_000ec208(param_1,uVar11 >> 0x10 & 0x3f);
      iVar20 = FUN_001054ec(ppppppuVar19,ppppppuVar42);
      *(undefined4 *)(iVar20 + 0xc) = uVar48;
      *(int *)(iVar20 + 8) = iVar49;
      if ((!bVar1) &&
         (iVar49 = FUN_0011346c(*(undefined4 *)(param_1 + 8),ppppppuVar19), iVar49 != 0)) {
        if (ppppppuVar42 == (uint ******)((int)&MACH_HEADER.magic + 1U)) {
          puVar13 = (uint *)&UNK_001aa9d4;
        }
        else {
          puVar13 = &DAT_001aa9cc;
        }
        local_178 = (uint ******)*puVar13;
      }
      in_r6 = ppppppuVar42;
      in_r7 = ppppppuVar19;
      ((int (*)())FUN_000f8aa0)(param_1,&local_178,*(undefined4 *)(iVar45 + (int)param_2[0x1b]),ppppppuVar42,
                   ppppppuVar19);
      ppppppuVar42 = (uint ******)((int)ppppppuVar42 + 1);
      iVar45 = iVar45 + 4;
    } while (ppppppuVar40 != ppppppuVar42);
  }
  local_b8 = FUN_000f3a30(ppppppuVar19);
  if (bVar1) {
    iVar20 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar20;
    pppppuVar54 = ppppppuVar19[0x25];
    pppppuVar16 = ppppppuVar19[0x26];
    iVar45 = FUN_001054ec(ppppppuVar19,0);
    *(int *)(iVar45 + 8) = iVar20;
    *(undefined4 *)(iVar45 + 0xc) = 0;
    iVar45 = FUN_0011346c(*(undefined4 *)(param_1 + 8),ppppppuVar19);
    iVar49 = FUN_001054ec(ppppppuVar19,0);
    ppppppuVar42 = *(uint *******)(iVar49 + 0x10);
    local_178 = ppppppuVar42;
    if (1 < local_b8) {
      local_7c = (uint ****)&local_188;
      iVar49 = 0;
      local_58 = local_7c;
      do {
        iVar21 = FUN_000f30d4(local_178);
        iVar22 = ((int (*)())FUN_000f9140)(param_1,iVar36,(uint)*ppppppuVar51 >> 0x10 & 0x3fff);
        ppppuVar47 = local_58;
        if (0 < (int)ppppppuVar40) {
          ppppppuVar50 = (uint ******)0x0;
          do {
            in_r6 = ppppppuVar50;
            FUN_00105e54(iVar22,ppppppuVar50,ppppppuVar19,ppppppuVar50);
            if (iVar45 != 0) {
              iVar23 = FUN_001054ec(iVar22,ppppppuVar50);
              ppppppuVar12 = *(uint *******)(iVar23 + 0x10);
              if (ppppppuVar50 == (uint ******)((int)&MACH_HEADER.magic + 1U)) {
                local_124 = (uint ******)
                            CONCAT31((int3)((uint)ppppppuVar12 >> 8),
                                     *(undefined1 *)((int)ppppuVar47 + iVar21 + 100));
              }
              else if (ppppppuVar50 == (uint ******)((int)&MACH_HEADER.magic + 2U)) {
                local_124 = (uint ******)
                            CONCAT13(*(undefined1 *)((int)ppppuVar47 + iVar21 + 100),
                                     (int3)ppppppuVar12);
              }
              else {
                local_124 = ppppppuVar12;
                if (ppppppuVar50 == (uint ******)((int)&MACH_HEADER.magic + 3U)) {
                  (*(unsigned short *)((unsigned char *)&(local_124) + 0)) = (undefined2)((uint)ppppppuVar12 >> 0x10);
                  (*(unsigned short *)((unsigned char *)&(local_124) + 2)) =
                       CONCAT11(*(undefined1 *)((int)ppppuVar47 + iVar21 + 100),(char)ppppppuVar12);
                }
              }
              ppppppuVar12 = local_124;
              iVar23 = FUN_001054ec(iVar22,ppppppuVar50);
              *(uint *******)(iVar23 + 0x10) = ppppppuVar12;
            }
            ppppppuVar50 = (uint ******)((int)ppppppuVar50 + 1);
          } while (ppppppuVar40 != ppppppuVar50);
        }
        *(undefined4 *)(iVar22 + 0x9c) = *(undefined4 *)(PTR_DAT_001e8b64 + iVar21 * 4);
        *(undefined1 *)((int)local_7c + iVar21 + 0x10) = 1;
        *(uint ******)(iVar22 + 0x120) = ppppppuVar19[0x48];
        FUN_00193f64(local_68,iVar22);
        iVar49 = iVar49 + 1;
      } while (local_b8 + -1 != iVar49);
    }
    ppppppuVar19[0x27] = (uint *****)local_178;
    if ((iVar45 != 0) && (iVar36 = FUN_000f30d4(local_178), 1 < (int)ppppppuVar40)) {
      ppppppuVar51 = (uint ******)((int)&MACH_HEADER.magic + 1);
      do {
        iVar45 = FUN_001054ec(ppppppuVar19,ppppppuVar51);
        ppppppuVar50 = *(uint *******)(iVar45 + 0x10);
        local_104 = ppppppuVar50;
        if (ppppppuVar51 == (uint ******)((int)&MACH_HEADER.magic + 1U)) {
          local_104 = (uint ******)
                      CONCAT31((int3)((uint)ppppppuVar50 >> 8),
                               *(undefined1 *)((int)&local_104 + iVar36));
        }
        else if (ppppppuVar51 == (uint ******)((int)&MACH_HEADER.magic + 2U)) {
          local_104 = (uint ******)
                      CONCAT13(*(undefined1 *)((int)&local_104 + iVar36),(int3)ppppppuVar50);
        }
        else if (ppppppuVar51 == (uint ******)((int)&MACH_HEADER.magic + 3U)) {
          (*(unsigned short *)((unsigned char *)&(local_104) + 0)) = (undefined2)((uint)ppppppuVar50 >> 0x10);
          (*(unsigned short *)((unsigned char *)&(local_104) + 2)) = CONCAT11(*(undefined1 *)((int)&local_104 + iVar36),(char)ppppppuVar50);
        }
        ppppppuVar50 = local_104;
        iVar45 = FUN_001054ec(ppppppuVar19,ppppppuVar51);
        ppppppuVar51 = (uint ******)((int)ppppppuVar51 + 1);
        *(uint *******)(iVar45 + 0x10) = ppppppuVar50;
      } while (ppppppuVar40 != ppppppuVar51);
    }
    iVar36 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar45 = FUN_001054ec(iVar36,0);
    *(uint ******)(iVar45 + 0xc) = pppppuVar16;
    *(uint ******)(iVar45 + 8) = pppppuVar54;
    *(uint *******)(iVar36 + 0x9c) = ppppppuVar42;
    iVar45 = FUN_001054ec(iVar36,1);
    *(int *)(iVar45 + 8) = iVar20;
    *(undefined4 *)(iVar45 + 0xc) = 0;
    FUN_00193f94(local_6c,iVar36);
  }
  piVar18 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
  iVar36 = (**(code **)(*piVar18 + 0x34))(piVar18,ppppppuVar19);
  if (iVar36 == 0) {
code_r0x001002dc:
    iVar36 = 0;
  }
  else {
    iVar36 = FUN_001054ec(ppppppuVar19,0);
    iVar49 = 0;
    iVar45 = 0;
    local_178 = *(uint *******)(iVar36 + 0x10);
    in_r8 = (uint ******)&local_104;
    local_104 = *(uint *******)(iVar36 + 0x10);
    iVar20 = 4;
    in_r7 = (uint ******)&local_178;
    iVar36 = -1;
    do {
      iVar21 = iVar36;
      if (*(char *)(iVar45 + (int)in_r8) == '\0') {
        iVar21 = iVar45;
        if ((iVar49 != 0) && (iVar21 = iVar36, 0 < iVar49)) {
          *(undefined1 *)(iVar45 + (int)in_r7) = 1;
        }
        iVar49 = iVar49 + 1;
      }
      iVar45 = iVar45 + 1;
      iVar20 = iVar20 + -1;
      iVar36 = iVar21;
    } while (iVar20 != 0);
    if (iVar49 < 2) goto code_r0x001002dc;
    iVar45 = 4;
    ppppppuVar19[0x27] = (uint *****)local_178;
    iVar36 = 0;
    in_r7 = (uint ******)&local_124;
    do {
      *(char *)(iVar36 + (int)in_r7) = (char)iVar21;
      iVar36 = iVar36 + 1;
      iVar45 = iVar45 + -1;
    } while (iVar45 != 0);
    iVar36 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    pppppuVar16 = ppppppuVar19[0x25];
    pppppuVar54 = ppppppuVar19[0x26];
    iVar45 = FUN_001054ec(iVar36,0);
    *(uint ******)(iVar45 + 0xc) = pppppuVar54;
    *(uint ******)(iVar45 + 8) = pppppuVar16;
    pppppuVar16 = ppppppuVar19[0x25];
    *(uint *******)(iVar36 + 0x9c) = local_104;
    pppppuVar54 = ppppppuVar19[0x26];
    iVar45 = FUN_001054ec(iVar36,1);
    ppppppuVar51 = local_124;
    *(uint ******)(iVar45 + 0xc) = pppppuVar54;
    *(uint ******)(iVar45 + 8) = pppppuVar16;
    iVar45 = FUN_001054ec(iVar36,1);
    *(uint *******)(iVar45 + 0x10) = ppppppuVar51;
  }
  iVar49 = *(int *)(local_14c + 8);
  iVar45 = local_14c;
  while (iVar20 = iVar49, iVar20 != 0) {
    FUN_0019401c(iVar45);
    ((int (*)())FUN_000f92fc)(param_1,iVar45,local_180);
    iVar45 = iVar20;
    iVar49 = *(int *)(iVar20 + 8);
  }
  ((int (*)())FUN_000f92fc)(param_1,ppppppuVar19,local_180);
  if (iVar36 != 0) {
    ((int (*)())FUN_000f92fc)(param_1,iVar36,local_180);
  }
  iVar45 = *(int *)(local_164 + 8);
  iVar36 = local_164;
  while (iVar49 = iVar45, iVar49 != 0) {
    FUN_0019401c(iVar36);
    ((int (*)())FUN_000f92fc)(param_1,iVar36,local_180);
    iVar36 = iVar49;
    iVar45 = *(int *)(iVar49 + 8);
  }
  goto switchD_000fdaf0_caseD_2;
switchD_0010061c_caseD_0:
  local_bc = 1;
code_r0x00103b34:
  if (ppppppuVar40 != (uint ******)0x0) {
code_r0x00103b3c:
    iVar45 = (*(code *)(*ppppppuVar40)[5])(ppppppuVar40);
    if ((uint ******)(iVar45 + 1U) == ppppppuVar42) {
      ((int (*)())FUN_000f92fc)(param_1,ppppppuVar40,local_180);
      ppppppuVar40 = (uint ******)0x0;
      ppppppuVar42 = (uint ******)0x0;
      local_178 = *(uint *******)(local_60 + -0x2c30);
      local_124 = *(uint *******)(local_78 + -0x2bfc);
    }
  }
  if (local_bc != 0) goto code_r0x00103bb0;
  local_17c = (int *)((int)local_17c + 1);
  goto code_r0x001005f4;
code_r0x00103bb0:
  iVar45 = *(int *)(local_164 + 8);
  iVar36 = local_164;
  while (iVar49 = iVar45, iVar49 != 0) {
    FUN_0019401c(iVar36);
    ((int (*)())FUN_000f92fc)(param_1,iVar36,local_180);
    iVar36 = iVar49;
    iVar45 = *(int *)(iVar49 + 8);
  }
  if (puVar13 != (uint *)0x0) {
    FUN_00193cc0(puVar15[4],puVar15[3]);
    FUN_00193cc0(*puVar15,puVar15);
  }
  if (ppppppuVar19 != (uint ******)0x0) {
    FUN_00193cc0(puVar24[4],puVar24[3]);
    FUN_00193cc0(*puVar24,puVar24);
  }
  goto switchD_000fdaf0_caseD_2;
}

