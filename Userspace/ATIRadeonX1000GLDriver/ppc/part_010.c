#include "decls.h"

/* FUN_0009d2e0 @ 0x9d2e0 (184 bytes) */
int FUN_0009d2e0(param_1)
  int param_1;
{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  
  if (*(char *)(param_1 + 0x3d4) != '\0') {
    return;
  }
  if (*(char *)(param_1 + 0x124) == '\0') {
    if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
      return;
    }
    iVar1 = *(int *)(param_1 + 0x14c);
    if (iVar1 == 0) {
      return;
    }
    (**(code **)(((unsigned char *)0x000012d0) + param_1))(param_1,iVar1);
    UNRECOVERED_JUMPTABLE = *(code **)(((unsigned char *)0x000012c4) + param_1);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x14c);
    if (iVar1 == 0) {
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(((unsigned char *)0x000012d0) + param_1);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,iVar1);
  return;
}

/* FUN_0009d3b0 @ 0x9d3b0 (64 bytes) */
int FUN_0009d3b0(param_1)
  int param_1;
{
  if (param_1 == 0) {
    return;
  }
  *(undefined1 *)(param_1 + 0x3d4) = 0;
  if ((*(uint *)(param_1 + 0x44) & 0x100000) != 0) {
    if (*(char *)(param_1 + 0x1868) != '\0') {
                    
                    
      (**(code **)((int)((unsigned char *)0x000011cc) + param_1))();
      return;
    }
    FUN_00064f40();
    return;
  }
  ((int (*)())FUN_0009d2e0)();
  return;
}

