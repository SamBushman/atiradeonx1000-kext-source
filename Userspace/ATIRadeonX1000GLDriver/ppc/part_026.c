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
  unsigned int frame_[120] __attribute__((aligned(16)));
  
  _memcpy(((int *)((char *)frame_ + 136)),&DAT_001aa87c,300);
  cVar1 = *(char *)(param_3 + 0x15c);
  puVar9 = ((undefined4 *)((char *)frame_ + 40));
  puVar11 = ((uint *)((char *)frame_ + 8));
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
  ((undefined4 *)((char *)frame_ + 24))[0] = *(undefined4 *)(param_1 + 8);
  ((undefined4 *)((char *)frame_ + 24))[1] = *(undefined4 *)(param_1 + 0xc);
  ((undefined4 *)((char *)frame_ + 24))[2] = *(undefined4 *)(param_1 + 0x10);
  ((undefined4 *)((char *)frame_ + 24))[3] = *(undefined4 *)(param_1 + 0x14);
  if (*(int *)(&DAT_001aa86c + (4 - param_2) * 4) < 0xf) {
    piVar12 = ((int *)((char *)frame_ + 136)) + *(int *)(&DAT_001aa86c + (4 - param_2) * 4) * 5;
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
          uVar7 = ((undefined4 *)((char *)frame_ + 40))[iVar3 * 6];
          *(undefined4 *)(iVar10 + 0x20) = ((undefined4 *)((char *)frame_ + 40))[iVar3 * 6 + 1];
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
      FUN_00194d44(((undefined4 *)((char *)frame_ + 24))[iVar10],param_3);
    } while (piVar12 != ((int *)((char *)frame_ + 436)));
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
  /* issue #64 live-repro: same defect as FUN_000f6248 in this file (fixed earlier this session) -
   * called below as ((int *)((char *)frame_ + 4))[param_2] with param_2 observed as 4, one past this array's declared
   * 4 elements; local_8c (assigned right after, from param_1[5]) sits exactly at the missing 5th
   * index by its own hex offset (0x9c-0x8c=0x10). Extended to 5 elements; local_8c aliased to
   * index 4. */
