#include "decls.h"

/* FUN_00113cd2 @ 0x113cd2 (83 bytes) */
int FUN_00113cd2(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_2;
  iVar1 = FUN_001139a8(*(undefined4 *)(*param_1 + 0x13c),*(undefined4 *)(*param_1 + 0x140));
  iVar2 = FUN_001139a8(*(undefined4 *)(iVar2 + 0x13c),*(undefined4 *)(iVar2 + 0x140));
  return iVar2 < iVar1;
}

/* FUN_00113d26 @ 0x113d26 (33 bytes) */
int FUN_00113d26(param_1, param_2)
  int *param_1;
  int *param_2;
{
  return *(int *)(*param_2 + 0x140) < *(int *)(*param_1 + 0x140);
}

/* FUN_00113d48 @ 0x113d48 (75 bytes) */
int FUN_00113d48(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  puVar2 = param_1;
  do {
    iVar1 = FUN_0010b0f4(*param_1,0);
    if (*(char *)(iVar3 + 0x10 + iVar1) != '\x01') {
      puVar2[1] = *(undefined4 *)(param_2 + iVar3 * 4);
      param_1[5] = param_1[5] + 1;
    }
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar3 != 4);
  return;
}

/* FUN_00113d94 @ 0x113d94 (82 bytes) */
int FUN_00113d94(param_1)
  undefined4 *param_1;
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int local_10;
  
  local_10 = 0;
  iVar3 = 0;
  puVar2 = param_1;
  do {
    if ((puVar2[7] != 0) ||
       (iVar1 = FUN_0010b0f4(*param_1,0), *(char *)(iVar3 + 0x10 + iVar1) == '\0')) {
      local_10 = local_10 + 1;
    }
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar3 != 4);
  return local_10;
}

/* FUN_00113de6 @ 0x113de6 (65 bytes) */
int FUN_00113de6(param_1, param_2)
  undefined4 *param_1;
  int param_2;
{
  int iVar1;
  
  if (param_1[param_2 + 7] == 0) {
    iVar1 = FUN_0010b0f4(*param_1,0);
    if (*(char *)(param_2 + 0x10 + iVar1) == '\x01') {
      return 1;
    }
  }
  return 0;
}

/* FUN_00113e28 @ 0x113e28 (96 bytes) */
int FUN_00113e28(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  uVar2 = *(uint *)(*(int *)(iVar1 + 0x3f4) + 0x30);
  if ((uVar2 & 1) == 0) {
    if ((uVar2 & 0x2000) != 0) {
      (**(code **)(**(int **)(iVar1 + 0x54) + 0x15c))(*(int **)(iVar1 + 0x54),param_1);
    }
  }
  else {
    (**(code **)(**(int **)(iVar1 + 0x54) + 0x164))(*(int **)(iVar1 + 0x54),param_1);
    piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    (**(code **)(*piVar3 + 0x160))(piVar3,param_1);
  }
  return;
}

/* FUN_00113e88 @ 0x113e88 (519 bytes) */
int FUN_00113e88(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int *local_98;
  int local_94;
  int local_90;
  int aiStack_8c [16];
  int aiStack_4c [16];
  
  piVar5 = *(int **)(*(int *)(param_2 + 0x39c) + 0x98);
  if (piVar5[2] == 0) {
    local_98 = (int *)0x0;
    local_94 = 0;
    local_90 = 0;
  }
  else {
    local_98 = (int *)0x0;
    local_94 = 0;
    local_90 = 0;
    do {
      while ((piVar2 = local_98, (*(byte *)(piVar5 + 5) & 1) == 0 ||
             (cVar3 = (**(code **)(*piVar5 + 0x68))(piVar5), cVar3 == '\0'))) {
LAB_00113ecd:
        local_98 = piVar2;
        piVar5 = (int *)piVar5[2];
        if (piVar5[2] == 0) goto LAB_00113f86;
      }
      iVar4 = FUN_0010aaf0(piVar5,0);
      if ((iVar4 == 0xb) ||
         ((iVar4 = FUN_0010aaf0(piVar5,0), iVar4 == 0xc ||
          (iVar4 = FUN_0010aaf0(piVar5,0), iVar4 == 1)))) {
        *(undefined4 *)(param_1 + 0x17b8) = 1;
      }
      iVar4 = piVar5[0x4f];
      if (((iVar4 == 6) || (piVar2 = piVar5, iVar4 == 0x18)) || (piVar2 = local_98, iVar4 == 7))
      goto LAB_00113ecd;
      if (iVar4 - 0x16U < 2) {
        aiStack_4c[local_90] = (int)piVar5;
        local_90 = local_90 + 1;
        goto LAB_00113ecd;
      }
      aiStack_8c[local_94] = (int)piVar5;
      local_94 = local_94 + 1;
      piVar5 = (int *)piVar5[2];
    } while (piVar5[2] != 0);
  }
LAB_00113f86:
  if (*(char *)(param_2 + 0x3d8) != '\0') {
    *(int *)(param_2 + 0x3e4) = -*(int *)(param_2 + 0x3dc);
    if (0 < local_90) {
      iVar4 = 0;
      do {
        iVar1 = aiStack_4c[iVar4];
        *(int *)(iVar1 + 0x94) = *(int *)(iVar1 + 0x140) + *(int *)(param_2 + 0x3e4);
        *(undefined4 *)(iVar1 + 0x98) = 5;
        iVar4 = iVar4 + 1;
      } while (local_90 != iVar4);
    }
    if (local_98 != (int *)0x0) {
      local_98[0x25] = local_98[0x50] + *(int *)(param_2 + 0x3e4);
      local_98[0x26] = 5;
    }
    if (0 < local_94) {
      iVar4 = 0;
      do {
        iVar1 = aiStack_8c[iVar4];
        *(int *)(iVar1 + 0x94) = *(int *)(iVar1 + 0x140) + *(int *)(param_2 + 0x3e4);
        *(undefined4 *)(iVar1 + 0x98) = 5;
        iVar4 = iVar4 + 1;
      } while (iVar4 != local_94);
    }
  }
  return;
}

/* FUN_00114090 @ 0x114090 (105 bytes) */
int FUN_00114090(param_1)
  undefined4 param_1;
{
  bool bVar1;
  int iVar2;
  char cStack_11;
  int local_10;
  
  iVar2 = FUN_0010b0f4(param_1,0);
  local_10 = *(int *)(iVar2 + 0x10);
  if (*(int *)(iVar2 + 0x10) != DAT_001cbee4) {
    bVar1 = false;
    iVar2 = 1;
    do {
      if ((&cStack_11)[iVar2] == '\0') {
        if (bVar1) {
          return 1;
        }
      }
      else if ((&cStack_11)[iVar2] == '\x01') {
        bVar1 = true;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 != 5);
  }
  return 0;
}

/* FUN_001140fa @ 0x1140fa (548 bytes) */
int FUN_001140fa(param_1, param_2)
  int *param_1;
  int param_2;
{
  code *pcVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  int local_3c;
  uint local_38;
  uint local_30;
  
  piVar13 = *(int **)(*(int *)(param_2 + 0x394) + 0x98);
  if (piVar13[2] != 0) {
    local_3c = 0;
    do {
      while (((*(byte *)(piVar13 + 5) & 1) == 0 ||
             (cVar5 = (**(code **)(*piVar13 + 0x4c))(piVar13), cVar5 == '\0'))) {
        piVar13 = (int *)piVar13[2];
        if (piVar13[2] == 0) {
          return;
        }
      }
      iVar6 = (**(code **)(*piVar13 + 0x80))(piVar13);
      *(int *)(iVar6 + 0x94) = local_3c;
      *(undefined4 *)(iVar6 + 0x98) = 0;
      *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) | 0x40;
      FUN_00137b7e(param_2,local_3c);
      local_38 = 0xf;
      iVar11 = 0;
      do {
        iVar7 = FUN_0010a72e(iVar6,iVar11);
        if ((iVar7 != 0) && (local_30 = 1 << ((byte)iVar11 & 0x1f), (local_30 & local_38) != 0)) {
          iVar7 = FUN_0010a7c6(iVar6,iVar11);
          iVar8 = FUN_0010a038(iVar6,iVar11);
          iVar12 = iVar11 + 1;
          if (iVar12 < 4) {
            do {
              iVar9 = FUN_0010a72e(iVar6,iVar12);
              if (((iVar9 != 0) && (iVar9 = FUN_0010a7c6(iVar6,iVar12), iVar9 == iVar7)) &&
                 (iVar9 = FUN_0010a038(iVar6,iVar12), iVar8 == iVar9)) {
                local_30 = local_30 | 1 << ((byte)iVar12 & 0x1f);
              }
              iVar12 = iVar12 + 1;
            } while (iVar12 != 4);
          }
          if (local_30 != 0) {
            pcVar1 = *(code **)(*param_1 + 0x54);
            uVar2 = *(undefined4 *)(iVar6 + 0x148);
            uVar3 = *(uint *)(iVar6 + 0x13c);
            iVar12 = FUN_0010b0f4(iVar6,1);
            uVar4 = *(undefined4 *)(iVar12 + 0x10);
            uVar10 = FUN_000edb5e(param_2,iVar7);
            (*pcVar1)(param_1,local_3c,uVar10,iVar8,uVar4,uVar3 & 1,(int)(uVar3 & 4) >> 2,
                      (int)(uVar3 & 2) >> 1,local_30,uVar2,DAT_001cbedc,param_2);
            local_38 = local_38 - local_30;
          }
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < 4);
      local_3c = local_3c + 1;
      piVar13 = (int *)piVar13[2];
    } while (piVar13[2] != 0);
  }
  return;
}

/* FUN_0011431e @ 0x11431e (1162 bytes) */
int FUN_0011431e(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  char cVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  int iVar16;
  int local_34;
  byte local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  
  iVar8 = *(int *)(param_2 + 0x398);
  if (iVar8 == 0) {
    iVar8 = *(int *)(param_2 + 0x394);
  }
  uVar1 = *(undefined4 *)(param_2 + 8);
  iVar9 = *(int *)(param_2 + 1000);
  iVar10 = *(int *)(param_2 + 0x3dc);
  iVar11 = *(int *)(param_2 + 0x3e0);
  if (*(char *)(param_2 + 0x3d8) != '\0') {
    piVar7 = *(int **)(iVar8 + 0x98);
    if (piVar7[2] == 0) goto LAB_00114387;
    do {
      while ((*(byte *)(piVar7 + 5) & 1) != 0) {
        cVar6 = (**(code **)(*piVar7 + 0x4c))(piVar7);
        if ((((cVar6 != '\0') && (iVar12 = piVar7[0x52], iVar9 == piVar7[0x51])) &&
            (iVar10 <= iVar12)) && (iVar12 < iVar11)) {
          iVar12 = iVar12 - iVar10;
          FUN_00137b7e(param_2,iVar12);
          FUN_00138146(param_2,iVar12);
          piVar7[0x25] = iVar12;
          piVar7[0x26] = 0;
          piVar7[5] = piVar7[5] | 0x40;
          if (*(int *)(param_2 + 0x80) < iVar12) {
            *(int *)(param_2 + 0x80) = iVar12;
          }
          local_30 = (byte)iVar12;
          *(uint *)(param_2 + 0x88) = *(uint *)(param_2 + 0x88) | 1 << (local_30 & 0x1f);
        }
        piVar7 = (int *)piVar7[2];
        if (piVar7[2] == 0) goto LAB_00114548;
      }
      piVar7 = (int *)piVar7[2];
    } while (piVar7[2] != 0);
  }
LAB_00114548:
  piVar7 = *(int **)(iVar8 + 0x98);
LAB_00114387:
  if (piVar7[2] == 0) {
    return;
  }
  local_34 = 0;
  do {
    while (((*(byte *)(piVar7 + 5) & 1) == 0 ||
           (cVar6 = (**(code **)(*piVar7 + 0x4c))(piVar7), cVar6 == '\0'))) {
LAB_0011439d:
      piVar7 = (int *)piVar7[2];
      if (piVar7[2] == 0) {
        return;
      }
    }
    iVar8 = (**(code **)(*piVar7 + 0x80))(piVar7);
    if (((*(byte *)(iVar8 + 0x14) & 0x40) == 0) || (*(int *)(iVar8 + 0x98) != 0)) {
      while (iVar9 = (**(code **)(*param_1 + 0x138))(param_1,*(undefined4 *)(param_2 + 8)),
            local_34 < iVar9) {
        cVar6 = FUN_00137fb8(param_2,local_34);
        if (cVar6 == '\0') {
          local_34 = local_34 + 1;
        }
        else {
          cVar6 = FUN_00137bae(param_2,local_34);
          if (cVar6 != '\0') {
            local_2c = local_34;
            local_34 = local_34 + 1;
            goto LAB_0011465a;
          }
          local_34 = local_34 + 1;
        }
      }
      local_2c = -1;
LAB_0011465a:
      FUN_00137b7e(param_2,local_2c);
      *(int *)(iVar8 + 0x94) = local_2c;
      *(undefined4 *)(iVar8 + 0x98) = 0;
      if (*(int *)(param_2 + 0x80) < local_2c) {
        *(int *)(param_2 + 0x80) = local_2c;
      }
      *(uint *)(param_2 + 0x88) = *(uint *)(param_2 + 0x88) | 1 << ((byte)local_2c & 0x1f);
      *(uint *)(iVar8 + 0x14) = *(uint *)(iVar8 + 0x14) | 0x40;
    }
    else {
      local_2c = *(int *)(iVar8 + 0x94);
    }
    if ((local_2c < 0) ||
       (iVar9 = (**(code **)(*param_1 + 0x138))(param_1,*(undefined4 *)(param_2 + 8)),
       iVar9 <= local_2c)) {
      FUN_000e27ca(uVar1,4);
    }
    if ((*(int *)(iVar8 + 0x144) == 0x1b) || (*(int *)(iVar8 + 0x144) == 0x23)) goto LAB_0011439d;
    if (*(int *)(iVar8 + 0x144) == 0x24) {
      *(int *)(iVar8 + 0x148) = local_2c;
    }
    local_28 = 0xf;
    iVar9 = 0;
    do {
      iVar10 = FUN_0010a72e(iVar8,iVar9);
      if ((iVar10 != 0) && (local_24 = 1 << ((byte)iVar9 & 0x1f), (local_24 & local_28) != 0)) {
        iVar11 = FUN_0010a7c6(iVar8,iVar9);
        iVar12 = FUN_0010a038(iVar8,iVar9);
        iVar10 = 1;
        if (iVar11 != 7) {
          iVar10 = iVar12;
        }
        iVar16 = iVar9 + 1;
        if (iVar16 < 4) {
          do {
            iVar13 = FUN_0010a72e(iVar8,iVar16);
            if (((iVar13 != 0) && (iVar13 = FUN_0010a7c6(iVar8,iVar16), iVar13 == iVar11)) &&
               (iVar13 = FUN_0010a038(iVar8,iVar16), iVar12 == iVar13)) {
              local_24 = local_24 | 1 << ((byte)iVar16 & 0x1f);
            }
            iVar16 = iVar16 + 1;
          } while (iVar16 != 4);
        }
        if (local_24 != 0) {
          uVar14 = FUN_0010a77e(iVar8);
          pcVar2 = *(code **)(*param_1 + 0x54);
          uVar3 = *(undefined4 *)(iVar8 + 0x148);
          uVar4 = *(uint *)(iVar8 + 0x13c);
          iVar12 = FUN_0010b0f4(iVar8,1);
          uVar5 = *(undefined4 *)(iVar12 + 0x10);
          uVar15 = FUN_000edb5e(param_2,iVar11);
          (*pcVar2)(param_1,local_2c,uVar15,iVar10,uVar5,uVar4 & 1,(int)(uVar4 & 4) >> 2,
                    (int)(uVar4 & 2) >> 1,local_24,uVar3,uVar14,param_2);
          local_28 = local_28 - local_24;
        }
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < 4);
    piVar7 = (int *)piVar7[2];
    if (piVar7[2] == 0) {
      return;
    }
  } while( true );
}

/* FUN_001147a8 @ 0x1147a8 (9 bytes) */
int FUN_001147a8()
{
  ((int (*)())FUN_0011431e)();
  return;
}

/* FUN_001147b2 @ 0x1147b2 (9 bytes) */
int FUN_001147b2()
{
  ((int (*)())FUN_0011431e)();
  return;
}

/* FUN_001147bc @ 0x1147bc (309 bytes) */
int FUN_001147bc(param_1, param_2)
  undefined4 *param_1;
  uint *param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint local_1c;
  int local_14;
  undefined4 *local_10;
  
  if (param_2[1] != 0) {
    local_1c = 0;
    do {
      if (local_1c < *param_2) {
        uVar1 = param_2[1];
        if (uVar1 <= local_1c) {
          _memset((void *)(param_2[2] + uVar1 * 4),0,(local_1c - uVar1) * 4 + 4);
          param_2[1] = local_1c + 1;
        }
        piVar4 = (int *)(param_2[2] + local_1c * 4);
      }
      else {
        piVar4 = (int *)FUN_001a7f7c(param_2,local_1c);
      }
      local_1c = local_1c + 1;
      piVar4 = (int *)*piVar4;
      local_10 = param_1;
      local_14 = 0;
      do {
        iVar2 = FUN_0010b0f4(*param_1,0);
        if (*(char *)(local_14 + 0x10 + iVar2) != '\x01') {
          iVar2 = 0;
          piVar5 = piVar4;
          do {
            iVar3 = FUN_0010b0f4(*piVar4,0);
            if ((*(char *)(iVar2 + 0x10 + iVar3) != '\x01') && (piVar5[1] == local_10[1])) {
              piVar5[1] = 0;
              piVar4[5] = piVar4[5] + -1;
              *(undefined1 *)(iVar2 + 0x9c + *piVar4) = 1;
            }
            iVar2 = iVar2 + 1;
            piVar5 = piVar5 + 1;
          } while (iVar2 != 4);
        }
        local_14 = local_14 + 1;
        local_10 = local_10 + 1;
      } while (local_14 != 4);
    } while (local_1c < param_2[1]);
  }
  return;
}

/* FUN_001148f2 @ 0x1148f2 (521 bytes) */
int FUN_001148f2(param_1)
  int param_1;
{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint uVar6;
  
  puVar5 = *(uint **)(param_1 + 0x410);
  if (puVar5[1] != 0) {
    uVar6 = 0;
    do {
      if (uVar6 < *puVar5) {
        uVar2 = puVar5[1];
        if (uVar2 <= uVar6) {
          _memset((void *)(puVar5[2] + uVar2 * 4),0,(uVar6 - uVar2) * 4 + 4);
          puVar5[1] = uVar6 + 1;
        }
        puVar4 = (undefined4 *)(puVar5[2] + uVar6 * 4);
      }
      else {
        puVar4 = (undefined4 *)FUN_001a7f7c(puVar5,uVar6);
      }
      uVar1 = *(undefined4 *)*puVar4;
      FUN_0010b0f4(uVar1,0);
      iVar3 = FUN_0010b7c8(uVar1,0);
      if (iVar3 != 0) {
        return 1;
      }
      uVar6 = uVar6 + 1;
      puVar5 = *(uint **)(param_1 + 0x410);
    } while (uVar6 < puVar5[1]);
  }
  puVar5 = *(uint **)(param_1 + 0x414);
  if (puVar5[1] != 0) {
    uVar6 = 0;
    do {
      if (uVar6 < *puVar5) {
        uVar2 = puVar5[1];
        if (uVar2 <= uVar6) {
          _memset((void *)(puVar5[2] + uVar2 * 4),0,(uVar6 - uVar2) * 4 + 4);
          puVar5[1] = uVar6 + 1;
        }
        puVar4 = (undefined4 *)(puVar5[2] + uVar6 * 4);
      }
      else {
        puVar4 = (undefined4 *)FUN_001a7f7c(puVar5,uVar6);
      }
      uVar1 = *(undefined4 *)*puVar4;
      FUN_0010b0f4(uVar1,0);
      iVar3 = FUN_0010b7c8(uVar1,0);
      if (iVar3 != 0) {
        return 1;
      }
      uVar6 = uVar6 + 1;
      puVar5 = *(uint **)(param_1 + 0x414);
    } while (uVar6 < puVar5[1]);
  }
  puVar5 = *(uint **)(param_1 + 0x418);
  if (puVar5[1] != 0) {
    uVar6 = 0;
    do {
      if (uVar6 < *puVar5) {
        uVar2 = puVar5[1];
        if (uVar2 <= uVar6) {
          _memset((void *)(puVar5[2] + uVar2 * 4),0,(uVar6 - uVar2) * 4 + 4);
          puVar5[1] = uVar6 + 1;
        }
        puVar4 = (undefined4 *)(puVar5[2] + uVar6 * 4);
      }
      else {
        puVar4 = (undefined4 *)FUN_001a7f7c(puVar5,uVar6);
      }
      uVar1 = *(undefined4 *)*puVar4;
      FUN_0010b0f4(uVar1,0);
      iVar3 = FUN_0010b7c8(uVar1,0);
      if (iVar3 != 0) {
        return 1;
      }
      uVar6 = uVar6 + 1;
      puVar5 = *(uint **)(param_1 + 0x418);
    } while (uVar6 < puVar5[1]);
  }
  return 0;
}

/* FUN_00114afc @ 0x114afc (325 bytes) */
int FUN_00114afc(param_1, param_2, param_3)
  int param_1;
  uint *param_2;
  int param_3;
{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint *puVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  
  uVar1 = *(undefined4 *)(param_3 + 0xbc);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar1,0x14);
  *puVar3 = uVar1;
  puVar3[2] = 0x30;
  puVar3[1] = 2;
  uVar6 = 0;
  puVar4 = puVar3 + 1;
  do {
    puVar4[2] = 0;
    uVar6 = uVar6 + 1;
    puVar4 = puVar4 + 1;
  } while (uVar6 < (uint)puVar3[1]);
  if (param_2[1] == 0) {
LAB_00114bc4:
    if (puVar3[2] != 0) {
      uVar6 = 0;
      iVar7 = 0;
      do {
        iVar7 = (iVar7 + 1) -
                (uint)(((uint)puVar3[(uVar6 >> 5) + 3] >> ((byte)uVar6 & 0x1f) & 1) == 0);
        uVar6 = uVar6 + 1;
      } while (puVar3[2] != uVar6);
      return iVar7;
    }
    return 0;
  }
  uVar6 = 0;
  do {
    if (uVar6 < *param_2) {
      uVar2 = param_2[1];
      if (uVar2 <= uVar6) {
        _memset((void *)(param_2[2] + uVar2 * 4),0,(uVar6 - uVar2) * 4 + 4);
        param_2[1] = uVar6 + 1;
      }
      iVar7 = *(int *)(param_2[2] + uVar6 * 4);
      if (*(int *)(iVar7 + 0x1c) == param_1) goto LAB_00114ba3;
LAB_00114b76:
      if (param_2[1] <= uVar6 + 1) goto LAB_00114bc4;
    }
    else {
      piVar5 = (int *)FUN_001a7f7c(param_2,uVar6);
      iVar7 = *piVar5;
      if (*(int *)(iVar7 + 0x1c) != param_1) goto LAB_00114b76;
LAB_00114ba3:
      puVar3[(*(uint *)(iVar7 + 0x14) >> 5) + 3] =
           puVar3[(*(uint *)(iVar7 + 0x14) >> 5) + 3] | 1 << ((byte)*(uint *)(iVar7 + 0x14) & 0x1f);
      if (param_2[1] <= uVar6 + 1) goto LAB_00114bc4;
    }
    uVar6 = uVar6 + 1;
  } while( true );
}