/* FUN_0009d410 @ 0x9d410 (5944 bytes) */
int FUN_0009d410(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int *param_4;
  int *param_5;
{
  undefined1 uVar1;
  byte bVar2;
  short sVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  void *pvVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  int *piVar11;
  float fVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int unaff_r17;
  int unaff_r18;
  float unaff_r19;
  undefined4 uVar18;
  int iVar19;
  int iVar20;
  int *piVar21;
  uint *puVar22;
  int iVar23;
  ushort *puVar24;
  int iVar25;
  float local_78;
  uint local_74 [4];
  float local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  float local_50;
  int local_4c;
  int local_48;
  
  iVar19 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  if ((*(uint *)(param_1 + 0x1874) & 0xc0000000) != 0x40000000) {
    uVar6 = *(uint *)(param_1 + 0x44);
    goto LAB_0009d494;
  }
  if ((*(uint *)(param_1 + 0x8c) & 0x800000) != 0) {
    uVar6 = *(uint *)(param_1 + 0x44);
    goto LAB_0009d4b8;
  }
  uVar6 = *(uint *)(param_1 + 0x44);
  if ((uVar6 & 0x20000) == 0) {
LAB_0009d494:
    uVar10 = 0;
  }
  else {
    if ((uVar6 & 0x2000) == 0) {
      if (((unsigned char *)0x00001135)[param_1] != '\0') goto LAB_0009d4b8;
      goto LAB_0009d494;
    }
    if (((unsigned char *)0x000011d3)[param_1] == '\0') goto LAB_0009d494;
LAB_0009d4b8:
    uVar10 = 1;
    if ((*(uint *)(((unsigned char *)0x000013c0) + param_1) & 1) == 0) goto LAB_0009d494;
  }
  if (((uVar6 & 0x400) == 0) || (uVar18 = 1, (*(uint *)(((unsigned char *)0x000013c0) + param_1) & 2) == 0)) {
    uVar18 = 0;
  }
  uVar1 = ((unsigned char *)0x000011d2)[param_1];
  pvVar7 = (void *)FUN_00092bf0(param_1,param_2,uVar10);
  (**(code **)(((unsigned char *)0x000012c0) + param_1))(param_1,pvVar7,&local_78,param_3);
  if (*(int *)(param_1 + 0x13c) == 1) {
    _memcpy(pvVar7,(void *)(param_1 + 0x19c),0x68);
  }
  else {
    _memcpy(pvVar7,(void *)(param_1 + 0x204),0x68);
  }
  piVar21 = (int *)((int)pvVar7 + 0xa4);
  iVar20 = *(int *)(*(int *)(param_1 + 4) + 0x10);
  _memset(piVar21,-1,0x324);
  param_5[2] = 0;
  if (((unsigned char *)0x00004301)[iVar20] == '\0') {
    local_78 = (float)(iVar20 + 0x2460);
    iVar8 = 0;
    if ((((((local_74[0] != 0 || local_74[1] != 0) || local_74[2] != 0) ||
          FLOAT_001aa0e8 != local_78) ||
         (((local_74[3] != 0 || local_60 != 0) || local_5c != 0) || FLOAT_001aa0e8 != local_64)) ||
        (((local_58 != 0 || local_54 != 0) || local_4c != 0) || FLOAT_001aa0e8 != local_50)) ||
        (((local_48 != 0 || unaff_r17 != 0) || unaff_r18 != 0) || FLOAT_001aa0e8 != unaff_r19)) {
      *(undefined4 *)((int)pvVar7 + 0xa4) = 0;
      iVar8 = 4;
      *(undefined4 *)(param_5[2] * 4 + *param_5) = 0;
      *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
      param_5[2] = param_5[2] + 1;
    }
    uVar6 = *(uint *)(param_1 + 0x8c);
    if ((uVar6 & 0x80000) != 0) {
      *(int *)((int)pvVar7 + 0xb4) = iVar8;
      iVar16 = iVar8 + 4;
      iVar8 = iVar8 + 8;
      *(undefined4 *)(param_5[2] * 4 + *param_5) = 1;
      *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
      param_5[2] = param_5[2] + 1;
      *(int *)((int)pvVar7 + 0xc4) = iVar16;
      *(undefined4 *)(param_5[2] * 4 + *param_5) = 2;
      *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
      param_5[2] = param_5[2] + 1;
      uVar6 = *(uint *)(param_1 + 0x8c);
    }
  }
  else {
    bVar2 = ((unsigned char *)0x00004300)[iVar20];
    iVar8 = 0;
    iVar16 = 4;
    uVar6 = 0;
    fVar12 = (float)(iVar20 + 0x1960);
    piVar11 = piVar21;
    do {
      if (((1 << (bVar2 & 0x3f)) - 1U & 1 << (uVar6 & 0x3f)) != 0) {
        if ((((((local_74[0] != 0 || local_74[1] != 0) || local_74[2] != 0) ||
              FLOAT_001aa0e8 != fVar12) ||
             (((local_74[3] != 0 || local_60 != 0) || local_5c != 0) || FLOAT_001aa0e8 != local_64))
            || (((local_58 != 0 || local_54 != 0) || local_4c != 0) || FLOAT_001aa0e8 != local_50))
            || (((local_48 != 0 || unaff_r17 != 0) || unaff_r18 != 0) || FLOAT_001aa0e8 != unaff_r19
               )) {
          *piVar11 = iVar8;
          iVar8 = iVar8 + 4;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0;
          *(uint *)(param_5[2] * 4 + param_5[1]) = uVar6;
          param_5[2] = param_5[2] + 1;
        }
        local_78 = fVar12;
        if ((*(uint *)(param_1 + 0x8c) & 0x80000) != 0) {
          piVar11[4] = iVar8;
          iVar15 = iVar8 + 4;
          iVar8 = iVar8 + 8;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 1;
          *(uint *)(param_5[2] * 4 + param_5[1]) = uVar6;
          param_5[2] = param_5[2] + 1;
          piVar11[8] = iVar15;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 2;
          *(uint *)(param_5[2] * 4 + param_5[1]) = uVar6;
          param_5[2] = param_5[2] + 1;
        }
      }
      uVar6 = uVar6 + 1;
      fVar12 = (float)((int)fVar12 + 0x40);
      piVar11 = piVar11 + 1;
      iVar16 = iVar16 + -1;
    } while (iVar16 != 0);
    *(int *)((int)pvVar7 + 0xd4) = iVar8;
    iVar8 = iVar8 + 4;
    *(undefined4 *)(param_5[2] * 4 + *param_5) = 3;
    *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
    param_5[2] = param_5[2] + 1;
    uVar6 = *(uint *)(param_1 + 0x8c);
  }
  if ((uVar6 & 0x800000) != 0) {
    uVar6 = 0xff;
    if ((*(uint *)(param_1 + 0x44) & 0x20000) != 0) {
      if ((*(uint *)(param_1 + 0x44) & 0x2000) == 0) {
        uVar6 = (uint)(byte)((unsigned char *)0x00001135)[param_1];
      }
      else {
        uVar6 = (uint)(byte)((unsigned char *)0x000011d3)[param_1];
      }
    }
    iVar25 = 8;
    uVar9 = 0;
    iVar23 = 0;
    iVar15 = param_1 + 0x450;
    piVar11 = piVar21;
    piVar13 = piVar21;
    iVar16 = param_1;
    do {
      if ((uVar6 & 1 << (uVar9 & 0x3f)) != 0) {
        uVar5 = *(uint *)(iVar16 + 0x48);
        if (((uVar5 & 0x20) != 0) && ((ushort)(*(short *)(iVar15 + 0x3c) + 0xdc00U) < 2)) {
          piVar11[0xa9] = iVar8;
          iVar8 = iVar8 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x1a;
          *(int *)(param_5[2] * 4 + param_5[1]) = iVar23;
          param_5[2] = param_5[2] + 1;
        }
        if (((uVar5 & 0x40) != 0) && ((ushort)(*(short *)(iVar15 + 0x60) + 0xdc00U) < 2)) {
          piVar11[0xaa] = iVar8;
          iVar8 = iVar8 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x1a;
          *(int *)(param_5[2] * 4 + param_5[1]) = iVar23 + 1;
          param_5[2] = param_5[2] + 1;
        }
        if (((uVar5 & 0x80) != 0) && ((ushort)(*(short *)(iVar15 + 0x84) + 0xdc00U) < 2)) {
          piVar11[0xab] = iVar8;
          iVar8 = iVar8 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x1a;
          *(int *)(param_5[2] * 4 + param_5[1]) = iVar23 + 2;
          param_5[2] = param_5[2] + 1;
        }
        if (((uVar5 & 0x100) != 0) && ((ushort)(*(short *)(iVar15 + 0xa8) + 0xdc00U) < 2)) {
          piVar11[0xac] = iVar8;
          iVar8 = iVar8 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x1a;
          *(int *)(param_5[2] * 4 + param_5[1]) = iVar23 + 3;
          param_5[2] = param_5[2] + 1;
        }
        if (*(int *)(iVar16 + 0x150) != 0) {
          piVar13[0xd] = iVar8;
          iVar8 = iVar8 + 4;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 4;
          *(uint *)(param_5[2] * 4 + param_5[1]) = uVar9;
          param_5[2] = param_5[2] + 1;
        }
      }
      uVar9 = uVar9 + 1;
      iVar15 = iVar15 + 0xcc;
      iVar23 = iVar23 + 4;
      piVar13 = piVar13 + 1;
      iVar16 = iVar16 + 4;
      piVar11 = piVar11 + 4;
      iVar25 = iVar25 + -1;
    } while (iVar25 != 0);
  }
  fVar12 = FLOAT_001aa0d4;
  uVar6 = *(uint *)(param_1 + 0x44);
  if ((int)uVar6 < 0) {
    uVar6 = *(uint *)(param_1 + 0x88);
    if (uVar6 == 0) {
      bVar4 = false;
      iVar16 = iVar8;
    }
    else {
      iVar25 = 0;
      bVar4 = false;
      iVar15 = iVar20;
      iVar23 = param_1;
      do {
        puVar22 = (uint *)(iVar25 * 4 + param_1 + 0x3a8);
        iVar16 = iVar8;
        if (((uVar6 & 1) != 0) &&
           (uVar9 = *(uint *)(param_1 + 0x3a8 + iVar25 * 4), (uVar9 & 0xfc000000) != 0)) {
          uVar9 = uVar9 & 0xc0000000;
          if (uVar9 == 0x80000000) {
            piVar21[0x16] = iVar8;
            iVar8 = iVar8 + 1;
            *(undefined4 *)(param_5[2] * 4 + *param_5) = 5;
            *(int *)(param_5[2] * 4 + param_5[1]) = iVar25;
            param_5[2] = param_5[2] + 1;
          }
          else if (uVar9 == 0xc0000000) {
            bVar4 = true;
          }
          uVar9 = *puVar22;
          if ((uVar9 & 0x30000000) == 0x20000000) {
            if (*(int *)(param_1 + 0x13c) == 1) {
              if (7 < *(uint *)(param_1 + 0x280)) {
                piVar21[0x18] = iVar8;
                iVar8 = iVar8 + 1;
                *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x1c;
                *(int *)(param_5[2] * 4 + param_5[1]) = iVar25 << 1;
                param_5[2] = param_5[2] + 1;
              }
              if (("}J3x})+x|B;x}k"[iVar20 + 4] != '\0') && (7 < *(uint *)(param_1 + 0x284))) {
                piVar21[0x19] = iVar8;
                iVar8 = iVar8 + 1;
                *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x1c;
                *(uint *)(param_5[2] * 4 + param_5[1]) = iVar25 << 1 | 1;
                param_5[2] = param_5[2] + 1;
              }
            }
            if ((piVar21[0x18] == -1) ||
               (("}J3x})+x|B;x}k"[iVar20 + 4] != '\0' && (piVar21[0x19] == -1)))) {
              piVar21[0x17] = iVar8;
              iVar8 = iVar8 + 1;
              *(undefined4 *)(param_5[2] * 4 + *param_5) = 6;
              *(int *)(param_5[2] * 4 + param_5[1]) = iVar25;
              param_5[2] = param_5[2] + 1;
              uVar9 = *puVar22;
            }
            else {
              uVar9 = *puVar22;
            }
          }
          if ((uVar9 & 0xc000000) == 0x8000000) {
            if (*(int *)(param_1 + 0x13c) == 1) {
              if (7 < *(uint *)(param_1 + 0x288)) {
                piVar21[0x1b] = iVar8;
                iVar8 = iVar8 + 1;
                *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x1d;
                *(int *)(param_5[2] * 4 + param_5[1]) = iVar25 << 1;
                param_5[2] = param_5[2] + 1;
              }
              if (("}J3x})+x|B;x}k"[iVar20 + 4] != '\0') && (7 < *(uint *)(param_1 + 0x28c))) {
                piVar21[0x1c] = iVar8;
                iVar8 = iVar8 + 1;
                *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x1d;
                *(uint *)(param_5[2] * 4 + param_5[1]) = iVar25 << 1 | 1;
                param_5[2] = param_5[2] + 1;
              }
            }
            if ((piVar21[0x1b] == -1) ||
               (("}J3x})+x|B;x}k"[iVar20 + 4] != '\0' && (piVar21[0x1c] == -1)))) {
              piVar21[0x1a] = iVar8;
              iVar8 = iVar8 + 1;
              *(undefined4 *)(param_5[2] * 4 + *param_5) = 7;
              *(int *)(param_5[2] * 4 + param_5[1]) = iVar25;
              param_5[2] = param_5[2] + 1;
            }
          }
          piVar21[0x1e] = iVar8;
          iVar14 = iVar8 + 2;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 8;
          *(int *)(param_5[2] * 4 + param_5[1]) = iVar25;
          param_5[2] = param_5[2] + 1;
          piVar21[0x1f] = iVar8 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 9;
          *(int *)(param_5[2] * 4 + param_5[1]) = iVar25;
          param_5[2] = param_5[2] + 1;
          iVar16 = iVar14;
          if (*(float *)(iVar15 + 0x24fc) != fVar12) {
            if ((*puVar22 & 0x2000000) != 0) {
              if ((*puVar22 & 0x1000000) == 0) {
                piVar21[0x20] = iVar14;
                uVar10 = 10;
                iVar16 = param_5[2];
                iVar17 = *param_5;
              }
              else {
                piVar21[0x22] = iVar14;
                uVar10 = 0xc;
                iVar16 = param_5[2];
                iVar17 = *param_5;
              }
              iVar14 = iVar8 + 3;
              *(undefined4 *)(iVar16 * 4 + iVar17) = uVar10;
              *(int *)(param_5[2] * 4 + param_5[1]) = iVar25;
              param_5[2] = param_5[2] + 1;
            }
            iVar16 = iVar14;
            if (((unsigned char *)0x0000150c)[iVar23] != '\0') {
              piVar21[0x21] = iVar14;
              iVar16 = iVar14 + 1;
              *(undefined4 *)(param_5[2] * 4 + *param_5) = 0xb;
              *(int *)(param_5[2] * 4 + param_5[1]) = iVar25;
              param_5[2] = param_5[2] + 1;
              if (*(float *)(iVar15 + 0x251c) != fVar12) {
                piVar21[0x23] = iVar16;
                iVar16 = iVar14 + 2;
                *(undefined4 *)(param_5[2] * 4 + *param_5) = 0xd;
                *(int *)(param_5[2] * 4 + param_5[1]) = iVar25;
                param_5[2] = param_5[2] + 1;
              }
            }
          }
        }
        uVar6 = uVar6 >> 1;
        iVar25 = iVar25 + 1;
        piVar21 = piVar21 + 0xf;
        iVar15 = iVar15 + 0x80;
        iVar23 = iVar23 + 0x6c;
        iVar8 = iVar16;
      } while (uVar6 != 0);
    }
    if (*(int *)(param_1 + 0x13c) == 1) {
      if (7 < *(uint *)(param_1 + 0x270)) {
        *(int *)((int)pvVar7 + 0x2d8) = iVar16;
        iVar16 = iVar16 + 1;
        *(undefined4 *)(param_5[2] * 4 + *param_5) = 0xe;
        *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
        param_5[2] = param_5[2] + 1;
      }
      if (7 < *(uint *)(param_1 + 0x278)) {
        *(int *)((int)pvVar7 + 0x2dc) = iVar16;
        iVar16 = iVar16 + 1;
        *(undefined4 *)(param_5[2] * 4 + *param_5) = 0xf;
        *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
        param_5[2] = param_5[2] + 1;
      }
      if (7 < *(uint *)(param_1 + 0x280)) {
        *(int *)((int)pvVar7 + 0x2e0) = iVar16;
        iVar16 = iVar16 + 1;
        *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x10;
        *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
        param_5[2] = param_5[2] + 1;
      }
      if (7 < *(uint *)(param_1 + 0x288)) {
        *(int *)((int)pvVar7 + 0x2ec) = iVar16;
        iVar16 = iVar16 + 1;
        *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x11;
        *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
        param_5[2] = param_5[2] + 1;
      }
      if ((7 < *(uint *)(param_1 + 0x270)) || (7 < *(uint *)(param_1 + 0x278))) {
        *(int *)((int)pvVar7 + 0x2f8) = iVar16;
        iVar16 = iVar16 + 1;
        *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x12;
        *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
        param_5[2] = param_5[2] + 1;
      }
      if (1 < *(uint *)(param_1 + 0x290)) {
        *(int *)((int)pvVar7 + 800) = iVar16;
        iVar16 = iVar16 + 1;
        *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x13;
        *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
        param_5[2] = param_5[2] + 1;
      }
      if ("}J3x})+x|B;x}k"[iVar20 + 4] != '\0') {
        if (7 < *(uint *)(param_1 + 0x274)) {
          *(int *)((int)pvVar7 + 0x2fc) = iVar16;
          iVar16 = iVar16 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0xe;
          *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 1;
          param_5[2] = param_5[2] + 1;
        }
        if (7 < *(uint *)(param_1 + 0x27c)) {
          *(int *)((int)pvVar7 + 0x300) = iVar16;
          iVar16 = iVar16 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0xf;
          *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 1;
          param_5[2] = param_5[2] + 1;
        }
        if (7 < *(uint *)(param_1 + 0x284)) {
          *(int *)((int)pvVar7 + 0x304) = iVar16;
          iVar16 = iVar16 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x10;
          *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 1;
          param_5[2] = param_5[2] + 1;
        }
        if (7 < *(uint *)(param_1 + 0x28c)) {
          *(int *)((int)pvVar7 + 0x310) = iVar16;
          iVar16 = iVar16 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x11;
          *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 1;
          param_5[2] = param_5[2] + 1;
        }
        if ((7 < *(uint *)(param_1 + 0x274)) || (7 < *(uint *)(param_1 + 0x27c))) {
          *(int *)((int)pvVar7 + 0x31c) = iVar16;
          iVar16 = iVar16 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x12;
          *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 1;
          param_5[2] = param_5[2] + 1;
        }
        if (1 < *(uint *)(param_1 + 0x294)) {
          *(int *)((int)pvVar7 + 0x324) = iVar16;
          iVar16 = iVar16 + 1;
          *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x13;
          *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 1;
          param_5[2] = param_5[2] + 1;
        }
      }
    }
    *(int *)((int)pvVar7 + 0x328) = iVar16;
    iVar8 = iVar16 + 1;
    *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x14;
    *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
    param_5[2] = param_5[2] + 1;
    if (bVar4) {
      *(int *)((int)pvVar7 + 0x32c) = iVar8;
      iVar8 = iVar16 + 2;
      *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x1b;
      *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
      param_5[2] = param_5[2] + 1;
      uVar6 = *(uint *)(param_1 + 0x44);
    }
    else {
      uVar6 = *(uint *)(param_1 + 0x44);
    }
  }
  if (((uVar6 & 0x1000000) != 0) && (*(char *)(param_1 + 0x121) == '\0')) {
    *(int *)((int)pvVar7 + 0x330) = iVar8;
    iVar8 = iVar8 + 1;
    *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x15;
    *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
    param_5[2] = param_5[2] + 1;
  }
  if ((*(uint *)(param_1 + 0x1874) & 0xc0000000) == 0x80000000) {
    *(int *)((int)pvVar7 + 0x334) = iVar8;
    iVar16 = iVar8 + 1;
    iVar20 = iVar8 + 2;
    iVar8 = iVar8 + 3;
    *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x16;
    *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
    param_5[2] = param_5[2] + 1;
    *(int *)((int)pvVar7 + 0x338) = iVar16;
    *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x17;
    *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
    param_5[2] = param_5[2] + 1;
    *(int *)((int)pvVar7 + 0x340) = iVar20;
    *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x18;
    *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
    param_5[2] = param_5[2] + 1;
  }
  if (*(char *)(param_1 + 300) != '\0') {
    *(int *)((int)pvVar7 + 0x344) = iVar8;
    iVar8 = iVar8 + 1;
    *(undefined4 *)(param_5[2] * 4 + *param_5) = 0x19;
    *(undefined4 *)(param_5[2] * 4 + param_5[1]) = 0;
    param_5[2] = param_5[2] + 1;
  }
  *param_4 = iVar8;
  if (((unsigned char *)0x00004301)[iVar19] == '\0') {
    local_78 = (float)(iVar19 + 0x1960);
    if ((((((local_74[0] == 0 && local_74[1] == 0) && local_74[2] == 0) &&
          FLOAT_001aa0e8 == local_78) &&
         (((local_74[3] == 0 && local_60 == 0) && local_5c == 0) && FLOAT_001aa0e8 == local_64)) &&
        (((local_58 == 0 && local_54 == 0) && local_4c == 0) && FLOAT_001aa0e8 == local_50)) &&
        (((local_48 == 0 && unaff_r17 == 0) && unaff_r18 == 0) && FLOAT_001aa0e8 == unaff_r19)) {
      FUN_00092d40(pvVar7,uVar18,uVar1);
    }
    else {
      FUN_00095dd0(pvVar7,uVar18,uVar1);
    }
    if (*(char *)(param_1 + 0x12a) != '\0') {
      FUN_00096500(pvVar7);
    }
  }
  else {
    uVar6 = (uint)*(byte *)(param_1 + 0x90);
    if (uVar6 != 0) {
      iVar20 = 0;
      iVar8 = param_1;
      if (uVar6 == 0) {
        uVar6 = 1;
      }
      do {
        local_74[iVar20] = (uint)(byte)((unsigned char *)0x000013a9)[iVar8];
        uVar6 = uVar6 - 1;
        iVar20 = iVar20 + 1;
        iVar8 = iVar8 + 1;
      } while (uVar6 != 0);
    }
    FUN_000955e0(pvVar7,*(undefined1 *)(param_1 + 0x91),((unsigned char *)0x00004302)[iVar19]);
    if (*(char *)(param_1 + 0x129) == '\0') {
      FUN_00093a40(pvVar7,local_74,*(undefined1 *)(param_1 + 0x91),((unsigned char *)0x00004302)[iVar19],uVar18,
                   uVar1);
    }
    else {
      FUN_00094840(pvVar7,local_74,*(undefined1 *)(param_1 + 0x91),((unsigned char *)0x00004302)[iVar19],
                   *(char *)(param_1 + 0x90) == '\x02');
      FUN_00095610(pvVar7,uVar18,uVar1);
    }
    if (*(char *)(param_1 + 0x12a) != '\0') {
      FUN_00093510(pvVar7,local_74,*(undefined1 *)(param_1 + 0x91),((unsigned char *)0x00004302)[iVar19]);
    }
  }
  if (*(char *)(param_1 + 0x128) == '\0') {
    if (*(char *)(param_1 + 300) != '\0') {
      FUN_000939e0(pvVar7);
    }
  }
  else {
    FUN_00093a20(pvVar7);
  }
  uVar6 = *(uint *)(param_1 + 0x44);
  if ((((uVar6 & 0x1000000) != 0) && (*(char *)(param_1 + 0x121) == '\0')) &&
     ((*(int *)((int)pvVar7 + 0x3d8) == 0 || ((uVar6 & 0x2000) == 0)))) {
    sVar3 = *(short *)(((unsigned char *)0x00002e04) + iVar19);
    if (sVar3 == 0x801) {
      FUN_00096540(pvVar7);
      uVar6 = *(uint *)(param_1 + 0x44);
    }
    else if (sVar3 == 0x2601) {
      FUN_0009af00(pvVar7);
      uVar6 = *(uint *)(param_1 + 0x44);
    }
    else if (sVar3 == 0x800) {
      FUN_0009b790(pvVar7);
      uVar6 = *(uint *)(param_1 + 0x44);
    }
  }
  if ((uVar6 & 0x20000) == 0) {
    if ((*(uint *)(param_1 + 0x8c) & 0x800000) == 0) goto LAB_0009e8dc;
    uVar9 = (uint)*(byte *)(param_1 + 0x2b);
    if ((uint)(byte)((unsigned char *)0x000013b0)[param_1] < (uint)*(byte *)(param_1 + 0x2b)) {
      uVar9 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    }
    if (uVar9 == 0) goto LAB_0009e8dc;
    uVar6 = 0;
    puVar24 = (ushort *)(param_1 + 0x187c);
    iVar20 = param_1;
    iVar8 = param_1;
    do {
      if (((unsigned char *)0x00001438)[iVar8] != '\0') {
        FUN_00096600(pvVar7,uVar6,0,uVar6,*(undefined1 *)(iVar20 + 0x153),uVar6,
                     *puVar24 >> 2 & 0xfff);
      }
      uVar6 = uVar6 + 1;
      puVar24 = puVar24 + 1;
      iVar8 = iVar8 + 1;
      iVar20 = iVar20 + 4;
    } while (uVar9 != uVar6);
  }
  else {
    if ((uVar6 & 0x2000) == 0) {
      bVar2 = ((unsigned char *)0x00001135)[param_1];
    }
    else {
      bVar2 = ((unsigned char *)0x000011d3)[param_1];
    }
    uVar9 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
    if (uVar9 == 0) goto LAB_0009e8dc;
    uVar6 = 0;
    puVar24 = (ushort *)(param_1 + 0x187c);
    iVar20 = param_1;
    do {
      if (((uint)bVar2 & 1 << (uVar6 & 0x3f)) != 0) {
        FUN_00096600(pvVar7,uVar6,0,uVar6,*(undefined1 *)(iVar20 + 0x153),uVar6,
                     *puVar24 >> 2 & 0xfff);
        uVar9 = (uint)(byte)((unsigned char *)0x000013b0)[param_1];
      }
      uVar6 = uVar6 + 1;
      puVar24 = puVar24 + 1;
      iVar20 = iVar20 + 4;
    } while ((int)uVar6 < (int)uVar9);
  }
  uVar6 = *(uint *)(param_1 + 0x44);
LAB_0009e8dc:
  if ((int)uVar6 < 0) {
    iVar20 = 0;
    FUN_00096d80(pvVar7);
    fVar12 = FLOAT_001aa0d4;
    uVar6 = *(uint *)(param_1 + 0x88);
    if (uVar6 != 0) {
      iVar20 = 0;
      iVar8 = 0;
      puVar22 = (uint *)(param_1 + 0x3a8);
      uVar9 = uVar6;
      do {
        if (((uVar9 & 1) != 0) && ((*puVar22 & 0xfc000000) != 0)) {
          iVar8 = iVar20;
        }
        uVar9 = uVar9 >> 1;
        iVar20 = iVar20 + 1;
        puVar22 = puVar22 + 1;
      } while (uVar9 != 0);
      iVar20 = 0;
      iVar16 = 0;
      puVar22 = (uint *)(param_1 + 0x3a8);
      do {
        if (((uVar6 & 1) != 0) && (uVar9 = *puVar22, (uVar9 & 0xfc000000) != 0)) {
          if (*(float *)(iVar19 + 0x24fc) == fVar12) {
            FUN_00097440(pvVar7,iVar16,iVar20 == 0,iVar16 == iVar8,uVar9 >> 0x1e,uVar9 >> 0x1c & 3,
                         uVar9 >> 0x1a & 3);
          }
          else {
            FUN_00098500(pvVar7,iVar16,iVar20 == 0,iVar16 == iVar8,uVar9 >> 0x19 & 1,
                         uVar9 >> 0x18 & 1,uVar9 >> 0x17 & 1,uVar9 >> 0x1e);
          }
          iVar20 = iVar20 + 1;
        }
        uVar6 = uVar6 >> 1;
        iVar16 = iVar16 + 1;
        puVar22 = puVar22 + 1;
        iVar19 = iVar19 + 0x80;
      } while (uVar6 != 0);
    }
    FUN_0009b430(pvVar7,iVar20);
  }
  else {
    FUN_00092ea0(pvVar7,3,0,0);
    if ((*(uint *)(param_1 + 0x44) & 0xa10000) != 0) {
      FUN_00092ea0(pvVar7,4,1,0);
    }
  }
  if ((*(uint *)(param_1 + 0x1874) & 0xc0000000) == 0x80000000) {
    FUN_00099e50(pvVar7,2,*(float *)(param_1 + 0x114) == FLOAT_001aa0d4);
  }
  if ((*(uint *)(param_1 + 0x44) & 0x800) == 0) {
    if (*(char *)(param_1 + 0x121) != '\0') {
      FUN_0009b850(pvVar7,*(undefined1 *)(param_1 + 0x120));
    }
  }
  else if (*(int *)((int)pvVar7 + 0x3d8) == 0) {
    FUN_0009b850(pvVar7,((unsigned char *)0x000011d1)[param_1]);
  }
  else {
    FUN_0009a590(pvVar7);
  }
  iVar19 = FUN_0009a910(pvVar7);
  if (iVar19 == 6) {
    *(undefined1 *)(param_1 + 0x126) = 1;
  }
  return pvVar7;
}

/* FUN_0009eb90 @ 0x9eb90 (560 bytes) */
int FUN_0009eb90(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  
  iVar11 = *(int *)(((unsigned char *)0x0000111c) + param_1);
  if (iVar11 != 0xfb2f) {
    *(int *)(((unsigned char *)0x0000111c) + param_1) = iVar11 + param_2;
    if (0xfb2f < (uint)(iVar11 + param_2)) {
      *(undefined4 *)(((unsigned char *)0x0000111c) + param_1) = 0xfb2f;
    }
    iVar3 = (**(code **)(param_1 + 0x10))(1,*(int *)(((unsigned char *)0x0000111c) + param_1) << 2);
    if (iVar11 == 0) {
      iVar4 = *(int *)(((unsigned char *)0x00001118) + param_1);
    }
    else {
      iVar4 = *(int *)(((unsigned char *)0x00001118) + param_1);
      iVar12 = 0;
      do {
        puVar5 = *(uint **)(iVar12 * 4 + iVar4);
        if (puVar5 != (uint *)0x0) {
          do {
            puVar10 = puVar5 + 0xc;
            if (puVar10 < puVar5 + 0xb) {
              uVar7 = 0;
              puVar6 = puVar5;
            }
            else {
              uVar7 = 0;
              puVar9 = puVar5 + 0xb;
              puVar8 = puVar5;
              do {
                puVar6 = puVar9;
                uVar7 = uVar7 ^ *puVar8 ^ (puVar8[1] << 3 | puVar8[1] >> 0x1d) ^
                        (puVar8[2] << 6 | puVar8[2] >> 0x1a) ^ (puVar8[3] << 9 | puVar8[3] >> 0x17)
                        ^ (puVar8[4] << 0xc | puVar8[4] >> 0x14) ^
                        (puVar8[5] << 0xf | puVar8[5] >> 0x11) ^
                        (puVar8[6] << 0x12 | puVar8[6] >> 0xe) ^
                        (puVar8[7] << 0x15 | puVar8[7] >> 0xb) ^
                        (puVar8[8] << 0x18 | puVar8[8] >> 8) ^ (puVar8[9] << 0x1b | puVar8[9] >> 5)
                        ^ (puVar8[10] << 0x1e | puVar8[10] >> 2);
                puVar9 = puVar6 + 0xb;
                puVar8 = puVar6;
              } while (puVar6 + 0xb <= puVar10);
            }
            puVar9 = puVar6 + 5;
            if (puVar10 < puVar9) {
              uVar2 = 0;
              puVar9 = puVar6;
            }
            else {
              uVar2 = 0xf;
              uVar7 = uVar7 ^ *puVar6 ^ (puVar6[1] << 3 | puVar6[1] >> 0x1d) ^
                      (puVar6[2] << 6 | puVar6[2] >> 0x1a) ^ (puVar6[3] << 9 | puVar6[3] >> 0x17) ^
                      (puVar6[4] << 0xc | puVar6[4] >> 0x14);
            }
            for (; puVar9 < puVar10; puVar9 = puVar9 + 1) {
              uVar1 = uVar2 & 0x1f;
              uVar2 = uVar2 + 3;
              uVar7 = uVar7 ^ (*puVar9 << uVar1 | *puVar9 >> 0x20 - uVar1);
            }
            puVar10 = (uint *)puVar5[0x17];
            iVar4 = (uVar7 - (uVar7 / *(uint *)(((unsigned char *)0x0000111c) + param_1)) *
                             *(uint *)(((unsigned char *)0x0000111c) + param_1)) * 4;
            puVar5[0x17] = *(uint *)(iVar3 + iVar4);
            *(uint **)(iVar3 + iVar4) = puVar5;
            puVar5 = puVar10;
          } while (puVar10 != (uint *)0x0);
          iVar4 = *(int *)(((unsigned char *)0x00001118) + param_1);
        }
        iVar12 = iVar12 + 1;
      } while (iVar11 != iVar12);
    }
    (**(code **)(param_1 + 0x18))(iVar4);
    *(int *)(((unsigned char *)0x00001118) + param_1) = iVar3;
  }
  return;
}

/* FUN_0009edd0 @ 0x9edd0 (708 bytes) */
int FUN_0009edd0(param_1, param_2)
  int param_1;
  uint *param_2;
{
  bool bVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  uint uVar10;
  void *pvVar11;
  
  bVar1 = ((unsigned char *)0x00001120)[param_1] == '\0';
  if (bVar1) {
    puVar8 = param_2 + 0xc;
    uVar10 = *(uint *)(((unsigned char *)0x0000111c) + param_1);
    uVar4 = 0;
    puVar3 = param_2;
    while (puVar3 + 0xb <= puVar8) {
      uVar4 = uVar4 ^ *puVar3 ^ (puVar3[1] << 3 | puVar3[1] >> 0x1d) ^
              (puVar3[2] << 6 | puVar3[2] >> 0x1a) ^ (puVar3[3] << 9 | puVar3[3] >> 0x17) ^
              (puVar3[4] << 0xc | puVar3[4] >> 0x14) ^ (puVar3[5] << 0xf | puVar3[5] >> 0x11) ^
              (puVar3[6] << 0x12 | puVar3[6] >> 0xe) ^ (puVar3[7] << 0x15 | puVar3[7] >> 0xb) ^
              (puVar3[8] << 0x18 | puVar3[8] >> 8) ^ (puVar3[9] << 0x1b | puVar3[9] >> 5) ^
              (puVar3[10] << 0x1e | puVar3[10] >> 2);
      puVar3 = puVar3 + 0xb;
    }
    puVar9 = puVar3 + 5;
    if (puVar8 < puVar9) {
      uVar6 = 0;
      puVar9 = puVar3;
    }
    else {
      uVar6 = 0xf;
      uVar4 = uVar4 ^ *puVar3 ^ (puVar3[1] << 3 | puVar3[1] >> 0x1d) ^
              (puVar3[2] << 6 | puVar3[2] >> 0x1a) ^ (puVar3[3] << 9 | puVar3[3] >> 0x17) ^
              (puVar3[4] << 0xc | puVar3[4] >> 0x14);
    }
    for (; puVar9 < puVar8; puVar9 = puVar9 + 1) {
      uVar2 = uVar6 & 0x1f;
      uVar6 = uVar6 + 3;
      uVar4 = uVar4 ^ (*puVar9 << uVar2 | *puVar9 >> 0x20 - uVar2);
    }
    iVar5 = uVar4 - (uVar4 / uVar10) * uVar10;
  }
  else {
    uVar10 = *(uint *)(((unsigned char *)0x0000111c) + param_1);
    uVar4 = *param_2 + param_2[2] + param_2[3];
    iVar5 = uVar4 - (uVar4 / uVar10) * uVar10;
  }
  pvVar11 = *(void **)(iVar5 * 4 + *(int *)(((unsigned char *)0x00001118) + param_1));
  if (*(char *)(param_1 + 0x2f) == '\0') {
    iVar5 = 0;
    if (pvVar11 != (void *)0x0) {
      do {
        iVar7 = _memcmp(pvVar11,param_2,0x30);
        if (iVar7 == 0) {
          return pvVar11;
        }
        pvVar11 = *(void **)((int)pvVar11 + 0x5c);
        iVar5 = iVar5 + 1;
      } while (pvVar11 != (void *)0x0);
      goto LAB_0009f014;
    }
  }
  else {
    iVar5 = 0;
    if (pvVar11 != (void *)0x0) {
      do {
        iVar7 = _memcmp(pvVar11,param_2,0x18);
        if (iVar7 == 0) {
          return pvVar11;
        }
        pvVar11 = *(void **)((int)pvVar11 + 0x5c);
        iVar5 = iVar5 + 1;
      } while (pvVar11 != (void *)0x0);
      goto LAB_0009f014;
    }
  }
  iVar5 = 0;
LAB_0009f014:
  if ((bVar1) || (iVar5 < 5)) {
    if ((iVar5 < 8) || (0xfb2e < uVar10)) {
      return (void *)0x0;
    }
    if (bVar1) {
      ((int (*)())FUN_0009eb90)(param_1,0x859);
      return (void *)0x0;
    }
  }
  ((int (*)())FUN_0009eb90)(param_1,0);
  ((unsigned char *)0x00001120)[param_1] = 0;
  return (void *)0x0;
}

/* FUN_0009f0b0 @ 0x9f0b0 (4444 bytes) */
int FUN_0009f0b0()
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  uint uVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  undefined4 uVar27;
  int iVar28;
  int iVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 uVar32;
  undefined4 uVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  int iVar36;
  undefined8 *puVar37;
  uint uVar38;
  int iVar39;
  undefined4 uVar40;
  int iVar41;
  int iVar42;
  uint uVar43;
  int iVar44;
  int iVar45;
  int iVar46;
  int iVar47;
  undefined4 uVar48;
  undefined4 uVar49;
  undefined4 uVar50;
  undefined4 uVar51;
  undefined4 uVar52;
  undefined4 uVar53;
  undefined4 uVar54;
  uint uVar55;
  int *piVar56;
  undefined8 uVar57;
  undefined8 uVar58;
  float local_168;
  float fStack_164;
  float local_160;
  undefined4 uStack_15c;
  float local_158;
  float local_154;
  float local_150;
  float local_14c;
  float local_148;
  float local_144;
  float local_140;
  float local_13c;
  float local_138;
  float local_134;
  float local_130;
  float local_12c;
  float local_128;
  float local_124;
  float local_120;
  float local_11c;
  undefined4 local_118;
  uint uStack_114;
  undefined4 local_110;
  uint uStack_10c;
  float local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  float local_f4;
  float local_f0;
  
  uVar58 = FUN_001a322c();
  iVar29 = (int)((ulonglong)uVar58 >> 0x20);
  iVar44 = (int)uVar58;
  piVar56 = *(int **)(iVar44 + 0x50);
  iVar42 = *(int *)(iVar29 + 4);
  iVar28 = *(int *)(iVar44 + 0x54);
  iVar47 = *(int *)(iVar44 + 0x4c);
  uVar38 = piVar56[2];
  iVar46 = *(int *)(iVar42 + 0x10);
  iVar44 = iVar28 + 0xa4;
  if (uVar38 != 0) {
    uVar43 = 0;
    iVar45 = 0;
    do {
      uVar55 = *(uint *)(piVar56[1] + iVar45);
      switch(*(undefined4 *)(*piVar56 + iVar45)) {
      case 0:
        fVar5 = *(float *)(iVar46 + 0x1920);
        iVar36 = iVar46 + 0x1860 + uVar55 * 0x40;
        fVar6 = *(float *)(iVar46 + 0x1930);
        fVar7 = *(float *)(iVar46 + 0x1934);
        fVar8 = *(float *)(iVar46 + 0x1938);
        fVar9 = *(float *)(iVar46 + 0x193c);
        fVar10 = *(float *)(iVar36 + 0x100);
        fVar11 = *(float *)(iVar46 + 0x1924);
        fVar12 = *(float *)(iVar36 + 0x104);
        fVar13 = *(float *)(iVar46 + 0x1928);
        fVar14 = *(float *)(iVar46 + 0x192c);
        fVar15 = *(float *)(iVar46 + 0x1940);
        fVar16 = *(float *)(iVar46 + 0x1944);
        fVar17 = *(float *)(iVar46 + 0x1948);
        fVar18 = *(float *)(iVar46 + 0x194c);
        fVar19 = *(float *)(iVar36 + 0x108);
        fVar20 = *(float *)(iVar46 + 0x195c);
        fVar1 = *(float *)(iVar46 + 0x1950);
        fVar2 = *(float *)(iVar46 + 0x1954);
        fVar3 = *(float *)(iVar46 + 0x1958);
        fVar4 = *(float *)(iVar36 + 0x10c);
        local_14c = fVar20 * fVar4 + fVar18 * fVar19 + fVar14 * fVar10 + fVar9 * fVar12;
        local_158 = fVar1 * fVar4 + fVar15 * fVar19 + fVar5 * fVar10 + fVar6 * fVar12;
        local_154 = fVar2 * fVar4 + fVar16 * fVar19 + fVar11 * fVar10 + fVar7 * fVar12;
        local_150 = fVar3 * fVar4 + fVar17 * fVar19 + fVar13 * fVar10 + fVar8 * fVar12;
        fVar10 = *(float *)(iVar36 + 0x114);
        fVar12 = *(float *)(iVar36 + 0x110);
        fVar19 = *(float *)(iVar36 + 0x118);
        fVar4 = *(float *)(iVar36 + 0x11c);
        local_13c = fVar20 * fVar4 + fVar18 * fVar19 + fVar14 * fVar12 + fVar9 * fVar10;
        local_148 = fVar1 * fVar4 + fVar15 * fVar19 + fVar5 * fVar12 + fVar6 * fVar10;
        local_144 = fVar2 * fVar4 + fVar16 * fVar19 + fVar11 * fVar12 + fVar7 * fVar10;
        local_140 = fVar3 * fVar4 + fVar17 * fVar19 + fVar13 * fVar12 + fVar8 * fVar10;
        fVar10 = *(float *)(iVar36 + 0x124);
        fVar12 = *(float *)(iVar36 + 0x120);
        fVar19 = *(float *)(iVar36 + 0x128);
        fVar4 = *(float *)(iVar36 + 300);
        local_12c = fVar20 * fVar4 + fVar18 * fVar19 + fVar14 * fVar12 + fVar9 * fVar10;
        local_138 = fVar1 * fVar4 + fVar15 * fVar19 + fVar5 * fVar12 + fVar6 * fVar10;
        local_134 = fVar2 * fVar4 + fVar16 * fVar19 + fVar11 * fVar12 + fVar7 * fVar10;
        local_130 = fVar3 * fVar4 + fVar17 * fVar19 + fVar13 * fVar12 + fVar8 * fVar10;
        fVar10 = *(float *)(iVar36 + 0x134);
        fVar12 = *(float *)(iVar36 + 0x130);
        fVar19 = *(float *)(iVar36 + 0x138);
        fVar4 = *(float *)(iVar36 + 0x13c);
        local_11c = fVar20 * fVar4 + fVar18 * fVar19 + fVar14 * fVar12 + fVar9 * fVar10;
        local_128 = fVar1 * fVar4 + fVar15 * fVar19 + fVar5 * fVar12 + fVar6 * fVar10;
        local_124 = fVar2 * fVar4 + fVar16 * fVar19 + fVar11 * fVar12 + fVar7 * fVar10;
        local_120 = fVar3 * fVar4 + fVar17 * fVar19 + fVar13 * fVar12 + fVar8 * fVar10;
        iVar36 = *(int *)(uVar55 * 4 + iVar44) * 0x10;
        iVar41 = iVar47 + iVar36;
        if ((*(uint *)(((unsigned char *)0x000013c0) + iVar29) & 4) == 0) {
          *(float *)(iVar47 + iVar36) = local_158;
          *(float *)(iVar41 + 0x3c) = local_11c;
          *(float *)(iVar41 + 4) = local_148;
          *(float *)(iVar41 + 8) = local_138;
          *(float *)(iVar41 + 0xc) = local_128;
          *(float *)(iVar41 + 0x10) = local_154;
          *(float *)(iVar41 + 0x14) = local_144;
          *(float *)(iVar41 + 0x18) = local_134;
          *(float *)(iVar41 + 0x1c) = local_124;
          *(float *)(iVar41 + 0x20) = local_150;
          *(float *)(iVar41 + 0x24) = local_140;
          *(float *)(iVar41 + 0x28) = local_130;
          *(float *)(iVar41 + 0x2c) = local_120;
          *(float *)(iVar41 + 0x30) = local_14c;
          *(float *)(iVar41 + 0x34) = local_13c;
          *(float *)(iVar41 + 0x38) = local_12c;
          uVar38 = piVar56[2];
        }
        else {
          *(float *)(iVar47 + iVar36) = local_158;
          *(float *)(iVar41 + 0x3c) = local_11c;
          *(float *)(iVar41 + 4) = local_154;
          *(float *)(iVar41 + 8) = local_150;
          *(float *)(iVar41 + 0xc) = local_14c;
          *(float *)(iVar41 + 0x10) = local_148;
          *(float *)(iVar41 + 0x14) = local_144;
          *(float *)(iVar41 + 0x18) = local_140;
          *(float *)(iVar41 + 0x1c) = local_13c;
          *(float *)(iVar41 + 0x20) = local_138;
          *(float *)(iVar41 + 0x24) = local_134;
          *(float *)(iVar41 + 0x28) = local_130;
          *(float *)(iVar41 + 0x2c) = local_12c;
          *(float *)(iVar41 + 0x30) = local_128;
          *(float *)(iVar41 + 0x34) = local_124;
          *(float *)(iVar41 + 0x38) = local_120;
          uVar38 = piVar56[2];
        }
        break;
      case 1:
        iVar39 = iVar46 + 0x1860 + uVar55 * 0x40;
        iVar36 = *(int *)(uVar55 * 4 + iVar44 + 0x10) * 0x10;
        uVar32 = *(undefined4 *)(iVar39 + 0x104);
        uVar35 = *(undefined4 *)(iVar39 + 0x13c);
        iVar41 = iVar47 + iVar36;
        uVar52 = *(undefined4 *)(iVar39 + 0x108);
        uVar50 = *(undefined4 *)(iVar39 + 0x10c);
        uVar40 = *(undefined4 *)(iVar39 + 0x110);
        uVar30 = *(undefined4 *)(iVar39 + 0x114);
        uVar53 = *(undefined4 *)(iVar39 + 0x118);
        uVar48 = *(undefined4 *)(iVar39 + 0x11c);
        uVar34 = *(undefined4 *)(iVar39 + 0x120);
        uVar31 = *(undefined4 *)(iVar39 + 0x124);
        uVar51 = *(undefined4 *)(iVar39 + 0x128);
        uVar49 = *(undefined4 *)(iVar39 + 300);
        uVar33 = *(undefined4 *)(iVar39 + 0x130);
        uVar54 = *(undefined4 *)(iVar39 + 0x134);
        uVar27 = *(undefined4 *)(iVar39 + 0x138);
        if ((*(uint *)(((unsigned char *)0x000013c0) + iVar29) & 4) == 0) {
          *(undefined4 *)(iVar47 + iVar36) = *(undefined4 *)(iVar39 + 0x100);
          *(undefined4 *)(iVar41 + 0x3c) = uVar35;
          *(undefined4 *)(iVar41 + 4) = uVar40;
          *(undefined4 *)(iVar41 + 8) = uVar34;
          *(undefined4 *)(iVar41 + 0xc) = uVar33;
          *(undefined4 *)(iVar41 + 0x10) = uVar32;
          *(undefined4 *)(iVar41 + 0x14) = uVar30;
          *(undefined4 *)(iVar41 + 0x18) = uVar31;
          *(undefined4 *)(iVar41 + 0x1c) = uVar54;
          *(undefined4 *)(iVar41 + 0x20) = uVar52;
          *(undefined4 *)(iVar41 + 0x24) = uVar53;
          *(undefined4 *)(iVar41 + 0x28) = uVar51;
          *(undefined4 *)(iVar41 + 0x2c) = uVar27;
          *(undefined4 *)(iVar41 + 0x30) = uVar50;
          *(undefined4 *)(iVar41 + 0x34) = uVar48;
          *(undefined4 *)(iVar41 + 0x38) = uVar49;
          uVar38 = piVar56[2];
        }
        else {
          *(undefined4 *)(iVar47 + iVar36) = *(undefined4 *)(iVar39 + 0x100);
          *(undefined4 *)(iVar41 + 0x3c) = uVar35;
          *(undefined4 *)(iVar41 + 4) = uVar32;
          *(undefined4 *)(iVar41 + 8) = uVar52;
          *(undefined4 *)(iVar41 + 0xc) = uVar50;
          *(undefined4 *)(iVar41 + 0x10) = uVar40;
          *(undefined4 *)(iVar41 + 0x14) = uVar30;
          *(undefined4 *)(iVar41 + 0x18) = uVar53;
          *(undefined4 *)(iVar41 + 0x1c) = uVar48;
          *(undefined4 *)(iVar41 + 0x20) = uVar34;
          *(undefined4 *)(iVar41 + 0x24) = uVar31;
          *(undefined4 *)(iVar41 + 0x28) = uVar51;
          *(undefined4 *)(iVar41 + 0x2c) = uVar49;
          *(undefined4 *)(iVar41 + 0x30) = uVar33;
          *(undefined4 *)(iVar41 + 0x34) = uVar54;
          *(undefined4 *)(iVar41 + 0x38) = uVar27;
          uVar38 = piVar56[2];
        }
        break;
      case 2:
        iVar36 = iVar46 + 0x1860 + uVar55 * 0x40;
        fVar5 = *(float *)(iVar36 + 0x100);
        fVar6 = *(float *)(iVar36 + 0x138);
        fVar7 = *(float *)(iVar36 + 0x11c);
        fVar8 = *(float *)(iVar36 + 0x118);
        fVar9 = *(float *)(iVar36 + 0x13c);
        fVar10 = *(float *)(iVar36 + 0x10c);
        fVar11 = *(float *)(iVar36 + 0x108);
        fVar12 = *(float *)(iVar36 + 0x128);
        fVar13 = *(float *)(iVar36 + 0x104);
        fVar14 = *(float *)(iVar36 + 0x114);
        fVar15 = *(float *)(iVar36 + 0x124);
        local_108 = fVar8 * fVar9 - fVar7 * fVar6;
        fVar25 = fVar11 * fVar9 - fVar10 * fVar6;
        fVar26 = fVar11 * fVar7 - fVar10 * fVar8;
        fVar16 = *(float *)(iVar36 + 300);
        fVar17 = *(float *)(iVar36 + 0x134);
        fVar18 = *(float *)(iVar36 + 0x120);
        fVar22 = fVar11 * fVar16 - fVar10 * fVar12;
        fVar23 = fVar8 * fVar16 - fVar7 * fVar12;
        local_100 = fVar17 * fVar26 + (fVar13 * local_108 - fVar14 * fVar25);
        fVar24 = fVar12 * fVar9 - fVar16 * fVar6;
        fVar4 = fVar5 * fVar15 - fVar13 * fVar18;
        local_104 = -(fVar13 * fVar23 - (fVar14 * fVar22 - fVar15 * fVar26));
        local_fc = -(fVar13 * fVar24 - (fVar15 * fVar25 - fVar17 * fVar22));
        local_f8 = fVar17 * fVar23 + (fVar14 * fVar24 - fVar15 * local_108);
        fVar19 = *(float *)(iVar36 + 0x130);
        fVar20 = *(float *)(iVar36 + 0x110);
        fVar1 = fVar20 * fVar15 - fVar14 * fVar18;
        fVar3 = fVar5 * fVar17 - fVar13 * fVar19;
        fVar2 = fVar5 * fVar14 - fVar13 * fVar20;
        fVar13 = fVar20 * fVar17 - fVar14 * fVar19;
        fVar14 = fVar18 * fVar17 - fVar15 * fVar19;
        local_f4 = fVar5 * local_f8 + fVar20 * local_fc + fVar19 * local_104 + fVar18 * local_100;
        local_f0 = fVar13 * fVar16;
        if (local_f4 != FLOAT_001aa0d4) {
          local_120 = FLOAT_001aa0e8 / local_f4;
          local_158 = local_f8 * local_120;
          local_138 = local_100 * local_120;
          local_148 = local_fc * local_120;
          local_14c = -(fVar14 * fVar8 - (fVar13 * fVar12 - fVar1 * fVar6)) * local_120;
          local_11c = (fVar2 * fVar12 + (fVar1 * fVar11 - fVar4 * fVar8)) * local_120;
          local_154 = local_120 * -(fVar20 * fVar24 - (fVar18 * local_108 - fVar19 * fVar23));
          local_150 = (fVar1 * fVar9 + (fVar14 * fVar7 - local_f0)) * local_120;
          local_144 = local_120 * (fVar19 * fVar22 + (fVar5 * fVar24 - fVar18 * fVar25));
          local_140 = -(fVar14 * fVar10 - (fVar3 * fVar16 - fVar4 * fVar9)) * local_120;
          local_134 = local_120 * -(fVar5 * local_108 - (fVar20 * fVar25 - fVar19 * fVar26));
          local_13c = (fVar4 * fVar6 + (fVar14 * fVar11 - fVar3 * fVar12)) * local_120;
          local_124 = local_120 * (fVar18 * fVar26 + (fVar5 * fVar23 - fVar20 * fVar22));
          local_128 = local_104 * local_120;
          local_12c = -(fVar13 * fVar11 - (fVar3 * fVar8 - fVar2 * fVar6)) * local_120;
          local_130 = (fVar2 * fVar9 + (fVar13 * fVar10 - fVar3 * fVar7)) * local_120;
          local_120 = -(fVar1 * fVar10 - (fVar4 * fVar7 - fVar2 * fVar16)) * local_120;
        }
        iVar36 = *(int *)(uVar55 * 4 + iVar44 + 0x20) * 0x10;
        iVar41 = iVar47 + iVar36;
        *(float *)(iVar47 + iVar36) = local_158;
        *(float *)(iVar41 + 0x3c) = local_11c;
        *(float *)(iVar41 + 4) = local_148;
        *(float *)(iVar41 + 8) = local_138;
        *(float *)(iVar41 + 0xc) = local_128;
        *(float *)(iVar41 + 0x10) = local_154;
        *(float *)(iVar41 + 0x14) = local_144;
        *(float *)(iVar41 + 0x18) = local_134;
        *(float *)(iVar41 + 0x1c) = local_124;
        *(float *)(iVar41 + 0x20) = local_150;
        *(float *)(iVar41 + 0x24) = local_140;
        *(float *)(iVar41 + 0x28) = local_130;
        *(float *)(iVar41 + 0x2c) = local_120;
        *(float *)(iVar41 + 0x30) = local_14c;
        *(float *)(iVar41 + 0x34) = local_13c;
        *(float *)(iVar41 + 0x38) = local_12c;
        uVar38 = piVar56[2];
        break;
      case 3:
        uVar33 = *(undefined4 *)(iVar46 + 0x1924);
        uVar52 = *(undefined4 *)(iVar46 + 0x1928);
        uVar50 = *(undefined4 *)(iVar46 + 0x192c);
        uVar31 = *(undefined4 *)(iVar46 + 0x1934);
        iVar36 = *(int *)(iVar28 + 0xd4) * 0x10;
        uVar27 = *(undefined4 *)(iVar46 + 0x195c);
        uVar40 = *(undefined4 *)(iVar46 + 0x1930);
        uVar53 = *(undefined4 *)(iVar46 + 0x1938);
        uVar48 = *(undefined4 *)(iVar46 + 0x193c);
        uVar35 = *(undefined4 *)(iVar46 + 0x1940);
        iVar41 = iVar47 + iVar36;
        uVar32 = *(undefined4 *)(iVar46 + 0x1944);
        uVar51 = *(undefined4 *)(iVar46 + 0x1948);
        uVar49 = *(undefined4 *)(iVar46 + 0x194c);
        uVar34 = *(undefined4 *)(iVar46 + 0x1950);
        uVar54 = *(undefined4 *)(iVar46 + 0x1954);
        uVar30 = *(undefined4 *)(iVar46 + 0x1958);
        if ((*(uint *)(((unsigned char *)0x000013c0) + iVar29) & 4) == 0) {
          *(undefined4 *)(iVar47 + iVar36) = *(undefined4 *)(iVar46 + 0x1920);
          *(undefined4 *)(iVar41 + 0x3c) = uVar27;
          *(undefined4 *)(iVar41 + 4) = uVar40;
          *(undefined4 *)(iVar41 + 8) = uVar35;
          *(undefined4 *)(iVar41 + 0xc) = uVar34;
          *(undefined4 *)(iVar41 + 0x10) = uVar33;
          *(undefined4 *)(iVar41 + 0x14) = uVar31;
          *(undefined4 *)(iVar41 + 0x18) = uVar32;
          *(undefined4 *)(iVar41 + 0x1c) = uVar54;
          *(undefined4 *)(iVar41 + 0x20) = uVar52;
          *(undefined4 *)(iVar41 + 0x24) = uVar53;
          *(undefined4 *)(iVar41 + 0x28) = uVar51;
          *(undefined4 *)(iVar41 + 0x2c) = uVar30;
          *(undefined4 *)(iVar41 + 0x30) = uVar50;
          *(undefined4 *)(iVar41 + 0x34) = uVar48;
          *(undefined4 *)(iVar41 + 0x38) = uVar49;
          uVar38 = piVar56[2];
        }
        else {
          *(undefined4 *)(iVar47 + iVar36) = *(undefined4 *)(iVar46 + 0x1920);
          *(undefined4 *)(iVar41 + 0x3c) = uVar27;
          *(undefined4 *)(iVar41 + 4) = uVar33;
          *(undefined4 *)(iVar41 + 8) = uVar52;
          *(undefined4 *)(iVar41 + 0xc) = uVar50;
          *(undefined4 *)(iVar41 + 0x10) = uVar40;
          *(undefined4 *)(iVar41 + 0x14) = uVar31;
          *(undefined4 *)(iVar41 + 0x18) = uVar53;
          *(undefined4 *)(iVar41 + 0x1c) = uVar48;
          *(undefined4 *)(iVar41 + 0x20) = uVar35;
          *(undefined4 *)(iVar41 + 0x24) = uVar32;
          *(undefined4 *)(iVar41 + 0x28) = uVar51;
          *(undefined4 *)(iVar41 + 0x2c) = uVar49;
          *(undefined4 *)(iVar41 + 0x30) = uVar34;
          *(undefined4 *)(iVar41 + 0x34) = uVar54;
          *(undefined4 *)(iVar41 + 0x38) = uVar30;
          uVar38 = piVar56[2];
        }
        break;
      case 4:
        iVar39 = *(int *)(iVar42 + 0x10) + 0x1860 + uVar55 * 0x40;
        iVar36 = *(int *)(uVar55 * 4 + iVar44 + 0x34) * 0x10;
        uVar40 = *(undefined4 *)(iVar39 + 0x420);
        uVar48 = *(undefined4 *)(iVar39 + 0x43c);
        iVar41 = iVar47 + iVar36;
        uVar54 = *(undefined4 *)(iVar39 + 0x404);
        uVar51 = *(undefined4 *)(iVar39 + 0x408);
        uVar49 = *(undefined4 *)(iVar39 + 0x40c);
        uVar34 = *(undefined4 *)(iVar39 + 0x410);
        uVar31 = *(undefined4 *)(iVar39 + 0x414);
        uVar53 = *(undefined4 *)(iVar39 + 0x418);
        uVar50 = *(undefined4 *)(iVar39 + 0x41c);
        uVar33 = *(undefined4 *)(iVar39 + 0x424);
        uVar30 = *(undefined4 *)(iVar39 + 0x428);
        uVar52 = *(undefined4 *)(iVar39 + 0x42c);
        uVar27 = *(undefined4 *)(iVar39 + 0x430);
        uVar35 = *(undefined4 *)(iVar39 + 0x434);
        uVar32 = *(undefined4 *)(iVar39 + 0x438);
        *(undefined4 *)(iVar47 + iVar36) = *(undefined4 *)(iVar39 + 0x400);
        *(undefined4 *)(iVar41 + 8) = uVar40;
        *(undefined4 *)(iVar41 + 4) = uVar34;
        *(undefined4 *)(iVar41 + 0x10) = uVar54;
        *(undefined4 *)(iVar41 + 0x14) = uVar31;
        *(undefined4 *)(iVar41 + 0xc) = uVar27;
        *(undefined4 *)(iVar41 + 0x18) = uVar33;
        *(undefined4 *)(iVar41 + 0x1c) = uVar35;
        *(undefined4 *)(iVar41 + 0x20) = uVar51;
        *(undefined4 *)(iVar41 + 0x24) = uVar53;
        *(undefined4 *)(iVar41 + 0x28) = uVar30;
        *(undefined4 *)(iVar41 + 0x2c) = uVar32;
        *(undefined4 *)(iVar41 + 0x30) = uVar49;
        *(undefined4 *)(iVar41 + 0x34) = uVar50;
        *(undefined4 *)(iVar41 + 0x38) = uVar52;
        *(undefined4 *)(iVar41 + 0x3c) = uVar48;
        uVar38 = piVar56[2];
        break;
      case 5:
        uVar58 = *(undefined8 *)(iVar46 + 0x24c0 + uVar55 * 0x80);
        uVar57 = *(undefined8 *)(iVar46 + 0x24c0 + uVar55 * 0x80 + 8);
        iVar36 = *(int *)(uVar55 * 0x3c + iVar44 + 0x58);
        goto LAB_0009fa50;
      case 6:
        iVar36 = iVar46 + 0x24c0 + uVar55 * 0x80;
        uVar58 = *(undefined8 *)(iVar36 + 0x10);
        uVar57 = *(undefined8 *)(iVar36 + 0x18);
        iVar36 = *(int *)(uVar55 * 0x3c + iVar44 + 0x5c);
        goto LAB_0009fa50;
      case 7:
        iVar36 = iVar46 + 0x24c0 + uVar55 * 0x80;
        uVar58 = *(undefined8 *)(iVar36 + 0x20);
        uVar57 = *(undefined8 *)(iVar36 + 0x28);
        iVar36 = *(int *)(uVar55 * 0x3c + iVar44 + 0x68);
        goto LAB_0009fa50;
      case 8:
        if ((*(char *)(iVar29 + 0x12f) != '\0') && ((*(uint *)(iVar46 + 0x24ac) & 0xffff00) != 0)) {
          if (*(char *)(iVar46 + 0x24ad) == '\0') {
            if (*(char *)(iVar46 + 0x24ae) != '\0') {
              fStack_164 = *(float *)(iVar46 + 0x24a4);
              iVar36 = uVar55 * 0x10 + iVar29;
              local_160 = fStack_164 * *(float *)(iVar36 + 0x2a0);
              local_168 = fStack_164 * *(float *)(iVar36 + 0x298);
              fStack_164 = fStack_164 * *(float *)(iVar36 + 0x29c);
            }
          }
          else {
            (**(code **)(((unsigned char *)0x00001348) + iVar29))(&local_168,uVar55 * 0x10 + iVar29 + 0x298);
          }
          uStack_15c = 0x3f800000;
          iVar36 = *(int *)(uVar55 * 0x3c + iVar44 + 0x78);
          goto LAB_0009fb60;
        }
        iVar36 = iVar29 + uVar55 * 0x10 + 0x290;
        uVar58 = *(undefined8 *)(iVar36 + 8);
        uVar57 = *(undefined8 *)(iVar36 + 0x10);
        iVar36 = *(int *)(uVar55 * 0x3c + iVar44 + 0x78);
        goto LAB_0009fa50;
      case 9:
        if ((*(char *)(iVar29 + 0x12f) != '\0') && ((*(uint *)(iVar46 + 0x24ac) & 0xffff00) != 0)) {
          if (*(char *)(iVar46 + 0x24ad) == '\0') {
            if (*(char *)(iVar46 + 0x24ae) != '\0') {
              fStack_164 = *(float *)(iVar46 + 0x24a4);
              iVar36 = uVar55 * 0x10 + iVar29;
              local_160 = fStack_164 * *(float *)(iVar36 + 800);
              local_168 = fStack_164 * *(float *)(iVar36 + 0x318);
              fStack_164 = fStack_164 * *(float *)(iVar36 + 0x31c);
            }
          }
          else {
            (**(code **)(((unsigned char *)0x00001348) + iVar29))(&local_168,uVar55 * 0x10 + iVar29 + 0x318);
          }
          uStack_15c = 0x3f800000;
          iVar36 = *(int *)(uVar55 * 0x3c + iVar44 + 0x7c);
          goto LAB_0009fb60;
        }
        iVar36 = iVar29 + uVar55 * 0x10 + 0x310;
        uVar58 = *(undefined8 *)(iVar36 + 8);
        uVar57 = *(undefined8 *)(iVar36 + 0x10);
        iVar36 = *(int *)(uVar55 * 0x3c + iVar44 + 0x7c);
        goto LAB_0009fa50;
      case 10:
        iVar36 = iVar46 + 0x24c0 + uVar55 * 0x80;
        local_168 = *(float *)(iVar36 + 0x58);
        fStack_164 = *(float *)(iVar36 + 0x54);
        local_160 = *(float *)(iVar36 + 0x50);
        uStack_15c = 0;
        iVar36 = *(int *)(uVar55 * 0x3c + iVar44 + 0x80);
        goto LAB_0009fb60;
      case 0xb:
        iVar41 = iVar29 + uVar55 * 0x6c;
        iVar36 = *(int *)(uVar55 * 0x3c + iVar44 + 0x84) * 0x10;
        *(undefined4 *)(iVar47 + iVar36) = *(undefined4 *)(((unsigned char *)0x00001500) + iVar41 + 4);
        iVar36 = iVar47 + iVar36;
        *(undefined4 *)(iVar36 + 4) = *(undefined4 *)(((unsigned char *)0x00001500) + iVar41 + 4);
        *(undefined4 *)(iVar36 + 8) = *(undefined4 *)(((unsigned char *)0x00001500) + iVar41 + 4);
        *(undefined4 *)(iVar36 + 0xc) = *(undefined4 *)(((unsigned char *)0x00001500) + iVar41 + 4);
        uVar38 = piVar56[2];
        break;
      case 0xc:
        iVar41 = iVar29 + uVar55 * 0x6c;
        iVar36 = *(int *)(uVar55 * 0x3c + iVar44 + 0x88) * 0x10;
        *(undefined4 *)(iVar47 + iVar36) = *(undefined4 *)(((unsigned char *)0x00001500) + iVar41 + 8);
        iVar36 = iVar47 + iVar36;
        *(undefined4 *)(iVar36 + 4) = *(undefined4 *)(((unsigned char *)0x00001500) + iVar41 + 8);
        *(undefined4 *)(iVar36 + 8) = *(undefined4 *)(((unsigned char *)0x00001500) + iVar41 + 8);
        *(undefined4 *)(iVar36 + 0xc) = *(undefined4 *)(((unsigned char *)0x00001500) + iVar41 + 8);
        uVar38 = piVar56[2];
        break;
      case 0xd:
        iVar41 = iVar46 + 0x24c0 + uVar55 * 0x80;
        iVar36 = *(int *)(uVar55 * 0x3c + iVar44 + 0x8c) * 0x10;
        *(undefined4 *)(iVar47 + iVar36) = *(undefined4 *)(iVar41 + 0x5c);
        iVar36 = iVar47 + iVar36;
        *(undefined4 *)(iVar36 + 4) = *(undefined4 *)(iVar41 + 0x5c);
        *(undefined4 *)(iVar36 + 8) = *(undefined4 *)(iVar41 + 0x5c);
        *(undefined4 *)(iVar36 + 0xc) = *(undefined4 *)(iVar41 + 0x5c);
        uVar38 = piVar56[2];
        break;
      case 0xe:
        if (uVar55 == 0) {
          uVar57 = *(undefined8 *)(iVar46 + 0x28f8);
          uVar58 = *(undefined8 *)(iVar46 + 0x28f0);
          iVar36 = *(int *)(iVar28 + 0x2d8);
        }
        else {
          uVar57 = *(undefined8 *)(((unsigned char *)0x00002b38) + iVar46);
          uVar58 = *(undefined8 *)(((unsigned char *)0x00002b30) + iVar46);
          iVar36 = *(int *)(uVar55 * 0x24 + iVar44 + 0x234);
        }
        goto LAB_0009fa50;
      case 0xf:
        if (uVar55 == 0) {
          uVar57 = *(undefined8 *)(iVar46 + 0x28c8);
          uVar58 = *(undefined8 *)(iVar46 + 0x28c0);
          iVar36 = *(int *)(iVar28 + 0x2dc);
        }
        else {
          uVar57 = *(undefined8 *)(((unsigned char *)0x00002b08) + iVar46);
          uVar58 = *(undefined8 *)(((unsigned char *)0x00002b00) + iVar46);
          iVar36 = *(int *)(uVar55 * 0x24 + iVar44 + 0x238);
        }
        goto LAB_0009fa50;
      case 0x10:
        if (uVar55 == 0) {
          uVar57 = *(undefined8 *)(iVar46 + 0x28d8);
          uVar58 = *(undefined8 *)(iVar46 + 0x28d0);
          iVar36 = *(int *)(iVar28 + 0x2e0);
        }
        else {
          uVar57 = *(undefined8 *)(((unsigned char *)0x00002b18) + iVar46);
          uVar58 = *(undefined8 *)(((unsigned char *)0x00002b10) + iVar46);
          iVar36 = *(int *)(uVar55 * 0x24 + iVar44 + 0x23c);
        }
        goto LAB_0009fa50;
      case 0x11:
        if (uVar55 == 0) {
          uVar57 = *(undefined8 *)(iVar46 + 0x28e8);
          uVar58 = *(undefined8 *)(iVar46 + 0x28e0);
          iVar36 = *(int *)(iVar28 + 0x2ec);
        }
        else {
          uVar57 = *(undefined8 *)(((unsigned char *)0x00002b28) + iVar46);
          uVar58 = *(undefined8 *)(((unsigned char *)0x00002b20) + iVar46);
          iVar36 = *(int *)(uVar55 * 0x24 + iVar44 + 0x248);
        }
        goto LAB_0009fa50;
      case 0x12:
        if (uVar55 == 0) {
          local_168 = *(float *)(iVar46 + 0x28c0) * *(float *)(iVar46 + 0x24b0) +
                      *(float *)(iVar46 + 0x28f0);
          fStack_164 = *(float *)(iVar46 + 0x28c4) * *(float *)(iVar46 + 0x24b4) +
                       *(float *)(iVar46 + 0x28f4);
          local_160 = *(float *)(iVar46 + 0x28c8) * *(float *)(iVar46 + 0x24b8) +
                      *(float *)(iVar46 + 0x28f8);
        }
        else {
          local_168 = *(float *)(((unsigned char *)0x00002b00) + iVar46) * *(float *)(iVar46 + 0x24b0) +
                      *(float *)(((unsigned char *)0x00002b30) + iVar46);
          fStack_164 = *(float *)(((unsigned char *)0x00002b04) + iVar46) * *(float *)(iVar46 + 0x24b4) +
                       *(float *)(((unsigned char *)0x00002b34) + iVar46);
          local_160 = *(float *)(((unsigned char *)0x00002b08) + iVar46) * *(float *)(iVar46 + 0x24b8) +
                      *(float *)(((unsigned char *)0x00002b38) + iVar46);
        }
        iVar36 = *(int *)(uVar55 * 0x24 + iVar44 + 0x254) * 0x10;
        *(ulonglong *)(iVar47 + iVar36) = CONCAT44(local_168,fStack_164);
        *(ulonglong *)(iVar47 + iVar36 + 8) = CONCAT44(local_160,uStack_15c);
        uVar38 = piVar56[2];
        break;
      case 0x13:
        if (uVar55 == 0) {
          iVar36 = *(int *)(iVar28 + 800) * 0x10;
          *(undefined4 *)(iVar47 + iVar36) = *(undefined4 *)(iVar46 + 0x2900);
          iVar36 = iVar47 + iVar36;
          *(undefined4 *)(iVar36 + 4) = *(undefined4 *)(iVar46 + 0x2900);
          *(undefined4 *)(iVar36 + 8) = *(undefined4 *)(iVar46 + 0x2900);
          *(undefined4 *)(iVar36 + 0xc) = *(undefined4 *)(iVar46 + 0x2900);
          uVar38 = piVar56[2];
        }
        else {
          iVar36 = *(int *)(uVar55 * 4 + iVar44 + 0x27c) * 0x10;
          *(undefined4 *)(iVar47 + iVar36) = *(undefined4 *)(((unsigned char *)0x00002b40) + iVar46);
          iVar36 = iVar47 + iVar36;
          *(undefined4 *)(iVar36 + 4) = *(undefined4 *)(((unsigned char *)0x00002b40) + iVar46);
          *(undefined4 *)(iVar36 + 8) = *(undefined4 *)(((unsigned char *)0x00002b40) + iVar46);
          *(undefined4 *)(iVar36 + 0xc) = *(undefined4 *)(((unsigned char *)0x00002b40) + iVar46);
          uVar38 = piVar56[2];
        }
        break;
      case 0x14:
        uVar57 = *(undefined8 *)(iVar46 + 0x24b8);
        uVar58 = *(undefined8 *)(iVar46 + 0x24b0);
        iVar36 = *(int *)(iVar28 + 0x328);
        goto LAB_0009fa50;
      case 0x15:
        fStack_164 = *(float *)(iVar29 + 0x134);
        local_160 = *(float *)(iVar29 + 0x138);
        uStack_15c = 0;
        local_168 = 0.0;
        iVar36 = *(int *)(iVar28 + 0x330);
        goto LAB_0009fb60;
      case 0x16:
        local_168 = *(float *)(iVar29 + 400);
        fStack_164 = *(float *)(iVar29 + 0x194);
        local_160 = *(float *)(iVar29 + 0xf0);
        uStack_15c = *(undefined4 *)(iVar29 + 0x198);
        iVar36 = *(int *)(iVar28 + 0x334);
        goto LAB_0009fb60;
      case 0x17:
        local_168 = *(float *)(iVar29 + 0x118);
        fStack_164 = *(float *)(iVar29 + 0x114);
        local_160 = *(float *)(iVar29 + 0x110);
        uStack_15c = 0;
        iVar36 = *(int *)(iVar28 + 0x338) * 0x10;
        *(ulonglong *)(iVar47 + iVar36) = CONCAT44(local_168,fStack_164);
        *(ulonglong *)(iVar47 + iVar36 + 8) = (ulonglong)(uint)local_160 << 0x20;
        uVar38 = piVar56[2];
        break;
      case 0x18:
        if ((*(uint *)(iVar29 + 0x44) & 0x40000000) == 0) {
          local_110 = 0x43300000;
          local_118 = 0x43300000;
          uStack_114 = *(uint *)(iVar29 + 0x108) ^ 0x80000000;
          uStack_10c = *(uint *)(iVar29 + 0x10c) ^ 0x80000000;
          local_168 = (float)((double)CONCAT44(0x43300000,uStack_114) - DOUBLE_001aa1e0);
          fStack_164 = (float)((double)CONCAT44(0x43300000,uStack_10c) - DOUBLE_001aa1e0);
        }
        else {
          local_168 = *(float *)(iVar29 + 0x100);
          fStack_164 = *(float *)(iVar29 + 0x104);
        }
        uStack_15c = 0;
        local_160 = 0.0;
        iVar36 = *(int *)(iVar28 + 0x340);
        goto LAB_0009fb60;
      case 0x19:
        iVar36 = *(int *)(iVar28 + 0x344) * 0x10;
        *(undefined4 *)(iVar47 + iVar36) = *(undefined4 *)(iVar46 + 0x24a4);
        iVar36 = iVar47 + iVar36;
        *(undefined4 *)(iVar36 + 4) = *(undefined4 *)(iVar46 + 0x24a4);
        *(undefined4 *)(iVar36 + 8) = *(undefined4 *)(iVar46 + 0x24a4);
        *(undefined4 *)(iVar36 + 0xc) = *(undefined4 *)(iVar46 + 0x24a4);
        uVar38 = piVar56[2];
        break;
      case 0x1a:
        uVar21 = uVar55 & 3;
        uVar38 = uVar55 >> 2;
        if (uVar21 == 1) {
          iVar36 = uVar38 * 0xcc + iVar29;
          if (*(short *)(iVar36 + 0x4b0) == 0x2401) {
            puVar37 = (undefined8 *)(iVar36 + 0x4c4);
          }
          else {
            puVar37 = (undefined8 *)(uVar38 * 0xcc + iVar29 + 0x4b4);
          }
        }
        else if (uVar21 == 0) {
          iVar36 = uVar38 * 0xcc + iVar29;
          if (*(short *)(iVar36 + 0x48c) == 0x2401) {
            puVar37 = (undefined8 *)(iVar36 + 0x4a0);
          }
          else {
            puVar37 = (undefined8 *)(uVar38 * 0xcc + iVar29 + 0x490);
          }
        }
        else if (uVar21 == 2) {
          iVar36 = uVar38 * 0xcc + iVar29;
          if (*(short *)(iVar36 + 0x4d4) == 0x2401) {
            puVar37 = (undefined8 *)(iVar36 + 0x4e8);
          }
          else {
            puVar37 = (undefined8 *)(uVar38 * 0xcc + iVar29 + 0x4d8);
          }
        }
        else {
          puVar37 = (undefined8 *)0x0;
          if (uVar21 == 3) {
            iVar36 = uVar38 * 0xcc + iVar29;
            if (*(short *)(iVar36 + 0x4f8) == 0x2401) {
              puVar37 = (undefined8 *)(iVar36 + 0x50c);
            }
            else {
              puVar37 = (undefined8 *)(uVar38 * 0xcc + iVar29 + 0x4fc);
            }
          }
        }
        uVar58 = puVar37[1];
        iVar36 = *(int *)(uVar55 * 4 + iVar44 + 0x2a4) * 0x10;
        *(undefined8 *)(iVar47 + iVar36) = *puVar37;
        *(undefined8 *)(iVar47 + iVar36 + 8) = uVar58;
        uVar38 = piVar56[2];
        break;
      case 0x1b:
        uVar57 = *(undefined8 *)(iVar29 + 0x3a0);
        uVar58 = *(undefined8 *)(iVar29 + 0x398);
        iVar36 = *(int *)(iVar28 + 0x32c);
LAB_0009fa50:
        *(undefined8 *)(iVar47 + iVar36 * 0x10) = uVar58;
        *(undefined8 *)(iVar47 + iVar36 * 0x10 + 8) = uVar57;
        uVar38 = piVar56[2];
        break;
      case 0x1c:
        iVar36 = iVar46 + 0x24c0 + (uVar55 >> 1) * 0x80;
        iVar41 = (uVar55 & 1) * 0x240 + iVar46;
        local_168 = *(float *)(iVar36 + 0x10) * *(float *)(iVar41 + 0x28d0);
        fStack_164 = *(float *)(iVar36 + 0x14) * *(float *)(iVar41 + 0x28d4);
        local_160 = *(float *)(iVar36 + 0x18) * *(float *)(iVar41 + 0x28d8);
        uStack_15c = *(undefined4 *)(iVar41 + 0x28dc);
        iVar36 = *(int *)(((uVar55 >> 1) * 0xf + (uVar55 & 1)) * 4 + iVar44 + 0x60);
        goto LAB_0009fb60;
      case 0x1d:
        iVar36 = iVar46 + 0x24c0 + (uVar55 >> 1) * 0x80;
        iVar41 = (uVar55 & 1) * 0x240 + iVar46;
        local_168 = *(float *)(iVar36 + 0x20) * *(float *)(iVar41 + 0x28e0);
        fStack_164 = *(float *)(iVar36 + 0x24) * *(float *)(iVar41 + 0x28e4);
        uStack_15c = 0x3f800000;
        local_160 = *(float *)(iVar36 + 0x28) * *(float *)(iVar41 + 0x28e8);
        iVar36 = *(int *)(((uVar55 >> 1) * 0xf + (uVar55 & 1)) * 4 + iVar44 + 0x6c);
LAB_0009fb60:
        *(ulonglong *)(iVar47 + iVar36 * 0x10) = CONCAT44(local_168,fStack_164);
        *(ulonglong *)(iVar47 + iVar36 * 0x10 + 8) = CONCAT44(local_160,uStack_15c);
        uVar38 = piVar56[2];
      }
      uVar43 = uVar43 + 1;
      iVar45 = iVar45 + 4;
    } while (uVar43 < uVar38);
  }
  FUN_001a327c();
  return;
}

