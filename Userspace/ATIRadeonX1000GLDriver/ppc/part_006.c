#include "decls.h"

/* FUN_0003e4d0 @ 0x3e4d0 (276 bytes) */
int FUN_0003e4d0(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  uint *param_4;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  
  if (param_3 != 0) {
    iVar6 = 0;
    do {
      uVar5 = *param_4;
      param_4 = param_4 + 1;
      uVar4 = 0x8977;
      uVar1 = uVar5 & 0x300;
      iVar2 = (uVar5 >> 0xc & 0xff) + 0x8921;
      if (uVar1 != 0x100) {
        if (uVar1 < 0x101) {
          uVar4 = 0x8976;
          if (uVar1 != 0) {
LAB_0003e540:
            uVar4 = 0;
          }
        }
        else {
          uVar4 = 0x8978;
          if (uVar1 != 0x200) {
            if (uVar1 != 0x300) goto LAB_0003e540;
            uVar4 = 0x8979;
          }
        }
      }
      uVar1 = uVar5 >> 0x14 & 0xff;
      if ((uVar5 & 7) == 1) {
        iVar3 = uVar1 + 0x8921;
      }
      else {
        iVar3 = 0;
        if ((uVar5 & 7) == 5) {
          iVar3 = uVar1 + 0x84c0;
        }
      }
      if ((uVar5 & 0xf0) == 0) {
        FUN_000a1a60(param_1,iVar2,iVar3,uVar4);
      }
      else {
        FUN_000a1bc0(param_1,iVar2,iVar3,uVar4);
      }
      iVar6 = iVar6 + 1;
    } while (param_3 != iVar6);
  }
  return;
}

/* FUN_0003e600 @ 0x3e600 (1352 bytes) */
int FUN_0003e600(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  int param_3;
  uint *param_4;
{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  
  if (param_3 != 0) {
    iVar9 = 0;
    iVar7 = 0;
    do {
      uVar5 = *param_4;
      param_4 = param_4 + 1;
      uVar2 = uVar5 & 0xf00;
      if (uVar2 == 0x500) {
        uVar10 = 0x8967;
      }
      else if (uVar2 < 0x501) {
        if (uVar2 == 0x200) {
          uVar10 = 0x8964;
        }
        else if (uVar2 < 0x201) {
          if (uVar2 == 0) {
            uVar10 = 0x8961;
          }
          else {
            uVar10 = 0x8963;
            if (uVar2 != 0x100) {
LAB_0003e674:
              uVar10 = 0;
            }
          }
        }
        else if (uVar2 == 0x300) {
          uVar10 = 0x8965;
        }
        else {
          if (uVar2 != 0x400) goto LAB_0003e674;
          uVar10 = 0x8966;
        }
      }
      else if (uVar2 == 0x800) {
        uVar10 = 0x896a;
      }
      else if (uVar2 < 0x801) {
        if (uVar2 == 0x600) {
          uVar10 = 0x8968;
        }
        else {
          if (uVar2 != 0x700) goto LAB_0003e674;
          uVar10 = 0x8969;
        }
      }
      else if (uVar2 == 0x900) {
        uVar10 = 0x896b;
      }
      else {
        if (uVar2 != 0xa00) goto LAB_0003e674;
        uVar10 = 0x896c;
      }
      uVar11 = 0;
      iVar8 = (uVar5 >> 0x14 & 0xff) + 0x8921;
      if ((uVar5 & 0xf000) != 0) {
        puVar1 = (undefined *)(uVar5 & 0x7000);
        uVar11 = 4;
        if (puVar1 != (undefined *)0x3000) {
          if (puVar1 < (undefined *)0x3001) {
            uVar11 = 1;
            if ((puVar1 != (undefined *)0x1000) && (uVar11 = 2, puVar1 != (undefined *)0x2000)) {
LAB_0003e7c8:
              uVar11 = 0;
            }
          }
          else {
            uVar11 = 0x10;
            if ((puVar1 != ((unsigned char *)0x00005000)) && (uVar11 = 0x20, puVar1 != (undefined *)0x6000)) {
              if (puVar1 != (undefined *)0x4000) goto LAB_0003e7c8;
              uVar11 = 8;
            }
          }
        }
        if ((uVar5 & 0x8000) != 0) {
          uVar11 = uVar11 | 0x40;
        }
      }
      if (uVar2 == 0) {
        iVar9 = 1;
LAB_0003e830:
        puVar6 = &local_60;
        iVar12 = iVar9;
        do {
          uVar4 = *param_4;
          param_4 = param_4 + 1;
          uVar2 = uVar4 & 7;
          uVar3 = uVar4 >> 0x14 & 0xff;
          if (uVar2 == 2) {
            uVar3 = uVar3 + 0x8941;
          }
          else if (uVar2 < 3) {
            if (uVar2 != 1) goto LAB_0003e868;
            uVar3 = uVar3 + 0x8921;
          }
          else if (uVar2 != 3) {
            if (uVar2 == 4) {
              if (uVar3 == 0) {
                uVar3 = 0x8577;
              }
              else {
                if (uVar3 != 1) goto LAB_0003e868;
                uVar3 = 0x896d;
              }
            }
            else {
LAB_0003e868:
              uVar3 = 0;
            }
          }
          uVar2 = uVar4 & 0x7000;
          puVar6[-2] = uVar3;
          if (uVar2 == 0x2000) {
            uVar3 = 0x1904;
          }
          else if (uVar2 < 0x2001) {
            uVar3 = 0x1903;
            if (uVar2 != 0x1000) {
LAB_0003e904:
              uVar3 = 0;
            }
          }
          else {
            uVar3 = 0x1905;
            if ((uVar2 != 0x3000) && (uVar3 = 0x1906, uVar2 != 0x4000)) goto LAB_0003e904;
          }
          puVar6[-1] = uVar3;
          uVar2 = 0;
          if ((uVar4 & 0xf00) != 0) {
            uVar2 = uVar4 >> 6 & 4;
            if ((uVar4 & 0x200) != 0) {
              uVar2 = uVar2 | 1;
            }
            if ((uVar4 & 0x400) != 0) {
              uVar2 = uVar2 | 8;
            }
            if ((uVar4 & 0x800) != 0) {
              uVar2 = uVar2 | 2;
            }
          }
          *puVar6 = uVar2;
          puVar6 = puVar6 + 3;
          iVar12 = iVar12 + -1;
        } while (iVar12 != 0);
      }
      else {
        if (uVar2 < 0x501) {
          iVar9 = 2;
          goto LAB_0003e830;
        }
        if (uVar2 < 0xa01) {
          iVar9 = 3;
          goto LAB_0003e830;
        }
        if (iVar9 != 0) goto LAB_0003e830;
      }
      if ((uVar5 & 0x70000) == 0) {
        uVar2 = 0;
        if ((uVar5 & 0xf0000) == 0) goto LAB_0003e9b8;
      }
      else {
        uVar2 = (uVar5 & 0x70000) >> 0x10 & 1;
        if ((uVar5 & 0x20000) != 0) {
          uVar2 = uVar2 | 2;
        }
        if ((uVar5 & 0x40000) != 0) {
          uVar2 = uVar2 | 4;
        }
LAB_0003e9b8:
        if (iVar9 == 2) {
          FUN_000a1dc0(param_1,uVar10,iVar8,uVar2,uVar11,local_68,local_64,local_60,local_5c,
                       local_58,local_54);
        }
        else if (iVar9 == 3) {
          FUN_000a1e70(param_1,uVar10,iVar8,uVar2,uVar11,local_68,local_64,local_60,local_5c,
                       local_58,local_54,local_50,local_4c,local_48);
        }
        else if (iVar9 == 1) {
          FUN_000a1d20(param_1,uVar10,iVar8,uVar2,uVar11,local_68,local_64,local_60);
        }
      }
      if (((uVar5 & 0x80000) != 0) || ((uVar5 & 0xf0000) == 0)) {
        if (iVar9 == 2) {
          FUN_000a1fb0(param_1,uVar10,iVar8,uVar11,local_68,local_64,local_60,local_5c,local_58,
                       local_54);
        }
        else if (iVar9 == 3) {
          FUN_000a2050(param_1,uVar10,iVar8,uVar11,local_68,local_64,local_60,local_5c,local_58,
                       local_54,local_50,local_4c,local_48);
        }
        else if (iVar9 == 1) {
          FUN_000a1f20(param_1,uVar10,iVar8,uVar11,local_68,local_64,local_60);
        }
      }
      iVar7 = iVar7 + 1;
    } while (param_3 != iVar7);
  }
  return;
}

/* FUN_0003eb70 @ 0x3eb70 (296 bytes) */
int FUN_0003eb70(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  undefined4 param_3;
{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  
  *(undefined2 *)(param_1 + 0x2800) = 0;
  FUN_000a16b0(param_1);
  uVar1 = *(ushort *)((int)param_2 + 0x16);
  uVar4 = *param_2 >> 0x10 & 0xff;
  puVar6 = param_2 + (*param_2 & 0xffff);
  if (uVar4 != 0) {
    uVar5 = 0;
    do {
      uVar2 = *puVar6;
      puVar6 = puVar6 + 1;
      if ((uVar2 & 3) == 1) {
        FUN_000a2100(param_1,(uVar2 >> 0x14 & 0xff) + 0x8941,
                     (int)param_2 + (uVar2 >> 8 & 0xff0) + (uint)uVar1 * 4);
      }
      uVar5 = uVar5 + 1;
    } while (uVar4 != uVar5);
  }
  ((int (*)())FUN_0003e4d0)(param_1,param_3,param_2[1] >> 0x10 & 0xff,param_2 + (param_2[1] & 0xffff));
  ((int (*)())FUN_0003e600)(param_1,param_3,param_2[2] >> 0x10 & 0xff,param_2 + (param_2[2] & 0xffff));
  ((int (*)())FUN_0003e4d0)(param_1,param_3,param_2[3] >> 0x10 & 0xff,param_2 + (param_2[3] & 0xffff));
  ((int (*)())FUN_0003e600)(param_1,param_3,param_2[4] >> 0x10 & 0xff,param_2 + (param_2[4] & 0xffff));
  FUN_000a1750(param_1);
  uVar3 = FUN_000a11a0(param_1);
  *(undefined4 *)(param_1 + 0x27b8) = uVar3;
  return 1;
}

/* FUN_0003eca0 @ 0x3eca0 (164 bytes) */
int FUN_0003eca0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar5 = *(uint *)(param_1[0xd] + 0x20);
  if ((uVar5 & 0x4000000) == 0) {
    *(uint *)(param_1[0xd] + 0x20) = uVar5 | 0x4000000;
    fVar4 = FLOAT_001aa13c;
    fVar3 = FLOAT_001aa138;
    fVar2 = FLOAT_001aa134;
    fVar1 = FLOAT_001aa130;
    iVar6 = param_1[6];
    iVar7 = param_1[10];
    *(undefined4 *)(iVar6 * 4 + iVar7) = 0x1c;
    iVar7 = iVar6 * 4 + iVar7;
    uVar5 = *(uint *)(*param_1 + 0x28);
    *(float *)(iVar7 + 8) = fVar1;
    *(uint *)(iVar7 + 4) = uVar5 & 0xffff | 0x10000;
    *(float *)(iVar7 + 0x14) = fVar4;
    *(float *)(iVar7 + 0xc) = fVar2;
    *(float *)(iVar7 + 0x10) = fVar3;
    param_1[6] = param_1[6] + 6;
  }
  return param_1[9];
}

/* FUN_0003ed50 @ 0x3ed50 (60 bytes) */
int FUN_0003ed50(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint uVar1;
  
  uVar1 = *(uint *)(((uint)*(ushort *)(param_2 + 6) + *(int *)(*param_1 + 0x14)) * 8 + *param_1) >>
          0x1a & 7;
  if (uVar1 == 3) {
    return 1;
  }
  return (uint)(uVar1 == 4) << 1;
}

/* FUN_0003ed90 @ 0x3ed90 (160 bytes) */
int FUN_0003ed90(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  uint *param_2;
  uint *param_3;
  uint *param_4;
  int param_5;
{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = *param_2;
  uVar3 = 0;
  if ((uVar5 & 0xe0000) == 0x20000) {
    uVar2 = (uint)*(ushort *)((int)param_2 + 6);
  }
  else {
    uVar1 = *(ushort *)((int)param_2 + 6);
    iVar4 = *(int *)(*param_1 + 0x10);
    param_1[4] = 1 << (uVar1 & 0x3f) | param_1[4];
    uVar2 = (uint)uVar1 + iVar4 + 1;
    uVar5 = *param_2;
  }
  if (param_5 != 0) {
    uVar3 = 0x100;
  }
  *param_3 = uVar2 & 0xffff | 0x440000;
  *param_4 = (uVar5 >> 0x10 & 1) << 6 |
             (uVar5 >> 0xf & 1) << 4 | (uVar5 >> 0xe & 1) << 2 | uVar5 >> 0xd & 1 | uVar3;
  return 0;
}

/* FUN_0003ee30 @ 0x3ee30 (88 bytes) */
int FUN_0003ee30(param_1, param_2, param_3)
  uint param_1;
  int param_2;
  uint *param_3;
{
  if (param_2 == 0) {
    *param_3 = param_1 & 7 | *param_3 & 0xfffffff8;
    return;
  }
  if (param_2 == 1) {
    *param_3 = (param_1 & 7) << 4 | *param_3 & 0xffffff8f;
    return;
  }
  if (param_2 == 2) {
    *param_3 = (param_1 & 7) << 8 | *param_3 & 0xfffff8ff;
    return;
  }
  *param_3 = (param_1 & 7) << 0xc | *param_3 & 0xffff8fff;
  return;
}

/* FUN_0003eea0 @ 0x3eea0 (168 bytes) */
int FUN_0003eea0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint *param_3;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if ((*(uint *)(param_1 + 0x14) >> 0x15 & 0x3f) < 0x20) {
    iVar1 = *(int *)(param_1 + 0x28);
    iVar3 = *(int *)(param_1 + 0x18) * 4;
    *(undefined4 *)(iVar3 + iVar1) = 0x1c;
    iVar3 = iVar3 + iVar1;
    uVar2 = *(uint *)(param_1 + 0x14);
    *(undefined4 *)(iVar3 + 0x14) = 0;
    *(undefined4 *)(iVar3 + 0xc) = 0;
    *(undefined4 *)(iVar3 + 0x10) = 0;
    *(undefined4 *)(iVar3 + 8) = param_2;
    *(uint *)(iVar3 + 4) = uVar2 >> 0x15 & 0x3f | 0x20000;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 6;
    *param_3 = *(uint *)(param_1 + 0x14) >> 0x15 & 0x3f;
    *(uint *)(param_1 + 0x14) =
         ((*(uint *)(param_1 + 0x14) >> 0x15 & 0x3f) + 1) * 0x200000 & 0x7e00000 |
         *(uint *)(param_1 + 0x14) & 0xf81fffff;
    return *(int *)(param_1 + 0x24);
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    return *(int *)(param_1 + 0x24);
  }
  *(undefined4 *)(param_1 + 0x24) = 4;
  return 4;
}

/* FUN_0003ef50 @ 0x3ef50 (240 bytes) */
int FUN_0003ef50(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0x28);
  iVar2 = *(int *)(param_1 + 0x2c);
  uVar1 = *(uint *)(param_1 + 0x30);
  if (uVar1 < (uint)(param_2 + iVar2)) {
    if (uVar1 == 0) {
      uVar1 = 0x10;
    }
    else {
      uVar1 = uVar1 << 1;
    }
    for (; uVar1 < (uint)(param_2 + iVar2); uVar1 = uVar1 << 1) {
    }
    if (*piVar3 == 0) {
      iVar2 = _malloc(uVar1 << 2);
    }
    else {
      iVar2 = _realloc(*piVar3,uVar1 << 2);
    }
    if (iVar2 == 0) {
      if (*(int *)(param_1 + 0x24) != 0) {
        return *(int *)(param_1 + 0x24);
      }
      *(undefined4 *)(param_1 + 0x24) = 1;
      return 1;
    }
    *piVar3 = iVar2;
    *(uint *)(param_1 + 0x30) = uVar1;
    iVar2 = *(int *)(param_1 + 0x2c);
  }
  *(int *)(param_1 + 0x2c) = param_2 + iVar2;
  *param_3 = iVar2 * 4 + *piVar3;
  return 0;
}

/* FUN_0003f050 @ 0x3f050 (336 bytes) */
int FUN_0003f050(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 *param_3;
{
  byte *pbVar1;
  ushort uVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  
  iVar5 = *param_1;
  iVar3 = iVar5 + *(int *)(iVar5 + 0x54) * 8 + param_2 * 8;
  if ((*(uint *)(iVar3 + 0x18) & 0x3800000) == 0x1000000) {
    iVar3 = ((uint)*(ushort *)(iVar3 + 0x1e) + *(int *)(iVar5 + 0x2c)) * 8;
    uVar7 = *(uint *)(iVar5 + iVar3);
    iVar5 = iVar5 + iVar3;
    if (((uVar7 & 0x1f0000) == 0x10000) && ((uVar7 & 0x1c000000) == 0xc000000)) {
      *param_3 = *(undefined4 *)((uint)*(ushort *)(iVar5 + 2) * 0x10 + param_1[3]);
      pbVar4 = (byte *)param_1[0xd];
      uVar7 = *(uint *)(pbVar4 + 0x20) >> 0x1b;
      if (uVar7 == 0) {
        uVar2 = *(ushort *)(iVar5 + 2);
LAB_0003f164:
        pbVar4[uVar7 * 2] = (byte)uVar2;
        *(char *)(uVar7 * 2 + param_1[0xd] + 1) = (char)*param_3;
        *(int *)(param_1[0xd] + 0x20) = *(int *)(param_1[0xd] + 0x20) + 0x8000000;
        return 0;
      }
      uVar2 = *(ushort *)(iVar5 + 2);
      if (*pbVar4 != uVar2) {
        iVar3 = 0;
        pbVar6 = pbVar4;
        uVar8 = uVar7;
        do {
          iVar3 = iVar3 + 1;
          uVar8 = uVar8 - 1;
          if (uVar8 == 0) {
            if (0xf < iVar3) {
              if (param_1[9] != 0) {
                return param_1[9];
              }
              param_1[9] = 4;
              return 4;
            }
            goto LAB_0003f164;
          }
          pbVar1 = pbVar6 + 2;
          pbVar6 = pbVar6 + 2;
        } while (*pbVar1 != uVar2);
      }
      return 0;
    }
  }
  if (param_1[9] != 0) {
    return param_1[9];
  }
  param_1[9] = 2;
  return 2;
}

/* FUN_0003f1c0 @ 0x3f1c0 (700 bytes) */
int FUN_0003f1c0(param_1, param_2, param_3, param_4)
  int *param_1;
  uint *param_2;
  uint *param_3;
  uint *param_4;
{
  int iVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined *puVar10;
  
  uVar7 = *param_2;
  uVar5 = uVar7 & 0x3800000;
  if (uVar5 == 0) {
    iVar8 = *param_1;
    iVar1 = ((uint)*(ushort *)((int)param_2 + 6) + *(int *)(iVar8 + 0x24)) * 8;
    switch(*(ushort *)(iVar8 + iVar1) & 0xf) {
    default:
switchD_0003f230_caseD_0:
      if (param_1[9] != 0) {
        return param_1[9];
      }
      param_1[9] = 3;
      return 3;
    case 1:
      bVar2 = false;
      puVar10 = ((unsigned char *)0x00160000);
      break;
    case 2:
      bVar2 = false;
      puVar10 = (undefined *)0x120000;
      break;
    case 3:
      bVar2 = false;
      puVar10 = (undefined *)0x130000;
      break;
    case 5:
      bVar2 = true;
      puVar10 = (undefined *)0x100000;
      break;
    case 7:
      bVar2 = false;
      puVar10 = (undefined *)(*(uint *)(iVar8 + iVar1) & 0x1f | 0x110000);
    }
  }
  else if (uVar5 == 0x1000000) {
    bVar2 = false;
    puVar10 = (undefined *)(*(ushort *)((int)param_2 + 6) | 0x10000);
  }
  else if (uVar5 == 0x800000) {
    bVar2 = false;
    puVar10 = (undefined *)(*(ushort *)((int)param_2 + 6) | 0x40000);
  }
  else {
    if (uVar5 != 0x1800000) goto switchD_0003f230_caseD_0;
    bVar2 = false;
    puVar10 = (undefined *)
              ((uint)*(ushort *)((int)param_2 + 6) + *(int *)(*param_1 + 0x10) + 1 & 0xffff |
              0x40000);
  }
  if ((param_1[5] & 0x20000000U) == 0) {
    uVar5 = 4;
  }
  else {
    uVar5 = (uVar7 >> 0xc & 3) + 1;
  }
  uVar3 = uVar7 >> 0x1b & 1;
  uVar6 = 4;
  if (uVar5 != 0) {
    uVar6 = *(uint *)(&DAT_001dac08 + (uVar7 >> 0x13 & 0xc)) >> 0x19 & 7;
  }
  uVar4 = uVar3 ^ *(uint *)(&DAT_001dac08 + (uVar7 >> 0x13 & 0xc)) >> 0x18 & 1;
  uVar9 = uVar4 << 3 | uVar6;
  if (uVar5 < 2) {
    uVar5 = uVar4 << 0xf |
            uVar6 << 0xc | uVar4 << 0xb | uVar6 << 8 | uVar4 << 7 | uVar6 << 4 | uVar9;
  }
  else {
    uVar6 = 4;
    if (2 < uVar5) {
      uVar6 = *(uint *)(&DAT_001dac08 + (uVar7 >> 0xf & 0xc)) >> 0x19 & 7;
    }
    uVar4 = 4;
    if (3 < uVar5) {
      uVar4 = *(uint *)(&DAT_001dac08 + (uVar7 >> 0xd & 0xc)) >> 0x19 & 7;
    }
    uVar5 = (uVar3 ^ *(uint *)(&DAT_001dac08 + (uVar7 >> 0xd & 0xc)) >> 0x18 & 1) << 0xf |
            uVar4 << 0xc |
            (uVar3 ^ *(uint *)(&DAT_001dac08 + (uVar7 >> 0xf & 0xc)) >> 0x18 & 1) << 0xb |
            uVar6 << 8 |
            (uVar3 ^ *(uint *)(&DAT_001dac08 + (uVar7 >> 0x11 & 0xc)) >> 0x18 & 1) << 7 |
            *(uint *)(&DAT_001dac08 + (uVar7 >> 0x11 & 0xc)) >> 0x15 & 0x70 | uVar9;
  }
  if (bVar2) {
    uVar5 = ((byte)(DAT_001dac00)[uVar5 >> 0xc & 7] & 7) << 0xc |
            ((byte)(DAT_001dac00)[uVar5 >> 8 & 7] & 7) << 8 |
            ((byte)(DAT_001dac00)[uVar5 >> 4 & 7] & 7) << 4 |
            (byte)(DAT_001dac00)[uVar5 & 7] & 7 | uVar5 & 0xffff8888;
  }
  *param_3 = (uint)puVar10 | 0x400000;
  *param_4 = uVar5;
  return 0;
}

/* FUN_0003f4e0 @ 0x3f4e0 (232 bytes) */
int FUN_0003f4e0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint *param_2;
  undefined4 *param_3;
  uint *param_4;
  uint *param_5;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 local_38;
  uint local_34 [7];
  
  iVar2 = ((int (*)())FUN_0003f1c0)(param_1,param_2,&local_38,local_34);
  if (iVar2 == 0) {
    uVar6 = *param_5;
    uVar3 = 0;
    uVar7 = *param_2 >> 0x1b & 1;
    uVar1 = *(uint *)(&DAT_001dac08 + (uVar6 >> 10 & 0x3c));
    uVar5 = *(uint *)(&DAT_001dac08 + (uVar6 >> 6 & 0x3c));
    uVar4 = *(uint *)(&DAT_001dac08 + (uVar6 >> 2 & 0x3c));
    uVar6 = *(uint *)(&DAT_001dac08 + (uVar6 & 0xf) * 4);
    *param_3 = local_38;
    *param_4 = (uVar7 ^ uVar6 >> 0x18 & 1) << 0xf |
               uVar6 >> 0xd & 0x7000 |
               (uVar7 ^ uVar4 >> 0x18 & 1) << 0xb |
               uVar4 >> 0x11 & 0x700 |
               (uVar7 ^ uVar5 >> 0x18 & 1) << 7 |
               uVar5 >> 0x15 & 0x70 |
               (uVar7 ^ uVar1 >> 0x18 & 1) << 3 | uVar1 >> 0x19 & 7 | local_34[0] & 0xffff0000;
  }
  else {
    uVar3 = *(undefined4 *)(param_1 + 0x24);
  }
  return uVar3;
}

/* FUN_0003f5d0 @ 0x3f5d0 (12 bytes) */
int FUN_0003f5d0(param_1)
  int param_1;
{
  if (param_1 == 0) {
    return;
  }
  _free(param_1);
  return;
}

/* FUN_0003f5e0 @ 0x3f5e0 (112 bytes) */
int FUN_0003f5e0(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x34) != 0) {
    ((int (*)())FUN_0003f5d0)(*(int *)(param_1 + 0x34));
  }
  if (*(int *)(param_1 + 0x28) != 0) {
    _free(*(int *)(param_1 + 0x28));
  }
  if (param_1 != 0) {
    _free(param_1);
    return;
  }
  return;
}

/* FUN_0003f660 @ 0x3f660 (220 bytes) */
int FUN_0003f660()
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _malloc(0x38);
  if (iVar2 != 0) {
    _memset(iVar2,0,0x38);
    *(undefined4 *)(iVar2 + 0x24) = 0;
    *(undefined4 *)(iVar2 + 0x28) = 0;
    *(undefined4 *)(iVar2 + 0x30) = 0;
    *(undefined4 *)(iVar2 + 0x2c) = 0;
    *(undefined4 *)(iVar2 + 4) = 0xffffffff;
    *(undefined4 *)(iVar2 + 8) = 0xffffffff;
    iVar3 = _malloc(0x24);
    iVar1 = 0;
    if (iVar3 != 0) {
      _memset(iVar3,0,0x24);
      iVar1 = iVar3;
    }
    *(int *)(iVar2 + 0x34) = iVar1;
    if (*(int *)(iVar2 + 0x34) != 0) {
      return iVar2;
    }
    if (iVar2 != 0) {
      _free(iVar2);
      return 0;
    }
  }
  return 0;
}

/* FUN_0003f750 @ 0x3f750 (232 bytes) */
int FUN_0003f750(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  uint *param_2;
  uint *param_3;
  uint *param_4;
  undefined4 param_5;
{
  undefined4 uVar1;
  uint uVar2;
  
  if (((param_1[5] & 0x20000000U) != 0) &&
     (((((uVar2 = *param_2, (uVar2 & 0x2000) != 0 && ((uVar2 & 0x300) != 0)) ||
        (((uVar2 & 0x4000) != 0 && ((uVar2 & 0xc0) != 0x40)))) ||
       (((uVar2 & 0x8000) != 0 && ((uVar2 & 0x30) != 0x20)))) ||
      (((uVar2 & 0x10000) != 0 && ((uVar2 & 0xc) != 0xc)))))) {
    uVar1 = *(undefined4 *)(*param_1 + 0x10);
    *param_3 = 0;
    *param_4 = 0;
    *param_3 = *param_3 & 0xffc0ffff | 0x40000;
    *(short *)((int)param_3 + 2) = (short)uVar1;
    *param_3 = *param_3 | 0x400000;
    *param_4 = *param_4 & 0xffffff00 | 0x55;
    return 0;
  }
  uVar1 = ((int (*)())FUN_0003ed90)(param_1,param_2,param_3,param_4,param_5);
  return uVar1;
}

/* FUN_0003f850 @ 0x3f850 (396 bytes) */
int FUN_0003f850(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  dword *pdVar3;
  dword *pdVar4;
  dword *pdVar5;
  undefined4 *puVar6;
  dword *pdVar7;
  int *piVar8;
  dword *pdVar9;
  dword *pdVar10;
  
  piVar8 = (int *)(param_1 + 0x28);
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  iVar2 = *(int *)(param_1 + 0x2c);
  uVar1 = *(uint *)(param_1 + 0x30);
  if (uVar1 < iVar2 + 7U) {
    if (uVar1 == 0) {
      uVar1 = 0x10;
    }
    else {
      uVar1 = uVar1 << 1;
    }
    for (; uVar1 < iVar2 + 7U; uVar1 = uVar1 << 1) {
    }
    if (*piVar8 == 0) {
      iVar2 = _malloc(uVar1 << 2);
    }
    else {
      iVar2 = _realloc(*piVar8,uVar1 << 2);
    }
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x24);
      if (iVar2 == 0) {
        iVar2 = 1;
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (iVar2 != 0) {
        return iVar2;
      }
      puVar6 = (undefined4 *)0x0;
      pdVar7 = &MACH_HEADER.cputype;
      pdVar9 = &MACH_HEADER.cpusubtype;
      pdVar10 = &MACH_HEADER.filetype;
      pdVar3 = &MACH_HEADER.ncmds;
      pdVar4 = &MACH_HEADER.sizeofcmds;
      pdVar5 = &MACH_HEADER.flags;
      goto LAB_0003f918;
    }
    *piVar8 = iVar2;
    *(uint *)(param_1 + 0x30) = uVar1;
    iVar2 = *(int *)(param_1 + 0x2c);
  }
  *(int *)(param_1 + 0x2c) = iVar2 + 7;
  puVar6 = (undefined4 *)(iVar2 * 4 + *piVar8);
  pdVar7 = puVar6 + 1;
  pdVar9 = puVar6 + 2;
  pdVar10 = puVar6 + 3;
  pdVar3 = puVar6 + 4;
  pdVar4 = puVar6 + 5;
  pdVar5 = puVar6 + 6;
LAB_0003f918:
  *puVar6 = 1;
  *pdVar7 = 0x10200;
  *pdVar9 = 0x47;
  *pdVar10 = 0x170000;
  *pdVar3 = 0x440000;
  *pdVar4 = (dword)((unsigned char *)0x00004444);
  *pdVar5 = 0x28;
  return 0;
}

/* FUN_0003f9f0 @ 0x3f9f0 (472 bytes) */
int FUN_0003f9f0(param_1, param_2, param_3)
  int *param_1;
  uint *param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  dword *pdVar6;
  dword *pdVar7;
  uint uVar8;
  uint uVar9;
  dword *pdVar10;
  uint uVar11;
  dword *pdVar12;
  int *piVar13;
  dword local_38;
  dword local_34 [6];
  
  local_38 = 0;
  local_34[0] = 0;
  iVar2 = ((int (*)())FUN_0003ed90)(param_1,param_2,&local_38,local_34,param_3);
  if (iVar2 != 0) {
    return param_1[9];
  }
  uVar11 = *param_2;
  piVar13 = param_1 + 10;
  iVar2 = param_1[0xb];
  uVar3 = param_1[0xc];
  uVar8 = *(uint *)(&DAT_001dac08 + (uVar11 >> 6 & 0xc));
  uVar5 = *(uint *)(&DAT_001dac08 + (uVar11 >> 4 & 0xc));
  uVar4 = *(uint *)(&DAT_001dac08 + (uVar11 >> 2 & 0xc));
  uVar9 = *(uint *)(&DAT_001dac08 + (uVar11 & 0xc));
  uVar11 = *(uint *)(*param_1 + 0x10);
  if (uVar3 < iVar2 + 5U) {
    if (uVar3 == 0) {
      uVar3 = 0x10;
    }
    else {
      uVar3 = uVar3 << 1;
    }
    for (; uVar3 < iVar2 + 5U; uVar3 = uVar3 << 1) {
    }
    if (*piVar13 == 0) {
      iVar2 = _malloc(uVar3 << 2);
    }
    else {
      iVar2 = _realloc(*piVar13,uVar3 << 2);
    }
    if (iVar2 == 0) {
      iVar2 = param_1[9];
      if (iVar2 == 0) {
        iVar2 = 1;
        param_1[9] = 1;
      }
      if (iVar2 != 0) {
        return iVar2;
      }
      puVar1 = (undefined4 *)0x0;
      pdVar6 = &MACH_HEADER.cputype;
      pdVar10 = &MACH_HEADER.cpusubtype;
      pdVar12 = &MACH_HEADER.filetype;
      pdVar7 = &MACH_HEADER.ncmds;
      goto LAB_0003fb50;
    }
    *piVar13 = iVar2;
    param_1[0xc] = uVar3;
    iVar2 = param_1[0xb];
  }
  param_1[0xb] = iVar2 + 5;
  puVar1 = (undefined4 *)(iVar2 * 4 + *piVar13);
  pdVar6 = puVar1 + 1;
  pdVar10 = puVar1 + 2;
  pdVar12 = puVar1 + 3;
  pdVar7 = puVar1 + 4;
LAB_0003fb50:
  *puVar1 = 0x47;
  *pdVar6 = local_38;
  *pdVar10 = local_34[0];
  *pdVar12 = uVar11 & 0xffff | 0x440000;
  *pdVar7 = uVar9 >> 9 & 0x8000 |
            uVar9 >> 0xd & 0x7000 |
            uVar4 >> 0xd & 0x800 |
            uVar4 >> 0x11 & 0x700 |
            uVar5 >> 0x11 & 0x80 | uVar5 >> 0x15 & 0x70 | uVar8 >> 0x15 & 8 | uVar8 >> 0x19 & 7;
  return 0;
}

/* FUN_0003fbf0 @ 0x3fbf0 (392 bytes) */
int FUN_0003fbf0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  int param_3;
  int param_4;
{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  
  if (*(int *)(param_1 + 0x24) != 0) {
    return *(int *)(param_1 + 0x24);
  }
  piVar8 = (int *)(param_1 + 0x28);
  iVar6 = *(int *)(param_1 + 0x2c);
  uVar2 = *(uint *)(param_1 + 0x30);
  iVar7 = (param_3 + param_4) * 2 + 1;
  uVar3 = iVar7 + iVar6;
  if (uVar2 < uVar3) {
    if (uVar2 == 0) {
      uVar2 = 0x10;
    }
    else {
      uVar2 = uVar2 << 1;
    }
    for (; uVar2 < uVar3; uVar2 = uVar2 << 1) {
    }
    if (*piVar8 == 0) {
      iVar6 = _malloc(uVar2 << 2);
    }
    else {
      iVar6 = _realloc(*piVar8,uVar2 << 2);
    }
    if (iVar6 == 0) {
      iVar6 = *(int *)(param_1 + 0x24);
      if (iVar6 == 0) {
        iVar6 = 1;
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      puVar4 = (undefined4 *)0x0;
      if (iVar6 != 0) {
        return iVar6;
      }
      goto LAB_0003fcc0;
    }
    *piVar8 = iVar6;
    *(uint *)(param_1 + 0x30) = uVar2;
    iVar6 = *(int *)(param_1 + 0x2c);
  }
  *(int *)(param_1 + 0x2c) = iVar7 + iVar6;
  puVar4 = (undefined4 *)(iVar6 * 4 + *piVar8);
LAB_0003fcc0:
  *puVar4 = *param_2;
  if (param_3 == 0) {
    iVar6 = 1;
  }
  else {
    iVar6 = 3;
    puVar4[1] = param_2[1];
    puVar4[2] = param_2[2];
  }
  if (0 < param_4) {
    puVar4 = puVar4 + iVar6;
    puVar5 = puVar4;
    do {
      *puVar5 = param_2[3];
      puVar5 = puVar5 + 2;
      puVar1 = param_2 + 6;
      param_2 = param_2 + 1;
      puVar4[1] = *puVar1;
      puVar4 = puVar4 + 2;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
  }
  return 0;
}

/* FUN_0003fd80 @ 0x3fd80 (440 bytes) */
int FUN_0003fd80(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  uint uVar10;
  
  uVar6 = *(uint *)(*param_1 + *(int *)(*param_1 + 0x54) * 8 + param_2 * 8);
  uVar10 = uVar6 >> 0x1d;
  uVar6 = (*(uint *)(&DAT_001dac40 + (uVar6 >> 0xe & 0xff0)) ^ 0x20000000) >> 0x1d & 1;
  if (param_1[9] != 0) {
    return param_1[9];
  }
  piVar9 = param_1 + 10;
  iVar7 = param_1[0xb];
  uVar2 = param_1[0xc];
  iVar8 = (uVar6 + uVar10) * 2 + 1;
  uVar3 = iVar8 + iVar7;
  if (uVar2 < uVar3) {
    if (uVar2 == 0) {
      uVar2 = 0x10;
    }
    else {
      uVar2 = uVar2 << 1;
    }
    for (; uVar2 < uVar3; uVar2 = uVar2 << 1) {
    }
    if (*piVar9 == 0) {
      iVar7 = _malloc(uVar2 << 2);
    }
    else {
      iVar7 = _realloc(*piVar9,uVar2 << 2);
    }
    if (iVar7 == 0) {
      iVar7 = param_1[9];
      if (iVar7 == 0) {
        iVar7 = 1;
        param_1[9] = 1;
      }
      puVar4 = (undefined4 *)0x0;
      if (iVar7 != 0) {
        return iVar7;
      }
      goto LAB_0003fe80;
    }
    *piVar9 = iVar7;
    param_1[0xc] = uVar2;
    iVar7 = param_1[0xb];
  }
  param_1[0xb] = iVar8 + iVar7;
  puVar4 = (undefined4 *)(iVar7 * 4 + *piVar9);
LAB_0003fe80:
  *puVar4 = *param_3;
  if (uVar6 == 0) {
    iVar7 = 1;
  }
  else {
    iVar7 = 3;
    puVar4[1] = param_3[1];
    puVar4[2] = param_3[2];
  }
  if (uVar10 != 0) {
    puVar4 = puVar4 + iVar7;
    puVar5 = puVar4;
    do {
      *puVar5 = param_3[3];
      puVar5 = puVar5 + 2;
      puVar1 = param_3 + 6;
      param_3 = param_3 + 1;
      puVar4[1] = *puVar1;
      puVar4 = puVar4 + 2;
      uVar10 = uVar10 - 1;
    } while (uVar10 != 0);
  }
  return 0;
}

/* FUN_0003ff40 @ 0x3ff40 (592 bytes) */
int FUN_0003ff40(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  dword *pdVar6;
  dword *pdVar7;
  int *piVar8;
  int aiStack_48 [4];
  longlong lStack_38;
  float fStack_30;
  
  if ((param_3[3] & 0x3f0000) != 0x10000) {
    if (param_1[9] != 0) {
      return param_1[9];
    }
    param_1[9] = 2;
    return 2;
  }
  iVar5 = *param_1;
  iVar2 = (uint)*(ushort *)((int)param_3 + 0xe) * 8;
  iVar1 = iVar5 + *(int *)(iVar5 + 0x2c) * 8;
  uVar4 = *(uint *)(iVar1 + iVar2);
  if ((((uVar4 & 0x1f0000) == 0x110000) && ((uVar4 >> 0x1a & 7) < 2)) && ((param_3[6] & 7) < 4)) {
    aiStack_48[0] = param_1[9];
    fStack_30 = *(float *)(iVar5 + *(int *)(iVar5 + 0x6c) * 8 +
                          ((uint)*(ushort *)(iVar1 + iVar2 + 2) * 4 + (param_3[6] & 7)) * 4);
  }
  else {
    aiStack_48[0] = param_1[9];
    if (aiStack_48[0] == 0) {
      aiStack_48[0] = 2;
      param_1[9] = 2;
    }
    fStack_30 = 0.0;
  }
  if (aiStack_48[0] != 0) {
    return aiStack_48[0];
  }
  lStack_38 = (longlong)(int)fStack_30;
  ((int (*)())FUN_0003eea0)(param_1,(int)fStack_30,aiStack_48);
  param_3[3] = param_3[3] & 0xffc0ffff | 0x20000;
  *(short *)((int)param_3 + 0xe) = (short)aiStack_48[0];
  if (param_1[9] != 0) {
    return param_1[9];
  }
  piVar8 = param_1 + 10;
  iVar2 = param_1[0xb];
  uVar4 = param_1[0xc];
  if (uVar4 < iVar2 + 3U) {
    if (uVar4 == 0) {
      uVar4 = 0x10;
    }
    else {
      uVar4 = uVar4 << 1;
    }
    for (; uVar4 < iVar2 + 3U; uVar4 = uVar4 << 1) {
    }
    if (*piVar8 == 0) {
      iVar2 = _malloc(uVar4 << 2);
    }
    else {
      iVar2 = _realloc(*piVar8,uVar4 << 2);
    }
    if (iVar2 == 0) {
      iVar2 = param_1[9];
      if (iVar2 == 0) {
        iVar2 = 1;
        param_1[9] = 1;
      }
      if (iVar2 != 0) {
        return iVar2;
      }
      puVar3 = (undefined4 *)0x0;
      pdVar7 = &MACH_HEADER.cputype;
      pdVar6 = &MACH_HEADER.cpusubtype;
      goto LAB_00040128;
    }
    *piVar8 = iVar2;
    param_1[0xc] = uVar4;
    iVar2 = param_1[0xb];
  }
  param_1[0xb] = iVar2 + 3;
  puVar3 = (undefined4 *)(iVar2 * 4 + *piVar8);
  pdVar7 = puVar3 + 1;
  pdVar6 = puVar3 + 2;
LAB_00040128:
  *puVar3 = *param_3;
  *pdVar7 = param_3[3];
  *pdVar6 = param_3[6];
  return 0;
}

/* FUN_000401b0 @ 0x401b0 (420 bytes) */
int FUN_000401b0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  uint uVar1;
  int iVar2;
  dword *pdVar3;
  dword *pdVar4;
  undefined4 *puVar5;
  dword *pdVar6;
  dword *pdVar7;
  int *piVar8;
  
  *(uint *)(*(int *)(param_1 + 0x34) + 0x20) =
       *(uint *)(*(int *)(param_1 + 0x34) + 0x20) | 0x1000000;
  if ((*(uint *)(*(int *)(param_1 + 0x34) + 0x20) & 0x800000) != 0) {
    uVar1 = param_3[6];
    param_3[6] = (uVar1 & 0xfffff777 ^ 0x8000) & 0x8000 |
                 (uVar1 & 0xffffff77 ^ 0x800) & 0x800 |
                 (uVar1 & 0xfffffff7 ^ 0x80) & 0x80 | (uVar1 ^ 8) & 8 | uVar1 & 0xffff7777;
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    return *(int *)(param_1 + 0x24);
  }
  piVar8 = (int *)(param_1 + 0x28);
  iVar2 = *(int *)(param_1 + 0x2c);
  uVar1 = *(uint *)(param_1 + 0x30);
  if (uVar1 < iVar2 + 5U) {
    if (uVar1 == 0) {
      uVar1 = 0x10;
    }
    else {
      uVar1 = uVar1 << 1;
    }
    for (; uVar1 < iVar2 + 5U; uVar1 = uVar1 << 1) {
    }
    if (*piVar8 == 0) {
      iVar2 = _malloc(uVar1 << 2);
    }
    else {
      iVar2 = _realloc(*piVar8,uVar1 << 2);
    }
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x24);
      if (iVar2 == 0) {
        iVar2 = 1;
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (iVar2 != 0) {
        return iVar2;
      }
      puVar5 = (undefined4 *)0x0;
      pdVar3 = &MACH_HEADER.cputype;
      pdVar4 = &MACH_HEADER.cpusubtype;
      pdVar6 = &MACH_HEADER.filetype;
      pdVar7 = &MACH_HEADER.ncmds;
      goto LAB_000402d0;
    }
    *piVar8 = iVar2;
    *(uint *)(param_1 + 0x30) = uVar1;
    iVar2 = *(int *)(param_1 + 0x2c);
  }
  *(int *)(param_1 + 0x2c) = iVar2 + 5;
  puVar5 = (undefined4 *)(iVar2 * 4 + *piVar8);
  pdVar3 = puVar5 + 1;
  pdVar4 = puVar5 + 2;
  pdVar6 = puVar5 + 3;
  pdVar7 = puVar5 + 4;
LAB_000402d0:
  *puVar5 = *param_3;
  *pdVar3 = param_3[1];
  *pdVar4 = param_3[2];
  *pdVar6 = param_3[3];
  *pdVar7 = param_3[6];
  return 0;
}

/* FUN_00040370 @ 0x40370 (4 bytes) */
int FUN_00040370(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  void *pvVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_r21;
  undefined4 unaff_r22;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  int *piVar10;
  
  uVar6 = 1;
  if ((param_1[5] & 0x20000000U) != 0) {
    uVar6 = (*(uint *)(param_2 * 8 + *param_1 + *(int *)(*param_1 + 0x54) * 8 + 4) >> 0x1a & 3) + 1;
  }
  uVar9 = param_3[6];
  if (1 < uVar6) {
    iVar4 = param_1[8];
    unaff_r22 = param_3[1];
    unaff_r21 = param_3[2];
    param_3[1] = 0x40000;
    *(short *)((int)param_3 + 6) = (short)iVar4;
    param_3[2] = 0x55;
    param_3[1] = param_3[1] | 0x400000;
  }
  uVar3 = uVar9 >> 3 & 1;
  puVar8 = param_3 + 6;
  param_3[6] = uVar3 << 0xf |
               (uVar9 & 7) << 0xc |
               uVar3 << 0xb |
               (uVar9 & 7) << 8 | uVar3 << 7 | (uVar9 & 7) << 4 | uVar3 << 3 | uVar9 & 0xffff0007;
  if (param_1[9] == 0) {
    piVar10 = param_1 + 10;
    iVar4 = param_1[0xb];
    uVar3 = param_1[0xc];
    if (uVar3 < iVar4 + 5U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar4 + 5U; uVar3 = uVar3 << 1) {
      }
      if ((void *)*piVar10 == (void *)0x0) {
        pvVar2 = _malloc(uVar3 << 2);
      }
      else {
        pvVar2 = _realloc((void *)*piVar10,uVar3 << 2);
      }
      if (pvVar2 == (void *)0x0) {
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        goto LAB_00040524;
      }
      *piVar10 = (int)pvVar2;
      param_1[0xc] = uVar3;
      iVar4 = param_1[0xb];
    }
    param_1[0xb] = iVar4 + 5;
    puVar1 = (undefined4 *)(iVar4 * 4 + *piVar10);
    *puVar1 = *param_3;
    puVar1[1] = param_3[1];
    puVar1[2] = param_3[2];
    puVar1[3] = param_3[3];
    puVar1[4] = param_3[6];
  }
LAB_00040524:
  if (1 >= uVar6) {
    return param_1[9];
  }
  uVar3 = uVar9 >> 4 & 7;
  uVar5 = uVar9 >> 7 & 1;
  puVar7 = param_3 + 2;
  param_3[2] = param_3[2] & 0xfffffffc;
  *puVar8 = uVar5 << 0xf |
            uVar3 << 0xc |
            uVar5 << 0xb |
            uVar3 << 8 | uVar5 << 7 | uVar3 << 4 | uVar5 << 3 | uVar3 | *puVar8 & 0xffff0000;
  if (param_1[9] == 0) {
    piVar10 = param_1 + 10;
    iVar4 = param_1[0xb];
    uVar3 = param_1[0xc];
    if (uVar3 < iVar4 + 5U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar4 + 5U; uVar3 = uVar3 << 1) {
      }
      if ((void *)*piVar10 == (void *)0x0) {
        pvVar2 = _malloc(uVar3 << 2);
      }
      else {
        pvVar2 = _realloc((void *)*piVar10,uVar3 << 2);
      }
      if (pvVar2 == (void *)0x0) {
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        goto LAB_00040664;
      }
      *piVar10 = (int)pvVar2;
      param_1[0xc] = uVar3;
      iVar4 = param_1[0xb];
    }
    param_1[0xb] = iVar4 + 5;
    puVar1 = (undefined4 *)(iVar4 * 4 + *piVar10);
    *puVar1 = *param_3;
    puVar1[1] = param_3[1];
    puVar1[2] = param_3[2];
    puVar1[3] = param_3[3];
    puVar1[4] = param_3[6];
  }
LAB_00040664:
  if (uVar6 < 3) goto LAB_000408d0;
  uVar3 = uVar9 >> 8 & 7;
  uVar5 = uVar9 >> 0xb & 1;
  *puVar7 = *puVar7 & 0xfffffff3;
  *puVar8 = uVar5 << 0xf |
            uVar3 << 0xc |
            uVar5 << 0xb |
            uVar3 << 8 | uVar5 << 7 | uVar3 << 4 | uVar5 << 3 | uVar3 | *puVar8 & 0xffff0000;
  if (param_1[9] == 0) {
    piVar10 = param_1 + 10;
    iVar4 = param_1[0xb];
    uVar3 = param_1[0xc];
    if (uVar3 < iVar4 + 5U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar4 + 5U; uVar3 = uVar3 << 1) {
      }
      if ((void *)*piVar10 == (void *)0x0) {
        pvVar2 = _malloc(uVar3 << 2);
      }
      else {
        pvVar2 = _realloc((void *)*piVar10,uVar3 << 2);
      }
      if (pvVar2 == (void *)0x0) {
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        goto LAB_00040794;
      }
      *piVar10 = (int)pvVar2;
      param_1[0xc] = uVar3;
      iVar4 = param_1[0xb];
    }
    param_1[0xb] = iVar4 + 5;
    puVar1 = (undefined4 *)(iVar4 * 4 + *piVar10);
    *puVar1 = *param_3;
    puVar1[1] = param_3[1];
    puVar1[2] = param_3[2];
    puVar1[3] = param_3[3];
    puVar1[4] = param_3[6];
  }
LAB_00040794:
  if (uVar6 == 4) {
    uVar6 = uVar9 >> 0xc & 7;
    uVar9 = uVar9 >> 0xf & 1;
    *puVar7 = *puVar7 & 0xffffffcf;
    *puVar8 = uVar9 << 0xf |
              uVar6 << 0xc |
              uVar9 << 0xb |
              uVar6 << 8 | uVar9 << 7 | uVar6 << 4 | uVar9 << 3 | uVar6 | *puVar8 & 0xffff0000;
    if (param_1[9] == 0) {
      piVar10 = param_1 + 10;
      iVar4 = param_1[0xb];
      uVar6 = param_1[0xc];
      if (uVar6 < iVar4 + 5U) {
        if (uVar6 == 0) {
          uVar6 = 0x10;
        }
        else {
          uVar6 = uVar6 << 1;
        }
        for (; uVar6 < iVar4 + 5U; uVar6 = uVar6 << 1) {
        }
        if ((void *)*piVar10 == (void *)0x0) {
          pvVar2 = _malloc(uVar6 << 2);
        }
        else {
          pvVar2 = _realloc((void *)*piVar10,uVar6 << 2);
        }
        if (pvVar2 == (void *)0x0) {
          if (param_1[9] == 0) {
            param_1[9] = 1;
          }
          goto LAB_000408d0;
        }
        *piVar10 = (int)pvVar2;
        param_1[0xc] = uVar6;
        iVar4 = param_1[0xb];
      }
      param_1[0xb] = iVar4 + 5;
      puVar1 = (undefined4 *)(iVar4 * 4 + *piVar10);
      *puVar1 = *param_3;
      puVar1[1] = param_3[1];
      puVar1[2] = param_3[2];
      puVar1[3] = param_3[3];
      puVar1[4] = param_3[6];
    }
  }
LAB_000408d0:
  iVar4 = param_1[8];
  param_3[3] = 0;
  *puVar8 = 0;
  param_3[3] = param_3[3] & 0xffc0ffff | 0x40000;
  *(short *)((int)param_3 + 0xe) = (short)iVar4;
  param_3[3] = param_3[3] | 0x400000;
  *puVar8 = *puVar8 & 0xffff0000 | 0x3210;
  *param_3 = 0;
  param_3[1] = unaff_r22;
  param_3[2] = unaff_r21;
  *(undefined2 *)((int)param_3 + 2) = 0x47;
  iVar4 = param_1[9];
  if (iVar4 == 0) {
    piVar10 = param_1 + 10;
    iVar4 = param_1[0xb];
    uVar6 = param_1[0xc];
    if (uVar6 < iVar4 + 5U) {
      if (uVar6 == 0) {
        uVar6 = 0x10;
      }
      else {
        uVar6 = uVar6 << 1;
      }
      for (; uVar6 < iVar4 + 5U; uVar6 = uVar6 << 1) {
      }
      if ((void *)*piVar10 == (void *)0x0) {
        pvVar2 = _malloc(uVar6 << 2);
      }
      else {
        pvVar2 = _realloc((void *)*piVar10,uVar6 << 2);
      }
      if (pvVar2 == (void *)0x0) {
        if (param_1[9] != 0) {
          return param_1[9];
        }
        param_1[9] = 1;
        return 1;
      }
      *piVar10 = (int)pvVar2;
      param_1[0xc] = uVar6;
      iVar4 = param_1[0xb];
    }
    param_1[0xb] = iVar4 + 5;
    puVar1 = (undefined4 *)(iVar4 * 4 + *piVar10);
    *puVar1 = *param_3;
    puVar1[1] = param_3[1];
    puVar1[2] = param_3[2];
    puVar1[3] = param_3[3];
    puVar1[4] = param_3[6];
    iVar4 = param_1[9];
  }
  return iVar4;
}

/* FUN_00040374 @ 0x40374 (1800 bytes) */
int FUN_00040374(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  int param_2;
  undefined4 *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_r21;
  undefined4 unaff_r22;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  int *piVar9;
  
  uVar5 = 1;
  if ((param_1[5] & 0x20000000U) != 0) {
    uVar5 = (*(uint *)(param_2 * 8 + *param_1 + *(int *)(*param_1 + 0x54) * 8 + 4) >> 0x1a & 3) + 1;
  }
  uVar8 = param_3[6];
  if (1 < uVar5) {
    iVar3 = param_1[8];
    unaff_r22 = param_3[1];
    unaff_r21 = param_3[2];
    param_3[1] = 0x40000;
    *(short *)((int)param_3 + 6) = (short)iVar3;
    param_3[2] = 0x55;
    param_3[1] = param_3[1] | 0x400000;
  }
  uVar2 = uVar8 >> 3 & 1;
  puVar7 = param_3 + 6;
  param_3[6] = uVar2 << 0xf |
               (uVar8 & 7) << 0xc |
               uVar2 << 0xb |
               (uVar8 & 7) << 8 | uVar2 << 7 | (uVar8 & 7) << 4 | uVar2 << 3 | uVar8 & 0xffff0007;
  if (param_1[9] == 0) {
    piVar9 = param_1 + 10;
    iVar3 = param_1[0xb];
    uVar2 = param_1[0xc];
    if (uVar2 < iVar3 + 5U) {
      if (uVar2 == 0) {
        uVar2 = 0x10;
      }
      else {
        uVar2 = uVar2 << 1;
      }
      for (; uVar2 < iVar3 + 5U; uVar2 = uVar2 << 1) {
      }
      if (*piVar9 == 0) {
        iVar3 = _malloc(uVar2 << 2);
      }
      else {
        iVar3 = _realloc(*piVar9,uVar2 << 2);
      }
      if (iVar3 == 0) {
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        goto LAB_00040524;
      }
      *piVar9 = iVar3;
      param_1[0xc] = uVar2;
      iVar3 = param_1[0xb];
    }
    param_1[0xb] = iVar3 + 5;
    puVar1 = (undefined4 *)(iVar3 * 4 + *piVar9);
    *puVar1 = *param_3;
    puVar1[1] = param_3[1];
    puVar1[2] = param_3[2];
    puVar1[3] = param_3[3];
    puVar1[4] = param_3[6];
  }
LAB_00040524:
  if (1 >= uVar5) {
    return param_1[9];
  }
  uVar2 = uVar8 >> 4 & 7;
  uVar4 = uVar8 >> 7 & 1;
  puVar6 = param_3 + 2;
  param_3[2] = param_3[2] & 0xfffffffc;
  *puVar7 = uVar4 << 0xf |
            uVar2 << 0xc |
            uVar4 << 0xb |
            uVar2 << 8 | uVar4 << 7 | uVar2 << 4 | uVar4 << 3 | uVar2 | *puVar7 & 0xffff0000;
  if (param_1[9] == 0) {
    piVar9 = param_1 + 10;
    iVar3 = param_1[0xb];
    uVar2 = param_1[0xc];
    if (uVar2 < iVar3 + 5U) {
      if (uVar2 == 0) {
        uVar2 = 0x10;
      }
      else {
        uVar2 = uVar2 << 1;
      }
      for (; uVar2 < iVar3 + 5U; uVar2 = uVar2 << 1) {
      }
      if (*piVar9 == 0) {
        iVar3 = _malloc(uVar2 << 2);
      }
      else {
        iVar3 = _realloc(*piVar9,uVar2 << 2);
      }
      if (iVar3 == 0) {
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        goto LAB_00040664;
      }
      *piVar9 = iVar3;
      param_1[0xc] = uVar2;
      iVar3 = param_1[0xb];
    }
    param_1[0xb] = iVar3 + 5;
    puVar1 = (undefined4 *)(iVar3 * 4 + *piVar9);
    *puVar1 = *param_3;
    puVar1[1] = param_3[1];
    puVar1[2] = param_3[2];
    puVar1[3] = param_3[3];
    puVar1[4] = param_3[6];
  }
LAB_00040664:
  if (uVar5 < 3) goto LAB_000408d0;
  uVar2 = uVar8 >> 8 & 7;
  uVar4 = uVar8 >> 0xb & 1;
  *puVar6 = *puVar6 & 0xfffffff3;
  *puVar7 = uVar4 << 0xf |
            uVar2 << 0xc |
            uVar4 << 0xb |
            uVar2 << 8 | uVar4 << 7 | uVar2 << 4 | uVar4 << 3 | uVar2 | *puVar7 & 0xffff0000;
  if (param_1[9] == 0) {
    piVar9 = param_1 + 10;
    iVar3 = param_1[0xb];
    uVar2 = param_1[0xc];
    if (uVar2 < iVar3 + 5U) {
      if (uVar2 == 0) {
        uVar2 = 0x10;
      }
      else {
        uVar2 = uVar2 << 1;
      }
      for (; uVar2 < iVar3 + 5U; uVar2 = uVar2 << 1) {
      }
      if (*piVar9 == 0) {
        iVar3 = _malloc(uVar2 << 2);
      }
      else {
        iVar3 = _realloc(*piVar9,uVar2 << 2);
      }
      if (iVar3 == 0) {
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        goto LAB_00040794;
      }
      *piVar9 = iVar3;
      param_1[0xc] = uVar2;
      iVar3 = param_1[0xb];
    }
    param_1[0xb] = iVar3 + 5;
    puVar1 = (undefined4 *)(iVar3 * 4 + *piVar9);
    *puVar1 = *param_3;
    puVar1[1] = param_3[1];
    puVar1[2] = param_3[2];
    puVar1[3] = param_3[3];
    puVar1[4] = param_3[6];
  }
LAB_00040794:
  if (uVar5 == 4) {
    uVar5 = uVar8 >> 0xc & 7;
    uVar8 = uVar8 >> 0xf & 1;
    *puVar6 = *puVar6 & 0xffffffcf;
    *puVar7 = uVar8 << 0xf |
              uVar5 << 0xc |
              uVar8 << 0xb |
              uVar5 << 8 | uVar8 << 7 | uVar5 << 4 | uVar8 << 3 | uVar5 | *puVar7 & 0xffff0000;
    if (param_1[9] == 0) {
      piVar9 = param_1 + 10;
      iVar3 = param_1[0xb];
      uVar5 = param_1[0xc];
      if (uVar5 < iVar3 + 5U) {
        if (uVar5 == 0) {
          uVar5 = 0x10;
        }
        else {
          uVar5 = uVar5 << 1;
        }
        for (; uVar5 < iVar3 + 5U; uVar5 = uVar5 << 1) {
        }
        if (*piVar9 == 0) {
          iVar3 = _malloc(uVar5 << 2);
        }
        else {
          iVar3 = _realloc(*piVar9,uVar5 << 2);
        }
        if (iVar3 == 0) {
          if (param_1[9] == 0) {
            param_1[9] = 1;
          }
          goto LAB_000408d0;
        }
        *piVar9 = iVar3;
        param_1[0xc] = uVar5;
        iVar3 = param_1[0xb];
      }
      param_1[0xb] = iVar3 + 5;
      puVar1 = (undefined4 *)(iVar3 * 4 + *piVar9);
      *puVar1 = *param_3;
      puVar1[1] = param_3[1];
      puVar1[2] = param_3[2];
      puVar1[3] = param_3[3];
      puVar1[4] = param_3[6];
    }
  }
LAB_000408d0:
  iVar3 = param_1[8];
  param_3[3] = 0;
  *puVar7 = 0;
  param_3[3] = param_3[3] & 0xffc0ffff | 0x40000;
  *(short *)((int)param_3 + 0xe) = (short)iVar3;
  param_3[3] = param_3[3] | 0x400000;
  *puVar7 = *puVar7 & 0xffff0000 | 0x3210;
  *param_3 = 0;
  param_3[1] = unaff_r22;
  param_3[2] = unaff_r21;
  *(undefined2 *)((int)param_3 + 2) = 0x47;
  iVar3 = param_1[9];
  if (iVar3 == 0) {
    piVar9 = param_1 + 10;
    iVar3 = param_1[0xb];
    uVar5 = param_1[0xc];
    if (uVar5 < iVar3 + 5U) {
      if (uVar5 == 0) {
        uVar5 = 0x10;
      }
      else {
        uVar5 = uVar5 << 1;
      }
      for (; uVar5 < iVar3 + 5U; uVar5 = uVar5 << 1) {
      }
      if (*piVar9 == 0) {
        iVar3 = _malloc(uVar5 << 2);
      }
      else {
        iVar3 = _realloc(*piVar9,uVar5 << 2);
      }
      if (iVar3 == 0) {
        if (param_1[9] != 0) {
          return param_1[9];
        }
        param_1[9] = 1;
        return 1;
      }
      *piVar9 = iVar3;
      param_1[0xc] = uVar5;
      iVar3 = param_1[0xb];
    }
    param_1[0xb] = iVar3 + 5;
    puVar1 = (undefined4 *)(iVar3 * 4 + *piVar9);
    *puVar1 = *param_3;
    puVar1[1] = param_3[1];
    puVar1[2] = param_3[2];
    puVar1[3] = param_3[3];
    puVar1[4] = param_3[6];
    iVar3 = param_1[9];
  }
  return iVar3;
}

/* FUN_00040ac4 @ 0x40ac4 (2096 bytes) */
int FUN_00040ac4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  int param_2;
  undefined4 *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 unaff_r19;
  undefined4 unaff_r20;
  uint uVar11;
  uint *puVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  uint uVar16;
  int *piVar17;
  
  uVar11 = 1;
  if ((param_1[5] & 0x20000000U) != 0) {
    uVar11 = (*(uint *)(param_2 * 8 + *param_1 + *(int *)(*param_1 + 0x54) * 8 + 4) >> 0x1a & 3) + 1
    ;
  }
  uVar16 = param_3[6];
  uVar15 = param_3[7];
  if (uVar11 >= 2) {
    iVar7 = param_1[8];
    unaff_r20 = param_3[1];
    unaff_r19 = param_3[2];
    param_3[1] = 0x40000;
    *(short *)((int)param_3 + 6) = (short)iVar7;
    param_3[2] = 0x55;
    param_3[1] = param_3[1] | 0x400000;
  }
  uVar4 = uVar16 >> 3 & 1;
  uVar8 = uVar15 >> 3 & 1;
  puVar14 = param_3 + 6;
  puVar13 = param_3 + 7;
  param_3[6] = uVar4 << 0xf |
               (uVar16 & 7) << 0xc |
               uVar4 << 0xb |
               (uVar16 & 7) << 8 | uVar4 << 7 | (uVar16 & 7) << 4 | uVar4 << 3 | uVar16 & 0xffff0007
  ;
  param_3[7] = uVar8 << 0xf |
               (uVar15 & 7) << 0xc |
               uVar8 << 0xb |
               (uVar15 & 7) << 8 | uVar8 << 7 | (uVar15 & 7) << 4 | uVar8 << 3 | uVar15 & 0xffff0007
  ;
  if (param_1[9] == 0) {
    piVar17 = param_1 + 10;
    iVar7 = param_1[0xb];
    uVar4 = param_1[0xc];
    if (uVar4 < iVar7 + 7U) {
      if (uVar4 == 0) {
        uVar4 = 0x10;
      }
      else {
        uVar4 = uVar4 << 1;
      }
      for (; uVar4 < iVar7 + 7U; uVar4 = uVar4 << 1) {
      }
      if (*piVar17 == 0) {
        iVar7 = _malloc(uVar4 << 2);
      }
      else {
        iVar7 = _realloc(*piVar17,uVar4 << 2);
      }
      if (iVar7 == 0) {
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        goto LAB_00040cf0;
      }
      *piVar17 = iVar7;
      param_1[0xc] = uVar4;
      iVar7 = param_1[0xb];
    }
    iVar3 = 0;
    param_1[0xb] = iVar7 + 7;
    puVar10 = (undefined4 *)(iVar7 * 4 + *piVar17);
    *puVar10 = *param_3;
    puVar10[1] = param_3[1];
    puVar10[2] = param_3[2];
    puVar6 = param_3;
    do {
      bVar2 = iVar3 != 1;
      iVar3 = iVar3 + 1;
      puVar10[3] = puVar6[3];
      puVar1 = puVar6 + 6;
      puVar6 = puVar6 + 1;
      puVar10[4] = *puVar1;
      puVar10 = puVar10 + 2;
    } while (bVar2);
  }
LAB_00040cf0:
  if (uVar11 < 2) {
    return param_1[9];
  }
  uVar8 = uVar16 >> 4 & 7;
  uVar9 = uVar16 >> 7 & 1;
  uVar5 = uVar15 >> 4 & 7;
  uVar4 = uVar15 >> 7 & 1;
  puVar12 = param_3 + 2;
  param_3[2] = param_3[2] & 0xfffffffc;
  *puVar14 = uVar9 << 0xf |
             uVar8 << 0xc |
             uVar9 << 0xb |
             uVar8 << 8 | uVar9 << 7 | uVar8 << 4 | uVar9 << 3 | uVar8 | *puVar14 & 0xffff0000;
  *puVar13 = uVar4 << 0xf |
             uVar5 << 0xc |
             uVar4 << 0xb |
             uVar5 << 8 | uVar4 << 7 | uVar5 << 4 | uVar4 << 3 | uVar5 | *puVar13 & 0xffff0000;
  if (param_1[9] == 0) {
    piVar17 = param_1 + 10;
    iVar7 = param_1[0xb];
    uVar4 = param_1[0xc];
    if (uVar4 < iVar7 + 7U) {
      if (uVar4 == 0) {
        uVar4 = 0x10;
      }
      else {
        uVar4 = uVar4 << 1;
      }
      for (; uVar4 < iVar7 + 7U; uVar4 = uVar4 << 1) {
      }
      if (*piVar17 == 0) {
        iVar7 = _malloc(uVar4 << 2);
      }
      else {
        iVar7 = _realloc(*piVar17,uVar4 << 2);
      }
      if (iVar7 == 0) {
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        goto LAB_00040e70;
      }
      *piVar17 = iVar7;
      param_1[0xc] = uVar4;
      iVar7 = param_1[0xb];
    }
    iVar3 = 0;
    param_1[0xb] = iVar7 + 7;
    puVar10 = (undefined4 *)(iVar7 * 4 + *piVar17);
    *puVar10 = *param_3;
    puVar10[1] = param_3[1];
    puVar10[2] = param_3[2];
    puVar6 = param_3;
    do {
      bVar2 = iVar3 != 1;
      iVar3 = iVar3 + 1;
      puVar10[3] = puVar6[3];
      puVar1 = puVar6 + 6;
      puVar6 = puVar6 + 1;
      puVar10[4] = *puVar1;
      puVar10 = puVar10 + 2;
    } while (bVar2);
  }
LAB_00040e70:
  if (uVar11 < 3) goto LAB_00041170;
  uVar8 = uVar16 >> 8 & 7;
  uVar9 = uVar16 >> 0xb & 1;
  uVar5 = uVar15 >> 8 & 7;
  uVar4 = uVar15 >> 0xb & 1;
  *puVar12 = *puVar12 & 0xfffffff3;
  *puVar14 = uVar9 << 0xf |
             uVar8 << 0xc |
             uVar9 << 0xb |
             uVar8 << 8 | uVar9 << 7 | uVar8 << 4 | uVar9 << 3 | uVar8 | *puVar14 & 0xffff0000;
  *puVar13 = uVar4 << 0xf |
             uVar5 << 0xc |
             uVar4 << 0xb |
             uVar5 << 8 | uVar4 << 7 | uVar5 << 4 | uVar4 << 3 | uVar5 | *puVar13 & 0xffff0000;
  if (param_1[9] == 0) {
    piVar17 = param_1 + 10;
    iVar7 = param_1[0xb];
    uVar4 = param_1[0xc];
    if (uVar4 < iVar7 + 7U) {
      if (uVar4 == 0) {
        uVar4 = 0x10;
      }
      else {
        uVar4 = uVar4 << 1;
      }
      for (; uVar4 < iVar7 + 7U; uVar4 = uVar4 << 1) {
      }
      if (*piVar17 == 0) {
        iVar7 = _malloc(uVar4 << 2);
      }
      else {
        iVar7 = _realloc(*piVar17,uVar4 << 2);
      }
      if (iVar7 == 0) {
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        goto LAB_00040ff0;
      }
      *piVar17 = iVar7;
      param_1[0xc] = uVar4;
      iVar7 = param_1[0xb];
    }
    iVar3 = 0;
    param_1[0xb] = iVar7 + 7;
    puVar10 = (undefined4 *)(iVar7 * 4 + *piVar17);
    *puVar10 = *param_3;
    puVar10[1] = param_3[1];
    puVar10[2] = param_3[2];
    puVar6 = param_3;
    do {
      bVar2 = iVar3 != 1;
      iVar3 = iVar3 + 1;
      puVar10[3] = puVar6[3];
      puVar1 = puVar6 + 6;
      puVar6 = puVar6 + 1;
      puVar10[4] = *puVar1;
      puVar10 = puVar10 + 2;
    } while (bVar2);
  }
LAB_00040ff0:
  if (uVar11 == 4) {
    uVar4 = uVar16 >> 0xc & 7;
    uVar8 = uVar16 >> 0xf & 1;
    uVar16 = uVar15 >> 0xc & 7;
    uVar11 = uVar15 >> 0xf & 1;
    *puVar12 = *puVar12 & 0xffffffcf;
    *puVar14 = uVar8 << 0xf |
               uVar4 << 0xc |
               uVar8 << 0xb |
               uVar4 << 8 | uVar8 << 7 | uVar4 << 4 | uVar8 << 3 | uVar4 | *puVar14 & 0xffff0000;
    *puVar13 = uVar11 << 0xf |
               uVar16 << 0xc |
               uVar11 << 0xb |
               uVar16 << 8 |
               uVar11 << 7 | uVar16 << 4 | uVar11 << 3 | uVar16 | *puVar13 & 0xffff0000;
    if (param_1[9] == 0) {
      piVar17 = param_1 + 10;
      iVar7 = param_1[0xb];
      uVar11 = param_1[0xc];
      if (uVar11 < iVar7 + 7U) {
        if (uVar11 == 0) {
          uVar11 = 0x10;
        }
        else {
          uVar11 = uVar11 << 1;
        }
        for (; uVar11 < iVar7 + 7U; uVar11 = uVar11 << 1) {
        }
        if (*piVar17 == 0) {
          iVar7 = _malloc(uVar11 << 2);
        }
        else {
          iVar7 = _realloc(*piVar17,uVar11 << 2);
        }
        if (iVar7 == 0) {
          if (param_1[9] == 0) {
            param_1[9] = 1;
          }
          goto LAB_00041170;
        }
        *piVar17 = iVar7;
        param_1[0xc] = uVar11;
        iVar7 = param_1[0xb];
      }
      iVar3 = 0;
      param_1[0xb] = iVar7 + 7;
      puVar10 = (undefined4 *)(iVar7 * 4 + *piVar17);
      *puVar10 = *param_3;
      puVar10[1] = param_3[1];
      puVar10[2] = param_3[2];
      puVar6 = param_3;
      do {
        bVar2 = iVar3 != 1;
        iVar3 = iVar3 + 1;
        puVar10[3] = puVar6[3];
        puVar1 = puVar6 + 6;
        puVar6 = puVar6 + 1;
        puVar10[4] = *puVar1;
        puVar10 = puVar10 + 2;
      } while (bVar2);
    }
  }
LAB_00041170:
  iVar7 = param_1[8];
  param_3[3] = 0;
  *puVar14 = 0;
  param_3[3] = param_3[3] & 0xffc0ffff | 0x40000;
  *(short *)((int)param_3 + 0xe) = (short)iVar7;
  param_3[3] = param_3[3] | 0x400000;
  *puVar14 = *puVar14 & 0xffff0000 | 0x3210;
  *param_3 = 0;
  param_3[1] = unaff_r20;
  param_3[2] = unaff_r19;
  *(undefined2 *)((int)param_3 + 2) = 0x47;
  iVar7 = param_1[9];
  if (iVar7 == 0) {
    piVar17 = param_1 + 10;
    iVar7 = param_1[0xb];
    uVar11 = param_1[0xc];
    if (uVar11 < iVar7 + 5U) {
      if (uVar11 == 0) {
        uVar11 = 0x10;
      }
      else {
        uVar11 = uVar11 << 1;
      }
      for (; uVar11 < iVar7 + 5U; uVar11 = uVar11 << 1) {
      }
      if (*piVar17 == 0) {
        iVar7 = _malloc(uVar11 << 2);
      }
      else {
        iVar7 = _realloc(*piVar17,uVar11 << 2);
      }
      if (iVar7 == 0) {
        if (param_1[9] != 0) {
          return param_1[9];
        }
        param_1[9] = 1;
        return 1;
      }
      *piVar17 = iVar7;
      param_1[0xc] = uVar11;
      iVar7 = param_1[0xb];
    }
    param_1[0xb] = iVar7 + 5;
    puVar10 = (undefined4 *)(iVar7 * 4 + *piVar17);
    *puVar10 = *param_3;
    puVar10[1] = param_3[1];
    puVar10[2] = param_3[2];
    puVar10[3] = param_3[3];
    puVar10[4] = param_3[6];
    iVar7 = param_1[9];
  }
  return iVar7;
}

/* FUN_00041310 @ 0x41310 (488 bytes) */
int FUN_00041310(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_40;
  
  _memcpy(&uStack_58,param_3,0x24);
  uVar5 = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_3 + 0x18) = 0;
  uVar2 = (undefined2)uVar5;
  *(undefined4 *)(param_3 + 0xc) = 0x40000;
  *(undefined2 *)(param_3 + 0xe) = uVar2;
  uStack_50 = 0x55;
  uStack_54 = CONCAT22(4,uVar2);
  uStack_58 = 0x4d;
  *(uint *)(param_3 + 0x18) = *(uint *)(param_3 + 0x18) & 0xffff0000 | 0x3210;
  *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) | 0x400000;
  uStack_54 = uStack_54 | 0x400000;
  if (*(int *)(param_1 + 0x24) == 0) {
    piVar6 = (int *)(param_1 + 0x28);
    iVar4 = *(int *)(param_1 + 0x2c);
    uVar3 = *(uint *)(param_1 + 0x30);
    if (uVar3 < iVar4 + 5U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar4 + 5U; uVar3 = uVar3 << 1) {
      }
      if (*piVar6 == 0) {
        iVar4 = _malloc(uVar3 << 2);
      }
      else {
        iVar4 = _realloc(*piVar6,uVar3 << 2);
      }
      if (iVar4 == 0) {
        if (*(int *)(param_1 + 0x24) == 0) {
          *(undefined4 *)(param_1 + 0x24) = 1;
        }
        goto LAB_000414c0;
      }
      *piVar6 = iVar4;
      *(uint *)(param_1 + 0x30) = uVar3;
      iVar4 = *(int *)(param_1 + 0x2c);
    }
    *(int *)(param_1 + 0x2c) = iVar4 + 5;
    puVar1 = (undefined4 *)(iVar4 * 4 + *piVar6);
    *puVar1 = uStack_58;
    puVar1[1] = uStack_54;
    puVar1[2] = uStack_50;
    puVar1[3] = uStack_4c;
    puVar1[4] = uStack_40;
  }
LAB_000414c0:
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  ((int (*)())FUN_00040370)(param_1,param_2,param_3);
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
  return *(undefined4 *)(param_1 + 0x24);
}

/* FUN_00041510 @ 0x41510 (548 bytes) */
int FUN_00041510(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  undefined4 *param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  dword *pdVar5;
  dword *pdVar6;
  undefined4 uVar7;
  int *piVar8;
  uint uVar9;
  
  iVar3 = (param_2 + *(int *)(*param_1 + 0x54)) * 8;
  uVar9 = *(uint *)(iVar3 + *param_1);
  ((int (*)())FUN_0003eca0)(param_1,iVar3,param_3,param_4,param_5,param_6,param_7);
  uVar7 = *(undefined4 *)(*param_1 + 0x28);
  param_3[7] = 0;
  param_3[4] = 0x10000;
  *(short *)((int)param_3 + 0x12) = (short)uVar7;
  uVar9 = *(uint *)(&UNK_001aa574 + (2 - ((int)-(uVar9 & 0x3fc0000 ^ 0x580000) >> 0x1f)) * 4);
  param_3[4] = param_3[4] | 0x400000;
  param_3[7] = (uVar9 & 7) << 0xc |
               (uVar9 & 7) << 8 | (uVar9 & 7) << 4 | uVar9 & 7 | param_3[7] & 0xffff0000;
  if (param_1[9] != 0) {
    return param_1[9];
  }
  piVar8 = param_1 + 10;
  iVar3 = param_1[0xb];
  uVar9 = param_1[0xc];
  if (uVar9 < iVar3 + 7U) {
    if (uVar9 == 0) {
      uVar9 = 0x10;
    }
    else {
      uVar9 = uVar9 << 1;
    }
    for (; uVar9 < iVar3 + 7U; uVar9 = uVar9 << 1) {
    }
    if (*piVar8 == 0) {
      iVar3 = _malloc(uVar9 << 2);
    }
    else {
      iVar3 = _realloc(*piVar8,uVar9 << 2);
    }
    if (iVar3 == 0) {
      iVar3 = param_1[9];
      if (iVar3 == 0) {
        iVar3 = 1;
        param_1[9] = 1;
      }
      if (iVar3 != 0) {
        return iVar3;
      }
      puVar4 = (undefined4 *)0x0;
      pdVar5 = &MACH_HEADER.cputype;
      pdVar6 = &MACH_HEADER.cpusubtype;
      goto LAB_00041698;
    }
    *piVar8 = iVar3;
    param_1[0xc] = uVar9;
    iVar3 = param_1[0xb];
  }
  param_1[0xb] = iVar3 + 7;
  puVar4 = (undefined4 *)(iVar3 * 4 + *piVar8);
  pdVar5 = puVar4 + 1;
  pdVar6 = puVar4 + 2;
LAB_00041698:
  iVar3 = 0;
  *puVar4 = *param_3;
  *pdVar5 = param_3[1];
  *pdVar6 = param_3[2];
  do {
    bVar2 = iVar3 != 1;
    iVar3 = iVar3 + 1;
    puVar4[3] = param_3[3];
    puVar1 = param_3 + 6;
    param_3 = param_3 + 1;
    puVar4[4] = *puVar1;
    puVar4 = puVar4 + 2;
  } while (bVar2);
  return 0;
}

/* FUN_00041750 @ 0x41750 (1160 bytes) */
int FUN_00041750(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined **ppuVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined2 uVar5;
  dword *pdVar6;
  int iVar7;
  undefined4 *puVar8;
  dword *pdVar9;
  undefined **ppuVar10;
  int *piVar11;
  undefined4 uStack_58;
  undefined4 uStack_54;
  dword dStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined *puStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  
  _memset(&uStack_58,0,0x24);
  iVar7 = *(int *)(param_1 + 0x24);
  uVar5 = (undefined2)*(undefined4 *)(param_1 + 0x20);
  uStack_54 = CONCAT22(4,uVar5);
  uStack_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_58) + 0)),0x20);
  dStack_50 = 0x55;
  uStack_4c = *(undefined **)(param_3 + 0xc);
  puStack_40 = *(undefined **)(param_3 + 0x18);
  uStack_48 = *(undefined4 *)(param_3 + 0x10);
  uStack_3c = *(undefined4 *)(param_3 + 0x1c);
  uStack_54 = uStack_54 | 0x400000;
  if (iVar7 == 0) {
    piVar11 = (int *)(param_1 + 0x28);
    iVar7 = *(int *)(param_1 + 0x2c);
    uVar3 = *(uint *)(param_1 + 0x30);
    if (uVar3 < iVar7 + 7U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar7 + 7U; uVar3 = uVar3 << 1) {
      }
      if (*piVar11 == 0) {
        iVar7 = _malloc(uVar3 << 2);
      }
      else {
        iVar7 = _realloc(*piVar11,uVar3 << 2);
      }
      if (iVar7 == 0) {
        iVar7 = *(int *)(param_1 + 0x24);
        if (iVar7 == 0) {
          iVar7 = 1;
          *(undefined4 *)(param_1 + 0x24) = 1;
        }
        uVar5 = (undefined2)*(undefined4 *)(param_1 + 0x20);
        goto LAB_000418f0;
      }
      *piVar11 = iVar7;
      *(uint *)(param_1 + 0x30) = uVar3;
      iVar7 = *(int *)(param_1 + 0x2c);
    }
    puVar8 = &uStack_4c;
    *(int *)(param_1 + 0x2c) = iVar7 + 7;
    puVar4 = (undefined4 *)(iVar7 * 4 + *piVar11);
    *puVar4 = uStack_58;
    puVar4[1] = uStack_54;
    puVar4[2] = dStack_50;
    do {
      puVar4[3] = *puVar8;
      puVar1 = puVar8 + 3;
      puVar8 = puVar8 + 1;
      puVar4[4] = *puVar1;
      puVar4 = puVar4 + 2;
    } while (&uStack_44 != puVar8);
    uVar5 = (undefined2)*(undefined4 *)(param_1 + 0x20);
    iVar7 = *(int *)(param_1 + 0x24);
  }
LAB_000418f0:
  uStack_4c = (undefined *)CONCAT22(4,uVar5);
  uStack_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_58) + 0)),0x30);
  puStack_40 = ((unsigned char *)0x00003210);
  uStack_4c = (undefined *)((uint)uStack_4c | 0x400000);
  if (iVar7 == 0) {
    piVar11 = (int *)(param_1 + 0x28);
    iVar7 = *(int *)(param_1 + 0x2c);
    uVar3 = *(uint *)(param_1 + 0x30);
    if (uVar3 < iVar7 + 5U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar7 + 5U; uVar3 = uVar3 << 1) {
      }
      if (*piVar11 == 0) {
        iVar7 = _malloc(uVar3 << 2);
      }
      else {
        iVar7 = _realloc(*piVar11,uVar3 << 2);
      }
      if (iVar7 == 0) {
        iVar7 = *(int *)(param_1 + 0x24);
        if (iVar7 == 0) {
          iVar7 = 1;
          *(undefined4 *)(param_1 + 0x24) = 1;
        }
        goto LAB_00041a08;
      }
      *piVar11 = iVar7;
      *(uint *)(param_1 + 0x30) = uVar3;
      iVar7 = *(int *)(param_1 + 0x2c);
    }
    *(int *)(param_1 + 0x2c) = iVar7 + 5;
    puVar4 = (undefined4 *)(iVar7 * 4 + *piVar11);
    *puVar4 = uStack_58;
    puVar4[1] = uStack_54;
    puVar4[2] = dStack_50;
    puVar4[3] = uStack_4c;
    puVar4[4] = puStack_40;
    iVar7 = *(int *)(param_1 + 0x24);
  }
LAB_00041a08:
  uVar3 = *(uint *)(param_3 + 0x1c);
  dStack_50 = *(dword *)(param_3 + 8);
  uStack_54 = *(dword *)(param_3 + 4);
  uStack_48 = *(undefined4 *)(param_3 + 0x10);
  uStack_44 = *(undefined4 *)(param_3 + 0xc);
  uStack_38 = *(undefined4 *)(param_3 + 0x18);
  uStack_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_58) + 0)),0x40);
  uStack_3c = (uVar3 & 0xfffff777 ^ 0x8000) & 0x8000 |
              (uVar3 & 0xffffff77 ^ 0x800) & 0x800 |
              (uVar3 & 0xfffffff7 ^ 0x80) & 0x80 | (uVar3 ^ 8) & 8 | uVar3 & 0xffff7777;
  if (iVar7 != 0) {
    return iVar7;
  }
  piVar11 = (int *)(param_1 + 0x28);
  iVar7 = *(int *)(param_1 + 0x2c);
  uVar3 = *(uint *)(param_1 + 0x30);
  if (uVar3 < iVar7 + 9U) {
    if (uVar3 == 0) {
      uVar3 = 0x10;
    }
    else {
      uVar3 = uVar3 << 1;
    }
    for (; uVar3 < iVar7 + 9U; uVar3 = uVar3 << 1) {
    }
    if (*piVar11 == 0) {
      iVar7 = _malloc(uVar3 << 2);
    }
    else {
      iVar7 = _realloc(*piVar11,uVar3 << 2);
    }
    if (iVar7 == 0) {
      iVar7 = *(int *)(param_1 + 0x24);
      if (iVar7 == 0) {
        iVar7 = 1;
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (iVar7 != 0) {
        return iVar7;
      }
      puVar4 = (undefined4 *)0x0;
      pdVar6 = &MACH_HEADER.cputype;
      pdVar9 = &MACH_HEADER.cpusubtype;
      goto LAB_00041b48;
    }
    *piVar11 = iVar7;
    *(uint *)(param_1 + 0x30) = uVar3;
    iVar7 = *(int *)(param_1 + 0x2c);
  }
  *(int *)(param_1 + 0x2c) = iVar7 + 9;
  puVar4 = (undefined4 *)(iVar7 * 4 + *piVar11);
  pdVar6 = puVar4 + 1;
  pdVar9 = puVar4 + 2;
LAB_00041b48:
  ppuVar10 = (undefined **)&uStack_4c;
  *puVar4 = uStack_58;
  *pdVar6 = uStack_54;
  *pdVar9 = dStack_50;
  do {
    puVar4[3] = *ppuVar10;
    ppuVar2 = ppuVar10 + 3;
    ppuVar10 = ppuVar10 + 1;
    puVar4[4] = *ppuVar2;
    puVar4 = puVar4 + 2;
  } while (&puStack_40 != ppuVar10);
  return 0;
}

/* FUN_00041c00 @ 0x41c00 (4544 bytes) */
int FUN_00041c00(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  undefined4 *puVar1;
  uint *puVar2;
  undefined **ppuVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 uVar7;
  uint uVar8;
  undefined *puVar9;
  char *pcVar10;
  undefined **ppuVar11;
  undefined4 uVar12;
  uint *puVar13;
  short sVar17;
  undefined4 *puVar14;
  undefined **ppuVar15;
  uint *puVar16;
  undefined4 *puVar18;
  int iVar19;
  int *piVar20;
  undefined4 uStack_68;
  undefined4 uStack_64;
  uint uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined *apuStack_50 [11];
  
  if ((*(uint *)((param_2 + *(int *)(*param_1 + 0x54)) * 8 + *param_1) & 0xe0000000) == 0x20000000)
  {
    *(undefined4 *)(param_3 + 0x10) = 0x40000;
    *(undefined2 *)(param_3 + 0x12) = 0;
    *(undefined **)(param_3 + 0x1c) = ((unsigned char *)0x00005555);
    *(uint *)(param_3 + 0x10) = *(uint *)(param_3 + 0x10) | 0x400000;
  }
  _memset(&uStack_68,0,0x24);
  iVar19 = param_1[8];
  iVar6 = param_1[9];
  uStack_64 = CONCAT22(4,(short)iVar19);
  uStack_68 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_68) + 0)),0x5b);
  uVar8 = *(uint *)(param_3 + 0x10);
  uStack_60 = 0x55;
  apuStack_50[0] = (undefined *)(*(uint *)(param_3 + 0x18) & 0xffff7777 | 0x100000);
  apuStack_50[1] = (undefined *)(*(uint *)(param_3 + 0x1c) & 0xffff7777 | 0x100000);
  uStack_5c = *(undefined **)(param_3 + 0xc);
  uStack_58 = (undefined *)uVar8;
  uStack_64 = uStack_64 | 0x400000;
  if (iVar6 == 0) {
    piVar20 = param_1 + 10;
    iVar6 = param_1[0xb];
    uVar5 = param_1[0xc];
    if (uVar5 < iVar6 + 7U) {
      if (uVar5 == 0) {
        uVar5 = 0x10;
      }
      else {
        uVar5 = uVar5 << 1;
      }
      for (; uVar5 < iVar6 + 7U; uVar5 = uVar5 << 1) {
      }
      if (*piVar20 == 0) {
        iVar6 = _malloc(uVar5 << 2);
      }
      else {
        iVar6 = _realloc(*piVar20,uVar5 << 2);
      }
      if (iVar6 == 0) {
        iVar6 = param_1[9];
        if (iVar6 == 0) {
          iVar6 = 1;
          param_1[9] = 1;
        }
        iVar19 = param_1[8];
        goto LAB_00041e30;
      }
      *piVar20 = iVar6;
      param_1[0xc] = uVar5;
      iVar6 = param_1[0xb];
    }
    puVar14 = &uStack_5c;
    param_1[0xb] = iVar6 + 7;
    puVar18 = (undefined4 *)(iVar6 * 4 + *piVar20);
    *puVar18 = uStack_68;
    puVar18[1] = uStack_64;
    puVar18[2] = uStack_60;
    do {
      puVar18[3] = *puVar14;
      puVar1 = puVar14 + 3;
      puVar14 = puVar14 + 1;
      puVar18[4] = *puVar1;
      puVar18 = puVar18 + 2;
    } while (&uStack_54 != puVar14);
    iVar19 = param_1[8];
    iVar6 = param_1[9];
  }
LAB_00041e30:
  puVar4 = apuStack_50;
  uStack_54 = (uint *)uStack_58;
  puVar9 = uStack_5c;
  uStack_68 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_68) + 0)),0xd);
  uStack_64 = CONCAT22(4,(short)iVar19 + 1);
  uStack_5c = (undefined *)CONCAT22(4,(short)iVar19);
  uStack_58 = puVar9;
  uStack_60 = 0x55;
  apuStack_50[2] = apuStack_50[1];
  apuStack_50[0] = ((unsigned char *)0x00003210);
  apuStack_50[1] = puVar4;
  uStack_68 = uStack_68 & 0xc000ffff | 0x30000;
  uStack_64 = uStack_64 | 0x400000;
  uStack_5c = (undefined *)((uint)uStack_5c | 0x400000);
  if (iVar6 == 0) {
    piVar20 = param_1 + 10;
    iVar6 = param_1[0xb];
    uVar5 = param_1[0xc];
    if (uVar5 < iVar6 + 9U) {
      if (uVar5 == 0) {
        uVar5 = 0x10;
      }
      else {
        uVar5 = uVar5 << 1;
      }
      for (; uVar5 < iVar6 + 9U; uVar5 = uVar5 << 1) {
      }
      if (*piVar20 == 0) {
        iVar6 = _malloc(uVar5 << 2);
      }
      else {
        iVar6 = _realloc(*piVar20,uVar5 << 2);
      }
      if (iVar6 == 0) {
        iVar6 = param_1[9];
        if (iVar6 == 0) {
          iVar6 = 1;
          param_1[9] = 1;
        }
        iVar19 = param_1[8];
        goto LAB_00042000;
      }
      *piVar20 = iVar6;
      param_1[0xc] = uVar5;
      iVar6 = param_1[0xb];
    }
    ppuVar11 = (undefined **)&uStack_5c;
    param_1[0xb] = iVar6 + 9;
    puVar13 = (uint *)(iVar6 * 4 + *piVar20);
    *puVar13 = uStack_68;
    puVar13[1] = uStack_64;
    puVar13[2] = uStack_60;
    do {
      puVar13[3] = (uint)*ppuVar11;
      ppuVar15 = ppuVar11 + 3;
      ppuVar11 = ppuVar11 + 1;
      puVar13[4] = (uint)*ppuVar15;
      puVar13 = puVar13 + 2;
    } while (apuStack_50 != ppuVar11);
    iVar19 = param_1[8];
    iVar6 = param_1[9];
  }
LAB_00042000:
  uStack_5c = (undefined *)CONCAT22(4,(short)iVar19);
  uStack_64 = CONCAT22(4,(short)iVar19 + 2);
  uStack_68 = uStack_68 & 0xc000ffff | 0x40000;
  uStack_60 = 0x55;
  apuStack_50[0] = ((unsigned char *)0x00003210);
  uStack_64 = uStack_64 | 0x400000;
  uStack_5c = (undefined *)((uint)uStack_5c | 0x400000);
  if (iVar6 == 0) {
    piVar20 = param_1 + 10;
    iVar6 = param_1[0xb];
    uVar5 = param_1[0xc];
    if (uVar5 < iVar6 + 9U) {
      if (uVar5 == 0) {
        uVar5 = 0x10;
      }
      else {
        uVar5 = uVar5 << 1;
      }
      for (; uVar5 < iVar6 + 9U; uVar5 = uVar5 << 1) {
      }
      if (*piVar20 == 0) {
        iVar6 = _malloc(uVar5 << 2);
      }
      else {
        iVar6 = _realloc(*piVar20,uVar5 << 2);
      }
      if (iVar6 == 0) {
        iVar6 = param_1[9];
        if (iVar6 == 0) {
          iVar6 = 1;
          param_1[9] = 1;
        }
        iVar19 = param_1[8];
        goto LAB_000421a0;
      }
      *piVar20 = iVar6;
      param_1[0xc] = uVar5;
      iVar6 = param_1[0xb];
    }
    ppuVar11 = (undefined **)&uStack_5c;
    param_1[0xb] = iVar6 + 9;
    puVar13 = (uint *)(iVar6 * 4 + *piVar20);
    *puVar13 = uStack_68;
    puVar13[1] = uStack_64;
    puVar13[2] = uStack_60;
    do {
      puVar13[3] = (uint)*ppuVar11;
      ppuVar15 = ppuVar11 + 3;
      ppuVar11 = ppuVar11 + 1;
      puVar13[4] = (uint)*ppuVar15;
      puVar13 = puVar13 + 2;
    } while (apuStack_50 != ppuVar11);
    iVar19 = param_1[8];
    iVar6 = param_1[9];
  }
LAB_000421a0:
  sVar17 = (short)iVar19 + 1;
  uStack_68 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_68) + 0)),0x20);
  uStack_5c = (undefined *)CONCAT22(4,(short)iVar19 + 2);
  uStack_64 = CONCAT22(4,sVar17);
  uStack_58 = (undefined *)CONCAT22(4,sVar17);
  pcVar10 = (*(GhidraMachOSection *)0x00000054).sectname + 1;
  uStack_60 = 0x55;
  apuStack_50[0] = ((unsigned char *)0x00003210);
  apuStack_50[1] = ((unsigned char *)0x00003210);
  uStack_68 = uStack_68 & 0xc000ffff;
  uStack_64 = uStack_64 | 0x400000;
  uStack_5c = (undefined *)((uint)uStack_5c | 0x400000);
  uStack_58 = (undefined *)((uint)uStack_58 | 0x400000);
  if (iVar6 == 0) {
    piVar20 = param_1 + 10;
    iVar6 = param_1[0xb];
    uVar5 = param_1[0xc];
    if (uVar5 < iVar6 + 7U) {
      if (uVar5 == 0) {
        uVar5 = 0x10;
      }
      else {
        uVar5 = uVar5 << 1;
      }
      for (; uVar5 < iVar6 + 7U; uVar5 = uVar5 << 1) {
      }
      if (*piVar20 == 0) {
        iVar6 = _malloc(uVar5 << 2);
      }
      else {
        iVar6 = _realloc(*piVar20,uVar5 << 2);
      }
      if (iVar6 != 0) {
        *piVar20 = iVar6;
        param_1[0xc] = uVar5;
        iVar6 = param_1[0xb];
        goto LAB_000422f0;
      }
      if (param_1[9] == 0) {
        param_1[9] = 1;
      }
    }
    else {
LAB_000422f0:
      puVar16 = &uStack_5c;
      pcVar10 = (char *)&uStack_54;
      param_1[0xb] = iVar6 + 7;
      puVar13 = (uint *)(iVar6 * 4 + *piVar20);
      *puVar13 = uStack_68;
      puVar13[1] = uStack_64;
      puVar13[2] = uStack_60;
      do {
        puVar13[3] = *puVar16;
        puVar2 = puVar16 + 3;
        puVar16 = puVar16 + 1;
        puVar13[4] = *puVar2;
        puVar13 = puVar13 + 2;
      } while ((uint *)pcVar10 != puVar16);
    }
    iVar19 = param_1[8];
  }
  uStack_5c = (undefined *)CONCAT22(4,(short)iVar19 + 1);
  param_1[8] = iVar19 + 3;
  (*(unsigned short *)((unsigned char *)&(uStack_68) + 2)) = 5;
  uVar12 = 0xffff7777;
  apuStack_50[0] = ((unsigned char *)0x00003210);
  uStack_5c = (undefined *)((uint)uStack_5c | 0x400000);
  ((int (*)())FUN_00040370)(param_1,param_2,&uStack_68);
  uVar7 = 0x24;
  param_1[8] = param_1[8] + -3;
  _memset(&uStack_68,0,0x24);
  uStack_68 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_68) + 0)),0x5b);
  ((int (*)())FUN_0003eca0)(param_1,extraout_r4,uVar7,uVar8,puVar9,pcVar10,uVar12);
  sVar17 = (short)param_1[8];
  uStack_58 = (undefined *)CONCAT22(4,sVar17 + 1);
  uStack_64 = CONCAT22(4,sVar17 + 2);
  uStack_5c = (undefined *)CONCAT22(1,(short)*(undefined4 *)(*param_1 + 0x28));
  iVar6 = param_1[9];
  apuStack_50[1] = ((unsigned char *)0x00003210);
  uStack_60 = 0x55;
  uStack_64 = uStack_64 | 0x400000;
  uStack_58 = (undefined *)((uint)uStack_58 | 0x400000);
  uStack_5c = (undefined *)((uint)uStack_5c | 0x400000);
  apuStack_50[0] = ((unsigned char *)0x00001111);
  uVar7 = extraout_r4_00;
  if (iVar6 == 0) {
    piVar20 = param_1 + 10;
    iVar6 = param_1[0xb];
    uVar8 = param_1[0xc];
    if (uVar8 < iVar6 + 7U) {
      if (uVar8 == 0) {
        uVar8 = 0x10;
      }
      else {
        uVar8 = uVar8 << 1;
      }
      for (; uVar8 < iVar6 + 7U; uVar8 = uVar8 << 1) {
      }
      if (*piVar20 == 0) {
        iVar6 = _malloc(uVar8 << 2);
        uVar7 = extraout_r4_01;
      }
      else {
        iVar6 = _realloc(*piVar20,uVar8 << 2);
        uVar7 = extraout_r4_02;
      }
      if (iVar6 == 0) {
        iVar6 = param_1[9];
        if (iVar6 == 0) {
          iVar6 = 1;
          param_1[9] = 1;
        }
        sVar17 = (short)param_1[8];
        goto LAB_00042600;
      }
      *piVar20 = iVar6;
      param_1[0xc] = uVar8;
      iVar6 = param_1[0xb];
    }
    puVar14 = &uStack_5c;
    param_1[0xb] = iVar6 + 7;
    puVar18 = (undefined4 *)(iVar6 * 4 + *piVar20);
    *puVar18 = uStack_68;
    puVar18[1] = uStack_64;
    puVar18[2] = uStack_60;
    do {
      puVar18[3] = *puVar14;
      puVar1 = puVar14 + 3;
      puVar14 = puVar14 + 1;
      puVar18[4] = *puVar1;
      puVar18 = puVar18 + 2;
    } while (&uStack_54 != puVar14);
    sVar17 = (short)param_1[8];
    iVar6 = param_1[9];
  }
LAB_00042600:
  uStack_68 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_68) + 0)),0xd);
  uStack_5c = (undefined *)CONCAT22(4,sVar17);
  uStack_58 = (undefined *)CONCAT22(4,sVar17 + 2);
  uStack_64 = CONCAT22(4,sVar17 + 1);
  uStack_54 = (uint *)CONCAT22(4,sVar17 + 1);
  uVar12 = 0x55;
  puVar9 = ((unsigned char *)0x00003210);
  ppuVar11 = (undefined **)((unsigned char *)0x00003210);
  uStack_60 = 0x55;
  apuStack_50[2] = ((unsigned char *)0x00003210);
  apuStack_50[1] = ((unsigned char *)0x00003210);
  apuStack_50[0] = ((unsigned char *)0x00003210);
  uStack_68 = uStack_68 & 0xc000ffff | 0x30000;
  uStack_64 = uStack_64 | 0x400000;
  uStack_5c = (undefined *)((uint)uStack_5c | 0x400000);
  uStack_58 = (undefined *)((uint)uStack_58 | 0x400000);
  puVar13 = (uint *)((uint)uStack_54 | 0x400000);
  uStack_54 = puVar13;
  if (iVar6 == 0) {
    piVar20 = param_1 + 10;
    puVar13 = (uint *)param_1[0xb];
    uVar8 = param_1[0xc];
    if (uVar8 < (int)puVar13 + 9U) {
      if (uVar8 == 0) {
        uVar8 = 0x10;
      }
      else {
        uVar8 = uVar8 << 1;
      }
      for (; uVar8 < (int)puVar13 + 9U; uVar8 = uVar8 << 1) {
      }
      if (*piVar20 == 0) {
        iVar6 = _malloc(uVar8 << 2);
        uVar7 = extraout_r4_03;
      }
      else {
        iVar6 = _realloc(*piVar20,uVar8 << 2);
        uVar7 = extraout_r4_04;
      }
      if (iVar6 == 0) {
        if (param_1[9] == 0) {
          param_1[9] = 1;
        }
        goto LAB_00042800;
      }
      *piVar20 = iVar6;
      param_1[0xc] = uVar8;
      puVar13 = (uint *)param_1[0xb];
    }
    ppuVar15 = (undefined **)&uStack_5c;
    ppuVar11 = apuStack_50;
    param_1[0xb] = (int)puVar13 + 9;
    puVar13 = (uint *)((int)puVar13 * 4 + *piVar20);
    *puVar13 = uStack_68;
    puVar13[1] = uStack_64;
    puVar13[2] = uStack_60;
    puVar16 = puVar13;
    do {
      puVar16[3] = (uint)*ppuVar15;
      ppuVar3 = ppuVar15 + 3;
      ppuVar15 = ppuVar15 + 1;
      puVar16[4] = (uint)*ppuVar3;
      puVar16 = puVar16 + 2;
    } while (ppuVar11 != ppuVar15);
  }
LAB_00042800:
  uStack_68 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_68) + 0)),0x5b);
  uStack_68 = uStack_68 & 0xc000ffff;
  ((int (*)())FUN_0003eca0)(param_1,uVar7,uStack_68,uVar12,puVar9,ppuVar11,puVar13);
  sVar17 = (short)param_1[8];
  uStack_5c = (undefined *)CONCAT22(1,(short)*(undefined4 *)(*param_1 + 0x28));
  uStack_64 = CONCAT22(4,sVar17 + 2);
  uStack_58 = (undefined *)CONCAT22(4,sVar17 + 1);
  iVar6 = param_1[9];
  apuStack_50[0] = (undefined *)0x0;
  apuStack_50[1] = ((unsigned char *)0x00003210);
  uStack_60 = 0x55;
  uStack_5c = (undefined *)((uint)uStack_5c | 0x400000);
  uStack_64 = uStack_64 | 0x400000;
  uStack_58 = (undefined *)((uint)uStack_58 | 0x400000);
  if (iVar6 == 0) {
    piVar20 = param_1 + 10;
    iVar6 = param_1[0xb];
    uVar8 = param_1[0xc];
    if (uVar8 < iVar6 + 7U) {
      if (uVar8 == 0) {
        uVar8 = 0x10;
      }
      else {
        uVar8 = uVar8 << 1;
      }
      for (; uVar8 < iVar6 + 7U; uVar8 = uVar8 << 1) {
      }
      if (*piVar20 == 0) {
        iVar6 = _malloc(uVar8 << 2);
      }
      else {
        iVar6 = _realloc(*piVar20,uVar8 << 2);
      }
      if (iVar6 == 0) {
        iVar6 = param_1[9];
        if (iVar6 == 0) {
          iVar6 = 1;
          param_1[9] = 1;
        }
        sVar17 = (short)param_1[8];
        goto LAB_000429f0;
      }
      *piVar20 = iVar6;
      param_1[0xc] = uVar8;
      iVar6 = param_1[0xb];
    }
    puVar16 = &uStack_5c;
    param_1[0xb] = iVar6 + 7;
    puVar13 = (uint *)(iVar6 * 4 + *piVar20);
    *puVar13 = uStack_68;
    puVar13[1] = uStack_64;
    puVar13[2] = uStack_60;
    do {
      puVar13[3] = *puVar16;
      puVar2 = puVar16 + 3;
      puVar16 = puVar16 + 1;
      puVar13[4] = *puVar2;
      puVar13 = puVar13 + 2;
    } while (puVar16 != &uStack_54);
    sVar17 = (short)param_1[8];
    iVar6 = param_1[9];
  }
LAB_000429f0:
  uStack_68 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_68) + 0)),0xd);
  uStack_58 = (undefined *)CONCAT22(4,sVar17 + 2);
  uStack_54 = (uint *)CONCAT22(4,sVar17 + 1);
  uStack_64 = CONCAT22(4,sVar17 + 1);
  uStack_68 = uStack_68 & 0xc000ffff | 0x50000;
  uStack_60 = 0x55;
  apuStack_50[1] = ((unsigned char *)0x00003210);
  apuStack_50[2] = ((unsigned char *)0x00003210);
  uStack_5c = *(undefined **)(param_3 + 0x10);
  apuStack_50[0] = *(undefined **)(param_3 + 0x1c);
  uStack_64 = uStack_64 | 0x400000;
  uStack_58 = (undefined *)((uint)uStack_58 | 0x400000);
  uStack_54 = (uint *)((uint)uStack_54 | 0x400000);
  if (iVar6 == 0) {
    piVar20 = param_1 + 10;
    iVar6 = param_1[0xb];
    uVar8 = param_1[0xc];
    if (uVar8 < iVar6 + 9U) {
      if (uVar8 == 0) {
        uVar8 = 0x10;
      }
      else {
        uVar8 = uVar8 << 1;
      }
      for (; uVar8 < iVar6 + 9U; uVar8 = uVar8 << 1) {
      }
      if (*piVar20 == 0) {
        iVar6 = _malloc(uVar8 << 2);
      }
      else {
        iVar6 = _realloc(*piVar20,uVar8 << 2);
      }
      if (iVar6 == 0) {
        iVar6 = param_1[9];
        if (iVar6 == 0) {
          iVar6 = 1;
          param_1[9] = 1;
        }
        sVar17 = (short)param_1[8];
        goto LAB_00042bf0;
      }
      *piVar20 = iVar6;
      param_1[0xc] = uVar8;
      iVar6 = param_1[0xb];
    }
    ppuVar11 = (undefined **)&uStack_5c;
    param_1[0xb] = iVar6 + 9;
    puVar13 = (uint *)(iVar6 * 4 + *piVar20);
    *puVar13 = uStack_68;
    puVar13[1] = uStack_64;
    puVar13[2] = uStack_60;
    do {
      puVar13[3] = (uint)*ppuVar11;
      ppuVar15 = ppuVar11 + 3;
      ppuVar11 = ppuVar11 + 1;
      puVar13[4] = (uint)*ppuVar15;
      puVar13 = puVar13 + 2;
    } while (apuStack_50 != ppuVar11);
    sVar17 = (short)param_1[8];
    iVar6 = param_1[9];
  }
LAB_00042bf0:
  uStack_68 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_68) + 0)),0xd);
  uStack_54 = (uint *)CONCAT22(4,sVar17 + 1);
  uStack_58 = (undefined *)CONCAT22(4,sVar17 + 1);
  uStack_68 = uStack_68 & 0xc000ffff | 0x50000;
  uStack_60 = *(uint *)(param_3 + 8);
  uStack_64 = *(uint *)(param_3 + 4);
  apuStack_50[2] = ((unsigned char *)0x00003210);
  uStack_5c = *(undefined **)(param_3 + 0xc);
  apuStack_50[0] = *(undefined **)(param_3 + 0x18);
  uStack_58 = (undefined *)((uint)uStack_58 | 0x400000);
  uStack_54 = (uint *)((uint)uStack_54 | 0x400000);
  apuStack_50[1] = (undefined *)0xba98;
  if (iVar6 == 0) {
    piVar20 = param_1 + 10;
    iVar6 = param_1[0xb];
    uVar8 = param_1[0xc];
    if (uVar8 < iVar6 + 9U) {
      if (uVar8 == 0) {
        uVar8 = 0x10;
      }
      else {
        uVar8 = uVar8 << 1;
      }
      for (; uVar8 < iVar6 + 9U; uVar8 = uVar8 << 1) {
      }
      if (*piVar20 == 0) {
        iVar6 = _malloc(uVar8 << 2);
      }
      else {
        iVar6 = _realloc(*piVar20,uVar8 << 2);
      }
      if (iVar6 == 0) {
        if (param_1[9] != 0) {
          return param_1[9];
        }
        param_1[9] = 1;
        return 1;
      }
      *piVar20 = iVar6;
      param_1[0xc] = uVar8;
      iVar6 = param_1[0xb];
    }
    ppuVar11 = (undefined **)&uStack_5c;
    param_1[0xb] = iVar6 + 9;
    puVar13 = (uint *)(iVar6 * 4 + *piVar20);
    *puVar13 = uStack_68;
    puVar13[1] = uStack_64;
    puVar13[2] = uStack_60;
    do {
      puVar13[3] = (uint)*ppuVar11;
      ppuVar15 = ppuVar11 + 3;
      ppuVar11 = ppuVar11 + 1;
      puVar13[4] = (uint)*ppuVar15;
      puVar13 = puVar13 + 2;
    } while (apuStack_50 != ppuVar11);
    iVar6 = param_1[9];
  }
  return iVar6;
}

/* FUN_00042e00 @ 0x42e00 (4024 bytes) */
int FUN_00042e00(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 *puVar1;
  undefined **ppuVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined **ppuVar6;
  undefined4 *puVar7;
  uint *puVar8;
  int *piVar9;
  short sVar10;
  undefined4 uStack_58;
  undefined4 uStack_54;
  uint uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined *apuStack_40 [11];
  
  _memset(&uStack_58,0,0x24);
  iVar4 = *(int *)(param_1 + 0x24);
  sVar10 = (short)*(undefined4 *)(param_1 + 0x20);
  uStack_54 = CONCAT22(4,sVar10);
  uStack_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_58) + 0)),0x23);
  uStack_50 = 0x55;
  uStack_4c = *(undefined **)(param_3 + 0xc);
  apuStack_40[0] = *(undefined **)(param_3 + 0x18);
  uStack_48 = (undefined *)*(undefined4 *)(param_3 + 0x10);
  apuStack_40[1] = (undefined *)*(undefined4 *)(param_3 + 0x1c);
  uStack_54 = uStack_54 | 0x400000;
  if (iVar4 == 0) {
    piVar9 = (int *)(param_1 + 0x28);
    iVar4 = *(int *)(param_1 + 0x2c);
    uVar3 = *(uint *)(param_1 + 0x30);
    if (uVar3 < iVar4 + 7U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar4 + 7U; uVar3 = uVar3 << 1) {
      }
      if (*piVar9 == 0) {
        iVar4 = _malloc(uVar3 << 2);
      }
      else {
        iVar4 = _realloc(*piVar9,uVar3 << 2);
      }
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0x24);
        if (iVar4 == 0) {
          iVar4 = 1;
          *(undefined4 *)(param_1 + 0x24) = 1;
        }
        sVar10 = (short)*(undefined4 *)(param_1 + 0x20);
        goto LAB_00042fa0;
      }
      *piVar9 = iVar4;
      *(uint *)(param_1 + 0x30) = uVar3;
      iVar4 = *(int *)(param_1 + 0x2c);
    }
    puVar5 = &uStack_4c;
    *(int *)(param_1 + 0x2c) = iVar4 + 7;
    puVar7 = (undefined4 *)(iVar4 * 4 + *piVar9);
    *puVar7 = uStack_58;
    puVar7[1] = uStack_54;
    puVar7[2] = uStack_50;
    do {
      puVar7[3] = *puVar5;
      puVar1 = puVar5 + 3;
      puVar5 = puVar5 + 1;
      puVar7[4] = *puVar1;
      puVar7 = puVar7 + 2;
    } while (&uStack_44 != puVar5);
    sVar10 = (short)*(undefined4 *)(param_1 + 0x20);
    iVar4 = *(int *)(param_1 + 0x24);
  }
LAB_00042fa0:
  uStack_54 = CONCAT22(4,sVar10 + 1);
  uStack_4c = (undefined *)CONCAT22(4,sVar10);
  uStack_48 = (undefined *)CONCAT22(4,sVar10);
  uStack_50 = 0x55;
  apuStack_40[0] = ((unsigned char *)0x00003210);
  uStack_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_58) + 0)),0x40);
  apuStack_40[1] = ((unsigned char *)0x00003210);
  apuStack_40[2] = (undefined *)0xdddd;
  uStack_54 = uStack_54 | 0x400000;
  uStack_4c = (undefined *)((uint)uStack_4c | 0x400000);
  uStack_44 = 0x440000;
  uStack_48 = (undefined *)((uint)uStack_48 | 0x400000);
  if (iVar4 == 0) {
    piVar9 = (int *)(param_1 + 0x28);
    iVar4 = *(int *)(param_1 + 0x2c);
    uVar3 = *(uint *)(param_1 + 0x30);
    if (uVar3 < iVar4 + 9U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar4 + 9U; uVar3 = uVar3 << 1) {
      }
      if (*piVar9 == 0) {
        iVar4 = _malloc(uVar3 << 2);
      }
      else {
        iVar4 = _realloc(*piVar9,uVar3 << 2);
      }
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0x24);
        if (iVar4 == 0) {
          iVar4 = 1;
          *(undefined4 *)(param_1 + 0x24) = 1;
        }
        sVar10 = (short)*(undefined4 *)(param_1 + 0x20);
        goto LAB_000431b0;
      }
      *piVar9 = iVar4;
      *(uint *)(param_1 + 0x30) = uVar3;
      iVar4 = *(int *)(param_1 + 0x2c);
    }
    ppuVar6 = (undefined **)&uStack_4c;
    *(int *)(param_1 + 0x2c) = iVar4 + 9;
    puVar7 = (undefined4 *)(iVar4 * 4 + *piVar9);
    *puVar7 = uStack_58;
    puVar7[1] = uStack_54;
    puVar7[2] = uStack_50;
    do {
      puVar7[3] = *ppuVar6;
      ppuVar2 = ppuVar6 + 3;
      ppuVar6 = ppuVar6 + 1;
      puVar7[4] = *ppuVar2;
      puVar7 = puVar7 + 2;
    } while (apuStack_40 != ppuVar6);
    sVar10 = (short)*(undefined4 *)(param_1 + 0x20);
    iVar4 = *(int *)(param_1 + 0x24);
  }
LAB_000431b0:
  uStack_54 = CONCAT22(4,sVar10 + 2);
  uStack_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_58) + 0)),0x49);
  uStack_50 = 0x55;
  uStack_48 = *(undefined **)(param_3 + 0x14);
  apuStack_40[1] = *(undefined **)(param_3 + 0x20);
  uStack_4c = *(undefined **)(param_3 + 0x14);
  apuStack_40[0] = *(undefined **)(param_3 + 0x20);
  uStack_54 = uStack_54 | 0x400000;
  if (iVar4 == 0) {
    piVar9 = (int *)(param_1 + 0x28);
    iVar4 = *(int *)(param_1 + 0x2c);
    uVar3 = *(uint *)(param_1 + 0x30);
    if (uVar3 < iVar4 + 7U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar4 + 7U; uVar3 = uVar3 << 1) {
      }
      if (*piVar9 == 0) {
        iVar4 = _malloc(uVar3 << 2);
      }
      else {
        iVar4 = _realloc(*piVar9,uVar3 << 2);
      }
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0x24);
        if (iVar4 == 0) {
          iVar4 = 1;
          *(undefined4 *)(param_1 + 0x24) = 1;
        }
        sVar10 = (short)*(undefined4 *)(param_1 + 0x20);
        goto LAB_00043320;
      }
      *piVar9 = iVar4;
      *(uint *)(param_1 + 0x30) = uVar3;
      iVar4 = *(int *)(param_1 + 0x2c);
    }
    puVar5 = &uStack_4c;
    *(int *)(param_1 + 0x2c) = iVar4 + 7;
    puVar7 = (undefined4 *)(iVar4 * 4 + *piVar9);
    *puVar7 = uStack_58;
    puVar7[1] = uStack_54;
    puVar7[2] = uStack_50;
    do {
      puVar7[3] = *puVar5;
      puVar1 = puVar5 + 3;
      puVar5 = puVar5 + 1;
      puVar7[4] = *puVar1;
      puVar7 = puVar7 + 2;
    } while (&uStack_44 != puVar5);
    sVar10 = (short)*(undefined4 *)(param_1 + 0x20);
    iVar4 = *(int *)(param_1 + 0x24);
  }
LAB_00043320:
  uStack_54 = CONCAT22(4,sVar10 + 1);
  uStack_4c = (undefined *)CONCAT22(4,sVar10 + 2);
  uStack_48 = (undefined *)CONCAT22(4,sVar10 + 1);
  uStack_50 = 0x55;
  uStack_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_58) + 0)),0x40);
  apuStack_40[1] = ((unsigned char *)0x00003210);
  apuStack_40[0] = ((unsigned char *)0x00003210);
  uStack_54 = uStack_54 | 0x400000;
  uStack_4c = (undefined *)((uint)uStack_4c | 0x400000);
  uStack_48 = (undefined *)((uint)uStack_48 | 0x400000);
  apuStack_40[2] = ((unsigned char *)0x00005555);
  uStack_44 = 0x440000;
  if (iVar4 == 0) {
    piVar9 = (int *)(param_1 + 0x28);
    iVar4 = *(int *)(param_1 + 0x2c);
    uVar3 = *(uint *)(param_1 + 0x30);
    if (uVar3 < iVar4 + 9U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar4 + 9U; uVar3 = uVar3 << 1) {
      }
      if (*piVar9 == 0) {
        iVar4 = _malloc(uVar3 << 2);
      }
      else {
        iVar4 = _realloc(*piVar9,uVar3 << 2);
      }
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0x24);
        if (iVar4 == 0) {
          iVar4 = 1;
          *(undefined4 *)(param_1 + 0x24) = 1;
        }
        sVar10 = (short)*(undefined4 *)(param_1 + 0x20);
        goto LAB_00043510;
      }
      *piVar9 = iVar4;
      *(uint *)(param_1 + 0x30) = uVar3;
      iVar4 = *(int *)(param_1 + 0x2c);
    }
    ppuVar6 = (undefined **)&uStack_4c;
    *(int *)(param_1 + 0x2c) = iVar4 + 9;
    puVar7 = (undefined4 *)(iVar4 * 4 + *piVar9);
    *puVar7 = uStack_58;
    puVar7[1] = uStack_54;
    puVar7[2] = uStack_50;
    do {
      puVar7[3] = *ppuVar6;
      ppuVar2 = ppuVar6 + 3;
      ppuVar6 = ppuVar6 + 1;
      puVar7[4] = *ppuVar2;
      puVar7 = puVar7 + 2;
    } while (apuStack_40 != ppuVar6);
    sVar10 = (short)*(undefined4 *)(param_1 + 0x20);
    iVar4 = *(int *)(param_1 + 0x24);
  }
LAB_00043510:
  uStack_54 = CONCAT22(4,sVar10 + 2);
  uStack_4c = (undefined *)CONCAT22(4,sVar10 + 1);
  uStack_50 = 0x55;
  uStack_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_58) + 0)),0x5a);
  apuStack_40[0] = ((unsigned char *)0x00003210);
  uStack_54 = uStack_54 | 0x400000;
  uStack_4c = (undefined *)((uint)uStack_4c | 0x400000);
  if (iVar4 == 0) {
    piVar9 = (int *)(param_1 + 0x28);
    iVar4 = *(int *)(param_1 + 0x2c);
    uVar3 = *(uint *)(param_1 + 0x30);
    if (uVar3 < iVar4 + 5U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar4 + 5U; uVar3 = uVar3 << 1) {
      }
      if (*piVar9 == 0) {
        iVar4 = _malloc(uVar3 << 2);
      }
      else {
        iVar4 = _realloc(*piVar9,uVar3 << 2);
      }
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0x24);
        if (iVar4 == 0) {
          iVar4 = 1;
          *(undefined4 *)(param_1 + 0x24) = 1;
        }
        sVar10 = (short)*(undefined4 *)(param_1 + 0x20);
        goto LAB_00043670;
      }
      *piVar9 = iVar4;
      *(uint *)(param_1 + 0x30) = uVar3;
      iVar4 = *(int *)(param_1 + 0x2c);
    }
    *(int *)(param_1 + 0x2c) = iVar4 + 5;
    puVar7 = (undefined4 *)(iVar4 * 4 + *piVar9);
    *puVar7 = uStack_58;
    puVar7[1] = uStack_54;
    puVar7[2] = uStack_50;
    puVar7[3] = uStack_4c;
    puVar7[4] = apuStack_40[0];
    sVar10 = (short)*(undefined4 *)(param_1 + 0x20);
    iVar4 = *(int *)(param_1 + 0x24);
  }
LAB_00043670:
  uStack_54 = CONCAT22(4,sVar10 + 2);
  uStack_44 = CONCAT22(4,sVar10 + 2);
  uStack_48 = (undefined *)CONCAT22(4,sVar10);
  uStack_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_58) + 0)),0x40);
  uStack_54 = uStack_54 | 0x400000;
  uStack_50 = 0x55;
  apuStack_40[1] = ((unsigned char *)0x00003210);
  apuStack_40[2] = ((unsigned char *)0x00003210);
  uStack_4c = *(undefined **)(param_3 + 0x14);
  apuStack_40[0] = *(undefined **)(param_3 + 0x20);
  uStack_44 = uStack_44 | 0x400000;
  uStack_48 = (undefined *)((uint)uStack_48 | 0x400000);
  if (iVar4 == 0) {
    piVar9 = (int *)(param_1 + 0x28);
    iVar4 = *(int *)(param_1 + 0x2c);
    uVar3 = *(uint *)(param_1 + 0x30);
    if (uVar3 < iVar4 + 9U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar4 + 9U; uVar3 = uVar3 << 1) {
      }
      if (*piVar9 == 0) {
        iVar4 = _malloc(uVar3 << 2);
      }
      else {
        iVar4 = _realloc(*piVar9,uVar3 << 2);
      }
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0x24);
        if (iVar4 == 0) {
          iVar4 = 1;
          *(undefined4 *)(param_1 + 0x24) = 1;
        }
        sVar10 = (short)*(undefined4 *)(param_1 + 0x20);
        goto LAB_00043870;
      }
      *piVar9 = iVar4;
      *(uint *)(param_1 + 0x30) = uVar3;
      iVar4 = *(int *)(param_1 + 0x2c);
    }
    ppuVar6 = (undefined **)&uStack_4c;
    *(int *)(param_1 + 0x2c) = iVar4 + 9;
    puVar7 = (undefined4 *)(iVar4 * 4 + *piVar9);
    *puVar7 = uStack_58;
    puVar7[1] = uStack_54;
    puVar7[2] = uStack_50;
    do {
      puVar7[3] = *ppuVar6;
      ppuVar2 = ppuVar6 + 3;
      ppuVar6 = ppuVar6 + 1;
      puVar7[4] = *ppuVar2;
      puVar7 = puVar7 + 2;
    } while (apuStack_40 != ppuVar6);
    sVar10 = (short)*(undefined4 *)(param_1 + 0x20);
    iVar4 = *(int *)(param_1 + 0x24);
  }
LAB_00043870:
  uStack_54 = CONCAT22(4,sVar10 + 2);
  uStack_4c = (undefined *)CONCAT22(4,sVar10 + 2);
  uStack_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_58) + 0)),0x49);
  apuStack_40[0] = ((unsigned char *)0x00003210);
  uStack_50 = 0x55;
  uStack_54 = uStack_54 | 0x400000;
  uStack_48 = (undefined *)*(undefined4 *)(param_3 + 0x10);
  apuStack_40[1] = (undefined *)*(undefined4 *)(param_3 + 0x1c);
  uStack_4c = (undefined *)((uint)uStack_4c | 0x400000);
  if (iVar4 == 0) {
    piVar9 = (int *)(param_1 + 0x28);
    iVar4 = *(int *)(param_1 + 0x2c);
    uVar3 = *(uint *)(param_1 + 0x30);
    if (uVar3 < iVar4 + 7U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar4 + 7U; uVar3 = uVar3 << 1) {
      }
      if (*piVar9 == 0) {
        iVar4 = _malloc(uVar3 << 2);
      }
      else {
        iVar4 = _realloc(*piVar9,uVar3 << 2);
      }
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0x24);
        if (iVar4 == 0) {
          iVar4 = 1;
          *(undefined4 *)(param_1 + 0x24) = 1;
        }
        sVar10 = (short)*(undefined4 *)(param_1 + 0x20);
        goto LAB_00043a10;
      }
      *piVar9 = iVar4;
      *(uint *)(param_1 + 0x30) = uVar3;
      iVar4 = *(int *)(param_1 + 0x2c);
    }
    puVar5 = &uStack_4c;
    *(int *)(param_1 + 0x2c) = iVar4 + 7;
    puVar7 = (undefined4 *)(iVar4 * 4 + *piVar9);
    *puVar7 = uStack_58;
    puVar7[1] = uStack_54;
    puVar7[2] = uStack_50;
    do {
      puVar7[3] = *puVar5;
      puVar1 = puVar5 + 3;
      puVar5 = puVar5 + 1;
      puVar7[4] = *puVar1;
      puVar7 = puVar7 + 2;
    } while (puVar5 != &uStack_44);
    sVar10 = (short)*(undefined4 *)(param_1 + 0x20);
    iVar4 = *(int *)(param_1 + 0x24);
  }
LAB_00043a10:
  uStack_54 = CONCAT22(4,sVar10 + 2);
  uStack_44 = CONCAT22(4,sVar10 + 2);
  uStack_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_58) + 0)),0x40);
  uStack_50 = 0x55;
  uStack_54 = uStack_54 | 0x400000;
  apuStack_40[2] = (undefined *)0xba98;
  uStack_4c = *(undefined **)(param_3 + 0x14);
  apuStack_40[0] = *(undefined **)(param_3 + 0x20);
  uStack_48 = (undefined *)*(undefined4 *)(param_3 + 0xc);
  apuStack_40[1] = (undefined *)*(undefined4 *)(param_3 + 0x18);
  uStack_44 = uStack_44 | 0x400000;
  if (iVar4 == 0) {
    piVar9 = (int *)(param_1 + 0x28);
    iVar4 = *(int *)(param_1 + 0x2c);
    uVar3 = *(uint *)(param_1 + 0x30);
    if (uVar3 < iVar4 + 9U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar4 + 9U; uVar3 = uVar3 << 1) {
      }
      if (*piVar9 == 0) {
        iVar4 = _malloc(uVar3 << 2);
      }
      else {
        iVar4 = _realloc(*piVar9,uVar3 << 2);
      }
      if (iVar4 == 0) {
        iVar4 = *(int *)(param_1 + 0x24);
        if (iVar4 == 0) {
          iVar4 = 1;
          *(undefined4 *)(param_1 + 0x24) = 1;
        }
        sVar10 = (short)*(undefined4 *)(param_1 + 0x20);
        goto LAB_00043be0;
      }
      *piVar9 = iVar4;
      *(uint *)(param_1 + 0x30) = uVar3;
      iVar4 = *(int *)(param_1 + 0x2c);
    }
    ppuVar6 = (undefined **)&uStack_4c;
    *(int *)(param_1 + 0x2c) = iVar4 + 9;
    puVar7 = (undefined4 *)(iVar4 * 4 + *piVar9);
    *puVar7 = uStack_58;
    puVar7[1] = uStack_54;
    puVar7[2] = uStack_50;
    do {
      puVar7[3] = *ppuVar6;
      ppuVar2 = ppuVar6 + 3;
      ppuVar6 = ppuVar6 + 1;
      puVar7[4] = *ppuVar2;
      puVar7 = puVar7 + 2;
    } while (apuStack_40 != ppuVar6);
    sVar10 = (short)*(undefined4 *)(param_1 + 0x20);
    iVar4 = *(int *)(param_1 + 0x24);
  }
LAB_00043be0:
  uStack_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_58) + 0)),0xd);
  uStack_4c = (undefined *)CONCAT22(4,sVar10 + 1);
  uStack_44 = CONCAT22(4,sVar10 + 2);
  uStack_58 = uStack_58 & 0xc000ffff | 0x50000;
  uStack_50 = *(uint *)(param_3 + 8);
  uStack_54 = *(uint *)(param_3 + 4);
  apuStack_40[1] = ((unsigned char *)0x00004444);
  apuStack_40[0] = ((unsigned char *)0x00003210);
  apuStack_40[2] = ((unsigned char *)0x00003210);
  uStack_4c = (undefined *)((uint)uStack_4c | 0x400000);
  uStack_48 = (undefined *)0x440000;
  uStack_44 = uStack_44 | 0x400000;
  if (iVar4 == 0) {
    piVar9 = (int *)(param_1 + 0x28);
    iVar4 = *(int *)(param_1 + 0x2c);
    uVar3 = *(uint *)(param_1 + 0x30);
    if (uVar3 < iVar4 + 9U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar4 + 9U; uVar3 = uVar3 << 1) {
      }
      if (*piVar9 == 0) {
        iVar4 = _malloc(uVar3 << 2);
      }
      else {
        iVar4 = _realloc(*piVar9,uVar3 << 2);
      }
      if (iVar4 == 0) {
        if (*(int *)(param_1 + 0x24) != 0) {
          return *(int *)(param_1 + 0x24);
        }
        *(undefined4 *)(param_1 + 0x24) = 1;
        return 1;
      }
      *piVar9 = iVar4;
      *(uint *)(param_1 + 0x30) = uVar3;
      iVar4 = *(int *)(param_1 + 0x2c);
    }
    ppuVar6 = (undefined **)&uStack_4c;
    *(int *)(param_1 + 0x2c) = iVar4 + 9;
    puVar8 = (uint *)(iVar4 * 4 + *piVar9);
    *puVar8 = uStack_58;
    puVar8[1] = uStack_54;
    puVar8[2] = uStack_50;
    do {
      puVar8[3] = (uint)*ppuVar6;
      ppuVar2 = ppuVar6 + 3;
      ppuVar6 = ppuVar6 + 1;
      puVar8[4] = (uint)*ppuVar2;
      puVar8 = puVar8 + 2;
    } while (apuStack_40 != ppuVar6);
    iVar4 = *(int *)(param_1 + 0x24);
  }
  return iVar4;
}

/* FUN_00043df0 @ 0x43df0 (352 bytes) */
int FUN_00043df0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int *piVar9;
  
  uVar6 = param_3[5];
  uVar7 = param_3[8];
  param_3[5] = param_3[3];
  param_3[8] = param_3[6];
  param_3[3] = uVar6;
  param_3[6] = uVar7;
  iVar4 = *(int *)(param_1 + 0x24);
  if (iVar4 == 0) {
    piVar9 = (int *)(param_1 + 0x28);
    iVar4 = *(int *)(param_1 + 0x2c);
    uVar3 = *(uint *)(param_1 + 0x30);
    if (uVar3 < iVar4 + 9U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar4 + 9U; uVar3 = uVar3 << 1) {
      }
      if (*piVar9 == 0) {
        iVar4 = _malloc(uVar3 << 2);
      }
      else {
        iVar4 = _realloc(*piVar9,uVar3 << 2);
      }
      if (iVar4 == 0) {
        if (*(int *)(param_1 + 0x24) != 0) {
          return *(int *)(param_1 + 0x24);
        }
        *(undefined4 *)(param_1 + 0x24) = 1;
        return 1;
      }
      *piVar9 = iVar4;
      *(uint *)(param_1 + 0x30) = uVar3;
      iVar4 = *(int *)(param_1 + 0x2c);
    }
    iVar5 = 0;
    *(int *)(param_1 + 0x2c) = iVar4 + 9;
    puVar8 = (undefined4 *)(iVar4 * 4 + *piVar9);
    *puVar8 = *param_3;
    puVar8[1] = param_3[1];
    puVar8[2] = param_3[2];
    do {
      bVar2 = iVar5 != 2;
      iVar5 = iVar5 + 1;
      puVar8[3] = param_3[3];
      puVar1 = param_3 + 6;
      param_3 = param_3 + 1;
      puVar8[4] = *puVar1;
      puVar8 = puVar8 + 2;
    } while (bVar2);
    iVar4 = *(int *)(param_1 + 0x24);
  }
  return iVar4;
}

/* FUN_00043f60 @ 0x43f60 (996 bytes) */
int FUN_00043f60(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int *piVar11;
  
  if ((*(uint *)(param_1 + 0x14) & 0x20000000) == 0) {
    *(undefined2 *)((int)param_3 + 2) = 0x24;
    if (*(int *)(param_1 + 0x24) != 0) {
      return *(int *)(param_1 + 0x24);
    }
    piVar11 = (int *)(param_1 + 0x28);
    iVar4 = *(int *)(param_1 + 0x2c);
    uVar3 = *(uint *)(param_1 + 0x30);
    if (iVar4 + 7U <= uVar3) {
LAB_000442bc:
      iVar5 = 0;
      *(int *)(param_1 + 0x2c) = iVar4 + 7;
      puVar8 = (undefined4 *)(iVar4 * 4 + *piVar11);
      *puVar8 = *param_3;
      puVar8[1] = param_3[1];
      puVar8[2] = param_3[2];
      do {
        bVar2 = iVar5 != 1;
        iVar5 = iVar5 + 1;
        puVar8[3] = param_3[3];
        puVar6 = param_3 + 6;
        param_3 = param_3 + 1;
        puVar8[4] = *puVar6;
        puVar8 = puVar8 + 2;
      } while (bVar2);
      return *(int *)(param_1 + 0x24);
    }
    if (uVar3 == 0) {
      uVar3 = 0x10;
    }
    else {
      uVar3 = uVar3 << 1;
    }
    for (; uVar3 < iVar4 + 7U; uVar3 = uVar3 << 1) {
    }
    if (*piVar11 == 0) {
      iVar4 = _malloc(uVar3 << 2);
    }
    else {
      iVar4 = _realloc(*piVar11,uVar3 << 2);
    }
    if (iVar4 != 0) {
      *piVar11 = iVar4;
      *(uint *)(param_1 + 0x30) = uVar3;
      iVar4 = *(int *)(param_1 + 0x2c);
      goto LAB_000442bc;
    }
    goto LAB_0004432c;
  }
  uVar7 = *(undefined4 *)(param_1 + 0x20);
  uVar10 = param_3[1];
  uVar9 = param_3[2];
  param_3[1] = 0x40000;
  *(short *)((int)param_3 + 6) = (short)uVar7;
  param_3[2] = 0x55;
  param_3[1] = param_3[1] | 0x400000;
  if (*(int *)(param_1 + 0x24) == 0) {
    piVar11 = (int *)(param_1 + 0x28);
    iVar4 = *(int *)(param_1 + 0x2c);
    uVar3 = *(uint *)(param_1 + 0x30);
    if (uVar3 < iVar4 + 7U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar4 + 7U; uVar3 = uVar3 << 1) {
      }
      if (*piVar11 == 0) {
        iVar4 = _malloc(uVar3 << 2);
      }
      else {
        iVar4 = _realloc(*piVar11,uVar3 << 2);
      }
      if (iVar4 == 0) {
        if (*(int *)(param_1 + 0x24) == 0) {
          *(undefined4 *)(param_1 + 0x24) = 1;
        }
        goto LAB_000440e0;
      }
      *piVar11 = iVar4;
      *(uint *)(param_1 + 0x30) = uVar3;
      iVar4 = *(int *)(param_1 + 0x2c);
    }
    iVar5 = 0;
    *(int *)(param_1 + 0x2c) = iVar4 + 7;
    puVar8 = (undefined4 *)(iVar4 * 4 + *piVar11);
    *puVar8 = *param_3;
    puVar8[1] = param_3[1];
    puVar8[2] = param_3[2];
    puVar6 = param_3;
    do {
      bVar2 = iVar5 != 1;
      iVar5 = iVar5 + 1;
      puVar8[3] = puVar6[3];
      puVar1 = puVar6 + 6;
      puVar6 = puVar6 + 1;
      puVar8[4] = *puVar1;
      puVar8 = puVar8 + 2;
    } while (bVar2);
  }
LAB_000440e0:
  param_3[1] = uVar10;
  param_3[2] = uVar9;
  *param_3 = 0;
  *(undefined2 *)((int)param_3 + 2) = 0x38;
  uVar7 = *(undefined4 *)(param_1 + 0x20);
  param_3[3] = 0x40000;
  *(short *)((int)param_3 + 0xe) = (short)uVar7;
  param_3[6] = ((unsigned char *)0x00003210);
  param_3[3] = param_3[3] | 0x400000;
  if (*(int *)(param_1 + 0x24) != 0) {
    return *(int *)(param_1 + 0x24);
  }
  piVar11 = (int *)(param_1 + 0x28);
  iVar4 = *(int *)(param_1 + 0x2c);
  uVar3 = *(uint *)(param_1 + 0x30);
  if (uVar3 < iVar4 + 5U) {
    if (uVar3 == 0) {
      uVar3 = 0x10;
    }
    else {
      uVar3 = uVar3 << 1;
    }
    for (; uVar3 < iVar4 + 5U; uVar3 = uVar3 << 1) {
    }
    if (*piVar11 == 0) {
      iVar4 = _malloc(uVar3 << 2);
    }
    else {
      iVar4 = _realloc(*piVar11,uVar3 << 2);
    }
    if (iVar4 == 0) {
LAB_0004432c:
      if (*(int *)(param_1 + 0x24) == 0) {
        *(undefined4 *)(param_1 + 0x24) = 1;
        return 1;
      }
      return *(int *)(param_1 + 0x24);
    }
    *piVar11 = iVar4;
    *(uint *)(param_1 + 0x30) = uVar3;
    iVar4 = *(int *)(param_1 + 0x2c);
  }
  *(int *)(param_1 + 0x2c) = iVar4 + 5;
  puVar8 = (undefined4 *)(iVar4 * 4 + *piVar11);
  *puVar8 = *param_3;
  puVar8[1] = param_3[1];
  puVar8[2] = param_3[2];
  puVar8[3] = param_3[3];
  puVar8[4] = param_3[6];
  return *(int *)(param_1 + 0x24);
}

/* FUN_00044360 @ 0x44360 (388 bytes) */
int FUN_00044360(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  undefined4 *puVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  param_3[4] = 0x40000;
  *(undefined2 *)((int)param_3 + 0x12) = 0;
  param_3[7] = ((unsigned char *)0x00004444);
  param_3[4] = param_3[4] | 0x400000;
  if (*(int *)(param_1 + 0x24) != 0) {
    return *(int *)(param_1 + 0x24);
  }
  piVar6 = (int *)(param_1 + 0x28);
  iVar4 = *(int *)(param_1 + 0x2c);
  uVar3 = *(uint *)(param_1 + 0x30);
  if (uVar3 < iVar4 + 5U) {
    if (uVar3 == 0) {
      uVar3 = 0x10;
    }
    else {
      uVar3 = uVar3 << 1;
    }
    for (; uVar3 < iVar4 + 5U; uVar3 = uVar3 << 1) {
    }
    if (*piVar6 == 0) {
      iVar4 = _malloc(uVar3 << 2);
    }
    else {
      iVar4 = _realloc(*piVar6,uVar3 << 2);
    }
    if (iVar4 == 0) {
      iVar4 = *(int *)(param_1 + 0x24);
      if (iVar4 == 0) {
        iVar4 = 1;
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      puVar5 = (undefined4 *)0x0;
      if (iVar4 != 0) {
        return iVar4;
      }
      goto LAB_00044460;
    }
    *piVar6 = iVar4;
    *(uint *)(param_1 + 0x30) = uVar3;
    iVar4 = *(int *)(param_1 + 0x2c);
  }
  *(int *)(param_1 + 0x2c) = iVar4 + 5;
  puVar5 = (undefined4 *)(iVar4 * 4 + *piVar6);
LAB_00044460:
  iVar4 = 0;
  *puVar5 = *param_3;
  do {
    bVar2 = iVar4 != 1;
    iVar4 = iVar4 + 1;
    puVar5[1] = param_3[3];
    puVar1 = param_3 + 6;
    param_3 = param_3 + 1;
    puVar5[2] = *puVar1;
    puVar5 = puVar5 + 2;
  } while (bVar2);
  return 0;
}

/* FUN_00044500 @ 0x44500 (1432 bytes) */
int FUN_00044500(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined *puStack_40;
  undefined *puStack_3c;
  
  _memset(&uStack_58,0,0x24);
  iVar3 = *(int *)(param_1 + 0x24);
  uVar4 = (undefined2)*(undefined4 *)(param_1 + 0x20);
  uStack_54 = CONCAT22(4,uVar4);
  uStack_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_58) + 0)),0x23);
  uStack_50 = 0x55;
  uStack_4c = *(undefined4 *)(param_3 + 0xc);
  puStack_40 = (undefined *)*(undefined4 *)(param_3 + 0x18);
  uStack_48 = *(undefined4 *)(param_3 + 0x10);
  puStack_3c = (undefined *)*(undefined4 *)(param_3 + 0x1c);
  uStack_54 = uStack_54 | 0x400000;
  if (iVar3 == 0) {
    piVar7 = (int *)(param_1 + 0x28);
    iVar3 = *(int *)(param_1 + 0x2c);
    uVar2 = *(uint *)(param_1 + 0x30);
    if (uVar2 < iVar3 + 7U) {
      if (uVar2 == 0) {
        uVar2 = 0x10;
      }
      else {
        uVar2 = uVar2 << 1;
      }
      for (; uVar2 < iVar3 + 7U; uVar2 = uVar2 << 1) {
      }
      if (*piVar7 == 0) {
        iVar3 = _malloc(uVar2 << 2);
      }
      else {
        iVar3 = _realloc(*piVar7,uVar2 << 2);
      }
      if (iVar3 == 0) {
        iVar3 = *(int *)(param_1 + 0x24);
        if (iVar3 == 0) {
          iVar3 = 1;
          *(undefined4 *)(param_1 + 0x24) = 1;
        }
        uVar4 = (undefined2)*(undefined4 *)(param_1 + 0x20);
        goto LAB_000446a0;
      }
      *piVar7 = iVar3;
      *(uint *)(param_1 + 0x30) = uVar2;
      iVar3 = *(int *)(param_1 + 0x2c);
    }
    puVar5 = &uStack_4c;
    *(int *)(param_1 + 0x2c) = iVar3 + 7;
    puVar6 = (undefined4 *)(iVar3 * 4 + *piVar7);
    *puVar6 = uStack_58;
    puVar6[1] = uStack_54;
    puVar6[2] = uStack_50;
    do {
      puVar6[3] = *puVar5;
      puVar1 = puVar5 + 3;
      puVar5 = puVar5 + 1;
      puVar6[4] = *puVar1;
      puVar6 = puVar6 + 2;
    } while (&uStack_44 != puVar5);
    uVar4 = (undefined2)*(undefined4 *)(param_1 + 0x20);
    iVar3 = *(int *)(param_1 + 0x24);
  }
LAB_000446a0:
  uStack_4c = CONCAT22(4,uVar4);
  uStack_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_58) + 0)),0x49);
  puStack_40 = ((unsigned char *)0x00003210);
  uStack_4c = uStack_4c | 0x400000;
  if (iVar3 == 0) {
    piVar7 = (int *)(param_1 + 0x28);
    iVar3 = *(int *)(param_1 + 0x2c);
    uVar2 = *(uint *)(param_1 + 0x30);
    if (uVar2 < iVar3 + 7U) {
      if (uVar2 == 0) {
        uVar2 = 0x10;
      }
      else {
        uVar2 = uVar2 << 1;
      }
      for (; uVar2 < iVar3 + 7U; uVar2 = uVar2 << 1) {
      }
      if (*piVar7 == 0) {
        iVar3 = _malloc(uVar2 << 2);
      }
      else {
        iVar3 = _realloc(*piVar7,uVar2 << 2);
      }
      if (iVar3 == 0) {
        iVar3 = *(int *)(param_1 + 0x24);
        if (iVar3 == 0) {
          iVar3 = 1;
          *(undefined4 *)(param_1 + 0x24) = 1;
        }
        uVar4 = (undefined2)*(undefined4 *)(param_1 + 0x20);
        goto LAB_00044810;
      }
      *piVar7 = iVar3;
      *(uint *)(param_1 + 0x30) = uVar2;
      iVar3 = *(int *)(param_1 + 0x2c);
    }
    puVar5 = &uStack_4c;
    *(int *)(param_1 + 0x2c) = iVar3 + 7;
    puVar6 = (undefined4 *)(iVar3 * 4 + *piVar7);
    *puVar6 = uStack_58;
    puVar6[1] = uStack_54;
    puVar6[2] = uStack_50;
    do {
      puVar6[3] = *puVar5;
      puVar1 = puVar5 + 3;
      puVar5 = puVar5 + 1;
      puVar6[4] = *puVar1;
      puVar6 = puVar6 + 2;
    } while (&uStack_44 != puVar5);
    uVar4 = (undefined2)*(undefined4 *)(param_1 + 0x20);
    iVar3 = *(int *)(param_1 + 0x24);
  }
LAB_00044810:
  uStack_48 = CONCAT22(4,uVar4);
  uStack_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_58) + 0)),3);
  puStack_3c = ((unsigned char *)0x00003210);
  uStack_48 = uStack_48 | 0x400000;
  if (iVar3 == 0) {
    piVar7 = (int *)(param_1 + 0x28);
    iVar3 = *(int *)(param_1 + 0x2c);
    uVar2 = *(uint *)(param_1 + 0x30);
    if (uVar2 < iVar3 + 7U) {
      if (uVar2 == 0) {
        uVar2 = 0x10;
      }
      else {
        uVar2 = uVar2 << 1;
      }
      for (; uVar2 < iVar3 + 7U; uVar2 = uVar2 << 1) {
      }
      if (*piVar7 == 0) {
        iVar3 = _malloc(uVar2 << 2);
      }
      else {
        iVar3 = _realloc(*piVar7,uVar2 << 2);
      }
      if (iVar3 == 0) {
        iVar3 = *(int *)(param_1 + 0x24);
        if (iVar3 == 0) {
          iVar3 = 1;
          *(undefined4 *)(param_1 + 0x24) = 1;
        }
        goto LAB_00044970;
      }
      *piVar7 = iVar3;
      *(uint *)(param_1 + 0x30) = uVar2;
      iVar3 = *(int *)(param_1 + 0x2c);
    }
    puVar5 = &uStack_4c;
    *(int *)(param_1 + 0x2c) = iVar3 + 7;
    puVar6 = (undefined4 *)(iVar3 * 4 + *piVar7);
    *puVar6 = uStack_58;
    puVar6[1] = uStack_54;
    puVar6[2] = uStack_50;
    do {
      puVar6[3] = *puVar5;
      puVar1 = puVar5 + 3;
      puVar5 = puVar5 + 1;
      puVar6[4] = *puVar1;
      puVar6 = puVar6 + 2;
    } while (puVar5 != &uStack_44);
    iVar3 = *(int *)(param_1 + 0x24);
  }
LAB_00044970:
  uStack_54 = *(undefined4 *)(param_3 + 4);
  uStack_50 = *(undefined4 *)(param_3 + 8);
  uStack_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(uStack_58) + 0)),0x5b);
  puStack_40 = (undefined *)*(undefined4 *)(param_3 + 0x18);
  uStack_4c = *(undefined4 *)(param_3 + 0xc);
  if (iVar3 == 0) {
    piVar7 = (int *)(param_1 + 0x28);
    iVar3 = *(int *)(param_1 + 0x2c);
    uVar2 = *(uint *)(param_1 + 0x30);
    if (uVar2 < iVar3 + 7U) {
      if (uVar2 == 0) {
        uVar2 = 0x10;
      }
      else {
        uVar2 = uVar2 << 1;
      }
      for (; uVar2 < iVar3 + 7U; uVar2 = uVar2 << 1) {
      }
      if (*piVar7 == 0) {
        iVar3 = _malloc(uVar2 << 2);
      }
      else {
        iVar3 = _realloc(*piVar7,uVar2 << 2);
      }
      if (iVar3 == 0) {
        if (*(int *)(param_1 + 0x24) != 0) {
          return *(int *)(param_1 + 0x24);
        }
        *(undefined4 *)(param_1 + 0x24) = 1;
        return 1;
      }
      *piVar7 = iVar3;
      *(uint *)(param_1 + 0x30) = uVar2;
      iVar3 = *(int *)(param_1 + 0x2c);
    }
    puVar5 = &uStack_4c;
    *(int *)(param_1 + 0x2c) = iVar3 + 7;
    puVar6 = (undefined4 *)(iVar3 * 4 + *piVar7);
    *puVar6 = uStack_58;
    puVar6[1] = uStack_54;
    puVar6[2] = uStack_50;
    do {
      puVar6[3] = *puVar5;
      puVar1 = puVar5 + 3;
      puVar5 = puVar5 + 1;
      puVar6[4] = *puVar1;
      puVar6 = puVar6 + 2;
    } while (puVar5 != &uStack_44);
    iVar3 = *(int *)(param_1 + 0x24);
  }
  return iVar3;
}

/* FUN_00044ac0 @ 0x44ac0 (440 bytes) */
int FUN_00044ac0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 *param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  dword *pdVar4;
  dword *pdVar5;
  int *piVar6;
  uint auStack_38 [9];
  
  uVar1 = *(uint *)(param_1 + 0x14);
  if ((uVar1 & 0x100000) == 0) {
    auStack_38[0] = uVar1 & 0x100000;
    ((int (*)())FUN_0003eea0)(param_1,0xff,auStack_38);
    uVar1 = (auStack_38[0] & 0x1f) << 0xf | *(uint *)(param_1 + 0x14) & 0xfff07fff | 0x100000;
    *(uint *)(param_1 + 0x14) = uVar1;
  }
  param_3[3] = 0x40000;
  *(ushort *)((int)param_3 + 0xe) = (ushort)(uVar1 >> 0xf) & 0x1f;
  param_3[6] = ((unsigned char *)0x00003210);
  param_3[3] = param_3[3] & 0xffc0ffff | 0x420000;
  if (*(int *)(param_1 + 0x24) != 0) {
    return *(int *)(param_1 + 0x24);
  }
  piVar6 = (int *)(param_1 + 0x28);
  iVar2 = *(int *)(param_1 + 0x2c);
  uVar1 = *(uint *)(param_1 + 0x30);
  if (uVar1 < iVar2 + 3U) {
    if (uVar1 == 0) {
      uVar1 = 0x10;
    }
    else {
      uVar1 = uVar1 << 1;
    }
    for (; uVar1 < iVar2 + 3U; uVar1 = uVar1 << 1) {
    }
    if (*piVar6 == 0) {
      iVar2 = _malloc(uVar1 << 2);
    }
    else {
      iVar2 = _realloc(*piVar6,uVar1 << 2);
    }
    if (iVar2 == 0) {
      iVar2 = *(int *)(param_1 + 0x24);
      if (iVar2 == 0) {
        iVar2 = 1;
        *(undefined4 *)(param_1 + 0x24) = 1;
      }
      if (iVar2 != 0) {
        return iVar2;
      }
      puVar3 = (undefined4 *)0x0;
      pdVar5 = &MACH_HEADER.cputype;
      pdVar4 = &MACH_HEADER.cpusubtype;
      goto LAB_00044c08;
    }
    *piVar6 = iVar2;
    *(uint *)(param_1 + 0x30) = uVar1;
    iVar2 = *(int *)(param_1 + 0x2c);
  }
  *(int *)(param_1 + 0x2c) = iVar2 + 3;
  puVar3 = (undefined4 *)(iVar2 * 4 + *piVar6);
  pdVar5 = puVar3 + 1;
  pdVar4 = puVar3 + 2;
LAB_00044c08:
  *puVar3 = *param_3;
  *pdVar5 = param_3[3];
  *pdVar4 = param_3[6];
  return 0;
}

/* FUN_00044c90 @ 0x44c90 (2856 bytes) */
int FUN_00044c90(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined **ppuVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined **ppuVar7;
  undefined **ppuVar8;
  undefined4 *puVar9;
  uint *puVar10;
  int iVar11;
  int *piVar12;
  undefined1 auStack_b8 [2];
  ushort local_b6;
  undefined1 auStack_b4 [4];
  undefined *local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined *local_94;
  undefined *local_90;
  undefined4 local_88;
  undefined4 local_84;
  uint local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined *local_70 [3];
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 auStack_54 [4];
  uint local_50;
  undefined *local_4c;
  undefined1 auStack_48 [4];
  undefined *local_44;
  
  iVar11 = *param_1;
  puVar5 = &local_a0;
  iVar3 = *(int *)(iVar11 + 0x54);
  _memset(&local_ac,0,0x24);
  iVar11 = iVar11 + iVar3 * 8 + param_2 * 8;
  _memset(&local_88,0,0x24);
  local_a8 = CONCAT22(4,(short)param_1[8]);
  local_ac = CONCAT22((*(unsigned short *)((unsigned char *)&(local_ac) + 0)),0x5b);
  local_a4 = 0x55;
  local_a8 = local_a8 | 0x400000;
  iVar3 = ((int (*)())FUN_0003f1c0)(param_1,iVar11 + 0x18,puVar5,&local_94);
  if (iVar3 == 0) {
    local_90 = ((unsigned char *)0x00005555);
    local_9c = 0x440000;
    if (param_1[9] != 0) {
      return param_1[9];
    }
    piVar12 = param_1 + 10;
    iVar3 = param_1[0xb];
    uVar4 = param_1[0xc];
    if (uVar4 < iVar3 + 7U) {
      if (uVar4 == 0) {
        uVar4 = 0x10;
      }
      else {
        uVar4 = uVar4 << 1;
      }
      for (; uVar4 < iVar3 + 7U; uVar4 = uVar4 << 1) {
      }
      if (*piVar12 == 0) {
        iVar3 = _malloc(uVar4 << 2);
      }
      else {
        iVar3 = _realloc(*piVar12,uVar4 << 2);
      }
      if (iVar3 == 0) goto LAB_000457a8;
      *piVar12 = iVar3;
      param_1[0xc] = uVar4;
      iVar3 = param_1[0xb];
    }
    param_1[0xb] = iVar3 + 7;
    puVar9 = (undefined4 *)(iVar3 * 4 + *piVar12);
    *puVar9 = local_ac;
    puVar9[1] = local_a8;
    puVar9[2] = local_a4;
    puVar6 = puVar5;
    do {
      puVar9[3] = *puVar6;
      puVar1 = puVar6 + 3;
      puVar6 = puVar6 + 1;
      puVar9[4] = *puVar1;
      puVar9 = puVar9 + 2;
    } while (&uStack_98 != puVar6);
    local_88 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_88) + 0)),0xd);
    local_84 = CONCAT22(4,(short)param_1[8] + 1);
    local_7c = (undefined *)CONCAT22(4,(short)param_1[8]);
    local_88 = local_88 & 0xc000ffff | 0x20000;
    local_84 = local_84 | 0x400000;
    local_80 = 0x55;
    local_70[0] = ((unsigned char *)0x00003210);
    local_70[1] = ((unsigned char *)0x00004454);
    local_70[2] = ((unsigned char *)0x00004445);
    local_7c = (undefined *)((uint)local_7c | 0x400000);
    local_78 = 0x440000;
    local_74 = 0x440000;
    if (param_1[9] != 0) {
      return param_1[9];
    }
    iVar3 = param_1[0xb];
    uVar4 = param_1[0xc];
    if (uVar4 < iVar3 + 9U) {
      if (uVar4 == 0) {
        uVar4 = 0x10;
      }
      else {
        uVar4 = uVar4 << 1;
      }
      for (; uVar4 < iVar3 + 9U; uVar4 = uVar4 << 1) {
      }
      if (*piVar12 == 0) {
        iVar3 = _malloc(uVar4 << 2);
      }
      else {
        iVar3 = _realloc(*piVar12,uVar4 << 2);
      }
      if (iVar3 == 0) goto LAB_000457a8;
      *piVar12 = iVar3;
      param_1[0xc] = uVar4;
      iVar3 = param_1[0xb];
    }
    ppuVar8 = (undefined **)&local_7c;
    param_1[0xb] = iVar3 + 9;
    puVar10 = (uint *)(iVar3 * 4 + *piVar12);
    *puVar10 = local_88;
    puVar10[1] = local_84;
    puVar10[2] = local_80;
    ppuVar7 = ppuVar8;
    do {
      puVar10[3] = (uint)*ppuVar7;
      ppuVar2 = ppuVar7 + 3;
      ppuVar7 = ppuVar7 + 1;
      puVar10[4] = (uint)*ppuVar2;
      puVar10 = puVar10 + 2;
    } while (local_70 != ppuVar7);
    if (1 < (*(uint *)(iVar11 + 4) >> 0x1a & 3)) {
      local_a0 = CONCAT22(4,(short)param_1[8]);
      local_94 = ((unsigned char *)0x00003210);
      local_a0 = local_a0 | 0x400000;
      if (param_1[9] != 0) {
        return param_1[9];
      }
      iVar3 = param_1[0xb];
      uVar4 = param_1[0xc];
      if (uVar4 < iVar3 + 7U) {
        if (uVar4 == 0) {
          uVar4 = 0x10;
        }
        else {
          uVar4 = uVar4 << 1;
        }
        for (; uVar4 < iVar3 + 7U; uVar4 = uVar4 << 1) {
        }
        if (*piVar12 == 0) {
          iVar3 = _malloc(uVar4 << 2);
        }
        else {
          iVar3 = _realloc(*piVar12,uVar4 << 2);
        }
        if (iVar3 == 0) goto LAB_000457a8;
        *piVar12 = iVar3;
        param_1[0xc] = uVar4;
        iVar3 = param_1[0xb];
      }
      param_1[0xb] = iVar3 + 7;
      puVar9 = (undefined4 *)(iVar3 * 4 + *piVar12);
      *puVar9 = local_ac;
      puVar9[1] = local_a8;
      puVar9[2] = local_a4;
      puVar6 = puVar5;
      do {
        puVar9[3] = *puVar6;
        puVar1 = puVar6 + 3;
        puVar6 = puVar6 + 1;
        puVar9[4] = *puVar1;
        puVar9 = puVar9 + 2;
      } while (&uStack_98 != puVar6);
      local_74 = CONCAT22(4,(short)param_1[8] + 1);
      local_70[1] = (undefined *)((uint)local_70[1] & 0xfffff88f | 0x540);
      local_70[2] = ((unsigned char *)0x00003210);
      local_74 = local_74 | 0x400000;
      if (param_1[9] != 0) {
        return param_1[9];
      }
      iVar3 = param_1[0xb];
      uVar4 = param_1[0xc];
      if (uVar4 < iVar3 + 9U) {
        if (uVar4 == 0) {
          uVar4 = 0x10;
        }
        else {
          uVar4 = uVar4 << 1;
        }
        for (; uVar4 < iVar3 + 9U; uVar4 = uVar4 << 1) {
        }
        if (*piVar12 == 0) {
          iVar3 = _malloc(uVar4 << 2);
        }
        else {
          iVar3 = _realloc(*piVar12,uVar4 << 2);
        }
        if (iVar3 == 0) goto LAB_000457a8;
        *piVar12 = iVar3;
        param_1[0xc] = uVar4;
        iVar3 = param_1[0xb];
      }
      param_1[0xb] = iVar3 + 9;
      puVar10 = (uint *)(iVar3 * 4 + *piVar12);
      *puVar10 = local_88;
      puVar10[1] = local_84;
      puVar10[2] = local_80;
      ppuVar7 = ppuVar8;
      do {
        puVar10[3] = (uint)*ppuVar7;
        ppuVar2 = ppuVar7 + 3;
        ppuVar7 = ppuVar7 + 1;
        puVar10[4] = (uint)*ppuVar2;
        puVar10 = puVar10 + 2;
      } while (local_70 != ppuVar7);
      if ((*(uint *)(iVar11 + 4) & 0xc000000) == 0xc000000) {
        if (param_1[9] != 0) {
          return param_1[9];
        }
        iVar3 = param_1[0xb];
        uVar4 = param_1[0xc];
        if (uVar4 < iVar3 + 7U) {
          if (uVar4 == 0) {
            uVar4 = 0x10;
          }
          else {
            uVar4 = uVar4 << 1;
          }
          for (; uVar4 < iVar3 + 7U; uVar4 = uVar4 << 1) {
          }
          if (*piVar12 == 0) {
            iVar3 = _malloc(uVar4 << 2);
          }
          else {
            iVar3 = _realloc(*piVar12,uVar4 << 2);
          }
          if (iVar3 == 0) goto LAB_000457a8;
          *piVar12 = iVar3;
          param_1[0xc] = uVar4;
          iVar3 = param_1[0xb];
        }
        param_1[0xb] = iVar3 + 7;
        puVar9 = (undefined4 *)(iVar3 * 4 + *piVar12);
        *puVar9 = local_ac;
        puVar9[1] = local_a8;
        puVar9[2] = local_a4;
        do {
          puVar9[3] = *puVar5;
          puVar6 = puVar5 + 3;
          puVar5 = puVar5 + 1;
          puVar9[4] = *puVar6;
          puVar9 = puVar9 + 2;
        } while (&uStack_98 != puVar5);
        local_70[1] = (undefined *)((uint)local_70[1] & 0xffff88ff | 0x5400);
        if (param_1[9] != 0) {
          return param_1[9];
        }
        iVar3 = param_1[0xb];
        uVar4 = param_1[0xc];
        if (uVar4 < iVar3 + 9U) {
          if (uVar4 == 0) {
            uVar4 = 0x10;
          }
          else {
            uVar4 = uVar4 << 1;
          }
          for (; uVar4 < iVar3 + 9U; uVar4 = uVar4 << 1) {
          }
          if (*piVar12 == 0) {
            iVar3 = _malloc(uVar4 << 2);
          }
          else {
            iVar3 = _realloc(*piVar12,uVar4 << 2);
          }
          if (iVar3 == 0) goto LAB_000457a8;
          *piVar12 = iVar3;
          param_1[0xc] = uVar4;
          iVar3 = param_1[0xb];
        }
        param_1[0xb] = iVar3 + 9;
        puVar10 = (uint *)(iVar3 * 4 + *piVar12);
        *puVar10 = local_88;
        puVar10[1] = local_84;
        puVar10[2] = local_80;
        do {
          puVar10[3] = (uint)*ppuVar8;
          ppuVar7 = ppuVar8 + 3;
          ppuVar8 = ppuVar8 + 1;
          puVar10[4] = (uint)*ppuVar7;
          puVar10 = puVar10 + 2;
        } while (local_70 != ppuVar8);
      }
    }
    _memset(&local_64,0,0x24);
    local_64 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_64) + 0)),0xd);
    local_88 = local_88 & 0xc000ffff | 0x30000;
    iVar3 = ((int (*)())FUN_0003f750)(param_1,iVar11 + 8,&local_60,&local_5c,*(uint *)(iVar11 + 4) >> 0x14 & 1);
    if (iVar3 == 0) {
      local_58 = (undefined *)CONCAT22(4,(short)param_1[8] + 1);
      local_4c = ((unsigned char *)0x00003210);
      local_58 = (undefined *)((uint)local_58 | 0x400000);
      iVar3 = ((int (*)())FUN_0003f1c0)(param_1,iVar11 + 0x10,auStack_54,auStack_48);
      if (iVar3 == 0) {
        iVar3 = ((int (*)())FUN_0003ed90)(param_1,iVar11 + 8,auStack_b8,auStack_b4,0);
        if (iVar3 == 0) {
          local_b0 = ((unsigned char *)0x00003210);
          uVar4 = *(uint *)(iVar11 + 8);
          if ((uVar4 & 0x2000) != 0) {
            ((int (*)())FUN_0003ee30)(0,uVar4 >> 8 & 3,&local_b0);
            uVar4 = *(uint *)(iVar11 + 8);
          }
          if ((uVar4 & 0x4000) != 0) {
            ((int (*)())FUN_0003ee30)(1,uVar4 >> 6 & 3,&local_b0);
            uVar4 = *(uint *)(iVar11 + 8);
          }
          if ((uVar4 & 0x8000) != 0) {
            ((int (*)())FUN_0003ee30)(2,uVar4 >> 4 & 3,&local_b0);
            uVar4 = *(uint *)(iVar11 + 8);
          }
          if ((uVar4 & 0x10000) != 0) {
            ((int (*)())FUN_0003ee30)(3,uVar4 >> 2 & 3,&local_b0);
          }
          iVar3 = param_1[9];
          local_50 = local_b6 | 0x440000;
          local_44 = local_b0;
        }
        else {
          iVar3 = param_1[9];
        }
        if (iVar3 != 0) {
          return iVar3;
        }
        iVar3 = param_1[0xb];
        uVar4 = param_1[0xc];
        if (uVar4 < iVar3 + 9U) {
          if (uVar4 == 0) {
            uVar4 = 0x10;
          }
          else {
            uVar4 = uVar4 << 1;
          }
          for (; uVar4 < iVar3 + 9U; uVar4 = uVar4 << 1) {
          }
          if (*piVar12 == 0) {
            iVar3 = _malloc(uVar4 << 2);
          }
          else {
            iVar3 = _realloc(*piVar12,uVar4 << 2);
          }
          if (iVar3 == 0) {
LAB_000457a8:
            if (param_1[9] != 0) {
              return param_1[9];
            }
            param_1[9] = 1;
            return 1;
          }
          *piVar12 = iVar3;
          param_1[0xc] = uVar4;
          iVar3 = param_1[0xb];
        }
        ppuVar7 = (undefined **)&local_58;
        param_1[0xb] = iVar3 + 9;
        puVar5 = (undefined4 *)(iVar3 * 4 + *piVar12);
        *puVar5 = local_64;
        puVar5[1] = local_60;
        puVar5[2] = local_5c;
        do {
          puVar5[3] = *ppuVar7;
          ppuVar8 = ppuVar7 + 3;
          ppuVar7 = ppuVar7 + 1;
          puVar5[4] = *ppuVar8;
          puVar5 = puVar5 + 2;
        } while (&local_4c != ppuVar7);
        return 0;
      }
    }
  }
  return param_1[9];
}

/* FUN_000457f0 @ 0x457f0 (2412 bytes) */
int FUN_000457f0(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined **ppuVar2;
  int iVar3;
  uint uVar4;
  short sVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined **ppuVar10;
  undefined **ppuVar11;
  uint *puVar12;
  undefined4 *puVar13;
  uint *puVar14;
  int *piVar15;
  int iVar16;
  uint local_98;
  uint local_94;
  undefined4 local_90;
  uint local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 uStack_74;
  undefined *local_70;
  undefined *local_6c;
  undefined4 local_64;
  undefined4 local_60;
  uint local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined *local_4c;
  uint local_48;
  undefined *local_44;
  
  iVar16 = *param_1;
  iVar3 = *(int *)(iVar16 + 0x54);
  _memset(&local_88,0,0x24);
  iVar16 = iVar16 + iVar3 * 8 + param_2 * 8;
  _memset(&local_64,0,0x24);
  iVar3 = ((int (*)())FUN_0003f750)(param_1,iVar16 + 8,&local_98,&local_94,*(uint *)(iVar16 + 4) >> 0x14 & 1);
  if (iVar3 != 0) {
LAB_000458f0:
    return param_1[9];
  }
  puVar14 = (uint *)(iVar16 + 0x10);
  iVar3 = ((int (*)())FUN_0003f1c0)(param_1,puVar14,&local_90,&local_8c);
  if (iVar3 != 0) goto LAB_000458f0;
  puVar6 = &local_7c;
  local_84 = CONCAT22(4,(short)param_1[8]);
  local_88 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_88) + 0)),0x5b);
  local_80 = 0x55;
  local_84 = local_84 | 0x400000;
  iVar3 = ((int (*)())FUN_0003f1c0)(param_1,iVar16 + 0x18,puVar6,&local_70);
  if (iVar3 != 0) goto LAB_000458f0;
  local_6c = ((unsigned char *)0x00005555);
  local_78 = 0x440000;
  if (param_1[9] != 0) {
    return param_1[9];
  }
  piVar15 = param_1 + 10;
  iVar3 = param_1[0xb];
  uVar4 = param_1[0xc];
  if (uVar4 < iVar3 + 7U) {
    if (uVar4 == 0) {
      uVar4 = 0x10;
    }
    else {
      uVar4 = uVar4 << 1;
    }
    for (; uVar4 < iVar3 + 7U; uVar4 = uVar4 << 1) {
    }
    if (*piVar15 == 0) {
      iVar3 = _malloc(uVar4 << 2);
    }
    else {
      iVar3 = _realloc(*piVar15,uVar4 << 2);
    }
    if (iVar3 == 0) goto LAB_00046124;
    *piVar15 = iVar3;
    param_1[0xc] = uVar4;
    iVar3 = param_1[0xb];
  }
  param_1[0xb] = iVar3 + 7;
  puVar13 = (undefined4 *)(iVar3 * 4 + *piVar15);
  *puVar13 = local_88;
  puVar13[1] = local_84;
  puVar13[2] = local_80;
  puVar9 = puVar6;
  do {
    puVar13[3] = *puVar9;
    puVar1 = puVar9 + 3;
    puVar9 = puVar9 + 1;
    puVar13[4] = *puVar1;
    puVar13 = puVar13 + 2;
  } while (&uStack_74 != puVar9);
  local_64 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_64) + 0)),0xd);
  local_64 = local_64 & 0xc000ffff | 0x20000;
  if ((*puVar14 & 0x3000) == 0x1000) {
    sVar5 = (short)param_1[8];
    local_60 = local_98;
    local_5c = local_94;
  }
  else {
    sVar5 = (short)param_1[8];
    local_60 = CONCAT22(4,sVar5 + 1);
    local_5c = 0x55;
    local_60 = local_60 | 0x400000;
  }
  uVar8 = local_8c >> 4 & 7;
  uVar7 = local_8c >> 7 & 1;
  local_58 = (undefined *)CONCAT22(4,sVar5);
  uVar4 = local_8c >> 3 & 1;
  local_4c = ((unsigned char *)0x00003210);
  local_50 = local_90;
  local_44 = (undefined *)
             (uVar4 << 0xf |
             (local_8c & 7) << 0xc |
             uVar4 << 0xb |
             (local_8c & 7) << 8 | uVar4 << 7 | (local_8c & 7) << 4 | local_8c & 0xffff000f);
  local_54 = local_90;
  local_58 = (undefined *)((uint)local_58 | 0x400000);
  local_48 = uVar7 << 0xf |
             uVar8 << 0xc |
             uVar7 << 0xb |
             uVar8 << 8 | uVar7 << 7 | uVar8 << 4 | uVar7 << 3 | local_8c & 0xffff0000 | uVar8;
  if (param_1[9] != 0) {
    return param_1[9];
  }
  iVar3 = param_1[0xb];
  uVar4 = param_1[0xc];
  if (uVar4 < iVar3 + 9U) {
    if (uVar4 == 0) {
      uVar4 = 0x10;
    }
    else {
      uVar4 = uVar4 << 1;
    }
    for (; uVar4 < iVar3 + 9U; uVar4 = uVar4 << 1) {
    }
    if (*piVar15 == 0) {
      iVar3 = _malloc(uVar4 << 2);
    }
    else {
      iVar3 = _realloc(*piVar15,uVar4 << 2);
    }
    if (iVar3 == 0) goto LAB_00046124;
    *piVar15 = iVar3;
    param_1[0xc] = uVar4;
    iVar3 = param_1[0xb];
  }
  ppuVar11 = (undefined **)&local_58;
  param_1[0xb] = iVar3 + 9;
  puVar12 = (uint *)(iVar3 * 4 + *piVar15);
  *puVar12 = local_64;
  puVar12[1] = local_60;
  puVar12[2] = local_5c;
  ppuVar10 = ppuVar11;
  do {
    puVar12[3] = (uint)*ppuVar10;
    ppuVar2 = ppuVar10 + 3;
    ppuVar10 = ppuVar10 + 1;
    puVar12[4] = (uint)*ppuVar2;
    puVar12 = puVar12 + 2;
  } while (&local_4c != ppuVar10);
  if (1 < (*puVar14 >> 0xc & 3)) {
    local_7c = CONCAT22(4,(short)param_1[8]);
    local_70 = ((unsigned char *)0x00003210);
    local_7c = local_7c | 0x400000;
    if (param_1[9] != 0) {
      return param_1[9];
    }
    iVar3 = param_1[0xb];
    uVar4 = param_1[0xc];
    if (uVar4 < iVar3 + 7U) {
      if (uVar4 == 0) {
        uVar4 = 0x10;
      }
      else {
        uVar4 = uVar4 << 1;
      }
      for (; uVar4 < iVar3 + 7U; uVar4 = uVar4 << 1) {
      }
      if (*piVar15 == 0) {
        iVar3 = _malloc(uVar4 << 2);
      }
      else {
        iVar3 = _realloc(*piVar15,uVar4 << 2);
      }
      if (iVar3 == 0) goto LAB_00046124;
      *piVar15 = iVar3;
      param_1[0xc] = uVar4;
      iVar3 = param_1[0xb];
    }
    param_1[0xb] = iVar3 + 7;
    puVar13 = (undefined4 *)(iVar3 * 4 + *piVar15);
    *puVar13 = local_88;
    puVar13[1] = local_84;
    puVar13[2] = local_80;
    puVar9 = puVar6;
    do {
      puVar13[3] = *puVar9;
      puVar1 = puVar9 + 3;
      puVar9 = puVar9 + 1;
      puVar13[4] = *puVar1;
      puVar13 = puVar13 + 2;
    } while (&uStack_74 != puVar9);
    if ((*puVar14 & 0x3000) == 0x2000) {
      local_60 = local_98;
      local_5c = local_94;
    }
    uVar4 = local_8c >> 8 & 7;
    uVar7 = local_8c >> 0xb & 1;
    local_50 = CONCAT22(4,(short)param_1[8] + 1);
    local_44 = ((unsigned char *)0x00003210);
    local_50 = local_50 | 0x400000;
    local_48 = uVar7 << 0xf |
               uVar4 << 0xc |
               uVar7 << 0xb |
               uVar4 << 8 | uVar7 << 7 | uVar4 << 4 | uVar7 << 3 | uVar4 | local_48 & 0xffff0000;
    if (param_1[9] != 0) {
      return param_1[9];
    }
    iVar3 = param_1[0xb];
    uVar4 = param_1[0xc];
    if (uVar4 < iVar3 + 9U) {
      if (uVar4 == 0) {
        uVar4 = 0x10;
      }
      else {
        uVar4 = uVar4 << 1;
      }
      for (; uVar4 < iVar3 + 9U; uVar4 = uVar4 << 1) {
      }
      if (*piVar15 == 0) {
        iVar3 = _malloc(uVar4 << 2);
      }
      else {
        iVar3 = _realloc(*piVar15,uVar4 << 2);
      }
      if (iVar3 == 0) goto LAB_00046124;
      *piVar15 = iVar3;
      param_1[0xc] = uVar4;
      iVar3 = param_1[0xb];
    }
    param_1[0xb] = iVar3 + 9;
    puVar12 = (uint *)(iVar3 * 4 + *piVar15);
    *puVar12 = local_64;
    puVar12[1] = local_60;
    puVar12[2] = local_5c;
    ppuVar10 = ppuVar11;
    do {
      puVar12[3] = (uint)*ppuVar10;
      ppuVar2 = ppuVar10 + 3;
      ppuVar10 = ppuVar10 + 1;
      puVar12[4] = (uint)*ppuVar2;
      puVar12 = puVar12 + 2;
    } while (&local_4c != ppuVar10);
    if ((*puVar14 & 0x3000) != 0x3000) {
      return 0;
    }
    if (param_1[9] != 0) {
      return param_1[9];
    }
    iVar3 = param_1[0xb];
    uVar4 = param_1[0xc];
    if (uVar4 < iVar3 + 7U) {
      if (uVar4 == 0) {
        uVar4 = 0x10;
      }
      else {
        uVar4 = uVar4 << 1;
      }
      for (; uVar4 < iVar3 + 7U; uVar4 = uVar4 << 1) {
      }
      if (*piVar15 == 0) {
        iVar3 = _malloc(uVar4 << 2);
      }
      else {
        iVar3 = _realloc(*piVar15,uVar4 << 2);
      }
      if (iVar3 == 0) goto LAB_00046124;
      *piVar15 = iVar3;
      param_1[0xc] = uVar4;
      iVar3 = param_1[0xb];
    }
    param_1[0xb] = iVar3 + 7;
    puVar13 = (undefined4 *)(iVar3 * 4 + *piVar15);
    *puVar13 = local_88;
    puVar13[1] = local_84;
    puVar13[2] = local_80;
    do {
      puVar13[3] = *puVar6;
      puVar9 = puVar6 + 3;
      puVar6 = puVar6 + 1;
      puVar13[4] = *puVar9;
      puVar13 = puVar13 + 2;
    } while (&uStack_74 != puVar6);
    uVar7 = local_8c >> 0xc & 7;
    uVar4 = local_8c >> 0xf & 1;
    local_60 = local_98;
    local_5c = local_94;
    local_48 = uVar4 << 0xf |
               uVar7 << 0xc |
               uVar4 << 0xb |
               uVar7 << 8 | uVar4 << 7 | uVar7 << 4 | uVar4 << 3 | uVar7 | local_48 & 0xffff0000;
    if (param_1[9] != 0) {
      return param_1[9];
    }
    iVar3 = param_1[0xb];
    uVar4 = param_1[0xc];
    if (uVar4 < iVar3 + 9U) {
      if (uVar4 == 0) {
        uVar4 = 0x10;
      }
      else {
        uVar4 = uVar4 << 1;
      }
      for (; uVar4 < iVar3 + 9U; uVar4 = uVar4 << 1) {
      }
      if (*piVar15 == 0) {
        iVar3 = _malloc(uVar4 << 2);
      }
      else {
        iVar3 = _realloc(*piVar15,uVar4 << 2);
      }
      if (iVar3 == 0) {
LAB_00046124:
        if (param_1[9] == 0) {
          param_1[9] = 1;
          return 1;
        }
        return param_1[9];
      }
      *piVar15 = iVar3;
      param_1[0xc] = uVar4;
      iVar3 = param_1[0xb];
    }
    param_1[0xb] = iVar3 + 9;
    puVar14 = (uint *)(iVar3 * 4 + *piVar15);
    *puVar14 = local_64;
    puVar14[1] = local_60;
    puVar14[2] = local_5c;
    do {
      puVar14[3] = (uint)*ppuVar11;
      ppuVar10 = ppuVar11 + 3;
      ppuVar11 = ppuVar11 + 1;
      puVar14[4] = (uint)*ppuVar10;
      puVar14 = puVar14 + 2;
    } while (ppuVar11 != &local_4c);
  }
  return 0;
}

/* FUN_00046180 @ 0x46180 (1528 bytes) */
int FUN_00046180(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  undefined4 *puVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int *piVar10;
  undefined4 local_58;
  uint local_54;
  uint local_50;
  undefined4 local_4c;
  uint local_48;
  undefined4 uStack_44;
  undefined *local_40;
  uint local_3c;
  
  bVar2 = param_3 == 0;
  iVar9 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
  _memset(&local_58,0,0x24);
  if (bVar2) {
    param_3 = (*(uint *)(param_2 * 8 + iVar9 + 4) >> 0x1a & 3) + 1;
  }
  if (param_3 < 3) {
    if (param_3 == 1) {
      (*(unsigned short *)((unsigned char *)&(local_58) + 2)) = 0x47;
    }
    else {
      (*(unsigned short *)((unsigned char *)&(local_58) + 2)) = 0x49;
    }
    iVar9 = iVar9 + param_2 * 8;
    iVar5 = ((int (*)())FUN_0003f750)(param_1,iVar9 + 8,&local_54,&local_50,1);
    if (iVar5 != 0) {
LAB_00046640:
      return param_1[9];
    }
    if (bVar2) {
      iVar9 = ((int (*)())FUN_0003f1c0)(param_1,iVar9 + 0x10,&local_4c,&local_40);
      if (iVar9 != 0) goto LAB_00046640;
    }
    else {
      local_4c = CONCAT22(4,(short)param_1[8]);
      local_40 = ((unsigned char *)0x00003210);
      local_4c = local_4c | 0x400000;
    }
    if (param_3 == 2) {
      local_48 = local_4c;
      local_3c = (uint)local_40 >> 4 & 8 | (uint)local_40 >> 4 & 7 | (uint)local_40 & 0xfffffff0;
    }
    if (param_1[9] != 0) {
      return param_1[9];
    }
    piVar10 = param_1 + 10;
    iVar9 = param_1[0xb];
    iVar5 = param_3 * 2 + 3;
    uVar3 = param_1[0xc];
    uVar4 = iVar5 + iVar9;
    if (uVar3 < uVar4) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < uVar4; uVar3 = uVar3 << 1) {
      }
      if (*piVar10 == 0) {
        iVar9 = _malloc(uVar3 << 2);
      }
      else {
        iVar9 = _realloc(*piVar10,uVar3 << 2);
      }
      if (iVar9 == 0) goto LAB_0004676c;
      *piVar10 = iVar9;
      param_1[0xc] = uVar3;
      iVar9 = param_1[0xb];
    }
    param_1[0xb] = iVar5 + iVar9;
    puVar6 = (undefined4 *)(iVar9 * 4 + *piVar10);
    *puVar6 = local_58;
    puVar6[1] = local_54;
    puVar6[2] = local_50;
    if (0 < param_3) {
      puVar7 = &local_4c;
      do {
        puVar6[3] = *puVar7;
        puVar8 = puVar7 + 3;
        puVar7 = puVar7 + 1;
        puVar6[4] = *puVar8;
        puVar6 = puVar6 + 2;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
  }
  else {
    local_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_58) + 0)),0x49);
    local_50 = local_50 & 0xffffff00 | 0x111;
    local_54 = CONCAT22((short)(local_54 >> 0x10),(short)param_1[8]) & 0xffc0ffff | 0x440000;
    if (bVar2) {
      iVar5 = ((int (*)())FUN_0003f1c0)(param_1,iVar9 + param_2 * 8 + 0x10,&local_4c,&local_40);
      if (iVar5 != 0) goto LAB_00046640;
    }
    else {
      local_4c = CONCAT22(4,(short)param_1[8]);
      local_40 = ((unsigned char *)0x00003210);
      local_4c = local_4c | 0x400000;
    }
    local_48 = local_4c;
    uVar3 = (uint)local_40 >> 4 & 7;
    uVar4 = (uint)local_40 >> 4 & 8;
    if (param_3 == 3) {
      local_3c = uVar4 | uVar3 | (uint)local_40 & 0xfffff0f0 | 0x500;
    }
    else {
      local_3c = ((uint)local_40 & 0xfffff8f0) >> 4 & 0x800 |
                 (uint)local_40 >> 4 & 0x700 | uVar4 | uVar3 | (uint)local_40 & 0xfffff0f0;
    }
    if (param_1[9] != 0) {
      return param_1[9];
    }
    piVar10 = param_1 + 10;
    iVar5 = param_1[0xb];
    uVar3 = param_1[0xc];
    if (uVar3 < iVar5 + 7U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar5 + 7U; uVar3 = uVar3 << 1) {
      }
      if (*piVar10 == 0) {
        iVar5 = _malloc(uVar3 << 2);
      }
      else {
        iVar5 = _realloc(*piVar10,uVar3 << 2);
      }
      if (iVar5 == 0) goto LAB_0004676c;
      *piVar10 = iVar5;
      param_1[0xc] = uVar3;
      iVar5 = param_1[0xb];
    }
    puVar8 = &local_4c;
    param_1[0xb] = iVar5 + 7;
    puVar6 = (undefined4 *)(iVar5 * 4 + *piVar10);
    *puVar6 = local_58;
    puVar6[1] = local_54;
    puVar6[2] = local_50;
    puVar7 = puVar8;
    do {
      puVar6[3] = *puVar7;
      puVar1 = puVar7 + 3;
      puVar7 = puVar7 + 1;
      puVar6[4] = *puVar1;
      puVar6 = puVar6 + 2;
    } while (&uStack_44 != puVar7);
    iVar9 = ((int (*)())FUN_0003f750)(param_1,iVar9 + param_2 * 8 + 8,&local_54,&local_50,1);
    if (iVar9 != 0) goto LAB_00046640;
    local_4c = CONCAT22(4,(short)param_1[8]);
    local_40 = (undefined *)0x0;
    local_3c = local_3c & 0xfffffff8 | 2;
    local_48 = local_4c | 0x400000;
    local_4c = local_4c | 0x400000;
    if (param_1[9] != 0) {
      return param_1[9];
    }
    iVar9 = param_1[0xb];
    uVar3 = param_1[0xc];
    if (uVar3 < iVar9 + 7U) {
      if (uVar3 == 0) {
        uVar3 = 0x10;
      }
      else {
        uVar3 = uVar3 << 1;
      }
      for (; uVar3 < iVar9 + 7U; uVar3 = uVar3 << 1) {
      }
      if (*piVar10 == 0) {
        iVar9 = _malloc(uVar3 << 2);
      }
      else {
        iVar9 = _realloc(*piVar10,uVar3 << 2);
      }
      if (iVar9 == 0) {
LAB_0004676c:
        if (param_1[9] != 0) {
          return param_1[9];
        }
        param_1[9] = 1;
        return 1;
      }
      *piVar10 = iVar9;
      param_1[0xc] = uVar3;
      iVar9 = param_1[0xb];
    }
    param_1[0xb] = iVar9 + 7;
    puVar6 = (undefined4 *)(iVar9 * 4 + *piVar10);
    *puVar6 = local_58;
    puVar6[1] = local_54;
    puVar6[2] = local_50;
    do {
      puVar6[3] = *puVar8;
      puVar7 = puVar8 + 3;
      puVar8 = puVar8 + 1;
      puVar6[4] = *puVar7;
      puVar6 = puVar6 + 2;
    } while (puVar8 != &uStack_44);
  }
  return 0;
}

/* FUN_000467a0 @ 0x467a0 (632 bytes) */
int FUN_000467a0(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined2 uVar5;
  undefined4 *puVar4;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48;
  undefined4 uStack_44;
  undefined *local_40;
  uint local_3c;
  
  iVar8 = *param_1;
  iVar2 = *(int *)(iVar8 + 0x54);
  _memset(&local_58,0,0x24);
  iVar8 = iVar8 + iVar2 * 8 + param_2 * 8;
  local_58 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_58) + 0)),0x23);
  iVar2 = ((int (*)())FUN_0003f750)(param_1,iVar8 + 8,&local_54,&local_50,1);
  if (iVar2 == 0) {
    if (param_3 == 0) {
      iVar2 = ((int (*)())FUN_0003f1c0)(param_1,iVar8 + 0x10,&local_4c,&local_40);
      if (iVar2 != 0) goto LAB_000468f0;
      uVar5 = (undefined2)param_1[8];
    }
    else {
      uVar5 = (undefined2)param_1[8];
      local_4c = CONCAT22(4,uVar5);
      local_40 = ((unsigned char *)0x00003210);
      local_4c = local_4c | 0x400000;
    }
    iVar2 = param_1[9];
    local_3c = local_3c & 0xffff0000 | 0x5555;
    local_48 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_48) + 0)),uVar5) & 0xffc0ffff | 0x440000;
    if (iVar2 == 0) {
      piVar7 = param_1 + 10;
      iVar2 = param_1[0xb];
      uVar3 = param_1[0xc];
      if (uVar3 < iVar2 + 7U) {
        if (uVar3 == 0) {
          uVar3 = 0x10;
        }
        else {
          uVar3 = uVar3 << 1;
        }
        for (; uVar3 < iVar2 + 7U; uVar3 = uVar3 << 1) {
        }
        if (*piVar7 == 0) {
          iVar2 = _malloc(uVar3 << 2);
        }
        else {
          iVar2 = _realloc(*piVar7,uVar3 << 2);
        }
        if (iVar2 == 0) {
          if (param_1[9] != 0) {
            return param_1[9];
          }
          param_1[9] = 1;
          return 1;
        }
        *piVar7 = iVar2;
        param_1[0xc] = uVar3;
        iVar2 = param_1[0xb];
      }
      puVar4 = &local_4c;
      param_1[0xb] = iVar2 + 7;
      puVar6 = (undefined4 *)(iVar2 * 4 + *piVar7);
      *puVar6 = local_58;
      puVar6[1] = local_54;
      puVar6[2] = local_50;
      do {
        puVar6[3] = *puVar4;
        puVar1 = puVar4 + 3;
        puVar4 = puVar4 + 1;
        puVar6[4] = *puVar1;
        puVar6 = puVar6 + 2;
      } while (&uStack_44 != puVar4);
      iVar2 = 0;
    }
  }
  else {
LAB_000468f0:
    iVar2 = param_1[9];
  }
  return iVar2;
}

/* FUN_00046a30 @ 0x46a30 (1080 bytes) */
int FUN_00046a30(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  undefined4 local_68;
  undefined4 local_64;
  uint local_60;
  undefined4 local_5c;
  undefined1 auStack_58 [2];
  short local_56;
  uint uStack_54;
  uint local_50;
  undefined1 auStack_4c [32];
  
  iVar11 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
  _memset(&local_68,0,0x24);
  iVar12 = iVar11 + param_2 * 8;
  uVar9 = *(uint *)(iVar11 + param_2 * 8) >> 0x12 & 0xff;
  if ((param_1[5] & 0x20000000U) == 0) {
    uVar7 = 0;
    uVar5 = 0;
    uVar6 = 0;
    uVar10 = 3;
  }
  else {
    uVar7 = *(uint *)(iVar12 + 4) >> 0x1c & 1;
    uVar5 = *(uint *)(iVar12 + 0x10) >> 0xe & 1;
    uVar6 = *(uint *)(iVar12 + 0x18) >> 0xe & 1;
    uVar10 = *(uint *)(iVar12 + 4) >> 0x1a & 3;
  }
  iVar11 = uVar9 * 0x10;
  local_68 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_68) + 0)),(short)(*(uint *)(&DAT_001dac34 + iVar11) >> 1));
  local_68 = (*(uint *)(&DAT_001dac38 + iVar11) >> 0x13) << 0x10 | local_68 & 0xc000ffff;
  iVar11 = ((int (*)())FUN_0003f750)(param_1,iVar12 + 8,&local_64,&local_60,*(uint *)(iVar12 + 4) >> 0x14 & 1);
  if (iVar11 == 0) {
    iVar11 = ((int (*)())FUN_0003f1c0)(param_1,iVar12 + 0x10,&local_5c,&local_50);
    if ((iVar11 == 0) &&
       (iVar11 = ((int (*)())FUN_0003f1c0)(param_1,iVar12 + 0x18,auStack_58,auStack_4c), iVar11 == 0)) {
      if (uVar7 == 0) {
        iVar11 = 1;
      }
      else {
        iVar11 = uVar10 + 1;
        if (iVar11 == 0) {
LAB_00046cd4:
          if ((((param_1[5] & 0x20000000U) == 0) || (uVar9 != 0x3a)) ||
             (iVar11 = ((int (*)())FUN_0003ed50)(param_1,iVar12 + 8), iVar11 != 1)) {
            return 0;
          }
          local_68 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_68) + 0)),99);
          local_5c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_5c) + 0)),(*(unsigned short *)((unsigned char *)&(local_64) + 2)));
          local_50 = local_50 & 0xffff0000 | 0x3210;
          local_5c = (local_64 >> 0x10 & 0x3f) << 0x10 | local_5c & 0xffc0ffff;
          local_68 = local_68 & 0xc000ffff;
          if (param_1[9] != 0) {
            return param_1[9];
          }
          piVar13 = param_1 + 10;
          iVar11 = param_1[0xb];
          uVar9 = param_1[0xc];
          if (uVar9 < iVar11 + 5U) {
            if (uVar9 == 0) {
              uVar9 = 0x10;
            }
            else {
              uVar9 = uVar9 << 1;
            }
            for (; uVar9 < iVar11 + 5U; uVar9 = uVar9 << 1) {
            }
            if (*piVar13 == 0) {
              iVar11 = _malloc(uVar9 << 2);
            }
            else {
              iVar11 = _realloc(*piVar13,uVar9 << 2);
            }
            if (iVar11 == 0) {
LAB_00046e28:
              if (param_1[9] != 0) {
                return param_1[9];
              }
              param_1[9] = 1;
              return 1;
            }
            *piVar13 = iVar11;
            param_1[0xc] = uVar9;
            iVar11 = param_1[0xb];
          }
          param_1[0xb] = iVar11 + 5;
          puVar4 = (uint *)(iVar11 * 4 + *piVar13);
          *puVar4 = local_68;
          puVar4[1] = local_64;
          puVar4[2] = local_60;
          puVar4[3] = local_5c;
          puVar4[4] = local_50;
          return 0;
        }
      }
      if (param_1[9] != 0) {
        return param_1[9];
      }
      iVar8 = 0;
      piVar13 = param_1 + 10;
      do {
        iVar2 = param_1[0xb];
        uVar10 = param_1[0xc];
        if (uVar10 < iVar2 + 7U) {
          if (uVar10 == 0) {
            uVar10 = 0x10;
          }
          else {
            uVar10 = uVar10 << 1;
          }
          for (; uVar10 < iVar2 + 7U; uVar10 = uVar10 << 1) {
          }
          if (*piVar13 == 0) {
            iVar2 = _malloc(uVar10 << 2);
          }
          else {
            iVar2 = _realloc(*piVar13,uVar10 << 2);
          }
          if (iVar2 == 0) goto LAB_00046e28;
          *piVar13 = iVar2;
          param_1[0xc] = uVar10;
          iVar2 = param_1[0xb];
        }
        param_1[0xb] = iVar2 + 7;
        puVar4 = (uint *)(iVar2 * 4 + *piVar13);
        *puVar4 = local_68;
        puVar4[1] = local_64;
        puVar4[2] = local_60;
        puVar3 = &local_5c;
        do {
          puVar4[3] = *puVar3;
          puVar1 = puVar3 + 3;
          puVar3 = puVar3 + 1;
          puVar4[4] = *puVar1;
          puVar4 = puVar4 + 2;
        } while (puVar3 != &uStack_54);
        if (uVar7 != 0) {
          local_64 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_64) + 0)),(*(unsigned short *)((unsigned char *)&(local_64) + 2)) + 1);
        }
        if (uVar5 != 0) {
          local_5c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_5c) + 0)),(*(unsigned short *)((unsigned char *)&(local_5c) + 2)) + 1);
        }
        if (uVar6 != 0) {
          local_56 = local_56 + 1;
        }
        iVar8 = iVar8 + 1;
        if (iVar11 == iVar8) goto LAB_00046cd4;
        if (param_1[9] != 0) {
          return param_1[9];
        }
      } while( true );
    }
  }
  return param_1[9];
}

/* FUN_00046e90 @ 0x46e90 (7800 bytes) */
int FUN_00046e90(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  bool bVar1;
  bool bVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined2 uVar10;
  uint uVar11;
  undefined *puVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  uint *puVar19;
  uint *puVar20;
  uint *puVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  undefined4 *puVar25;
  uint *puVar26;
  uint local_108;
  uint local_104;
  uint local_100;
  uint local_fc;
  uint local_f8;
  uint local_f4;
  uint *local_f0;
  undefined4 local_ec;
  uint local_e8;
  uint local_e4;
  uint local_e0;
  uint local_dc;
  uint local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  uint local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined *local_bc;
  undefined *local_b8 [2];
  undefined4 local_b0;
  undefined4 local_ac;
  uint local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined *local_98;
  undefined *local_94;
  undefined *local_90;
  int local_88;
  int local_84;
  int local_80;
  uint local_7c;
  uint local_78;
  uint *local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  undefined4 *local_60;
  undefined4 *local_5c;
  
  iVar5 = *param_1;
  iVar16 = *(int *)(iVar5 + 0x50);
  iVar8 = *(int *)(iVar5 + 0x54) * 8;
  puVar20 = (uint *)(iVar5 + iVar8);
  if (iVar16 < 1) {
LAB_00048d20:
    iVar8 = 0;
  }
  else {
    uVar22 = *(uint *)(iVar5 + iVar8) >> 0x12 & 0xff;
    iVar8 = uVar22 * 0x10;
    uVar13 = *(uint *)(&DAT_001dac34 + iVar8) >> 0x11 & 0xf;
    if ((uVar13 != 0) && ((*(uint *)(&DAT_001dac40 + iVar8) >> 0x1c & DAT_001db344) == 0)) {
      iVar17 = 0;
      iVar18 = 0;
      iVar5 = 0;
      puVar19 = puVar20;
      do {
        uVar11 = *puVar19 >> 0x1d;
        iVar15 = uVar11 + 2;
        if (uVar13 == 2) {
          iVar6 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
          uVar13 = *(uint *)(iVar5 + iVar6) >> 0x12 & 0xff;
          if ((uVar13 - 0x44 < 2) || (iVar23 = 0, uVar13 == 0x47)) {
            iVar23 = 1;
          }
          if (((uVar13 == 0x43) || (uVar13 == 0x45)) || (bVar1 = false, uVar13 == 0x47)) {
            bVar1 = true;
          }
          local_5c = &local_b0;
          iVar24 = iVar6 + iVar5;
          _memset(local_5c,0,0x24);
          local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),(short)(*(uint *)(&DAT_001dac34 + uVar13 * 0x10) >> 1))
          ;
          ((int (*)())FUN_0003f750)(param_1,iVar24 + 8,&local_ac,&local_a8,
                       *(uint *)(iVar5 + iVar6 + 4) >> 0x14 & 1);
          ((int (*)())FUN_0003f1c0)(param_1,iVar24 + 0x10,&local_a4,&local_98);
          if ((param_1[5] & 0x20000000U) == 0) {
            local_b0 = (*(uint *)(iVar24 + 0x18) & 0x1f) << 0x10 | local_b0 & 0xc000ffff;
            uVar13 = *(uint *)(iVar24 + 0x18) >> 5 & 7;
            if (iVar23 != 0) {
              local_a0 = local_a4;
              local_94 = local_98;
            }
          }
          else {
            local_f0 = (uint *)0x0;
            iVar6 = ((int (*)())FUN_0003f050)(param_1,iVar18,&local_f0);
            if (iVar6 != 0) goto LAB_00048a2c;
            local_b0 = ((uint)local_f0 & 0x3fff) << 0x10 | local_b0 & 0xc000ffff;
            uVar13 = *(uint *)(iVar24 + 0x20) >> 5 & 7;
            if (iVar23 != 0) {
              ((int (*)())FUN_0003f1c0)(param_1,iVar24 + 0x28,&local_a0,&local_94);
              uVar11 = (uint)local_94 >> 3 & 1;
              local_94 = (undefined *)
                         (uVar11 << 0xf |
                         ((uint)local_94 & 7) << 0xc |
                         uVar11 << 0xb |
                         ((uint)local_94 & 7) << 8 |
                         uVar11 << 7 | ((uint)local_94 & 7) << 4 | (uint)local_94 & 0xffff000f);
            }
          }
          if (uVar13 - 5 < 3) {
            local_b0 = local_b0 & 0xf3ffffff | 0x4000000;
          }
          puVar12 = local_98;
          if ((bVar1) &&
             (puVar12 = (undefined *)((uint)local_98 & 0xff1fffff | 0x600000),
             ((uint)local_98 & 0x8000) != 0)) {
            puVar12 = (undefined *)
                      (((uint)local_98 & 0xff1ff777 ^ 0x8000) & 0x8000 |
                      ((uint)local_98 & 0xff1fff77 ^ 0x800) & 0x800 |
                      ((uint)local_98 & 0xff1ffff7 ^ 0x80) & 0x80 |
                      ((uint)puVar12 ^ 8) & 8 | (uint)local_98 & 0xff1f7777 | 0x600000);
          }
          local_98 = puVar12;
          ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,iVar23 + 1);
LAB_00048c70:
          if (uVar22 != 0x4d) {
LAB_00048c78:
            if ((((*(uint *)(&DAT_001dac34 + iVar8) >> 0x11 & 0xf) != 3) &&
                ((param_1[5] & 0x20000000U) != 0)) &&
               (((((uVar13 = *(uint *)((int)puVar20 + iVar5 + 8), (uVar13 & 0x2000) != 0 &&
                   ((uVar13 & 0x300) != 0)) ||
                  (((uVar13 & 0x4000) != 0 && ((uVar13 & 0xc0) != 0x40)))) ||
                 (((uVar13 & 0x8000) != 0 && ((uVar13 & 0x30) != 0x20)))) ||
                (((uVar13 & 0x10000) != 0 && ((uVar13 & 0xc) != 0xc)))))) {
              ((int (*)())FUN_0003f9f0)(param_1,(int)puVar20 + iVar5 + 8,puVar19[1] >> 0x14 & 1);
            }
          }
        }
        else {
          if (uVar13 != 7) {
            if (uVar13 == 5) {
              local_60 = &local_d4;
              _memset(local_60,0,0x24);
              local_d4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_d4) + 0)),(short)(*(uint *)(&DAT_001dac34 + iVar8) >> 1));
              local_d4 = (*(uint *)(&DAT_001dac38 + iVar8) >> 0x13) << 0x10 | local_d4 & 0xc000ffff;
              if ((*(uint *)(&DAT_001dac40 + iVar8) >> 0x1c & 2) == 0) {
                if (((puVar19[1] & 0x100000) != 0) ||
                   (uVar9 = 0, (*(uint *)(&DAT_001dac40 + iVar8) >> 0x1c & 1) != 0)) {
                  uVar9 = 1;
                }
                ((int (*)())FUN_0003f750)(param_1,(int)puVar20 + iVar5 + 8,&local_d0,&local_cc,uVar9);
              }
              if (uVar11 != 0) {
                uVar13 = 0;
                puVar25 = &local_c8;
                puVar21 = puVar20 + iVar18 * 2 + 4;
                do {
                  uVar13 = uVar13 + 1;
                  ((int (*)())FUN_0003f1c0)(param_1,puVar21,puVar25,puVar25 + 3);
                  puVar25 = puVar25 + 1;
                  puVar21 = puVar21 + 2;
                } while (uVar11 != uVar13);
              }
              (**(code **)(&DAT_001dac3c + iVar8))(param_1,iVar18,local_60);
LAB_00048a2c:
              if (param_1[9] != 0) {
                return param_1[9];
              }
            }
            else {
              uVar7 = *(uint *)(&DAT_001dac34 + iVar8);
              uVar4 = *(uint *)(&DAT_001dac38 + iVar8);
              if (uVar13 == 4) {
                uVar11 = uVar11 - 1;
              }
              iVar6 = uVar11 * 2 + 1;
              if (uVar13 != 3) {
                iVar6 = uVar11 * 2 + 3;
              }
              iVar6 = ((int (*)())FUN_0003ef50)(param_1,iVar6,&local_f0);
              if (iVar6 != 0) goto LAB_00048d74;
              *local_f0 = (uVar4 >> 0x13) << 0x10 | uVar7 >> 1 & 0xffff;
              if ((*(uint *)(&DAT_001dac34 + iVar8) >> 0x11 & 0xf) != 3) {
                if (((puVar19[1] & 0x100000) != 0) ||
                   (uVar9 = 0, (*(uint *)(&DAT_001dac40 + iVar8) & 0x10000000) != 0)) {
                  uVar9 = 1;
                }
                iVar6 = ((int (*)())FUN_0003f750)(param_1,(int)puVar20 + iVar5 + 8,&local_108,&local_104,uVar9);
                if (iVar6 != 0) goto LAB_00048d74;
                local_f0[1] = local_108;
                local_f0[2] = local_104;
              }
              if ((*(uint *)(&DAT_001dac34 + iVar8) >> 0x11 & 0xf) == 4) {
                iVar6 = ((int (*)())FUN_0003f4e0)(param_1,(int)puVar20 + iVar5 + 0x10,&local_100,&local_fc,
                                     (int)puVar20 + iVar5 + 0x18);
              }
              else {
                iVar6 = ((int (*)())FUN_0003f1c0)(param_1,(int)puVar20 + iVar5 + 0x10,&local_100,&local_fc);
              }
              if (iVar6 != 0) goto LAB_00048d74;
              uVar13 = *(uint *)(&DAT_001dac34 + iVar8) >> 0x11 & 0xf;
              if (uVar13 == 6) {
                local_fc = local_fc & 0xffff0fff | 0x5000;
              }
              if (uVar13 == 3) {
                local_f0[1] = local_100;
                local_f0[2] = local_fc;
              }
              else {
                local_f0[3] = local_100;
                local_f0[4] = local_fc;
              }
              if (1 < (int)uVar11) {
                iVar6 = ((int (*)())FUN_0003f1c0)(param_1,(int)puVar20 + iVar5 + 0x18,&local_100,&local_fc);
                if (iVar6 != 0) goto LAB_00048d74;
                local_f0[5] = local_100;
                local_f0[6] = local_fc;
                if (2 < (int)uVar11) {
                  iVar6 = ((int (*)())FUN_0003f1c0)(param_1,(int)puVar20 + iVar5 + 0x20,&local_100,&local_fc);
                  if (iVar6 != 0) goto LAB_00048d74;
                  local_f0[7] = local_100;
                  local_f0[8] = local_fc;
                }
              }
            }
            goto LAB_00048c70;
          }
          if (uVar22 == 0) {
            local_5c = &local_b0;
            iVar24 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
            _memset(local_5c,0,0x24);
            iVar23 = iVar5 + iVar24;
            iVar24 = iVar24 + iVar5;
            local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),0x47);
            iVar6 = ((int (*)())FUN_0003f750)(param_1,iVar24 + 8,&local_ac,&local_a8,
                                 *(uint *)(iVar23 + 4) >> 0x14 & 1);
            if ((iVar6 == 0) &&
               (iVar6 = ((int (*)())FUN_0003f1c0)(param_1,iVar24 + 0x10,&local_a4,&local_98), iVar6 == 0)) {
              if (((param_1[5] & 0x20000000U) == 0) ||
                 (uVar13 = *(uint *)(iVar23 + 4), (uVar13 & 0x10000000) == 0)) {
                iVar6 = 1;
              }
              else {
                iVar6 = (uVar13 >> 0x1a & 3) + 1;
                if (iVar6 == 0) goto LAB_00048c78;
              }
              iVar23 = 0;
              do {
                iVar24 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,1);
                if (iVar24 != 0) goto LAB_00048418;
                iVar23 = iVar23 + 1;
                local_ac = CONCAT22((*(unsigned short *)((unsigned char *)&(local_ac) + 0)),(*(unsigned short *)((unsigned char *)&(local_ac) + 2)) + 1);
                local_a4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_a4) + 0)),(*(unsigned short *)((unsigned char *)&(local_a4) + 2)) + 1);
              } while (iVar6 != iVar23);
              goto LAB_00048c78;
            }
LAB_00048418:
            if (param_1[9] != 0) {
              return param_1[9];
            }
            goto LAB_00048c78;
          }
          if (uVar22 == 0x40) {
            iVar23 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
            iVar6 = ((int (*)())FUN_0003f750)(param_1,iVar23 + iVar5 + 8,&local_f8,&local_f4,
                                 *(uint *)(iVar5 + iVar23 + 4) >> 0x14 & 1);
            if (iVar6 == 0) {
              local_5c = &local_b0;
              iVar6 = 0;
              iVar23 = iVar18 * 8 + iVar23 + 0x10;
              do {
                iVar24 = ((int (*)())FUN_0003f1c0)(param_1,iVar23,iVar6 + (int)local_5c,(int)&local_e0 + iVar6);
                if (iVar24 != 0) goto LAB_00048418;
                bVar1 = iVar6 != 8;
                iVar23 = iVar23 + 8;
                iVar6 = iVar6 + 4;
              } while (bVar1);
              iVar6 = param_1[8];
              iVar24 = 0;
              iVar23 = 0;
              local_60 = &local_d4;
              puVar21 = &local_108;
              do {
                sVar3 = (short)iVar6 + (short)iVar24;
                bVar1 = iVar24 != 2;
                iVar24 = iVar24 + 1;
                *(undefined4 *)(iVar23 + (int)local_60) = 0;
                puVar21[0xd] = puVar21[0xd] & 0xffc0ffff | 0x40000;
                *(short *)((int)puVar21 + 0x36) = sVar3;
                *(undefined4 *)((int)&local_ec + iVar23) = 0;
                iVar23 = iVar23 + 4;
                puVar21[7] = puVar21[7] & 0xffc0ffff | 0x40000;
                *(short *)((int)puVar21 + 0x1e) = sVar3;
                puVar21[7] = puVar21[7] | 0x400000;
                puVar21 = puVar21 + 1;
              } while (bVar1);
              iVar6 = ((int (*)())FUN_0003ef50)(param_1,7,&local_f0);
              uVar13 = local_ec;
              if (iVar6 == 0) {
                *local_f0 = 0x5b;
                local_f0[1] = local_ec;
                local_f0[2] = local_f4;
                local_f0[3] = local_a8;
                local_f0[4] = local_d8;
                local_f0[5] = local_b0;
                local_f0[6] = local_e0;
                iVar6 = ((int (*)())FUN_0003ef50)(param_1,7,&local_f0);
                if (iVar6 == 0) {
                  *local_f0 = 0x5b;
                  local_6c = local_e8;
                  local_f0[1] = local_e8;
                  local_f0[2] = local_f4;
                  local_f0[3] = local_ac;
                  local_f0[4] = local_dc;
                  local_f0[5] = local_b0;
                  local_f0[6] = local_e0;
                  local_f4 = local_f4 | 0x100;
                  iVar6 = ((int (*)())FUN_0003ef50)(param_1,5,&local_f0);
                  uVar22 = local_d4;
                  if (iVar6 == 0) {
                    *local_f0 = 0x20;
                    local_f0[1] = uVar13;
                    local_f0[2] = local_f4;
                    local_f0[3] = local_d4;
                    local_70 = local_d0;
                    local_f0[4] = local_d0;
                    local_f4 = local_f4 & 0xfffffeff;
                    iVar6 = ((int (*)())FUN_0003ef50)(param_1,5,&local_f0);
                    if (iVar6 == 0) {
                      *local_f0 = 3;
                      local_f0[1] = local_6c;
                      local_f0[2] = local_f4;
                      local_f0[3] = uVar22;
                      local_f0[4] = uVar22;
                      iVar6 = ((int (*)())FUN_0003ef50)(param_1,5,&local_f0);
                      if (iVar6 == 0) {
                        *local_f0 = 0x49;
                        local_f0[1] = uVar13;
                        local_f0[2] = local_f4;
                        local_f0[3] = uVar22;
                        local_f0[4] = uVar22;
                        iVar6 = ((int (*)())FUN_0003ef50)(param_1,5,&local_f0);
                        uVar13 = local_d4;
                        if (iVar6 == 0) {
                          *local_f0 = 0x49;
                          local_f0[1] = local_6c;
                          local_f0[2] = local_f4;
                          local_f0[3] = uVar22;
                          local_f0[4] = local_70;
                          iVar6 = ((int (*)())FUN_0003ef50)(param_1,7,&local_f0);
                          if (iVar6 == 0) {
                            *local_f0 = 0x23;
                            local_f0[1] = local_e4;
                            local_f0[2] = local_f4;
                            local_f0[3] = uVar13 | 0x400000;
                            local_f0[4] = (uint)((unsigned char *)0x00004555);
                            local_f0[5] = uVar13 | 0x400000;
                            local_f0[6] = (uint)((unsigned char *)0x00004555);
                            local_d0 = local_d0 | 0x400000;
                            iVar6 = ((int (*)())FUN_0003ef50)(param_1,7,&local_f0);
                            if (iVar6 == 0) {
                              *local_f0 = 0x40;
                              local_f0[1] = local_f8;
                              local_f0[2] = local_f4;
                              local_f0[3] = local_d4;
                              local_f0[4] = local_cc;
                              local_f0[5] = local_d0;
                              local_f0[6] = 0xba98;
                              goto LAB_00048c78;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            goto LAB_00048418;
          }
          if (uVar22 == 0x22) {
            iVar23 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
            iVar24 = iVar23 + iVar5;
            puVar21 = (uint *)(iVar24 + 0x10);
            iVar6 = (*(uint *)(iVar24 + 0x10) >> 0xe & 1) + (*(uint *)(iVar24 + 0x18) >> 0xe & 1);
            if ((iVar6 == 1) &&
               (((*(uint *)(iVar24 + 0x10) & 0x3000) == 0 ||
                ((*(uint *)(iVar24 + 0x18) & 0x3000) == 0)))) {
              iVar6 = ((int (*)())FUN_00046a30)(param_1,iVar18);
              goto joined_r0x00048448;
            }
            local_60 = &local_d4;
            _memset(local_60,0,0x24);
            local_d4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_d4) + 0)),0x49);
            iVar23 = ((int (*)())FUN_0003f750)(param_1,iVar24 + 8,&local_d0,&local_cc,
                                  *(uint *)(iVar5 + iVar23 + 4) >> 0x14 & 1);
            if (((iVar23 != 0) ||
                (iVar23 = ((int (*)())FUN_0003f1c0)(param_1,puVar21,&local_c8,&local_bc), iVar23 != 0)) ||
               (iVar23 = ((int (*)())FUN_0003f1c0)(param_1,(uint *)(iVar24 + 0x18),&local_c4,local_b8),
               uVar22 = local_cc, uVar13 = local_d0, iVar23 != 0)) {
LAB_000479ec:
              iVar6 = param_1[9];
              goto joined_r0x00048448;
            }
            if (iVar6 == 0) {
              iVar6 = ((int (*)())FUN_0003fbf0)(param_1,local_60,1,2);
joined_r0x000479e8:
              if (iVar6 != 0) goto LAB_000479ec;
            }
            else if (iVar6 != 1) {
              uVar10 = (undefined2)param_1[8];
              local_d0 = CONCAT22(4,uVar10);
              local_68 = uVar13;
              iVar23 = (*puVar21 >> 0xc & 3) + 1;
              iVar6 = iVar23 + param_1[8];
              local_64 = local_cc;
              param_1[8] = iVar6;
              local_cc = 0x55;
              local_d0 = local_d0 | 0x400000;
              if (iVar23 != 0) {
                local_5c = &local_b0;
                iVar6 = 0;
                do {
                  uVar22 = *puVar21 >> 0xc & 3;
                  _memcpy(local_5c,local_60,0x24);
                  iVar14 = param_1[8];
                  uVar13 = (uint)local_b8[0] >> 3 & 1;
                  local_ac = CONCAT22(4,(short)iVar14);
                  local_a8 = 0x55;
                  local_94 = (undefined *)
                             (uVar13 << 0xf |
                             ((uint)local_b8[0] & 7) << 0xc |
                             uVar13 << 0xb |
                             ((uint)local_b8[0] & 7) << 8 |
                             uVar13 << 7 |
                             ((uint)local_b8[0] & 7) << 4 |
                             uVar13 << 3 | (uint)local_b8[0] & 7 | (uint)local_94 & 0xffff0000);
                  local_ac = local_ac | 0x400000;
                  iVar24 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,2);
                  if (iVar24 == 0) {
                    local_9c = CONCAT22(4,(short)iVar14);
                    local_a4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_a4) + 0)),(*(unsigned short *)((unsigned char *)&(local_a4) + 2)) + 1);
                    local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),0x40);
                    local_90 = ((unsigned char *)0x00003210);
                    local_9c = local_9c | 0x400000;
                    if (uVar22 == 1) {
                      local_ac = local_d0;
                      local_a8 = local_cc;
                    }
                    uVar11 = (uint)local_b8[0] >> 4 & 7;
                    uVar13 = (uint)local_b8[0] >> 7 & 1;
                    local_94 = (undefined *)
                               (uVar13 << 0xf |
                               uVar11 << 0xc |
                               uVar13 << 0xb |
                               uVar11 << 8 |
                               uVar13 << 7 |
                               uVar11 << 4 | uVar13 << 3 | uVar11 | (uint)local_94 & 0xffff0000);
                    iVar24 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,3);
                    if ((iVar24 == 0) && (1 < uVar22)) {
                      local_a4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_a4) + 0)),(*(unsigned short *)((unsigned char *)&(local_a4) + 2)) + 1);
                      if (uVar22 == 2) {
                        local_ac = local_d0;
                        local_a8 = local_cc;
                      }
                      uVar11 = (uint)local_b8[0] >> 8 & 7;
                      uVar13 = (uint)local_b8[0] >> 0xb & 1;
                      local_94 = (undefined *)
                                 (uVar13 << 0xf |
                                 uVar11 << 0xc |
                                 uVar13 << 0xb |
                                 uVar11 << 8 |
                                 uVar13 << 7 |
                                 uVar11 << 4 | uVar13 << 3 | uVar11 | (uint)local_94 & 0xffff0000);
                      iVar24 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,3);
                      if ((iVar24 == 0) && (uVar22 == 3)) {
                        uVar22 = (uint)local_b8[0] >> 0xc & 7;
                        uVar13 = (uint)local_b8[0] >> 0xf & 1;
                        local_ac = local_d0;
                        local_a8 = local_cc;
                        local_a4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_a4) + 0)),(*(unsigned short *)((unsigned char *)&(local_a4) + 2)) + 1);
                        local_94 = (undefined *)
                                   (uVar13 << 0xf |
                                   uVar22 << 0xc |
                                   uVar13 << 0xb |
                                   uVar22 << 8 |
                                   uVar13 << 7 |
                                   uVar22 << 4 | uVar13 << 3 | uVar22 | (uint)local_94 & 0xffff0000)
                        ;
                        ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,3);
                      }
                    }
                  }
                  iVar6 = iVar6 + 1;
                  local_d0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_d0) + 0)),(*(unsigned short *)((unsigned char *)&(local_d0) + 2)) + 1);
                  local_c4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_c4) + 0)),(*(unsigned short *)((unsigned char *)&(local_c4) + 2)) + 1);
                } while (iVar23 != iVar6);
                iVar6 = param_1[8];
              }
              local_c8 = CONCAT22(4,uVar10);
              param_1[8] = iVar6 - iVar23;
              local_d4 = 0x47;
              local_bc = ((unsigned char *)0x00003210);
              local_d0 = local_68;
              local_cc = local_64;
              local_c8 = local_c8 | 0x400000;
              if (iVar23 != 0) {
                iVar6 = 0;
                do {
                  iVar6 = iVar6 + 1;
                  ((int (*)())FUN_0003fbf0)(param_1,local_60,1,1);
                  local_d0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_d0) + 0)),(*(unsigned short *)((unsigned char *)&(local_d0) + 2)) + 1);
                  local_c8 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_c8) + 0)),(*(unsigned short *)((unsigned char *)&(local_c8) + 2)) + 1);
                } while (iVar23 != iVar6);
              }
            }
            else {
              if ((*puVar21 & 0x4000) == 0) {
                uVar11 = local_cc & 3;
                local_d0 = CONCAT22(4,(short)param_1[8]);
                local_cc = 0;
                local_d4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_d4) + 0)),0x23);
                local_d0 = local_d0 | 0x400000;
                do {
                  iVar6 = 0;
                  bVar1 = uVar11 == 1;
                  while( true ) {
                    if (bVar1) {
                      uVar4 = local_cc & 0xffffff00;
                      if (iVar6 == 0) {
                        local_cc = uVar4 | 1;
                      }
                      else if (iVar6 == 1) {
                        local_cc = uVar4 | 4;
                      }
                      else if (iVar6 == 2) {
                        local_cc = uVar4 | 0x10;
                      }
                      else {
                        local_cc = local_cc & 0xffffff00 | 0x40;
                      }
                      iVar23 = ((int (*)())FUN_0003fbf0)(param_1,local_60,1,2);
                      if (iVar23 != 0) goto LAB_000479ec;
                    }
                    iVar6 = iVar6 + 1;
                    local_c4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_c4) + 0)),(*(unsigned short *)((unsigned char *)&(local_c4) + 2)) + 1);
                    if ((int)(*(uint *)(iVar24 + 0x18) >> 0xc & 3) < iVar6) {
                      local_c8 = CONCAT22(4,(short)param_1[8]);
                      local_d4 = 0x47;
                      local_bc = ((unsigned char *)0x00003210);
                      local_c8 = local_c8 | 0x400000;
                      local_d0 = uVar13;
                      local_cc = uVar22;
                      iVar6 = ((int (*)())FUN_0003fbf0)(param_1,local_60,1,1);
                      goto joined_r0x000479e8;
                    }
                    if (iVar6 == 0) break;
                    if (iVar6 == 1) {
                      bVar1 = (uVar22 & 0xc) == 4;
                    }
                    else if (iVar6 == 2) {
                      bVar1 = (uVar22 & 0x30) == 0x10;
                    }
                    else {
                      bVar1 = (uVar22 & 0xc0) == 0x40;
                    }
                  }
                } while( true );
              }
              local_5c = &local_b0;
              uVar22 = *puVar21 >> 0xc & 3;
              _memcpy(local_5c,local_60,0x24);
              iVar6 = param_1[8];
              uVar13 = (uint)local_b8[0] >> 3 & 1;
              local_ac = CONCAT22(4,(short)iVar6);
              local_a8 = 0x55;
              local_94 = (undefined *)
                         (uVar13 << 0xf |
                         ((uint)local_b8[0] & 7) << 0xc |
                         uVar13 << 0xb |
                         ((uint)local_b8[0] & 7) << 8 |
                         uVar13 << 7 |
                         ((uint)local_b8[0] & 7) << 4 |
                         uVar13 << 3 | (uint)local_b8[0] & 7 | (uint)local_94 & 0xffff0000);
              local_ac = local_ac | 0x400000;
              iVar23 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,2);
              if (iVar23 == 0) {
                local_9c = CONCAT22(4,(short)iVar6);
                local_a4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_a4) + 0)),(*(unsigned short *)((unsigned char *)&(local_a4) + 2)) + 1);
                local_90 = ((unsigned char *)0x00003210);
                local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),0x40);
                local_9c = local_9c | 0x400000;
                if (uVar22 == 1) {
                  local_ac = local_d0;
                  local_a8 = local_cc;
                }
                uVar11 = (uint)local_b8[0] >> 4 & 7;
                uVar13 = (uint)local_b8[0] >> 7 & 1;
                local_94 = (undefined *)
                           (uVar13 << 0xf |
                           uVar11 << 0xc |
                           uVar13 << 0xb |
                           uVar11 << 8 |
                           uVar13 << 7 |
                           uVar11 << 4 | uVar13 << 3 | uVar11 | (uint)local_94 & 0xffff0000);
                iVar6 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,3);
                if ((iVar6 == 0) && (1 < uVar22)) {
                  local_a4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_a4) + 0)),(*(unsigned short *)((unsigned char *)&(local_a4) + 2)) + 1);
                  if (uVar22 == 2) {
                    local_ac = local_d0;
                    local_a8 = local_cc;
                  }
                  uVar11 = (uint)local_b8[0] >> 8 & 7;
                  uVar13 = (uint)local_b8[0] >> 0xb & 1;
                  local_94 = (undefined *)
                             (uVar13 << 0xf |
                             uVar11 << 0xc |
                             uVar13 << 0xb |
                             uVar11 << 8 |
                             uVar13 << 7 |
                             uVar11 << 4 | uVar13 << 3 | uVar11 | (uint)local_94 & 0xffff0000);
                  iVar6 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,3);
                  if ((iVar6 == 0) && (uVar22 == 3)) {
                    uVar22 = (uint)local_b8[0] >> 0xc & 7;
                    uVar13 = (uint)local_b8[0] >> 0xf & 1;
                    local_ac = local_d0;
                    local_a8 = local_cc;
                    local_a4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_a4) + 0)),(*(unsigned short *)((unsigned char *)&(local_a4) + 2)) + 1);
                    local_94 = (undefined *)
                               (uVar13 << 0xf |
                               uVar22 << 0xc |
                               uVar13 << 0xb |
                               uVar22 << 8 |
                               uVar13 << 7 |
                               uVar22 << 4 | uVar13 << 3 | uVar22 | (uint)local_94 & 0xffff0000);
                    ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,3);
                  }
                }
              }
            }
            goto LAB_00048c78;
          }
          if (((uVar22 - 0x1f < 2) || (uVar22 == 0x23)) || (uVar22 == 0x3a)) {
            iVar6 = ((int (*)())FUN_00046a30)(param_1,iVar18);
            goto joined_r0x0004802c;
          }
          if (uVar22 == 0x6c) {
            local_5c = &local_b0;
            iVar14 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
            _memset(local_5c,0,0x24);
            iVar23 = iVar14 + iVar5;
            iVar24 = iVar23 + 8;
            iVar6 = ((int (*)())FUN_0003ed50)(param_1,iVar24);
            if (iVar6 == 1) {
              local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),99);
            }
            else if (iVar6 == 2) {
              local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),0x56);
              local_b0 = local_b0 & 0xc000ffff;
            }
            else {
              local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),0x47);
            }
            iVar24 = ((int (*)())FUN_0003f750)(param_1,iVar24,&local_ac,&local_a8,
                                  *(uint *)(iVar5 + iVar14 + 4) >> 0x14 & 1);
            if ((iVar24 == 0) &&
               (iVar23 = ((int (*)())FUN_0003f1c0)(param_1,iVar23 + 0x10,&local_a4,&local_98), iVar23 == 0)) {
              uVar9 = 1;
              if (iVar6 == 2) {
                uVar9 = 2;
                local_94 = (undefined *)((uint)local_94 & 0xffff0000 | 0x4444);
                local_a0 = CONCAT22((short)(local_a0 >> 0x10),(short)param_1[8]) & 0xffc0ffff |
                           0x440000;
              }
              iVar6 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,uVar9);
              goto joined_r0x00048414;
            }
            goto LAB_00048418;
          }
          if (uVar22 == 8) {
            iVar6 = ((int (*)())FUN_000467a0)(param_1,iVar18,0);
joined_r0x00048448:
            if (iVar6 != 0) {
LAB_00048d74:
              return param_1[9];
            }
            goto LAB_00048c78;
          }
          if (uVar22 == 9) {
            iVar6 = ((int (*)())FUN_00046180)(param_1,iVar18,0);
            goto joined_r0x00048448;
          }
          if (uVar22 == 10) {
            local_5c = &local_b0;
            iVar23 = *param_1;
            iVar6 = *(int *)(iVar23 + 0x54);
            _memset(local_5c,0,0x24);
            iVar23 = iVar23 + iVar6 * 8 + iVar5;
            local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),0x5b);
            iVar6 = ((int (*)())FUN_0003f750)(param_1,iVar23 + 8,&local_ac,&local_a8,1);
            if (iVar6 == 0) {
              local_98 = (undefined *)((uint)local_98 & 0xffff0000 | 0x5555);
              local_a4 = CONCAT22((short)(local_a4 >> 0x10),(short)param_1[8]) & 0xffc0ffff |
                         0x440000;
              iVar6 = ((int (*)())FUN_0003f1c0)(param_1,iVar23 + 0x10,&local_a0,&local_94);
              if (iVar6 == 0) {
                iVar6 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,2);
joined_r0x00048414:
                if (iVar6 == 0) goto LAB_00048c78;
              }
            }
            goto LAB_00048418;
          }
          if (uVar22 == 0x26) {
            local_5c = &local_b0;
            iVar23 = *param_1;
            iVar6 = *(int *)(iVar23 + 0x54);
            _memset(local_5c,0,0x24);
            iVar23 = iVar23 + iVar6 * 8 + iVar5;
            local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),0x5b);
            local_a8 = local_a8 & 0xffffff00 | 0x55;
            local_ac = CONCAT22((short)(local_ac >> 0x10),(short)param_1[8]) & 0xffc0ffff | 0x440000
            ;
            iVar6 = ((int (*)())FUN_0003f1c0)(param_1,iVar23 + 0x10,&local_a4,&local_98);
            if (((iVar6 == 0) &&
                (iVar6 = ((int (*)())FUN_0003f1c0)(param_1,iVar23 + 0x18,&local_a0,&local_94), iVar6 == 0)) &&
               (iVar6 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,2), iVar6 == 0)) {
              local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),1);
              iVar6 = ((int (*)())FUN_0003f750)(param_1,iVar23 + 8,&local_ac,&local_a8,1);
              if (iVar6 == 0) {
                local_a4 = CONCAT22(4,(short)param_1[8]);
                local_98 = ((unsigned char *)0x00003210);
                local_a4 = local_a4 | 0x400000;
                iVar6 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,1);
                goto joined_r0x00048414;
              }
            }
            goto LAB_00048418;
          }
          if (uVar22 == 0x39) {
            iVar6 = ((int (*)())FUN_000457f0)(param_1,iVar18);
            goto joined_r0x00048448;
          }
          if (uVar22 == 0x6d) {
            iVar6 = ((int (*)())FUN_00044c90)(param_1,iVar18);
            goto joined_r0x00048448;
          }
          if ((uVar22 == 0x31) || (uVar22 == 0x36)) {
            iVar6 = *param_1 + *(int *)(*param_1 + 0x54) * 8;
            if ((param_1[5] & 0x20000000U) == 0) {
              local_7c = 0;
              local_78 = 0;
            }
            else {
              local_78 = *(uint *)(iVar6 + iVar5 + 0x10) >> 0xe & 1;
              local_7c = *(uint *)(iVar6 + iVar5 + 0x18) >> 0xe & 1;
            }
            puVar26 = (uint *)(iVar5 + iVar6 + 0x10);
            puVar21 = (uint *)(iVar5 + iVar6 + 0x18);
            local_74 = (uint *)(iVar5 + iVar6);
            local_5c = &local_b0;
            local_80 = (local_74[1] >> 0x1a & 3) + 1;
            local_84 = (*puVar26 >> 0xc & 3) + 1;
            local_88 = (*puVar21 >> 0xc & 3) + 1;
            _memset(local_5c,0,0x24);
            local_b0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b0) + 0)),0x56);
            local_b0 = (uint)((*(uint *)(iVar5 + iVar6) & 0x3fc0000) == 0xc40000) << 0x10 |
                       local_b0 & 0xc000ffff;
            iVar23 = ((int (*)())FUN_0003f1c0)(param_1,puVar26,&local_a4,&local_98);
            if ((iVar23 == 0) &&
               (iVar23 = ((int (*)())FUN_0003f1c0)(param_1,puVar21,&local_a0,&local_94), iVar23 == 0)) {
              if (local_80 < 2) {
                local_ac = CONCAT22(4,(short)param_1[8]);
                local_a8 = 0x55;
                local_ac = local_ac | 0x400000;
                iVar23 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,2);
                if (iVar23 == 0) {
                  iVar23 = local_84;
                  if (local_84 < local_88) {
                    iVar23 = local_88;
                  }
                  bVar1 = local_78 != 0;
                  if (((bVar1) || (local_7c != 0)) && (1 < iVar23)) {
                    local_60 = &local_d4;
                    local_ac = CONCAT22((*(unsigned short *)((unsigned char *)&(local_ac) + 0)),(short)param_1[8] + 1);
                    _memset(local_60,0,0x24);
                    uVar10 = 0x49;
                    if ((*(uint *)(iVar5 + iVar6) & 0x3fc0000) != 0xc40000) {
                      uVar10 = 3;
                    }
                    local_d4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_d4) + 0)),uVar10);
                    sVar3 = (short)param_1[8];
                    local_d0 = CONCAT22(4,sVar3);
                    iVar6 = 1;
                    local_c4 = CONCAT22(4,sVar3 + 1);
                    local_c8 = CONCAT22(4,sVar3);
                    local_cc = 0x55;
                    bVar2 = local_7c != 0;
                    local_b8[0] = ((unsigned char *)0x00003210);
                    local_bc = ((unsigned char *)0x00003210);
                    local_d0 = local_d0 | 0x400000;
                    local_c4 = local_c4 | 0x400000;
                    local_c8 = local_c8 | 0x400000;
                    do {
                      if (bVar1) {
                        local_a4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_a4) + 0)),(*(unsigned short *)((unsigned char *)&(local_a4) + 2)) + 1);
                      }
                      if (bVar2) {
                        local_a0 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_a0) + 0)),(*(unsigned short *)((unsigned char *)&(local_a0) + 2)) + 1);
                      }
                      iVar24 = ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,2);
                      if ((iVar24 != 0) ||
                         (iVar24 = ((int (*)())FUN_0003fbf0)(param_1,local_60,1,2), iVar24 != 0))
                      goto LAB_000488e8;
                      iVar6 = iVar6 + 1;
                    } while (iVar23 != iVar6);
                  }
                  if ((*local_74 & 0x3fc0000) == 0xc40000) {
                    iVar6 = ((int (*)())FUN_00046180)(param_1,iVar18,iVar23);
                    goto joined_r0x0004802c;
                  }
                  local_60 = &local_d4;
                  iVar23 = *param_1;
                  iVar6 = *(int *)(iVar23 + 0x54);
                  _memset(local_60,0,0x24);
                  local_d4 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_d4) + 0)),0x23);
                  iVar6 = ((int (*)())FUN_0003f750)(param_1,iVar23 + iVar6 * 8 + iVar5 + 8,&local_d0,&local_cc,1)
                  ;
                  if (iVar6 == 0) {
                    local_c8 = CONCAT22(4,(short)param_1[8]);
                    local_bc = ((unsigned char *)0x00003210);
                    local_b8[0] = (undefined *)((uint)local_b8[0] & 0xffff0000 | 0x5555);
                    local_c8 = local_c8 | 0x400000;
                    local_c4 = CONCAT22((short)(local_c4 >> 0x10),(short)param_1[8]) & 0xffc0ffff |
                               0x440000;
                    iVar6 = ((int (*)())FUN_0003fbf0)(param_1,local_60,1,2);
                    if (iVar6 == 0) goto LAB_00048c70;
                  }
                }
                goto LAB_000488e8;
              }
              ((int (*)())FUN_0003f750)(param_1,iVar5 + iVar6 + 8,&local_ac,&local_a8,0);
              ((int (*)())FUN_0003fbf0)(param_1,local_5c,1,2);
              iVar6 = param_1[9];
            }
            else {
LAB_000488e8:
              iVar6 = param_1[9];
            }
joined_r0x0004802c:
            if (iVar6 != 0) goto LAB_00048d74;
            goto LAB_00048c70;
          }
          if (uVar22 != 0x4d) break;
        }
        iVar17 = iVar17 + 1;
        iVar18 = iVar18 + iVar15;
        if (iVar16 == iVar17) goto LAB_00048d20;
        iVar5 = iVar18 * 8;
        puVar19 = puVar20 + iVar18 * 2;
        uVar22 = puVar20[iVar18 * 2] >> 0x12 & 0xff;
        iVar8 = uVar22 * 0x10;
        uVar13 = *(uint *)(&DAT_001dac34 + iVar8) >> 0x11 & 0xf;
        if ((uVar13 == 0) || ((*(uint *)(&DAT_001dac40 + iVar8) >> 0x1c & DAT_001db344) != 0))
        break;
      } while( true );
    }
    iVar8 = param_1[9];
    if (iVar8 == 0) {
      iVar8 = 3;
      param_1[9] = 3;
    }
  }
  return iVar8;
}

/* FUN_00048da0 @ 0x48da0 (6552 bytes) */
int FUN_00048da0(param_1)
  int *param_1;
{
  undefined **ppuVar1;
  undefined4 *puVar2;
  bool bVar3;
  ushort uVar4;
  short sVar5;
  undefined2 uVar6;
  short sVar7;
  double dVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  undefined4 in_r4;
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
  int in_r5;
  undefined4 in_r6;
  undefined4 *puVar15;
  dword *pdVar16;
  int iVar17;
  uint uVar18;
  undefined4 *puVar19;
  undefined **ppuVar20;
  int *piVar21;
  undefined *puVar22;
  uint uVar23;
  undefined4 uVar24;
  uint uVar25;
  undefined4 *puVar26;
  int iVar27;
  undefined4 local_b8;
  undefined4 local_b4;
  uint local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined *local_a0 [10];
  undefined4 local_78;
  uint uStack_74;
  undefined4 local_70;
  uint uStack_6c;
  undefined4 local_68;
  uint uStack_64;
  undefined4 local_60;
  uint uStack_5c;
  
  piVar21 = (int *)*param_1;
  if (piVar21 == (int *)0x0) {
    if (param_1[9] != 0) {
      return param_1[9];
    }
    param_1[9] = 2;
    return 2;
  }
  param_1[8] = piVar21[4] + piVar21[0xc] + 1;
  iVar12 = *piVar21;
  if ((iVar12 != 0x8804) && (iVar12 != 0x8b30)) {
switchD_00049180_caseD_0:
    if (param_1[9] != 0) {
      return param_1[9];
    }
LAB_0004a4ec:
    param_1[9] = 3;
    return 3;
  }
  piVar21 = param_1 + 10;
  param_1[5] = (uint)(iVar12 - 0x8b30U < 2) << 0x1d | param_1[5] & 0xdfffffffU;
  iVar12 = param_1[0xb];
  uVar9 = param_1[0xc];
  if (uVar9 < iVar12 + 2U) {
    if (uVar9 == 0) {
      uVar9 = 0x10;
    }
    else {
      uVar9 = uVar9 << 1;
    }
    for (; uVar9 < iVar12 + 2U; uVar9 = uVar9 << 1) {
    }
    if (*piVar21 == 0) {
      iVar12 = _malloc(uVar9 << 2);
      in_r4 = extraout_r4;
    }
    else {
      iVar12 = _realloc(*piVar21,uVar9 << 2);
      in_r4 = extraout_r4_00;
    }
    if (iVar12 != 0) {
      *piVar21 = iVar12;
      param_1[0xc] = uVar9;
      iVar12 = param_1[0xb];
      goto LAB_00048eb4;
    }
    iVar12 = param_1[9];
    if (iVar12 == 0) {
      iVar12 = 1;
      param_1[9] = 1;
    }
    if (iVar12 != 0) {
      return iVar12;
    }
    puVar26 = (undefined4 *)0x0;
    pdVar16 = &MACH_HEADER.cputype;
  }
  else {
LAB_00048eb4:
    param_1[0xb] = iVar12 + 2;
    puVar26 = (undefined4 *)(iVar12 * 4 + *piVar21);
    pdVar16 = puVar26 + 1;
  }
  *puVar26 = 1;
  *pdVar16 = 0x10200;
  iVar27 = *param_1;
  iVar12 = *(int *)(iVar27 + 0x30);
  puVar10 = (uint *)(iVar27 + *(int *)(iVar27 + 0x34) * 8);
  if (0 < iVar12) {
    do {
      if (((*puVar10 >> 0x10 & 0xf) == 4) && ((*puVar10 & 0xe) != 0)) {
        *(uint *)(param_1[0xd] + 0x20) = *(uint *)(param_1[0xd] + 0x20) | 0x400000;
        iVar27 = *param_1;
        break;
      }
      puVar10 = puVar10 + 2;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
  }
  iVar13 = *(int *)(iVar27 + 0x48);
  iVar12 = iVar27 + *(int *)(iVar27 + 0x4c) * 8;
  if (0 < iVar13) {
    do {
      switch(*(undefined1 *)(iVar12 + 3)) {
      case 0:
      case 8:
      case 10:
        iVar12 = param_1[9];
        if (iVar12 == 0) goto LAB_0004a4ec;
        if (iVar12 != 0) {
          return iVar12;
        }
        goto LAB_00049048;
      case 1:
        param_1[5] = param_1[5] & 0xe7ffffffU | 0x10000000;
        break;
      case 2:
        param_1[5] = param_1[5] & 0xe7ffffffU | 0x18000000;
        break;
      case 3:
        param_1[5] = param_1[5] & 0xe7ffffffU | 0x8000000;
      }
      iVar13 = iVar13 + -1;
      iVar12 = iVar12 + 8;
    } while (iVar13 != 0);
  }
LAB_00049048:
  iVar12 = *(int *)(iVar27 + 0x20);
  iVar13 = param_1[0xb];
  uVar9 = param_1[0xc];
  uVar14 = iVar12 * 2 + iVar13;
  puVar10 = (uint *)(iVar27 + *(int *)(iVar27 + 0x24) * 8);
  if (uVar9 < uVar14) {
    if (uVar9 == 0) {
      uVar9 = 0x10;
    }
    else {
      uVar9 = uVar9 << 1;
    }
    for (; uVar9 < uVar14; uVar9 = uVar9 << 1) {
    }
    if (*piVar21 == 0) {
      iVar27 = _malloc(uVar9 << 2);
      in_r4 = extraout_r4_01;
    }
    else {
      iVar27 = _realloc(*piVar21,uVar9 << 2);
      in_r4 = extraout_r4_02;
    }
    if (iVar27 == 0) goto LAB_0004a55c;
    *piVar21 = iVar27;
    param_1[0xc] = uVar9;
    iVar13 = param_1[0xb];
  }
  param_1[0xb] = iVar12 * 2 + iVar13;
  puVar15 = (undefined4 *)(iVar13 * 4 + *piVar21);
  if (iVar12 < 1) {
LAB_0004921c:
    if ((param_1[5] & 0x18000000U) != 0) {
      iVar12 = param_1[0xb];
      uVar9 = param_1[0xc];
      if (uVar9 < iVar12 + 2U) {
        if (uVar9 == 0) {
          uVar9 = 0x10;
        }
        else {
          uVar9 = uVar9 << 1;
        }
        for (; uVar9 < iVar12 + 2U; uVar9 = uVar9 << 1) {
        }
        if (*piVar21 == 0) {
          iVar12 = _malloc(uVar9 << 2);
          in_r4 = extraout_r4_03;
        }
        else {
          iVar12 = _realloc(*piVar21,uVar9 << 2);
          in_r4 = extraout_r4_04;
        }
        if (iVar12 == 0) goto LAB_0004a55c;
        *piVar21 = iVar12;
        param_1[0xc] = uVar9;
        iVar12 = param_1[0xb];
      }
      param_1[0xb] = iVar12 + 2;
      puVar15 = (undefined4 *)(iVar12 * 4 + *piVar21);
      *puVar15 = 0x1ff0016;
      puVar15[1] = 0x100000;
    }
  }
  else {
    in_r5 = 0;
    do {
      uVar4 = *(ushort *)puVar10;
      if ((uVar4 & 0xf) == 1) {
        *puVar15 = 0x3ff0016;
switchD_00049180_caseD_1:
        puVar22 = ((unsigned char *)0x00160000);
      }
      else {
        *puVar15 = 0x1ff0016;
        switch(uVar4 & 0xf) {
        default:
          goto switchD_00049180_caseD_0;
        case 1:
          goto switchD_00049180_caseD_1;
        case 2:
          puVar22 = (undefined *)0x120000;
          break;
        case 3:
          puVar22 = (undefined *)0x130000;
          break;
        case 5:
          in_r5 = 1;
          puVar22 = (undefined *)0x100000;
          break;
        case 7:
          puVar22 = (undefined *)(*puVar10 & 0x1f | 0x110000);
        }
      }
      iVar12 = iVar12 + -1;
      puVar15[1] = puVar22;
      puVar15 = puVar15 + 2;
      puVar10 = puVar10 + 2;
    } while (iVar12 != 0);
    in_r6 = 0;
    if (in_r5 == 0) goto LAB_0004921c;
  }
  uVar9 = param_1[1];
  uVar14 = param_1[2];
  puVar19 = (undefined4 *)0x0;
  iVar27 = 0x10;
  iVar12 = 0;
  do {
    iVar13 = iVar12;
    switch(uVar14 & 0xf) {
    case 0:
      puVar15 = &local_b8;
      iVar13 = iVar12 + 1;
      puVar15[iVar12] = (int)puVar19 << 0x10 | 0xc000019;
      break;
    case 1:
      puVar15 = &local_b8;
      iVar13 = iVar12 + 1;
      puVar15[iVar12] = (int)puVar19 << 0x10 | 0xb000019;
      break;
    case 2:
      puVar15 = &local_b8;
      iVar13 = iVar12 + 1;
      puVar15[iVar12] = (int)puVar19 << 0x10 | 0x12000019;
      break;
    case 3:
      puVar15 = &local_b8;
      iVar13 = iVar12 + 1;
      puVar15[iVar12] = (int)puVar19 << 0x10 | 0xa000019;
      break;
    case 4:
      puVar15 = &local_b8;
      iVar13 = iVar12 + 1;
      puVar15[iVar12] = (int)puVar19 << 0x10 | 0x9000019;
    }
    iVar27 = iVar27 + -1;
    uVar23 = uVar9 << 0x1c;
    uVar9 = uVar9 >> 4;
    puVar19 = (undefined4 *)((int)puVar19 + 1);
    uVar14 = uVar23 | uVar14 >> 4;
    iVar12 = iVar13;
  } while (iVar27 != 0);
  iVar12 = param_1[0xb];
  uVar9 = param_1[0xc];
  if (uVar9 < (uint)(iVar13 + iVar12)) {
    if (uVar9 == 0) {
      uVar9 = 0x10;
    }
    else {
      uVar9 = uVar9 << 1;
    }
    for (; uVar9 < (uint)(iVar13 + iVar12); uVar9 = uVar9 << 1) {
    }
    if (*piVar21 == 0) {
      iVar27 = _malloc(uVar9 << 2);
      in_r4 = extraout_r4_05;
    }
    else {
      iVar27 = _realloc(*piVar21,uVar9 << 2);
      in_r4 = extraout_r4_06;
    }
    if (iVar27 != 0) {
      *piVar21 = iVar27;
      param_1[0xc] = uVar9;
      iVar12 = param_1[0xb];
      goto LAB_00049448;
    }
    iVar17 = param_1[9];
    if (iVar17 == 0) {
      iVar17 = 1;
      param_1[9] = 1;
    }
    iVar27 = 0;
    if (iVar17 != 0) {
      return iVar17;
    }
  }
  else {
LAB_00049448:
    iVar27 = iVar12 * 4;
    iVar12 = iVar13 + iVar12;
    param_1[0xb] = iVar12;
    iVar27 = iVar27 + *piVar21;
  }
  if (0 < iVar13) {
    iVar17 = 0;
    puVar15 = &local_b8;
    do {
      *(undefined4 *)(iVar17 + iVar27) = *(undefined4 *)(iVar17 + (int)puVar15);
      iVar17 = iVar17 + 4;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
  }
  dVar8 = DOUBLE_001aa1e0;
  iVar27 = *param_1;
  uVar9 = *(uint *)(iVar27 + 0x28);
  puVar10 = (uint *)(iVar27 + *(int *)(iVar27 + 0x2c) * 8);
  iVar27 = iVar27 + *(int *)(iVar27 + 0x6c) * 8;
  if (0 < (int)uVar9) {
    uVar14 = 0;
    do {
      uVar23 = *puVar10 & 0x1c000000;
      uVar18 = *puVar10 >> 0x10 & 0x1f;
      if ((((uVar23 != 0xc000000) && (uVar23 != 0x4000000)) && (uVar23 != 0x10000000)) &&
         (uVar23 != 0)) {
        iVar27 = param_1[9];
        if (iVar27 == 0) goto LAB_0004a4ec;
        goto LAB_0004980c;
      }
      if (uVar18 == 0x11) {
        iVar13 = param_1[0xb];
        uVar23 = param_1[0xc];
        if (uVar23 < iVar13 + 6U) {
          if (uVar23 == 0) {
            uVar23 = 0x10;
          }
          else {
            uVar23 = uVar23 << 1;
          }
          for (; uVar23 < iVar13 + 6U; uVar23 = uVar23 << 1) {
          }
          if (*piVar21 == 0) {
            iVar12 = _malloc(uVar23 << 2);
            in_r4 = extraout_r4_07;
          }
          else {
            iVar12 = _realloc(*piVar21,uVar23 << 2);
            in_r4 = extraout_r4_08;
          }
          if (iVar12 == 0) goto LAB_0004a55c;
          *piVar21 = iVar12;
          param_1[0xc] = uVar23;
          iVar13 = param_1[0xb];
        }
        iVar12 = iVar13 + 6;
        param_1[0xb] = iVar12;
        puVar19 = (undefined4 *)(iVar13 * 4 + *piVar21);
        *puVar19 = 0x1c;
        puVar19[1] = uVar14 & 0xffff | 0x10000;
        uVar23 = (uint)(ushort)*puVar10;
        if ((*puVar10 & 0x1c000000) == 0xc000000) {
          local_78 = 0x43300000;
          iVar13 = iVar27 + uVar23 * 0x10;
          uStack_74 = *(uint *)(uVar23 * 0x10 + iVar27) ^ 0x80000000;
          puVar19[2] = (float)((double)CONCAT44(0x43300000,uStack_74) - dVar8);
          local_70 = 0x43300000;
          uStack_6c = *(uint *)(iVar13 + 4) ^ 0x80000000;
          puVar19[3] = (float)((double)CONCAT44(0x43300000,uStack_6c) - dVar8);
          local_68 = 0x43300000;
          uStack_64 = *(uint *)(iVar13 + 8) ^ 0x80000000;
          puVar19[4] = (float)((double)CONCAT44(0x43300000,uStack_64) - dVar8);
          local_60 = 0x43300000;
          uStack_5c = *(uint *)(iVar13 + 0xc) ^ 0x80000000;
          puVar19[5] = (float)((double)CONCAT44(0x43300000,uStack_5c) - dVar8);
        }
        else if ((*puVar10 & 0x1c000000) == 0x10000000) {
          iVar13 = iVar27 + uVar23 * 0x10;
          puVar19[2] = (uint)(*(int *)(iVar27 + uVar23 * 0x10) != 0);
          puVar19[3] = (uint)(*(int *)(iVar13 + 4) != 0);
          puVar19[4] = (uint)(*(int *)(iVar13 + 8) != 0);
          puVar19[5] = (uint)(*(int *)(iVar13 + 0xc) != 0);
        }
        else {
          iVar13 = iVar27 + uVar23 * 0x10;
          puVar19[2] = *(undefined4 *)(iVar27 + uVar23 * 0x10);
          puVar19[3] = *(undefined4 *)(iVar13 + 4);
          puVar19[4] = *(undefined4 *)(iVar13 + 8);
          puVar19[5] = *(undefined4 *)(iVar13 + 0xc);
        }
      }
      uVar14 = uVar14 + 1;
      puVar10 = puVar10 + 2;
    } while (uVar9 != uVar14);
  }
  param_1[6] = param_1[0xb];
  iVar27 = param_1[0xb];
  uVar9 = param_1[0xc];
  if (uVar9 < iVar27 + 0xc6U) {
    if (uVar9 == 0) {
      uVar9 = 0x10;
    }
    else {
      uVar9 = uVar9 << 1;
    }
    for (; uVar9 < iVar27 + 0xc6U; uVar9 = uVar9 << 1) {
    }
    if (*piVar21 == 0) {
      iVar12 = _malloc(uVar9 << 2);
      in_r4 = extraout_r4_09;
    }
    else {
      iVar12 = _realloc(*piVar21,uVar9 << 2);
      in_r4 = extraout_r4_10;
    }
    if (iVar12 == 0) {
LAB_0004a55c:
      if (param_1[9] != 0) {
        return param_1[9];
      }
      param_1[9] = 1;
      return 1;
    }
    *piVar21 = iVar12;
    param_1[0xc] = uVar9;
    iVar27 = param_1[0xb];
  }
  iVar12 = iVar27 + 0xc6;
  param_1[0xb] = iVar12;
  uVar18 = iVar27 * 4 + *piVar21;
  iVar27 = 0;
  iVar13 = 0xc6;
  do {
    *(undefined4 *)(iVar27 + uVar18) = 0x4b;
    iVar27 = iVar27 + 4;
    iVar13 = iVar13 + -1;
  } while (iVar13 != 0);
  iVar27 = param_1[9];
  param_1[7] = param_1[0xb];
LAB_0004980c:
  if (iVar27 != 0) {
    return iVar27;
  }
  iVar12 = ((int (*)())FUN_00046e90)(param_1,in_r4,in_r5,in_r6,puVar15,iVar12,uVar18,puVar19);
  if (iVar12 != 0) goto LAB_0004a7b4;
  iVar12 = *param_1;
  uVar9 = *(uint *)(iVar12 + 0x30);
  puVar10 = (uint *)(iVar12 + *(int *)(iVar12 + 0x34) * 8);
  if (0 < (int)uVar9) {
    uVar14 = 0;
    do {
      if ((1 << (uVar14 & 0x3f) & param_1[4]) != 0) {
        uVar24 = 0x55;
        puVar22 = ((unsigned char *)0x00003210);
        uVar23 = uVar14 + *(int *)(*param_1 + 0x10) + 1 & 0xffff | 0x440000;
        if ((*(ushort *)puVar10 & 0xf) == 4) {
          iVar12 = param_1[0xd];
          if (((*(uint *)(iVar12 + 0x20) & 0x400000) != 0) ||
             (bVar3 = true, (*(uint *)(iVar12 + 0x20) >> 0x12 & 0xf) < 2)) {
            bVar3 = false;
          }
          uVar18 = param_1[5];
          param_1[5] = uVar18 | 0x80000000;
          uVar25 = *puVar10 >> 1 & 7 | 0x570000;
          if ((uVar18 & 0x18000000) != 0) {
            *(uint *)(iVar12 + 0x20) = *(uint *)(iVar12 + 0x20) | 0x2000000;
            uVar6 = (undefined2)param_1[8];
            sVar7 = ((ushort)((uint)*(undefined4 *)(param_1[0xd] + 0x20) >> 0x1a) & 1) +
                    (short)*(undefined4 *)(*param_1 + 0x28);
            _memset(&local_b8,0,0x24);
            sVar5 = sVar7 + 1;
            uVar18 = (uint)param_1[5] >> 0x1b & 3;
            local_b4 = CONCAT22(4,uVar6);
            local_b0 = 0x55;
            local_a0[0] = (undefined *)((uint)local_a0[0] & 0xffff0000);
            local_ac = (undefined *)((uint)local_ac & 0xffc0ffff | 0x500000);
            local_b4 = local_b4 | 0x400000;
            if (uVar18 == 1) {
              iVar12 = param_1[9];
              local_b8 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b8) + 0)),0x40);
              local_b0 = 0x155;
              local_a0[1] = (undefined *)0x0;
              local_a8 = CONCAT22(1,sVar5) | 0x400000;
              local_a0[2] = ((unsigned char *)0x00001111);
              local_a4 = CONCAT22(1,sVar5) | 0x400000;
              if (iVar12 == 0) {
                iVar12 = param_1[0xb];
                uVar18 = param_1[0xc];
                if (uVar18 < iVar12 + 9U) {
                  if (uVar18 == 0) {
                    uVar18 = 0x10;
                  }
                  else {
                    uVar18 = uVar18 << 1;
                  }
                  for (; uVar18 < iVar12 + 9U; uVar18 = uVar18 << 1) {
                  }
                  if (*piVar21 == 0) {
                    iVar12 = _malloc(uVar18 << 2);
                  }
                  else {
                    iVar12 = _realloc(*piVar21,uVar18 << 2);
                  }
                  if (iVar12 == 0) {
LAB_0004a188:
                    iVar12 = param_1[9];
                    if (iVar12 == 0) {
                      iVar12 = 1;
                      param_1[9] = 1;
                    }
                    goto LAB_0004a0d8;
                  }
                  *piVar21 = iVar12;
                  param_1[0xc] = uVar18;
                  iVar12 = param_1[0xb];
                }
                ppuVar20 = (undefined **)&local_ac;
                param_1[0xb] = iVar12 + 9;
                puVar15 = (undefined4 *)(iVar12 * 4 + *piVar21);
                *puVar15 = local_b8;
                puVar15[1] = local_b4;
                puVar15[2] = local_b0;
                do {
                  puVar15[3] = *ppuVar20;
                  ppuVar1 = ppuVar20 + 3;
                  ppuVar20 = ppuVar20 + 1;
                  puVar15[4] = *ppuVar1;
                  puVar15 = puVar15 + 2;
                } while (local_a0 != ppuVar20);
                goto LAB_0004a0d4;
              }
            }
            else {
              if ((uVar18 == 0) || (3 < uVar18)) goto LAB_0004a474;
              local_b8 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b8) + 0)),0x49);
              if ((param_1[5] & 0x18000000U) == 0x10000000) {
                local_a8 = CONCAT22(1,sVar5);
                iVar12 = param_1[9];
                local_a0[1] = (undefined *)0x2222;
                local_a8 = local_a8 | 0x400000;
                if (iVar12 == 0) {
                  iVar12 = param_1[0xb];
                  uVar18 = param_1[0xc];
                  if (uVar18 < iVar12 + 7U) {
                    if (uVar18 == 0) {
                      uVar18 = 0x10;
                    }
                    else {
                      uVar18 = uVar18 << 1;
                    }
                    for (; uVar18 < iVar12 + 7U; uVar18 = uVar18 << 1) {
                    }
                    if (*piVar21 == 0) {
                      iVar12 = _malloc(uVar18 << 2);
                    }
                    else {
                      iVar12 = _realloc(*piVar21,uVar18 << 2);
                    }
                    if (iVar12 == 0) {
LAB_00049f94:
                      iVar12 = param_1[9];
                      if (iVar12 == 0) {
                        iVar12 = 1;
                        param_1[9] = 1;
                      }
                      goto LAB_00049fa8;
                    }
                    *piVar21 = iVar12;
                    param_1[0xc] = uVar18;
                    iVar12 = param_1[0xb];
                  }
                  puVar19 = &local_ac;
                  param_1[0xb] = iVar12 + 7;
                  puVar15 = (undefined4 *)(iVar12 * 4 + *piVar21);
                  *puVar15 = local_b8;
                  puVar15[1] = local_b4;
                  puVar15[2] = local_b0;
                  do {
                    puVar15[3] = *puVar19;
                    puVar2 = puVar19 + 3;
                    puVar19 = puVar19 + 1;
                    puVar15[4] = *puVar2;
                    puVar15 = puVar15 + 2;
                  } while (&local_a4 != puVar19);
LAB_00049f80:
                  iVar12 = param_1[9];
                }
              }
              else {
                local_a8 = CONCAT22(1,sVar5);
                iVar12 = param_1[9];
                local_a8 = local_a8 | 0x400000;
                local_a0[1] = ((unsigned char *)0x00003333);
                if (iVar12 == 0) {
                  iVar12 = param_1[0xb];
                  uVar18 = param_1[0xc];
                  if (uVar18 < iVar12 + 7U) {
                    if (uVar18 == 0) {
                      uVar18 = 0x10;
                    }
                    else {
                      uVar18 = uVar18 << 1;
                    }
                    for (; uVar18 < iVar12 + 7U; uVar18 = uVar18 << 1) {
                    }
                    if (*piVar21 == 0) {
                      iVar12 = _malloc(uVar18 << 2);
                    }
                    else {
                      iVar12 = _realloc(*piVar21,uVar18 << 2);
                    }
                    if (iVar12 == 0) {
                      iVar12 = param_1[9];
                      if (iVar12 == 0) {
                        iVar12 = 1;
                        param_1[9] = 1;
                      }
                      goto LAB_00049e2c;
                    }
                    *piVar21 = iVar12;
                    param_1[0xc] = uVar18;
                    iVar12 = param_1[0xb];
                  }
                  puVar19 = &local_ac;
                  param_1[0xb] = iVar12 + 7;
                  puVar15 = (undefined4 *)(iVar12 * 4 + *piVar21);
                  *puVar15 = local_b8;
                  puVar15[1] = local_b4;
                  puVar15[2] = local_b0;
                  do {
                    puVar15[3] = *puVar19;
                    puVar2 = puVar19 + 3;
                    puVar19 = puVar19 + 1;
                    puVar15[4] = *puVar2;
                    puVar15 = puVar15 + 2;
                  } while (&local_a4 != puVar19);
                  iVar12 = param_1[9];
                }
LAB_00049e2c:
                local_ac = (undefined *)CONCAT22(4,uVar6);
                local_a8 = CONCAT22(4,uVar6);
                local_a0[0] = ((unsigned char *)0x00003210);
                local_a0[1] = ((unsigned char *)0x00003210);
                local_b8 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b8) + 0)),0x49);
                local_ac = (undefined *)((uint)local_ac | 0x400000);
                local_a8 = local_a8 | 0x400000;
                if (iVar12 == 0) {
                  iVar12 = param_1[0xb];
                  uVar18 = param_1[0xc];
                  if (uVar18 < iVar12 + 7U) {
                    if (uVar18 == 0) {
                      uVar18 = 0x10;
                    }
                    else {
                      uVar18 = uVar18 << 1;
                    }
                    for (; uVar18 < iVar12 + 7U; uVar18 = uVar18 << 1) {
                    }
                    if (*piVar21 == 0) {
                      iVar12 = _malloc(uVar18 << 2);
                    }
                    else {
                      iVar12 = _realloc(*piVar21,uVar18 << 2);
                    }
                    if (iVar12 == 0) goto LAB_00049f94;
                    *piVar21 = iVar12;
                    param_1[0xc] = uVar18;
                    iVar12 = param_1[0xb];
                  }
                  puVar19 = &local_ac;
                  param_1[0xb] = iVar12 + 7;
                  puVar15 = (undefined4 *)(iVar12 * 4 + *piVar21);
                  *puVar15 = local_b8;
                  puVar15[1] = local_b4;
                  puVar15[2] = local_b0;
                  do {
                    puVar15[3] = *puVar19;
                    puVar2 = puVar19 + 3;
                    puVar19 = puVar19 + 1;
                    puVar15[4] = *puVar2;
                    puVar15 = puVar15 + 2;
                  } while (&local_a4 != puVar19);
                  goto LAB_00049f80;
                }
              }
LAB_00049fa8:
              local_ac = (undefined *)CONCAT22(4,uVar6);
              local_b0 = local_b0 | 0x100;
              local_b8 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b8) + 0)),0x2d);
              local_ac = (undefined *)((uint)local_ac | 0x400000);
              local_a0[0] = (undefined *)0xba98;
              if (iVar12 != 0) goto LAB_0004a0d8;
              iVar12 = param_1[0xb];
              uVar18 = param_1[0xc];
              if (uVar18 < iVar12 + 5U) {
                if (uVar18 == 0) {
                  uVar18 = 0x10;
                }
                else {
                  uVar18 = uVar18 << 1;
                }
                for (; uVar18 < iVar12 + 5U; uVar18 = uVar18 << 1) {
                }
                if (*piVar21 == 0) {
                  iVar12 = _malloc(uVar18 << 2);
                }
                else {
                  iVar12 = _realloc(*piVar21,uVar18 << 2);
                }
                if (iVar12 == 0) goto LAB_0004a188;
                *piVar21 = iVar12;
                param_1[0xc] = uVar18;
                iVar12 = param_1[0xb];
              }
              param_1[0xb] = iVar12 + 5;
              puVar15 = (undefined4 *)(iVar12 * 4 + *piVar21);
              *puVar15 = local_b8;
              puVar15[1] = local_b4;
              puVar15[2] = local_b0;
              puVar15[3] = local_ac;
              puVar15[4] = local_a0[0];
LAB_0004a0d4:
              iVar12 = param_1[9];
            }
LAB_0004a0d8:
            iVar27 = *param_1;
            local_b8 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b8) + 0)),0x47);
            local_b0 = 0x155;
            sVar5 = (short)uVar14;
            local_b4 = CONCAT22(4,sVar5 + (short)*(undefined4 *)(iVar27 + 0x10) + 1);
            local_b4 = local_b4 | 0x400000;
            local_a0[0] = ((unsigned char *)0x00003210);
            local_ac = (undefined *)CONCAT22(4,sVar5 + (short)*(undefined4 *)(iVar27 + 0x10) + 1);
            local_ac = (undefined *)((uint)local_ac | 0x400000);
            if (iVar12 == 0) {
              iVar12 = param_1[0xb];
              uVar18 = param_1[0xc];
              if (uVar18 < iVar12 + 5U) {
                if (uVar18 == 0) {
                  uVar18 = 0x10;
                }
                else {
                  uVar18 = uVar18 << 1;
                }
                for (; uVar18 < iVar12 + 5U; uVar18 = uVar18 << 1) {
                }
                if (*piVar21 == 0) {
                  iVar12 = _malloc(uVar18 << 2);
                }
                else {
                  iVar12 = _realloc(*piVar21,uVar18 << 2);
                }
                if (iVar12 == 0) {
                  iVar12 = param_1[9];
                  if (iVar12 == 0) {
                    iVar12 = 1;
                    param_1[9] = 1;
                  }
                  iVar27 = *param_1;
                  goto LAB_0004a25c;
                }
                *piVar21 = iVar12;
                param_1[0xc] = uVar18;
                iVar12 = param_1[0xb];
              }
              param_1[0xb] = iVar12 + 5;
              puVar15 = (undefined4 *)(iVar12 * 4 + *piVar21);
              *puVar15 = local_b8;
              puVar15[1] = local_b4;
              puVar15[2] = local_b0;
              puVar15[3] = local_ac;
              puVar15[4] = local_a0[0];
              iVar27 = *param_1;
              iVar12 = param_1[9];
            }
LAB_0004a25c:
            local_b8 = CONCAT22((*(unsigned short *)((unsigned char *)&(local_b8) + 0)),0x3f);
            local_ac = (undefined *)CONCAT22(4,uVar6);
            local_b0 = 0x15;
            local_a0[0] = ((unsigned char *)0x00003210);
            local_b4 = CONCAT22(4,sVar5 + (short)*(undefined4 *)(iVar27 + 0x10) + 1);
            local_ac = (undefined *)((uint)local_ac | 0x400000);
            local_b4 = local_b4 | 0x400000;
            local_a4 = CONCAT22(1,sVar7);
            local_a0[1] = ((unsigned char *)0x00003210);
            local_a0[2] = ((unsigned char *)0x00003210);
            local_a8 = CONCAT22(4,sVar5 + (short)*(undefined4 *)(iVar27 + 0x10) + 1);
            local_a4 = local_a4 | 0x400000;
            local_a8 = local_a8 | 0x400000;
            if (iVar12 == 0) {
              iVar12 = param_1[0xb];
              uVar18 = param_1[0xc];
              if (uVar18 < iVar12 + 9U) {
                if (uVar18 == 0) {
                  uVar18 = 0x10;
                }
                else {
                  uVar18 = uVar18 << 1;
                }
                for (; uVar18 < iVar12 + 9U; uVar18 = uVar18 << 1) {
                }
                if (*piVar21 == 0) {
                  iVar12 = _malloc(uVar18 << 2);
                }
                else {
                  iVar12 = _realloc(*piVar21,uVar18 << 2);
                }
                if (iVar12 == 0) {
                  if (param_1[9] == 0) {
                    param_1[9] = 1;
                  }
                  goto LAB_0004a474;
                }
                *piVar21 = iVar12;
                param_1[0xc] = uVar18;
                iVar12 = param_1[0xb];
              }
              ppuVar20 = (undefined **)&local_ac;
              param_1[0xb] = iVar12 + 9;
              puVar15 = (undefined4 *)(iVar12 * 4 + *piVar21);
              *puVar15 = local_b8;
              puVar15[1] = local_b4;
              puVar15[2] = local_b0;
              do {
                puVar15[3] = *ppuVar20;
                ppuVar1 = ppuVar20 + 3;
                ppuVar20 = ppuVar20 + 1;
                puVar15[4] = *ppuVar1;
                puVar15 = puVar15 + 2;
              } while (local_a0 != ppuVar20);
            }
          }
LAB_0004a474:
          uVar18 = 0;
          if (bVar3) {
            do {
              if (((int)(*(uint *)(param_1[0xd] + 0x20) >> 0x12 & 0xf) >> (uVar18 & 0x3f) & 1U) != 0
                 ) {
                iVar12 = param_1[0xb];
                uVar11 = param_1[0xc];
                if (uVar11 < iVar12 + 5U) {
                  if (uVar11 == 0) {
                    uVar11 = 0x10;
                  }
                  else {
                    uVar11 = uVar11 << 1;
                  }
                  for (; uVar11 < iVar12 + 5U; uVar11 = uVar11 << 1) {
                  }
                  if (*piVar21 == 0) {
                    iVar12 = _malloc(uVar11 << 2);
                  }
                  else {
                    iVar12 = _realloc(*piVar21,uVar11 << 2);
                  }
                  if (iVar12 == 0) goto LAB_0004a55c;
                  *piVar21 = iVar12;
                  param_1[0xc] = uVar11;
                  iVar12 = param_1[0xb];
                }
                uVar25 = uVar18 & 0xffff | uVar25 & 0xffff0000;
                param_1[0xb] = iVar12 + 5;
                iVar27 = iVar12 * 4 + *piVar21;
                *(undefined4 *)(iVar12 * 4 + *piVar21) = 0x47;
                *(undefined **)(iVar27 + 0x10) = ((unsigned char *)0x00003210);
                *(uint *)(iVar27 + 4) = uVar25;
                *(undefined4 *)(iVar27 + 8) = 0x55;
                *(uint *)(iVar27 + 0xc) = uVar23;
              }
              bVar3 = uVar18 != 3;
              uVar18 = uVar18 + 1;
            } while (bVar3);
            goto LAB_0004a680;
          }
        }
        else {
          if ((*(ushort *)puVar10 & 0xf) != 7) goto switchD_00049180_caseD_0;
          uVar18 = param_1[5];
          uVar24 = 0x155;
          param_1[5] = uVar18 | 0x40000000;
          uVar25 = 0x580000;
          if ((uVar18 & 0x20000000) == 0) {
            puVar22 = ((unsigned char *)0x00003212);
          }
        }
        iVar12 = param_1[0xb];
        uVar18 = param_1[0xc];
        if (uVar18 < iVar12 + 5U) {
          if (uVar18 == 0) {
            uVar18 = 0x10;
          }
          else {
            uVar18 = uVar18 << 1;
          }
          for (; uVar18 < iVar12 + 5U; uVar18 = uVar18 << 1) {
          }
          if (*piVar21 == 0) {
            iVar12 = _malloc(uVar18 << 2);
          }
          else {
            iVar12 = _realloc(*piVar21,uVar18 << 2);
          }
          if (iVar12 == 0) goto LAB_0004a55c;
          *piVar21 = iVar12;
          param_1[0xc] = uVar18;
          iVar12 = param_1[0xb];
        }
        param_1[0xb] = iVar12 + 5;
        puVar15 = (undefined4 *)(iVar12 * 4 + *piVar21);
        *puVar15 = 0x47;
        puVar15[4] = puVar22;
        puVar15[1] = uVar25;
        puVar15[2] = uVar24;
        puVar15[3] = uVar23;
      }
LAB_0004a680:
      uVar14 = uVar14 + 1;
      puVar10 = puVar10 + 2;
    } while (uVar9 != uVar14);
  }
  iVar12 = param_1[0xb];
  uVar9 = param_1[0xc];
  if (uVar9 < iVar12 + 1U) {
    if (uVar9 == 0) {
      uVar9 = 0x10;
    }
    else {
      uVar9 = uVar9 << 1;
    }
    for (; uVar9 < iVar12 + 1U; uVar9 = uVar9 << 1) {
    }
    if (*piVar21 == 0) {
      iVar12 = _malloc(uVar9 << 2);
    }
    else {
      iVar12 = _realloc(*piVar21,uVar9 << 2);
    }
    if (iVar12 != 0) {
      *piVar21 = iVar12;
      param_1[0xc] = uVar9;
      iVar12 = param_1[0xb];
      goto LAB_0004a708;
    }
    iVar12 = param_1[9];
    if (iVar12 == 0) {
      iVar12 = 1;
      param_1[9] = 1;
    }
    if (iVar12 != 0) {
      return iVar12;
    }
  }
  else {
LAB_0004a708:
    param_1[0xb] = iVar12 + 1;
    puVar26 = (undefined4 *)(iVar12 * 4 + *piVar21);
  }
  *puVar26 = 0x28;
  iVar12 = param_1[7];
  iVar27 = iVar12 - param_1[6];
  if (iVar27 != 0) {
    _memmove(param_1[10] + param_1[6] * 4,param_1[10] + iVar12 * 4,(param_1[0xb] - iVar12) * 4);
    param_1[7] = param_1[6];
    param_1[0xb] = param_1[0xb] - iVar27;
  }
  if ((param_1[5] & 0xc0000000U) == 0) {
    ((int (*)())FUN_0003f850)(param_1);
  }
LAB_0004a7b4:
  return param_1[9];
}

/* FUN_0004a7d0 @ 0x4a7d0 (80 bytes) */
uint FUN_0004a7d0(double fparam_1)
{
  float fVar1;
  uint uVar2;
  uint uVar3;
  
  fVar1 = (float)fparam_1;
  uVar2 = (uint)GH_F2U(fVar1) >> 0x17 & 0xff;
  uVar3 = (uint)GH_F2U(fVar1) >> 8 & 0x800000;
  if (uVar2 < 0x41) {
    return 0;
  }
  if (0xbf < uVar2) {
    return uVar3 | 0x7fffff;
  }
  return (uint)GH_F2U(fVar1) >> 7 & 0xffff | uVar3 | (uVar2 - 0x40) * 0x10000;
}

/* FUN_0004a830 @ 0x4a830 (40 bytes) */
double FUN_0004a830(uint param_1)
{
  return (double)GH_U2F((unsigned int)(((param_1 & 0x800000) << 8 | ((param_1 >> 0x10 & 0x7f) + 0x40) * 0x800000 |
                        (param_1 & 0xffff) << 7)));
}

/* FUN_0004a860 @ 0x4a860 (112 bytes) */
int FUN_0004a860(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  char cVar1;
  
  if (((*(uint *)(param_1 + 0x44) & 0x20000) != 0) && (*(int *)(param_1 + 0x1e70) != 0)) {
    if ((*(uint *)(param_1 + 0x44) & 0x2000) == 0) {
      cVar1 = ((unsigned char *)0x00001136)[param_1];
    }
    else {
      cVar1 = ((unsigned char *)0x000011d0)[param_1];
    }
    if (cVar1 == '\0') {
                    
                    
      (**(code **)(param_1 + 0x294c))(param_1);
      return;
    }
  }
                    
                    
  (**(code **)(param_1 + 0x294c))(param_1,*(undefined4 *)(param_1 + 0x1e5c));
  return;
}

/* FUN_0004a8f0 @ 0x4a8f0 (140 bytes) */
void FUN_0004a8f0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fparam_1)
{
  if ((*(uint *)(param_1 + 0x44) & 0x20000) == 0) {
    FUN_000b6580(param_1,0);
                    
                    
    (**(code **)(param_1 + 0x294c))(param_1,*(undefined4 *)(param_1 + 0x1e5c));
    return;
  }
  if ((*(uint *)(param_1 + 0x44) & 0x2000) != 0) {
    ((undefined4 (*)())FUN_000afe40)(param_1,0,param_3,param_4,fparam_1);
    return;
  }
  FUN_000b3630(param_1);
  return;
}

/* FUN_0004a990 @ 0x4a990 (100 bytes) */
int FUN_0004a990(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  FUN_0004cde0(param_2 + 8);
  FUN_0004cde0(param_2 + 8);
  *param_2 = 0;
  param_2[7] = 0;
  if ((param_1 != 0) && (param_2 == *(undefined4 **)(param_1 + 0x1e68))) {
    *(undefined4 *)(param_1 + 0x1e68) = 0;
  }
  return;
}

/* FUN_0004aa00 @ 0x4aa00 (136 bytes) */
int FUN_0004aa00(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined1 *puVar2;
  
  puVar2 = *(undefined1 **)(((unsigned char *)0x00001488) + param_1);
  if ((puVar2 == (undefined1 *)0x0) ||
     ((*(int *)(puVar2 + 0x37cc) < 0x41 && (*(int *)(puVar2 + 0x37d0) < 0x41)))) {
    uVar1 = 0;
  }
  else {
    if (param_2 != 0) {
      *(undefined4 *)(param_1 + 0x1e68) = 0;
      *puVar2 = 0;
      *(undefined4 *)(((unsigned char *)0x00001488) + param_1) = 0;
    }
    FUN_00088190(param_1,puVar2);
    uVar1 = 1;
  }
  return uVar1;
}

/* FUN_0004aa90 @ 0x4aa90 (196 bytes) */
int FUN_0004aa90(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  
  if (((unsigned char *)0x000013b2)[param_1] != '\0') {
    iVar3 = 0;
    puVar2 = param_2;
    do {
      puVar1 = puVar2 + 1;
      iVar3 = iVar3 + 1;
      puVar2[0x22] = puVar2[0x22] & 0xfe001fc0 | 0xd10000;
      puVar2 = puVar2 + 1;
      *puVar2 = *puVar1 & 0xfffcffef;
    } while (iVar3 < (int)(uint)(byte)((unsigned char *)0x000013b2)[param_1]);
  }
  param_2[0x87] = 0;
  param_2[0x83] = 1;
  param_2[0x84] = 0;
  param_2[0x86] = 0;
  *param_2 = *param_2 & 0xfffffff0;
  param_2[1] = param_2[1] & 0xfffc0fff | 0x10000;
  param_2[0x22] = param_2[0x22] & 0xffffe03f;
  param_2[0x82] = param_2[0x82] & 0xfffff800 | 0x80;
  return;
}

/* FUN_0004ab60 @ 0x4ab60 (304 bytes) */
int FUN_0004ab60(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  FUN_000b6020(param_1,(*(uint *)(PTR_DAT_001e88c8 + (uint)*(byte *)(param_1 + 0x293f) * 0x24 + 0x20
                                 ) ^ 0x800000) >> 0x17 & 1,1);
  *(uint *)(((unsigned char *)0x00001544) + *(int *)(param_1 + 0x1e60)) =
       *(uint *)(((unsigned char *)0x00001544) + *(int *)(param_1 + 0x1e60)) & 0xffc0003f | 0x40;
  *(undefined4 *)(((unsigned char *)0x00001098) + *(int *)(param_1 + 0x1e60)) = 1;
  ((int (*)())FUN_0004aa90)(param_1,((unsigned char *)0x000010ec) + *(int *)(param_1 + 0x1e60));
  *(undefined4 *)(param_1 + 0x1e84) = 0;
  *(undefined4 *)(param_1 + 0x277c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1e64) = 0;
  *(undefined4 *)(param_1 + 0x1e80) = 0;
  if (0 < *(int *)(param_1 + 0x1e74)) {
    iVar1 = 0;
    do {
      iVar2 = iVar1 * 4;
      iVar1 = iVar1 + 1;
      ((unsigned char *)0x000010e9)[*(int *)(iVar2 + *(int *)(param_1 + 0x1e7c))] = 0;
      ((unsigned char *)0x000010ea)[*(int *)(iVar2 + *(int *)(param_1 + 0x1e7c))] = 0;
    } while (iVar1 < *(int *)(param_1 + 0x1e74));
  }
  *(undefined4 *)(param_1 + 0x1e74) = 0;
  if (*(int *)(param_1 + 0x1e5c) == 0) {
    *(undefined4 *)(param_1 + 0x1e5c) = *(undefined4 *)(param_1 + 0x1e60);
  }
  *(undefined4 *)(param_1 + 0x1e84) = 0;
  *(undefined4 *)(param_1 + 0x1e80) = 0;
  iVar2 = 8;
  iVar1 = 0;
  do {
    *(undefined4 *)(param_1 + 0x1e88 + iVar1) = 0;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

/* FUN_0004ac90 @ 0x4ac90 (1272 bytes) */
int FUN_0004ac90(param_1)
  int param_1;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  code *pcVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  int iVar14;
  double fparam_1;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  
  piVar9 = *(int **)(param_1 + 0x1e5c);
  piVar9[0x42e] = piVar9[0x42e] & 0xffff00ff;
  uVar11 = (uint)*(byte *)(param_1 + 0x2b);
  if ((uint)(byte)((unsigned char *)0x000013b2)[param_1] < (uint)*(byte *)(param_1 + 0x2b)) {
    uVar11 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
  }
  bVar1 = false;
  if (uVar11 != 0) {
    uVar10 = 0;
    iVar12 = param_1;
    do {
      iVar3 = *(int *)(((unsigned char *)0x000013f8) + iVar12);
      if (((iVar3 != 0) && (*(short *)(iVar3 + 0x38) == 0x1902)) &&
         (fparam_1 = (double)*(float *)(iVar3 + 0x50), fparam_1 != 0.0)) {
        iVar3 = ((int)uVar10 >> 2) + (uint)((int)uVar10 < 0 && (uVar10 & 3) != 0);
        if (iVar3 == 1) {
          iVar14 = ((uint (*)())FUN_0004a7d0)(fparam_1);
          piVar9[0x68] = iVar14;
        }
        else if (iVar3 < 2) {
          if (iVar3 == 0) {
            iVar14 = ((uint (*)())FUN_0004a7d0)(fparam_1);
            piVar9[99] = iVar14;
          }
        }
        else if (iVar3 == 2) {
          iVar14 = ((uint (*)())FUN_0004a7d0)(fparam_1);
          piVar9[0x6d] = iVar14;
        }
        else if (iVar3 == 3) {
          iVar14 = ((uint (*)())FUN_0004a7d0)(fparam_1);
          piVar9[0x72] = iVar14;
        }
        uVar2 = iVar3 + 0x10U >> 3 & 0x1ffffffc;
        bVar1 = true;
        *(uint *)((int)piVar9 + (int)(((unsigned char *)0x000010b8) + uVar2)) =
             1 << (iVar3 + 0x10U & 0x1f) | *(uint *)((int)piVar9 + (int)(((unsigned char *)0x000010b8) + uVar2));
      }
      uVar10 = uVar10 + 1;
      iVar12 = iVar12 + 4;
    } while (uVar11 != uVar10);
  }
  if (*(char *)(param_1 + 0x121) != '\0') {
    iVar12 = *(int *)(*(int *)(param_1 + 4) + 0x10);
    local_58 = *(undefined4 *)(((unsigned char *)0x00002de0) + iVar12);
    local_54 = *(undefined4 *)(((unsigned char *)0x00002de4) + iVar12);
    local_50 = *(undefined4 *)(((unsigned char *)0x00002de8) + iVar12);
    local_4c = 0;
    local_48 = -1.0 / (*(float *)(((unsigned char *)0x00002df8) + iVar12) - *(float *)(((unsigned char *)0x00002df4) + iVar12));
    local_44 = *(float *)(((unsigned char *)0x00002df8) + iVar12) * *(float *)(((unsigned char *)0x00002dfc) + iVar12);
    local_40 = *(float *)(((unsigned char *)0x00002df0) + iVar12) / 0.6931472;
    local_3c = *(float *)(((unsigned char *)0x00002df0) + iVar12) / 0.83255464;
    (**(code **)(((unsigned char *)0x00001280) + param_1))
              (param_1,0,
               *(undefined4 *)(((unsigned char *)0x00003878) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(param_1 + 0x1e5c)))
               ,*(undefined4 *)
                 (((unsigned char *)0x00003878) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(param_1 + 0x1e5c))),&local_58,1,
               1,*(code **)(((unsigned char *)0x00001280) + param_1));
    (**(code **)(((unsigned char *)0x00001280) + param_1))
              (param_1,0,
               *(undefined4 *)(((unsigned char *)0x0000387c) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(param_1 + 0x1e5c)))
               ,*(undefined4 *)
                 (((unsigned char *)0x0000387c) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(param_1 + 0x1e5c))),&local_48,1,
               1);
  }
  FUN_000b5190(param_1,*(int *)(param_1 + 0x1e5c) + 0x1784,
               ((unsigned char *)0x00001660) + *(int *)(param_1 + 0x1e5c));
  uVar11 = (uint)*(byte *)(param_1 + 0x20);
  if (uVar11 != 0) {
    iVar12 = 0;
    iVar3 = param_1 + 0x28b4;
    do {
      if ((uVar11 & 1) != 0) {
        (**(code **)(((unsigned char *)0x00001280) + param_1))(param_1,0,iVar12 + 0x14,iVar12 + 0x14,iVar3,1,1);
      }
      uVar11 = uVar11 >> 1;
      iVar12 = iVar12 + 1;
      iVar3 = iVar3 + 0x10;
    } while (uVar11 != 0);
  }
  if ((bVar1) && (*(undefined1 *)((int)piVar9 + 0x10eb) = 0, piVar9 == *(int **)(param_1 + 0x1e64)))
  {
    if (*(int *)(param_1 + 0x23e0) == 0) {
      iVar12 = piVar9[0xdac];
      puVar13 = (uint *)(piVar9 + 0x43b);
      piVar5 = piVar9 + 0x423;
      piVar6 = piVar9;
    }
    else {
      iVar12 = piVar9[0xdaf];
      puVar13 = (uint *)(piVar9 + 0x4c6);
      piVar5 = piVar9 + 0x424;
      piVar6 = piVar9 + 7;
    }
    *(int **)(param_1 + 0x1e64) = piVar9;
    if (*piVar6 == 0) {
      iVar3 = piVar6[1];
      *(undefined4 *)(FUN_00002348 + param_1 + 4) = 1;
      *(int *)(param_1 + 0x2350) = iVar3;
      *(int *)(param_1 + 0x2338) = *piVar5;
      *piVar6 = 1;
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x100000;
    }
    if (*(char *)((int)piVar9 + 0x10eb) == '\0') {
      iVar14 = 8;
      iVar3 = param_1;
      piVar6 = piVar9;
      do {
        piVar5 = piVar6 + 0x42e;
        piVar6 = piVar6 + 1;
        *(int *)(iVar3 + 0x1e88) = *piVar5;
        iVar3 = iVar3 + 4;
        iVar14 = iVar14 + -1;
      } while (iVar14 != 0);
      uVar11 = 0;
      pcVar4 = FUN_00001f30 + param_1;
      piVar5 = piVar9 + 0x20;
      piVar6 = piVar9;
      do {
        uVar10 = piVar6[0x42e];
        if (uVar10 != 0) {
          piVar7 = piVar5 + 3;
          pcVar8 = pcVar4 + 8;
          uVar2 = uVar11;
          do {
            if (((uVar10 & 1) != 0) && ((1 << (uVar2 & 0x3f) & piVar9[0x436]) == 0)) {
              *(int *)pcVar8 = *piVar7;
              *(int *)(pcVar8 + 4) = piVar7[1];
              *(int *)(pcVar8 + 8) = piVar7[2];
              *(int *)(pcVar8 + 0xc) = piVar7[3];
            }
            uVar10 = uVar10 >> 1;
            uVar2 = uVar2 + 1;
            piVar7 = piVar7 + 4;
            pcVar8 = pcVar8 + 0x10;
          } while (uVar10 != 0);
        }
        bVar1 = uVar11 != 0xe0;
        piVar6 = piVar6 + 1;
        piVar5 = piVar5 + 0x80;
        pcVar4 = pcVar4 + 0x200;
        uVar11 = uVar11 + 0x20;
      } while (bVar1);
      *(undefined1 *)((int)piVar9 + 0x10eb) = 1;
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x40000000;
    }
    if (puVar13[0x85] == 0) {
      *(uint *)(param_1 + 0x1f2c) = puVar13[0x82];
      uVar11 = *puVar13;
      *(int *)(param_1 + 0x1f34) = iVar12;
      *(uint *)(FUN_00001f30 + param_1) = uVar11 & 0xffffff1f;
      _memcpy(param_1 + 0x1ea8,puVar13 + 1,iVar12 << 2);
      uVar2 = puVar13[0x23];
      uVar10 = puVar13[0x24];
      uVar11 = puVar13[0x25];
      *(uint *)(param_1 + 0x1ee8) = puVar13[0x22];
      *(uint *)(param_1 + 0x1eec) = uVar2;
      *(uint *)(param_1 + 0x1ef0) = uVar10;
      *(uint *)(param_1 + 0x1ef4) = uVar11;
      uVar2 = puVar13[0x26];
      uVar10 = puVar13[0x27];
      uVar11 = puVar13[0x28];
      *(uint *)(param_1 + 0x1f04) = puVar13[0x29];
      *(uint *)(param_1 + 0x1ef8) = uVar2;
      *(uint *)(param_1 + 0x1efc) = uVar10;
      *(uint *)(param_1 + 0x1f00) = uVar11;
      puVar13[0x85] = 1;
      *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x80000000;
    }
  }
  return;
}

/* FUN_0004b190 @ 0x4b190 (700 bytes) */
int FUN_0004b190(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  char cVar4;
  code *pcVar3;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  
  iVar7 = *(int *)(param_1 + 0x276c);
  if (((*(uint *)(param_1 + 0x44) & 0x20000) == 0) || (*(int *)(param_1 + 0x1e70) == 0)) {
LAB_0004b200:
    uVar8 = 1;
    iVar9 = *(int *)(param_1 + 0x1e5c);
    bVar2 = false;
  }
  else {
    if ((*(uint *)(param_1 + 0x44) & 0x2000) == 0) {
      cVar4 = ((unsigned char *)0x00001136)[param_1];
    }
    else {
      cVar4 = ((unsigned char *)0x000011d0)[param_1];
    }
    if (cVar4 != '\0') goto LAB_0004b200;
    uVar8 = 0;
    iVar9 = *(int *)(param_1 + 0x1e70);
    bVar2 = true;
  }
  bVar1 = param_2 == 0;
  if (bVar1) {
    *(undefined4 *)(param_1 + 0x23e0) = 0;
  }
  else {
    *(undefined4 *)(param_1 + 0x23e0) = 1;
  }
  puVar5 = *(undefined1 **)(((unsigned char *)0x000036c0) + iVar9);
  if (puVar5 == (undefined1 *)0x0) {
    return;
  }
  if (param_2 == *(int *)(((unsigned char *)0x000010e4) + iVar9)) {
    if (((unsigned char *)0x000036c4)[iVar9] == '\0') {
      if (!bVar1) {
        cVar4 = '\0';
        goto LAB_0004b2f8;
      }
      cVar4 = ((unsigned char *)0x000010e9)[iVar9];
    }
    else {
      if (bVar1) goto LAB_0004b340;
      cVar4 = ((unsigned char *)0x000010ea)[iVar9];
    }
    if (cVar4 != '\0') {
      return;
    }
    if (bVar2) {
      *puVar5 = (char)uVar8;
      ((unsigned char *)0x000010e9)[iVar9] = 0;
      ((unsigned char *)0x000010ea)[iVar9] = 0;
LAB_0004b42c:
      FUN_00088190(param_1,*(undefined4 *)(((unsigned char *)0x000036c0) + iVar9));
      return;
    }
    iVar7 = *(int *)(param_1 + 0x1e5c);
    ((unsigned char *)0x000010e9)[iVar7] = 0;
    ((unsigned char *)0x000010ea)[iVar7] = 0;
    (**(code **)(param_1 + 0x294c))(param_1,iVar7);
    pcVar3 = *(code **)(((unsigned char *)0x00001330) + param_1);
    uVar8 = *(undefined4 *)(param_1 + 0x1930);
  }
  else {
    if (!bVar1) {
      cVar4 = ((unsigned char *)0x000036c4)[iVar9];
LAB_0004b2f8:
      if (cVar4 == '\0') {
        if (bVar2) {
          FUN_00087e80(param_1,0,puVar5,puVar5 + 4);
        }
        else {
          FUN_000b6580(param_1,1);
        }
        ((unsigned char *)0x000036c4)[iVar9] = 1;
      }
    }
LAB_0004b340:
    *(int *)(((unsigned char *)0x000010e4) + iVar9) = param_2;
    *(int *)(((unsigned char *)0x00001528) + iVar9) = param_2;
    *(int *)(((unsigned char *)0x000012fc) + iVar9) = param_2;
    if (param_2 == 2) {
      iVar7 = iVar7 << 2;
      uVar6 = 4;
    }
    else {
      iVar7 = iVar7 * 4;
      uVar6 = (*(uint *)(((unsigned char *)0x000013e0) + iVar7 + iVar9) >> 6 & 0x3f) + 1 & 0x3f;
    }
    *(uint *)(((unsigned char *)0x000013e0) + iVar7 + iVar9) =
         uVar6 << 0xc | *(uint *)(((unsigned char *)0x000013e0) + iVar7 + iVar9) & 0xff000fff | 0xfc0000;
    if (bVar2) {
      **(undefined1 **)(((unsigned char *)0x000036c0) + iVar9) = (char)uVar8;
      ((unsigned char *)0x000010e9)[iVar9] = 0;
      ((unsigned char *)0x000010ea)[iVar9] = 0;
      *(undefined4 *)(param_1 + 0x1e68) = uVar8;
      goto LAB_0004b42c;
    }
    iVar7 = *(int *)(param_1 + 0x1e5c);
    ((unsigned char *)0x000010e9)[iVar7] = 0;
    ((unsigned char *)0x000010ea)[iVar7] = 0;
    *(undefined4 *)(param_1 + 0x1e68) = 0;
    (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,1);
    (**(code **)(param_1 + 0x294c))(param_1,iVar7);
    pcVar3 = *(code **)(((unsigned char *)0x00001330) + param_1);
    uVar8 = *(undefined4 *)(param_1 + 0x1930);
  }
  (*pcVar3)(param_1,uVar8);
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) & 0x3fefffff;
  return;
}

/* FUN_0004b480 @ 0x4b480 (148 bytes) */
int FUN_0004b480(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  code *a6;
  undefined4 uVar2;
  
  iVar1 = param_2 * 4 + param_1;
  if (*(int *)(((unsigned char *)0x00001448) + iVar1) != 0) {
    uVar2 = *(undefined4 *)(param_1 + 0x1930);
    *(undefined4 *)(param_1 + 0x23e0) = 0;
    **(undefined1 **)(((unsigned char *)0x00001448) + iVar1) = 0;
    (**(code **)(((unsigned char *)0x00001290) + param_1))
              (param_1,*(undefined4 *)(((unsigned char *)0x00001448) + iVar1),in_r5,in_r6,in_r7,in_r8,0);
    a6 = *(code **)(((unsigned char *)0x00001330) + param_1);
    *(uint *)(param_1 + 0x1f2c) = *(uint *)(param_1 + 0x1f2c) & 0xfffff800 | 0x80;
    (*a6)(param_1,0xc0100000,in_r5,in_r6,in_r7,in_r8,a6);
    *(undefined4 *)(param_1 + 0x1930) = uVar2;
  }
  return;
}

/* FUN_0004b520 @ 0x4b520 (160 bytes) */
int FUN_0004b520(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x1e74);
  while( true ) {
    if (iVar3 < 1) {
      return;
    }
    piVar1 = *(int **)(param_1 + 0x1e7c);
    iVar2 = 0;
    if (param_2 != *piVar1) {
      iVar2 = 0;
      iVar4 = iVar3;
      do {
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) {
          return;
        }
      } while (param_2 != piVar1[iVar2]);
    }
    iVar3 = iVar3 + -1;
    *(int *)(param_1 + 0x1e74) = iVar3;
    if (iVar3 == iVar2) break;
    if (iVar2 < iVar3) {
      iVar4 = iVar2 << 2;
      while( true ) {
        iVar2 = iVar2 + 1;
        *(undefined4 *)(iVar4 + (int)piVar1) = *(undefined4 *)((int)piVar1 + iVar4 + 4);
        iVar4 = iVar4 + 4;
        iVar3 = *(int *)(param_1 + 0x1e74);
        if (iVar3 <= iVar2) break;
        piVar1 = *(int **)(param_1 + 0x1e7c);
      }
    }
  }
  return;
}

/* FUN_0004b5d0 @ 0x4b5d0 (296 bytes) */
int FUN_0004b5d0(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  ((int (*)())FUN_0004a990)(param_1,param_2);
  if ((param_1 != 0) && (iVar5 = *(int *)(((unsigned char *)0x000036c0) + param_2), iVar5 != 0)) {
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 0xc));
    *(undefined4 *)(iVar5 + 0xc) = 0;
    iVar5 = *(int *)(((unsigned char *)0x000036c0) + param_2);
    iVar3 = *(int *)(param_1 + 0x1e74);
    while (0 < iVar3) {
      piVar1 = *(int **)(param_1 + 0x1e7c);
      iVar2 = 0;
      if (param_2 != *piVar1) {
        iVar2 = 0;
        iVar4 = iVar3;
        do {
          iVar2 = iVar2 + 1;
          iVar4 = iVar4 + -1;
          if (iVar4 == 0) goto LAB_0004b6a8;
        } while (piVar1[iVar2] != param_2);
      }
      iVar3 = iVar3 + -1;
      *(int *)(param_1 + 0x1e74) = iVar3;
      if (iVar3 == iVar2) break;
      if (iVar2 < iVar3) {
        iVar4 = iVar2 << 2;
        while( true ) {
          iVar2 = iVar2 + 1;
          *(undefined4 *)(iVar4 + (int)piVar1) = *(undefined4 *)((int)piVar1 + iVar4 + 4);
          iVar4 = iVar4 + 4;
          iVar3 = *(int *)(param_1 + 0x1e74);
          if (iVar3 <= iVar2) break;
          piVar1 = *(int **)(param_1 + 0x1e7c);
        }
      }
    }
LAB_0004b6a8:
    (**(code **)(param_1 + 0x18))(*(undefined4 *)(((unsigned char *)0x000036c0) + param_2));
    if (param_2 != iVar5 + 0x124) {
      *(undefined4 *)(((unsigned char *)0x000036c0) + param_2) = 0;
    }
  }
  return;
}

/* FUN_0004b710 @ 0x4b710 (188 bytes) */
int FUN_0004b710(param_1)
  int param_1;
{
  undefined *puVar1;
  int iVar2;
  undefined *puVar3;
  
  if (*(short *)(param_1 + 0x1e6c) != 0) {
    iVar2 = 0;
    puVar3 = (undefined *)0x0;
    do {
      iVar2 = iVar2 + 1;
      puVar1 = puVar3 + *(int *)(param_1 + 0x1e60);
      puVar3 = ((unsigned char *)0x00003754) + (int)puVar3;
      *(undefined4 *)(puVar1 + 0x1780) = 0;
      ((int (*)())FUN_0004b5d0)(param_1,puVar1);
    } while (iVar2 < (int)(uint)*(ushort *)(param_1 + 0x1e6c));
  }
  _free(*(undefined4 *)(param_1 + 0x1e60));
  _memset(*(undefined4 *)(((unsigned char *)0x00001114) + param_1),0xff,
          (uint)*(ushort *)(((unsigned char *)0x00001110) + param_1) << 1);
  *(undefined2 *)(param_1 + 0x1e6c) = 0;
  *(undefined4 *)(param_1 + 0x1e5c) = 0;
  *(undefined4 *)(param_1 + 0x1e80) = 0;
  *(undefined4 *)(param_1 + 0x1e84) = 0;
  *(undefined4 *)(param_1 + 0x1e60) = 0;
  return;
}

/* FUN_0004b7d0 @ 0x4b7d0 (392 bytes) */
int FUN_0004b7d0(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = *(int *)(((unsigned char *)0x0000112c) + param_1);
  ((int (*)())FUN_0004b710)(param_1);
  *(undefined2 *)(param_1 + 0x1e6c) = 1;
  uVar3 = _malloc(((unsigned char *)0x00003754));
  *(undefined4 *)(param_1 + 0x1e60) = uVar3;
  _memset(uVar3,0,((unsigned char *)0x00003754));
  *(undefined4 *)(param_1 + 0x1e5c) = 0;
  ((int (*)())FUN_0004ab60)(param_1);
  *(undefined2 *)(((unsigned char *)0x000015c8) + *(int *)(param_1 + 0x1e60)) = 0xffff;
  FUN_000b5fb0(param_1);
  iVar4 = *(int *)(((unsigned char *)0x00001154) + param_1);
  iVar1 = *(int *)(iVar4 + 0x88);
  if (iVar1 != 0) {
    uVar5 = *(uint *)(iVar4 + 4);
    iVar7 = 0;
    if (uVar5 != 0) {
      do {
        iVar1 = *(int *)(*(int *)(((unsigned char *)0x0000113c) + param_1) * 4 +
                        *(int *)(iVar7 * 0x78 + iVar1 + 0x70));
        if (iVar1 != 0) {
          *(undefined1 *)(iVar1 + 0x119) = 1;
          uVar5 = *(uint *)(iVar4 + 4);
        }
        iVar2 = uVar5 - iVar7;
        if ((uVar5 < iVar7 + 1U) || (uVar5 == 0)) {
          iVar2 = 1;
        }
        do {
          iVar7 = iVar7 + 1;
          iVar2 = iVar2 + -1;
          if (iVar2 == 0) goto LAB_0004b8b8;
          iVar1 = *(int *)(iVar4 + 0x88);
        } while (iVar1 == 0);
      } while( true );
    }
  }
LAB_0004b8b8:
  uVar5 = *(uint *)(iVar8 + 4);
  if (uVar5 != 0) {
    uVar6 = 0;
    iVar1 = 0;
    do {
      iVar4 = iVar1 + *(int *)(iVar8 + 8);
      if (((*(int *)(iVar4 + 4) == 0x8804) &&
          (iVar4 = *(int *)(*(int *)(iVar4 + 0x14) + 0x70), iVar4 != 0)) &&
         (iVar4 = *(int *)(*(int *)(((unsigned char *)0x00001130) + param_1) * 4 + iVar4), iVar4 != 0)) {
        *(undefined1 *)(iVar4 + 0x119) = 1;
        uVar5 = *(uint *)(iVar8 + 4);
      }
      uVar6 = uVar6 + 1;
      iVar1 = iVar1 + 0x18;
    } while (uVar6 < uVar5);
  }
  return;
}

/* FUN_0004b980 @ 0x4b980 (616 bytes) */
int FUN_0004b980(param_1, param_2)
  int param_1;
  int param_2;
{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  uint *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  
  uVar13 = (uint)*(ushort *)(((unsigned char *)0x00001110) + param_1);
  iVar15 = *(int *)(param_1 + 0x1e60);
  if (uVar13 != 0x2811) {
    *(short *)(((unsigned char *)0x00001110) + param_1) = (short)(uVar13 + param_2);
    if (0x2811 < (uVar13 + param_2 & 0xffff)) {
      *(undefined2 *)(((unsigned char *)0x00001110) + param_1) = 0x2811;
    }
    iVar5 = (**(code **)(param_1 + 0xc))((uint)*(ushort *)(((unsigned char *)0x00001110) + param_1) << 1);
    _memset(iVar5,0xff,(uint)*(ushort *)(((unsigned char *)0x00001110) + param_1) << 1);
    if (uVar13 == 0) {
      iVar6 = *(int *)(((unsigned char *)0x00001114) + param_1);
    }
    else {
      iVar6 = *(int *)(((unsigned char *)0x00001114) + param_1);
      uVar14 = 0;
      do {
        uVar12 = (uint)*(ushort *)(uVar14 * 2 + iVar6);
        if (uVar12 != 0xffff) {
          do {
            iVar6 = iVar15 + uVar12 * 0x3754;
            puVar7 = (uint *)(((unsigned char *)0x000015c8) + iVar6);
            puVar9 = (uint *)(((unsigned char *)0x00001544) + iVar6);
            if (puVar7 < ((unsigned char *)0x00001570) + iVar6) {
              uVar8 = 0;
            }
            else {
              uVar8 = 0;
              puVar11 = (uint *)(((unsigned char *)0x00001570) + iVar6);
              puVar10 = puVar9;
              do {
                puVar9 = puVar11;
                uVar8 = uVar8 ^ *puVar10 ^ (puVar10[1] << 3 | puVar10[1] >> 0x1d) ^
                        (puVar10[2] << 6 | puVar10[2] >> 0x1a) ^
                        (puVar10[3] << 9 | puVar10[3] >> 0x17) ^
                        (puVar10[4] << 0xc | puVar10[4] >> 0x14) ^
                        (puVar10[5] << 0xf | puVar10[5] >> 0x11) ^
                        (puVar10[6] << 0x12 | puVar10[6] >> 0xe) ^
                        (puVar10[7] << 0x15 | puVar10[7] >> 0xb) ^
                        (puVar10[8] << 0x18 | puVar10[8] >> 8) ^
                        (puVar10[9] << 0x1b | puVar10[9] >> 5) ^
                        (puVar10[10] << 0x1e | puVar10[10] >> 2);
                puVar11 = puVar9 + 0xb;
                puVar10 = puVar9;
              } while (puVar9 + 0xb <= puVar7);
            }
            puVar11 = puVar9 + 5;
            if (puVar7 < puVar11) {
              uVar4 = 0;
              puVar11 = puVar9;
            }
            else {
              uVar4 = 0xf;
              uVar8 = uVar8 ^ *puVar9 ^ (puVar9[1] << 3 | puVar9[1] >> 0x1d) ^
                      (puVar9[2] << 6 | puVar9[2] >> 0x1a) ^ (puVar9[3] << 9 | puVar9[3] >> 0x17) ^
                      (puVar9[4] << 0xc | puVar9[4] >> 0x14);
            }
            for (; puVar11 < puVar7; puVar11 = puVar11 + 1) {
              uVar3 = uVar4 & 0x1f;
              uVar4 = uVar4 + 3;
              uVar8 = uVar8 ^ (*puVar11 << uVar3 | *puVar11 >> 0x20 - uVar3);
            }
            uVar1 = *(ushort *)(((unsigned char *)0x000015c8) + iVar6);
            iVar2 = (uVar8 - (uVar8 / *(ushort *)(((unsigned char *)0x00001110) + param_1)) *
                             (uint)*(ushort *)(((unsigned char *)0x00001110) + param_1)) * 2;
            *(undefined2 *)(((unsigned char *)0x000015c8) + iVar6) = *(undefined2 *)(iVar5 + iVar2);
            *(short *)(iVar5 + iVar2) = (short)uVar12;
            uVar12 = (uint)uVar1;
          } while (uVar1 != 0xffff);
          iVar6 = *(int *)(((unsigned char *)0x00001114) + param_1);
        }
        uVar14 = uVar14 + 1;
      } while (uVar14 < uVar13);
    }
    (**(code **)(param_1 + 0x18))(iVar6);
    *(int *)(((unsigned char *)0x00001114) + param_1) = iVar5;
  }
  return;
}

/* FUN_0004bbf0 @ 0x4bbf0 (1244 bytes) */
int FUN_0004bbf0(param_1)
  int param_1;
{
  uint *puVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  ushort uVar7;
  uint *puVar8;
  undefined4 uVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  uint *puVar14;
  int iVar15;
  undefined *puVar16;
  uint uVar17;
  
  uVar17 = 0x11;
  puVar8 = (uint *)(param_1 + 0x18a4);
  if (*(byte *)(param_1 + 0x2b) < 9) {
    uVar17 = (uint)*(byte *)(param_1 + 0x2b) * 2 + 1;
  }
  cVar2 = ((unsigned char *)0x00001112)[param_1];
  if (cVar2 == '\0') {
    puVar11 = (uint *)(param_1 + 0x18e8);
    uVar7 = *(ushort *)(((unsigned char *)0x00001110) + param_1);
    if (puVar11 < (uint *)(param_1 + 0x18d0)) {
      uVar5 = 0;
      puVar12 = puVar8;
    }
    else {
      uVar5 = 0;
      puVar14 = (uint *)(param_1 + 0x18d0);
      puVar13 = puVar8;
      do {
        puVar12 = puVar14;
        uVar5 = uVar5 ^ *puVar13 ^ (puVar13[1] << 3 | puVar13[1] >> 0x1d) ^
                (puVar13[2] << 6 | puVar13[2] >> 0x1a) ^ (puVar13[3] << 9 | puVar13[3] >> 0x17) ^
                (puVar13[4] << 0xc | puVar13[4] >> 0x14) ^ (puVar13[5] << 0xf | puVar13[5] >> 0x11)
                ^ (puVar13[6] << 0x12 | puVar13[6] >> 0xe) ^
                (puVar13[7] << 0x15 | puVar13[7] >> 0xb) ^ (puVar13[8] << 0x18 | puVar13[8] >> 8) ^
                (puVar13[9] << 0x1b | puVar13[9] >> 5) ^ (puVar13[10] << 0x1e | puVar13[10] >> 2);
        puVar14 = puVar12 + 0xb;
        puVar13 = puVar12;
      } while (puVar12 + 0xb <= puVar11);
    }
    puVar14 = puVar12 + 5;
    if (puVar11 < puVar14) {
      uVar10 = 0;
      puVar14 = puVar12;
    }
    else {
      uVar10 = 0xf;
      uVar5 = uVar5 ^ *puVar12 ^ (puVar12[1] << 3 | puVar12[1] >> 0x1d) ^
              (puVar12[2] << 6 | puVar12[2] >> 0x1a) ^ (puVar12[3] << 9 | puVar12[3] >> 0x17) ^
              (puVar12[4] << 0xc | puVar12[4] >> 0x14);
    }
    for (; puVar14 < puVar11; puVar14 = puVar14 + 1) {
      uVar3 = uVar10 & 0x1f;
      uVar10 = uVar10 + 3;
      uVar5 = uVar5 ^ (*puVar14 << uVar3 | *puVar14 >> 0x20 - uVar3);
    }
    uVar5 = uVar5 - (uVar5 / uVar7) * (uint)uVar7;
  }
  else {
    uVar7 = *(ushort *)(((unsigned char *)0x00001110) + param_1);
    uVar5 = *(int *)(param_1 + 0x18a8) + *(int *)(param_1 + 0x18b0) + *(int *)(param_1 + 0x18b8) +
            *(int *)(param_1 + 0x18c0);
    uVar5 = uVar5 - (uVar5 / uVar7) * (uint)uVar7;
  }
  iVar6 = *(int *)(((unsigned char *)0x00001114) + param_1);
  iVar4 = (uVar5 & 0xffff) * 2;
  *(undefined4 *)(param_1 + 0x277c) = 0xffffffff;
  uVar5 = (uint)*(ushort *)(iVar6 + iVar4);
  if (uVar5 == 0xffff) {
    iVar6 = 0;
  }
  else {
    iVar6 = 0;
    uVar10 = uVar5;
    do {
      uVar5 = uVar10;
      iVar6 = iVar6 + 1;
      iVar15 = *(int *)(param_1 + 0x1e60) + uVar5 * 0x3754;
      puVar16 = ((unsigned char *)0x00001544) + iVar15;
      if ((*puVar8 == *(uint *)(((unsigned char *)0x00001544) + iVar15) &&
          *(int *)(param_1 + 0x18a8) == *(int *)(((unsigned char *)0x00001548) + iVar15)) &&
          *(int *)(param_1 + 0x18ac) == *(int *)(((unsigned char *)0x0000154c) + iVar15)) {
        if (uVar17 < 4) {
LAB_0004bee0:
          *(int *)(param_1 + 0x1e5c) = iVar15;
          return 1;
        }
        if (*(int *)(((unsigned char *)0x00001550) + iVar15) == *(int *)(param_1 + 0x18b0) &&
            *(int *)(((unsigned char *)0x00001554) + iVar15) == *(int *)(param_1 + 0x18b4)) {
          uVar10 = 3;
          puVar11 = puVar8;
          do {
            uVar10 = uVar10 + 2;
            if (uVar17 <= uVar10) goto LAB_0004bee0;
            puVar12 = (uint *)(puVar16 + 0x18);
            puVar14 = puVar11 + 6;
            puVar13 = (uint *)(puVar16 + 0x14);
            puVar1 = puVar11 + 5;
            puVar16 = puVar16 + 8;
            puVar11 = puVar11 + 2;
          } while (*puVar13 == *puVar1 && *puVar14 == *puVar12);
        }
      }
      uVar10 = (uint)*(ushort *)(((unsigned char *)0x000015c8) + iVar15);
    } while (*(ushort *)(((unsigned char *)0x000015c8) + iVar15) != 0xffff);
  }
  if ((cVar2 == '\0') || (iVar6 < 7)) {
    if ((iVar6 < 8) || (0x2810 < uVar7)) {
      uVar7 = *(ushort *)(param_1 + 0x1e6c);
      if (0x400 < uVar7) {
        uVar5 = 0;
        ((int (*)())FUN_0004b710)(param_1);
        *(undefined2 *)(param_1 + 0x1e6c) = 1;
        uVar9 = _malloc(((unsigned char *)0x00003754));
        *(undefined4 *)(param_1 + 0x1e60) = uVar9;
        _memset(uVar9,0,((unsigned char *)0x00003754));
        ((int (*)())FUN_0004ab60)(param_1);
        *(undefined2 *)(((unsigned char *)0x000015c8) + *(int *)(param_1 + 0x1e60)) = 0xffff;
        uVar7 = *(ushort *)(param_1 + 0x1e6c);
      }
      *(ushort *)(param_1 + 0x1e6c) = uVar7 + 1;
      if (*(int *)(param_1 + 0x1e68) != 0) {
        ((unsigned char *)0x000010e9)[*(int *)(param_1 + 0x1e68)] = 0;
        ((unsigned char *)0x000010ea)[*(int *)(param_1 + 0x1e68)] = 0;
        ((unsigned char *)0x000010eb)[*(int *)(param_1 + 0x1e68)] = 0;
        *(undefined4 *)(param_1 + 0x1e68) = 0;
      }
      if (0 < *(int *)(param_1 + 0x1e74)) {
        iVar6 = 0;
        do {
          iVar15 = iVar6 * 4;
          iVar6 = iVar6 + 1;
          ((unsigned char *)0x000010e9)[*(int *)(*(int *)(param_1 + 0x1e7c) + iVar15)] = 0;
          ((unsigned char *)0x000010ea)[*(int *)(*(int *)(param_1 + 0x1e7c) + iVar15)] = 0;
        } while (iVar6 < *(int *)(param_1 + 0x1e74));
      }
      *(undefined4 *)(param_1 + 0x1e74) = 0;
      iVar6 = _realloc(*(undefined4 *)(param_1 + 0x1e60),
                       (uint)*(ushort *)(param_1 + 0x1e6c) * 0x3754);
      *(int *)(param_1 + 0x1e60) = iVar6;
      if (iVar6 == 0) {
        return 0;
      }
      uVar7 = *(ushort *)(param_1 + 0x1e6c);
      iVar15 = *(int *)(((unsigned char *)0x00001114) + param_1);
      *(uint *)(param_1 + 0x1e5c) = iVar6 + (uint)uVar7 * 0x3754 + -0x3754;
      if (*(short *)(iVar4 + iVar15) == -1) {
        *(ushort *)(iVar4 + iVar15) = uVar7 - 1;
      }
      else {
        *(ushort *)(((unsigned char *)0x000015c8) + uVar5 * 0x3754 + iVar6) = uVar7 - 1;
      }
      _memset(*(undefined4 *)(param_1 + 0x1e5c),0,((unsigned char *)0x00003754));
      *(undefined2 *)(((unsigned char *)0x000015c8) + *(int *)(param_1 + 0x1e5c)) = 0xffff;
      _memcpy(((unsigned char *)0x00001544) + *(int *)(param_1 + 0x1e5c),param_1 + 0x18a4,0x84);
      return 0;
    }
    if (cVar2 == '\0') {
      ((int (*)())FUN_0004b980)(param_1,0x313);
      goto LAB_0004bf48;
    }
  }
  ((int (*)())FUN_0004b980)(param_1,0);
  ((unsigned char *)0x00001112)[param_1] = 0;
LAB_0004bf48:
  uVar9 = ((int (*)())FUN_0004bbf0)(param_1);
  return uVar9;
}

/* FUN_0004c100 @ 0x4c100 (336 bytes) */
int FUN_0004c100(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  iVar2 = *(int *)(param_2 + 0x1e64);
  if (iVar2 != 0) {
    if (*(int *)(param_2 + 0x23e0) == 0) {
      uVar4 = *(uint *)(((unsigned char *)0x000036a8) + iVar2);
      puVar5 = (undefined4 *)(iVar2 + 4);
      puVar1 = ((unsigned char *)0x000010ec);
    }
    else {
      uVar4 = *(uint *)(((unsigned char *)0x000036b4) + iVar2);
      puVar5 = (undefined4 *)(iVar2 + 0x20);
      puVar1 = ((unsigned char *)0x00001318);
    }
    *(undefined4 *)(param_1 + 0x250) = *(undefined4 *)(puVar1 + iVar2 + 0x44);
    *(undefined4 *)(param_1 + 600) = *(undefined4 *)(puVar1 + iVar2 + 0x48);
    uVar3 = puVar5[2];
    *(undefined4 *)(param_1 + 0x218) = 0;
    *(undefined4 *)(param_1 + 0x220) = uVar3;
    *(undefined4 *)(param_1 + 0x210) = puVar5[3];
    *(undefined4 *)(param_1 + 0x208) = *puVar5;
    *(undefined4 *)(param_1 + 0x200) = puVar5[1];
    if (uVar4 != 0) {
      *(undefined4 *)(param_1 + 0x108) = *(undefined4 *)puVar5[4];
      *(undefined4 *)(param_1 + 0x110) = *(undefined4 *)(puVar5[4] + 4);
      *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(puVar5[4] + 8);
      *(undefined4 *)(param_1 + 0x120) = *(undefined4 *)(puVar5[4] + 0xc);
      *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(puVar5[4] + 0x10);
      *(undefined4 *)(param_1 + 0x130) = *(undefined4 *)(puVar5[4] + 0x14);
      if (1 < uVar4) {
        *(undefined4 *)(param_1 + 0x138) = *(undefined4 *)(puVar5[4] + 0x18);
        *(undefined4 *)(param_1 + 0x140) = *(undefined4 *)(puVar5[4] + 0x1c);
        *(undefined4 *)(param_1 + 0x148) = *(undefined4 *)(puVar5[4] + 0x20);
        *(undefined4 *)(param_1 + 0x150) = *(undefined4 *)(puVar5[4] + 0x24);
        *(undefined4 *)(param_1 + 0x158) = *(undefined4 *)(puVar5[4] + 0x28);
        *(undefined4 *)(param_1 + 0x160) = *(undefined4 *)(puVar5[4] + 0x2c);
        return;
      }
      goto LAB_0004c1ac;
    }
  }
  *(undefined4 *)(param_1 + 0x1fc) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x104) = 0xc00a1000;
  *(undefined4 *)(param_1 + 0x24c) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x254) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x21c) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x214) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x20c) = 0xc0001000;
  *(undefined4 *)(param_1 + 0x204) = 0xc0001000;
LAB_0004c1ac:
  *(undefined4 *)(param_1 + 0x134) = 0xc00a1000;
  return;
}