/* FUN_00114c42 @ 0x114c42 (484 bytes) */
int FUN_00114c42(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint *param_3;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  uint *puVar7;
  int iVar8;
  uint local_20;
  uint local_1c;
  int local_14;
  uint local_10;
  
  if (param_3[1] != 0) {
    local_1c = 0;
    do {
      if (local_1c < *param_3) {
        uVar1 = param_3[1];
        if (uVar1 <= local_1c) {
          _memset((void *)(param_3[2] + uVar1 * 4),0,(local_1c - uVar1) * 4 + 4);
          param_3[1] = local_1c + 1;
        }
        puVar6 = (undefined4 *)(param_3[2] + local_1c * 4);
      }
      else {
        puVar6 = (undefined4 *)FUN_001a7f7c(param_3,local_1c);
      }
      local_20 = local_1c + 1;
      iVar2 = *(int *)*puVar6;
      if (*(uint *)(iVar2 + 0x94) != local_1c) {
        iVar3 = FUN_0010b0f4(iVar2,0);
        *(uint *)(iVar3 + 8) = local_1c;
        local_14 = 0;
        do {
          puVar7 = *(uint **)(param_1 + 0x40c);
          if (puVar7[1] != 0) {
            local_10 = 0;
            do {
              if (local_10 < *puVar7) {
                uVar1 = puVar7[1];
                if (uVar1 <= local_10) {
                  _memset((void *)(puVar7[2] + uVar1 * 4),0,(local_10 - uVar1) * 4 + 4);
                  puVar7[1] = local_10 + 1;
                }
                iVar8 = *(int *)(puVar7[2] + local_10 * 4);
                iVar3 = *(int *)(iVar8 + 4);
                iVar5 = FUN_0010aaf0(iVar2,local_14);
                if (iVar3 == iVar5) goto LAB_00114d4f;
              }
              else {
                piVar4 = (int *)FUN_001a7f7c(puVar7,local_10);
                iVar8 = *piVar4;
                iVar3 = *(int *)(iVar8 + 4);
                iVar5 = FUN_0010aaf0(iVar2,local_14);
                if (iVar3 == iVar5) {
LAB_00114d4f:
                  iVar3 = *(int *)(iVar8 + 8);
                  iVar5 = FUN_00109f54(iVar2,local_14);
                  if ((iVar3 == iVar5) && (*(int *)(iVar8 + 0x18) == local_14)) {
                    *(uint *)(iVar8 + 0x14) = local_1c;
                    *(uint *)(iVar8 + 0xc) = local_1c;
                    break;
                  }
                }
              }
              local_10 = local_10 + 1;
              puVar7 = *(uint **)(param_1 + 0x40c);
            } while (local_10 < puVar7[1]);
          }
          local_14 = local_14 + 1;
        } while (local_14 != 4);
      }
      local_1c = local_20;
    } while (local_20 < param_3[1]);
  }
  return;
}

/* FUN_00114e26 @ 0x114e26 (250 bytes) */
int FUN_00114e26(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  uint *param_5;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (param_5[1] != 0) {
    uVar5 = 0;
    do {
      while( true ) {
        if (uVar5 < *param_5) {
          uVar6 = param_5[1];
          if (uVar6 <= uVar5) {
            _memset((void *)(param_5[2] + uVar6 * 4),0,(uVar5 - uVar6) * 4 + 4);
            param_5[1] = uVar5 + 1;
          }
          iVar1 = *(int *)(param_5[2] + uVar5 * 4);
          iVar4 = *(int *)(iVar1 + 0x1c);
        }
        else {
          piVar2 = (int *)FUN_001a7f7c(param_5,uVar5);
          iVar1 = *piVar2;
          iVar4 = *(int *)(iVar1 + 0x1c);
        }
        if ((iVar4 == param_1) && (uVar6 = uVar5 + 1, param_3 < param_4)) break;
LAB_00114e73:
        uVar5 = uVar5 + 1;
        if (param_5[1] <= uVar5) {
          return;
        }
      }
      if (*(int *)(iVar1 + 0x14) == *(int *)(param_2 + param_3 * 4)) {
        *(int *)(iVar1 + 0x14) = param_3;
      }
      else {
        iVar4 = param_2 + param_3 * 4;
        iVar3 = param_3;
        do {
          iVar3 = iVar3 + 1;
          if (iVar3 == param_4) goto LAB_00114e73;
          piVar2 = (int *)(iVar4 + 4);
          iVar4 = iVar4 + 4;
        } while (*piVar2 != *(int *)(iVar1 + 0x14));
        *(int *)(iVar1 + 0x14) = iVar3;
      }
      uVar5 = uVar6;
    } while (uVar6 < param_5[1]);
  }
  return;
}

/* FUN_00114f20 @ 0x114f20 (352 bytes) */
int FUN_00114f20(param_1, param_2, param_3)
  uint *param_1;
  int *param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int local_d0;
  undefined4 local_cc [48];
  
  iVar1 = *param_2;
  *param_2 = iVar1 + 4;
  if ((int)param_1[1] < 1) {
    iVar6 = 1;
  }
  else {
    uVar7 = 0;
    local_d0 = 0;
    do {
      if (uVar7 < *param_1) {
        uVar3 = param_1[1];
        if (uVar3 <= uVar7) {
          _memset((void *)(param_1[2] + uVar3 * 4),0,(uVar7 - uVar3) * 4 + 4);
          param_1[1] = uVar7 + 1;
        }
        puVar5 = (undefined4 *)(param_1[2] + uVar7 * 4);
      }
      else {
        puVar5 = (undefined4 *)FUN_001a7f7c(param_1,uVar7);
      }
      uVar7 = uVar7 + 1;
      piVar4 = (int *)*puVar5;
      iVar6 = FUN_001139a8(*(undefined4 *)(*piVar4 + 0x13c),*(undefined4 *)(*piVar4 + 0x140));
      if (iVar6 < 4) {
        iVar6 = iVar1 + iVar6;
      }
      else {
        iVar6 = *param_2;
        *param_2 = iVar6 + 1;
      }
      local_cc[iVar6] = *(undefined4 *)(*piVar4 + 0x94);
      iVar2 = *piVar4;
      *(int *)(iVar2 + 0x94) = iVar6;
      *(undefined4 *)(iVar2 + 0x98) = 5;
      if (iVar6 <= local_d0) {
        iVar6 = local_d0;
      }
      local_d0 = iVar6;
    } while ((int)uVar7 < (int)param_1[1]);
    iVar6 = iVar6 + 1;
  }
  ((int (*)())FUN_00114e26)(2,local_cc,iVar1,iVar6,*(undefined4 *)(param_3 + 0x40c));
  return;
}