/* FUN_000a0290 @ 0xa0290 (96 bytes) */
int FUN_000a0290(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  if (param_3 != 0) {
    uVar2 = 3;
    iVar3 = 0x48;
    bVar1 = true;
    while (uVar2 < *(uint *)(param_2 + 4)) {
      if (!bVar1) {
        return uVar2;
      }
      if (param_3 == *(int *)(iVar3 + *(int *)(param_2 + 8))) {
        bVar1 = false;
      }
      else {
        uVar2 = uVar2 + 1;
        iVar3 = iVar3 + 0x18;
      }
    }
    if (!bVar1) {
      return uVar2;
    }
  }
  return 0;
}

/* FUN_000a0300 @ 0xa0300 (80 bytes) */
int FUN_000a0300(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
{
  *(undefined4 *)(((unsigned char *)0x00001124) + param_1) = 0xffffffff;
  **(undefined1 **)(((unsigned char *)0x00001128) + param_1) = 0;
  if (param_4 < 1) {
    return;
  }
  if (param_3 != 0x8875) {
    return;
  }
  if (param_2 != 0x8804) {
    return;
  }
  FUN_0008df50(param_1,0x8875,param_4,param_5);
  return;
}

/* FUN_000a0350 @ 0xa0350 (36 bytes) */
int FUN_000a0350(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  param_2[5] = 0;
  param_2[3] = 0xffffffff;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[4] = 0;
  return;
}

/* FUN_000a0380 @ 0xa0380 (476 bytes) */
int FUN_000a0380(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if ((param_2 == 0x8620) || (param_2 == 0x8804)) {
    iVar5 = *(int *)(((unsigned char *)0x0000112c) + param_1);
    iVar2 = ((int (*)())FUN_000a0290)(param_1,iVar5);
    if (iVar2 == 0) {
      if (param_3 != 0) {
        uVar1 = *(uint *)(iVar5 + 4);
        if ((uVar1 & 7) == 0) {
          iVar2 = (**(code **)(param_1 + 0xc))(uVar1 * 0x18 + 0xc0);
          if (iVar2 == 0) {
            return;
          }
          (**(code **)(((unsigned char *)0x00001344) + param_1))
                    (iVar2,*(undefined4 *)(iVar5 + 8),*(int *)(iVar5 + 4) * 0x18);
          (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar5 + 8));
          *(int *)(iVar5 + 8) = iVar2;
          uVar1 = *(uint *)(iVar5 + 4);
        }
        ((int (*)())FUN_000a0350)(param_1,uVar1 * 0x18 + *(int *)(iVar5 + 8));
        *(int *)(*(int *)(iVar5 + 4) * 0x18 + *(int *)(iVar5 + 8) + 4) = param_2;
        *(int *)(*(int *)(iVar5 + 4) * 0x18 + *(int *)(iVar5 + 8)) = param_3;
        if (param_2 == 0x8804) {
          iVar2 = *(int *)(iVar5 + 4);
          iVar4 = *(int *)(iVar5 + 8);
          uVar3 = (**(code **)(param_1 + 0xc))(0x78);
          *(undefined4 *)(iVar2 * 0x18 + iVar4 + 0x14) = uVar3;
          FUN_0008dc50(param_1,*(undefined4 *)
                                (*(int *)(iVar5 + 4) * 0x18 + *(int *)(iVar5 + 8) + 0x14));
          FUN_0008dbd0(param_1,*(undefined4 *)(iVar5 + 4));
        }
        *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + 1;
        return;
      }
    }
    else if (param_2 != *(int *)(iVar2 * 0x18 + *(int *)(iVar5 + 8) + 4)) {
      return;
    }
    if (param_2 == 0x8804) {
      if (iVar2 == 0) {
        iVar2 = *(int *)(((unsigned char *)0x0000126c) + param_1);
      }
      FUN_0008dbd0(param_1,iVar2);
      return;
    }
  }
  return;
}

