#include "decls.h"

/* FUN_000e15b8 @ 0xe15b8 (36 bytes) */
int FUN_000e15b8(param_1)
  int param_1;
{
  uint uVar1;
  
  uVar1 = *(byte *)(param_1 + 0x5a1) >> 1 & 1;
  *(uint *)(*(int *)(param_1 + 0x370) + 0x28) = uVar1;
  *(uint *)(*(int *)(param_1 + 0x374) + 0x28) = uVar1;
  *(uint *)(*(int *)(param_1 + 0x378) + 0x28) = uVar1;
  return;
}

/* FUN_000e15dc @ 0xe15dc (64 bytes) */
int FUN_000e15dc(param_1)
  int param_1;
{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x6c4) + 0x30);
  if ((uVar1 & 1) != 0) {
    return *(undefined4 *)(param_1 + 0x534);
  }
  if ((uVar1 & 0x2000) != 0) {
    return *(undefined4 *)(param_1 + 0x538);
  }
  if ((uVar1 & 0x4000) != 0) {
    return *(undefined4 *)(param_1 + 0x53c);
  }
  return *(undefined4 *)(param_1 + 0x534);
}

/* FUN_000e161c @ 0xe161c (156 bytes) */
int FUN_000e161c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x47c) != 0) {
    if (param_2 == 5) {
LAB_000e1644:
      *(undefined4 *)(param_1 + 0x318) = 1;
      *(int *)(param_1 + 0x478) = *(int *)(param_1 + 0x480) + -1;
      *(undefined4 *)(param_1 + 0x314) = 0;
      *(undefined4 *)(param_1 + 0x47c) = 0;
      return 1;
    }
    if (param_2 == 4) {
      iVar1 = 0;
      if (*(int *)(param_1 + 0x6bc) != 0) goto LAB_000e1644;
      goto LAB_000e16a4;
    }
  }
  iVar1 = *(int *)(param_1 + 0x6bc);
LAB_000e16a4:
  if ((iVar1 == 0) && (param_2 == 4)) {
    uVar2 = 1;
    *(undefined4 *)(param_1 + 0x318) = 1;
    *(undefined4 *)(param_1 + 0x6b8) = 1;
    *(undefined4 *)(param_1 + 0x314) = 0;
    *(undefined4 *)(param_1 + 0x6bc) = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_000e16b8 @ 0xe16b8 (76 bytes) */
int FUN_000e16b8(param_1)
  int param_1;
{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 0x6c4) + 0x30);
  if ((uVar1 & 0x2000) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x398) + 0x38);
  }
  if ((uVar1 & 1) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x398) + 0x3c);
  }
  if ((uVar1 & 0x4000) == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x398) + 0x40);
}

/* FUN_000e1704 @ 0xe1704 (88 bytes) */
int FUN_000e1704(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = ((int (*)())FUN_000e16b8)(param_1);
  iVar1 = ((int)param_2 >> 5) + (uint)((int)param_2 < 0 && (param_2 & 0x1f) != 0);
  iVar2 = iVar1 * 4 + iVar2;
  *(uint *)(iVar2 + 0xb8) = 1 << (param_2 + iVar1 * -0x20 & 0x3f) | *(uint *)(iVar2 + 0xb8);
  return;
}

/* FUN_000e175c @ 0xe175c (88 bytes) */
int FUN_000e175c(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = ((int (*)())FUN_000e16b8)(param_1);
  iVar1 = ((int)param_2 >> 5) + (uint)((int)param_2 < 0 && (param_2 & 0x1f) != 0);
  iVar2 = iVar1 * 4 + iVar2;
  *(uint *)(iVar2 + 0xd8) = 1 << (param_2 + iVar1 * -0x20 & 0x3f) | *(uint *)(iVar2 + 0xd8);
  return;
}

/* FUN_000e17b4 @ 0xe17b4 (88 bytes) */
int FUN_000e17b4(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = ((int (*)())FUN_000e16b8)(param_1);
  iVar1 = ((int)param_2 >> 5) + (uint)((int)param_2 < 0 && (param_2 & 0x1f) != 0);
  iVar2 = iVar1 * 4 + iVar2;
  *(uint *)(iVar2 + 0x98) = 1 << (param_2 + iVar1 * -0x20 & 0x3f) | *(uint *)(iVar2 + 0x98);
  return;
}

/* FUN_000e180c @ 0xe180c (124 bytes) */
int FUN_000e180c(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  
  iVar2 = param_2 * 4 + param_1;
  if (*(int *)(iVar2 + 0x370) == 0) {
    piVar1 = (int *)FUN_000e1564(param_1,0x2c);
    if (piVar1 != (int *)0x0) {
      piVar1[10] = 0;
      *piVar1 = param_1;
      piVar1[1] = 0;
      piVar1[2] = 0;
      piVar1[3] = 0;
      piVar1[4] = 0;
      piVar1[5] = 0;
      piVar1[6] = 0;
      piVar1[7] = 0;
      piVar1[8] = 0;
      piVar1[9] = 0;
    }
    *(int **)(iVar2 + 0x370) = piVar1;
  }
  return;
}

/* FUN_000e1888 @ 0xe1888 (152 bytes) */
int FUN_000e1888(param_1)
  int param_1;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0x14;
  *(undefined4 *)(param_1 + 0x530) = 0;
  *(undefined4 *)(param_1 + 0x6c0) = 0;
  *(undefined4 *)(param_1 + 0x314) = 0;
  *(undefined4 *)(param_1 + 0x584) = 0;
  iVar2 = param_1;
  do {
    *(undefined4 *)(iVar2 + 0x484) = 0;
    *(undefined4 *)(iVar2 + 0x4d4) = 0;
    *(undefined4 *)(iVar2 + 0x534) = 0;
    iVar2 = iVar2 + 4;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  iVar2 = 0;
  do {
    ((int (*)())FUN_000e180c)(param_1,iVar2);
    bVar1 = iVar2 != 2;
    iVar2 = iVar2 + 1;
  } while (bVar1);
  uVar3 = FUN_00193e18(*(undefined4 *)(param_1 + 0x370),0x2000);
  *(undefined4 *)(param_1 + 0x3a0) = uVar3;
  *(undefined4 *)(param_1 + 0x3a8) = 0;
  *(undefined4 *)(param_1 + 0x3a4) = 0;
  FUN_000e0850(param_1);
  return;
}

/* FUN_000e1920 @ 0xe1920 (232 bytes) */
int FUN_000e1920(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  undefined4 *param_1;
  undefined4 param_2;
  code *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
{
  int iVar1;
  undefined4 *puStack00000018;
  
  param_1[0x162] = 1;
  param_1[0xca] = param_6;
  param_1[0x11e] = 0x400;
  param_1[0xd7] = param_8;
  param_1[0xd8] = param_9;
  param_1[0xd9] = param_10;
  param_1[0xd6] = param_7;
  param_1[0xda] = param_11;
  param_1[0xd3] = param_4;
  *param_1 = param_5;
  param_1[199] = 1;
  param_1[0xd5] = param_2;
  param_1[0xdb] = param_12;
  param_1[1] = (int)(param_1 + 2) + (-(int)(param_1 + 2) & 7U);
  param_1[0xc3] = 0;
  param_1[0xc4] = 0;
  param_1[0x11f] = 0;
  param_1[0x120] = 0;
  param_1[0x1b1] = 0;
  param_1[0xd4] = param_3;
  param_1[200] = 0;
  param_1[0xdc] = 0;
  param_1[0xdd] = 0;
  param_1[0xde] = 0;
  puStack00000018 = param_1;
  iVar1 = (*param_3)(param_2,0x1744);
  *(undefined1 *)(puStack00000018 + 0xfe) = 0;
  if (iVar1 == 0) {
    puStack00000018[0xc5] = 2;
  }
  else {
    FUN_00129130(iVar1,puStack00000018,0);
    puStack00000018[0xc3] = iVar1;
    iVar1 = _setjmp((int *)puStack00000018[1]);
    if (iVar1 == 0) {
      ((int (*)())FUN_000e1888)(puStack00000018);
      FUN_000e13b4(puStack00000018);
    }
  }
  return;
}

/* FUN_000e1a48 @ 0xe1a48 (232 bytes) */
int FUN_000e1a48(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  undefined4 *param_1;
  undefined4 param_2;
  code *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  undefined4 param_9;
  undefined4 param_10;
  undefined4 param_11;
  undefined4 param_12;
{
  int iVar1;
  undefined4 *puStack00000018;
  
  param_1[0x162] = 1;
  param_1[0xca] = param_6;
  param_1[0x11e] = 0x400;
  param_1[0xd7] = param_8;
  param_1[0xd8] = param_9;
  param_1[0xd9] = param_10;
  param_1[0xd6] = param_7;
  param_1[0xda] = param_11;
  param_1[0xd3] = param_4;
  *param_1 = param_5;
  param_1[199] = 1;
  param_1[0xd5] = param_2;
  param_1[0xdb] = param_12;
  param_1[1] = (int)(param_1 + 2) + (-(int)(param_1 + 2) & 7U);
  param_1[0xc3] = 0;
  param_1[0xc4] = 0;
  param_1[0x11f] = 0;
  param_1[0x120] = 0;
  param_1[0x1b1] = 0;
  param_1[0xd4] = param_3;
  param_1[200] = 0;
  param_1[0xdc] = 0;
  param_1[0xdd] = 0;
  param_1[0xde] = 0;
  puStack00000018 = param_1;
  iVar1 = (*param_3)(param_2,0x1744);
  *(undefined1 *)(puStack00000018 + 0xfe) = 0;
  if (iVar1 == 0) {
    puStack00000018[0xc5] = 2;
  }
  else {
    FUN_00129130(iVar1,puStack00000018,0);
    puStack00000018[0xc3] = iVar1;
    iVar1 = _setjmp((int *)puStack00000018[1]);
    if (iVar1 == 0) {
      ((int (*)())FUN_000e1888)(puStack00000018);
      FUN_000e13b4(puStack00000018);
    }
  }
  return;
}

/* FUN_000e1b70 @ 0xe1b70 (172 bytes) */
int FUN_000e1b70(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x30c) != 0) {
    (**(code **)(param_1 + 0x34c))(*(undefined4 *)(param_1 + 0x354),*(int *)(param_1 + 0x30c));
    *(undefined4 *)(param_1 + 0x30c) = 0;
  }
  if (0 < param_2) {
    if (param_2 < 4) {
      iVar1 = FUN_000e1564(param_1,0x10);
      if (iVar1 != 0) {
        FUN_0010e114(iVar1,param_1);
      }
      *(int *)(param_1 + 0x310) = iVar1;
      if (param_2 == 2) {
        FUN_0010dd54(*(undefined4 *)(iVar1 + 4));
        *(undefined4 *)(FUN_00001740 + *(int *)(*(int *)(param_1 + 0x310) + 8)) = 2;
      }
    }
    else if (param_2 == 4) {
      iVar1 = FUN_000e1564(param_1,0x10);
      if (iVar1 != 0) {
        FUN_0010e1d8(iVar1,param_1);
      }
      *(int *)(param_1 + 0x310) = iVar1;
    }
  }
  return;
}