/* FUN_00115080 @ 0x115080 (296 bytes) */
int FUN_00115080(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint *param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  int local_d0;
  undefined4 local_cc [48];
  
  iVar1 = *(int *)(param_4 + 0x3e4);
  if ((int)param_2[1] < 1) {
    iVar6 = 1;
  }
  else {
    uVar7 = 0;
    local_d0 = 0;
    do {
      if (uVar7 < *param_2) {
        uVar2 = param_2[1];
        if (uVar2 <= uVar7) {
          _memset((void *)(param_2[2] + uVar2 * 4),0,(uVar7 - uVar2) * 4 + 4);
          param_2[1] = uVar7 + 1;
        }
        puVar5 = (undefined4 *)(param_2[2] + uVar7 * 4);
      }
      else {
        puVar5 = (undefined4 *)FUN_001a7f7c(param_2,uVar7);
      }
      uVar7 = uVar7 + 1;
      piVar3 = (int *)*puVar5;
      iVar4 = *piVar3;
      iVar6 = iVar1 + *(int *)(iVar4 + 0x140);
      local_cc[iVar6] = *(undefined4 *)(iVar4 + 0x94);
      iVar4 = *piVar3;
      *(int *)(iVar4 + 0x94) = iVar6;
      *(undefined4 *)(iVar4 + 0x98) = 5;
      if (iVar6 <= local_d0) {
        iVar6 = local_d0;
      }
      local_d0 = iVar6;
    } while ((int)uVar7 < (int)param_2[1]);
    iVar6 = iVar6 + 1;
  }
  ((int (*)())FUN_00114e26)(param_1,local_cc,iVar1,iVar6,*(undefined4 *)(param_4 + 0x40c));
  return;
}

/* FUN_001151a8 @ 0x1151a8 (413 bytes) */
int FUN_001151a8(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint *param_2;
  int *param_3;
  int param_4;
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  int iVar9;
  uint local_d8;
  int local_d0 [49];
  
  iVar6 = 1;
  do {
    local_d0[iVar6] = -1;
    iVar6 = iVar6 + 1;
  } while (iVar6 != 0x31);
  iVar6 = *param_3;
  local_d0[0] = iVar6;
  if (0 < (int)param_2[1]) {
    local_d8 = 0;
    do {
      if (local_d8 < *param_2) {
        uVar1 = param_2[1];
        if (uVar1 <= local_d8) {
          _memset((void *)(param_2[2] + uVar1 * 4),0,(local_d8 - uVar1) * 4 + 4);
          param_2[1] = local_d8 + 1;
        }
        puVar7 = (undefined4 *)(param_2[2] + local_d8 * 4);
      }
      else {
        puVar7 = (undefined4 *)FUN_001a7f7c(param_2,local_d8);
      }
      local_d8 = local_d8 + 1;
      piVar2 = (int *)*puVar7;
      iVar6 = *(int *)(*piVar2 + 0x94);
      if (local_d0[0] < 0x30) {
        piVar8 = local_d0 + 1 + local_d0[0];
        iVar9 = local_d0[0];
        bVar5 = false;
        do {
          while (bVar4 = bVar5, iVar6 != *piVar8) {
            iVar9 = iVar9 + 1;
            piVar8 = piVar8 + 1;
            bVar5 = bVar4;
            if (iVar9 == 0x30) goto LAB_00115276;
          }
          iVar3 = *piVar2;
          *(int *)(iVar3 + 0x94) = iVar9;
          *(undefined4 *)(iVar3 + 0x98) = 5;
          bVar4 = true;
          iVar9 = iVar9 + 1;
          piVar8 = piVar8 + 1;
          bVar5 = true;
        } while (iVar9 != 0x30);
LAB_00115276:
        if (!bVar4) goto LAB_0011527a;
      }
      else {
LAB_0011527a:
        iVar9 = *param_3;
        local_d0[iVar9 + 1] = iVar6;
        iVar6 = *piVar2;
        *(int *)(iVar6 + 0x94) = iVar9;
        *(undefined4 *)(iVar6 + 0x98) = 5;
        *param_3 = *param_3 + 1;
      }
    } while ((int)local_d8 < (int)param_2[1]);
    iVar6 = *param_3;
  }
  ((int (*)())FUN_00114e26)(param_1,local_d0 + 1,local_d0[0],iVar6,*(undefined4 *)(param_4 + 0x40c));
  return;
}

/* FUN_00115346 @ 0x115346 (224 bytes) */
int FUN_00115346(param_1, param_2)
  int *param_1;
  uint *param_2;
{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  
  if (param_2[1] != 0) {
    uVar5 = 0;
    do {
      if (uVar5 < *param_2) {
        uVar2 = param_2[1];
        if (uVar2 <= uVar5) {
          _memset((void *)(param_2[2] + uVar2 * 4),0,(uVar5 - uVar2) * 4 + 4);
          param_2[1] = uVar5 + 1;
        }
        piVar4 = *(int **)(param_2[2] + uVar5 * 4);
        if (piVar4[7] == param_1[6]) goto LAB_001153b4;
      }
      else {
        piVar4 = (int *)FUN_001a7f7c(param_2,uVar5);
        piVar4 = (int *)*piVar4;
        if (piVar4[7] == param_1[6]) {
LAB_001153b4:
          iVar6 = 0;
          iVar1 = param_1[1];
          piVar3 = param_1;
          while( true ) {
            if (*piVar4 == iVar1) {
              piVar4[5] = *(int *)(*param_1 + 0x94);
              piVar4[6] = iVar6;
            }
            iVar6 = iVar6 + 1;
            if (iVar6 == 4) break;
            iVar1 = piVar3[2];
            piVar3 = piVar3 + 1;
          }
        }
      }
      uVar5 = uVar5 + 1;
    } while (uVar5 < param_2[1]);
  }
  return;
}

/* FUN_00115426 @ 0x115426 (903 bytes) */
int FUN_00115426(param_1, param_2)
  int param_1;
  int param_2;
{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char cVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int *piVar13;
  int local_3c;
  int local_20;
  
  piVar13 = *(int **)(param_2 + 0xb0);
  cVar6 = FUN_00113b56(piVar13);
  if (cVar6 == '\0') {
    return;
  }
  iVar7 = FUN_0010b0f4(piVar13,0);
  if (*(int *)(iVar7 + 0x10) == DAT_001cbee0) {
    FUN_000f1b60(param_1,piVar13);
    (**(code **)(*piVar13 + 0xc))(piVar13,0,*(undefined4 *)(param_1 + 8));
    return;
  }
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
  puVar8 = (undefined4 *)FUN_001a7bca(uVar1,0x30);
  *puVar8 = uVar1;
  piVar9 = puVar8 + 1;
  FUN_00113c88(piVar9,piVar13);
  cVar6 = FUN_00113bf8(piVar13);
  if (cVar6 == '\0') {
    cVar6 = FUN_00113bc0(piVar13);
    if (cVar6 != '\0') {
      puVar2 = *(uint **)(param_1 + 0x414);
      uVar3 = puVar2[1];
      if (uVar3 < *puVar2) {
        _memset((void *)(uVar3 * 4 + puVar2[2]),0,4);
        puVar2[1] = uVar3 + 1;
        *(int **)(uVar3 * 4 + puVar2[2]) = piVar9;
      }
      else {
        puVar8 = (undefined4 *)FUN_001a7f7c(puVar2,uVar3);
        *puVar8 = piVar9;
      }
      goto LAB_001154fc;
    }
    cVar6 = FUN_00113b8e(piVar13);
    if (cVar6 == '\0') goto LAB_001154fc;
    puVar2 = *(uint **)(param_1 + 0x418);
    uVar3 = puVar2[1];
    if (uVar3 < *puVar2) {
      _memset((void *)(uVar3 * 4 + puVar2[2]),0,4);
      puVar2[1] = uVar3 + 1;
      puVar8 = (undefined4 *)(uVar3 * 4 + puVar2[2]);
    }
    else {
      puVar8 = (undefined4 *)FUN_001a7f7c(puVar2,uVar3);
    }
  }
  else {
    puVar2 = *(uint **)(param_1 + 0x410);
    uVar3 = puVar2[1];
    if (uVar3 < *puVar2) {
      _memset((void *)(uVar3 * 4 + puVar2[2]),0,4);
      puVar2[1] = uVar3 + 1;
      puVar8 = (undefined4 *)(uVar3 * 4 + puVar2[2]);
    }
    else {
      puVar8 = (undefined4 *)FUN_001a7f7c(puVar2,uVar3);
    }
  }
  *puVar8 = piVar9;
LAB_001154fc:
  cVar6 = FUN_000e1402(*(undefined4 *)(param_1 + 8),7);
  if (cVar6 != '\0') {
    FUN_00183382(param_2);
    ((int (*)())FUN_00113d48)(piVar9,param_2 + 0x20);
  }
  local_20 = param_2;
  local_3c = 0;
  do {
    iVar7 = FUN_0010b0f4(*piVar9,0);
    if (*(char *)(local_3c + 0x10 + iVar7) != '\x01') {
      uVar1 = *(undefined4 *)(local_20 + 0x20);
      uVar10 = FUN_0010aaf0(*piVar9,local_3c);
      uVar11 = FUN_00109f54(*piVar9,local_3c);
      uVar4 = *(undefined4 *)(*piVar9 + 0x94);
      uVar12 = FUN_00113930(*(undefined4 *)(*piVar9 + 0x13c));
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
      puVar8 = (undefined4 *)FUN_001a7bca(uVar5,0x24);
      *puVar8 = uVar5;
      puVar8[1] = uVar1;
      puVar8[2] = uVar10;
      puVar8[3] = uVar11;
      puVar8[4] = uVar4;
      puVar8[5] = local_3c;
      puVar8[6] = uVar4;
      puVar8[7] = local_3c;
      puVar8[8] = uVar12;
      puVar2 = *(uint **)(param_1 + 0x40c);
      uVar3 = puVar2[1];
      if (uVar3 < *puVar2) {
        _memset((void *)(uVar3 * 4 + puVar2[2]),0,4);
        puVar2[1] = uVar3 + 1;
        piVar13 = (int *)(uVar3 * 4 + puVar2[2]);
      }
      else {
        piVar13 = (int *)FUN_001a7f7c(puVar2,uVar3);
      }
      *piVar13 = (int)(puVar8 + 1);
    }
    local_3c = local_3c + 1;
    local_20 = local_20 + 4;
  } while (local_3c != 4);
  return;
}