/* FUN_000a0570 @ 0xa0570 (124 bytes) */
int FUN_000a0570(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  if (0 < param_2) {
    piVar3 = *(int **)(((unsigned char *)0x0000112c) + param_1);
    iVar2 = 0;
    iVar4 = *piVar3;
    do {
      while (iVar1 = ((int (*)())FUN_000a0290)(param_1,piVar3,iVar4), iVar1 != 0) {
        iVar4 = iVar4 + 1;
      }
      iVar1 = iVar2 * 4;
      iVar2 = iVar2 + 1;
      *(int *)(param_3 + iVar1) = iVar4;
      iVar4 = iVar4 + 1;
    } while (param_2 != iVar2);
    *piVar3 = iVar4;
  }
  return;
}

/* FUN_000a05f0 @ 0xa05f0 (704 bytes) */
int FUN_000a05f0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint *param_4;
{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0x8620) {
    iVar2 = *(int *)(((unsigned char *)0x000014a0) + param_1);
  }
  else {
    if (param_2 != 0x8804) {
      return;
    }
    iVar2 = *(int *)(((unsigned char *)0x00001270) + param_1);
  }
  iVar1 = *(int *)(((unsigned char *)0x0000112c) + param_1);
  if (param_3 == 0x8627) {
    *param_4 = *(uint *)(iVar2 * 0x18 + *(int *)(iVar1 + 8) + 0xc);
    return;
  }
  if (param_3 == 0x8876) {
    *param_4 = *(uint *)(iVar2 * 0x18 + *(int *)(iVar1 + 8) + 8);
    return;
  }
  if (param_3 != 0x8677) {
    if (param_2 == 0x8804) {
      iVar2 = *(int *)(iVar2 * 0x18 + *(int *)(iVar1 + 8) + 0x14);
      switch(param_3) {
      case 0x8805:
        *param_4 = *(uint *)(*(int *)(iVar2 + 0x74) + 0x6c);
        return;
      case 0x8806:
        *param_4 = *(uint *)(*(int *)(iVar2 + 0x74) + 0x70);
        return;
      case 0x8807:
        *param_4 = *(uint *)(*(int *)(iVar2 + 0x74) + 0x74);
        return;
      case 0x8808:
        *param_4 = *(uint *)(iVar2 + 0x54);
        return;
      case 0x8809:
        *param_4 = *(uint *)(iVar2 + 0x58);
        return;
      case 0x880a:
        *param_4 = *(uint *)(iVar2 + 0x5c);
switchD_000a0718_caseD_8811:
        return;
      case 0x880b:
        *param_4 = *(uint *)(((unsigned char *)0x00001204) + param_1);
        return;
      case 0x880c:
        *param_4 = *(uint *)(((unsigned char *)0x00001208) + param_1);
        return;
      case 0x880d:
        *param_4 = *(uint *)((*(unsigned char *)0x0000120c) + param_1);
        return;
      case 0x880e:
        *param_4 = *(uint *)(((unsigned char *)0x00001210) + param_1);
        return;
      case 0x880f:
        *param_4 = *(uint *)(((unsigned char *)0x00001214) + param_1);
        return;
      case 0x8810:
        *param_4 = *(uint *)(((unsigned char *)0x00001218) + param_1);
        return;
      case 0x8811:
      case 0x8812:
      case 0x8813:
      case 0x8814:
      case 0x8815:
      case 0x8816:
      case 0x8817:
      case 0x8818:
      case 0x8819:
      case 0x881a:
      case 0x881b:
      case 0x881c:
      case 0x881d:
      case 0x881e:
      case 0x881f:
      case 0x8820:
      case 0x8821:
      case 0x8822:
      case 0x8823:
      case 0x8824:
      case 0x8825:
      case 0x8826:
      case 0x8827:
      case 0x8828:
      case 0x8829:
      case 0x882a:
      case 0x882b:
      case 0x882c:
      case 0x882d:
      case 0x882e:
      case 0x882f:
      case 0x8830:
      case 0x8831:
      case 0x8832:
      case 0x8833:
      case 0x8834:
      case 0x8835:
      case 0x8836:
      case 0x8837:
      case 0x8838:
      case 0x8839:
      case 0x883a:
      case 0x883b:
      case 0x883c:
      case 0x883d:
      case 0x883e:
      case 0x883f:
      case 0x8840:
      case 0x8841:
      case 0x8842:
      case 0x8843:
      case 0x8844:
      case 0x8845:
      case 0x8846:
      case 0x8847:
      case 0x8848:
      case 0x8849:
      case 0x884a:
      case 0x884b:
      case 0x884c:
      case 0x884d:
      case 0x884e:
      case 0x884f:
      case 0x8850:
      case 0x8851:
      case 0x8852:
      case 0x8853:
      case 0x8854:
      case 0x8855:
      case 0x8856:
      case 0x8857:
      case 0x8858:
      case 0x8859:
      case 0x885a:
      case 0x885b:
      case 0x885c:
      case 0x885d:
      case 0x885e:
      case 0x885f:
      case 0x8860:
      case 0x8861:
      case 0x8862:
      case 0x8863:
      case 0x8864:
      case 0x8865:
      case 0x8866:
      case 0x8867:
      case 0x8868:
      case 0x8869:
      case 0x886a:
      case 0x886b:
      case 0x886c:
      case 0x886d:
      case 0x886e:
      case 0x886f:
      case 0x8870:
      case 0x8871:
      case 0x8872:
      case 0x8873:
      case 0x8874:
      case 0x8875:
      case 0x8876:
      case 0x8877:
      case 0x8878:
      case 0x8879:
      case 0x887a:
      case 0x887b:
      case 0x887c:
      case 0x887d:
      case 0x887e:
      case 0x887f:
      case 0x8880:
      case 0x8881:
      case 0x8882:
      case 0x8883:
      case 0x8884:
      case 0x8885:
      case 0x8886:
      case 0x8887:
      case 0x8888:
      case 0x8889:
      case 0x888a:
      case 0x888b:
      case 0x888c:
      case 0x888d:
      case 0x888e:
      case 0x888f:
      case 0x8890:
      case 0x8891:
      case 0x8892:
      case 0x8893:
      case 0x8894:
      case 0x8895:
      case 0x8896:
      case 0x8897:
      case 0x8898:
      case 0x8899:
      case 0x889a:
      case 0x889b:
      case 0x889c:
      case 0x889d:
      case 0x889e:
      case 0x889f:
        goto switchD_000a0718_caseD_8811;
      case 0x88a0:
        *param_4 = *(uint *)(*(int *)(iVar2 + 0x74) + 0x68);
        return;
      case 0x88a1:
        *param_4 = *(uint *)(((unsigned char *)0x000011d4) + param_1);
        return;
      case 0x88a2:
        *param_4 = *(uint *)(iVar2 + 0x50);
        return;
      case 0x88a3:
        *param_4 = *(uint *)(((unsigned char *)0x000011d8) + param_1);
        return;
      case 0x88a4:
        *param_4 = *(uint *)(*(int *)(iVar2 + 0x74) + 0x88);
        return;
      case 0x88a5:
        *param_4 = *(uint *)(((unsigned char *)0x000011dc) + param_1);
        return;
      case 0x88a6:
        *param_4 = *(uint *)(iVar2 + 0x68);
        return;
      case 0x88a7:
        *param_4 = *(uint *)(((unsigned char *)0x000011e0) + param_1);
        return;
      case 0x88a8:
        *param_4 = *(uint *)(*(int *)(iVar2 + 0x74) + 0x84);
        return;
      case 0x88a9:
        *param_4 = *(uint *)(((unsigned char *)0x000011e4) + param_1);
        return;
      case 0x88aa:
        *param_4 = *(uint *)(iVar2 + 100);
        return;
      case 0x88ab:
        *param_4 = *(uint *)(((unsigned char *)0x000011e8) + param_1);
        return;
      case 0x88ac:
        *param_4 = *(uint *)(*(int *)(iVar2 + 0x74) + 0x7c);
        return;
      case 0x88ad:
        *param_4 = *(uint *)(((unsigned char *)0x000011ec) + param_1);
        return;
      case 0x88ae:
        *param_4 = *(uint *)(iVar2 + 0x60);
        return;
      case 0x88af:
        *param_4 = *(uint *)(((unsigned char *)0x000011f0) + param_1);
        return;
      case 0x88b0:
      case 0x88b2:
        *param_4 = 0;
        return;
      case 0x88b1:
        *param_4 = *(uint *)(((unsigned char *)0x000011f4) + param_1);
        return;
      case 0x88b3:
        *param_4 = *(uint *)(((unsigned char *)0x000011f8) + param_1);
        return;
      case 0x88b4:
        *param_4 = *(uint *)(((unsigned char *)0x000011fc) + param_1);
        return;
      case 0x88b5:
        *param_4 = *(uint *)(((unsigned char *)0x00001200) + param_1);
        return;
      case 0x88b6:
        *param_4 = (uint)*(byte *)(iVar2 + 0x6c);
        return;
      default:
        return;
      }
    }
    return;
  }
  *param_4 = *(uint *)(iVar2 * 0x18 + *(int *)(iVar1 + 8));
  return;
}