/* FUN_000e1c50 @ 0xe1c50 (916 bytes) */
int FUN_000e1c50(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  
  if (((*(uint *)(param_1 + 0x30) & 1) == 0) && ((*(uint *)(param_1 + 0x30) & 0x2000) != 0)) {
    uVar6 = *(undefined4 *)(param_1 + 8);
    iVar1 = *(int *)(param_1 + 900);
    for (iVar4 = *(int *)(*(int *)(param_1 + 900) + 8); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
      piVar2 = (int *)(*(int **)(iVar1 + 0x98))[2];
      piVar9 = *(int **)(iVar1 + 0x98);
      if (piVar2 != (int *)0x0) {
        do {
          piVar3 = piVar2;
          if ((piVar9[5] & 1U) != 0) {
            if (*(int *)(piVar9[0x22] + 8) == 0x13) {
              piVar2 = (int *)FUN_00105594(piVar9,1);
              piVar3 = (int *)FUN_00105594(piVar9,2);
              iVar4 = (**(code **)(*piVar2 + 0x4c))(piVar2);
              if (((iVar4 != 0) && (iVar4 = (**(code **)(*piVar3 + 0x48))(piVar3), iVar4 != 0)) ||
                 ((iVar4 = (**(code **)(*piVar3 + 0x4c))(piVar3), iVar4 != 0 &&
                  (iVar4 = (**(code **)(*piVar2 + 0x48))(piVar2), iVar4 != 0)))) {
                iVar4 = (**(code **)(*piVar2 + 0x4c))(piVar2);
                if (iVar4 == 0) {
                  piVar2 = piVar3;
                }
                puVar12 = (uint *)piVar9[4];
                uVar7 = puVar12[1];
                uVar10 = uVar7 - 1;
                if (-1 < (int)uVar10) {
                  iVar4 = uVar10 * 4;
                  uVar8 = 0;
                  do {
                    if (uVar10 < *puVar12) {
                      uVar5 = puVar12[1];
                      if (uVar5 <= uVar10) {
                        _memset(uVar5 * 4 + puVar12[2],0,(uVar10 - uVar5) * 4 + 4);
                        puVar12[1] = uVar10 + 1;
                      }
                      piVar3 = (int *)(iVar4 + puVar12[2]);
                    }
                    else {
                      piVar3 = (int *)FUN_0019423c(puVar12,uVar10);
                    }
                    iVar13 = *piVar3;
                    if (0 < *(int *)(iVar13 + 0x84)) {
                      iVar11 = 1;
                      do {
                        piVar3 = (int *)FUN_00105594(iVar13,iVar11);
                        if (piVar9 == piVar3) {
                          FUN_00106004(iVar13,iVar11,piVar2,1,uVar6);
                          break;
                        }
                        iVar11 = iVar11 + 1;
                      } while (iVar11 <= *(int *)(iVar13 + 0x84));
                    }
                    uVar8 = uVar8 + 1;
                    uVar10 = uVar10 - 1;
                    iVar4 = iVar4 + -4;
                    if (uVar7 == uVar8) break;
                    puVar12 = (uint *)piVar9[4];
                  } while( true );
                }
              }
            }
            iVar4 = (**(code **)(*piVar9 + 100))(piVar9);
            if ((iVar4 != 0) && ((piVar9[0x49] != 0 || (piVar9[0x48] != 0)))) {
              piVar2 = (int *)FUN_00105594(piVar9,1);
              iVar4 = (**(code **)(*piVar2 + 0x4c))();
              if (iVar4 != 0) {
                puVar12 = (uint *)piVar9[4];
                uVar7 = puVar12[1];
                uVar10 = uVar7 - 1;
                if (-1 < (int)uVar10) {
                  iVar4 = uVar10 * 4;
                  uVar8 = 0;
                  do {
                    if (uVar10 < *puVar12) {
                      uVar5 = puVar12[1];
                      if (uVar5 <= uVar10) {
                        _memset(uVar5 * 4 + puVar12[2],0,(uVar10 - uVar5) * 4 + 4);
                        puVar12[1] = uVar10 + 1;
                      }
                      piVar3 = (int *)(iVar4 + puVar12[2]);
                    }
                    else {
                      piVar3 = (int *)FUN_0019423c(puVar12,uVar10);
                    }
                    iVar13 = *piVar3;
                    if (0 < *(int *)(iVar13 + 0x84)) {
                      iVar11 = 1;
                      do {
                        piVar3 = (int *)FUN_00105594(iVar13,iVar11);
                        if (piVar9 == piVar3) {
                          FUN_00106004(iVar13,iVar11,piVar2,1,uVar6);
                          break;
                        }
                        iVar11 = iVar11 + 1;
                      } while (iVar11 <= *(int *)(iVar13 + 0x84));
                    }
                    uVar8 = uVar8 + 1;
                    uVar10 = uVar10 - 1;
                    iVar4 = iVar4 + -4;
                    if (uVar8 == uVar7) break;
                    puVar12 = (uint *)piVar9[4];
                  } while( true );
                }
              }
            }
            piVar3 = (int *)piVar9[2];
          }
          piVar2 = (int *)piVar3[2];
          piVar9 = piVar3;
        } while ((int *)piVar3[2] != (int *)0x0);
        iVar4 = *(int *)(iVar1 + 8);
      }
      iVar1 = iVar4;
    }
  }
  return;
}

/* FUN_000e1fe4 @ 0xe1fe4 (160 bytes) */
int FUN_000e1fe4(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if ((param_2 != 0) && (*(int *)(param_1 + 0x310) != 0)) {
    FUN_0010defc(*(int *)(param_1 + 0x310),param_1);
    (**(code **)(param_1 + 0x34c))
              (*(undefined4 *)(param_1 + 0x354),*(undefined4 *)(param_1 + 0x310));
  }
  iVar1 = param_1;
  do {
    if (*(int *)(iVar1 + 0x370) != 0) {
      FUN_00193d18(*(int *)(iVar1 + 0x370));
      (**(code **)(param_1 + 0x34c))
                (*(undefined4 *)(param_1 + 0x354),*(undefined4 *)(iVar1 + 0x370));
      *(undefined4 *)(iVar1 + 0x370) = 0;
    }
    iVar1 = iVar1 + 4;
  } while (iVar1 != param_1 + 0xc);
  return;
}