/* FUN_001157ce @ 0x1157ce (9800 bytes) */
int FUN_001157ce(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  undefined1 uVar1;
  undefined1 uVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  int *piVar13;
  int iVar14;
  int iVar15;
  undefined4 *puVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  uint *puVar23;
  uint *puVar24;
  int *piVar25;
  uint *puVar26;
  undefined4 *local_198;
  int local_194;
  uint local_18c;
  uint local_188;
  uint local_184;
  uint local_180;
  uint local_17c;
  uint local_178;
  uint local_174;
  uint local_170;
  uint local_16c;
  uint local_168;
  uint local_164;
  uint local_160;
  uint *local_144;
  uint *local_134;
  int local_12c;
  int local_124;
  int local_120;
  uint local_118;
  undefined4 *local_108;
  int local_100;
  int local_f0;
  undefined4 *local_ec;
  int local_e8;
  int local_d0;
  int local_cc;
  uint local_c8;
  undefined4 *local_c0;
  int *local_b8;
  int local_b4;
  uint local_b0;
  int local_a8;
  int local_a4;
  undefined4 *local_98;
  undefined4 *local_94;
  int local_90;
  int local_8c;
  int *local_88;
  undefined4 *local_84;
  undefined4 *local_80;
  int *local_78;
  int *local_74;
  uint local_60;
  int local_5c;
  uint local_54;
  uint local_50;
  int aiStack_44 [5];
  int local_30 [4];
  int local_20 [4];
  
  uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar4 = (undefined4 *)FUN_001a7bca(uVar5,0x14);
  *puVar4 = uVar5;
  puVar4[4] = uVar5;
  puVar4[2] = 0;
  puVar4[1] = 2;
  uVar5 = FUN_001a7bca(uVar5,8);
  puVar4[3] = uVar5;
  puVar23 = *(uint **)(param_1 + 0x40c);
  if (puVar23[1] != 0) {
    uVar22 = 0;
    do {
      while( true ) {
        if (uVar22 < *puVar23) {
          uVar19 = puVar23[1];
          if (uVar19 <= uVar22) {
            _memset((void *)(puVar23[2] + uVar19 * 4),0,(uVar22 - uVar19) * 4 + 4);
            puVar23[1] = uVar22 + 1;
          }
          piVar6 = *(int **)(puVar23[2] + uVar22 * 4);
          iVar7 = piVar6[7];
        }
        else {
          piVar6 = (int *)FUN_001a7f7c(puVar23,uVar22);
          piVar6 = (int *)*piVar6;
          iVar7 = piVar6[7];
        }
        if (param_2 == iVar7) break;
LAB_0011586c:
        local_18c = uVar22 + 1;
        puVar23 = *(uint **)(param_1 + 0x40c);
        uVar22 = local_18c;
        if (puVar23[1] <= local_18c) goto LAB_00115956;
      }
      local_18c = uVar22 + 1;
      uVar19 = puVar4[2];
      if ((int)uVar19 < 1) {
        local_194 = *piVar6;
      }
      else {
        local_194 = *piVar6;
        uVar18 = 0;
        do {
          if (uVar18 < uVar19) {
            piVar6 = (int *)(puVar4[3] + uVar18 * 4);
          }
          else {
            piVar6 = (int *)0x0;
          }
          if (*piVar6 == local_194) goto LAB_0011586c;
          uVar18 = uVar18 + 1;
        } while (uVar19 != uVar18);
      }
      if (uVar19 < (uint)puVar4[1]) {
        _memset((void *)(uVar19 * 4 + puVar4[3]),0,4);
        puVar4[2] = uVar19 + 1;
        piVar6 = (int *)(uVar19 * 4 + puVar4[3]);
      }
      else {
        piVar6 = (int *)FUN_001a7f7c(puVar4 + 1,uVar19);
      }
      *piVar6 = local_194;
      puVar23 = *(uint **)(param_1 + 0x40c);
      uVar22 = local_18c;
    } while (local_18c < puVar23[1]);
  }
LAB_00115956:
  uVar19 = puVar4[2];
  *(uint *)(param_1 + 0x41c) = uVar19;
  uVar22 = uVar19;
  if ((int)uVar19 < 0) {
    uVar22 = uVar19 + 3;
  }
  iVar7 = ((int)uVar22 >> 2) + 1;
  if ((uVar19 & 3) == 0) {
    iVar7 = (int)uVar22 >> 2;
  }
  iVar8 = ((int (*)())FUN_00114afc)(param_2,puVar23,*(undefined4 *)(param_1 + 8));
  if (iVar7 < iVar8) {
    if (param_3[1] != 0) {
      uVar22 = 0;
      do {
        if (uVar22 < *param_3) {
          uVar19 = param_3[1];
          if (uVar19 <= uVar22) {
            _memset((void *)(param_3[2] + uVar19 * 4),0,(uVar22 - uVar19) * 4 + 4);
            param_3[1] = uVar22 + 1;
          }
          FUN_001a7d72(**(undefined4 **)(param_3[2] + uVar22 * 4));
          if (param_3[1] <= uVar22 + 1) break;
        }
        else {
          puVar4 = (undefined4 *)FUN_001a7f7c(param_3,uVar22);
          FUN_001a7d72(*(undefined4 *)*puVar4);
          if (param_3[1] <= uVar22 + 1) break;
        }
        uVar22 = uVar22 + 1;
      } while( true );
    }
    if (param_3[1] != 0) {
      local_188 = 0;
      do {
        if (local_188 < *param_3) {
          uVar22 = param_3[1];
          if (uVar22 <= local_188) {
            _memset((void *)(param_3[2] + uVar22 * 4),0,(local_188 - uVar22) * 4 + 4);
            param_3[1] = local_188 + 1;
          }
          piVar6 = (int *)(param_3[2] + local_188 * 4);
        }
        else {
          piVar6 = (int *)FUN_001a7f7c(param_3,local_188);
        }
        local_188 = local_188 + 1;
        piVar6 = (int *)*piVar6;
        local_12c = 0;
        local_74 = piVar6;
        do {
          iVar8 = FUN_0010b0f4(*piVar6,0);
          if ((*(char *)(local_12c + 0x10 + iVar8) != '\x01') &&
             (iVar8 = FUN_00113966(piVar6,local_12c), -1 < iVar8)) {
            piVar6[5] = piVar6[5] + -1;
            local_74[1] = 0;
            puVar23 = *(uint **)(param_1 + 0x40c);
            if (puVar23[1] != 0) {
              uVar22 = 0;
              do {
                if (uVar22 < *puVar23) {
                  uVar19 = puVar23[1];
                  if (uVar19 <= uVar22) {
                    _memset((void *)(puVar23[2] + uVar19 * 4),0,(uVar22 - uVar19) * 4 + 4);
                    puVar23[1] = uVar22 + 1;
                  }
                  iVar17 = *(int *)(puVar23[2] + uVar22 * 4);
                  iVar20 = *(int *)(iVar17 + 0x1c);
                }
                else {
                  piVar9 = (int *)FUN_001a7f7c(puVar23,uVar22);
                  iVar17 = *piVar9;
                  iVar20 = *(int *)(iVar17 + 0x1c);
                }
                if (((param_2 == iVar20) && (*(int *)(iVar17 + 0x10) == local_12c)) &&
                   (*(int *)(iVar17 + 0xc) == *(int *)(*piVar6 + 0x94))) {
                  *(int *)(iVar17 + 0x18) = iVar8;
                  break;
                }
                uVar22 = uVar22 + 1;
                puVar23 = *(uint **)(param_1 + 0x40c);
              } while (uVar22 < puVar23[1]);
            }
            *(undefined1 *)(local_12c + 0x9c + *piVar6) = 1;
          }
          local_12c = local_12c + 1;
          local_74 = local_74 + 1;
        } while (local_12c != 4);
      } while (local_188 < param_3[1]);
    }
    piVar6 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    cVar3 = (**(code **)(*piVar6 + 0xc4))(piVar6);
    if (cVar3 == '\0') {
      if (param_3[1] != 0) {
        local_184 = 0;
        do {
          if (local_184 < *param_3) {
            uVar22 = param_3[1];
            if (uVar22 <= local_184) {
              _memset((void *)(param_3[2] + uVar22 * 4),0,(local_184 - uVar22) * 4 + 4);
              param_3[1] = local_184 + 1;
            }
            piVar6 = *(int **)(param_3[2] + local_184 * 4);
            cVar3 = ((int (*)())FUN_00114090)(*piVar6);
          }
          else {
            puVar4 = (undefined4 *)FUN_001a7f7c(param_3,local_184);
            piVar6 = (int *)*puVar4;
            cVar3 = ((int (*)())FUN_00114090)(*piVar6);
          }
          if (cVar3 != '\0') {
            local_124 = 0;
            do {
              iVar8 = FUN_0010b0f4(*piVar6,0);
              if ((*(char *)(local_124 + 0x10 + iVar8) == '\x01') &&
                 (local_120 = local_124 + 1, local_120 < 4)) {
                do {
                  iVar8 = FUN_0010b0f4(*piVar6,0);
                  if (*(char *)(local_120 + 0x10 + iVar8) == '\0') {
                    iVar8 = piVar6[local_124 + 1];
                    piVar6[local_124 + 1] = piVar6[local_120 + 1];
                    piVar6[local_120 + 1] = iVar8;
                    *(undefined1 *)(local_124 + 0x9c + *piVar6) = 0;
                    *(undefined1 *)(local_120 + 0x9c + *piVar6) = 1;
                    iVar8 = FUN_0010b0f4(*piVar6,1);
                    uVar1 = *(undefined1 *)(local_120 + 0x10 + iVar8);
                    iVar8 = FUN_0010b0f4(*piVar6,1);
                    uVar2 = *(undefined1 *)(local_124 + 0x10 + iVar8);
                    (**(code **)(*(int *)*piVar6 + 0x88))((int *)*piVar6,1,local_124,uVar1);
                    (**(code **)(*(int *)*piVar6 + 0x88))((int *)*piVar6,1,local_120,uVar2);
                    break;
                  }
                  local_120 = local_120 + 1;
                } while (local_120 != 4);
              }
              local_124 = local_124 + 1;
            } while (local_124 < 4);
            puVar23 = *(uint **)(param_1 + 0x40c);
            if (puVar23[1] != 0) {
              local_180 = 0;
              do {
                if (local_180 < *puVar23) {
                  uVar22 = puVar23[1];
                  if (uVar22 <= local_180) {
                    _memset((void *)(puVar23[2] + uVar22 * 4),0,(local_180 - uVar22) * 4 + 4);
                    puVar23[1] = local_180 + 1;
                  }
                  piVar9 = *(int **)(puVar23[2] + local_180 * 4);
                  iVar8 = piVar9[7];
                }
                else {
                  piVar9 = (int *)FUN_001a7f7c(puVar23,local_180);
                  piVar9 = (int *)*piVar9;
                  iVar8 = piVar9[7];
                }
                if ((param_2 == iVar8) && (piVar9[3] == *(int *)(*piVar6 + 0x94))) {
                  iVar8 = 0;
                  piVar10 = piVar6;
                  do {
                    if (*piVar9 == piVar10[1]) {
                      piVar9[6] = iVar8;
                      break;
                    }
                    iVar8 = iVar8 + 1;
                    piVar10 = piVar10 + 1;
                  } while (iVar8 != 4);
                }
                local_180 = local_180 + 1;
                puVar23 = *(uint **)(param_1 + 0x40c);
              } while (local_180 < puVar23[1]);
            }
          }
          local_184 = local_184 + 1;
        } while (local_184 < param_3[1]);
      }
      local_90 = 4;
      do {
        if (0 < (int)param_3[1]) {
          local_17c = 0;
          do {
            if (local_17c < *param_3) {
              uVar22 = param_3[1];
              if (uVar22 <= local_17c) {
                _memset((void *)(param_3[2] + uVar22 * 4),0,(local_17c - uVar22) * 4 + 4);
                param_3[1] = local_17c + 1;
              }
              piVar6 = *(int **)(param_3[2] + local_17c * 4);
              iVar8 = piVar6[5];
            }
            else {
              piVar6 = (int *)FUN_001a7f7c(param_3,local_17c);
              piVar6 = (int *)*piVar6;
              iVar8 = piVar6[5];
            }
            if ((local_90 == iVar8) && (0 < (int)param_3[1])) {
              local_118 = 0;
              if (*param_3 == 0) goto LAB_00115dcb;
LAB_00115c59:
              uVar22 = param_3[1];
              if (uVar22 <= local_118) {
                _memset((void *)(param_3[2] + uVar22 * 4),0,(local_118 - uVar22) * 4 + 4);
                param_3[1] = local_118 + 1;
              }
              puVar4 = (undefined4 *)(param_3[2] + local_118 * 4);
              do {
                piVar9 = (int *)*puVar4;
                cVar3 = FUN_001139e8(piVar9,piVar6,local_30);
                if (cVar3 != '\0') {
                  iVar8 = *(int *)(*piVar9 + 0x94);
                  uVar5 = *(undefined4 *)(*piVar6 + 0x94);
                  puVar23 = *(uint **)(param_1 + 0x40c);
                  if (0 < (int)puVar23[1]) {
                    uVar22 = 0;
                    do {
                      while( true ) {
                        if (uVar22 < *puVar23) {
                          uVar19 = puVar23[1];
                          if (uVar19 <= uVar22) {
                            _memset((void *)(puVar23[2] + uVar19 * 4),0,(uVar22 - uVar19) * 4 + 4);
                            puVar23[1] = uVar22 + 1;
                          }
                          iVar17 = *(int *)(puVar23[2] + uVar22 * 4);
                          iVar20 = *(int *)(iVar17 + 0x1c);
                        }
                        else {
                          piVar10 = (int *)FUN_001a7f7c(puVar23,uVar22);
                          iVar17 = *piVar10;
                          iVar20 = *(int *)(iVar17 + 0x1c);
                        }
                        if (param_2 == iVar20) break;
LAB_00115d07:
                        uVar22 = uVar22 + 1;
                        puVar23 = *(uint **)(param_1 + 0x40c);
                        if ((int)puVar23[1] <= (int)uVar22) goto LAB_00115d67;
                      }
                      uVar19 = uVar22 + 1;
                      if ((iVar8 != *(int *)(iVar17 + 0x14)) ||
                         (local_30[*(int *)(iVar17 + 0x18)] == -1)) goto LAB_00115d07;
                      *(int *)(iVar17 + 0x18) = local_30[*(int *)(iVar17 + 0x18)];
                      *(undefined4 *)(iVar17 + 0x14) = uVar5;
                      puVar23 = *(uint **)(param_1 + 0x40c);
                      uVar22 = uVar19;
                    } while ((int)uVar19 < (int)puVar23[1]);
                  }
LAB_00115d67:
                  FUN_001a805e(param_3,piVar9);
                  FUN_000f1b60(param_1,*piVar9);
                  *(int *)(param_1 + 0x230) = *(int *)(param_1 + 0x230) + 1;
                  local_118 = local_118 - 1;
                }
                local_118 = local_118 + 1;
                if ((int)param_3[1] <= (int)local_118) break;
                if (local_118 < *param_3) goto LAB_00115c59;
LAB_00115dcb:
                puVar4 = (undefined4 *)FUN_001a7f7c(param_3,local_118);
              } while( true );
            }
            local_17c = local_17c + 1;
          } while ((int)local_17c < (int)param_3[1]);
        }
        local_90 = local_90 + -1;
      } while (local_90 != 0);
    }
    piVar6 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    cVar3 = (**(code **)(*piVar6 + 0xc4))(piVar6);
    if (cVar3 == '\0') {
      local_144 = (uint *)0x0;
    }
    else {
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
      puVar4 = (undefined4 *)FUN_001a7bca(uVar5,0x14);
      *puVar4 = uVar5;
      local_144 = puVar4 + 1;
      puVar4[4] = uVar5;
      puVar4[2] = 0;
      puVar4[1] = 2;
      uVar5 = FUN_001a7bca(uVar5,8);
      puVar4[3] = uVar5;
      local_8c = 4;
      do {
        if (param_3[1] == 0) break;
        if (0 < (int)param_3[1]) {
          uVar22 = 0;
          do {
            while (uVar22 < *param_3) {
              uVar19 = param_3[1];
              if (uVar19 <= uVar22) {
                _memset((void *)(param_3[2] + uVar19 * 4),0,(uVar22 - uVar19) * 4 + 4);
                param_3[1] = uVar22 + 1;
              }
              local_108 = *(undefined4 **)(param_3[2] + uVar22 * 4);
              iVar8 = local_108[5];
              if (iVar8 != 0) goto LAB_00115ea5;
LAB_00115ee3:
              FUN_001a805e(param_3,local_108);
              FUN_000f1b60(param_1,*local_108);
              *(int *)(param_1 + 0x230) = *(int *)(param_1 + 0x230) + 1;
              FUN_0010b0f4(*local_108,0);
              if ((int)param_3[1] <= (int)uVar22) goto LAB_00115f2d;
            }
            piVar6 = (int *)FUN_001a7f7c(param_3,uVar22);
            local_108 = (undefined4 *)*piVar6;
            iVar8 = local_108[5];
            if (iVar8 == 0) goto LAB_00115ee3;
LAB_00115ea5:
            if (iVar8 == local_8c) {
              FUN_001a805e(param_3,local_108);
              ((int (*)())FUN_001147bc)(local_108,param_3);
              ((int (*)())FUN_00115346)(local_108,*(undefined4 *)(param_1 + 0x40c));
              uVar19 = puVar4[2];
              if (uVar19 < *local_144) {
                _memset((void *)(uVar19 * 4 + puVar4[3]),0,4);
                puVar4[2] = uVar19 + 1;
                piVar6 = (int *)(uVar19 * 4 + puVar4[3]);
              }
              else {
                piVar6 = (int *)FUN_001a7f7c(local_144,uVar19);
              }
              *piVar6 = (int)local_108;
              uVar22 = uVar22 - 1;
            }
            uVar22 = uVar22 + 1;
          } while ((int)uVar22 < (int)param_3[1]);
        }
LAB_00115f2d:
        local_8c = local_8c + -1;
      } while (local_8c != 0);
    }
    piVar6 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    cVar3 = (**(code **)(*piVar6 + 0xc4))(piVar6);
    if (cVar3 == '\0') {
      local_144 = param_3;
    }
    uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
    puVar4 = (undefined4 *)FUN_001a7bca(uVar5,0x14);
    *puVar4 = uVar5;
    puVar23 = puVar4 + 1;
    puVar4[4] = uVar5;
    puVar4[2] = 0;
    puVar4[1] = 2;
    uVar5 = FUN_001a7bca(uVar5,8);
    puVar4[3] = uVar5;
    uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
    puVar11 = (undefined4 *)FUN_001a7bca(uVar5,0x14);
    *puVar11 = uVar5;
    puVar26 = puVar11 + 1;
    puVar11[4] = uVar5;
    puVar11[2] = 0;
    puVar11[1] = 2;
    uVar5 = FUN_001a7bca(uVar5,8);
    puVar11[3] = uVar5;
    local_100 = 0;
    local_78 = &DAT_00212280;
    do {
      *local_78 = local_100;
      local_78[2] = 4;
      local_78[1] = DAT_001cbee0;
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
      puVar12 = (undefined4 *)FUN_001a7bca(uVar5,0x14);
      *puVar12 = uVar5;
      puVar12[4] = uVar5;
      puVar12[2] = 0;
      puVar12[1] = 2;
      uVar5 = FUN_001a7bca(uVar5,8);
      puVar12[3] = uVar5;
      local_78[3] = (int)(puVar12 + 1);
      local_100 = local_100 + 1;
      local_78 = local_78 + 4;
    } while (local_100 != 0xc);
    if (0 < (int)local_144[1]) {
      local_178 = 0;
      if (*local_144 == 0) goto LAB_00117249;
      do {
        uVar22 = local_144[1];
        if (uVar22 <= local_178) {
          _memset((void *)(local_144[2] + uVar22 * 4),0,(local_178 - uVar22) * 4 + 4);
          local_144[1] = local_178 + 1;
        }
        puVar12 = (undefined4 *)(local_144[2] + local_178 * 4);
        while( true ) {
          local_178 = local_178 + 1;
          piVar6 = (int *)*puVar12;
          iVar8 = *(int *)(*piVar6 + 0x94);
          puVar12 = &DAT_00212280 + iVar8 * 4;
          iVar20 = 0;
          do {
            iVar17 = FUN_0010b0f4(*piVar6,0);
            if (*(char *)(iVar20 + 0x10 + iVar17) != '\x01') {
              *(undefined1 *)(puVar12 + 1) = 0;
              (DAT_00212288)[iVar8 * 4] = (DAT_00212288)[iVar8 * 4] + -1;
            }
            iVar20 = iVar20 + 1;
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          } while (iVar20 != 4);
          puVar24 = (uint *)(DAT_0021228c)[iVar8 * 4];
          uVar22 = puVar24[1];
          if (uVar22 < *puVar24) {
            _memset((void *)(uVar22 * 4 + puVar24[2]),0,4);
            puVar24[1] = uVar22 + 1;
            puVar12 = (undefined4 *)(uVar22 * 4 + puVar24[2]);
          }
          else {
            puVar12 = (undefined4 *)FUN_001a7f7c(puVar24,uVar22);
          }
          *puVar12 = piVar6;
          if ((int)local_144[1] <= (int)local_178) goto LAB_001160e9;
          if (local_178 < *local_144) break;
LAB_00117249:
          puVar12 = (undefined4 *)FUN_001a7f7c(local_144,local_178);
        }
      } while( true );
    }
LAB_001160e9:
    local_f0 = 0;
    local_80 = &DAT_00212280;
    local_198 = &DAT_00212280;
    do {
      while (local_80[2] == 0) {
        puVar24 = (uint *)local_80[3];
        if (0 < (int)puVar24[1]) {
          local_174 = 0;
          do {
            if (local_174 < *puVar24) {
              uVar22 = puVar24[1];
              if (uVar22 <= local_174) {
                _memset((void *)(puVar24[2] + uVar22 * 4),0,(local_174 - uVar22) * 4 + 4);
                puVar24[1] = local_174 + 1;
              }
              local_ec = (undefined4 *)(puVar24[2] + local_174 * 4);
              uVar22 = puVar4[2];
              if (uVar22 < *puVar23) goto LAB_00116184;
LAB_0011620b:
              puVar12 = (undefined4 *)FUN_001a7f7c(puVar23,uVar22);
            }
            else {
              local_ec = (undefined4 *)FUN_001a7f7c(puVar24,local_174);
              uVar22 = puVar4[2];
              if (*puVar23 <= uVar22) goto LAB_0011620b;
LAB_00116184:
              _memset((void *)(uVar22 * 4 + puVar4[3]),0,4);
              puVar4[2] = uVar22 + 1;
              puVar12 = (undefined4 *)(uVar22 * 4 + puVar4[3]);
            }
            local_174 = local_174 + 1;
            *puVar12 = *local_ec;
            puVar24 = (uint *)local_80[3];
          } while ((int)local_174 < (int)puVar24[1]);
        }
LAB_0011610d:
        local_f0 = local_f0 + 1;
        local_198 = local_198 + 4;
        local_80 = local_80 + 4;
        if (local_f0 == 0xc) goto LAB_001162f4;
      }
      if (3 < (int)local_80[2]) goto LAB_0011610d;
      uVar22 = puVar11[2];
      if (uVar22 < *puVar26) {
        _memset((void *)(uVar22 * 4 + puVar11[3]),0,4);
        puVar11[2] = uVar22 + 1;
        puVar12 = (undefined4 *)(uVar22 * 4 + puVar11[3]);
      }
      else {
        puVar12 = (undefined4 *)FUN_001a7f7c(puVar26,uVar22);
      }
      *puVar12 = local_198;
      local_f0 = local_f0 + 1;
      local_198 = local_198 + 4;
      local_80 = local_80 + 4;
    } while (local_f0 != 0xc);
LAB_001162f4:
    local_e8 = 1;
    do {
      if (0 < (int)puVar11[2]) {
        local_60 = 0;
        do {
          if (local_60 < *puVar26) {
            uVar22 = puVar11[2];
            if (uVar22 <= local_60) {
              _memset((void *)(puVar11[3] + uVar22 * 4),0,(local_60 - uVar22) * 4 + 4);
              puVar11[2] = local_60 + 1;
            }
            piVar6 = (int *)(puVar11[3] + local_60 * 4);
          }
          else {
            piVar6 = (int *)FUN_001a7f7c(puVar26,local_60);
          }
          piVar6 = (int *)*piVar6;
          iVar8 = *piVar6;
          if ((local_e8 == piVar6[2]) && (0 < (int)puVar11[2])) {
            uVar22 = 0;
LAB_0011697b:
            if (uVar22 < *puVar26) {
              uVar19 = puVar11[2];
              if (uVar19 <= uVar22) {
                _memset((void *)(puVar11[3] + uVar19 * 4),0,(uVar22 - uVar19) * 4 + 4);
                puVar11[2] = uVar22 + 1;
              }
              piVar9 = (int *)(puVar11[3] + uVar22 * 4);
            }
            else {
              piVar9 = (int *)FUN_001a7f7c(puVar26,uVar22);
            }
            piVar9 = (int *)*piVar9;
            iVar20 = *piVar9;
            if ((iVar20 == iVar8) || (local_e8 < 4 - piVar9[2])) goto LAB_00116969;
            FUN_001a805e(puVar26,piVar9);
            puVar24 = (uint *)piVar9[3];
            if (0 < (int)puVar24[1]) {
              local_170 = 0;
              do {
                if (local_170 < *puVar24) {
                  uVar22 = puVar24[1];
                  if (uVar22 <= local_170) {
                    _memset((void *)(puVar24[2] + uVar22 * 4),0,(local_170 - uVar22) * 4 + 4);
                    puVar24[1] = local_170 + 1;
                  }
                  piVar10 = (int *)(puVar24[2] + local_170 * 4);
                }
                else {
                  piVar10 = (int *)FUN_001a7f7c(puVar24,local_170);
                }
                local_170 = local_170 + 1;
                piVar10 = (int *)*piVar10;
                iVar17 = *piVar10;
                iVar14 = DAT_001cbee0;
                iVar15 = DAT_001cbedc;
                iVar21 = 1;
                piVar25 = piVar10;
                do {
                  aiStack_44[iVar21] = 0;
                  piVar25[7] = 0;
                  iVar21 = iVar21 + 1;
                  piVar25 = piVar25 + 1;
                } while (iVar21 != 5);
                local_d0 = 0;
                piVar25 = piVar6;
                local_30[0] = iVar15;
                local_20[0] = iVar14;
                do {
                  if ((char)piVar25[1] == '\x01') {
                    local_cc = 0;
                    iVar14 = FUN_0010b0f4(iVar17,0);
                    cVar3 = *(char *)(iVar14 + 0x10);
                    while (cVar3 == '\x01') {
                      if (local_cc + 1 == 4) goto LAB_00116b3d;
                      iVar14 = FUN_0010b0f4(iVar17,0);
                      cVar3 = *(char *)(local_cc + 0x11 + iVar14);
                      local_cc = local_cc + 1;
                    }
                    iVar14 = FUN_0010b0f4(iVar17,1);
                    *(undefined1 *)((int)local_30 + local_d0) =
                         *(undefined1 *)(local_cc + 0x10 + iVar14);
                    *(undefined1 *)((int)local_20 + local_d0) = 0;
                    piVar6[2] = piVar6[2] + -1;
                    *(undefined1 *)(piVar25 + 1) = 0;
                    aiStack_44[local_d0 + 1] = piVar10[local_cc + 1];
                    puVar24 = *(uint **)(param_1 + 0x40c);
                    if (0 < (int)puVar24[1]) {
                      local_c8 = 0;
                      do {
                        if (local_c8 < *puVar24) {
                          uVar22 = puVar24[1];
                          if (uVar22 <= local_c8) {
                            _memset((void *)(puVar24[2] + uVar22 * 4),0,(local_c8 - uVar22) * 4 + 4)
                            ;
                            puVar24[1] = local_c8 + 1;
                          }
                          iVar15 = *(int *)(puVar24[2] + local_c8 * 4);
                          iVar14 = *(int *)(iVar15 + 0x1c);
                        }
                        else {
                          piVar13 = (int *)FUN_001a7f7c(puVar24,local_c8);
                          iVar15 = *piVar13;
                          iVar14 = *(int *)(iVar15 + 0x1c);
                        }
                        if (((param_2 == iVar14) && (iVar20 == *(int *)(iVar15 + 0x14))) &&
                           (local_cc == *(int *)(iVar15 + 0x18))) {
                          *(int *)(iVar15 + 0x14) = iVar8;
                          *(int *)(iVar15 + 0x18) = local_d0;
                        }
                        local_c8 = local_c8 + 1;
                        puVar24 = *(uint **)(param_1 + 0x40c);
                      } while ((int)local_c8 < (int)puVar24[1]);
                    }
                    *(undefined1 *)(local_cc + 0x9c + iVar17) = 1;
                  }
LAB_00116b3d:
                  local_d0 = local_d0 + 1;
                  piVar25 = (int *)((int)piVar25 + 1);
                } while (local_d0 != 4);
                iVar14 = 1;
                piVar25 = piVar10;
                do {
                  piVar25[1] = aiStack_44[iVar14];
                  piVar25[7] = 1;
                  iVar14 = iVar14 + 1;
                  piVar25 = piVar25 + 1;
                } while (iVar14 != 5);
                iVar15 = FUN_0010b0f4(iVar17,0);
                iVar14 = local_30[0];
                *(int *)(iVar15 + 8) = iVar8;
                *(int *)(iVar17 + 0x9c) = local_20[0];
                iVar17 = FUN_0010b0f4(iVar17,1);
                *(int *)(iVar17 + 0x10) = iVar14;
                puVar24 = (uint *)piVar6[3];
                uVar22 = puVar24[1];
                if (uVar22 < *puVar24) {
                  _memset((void *)(uVar22 * 4 + puVar24[2]),0,4);
                  puVar24[1] = uVar22 + 1;
                  piVar25 = (int *)(uVar22 * 4 + puVar24[2]);
                }
                else {
                  piVar25 = (int *)FUN_001a7f7c(puVar24,uVar22);
                }
                *piVar25 = (int)piVar10;
                puVar24 = (uint *)piVar9[3];
              } while ((int)local_170 < (int)puVar24[1]);
            }
            if (0 < piVar6[2]) {
              local_e8 = piVar6[2] + -1;
              local_60 = 1;
              goto LAB_0011636a;
            }
            puVar24 = (uint *)piVar6[3];
            if (0 < (int)puVar24[1]) {
              local_16c = 0;
              do {
                while (*puVar24 <= local_16c) {
                  local_c0 = (undefined4 *)FUN_001a7f7c(puVar24,local_16c);
                  uVar22 = puVar4[2];
                  if (*puVar23 <= uVar22) goto LAB_0011739d;
LAB_00117316:
                  local_16c = local_16c + 1;
                  _memset((void *)(uVar22 * 4 + puVar4[3]),0,4);
                  puVar4[2] = uVar22 + 1;
                  *(undefined4 *)(uVar22 * 4 + puVar4[3]) = *local_c0;
                  puVar24 = (uint *)piVar6[3];
                  if ((int)puVar24[1] <= (int)local_16c) goto LAB_001173cf;
                }
                uVar22 = puVar24[1];
                if (uVar22 <= local_16c) {
                  _memset((void *)(puVar24[2] + uVar22 * 4),0,(local_16c - uVar22) * 4 + 4);
                  puVar24[1] = local_16c + 1;
                }
                local_c0 = (undefined4 *)(puVar24[2] + local_16c * 4);
                uVar22 = puVar4[2];
                if (uVar22 < *puVar23) goto LAB_00117316;
LAB_0011739d:
                local_16c = local_16c + 1;
                puVar12 = (undefined4 *)FUN_001a7f7c(puVar23,uVar22);
                *puVar12 = *local_c0;
                puVar24 = (uint *)piVar6[3];
              } while ((int)local_16c < (int)puVar24[1]);
            }
LAB_001173cf:
            FUN_001a805e(puVar26,piVar6);
          }
          else {
LAB_00116366:
            local_60 = local_60 + 1;
          }
LAB_0011636a: ;
        } while ((int)local_60 < (int)puVar11[2]);
      }
      local_e8 = local_e8 + 1;
    } while (local_e8 < 4);
    if (0 < (int)puVar11[2]) {
      local_168 = 0;
      do {
        if (local_168 < *puVar26) {
          uVar22 = puVar11[2];
          if (uVar22 <= local_168) {
            _memset((void *)(puVar11[3] + uVar22 * 4),0,(local_168 - uVar22) * 4 + 4);
            puVar11[2] = local_168 + 1;
          }
          piVar6 = (int *)(puVar11[3] + local_168 * 4);
        }
        else {
          piVar6 = (int *)FUN_001a7f7c(puVar26,local_168);
        }
        local_168 = local_168 + 1;
        iVar8 = *piVar6;
        puVar24 = *(uint **)(iVar8 + 0xc);
        if (0 < (int)puVar24[1]) {
          local_164 = 0;
          do {
            if (local_164 < *puVar24) {
              uVar22 = puVar24[1];
              if (uVar22 <= local_164) {
                _memset((void *)(puVar24[2] + uVar22 * 4),0,(local_164 - uVar22) * 4 + 4);
                puVar24[1] = local_164 + 1;
              }
              local_5c = *(int *)(puVar24[2] + local_164 * 4);
              uVar22 = puVar4[2];
              if (uVar22 < *puVar23) goto LAB_0011641c;
LAB_00116a42:
              piVar6 = (int *)FUN_001a7f7c(puVar23,uVar22);
            }
            else {
              piVar6 = (int *)FUN_001a7f7c(puVar24,local_164);
              local_5c = *piVar6;
              uVar22 = puVar4[2];
              if (*puVar23 <= uVar22) goto LAB_00116a42;
LAB_0011641c:
              _memset((void *)(uVar22 * 4 + puVar4[3]),0,4);
              puVar4[2] = uVar22 + 1;
              piVar6 = (int *)(uVar22 * 4 + puVar4[3]);
            }
            local_164 = local_164 + 1;
            *piVar6 = local_5c;
            iVar17 = 4;
            iVar20 = iVar8;
            do {
              if (*(char *)(iVar20 + 4) == '\0') {
                *(undefined4 *)(local_5c + 0x1c) = 1;
              }
              iVar20 = iVar20 + 1;
              local_5c = local_5c + 4;
              iVar17 = iVar17 + -1;
            } while (iVar17 != 0);
            puVar24 = *(uint **)(iVar8 + 0xc);
          } while ((int)local_164 < (int)puVar24[1]);
        }
      } while ((int)local_168 < (int)puVar11[2]);
    }
    if (0 < (int)puVar4[2]) {
      local_160 = 0;
      do {
        if (local_160 < *puVar23) {
          uVar22 = puVar4[2];
          if (uVar22 <= local_160) {
            _memset((void *)(puVar4[3] + uVar22 * 4),0,(local_160 - uVar22) * 4 + 4);
            puVar4[2] = local_160 + 1;
          }
          puVar11 = (undefined4 *)(puVar4[3] + local_160 * 4);
        }
        else {
          puVar11 = (undefined4 *)FUN_001a7f7c(puVar23,local_160);
        }
        local_160 = local_160 + 1;
        puVar11 = (undefined4 *)*puVar11;
        iVar8 = 0;
        do {
          FUN_00109ed6(*puVar11,iVar8,0,0);
          iVar8 = iVar8 + 1;
        } while (iVar8 != 4);
      } while ((int)local_160 < (int)puVar4[2]);
    }
    piVar6 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    cVar3 = (**(code **)(*piVar6 + 0xc4))(piVar6);
    if (cVar3 == '\0') {
      local_134 = (uint *)0x0;
    }
    else {
      uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
      puVar11 = (undefined4 *)FUN_001a7bca(uVar5,0x14);
      *puVar11 = uVar5;
      local_134 = puVar11 + 1;
      puVar11[4] = uVar5;
      puVar11[2] = 0;
      puVar11[1] = 2;
      uVar5 = FUN_001a7bca(uVar5,8);
      puVar11[3] = uVar5;
      for (iVar8 = ((int (*)())FUN_00114afc)(param_2,*(undefined4 *)(param_1 + 0x40c),
                                *(undefined4 *)(param_1 + 8)); iVar7 < iVar8; iVar8 = iVar8 + -1) {
        iVar20 = 1;
        local_b8 = (int *)0x0;
        do {
          if (0 < (int)puVar4[2]) {
            uVar22 = 0;
            do {
              if (uVar22 < *puVar23) {
                uVar19 = puVar4[2];
                if (uVar19 <= uVar22) {
                  _memset((void *)(puVar4[3] + uVar19 * 4),0,(uVar22 - uVar19) * 4 + 4);
                  puVar4[2] = uVar22 + 1;
                }
                local_b8 = *(int **)(puVar4[3] + uVar22 * 4);
                iVar17 = local_b8[5];
              }
              else {
                local_b8 = (int *)FUN_001a7f7c(puVar23,uVar22);
                local_b8 = (int *)*local_b8;
                iVar17 = local_b8[5];
              }
              if (iVar17 == iVar20) {
                FUN_001a805e(puVar23,local_b8);
                FUN_000f1b60(param_1,*local_b8);
                *(int *)(param_1 + 0x230) = *(int *)(param_1 + 0x230) + 1;
                goto LAB_0011752c;
              }
              uVar22 = uVar22 + 1;
            } while ((int)uVar22 < (int)puVar4[2]);
          }
          iVar20 = iVar20 + 1;
        } while (iVar20 < 5);
LAB_0011752c:
        local_b4 = 3;
        do {
          if (0 < (int)puVar4[2]) {
            local_b0 = 0;
            do {
              while( true ) {
                if (local_b0 < *puVar23) {
                  uVar22 = puVar4[2];
                  if (uVar22 <= local_b0) {
                    _memset((void *)(puVar4[3] + uVar22 * 4),0,(local_b0 - uVar22) * 4 + 4);
                    puVar4[2] = local_b0 + 1;
                  }
                  piVar6 = *(int **)(puVar4[3] + local_b0 * 4);
                  iVar20 = ((int (*)())FUN_00113d94)(piVar6);
                }
                else {
                  puVar12 = (undefined4 *)FUN_001a7f7c(puVar23,local_b0);
                  piVar6 = (int *)*puVar12;
                  iVar20 = ((int (*)())FUN_00113d94)(piVar6);
                }
                if (local_b4 == iVar20) break;
LAB_00117588:
                local_b0 = local_b0 + 1;
                if ((int)puVar4[2] <= (int)local_b0) goto LAB_001178f9;
              }
              local_a8 = 0;
              local_84 = (undefined4 *)PTR_DAT_0021345d;
              cVar3 = ((int (*)())FUN_00113de6)(piVar6,0);
              local_88 = piVar6;
              if (cVar3 != '\0') goto LAB_0011765a;
              do {
                do {
                  local_a8 = local_a8 + 1;
                  local_88 = local_88 + 1;
                  local_84 = local_84 + 1;
                  if (local_a8 == 4) goto LAB_00117588;
                  cVar3 = ((int (*)())FUN_00113de6)(piVar6,local_a8);
                } while (cVar3 == '\0');
LAB_0011765a:
                local_a4 = 0;
                do {
                  iVar20 = FUN_0010b0f4(*local_b8,0);
                  if (*(char *)(local_a4 + 0x10 + iVar20) != '\x01') {
                    iVar20 = local_b8[local_a4 + 1];
                    *(undefined1 *)(local_a4 + 0x9c + *local_b8) = 1;
                    local_b8[local_a4 + 1] = 0;
                    local_b8[5] = local_b8[5] + -1;
                    goto LAB_00117693;
                  }
                  local_a4 = local_a4 + 1;
                } while (local_a4 != 4);
                local_a4 = -1;
                iVar20 = 0;
LAB_00117693:
                iVar17 = *(int *)(*local_b8 + 0x94);
                iVar14 = FUN_0010a1c2(*local_b8,*(undefined4 *)(param_1 + 8),0);
                uVar5 = *(undefined4 *)(*piVar6 + 0x94);
                iVar15 = FUN_0010b0f4(iVar14,0);
                *(undefined4 *)(iVar15 + 8) = uVar5;
                *(undefined4 *)(iVar14 + 0x9c) = *local_84;
                iVar15 = FUN_0010b0f4(*local_b8,1);
                uVar5 = *(undefined4 *)
                         (PTR_DAT_00213485 + (uint)*(byte *)(local_a4 + 0x10 + iVar15) * 4);
                iVar15 = FUN_0010b0f4(iVar14,1);
                *(undefined4 *)(iVar15 + 0x10) = uVar5;
                FUN_000f0b74(param_1,iVar14);
                *(int *)(param_1 + 0x230) = *(int *)(param_1 + 0x230) + -1;
                uVar5 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
                puVar12 = (undefined4 *)FUN_001a7bca(uVar5,0x30);
                *puVar12 = uVar5;
                FUN_00113c88(puVar12 + 1,iVar14);
                puVar12[6] = 1;
                puVar12[local_a8 + 2] = iVar20;
                uVar22 = puVar11[2];
                if (uVar22 < *local_134) {
                  _memset((void *)(uVar22 * 4 + puVar11[3]),0,4);
                  puVar11[2] = uVar22 + 1;
                  puVar16 = (undefined4 *)(uVar22 * 4 + puVar11[3]);
                }
                else {
                  puVar16 = (undefined4 *)FUN_001a7f7c(local_134,uVar22);
                }
                *puVar16 = puVar12 + 1;
                uVar5 = *(undefined4 *)(iVar14 + 0x94);
                local_88[7] = 1;
                puVar26 = *(uint **)(param_1 + 0x40c);
                if (puVar26[1] != 0) {
                  uVar22 = 0;
                  do {
                    if (uVar22 < *puVar26) {
                      uVar19 = puVar26[1];
                      if (uVar19 <= uVar22) {
                        _memset((void *)(puVar26[2] + uVar19 * 4),0,(uVar22 - uVar19) * 4 + 4);
                        puVar26[1] = uVar22 + 1;
                      }
                      iVar20 = *(int *)(puVar26[2] + uVar22 * 4);
                      if (param_2 == *(int *)(iVar20 + 0x1c)) goto LAB_0011788c;
LAB_0011785f:
                      puVar26 = *(uint **)(param_1 + 0x40c);
                      if (puVar26[1] <= uVar22 + 1) break;
                    }
                    else {
                      piVar9 = (int *)FUN_001a7f7c(puVar26,uVar22);
                      iVar20 = *piVar9;
                      if (param_2 != *(int *)(iVar20 + 0x1c)) goto LAB_0011785f;
LAB_0011788c:
                      if ((iVar17 != *(int *)(iVar20 + 0x14)) ||
                         (local_a4 != *(int *)(iVar20 + 0x18))) goto LAB_0011785f;
                      *(undefined4 *)(iVar20 + 0x14) = uVar5;
                      *(int *)(iVar20 + 0x18) = local_a8;
                      puVar26 = *(uint **)(param_1 + 0x40c);
                      if (puVar26[1] <= uVar22 + 1) break;
                    }
                    uVar22 = uVar22 + 1;
                  } while( true );
                }
              } while (local_b8[5] != 0);
              local_b4 = 0;
              local_b0 = local_b0 + 1;
            } while ((int)local_b0 < (int)puVar4[2]);
          }
LAB_001178f9:
          local_b4 = local_b4 + -1;
        } while (0 < local_b4);
      }
    }
    uVar5 = *(undefined4 *)(param_1 + 0x39c);
    if (puVar4[2] != 0) {
      uVar22 = 0;
      do {
        if (uVar22 < *puVar23) {
          uVar19 = puVar4[2];
          if (uVar19 <= uVar22) {
            _memset((void *)(puVar4[3] + uVar19 * 4),0,(uVar22 - uVar19) * 4 + 4);
            puVar4[2] = uVar22 + 1;
          }
          FUN_000e9512(uVar5,**(undefined4 **)(puVar4[3] + uVar22 * 4));
          if ((uint)puVar4[2] <= uVar22 + 1) break;
        }
        else {
          puVar11 = (undefined4 *)FUN_001a7f7c(puVar23,uVar22);
          FUN_000e9512(uVar5,*(undefined4 *)*puVar11);
          if ((uint)puVar4[2] <= uVar22 + 1) break;
        }
        uVar22 = uVar22 + 1;
      } while( true );
    }
    piVar6 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    cVar3 = (**(code **)(*piVar6 + 0xc4))(piVar6);
    if ((cVar3 != '\0') && (local_134[1] != 0)) {
      uVar22 = 0;
      do {
        if (uVar22 < *local_134) {
          uVar19 = local_134[1];
          if (uVar19 <= uVar22) {
            _memset((void *)(local_134[2] + uVar19 * 4),0,(uVar22 - uVar19) * 4 + 4);
            local_134[1] = uVar22 + 1;
          }
          puVar11 = (undefined4 *)(local_134[2] + uVar22 * 4);
        }
        else {
          puVar11 = (undefined4 *)FUN_001a7f7c(local_134,uVar22);
        }
        uVar22 = uVar22 + 1;
        FUN_000e9512(uVar5,*(undefined4 *)*puVar11);
      } while (uVar22 < local_134[1]);
    }
    uVar22 = param_3[1];
    while ((uVar22 != 0 && (FUN_001a7f3c(param_3,0), param_3[1] != 0))) {
      FUN_001a7f3c(param_3,0);
      uVar22 = param_3[1];
    }
    if (puVar4[2] != 0) {
      uVar22 = 0;
      do {
        if (uVar22 < *puVar23) {
          uVar19 = puVar4[2];
          if (uVar19 <= uVar22) {
            _memset((void *)(puVar4[3] + uVar19 * 4),0,(uVar22 - uVar19) * 4 + 4);
            puVar4[2] = uVar22 + 1;
          }
          local_98 = (undefined4 *)(puVar4[3] + uVar22 * 4);
          uVar19 = param_3[1];
          if (uVar19 < *param_3) goto LAB_00116662;
LAB_001166eb:
          local_54 = uVar22 + 1;
          puVar11 = (undefined4 *)FUN_001a7f7c(param_3,uVar19);
          *puVar11 = *local_98;
          if ((uint)puVar4[2] <= local_54) break;
        }
        else {
          local_98 = (undefined4 *)FUN_001a7f7c(puVar23,uVar22);
          uVar19 = param_3[1];
          if (*param_3 <= uVar19) goto LAB_001166eb;
LAB_00116662:
          local_54 = uVar22 + 1;
          _memset((void *)(uVar19 * 4 + param_3[2]),0,4);
          param_3[1] = uVar19 + 1;
          *(undefined4 *)(uVar19 * 4 + param_3[2]) = *local_98;
          if ((uint)puVar4[2] <= local_54) break;
        }
        local_54 = uVar22 + 1;
        uVar22 = local_54;
      } while( true );
    }
    piVar6 = *(int **)(*(int *)(param_1 + 8) + 0x54);
    cVar3 = (**(code **)(*piVar6 + 0xc4))(piVar6);
    if ((cVar3 != '\0') && (local_134[1] != 0)) {
      local_50 = 0;
      do {
        if (local_50 < *local_134) {
          uVar22 = local_134[1];
          if (uVar22 <= local_50) {
            _memset((void *)(local_134[2] + uVar22 * 4),0,(local_50 - uVar22) * 4 + 4);
            local_134[1] = local_50 + 1;
          }
          local_94 = (undefined4 *)(local_134[2] + local_50 * 4);
          uVar22 = param_3[1];
          if (uVar22 < *param_3) goto LAB_00116779;
LAB_00116807:
          puVar4 = (undefined4 *)FUN_001a7f7c(param_3,uVar22);
        }
        else {
          local_94 = (undefined4 *)FUN_001a7f7c(local_134,local_50);
          uVar22 = param_3[1];
          if (*param_3 <= uVar22) goto LAB_00116807;
LAB_00116779:
          _memset((void *)(uVar22 * 4 + param_3[2]),0,4);
          param_3[1] = uVar22 + 1;
          puVar4 = (undefined4 *)(uVar22 * 4 + param_3[2]);
        }
        local_50 = local_50 + 1;
        *puVar4 = *local_94;
      } while (local_50 < local_134[1]);
    }
  }
  return;
LAB_00116969:
  uVar22 = uVar22 + 1;
  if ((int)puVar11[2] <= (int)uVar22) goto LAB_00116366;
  goto LAB_0011697b;
}