/* FUN_000a0ba0 @ 0xa0ba0 (188 bytes) */
int FUN_000a0ba0(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  int iVar1;
  
  iVar1 = param_2[5];
  if (iVar1 != 0) {
    if (param_2[1] == 0x8804) {
      FUN_0008dda0();
      iVar1 = param_2[5];
    }
    (**(code **)(param_1 + 0x18))(iVar1);
    param_2[5] = 0;
  }
  if (param_2[4] != 0) {
    (**(code **)(param_1 + 0x18))();
    param_2[4] = 0;
  }
  param_2[2] = 0;
  param_2[3] = 0xffffffff;
  *param_2 = 0;
  param_2[1] = 0;
  return;
}

/* FUN_000a0c60 @ 0xa0c60 (260 bytes) */
int FUN_000a0c60(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  FUN_0008dc40();
  if (*(int *)(((unsigned char *)0x00001128) + param_1) != 0) {
    (**(code **)(param_1 + 0x18))();
    *(undefined4 *)(((unsigned char *)0x00001128) + param_1) = 0;
  }
  *(int *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 0xc) =
       *(int *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 0xc) + -1;
  if (*(int *)(*(int *)(((unsigned char *)0x0000112c) + param_1) + 0xc) == 0) {
    iVar4 = *(int *)(((unsigned char *)0x0000112c) + param_1);
    if (*(int *)(iVar4 + 4) != 0) {
      uVar2 = 0;
      iVar3 = 0;
      do {
        uVar2 = uVar2 + 1;
        iVar1 = iVar3 + *(int *)(iVar4 + 8);
        iVar3 = iVar3 + 0x18;
        ((int (*)())FUN_000a0ba0)(param_1,iVar1);
      } while (uVar2 < *(uint *)(iVar4 + 4));
    }
    *(undefined4 *)(iVar4 + 4) = 0;
    if (*(int *)(iVar4 + 8) != 0) {
      (**(code **)(param_1 + 0x18))();
      *(undefined4 *)(iVar4 + 8) = 0;
    }
    (**(code **)(param_1 + 0x18))(iVar4);
    *(undefined4 *)(((unsigned char *)0x0000112c) + param_1) = 0;
  }
  return;
}

/* FUN_000a0d70 @ 0xa0d70 (372 bytes) */
int FUN_000a0d70(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if (0 < param_2) {
    iVar6 = *(int *)(((unsigned char *)0x0000112c) + param_1);
    iVar4 = 0;
    do {
      uVar1 = ((int (*)())FUN_000a0290)(param_1,iVar6,*param_3);
      if (uVar1 != 0) {
        iVar3 = *(int *)(iVar6 + 8);
        iVar5 = uVar1 * 0x18;
        if ((*(int *)(iVar3 + iVar5 + 4) == 0x8804) &&
           (*(int *)(*(int *)(((unsigned char *)0x00001270) + param_1) * 0x18 + iVar3) == *param_3)) {
          ((int (*)())FUN_000a0380)(param_1,0x8804,0);
          iVar3 = *(int *)(iVar6 + 8);
        }
        ((int (*)())FUN_000a0ba0)(param_1,iVar5 + iVar3);
        pvVar2 = (void *)(iVar5 + *(int *)(iVar6 + 8));
        _memmove(pvVar2,(void *)((int)pvVar2 + 0x18),(*(int *)(iVar6 + 4) - uVar1) * 0x18 - 0x18);
        iVar3 = *(int *)(iVar6 + 4) + -1;
        *(int *)(iVar6 + 4) = iVar3;
        *(undefined4 *)(iVar3 * 0x18 + *(int *)(iVar6 + 8) + 8) = 0;
        *(undefined4 *)(*(int *)(iVar6 + 4) * 0x18 + *(int *)(iVar6 + 8)) = 0;
        *(undefined4 *)(*(int *)(iVar6 + 4) * 0x18 + *(int *)(iVar6 + 8) + 0xc) = 0xffffffff;
        *(undefined4 *)(*(int *)(iVar6 + 4) * 0x18 + *(int *)(iVar6 + 8) + 0x10) = 0;
        *(undefined4 *)(*(int *)(iVar6 + 4) * 0x18 + *(int *)(iVar6 + 8) + 4) = 0;
        *(undefined4 *)(*(int *)(iVar6 + 4) * 0x18 + *(int *)(iVar6 + 8) + 0x14) = 0;
        if (uVar1 < *(uint *)(((unsigned char *)0x00001270) + param_1)) {
          *(uint *)(((unsigned char *)0x00001270) + param_1) = *(uint *)(((unsigned char *)0x00001270) + param_1) - 1;
        }
      }
      iVar4 = iVar4 + 1;
      param_3 = param_3 + 1;
    } while (param_2 != iVar4);
  }
  return;
}

/* FUN_000a0ef0 @ 0xa0ef0 (144 bytes) */
int FUN_000a0ef0(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(((unsigned char *)0x0000112c) + param_1);
  puVar3[3] = 1;
  *puVar3 = 1;
  puVar3[4] = 1;
  puVar3[1] = 3;
  uVar1 = (**(code **)(param_1 + 0xc))(0xc0);
  puVar3[2] = uVar1;
  *(undefined4 *)(((unsigned char *)0x00001124) + param_1) = 0xffffffff;
  puVar2 = (undefined1 *)(**(code **)(param_1 + 0xc))(1);
  *(undefined1 **)(((unsigned char *)0x00001128) + param_1) = puVar2;
  *puVar2 = 0;
  *(undefined4 *)(((unsigned char *)0x00001130) + param_1) = 0;
  FUN_0008f520(param_1);
  return;
}

/* FUN_000a0f90 @ 0xa0f90 (152 bytes) */
int FUN_000a0f90(param_1)
  int param_1;
{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  puVar2 = PTR_FUN_001e89f0;
  *(undefined **)(((unsigned char *)0x00001160) + param_1) = ((unsigned char *)0x000a0f80);
  *(undefined **)(((unsigned char *)0x0000115c) + param_1) = ((unsigned char *)0x000a0f80);
  *(undefined **)(((unsigned char *)0x00001164) + param_1) = puVar2;
  ((int (*)())FUN_000a21d0)();
  uVar5 = *(uint *)(param_1 + 0x27bc);
  uVar4 = 0;
  iVar6 = 0x10;
  iVar3 = param_1;
  do {
    uVar1 = uVar4 & 0x3f;
    *(undefined4 *)(iVar3 + 0x27c0) = 0xff;
    uVar4 = uVar4 + 1;
    iVar3 = iVar3 + 4;
    uVar5 = 1 << uVar1 | uVar5;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  *(uint *)(param_1 + 0x27bc) = uVar5;
  return 1;
}

/* FUN_000a1090 @ 0xa1090 (200 bytes) */
int FUN_000a1090(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int *param_3;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = 0;
  iVar5 = 0x10;
  iVar3 = param_1;
  do {
    uVar1 = 0;
    if (*(char *)(param_2 + iVar4) != '\0') {
      uVar1 = 2;
      if ((*param_3 != 1) && (uVar1 = 1, *param_3 != 2)) {
        uVar1 = 8;
      }
    }
    *(undefined4 *)(iVar3 + 0x48) = uVar1;
    iVar4 = iVar4 + 1;
    param_3 = param_3 + 1;
    iVar3 = iVar3 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  iVar3 = *(int *)(((unsigned char *)0x00001154) + param_1);
  if (*(int *)(iVar3 + 4) != 0) {
    uVar2 = 0;
    iVar4 = 0;
    do {
      iVar5 = *(int *)(*(int *)(((unsigned char *)0x0000113c) + param_1) * 4 +
                      *(int *)(iVar4 + *(int *)(iVar3 + 0x88) + 0x70));
      if (iVar5 != 0) {
        *(undefined4 *)(((unsigned char *)0x000015cc) + iVar5) = 1;
        iVar3 = *(int *)(((unsigned char *)0x00001154) + param_1);
      }
      uVar2 = uVar2 + 1;
      iVar4 = iVar4 + 0x78;
    } while (uVar2 < *(uint *)(iVar3 + 4));
  }
  *(undefined4 *)(param_1 + 0x27bc) = 0;
  return;
}

/* FUN_000a11a0 @ 0xa11a0 (64 bytes) */
int FUN_000a11a0(param_1)
  int param_1;
{
  int iVar1;
  
  if (((param_1 != -0x1134) && (iVar1 = *(int *)(((unsigned char *)0x00001144) + param_1), iVar1 != 0)) &&
     (*(char *)(iVar1 + 0x74) != '\0')) {
    if (*(char *)(iVar1 + 0x6c) != '\0') {
      return 3;
    }
    return 1;
  }
  return 0;
}

/* FUN_000a11f0 @ 0xa11f0 (192 bytes) */
int FUN_000a11f0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  ((unsigned char *)0x00001135)[param_1] = 0;
  if (param_3 < 1) {
    return;
  }
  uVar1 = *(ushort *)(((unsigned char *)0x00001148) + param_1);
  iVar4 = 0;
  do {
    uVar6 = (uint)uVar1;
    if (uVar1 != 0) {
      iVar5 = 0;
      if ((uVar1 == 0) || (uVar6 == 0x80000000)) {
        uVar6 = 1;
      }
      do {
        iVar2 = (iVar5 + iVar4 * (uint)uVar1) * 0xc;
        if ((*(char *)(iVar2 + *(int *)(param_2 + 0xc)) != '\0') &&
           (uVar3 = *(int *)(iVar2 + *(int *)(param_2 + 0xc) + 8) - 0x84c0, uVar3 < 8)) {
          ((unsigned char *)0x00001135)[param_1] = (byte)(1 << (uVar3 & 0x3f)) | ((unsigned char *)0x00001135)[param_1];
        }
        iVar5 = iVar5 + 1;
        uVar6 = uVar6 - 1;
      } while (uVar6 != 0);
    }
    iVar4 = iVar4 + 1;
  } while (param_3 != iVar4);
  return;
}

/* FUN_000a12b0 @ 0xa12b0 (52 bytes) */
int FUN_000a12b0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if ((param_2 != 0) && (((unsigned char *)0x00001134)[param_1] == '\0')) {
    iVar1 = **(int **)(((unsigned char *)0x00001154) + param_1);
    **(int **)(((unsigned char *)0x00001154) + param_1) = param_2 + iVar1;
    return iVar1;
  }
  return 0;
}

/* FUN_000a12f0 @ 0xa12f0 (612 bytes) */
int FUN_000a12f0(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  if (((unsigned char *)0x00001134)[param_1] == '\0') {
    iVar7 = *(int *)(((unsigned char *)0x00001154) + param_1);
    uVar6 = 0;
    iVar4 = 0;
    uVar5 = *(uint *)(iVar7 + 4);
    bVar1 = true;
    iVar3 = 0;
    while (uVar6 < uVar5) {
      if (!bVar1) goto LAB_000a1378;
      if (param_2 == *(int *)(iVar3 + *(int *)(iVar7 + 0x88))) {
        bVar1 = false;
      }
      else {
        iVar4 = iVar4 + 0x78;
        uVar6 = uVar6 + 1;
        iVar3 = iVar4;
      }
    }
    if (bVar1) {
      if ((uVar5 & 7) == 0) {
        uVar2 = (**(code **)(param_1 + 0x10))(1,uVar5 * 0x78 + 0x3c0);
        (**(code **)(((unsigned char *)0x00001344) + param_1))
                  (uVar2,*(undefined4 *)(iVar7 + 0x88),*(int *)(iVar7 + 4) * 0x78);
        (**(code **)(param_1 + 0x18))(*(undefined4 *)(iVar7 + 0x88));
        *(undefined4 *)(iVar7 + 0x88) = uVar2;
        uVar5 = *(uint *)(iVar7 + 4);
      }
      ((int (*)())FUN_000a2920)(param_1,uVar5 * 0x78 + *(int *)(iVar7 + 0x88));
      *(int *)(*(int *)(iVar7 + 4) * 0x78 + *(int *)(iVar7 + 0x88)) = param_2;
      *(int *)(iVar7 + 4) = *(int *)(iVar7 + 4) + 1;
      *(uint *)(((unsigned char *)0x00001140) + param_1) = uVar6;
      uVar5 = *(uint *)(param_1 + 0x44);
      *(uint *)(param_1 + 0x44) = uVar5 & 0xffffbfff;
      if ((uVar5 & 0x32000) == 0x30000) {
        *(uint *)(param_1 + 0x44) = uVar5 & 0xfffebfff;
      }
      ((unsigned char *)0x00001136)[param_1] = 1;
    }
    else {
LAB_000a1378:
      iVar4 = *(int *)(iVar7 + 0x88);
      if (uVar6 != *(uint *)(((unsigned char *)0x00001140) + param_1)) {
        ((unsigned char *)0x00001136)[param_1] = 1;
      }
      *(uint *)(((unsigned char *)0x00001140) + param_1) = uVar6;
      if (*(char *)(iVar3 + iVar4 + 0x6c) == '\0') {
        uVar5 = *(uint *)(param_1 + 0x44);
        *(uint *)(param_1 + 0x44) = uVar5 & 0xffffbfff;
        if ((uVar5 & 0x32000) == 0x30000) {
          *(uint *)(param_1 + 0x44) = uVar5 & 0xfffebfff;
        }
      }
      else {
        uVar5 = *(uint *)(param_1 + 0x44);
        uVar6 = uVar5 >> 1 & 0x4000 | uVar5 & 0xffffbfff;
        *(uint *)(param_1 + 0x44) = uVar6;
        if ((uVar5 & 0x32000) == 0x20000) {
          *(uint *)(param_1 + 0x44) = uVar6 | 0x10000;
        }
      }
    }
    iVar3 = iVar3 + *(int *)(iVar7 + 0x88);
    *(int *)(((unsigned char *)0x00001144) + param_1) = iVar3;
    ((int (*)())FUN_000a11f0)(param_1,iVar3,*(undefined4 *)(iVar3 + 4));
    if ((*(uint *)(param_1 + 0x44) & 0x22000) == 0x20000) {
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2000;
      *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 3;
      *(undefined1 *)(param_1 + 0x29) = 1;
    }
  }
  return;
}

/* FUN_000a1570 @ 0xa1570 (312 bytes) */
int FUN_000a1570(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  int iVar5;
  
  if ((((unsigned char *)0x00001134)[param_1] == '\0') && (param_2 != 0)) {
    iVar5 = *(int *)(((unsigned char *)0x00001154) + param_1);
    if (param_2 == **(int **)(((unsigned char *)0x00001144) + param_1)) {
      ((int (*)())FUN_000a12f0)(param_1,0);
    }
    uVar3 = 0;
    iVar2 = 0;
    bVar1 = true;
    while (uVar3 < *(uint *)(iVar5 + 4)) {
      if (!bVar1) goto LAB_000a161c;
      if (param_2 == *(int *)(iVar2 + *(int *)(iVar5 + 0x88))) {
        bVar1 = false;
      }
      else {
        uVar3 = uVar3 + 1;
        iVar2 = iVar2 + 0x78;
      }
    }
    if (!bVar1) {
LAB_000a161c:
      ((int (*)())FUN_000a2bb0)(param_1,uVar3 * 0x78 + *(int *)(iVar5 + 0x88));
      pvVar4 = (void *)(uVar3 * 0x78 + *(int *)(iVar5 + 0x88));
      _memmove(pvVar4,(void *)((int)pvVar4 + 0x78),(*(int *)(iVar5 + 4) - uVar3) * 0x78 - 0x78);
      *(int *)(iVar5 + 4) = *(int *)(iVar5 + 4) + -1;
      if (uVar3 < *(uint *)(((unsigned char *)0x00001140) + param_1)) {
        iVar2 = *(uint *)(((unsigned char *)0x00001140) + param_1) - 1;
        *(int *)(((unsigned char *)0x00001140) + param_1) = iVar2;
        *(int *)(((unsigned char *)0x00001144) + param_1) = iVar2 * 0x78 + *(int *)(iVar5 + 0x88);
      }
    }
  }
  return;
}

/* FUN_000a16b0 @ 0xa16b0 (148 bytes) */
int FUN_000a16b0(param_1)
  int param_1;
{
  if (((unsigned char *)0x00001134)[param_1] == '\0') {
    ((unsigned char *)0x00001134)[param_1] = 1;
    ((int (*)())FUN_000a2bb0)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1));
    ((int (*)())FUN_000a2920)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1));
    if ((*(uint *)(param_1 + 0x44) & 0x22000) == 0x20000) {
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2000;
      *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 3;
    }
  }
  return;
}