/* FUN_000e2094 @ 0xe2094 (292 bytes) */
int FUN_000e2094(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined8 uVar8;
  
  ((int (*)())FUN_000e15b8)(param_1);
  *(char **)(param_1 + 0x5a8) = "INITIAL_INPUT";
  *(char **)(param_1 + 0x5bc) = "BUILD_SSA";
  *(char **)(param_1 + 0x5d0) = "REDUCE_DEP";
  *(char **)(param_1 + 0x5e4) = "PEEPHOLE";
  *(char **)(param_1 + 0x5f8) = "SCHED";
  *(char **)(param_1 + 0x60c) = "REPLACE_PHI";
  pcVar4 = "ASSEMBLY";
  *(char **)(param_1 + 0x620) = "GLOBAL_ALLOC";
  *(char **)(param_1 + 0x634) = "ASSEMBLY";
  FUN_00115fa0(param_1);
  iVar1 = *(int *)(param_2 + 8) + -1;
  *(int *)(param_1 + 0x52c) = iVar1;
  while (-1 < iVar1) {
    FUN_000e13b4(param_1);
    iVar1 = *(int *)(param_1 + 0x52c);
    if (iVar1 < 2) {
      uVar5 = *(undefined4 *)(iVar1 * 4 + param_2 + 0xc);
    }
    else {
      pcVar4 = *(char **)(param_2 + 0x14);
      uVar5 = *(undefined4 *)(pcVar4 + iVar1 * 4);
    }
    uVar6 = *(undefined4 *)(param_1 + 0x374);
    puVar3 = (undefined4 *)FUN_00193e18(uVar6,0x484);
    *puVar3 = uVar6;
    FUN_000ee29c(puVar3 + 1,param_1);
    uVar6 = *(undefined4 *)(param_1 + 0x378);
    *(undefined4 **)(param_1 + 0x6c4) = puVar3 + 1;
    puVar3 = (undefined4 *)FUN_00193e18(uVar6,0x290);
    puVar7 = puVar3 + 1;
    *puVar3 = uVar6;
    iVar1 = param_1;
    FUN_000e5570(puVar7,uVar5,param_1);
    if ((*(uint *)(param_2 + 4) & 0x20) != 0) {
      iVar2 = *(int *)(param_1 + 0x52c) + 1;
      if (iVar2 < 2) {
        uVar5 = *(undefined4 *)(iVar2 * 4 + param_2 + 0xc);
      }
      else {
        pcVar4 = *(char **)(param_2 + 0x14);
        uVar5 = *(undefined4 *)(pcVar4 + iVar2 * 4);
      }
      ((int (*)())FUN_000e4400)(puVar7,uVar5);
    }
    (**(code **)(**(int **)(param_1 + 0x30c) + 0x60))();
    FUN_000ef498(*(undefined4 *)(param_1 + 0x6c4),puVar7);
    if (puVar7 != (undefined4 *)0x0) {
      ((int (*)())FUN_000e4934)(puVar7);
      FUN_00193cc0(*puVar3,puVar3);
    }
    FUN_00193d18(*(undefined4 *)(param_1 + 0x378));
    FUN_00122de8(*(undefined4 *)(param_1 + 0x6c4));
    FUN_00193d18(*(undefined4 *)(param_1 + 0x378));
    iVar2 = FUN_000e07dc(param_1,0xf);
    if (iVar2 != 0) {
      FUN_0013d3b8(*(undefined4 *)(param_1 + 0x6c4));
      FUN_0013da3c(*(undefined4 *)(param_1 + 0x6c4));
    }
    iVar2 = FUN_000e07dc(param_1,0x34);
    if (iVar2 != 0) {
      FUN_0013a8a4(*(undefined4 *)(param_1 + 0x6c4));
    }
    iVar2 = FUN_000e07dc(param_1,0x35);
    if (iVar2 != 0) {
      FUN_0013fc38(*(undefined4 *)(param_1 + 0x6c4));
    }
    uVar8 = FUN_000e07dc(param_1,0x10);
    if ((int)((ulonglong)uVar8 >> 0x20) != 0) {
      ((int (*)())FUN_000e1c50)(*(undefined4 *)(param_1 + 0x6c4),(int)uVar8,iVar1,in_r6,in_r7,in_r8,pcVar4);
    }
    *(uint *)(*(int *)(param_1 + 0x6c4) + 0x30) = *(uint *)(*(int *)(param_1 + 0x6c4) + 0x30) | 0x80
    ;
    iVar1 = FUN_000e07dc(param_1,0x11);
    if (iVar1 != 0) {
      FUN_0013bd68(*(undefined4 *)(param_1 + 0x6c4),0);
    }
    iVar1 = FUN_000e07dc(param_1,0x1a);
    if (iVar1 == 0) {
      *(uint *)(*(int *)(param_1 + 0x6c4) + 0x30) =
           *(uint *)(*(int *)(param_1 + 0x6c4) + 0x30) & 0xffffff7f;
    }
    else {
      FUN_0013d160(*(undefined4 *)(param_1 + 0x6c4));
    }
    iVar1 = FUN_000e07dc(param_1,0x20);
    if (iVar1 != 0) {
      FUN_001300b0(*(undefined4 *)(param_1 + 0x6c4));
    }
    iVar1 = FUN_000e07dc(param_1,0x12);
    if (iVar1 != 0) {
      FUN_0013da3c(*(undefined4 *)(param_1 + 0x6c4));
      *(uint *)(*(int *)(param_1 + 0x6c4) + 0x30) =
           *(uint *)(*(int *)(param_1 + 0x6c4) + 0x30) | 0x80;
      iVar1 = FUN_000e07dc(param_1,0x11);
      if (iVar1 != 0) {
        FUN_0013bd68(*(undefined4 *)(param_1 + 0x6c4),0);
      }
      FUN_0014657c(*(undefined4 *)(param_1 + 0x6c4));
      *(uint *)(*(int *)(param_1 + 0x6c4) + 0x30) =
           *(uint *)(*(int *)(param_1 + 0x6c4) + 0x30) & 0xffffff7f;
    }
    iVar1 = FUN_000e07dc(param_1,0x22);
    if (iVar1 != 0) {
      FUN_00139d40(*(undefined4 *)(param_1 + 0x6c4));
    }
    FUN_000f29f4(*(undefined4 *)(param_1 + 0x6c4));
    FUN_00193d18(*(undefined4 *)(param_1 + 0x378));
    FUN_00171e68(*(undefined4 *)(param_1 + 0x6c4));
    FUN_00193d18(*(undefined4 *)(param_1 + 0x378));
    FUN_00120cd4(*(undefined4 *)(param_1 + 0x6c4));
    FUN_00193d18(*(undefined4 *)(param_1 + 0x378));
    FUN_00134658(*(undefined4 *)(param_1 + 0x6c4));
    FUN_00193d18(*(undefined4 *)(param_1 + 0x378));
    FUN_000f60c4(*(undefined4 *)(param_1 + 0x6c4),param_1);
    *(uint *)(*(int *)(param_1 + 0x6c4) + 0x30) =
         *(uint *)(*(int *)(param_1 + 0x6c4) + 0x30) | 0x10000;
    FUN_0012ab80(*(undefined4 *)(param_1 + 0x6c4));
    ((int (*)())FUN_000e36bc)(*(undefined4 *)(param_1 + 0x6c4),*(int *)(param_1 + 0x52c) * 4 + param_1 + 0x484,
                 *(int *)(param_1 + 0x52c));
    FUN_00193d18(*(undefined4 *)(param_1 + 0x378));
    FUN_0013061c(*(undefined4 *)(param_1 + 0x6c4),0);
    (**(code **)(**(int **)(param_1 + 0x30c) + 0x38))
              (*(int **)(param_1 + 0x30c),*(undefined4 *)(param_1 + 0x52c),param_1);
    pcVar4 = (char *)**(undefined4 **)(param_1 + 0x30c);
    iVar1 = *(int *)(param_1 + 0x52c) * 4 + param_1;
    in_r6 = param_1;
    (**(code **)(pcVar4 + 0x8c))
              (*(undefined4 **)(param_1 + 0x30c),*(undefined4 *)(iVar1 + 0x524),
               *(undefined4 *)(iVar1 + 0x4d4));
    iVar1 = *(int *)(param_1 + 0x6c4);
    if (iVar1 != 0) {
      FUN_000ecfac(iVar1);
      FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
    }
    FUN_00193d18(*(undefined4 *)(param_1 + 0x374));
    FUN_00193d18(*(undefined4 *)(param_1 + 0x378));
    iVar1 = *(int *)(param_1 + 0x52c) + -1;
    *(int *)(param_1 + 0x52c) = iVar1;
  }
  return;
}

/* FUN_000e2524 @ 0xe2524 (324 bytes) */
int FUN_000e2524(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int iVar1;
  int iVar2;
  int iStack00000018;
  int iStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  
  *(undefined4 *)(param_1 + 0x398) = param_5;
  iStack00000018 = param_1;
  iStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  FUN_000e0ca8(param_1);
  do {
    iVar1 = _setjmp(*(undefined4 *)(iStack00000018 + 4));
    if (iVar1 == 0) {
      ((int (*)())FUN_000e1888)(iStack00000018);
      FUN_000e0cd0(iStack00000018,uStack00000024);
      iVar1 = FUN_00193c00(uStack00000020,iStack00000018);
      *(int *)(iStack00000018 + 0x524) = iStack0000001c;
      if ((*(uint *)(iVar1 + 4) & 4) == 0) {
        if ((*(uint *)(iVar1 + 4) & 2) == 0) {
          *(undefined4 *)(iStack0000001c + 0xf8) = 2;
        }
        else {
          *(undefined4 *)(iStack0000001c + 0xf8) = 0;
        }
      }
      else {
        *(undefined4 *)(iStack0000001c + 0xf8) = 1;
      }
      *(undefined4 *)(iStack0000001c + 0xfc) =
           *(undefined4 *)(*(int *)(iStack00000018 + 0x398) + 0x28);
      ((int (*)())FUN_000e2094)(iStack00000018,iVar1);
      if (iVar1 != 0) {
        FUN_00193be8(iVar1);
        FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
      }
    }
    *(undefined4 *)(iStack00000018 + 0x4d8) = 0;
    *(undefined4 *)(iStack00000018 + 0x484) = 0;
    *(undefined4 *)(iStack00000018 + 0x4d4) = 0;
    *(undefined4 *)(iStack00000018 + 0x488) = 0;
    iVar1 = *(int *)(iStack00000018 + 0x314);
    FUN_000e0e28(iStack00000018);
    ((int (*)())FUN_000e1fe4)(iStack00000018,0);
  } while ((iVar1 != 0) && (iVar2 = ((int (*)())FUN_000e161c)(iStack00000018,iVar1), iVar2 != 0));
  return iVar1;
}

/* FUN_000e2668 @ 0xe2668 (280 bytes) */
int FUN_000e2668(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int iVar1;
  int iVar2;
  int iStack00000018;
  int iStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  
  *(undefined4 *)(param_1 + 0x398) = param_7;
  iStack00000018 = param_1;
  iStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  FUN_000e0ca8(param_1);
  do {
    iVar1 = _setjmp(*(undefined4 *)(iStack00000018 + 4));
    if (iVar1 == 0) {
      ((int (*)())FUN_000e1888)(iStack00000018);
      FUN_000e0cd0(iStack00000018,uStack00000028);
      iVar1 = FUN_00193b3c(uStack00000020,uStack00000024,iStack00000018);
      *(int *)(iStack00000018 + 0x524) = iStack0000001c;
      *(undefined4 *)(iStack0000001c + 0xf8) = 0;
      *(undefined4 *)(iStack0000001c + 0xfc) =
           *(undefined4 *)(*(int *)(iStack00000018 + 0x398) + 0x28);
      ((int (*)())FUN_000e2094)(iStack00000018,iVar1);
      if (iVar1 != 0) {
        FUN_00193be8(iVar1);
        FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
      }
    }
    *(undefined4 *)(iStack00000018 + 0x4d8) = 0;
    *(undefined4 *)(iStack00000018 + 0x484) = 0;
    *(undefined4 *)(iStack00000018 + 0x4d4) = 0;
    *(undefined4 *)(iStack00000018 + 0x488) = 0;
    iVar1 = *(int *)(iStack00000018 + 0x314);
    FUN_000e0e28(iStack00000018);
    ((int (*)())FUN_000e1fe4)(iStack00000018,0);
  } while ((iVar1 != 0) && (iVar2 = ((int (*)())FUN_000e161c)(iStack00000018,iVar1), iVar2 != 0));
  return iVar1;
}

