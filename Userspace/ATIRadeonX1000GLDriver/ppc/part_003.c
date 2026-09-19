#include "decls.h"

/* FUN_00026650 @ 0x26650 (792 bytes) */
int FUN_00026650(param_1, param_2)
  int param_1;
  int *param_2;
{
  short sVar1;
  uint uVar2;
  short *psVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  
  if (param_2[7] != 0) goto LAB_00026758;
  psVar3 = (short *)*param_2;
  if (psVar3[1] == 0) {
    if ((*psVar3 == -0x79e0) || (*psVar3 == -0x74cf)) {
      iVar4 = 1;
      goto LAB_00026698;
    }
LAB_00026694:
    iVar4 = 0;
  }
  else {
    if (psVar3[1] != 1) goto LAB_00026694;
    sVar1 = *psVar3;
    if ((sVar1 == -0x77fc) || (sVar1 == -0x74d0)) {
      iVar4 = 2;
    }
    else {
      iVar4 = 3;
      if (sVar1 != -0x7e00) goto LAB_00026694;
    }
  }
LAB_00026698:
  param_2[7] = iVar4;
  if (iVar4 == 0) {
    return 0;
  }
  param_2[8] = (int)(param_2 + 8);
  param_2[9] = (int)(param_2 + 8);
  iVar6 = *(int *)(param_1 + 0xc);
  iVar4 = *(int *)(iVar6 + 0x2c);
  param_2[4] = iVar6 + 0x2c;
  param_2[3] = iVar4;
  *(int **)(iVar6 + 0x2c) = param_2 + 3;
  *(int **)(param_2[3] + 4) = param_2 + 3;
LAB_00026758:
  uVar2 = param_2[0xf];
  if (uVar2 != 0) {
    if ((uVar2 & 1) != 0) {
      param_2[5] = param_2[5] + 1;
    }
    if ((uVar2 & 2) != 0) {
      param_2[6] = param_2[6] + 1;
    }
    param_2[0xf] = 0;
  }
  psVar3 = (short *)*param_2;
  if (psVar3[1] == 0) {
    if (*psVar3 == -0x79e0) {
      uVar2 = FUN_00026440(param_1,param_2);
      return uVar2;
    }
    if (*psVar3 == -0x74cf) {
      uVar2 = FUN_00026440(param_1,param_2);
      return uVar2 & 0xff;
    }
  }
  else if (psVar3[1] == 1) {
    sVar1 = *psVar3;
    if (sVar1 == -0x77fc) {
      uVar2 = FUN_00025ec0(param_1,param_2);
      return uVar2;
    }
    if (sVar1 == -0x74d0) {
      uVar2 = FUN_00025ec0(param_1,param_2);
      return uVar2 & 0xff;
    }
    if (sVar1 == -0x7e00) {
      piVar5 = (int *)param_2[9];
      piVar7 = param_2 + 8;
      if (piVar5 == piVar7) {
LAB_0002687c:
        piVar5 = _calloc(1,*(int *)(&DAT_001aa4c4 + param_2[7] * 4) + 0x14);
        piVar5[3] = param_2[5] + -1;
        iVar4 = param_2[6];
        piVar5[2] = param_1;
        piVar5[1] = (int)piVar7;
        piVar5[4] = iVar4 + -1;
        *piVar5 = param_2[8];
        param_2[8] = (int)piVar5;
        *(int **)(*piVar5 + 4) = piVar5;
      }
      else {
        iVar4 = piVar5[2];
        while (iVar4 != param_1) {
          piVar5 = (int *)piVar5[1];
          if (piVar7 == piVar5) goto LAB_0002687c;
          iVar4 = piVar5[2];
        }
      }
      iVar4 = FUN_0003e3a0(param_1 + 0x240,piVar5 + 5);
      if (iVar4 != 0) {
        if (piVar5[3] != param_2[5]) {
          piVar5[3] = param_2[5];
          iVar4 = FUN_0003eb70(param_1 + 0x240,*(undefined4 *)(*param_2 + 4),piVar5 + 5);
          if (iVar4 == 0) {
            return 0;
          }
        }
        *(int **)(param_1 + 0x29ec) = piVar5;
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_000269a0 @ 0x269a0 (516 bytes) */
int FUN_000269a0(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  undefined4 param_3;
  int *param_4;
{
  int *piVar1;
  short *psVar2;
  int iVar3;
  
  _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
  if (((param_2 != (int *)0x0) && (*param_2 != 0)) && (*(int *)(*param_2 + 4) != 0)) {
    FUN_0000a820(param_1,0xffff);
    FUN_000a7ee0(param_1,0xffff);
    ((int (*)())FUN_00026650)(param_1,param_2);
    psVar2 = (short *)*param_2;
    if (psVar2[1] == 0) {
      if (*psVar2 == -0x79e0) {
        for (piVar1 = (int *)param_2[9]; piVar1 != param_2 + 8; piVar1 = (int *)piVar1[1]) {
          if (param_1 == piVar1[2]) goto LAB_00026ae0;
        }
        piVar1 = _calloc(1,*(int *)(&DAT_001aa4c4 + param_2[7] * 4) + 0x14);
        piVar1[3] = param_2[5] + -1;
        iVar3 = param_2[6];
        piVar1[2] = param_1;
        piVar1[1] = (int)(param_2 + 8);
        piVar1[4] = iVar3 + -1;
        *piVar1 = param_2[8];
        param_2[8] = (int)piVar1;
        *(int **)(*piVar1 + 4) = piVar1;
LAB_00026ae0:
        switch(param_3) {
        case 0x88a2:
          *param_4 = piVar1[0x23];
          break;
        case 0x88a6:
          *param_4 = piVar1[0x25];
          break;
        case 0x88aa:
          *param_4 = piVar1[0x24];
          break;
        case 0x88ae:
          *param_4 = piVar1[0x26];
          break;
        case 0x88b2:
          *param_4 = piVar1[0x27];
        }
      }
    }
    else if (((psVar2[1] == 1) && (*psVar2 != -0x7e00)) && (*psVar2 == -0x77fc)) {
      FUN_000a05f0(param_1 + 0x240,0x8804,param_3,param_4);
    }
  }
  _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
  return;
}

/* FUN_00027990 @ 0x27990 (2360 bytes) */
int FUN_00027990(param_1)
  int param_1;
{
  bool bVar1;
  bool bVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  ushort uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  uint *puVar19;
  uint uVar20;
  ushort uVar21;
  uint uVar22;
  undefined1 *puVar23;
  undefined1 *puVar24;
  int iVar25;
  uint uVar26;
  int iVar27;
  int iVar28;
  int iVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  int iVar33;
  int iVar34;
  uint uVar35;
  int local_74;
  uint local_70;
  int local_68;
  int local_64;
  int local_60;
  
  *(int *)(param_1 + 0x2440) = param_1 + 0x249c;
  *(int *)(param_1 + 0x2444) = param_1 + 0x24bc;
  *(undefined4 *)(param_1 + 0x2494) = 0;
  iVar33 = *(int *)(param_1 + 4);
  uVar31 = *(uint *)(param_1 + 0x243c);
  if ((((*(char *)(iVar33 + 0x20) == '\0') ||
       (*(int *)(((unsigned char *)0x00003170) + *(int *)(iVar33 + 0x10)) != 0x1b021b02)) || (uVar31 < 2)) ||
     (0x10 < uVar31)) {
    if ((*(int *)(*(int *)(iVar33 + 0x14) + 0x11c) == 0) &&
       (*(int *)(*(int *)(iVar33 + 0x14) + 0x120) == 0)) {
      return;
    }
switchD_00027e30_default:
    *(uint *)(param_1 + 0x2488) = *(uint *)(param_1 + 0x2488) | 2;
    *(undefined4 *)(*(int *)(iVar33 + 0x14) + 0x11c) = 0;
    *(undefined4 *)(*(int *)(iVar33 + 0x14) + 0x120) = 0;
    return;
  }
  if (*(int **)(iVar33 + 0x1cc) == (int *)0x0) {
    iVar29 = 0;
    local_68 = 0;
    local_64 = 0;
    local_60 = 0;
  }
  else {
    local_64 = *(int *)(**(int **)(iVar33 + 0x1cc) + 4);
    iVar29 = *(int *)(iVar33 + 0x29e8) + 0x14;
    local_60 = *(int *)(*(int *)(iVar33 + 0x29e8) + 0x34);
    local_68 = *(int *)(local_64 + 0x24);
  }
  puVar24 = *(undefined1 **)(param_1 + 0x258c);
  iVar8 = **(int **)(*(int *)(iVar33 + 0x18) + 0x194);
  *(undefined1 **)(*(int *)(iVar33 + 0x14) + 0x11c) = puVar24;
  puVar23 = *(undefined1 **)(param_1 + 0x2590);
  *(undefined1 **)(*(int *)(iVar33 + 0x14) + 0x120) = puVar23;
  if (*(char *)(param_1 + 0x2595) != '\0') {
    *(undefined4 *)(*(int *)(iVar33 + 0x14) + 0x120) = 0;
  }
  *(uint *)(param_1 + 0x2488) = *(uint *)(param_1 + 0x2488) | 2;
  iVar16 = param_1;
  for (uVar35 = uVar31 + 1 >> 1; uVar35 != 0; uVar35 = uVar35 - 1) {
    uVar7 = *(undefined4 *)(iVar16 + 0x1be4);
    uVar9 = *(undefined4 *)(iVar16 + 0x1c04);
    *(undefined4 *)(((unsigned char *)0x000026a4) + iVar16) = uVar7;
    *(undefined4 *)(((unsigned char *)0x000026c4) + iVar16) = uVar9;
    *(undefined4 *)(iVar16 + 0x2600) = uVar7;
    *(undefined4 *)(iVar16 + 0x2620) = uVar9;
    iVar16 = iVar16 + 4;
  }
  *(undefined4 *)(((unsigned char *)0x000026a0) + param_1) = *(undefined4 *)(param_1 + 0x1ca4);
  *(uint *)(param_1 + 0x25fc) = uVar31 & 0x1f | 0x20;
  if (*(int *)(iVar33 + 0x1cc) == 0) {
    iVar16 = *(int *)(param_1 + 4);
  }
  else {
    iVar16 = *(int *)(param_1 + 4);
    uVar35 = 0;
    iVar18 = 0;
    iVar12 = 0x16;
    bVar1 = *(int *)(iVar16 + 0x1cc) == 0;
    do {
      if (bVar1) {
        if ((1 << (uVar35 & 0x3f) & *(uint *)(param_1 + 0x1ca0)) != 0) goto LAB_00027b90;
      }
      else if ((*(int *)(iVar18 + *(int *)(iVar29 + 0x20)) != 0x80) ||
              (*(uint *)(iVar29 + 0x1c) <= uVar35)) {
LAB_00027b90:
        if (bVar1) {
          iVar34 = *(int *)(iVar18 + 0x1d9e58);
        }
        else {
          if (*(uint *)(iVar29 + 0x1c) <= uVar35) goto switchD_00027c3c_default;
          iVar34 = (local_68 + *(int *)(local_60 + iVar18)) * 8;
          uVar26 = *(uint *)(local_64 + iVar34);
          puVar19 = (uint *)(local_64 + iVar34);
          iVar34 = *(int *)(&DAT_001d9eb0 + (uVar26 >> 0xe & 0x3c));
          if (iVar34 == 8) {
            iVar34 = (uVar26 & 0x1f) + 8;
          }
          else if (iVar34 == 0x10) {
            iVar34 = (uVar26 & 0x1f) + 0x10;
          }
          else if (iVar34 == 0x2f) {
            switch(uVar26 >> 0xc & 0xf) {
            case 0:
              iVar34 = (*puVar19 & 1) + 0x20;
              break;
            case 1:
              iVar34 = (*puVar19 & 1) + 0x22;
              break;
            case 2:
              iVar34 = (*puVar19 & 1) + 0x24;
              break;
            case 3:
              iVar34 = (*puVar19 & 1) + 0x26;
              break;
            case 4:
              iVar34 = (*puVar19 & 1) + 0x28;
              break;
            default:
              goto switchD_00027c3c_default;
            }
          }
        }
        if ((iVar34 == 0) || (iVar34 == 0x10)) {
          bVar1 = true;
          goto LAB_00027d04;
        }
      }
switchD_00027c3c_default:
      iVar12 = iVar12 + -1;
      uVar35 = uVar35 + 1;
      iVar18 = iVar18 + 4;
    } while (iVar12 != 0);
  }
  bVar1 = false;
LAB_00027d04:
  iVar27 = 0;
  local_70 = 0;
  uVar35 = 0;
  iVar25 = 0;
  local_74 = 1;
  iVar34 = 0x16;
  uVar26 = 0;
  iVar12 = 0;
  uVar32 = 0;
  iVar28 = 0;
  iVar18 = param_1;
LAB_00027d44:
  bVar2 = *(int *)(iVar16 + 0x1cc) == 0;
  if (bVar2) {
    if ((1 << (uVar26 & 0x3f) & *(uint *)(param_1 + 0x1ca0)) != 0) goto LAB_00027d90;
    goto LAB_00028214;
  }
  if ((*(int *)(iVar28 + *(int *)(iVar29 + 0x20)) == 0x80) && (uVar26 < *(uint *)(iVar29 + 0x1c)))
  goto LAB_00028214;
LAB_00027d90:
  if (bVar2) {
    uVar14 = *(uint *)(iVar28 + 0x1d9e58);
LAB_00027eac:
    if (uVar14 == 0x30) goto switchD_00027e30_default;
    uVar22 = uVar14 & 0xffff;
  }
  else {
    if (uVar26 < *(uint *)(iVar29 + 0x1c)) {
      iVar16 = (local_68 + *(int *)(local_60 + iVar28)) * 8;
      uVar22 = *(uint *)(local_64 + iVar16);
      puVar19 = (uint *)(local_64 + iVar16);
      uVar14 = *(uint *)(&DAT_001d9eb0 + (uVar22 >> 0xe & 0x3c));
      if (uVar14 == 8) {
        uVar14 = (uVar22 & 0x1f) + 8;
      }
      else if (uVar14 == 0x10) {
        uVar14 = (uVar22 & 0x1f) + 0x10;
      }
      else if (uVar14 == 0x2f) {
        switch(uVar22 >> 0xc & 0xf) {
        case 0:
          uVar14 = (*puVar19 & 1) + 0x20;
          break;
        case 1:
          uVar14 = (*puVar19 & 1) + 0x22;
          break;
        case 2:
          uVar14 = (*puVar19 & 1) + 0x24;
          break;
        case 3:
          uVar14 = (*puVar19 & 1) + 0x26;
          break;
        case 4:
          uVar14 = (*puVar19 & 1) + 0x28;
          break;
        default:
          goto switchD_00027e30_default;
        }
      }
      goto LAB_00027eac;
    }
    uVar14 = 2;
    uVar22 = 2;
  }
  if ((bVar1) && ((uVar14 == 0 || (iVar12 = local_74, uVar14 == 0x10)))) {
    iVar12 = 0;
  }
  uVar10 = uVar32 >> 1;
  if (bVar2) {
    uVar20 = *(uint *)(iVar28 + 0x1d9edc) & 0xffff;
  }
  else {
    uVar20 = 3;
  }
  bVar2 = (uVar32 & 1) == 0;
  if (bVar2) {
    iVar16 = uVar10 * 4 + param_1;
    *(uint *)(iVar16 + 0x2640) = (uVar31 & 0x1f) << 10 | *(uint *)(iVar16 + 0x2640) & 0xffff8080 | 4
    ;
  }
  else {
    iVar16 = uVar10 * 4 + param_1;
    *(uint *)(iVar16 + 0x2640) =
         (uVar31 & 0x1f) << 0x1a | *(uint *)(iVar16 + 0x2640) & 0x8080ffff | 0x40000;
  }
  iVar16 = uVar10 * 4;
  uVar6 = (ushort)(uVar22 << 10);
  uVar21 = (ushort)(uVar20 << 8) | uVar6;
  *(int *)(uVar32 * 4 + param_1 + 0x2660) = iVar27;
  *(ushort *)(puVar24 + iVar12 * 2 + 4) = uVar21 | (ushort)iVar27;
  if (*(char *)(param_1 + 0x2595) == '\0') {
    uVar3 = *(ushort *)(uVar14 * 0x18 + iVar8 + 8);
    if (uVar14 < 0x10) {
      uVar35 = *(uint *)(iVar8 + 0x304);
    }
    else {
      uVar35 = *(uint *)(iVar8 + 0x300);
    }
    if ((uVar35 & *(uint *)(&DAT_001d9dd8 + uVar14 * 4)) == 0) {
      uVar35 = 4;
      uVar17 = 4;
      uVar22 = 3;
      uVar20 = 0;
      uVar14 = 0;
      uVar11 = 0;
      uVar13 = 1;
      uVar15 = 2;
      uVar30 = 3;
      uVar10 = 0;
    }
    else {
      iVar4 = ((uVar3 & 0xffff7fff) - 0x1400) * 4;
      iVar5 = (iVar4 + *(short *)(uVar14 * 0x18 + iVar8 + 10) + -1) * 4;
      uVar35 = *(uint *)(&DAT_001d9c4c + iVar5);
      uVar21 = (ushort)(*(int *)(&DAT_001d9cfc + iVar5) << 8) | uVar6;
      uVar14 = (uint)(uVar3 >> 0xf);
      uVar22 = *(uint *)(&DAT_001d9b9c + iVar5) & 0xff;
      uVar10 = *(uint *)(&DAT_001d9dac + iVar4) & 0xffff;
      uVar20 = *(uint *)(&DAT_001d9b70 + iVar4) & 0xff;
      uVar11 = *(uint *)(&DAT_001d9ac0 + iVar5) & 0xff;
      uVar17 = uVar35 & 0xff;
      uVar13 = *(uint *)(&DAT_001d9a10 + iVar5) & 0xff;
      uVar15 = *(uint *)(&DAT_001d9960 + iVar5) & 0xff;
      uVar30 = *(uint *)(&DAT_001d98b0 + iVar5) & 0xff;
    }
    if (bVar2) {
      *(uint *)(((unsigned char *)0x000026e4) + iVar16 + param_1) =
           uVar17 & 0x7f | *(uint *)(((unsigned char *)0x000026e4) + iVar16 + param_1) & 0xffffff80;
    }
    else {
      *(uint *)(((unsigned char *)0x000026e4) + iVar16 + param_1) =
           (uVar17 & 0x7f) << 0x10 | *(uint *)(((unsigned char *)0x000026e4) + iVar16 + param_1) & 0xff80ffff;
    }
    *(int *)(((unsigned char *)0x00002704) + uVar32 * 4 + param_1) = iVar25;
    if (bVar2) {
      iVar16 = iVar16 + param_1;
      *(uint *)(((unsigned char *)0x000026a4) + iVar16) =
           uVar14 << 0xf |
           (uVar20 & 1) << 0xe | uVar22 & 0xf | *(uint *)(((unsigned char *)0x000026a4) + iVar16) & 0xffff3ff0;
      *(uint *)(((unsigned char *)0x000026c4) + iVar16) =
           (uVar30 & 7) << 9 |
           (uVar15 & 7) << 6 |
           (uVar13 & 7) << 3 | uVar11 & 7 | *(uint *)(((unsigned char *)0x000026c4) + iVar16) & 0xfffff000;
    }
    else {
      iVar16 = iVar16 + param_1;
      *(uint *)(((unsigned char *)0x000026a4) + iVar16) =
           uVar14 << 0x1f |
           (uVar20 & 1) << 0x1e |
           (uVar22 & 0xf) << 0x10 | *(uint *)(((unsigned char *)0x000026a4) + iVar16) & 0x3ff0ffff;
      *(uint *)(((unsigned char *)0x000026c4) + iVar16) =
           (uVar30 & 7) << 0x19 |
           (uVar15 & 7) << 0x16 |
           (uVar13 & 7) << 0x13 |
           (uVar11 & 7) << 0x10 | *(uint *)(((unsigned char *)0x000026c4) + iVar16) & 0xf000ffff;
    }
    *(ushort *)(puVar23 + iVar12 * 2 + 4) = uVar21 | (ushort)(uVar10 << 6) | (ushort)iVar25;
  }
  *(uint *)(iVar18 + 0x259c) = uVar32;
  iVar27 = iVar27 + 4;
  iVar25 = iVar25 + uVar35;
  uVar32 = uVar32 + 1;
  local_70 = local_70 + uVar35;
  if (!bVar1) {
    iVar12 = iVar12 + 1;
  }
  else if (iVar12 != 0) {
    local_74 = local_74 + 1;
  }
LAB_00028214:
  if (uVar32 == uVar31) {
LAB_00028238:
    if (*(char *)(param_1 + 0x2595) == '\0') {
      uVar26 = 0;
      bVar1 = false;
      *(uint *)(param_1 + 0x2744) = local_70 & 0x7f | *(uint *)(param_1 + 0x2744) & 0xffffff80;
      uVar35 = uVar31;
      do {
        if (bVar1) {
          iVar29 = (uVar26 & 0x7ffffffe) * 2 + param_1;
          *(uint *)(((unsigned char *)0x000026e4) + iVar29) =
               (local_70 & 0x7f) << 0x18 | *(uint *)(((unsigned char *)0x000026e4) + iVar29) & 0x80ffffff;
        }
        else {
          iVar29 = (uVar26 & 0x7ffffffe) * 2 + param_1;
          *(uint *)(((unsigned char *)0x000026e4) + iVar29) =
               (local_70 & 0x7f) << 8 | *(uint *)(((unsigned char *)0x000026e4) + iVar29) & 0xffff80ff;
        }
        uVar26 = uVar26 + 1;
        bVar1 = (bool)(bVar1 ^ 1);
        uVar35 = uVar35 - 1;
      } while (uVar35 != 0);
    }
    *puVar24 = (char)uVar31;
    *puVar23 = (char)uVar31;
    puVar24[1] = 0;
    puVar23[1] = 0;
    puVar24[2] = (char)(uVar31 << 2);
    puVar23[2] = (char)local_70;
    if (*(char *)(iVar33 + 8) == ' ') {
      uVar35 = 0x20;
      if (7 < uVar31 << 2) {
        puVar24[1] = puVar24[1] | 0x40;
        uVar35 = (uint)*(byte *)(iVar33 + 8);
      }
      if (uVar35 >> 2 <= local_70) {
        puVar23[1] = puVar23[1] | 0x40;
      }
    }
    *(uint *)(param_1 + 0x2598) = *(uint *)(param_1 + 0x2598) & 0xffffffe7;
    return;
  }
  uVar26 = uVar26 + 1;
  iVar28 = iVar28 + 4;
  iVar18 = iVar18 + 4;
  iVar34 = iVar34 + -1;
  if (iVar34 == 0) goto LAB_00028238;
  iVar16 = *(int *)(param_1 + 4);
  goto LAB_00027d44;
}

/* FUN_00028350 @ 0x28350 (3820 bytes) */
int FUN_00028350(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  undefined *param_7;
  int param_8;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  uint uVar9;
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
  double dVar21;
  undefined *puVar22;
  uint uVar23;
  uint *puVar24;
  int *piVar25;
  int iVar26;
  undefined4 uVar27;
  uint *puVar28;
  undefined4 *puVar29;
  uint uVar30;
  int iVar31;
  undefined4 *puVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  int iVar36;
  int iVar37;
  int iVar38;
  char in_RESERVE;
  byte bVar39;
  int iVar40;
  undefined4 *in_stack_0000003c;
  uint local_108;
  undefined1 auStack_104 [4];
  int local_100 [2];
  undefined4 local_f8;
  uint uStack_f4;
  undefined4 local_f0;
  uint uStack_ec;
  undefined4 local_e8;
  uint uStack_e4;
  undefined4 local_e0;
  uint uStack_dc;
  undefined4 local_d8;
  uint uStack_d4;
  undefined4 local_d0;
  uint uStack_cc;
  undefined4 local_c8;
  uint uStack_c4;
  undefined4 local_c0;
  uint uStack_bc;
  undefined4 local_b8[0];
  uint uStack_b4;
  undefined4 local_b0;
  uint uStack_ac;
  undefined4 local_a8;
  uint uStack_a4;
  longlong local_a0;
  longlong local_98;
  
  bVar39 = (param_6 == 0x1909) << 1;
  uVar35 = param_6;
  FUN_001a324c();
  if ((bool)(bVar39 >> 1 & 1)) {
    iVar38 = 1;
    if (param_7 != ((unsigned char *)0x00001401)) {
      iVar38 = 0x13;
      if ((param_7 == ((unsigned char *)0x00001406)) || (iVar38 = 0x1f, param_7 == ((unsigned char *)0x0000140b)))
      goto LAB_000284b0;
      iVar38 = 0;
      if (param_7 == ((unsigned char *)0x00001403)) {
        iVar38 = 0x19;
        goto LAB_000284b0;
      }
    }
  }
  else if (uVar35 < 0x190a) {
    if (uVar35 == 0x1907) {
      iVar38 = 5;
      if ((param_7 != (undefined *)0x8363) && (iVar38 = 0x28, param_7 != (undefined *)0x8032)) {
        return 0;
      }
      goto LAB_000284b0;
    }
    if (uVar35 < 0x1908) {
      if (uVar35 != 0x1906) {
        return 0;
      }
      iVar38 = 2;
      if (param_7 != ((unsigned char *)0x00001401)) {
        iVar38 = 0x14;
        if ((param_7 == ((unsigned char *)0x00001406)) || (iVar38 = 0x20, param_7 == ((unsigned char *)0x0000140b)))
        goto LAB_000284b0;
        iVar38 = 0;
        if (param_7 == ((unsigned char *)0x00001403)) {
          iVar38 = 0x1a;
          goto LAB_000284b0;
        }
      }
      goto LAB_000283c0;
    }
    iVar38 = 0x12;
    if (param_7 == ((unsigned char *)0x00001406)) {
LAB_00028524:
      if (param_7 != (undefined *)0x8367) {
        if (param_7 == ((unsigned char *)0x00001401)) {
          iVar38 = 9;
          goto LAB_000284b0;
        }
        goto LAB_00028510;
      }
      iVar38 = 10;
    }
    else {
      iVar38 = 0x1e;
      if (param_7 != ((unsigned char *)0x0000140b)) {
        iVar38 = 0;
        if (param_7 != (undefined *)0x8035) goto LAB_00028524;
        iVar38 = 9;
      }
LAB_00028510:
      if (param_7 == (undefined *)0x8368) {
        iVar38 = 0x23;
        goto LAB_000284b0;
      }
    }
    if (param_7 == ((unsigned char *)0x00001403)) {
      iVar38 = 0x18;
      goto LAB_000284b0;
    }
  }
  else {
    if (uVar35 != 0x80e1) {
      if (uVar35 == 0x85b9) {
        iVar38 = 0x27;
        if ((param_7 != (undefined *)0x85ba) && (iVar38 = 0x26, param_7 != (undefined *)0x85bb)) {
          return 0;
        }
        goto LAB_000284b0;
      }
      if (uVar35 != 0x190a) {
        return 0;
      }
      iVar38 = 4;
      if (param_7 != ((unsigned char *)0x00001401)) {
        if (param_7 == ((unsigned char *)0x00001406)) {
          iVar38 = 0x16;
          goto LAB_000284b0;
        }
        iVar38 = 0x22;
        if (param_7 == ((unsigned char *)0x0000140b)) goto LAB_000284b0;
        iVar38 = 0;
        if (param_7 == ((unsigned char *)0x00001403)) {
          iVar38 = 0x1c;
          goto LAB_000284b0;
        }
      }
      goto LAB_000283c0;
    }
    iVar38 = 7;
    if (param_7 == (undefined *)0x8366) {
LAB_00028460:
      if (param_7 != (undefined *)0x8035) {
LAB_00028428:
        if (param_7 == ((unsigned char *)0x00001401)) {
          iVar38 = 8;
          goto LAB_000283c0;
        }
        goto LAB_0002844c;
      }
      iVar38 = 8;
LAB_00028474:
      if (param_7 == ((unsigned char *)0x00001406)) {
        iVar38 = 0x11;
        goto LAB_000284b0;
      }
      if (param_7 == ((unsigned char *)0x0000140b)) {
        iVar38 = 0x1d;
        goto LAB_000284b0;
      }
    }
    else {
      if (param_7 == (undefined *)0x8365) {
        iVar38 = 6;
        goto LAB_00028428;
      }
      iVar38 = 0;
      if (param_7 != (undefined *)0x8367) goto LAB_00028460;
      iVar38 = 0xb;
LAB_0002844c:
      if (param_7 != (undefined *)0x8368) goto LAB_00028474;
      iVar38 = 0x24;
    }
    if (param_7 == ((unsigned char *)0x00001403)) {
      iVar38 = 0x17;
      goto LAB_000284b0;
    }
  }
LAB_000283c0:
  if (iVar38 == 0) {
    return 0;
  }
LAB_000284b0:
  if ((((0x1000 < (int)param_4) || (0x1000 < (int)param_5)) || (0x1000 < *(int *)(param_1 + 0x15c)))
     || (0x1000 < *(int *)(param_1 + 0x160))) {
    return 0;
  }
  _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
  FUN_0000a6e0(param_1,param_6,param_7,param_4,param_5,&local_108,auStack_104,local_100);
  uVar35 = param_8 + local_100[0];
  if ((int)param_4 < 1) {
    uVar33 = 1;
    fVar7 = FLOAT_001aa0e8;
  }
  else {
    uStack_f4 = param_4 ^ 0x80000000;
    local_f8 = 0x43300000;
    fVar7 = (float)((double)CONCAT44(0x43300000,uStack_f4) - DOUBLE_001aa1e0);
    uVar33 = param_4;
  }
  if ((int)param_5 < 1) {
    uVar34 = 1;
    fVar2 = FLOAT_001aa0e8;
  }
  else {
    uStack_ec = param_5 ^ 0x80000000;
    local_f0 = 0x43300000;
    fVar2 = (float)((double)CONCAT44(0x43300000,uStack_ec) - DOUBLE_001aa1e0);
    uVar34 = param_5;
  }
  uStack_e4 = param_2 ^ 0x80000000;
  uStack_ac = param_5 + param_3 ^ 0x80000000;
  uStack_b4 = param_3 ^ 0x80000000;
  local_b0 = 0x43300000;
  local_e8 = 0x43300000;
  local_e0 = 0x43300000;
  local_b8[0] = 0x43300000;
  uStack_c4 = -param_2 ^ 0x80000000;
  uStack_bc = uVar34 - param_3 ^ 0x80000000;
  uStack_dc = param_4 + param_2 ^ 0x80000000;
  local_d8 = 0x43300000;
  local_d0 = 0x43300000;
  local_c8 = 0x43300000;
  local_c0 = 0x43300000;
  uStack_d4 = *(uint *)(param_1 + 0x15c) ^ 0x80000000;
  uStack_cc = *(uint *)(param_1 + 0x160) ^ 0x80000000;
  fVar13 = (float)((double)CONCAT44(0x43300000,uStack_e4) - DOUBLE_001aa1e0) + FLOAT_001aa0d4;
  fVar11 = fVar2 - (float)((double)CONCAT44(0x43300000,uStack_ac) - DOUBLE_001aa1e0);
  fVar14 = (float)((double)CONCAT44(0x43300000,uStack_dc) - DOUBLE_001aa1e0) + FLOAT_001aa0d4;
  fVar17 = fVar13;
  if (fVar13 < 0.0) {
    fVar17 = FLOAT_001aa0d4;
  }
  fVar3 = (float)((double)CONCAT44(0x43300000,uStack_c4) - DOUBLE_001aa1e0);
  fVar4 = (float)((double)CONCAT44(0x43300000,uStack_bc) - DOUBLE_001aa1e0);
  fVar5 = (float)((double)CONCAT44(0x43300000,uStack_d4) - DOUBLE_001aa1e0);
  fVar6 = (float)((double)CONCAT44(0x43300000,uStack_cc) - DOUBLE_001aa1e0);
  fVar16 = FLOAT_001aa0d4;
  if (-fVar13 < 0.0) {
    fVar16 = fVar17;
  }
  fVar13 = fVar2 - (float)((double)CONCAT44(0x43300000,uStack_b4) - DOUBLE_001aa1e0);
  fVar17 = FLOAT_001aa0d4;
  fVar18 = FLOAT_001aa148;
  if (FLOAT_001aa0d4 < fVar11) {
    fVar17 = fVar11;
    fVar18 = -fVar11;
  }
  fVar10 = fVar5 - fVar14;
  fVar11 = fVar6 - fVar13;
  fVar18 = fVar4 + fVar18;
  fVar20 = fVar16 + fVar3;
  if (fVar10 < 0.0) {
    fVar14 = fVar5;
  }
  if (fVar11 < 0.0) {
    fVar13 = fVar6;
  }
  fVar15 = fVar18 - fVar2;
  fVar12 = fVar20;
  if (fVar20 < 0.0) {
    fVar12 = FLOAT_001aa0d4;
  }
  fVar19 = fVar5;
  if (-fVar10 < 0.0) {
    fVar19 = fVar14;
  }
  fVar14 = fVar2;
  if (fVar15 < 0.0) {
    fVar14 = fVar18;
  }
  fVar18 = fVar6;
  if (-fVar11 < 0.0) {
    fVar18 = fVar13;
  }
  fVar11 = FLOAT_001aa0d4;
  if (-fVar20 < 0.0) {
    fVar11 = fVar12;
  }
  fVar3 = fVar19 + fVar3;
  if (-fVar15 < 0.0) {
    fVar14 = fVar2;
  }
  fVar4 = fVar4 - fVar18;
  fVar2 = fVar3 - fVar7;
  fVar13 = fVar4;
  if (fVar4 < 0.0) {
    fVar13 = FLOAT_001aa0d4;
  }
  fVar10 = fVar7;
  if (fVar2 < 0.0) {
    fVar10 = fVar3;
  }
  fVar3 = FLOAT_001aa0d4;
  if (-fVar4 < 0.0) {
    fVar3 = fVar13;
  }
  if (-fVar2 < 0.0) {
    fVar10 = fVar7;
  }
  if ((fVar10 <= fVar11) || (fVar14 <= fVar3)) {
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    return 1;
  }
  if (((((*(int *)in_stack_0000003c[1] != 0) &&
        (iVar26 = FUN_0001e280(param_1,in_stack_0000003c,1), iVar26 == 0)) ||
       ((puVar22 = PTR_DAT_001e88c8, (int *)in_stack_0000003c[2] == (int *)0x0 ||
        ((iVar26 = *(int *)in_stack_0000003c[2], iVar26 == 0 ||
         (uVar30 = *(uint *)*in_stack_0000003c, uVar35 != uVar30)))))) ||
      ((*(char *)(iVar26 + 0x16) != '\x06' && ((param_6 != 0x1908 || (param_7 != ((unsigned char *)0x00001406)))))))
     || (((uVar35 | local_108) & 0x1f) != 0)) {
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    return 0;
  }
  if (uVar30 != 0) {
    FUN_0000b670(param_1,uVar30,uVar34 * local_108);
  }
  iVar37 = param_1 + 0x240;
  iVar36 = 0xf;
  uVar27 = (**(code **)(param_1 + 0x2998))(iVar37,0x343);
  *(undefined4 *)(param_1 + 0x298c) = uVar27;
  iVar26 = param_1;
  do {
    if (*(int *)(iVar26 + 0x1c8) != 0) {
      uVar27 = ((int (*)())FUN_0002cd50)(param_1,0,iVar36,uVar27);
    }
    iVar36 = iVar36 + -1;
    bVar39 = (iVar36 == 0) << 1;
    iVar26 = iVar26 + -4;
  } while (iVar36 != 0);
  puVar28 = (uint *)((int (*)())FUN_0002cd50)(param_1,0,0,uVar27);
  puVar29 = (undefined4 *)((uint)(puVar28 + 0xb) & 0xffffffe0);
  *puVar28 = (((int)puVar29 - (int)puVar28) + -8) * 0x4000 | 0xc0001000;
  puVar29[-1] = (int)puVar29 - (int)puVar28;
  puVar24 = *(uint **)(param_1 + 0x1d8);
  *puVar24 = (int)puVar29 - (int)puVar24 >> 2 | *puVar24;
  *(undefined4 **)(param_1 + 0x1d8) = puVar29;
  *puVar29 = 0x40000000;
  puVar32 = *(undefined4 **)in_stack_0000003c[2];
  piVar25 = puVar32 + 4;
  do {
    if (in_RESERVE != '\0') {
      iVar26 = storeWordConditionalIndexed(*piVar25 + 0x10000,0,piVar25);
      *piVar25 = iVar26;
      bVar39 = 2;
    }
  } while (!(bool)(bVar39 >> 1 & 1));
  puVar29[2] = *puVar32;
  puVar29[3] = uVar35 - *(int *)*in_stack_0000003c;
  uVar27 = FUN_0000a2f0(*(undefined2 *)(((unsigned char *)0x00002db8) + *(int *)(param_1 + 0x10)),
                        *(undefined4 *)(param_1 + 0x154));
  puVar29[4] = uVar27;
  _memcpy(puVar29 + 5,PTR_DAT_001e88d0,0x2f4);
  puVar29[0x23] = 0;
  puVar29[0x9f] = 0;
  uVar23 = puVar29[0x8f];
  puVar29[0xa1] =
       param_4 & 0x3ffe | *(uint *)(puVar22 + iVar38 * 0x24 + 0x18) >> 0xb & 0x180000 |
       (*(uint *)(puVar22 + iVar38 * 0x24 + 0x18) & 0x3c00) << 0xb;
  uVar35 = *(uint *)(puVar22 + iVar38 * 0x24 + 0x18) >> 5 & 0x1f;
  puVar29[0x8f] = uVar35 | uVar23 & 0xffffffe0;
  uVar30 = (*(uint *)(puVar22 + iVar38 * 0x24 + 0x18) & 0x18) << 5;
  puVar29[0x8f] = uVar30 | uVar35 | uVar23 & 0xfffffce0;
  uVar8 = (*(uint *)(puVar22 + iVar38 * 0x24 + 0x18) & 6) << 9;
  puVar29[0x8f] = uVar8 | uVar30 | uVar35 | uVar23 & 0xfffff0e0;
  uVar9 = *(uint *)(puVar22 + iVar38 * 0x24 + 0x1c) >> 0x12 & 0x3000;
  puVar29[0x8f] = uVar9 | uVar8 | uVar30 | uVar35 | uVar23 & 0xffffc0e0;
  puVar29[0x8f] =
       *(uint *)(puVar22 + iVar38 * 0x24 + 0x1c) >> 0xe & 0xc000 |
       uVar9 | uVar8 | uVar30 | uVar35 | uVar23 & 0xffff00e0;
  if ((*(uint *)(puVar22 + iVar38 * 0x24 + 0x14) & 0xfc000000) == 0) {
    puVar29[0x5b] = puVar29[0x5b] & 0xfffe3fff | 0x18000;
  }
  uStack_a4 = param_5 ^ 0x80000000;
  puVar29[0xb8] = uVar33 - 1 & 0x1fff | (uVar34 - 1) * 0x2000 & 0x3ffe000;
  dVar21 = DOUBLE_001aa1e0;
  fVar4 = FLOAT_001aa12c;
  fVar13 = FLOAT_001aa10c;
  local_a8 = 0x43300000;
  puVar32 = puVar29 + 0xce;
  fVar5 = FLOAT_001aa0e8 / fVar5;
  fVar2 = FLOAT_001aa0e8 / fVar6;
  puVar29[0xc2] = 0x31080;
  puVar29[199] = ((unsigned char *)0x00001087);
  fVar7 = (float)((double)CONCAT44(0x43300000,uStack_a4) - dVar21);
  puVar29[0xc5] = fVar19 * fVar5;
  puVar29[0xc3] = fVar16 * fVar5;
  puVar29[0xc6] = fVar2 * (fVar6 - fVar17);
  fVar3 = fVar7 - fVar3;
  puVar29[0xc4] = fVar2 * (fVar6 - fVar18);
  fVar7 = fVar7 - fVar14;
  iVar38 = (int)((fVar10 - fVar11) * fVar4);
  local_a0 = (longlong)iVar38;
  uVar35 = (uint)((fVar3 - fVar7) * fVar4);
  local_98 = (longlong)(int)uVar35;
  puVar29[0xc9] = 0xc0033500;
  puVar29[0xca] = 0x10031;
  puVar29[0xcb] = (fVar11 + fVar10) * fVar13;
  puVar29[0xcc] = (fVar7 + fVar3) * fVar13;
  puVar29[0xcd] = 0;
  puVar29[200] = iVar38 << 0x10 | uVar35;
  puVar29[1] = (int)puVar32 - (int)puVar28 >> 2;
  puVar24 = *(uint **)(param_1 + 0x1d8);
  *puVar24 = (int)puVar32 - (int)puVar24 >> 2 | *puVar24;
  *(undefined4 **)(param_1 + 0x1d8) = puVar32;
  puVar29[0xce] = 0x33000000;
  puVar29[0xcf] = 0;
  puVar29[0xd1] = 10;
  puVar29[0xd0] = ((unsigned char *)0x00001393);
  puVar29[0xd2] = ((unsigned char *)0x000013c6);
  puVar29[0xd3] = 3;
  puVar29[0xd4] = 0x5c8;
  puVar29[0xd5] = 0x20000;
  puVar29[0xd6] = ((unsigned char *)0x000010ea);
  uVar27 = *(undefined4 *)(param_1 + 0x1cfc);
  puVar29[0xd8] = ((unsigned char *)0x000010fa);
  puVar29[0xd7] = uVar27;
  uVar27 = *(undefined4 *)(((unsigned char *)0x00001da0) + param_1);
  puVar29[0xda] = 0xc0001000;
  puVar29[0xdc] = 0x11004;
  puVar29[0xd9] = uVar27;
  puVar29[0xdd] = *(undefined4 *)(param_1 + 0x1ca8);
  uVar27 = *(undefined4 *)(param_1 + 0x1cac);
  puVar29[0xdf] = ((unsigned char *)0x00001008);
  puVar29[0xde] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1ca0);
  puVar29[0xe1] = ((unsigned char *)0x000010e9);
  puVar29[0xe0] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1d20);
  puVar29[0xe3] = ((unsigned char *)0x000013c7);
  puVar29[0xe2] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1cf0);
  puVar29[0xe5] = ((unsigned char *)0x000013c1);
  puVar29[0xe4] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1ce4);
  puVar29[0xe7] = 0x850;
  puVar29[0xe6] = uVar27;
  uVar27 = *(undefined4 *)(((unsigned char *)0x00001dc0) + param_1);
  puVar29[0xe9] = 0x887;
  puVar29[0xe8] = uVar27;
  uVar27 = *(undefined4 *)(((unsigned char *)0x00001db4) + param_1);
  puVar29[0x18b] = 0x82c;
  puVar29[0xea] = uVar27;
  uVar27 = *(undefined4 *)(((unsigned char *)0x00001dc4) + param_1);
  puVar29[0xeb] = ((unsigned char *)0x000010ae);
  puVar29[0x18c] = uVar27;
  uVar27 = *(undefined4 *)(((unsigned char *)0x00001d70) + param_1);
  puVar29[0xed] = ((unsigned char *)0x00001394);
  puVar29[0xec] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1d30);
  puVar29[0xef] = ((unsigned char *)0x00001380);
  puVar29[0xf1] = ((unsigned char *)0x00001002);
  puVar29[0xf0] = 0;
  puVar29[0xee] = uVar27;
  puVar29[0xf2] = *(undefined4 *)(((unsigned char *)0x00001d90) + param_1);
  uVar27 = *(undefined4 *)(((unsigned char *)0x00001d90) + param_1);
  puVar29[0xf3] = 0x824;
  puVar29[0xf2] = uVar27;
  uVar27 = *(undefined4 *)(((unsigned char *)0x00001ddc) + param_1);
  puVar29[0xf5] = 0x825;
  puVar29[0xf4] = uVar27;
  uVar27 = *(undefined4 *)(((unsigned char *)0x00001de0) + param_1);
  puVar29[0xf7] = 0x82d;
  puVar29[0xf6] = uVar27;
  uVar27 = *(undefined4 *)(((unsigned char *)0x000026cc) + param_1);
  puVar29[0xf9] = 0x854;
  puVar29[0xf8] = uVar27;
  uVar27 = **(undefined4 **)(((unsigned char *)0x00002680) + param_1);
  puVar29[0xfb] = 0x878;
  puVar29[0xfa] = uVar27;
  uVar27 = **(undefined4 **)(((unsigned char *)0x00002684) + param_1);
  puVar29[0xfd] = ((unsigned char *)0x000013c0);
  puVar29[0xfc] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1ce0);
  puVar29[0xff] = ((unsigned char *)0x000012f0);
  puVar22 = PTR_DAT_001e88c8;
  puVar29[0xfe] = uVar27;
  uVar35 = *(uint *)(param_1 + 0x1d2c);
  puVar29[0x100] = uVar35;
  if ((*(uint *)(puVar22 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x8000) == 0) {
    puVar29[0x100] = uVar35 & 0xfffffffe;
  }
  puVar29[0x101] = ((unsigned char *)0x000012f5);
  uVar35 = *(uint *)(param_1 + 0x1c8c);
  puVar29[0x102] = uVar35;
  if ((*(uint *)(puVar22 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x8000) == 0) {
    puVar29[0x102] = uVar35 & 0xfffff7ff;
  }
  puVar29[0x103] = ((unsigned char *)0x000010a2);
  uVar27 = *(undefined4 *)(((unsigned char *)0x00001d7c) + param_1);
  puVar29[0x105] = ((unsigned char *)0x00001381);
  puVar29[0x104] = uVar27;
  uVar35 = *(uint *)(param_1 + 0x1cc0);
  puVar29[0x106] = uVar35;
  if ((*(uint *)(puVar22 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x4000) == 0) {
    puVar29[0x106] = uVar35 & 0xfffffffc;
  }
  puVar29[0x107] = ((unsigned char *)0x0000109e);
  iVar36 = 0;
  iVar26 = 0;
  uVar27 = *(undefined4 *)(((unsigned char *)0x00001d6c) + param_1);
  puVar29[0x109] = ((unsigned char *)0x00001096);
  puVar29[0x108] = uVar27;
  uVar27 = *(undefined4 *)(((unsigned char *)0x00001df8) + param_1);
  puVar29[0x10b] = ((unsigned char *)0x00001041);
  puVar29[0x108] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x29f0);
  puVar29[0x10d] = ((unsigned char *)0x00001046);
  puVar29[0x10c] = uVar27;
  uVar27 = *(undefined4 *)(((unsigned char *)0x00001dfc) + param_1);
  puVar29[0x10f] = ((unsigned char *)0x00001094);
  puVar29[0x127] = ((unsigned char *)0x00001095);
  puVar29[0x111] = ((unsigned char *)0x00001095);
  puVar29[0x14d] = ((unsigned char *)0x00001180);
  puVar29[0x113] = ((unsigned char *)0x00001095);
  puVar29[0x115] = ((unsigned char *)0x00001095);
  puVar29[0x117] = ((unsigned char *)0x00001095);
  puVar29[0x10e] = uVar27;
  puVar29[0x119] = ((unsigned char *)0x00001095);
  puVar29[0x11b] = ((unsigned char *)0x00001095);
  puVar29[0x11d] = ((unsigned char *)0x00001095);
  puVar29[0x11f] = ((unsigned char *)0x00001095);
  puVar29[0x121] = ((unsigned char *)0x00001095);
  puVar29[0x123] = ((unsigned char *)0x00001095);
  puVar29[0x125] = ((unsigned char *)0x00001095);
  puVar29[0x129] = 0xc0221000;
  puVar29[0x110] = 0;
  puVar29[0x14e] = 2;
  puVar29[0x14f] = ((unsigned char *)0x00001189);
  puVar29[0x151] = ((unsigned char *)0x00001181);
  puVar29[0x153] = ((unsigned char *)0x0000118d);
  puVar29[0x155] = ((unsigned char *)0x0000118e);
  puVar29[0x157] = ((unsigned char *)0x0000118c);
  puVar29[0x159] = ((unsigned char *)0x000011a9);
  uVar27 = *(undefined4 *)(param_1 + 0x257c);
  puVar29[0x15b] = ((unsigned char *)0x000011aa);
  puVar29[0x15a] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x2580);
  puVar29[0x15d] = ((unsigned char *)0x000011ab);
  puVar29[0x15c] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x2584);
  puVar29[0x15f] = ((unsigned char *)0x000011ac);
  puVar29[0x15e] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x2588);
  puVar29[0x161] = ((unsigned char *)0x000010c0);
  puVar29[0x160] = uVar27;
  uVar27 = *(undefined4 *)(((unsigned char *)0x0000216c) + param_1);
  puVar29[0x163] = ((unsigned char *)0x000010c1);
  puVar29[0x165] = ((unsigned char *)0x000010c8);
  puVar29[0x167] = ((unsigned char *)0x0000101d);
  puVar29[0x162] = uVar27;
  uVar27 = *(undefined4 *)(((unsigned char *)0x00002128) + param_1);
  puVar29[0x169] = ((unsigned char *)0x0000138a);
  puVar29[0x16b] = ((unsigned char *)0x0000138e);
  puVar29[0x170] = 0;
  puVar29[0x16d] = ((unsigned char *)0x00001040);
  puVar29[0x16a] = 0;
  puVar29[0x16c] = 0;
  puVar29[0x16e] = 0;
  puVar29[0x168] = uVar27;
  puVar29[0x16f] = ((unsigned char *)0x00001150);
  puVar29[0x171] = ((unsigned char *)0x00001100);
  uVar27 = *(undefined4 *)(param_1 + 0x1f1c);
  puVar29[0x173] = ((unsigned char *)0x00001110);
  puVar29[0x172] = uVar27;
  puVar29[0x174] = *(undefined4 *)(((unsigned char *)0x00001f5c) + param_1);
  puVar29[0x175] = ((unsigned char *)0x00001120);
  uVar27 = *(undefined4 *)(param_1 + 0x1f9c);
  puVar29[0x177] = ((unsigned char *)0x00001130);
  puVar29[0x176] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1fdc);
  puVar29[0x179] = ((unsigned char *)0x00001140);
  puVar29[0x178] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x201c);
  puVar29[0x17b] = ((unsigned char *)0x000010f4);
  puVar29[0x17c] = 0xaaaa;
  puVar29[0x17d] = ((unsigned char *)0x00001383);
  puVar29[0x17a] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1d34);
  puVar29[0x17f] = ((unsigned char *)0x00001386);
  puVar29[0x17e] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1d38);
  puVar29[0x181] = 0x110f8;
  puVar29[0x180] = uVar27;
  puVar29[0x182] = *(undefined4 *)(((unsigned char *)0x00001d98) + param_1);
  uVar27 = *(undefined4 *)(param_1 + 0x1d50);
  puVar29[0x184] = ((unsigned char *)0x00001087);
  puVar29[0x183] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1f0c);
  puVar29[0x186] = 0x31080;
  puVar29[0x185] = uVar27;
  puVar29[0x187] = *(undefined4 *)(param_1 + 0x1efc);
  puVar29[0x188] = *(undefined4 *)(param_1 + 0x1f04);
  puVar29[0x189] = *(undefined4 *)(param_1 + 0x1f00);
  puVar29[0x18a] = *(undefined4 *)(param_1 + 0x1f08);
  FUN_0004c100(puVar29 + 0xd0,iVar37);
  puVar29 = puVar29 + 0x18d;
  iVar38 = param_1;
  do {
    iVar31 = *(int *)(iVar38 + 0x18c);
    if (iVar31 != 0) {
      iVar40 = 5;
      piVar25 = (int *)(iVar26 + *(int *)(param_1 + 0x18));
      do {
        if (iVar31 == *piVar25) {
          if (*(int *)(iVar31 + 0x34) != 0) goto LAB_0002918c;
          break;
        }
        piVar25 = piVar25 + 1;
        iVar40 = iVar40 + -1;
      } while (iVar40 != 0);
      iVar31 = 0;
    }
LAB_0002918c:
    if ((iVar36 == 0) || (iVar31 != 0)) {
      puVar29 = (undefined4 *)((int (*)())FUN_0002cd50)(param_1,iVar31,iVar36);
    }
    bVar1 = iVar36 == 0xf;
    iVar26 = iVar26 + 0x14;
    iVar38 = iVar38 + 4;
    iVar36 = iVar36 + 1;
    if (bVar1) {
      *(undefined4 **)(param_1 + 0x298c) = puVar29;
      (**(code **)(param_1 + 0x299c))(iVar37,puVar29);
      _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
      if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
        FUN_0001a0f0(param_1,0x1000000);
      }
      if (*(int *)*in_stack_0000003c != 0) {
        FUN_0000b670(param_1,*(int *)*in_stack_0000003c,uVar34 * local_108);
        return 1;
      }
      return 1;
    }
  } while( true );
}

/* FUN_00029c00 @ 0x29c00 (1624 bytes) */
int FUN_00029c00(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  float *param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  uint param_7;
  uint param_8;
{
  uint uVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  float fVar15;
  int iVar16;
  undefined4 *puVar17;
  undefined4 *puVar18;
  float *pfVar19;
  float fVar20;
  undefined4 uVar21;
  float *pfVar22;
  int iVar23;
  int iVar24;
  int in_stack_00000038;
  int in_stack_0000003c;
  char in_stack_00000043;
  float local_168;
  undefined4 local_160;
  float local_15c;
  float local_154;
  float local_150;
  float local_14c;
  undefined1 auStack_148 [144];
  undefined4 local_b8[0];
  undefined4 uStack_b4;
  longlong local_b0;
  undefined4 local_a8;
  uint uStack_a4;
  undefined4 local_a0;
  uint uStack_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  longlong local_90;
  undefined4 local_88[0];
  uint uStack_84;
  undefined4 local_80;
  uint uStack_7c;
  undefined4 local_78;
  uint uStack_74;
  undefined4 local_70;
  uint uStack_6c;
  undefined4 local_68;
  uint uStack_64;
  
  iVar24 = param_1 + 0x240;
  iVar23 = param_3 * param_4;
  uVar21 = *(undefined4 *)(param_1 + 0x248);
  iVar16 = *(int *)(*(int *)(param_1 + 0x244) + 0x10);
  fVar8 = FLOAT_001aa0e8;
  if (*(float *)(((unsigned char *)0x00002e4c) + iVar16) < 0.0) {
    fVar8 = FLOAT_001aa114;
  }
  fVar7 = FLOAT_001aa0e8;
  if (*(float *)(((unsigned char *)0x00002e48) + iVar16) < 0.0) {
    fVar7 = FLOAT_001aa114;
  }
  if (-*(float *)(((unsigned char *)0x00002e4c) + iVar16) < 0.0) {
    fVar8 = FLOAT_001aa0e8;
  }
  if (-*(float *)(((unsigned char *)0x00002e48) + iVar16) < 0.0) {
    fVar7 = FLOAT_001aa0e8;
  }
  if (in_stack_0000003c != 0x1901) {
    if (in_stack_00000043 == '\0') {
      FUN_000a6140(iVar24,(*(uint *)(param_1 + 0x1cf8) ^ 1) & 1 |
                          (uint)(in_stack_0000003c == 0x1902) << 0xc,auStack_148);
      FUN_0004b480(iVar24,*(uint *)(param_1 + 0x1ae4) >> 6 & 0xffff);
      *(uint *)(((unsigned char *)0x0000216c) + param_1) = *(uint *)(((unsigned char *)0x0000216c) + param_1) & 0xfffff800 | 0x80;
    }
    else {
      FUN_00086ba0(iVar24,1,0,0,auStack_148);
    }
    iVar16 = iVar23 * 8 + 0x1b;
  }
  else {
    FUN_00086ba0(iVar24,0,0,1,auStack_148);
    iVar16 = iVar23 * 0x10 + 0x19;
  }
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    iVar16 = iVar16 + 2;
  }
  puVar17 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar24,iVar16);
  *(undefined4 **)(param_1 + 0x298c) = puVar17;
  puVar18 = puVar17;
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    puVar18 = puVar17 + 2;
    *puVar17 = 0x5c8;
    puVar17[1] = 0x10000000;
    *(undefined1 *)(param_1 + 0x2a42) = 1;
  }
  *puVar18 = ((unsigned char *)0x000010c0);
  puVar18[1] = *(undefined4 *)(((unsigned char *)0x0000216c) + param_1);
  puVar18 = (undefined4 *)FUN_00083c90(iVar24,puVar18 + 2);
  dVar11 = DOUBLE_001aa1e0;
  fVar9 = FLOAT_001aa10c;
  uStack_a4 = param_8 ^ 0x80000000;
  local_b8[0] = 0x43300000;
  pfVar19 = (float *)(puVar18 + 2);
  uVar1 = (uint)(((double)CONCAT44(0x43300000,uVar21) - DOUBLE_001aa250) * DOUBLE_001aa240);
  local_b0 = (longlong)(int)uVar1;
  *puVar18 = ((unsigned char *)0x00001087);
  puVar18[1] = uVar1 << 0x10 | uVar1 & 0xffff;
  local_a8 = 0x43300000;
  local_160 = fVar9 / *(float *)(param_1 + 0x2a58) +
              (float)((double)CONCAT44(0x43300000,uStack_a4) - dVar11);
  if (in_stack_0000003c != 0x1901) {
    pfVar19 = (float *)(puVar18 + 4);
    puVar18[2] = iVar23 * 0x80000 | 0xc0003500;
    puVar18[3] = iVar23 * 0x10000 | 0x31;
    if (param_4 != 0) {
      uStack_84 = param_7 ^ 0x80000000;
      local_88[0] = 0x43300000;
      iVar23 = 0;
      fVar9 = (float)((double)CONCAT44(0x43300000,uStack_84) - dVar11) + fVar9;
      iVar16 = param_3;
      fVar20 = fVar9;
      fVar10 = FLOAT_001aa0f0;
      dVar11 = DOUBLE_001aa250;
      pfVar22 = param_2;
      do {
        for (; dVar12 = DOUBLE_001aa250, fVar3 = FLOAT_001aa0f0, iVar16 != 0; iVar16 = iVar16 + -1)
        {
          if (in_stack_0000003c == 0x1902) {
            local_15c = *param_2;
            local_154 = *(float *)(in_stack_00000038 + 0x30);
            local_150 = *(float *)(in_stack_00000038 + 0x34);
            local_14c = *(float *)(in_stack_00000038 + 0x38);
            local_168 = *(float *)(in_stack_00000038 + 0x3c);
          }
          else {
            local_15c = *(float *)(in_stack_00000038 + 8);
            fVar15 = *param_2;
            local_80 = 0x43300000;
            local_78 = 0x43300000;
            local_70 = 0x43300000;
            local_68 = 0x43300000;
            uStack_64 = (uint)fVar15 & 0xff;
            uStack_7c = (uint)fVar15 >> 0x18;
            uStack_74 = (uint)fVar15 >> 0x10 & 0xff;
            uStack_6c = (uint)fVar15 >> 8 & 0xff;
            local_168 = (float)((double)CONCAT44(0x43300000,uStack_7c) - DOUBLE_001aa250) /
                        FLOAT_001aa0f0;
            local_14c = (float)((double)CONCAT44(0x43300000,uStack_64) - DOUBLE_001aa250) /
                        FLOAT_001aa0f0;
            local_154 = (float)((double)CONCAT44(0x43300000,uStack_74) - DOUBLE_001aa250) /
                        FLOAT_001aa0f0;
            local_150 = (float)((double)CONCAT44(0x43300000,uStack_6c) - DOUBLE_001aa250) /
                        FLOAT_001aa0f0;
          }
          param_2 = (float *)((int)param_2 + param_6);
          FLOAT_001aa0f0 = fVar10;
          DOUBLE_001aa250 = dVar11;
          *pfVar19 = fVar20;
          pfVar19[1] = local_160;
          pfVar19[2] = local_15c;
          pfVar19[3] = 1.0;
          pfVar19[4] = local_154;
          pfVar19[5] = local_150;
          pfVar19[6] = local_14c;
          pfVar19[7] = local_168;
          pfVar19 = pfVar19 + 8;
          fVar20 = fVar7 + fVar20;
          fVar10 = FLOAT_001aa0f0;
          dVar11 = DOUBLE_001aa250;
          DOUBLE_001aa250 = dVar12;
          FLOAT_001aa0f0 = fVar3;
        }
        iVar23 = iVar23 + 1;
        param_2 = (float *)((int)pfVar22 + param_5);
        local_160 = fVar8 + local_160;
        FLOAT_001aa0f0 = fVar10;
        DOUBLE_001aa250 = dVar11;
        iVar16 = param_3;
        fVar20 = fVar9;
        pfVar22 = param_2;
      } while (iVar23 != param_4);
    }
  }
  else {
    fVar20 = (float)(*(uint *)(param_1 + 0x1ce8) & 0xffff00ff | 0xff00);
    if (param_4 != 0) {
      uStack_9c = param_7 ^ 0x80000000;
      local_a0 = 0x43300000;
      iVar23 = 0;
      fVar9 = fVar9 / *(float *)(param_1 + 0x2a54) +
              (float)((double)CONCAT44(0x43300000,uStack_9c) - dVar11);
      iVar16 = param_3;
      fVar10 = fVar9;
      dVar11 = DOUBLE_001aa240;
      dVar12 = DOUBLE_001aa250;
      pfVar22 = param_2;
      do {
        for (; dVar14 = DOUBLE_001aa250, dVar13 = DOUBLE_001aa240, DOUBLE_001aa240 = dVar11,
            DOUBLE_001aa250 = dVar12, iVar16 != 0; iVar16 = iVar16 + -1) {
          fVar3 = *(float *)(in_stack_00000038 + 8);
          fVar15 = *(float *)(in_stack_00000038 + 0x30);
          fVar4 = *(float *)(in_stack_00000038 + 0x34);
          fVar5 = *(float *)(in_stack_00000038 + 0x38);
          fVar6 = *(float *)(in_stack_00000038 + 0x3c);
          bVar2 = *(byte *)param_2;
          *pfVar19 = (float)0x000013c2;
          param_2 = (float *)((int)param_2 + param_6);
          fVar20 = (float)((uint)bVar2 | (uint)fVar20 & 0xffffff00);
          pfVar19[1] = fVar20;
          uStack_94 = *(undefined4 *)(param_1 + 0x248);
          local_98 = 0x43300000;
          uVar1 = (uint)(((double)CONCAT44(0x43300000,uStack_94) - dVar14) * dVar13);
          local_90 = (longlong)(int)uVar1;
          pfVar19[5] = 9.19042e-41;
          pfVar19[6] = fVar10;
          pfVar19[7] = local_160;
          pfVar19[8] = fVar3;
          pfVar19[2] = (float)0x00001087;
          pfVar19[4] = -2.1282349;
          pfVar19[3] = (float)(uVar1 << 0x10 | uVar1 & 0xffff);
          pfVar19[9] = 1.0;
          pfVar19[10] = fVar15;
          pfVar19[0xb] = fVar4;
          pfVar19[0xc] = fVar5;
          pfVar19[0xd] = fVar6;
          pfVar19[0xe] = (float)0x00001087;
          pfVar19[0xf] = *(float *)(param_1 + 0x1f0c);
          pfVar19 = pfVar19 + 0x10;
          fVar10 = fVar7 + fVar10;
          dVar11 = DOUBLE_001aa240;
          dVar12 = DOUBLE_001aa250;
          DOUBLE_001aa250 = dVar14;
          DOUBLE_001aa240 = dVar13;
        }
        iVar23 = iVar23 + 1;
        param_2 = (float *)((int)pfVar22 + param_5);
        local_160 = fVar8 + local_160;
        iVar16 = param_3;
        fVar10 = fVar9;
        pfVar22 = param_2;
      } while (param_4 != iVar23);
    }
  }
  *pfVar19 = (float)0x00001087;
  pfVar19[1] = *(float *)(param_1 + 0x1f0c);
  *(float **)(param_1 + 0x298c) = pfVar19 + 2;
  uStack_b4 = uVar21;
  (**(code **)(param_1 + 0x299c))(iVar24,pfVar19 + 2);
  FUN_0009d3b0(iVar24);
  FUN_000872e0(iVar24,auStack_148);
  return;
}

/* FUN_0002a3d0 @ 0x2a3d0 (3968 bytes) */
int FUN_0002a3d0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  undefined *param_6;
  int param_7;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  uint uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  double dVar15;
  undefined *puVar16;
  undefined *puVar17;
  uint uVar18;
  uint *puVar19;
  uint uVar20;
  int *piVar21;
  int iVar22;
  uint *puVar23;
  undefined4 *puVar24;
  undefined4 uVar25;
  int iVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  undefined4 *puVar30;
  uint uVar31;
  int iVar32;
  int iVar33;
  int iVar34;
  char in_RESERVE;
  byte bVar35;
  int iVar36;
  double dVar37;
  double dVar38;
  double dVar39;
  double dVar40;
  double dVar41;
  undefined4 *in_stack_00000038;
  uint local_108;
  undefined1 auStack_104 [4];
  int local_100 [2];
  undefined4 local_f8;
  uint uStack_f4;
  undefined4 local_f0;
  uint uStack_ec;
  undefined4 local_e8;
  uint uStack_e4;
  undefined4 local_e0;
  uint uStack_dc;
  undefined4 local_d8;
  uint uStack_d4;
  longlong local_d0;
  longlong local_c8;
  longlong local_c0;
  longlong local_b8[0];
  longlong local_b0;
  longlong local_a8;
  longlong local_a0;
  longlong local_98;
  longlong local_90;
  longlong local_88[0];
  
  bVar35 = (param_5 == 0x1909) << 1;
  uVar31 = param_5;
  FUN_001a3254();
  if ((bool)(bVar35 >> 1 & 1)) {
    iVar32 = 1;
    if (param_6 != ((unsigned char *)0x00001401)) {
      iVar32 = 0x13;
      if ((param_6 != ((unsigned char *)0x00001406)) && (iVar32 = 0x1f, param_6 != ((unsigned char *)0x0000140b))) {
        iVar32 = 0;
        if (param_6 != ((unsigned char *)0x00001403)) goto LAB_0002a440;
        iVar32 = 0x19;
      }
      goto LAB_0002a520;
    }
LAB_0002a440:
    if (iVar32 == 0) {
      return 0;
    }
  }
  else if (uVar31 < 0x190a) {
    if (uVar31 == 0x1907) {
      iVar32 = 5;
      if ((param_6 != (undefined *)0x8363) && (iVar32 = 0x28, param_6 != (undefined *)0x8032)) {
        return 0;
      }
    }
    else if (uVar31 < 0x1908) {
      if (uVar31 != 0x1906) {
        return 0;
      }
      iVar32 = 2;
      if (param_6 == ((unsigned char *)0x00001401)) goto LAB_0002a440;
      iVar32 = 0x14;
      if ((param_6 != ((unsigned char *)0x00001406)) && (iVar32 = 0x20, param_6 != ((unsigned char *)0x0000140b))) {
        iVar32 = 0;
        if (param_6 != ((unsigned char *)0x00001403)) goto LAB_0002a440;
        iVar32 = 0x1a;
      }
    }
    else {
      iVar32 = 0x12;
      if (param_6 == ((unsigned char *)0x00001406)) {
LAB_0002a570:
        if (param_6 == (undefined *)0x8368) {
          iVar32 = 0x23;
          goto LAB_0002a520;
        }
      }
      else {
        if (param_6 == (undefined *)0x8035) {
          iVar32 = 9;
          goto LAB_0002a570;
        }
        if (param_6 != (undefined *)0x8367) {
          iVar32 = 0;
          if (param_6 == ((unsigned char *)0x00001401)) {
            iVar32 = 9;
            goto LAB_0002a520;
          }
          goto LAB_0002a570;
        }
        iVar32 = 10;
      }
      if (param_6 != ((unsigned char *)0x00001403)) goto LAB_0002a440;
      iVar32 = 0x18;
    }
  }
  else if (uVar31 == 0x80e1) {
    iVar32 = 7;
    if (param_6 == (undefined *)0x8366) {
LAB_0002a4e0:
      if (param_6 == (undefined *)0x8035) {
        iVar32 = 8;
        goto LAB_0002a4f4;
      }
LAB_0002a4a8:
      if (param_6 != (undefined *)0x8368) goto LAB_0002a4d4;
      iVar32 = 0x24;
LAB_0002a504:
      if (param_6 != ((unsigned char *)0x00001403)) goto LAB_0002a440;
      iVar32 = 0x17;
    }
    else {
      if (param_6 == (undefined *)0x8365) {
        iVar32 = 6;
        goto LAB_0002a4a8;
      }
      iVar32 = 0;
      if (param_6 != (undefined *)0x8367) goto LAB_0002a4e0;
      iVar32 = 0xb;
LAB_0002a4d4:
      if (param_6 == ((unsigned char *)0x00001406)) {
        iVar32 = 0x11;
      }
      else {
LAB_0002a4f4:
        if (param_6 != ((unsigned char *)0x0000140b)) goto LAB_0002a504;
        iVar32 = 0x1d;
      }
    }
  }
  else if (uVar31 == 0x85b9) {
    iVar32 = 0x27;
    if ((param_6 != (undefined *)0x85ba) && (iVar32 = 0x26, param_6 != (undefined *)0x85bb)) {
      return 0;
    }
  }
  else {
    if (uVar31 != 0x190a) {
      return 0;
    }
    iVar32 = 4;
    if (param_6 == ((unsigned char *)0x00001401)) goto LAB_0002a440;
    if (param_6 == ((unsigned char *)0x00001406)) {
      iVar32 = 0x16;
    }
    else {
      iVar32 = 0x22;
      if (param_6 != ((unsigned char *)0x0000140b)) {
        iVar32 = 0;
        if (param_6 != ((unsigned char *)0x00001403)) goto LAB_0002a440;
        iVar32 = 0x1c;
      }
    }
  }
LAB_0002a520:
  _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
  FUN_0000a6e0(param_1,param_5,param_6,param_3,param_4,&local_108,auStack_104,local_100);
  iVar26 = *(int *)*in_stack_00000038;
  uVar31 = param_7 + local_100[0];
  if (((((int)local_108 < 0x1001) && ((int)param_4 < 0x1001)) &&
      (uVar27 = *(uint *)(param_1 + 0x15c), (int)uVar27 < 0x1001)) &&
     (uVar29 = *(uint *)(param_1 + 0x160), (int)uVar29 < 0x1001)) {
    if ((int)uVar27 < 1) {
      uVar27 = 1;
      fVar3 = FLOAT_001aa0e8;
    }
    else {
      uStack_f4 = uVar27 ^ 0x80000000;
      local_f8 = 0x43300000;
      fVar3 = (float)((double)CONCAT44(0x43300000,uStack_f4) - DOUBLE_001aa1e0);
    }
    if ((int)uVar29 < 1) {
      uVar29 = 1;
      uStack_d4 = 0xffffffff;
      fVar4 = FLOAT_001aa0e8;
    }
    else {
      uStack_ec = uVar29 ^ 0x80000000;
      uStack_d4 = -uVar29;
      local_f0 = 0x43300000;
      fVar4 = (float)((double)CONCAT44(0x43300000,uStack_ec) - DOUBLE_001aa1e0);
    }
    uStack_e4 = param_3 ^ 0x80000000;
    uStack_dc = param_4 ^ 0x80000000;
    local_e0 = 0x43300000;
    local_e8 = 0x43300000;
    fVar5 = *(float *)(param_2 + 0x20);
    fVar6 = *(float *)(param_2 + 0x24);
    fVar8 = fVar5 + FLOAT_001aa0d4 + FLOAT_001aa0d4;
    fVar2 = fVar4 - (fVar6 + FLOAT_001aa0d4);
    fVar13 = fVar4 - ((float)((double)CONCAT44(0x43300000,uStack_dc) - DOUBLE_001aa1e0) + fVar6);
    fVar11 = (float)((double)CONCAT44(0x43300000,uStack_e4) - DOUBLE_001aa1e0) + fVar5 +
             FLOAT_001aa0d4;
    fVar10 = FLOAT_001aa0d4;
    fVar12 = FLOAT_001aa0d4;
    if (FLOAT_001aa0d4 < fVar8) {
      fVar10 = fVar8;
      fVar12 = fVar8 + FLOAT_001aa0d4;
    }
    uStack_d4 = uStack_d4 ^ 0x80000000;
    fVar8 = fVar11 - fVar3;
    fVar14 = fVar2 - fVar4;
    local_d8 = 0x43300000;
    fVar9 = fVar3;
    if (fVar8 < 0.0) {
      fVar9 = fVar11;
    }
    fVar11 = fVar4;
    if (fVar14 < 0.0) {
      fVar11 = fVar2;
    }
    fVar2 = fVar13;
    if (fVar13 < 0.0) {
      fVar2 = FLOAT_001aa0d4;
    }
    if (-fVar8 < 0.0) {
      fVar9 = fVar3;
    }
    if (-fVar14 < 0.0) {
      fVar11 = fVar4;
    }
    fVar3 = FLOAT_001aa0d4;
    if (-fVar13 < 0.0) {
      fVar3 = fVar2;
    }
    fVar8 = -fVar5 + fVar12 + FLOAT_001aa0d4;
    fVar12 = -fVar5 + fVar9 + FLOAT_001aa0d4 + FLOAT_001aa0d4;
    fVar4 = (float)((double)CONCAT44(0x43300000,uStack_d4) - DOUBLE_001aa1e0);
    fVar5 = -fVar6 + (FLOAT_001aa0d4 - (fVar11 + fVar4));
    fVar4 = -fVar6 + (FLOAT_001aa0d4 - (fVar3 + fVar4));
    if ((fVar10 < fVar9) && (fVar3 < fVar11)) {
      if (((((*(int *)in_stack_00000038[1] != 0) &&
            (iVar22 = FUN_0001e280(param_1,in_stack_00000038,1), iVar22 == 0)) ||
           ((puVar16 = PTR_DAT_001e88c8, (int *)in_stack_00000038[2] == (int *)0x0 ||
            (iVar22 = *(int *)in_stack_00000038[2], iVar22 == 0)))) ||
          ((*(char *)(iVar22 + 0x16) != '\x06' &&
           ((param_5 != 0x1908 || ((param_6 != ((unsigned char *)0x00001406) && (param_6 != (undefined *)0x8366)))))
           ))) || (((uVar31 | local_108) & 0x1f) != 0)) goto LAB_0002a9a0;
      iVar33 = param_1 + 0x240;
      iVar34 = 0xf;
      uVar25 = (**(code **)(param_1 + 0x2998))(iVar33,0x343);
      *(undefined4 *)(param_1 + 0x298c) = uVar25;
      iVar22 = param_1;
      do {
        if (*(int *)(iVar22 + 0x1c8) != 0) {
          uVar25 = ((int (*)())FUN_0002cd50)(param_1,0,iVar34,uVar25);
        }
        iVar34 = iVar34 + -1;
        bVar35 = (iVar34 == 0) << 1;
        iVar22 = iVar22 + -4;
      } while (iVar34 != 0);
      puVar23 = (uint *)((int (*)())FUN_0002cd50)(param_1,0,0,uVar25);
      puVar24 = (undefined4 *)((uint)(puVar23 + 0xb) & 0xffffffe0);
      *puVar23 = (((int)puVar24 - (int)puVar23) + -8) * 0x4000 | 0xc0001000;
      puVar24[-1] = (int)puVar24 - (int)puVar23;
      puVar19 = *(uint **)(param_1 + 0x1d8);
      *puVar19 = (int)puVar24 - (int)puVar19 >> 2 | *puVar19;
      *(undefined4 **)(param_1 + 0x1d8) = puVar24;
      *puVar24 = 0x3f000000;
      puVar30 = *(undefined4 **)in_stack_00000038[2];
      piVar21 = puVar30 + 4;
      do {
        if (in_RESERVE != '\0') {
          iVar22 = storeWordConditionalIndexed(*piVar21 + 0x10000,0,piVar21);
          *piVar21 = iVar22;
          bVar35 = 2;
        }
        puVar17 = PTR_DAT_001e88d0;
      } while (!(bool)(bVar35 >> 1 & 1));
      puVar24[2] = *puVar30;
      puVar24[3] = uVar31 - *(int *)*in_stack_00000038;
      _memcpy(puVar24 + 4,puVar17,0x2f4);
      fVar6 = fVar12 - fVar8;
      dVar40 = (double)fVar6;
      fVar2 = fVar4 - fVar5;
      dVar41 = (double)fVar2;
      dVar37 = (double)FLOAT_001aa0e8;
      puVar24[0x22] = 0;
      dVar39 = DOUBLE_001aa1e8;
      dVar38 = (double)(float)(dVar40 - dVar37);
      bVar1 = DOUBLE_001aa1e8 <= dVar38;
      puVar24[0xa4] = *(uint *)(puVar16 + iVar32 * 0x24 + 0x18) >> 0x1e | puVar24[0xa4] & 0xfffffffc
      ;
      dVar15 = DOUBLE_001aa1e8;
      if (bVar1) {
        iVar22 = (int)(dVar38 - dVar39);
        local_c8 = (longlong)iVar22;
        uVar20 = iVar22 + 0x80000000;
      }
      else {
        uVar20 = (uint)(dVar40 - dVar37);
        local_d0 = (longlong)(int)uVar20;
      }
      dVar39 = (double)(float)(dVar41 - (double)FLOAT_001aa0e8);
      if (DOUBLE_001aa1e8 <= dVar39) {
        iVar22 = (int)(dVar39 - DOUBLE_001aa1e8);
        local_b8[0] = (longlong)iVar22;
        uVar28 = iVar22 + 0x80000000;
      }
      else {
        uVar28 = (uint)(dVar41 - (double)FLOAT_001aa0e8);
        local_c0 = (longlong)(int)uVar28;
      }
      puVar24[0xaa] = uVar20 & 0x7ff | (uVar28 & 0x7ff) << 0xb | 0x80000000;
      uVar20 = *(uint *)(puVar16 + iVar32 * 0x24 + 0x1c);
      uVar28 = *(uint *)(puVar16 + iVar32 * 0x24 + 0x20);
      puVar24[0xac] =
           uVar20 >> 7 & 0x1f | uVar28 >> 3 & 0x400000 | (uVar20 & 0x70) << 5 |
           (uVar20 & 0xe) << 0xb | uVar28 >> 0xe & 0x38000 | uVar28 >> 8 & 0x1c0000;
      puVar17 = PTR_DAT_001e88c8;
      if (dVar15 <= dVar40) {
        iVar22 = (int)(dVar40 - dVar15);
        local_a8 = (longlong)iVar22;
        iVar22 = iVar22 + -0x80000000;
      }
      else {
        iVar22 = (int)fVar6;
        local_b0 = (longlong)iVar22;
      }
      if (DOUBLE_001aa1e8 <= dVar41) {
        local_98 = (longlong)(int)(dVar41 - DOUBLE_001aa1e8);
        iVar34 = (int)(dVar41 - DOUBLE_001aa1e8) + -0x80000000;
      }
      else {
        iVar34 = (int)fVar2;
        local_a0 = (longlong)iVar34;
      }
      uVar18 = puVar24[0x8e];
      puVar24[0xae] =
           ((int)local_108 >> (*(uint *)(puVar16 + iVar32 * 0x24 + 0x14) & 7)) - 1U & 0x3fff |
           (iVar22 + -1) * 0x10 & 0xffff8000U | (iVar34 + -1) * 0x20 & 0xffff0000U;
      puVar24[0xa4] = (uVar31 - iVar26) * 0x20 | puVar24[0xa4] & 0x1f;
      bVar35 = ((unsigned char *)0x00002b7f)[param_1];
      uVar31 = (*(uint *)(puVar17 + (uint)bVar35 * 0x24 + 0x18) & 0x18) << 5;
      puVar24[0x8e] = uVar31 | uVar18 & 0xfffffcff;
      uVar20 = (*(uint *)(puVar17 + (uint)bVar35 * 0x24 + 0x18) & 6) << 9;
      puVar24[0x8e] = uVar20 | uVar31 | uVar18 & 0xfffff0ff;
      uVar28 = *(uint *)(puVar17 + (uint)bVar35 * 0x24 + 0x1c) >> 0x12 & 0x3000;
      puVar24[0x8e] = uVar28 | uVar20 | uVar31 | uVar18 & 0xffffc0ff;
      uVar7 = *(uint *)(puVar17 + (uint)bVar35 * 0x24 + 0x1c) >> 0xe & 0xc000;
      puVar24[0x8e] = uVar7 | uVar28 | uVar20 | uVar31 | uVar18 & 0xffff00ff;
      puVar24[0x8e] =
           *(uint *)(puVar17 + (uint)bVar35 * 0x24 + 0x18) >> 5 & 0x1f |
           uVar7 | uVar28 | uVar20 | uVar31 | uVar18 & 0xffff00e0;
      if ((*(uint *)(puVar17 + (uint)bVar35 * 0x24 + 0x14) & 0xfc000000) == 0) {
        puVar24[0x5a] = puVar24[0x5a] & 0xfffe3fff | 0x18000;
      }
      fVar14 = FLOAT_001aa12c;
      fVar13 = FLOAT_001aa10c;
      puVar30 = puVar24 + 0xcd;
      fVar6 = (float)((double)FLOAT_001aa0e8 / dVar41);
      fVar2 = (float)((double)FLOAT_001aa0e8 / dVar40);
      puVar24[0xb7] = uVar27 - 1 & 0x1fff | (uVar29 - 1) * 0x2000 & 0x3ffe000;
      puVar24[0xc1] = 0x31080;
      puVar24[0xc6] = ((unsigned char *)0x00001087);
      puVar24[0xc5] = fVar4 * fVar6;
      iVar32 = (int)((fVar9 - fVar10) * fVar14);
      local_90 = (longlong)iVar32;
      puVar24[0xc4] = fVar12 * fVar2;
      puVar24[0xc2] = fVar8 * fVar2;
      puVar24[0xc3] = fVar5 * fVar6;
      uVar31 = (uint)((fVar11 - fVar3) * fVar14);
      local_88[0] = (longlong)(int)uVar31;
      puVar24[0xc9] = 0x10031;
      puVar24[200] = 0xc0033500;
      puVar24[0xca] = (fVar10 + fVar9) * fVar13;
      puVar24[0xcb] = (fVar3 + fVar11) * fVar13;
      puVar24[0xcc] = 0;
      puVar24[199] = iVar32 << 0x10 | uVar31;
      puVar24[1] = (int)puVar30 - (int)puVar23 >> 2;
      puVar19 = *(uint **)(param_1 + 0x1d8);
      *puVar19 = (int)puVar30 - (int)puVar19 >> 2 | *puVar19;
      *(undefined4 **)(param_1 + 0x1d8) = puVar30;
      puVar24[0xce] = 0;
      puVar24[0xcd] = 0x33000000;
      puVar24[0xcf] = ((unsigned char *)0x00001393);
      puVar24[0xd0] = 10;
      puVar24[0xd1] = ((unsigned char *)0x000013c6);
      puVar24[0xd2] = 3;
      puVar24[0xd3] = 0x5c8;
      puVar24[0xd4] = 0x20000;
      puVar24[0xd5] = ((unsigned char *)0x000010ea);
      uVar25 = *(undefined4 *)(param_1 + 0x1cfc);
      puVar24[0xd7] = ((unsigned char *)0x000010fa);
      puVar24[0xd6] = uVar25;
      uVar25 = *(undefined4 *)(((unsigned char *)0x00001da0) + param_1);
      puVar24[0xd9] = 0xc0001000;
      puVar24[0xdb] = 0x11004;
      puVar24[0xd8] = uVar25;
      puVar24[0xdc] = *(undefined4 *)(param_1 + 0x1ca8);
      uVar25 = *(undefined4 *)(param_1 + 0x1cac);
      puVar24[0xde] = ((unsigned char *)0x00001008);
      puVar24[0xdd] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1ca0);
      puVar24[0xe0] = ((unsigned char *)0x000010e9);
      puVar24[0xdf] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1d20);
      puVar24[0xe2] = ((unsigned char *)0x000013c7);
      puVar24[0xe1] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1cf0);
      puVar24[0xe4] = ((unsigned char *)0x000013c1);
      puVar24[0xe3] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1ce4);
      puVar24[0xe6] = 0x850;
      puVar24[0xe5] = uVar25;
      uVar25 = *(undefined4 *)(((unsigned char *)0x00001dc0) + param_1);
      puVar24[0xe8] = 0x887;
      puVar24[0xe7] = uVar25;
      uVar25 = *(undefined4 *)(((unsigned char *)0x00001db4) + param_1);
      puVar24[0x18a] = 0x82c;
      puVar24[0xe9] = uVar25;
      uVar25 = *(undefined4 *)(((unsigned char *)0x00001dc4) + param_1);
      puVar24[0xea] = ((unsigned char *)0x000010ae);
      puVar24[0x18b] = uVar25;
      uVar25 = *(undefined4 *)(((unsigned char *)0x00001d70) + param_1);
      puVar24[0xec] = ((unsigned char *)0x00001394);
      puVar24[0xeb] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1d30);
      puVar24[0xee] = ((unsigned char *)0x00001380);
      puVar24[0xf0] = ((unsigned char *)0x00001002);
      puVar24[0xef] = 0;
      puVar24[0xed] = uVar25;
      puVar24[0xf1] = *(undefined4 *)(((unsigned char *)0x00001d90) + param_1);
      uVar25 = *(undefined4 *)(((unsigned char *)0x00001d90) + param_1);
      puVar24[0xf2] = 0x824;
      puVar24[0xf1] = uVar25;
      uVar25 = *(undefined4 *)(((unsigned char *)0x00001ddc) + param_1);
      puVar24[0xf4] = 0x825;
      puVar24[0xf3] = uVar25;
      uVar25 = *(undefined4 *)(((unsigned char *)0x00001de0) + param_1);
      puVar24[0xf6] = 0x82d;
      puVar24[0xf5] = uVar25;
      uVar25 = *(undefined4 *)(((unsigned char *)0x000026cc) + param_1);
      puVar24[0xf8] = 0x854;
      puVar24[0xf7] = uVar25;
      uVar25 = **(undefined4 **)(((unsigned char *)0x00002680) + param_1);
      puVar24[0xfa] = 0x878;
      puVar24[0xf9] = uVar25;
      uVar25 = **(undefined4 **)(((unsigned char *)0x00002684) + param_1);
      puVar24[0xfc] = ((unsigned char *)0x000013c0);
      puVar24[0xfb] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1ce0);
      puVar24[0xfe] = ((unsigned char *)0x000012f0);
      puVar24[0xfd] = uVar25;
      uVar31 = *(uint *)(param_1 + 0x1d2c);
      puVar24[0xff] = uVar31;
      if ((*(uint *)(puVar17 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x8000) == 0) {
        puVar24[0xff] = uVar31 & 0xfffffffe;
      }
      puVar24[0x100] = ((unsigned char *)0x000012f5);
      uVar31 = *(uint *)(param_1 + 0x1c8c);
      puVar24[0x101] = uVar31;
      if ((*(uint *)(puVar17 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x8000) == 0) {
        puVar24[0x101] = uVar31 & 0xfffff7ff;
      }
      puVar24[0x102] = ((unsigned char *)0x000010a2);
      uVar25 = *(undefined4 *)(((unsigned char *)0x00001d7c) + param_1);
      puVar24[0x104] = ((unsigned char *)0x00001381);
      puVar24[0x103] = uVar25;
      uVar31 = *(uint *)(param_1 + 0x1cc0);
      puVar24[0x105] = uVar31;
      if ((*(uint *)(puVar17 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x4000) == 0) {
        puVar24[0x105] = uVar31 & 0xfffffffc;
      }
      puVar24[0x106] = ((unsigned char *)0x0000109e);
      iVar22 = 0;
      iVar26 = 0;
      uVar25 = *(undefined4 *)(((unsigned char *)0x00001d6c) + param_1);
      puVar24[0x108] = ((unsigned char *)0x00001096);
      puVar24[0x107] = uVar25;
      uVar25 = *(undefined4 *)(((unsigned char *)0x00001df8) + param_1);
      puVar24[0x10a] = ((unsigned char *)0x00001041);
      puVar24[0x107] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x29f0);
      puVar24[0x10c] = ((unsigned char *)0x00001046);
      puVar24[0x10b] = uVar25;
      uVar25 = *(undefined4 *)(((unsigned char *)0x00001dfc) + param_1);
      puVar24[0x10e] = ((unsigned char *)0x00001094);
      puVar24[0x126] = ((unsigned char *)0x00001095);
      puVar24[0x110] = ((unsigned char *)0x00001095);
      puVar24[0x14c] = ((unsigned char *)0x00001180);
      puVar24[0x112] = ((unsigned char *)0x00001095);
      puVar24[0x114] = ((unsigned char *)0x00001095);
      puVar24[0x116] = ((unsigned char *)0x00001095);
      puVar24[0x10d] = uVar25;
      puVar24[0x118] = ((unsigned char *)0x00001095);
      puVar24[0x11a] = ((unsigned char *)0x00001095);
      puVar24[0x11c] = ((unsigned char *)0x00001095);
      puVar24[0x11e] = ((unsigned char *)0x00001095);
      puVar24[0x120] = ((unsigned char *)0x00001095);
      puVar24[0x122] = ((unsigned char *)0x00001095);
      puVar24[0x124] = ((unsigned char *)0x00001095);
      puVar24[0x128] = 0xc0221000;
      puVar24[0x10f] = 0;
      puVar24[0x14d] = 2;
      puVar24[0x14e] = ((unsigned char *)0x00001189);
      puVar24[0x150] = ((unsigned char *)0x00001181);
      puVar24[0x152] = ((unsigned char *)0x0000118d);
      puVar24[0x154] = ((unsigned char *)0x0000118e);
      puVar24[0x156] = ((unsigned char *)0x0000118c);
      puVar24[0x158] = ((unsigned char *)0x000011a9);
      uVar25 = *(undefined4 *)(param_1 + 0x257c);
      puVar24[0x15a] = ((unsigned char *)0x000011aa);
      puVar24[0x159] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x2580);
      puVar24[0x15c] = ((unsigned char *)0x000011ab);
      puVar24[0x15b] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x2584);
      puVar24[0x15e] = ((unsigned char *)0x000011ac);
      puVar24[0x15d] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x2588);
      puVar24[0x160] = ((unsigned char *)0x000010c0);
      puVar24[0x15f] = uVar25;
      uVar25 = *(undefined4 *)(((unsigned char *)0x0000216c) + param_1);
      puVar24[0x162] = ((unsigned char *)0x000010c1);
      puVar24[0x164] = ((unsigned char *)0x000010c8);
      puVar24[0x166] = ((unsigned char *)0x0000101d);
      puVar24[0x161] = uVar25;
      uVar25 = *(undefined4 *)(((unsigned char *)0x00002128) + param_1);
      puVar24[0x168] = ((unsigned char *)0x0000138a);
      puVar24[0x16a] = ((unsigned char *)0x0000138e);
      puVar24[0x16f] = 0;
      puVar24[0x16c] = ((unsigned char *)0x00001040);
      puVar24[0x169] = 0;
      puVar24[0x16b] = 0;
      puVar24[0x16d] = 0;
      puVar24[0x167] = uVar25;
      puVar24[0x16e] = ((unsigned char *)0x00001150);
      puVar24[0x170] = ((unsigned char *)0x00001100);
      uVar25 = *(undefined4 *)(param_1 + 0x1f1c);
      puVar24[0x172] = ((unsigned char *)0x00001110);
      puVar24[0x171] = uVar25;
      puVar24[0x173] = *(undefined4 *)(((unsigned char *)0x00001f5c) + param_1);
      puVar24[0x174] = ((unsigned char *)0x00001120);
      uVar25 = *(undefined4 *)(param_1 + 0x1f9c);
      puVar24[0x176] = ((unsigned char *)0x00001130);
      puVar24[0x175] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1fdc);
      puVar24[0x178] = ((unsigned char *)0x00001140);
      puVar24[0x177] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x201c);
      puVar24[0x17a] = ((unsigned char *)0x000010f4);
      puVar24[0x17b] = 0xaaaa;
      puVar24[0x17c] = ((unsigned char *)0x00001383);
      puVar24[0x179] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1d34);
      puVar24[0x17e] = ((unsigned char *)0x00001386);
      puVar24[0x17d] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1d38);
      puVar24[0x180] = 0x110f8;
      puVar24[0x17f] = uVar25;
      puVar24[0x181] = *(undefined4 *)(((unsigned char *)0x00001d98) + param_1);
      uVar25 = *(undefined4 *)(param_1 + 0x1d50);
      puVar24[0x183] = ((unsigned char *)0x00001087);
      puVar24[0x182] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1f0c);
      puVar24[0x185] = 0x31080;
      puVar24[0x184] = uVar25;
      puVar24[0x186] = *(undefined4 *)(param_1 + 0x1efc);
      puVar24[0x187] = *(undefined4 *)(param_1 + 0x1f04);
      puVar24[0x188] = *(undefined4 *)(param_1 + 0x1f00);
      puVar24[0x189] = *(undefined4 *)(param_1 + 0x1f08);
      FUN_0004c100(puVar24 + 0xcf,iVar33);
      puVar24 = puVar24 + 0x18c;
      iVar32 = param_1;
      do {
        iVar34 = *(int *)(iVar32 + 0x18c);
        if (iVar34 != 0) {
          iVar36 = 5;
          piVar21 = (int *)(iVar26 + *(int *)(param_1 + 0x18));
          do {
            if (iVar34 == *piVar21) {
              if (*(int *)(iVar34 + 0x34) != 0) goto LAB_0002b2fc;
              break;
            }
            piVar21 = piVar21 + 1;
            iVar36 = iVar36 + -1;
          } while (iVar36 != 0);
          iVar34 = 0;
        }
LAB_0002b2fc:
        if ((iVar22 == 0) || (iVar34 != 0)) {
          puVar24 = (undefined4 *)((int (*)())FUN_0002cd50)(param_1,iVar34,iVar22);
        }
        bVar1 = iVar22 != 0xf;
        iVar26 = iVar26 + 0x14;
        iVar32 = iVar32 + 4;
        iVar22 = iVar22 + 1;
      } while (bVar1);
      *(undefined4 **)(param_1 + 0x298c) = puVar24;
      (**(code **)(param_1 + 0x299c))(iVar33,puVar24);
    }
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    uVar25 = 1;
  }
  else {
LAB_0002a9a0:
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    uVar25 = 0;
  }
  return uVar25;
}

/* FUN_0002b3b0 @ 0x2b3b0 (4 bytes) */
int FUN_0002b3b0()
{
  return;
}

/* FUN_0002b3c0 @ 0x2b3c0 (464 bytes) */
int FUN_0002b3c0(param_1, param_2)
  int param_1;
  int *param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  uint uVar11;
  int *piVar12;
  bool bVar13;
  int iVar14;
  
  uVar7 = *(uint *)(param_1 + 0x2610);
  piVar12 = *(int **)(param_1 + 0x224);
  uVar1 = *(uint *)(param_1 + 0x154) & 0x30000;
  puVar10 = (uint *)(piVar12 + *param_2 * 8 + 0x84);
  if ((uVar7 == 1) && (*(int *)(param_1 + 0x261c) == 2)) {
    uVar7 = 2;
  }
  if (uVar1 == 0x10000) {
    uVar5 = *puVar10 << 0x10 | *puVar10 >> 0x10;
    uVar8 = puVar10[4] << 0x10 | puVar10[4] >> 0x10;
    uVar2 = puVar10[2] << 0x10 | puVar10[2] >> 0x10;
    uVar3 = puVar10[3] << 0x10 | puVar10[3] >> 0x10;
  }
  else {
    uVar5 = *puVar10;
    uVar8 = puVar10[4];
    uVar2 = puVar10[2];
    uVar3 = puVar10[3];
  }
  uVar9 = puVar10[1];
  uVar4 = 0;
  if (1 < uVar7) {
    bVar13 = CARRY4(uVar5,uVar8);
    uVar5 = uVar5 + uVar8;
    uVar4 = (uint)bVar13;
  }
  if (2 < uVar7) {
    bVar13 = CARRY4(uVar5,uVar2);
    uVar5 = uVar5 + uVar2;
    uVar4 = uVar4 + bVar13;
  }
  if (3 < uVar7) {
    bVar13 = CARRY4(uVar5,uVar3);
    uVar5 = uVar5 + uVar3;
    uVar4 = uVar4 + bVar13;
  }
  if (uVar9 != 0) {
    bVar13 = CARRY4(uVar5,uVar9);
    uVar5 = uVar5 + uVar9;
    uVar4 = uVar4 + bVar13;
  }
  if (*piVar12 != 0) {
    puVar10 = (uint *)(piVar12 + 4);
    iVar6 = 0;
    iVar14 = 0x10;
    uVar8 = 0;
    do {
      if (uVar1 == 0x10000) {
        uVar2 = *puVar10 << 0x10 | *puVar10 >> 0x10;
        uVar3 = puVar10[4] << 0x10 | puVar10[4] >> 0x10;
        uVar9 = puVar10[2] << 0x10 | puVar10[2] >> 0x10;
        uVar11 = puVar10[3] << 0x10 | puVar10[3] >> 0x10;
      }
      else {
        uVar2 = *puVar10;
        uVar3 = puVar10[4];
        uVar9 = puVar10[2];
        uVar11 = puVar10[3];
      }
      bVar13 = CARRY4(uVar8,uVar2);
      uVar8 = uVar8 + uVar2;
      iVar6 = iVar6 + (uint)bVar13;
      if (1 < uVar7) {
        bVar13 = CARRY4(uVar8,uVar3);
        uVar8 = uVar8 + uVar3;
        iVar6 = iVar6 + (uint)bVar13;
      }
      if (2 < uVar7) {
        bVar13 = CARRY4(uVar8,uVar9);
        uVar8 = uVar8 + uVar9;
        iVar6 = iVar6 + (uint)bVar13;
      }
      if (3 < uVar7) {
        bVar13 = CARRY4(uVar8,uVar11);
        uVar8 = uVar8 + uVar11;
        iVar6 = iVar6 + (uint)bVar13;
      }
      puVar10 = puVar10 + 8;
      iVar14 = iVar14 + -1;
    } while (iVar14 != 0);
    bVar13 = CARRY4(uVar5,uVar8);
    uVar5 = uVar5 + uVar8;
    uVar4 = uVar4 + iVar6 + (uint)bVar13;
  }
  *piVar12 = 0;
  if (uVar4 != 0) {
    return 0xffffffff;
  }
  return uVar5;
}

/* _gldGetQueryInfo @ 0x2b5a0 (404 bytes) */
int _gldGetQueryInfo(param_1, param_2, param_3, param_4)
  int param_1;
  int *param_2;
  int param_3;
  int *param_4;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined *puVar7;
  int *piVar8;
  
  uVar5 = *(uint *)(param_1 + 0x2610);
  iVar2 = *(int *)(param_1 + 0x224) + 0x210;
  piVar8 = (int *)(iVar2 + *param_2 * 0x20);
  iVar6 = piVar8[2];
  iVar3 = piVar8[4];
  iVar4 = piVar8[3];
  if ((uVar5 == 1) && (*(int *)(param_1 + 0x261c) == 2)) {
    uVar5 = 2;
  }
  bVar1 = *(int *)(iVar2 + *param_2 * 0x20) == -1;
  if ((((bVar1) || ((1 < uVar5 && (iVar3 == -1)))) || ((2 < uVar5 && (iVar6 == -1)))) ||
     ((3 < uVar5 && (iVar4 == -1)))) {
    iVar2 = 0;
  }
  else {
    iVar2 = 1;
  }
  if (param_3 == 0x8866) {
    puVar7 = (undefined *)0x0;
    while ((((bVar1 || ((1 < uVar5 && (iVar3 == -1)))) ||
            (((2 < uVar5 && (iVar6 == -1)) || ((3 < uVar5 && (iVar4 == -1)))))) &&
           (bVar1 = puVar7 != ((unsigned char *)0x00002710), puVar7 = puVar7 + 1, bVar1))) {
      FUN_00009bd0(param_1);
      _usleep(100);
      iVar3 = piVar8[4];
      iVar6 = piVar8[2];
      iVar4 = piVar8[3];
      bVar1 = *piVar8 == -1;
    }
    iVar2 = ((int (*)())FUN_0002b3c0)(param_1,param_2);
    *param_4 = iVar2;
  }
  else if (param_3 == 0x8867) {
    if (iVar2 == 0) {
      _gldFlush(param_1);
    }
    *param_4 = iVar2;
  }
  return 0;
}

/* FUN_0002b7f0 @ 0x2b7f0 (968 bytes) */
int FUN_0002b7f0(param_1, param_2)
  int param_1;
  uint *param_2;
{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 *puVar13;
  int iVar14;
  bool bVar15;
  char in_RESERVE;
  byte in_cr0;
  int iVar16;
  
  piVar8 = *(int **)(param_1 + 0x224);
  uVar12 = *(undefined4 *)(param_1 + 0x1cf8);
  uVar7 = *(uint *)(param_1 + 0x2610);
  puVar13 = (undefined4 *)**(undefined4 **)(param_1 + 0x234);
  uVar6 = *(uint *)(param_1 + 0x154) & 0x30000;
  if ((piVar8 != (int *)0x0) && (((unsigned char *)0x00002b7e)[param_1] != '\0')) {
    bVar1 = *(int *)(param_1 + 0x261c) != 2;
    if ((uVar7 == 1) && (!bVar1)) {
      uVar7 = 2;
    }
    if (*piVar8 == 0) {
      iVar16 = 0x10;
      piVar3 = piVar8;
      do {
        piVar3[4] = 0;
        piVar3[8] = 0;
        piVar3[6] = 0;
        piVar3[7] = 0;
        piVar3 = piVar3 + 8;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
      iVar14 = 0;
      iVar16 = 0;
      piVar8[1] = 1;
    }
    else {
      iVar14 = piVar8[1];
      piVar8[1] = iVar14 + 1U & 0xf;
      uVar11 = piVar8[piVar8[2] * 8 + 0x85];
      if (uVar6 == 0x10000) {
        uVar2 = piVar8[iVar14 * 8 + 4] << 0x10 | (uint)piVar8[iVar14 * 8 + 4] >> 0x10;
      }
      else {
        uVar2 = piVar8[iVar14 * 8 + 4];
      }
      iVar16 = iVar14 * 0x20;
      if ((uVar2 != 0) && (bVar15 = CARRY4(uVar11,uVar2), uVar11 = uVar11 + uVar2, bVar15)) {
        uVar11 = 0xffffffff;
      }
      if (1 < uVar7) {
        if (uVar6 == 0x10000) {
          uVar2 = piVar8[iVar14 * 8 + 8] << 0x10 | (uint)piVar8[iVar14 * 8 + 8] >> 0x10;
        }
        else {
          uVar2 = piVar8[iVar14 * 8 + 8];
        }
        if ((uVar2 != 0) && (bVar15 = CARRY4(uVar11,uVar2), uVar11 = uVar11 + uVar2, bVar15)) {
          uVar11 = 0xffffffff;
        }
      }
      if (2 < uVar7) {
        if (uVar6 == 0x10000) {
          uVar2 = piVar8[iVar14 * 8 + 6] << 0x10 | (uint)piVar8[iVar14 * 8 + 6] >> 0x10;
        }
        else {
          uVar2 = piVar8[iVar14 * 8 + 6];
        }
        if ((uVar2 != 0) && (bVar15 = CARRY4(uVar11,uVar2), uVar11 = uVar11 + uVar2, bVar15)) {
          uVar11 = 0xffffffff;
        }
      }
      uVar2 = uVar11;
      if (3 < uVar7) {
        if (uVar6 == 0x10000) {
          uVar6 = piVar8[iVar14 * 8 + 7] << 0x10 | (uint)piVar8[iVar14 * 8 + 7] >> 0x10;
        }
        else {
          uVar6 = piVar8[iVar14 * 8 + 7];
        }
        if (uVar6 != 0) {
          uVar2 = 0xffffffff;
          if (!CARRY4(uVar6,uVar11)) {
            uVar2 = uVar6 + uVar11;
          }
        }
      }
      piVar8[piVar8[2] * 8 + 0x85] = uVar2;
    }
    piVar3 = puVar13 + 4;
    *(undefined4 *)((int)piVar8 + iVar16 + 0x1c) = 0;
    *(undefined4 *)((int)piVar8 + iVar16 + 0x10) = 0;
    *(undefined4 *)((int)piVar8 + iVar16 + 0x20) = 0;
    *(undefined4 *)((int)piVar8 + iVar16 + 0x18) = 0;
    do {
      if (in_RESERVE != '\0') {
        iVar16 = storeWordConditionalIndexed(*piVar3 + 0x10000,0,piVar3);
        *piVar3 = iVar16;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    puVar9 = (undefined4 *)((uint)(param_2 + 0xb) & 0xffffffe0);
    puVar10 = puVar9 + 4;
    *param_2 = (((int)puVar9 - (int)param_2) + -8) * 0x4000 | 0xc0001000;
    puVar9[-1] = (int)puVar9 - (int)param_2;
    puVar4 = *(uint **)(param_1 + 0x1d8);
    *puVar4 = (int)puVar9 - (int)puVar4 >> 2 | *puVar4;
    *(undefined4 **)(param_1 + 0x1d8) = puVar9;
    *puVar9 = 0x3b000000;
    uVar5 = *puVar13;
    puVar9[2] = 1;
    puVar9[3] = iVar14;
    puVar9[1] = uVar5;
    if (bVar1) {
      if (uVar7 != 0) {
        uVar6 = 0;
        do {
          *puVar10 = ((unsigned char *)0x000010b2);
          puVar10[2] = ((unsigned char *)0x000013d7);
          puVar10[3] = 0;
          puVar10[1] = 1 << (uVar6 & 0x3f);
          uVar6 = uVar6 + 1;
          puVar10 = puVar10 + 4;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
      }
      param_2 = puVar10 + 2;
      *puVar10 = ((unsigned char *)0x000010b2);
      puVar10[1] = 0xf;
    }
    else {
      puVar9[5] = 0;
      puVar9[4] = ((unsigned char *)0x000013c5);
      uVar6 = 0;
      iVar16 = 2;
      puVar13 = puVar9 + 6;
      do {
        puVar9 = puVar13;
        *puVar9 = ((unsigned char *)0x000012fa);
        puVar9[2] = ((unsigned char *)0x000013d7);
        puVar9[3] = 0;
        puVar9[1] = 1 << (uVar6 & 0x3f);
        uVar6 = uVar6 + 1;
        iVar16 = iVar16 + -1;
        puVar13 = puVar9 + 4;
      } while (iVar16 != 0);
      puVar9[4] = ((unsigned char *)0x000012fa);
      puVar9[7] = uVar12;
      param_2 = puVar9 + 8;
      puVar9[5] = 3;
      puVar9[6] = ((unsigned char *)0x000013c5);
    }
    *piVar8 = 1;
  }
  return param_2;
}

/* FUN_0002be90 @ 0x2be90 (12 bytes) */
int FUN_0002be90(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_000a3be0(param_1 + 0x240,param_3);
  return;
}

/* FUN_0002bea0 @ 0x2bea0 (116 bytes) */
int FUN_0002bea0(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  uint param_3;
{
  int iVar1;
  
  iVar1 = (param_2 >> 3 & 1) + (param_2 >> 2 & 1) + (param_2 >> 1 & 1) + (param_2 & 1);
  if (iVar1 == 2) {
    return param_3;
  }
  if (iVar1 == 0) {
    return param_3;
  }
  if (param_2 == 2) {
    return param_3;
  }
  if (iVar1 == 3) {
    return param_3 & 0xfffffffc;
  }
  if (param_2 == 4) {
    return ((int)param_3 / 3) * 3;
  }
  return param_3 & 0xfffffffe;
}

/* FUN_0002bf30 @ 0x2bf30 (180 bytes) */
int FUN_0002bf30(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  uint param_3;
{
  uint uVar1;
  
  switch(param_2) {
  case 0:
    if (param_3 != 0) {
      return param_3;
    }
    break;
  case 1:
    if (1 < (int)(param_3 & 0xfffffffe)) {
      return param_3 & 0xfffffffe;
    }
    break;
  case 2:
  case 3:
    if (1 < (int)param_3) {
      return param_3;
    }
    break;
  case 4:
    uVar1 = ((int)param_3 / 3) * 3;
    if (2 < (int)uVar1) {
      return uVar1;
    }
    break;
  case 5:
  case 6:
  case 9:
    if (2 < (int)param_3) {
      return param_3;
    }
    break;
  case 7:
    if (3 < (int)(param_3 & 0xfffffffc)) {
      return param_3 & 0xfffffffc;
    }
    break;
  case 8:
    if (3 < (int)(param_3 & 0xfffffffe)) {
      return param_3 & 0xfffffffe;
    }
  }
  return 0;
}

/* FUN_0002c020 @ 0x2c020 (148 bytes) */
int FUN_0002c020(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_1 + 0x1874);
  *(uint *)(param_1 + 0x1874) = uVar1 & 0x3fffffff;
  if ((param_2 == 0) && ((*(uint *)(param_1 + 0x1928) & 2) != 0)) {
    iVar2 = 1;
    *(uint *)(param_1 + 0x1874) = uVar1 & 0x3fffffff | 0x80000000;
  }
  else {
    iVar2 = 0;
  }
  if (iVar2 != *(int *)(param_1 + 0x192c)) {
    FUN_00083c80(param_1);
    FUN_00090960(param_1);
    *(int *)(param_1 + 0x192c) = iVar2;
  }
  *(uint *)(param_1 + 0x1928) = *(uint *)(param_1 + 0x1928) & 0xfffffffe;
  return;
}

/* FUN_0002c0c0 @ 0x2c0c0 (180 bytes) */
int FUN_0002c0c0(param_1, param_2)
  int param_1;
  uint *param_2;
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  
  puVar3 = param_2 + 1;
  uVar7 = *(int *)(((unsigned char *)0x0000267c) + param_1) + 1U >> 1;
  uVar1 = (uVar7 - 1) * 0x10000;
  *param_2 = uVar1 | 0x854;
  if (uVar7 != 0) {
    iVar4 = 0;
    uVar6 = uVar7;
    do {
      iVar2 = iVar4 * 4;
      iVar4 = iVar4 + 1;
      *puVar3 = *(uint *)(iVar2 + *(int *)(((unsigned char *)0x00002680) + param_1));
      puVar3 = puVar3 + 1;
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  puVar5 = puVar3 + 1;
  *puVar3 = uVar1 | 0x878;
  if (uVar7 != 0) {
    iVar4 = 0;
    do {
      iVar2 = iVar4 * 4;
      iVar4 = iVar4 + 1;
      *puVar5 = *(uint *)(iVar2 + *(int *)(((unsigned char *)0x00002684) + param_1));
      puVar5 = puVar5 + 1;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  *puVar5 = 0x82d;
  puVar5[1] = *(uint *)(((unsigned char *)0x000026cc) + param_1);
  return puVar5 + 2;
}

/* FUN_0002c180 @ 0x2c180 (164 bytes) */
int FUN_0002c180(param_1, param_2)
  int param_1;
  uint *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  
  puVar5 = param_2 + 1;
  iVar3 = (int)((*(uint *)(((unsigned char *)0x000026d0) + param_1) & 0x1f) + 1) >> 1;
  *param_2 = (iVar3 * 3 + -1) * 0x10000 | 0x831;
  if (iVar3 != 0) {
    iVar2 = 0;
    iVar4 = 0;
    if (iVar3 == 0) {
      iVar3 = 1;
    }
    do {
      iVar1 = iVar2 * 4;
      iVar2 = iVar2 + 1;
      *puVar5 = *(uint *)(iVar1 + *(int *)(((unsigned char *)0x000026d4) + param_1));
      puVar5[1] = *(uint *)(*(int *)(((unsigned char *)0x000026d8) + param_1) + iVar4);
      iVar1 = *(int *)(((unsigned char *)0x000026d8) + param_1) + iVar4;
      iVar4 = iVar4 + 8;
      puVar5[2] = *(uint *)(iVar1 + 4);
      puVar5 = puVar5 + 3;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  *puVar5 = 0x830;
  puVar5[1] = *(uint *)(((unsigned char *)0x000026d0) + param_1);
  return puVar5 + 2;
}

/* FUN_0002c230 @ 0x2c230 (1144 bytes) */
int FUN_0002c230(param_1, param_2)
  int param_1;
  uint *param_2;
{
  undefined2 *puVar1;
  code *pcVar2;
  uint *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  undefined4 local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  
  uVar6 = param_2[3];
  iVar8 = *(int *)(param_1 + 4);
  bVar12 = (uVar6 & 0x10000000) != *(uint *)(param_1 + 0x2780);
  if ((((*param_2 != 0) || (param_2[1] != 0)) || (param_2[2] != 0)) ||
     ((((uVar6 & 0xffefffff) != 0 || (param_2[4] != 0)) || (bVar12)))) {
    if ((((param_2[2] & 0x3f000008) != 0) || ((uVar6 & 0x4c00003) != 0)) ||
       ((*(char *)(iVar8 + 0x2a43) != '\0' || (bVar12)))) {
      FUN_00090990(param_1,param_2);
      FUN_00090840(param_1);
    }
    if (*(char *)(iVar8 + 0x20) == '\0') {
      FUN_000a7d10(param_1);
    }
    FUN_00065370(param_1);
    FUN_00090960(param_1);
    uVar6 = *param_2;
    if (((uVar6 & 0x20000000) != 0) || (*(char *)(iVar8 + 0x2a43) != '\0')) {
      FUN_00022eb0(iVar8,0);
      uVar6 = *param_2;
    }
    if ((((uVar6 & 0x180) != 0) || (*(char *)(iVar8 + 0x2a43) != '\0')) &&
       (*(int *)(iVar8 + 0x150) == 0)) {
      iVar7 = *(int *)(param_1 + 4);
      iVar9 = 0;
      iVar11 = *(int *)(iVar7 + 0x10);
      iVar10 = param_1;
      do {
        puVar1 = (undefined2 *)(((unsigned char *)0x00002dba) + iVar11);
        iVar11 = iVar11 + 2;
        uVar4 = FUN_00016fc0(*puVar1,*(undefined4 *)(iVar7 + 0x154));
        bVar12 = iVar9 != 3;
        iVar9 = iVar9 + 1;
        *(undefined4 *)(iVar10 + 0x2460) = uVar4;
        iVar10 = iVar10 + 4;
      } while (bVar12);
      puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x22d);
      iVar10 = *(int *)(param_1 + 0x2460);
      *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar5;
      if (((iVar10 == 1) && (uVar6 = *(uint *)(iVar7 + 0x154), (uVar6 & 0x800) == 0)) &&
         (((uVar6 & 0x20) != 0 && ((uVar6 & 0x400) != 0)))) {
        (**(code **)(param_1 + 0x275c))(param_1,puVar5);
        if (*(int *)(iVar7 + 0x1e4) + 0x28U < *(uint *)(iVar7 + 0x1dc)) {
          FUN_0001a0f0(iVar7,0x1000000);
        }
        uVar6 = *(uint *)(iVar7 + 0x3c) | 0x800;
        *(uint *)(iVar7 + 0x154) = uVar6;
        *(uint *)(iVar7 + 0x3c) = uVar6;
        local_48 = *(undefined4 *)(*(int *)(iVar7 + 0xf8) + 8);
        local_44 = *(uint *)(iVar7 + 0x3c) & 0xffff3fc0;
        local_40 = *(undefined4 *)(iVar7 + 0xfc);
        local_3c = *(undefined4 *)(iVar7 + 0x100);
        _io_connect_method_scalarI_structureI(*(undefined4 *)(iVar7 + 4),0,&local_48,4,0,0);
        puVar5 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x22d);
        iVar10 = *(int *)(param_1 + 0x2460);
        *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar5;
      }
      iVar10 = FUN_0001a010(iVar7,iVar10);
      if (iVar10 == 0) {
        puVar3 = *(uint **)(iVar7 + 0x1d8);
        *puVar3 = (int)puVar5 - (int)puVar3 >> 2 | *puVar3;
        *(undefined4 **)(iVar7 + 0x1d8) = puVar5;
        *puVar5 = 0x29000000;
        puVar5[1] = *(undefined4 *)(param_1 + 0x2460);
        puVar5[2] = *(undefined4 *)(param_1 + 0x2464);
        puVar5[3] = *(undefined4 *)(param_1 + 0x2468);
        uVar4 = *(undefined4 *)(param_1 + 0x246c);
        puVar5[5] = 0x11;
        puVar5[4] = uVar4;
        puVar5[6] = *(undefined4 *)(param_1 + 0x1ae0);
        puVar5[7] = *(undefined4 *)(param_1 + 0x1ab0);
      }
      else {
        puVar3 = *(uint **)(iVar7 + 0x1d8);
        *puVar3 = (int)puVar5 - (int)puVar3 >> 2 | *puVar3;
        *(undefined4 **)(iVar7 + 0x1d8) = puVar5;
        *puVar5 = 0x29000000;
        uVar4 = *(undefined4 *)(param_1 + 0x2460);
        puVar5[4] = 0x11;
        puVar5[5] = 0x10;
        puVar5[2] = 0x11;
        puVar5[3] = 0x11;
        puVar5[1] = uVar4;
        puVar5[6] = *(undefined4 *)(param_1 + 0x1ae0);
        puVar5[7] = *(undefined4 *)(param_1 + 0x1ab0);
      }
      pcVar2 = *(code **)(param_1 + 0x275c);
      *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar5 + 0x39;
      (*pcVar2)(param_1);
    }
    if (*(short *)((int)param_2 + 6) != 0) {
      ((int (*)())FUN_0002ce40)(param_1,param_2);
    }
    if (*(char *)(param_1 + 0x2435) == '\0') goto LAB_0002c610;
    *(int *)(param_1 + 0x2440) = param_1 + 0x249c;
    *(int *)(param_1 + 0x2444) = param_1 + 0x24bc;
    *(undefined4 *)(param_1 + 0x2494) = 0;
    uVar6 = *(uint *)(param_1 + 0x2488) | 4;
    *(uint *)(param_1 + 0x2488) = uVar6;
  }
  else {
LAB_0002c610:
    uVar6 = *(uint *)(param_1 + 0x2488);
  }
  if (((uVar6 & 4) == 0) && (*(char *)(param_1 + 0x247d) == '\0')) {
    if (*(char *)(param_1 + 0x2595) == '\0') {
      uVar6 = param_2[3] & 0x100000;
    }
    else {
      uVar6 = *(uint *)(*(int *)(iVar8 + 0x14) + 0x120);
    }
    if ((uVar6 == 0) && ((*param_2 & 0x800000) == 0)) goto LAB_0002c67c;
  }
  ((int (*)())FUN_00027990)(param_1,param_2);
LAB_0002c67c:
  if ((((param_2[3] & 0x100000) != 0) || ((*(uint *)(param_1 + 0x2488) & 4) != 0)) ||
     (*(char *)(param_1 + 0x247d) != '\0')) {
    FUN_0001fd00(param_1,param_2);
  }
  return;
}

/* FUN_0002c6c0 @ 0x2c6c0 (184 bytes) */
int FUN_0002c6c0(param_1)
  int param_1;
{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x208);
  puVar1[7] = puVar1[7] | 1;
  *(undefined1 **)(param_1 + 0x2998) = ((unsigned char *)0x0002be70);
  *(undefined **)(param_1 + 0x299c) = ((unsigned char *)0x0002be80);
  *(undefined4 **)(param_1 + 0x298c) = puVar1 + 8;
  FUN_00050300(param_1 + 0x240);
  *puVar1 = *(undefined4 *)(param_1 + 0x1d20);
  puVar1[1] = *(undefined4 *)(param_1 + 0x1cf0);
  puVar1[5] = *(int *)(param_1 + 0x298c) - (int)(puVar1 + 8) >> 2;
  *(undefined1 **)(param_1 + 0x299c) = ((unsigned char *)0x0002be60);
  *(undefined1 **)(param_1 + 0x2998) = ((unsigned char *)0x0002be00);
  if ((uint)puVar1[4] < (uint)puVar1[5]) {
                    
    _exit(1);
  }
  return;
}

/* FUN_0002c790 @ 0x2c790 (932 bytes) */
int FUN_0002c790(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  undefined1 uVar5;
  void *pvVar4;
  uint uVar6;
  int *piVar7;
  int iVar8;
  void *pvVar9;
  int iVar10;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  pvVar9 = (void *)(param_1 + 0x240);
  _memset(pvVar9,0,0x2950);
  ((unsigned char *)0x00002b7d)[param_1] = 0;
  ((unsigned char *)0x00002b7c)[param_1] = 1;
  *(uint *)(param_1 + 0x258c) = *(uint *)(param_1 + 0x258c) & 0xfffffffc | 1;
  uVar5 = ((int (*)())FUN_0002f410)(*(undefined4 *)(param_1 + 0x154));
  ((unsigned char *)0x00002b7f)[param_1] = uVar5;
  *(undefined **)(((unsigned char *)0x00002680) + param_1) = ((unsigned char *)0x000026dc) + param_1;
  *(undefined **)(((unsigned char *)0x00002684) + param_1) = ((unsigned char *)0x000026fc) + param_1;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  pvVar4 = _malloc(0x44);
  *(void **)(((unsigned char *)0x000027cc) + param_1) = pvVar4;
  _memset(pvVar4,0,0x44);
  pvVar4 = _malloc(0x44);
  *(void **)(FUN_000027d0 + param_1) = pvVar4;
  _memset(pvVar4,0,0x44);
  FUN_00020b00(param_1);
  *(undefined4 *)(param_1 + 0x2a64) = *(undefined4 *)(param_2 + 0x30);
  if (*(char *)(param_1 + 0x2a6a) == '\0') {
    FUN_00017b20(param_1);
  }
  *(undefined1 *)(param_1 + 0x2a43) = 1;
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  FUN_00019c50(param_1);
  *(undefined4 *)(param_1 + 0x261c) = 1;
  *(undefined4 *)(param_1 + 0x2610) = 1;
  *(undefined4 *)(param_1 + 0x29d8) = 0xfff0;
  local_38 = DAT_001aa504;
  local_40 = DAT_001aa4fc;
  local_58 = 5;
  local_3c = DAT_001aa500;
  local_34 = DAT_001aa508;
  local_30 = DAT_001aa50c;
  _io_connect_method_scalarI_scalarO(*(undefined4 *)(param_1 + 4),0x14,0,0,&local_40,&local_58);
  *(undefined4 *)(param_1 + 0x2614) = local_3c;
  *(undefined4 *)(param_1 + 0x2618) = local_38;
  *(undefined4 *)(param_1 + 0x261c) = local_34;
  *(undefined4 *)(param_1 + 0x2610) = local_40;
  iVar8 = *(int *)(param_1 + 0x1e4);
  *(int *)(param_1 + 0x1dc) = iVar8 + 0x20;
  *(int *)(param_1 + 0x1d8) = iVar8 + 0x1c;
  *(int *)(param_1 + 0x1e0) = iVar8 + 0x20 + *(int *)(iVar8 + 0x10) * 4 + -0x94;
  *(undefined4 *)(iVar8 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  FUN_000a7050(param_1);
  FUN_000a0f90(pvVar9);
  FUN_00052cc0(pvVar9);
  *(undefined4 *)(((unsigned char *)0x00002b74) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x000026a0) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x000026b0) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00002b78) + param_1) = 0;
  iVar8 = 0x10;
  pvVar4 = pvVar9;
  do {
    *(undefined1 *)((int)pvVar4 + 0x2784) = 0;
    pvVar4 = (void *)((int)pvVar4 + 1);
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  ((unsigned char *)0x00002b82)[param_1] = 0;
  puVar1 = PTR_DAT_001e8994;
  *(undefined4 *)(((unsigned char *)0x000026c8) + param_1) = 7;
  uVar6 = 0;
  *(undefined1 *)(param_1 + 0x2a43) = 1;
  ((unsigned char *)0x000026bd)[param_1] = 1;
  iVar8 = 0x10;
  piVar3 = (int *)((uint)(puVar1 + 0xc) & 0xfffffff3);
  *(int **)PTR_DAT_001e88cc = piVar3;
  piVar7 = piVar3;
  do {
    uVar2 = uVar6 << 8 | uVar6;
    uVar6 = uVar6 + 1;
    uVar2 = uVar2 | uVar2 << 0x10;
    *piVar7 = uVar2 + 0x2030001;
    piVar7[3] = uVar2 + 0xe0f0c0d;
    piVar7[1] = uVar2 + 0x6070405;
    piVar7[2] = uVar2 + 0xa0b0809;
    piVar7 = piVar7 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  uVar6 = 0xffffffff;
  uVar2 = 0xffffffa0;
  iVar10 = 0x10;
  iVar8 = 0;
  while( true ) {
    piVar3[0x40] = uVar6;
    uVar6 = 0xffffffff;
    if ((4 < iVar8) && (uVar6 = 0, iVar8 < 8)) {
      uVar6 = 0xffffffff >> (uVar2 + 0x40 & 0x3f);
    }
    piVar3[0x41] = uVar6;
    uVar6 = 0xffffffff;
    if ((8 < iVar8) && (uVar6 = 0, iVar8 < 0xc)) {
      uVar6 = 0xffffffff >> (uVar2 + 0x20 & 0x3f);
    }
    piVar3[0x42] = uVar6;
    uVar6 = 0xffffffff;
    if (0xc < iVar8) {
      uVar6 = 0xffffffff >> (uVar2 & 0x3f);
    }
    piVar3[0x43] = uVar6;
    iVar8 = iVar8 + 1;
    piVar3 = piVar3 + 4;
    uVar2 = uVar2 + 8;
    iVar10 = iVar10 + -1;
    if (iVar10 == 0) break;
    uVar6 = 0xffffffff;
    if ((0 < iVar8) && (uVar6 = 0, iVar8 < 4)) {
      uVar6 = 0xffffffff >> (iVar8 * 8 & 0x38U);
    }
  }
  ((unsigned char *)0x00002b88)[param_1] = 1;
  local_54 = DAT_001aa4e8;
  local_50 = DAT_001aa4ec;
  local_44 = DAT_001aa4f8;
  local_4c = DAT_001aa4f0;
  local_48 = DAT_001aa4f4;
  FUN_000a9ac0(pvVar9,&local_54);
  ((int (*)())FUN_0002c6c0)(param_1);
  return;
}

/* FUN_0002cb40 @ 0x2cb40 (200 bytes) */
int FUN_0002cb40(param_1)
  int param_1;
{
  if (*(void **)(((unsigned char *)0x000027cc) + param_1) != (void *)0x0) {
    _free(*(void **)(((unsigned char *)0x000027cc) + param_1));
  }
  if (*(void **)(FUN_000027d0 + param_1) != (void *)0x0) {
    _free(*(void **)(FUN_000027d0 + param_1));
  }
  if (*(char *)(param_1 + 0x2a6a) == '\0') {
    FUN_00017e10(param_1);
  }
  FUN_00025da0(param_1);
  if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
    FUN_0001a0f0(param_1,0x1000000);
  }
  thunk_FUN_00054a90(param_1 + 0x240);
  thunk_FUN_000a2330(param_1 + 0x240);
  FUN_000a7970(param_1);
  if (*(int *)(((unsigned char *)0x00002b74) + param_1) != 0) {
    _vfree();
  }
  *(undefined4 *)(((unsigned char *)0x00002b74) + param_1) = 0;
  *(undefined4 *)(((unsigned char *)0x00002b78) + param_1) = 0;
  return;
}

/* FUN_0002cc10 @ 0x2cc10 (28 bytes) */
int FUN_0002cc10(param_1)
  int param_1;
{
  if (*(uint *)(param_1 + 0x1dc) <= *(int *)(param_1 + 0x1e4) + 0x28U) {
    return;
  }
  FUN_0001a0f0(param_1,0x1000000);
  return;
}

/* FUN_0002cc30 @ 0x2cc30 (276 bytes) */
int FUN_0002cc30(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  uint param_3;
  uint param_4;
{
  int iVar1;
  
  if ((int)param_4 < 4) {
    param_4 = ((int (*)())FUN_0002bf30)(param_1,param_3,param_4);
  }
  else {
    iVar1 = (param_3 >> 3 & 1) + (param_3 >> 2 & 1) + (param_3 >> 1 & 1) + (param_3 & 1);
    if (((iVar1 == 2) || (iVar1 == 0)) || (param_3 == 2)) goto LAB_0002cce8;
    if (iVar1 == 3) {
      param_4 = param_4 & 0xfffffffc;
    }
    else if (param_3 == 4) {
      param_4 = ((int)param_4 / 3) * 3;
    }
    else {
      param_4 = param_4 & 0xfffffffe;
    }
  }
  if (param_4 == 0) {
    return 0;
  }
LAB_0002cce8:
  if (((unsigned char *)0x00002b80)[param_1] != '\0') {
    FUN_000a3be0(param_1 + 0x240,param_3);
  }
  if (*(int *)(param_1 + 0x1b68) != 0) {
    ((int (*)())FUN_0002c020)(param_1 + 0x240,param_3);
  }
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  return param_4;
}

/* FUN_0002cd50 @ 0x2cd50 (236 bytes) */
int FUN_0002cd50(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  uint *param_4;
{
  int iVar1;
  int *piVar2;
  bool bVar3;
  uint uVar4;
  uint *puVar5;
  int *piVar6;
  char in_RESERVE;
  
  if (param_2 == 0) {
    puVar5 = *(uint **)(param_1 + 0x1d8);
    *puVar5 = (int)param_4 - (int)puVar5 >> 2 | *puVar5;
    *(uint **)(param_1 + 0x1d8) = param_4;
    *param_4 = param_3 * 0x1000000 + 0x16000000;
    return param_4 + 1;
  }
  piVar2 = (int *)((uint)(param_4 + 0xb) & 0xffffffe0);
  *param_4 = (((int)piVar2 - (int)param_4) + -8) * 0x4000 | 0xc0001000;
  piVar2[-1] = (int)piVar2 - (int)param_4;
  puVar5 = *(uint **)(param_1 + 0x1d8);
  *puVar5 = (int)piVar2 - (int)puVar5 >> 2 | *puVar5;
  *(int **)(param_1 + 0x1d8) = piVar2;
  *piVar2 = param_3 * 0x1000000 + 0x6000000;
  piVar2[1] = **(int **)(param_2 + 0x34);
  piVar6 = (int *)(*(int *)(param_2 + 0x34) + 0x10);
  bVar3 = false;
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar6 + 0x10000,0,piVar6);
      *piVar6 = iVar1;
      bVar3 = true;
    }
  } while (!bVar3);
  uVar4 = *(uint *)(param_2 + 200);
  piVar2[2] = *(int *)(param_2 + 0x40);
  if ((uVar4 & 0xc00000) == 0) {
    return (uint *)(piVar2 + 3);
  }
  piVar2[3] = *(uint *)(param_2 + 0xcc) >> 2 | (uint)*(byte *)(param_2 + 0x38) << 0x18;
  return (uint *)(piVar2 + 4);
}

/* FUN_0002ce40 @ 0x2ce40 (492 bytes) */
int FUN_0002ce40(param_1, param_2)
  int param_1;
  int param_2;
{
  byte bVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  iVar6 = *(int *)(param_1 + 4);
  iVar7 = iVar6;
  for (uVar8 = (uint)*(ushort *)(param_2 + 6); uVar8 != 0; uVar8 = uVar8 >> 1) {
    if (((((uVar8 & 1) != 0) && (iVar5 = *(int *)(iVar7 + 0x18c), iVar5 != 0)) &&
        (*(short *)(*(int *)(iVar5 + 0x30) + 2) == 0x1902)) && (*(char *)(iVar5 + 200) == '\x01')) {
      puVar3 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x3fa);
      *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3;
      puVar2 = *(uint **)(iVar6 + 0x1d8);
      *puVar2 = (int)puVar3 - (int)puVar2 >> 2 | *puVar2;
      *(undefined4 **)(iVar6 + 0x1d8) = puVar3;
      *puVar3 = 0x45000000;
      puVar3[1] = 0x3ed;
      puVar3[2] = 0xd;
      puVar3[3] = **(undefined4 **)(*(int *)(iVar7 + 0x18c) + 0x34);
      bVar1 = *(byte *)(*(int *)(iVar7 + 0x18c) + 0x38);
      puVar3[0x3ed] = ((unsigned char *)0x000013c4);
      puVar3[4] = (uint)bVar1;
      puVar3[0x3f6] = ((unsigned char *)0x000013ca);
      puVar3[0x3f4] = ((unsigned char *)0x000013cc);
      puVar3[0x3ef] = 0x113c8;
      puVar3[0x3f2] = ((unsigned char *)0x000013cd);
      *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar3 + 0x3f8;
      (**(code **)(param_1 + 0x275c))(param_1,puVar3 + 0x3f8);
      if (*(int *)(iVar6 + 0x1e4) + 0x28U < *(uint *)(iVar6 + 0x1dc)) {
        FUN_0001a0f0(iVar6,0x1000000);
      }
      *(undefined1 *)(*(int *)(iVar7 + 0x18c) + 200) = 0;
    }
    iVar7 = iVar7 + 4;
  }
  uVar8 = (uint)*(ushort *)(param_2 + 6);
  uVar4 = (**(code **)(param_1 + 0x2758))(param_1,0x96);
  *(undefined4 *)(FUN_00002748 + param_1 + 4) = uVar4;
  if (uVar8 != 0) {
    iVar5 = 0;
    iVar7 = iVar6;
    do {
      if ((uVar8 & 1) != 0) {
        uVar4 = ((int (*)())FUN_0002cd50)(iVar6,*(undefined4 *)(iVar7 + 0x18c),iVar5);
      }
      uVar8 = uVar8 >> 1;
      iVar5 = iVar5 + 1;
      iVar7 = iVar7 + 4;
    } while (uVar8 != 0);
  }
  *(undefined4 *)(FUN_00002748 + param_1 + 4) = uVar4;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,uVar4);
  return;
}

/* FUN_0002d030 @ 0x2d030 (456 bytes) */
int FUN_0002d030(param_1, param_2)
  int param_1;
  undefined *param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  uVar2 = *(uint *)(param_1 + 0x18) & 0xfff07fff;
  *(uint *)(param_1 + 0x18) = uVar2;
  if ((uVar1 & 0xe00000) == 0) {
    *(uint *)(param_1 + 0x18) = uVar2;
    if (param_2 == ((unsigned char *)0x00002700)) {
      uVar2 = uVar1 & 0xffff87ff | 0x2800;
      *(uint *)(param_1 + 0x14) = uVar2;
    }
    else {
      uVar2 = uVar1;
      if (((unsigned char *)0x00002700) < param_2) {
        if (param_2 == ((unsigned char *)0x00002702)) {
          uVar2 = uVar1 & 0xffff87ff | 0x4800;
          *(uint *)(param_1 + 0x14) = uVar2;
        }
        else if (param_2 < ((unsigned char *)0x00002702)) {
          uVar2 = uVar1 & 0xffff87ff | 0x3000;
          *(uint *)(param_1 + 0x14) = uVar2;
        }
        else if (param_2 == ((unsigned char *)0x00002703)) {
          uVar2 = uVar1 & 0xffff87ff | 0x5000;
          *(uint *)(param_1 + 0x14) = uVar2;
        }
      }
      else if (param_2 == (undefined *)0x2600) {
        uVar2 = uVar1 & 0xffff87ff | 0x800;
        *(uint *)(param_1 + 0x14) = uVar2;
      }
      else if (param_2 == (undefined *)0x2601) {
        uVar2 = uVar1 & 0xffff87ff | 0x1000;
        *(uint *)(param_1 + 0x14) = uVar2;
      }
    }
    goto LAB_0002d190;
  }
  uVar2 = uVar1 & 0xffffe7ff | 0x1800;
  *(uint *)(param_1 + 0x14) = uVar2;
  if (param_2 == ((unsigned char *)0x00002700)) {
LAB_0002d0a0:
    uVar2 = uVar1 & 0xffff87ff | 0x3800;
    *(uint *)(param_1 + 0x14) = uVar2;
  }
  else {
    if (param_2 < ((unsigned char *)0x00002701)) {
      if (param_2 + -0x2600 < (undefined *)0x2) {
        uVar2 = uVar1 & 0xffff87ff | 0x1800;
        *(uint *)(param_1 + 0x14) = uVar2;
      }
      goto LAB_0002d190;
    }
    if (param_2 != ((unsigned char *)0x00002702)) {
      if (param_2 < ((unsigned char *)0x00002702)) goto LAB_0002d0a0;
      if (param_2 != ((unsigned char *)0x00002703)) goto LAB_0002d190;
    }
    uVar2 = uVar1 & 0xffff87ff | 0x5800;
    *(uint *)(param_1 + 0x14) = uVar2;
  }
LAB_0002d190:
  if (*(char *)(param_1 + 0x35) != '\0') {
    uVar1 = *(uint *)(param_1 + 0x18);
    *(uint *)(param_1 + 0x18) = uVar1 & 0xfff1ffff;
    if (1 < (uVar2 >> 0xb & 3)) {
      uVar2 = uVar2 & 0xffffe7ff | 0x800;
      *(uint *)(param_1 + 0x14) = uVar2;
    }
    if ((uVar2 & 0x6000) == 0x4000) {
      uVar2 = uVar2 & 0xffff9fff | 0x2000;
      *(uint *)(param_1 + 0x14) = uVar2;
      *(uint *)(param_1 + 0x18) = uVar1 & 0xfff07fff;
    }
  }
  *(bool *)(param_1 + 0x36) = (uVar2 & 0x1e00) == 0xa00;
  return;
}

/* FUN_0002d210 @ 0x2d210 (140 bytes) */
int FUN_0002d210(param_1, param_2)
  int param_1;
  int param_2;
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  if ((uVar1 & 0xe00000) == 0) {
    if (param_2 == 0x2600) {
      uVar1 = uVar1 & 0xfffff9ff | 0x200;
      *(uint *)(param_1 + 0x14) = uVar1;
    }
    else if (param_2 == 0x2601) {
      uVar1 = uVar1 & 0xfffff9ff | 0x400;
      *(uint *)(param_1 + 0x14) = uVar1;
    }
  }
  else {
    uVar1 = uVar1 & 0xfffff9ff | 0x600;
    *(uint *)(param_1 + 0x14) = uVar1;
  }
  if ((*(char *)(param_1 + 0x35) != '\0') && (1 < (uVar1 >> 9 & 3))) {
    uVar1 = uVar1 & 0xfffff9ff | 0x200;
    *(uint *)(param_1 + 0x14) = uVar1;
  }
  *(bool *)(param_1 + 0x36) = (uVar1 & 0x1e00) == 0xa00;
  return;
}

/* FUN_0002d2b0 @ 0x2d2b0 (2388 bytes) */
void FUN_0002d2b0(double param_1,double param_2,double param_3,double param_4,int param_5)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  float fVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  double dVar15;
  float fStack0000001c;
  float fStack00000028;
  
  fStack00000028 = (float)param_4;
  fStack0000001c = (float)param_1;
  if (*(char *)(param_5 + 0x37) == '\0') {
    return;
  }
  dVar7 = (double)FLOAT_001aa0d4;
  dVar11 = DOUBLE_001aa228;
  if ((dVar7 <= param_1) && (dVar7 = param_1, dVar11 = param_1, (double)FLOAT_001aa0e8 < param_1)) {
    dVar7 = (double)FLOAT_001aa0e8;
    dVar11 = DOUBLE_001aa200;
  }
  dVar8 = (double)FLOAT_001aa0d4;
  dVar12 = DOUBLE_001aa228;
  if ((dVar8 <= param_2) && (dVar8 = param_2, dVar12 = param_2, (double)FLOAT_001aa0e8 < param_2)) {
    dVar8 = (double)FLOAT_001aa0e8;
    dVar12 = DOUBLE_001aa200;
  }
  dVar9 = (double)FLOAT_001aa0d4;
  dVar13 = DOUBLE_001aa228;
  if ((dVar9 <= param_3) && (dVar9 = param_3, dVar13 = param_3, (double)FLOAT_001aa0e8 < param_3)) {
    dVar9 = (double)FLOAT_001aa0e8;
    dVar13 = DOUBLE_001aa200;
  }
  dVar15 = (double)fStack00000028;
  dVar10 = (double)FLOAT_001aa0d4;
  dVar14 = DOUBLE_001aa228;
  if ((dVar10 <= dVar15) && (dVar10 = dVar15, dVar14 = dVar15, (double)FLOAT_001aa0e8 < dVar15)) {
    dVar10 = (double)FLOAT_001aa0e8;
    dVar14 = DOUBLE_001aa200;
  }
  dVar11 = dVar11 * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= dVar11) {
    fVar2 = (float)((int)(dVar11 - DOUBLE_001aa1e8) + -0x80000000);
  }
  else {
    fVar2 = (float)(int)dVar11;
  }
  dVar12 = dVar12 * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= dVar12) {
    uVar3 = (int)(dVar12 - DOUBLE_001aa1e8) + 0x80000000;
  }
  else {
    uVar3 = (uint)dVar12;
  }
  dVar13 = dVar13 * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= dVar13) {
    uVar4 = (int)(dVar13 - DOUBLE_001aa1e8) + 0x80000000;
  }
  else {
    uVar4 = (uint)dVar13;
  }
  dVar14 = dVar14 * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= dVar14) {
    fVar6 = (float)((int)(dVar14 - DOUBLE_001aa1e8) + -0x80000000);
  }
  else {
    fVar6 = (float)(int)dVar14;
  }
  switch(*(char *)(param_5 + 0x37)) {
  default:
    fVar6 = 0.0;
    break;
  case '\x01':
  case '\x03':
    fVar6 = fVar2;
    break;
  case '\x02':
    break;
  case '\x04':
  case '\x0f':
  case '\x16':
    fVar6 = (float)((uint)fVar2 | (int)fVar6 << 8);
    break;
  case '\x05':
    fVar6 = (float)(((uint)fVar2 & 0xf8) << 8 | (uVar3 & 0xfc) << 3 | uVar4 >> 3);
    break;
  case '\x06':
    fVar6 = (float)(((uint)fVar6 & 0xf0) << 8 | ((uint)fVar2 & 0xf0) << 4 | uVar3 & 0xf0 |
                   uVar4 >> 4);
    break;
  case '\a':
    fVar6 = (float)(((uint)fVar6 & 0x80) << 8 | ((uint)fVar2 & 0xf8) << 7 | (uVar3 & 0xf8) << 2 |
                   uVar4 >> 3);
    break;
  case '\b':
  case '\v':
  case '\f':
  case '\r':
  case '\x0e':
  case '\x11':
  case '\x17':
  case '\x1d':
  case '&':
  case '\'':
    fVar6 = (float)(uVar4 | (int)fVar6 << 0x18 | (int)fVar2 << 0x10 | uVar3 << 8);
    break;
  case '\t':
  case '\n':
  case '\x12':
  case '\x18':
  case '\x1e':
    fVar6 = (float)((uint)fVar2 | uVar3 << 8 | (int)fVar6 << 0x18 | uVar4 << 0x10);
    break;
  case '\x10':
    dVar7 = dVar7 * (double)FLOAT_001aa14c + (double)FLOAT_001aa10c;
    dVar11 = (double)(float)dVar7;
    if (DOUBLE_001aa1e8 <= dVar11) {
      uVar3 = (int)(dVar11 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar3 = (uint)dVar7;
    }
    goto LAB_0002d9d4;
  case '\x13':
  case '\x15':
    fVar6 = fStack0000001c;
    break;
  case '\x14':
    fVar6 = fStack00000028;
    break;
  case '\x19':
  case '\x1b':
    dVar7 = dVar7 * (double)FLOAT_001aa14c + (double)FLOAT_001aa10c;
    dVar11 = (double)(float)dVar7;
    if (DOUBLE_001aa1e8 <= dVar11) {
      uVar3 = (int)(dVar11 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar3 = (uint)dVar7;
    }
    goto LAB_0002d9d0;
  case '\x1a':
    dVar7 = dVar10 * (double)FLOAT_001aa14c + (double)FLOAT_001aa10c;
    dVar11 = (double)(float)dVar7;
    if (DOUBLE_001aa1e8 <= dVar11) {
      uVar3 = (int)(dVar11 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar3 = (uint)dVar7;
    }
LAB_0002d9d0:
    uVar3 = uVar3 & 0xffff;
LAB_0002d9d4:
    fVar6 = (float)(uVar3 | uVar3 << 0x10);
    break;
  case '\x1c':
    dVar7 = dVar7 * (double)FLOAT_001aa14c + (double)FLOAT_001aa10c;
    dVar11 = (double)(float)dVar7;
    if (DOUBLE_001aa1e8 <= dVar11) {
      uVar3 = (int)(dVar11 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar3 = (uint)dVar7;
    }
    dVar7 = dVar10 * (double)FLOAT_001aa14c + (double)FLOAT_001aa10c;
    dVar11 = (double)(float)dVar7;
    if (DOUBLE_001aa1e8 <= dVar11) {
      iVar1 = (int)(dVar11 - DOUBLE_001aa1e8) + -0x80000000;
    }
    else {
      iVar1 = (int)dVar7;
    }
    fVar6 = (float)(uVar3 & 0xffff | iVar1 << 0x10);
    break;
  case '\x1f':
  case '!':
    uVar3 = ((uint (*)())FUN_0001d7c0)(param_1);
    fVar6 = (float)(uVar3 << 0x10 | uVar3);
    break;
  case ' ':
    uVar3 = ((uint (*)())FUN_0001d7c0)();
    fVar6 = (float)(uVar3 << 0x10 | uVar3);
    break;
  case '\"':
    uVar3 = ((uint (*)())FUN_0001d7c0)(param_1);
    iVar1 = ((uint (*)())FUN_0001d7c0)((double)fStack00000028);
    fVar6 = (float)(uVar3 | iVar1 << 0x10);
    break;
  case '#':
    dVar7 = dVar7 * (double)FLOAT_001aa154 + (double)FLOAT_001aa10c;
    dVar11 = (double)(float)dVar7;
    if (DOUBLE_001aa1e8 <= dVar11) {
      uVar3 = (int)(dVar11 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar3 = (uint)dVar7;
    }
    uVar3 = uVar3 & 0x3ff;
    dVar7 = dVar10 * (double)FLOAT_001aa158 + (double)FLOAT_001aa10c;
    dVar11 = (double)(float)dVar7;
    if (DOUBLE_001aa1e8 <= dVar11) {
      iVar1 = (int)(dVar11 - DOUBLE_001aa1e8) + -0x80000000;
    }
    else {
      iVar1 = (int)dVar7;
    }
    dVar7 = dVar9 * (double)FLOAT_001aa154 + (double)FLOAT_001aa10c;
    dVar11 = (double)(float)dVar7;
    if (DOUBLE_001aa1e8 <= dVar11) {
      uVar4 = (int)(dVar11 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar4 = (uint)dVar7;
    }
    uVar4 = iVar1 << 0x1e | (uVar4 & 0x3ff) << 0x14;
    dVar7 = dVar8 * (double)FLOAT_001aa154 + (double)FLOAT_001aa10c;
    dVar11 = (double)(float)dVar7;
    if (DOUBLE_001aa1e8 <= dVar11) {
      uVar5 = (int)(dVar11 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar5 = (uint)dVar7;
    }
    goto LAB_0002dcb4;
  case '$':
    dVar11 = dVar9 * (double)FLOAT_001aa154 + (double)FLOAT_001aa10c;
    dVar12 = (double)(float)dVar11;
    if (DOUBLE_001aa1e8 <= dVar12) {
      uVar3 = (int)(dVar12 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar3 = (uint)dVar11;
    }
    uVar3 = uVar3 & 0x3ff;
    dVar11 = dVar10 * (double)FLOAT_001aa158 + (double)FLOAT_001aa10c;
    dVar12 = (double)(float)dVar11;
    if (DOUBLE_001aa1e8 <= dVar12) {
      iVar1 = (int)(dVar12 - DOUBLE_001aa1e8) + -0x80000000;
    }
    else {
      iVar1 = (int)dVar11;
    }
    dVar7 = dVar7 * (double)FLOAT_001aa154 + (double)FLOAT_001aa10c;
    dVar11 = (double)(float)dVar7;
    if (DOUBLE_001aa1e8 <= dVar11) {
      uVar4 = (int)(dVar11 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar4 = (uint)dVar7;
    }
    uVar4 = iVar1 << 0x1e | (uVar4 & 0x3ff) << 0x14;
    dVar7 = dVar8 * (double)FLOAT_001aa154 + (double)FLOAT_001aa10c;
    dVar11 = (double)(float)dVar7;
    if (DOUBLE_001aa1e8 <= dVar11) {
      uVar5 = (int)(dVar11 - DOUBLE_001aa1e8) + 0x80000000;
    }
    else {
      uVar5 = (uint)dVar7;
    }
LAB_0002dcb4:
    fVar6 = (float)(uVar3 | uVar4 | (uVar5 & 0x3ff) << 10);
    break;
  case '(':
    fVar6 = (float)((uint)fVar2 & 0xe0 | uVar3 >> 3 & 0x1c | uVar4 >> 6);
    break;
  case ')':
    dVar7 = dVar7 * (double)FLOAT_001aa150 + (double)FLOAT_001aa10c;
    dVar11 = (double)(float)dVar7;
    if (DOUBLE_001aa1e8 <= dVar11) {
      iVar1 = (int)(dVar11 - DOUBLE_001aa1e8) + -0x80000000;
    }
    else {
      iVar1 = (int)dVar7;
    }
    fVar6 = (float)(iVar1 << 8);
  }
  *(float *)(param_5 + 0x28) = fVar6;
  return;
}

/* FUN_0002dcf0 @ 0x2dcf0 (236 bytes) */
int FUN_0002dcf0(param_1)
  int param_1;
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  
  iVar3 = *(int *)(param_1 + 0x30);
  bVar1 = *(byte *)(iVar3 + 1);
  bVar5 = bVar1 & 0xf;
  *(byte *)(param_1 + 0x6c) = bVar5;
  iVar3 = *(short *)(iVar3 + 0x3c) * 0x18 + iVar3;
  uVar4 = (uint)*(byte *)(iVar3 + 0xaa);
  uVar6 = (uint)*(ushort *)(iVar3 + 0xa4) + uVar4 * -2;
  if ((int)uVar6 < 1) {
    uVar6 = 1;
  }
  uVar2 = (uint)*(ushort *)(iVar3 + 0xa6) + uVar4 * -2;
  if ((int)uVar2 < 1) {
    uVar2 = 1;
  }
  uVar4 = (uint)*(ushort *)(iVar3 + 0xa8) + uVar4 * -2;
  if ((int)uVar4 < 1) {
    uVar4 = 1;
  }
  if (bVar5 == 1) {
    if ((uVar6 & uVar6 - 1) != 0) {
      return 1;
    }
    if ((uVar2 & uVar2 - 1) != 0) {
      return 1;
    }
    uVar6 = uVar4 & uVar4 - 1;
  }
  else if (((bVar1 & 0xf) == 0) || (bVar5 == 3)) {
    if ((uVar6 & uVar6 - 1) != 0) {
      return 1;
    }
    uVar6 = uVar2 & uVar2 - 1;
  }
  else {
    if (bVar5 != 4) {
      return 1;
    }
    uVar6 = uVar6 & uVar6 - 1;
  }
  if (uVar6 != 0) {
    return 1;
  }
  return 0;
}

/* FUN_0002ddf0 @ 0x2ddf0 (3396 bytes) */
int FUN_0002ddf0(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  ushort uVar9;
  short sVar10;
  undefined2 uVar11;
  float fVar12;
  undefined *puVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  short sVar19;
  ushort uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  char cVar25;
  byte bVar26;
  int iVar27;
  ushort *puVar28;
  char cVar30;
  int iVar29;
  int *piVar31;
  double dVar32;
  double dVar33;
  
  piVar31 = param_2 + 0xf;
  param_2[0x2e] = (int)param_2;
  dVar32 = DOUBLE_001aa240;
  puVar28 = (ushort *)param_2[0xc];
  *(byte *)((int)param_2 + 0x3d) = (byte)(-(uint)puVar28[0x2e] >> 0x1f);
  uVar15 = (uint)((double)*(float *)(puVar28 + 0x18) + dVar32);
  uVar17 = (uint)((double)*(float *)(puVar28 + 0x1a) + dVar32);
  uVar14 = (uint)*(byte *)(puVar28 + 0x2f);
  uVar16 = uVar15 + uVar14;
  if ((int)uVar16 < 0) {
    uVar16 = 0;
  }
  if ((int)uVar14 < (int)uVar16) {
    uVar14 = uVar16;
  }
  uVar23 = (uint)(short)puVar28[0x1e];
  uVar16 = uVar17 + uVar23;
  if (((int)uVar16 < (int)uVar14) && (uVar14 = uVar23, (int)uVar23 < (int)uVar16)) {
    uVar14 = uVar16;
  }
  uVar16 = (uint)*(byte *)((int)puVar28 + 0x5f);
  if ((int)uVar14 <= (int)(uint)*(byte *)((int)puVar28 + 0x5f)) {
    uVar16 = uVar14;
  }
  if ((int)uVar15 < 0) {
    uVar15 = 0;
  }
  if ((int)uVar15 < (int)uVar17) {
    uVar17 = uVar15;
  }
  if ((int)((int)(short)puVar28[0x1f] - uVar23) < (int)uVar17) {
    uVar17 = (int)(short)puVar28[0x1f] - uVar23;
  }
  uVar15 = uVar17;
  if ((int)(uint)*(byte *)(puVar28 + 0x32) < (int)uVar17) {
    uVar15 = (uint)*(byte *)(puVar28 + 0x32);
  }
  if ((int)uVar15 < 0) {
    uVar15 = 0;
  }
  uVar15 = uVar15 & 0xff;
  uVar14 = uVar17;
  if ((int)(uint)*(byte *)((int)puVar28 + 0x65) < (int)uVar17) {
    uVar14 = (uint)*(byte *)((int)puVar28 + 0x65);
  }
  if ((int)uVar14 < 0) {
    uVar14 = 0;
  }
  uVar14 = uVar14 & 0xff;
  if ((int)(uint)*(byte *)(puVar28 + 0x33) < (int)uVar17) {
    uVar17 = (uint)*(byte *)(puVar28 + 0x33);
  }
  if ((int)uVar17 < 0) {
    uVar17 = 0;
  }
  uVar4 = *(ushort *)(param_2 + 0x1d);
  bVar1 = *(byte *)((int)param_2 + 0x73);
  uVar5 = *(ushort *)((int)param_2 + 0x7a);
  uVar18 = (uint)*(ushort *)((int)param_2 + 0x3e);
  uVar6 = *(ushort *)(param_2 + 0x1f);
  uVar7 = *(ushort *)((int)param_2 + 0x76);
  uVar23 = (uint)uVar7;
  uVar8 = *(ushort *)(param_2 + 0x1e);
  uVar22 = (uint)uVar8;
  *(undefined1 *)((int)param_2 + 0x6e) = *(undefined1 *)(puVar28 + 0x35);
  bVar2 = *(byte *)(param_2 + 0x1b);
  *(ushort *)(param_2 + 0x1d) = puVar28[1];
  uVar21 = (uint)*(byte *)(param_2 + 0xe);
  *(byte *)((int)param_2 + 0x73) = *(byte *)(param_2 + 0xe);
  uVar17 = (uint)*(byte *)(puVar28 + 0x33) - (uVar17 & 0xff);
  *(short *)((int)param_2 + 0x7a) = (short)uVar17;
  uVar20 = puVar28[1];
  *(ushort *)(param_2 + 0x1f) = *(ushort *)((int)param_2 + 0x3e);
  *(ushort *)(param_2 + 0x1d) = uVar20;
  bVar26 = *(byte *)(param_2[0xc] + 1) & 0xf;
  *(byte *)(param_2 + 0x1b) = bVar26;
  dVar32 = DOUBLE_001aa250;
  switch(bVar26) {
  case 0:
    uVar23 = 1 << (*(byte *)(puVar28 + 0x32) - uVar15 & 0x3f);
    *(short *)((int)param_2 + 0x76) = (short)uVar23;
    bVar3 = *(byte *)((int)puVar28 + 0x65);
    *(undefined1 *)((int)param_2 + 0x6d) = 2;
    uVar22 = 1 << (bVar3 - uVar14 & 0x3f);
    *(short *)(param_2 + 0x1e) = (short)uVar22;
    param_2[0x20] = (int)(float)((double)CONCAT44(0x43300000,uVar23 & 0xffff) - dVar32);
    param_2[0x21] = (int)(float)((double)CONCAT44(0x43300000,uVar22 & 0xffff) - dVar32);
    break;
  case 1:
    uVar23 = 1 << (*(byte *)(puVar28 + 0x32) - uVar15 & 0x3f);
    *(short *)((int)param_2 + 0x76) = (short)uVar23;
    bVar3 = *(byte *)((int)puVar28 + 0x65);
    *(undefined1 *)((int)param_2 + 0x6d) = 3;
    uVar22 = 1 << (bVar3 - uVar14 & 0x3f);
    *(short *)(param_2 + 0x1e) = (short)uVar22;
    param_2[0x20] = (int)(float)((double)CONCAT44(0x43300000,uVar23 & 0xffff) - dVar32);
    param_2[0x21] = (int)(float)((double)CONCAT44(0x43300000,uVar22 & 0xffff) - dVar32);
    break;
  case 2:
    uVar23 = (uint)puVar28[uVar16 * 0xc + 0x52] +
             (uint)*(byte *)(puVar28 + uVar16 * 0xc + 0x55) * -2;
    *(short *)((int)param_2 + 0x76) = (short)uVar23;
    bVar3 = *(byte *)(puVar28 + uVar16 * 0xc + 0x55);
    uVar9 = puVar28[uVar16 * 0xc + 0x53];
    *(undefined1 *)((int)param_2 + 0x6d) = 2;
    uVar22 = (uint)uVar9 + (uint)bVar3 * -2;
    *(short *)(param_2 + 0x1e) = (short)uVar22;
    param_2[0x20] = (int)(float)((double)CONCAT44(0x43300000,uVar23 & 0xffff) - dVar32);
    param_2[0x21] = (int)(float)((double)CONCAT44(0x43300000,uVar22 & 0xffff) - dVar32);
    break;
  case 3:
    iVar27 = ((int (*)())FUN_0002dcf0)(param_2);
    if (iVar27 == 0) {
      *(short *)((int)param_2 + 0x76) = (short)(1 << (*(byte *)(puVar28 + 0x32) - uVar15 & 0x3f));
      *(short *)(param_2 + 0x1e) = (short)(1 << (*(byte *)((int)puVar28 + 0x65) - uVar14 & 0x3f));
    }
    else {
      *(ushort *)((int)param_2 + 0x76) =
           puVar28[uVar16 * 0xc + 0x52] + (ushort)*(byte *)(puVar28 + uVar16 * 0xc + 0x55) * -2;
      *(ushort *)(param_2 + 0x1e) =
           puVar28[uVar16 * 0xc + 0x53] + (ushort)*(byte *)(puVar28 + uVar16 * 0xc + 0x55) * -2;
    }
    dVar32 = DOUBLE_001aa250;
    uVar23 = (uint)*(ushort *)((int)param_2 + 0x76);
    uVar22 = (uint)*(ushort *)(param_2 + 0x1e);
    *(undefined1 *)((int)param_2 + 0x6d) = 2;
    uVar21 = (uint)*(byte *)((int)param_2 + 0x73);
    bVar26 = *(byte *)(param_2 + 0x1b);
    uVar17 = (uint)*(ushort *)((int)param_2 + 0x7a);
    uVar20 = *(ushort *)(param_2 + 0x1d);
    uVar18 = (uint)*(ushort *)(param_2 + 0x1f);
    param_2[0x21] =
         (int)(float)((double)CONCAT44(0x43300000,(uint)*(ushort *)(param_2 + 0x1e)) - dVar32);
    param_2[0x20] =
         (int)(float)((double)CONCAT44(0x43300000,(uint)*(ushort *)((int)param_2 + 0x76)) - dVar32);
    break;
  case 4:
    iVar27 = ((int (*)())FUN_0002dcf0)(param_2);
    if (iVar27 == 0) {
      *(short *)((int)param_2 + 0x76) = (short)(1 << (*(byte *)(puVar28 + 0x32) - uVar15 & 0x3f));
    }
    else {
      *(ushort *)((int)param_2 + 0x76) =
           puVar28[uVar16 * 0xc + 0x52] + (ushort)*(byte *)(puVar28 + uVar16 * 0xc + 0x55) * -2;
    }
    uVar23 = (uint)*(ushort *)((int)param_2 + 0x76);
    uVar22 = 1;
    *(undefined2 *)(param_2 + 0x1e) = 1;
    param_2[0x21] = 0x3f800000;
    *(undefined1 *)((int)param_2 + 0x6d) = 1;
    uVar21 = (uint)*(byte *)((int)param_2 + 0x73);
    bVar26 = *(byte *)(param_2 + 0x1b);
    uVar17 = (uint)*(ushort *)((int)param_2 + 0x7a);
    uVar20 = *(ushort *)(param_2 + 0x1d);
    uVar18 = (uint)*(ushort *)(param_2 + 0x1f);
    param_2[0x20] =
         (int)(float)((double)CONCAT44(0x43300000,(uint)*(ushort *)((int)param_2 + 0x76)) -
                     DOUBLE_001aa250);
  }
  if (((((bVar1 != uVar21) || (bVar2 != bVar26)) || ((uint)uVar7 != (uVar23 & 0xffff))) ||
      (((uint)uVar8 != (uVar22 & 0xffff) || ((uint)uVar5 != (uVar17 & 0xffff))))) ||
     ((uVar4 != uVar20 || (uVar6 != uVar18)))) {
    *(undefined1 *)((int)param_2 + 0x71) = 0;
    uVar14 = param_2[0x17];
    param_2[0x15] = param_2[0x15] & 0xbfdfffff;
    uVar24 = ((uVar22 & 0xffff) - 1) * 0x20 & 0x10000 |
             ((uVar23 & 0xffff) - 1) * 0x10 & 0x8000 | uVar18 - 1 & 0x3fff;
    param_2[0x17] = uVar14 & 0xfffffe1f;
    param_2[0x18] = uVar24;
    puVar13 = PTR_DAT_001e88c8;
    param_2[0x16] =
         -uVar18 & 0x80000000 |
         (uVar17 & 0xf) << 0x16 |
         (uVar22 - 1) * 0x800 & 0x3ff800 | uVar23 - 1 & 0x7ff | param_2[0x16] & 0x40000000U;
    uVar15 = *(uint *)(puVar13 + uVar21 * 0x24 + 0x1c) >> 7 & 0x1f;
    param_2[0x17] = uVar15 | uVar14 & 0xfffffe00;
    if (uVar21 == 0x29) {
      param_2[0x18] = uVar24 | 0x4000;
      param_2[0x17] = uVar14 & 0xffe00000 | 6;
    }
    else {
      uVar17 = (*(uint *)(puVar13 + uVar21 * 0x24 + 0x1c) & 0x70) << 5;
      param_2[0x17] = uVar17 | uVar15 | uVar14 & 0xfffff000;
      uVar23 = (*(uint *)(puVar13 + uVar21 * 0x24 + 0x1c) & 0xe) << 0xb;
      param_2[0x17] = uVar23 | uVar17 | uVar15 | uVar14 & 0xffff8000;
      uVar18 = *(uint *)(puVar13 + uVar21 * 0x24 + 0x20) >> 0xe & 0x38000;
      param_2[0x17] = uVar18 | uVar23 | uVar17 | uVar15 | uVar14 & 0xfffc0000;
      param_2[0x17] =
           *(uint *)(puVar13 + uVar21 * 0x24 + 0x20) >> 8 & 0x1c0000 |
           uVar18 | uVar23 | uVar17 | uVar15 | uVar14 & 0xffe00000;
    }
    uVar17 = param_2[0x17];
    uVar15 = (*(uint *)(puVar13 + uVar21 * 0x24 + 0x20) >> 0x19 & 1) << 0x16;
    param_2[0x17] = uVar15 | uVar17 & 0xff3fffff;
    *(byte *)((int)param_2 + 0x71) = (puVar13[uVar21 * 0x24 + 0x20] ^ 1) & 1;
    if (bVar26 == 0) {
      param_2[0x17] = uVar15 | uVar17 & 0xf93fffff | 0x4000000;
    }
    else if (*(char *)((int)param_2 + 0x6d) == '\x03') {
      param_2[0x17] = uVar15 | uVar17 & 0xf93fffff | 0x2000000;
    }
    else {
      param_2[0x17] = uVar15 | uVar17 & 0xf93fffff;
    }
    if (uVar20 == 0x1907) {
      param_2[0x17] = param_2[0x17] & 0xfffff1ffU | 0xa00;
    }
  }
  uVar15 = (uint)param_2[0x32] >> 0x16;
  if (*param_2 == 0) {
    if ((*puVar28 & 0x400) == 0) {
      param_2[0x10] = uVar15 << 0x1e;
    }
    else {
      param_2[0x10] = uVar15 << 0x1e | uVar16;
    }
  }
  else {
    param_2[0x10] = uVar15 << 0x1e | *(uint *)(uVar16 * 0x20 + *param_2 + 0x48);
  }
  iVar27 = param_2[0xc];
  cVar30 = *(char *)((int)param_2 + 0x72);
  if ((float)param_2[0x24] != *(float *)(iVar27 + 0x2c)) {
    param_2[0x24] = (int)*(float *)(iVar27 + 0x2c);
    dVar32 = (double)*(float *)(iVar27 + 0x2c);
    if (DOUBLE_001aa1e8 <= dVar32) {
      iVar29 = (int)(dVar32 - DOUBLE_001aa1e8) + -0x80000000;
    }
    else {
      iVar29 = (int)*(float *)(iVar27 + 0x2c);
    }
    uVar15 = *(uint *)(&DAT_001aa510 + iVar29 * 4);
    if (((uint)param_2[0x14] >> 0x15 & 7) != uVar15) {
      *(undefined2 *)((int)param_2 + 0xa2) = 0xffff;
      *(undefined2 *)(param_2 + 0x28) = 0xffff;
      param_2[0x14] = (uVar15 & 7) << 0x15 | param_2[0x14] & 0xff1fffffU;
    }
  }
  sVar10 = *(short *)(iVar27 + 0x16);
  if (*(short *)(param_2 + 0x28) == sVar10) {
    sVar19 = *(short *)(iVar27 + 0x18);
    if (*(short *)((int)param_2 + 0xa2) == sVar19) {
      cVar25 = *(char *)((int)param_2 + 0x71);
      if (cVar25 == *(char *)(param_2 + 0x1c)) goto LAB_0002e708;
      goto LAB_0002e690;
    }
    if (*(char *)((int)param_2 + 0x71) != *(char *)(param_2 + 0x1c)) goto LAB_0002e690;
LAB_0002e6d8:
    *(short *)((int)param_2 + 0xa2) = sVar19;
    ((int (*)())FUN_0002d210)(piVar31);
    cVar25 = *(char *)((int)param_2 + 0x71);
  }
  else {
LAB_0002e690:
    *(short *)(param_2 + 0x28) = sVar10;
    ((int (*)())FUN_0002d030)(piVar31,sVar10);
    *(byte *)((int)param_2 + 0x3d) = (byte)(-(uint)*(ushort *)(param_2[0xc] + 0x5c) >> 0x1f);
    sVar19 = *(short *)(iVar27 + 0x18);
    if ((*(short *)((int)param_2 + 0xa2) != sVar19) ||
       (cVar25 = *(char *)((int)param_2 + 0x71), cVar25 != *(char *)(param_2 + 0x1c)))
    goto LAB_0002e6d8;
  }
  if (cVar30 != *(char *)((int)param_2 + 0x72)) {
    *(undefined2 *)((int)param_2 + 0x9e) = 0xffff;
    *(undefined2 *)((int)param_2 + 0x9a) = 0xffff;
    *(undefined2 *)(param_2 + 0x27) = 0xffff;
    cVar30 = *(char *)((int)param_2 + 0x72);
  }
LAB_0002e708:
  *(char *)(param_2 + 0x1c) = cVar25;
  uVar15 = (uint)*(ushort *)(iVar27 + 0x10);
  if (*(ushort *)((int)param_2 + 0x9a) != uVar15) {
    *(ushort *)((int)param_2 + 0x9a) = *(ushort *)(iVar27 + 0x10);
    if (cVar30 == '\0') {
      param_2[0x14] =
           (uVar15 * 0x29 >> 0x10 & 1 | uVar15 * 0x97 >> 9 & 2 | uVar15 * 0x113 >> 7 & 4) ^ 2 |
           param_2[0x14] & 0xfffffff8U;
    }
    else {
      param_2[0x14] =
           (uVar15 * 0x29 >> 0x10 & 1 | uVar15 * 0x73 >> 5 & 2 | uVar15 * 7 >> 3 & 4) ^ 2 |
           param_2[0x14] & 0xfffffff8U;
    }
  }
  uVar15 = (uint)*(ushort *)(iVar27 + 0x12);
  if (*(ushort *)(param_2 + 0x27) != uVar15) {
    *(ushort *)(param_2 + 0x27) = *(ushort *)(iVar27 + 0x12);
    if (*(char *)((int)param_2 + 0x6d) == '\x01') {
      param_2[0x14] = param_2[0x14] & 0xffffffc7;
    }
    else if (cVar30 == '\0') {
      param_2[0x14] =
           ((uVar15 * 0x29 >> 0x10 & 1 | uVar15 * 0x97 >> 9 & 2 | uVar15 * 0x113 >> 7 & 4) ^ 2) << 3
           | param_2[0x14] & 0xffffffc7U;
    }
    else {
      param_2[0x14] =
           ((uVar15 * 0x29 >> 0x10 & 1 | uVar15 * 0x73 >> 5 & 2 | uVar15 * 7 >> 3 & 4) ^ 2) << 3 |
           param_2[0x14] & 0xffffffc7U;
    }
  }
  uVar15 = (uint)*(ushort *)(iVar27 + 0x14);
  if (*(ushort *)((int)param_2 + 0x9e) != uVar15) {
    *(ushort *)((int)param_2 + 0x9e) = *(ushort *)(iVar27 + 0x14);
    if (*(char *)((int)param_2 + 0x6d) == '\x03') {
      if (cVar30 == '\0') {
        param_2[0x14] =
             ((uVar15 * 0x29 >> 0x10 & 1 | uVar15 * 0x97 >> 9 & 2 | uVar15 * 0x113 >> 7 & 4) ^ 2) <<
             6 | param_2[0x14] & 0xfffffe3fU;
      }
      else {
        param_2[0x14] =
             ((uVar15 * 0x29 >> 0x10 & 1 | uVar15 * 0x73 >> 5 & 2 | uVar15 * 7 >> 3 & 4) ^ 2) << 6 |
             param_2[0x14] & 0xfffffe3fU;
      }
    }
    else {
      param_2[0x14] = param_2[0x14] & 0xfffffe3f;
    }
  }
  iVar29 = param_2[0xc];
  sVar10 = *(short *)(iVar29 + 2);
  if (sVar10 == 0x1902) {
    if (*(short *)(iVar27 + 0x48) == -0x7fb7) {
      *(undefined1 *)((int)param_2 + 0x6b) = 5;
    }
    else if (*(short *)(iVar27 + 0x48) == 0x1906) {
      *(undefined1 *)((int)param_2 + 0x6b) = 0;
    }
    else {
      *(undefined1 *)((int)param_2 + 0x6b) = 1;
    }
    *(undefined2 *)(param_2 + 0x25) = *(undefined2 *)(iVar27 + 0x48);
    *(undefined2 *)((int)param_2 + 0x96) = *(undefined2 *)(iVar27 + 0x42);
    uVar11 = *(undefined2 *)(iVar27 + 0x40);
    *(undefined2 *)(param_2 + 0x26) = uVar11;
    param_2[0x23] = *(int *)(iVar27 + 0x44);
    sVar10 = *(short *)(iVar27 + 0x42);
    *(char *)((int)param_2 + 0x69) = (char)uVar11;
    fVar12 = FLOAT_001aa0d4;
    iVar29 = param_2[0xc];
    *(bool *)((int)param_2 + 0x6a) = sVar10 == -0x77b2;
    *(bool *)(param_2 + 0x1a) = *(float *)(iVar27 + 0x44) != fVar12;
  }
  else if (sVar10 == -0x7fb7) {
    *(undefined1 *)((int)param_2 + 0x6b) = 5;
  }
  else {
    *(char *)((int)param_2 + 0x6b) = (char)sVar10 + -6;
  }
  *(undefined1 *)(param_2 + 0x29) = 0;
  dVar32 = DOUBLE_001aa1e8;
  fVar12 = FLOAT_001aa10c;
  *(char *)((int)param_2 + 0xa5) = *(char *)(iVar29 + 0x5f) - *(char *)(iVar29 + 0x5e);
  param_2[0x12] = (uint)*(byte *)(iVar29 + 0x5f) << 0x10 | (uint)*(byte *)(iVar29 + 0x5e);
  fVar12 = *(float *)(iVar29 + 0x30) + fVar12;
  dVar33 = (double)fVar12;
  if (dVar32 <= dVar33) {
    iVar27 = (int)(dVar33 - dVar32) + -0x80000000;
  }
  else {
    iVar27 = (int)fVar12;
  }
  fVar12 = *(float *)(iVar29 + 0x34) + FLOAT_001aa10c;
  dVar32 = (double)fVar12;
  if (DOUBLE_001aa1e8 <= dVar32) {
    uVar15 = (int)(dVar32 - DOUBLE_001aa1e8) + 0x80000000;
  }
  else {
    uVar15 = (uint)fVar12;
  }
  param_2[0x13] = iVar27 << 0x10 | uVar15;
  ((void (*)())FUN_0002d2b0)((double)*(float *)(iVar29 + 0x1c),(double)*(float *)(iVar29 + 0x20),
               (double)*(float *)(iVar29 + 0x24),(double)*(float *)(iVar29 + 0x28),piVar31);
  uVar14 = (uint)*(byte *)((int)param_2 + 0xa5);
  uVar15 = (uint)(*(float *)(iVar29 + 0x34) + FLOAT_001aa10c);
  uVar17 = (uint)(*(float *)(iVar29 + 0x30) + FLOAT_001aa10c);
  if ((int)uVar14 < (int)uVar15) {
    uVar15 = uVar14;
  }
  if ((int)uVar14 < (int)uVar17) {
    uVar17 = uVar14;
  }
  uVar16 = uVar14 + 1;
  if ((uint)*(byte *)((int)param_2 + 0x6e) < uVar14 + 1) {
    uVar16 = (uint)*(byte *)((int)param_2 + 0x6e);
  }
  uVar15 = (uVar15 - uVar17) + 1;
  if ((int)uVar16 <= (int)uVar15) {
    uVar15 = uVar16;
  }
  iVar27 = 1;
  if (0 < (int)uVar15) {
    iVar27 = (int)(char)uVar15;
  }
  param_2[0x16] = (iVar27 + -1) * 0x4000000 & 0x3c000000U | param_2[0x16] & 0xc3ffffffU;
  *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) & 0x7f;
  return;
}

/* FUN_0002ebc0 @ 0x2ebc0 (596 bytes) */
int FUN_0002ebc0(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  if (*(int *)(param_1 + 0x2a90) != 0) {
    iVar5 = *(int *)(param_2 * 4 + param_1 + 0x18c);
    sVar4 = *(short *)(iVar5 + 0xa0);
    if ((((*(short *)(*(int *)(iVar5 + 0x30) + 0x18) != 0x2600) &&
         (sVar3 = *(short *)(*(int *)(iVar5 + 0x30) + 0x16), sVar3 != 0x2600)) && (sVar3 != 0x2702))
       && (sVar3 != 0x2700)) {
      *(uint *)(iVar5 + 0x50) =
           (*(uint *)(&DAT_001aa510 + *(int *)(param_1 + 0x2a90) * 4) & 7) << 0x15 |
           *(uint *)(iVar5 + 0x50) & 0xff1fffff;
      if (3 < *(uint *)(param_1 + 0x2a8c)) {
        if (sVar4 == 0x2703) {
          sVar4 = 0x2701;
        }
        else if (sVar4 == 0x2702) {
          sVar4 = 0x2700;
        }
      }
      cVar2 = *(char *)(iVar5 + 0x72);
      ((int (*)())FUN_0002d030)(iVar5 + 0x3c,sVar4);
      ((int (*)())FUN_0002d210)(iVar5 + 0x3c,*(undefined2 *)(iVar5 + 0xa2));
      if (cVar2 != *(char *)(iVar5 + 0x72)) {
        bVar1 = *(char *)(iVar5 + 0x72) == '\0';
        uVar6 = (uint)*(ushort *)(iVar5 + 0x9a);
        if (bVar1) {
          uVar6 = (uVar6 * 0x29 >> 0x10 & 1 | uVar6 * 0x97 >> 9 & 2 | uVar6 * 0x113 >> 7 & 4) ^ 2 |
                  *(uint *)(iVar5 + 0x50) & 0xfffffff8;
          *(uint *)(iVar5 + 0x50) = uVar6;
        }
        else {
          uVar6 = (uVar6 * 0x29 >> 0x10 & 1 | uVar6 * 0x73 >> 5 & 2 | uVar6 * 7 >> 3 & 4) ^ 2 |
                  *(uint *)(iVar5 + 0x50) & 0xfffffff8;
          *(uint *)(iVar5 + 0x50) = uVar6;
        }
        uVar7 = (uint)*(ushort *)(iVar5 + 0x9c);
        if (*(char *)(iVar5 + 0x6d) == '\x01') {
          uVar6 = uVar6 & 0xffffffc7;
          *(uint *)(iVar5 + 0x50) = uVar6;
        }
        else if (bVar1) {
          uVar6 = ((uVar7 * 0x29 >> 0x10 & 1 | uVar7 * 0x97 >> 9 & 2 | uVar7 * 0x113 >> 7 & 4) ^ 2)
                  << 3 | uVar6 & 0xffffffc7;
          *(uint *)(iVar5 + 0x50) = uVar6;
        }
        else {
          uVar6 = ((uVar7 * 0x29 >> 0x10 & 1 | uVar7 * 0x73 >> 5 & 2 | uVar7 * 7 >> 3 & 4) ^ 2) << 3
                  | uVar6 & 0xffffffc7;
          *(uint *)(iVar5 + 0x50) = uVar6;
        }
        uVar7 = (uint)*(ushort *)(iVar5 + 0x9e);
        if (*(char *)(iVar5 + 0x6d) == '\x03') {
          if (bVar1) {
            *(uint *)(iVar5 + 0x50) =
                 ((uVar7 * 0x29 >> 0x10 & 1 | uVar7 * 0x97 >> 9 & 2 | uVar7 * 0x113 >> 7 & 4) ^ 2)
                 << 6 | uVar6 & 0xfffffe3f;
          }
          else {
            *(uint *)(iVar5 + 0x50) =
                 ((uVar7 * 0x29 >> 0x10 & 1 | uVar7 * 0x73 >> 5 & 2 | uVar7 * 7 >> 3 & 4) ^ 2) << 6
                 | uVar6 & 0xfffffe3f;
          }
        }
        else {
          *(uint *)(iVar5 + 0x50) = uVar6 & 0xfffffe3f;
        }
      }
    }
  }
  return;
}

/* FUN_0002ee30 @ 0x2ee30 (1476 bytes) */
int FUN_0002ee30(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  float fVar1;
  float fVar2;
  float fVar3;
  short sVar4;
  undefined2 uVar5;
  uint uVar6;
  int iVar7;
  short sVar8;
  char cVar9;
  char cVar10;
  int iVar11;
  int iVar12;
  double dVar13;
  
  iVar12 = param_2 + 0x3c;
  iVar11 = *(int *)(param_2 + 0x30);
  fVar1 = *(float *)(iVar11 + 0x30) + FLOAT_001aa10c;
  dVar13 = (double)fVar1;
  if (DOUBLE_001aa1e8 <= dVar13) {
    iVar7 = (int)(dVar13 - DOUBLE_001aa1e8) + -0x80000000;
  }
  else {
    iVar7 = (int)fVar1;
  }
  fVar1 = *(float *)(iVar11 + 0x34) + FLOAT_001aa10c;
  dVar13 = (double)fVar1;
  if (DOUBLE_001aa1e8 <= dVar13) {
    uVar6 = (int)(dVar13 - DOUBLE_001aa1e8) + 0x80000000;
  }
  else {
    uVar6 = (uint)fVar1;
  }
  if ((((uint)*(byte *)(iVar11 + 0x5f) << 0x10 | (uint)*(byte *)(iVar11 + 0x5e)) !=
       *(uint *)(param_2 + 0x48)) || ((iVar7 << 0x10 | uVar6) != *(uint *)(param_2 + 0x4c))) {
    ((int (*)())FUN_0002ddf0)(param_1,param_2);
    return;
  }
  cVar10 = *(char *)(param_2 + 0x72);
  if (*(float *)(param_2 + 0x90) != *(float *)(iVar11 + 0x2c)) {
    *(float *)(param_2 + 0x90) = *(float *)(iVar11 + 0x2c);
    dVar13 = (double)*(float *)(iVar11 + 0x2c);
    if (DOUBLE_001aa1e8 <= dVar13) {
      iVar7 = (int)(dVar13 - DOUBLE_001aa1e8) + -0x80000000;
    }
    else {
      iVar7 = (int)*(float *)(iVar11 + 0x2c);
    }
    uVar6 = *(uint *)(&DAT_001aa510 + iVar7 * 4);
    if ((*(uint *)(param_2 + 0x50) >> 0x15 & 7) != uVar6) {
      *(undefined2 *)(param_2 + 0xa2) = 0xffff;
      *(undefined2 *)(param_2 + 0xa0) = 0xffff;
      *(uint *)(param_2 + 0x50) = (uVar6 & 7) << 0x15 | *(uint *)(param_2 + 0x50) & 0xff1fffff;
    }
  }
  sVar4 = *(short *)(iVar11 + 0x16);
  if (*(short *)(param_2 + 0xa0) == sVar4) {
    sVar8 = *(short *)(iVar11 + 0x18);
    if (*(short *)(param_2 + 0xa2) != sVar8) {
      if (*(char *)(param_2 + 0x70) != *(char *)(param_2 + 0x71)) goto LAB_0002f040;
      goto LAB_0002f088;
    }
    cVar9 = *(char *)(param_2 + 0x71);
    if (cVar9 != *(char *)(param_2 + 0x70)) goto LAB_0002f040;
  }
  else {
LAB_0002f040:
    *(short *)(param_2 + 0xa0) = sVar4;
    ((int (*)())FUN_0002d030)(iVar12,sVar4);
    *(byte *)(param_2 + 0x3d) = (byte)(-(uint)*(ushort *)(*(int *)(param_2 + 0x30) + 0x5c) >> 0x1f);
    sVar8 = *(short *)(iVar11 + 0x18);
    if ((*(short *)(param_2 + 0xa2) != sVar8) ||
       (cVar9 = *(char *)(param_2 + 0x71), cVar9 != *(char *)(param_2 + 0x70))) {
LAB_0002f088:
      *(short *)(param_2 + 0xa2) = sVar8;
      ((int (*)())FUN_0002d210)(iVar12);
      cVar9 = *(char *)(param_2 + 0x71);
    }
    if (cVar10 != *(char *)(param_2 + 0x72)) {
      *(undefined2 *)(param_2 + 0x9e) = 0xffff;
      *(undefined2 *)(param_2 + 0x9a) = 0xffff;
      *(undefined2 *)(param_2 + 0x9c) = 0xffff;
      cVar10 = *(char *)(param_2 + 0x72);
    }
  }
  *(char *)(param_2 + 0x70) = cVar9;
  uVar6 = (uint)*(ushort *)(iVar11 + 0x10);
  if (*(ushort *)(param_2 + 0x9a) != uVar6) {
    *(ushort *)(param_2 + 0x9a) = *(ushort *)(iVar11 + 0x10);
    if (cVar10 == '\0') {
      *(uint *)(param_2 + 0x50) =
           (uVar6 * 0x29 >> 0x10 & 1 | uVar6 * 0x97 >> 9 & 2 | uVar6 * 0x113 >> 7 & 4) ^ 2 |
           *(uint *)(param_2 + 0x50) & 0xfffffff8;
    }
    else {
      *(uint *)(param_2 + 0x50) =
           (uVar6 * 0x29 >> 0x10 & 1 | uVar6 * 0x73 >> 5 & 2 | uVar6 * 7 >> 3 & 4) ^ 2 |
           *(uint *)(param_2 + 0x50) & 0xfffffff8;
    }
  }
  uVar6 = (uint)*(ushort *)(iVar11 + 0x12);
  if (*(ushort *)(param_2 + 0x9c) != uVar6) {
    *(ushort *)(param_2 + 0x9c) = *(ushort *)(iVar11 + 0x12);
    if (*(char *)(param_2 + 0x6d) == '\x01') {
      *(uint *)(param_2 + 0x50) = *(uint *)(param_2 + 0x50) & 0xffffffc7;
    }
    else if (cVar10 == '\0') {
      *(uint *)(param_2 + 0x50) =
           ((uVar6 * 0x29 >> 0x10 & 1 | uVar6 * 0x97 >> 9 & 2 | uVar6 * 0x113 >> 7 & 4) ^ 2) << 3 |
           *(uint *)(param_2 + 0x50) & 0xffffffc7;
    }
    else {
      *(uint *)(param_2 + 0x50) =
           ((uVar6 * 0x29 >> 0x10 & 1 | uVar6 * 0x73 >> 5 & 2 | uVar6 * 7 >> 3 & 4) ^ 2) << 3 |
           *(uint *)(param_2 + 0x50) & 0xffffffc7;
    }
  }
  uVar6 = (uint)*(ushort *)(iVar11 + 0x14);
  if (*(ushort *)(param_2 + 0x9e) != uVar6) {
    *(ushort *)(param_2 + 0x9e) = *(ushort *)(iVar11 + 0x14);
    if (*(char *)(param_2 + 0x6d) == '\x03') {
      if (cVar10 == '\0') {
        *(uint *)(param_2 + 0x50) =
             ((uVar6 * 0x29 >> 0x10 & 1 | uVar6 * 0x97 >> 9 & 2 | uVar6 * 0x113 >> 7 & 4) ^ 2) << 6
             | *(uint *)(param_2 + 0x50) & 0xfffffe3f;
      }
      else {
        *(uint *)(param_2 + 0x50) =
             ((uVar6 * 0x29 >> 0x10 & 1 | uVar6 * 0x73 >> 5 & 2 | uVar6 * 7 >> 3 & 4) ^ 2) << 6 |
             *(uint *)(param_2 + 0x50) & 0xfffffe3f;
      }
    }
    else {
      *(uint *)(param_2 + 0x50) = *(uint *)(param_2 + 0x50) & 0xfffffe3f;
    }
  }
  sVar4 = *(short *)(*(int *)(param_2 + 0x30) + 2);
  if (sVar4 == 0x1902) {
    if (*(short *)(iVar11 + 0x48) == -0x7fb7) {
      *(undefined1 *)(param_2 + 0x6b) = 5;
    }
    else if (*(short *)(iVar11 + 0x48) == 0x1906) {
      *(undefined1 *)(param_2 + 0x6b) = 0;
    }
    else {
      *(undefined1 *)(param_2 + 0x6b) = 1;
    }
    *(undefined2 *)(param_2 + 0x94) = *(undefined2 *)(iVar11 + 0x48);
    *(undefined2 *)(param_2 + 0x96) = *(undefined2 *)(iVar11 + 0x42);
    uVar5 = *(undefined2 *)(iVar11 + 0x40);
    *(undefined2 *)(param_2 + 0x98) = uVar5;
    *(undefined4 *)(param_2 + 0x8c) = *(undefined4 *)(iVar11 + 0x44);
    sVar4 = *(short *)(iVar11 + 0x42);
    *(char *)(param_2 + 0x69) = (char)uVar5;
    fVar1 = FLOAT_001aa0d4;
    *(bool *)(param_2 + 0x6a) = sVar4 == -0x77b2;
    *(bool *)(param_2 + 0x68) = *(float *)(iVar11 + 0x44) != fVar1;
  }
  else if (sVar4 == -0x7fb7) {
    *(undefined1 *)(param_2 + 0x6b) = 5;
  }
  else {
    *(char *)(param_2 + 0x6b) = (char)sVar4 + -6;
  }
  if (*(float *)(param_2 + 0xa8) == *(float *)(iVar11 + 0x1c)) {
    fVar1 = *(float *)(iVar11 + 0x20);
    if (*(float *)(param_2 + 0xac) == fVar1) {
      fVar2 = *(float *)(iVar11 + 0x24);
      if (*(float *)(param_2 + 0xb0) == fVar2) {
        fVar3 = *(float *)(iVar11 + 0x28);
        if (*(float *)(param_2 + 0xb4) == fVar3) goto LAB_0002f3e8;
      }
      else {
        fVar3 = *(float *)(iVar11 + 0x28);
      }
    }
    else {
      fVar2 = *(float *)(iVar11 + 0x24);
      fVar3 = *(float *)(iVar11 + 0x28);
    }
  }
  else {
    fVar1 = *(float *)(iVar11 + 0x20);
    fVar2 = *(float *)(iVar11 + 0x24);
    fVar3 = *(float *)(iVar11 + 0x28);
  }
  *(float *)(param_2 + 0xa8) = *(float *)(iVar11 + 0x1c);
  *(float *)(param_2 + 0xac) = fVar1;
  *(float *)(param_2 + 0xb0) = fVar2;
  *(float *)(param_2 + 0xb4) = fVar3;
  ((void (*)())FUN_0002d2b0)((double)*(float *)(iVar11 + 0x1c),(double)*(float *)(iVar11 + 0x20),
               (double)*(float *)(iVar11 + 0x24),(double)*(float *)(iVar11 + 0x28),iVar12);
LAB_0002f3e8:
  *(byte *)(param_2 + 0x39) = *(byte *)(param_2 + 0x39) & 0x7f;
  return;
}

/* FUN_0002f410 @ 0x2f410 (148 bytes) */
int FUN_0002f410(param_1)
  uint param_1;
{
  switch(param_1 & 0xf) {
  case 3:
    return 7;
  case 4:
    return 0xb;
  default:
    return 0;
  case 6:
    return 0x27;
  case 7:
    return 0x2b;
  case 8:
    return 0x2c;
  case 9:
    return 0x2a;
  case 10:
    return 8;
  case 0xb:
    return 0x18;
  case 0xc:
    return 0x1e;
  case 0xd:
    return 0x12;
  }
}

/* FUN_0002f4d0 @ 0x2f4d0 (708 bytes) */
int FUN_0002f4d0(param_1, param_2, param_3)
  uint param_1;
  undefined *param_2;
  int param_3;
{
  bool bVar1;
  
  if (param_1 == 0x1909) {
    if (param_3 == 1) {
LAB_0002f7a0:
      return param_2 == ((unsigned char *)0x00001401);
    }
    if (param_3 == 0x13) goto LAB_0002f790;
    if (param_3 == 0x1f) {
LAB_0002f6c0:
      if (param_2 == ((unsigned char *)0x0000140b)) {
        return true;
      }
      return false;
    }
    if (param_3 != 0x19) {
      return false;
    }
  }
  else if (param_1 < 0x190a) {
    if (param_1 == 0x1907) {
      if (param_3 == 5) {
        if (param_2 != (undefined *)0x8363) {
          return false;
        }
        return true;
      }
      if (param_3 == 0x28) {
        if (param_2 == (undefined *)0x8032) {
          return true;
        }
        return false;
      }
      return false;
    }
    if (param_1 < 0x1908) {
      if (param_1 != 0x1906) {
        return false;
      }
      if (param_3 == 2) goto LAB_0002f7a0;
      if (param_3 == 0x14) goto LAB_0002f790;
      if (param_3 == 0x20) goto LAB_0002f6c0;
      if (param_3 != 0x1a) {
        return false;
      }
    }
    else {
      if (param_3 == 0x12) {
LAB_0002f790:
        return param_2 == ((unsigned char *)0x00001406);
      }
      if (param_3 == 0x1e) {
        return param_2 == ((unsigned char *)0x0000140b);
      }
      if (param_3 == 10) {
        return param_2 == (undefined *)0x8367;
      }
      if (param_3 == 9) {
LAB_0002f5d0:
        if (param_2 == (undefined *)0x8035) {
          return true;
        }
        if (param_2 == ((unsigned char *)0x00001401)) {
          return true;
        }
        return false;
      }
      if (param_3 == 0x23) {
LAB_0002f5fc:
        if (param_2 == (undefined *)0x8368) {
          return true;
        }
        return false;
      }
      if (param_3 != 0x18) {
        return false;
      }
    }
  }
  else {
    if (param_1 == 0x80e1) {
      if (param_3 == 7) {
        bVar1 = param_2 == (undefined *)0x8366;
      }
      else if (param_3 == 6) {
        bVar1 = param_2 == (undefined *)0x8365;
      }
      else if (param_3 == 0xb) {
        bVar1 = param_2 == (undefined *)0x8367;
      }
      else {
        if (param_3 == 8) goto LAB_0002f5d0;
        bVar1 = false;
        if (param_3 == 0x24) goto LAB_0002f5fc;
        if (param_3 == 0x11) {
          if (param_2 == ((unsigned char *)0x00001406)) {
            return true;
          }
          return bVar1;
        }
        if (param_3 == 0x1d) {
          if (param_2 == ((unsigned char *)0x0000140b)) {
            return true;
          }
          return false;
        }
      }
      if (param_3 != 0x17) {
        return bVar1;
      }
      if (param_2 == ((unsigned char *)0x00001403)) {
        return true;
      }
      return bVar1;
    }
    if (param_1 == 0x85b9) {
      if (param_3 == 0x27) {
        if (param_2 == (undefined *)0x85ba) {
          return true;
        }
        return false;
      }
      if (param_3 != 0x26) {
        return false;
      }
      if (param_2 == (undefined *)0x85bb) {
        return true;
      }
      return false;
    }
    if (param_1 != 0x190a) {
      return false;
    }
    if (param_3 == 4) goto LAB_0002f7a0;
    if (param_3 == 0x16) {
      return param_2 == ((unsigned char *)0x00001406);
    }
    if (param_3 == 0x22) goto LAB_0002f6c0;
    if (param_3 != 0x1c) {
      return false;
    }
  }
  if (param_2 == ((unsigned char *)0x00001403)) {
    return true;
  }
  return false;
}

/* FUN_0002fac0 @ 0x2fac0 (2252 bytes) */
int FUN_0002fac0(param_1, param_2)
  int param_1;
  int param_2;
{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  char cVar6;
  char cVar7;
  int iVar8;
  undefined1 uVar9;
  char cVar10;
  char cVar11;
  char cVar12;
  ushort *puVar13;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30 [9];
  
  puVar13 = *(ushort **)(param_2 + 0x30);
  uVar1 = *puVar13;
  if ((uVar1 & 0x200) != 0) {
    return;
  }
  if ((uVar1 & 0x400) != 0) {
    local_38 = *(undefined4 *)(puVar13 + 4);
    *(undefined1 *)(param_2 + 0x38) = 0;
    local_34 = 3;
    iVar8 = _io_connect_method_scalarI_scalarO
                      (*(undefined4 *)(param_1 + 4),6,&local_38,1,local_30,&local_34);
    if (iVar8 != 0) {
      return;
    }
    uVar1 = puVar13[6];
    if (uVar1 == 0x409) {
      if ((local_30[0] & 0x300) < 0x100) {
        return;
      }
    }
    else if (uVar1 == 0x40a) {
      if ((local_30[0] & 0x300) < 0x200) {
        return;
      }
    }
    else if ((ushort)(uVar1 - 0x40b) < 2) {
      return;
    }
    uVar9 = ((int (*)())FUN_0002f410)(local_30[0]);
    *(undefined1 *)(param_2 + 0x38) = uVar9;
    return;
  }
  uVar2 = puVar13[0x2c];
  uVar3 = puVar13[0x2a];
  uVar4 = puVar13[0x2d];
  uVar5 = *(uint *)(param_1 + 0x154) & 0xf;
  if (uVar2 != 0x1900) {
    if (uVar2 != 0x85b9) {
      if (uVar4 == 0x8362) {
LAB_0002fcd4:
        cVar6 = '(';
        cVar11 = '(';
        cVar10 = '(';
      }
      else if (uVar4 < 0x8363) {
        if (uVar4 == 0x8034) {
LAB_0002fcf4:
          cVar6 = '\0';
          cVar11 = '\a';
          cVar10 = '\a';
        }
        else if (uVar4 < 0x8035) {
          if (uVar4 == 0x8032) goto LAB_0002fcd4;
          if (uVar4 == 0x8033) goto LAB_0002fcc4;
LAB_0002fc40:
          cVar6 = '\0';
          cVar11 = '\0';
          cVar10 = '\0';
        }
        else if (uVar4 == 0x8035) {
          if (uVar2 == 0x80e1) {
            cVar6 = '\0';
            cVar11 = '\0';
            cVar10 = '\b';
          }
          else {
            cVar6 = '\0';
            cVar11 = '\0';
            cVar10 = '\t';
          }
        }
        else {
          if (uVar4 != 0x8036) goto LAB_0002fc40;
LAB_0002fd64:
          if (uVar2 == 0x80e1) {
            cVar6 = '\0';
            cVar11 = '\0';
            cVar10 = '$';
          }
          else {
            cVar6 = '\0';
            cVar11 = '\0';
            cVar10 = '#';
          }
        }
      }
      else if (uVar4 == 0x8365) {
LAB_0002fcc4:
        cVar6 = '\0';
        cVar11 = '\x06';
        cVar10 = '\x06';
      }
      else if (uVar4 < 0x8365) {
        cVar6 = '\0';
        cVar11 = '\x05';
        cVar10 = '\x05';
      }
      else {
        if (uVar4 != 0x8367) {
          if (0x8366 < uVar4) {
            if (uVar4 == 0x8368) goto LAB_0002fd64;
            goto LAB_0002fc40;
          }
          goto LAB_0002fcf4;
        }
        if (uVar2 == 0x80e1) {
          cVar6 = '\0';
          cVar11 = '\0';
          cVar10 = '\v';
        }
        else {
          cVar6 = '\0';
          cVar11 = '\0';
          cVar10 = '\n';
        }
      }
      if (0x8056 < uVar3) {
        if (uVar3 == 0x84ec) {
          cVar11 = '\0';
          cVar7 = '\f';
          cVar12 = '\x03';
        }
        else if (uVar3 < 0x84ed) {
          if (uVar3 < 0x81a8) {
            if (uVar3 < 0x81a6) {
              if (uVar3 == 0x8059) {
                if (uVar2 == 0x80e1) {
                  cVar11 = '\0';
                  cVar7 = '\0';
                  cVar12 = '$';
                }
                else {
                  cVar11 = '\0';
                  cVar7 = '\0';
                  cVar12 = '#';
                }
              }
              else if (uVar3 < 0x805a) {
                if (uVar3 != 0x8057) {
                  if (uVar3 == 0x8058) goto LAB_0002fec0;
                  goto LAB_0002fde8;
                }
                cVar7 = '\0';
                cVar12 = '\a';
              }
              else {
                if (uVar3 < 0x805c) goto LAB_00030378;
                if (uVar3 != 0x81a5) goto LAB_0002fde8;
LAB_0003034c:
                cVar7 = '\0';
                cVar12 = '\x10';
                cVar11 = '\0';
              }
            }
            else {
LAB_0003009c:
              cVar11 = '\0';
              cVar7 = '\0';
              cVar12 = ')';
            }
          }
          else if (uVar3 == 0x83f3) {
            cVar7 = '\x0e';
            cVar12 = '\x06';
          }
          else if (uVar3 < 0x83f4) {
            if (uVar3 == 0x83f1) {
              cVar7 = '\f';
              cVar12 = '\x06';
            }
            else {
              if (uVar3 < 0x83f2) {
                if (uVar3 == 0x83f0) goto LAB_000301a0;
                goto LAB_0002fde8;
              }
LAB_0003017c:
              cVar7 = '\r';
              cVar12 = '\x06';
            }
          }
          else if (uVar3 == 0x84ea) {
            cVar11 = '\0';
            cVar7 = '\f';
            cVar12 = '\x01';
          }
          else if (uVar3 < 0x84eb) {
            if (uVar3 != 0x84e9) goto LAB_0002fde8;
            if (uVar2 == 0x1908) {
LAB_00030298:
              if ((uVar4 == 0x8034) || (uVar4 == 0x8366)) goto LAB_00030260;
            }
            else if (uVar2 < 0x1909) {
              if (uVar2 != 0x1906) {
LAB_00030260:
                cVar11 = '\0';
                cVar7 = '\f';
                cVar12 = '\x02';
                goto LAB_00030270;
              }
            }
            else if (uVar2 != 0x190a) {
              if (uVar2 == 0x80e1) goto LAB_00030298;
              goto LAB_00030260;
            }
LAB_000302b8:
            cVar7 = '\0';
            cVar12 = '\x02';
            cVar11 = '\0';
          }
          else {
            cVar7 = '\r';
            cVar12 = '\x04';
          }
        }
        else if (uVar3 == 0x8819) {
          cVar11 = '\0';
          cVar7 = '\0';
          cVar12 = '\x16';
        }
        else if (uVar3 < 0x881a) {
          if (uVar3 < 0x8816) {
            if (uVar3 < 0x8814) {
              if (uVar3 != 0x84ed) {
                if (uVar3 == 0x84ee) goto LAB_0003017c;
                goto LAB_0002fde8;
              }
LAB_000301a0:
              cVar7 = '\f';
              cVar12 = '\x05';
            }
            else if (uVar2 == 0x80e1) {
              cVar11 = '\0';
              cVar7 = '\0';
              cVar12 = '\x11';
            }
            else {
              cVar11 = '\0';
              cVar7 = '\0';
              cVar12 = '\x12';
            }
          }
          else if (uVar3 == 0x8817) {
            cVar11 = '\0';
            cVar7 = '\0';
            cVar12 = '\x15';
          }
          else if (uVar3 < 0x8818) {
            cVar11 = '\0';
            cVar7 = '\0';
            cVar12 = '\x14';
          }
          else {
            cVar11 = '\0';
            cVar7 = '\0';
            cVar12 = '\x13';
          }
        }
        else if (uVar3 == 0x881d) {
          cVar11 = '\0';
          cVar7 = '\0';
          cVar12 = '!';
        }
        else if (uVar3 < 0x881e) {
          if (uVar3 < 0x881c) {
            cVar11 = '\0';
            cVar7 = '\0';
            cVar12 = '\x1e';
          }
          else {
            cVar11 = '\0';
            cVar7 = '\0';
            cVar12 = ' ';
          }
        }
        else if (uVar3 == 0x881f) {
          cVar11 = '\0';
          cVar7 = '\0';
          cVar12 = '\"';
        }
        else if (uVar3 < 0x881f) {
          cVar11 = '\0';
          cVar7 = '\0';
          cVar12 = '\x1f';
        }
        else {
          if (uVar3 != 0x8837) {
            if (uVar3 == 0x88f0) goto LAB_0003009c;
            goto LAB_0002fde8;
          }
          cVar11 = '\0';
          cVar7 = '\x0f';
          cVar12 = '\x04';
        }
        goto LAB_00030270;
      }
      if (uVar3 < 0x8055) {
        if (uVar3 < 0x8041) {
          if (uVar3 < 0x803f) {
            if (uVar3 == 0x1908) {
LAB_000302e8:
              if (uVar2 == 0x1908) {
LAB_0003031c:
                if (uVar5 == 3) goto LAB_00030360;
              }
              else {
                if (uVar2 < 0x1909) {
                  if (uVar2 == 0x1906) goto LAB_0003031c;
                }
                else if ((uVar2 == 0x190a) || (uVar2 == 0x80e1)) goto LAB_0003031c;
LAB_00030340:
                if (uVar5 == 3) goto LAB_0003036c;
              }
LAB_0002fec0:
              cVar7 = '\0';
              cVar12 = '\t';
              cVar11 = cVar10;
            }
            else {
              if (uVar3 < 0x1909) {
                if (uVar3 == 4) goto LAB_000302e8;
                if (4 < uVar3) {
                  if (uVar3 == 0x1906) goto LAB_000302b8;
                  if (0x1906 < uVar3) goto LAB_00030328;
                  if (uVar3 == 0x1902) goto LAB_0003034c;
LAB_0002fde8:
                  cVar7 = '\0';
                  cVar12 = '\0';
                  cVar11 = '\0';
                  goto LAB_00030270;
                }
                if (uVar3 == 2) goto LAB_000301ec;
                if (uVar3 < 3) {
                  if (uVar3 == 1) goto LAB_00030218;
                  goto LAB_0002fde8;
                }
LAB_00030328:
                if (uVar2 == 0x1906) {
                  cVar7 = '\0';
                  cVar12 = '(';
                  cVar11 = '\0';
                  goto LAB_00030270;
                }
                goto LAB_00030340;
              }
              if (uVar3 < 0x803d) {
                if (0x803a < uVar3) goto LAB_000302b8;
                if (uVar3 == 0x190a) {
LAB_000301ec:
                  cVar7 = '\0';
                  cVar12 = '\x04';
                  cVar11 = '\0';
                }
                else {
                  if (uVar3 < 0x190a) goto LAB_00030218;
                  if (uVar3 != 0x2a10) goto LAB_0002fde8;
                  cVar7 = '\0';
                  cVar12 = '(';
                  cVar11 = cVar6;
                }
              }
              else {
                cVar7 = '\0';
                cVar12 = '\x1a';
                cVar11 = '\0';
              }
            }
          }
          else {
LAB_00030218:
            cVar7 = '\0';
            cVar12 = '\x01';
            cVar11 = '\0';
          }
        }
        else if (uVar3 < 0x804c) {
          if (uVar3 < 0x8049) {
            if (uVar3 < 0x8047) {
              if (0x8042 < uVar3) goto LAB_000301ec;
              cVar7 = '\0';
              cVar12 = '\x19';
              cVar11 = '\0';
            }
            else {
              cVar7 = '\0';
              cVar12 = '\x1c';
              cVar11 = '\0';
            }
          }
          else {
            cVar7 = '\0';
            cVar12 = '\x03';
            cVar11 = '\0';
          }
        }
        else if (uVar3 < 0x8051) {
          if (uVar3 < 0x804f) {
            if (0x804d < uVar3) goto LAB_0002fde8;
            cVar7 = '\0';
            cVar12 = '\x1b';
            cVar11 = '\0';
          }
          else {
LAB_0003036c:
            cVar7 = '\0';
            cVar12 = '\x05';
          }
        }
        else if (uVar3 == 0x8052) {
          cVar7 = '\0';
          cVar12 = '#';
          cVar11 = cVar10;
        }
        else {
          if (uVar3 < 0x8053) goto LAB_0002fec0;
LAB_00030378:
          cVar7 = '\0';
          cVar12 = '\x18';
          cVar11 = '\0';
        }
      }
      else {
LAB_00030360:
        cVar7 = '\0';
        cVar12 = '\x06';
      }
LAB_00030270:
      if ((((uVar1 & 0xf) == 2) || (cVar7 == '\0')) && (cVar7 = cVar11, cVar11 == '\0')) {
        cVar7 = cVar12;
      }
      goto LAB_000303b4;
    }
    cVar7 = '\'';
    if ((uVar4 == 0x85ba) || (cVar7 = '&', uVar4 == 0x85bb)) goto LAB_000303b4;
  }
  cVar7 = '\0';
LAB_000303b4:
  *(char *)(param_2 + 0x38) = cVar7;
  return;
}

/* FUN_000303d0 @ 0x303d0 (68 bytes) */
int FUN_000303d0(param_1, param_2, param_3, param_4)
  uint param_1;
  int param_2;
  int param_3;
  int param_4;
{
  param_4 = (param_2 + 3 >> 2) * (param_3 + 3 >> 2) * param_4;
  if (param_1 == 0xc) {
    return param_4 * 8;
  }
  if ((0xb < param_1) && (param_1 < 0x10)) {
    return param_4 * 0x10;
  }
  return 0;
}

/* FUN_00030420 @ 0x30420 (392 bytes) */
int FUN_00030420(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  void *param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  uint param_7;
{
  uint uVar1;
  uint uVar2;
  float fVar3;
  double dVar4;
  uint uVar5;
  uint uVar6;
  
  _memcpy(param_1,PTR_DAT_001e8998,0x74);
  dVar4 = DOUBLE_001aa250;
  fVar3 = FLOAT_001aa10c;
  uVar5 = *(uint *)((int)param_1 + 0xc);
  uVar2 = param_4 >> (*(uint *)(param_2 + 0x14) & 7) & 0x3ffe;
  uVar6 = (param_5 & 1) << 0x10;
  uVar1 = (param_5 & 6) << 0x10;
  *(uint *)((int)param_1 + 0xc) = uVar1 | uVar6 | uVar2 | uVar5 & 0xffe0c001;
  *(uint *)((int)param_1 + 0xc) =
       (*(uint *)(param_2 + 0x18) & 0x3c00) << 0xb | uVar1 | uVar6 | uVar2 | uVar5 & 0xfe00c001;
  uVar6 = *(uint *)(param_2 + 0x18);
  *(uint *)((int)param_1 + 0x1c) =
       (param_7 - 1 & 0x7ff) << 0xb |
       param_6 - 1 & 0x7ff | *(uint *)((int)param_1 + 0x1c) & 0x80000000 | 0x80000000;
  *(uint *)((int)param_1 + 0x14) = uVar6 >> 0x1e;
  uVar6 = *(uint *)(param_2 + 0x14);
  *(uint *)((int)param_1 + 0x30) =
       (param_7 - 1 & 0x1fff) << 0xd |
       param_6 - 1 & 0x1fff | *(uint *)((int)param_1 + 0x30) & 0xfc000000;
  *(uint *)((int)param_1 + 0x4c) = param_6 * 0x60000 | param_7 * 6;
  *(float *)((int)param_1 + 0x5c) = (float)((double)CONCAT44(0x43300000,param_7) - dVar4) * fVar3;
  *(float *)((int)param_1 + 0x58) = (float)((double)CONCAT44(0x43300000,param_6) - dVar4) * fVar3;
  *(uint *)((int)param_1 + 0x24) =
       (uint)(0x800 < param_7) * 0x10000 |
       (uint)(0x800 < param_6) * 0x8000 |
       (param_3 >> (uVar6 & 7)) - 1 & 0x3fff | *(uint *)((int)param_1 + 0x24) & 0xfff00000;
  return (int)param_1 + 0x74;
}

/* FUN_000305b0 @ 0x305b0 (492 bytes) */
int FUN_000305b0(param_1, param_2, param_3, param_4)
  undefined1 *param_1;
  byte *param_2;
  int param_3;
  int param_4;
{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  uint uVar9;
  byte *pbVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int local_58 [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  
  uVar4 = 0;
  uVar9 = 0xff;
  iVar6 = 0;
  pbVar10 = param_2;
  do {
    iVar14 = 4;
    pbVar8 = pbVar10;
    do {
      uVar3 = (uint)*pbVar8;
      pbVar8 = pbVar8 + param_3;
      if (uVar3 < uVar9) {
        uVar9 = uVar3;
      }
      if (uVar4 < uVar3) {
        uVar4 = uVar3;
      }
      iVar14 = iVar14 + -1;
    } while (iVar14 != 0);
    bVar1 = iVar6 != 3;
    pbVar10 = pbVar10 + param_4;
    iVar6 = iVar6 + 1;
  } while (bVar1);
  iVar6 = uVar4 * 0x100;
  iVar14 = uVar9 * 0x100;
  iVar12 = (int)(iVar6 + uVar9 * -0x100) / 7;
  iVar5 = iVar12 >> 1;
  if (iVar6 == iVar14) {
    if (uVar9 == 0) {
      iVar6 = 0x100;
      iVar5 = 0x7fff;
      iVar12 = 0xffff;
    }
    else {
      iVar14 = iVar14 + -0x100;
      iVar5 = 0x7fff;
      iVar12 = 0xffff;
    }
  }
  iVar13 = 0;
  uVar4 = 0x10;
  local_58[0] = DAT_001aa554;
  local_58[1] = DAT_001aa558;
  local_3c = DAT_001aa570;
  local_58[2] = DAT_001aa55c;
  local_58[3] = DAT_001aa560;
  local_48 = DAT_001aa564;
  local_44 = DAT_001aa568;
  local_40 = DAT_001aa56c;
  do {
    iVar15 = 4;
    pbVar10 = param_2;
    uVar9 = uVar4;
    do {
      bVar2 = *pbVar10;
      iVar11 = (int)uVar9 >> 3;
      uVar3 = uVar9 & 7;
      pbVar10 = pbVar10 + param_3;
      iVar7 = local_58[(int)(((uint)bVar2 * 0x100 + iVar5) - iVar14) / iVar12];
      param_1[iVar11] = (byte)(iVar7 << uVar3) | param_1[iVar11] & ~(byte)(7 << uVar3);
      if (5 < uVar3) {
        param_1[iVar11 + 1] =
             (byte)(iVar7 >> (8 - uVar3 & 0x3f)) |
             param_1[iVar11 + 1] & ~(byte)(7 >> (8 - uVar3 & 0x3f));
      }
      uVar9 = uVar9 + 3;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
    bVar1 = iVar13 != 3;
    param_2 = param_2 + param_4;
    uVar4 = uVar4 + 0xc;
    iVar13 = iVar13 + 1;
  } while (bVar1);
  *param_1 = (char)((uint)iVar6 >> 8);
  param_1[1] = (char)((uint)iVar14 >> 8);
  return;
}

/* FUN_000307a0 @ 0x307a0 (148 bytes) */
int FUN_000307a0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  int *piVar2;
  
  piVar2 = *(int **)(param_1 + 0x1dc);
  if (*(int **)(param_1 + 0x1e0) <= piVar2 + 1) {
    FUN_0001a0f0(param_1,0x1000000);
    piVar2 = *(int **)(param_1 + 0x1dc);
  }
  puVar1 = *(uint **)(param_1 + 0x1d8);
  *(int **)(param_1 + 0x1dc) = piVar2 + 1;
  *puVar1 = (int)piVar2 - (int)puVar1 >> 2 | *puVar1;
  *(int **)(param_1 + 0x1d8) = piVar2;
  *piVar2 = param_2 * 0x1000000 + 0x16000000;
  FUN_000a8320(param_1,param_2);
  return;
}

/* FUN_00030840 @ 0x30840 (124 bytes) */
int FUN_00030840(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  
  iVar1 = 0xf;
  iVar2 = param_1;
  do {
    if (*(int *)(iVar2 + 0x1c8) != 0) {
      param_2 = ((int (*)())FUN_0002cd50)(param_1,0,iVar1,param_2);
    }
    iVar1 = iVar1 + -1;
    iVar2 = iVar2 + -4;
  } while (iVar1 != 0);
  ((int (*)())FUN_0002cd50)(param_1,param_3,0,param_2);
  return;
}

/* FUN_000308c0 @ 0x308c0 (192 bytes) */
int FUN_000308c0(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar5 = 0;
  iVar4 = 0;
  iVar6 = param_1;
  do {
    iVar3 = *(int *)(iVar6 + 0x18c);
    if (iVar3 != 0) {
      iVar7 = 5;
      piVar2 = (int *)(iVar4 + *(int *)(param_1 + 0x18));
      do {
        if (iVar3 == *piVar2) {
          if (*(int *)(iVar3 + 0x34) != 0) goto LAB_0003093c;
          break;
        }
        piVar2 = piVar2 + 1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
      iVar3 = 0;
    }
LAB_0003093c:
    if ((iVar5 == 0) || (iVar3 != 0)) {
      param_2 = ((int (*)())FUN_0002cd50)(param_1,iVar3,iVar5,param_2);
    }
    bVar1 = iVar5 == 0xf;
    iVar4 = iVar4 + 0x14;
    iVar6 = iVar6 + 4;
    iVar5 = iVar5 + 1;
    if (bVar1) {
      return;
    }
  } while( true );
}

/* FUN_00030990 @ 0x30990 (40 bytes) */
int FUN_00030990(param_1)
  uint param_1;
{
  int iVar1;
  
  iVar1 = 0;
  for (; 1 < param_1; param_1 = param_1 >> 1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

/* FUN_000309c0 @ 0x309c0 (136 bytes) */
int FUN_000309c0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  *(undefined4 *)(param_3 * 4 + iVar2 + 0x18c) = param_2;
  uVar1 = (**(code **)(iVar2 + 0x2998))(param_1,0xe);
  *(undefined4 *)(iVar2 + 0x298c) = uVar1;
  uVar1 = ((int (*)())FUN_0002cd50)(iVar2,param_2,param_3,uVar1);
  *(undefined4 *)(iVar2 + 0x298c) = uVar1;
                    
                    
  (**(code **)(iVar2 + 0x299c))(param_1,uVar1);
  return;
}

/* FUN_00030a50 @ 0x30a50 (8 bytes) */
int FUN_00030a50(param_1)
  int param_1;
{
  _gldDeleteTexture(*(undefined4 *)(param_1 + 4));
  return;
}

/* FUN_00030a60 @ 0x30a60 (240 bytes) */
int FUN_00030a60(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 *param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  *param_1 = 0xc0101000;
  param_1[1] = 0x51b;
  param_1[2] = (param_2 & 0xf) << 8 | 0x42cc30f3;
  param_1[3] = 0x1056b;
  param_1[4] = 0;
  param_1[5] = param_3;
  param_1[6] = 0x10501;
  param_1[7] = 0;
  param_1[8] = param_4;
  param_1[9] = 0x5c1;
  param_1[10] = 0;
  param_1[0xb] = 0x5c0;
  param_1[0xc] = param_5;
  param_1[0xd] = 0x50d;
  param_1[0xe] = param_6;
  param_1[0xf] = 0x1050e;
  param_1[0x10] = 0;
  param_1[0x11] = param_7;
  return param_1 + 0x12;
}

/* FUN_00030b50 @ 0x30b50 (236 bytes) */
int FUN_00030b50(param_1)
  int param_1;
{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  
  iVar3 = *(int *)(param_1 + 0x30);
  bVar1 = *(byte *)(iVar3 + 1);
  bVar5 = bVar1 & 0xf;
  *(byte *)(param_1 + 0x6c) = bVar5;
  iVar3 = *(short *)(iVar3 + 0x3c) * 0x18 + iVar3;
  uVar4 = (uint)*(byte *)(iVar3 + 0xaa);
  uVar6 = (uint)*(ushort *)(iVar3 + 0xa4) + uVar4 * -2;
  if ((int)uVar6 < 1) {
    uVar6 = 1;
  }
  uVar2 = (uint)*(ushort *)(iVar3 + 0xa6) + uVar4 * -2;
  if ((int)uVar2 < 1) {
    uVar2 = 1;
  }
  uVar4 = (uint)*(ushort *)(iVar3 + 0xa8) + uVar4 * -2;
  if ((int)uVar4 < 1) {
    uVar4 = 1;
  }
  if (bVar5 == 1) {
    if ((uVar6 & uVar6 - 1) != 0) {
      return 1;
    }
    if ((uVar2 & uVar2 - 1) != 0) {
      return 1;
    }
    uVar6 = uVar4 & uVar4 - 1;
  }
  else if (((bVar1 & 0xf) == 0) || (bVar5 == 3)) {
    if ((uVar6 & uVar6 - 1) != 0) {
      return 1;
    }
    uVar6 = uVar2 & uVar2 - 1;
  }
  else {
    if (bVar5 != 4) {
      return 1;
    }
    uVar6 = uVar6 & uVar6 - 1;
  }
  if (uVar6 != 0) {
    return 1;
  }
  return 0;
}

/* FUN_00030c50 @ 0x30c50 (684 bytes) */
int FUN_00030c50(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
{
  undefined2 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  undefined4 uVar7;
  int iVar8;
  int local_58 [9];
  
  uVar7 = *(undefined4 *)(param_1 + 4);
  local_58[0] = 0;
  puVar1 = _malloc(0x910);
  if (puVar1 != (undefined2 *)0x0) {
    puVar1[0x24] = 0;
    *(undefined4 *)(puVar1 + 0x26) = 0;
    *(undefined4 *)(puVar1 + 4) = 0;
    puVar1[6] = 0x405;
    *(undefined4 *)(puVar1 + 0x22) = 0;
    puVar1[10] = 0x2901;
    puVar1[8] = 0x2901;
    puVar1[9] = 0x2901;
    *(undefined4 *)(puVar1 + 0xe) = 0;
    *(undefined4 *)(puVar1 + 0x10) = 0;
    *(undefined4 *)(puVar1 + 0x12) = 0;
    *(undefined4 *)(puVar1 + 0x14) = 0;
    *(undefined4 *)(puVar1 + 0x1c) = 0;
    puVar1[0x1e] = 0;
    puVar1[0x1f] = 0;
    puVar1[0x20] = 0;
    puVar1[0x21] = 0;
    *puVar1 = (short)param_8;
    puVar1[0xd] = 0x85bd;
    *(undefined4 *)(puVar1 + 0x16) = 0x3f800000;
    *(undefined4 *)(puVar1 + 2) = 0x3f800000;
    *(undefined4 *)(puVar1 + 0x18) = 0xc47a0000;
    *(undefined4 *)(puVar1 + 0x1a) = 0x447a0000;
    puVar1[0x2e] = 0x2600;
    puVar1[0xb] = 0x2600;
    puVar1[0xc] = 0x2600;
    puVar1[1] = param_5;
    puVar1[0x2a] = param_5;
    puVar1[0x2c] = param_5;
    puVar1[0x2d] = param_7;
    *(undefined1 *)(puVar1 + 0x2f) = 0;
    *(uint *)(puVar1 + 0x24) = *(uint *)(puVar1 + 0x24) & 0xffff7f7f;
    *(undefined1 *)((int)puVar1 + 0x5f) = 0;
    iVar2 = ((int (*)())FUN_00030990)(param_2);
    iVar3 = ((int (*)())FUN_00030990)(param_3);
    iVar4 = ((int (*)())FUN_00030990)(param_4);
    *(char *)(puVar1 + 0x30) = (char)iVar2;
    *(char *)(puVar1 + 0x31) = (char)iVar4;
    *(char *)((int)puVar1 + 0x61) = (char)iVar3;
    iVar8 = iVar3;
    if (iVar3 < iVar4) {
      iVar8 = iVar4;
    }
    iVar5 = iVar2;
    if (iVar2 < iVar8) {
      iVar5 = iVar8;
    }
    *(char *)((int)puVar1 + 0x65) = (char)iVar3;
    *(char *)(puVar1 + 0x32) = (char)iVar2;
    *(undefined1 *)(puVar1 + 0x36) = 1;
    *(undefined1 *)(puVar1 + 0x35) = 1;
    *(char *)(puVar1 + 0x33) = (char)iVar4;
    *(char *)((int)puVar1 + 0x67) = (char)iVar5;
    *(undefined1 *)((int)puVar1 + 0x6d) = 0;
    puVar1[0x3e] = 1;
    *(char *)((int)puVar1 + 99) = (char)iVar5;
    *(undefined1 *)((int)puVar1 + 0x69) = 0;
    *(undefined1 *)((int)puVar1 + 0x6b) = 0;
    puVar1[0x38] = 1;
    *(char *)(puVar1 + 0x37) = (param_8 == 3) << 1;
    *(char *)((int)puVar1 + 0x6f) = (param_8 == 1) << 1;
    iVar8 = 1 << (*(uint *)(&DAT_001d9f48 + (uint)param_6 * 0x24) & 7);
    pvVar6 = _malloc(iVar8 * param_4 * param_2 * param_3);
    if (pvVar6 != (void *)0x0) {
      *(void **)(puVar1 + 0x5a) = pvVar6;
      puVar1[0x54] = (short)param_4;
      puVar1[0x57] = (short)param_3;
      *(undefined1 *)(puVar1 + 0x55) = 0;
      puVar1[0x58] = param_5;
      puVar1[0x56] = (short)param_2 * (short)iVar8;
      puVar1[0x59] = param_7;
      puVar1[0x52] = (short)param_2;
      puVar1[0x53] = (short)param_3;
      iVar8 = _gldCreateTexture(uVar7,local_58,puVar1);
      if ((iVar8 == 0) && (local_58[0] != 0)) {
        *(undefined1 *)(local_58[0] + 0x39) = 0xff;
        *(byte *)(local_58[0] + 0x38) = param_6;
        *(ushort *)(local_58[0] + 0x24) = *(ushort *)(local_58[0] + 0x24) | 1;
        return local_58[0];
      }
    }
    _free(puVar1);
  }
  return 0;
}

/* FUN_00030f00 @ 0x30f00 (88 bytes) */
int FUN_00030f00(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_2 + 0x38);
  if (uVar1 == 0xc) {
    return -2;
  }
  if ((0xb < uVar1) && (uVar1 < 0x10)) {
    return 1;
  }
  return 1 << (*(uint *)(&DAT_001d9f48 + uVar1 * 0x24) & 7);
}

/* FUN_00030f60 @ 0x30f60 (492 bytes) */
int FUN_00030f60(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
  uint *param_5;
{
  ushort uVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar3 = (uint)*(byte *)(param_2 + 0x38);
  if (uVar3 == 0) {
    ((int (*)())FUN_0002fac0)();
    uVar3 = (uint)*(byte *)(param_2 + 0x38);
  }
  iVar4 = uVar3 * 0x24;
  uVar5 = *(uint *)(&DAT_001d9f44 + iVar4);
  if ((uVar5 & 0x3f0000) != 0) {
    if ((uVar5 & 0xfc00) != 0) {
      if ((((uVar5 & 0x3f0) != 0) && (*(uint *)(&DAT_001d9f48 + iVar4) >> 0x1a != 0)) &&
         (*(short *)(*(int *)(param_2 + 0x30) + 2) == 0x1907)) {
        uVar1 = *(ushort *)(&DAT_001d9f3e + iVar4);
        param_5[4] = 0;
        *param_5 = (uint)uVar1;
        param_5[7] = *(uint *)(&DAT_001d9f48 + iVar4) >> 8 & 0x3f;
        goto LAB_000310c0;
      }
    }
  }
  if (uVar3 == 0x29) {
    sVar2 = *(short *)(*(int *)(param_2 + 0x30) + 2);
    if (sVar2 == 0x1902) {
      *param_5 = 0x81a6;
      param_5[7] = (*(unsigned int *)0x001da50c) >> 8 & 0x3f;
    }
    else if (sVar2 == 0x1901) {
      param_5[7] = 0;
      *param_5 = 0x81a6;
    }
    else {
      *param_5 = (uint)(*(unsigned int *)0x001da500);
      param_5[7] = (*(unsigned int *)0x001da50c) >> 8 & 0x3f;
    }
    param_5[4] = 0;
  }
  else {
    *param_5 = (uint)*(ushort *)(&DAT_001d9f3c + iVar4);
    param_5[4] = *(uint *)(&DAT_001d9f48 + iVar4) >> 0x1a;
    param_5[7] = *(uint *)(&DAT_001d9f48 + iVar4) >> 8 & 0x3f;
  }
LAB_000310c0:
  param_5[1] = *(ushort *)(&DAT_001d9f44 + iVar4) & 0x3f;
  param_5[2] = *(uint *)(&DAT_001d9f44 + iVar4) >> 10 & 0x3f;
  param_5[3] = *(uint *)(&DAT_001d9f44 + iVar4) >> 4 & 0x3f;
  param_5[5] = *(uint *)(&DAT_001d9f48 + iVar4) >> 0x14 & 0x3f;
  param_5[6] = *(uint *)(&DAT_001d9f48 + iVar4) >> 0xe & 0x3f;
  uVar3 = *(uint *)(&DAT_001d9f48 + iVar4) >> 3 & 1;
  *(char *)(param_5 + 9) = (char)uVar3;
  if (uVar3 == 0) {
    param_5[8] = 0;
  }
  else {
    iVar4 = *(int *)(param_2 + 0x30) + 0xa0 + param_4 * 0x18 + param_3 * 0x168;
    uVar3 = ((int (*)())FUN_000303d0)(*(undefined1 *)(param_2 + 0x38),*(undefined2 *)(iVar4 + 4),
                         *(undefined2 *)(iVar4 + 6),*(undefined2 *)(iVar4 + 8));
    param_5[8] = uVar3;
  }
  return;
}

/* FUN_00031170 @ 0x31170 (164 bytes) */
int FUN_00031170(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  uint param_1;
  undefined4 param_2;
  int param_3;
  uint *param_4;
  uint *param_5;
  uint *param_6;
  int *param_7;
  uint *param_8;
{
  int iVar1;
  uint *in_stack_00000038;
  
  iVar1 = (param_1 & 0xff) * 0x24;
  *(uint *)(param_3 + 0x18) = *(uint *)(&DAT_001d9f44 + iVar1) >> 0x1b;
  *(uint *)(param_3 + 0x1c) = *(uint *)(&DAT_001d9f44 + iVar1) >> 0x16 & 0x1f;
  *param_8 = *(uint *)(&DAT_001d9f4c + iVar1) >> 0x17 & 0x1f;
  *in_stack_00000038 = *(uint *)(&DAT_001d9f4c + iVar1) >> 0x1e;
  *param_4 = *(uint *)(&DAT_001d9f48 + iVar1) & 7;
  *param_5 = *(uint *)(&DAT_001d9f4c + iVar1) >> 0x14 & 7;
  *param_6 = *(uint *)(&DAT_001d9f4c + iVar1) >> 0x11 & 7;
  *param_7 = 1 << (*(uint *)(&DAT_001d9f48 + iVar1) & 7);
  *(uint *)(param_3 + 0x24) = *(uint *)(param_3 + 0x24) & *(uint *)(&DAT_001d9f40 + iVar1);
  return;
}

/* FUN_00031220 @ 0x31220 (280 bytes) */
int FUN_00031220(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  undefined *puVar4;
  ushort *puVar5;
  
  puVar5 = *(ushort **)(param_2 + 0x30);
  if (*(char *)(param_2 + 0x38) == '\0') {
    ((int (*)())FUN_0002fac0)();
  }
  bVar1 = param_5 == 0;
  if ((((!bVar1) ||
       ((((*(uint *)(((unsigned char *)0x000030b0) + *(int *)(param_1 + 0x10)) & 0x1ff) == 0 &&
         ((*(uint *)(((unsigned char *)0x000030b4) + *(int *)(param_1 + 0x10)) & 0xff0000) == 0)) &&
        ((*(uint *)(((unsigned char *)0x000030b4) + *(int *)(param_1 + 0x10)) & 0xff1) == 0)))) &&
      ((*(char *)(puVar5 + param_3 * 0xb4 + param_4 * 0xc + 0x55) == '\0' &&
       (uVar2 = *puVar5, (uVar2 & 0xf) != 4)))) && ((!bVar1 || ((uVar2 & 0x400) == 0)))) {
    iVar3 = (uint)*(byte *)(param_2 + 0x38) * 0x24;
    puVar4 = &DAT_001d9f34 + iVar3;
    if (((*(uint *)(*(int *)(param_2 + 0x30) + 0x48) & 0x8000) == 0) && (bVar1)) {
      return puVar4;
    }
    if (param_4 != *(byte *)(*(int *)(param_2 + 0x30) + 0x5e)) {
      return puVar4;
    }
    if ((*(uint *)(&DAT_001d9f54 + iVar3) & 0x1000000) != 0) {
      return puVar4;
    }
  }
  return (undefined *)0x0;
}

/* FUN_00031340 @ 0x31340 (1352 bytes) */
int FUN_00031340(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int *param_2;
  int param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
  int param_8;
{
  byte bVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  short sVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined1 auStack_140 [4];
  undefined1 auStack_13c [4];
  undefined1 auStack_138 [4];
  undefined1 auStack_134 [4];
  undefined1 auStack_130 [8];
  int local_128;
  uint local_124;
  undefined4 local_120;
  undefined4 local_11c;
  int local_118;
  int local_114;
  undefined1 auStack_110 [4];
  undefined1 auStack_10c [4];
  undefined4 local_108;
  uint local_104[0];
  undefined4 local_100;
  int local_fc;
  int local_f8;
  undefined1 local_bc;
  undefined4 local_b8[0];
  uint local_b4;
  undefined4 local_a0;
  undefined4 local_9c;
  
  puVar13 = (undefined4 *)param_2[0xd];
  iVar11 = *param_2;
  if ((puVar13 == (undefined4 *)0x0) || (*(char *)(param_2 + 0xe) == '\0')) {
LAB_00031860:
    return ((unsigned char *)0x00002717);
  }
  if ((*(short *)(param_2[0xc] + 2) == 0x1902) && (*(char *)(param_2 + 0x32) == '\x01')) {
    puVar7 = (undefined4 *)(**(code **)(param_1 + 0x2998))(param_1 + 0x240,0x3fa);
    *(undefined4 **)(param_1 + 0x298c) = puVar7;
    puVar5 = *(uint **)(param_1 + 0x1d8);
    *puVar5 = (int)puVar7 - (int)puVar5 >> 2 | *puVar5;
    *(undefined4 **)(param_1 + 0x1d8) = puVar7;
    *puVar7 = 0x45000000;
    puVar7[1] = 0x3ed;
    puVar7[2] = 0xd;
    puVar7[3] = *(undefined4 *)param_2[0xd];
    bVar1 = *(byte *)(param_2 + 0xe);
    puVar7[0x3ed] = ((unsigned char *)0x000013c4);
    puVar7[4] = (uint)bVar1;
    puVar7[0x3f6] = ((unsigned char *)0x000013ca);
    puVar7[0x3ef] = 0x113c8;
    puVar7[0x3f4] = ((unsigned char *)0x000013cc);
    puVar7[0x3f2] = ((unsigned char *)0x000013cd);
    *(undefined4 **)(param_1 + 0x298c) = puVar7 + 0x3f8;
    (**(code **)(param_1 + 0x299c))(param_1 + 0x240,puVar7 + 0x3f8);
    if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
      FUN_0001a0f0(param_1,0x1000000);
    }
    *(undefined1 *)(param_2 + 0x32) = 0;
  }
  cVar2 = *(char *)((int)puVar13 + 0x16);
  if ((cVar2 != '\x03') && (cVar2 != '\a')) {
    if (cVar2 == '\x06') {
      if ((0x1ffff < (int)puVar13[4]) &&
         (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc))) {
        FUN_0001a0f0(param_1,0x1000000);
      }
      param_3 = param_3 * 2;
      if ((((uint)*(ushort *)((int)puVar13 + param_3 + 0x28) &
           ~(uint)*(ushort *)((int)puVar13 + param_3 + 0x1c)) >> (param_4 & 0x3f) & 1) == 0) {
        return (undefined *)0x0;
      }
      iVar11 = FUN_0001a0d0(param_1,puVar13[3]);
      if (iVar11 == 0) {
        _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,puVar13 + 3,1,0,0);
      }
      if ((param_7 != 0) && ((*(uint *)(param_1 + 0x24) & 0x82) != 0)) {
        FUN_0000b670(param_1,param_7,param_2[4]);
      }
      *(ushort *)((int)puVar13 + param_3 + 0x1c) =
           *(ushort *)((int)puVar13 + param_3 + 0x1c) | *(ushort *)((int)puVar13 + param_3 + 0x28);
      return (undefined *)0x0;
    }
    goto LAB_00031860;
  }
  iVar10 = iVar11 + 0x40 + (param_3 * 0xd + param_4) * 0x20;
  if ((0x1ffff < (int)puVar13[4]) &&
     (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc))) {
    FUN_0001a0f0(param_1,0x1000000);
  }
  if ((((uint)*(ushort *)((int)puVar13 + param_3 * 2 + 0x28) &
       ~(uint)*(ushort *)((int)puVar13 + param_3 * 2 + 0x1c)) >> (param_4 & 0x3f) & 1) != 0) {
    local_b8[0] = *puVar13;
    local_b4 = param_4 | param_3 << 0x10;
    _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),0xd,&local_b8,2,0,0);
  }
  if ((*(uint *)(iVar11 + 0x20) & 0x10000000) != 0) {
    iVar8 = FUN_0001a0d0(param_1,*(undefined4 *)(iVar11 + 0x1c));
    if (iVar8 == 0) {
      _io_connect_method_scalarI_structureI(*(undefined4 *)(param_1 + 4),9,iVar11 + 0x1c,1,0,0);
    }
    *(uint *)(iVar11 + 0x20) = *(uint *)(iVar11 + 0x20) & 0xefffffff;
  }
  if (*(char *)((int)puVar13 + 0x16) == '\a') {
    return (undefined *)0x0;
  }
  param_4 = param_4 - *(byte *)((int)puVar13 + 0x17);
  iVar4 = (int)(uint)*(ushort *)(iVar11 + 0x14) >> (param_4 & 0x3f);
  iVar12 = (int)(uint)*(ushort *)(iVar11 + 0x16) >> (param_4 & 0x3f);
  iVar9 = (int)(uint)*(ushort *)(iVar11 + 0x18) >> (param_4 & 0x3f);
  iVar8 = 1;
  if (0 < iVar4) {
    iVar8 = iVar4;
  }
  if (iVar12 < 1) {
    iVar12 = 1;
  }
  if (iVar9 < 1) {
    iVar9 = 1;
  }
  iVar9 = iVar9 / (int)(uint)*(ushort *)(iVar10 + 2);
  ((int (*)())FUN_00031170)(*(undefined1 *)(param_2 + 0xe),param_2,&local_b8,auStack_140,auStack_13c,auStack_138,
               auStack_134,auStack_130);
  local_108 = 2;
  local_120 = local_a0;
  local_11c = local_9c;
  local_104[0] = 0;
  local_100 = 0xffffefff;
  local_124 = *(uint *)(iVar11 + 0x10) >> (param_4 & 0x3f);
  if ((int)local_124 < 0x20) {
    local_124 = 0x20;
  }
  local_bc = 0;
  local_118 = param_7;
  local_114 = param_8;
  local_fc = iVar8;
  local_f8 = iVar12;
  _glgConvertType(param_5,param_6,auStack_110,auStack_10c);
  iVar11 = *(int *)(iVar10 + 0x1c);
  if (iVar11 == 0) goto LAB_00031860;
  sVar6 = *(short *)(param_2[0xc] + 2);
  if ((sVar6 == 0x1909) || (uVar3 = local_104[0] | 0x20000, sVar6 == 0x1907)) {
    local_104[0] = local_104[0] | 0x28000;
    sVar6 = *(short *)(param_2[0xc] + 2);
    uVar3 = local_104[0];
    if (sVar6 != 0x1909) goto LAB_000316d8;
  }
  else {
LAB_000316d8:
    local_104[0] = uVar3;
    if ((sVar6 != -0x7fb7) && (sVar6 != 0x190a)) goto LAB_000316fc;
  }
  local_104[0] = local_104[0] | 0x40000;
LAB_000316fc:
  if (*(short *)(iVar10 + 2) != 0) {
    iVar8 = 0;
    do {
      if (0 < iVar9) {
        iVar4 = 0;
        local_128 = iVar11;
        do {
          iVar4 = iVar4 + 1;
          _glgProcessPixels(0,&local_128);
          local_128 = iVar12 * local_124 + local_128;
          local_118 = iVar12 * local_114 + local_118;
        } while (iVar9 != iVar4);
      }
      iVar8 = iVar8 + 1;
      iVar11 = iVar11 + *(int *)(iVar10 + 0xc);
    } while (iVar8 < (int)(uint)*(ushort *)(iVar10 + 2));
  }
  return (undefined *)0x0;
}

/* _gldGetTextureLevel @ 0x31890 (176 bytes) */
int _gldGetTextureLevel(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  ushort uVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  
  puVar3 = ((unsigned char *)0x00002717);
  if (*(int *)(param_2 + 0x30) != 0) {
    iVar4 = *(int *)(param_2 + 0x30) + 0xa0 + param_4 * 0x18 + param_3 * 0x168;
    uVar1 = *(ushort *)(iVar4 + 0xc);
    iVar2 = FUN_0000a3f0(*(undefined2 *)(iVar4 + 0x10),*(undefined2 *)(iVar4 + 0x12));
    _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
    puVar3 = (undefined *)
             ((int (*)())FUN_00031340)(param_1,param_2,param_3,param_4,*(undefined2 *)(iVar4 + 0x10),
                          *(undefined2 *)(iVar4 + 0x12),*(undefined4 *)(iVar4 + 0x14),
                          (uint)uVar1 * iVar2);
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
  }
  return puVar3;
}

/* FUN_00031940 @ 0x31940 (1972 bytes) */
int FUN_00031940(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  uint uVar14;
  uint uVar15;
  void *pvVar16;
  int *piVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  int *piVar24;
  int *piVar25;
  undefined *puVar26;
  int iVar27;
  uint local_f8;
  uint local_f4;
  int local_f0;
  int local_ec;
  undefined1 auStack_e8 [4];
  void *local_e4;
  int local_e0;
  undefined1 auStack_dc [4];
  undefined1 auStack_d8 [4];
  int *local_d4;
  uint local_d0;
  undefined4 local_c0;
  uint local_b8[0];
  uint local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  uint local_68;
  int local_64;
  int *local_60;
  void **local_5c;
  
  iVar10 = param_2[0xc];
  iVar8 = (uint)*(byte *)(param_2 + 0xe) * 0x24;
  bVar2 = *(byte *)(iVar10 + 0x5e);
  uVar18 = (uint)bVar2;
  uVar3 = *(ushort *)(iVar10 + 0x7c);
  local_5c = &local_e4;
  iVar27 = iVar10 + 0xa0 + uVar18 * 0x18;
  uVar20 = (uint)((*(uint *)(&DAT_001d9f48 + iVar8) & 7) == 4);
  iVar10 = FUN_0000a3f0(*(undefined2 *)(iVar27 + 0x10),*(undefined2 *)(iVar27 + 0x12));
  iVar23 = iVar10 * (uint)*(ushort *)(iVar27 + 0xc);
  uVar19 = uVar20 ^ 1;
  pvVar16 = (void *)((uint)*(byte *)(iVar27 + 10) * (iVar10 + iVar23) + *(int *)(iVar27 + 0x14));
  ((int (*)())FUN_00031170)(*(undefined1 *)(param_2 + 0xe),param_2,local_5c,&local_f8,auStack_e8,auStack_e8,
               &local_ec,&local_f4);
  uVar22 = (uint)*(ushort *)(iVar27 + 4) + (uint)*(byte *)(iVar27 + 10) * -2;
  if ((int)uVar22 < 1) {
    uVar22 = 1;
  }
  uVar21 = (uint)*(ushort *)(iVar27 + 6) + (uint)*(byte *)(iVar27 + 10) * -2;
  if ((int)uVar21 < 1) {
    uVar21 = 1;
  }
  local_c0 = 0;
  if (uVar20 == 0) {
    uVar14 = *(uint *)(&DAT_001d9f4c + iVar8) >> 0x1c & 3;
    if (uVar14 == 0) {
      local_64 = 1;
      uVar15 = 0;
    }
    else {
      local_64 = 0;
      uVar15 = uVar14;
    }
  }
  else {
    uVar14 = 0;
    local_64 = 0;
    uVar15 = 0;
  }
  if (((uVar20 != 0) || ((*(uint *)(&DAT_001d9f4c + iVar8) & 0x30000000) != 0x20000000)) ||
     (local_68 = 1, (*(uint *)(&DAT_001d9f48 + iVar8) & 7) != 1)) {
    local_68 = 0;
  }
  uVar15 = 8 << uVar15;
  uVar20 = (0x20 >> (local_f8 + uVar14 & 0x3f)) * 8;
  if ((uVar22 <= uVar20) || (uVar14 = 1, uVar21 <= uVar15)) {
    uVar14 = 0;
  }
  uVar7 = (uVar22 << (local_f8 & 0x3f)) + 0x1f & 0xffffffe0;
  iVar8 = uVar7 * uVar21;
  if (uVar14 == 0) {
    uVar19 = 0;
    iVar10 = iVar8;
    uVar20 = uVar7;
  }
  else {
    uVar20 = uVar20 * (((uVar20 + uVar22) - 1) / uVar20) << (local_f8 & 0x3f);
    iVar10 = uVar15 * (((uVar15 + uVar21) - 1) / uVar15) * uVar20;
  }
  *(short *)((int)param_2 + 0x3e) = (short)(uVar20 >> (local_f8 & 0x3f));
  iVar10 = FUN_0000acb0(param_1,param_2,iVar8 + 0x3a0,iVar10);
  if (iVar10 == 0) {
    return 0;
  }
  *(byte *)(param_2[0xd] + 0x15) =
       (byte)(uVar14 << 2) | (byte)((uVar19 << (local_68 & 0x3f)) << 3) & 0x18;
  piVar24 = (int *)*param_2;
  if ((uVar3 & 1) != 0) {
    piVar25 = piVar24 + 0x368;
    _glgConvertType(*(undefined2 *)(iVar27 + 0x10),*(undefined2 *)(iVar27 + 0x12),auStack_dc,
                    auStack_d8);
    local_ac = 0;
    local_b0 = 0;
    local_60 = piVar24 + 0x280;
    local_e4 = pvVar16;
    local_e0 = iVar23;
    local_d4 = piVar25;
    local_d0 = uVar7;
    local_b8[0] = uVar22;
    local_b4 = uVar21;
    iVar10 = ((int (*)())FUN_0002f4d0)(*(undefined2 *)(iVar27 + 0x10),*(undefined2 *)(iVar27 + 0x12),
                          *(undefined1 *)(param_2 + 0xe));
    if (iVar10 == 0) {
      _glgProcessPixels(0,local_5c);
    }
    else if (uVar21 != 0) {
      uVar15 = 0;
      do {
        uVar15 = uVar15 + 1;
        _memcpy(piVar25,pvVar16,local_ec * local_b8[0]);
        piVar25 = (int *)((int)piVar25 + local_d0);
        pvVar16 = (void *)((int)pvVar16 + local_e0);
      } while (uVar15 < local_b4);
    }
    if ((*(uint *)(param_1 + 0x24) & 0x82) != 0) {
      FUN_0000b620(param_1,local_60 + 0x20,iVar8);
    }
  }
  if ((*(byte *)((int)param_2 + 0x39) & 3) == 0) goto LAB_00032098;
  if ((local_f4 < 3) || ((iVar8 = 1, 4 < local_f4 && (iVar8 = 2, local_f4 != 6)))) {
    iVar8 = 0;
  }
  piVar25 = piVar24 + 0x280;
  *(byte *)(param_2[0xd] + 0x17) = bVar2;
  bVar1 = (int)(uVar22 << (local_f8 & 0x3f)) >> iVar8 < 0x2000;
  *(undefined1 *)(param_2[0xd] + 0x34) = 1;
  *(undefined1 *)(param_2[0xd] + 0x35) = 1;
  *(uint *)(*param_2 + 0x20) = (uint)bVar1 << 0x1f | *(uint *)(*param_2 + 0x20) & 0x7fffffff;
  *(uint *)(*param_2 + 0x20) = *(uint *)(*param_2 + 0x20) | 0x40000000;
  piVar24[1] = 0x20;
  piVar24[2] = 0;
  *piVar24 = 0;
  uVar15 = piVar24[8];
  piVar24[8] = uVar15 & 0xefffffff;
  *(char *)((int)piVar24 + 0x1a) = (char)local_f8;
  *(undefined2 *)(piVar24 + 6) = 1;
  *(short *)(piVar24 + 5) = (short)uVar22;
  *(short *)((int)piVar24 + 0x16) = (short)uVar21;
  piVar24[8] = uVar15 & 0xcfffffff;
  piVar24[3] = uVar20;
  piVar24[4] = uVar7;
  *(char *)((int)piVar24 + 0x1b) = (char)local_f0;
  iVar10 = (uint)*(byte *)(param_2 + 0xe) * 0x24;
  puVar26 = &DAT_001d9f34 + iVar10;
  if ((*(uint *)(&DAT_001d9f4c + iVar10) & 0x10000) == 0) {
    if ((*(uint *)(&DAT_001d9f48 + iVar10) & 8) == 0) {
      uVar15 = *(uint *)(&DAT_001d9f48 + iVar10) & 7;
      if (uVar15 == 1) {
        puVar26 = &DAT_001da00c;
      }
      else if (uVar15 < 2) {
        if (uVar15 == 0) {
          puVar26 = &DAT_001d9fa0;
        }
        else {
LAB_00031db8:
          puVar26 = &DAT_001da1bc;
        }
      }
      else {
        if (uVar15 == 2) goto LAB_00031eb4;
        if (uVar15 != 3) goto LAB_00031db8;
        puVar26 = &DAT_001da36c;
      }
    }
    else {
LAB_00031eb4:
      puVar26 = &DAT_001da054;
    }
  }
  _memcpy(piVar24 + 0x2a0,PTR_DAT_001e899c,0x23c);
  uVar9 = piVar24[0x306];
  uVar11 = piVar24[0x31c];
  piVar24[0x2ab] = 0;
  uVar15 = *(uint *)(puVar26 + 0x18) >> 5 & 0x1f;
  piVar24[0x306] = uVar15 | uVar9 & 0xffffffe0;
  uVar4 = (*(uint *)(puVar26 + 0x18) & 0x18) << 5;
  piVar24[0x306] = uVar4 | uVar15 | uVar9 & 0xfffffce0;
  uVar5 = (*(uint *)(puVar26 + 0x18) & 6) << 9;
  piVar24[0x306] = uVar5 | uVar4 | uVar15 | uVar9 & 0xfffff0e0;
  uVar6 = *(uint *)(puVar26 + 0x1c) >> 0x12 & 0x3000;
  piVar24[0x306] = uVar6 | uVar5 | uVar4 | uVar15 | uVar9 & 0xffffc0e0;
  piVar24[0x306] =
       *(uint *)(puVar26 + 0x1c) >> 0xe & 0xc000 |
       uVar6 | uVar5 | uVar4 | uVar15 | uVar9 & 0xfff000e0;
  uVar15 = *(uint *)(puVar26 + 0x1c) >> 7 & 0x1f;
  piVar24[0x31c] = uVar15 | uVar11 & 0xfffffe00;
  uVar4 = (*(uint *)(puVar26 + 0x1c) & 0x70) << 5;
  piVar24[0x31c] = uVar4 | uVar15 | uVar11 & 0xfffff000;
  uVar5 = (*(uint *)(puVar26 + 0x1c) & 0xe) << 0xb;
  piVar24[0x31c] = uVar5 | uVar4 | uVar15 | uVar11 & 0xffff8000;
  uVar6 = *(uint *)(puVar26 + 0x20) >> 0xe & 0x38000;
  piVar24[0x31c] = uVar6 | uVar5 | uVar4 | uVar15 | uVar11 & 0xfffc0000;
  uVar9 = *(uint *)(puVar26 + 0x20) >> 8 & 0x1c0000;
  piVar24[0x31c] = uVar9 | uVar6 | uVar5 | uVar4 | uVar15 | uVar11 & 0xffc00000;
  piVar24[0x31c] =
       (*(uint *)(puVar26 + 0x20) >> 0x19 & 1) << 0x16 |
       uVar9 | uVar6 | uVar5 | uVar4 | uVar15 | uVar11 & 0xf8000000;
  piVar17 = piVar25;
  if (bVar1) {
    *piVar25 = (int)((unsigned char *)0x00001393);
    piVar24[0x281] = 10;
    piVar24[0x282] = 0x5c8;
    piVar24[0x283] = 0x20000;
    piVar24[0x284] = 0x575;
    piVar17 = piVar24 + 0x286;
    piVar24[0x285] = local_f0;
  }
  iVar23 = (int)piVar17 - (int)piVar25 >> 2;
  *(short *)(piVar24 + uVar18 * 8 + 0x10) = (short)iVar23;
  iVar10 = piVar24[1];
  piVar24[uVar18 * 8 + 0x17] = (int)(piVar24 + 0x368);
  piVar24[uVar18 * 8 + 0x11] = 0xda0;
  piVar24[uVar18 * 8 + 0x15] = 0;
  *(undefined2 *)((int)piVar24 + uVar18 * 0x20 + 0x42) = 1;
  piVar24[uVar18 * 8 + 0x12] = 0;
  piVar24[uVar18 * 8 + 0x13] = 0;
  piVar24[uVar18 * 8 + 0x14] = 0;
  *(short *)(piVar24 + uVar18 * 8 + 0x16) =
       (short)((int)(piVar24 + 0x32f) - (int)piVar25 >> 2) - (short)iVar10;
  if ((uVar19 == 0) || (uVar18 = 1, local_64 != 0)) {
    uVar18 = 0;
  }
  uVar14 = (local_68 << 1 | uVar18) << 1 | uVar14;
  puVar12 = (undefined4 *)
            ((int (*)())FUN_00030420)(piVar24 + 0x32f,puVar26,uVar7,uVar20,uVar14,
                         (int)(uVar22 << (local_f8 & 0x3f)) >> (*(uint *)(puVar26 + 0x14) & 7),
                         uVar21);
  *puVar12 = ((unsigned char *)0x00001393);
  puVar12[1] = 10;
  puVar12[2] = 0x5c8;
  puVar12[3] = 0x20000;
  puVar12[4] = ((unsigned char *)0x00001040);
  puVar12[5] = 0;
  if (bVar1) {
    puVar13 = (undefined4 *)
              ((int (*)())FUN_00030a60)(piVar17,local_f4,uVar7,uVar20,uVar14,0,
                           uVar21 << 0x10 | (int)(uVar22 << (local_f8 & 0x3f)) >> iVar8);
    *puVar13 = 0xd0b;
    puVar13[1] = 5;
    puVar13[2] = 0x5c8;
    puVar13[3] = 0x10000;
    puVar13[4] = ((unsigned char *)0x00001040);
    puVar13[5] = 0;
    iVar23 = (int)puVar13 + (0x18 - (int)piVar25) >> 2;
  }
  *piVar24 = iVar23;
  piVar24[2] = ((int)puVar12 + (0x18 - (int)piVar25) >> 2) - piVar24[1];
LAB_00032098:
  *(ushort *)(param_2[0xd] + 0x1c) = uVar3 | *(ushort *)(param_2[0xd] + 0x1c);
  *(ushort *)(param_2[0xd] + 0x28) = ~uVar3 & *(ushort *)(param_2[0xd] + 0x28);
  *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) & 0xf8;
  *(ushort *)(param_2 + 9) = ~uVar3 & *(ushort *)(param_2 + 9);
  return 1;
}

/* FUN_00032100 @ 0x32100 (8252 bytes) */
int FUN_00032100(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  undefined1 uVar4;
  short sVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  uint uVar8;
  uint uVar9;
  ushort uVar10;
  void *pvVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  byte bVar19;
  undefined4 *puVar17;
  int *piVar18;
  byte bVar20;
  int *piVar21;
  uint uVar22;
  undefined4 uVar23;
  uint uVar24;
  uint uVar25;
  int iVar26;
  uint uVar27;
  int *piVar28;
  int iVar29;
  ushort uVar30;
  uint uVar31;
  int iVar32;
  uint uVar33;
  void *pvVar34;
  ushort *puVar35;
  int iVar36;
  size_t sVar37;
  int *piVar38;
  void *pvVar39;
  int iVar40;
  undefined *puVar41;
  byte in_xer_so;
  bool bVar42;
  bool bVar43;
  byte in_cr1;
  byte unaff_cr2;
  byte unaff_cr3;
  byte unaff_cr4;
  byte in_cr5;
  byte bVar44;
  byte bVar45;
  int iStack00000018;
  uint local_218;
  uint local_214;
  uint local_210;
  int local_20c;
  int local_208;
  int local_204;
  int aiStack_200 [14];
  int aiStack_1c8 [9];
  undefined4 local_1a4;
  void *local_158;
  uint local_154;
  undefined1 auStack_150 [4];
  undefined1 auStack_14c [4];
  void *local_148;
  int local_144;
  undefined4 local_138;
  uint local_134;
  undefined *local_130;
  uint local_12c;
  uint local_128;
  undefined4 local_124;
  undefined4 local_120;
  int *local_e8;
  int local_e4;
  int local_e0;
  int *local_dc;
  int local_d8;
  int *local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c4;
  uint local_c0;
  int local_bc;
  uint local_b8[0];
  void *local_b4;
  uint local_b0;
  int local_ac;
  uint local_a8;
  uint local_a4;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  void *local_90;
  int *local_8c;
  uint local_88[0];
  int *local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  int local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  void **local_64;
  uint local_60;
  int *local_5c;
  uint local_58;
  uint local_54;
  
  puVar35 = (ushort *)param_2[0xc];
  iStack00000018 = param_1;
  iVar16 = ((int (*)())FUN_00030b50)(param_2);
  if (iVar16 != 0) {
    iVar29 = param_2[0xc];
    bVar44 = *(byte *)(iVar29 + 1);
    bVar19 = bVar44 & 0xf;
    *(byte *)(param_2 + 0x1b) = bVar19;
    iVar16 = *(short *)(iVar29 + 0x3c) * 0x18 + iVar29;
    uVar27 = (uint)*(byte *)(iVar16 + 0xaa);
    if ((bVar44 & 0xf) == 0) {
      uVar31 = (uint)*(ushort *)(iVar16 + 0xa4) + uVar27 * -2;
      if ((int)uVar31 < 1) {
        uVar31 = 1;
      }
      uVar27 = (uint)*(ushort *)(iVar16 + 0xa6) + uVar27 * -2;
      if ((int)uVar27 < 1) {
        uVar27 = 1;
      }
      if (((uVar31 & uVar31 - 1) == 0) && ((uVar27 & uVar27 - 1) == 0)) goto LAB_00032230;
      goto LAB_00032380;
    }
    if (bVar19 == 1) {
      uVar31 = (uint)*(ushort *)(iVar16 + 0xa4) + uVar27 * -2;
      if ((int)uVar31 < 1) {
        uVar31 = 1;
      }
      uVar25 = (uint)*(ushort *)(iVar16 + 0xa6) + uVar27 * -2;
      if ((int)uVar25 < 1) {
        uVar25 = 1;
      }
      uVar27 = (uint)*(ushort *)(iVar16 + 0xa8) + uVar27 * -2;
      if ((int)uVar27 < 1) {
        uVar27 = 1;
      }
      if ((((uVar31 & uVar31 - 1) != 0) || ((uVar25 & uVar25 - 1) != 0)) ||
         ((uVar27 & uVar27 - 1) != 0)) goto LAB_00032380;
    }
LAB_00032230:
    bVar44 = *(byte *)(iVar29 + 1) & 0xf;
    *(byte *)(param_2 + 0x1b) = bVar44;
    iVar16 = *(short *)(iVar29 + 0x3c) * 0x18 + iVar29;
    uVar27 = (uint)*(byte *)(iVar16 + 0xaa);
    if (bVar44 == 3) {
      uVar31 = (uint)*(ushort *)(iVar16 + 0xa4) + uVar27 * -2;
      if ((int)uVar31 < 1) {
        uVar31 = 1;
      }
      uVar27 = (uint)*(ushort *)(iVar16 + 0xa6) + uVar27 * -2;
      if ((int)uVar27 < 1) {
        uVar27 = 1;
      }
      if (((uVar31 & uVar31 - 1) != 0) || ((uVar27 & uVar27 - 1) != 0)) {
        if ((ushort)(*(short *)(iVar29 + 0x16) + 0xda00U) < 2) {
          uVar30 = *(ushort *)(iVar29 + 0x10);
          if (uVar30 < 0x8744) {
            if (((uVar30 < 0x8742) && (uVar30 != 0x2901)) && (uVar30 != 0x8370)) {
LAB_00032340:
              uVar30 = *(ushort *)(iVar29 + 0x12);
              if (0x8743 < uVar30) goto LAB_00032370;
LAB_0003234c:
              if (((uVar30 < 0x8742) && (uVar30 != 0x2901)) && (uVar30 != 0x8370))
              goto LAB_00032390;
            }
          }
          else if (uVar30 != 0x8912) goto LAB_00032340;
        }
LAB_00032380:
        *(undefined1 *)(param_2 + 0x11) = 1;
        goto LAB_000323a0;
      }
    }
    else if (bVar44 == 4) {
      uVar27 = (uint)*(ushort *)(iVar16 + 0xa4) + uVar27 * -2;
      if ((int)uVar27 < 1) {
        uVar27 = 1;
      }
      if ((uVar27 & uVar27 - 1) != 0) {
        if (1 < (ushort)(*(short *)(iVar29 + 0x16) + 0xda00U)) goto LAB_00032380;
        uVar30 = *(ushort *)(iVar29 + 0x10);
        if (uVar30 < 0x8744) goto LAB_0003234c;
LAB_00032370:
        if (uVar30 == 0x8912) goto LAB_00032380;
      }
    }
LAB_00032390:
    *(undefined1 *)(param_2 + 0x11) = 0;
  }
LAB_000323a0:
  bVar44 = *(byte *)((int)param_2 + 0x39);
  *(byte *)((int)param_2 + 0x39) = bVar44 & 0x9f;
  if ((bVar44 & 0x1f) == 0) {
    ((int (*)())FUN_0002ee30)(iStack00000018,param_2);
    return 1;
  }
  ((int (*)())FUN_0002fac0)(iStack00000018,param_2);
  if (*(char *)(param_2 + 0xe) == '\0') {
    return 0;
  }
  bVar42 = *(char *)((int)puVar35 + 0x6f) == '\0';
  bVar44 = (*(char *)((int)puVar35 + 0x6f) != '\0') << 2 | bVar42 << 1 | in_xer_so & 1;
  if (!bVar42) {
    if (((unsigned char *)0x00001001) <= (undefined *)(1 << (*(byte *)(puVar35 + 0x32) & 0x3f))) {
      return 0;
    }
    if (((unsigned char *)0x00001001) <= (undefined *)(1 << (*(byte *)((int)puVar35 + 0x65) & 0x3f))) {
      return 0;
    }
    if (0x100 < (uint)(1 << (*(byte *)(puVar35 + 0x33) & 0x3f))) {
      return 0;
    }
  }
  uVar30 = *puVar35;
  uVar27 = (uint)*(byte *)(puVar35 + 0x2f);
  if ((uVar30 & 0x400) == 0) {
    if ((uVar30 & 0x800) != 0) {
      iVar16 = FUN_0000b4f0(iStack00000018,param_2,*(undefined4 *)(puVar35 + 4));
      if (iVar16 == 0) {
        return 0;
      }
      if (*(char *)((int)puVar35 + 0x6d) != '\0') {
        uVar27 = 1 << (*(uint *)(&DAT_001d9f48 + (uint)*(byte *)(param_2 + 0xe) * 0x24) & 7);
        *(short *)((int)param_2 + 0x3e) =
             (short)((uVar27 * ((uint)puVar35[0x52] + (uint)*(byte *)(puVar35 + 0x55) * -2) + 0x1f &
                     0xffffffe0) / uVar27);
      }
      goto LAB_00032600;
    }
    if ((uVar30 & 0x2000) != 0) {
      iVar16 = ((int (*)())FUN_00031940)(iStack00000018,param_2);
      if (iVar16 == 0) {
        return 0;
      }
      goto LAB_00032600;
    }
    if ((((((*(float *)(param_2[0xc] + 4) == FLOAT_001aa0d4) ||
           (sVar5 = *(short *)(param_2[0xc] + 0x1a), sVar5 == -0x7a41)) || (sVar5 == -0x7a42)) &&
         ((*(char *)(puVar35 + 0x36) == '\x01' && (*(char *)(puVar35 + 0x35) == '\x01')))) &&
        (bVar42)) && (*(int *)(puVar35 + uVar27 * 0xc + 0x5a) != 0)) {
      iVar16 = FUN_0000a3f0(puVar35[uVar27 * 0xc + 0x58],puVar35[uVar27 * 0xc + 0x59]);
      uVar30 = puVar35[uVar27 * 0xc + 0x56];
      uVar31 = iVar16 * (int)(uint)uVar30;
      uVar25 = *(int *)(puVar35 + uVar27 * 0xc + 0x5a) +
               iVar16 * (uint)*(byte *)(puVar35 + uVar27 * 0xc + 0x55);
      if (*(char *)(puVar35 + 0x37) != '\0') {
        uVar25 = uVar25 + uVar31 * *(byte *)(puVar35 + uVar27 * 0xc + 0x55);
      }
      uVar4 = *(undefined1 *)(param_2 + 0xe);
      uVar33 = uVar25 & 0x1f;
      bVar44 = (uVar33 != 0) << 2 | (uVar33 == 0) << 1 | in_xer_so & 1;
      bVar19 = ((int (*)())FUN_0002f4d0)(puVar35[uVar27 * 0xc + 0x58],puVar35[uVar27 * 0xc + 0x59],uVar4);
      iVar29 = param_2[0xc];
      if (*(short *)(iVar29 + 0x1a) == -0x7a41) {
        bVar42 = (undefined *)(uint)uVar30 < ((unsigned char *)0x00004001);
      }
      else {
        bVar42 = uVar31 <= *(uint *)(iStack00000018 + 0x29d8);
      }
      if ((uVar33 == 0 & bVar19 & (uVar31 & 0x1f) == 0 & bVar42) == 0) goto LAB_00034128;
      bVar44 = *(byte *)(iVar29 + 0x5e);
      uVar33 = (uint)bVar44;
      local_1a4 = 0;
      ((int (*)())FUN_00031170)(uVar4,param_2,aiStack_1c8,&local_218,&local_208,&local_208,&local_210,&local_214)
      ;
      iVar36 = (uint)puVar35[uVar27 * 0xc + 0x52] +
               (uint)*(byte *)(puVar35 + uVar27 * 0xc + 0x55) * -2;
      if (iVar36 < 1) {
        iVar36 = 1;
      }
      uVar27 = (uint)puVar35[uVar27 * 0xc + 0x53] -
               (uint)*(byte *)(puVar35 + uVar27 * 0xc + 0x55) * (uint)*(byte *)(iVar29 + 0x6e);
      if ((int)uVar27 < 1) {
        uVar27 = 1;
      }
      iVar29 = uVar31 * (uVar27 - 1) + iVar16 * (iVar36 + 1U & 0xfffffffe);
      if ((*(uint *)(iStack00000018 + 0x24) & 0x82) == 0) {
        iVar32 = param_2[0xc];
      }
      else {
        iVar32 = param_2[0xc];
        if (((*(uint *)(iVar32 + 0x48) & 0x40) == 0) && (uVar27 != 0)) {
          uVar24 = 0;
          uVar22 = uVar25;
          do {
            uVar24 = uVar24 + 1;
            FUN_0000b620(iStack00000018,uVar22,iVar16 * iVar36);
            uVar22 = uVar22 + uVar31;
          } while (uVar24 < uVar27);
          iVar32 = param_2[0xc];
        }
      }
      uVar24 = *(uint *)(iVar32 + 0x50);
      uVar22 = uVar25;
      if ((uVar24 <= uVar25) &&
         (uVar12 = uVar24 + *(int *)(iVar32 + 0x4c), uVar25 + iVar29 <= uVar12)) {
        iVar29 = uVar12 - uVar24;
        uVar22 = uVar24;
      }
      if ((*(short *)(iVar32 + 0x1a) == -0x7a41) &&
         ((*(char *)(iVar32 + 0x6d) != '\0' || (iVar36 * iVar16 == uVar31)))) {
        *(short *)((int)param_2 + 0x3e) = (short)(uVar31 >> (local_218 & 0x3f));
        iVar16 = FUN_0000b150(iStack00000018,param_2,uVar25,uVar22,iVar29);
        if (iVar16 == 0) {
          return 0;
        }
        uVar30 = (ushort)(-2 << (uVar33 & 0x1f)) | (ushort)(0xfffffffe >> 0x20 - (uVar33 & 0x1f));
        *(byte *)(param_2[0xd] + 0x15) = (byte)local_20c & 3;
      }
      else {
        uVar24 = (iVar36 << (local_218 & 0x3f)) + 0x1fU & 0xffffffe0;
        *(short *)((int)param_2 + 0x3e) = (short)(uVar24 >> (local_218 & 0x3f));
        if ((*(byte *)((int)param_2 + 0x39) & 3) != 0) {
          if ((local_214 < 3) || ((iVar16 = 1, 4 < local_214 && (iVar16 = 2, local_214 != 6)))) {
            iVar16 = 0;
          }
          bVar42 = (iVar36 << (local_218 & 0x3f)) >> iVar16 < 0x2000;
          iVar29 = FUN_0000b270(iStack00000018,param_2,0x348,uVar24 * uVar27,uVar22,iVar29);
          if (iVar29 == 0) {
            return 0;
          }
          *(undefined1 *)(param_2[0xd] + 0x15) = 0;
          piVar38 = (int *)*param_2;
          uVar12 = piVar38[8];
          piVar38[2] = 0;
          piVar21 = piVar38 + 0x280;
          *piVar38 = 0;
          piVar38[1] = 0x20;
          piVar38[8] = (uint)bVar42 << 0x1f | uVar12 & 0x6fffffff | 0x40000000;
          *(char *)((int)piVar38 + 0x1a) = (char)local_218;
          *(undefined2 *)(piVar38 + 6) = 1;
          *(short *)(piVar38 + 5) = (short)iVar36;
          *(short *)((int)piVar38 + 0x16) = (short)uVar27;
          piVar38[8] = (uint)bVar42 << 0x1f | uVar12 & 0x4fffffff | 0x40000000;
          piVar38[3] = uVar24;
          piVar38[4] = uVar31;
          *(char *)((int)piVar38 + 0x1b) = (char)local_20c;
          iVar29 = (uint)*(byte *)(param_2 + 0xe) * 0x24;
          puVar41 = &DAT_001d9f34 + iVar29;
          if ((*(uint *)(&DAT_001d9f4c + iVar29) & 0x10000) == 0) {
            if ((*(uint *)(&DAT_001d9f48 + iVar29) & 8) == 0) {
              uVar12 = *(uint *)(&DAT_001d9f48 + iVar29) & 7;
              if (uVar12 == 1) {
                puVar41 = &DAT_001da00c;
              }
              else if (uVar12 < 2) {
                if (uVar12 == 0) {
                  puVar41 = &DAT_001d9fa0;
                }
                else {
LAB_00032a20:
                  puVar41 = &DAT_001da1bc;
                }
              }
              else {
                if (uVar12 == 2) goto LAB_00032b08;
                if (uVar12 != 3) goto LAB_00032a20;
                puVar41 = &DAT_001da36c;
              }
            }
            else {
LAB_00032b08:
              puVar41 = &DAT_001da054;
            }
          }
          _memcpy(piVar38 + 0x2a0,PTR_DAT_001e899c,0x23c);
          uVar13 = piVar38[0x306];
          uVar15 = piVar38[0x31c];
          piVar38[0x2ab] = 0;
          uVar12 = *(uint *)(puVar41 + 0x18) >> 5 & 0x1f;
          piVar38[0x306] = uVar12 | uVar13 & 0xffffffe0;
          uVar14 = (*(uint *)(puVar41 + 0x18) & 0x18) << 5;
          piVar38[0x306] = uVar14 | uVar12 | uVar13 & 0xfffffce0;
          uVar8 = (*(uint *)(puVar41 + 0x18) & 6) << 9;
          piVar38[0x306] = uVar8 | uVar14 | uVar12 | uVar13 & 0xfffff0e0;
          uVar9 = *(uint *)(puVar41 + 0x1c) >> 0x12 & 0x3000;
          piVar38[0x306] = uVar9 | uVar8 | uVar14 | uVar12 | uVar13 & 0xffffc0e0;
          piVar38[0x306] =
               *(uint *)(puVar41 + 0x1c) >> 0xe & 0xc000 |
               uVar9 | uVar8 | uVar14 | uVar12 | uVar13 & 0xfff000e0;
          uVar12 = *(uint *)(puVar41 + 0x1c) >> 7 & 0x1f;
          piVar38[0x31c] = uVar12 | uVar15 & 0xfffffe00;
          uVar14 = (*(uint *)(puVar41 + 0x1c) & 0x70) << 5;
          piVar38[0x31c] = uVar14 | uVar12 | uVar15 & 0xfffff000;
          uVar8 = (*(uint *)(puVar41 + 0x1c) & 0xe) << 0xb;
          piVar38[0x31c] = uVar8 | uVar14 | uVar12 | uVar15 & 0xffff8000;
          uVar9 = *(uint *)(puVar41 + 0x20) >> 0xe & 0x38000;
          piVar38[0x31c] = uVar9 | uVar8 | uVar14 | uVar12 | uVar15 & 0xfffc0000;
          piVar38[0x31c] =
               *(uint *)(puVar41 + 0x20) >> 8 & 0x1c0000 |
               uVar9 | uVar8 | uVar14 | uVar12 | uVar15 & 0xf8000000;
          piVar18 = piVar21;
          if (bVar42) {
            *piVar21 = (int)((unsigned char *)0x00001393);
            piVar38[0x281] = 10;
            piVar38[0x282] = 0x5c8;
            piVar38[0x283] = 0x20000;
            piVar38[0x284] = 0x575;
            piVar18 = piVar38 + 0x286;
            piVar38[0x285] = local_20c;
          }
          *(short *)(piVar38 + uVar33 * 8 + 0x10) = (short)((int)piVar18 - (int)piVar21 >> 2);
          iVar29 = piVar38[1];
          *(undefined2 *)((int)piVar38 + uVar33 * 0x20 + 0x42) = 1;
          piVar38[uVar33 * 8 + 0x17] = 0;
          piVar38[uVar33 * 8 + 0x11] = uVar25 - (uVar22 & 0xfffff000);
          piVar38[uVar33 * 8 + 0x12] = 0;
          piVar38[uVar33 * 8 + 0x13] = 0;
          piVar38[uVar33 * 8 + 0x14] = 0;
          piVar38[uVar33 * 8 + 0x15] = 0;
          *(short *)(piVar38 + uVar33 * 8 + 0x16) =
               (short)((int)(piVar38 + 0x32f) - (int)piVar21 >> 2) - (short)iVar29;
          iVar29 = (uint)*(byte *)(param_2 + 0xe) * 0x24;
          puVar41 = &DAT_001d9f34 + iVar29;
          if ((*(uint *)(&DAT_001d9f4c + iVar29) & 0x10000) == 0) {
            if ((*(uint *)(&DAT_001d9f48 + iVar29) & 8) == 0) {
              uVar25 = *(uint *)(&DAT_001d9f48 + iVar29) & 7;
              if (uVar25 == 1) {
                puVar41 = &DAT_001da00c;
              }
              else if (uVar25 < 2) {
                if (uVar25 == 0) {
                  puVar41 = &DAT_001d9fa0;
                }
                else {
LAB_00032bf4:
                  puVar41 = &DAT_001da1bc;
                }
              }
              else {
                if (uVar25 == 2) goto LAB_00032c54;
                if (uVar25 != 3) goto LAB_00032bf4;
                puVar41 = &DAT_001da36c;
              }
            }
            else {
LAB_00032c54:
              puVar41 = &DAT_001da054;
            }
          }
          puVar17 = (undefined4 *)
                    ((int (*)())FUN_00030420)(piVar38 + 0x32f,puVar41,uVar31,uVar24,0,
                                 (iVar36 << (local_218 & 0x3f)) >> (*(uint *)(puVar41 + 0x14) & 7),
                                 uVar27);
          if (bVar42) {
            piVar18 = (int *)((int (*)())FUN_00030a60)(piVar18,local_214,uVar31,uVar24,0,0,
                                          uVar27 << 0x10 | (iVar36 << (local_218 & 0x3f)) >> iVar16)
            ;
          }
          *puVar17 = ((unsigned char *)0x00001393);
          puVar17[1] = 10;
          puVar17[2] = 0x5c8;
          puVar17[3] = 0x20000;
          puVar17[4] = ((unsigned char *)0x00001040);
          puVar17[5] = 0;
          if (bVar42) {
            *piVar18 = 0xd0b;
            piVar18[1] = 5;
            piVar18[2] = 0x5c8;
            piVar18[3] = 0x10000;
            piVar28 = piVar18 + 5;
            piVar18[4] = (int)((unsigned char *)0x00001040);
            piVar18 = piVar18 + 6;
            *piVar28 = 0;
          }
          *(uint *)(param_2[0xd] + 0x18) = uVar24 * uVar27;
          *(byte *)(param_2[0xd] + 0x14) = *(byte *)(param_2[0xd] + 0x14) | 2;
          *piVar38 = (int)piVar18 - (int)piVar21 >> 2;
          piVar38[2] = ((int)puVar17 + (0x18 - (int)piVar21) >> 2) - piVar38[1];
        }
        uVar10 = (ushort)(1 << (uVar33 & 0x3f));
        uVar30 = ~uVar10;
        *(byte *)(param_2[0xd] + 0x14) = *(byte *)(param_2[0xd] + 0x14) | 1;
        *(ushort *)(param_2[0xd] + 0x1c) = uVar10 | *(ushort *)(param_2[0xd] + 0x1c);
        *(ushort *)(param_2[0xd] + 0x28) = uVar30 & *(ushort *)(param_2[0xd] + 0x28);
        *(byte *)(param_2[0xd] + 0x17) = bVar44;
        *(undefined1 *)(param_2[0xd] + 0x34) = 1;
        *(undefined1 *)(param_2[0xd] + 0x35) = 1;
      }
      *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) & 0xf8;
      *(ushort *)(param_2 + 9) = uVar30 & *(ushort *)(param_2 + 9);
    }
    else {
LAB_00034128:
      if (*(char *)((int)puVar35 + 0x6d) == '\0') {
        iVar16 = ((int (*)())FUN_00030b50)(param_2);
        if (iVar16 == 0) {
          local_74 = param_2[0xc];
          local_78 = (uint)*(byte *)(local_74 + 0x6c);
          local_7c = (uint)*(byte *)(local_74 + 0x69);
          local_80 = (uint)*(byte *)(local_74 + 0x6b);
          uVar30 = *(ushort *)(local_74 + 2);
          local_134 = 0;
          if (0x1908 < uVar30) {
            local_134 = 0;
            if (0x190a < uVar30) {
              local_134 = 0;
              if (uVar30 != 0x8049) goto LAB_00032e78;
              local_134 = 0x4000;
            }
            local_134 = local_134 | 0x2000;
          }
LAB_00032e78:
          local_64 = &local_158;
          local_138 = 2;
          ((int (*)())FUN_00031170)(*(undefined1 *)(param_2 + 0xe),param_2,local_64,&local_214,&local_208,
                       &local_204,&local_218,&local_210);
          iVar16 = (uint)*(byte *)(param_2 + 0xe) * 0x24;
          puVar41 = &DAT_001d9f34 + iVar16;
          uVar27 = *(uint *)(&DAT_001d9f48 + iVar16) & 7;
          if (uVar27 == 4) {
            iVar29 = 0;
            bVar42 = false;
            local_a4 = 0;
            local_c0 = 5;
            local_60 = (uint)(in_xer_so & 1 | 2) << 0x1c | (uint)(in_cr1 & 0xf) << 0x18 |
                       (uint)(unaff_cr2 & 0xf) << 0x14 | (uint)(unaff_cr3 & 0xf) << 0x10 |
                       (uint)(unaff_cr4 & 0xf) << 0xc | (uint)(in_cr5 & 0xf) << 8 |
                       (uint)(bVar44 & 0xf) << 4 |
                       (uint)(byte)((uVar27 < 4) << 3 | (4 < uVar27) << 2 | (uVar27 == 4) << 1 |
                                   in_xer_so & 1);
LAB_00032f74:
            iVar16 = 0;
          }
          else {
            local_a4 = *(uint *)(&DAT_001d9f4c + iVar16) >> 0x1c & 3;
            bVar19 = (local_a4 != 0) << 2 | (local_a4 == 0) << 1 | in_xer_so & 1;
            bVar42 = local_a4 != 0;
            if (bVar42) {
              local_c0 = 5 - local_a4;
              local_60 = (uint)(in_xer_so & 1 | 4) << 0x1c | (uint)(in_cr1 & 0xf) << 0x18 |
                         (uint)(unaff_cr2 & 0xf) << 0x14 | (uint)(unaff_cr3 & 0xf) << 0x10 |
                         (uint)(unaff_cr4 & 0xf) << 0xc | (uint)(in_cr5 & 0xf) << 8 |
                         (uint)(bVar44 & 0xf) << 4 | (uint)bVar19;
            }
            else {
              local_c0 = 5;
              local_60 = (uint)(in_xer_so & 1 | 4) << 0x1c | (uint)(in_cr1 & 0xf) << 0x18 |
                         (uint)(unaff_cr2 & 0xf) << 0x14 | (uint)(unaff_cr3 & 0xf) << 0x10 |
                         (uint)(unaff_cr4 & 0xf) << 0xc | (uint)(in_cr5 & 0xf) << 8 |
                         (uint)(bVar44 & 0xf) << 4 | (uint)bVar19;
            }
            iVar29 = 1;
            bVar42 = !bVar42;
            if (((*(uint *)(&DAT_001d9f4c + iVar16) & 0x30000000) != 0x20000000) ||
               (iVar16 = 1, uVar27 != 1)) goto LAB_00032f74;
          }
          uVar31 = *(byte *)(local_74 + 0x62) - local_7c;
          uVar27 = uVar31;
          if ((int)uVar31 < 0) {
            uVar27 = 0;
          }
          iVar36 = *(byte *)(local_74 + 0x60) - local_7c;
          if (iVar36 < 0) {
            iVar36 = 0;
          }
          uVar25 = iVar36 - local_208;
          if ((int)uVar25 < 0) {
            uVar25 = 0;
          }
          iVar36 = *(byte *)(local_74 + 0x61) - local_7c;
          if (iVar36 < 0) {
            iVar36 = 0;
          }
          uVar33 = iVar36 - local_204;
          if ((int)uVar33 < 0) {
            uVar33 = 0;
          }
          bVar19 = (local_80 < local_7c) << 3 | (local_7c < local_80) << 2 |
                   (local_80 == local_7c) << 1 | in_xer_so & 1;
          bVar43 = (uint)((1 << (uVar25 & 0x3f)) << (local_214 & 0x3f)) <=
                   *(uint *)(iStack00000018 + 0x29d8);
          uVar22 = local_7c;
          local_a0 = uVar27;
          local_9c = uVar33;
          local_98 = uVar25;
          if (local_80 < local_7c) {
            iVar32 = 0;
            iVar40 = 0;
            iVar26 = 0;
            iVar36 = 0;
            local_88[0] = 0;
          }
          else {
            iVar32 = 0;
            iVar40 = 0;
            iVar36 = local_a4 + 3;
            uVar24 = local_c0 + 3;
            piVar21 = aiStack_1c8 + local_7c;
            piVar38 = aiStack_200 + local_7c;
            local_88[0] = 0;
            do {
              uVar14 = local_214 + uVar25;
              *piVar38 = iVar40;
              *piVar21 = iVar32;
              iVar26 = 1 << (uVar27 & 0x3f);
              uVar12 = uVar14;
              if ((int)uVar14 < 5) {
                uVar12 = 5;
              }
              iVar40 = iVar40 + iVar26 * (1 << (uVar12 & 0x3f)) * (1 << (uVar33 & 0x3f));
              uVar12 = local_c0;
              if ((int)local_c0 < (int)uVar14) {
                uVar12 = uVar14;
              }
              uVar14 = 1 << (uVar12 & 0x3f);
              uVar12 = uVar33;
              if ((int)uVar33 < (int)local_a4) {
                uVar12 = local_a4;
              }
              uVar12 = 1 << (uVar12 & 0x3f);
              iVar32 = iVar32 + iVar26 * uVar14 * uVar12;
              if ((uVar14 < (uint)(1 << (uVar24 & 0x3f))) || (uVar12 < (uint)(1 << iVar36))) {
                local_88[0] = local_88[0] & ~(1 << (uVar22 & 0x3f));
              }
              else {
                local_88[0] = local_88[0] | 1 << (uVar22 & 0x3f);
              }
              if (0 < (int)uVar25) {
                uVar25 = uVar25 - 1;
              }
              if (0 < (int)uVar33) {
                uVar33 = uVar33 - 1;
              }
              if (0 < (int)uVar27) {
                uVar27 = uVar27 - 1;
              }
              uVar22 = uVar22 + 1;
              piVar38 = piVar38 + 1;
              piVar21 = piVar21 + 1;
              bVar19 = (local_80 < uVar22) << 3 | (uVar22 < local_80) << 2 |
                       (local_80 == uVar22) << 1 | in_xer_so & 1;
            } while (local_80 >= uVar22);
            iVar26 = local_78 * iVar40;
            iVar36 = local_78 * iVar32;
          }
          uVar27 = 0;
          local_6c = (uint)(byte)(bVar43 << 2 | !bVar43 << 1 | in_xer_so & 1) << 0x1c |
                     (uint)(in_cr1 & 0xf) << 0x18 | (uint)(unaff_cr2 & 0xf) << 0x14 |
                     (uint)(unaff_cr3 & 0xf) << 0x10 | (uint)(unaff_cr4 & 0xf) << 0xc |
                     (uint)(in_cr5 & 0xf) << 8 | (uint)(bVar44 & 0xf) << 4 | (uint)bVar19;
          aiStack_1c8[uVar22] = iVar32;
          aiStack_200[uVar22] = iVar40;
          if (bVar43) {
            uVar27 = 0x15;
            if (local_7c <= local_80) {
              iVar32 = 0;
              uVar27 = uVar31;
              uVar25 = local_7c;
              do {
                uVar33 = uVar27;
                if ((int)uVar27 < 0) {
                  uVar33 = 0;
                }
                uVar25 = uVar25 + 1;
                uVar27 = uVar27 - 1;
                iVar32 = iVar32 + (local_78 * 0x12 << (uVar33 & 0x3f));
              } while (uVar25 <= local_80);
              uVar27 = iVar32 + 0x15;
            }
            uVar27 = uVar27 & 0xfffffff8;
          }
          uVar25 = 0x98;
          if (local_7c <= local_80) {
            iVar32 = 0x91;
            uVar25 = local_7c;
            do {
              uVar33 = uVar31;
              if ((int)uVar31 < 0) {
                uVar33 = 0;
              }
              uVar25 = uVar25 + 1;
              uVar31 = uVar31 - 1;
              iVar32 = iVar32 + (local_78 * 0x2a << (uVar33 & 0x3f));
            } while (uVar25 <= local_80);
            uVar25 = iVar32 + 7;
          }
          iVar36 = FUN_0000acb0(iStack00000018,param_2,
                                iVar26 + uVar27 * 4 + (uVar25 & 0xfffffff8) * 4,iVar36);
          if (iVar36 == 0) {
            return 0;
          }
          *(byte *)(param_2[0xd] + 0x15) = (byte)((iVar29 << iVar16) << 3) & 0x18 | 4;
          local_84 = (int *)*param_2;
          if ((*(byte *)((int)param_2 + 0x39) & 3) == 0) {
            local_8c = (int *)0x0;
            local_e8 = (int *)0x0;
          }
          else {
            *(char *)(param_2[0xd] + 0x17) = (char)local_7c;
            uVar33 = 1 << (local_98 & 0x3f);
            *(char *)(param_2[0xd] + 0x34) = (char)local_78;
            *(char *)(param_2[0xd] + 0x35) = ((char)local_80 - (char)local_7c) + '\x01';
            uVar31 = local_84[8];
            local_84[2] = 0;
            local_84[1] = uVar27;
            *local_84 = 0;
            local_84[8] = (uint)bVar43 << 0x1f | uVar31 & 0x6fffffff | 0x40000000;
            *(char *)((int)local_84 + 0x1a) = (char)local_214;
            *(short *)((int)local_84 + 0x16) = (short)(1 << (local_9c & 0x3f));
            *(short *)(local_84 + 6) = (short)(1 << (local_a0 & 0x3f));
            *(short *)(local_84 + 5) = (short)uVar33;
            *(char *)((int)local_84 + 0x1b) = (char)local_20c;
            uVar33 = (uVar33 & 0xffff) << (local_214 & 0x3f);
            local_84[3] = uVar33;
            if (uVar33 >> (local_c0 & 0x3f) == 0) {
              local_84[3] = 1 << (local_c0 & 0x3f);
            }
            uVar33 = (uint)*(ushort *)(local_84 + 5) << (local_214 & 0x3f);
            local_84[4] = uVar33;
            if (uVar33 >> 5 == 0) {
              local_84[4] = 0x20;
            }
            puVar41 = PTR_DAT_001e899c;
            local_84[8] = (uint)bVar43 << 0x1f | uVar31 & 0x4fffffff | 0x40000000;
            local_8c = local_84 + 0x280;
            piVar21 = local_8c + local_84[1];
            local_e8 = piVar21 + 0x8f;
            _memcpy(piVar21,puVar41,0x23c);
            iVar29 = (uint)*(byte *)(param_2 + 0xe) * 0x24;
            puVar41 = &DAT_001d9f34 + iVar29;
            if ((*(uint *)(&DAT_001d9f4c + iVar29) & 0x10000) == 0) {
              if ((*(uint *)(&DAT_001d9f48 + iVar29) & 8) == 0) {
                uVar31 = *(uint *)(&DAT_001d9f48 + iVar29) & 7;
                if (uVar31 == 1) {
                  puVar41 = &DAT_001da00c;
                }
                else if (uVar31 < 2) {
                  if (uVar31 == 0) {
                    puVar41 = &DAT_001d9fa0;
                  }
                  else {
LAB_000333f4:
                    puVar41 = &DAT_001da1bc;
                  }
                }
                else {
                  if (uVar31 == 2) goto LAB_000334dc;
                  if (uVar31 != 3) goto LAB_000333f4;
                  puVar41 = &DAT_001da36c;
                }
              }
              else {
LAB_000334dc:
                puVar41 = &DAT_001da054;
              }
            }
            uVar12 = piVar21[0x66];
            uVar14 = piVar21[0x7c];
            piVar21[0xb] = 0;
            uVar31 = *(uint *)(puVar41 + 0x18) >> 5 & 0x1f;
            piVar21[0x66] = uVar31 | uVar12 & 0xffffffe0;
            uVar33 = (*(uint *)(puVar41 + 0x18) & 0x18) << 5;
            piVar21[0x66] = uVar33 | uVar31 | uVar12 & 0xfffffce0;
            uVar22 = (*(uint *)(puVar41 + 0x18) & 6) << 9;
            piVar21[0x66] = uVar22 | uVar33 | uVar31 | uVar12 & 0xfffff0e0;
            uVar24 = *(uint *)(puVar41 + 0x1c) >> 0x12 & 0x3000;
            piVar21[0x66] = uVar24 | uVar22 | uVar33 | uVar31 | uVar12 & 0xffffc0e0;
            piVar21[0x66] =
                 *(uint *)(puVar41 + 0x1c) >> 0xe & 0xc000 |
                 uVar24 | uVar22 | uVar33 | uVar31 | uVar12 & 0xfff000e0;
            uVar31 = *(uint *)(puVar41 + 0x1c) >> 7 & 0x1f;
            piVar21[0x7c] = uVar31 | uVar14 & 0xfffffe00;
            uVar33 = (*(uint *)(puVar41 + 0x1c) & 0x70) << 5;
            piVar21[0x7c] = uVar33 | uVar31 | uVar14 & 0xfffff000;
            uVar22 = (*(uint *)(puVar41 + 0x1c) & 0xe) << 0xb;
            piVar21[0x7c] = uVar22 | uVar33 | uVar31 | uVar14 & 0xffff8000;
            uVar24 = *(uint *)(puVar41 + 0x20) >> 0xe & 0x38000;
            piVar21[0x7c] = uVar24 | uVar22 | uVar33 | uVar31 | uVar14 & 0xfffc0000;
            uVar12 = *(uint *)(puVar41 + 0x20) >> 8 & 0x1c0000;
            piVar21[0x7c] = uVar12 | uVar24 | uVar22 | uVar33 | uVar31 | uVar14 & 0xffc00000;
            piVar21[0x7c] =
                 (*(uint *)(puVar41 + 0x20) >> 0x19 & 1) << 0x16 |
                 uVar12 | uVar24 | uVar22 | uVar33 | uVar31 | uVar14 & 0xf8000000;
            if (!(bool)((byte)(local_6c >> 0x1d) & 1)) {
              *local_8c = (int)((unsigned char *)0x00001393);
              local_8c[1] = 10;
              local_8c[2] = 0x5c8;
              piVar21 = local_8c + 5;
              local_8c[3] = 0x20000;
              local_8c[4] = 0x575;
              local_8c = local_8c + 6;
              *piVar21 = local_20c;
            }
          }
          bVar19 = ((int)local_78 < 0) << 3 | (0 < (int)local_78) << 2 | (local_78 == 0) << 1 |
                   in_xer_so & 1;
          if (local_78 != 0) {
            local_90 = (void *)0x0;
            local_dc = param_2;
            local_58 = iVar16 << 1;
            local_94 = 0;
            local_e4 = local_7c * 0x18;
            local_54 = (uint)(byte)(bVar42 << 2 | !bVar42 << 1 | in_xer_so & 1) << 0x1c |
                       (uint)(in_cr1 & 0xf) << 0x18 | (uint)(unaff_cr2 & 0xf) << 0x14 |
                       (uint)(unaff_cr3 & 0xf) << 0x10 | (uint)(unaff_cr4 & 0xf) << 0xc |
                       (uint)(in_cr5 & 0xf) << 8 | (uint)(bVar44 & 0xf) << 4 | (uint)bVar19;
            local_c4 = (uVar27 + (uVar25 & 0xfffffff8)) * 4;
            local_e0 = local_7c << 5;
            local_68 = (uint)(in_xer_so & 1 | 2) << 0x1c | (uint)(in_cr1 & 0xf) << 0x18 |
                       (uint)(unaff_cr2 & 0xf) << 0x14 | (uint)(unaff_cr3 & 0xf) << 0x10 |
                       (uint)(unaff_cr4 & 0xf) << 0xc | (uint)(in_cr5 & 0xf) << 8 |
                       (uint)(bVar44 & 0xf) << 4 | (uint)bVar19;
            local_5c = local_84 + 0x10;
            local_d8 = local_74;
            do {
              local_a8 = (uint)*(ushort *)(local_d8 + 0x7c);
              if (local_7c <= local_80) {
                piVar21 = aiStack_200 + local_7c;
                local_c8 = local_e0;
                local_d0 = local_e0;
                local_d4 = aiStack_1c8 + local_7c;
                local_70 = 0x80e1;
                local_cc = local_e4;
                uVar27 = local_98;
                uVar31 = local_a0;
                uVar25 = local_9c;
                uVar33 = local_7c;
                do {
                  uVar24 = uVar27 + local_214;
                  uVar22 = uVar24;
                  if ((int)uVar24 < 5) {
                    uVar22 = 5;
                  }
                  iVar16 = 1 << (uVar22 & 0x3f);
                  local_b0 = 1;
                  bVar42 = 3 < *(byte *)(param_2 + 0xe) - 0xc;
                  local_ac = *piVar21 * local_78 + local_94 * (piVar21[1] - *piVar21) + local_c4 +
                             0xa00;
                  if (bVar42) {
                    local_b0 = 0;
                  }
                  local_b0 = (uint)!bVar42;
                  if ((*(byte *)((int)param_2 + 0x39) & 3) == 0) {
                    bVar19 = ((int)uVar31 < 0) << 3 | (0 < (int)uVar31) << 2 | (uVar31 == 0) << 1 |
                             in_xer_so & 1;
                    local_a8 = local_a8 & *(ushort *)(local_dc + 9);
                  }
                  else {
                    bVar19 = ((int)uVar31 < 0) << 3 | (0 < (int)uVar31) << 2 | (uVar31 == 0) << 1 |
                             in_xer_so & 1;
                    uVar12 = uVar31;
                    uVar22 = uVar25;
                    if ((((uVar25 != local_a4 + 3) && (local_a4 <= uVar25)) &&
                        (bVar19 = ((int)uVar31 < 0) << 3 | (0 < (int)uVar31) << 2 |
                                  (uVar31 == 0) << 1 | in_xer_so & 1, uVar31 != 0)) &&
                       (uVar14 = uVar31, uVar25 < 0xb)) {
                      do {
                        uVar12 = uVar12 - 1;
                        uVar22 = uVar22 + 1;
                        if (uVar14 - 1 == 0) goto LAB_00033700;
                        uVar14 = uVar14 - 1;
                      } while (uVar22 != 0xb);
                      uVar22 = 0xb;
                    }
LAB_00033700:
                    if ((int)uVar24 < (int)local_c0) {
                      uVar24 = local_c0;
                    }
                    iVar32 = 1 << (uVar24 & 0x3f);
                    *(short *)(local_d0 + (int)local_5c) =
                         (short)((int)local_8c - (int)(local_84 + 0x280) >> 2);
                    iVar29 = local_84[1];
                    *(int *)((int)local_5c + local_d0 + 4) = local_ac;
                    *(short *)((int)local_5c + local_d0 + 0x18) =
                         (short)((int)local_e8 - (int)(local_84 + 0x280) >> 2) - (short)iVar29;
                    iVar36 = *local_d4;
                    iVar29 = local_d4[1];
                    *(short *)((int)local_5c + local_d0 + 2) = (short)(1 << (uVar12 & 0x3f));
                    *(int *)((int)local_5c + local_d0 + 0xc) = iVar16 << (uVar22 & 0x3f);
                    *(uint *)((int)local_5c + local_d0 + 8) =
                         local_78 * iVar36 + local_94 * (iVar29 - iVar36);
                    uVar24 = uVar22;
                    if ((int)uVar22 < (int)local_a4) {
                      uVar24 = local_a4;
                    }
                    *(int *)((int)local_5c + local_d0 + 0x10) = (1 << (uVar24 & 0x3f)) * iVar32;
                    uVar24 = uVar25;
                    if ((int)uVar25 < (int)local_a4) {
                      uVar24 = local_a4;
                    }
                    *(int *)((int)local_5c + local_d0 + 0x14) = iVar32 << (uVar24 & 0x3f);
                    *(int *)((int)local_5c + local_d0 + 0x1c) = (int)local_84 + local_ac;
                    if ((local_210 < 3) ||
                       ((iVar29 = 1, 4 < local_210 && (iVar29 = 2, local_210 != 6)))) {
                      iVar29 = 0;
                    }
                    uVar24 = 1 << (uVar12 & 0x3f);
                    if (uVar24 != 0) {
                      iVar36 = 1 << (uVar22 & 0x3f);
                      iVar40 = 1 << (uVar27 & 0x3f);
                      uVar12 = 0;
                      uVar22 = local_88[0] >> (uVar33 & 0x3f);
                      do {
                        if (((bool)((byte)(local_60 >> 0x1d) & 1)) ||
                           (!(bool)((byte)(local_54 >> 0x1d) & 1))) {
                          uVar14 = 0;
                        }
                        else {
                          uVar14 = 1;
                        }
                        uVar14 = (uVar14 | local_58) << 1 | uVar22 & 1;
                        local_e8 = (int *)((int (*)())FUN_00030420)(local_e8,puVar41,iVar16,iVar32,uVar14,
                                                       (iVar40 << (local_214 & 0x3f)) >>
                                                       (*(uint *)(puVar41 + 0x14) & 7),iVar36);
                        if (!(bool)((byte)(local_6c >> 0x1d) & 1)) {
                          local_8c = (int *)((int (*)())FUN_00030a60)(local_8c,local_210,iVar16,iVar32,uVar14,0,
                                                         iVar36 << 0x10 |
                                                         (iVar40 << (local_214 & 0x3f)) >> iVar29);
                        }
                        uVar12 = uVar12 + 1;
                      } while (uVar12 < uVar24);
                    }
                  }
                  if ((local_a8 >> (uVar33 & 0x3f) & 1) != 0) {
                    iVar36 = local_cc + local_74 + 0xa0;
                    sVar5 = *(short *)(iVar36 + 0x12);
                    iVar29 = FUN_0000a3f0(*(undefined2 *)(iVar36 + 0x10),sVar5);
                    uVar22 = (uint)*(ushort *)(iVar36 + 0xc);
                    bVar42 = sVar5 != 0;
                    bVar20 = in_xer_so & 1;
                    local_158 = *(void **)(iVar36 + 0x14);
                    local_154 = iVar29 * uVar22;
                    if ((*(char *)(iVar36 + 10) != '\0') && (bVar42)) {
                      iVar32 = 1;
                      if ((*(char *)(local_74 + 0x6e) != '\0') &&
                         (iVar32 = uVar22 + 1, *(char *)(local_74 + 0x6f) != '\0')) {
                        iVar32 = iVar32 + uVar22 * *(ushort *)(iVar36 + 0xe);
                      }
                      local_158 = (void *)((int)local_158 + iVar29 * iVar32);
                    }
                    uVar22 = *(byte *)(local_74 + 0x60) - uVar33;
                    if ((int)uVar22 < 0) {
                      uVar22 = 0;
                    }
                    local_12c = 1 << (uVar22 & 0x3f);
                    iVar29 = *(byte *)(local_74 + 0x61) - uVar33;
                    if (iVar29 < 0) {
                      iVar29 = 0;
                    }
                    iVar32 = *(byte *)(local_74 + 0x62) - uVar33;
                    if (iVar32 < 0) {
                      iVar32 = 0;
                    }
                    local_128 = 1 << (iVar29 + iVar32 & 0x3fU);
                    bVar43 = (int)local_b0 < 0;
                    bVar1 = 0 < (int)local_b0;
                    bVar2 = local_b0 == 0;
                    bVar3 = in_xer_so & 1;
                    _glgConvertType(*(undefined2 *)(iVar36 + 0x10),*(undefined2 *)(iVar36 + 0x12),
                                    auStack_150,auStack_14c);
                    local_144 = iVar16;
                    if (!bVar2) {
                      local_144 = local_12c << 2;
                    }
                    local_148 = (void *)(local_ac + *param_2);
                    local_130 = (undefined *)0x7ffff;
                    uVar30 = *(short *)(iVar36 + 0x10) + 0xe6fa;
                    bVar45 = (uVar30 < 4) << 3 | (4 < uVar30) << 2 | (uVar30 == 4) << 1 |
                             in_xer_so & 1;
                    if ((4 >= uVar30) && ((1 << ((int)(short)uVar30 & 0x3fU) & 0x19U) != 0)) {
                      local_130 = ((unsigned char *)0x0007dfff);
                    }
                    local_120 = 0;
                    local_124 = 0;
                    if (((bVar42) && (!bVar2)) && ((bool)((byte)(local_68 >> 0x1d) & 1))) {
                      local_90 = _valloc(((1 << (*(byte *)(local_74 + 100) + 2 & 0x3f)) + 0x1fU &
                                         0xffffffe0) <<
                                         ((uint)*(byte *)(local_74 + 0x66) +
                                          (uint)*(byte *)(local_74 + 0x65) & 0x3f));
                      local_68 = (uint)(byte)(((int)local_90 < 0) << 3 | (0 < (int)local_90) << 2 |
                                              (local_90 == (void *)0x0) << 1 | in_xer_so & 1) <<
                                 0x1c | (uint)(in_cr1 & 0xf) << 0x18 | (uint)bVar19 << 0x14 |
                                 (uint)(byte)((sVar5 == 0) << 2 | bVar42 << 1 | bVar20) << 0x10 |
                                 (uint)(byte)(bVar43 << 3 | bVar1 << 2 | bVar2 << 1 | bVar3) << 0xc
                                 | (uint)(in_cr5 & 0xf) << 8 | (uint)(bVar44 & 0xf) << 4 |
                                 (uint)(bVar45 & 0xf);
                    }
                    uVar6 = *(undefined2 *)(iVar36 + 0x10);
                    uVar7 = *(undefined2 *)(iVar36 + 0x12);
                    sVar37 = 1 << (uVar31 + uVar27 + uVar25 + local_214 & 0x3f);
                    bVar20 = ((int (*)())FUN_0002f4d0)(uVar6,uVar7,*(undefined1 *)(param_2 + 0xe));
                    iVar16 = FUN_0000a3f0(uVar6,uVar7);
                    if ((((local_154 == iVar16 * local_12c & bVar20) == 0) ||
                        (((uint)local_158 & 0x1f) != 0)) || ((local_154 & 0x1f) != 0)) {
                      if (bVar42) {
                        if (bVar2) {
                          _glgProcessPixels(0,local_64);
                        }
                        else {
                          uVar22 = (uint)*(ushort *)(iVar36 + 0x10);
                          local_b4 = local_148;
                          if (((local_12c != *(ushort *)(iVar36 + 0xc)) ||
                              ((*(short *)(iVar36 + 0x12) != 0x1401 &&
                               (*(short *)(iVar36 + 0x12) != -0x7fcb)))) ||
                             ((pvVar34 = local_158, 1 < uVar22 - 0x1907 &&
                              ((uVar22 != local_70 && (uVar22 != 0x80e0)))))) {
                            local_148 = local_90;
                            _glgProcessPixels(0,local_64);
                            uVar22 = 0x1908;
                            local_148 = local_b4;
                            pvVar34 = local_90;
                          }
                          uVar24 = local_12c;
                          local_148 = local_b4;
                          if (*(char *)(param_2 + 0xe) == '\x0f') {
                            bVar42 = uVar22 == 0x1908;
                            bVar44 = (uVar22 < 0x1908) << 3 | (0x1908 < uVar22) << 2 | bVar42 << 1 |
                                     in_xer_so & 1;
                            local_b8[0] = local_128;
                            if ((bVar42) || (iVar16 = 3, uVar22 == local_70)) {
                              iVar16 = 4;
                            }
                            iVar29 = iVar16 * local_12c;
                            if ((bVar42) || (local_bc = 0, uVar22 == local_70)) {
                              local_bc = 3;
                            }
                            if (0 < (int)local_128) {
                              bVar42 = 0 < (int)local_12c;
                              iVar36 = 0;
                              do {
                                if (bVar42) {
                                  iVar32 = 0;
                                  pvVar39 = (void *)((int)local_b4 + iVar36 * uVar24);
                                  do {
                                    iVar26 = iVar16 * iVar32;
                                    iVar32 = iVar32 + 4;
                                    iVar26 = iVar26 + iVar36 * iVar29;
                                    ((int (*)())FUN_000305b0)(pvVar39,(int)pvVar34 + local_bc + iVar26,iVar16,
                                                 iVar29);
                                    iVar40 = (int)pvVar39 + 8;
                                    pvVar39 = (void *)((int)pvVar39 + 0x10);
                                    ((int (*)())FUN_000305b0)(iVar40,(int)pvVar34 +
                                                        (uint)(1 < uVar22 - 0x1907) * 2 + iVar26,
                                                 iVar16,iVar29);
                                  } while (iVar32 < (int)uVar24);
                                }
                                iVar36 = iVar36 + 4;
                              } while (iVar36 < (int)local_b8[0]);
                            }
                          }
                          else {
                            FUN_0001c380(local_12c,local_128,uVar22,*(char *)(param_2 + 0xe),pvVar34
                                         ,local_b4);
                          }
                        }
                      }
                      else if (!bVar2) {
                        uVar22 = ((int (*)())FUN_000303d0)(*(undefined1 *)(param_2 + 0xe),local_12c,1,1);
                        if (uVar22 < 0x20) {
                          if (local_128 != 0) {
                            uVar24 = 0;
                            pvVar34 = local_158;
                            pvVar39 = local_148;
                            do {
                              uVar24 = uVar24 + 4;
                              pvVar11 = (void *)((int)pvVar39 + 0x1fU & 0xffffffe0);
                              pvVar39 = (void *)((int)pvVar11 + uVar22);
                              _memcpy(pvVar11,pvVar34,uVar22);
                              pvVar34 = (void *)((int)pvVar34 + uVar22);
                            } while (uVar24 < local_128);
                          }
                        }
                        else {
                          _memcpy(local_148,local_158,sVar37);
                        }
                      }
                    }
                    else {
                      _memcpy(local_148,local_158,sVar37);
                    }
                    if ((*(uint *)(iStack00000018 + 0x24) & 0x82) != 0) {
                      FUN_0000b620(iStack00000018,local_ac + *param_2,
                                   (uint)*(ushort *)((int)local_5c + local_c8 + 2) *
                                   *(int *)((int)local_5c + local_c8 + 0xc));
                    }
                  }
                  if (0 < (int)uVar27) {
                    uVar27 = uVar27 - 1;
                  }
                  if (0 < (int)uVar25) {
                    uVar25 = uVar25 - 1;
                  }
                  if ((bool)(bVar19 >> 2 & 1)) {
                    uVar31 = uVar31 - 1;
                  }
                  uVar33 = uVar33 + 1;
                  piVar21 = piVar21 + 1;
                  local_c8 = local_c8 + 0x20;
                  local_cc = local_cc + 0x18;
                  local_d0 = local_d0 + 0x20;
                  local_d4 = local_d4 + 1;
                } while (uVar33 <= local_80);
              }
              iVar16 = local_94 * 2;
              local_94 = local_94 + 1;
              uVar30 = ~(ushort)local_a8;
              iVar29 = iVar16 + param_2[0xd];
              local_d8 = local_d8 + 2;
              local_e0 = local_e0 + 0x1a0;
              local_e4 = local_e4 + 0x168;
              *(ushort *)(iVar29 + 0x1c) = (ushort)local_a8 | *(ushort *)(iVar29 + 0x1c);
              iVar16 = iVar16 + param_2[0xd];
              *(ushort *)(iVar16 + 0x28) = uVar30 & *(ushort *)(iVar16 + 0x28);
              *(ushort *)(local_dc + 9) = uVar30 & *(ushort *)(local_dc + 9);
              local_dc = (int *)((int)local_dc + 2);
            } while (local_94 < local_78);
            if (!(bool)((byte)(local_68 >> 0x1d) & 1)) {
              _free(local_90);
            }
          }
          bVar44 = *(byte *)((int)param_2 + 0x39);
          if ((bVar44 & 3) != 0) {
            *local_e8 = (int)((unsigned char *)0x00001393);
            local_e8[1] = 10;
            local_e8[2] = 0x5c8;
            local_e8[3] = 0x20000;
            local_e8[4] = (int)((unsigned char *)0x00001040);
            local_e8[5] = 0;
            if (!(bool)((byte)(local_6c >> 0x1d) & 1)) {
              *local_8c = 0xd0b;
              local_8c[1] = 5;
              local_8c[2] = 0x5c8;
              local_8c[3] = 0x10000;
              piVar21 = local_8c + 5;
              local_8c[4] = (int)((unsigned char *)0x00001040);
              local_8c = local_8c + 6;
              *piVar21 = 0;
            }
            *local_84 = (int)local_8c - (int)(local_84 + 0x280) >> 2;
            local_84[2] = ((int)local_e8 + (0x18 - (int)(local_84 + 0x280)) >> 2) - local_84[1];
            bVar44 = *(byte *)((int)param_2 + 0x39);
          }
          *(byte *)((int)param_2 + 0x39) = bVar44 & 0xf8;
          goto LAB_00033ff0;
        }
        if (*(char *)(param_2 + 0x11) != '\0') {
          return 0;
        }
      }
      iVar16 = ((int (*)())FUN_00031940)(iStack00000018,param_2);
      if (iVar16 == 0) {
        return 0;
      }
    }
  }
  else {
    uVar30 = puVar35[6];
    if (uVar30 == 0x405) {
LAB_000324ac:
      uVar23 = 0;
    }
    else if (uVar30 < 0x406) {
      if (uVar30 == 0x402) goto LAB_000324ac;
      uVar23 = 2;
      if ((uVar30 != 0x403) && (uVar23 = 3, uVar30 != 0x401)) {
LAB_00032480:
        uVar23 = 1;
      }
    }
    else {
      uVar23 = 8;
      if ((uVar30 != 0x40a) && (uVar23 = 0x11, uVar30 != 0x1100)) {
        if (uVar30 != 0x409) goto LAB_00032480;
        uVar23 = 7;
      }
    }
    iVar16 = FUN_0000b3a0(iStack00000018,param_2,*(undefined4 *)(puVar35 + 4),uVar23,
                          *(undefined1 *)(puVar35 + 0x36));
    if (iVar16 == 0) {
      return 0;
    }
    if (*(char *)((int)puVar35 + 0x6d) == '\0') {
      uVar27 = (uint)puVar35[0x52];
      if ((0x20 < uVar27) || (0x20 < puVar35[0x53])) goto LAB_00032600;
    }
    else {
      uVar27 = (uint)puVar35[0x52];
    }
    uVar31 = 1 << (*(uint *)(&DAT_001d9f48 + (uint)*(byte *)(param_2 + 0xe) * 0x24) & 7);
    *(short *)((int)param_2 + 0x3e) =
         (short)((uVar31 * (uVar27 + (uint)*(byte *)(puVar35 + 0x55) * -2) + 0xff & 0xffffff00) /
                uVar31);
LAB_00032600:
    *(byte *)((int)param_2 + 0x39) = *(byte *)((int)param_2 + 0x39) & 0xf8;
  }
LAB_00033ff0:
  if (*(char *)((int)puVar35 + 0x6d) != '\0') {
    if (0x1000 < puVar35[0x52]) {
      if (0x1000 < puVar35[0x53]) {
        return 0;
      }
      param_2[0x32] = param_2[0x32] & 0xff3fffffU | 0x400000;
      uVar30 = puVar35[0x52];
      uVar27 = uVar30 >> 1 & 0x7e00;
      sVar5 = (short)uVar27;
      *(short *)(param_2 + 0x35) = sVar5;
      *(ushort *)((int)param_2 + 0xd2) = uVar30 - sVar5;
      *(short *)(param_2 + 0x34) = sVar5 + 2;
      param_2[0x33] = uVar27 << 2 | param_2[0x33] & 3U;
      goto LAB_00034100;
    }
    if (0x1000 < puVar35[0x53]) {
      param_2[0x32] = param_2[0x32] & 0xff3fffffU | 0x800000;
      uVar30 = puVar35[0x53];
      uVar27 = uVar30 >> 1 & 0x7fc0;
      sVar5 = (short)uVar27;
      *(short *)(param_2 + 0x35) = sVar5;
      *(ushort *)((int)param_2 + 0xd2) = uVar30 - sVar5;
      *(short *)(param_2 + 0x34) = sVar5 + 1;
      if ((*(ushort *)param_2[0xc] & 0x400) == 0) {
        param_2[0x33] =
             ((*(ushort *)((int)param_2 + 0x3e) * uVar27 <<
              (*(uint *)(&DAT_001d9f48 + (uint)*(byte *)(param_2 + 0xe) * 0x24) & 7)) >> 5) << 2 |
             param_2[0x33] & 3U;
      }
      else {
        param_2[0x33] = uVar27 << 2 | param_2[0x33] & 3U;
      }
      goto LAB_00034100;
    }
  }
  param_2[0x32] = param_2[0x32] & 0xff3fffff;
LAB_00034100:
  ((int (*)())FUN_0002ddf0)(iStack00000018,param_2);
  return 1;
}

/* FUN_000341a0 @ 0x341a0 (92 bytes) */
int FUN_000341a0(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_1 + 4);
  iVar1 = ((int (*)())FUN_00032100)(uVar2);
  if (iVar1 == 0) {
    _gldDeleteTexture(uVar2,param_2);
  }
  return iVar1 != 0;
}

/* FUN_00039100 @ 0x39100 (188 bytes) */
int FUN_00039100(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_38;
  undefined4 local_34;
  undefined1 auStack_30 [44];
  
  local_38 = 0;
  local_34 = 3;
  iVar2 = _IOServiceOpen(*(undefined4 *)(param_1 * 4 + *(int *)(PTR_DAT_001e88ac + 8)),
                         *(undefined4 *)PTR_001e88b4,1,&local_38);
  uVar1 = 0;
  if (iVar2 == 0) {
    iVar2 = _io_connect_method_scalarI_scalarO(local_38,3,0,0,auStack_30,&local_34);
    if (iVar2 == 0) {
      _IOServiceClose(local_38);
      uVar1 = 1;
    }
    else {
      _IOServiceClose(local_38);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* _gldGetVersion @ 0x391f0 (84 bytes) */
int _gldGetVersion(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  undefined4 *param_4;
{
  if (*(int *)PTR_DAT_001e88ac == 0) {
    return 0;
  }
  *param_1 = 2;
  *param_2 = 4;
  *param_3 = 0xb;
  *param_4 = 0x1900;
  return 1;
}

/* _gldGetString @ 0x39250 (204 bytes) */
int _gldGetString(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint uVar1;
  
  switch(param_2) {
  case 0x1f00:
    return "ATI Technologies Inc.";
  case 0x1f01:
    break;
  case 0x1f02:
    return "1.5 ATI-1.4.19";
  case 0x1f03:
    return "";
  case 0x1f04:
    return "ATIRadeonX1000GLDriver";
  default:
    return (char *)0x0;
  }
  uVar1 = *(uint *)(param_1 + 0x24) & 0x7ff00000;
  if (uVar1 == 0x100000) {
    return "ATI Radeon X1800 OpenGL Engine";
  }
  if (uVar1 != 0x200000) {
    if (uVar1 != 0x800000) {
      return "ATI Radeon X1000 OpenGL Engine";
    }
    return "ATI Radeon X1900 OpenGL Engine";
  }
  return "ATI Radeon X1600 OpenGL Engine";
}

/* FUN_00039330 @ 0x39330 (724 bytes) */
int FUN_00039330(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  uint uVar10;
  uint uVar11;
  undefined4 *puVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  iVar7 = ((int (*)())FUN_0002cc30)(param_1,param_4,3,param_3);
  if (iVar7 != 0) {
    iVar13 = *(int *)(param_1 + 0x29e8);
    iVar14 = *(int *)(*(int *)(**(int **)(param_1 + 0x1cc) + 4) + 0x20);
    puVar8 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (param_1 + 0x240,
                        iVar14 * iVar7 * 5 + iVar7 * 2 +
                        (*(int *)(((unsigned char *)0x0000267c) + param_1) + 1U & 0xfffffffe) + 0x16);
    pcVar4 = *(code **)(((unsigned char *)0x00002680) + param_1);
    *(undefined4 **)(param_1 + 0x298c) = puVar8;
    if (pcVar4 != FUN_00001e24 + param_1) {
      uVar6 = *(undefined4 *)(param_1 + 0x1ee4);
      *(code **)(((unsigned char *)0x00002680) + param_1) = FUN_00001e24 + param_1;
      *(int *)(((unsigned char *)0x00002684) + param_1) = param_1 + 0x1e44;
      *(undefined4 *)(((unsigned char *)0x000026cc) + param_1) = uVar6;
      puVar8 = (undefined4 *)((int (*)())FUN_0002c0c0)(param_1,puVar8);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar8 = 0x5c8;
      puVar8[1] = 0x10000000;
      puVar8 = puVar8 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar9 = puVar8 + 4;
    *puVar8 = 0x82c;
    uVar11 = param_2 + iVar7 * iVar14 * 4 * 4;
    uVar6 = *(undefined4 *)(((unsigned char *)0x00001dc4) + param_1);
    puVar8[2] = 0x821;
    puVar8[3] = 3;
    puVar8[1] = uVar6;
    iVar7 = *(int *)(iVar13 + 0x2c);
    *(undefined1 *)(param_1 + 0x2a5e) = 1;
    if (param_2 < uVar11) {
      iVar13 = iVar14 + -1;
      uVar10 = 0;
      do {
        *puVar9 = 0x917;
        if (uVar10 < 0x20) {
          puVar9[1] = (uint)((1 << (uVar10 & 0x3f) &
                             **(uint **)("}J3x})+x|B;x}k" + *(int *)(param_1 + 0x10) + 8)) != 0);
        }
        else if (uVar10 < 0x40) {
          puVar9[1] = (uint)((1 << (uVar10 - 0x20 & 0x3f) &
                             *(uint *)(*(int *)("}J3x})+x|B;x}k" + *(int *)(param_1 + 0x10) + 8) + 4
                                      )) != 0);
        }
        else if (uVar10 < 0x60) {
          puVar9[1] = (uint)((1 << (uVar10 - 0x40 & 0x3f) &
                             *(uint *)(*(int *)("}J3x})+x|B;x}k" + *(int *)(param_1 + 0x10) + 8) + 8
                                      )) != 0);
        }
        else {
          puVar9[1] = (uint)((1 << (uVar10 - 0x60 & 0x3f) &
                             *(uint *)(*(int *)("}J3x})+x|B;x}k" + *(int *)(param_1 + 0x10) + 8) +
                                      0xc)) != 0);
        }
        puVar9 = puVar9 + 2;
        if (-1 < iVar13) {
          puVar12 = (undefined4 *)(iVar7 + iVar13 * 4);
          puVar8 = (undefined4 *)(param_2 + iVar13 * 0x10);
          iVar15 = iVar14;
          do {
            uVar6 = *puVar8;
            uVar1 = puVar8[1];
            uVar2 = puVar8[2];
            uVar3 = puVar8[3];
            puVar8 = puVar8 + -4;
            uVar5 = *puVar12;
            puVar12 = puVar12 + -1;
            puVar9[1] = uVar6;
            puVar9[2] = uVar1;
            puVar9[3] = uVar2;
            *puVar9 = uVar5;
            puVar9[4] = uVar3;
            puVar9 = puVar9 + 5;
            iVar15 = iVar15 + -1;
          } while (iVar15 != 0);
        }
        param_2 = param_2 + iVar14 * 0x10;
        uVar10 = uVar10 + 1;
      } while (param_2 < uVar11);
    }
    *puVar9 = 0x92b;
    puVar9[3] = 0;
    puVar9[2] = ((unsigned char *)0x00001393);
    puVar9[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar9 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(param_1 + 0x240);
    return;
  }
  return;
}

/* FUN_0003b160 @ 0x3b160 (284 bytes) */
int FUN_0003b160(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  
  piVar5 = *(int **)(param_1 + 0x1cc);
  if ((param_2 == 0) || (uVar4 = 0, (*(uint *)(param_2 + 0xc) & 0x4400000) != 0)) {
    uVar4 = 2;
  }
  if ((piVar5 != (int *)0x0) &&
     (((param_2 == 0 || ((*(uint *)(param_2 + 8) & 0xff00) != 0)) ||
      ((*(uint *)(param_2 + 0xc) & 0x4c00000) != 0)))) {
    uVar4 = uVar4 | 1;
  }
  FUN_00053000(param_1 + 0x240,uVar4);
  iVar1 = *(int *)(param_1 + 0x29e8) + 0x14;
  if ((uVar4 & 1) != 0) {
    iVar2 = piVar5[0xd];
    if (((iVar2 == 0) && (iVar2 = piVar5[0xc], iVar2 == 0)) && (iVar2 = piVar5[0xb], iVar2 == 0)) {
      iVar3 = *piVar5;
      iVar2 = *(int *)(iVar3 + 4);
    }
    else {
      iVar3 = *piVar5;
    }
    if ((uVar4 & 2) == 0) {
      FUN_0003d590(param_1,iVar1,*(undefined4 *)(iVar2 + 0x28),iVar2 + *(int *)(iVar2 + 0x2c) * 8,
                   *(undefined4 *)(iVar3 + 0x18),param_2 + 0x14);
    }
    else {
      FUN_0003b870(param_1,iVar1,*(undefined4 *)(iVar2 + 0x28),iVar2 + *(int *)(iVar2 + 0x2c) * 8,
                   *(undefined4 *)(iVar3 + 0x18));
    }
  }
  return param_3;
}