/* FUN_000a1750 @ 0xa1750 (772 bytes) */
int FUN_000a1750(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  if (((unsigned char *)0x00001134)[param_1] == '\0') {
    return;
  }
  iVar13 = *(int *)(((unsigned char *)0x00001144) + param_1);
  if ((byte)((unsigned char *)0x00001138)[param_1] == 1) {
    bVar2 = false;
    iVar12 = 0;
    iVar7 = 0;
    iVar6 = 0;
    iVar11 = 0;
    iVar5 = 0;
    iVar3 = 0;
    iVar4 = 0;
    bVar1 = 0 < **(int **)(iVar13 + 0x14);
    while ((bVar1 || (iVar7 < **(int **)(iVar13 + 0x20)))) {
      if ((iVar6 < *(int *)(iVar13 + 0x18)) &&
         ((bVar1 && (iVar8 = iVar4 + *(int *)(iVar13 + 0x10), iVar5 == *(int *)(iVar8 + 0x44))))) {
        if (((*(int *)(iVar8 + 0x14) == 0x8577) ||
            (((*(int *)(iVar8 + 0x14) == 0x896d || (*(int *)(iVar8 + 0x24) == 0x8577)) ||
             (*(int *)(iVar8 + 0x24) == 0x896d)))) ||
           ((*(int *)(iVar8 + 0x34) == 0x8577 || (*(int *)(iVar8 + 0x34) == 0x896d)))) {
          bVar2 = true;
        }
        iVar12 = iVar12 + 1;
        iVar6 = iVar6 + 1;
        iVar4 = iVar4 + 0x4c;
        iVar5 = iVar5 + 1;
        bVar1 = iVar12 < **(int **)(iVar13 + 0x14);
      }
      if (((iVar11 < *(int *)(iVar13 + 0x24)) && (iVar7 < **(int **)(iVar13 + 0x20))) &&
         (iVar8 = iVar3 + *(int *)(iVar13 + 0x1c), iVar5 == *(int *)(iVar8 + 0x44))) {
        if (((((*(int *)(iVar8 + 0x14) == 0x8577) || (*(int *)(iVar8 + 0x14) == 0x896d)) ||
             (*(int *)(iVar8 + 0x24) == 0x8577)) ||
            ((*(int *)(iVar8 + 0x24) == 0x896d || (*(int *)(iVar8 + 0x34) == 0x8577)))) ||
           (*(int *)(iVar8 + 0x34) == 0x896d)) {
          bVar2 = true;
        }
        iVar11 = iVar11 + 1;
        iVar3 = iVar3 + 0x4c;
        iVar5 = iVar5 + 1;
        iVar7 = iVar7 + 1;
      }
    }
    if (bVar2) {
      *(undefined4 *)(iVar13 + 4) = 1;
      ((int (*)())FUN_000a2910)(*(undefined4 *)(((unsigned char *)0x00001144) + param_1),0);
      goto LAB_000a1914;
    }
  }
  *(uint *)(iVar13 + 4) = (byte)((unsigned char *)0x00001138)[param_1] + 1;
LAB_000a1914:
  ((int (*)())FUN_000a11f0)(param_1,*(int *)(((unsigned char *)0x00001144) + param_1),
               *(undefined4 *)(*(int *)(((unsigned char *)0x00001144) + param_1) + 4));
  ((unsigned char *)0x00001136)[param_1] = 1;
  ((unsigned char *)0x00001134)[param_1] = 0;
  iVar3 = (**(code **)(((unsigned char *)0x00001164) + param_1))(param_1);
  if (iVar3 == 0) {
    ((int (*)())FUN_000a2910)(*(undefined4 *)(((unsigned char *)0x00001144) + param_1),0);
  }
  ((unsigned char *)0x00001137)[param_1] = 0;
  ((unsigned char *)0x00001138)[param_1] = 0;
  if (*(char *)(iVar13 + 0x6c) == '\0') {
    uVar9 = *(uint *)(param_1 + 0x44);
    uVar10 = uVar9 & 0xffffbfff;
    *(uint *)(param_1 + 0x44) = uVar10;
    if ((uVar9 & 0x32000) == 0x30000) {
      uVar10 = uVar9 & 0xfffebfff;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x44) = uVar10;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
    }
  }
  else {
    uVar9 = *(uint *)(param_1 + 0x44);
    uVar10 = uVar9 >> 1 & 0x4000 | uVar9 & 0xffffbfff;
    *(uint *)(param_1 + 0x44) = uVar10;
    if ((uVar9 & 0x32000) == 0x20000) {
      uVar10 = uVar10 | 0x10000;
      *(undefined1 *)(param_1 + 0x29) = 1;
      *(uint *)(param_1 + 0x44) = uVar10;
      *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x20;
    }
  }
  if ((uVar10 & 0x22000) == 0x20000) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2000;
    *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 3;
    *(undefined1 *)(param_1 + 0x29) = 1;
  }
  return;
}

/* FUN_000a1a60 @ 0xa1a60 (328 bytes) */
int FUN_000a1a60(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  uint uVar2;
  
  if (((unsigned char *)0x00001134)[param_1] == '\0') {
    return;
  }
  uVar2 = (uint)(byte)((unsigned char *)0x00001138)[param_1] -
          ((int)-(uint)(byte)((unsigned char *)0x00001137)[param_1] >> 0x1f);
  if (((uVar2 < (byte)((unsigned char *)0x00001150)[param_1]) && (param_2 - 0x8921U < 6)) &&
     (param_4 - 0x8976U < 4)) {
    if (param_3 - 0x84c0U < 0x20) {
      if ((int)(uint)(byte)((unsigned char *)0x000013b2)[param_1] < (int)(param_3 - 0x84c0U)) goto LAB_000a1b60;
    }
    else if (((5 < param_3 - 0x8921U) || (uVar2 == 0)) ||
            ((param_4 != 0x8976 && (param_4 != 0x8978)))) goto LAB_000a1b60;
    iVar1 = ((int (*)())FUN_000a2d60)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1),uVar2,param_2,param_3,0,
                         param_4);
    if (iVar1 != 0) {
      if (((unsigned char *)0x00001137)[param_1] == '\0') {
        return;
      }
      ((unsigned char *)0x00001137)[param_1] = 0;
      ((unsigned char *)0x00001138)[param_1] = ((unsigned char *)0x00001138)[param_1] + '\x01';
      return;
    }
  }
LAB_000a1b60:
  ((int (*)())FUN_000a2910)(*(undefined4 *)(((unsigned char *)0x00001144) + param_1),0);
  return;
}

/* FUN_000a1bc0 @ 0xa1bc0 (328 bytes) */
int FUN_000a1bc0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  uint uVar2;
  
  if (((unsigned char *)0x00001134)[param_1] == '\0') {
    return;
  }
  uVar2 = (uint)(byte)((unsigned char *)0x00001138)[param_1] -
          ((int)-(uint)(byte)((unsigned char *)0x00001137)[param_1] >> 0x1f);
  if (((uVar2 < (byte)((unsigned char *)0x00001150)[param_1]) && (param_2 - 0x8921U < 6)) &&
     (param_4 - 0x8976U < 4)) {
    if (param_3 - 0x84c0U < 0x20) {
      if ((int)(uint)(byte)((unsigned char *)0x000013b2)[param_1] < (int)(param_3 - 0x84c0U)) goto LAB_000a1cc0;
    }
    else if (((5 < param_3 - 0x8921U) || (uVar2 == 0)) ||
            ((param_4 != 0x8976 && (param_4 != 0x8978)))) goto LAB_000a1cc0;
    iVar1 = ((int (*)())FUN_000a2d60)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1),uVar2,param_2,param_3,1,
                         param_4);
    if (iVar1 != 0) {
      if (((unsigned char *)0x00001137)[param_1] == '\0') {
        return;
      }
      ((unsigned char *)0x00001137)[param_1] = 0;
      ((unsigned char *)0x00001138)[param_1] = ((unsigned char *)0x00001138)[param_1] + '\x01';
      return;
    }
  }
LAB_000a1cc0:
  ((int (*)())FUN_000a2910)(*(undefined4 *)(((unsigned char *)0x00001144) + param_1),0);
  return;
}

/* FUN_000a1d20 @ 0xa1d20 (156 bytes) */
int FUN_000a1d20(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  if (((unsigned char *)0x00001134)[param_1] != '\0') {
    ((unsigned char *)0x00001137)[param_1] = 1;
    ((int (*)())FUN_000a2e90)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1),((unsigned char *)0x00001138)[param_1],param_2,
                 param_3,param_4,param_5,param_6);
  }
  return;
}

/* FUN_000a1dc0 @ 0xa1dc0 (168 bytes) */
int FUN_000a1dc0(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  if (((unsigned char *)0x00001134)[param_1] != '\0') {
    ((unsigned char *)0x00001137)[param_1] = 1;
    ((int (*)())FUN_000a2e90)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1),((unsigned char *)0x00001138)[param_1],param_2,
                 param_3,param_4,param_5,param_6);
  }
  return;
}

/* FUN_000a1e70 @ 0xa1e70 (176 bytes) */
int FUN_000a1e70(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  if (((unsigned char *)0x00001134)[param_1] != '\0') {
    ((unsigned char *)0x00001137)[param_1] = 1;
    ((int (*)())FUN_000a2e90)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1),((unsigned char *)0x00001138)[param_1],param_2,
                 param_3,param_4,param_5,param_6);
  }
  return;
}

/* FUN_000a1f20 @ 0xa1f20 (144 bytes) */
int FUN_000a1f20(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  if (((unsigned char *)0x00001134)[param_1] != '\0') {
    ((unsigned char *)0x00001137)[param_1] = 1;
    ((int (*)())FUN_000a3160)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1),((unsigned char *)0x00001138)[param_1],param_2,
                 param_3,param_4,param_5,param_6);
  }
  return;
}

/* FUN_000a1fb0 @ 0xa1fb0 (160 bytes) */
int FUN_000a1fb0(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  if (((unsigned char *)0x00001134)[param_1] != '\0') {
    ((unsigned char *)0x00001137)[param_1] = 1;
    ((int (*)())FUN_000a3160)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1),((unsigned char *)0x00001138)[param_1],param_2,
                 param_3,param_4,param_5,param_6);
  }
  return;
}

/* FUN_000a2050 @ 0xa2050 (168 bytes) */
int FUN_000a2050(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  if (((unsigned char *)0x00001134)[param_1] != '\0') {
    ((unsigned char *)0x00001137)[param_1] = 1;
    ((int (*)())FUN_000a3160)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1),((unsigned char *)0x00001138)[param_1],param_2,
                 param_3,param_4,param_5,param_6);
  }
  return;
}

/* FUN_000a2100 @ 0xa2100 (192 bytes) */
int FUN_000a2100(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  if (7 < param_2 - 0x8941U) {
    ((int (*)())FUN_000a2910)(*(undefined4 *)(((unsigned char *)0x00001144) + param_1),0);
    return;
  }
  ((int (*)())FUN_000a3490)(param_1,*(undefined4 *)(((unsigned char *)0x00001144) + param_1),param_2,param_3,
               ((unsigned char *)0x00001134)[param_1]);
  if (((*(uint *)(param_1 + 0x44) & 0x22000) == 0x20000) &&
     ((*(uint *)(param_1 + 0x38) & 0x2000) != 0)) {
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x2000;
    *(undefined1 *)(param_1 + 0x29) = 1;
    *(byte *)(param_1 + 0x2e) = *(byte *)(param_1 + 0x2e) | 2;
  }
  return;
}

/* FUN_000a21d0 @ 0xa21d0 (100 bytes) */
int FUN_000a21d0(param_1)
  int param_1;
{
  (**(code **)(((unsigned char *)0x0000115c) + param_1))();
  ((unsigned char *)0x00001134)[param_1] = 0;
  ((unsigned char *)0x00001136)[param_1] = 1;
  ((unsigned char *)0x00001138)[param_1] = 0;
  ((unsigned char *)0x00001137)[param_1] = 0;
  *(undefined4 *)(((unsigned char *)0x00001140) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00001144) + param_1) =
       *(undefined4 *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 0x88);
  return;
}

/* FUN_000a2240 @ 0xa2240 (232 bytes) */
int FUN_000a2240(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(((unsigned char *)0x00001154) + param_1);
  ((int (*)())FUN_000a2bb0)(param_1,iVar4 + 0x10);
  if (*(int *)(iVar4 + 4) != 0) {
    uVar2 = 0;
    iVar3 = 0;
    do {
      uVar2 = uVar2 + 1;
      iVar1 = iVar3 + *(int *)(iVar4 + 0x88);
      iVar3 = iVar3 + 0x78;
      ((int (*)())FUN_000a2bb0)(param_1,iVar1);
    } while (uVar2 < *(uint *)(iVar4 + 4));
  }
  *(undefined4 *)(iVar4 + 4) = 0;
  if (*(int *)(iVar4 + 0x88) != 0) {
    (**(code **)(param_1 + 0x18))();
    *(undefined4 *)(iVar4 + 0x88) = 0;
  }
  if (*(int *)(iVar4 + 0xc) != 0) {
    (**(code **)(param_1 + 0x18))();
    *(undefined4 *)(iVar4 + 0xc) = 0;
  }
  (**(code **)(param_1 + 0x18))(iVar4);
  *(undefined4 *)(((unsigned char *)0x00001154) + param_1) = 0;
  return;
}

/* FUN_000a2330 @ 0xa2330 (120 bytes) */
int FUN_000a2330(param_1)
  int param_1;
{
  *(int *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 8) =
       *(int *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 8) + -1;
  if (*(int *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 8) == 0) {
    (**(code **)(((unsigned char *)0x00001160) + param_1))();
    ((int (*)())FUN_000a2240)(param_1);
    return;
  }
  return;
}

/* FUN_000a2530 @ 0xa2530 (288 bytes) */
int FUN_000a2530(param_1)
  int param_1;
{
  undefined4 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  
  *(undefined4 *)(((unsigned char *)0x0000113c) + param_1) = 0;
  puVar1 = (undefined4 *)(**(code **)(param_1 + 0xc))(0x3c0);
  puVar2 = (undefined1 *)
           (**(code **)(param_1 + 0xc))((uint)*(ushort *)(((unsigned char *)0x0000114a) + param_1) * 0x14);
  if (puVar2 != (undefined1 *)0x0) {
    if (*(short *)(((unsigned char *)0x0000114a) + param_1) != 0) {
      iVar4 = 0;
      puVar3 = puVar2;
      do {
        iVar4 = iVar4 + 1;
        *(undefined4 *)(puVar3 + 0x10) = 0x3f800000;
        *puVar3 = 0;
        *(undefined4 *)(puVar3 + 4) = 0x3f800000;
        *(undefined4 *)(puVar3 + 8) = 0x3f800000;
        *(undefined4 *)(puVar3 + 0xc) = 0x3f800000;
        puVar3 = puVar3 + 0x14;
      } while (iVar4 < (int)(uint)*(ushort *)(((unsigned char *)0x0000114a) + param_1));
    }
    *(undefined4 *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 8) = 1;
    *(undefined4 **)(*(int *)(((unsigned char *)0x00001154) + param_1) + 0x88) = puVar1;
    *(undefined1 **)(*(int *)(((unsigned char *)0x00001154) + param_1) + 0xc) = puVar2;
    **(undefined4 **)(((unsigned char *)0x00001154) + param_1) = 1;
    *(undefined4 *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 4) = 1;
    *(undefined4 *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 0x8c) = 1;
    ((int (*)())FUN_000a2920)(param_1,puVar1);
    *puVar1 = 0;
    ((int (*)())FUN_000a2920)(param_1,*(int *)(((unsigned char *)0x00001154) + param_1) + 0x10);
    *(undefined4 *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 0x10) = 0;
  }
  return;
}

/* FUN_000a2660 @ 0xa2660 (392 bytes) */
int FUN_000a2660(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint *param_6;
{
  uint uVar1;
  uint uVar2;
  
  if (((((((5 < param_3 - 0x8921) && (7 < param_3 - 0x8941)) && (param_3 != 0)) &&
        ((param_3 != 1 && (param_3 != 0x8577)))) && (param_3 != 0x896d)) ||
      (((*param_6 = param_3, param_4 != 0 && (param_4 != 0x1903)) &&
       ((param_4 != 0x1904 && ((param_4 != 0x1905 && (param_4 != 0x1906)))))))) ||
     (param_6[3] = param_4, (param_5 & 0xfffffff0) != 0)) {
    return 0;
  }
  param_6[2] = param_5;
  param_6[1] = 0;
  if (param_3 < 2) {
    param_6[3] = 0;
    if (param_3 == 0) {
      if ((param_5 & 2) != 0) {
        param_5 = param_5 & 0xfffffffd;
        param_3 = 1;
      }
    }
    else if ((param_3 == 1) && ((param_5 & 2) != 0)) {
      param_5 = param_5 & 0xfffffffd;
      param_3 = 0;
    }
    uVar1 = param_5;
    if ((((param_5 & 8) != 0) ||
        ((uVar2 = param_5, param_3 == 0 &&
         (uVar1 = param_5 & 0xfffffffa, uVar2 = uVar1, (param_5 & 8) != 0)))) &&
       ((uVar2 = uVar1, (uVar1 & 1) != 0 && (uVar2 = uVar1 & 0xfffffff6, param_3 == 0)))) {
      if ((uVar1 & 4) == 0) {
        uVar2 = uVar2 | 4;
        param_3 = 1;
      }
      else {
        param_3 = 1;
        uVar2 = uVar1 & 0xfffffff2;
      }
    }
    param_6[2] = uVar2;
    *param_6 = param_3;
  }
  if (param_3 == 0x896d) {
    *(undefined1 *)(param_2 + 0x6c) = 1;
    return 1;
  }
  return 1;
}

/* FUN_000a27f0 @ 0xa27f0 (272 bytes) */
int FUN_000a27f0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int *param_3;
  int *param_4;
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  if (*(byte *)(param_1 + 4) == 0xffffffff) {
    iVar3 = 0;
    iVar6 = 0;
  }
  else {
    iVar8 = 0;
    iVar9 = 0;
    iVar7 = 0;
    iVar11 = 0;
    iVar10 = 0;
    do {
      iVar4 = *(int *)(iVar10 + *(int *)(param_2 + 0x14));
      iVar5 = *(int *)(iVar10 + *(int *)(param_2 + 0x20));
      iVar3 = 0;
      iVar6 = 0;
      bVar1 = 0 < iVar4;
      bVar2 = 0 < iVar5;
      while ((bVar1 || (bVar2))) {
        if ((iVar8 < *(int *)(param_2 + 0x18)) &&
           ((bVar1 && (iVar7 == *(int *)(iVar8 * 0x4c + *(int *)(param_2 + 0x10) + 0x44))))) {
          iVar3 = iVar3 + 1;
          iVar8 = iVar8 + 1;
          iVar7 = iVar7 + 1;
          bVar1 = iVar3 < iVar4;
        }
        if (((iVar9 < *(int *)(param_2 + 0x24)) && (bVar2)) &&
           (iVar7 == *(int *)(iVar9 * 0x4c + *(int *)(param_2 + 0x1c) + 0x44))) {
          iVar6 = iVar6 + 1;
          iVar9 = iVar9 + 1;
          iVar7 = iVar7 + 1;
          bVar2 = iVar6 < iVar5;
        }
      }
      iVar11 = iVar11 + 1;
      iVar10 = iVar10 + 4;
    } while (iVar11 != *(byte *)(param_1 + 4) + 1);
  }
  *param_3 = iVar3;
  *param_4 = iVar6;
  return;
}

/* FUN_000a2910 @ 0xa2910 (8 bytes) */
int FUN_000a2910(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined1 *)(param_1 + 0x74) = param_2;
  return;
}

/* FUN_000a2920 @ 0xa2920 (648 bytes) */
int FUN_000a2920(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  *(undefined1 *)(param_2 + 0x6c) = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 4) = 1;
  *(undefined4 *)(param_2 + 0x18) = 0;
  uVar3 = (**(code **)(param_1 + 0xc))((uint)*(ushort *)(((unsigned char *)0x0000114c) + param_1) * 0x4c);
  *(undefined4 *)(param_2 + 0x10) = uVar3;
  uVar3 = (**(code **)(param_1 + 0xc))((uint)(byte)((unsigned char *)0x00001150)[param_1] << 2);
  *(undefined4 *)(param_2 + 0x24) = 0;
  *(undefined4 *)(param_2 + 0x14) = uVar3;
  uVar3 = (**(code **)(param_1 + 0xc))((uint)*(ushort *)(((unsigned char *)0x0000114c) + param_1) * 0x4c);
  *(undefined4 *)(param_2 + 0x1c) = uVar3;
  uVar3 = (**(code **)(param_1 + 0xc))((uint)(byte)((unsigned char *)0x00001150)[param_1] << 2);
  *(undefined4 *)(param_2 + 0x20) = uVar3;
  uVar1 = 0;
  if (((unsigned char *)0x00001150)[param_1] != '\0') {
    iVar6 = 0;
    do {
      iVar4 = iVar6 * 4;
      iVar6 = iVar6 + 1;
      *(undefined4 *)(*(int *)(param_2 + 0x14) + iVar4) = 0;
      *(undefined4 *)(*(int *)(param_2 + 0x20) + iVar4) = 0;
      uVar1 = (uint)(byte)((unsigned char *)0x00001150)[param_1];
    } while (iVar6 < (int)uVar1);
  }
  uVar3 = (**(code **)(param_1 + 0xc))(*(ushort *)(((unsigned char *)0x00001148) + param_1) * uVar1 * 0xc);
  *(undefined4 *)(param_2 + 0xc) = uVar3;
  uVar1 = (uint)(byte)((unsigned char *)0x00001150)[param_1];
  if (uVar1 != 0) {
    uVar2 = (uint)*(ushort *)(((unsigned char *)0x00001148) + param_1);
    iVar6 = 0;
    do {
      iVar4 = 0;
      if (uVar2 != 0) {
        do {
          iVar7 = iVar4 + 0x84c0;
          iVar5 = iVar4 + iVar6 * uVar2;
          iVar4 = iVar4 + 1;
          iVar5 = iVar5 * 0xc;
          *(undefined1 *)(*(int *)(param_2 + 0xc) + iVar5) = 0;
          *(undefined1 *)(iVar5 + *(int *)(param_2 + 0xc) + 1) = 1;
          *(int *)(iVar5 + *(int *)(param_2 + 0xc) + 8) = iVar7;
          uVar2 = (uint)*(ushort *)(((unsigned char *)0x00001148) + param_1);
        } while (iVar4 < (int)uVar2);
        uVar1 = (uint)(byte)((unsigned char *)0x00001150)[param_1];
        uVar2 = (uint)*(ushort *)(((unsigned char *)0x00001148) + param_1);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)uVar1);
  }
  uVar3 = (**(code **)(param_1 + 0xc))((uint)*(ushort *)(((unsigned char *)0x0000114a) + param_1) * 0x14);
  *(undefined4 *)(param_2 + 0x28) = uVar3;
  if (*(short *)(((unsigned char *)0x0000114a) + param_1) != 0) {
    iVar6 = 0;
    iVar4 = 0;
    do {
      iVar6 = iVar6 + 1;
      *(undefined1 *)(*(int *)(param_2 + 0x28) + iVar4) = 0;
      *(undefined4 *)(*(int *)(param_2 + 0x28) + iVar4 + 4) = 0x3f800000;
      *(undefined4 *)(*(int *)(param_2 + 0x28) + iVar4 + 8) = 0x3f800000;
      *(undefined4 *)(*(int *)(param_2 + 0x28) + iVar4 + 0xc) = 0x3f800000;
      iVar5 = *(int *)(param_2 + 0x28) + iVar4;
      iVar4 = iVar4 + 0x14;
      *(undefined4 *)(iVar5 + 0x10) = 0x3f800000;
    } while (iVar6 < (int)(uint)*(ushort *)(((unsigned char *)0x0000114a) + param_1));
  }
  uVar3 = (**(code **)(param_1 + 0x10))(*(undefined4 *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 0x8c),4)
  ;
  *(undefined4 *)(param_2 + 0x70) = uVar3;
  ((int (*)())FUN_000a2910)(param_2,1);
  return;
}