/* FUN_000e2780 @ 0xe2780 (140 bytes) */
int FUN_000e2780(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  param_1[0xa4] = param_1[0xa4] + *(int *)(param_2 + 4);
  param_1[0xa5] = param_1[0xa5] + *(int *)(param_2 + 8);
  param_1[0xa6] = param_1[0xa6] + *(int *)(param_2 + 0xc);
  param_1[0xa7] = param_1[0xa7] + *(int *)(param_2 + 0x10);
  param_1[0xa8] = param_1[0xa8] + *(int *)(param_2 + 0x14);
  param_1[0xa9] = param_1[0xa9] + *(int *)(param_2 + 0x18);
  param_1[0xaa] = param_1[0xaa] + *(int *)(param_2 + 0x1c);
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x1c))(*(int **)(param_2 + 0x20),*param_1);
  return;
}

/* FUN_000e280c @ 0xe280c (44 bytes) */
int FUN_000e280c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x6c))
            (*(int **)(param_2 + 0x20),param_1,param_1 + 0x90,param_3,param_2,
             *(undefined4 *)(param_1 + 0xa8));
  return;
}

/* FUN_000e2838 @ 0xe2838 (20 bytes) */
int FUN_000e2838(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  uint param_3;
{
                    
                    
  (**(code **)(**(int **)(param_1 + 0x20) + 0x30))(*(int **)(param_1 + 0x20),param_2,param_3);
  return;
}

/* FUN_000e284c @ 0xe284c (20 bytes) */
int FUN_000e284c(param_1)
  int param_1;
{
  undefined4 uVar1;
  
                    
                    
  uVar1 = (**(code **)(**(int **)(param_1 + 0x20) + 8))();
  return uVar1;
}

/* FUN_000e2860 @ 0xe2860 (36 bytes) */
int FUN_000e2860(param_1, param_2)
  int param_1;
  int param_2;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x34))
            (*(int **)(param_2 + 0x20),param_1 + 0x90,*(undefined4 *)(param_1 + 0xdc));
  return;
}

/* FUN_000e28f0 @ 0xe28f0 (96 bytes) */
int FUN_000e28f0(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0xdc);
  (**(code **)(**(int **)(param_2 + 0x20) + 0x74))(*(int **)(param_2 + 0x20));
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x34))(*(int **)(param_2 + 0x20),param_1 + 0x90,uVar1);
  return;
}

/* FUN_000e2a04 @ 0xe2a04 (64 bytes) */
int FUN_000e2a04(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (iVar1 < 0) {
    iVar1 = FUN_00130690(*(undefined4 *)(param_1 + 0x34),param_2);
    *(int *)(param_1 + 0x30) = iVar1;
  }
  return iVar1;
}

/* FUN_000e2a44 @ 0xe2a44 (16 bytes) */
int FUN_000e2a44(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  iVar1 = param_1 - param_2;
  if (-1 < iVar1) {
    return iVar1;
  }
  return iVar1 + param_3;
}

/* FUN_000e2a54 @ 0xe2a54 (28 bytes) */
int FUN_000e2a54(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
                    
                    
  (**(code **)(*param_2 + 0xac))(param_2,param_1);
  return;
}

/* FUN_000e2a70 @ 0xe2a70 (28 bytes) */
int FUN_000e2a70(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
                    
                    
  (**(code **)(*param_2 + 0xb0))(param_2,param_1);
  return;
}

/* FUN_000e2a8c @ 0xe2a8c (28 bytes) */
int FUN_000e2a8c(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
                    
                    
  (**(code **)(*param_2 + 0xb4))(param_2,param_1);
  return;
}

/* FUN_000e2aa8 @ 0xe2aa8 (28 bytes) */
int FUN_000e2aa8(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
                    
                    
  (**(code **)(*param_2 + 0xb8))(param_2,param_1);
  return;
}

/* FUN_000e2acc @ 0xe2acc (156 bytes) */
int FUN_000e2acc(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 1;
  while( true ) {
    iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
    if (iVar2 < iVar3) {
      return 0;
    }
    iVar2 = FUN_00105594(param_1,iVar3);
    iVar1 = thunk_FUN_00134de8(*(undefined4 *)(param_3 + 0x6c4),iVar2);
    if ((iVar1 == param_2) && (iVar2 = FUN_00126708(*(undefined4 *)(iVar2 + 0x98)), iVar2 == 0))
    break;
    iVar3 = iVar3 + 1;
  }
  return 1;
}

/* FUN_000e2b68 @ 0xe2b68 (140 bytes) */
int FUN_000e2b68(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int *piVar1;
  int iVar2;
  undefined4 local_18 [2];
  
  piVar1 = (int *)FUN_00105594(param_1,param_2);
  iVar2 = (**(code **)(*piVar1 + 0x48))();
  if ((iVar2 != 0) && (piVar1[0x26] == 0xc)) {
    iVar2 = FUN_001054ec(param_1,param_2);
    FUN_000f2bdc(local_18,piVar1[0x55],*(undefined4 *)(iVar2 + 0x10));
    iVar2 = FUN_001054ec(param_1,param_2);
    *(undefined4 *)(iVar2 + 0x10) = local_18[0];
  }
  return;
}

/* FUN_000e2bf4 @ 0xe2bf4 (132 bytes) */
int FUN_000e2bf4(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int *piVar1;
  int *piVar2;
  
  piVar1 = *(int **)(param_1 + 8);
  for (piVar2 = (int *)(*(int **)(param_1 + 8))[2]; piVar2 != (int *)0x0; piVar2 = (int *)piVar2[2])
  {
    if (((piVar1[5] & 1U) != 0) && (*(int *)(piVar1[0x22] + 8) != 0x57)) {
      (**(code **)(*piVar1 + 0x84))(piVar1,param_2);
      piVar2 = (int *)piVar1[2];
    }
    piVar1 = piVar2;
  }
  return;
}

/* FUN_000e2c78 @ 0xe2c78 (620 bytes) */
int FUN_000e2c78(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  bool bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  float fVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iVar16;
  
  iVar3 = *(int *)(param_1 + 0x98);
  if (iVar3 == 3) {
    uVar7 = 0;
    iVar3 = param_1;
    do {
      if (((int)*(char *)(param_1 + 0x15c) >> (uVar7 & 0x3f) & 1U) != 0) {
        iVar16 = *(int *)(iVar3 + 0x20);
        uVar12 = *(undefined4 *)(param_1 + 0x94);
        uVar15 = *(undefined4 *)(param_3 + 0x398);
        uVar5 = ((int (*)())FUN_000e16b8)(param_3);
        FUN_000d9d74(uVar15,uVar12,(uint)(iVar16 == 1),uVar7,uVar5,0);
      }
      bVar1 = uVar7 != 3;
      iVar3 = iVar3 + 0x18;
      uVar7 = uVar7 + 1;
    } while (bVar1);
    return;
  }
  if (iVar3 < 4) {
    if (iVar3 != 2) {
      return;
    }
  }
  else {
    if (iVar3 == 4) {
      uVar7 = 0;
      iVar3 = param_1;
      iVar16 = param_1;
      do {
        if (((int)*(char *)(param_1 + 0x15c) >> (uVar7 & 0x3f) & 1U) != 0) {
          iVar4 = *(int *)(iVar16 + 0x1c);
          if (iVar4 == 3) {
            uVar15 = *(undefined4 *)(param_1 + 0x94);
            uVar12 = *(undefined4 *)(iVar16 + 0x20);
            uVar8 = *(undefined4 *)(param_3 + 0x398);
            uVar5 = ((int (*)())FUN_000e16b8)(param_3);
            FUN_000d9c90(uVar8,uVar15,uVar12,uVar7,uVar5,0);
          }
          else {
            uVar13 = *(undefined4 *)(iVar3 + 0x94);
            uVar10 = *(undefined4 *)(iVar16 + 0x20);
            uVar8 = *(undefined4 *)(iVar16 + 0x24);
            uVar15 = *(undefined4 *)(iVar16 + 0x28);
            uVar12 = *(undefined4 *)(iVar16 + 0x2c);
            uVar14 = *(undefined4 *)(param_3 + 0x398);
            uVar11 = *(undefined4 *)(iVar16 + 0x30);
            uVar5 = ((int (*)())FUN_000e16b8)(param_3);
            FUN_000d9e98(uVar14,uVar13,uVar7,iVar4,uVar10,uVar8,uVar15,uVar12,uVar11,uVar5);
          }
        }
        bVar1 = uVar7 != 3;
        iVar3 = iVar3 + 0x18;
        iVar16 = iVar16 + 0x18;
        uVar7 = uVar7 + 1;
      } while (bVar1);
      return;
    }
    if (iVar3 != 0xc) {
      return;
    }
  }
  iVar4 = *(int *)(param_1 + 0x98);
  uVar7 = 0;
  iVar9 = param_1 + 0x1c;
  iVar3 = param_3;
  iVar16 = param_1;
  do {
    if (((int)*(char *)(param_1 + 0x15c) >> (uVar7 & 0x3f) & 1U) != 0) {
      if (*(int *)(iVar16 + 0x1c) == 1) {
        uVar12 = *(undefined4 *)(param_1 + 0x94);
        sVar2 = *(short *)(iVar16 + 0x22);
        uVar15 = *(undefined4 *)(param_3 + 0x398);
        iVar3 = (int)*(short *)(iVar16 + 0x20);
        uVar5 = ((int (*)())FUN_000e16b8)(param_3);
        FUN_000d9e58(uVar15,uVar12,iVar3,(int)sVar2,uVar7,uVar5);
      }
      else {
        fVar6 = (float)(**(code **)(*param_2 + 0x8c))(param_2,iVar9);
        uVar12 = *(undefined4 *)(param_1 + 0x94);
        uVar15 = *(undefined4 *)(param_3 + 0x398);
        uVar5 = ((int (*)())FUN_000e16b8)(param_3);
        ((undefined4 (*)())FUN_000d9bac)(uVar15,uVar12,iVar3,uVar7,uVar5,(uint)(iVar4 == 0xc),(double)fVar6);
      }
    }
    bVar1 = uVar7 != 3;
    iVar9 = iVar9 + 0x18;
    iVar16 = iVar16 + 0x18;
    uVar7 = uVar7 + 1;
  } while (bVar1);
  return;
}