#define local_8c ((int *)((char *)frame_ + 4))[4]
  unsigned int frame_[40] __attribute__((aligned(16)));
  
  ((int *)((char *)frame_ + 4))[1] = param_1[2];
  ((int *)((char *)frame_ + 4))[2] = param_1[3];
  iVar9 = 4;
  iVar7 = 0;
  uVar8 = 0;
  ((undefined4 *)((char *)frame_ + 24))[0] = param_3;
  ((undefined4 *)((char *)frame_ + 24))[1] = param_4;
  ((int *)((char *)frame_ + 4))[3] = param_1[4];
  local_8c = param_1[5];
  puVar6 = ((undefined4 *)((char *)frame_ + 24));
  do {
    if ((int)uVar8 < param_2) {
      *(byte *)(param_1[10] + 0x15c) = (byte)(1 << (uVar8 & 0x3f)) | *(byte *)(param_1[10] + 0x15c);
      uVar1 = *(undefined4 *)((int)puVar6 + iVar7);
      iVar2 = iVar7 + 0x10 + param_1[10];
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)((int)((undefined4 *)((char *)frame_ + 24)) + iVar7 + 4);
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
  puVar3 = (undefined4 *)FUN_00194834(((int *)((char *)frame_ + 4))[param_2],param_1[10]);
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
      uVar1 = FUN_000f4a84(param_1,((undefined4 *)((char *)frame_ + 24))[0],0,puVar6,iVar7,uVar8,*param_1);
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
        uVar1 = *(undefined4 *)((int)((undefined4 *)((char *)frame_ + 24)) + iVar7);
        puVar6[4] = *(undefined4 *)((int)((undefined4 *)((char *)frame_ + 24)) + iVar7 + 4);
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
#undef local_8c

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
  return ((int (*)())FUN_000f4fdc)(param_1,3,param_2,param_3,param_4,param_5,param_6,param_7);
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
  return ((int (*)())FUN_000f4fdc)(param_1,2,param_2,param_3,param_4,param_5,param_6,param_7);
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
  return ((int (*)())FUN_000f4fdc)(param_1,1,param_2,param_3,param_4,param_5,param_6,param_7);
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
  unsigned int frame_[16] __attribute__((aligned(16)));
  
  if (param_1[7] != 0) {
    uVar8 = 0;
    do {
      puVar9 = (uint *)param_1[8];
      if (uVar8 < *puVar9) {
        uVar4 = puVar9[1];
        if (uVar4 <= uVar8) {
          _memset(uVar4 * 4 + puVar9[2],0,(uVar8 - uVar4) * 4 + 4);
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
      ((undefined4 *)((char *)frame_ + 8))[0] = *(undefined4 *)param_3;
      pcVar7 = param_3;
      do {
        uVar4 = (uint)*(byte *)((int)((undefined4 *)((char *)frame_ + 8)) + iVar6);
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
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  uint uVar1;
  int *a0;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  unsigned int frame_[16] __attribute__((aligned(16)));
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  a0 = (int *)FUN_00105594(param_1,param_2);
  iVar2 = (**(code **)(*a0 + 0x48))(a0);
  if (iVar2 == 0) {
LAB_000f5cd8:
    uVar3 = 0;
  }
  else {
    iVar2 = FUN_001054ec(param_1,param_2);
    iVar4 = 0;
    pcVar5 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
    ((undefined4 *)((char *)frame_ + 8))[0] = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = 4;
    do {
      if (((*pcVar5 == '\0') && (uVar1 = (uint)*(byte *)((int)((undefined4 *)((char *)frame_ + 8)) + iVar4), uVar1 < 4)) &&
         ((((int)*(char *)(a0 + 0x57) >> (uVar1 & 0x3f) & 1U) == 0 ||
          (a0[uVar1 * 6 + 8] != *param_4)))) goto LAB_000f5cd8;
      iVar4 = iVar4 + 1;
      pcVar5 = pcVar5 + 1;
      param_4 = param_4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    uVar3 = 1;
  }
  return uVar3;
}

/* FUN_000f5cf0 @ 0xf5cf0 (412 bytes) */
int FUN_000f5cf0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int *param_4;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool bVar1;
  int *a0;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  unsigned int frame_[20] __attribute__((aligned(16)));
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  a0 = (int *)FUN_00105594(param_1,param_2);
  iVar2 = (**(code **)(*a0 + 0x48))(a0);
  if (iVar2 != 0) {
    iVar2 = FUN_001054ec(param_1,param_2);
    bVar1 = false;
    iVar3 = 0;
    pcVar4 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
    (*(undefined4 *)((char *)frame_ + 8)) = *(undefined4 *)(iVar2 + 0x10);
    iVar2 = 4;
    do {
      if ((*pcVar4 == '\0') && (uVar5 = (uint)*(byte *)((int)&(*(undefined4 *)((char *)frame_ + 8)) + iVar3), uVar5 < 4)) {
        (*(int *)((char *)frame_ + 16)) = a0[uVar5 * 6 + 8];
        (*(int *)((char *)frame_ + 20)) = a0[uVar5 * 6 + 9];
        (*(int *)((char *)frame_ + 24)) = a0[uVar5 * 6 + 10];
        (*(int *)((char *)frame_ + 12)) = a0[uVar5 * 6 + 7];
        (*(int *)((char *)frame_ + 32)) = a0[uVar5 * 6 + 0xc];
        (*(int *)((char *)frame_ + 28)) = a0[uVar5 * 6 + 0xb];
        if (a0[uVar5 * 6 + 7] != 2) {
          return 0;
        }
        if (((int)*(char *)(a0 + 0x57) >> (uVar5 & 0x3f) & 1U) == 0) {
          return 0;
        }
        if (bVar1) {
          if (*param_4 != 2) {
            return 0;
          }
          if ((*(int *)((char *)frame_ + 16)) != param_4[1]) {
            return 0;
          }
          bVar1 = true;
        }
        else {
          bVar1 = true;
          *param_4 = 2;
          param_4[1] = (*(int *)((char *)frame_ + 16));
        }
      }
      iVar3 = iVar3 + 1;
      pcVar4 = pcVar4 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    if (bVar1) {
      if (((*(uint *)(param_2 * 0x18 + param_1 + 0xa0) & 2) != 0) && (GH_U2F((unsigned int)(param_4[1])) < 0.0)) {
        param_4[1] = (int)GH_F2U((float)(-GH_U2F((unsigned int)(param_4[1]))));
      }
      if ((*(uint *)(param_2 * 0x18 + param_1 + 0xa0) & 1) != 0) {
        param_4[1] = (int)GH_F2U((float)(-GH_U2F((unsigned int)(param_4[1]))));
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
  int *a0;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  unsigned int frame_[16] __attribute__((aligned(16)));
  
  a0 = (int *)FUN_00105594(param_1,param_2);
  iVar1 = (**(code **)(*a0 + 0x48))(a0);
  if (iVar1 == 0) {
LAB_000f5f7c:
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_001054ec(param_1,param_2);
    iVar3 = 0;
    (*(undefined4 *)((char *)frame_ + 8)) = *(undefined4 *)(iVar1 + 0x10);
    iVar1 = 4;
    do {
      uVar4 = (uint)*(byte *)((int)&(*(undefined4 *)((char *)frame_ + 8)) + iVar3);
      if (uVar4 < 4) {
        (*(float *)((char *)frame_ + 16)) = GH_U2F((unsigned int)(a0[uVar4 * 6 + 8]));
        (*(int *)((char *)frame_ + 20)) = a0[uVar4 * 6 + 9];
        (*(int *)((char *)frame_ + 24)) = a0[uVar4 * 6 + 10];
        (*(int *)((char *)frame_ + 12)) = a0[uVar4 * 6 + 7];
        (*(int *)((char *)frame_ + 32)) = a0[uVar4 * 6 + 0xc];
        (*(int *)((char *)frame_ + 28)) = a0[uVar4 * 6 + 0xb];
        if (((a0[uVar4 * 6 + 7] != 2) || (((int)*(char *)(a0 + 0x57) >> (uVar4 & 0x3f) & 1U) == 0))
           || (GH_U2F((unsigned int)(a0[uVar4 * 6 + 8])) < 0.0)) goto LAB_000f5f7c;
      }
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    uVar2 = 1;
  }
  return uVar2;
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
          _memset(uVar1 * 4 + puVar8[2],0,(uVar7 - uVar1) * 4 + 4);
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
  unsigned int frame_[48] __attribute__((aligned(16)));
  
  puVar10 = *(uint **)(param_1 + 0x3c8);
  uVar2 = puVar10[1];
  uVar7 = 0;
  if (uVar2 != 0) {
    do {
      if (uVar7 < *puVar10) {
        if (uVar2 <= uVar7) {
          _memset(uVar2 * 4 + puVar10[2],0,(uVar7 - uVar2) * 4 + 4);
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
          puVar6 = ((undefined1 *)((char *)frame_ + 8));
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
  /* issue #64 live-repro: called below as ((undefined4 *)((char *)frame_ + 4))[param_2] with param_2 observed as 4 - one
   * past this array's declared 4 elements (indices 0-3). Confirmed in stock's own disassembly: the
   * word this 5th index reads (entry-sp-0x8c+0x10, by this array's own hex name) is the exact same
   * stack slot as local_7c (entry-sp-0x7c), which the very next line fills with a real value
   * (*(param_1+0x14)) - stock never writes a separate word for index 0 either (genuinely padding/
   * unused there), so this is the same locals-that-must-be-contiguous defect as elsewhere this
   * session, just one array cell short instead of a raw address. Left separate, ((undefined4 *)((char *)frame_ + 4))[4] read
   * whatever unrelated word happened to follow it on this build's stack instead of local_7c's real
   * value, corrupting a callback-table lookup several frames down (FUN_00194834 called through a
   * garbage function pointer, jumping into stack memory as code). Extended to 5 elements; local_7c
   * aliased to index 4 so both names reach the same word. */
#define local_7c ((undefined4 *)((char *)frame_ + 4))[4]
  unsigned int frame_[36] __attribute__((aligned(16)));
  
  ((undefined4 *)((char *)frame_ + 4))[1] = *(undefined4 *)(param_1 + 8);
  ((undefined4 *)((char *)frame_ + 4))[2] = *(undefined4 *)(param_1 + 0xc);
  iVar7 = 4;
  iVar4 = 0;
  uVar5 = 0;
  ((undefined4 *)((char *)frame_ + 24))[0] = param_3;
  ((undefined4 *)((char *)frame_ + 24))[1] = param_4;
  ((undefined4 *)((char *)frame_ + 4))[3] = *(undefined4 *)(param_1 + 0x10);
  local_7c = *(undefined4 *)(param_1 + 0x14);
  do {
    if ((int)uVar5 < param_2) {
      *(byte *)(*(int *)(param_1 + 0x28) + 0x15c) =
           (byte)(1 << (uVar5 & 0x3f)) | *(byte *)(*(int *)(param_1 + 0x28) + 0x15c);
      uVar1 = *(undefined4 *)((int)((undefined4 *)((char *)frame_ + 24)) + iVar4);
      iVar2 = iVar4 + 0x10 + *(int *)(param_1 + 0x28);
      *(undefined4 *)(iVar2 + 0x10) = *(undefined4 *)((int)((undefined4 *)((char *)frame_ + 24)) + iVar4 + 4);
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
  iVar4 = FUN_00194834(((undefined4 *)((char *)frame_ + 4))[param_2],*(undefined4 *)(param_1 + 0x28));
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
        uVar1 = *(undefined4 *)((int)((undefined4 *)((char *)frame_ + 24)) + iVar2);
        *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)((int)((undefined4 *)((char *)frame_ + 24)) + iVar2 + 4);
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
#undef local_7c

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
  return ((int (*)())FUN_000f6248)(param_1,3,param_2,param_3,param_4,param_5,param_6,param_7);
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
  return ((int (*)())FUN_000f6248)(param_1,2,param_2,param_3,param_4,param_5,param_6,param_7);
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
  return ((int (*)())FUN_000f6248)(param_1,1,param_2,param_3,param_4,param_5,param_6,param_7);
}

/* FUN_000f6a04 @ 0xf6a04 (588 bytes) */
int FUN_000f6a04(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
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
  unsigned int frame_[40] __attribute__((aligned(16)));
  
  puVar10 = (undefined4 *)0x0;
  iVar9 = *(int *)(param_1 + 8);
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  iVar2 = (**(code **)(**(int **)(iVar9 + 0x30c) + 0xe8))
                    (*(int **)(iVar9 + 0x30c),param_2,&(*(int *)((char *)frame_ + 8)),param_3,iVar9);
  if (iVar2 != 0) {
    FUN_000f4a24(param_2,((int *)((char *)frame_ + 12)));
    iVar2 = *(int *)(param_1 + 0x3ac);
    uVar13 = 0;
    uVar11 = *(uint *)(*(int *)(iVar2 + 0x18) + 4);
    if (0 < (int)uVar11) {
      while( true ) {
        puVar14 = *(uint **)(iVar2 + 0x18);
        if (uVar13 < *puVar14) {
          uVar3 = puVar14[1];
          if (uVar3 <= uVar13) {
            _memset(uVar3 * 4 + puVar14[2],0,(uVar13 - uVar3) * 4 + 4);
            puVar14[1] = uVar13 + 1;
          }
          piVar5 = (int *)(uVar13 * 4 + puVar14[2]);
        }
        else {
          piVar5 = (int *)FUN_0019423c(puVar14,uVar13);
        }
        puVar10 = (undefined4 *)*piVar5;
        if (puVar10[0x4b] == (*(int *)((char *)frame_ + 8))) {
          pcVar7 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
          puVar6 = puVar10 + 4;
          iVar8 = 0;
          iVar2 = 4;
          while ((*pcVar7 == '\x04' ||
                 ((puVar6[3] == *(int *)((int)((int *)((char *)frame_ + 12)) + iVar8) &&
                  (puVar6[4] == *(int *)((int)((int *)((char *)frame_ + 12)) + iVar8 + 4)))))) {
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
    puVar10[0x4b] = (*(int *)((char *)frame_ + 8));
    puVar14 = *(uint **)(*(int *)(param_1 + 0x3ac) + 0x18);
    uVar11 = puVar14[1];
    if (uVar11 < *puVar14) {
      _memset(uVar11 * 4 + puVar14[2],0,4);
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
      puVar1 = (undefined4 *)((int)((int *)((char *)frame_ + 12)) + iVar2);
      uVar4 = *(undefined4 *)((int)((int *)((char *)frame_ + 12)) + iVar2 + 4);
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
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
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
  unsigned int frame_[164] __attribute__((aligned(16)));
  
  uVar13 = *(undefined4 *)(param_2 + 8);
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  (*(int *)((unsigned char *)ghidra_home + 12)) = param_4;
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = param_5;
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = param_6;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = param_7;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = param_8;
  if ((((param_4 == 2) && (param_10 == 2)) && (param_16 == 2)) && (param_22 == 2)) {
    iVar15 = 4;
    ppiVar5 = ((int * *)((char *)frame_ + 32)) + 7;
    do {
      *ppiVar5 = (int *)0x7ffffffe;
      ppiVar5 = ppiVar5 + 1;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
    ((int * *)((char *)frame_ + 32))[8] = (int *)param_11;
    ((int * *)((char *)frame_ + 32))[9] = (int *)param_17;
    ((int * *)((char *)frame_ + 32))[7] = (int *)param_5;
    iVar15 = ((int (*)())FUN_000f6a04)(param_2,((int * *)((char *)frame_ + 32)) + 7,DAT_001aa868);
    if (iVar15 != 0) {
      if ((*(uint *)(param_2 + 0x30) & 8) == 0) {
        FUN_001046c8(param_1,(*(unsigned int *)((unsigned char *)ghidra_home + 8)),*(undefined4 *)(iVar15 + 0x8c));
      }
      else {
        FUN_00106004(param_1,(*(unsigned int *)((unsigned char *)ghidra_home + 8)),iVar15,*(uint *)(param_2 + 0x30) >> 7 & 1,uVar13);
      }
      iVar6 = FUN_001054ec(iVar15,0);
      (*(int *)((char *)frame_ + 8)) = *(int *)(iVar6 + 0x10);
      if ((*(int *)((char *)frame_ + 8)) != DAT_001aa860) {
        iVar6 = 0;
        do {
          iVar7 = FUN_001054ec(param_1,(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
          if (*(byte *)(iVar6 + iVar7 + 0x10) < 4) {
            iVar7 = FUN_001054ec(param_1,(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
            uVar3 = (uint)*(byte *)(iVar6 + iVar7 + 0x10);
            ((undefined1 *)((char *)frame_ + 12))[uVar3 - 4] = 0;
            *(byte *)(iVar15 + uVar3 + 0xc) =
                 (byte)(1 << (uVar3 & 0x3f)) | *(byte *)(iVar15 + uVar3 + 0xc);
          }
          bVar14 = iVar6 != 3;
          iVar6 = iVar6 + 1;
        } while (bVar14);
        *(int *)(iVar15 + 0x9c) = (*(int *)((char *)frame_ + 8));
      }
      return;
    }
  }
  piVar9 = &(*(unsigned int *)((unsigned char *)ghidra_home + 12));
  (*(undefined4 *)((char *)frame_ + 20)) = DAT_001aa868;
  ((int * *)((char *)frame_ + 32))[0] = &param_10;
  ppiVar5 = &(*(int * *)((char *)frame_ + 28));
  iVar15 = 0;
  ((int * *)((char *)frame_ + 32))[1] = &param_16;
  ((int * *)((char *)frame_ + 32))[2] = &param_22;
  ((int * *)((char *)frame_ + 32))[6] = (int *)PTR_DAT_001e8b70;
  (*(int * *)((char *)frame_ + 28)) = piVar9;
  ((int * *)((char *)frame_ + 32))[3] = (int *)PTR_DAT_001e8b70;
  ((int * *)((char *)frame_ + 32))[4] = (int *)PTR_DAT_001e8b70;
  ((int * *)((char *)frame_ + 32))[5] = (int *)PTR_DAT_001e8b70;
  iVar6 = 0;
LAB_000f6f18:
  do {
    iVar7 = iVar6;
    *(char *)((int)&(*(undefined4 *)((char *)frame_ + 20)) + iVar15) = (char)iVar7;
    iVar6 = iVar7 + 1;
    ((int * *)((char *)frame_ + 32))[iVar7 + 3] = piVar9;
LAB_000f6f58:
    iVar4 = 4 - iVar15;
    do {
      iVar11 = iVar15;
      iVar15 = iVar11 + 1;
      ppiVar5 = ppiVar5 + 1;
      iVar4 = iVar4 + -1;
      if (iVar4 == 0) {
        (*(undefined4 *)((char *)frame_ + 24)) = DAT_001aa868;
        if (0 < iVar6) {
          do {
            iVar11 = iVar7 + 1;
            iVar4 = 0;
            iVar15 = 0;
            ppiVar5 = ((int * *)((char *)frame_ + 32)) + 4;
            if (iVar7 < 0) {
              iVar11 = 1;
            }
            while (iVar11 = iVar11 + -1, iVar11 != 0) {
              puVar12 = (uint *)ppiVar5[-1];
              puVar10 = (uint *)*ppiVar5;
              uVar3 = *puVar12;
              if (uVar3 == *puVar10) {
                if (uVar3 == 2) {
                  bVar14 = GH_U2F((unsigned int)(puVar12[1])) < GH_U2F((unsigned int)(puVar10[1]));
                }
                else {
                  bVar14 = puVar12[1] < puVar10[1];
                }
              }
              else {
                bVar14 = uVar3 < *puVar10;
              }
              if (bVar14) {
                uVar2 = *(undefined1 *)((int)&(*(undefined4 *)((char *)frame_ + 24)) + iVar4);
                uVar1 = *(undefined1 *)((int)&(*(undefined4 *)((char *)frame_ + 24)) + iVar15 + 1);
                *ppiVar5 = (int *)puVar12;
                *(undefined1 *)((int)&(*(undefined4 *)((char *)frame_ + 24)) + iVar15 + 1) = uVar2;
                ppiVar5[-1] = (int *)puVar10;
                *(undefined1 *)((int)&(*(undefined4 *)((char *)frame_ + 24)) + iVar4) = uVar1;
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
            ((undefined1 *)((char *)frame_ + 12))[*(byte *)((int)&(*(undefined4 *)((char *)frame_ + 24)) + iVar7)] = (char)iVar7;
            iVar7 = iVar7 + 1;
            iVar15 = iVar15 + -1;
          } while (iVar15 != 0);
        }
        iVar15 = 0;
        iVar7 = 4;
        do {
          *(undefined1 *)((int)&(*(undefined4 *)((char *)frame_ + 16)) + iVar15) =
               ((undefined1 *)((char *)frame_ + 12))[*(byte *)((int)&(*(undefined4 *)((char *)frame_ + 20)) + iVar15)];
          iVar15 = iVar15 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        uVar3 = *(uint *)(param_2 + 0x30);
        if ((uVar3 & 8) == 0) {
          if (iVar6 == 2) {
            (*(undefined4 *)((char *)frame_ + 76)) = *((int * *)((char *)frame_ + 32))[3];
            (*(undefined4 *)((char *)frame_ + 80)) = ((int * *)((char *)frame_ + 32))[3][1];
            (*(undefined4 *)((char *)frame_ + 84)) = ((int * *)((char *)frame_ + 32))[3][2];
            (*(undefined4 *)((char *)frame_ + 88)) = ((int * *)((char *)frame_ + 32))[3][3];
            (*(undefined4 *)((char *)frame_ + 96)) = ((int * *)((char *)frame_ + 32))[3][5];
            (*(undefined4 *)((char *)frame_ + 92)) = ((int * *)((char *)frame_ + 32))[3][4];
            (*(undefined4 *)((char *)frame_ + 532)) = *((int * *)((char *)frame_ + 32))[4];
            (*(undefined4 *)((char *)frame_ + 536)) = ((int * *)((char *)frame_ + 32))[4][1];
            (*(undefined4 *)((char *)frame_ + 540)) = ((int * *)((char *)frame_ + 32))[4][2];
            (*(undefined4 *)((char *)frame_ + 544)) = ((int * *)((char *)frame_ + 32))[4][3];
            (*(undefined4 *)((char *)frame_ + 552)) = ((int * *)((char *)frame_ + 32))[4][5];
            (*(undefined4 *)((char *)frame_ + 548)) = ((int * *)((char *)frame_ + 32))[4][4];
            uVar13 = ((int (*)())FUN_000f6760)(*(undefined4 *)(param_2 + 0x3ac),(*(undefined4 *)((char *)frame_ + 76)),(*(undefined4 *)((char *)frame_ + 80)),(*(undefined4 *)((char *)frame_ + 84)),
                                  (*(undefined4 *)((char *)frame_ + 88)),(*(undefined4 *)((char *)frame_ + 92)),(*(undefined4 *)((char *)frame_ + 96)),(*(undefined4 *)((char *)frame_ + 532)));
          }
          else if (iVar6 < 3) {
            if (iVar6 == 1) {
              (*(undefined4 *)((char *)frame_ + 100)) = *((int * *)((char *)frame_ + 32))[3];
              (*(undefined4 *)((char *)frame_ + 104)) = ((int * *)((char *)frame_ + 32))[3][1];
              (*(undefined4 *)((char *)frame_ + 108)) = ((int * *)((char *)frame_ + 32))[3][2];
              (*(undefined4 *)((char *)frame_ + 112)) = ((int * *)((char *)frame_ + 32))[3][3];
              (*(undefined4 *)((char *)frame_ + 120)) = ((int * *)((char *)frame_ + 32))[3][5];
              (*(undefined4 *)((char *)frame_ + 116)) = ((int * *)((char *)frame_ + 32))[3][4];
              uVar13 = ((int (*)())FUN_000f68c0)(*(undefined4 *)(param_2 + 0x3ac),(*(undefined4 *)((char *)frame_ + 100)),(*(undefined4 *)((char *)frame_ + 104)),(*(undefined4 *)((char *)frame_ + 108)),
                                    (*(undefined4 *)((char *)frame_ + 112)),(*(undefined4 *)((char *)frame_ + 116)),(*(undefined4 *)((char *)frame_ + 120)));
            }
            else {
LAB_000f73f0:
              uVar13 = 0;
            }
          }
          else if (iVar6 == 3) {
            (*(undefined4 *)((char *)frame_ + 508)) = *((int * *)((char *)frame_ + 32))[3];
            (*(undefined4 *)((char *)frame_ + 512)) = ((int * *)((char *)frame_ + 32))[3][1];
            (*(undefined4 *)((char *)frame_ + 516)) = ((int * *)((char *)frame_ + 32))[3][2];
            (*(undefined4 *)((char *)frame_ + 520)) = ((int * *)((char *)frame_ + 32))[3][3];
            (*(undefined4 *)((char *)frame_ + 528)) = ((int * *)((char *)frame_ + 32))[3][5];
            (*(undefined4 *)((char *)frame_ + 524)) = ((int * *)((char *)frame_ + 32))[3][4];
            (*(undefined4 *)((char *)frame_ + 488)) = ((int * *)((char *)frame_ + 32))[4][1];
            (*(undefined4 *)((char *)frame_ + 492)) = ((int * *)((char *)frame_ + 32))[4][2];
            (*(undefined4 *)((char *)frame_ + 496)) = ((int * *)((char *)frame_ + 32))[4][3];
            (*(undefined4 *)((char *)frame_ + 484)) = *((int * *)((char *)frame_ + 32))[4];
            (*(undefined4 *)((char *)frame_ + 504)) = ((int * *)((char *)frame_ + 32))[4][5];
            (*(undefined4 *)((char *)frame_ + 500)) = ((int * *)((char *)frame_ + 32))[4][4];
            (*(undefined4 *)((char *)frame_ + 468)) = ((int * *)((char *)frame_ + 32))[5][2];
            (*(undefined4 *)((char *)frame_ + 472)) = ((int * *)((char *)frame_ + 32))[5][3];
            (*(undefined4 *)((char *)frame_ + 460)) = *((int * *)((char *)frame_ + 32))[5];
            (*(undefined4 *)((char *)frame_ + 464)) = ((int * *)((char *)frame_ + 32))[5][1];
            (*(undefined4 *)((char *)frame_ + 480)) = ((int * *)((char *)frame_ + 32))[5][5];
            (*(undefined4 *)((char *)frame_ + 476)) = ((int * *)((char *)frame_ + 32))[5][4];
            uVar13 = ((int (*)())FUN_000f65d4)(*(undefined4 *)(param_2 + 0x3ac),(*(undefined4 *)((char *)frame_ + 508)),(*(undefined4 *)((char *)frame_ + 512)),(*(undefined4 *)((char *)frame_ + 516)),
                                  (*(undefined4 *)((char *)frame_ + 520)),(*(undefined4 *)((char *)frame_ + 524)),(*(undefined4 *)((char *)frame_ + 528)),(*(undefined4 *)((char *)frame_ + 484)));
          }
          else {
            if (iVar6 != 4) goto LAB_000f73f0;
            (*(undefined4 *)((char *)frame_ + 436)) = *((int * *)((char *)frame_ + 32))[3];
            (*(undefined4 *)((char *)frame_ + 440)) = ((int * *)((char *)frame_ + 32))[3][1];
            (*(undefined4 *)((char *)frame_ + 444)) = ((int * *)((char *)frame_ + 32))[3][2];
            (*(undefined4 *)((char *)frame_ + 448)) = ((int * *)((char *)frame_ + 32))[3][3];
            (*(undefined4 *)((char *)frame_ + 456)) = ((int * *)((char *)frame_ + 32))[3][5];
            (*(undefined4 *)((char *)frame_ + 452)) = ((int * *)((char *)frame_ + 32))[3][4];
            (*(undefined4 *)((char *)frame_ + 416)) = ((int * *)((char *)frame_ + 32))[4][1];
            (*(undefined4 *)((char *)frame_ + 420)) = ((int * *)((char *)frame_ + 32))[4][2];
            (*(undefined4 *)((char *)frame_ + 424)) = ((int * *)((char *)frame_ + 32))[4][3];
            (*(undefined4 *)((char *)frame_ + 412)) = *((int * *)((char *)frame_ + 32))[4];
            (*(undefined4 *)((char *)frame_ + 432)) = ((int * *)((char *)frame_ + 32))[4][5];
            (*(undefined4 *)((char *)frame_ + 428)) = ((int * *)((char *)frame_ + 32))[4][4];
            (*(undefined4 *)((char *)frame_ + 396)) = ((int * *)((char *)frame_ + 32))[5][2];
            (*(undefined4 *)((char *)frame_ + 400)) = ((int * *)((char *)frame_ + 32))[5][3];
            (*(undefined4 *)((char *)frame_ + 388)) = *((int * *)((char *)frame_ + 32))[5];
            (*(undefined4 *)((char *)frame_ + 392)) = ((int * *)((char *)frame_ + 32))[5][1];
            (*(undefined4 *)((char *)frame_ + 408)) = ((int * *)((char *)frame_ + 32))[5][5];
            (*(undefined4 *)((char *)frame_ + 404)) = ((int * *)((char *)frame_ + 32))[5][4];
            (*(undefined4 *)((char *)frame_ + 220)) = *((int * *)((char *)frame_ + 32))[6];
            (*(undefined4 *)((char *)frame_ + 224)) = ((int * *)((char *)frame_ + 32))[6][1];
            (*(undefined4 *)((char *)frame_ + 228)) = ((int * *)((char *)frame_ + 32))[6][2];
            (*(undefined4 *)((char *)frame_ + 232)) = ((int * *)((char *)frame_ + 32))[6][3];
            (*(undefined4 *)((char *)frame_ + 240)) = ((int * *)((char *)frame_ + 32))[6][5];
            (*(undefined4 *)((char *)frame_ + 236)) = ((int * *)((char *)frame_ + 32))[6][4];
            uVar13 = ((int (*)())FUN_000f645c)(*(undefined4 *)(param_2 + 0x3ac),(*(undefined4 *)((char *)frame_ + 436)),(*(undefined4 *)((char *)frame_ + 440)),(*(undefined4 *)((char *)frame_ + 444)),
                                  (*(undefined4 *)((char *)frame_ + 448)),(*(undefined4 *)((char *)frame_ + 452)),(*(undefined4 *)((char *)frame_ + 456)),(*(undefined4 *)((char *)frame_ + 412)));
          }
          FUN_001046c8(param_1,(*(unsigned int *)((unsigned char *)ghidra_home + 8)),uVar13);
          goto LAB_000f76c8;
        }
        if (iVar6 == 2) {
          (*(undefined4 *)((char *)frame_ + 324)) = ((int * *)((char *)frame_ + 32))[3][2];
          (*(undefined4 *)((char *)frame_ + 316)) = *((int * *)((char *)frame_ + 32))[3];
          (*(undefined4 *)((char *)frame_ + 320)) = ((int * *)((char *)frame_ + 32))[3][1];
          (*(undefined4 *)((char *)frame_ + 328)) = ((int * *)((char *)frame_ + 32))[3][3];
          (*(undefined4 *)((char *)frame_ + 336)) = ((int * *)((char *)frame_ + 32))[3][5];
          (*(undefined4 *)((char *)frame_ + 332)) = ((int * *)((char *)frame_ + 32))[3][4];
          (*(undefined4 *)((char *)frame_ + 292)) = *((int * *)((char *)frame_ + 32))[4];
          (*(undefined4 *)((char *)frame_ + 296)) = ((int * *)((char *)frame_ + 32))[4][1];
          (*(undefined4 *)((char *)frame_ + 300)) = ((int * *)((char *)frame_ + 32))[4][2];
          (*(undefined4 *)((char *)frame_ + 304)) = ((int * *)((char *)frame_ + 32))[4][3];
          (*(undefined4 *)((char *)frame_ + 312)) = ((int * *)((char *)frame_ + 32))[4][5];
          (*(undefined4 *)((char *)frame_ + 308)) = ((int * *)((char *)frame_ + 32))[4][4];
          uVar8 = ((int (*)())FUN_000f554c)(*(undefined4 *)(param_2 + 0x3ac),(*(undefined4 *)((char *)frame_ + 316)),(*(undefined4 *)((char *)frame_ + 320)),(*(undefined4 *)((char *)frame_ + 324)),
                               (*(undefined4 *)((char *)frame_ + 328)),(*(undefined4 *)((char *)frame_ + 332)),(*(undefined4 *)((char *)frame_ + 336)),(*(undefined4 *)((char *)frame_ + 292)));
          uVar3 = *(uint *)(param_2 + 0x30);
        }
        else if (iVar6 < 3) {
          if (iVar6 == 1) {
            (*(undefined4 *)((char *)frame_ + 348)) = ((int * *)((char *)frame_ + 32))[3][2];
            (*(undefined4 *)((char *)frame_ + 340)) = *((int * *)((char *)frame_ + 32))[3];
            (*(undefined4 *)((char *)frame_ + 344)) = ((int * *)((char *)frame_ + 32))[3][1];
            (*(undefined4 *)((char *)frame_ + 352)) = ((int * *)((char *)frame_ + 32))[3][3];
            (*(undefined4 *)((char *)frame_ + 360)) = ((int * *)((char *)frame_ + 32))[3][5];
            (*(undefined4 *)((char *)frame_ + 356)) = ((int * *)((char *)frame_ + 32))[3][4];
            uVar8 = ((int (*)())FUN_000f56ac)(*(undefined4 *)(param_2 + 0x3ac),(*(undefined4 *)((char *)frame_ + 340)),(*(undefined4 *)((char *)frame_ + 344)),(*(undefined4 *)((char *)frame_ + 348)),
                                 (*(undefined4 *)((char *)frame_ + 352)),(*(undefined4 *)((char *)frame_ + 356)),(*(undefined4 *)((char *)frame_ + 360)));
            uVar3 = *(uint *)(param_2 + 0x30);
          }
          else {
LAB_000f70d4:
            uVar8 = 0;
          }
        }
        else if (iVar6 == 3) {
          (*(undefined4 *)((char *)frame_ + 276)) = ((int * *)((char *)frame_ + 32))[3][2];
          (*(undefined4 *)((char *)frame_ + 268)) = *((int * *)((char *)frame_ + 32))[3];
          (*(undefined4 *)((char *)frame_ + 272)) = ((int * *)((char *)frame_ + 32))[3][1];
          (*(undefined4 *)((char *)frame_ + 280)) = ((int * *)((char *)frame_ + 32))[3][3];
          (*(undefined4 *)((char *)frame_ + 288)) = ((int * *)((char *)frame_ + 32))[3][5];
          (*(undefined4 *)((char *)frame_ + 284)) = ((int * *)((char *)frame_ + 32))[3][4];
          (*(undefined4 *)((char *)frame_ + 248)) = ((int * *)((char *)frame_ + 32))[4][1];
          (*(undefined4 *)((char *)frame_ + 244)) = *((int * *)((char *)frame_ + 32))[4];
          (*(undefined4 *)((char *)frame_ + 252)) = ((int * *)((char *)frame_ + 32))[4][2];
          (*(undefined4 *)((char *)frame_ + 256)) = ((int * *)((char *)frame_ + 32))[4][3];
          (*(undefined4 *)((char *)frame_ + 264)) = ((int * *)((char *)frame_ + 32))[4][5];
          (*(undefined4 *)((char *)frame_ + 260)) = ((int * *)((char *)frame_ + 32))[4][4];
          (*(undefined4 *)((char *)frame_ + 364)) = *((int * *)((char *)frame_ + 32))[5];
          (*(undefined4 *)((char *)frame_ + 372)) = ((int * *)((char *)frame_ + 32))[5][2];
          (*(undefined4 *)((char *)frame_ + 376)) = ((int * *)((char *)frame_ + 32))[5][3];
          (*(undefined4 *)((char *)frame_ + 368)) = ((int * *)((char *)frame_ + 32))[5][1];
          (*(undefined4 *)((char *)frame_ + 384)) = ((int * *)((char *)frame_ + 32))[5][5];
          (*(undefined4 *)((char *)frame_ + 380)) = ((int * *)((char *)frame_ + 32))[5][4];
          uVar8 = ((int (*)())FUN_000f53c0)(*(undefined4 *)(param_2 + 0x3ac),(*(undefined4 *)((char *)frame_ + 268)),(*(undefined4 *)((char *)frame_ + 272)),(*(undefined4 *)((char *)frame_ + 276)),
                               (*(undefined4 *)((char *)frame_ + 280)),(*(undefined4 *)((char *)frame_ + 284)),(*(undefined4 *)((char *)frame_ + 288)),(*(undefined4 *)((char *)frame_ + 244)));
          uVar3 = *(uint *)(param_2 + 0x30);
        }
        else {
          if (iVar6 != 4) goto LAB_000f70d4;
          (*(undefined4 *)((char *)frame_ + 204)) = ((int * *)((char *)frame_ + 32))[3][2];
          (*(undefined4 *)((char *)frame_ + 196)) = *((int * *)((char *)frame_ + 32))[3];
          (*(undefined4 *)((char *)frame_ + 200)) = ((int * *)((char *)frame_ + 32))[3][1];
          (*(undefined4 *)((char *)frame_ + 208)) = ((int * *)((char *)frame_ + 32))[3][3];
          (*(undefined4 *)((char *)frame_ + 216)) = ((int * *)((char *)frame_ + 32))[3][5];
          (*(undefined4 *)((char *)frame_ + 212)) = ((int * *)((char *)frame_ + 32))[3][4];
          (*(undefined4 *)((char *)frame_ + 176)) = ((int * *)((char *)frame_ + 32))[4][1];
          (*(undefined4 *)((char *)frame_ + 172)) = *((int * *)((char *)frame_ + 32))[4];
          (*(undefined4 *)((char *)frame_ + 180)) = ((int * *)((char *)frame_ + 32))[4][2];
          (*(undefined4 *)((char *)frame_ + 184)) = ((int * *)((char *)frame_ + 32))[4][3];
          (*(undefined4 *)((char *)frame_ + 192)) = ((int * *)((char *)frame_ + 32))[4][5];
          (*(undefined4 *)((char *)frame_ + 188)) = ((int * *)((char *)frame_ + 32))[4][4];
          (*(undefined4 *)((char *)frame_ + 148)) = *((int * *)((char *)frame_ + 32))[5];
          (*(undefined4 *)((char *)frame_ + 156)) = ((int * *)((char *)frame_ + 32))[5][2];
          (*(undefined4 *)((char *)frame_ + 160)) = ((int * *)((char *)frame_ + 32))[5][3];
          (*(undefined4 *)((char *)frame_ + 152)) = ((int * *)((char *)frame_ + 32))[5][1];
          (*(undefined4 *)((char *)frame_ + 168)) = ((int * *)((char *)frame_ + 32))[5][5];
          (*(undefined4 *)((char *)frame_ + 164)) = ((int * *)((char *)frame_ + 32))[5][4];
          (*(undefined4 *)((char *)frame_ + 124)) = *((int * *)((char *)frame_ + 32))[6];
          (*(undefined4 *)((char *)frame_ + 128)) = ((int * *)((char *)frame_ + 32))[6][1];
          (*(undefined4 *)((char *)frame_ + 132)) = ((int * *)((char *)frame_ + 32))[6][2];
          (*(undefined4 *)((char *)frame_ + 136)) = ((int * *)((char *)frame_ + 32))[6][3];
          (*(undefined4 *)((char *)frame_ + 144)) = ((int * *)((char *)frame_ + 32))[6][5];
          (*(undefined4 *)((char *)frame_ + 140)) = ((int * *)((char *)frame_ + 32))[6][4];
          uVar8 = ((int (*)())FUN_000f5248)(*(undefined4 *)(param_2 + 0x3ac),(*(undefined4 *)((char *)frame_ + 196)),(*(undefined4 *)((char *)frame_ + 200)),(*(undefined4 *)((char *)frame_ + 204)),
                               (*(undefined4 *)((char *)frame_ + 208)),(*(undefined4 *)((char *)frame_ + 212)),(*(undefined4 *)((char *)frame_ + 216)),(*(undefined4 *)((char *)frame_ + 172)));
          uVar3 = *(uint *)(param_2 + 0x30);
        }
        FUN_00106004(param_1,(*(unsigned int *)((unsigned char *)ghidra_home + 8)),uVar8,uVar3 >> 7 & 1,uVar13);
LAB_000f76c8:
        iVar15 = FUN_001054ec(param_1,(*(unsigned int *)((unsigned char *)ghidra_home + 8)));
        *(undefined4 *)(iVar15 + 0x10) = (*(undefined4 *)((char *)frame_ + 16));
        return;
      }
    } while (iVar6 < 0);
    if (iVar6 != 0) {
      piVar9 = *ppiVar5;
      iVar4 = 0;
      while ((*((int * *)((char *)frame_ + 32))[iVar4 + 3] != *piVar9 || (((int * *)((char *)frame_ + 32))[iVar4 + 3][1] != piVar9[1]))) {
        iVar4 = iVar4 + 1;
        if (iVar6 < iVar4) goto LAB_000f6f58;
        if (iVar4 == iVar6) goto LAB_000f6f18;
      }
      *(char *)((int)&(*(undefined4 *)((char *)frame_ + 20)) + iVar11 + 1) = (char)iVar4;
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
  
  return ((int (*)())FUN_000f6d14)(param_1,param_2,param_3,1,param_4,local_b0,local_ac,local_a8,local_a4,1,param_5,
               local_98,local_94,local_90,local_8c,1,param_6,local_80,local_7c,local_78,local_74,1);
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
  
  return ((int (*)())FUN_000f6d14)(param_1,param_2,param_3,3,param_4,local_b0,local_ac,local_a8,local_a4,3,param_5,
               local_98,local_94,local_90,local_8c,3,param_6,local_80,local_7c,local_78,local_74,3);
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
          _memset(uVar2 * 4 + param_1[2],0,(uVar3 - uVar2) * 4 + 4);
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

/* FUN_000f89b4 @ 0xf89b4 (52 bytes) */
int FUN_000f89b4(param_1)
  uint param_1;
{
  if (5 < param_1) {
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
  int *a4;
  undefined4 in_r8;
  uint uVar2;
  uint uVar3;
  unsigned int frame_[16] __attribute__((aligned(16)));
  
  ((char *)((char *)frame_ + 8))[0] = '\0';
  ((char *)((char *)frame_ + 8))[1] = 1;
  ((char *)((char *)frame_ + 8))[2] = 2;
  ((char *)((char *)frame_ + 8))[3] = 3;
  uVar3 = *param_2;
  a4 = param_5;
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
    ((char *)((char *)frame_ + 8))[0] = FUN_0019e9fc(param_3,0);
    ((char *)((char *)frame_ + 8))[1] = FUN_0019e9fc(param_3,1);
    ((char *)((char *)frame_ + 8))[2] = FUN_0019e9fc(param_3,2);
    ((char *)((char *)frame_ + 8))[3] = FUN_0019e9fc(param_3,3);
  }
  (**(code **)(*param_5 + 0x88))
            (param_5,param_4,0,(int)((char *)((char *)frame_ + 8))[uVar3 >> 0x18],a4,in_r8,*(code **)(*param_5 + 0x88));
  (**(code **)(*param_5 + 0x88))
            (param_5,param_4,1,(int)((char *)((char *)frame_ + 8))[uVar3 >> 0x10 & 0xff],a4,in_r8,
             *(code **)(*param_5 + 0x88));
  (**(code **)(*param_5 + 0x88))
            (param_5,param_4,2,(int)((char *)((char *)frame_ + 8))[uVar3 >> 8 & 0xff],a4,in_r8,*(code **)(*param_5 + 0x88)
            );
  (**(code **)(*param_5 + 0x88))
            (param_5,param_4,3,(int)((char *)((char *)frame_ + 8))[uVar3 & 0xff],a4,in_r8,*(code **)(*param_5 + 0x88));
  *param_2 = 0x10203;
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
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x30c) + 0xdc))
                    (*(int **)(param_2 + 0x30c),param_2,param_3);
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
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, param_6, param_7, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
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
  unsigned int frame_[16] __attribute__((aligned(16)));
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = param_3;
  ((char *)((char *)frame_ + 8))[0] = '\0';
  ((char *)((char *)frame_ + 8))[1] = '\0';
  ((char *)((char *)frame_ + 8))[2] = '\0';
  ((char *)((char *)frame_ + 8))[3] = '\0';
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
    ((char *)((char *)frame_ + 8))[0] = (char)*(undefined4 *)(PTR_DAT_001e8bc8 + iVar4 * 4);
    iVar4 = FUN_0019e990(param_4,1);
    ((char *)((char *)frame_ + 8))[1] = (char)*(undefined4 *)(puVar1 + iVar4 * 4);
    iVar4 = FUN_0019e990(param_4,2);
    ((char *)((char *)frame_ + 8))[2] = (char)*(undefined4 *)(puVar1 + iVar4 * 4);
    iVar4 = FUN_0019e990(param_4,3);
    ((char *)((char *)frame_ + 8))[3] = (char)*(undefined4 *)(puVar1 + iVar4 * 4);
  }
  if (param_7 == 0) {
    iVar12 = 4;
    iVar4 = 0;
    pcVar8 = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
    do {
      cVar3 = ((char *)((char *)frame_ + 8))[iVar4];
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
    puVar7 = (undefined1 *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
    do {
      uVar2 = 1;
      if (((char *)((char *)frame_ + 8))[iVar4] != '\x01') {
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
  int *a0;
  int iVar1;
  undefined4 uVar2;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0xc);
  iVar3 = (**(code **)(param_2 * 0x24 + iVar3 + 0x14))
                    (*(undefined4 *)(param_2 * 0x24 + iVar3),*(int *)(param_1 + 8),param_3,in_r6,
                     in_r7,in_r8,iVar3);
  if ((param_3 != 0) &&
     (a0 = *(int **)(*(int *)(param_1 + 8) + 0x30c), iVar1 = (**(code **)(*a0 + 0xb0))(a0),
     iVar1 != 0)) {
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
  void *pvVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = (**(code **)(*param_2 + 0x30))(param_2,param_2,param_3);
  if ((iVar2 != 0) &&
     (piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x30c),
     iVar2 = (**(code **)(*piVar3 + 0x168))(piVar3,param_1,param_2), iVar2 != 0)) {
    pvVar4 = FUN_001043f0(0x13,*(undefined4 *)(param_1 + 8));
    iVar5 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar5;
    iVar2 = FUN_001054ec(pvVar4,0);
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(int *)(iVar2 + 8) = iVar5;
    uVar1 = param_2[0x4d];
    ((int (*)())FUN_000f771c)(pvVar4,param_1,1,uVar1 & 0xffff | 0x60000,uVar1 & 0xffff | 0x70000,
                 uVar1 & 0xffff | 0x70000,uVar1 & 0xffff | 0x70000);
    iVar6 = param_2[0x2b];
    iVar7 = param_2[0x2c];
    iVar2 = FUN_001054ec(pvVar4,2);
    *(int *)(iVar2 + 0xc) = iVar7;
    *(int *)(iVar2 + 8) = iVar6;
    ((int (*)())FUN_000f92fc)(param_1,pvVar4,param_3);
    pvVar4 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar2 = FUN_001054ec(pvVar4,0);
    *(undefined4 *)(iVar2 + 0xc) = 0;
    *(int *)(iVar2 + 8) = iVar5;
    *(undefined4 *)((int)pvVar4 + 0x9c) = 0x1010000;
    iVar6 = param_2[0x2b];
    iVar7 = param_2[0x2c];
    iVar2 = FUN_001054ec(pvVar4,1);
    *(int *)(iVar2 + 8) = iVar6;
    *(int *)(iVar2 + 0xc) = iVar7;
    ((int (*)())FUN_000f92fc)(param_1,pvVar4,param_3);
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
  void *pvVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined4 uVar14;
  unsigned int frame_[28] __attribute__((aligned(16)));
  
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
        pvVar5 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        FUN_00130478(param_1,iVar13);
        iVar6 = FUN_001054ec(pvVar5,0);
        *(int *)(iVar6 + 8) = iVar13;
        *(undefined4 *)(iVar6 + 0xc) = 0x10;
        *(undefined4 *)((int)pvVar5 + 0x9c) = 0x10101;
        FUN_00130444(param_1,iVar13);
        FUN_00130bd4(param_1,iVar13);
        piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
        uVar14 = (**(code **)(*piVar7 + 0x9c))(piVar7,uVar1,*(int *)(param_1 + 8));
        iVar6 = FUN_001054ec(pvVar5,1);
        *(undefined4 *)(iVar6 + 8) = uVar14;
        *(undefined4 *)(iVar6 + 0xc) = 0x1f;
        piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
        (**(code **)(*piVar7 + 0xa0))(((undefined4 *)((char *)frame_ + 24)),piVar7,uVar1,*(int *)(param_1 + 8));
        uVar14 = ((undefined4 *)((char *)frame_ + 24))[0];
        iVar6 = FUN_001054ec(pvVar5,1);
        *(undefined4 *)(iVar6 + 0x10) = uVar14;
        ((int (*)())FUN_000f92fc)(param_1,pvVar5,uVar2);
        if ((int)uVar1 < 3) {
          FUN_001046c8(puVar12,iVar4,*(undefined4 *)((int)pvVar5 + 0x8c));
          if (iVar4 == 0) {
            puVar3[0x28] = 0;
          }
          else {
            iVar6 = FUN_001054ec(puVar12,iVar4);
            *(undefined4 *)(iVar6 + 0x10) = 0;
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
          FUN_001046c8(puVar10,iVar11,*(undefined4 *)((int)pvVar5 + 0x8c));
          if (iVar11 == 0) {
            puVar10[0x27] = 0;
          }
          else {
            iVar6 = FUN_001054ec(puVar10,iVar11);
            *(undefined4 *)(iVar6 + 0x10) = 0;
          }
        }
        uVar14 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar8 = (undefined4 *)FUN_00193e18(uVar14,0x168);
        *puVar8 = uVar14;
        puVar8 = puVar8 + 1;
        FUN_00109428(puVar8,0x7a,*(undefined4 *)(param_1 + 8));
        iVar6 = FUN_001054ec(puVar8,0);
        *(undefined4 *)(iVar6 + 0xc) = 0x10;
        uVar1 = uVar1 + 1;
        *(int *)(iVar6 + 8) = iVar13;
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
  iVar11 = *(int *)(*(int *)(param_1 + 8) + 0x3b4) + 1;
  *(int *)(*(int *)(param_1 + 8) + 0x3b4) = iVar11;
  iVar4 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x3a,iVar11,0);
  *(undefined4 *)(iVar4 + 0x30) = 2;
  FUN_001046c8(puVar12,0,iVar4);
  uVar9 = *param_3;
  uVar2 = FUN_000ec208(param_1,*param_3 >> 0x10 & 0x3f);
  iVar4 = FUN_001054ec(puVar12,1);
  *(undefined4 *)(iVar4 + 0xc) = uVar2;
  *(uint *)(iVar4 + 8) = (uint)(ushort)uVar9;
  ((undefined4 *)((char *)frame_ + 8))[0] = 0x10203;
  ((int (*)())FUN_000f8aa0)(param_1,((undefined4 *)((char *)frame_ + 8)),param_3,1,puVar12);
  puVar3[0x4d] = 1;
  FUN_00193f64(param_2,puVar12);
  pvVar5 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
  uVar2 = FUN_000ec208(param_1,param_6);
  iVar4 = FUN_001054ec(pvVar5,0);
  *(undefined4 *)(iVar4 + 0xc) = uVar2;
  *(undefined4 *)(iVar4 + 8) = param_5;
  *(undefined4 *)((int)pvVar5 + 0x9c) = 0x10101;
  iVar4 = FUN_001054ec(pvVar5,1);
  *(undefined4 *)(iVar4 + 0xc) = 0x3a;
  *(int *)(iVar4 + 8) = iVar11;
  FUN_001049e8(pvVar5,*(undefined4 *)(*(int *)(param_1 + 0x374) + 0x8c));
  FUN_00193f64(param_2,pvVar5);
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
  void *pvVar3;
  void *pvVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  code *pcVar15;
  uint uVar16;
  uint uVar17;
  int *piVar18;
  undefined4 uVar19;
  int iVar20;
  undefined4 *puVar21;
  double fparam_1;
  unsigned int frame_[28] __attribute__((aligned(16)));
  
  iVar8 = (int)(short)*param_3;
  uVar10 = *param_3 >> 0x10 & 0x3f;
  if (((*param_3 & 0x400000) == 0) || (uVar14 = param_3[1] >> 9 & 0xf, uVar14 == 0)) {
    pvVar4 = (void *)0x0;
    iVar20 = 0;
  }
  else {
    iVar20 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar20;
    *(short *)((int)param_3 + 2) = (short)iVar20;
    *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    pvVar4 = FUN_001043f0(0x13,*(undefined4 *)(param_1 + 8));
    iVar5 = FUN_001054ec(pvVar4,0);
    *(undefined4 *)(iVar5 + 0xc) = 0;
    *(int *)(iVar5 + 8) = iVar20;
    iVar5 = FUN_001054ec(pvVar4,1);
    *(undefined4 *)(iVar5 + 0xc) = 0;
    fparam_1 = (double)*(float *)(&DAT_001aa9fc + uVar14 * 4);
    *(int *)(iVar5 + 8) = iVar20;
    ((void (*)())FUN_000f79c4)(pvVar4,param_1,2,fparam_1,fparam_1,fparam_1,fparam_1);
    FUN_00193f64(param_2,pvVar4);
  }
  uVar14 = 0;
  uVar17 = 0;
  do {
    iVar5 = FUN_0019e990(param_3,uVar17);
    bVar1 = uVar17 != 3;
    uVar14 = uVar14 | (uint)(iVar5 == 2) << (uVar17 & 0x3f);
    uVar17 = uVar17 + 1;
  } while (bVar1);
  if (uVar14 != 0) {
    if (pvVar4 == (void *)0x0) {
      iVar20 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar20;
      *(short *)((int)param_3 + 2) = (short)iVar20;
      *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    }
    pvVar4 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar5 = FUN_001054ec(pvVar4,0);
    *(undefined4 *)(iVar5 + 0xc) = 0;
    *(int *)(iVar5 + 8) = iVar20;
    ((void (*)())FUN_000f79c4)(pvVar4,param_1,1,0.0,0.0,0.0,0.0);
    iVar5 = 4;
    uVar17 = 0;
    pvVar3 = pvVar4;
    do {
      if (((int)uVar14 >> (uVar17 & 0x3f) & 1U) == 0) {
        *(undefined1 *)((int)pvVar3 + 0x9c) = 1;
      }
      else {
        *(undefined1 *)((int)pvVar3 + 0x9c) = 0;
      }
      uVar17 = uVar17 + 1;
      pvVar3 = (void *)((int)pvVar3 + 1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    FUN_00193f64(param_2,pvVar4);
  }
  uVar14 = 0;
  uVar17 = 0;
  do {
    iVar5 = FUN_0019e990(param_3,uVar17);
    bVar1 = uVar17 != 3;
    uVar14 = uVar14 | (uint)(iVar5 == 3) << (uVar17 & 0x3f);
    uVar17 = uVar17 + 1;
  } while (bVar1);
  if (uVar14 != 0) {
    if (pvVar4 == (void *)0x0) {
      iVar20 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar20;
      *(short *)((int)param_3 + 2) = (short)iVar20;
      *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    }
    pvVar4 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar5 = FUN_001054ec(pvVar4,0);
    *(undefined4 *)(iVar5 + 0xc) = 0;
    *(int *)(iVar5 + 8) = iVar20;
    ((void (*)())FUN_000f79c4)(pvVar4,param_1,1,1.0,1.0,1.0,1.0);
    iVar5 = 4;
    uVar17 = 0;
    pvVar3 = pvVar4;
    do {
      if (((int)uVar14 >> (uVar17 & 0x3f) & 1U) == 0) {
        *(undefined1 *)((int)pvVar3 + 0x9c) = 1;
      }
      else {
        *(undefined1 *)((int)pvVar3 + 0x9c) = 0;
      }
      uVar17 = uVar17 + 1;
      pvVar3 = (void *)((int)pvVar3 + 1);
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    FUN_00193f64(param_2,pvVar4);
  }
  uVar14 = 0;
  if ((*param_3 & 0x400000) != 0) {
    uVar14 = param_3[1];
    uVar14 = (uint)((uVar14 & 0xc0) == 0) |
             (uint)((uVar14 & 0x30) == 0) << 8 |
             (uint)((uVar14 & 0xc) == 0) << 0x10 | (uint)((uVar14 & 3) == 0) << 0x18;
  }
  iVar5 = FUN_0019eb30(param_3);
  if (iVar5 != 0) {
    pvVar4 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar5 = FUN_001054ec(pvVar4,0);
    *(undefined4 *)(iVar5 + 0xc) = 0;
    *(int *)(iVar5 + 8) = iVar20;
    iVar5 = FUN_001054ec(pvVar4,1);
    *(undefined4 *)(iVar5 + 0xc) = 0;
    *(int *)(iVar5 + 8) = iVar20;
    FUN_00193f64(param_2,pvVar4);
  }
  uVar17 = *param_3;
  if (((uVar17 & 0x400000) == 0) || ((param_3[1] & 0x100) == 0)) {
LAB_000f9f08:
    bVar1 = false;
  }
  else {
    piVar18 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
    pcVar15 = *(code **)(*piVar18 + 0x78);
    uVar6 = FUN_000ec208(param_1,uVar10);
    iVar5 = (*pcVar15)(piVar18,uVar6);
    if (iVar5 == 0) {
      iVar20 = FUN_000ec208(param_1,*param_3 >> 0x10 & 0x3f);
      if (iVar20 == 9) {
        uVar17 = *param_3;
        goto LAB_000f9f08;
      }
      FUN_000ec208(param_1,*param_3 >> 0x10 & 0x3f);
      uVar17 = *param_3;
      bVar1 = false;
    }
    else {
      piVar18 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
      iVar5 = (**(code **)(*piVar18 + 0x80))(piVar18);
      if (iVar5 == 0) {
        if (pvVar4 == (void *)0x0) {
          iVar20 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar20;
          *(short *)((int)param_3 + 2) = (short)iVar20;
          *param_3 = *param_3 & 0xffc0ffff | 0x40000;
        }
        pvVar4 = (void *)((int (*)())FUN_000f9038)(param_1,iVar20,param_2);
        uVar17 = *param_3;
        if ((uVar17 & 0x400000) == 0) goto LAB_000f9f08;
        bVar1 = false;
        param_3[1] = param_3[1] & 0xfffffeff;
      }
      else {
        uVar17 = *param_3;
        bVar1 = true;
      }
    }
  }
  if (pvVar4 != (void *)0x0) {
    if ((uVar17 & 0x1800000) == 0x800000) {
      if (*(int *)(param_1 + 0x3e4) == 0) {
        *(undefined4 *)(param_1 + 0x3e4) = 1;
        uVar6 = FUN_000ec208(param_1,uVar10);
        *(undefined4 *)(param_1 + 0x3f4) = uVar6;
      }
      else {
        FUN_000ec208(param_1,uVar10);
      }
      uVar6 = *(undefined4 *)(param_1 + 0x3ac);
      iVar20 = *(int *)(*(int *)(param_1 + 8) + 0x3c0) + 1;
      *(int *)(*(int *)(param_1 + 8) + 0x3c0) = iVar20;
      iVar20 = FUN_00127608(uVar6,0x2a,iVar20,0);
      *(int *)(iVar20 + 0x30) = iVar8;
      FUN_001046c8(pvVar4,0,iVar20);
      *param_3 = *param_3 & 0xfe7fffff;
    }
    else {
      uVar6 = FUN_000ec208(param_1,uVar10);
      iVar20 = FUN_001054ec(pvVar4,0);
      *(undefined4 *)(iVar20 + 0xc) = uVar6;
      *(int *)(iVar20 + 8) = iVar8;
    }
    if (bVar1) {
      *(undefined4 *)((int)pvVar4 + 0x120) = 1;
    }
    if ((*param_3 & 0x400000) != 0) {
      param_3[1] = param_3[1] & 0xfffffeff;
    }
    iVar20 = 0;
    do {
      iVar5 = FUN_0019e990(param_3,iVar20);
      if (iVar5 == 0) {
        *(undefined1 *)((int)pvVar4 + 0x9c) = 1;
      }
      else {
        *(undefined1 *)((int)pvVar4 + 0x9c) = 0;
      }
      bVar1 = iVar20 != 3;
      pvVar4 = (void *)((int)pvVar4 + 1);
      iVar20 = iVar20 + 1;
    } while (bVar1);
    uVar17 = *param_3;
    if ((uVar17 & 0x400000) != 0) {
      param_3[1] = param_3[1] & 0xffffff00 | 0x55;
    }
  }
  if ((uVar10 != 0x1f) || ((*(uint *)(param_1 + 0x30) & 0x4000) == 0)) {
    bVar1 = false;
    bVar2 = false;
  }
  else {
    bVar1 = true;
    bVar2 = true;
  }
  if (((undefined4 *)(uVar17 & 0x3f0000) != 0x001b0000) && (!bVar1)) goto LAB_000fa744;
  iVar20 = 1;
  iVar5 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
  *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar5;
  uVar17 = *param_3;
  uVar12 = (uint)(ushort)*param_3;
  uVar11 = uVar17 >> 0x10 & 0x3f;
  if ((int)uVar17 < 0) {
    iVar20 = 2;
    uVar12 = uVar12 | param_3[1] << 0x10;
  }
  if ((uVar17 & 0x400000) != 0) {
    iVar20 = iVar20 + 1;
  }
  if ((uVar17 & 0x1800000) == 0x1000000) {
    puVar9 = param_3 + iVar20;
    if (!bVar2) {
      uVar6 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar7 = (undefined4 *)FUN_00193e18(uVar6,0x168);
      *puVar7 = uVar6;
      puVar21 = puVar7 + 1;
      FUN_001071fc(puVar21,0xfc,*(undefined4 *)(param_1 + 8));
      uVar6 = FUN_000ec208(param_1,uVar11);
      iVar13 = FUN_001054ec(puVar21,0);
      *(undefined4 *)(iVar13 + 0xc) = uVar6;
      *(uint *)(iVar13 + 8) = uVar12;
      uVar6 = FUN_000ec208(param_1,4);
      iVar13 = FUN_001054ec(puVar21,1);
      puVar7[0x28] = uVar14;
      *(undefined4 *)(iVar13 + 0xc) = uVar6;
      *(int *)(iVar13 + 8) = iVar5;
      if ((*param_3 & 0x4000000) == 0) goto LAB_000fa1bc;
      iVar13 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar13;
      uVar17 = param_3[iVar20 + 2];
      pvVar4 = FUN_001043f0(0xc6,*(undefined4 *)(param_1 + 8));
      uVar6 = FUN_000ec208(param_1,4);
      iVar20 = FUN_001054ec(pvVar4,0);
      *(undefined4 *)(iVar20 + 0xc) = uVar6;
      *(int *)(iVar20 + 8) = iVar13;
      uVar14 = *puVar9;
      uVar6 = FUN_000ec208(param_1,*puVar9 >> 0x10 & 0x3f);
      iVar20 = FUN_001054ec(pvVar4,1);
      *(undefined4 *)(iVar20 + 0xc) = uVar6;
      *(uint *)(iVar20 + 8) = (uint)(ushort)uVar14;
      ((int (*)())FUN_000f7870)(pvVar4,param_1,2,uVar17,uVar17,uVar17,uVar17);
      FUN_00193f64(param_2,pvVar4);
      uVar6 = FUN_000ec208(param_1,4);
      iVar20 = FUN_001054ec(puVar21,2);
      *(undefined4 *)(iVar20 + 0xc) = uVar6;
      *(int *)(iVar20 + 8) = iVar13;
    }
    else {
      uVar6 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar7 = (undefined4 *)FUN_00193e18(uVar6,0x168);
      *puVar7 = uVar6;
      puVar21 = puVar7 + 1;
      FUN_00108a50(puVar21,0xf9,*(undefined4 *)(param_1 + 8));
      puVar7[0x28] = uVar14;
      puVar7[0x22] = 2;
      if ((*param_3 & 0x4000000) != 0) {
        uVar12 = uVar12 + param_3[iVar20 + 2];
      }
      puVar7[0x51] = uVar12;
      puVar7[0x50] = 0x24;
      uVar6 = FUN_00127608(*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x6c4) + 0x3ac),0x2c,0,0
                          );
      FUN_001046c8(puVar21,0,uVar6);
      iVar20 = FUN_001054ec(puVar21,1);
      *(undefined4 *)(iVar20 + 0xc) = 0;
      *(int *)(iVar20 + 8) = iVar5;
LAB_000fa1bc:
      uVar14 = *puVar9;
      uVar6 = FUN_000ec208(param_1,*puVar9 >> 0x10 & 0x3f);
      iVar20 = FUN_001054ec(puVar21,2);
      *(undefined4 *)(iVar20 + 0xc) = uVar6;
      *(uint *)(iVar20 + 8) = (uint)(ushort)uVar14;
      if (bVar2) goto LAB_000fa4f8;
    }
    uVar6 = FUN_000ec208(param_1,uVar11);
    iVar20 = FUN_001054ec(puVar21,3);
    *(undefined4 *)(iVar20 + 0xc) = uVar6;
    *(uint *)(iVar20 + 8) = uVar12;
    ((undefined4 *)((char *)frame_ + 12))[0] = 0x10203;
    ((int (*)())FUN_000f8aa0)(param_1,((undefined4 *)((char *)frame_ + 12)),puVar9,2,puVar21);
  }
  else if ((uVar17 & 0x1800000) == 0) {
    uVar16 = 0;
    if ((uVar17 & 0x4000000) != 0) {
      uVar16 = param_3[iVar20];
    }
    if (bVar2) {
      uVar6 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar7 = (undefined4 *)FUN_00193e18(uVar6,0x168);
      *puVar7 = uVar6;
      puVar21 = puVar7 + 1;
      FUN_00108770(puVar21,*(undefined4 *)(param_1 + 8));
      puVar7[0x28] = uVar14;
      puVar7[0x50] = 0x24;
      puVar7[0x51] = uVar12;
      uVar6 = FUN_00127608(*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x6c4) + 0x3ac),0x2c,0,0
                          );
      FUN_001046c8(puVar21,0,uVar6);
      iVar20 = FUN_001054ec(puVar21,1);
      *(undefined4 *)(iVar20 + 0xc) = 0;
      *(int *)(iVar20 + 8) = iVar5;
    }
    else {
      uVar6 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar7 = (undefined4 *)FUN_00193e18(uVar6,0x168);
      *puVar7 = uVar6;
      puVar21 = puVar7 + 1;
      FUN_001071fc(puVar21,0xfc,*(undefined4 *)(param_1 + 8));
      uVar6 = FUN_000ec208(param_1,uVar11);
      iVar20 = FUN_001054ec(puVar21,0);
      *(undefined4 *)(iVar20 + 0xc) = uVar6;
      *(uint *)(iVar20 + 8) = uVar12;
      uVar6 = FUN_000ec208(param_1,4);
      iVar20 = FUN_001054ec(puVar21,1);
      *(undefined4 *)(iVar20 + 0xc) = uVar6;
      *(int *)(iVar20 + 8) = iVar5;
      ((int (*)())FUN_000f7870)(puVar21,param_1,2,uVar16,uVar16,uVar16,uVar16);
      puVar7[0x28] = uVar14;
    }
  }
  else {
    puVar21 = (undefined4 *)0x0;
  }
LAB_000fa4f8:
  iVar20 = FUN_001054ec(puVar21,2);
  (*(undefined4 *)((char *)frame_ + 8)) = *(undefined4 *)(iVar20 + 0x10);
  piVar18 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
  iVar20 = (**(code **)(*piVar18 + 0x104))(piVar18,puVar21,2,&(*(undefined4 *)((char *)frame_ + 8)),0);
  if (iVar20 == 0) {
    iVar13 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar13;
    pvVar4 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    uVar19 = puVar21[0x32];
    uVar6 = puVar21[0x31];
    iVar20 = FUN_001054ec(pvVar4,1);
    *(undefined4 *)(iVar20 + 0xc) = uVar19;
    *(undefined4 *)(iVar20 + 8) = uVar6;
    uVar6 = FUN_000ec208(param_1,4);
    iVar20 = FUN_001054ec(pvVar4,0);
    *(undefined4 *)(iVar20 + 0xc) = uVar6;
    *(int *)(iVar20 + 8) = iVar13;
    iVar20 = FUN_001054ec(puVar21,2);
    uVar6 = *(undefined4 *)(iVar20 + 0x10);
    iVar20 = FUN_001054ec(pvVar4,1);
    *(undefined4 *)(iVar20 + 0x10) = uVar6;
    FUN_00193f64(param_2,pvVar4);
    uVar6 = FUN_000ec208(param_1,4);
    iVar20 = FUN_001054ec(puVar21,2);
    *(undefined4 *)(iVar20 + 0xc) = uVar6;
    *(int *)(iVar20 + 8) = iVar13;
    iVar20 = FUN_001054ec(puVar21,2);
    *(undefined4 *)(iVar20 + 0x10) = 0;
  }
  if ((!bVar2) &&
     (piVar18 = *(int **)(*(int *)(param_1 + 8) + 0x30c),
     iVar20 = (**(code **)(*piVar18 + 0x104))(piVar18,puVar21,1,&(*(undefined4 *)((char *)frame_ + 8)),0), iVar20 == 0)) {
    iVar13 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar13;
    pvVar4 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    uVar19 = puVar21[0x2c];
    uVar6 = puVar21[0x2b];
    iVar20 = FUN_001054ec(pvVar4,1);
    *(undefined4 *)(iVar20 + 0xc) = uVar19;
    *(undefined4 *)(iVar20 + 8) = uVar6;
    uVar6 = FUN_000ec208(param_1,4);
    iVar20 = FUN_001054ec(pvVar4,0);
    *(undefined4 *)(iVar20 + 0xc) = uVar6;
    *(int *)(iVar20 + 8) = iVar13;
    iVar20 = FUN_001054ec(puVar21,1);
    uVar6 = *(undefined4 *)(iVar20 + 0x10);
    iVar20 = FUN_001054ec(pvVar4,1);
    *(undefined4 *)(iVar20 + 0x10) = uVar6;
    FUN_00193f64(param_2,pvVar4);
    uVar6 = FUN_000ec208(param_1,4);
    iVar20 = FUN_001054ec(puVar21,1);
    *(undefined4 *)(iVar20 + 0xc) = uVar6;
    *(int *)(iVar20 + 8) = iVar13;
    iVar20 = FUN_001054ec(puVar21,1);
    *(undefined4 *)(iVar20 + 0x10) = 0x10203;
  }
  FUN_00193f64(param_2,puVar21);
  *param_3 = *param_3 & 0xffc0ffff | 0x40000;
  *(short *)((int)param_3 + 2) = (short)iVar5;
LAB_000fa744:
  if ((uVar10 == 0x1f) && ((*(uint *)(param_1 + 0x30) & 0x200000) != 0)) {
    iVar5 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar5;
    iVar13 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar13;
    pvVar4 = FUN_001043f0(0xcc,*(undefined4 *)(param_1 + 8));
    iVar20 = FUN_001054ec(pvVar4,0);
    *(undefined4 *)(iVar20 + 0xc) = 0;
    *(int *)(iVar20 + 8) = iVar13;
    iVar20 = FUN_001054ec(pvVar4,1);
    *(undefined4 *)(iVar20 + 8) = 0;
    *(undefined4 *)(iVar20 + 0xc) = 0x1f;
    iVar20 = FUN_001054ec(pvVar4,1);
    *(undefined4 *)(iVar20 + 0x10) = 0x1010101;
    if (param_5 == 1) {
      ((int (*)())FUN_000f7870)(pvVar4,param_1,2,1,1,1,1);
    }
    else if (param_5 < 2) {
      if (param_5 == 0) {
        ((int (*)())FUN_000f7870)(pvVar4,param_1,2,0,0,0,0);
      }
    }
    else if (param_5 == 2) {
      ((int (*)())FUN_000f7870)(pvVar4,param_1,2,2,2,2,2);
    }
    else if (param_5 == 3) {
      ((int (*)())FUN_000f7870)(pvVar4,param_1,2,3,3,3,3);
    }
    FUN_00193f64(param_2,pvVar4);
    pvVar4 = FUN_001043f0(0x24,*(undefined4 *)(param_1 + 8));
    uVar6 = FUN_000ec208(param_1,0x1f);
    iVar20 = FUN_001054ec(pvVar4,0);
    *(undefined4 *)(iVar20 + 0xc) = uVar6;
    *(int *)(iVar20 + 8) = iVar8;
    iVar20 = FUN_001054ec(pvVar4,1);
    *(undefined4 *)(iVar20 + 0xc) = 0;
    *(int *)(iVar20 + 8) = iVar13;
    uVar6 = FUN_000ec208(param_1,4);
    iVar20 = FUN_001054ec(pvVar4,2);
    *(undefined4 *)(iVar20 + 0xc) = uVar6;
    *(int *)(iVar20 + 8) = iVar5;
    uVar6 = FUN_000ec208(param_1,0x1f);
    iVar20 = FUN_001054ec(pvVar4,3);
    *(undefined4 *)(iVar20 + 0xc) = uVar6;
    *(int *)(iVar20 + 8) = iVar8;
    FUN_00193f64(param_2,pvVar4);
    *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    *(short *)((int)param_3 + 2) = (short)iVar5;
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
  unsigned int frame_[20] __attribute__((aligned(16)));
  
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
      (*(undefined4 *)((char *)frame_ + 12)) = CONCAT22((*(unsigned short *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 12))) + 0)),(short)*puVar10);
      (*(undefined4 *)((char *)frame_ + 12)) = *puVar10 & 0x1800000 | *puVar10 & 0x3f0000 | (*(undefined4 *)((char *)frame_ + 12)) & 0xfe40ffff;
      puVar10 = &(*(undefined4 *)((char *)frame_ + 12));
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
    (*(undefined4 *)((char *)frame_ + 8)) = *(undefined4 *)(iVar4 + 0x10);
    iVar4 = 4;
    do {
      if (*(char *)((int)&(*(undefined4 *)((char *)frame_ + 8)) + iVar1) == '\0') {
        iVar6 = iVar6 + 1;
        iVar3 = iVar1;
      }
      iVar1 = iVar1 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (1 < iVar6) {
      (*(undefined4 *)((char *)frame_ + 12)) = DAT_001aa9e0;
      *(undefined1 *)((int)&(*(undefined4 *)((char *)frame_ + 12)) + iVar3) = 0;
      uVar9 = *(undefined4 *)(iVar3 * 4 + 0x1dc7bc);
      iVar3 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      uVar2 = FUN_000ec208(param_1,uVar8);
      iVar1 = FUN_001054ec(iVar3,0);
      *(undefined4 *)(iVar1 + 0xc) = uVar2;
      *(int *)(iVar1 + 8) = iVar7;
      *(undefined4 *)(iVar3 + 0x9c) = (*(undefined4 *)((char *)frame_ + 8));
      uVar2 = FUN_000ec208(param_1,uVar8);
      iVar1 = FUN_001054ec(iVar3,1);
      *(undefined4 *)(iVar1 + 0xc) = uVar2;
      *(int *)(iVar1 + 8) = iVar7;
      iVar1 = FUN_001054ec(iVar3,1);
      *(undefined4 *)(iVar1 + 0x10) = uVar9;
      *(uint *)(param_5 + 0x9c) = (*(undefined4 *)((char *)frame_ + 12));
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
  unsigned int frame_[20] __attribute__((aligned(16)));
  
  uVar7 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  puVar3 = (undefined4 *)FUN_00193e18(uVar7,0x15c);
  *puVar3 = uVar7;
  puVar6 = puVar3 + 1;
  FUN_000ea6d0(puVar6,param_2,param_4,0,*(undefined4 *)(param_1 + 8));
  FUN_000e78c0(puVar6,param_3);
  ((undefined4 *)((char *)frame_ + 8))[0] = DAT_001aa9a8;
  ((int (*)())FUN_000fa958)(param_1,5,1,param_7,param_2,1,DAT_001aa9dc,((undefined4 *)((char *)frame_ + 8)),param_6,1,puVar6);
  iVar4 = FUN_001054ec(param_2,1);
  iVar2 = 0;
  iVar9 = 4;
  (*(unsigned char *)((unsigned char *)&(((undefined4 *)((char *)frame_ + 8))[0]) + 0)) = (undefined1)((uint)*(undefined4 *)(iVar4 + 0x10) >> 0x18);
  uVar1 = (*(unsigned char *)((unsigned char *)&(((undefined4 *)((char *)frame_ + 8))[0]) + 0));
  ((undefined4 *)((char *)frame_ + 8))[0] = *(undefined4 *)(iVar4 + 0x10);
  do {
    *(undefined1 *)((int)((undefined4 *)((char *)frame_ + 8)) + iVar2) = uVar1;
    uVar7 = ((undefined4 *)((char *)frame_ + 8))[0];
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
    _memset(uVar9 * 4 + puVar7[2],0,4);
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
  unsigned int frame_[20] __attribute__((aligned(16)));
  
  uVar2 = *(uint *)(param_1 + 0x30) & 1 | *(uint *)(param_1 + 0x30) >> 0xe & 1;
  iVar1 = FUN_000d9fc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2);
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      FUN_000da070(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2,iVar4,1,&(*(int *)((char *)frame_ + 8)));
      FUN_000e4724(param_2,iVar4,(uint)((*(int *)((char *)frame_ + 8)) != 0));
      iVar3 = iVar4 + 1;
      ((int (*)())FUN_000fafa4)(param_1,0,iVar4,1,&(*(int *)((char *)frame_ + 8)));
      iVar4 = iVar3;
    } while (iVar1 != iVar3);
  }
  iVar1 = FUN_000d9fa0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2);
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      FUN_000da028(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2,iVar4,4,&(*(int *)((char *)frame_ + 8)));
      FUN_000e4450(param_2,iVar4,(*(int *)((char *)frame_ + 8)),(*(undefined4 *)((char *)frame_ + 12)),(*(undefined4 *)((char *)frame_ + 16)),(*(undefined4 *)((char *)frame_ + 20)));
      iVar3 = iVar4 + 1;
      ((int (*)())FUN_000fafa4)(param_1,2,iVar4,4,&(*(int *)((char *)frame_ + 8)));
      iVar4 = iVar3;
    } while (iVar1 != iVar3);
  }
  iVar1 = FUN_000d9f80(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2);
  if (0 < iVar1) {
    iVar4 = 0;
    do {
      FUN_000d9fe0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x398),uVar2,iVar4,4,&(*(float *)((char *)frame_ + 24)));
      ((void (*)())FUN_000e4780)(param_2,iVar4,(double)(*(float *)((char *)frame_ + 24)),(double)(*(float *)((char *)frame_ + 28)),(double)(*(float *)((char *)frame_ + 32)),(double)(*(float *)((char *)frame_ + 36))
                  );
      iVar3 = iVar4 + 1;
      ((int (*)())FUN_000fafa4)(param_1,1,iVar4,4,&(*(float *)((char *)frame_ + 24)));
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
  void *pvVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  void *pvVar15;
  void *pvVar16;
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
  undefined4 extraout_r4_17;
  dword *pdVar17;
  dword *pdVar18;
  uint uVar19;
  int iVar20;
  undefined1 *puVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  dword *pdVar25;
  dword *pdVar26;
  dword *pdVar27;
  dword *pdVar28;
  dword *pdVar29;
  dword *pdVar30;
  dword *pdVar31;
  dword *pdVar32;
  undefined4 *puVar33;
  uint uVar34;
  undefined4 uVar35;
  code *pcVar36;
  uint *puVar37;
  int iVar38;
  double fparam_1;
  double fparam_2;
  double fparam_3;
  double fparam_4;
  undefined8 uVar39;
  dword local_94 [3];
  unsigned int frame_[40] __attribute__((aligned(16)));
  
  uVar22 = *param_4;
  uVar23 = uVar22 >> 0x16 & 1;
  iVar20 = *(int *)(param_1 + 8);
  if ((((uVar22 & 0x3f0000) == 0x100000) && (iVar20 != 0)) &&
     ((*(uint *)(*(int *)(iVar20 + 0x30c) + 8) & 0x80) != 0)) {
    pdVar25 = (dword *)((int)((unsigned char *)0xc) + 3);
  }
  else {
    pdVar25 = (dword *)(int)(short)*param_4;
  }
  uVar24 = uVar22 >> 0x10 & 0x3f;
  uVar8 = param_2;
  pdVar17 = param_3;
  pdVar18 = param_4;
  pdVar32 = param_6;
  pdVar31 = pdVar25;
  if ((uVar22 & 0x1800000) == 0x800000) {
    iVar6 = 8;
    if (uVar23 == 0) {
      iVar6 = 4;
    }
    uVar22 = *(uint *)(iVar6 + (int)param_4);
    uVar1 = *(ushort *)((int)param_4 + iVar6 + 2);
    if ((uVar22 & 0x10000) == 0) {
      pdVar31 = (dword *)(*(int *)(iVar20 + 0x3b4) + 1);
      *(dword **)(iVar20 + 0x3b4) = pdVar31;
      iVar20 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x26,pdVar31,0);
      *(dword **)(iVar20 + 0x30) = pdVar25;
      uVar8 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar9 = (undefined4 *)FUN_00193e18(uVar8,0x168);
      *puVar9 = uVar8;
      puVar33 = puVar9 + 1;
      FUN_00109e28(puVar33,0x84,*(undefined4 *)(param_1 + 8));
      FUN_001046c8(puVar33,0,iVar20);
      pdVar18 = (dword *)0x0;
      uVar24 = 0x22;
      pdVar25 = (dword *)FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x25,(uint)uVar1,0);
      pdVar17 = pdVar25;
      FUN_001046c8(puVar33,1,pdVar25);
      uVar8 = *(undefined4 *)(PTR_DAT_001e8b8c + (uVar22 >> 0x11 & 7) * 4);
      iVar20 = FUN_001054ec(puVar33,1);
      *(undefined4 *)(iVar20 + 0x10) = uVar8;
      puVar9[0x4c] = pdVar25[0xc];
      FUN_00193f64(param_2,puVar33);
      uVar8 = extraout_r4_01;
    }
    else {
      piVar7 = (int *)0x0;
      uVar22 = param_5[1] - 1;
      if (uVar22 < param_5[1]) {
        piVar7 = (int *)(uVar22 * 4 + param_5[2]);
      }
      iVar20 = *piVar7;
      *(undefined4 *)(iVar20 + 0x140) = 1;
      uVar8 = FUN_000e7d5c(iVar20);
      uVar8 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x27,uVar8,0);
      if (uVar24 == 1) {
        pdVar18 = (dword *)0x0;
        pdVar31 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3b8) + 1);
        *(dword **)(*(int *)(param_1 + 8) + 0x3b8) = pdVar31;
        iVar6 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x28,pdVar31,0);
        *(dword **)(iVar6 + 0x30) = pdVar25;
        uVar35 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar9 = (undefined4 *)FUN_00193e18(uVar35,0x168);
        *puVar9 = uVar35;
        pdVar17 = puVar9 + 1;
        FUN_0010502c(pdVar17,0x82,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(pdVar17,0,iVar6);
        FUN_001046c8(pdVar17,1,uVar8);
        uVar24 = 0x23;
        FUN_000e7688(iVar20,pdVar17);
        FUN_0012306c(iVar6,pdVar17);
        FUN_001236e4(uVar8,1,pdVar17);
        uVar8 = extraout_r4;
      }
      else {
        if ((*(uint *)(param_1 + 0x30) & 1) == 0) {
          if ((*(uint *)(param_1 + 0x30) & 0x2000) != 0) {
            if (*(int *)(param_1 + 0x3e4) == 0) {
              *(undefined4 *)(param_1 + 0x3e4) = 1;
              uVar35 = FUN_000ec208(param_1,uVar24);
              *(undefined4 *)(param_1 + 0x3f4) = uVar35;
            }
            else {
              FUN_000ec208(param_1,uVar24);
            }
          }
        }
        else {
          *(undefined4 *)(param_1 + 0x3d4) = 1;
        }
        pdVar31 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3bc) + 1);
        *(dword **)(*(int *)(param_1 + 8) + 0x3bc) = pdVar31;
        uVar12 = *(undefined4 *)(param_1 + 0x3ac);
        uVar35 = FUN_000ec208(param_1,0x24);
        pdVar18 = (dword *)0x0;
        iVar6 = FUN_00127608(uVar12,uVar35,pdVar31,0);
        *(dword **)(iVar6 + 0x30) = pdVar25;
        uVar35 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar9 = (undefined4 *)FUN_00193e18(uVar35,0x168);
        *puVar9 = uVar35;
        pdVar17 = puVar9 + 1;
        FUN_0010502c(pdVar17,0x82,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(pdVar17,0,iVar6);
        FUN_001046c8(pdVar17,1,uVar8);
        uVar24 = 0x24;
        FUN_000e7688(iVar20,pdVar17);
        FUN_0012306c(iVar6,pdVar17);
        FUN_001236e4(uVar8,1,pdVar17);
        uVar8 = extraout_r4_00;
      }
    }
    uVar22 = *param_4 & 0xfe7fffff;
    *param_4 = uVar22;
  }
  if (((uVar22 & 0x3f0000) == 0x1c0000) &&
     ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 8) == 0)) {
    *param_4 = uVar22 & 0xffc0ffff | 0x10000;
    pdVar25 = param_4;
    if ((uVar22 & 0x400000) != 0) {
      pdVar25 = param_4 + 1;
    }
    bVar3 = false;
    *(short *)((int)param_4 + 2) = (short)pdVar25[1];
    uVar22 = *param_4 & 0xfbffffff;
    *param_4 = uVar22;
  }
  else {
    bVar3 = true;
  }
  if ((uVar24 == 0x20) && (bVar2 = true, (uVar22 & 0x1800000) == 0x1000000)) {
LAB_000fb800:
    pdVar25 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1);
    *(dword **)(*(int *)(param_1 + 8) + 0x3ac) = pdVar25;
    uVar22 = *param_4;
    uVar34 = uVar22 >> 0x10 & 0x3f;
    if (!bVar2) {
      uVar8 = 0xfe;
      if (uVar34 != 0x1c) {
        uVar8 = 0xfb;
      }
    }
    else {
      uVar8 = 0x10b;
    }
    iVar20 = 1;
    pdVar18 = pdVar31;
    if ((int)uVar22 < 0) {
      iVar20 = 2;
      pdVar18 = (dword *)((uint)pdVar31 | param_4[1] << 0x10);
    }
    if ((uVar22 & 0x400000) != 0) {
      iVar20 = iVar20 + 1;
    }
    if ((uVar22 & 0x1800000) == 0x1000000) {
      pdVar29 = param_4 + iVar20;
      if (!bVar2) {
        uVar35 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar9 = (undefined4 *)FUN_00193e18(uVar35,0x168);
        *puVar9 = uVar35;
        puVar9 = puVar9 + 1;
        FUN_00107980(puVar9,uVar8,*(undefined4 *)(param_1 + 8));
        uVar8 = FUN_000ec208(param_1,uVar34);
        pdVar17 = (dword *)((int)((unsigned char *)0x0) + 2);
        iVar6 = FUN_001054ec(puVar9,1);
        *(undefined4 *)(iVar6 + 0xc) = uVar8;
        *(dword **)(iVar6 + 8) = pdVar18;
      }
      else {
        pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
        puVar9 = FUN_001043f0(uVar8,*(undefined4 *)(param_1 + 8));
        puVar9[0x27] = 0;
        puVar9[0x50] = 0x10203;
        puVar9[0x21] = 2;
        uVar8 = FUN_000ec208(param_1,uVar34);
        iVar6 = FUN_001054ec(puVar9,2);
        *(undefined4 *)(iVar6 + 0xc) = uVar8;
        *(undefined4 *)(iVar6 + 8) = 0xffffffff;
      }
      uVar8 = FUN_000ec208(param_1,4);
      iVar6 = FUN_001054ec(puVar9,0);
      *(undefined4 *)(iVar6 + 0xc) = uVar8;
      *(dword **)(iVar6 + 8) = pdVar25;
      if ((*param_4 & 0x4000000) == 0) {
        dVar4 = *pdVar29;
        uVar8 = FUN_000ec208(param_1,*pdVar29 >> 0x10 & 0x3f);
        iVar20 = FUN_001054ec(puVar9,pdVar17);
        *(undefined4 *)(iVar20 + 0xc) = uVar8;
        *(uint *)(iVar20 + 8) = (uint)GH_F2U((float)((ushort)dVar4));
      }
      else {
        pdVar32 = (dword *)param_4[iVar20 + 2];
        pvVar10 = FUN_001043f0(0xc6,*(undefined4 *)(param_1 + 8));
        uVar8 = FUN_000ec208(param_1,4);
        iVar20 = FUN_001054ec(pvVar10,0);
        *(undefined4 *)(iVar20 + 0xc) = uVar8;
        *(dword **)(iVar20 + 8) = pdVar25;
        dVar4 = *pdVar29;
        uVar8 = FUN_000ec208(param_1,*pdVar29 >> 0x10 & 0x3f);
        iVar20 = FUN_001054ec(pvVar10,1);
        *(undefined4 *)(iVar20 + 0xc) = uVar8;
        *(uint *)(iVar20 + 8) = (uint)GH_F2U((float)((ushort)dVar4));
        ((int (*)())FUN_000f7870)(pvVar10,param_1,2,pdVar32,pdVar32,pdVar32,pdVar32);
        FUN_00193f64(param_2,pvVar10);
        uVar8 = FUN_000ec208(param_1,4);
        iVar20 = FUN_001054ec(puVar9,pdVar17);
        *(undefined4 *)(iVar20 + 0xc) = uVar8;
        *(dword **)(iVar20 + 8) = pdVar25;
      }
      (*(undefined4 *)((char *)frame_ + 8)) = 0x10203;
      ((int (*)())FUN_000f8aa0)(param_1,&(*(undefined4 *)((char *)frame_ + 8)),pdVar29,pdVar17,puVar9);
    }
    else if ((uVar22 & 0x1800000) == 0) {
      pdVar32 = (dword *)param_4[iVar20];
      uVar35 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar9 = (undefined4 *)FUN_00193e18(uVar35,0x168);
      *puVar9 = uVar35;
      puVar9 = puVar9 + 1;
      FUN_00107980(puVar9,uVar8,*(undefined4 *)(param_1 + 8));
      uVar8 = FUN_000ec208(param_1,4);
      iVar20 = FUN_001054ec(puVar9,0);
      *(undefined4 *)(iVar20 + 0xc) = uVar8;
      *(dword **)(iVar20 + 8) = pdVar25;
      uVar8 = FUN_000ec208(param_1,uVar34);
      iVar20 = FUN_001054ec(puVar9,1);
      *(undefined4 *)(iVar20 + 0xc) = uVar8;
      *(dword **)(iVar20 + 8) = pdVar18;
      ((int (*)())FUN_000f7870)(puVar9,param_1,2,pdVar32,pdVar32,pdVar32,pdVar32);
      pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
    }
    else {
      puVar9 = (undefined4 *)0x0;
      pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
    }
    iVar20 = FUN_001054ec(puVar9,pdVar17);
    local_94[0] = *(dword *)(iVar20 + 0x10);
    pdVar18 = local_94;
    param_5 = (dword *)0x0;
    piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
    iVar20 = (**(code **)(*piVar7 + 0x104))(piVar7,puVar9,pdVar17,pdVar18,0);
    if (iVar20 == 0) {
      iVar6 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar6;
      pvVar10 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      uVar35 = puVar9[0x32];
      uVar8 = puVar9[0x31];
      iVar20 = FUN_001054ec(pvVar10,1);
      *(undefined4 *)(iVar20 + 0xc) = uVar35;
      *(undefined4 *)(iVar20 + 8) = uVar8;
      uVar8 = FUN_000ec208(param_1,4);
      iVar20 = FUN_001054ec(pvVar10,0);
      *(undefined4 *)(iVar20 + 0xc) = uVar8;
      *(int *)(iVar20 + 8) = iVar6;
      iVar20 = FUN_001054ec(puVar9,2);
      uVar8 = *(undefined4 *)(iVar20 + 0x10);
      iVar20 = FUN_001054ec(pvVar10,1);
      *(undefined4 *)(iVar20 + 0x10) = uVar8;
      FUN_00193f64(param_2,pvVar10);
      uVar8 = FUN_000ec208(param_1,4);
      iVar20 = FUN_001054ec(puVar9,2);
      *(undefined4 *)(iVar20 + 0xc) = uVar8;
      *(int *)(iVar20 + 8) = iVar6;
      iVar20 = FUN_001054ec(puVar9,2);
      *(undefined4 *)(iVar20 + 0x10) = 0;
    }
    FUN_00193f64(param_2,puVar9);
    bVar3 = false;
    *param_4 = *param_4 & 0xffc0ffff | 0x40000;
    *(short *)((int)param_4 + 2) = (short)pdVar25;
    uVar8 = extraout_r4_02;
  }
  else {
    if (((undefined4 *)(uVar22 & 0x3f0000) == (undefined4 *)0x1c0000) ||
       ((undefined4 *)(uVar22 & 0x3f0000) == 0x001b0000)) {
      bVar2 = false;
      goto LAB_000fb800;
    }
    pdVar25 = (dword *)0x0;
    if ((uVar22 & 0x2000000) != 0) {
      pdVar25 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1);
      *(dword **)(*(int *)(param_1 + 8) + 0x3ac) = pdVar25;
      uVar22 = *param_4;
      if ((uVar22 & 0x400000) == 0) {
        pdVar32 = (dword *)((int)((unsigned char *)0x0) + 1);
        pdVar29 = (dword *)((int)((unsigned char *)0x0) + 1);
        param_5 = (dword *)((int)((unsigned char *)0x0) + 2);
      }
      else {
        pdVar32 = (dword *)((int)((unsigned char *)0x0) + 2);
        pdVar29 = (dword *)((int)((unsigned char *)0x0) + 2);
        param_5 = (dword *)((int)((unsigned char *)0x0) + 3);
      }
      if ((uVar22 & 0x1800000) == 0x1000000) {
        pdVar17 = param_4 + (int)pdVar29;
        pdVar18 = param_4 + (int)param_5;
        pdVar29 = (dword *)((int)pdVar32 + 2);
        if ((uVar22 & 0x4000000) == 0) {
          param_5 = (dword *)((int)pdVar32 + 3);
          pdVar26 = pdVar29;
        }
        else {
          pdVar29 = (dword *)((int)pdVar32 + 3);
          param_5 = pdVar32 + 1;
          pdVar26 = pdVar29;
        }
      }
      else {
        pdVar17 = (dword *)0x0;
        pdVar18 = (dword *)0x0;
        pdVar26 = pdVar32;
      }
      if ((param_4[(int)pdVar29] & 0x1800000) == 0x1000000) {
        pdVar30 = param_4 + (int)param_5;
        pdVar28 = (dword *)0x0;
        pdVar27 = param_4 + (int)((int)pdVar26 + 2);
        if ((param_4[(int)pdVar29] & 0x4000000) != 0) {
          pdVar28 = param_4 + (int)((int)pdVar26 + 3);
        }
      }
      else {
        pdVar30 = (dword *)0x0;
        pdVar27 = (dword *)0x0;
        pdVar28 = (dword *)0x0;
      }
      if (pdVar17 == (dword *)0x0) {
        if (pdVar30 != (dword *)0x0) {
          if ((pdVar18 != (dword *)0x0) || (pdVar27 == (dword *)0x0)) goto LAB_000fc43c;
          pdVar17 = FUN_001043f0(0xe6,*(undefined4 *)(param_1 + 8));
          dVar4 = *param_4;
          piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
          uVar8 = (**(code **)(*piVar7 + 0x9c))(piVar7,(short)dVar4);
          piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
          (**(code **)(*piVar7 + 0xa0))(&(*(undefined4 *)((char *)frame_ + 28)),piVar7,(short)dVar4);
          uVar35 = FUN_000ec208(param_1,4);
          iVar20 = FUN_001054ec(pdVar17,0);
          pdVar32 = ((unsigned char *)0x4);
          *(undefined4 *)(iVar20 + 0xc) = uVar35;
          *(dword **)(iVar20 + 8) = pdVar25;
          ((int (*)())FUN_000f7870)(pdVar17,param_1,1,4,4,4,4);
          dVar4 = *pdVar30;
          uVar35 = FUN_000ec208(param_1,*pdVar30 >> 0x10 & 0x3f);
          iVar20 = FUN_001054ec(pdVar17,2);
          *(undefined4 *)(iVar20 + 0xc) = uVar35;
          *(uint *)(iVar20 + 8) = (uint)GH_F2U((float)((ushort)dVar4));
          pdVar18 = (dword *)((int)((unsigned char *)0x0) + 2);
          (*(undefined4 *)((char *)frame_ + 8)) = 0x10203;
          param_5 = pdVar17;
          ((int (*)())FUN_000f8aa0)(param_1,&(*(undefined4 *)((char *)frame_ + 8)),pdVar30,2,pdVar17);
          FUN_00193f64(param_2,pdVar17);
          if ((pdVar28 != (dword *)0x0) && (*pdVar28 != 0)) {
            pvVar10 = FUN_001043f0(0xc6,*(undefined4 *)(param_1 + 8));
            uVar35 = FUN_000ec208(param_1,4);
            iVar20 = FUN_001054ec(pvVar10,0);
            *(undefined4 *)(iVar20 + 0xc) = uVar35;
            *(dword **)(iVar20 + 8) = pdVar25;
            uVar35 = FUN_000ec208(param_1,4);
            iVar20 = FUN_001054ec(pvVar10,1);
            *(undefined4 *)(iVar20 + 0xc) = uVar35;
            pdVar30 = (dword *)((int)((unsigned char *)0x0) + 2);
            *(dword **)(iVar20 + 8) = pdVar25;
            pdVar18 = (dword *)(*pdVar28 << 2);
            param_5 = pdVar18;
            pdVar32 = pdVar18;
            ((int (*)())FUN_000f7870)(pvVar10,param_1,2,pdVar18,pdVar18,pdVar18,pdVar18);
            iVar20 = FUN_001054ec(pvVar10,2);
            *(undefined4 *)(iVar20 + 0x10) = (*(undefined4 *)((char *)frame_ + 28));
            FUN_00193f64(param_2,pvVar10);
          }
          pvVar10 = FUN_001043f0(0xc6,*(undefined4 *)(param_1 + 8));
          uVar35 = FUN_000ec208(param_1,4);
          iVar20 = FUN_001054ec(pvVar10,0);
          *(undefined4 *)(iVar20 + 0xc) = uVar35;
          *(dword **)(iVar20 + 8) = pdVar25;
          uVar35 = FUN_000ec208(param_1,4);
          iVar20 = FUN_001054ec(pvVar10,1);
          *(undefined4 *)(iVar20 + 0xc) = uVar35;
          *(dword **)(iVar20 + 8) = pdVar25;
          iVar20 = FUN_001054ec(pvVar10,2);
          *(undefined4 *)(iVar20 + 0xc) = 0x1f;
          *(undefined4 *)(iVar20 + 8) = uVar8;
          iVar20 = FUN_001054ec(pvVar10,2);
          *(undefined4 *)(iVar20 + 0x10) = (*(undefined4 *)((char *)frame_ + 28));
          FUN_00193f64(param_2,pvVar10);
          pvVar10 = FUN_001043f0(0x68,*(undefined4 *)(param_1 + 8));
          uVar8 = FUN_000ec208(param_1,4);
          iVar20 = FUN_001054ec(pvVar10,0);
          *(undefined4 *)(iVar20 + 0xc) = uVar8;
          *(dword **)(iVar20 + 8) = pdVar25;
          *(undefined4 *)((int)pvVar10 + 0x130) = 0;
          pdVar17 = pdVar30;
LAB_000fc3f4:
          *(undefined4 *)((int)pvVar10 + 0x140) = 0x10203;
          uVar8 = FUN_000ec208(param_1,4);
          iVar20 = FUN_001054ec(pvVar10,1);
          *(undefined4 *)(iVar20 + 0xc) = uVar8;
          *(dword **)(iVar20 + 8) = pdVar25;
          iVar20 = FUN_001054ec(pvVar10,1);
          pvVar15 = (void *)0x0;
          *(undefined4 *)(iVar20 + 0x10) = 0;
          goto LAB_000fc74c;
        }
        uVar22 = (uint)*(ushort *)((int)param_4 + (int)pdVar29 * 4 + 2);
        pdVar29 = (dword *)(uint)(ushort)*param_4;
        if ((*(uint *)(param_1 + 0x30) & 0x40000) == 0) {
          pvVar15 = (void *)0x0;
          pvVar10 = FUN_001043f0(0x68,*(undefined4 *)(param_1 + 8));
          uVar8 = FUN_000ec208(param_1,4);
          iVar20 = FUN_001054ec(pvVar10,0);
          *(undefined4 *)(iVar20 + 0xc) = uVar8;
          *(dword **)(iVar20 + 8) = pdVar25;
          *(undefined4 *)((int)pvVar10 + 0x140) = 0x10203;
          *(uint *)((int)pvVar10 + 0x130) = uVar22;
          piVar7 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
          uVar8 = (**(code **)(*piVar7 + 0x9c))(piVar7,pdVar29);
          pdVar18 = *(dword **)(param_1 + 8);
          (**(code **)(*(*(int * *)(pdVar18 + (0xc3))) + 0xa0))(&(*(undefined4 *)((char *)frame_ + 24)));
          iVar20 = FUN_001054ec(pvVar10,1);
          *(undefined4 *)(iVar20 + 8) = uVar8;
          *(undefined4 *)(iVar20 + 0xc) = 0x1f;
          iVar20 = FUN_001054ec(pvVar10,1);
          *(undefined4 *)(iVar20 + 0x10) = (*(undefined4 *)((char *)frame_ + 24));
          pdVar17 = pdVar29;
          if (uVar22 == *param_6) {
            pdVar17 = *(dword **)(param_1 + 8);
            uVar35 = (**(code **)(*(*(int * *)(pdVar17 + (0xc3))) + 0xa8))((*(int * *)(pdVar17 + (0xc3))),&(*(undefined4 *)((char *)frame_ + 8)));
            pvVar15 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
            uVar8 = FUN_000ec208(param_1,4);
            iVar20 = FUN_001054ec(pvVar15,0);
            *(undefined4 *)(iVar20 + 0xc) = uVar8;
            *(dword **)(iVar20 + 8) = pdVar25;
            *(dword *)((int)pvVar15 + 0x9c) = param_6[1];
            iVar20 = FUN_001054ec(pvVar15,1);
            uVar8 = (*(undefined4 *)((char *)frame_ + 8));
            *(undefined4 *)(iVar20 + 0xc) = 0x1f;
            *(undefined4 *)(iVar20 + 8) = uVar35;
            iVar20 = FUN_001054ec(pvVar15,1);
            *(undefined4 *)(iVar20 + 0x10) = uVar8;
          }
          goto LAB_000fc74c;
        }
        iVar20 = (int)pdVar29 * 4;
        puVar37 = *(uint **)(iVar20 + param_7);
        if (puVar37 == (uint *)0x0) {
          uVar8 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
          puVar9 = (undefined4 *)FUN_00193e18(uVar8,0x14);
          puVar37 = puVar9 + 1;
          *puVar9 = uVar8;
          puVar9[1] = 2;
          puVar9[2] = 0;
          puVar9[4] = uVar8;
          uVar8 = FUN_00193e18(uVar8,8);
          puVar9[3] = uVar8;
          *(uint **)(iVar20 + param_7) = puVar37;
          uVar8 = extraout_r4_03;
        }
        if (uVar22 < *puVar37) {
          uVar34 = puVar37[1];
          if (uVar34 <= uVar22) {
            pdVar17 = (dword *)((uVar22 - uVar34) * 4 + 4);
            _memset(uVar34 * 4 + puVar37[2],0,pdVar17);
            puVar37[1] = uVar22 + 1;
            uVar8 = extraout_r4_04;
          }
          uVar39 = CONCAT44(uVar22 * 4 + puVar37[2],uVar8);
        }
        else {
          uVar39 = FUN_0019423c(puVar37,uVar22);
        }
        uVar8 = (undefined4)uVar39;
        if (*(int *)((ulonglong)uVar39 >> 0x20) == 0) {
          iVar6 = FUN_00109810(0xa4,*(undefined4 *)(param_1 + 8));
          *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) & 0xffff7fff;
          iVar38 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar38;
          iVar11 = FUN_001054ec(iVar6,0);
          *(int *)(iVar11 + 8) = iVar38;
          *(undefined4 *)(iVar11 + 0xc) = 0;
          *(dword **)(iVar6 + 0x130) = pdVar29;
          *(uint *)(iVar6 + 300) = uVar22;
          pdVar17 = *(dword **)(param_1 + 0x3a0);
          ((int (*)())FUN_000f92fc)(param_1,iVar6,pdVar17);
          puVar37 = *(uint **)(iVar20 + param_7);
          if (uVar22 < *puVar37) {
            uVar34 = puVar37[1];
            uVar8 = extraout_r4_05;
            if (uVar34 <= uVar22) {
              pdVar17 = (dword *)((uVar22 - uVar34) * 4 + 4);
              _memset(uVar34 * 4 + puVar37[2],0,pdVar17);
              puVar37[1] = uVar22 + 1;
              uVar8 = extraout_r4_06;
            }
            uVar39 = CONCAT44(uVar22 * 4 + puVar37[2],uVar8);
          }
          else {
            uVar39 = FUN_0019423c(puVar37,uVar22);
          }
          uVar8 = (undefined4)uVar39;
          *(int *)((ulonglong)uVar39 >> 0x20) = iVar6;
        }
        puVar37 = *(uint **)(iVar20 + param_7);
        if (uVar22 < *puVar37) {
          uVar34 = puVar37[1];
          if (uVar34 <= uVar22) {
            pdVar17 = (dword *)((uVar22 - uVar34) * 4 + 4);
            _memset(uVar34 * 4 + puVar37[2],0,pdVar17);
            puVar37[1] = uVar22 + 1;
            uVar8 = extraout_r4_07;
          }
          uVar39 = CONCAT44(uVar22 * 4 + puVar37[2],uVar8);
        }
        else {
          uVar39 = FUN_0019423c(puVar37,uVar22);
        }
        uVar8 = (undefined4)uVar39;
        pdVar25 = *(dword **)(*(int *)((ulonglong)uVar39 >> 0x20) + 0x94);
      }
      else {
        if (((pdVar18 != (dword *)0x0) && (pdVar30 == (dword *)0x0)) && (pdVar27 == (dword *)0x0)) {
          pdVar32 = ((unsigned char *)0x4);
          param_5 = pdVar25;
          ((int (*)())FUN_000f94dc)(param_1,param_2,pdVar17,pdVar18,pdVar25,4,*(undefined4 *)(param_1 + 0x400));
          uVar1 = *(ushort *)((int)param_4 + (int)pdVar29 * 4 + 2);
          pvVar10 = FUN_001043f0(0x68,*(undefined4 *)(param_1 + 8));
          uVar8 = FUN_000ec208(param_1,4);
          iVar20 = FUN_001054ec(pvVar10,0);
          *(undefined4 *)(iVar20 + 0xc) = uVar8;
          *(dword **)(iVar20 + 8) = pdVar25;
          *(uint *)((int)pvVar10 + 0x130) = (uint)uVar1;
          goto LAB_000fc3f4;
        }
LAB_000fc43c:
        ((int (*)())FUN_000f94dc)(param_1,param_2,pdVar17,pdVar18,pdVar25,4,*(undefined4 *)(param_1 + 0x400));
        uVar34 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) - 1;
        *(uint *)(*(int *)(param_1 + 8) + 0x3ac) = uVar34;
        uVar22 = (uint)(ushort)*pdVar30;
        if (pdVar28 != (dword *)0x0) {
          pvVar10 = FUN_001043f0(0xc6,*(undefined4 *)(param_1 + 8));
          uVar8 = FUN_000ec208(param_1,4);
          iVar20 = FUN_001054ec(pvVar10,0);
          *(undefined4 *)(iVar20 + 0xc) = uVar8;
          *(undefined4 *)((int)pvVar10 + 0x9c) = 0x10101;
          *(uint *)(iVar20 + 8) = uVar34;
          uVar19 = *pdVar28;
          ((int (*)())FUN_000f7870)(pvVar10,param_1,1,uVar19,uVar19,uVar19,uVar19);
          uVar8 = FUN_000ec208(param_1,*pdVar30 >> 0x10 & 0x3f);
          iVar20 = FUN_001054ec(pvVar10,2);
          *(undefined4 *)(iVar20 + 0xc) = uVar8;
          *(uint *)(iVar20 + 8) = uVar22;
          local_94[0] = 0x10203;
          ((int (*)())FUN_000f8aa0)(param_1,local_94,pdVar30,2,pvVar10);
          FUN_00193f64(param_2,pvVar10);
          *pdVar30 = *pdVar30 & 0xffc0ffff | 0x40000;
          uVar22 = uVar34;
        }
        pdVar29 = FUN_001043f0(0xe6,*(undefined4 *)(param_1 + 8));
        uVar8 = FUN_000ec208(param_1,4);
        iVar20 = FUN_001054ec(pdVar29,0);
        *(undefined4 *)(iVar20 + 0xc) = uVar8;
        pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
        pdVar29[0x27] = 0x10101;
        pdVar18 = ((unsigned char *)0x4);
        param_5 = ((unsigned char *)0x4);
        pdVar32 = ((unsigned char *)0x4);
        *(uint *)(iVar20 + 8) = uVar34;
        ((int (*)())FUN_000f7870)(pdVar29,param_1,1,4,4,4,4);
        uVar8 = FUN_000ec208(param_1,*pdVar30 >> 0x10 & 0x3f);
        iVar20 = FUN_001054ec(pdVar29,2);
        *(undefined4 *)(iVar20 + 0xc) = uVar8;
        *(uint *)(iVar20 + 8) = uVar22;
        (*(undefined4 *)((char *)frame_ + 8)) = 0x10203;
        if (pdVar28 == (dword *)0x0) {
          pdVar18 = (dword *)((int)((unsigned char *)0x0) + 2);
          param_5 = pdVar29;
          ((int (*)())FUN_000f8aa0)(param_1,&(*(undefined4 *)((char *)frame_ + 8)),pdVar30,2,pdVar29);
          pdVar17 = pdVar30;
        }
        else {
          iVar20 = FUN_001054ec(pdVar29,2);
          *(undefined4 *)(iVar20 + 0x10) = 0;
        }
        FUN_00193f64(param_2,pdVar29);
        pvVar10 = FUN_001043f0(0xc6,*(undefined4 *)(param_1 + 8));
        *(undefined4 *)((int)pvVar10 + 0x9c) = 0x10101;
        uVar8 = FUN_000ec208(param_1,4);
        iVar20 = FUN_001054ec(pvVar10,0);
        *(undefined4 *)(iVar20 + 0xc) = uVar8;
        *(dword **)(iVar20 + 8) = pdVar25;
        uVar8 = FUN_000ec208(param_1,4);
        iVar20 = FUN_001054ec(pvVar10,1);
        *(undefined4 *)(iVar20 + 0xc) = uVar8;
        *(dword **)(iVar20 + 8) = pdVar25;
        uVar8 = FUN_000ec208(param_1,4);
        iVar20 = FUN_001054ec(pvVar10,2);
        *(undefined4 *)(iVar20 + 0xc) = uVar8;
        *(uint *)(iVar20 + 8) = uVar34;
        iVar20 = FUN_001054ec(pvVar10,1);
        pvVar15 = (void *)0x0;
        *(undefined4 *)(iVar20 + 0x10) = 0;
        iVar20 = FUN_001054ec(pvVar10,2);
        *(undefined4 *)(iVar20 + 0x10) = 0;
        FUN_00193f64(param_2,pvVar10);
        pvVar10 = FUN_001043f0(0x68,*(undefined4 *)(param_1 + 8));
        uVar8 = FUN_000ec208(param_1,4);
        iVar20 = FUN_001054ec(pvVar10,0);
        *(undefined4 *)(iVar20 + 0xc) = uVar8;
        *(dword **)(iVar20 + 8) = pdVar25;
        *(undefined4 *)((int)pvVar10 + 0x130) = 0;
        *(undefined4 *)((int)pvVar10 + 0x140) = 0x10203;
        uVar8 = FUN_000ec208(param_1,4);
        iVar20 = FUN_001054ec(pvVar10,1);
        *(undefined4 *)(iVar20 + 0xc) = uVar8;
        *(dword **)(iVar20 + 8) = pdVar25;
        iVar20 = FUN_001054ec(pvVar10,1);
        *(undefined4 *)(iVar20 + 0x10) = 0;
LAB_000fc74c:
        FUN_00193f64(param_2,pvVar10);
        uVar8 = extraout_r4_08;
        if (pvVar15 != (void *)0x0) {
          FUN_00193f64(param_2,pvVar15);
          uVar8 = extraout_r4_09;
        }
      }
      bVar3 = false;
      *param_4 = *param_4 & 0xffc0ffff | 0x40000;
      *(short *)((int)param_4 + 2) = (short)pdVar25;
    }
  }
  if (uVar23 == 0) goto code_r0x000fd490;
  uVar22 = *param_4;
  if (((uVar22 & 0x400000) == 0) || ((param_4[1] & 0x4444) == 0)) {
    bVar2 = false;
  }
  else {
    uVar8 = FUN_0019e9fc(param_4,0);
    uVar35 = FUN_0019e9fc(param_4,1);
    uVar12 = FUN_0019e9fc(param_4,2);
    uVar13 = FUN_0019e9fc(param_4,3);
    pdVar18 = local_94;
    pdVar25 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1);
    *(dword **)(*(int *)(param_1 + 8) + 0x3ac) = pdVar25;
    pvVar10 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar20 = FUN_001054ec(pvVar10,0);
    *(undefined4 *)(iVar20 + 0xc) = 0;
    *(dword **)(iVar20 + 8) = pdVar25;
    uVar14 = FUN_000ec208(param_1,uVar24);
    iVar20 = FUN_001054ec(pvVar10,1);
    *(undefined4 *)(iVar20 + 0xc) = uVar14;
    *(dword **)(iVar20 + 8) = pdVar31;
    local_94[0] = 0x10203;
    fparam_1 = (double)((double (*)())FUN_000f8a30)(uVar8,0,&(*(undefined4 *)((char *)frame_ + 8)),pdVar18);
    fparam_2 = (double)((double (*)())FUN_000f8a30)(uVar35,1,&(*(undefined4 *)((char *)frame_ + 8)),pdVar18);
    fparam_3 = (double)((double (*)())FUN_000f8a30)(uVar12,2,&(*(undefined4 *)((char *)frame_ + 8)),pdVar18);
    fparam_4 = (double)((double (*)())FUN_000f8a30)(uVar13,3,&(*(undefined4 *)((char *)frame_ + 8)),pdVar18);
    dVar4 = local_94[0];
    iVar20 = FUN_001054ec(pvVar10,1);
    *(dword *)(iVar20 + 0x10) = dVar4;
    FUN_00193f64(param_2,pvVar10);
    pvVar10 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar20 = FUN_001054ec(pvVar10,0);
    *(undefined4 *)(iVar20 + 0xc) = 0;
    *(dword **)(iVar20 + 8) = pdVar25;
    pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
    ((void (*)())FUN_000f79c4)(pvVar10,param_1,1,fparam_1,fparam_2,fparam_3,fparam_4);
    *(undefined4 *)((int)pvVar10 + 0x9c) = (*(undefined4 *)((char *)frame_ + 8));
    FUN_00193f64(param_2,pvVar10);
    uVar22 = *param_4;
    uVar8 = extraout_r4_10;
    pdVar31 = pdVar25;
    if ((uVar22 & 0x400000) == 0) {
      uVar24 = 4;
      bVar2 = true;
    }
    else {
      uVar24 = 4;
      bVar2 = true;
      param_4[1] = param_4[1] & 0xffff8888 | 0x3210;
    }
  }
  if ((uVar22 & 0x400000) == 0) goto code_r0x000fd490;
  puVar21 = (undefined1 *)param_4[1];
  pdVar29 = param_4 + 1;
  if (((uint)puVar21 & 0xffff8888) == 0) goto code_r0x000fd490;
  pdVar26 = pdVar31;
  if (((ushort)*param_3 - 0x8e < 0x10) && (((uint)puVar21 & 0x8888) != 0)) {
    param_4[1] = (uint)puVar21 & 0xffff7777;
    pdVar26 = pdVar25;
    if (!bVar2) {
      puVar21 = *(undefined1 **)(param_1 + 8);
      pdVar26 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
      *(dword **)(puVar21 + 0x3ac) = pdVar26;
    }
    bVar2 = true;
    pvVar10 = FUN_001043f0(0xcb,*(undefined4 *)(param_1 + 8));
    iVar20 = FUN_001054ec(pvVar10,0);
    pdVar17 = (dword *)((int)((unsigned char *)0x0) + 2);
    *(undefined4 *)(iVar20 + 0xc) = 0;
    *(dword **)(iVar20 + 8) = pdVar26;
    ((void (*)())FUN_000f79c4)(pvVar10,param_1,2,0.0,0.0,0.0,0.0);
    uVar8 = FUN_000ec208(param_1,uVar24);
    iVar20 = FUN_001054ec(pvVar10,1);
    *(dword **)(iVar20 + 8) = pdVar31;
    *(undefined4 *)(iVar20 + 0xc) = uVar8;
    FUN_00193f64(param_2,pvVar10);
    uVar22 = *param_4;
    uVar8 = extraout_r4_11;
    uVar24 = 4;
    pdVar25 = pdVar26;
  }
  pdVar31 = pdVar26;
  if (((uVar22 & 0x400000) != 0) && ((*pdVar29 & 0x10000) != 0)) {
    pdVar31 = pdVar25;
    if (!bVar2) {
      puVar21 = *(undefined1 **)(param_1 + 8);
      pdVar31 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
      *(dword **)(puVar21 + 0x3ac) = pdVar31;
    }
    pvVar10 = FUN_001043f0(0x12,*(undefined4 *)(param_1 + 8));
    iVar20 = FUN_001054ec(pvVar10,0);
    *(undefined4 *)(iVar20 + 0xc) = 0;
    *(dword **)(iVar20 + 8) = pdVar31;
    uVar8 = FUN_000ec208(param_1,uVar24);
    iVar20 = FUN_001054ec(pvVar10,1);
    *(undefined4 *)(iVar20 + 0xc) = uVar8;
    *(dword **)(iVar20 + 8) = pdVar26;
    FUN_00103d50((int)pvVar10 + 0xa4,1,1);
    if (!bVar2) {
      ((int (*)())FUN_000f8f88)(param_4,pvVar10);
    }
    pdVar17 = (dword *)((int)((unsigned char *)0x0) + 2);
    uVar24 = 4;
    bVar2 = true;
    ((void (*)())FUN_000f79c4)(pvVar10,param_1,2,1.0,1.0,1.0,1.0);
    FUN_00193f64(param_2,pvVar10);
    uVar22 = *param_4;
    uVar8 = extraout_r4_12;
    pdVar25 = pdVar31;
  }
  if ((((uVar22 & 0x400000) == 0) || ((*pdVar29 & 0x20000) == 0)) || ((*pdVar29 & 0x40000) == 0)) {
    if (((uVar22 & 0x400000) == 0) || ((*pdVar29 & 0x20000) == 0)) {
      if (((uVar22 & 0x400000) == 0) || ((*pdVar29 & 0x40000) == 0)) goto code_r0x000fcda8;
      if (!bVar2) {
        puVar21 = *(undefined1 **)(param_1 + 8);
        pdVar25 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
        *(dword **)(puVar21 + 0x3ac) = pdVar25;
      }
      pvVar10 = FUN_001043f0(0x13,*(undefined4 *)(param_1 + 8));
      iVar20 = FUN_001054ec(pvVar10,0);
      *(undefined4 *)(iVar20 + 0xc) = 0;
      *(dword **)(iVar20 + 8) = pdVar25;
      uVar8 = FUN_000ec208(param_1,uVar24);
      iVar20 = FUN_001054ec(pvVar10,1);
      *(undefined4 *)(iVar20 + 0xc) = uVar8;
      *(dword **)(iVar20 + 8) = pdVar31;
      if (!bVar2) {
        ((int (*)())FUN_000f8f88)(param_4,pvVar10);
      }
      pdVar17 = (dword *)((int)((unsigned char *)0x0) + 2);
      ((void (*)())FUN_000f79c4)(pvVar10,param_1,2,2.0,2.0,2.0,2.0);
      pdVar31 = pdVar25;
    }
    else {
      if (!bVar2) {
        puVar21 = *(undefined1 **)(param_1 + 8);
        pdVar25 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
        *(dword **)(puVar21 + 0x3ac) = pdVar25;
      }
      pvVar10 = FUN_001043f0(0x12,*(undefined4 *)(param_1 + 8));
      iVar20 = FUN_001054ec(pvVar10,0);
      *(undefined4 *)(iVar20 + 0xc) = 0;
      *(dword **)(iVar20 + 8) = pdVar25;
      uVar8 = FUN_000ec208(param_1,uVar24);
      iVar20 = FUN_001054ec(pvVar10,1);
      *(undefined4 *)(iVar20 + 0xc) = uVar8;
      *(dword **)(iVar20 + 8) = pdVar31;
      if (!bVar2) {
        ((int (*)())FUN_000f8f88)(param_4,pvVar10);
      }
      ((void (*)())FUN_000f79c4)(pvVar10,param_1,2,0.5,0.5,0.5,0.5);
      pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
      FUN_00103d50((int)pvVar10 + 0xbc,1,1);
      pdVar31 = pdVar25;
    }
    FUN_00193f64(param_2,pvVar10);
    uVar22 = *param_4;
    uVar24 = 4;
    bVar2 = true;
    uVar8 = extraout_r4_14;
    pdVar25 = pdVar31;
  }
  else {
    if (!bVar2) {
      puVar21 = *(undefined1 **)(param_1 + 8);
      pdVar25 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
      *(dword **)(puVar21 + 0x3ac) = pdVar25;
    }
    pvVar10 = FUN_001043f0(0x14,*(undefined4 *)(param_1 + 8));
    iVar20 = FUN_001054ec(pvVar10,0);
    *(undefined4 *)(iVar20 + 0xc) = 0;
    *(dword **)(iVar20 + 8) = pdVar25;
    uVar8 = FUN_000ec208(param_1,uVar24);
    iVar20 = FUN_001054ec(pvVar10,1);
    *(undefined4 *)(iVar20 + 0xc) = uVar8;
    *(dword **)(iVar20 + 8) = pdVar31;
    if (!bVar2) {
      ((int (*)())FUN_000f8f88)(param_4,pvVar10);
    }
    uVar24 = 4;
    bVar2 = true;
    ((void (*)())FUN_000f79c4)(pvVar10,param_1,2,2.0,2.0,2.0,2.0);
    ((void (*)())FUN_000f79c4)(pvVar10,param_1,3,1.0,1.0,1.0,1.0);
    pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
    FUN_00103d50((int)pvVar10 + 0xd4,1,1);
    FUN_00193f64(param_2,pvVar10);
    uVar22 = *param_4;
    uVar8 = extraout_r4_13;
    pdVar31 = pdVar25;
  }
code_r0x000fcda8:
  pdVar26 = pdVar31;
  if (((uVar22 & 0x400000) != 0) && ((*pdVar29 & 0x80000) != 0)) {
    puVar21 = *(undefined1 **)(param_1 + 8);
    pdVar26 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
    *(dword **)(puVar21 + 0x3ac) = pdVar26;
    pvVar10 = FUN_001043f0(0x26,*(undefined4 *)(param_1 + 8));
    iVar20 = FUN_001054ec(pvVar10,0);
    *(undefined4 *)(iVar20 + 0xc) = 0;
    *(dword **)(iVar20 + 8) = pdVar26;
    uVar8 = FUN_000ec208(param_1,uVar24);
    iVar20 = FUN_001054ec(pvVar10,1);
    *(undefined4 *)(iVar20 + 0xc) = uVar8;
    *(dword **)(iVar20 + 8) = pdVar31;
    ((void (*)())FUN_000f79c4)(pvVar10,param_1,2,1.0,1.0,1.0,1.0);
    uVar8 = FUN_000ec208(param_1,uVar24);
    iVar20 = FUN_001054ec(pvVar10,3);
    *(undefined4 *)(iVar20 + 0xc) = uVar8;
    *(dword **)(iVar20 + 8) = pdVar31;
    if (!bVar2) {
      ((int (*)())FUN_000f8f88)(param_4,pvVar10);
      iVar20 = FUN_001054ec(pvVar10,1);
      uVar8 = *(undefined4 *)(iVar20 + 0x10);
      iVar20 = FUN_001054ec(pvVar10,3);
      *(undefined4 *)(iVar20 + 0x10) = uVar8;
    }
    FUN_00193f64(param_2,pvVar10);
    pvVar10 = FUN_001043f0(0x25,*(undefined4 *)(param_1 + 8));
    iVar20 = FUN_001054ec(pvVar10,0);
    *(undefined4 *)(iVar20 + 0xc) = 0;
    *(dword **)(iVar20 + 8) = pdVar26;
    iVar20 = FUN_001054ec(pvVar10,1);
    *(undefined4 *)(iVar20 + 0xc) = 0;
    uVar24 = 4;
    *(dword **)(iVar20 + 8) = pdVar26;
    iVar20 = FUN_001054ec(pvVar10,2);
    *(undefined4 *)(iVar20 + 0xc) = 0;
    *(dword **)(iVar20 + 8) = pdVar26;
    bVar2 = true;
    ((void (*)())FUN_000f79c4)(pvVar10,param_1,3,1.0,1.0,1.0,1.0);
    pdVar17 = (dword *)((int)((unsigned char *)0x0) + 1);
    FUN_00103d50((int)pvVar10 + 0xd4,1,1);
    FUN_00193f64(param_2,pvVar10);
    uVar22 = *param_4;
    uVar8 = extraout_r4_15;
    pdVar25 = pdVar26;
  }
  pdVar27 = pdVar26;
  if (((uVar22 & 0x400000) != 0) && (uVar23 = *pdVar29 >> 0x15 & 7, uVar23 != 0)) {
    puVar21 = (undefined1 *)**(undefined4 **)(*(int *)(param_1 + 8) + 0x30c);
    uVar39 = (**(code **)(puVar21 + 0xb4))();
    uVar8 = (undefined4)uVar39;
    if (((int)((ulonglong)uVar39 >> 0x20) == 0) ||
       ((pdVar17 = (dword *)(uint)(ushort)*param_3,
        (uint *)((int)&(*(GhidraMachOSection *)0x00000098).size + 2) < pdVar17 ||
        (pdVar17 != (dword *)((*(GhidraMachOSection *)0x00000054).sectname + 9))))) {
      if (uVar23 == 4) {
code_r0x000fd284:
        uVar22 = *param_4;
      }
      else {
        if (uVar23 == 1) {
          uVar35 = 0x10101;
          iVar20 = 1;
          uVar8 = 0x1000000;
        }
        else if (uVar23 == 2) {
          uVar35 = 0x101;
          iVar20 = 2;
          uVar8 = 0x1010000;
        }
        else {
          if (uVar23 != 3) goto code_r0x000fd284;
          uVar35 = 1;
          iVar20 = 3;
          uVar8 = 0x1010100;
        }
        pvVar10 = FUN_001043f0(0x40,*(undefined4 *)(param_1 + 8));
        pdVar27 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1);
        *(dword **)(*(int *)(param_1 + 8) + 0x3ac) = pdVar27;
        iVar6 = FUN_001054ec(pvVar10,0);
        *(undefined4 *)(iVar6 + 0xc) = 0;
        *(undefined4 *)((int)pvVar10 + 0x9c) = 0x1010100;
        *(dword **)(iVar6 + 8) = pdVar27;
        uVar12 = FUN_000ec208(param_1,uVar24);
        iVar6 = FUN_001054ec(pvVar10,1);
        *(undefined4 *)(iVar6 + 0xc) = uVar12;
        *(dword **)(iVar6 + 8) = pdVar26;
        pvVar15 = FUN_001043f0(0x13,*(undefined4 *)(param_1 + 8));
        iVar6 = FUN_001054ec(pvVar15,0);
        *(undefined4 *)(iVar6 + 0xc) = 0;
        *(dword **)(iVar6 + 8) = pdVar27;
        uVar12 = FUN_000ec208(param_1,uVar24);
        iVar6 = FUN_001054ec(pvVar15,1);
        *(undefined4 *)(iVar6 + 0xc) = uVar12;
        *(dword **)(iVar6 + 8) = pdVar26;
        pvVar16 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        iVar6 = FUN_001054ec(pvVar16,0);
        *(undefined4 *)(iVar6 + 0xc) = 0;
        *(dword **)(iVar6 + 8) = pdVar27;
        uVar12 = FUN_000ec208(param_1,uVar24);
        iVar6 = FUN_001054ec(pvVar16,1);
        *(undefined4 *)(iVar6 + 0xc) = uVar12;
        *(dword **)(iVar6 + 8) = pdVar26;
        if (!bVar2) {
          ((int (*)())FUN_000f8f88)(param_4,pvVar15);
          iVar6 = FUN_001054ec(pvVar15,1);
          uVar12 = *(undefined4 *)(iVar6 + 0x10);
          iVar6 = FUN_001054ec(pvVar16,1);
          *(undefined4 *)(iVar6 + 0x10) = uVar12;
        }
        iVar6 = FUN_001054ec(pvVar15,2);
        puVar5 = PTR_DAT_001e8b8c;
        *(undefined4 *)(iVar6 + 0xc) = 0;
        uVar12 = *(undefined4 *)(puVar5 + 0xc);
        uVar24 = 4;
        *(dword **)(iVar6 + 8) = pdVar27;
        iVar6 = FUN_001054ec(pvVar15,2);
        *(undefined4 *)(iVar6 + 0x10) = uVar12;
        iVar6 = FUN_001054ec(pvVar15,1);
        puVar21 = &STACKARG(0xffffff30) + iVar20;
        (*(undefined4 *)((char *)frame_ + 32)) = *(undefined4 *)(iVar6 + 0x10);
        bVar2 = true;
        uVar12 = *(undefined4 *)(puVar5 + (uint)*(byte *)((int)&(*(undefined4 *)((char *)frame_ + 32)) + iVar20) * 4);
        iVar20 = FUN_001054ec(pvVar10,1);
        *(undefined4 *)(iVar20 + 0x10) = uVar12;
        *(undefined4 *)((int)pvVar15 + 0x9c) = uVar35;
        *(undefined4 *)((int)pvVar16 + 0x9c) = uVar8;
        FUN_00193f64(param_2,pvVar10);
        FUN_00193f64(param_2,pvVar15);
        FUN_00193f64(param_2,pvVar16);
        uVar22 = *param_4;
        uVar8 = extraout_r4_17;
        pdVar25 = pdVar27;
      }
    }
    else if (uVar23 == 3) {
      *(undefined4 *)(param_1 + 0x47c) = 1;
      uVar22 = *param_4;
    }
    else {
      if (uVar23 != 2) goto code_r0x000fd284;
      puVar21 = *(undefined1 **)(param_1 + 8);
      *(undefined4 *)(param_1 + 0x47c) = 1;
      bVar2 = true;
      pdVar27 = (dword *)(*(int *)(puVar21 + 0x3ac) + -1);
      *(dword **)(puVar21 + 0x3ac) = pdVar27;
      piVar7 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      iVar20 = FUN_001054ec(piVar7,0);
      *(undefined4 *)(iVar20 + 0xc) = 0;
      *(dword **)(iVar20 + 8) = pdVar27;
      uVar8 = FUN_000ec208(param_1,uVar24);
      iVar20 = FUN_001054ec(piVar7,1);
      *(undefined4 *)(iVar20 + 0xc) = uVar8;
      *(dword **)(iVar20 + 8) = pdVar26;
      ((int (*)())FUN_000f8f88)(param_4,piVar7);
      pcVar36 = *(code **)(*piVar7 + 0x88);
      iVar20 = FUN_001054ec(piVar7,1);
      pdVar18 = (dword *)(uint)*(byte *)(iVar20 + 0x12);
      pdVar17 = (dword *)((int)((unsigned char *)0x0) + 3);
      (*pcVar36)(piVar7,1);
      FUN_00193f64(param_2,piVar7);
      uVar22 = *param_4;
      uVar8 = extraout_r4_16;
      uVar24 = 4;
      pdVar25 = pdVar27;
    }
  }
  pdVar31 = pdVar27;
  if (((((uVar22 & 0x400000) != 0) && ((*pdVar29 & 0x8888) != 0)) &&
      (uVar22 = FUN_0019eaa4(param_4,uVar8,pdVar17,pdVar18,param_5,pdVar32,puVar21), uVar22 != 0))
     && (uVar22 != 0x8888)) {
    pdVar31 = pdVar25;
    if (!bVar2) {
      pdVar31 = (dword *)(*(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1);
      *(dword **)(*(int *)(param_1 + 8) + 0x3ac) = pdVar31;
    }
    pvVar10 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar20 = FUN_001054ec(pvVar10,0);
    *(dword **)(iVar20 + 8) = pdVar31;
    *(undefined4 *)(iVar20 + 0xc) = 0;
    uVar8 = FUN_000ec208(param_1,uVar24);
    iVar20 = FUN_001054ec(pvVar10,1);
    *(undefined4 *)(iVar20 + 0xc) = uVar8;
    *(dword **)(iVar20 + 8) = pdVar27;
    if (!bVar2) {
      ((int (*)())FUN_000f8f88)(param_4,pvVar10);
    }
    if (((*param_4 & 0x400000) != 0) && ((*pdVar29 & 0x100000) != 0)) {
      FUN_00103d50((int)pvVar10 + 0xa4,2,1);
    }
    FUN_00193f64(param_2,pvVar10);
    iVar20 = FUN_001054ec(pvVar10,1);
    uVar35 = *(undefined4 *)(iVar20 + 0x10);
    pvVar10 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar20 = FUN_001054ec(pvVar10,0);
    *(undefined4 *)(iVar20 + 0xc) = 0;
    *(dword **)(iVar20 + 8) = pdVar31;
    uVar8 = FUN_000ec208(param_1,uVar24);
    iVar20 = FUN_001054ec(pvVar10,1);
    *(undefined4 *)(iVar20 + 0xc) = uVar8;
    *(dword **)(iVar20 + 8) = pdVar27;
    if (!bVar2) {
      iVar20 = FUN_001054ec(pvVar10,1);
      *(undefined4 *)(iVar20 + 0x10) = uVar35;
    }
    FUN_00103d50((int)pvVar10 + 0xa4,1,1);
    if ((((*param_4 & 0x400000) != 0) && ((*pdVar29 & 0x100000) != 0)) &&
       (FUN_00103d50((int)pvVar10 + 0xa4,2,1), (*param_4 & 0x400000) != 0)) {
      *pdVar29 = *pdVar29 & 0xffefffff;
    }
    *(uint *)((int)pvVar10 + 0x9c) =
         uVar22 >> 0xf & 1 ^ 1 |
         (uVar22 >> 0xb & 1 ^ 1) << 8 |
         (uVar22 >> 7 & 1 ^ 1) << 0x10 | (uVar22 >> 3 & 1 ^ 1) << 0x18;
    FUN_00193f64(param_2,pvVar10);
    if ((*param_4 & 0x400000) != 0) {
      *pdVar29 = *pdVar29 & 0xffff7777;
    }
    uVar24 = 4;
  }
code_r0x000fd490:
  if (bVar3) {
    *(short *)((int)param_4 + 2) = (short)pdVar31;
    *param_4 = uVar24 << 0x10 | *param_4 & 0xffc0ffff;
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
    _memset(uVar3 * 4 + param_6[2],0,4);
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
  uint uVar10;
  uint *****pppppuVar11;
  uint *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  uint *****pppppuVar15;
  void *pvVar16;
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
  undefined2 uVar31;
  undefined4 *puVar28;
  undefined4 *puVar29;
  uint ****ppppuVar30;
  undefined4 *puVar32;
  uint ******in_r6;
  uint ******in_r7;
  uint ******in_r8;
  uint ***pppuVar33;
  int iVar34;
  uint *puVar35;
  int *piVar36;
  uint ******ppppppuVar37;
  uint ******ppppppuVar38;
  uint ******ppppppuVar39;
  uint ******ppppppuVar40;
  undefined4 uVar41;
  uint ***pppuVar42;
  int iVar43;
  uint uVar44;
  uint ****ppppuVar45;
  undefined4 uVar46;
  int iVar47;
  uint ******ppppppuVar48;
  uint ******ppppppuVar49;
  undefined4 uVar50;
  uint ****ppppuVar51;
  uint *****pppppuVar52;
  undefined1 *puVar53;
  double dVar54;
  /* issue #64 live-repro (2nd instance, same function): FUN_001940a8((*(undefined1 * *)((char *)frame_ + 292))=auStack_16c), two lines
   * below FUN_001940a8((*(undefined1 * *)((char *)frame_ + 296))=auStack_154) which already got this fix, writes the same 6-word/0x18-byte
   * sentinel-list header (see the comment on auStack_154 just below) - word[2] (self-referential "next",
   * param_1[2] = param_1+3) is what `local_164`'s four loops read as the list head, same shape as
   * local_14c's. auStack_16c was declared only 8 bytes with local_164 as a separate scalar 8 bytes in;
   * live-confirmed the pointer this yields (local_164, still holding the list head's own address) is a
   * real allocation but reads back as MallocPreScribble's 0xAA fill - i.e. never received the init write,
   * same root cause as local_14c's, just missed by that fix since it's a second, independent instance.
   * Merged into one 0x18-byte buffer the same way, aliased back to the original name. */
  unsigned char auStack_16c [0x18];
#define local_164 (*(int *)(auStack_16c + 0x08))
  /* issue #64 live-repro: FUN_001940a8 (called below via (*(undefined1 * *)((char *)frame_ + 296))=auStack_154) writes param_1[0]
   * through param_1[5] - 6 words, 0x18 bytes - into whatever auStack_154 points to, including a
   * self-referential empty-list-head init at param_1[2] (offset 8: *(auStack_154+8) = auStack_154+12).
   * auStack_154 was declared only 8 bytes; local_14c (used as a list head in four separate loops
   * later in this function) sits exactly at that offset-8 slot by its own hex name (0x154-0x14c=8),
   * and the 12 bytes after it (up to (*(uint * *)((char *)frame_ + 84)), 0x154-0x13c=0x18) are the same buffer's remaining
   * two words, never individually named. Left separate, local_14c never receives its initializer at
   * all in the rebuild (confirmed live: read as garbage/uninitialized), corrupting every one of the
   * four unlink loops that use it as a list head - traced down to a crash in FUN_0019401c, a plain
   * linked-list unlink helper, dereferencing garbage. Merged into one 0x18-byte buffer. */
  unsigned char auStack_154 [0x18];
#define local_14c (*(int *)(auStack_154 + 0x08))
  unsigned int frame_[100] __attribute__((aligned(16)));
  
  iVar34 = *(int *)(*(int *)(param_1 + 8) + 0x30c);
  (*(uint *)((char *)frame_ + 244)) = 0;
  (*(uint *)((char *)frame_ + 248)) = 0;
  *(uint *)(iVar34 + 8) = *(uint *)(iVar34 + 8) & 0xffffffdf;
  (*(uint *)((char *)frame_ + 252)) = 0;
  uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  iVar34 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0x50);
  uVar10 = iVar34 + 0x1fU >> 5;
  puVar13 = (undefined4 *)FUN_00193e18(uVar46,uVar10 * 4 + 0xc);
  (*(undefined4 * *)((char *)frame_ + 240)) = puVar13 + 1;
  *puVar13 = uVar46;
  puVar13[1] = uVar10;
  puVar13[2] = iVar34;
  (*(uint *)((char *)frame_ + 256)) = 0;
  (*(uint *)((char *)frame_ + 260)) = 0;
  (*(uint ***** *)((char *)frame_ + 264)) = (uint *****)0x0;
  (*(uint ***** *)((char *)frame_ + 268)) = (uint *****)0x0;
  (*(uint *)((char *)frame_ + 272)) = 0;
  if (uVar10 != 0) {
    puVar13 = (*(undefined4 * *)((char *)frame_ + 240));
    if (uVar10 == 0) {
      uVar10 = 1;
    }
    do {
      uVar10 = uVar10 - 1;
      puVar13[2] = 0;
      puVar13 = puVar13 + 1;
    } while (uVar10 != 0);
  }
  uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar13 = (undefined4 *)FUN_00193e18(uVar46,0x14);
  ppppppuVar37 = (uint ******)(puVar13 + 1);
  *puVar13 = uVar46;
  puVar13[1] = 2;
  puVar13[4] = uVar46;
  puVar13[2] = 0;
  uVar46 = FUN_00193e18(uVar46,8);
  puVar13[3] = uVar46;
  (*(uint **** *)((char *)frame_ + 8)) = (uint ****)0x0;
  uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar14 = (undefined4 *)FUN_00193e18(uVar46,0x14);
  (*(uint ***** *)((char *)frame_ + 232)) = (uint *****)(puVar14 + 1);
  *puVar14 = uVar46;
  puVar14[1] = 2;
  puVar14[4] = uVar46;
  puVar14[2] = 0;
  pppppuVar15 = (uint *****)FUN_00193e18(uVar46,8);
  (*(uint ***** *)((char *)frame_ + 232))[2] = (uint ****)pppppuVar15;
  uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar14 = (undefined4 *)FUN_00193e18(uVar46,0x14);
  (*(uint * *)((char *)frame_ + 224)) = puVar14 + 1;
  *puVar14 = uVar46;
  puVar14[1] = 2;
  puVar14[2] = 0;
  puVar14[4] = uVar46;
  uVar10 = FUN_00193e18(uVar46,8);
  (*(uint * *)((char *)frame_ + 224))[2] = uVar10;
  uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar14 = (undefined4 *)FUN_00193e18(uVar46,0x14);
  puVar14[1] = 2;
  *puVar14 = uVar46;
  puVar14[2] = 0;
  puVar14[4] = uVar46;
  uVar46 = FUN_00193e18(uVar46,8);
  puVar14[3] = uVar46;
  *(undefined4 **)(param_1 + 0x414) = puVar14 + 1;
  uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
  puVar14 = (undefined4 *)FUN_00193e18(uVar46,0x14);
  puVar14[1] = 2;
  *puVar14 = uVar46;
  puVar14[2] = 0;
  puVar14[4] = uVar46;
  uVar46 = FUN_00193e18(uVar46,8);
  puVar14[3] = uVar46;
  (*(undefined * *)((char *)frame_ + 308)) = &DAT_001ad5d8;
  (*(uint ***** *)((char *)frame_ + 12)) = *(uint ******)(param_1 + 0x3a0);
  (*(undefined4 *)((char *)frame_ + 104)) = 0;
  (*(uint ***** *)((char *)frame_ + 32)) = (uint *****)0x1010101;
  (*(uint **** *)((char *)frame_ + 28)) = (uint ****)0xffffffff;
  (*(undefined4 *)((char *)frame_ + 88)) = 0;
  (*(undefined4 *)((char *)frame_ + 92)) = 0;
  (*(undefined4 *)((char *)frame_ + 96)) = 0;
  (*(undefined4 *)((char *)frame_ + 100)) = 0;
  uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
  (*(uint * *)((char *)frame_ + 84)) = puVar14 + 1;
  puVar14 = (undefined4 *)FUN_00193e18(uVar46,0x130);
  *puVar14 = uVar46;
  ppppppuVar49 = (uint ******)(puVar14 + 1);
  FUN_000ea020(ppppppuVar49,*(undefined4 *)(param_1 + 8));
  (*(uint ***** *)((char *)frame_ + 16)) = (uint *****)ppppppuVar49;
  FUN_000ec3ac(param_1,(*(uint ***** *)((char *)frame_ + 12)),ppppppuVar49);
  (*(undefined1 * *)((char *)frame_ + 292)) = auStack_16c;
  FUN_000e8e4c((*(uint ***** *)((char *)frame_ + 12)),(*(uint ***** *)((char *)frame_ + 16)));
  (*(undefined1 * *)((char *)frame_ + 296)) = auStack_154;
  (*(uint ***** *)((char *)frame_ + 12)) = (*(uint ***** *)((char *)frame_ + 16));
  FUN_001940a8((*(undefined1 * *)((char *)frame_ + 292)));
  FUN_001940a8((*(undefined1 * *)((char *)frame_ + 296)));
  *(undefined4 *)(param_1 + 0x3d4) = 0;
  *(undefined4 *)(param_1 + 0x3e4) = 0;
  ((int (*)())FUN_000fb230)(param_1,param_2);
  (*(uint ***** *)((char *)frame_ + 236)) = (uint *****)0x0;
  (*(int *)((char *)frame_ + 228)) = 0;
switchD_000fdaf0_caseD_2:
  iVar34 = FUN_000e5e70(param_2);
  if (iVar34 == 0) {
code_r0x00103c40:
    FUN_000ec728(param_1);
    FUN_000e8e4c((*(uint ***** *)((char *)frame_ + 16)),*(undefined4 *)(param_1 + 0x3a8));
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 2;
    FUN_0012e8c0(param_1,*(undefined4 *)(param_1 + 0x3a0),*(undefined4 *)(param_1 + 0x3a8));
    if ((uint ******)(*(uint ***** *)((char *)frame_ + 232)) != (uint ******)0x0) {
      FUN_00193cc0((*(uint ***** *)((char *)frame_ + 232))[3],(*(uint ***** *)((char *)frame_ + 232))[2]);
      FUN_00193cc0((*(uint ***** *)((char *)frame_ + 232))[-1],(*(uint ***** *)((char *)frame_ + 232)) + -1);
    }
    if (ppppppuVar37 != (uint ******)0x0) {
      FUN_00193cc0(puVar13[4],puVar13[3]);
      FUN_00193cc0(*puVar13,puVar13);
    }
    if ((*(undefined4 * *)((char *)frame_ + 240)) != (undefined4 *)0x0) {
      FUN_00193cc0((*(undefined4 * *)((char *)frame_ + 240))[-1],(*(undefined4 * *)((char *)frame_ + 240)) + -1);
    }
    FUN_00193cc0(*(undefined4 *)(*(int *)(param_1 + 8) + 0x378),*(undefined4 *)(param_1 + 0x78));
    FUN_0011e894(param_1);
    return;
  }
  iVar34 = FUN_000e43ec(param_2);
  if (iVar34 != 0) {
    iVar34 = *(int *)(param_1 + 0x3c4);
    iVar43 = 0;
    (*(int * *)((char *)frame_ + 20)) = (int *)0x0;
    for (uVar10 = 1; uVar10 <= *(uint *)(iVar34 + 4); uVar10 = uVar10 + 1) {
      (*(int * *)((char *)frame_ + 20)) = *(int **)(iVar43 + *(int *)(iVar34 + 8));
      if (((*(int * *)((char *)frame_ + 20))[5] & 1U) != 0) {
        (**(code **)(*(*(int * *)((char *)frame_ + 20)) + 0x68))((*(int * *)((char *)frame_ + 20)));
        piVar18 = (*(int * *)((char *)frame_ + 20));
        pvVar16 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(pvVar16,1,(*(int * *)((char *)frame_ + 20))[0x29]);
        puVar12 = (*(uint * *)((char *)frame_ + 84));
        uVar44 = piVar18[0x50];
        if (uVar44 < *(*(uint * *)((char *)frame_ + 84))) {
          uVar17 = (*(uint * *)((char *)frame_ + 84))[1];
          if (uVar17 <= uVar44) {
            _memset(uVar17 * 4 + (*(uint * *)((char *)frame_ + 84))[2],0,(uVar44 - uVar17) * 4 + 4);
            puVar12[1] = uVar44 + 1;
          }
          puVar14 = (undefined4 *)(uVar44 * 4 + puVar12[2]);
        }
        else {
          puVar14 = (undefined4 *)FUN_0019423c((*(uint * *)((char *)frame_ + 84)),uVar44);
        }
        *puVar14 = pvVar16;
        iVar34 = *(int *)(param_1 + 0x3c4);
      }
      iVar43 = iVar43 + 4;
    }
    piVar18 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
    (**(code **)(*piVar18 + 0x17c))(piVar18,param_1);
    FUN_000e5e70(param_2);
  }
  ppppppuVar49 = param_2 + 0x23;
  *(undefined4 *)(param_1 + 0x47c) = 0;
  iVar34 = FUN_000e4408(param_2);
  if (iVar34 == 0x52) {
    *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x100;
  }
  else if (((iVar34 == 0x84) && ((*(uint *)(param_1 + 0x30) & 0x40000) != 0)) &&
          ((*(uint *)(param_1 + 0x30) & 0x200000) == 0)) goto code_r0x00103c40;
  iVar43 = *(int *)(param_1 + 8);
  piVar18 = *(int **)(iVar43 + 0x30c);
  iVar47 = piVar18[3];
  uVar46 = ((int (*)())FUN_000f89a4)(iVar34,iVar47);
  switch(uVar46) {
  case 0:
  case 1:
    switch(iVar34) {
    case 0x14:
      if ((*(uint *)(param_1 + 0x30) & 0x4000) == 0) {
        ppppuVar45 = *param_2[0x1b];
        iVar34 = FUN_000ec208(param_1,(uint)*ppppuVar45 >> 0x10 & 0x3f);
        iVar43 = *(int *)(param_1 + 8);
        if (((((uint)*ppppuVar45 & 0x3f0000) == 0x100000) && (iVar43 != 0)) &&
           ((*(uint *)(*(int *)(iVar43 + 0x30c) + 8) & 0x80) != 0)) {
          iVar47 = 0xf;
        }
        else {
          iVar47 = (int)*(short *)((int)ppppuVar45 + 2);
        }
        if (((((uint)*param_2[0x1b][1] & 0x3f0000) == 0x100000) && (iVar43 != 0)) &&
           ((*(uint *)(*(int *)(iVar43 + 0x30c) + 8) & 0x80) != 0)) {
          iVar43 = 0xf;
        }
        else {
          iVar43 = (int)*(short *)((int)param_2[0x1b][1] + 2);
        }
        if (iVar34 == 0x15) {
code_r0x000fed00:
          if ((*(uint *)(param_1 + 0x30) & 0x4000) == 0) {
            *(int *)(param_1 + 1000) = iVar47;
            *(undefined4 *)(param_1 + 0x3e4) = 1;
            *(int *)(param_1 + 0x3ec) = iVar43 + 1;
            *(int *)(param_1 + 0x3f4) = iVar34;
            if (((*(uint *)(param_1 + 0x30) & 1) != 0) && (iVar47 < iVar43 + 1)) {
              do {
                in_r6 = (uint ******)0x0;
                FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),iVar34,iVar47,0);
                iVar47 = iVar47 + 1;
              } while (iVar47 < *(int *)(param_1 + 0x3ec));
            }
          }
          goto switchD_000fdaf0_caseD_2;
        }
        if (iVar34 < 0x16) {
          if (iVar34 != 0x14) goto switchD_000fdaf0_caseD_2;
        }
        else if (iVar34 != 0x1a) {
          if (iVar34 == 0x24) goto code_r0x000fed00;
          goto switchD_000fdaf0_caseD_2;
        }
        *(int *)(param_1 + 1000) = iVar47;
        *(undefined4 *)(param_1 + 0x3e4) = 1;
        *(int *)(param_1 + 0x3ec) = iVar43 + 1;
        *(int *)(param_1 + 0x3f4) = iVar34;
        if (((*(uint *)(param_1 + 0x30) & 1) != 0) && (iVar47 < iVar43 + 1)) {
          do {
            in_r6 = (uint ******)0x0;
            FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),iVar34,iVar47,0);
            iVar47 = iVar47 + 1;
          } while (iVar47 < *(int *)(param_1 + 0x3ec));
        }
      }
    default:
      goto switchD_000fdaf0_caseD_2;
    case 0x16:
    case 0x18:
      if ((*(uint *)(*(int *)(iVar43 + 0x6c4) + 0x30) & 0x2000) != 0) {
        pppuVar42 = **param_2[0x19];
        uVar10 = (uint)pppuVar42 >> 0x10 & 0x3f;
        if (((((uint)pppuVar42 & 0x3f0000) == 0x100000) && (iVar43 != 0)) &&
           ((piVar18[2] & 0x80U) != 0)) {
          ppppppuVar19 = (uint ******)((int)((unsigned char *)0xc) + 3);
        }
        else {
          ppppppuVar19 = (uint ******)(int)*(short *)((int)*param_2[0x19] + 2);
        }
        uVar46 = FUN_000ec208(param_1,uVar10);
        in_r6 = (uint ******)FUN_000ec2a0(param_1,uVar10);
        iVar34 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),uVar46,ppppppuVar19,0);
        iVar34 = *(int *)(iVar34 + 0x38);
        FUN_001041d0(iVar34,0,(uint)*ppppppuVar49 >> 0x10 & 3,in_r6,ppppppuVar19);
        FUN_001041d0(iVar34,1,(uint)*ppppppuVar49 >> 0x12 & 3,in_r6,ppppppuVar19);
        FUN_001041d0(iVar34,2,(uint)*ppppppuVar49 >> 0x14 & 3,in_r6,ppppppuVar19);
        in_r7 = ppppppuVar19;
        FUN_001041d0(iVar34,3,(uint)*ppppppuVar49 >> 0x16 & 3,in_r6,ppppppuVar19);
        pppppuVar15 = *ppppppuVar49;
        if (((uint)pppppuVar15 & 0x1000000) != 0) {
          *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 1;
          pppppuVar15 = *ppppppuVar49;
        }
        *(uint *******)(iVar34 + 0x148) = ppppppuVar19;
        *(uint *)(iVar34 + 0x140) = (uint)pppppuVar15 >> 0x19 & 1;
        *(undefined4 *)(iVar34 + 0x144) = uVar46;
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x17:
      ppppppuVar19 = (uint ******)FUN_000ec27c(param_1,(uint)*ppppppuVar49 >> 0x10 & 0x1f);
      ppppppuVar38 = (uint ******)((uint)*ppppppuVar49 >> 0x15 & 0xff);
      if ((int)*ppppppuVar49 < 0) {
        pppppuVar15 = param_2[0x24];
        uVar17 = (uint)pppppuVar15 >> 9 & 1;
        uVar10 = (uint)pppppuVar15 >> 8 & 1;
        uVar44 = (uint)pppppuVar15 >> 10 & 1;
        (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)
                    (CONCAT31(CONCAT21(CONCAT11((char)pppppuVar15,(char)((uint)pppppuVar15 >> 2)),
                                       (char)((uint)pppppuVar15 >> 4)),
                              (char)((uint)pppppuVar15 >> 6)) & 0x3030303);
      }
      else {
        uVar10 = 0;
        uVar44 = 0;
        uVar17 = 0;
        (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)0x3030303;
      }
      iVar43 = (int)*(short *)((int)*param_2[0x19] + 2);
      uVar46 = FUN_000ec208(param_1,(uint)**param_2[0x19] >> 0x10 & 0x3f);
      iVar34 = *(int *)(param_1 + 1000);
      if (iVar43 <= *(int *)(param_1 + 1000)) {
        iVar34 = iVar43;
      }
      iVar47 = *(int *)(param_1 + 0x3ec);
      *(int *)(param_1 + 1000) = iVar34;
      if (iVar47 <= iVar43) {
        iVar47 = iVar43 + 1;
      }
      *(int *)(param_1 + 0x3ec) = iVar47;
      *(undefined4 *)(param_1 + 0x3f4) = 0x24;
      in_r6 = (uint ******)0x0;
      iVar34 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),uVar46,iVar43,0);
      iVar34 = *(int *)(iVar34 + 0x38);
      if (uVar10 == 0) {
        *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 1;
      }
      if (uVar44 != 0) {
        *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 4;
      }
      if (uVar17 != 0) {
        *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 2;
      }
      (*(undefined4 * *)((char *)frame_ + 288)) = &(*(undefined4 *)((char *)frame_ + 24));
      iVar43 = 0;
      do {
        if (*(byte *)(iVar43 + (int)(*(undefined4 * *)((char *)frame_ + 288))) != 0) {
          in_r6 = ppppppuVar19;
          in_r7 = ppppppuVar38;
          FUN_001041d0(iVar34,iVar43,(uint)*(byte *)(iVar43 + (int)(*(undefined4 * *)((char *)frame_ + 288))),ppppppuVar19,
                       ppppppuVar38);
        }
        bVar1 = iVar43 != 3;
        iVar43 = iVar43 + 1;
      } while (bVar1);
      goto switchD_000fdaf0_caseD_2;
    case 0x19:
      bVar4 = *(byte *)((int)param_2 + 0x8d);
      pppppuVar15 = *ppppppuVar49;
      iVar34 = (uint)bVar4 * 0xc;
      *(uint *)(*(int *)(param_1 + 0x78) + iVar34) = (uint)pppppuVar15 >> 0x1b & 3;
      if (*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0x50) < (int)(uint)bVar4) {
        FUN_000e1534(*(int *)(param_1 + 8),7);
      }
      uVar10 = bVar4 >> 3 & 0x1c;
      *(uint *)((int)(*(undefined4 * *)((char *)frame_ + 240)) + uVar10 + 8) =
           1 << (bVar4 & 0x1f) | *(uint *)((int)(*(undefined4 * *)((char *)frame_ + 240)) + uVar10 + 8);
      *(uint *)(iVar34 + *(int *)(param_1 + 0x78) + 8) = (uint)*ppppppuVar49 >> 0x1d & 1;
      piVar18 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
      iVar43 = (**(code **)(*piVar18 + 0x48))(piVar18,param_1,(uint)pppppuVar15 >> 0x18 & 7);
      if (iVar43 != 0) {
        *(int *)(iVar34 + *(int *)(param_1 + 0x78) + 4) = iVar43;
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x1a:
      FUN_001940a8(&(*(undefined4 *)((char *)frame_ + 108)));
      pppppuVar15 = *ppppppuVar49;
      in_r7 = (uint ******)0x4050607;
      uVar10 = 0;
      if ((int)pppppuVar15 < 0) {
        pppppuVar52 = param_2[0x24];
        bVar1 = ((uint)pppppuVar52 & 3) != 0;
        in_r7 = *(uint *******)((*(undefined * *)((char *)frame_ + 308)) + -0x2bf8);
        if (bVar1) {
          in_r7 = (uint ******)((uint)in_r7 & 0xffffff | 0x4000000);
        }
        uVar10 = (uint)bVar1;
        if (((uint)pppppuVar52 & 0xc) != 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          in_r7 = (uint ******)(iVar34 * 0x10000 | (uint)in_r7 & 0xff00ffff);
        }
        if (((uint)pppppuVar52 & 0x30) != 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          in_r7 = (uint ******)(iVar34 * 0x100 | (uint)in_r7 & 0xffff00ff);
        }
        if (((uint)pppppuVar52 & 0xc0) != 0) {
          uVar44 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          in_r7 = (uint ******)(uVar44 | (uint)in_r7 & 0xffffff00);
        }
      }
      in_r6 = (uint ******)*param_2[0x19];
      if (((uint)*in_r6 & 0x400000) != 0) {
        in_r7 = *(uint *******)((*(undefined * *)((char *)frame_ + 308)) + -0x2bf8);
        iVar34 = FUN_0019e990(in_r6,0);
        puVar8 = PTR_DAT_001e8bc8;
        if (*(int *)(PTR_DAT_001e8bc8 + iVar34 * 4) == 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          in_r7 = (uint ******)(iVar34 * 0x1000000 | (uint)in_r7 & 0xffffff);
        }
        iVar34 = FUN_0019e990(in_r6,1);
        if (*(int *)(puVar8 + iVar34 * 4) == 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          in_r7 = (uint ******)(iVar34 * 0x10000 | (uint)in_r7 & 0xff00ffff);
        }
        iVar34 = FUN_0019e990(in_r6,2);
        if (*(int *)(puVar8 + iVar34 * 4) == 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          in_r7 = (uint ******)(iVar34 * 0x100 | (uint)in_r7 & 0xffff00ff);
        }
        iVar34 = FUN_0019e990(in_r6,3);
        if (*(int *)(puVar8 + iVar34 * 4) == 0) {
          in_r7 = (uint ******)(uVar10 + 4 | (uint)in_r7 & 0xffffff00);
        }
      }
      iVar43 = (int)*(short *)((int)in_r6 + 2);
      iVar34 = *(int *)(param_1 + 0x3d8);
      if (iVar43 <= *(int *)(param_1 + 0x3d8)) {
        iVar34 = iVar43;
      }
      iVar47 = *(int *)(param_1 + 0x3dc);
      *(int *)(param_1 + 0x3d8) = iVar34;
      if (iVar47 <= iVar43) {
        iVar47 = iVar43 + 1;
      }
      *(int *)(param_1 + 0x3dc) = iVar47;
      piVar18 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
      in_r8 = *(uint *******)(param_1 + 0x3a0);
      (**(code **)(*piVar18 + 0x4c))(piVar18,param_1,(uint)pppppuVar15 >> 0x10 & 0x3f);
      iVar43 = *(int *)((*(int *)((char *)frame_ + 116)) + 8);
      iVar34 = (*(int *)((char *)frame_ + 116));
      while (iVar47 = iVar43, iVar47 != 0) {
        FUN_0019401c(iVar34);
        ((int (*)())FUN_000f92fc)(param_1,iVar34,(*(uint ***** *)((char *)frame_ + 16)));
        iVar34 = iVar47;
        iVar43 = *(int *)(iVar47 + 8);
      }
      (*(undefined4 *)((char *)frame_ + 108)) = (uint *****)(PTR_DAT_001e8b48 + 8);
      (*(uint **** *)((char *)frame_ + 120)) = (uint ****)(*(undefined4 *)((char *)frame_ + 108));
      goto switchD_000fdaf0_caseD_2;
    case 0x1b:
      iVar34 = FUN_000ec27c(param_1,(uint)*ppppppuVar49 >> 0x10 & 0x1f);
      ppppppuVar19 = (uint ******)((uint)*ppppppuVar49 >> 0x15 & 0xff);
      (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)0x0;
      if ((int)*ppppppuVar49 < 0) {
        pppppuVar15 = param_2[0x24];
        (*(unsigned short *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 24))) + 2)) =
             (ushort)(((uint)(byte)((((uint)pppppuVar15 & 0xc0) == 0) << 1) << 0x14) >> 0x15);
        (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)
                    CONCAT13(((uint)pppppuVar15 & 3) == 0,
                             CONCAT12(((uint)pppppuVar15 & 0xc) == 0,(*(unsigned short *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 24))) + 2))));
        (*(unsigned short *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 24))) + 2)) = CONCAT11(((uint)pppppuVar15 & 0x30) == 0,(undefined1)(*(undefined4 *)((char *)frame_ + 24)));
      }
      iVar43 = (int)*(short *)((int)*param_2[0x19] + 2);
      uVar46 = FUN_000ec208(param_1,(uint)**param_2[0x19] >> 0x10 & 0x3f);
      if (iVar34 == 0) {
        *(int *)(*(int *)(param_1 + 0x3ac) + 0x44) = iVar43;
      }
      else if (iVar34 == 1) {
        *(int *)(*(int *)(param_1 + 0x3ac) + 0x48) = iVar43;
      }
      iVar47 = *(int *)(param_1 + 1000);
      if (iVar43 <= *(int *)(param_1 + 1000)) {
        iVar47 = iVar43;
      }
      iVar20 = *(int *)(param_1 + 0x3ec);
      *(int *)(param_1 + 1000) = iVar47;
      if (iVar20 <= iVar43) {
        iVar20 = iVar43 + 1;
      }
      *(int *)(param_1 + 0x3ec) = iVar20;
      *(undefined4 *)(param_1 + 0x3f4) = 0x24;
      in_r6 = (uint ******)0x0;
      piVar18 = (int *)FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),uVar46,iVar43,0);
      uVar46 = (**(code **)(*piVar18 + 0x2c))();
      (*(undefined4 * *)((char *)frame_ + 288)) = &(*(undefined4 *)((char *)frame_ + 24));
      iVar43 = 0;
      do {
        if (*(char *)(iVar43 + (int)(*(undefined4 * *)((char *)frame_ + 288))) == '\0') {
          in_r6 = ppppppuVar19;
          FUN_00104104(uVar46,iVar43,iVar34,ppppppuVar19);
        }
        bVar1 = iVar43 != 3;
        iVar43 = iVar43 + 1;
      } while (bVar1);
      goto switchD_000fdaf0_caseD_2;
    case 0x1c:
    case 0x1d:
    case 0x79:
      in_r6 = (uint ******)param_2[0x17];
      pppuVar42 = **param_2[0x19];
      sVar6 = *(short *)((int)*param_2[0x19] + 2);
      if ((int)in_r6 < 1) {
        in_r6 = (uint ******)0x0;
      }
      else {
        puVar12 = &(*(undefined4 *)((char *)frame_ + 108));
        ppppppuVar19 = param_2 + (int)param_2[0x16] + 0x23;
        ppppppuVar49 = in_r6;
        do {
          pppppuVar15 = *ppppppuVar19;
          ppppppuVar19 = ppppppuVar19 + 1;
          *puVar12 = (uint)pppppuVar15;
          puVar12 = puVar12 + 1;
          ppppppuVar49 = (uint ******)((int)ppppppuVar49 - 1);
        } while (ppppppuVar49 != (uint ******)0x0);
      }
      in_r7 = (uint ******)&(*(undefined4 *)((char *)frame_ + 108));
      ((int (*)())FUN_000fafa4)(param_1,(uint)pppuVar42 >> 0x10 & 0x3f,(int)sVar6,in_r6,in_r7);
      goto switchD_000fdaf0_caseD_2;
    case 0x42:
      uVar46 = *(undefined4 *)(iVar43 + 0x374);
      puVar14 = (undefined4 *)FUN_00193e18(uVar46,0x168);
      *puVar14 = uVar46;
      piVar18 = puVar14 + 1;
      FUN_0010502c(piVar18,0x94,*(undefined4 *)(param_1 + 8));
      uVar46 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x2f,0,0);
      FUN_001046c8(piVar18,0,uVar46);
      puVar14[0x4c] = 0;
      ((int (*)())FUN_000f92fc)(param_1,piVar18,(*(uint ***** *)((char *)frame_ + 16)));
      bVar1 = (*(int *)((char *)frame_ + 228)) != 0;
      if (bVar1) {
        (**(code **)(*piVar18 + 0x90))(piVar18,uVar46);
      }
      pppppuVar15 = *ppppppuVar49;
      in_r6 = (uint ******)((uint)pppppuVar15 >> 0x17 & 0x3f);
      if (((unsigned char *)0x4) < in_r6) {
        in_r6 = (uint ******)0x0;
      }
      ppppuVar45 = *param_2[0x1b];
      sVar6 = *(short *)((int)ppppuVar45 + 2);
      uVar50 = FUN_000ec208(param_1,(uint)*ppppuVar45 >> 0x10 & 0x3f);
      pppuVar42 = *param_2[0x1b][1];
      if (((((uint)pppuVar42 & 0x3f0000) == 0x100000) && (*(int *)(param_1 + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar34 = 0xf;
      }
      else {
        iVar34 = (int)*(short *)((int)param_2[0x1b][1] + 2);
      }
      uVar27 = FUN_000ec208(param_1,(uint)pppuVar42 >> 0x10 & 0x3f);
      uVar41 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x2b,0,0);
      piVar18 = FUN_001043f0(0x14,*(undefined4 *)(param_1 + 8));
      iVar43 = FUN_001054ec(piVar18,1);
      *(undefined4 *)(iVar43 + 0xc) = uVar50;
      *(int *)(iVar43 + 8) = (int)sVar6;
      (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)0x10203;
      ((int (*)())FUN_000f8aa0)(param_1,&(*(undefined4 *)((char *)frame_ + 24)),ppppuVar45,1,piVar18);
      iVar43 = FUN_001054ec(piVar18,1);
      *(undefined4 *)(iVar43 + 0x10) = 0;
      ((void (*)())FUN_000f79c4)(piVar18,param_1,2,0.0,1.0,0.0,0.0);
      (*(uint *)((char *)frame_ + 260)) = (uint)(short)((ushort)((uint)pppppuVar15 >> 0x10) & 0x3f);
      (*(uint *)((char *)frame_ + 272)) = (*(uint *)((char *)frame_ + 260)) | 0x120000;
      in_r8 = (uint ******)((*(uint *)((char *)frame_ + 260)) | 0x100000);
      in_r7 = (uint ******)((*(uint *)((char *)frame_ + 260)) | 0x110000);
      (*(uint *)((char *)frame_ + 260)) = (*(uint *)((char *)frame_ + 260)) | 0xf0000;
      (*(uint ***** *)((char *)frame_ + 264)) = (uint *****)in_r8;
      (*(uint ***** *)((char *)frame_ + 268)) = (uint *****)in_r7;
      ((int (*)())FUN_000f771c)(piVar18,param_1,3,(*(uint *)((char *)frame_ + 272)),in_r7,in_r8,(*(uint *)((char *)frame_ + 260)));
      iVar43 = FUN_001054ec(piVar18,0);
      *(undefined4 *)(iVar43 + 0xc) = 0x2b;
      *(undefined4 *)(iVar43 + 8) = 0;
      ((int (*)())FUN_000f92fc)(param_1,piVar18,(*(uint ***** *)((char *)frame_ + 16)));
      (**(code **)(*piVar18 + 0x90))(piVar18,uVar46);
      if (bVar1) {
        (**(code **)(*piVar18 + 0x90))(piVar18,uVar41);
      }
      FUN_0010469c(piVar18,param_1,0x2b,0);
      piVar18[0x20] = 1;
      piVar18 = (int *)FUN_001084b8(0x31,*(undefined4 *)(param_1 + 8));
      iVar43 = FUN_001054ec(piVar18,0);
      *(uint *******)(iVar43 + 8) = in_r6;
      *(undefined4 *)(iVar43 + 0xc) = 0x2c;
      iVar43 = FUN_001054ec(piVar18,1);
      *(undefined4 *)(iVar43 + 0xc) = uVar27;
      *(int *)(iVar43 + 8) = iVar34;
      (**(code **)(*piVar18 + 0x90))(piVar18,uVar41);
      ((int (*)())FUN_000f92fc)(param_1,piVar18,(*(uint ***** *)((char *)frame_ + 16)));
      FUN_0010469c(piVar18,param_1,0x2c,in_r6);
      (*(int *)((char *)frame_ + 228)) = 1;
      goto switchD_000fdaf0_caseD_2;
    case 0x43:
      pppppuVar15 = *ppppppuVar49;
      in_r6 = (uint ******)*param_2[0x19];
      in_r7 = (uint ******)0x4050607;
      if (((uint)*in_r6 & 0x400000) != 0) {
        in_r7 = *(uint *******)((*(undefined * *)((char *)frame_ + 308)) + -0x2bf8);
        iVar34 = FUN_0019e990(in_r6,0);
        if (*(int *)(PTR_DAT_001e8bc8 + iVar34 * 4) == 0) {
          in_r7 = (uint ******)((uint)in_r7 & 0xffffff | 0x4000000);
        }
        uVar10 = (uint)(*(int *)(PTR_DAT_001e8bc8 + iVar34 * 4) == 0);
        iVar34 = FUN_0019e990(in_r6,1);
        puVar8 = PTR_DAT_001e8bc8;
        if (*(int *)(PTR_DAT_001e8bc8 + iVar34 * 4) == 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          in_r7 = (uint ******)(iVar34 * 0x10000 | (uint)in_r7 & 0xff00ffff);
        }
        iVar34 = FUN_0019e990(in_r6,2);
        if (*(int *)(puVar8 + iVar34 * 4) == 0) {
          iVar34 = uVar10 + 4;
          uVar10 = uVar10 + 1;
          in_r7 = (uint ******)(iVar34 * 0x100 | (uint)in_r7 & 0xffff00ff);
        }
        iVar34 = FUN_0019e990(in_r6,3);
        if (*(int *)(puVar8 + iVar34 * 4) == 0) {
          iVar43 = *(int *)(param_1 + 8);
          in_r7 = (uint ******)(uVar10 + 4 | (uint)in_r7 & 0xffffff00);
        }
        else {
          iVar43 = *(int *)(param_1 + 8);
        }
      }
      in_r8 = (uint ******)(*(uint ***** *)((char *)frame_ + 16));
      (**(code **)(**(int **)(iVar43 + 0x30c) + 0x4c))
                (*(int **)(iVar43 + 0x30c),param_1,(uint)pppppuVar15 >> 0x10 & 0x3f);
      goto switchD_000fdaf0_caseD_2;
    case 0x6e:
      uVar46 = *(undefined4 *)(iVar43 + 0x374);
      pppppuVar15 = param_2[(int)param_2[0x16] + 0x23];
      puVar14 = (undefined4 *)FUN_00193e18(uVar46,0x134);
      *puVar14 = uVar46;
      pppppuVar52 = (uint *****)(puVar14 + 1);
      FUN_000ea148(pppppuVar52,*(undefined4 *)(param_1 + 8));
      puVar14[0x4c] = pppppuVar15;
      puVar14[1] = PTR_DAT_001e8bd0 + 8;
      (*(uint ***** *)((char *)frame_ + 16)) = pppppuVar52;
      FUN_000ec3ac(param_1,(*(uint ***** *)((char *)frame_ + 12)),pppppuVar52);
      FUN_000e8e4c((*(uint ***** *)((char *)frame_ + 12)),(*(uint ***** *)((char *)frame_ + 16)));
      (*(uint ***** *)((char *)frame_ + 12)) = (*(uint ***** *)((char *)frame_ + 16));
      uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar14 = (undefined4 *)FUN_00193e18(uVar46,0x130);
      *puVar14 = uVar46;
      ppppppuVar49 = (uint ******)(puVar14 + 1);
      FUN_000ea020(ppppppuVar49,*(undefined4 *)(param_1 + 8));
      (*(uint ***** *)((char *)frame_ + 16)) = (uint *****)ppppppuVar49;
      FUN_000ec3ac(param_1,(*(uint ***** *)((char *)frame_ + 12)),ppppppuVar49);
      FUN_000e8e4c((*(uint ***** *)((char *)frame_ + 12)),(*(uint ***** *)((char *)frame_ + 16)));
      (*(uint ***** *)((char *)frame_ + 12)) = (*(uint ***** *)((char *)frame_ + 16));
      goto switchD_000fdaf0_caseD_2;
    case 0x72:
      piVar18 = (int *)FUN_00193e18(*(undefined4 *)(iVar43 + 0x378),0xc);
      piVar18[1] = 0;
      piVar18[2] = 0;
      ppppppuVar19 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      iVar43 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar43;
      *piVar18 = iVar43;
      iVar34 = FUN_001054ec(ppppppuVar19,0);
      *(undefined4 *)(iVar34 + 0xc) = 0;
      *(int *)(iVar34 + 8) = iVar43;
      (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)0x10203;
      in_r8 = (uint ******)&(*(uint **** *)((char *)frame_ + 28));
      ((int (*)())FUN_000fb3d4)(param_1,(*(undefined1 * *)((char *)frame_ + 296)),ppppppuVar49,*param_2[0x1b],ppppppuVar37,in_r8,&(*(uint * *)((char *)frame_ + 84)));
      pppuVar42 = **param_2[0x1b];
      if (((((uint)pppuVar42 & 0x3f0000) == 0x100000) && (*(int *)(param_1 + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar34 = 0xf;
      }
      else {
        iVar34 = (int)*(short *)((int)*param_2[0x1b] + 2);
      }
      uVar46 = FUN_000ec208(param_1,(uint)pppuVar42 >> 0x10 & 0x3f);
      iVar43 = FUN_001054ec(ppppppuVar19,1);
      *(undefined4 *)(iVar43 + 0xc) = uVar46;
      *(int *)(iVar43 + 8) = iVar34;
      in_r6 = (uint ******)((int)((unsigned char *)0x0) + 1);
      in_r7 = ppppppuVar19;
      ((int (*)())FUN_000f8aa0)(param_1,&(*(undefined4 *)((char *)frame_ + 24)),*param_2[0x1b],1,ppppppuVar19);
      iVar43 = *(int *)(local_14c + 8);
      iVar34 = local_14c;
      while (iVar47 = iVar43, iVar47 != 0) {
        FUN_0019401c(iVar34);
        ((int (*)())FUN_000f92fc)(param_1,iVar34,(*(uint ***** *)((char *)frame_ + 16)));
        iVar34 = iVar47;
        iVar43 = *(int *)(iVar47 + 8);
      }
      ((int (*)())FUN_000f92fc)(param_1,ppppppuVar19,(*(uint ***** *)((char *)frame_ + 16)));
      uVar10 = (*(uint * *)((char *)frame_ + 224))[1];
      if (uVar10 < *(*(uint * *)((char *)frame_ + 224))) {
        _memset(uVar10 * 4 + (*(uint * *)((char *)frame_ + 224))[2],0,4);
        (*(uint * *)((char *)frame_ + 224))[1] = uVar10 + 1;
        piVar36 = (int *)(uVar10 * 4 + (*(uint * *)((char *)frame_ + 224))[2]);
      }
      else {
        piVar36 = (int *)FUN_0019423c((*(uint * *)((char *)frame_ + 224)),uVar10);
      }
      goto code_r0x000febe0;
    case 0x73:
      uVar46 = *(undefined4 *)(iVar43 + 0x374);
      puVar14 = (undefined4 *)FUN_00193e18(uVar46,0x168);
      *puVar14 = uVar46;
      piVar18 = puVar14 + 1;
      FUN_0010502c(piVar18,0xf8,*(undefined4 *)(param_1 + 8));
      puVar14[0x4c] = param_2[(int)param_2[0x16] + 0x23];
      ((int (*)())FUN_000f92fc)(param_1,piVar18,(*(uint ***** *)((char *)frame_ + 16)));
      break;
    case 0x76:
    case 0x77:
      if ((iVar34 == 0x76) && ((int)*ppppppuVar49 < 0)) {
        pppppuVar52 = param_2[10];
        in_r6 = (uint ******)0x0;
        pppppuVar15 = param_2[(int)param_2[0x16] + 0x23];
        uVar46 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x43,0xffffffff,0);
        iVar34 = FUN_00109b74(0x10a,*(undefined4 *)(param_1 + 8));
        *(int *)(param_1 + 0x354) = iVar34;
        FUN_001046c8(iVar34,0,uVar46);
        *(uint ******)(iVar34 + 300) = pppppuVar52 + (int)pppppuVar15;
        FUN_000e7688(*(undefined4 *)(param_1 + 0x3a0),iVar34);
      }
      else {
        iVar34 = 1;
        ppppuVar45 = *param_2[0x1b];
        uVar44 = (uint)*(ushort *)((int)ppppuVar45 + 2);
        uVar10 = (uint)*ppppuVar45 >> 0x10 & 0x3f;
        if ((int)*ppppuVar45 < 0) {
          iVar34 = 2;
          uVar44 = uVar44 | (int)ppppuVar45[1] << 0x10;
        }
        pppuVar42 = ppppuVar45[iVar34];
        if (uVar10 == 0x1c) {
          puVar12 = *(uint **)(param_1 + 0x90);
          if (puVar12 == (uint *)0x0) {
            uVar46 = *(undefined4 *)(iVar43 + 0x374);
            puVar14 = (undefined4 *)FUN_00193e18(uVar46,0x14);
            puVar12 = puVar14 + 1;
            *puVar14 = uVar46;
            puVar14[1] = 2;
            puVar14[2] = 0;
            puVar14[4] = uVar46;
            uVar46 = FUN_00193e18(uVar46,8);
            puVar14[3] = uVar46;
            *(uint **)(param_1 + 0x90) = puVar12;
          }
        }
        else {
          puVar12 = *(uint **)(param_1 + 0x8c);
          if (puVar12 == (uint *)0x0) {
            uVar46 = *(undefined4 *)(iVar43 + 0x374);
            puVar14 = (undefined4 *)FUN_00193e18(uVar46,0x14);
            puVar12 = puVar14 + 1;
            *puVar14 = uVar46;
            puVar14[1] = 2;
            puVar14[2] = 0;
            puVar14[4] = uVar46;
            uVar46 = FUN_00193e18(uVar46,8);
            puVar14[3] = uVar46;
            *(uint **)(param_1 + 0x8c) = puVar12;
          }
        }
        if (uVar44 < *puVar12) {
          uVar17 = puVar12[1];
          if (uVar17 <= uVar44) {
            _memset(uVar17 * 4 + puVar12[2],0,(uVar44 - uVar17) * 4 + 4);
            puVar12[1] = uVar44 + 1;
          }
          puVar12 = (uint *)(uVar44 * 4 + puVar12[2]);
        }
        else {
          puVar12 = (uint *)FUN_0019423c(puVar12,uVar44);
        }
        *puVar12 = (uint)pppuVar42;
        iVar34 = (uVar44 >> 3 & 0x1ffffffc) + *(int *)(param_1 + 0x434);
        *(uint *)(iVar34 + 8) = 1 << (uVar44 & 0x1f) | *(uint *)(iVar34 + 8);
        if ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 8) != 0) {
          uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
          puVar14 = (undefined4 *)FUN_00193e18(uVar46,0x168);
          *puVar14 = uVar46;
          puVar24 = puVar14 + 1;
          FUN_00109a80(puVar24,0xfa,*(undefined4 *)(param_1 + 8));
          uVar46 = FUN_000ec208(param_1,uVar10);
          iVar34 = FUN_001054ec(puVar24,0);
          *(undefined4 *)(iVar34 + 0xc) = uVar46;
          *(uint *)(iVar34 + 8) = uVar44;
          puVar14[0x4c] = pppuVar42;
          ((int (*)())FUN_000f92fc)(param_1,puVar24,*(undefined4 *)(param_1 + 0x3a0));
        }
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x78:
      *(uint *)(param_1 + 0x400) = (uint)*ppppppuVar49 >> 0x10 & 0x3fff;
      goto switchD_000fdaf0_caseD_2;
    case 0x7a:
      *(uint *)(param_1 + 0x3f8) = (uint)*ppppppuVar49 >> 0x10 & 0x3fff;
      goto switchD_000fdaf0_caseD_2;
    case 0x7c:
      *(uint *)(param_1 + 0x3fc) = (uint)*ppppppuVar49 >> 0x10 & 0x3fff;
      goto switchD_000fdaf0_caseD_2;
    case 0x7d:
      ppppuVar45 = *param_2[0x19];
      if ((*(uint *)(param_1 + 0x30) & 0x4000) == 0) {
        if ((*(uint *)(param_1 + 0x30) & 1) != 0) {
          (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)0x0;
          ppppppuVar19 = (uint ******)(int)*(short *)((int)ppppuVar45 + 2);
          uVar46 = FUN_000ec208(param_1,(uint)*ppppuVar45 >> 0x10 & 0x3f);
          iVar34 = FUN_000ec27c(param_1,(uint)*ppppppuVar49 >> 0x10 & 0x3fff);
          if (iVar34 == 0) {
            *(uint *******)(*(int *)(param_1 + 0x3ac) + 0x44) = ppppppuVar19;
          }
          else if (iVar34 == 1) {
            *(uint *******)(*(int *)(param_1 + 0x3ac) + 0x48) = ppppppuVar19;
          }
          ppppppuVar49 = *(uint *******)(param_1 + 1000);
          if ((int)ppppppuVar19 <= (int)*(uint *******)(param_1 + 1000)) {
            ppppppuVar49 = ppppppuVar19;
          }
          puVar53 = *(undefined1 **)(param_1 + 0x3ec);
          *(uint *******)(param_1 + 1000) = ppppppuVar49;
          if ((int)puVar53 <= (int)ppppppuVar19) {
            puVar53 = (undefined1 *)((int)ppppppuVar19 + 1);
          }
          *(undefined1 **)(param_1 + 0x3ec) = puVar53;
          *(undefined4 *)(param_1 + 0x3f4) = 0x24;
          if (iVar34 == 0xd) {
            iVar43 = *(int *)(param_1 + 0x3ac);
            if (*(int *)(iVar43 + 0x4c) == -1) {
              *(uint *******)(iVar43 + 0x4c) = ppppppuVar19;
            }
            else {
              *(uint *******)(iVar43 + 0x54) = ppppppuVar19;
            }
          }
          else if (iVar34 == 0xe) {
            iVar43 = *(int *)(param_1 + 0x3ac);
            if (*(int *)(iVar43 + 0x50) == -1) {
              *(uint *******)(iVar43 + 0x50) = ppppppuVar19;
            }
            else {
              *(uint *******)(iVar43 + 0x58) = ppppppuVar19;
            }
          }
          else if (iVar34 == 0xb) {
            *(uint *******)(*(int *)(param_1 + 0x3ac) + 0x5c) = ppppppuVar19;
          }
          else if (iVar34 == 0xc) {
            *(uint *******)(*(int *)(param_1 + 0x3ac) + 0x60) = ppppppuVar19;
          }
          else if (iVar34 == 0xf) {
            *(uint *******)(*(int *)(param_1 + 0x3ac) + 100) = ppppppuVar19;
          }
          in_r6 = (uint ******)0x0;
          piVar18 = (int *)FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),uVar46,ppppppuVar19,0);
          iVar43 = (**(code **)(*piVar18 + 0x2c))();
          (*(undefined4 * *)((char *)frame_ + 288)) = &(*(undefined4 *)((char *)frame_ + 24));
          *(uint *******)(iVar43 + 0x140) = ppppppuVar19;
          iVar47 = 0;
          do {
            if (*(char *)(iVar47 + (int)(*(undefined4 * *)((char *)frame_ + 288))) == '\0') {
              in_r6 = ppppppuVar19;
              FUN_00104104(iVar43,iVar47,iVar34,ppppppuVar19);
            }
            bVar1 = iVar47 != 3;
            iVar47 = iVar47 + 1;
          } while (bVar1);
        }
      }
      else {
        in_r7 = (uint ******)0x10203;
        in_r6 = (uint ******)(uint)*(ushort *)((int)ppppuVar45 + 2);
        in_r8 = (uint ******)0x0;
        (**(code **)(*piVar18 + 0x54))(piVar18,in_r6,(uint)*ppppppuVar49 >> 0x10 & 0x3fff);
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x7e:
      uVar44 = (uint)*ppppppuVar49 >> 0xe & 0x1f;
      ppppppuVar19 = (uint ******)FUN_000ec27c(param_1,uVar44);
      uVar10 = (uint)*ppppppuVar49 >> 0x13 & 7;
      if (uVar10 == 3) {
        bVar1 = true;
        bVar3 = false;
        bVar2 = false;
      }
      else if (uVar10 < 4) {
        if (uVar10 == 1) {
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
      else if (uVar10 == 4) {
        bVar1 = false;
        bVar3 = true;
        bVar2 = false;
      }
      else {
        if (uVar10 != 5) goto code_r0x000feeb8;
        bVar1 = true;
        bVar3 = true;
        bVar2 = false;
      }
      ppppppuVar49 = (uint ******)*param_2[0x19];
      pppppuVar15 = *ppppppuVar49;
      if (((uint)pppppuVar15 & 0x400000) == 0) {
        if (((uint)pppppuVar15 & 0x2000000) == 0) {
          ppppppuVar40 = (uint ******)0x0;
          ppppppuVar38 = (uint ******)0x0;
        }
        else {
          ppppppuVar40 = ppppppuVar49 + 1;
          ppppppuVar38 = (uint ******)0x0;
        }
      }
      else {
        ppppppuVar38 = ppppppuVar49 + 1;
        ppppppuVar40 = (uint ******)0x0;
        if (((uint)pppppuVar15 & 0x2000000) != 0) {
          ppppppuVar40 = ppppppuVar49 + 2;
        }
      }
      if (((*(uint *)(param_1 + 0x30) & 1) == 0) && ((*(uint *)(param_1 + 0x30) & 0x2000) == 0)) {
        if (uVar44 == 10) {
          (*(uint **** *)((char *)frame_ + 28)) = (uint ****)(uint)*(ushort *)((int)ppppppuVar40 + 2);
          (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)0x10101;
          puVar12 = &(*(undefined4 *)((char *)frame_ + 24));
          if (((uint)*ppppppuVar38 & 3) == 1) {
            puVar12 = &DAT_001aa9d0;
          }
          puVar35 = &(*(undefined4 *)((char *)frame_ + 24));
          (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)*puVar12;
          if (((uint)*ppppppuVar38 & 0xc) == 4) {
            puVar35 = &UNK_001aa9c4;
          }
          puVar12 = &(*(undefined4 *)((char *)frame_ + 24));
          (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)*puVar35;
          if (((uint)*ppppppuVar38 & 0x30) == 0x10) {
            puVar12 = &UNK_001aa9c0;
          }
          puVar35 = &(*(undefined4 *)((char *)frame_ + 24));
          (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)*puVar12;
          if (((uint)*ppppppuVar38 & 0xc0) == 0x40) {
            puVar35 = &UNK_001aa9bc;
          }
          (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)*puVar35;
          (*(uint ***** *)((char *)frame_ + 32)) = (uint *****)(*(undefined4 *)((char *)frame_ + 24));
        }
      }
      else {
        uVar10 = (uint)pppppuVar15 >> 0x10 & 0x3f;
        ppppppuVar48 = (uint ******)(uint)*(ushort *)((int)ppppppuVar49 + 2);
        uVar46 = FUN_000ec208(param_1,uVar10);
        puVar12 = (*(uint * *)((char *)frame_ + 84));
        ppppppuVar38 = *(uint *******)(param_1 + 1000);
        if ((int)ppppppuVar48 <= (int)*(uint *******)(param_1 + 1000)) {
          ppppppuVar38 = ppppppuVar48;
        }
        puVar53 = *(undefined1 **)(param_1 + 0x3ec);
        *(uint *******)(param_1 + 1000) = ppppppuVar38;
        if ((int)puVar53 <= (int)ppppppuVar48) {
          puVar53 = (undefined1 *)((int)ppppppuVar48 + 1);
        }
        *(undefined1 **)(param_1 + 0x3ec) = puVar53;
        *(undefined4 *)(param_1 + 0x3f4) = 0x24;
        in_r7 = (uint ******)0x4050607;
        if ((*(uint *)(param_1 + 0x30) & 1) == 0) {
          iVar34 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),uVar46,ppppppuVar48,0);
          iVar34 = *(int *)(iVar34 + 0x38);
          if (!bVar1) {
            *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 1;
          }
          if (bVar3) {
            *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 4;
          }
          if (bVar2) {
            *(uint *)(iVar34 + 0x13c) = *(uint *)(iVar34 + 0x13c) | 2;
          }
          iVar43 = 0;
          do {
            in_r6 = ppppppuVar19;
            in_r7 = ppppppuVar48;
            FUN_001041d0(iVar34,iVar43,1,ppppppuVar19,ppppppuVar48);
            bVar1 = iVar43 != 3;
            iVar43 = iVar43 + 1;
          } while (bVar1);
        }
        else if ((*(uint *)(param_1 + 0x30) & 0x40000) == 0) {
          in_r8 = *(uint *******)(param_1 + 0x3a0);
          piVar18 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
          (**(code **)(*piVar18 + 0x4c))(piVar18,param_1,ppppppuVar48);
          in_r6 = ppppppuVar49;
        }
        else if (uVar10 != 9) {
          uVar10 = (uint)*(ushort *)((int)ppppppuVar40 + 2);
          if (uVar10 < *(*(uint * *)((char *)frame_ + 84))) {
            uVar44 = (*(uint * *)((char *)frame_ + 84))[1];
            if (uVar44 <= uVar10) {
              _memset(uVar44 * 4 + (*(uint * *)((char *)frame_ + 84))[2],0,(uVar10 - uVar44) * 4 + 4);
              puVar12[1] = uVar10 + 1;
            }
            puVar14 = (undefined4 *)(uVar10 * 4 + puVar12[2]);
          }
          else {
            puVar14 = (undefined4 *)FUN_0019423c((*(uint * *)((char *)frame_ + 84)),uVar10);
          }
          ppppppuVar49 = (uint ******)*puVar14;
          in_r6 = (uint ******)0x0;
          iVar34 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar34;
          uVar46 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0,iVar34,0);
          FUN_001046c8(ppppppuVar49,0,uVar46);
          goto code_r0x000ff070;
        }
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x80:
      bVar4 = *(byte *)((int)param_2 + 0x8d);
      uVar10 = (uint)*ppppppuVar49 >> 0x18 & 0xf;
      if (piVar18[0x14] < (int)(uint)bVar4) {
        FUN_000e1534(iVar43,7);
      }
      uVar44 = bVar4 >> 3 & 0x1c;
      iVar34 = (uint)bVar4 * 0xc;
      *(uint *)((int)(*(undefined4 * *)((char *)frame_ + 240)) + uVar44 + 8) =
           1 << (bVar4 & 0x1f) | *(uint *)((int)(*(undefined4 * *)((char *)frame_ + 240)) + uVar44 + 8);
      *(undefined4 *)(*(int *)(param_1 + 0x78) + iVar34) = 1;
      if (uVar10 != 0) {
        *(uint *)(iVar34 + *(int *)(param_1 + 0x78) + 4) = uVar10;
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x81:
    case 0x84:
    case 0x85:
      (*(uint ***** *)((char *)frame_ + 236)) = (uint *****)((int)(*(uint ***** *)((char *)frame_ + 236)) + 1);
      if ((*(uint *)(param_1 + 0x30) & 0x40000) == 0) {
        if (puVar13[2] != 0) {
          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x180000;
        }
        if ((uint *****)(*(uint ***** *)((char *)frame_ + 232))[1] != (uint *****)0x0) {
          *(uint *)(param_1 + 0x30) = *(uint *)(param_1 + 0x30) | 0x80000;
        }
        pvVar16 = FUN_001043f0(*(undefined4 *)
                                (iVar34 * 0x24 + *(int *)(*(int *)(iVar43 + 0x30c) + 0xc)),iVar43);
        iVar34 = FUN_001054ec(pvVar16,0);
        *(undefined4 *)(iVar34 + 0xc) = 0x2c;
        *(undefined4 *)(iVar34 + 8) = 0;
        *(undefined4 *)((int)pvVar16 + 0x9c) = 0x10101;
        iVar34 = FUN_001054ec(pvVar16,1);
        *(undefined4 *)(iVar34 + 0xc) = 0x2c;
        *(undefined4 *)(iVar34 + 8) = 0;
        iVar34 = FUN_001054ec(pvVar16,1);
        *(undefined4 *)(iVar34 + 0x10) = 0;
        ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
      }
      goto switchD_000fdaf0_caseD_2;
    case 0x87:
      uVar10 = (uint)*(byte *)((int)param_2 + 0x8d);
      pppppuVar15 = *ppppppuVar49;
      if (*(int *)(param_1 + 0x7c) < (int)uVar10) {
        *(uint *)(param_1 + 0x7c) = uVar10;
      }
      *(uint *)(param_1 + 0x84) = 1 << (uVar10 & 0x3f) | *(uint *)(param_1 + 0x84);
      (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)0x10203;
      uVar46 = *(undefined4 *)(param_1 + 0x3ac);
      iVar34 = *(int *)(iVar43 + 0x3ac) + -1;
      *(int *)(iVar43 + 0x3ac) = iVar34;
      uVar46 = FUN_00127608(uVar46,0,iVar34,0);
      uVar50 = *(undefined4 *)(param_1 + 0x3ac);
      iVar34 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar34;
      uVar50 = FUN_00127608(uVar50,0,iVar34,0);
      pvVar16 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      FUN_001046c8(pvVar16,0,uVar50);
      (*(undefined4 * *)((char *)frame_ + 288)) = &(*(undefined4 *)((char *)frame_ + 24));
      ((int (*)())FUN_000fa958)(param_1,5,1,param_2,pvVar16,1,0,(*(undefined4 * *)((char *)frame_ + 288)),ppppppuVar37,1,(*(uint ***** *)((char *)frame_ + 16)));
      ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
      pvVar16 = FUN_001043f0(0x109,*(undefined4 *)(param_1 + 8));
      *(uint *)((int)pvVar16 + 0x134) = uVar10;
      FUN_001046c8(pvVar16,0,uVar46);
      FUN_001046c8(pvVar16,1,uVar50);
      ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
      puVar9 = PTR_DAT_001e8b8c;
      puVar8 = PTR_DAT_001e8b64;
      (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)0x10203;
      if (((uint)pppppuVar15 & 0x1f000000) != 0x1000000) {
        iVar34 = 0;
        do {
          pvVar16 = FUN_001043f0(0xe1,*(undefined4 *)(param_1 + 8));
          FUN_001046c8(pvVar16,0,uVar46);
          FUN_001046c8(pvVar16,1,uVar46);
          uVar50 = *(undefined4 *)(puVar9 + iVar34);
          *(undefined4 *)((int)pvVar16 + 0x9c) = *(undefined4 *)(puVar8 + iVar34);
          iVar43 = FUN_001054ec(pvVar16,1);
          *(undefined4 *)(iVar43 + 0x10) = uVar50;
          ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
          bVar1 = iVar34 != 0xc;
          iVar34 = iVar34 + 4;
        } while (bVar1);
      }
      ppppppuVar49 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      in_r8 = (uint ******)((int)((unsigned char *)0x0) + 1);
      in_r6 = param_2;
      in_r7 = ppppppuVar49;
      ((int (*)())FUN_000fa958)(param_1,0,0,param_2,ppppppuVar49,1,0,(*(undefined4 * *)((char *)frame_ + 288)),ppppppuVar37,1,(*(uint ***** *)((char *)frame_ + 16)));
      FUN_001046c8(ppppppuVar49,1,uVar46);
code_r0x000ff070:
      ((int (*)())FUN_000f92fc)(param_1,ppppppuVar49,(*(uint ***** *)((char *)frame_ + 16)));
      goto switchD_000fdaf0_caseD_2;
    case 0xbe:
      uVar46 = *(undefined4 *)(iVar43 + 0x374);
      puVar14 = (undefined4 *)FUN_00193e18(uVar46,0x168);
      *puVar14 = uVar46;
      ppppppuVar19 = (uint ******)(puVar14 + 1);
      FUN_0010502c(ppppppuVar19,0xb4,*(undefined4 *)(param_1 + 8));
      if (((uint)*ppppppuVar49 & 0x3fff0000) != 0) {
        puVar14[0x4c] = 1;
      }
      in_r8 = (uint ******)&(*(uint **** *)((char *)frame_ + 28));
      ((int (*)())FUN_000fb3d4)(param_1,(*(undefined1 * *)((char *)frame_ + 296)),ppppppuVar49,*param_2[0x1b],ppppppuVar37,in_r8,&(*(uint * *)((char *)frame_ + 84)));
      pppuVar42 = **param_2[0x1b];
      if (((((uint)pppuVar42 & 0x3f0000) == 0x100000) && (*(int *)(param_1 + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar34 = 0xf;
      }
      else {
        iVar34 = (int)*(short *)((int)*param_2[0x1b] + 2);
      }
      uVar10 = (uint)pppuVar42 >> 0x10 & 0x3f;
      iVar43 = FUN_00127534(*(undefined4 *)(param_1 + 0x3ac),0x2c,0,0);
      if (iVar43 == 0) {
        uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar14 = (undefined4 *)FUN_00193e18(uVar46,0x168);
        *puVar14 = uVar46;
        puVar24 = puVar14 + 1;
        FUN_00108918(puVar24,*(undefined4 *)(param_1 + 8));
        puVar14[6] = puVar14[6] | 0x10000;
        *(undefined4 **)(param_1 + 0x350) = puVar24;
        puVar14[0x28] = 0;
        iVar43 = FUN_001275a0(*(undefined4 *)(param_1 + 0x3ac),0x2c,0,0);
        FUN_001046c8(puVar24,0,iVar43);
        FUN_001046c8(puVar24,1,iVar43);
        iVar47 = FUN_001054ec(puVar24,1);
        *(undefined4 *)(iVar47 + 0x10) = 0x10203;
        FUN_000e7688(*(undefined4 *)(param_1 + 0x3a8),puVar24);
        FUN_0012306c(iVar43,puVar24);
        FUN_001236e4(iVar43,1,puVar24);
      }
      FUN_001046c8(ppppppuVar19,0,iVar43);
      uVar46 = FUN_000ec208(param_1,uVar10);
      iVar43 = FUN_001054ec(ppppppuVar19,1);
      *(undefined4 *)(iVar43 + 0xc) = uVar46;
      *(int *)(iVar43 + 8) = iVar34;
      uVar46 = FUN_000ec208(param_1,uVar10);
      iVar43 = FUN_001054ec(ppppppuVar19,2);
      *(undefined4 *)(iVar43 + 0xc) = uVar46;
      *(int *)(iVar43 + 8) = iVar34;
      uVar46 = FUN_000ec208(param_1,uVar10);
      iVar43 = FUN_001054ec(ppppppuVar19,3);
      *(undefined4 *)(iVar43 + 0xc) = uVar46;
      (*(undefined4 * *)((char *)frame_ + 288)) = &(*(undefined4 *)((char *)frame_ + 24));
      *(int *)(iVar43 + 8) = iVar34;
      (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)0x10101;
      ((int (*)())FUN_000f8aa0)(param_1,(*(undefined4 * *)((char *)frame_ + 288)),*param_2[0x1b],1,ppppppuVar19);
      (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)0x2020202;
      ((int (*)())FUN_000f8aa0)(param_1,(*(undefined4 * *)((char *)frame_ + 288)),*param_2[0x1b],2,ppppppuVar19);
      in_r6 = (uint ******)((int)((unsigned char *)0x0) + 3);
      (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)0x3030303;
      in_r7 = ppppppuVar19;
      ((int (*)())FUN_000f8aa0)(param_1,(*(undefined4 * *)((char *)frame_ + 288)),*param_2[0x1b],3,ppppppuVar19);
      iVar43 = *(int *)(local_14c + 8);
      iVar34 = local_14c;
      while (iVar47 = iVar43, iVar47 != 0) {
        FUN_0019401c(iVar34);
        ((int (*)())FUN_000f92fc)(param_1,iVar34,(*(uint ***** *)((char *)frame_ + 16)));
        iVar34 = iVar47;
        iVar43 = *(int *)(iVar47 + 8);
      }
      ((int (*)())FUN_000f92fc)(param_1,ppppppuVar19,(*(uint ***** *)((char *)frame_ + 16)));
      goto switchD_000fdaf0_caseD_2;
    case 0xe3:
      uVar46 = *(undefined4 *)(iVar43 + 0x374);
      puVar14 = (undefined4 *)FUN_00193e18(uVar46,0x168);
      *puVar14 = uVar46;
      piVar18 = puVar14 + 1;
      FUN_0010502c(piVar18,0x106,*(undefined4 *)(param_1 + 8));
      ((int (*)())FUN_000f92fc)(param_1,piVar18,(*(uint ***** *)((char *)frame_ + 16)));
    }
    puVar12 = *(uint **)(param_1 + 0x414);
    uVar10 = puVar12[1];
    if (uVar10 < *puVar12) {
      _memset(uVar10 * 4 + puVar12[2],0,4);
      piVar36 = (int *)(uVar10 * 4 + puVar12[2]);
      puVar12[1] = uVar10 + 1;
    }
    else {
      piVar36 = (int *)FUN_0019423c(puVar12,uVar10);
    }
code_r0x000febe0:
    *piVar36 = (int)piVar18;
    goto switchD_000fdaf0_caseD_2;
  default:
    goto switchD_000fdaf0_caseD_2;
  case 4:
    bVar1 = false;
    break;
  case 5:
    (*(undefined * *)((char *)frame_ + 280)) = &DAT_001ad5d8;
    (*(undefined * *)((char *)frame_ + 304)) = &DAT_001ad5d8;
    iVar47 = *(int *)(iVar34 * 0x24 + iVar47 + 0x18);
    (*(undefined4 *)((char *)frame_ + 108)) = (uint *****)0x0;
    (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)0x10203;
    uVar46 = *(undefined4 *)(iVar43 + 0x378);
    puVar14 = (undefined4 *)FUN_00193e18(uVar46,0x14);
    puVar12 = puVar14 + 1;
    *puVar14 = uVar46;
    puVar14[1] = 2;
    puVar14[2] = 0;
    puVar14[4] = uVar46;
    uVar46 = FUN_00193e18(uVar46,8);
    puVar14[3] = uVar46;
    uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
    puVar24 = (undefined4 *)FUN_00193e18(uVar46,0x14);
    ppppppuVar19 = (uint ******)(puVar24 + 1);
    *puVar24 = uVar46;
    puVar24[1] = 2;
    puVar24[2] = 0;
    puVar24[4] = uVar46;
    uVar46 = FUN_00193e18(uVar46,8);
    puVar24[3] = uVar46;
    (*(int * *)((char *)frame_ + 20)) = (int *)0x0;
    _memcpy(&(*(undefined4 *)((char *)frame_ + 140)),&UNK_001aaa2c,0x24);
    iVar20 = *(int *)(param_1 + 8);
    ppppppuVar38 = (uint ******)0x0;
    uVar46 = *(undefined4 *)(*(int *)(iVar20 + 0x30c) + 0xc);
    (*(uint ***** *)((char *)frame_ + 208)) = (uint *****)((int (*)())FUN_000f8960)(iVar34,uVar46);
    iVar43 = ((int (*)())FUN_000f8970)(iVar34,uVar46);
    if (0 < (int)(*(uint ***** *)((char *)frame_ + 208))) {
      do {
        iVar21 = (int)ppppppuVar38 << 2;
        for (iVar22 = 0;
            iVar23 = ((int (*)())FUN_000f8980)(iVar34,ppppppuVar38,
                                  *(undefined4 *)(*(int *)(iVar20 + 0x30c) + 0xc)), iVar22 <= iVar23
            ; iVar22 = iVar22 + 1) {
          in_r6 = ppppppuVar37;
          in_r7 = (uint ******)(*(uint ***** *)((char *)frame_ + 236));
          ((int (*)())FUN_000f9a58)(param_1,(*(undefined1 * *)((char *)frame_ + 292)),*(undefined4 *)((int)param_2[0x19] + iVar21),ppppppuVar37,
                       (*(uint ***** *)((char *)frame_ + 236)));
          iVar20 = *(int *)(param_1 + 8);
          iVar21 = iVar21 + 0x14;
        }
        ppppppuVar38 = (uint ******)((int)ppppppuVar38 + 1);
      } while ((uint ******)(*(uint ***** *)((char *)frame_ + 208)) != ppppppuVar38);
    }
    iVar21 = 0;
    if (0 < iVar43) {
      do {
        iVar22 = iVar21 << 2;
        puVar53 = (undefined1 *)((int)(*(uint ***** *)((char *)frame_ + 208)) + iVar21);
        for (iVar23 = 0;
            iVar25 = ((int (*)())FUN_000f8980)(iVar34,puVar53,*(undefined4 *)(*(int *)(iVar20 + 0x30c) + 0xc)),
            iVar23 <= iVar25; iVar23 = iVar23 + 1) {
          in_r6 = *(uint *******)((int)param_2[0x1b] + iVar22);
          in_r8 = (uint ******)&(*(uint **** *)((char *)frame_ + 28));
          in_r7 = ppppppuVar37;
          ((int (*)())FUN_000fb3d4)(param_1,(*(undefined1 * *)((char *)frame_ + 296)),ppppppuVar49,in_r6,ppppppuVar37,in_r8,&(*(uint * *)((char *)frame_ + 84)));
          iVar20 = *(int *)(param_1 + 8);
          iVar22 = iVar22 + 0x14;
        }
        iVar21 = iVar21 + 1;
      } while (iVar43 != iVar21);
    }
    iVar20 = *(int *)(local_14c + 8);
    iVar43 = local_14c;
    while (iVar21 = iVar20, iVar21 != 0) {
      FUN_0019401c(iVar43);
      ((int (*)())FUN_000f92fc)(param_1,iVar43,(*(uint ***** *)((char *)frame_ + 16)));
      iVar43 = iVar21;
      iVar20 = *(int *)(iVar21 + 8);
    }
    (*(undefined4 *)((char *)frame_ + 220)) = 0;
    ppppppuVar38 = (uint ******)0x0;
    ppppppuVar40 = (uint ******)0x0;
code_r0x001005f4:
    ppppppuVar39 = (uint ******)(*(uint ***** *)((char *)frame_ + 16));
    ppppppuVar48 = (uint ******)PTR_DAT_001e8bd4;
    uVar10 = *(uint *)(iVar47 + (int)(*(int * *)((char *)frame_ + 20)) * 4);
    if (0x71 < uVar10) goto switchD_0010061c_caseD_0;
    switch(uVar10) {
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
      in_r7 = ppppppuVar38;
      in_r8 = (uint ******)(*(uint ***** *)((char *)frame_ + 208));
      iVar43 = ((int (*)())FUN_000fa958)(param_1,uVar10 - 2,ppppppuVar40,param_2,ppppppuVar38,(*(uint ***** *)((char *)frame_ + 208)),(*(undefined4 *)((char *)frame_ + 108)),
                            &(*(undefined4 *)((char *)frame_ + 24)),ppppppuVar37,(*(undefined4 *)((char *)frame_ + 220)),(*(uint ***** *)((char *)frame_ + 16)));
      if (iVar43 != 0) {
        FUN_00193f94((*(undefined1 * *)((char *)frame_ + 292)),iVar43);
      }
      goto code_r0x001025c0;
    case 0x12:
      FUN_00103d50(ppppppuVar38 + (int)ppppppuVar40 * 6 + 0x23,2,1);
      goto code_r0x00101d1c;
    case 0x14:
    case 0x15:
    case 0x16:
      uVar44 = (uint)*ppppppuVar49 >> 0x10 & 0x3fff;
      if (uVar10 == 0x14) {
        in_r7 = (uint ******)(PTR_DAT_001dc78c)[uVar44];
      }
      else if (uVar10 == 0x15) {
        in_r7 = (uint ******)(PTR_DAT_001dc77c)[uVar44];
      }
      else {
        in_r7 = (uint ******)(PTR_DAT_001dc76c)[uVar44];
      }
      goto code_r0x001022b4;
    case 0x17:
      iVar43 = FUN_000e47f4(param_2);
      if ((iVar43 == 0x3e) || (iVar43 = FUN_000e47f4(param_2), iVar43 == 0x71)) {
        uVar10 = puVar13[2];
        if (uVar10 != 0) {
          piVar18 = (int *)0x0;
          if (uVar10 - 1 < uVar10) {
            piVar18 = (int *)((uVar10 - 1) * 4 + puVar13[3]);
          }
          iVar43 = *piVar18;
          pppppuVar15 = (uint *****)(*(uint ***** *)((char *)frame_ + 232))[1];
          ppppppuVar48 = (uint ******)PTR_DAT_001e8bbc;
          if (pppppuVar15 != (uint *****)0x0) {
            pppppuVar52 = (uint *****)0x0;
            if ((uint *****)((int)pppppuVar15 - 1U) < pppppuVar15) {
              pppppuVar52 = (uint *****)((*(uint ***** *)((char *)frame_ + 232))[2] + (int)((int)pppppuVar15 - 1U));
            }
            if ((int)(*(uint **** *)((char *)frame_ + 8)) <= (int)(*pppppuVar52)[0x2e]) {
              uVar46 = *(undefined4 *)(iVar43 + 0x154);
              uVar50 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
              puVar32 = (undefined4 *)FUN_00193e18(uVar50,0x138);
              *puVar32 = uVar50;
              ppppppuVar48 = (uint ******)(puVar32 + 1);
              in_r6 = *(uint *******)(param_1 + 8);
              FUN_000ec0c8(ppppppuVar48,iVar43,*(undefined4 *)(iVar43 + 300),in_r6);
              puVar32[0x2f] = (*(uint **** *)((char *)frame_ + 8));
              FUN_000ec3ac(param_1,(*(uint ***** *)((char *)frame_ + 12)),ppppppuVar48);
              FUN_000e8e4c((*(uint ***** *)((char *)frame_ + 12)),ppppppuVar48);
              FUN_000e8e4c(ppppppuVar48,uVar46);
              (*(int *)((char *)frame_ + 212)) = 0;
              *(int *)(iVar43 + 0x138) = *(int *)(iVar43 + 0x138) + 1;
              (*(uint ***** *)((char *)frame_ + 12)) = (uint *****)ppppppuVar48;
              break;
            }
          }
          goto code_r0x00103718;
        }
      }
      else {
        iVar43 = FUN_000e47f4(param_2);
        ppppppuVar48 = (uint ******)PTR_DAT_001e8bb4;
        if (iVar43 == 0x72) {
          piVar18 = (int *)0x0;
          uVar10 = (*(uint * *)((char *)frame_ + 224))[1] - 1;
          if (uVar10 < (*(uint * *)((char *)frame_ + 224))[1]) {
            piVar18 = (int *)(uVar10 * 4 + (*(uint * *)((char *)frame_ + 224))[2]);
          }
          *(int *)(*piVar18 + 4) = *(int *)(*piVar18 + 4) + 1;
code_r0x00103718:
          in_r6 = (uint ******)0x0;
          in_r8 = ppppppuVar19;
          iVar47 = ((int (*)())FUN_000fd50c)(param_1,iVar47,&(*(int * *)((char *)frame_ + 20)),0,ppppppuVar48,ppppppuVar19);
          in_r7 = ppppppuVar48;
          goto code_r0x0010372c;
        }
      }
      goto switchD_0010061c_caseD_1;
    case 0x1f:
      (*(int * *)((char *)frame_ + 20)) = (int *)((int)(*(int * *)((char *)frame_ + 20)) + 1);
      uVar10 = *(uint *)(iVar47 + (int)(*(int * *)((char *)frame_ + 20)) * 4);
      (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)
                  (uVar10 << 0x18 | (uVar10 & 0xff00) << 8 | uVar10 >> 8 & 0xff00 | uVar10 >> 0x18);
      (*(int *)((char *)frame_ + 212)) = 0;
      break;
    case 0x20:
      (*(int * *)((char *)frame_ + 20)) = (int *)((int)(*(int * *)((char *)frame_ + 20)) + 1);
      uVar10 = *(uint *)(iVar47 + (int)(*(int * *)((char *)frame_ + 20)) * 4);
      in_r7 = (uint ******)&(*(undefined4 *)((char *)frame_ + 108));
      (*(undefined4 *)((char *)frame_ + 108)) = (uint *****)
                  (uVar10 << 0x18 | (uVar10 & 0xff00) << 8 | uVar10 >> 8 & 0xff00 | uVar10 >> 0x18);
      (*(int *)((char *)frame_ + 212)) = 0;
      break;
    case 0x21:
      ppppppuVar48 = (uint ******)0x0;
      switch((uint)*ppppppuVar49 >> 0x10 & 7) {
      case 0:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8b80;
        break;
      case 1:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8bac;
        break;
      case 2:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8ba8;
        break;
      case 3:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8bcc;
        break;
      case 4:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8b94;
        break;
      case 5:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8b74;
      }
      goto switchD_00102044_default;
    case 0x22:
      uVar10 = (uint)*ppppppuVar49 >> 0x16 & 7;
      if (uVar10 == 0) goto switchD_0010061c_caseD_1;
      ppppppuVar48 = FUN_001043f0(0x12,*(undefined4 *)(param_1 + 8));
      if ((*(int *)((char *)frame_ + 144)) == 0) {
        (*(int *)((char *)frame_ + 144)) = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = (*(int *)((char *)frame_ + 144));
      }
      iVar43 = (*(int *)((char *)frame_ + 144));
      iVar20 = FUN_001054ec(ppppppuVar48,0);
      *(int *)(iVar20 + 8) = iVar43;
      *(undefined4 *)(iVar20 + 0xc) = 0;
      pppuVar42 = **param_2[0x1b];
      if (((((uint)pppuVar42 & 0x3f0000) == 0x100000) && (*(int *)(param_1 + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar20 = 0xf;
      }
      else {
        iVar20 = (int)*(short *)((int)*param_2[0x1b] + 2);
      }
      uVar46 = FUN_000ec208(param_1,(uint)pppuVar42 >> 0x10 & 0x3f);
      iVar21 = FUN_001054ec(ppppppuVar48,1);
      *(undefined4 *)(iVar21 + 0xc) = uVar46;
      *(int *)(iVar21 + 8) = iVar20;
      in_r6 = ppppppuVar40;
      in_r7 = ppppppuVar48;
      ((int (*)())FUN_000f8aa0)(param_1,&(*(undefined4 *)((char *)frame_ + 24)),*param_2[0x1b],ppppppuVar40,ppppppuVar48);
      if (uVar10 == 2) {
        fVar5 = 1.0;
code_r0x001021c0:
        dVar54 = (double)fVar5;
        ((void (*)())FUN_000f79c4)(ppppppuVar48,param_1,2,dVar54,dVar54,dVar54,dVar54);
        FUN_00103d50(ppppppuVar48 + 0x2f,1,1);
      }
      else if (uVar10 < 3) {
        if (uVar10 == 1) {
          fVar5 = 0.5;
          goto code_r0x001021c0;
        }
      }
      else {
        if (uVar10 == 3) {
          fVar5 = 0.5;
        }
        else {
          if (uVar10 != 4) goto code_r0x00102220;
          fVar5 = 1.0;
        }
        dVar54 = (double)fVar5;
        ((void (*)())FUN_000f79c4)(ppppppuVar48,param_1,2,dVar54,dVar54,dVar54,dVar54);
      }
code_r0x00102220:
      ((int (*)())FUN_000f92fc)(param_1,ppppppuVar48,(*(uint ***** *)((char *)frame_ + 16)));
      iVar20 = FUN_001054ec(ppppppuVar38,ppppppuVar40);
      *(int *)(iVar20 + 8) = iVar43;
      *(undefined4 *)(iVar20 + 0xc) = 0;
      ppppppuVar40 = (uint ******)((int)ppppppuVar40 + 1);
      (*(int *)((char *)frame_ + 212)) = 0;
      (*(int * *)((char *)frame_ + 20)) = (int *)((int)(*(int * *)((char *)frame_ + 20)) + 1);
      break;
    case 0x23:
      ppppppuVar48 = (uint ******)0x0;
      switch((uint)*ppppppuVar49 >> 0x10 & 7) {
      case 0:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8bc0;
        break;
      case 1:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8b7c;
        break;
      case 2:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8ba4;
        break;
      case 3:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8b90;
        break;
      case 4:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8bc4;
        break;
      case 5:
        ppppppuVar48 = (uint ******)PTR_DAT_001e8ba0;
      }
      goto switchD_00102044_default;
    case 0x24:
      if (puVar13[2] != 0) {
        pppppuVar15 = (uint *****)(*(uint ***** *)((char *)frame_ + 232))[1];
        ppppppuVar48 = (uint ******)PTR_DAT_001e8b78;
        if (pppppuVar15 != (uint *****)0x0) {
          pppppuVar52 = (uint *****)0x0;
          if ((uint *****)((int)pppppuVar15 - 1U) < pppppuVar15) {
            pppppuVar52 = (uint *****)((*(uint ***** *)((char *)frame_ + 232))[2] + (int)((int)pppppuVar15 - 1U));
          }
          if ((int)(*(uint **** *)((char *)frame_ + 8)) <= (int)(*pppppuVar52)[0x2e]) {
            uVar10 = puVar13[2] - 1;
            piVar18 = (int *)0x0;
            if (uVar10 < (uint)puVar13[2]) {
              piVar18 = (int *)(uVar10 * 4 + puVar13[3]);
            }
            iVar43 = *piVar18;
            uVar50 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
            uVar46 = *(undefined4 *)(iVar43 + 0x150);
            puVar32 = (undefined4 *)FUN_00193e18(uVar50,0x138);
            *puVar32 = uVar50;
            ppppppuVar48 = (uint ******)(puVar32 + 1);
            in_r6 = *(uint *******)(param_1 + 8);
            FUN_000ec178(ppppppuVar48,iVar43,*(undefined4 *)(iVar43 + 300),in_r6);
            puVar32[0x2f] = (*(uint **** *)((char *)frame_ + 8));
            FUN_000ec3ac(param_1,(*(uint ***** *)((char *)frame_ + 12)),ppppppuVar48);
            FUN_000e8e4c((*(uint ***** *)((char *)frame_ + 12)),ppppppuVar48);
            FUN_000e8e4c(ppppppuVar48,uVar46);
            (*(int *)((char *)frame_ + 212)) = 0;
            *(undefined4 *)(iVar43 + 0x13c) = 1;
            (*(uint ***** *)((char *)frame_ + 12)) = (uint *****)ppppppuVar48;
            break;
          }
        }
        goto code_r0x00103718;
      }
      goto switchD_0010061c_caseD_1;
    case 0x26:
      puVar32 = (undefined4 *)0x0;
      uVar10 = puVar14[2] - 1;
      if (uVar10 < (uint)puVar14[2]) {
        puVar32 = (undefined4 *)(uVar10 * 4 + puVar14[3]);
      }
      if (*(int *)*puVar32 == 0) goto switchD_0010061c_caseD_1;
      piVar18 = (int *)((int)(*(int * *)((char *)frame_ + 20)) * 4 + iVar47);
      do {
        piVar36 = (*(int * *)((char *)frame_ + 20));
        if (*piVar18 == 0x37) {
          piVar36 = (int *)((int)(*(int * *)((char *)frame_ + 20)) + 1);
          piVar18 = piVar18 + 1;
        }
        (*(int * *)((char *)frame_ + 20)) = (int *)((int)piVar36 + 1);
        piVar18 = piVar18 + 1;
      } while (*piVar18 != 0x28);
      (*(int *)((char *)frame_ + 212)) = 0;
      (*(int * *)((char *)frame_ + 20)) = piVar36;
      break;
    case 0x27:
      pppppuVar52 = (uint *****)0x0;
      pppppuVar15 = (uint *****)((int)(*(uint ***** *)((char *)frame_ + 232))[1] - 1);
      if (pppppuVar15 < (*(uint ***** *)((char *)frame_ + 232))[1]) {
        pppppuVar52 = (uint *****)((*(uint ***** *)((char *)frame_ + 232))[2] + (int)pppppuVar15);
      }
      ppppuVar45 = *pppppuVar52;
      uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar32 = (undefined4 *)FUN_00193e18(uVar46,0x130);
      *puVar32 = uVar46;
      ppppppuVar48 = (uint ******)(puVar32 + 1);
      FUN_000ea020(ppppppuVar48,*(undefined4 *)(param_1 + 8));
      puVar32[0x2f] = (*(uint **** *)((char *)frame_ + 8));
      ppppuVar45[0x4e] = (uint ***)ppppppuVar48;
      (*(uint ***** *)((char *)frame_ + 16)) = (uint *****)ppppppuVar48;
      FUN_000e8e4c(ppppuVar45,ppppppuVar48);
      FUN_000ec3ac(param_1,(*(uint ***** *)((char *)frame_ + 12)),(*(uint ***** *)((char *)frame_ + 16)));
      goto code_r0x00103300;
    case 0x28:
      uVar10 = puVar14[2];
      piVar18 = (int *)0x0;
      if (uVar10 - 1 < uVar10) {
        piVar18 = (int *)((uVar10 - 1) * 4 + puVar14[3]);
      }
      piVar18 = (int *)*piVar18;
      FUN_00194208(puVar12,uVar10 - 1);
joined_r0x00103afc:
      if (piVar18 != (int *)0x0) {
        FUN_00193cc0(piVar18[-1],piVar18 + -1);
        goto code_r0x00101d1c;
      }
      goto switchD_0010061c_caseD_1;
    case 0x29:
      pppppuVar52 = (uint *****)0x0;
      pppppuVar15 = (uint *****)((int)(*(uint ***** *)((char *)frame_ + 232))[1] - 1);
      if (pppppuVar15 < (*(uint ***** *)((char *)frame_ + 232))[1]) {
        pppppuVar52 = (uint *****)((*(uint ***** *)((char *)frame_ + 232))[2] + (int)pppppuVar15);
      }
      ppppuVar45 = *pppppuVar52;
      pppuVar42 = ppppuVar45[0x4f];
      pppuVar42[0x2e] = (uint **)(*(uint **** *)((char *)frame_ + 8));
      FUN_000ec3ac(param_1,(*(uint ***** *)((char *)frame_ + 12)),pppuVar42);
      piVar18 = (int *)FUN_000e7b9c(ppppuVar45);
      piVar18[0x2e] = (int)(*(uint **** *)((char *)frame_ + 8));
      iVar43 = (**(code **)(*piVar18 + 0x38))();
      if ((iVar43 == 0) && (iVar43 = (**(code **)(*piVar18 + 0x3c))(piVar18), iVar43 == 0)) {
        FUN_000e8e4c(piVar18,pppuVar42);
      }
      ppppuVar30 = (uint ****)FUN_000e7a9c(ppppuVar45);
      ppppuVar30[0x2e] = (uint ***)(*(uint **** *)((char *)frame_ + 8));
      ppppuVar51 = ppppuVar30;
      if (ppppuVar30 == ppppuVar45) {
        uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar32 = (undefined4 *)FUN_00193e18(uVar46,0x130);
        *puVar32 = uVar46;
        ppppuVar51 = (uint ****)(puVar32 + 1);
        FUN_000ea020(ppppuVar51,*(undefined4 *)(param_1 + 8));
        puVar32[0x2f] = (*(uint **** *)((char *)frame_ + 8));
        ppppuVar30[0x4e] = (uint ***)ppppuVar51;
        FUN_000e8e4c(ppppuVar30,ppppuVar51);
        FUN_000ec3ac(param_1,(*(uint ***** *)((char *)frame_ + 12)),ppppuVar51);
      }
      iVar43 = (*(code *)(*ppppuVar51)[0xe])(ppppuVar51);
      if ((iVar43 == 0) && (iVar43 = (*(code *)(*ppppuVar51)[0xf])(ppppuVar51), iVar43 == 0)) {
        FUN_000e8e4c(ppppuVar51,pppuVar42);
      }
      uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar32 = (undefined4 *)FUN_00193e18(uVar46,0x130);
      *puVar32 = uVar46;
      ppppppuVar48 = (uint ******)(puVar32 + 1);
      FUN_000ea020(ppppppuVar48,*(undefined4 *)(param_1 + 8));
      puVar32[0x2f] = (*(uint **** *)((char *)frame_ + 8));
      (*(uint ***** *)((char *)frame_ + 16)) = (uint *****)ppppppuVar48;
      FUN_000ec3ac(param_1,pppuVar42,ppppppuVar48);
      FUN_000e8e4c(pppuVar42,(*(uint ***** *)((char *)frame_ + 16)));
      (*(uint ***** *)((char *)frame_ + 12)) = (*(uint ***** *)((char *)frame_ + 16));
      FUN_00194208((*(uint ***** *)((char *)frame_ + 232)),(int)(*(uint ***** *)((char *)frame_ + 232))[1] - 1);
      uVar10 = puVar13[2];
      if (uVar10 == 0) goto switchD_0010061c_caseD_1;
      piVar18 = (int *)0x0;
      if (uVar10 - 1 < uVar10) {
        piVar18 = (int *)((uVar10 - 1) * 4 + puVar13[3]);
      }
      (*(int *)((char *)frame_ + 212)) = 0;
      *(int *)(*piVar18 + 300) = *(int *)(*piVar18 + 300) + -1;
      break;
    case 0x2a:
      uVar10 = puVar24[2];
      if (uVar10 != 0) {
        puVar32 = (undefined4 *)0x0;
        if (uVar10 - 1 < uVar10) {
          puVar32 = (undefined4 *)((uVar10 - 1) * 4 + puVar24[3]);
        }
        piVar18 = (int *)*puVar32;
        FUN_00194208(ppppppuVar19,uVar10 - 1);
        if ((uint ******)piVar18[2] != (uint ******)0x0) {
          (*(uint ***** *)((char *)frame_ + 16)) = (uint *****)piVar18[2];
        }
        (*(int * *)((char *)frame_ + 20)) = (int *)piVar18[1];
        iVar47 = *piVar18;
        goto joined_r0x00103afc;
      }
      goto switchD_0010061c_caseD_0;
    case 0x2c:
      (*(int *)((char *)frame_ + 284)) = 0x1dd5d8;
      if ((UNK_001dc660 == 0) || (iVar34 == UNK_001dc660)) {
code_r0x00101020:
        (*(int *)((char *)frame_ + 300)) = 0;
      }
      else {
        piVar18 = &UNK_001dc66c;
        (*(int *)((char *)frame_ + 300)) = 0;
        do {
          iVar43 = *piVar18;
          (*(int *)((char *)frame_ + 300)) = (*(int *)((char *)frame_ + 300)) + 1;
          if (iVar43 == 0) goto code_r0x00101020;
          piVar18 = piVar18 + 3;
        } while (iVar34 != iVar43);
      }
      (*(int *)((char *)frame_ + 300)) = (*(int *)((char *)frame_ + 300)) * 0xc;
      uVar10 = *(uint *)((*(int *)((char *)frame_ + 300)) + 0x1dc664);
      if ((uVar10 & 0x80) == 0) {
        uVar17 = (uint)*(byte *)((int)param_2 + 0x8d);
        uVar44 = uVar17;
      }
      else {
        uVar17 = (uint)*ppppppuVar49 >> 0x18 & 0x1f;
        uVar44 = (uint)*(byte *)((int)param_2 + 0x8d);
      }
      if (*(int *)(param_1 + 0x7c) < (int)uVar44) {
        *(uint *)(param_1 + 0x7c) = uVar44;
      }
      *(uint *)(param_1 + 0x84) = 1 << (uVar44 & 0x3f) | *(uint *)(param_1 + 0x84);
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
      if ((int)*ppppppuVar49 < 0) {
        uVar31 = ((int (*)())FUN_000f8a0c)((uint)param_2[0x25] & 7);
        *puVar26 = uVar31;
        uVar31 = ((int (*)())FUN_000f8a0c)((uint)param_2[0x25] >> 3 & 7);
        puVar26[1] = uVar31;
        uVar31 = ((int (*)())FUN_000f8a0c)((uint)param_2[0x25] >> 0xc & 7);
        puVar26[2] = uVar31;
        uVar31 = ((int (*)())FUN_000f8a0c)((uint)param_2[0x25] >> 6 & 7);
        puVar26[5] = uVar31;
        uVar31 = ((int (*)())FUN_000f8a0c)((uint)param_2[0x25] >> 9 & 7);
        puVar26[6] = uVar31;
        uVar31 = ((int (*)())FUN_000f8a0c)((uint)param_2[0x25] >> 0xf & 7);
        puVar26[3] = uVar31;
        puVar26[0xb] = (ushort)((uint)param_2[0x25] >> 0x12) & 0x7f;
        if ((uVar10 & 4) != 0) {
          puVar26[8] = ((ushort)((uint)param_2[0x25] >> 0x19) & 1) + 1;
        }
      }
      if (param_2[0x18] != (uint *****)0x0) {
        pppppuVar15 = param_2[0x24];
        puVar26[0xc] = (ushort)pppppuVar15 & 0xff;
        puVar26[0xd] = (ushort)((uint)pppppuVar15 >> 8) & 0xff;
        puVar26[0xe] = (ushort)((uint)pppppuVar15 >> 0x10) & 0xff;
      }
      bVar3 = (uVar10 & 1) != 0;
      (*(uint *)((char *)frame_ + 204)) = (uint)*ppppppuVar49 >> 0x18 & 1;
      puVar26[9] = (ushort)(*(uint *)((char *)frame_ + 204)) ^ 1;
      bVar1 = ((uint)*ppppppuVar49 >> 0x19 & 1) == 0;
      puVar26[7] = (ushort)bVar1;
      if (bVar3) {
        puVar26[8] = (ushort)(iVar34 != 0x5f);
      }
      uVar46 = *(undefined4 *)(param_1 + 0x3ac);
      iVar43 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar43;
      (*(undefined4 *)((char *)frame_ + 200)) = FUN_00127608(uVar46,0,iVar43,0);
      (*(undefined4 *)((char *)frame_ + 24)) = *(uint *******)((*(undefined * *)((char *)frame_ + 304)) + -0x2c30);
      (*(undefined4 *)((char *)frame_ + 108)) = *(uint ******)((*(undefined * *)((char *)frame_ + 280)) + -0x2bfc);
      uVar46 = *(undefined4 *)(param_1 + 0x3ac);
      iVar43 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar43;
      uVar46 = FUN_00127608(uVar46,0,iVar43,0);
      pvVar16 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      FUN_001046c8(pvVar16,0,uVar46);
      (*(undefined4 * *)((char *)frame_ + 288)) = &(*(undefined4 *)((char *)frame_ + 24));
      ((int (*)())FUN_000fa958)(param_1,5,1,param_2,pvVar16,1,(*(undefined4 *)((char *)frame_ + 108)),(*(undefined4 * *)((char *)frame_ + 288)),ppppppuVar37,1,(*(uint ***** *)((char *)frame_ + 16)));
      ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
      if (bVar3) {
        uVar50 = *(undefined4 *)(param_1 + 0x3ac);
        iVar43 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar43;
        (*(undefined4 *)((char *)frame_ + 196)) = FUN_00127608(uVar50,0,iVar43,0);
        pvVar16 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(pvVar16,0,(*(undefined4 *)((char *)frame_ + 196)));
        ((int (*)())FUN_000fa958)(param_1,10,1,param_2,pvVar16,1,(*(undefined4 *)((char *)frame_ + 108)),(*(undefined4 * *)((char *)frame_ + 288)),ppppppuVar37,1,(*(uint ***** *)((char *)frame_ + 16)));
        ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
      }
      else {
        (*(undefined4 *)((char *)frame_ + 196)) = 0;
      }
      bVar2 = (uVar10 >> 3 & 1) != 0;
      if (bVar2) {
        uVar50 = *(undefined4 *)(param_1 + 0x3ac);
        iVar43 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar43;
        (*(undefined4 *)((char *)frame_ + 192)) = FUN_00127608(uVar50,0,iVar43,0);
        pvVar16 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(pvVar16,0,(*(undefined4 *)((char *)frame_ + 192)));
        ((int (*)())FUN_000fa958)(param_1,0xe,1,param_2,pvVar16,1,(*(undefined4 *)((char *)frame_ + 108)),(*(undefined4 * *)((char *)frame_ + 288)),ppppppuVar37,1,(*(uint ***** *)((char *)frame_ + 16)));
        ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
      }
      else {
        (*(undefined4 *)((char *)frame_ + 192)) = 0;
      }
      if ((uVar10 & 0x40) != 0) {
        pvVar16 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(pvVar16,0,uVar46);
        FUN_001046c8(pvVar16,1,(*(undefined4 *)((char *)frame_ + 196)));
        iVar43 = FUN_001054ec(pvVar16,1);
        *(undefined4 *)(iVar43 + 0x10) = 0;
        *(undefined4 *)((int)pvVar16 + 0x9c) = 0x1010100;
        ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
      }
      iVar20 = uVar44 * 0xc;
      iVar43 = *(int *)(*(int *)(param_1 + 0x78) + iVar20 + 4);
      if ((iVar43 == 4) || (uVar50 = uVar46, iVar43 == 0xb)) {
        uVar50 = *(undefined4 *)(param_1 + 0x3ac);
        iVar43 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar43;
        uVar50 = FUN_00127608(uVar50,0,iVar43,0);
        pvVar16 = FUN_001043f0(0x1b,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(pvVar16,0,uVar50);
        FUN_001046c8(pvVar16,1,uVar46);
        (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)0x2020001;
        iVar43 = FUN_001054ec(pvVar16,1);
        *(undefined4 *)(iVar43 + 0x10) = 0x2020001;
        FUN_001046c8(pvVar16,2,uVar46);
        (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)0x1000202;
        iVar43 = FUN_001054ec(pvVar16,2);
        *(undefined4 *)(iVar43 + 0x10) = 0x1000202;
        ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
        pvVar16 = FUN_001043f0(0x40,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(pvVar16,0,uVar50);
        *(undefined4 *)((int)pvVar16 + 0x9c) = 0x1010001;
        FUN_001046c8(pvVar16,1,uVar50);
        FUN_00103d50((int)pvVar16 + 0xa4,2,1);
        iVar43 = FUN_001054ec(pvVar16,1);
        *(undefined4 *)(iVar43 + 0x10) = 0x2020202;
        ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
        pvVar16 = FUN_001043f0(0x14,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(pvVar16,0,uVar50);
        *(undefined1 *)((int)pvVar16 + 0x9c) = 0;
        *(undefined1 *)((int)pvVar16 + 0x9d) = 0;
        *(undefined1 *)((int)pvVar16 + 0x9e) = 1;
        *(undefined1 *)((int)pvVar16 + 0x9f) = 1;
        FUN_001046c8(pvVar16,1,uVar50);
        FUN_001046c8(pvVar16,2,uVar50);
        iVar43 = FUN_001054ec(pvVar16,2);
        *(undefined4 *)(iVar43 + 0x10) = 0x2020202;
        ((void (*)())FUN_000f79c4)(pvVar16,param_1,3,1.5,1.5,1.5,1.5);
        ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
        piVar18 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(piVar18,0,uVar50);
        FUN_001046c8(piVar18,1,uVar50);
        (**(code **)(*piVar18 + 0x88))(piVar18,1,0,1);
        (**(code **)(*piVar18 + 0x88))(piVar18,1,1,0);
        (**(code **)(*piVar18 + 0x88))(piVar18,1,2,3);
        (**(code **)(*piVar18 + 0x88))(piVar18,1,3,0);
        ((int (*)())FUN_000f92fc)(param_1,piVar18,(*(uint ***** *)((char *)frame_ + 16)));
        if (iVar34 == 0x8b) {
          pvVar16 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
          FUN_001046c8(pvVar16,0,uVar50);
          *(undefined1 *)((int)pvVar16 + 0x9e) = 1;
          *(undefined1 *)((int)pvVar16 + 0x9f) = 0;
          *(undefined1 *)((int)pvVar16 + 0x9c) = 1;
          *(undefined1 *)((int)pvVar16 + 0x9d) = 1;
          FUN_001046c8(pvVar16,1,uVar46);
          ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
        }
        piVar18 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
        (**(code **)(*piVar18 + 0x5c))(piVar18,uVar44);
      }
      if (bVar2) {
        pvVar16 = FUN_001043f0(0x73,*(undefined4 *)(param_1 + 8));
        piVar18 = FUN_001043f0(0x72,*(undefined4 *)(param_1 + 8));
        uVar46 = FUN_00127608(*(undefined4 *)(param_1 + 0x3ac),0x1e,0,0);
        FUN_001046c8(pvVar16,0,uVar46);
        FUN_001046c8(pvVar16,1,(*(undefined4 *)((char *)frame_ + 196)));
        FUN_001046c8(piVar18,0,uVar46);
        FUN_001046c8(piVar18,1,(*(undefined4 *)((char *)frame_ + 192)));
        (**(code **)(*piVar18 + 0x90))(piVar18,uVar46);
        ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
        ((int (*)())FUN_000f92fc)(param_1,piVar18,(*(uint ***** *)((char *)frame_ + 16)));
      }
      else {
        uVar46 = 0;
      }
      uVar27 = uVar50;
      if (bVar3) {
        bVar3 = (uVar10 >> 2 & 1) == 0;
        if (!bVar3) {
          uVar27 = *(undefined4 *)(param_1 + 0x3ac);
          iVar43 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
          *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar43;
          uVar27 = FUN_00127608(uVar27,0,iVar43,0);
          pvVar16 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
          FUN_001046c8(pvVar16,0,uVar27);
          *(undefined4 *)((int)pvVar16 + 0x9c) = 1;
          FUN_001046c8(pvVar16,1,uVar50);
          ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
          pvVar16 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
          FUN_001046c8(pvVar16,0,uVar27);
          *(undefined4 *)((int)pvVar16 + 0x9c) = 0x1010100;
          FUN_001046c8(pvVar16,1,(*(undefined4 *)((char *)frame_ + 196)));
          ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
        }
      }
      else {
        bVar3 = (uVar10 >> 2 & 1) == 0;
      }
      iVar43 = *(int *)((*(int *)((char *)frame_ + 300)) + (*(int *)((char *)frame_ + 284)) + -0xf70);
      if ((bVar3) || (bVar1)) {
        if ((iVar43 != 0xff) || (*(int *)(iVar20 + *(int *)(param_1 + 0x78) + 4) != 7))
        goto code_r0x001019bc;
        pvVar16 = FUN_001043f0(0x104,*(undefined4 *)(param_1 + 8));
        *(uint *)((int)pvVar16 + 0x130) = uVar44;
        *(undefined4 *)((int)pvVar16 + 0x140) = *(undefined4 *)((*(undefined * *)((char *)frame_ + 304)) + -0x2c30);
        FUN_001046c8(pvVar16,0,(*(undefined4 *)((char *)frame_ + 200)));
        FUN_001046c8(pvVar16,1,uVar27);
        ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
      }
      else {
        iVar43 = 0xae;
code_r0x001019bc:
        piVar18 = FUN_001043f0(iVar43,*(undefined4 *)(param_1 + 8));
        piVar18[0x4f] = (int)puVar26;
        piVar18[0x4d] = uVar44;
        FUN_001046c8(piVar18,0,(*(undefined4 *)((char *)frame_ + 200)));
        FUN_001046c8(piVar18,1,uVar27);
        if (bVar2) {
          (**(code **)(*piVar18 + 0x90))(piVar18,uVar46);
        }
        iVar43 = *(int *)(param_1 + 0x78);
        if (*(int *)(iVar20 + iVar43 + 4) == 8) {
          (**(code **)(*piVar18 + 0x88))(piVar18,1,2,1);
          pvVar16 = FUN_001043f0(0xbe,*(undefined4 *)(param_1 + 8));
          iVar21 = piVar18[0x2b];
          iVar22 = piVar18[0x2c];
          iVar43 = FUN_001054ec(pvVar16,0);
          *(int *)(iVar43 + 0xc) = iVar22;
          *(int *)(iVar43 + 8) = iVar21;
          iVar21 = piVar18[0x2b];
          iVar22 = piVar18[0x2c];
          iVar43 = FUN_001054ec(pvVar16,1);
          *(int *)(iVar43 + 0xc) = iVar22;
          *(int *)(iVar43 + 8) = iVar21;
          iVar43 = FUN_001054ec(pvVar16,1);
          *(undefined4 *)(iVar43 + 0x10) = 0x1010101;
          *(undefined4 *)((int)pvVar16 + 0x9c) = 0x1000101;
          ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
          iVar43 = *(int *)(param_1 + 0x78);
        }
        if (*(int *)(iVar20 + iVar43 + 4) == 9) {
          pvVar16 = FUN_001043f0(0xbe,*(undefined4 *)(param_1 + 8));
          iVar21 = piVar18[0x2b];
          iVar22 = piVar18[0x2c];
          iVar43 = FUN_001054ec(pvVar16,0);
          *(int *)(iVar43 + 0xc) = iVar22;
          *(int *)(iVar43 + 8) = iVar21;
          iVar21 = piVar18[0x2b];
          iVar22 = piVar18[0x2c];
          iVar43 = FUN_001054ec(pvVar16,1);
          *(int *)(iVar43 + 0xc) = iVar22;
          *(int *)(iVar43 + 8) = iVar21;
          iVar43 = FUN_001054ec(pvVar16,1);
          *(undefined4 *)(iVar43 + 0x10) = 0x2020202;
          *(undefined4 *)((int)pvVar16 + 0x9c) = 0x1010001;
          ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
          iVar43 = *(int *)(param_1 + 0x78);
        }
        iVar43 = ((int (*)())FUN_000f89e8)(*(undefined4 *)(iVar20 + iVar43));
        piVar18[0x4e] = iVar43;
        *(short *)(piVar18[0x4f] + 0x12) = (short)(*(uint *)((char *)frame_ + 204));
        ((int (*)())FUN_000f92fc)(param_1,piVar18,(*(uint ***** *)((char *)frame_ + 16)));
        if (*(int *)(iVar20 + *(int *)(param_1 + 0x78) + 8) != 0) {
          pvVar16 = FUN_001043f0(0x13,*(undefined4 *)(param_1 + 8));
          iVar20 = piVar18[0x25];
          iVar21 = piVar18[0x26];
          iVar43 = FUN_001054ec(pvVar16,0);
          *(int *)(iVar43 + 0xc) = iVar21;
          *(int *)(iVar43 + 8) = iVar20;
          iVar20 = piVar18[0x26];
          iVar21 = piVar18[0x25];
          iVar43 = FUN_001054ec(pvVar16,1);
          (*(uint *)((char *)frame_ + 248)) = (uint)(short)uVar44;
          *(int *)(iVar43 + 0xc) = iVar20;
          (*(uint *)((char *)frame_ + 256)) = (*(uint *)((char *)frame_ + 248)) | 0x130000;
          (*(uint *)((char *)frame_ + 252)) = (*(uint *)((char *)frame_ + 248)) | 0x130000;
          (*(uint *)((char *)frame_ + 244)) = (*(uint *)((char *)frame_ + 248)) | 0x130000;
          (*(uint *)((char *)frame_ + 248)) = (*(uint *)((char *)frame_ + 248)) | 0x130000;
          *(int *)(iVar43 + 8) = iVar21;
          ((int (*)())FUN_000f771c)(pvVar16,param_1,2,(*(uint *)((char *)frame_ + 256)),(*(uint *)((char *)frame_ + 252)),(*(uint *)((char *)frame_ + 248)),(*(uint *)((char *)frame_ + 244)));
          ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
        }
      }
      (*(undefined4 *)((char *)frame_ + 24)) = *(uint *******)((*(undefined * *)((char *)frame_ + 304)) + -0x2c30);
      (*(undefined4 *)((char *)frame_ + 108)) = *(uint ******)((*(undefined * *)((char *)frame_ + 280)) + -0x2bfc);
      ppppppuVar38 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      in_r8 = (uint ******)((int)((unsigned char *)0x0) + 1);
      in_r6 = param_2;
      in_r7 = ppppppuVar38;
      ((int (*)())FUN_000fa958)(param_1,0,0,param_2,ppppppuVar38,1,(*(undefined4 *)((char *)frame_ + 108)),(*(undefined4 * *)((char *)frame_ + 288)),ppppppuVar37,1,(*(uint ***** *)((char *)frame_ + 16)));
      FUN_001046c8(ppppppuVar38,1,(*(undefined4 *)((char *)frame_ + 200)));
      goto code_r0x00101cbc;
    case 0x2d:
    case 0x2e:
      pppppuVar11 = (uint *****)(uint)*(byte *)((int)param_2 + 0x8d);
      pppppuVar15 = (uint *****)FUN_00193e18(*(undefined4 *)(*(int *)(param_1 + 8) + 0x374),0x24);
      _memset(pppppuVar15,0,0x24);
      *(undefined2 *)((int)pppppuVar15 + 0x12) = 1;
      *(undefined2 *)((int)pppppuVar15 + 0xe) = 1;
      *(undefined2 *)(pppppuVar15 + 5) = 0;
      *(undefined2 *)(pppppuVar15 + 4) = 0;
      *(undefined2 *)((int)pppppuVar15 + 0x16) = 0;
      *(undefined2 *)(pppppuVar15 + 6) = 0;
      *(undefined2 *)((int)pppppuVar15 + 0x1a) = 0;
      *(undefined2 *)(pppppuVar15 + 7) = 0;
      *(undefined2 *)(pppppuVar15 + 2) = 7;
      *(undefined2 *)(pppppuVar15 + 3) = 3;
      *(undefined2 *)pppppuVar15 = 3;
      *(undefined2 *)((int)pppppuVar15 + 2) = 3;
      *(undefined2 *)(pppppuVar15 + 1) = 3;
      *(undefined2 *)((int)pppppuVar15 + 6) = 7;
      *(undefined2 *)((int)pppppuVar15 + 10) = 3;
      *(ushort *)((int)pppppuVar15 + 0x12) =
           (ushort)(((uint)(byte)((((uint)*ppppppuVar49 & 0x1000000) == 0) << 1) << 0x1c) >> 0x1d);
      bVar1 = ((uint)*ppppppuVar49 >> 0x19 & 1) == 0;
      *(ushort *)((int)pppppuVar15 + 0xe) = (ushort)bVar1;
      uVar46 = *(undefined4 *)(param_1 + 0x3ac);
      iVar43 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar43;
      uVar46 = FUN_00127608(uVar46,0,iVar43,0);
      (*(undefined4 *)((char *)frame_ + 108)) = (uint *****)0x1;
      pppppuVar52 = *(uint ******)((*(undefined * *)((char *)frame_ + 304)) + -0x2c30);
      (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)pppppuVar52;
      pvVar16 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      FUN_001046c8(pvVar16,0,uVar46);
      *(undefined4 *)((int)pvVar16 + 0x9c) = 1;
      (*(undefined4 * *)((char *)frame_ + 288)) = &(*(undefined4 *)((char *)frame_ + 24));
      ((int (*)())FUN_000fa958)(param_1,5,1,param_2,pvVar16,1,(*(undefined4 *)((char *)frame_ + 108)),(*(undefined4 * *)((char *)frame_ + 288)),ppppppuVar37,1,(*(uint ***** *)((char *)frame_ + 16)));
      ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
      (*(undefined4 *)((char *)frame_ + 108)) = (uint *****)0x1010100;
      (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)pppppuVar52;
      ppppppuVar38 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      FUN_001046c8(ppppppuVar38,0,uVar46);
      ppppppuVar38[0x27] = (uint *****)0x1010100;
      ((int (*)())FUN_000fa958)(param_1,10,1,param_2,ppppppuVar38,1,(*(undefined4 *)((char *)frame_ + 108)),(*(undefined4 * *)((char *)frame_ + 288)),ppppppuVar37,1,(*(uint ***** *)((char *)frame_ + 16)));
      ((int (*)())FUN_000f92fc)(param_1,ppppppuVar38,(*(uint ***** *)((char *)frame_ + 16)));
      if (bVar1) {
        uVar50 = 0x76;
      }
      else {
        uVar50 = 0xae;
        if (uVar10 == 0x2d) {
          FUN_000e1534(*(undefined4 *)(param_1 + 8),0xf);
          uVar50 = 0xae;
        }
      }
      (*(undefined4 *)((char *)frame_ + 108)) = *(uint ******)((*(undefined * *)((char *)frame_ + 280)) + -0x2bfc);
      ppppppuVar39 = *(uint *******)((*(undefined * *)((char *)frame_ + 304)) + -0x2c30);
      (*(undefined4 *)((char *)frame_ + 24)) = ppppppuVar39;
      ppppppuVar48 = FUN_001043f0(uVar50,*(undefined4 *)(param_1 + 8));
      ppppppuVar48[0x4f] = pppppuVar15;
      ppppppuVar48[0x4d] = pppppuVar11;
      if (*(int *)(param_1 + 0x7c) < (int)pppppuVar11) {
        *(uint ******)(param_1 + 0x7c) = pppppuVar11;
      }
      *(uint *)(param_1 + 0x84) = 1 << ((uint)pppppuVar11 & 0x3f) | *(uint *)(param_1 + 0x84);
      pppppuVar15 = (uint *****)
                    ((int (*)())FUN_000f89e8)(*(undefined4 *)(*(int *)(param_1 + 0x78) + (int)pppppuVar11 * 0xc))
      ;
      ppppppuVar48[0x4c] = pppppuVar11;
      ppppppuVar48[0x4e] = pppppuVar15;
      in_r8 = (uint ******)((int)((unsigned char *)0x0) + 1);
      in_r6 = param_2;
      in_r7 = ppppppuVar48;
      iVar43 = ((int (*)())FUN_000fa958)(param_1,4,0,param_2,ppppppuVar48,1,(*(undefined4 *)((char *)frame_ + 108)),(*(undefined4 * *)((char *)frame_ + 288)),ppppppuVar37,1,
                            (*(uint ***** *)((char *)frame_ + 16)));
      if (iVar43 != 0) {
        FUN_00193f94((*(undefined1 * *)((char *)frame_ + 292)),iVar43);
      }
      FUN_001046c8(ppppppuVar48,1,uVar46);
      iVar43 = FUN_001054ec(ppppppuVar48,1);
      *(uint *******)(iVar43 + 0x10) = ppppppuVar39;
      pppppuVar15 = (uint *****)
                    ((int (*)())FUN_000f89e8)(*(undefined4 *)((int)pppppuVar11 * 0xc + *(int *)(param_1 + 0x78)))
      ;
      ppppppuVar48[0x4e] = pppppuVar15;
      ((int (*)())FUN_000f92fc)(param_1,ppppppuVar48,(*(uint ***** *)((char *)frame_ + 16)));
      goto code_r0x00101d1c;
    case 0x2f:
      uVar10 = (uint)*(byte *)((int)param_2 + 0x8d);
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
      uVar7 = (byte)((uint)*ppppppuVar49 >> 0x18) & 1;
      puVar26[9] = uVar7 ^ 1;
      puVar26[7] = (ushort)(((uint)(byte)((((uint)*ppppppuVar49 & 0x2000000) == 0) << 1) << 0x1c) >>
                           0x1d);
      uVar46 = *(undefined4 *)(param_1 + 0x3ac);
      iVar43 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar43;
      uVar50 = FUN_00127608(uVar46,0,iVar43,0);
      (*(undefined4 *)((char *)frame_ + 24)) = *(uint *******)((*(undefined * *)((char *)frame_ + 304)) + -0x2c30);
      (*(undefined4 *)((char *)frame_ + 108)) = *(uint ******)((*(undefined * *)((char *)frame_ + 280)) + -0x2bfc);
      uVar46 = *(undefined4 *)(param_1 + 0x3ac);
      iVar43 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
      *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar43;
      uVar27 = FUN_00127608(uVar46,0,iVar43,0);
      pvVar16 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      FUN_001046c8(pvVar16,0,uVar27);
      (*(undefined4 * *)((char *)frame_ + 288)) = &(*(undefined4 *)((char *)frame_ + 24));
      ((int (*)())FUN_000fa958)(param_1,5,1,param_2,pvVar16,1,(*(undefined4 *)((char *)frame_ + 108)),(*(undefined4 * *)((char *)frame_ + 288)),ppppppuVar37,1,(*(uint ***** *)((char *)frame_ + 16)));
      ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
      uVar46 = 0;
      if (iVar34 == 0x5f) {
        uVar46 = *(undefined4 *)(param_1 + 0x3ac);
        iVar43 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar43;
        uVar46 = FUN_00127608(uVar46,0,iVar43,0);
        pvVar16 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(pvVar16,0,uVar46);
        ((int (*)())FUN_000fa958)(param_1,10,1,param_2,pvVar16,1,(*(undefined4 *)((char *)frame_ + 108)),(*(undefined4 * *)((char *)frame_ + 288)),ppppppuVar37,1,(*(uint ***** *)((char *)frame_ + 16)));
        ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
        uVar41 = *(undefined4 *)(param_1 + 0x3ac);
        iVar43 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar43;
        uVar41 = FUN_00127608(uVar41,0,iVar43,0);
        pvVar16 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(pvVar16,0,uVar41);
        ((int (*)())FUN_000fa958)(param_1,0xe,1,param_2,pvVar16,1,(*(undefined4 *)((char *)frame_ + 108)),(*(undefined4 * *)((char *)frame_ + 288)),ppppppuVar37,1,(*(uint ***** *)((char *)frame_ + 16)));
        ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
      }
      else {
        uVar41 = 0;
      }
      pvVar16 = FUN_001043f0(0x78,*(undefined4 *)(param_1 + 8));
      *(undefined2 **)((int)pvVar16 + 0x13c) = puVar26;
      FUN_001046c8(pvVar16,0,uVar50);
      FUN_001046c8(pvVar16,1,uVar27);
      if (iVar34 == 0x5f) {
        FUN_001046c8(pvVar16,2,uVar46);
        FUN_001046c8(pvVar16,3,uVar41);
      }
      *(uint *)((int)pvVar16 + 0x134) = uVar10;
      if (*(int *)(param_1 + 0x7c) < (int)uVar10) {
        *(uint *)(param_1 + 0x7c) = uVar10;
      }
      *(uint *)(param_1 + 0x84) = 1 << (uVar10 & 0x3f) | *(uint *)(param_1 + 0x84);
      uVar46 = ((int (*)())FUN_000f89e8)(*(undefined4 *)(uVar10 * 0xc + *(int *)(param_1 + 0x78)));
      *(undefined4 *)((int)pvVar16 + 0x138) = uVar46;
      *(uint *)((int)pvVar16 + 0x130) = uVar10;
      *(ushort *)(*(int *)((int)pvVar16 + 0x13c) + 0x12) = uVar7;
      ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
      (*(undefined4 *)((char *)frame_ + 24)) = *(uint *******)((*(undefined * *)((char *)frame_ + 304)) + -0x2c30);
      (*(undefined4 *)((char *)frame_ + 108)) = *(uint ******)((*(undefined * *)((char *)frame_ + 280)) + -0x2bfc);
      ppppppuVar38 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
      in_r8 = (uint ******)((int)((unsigned char *)0x0) + 1);
      in_r6 = param_2;
      in_r7 = ppppppuVar38;
      ((int (*)())FUN_000fa958)(param_1,0,0,param_2,ppppppuVar38,1,(*(undefined4 *)((char *)frame_ + 108)),(*(undefined4 * *)((char *)frame_ + 288)),ppppppuVar37,1,(*(uint ***** *)((char *)frame_ + 16)));
      FUN_001046c8(ppppppuVar38,1,uVar50);
code_r0x00101cbc:
      ((int (*)())FUN_000f92fc)(param_1,ppppppuVar38,(*(uint ***** *)((char *)frame_ + 16)));
      goto code_r0x00101d1c;
    case 0x30:
      iVar43 = iVar47 + (int)(*(int * *)((char *)frame_ + 20)) * 4;
      ((void (*)())FUN_000f79c4)(ppppppuVar38,param_1,ppppppuVar40,(double)*(float *)(iVar43 + 4),
                   (double)*(float *)(iVar43 + 8),(double)*(float *)(iVar43 + 0xc),
                   (double)*(float *)(iVar43 + 0x10));
      iVar43 = FUN_001054ec(ppppppuVar38,ppppppuVar40);
      FUN_000f2bdc(&(*(undefined4 *)((char *)frame_ + 184)),*(undefined4 *)(iVar43 + 0x10),(*(undefined4 *)((char *)frame_ + 24)));
      uVar46 = (*(undefined4 *)((char *)frame_ + 184));
      iVar43 = FUN_001054ec(ppppppuVar38,ppppppuVar40);
      *(undefined4 *)(iVar43 + 0x10) = uVar46;
      ppppppuVar40 = (uint ******)((int)ppppppuVar40 + 1);
      (*(int *)((char *)frame_ + 212)) = 0;
      (*(int * *)((char *)frame_ + 20)) = (*(int * *)((char *)frame_ + 20)) + 1;
      break;
    case 0x31:
      uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
      puVar32 = (undefined4 *)FUN_00193e18(uVar46,0x10);
      *puVar32 = uVar46;
      puVar35 = puVar32 + 1;
      (*(int * *)((char *)frame_ + 20)) = (int *)((int)(*(int * *)((char *)frame_ + 20)) + 1);
      switch(*(undefined4 *)(iVar47 + (int)(*(int * *)((char *)frame_ + 20)) * 4)) {
      case 0x3f:
        *puVar35 = (uint)*ppppppuVar49 >> 0x12 & 1;
        break;
      default:
        *puVar35 = 0;
        break;
      case 0x5f:
        *puVar35 = (uint)*ppppppuVar49 >> 0x18 & 1;
        break;
      case 0x67:
        *puVar35 = 1;
      }
      uVar10 = puVar14[2];
      if (uVar10 < *puVar12) {
        _memset(uVar10 * 4 + puVar14[3],0,4);
        puVar14[2] = uVar10 + 1;
        puVar32 = (undefined4 *)(uVar10 * 4 + puVar14[3]);
      }
      else {
        puVar32 = (undefined4 *)FUN_0019423c(puVar12,uVar10);
      }
      (*(int *)((char *)frame_ + 212)) = 0;
      *puVar32 = puVar35;
      break;
    case 0x32:
      ppppppuVar48 = (uint ******)0x0;
      pppppuVar15 = (uint *****)(*(uint ***** *)((char *)frame_ + 232))[1];
      if (pppppuVar15 != (uint *****)0x0) {
        pppppuVar52 = (uint *****)0x0;
        if ((uint *****)((int)pppppuVar15 - 1U) < pppppuVar15) {
          pppppuVar52 = (uint *****)((*(uint ***** *)((char *)frame_ + 232))[2] + (int)((int)pppppuVar15 - 1U));
        }
        ppppppuVar48 = (uint ******)*pppppuVar52;
        ppppppuVar48[0x51] = (uint *****)0x0;
      }
      (*(int * *)((char *)frame_ + 20)) = (int *)((int)(*(int * *)((char *)frame_ + 20)) + 1);
      switch(*(undefined4 *)(iVar47 + (int)(*(int * *)((char *)frame_ + 20)) * 4)) {
      case 0x62:
        pvVar16 = FUN_001043f0(0x8b,*(undefined4 *)(param_1 + 8));
        ((void (*)())FUN_000f79c4)(pvVar16,param_1,1,1.0,1.0,1.0,1.0);
        ((void (*)())FUN_000f79c4)(pvVar16,param_1,2,1.0,1.0,1.0,1.0);
        *(undefined4 *)((int)pvVar16 + 300) = 0;
        uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar32 = (undefined4 *)FUN_00193e18(uVar46,0x15c);
        *puVar32 = uVar46;
        pppppuVar15 = (uint *****)(puVar32 + 1);
        in_r6 = (uint ******)0x0;
        in_r7 = *(uint *******)(param_1 + 8);
        FUN_000ea6d0(pppppuVar15,pvVar16,ppppppuVar48,0,in_r7);
        break;
      case 99:
        iVar43 = *(int *)(param_1 + 8);
        pppuVar42 = **param_2[0x1b];
        if (((((uint)pppuVar42 & 0x3f0000) == 0x100000) && (iVar43 != 0)) &&
           ((*(uint *)(*(int *)(iVar43 + 0x30c) + 8) & 0x80) != 0)) {
          iVar20 = 0xf;
        }
        else {
          iVar20 = (int)*(short *)((int)*param_2[0x1b] + 2);
        }
        pvVar16 = FUN_001043f0(0x8d,iVar43);
        uVar46 = FUN_000ec208(param_1,(uint)pppuVar42 >> 0x10 & 0x3f);
        iVar43 = FUN_001054ec(pvVar16,1);
        *(undefined4 *)(iVar43 + 0xc) = uVar46;
        puVar8 = PTR_DAT_001e8b84;
        *(int *)(iVar43 + 8) = iVar20;
        *(undefined4 *)((int)pvVar16 + 300) = *(undefined4 *)puVar8;
        uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar32 = (undefined4 *)FUN_00193e18(uVar46,0x15c);
        *puVar32 = uVar46;
        pppppuVar15 = (uint *****)(puVar32 + 1);
        in_r6 = *(uint *******)(param_1 + 8);
        FUN_000ebac8(pppppuVar15,pvVar16,ppppppuVar48,in_r6);
        FUN_000e78c0(pppppuVar15,(*(uint **** *)((char *)frame_ + 8)));
        FUN_000ed63c(param_1,pvVar16);
        pppppuVar52 = (uint *****)0x0;
        if ((uint *****)(*(uint ***** *)((char *)frame_ + 232))[1] != (uint *****)0x0) {
          puVar32[0x53] = 0;
          pppppuVar52 = (uint *****)(*(uint ***** *)((char *)frame_ + 232))[1];
        }
        if (pppppuVar52 < *(*(uint ***** *)((char *)frame_ + 232))) {
          _memset((*(uint ***** *)((char *)frame_ + 232))[2] + (int)pppppuVar52,0,4);
          (*(uint ***** *)((char *)frame_ + 232))[1] = (uint ****)((int)pppppuVar52 + 1);
          pppppuVar52 = (uint *****)((*(uint ***** *)((char *)frame_ + 232))[2] + (int)pppppuVar52);
        }
        else {
          pppppuVar52 = (uint *****)FUN_0019423c((*(uint ***** *)((char *)frame_ + 232)),pppppuVar52);
        }
        *pppppuVar52 = (uint ****)pppppuVar15;
        uVar10 = puVar13[2];
        if (uVar10 == 0) goto code_r0x00103240;
        goto code_r0x00103214;
      case 100:
        ppppuVar45 = *param_2[0x1b];
        pppuVar42 = *ppppuVar45;
        iVar43 = *(int *)(param_1 + 8);
        if ((((uint)pppuVar42 & 0x3f0000) == 0x100000) && (iVar43 != 0)) {
          piVar18 = *(int **)(iVar43 + 0x30c);
          if ((piVar18[2] & 0x80U) == 0) goto code_r0x00100810;
          iVar20 = 0xf;
        }
        else {
          piVar18 = *(int **)(iVar43 + 0x30c);
code_r0x00100810:
          iVar20 = (int)*(short *)((int)ppppuVar45 + 2);
        }
        ppppuVar45 = param_2[0x1b][1];
        pppuVar33 = *ppppuVar45;
        if (((((uint)pppuVar33 & 0x3f0000) == 0x100000) && (iVar43 != 0)) &&
           ((piVar18[2] & 0x80U) != 0)) {
          iVar43 = 0xf;
        }
        else {
          iVar43 = (int)*(short *)((int)ppppuVar45 + 2);
        }
        in_r8 = (uint ******)((uint)pppuVar33 >> 0x10 & 0x3f);
        pvVar16 = (void *)(**(code **)(*piVar18 + 0x24))
                                    (piVar18,(uint)*ppppppuVar49 >> 0x10 & 7,iVar20,
                                     (uint)pppuVar42 >> 0x10 & 0x3f,iVar43,in_r8,(*(undefined4 *)((char *)frame_ + 24)),param_2);
        uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar32 = (undefined4 *)FUN_00193e18(uVar46,0x15c);
        *puVar32 = uVar46;
        pppppuVar15 = (uint *****)(puVar32 + 1);
        in_r6 = (uint ******)0x0;
        in_r7 = *(uint *******)(param_1 + 8);
        FUN_000ea6d0(pppppuVar15,pvVar16,ppppppuVar48,0,in_r7);
        break;
      case 0x65:
        uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar32 = (undefined4 *)FUN_00193e18(uVar46,0x168);
        *puVar32 = uVar46;
        puVar32 = puVar32 + 1;
        FUN_0010502c(puVar32,0x8c,*(undefined4 *)(param_1 + 8));
        uVar46 = 6;
        goto code_r0x00102c90;
      case 0x66:
        uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar32 = (undefined4 *)FUN_00193e18(uVar46,0x168);
        *puVar32 = uVar46;
        puVar32 = puVar32 + 1;
        FUN_0010502c(puVar32,0x8c,*(undefined4 *)(param_1 + 8));
        uVar46 = 7;
code_r0x00102c90:
        puVar32[0x4b] = uVar46;
        in_r7 = (uint ******)(*(uint ***** *)((char *)frame_ + 232));
        in_r8 = ppppppuVar37;
        pppppuVar15 = (uint *****)
                      ((int (*)())FUN_000fadc4)(param_1,puVar32,(*(uint **** *)((char *)frame_ + 8)),ppppppuVar48,(*(uint ***** *)((char *)frame_ + 232)),ppppppuVar37,
                                   param_2);
        in_r6 = ppppppuVar48;
        goto code_r0x00103240;
      default:
        pppppuVar15 = (uint *****)0x0;
        goto code_r0x00103240;
      case 0x6f:
        uVar10 = (*(uint * *)((char *)frame_ + 224))[1] - 1;
        puVar32 = (undefined4 *)0x0;
        if (uVar10 < (*(uint * *)((char *)frame_ + 224))[1]) {
          puVar32 = (undefined4 *)(uVar10 * 4 + (*(uint * *)((char *)frame_ + 224))[2]);
        }
        piVar18 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
        in_r8 = (*(undefined4 *)((char *)frame_ + 24));
        uVar46 = (**(code **)(*piVar18 + 0x28))
                           (piVar18,1,*(undefined4 *)*puVar32,4,param_2[(int)param_2[0x16] + 0x23],
                            (*(undefined4 *)((char *)frame_ + 24)),param_2,(*(uint ***** *)((char *)frame_ + 16)));
        uVar50 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar32 = (undefined4 *)FUN_00193e18(uVar50,0x15c);
        *puVar32 = uVar50;
        pppppuVar15 = (uint *****)(puVar32 + 1);
        in_r6 = (uint ******)0x0;
        in_r7 = *(uint *******)(param_1 + 8);
        FUN_000ea6d0(pppppuVar15,uVar46,ppppppuVar48,0,in_r7);
        uVar10 = (*(uint * *)((char *)frame_ + 224))[1] - 1;
        if (uVar10 < (*(uint * *)((char *)frame_ + 224))[1]) {
          piVar18 = (int *)(uVar10 * 4 + (*(uint * *)((char *)frame_ + 224))[2]);
        }
        else {
          piVar18 = (int *)0x0;
        }
        iVar43 = *piVar18;
        FUN_000e77f4(pppppuVar15,*(undefined4 *)(iVar43 + 8));
        *(uint ******)(iVar43 + 8) = pppppuVar15;
        FUN_000e78c0(pppppuVar15,(*(uint **** *)((char *)frame_ + 8)));
        FUN_000ed63c(param_1,uVar46);
        goto code_r0x0010319c;
      case 0x72:
        iVar43 = *(int *)(param_1 + 8);
        pppuVar42 = **param_2[0x1b];
        if ((((uint)pppuVar42 & 0x3f0000) == 0x100000) && (iVar43 != 0)) {
          piVar18 = *(int **)(iVar43 + 0x30c);
          if ((piVar18[2] & 0x80U) == 0) goto code_r0x0010082c;
          iVar43 = 0xf;
        }
        else {
          piVar18 = *(int **)(iVar43 + 0x30c);
code_r0x0010082c:
          iVar43 = (int)*(short *)((int)*param_2[0x1b] + 2);
        }
        in_r8 = (*(undefined4 *)((char *)frame_ + 24));
        pvVar16 = (void *)(**(code **)(*piVar18 + 0x28))
                                    (piVar18,iVar34 == 0x6f,iVar43,(uint)pppuVar42 >> 0x10 & 0x3f,0,
                                     (*(undefined4 *)((char *)frame_ + 24)),param_2,(*(uint ***** *)((char *)frame_ + 16)));
        uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar32 = (undefined4 *)FUN_00193e18(uVar46,0x15c);
        *puVar32 = uVar46;
        pppppuVar15 = (uint *****)(puVar32 + 1);
        in_r6 = (uint ******)0x0;
        in_r7 = *(uint *******)(param_1 + 8);
        FUN_000ea6d0(pppppuVar15,pvVar16,ppppppuVar48,0,in_r7);
      }
      FUN_000e78c0(pppppuVar15,(*(uint **** *)((char *)frame_ + 8)));
      FUN_000ed63c(param_1,pvVar16);
code_r0x0010319c:
      pppppuVar52 = (uint *****)0x0;
      if ((uint *****)(*(uint ***** *)((char *)frame_ + 232))[1] != (uint *****)0x0) {
        pppppuVar15[0x52] = (uint ****)0x0;
        pppppuVar52 = (uint *****)(*(uint ***** *)((char *)frame_ + 232))[1];
      }
      if (pppppuVar52 < *(*(uint ***** *)((char *)frame_ + 232))) {
        _memset((*(uint ***** *)((char *)frame_ + 232))[2] + (int)pppppuVar52,0,4);
        (*(uint ***** *)((char *)frame_ + 232))[1] = (uint ****)((int)pppppuVar52 + 1);
        pppppuVar52 = (uint *****)((*(uint ***** *)((char *)frame_ + 232))[2] + (int)pppppuVar52);
      }
      else {
        pppppuVar52 = (uint *****)FUN_0019423c((*(uint ***** *)((char *)frame_ + 232)),pppppuVar52);
      }
      *pppppuVar52 = (uint ****)pppppuVar15;
      uVar10 = puVar13[2];
      if (uVar10 != 0) {
code_r0x00103214:
        piVar18 = (int *)0x0;
        if (uVar10 - 1 < uVar10) {
          piVar18 = (int *)((uVar10 - 1) * 4 + puVar13[3]);
        }
        *(int *)(*piVar18 + 300) = *(int *)(*piVar18 + 300) + 1;
      }
code_r0x00103240:
      FUN_000ec3ac(param_1,(*(uint ***** *)((char *)frame_ + 12)),pppppuVar15);
      FUN_000e8e4c((*(uint ***** *)((char *)frame_ + 12)),pppppuVar15);
      (*(uint ***** *)((char *)frame_ + 16)) = (uint *****)pppppuVar15[0x4d];
      (*(uint ***** *)((char *)frame_ + 12)) = pppppuVar15;
      FUN_000ec3ac(param_1,pppppuVar15,(*(uint ***** *)((char *)frame_ + 16)));
code_r0x00103300:
      (*(int *)((char *)frame_ + 212)) = 0;
      (*(uint ***** *)((char *)frame_ + 12)) = (*(uint ***** *)((char *)frame_ + 16));
      break;
    case 0x34:
      iVar43 = FUN_001054ec(ppppppuVar38,ppppppuVar40);
      (*(int *)((char *)frame_ + 212)) = 0;
      ppppppuVar40 = (uint ******)((int)ppppppuVar40 + 1);
      *(undefined4 *)(iVar43 + 8) = 0;
      *(undefined4 *)(iVar43 + 0xc) = 0x21;
      break;
    case 0x35:
      piVar18 = (int *)0x0;
      uVar10 = puVar13[2] - 1;
      if (uVar10 < (uint)puVar13[2]) {
        piVar18 = (int *)(uVar10 * 4 + puVar13[3]);
      }
      iVar20 = *piVar18;
      iVar43 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),3);
      if ((iVar43 == 0) || (iVar43 = FUN_0012c2dc(param_1,iVar20), iVar43 == 0)) {
        in_r6 = &(*(uint ***** *)((char *)frame_ + 12));
        in_r7 = &(*(uint ***** *)((char *)frame_ + 16));
        in_r8 = (uint ******)&(*(uint **** *)((char *)frame_ + 8));
        iVar43 = FUN_0012f0f8(param_1,ppppppuVar37,iVar20,in_r6,in_r7,in_r8);
        if (iVar43 != 0) goto switchD_0010061c_caseD_1;
        if (*(int *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0x4c) < (int)(*(uint **** *)((char *)frame_ + 8))) {
          FUN_000e1534(*(int *)(param_1 + 8),8);
        }
        iVar21 = *(int *)(iVar20 + 0x150);
        FUN_000ec3ac(param_1,(*(uint ***** *)((char *)frame_ + 12)),iVar21);
        iVar43 = (*(code *)(*(*(uint ***** *)((char *)frame_ + 12)))[0xe])();
        if ((iVar43 == 0) && (iVar43 = (*(code *)(*(*(uint ***** *)((char *)frame_ + 12)))[0xf])(), iVar43 == 0)) {
          FUN_000e8e4c((*(uint ***** *)((char *)frame_ + 12)),iVar21);
        }
        uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar32 = (undefined4 *)FUN_00193e18(uVar46,0x130);
        *puVar32 = uVar46;
        puVar29 = puVar32 + 1;
        FUN_000ea020(puVar29,*(undefined4 *)(param_1 + 8));
        FUN_000e8e4c(iVar20,puVar29);
        FUN_000ec3ac(param_1,iVar21,puVar29);
        iVar43 = *(int *)(iVar20 + 0x154);
        FUN_000e8e4c(puVar29,iVar43);
        FUN_000ec3ac(param_1,puVar29,iVar43);
        uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
        puVar29 = (undefined4 *)FUN_00193e18(uVar46,0x130);
        *puVar29 = uVar46;
        ppppppuVar48 = (uint ******)(puVar29 + 1);
        FUN_000ea020(ppppppuVar48,*(undefined4 *)(param_1 + 8));
        (*(uint ***** *)((char *)frame_ + 16)) = (uint *****)ppppppuVar48;
        FUN_000ec3ac(param_1,iVar43,ppppppuVar48);
        FUN_000e8e4c(iVar43,(*(uint ***** *)((char *)frame_ + 16)));
        (*(uint ***** *)((char *)frame_ + 12)) = (*(uint ***** *)((char *)frame_ + 16));
        FUN_00194208(ppppppuVar37,puVar13[2] + -1);
        (*(int *)((char *)frame_ + 212)) = 0;
        *(uint *****)(iVar21 + 0xb8) = (*(uint **** *)((char *)frame_ + 8));
        (*(uint **** *)((char *)frame_ + 8)) = (uint ****)((int)(*(uint **** *)((char *)frame_ + 8)) - 1);
        *(uint *****)(iVar43 + 0xb8) = (*(uint **** *)((char *)frame_ + 8));
        puVar32[0x2f] = (*(uint **** *)((char *)frame_ + 8));
        (*(uint ***** *)((char *)frame_ + 16))[0x2e] = (*(uint **** *)((char *)frame_ + 8));
      }
      else {
        (*(uint ***** *)((char *)frame_ + 12)) = (uint *****)FUN_000e7e90(iVar20);
        if (*(int **)(iVar20 + 0x150) != (int *)0x0) {
          (**(code **)(**(int **)(iVar20 + 0x150) + 4))();
        }
        if (*(int **)(iVar20 + 0x154) != (int *)0x0) {
          (**(code **)(**(int **)(iVar20 + 0x154) + 4))();
        }
        FUN_00194374((*(uint ***** *)((char *)frame_ + 12))[0x34],iVar20);
        do {
          ppppppuVar48 = (uint ******)(*(uint ***** *)((char *)frame_ + 12))[2];
          pppppuVar15 = ppppppuVar48[0x26];
          for (pppppuVar52 = (uint *****)ppppppuVar48[0x26][2]; pppppuVar52 != (uint *****)0x0;
              pppppuVar52 = (uint *****)pppppuVar52[2]) {
            if (((uint)pppppuVar15[5] & 1) != 0) {
              pppppuVar15[5] = (uint ****)((uint)pppppuVar15[5] & 0xfffffffe);
            }
            pppppuVar15 = pppppuVar52;
          }
          FUN_00193fa4(ppppppuVar48 + 0x24);
          FUN_0019401c(ppppppuVar48);
          if (ppppppuVar48 != (uint ******)0x0) {
            (*(code *)(*ppppppuVar48)[1])(ppppppuVar48);
          }
        } while (ppppppuVar48 != (uint ******)(*(uint ***** *)((char *)frame_ + 16)));
        (*(int *)((char *)frame_ + 212)) = 0;
        (*(uint **** *)((char *)frame_ + 8)) = (uint ****)((int)(*(uint **** *)((char *)frame_ + 8)) - 1);
        (*(uint ***** *)((char *)frame_ + 16)) = (*(uint ***** *)((char *)frame_ + 12));
      }
      break;
    case 0x36:
      uVar10 = puVar13[2];
      uVar46 = 0;
      if (uVar10 != 0) {
        puVar32 = (undefined4 *)0x0;
        if (uVar10 - 1 < uVar10) {
          puVar32 = (undefined4 *)((uVar10 - 1) * 4 + puVar13[3]);
        }
        uVar46 = *puVar32;
      }
      in_r6 = (uint ******)(uint)(iVar34 == 0x71);
      if (in_r6 == (uint ******)0x0) {
        uVar10 = (uint)*(ushort *)((int)*param_2[0x1b] + 2);
      }
      else {
        uVar10 = 0;
      }
      uVar50 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar32 = (undefined4 *)FUN_00193e18(uVar50,0x15c);
      *puVar32 = uVar50;
      puVar29 = puVar32 + 1;
      in_r7 = *(uint *******)(param_1 + 8);
      FUN_000ea828(puVar29,uVar10,uVar46,in_r6,in_r7);
      puVar32[0x2f] = (*(uint **** *)((char *)frame_ + 8));
      if (((uint)*ppppppuVar49 & 0x10000) != 0) {
        puVar32[0x4e] = 1;
      }
      FUN_000ed63c(param_1,puVar32[0x53]);
      pppppuVar15 = (uint *****)puVar13[2];
      if (pppppuVar15 < *ppppppuVar37) {
        _memset((int)pppppuVar15 * 4 + puVar13[3],0,4);
        puVar13[2] = (int)pppppuVar15 + 1;
        puVar28 = (undefined4 *)((int)pppppuVar15 * 4 + puVar13[3]);
      }
      else {
        puVar28 = (undefined4 *)FUN_0019423c(ppppppuVar37,pppppuVar15);
      }
      *puVar28 = puVar29;
      (*(uint **** *)((char *)frame_ + 8)) = (uint ****)((int)(*(uint **** *)((char *)frame_ + 8)) + 1);
      FUN_000ec3ac(param_1,(*(uint ***** *)((char *)frame_ + 12)),puVar29);
      FUN_000e8e4c((*(uint ***** *)((char *)frame_ + 12)),puVar29);
      uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
      puVar28 = (undefined4 *)FUN_00193e18(uVar46,0x130);
      *puVar28 = uVar46;
      ppppppuVar48 = (uint ******)(puVar28 + 1);
      FUN_000ea020(ppppppuVar48,*(undefined4 *)(param_1 + 8));
      puVar28[0x2f] = (*(uint **** *)((char *)frame_ + 8));
      (*(uint ***** *)((char *)frame_ + 16)) = (uint *****)ppppppuVar48;
      FUN_000ec3ac(param_1,puVar29,ppppppuVar48);
      FUN_000e8e4c(puVar29,(*(uint ***** *)((char *)frame_ + 16)));
      (*(uint ***** *)((char *)frame_ + 12)) = (*(uint ***** *)((char *)frame_ + 16));
      (*(int *)((char *)frame_ + 212)) = 0;
      puVar32[0x4d] = *(undefined4 *)(*(int *)(param_1 + 8) + 0x324);
      break;
    case 0x37:
      (*(int * *)((char *)frame_ + 20)) = (int *)((int)(*(int * *)((char *)frame_ + 20)) + 1);
      uVar46 = *(undefined4 *)(iVar47 + (int)(*(int * *)((char *)frame_ + 20)) * 4);
      if (*(int *)(param_1 + 0x47c) != 0) {
        uVar46 = 0x75;
      }
      ppppppuVar38 = FUN_001043f0(uVar46,*(undefined4 *)(param_1 + 8));
      (*(int *)((char *)frame_ + 212)) = 0;
      break;
    case 0x38:
      (*(undefined4 *)((char *)frame_ + 220)) = 1;
      goto code_r0x00101d1c;
    case 0x3a:
      (*(int *)((char *)frame_ + 212)) = 0;
      ppppppuVar38[0x48] = (uint *****)0x1;
      goto code_r0x00103b3c;
    case 0x3d:
      FUN_00103d50(ppppppuVar38 + (int)ppppppuVar40 * 6 + 0x23,1,
                   (uint)ppppppuVar38[(int)ppppppuVar40 * 6 + 0x28] & 1 ^ 1);
      goto code_r0x00101d1c;
    case 0x42:
      (*(int * *)((char *)frame_ + 20)) = (int *)((int)(*(int * *)((char *)frame_ + 20)) + 1);
      dVar54 = (double)*(float *)(iVar47 + (int)(*(int * *)((char *)frame_ + 20)) * 4);
      ((void (*)())FUN_000f79c4)(ppppppuVar38,param_1,ppppppuVar40,dVar54,dVar54,dVar54,dVar54);
      goto code_r0x001025c0;
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
      ppppppuVar48 = (uint ******)
                     (PTR_s_IF_b_001dc2cc)[uVar10 * 4 + ((uint)*ppppppuVar49 >> 0x10 & 0x3fff)];
      goto switchD_00102044_default;
    case 0x4a:
      ppppppuVar48 = *(uint *******)((int)&PTR_DAT_001dc75c + ((uint)*ppppppuVar49 >> 0xe & 0xc));
switchD_00102044_default:
      in_r6 = (uint ******)(*(uint ***** *)((char *)frame_ + 16));
      in_r8 = ppppppuVar19;
      iVar47 = ((int (*)())FUN_000fd50c)(param_1,iVar47,&(*(int * *)((char *)frame_ + 20)),(*(uint ***** *)((char *)frame_ + 16)),ppppppuVar48,ppppppuVar19);
      in_r7 = ppppppuVar48;
code_r0x0010372c:
      (*(int *)((char *)frame_ + 212)) = 0;
      break;
    case 0x4b:
      if ((((uint)*ppppppuVar49 & 0x10000) == 0) ||
         (bVar1 = true, (*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x40) != 0)) {
        bVar1 = false;
      }
      in_r7 = (uint ******)PTR_DAT_001e8b98;
      if (bVar1) {
        in_r7 = (uint ******)PTR_DAT_001e8b9c;
      }
code_r0x001022b4:
      in_r6 = (uint ******)(*(uint ***** *)((char *)frame_ + 16));
      in_r8 = ppppppuVar19;
      iVar47 = ((int (*)())FUN_000fd50c)(param_1,iVar47,&(*(int * *)((char *)frame_ + 20)),(*(uint ***** *)((char *)frame_ + 16)),in_r7,ppppppuVar19);
      goto code_r0x0010372c;
    case 0x4d:
      (*(int *)((char *)frame_ + 212)) = 0;
      *(ushort *)((int)ppppppuVar38[0x4f] + 0x12) = (byte)((uint)*ppppppuVar49 >> 0x18) & 1;
      break;
    case 0x4e:
      ppppppuVar48 = (uint ******)
                     ((int (*)())FUN_000f8ccc)((uint)*ppppppuVar49 >> 0x10 & 7,*(undefined4 *)(param_1 + 8),0);
      goto code_r0x00101f74;
    case 0x4f:
      (*(int * *)((char *)frame_ + 20)) = (int *)((int)(*(int * *)((char *)frame_ + 20)) + 1);
      ((void (*)())FUN_001048d4)(ppppppuVar38,(double)*(float *)(iVar47 + (int)(*(int * *)((char *)frame_ + 20)) * 4));
      goto code_r0x00101d1c;
    case 0x50:
      (*(int * *)((char *)frame_ + 20)) = (int *)((int)(*(int * *)((char *)frame_ + 20)) + 1);
      ((void (*)())FUN_0010490c)(ppppppuVar38,(double)*(float *)(iVar47 + (int)(*(int * *)((char *)frame_ + 20)) * 4));
      goto code_r0x00101d1c;
    case 0x51:
      bVar4 = *(byte *)((int)param_2 + 0x8d);
      pppppuVar15 = (uint *****)(uint)bVar4;
      if ((*(uint *)((int)(*(undefined4 * *)((char *)frame_ + 240)) + (bVar4 >> 3 & 0x1c) + 8) >> (bVar4 & 0x1f) & 1) == 0) {
        FUN_000e0e0c(*(undefined4 *)(param_1 + 8),"TextureStage %d misses DCLPT\n",pppppuVar15,in_r6
                     ,in_r7,in_r8,bVar4 & 0x1f,0);
      }
      pppppuVar52 = *(uint ******)(param_1 + 0x7c);
      if ((int)*(uint ******)(param_1 + 0x7c) < (int)pppppuVar15) {
        pppppuVar52 = pppppuVar15;
      }
      *(uint ******)(param_1 + 0x7c) = pppppuVar52;
      *(uint *)(param_1 + 0x84) = 1 << ((uint)pppppuVar15 & 0x3f) | *(uint *)(param_1 + 0x84);
      ppppppuVar38[0x4d] = pppppuVar15;
      ppppppuVar38[0x4c] = pppppuVar15;
      (*(int *)((char *)frame_ + 212)) = 0;
      pppppuVar15 = (uint *****)
                    ((int (*)())FUN_000f89e8)(*(undefined4 *)((int)pppppuVar15 * 0xc + *(int *)(param_1 + 0x78)))
      ;
      ppppppuVar38[0x4e] = pppppuVar15;
      break;
    case 0x52:
      (*(int *)((char *)frame_ + 212)) = 0;
      ppppppuVar38[0x4d] = (uint *****)(uint)*(byte *)((int)param_2 + 0x8d);
      ppppppuVar38[0x4c] = (uint *****)(uint)*(byte *)((int)param_2 + 0x8d);
      break;
    case 0x53:
      ppppppuVar48 = (uint ******)
                     ((int (*)())FUN_000f8ccc)((uint)*ppppppuVar49 >> 0x10 & 7,*(undefined4 *)(param_1 + 8),1);
code_r0x00101f74:
      if (ppppppuVar48 != (uint ******)0x0) goto switchD_00102044_default;
      goto switchD_0010061c_caseD_1;
    case 0x54:
      pppppuVar15 = *ppppppuVar49;
      sVar6 = *(short *)((int)*param_2[0x19] + 2);
      uVar10 = (uint)**param_2[0x19] >> 0x10 & 0x3f;
      FUN_000ec208(param_1,uVar10);
      uVar50 = *(undefined4 *)(param_1 + 0x3ac);
      uVar46 = FUN_000ec208(param_1,uVar10);
      in_r6 = (uint ******)0x0;
      iVar43 = FUN_00127608(uVar50,uVar46,(int)sVar6,0);
      if (((uint)pppppuVar15 >> 0x10 & 0x3fff) == 0) goto switchD_0010061c_caseD_1;
      (*(int *)((char *)frame_ + 212)) = 0;
      *(undefined4 *)(iVar43 + 0x30) = 1;
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
      iVar43 = (&(*(undefined4 *)((char *)frame_ + 140)))[uVar10 - 0x55];
      if (iVar43 == 0) {
        iVar43 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar43;
        (&(*(undefined4 *)((char *)frame_ + 140)))[uVar10 - 0x55] = iVar43;
      }
      iVar20 = FUN_001054ec(ppppppuVar38,ppppppuVar40);
      *(undefined4 *)(iVar20 + 0xc) = 0;
      *(int *)(iVar20 + 8) = iVar43;
      if (ppppppuVar40 == (uint ******)0x0) {
        in_r6 = (uint ******)0x0;
        in_r7 = (uint ******)0x0;
        in_r8 = ppppppuVar38;
        ((int (*)())FUN_000f8d50)(param_1,ppppppuVar37,(*(undefined4 *)((char *)frame_ + 108)),0,0,ppppppuVar38,0);
      }
      else {
        in_r6 = ppppppuVar40;
        in_r7 = ppppppuVar38;
        ((int (*)())FUN_000f8aa0)(param_1,&(*(undefined4 *)((char *)frame_ + 24)),0,ppppppuVar40,ppppppuVar38);
      }
      goto code_r0x001025c0;
    case 0x60:
      puVar32 = (undefined4 *)0x0;
      uVar10 = puVar14[2] - 1;
      if (uVar10 < (uint)puVar14[2]) {
        puVar32 = (undefined4 *)(uVar10 * 4 + puVar14[3]);
      }
      if (*(int *)*puVar32 != 0) goto switchD_0010061c_caseD_1;
      piVar18 = (int *)((int)(*(int * *)((char *)frame_ + 20)) * 4 + iVar47);
      do {
        piVar36 = (*(int * *)((char *)frame_ + 20));
        if (*piVar18 == 0x37) {
          piVar36 = (int *)((int)(*(int * *)((char *)frame_ + 20)) + 1);
          piVar18 = piVar18 + 1;
        }
        (*(int * *)((char *)frame_ + 20)) = (int *)((int)piVar36 + 1);
        piVar18 = piVar18 + 1;
      } while (*piVar18 != 0x26);
      (*(int *)((char *)frame_ + 212)) = 0;
      (*(int * *)((char *)frame_ + 20)) = piVar36;
      break;
    case 0x6a:
      FUN_000e1534(*(undefined4 *)(param_1 + 8),0xf);
      goto code_r0x00101d1c;
    case 0x6b:
      iVar43 = FUN_000e07dc(*(undefined4 *)(param_1 + 8),4);
      in_r7 = (uint ******)PTR_DAT_001e8bd8;
      if (iVar43 != 0) {
        in_r7 = (uint ******)PTR_DAT_001e8bb0;
      }
      in_r8 = ppppppuVar19;
      iVar47 = ((int (*)())FUN_000fd50c)(param_1,iVar47,&(*(int * *)((char *)frame_ + 20)),ppppppuVar39,in_r7,ppppppuVar19);
      in_r6 = ppppppuVar39;
      goto code_r0x0010372c;
    case 0x6c:
      (*(code *)(*ppppppuVar38)[9])(ppppppuVar38);
      (*(int *)((char *)frame_ + 212)) = 0;
      ppppppuVar38[0x4b] = (uint *****)0x1;
      goto code_r0x00103b3c;
    case 0x6d:
      iVar43 = FUN_001054ec(ppppppuVar38,1);
      iVar20 = *(int *)(iVar43 + 0x10);
      iVar43 = *(int *)((*(undefined * *)((char *)frame_ + 304)) + -0x2c30);
      if (iVar20 != iVar43) {
        uVar46 = *(undefined4 *)(param_1 + 0x3ac);
        in_r6 = (uint ******)0x0;
        iVar21 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
        *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar21;
        uVar46 = FUN_00127608(uVar46,0,iVar21,0);
        pvVar16 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
        FUN_001046c8(pvVar16,1,uVar46);
        pppppuVar52 = ppppppuVar38[0x25];
        pppppuVar15 = ppppppuVar38[0x26];
        iVar21 = FUN_001054ec(pvVar16,0);
        *(uint ******)(iVar21 + 0xc) = pppppuVar15;
        *(uint ******)(iVar21 + 8) = pppppuVar52;
        iVar21 = FUN_001054ec(pvVar16,1);
        *(int *)(iVar21 + 0x10) = iVar20;
        iVar21 = FUN_001054ec(ppppppuVar38,0);
        *(undefined4 *)((int)pvVar16 + 0x9c) = *(undefined4 *)(iVar21 + 0x10);
        FUN_001046c8(ppppppuVar38,0,uVar46);
        FUN_000f32cc(&(*(uint **** *)((char *)frame_ + 188)),iVar20);
        ppppppuVar38[0x27] = (uint *****)(*(uint **** *)((char *)frame_ + 188));
        iVar20 = FUN_001054ec(ppppppuVar38,1);
        *(int *)(iVar20 + 0x10) = iVar43;
        FUN_00193f94((*(undefined1 * *)((char *)frame_ + 292)),pvVar16);
        goto code_r0x00101d1c;
      }
switchD_0010061c_caseD_1:
      (*(int *)((char *)frame_ + 212)) = 0;
      break;
    case 0x6e:
      (*(int * *)((char *)frame_ + 20)) = (int *)((int)(*(int * *)((char *)frame_ + 20)) + 1);
      in_r6 = *(uint *******)(iVar47 + (int)(*(int * *)((char *)frame_ + 20)) * 4);
      in_r7 = in_r6;
      in_r8 = in_r6;
      ((int (*)())FUN_000f7870)(ppppppuVar38,param_1,ppppppuVar40,in_r6,in_r6,in_r6,in_r6);
code_r0x001025c0:
      ppppppuVar40 = (uint ******)((int)ppppppuVar40 + 1);
      (*(int *)((char *)frame_ + 212)) = 0;
      break;
    case 0x70:
      uVar10 = (*(uint * *)((char *)frame_ + 224))[1];
      piVar18 = (int *)0x0;
      if (uVar10 - 1 < uVar10) {
        piVar18 = (int *)((uVar10 - 1) * 4 + (*(uint * *)((char *)frame_ + 224))[2]);
      }
      if (*(int *)(*piVar18 + 4) == 0) {
        puVar32 = (undefined4 *)0x0;
        uVar46 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x378);
        if (uVar10 - 1 < (*(uint * *)((char *)frame_ + 224))[1]) {
          puVar32 = (undefined4 *)((uVar10 - 1) * 4 + (*(uint * *)((char *)frame_ + 224))[2]);
        }
        uVar50 = *puVar32;
        FUN_00194208((*(uint * *)((char *)frame_ + 224)),(*(uint * *)((char *)frame_ + 224))[1] - 1);
        FUN_00193cc0(uVar46,uVar50);
      }
      else {
        piVar18 = (int *)0x0;
        if (uVar10 - 1 < (*(uint * *)((char *)frame_ + 224))[1]) {
          piVar18 = (int *)((uVar10 - 1) * 4 + (*(uint * *)((char *)frame_ + 224))[2]);
        }
        in_r6 = (uint ******)0x0;
        *(int *)(*piVar18 + 4) = *(int *)(*piVar18 + 4) + -1;
        (*(int * *)((char *)frame_ + 20)) = (int *)((int)(*(int * *)((char *)frame_ + 20)) + -1);
        in_r8 = ppppppuVar19;
        iVar47 = ((int (*)())FUN_000fd50c)(param_1,iVar47,&(*(int * *)((char *)frame_ + 20)),0,ppppppuVar48,ppppppuVar19);
        in_r7 = ppppppuVar48;
      }
code_r0x00101d1c:
      (*(int *)((char *)frame_ + 212)) = 0;
      break;
    case 0x71:
      (*(int *)((char *)frame_ + 212)) = 0;
      ppppppuVar38[0x50] = *(uint ******)(iVar47 + ((int)(*(int * *)((char *)frame_ + 20)) + 1) * 4);
      (*(int * *)((char *)frame_ + 20)) = (int *)((int)(*(int * *)((char *)frame_ + 20)) + 1);
    }
    goto code_r0x00103b34;
  case 7:
    bVar1 = true;
  }
  ppppppuVar19 = (uint ******)((int (*)())FUN_000f9140)(param_1,iVar34,(uint)*ppppppuVar49 >> 0x10 & 0x3fff);
  ((int (*)())FUN_000f9a58)(param_1,(*(undefined1 * *)((char *)frame_ + 292)),*param_2[0x19],ppppppuVar37,(*(uint ***** *)((char *)frame_ + 236)));
  sVar6 = *(short *)((int)*param_2[0x19] + 2);
  uVar46 = FUN_000ec208(param_1,(uint)**param_2[0x19] >> 0x10 & 0x3f);
  iVar43 = FUN_001054ec(ppppppuVar19,0);
  *(undefined4 *)(iVar43 + 0xc) = uVar46;
  *(int *)(iVar43 + 8) = (int)sVar6;
  in_r7 = (uint ******)0x0;
  in_r6 = (uint ******)*param_2[0x19];
  in_r8 = ppppppuVar19;
  ((int (*)())FUN_000f8d50)(param_1,ppppppuVar37,0,in_r6,0,ppppppuVar19,0);
  iVar43 = ((int (*)())FUN_000f8970)(iVar34,*(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 0xc));
  ppppppuVar38 = (uint ******)(iVar43 + 1);
  if (1 < (int)ppppppuVar38) {
    ppppppuVar40 = (uint ******)((int)((unsigned char *)0x0) + 1);
    iVar43 = 0;
    (*(undefined * *)((char *)frame_ + 304)) = &DAT_001ad5d8;
    do {
      (*(undefined4 *)((char *)frame_ + 24)) = *(uint *******)((*(undefined * *)((char *)frame_ + 304)) + -0x2c30);
      in_r8 = (uint ******)&(*(uint **** *)((char *)frame_ + 28));
      ((int (*)())FUN_000fb3d4)(param_1,(*(undefined1 * *)((char *)frame_ + 296)),ppppppuVar49,*(undefined4 *)(iVar43 + (int)param_2[0x1b]),
                   ppppppuVar37,&(*(uint **** *)((char *)frame_ + 28)),&(*(uint * *)((char *)frame_ + 84)));
      uVar10 = **(uint **)(iVar43 + (int)param_2[0x1b]);
      if ((((uVar10 & 0x3f0000) == 0x100000) && (*(int *)(param_1 + 8) != 0)) &&
         ((*(uint *)(*(int *)(*(int *)(param_1 + 8) + 0x30c) + 8) & 0x80) != 0)) {
        iVar47 = 0xf;
      }
      else {
        iVar47 = (int)(short)**(uint **)(iVar43 + (int)param_2[0x1b]);
      }
      uVar46 = FUN_000ec208(param_1,uVar10 >> 0x10 & 0x3f);
      iVar20 = FUN_001054ec(ppppppuVar19,ppppppuVar40);
      *(undefined4 *)(iVar20 + 0xc) = uVar46;
      *(int *)(iVar20 + 8) = iVar47;
      if ((!bVar1) &&
         (iVar47 = FUN_0011346c(*(undefined4 *)(param_1 + 8),ppppppuVar19), iVar47 != 0)) {
        if (ppppppuVar40 == (uint ******)((int)((unsigned char *)0x0) + 1U)) {
          puVar12 = &UNK_001aa9d4;
        }
        else {
          puVar12 = &DAT_001aa9cc;
        }
        (*(undefined4 *)((char *)frame_ + 24)) = (uint ******)*puVar12;
      }
      in_r6 = ppppppuVar40;
      in_r7 = ppppppuVar19;
      ((int (*)())FUN_000f8aa0)(param_1,&(*(undefined4 *)((char *)frame_ + 24)),*(undefined4 *)(iVar43 + (int)param_2[0x1b]),ppppppuVar40,
                   ppppppuVar19);
      ppppppuVar40 = (uint ******)((int)ppppppuVar40 + 1);
      iVar43 = iVar43 + 4;
    } while (ppppppuVar38 != ppppppuVar40);
  }
  (*(int *)((char *)frame_ + 216)) = FUN_000f3a30(ppppppuVar19);
  if (bVar1) {
    iVar20 = *(int *)(*(int *)(param_1 + 8) + 0x3ac) + -1;
    *(int *)(*(int *)(param_1 + 8) + 0x3ac) = iVar20;
    pppppuVar52 = ppppppuVar19[0x25];
    pppppuVar15 = ppppppuVar19[0x26];
    iVar43 = FUN_001054ec(ppppppuVar19,0);
    *(int *)(iVar43 + 8) = iVar20;
    *(undefined4 *)(iVar43 + 0xc) = 0;
    iVar43 = FUN_0011346c(*(undefined4 *)(param_1 + 8),ppppppuVar19);
    iVar47 = FUN_001054ec(ppppppuVar19,0);
    ppppppuVar40 = *(uint *******)(iVar47 + 0x10);
    (*(undefined4 *)((char *)frame_ + 24)) = ppppppuVar40;
    if (1 < (*(int *)((char *)frame_ + 216))) {
      (*(uint **** *)((char *)frame_ + 276)) = (uint ****)&(*(uint **** *)((char *)frame_ + 8));
      iVar47 = 0;
      (*(uint **** *)((char *)frame_ + 312)) = (*(uint **** *)((char *)frame_ + 276));
      do {
        iVar21 = FUN_000f30d4((*(undefined4 *)((char *)frame_ + 24)));
        iVar22 = ((int (*)())FUN_000f9140)(param_1,iVar34,(uint)*ppppppuVar49 >> 0x10 & 0x3fff);
        ppppuVar45 = (*(uint **** *)((char *)frame_ + 312));
        if (0 < (int)ppppppuVar38) {
          ppppppuVar48 = (uint ******)0x0;
          do {
            in_r6 = ppppppuVar48;
            FUN_00105e54(iVar22,ppppppuVar48,ppppppuVar19,ppppppuVar48);
            if (iVar43 != 0) {
              iVar23 = FUN_001054ec(iVar22,ppppppuVar48);
              pppppuVar11 = *(uint ******)(iVar23 + 0x10);
              if (ppppppuVar48 == (uint ******)((int)((unsigned char *)0x0) + 1U)) {
                (*(undefined4 *)((char *)frame_ + 108)) = (uint *****)
                            CONCAT31((int3)((uint)pppppuVar11 >> 8),
                                     *(undefined1 *)((int)ppppuVar45 + iVar21 + 100));
              }
              else if (ppppppuVar48 == (uint ******)((int)((unsigned char *)0x0) + 2U)) {
                (*(undefined4 *)((char *)frame_ + 108)) = (uint *****)
                            CONCAT13(*(undefined1 *)((int)ppppuVar45 + iVar21 + 100),
                                     (int3)pppppuVar11);
              }
              else {
                (*(undefined4 *)((char *)frame_ + 108)) = pppppuVar11;
                if (ppppppuVar48 == (uint ******)((int)((unsigned char *)0x0) + 3U)) {
                  (*(unsigned short *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 108))) + 0)) = (undefined2)((uint)pppppuVar11 >> 0x10);
                  (*(unsigned short *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 108))) + 2)) =
                       CONCAT11(*(undefined1 *)((int)ppppuVar45 + iVar21 + 100),(char)pppppuVar11);
                }
              }
              pppppuVar11 = (*(undefined4 *)((char *)frame_ + 108));
              iVar23 = FUN_001054ec(iVar22,ppppppuVar48);
              *(uint ******)(iVar23 + 0x10) = pppppuVar11;
            }
            ppppppuVar48 = (uint ******)((int)ppppppuVar48 + 1);
          } while (ppppppuVar38 != ppppppuVar48);
        }
        *(undefined4 *)(iVar22 + 0x9c) = *(undefined4 *)(PTR_DAT_001e8b64 + iVar21 * 4);
        *(undefined1 *)((int)(*(uint **** *)((char *)frame_ + 276)) + iVar21 + 0x10) = 1;
        *(uint ******)(iVar22 + 0x120) = ppppppuVar19[0x48];
        FUN_00193f64((*(undefined1 * *)((char *)frame_ + 296)),iVar22);
        iVar47 = iVar47 + 1;
      } while ((*(int *)((char *)frame_ + 216)) + -1 != iVar47);
    }
    ppppppuVar19[0x27] = (uint *****)(*(undefined4 *)((char *)frame_ + 24));
    if ((iVar43 != 0) && (iVar34 = FUN_000f30d4((*(undefined4 *)((char *)frame_ + 24))), 1 < (int)ppppppuVar38)) {
      ppppppuVar49 = (uint ******)((int)((unsigned char *)0x0) + 1);
      do {
        iVar43 = FUN_001054ec(ppppppuVar19,ppppppuVar49);
        ppppppuVar48 = *(uint *******)(iVar43 + 0x10);
        (*(undefined4 *)((char *)frame_ + 140)) = ppppppuVar48;
        if (ppppppuVar49 == (uint ******)((int)((unsigned char *)0x0) + 1U)) {
          (*(undefined4 *)((char *)frame_ + 140)) = (uint ******)
                      CONCAT31((int3)((uint)ppppppuVar48 >> 8),
                               *(undefined1 *)((int)&(*(undefined4 *)((char *)frame_ + 140)) + iVar34));
        }
        else if (ppppppuVar49 == (uint ******)((int)((unsigned char *)0x0) + 2U)) {
          (*(undefined4 *)((char *)frame_ + 140)) = (uint ******)
                      CONCAT13(*(undefined1 *)((int)&(*(undefined4 *)((char *)frame_ + 140)) + iVar34),(int3)ppppppuVar48);
        }
        else if (ppppppuVar49 == (uint ******)((int)((unsigned char *)0x0) + 3U)) {
          (*(unsigned short *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 140))) + 0)) = (undefined2)((uint)ppppppuVar48 >> 0x10);
          (*(unsigned short *)((unsigned char *)&((*(undefined4 *)((char *)frame_ + 140))) + 2)) = CONCAT11(*(undefined1 *)((int)&(*(undefined4 *)((char *)frame_ + 140)) + iVar34),(char)ppppppuVar48);
        }
        ppppppuVar48 = (*(undefined4 *)((char *)frame_ + 140));
        iVar43 = FUN_001054ec(ppppppuVar19,ppppppuVar49);
        ppppppuVar49 = (uint ******)((int)ppppppuVar49 + 1);
        *(uint *******)(iVar43 + 0x10) = ppppppuVar48;
      } while (ppppppuVar38 != ppppppuVar49);
    }
    pvVar16 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    iVar34 = FUN_001054ec(pvVar16,0);
    *(uint ******)(iVar34 + 0xc) = pppppuVar15;
    *(uint ******)(iVar34 + 8) = pppppuVar52;
    *(uint *******)((int)pvVar16 + 0x9c) = ppppppuVar40;
    iVar34 = FUN_001054ec(pvVar16,1);
    *(int *)(iVar34 + 8) = iVar20;
    *(undefined4 *)(iVar34 + 0xc) = 0;
    FUN_00193f94((*(undefined1 * *)((char *)frame_ + 292)),pvVar16);
  }
  piVar18 = *(int **)(*(int *)(param_1 + 8) + 0x30c);
  iVar34 = (**(code **)(*piVar18 + 0x34))(piVar18,ppppppuVar19);
  if (iVar34 == 0) {
code_r0x001002dc:
    pvVar16 = (void *)0x0;
  }
  else {
    iVar34 = FUN_001054ec(ppppppuVar19,0);
    iVar47 = 0;
    iVar43 = 0;
    (*(undefined4 *)((char *)frame_ + 24)) = *(uint *******)(iVar34 + 0x10);
    in_r8 = (uint ******)&(*(undefined4 *)((char *)frame_ + 140));
    (*(undefined4 *)((char *)frame_ + 140)) = *(uint *******)(iVar34 + 0x10);
    iVar20 = 4;
    in_r7 = (uint ******)&(*(undefined4 *)((char *)frame_ + 24));
    iVar34 = -1;
    do {
      iVar21 = iVar34;
      if (*(char *)(iVar43 + (int)in_r8) == '\0') {
        iVar21 = iVar43;
        if ((iVar47 != 0) && (iVar21 = iVar34, 0 < iVar47)) {
          *(undefined1 *)(iVar43 + (int)in_r7) = 1;
        }
        iVar47 = iVar47 + 1;
      }
      iVar43 = iVar43 + 1;
      iVar20 = iVar20 + -1;
      iVar34 = iVar21;
    } while (iVar20 != 0);
    if (iVar47 < 2) goto code_r0x001002dc;
    iVar43 = 4;
    ppppppuVar19[0x27] = (uint *****)(*(undefined4 *)((char *)frame_ + 24));
    iVar34 = 0;
    in_r7 = (uint ******)&(*(undefined4 *)((char *)frame_ + 108));
    do {
      *(char *)(iVar34 + (int)in_r7) = (char)iVar21;
      iVar34 = iVar34 + 1;
      iVar43 = iVar43 + -1;
    } while (iVar43 != 0);
    pvVar16 = FUN_001043f0(0x31,*(undefined4 *)(param_1 + 8));
    pppppuVar15 = ppppppuVar19[0x25];
    pppppuVar52 = ppppppuVar19[0x26];
    iVar34 = FUN_001054ec(pvVar16,0);
    *(uint ******)(iVar34 + 0xc) = pppppuVar52;
    *(uint ******)(iVar34 + 8) = pppppuVar15;
    pppppuVar52 = ppppppuVar19[0x25];
    *(uint *******)((int)pvVar16 + 0x9c) = (*(undefined4 *)((char *)frame_ + 140));
    pppppuVar11 = ppppppuVar19[0x26];
    iVar34 = FUN_001054ec(pvVar16,1);
    pppppuVar15 = (*(undefined4 *)((char *)frame_ + 108));
    *(uint ******)(iVar34 + 0xc) = pppppuVar11;
    *(uint ******)(iVar34 + 8) = pppppuVar52;
    iVar34 = FUN_001054ec(pvVar16,1);
    *(uint ******)(iVar34 + 0x10) = pppppuVar15;
  }
  iVar43 = *(int *)(local_14c + 8);
  iVar34 = local_14c;
  while (iVar47 = iVar43, iVar47 != 0) {
    FUN_0019401c(iVar34);
    ((int (*)())FUN_000f92fc)(param_1,iVar34,(*(uint ***** *)((char *)frame_ + 16)));
    iVar34 = iVar47;
    iVar43 = *(int *)(iVar47 + 8);
  }
  ((int (*)())FUN_000f92fc)(param_1,ppppppuVar19,(*(uint ***** *)((char *)frame_ + 16)));
  if (pvVar16 != (void *)0x0) {
    ((int (*)())FUN_000f92fc)(param_1,pvVar16,(*(uint ***** *)((char *)frame_ + 16)));
  }
  iVar43 = *(int *)(local_164 + 8);
  iVar34 = local_164;
  while (iVar47 = iVar43, iVar47 != 0) {
    FUN_0019401c(iVar34);
    ((int (*)())FUN_000f92fc)(param_1,iVar34,(*(uint ***** *)((char *)frame_ + 16)));
    iVar34 = iVar47;
    iVar43 = *(int *)(iVar47 + 8);
  }
  goto switchD_000fdaf0_caseD_2;