/* FUN_000a2bb0 @ 0xa2bb0 (400 bytes) */
int FUN_000a2bb0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  if (*(int *)(param_2 + 0x10) != 0) {
    (**(code **)(param_1 + 0x18))();
    *(undefined4 *)(param_2 + 0x10) = 0;
  }
  if (*(int *)(param_2 + 0x14) != 0) {
    (**(code **)(param_1 + 0x18))();
    *(undefined4 *)(param_2 + 0x14) = 0;
  }
  if (*(int *)(param_2 + 0x1c) != 0) {
    (**(code **)(param_1 + 0x18))();
    *(undefined4 *)(param_2 + 0x1c) = 0;
  }
  if (*(int *)(param_2 + 0x20) != 0) {
    (**(code **)(param_1 + 0x18))();
    *(undefined4 *)(param_2 + 0x20) = 0;
  }
  if (*(int *)(param_2 + 0xc) != 0) {
    (**(code **)(param_1 + 0x18))();
    *(undefined4 *)(param_2 + 0xc) = 0;
  }
  if (*(int *)(param_2 + 0x28) != 0) {
    (**(code **)(param_1 + 0x18))();
    *(undefined4 *)(param_2 + 0x28) = 0;
  }
  iVar1 = *(int *)(param_2 + 0x70);
  if (iVar1 != 0) {
    iVar2 = *(int *)(((unsigned char *)0x00001154) + param_1);
    uVar3 = 0;
    if (*(int *)(iVar2 + 0x8c) != 0) {
      do {
        if (*(int *)(uVar3 * 4 + iVar1) != 0) {
          *(undefined4 *)(uVar3 * 4 + iVar1) = 0;
          (**(code **)(((unsigned char *)0x00001158) + param_1))(param_1);
          iVar1 = *(int *)(param_2 + 0x70);
          iVar2 = *(int *)(((unsigned char *)0x00001154) + param_1);
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(iVar2 + 0x8c));
    }
    (**(code **)(param_1 + 0x18))();
    *(undefined4 *)(param_2 + 0x70) = 0;
  }
  return;
}

/* FUN_000a2d60 @ 0xa2d60 (276 bytes) */
int FUN_000a2d60(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar4 = *(char **)(param_2 + 0xc);
  iVar2 = ((uint)*(ushort *)(((unsigned char *)0x00001148) + param_1) * param_3 + param_4 + -0x8921) * 0xc;
  pcVar3 = pcVar4 + iVar2;
  if (pcVar4[iVar2] != '\0') {
    return 0;
  }
  iVar1 = (uint)*(ushort *)(((unsigned char *)0x00001148) + param_1) * (uint)(byte)((unsigned char *)0x00001150)[param_1];
  do {
    if (iVar1 == 0) {
      *pcVar3 = '\x01';
      *(undefined1 *)(iVar2 + *(int *)(param_2 + 0xc) + 1) = param_6;
      *(int *)(iVar2 + *(int *)(param_2 + 0xc) + 8) = param_5;
      *(int *)(iVar2 + *(int *)(param_2 + 0xc) + 4) = param_7;
      return 1;
    }
    if ((*pcVar4 != '\0') && (*(int *)(pcVar4 + 8) == param_5)) {
      if ((param_7 == 0x8976) || (param_7 == 0x8978)) {
        if (*(int *)(pcVar4 + 4) == 0x8977) {
          return 0;
        }
        if (*(int *)(pcVar4 + 4) == 0x8979) {
          return 0;
        }
      }
      else {
        if (*(int *)(pcVar4 + 4) == 0x8976) {
          return 0;
        }
        if (*(int *)(pcVar4 + 4) == 0x8978) {
          return 0;
        }
      }
    }
    pcVar4 = pcVar4 + 0xc;
    iVar1 = iVar1 + -1;
  } while( true );
}

/* FUN_000a2e90 @ 0xa2e90 (708 bytes) */
int FUN_000a2e90(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  uint param_6;
  uint param_7;
  int param_8;
{
  int iVar1;
  undefined4 uVar2;
  int in_stack_00000038;
  undefined4 in_stack_0000003c;
  int in_stack_00000040;
  int in_stack_00000044;
  undefined4 in_stack_00000048;
  int in_stack_0000004c;
  int in_stack_00000050;
  undefined4 in_stack_00000054;
  int local_98;
  undefined1 auStack_94 [4];
  int local_90;
  int local_8c;
  uint local_88;
  uint local_84;
  undefined4 local_80;
  undefined1 auStack_7c [16];
  undefined1 auStack_6c [16];
  undefined1 auStack_5c [16];
  int local_4c;
  int local_48;
  
  ((int (*)())FUN_000a27f0)((*(unsigned char *)0x00001134) + param_1,param_2,&local_98,auStack_94);
  if ((((((((param_3 < (int)(uint)(byte)((unsigned char *)0x00001150)[param_1]) &&
           (local_98 < (int)(uint)*(ushort *)(((unsigned char *)0x0000114e) + param_1))) &&
          (param_4 - 0x8961U < 0xc)) &&
         (((1 << (param_4 - 0x8961U & 0x3f) & 0xffdU) != 0 &&
          (local_90 = param_4,
          iVar1 = ((int (*)())FUN_000a2660)(param_1,param_2,param_8,in_stack_00000038,in_stack_0000003c,
                               auStack_7c), iVar1 != 0)))) &&
        ((iVar1 = ((int (*)())FUN_000a2660)(param_1,param_2,in_stack_00000040,in_stack_00000044,in_stack_00000048
                               ,auStack_6c), iVar1 != 0 &&
         ((iVar1 = ((int (*)())FUN_000a2660)(param_1,param_2,in_stack_0000004c,in_stack_00000050,
                                in_stack_00000054,auStack_5c), iVar1 != 0 && (param_5 - 0x8921U < 6)
          ))))) &&
       ((7 < param_8 - 0x8941U ||
        ((((7 < in_stack_00000040 - 0x8941U || (7 < in_stack_0000004c - 0x8941U)) ||
          (param_8 == in_stack_00000040)) ||
         ((param_8 == in_stack_0000004c || (in_stack_00000040 == in_stack_0000004c)))))))) &&
      ((((param_7 & 0xffffffbf & (param_7 & 0xffffffbf) - 1) == 0 &&
        ((param_8 != 0x896d || (in_stack_00000038 != 0x1906)))) &&
       ((in_stack_00000040 != 0x896d || (in_stack_00000044 != 0x1906)))))) &&
     (((in_stack_0000004c != 0x896d || (in_stack_00000050 != 0x1906)) &&
      ((param_4 != 0x8967 ||
       (((param_8 != 0x896d || ((in_stack_00000038 != 0 && (in_stack_00000038 != 0x1906)))) &&
        ((in_stack_00000040 != 0x896d || ((in_stack_00000044 != 0 && (in_stack_00000044 != 0x1906)))
         ))))))))) {
    uVar2 = 0;
    if (param_6 < 8) {
      local_4c = *(int *)(param_2 + 8);
      *(int *)(param_2 + 8) = local_4c + 1;
      local_80 = 0;
      local_8c = param_5;
      local_88 = param_6;
      local_84 = param_7;
      local_48 = param_3;
      (**(code **)(((unsigned char *)0x00001344) + param_1))
                (*(int *)(param_2 + 0x18) * 0x4c + *(int *)(param_2 + 0x10),&local_90,0x4c);
      uVar2 = 1;
      *(int *)(param_3 * 4 + *(int *)(param_2 + 0x14)) =
           *(int *)(param_3 * 4 + *(int *)(param_2 + 0x14)) + 1;
      *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + 1;
    }
  }
  else {
    ((int (*)())FUN_000a2910)(param_2,0);
    uVar2 = 0;
  }
  return uVar2;
}

/* FUN_000a3160 @ 0xa3160 (804 bytes) */
int FUN_000a3160(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  uint param_6;
  int param_7;
  int param_8;
{
  int iVar1;
  undefined4 in_stack_00000038;
  int in_stack_0000003c;
  int in_stack_00000040;
  undefined4 in_stack_00000044;
  int in_stack_00000048;
  int in_stack_0000004c;
  undefined4 in_stack_00000050;
  undefined1 auStack_98 [4];
  int local_94;
  int local_90;
  int local_8c;
  undefined4 local_88;
  uint local_84;
  undefined4 local_80;
  undefined1 auStack_7c [16];
  undefined1 auStack_6c [16];
  undefined1 auStack_5c [16];
  int local_4c;
  int local_48;
  
  ((int (*)())FUN_000a27f0)((*(unsigned char *)0x00001134) + param_1,param_2,auStack_98,&local_94);
  if (((((((((param_3 < (int)(uint)(byte)((unsigned char *)0x00001150)[param_1]) &&
            (local_94 < (int)(uint)*(ushort *)(((unsigned char *)0x0000114e) + param_1))) &&
           (param_4 - 0x8961U < 0xc)) &&
          (((1 << (param_4 - 0x8961U & 0x3f) & 0xffdU) != 0 &&
           (local_90 = param_4,
           iVar1 = ((int (*)())FUN_000a2660)(param_1,param_2,param_7,param_8,in_stack_00000038,auStack_7c),
           iVar1 != 0)))) &&
         (iVar1 = ((int (*)())FUN_000a2660)(param_1,param_2,in_stack_0000003c,in_stack_00000040,in_stack_00000044
                               ,auStack_6c), iVar1 != 0)) &&
        ((iVar1 = ((int (*)())FUN_000a2660)(param_1,param_2,in_stack_00000048,in_stack_0000004c,in_stack_00000050
                               ,auStack_5c), iVar1 != 0 && (param_5 - 0x8921U < 6)))) &&
       ((((7 < param_7 - 0x8941U ||
          (((7 < in_stack_0000003c - 0x8941U || (7 < in_stack_00000048 - 0x8941U)) ||
           (param_7 == in_stack_0000003c)))) ||
         ((param_7 == in_stack_00000048 || (in_stack_0000003c == in_stack_00000048)))) &&
        ((((param_6 & 0xffffffbf & (param_6 & 0xffffffbf) - 1) == 0 &&
          (((1 < param_4 - 0x8966U && (param_4 != 0x896c)) ||
           ((0 < *(int *)(param_2 + 0x18) &&
            (((iVar1 = *(int *)(param_2 + 0x18) * 0x4c + *(int *)(param_2 + 0x10),
              *(int *)(iVar1 + -8) == *(int *)(param_2 + 8) + -1 &&
              (param_3 == *(int *)(iVar1 + -4))) && (param_4 == *(int *)(iVar1 + -0x4c))))))))) &&
         ((((param_4 == 0x8967 || (*(int *)(param_2 + 0x18) < 2)) ||
           (iVar1 = *(int *)(param_2 + 0x18) * 0x4c + *(int *)(param_2 + 0x10),
           *(int *)(iVar1 + -8) != *(int *)(param_2 + 8) + -1)) ||
          ((param_3 != *(int *)(iVar1 + -4) || (*(int *)(iVar1 + -0x4c) != 0x8967)))))))))) &&
      (((param_7 != 0x896d || ((param_8 != 0 && (param_8 != 0x1906)))) &&
       ((in_stack_0000003c != 0x896d || ((in_stack_00000040 != 0 && (in_stack_00000040 != 0x1906))))
       )))) && ((in_stack_00000048 != 0x896d ||
                ((in_stack_0000004c != 0 && (in_stack_0000004c != 0x1906)))))) {
    local_4c = *(int *)(param_2 + 8);
    *(int *)(param_2 + 8) = local_4c + 1;
    local_80 = 0;
    local_88 = 0;
    local_8c = param_5;
    local_84 = param_6;
    local_48 = param_3;
    (**(code **)(((unsigned char *)0x00001344) + param_1))
              (*(int *)(param_2 + 0x24) * 0x4c + *(int *)(param_2 + 0x1c),&local_90,0x4c);
    *(int *)(param_3 * 4 + *(int *)(param_2 + 0x20)) =
         *(int *)(param_3 * 4 + *(int *)(param_2 + 0x20)) + 1;
    *(int *)(param_2 + 0x24) = *(int *)(param_2 + 0x24) + 1;
    return 1;
  }
  ((int (*)())FUN_000a2910)(param_2,0);
  return 0;
}

/* FUN_000a3490 @ 0xa3490 (196 bytes) */
int FUN_000a3490(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 *param_4;
  int param_5;
{
  int iVar1;
  
  param_3 = param_3 + -0x8941;
  if ((-1 < param_3) && (param_3 < (int)(uint)*(ushort *)(((unsigned char *)0x0000114a) + param_1))) {
    if (param_5 != 0) {
      param_3 = param_3 * 0x14;
      *(undefined1 *)(*(int *)(param_2 + 0x28) + param_3) = 1;
      *(undefined4 *)(param_3 + *(int *)(param_2 + 0x28) + 4) = *param_4;
      *(undefined4 *)(param_3 + *(int *)(param_2 + 0x28) + 8) = param_4[1];
      *(undefined4 *)(param_3 + *(int *)(param_2 + 0x28) + 0xc) = param_4[2];
      *(undefined4 *)(param_3 + *(int *)(param_2 + 0x28) + 0x10) = param_4[3];
      return 1;
    }
    iVar1 = *(int *)(*(int *)(((unsigned char *)0x00001154) + param_1) + 0xc);
    *(undefined1 *)(param_3 * 0x14 + iVar1) = 1;
    iVar1 = param_3 * 0x14 + iVar1;
    *(undefined4 *)(iVar1 + 4) = *param_4;
    *(undefined4 *)(iVar1 + 8) = param_4[1];
    *(undefined4 *)(iVar1 + 0xc) = param_4[2];
    *(undefined4 *)(iVar1 + 0x10) = param_4[3];
    return 1;
  }
  return 0;
}

/* FUN_000a3560 @ 0xa3560 (164 bytes) */
uint FUN_000a3560(double param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(((unsigned char *)0x000013e0) + param_2);
  if ((double)(float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x000013e0) + param_2) ^ 0x80000000) -
                     DOUBLE_001aa1e0) < param_1) {
    uVar1 = *(uint *)(((unsigned char *)0x000013e4) + param_2);
    if (param_1 < (double)(float)((double)CONCAT44(0x43300000,
                                                   *(uint *)(((unsigned char *)0x000013e4) + param_2) ^ 0x80000000)
                                 - DOUBLE_001aa1e0)) {
      uVar1 = (uint)(param_1 + (double)FLOAT_001aa10c);
    }
  }
  return uVar1;
}

/* FUN_000a3610 @ 0xa3610 (88 bytes) */
int FUN_000a3610(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)(byte)((unsigned char *)0x000013b7)[param_1];
  uVar1 = 1 << (uVar3 & 0x3f);
  if ((param_2 & uVar1) == 0) {
    iVar2 = uVar3 + 1;
    do {
      uVar3 = uVar3 - 1;
      iVar2 = iVar2 + -1;
      if (iVar2 == 0) {
        uVar1 = 1 << (uVar3 & 0x3f);
        break;
      }
      uVar1 = 1 << (uVar3 & 0x3f);
    } while ((param_2 & uVar1) == 0);
  }
  if ((int)param_2 <= (int)uVar1) {
    return uVar1;
  }
  return uVar1 << 1;
}

/* FUN_000a3670 @ 0xa3670 (48 bytes) */
int FUN_000a3670(param_1)
  int param_1;
{
  uint uVar1;
  
  if ((*(uint *)(param_1 + 0x44) & 0x100000) == 0) {
    uVar1 = *(uint *)(param_1 + 0xe8) & 1;
  }
  else {
    uVar1 = *(uint *)(param_1 + 0x44) & 0x80;
  }
  if (uVar1 == 0) {
    return 0;
  }
  return 1;
}

/* FUN_000a36b0 @ 0xa36b0 (212 bytes) */
int FUN_000a36b0(param_1, param_2)
  int param_1;
  int param_2;
{
  float fVar1;
  
  if (param_2 != 0) {
    fVar1 = FLOAT_001aa0e8;
    if (*(short *)(((unsigned char *)0x00002e0e) + *(int *)(*(int *)(param_1 + 4) + 0x10)) == 0x1102) {
      fVar1 = FLOAT_001aa108;
    }
    return (int)((float)((double)CONCAT44(0x43300000,*(undefined4 *)(param_1 + 8)) - DOUBLE_001aa250
                        ) * FLOAT_001aa10c * (fVar1 + *(float *)(param_1 + 0xe0)));
  }
  return (int)((float)((double)CONCAT44(0x43300000,*(undefined4 *)(param_1 + 8)) - DOUBLE_001aa250)
               * FLOAT_001aa10c * *(float *)(param_1 + 0xe0));
}

/* FUN_000a3790 @ 0xa3790 (716 bytes) */
void FUN_000a3790(double param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5,
                 int *param_6)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  char cStack_19;
  
  dVar5 = (double)FLOAT_001aa0e8;
  if (dVar5 <= param_1) {
    dVar5 = (double)(float)((double)CONCAT44(0x43300000,(int)param_1 ^ 0x80000000) - DOUBLE_001aa1e0
                           );
  }
  iVar4 = 0;
  dVar8 = (double)FLOAT_001aa0e8;
  iVar3 = ((int)param_4 >> 1) + (uint)((int)param_4 < 0 && (param_4 & 1) != 0);
  dVar6 = dVar8;
  if ((float)(param_1 - dVar8) < 0.0) {
    dVar6 = param_1;
  }
  if (-(float)(param_1 - dVar8) < 0.0) {
    param_1 = dVar6;
  }
  dVar6 = (double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) - DOUBLE_001aa1e0);
  dVar7 = (double)(float)((double)CONCAT44(0x43300000,
                                           (int)(dVar6 / (double)(float)(dVar5 + (double)
                                                  FLOAT_001aa108)) ^ 0x80000000) - DOUBLE_001aa1e0);
  dVar5 = (double)(float)(param_1 *
                         (double)(float)(dVar8 / (double)(float)(dVar7 * (double)(float)(dVar7 - 
                                                  dVar8))));
  if (0 < iVar3) {
    do {
      dVar8 = (double)FLOAT_001aa0d4;
      if (dVar7 <= dVar8) {
LAB_000a39f0:
        fVar1 = (float)(dVar8 * (double)FLOAT_001aa0f0);
      }
      else {
        uVar2 = 0;
        dVar9 = dVar8;
        do {
          dVar10 = (double)(float)((double)CONCAT44(0x43300000,
                                                    (int)((double)(float)((double)CONCAT44(
                                                  0x43300000,uVar2 + iVar4 ^ 0x80000000) -
                                                  DOUBLE_001aa1e0) - dVar7) ^ 0x80000000) -
                                  DOUBLE_001aa1e0);
          if ((dVar7 <= dVar10) && (dVar10 < (double)(float)(dVar6 - dVar7))) {
            dVar8 = (double)(float)(dVar5 * dVar9 + dVar8);
          }
          uVar2 = uVar2 + 1;
          dVar9 = (double)(float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - DOUBLE_001aa1e0)
          ;
        } while (dVar9 < dVar7);
        uVar2 = 0;
        dVar9 = (double)FLOAT_001aa0d4;
        do {
          dVar10 = (double)(float)((double)CONCAT44(0x43300000,uVar2 + iVar4 ^ 0x80000000) -
                                  DOUBLE_001aa1e0);
          if ((dVar7 <= dVar10) && (dVar10 < (double)(float)(dVar6 - dVar7))) {
            dVar8 = (double)(float)(dVar5 * (double)((float)(dVar7 - dVar9) - FLOAT_001aa0e8) +
                                   dVar8);
          }
          uVar2 = uVar2 + 1;
          dVar9 = (double)(float)((double)CONCAT44(0x43300000,uVar2 ^ 0x80000000) - DOUBLE_001aa1e0)
          ;
        } while (dVar9 < dVar7);
        fVar1 = FLOAT_001aa0f0;
        if (dVar8 <= (double)FLOAT_001aa0e8) goto LAB_000a39f0;
      }
      cStack_19 = (char)(int)(fVar1 + FLOAT_001aa10c);
      *(char *)(iVar4 + param_5) = cStack_19;
    } while ((cStack_19 != -1) && (iVar4 = iVar4 + 1, iVar3 != iVar4));
  }
  *param_6 = iVar4;
  return;
}

/* FUN_000a3a60 @ 0xa3a60 (372 bytes) */
void FUN_000a3a60(double param_1,undefined4 param_2,undefined4 param_3,uint param_4,int param_5,
                 uint *param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  uint uVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  
  dVar5 = DOUBLE_001aa1e0;
  fVar4 = FLOAT_001aa10c;
  dVar7 = (double)FLOAT_001aa0e8;
  if (dVar7 <= param_1) {
    dVar7 = (double)(float)((double)CONCAT44(0x43300000,(int)param_1 ^ 0x80000000) - DOUBLE_001aa1e0
                           );
  }
  dVar8 = (double)FLOAT_001aa0e8;
  uVar6 = 0;
  dVar9 = dVar8;
  if ((float)(param_1 - dVar8) < 0.0) {
    dVar9 = param_1;
  }
  if (-(float)(param_1 - dVar8) < 0.0) {
    param_1 = dVar9;
  }
  fVar1 = (float)((double)CONCAT44(0x43300000,
                                   (int)(((float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000)
                                                 - DOUBLE_001aa1e0) * FLOAT_001aa10c) /
                                        (float)(dVar7 + dVar8)) ^ 0x80000000) - DOUBLE_001aa1e0);
  fVar1 = fVar1 + fVar1;
  fVar3 = FLOAT_001aa0f0 / fVar1;
  fVar2 = FLOAT_001aa0d4;
  while (fVar2 < fVar1) {
    *(char *)(param_5 + uVar6) = (char)(int)((float)(param_1 * (double)fVar3) * fVar2 + fVar4);
    uVar6 = uVar6 + 1;
    fVar2 = (float)((double)CONCAT44(0x43300000,uVar6 ^ 0x80000000) - dVar5);
  }
  if ((int)uVar6 < (int)(((int)param_4 >> 1) + (uint)((int)param_4 < 0 && (param_4 & 1) != 0))) {
    *(undefined1 *)(uVar6 + param_5) = 0xff;
  }
  *param_6 = uVar6;
  return;
}