/* FUN_000e2ee4 @ 0xe2ee4 (32 bytes) */
int FUN_000e2ee4(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
                    
                    
  (**(code **)(*(int *)param_1[8] + 0x94))((int *)param_1[8],param_2,param_2 + 0x90,*param_1);
  return;
}

/* FUN_000e2f04 @ 0xe2f04 (136 bytes) */
int FUN_000e2f04(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  int *piVar1;
  
  piVar1 = (int *)FUN_001043f0(0x31,param_5);
  piVar1[0x25] = param_2;
  piVar1[0x26] = param_3;
  FUN_00106004(piVar1,1,param_4,0,param_5);
  *(int *)(param_1 + 0x94) = param_2;
  *(int *)(param_1 + 0x98) = param_3;
  (**(code **)(*piVar1 + 0x84))(piVar1,*(undefined4 *)(param_1 + 0x11c));
  return piVar1;
}

/* FUN_000e2f8c @ 0xe2f8c (76 bytes) */
int FUN_000e2f8c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_00105594(param_1,*(undefined4 *)(param_1 + 0x84));
  iVar2 = thunk_FUN_00134de8(*(undefined4 *)(param_3 + 0x6c4),uVar1);
  return iVar2 == param_2;
}

/* FUN_000e2fd8 @ 0xe2fd8 (360 bytes) */
int FUN_000e2fd8(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_2 + 0x98);
  if ((iVar2 == 2) || (iVar2 == 0xc)) {
    iVar2 = 0;
    uVar3 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),param_2);
    do {
      iVar4 = FUN_001054ec(param_2,0);
      if (*(char *)(iVar2 + iVar4 + 0x10) != '\x01') {
        ((int (*)())FUN_000e17b4)(*(undefined4 *)(param_1 + 0xc),uVar3);
      }
      bVar1 = iVar2 != 3;
      iVar2 = iVar2 + 1;
    } while (bVar1);
  }
  else if (iVar2 == 4) {
    iVar2 = 0;
    uVar3 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),param_2);
    do {
      iVar4 = FUN_001054ec(param_2,0);
      if (*(char *)(iVar2 + iVar4 + 0x10) != '\x01') {
        ((int (*)())FUN_000e175c)(*(undefined4 *)(param_1 + 0xc),uVar3);
      }
      bVar1 = iVar2 != 3;
      iVar2 = iVar2 + 1;
    } while (bVar1);
  }
  else if (iVar2 == 3) {
    iVar2 = 0;
    uVar3 = thunk_FUN_00134de8(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x6c4),param_2);
    do {
      iVar4 = FUN_001054ec(param_2,0);
      if (*(char *)(iVar2 + iVar4 + 0x10) != '\x01') {
        ((int (*)())FUN_000e1704)(*(undefined4 *)(param_1 + 0xc),uVar3);
      }
      bVar1 = iVar2 != 3;
      iVar2 = iVar2 + 1;
    } while (bVar1);
  }
  return;
}

/* FUN_000e3140 @ 0xe3140 (260 bytes) */
int FUN_000e3140(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint *puVar7;
  
  iVar2 = FUN_000e7804(param_2,param_2,param_3,param_4,param_5,param_6,param_7);
  uVar5 = *(undefined4 *)(param_4 + 0x6c4);
  iVar1 = *(int *)(iVar2 + 300);
  uVar3 = FUN_00105594(iVar2,1);
  uVar3 = thunk_FUN_00134de8(uVar5,uVar3);
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  uVar3 = (**(code **)(*param_1 + 0x98))(param_1,iVar1 != 1,uVar3,0);
  puVar7 = *(uint **)(param_1[4] + 0x24);
  uVar6 = puVar7[1];
  if (uVar6 < *puVar7) {
    _memset(uVar6 * 4 + puVar7[2],0,4);
    puVar4 = (undefined4 *)(uVar6 * 4 + puVar7[2]);
    puVar7[1] = uVar6 + 1;
  }
  else {
    puVar4 = (undefined4 *)FUN_0019423c(puVar7,uVar6);
  }
  *puVar4 = uVar3;
  return;
}

/* FUN_000e3244 @ 0xe3244 (196 bytes) */
int FUN_000e3244(param_1)
  int param_1;
{
  int iVar1;
  
  if (*(int **)(param_1 + 0x20) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x20) + 4))();
  }
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x2c);
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
    return;
  }
  return;
}

/* FUN_000e3308 @ 0xe3308 (196 bytes) */
int FUN_000e3308(param_1)
  int param_1;
{
  int iVar1;
  
  if (*(int **)(param_1 + 0x20) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 0x20) + 4))();
  }
  iVar1 = *(int *)(param_1 + 0x28);
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x2c);
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = *(int *)(param_1 + 0x24);
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
    return;
  }
  return;
}

/* FUN_000e33cc @ 0xe33cc (340 bytes) */
int FUN_000e33cc(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(param_2 + 8);
  param_1[0xd] = param_2;
  param_1[0xc] = -1;
  *param_1 = iVar1;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  uVar4 = *(undefined4 *)(iVar1 + 0x378);
  puVar2 = (undefined4 *)FUN_00193e18(uVar4,0x14);
  *puVar2 = uVar4;
  puVar2[1] = 2;
  puVar2[4] = uVar4;
  puVar2[2] = 0;
  uVar4 = FUN_00193e18(uVar4,8);
  puVar2[3] = uVar4;
  param_1[10] = (int)(puVar2 + 1);
  uVar4 = *(undefined4 *)(*param_1 + 0x378);
  puVar2 = (undefined4 *)FUN_00193e18(uVar4,0x14);
  *puVar2 = uVar4;
  puVar2[1] = 2;
  puVar2[4] = uVar4;
  puVar2[2] = 0;
  uVar4 = FUN_00193e18(uVar4,8);
  puVar2[3] = uVar4;
  param_1[0xb] = (int)(puVar2 + 1);
  uVar4 = *(undefined4 *)(*param_1 + 0x378);
  puVar2 = (undefined4 *)FUN_00193e18(uVar4,0x14);
  *puVar2 = uVar4;
  puVar2[1] = 2;
  puVar2[2] = 0;
  puVar2[4] = uVar4;
  uVar4 = FUN_00193e18(uVar4,8);
  puVar2[3] = uVar4;
  param_1[9] = (int)(puVar2 + 1);
  piVar3 = (int *)(**(code **)(**(int **)(*param_1 + 0x30c) + 0x68))();
  param_1[8] = (int)piVar3;
                    
                    
  (**(code **)(*piVar3 + 0x14))(piVar3,param_1,param_3,*param_1);
  return;
}

/* FUN_000e3544 @ 0xe3544 (340 bytes) */
int FUN_000e3544(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(param_2 + 8);
  param_1[0xd] = param_2;
  param_1[0xc] = -1;
  *param_1 = iVar1;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  uVar4 = *(undefined4 *)(iVar1 + 0x378);
  puVar2 = (undefined4 *)FUN_00193e18(uVar4,0x14);
  *puVar2 = uVar4;
  puVar2[1] = 2;
  puVar2[4] = uVar4;
  puVar2[2] = 0;
  uVar4 = FUN_00193e18(uVar4,8);
  puVar2[3] = uVar4;
  param_1[10] = (int)(puVar2 + 1);
  uVar4 = *(undefined4 *)(*param_1 + 0x378);
  puVar2 = (undefined4 *)FUN_00193e18(uVar4,0x14);
  *puVar2 = uVar4;
  puVar2[1] = 2;
  puVar2[4] = uVar4;
  puVar2[2] = 0;
  uVar4 = FUN_00193e18(uVar4,8);
  puVar2[3] = uVar4;
  param_1[0xb] = (int)(puVar2 + 1);
  uVar4 = *(undefined4 *)(*param_1 + 0x378);
  puVar2 = (undefined4 *)FUN_00193e18(uVar4,0x14);
  *puVar2 = uVar4;
  puVar2[1] = 2;
  puVar2[2] = 0;
  puVar2[4] = uVar4;
  uVar4 = FUN_00193e18(uVar4,8);
  puVar2[3] = uVar4;
  param_1[9] = (int)(puVar2 + 1);
  piVar3 = (int *)(**(code **)(**(int **)(*param_1 + 0x30c) + 0x68))();
  param_1[8] = (int)piVar3;
                    
                    
  (**(code **)(*piVar3 + 0x14))(piVar3,param_1,param_3,*param_1);
  return;
}