/* FUN_00117f44 @ 0x117f44 (2103 bytes) */
int FUN_00117f44(param_1)
  int param_1;
{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint local_b4;
  int *local_a0;
  int local_9c;
  uint local_90;
  int local_7c;
  int local_78;
  int local_74;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_54 [4];
  undefined4 auStack_44 [4];
  undefined4 auStack_34 [4];
  int local_24;
  undefined1 local_20 [16];
  
  local_a0 = *(int **)(param_1 + 0x398);
  if (local_a0 == (int *)0x0) {
    local_a0 = *(int **)(param_1 + 0x394);
  }
  uVar6 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xbc);
  puVar5 = (undefined4 *)FUN_001a7bca(uVar6,0x14);
  *puVar5 = uVar6;
  puVar1 = puVar5 + 1;
  puVar5[4] = uVar6;
  puVar5[2] = 0;
  puVar5[1] = 2;
  uVar6 = FUN_001a7bca(uVar6,8);
  puVar5[3] = uVar6;
  piVar12 = (int *)local_a0[0x26];
  if (piVar12[2] == 0) {
    local_9c = 0;
  }
  else {
    local_9c = 0;
    do {
      if (((*(byte *)(piVar12 + 5) & 1) != 0) &&
         (cVar4 = (**(code **)(*piVar12 + 0x4c))(piVar12), cVar4 != '\0')) {
        iVar7 = (**(code **)(*piVar12 + 0x80))(piVar12);
        iVar8 = *(int *)(iVar7 + 0x144);
        if (((*(char *)(param_1 + 0x3d8) == '\0') ||
            (((iVar8 != *(int *)(param_1 + 1000) ||
              (*(int *)(iVar7 + 0x148) < *(int *)(param_1 + 0x3dc))) ||
             (*(int *)(param_1 + 0x3e0) <= *(int *)(iVar7 + 0x148))))) &&
           ((((iVar8 == 0x24 || (iVar8 == 0x15)) && (iVar8 = FUN_000f60f4(iVar7), iVar8 != 4)) &&
            (iVar8 = FUN_000f60f4(iVar7), iVar8 != 0)))) {
          local_9c = local_9c + 1;
          uVar15 = puVar5[2];
          if (uVar15 < *puVar1) {
            _memset((void *)(uVar15 * 4 + puVar5[3]),0,4);
            puVar5[2] = uVar15 + 1;
            piVar9 = (int *)(uVar15 * 4 + puVar5[3]);
          }
          else {
            piVar9 = (int *)FUN_001a7f7c(puVar1,uVar15);
          }
          *piVar9 = iVar7;
        }
      }
      piVar12 = (int *)piVar12[2];
    } while (piVar12[2] != 0);
  }
  FUN_001a7e60(puVar1,FUN_00113a52);
  if (local_9c < 1) {
LAB_001180fa:
    if (puVar1 != (uint *)0x0) {
      FUN_001a7aba(puVar5[4],puVar5[3]);
      FUN_001a7aba(*puVar5,puVar5);
    }
    return;
  }
  local_90 = 0;
  if (*puVar1 == 0) goto LAB_0011859a;