switchD_0010061c_caseD_0:
  (*(int *)((char *)frame_ + 212)) = 1;
code_r0x00103b34:
  if (ppppppuVar38 != (uint ******)0x0) {
code_r0x00103b3c:
    iVar43 = (*(code *)(*ppppppuVar38)[5])(ppppppuVar38);
    if ((uint ******)(iVar43 + 1U) == ppppppuVar40) {
      ((int (*)())FUN_000f92fc)(param_1,ppppppuVar38,(*(uint ***** *)((char *)frame_ + 16)));
      ppppppuVar38 = (uint ******)0x0;
      ppppppuVar40 = (uint ******)0x0;
      (*(undefined4 *)((char *)frame_ + 24)) = *(uint *******)((*(undefined * *)((char *)frame_ + 304)) + -0x2c30);
      (*(undefined4 *)((char *)frame_ + 108)) = *(uint ******)((*(undefined * *)((char *)frame_ + 280)) + -0x2bfc);
    }
  }
  if ((*(int *)((char *)frame_ + 212)) != 0) goto code_r0x00103bb0;
  (*(int * *)((char *)frame_ + 20)) = (int *)((int)(*(int * *)((char *)frame_ + 20)) + 1);
  goto code_r0x001005f4;
code_r0x00103bb0:
  iVar43 = *(int *)(local_164 + 8);
  iVar34 = local_164;
  while (iVar47 = iVar43, iVar47 != 0) {
    FUN_0019401c(iVar34);
    ((int (*)())FUN_000f92fc)(param_1,iVar34,(*(uint ***** *)((char *)frame_ + 16)));
    iVar34 = iVar47;
    iVar43 = *(int *)(iVar47 + 8);
  }
  if (puVar12 != (uint *)0x0) {
    FUN_00193cc0(puVar14[4],puVar14[3]);
    FUN_00193cc0(*puVar14,puVar14);
  }
  if (ppppppuVar19 != (uint ******)0x0) {
    FUN_00193cc0(puVar24[4],puVar24[3]);
    FUN_00193cc0(*puVar24,puVar24);
  }
  goto switchD_000fdaf0_caseD_2;
}
#undef local_14c
#undef local_164