/* FUN_000e36bc @ 0xe36bc (652 bytes) */
int FUN_000e36bc(param_1, param_2, param_3)
  uint *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  undefined1 auStack_78 [4];
  undefined1 auStack_74 [32];
  int *local_54;
  
  ((int (*)())FUN_000e3544)(auStack_74,param_1,param_3);
  (**(code **)(*local_54 + 0x18))(local_54,*param_1);
  piVar1 = (int *)param_1[0xe1];
  for (piVar3 = (int *)((int *)param_1[0xe1])[2]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[2]) {
    iVar2 = (**(code **)(*piVar1 + 0x24))(piVar1);
    if ((iVar2 == 0) || (iVar2 = FUN_000e87e4(piVar1,auStack_78), iVar2 == 0)) {
      iVar2 = FUN_000e79dc(piVar1);
      if (0 < iVar2) {
        piVar4 = (int *)piVar1[0x35];
        if (*piVar4 == 0) {
          puVar5 = (undefined4 *)FUN_0019423c(piVar4,0);
        }
        else {
          if (piVar4[1] == 0) {
            *(undefined4 *)piVar4[2] = 0;
            piVar4[1] = 1;
          }
          puVar5 = (undefined4 *)piVar4[2];
        }
        piVar4 = (int *)*puVar5;
        if (((piVar4 != (int *)0x0) && (iVar2 = (**(code **)(*piVar4 + 0x24))(piVar4), iVar2 != 0))
           && (piVar1 == (int *)piVar4[0x4e])) {
          ((int (*)())FUN_000e2ee4)(auStack_74,piVar4);
        }
      }
      ((int (*)())FUN_000e2838)(auStack_74,(uint)piVar1,*param_1);
    }
    else {
      ((int (*)())FUN_000e280c)(piVar1,auStack_74,auStack_78);
      piVar3 = *(int **)(piVar1[0x4f] + 8);
    }
    piVar1 = piVar3;
  }
  (**(code **)(*local_54 + 0x10))();
  uVar6 = (**(code **)(*local_54 + 0x20))();
  param_1[1] = uVar6;
  ((int (*)())FUN_000e2780)(param_1,auStack_74);
  iVar2 = ((int (*)())FUN_000e284c)(auStack_74);
  iVar7 = FUN_000e07dc(param_1[2],0x4d);
  if (iVar7 == 0) {
    if (iVar2 != 0) goto LAB_000e3900;
  }
  else if (iVar2 != 0) {
    if (*param_1 == 0) {
      *param_1 = 1;
      uVar6 = param_1[1];
      (**(code **)(*local_54 + 0xc))();
      ((int (*)())FUN_000e36bc)(param_1,param_2,param_3);
      ((int (*)())FUN_000e284c)(auStack_74);
      FUN_000e0e0c(param_1[2],"Compression : size reduced from %d to %d  (%%%d)\n",uVar6,
                   param_1[1],(int)((uVar6 - param_1[1]) * 100) / (int)uVar6,in_r8,in_r9,in_r10);
      goto LAB_000e392c;
    }
LAB_000e3900:
    FUN_000e1534(param_1[2],5);
  }
  (**(code **)(*local_54 + 0x24))(local_54,param_2,param_3);
LAB_000e392c:
  ((int (*)())FUN_000e3308)(auStack_74);
  return;
}