LAB_00118163:
  uVar15 = puVar5[2];
  if (uVar15 <= local_90) {
    _memset((void *)(puVar5[3] + uVar15 * 4),0,(local_90 - uVar15) * 4 + 4);
    puVar5[2] = local_90 + 1;
  }
  piVar12 = (int *)(puVar5[3] + local_90 * 4);
  do {
    local_b4 = local_90 + 1;
    iVar8 = *piVar12;
    if (iVar8 != 0) {
      local_78 = 0;
      iVar7 = 0;
      do {
        iVar10 = FUN_0010b0f4(iVar8,0);
        if (*(char *)(iVar7 + 0x10 + iVar10) != '\x01') {
          uVar6 = FUN_0010a7c6(iVar8,iVar7);
          auStack_34[local_78] = uVar6;
          uVar6 = FUN_0010a038(iVar8,iVar7);
          auStack_44[local_78] = uVar6;
          local_20[local_78] = (char)iVar7;
          local_78 = local_78 + 1;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 != 4);
      iVar7 = *(int *)(iVar8 + 0x144);
      uVar6 = *(undefined4 *)(iVar8 + 0x148);
      iVar10 = *(int *)(iVar8 + 0x13c);
      iVar2 = *(int *)(iVar8 + 0x140);
      local_54[0] = iVar8;
      if ((int)local_b4 < local_9c) {
        local_64 = local_b4 * 4;
        local_60 = local_90 + 2;
        local_7c = 1;
        do {
          uVar15 = local_60 - 1;
          if (uVar15 < *puVar1) {
            uVar3 = puVar5[2];
            if (uVar3 <= uVar15) {
              _memset((void *)(puVar5[3] + uVar3 * 4),0,(uVar15 - uVar3) * 4 + 4);
              puVar5[2] = local_60;
            }
            piVar12 = (int *)(local_64 + puVar5[3]);
          }
          else {
            piVar12 = (int *)FUN_001a7f7c(puVar1,uVar15);
          }
          iVar8 = *piVar12;
          if (((iVar8 != 0) && (iVar11 = FUN_000f60f4(iVar8), iVar11 + local_78 < 5)) &&
             ((*(int *)(iVar8 + 0x144) == iVar7 &&
              ((iVar10 == *(int *)(iVar8 + 0x13c) && (iVar2 == *(int *)(iVar8 + 0x140))))))) {
            local_74 = 0;
            do {
              iVar11 = FUN_0010b0f4(iVar8,0);
              if (*(char *)(local_74 + 0x10 + iVar11) != '\x01') {
                uVar13 = FUN_0010a7c6(iVar8,local_74);
                auStack_34[local_78] = uVar13;
                uVar13 = FUN_0010a038(iVar8,local_74);
                auStack_44[local_78] = uVar13;
                local_20[local_78] = (undefined1)local_74;
                local_78 = local_78 + 1;
              }
              local_74 = local_74 + 1;
            } while (local_74 != 4);
            local_54[local_7c] = iVar8;
            local_7c = local_7c + 1;
            if (uVar15 < *puVar1) {
              uVar3 = puVar5[2];
              if (uVar3 <= uVar15) {
                _memset((void *)(puVar5[3] + uVar3 * 4),0,(uVar15 - uVar3) * 4 + 4);
                puVar5[2] = local_60;
              }
              puVar14 = (undefined4 *)(local_64 + puVar5[3]);
            }
            else {
              puVar14 = (undefined4 *)FUN_001a7f7c(puVar1,uVar15);
            }
            *puVar14 = 0;
            if (local_78 == 4) break;
          }
          local_64 = local_64 + 4;
          local_60 = local_60 + 1;
        } while (local_60 != local_9c + 1);
        if (1 < local_7c) {
          uVar13 = *(undefined4 *)(*(int *)(param_1 + 8) + 0xb8);
          puVar14 = (undefined4 *)FUN_001a7bca(uVar13,0x168);
          *puVar14 = uVar13;
          piVar12 = puVar14 + 1;
          FUN_0010e6e2(piVar12,*(undefined4 *)(param_1 + 8));
          puVar14[0x52] = iVar7;
          puVar14[0x53] = uVar6;
          puVar14[0x51] = iVar2;
          puVar14[0x50] = iVar10;
          puVar14[0x26] = uVar6;
          puVar14[0x27] = iVar7;
          if (0 < local_78) {
            iVar8 = 0;
            piVar9 = piVar12;
            do {
              *(undefined1 *)(piVar9 + 0x27) = 0;
              (**(code **)(*piVar12 + 0x88))(piVar12,1,iVar8,local_20[iVar8]);
              FUN_00109fa4(piVar12,iVar8,3,auStack_34[iVar8],auStack_44[iVar8]);
              iVar8 = iVar8 + 1;
              piVar9 = (int *)((int)piVar9 + 1);
            } while (local_78 != iVar8);
          }
          puVar14[0x59] = local_7c + *(int *)(param_1 + 0x46c);
          (**(code **)(*local_a0 + 0xc))(local_a0,piVar12);
          local_6c = 0;
          local_68 = 0;
          do {
            piVar9 = (int *)local_54[local_68];
            iVar8 = FUN_0010b0f4(piVar9,0);
            local_24 = *(int *)(iVar8 + 0x10);
            iVar8 = piVar9[0x58] - *(int *)(param_1 + 0x46c);
            if (iVar8 < 0) {
              iVar8 = 0;
            }
            FUN_001a7d72(piVar9);
            FUN_0010db52(piVar9,0x31,*(undefined4 *)(param_1 + 8));
            piVar9[0x25] = piVar9[0x53];
            piVar9[0x26] = 0;
            piVar9[0x27] = local_24;
            piVar9[0x58] = iVar8 + *(int *)(param_1 + 0x46c);
            iVar8 = 0;
            do {
              if (local_20[iVar8 + -4] == '\x01') {
                (**(code **)(*piVar9 + 0x88))(piVar9,1,iVar8,4);
              }
              else {
                (**(code **)(*piVar9 + 0x88))(piVar9,1,iVar8,local_6c);
                local_6c = local_6c + 1;
              }
              iVar8 = iVar8 + 1;
            } while (iVar8 != 4);
            FUN_0010ba02(piVar9,1,piVar12,0,*(undefined4 *)(param_1 + 8));
            FUN_000e9512(local_a0,piVar9);
            local_68 = local_68 + 1;
          } while (local_7c != local_68);
        }
      }
    }
    local_90 = local_b4;
    if (local_9c <= (int)local_b4) goto LAB_001180fa;
    if (local_b4 < *puVar1) goto LAB_00118163;
LAB_0011859a:
    piVar12 = (int *)FUN_001a7f7c(puVar1,local_90);
  } while( true );
}