/* FUN_000a3be0 @ 0xa3be0 (2056 bytes) */
int FUN_000a3be0(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined4 uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  
  if (*(int *)(param_1 + 0x277c) == param_2) {
    return;
  }
  *(int *)(param_1 + 0x277c) = param_2;
  bVar1 = *(int *)(param_1 + 0x2768) == 0;
  uVar10 = (uint)*(ushort *)(param_1 + 0x1b52);
  *(uint *)(param_1 + 0x1b50) = uVar10;
  if (bVar1) {
    if ((*(uint *)(param_1 + 0x44) & 0x20000000) == 0) {
      return;
    }
  }
  else if ((param_2 != 0) || ((*(uint *)(param_1 + 0x44) & 0x20000000) == 0)) {
    *(uint *)(param_1 + 0x1b50) = uVar10;
    iVar12 = param_2 * 4 + *(int *)(param_1 + 0x2768);
    uVar16 = *(uint *)(&DAT_001aa7a8 + param_2 * 4);
    *(uint *)(param_1 + 0x1b50) =
         uVar10 | *(int *)(iVar12 + 0xe8) << (*(int *)(param_1 + 0x276c) * 2 + 0x10U & 0x3f);
    uVar10 = *(uint *)(iVar12 + 0x110);
    *(uint *)(param_1 + 0x1b64) = uVar16 & 3 | *(uint *)(param_1 + 0x1b64) & 0xfffffffc;
    *(undefined4 *)(param_1 + 0x1b68) = 0;
    *(uint *)(param_1 + 0x1a64) = uVar10 & 0x10 | *(uint *)(param_1 + 0x1a64) & 0xffffffef;
    FUN_0004b190(param_1,*(undefined4 *)(iVar12 + 0xc0));
  }
  *(undefined4 *)(param_1 + 0x1ba8) = *(undefined4 *)(param_1 + 0x1ba0);
  if (!bVar1) goto LAB_000a41d0;
  if ((*(uint *)(param_1 + 0x44) & 0x100000) == 0) {
    FUN_000900a0(param_1);
  }
  else {
    FUN_00064720(param_1);
  }
  (**(code **)(((unsigned char *)0x00001334) + param_1))(param_1,1);
  uVar10 = *(uint *)(param_1 + 0x44);
  uVar16 = *(uint *)(param_1 + 0x1ba4);
  *(uint *)(param_1 + 0x1ba0) = uVar16;
  bVar2 = (uVar10 >> 0x1d & 1) == 0;
  *(uint *)(param_1 + 0x1a64) = *(uint *)(param_1 + 0x1a64) & 0xffffffef;
  if ((bVar2) || ((*(uint *)(param_1 + 0x8c) & 0x40000000) != 0)) {
    if ((uVar10 & 0x40000000) == 0) {
      *(uint *)(param_1 + 0x1b50) = (uint)*(ushort *)(param_1 + 0x1b52);
    }
    else if ((!bVar2) && ((*(uint *)(param_1 + 0x8c) & 0x40000000) != 0)) {
      *(undefined4 *)(param_1 + 0x1bc0) = 0;
      *(uint *)(param_1 + 0x1b50) = (uint)*(ushort *)(param_1 + 0x1b52);
    }
  }
  else {
    if (param_2 == 0) {
      if ((uVar10 & 0x20000) == 0) {
        if (((unsigned char *)0x000013b2)[param_1] == '\0') goto LAB_000a40f0;
        uVar11 = 0;
        uVar8 = 0;
        uVar9 = 0;
        uVar10 = 0x10;
        uVar6 = 0;
        iVar12 = param_1;
        do {
          if ((((*(uint *)(iVar12 + 0x48) & 0x1f) == 0) ||
              ((1 << (uVar8 & 0x3f) & *(uint *)(param_1 + 0xec)) == 0)) ||
             (*(int *)(((unsigned char *)0x000013f8) + iVar12) == 0)) {
            iVar18 = (int)(char)uVar11;
            iVar13 = uVar8 * 4 + param_1;
            *(uint *)(iVar13 + 0x1ee8) =
                 (iVar18 + 3) * 0x40000 & 0xfc0000U |
                 (iVar18 + 2) * 0x1000 & 0x3f000U |
                 (iVar18 + 1) * 0x40 & 0xfc0U |
                 uVar11 & 0x3f | *(uint *)(iVar13 + 0x1ee8) & 0xff000000;
            *(uint *)(param_1 + 0x1b50) = *(uint *)(param_1 + 0x1b50) & ~(1 << (uVar10 & 0x3f));
            *(uint *)(param_1 + 0x1bc0) = *(uint *)(param_1 + 0x1bc0) & ~(1 << (uVar6 & 0x3f));
            uVar11 = uVar11 + (*(uint *)(param_1 + 0x1ba0) >> (uVar9 & 0x3f) & 7);
          }
          else {
            iVar18 = uVar11 + 1;
            *(uint *)(param_1 + 0x1a64) = *(uint *)(param_1 + 0x1a64) | 0x10;
            *(uint *)(param_1 + 0x1b50) = 1 << (uVar10 & 0x3f) | *(uint *)(param_1 + 0x1b50);
            *(uint *)(param_1 + 0x1bc0) = 1 << (uVar6 & 0x3f) | *(uint *)(param_1 + 0x1bc0);
            iVar13 = uVar8 * 4 + param_1;
            uVar16 = uVar16 & ~(7 << (uVar9 & 0x3f));
            uVar17 = uVar11 & 0x3f;
            uVar11 = uVar11 + 2;
            *(uint *)(iVar13 + 0x1ee8) =
                 iVar18 * 0x40 & 0xfc0U | uVar17 | *(uint *)(iVar13 + 0x1ee8) & 0xff000000 |
                 0xffe000;
          }
          uVar8 = uVar8 + 1;
          iVar12 = iVar12 + 4;
          uVar9 = uVar9 + 3;
          uVar10 = uVar10 + 2;
          uVar6 = uVar6 + 2;
        } while ((int)uVar8 < (int)(uint)(byte)((unsigned char *)0x000013b2)[param_1]);
      }
      else {
        if ((uVar10 & 0x2000) == 0) {
          bVar3 = ((unsigned char *)0x00001135)[param_1];
        }
        else {
          bVar3 = ((unsigned char *)0x000011d3)[param_1];
        }
        uVar10 = *(uint *)(param_1 + 0xec);
        if (((unsigned char *)0x000013b2)[param_1] == '\0') {
LAB_000a40f0:
          uVar11 = 0;
          goto LAB_000a40f4;
        }
        uVar11 = 0;
        uVar9 = 0;
        uVar17 = 0;
        uVar6 = 0x10;
        uVar8 = 0;
        iVar12 = param_1 + 0x1ee0;
        do {
          if (((bVar3 & uVar10) >> (uVar9 & 0x3f) & 1) == 0) {
            iVar13 = (int)(char)uVar11;
            *(uint *)(iVar12 + 8) =
                 (iVar13 + 3) * 0x40000 & 0xfc0000U |
                 (iVar13 + 2) * 0x1000 & 0x3f000U |
                 (iVar13 + 1) * 0x40 & 0xfc0U | uVar11 & 0x3f | *(uint *)(iVar12 + 8) & 0xff000000;
            *(uint *)(param_1 + 0x1b50) = *(uint *)(param_1 + 0x1b50) & ~(1 << (uVar6 & 0x3f));
            *(uint *)(param_1 + 0x1bc0) = *(uint *)(param_1 + 0x1bc0) & ~(1 << (uVar8 & 0x3f));
            uVar11 = uVar11 + (*(uint *)(param_1 + 0x1ba0) >> (uVar17 & 0x3f) & 7);
          }
          else {
            *(uint *)(param_1 + 0x1a64) = *(uint *)(param_1 + 0x1a64) | 0x10;
            *(uint *)(param_1 + 0x1b50) = 1 << (uVar6 & 0x3f) | *(uint *)(param_1 + 0x1b50);
            iVar13 = uVar11 + 1;
            *(uint *)(param_1 + 0x1bc0) = 1 << (uVar8 & 0x3f) | *(uint *)(param_1 + 0x1bc0);
            uVar16 = uVar16 & ~(7 << (uVar17 & 0x3f));
            uVar4 = uVar11 & 0x3f;
            uVar11 = uVar11 + 2;
            *(uint *)(iVar12 + 8) =
                 iVar13 * 0x40 & 0xfc0U | uVar4 | *(uint *)(iVar12 + 8) & 0xff000000 | 0xffe000;
          }
          uVar9 = uVar9 + 1;
          iVar12 = iVar12 + 4;
          uVar17 = uVar17 + 3;
          uVar6 = uVar6 + 2;
          uVar8 = uVar8 + 2;
        } while ((int)uVar9 < (int)(uint)(byte)((unsigned char *)0x000013b2)[param_1]);
      }
      uVar11 = uVar11 & 0xff;
    }
    else {
      if (*(int *)(param_1 + 0x2768) != 0) goto LAB_000a40f0;
      if ((uVar10 & 0x20000) == 0) {
        uVar10 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
        if (uVar10 == 0) goto LAB_000a40d4;
        uVar11 = 0;
        iVar13 = 0;
        iVar12 = param_1;
        do {
          if (((*(uint *)(iVar12 + 0x48) & 0x1f) != 0) && (*(int *)(((unsigned char *)0x000013f8) + iVar12) != 0)) {
            iVar14 = (int)(char)uVar11;
            iVar18 = iVar13 * 4 + param_1;
            *(uint *)(iVar18 + 0x1ee8) =
                 (iVar14 + 3) * 0x40000 & 0xfc0000U |
                 (iVar14 + 2) * 0x1000 & 0x3f000U |
                 (iVar14 + 1) * 0x40 & 0xfc0U |
                 uVar11 & 0x3f | *(uint *)(iVar18 + 0x1ee8) & 0xff000000;
            uVar10 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
          }
          uVar6 = iVar13 * 3;
          iVar13 = iVar13 + 1;
          iVar12 = iVar12 + 4;
          uVar11 = uVar11 + (*(uint *)(param_1 + 0x1ba0) >> (uVar6 & 0x3f) & 7);
        } while (iVar13 < (int)uVar10);
      }
      else {
        if ((uVar10 & 0x2000) == 0) {
          bVar3 = ((unsigned char *)0x00001135)[param_1];
        }
        else {
          bVar3 = ((unsigned char *)0x000011d3)[param_1];
        }
        uVar10 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
        if (uVar10 == 0) {
LAB_000a40d4:
          uVar11 = 0;
        }
        else {
          uVar11 = 0;
          uVar8 = 0;
          uVar6 = 0;
          iVar12 = param_1 + 0x1ee0;
          do {
            if ((bVar3 >> (uVar8 & 0x3f) & 1) != 0) {
              iVar13 = (int)(char)uVar11;
              *(uint *)(iVar12 + 8) =
                   (iVar13 + 3) * 0x40000 & 0xfc0000U |
                   (iVar13 + 2) * 0x1000 & 0x3f000U |
                   (iVar13 + 1) * 0x40 & 0xfc0U | uVar11 & 0x3f | *(uint *)(iVar12 + 8) & 0xff000000
              ;
              uVar10 = (uint)(byte)((unsigned char *)0x000013b2)[param_1];
            }
            uVar8 = uVar8 + 1;
            iVar12 = iVar12 + 4;
            uVar9 = uVar6 & 0x3f;
            uVar6 = uVar6 + 3;
            uVar11 = uVar11 + (*(uint *)(param_1 + 0x1ba0) >> uVar9 & 7);
          } while ((int)uVar8 < (int)uVar10);
        }
      }
      uVar11 = uVar11 & 0xff;
      *(undefined4 *)(param_1 + 0x1bc0) = 0;
      *(uint *)(param_1 + 0x1b50) = (uint)*(ushort *)(param_1 + 0x1b52);
    }
LAB_000a40f4:
    *(uint *)(param_1 + 0x1f2c) = uVar11 & 0x7f | *(uint *)(param_1 + 0x1f2c) & 0xffffff80;
    puVar7 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0xd);
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar7;
    iVar13 = 0;
    *puVar7 = ((unsigned char *)0x000010c0);
    iVar18 = 8;
    uVar15 = *(undefined4 *)(param_1 + 0x1f2c);
    puVar7[2] = 0x825;
    puVar7[1] = uVar15;
    puVar7[3] = *(undefined4 *)(param_1 + 0x1ba0);
    puVar7[4] = *(uint *)(param_1 + 0x1f28) | 0x70000;
    iVar12 = param_1;
    do {
      puVar5 = (undefined4 *)(iVar12 + 0x1ee8);
      iVar12 = iVar12 + 4;
      *(undefined4 *)((int)puVar7 + iVar13 + 0x14) = *puVar5;
      iVar13 = iVar13 + 4;
      iVar18 = iVar18 + -1;
    } while (iVar18 != 0);
    UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
    *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 0x34;
    (*UNRECOVERED_JUMPTABLE)(param_1);
  }
  *(uint *)(param_1 + 0x1ba8) = uVar16;
LAB_000a41d0:
  puVar7 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0xc);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar7;
  *puVar7 = ((unsigned char *)0x00001002);
  uVar15 = *(undefined4 *)(param_1 + 0x1b50);
  puVar7[2] = 0x825;
  puVar7[1] = uVar15;
  uVar15 = *(undefined4 *)(param_1 + 0x1ba0);
  puVar7[4] = ((unsigned char *)0x00001007);
  puVar7[3] = uVar15;
  uVar15 = *(undefined4 *)(param_1 + 0x1a64);
  puVar7[6] = ((unsigned char *)0x0000108e);
  puVar7[5] = uVar15;
  uVar15 = *(undefined4 *)(param_1 + 0x1b64);
  puVar7[8] = ((unsigned char *)0x00001098);
  puVar7[7] = uVar15;
  uVar15 = *(undefined4 *)(param_1 + 0x1b68);
  puVar7[10] = ((unsigned char *)0x000010c0);
  puVar7[9] = uVar15;
  puVar7[0xb] = *(undefined4 *)(param_1 + 0x1f2c);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 0x30;
  (*UNRECOVERED_JUMPTABLE)(param_1);
  if (*(char *)(param_1 + 0x1868) != '\0') {
    puVar7 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,9);
    *puVar7 = 0x7101d;
    *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar7 + 1;
    iVar13 = 8;
    iVar12 = param_1;
    do {
      puVar5 = *(undefined4 **)(FUN_00002748 + param_1 + 4);
      puVar7 = (undefined4 *)(iVar12 + 0x1ee8);
      iVar12 = iVar12 + 4;
      *puVar5 = *puVar7;
      *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar5 + 1;
      iVar13 = iVar13 + -1;
    } while (iVar13 != 0);
    (**(code **)(param_1 + 0x275c))(param_1);
  }
  if (bVar1) {
    (**(code **)(((unsigned char *)0x00001330) + param_1))(param_1,0xc0100000);
  }
  if (*(int *)(param_1 + 0x1ba8) == *(int *)(param_1 + 0x1ba0)) {
    return;
  }
  puVar7 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,2);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar7;
  *puVar7 = ((unsigned char *)0x00001001);
  *(undefined4 *)(*(int *)(FUN_00002748 + param_1 + 4) + 4) = *(undefined4 *)(param_1 + 0x1ba8);
  UNRECOVERED_JUMPTABLE = *(code **)(param_1 + 0x275c);
  *(int *)(FUN_00002748 + param_1 + 4) = *(int *)(FUN_00002748 + param_1 + 4) + 8;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1);
  return;
}

/* FUN_000a43f0 @ 0xa43f0 (148 bytes) */
int FUN_000a43f0(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x2764);
  while (iVar1 != 0) {
    if (*(int *)(iVar1 + 0xbc) != 0) {
      FUN_00030a50(param_1,*(undefined4 *)(*(int *)(iVar1 + 0xbc) + 0x7c));
    }
    iVar2 = *(int *)(iVar1 + 0x138);
    (**(code **)(param_1 + 0x18))(iVar1);
    iVar1 = iVar2;
  }
  *(undefined4 *)(param_1 + 0x2778) = 0;
  *(undefined4 *)(param_1 + 0x2764) = 0;
  *(undefined4 *)(param_1 + 0x2768) = 0;
  return;
}

/* FUN_000a4490 @ 0xa4490 (184 bytes) */
int FUN_000a4490(param_1)
  int param_1;
{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 0x2764); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x138)) {
    if ((*(int *)(iVar1 + 0xbc) != 0) && (-1 < *(int *)(param_1 + 0x276c))) {
      FUN_000309c0(param_1,0);
    }
  }
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x200;
  *(ushort *)(param_1 + 0x32) =
       (ushort)(1 << (*(uint *)(param_1 + 0x276c) & 0x3f)) | *(ushort *)(param_1 + 0x32);
  *(ushort *)(param_1 + 0x34) =
       (ushort)(1 << (*(uint *)(param_1 + 0x276c) & 0x3f)) | *(ushort *)(param_1 + 0x34);
  return;
}

/* FUN_000a4550 @ 0xa4550 (372 bytes) */
int FUN_000a4550(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = *(int *)(((unsigned char *)0x00001154) + param_1);
  uVar1 = *(uint *)(iVar5 + 4);
  if (uVar1 != 0) {
    uVar3 = 0;
    iVar4 = 0;
    do {
      iVar2 = *(int *)(*(int *)(((unsigned char *)0x0000113c) + param_1) * 4 +
                      *(int *)(iVar4 + *(int *)(iVar5 + 0x88) + 0x70));
      if (iVar2 != 0) {
        *(undefined4 *)(((unsigned char *)0x000015cc) + iVar2) = 1;
        uVar1 = *(uint *)(iVar5 + 4);
      }
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 0x78;
    } while (uVar3 < uVar1);
  }
  iVar5 = *(int *)(((unsigned char *)0x0000112c) + param_1);
  uVar1 = *(uint *)(iVar5 + 4);
  if (uVar1 != 0) {
    uVar3 = 0;
    iVar4 = 0;
    do {
      iVar2 = iVar4 + *(int *)(iVar5 + 8);
      if (*(int *)(iVar2 + 4) == 0x8804) {
        iVar2 = *(int *)(*(int *)(((unsigned char *)0x00001130) + param_1) * 4 +
                        *(int *)(*(int *)(iVar2 + 0x14) + 0x70));
        if (iVar2 != 0) {
          *(undefined4 *)(((unsigned char *)0x000015cc) + iVar2) = 1;
          uVar1 = *(uint *)(iVar5 + 4);
        }
      }
      uVar3 = uVar3 + 1;
      iVar4 = iVar4 + 0x18;
    } while (uVar3 < uVar1);
  }
  FUN_0004b190(param_1,0);
  *(uint *)(param_1 + 0x1b50) = (uint)*(ushort *)(param_1 + 0x1b52);
  *(uint *)(param_1 + 0x1a64) = *(uint *)(param_1 + 0x1a64) & 0xffffffef;
  *(uint *)(param_1 + 0x1930) = *(uint *)(param_1 + 0x1930) | 0x2000;
  ((int (*)())FUN_000a4490)(param_1);
  *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x200;
  *(undefined1 *)(param_1 + 0x29) = 1;
  *(ushort *)(param_1 + 0x34) =
       (ushort)(1 << (*(uint *)(param_1 + 0x276c) & 0x3f)) | *(ushort *)(param_1 + 0x34);
  *(undefined4 *)(param_1 + 0x276c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x2768) = 0;
  return;
}

/* FUN_000a46d0 @ 0xa46d0 (144 bytes) */
int FUN_000a46d0(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x2768) != 0) {
    FUN_000309c0(param_1,*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x2768) + 0xbc) + 0x7c),
                 *(undefined4 *)(param_1 + 0x276c));
    *(uint *)(param_1 + 0x38) = *(uint *)(param_1 + 0x38) | 0x200;
    *(ushort *)(param_1 + 0x32) =
         (ushort)(1 << (*(uint *)(param_1 + 0x276c) & 0x3f)) | *(ushort *)(param_1 + 0x32);
    *(ushort *)(param_1 + 0x34) =
         (ushort)(1 << (*(uint *)(param_1 + 0x276c) & 0x3f)) | *(ushort *)(param_1 + 0x34);
  }
  return 1;
}

/* FUN_000a4760 @ 0xa4760 (8 bytes) */
int FUN_000a4760(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x29ac);
}

/* FUN_000a4770 @ 0xa4770 (504 bytes) */
int FUN_000a4770(param_1)
  int param_1;
{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = *(int *)(param_1 + 4);
  iVar6 = *(int *)(param_1 + 8);
  iVar7 = *(int *)(iVar5 + 0x10);
  if (((((unsigned char *)0x00002e2d)[iVar7] == '\0') || ((*(uint *)(param_1 + 0x44) & 0x20000) != 0)) ||
     (iVar5 = FUN_0001a010(iVar5,*(undefined4 *)(((unsigned char *)0x000026a0) + iVar5)), iVar5 != 0)) {
    uVar4 = *(uint *)(((unsigned char *)0x000013e0) + param_1);
    fVar1 = *(float *)(((unsigned char *)0x00002e20) + iVar7);
    if (((float)((double)CONCAT44(0x43300000,uVar4 ^ 0x80000000) - DOUBLE_001aa1e0) < fVar1) &&
       (uVar4 = *(uint *)(((unsigned char *)0x000013e4) + param_1),
       fVar1 < (float)((double)CONCAT44(0x43300000,*(uint *)(((unsigned char *)0x000013e4) + param_1) ^ 0x80000000)
                      - DOUBLE_001aa1e0))) {
      uVar4 = (uint)(fVar1 + FLOAT_001aa10c);
    }
    uVar4 = iVar6 * uVar4 >> 1;
  }
  else {
    fVar1 = *(float *)(((unsigned char *)0x00002e20) + iVar7);
    fVar2 = *(float *)(((unsigned char *)0x000013e8) + param_1);
    fVar3 = fVar2;
    if ((fVar2 < fVar1) &&
       (fVar3 = *(float *)(((unsigned char *)0x000013ec) + param_1), fVar1 < *(float *)(((unsigned char *)0x000013ec) + param_1))) {
      fVar3 = *(float *)(((unsigned char *)0x000013f0) + param_1) *
              (float)((double)CONCAT44(0x43300000,
                                       (int)((fVar1 - fVar2) / *(float *)(((unsigned char *)0x000013f0) + param_1) +
                                            FLOAT_001aa10c) ^ 0x80000000) - DOUBLE_001aa1e0) + fVar2
      ;
    }
    fVar1 = fVar3;
    if (fVar3 - FLOAT_001aa0e8 < 0.0) {
      fVar1 = FLOAT_001aa0e8;
    }
    if (-(fVar3 - FLOAT_001aa0e8) < 0.0) {
      fVar1 = fVar3;
    }
    fVar2 = FLOAT_001aa0e8;
    if (*(short *)(((unsigned char *)0x00002e10) + iVar7) == 0x1102) {
      fVar2 = FLOAT_001aa108;
    }
    uVar4 = (uint)((float)((double)CONCAT44(0x43300000,iVar6) - DOUBLE_001aa250) * FLOAT_001aa10c *
                  (fVar1 + fVar2));
  }
  return uVar4;
}