/* FUN_000e3968 @ 0xe3968 (396 bytes) */
int FUN_000e3968(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_38 [4];
  undefined4 local_28;
  int local_24 [3];
  
  piVar3 = (int *)FUN_001043f0(0x31,param_3);
  iVar1 = *(int *)(param_1 + 0x94);
  piVar3[0x26] = *(int *)(param_1 + 0x98);
  piVar3[0x25] = iVar1;
  if ((*(uint *)(param_1 + 0x14) & 0x40) == 0) {
    uVar2 = piVar3[5] & 0xffffffbf;
    piVar3[5] = uVar2;
  }
  else {
    uVar2 = piVar3[5] | 0x40;
    piVar3[5] = uVar2;
  }
  if ((*(uint *)(param_1 + 0x14) & 0x20) == 0) {
    piVar3[5] = uVar2 & 0xffffffdf;
  }
  else {
    piVar3[5] = uVar2 | 0x20;
  }
  FUN_00106004(piVar3,1,param_2,0,param_3);
  iVar1 = FUN_001054ec(param_2,0);
  uVar4 = *(undefined4 *)(iVar1 + 0x10);
  iVar1 = FUN_001054ec(param_1,0);
  local_38[0] = *(undefined4 *)(iVar1 + 0x10);
  if ((*(uint *)(param_2 + 0x14) & 0x200) != 0) {
    do {
      param_2 = FUN_00105594(param_2,*(undefined4 *)(param_2 + 0x84));
      iVar1 = FUN_001054ec(param_2,0);
      FUN_000f2f84(&local_28,uVar4,*(undefined4 *)(iVar1 + 0x10));
      uVar4 = local_28;
    } while ((*(uint *)(param_2 + 0x14) & 0x200) != 0);
  }
  iVar1 = 0;
  iVar5 = 4;
  do {
    if (*(char *)((int)local_38 + iVar1) == '\x01') {
      *(undefined1 *)((int)local_38 + iVar1) = 0;
    }
    else {
      *(undefined1 *)((int)local_38 + iVar1) = 1;
    }
    iVar1 = iVar1 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  FUN_000f2f28(local_24,uVar4,local_38[0]);
  piVar3[0x27] = local_24[0];
  (**(code **)(*piVar3 + 0x84))(piVar3,*(undefined4 *)(param_1 + 0x11c));
  return piVar3;
}

/* FUN_000e3af4 @ 0xe3af4 (148 bytes) */
int FUN_000e3af4(param_1, param_2)
  uint param_1;
  undefined4 param_2;
{
  uint uVar1;
  
  uVar1 = param_1;
  do {
    if (uVar1 == 0) {
      return;
    }
    uVar1 = *(uint *)(param_1 + 0x14);
    if (((uVar1 & 1) != 0) && ((uVar1 & 0x200) != 0)) {
      FUN_00106004(param_1,*(undefined4 *)(param_1 + 0x84),0,0,param_2);
      uVar1 = *(uint *)(param_1 + 0x14) & 0xfffffdff;
      *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + -1;
      *(uint *)(param_1 + 0x14) = uVar1;
    }
    param_1 = *(uint *)(param_1 + 8);
    uVar1 = uVar1 & 4;
  } while (param_1 != 0);
  return;
}

/* FUN_000e3b88 @ 0xe3b88 (1848 bytes) */
int FUN_000e3b88(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int *param_3;
  undefined4 *param_4;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int *piVar13;
  int iVar14;
  undefined4 local_58;
  int *local_54 [4];
  undefined4 local_44 [3];
  
  *param_4 = 0;
  if ((param_3 == *(int **)(param_2 + 8)) || ((*(uint *)(param_3[1] + 0x14) & 4) == 0)) {
    if (param_3 != (int *)0x0) {
      iVar14 = 0;
      piVar13 = param_3;
      do {
        uVar4 = piVar13[5];
        if ((uVar4 & 1) != 0) {
          local_54[iVar14] = (int *)0x0;
          if ((piVar13[5] & 0x200U) != 0) {
            if ((piVar13[5] & 2U) == 0) {
              piVar8 = (int *)FUN_00105594(piVar13,piVar13[0x21]);
              iVar6 = (**(code **)(*piVar8 + 0x50))();
              if ((iVar6 == 0) && ((piVar13[5] & 0x800000U) == 0)) {
                uVar11 = thunk_FUN_00134de8(*(undefined4 *)(*param_1 + 0x6c4),piVar13);
                iVar6 = ((int (*)())FUN_000e2f8c)(piVar13,uVar11,*param_1);
                if (iVar6 == 0) {
                  local_54[iVar14] = piVar13;
                  iVar14 = iVar14 + 1;
                  piVar13[5] = piVar13[5] | 0x800000;
                }
              }
            }
            else {
              FUN_00106004(piVar13,piVar13[0x21],0,0,*param_1);
              piVar13[0x21] = piVar13[0x21] + -1;
              piVar13[5] = piVar13[5] & 0xfffffdff;
            }
          }
          if ((piVar13[0x20] == 0) || (iVar6 = FUN_00126760(piVar13[0x26]), iVar6 == 0)) {
            uVar4 = piVar13[5];
          }
          else {
            uVar4 = piVar13[5];
            if ((uVar4 & 2) == 0) {
              (**(code **)(*piVar13 + 0x50))(piVar13);
              uVar4 = piVar13[5];
            }
          }
        }
        piVar13 = (int *)piVar13[2];
      } while ((piVar13 != (int *)0x0) && ((uVar4 & 4) != 0));
    }
    else {
      piVar13 = (int *)0x0;
      iVar14 = 0;
    }
    piVar8 = local_54;
    piVar13 = (int *)piVar13[1];
    if (iVar14 != 0) {
      bVar1 = iVar14 == 2;
      if (bVar1) {
        iVar14 = thunk_FUN_00134de8(*(undefined4 *)(*param_1 + 0x6c4),local_54[0]);
        piVar5 = (int *)FUN_00105594(piVar8,piVar8[0x21]);
        piVar9 = local_54[1];
        iVar6 = thunk_FUN_00134de8(*(undefined4 *)(*param_1 + 0x6c4),local_54[1]);
        piVar7 = (int *)FUN_00105594(piVar9,piVar9[0x21]);
        if ((iVar14 == iVar6) && (piVar5 == piVar7)) {
          param_1[1] = param_1[1] + 1;
          iVar14 = ((int (*)())FUN_000e3968)(piVar8,piVar7,*param_1);
          FUN_000f47a8(iVar14,piVar8,piVar9);
          FUN_000e7738(piVar13[0x56],piVar13,iVar14);
          return iVar14;
        }
        iVar6 = ((int (*)())FUN_000e2f8c)(piVar8,iVar6,*param_1);
        if (iVar6 == 0) {
          bVar2 = true;
          param_1[1] = param_1[1] + 1;
          piVar8 = (int *)((int (*)())FUN_000e3968)(piVar8,piVar5,*param_1);
          FUN_000e7738(piVar13[0x56],piVar13,piVar8);
          local_54[0] = piVar9;
          piVar13 = piVar8;
        }
        else {
          iVar14 = ((int (*)())FUN_000e2f8c)(piVar9,iVar14,*param_1);
          if (iVar14 == 0) {
            bVar2 = true;
            param_1[1] = param_1[1] + 1;
            piVar8 = (int *)((int (*)())FUN_000e3968)(piVar9,piVar7,*param_1);
            FUN_000e7738(piVar13[0x56],piVar13,piVar8);
            piVar13 = piVar8;
          }
          else if (piVar5 == piVar9) {
            bVar2 = false;
            param_1[1] = param_1[1] + 1;
            piVar8 = (int *)((int (*)())FUN_000e3968)(piVar8,piVar9,*param_1);
            FUN_000e7738(piVar13[0x56],piVar13,piVar8);
            local_54[0] = piVar9;
            piVar13 = piVar8;
          }
          else {
            if (piVar8 != piVar7) {
              bVar2 = true;
              bVar1 = true;
              goto LAB_000e4140;
            }
            bVar2 = false;
            param_1[1] = param_1[1] + 1;
            piVar8 = (int *)((int (*)())FUN_000e3968)(piVar9,piVar8,*param_1);
            FUN_000e7738(piVar13[0x56],piVar13,piVar8);
            piVar13 = piVar8;
          }
        }
      }
      else {
        bVar2 = true;
        if (iVar14 != 1) {
LAB_000e4140:
          piVar8 = local_54;
          uVar11 = FUN_00105594(local_54[0],local_54[0][0x21]);
          param_1[2] = param_1[2] + 1;
          iVar10 = piVar8[0x26];
          iVar6 = piVar8[0x25];
          uVar12 = ((int (*)())FUN_000e2a04)(param_1,(uint)(iVar10 != 0));
          iVar14 = ((int (*)())FUN_000e2f04)(piVar8,uVar12,iVar10,uVar11,*param_1);
          FUN_000e7700(param_3[0x56],param_3,iVar14);
          piVar9 = piVar13;
          if (bVar1) {
            uVar11 = FUN_00105594(local_54[1],local_54[1][0x21]);
            param_1[1] = param_1[1] + 1;
            piVar9 = (int *)((int (*)())FUN_000e3968)(local_54[1],uVar11,*param_1);
            FUN_000e7738(piVar13[0x56],piVar13,piVar9);
            FUN_00106004(local_54[1],local_54[1][0x21],0,0,*param_1);
            local_54[1][0x21] = local_54[1][0x21] + -1;
            local_54[1][5] = local_54[1][5] & 0xfffffdff;
          }
          if (bVar2) {
            param_1[1] = param_1[1] + 1;
            piVar13 = (int *)FUN_0010445c(piVar8,*param_1,0);
            FUN_00193f44(piVar13,piVar8);
            FUN_00106004(piVar13,piVar13[0x21],0,0,*param_1);
            piVar13[0x21] = piVar13[0x21] + -1;
            piVar13[5] = piVar13[5] & 0xfffffdff;
            if (piVar9 == piVar8) {
              piVar9 = piVar13;
            }
            uVar4 = piVar8[5];
            FUN_0019401c(piVar8);
            FUN_00108448(piVar8,0x31,*param_1);
            piVar8[0x25] = iVar6;
            piVar8[0x26] = iVar10;
            if ((uVar4 & 0x40) == 0) {
              uVar3 = piVar8[5] & 0xffffffbf;
              piVar8[5] = uVar3;
            }
            else {
              uVar3 = piVar8[5] | 0x40;
              piVar8[5] = uVar3;
            }
            if ((uVar4 & 0x20) == 0) {
              piVar8[5] = uVar3 & 0xffffffdf;
            }
            else {
              piVar8[5] = uVar3 | 0x20;
            }
            FUN_00106004(piVar8,1,piVar13,0,*param_1);
            FUN_00193f74(piVar8,piVar9);
          }
          *param_4 = 1;
          return iVar14;
        }
      }
      piVar8 = local_54;
      iVar14 = thunk_FUN_00134de8(*(undefined4 *)(*param_1 + 0x6c4),local_54[0]);
      iVar6 = FUN_001054ec(piVar8,0);
      local_58 = *(undefined4 *)(iVar6 + 0x10);
      piVar9 = (int *)FUN_00105594(piVar8,piVar8[0x21]);
      iVar6 = thunk_FUN_00134de8(*(undefined4 *)(*param_1 + 0x6c4),piVar9);
      if (param_3 != (int *)0x0) {
        bVar1 = false;
        piVar5 = param_3;
        do {
          uVar4 = piVar5[5];
          if ((uVar4 & 1) != 0) {
            iVar10 = thunk_FUN_00134de8(*(undefined4 *)(*param_1 + 0x6c4),piVar5);
            if ((iVar6 == iVar10) && (piVar5 != piVar9)) {
              bVar1 = true;
            }
            if (piVar5 == piVar8) {
              uVar4 = piVar8[5];
            }
            else {
              iVar10 = thunk_FUN_00134de8(*(undefined4 *)(*param_1 + 0x6c4),piVar5);
              uVar11 = local_58;
              if (iVar14 == iVar10) {
                iVar10 = FUN_001054ec(piVar5,0);
                FUN_000f2f84(local_54 + 3,uVar11,*(undefined4 *)(iVar10 + 0x10));
                local_58 = local_54[3];
                uVar4 = piVar5[5];
              }
              else {
                uVar4 = piVar5[5];
              }
            }
          }
          piVar5 = (int *)piVar5[2];
        } while ((piVar5 != (int *)0x0) && ((uVar4 & 4) != 0));
        piVar5 = param_3;
        if (bVar1) {
          do {
            uVar4 = piVar5[5];
            if ((uVar4 & 1) != 0) {
              iVar6 = ((int (*)())FUN_000e2acc)(piVar5,iVar14,*param_1);
              if (iVar6 != 0) {
LAB_000e413c:
                bVar1 = false;
                goto LAB_000e4140;
              }
              uVar4 = piVar5[5];
              if ((uVar4 & 0x200) != 0) {
                iVar6 = ((int (*)())FUN_000e2f8c)(piVar5,iVar14,*param_1);
                if (iVar6 != 0) goto LAB_000e413c;
                uVar4 = piVar5[5];
              }
            }
            piVar5 = (int *)piVar5[2];
            if ((piVar5 == (int *)0x0) || ((uVar4 & 4) == 0)) {
              param_1[1] = param_1[1] + 1;
              iVar14 = ((int (*)())FUN_000e3968)(piVar8,piVar9,*param_1);
              FUN_000e7700(param_3[0x56],param_3,iVar14);
              FUN_00106004(piVar8,piVar8[0x21],0,0,*param_1);
              piVar8[0x21] = piVar8[0x21] + -1;
              piVar8[5] = piVar8[5] & 0xfffffdff;
              FUN_00106804(piVar8,iVar14,0,*param_1);
              *param_4 = 1;
              return iVar14;
            }
          } while( true );
        }
      }
      param_1[1] = param_1[1] + 1;
      iVar14 = ((int (*)())FUN_000e3968)(piVar8,piVar9,*param_1);
      iVar10 = 4;
      iVar6 = 0;
      do {
        if (*(char *)((int)&local_58 + iVar6) == '\x01') {
          *(undefined1 *)((int)&local_58 + iVar6) = 0;
        }
        else {
          *(undefined1 *)((int)&local_58 + iVar6) = 1;
        }
        iVar6 = iVar6 + 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      iVar6 = FUN_001054ec(iVar14,0);
      FUN_000f2f28(local_44,*(undefined4 *)(iVar6 + 0x10),local_58);
      local_58 = local_44[0];
      *(undefined4 *)(iVar14 + 0x9c) = local_44[0];
      FUN_000e7738(piVar13[0x56],piVar13,iVar14);
      return iVar14;
    }
  }
  return 0;
}

/* FUN_000e43ec @ 0xe43ec (20 bytes) */
int FUN_000e43ec(param_1)
  int param_1;
{
  return *(int *)(param_1 + 0x7c) == 3;
}

/* FUN_000e4400 @ 0xe4400 (8 bytes) */
int FUN_000e4400(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x30) = param_2;
  return;
}

/* FUN_000e4408 @ 0xe4408 (8 bytes) */
int FUN_000e4408(param_1)
  int param_1;
{
  return *(undefined2 *)(param_1 + 0x8e);
}

/* FUN_000e4410 @ 0xe4410 (64 bytes) */
int FUN_000e4410(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0xc) + 8);
  do {
    if (*piVar1 == param_2) {
      return piVar1[1];
    }
  } while ((*(int **)(param_1 + 0x10) != piVar1) &&
          (piVar1 = (int *)piVar1[2], piVar1 != (int *)0x0));
  return -1;
}

/* FUN_000e4450 @ 0xe4450 (116 bytes) */
int FUN_000e4450(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),0x18);
  puVar1[5] = 0;
  *puVar1 = param_2;
  puVar1[1] = param_3;
  puVar1[2] = param_4;
  puVar1[3] = param_5;
  puVar1[4] = param_6;
  *(undefined4 **)(param_1[6] + 0x14) = puVar1;
  param_1[6] = (int)puVar1;
  return;
}