/* FUN_001187c0 @ 0x1187c0 (1907 bytes) */
int FUN_001187c0(param_1, param_2)
  int *param_1;
  int param_2;
{
  code *pcVar1;
  uint uVar2;
  int *piVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  uint uVar15;
  int local_6c;
  int *local_68;
  int *local_64;
  uint local_5c;
  undefined4 local_58;
  uint local_50;
  uint local_4c;
  int local_48;
  uint local_44;
  uint local_40;
  undefined4 local_34 [4];
  undefined1 local_24 [4];
  int local_20 [4];
  
  piVar8 = *(int **)(*(int *)(param_2 + 0x39c) + 0x98);
  if (piVar8[2] == 0) {
    local_68 = (int *)0x0;
    local_64 = (int *)0x0;
  }
  else {
    local_68 = (int *)0x0;
    local_64 = (int *)0x0;
    do {
      while (((piVar3 = local_68, (*(byte *)(piVar8 + 5) & 1) == 0 ||
              (cVar4 = (**(code **)(*piVar8 + 0x68))(piVar8), cVar4 == '\0')) ||
             (piVar3 = piVar8, piVar8[0x4f] == 6))) {
        local_68 = piVar3;
        piVar8 = (int *)piVar8[2];
        if (piVar8[2] == 0) goto LAB_0011883c;
      }
      if (piVar8[0x4f] == 7) {
        local_64 = piVar8;
      }
      piVar8 = (int *)piVar8[2];
    } while (piVar8[2] != 0);
  }
LAB_0011883c:
  local_20[0] = 0;
  uVar7 = *(undefined4 *)(param_2 + 8);
  if (local_68 != (int *)0x0) {
    local_68[0x25] = 0;
    local_68[0x26] = 5;
    local_20[0] = 1;
    pcVar1 = *(code **)(*param_1 + 0x54);
    uVar5 = FUN_00109f54(local_68,0);
    uVar6 = FUN_00109f54(local_68,0);
    (*pcVar1)(param_1,0,0,uVar6,DAT_001cbed8,0,0,0,0xf,uVar5,DAT_001cbedc,param_2);
  }
  if (local_64 != (int *)0x0) {
    local_64[0x25] = 1;
    local_64[0x26] = 5;
    local_20[0] = local_20[0] + 1;
    pcVar1 = *(code **)(*param_1 + 0x54);
    uVar5 = FUN_00109f54(local_64,0);
    uVar6 = FUN_00109f54(local_64,0);
    (*pcVar1)(param_1,1,1,uVar6,DAT_001cbed8,0,0,0,0xf,uVar5,DAT_001cbedc,param_2);
  }
  cVar4 = ((int (*)())FUN_001148f2)(param_2);
  *(char *)(param_2 + 0x3d8) = cVar4;
  if (cVar4 == '\0') {
    FUN_001a7e60(*(undefined4 *)(param_2 + 0x414),FUN_00113cd2);
    puVar14 = *(uint **)(param_2 + 0x414);
    if (puVar14[1] != 0) {
      uVar15 = 0;
      local_4c = 1;
      local_48 = 0;
      do {
        if (uVar15 < *puVar14) {
          uVar2 = puVar14[1];
          if (uVar2 <= uVar15) {
            _memset((void *)(puVar14[2] + uVar2 * 4),0,(uVar15 - uVar2) * 4 + 4);
            puVar14[1] = local_4c;
          }
          local_58 = *(undefined4 *)(**(int **)(local_48 + puVar14[2]) + 0x140);
          if (*puVar14 <= uVar15) goto LAB_00118cf9;
LAB_00118c92:
          uVar2 = puVar14[1];
          if (uVar2 <= uVar15) {
            _memset((void *)(puVar14[2] + uVar2 * 4),0,(uVar15 - uVar2) * 4 + 4);
            puVar14[1] = local_4c;
          }
          puVar11 = (undefined4 *)(local_48 + puVar14[2]);
        }
        else {
          puVar11 = (undefined4 *)FUN_001a7f7c(puVar14,uVar15);
          local_58 = *(undefined4 *)(*(int *)*puVar11 + 0x140);
          if (uVar15 < *puVar14) goto LAB_00118c92;
LAB_00118cf9:
          puVar11 = (undefined4 *)FUN_001a7f7c(puVar14,uVar15);
        }
        iVar10 = FUN_001139a8(*(undefined4 *)(*(int *)*puVar11 + 0x13c),local_58);
        if (iVar10 - 2U < 2) {
          cVar4 = FUN_000e1402(uVar7,0x3f);
          iVar10 = local_20[0];
          if (cVar4 == '\0') {
            local_20[0] = local_20[0] + 4;
            puVar14 = *(uint **)(param_2 + 0x414);
            if (puVar14[1] != 0) {
              local_44 = 0;
              do {
                if (local_44 < *puVar14) {
                  uVar15 = puVar14[1];
                  if (uVar15 <= local_44) {
                    _memset((void *)(puVar14[2] + uVar15 * 4),0,(local_44 - uVar15) * 4 + 4);
                    puVar14[1] = local_44 + 1;
                  }
                  puVar11 = (undefined4 *)(puVar14[2] + local_44 * 4);
                }
                else {
                  puVar11 = (undefined4 *)FUN_001a7f7c(puVar14,local_44);
                }
                local_44 = local_44 + 1;
                piVar8 = (int *)*puVar11;
                iVar9 = *piVar8;
                iVar12 = FUN_001139a8(*(undefined4 *)(iVar9 + 0x13c),*(undefined4 *)(iVar9 + 0x140))
                ;
                if (iVar12 < 4) {
                  *(int *)(iVar9 + 0x94) = iVar12 + iVar10;
                  *(undefined4 *)(iVar9 + 0x98) = 5;
                }
                else {
                  iVar9 = *piVar8;
                  *(int *)(iVar9 + 0x94) = local_20[0];
                  *(undefined4 *)(iVar9 + 0x98) = 5;
                  local_20[0] = local_20[0] + 1;
                }
                puVar14 = *(uint **)(param_2 + 0x414);
              } while (local_44 < puVar14[1]);
            }
          }
          else {
            ((int (*)())FUN_00114f20)(*(undefined4 *)(param_2 + 0x414),local_20,param_2);
          }
          goto LAB_00118d2e;
        }
        uVar15 = uVar15 + 1;
        local_4c = local_4c + 1;
        local_48 = local_48 + 4;
      } while (uVar15 < puVar14[1]);
      puVar14 = *(uint **)(param_2 + 0x414);
    }
    ((int (*)())FUN_001151a8)(2,puVar14,local_20,param_2);
LAB_00118d2e:
    ((int (*)())FUN_001151a8)(3,*(undefined4 *)(param_2 + 0x418),local_20,param_2);
    FUN_001a7e60(*(undefined4 *)(param_2 + 0x410),FUN_00113d26);
    ((int (*)())FUN_001151a8)(1,*(undefined4 *)(param_2 + 0x410),local_20,param_2);
  }
  else {
    *(int *)(param_2 + 0x3e4) = local_20[0] - *(int *)(param_2 + 0x3dc);
    ((int (*)())FUN_00115080)(2,*(undefined4 *)(param_2 + 0x414),local_20,param_2);
    ((int (*)())FUN_00115080)(3,*(undefined4 *)(param_2 + 0x418),local_20,param_2);
    ((int (*)())FUN_00115080)(1,*(undefined4 *)(param_2 + 0x410),local_20,param_2);
  }
  *(int *)(param_2 + 0x234) = local_20[0] + 1;
  local_5c = 0;
  local_40 = 0;
  do {
    puVar14 = *(uint **)(param_2 + 0x40c);
    if (puVar14[1] <= local_40) {
      return;
    }
    if (local_40 < *puVar14) {
      uVar15 = puVar14[1];
      puVar13 = puVar14;
      if (uVar15 <= local_40) {
        _memset((void *)(puVar14[2] + uVar15 * 4),0,(local_40 - uVar15) * 4 + 4);
        puVar14[1] = local_40 + 1;
        puVar13 = *(uint **)(param_2 + 0x40c);
      }
      piVar8 = (int *)(puVar14[2] + local_40 * 4);
    }
    else {
      piVar8 = (int *)FUN_001a7f7c(puVar14,local_40);
      puVar13 = *(uint **)(param_2 + 0x40c);
    }
    local_50 = local_40 + 1;
    iVar10 = *piVar8;
    local_5c = local_5c | 1 << ((byte)*(int *)(iVar10 + 0x10) & 0x1f);
    local_34[*(int *)(iVar10 + 0x10)] = *(undefined4 *)(iVar10 + 0x14);
    local_24[*(int *)(iVar10 + 0x10)] = (char)*(undefined4 *)(iVar10 + 0x18);
    if (puVar13[1] == local_50) {
      local_6c = *(int *)(iVar10 + 4);
      iVar10 = *(int *)(iVar10 + 8);
LAB_00118ad2:
      pcVar1 = *(code **)(*param_1 + 0x58);
      uVar7 = FUN_00113a80(local_6c,iVar10);
      uVar5 = FUN_000edb5e(param_2,local_6c);
      (*pcVar1)(param_1,local_34,local_24,uVar5,uVar7,local_5c);
      local_5c = 0;
    }
    else {
      if (local_50 < *puVar13) {
        uVar15 = puVar13[1];
        if (uVar15 <= local_50) {
          _memset((void *)(puVar13[2] + uVar15 * 4),0,(local_50 - uVar15) * 4 + 4);
          puVar13[1] = local_40 + 2;
        }
        iVar9 = *(int *)(puVar13[2] + local_50 * 4);
        local_6c = *(int *)(iVar10 + 4);
        if (local_6c != *(int *)(iVar9 + 4)) {
LAB_00118acf:
          iVar10 = *(int *)(iVar10 + 8);
          goto LAB_00118ad2;
        }
      }
      else {
        piVar8 = (int *)FUN_001a7f7c(puVar13,local_50);
        iVar9 = *piVar8;
        local_6c = *(int *)(iVar10 + 4);
        if (local_6c != *(int *)(iVar9 + 4)) goto LAB_00118acf;
      }
      iVar10 = *(int *)(iVar10 + 8);
      if (iVar10 != *(int *)(iVar9 + 8)) goto LAB_00118ad2;
    }
    local_40 = local_50;
  } while( true );
}