/* FUN_000e44c4 @ 0xe44c4 (456 bytes) */
int FUN_000e44c4(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  float fVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  
  fVar6 = FLOAT_001aa10c;
  fVar4 = FLOAT_001aa0e8;
  fVar3 = FLOAT_001aa0d4;
  uVar8 = param_4 >> 0x15 & 7;
  piVar7 = *(int **)(*(int *)(param_1 + 0x1c) + 0x14);
  do {
    if (*piVar7 == param_2) {
      iVar10 = 4;
      uVar9 = 0;
      do {
        uVar5 = param_4 >> (uVar9 & 0x3f) & 7;
        if (uVar5 < 4) {
          fVar1 = (float)piVar7[uVar5 + 1];
        }
        else {
          fVar1 = FLOAT_001aa0d4;
          if ((uVar5 != 4) && (fVar1 = FLOAT_001aa0e8, uVar5 != 5)) {
            return 0;
          }
        }
        if ((param_4 & 0x10000) != 0) {
          fVar1 = fVar4 - fVar1;
        }
        if ((param_4 >> 0x11 & 1) != 0) {
          fVar1 = fVar1 - fVar6;
        }
        if ((param_4 >> 0x12 & 1) != 0) {
          fVar1 = fVar1 + fVar1;
        }
        fVar2 = fVar1;
        if ((((param_4 & 0x80000) != 0) && (fVar2 = FLOAT_001aa114, fVar3 <= fVar1)) &&
           (fVar2 = FLOAT_001aa0e8, fVar1 == fVar3)) {
          fVar2 = FLOAT_001aa0d4;
        }
        *(float *)(param_3 + uVar9) = fVar2;
        uVar9 = uVar9 + 4;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      fVar3 = FLOAT_001aa0e8;
      if (((param_4 & 0xe00000) != 0) && (uVar8 != 0)) {
        if (uVar8 < 4) {
          fVar3 = *(float *)(param_3 + uVar8 * 4);
        }
        else if (uVar8 == 4) {
          return 0;
        }
      }
      uVar8 = 0;
      iVar10 = 4;
      do {
        fVar4 = *(float *)(uVar8 + param_3) / fVar3;
        if ((param_4 & 0x100000) != 0) {
          fVar4 = ABS(fVar4);
        }
        if ((8 << (uVar8 & 0x3f) & param_4) != 0) {
          fVar4 = -fVar4;
        }
        *(float *)(uVar8 + param_3) = fVar4;
        uVar8 = uVar8 + 4;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
      return 1;
    }
  } while ((piVar7 != *(int **)(param_1 + 0x20)) &&
          (piVar7 = (int *)piVar7[5], piVar7 != (int *)0x0));
  return 0;
}

/* FUN_000e468c @ 0xe468c (132 bytes) */
int FUN_000e468c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int *param_4;
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x14) + 0x14);
  while (*piVar1 != param_2) {
    if (*(int **)(param_1 + 0x18) == piVar1) {
      return 0;
    }
    piVar1 = (int *)piVar1[5];
    if (piVar1 == (int *)0x0) {
      return 0;
    }
  }
  if (param_3 < 4) {
    *param_4 = piVar1[param_3 + 1];
    return 1;
  }
  if (param_3 != 4) {
    if (param_3 != 5) {
      return 0;
    }
    *param_4 = 1;
    return 1;
  }
  *param_4 = 0;
  return 1;
}

/* FUN_000e4710 @ 0xe4710 (20 bytes) */
int FUN_000e4710(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  return *(undefined1 *)(param_2 + param_1 * 0x24 + param_3 + 0x1c);
}

/* FUN_000e4724 @ 0xe4724 (92 bytes) */
int FUN_000e4724(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),0xc);
  puVar1[2] = 0;
  *puVar1 = param_2;
  puVar1[1] = param_3;
  *(undefined4 **)(param_1[4] + 8) = puVar1;
  param_1[4] = (int)puVar1;
  return;
}

/* FUN_000e4780 @ 0xe4780 (116 bytes) */
void FUN_000e4780(int *param_1,undefined4 param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00193e18(*(undefined4 *)(*param_1 + 0x378),0x18);
  puVar1[5] = 0;
  *puVar1 = param_2;
  puVar1[1] = (float)fparam_1;
  puVar1[2] = (float)fparam_2;
  puVar1[3] = (float)fparam_3;
  puVar1[4] = (float)fparam_4;
  *(undefined4 **)(param_1[8] + 0x14) = puVar1;
  param_1[8] = (int)puVar1;
  return;
}

/* FUN_000e47f4 @ 0xe47f4 (60 bytes) */
int FUN_000e47f4(param_1)
  int param_1;
{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*(int *)(param_1 + 0x40) + 4);
  if (uVar2 == 0) {
    return 0xbf;
  }
  puVar1 = (undefined4 *)0x0;
  if (uVar2 - 1 < uVar2) {
    puVar1 = (undefined4 *)((uVar2 - 1) * 4 + *(int *)(*(int *)(param_1 + 0x40) + 8));
  }
  return *(undefined4 *)*puVar1;
}

/* FUN_000e4830 @ 0xe4830 (260 bytes) */
int FUN_000e4830(param_1)
  int *param_1;
{
  int iVar1;
  
  iVar1 = param_1[0xf];
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x10];
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x22];
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x11];
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),param_1[0x19]);
  FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),param_1[0x1a]);
  FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),param_1[0x1b]);
  FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),param_1[0x1c]);
  param_1[0x1a] = 0;
  param_1[0x19] = 0;
  return;
}

/* FUN_000e4934 @ 0xe4934 (260 bytes) */
int FUN_000e4934(param_1)
  int *param_1;
{
  int iVar1;
  
  iVar1 = param_1[0xf];
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x10];
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x22];
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  iVar1 = param_1[0x11];
  if (iVar1 != 0) {
    FUN_00193cc0(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_00193cc0(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),param_1[0x19]);
  FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),param_1[0x1a]);
  FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),param_1[0x1b]);
  FUN_00193cc0(*(undefined4 *)(*param_1 + 0x378),param_1[0x1c]);
  param_1[0x1a] = 0;
  param_1[0x19] = 0;
  return;
}

/* FUN_000e4a38 @ 0xe4a38 (520 bytes) */
int FUN_000e4a38(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ushort uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  int *piVar10;
  int iVar11;
  
  bVar1 = param_2 == 0;
  iVar6 = param_2 * 4 + param_1;
  do {
    iVar4 = *(int *)(param_1 + 0x7c);
    if (iVar4 == 1) {
      iVar4 = *(int *)(param_1 + 0x88);
      puVar8 = (undefined4 *)0x0;
      uVar3 = *(uint *)(iVar4 + 4);
      if (uVar3 - 1 < uVar3) {
        puVar8 = (undefined4 *)((uVar3 - 1) * 4 + *(int *)(iVar4 + 8));
      }
      uVar9 = *puVar8;
      FUN_00194208(iVar4,uVar3 - 1);
      iVar4 = *(int *)(param_1 + 0x7c);
      *(undefined4 *)(iVar6 + 0x8c) = uVar9;
    }
    else {
      if (iVar4 == 2) {
        *(undefined4 *)(iVar6 + 0x8c) = 0x2b;
        return 0;
      }
      if (iVar4 == 0) {
        uVar9 = **(undefined4 **)(param_1 + 0x74);
        *(undefined4 **)(param_1 + 0x74) = *(undefined4 **)(param_1 + 0x74) + 1;
        *(undefined4 *)(iVar6 + 0x8c) = uVar9;
      }
    }
    uVar7 = *(ushort *)(param_1 + 0x8e);
    if (0xbe < uVar7) {
      uVar7 = 0;
    }
    if (((iVar4 == 1) && (bVar1)) && (*(int *)(param_1 + 0x8c) == -1)) {
      iVar4 = *(int *)(param_1 + 0x88);
      puVar8 = (undefined4 *)0x0;
      uVar3 = *(uint *)(iVar4 + 4);
      if (uVar3 - 1 < uVar3) {
        puVar8 = (undefined4 *)((uVar3 - 1) * 4 + *(int *)(iVar4 + 8));
      }
      uVar9 = *puVar8;
      FUN_00194208(iVar4,uVar3 - 1);
      iVar4 = *(int *)(param_1 + 0x88);
      *(undefined4 *)(param_1 + 0x80) = uVar9;
      puVar8 = (undefined4 *)0x0;
      uVar3 = *(uint *)(iVar4 + 4);
      if (uVar3 - 1 < uVar3) {
        puVar8 = (undefined4 *)((uVar3 - 1) * 4 + *(int *)(iVar4 + 8));
      }
      uVar9 = *puVar8;
      FUN_00194208(iVar4,uVar3 - 1);
      iVar4 = *(int *)(param_1 + 0x88);
      *(undefined4 *)(param_1 + 0x7c) = uVar9;
      piVar10 = (int *)0x0;
      uVar3 = *(uint *)(iVar4 + 4);
      iVar5 = *(int *)(param_1 + 0x2c);
      if (uVar3 - 1 < uVar3) {
        piVar10 = (int *)((uVar3 - 1) * 4 + *(int *)(iVar4 + 8));
      }
      iVar11 = *piVar10;
      FUN_00194208(iVar4,uVar3 - 1);
      bVar2 = true;
      *(int *)(param_1 + 0x74) = iVar5 + iVar11 * 4;
    }
    else {
      bVar2 = false;
    }
    if (*(int *)(param_1 + 0x80) == 0) {
      if (bVar1 && uVar7 == 0x2b) {
        *(undefined4 *)(param_1 + 0x7c) = 2;
        return 0;
      }
      if (bVar1 && uVar7 == 0x28) {
        *(undefined4 *)(param_1 + 0x7c) = 2;
        return 0;
      }
    }
    if (!bVar2) {
      return 1;
    }
  } while( true );
}