/* FUN_00118f34 @ 0x118f34 (49 bytes) */
int FUN_00118f34(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x54) + 0x16c))(*(int **)(param_2 + 0x54));
  return iVar1 + 0x10 + param_1 * 0x38;
}

/* FUN_00118f66 @ 0x118f66 (20 bytes) */
int FUN_00118f66(param_1)
  int param_1;
{
  return *(undefined4 *)(&DAT_00212340 + param_1 * 4);
}

/* FUN_00118f7a @ 0x118f7a (54 bytes) */
int FUN_00118f7a(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x54) + 0x16c))(*(int **)(param_2 + 0x54));
  return *(uint *)(param_1 * 0x38 + iVar1) & 1;
}

/* FUN_00118fb0 @ 0x118fb0 (14 bytes) */
int FUN_00118fb0(param_1)
  uint param_1;
{
  return param_1 < 8;
}

/* FUN_00118fbe @ 0x118fbe (14 bytes) */
int FUN_00118fbe(param_1)
  uint param_1;
{
  return param_1 < 7;
}

/* FUN_00118fcc @ 0x118fcc (95 bytes) */
int FUN_00118fcc(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = (**(code **)(**(int **)(param_1 + 0x54) + 0x16c))(*(int **)(param_1 + 0x54));
  iVar3 = (**(code **)(**(int **)(param_1 + 0x54) + 0x40))(*(int **)(param_1 + 0x54));
  if (iVar3 < 1) {
    return 1;
  }
  if (*(int *)(iVar2 + 8) == 0) {
    piVar4 = (int *)(iVar2 + 0x40);
    iVar2 = 0;
    do {
      iVar1 = iVar2 + 1;
      if (iVar3 == iVar1) {
        return 1;
      }
      iVar2 = *piVar4;
      piVar4 = piVar4 + 0xe;
    } while (iVar2 == iVar1);
  }
  return 0;
}

/* FUN_0011902c @ 0x11902c (54 bytes) */
int FUN_0011902c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x54) + 0x16c))(*(int **)(param_2 + 0x54));
  return *(uint *)(param_1 * 0x38 + iVar1) >> 2 & 1;
}

/* FUN_00119062 @ 0x119062 (54 bytes) */
int FUN_00119062(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x54) + 0x16c))(*(int **)(param_2 + 0x54));
  return *(uint *)(param_1 * 0x38 + iVar1) >> 3 & 1;
}

/* FUN_00119098 @ 0x119098 (54 bytes) */
int FUN_00119098(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x54) + 0x16c))(*(int **)(param_2 + 0x54));
  return *(uint *)(param_1 * 0x38 + iVar1) >> 6 & 1;
}

/* FUN_001190ce @ 0x1190ce (54 bytes) */
int FUN_001190ce(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x54) + 0x16c))(*(int **)(param_2 + 0x54));
  return *(uint *)(param_1 * 0x38 + iVar1) >> 7 & 1;
}

/* FUN_00119104 @ 0x119104 (54 bytes) */
int FUN_00119104(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x54) + 0x16c))(*(int **)(param_2 + 0x54));
  return *(uint *)(param_1 * 0x38 + iVar1) >> 8 & 1;
}

/* FUN_0011913a @ 0x11913a (54 bytes) */
int FUN_0011913a(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x54) + 0x16c))(*(int **)(param_2 + 0x54));
  return *(uint *)(param_1 * 0x38 + iVar1) >> 9 & 1;
}

/* FUN_00119170 @ 0x119170 (54 bytes) */
int FUN_00119170(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x54) + 0x16c))(*(int **)(param_2 + 0x54));
  return *(uint *)(param_1 * 0x38 + iVar1) >> 10 & 1;
}

/* FUN_001191a6 @ 0x1191a6 (54 bytes) */
int FUN_001191a6(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x54) + 0x16c))(*(int **)(param_2 + 0x54));
  return *(uint *)(param_1 * 0x38 + iVar1) >> 0xc & 1;
}

/* FUN_001191dc @ 0x1191dc (54 bytes) */
int FUN_001191dc(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x54) + 0x16c))(*(int **)(param_2 + 0x54));
  return *(uint *)(param_1 * 0x38 + iVar1) >> 0xd & 1;
}

/* FUN_00119212 @ 0x119212 (49 bytes) */
int FUN_00119212(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x54) + 0x16c))(*(int **)(param_2 + 0x54));
  return *(undefined4 *)(param_1 * 0x38 + 4 + iVar1);
}

/* FUN_00119244 @ 0x119244 (49 bytes) */
int FUN_00119244(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x54) + 0x16c))(*(int **)(param_2 + 0x54));
  return *(undefined4 *)(param_1 * 0x38 + 0x30 + iVar1);
}

/* FUN_00119276 @ 0x119276 (49 bytes) */
int FUN_00119276(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x54) + 0x16c))(*(int **)(param_2 + 0x54));
  return *(undefined4 *)(param_1 * 0x38 + 0xc + iVar1);
}

/* FUN_001192a8 @ 0x1192a8 (49 bytes) */
int FUN_001192a8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_2 + 0x54) + 0x16c))(*(int **)(param_2 + 0x54));
  return *(undefined4 *)(param_1 * 0x38 + 0x34 + iVar1);
}

/* FUN_001192da @ 0x1192da (58 bytes) */
int FUN_001192da(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(**(int **)(param_1 + 0x54) + 0x16c))(*(int **)(param_1 + 0x54));
  return *(uint *)(*(int *)(*(int *)(param_2 + 0x88) + 8) * 0x38 + iVar1) >> 2 & 1;
}

/* FUN_00119314 @ 0x119314 (125 bytes) */
int FUN_00119314(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  char cVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0xc) == 0) &&
     (cVar1 = ((int (*)())FUN_001192da)(*(undefined4 *)(param_3 + 8),param_2), cVar1 != '\0')) {
    return 1;
  }
  iVar2 = *(int *)(param_1 + 0xc);
  if (iVar2 == 0x10) {
    cVar1 = (**(code **)(*param_2 + 0x30))(param_2);
    if (cVar1 == '\0') {
      cVar1 = ((int (*)())FUN_001192da)(*(undefined4 *)(param_3 + 8),param_2);
      if (cVar1 != '\0') {
        return 1;
      }
      return 0;
    }
    iVar2 = 9;
  }
  return iVar2;
}

/* FUN_00119392 @ 0x119392 (37 bytes) */
int FUN_00119392()
{
  float in_XMM0_Da;
  float in_XMM1_Da;
  
  if ((in_XMM0_Da == 0.0) && (!NAN(in_XMM0_Da))) {
    return;
  }
  if ((in_XMM1_Da == 0.0) && (!NAN(in_XMM1_Da))) {
    return;
  }
  return;
}

/* FUN_001193b8 @ 0x1193b8 (38 bytes) */
int FUN_001193b8(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_2 + 0x84) = 3;
  *(undefined4 *)(param_1 + 4) = 9;
  return;
}

/* FUN_001193de @ 0x1193de (38 bytes) */
int FUN_001193de(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(undefined4 *)(param_1 + 4) = 6;
  return;
}

/* FUN_00119404 @ 0x119404 (55 bytes) */
int FUN_00119404(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 300) = 0;
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 1;
  return;
}

/* FUN_0011943c @ 0x11943c (66 bytes) */
int FUN_0011943c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18;
  FUN_000f0b74(*(undefined4 *)(param_3 + 0x3f4),param_2);
  *(undefined4 *)(param_1 + 4) = 7;
  return;
}

/* FUN_0011947e @ 0x11947e (66 bytes) */
int FUN_0011947e(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined4 *)(param_2 + 0x80) = 0;
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18;
  FUN_000f0b74(*(undefined4 *)(param_3 + 0x3f4),param_2);
  *(undefined4 *)(param_1 + 4) = 8;
  return;
}

/* FUN_001194c0 @ 0x1194c0 (69 bytes) */
int FUN_001194c0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18018;
  FUN_000f0b74(*(undefined4 *)(param_3 + 0x3f4),param_2);
  *(undefined4 *)(param_1 + 4) = 5;
  return;
}

/* FUN_00119506 @ 0x119506 (45 bytes) */
int FUN_00119506(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x80) = 1;
  *(undefined4 *)(param_2 + 0x84) = 1;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 3;
  return;
}

/* FUN_00119534 @ 0x119534 (45 bytes) */
int FUN_00119534(param_1, param_2)
  int param_1;
  int param_2;
{
  *(undefined4 *)(param_2 + 0x80) = 0;
  *(undefined4 *)(param_2 + 0x84) = 0;
  *(uint *)(param_2 + 0x14) = *(uint *)(param_2 + 0x14) | 0x18000;
  *(undefined4 *)(param_1 + 4) = 2;
  return;
}

/* FUN_00119562 @ 0x119562 (68 bytes) */
int FUN_00119562(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x54);
  if ((*(byte *)(piVar1 + 2) & 0x10) == 0) {
    return 0;
  }
  iVar2 = (**(code **)(*piVar1 + 0x16c))(piVar1);
  return *(uint *)(*(int *)(*(int *)(param_2 + 0x88) + 8) * 0x38 + iVar2) >> 2 & 1;
}

/* FUN_001195a6 @ 0x1195a6 (98 bytes) */
int FUN_001195a6(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = (**(code **)(**(int **)(param_1 + 0x54) + 0x16c))(*(int **)(param_1 + 0x54));
  iVar1 = *(int *)(*(int *)(param_2 + 0x88) + 8);
  cVar2 = ((int (*)())FUN_001190ce)(iVar1,param_1);
  if ((cVar2 == '\0') && ((*(byte *)(iVar1 * 0x38 + iVar3) & 2) != 0)) {
    return 1;
  }
  return 0;
}

/* FUN_00119608 @ 0x119608 (25 bytes) */
int FUN_00119608()
{
  DAT_002119d4 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_00119622 @ 0x119622 (25 bytes) */
int FUN_00119622()
{
  DAT_002119c0 = PTR_DAT_00213819 + 8;
  return;
}

/* FUN_0011963c @ 0x11963c (25 bytes) */
int FUN_0011963c()
{
  DAT_002119ac = PTR_DAT_00213819 + 8;
  return;
}

