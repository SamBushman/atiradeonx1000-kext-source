#include "decls.h"

/* FUN_00190762 @ 0x190762 (1150 bytes) */
int FUN_00190762(param_1, param_2)
  int param_1;
  int *param_2;
{
  bool bVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  char local_35;
  int local_34;
  int local_30;
  char local_1d [13];
  
  iVar6 = *(int *)(param_1 + 0xb0);
  cVar2 = FUN_00186d16(*(undefined4 *)(*(int *)(iVar6 + 0x88) + 8));
  if (cVar2 != '\0') {
    return 0;
  }
  cVar2 = FUN_00186d28(*(undefined4 *)(*(int *)(iVar6 + 0x88) + 8));
  if (cVar2 == '\0') {
    cVar2 = FUN_001190ce(*(undefined4 *)(*(int *)(iVar6 + 0x88) + 8),
                         *(undefined4 *)(param_1 + 0x238));
    if ((cVar2 == '\0') ||
       (cVar2 = FUN_00119104(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                             *(undefined4 *)(param_1 + 0x238)), cVar2 == '\0')) {
      cVar2 = FUN_0011902c(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(param_1 + 0x238));
      if (cVar2 == '\0') {
        local_30 = param_1;
        local_35 = '\0';
        iVar6 = 0;
        piVar7 = param_2;
        do {
          local_1d[0] = '\0';
          cVar2 = FUN_00186f34(param_1,iVar6);
          if (cVar2 != '\0') {
            iVar3 = FUN_0018736e(param_1,iVar6,local_1d);
            *piVar7 = iVar3;
            if (iVar3 != 0x7ffffffe) {
              uVar4 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),iVar3);
              *(undefined4 *)(local_30 + 0x30) = uVar4;
            }
          }
          iVar3 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
          if ((*(char *)(iVar6 + 0x10 + iVar3) == '\0') && (local_1d[0] != '\0')) {
            local_35 = '\x01';
          }
          iVar6 = iVar6 + 1;
          piVar7 = piVar7 + 1;
          local_30 = local_30 + 4;
        } while (iVar6 != 4);
        iVar6 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(int *)(iVar6 + 0x10) != DAT_001cc720) {
          iVar6 = 0;
          piVar7 = param_2;
          do {
            iVar3 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
            if ((*(char *)(iVar6 + 0x10 + iVar3) != '\x01') && (*piVar7 == 0x7ffffffe))
            goto LAB_00190894;
            iVar6 = iVar6 + 1;
            piVar7 = piVar7 + 1;
          } while (iVar6 != 4);
          bVar1 = false;
          goto LAB_00190899;
        }
      }
      else {
        cVar2 = FUN_00186e98(param_1);
        if (cVar2 == '\0') goto LAB_00190890;
        local_1d[0] = '\0';
        iVar6 = ((float (*)())FUN_00188074)(param_1,local_1d);
        local_35 = local_1d[0];
        if (iVar6 != 0x7ffffffe) {
          uVar4 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),iVar6);
          iVar5 = 1;
          iVar3 = param_1;
          do {
            param_2[iVar5 + -1] = iVar6;
            *(undefined4 *)(iVar3 + 0x30) = uVar4;
            iVar5 = iVar5 + 1;
            iVar3 = iVar3 + 4;
          } while (iVar5 != 5);
          bVar1 = false;
          goto LAB_00190899;
        }
      }
    }
    else {
      cVar2 = FUN_0018854c(param_1);
      if (cVar2 == '\0') {
LAB_00190890:
        local_35 = '\0';
      }
      else {
        local_1d[0] = '\0';
        iVar6 = ((float (*)())FUN_001871a4)(param_1,local_1d);
        local_35 = local_1d[0];
        if (iVar6 != 0x7ffffffe) {
          uVar4 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),iVar6);
          iVar5 = 1;
          iVar3 = param_1;
          do {
            param_2[iVar5 + -1] = iVar6;
            *(undefined4 *)(iVar3 + 0x30) = uVar4;
            iVar5 = iVar5 + 1;
            iVar3 = iVar3 + 4;
          } while (iVar5 != 5);
          bVar1 = false;
          goto LAB_00190899;
        }
      }
    }
  }
  else {
    local_34 = param_1;
    local_35 = '\0';
    iVar6 = 0;
    piVar7 = param_2;
    do {
      local_1d[0] = '\0';
      cVar2 = FUN_0018864c(param_1,iVar6);
      if (cVar2 != '\0') {
        iVar3 = ((float (*)())FUN_00188214)(param_1,iVar6,local_1d);
        *piVar7 = iVar3;
        if (iVar3 != 0x7ffffffe) {
          uVar4 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),iVar3);
          *(undefined4 *)(local_34 + 0x30) = uVar4;
        }
      }
      iVar3 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
      if ((*(char *)(iVar6 + 0x10 + iVar3) == '\0') && (local_1d[0] != '\0')) {
        local_35 = '\x01';
      }
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 1;
      local_34 = local_34 + 4;
    } while (iVar6 != 4);
    iVar6 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(int *)(iVar6 + 0x10) != DAT_001cc720) {
      iVar6 = 0;
      piVar7 = param_2;
      do {
        iVar3 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
        if ((*(char *)(iVar6 + 0x10 + iVar3) != '\x01') && (*piVar7 == 0x7ffffffe))
        goto LAB_00190894;
        iVar6 = iVar6 + 1;
        piVar7 = piVar7 + 1;
      } while (iVar6 != 4);
      bVar1 = false;
      goto LAB_00190899;
    }
  }
LAB_00190894:
  bVar1 = true;
LAB_00190899:
  cVar2 = (**(code **)(**(int **)(param_1 + 0xb0) + 100))(*(int **)(param_1 + 0xb0));
  if ((cVar2 == '\0') && (!bVar1)) {
    iVar6 = FUN_00190246(param_1,param_2);
    if (iVar6 != 0) {
      FUN_00184a5a(param_1);
      return 1;
    }
    piVar7 = (int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0x138);
    *piVar7 = *piVar7 + 1;
    if ((*(char *)(*(int *)(param_1 + 0xb0) + 0x120) != '\0') && (local_35 == '\0')) {
      *(undefined1 *)(*(int *)(param_1 + 0xb0) + 0x120) = 0;
      FUN_00184a5a(param_1);
      return 0;
    }
  }
  return 0;
}

/* FUN_00190be0 @ 0x190be0 (619 bytes) */
int FUN_00190be0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  undefined4 local_24;
  undefined4 local_20;
  
  FUN_001a7d72(*(undefined4 *)(param_1 + 0xb0));
  uVar2 = *(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c);
  iVar11 = FUN_0010b0f4(*(int *)(param_1 + 0xb0),0);
  uVar3 = *(undefined4 *)(iVar11 + 0x10);
  iVar11 = *(int *)(param_1 + 0xb0);
  uVar1 = *(undefined1 *)(iVar11 + 0x120);
  uVar4 = *(undefined4 *)(param_2 * 0x18 + 0x8c + iVar11);
  iVar11 = FUN_0010b0f4(iVar11,param_2);
  uVar5 = *(undefined4 *)(iVar11 + 0x10);
  iVar11 = *(int *)(param_1 + 0xb0);
  uVar6 = *(uint *)(param_2 * 0x18 + 0xa0 + iVar11);
  uVar7 = *(undefined4 *)(param_1 + 0x210 + param_2 * 4);
  uVar8 = *(uint *)(iVar11 + 0x14);
  uVar12 = uVar8 >> 9;
  if ((uVar12 & 1) == 0) {
    local_24 = 0;
    local_20 = 0;
  }
  else {
    local_24 = *(undefined4 *)(param_1 + 0x210 + *(int *)(iVar11 + 0x84) * 4);
    local_20 = *(undefined4 *)(iVar11 + 0x8c + *(int *)(iVar11 + 0x84) * 0x18);
  }
  uVar9 = *(undefined4 *)(iVar11 + 0x94);
  uVar10 = *(undefined4 *)(iVar11 + 0x98);
  FUN_0010db52(iVar11,0x31,*(undefined4 *)(param_1 + 0x238));
  FUN_0010a3c2(iVar11,0,uVar2);
  *(undefined4 *)(iVar11 + 0x94) = uVar9;
  *(undefined4 *)(iVar11 + 0x98) = uVar10;
  if ((uVar12 & 1) == 0) {
    *(undefined4 *)(param_1 + 0x218) = 0;
  }
  else {
    FUN_0010a6a6(iVar11,local_20,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar11 + 0x14) = *(uint *)(iVar11 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x218) = local_24;
  }
  *(undefined4 *)(iVar11 + 0x9c) = uVar3;
  FUN_0010a3c2(iVar11,1,uVar4);
  iVar13 = FUN_0010b0f4(iVar11,1);
  *(undefined4 *)(iVar13 + 0x10) = uVar5;
  FUN_00109c0e(iVar11 + 0xa4,1,(byte)uVar6 & 1);
  FUN_00109c0e(iVar11 + 0xa4,2,(byte)(uVar6 >> 1) & 1);
  *(undefined1 *)(iVar11 + 0x120) = uVar1;
  *(undefined4 *)(iVar11 + 0x124) = param_3;
  *(undefined4 *)(param_1 + 0x214) = uVar7;
  if ((uVar8 & 0x200000) != 0) {
    *(uint *)(iVar11 + 0x14) = *(uint *)(iVar11 + 0x14) | 0x200000;
  }
  FUN_000e9596();
  return;
}

/* FUN_00190e54 @ 0x190e54 (271 bytes) */
int FUN_00190e54(param_1)
  int param_1;
{
  int iVar1;
  int *piVar2;
  char cVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int local_24;
  
  local_24 = 1;
  do {
    uVar4 = FUN_00187782(param_1,local_24);
    if (uVar4 != 0x7ffffffe) {
      uVar7 = uVar4;
      if ((int)uVar4 < 0) {
        uVar7 = uVar4 ^ 0x80000000;
      }
      cVar3 = ((undefined4 (*)())FUN_0010fd8c)(uVar7);
      if (cVar3 != '\0') {
        iVar5 = ((int (*)())FUN_0010fdbc)(uVar7);
        iVar5 = iVar5 + *(int *)(*(int *)(param_1 + 0xb0) + 0x124);
        piVar2 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
        cVar3 = (**(code **)(*piVar2 + 0xfc))(piVar2,iVar5,*(int *)(param_1 + 0xb0));
        if (cVar3 != '\0') {
          iVar6 = (local_24 == 1) + 1;
          if ((int)uVar4 < 0) {
            iVar1 = iVar6 * 0x18 + 0x80;
            FUN_00109c0e(*(int *)(param_1 + 0xb0) + 0xc + iVar1,1,
                         (*(uint *)(*(int *)(param_1 + 0xb0) + 0x20 + iVar1) ^ 1) & 1);
          }
          ((int (*)())FUN_00190be0)(param_1,iVar6,iVar5);
          FUN_00184a5a(param_1);
          return 1;
        }
      }
    }
    local_24 = local_24 + 1;
  } while (local_24 != 3);
  return 0;
}

/* FUN_00190f64 @ 0x190f64 (184 bytes) */
int FUN_00190f64(param_1)
  int param_1;
{
  int iVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  
  cVar3 = FUN_0018a266(param_1,1,2);
  if (cVar3 != '\0') {
    iVar1 = *(int *)(param_1 + 0xb0);
    if ((((byte)*(uint *)(iVar1 + 0xb8) & 1) == ((byte)*(uint *)(iVar1 + 0xd0) & 1)) &&
       (((byte)(*(uint *)(iVar1 + 0xb8) >> 1) & 1) == ((byte)(*(uint *)(iVar1 + 0xd0) >> 1) & 1))) {
      iVar4 = *(int *)(iVar1 + 0x124) + 1;
      piVar2 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
      cVar3 = (**(code **)(*piVar2 + 0xfc))(piVar2,iVar4,iVar1);
      if (cVar3 != '\0') {
        ((int (*)())FUN_00190be0)(param_1,2,iVar4);
        FUN_00184a5a(param_1);
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_0019101c @ 0x19101c (937 bytes) */
int FUN_0019101c(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar15 = *(int *)(param_1 + 0xb0);
  uVar2 = *(undefined4 *)(iVar15 + 0x94);
  uVar3 = *(undefined4 *)(iVar15 + 0x98);
  uVar4 = *(undefined4 *)(iVar15 + 0x8c);
  iVar15 = FUN_0010b0f4(iVar15,0);
  uVar5 = *(undefined4 *)(iVar15 + 0x10);
  iVar15 = *(int *)(param_1 + 0xb0);
  uVar1 = *(undefined1 *)(iVar15 + 0x120);
  uVar6 = *(undefined4 *)(iVar15 + 0x124);
  uVar7 = *(undefined4 *)(param_3 * 0x18 + 0x8c + iVar15);
  iVar15 = FUN_0010b0f4(iVar15,param_3);
  uVar8 = *(undefined4 *)(iVar15 + 0x10);
  iVar15 = *(int *)(param_1 + 0xb0);
  uVar9 = *(uint *)(param_3 * 0x18 + 0xa0 + iVar15);
  uVar10 = *(undefined4 *)(param_4 * 0x18 + 0x8c + iVar15);
  iVar15 = FUN_0010b0f4(iVar15,param_4);
  uVar11 = *(undefined4 *)(iVar15 + 0x10);
  iVar15 = *(int *)(param_1 + 0xb0);
  uVar12 = *(uint *)(param_4 * 0x18 + 0xa0 + iVar15);
  uVar13 = *(undefined4 *)(param_1 + 0x210 + param_3 * 4);
  uVar14 = *(undefined4 *)(param_1 + 0x210 + param_4 * 4);
  uVar16 = *(uint *)(iVar15 + 0x14) >> 9;
  if ((uVar16 & 1) == 0) {
    local_20 = 0;
    local_1c = 0;
  }
  else {
    local_20 = *(undefined4 *)(param_1 + 0x210 + *(int *)(iVar15 + 0x84) * 4);
    local_1c = *(undefined4 *)(iVar15 + 0x8c + *(int *)(iVar15 + 0x84) * 0x18);
  }
  FUN_001a7d72(iVar15);
  iVar15 = *(int *)(param_1 + 0xb0);
  FUN_0010d8fc(iVar15,param_2,*(undefined4 *)(param_1 + 0x238));
  FUN_0010a3c2(iVar15,0,uVar4);
  *(undefined4 *)(iVar15 + 0x94) = uVar2;
  *(undefined4 *)(iVar15 + 0x98) = uVar3;
  if ((uVar16 & 1) == 0) {
    iVar17 = FUN_0012a37e(uVar4,*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0x394)
                          ,*(int *)(param_1 + 0x238));
    *(undefined4 *)(param_1 + 0x21c) = *(undefined4 *)(iVar17 + 0xb0);
  }
  else {
    FUN_0010a6a6(iVar15,local_1c,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar15 + 0x14) = *(uint *)(iVar15 + 0x14) | 0x200;
    *(undefined4 *)(param_1 + 0x21c) = local_20;
  }
  *(undefined4 *)(iVar15 + 0x9c) = uVar5;
  *(undefined1 *)(iVar15 + 0x120) = uVar1;
  *(undefined4 *)(iVar15 + 0x124) = uVar6;
  FUN_0010a3c2(iVar15,1,uVar7);
  iVar17 = FUN_0010b0f4(iVar15,1);
  *(undefined4 *)(iVar17 + 0x10) = uVar8;
  FUN_00109c0e(iVar15 + 0xa4,1,(byte)uVar9 & 1);
  FUN_00109c0e(iVar15 + 0xa4,2,(byte)(uVar9 >> 1) & 1);
  FUN_0010a3c2(iVar15,2,uVar10);
  iVar17 = FUN_0010b0f4(iVar15,2);
  *(undefined4 *)(iVar17 + 0x10) = uVar11;
  FUN_00109c0e(iVar15 + 0xbc,1,(byte)uVar12 & 1);
  FUN_00109c0e(iVar15 + 0xbc,2,(byte)(uVar12 >> 1) & 1);
  *(undefined4 *)(param_1 + 0x214) = uVar13;
  *(undefined4 *)(param_1 + 0x218) = uVar14;
  FUN_000e9596();
  return;
}

/* FUN_001913ce @ 0x1913ce (121 bytes) */
int FUN_001913ce(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),0);
  cVar1 = FUN_00187720(param_1,*(undefined4 *)(iVar2 + 4),3);
  if (cVar1 == '\0') {
    return 0;
  }
  ((int (*)())FUN_0019101c)(param_1,0x13,1,2);
  FUN_00184a5a(param_1);
  return 1;
}

/* FUN_00191448 @ 0x191448 (316 bytes) */
int FUN_00191448(param_1)
  int param_1;
{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  
  iVar3 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),0x3f800000);
  uVar1 = *(undefined4 *)(iVar3 + 4);
  iVar3 = 1;
  do {
    cVar2 = FUN_00187720(param_1,uVar1,iVar3);
    if (cVar2 != '\0') {
      ((int (*)())FUN_0019101c)(param_1,0x12,(iVar3 == 1) + '\x01',3);
      FUN_00184a5a(param_1);
      return 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 3);
  iVar3 = FUN_001840fe(*(undefined4 *)(param_1 + 0x238),0xbf800000);
  uVar1 = *(undefined4 *)(iVar3 + 4);
  iVar3 = 1;
  do {
    cVar2 = FUN_00187720(param_1,uVar1,iVar3);
    if (cVar2 != '\0') {
      ((int (*)())FUN_0019101c)(param_1,0x12,(iVar3 == 1) + '\x01',3);
      FUN_00109c0e(*(int *)(param_1 + 0xb0) + 0xa4,1,
                   (*(uint *)(*(int *)(param_1 + 0xb0) + 0xb8) ^ 1) & 1);
      FUN_00184a5a(param_1);
      return 1;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 3);
  return 0;
}

/* FUN_00191584 @ 0x191584 (1476 bytes) */
int FUN_00191584(param_1)
  int param_1;
{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  int *piVar17;
  undefined4 uVar18;
  int iVar19;
  int iVar20;
  int *piVar21;
  int iVar22;
  undefined4 local_40;
  undefined4 local_24;
  int local_20 [4];
  
  iVar15 = *(int *)(param_1 + 0xb0);
  uVar18 = *(undefined4 *)(iVar15 + 4);
  uVar2 = *(undefined4 *)(iVar15 + 0x158);
  uVar3 = *(undefined4 *)(iVar15 + 0x94);
  uVar4 = *(undefined4 *)(iVar15 + 0x98);
  uVar5 = *(undefined4 *)(iVar15 + 0x8c);
  iVar15 = FUN_0010b0f4(iVar15,0);
  local_20[0] = *(int *)(iVar15 + 0x10);
  iVar15 = *(int *)(param_1 + 0xb0);
  uVar1 = *(undefined1 *)(iVar15 + 0x120);
  iVar22 = *(int *)(iVar15 + 0x124);
  uVar6 = *(undefined4 *)(iVar15 + 0xa4);
  iVar15 = FUN_0010b0f4(iVar15,1);
  uVar7 = *(undefined4 *)(iVar15 + 0x10);
  iVar15 = *(int *)(param_1 + 0xb0);
  uVar8 = *(uint *)(iVar15 + 0xb8);
  uVar9 = *(undefined4 *)(iVar15 + 0xbc);
  iVar15 = FUN_0010b0f4(iVar15,2);
  uVar10 = *(undefined4 *)(iVar15 + 0x10);
  iVar15 = *(int *)(param_1 + 0xb0);
  uVar11 = *(uint *)(iVar15 + 0xd0);
  uVar12 = *(undefined4 *)(iVar15 + 0xd4);
  iVar15 = FUN_0010b0f4(iVar15,3);
  uVar13 = *(undefined4 *)(iVar15 + 0x10);
  iVar15 = *(int *)(param_1 + 0xb0);
  uVar14 = *(uint *)(iVar15 + 0xe8);
  uVar16 = *(uint *)(iVar15 + 0x14) >> 9;
  if ((uVar16 & 1) == 0) {
    local_40 = 0;
  }
  else {
    local_40 = *(undefined4 *)(iVar15 + 0x8c + *(int *)(iVar15 + 0x84) * 0x18);
  }
  FUN_001a7d72(iVar15);
  iVar15 = *(int *)(param_1 + 0xb0);
  FUN_0010d8fc(iVar15,0x13,*(undefined4 *)(param_1 + 0x238));
  FUN_000e9596(uVar2,uVar18,iVar15);
  piVar17 = (int *)FUN_0010a17a(0x12,*(undefined4 *)(param_1 + 0x238));
  FUN_000e9596(uVar2,*(undefined4 *)(param_1 + 0xb0),piVar17);
  iVar19 = *(int *)(param_1 + 0x238);
  iVar20 = *(int *)(iVar19 + 0xf0) + -1;
  *(int *)(iVar19 + 0xf0) = iVar20;
  uVar18 = FUN_0012eb84(*(undefined4 *)(*(int *)(iVar19 + 0x3f4) + 0x3a0),0,iVar20,0);
  FUN_0010a3c2(iVar15,0,uVar18);
  FUN_0010a3c2(iVar15,1,uVar6);
  iVar19 = FUN_0010b0f4(iVar15,1);
  *(undefined4 *)(iVar19 + 0x10) = uVar7;
  FUN_00109c0e(iVar15 + 0xa4,1,(byte)uVar8 & 1);
  FUN_00109c0e(iVar15 + 0xa4,2,(byte)(uVar8 >> 1) & 1);
  FUN_0010a3c2(iVar15,2,uVar9);
  iVar19 = FUN_0010b0f4(iVar15,2);
  *(undefined4 *)(iVar19 + 0x10) = uVar10;
  FUN_00109c0e(iVar15 + 0xbc,1,(byte)uVar11 & 1);
  FUN_00109c0e(iVar15 + 0xbc,2,(byte)(uVar11 >> 1) & 1);
  *(undefined4 *)(iVar15 + 0x94) = uVar3;
  *(undefined4 *)(iVar15 + 0x98) = uVar4;
  *(int *)(iVar15 + 0x9c) = local_20[0];
  FUN_0012a42e(uVar18,iVar15);
  local_24 = DAT_001cc72c;
  iVar19 = 0;
  do {
    if (*(char *)((int)local_20 + iVar19) == '\0') {
      *(char *)((int)local_20 + iVar19 + -4) = (char)iVar19;
    }
    iVar19 = iVar19 + 1;
  } while (iVar19 != 4);
  FUN_0010a3c2(piVar17,0,uVar5);
  piVar17[0x27] = local_20[0];
  FUN_0010a3c2(piVar17,1,uVar18);
  uVar18 = local_24;
  iVar19 = FUN_0010b0f4(piVar17,1);
  *(undefined4 *)(iVar19 + 0x10) = uVar18;
  FUN_0010a3c2(piVar17,2,uVar12);
  iVar19 = FUN_0010b0f4(piVar17,2);
  *(undefined4 *)(iVar19 + 0x10) = uVar13;
  FUN_00109c0e(piVar17 + 0x2f,1,(byte)uVar14 & 1);
  FUN_00109c0e(piVar17 + 0x2f,2,(byte)(uVar14 >> 1) & 1);
  *(undefined1 *)(piVar17 + 0x48) = uVar1;
  piVar17[0x49] = iVar22;
  FUN_0012a42e(uVar5,piVar17);
  iVar22 = 1;
  piVar21 = piVar17;
  while( true ) {
    iVar19 = (**(code **)(*piVar17 + 0x14))(piVar17);
    if (iVar19 < iVar22) break;
    FUN_0012a9e6(piVar21[0x29],iVar22,piVar17);
    iVar22 = iVar22 + 1;
    piVar21 = piVar21 + 6;
  }
  if ((uVar16 & 1) != 0) {
    FUN_0010a6a6(iVar15,local_40,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar15 + 0x14) = *(uint *)(iVar15 + 0x14) | 0x200;
    FUN_0012a9e6(local_40,*(undefined4 *)(iVar15 + 0x84),iVar15);
    FUN_0010a6a6(piVar17,uVar5,*(undefined4 *)(param_1 + 0x238));
    piVar17[5] = piVar17[5] | 0x200;
    FUN_0012a9e6(uVar5,piVar17[0x21],piVar17);
  }
  FUN_00184a5a();
  return;
}

/* FUN_00191b50 @ 0x191b50 (972 bytes) */
int FUN_00191b50(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  undefined4 uVar15;
  undefined4 *puVar16;
  int iVar17;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar12 = *(int *)(param_1 + 0xb0);
  uVar15 = *(undefined4 *)(iVar12 + 4);
  uVar2 = *(undefined4 *)(iVar12 + 0x158);
  uVar3 = *(undefined4 *)(iVar12 + 0x94);
  uVar4 = *(undefined4 *)(iVar12 + 0x98);
  uVar5 = *(undefined4 *)(iVar12 + 0x8c);
  iVar12 = FUN_0010b0f4(iVar12,0);
  uVar6 = *(undefined4 *)(iVar12 + 0x10);
  iVar12 = *(int *)(param_1 + 0xb0);
  uVar1 = *(undefined1 *)(iVar12 + 0x120);
  uVar7 = *(undefined4 *)(iVar12 + 0x124);
  uVar8 = *(undefined4 *)(iVar12 + 0xd4);
  uVar9 = *(undefined4 *)(param_1 + 0x21c);
  iVar12 = FUN_0010b0f4(iVar12,3);
  uVar10 = *(undefined4 *)(iVar12 + 0x10);
  iVar12 = *(int *)(param_1 + 0xb0);
  uVar11 = *(uint *)(iVar12 + 0xe8);
  uVar13 = *(uint *)(iVar12 + 0x14) >> 9;
  if ((uVar13 & 1) == 0) {
    local_20 = 0;
    local_1c = 0;
  }
  else {
    local_20 = *(undefined4 *)(param_1 + 0x210 + *(int *)(iVar12 + 0x84) * 4);
    local_1c = *(undefined4 *)(iVar12 + 0x8c + *(int *)(iVar12 + 0x84) * 0x18);
  }
  FUN_001a7d72(iVar12);
  iVar12 = *(int *)(param_1 + 0xb0);
  FUN_0010d8fc(iVar12,0x12,*(undefined4 *)(param_1 + 0x238));
  FUN_000e9596(uVar2,uVar15,iVar12);
  *(undefined1 *)(iVar12 + 0x120) = uVar1;
  *(undefined4 *)(iVar12 + 0x124) = uVar7;
  *(undefined4 *)(iVar12 + 0x94) = uVar3;
  *(undefined4 *)(iVar12 + 0x98) = uVar4;
  FUN_0010a3c2(iVar12,0,uVar5);
  *(undefined4 *)(iVar12 + 0x9c) = uVar6;
  iVar14 = *(int *)(param_2 + 0x8c);
  if (*(int *)(*(int *)(iVar14 + 0x2c) + 4) == 0) {
    uVar15 = *(undefined4 *)(*(int *)(param_1 + 0x238) + 0xbc);
    puVar16 = (undefined4 *)FUN_001a7bca(uVar15,0x240);
    *puVar16 = uVar15;
    puVar16 = puVar16 + 1;
    FUN_00183c52(puVar16,param_2,*(undefined4 *)(param_1 + 0x238));
    FUN_00185344(puVar16);
    FUN_00183630(puVar16);
    FUN_0012a7b2(iVar14,*(undefined4 *)(*(int *)(param_2 + 0x158) + 0xb0),puVar16);
  }
  FUN_0010a3c2(iVar12,1,iVar14);
  iVar14 = FUN_0010b0f4(iVar12,1);
  *(undefined4 *)(iVar14 + 0x10) = param_3;
  FUN_00109c0e(iVar12 + 0xa4,1,param_4);
  FUN_0010a3c2(iVar12,2,uVar8);
  iVar14 = FUN_0010b0f4(iVar12,2);
  *(undefined4 *)(iVar14 + 0x10) = uVar10;
  FUN_00109c0e(iVar12 + 0xbc,1,(byte)uVar11 & 1);
  FUN_00109c0e(iVar12 + 0xbc,2,(byte)(uVar11 >> 1) & 1);
  if ((uVar13 & 1) != 0) {
    FUN_0010a6a6(iVar12,local_1c,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar12 + 0x14) = *(uint *)(iVar12 + 0x14) | 0x200;
  }
  *(int *)(param_1 + 0x214) = param_2;
  *(undefined4 *)(param_1 + 0x218) = uVar9;
  uVar15 = 0;
  if ((uVar13 & 1) != 0) {
    uVar15 = local_20;
  }
  *(undefined4 *)(param_1 + 0x21c) = uVar15;
  FUN_0012a42e(uVar5,iVar12);
  if (*(int *)(iVar12 + 0x84) < 1) {
    FUN_00184a5a();
    return;
  }
  iVar17 = 1;
  iVar14 = iVar12;
  do {
    FUN_0012a9e6(*(undefined4 *)(iVar14 + 0xa4),iVar17,iVar12);
    iVar17 = iVar17 + 1;
    iVar14 = iVar14 + 0x18;
  } while (iVar17 <= *(int *)(iVar12 + 0x84));
  FUN_00184a5a();
  return;
}

/* FUN_00191f42 @ 0x191f42 (1227 bytes) */
int FUN_00191f42(param_1)
  int param_1;
{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined *puVar11;
  float fVar12;
  uint uVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  undefined4 local_3c;
  
  iVar17 = 1;
  while (fVar12 = (float)FUN_001883e0(param_1,iVar17), fVar12 != FLOAT_001c5ba4) {
    if ((fVar12 == FLOAT_001c5bdc) && (!NAN(fVar12) && !NAN(FLOAT_001c5bdc))) break;
    iVar17 = iVar17 + 1;
    if (iVar17 == 3) {
      return 0;
    }
  }
  iVar18 = (iVar17 == 1) + 1;
  iVar17 = *(int *)(param_1 + 0xb0);
  iVar15 = *(int *)(*(int *)(iVar17 + 0x88) + 8);
  uVar2 = *(undefined4 *)(iVar17 + 0x8c);
  iVar17 = FUN_0010b0f4(iVar17,0);
  uVar3 = *(undefined4 *)(iVar17 + 0x10);
  iVar17 = *(int *)(param_1 + 0xb0);
  uVar1 = *(undefined1 *)(iVar17 + 0x120);
  uVar4 = *(undefined4 *)(iVar17 + 0x124);
  uVar5 = *(undefined4 *)(iVar17 + 0x8c + iVar18 * 0x18);
  iVar17 = FUN_0010b0f4(iVar17,iVar18);
  uVar6 = *(uint *)(iVar17 + 0x10);
  uVar7 = *(undefined4 *)(param_1 + 0x210 + iVar18 * 4);
  iVar17 = *(int *)(param_1 + 0xb0);
  uVar13 = *(uint *)(iVar17 + 0x14) >> 9;
  if ((uVar13 & 1) == 0) {
    local_3c = 0;
  }
  else {
    local_3c = *(undefined4 *)(iVar17 + 0x8c + *(int *)(iVar17 + 0x84) * 0x18);
  }
  uVar8 = *(undefined4 *)(iVar17 + 0x94);
  uVar9 = *(undefined4 *)(iVar17 + 0x98);
  uVar14 = *(undefined4 *)(iVar17 + 4);
  uVar10 = *(undefined4 *)(iVar17 + 0x158);
  FUN_001a7d72(iVar17);
  iVar17 = *(int *)(param_1 + 0xb0);
  FUN_0010d8fc(iVar17,0x12,*(undefined4 *)(param_1 + 0x238));
  FUN_000e9596(uVar10,uVar14,iVar17);
  iVar18 = *(int *)(param_1 + 0x238);
  iVar16 = *(int *)(iVar18 + 0xf0) + -1;
  *(int *)(iVar18 + 0xf0) = iVar16;
  uVar14 = FUN_0012eb84(*(undefined4 *)(*(int *)(iVar18 + 0x3f4) + 0x3a0),0,iVar16,0);
  FUN_0012a42e(uVar14,*(undefined4 *)(param_1 + 0xb0));
  FUN_0010a3c2(*(undefined4 *)(param_1 + 0xb0),0,uVar14);
  *(undefined4 *)(iVar17 + 0x94) = uVar8;
  *(undefined4 *)(iVar17 + 0x98) = uVar9;
  FUN_0010a3c2(iVar17,1,uVar5);
  FUN_0010a3c2(iVar17,2,uVar5);
  iVar18 = FUN_0010a17a(0x12,*(undefined4 *)(param_1 + 0x238));
  FUN_000e9596(uVar10,iVar17,iVar18);
  FUN_0010a3c2(iVar18,0,uVar2);
  *(undefined4 *)(iVar18 + 0x94) = uVar8;
  *(undefined4 *)(iVar18 + 0x98) = uVar9;
  *(undefined4 *)(iVar18 + 0x9c) = uVar3;
  if ((uVar13 & 1) != 0) {
    FUN_0010a6a6(iVar18,local_3c,*(undefined4 *)(param_1 + 0x238));
    *(uint *)(iVar18 + 0x14) = *(uint *)(iVar18 + 0x14) | 0x200;
  }
  *(undefined1 *)(iVar18 + 0x120) = uVar1;
  *(undefined4 *)(iVar18 + 0x124) = uVar4;
  *(undefined4 *)(param_1 + 0x214) = uVar7;
  *(undefined4 *)(param_1 + 0x218) = uVar7;
  if (iVar15 == 0x1c) {
    *(uint *)(iVar17 + 0x9c) = DAT_001cc720 & 0xffffff00;
    uVar2 = *(undefined4 *)(PTR_DAT_00213485 + (uVar6 & 0xff) * 4);
    iVar15 = FUN_0010b0f4(iVar17,1);
    *(undefined4 *)(iVar15 + 0x10) = uVar2;
    uVar2 = *(undefined4 *)(PTR_DAT_00213485 + (uVar6 >> 8 & 0xff) * 4);
    iVar17 = FUN_0010b0f4(iVar17,2);
    *(undefined4 *)(iVar17 + 0x10) = uVar2;
    FUN_0010a3c2(iVar18,1,uVar14);
    FUN_0010a3c2(iVar18,2,uVar5);
    uVar2 = *(undefined4 *)PTR_DAT_00213485;
    iVar17 = FUN_0010b0f4(iVar18,1);
    *(undefined4 *)(iVar17 + 0x10) = uVar2;
    uVar2 = *(undefined4 *)(PTR_DAT_00213485 + (uVar6 >> 0x10 & 0xff) * 4);
    iVar17 = FUN_0010b0f4(iVar18,2);
    *(undefined4 *)(iVar17 + 0x10) = uVar2;
  }
  else if (iVar15 == 0x1d) {
    *(uint *)(iVar17 + 0x9c) = DAT_001cc720 & 0xffff0000;
    uVar13 = (uint)DAT_001cc728 >> 0x10;
    iVar15 = FUN_0010b0f4(iVar17,1);
    *(uint *)(iVar15 + 0x10) = CONCAT22((short)uVar13,(short)uVar6);
    uVar13 = (uint)DAT_001cc728 >> 0x10;
    iVar17 = FUN_0010b0f4(iVar17,2);
    *(uint *)(iVar17 + 0x10) = CONCAT22((short)uVar13,(short)(uVar6 >> 0x10));
    FUN_0010a3c2(iVar18,1,uVar14);
    FUN_0010a3c2(iVar18,2,uVar14);
    puVar11 = PTR_DAT_00213485;
    uVar2 = *(undefined4 *)PTR_DAT_00213485;
    iVar17 = FUN_0010b0f4(iVar18,1);
    *(undefined4 *)(iVar17 + 0x10) = uVar2;
    uVar2 = *(undefined4 *)(puVar11 + 4);
    iVar17 = FUN_0010b0f4(iVar18,2);
    *(undefined4 *)(iVar17 + 0x10) = uVar2;
  }
  FUN_00184a5a(param_1);
  return 1;
}

/* FUN_00192416 @ 0x192416 (524 bytes) */
int FUN_00192416(param_1)
  int param_1;
{
  int *piVar1;
  float *pfVar2;
  int iVar3;
  float *pfVar4;
  undefined4 uVar5;
  int iVar6;
  int local_60;
  int local_54;
  int local_50;
  float local_44 [5];
  float local_30 [4];
  float local_20 [4];
  
  pfVar2 = local_44;
  do {
    *pfVar2 = NAN;
    pfVar2 = pfVar2 + 1;
  } while (pfVar2 != local_30);
  pfVar2 = local_30;
  do {
    *pfVar2 = NAN;
    pfVar2 = pfVar2 + 1;
  } while (pfVar2 != local_20);
  iVar3 = 1;
  do {
    local_44[iVar3 + 4] = NAN;
    iVar3 = iVar3 + 1;
  } while (iVar3 != 5);
  local_54 = 0;
  local_60 = param_1 + 0x160;
  do {
    iVar3 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(char *)(local_54 + 0x10 + iVar3) != '\x01') {
      iVar3 = local_60 + 8;
      local_50 = 0;
      pfVar2 = local_44;
      do {
        pfVar2 = pfVar2 + 1;
        if (-1 < *(int *)(iVar3 + 0x10)) {
          return 0;
        }
        pfVar4 = (float *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),*(int *)(iVar3 + 0x10));
        *pfVar2 = *pfVar4;
        local_50 = local_50 + 1;
        iVar3 = iVar3 + 0x10;
      } while (local_50 != 2);
      local_44[local_54 + 5] = local_44[1] * local_44[2];
    }
    local_54 = local_54 + 1;
    local_60 = local_60 + 4;
  } while (local_54 != 4);
  iVar3 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
  uVar5 = FUN_000f5fea(*(undefined4 *)(iVar3 + 0x10));
  local_20[0] = (float)FUN_000f5b96(DAT_001cc728,uVar5);
  piVar1 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
  iVar3 = (**(code **)(*piVar1 + 0x154))
                    (piVar1,*(undefined4 *)(*(int *)(param_1 + 0x238) + 0x3f4),local_30,local_20);
  if (iVar3 == 0) {
    iVar3 = 0;
    pfVar2 = local_30;
    do {
      iVar6 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
      if (*(char *)(iVar3 + 0x10 + iVar6) != '\x01') {
        *pfVar2 = -*pfVar2;
      }
      iVar3 = iVar3 + 1;
      pfVar2 = pfVar2 + 1;
    } while (iVar3 != 4);
    piVar1 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
    iVar3 = (**(code **)(*piVar1 + 0x154))
                      (piVar1,*(undefined4 *)(*(int *)(param_1 + 0x238) + 0x3f4),local_30,local_20);
    if (iVar3 == 0) {
      return 0;
    }
    uVar5 = 1;
  }
  else {
    uVar5 = 0;
  }
  ((int (*)())FUN_00191b50)(param_1,iVar3,local_20[0],uVar5);
  return 1;
}

/* FUN_00192622 @ 0x192622 (482 bytes) */
int FUN_00192622(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  undefined4 uVar7;
  byte local_2c;
  char cStack_11;
  undefined4 local_10;
  
  cVar3 = FUN_0018a266(param_1,1,2);
  if (cVar3 != '\0') {
    iVar4 = *(int *)(param_1 + 0xb0);
    if ((((byte)*(uint *)(iVar4 + 0xb8) & 1) != ((byte)*(uint *)(iVar4 + 0xd0) & 1)) &&
       (((byte)(*(uint *)(iVar4 + 0xb8) >> 1) & 1) == ((byte)(*(uint *)(iVar4 + 0xd0) >> 1) & 1))) {
      iVar4 = FUN_0010b0f4(iVar4,0);
      local_10 = *(undefined4 *)(iVar4 + 0x10);
      bVar2 = true;
      local_2c = 0;
      iVar6 = 1;
      iVar4 = param_1;
      do {
        if ((&cStack_11)[iVar6] == '\0') {
          if (-1 < *(int *)(iVar4 + 0x178)) {
LAB_00192793:
            piVar1 = *(int **)(*(int *)(param_1 + 0x238) + 0x54);
            cVar3 = (**(code **)(*piVar1 + 0x88))(piVar1);
            if (cVar3 == '\0') {
              return 0;
            }
            FUN_0018ea90(param_1,1);
            FUN_00109c0e(*(int *)(param_1 + 0xb0) + 0xa4,2,1);
            param_2 = param_2 ^ 1;
            uVar7 = 1;
            goto LAB_00192757;
          }
          puVar5 = (uint *)FUN_001836ee(*(undefined4 *)(param_1 + 0x238),*(int *)(iVar4 + 0x178));
          if (bVar2) {
            local_2c = (byte)(*puVar5 >> 0x1f);
            bVar2 = false;
          }
          else if (*puVar5 >> 0x1f != (uint)local_2c) goto LAB_00192793;
        }
        iVar6 = iVar6 + 1;
        iVar4 = iVar4 + 4;
      } while (iVar6 != 5);
      FUN_0018ea90(param_1,1);
      FUN_00109c0e(*(int *)(param_1 + 0xb0) + 0xa4,1,param_2 == local_2c);
      param_2 = 0;
      uVar7 = 2;
LAB_00192757:
      FUN_00109c0e(*(int *)(param_1 + 0xb0) + 0xa4,uVar7,param_2);
      FUN_00184a5a(param_1);
      return 1;
    }
  }
  return 0;
}

/* FUN_00192804 @ 0x192804 (30 bytes) */
int FUN_00192804(param_1)
  undefined4 param_1;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_00192622)(param_1,1);
  return uVar1;
}

/* FUN_00192822 @ 0x192822 (30 bytes) */
int FUN_00192822(param_1)
  undefined4 param_1;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_00192622)(param_1,0);
  return uVar1;
}

/* FUN_00192ad8 @ 0x192ad8 (66 bytes) */
int FUN_00192ad8(param_1)
  int param_1;
{
  uint *puVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  
  if (*(int *)(*(int *)(param_1 + 0xb0) + 0x98) != 0x2c) {
    cVar2 = FUN_001195a6(*(undefined4 *)(param_1 + 0x238),*(int *)(param_1 + 0xb0));
    if (cVar2 != '\0') {
      iVar3 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
      cVar2 = FUN_000f57b4(*(undefined4 *)(iVar3 + 0x10));
      if (cVar2 != '\0') {
        return;
      }
      piVar4 = (int *)FUN_0010a1c2(*(undefined4 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0x238),
                                   0);
      iVar3 = *(int *)(param_1 + 0x238);
      iVar6 = *(int *)(iVar3 + 0xf0) + -1;
      *(int *)(iVar3 + 0xf0) = iVar6;
      uVar5 = FUN_0012eb84(*(undefined4 *)(*(int *)(iVar3 + 0x3f4) + 0x3a0),0,iVar6,0);
      FUN_0012a42e(uVar5,*(undefined4 *)(param_1 + 0xb0));
      FUN_0010a3c2(*(undefined4 *)(param_1 + 0xb0),0,uVar5);
      *(undefined1 *)(*(int *)(param_1 + 0xb0) + 0x9f) = 1;
      piVar4[0x27] = _UNK_001cc724;
      FUN_0012a42e(piVar4[0x23],piVar4);
      iVar3 = 1;
      piVar7 = piVar4;
      while( true ) {
        iVar6 = (**(code **)(*piVar4 + 0x14))(piVar4);
        if (iVar6 < iVar3) break;
        FUN_0012a9e6(piVar7[0x29],iVar3,piVar4);
        iVar3 = iVar3 + 1;
        piVar7 = piVar7 + 6;
      }
      if ((*(byte *)(*(int *)(param_1 + 0xb0) + 0x15) & 2) == 0) {
        FUN_0010a6a6(*(int *)(param_1 + 0xb0),uVar5,*(undefined4 *)(param_1 + 0x238));
        FUN_0012a9e6(uVar5,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x84),*(int *)(param_1 + 0xb0)
                    );
        puVar1 = (uint *)(*(int *)(param_1 + 0xb0) + 0x14);
        *puVar1 = *puVar1 | 0x200;
        iVar3 = FUN_0012a37e(uVar5,*(undefined4 *)
                                    (*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0x394),
                             *(int *)(param_1 + 0x238));
        *(undefined4 *)(param_1 + 0x210 + *(int *)(*(int *)(param_1 + 0xb0) + 0x84) * 4) =
             *(undefined4 *)(iVar3 + 0xb0);
        FUN_0010a6a6(piVar4,uVar5,*(undefined4 *)(param_1 + 0x238));
        FUN_0012a9e6(uVar5,piVar4[0x21],piVar4);
        piVar4[5] = piVar4[5] | 0x200;
      }
      else {
        FUN_0010a3c2(piVar4,piVar4[0x21],uVar5);
        FUN_0012a9e6(uVar5,piVar4[0x21],piVar4);
      }
      FUN_00184a5a(param_1);
      FUN_000e9596(*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158),*(int *)(param_1 + 0xb0),piVar4
                  );
      return;
    }
  }
  return;
}

/* FUN_00192b1a @ 0x192b1a (1816 bytes) */
int FUN_00192b1a(param_1)
  int param_1;
{
  int *piVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int local_30 [5];
  int local_1c [3];
  
  if ((*(int *)(*(int *)(param_1 + 0xb0) + 0x80) == 1) &&
     (iVar3 = FUN_0010b0f4(*(int *)(param_1 + 0xb0),0), *(int *)(iVar3 + 0x10) == DAT_001cc720)) {
    return 0;
  }
  piVar1 = local_30 + 1;
  piVar4 = piVar1;
  do {
    *piVar4 = 0x7ffffffe;
    piVar4 = piVar4 + 1;
  } while (local_1c != piVar4);
  iVar3 = 1;
  do {
    local_30[iVar3] = 0x7ffffffe;
    iVar3 = iVar3 + 1;
  } while (iVar3 != 5);
  cVar2 = ((int (*)())FUN_00190762)(param_1,piVar1);
  if (cVar2 != '\0') {
    return 0;
  }
  piVar4 = (int *)FUN_00118f66(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8));
  local_30[0] = *(int *)(param_1 + 0x238);
  iVar3 = (**(code **)(*piVar4 + 0x14))(piVar4,param_1,piVar1);
  if (iVar3 == 0) {
    return 0;
  }
  iVar5 = *(int *)(param_1 + 0xb0);
  iVar3 = *(int *)(*(int *)(iVar5 + 0x88) + 8);
  if (iVar3 == 0x1d) {
    FUN_00189024(param_1);
    cVar2 = FUN_0018e906(param_1);
    if (cVar2 != '\0') {
      return 0;
    }
    cVar2 = FUN_0018b262(param_1);
    if (cVar2 != '\0') {
      return 1;
    }
    cVar2 = FUN_00186e2c(param_1);
    if (cVar2 != '\0') {
      return 1;
    }
  }
  else if (iVar3 < 0x1e) {
    if (iVar3 == 0x17) {
      cVar2 = FUN_0018f4a8(param_1);
      if (cVar2 != '\0') {
        return 0;
      }
      cVar2 = FUN_0018f1ac(param_1);
      if (cVar2 != '\0') {
        return 0;
      }
      cVar2 = ((int (*)())FUN_00192804)(param_1);
      if (cVar2 != '\0') {
        return 0;
      }
      iVar3 = 0;
      do {
        iVar5 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(char *)(iVar3 + 0x10 + iVar5) != '\x01') {
          iVar6 = *(int *)(param_1 + 0x238);
          if (*(int *)(iVar6 + 0x38c) <= *(int *)(*(int *)(iVar6 + 0x3f4) + 0xa8))
          goto LAB_00193182;
          if ((local_30[iVar3 + 1] == 0x7ffffffe) &&
             (cVar2 = FUN_0018a43c(param_1,iVar3), cVar2 == '\0')) {
            FUN_00189fae(param_1,iVar3);
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != 4);
    }
    else if (iVar3 < 0x18) {
      if (iVar3 == 0x13) {
        FUN_00189024(param_1);
        cVar2 = FUN_00190118(param_1);
        if (cVar2 != '\0') {
          return 0;
        }
        cVar2 = FUN_0018f084(param_1);
        if (cVar2 != '\0') {
          return 0;
        }
        cVar2 = FUN_000e1402(*(undefined4 *)(param_1 + 0x238),0xc);
        if ((cVar2 != '\0') && (cVar2 = ((int (*)())FUN_00190e54)(param_1), cVar2 != '\0')) {
          return 0;
        }
        iVar3 = 0;
        do {
          iVar5 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
          if (*(char *)(iVar3 + 0x10 + iVar5) != '\x01') {
            iVar6 = *(int *)(param_1 + 0x238);
            if (*(int *)(iVar6 + 0x38c) <= *(int *)(*(int *)(iVar6 + 0x3f4) + 0xa8))
            goto LAB_00193182;
            if ((local_30[iVar3 + 1] == 0x7ffffffe) &&
               (cVar2 = FUN_00187018(param_1,iVar3), cVar2 == '\0')) {
              FUN_0018a502(param_1,iVar3);
            }
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 != 4);
      }
      else {
        if (iVar3 != 0x14) goto LAB_00192d53;
        FUN_00189024(param_1);
        cVar2 = FUN_0018f724(param_1);
        if (cVar2 != '\0') {
          return 0;
        }
        cVar2 = ((int (*)())FUN_00191448)(param_1);
        if (cVar2 != '\0') {
          return 1;
        }
        cVar2 = ((int (*)())FUN_001913ce)(param_1);
        if (cVar2 != '\0') {
          return 1;
        }
        cVar2 = ((int (*)())FUN_00192416)(param_1);
        if (cVar2 != '\0') {
          return 1;
        }
        iVar3 = 0;
        do {
          iVar5 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
          if (*(char *)(iVar3 + 0x10 + iVar5) != '\x01') {
            iVar6 = *(int *)(param_1 + 0x238);
            if (*(int *)(iVar6 + 0x38c) <= *(int *)(*(int *)(iVar6 + 0x3f4) + 0xa8))
            goto LAB_00193182;
            if (local_30[iVar3 + 1] == 0x7ffffffe) {
              FUN_0018a390(param_1,iVar3);
            }
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 != 4);
      }
    }
    else if (iVar3 == 0x19) {
      cVar2 = FUN_0018f22c(param_1);
      if (cVar2 != '\0') {
        return 0;
      }
      cVar2 = FUN_0018f1ac(param_1);
      if (cVar2 != '\0') {
        return 0;
      }
      cVar2 = ((int (*)())FUN_00192822)(param_1);
      if (cVar2 != '\0') {
        return 0;
      }
      iVar3 = 0;
      do {
        iVar5 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(char *)(iVar3 + 0x10 + iVar5) != '\x01') {
          iVar6 = *(int *)(param_1 + 0x238);
          if (*(int *)(iVar6 + 0x38c) <= *(int *)(*(int *)(iVar6 + 0x3f4) + 0xa8))
          goto LAB_00193182;
          if ((local_30[iVar3 + 1] == 0x7ffffffe) &&
             (cVar2 = FUN_0018a43c(param_1,iVar3), cVar2 == '\0')) {
            FUN_0018a08c(param_1,iVar3);
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != 4);
    }
    else {
      if (iVar3 != 0x1c) goto LAB_00192d53;
      FUN_00189024(param_1);
      cVar2 = FUN_0018e754(param_1);
      if (cVar2 != '\0') {
        return 0;
      }
      cVar2 = FUN_0018b262(param_1);
      if (cVar2 != '\0') {
        return 1;
      }
    }
  }
  else if (iVar3 < 0x2b) {
    if (iVar3 < 0x27) {
      if (iVar3 < 0x24) {
LAB_00192d53:
        iVar6 = *(int *)(param_1 + 0x238);
        goto LAB_00192d59;
      }
      cVar2 = FUN_0018eebc(param_1);
      if (cVar2 != '\0') {
        return 0;
      }
      cVar2 = FUN_0018ed02(param_1);
      if (cVar2 != '\0') {
        return 0;
      }
      cVar2 = FUN_0018ed82(param_1);
      if (cVar2 != '\0') {
        return 0;
      }
      iVar3 = 0;
      do {
        iVar5 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(char *)(iVar3 + 0x10 + iVar5) != '\x01') {
          iVar6 = *(int *)(param_1 + 0x238);
          if (*(int *)(iVar6 + 0x38c) <= *(int *)(*(int *)(iVar6 + 0x3f4) + 0xa8))
          goto LAB_00193182;
          if ((local_30[iVar3 + 1] == 0x7ffffffe) &&
             (cVar2 = FUN_0018a5dc(param_1,iVar3), cVar2 == '\0')) {
            FUN_00189e36(param_1,iVar3);
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != 4);
    }
    else {
      cVar2 = FUN_0019050c(param_1);
      if (cVar2 != '\0') {
        return 0;
      }
      cVar2 = FUN_0018ffc0(param_1);
      if (cVar2 != '\0') {
        return 0;
      }
      iVar3 = 0;
      do {
        iVar5 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
        if (*(char *)(iVar3 + 0x10 + iVar5) != '\x01') {
          iVar6 = *(int *)(param_1 + 0x238);
          if (*(int *)(iVar6 + 0x38c) <= *(int *)(*(int *)(iVar6 + 0x3f4) + 0xa8))
          goto LAB_00193182;
          if ((local_30[iVar3 + 1] == 0x7ffffffe) &&
             (cVar2 = FUN_00187076(param_1,iVar3), cVar2 == '\0')) {
            FUN_00189efc(param_1,iVar3);
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 != 4);
    }
  }
  else {
    if (iVar3 == 0x8b) {
      cVar2 = FUN_0018ae1e(param_1);
      if (cVar2 != '\0') {
        return 0;
      }
      cVar2 = FUN_0018aa0c(param_1);
      if (cVar2 != '\0') {
        return 0;
      }
      FUN_00187d12(param_1);
      iVar5 = *(int *)(param_1 + 0xb0);
      iVar6 = *(int *)(param_1 + 0x238);
      goto LAB_00192d59;
    }
    if (iVar3 != 0x8c) goto LAB_00192d53;
    cVar2 = FUN_0018af8c(param_1);
    if (cVar2 != '\0') {
      return 0;
    }
  }
  iVar5 = *(int *)(param_1 + 0xb0);
  iVar6 = *(int *)(param_1 + 0x238);
LAB_00192d59:
  cVar2 = FUN_0011902c(*(undefined4 *)(*(int *)(iVar5 + 0x88) + 8),iVar6);
  if ((cVar2 == '\0') &&
     (cVar2 = FUN_00119104(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                           *(undefined4 *)(param_1 + 0x238)), cVar2 == '\0')) {
    iVar3 = 0;
    do {
      if (*(int *)(*(int *)(param_1 + 0x238) + 0x38c) <=
          *(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0xa8)) {
        return 0;
      }
      if (local_30[iVar3 + 1] != 0x7ffffffe) {
        FUN_00186d50(param_1,local_30[iVar3 + 1],iVar3);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 4);
  }
  else {
    iVar3 = 0;
    do {
      if (*(int *)(*(int *)(param_1 + 0x238) + 0x38c) <=
          *(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0xa8)) {
        return 0;
      }
      if (local_30[iVar3 + 1] != 0x7ffffffe) {
        FUN_00186d50(param_1,local_30[iVar3 + 1],iVar3);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 != 4);
  }
  return 0;
LAB_00193182:
  iVar5 = *(int *)(param_1 + 0xb0);
  goto LAB_00192d59;
}

/* FUN_00193232 @ 0x193232 (278 bytes) */
int FUN_00193232(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int local_20;
  
  iVar4 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
  if (*(int *)(iVar4 + 0x10) == DAT_001cc720) {
    local_20 = 0;
    iVar4 = *(int *)(param_1 + 0x30);
  }
  else {
    iVar4 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    local_20 = FUN_000f5950(*(undefined4 *)(iVar4 + 0x10));
    iVar4 = *(int *)(param_1 + 0x30 + local_20 * 4);
  }
  if (iVar4 == 0) {
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    if ((((byte)uVar1 & 1) == ((byte)uVar2 & 1)) &&
       (((byte)(uVar1 >> 1) & 1) == ((byte)(uVar2 >> 1) & 1))) {
      iVar4 = 0;
      do {
        cVar3 = FUN_00189c5c(param_1,iVar4,1,2);
        if (cVar3 == '\0') {
          return;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != 4);
      iVar4 = *(int *)(param_1 + 0x40 + local_20 * 4);
      if (iVar4 == 0) {
        iVar4 = FUN_001851d0(*(undefined4 *)(param_1 + 0x238),local_20,param_1);
      }
      *(undefined4 *)(iVar4 + 0xc) = 4;
      iVar5 = 4;
      do {
        *(int *)(param_1 + 0x40) = iVar4;
        param_1 = param_1 + 4;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  return;
}

/* FUN_00193348 @ 0x193348 (278 bytes) */
int FUN_00193348(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int local_20;
  
  iVar4 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
  if (*(int *)(iVar4 + 0x10) == DAT_001cc720) {
    local_20 = 0;
    iVar4 = *(int *)(param_1 + 0x30);
  }
  else {
    iVar4 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    local_20 = FUN_000f5950(*(undefined4 *)(iVar4 + 0x10));
    iVar4 = *(int *)(param_1 + 0x30 + local_20 * 4);
  }
  if (iVar4 == 0) {
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    if ((((byte)uVar1 & 1) == ((byte)uVar2 & 1)) &&
       (((byte)(uVar1 >> 1) & 1) == ((byte)(uVar2 >> 1) & 1))) {
      iVar4 = 0;
      do {
        cVar3 = FUN_00189c5c(param_1,iVar4,1,2);
        if (cVar3 == '\0') {
          return;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 != 3);
      iVar4 = *(int *)(param_1 + 0x40 + local_20 * 4);
      if (iVar4 == 0) {
        iVar4 = FUN_001851d0(*(undefined4 *)(param_1 + 0x238),local_20,param_1);
      }
      *(undefined4 *)(iVar4 + 0xc) = 4;
      iVar5 = 4;
      do {
        *(int *)(param_1 + 0x40) = iVar4;
        param_1 = param_1 + 4;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
  }
  return;
}

/* FUN_0019345e @ 0x19345e (57 bytes) */
int FUN_0019345e(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iStack_20;
  
  switch(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8)) {
  case 0x16:
  case 0x27:
  case 0x28:
  case 0x29:
  case 0x2a:
    FUN_00186db4(param_1);
    iVar7 = 0;
    iVar6 = param_1;
    do {
      iVar4 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
      if (((*(char *)(iVar7 + 0x10 + iVar4) != '\x01') && (*(int *)(iVar6 + 0x30) == 0)) &&
         (*(int *)(*(int *)(param_1 + 0xb0) + 0x124) < 1)) {
        if (*(int *)(iVar6 + 0x40) == 0) {
          uVar5 = FUN_001851d0(*(undefined4 *)(param_1 + 0x238),iVar7,param_1);
          *(undefined4 *)(iVar6 + 0x40) = uVar5;
        }
        *(undefined4 *)(*(int *)(iVar6 + 0x40) + 0x10) = 4;
      }
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 4;
    } while (iVar7 != 4);
    return;
  default:
    return;
  case 0x1c:
    break;
  case 0x1d:
    iVar6 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(int *)(iVar6 + 0x10) == DAT_001cc720) {
      iStack_20 = 0;
      iVar6 = *(int *)(param_1 + 0x30);
    }
    else {
      iVar6 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
      iStack_20 = FUN_000f5950(*(undefined4 *)(iVar6 + 0x10));
      iVar6 = *(int *)(param_1 + 0x30 + iStack_20 * 4);
    }
    if (iVar6 == 0) {
      uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
      uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
      if ((((byte)uVar1 & 1) == ((byte)uVar2 & 1)) &&
         (((byte)(uVar1 >> 1) & 1) == ((byte)(uVar2 >> 1) & 1))) {
        iVar6 = 0;
        do {
          cVar3 = FUN_00189c5c(param_1,iVar6,1,2);
          if (cVar3 == '\0') {
            return;
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 != 4);
        iVar6 = *(int *)(param_1 + 0x40 + iStack_20 * 4);
        if (iVar6 == 0) {
          iVar6 = FUN_001851d0(*(undefined4 *)(param_1 + 0x238),iStack_20,param_1);
        }
        *(undefined4 *)(iVar6 + 0xc) = 4;
        iVar7 = 4;
        do {
          *(int *)(param_1 + 0x40) = iVar6;
          param_1 = param_1 + 4;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
      }
    }
    return;
  }
  iVar6 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
  if (*(int *)(iVar6 + 0x10) == DAT_001cc720) {
    iStack_20 = 0;
    iVar6 = *(int *)(param_1 + 0x30);
  }
  else {
    iVar6 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    iStack_20 = FUN_000f5950(*(undefined4 *)(iVar6 + 0x10));
    iVar6 = *(int *)(param_1 + 0x30 + iStack_20 * 4);
  }
  if (iVar6 == 0) {
    uVar1 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xb8);
    uVar2 = *(uint *)(*(int *)(param_1 + 0xb0) + 0xd0);
    if ((((byte)uVar1 & 1) == ((byte)uVar2 & 1)) &&
       (((byte)(uVar1 >> 1) & 1) == ((byte)(uVar2 >> 1) & 1))) {
      iVar6 = 0;
      do {
        cVar3 = FUN_00189c5c(param_1,iVar6,1,2);
        if (cVar3 == '\0') {
          return;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 != 3);
      iVar6 = *(int *)(param_1 + 0x40 + iStack_20 * 4);
      if (iVar6 == 0) {
        iVar6 = FUN_001851d0(*(undefined4 *)(param_1 + 0x238),iStack_20,param_1);
      }
      *(undefined4 *)(iVar6 + 0xc) = 4;
      iVar7 = 4;
      do {
        *(int *)(param_1 + 0x40) = iVar6;
        param_1 = param_1 + 4;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
  }
  return;
}

/* FUN_0019351e @ 0x19351e (85 bytes) */
int FUN_0019351e(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
  char cVar1;
  
  cVar1 = FUN_0010a62e(param_1,param_3);
  if ((((cVar1 != '\0') && (cVar1 = (**(code **)(*param_1 + 0x68))(param_1), cVar1 == '\0')) &&
      ((*(byte *)((int)param_1 + 0x15) & 2) == 0)) &&
     ((*(int *)(param_1[0x22] + 8) != 0x8e && (param_1[0x56] == param_2)))) {
    return 1;
  }
  return 0;
}

/* FUN_00193574 @ 0x193574 (179 bytes) */
int FUN_00193574(param_1, param_2)
  int *param_1;
  int *param_2;
{
  char cVar1;
  int iVar2;
  int local_10;
  
  if (param_1[0x20] == 0) {
LAB_0019358c:
    local_10 = 0;
  }
  else {
    cVar1 = FUN_0012dfd8(param_1[0x26]);
    if ((cVar1 == '\0') || ((*(byte *)(param_1 + 5) & 2) != 0)) goto LAB_0019358c;
    cVar1 = (**(code **)(*param_1 + 0x50))(param_1);
    if (cVar1 != '\0') goto LAB_0019358c;
    local_10 = FUN_000f60f4(param_1);
  }
  if (param_2[0x20] != 0) {
    cVar1 = FUN_0012dfd8(param_2[0x26]);
    if ((cVar1 != '\0') && ((*(byte *)(param_2 + 5) & 2) == 0)) {
      cVar1 = (**(code **)(*param_2 + 0x50))(param_2);
      if (cVar1 == '\0') {
        iVar2 = FUN_000f60f4(param_2);
        goto LAB_0019359f;
      }
    }
  }
  iVar2 = 0;
LAB_0019359f:
  return param_2[0x54] - iVar2 < param_1[0x54] - local_10;
}

/* FUN_00193628 @ 0x193628 (224 bytes) */
int FUN_00193628(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int local_1c;
  
  iVar6 = *(int *)(param_2 + 0x98);
  if (*(int *)(iVar6 + 8) != 0) {
    local_1c = 0;
    do {
      while ((*(byte *)(iVar6 + 0x14) & 1) != 0) {
        *(int *)(iVar6 + 0x150) = local_1c;
        uVar1 = *(undefined4 *)(*param_1 + 0xbc);
        puVar4 = (undefined4 *)FUN_001a7bca(uVar1,0x1c);
        *puVar4 = uVar1;
        puVar2 = (uint *)param_1[7];
        uVar3 = puVar2[1];
        if (uVar3 < *puVar2) {
          _memset((void *)(uVar3 * 4 + puVar2[2]),0,4);
          puVar2[1] = uVar3 + 1;
          puVar5 = (undefined4 *)(uVar3 * 4 + puVar2[2]);
        }
        else {
          puVar5 = (undefined4 *)FUN_001a7f7c(puVar2,uVar3);
        }
        *puVar5 = puVar4 + 1;
        local_1c = local_1c + 1;
        iVar6 = *(int *)(iVar6 + 8);
        if (*(int *)(iVar6 + 8) == 0) {
          return;
        }
      }
      iVar6 = *(int *)(iVar6 + 8);
    } while (*(int *)(iVar6 + 8) != 0);
  }
  return;
}

/* FUN_00193708 @ 0x193708 (894 bytes) */
int FUN_00193708(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int *param_3;
  undefined4 *param_4;
{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  int local_2c;
  
  iVar1 = *(int *)(param_2 + 0x98);
  iVar11 = *(int *)(iVar1 + 8);
  while (iVar11 != 0) {
    if ((*(byte *)(iVar1 + 0x14) & 1) != 0) {
      uVar2 = *(uint *)(iVar1 + 0x150);
      puVar3 = *(uint **)(param_1 + 0x1c);
      if (uVar2 < *puVar3) {
        uVar4 = puVar3[1];
        if (uVar4 <= uVar2) {
          _memset((void *)(puVar3[2] + uVar4 * 4),0,(uVar2 - uVar4) * 4 + 4);
          puVar3[1] = uVar2 + 1;
        }
        puVar8 = (undefined4 *)(puVar3[2] + uVar2 * 4);
      }
      else {
        puVar8 = (undefined4 *)FUN_001a7f7c(puVar3,uVar2);
      }
      puVar8 = (undefined4 *)*puVar8;
      *puVar8 = 1;
      puVar8[1] = 1;
      puVar8[2] = 0;
      puVar8[3] = 0;
      puVar8[4] = 0;
      *(undefined1 *)(puVar8 + 5) = 1;
      if ((*(int *)(*(int *)(iVar1 + 0x88) + 8) != 0x8e) && (0 < *(int *)(iVar1 + 0x84))) {
        local_2c = 1;
        do {
          iVar11 = FUN_0010b180(iVar1,local_2c);
          if (param_2 == *(int *)(iVar11 + 0x158)) {
            uVar2 = *(uint *)(iVar11 + 0x150);
            puVar3 = *(uint **)(param_1 + 0x1c);
            if (uVar2 < *puVar3) {
              uVar4 = puVar3[1];
              if (uVar4 <= uVar2) {
                _memset((void *)(puVar3[2] + uVar4 * 4),0,(uVar2 - uVar4) * 4 + 4);
                puVar3[1] = uVar2 + 1;
              }
              piVar10 = (int *)(puVar3[2] + uVar2 * 4);
            }
            else {
              piVar10 = (int *)FUN_001a7f7c(puVar3,uVar2);
            }
            iVar6 = *(int *)(*piVar10 + 4) + 1;
            iVar11 = puVar8[1];
            if ((int)puVar8[1] < iVar6) {
              iVar11 = iVar6;
            }
            puVar8[1] = iVar11;
          }
          local_2c = local_2c + 1;
        } while (local_2c <= *(int *)(iVar1 + 0x84));
      }
    }
    iVar1 = *(int *)(iVar1 + 8);
    iVar11 = *(int *)(iVar1 + 8);
  }
  *param_3 = 0;
  FUN_001825e0(*(undefined4 *)(param_1 + 8));
  iVar1 = *(int *)(param_2 + 0xa0);
  iVar11 = *(int *)(iVar1 + 4);
  while (iVar11 != 0) {
    if (((*(byte *)(iVar1 + 0x14) & 1) != 0) && (*(int *)(*(int *)(iVar1 + 0x88) + 8) != 0x8e)) {
      uVar2 = *(uint *)(iVar1 + 0x150);
      puVar3 = *(uint **)(param_1 + 0x1c);
      if (uVar2 < *puVar3) {
        uVar4 = puVar3[1];
        if (uVar4 <= uVar2) {
          _memset((void *)(puVar3[2] + uVar4 * 4),0,(uVar2 - uVar4) * 4 + 4);
          puVar3[1] = uVar2 + 1;
        }
        puVar8 = (undefined4 *)(puVar3[2] + uVar2 * 4);
      }
      else {
        puVar8 = (undefined4 *)FUN_001a7f7c(puVar3,uVar2);
      }
      piVar10 = (int *)*puVar8;
      FUN_00182720(*(undefined4 *)(param_1 + 8),iVar1);
      if (0 < *(int *)(iVar1 + 0x84)) {
        iVar11 = 1;
        do {
          iVar6 = FUN_0010b180(iVar1,iVar11);
          if (param_2 == *(int *)(iVar6 + 0x158)) {
            uVar2 = *(uint *)(iVar6 + 0x150);
            puVar3 = *(uint **)(param_1 + 0x1c);
            if (uVar2 < *puVar3) {
              uVar4 = puVar3[1];
              if (uVar4 <= uVar2) {
                _memset((void *)(puVar3[2] + uVar4 * 4),0,(uVar2 - uVar4) * 4 + 4);
                puVar3[1] = uVar2 + 1;
              }
              piVar9 = (int *)(puVar3[2] + uVar2 * 4);
            }
            else {
              piVar9 = (int *)FUN_001a7f7c(puVar3,uVar2);
            }
            piVar9 = (int *)*piVar9;
            iVar6 = *piVar9;
            if (*piVar9 < *piVar10 + 1) {
              iVar6 = *piVar10 + 1;
            }
            *piVar9 = iVar6;
            piVar9[3] = iVar1;
            piVar9[4] = iVar11;
            iVar7 = *param_3;
            if (*param_3 <= iVar6) {
              iVar7 = iVar6;
            }
            *param_3 = iVar7;
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 <= *(int *)(iVar1 + 0x84));
      }
    }
    iVar1 = *(int *)(iVar1 + 4);
    iVar11 = *(int *)(iVar1 + 4);
  }
  uVar5 = (**(code **)(**(int **)(param_1 + 8) + 0x5c))(*(int **)(param_1 + 8));
  *param_4 = uVar5;
  return;
}

/* FUN_00193a86 @ 0x193a86 (9713 bytes) */
int FUN_00193a86(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  char cVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int *piVar12;
  int iVar13;
  undefined4 *puVar14;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined4 *puVar15;
  int iVar16;
  int *piVar17;
  int iVar18;
  int iVar19;
  undefined2 extraout_var_01;
  uint uVar20;
  byte bVar21;
  uint uVar22;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_ac;
  undefined4 local_a8;
  int local_a4;
  int local_a0;
  int local_6c;
  int local_58;
  int local_54;
  int local_50;
  uint local_4c;
  uint local_48;
  int local_44;
  int local_40;
  undefined1 local_34 [8];
  int local_2c;
  
  uVar9 = *(undefined4 *)(*param_1 + 0xbc);
  puVar8 = (undefined4 *)FUN_001a7bca(uVar9,0x14);
  *puVar8 = uVar9;
  puVar1 = puVar8 + 1;
  puVar8[4] = uVar9;
  puVar8[2] = 0;
  puVar8[1] = 2;
  uVar9 = FUN_001a7bca(uVar9,8);
  puVar8[3] = uVar9;
  uVar9 = *(undefined4 *)(*param_1 + 0xbc);
  puVar10 = (undefined4 *)FUN_001a7bca(uVar9,0x14);
  *puVar10 = uVar9;
  puVar2 = puVar10 + 1;
  puVar10[4] = uVar9;
  puVar10[2] = 0;
  puVar10[1] = 2;
  uVar9 = FUN_001a7bca(uVar9,8);
  puVar10[3] = uVar9;
  uVar9 = *(undefined4 *)(*param_1 + 0xbc);
  puVar11 = (undefined4 *)FUN_001a7bca(uVar9,0x14);
  *puVar11 = uVar9;
  puVar3 = puVar11 + 1;
  puVar11[4] = uVar9;
  puVar11[2] = 0;
  puVar11[1] = 2;
  uVar9 = FUN_001a7bca(uVar9,8);
  puVar11[3] = uVar9;
  uVar4 = puVar8[2];
  if (uVar4 < *puVar1) {
    _memset((void *)(uVar4 * 4 + puVar8[3]),0,4);
    puVar8[2] = uVar4 + 1;
    piVar12 = (int *)(uVar4 * 4 + puVar8[3]);
  }
  else {
    piVar12 = (int *)FUN_001a7f7c(puVar1,uVar4);
  }
  *piVar12 = param_3;
  while (puVar8[2] != 0) {
    while( true ) {
      uVar4 = puVar8[2];
      if (uVar4 - 1 < uVar4) {
        piVar12 = (int *)(puVar8[3] + (uVar4 - 1) * 4);
      }
      else {
        piVar12 = (int *)0x0;
      }
      iVar16 = *piVar12;
      FUN_001a7f3c(puVar1,uVar4 - 1);
      local_44 = 1;
      local_d0 = iVar16 + 0xa4;
      local_cc = 0x98;
      local_c8 = local_d0;
      do {
        iVar13 = FUN_0010b180(iVar16,local_44);
        if (param_2 == *(int *)(iVar13 + 0x158)) {
          uVar4 = *(uint *)(iVar13 + 0x150);
          puVar5 = (uint *)param_1[7];
          if (uVar4 < *puVar5) {
            uVar22 = puVar5[1];
            if (uVar22 <= uVar4) {
              _memset((void *)(puVar5[2] + uVar22 * 4),0,(uVar4 - uVar22) * 4 + 4);
              puVar5[1] = uVar4 + 1;
            }
            piVar12 = (int *)(puVar5[2] + uVar4 * 4);
          }
          else {
            piVar12 = (int *)FUN_001a7f7c(puVar5,uVar4);
          }
          if (*(char *)(*piVar12 + 0x14) == '\0') {
            if (((*(byte *)(local_cc + 0x20 + iVar16) & 2) != 0) &&
               (*(int *)(*(int *)(iVar13 + 0x88) + 8) == 0x13)) {
              local_ac = 1;
              iVar19 = iVar13 + 0xa4;
              iVar18 = 0x98;
              do {
                FUN_00109c0e(iVar19,2,1);
                if ((*(byte *)(iVar18 + 0x20 + iVar13) & 1) != 0) {
                  FUN_00109c0e(iVar19,1,0);
                }
                local_ac = local_ac + 1;
                iVar18 = iVar18 + 0x18;
                iVar19 = iVar19 + 0x18;
              } while (local_ac != 3);
              FUN_00109c0e(local_d0,2,0);
            }
            uVar4 = *(uint *)(local_cc + 0x20 + iVar16);
            if ((((uVar4 & 1) != 0) && ((uVar4 & 2) == 0)) &&
               (*(int *)(*(int *)(iVar13 + 0x88) + 8) == 0x12)) {
              local_40 = 1;
              iVar19 = iVar13 + 0xa4;
              iVar18 = 0x98;
              do {
                FUN_00109c0e(iVar19,1,*(byte *)(iVar18 + 0x20 + iVar13) & 1 ^ 1);
                local_40 = local_40 + 1;
                iVar18 = iVar18 + 0x18;
                iVar19 = iVar19 + 0x18;
              } while (local_40 != 3);
              FUN_00109c0e(local_c8,1,0);
            }
            uVar4 = puVar8[2];
            if (uVar4 < *puVar1) {
              _memset((void *)(uVar4 * 4 + puVar8[3]),0,4);
              puVar8[2] = uVar4 + 1;
              piVar12 = (int *)(uVar4 * 4 + puVar8[3]);
            }
            else {
              piVar12 = (int *)FUN_001a7f7c(puVar1,uVar4);
            }
            *piVar12 = iVar13;
          }
        }
        local_44 = local_44 + 1;
        local_d0 = local_d0 + 0x18;
        local_cc = local_cc + 0x18;
        local_c8 = local_c8 + 0x18;
      } while (local_44 != 3);
      iVar13 = FUN_0010b0f4(iVar16,1);
      cVar7 = FUN_000f5672(*(undefined4 *)(iVar13 + 0x10));
      if (cVar7 != '\0') {
        iVar13 = FUN_0010b0f4(iVar16,2);
        FUN_000f5672(*(undefined4 *)(iVar13 + 0x10));
      }
      iVar13 = FUN_0010b0f4(iVar16,1);
      cVar7 = FUN_000f5672(*(undefined4 *)(iVar13 + 0x10));
      if (cVar7 == '\0') break;
      uVar4 = puVar10[2];
      if (uVar4 < *puVar2) {
        _memset((void *)(uVar4 * 4 + puVar10[3]),0,4);
        puVar10[2] = uVar4 + 1;
        piVar12 = (int *)(uVar4 * 4 + puVar10[3]);
      }
      else {
        piVar12 = (int *)FUN_001a7f7c(puVar2,uVar4);
      }
      *piVar12 = iVar16;
      uVar4 = puVar11[2];
      if (uVar4 < *puVar3) {
        _memset((void *)(uVar4 * 4 + puVar11[3]),0,4);
        puVar11[2] = uVar4 + 1;
        puVar14 = (undefined4 *)(uVar4 * 4 + puVar11[3]);
      }
      else {
        puVar14 = (undefined4 *)FUN_001a7f7c(puVar3,uVar4);
      }
      *puVar14 = 1;
      if (puVar8[2] == 0) goto LAB_00193d94;
    }
    iVar13 = FUN_0010b0f4(iVar16,2);
    cVar7 = FUN_000f5672(*(undefined4 *)(iVar13 + 0x10));
    if (cVar7 != '\0') {
      uVar4 = puVar10[2];
      if (uVar4 < *puVar2) {
        _memset((void *)(uVar4 * 4 + puVar10[3]),0,4);
        puVar10[2] = uVar4 + 1;
        piVar12 = (int *)(uVar4 * 4 + puVar10[3]);
      }
      else {
        piVar12 = (int *)FUN_001a7f7c(puVar2,uVar4);
      }
      *piVar12 = iVar16;
      uVar4 = puVar11[2];
      if (uVar4 < *puVar3) {
        _memset((void *)(uVar4 * 4 + puVar11[3]),0,4);
        puVar11[2] = uVar4 + 1;
        puVar14 = (undefined4 *)(uVar4 * 4 + puVar11[3]);
      }
      else {
        puVar14 = (undefined4 *)FUN_001a7f7c(puVar3,uVar4);
      }
      *puVar14 = 2;
    }
  }
LAB_00193d94:
  iVar16 = *(int *)(param_3 + 0x88);
  if ((*(int *)(iVar16 + 8) == 0x13) || (*(int *)(iVar16 + 8) == 0x14)) {
    local_a8 = 0x13;
  }
  else if (*(int *)(iVar16 + 8) == 0x12) {
    local_a8 = 0x12;
  }
  else {
    local_a8 = 0;
  }
  FUN_001a7e06(local_34);
  uVar22 = puVar10[2];
  uVar4 = uVar22 - 1;
  local_48 = uVar4;
  if ((int)uVar4 < 1) {
    local_a4 = 0;
  }
  else {
    local_54 = uVar4 * 4;
    local_50 = local_54 + -4;
    local_a4 = 0;
    local_4c = uVar22;
    do {
      iVar16 = FUN_0010a17a(local_a8,*param_1);
      *(undefined4 *)(iVar16 + 0x94) = *(undefined4 *)(iVar16 + 0x14c);
      *(undefined4 *)(iVar16 + 0x98) = 0;
      *(undefined4 *)(iVar16 + 0x9c) = DAT_001cc768;
      uVar20 = local_48 - 1;
      if (uVar20 < *puVar2) {
        uVar6 = puVar10[2];
        if (uVar6 <= uVar20) {
          _memset((void *)(puVar10[3] + uVar6 * 4),0,(uVar20 - uVar6) * 4 + 4);
          puVar10[2] = local_48;
        }
        piVar12 = (int *)(local_50 + puVar10[3]);
      }
      else {
        piVar12 = (int *)FUN_001a7f7c(puVar2,uVar20);
      }
      if (param_3 != *piVar12) {
        if (uVar20 < *puVar2) {
          uVar6 = puVar10[2];
          if (uVar6 <= uVar20) {
            _memset((void *)(puVar10[3] + uVar6 * 4),0,(uVar20 - uVar6) * 4 + 4);
            puVar10[2] = local_48;
          }
          piVar12 = (int *)(local_50 + puVar10[3]);
        }
        else {
          piVar12 = (int *)FUN_001a7f7c(puVar2,uVar20);
        }
        local_a4 = local_a4 + *(int *)(*piVar12 + 0x124);
      }
      if (local_48 < *puVar2) {
        uVar6 = puVar10[2];
        if (uVar6 <= local_48) {
          _memset((void *)(puVar10[3] + uVar6 * 4),0,(local_48 - uVar6) * 4 + 4);
          puVar10[2] = local_4c;
        }
        piVar12 = (int *)(local_54 + puVar10[3]);
      }
      else {
        piVar12 = (int *)FUN_001a7f7c(puVar2,local_48);
      }
      if (param_3 != *piVar12) {
        if (local_48 < *puVar2) {
          uVar6 = puVar10[2];
          if (uVar6 <= local_48) {
            _memset((void *)(puVar10[3] + uVar6 * 4),0,(local_48 - uVar6) * 4 + 4);
            puVar10[2] = local_4c;
          }
          piVar12 = (int *)(local_54 + puVar10[3]);
        }
        else {
          piVar12 = (int *)FUN_001a7f7c(puVar2,local_48);
        }
        local_a4 = local_a4 + *(int *)(*piVar12 + 0x124);
      }
      if (local_a4 == 0) {
        iVar13 = *param_1;
        if (uVar20 < *puVar3) goto LAB_00193e65;
LAB_001944b2:
        puVar14 = (undefined4 *)FUN_001a7f7c(puVar3,uVar20);
        uVar9 = *puVar14;
        if (uVar20 < *puVar2) goto LAB_00193e92;
LAB_001944e0:
        puVar14 = (undefined4 *)FUN_001a7f7c(puVar2,uVar20);
      }
      else {
        iVar13 = *(int *)(*(int *)(*param_1 + 0x54) + 0x58);
        if (local_a4 < iVar13) {
          *(int *)(iVar16 + 0x124) = iVar13;
          iVar13 = *param_1;
          local_a4 = local_a4 - *(int *)(*(int *)(iVar13 + 0x54) + 0x58);
        }
        else {
          iVar13 = *(int *)(*(int *)(*param_1 + 0x54) + 0x5c);
          if (iVar13 < local_a4) {
            *(int *)(iVar16 + 0x124) = iVar13;
            iVar13 = *param_1;
            local_a4 = local_a4 - *(int *)(*(int *)(iVar13 + 0x54) + 0x5c);
          }
          else {
            *(int *)(iVar16 + 0x124) = local_a4;
            local_a4 = 0;
            iVar13 = *param_1;
          }
        }
        if (*puVar3 <= uVar20) goto LAB_001944b2;
LAB_00193e65:
        uVar6 = puVar11[2];
        if (uVar6 <= uVar20) {
          _memset((void *)(puVar11[3] + uVar6 * 4),0,(uVar20 - uVar6) * 4 + 4);
          puVar11[2] = local_48;
        }
        uVar9 = *(undefined4 *)(local_50 + puVar11[3]);
        if (*puVar2 <= uVar20) goto LAB_001944e0;
LAB_00193e92:
        uVar6 = puVar10[2];
        if (uVar6 <= uVar20) {
          _memset((void *)(puVar10[3] + uVar6 * 4),0,(uVar20 - uVar6) * 4 + 4);
          puVar10[2] = local_48;
        }
        puVar14 = (undefined4 *)(local_50 + puVar10[3]);
      }
      uVar9 = FUN_0010b180(*puVar14,uVar9);
      FUN_0010ba02(iVar16,1,uVar9,0,iVar13);
      iVar13 = *param_1;
      if (local_48 < *puVar3) {
        uVar6 = puVar11[2];
        if (uVar6 <= local_48) {
          _memset((void *)(puVar11[3] + uVar6 * 4),0,(local_48 - uVar6) * 4 + 4);
          puVar11[2] = local_4c;
        }
        puVar14 = (undefined4 *)(local_54 + puVar11[3]);
      }
      else {
        puVar14 = (undefined4 *)FUN_001a7f7c(puVar3,local_48);
      }
      uVar9 = *puVar14;
      if (local_48 < *puVar2) {
        uVar6 = puVar10[2];
        if (uVar6 <= local_48) {
          _memset((void *)(puVar10[3] + uVar6 * 4),0,(local_48 - uVar6) * 4 + 4);
          puVar10[2] = local_4c;
        }
        puVar14 = (undefined4 *)(local_54 + puVar10[3]);
      }
      else {
        puVar14 = (undefined4 *)FUN_001a7f7c(puVar2,local_48);
      }
      uVar9 = FUN_0010b180(*puVar14,uVar9);
      FUN_0010ba02(iVar16,2,uVar9,0,iVar13);
      if (uVar20 < *puVar3) {
        uVar6 = puVar11[2];
        if (uVar6 <= uVar20) {
          _memset((void *)(puVar11[3] + uVar6 * 4),0,(uVar20 - uVar6) * 4 + 4);
          puVar11[2] = local_48;
        }
        puVar14 = (undefined4 *)(local_50 + puVar11[3]);
      }
      else {
        puVar14 = (undefined4 *)FUN_001a7f7c(puVar3,uVar20);
      }
      uVar9 = *puVar14;
      if (uVar20 < *puVar2) {
        uVar6 = puVar10[2];
        if (uVar6 <= uVar20) {
          _memset((void *)(puVar10[3] + uVar6 * 4),0,(uVar20 - uVar6) * 4 + 4);
          puVar10[2] = local_48;
        }
        puVar14 = (undefined4 *)(local_50 + puVar10[3]);
      }
      else {
        puVar14 = (undefined4 *)FUN_001a7f7c(puVar2,uVar20);
      }
      iVar13 = FUN_0010b0f4(*puVar14,uVar9);
      FUN_000f5c30(*(undefined4 *)(iVar13 + 0x10));
      if (local_48 < *puVar3) {
        uVar6 = puVar11[2];
        if (uVar6 <= local_48) {
          _memset((void *)(puVar11[3] + uVar6 * 4),0,(local_48 - uVar6) * 4 + 4);
          puVar11[2] = local_4c;
        }
        puVar14 = (undefined4 *)(local_54 + puVar11[3]);
      }
      else {
        puVar14 = (undefined4 *)FUN_001a7f7c(puVar3,local_48);
      }
      uVar9 = *puVar14;
      if (local_48 < *puVar2) {
        uVar6 = puVar10[2];
        if (uVar6 <= local_48) {
          _memset((void *)(puVar10[3] + uVar6 * 4),0,(local_48 - uVar6) * 4 + 4);
          puVar10[2] = local_4c;
        }
        puVar14 = (undefined4 *)(local_54 + puVar10[3]);
      }
      else {
        puVar14 = (undefined4 *)FUN_001a7f7c(puVar2,local_48);
      }
      iVar13 = FUN_0010b0f4(*puVar14,uVar9);
      FUN_000f5c30(*(undefined4 *)(iVar13 + 0x10));
      iVar13 = FUN_0010b0f4(iVar16,1);
      *(uint *)(iVar13 + 0x10) = CONCAT22(extraout_var,0x404) & 0xff00ffff | 0x40000;
      iVar13 = FUN_0010b0f4(iVar16,2);
      *(uint *)(iVar13 + 0x10) = CONCAT22(extraout_var_00,0x404) & 0xff00ffff | 0x40000;
      if (uVar20 < *puVar3) {
        uVar6 = puVar11[2];
        if (uVar6 <= uVar20) {
          _memset((void *)(puVar11[3] + uVar6 * 4),0,(uVar20 - uVar6) * 4 + 4);
          puVar11[2] = local_48;
        }
        piVar12 = (int *)(local_50 + puVar11[3]);
      }
      else {
        piVar12 = (int *)FUN_001a7f7c(puVar3,uVar20);
      }
      iVar13 = *piVar12;
      if (uVar20 < *puVar2) {
        uVar6 = puVar10[2];
        if (uVar6 <= uVar20) {
          _memset((void *)(puVar10[3] + uVar6 * 4),0,(uVar20 - uVar6) * 4 + 4);
          puVar10[2] = local_48;
        }
        piVar12 = (int *)(local_50 + puVar10[3]);
      }
      else {
        piVar12 = (int *)FUN_001a7f7c(puVar2,uVar20);
      }
      FUN_00109c0e(iVar16 + 0xa4,1,*(byte *)(*piVar12 + 0xa0 + iVar13 * 0x18) & 1);
      if (local_48 < *puVar3) {
        uVar6 = puVar11[2];
        if (uVar6 <= local_48) {
          _memset((void *)(puVar11[3] + uVar6 * 4),0,(local_48 - uVar6) * 4 + 4);
          puVar11[2] = local_4c;
        }
        piVar12 = (int *)(local_54 + puVar11[3]);
      }
      else {
        piVar12 = (int *)FUN_001a7f7c(puVar3,local_48);
      }
      iVar13 = *piVar12;
      if (local_48 < *puVar2) {
        uVar6 = puVar10[2];
        if (uVar6 <= local_48) {
          _memset((void *)(puVar10[3] + uVar6 * 4),0,(local_48 - uVar6) * 4 + 4);
          puVar10[2] = local_4c;
        }
        piVar12 = (int *)(local_54 + puVar10[3]);
      }
      else {
        piVar12 = (int *)FUN_001a7f7c(puVar2,local_48);
      }
      FUN_00109c0e(iVar16 + 0xbc,1,*(byte *)(*piVar12 + 0xa0 + iVar13 * 0x18) & 1);
      if (uVar20 < *puVar3) {
        uVar6 = puVar11[2];
        if (uVar6 <= uVar20) {
          _memset((void *)(puVar11[3] + uVar6 * 4),0,(uVar20 - uVar6) * 4 + 4);
          puVar11[2] = local_48;
        }
        piVar12 = (int *)(local_50 + puVar11[3]);
      }
      else {
        piVar12 = (int *)FUN_001a7f7c(puVar3,uVar20);
      }
      iVar13 = *piVar12;
      if (uVar20 < *puVar2) {
        uVar6 = puVar10[2];
        if (uVar6 <= uVar20) {
          _memset((void *)(puVar10[3] + uVar6 * 4),0,(uVar20 - uVar6) * 4 + 4);
          puVar10[2] = local_48;
        }
        piVar12 = (int *)(local_50 + puVar10[3]);
      }
      else {
        piVar12 = (int *)FUN_001a7f7c(puVar2,uVar20);
      }
      FUN_00109c0e(iVar16 + 0xa4,2,*(uint *)(*piVar12 + 0xa0 + iVar13 * 0x18) >> 1 & 1);
      if (local_48 < *puVar3) {
        uVar20 = puVar11[2];
        if (uVar20 <= local_48) {
          _memset((void *)(puVar11[3] + uVar20 * 4),0,(local_48 - uVar20) * 4 + 4);
          puVar11[2] = local_4c;
        }
        piVar12 = (int *)(local_54 + puVar11[3]);
      }
      else {
        piVar12 = (int *)FUN_001a7f7c(puVar3,local_48);
      }
      iVar13 = *piVar12;
      if (local_48 < *puVar2) {
        uVar20 = puVar10[2];
        if (uVar20 <= local_48) {
          _memset((void *)(puVar10[3] + uVar20 * 4),0,(local_48 - uVar20) * 4 + 4);
          puVar10[2] = local_4c;
        }
        piVar12 = (int *)(local_54 + puVar10[3]);
      }
      else {
        piVar12 = (int *)FUN_001a7f7c(puVar2,local_48);
      }
      FUN_00109c0e(iVar16 + 0xbc,2,*(uint *)(*piVar12 + 0xa0 + iVar13 * 0x18) >> 1 & 1);
      *(undefined4 *)(iVar16 + 0x150) = *(undefined4 *)(param_1[7] + 4);
      uVar9 = *(undefined4 *)(*param_1 + 0xbc);
      puVar14 = (undefined4 *)FUN_001a7bca(uVar9,0x1c);
      *puVar14 = uVar9;
      puVar5 = (uint *)param_1[7];
      uVar20 = puVar5[1];
      if (uVar20 < *puVar5) {
        _memset((void *)(uVar20 * 4 + puVar5[2]),0,4);
        puVar5[1] = uVar20 + 1;
        puVar15 = (undefined4 *)(uVar20 * 4 + puVar5[2]);
      }
      else {
        puVar15 = (undefined4 *)FUN_001a7f7c(puVar5,uVar20);
      }
      *puVar15 = puVar14 + 1;
      FUN_001a7cd6(local_34,iVar16);
      local_48 = local_48 - 2;
      local_54 = local_54 + -8;
      local_50 = local_50 + -8;
      local_4c = local_4c - 2;
    } while (0 < (int)local_48);
  }
  iVar16 = local_2c;
  local_a0 = local_2c;
  if (local_48 == 0) {
    iVar13 = FUN_0010a17a(local_a8,*param_1);
    *(undefined4 *)(iVar13 + 0x94) = *(undefined4 *)(iVar13 + 0x14c);
    *(undefined4 *)(iVar13 + 0x98) = 0;
    *(undefined4 *)(iVar13 + 0x9c) = DAT_001cc768;
    if (*puVar2 == 0) {
      piVar12 = (int *)FUN_001a7f7c(puVar2,0);
    }
    else {
      if (puVar10[2] == 0) {
        *(undefined4 *)puVar10[3] = 0;
        puVar10[2] = 1;
      }
      piVar12 = (int *)puVar10[3];
    }
    if (param_3 != *piVar12) {
      if (*puVar2 == 0) {
        piVar12 = (int *)FUN_001a7f7c(puVar2,0);
      }
      else {
        if (puVar10[2] == 0) {
          *(undefined4 *)puVar10[3] = 0;
          puVar10[2] = 1;
        }
        piVar12 = (int *)puVar10[3];
      }
      local_a4 = local_a4 + *(int *)(*piVar12 + 0x124);
    }
    if (local_a4 == 0) {
      iVar19 = *param_1;
    }
    else {
      iVar19 = *(int *)(*(int *)(*param_1 + 0x54) + 0x58);
      if (local_a4 < iVar19) {
        *(int *)(iVar13 + 0x124) = iVar19;
        iVar19 = *param_1;
        local_a4 = local_a4 - *(int *)(*(int *)(iVar19 + 0x54) + 0x58);
      }
      else {
        iVar19 = *(int *)(*(int *)(*param_1 + 0x54) + 0x5c);
        if (iVar19 < local_a4) {
          *(int *)(iVar13 + 0x124) = iVar19;
          iVar19 = *param_1;
          local_a4 = local_a4 - *(int *)(*(int *)(iVar19 + 0x54) + 0x5c);
        }
        else {
          *(int *)(iVar13 + 0x124) = local_a4;
          local_a4 = 0;
          iVar19 = *param_1;
        }
      }
    }
    FUN_0010ba02(iVar13,1,iVar16,0,iVar19);
    iVar19 = FUN_0010b0f4(iVar13,1);
    *(undefined4 *)(iVar19 + 0x10) = DAT_001cc764;
    iVar19 = *param_1;
    if (*puVar3 == 0) {
      puVar14 = (undefined4 *)FUN_001a7f7c(puVar3,0);
    }
    else {
      if (puVar11[2] == 0) {
        *(undefined4 *)puVar11[3] = 0;
        puVar11[2] = 1;
      }
      puVar14 = (undefined4 *)puVar11[3];
    }
    uVar9 = *puVar14;
    if (*puVar2 == 0) {
      puVar14 = (undefined4 *)FUN_001a7f7c(puVar2,0);
    }
    else {
      if (puVar10[2] == 0) {
        *(undefined4 *)puVar10[3] = 0;
        puVar10[2] = 1;
      }
      puVar14 = (undefined4 *)puVar10[3];
    }
    uVar9 = FUN_0010b180(*puVar14,uVar9);
    FUN_0010ba02(iVar13,2,uVar9,0,iVar19);
    if (*puVar3 == 0) {
      puVar14 = (undefined4 *)FUN_001a7f7c(puVar3,0);
    }
    else {
      if (puVar11[2] == 0) {
        *(undefined4 *)puVar11[3] = 0;
        puVar11[2] = 1;
      }
      puVar14 = (undefined4 *)puVar11[3];
    }
    uVar9 = *puVar14;
    if (*puVar2 == 0) {
      puVar14 = (undefined4 *)FUN_001a7f7c(puVar2,0);
    }
    else {
      if (puVar10[2] == 0) {
        *(undefined4 *)puVar10[3] = 0;
        puVar10[2] = 1;
      }
      puVar14 = (undefined4 *)puVar10[3];
    }
    iVar19 = FUN_0010b0f4(*puVar14,uVar9);
    FUN_000f5c30(*(undefined4 *)(iVar19 + 0x10));
    iVar19 = FUN_0010b0f4(iVar13,2);
    *(uint *)(iVar19 + 0x10) = CONCAT22(extraout_var_01,0x404) & 0xff00ffff | 0x40000;
    if (*puVar3 == 0) {
      piVar12 = (int *)FUN_001a7f7c(puVar3,0);
    }
    else {
      if (puVar11[2] == 0) {
        *(undefined4 *)puVar11[3] = 0;
        puVar11[2] = 1;
      }
      piVar12 = (int *)puVar11[3];
    }
    iVar19 = *piVar12;
    if (*puVar2 == 0) {
      piVar12 = (int *)FUN_001a7f7c(puVar2,0);
    }
    else {
      if (puVar10[2] == 0) {
        *(undefined4 *)puVar10[3] = 0;
        puVar10[2] = 1;
      }
      piVar12 = (int *)puVar10[3];
    }
    FUN_00109c0e(iVar13 + 0xbc,1,*(byte *)(*piVar12 + 0xa0 + iVar19 * 0x18) & 1);
    if (*puVar3 == 0) {
      piVar12 = (int *)FUN_001a7f7c(puVar3,0);
    }
    else {
      if (puVar11[2] == 0) {
        *(undefined4 *)puVar11[3] = 0;
        puVar11[2] = 1;
      }
      piVar12 = (int *)puVar11[3];
    }
    iVar19 = *piVar12;
    if (*puVar2 == 0) {
      piVar12 = (int *)FUN_001a7f7c(puVar2,0);
    }
    else {
      if (puVar10[2] == 0) {
        *(undefined4 *)puVar10[3] = 0;
        puVar10[2] = 1;
      }
      piVar12 = (int *)puVar10[3];
    }
    FUN_00109c0e(iVar13 + 0xbc,2,*(uint *)(*piVar12 + 0xa0 + iVar19 * 0x18) >> 1 & 1);
    FUN_001a7cd6(local_34,iVar13);
    *(undefined4 *)(iVar13 + 0x150) = *(undefined4 *)(param_1[7] + 4);
    uVar9 = *(undefined4 *)(*param_1 + 0xbc);
    puVar14 = (undefined4 *)FUN_001a7bca(uVar9,0x1c);
    *puVar14 = uVar9;
    puVar5 = (uint *)param_1[7];
    uVar20 = puVar5[1];
    if (uVar20 < *puVar5) {
      _memset((void *)(uVar20 * 4 + puVar5[2]),0,4);
      puVar5[1] = uVar20 + 1;
      puVar15 = (undefined4 *)(uVar20 * 4 + puVar5[2]);
    }
    else {
      puVar15 = (undefined4 *)FUN_001a7f7c(puVar5,uVar20);
    }
    *puVar15 = puVar14 + 1;
    local_a0 = *(int *)(iVar16 + 8);
  }
  local_6c = *(int *)(local_a0 + 8);
  iVar16 = *(int *)(local_6c + 8);
  while (iVar16 != 0) {
    while( true ) {
      iVar16 = FUN_0010a17a(local_a8,*param_1);
      *(undefined4 *)(iVar16 + 0x94) = *(undefined4 *)(iVar16 + 0x14c);
      *(undefined4 *)(iVar16 + 0x98) = 0;
      *(undefined4 *)(iVar16 + 0x9c) = DAT_001cc768;
      if (local_a4 == 0) {
        iVar13 = *param_1;
      }
      else {
        iVar13 = *(int *)(*(int *)(*param_1 + 0x54) + 0x58);
        if (local_a4 < iVar13) {
          *(int *)(iVar16 + 0x124) = iVar13;
          iVar13 = *param_1;
          local_a4 = local_a4 - *(int *)(*(int *)(iVar13 + 0x54) + 0x58);
        }
        else {
          iVar13 = *(int *)(*(int *)(*param_1 + 0x54) + 0x5c);
          if (iVar13 < local_a4) {
            *(int *)(iVar16 + 0x124) = iVar13;
            iVar13 = *param_1;
            local_a4 = local_a4 - *(int *)(*(int *)(iVar13 + 0x54) + 0x5c);
          }
          else {
            *(int *)(iVar16 + 0x124) = local_a4;
            local_a4 = 0;
            iVar13 = *param_1;
          }
        }
      }
      FUN_0010ba02(iVar16,1,local_a0,0,iVar13);
      FUN_0010ba02(iVar16,2,local_6c,0,*param_1);
      iVar13 = FUN_0010b0f4(iVar16,1);
      *(undefined4 *)(iVar13 + 0x10) = DAT_001cc764;
      iVar13 = FUN_0010b0f4(iVar16,2);
      *(undefined4 *)(iVar13 + 0x10) = DAT_001cc764;
      FUN_001a7cd6(local_34,iVar16);
      *(undefined4 *)(iVar16 + 0x150) = *(undefined4 *)(param_1[7] + 4);
      uVar9 = *(undefined4 *)(*param_1 + 0xbc);
      puVar14 = (undefined4 *)FUN_001a7bca(uVar9,0x1c);
      *puVar14 = uVar9;
      puVar5 = (uint *)param_1[7];
      uVar20 = puVar5[1];
      if (*puVar5 <= uVar20) break;
      _memset((void *)(uVar20 * 4 + puVar5[2]),0,4);
      puVar5[1] = uVar20 + 1;
      *(undefined4 **)(uVar20 * 4 + puVar5[2]) = puVar14 + 1;
      local_a0 = *(int *)(local_6c + 8);
      local_6c = *(int *)(local_a0 + 8);
      if (*(int *)(local_6c + 8) == 0) goto LAB_0019500c;
    }
    puVar15 = (undefined4 *)FUN_001a7f7c(puVar5,uVar20);
    *puVar15 = puVar14 + 1;
    local_a0 = *(int *)(local_6c + 8);
    local_6c = *(int *)(local_a0 + 8);
    iVar16 = *(int *)(local_6c + 8);
  }
LAB_0019500c:
  if (-1 < (int)uVar4) {
    local_58 = uVar4 * 4;
    do {
      uVar4 = uVar22 - 1;
      if (uVar4 < *puVar2) {
        uVar20 = puVar10[2];
        if (uVar20 <= uVar4) {
          _memset((void *)(puVar10[3] + uVar20 * 4),0,(uVar4 - uVar20) * 4 + 4);
          puVar10[2] = uVar22;
        }
        piVar12 = (int *)(local_58 + puVar10[3]);
      }
      else {
        piVar12 = (int *)FUN_001a7f7c(puVar2,uVar4);
      }
      if (param_3 == *piVar12) break;
      if (uVar4 < *puVar2) {
        uVar20 = puVar10[2];
        if (uVar20 <= uVar4) {
          _memset((void *)(puVar10[3] + uVar20 * 4),0,(uVar4 - uVar20) * 4 + 4);
          puVar10[2] = uVar22;
        }
        puVar14 = (undefined4 *)(local_58 + puVar10[3]);
      }
      else {
        puVar14 = (undefined4 *)FUN_001a7f7c(puVar2,uVar4);
      }
      piVar12 = (int *)*puVar14;
      if (uVar4 < *puVar3) {
        uVar20 = puVar11[2];
        if (uVar20 <= uVar4) {
          _memset((void *)(puVar11[3] + uVar20 * 4),0,(uVar4 - uVar20) * 4 + 4);
          puVar11[2] = uVar22;
        }
        piVar17 = (int *)(local_58 + puVar11[3]);
      }
      else {
        piVar17 = (int *)FUN_001a7f7c(puVar3,uVar4);
      }
      iVar16 = (*piVar17 == 1) + 1;
      FUN_0010a62e(piVar12,param_1[1]);
      uVar22 = piVar12[0x54];
      puVar5 = (uint *)param_1[7];
      if (uVar22 < *puVar5) {
        uVar20 = puVar5[1];
        if (uVar20 <= uVar22) {
          _memset((void *)(puVar5[2] + uVar20 * 4),0,(uVar22 - uVar20) * 4 + 4);
          puVar5[1] = uVar22 + 1;
        }
        piVar17 = (int *)(puVar5[2] + uVar22 * 4);
      }
      else {
        piVar17 = (int *)FUN_001a7f7c(puVar5,uVar22);
      }
      iVar13 = *(int *)(*piVar17 + 0xc);
      iVar19 = *(int *)(*piVar17 + 0x10);
      iVar18 = *param_1;
      uVar9 = FUN_0010b180(piVar12,iVar16);
      FUN_0010ba02(iVar13,iVar19,uVar9,0,iVar18);
      iVar18 = FUN_0010b0f4(piVar12,iVar16);
      uVar9 = *(undefined4 *)(iVar18 + 0x10);
      iVar18 = FUN_0010b0f4(iVar13,iVar19);
      *(undefined4 *)(iVar18 + 0x10) = uVar9;
      if ((*(byte *)(iVar13 + 0xa0 + iVar19 * 0x18) & 1) == 0) {
        bVar21 = *(byte *)(piVar12 + iVar16 * 6 + 0x28) & 1;
      }
      else {
        bVar21 = *(byte *)(piVar12 + iVar16 * 6 + 0x28) & 1 ^ 1;
      }
      iVar13 = iVar13 + 0x8c + iVar19 * 0x18;
      FUN_00109c0e(iVar13,1,bVar21);
      FUN_00109c0e(iVar13,2,(uint)piVar12[iVar16 * 6 + 0x28] >> 1 & 1);
      (**(code **)(*piVar12 + 0xc))(piVar12,0,*param_1);
      local_58 = local_58 + -4;
      uVar22 = uVar4;
    } while (uVar4 != 0);
  }
  if (*puVar2 == 0) {
    piVar12 = (int *)FUN_001a7f7c(puVar2,0);
  }
  else {
    if (puVar10[2] == 0) {
      *(undefined4 *)puVar10[3] = 0;
      puVar10[2] = 1;
    }
    piVar12 = (int *)puVar10[3];
  }
  if (param_3 == *piVar12) {
    iVar13 = *(int *)(local_2c + 8);
    iVar16 = local_2c;
    while (iVar19 = iVar13, iVar19 != 0) {
      FUN_001a7d72(iVar16);
      FUN_000e956e(param_2,param_3,iVar16);
      iVar16 = iVar19;
      iVar13 = *(int *)(iVar19 + 8);
    }
    if (*puVar3 == 0) {
      piVar12 = (int *)FUN_001a7f7c(puVar3,0);
    }
    else {
      if (puVar11[2] == 0) {
        *(undefined4 *)puVar11[3] = 0;
        puVar11[2] = 1;
      }
      piVar12 = (int *)puVar11[3];
    }
    iVar16 = *piVar12;
    FUN_0010ba02(param_3,iVar16,*(undefined4 *)(param_3 + 4),0,*param_1);
    iVar13 = FUN_0010b0f4(param_3,iVar16);
    *(undefined4 *)(iVar13 + 0x10) = DAT_001cc764;
    iVar16 = param_3 + 0x8c + iVar16 * 0x18;
    FUN_00109c0e(iVar16,1,0);
    FUN_00109c0e(iVar16,2,0);
  }
  else {
    iVar13 = FUN_0010a17a(local_a8,*param_1);
    *(undefined4 *)(iVar13 + 0x94) = *(undefined4 *)(iVar13 + 0x14c);
    *(undefined4 *)(iVar13 + 0x98) = 0;
    iVar16 = FUN_0010b0f4(param_3,0);
    *(undefined4 *)(iVar13 + 0x9c) = *(undefined4 *)(iVar16 + 0x10);
    iVar16 = *param_1;
    uVar9 = FUN_0010b180(param_3,1);
    FUN_0010ba02(iVar13,1,uVar9,0,iVar16);
    iVar16 = *param_1;
    uVar9 = FUN_0010b180(param_3,2);
    FUN_0010ba02(iVar13,2,uVar9,0,iVar16);
    iVar16 = FUN_0010b0f4(param_3,1);
    uVar9 = *(undefined4 *)(iVar16 + 0x10);
    iVar16 = FUN_0010b0f4(iVar13,1);
    *(undefined4 *)(iVar16 + 0x10) = uVar9;
    iVar16 = FUN_0010b0f4(param_3,2);
    uVar9 = *(undefined4 *)(iVar16 + 0x10);
    iVar16 = FUN_0010b0f4(iVar13,2);
    *(undefined4 *)(iVar16 + 0x10) = uVar9;
    FUN_00109c0e(iVar13 + 0xa4,1,*(byte *)(param_3 + 0xb8) & 1);
    FUN_00109c0e(iVar13 + 0xbc,1,*(byte *)(param_3 + 0xd0) & 1);
    FUN_00109c0e(iVar13 + 0xa4,2,*(uint *)(param_3 + 0xb8) >> 1 & 1);
    FUN_00109c0e(iVar13 + 0xbc,2,*(uint *)(param_3 + 0xd0) >> 1 & 1);
    FUN_000e956e(param_2,param_3,iVar13);
    FUN_0010ba02(param_3,1,iVar13,0,*param_1);
    iVar16 = FUN_0010b0f4(param_3,1);
    *(undefined4 *)(iVar16 + 0x10) = DAT_001cc760;
    FUN_00109c0e(param_3 + 0xa4,1,0);
    FUN_00109c0e(param_3 + 0xa4,2,0);
    iVar16 = *(int *)(local_2c + 8);
    while (iVar13 = iVar16, iVar13 != 0) {
      FUN_001a7d72(local_2c);
      FUN_000e956e(param_2,param_3,local_2c);
      local_2c = iVar13;
      iVar16 = *(int *)(iVar13 + 8);
    }
    FUN_0010ba02(param_3,2,*(undefined4 *)(param_3 + 4),0,*param_1);
    iVar16 = FUN_0010b0f4(param_3,2);
    *(undefined4 *)(iVar16 + 0x10) = DAT_001cc764;
    FUN_00109c0e(param_3 + 0xbc,1,0);
    FUN_00109c0e(param_3 + 0xbc,2,0);
    FUN_000f5d78(param_3);
  }
  if (puVar3 != (uint *)0x0) {
    FUN_001a7aba(puVar11[4],puVar11[3]);
    FUN_001a7aba(*puVar11,puVar11);
  }
  if (puVar2 != (uint *)0x0) {
    FUN_001a7aba(puVar10[4],puVar10[3]);
    FUN_001a7aba(*puVar10,puVar10);
  }
  if (puVar1 != (uint *)0x0) {
    FUN_001a7aba(puVar8[4],puVar8[3]);
    FUN_001a7aba(*puVar8,puVar8);
  }
  return 1;
}

/* FUN_001960e2 @ 0x1960e2 (180 bytes) */
int FUN_001960e2(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint *puVar5;
  uint local_14;
  
  puVar5 = *(uint **)(param_1 + 0x1c);
  uVar1 = puVar5[1];
  if (0 < (int)uVar1) {
    local_14 = 0;
    while( true ) {
      if (local_14 < *puVar5) {
        uVar2 = puVar5[1];
        if (uVar2 <= local_14) {
          _memset((void *)(puVar5[2] + uVar2 * 4),0,(local_14 - uVar2) * 4 + 4);
          puVar5[1] = local_14 + 1;
        }
        piVar4 = (int *)(puVar5[2] + local_14 * 4);
      }
      else {
        piVar4 = (int *)FUN_001a7f7c(puVar5,local_14);
      }
      local_14 = local_14 + 1;
      iVar3 = *piVar4;
      if (iVar3 != 0) {
        FUN_001a7aba(*(undefined4 *)(iVar3 + -4),iVar3 + -4);
      }
      if (uVar1 == local_14) break;
      puVar5 = *(uint **)(param_1 + 0x1c);
    }
    puVar5 = *(uint **)(param_1 + 0x1c);
  }
  puVar5[1] = 0;
  return;
}

/* FUN_00196196 @ 0x196196 (1341 bytes) */
int FUN_00196196(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int local_38;
  int local_24;
  int local_20 [4];
  
  ((int (*)())FUN_00193628)(param_1,param_2);
LAB_001961c2:
  ((int (*)())FUN_00193708)(param_1,param_2,local_20,&local_24);
  if ((local_24 <= local_20[0]) ||
     (iVar1 = *(int *)(param_1 + 8),
     *(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 0x10) <= *(int *)(iVar1 + 0x14))) {
LAB_001963ac:
    ((int (*)())FUN_001960e2)(param_1);
    return;
  }
  iVar1 = *(int *)(param_2 + 0x98);
  iVar7 = *(int *)(iVar1 + 8);
joined_r0x00196214:
  do {
    if (iVar7 == 0) goto LAB_001963ac;
    if ((*(byte *)(iVar1 + 0x14) & 1) != 0) {
      iVar7 = *(int *)(iVar1 + 0x88);
      if ((*(int *)(iVar7 + 8) == 0x13) || (*(int *)(iVar7 + 8) == 0x14)) {
        local_38 = 0x13;
      }
      else {
        if (*(int *)(iVar7 + 8) != 0x12) goto LAB_00196230;
        local_38 = 0x12;
      }
      uVar2 = *(uint *)(iVar1 + 0x150);
      puVar3 = *(uint **)(param_1 + 0x1c);
      if (uVar2 < *puVar3) {
        uVar4 = puVar3[1];
        if (uVar4 <= uVar2) {
          _memset((void *)(puVar3[2] + uVar4 * 4),0,(uVar2 - uVar4) * 4 + 4);
          puVar3[1] = uVar2 + 1;
          iVar7 = *(int *)(iVar1 + 0x88);
        }
        iVar5 = *(int *)(puVar3[2] + uVar2 * 4);
        iVar7 = *(int *)(iVar7 + 8);
      }
      else {
        piVar10 = (int *)FUN_001a7f7c(puVar3,uVar2);
        iVar5 = *piVar10;
        iVar7 = *(int *)(*(int *)(iVar1 + 0x88) + 8);
      }
      if ((((((local_38 == iVar7) && (*(char *)(iVar1 + 0x120) == '\0')) &&
            ((*(byte *)(iVar1 + 0x15) & 2) == 0)) &&
           ((local_38 != 0x12 || (*(int *)(iVar1 + 0x124) == 0)))) &&
          (((iVar7 = FUN_0010b0f4(iVar1,0), *(int *)(iVar7 + 0x10) != DAT_001cc774 &&
            ((iVar7 = FUN_0010b0f4(iVar1,0), *(int *)(iVar7 + 0x10) != DAT_001cc770 &&
             (iVar7 = FUN_0010b0f4(iVar1,0), *(int *)(iVar7 + 0x10) != DAT_001cc76c)))) &&
           (iVar7 = FUN_0010b0f4(iVar1,0), *(int *)(iVar7 + 0x10) != DAT_001cc768)))) &&
         ((((cVar6 = FUN_0010a62e(iVar1,*(undefined4 *)(param_1 + 4)), cVar6 != '\0' &&
            (iVar7 = *(int *)(iVar5 + 0xc), iVar7 != 0)) &&
           (local_38 == *(int *)(*(int *)(iVar7 + 0x88) + 8))) &&
          ((cVar6 = FUN_000f5a1e(iVar7,*(undefined4 *)(iVar5 + 0x10)), cVar6 != '\0' &&
           ((local_38 != 0x12 ||
            ((*(byte *)(*(int *)(iVar5 + 0xc) + 0xa0 + *(int *)(iVar5 + 0x10) * 0x18) & 2) == 0)))))
          ))) {
        *(undefined1 *)(iVar5 + 0x14) = 0;
      }
      iVar7 = FUN_0010b180(iVar1,1);
      iVar8 = FUN_0010b180(iVar1,2);
      iVar9 = FUN_0010b0f4(iVar1,1);
      cVar6 = FUN_000f5672(*(undefined4 *)(iVar9 + 0x10));
      if (cVar6 == '\0') {
LAB_0019630c:
        iVar9 = FUN_0010b0f4(iVar1,1);
        cVar6 = FUN_000f5672(*(undefined4 *)(iVar9 + 0x10));
        if (cVar6 == '\0') {
          iVar9 = FUN_0010b0f4(iVar1,2);
          cVar6 = FUN_000f5672(*(undefined4 *)(iVar9 + 0x10));
          if (cVar6 != '\0') goto LAB_001963e5;
        }
        if (param_2 == *(int *)(iVar7 + 0x158)) goto LAB_001963fb;
LAB_00196341:
        iVar7 = *(int *)(iVar8 + 0x158);
      }
      else {
        iVar9 = FUN_0010b0f4(iVar1,2);
        cVar6 = FUN_000f5672(*(undefined4 *)(iVar9 + 0x10));
        if (cVar6 != '\0') goto LAB_0019630c;
LAB_001963e5:
        *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) + 1;
        if (param_2 != *(int *)(iVar7 + 0x158)) goto LAB_00196341;
LAB_001963fb:
        uVar2 = *(uint *)(iVar7 + 0x150);
        puVar3 = *(uint **)(param_1 + 0x1c);
        if (uVar2 < *puVar3) {
          uVar4 = puVar3[1];
          if (uVar4 <= uVar2) {
            _memset((void *)(puVar3[2] + uVar4 * 4),0,(uVar2 - uVar4) * 4 + 4);
            puVar3[1] = uVar2 + 1;
          }
          piVar10 = (int *)(puVar3[2] + uVar2 * 4);
        }
        else {
          piVar10 = (int *)FUN_001a7f7c(puVar3,uVar2);
        }
        iVar7 = *piVar10;
        if ((iVar7 == 0) || (*(char *)(iVar7 + 0x14) != '\0')) goto LAB_00196341;
        *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) + *(int *)(iVar7 + 8);
        iVar7 = *(int *)(iVar8 + 0x158);
      }
      if (param_2 == iVar7) {
        uVar2 = *(uint *)(iVar8 + 0x150);
        puVar3 = *(uint **)(param_1 + 0x1c);
        if (uVar2 < *puVar3) {
          uVar4 = puVar3[1];
          if (uVar4 <= uVar2) {
            _memset((void *)(puVar3[2] + uVar4 * 4),0,(uVar2 - uVar4) * 4 + 4);
            puVar3[1] = uVar2 + 1;
          }
          piVar10 = (int *)(puVar3[2] + uVar2 * 4);
        }
        else {
          piVar10 = (int *)FUN_001a7f7c(puVar3,uVar2);
        }
        iVar7 = *piVar10;
        if ((iVar7 != 0) && (*(char *)(iVar7 + 0x14) == '\0')) {
          *(int *)(iVar5 + 8) = *(int *)(iVar5 + 8) + *(int *)(iVar7 + 8);
        }
      }
      if ((*(char *)(iVar5 + 0x14) != '\0') && (1 < *(int *)(iVar5 + 8))) {
        cVar6 = ((int (*)())FUN_00193a86)(param_1,param_2,iVar1);
        if (cVar6 == '\0') {
          iVar1 = *(int *)(iVar1 + 8);
          iVar7 = *(int *)(iVar1 + 8);
          goto joined_r0x00196214;
        }
        goto LAB_001961c2;
      }
    }
LAB_00196230:
    iVar1 = *(int *)(iVar1 + 8);
    iVar7 = *(int *)(iVar1 + 8);
  } while( true );
}

/* FUN_001966d4 @ 0x1966d4 (266 bytes) */
int FUN_001966d4(param_1, param_2)
  int *param_1;
  int param_2;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  param_1[1] = param_2;
  iVar1 = *(int *)(param_2 + 8);
  *param_1 = iVar1;
  iVar1 = FUN_001133e6(iVar1);
  param_1[2] = iVar1;
  uVar3 = *(undefined4 *)(*param_1 + 0xbc);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar3,0x14);
  *puVar2 = uVar3;
  puVar2[4] = uVar3;
  puVar2[2] = 0;
  puVar2[1] = 2;
  uVar3 = FUN_001a7bca(uVar3,8);
  puVar2[3] = uVar3;
  param_1[7] = (int)(puVar2 + 1);
  iVar4 = *(int *)(param_1[1] + 0x378);
  iVar1 = *(int *)(iVar4 + 8);
  while (iVar1 != 0) {
    while (iVar1 = FUN_001a7d8a(iVar4 + 0x90), 2 < iVar1) {
      ((int (*)())FUN_00196196)(param_1,iVar4);
      iVar4 = *(int *)(iVar4 + 8);
      if (*(int *)(iVar4 + 8) == 0) goto LAB_00196793;
    }
    iVar4 = *(int *)(iVar4 + 8);
    iVar1 = *(int *)(iVar4 + 8);
  }
LAB_00196793:
  iVar1 = param_1[7];
  if (iVar1 != 0) {
    FUN_001a7aba(*(undefined4 *)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 8));
    FUN_001a7aba(*(undefined4 *)(iVar1 + -4),iVar1 + -4);
  }
  FUN_000f0346(param_2,"height_reduction");
  return;
}

/* FUN_001967fc @ 0x1967fc (2706 bytes) */
int FUN_001967fc(param_1, param_2, param_3, param_4)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
  int *param_4;
{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  dword dVar4;
  char cVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint local_70;
  int local_54;
  int local_44;
  undefined4 local_28;
  int local_20;
  
  uVar7 = *(undefined4 *)(*param_1 + 0xbc);
  puVar6 = (undefined4 *)FUN_001a7bca(uVar7,0x14);
  *puVar6 = uVar7;
  puVar1 = puVar6 + 1;
  puVar6[4] = uVar7;
  puVar6[2] = 0;
  puVar6[1] = 2;
  uVar7 = FUN_001a7bca(uVar7,8);
  puVar6[3] = uVar7;
  uVar7 = *(undefined4 *)(*param_1 + 0xbc);
  puVar8 = (undefined4 *)FUN_001a7bca(uVar7,0x14);
  *puVar8 = uVar7;
  puVar2 = puVar8 + 1;
  puVar8[4] = uVar7;
  puVar8[2] = 0;
  puVar8[1] = 2;
  uVar7 = FUN_001a7bca(uVar7,8);
  puVar8[3] = uVar7;
  uVar7 = *(undefined4 *)(*param_1 + 0xbc);
  puVar9 = (undefined4 *)FUN_001a7bca(uVar7,0x14);
  *puVar9 = uVar7;
  puVar3 = puVar9 + 1;
  puVar9[4] = uVar7;
  puVar9[2] = 0;
  puVar9[1] = 2;
  uVar7 = FUN_001a7bca(uVar7,8);
  puVar9[3] = uVar7;
  uVar14 = puVar6[2];
  if (uVar14 < *puVar1) {
    _memset((void *)(uVar14 * 4 + puVar6[3]),0,4);
    puVar6[2] = uVar14 + 1;
    puVar10 = (undefined4 *)(uVar14 * 4 + puVar6[3]);
  }
  else {
    puVar10 = (undefined4 *)FUN_001a7f7c(puVar1,uVar14);
  }
  *puVar10 = param_4;
  uVar14 = puVar8[2];
  if (uVar14 < *puVar2) {
    _memset((void *)(uVar14 * 4 + puVar8[3]),0,4);
    puVar8[2] = uVar14 + 1;
    puVar10 = (undefined4 *)(uVar14 * 4 + puVar8[3]);
  }
  else {
    puVar10 = (undefined4 *)FUN_001a7f7c(puVar2,uVar14);
  }
LAB_0019697f:
  *puVar10 = 1;
  if (puVar6[2] != 0) {
    do {
      if (puVar6[2] - 1 < (uint)puVar6[2]) {
        piVar11 = (int *)(puVar6[3] + (puVar6[2] - 1) * 4);
      }
      else {
        piVar11 = (int *)0x0;
      }
      piVar11 = (int *)*piVar11;
      if (puVar8[2] - 1 < (uint)puVar8[2]) {
        piVar12 = (int *)(puVar8[3] + (puVar8[2] - 1) * 4);
      }
      else {
        piVar12 = (int *)0x0;
      }
      iVar13 = *piVar12;
      cVar5 = ((int (*)())FUN_0019351e)();
      if ((cVar5 == '\0') && (param_4 != piVar11)) {
        piVar11[0x54] = 0;
      }
      else {
        iVar15 = (**(code **)(*piVar11 + 0x14))(piVar11);
        if (iVar13 <= iVar15) goto code_r0x00196dd3;
        uVar14 = (**(code **)(*piVar11 + 0x14))(piVar11);
        if (0 < (int)uVar14) {
          local_54 = 1;
          do {
            uVar7 = FUN_0010b180(piVar11,local_54);
            uVar16 = puVar9[2];
            if (uVar16 < *puVar3) {
              _memset((void *)(uVar16 * 4 + puVar9[3]),0,4);
              puVar9[2] = uVar16 + 1;
              puVar10 = (undefined4 *)(uVar16 * 4 + puVar9[3]);
            }
            else {
              puVar10 = (undefined4 *)FUN_001a7f7c(puVar3,uVar16);
            }
            *puVar10 = uVar7;
            local_54 = local_54 + 1;
          } while (local_54 <= (int)uVar14);
        }
        FUN_001a7e60(puVar3,FUN_00193574);
        if (0 < (int)uVar14) {
          uVar16 = 0;
          local_44 = 0;
          if (*puVar3 == 0) goto LAB_0019705d;
LAB_00197013:
          uVar17 = puVar9[2];
          if (uVar17 <= uVar16) {
            _memset((void *)(puVar9[3] + uVar17 * 4),0,(uVar16 - uVar17) * 4 + 4);
            puVar9[2] = uVar16 + 1;
          }
          uVar17 = uVar16 + 1;
          piVar12 = *(int **)(puVar9[3] + uVar16 * 4);
          if (piVar12[0x20] != 0) goto LAB_0019707b;
          do {
            iVar13 = 0;
            uVar16 = uVar17;
            while( true ) {
              local_44 = local_44 + iVar13;
              if (local_44 <= piVar12[0x54]) {
                local_44 = piVar12[0x54];
              }
              if (uVar14 == uVar16) goto LAB_00196fe8;
              if (uVar16 < *puVar3) goto LAB_00197013;
LAB_0019705d:
              piVar12 = (int *)FUN_001a7f7c(puVar3,uVar16);
              uVar17 = uVar16 + 1;
              piVar12 = (int *)*piVar12;
              if (piVar12[0x20] == 0) break;
LAB_0019707b:
              cVar5 = FUN_0012dfd8(piVar12[0x26]);
              if (((cVar5 == '\0') || ((*(byte *)(piVar12 + 5) & 2) != 0)) ||
                 (cVar5 = (**(code **)(*piVar12 + 0x50))(piVar12), cVar5 != '\0')) break;
              iVar13 = FUN_000f60f4(piVar12);
              uVar16 = uVar17;
            }
          } while( true );
        }
        local_44 = 0;
LAB_00196fe8:
        puVar9[2] = 0;
        piVar11[0x54] = local_44;
      }
      FUN_001a7f3c(puVar1,puVar6[2] + -1);
      FUN_001a7f3c(puVar2,puVar8[2] + -1);
      if (puVar6[2] == 0) break;
    } while( true );
  }
  if (*puVar1 == 0) {
    puVar10 = (undefined4 *)FUN_001a7f7c(puVar1,0);
  }
  else {
    _memset((void *)puVar6[3],0,4);
    puVar6[2] = 1;
    puVar10 = (undefined4 *)puVar6[3];
  }
  *puVar10 = param_4;
  uVar14 = puVar8[2];
  if (uVar14 < *puVar2) {
    _memset((void *)(uVar14 * 4 + puVar8[3]),0,4);
    puVar8[2] = uVar14 + 1;
    puVar10 = (undefined4 *)(uVar14 * 4 + puVar8[3]);
  }
  else {
    puVar10 = (undefined4 *)FUN_001a7f7c(puVar2,uVar14);
  }
  *puVar10 = 1;
  do {
    while( true ) {
      iVar13 = puVar6[2];
      while( true ) {
        if (iVar13 == 0) {
          if (puVar3 != (uint *)0x0) {
            FUN_001a7aba(puVar9[4],puVar9[3]);
            FUN_001a7aba(*puVar9,puVar9);
          }
          if (puVar2 != (uint *)0x0) {
            FUN_001a7aba(puVar8[4],puVar8[3]);
            FUN_001a7aba(*puVar8,puVar8);
          }
          if (puVar1 != (uint *)0x0) {
            FUN_001a7aba(puVar6[4],puVar6[3]);
            FUN_001a7aba();
            return;
          }
          return;
        }
        if (puVar6[2] - 1 < (uint)puVar6[2]) {
          piVar11 = (int *)(puVar6[3] + (puVar6[2] - 1) * 4);
        }
        else {
          piVar11 = (int *)0x0;
        }
        piVar11 = (int *)*piVar11;
        cVar5 = ((int (*)())FUN_0019351e)();
        dVar4 = MACH_HEADER.magic;
        if ((cVar5 != '\0') || (param_4 == piVar11)) break;
        FUN_001a7f3c(puVar1,puVar6[2] + -1);
        FUN_001a7f3c(puVar2,puVar8[2] + -1);
        iVar13 = puVar6[2];
      }
      if (puVar8[2] - 1 < (uint)puVar8[2]) break;
      iVar13 = (**(code **)(*piVar11 + 0x14))(piVar11);
      if ((int)dVar4 <= iVar13) goto LAB_00196be4;
LAB_00196f20:
      FUN_001a7f3c(puVar1,puVar6[2] + -1);
      FUN_001a7f3c(puVar2,puVar8[2] + -1);
      if (param_4 != piVar11) {
        FUN_001a7d72(piVar11);
        FUN_000e956e(param_3,param_4,piVar11);
      }
    }
    iVar13 = *(int *)(puVar8[3] + (puVar8[2] - 1) * 4);
    iVar15 = (**(code **)(*piVar11 + 0x14))(piVar11);
    if (iVar15 < iVar13) goto LAB_00196f20;
LAB_00196be4:
    uVar14 = (**(code **)(*piVar11 + 0x14))(piVar11);
    if (0 < (int)uVar14) {
      local_20 = 1;
      do {
        uVar7 = FUN_0010b180(piVar11,local_20);
        uVar16 = puVar9[2];
        if (uVar16 < *puVar3) {
          _memset((void *)(uVar16 * 4 + puVar9[3]),0,4);
          puVar9[2] = uVar16 + 1;
          puVar10 = (undefined4 *)(uVar16 * 4 + puVar9[3]);
        }
        else {
          puVar10 = (undefined4 *)FUN_001a7f7c(puVar3,uVar16);
        }
        *puVar10 = uVar7;
        local_20 = local_20 + 1;
      } while (local_20 <= (int)uVar14);
    }
    FUN_001a7e60(puVar3,FUN_00193574);
    FUN_001a7f3c(puVar2,puVar8[2] + -1);
    uVar16 = puVar8[2];
    if (uVar16 < *puVar2) {
      _memset((void *)(uVar16 * 4 + puVar8[3]),0,4);
      puVar8[2] = uVar16 + 1;
      piVar11 = (int *)(uVar16 * 4 + puVar8[3]);
    }
    else {
      piVar11 = (int *)FUN_001a7f7c(puVar2,uVar16);
    }
    *piVar11 = uVar14 + 1;
    if (0 < (int)uVar14) {
      local_70 = 0;
      do {
        while (*puVar3 <= local_70) {
          puVar10 = (undefined4 *)FUN_001a7f7c(puVar3,local_70);
          local_28 = *puVar10;
          uVar16 = puVar6[2];
          if (*puVar1 <= uVar16) goto LAB_00196d71;
LAB_00196cb6:
          _memset((void *)(uVar16 * 4 + puVar6[3]),0,4);
          puVar6[2] = uVar16 + 1;
          *(undefined4 *)(uVar16 * 4 + puVar6[3]) = local_28;
          uVar16 = puVar8[2];
          if (uVar16 < *puVar2) goto LAB_00196cfe;
LAB_00196d93:
          local_70 = local_70 + 1;
          puVar10 = (undefined4 *)FUN_001a7f7c(puVar2,uVar16);
          *puVar10 = 1;
          if (uVar14 == local_70) goto LAB_00196db0;
        }
        uVar16 = puVar9[2];
        if (uVar16 <= local_70) {
          _memset((void *)(puVar9[3] + uVar16 * 4),0,(local_70 - uVar16) * 4 + 4);
          puVar9[2] = local_70 + 1;
        }
        local_28 = *(undefined4 *)(puVar9[3] + local_70 * 4);
        uVar16 = puVar6[2];
        if (uVar16 < *puVar1) goto LAB_00196cb6;
LAB_00196d71:
        puVar10 = (undefined4 *)FUN_001a7f7c(puVar1,uVar16);
        *puVar10 = local_28;
        uVar16 = puVar8[2];
        if (*puVar2 <= uVar16) goto LAB_00196d93;
LAB_00196cfe:
        local_70 = local_70 + 1;
        _memset((void *)(uVar16 * 4 + puVar8[3]),0,4);
        puVar8[2] = uVar16 + 1;
        *(undefined4 *)(uVar16 * 4 + puVar8[3]) = 1;
      } while (uVar14 != local_70);
    }
LAB_00196db0:
    puVar9[2] = 0;
  } while( true );
code_r0x00196dd3:
  uVar7 = FUN_0010b180(piVar11,iVar13);
  uVar14 = puVar6[2];
  if (uVar14 < *puVar1) {
    _memset((void *)(uVar14 * 4 + puVar6[3]),0,4);
    puVar6[2] = uVar14 + 1;
    puVar10 = (undefined4 *)(uVar14 * 4 + puVar6[3]);
  }
  else {
    puVar10 = (undefined4 *)FUN_001a7f7c(puVar1,uVar14);
  }
  *puVar10 = uVar7;
  FUN_001a7f3c(puVar2,puVar8[2] + -1);
  uVar14 = puVar8[2];
  if (uVar14 < *puVar2) {
    _memset((void *)(uVar14 * 4 + puVar8[3]),0,4);
    puVar8[2] = uVar14 + 1;
    piVar11 = (int *)(uVar14 * 4 + puVar8[3]);
  }
  else {
    piVar11 = (int *)FUN_001a7f7c(puVar2,uVar14);
  }
  *piVar11 = iVar13 + 1;
  uVar14 = puVar8[2];
  if (uVar14 < *puVar2) {
    _memset((void *)(uVar14 * 4 + puVar8[3]),0,4);
    puVar8[2] = uVar14 + 1;
    puVar10 = (undefined4 *)(uVar14 * 4 + puVar8[3]);
  }
  else {
    puVar10 = (undefined4 *)FUN_001a7f7c(puVar2,uVar14);
  }
  goto LAB_0019697f;
}

/* FUN_001972e2 @ 0x1972e2 (204 bytes) */
int FUN_001972e2(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  
  iVar1 = *(int *)(param_2 + 0x378);
  iVar5 = *(int *)(iVar1 + 8);
  while (iVar5 != 0) {
    piVar2 = *(int **)(iVar1 + 0xa0);
    piVar3 = (int *)(*(int **)(iVar1 + 0xa0))[1];
    while (piVar3 != (int *)0x0) {
      cVar4 = (**(code **)(*piVar2 + 0x34))(piVar2);
      if ((((cVar4 == '\0') && (cVar4 = (**(code **)(*piVar2 + 0x38))(piVar2), cVar4 == '\0')) &&
          (iVar5 = (**(code **)(*piVar2 + 0x14))(piVar2), 0 < iVar5)) &&
         (cVar4 = ((int (*)())FUN_0019351e)(), cVar4 == '\0')) {
        ((int (*)())FUN_001967fc)(param_1,param_2,iVar1,piVar2);
        piVar2 = piVar3;
        piVar3 = (int *)piVar3[1];
      }
      else {
        piVar2 = piVar3;
        piVar3 = (int *)piVar3[1];
      }
    }
    iVar1 = *(int *)(iVar1 + 8);
    iVar5 = *(int *)(iVar1 + 8);
  }
  FUN_000f0346(param_2,"minreg_order");
  return;
}

/* FUN_001973ae @ 0x1973ae (31 bytes) */
int FUN_001973ae(param_1, param_2)
  uint param_1;
  uint param_2;
{
  if (param_1 == param_2) {
    return 0;
  }
  return (-(uint)(param_2 < param_1) & 2) - 1;
}

/* FUN_001973ce @ 0x1973ce (182 bytes) */
int FUN_001973ce(param_1)
  int param_1;
{
  uint uVar1;
  char cVar2;
  undefined4 *puVar3;
  uint *puVar4;
  uint uVar5;
  int local_14;
  
  puVar4 = *(uint **)(param_1 + 0x10);
  uVar5 = puVar4[1] - 1;
  if (-1 < (int)uVar5) {
    local_14 = uVar5 * 4;
    while( true ) {
      if (uVar5 < *puVar4) {
        uVar1 = puVar4[1];
        if (uVar1 <= uVar5) {
          _memset((void *)(puVar4[2] + uVar1 * 4),0,(uVar5 - uVar1) * 4 + 4);
          puVar4[1] = uVar5 + 1;
        }
        cVar2 = (**(code **)(**(int **)(local_14 + puVar4[2]) + 0x24))
                          (*(int **)(local_14 + puVar4[2]));
      }
      else {
        puVar3 = (undefined4 *)FUN_001a7f7c(puVar4,uVar5);
        cVar2 = (**(code **)(*(int *)*puVar3 + 0x24))((int *)*puVar3);
      }
      if (cVar2 == '\0') {
        return 0;
      }
      uVar5 = uVar5 - 1;
      local_14 = local_14 + -4;
      if (uVar5 == 0xffffffff) break;
      puVar4 = *(uint **)(param_1 + 0x10);
    }
  }
  return 1;
}

/* FUN_00197484 @ 0x197484 (106 bytes) */
int FUN_00197484(param_1, param_2, param_3)
  int *param_1;
  undefined4 param_2;
  int param_3;
{
  int *piVar1;
  int iVar2;
  char cVar3;
  
  cVar3 = (**(code **)(*param_1 + 0x24))(param_1);
  if (cVar3 != '\0') {
    piVar1 = *(int **)(*(int *)(param_3 + 8) + 0x54);
    cVar3 = (**(code **)(*piVar1 + 0xfc))(piVar1,param_1[0x49] + -1,param_1);
    if ((cVar3 != '\0') &&
       (((iVar2 = *(int *)(param_1[0x22] + 8), iVar2 == 0x13 || (iVar2 == 0x1c)) || (iVar2 == 0x1d))
       )) {
      return 1;
    }
  }
  return 0;
}

/* FUN_001974ee @ 0x1974ee (327 bytes) */
int FUN_001974ee(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint uVar1;
  char cVar2;
  undefined4 *puVar3;
  uint *puVar4;
  uint uVar5;
  uint local_10;
  
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) == 0x13) {
    puVar4 = *(uint **)(param_1 + 0x10);
    if (0 < (int)puVar4[1]) {
      uVar5 = 0;
      do {
        if (uVar5 < *puVar4) {
          uVar1 = puVar4[1];
          if (uVar1 <= uVar5) {
            _memset((void *)(puVar4[2] + uVar1 * 4),0,(uVar5 - uVar1) * 4 + 4);
            puVar4[1] = uVar5 + 1;
          }
          puVar3 = (undefined4 *)(puVar4[2] + uVar5 * 4);
        }
        else {
          puVar3 = (undefined4 *)FUN_001a7f7c(puVar4,uVar5);
        }
        cVar2 = FUN_0015013c(*puVar3,param_2,0);
        if (cVar2 == '\0') {
          return;
        }
        uVar5 = uVar5 + 1;
        puVar4 = *(uint **)(param_1 + 0x10);
      } while ((int)uVar5 < (int)puVar4[1]);
    }
    if (0 < (int)puVar4[1]) {
      local_10 = 0;
      do {
        if (local_10 < *puVar4) {
          uVar5 = puVar4[1];
          if (uVar5 <= local_10) {
            _memset((void *)(puVar4[2] + uVar5 * 4),0,(local_10 - uVar5) * 4 + 4);
            puVar4[1] = local_10 + 1;
          }
          puVar3 = (undefined4 *)(puVar4[2] + local_10 * 4);
        }
        else {
          puVar3 = (undefined4 *)FUN_001a7f7c(puVar4,local_10);
        }
        local_10 = local_10 + 1;
        FUN_00157ac6(*puVar3,param_2,1,0);
        puVar4 = *(uint **)(param_1 + 0x10);
      } while ((int)local_10 < (int)puVar4[1]);
    }
  }
  return;
}

/* FUN_00197636 @ 0x197636 (417 bytes) */
int FUN_00197636(param_1, param_2)
  int *param_1;
  int param_2;
{
  byte bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint local_28;
  float local_24;
  int local_20;
  
  cVar2 = (**(code **)(*param_1 + 0x68))(param_1);
  if (cVar2 != '\0') {
    piVar3 = (int *)FUN_0010b180(param_1,1);
    cVar2 = (**(code **)(*piVar3 + 0x40))(piVar3);
    if (cVar2 != '\0') {
      local_28 = 0xffffffff;
      local_24 = 0.0;
      local_20 = 0;
      do {
        iVar4 = FUN_0010b0f4(param_1,0);
        if (*(char *)(local_20 + 0x10 + iVar4) != '\x01') {
          iVar4 = FUN_0010b0f4(param_1,1);
          bVar1 = *(byte *)(local_20 + 0x10 + iVar4);
          uVar5 = (uint)bVar1;
          if (((int)(char)piVar3[0x57] >> (bVar1 & 0x1f) & 1U) == 0) {
            return;
          }
          cVar2 = ((undefined4 (*)())FUN_0010fd8c)(piVar3[uVar5 * 6 + 8]);
          if (cVar2 == '\0') {
            return;
          }
          if (local_28 == 0xffffffff) {
            local_24 = (float)piVar3[uVar5 * 6 + 8];
            local_28 = uVar5;
          }
          else {
            if (local_24 != (float)piVar3[uVar5 * 6 + 8]) {
              return;
            }
            if (NAN(local_24) || NAN((float)piVar3[uVar5 * 6 + 8])) {
              return;
            }
          }
        }
        local_20 = local_20 + 1;
      } while (local_20 != 4);
      iVar4 = ((int (*)())FUN_0010fdbc)(piVar3[local_28 * 6 + 8]);
      cVar2 = (**(code **)(**(int **)(param_2 + 0x54) + 0xfc))(*(int **)(param_2 + 0x54),iVar4,0);
      if (cVar2 != '\0') {
        FUN_000fa0d2(param_1,*(undefined4 *)(param_2 + 0x3f4),1,0x3f800000,0x3f800000,0x3f800000,
                     0x3f800000);
        param_1[0x49] = iVar4;
        iVar4 = FUN_0010b0f4(param_1,1);
        *(undefined4 *)(iVar4 + 0x10) = DAT_001cc778;
      }
    }
  }
  return;
}

/* FUN_001977d8 @ 0x1977d8 (2012 bytes) */
int FUN_001977d8(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  int param_2;
  int *param_3;
  int *param_4;
  int *param_5;
  int param_6;
  int param_7;
  int param_8;
  undefined4 *param_9;
  int *param_10;
{
  undefined4 uVar1;
  code *pcVar2;
  bool bVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_40;
  int local_3c;
  int *local_38;
  int local_30;
  char cStack_25;
  int local_24;
  undefined4 local_20 [4];
  
  iVar5 = FUN_0010b0f4(param_5,1);
  uVar7 = *(undefined4 *)(iVar5 + 0x10);
  iVar5 = FUN_0010b0f4(param_3,param_1);
  uVar1 = *(undefined4 *)(iVar5 + 0x10);
  local_20[0] = FUN_000f5610(uVar7,uVar1);
  piVar6 = *(int **)(*(int *)(param_6 + 8) + 0x54);
  cVar4 = (**(code **)(*piVar6 + 0x108))(piVar6,local_20);
  if (cVar4 == '\0') {
    *(int *)(param_6 + 0x20c) = *(int *)(param_6 + 0x20c) + 1;
    return 0;
  }
  if ((param_2 == 0) || ((*(byte *)(param_3 + param_1 * 6 + 0x28) & 2) != 0)) {
LAB_0019786f:
    if (param_7 != '\0') {
LAB_001979ee:
      uVar7 = local_20[0];
      iVar5 = FUN_0010b0f4(param_3,param_1);
      *(undefined4 *)(iVar5 + 0x10) = uVar7;
      FUN_0010ba02(param_3,param_1,param_4,0,*(undefined4 *)(param_6 + 8));
      iVar5 = FUN_000f5b3c(local_20[0]);
      param_4[0x27] = iVar5;
      goto joined_r0x00197a43;
    }
  }
  else {
    if ((*(int *)(param_4[0x22] + 8) == 0x9a) && (param_4[0x2c] == param_4[0x32])) {
      FUN_0010fe82(param_4,1,2,*(undefined4 *)(param_6 + 8));
      param_2 = 0;
      goto LAB_0019786f;
    }
    if (param_7 != '\0') {
      cVar4 = (**(code **)(*param_3 + 0x60))(param_3);
      if (cVar4 != '\0') {
        return 0;
      }
      FUN_00109c0e(param_3 + param_1 * 6 + 0x23,1,*(byte *)(param_3 + param_1 * 6 + 0x28) & 1 ^ 1);
      goto LAB_001979ee;
    }
  }
  iVar5 = FUN_000f5b3c(local_20[0]);
  param_4[0x27] = iVar5;
joined_r0x00197a43:
  if ((param_8 != '\0') &&
     (cVar4 = FUN_001a0c4c(param_3,*(undefined4 *)(param_6 + 8)), cVar4 == '\0')) {
    local_40 = 0;
    for (iVar5 = 1; iVar10 = (**(code **)(*param_3 + 0x14))(param_3), iVar5 <= iVar10;
        iVar5 = iVar5 + 1) {
      cVar4 = FUN_000f6192(param_3,iVar5);
      iVar10 = local_40;
      if ((cVar4 != '\0') && (iVar10 = local_40 + 1, iVar5 == param_1)) {
        iVar10 = local_40 + 2;
      }
      local_40 = iVar10;
      FUN_000f61d2(param_3,iVar5);
    }
    if (3 < local_40) {
      for (local_3c = 1; iVar5 = (**(code **)(*param_3 + 0x14))(param_3), local_3c <= iVar5;
          local_3c = local_3c + 1) {
        if (param_1 == local_3c) {
          cVar4 = (**(code **)(*param_5 + 100))(param_5);
          if (cVar4 != '\0') {
            local_38 = (int *)FUN_0010b180(param_5,1);
            goto LAB_00197c83;
          }
        }
        else {
          local_38 = (int *)FUN_0010b180(param_3,local_3c);
LAB_00197c83:
          iVar5 = FUN_0010b0f4(param_3,local_3c);
          local_24 = *(int *)(iVar5 + 0x10);
          cVar4 = FUN_000f5672(local_24);
          if (cVar4 != '\0') {
            cVar4 = FUN_001195a6(*(undefined4 *)(param_6 + 8),local_38);
            if ((cVar4 == '\0') || (cVar4 = FUN_0010a62e(local_38,param_6), cVar4 == '\0')) {
              bVar3 = false;
            }
            else {
              iVar5 = FUN_000f56ae(local_24);
              local_38[0x27] = DAT_001cc794;
              for (local_30 = 1; iVar10 = (**(code **)(*local_38 + 0x14))(local_38),
                  local_30 <= iVar10; local_30 = local_30 + 1) {
                pcVar2 = *(code **)(*local_38 + 0x88);
                iVar10 = FUN_0010b0f4(local_38,local_30);
                (*pcVar2)(local_38,local_30,3,*(undefined1 *)(iVar5 + 0x10 + iVar10));
                (**(code **)(*local_38 + 0x88))(local_38,local_30,iVar5,4);
              }
              iVar5 = 1;
              do {
                if ((&cStack_25)[iVar5] != '\x04') {
                  (&cStack_25)[iVar5] = '\x03';
                }
                iVar10 = local_24;
                iVar5 = iVar5 + 1;
              } while (iVar5 != 5);
              if (local_3c == 0) {
                param_3[0x27] = local_24;
                bVar3 = true;
              }
              else {
                iVar5 = FUN_0010b0f4(param_3,local_3c);
                *(int *)(iVar5 + 0x10) = iVar10;
                bVar3 = true;
              }
            }
            cVar4 = FUN_00119104(*(undefined4 *)(local_38[0x22] + 8),*(undefined4 *)(param_6 + 8));
            if (cVar4 != '\0') {
              cVar4 = FUN_0010a62e(local_38,param_6);
              if (cVar4 == '\0') {
                *(undefined1 *)((int)local_38 + 0x9f) = 0;
              }
              else {
                local_38[0x27] = DAT_001cc794;
              }
              iVar5 = 1;
              do {
                if ((&cStack_25)[iVar5] != '\x04') {
                  (&cStack_25)[iVar5] = '\x03';
                }
                iVar10 = local_24;
                iVar5 = iVar5 + 1;
              } while (iVar5 != 5);
              if (local_3c == 0) {
                param_3[0x27] = local_24;
              }
              else {
                iVar5 = FUN_0010b0f4(param_3,local_3c);
                *(int *)(iVar5 + 0x10) = iVar10;
              }
LAB_00197cf5:
              if (local_3c == param_1) {
                param_4[0x27] = DAT_001cc794;
                for (iVar5 = 1; iVar10 = (**(code **)(*param_4 + 0x14))(param_4), iVar5 <= iVar10;
                    iVar5 = iVar5 + 1) {
                  if (iVar5 == 0) {
                    param_4[0x27] = DAT_001cc77c;
                  }
                  else {
                    iVar10 = FUN_0010b0f4(param_4,iVar5);
                    *(int *)(iVar10 + 0x10) = DAT_001cc77c;
                  }
                  (**(code **)(*param_4 + 0x88))(param_4,iVar5,3,3);
                }
              }
              break;
            }
            if (bVar3) goto LAB_00197cf5;
          }
        }
      }
    }
  }
  cVar4 = FUN_001a0c4c(param_3,*(undefined4 *)(param_6 + 8));
  if ((cVar4 == '\0') && (param_8 != '\0')) {
    if (param_7 != '\0') {
      if (param_10 == (int *)0x0) {
        uVar7 = *(undefined4 *)(param_6 + 8);
        piVar6 = param_5;
      }
      else {
        uVar7 = *(undefined4 *)(param_6 + 8);
        piVar6 = param_10;
      }
      FUN_0010ba02(param_3,param_1,piVar6,0,uVar7);
      iVar5 = FUN_0010b0f4(param_3,param_1);
      *(undefined4 *)(iVar5 + 0x10) = uVar1;
      if ((param_2 != 0) && ((param_3[param_1 * 6 + 0x28] & 2U) == 0)) {
        FUN_00109c0e(param_3 + param_1 * 6 + 0x23,1,param_3[param_1 * 6 + 0x28] & 1U ^ 1);
      }
    }
    if (param_10 == (int *)0x0) {
      param_5[0x54] = *(int *)(param_6 + 0x468) + -1;
    }
    else {
      param_10[0x54] = *(int *)(param_6 + 0x468) + -1;
    }
    *(int *)(param_6 + 0x208) = *(int *)(param_6 + 0x208) + 1;
    return 0;
  }
  if (param_7 != '\0') {
    *(int *)(param_6 + 0x200) = *(int *)(param_6 + 0x200) + 1;
    FUN_000e956e(param_3[0x56],param_3,param_4);
    param_4[0x58] = *(int *)(param_6 + 0x46c) + 1;
  }
  iVar5 = FUN_0010b0f4(param_4,0);
  uVar7 = FUN_000f5fea(*(undefined4 *)(iVar5 + 0x10));
  iVar5 = FUN_000f5b96(DAT_001cc778,uVar7);
  if (0 < param_4[0x21]) {
    iVar10 = 1;
    do {
      if (param_7 != '\0') {
        iVar8 = *(int *)(param_6 + 0x46c);
        iVar9 = FUN_0010b180(param_4,iVar10);
        if (iVar8 < *(int *)(iVar9 + 0x160)) {
          *(int *)(iVar9 + 0x160) = *(int *)(iVar9 + 0x160) + 1;
        }
        else {
          *(int *)(iVar9 + 0x160) = iVar8 + 1;
        }
      }
      iVar8 = (**(code **)(*param_4 + 0x14))(param_4);
      if (iVar10 <= iVar8) {
        if (iVar10 == 0) {
          param_4[0x27] = iVar5;
        }
        else {
          iVar8 = FUN_0010b0f4(param_4,iVar10);
          *(int *)(iVar8 + 0x10) = iVar5;
        }
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 <= param_4[0x21]);
  }
  if (param_7 != '\0') {
    if (param_10 == (int *)0x0) {
      param_5[5] = param_5[5] | 0x40000;
      FUN_0010b3fe(param_5,*(undefined4 *)(param_6 + 8));
    }
    else {
      param_10[5] = param_10[5] | 0x40000;
      FUN_0010b3fe(param_10,*(undefined4 *)(param_6 + 8));
      FUN_001a7d72(param_5);
    }
  }
  if (param_9 != (undefined4 *)0x0) {
    *param_9 = param_4;
  }
  return 1;
}

/* FUN_00197fb4 @ 0x197fb4 (1297 bytes) */
int FUN_00197fb4(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  int param_4;
{
  byte bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  int local_80;
  int *local_74;
  int local_68;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  undefined1 *local_50;
  undefined4 uStack_48;
  int local_44 [3];
  byte bStack_35;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  int local_20 [4];
  
  iVar4 = FUN_0010b0f4(param_1,1);
  local_34 = *(int *)(iVar4 + 0x10);
  iVar4 = FUN_0010b0f4(param_1,2);
  local_20[0] = *(int *)(iVar4 + 0x10);
  if (local_34 == local_20[0]) {
    return 1;
  }
  iVar4 = FUN_0010b0f4(param_1,0);
  local_30 = *(undefined4 *)(iVar4 + 0x10);
  local_80 = 0;
  do {
    iVar4 = 0;
    pcVar5 = &DAT_001cc780 + local_80 * 4;
    while ((*(char *)((int)&local_30 + iVar4) != '\0' ||
           ((*(char *)((int)&local_34 + iVar4) == *(char *)((int)local_20 + iVar4) &&
            (*pcVar5 == *(char *)((int)&local_34 + iVar4)))))) {
      iVar4 = iVar4 + 1;
      pcVar5 = pcVar5 + 1;
      if (iVar4 == 4) {
        return 1;
      }
    }
    local_80 = local_80 + 1;
  } while (local_80 != 5);
  cVar3 = FUN_000f5a1e(param_1,1);
  if ((cVar3 == '\0') && (cVar3 = FUN_000f5a1e(param_1,2), cVar3 == '\0')) {
    piVar9 = (int *)(*(int *)(param_4 + 0x3f4) + 0x204);
    *piVar9 = *piVar9 + 1;
    return 0;
  }
  piVar9 = (int *)*param_2;
  piVar10 = (int *)*param_3;
  cVar3 = FUN_000f5a1e(param_1,1);
  if (cVar3 == '\0') {
    local_68 = 1;
    piVar10 = piVar9;
  }
  else {
    local_34 = local_20[0];
    local_68 = 2;
  }
  iVar4 = *(int *)(param_4 + 0x3f4);
  iVar6 = FUN_0010b0f4(param_1,0);
  local_24 = *(uint *)(iVar6 + 0x10);
  iVar6 = FUN_0010b0f4(piVar10,0);
  local_28 = *(uint *)(iVar6 + 0x10);
  local_2c = DAT_001cc77c;
  if ((*(byte *)((int)piVar10 + 0x15) & 2) != 0) {
    piVar9 = (int *)(*(int *)(param_4 + 0x3f4) + 0x204);
    *piVar9 = *piVar9 + 1;
    iVar6 = FUN_0010b0f4(piVar10,piVar10[0x21]);
    local_2c = *(int *)(iVar6 + 0x10);
    iVar6 = 1;
    do {
      if (((&bStack_35)[iVar6] != 4) &&
         (*(char *)((int)&local_2c + (uint)(&bStack_35)[iVar6]) != '\x04')) {
        bVar2 = false;
        goto LAB_00198125;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 != 5);
  }
  bVar2 = true;
LAB_00198125:
  if (bVar2) {
    cVar3 = FUN_001195a6(param_4,piVar10);
    if (cVar3 == '\0') {
      cVar3 = FUN_00119104(*(undefined4 *)(piVar10[0x22] + 8),param_4);
      if (cVar3 != '\0') {
        cVar3 = FUN_0010a62e(piVar10,iVar4);
        uVar8 = local_24;
        if (cVar3 == '\0') {
          iVar6 = 1;
          do {
            if (((*(char *)((int)&local_28 + iVar6 + 3) == '\0') &&
                (cVar3 = *(char *)((int)&local_2c + iVar6 + 3), cVar3 != '\0')) &&
               ((cVar3 != '\x01' || (*(char *)((int)&local_30 + iVar6 + 3) != '\x04'))))
            goto LAB_0019812d;
            iVar6 = iVar6 + 1;
          } while (iVar6 != 5);
          uVar8 = local_24 & local_28;
        }
        piVar10[0x27] = uVar8;
        uVar7 = FUN_000f5fea(uVar8);
        uVar7 = FUN_000f5b96(DAT_001cc778,uVar7);
        if (local_68 != 0) {
          iVar4 = FUN_0010b0f4(param_1,local_68);
          *(undefined4 *)(iVar4 + 0x10) = uVar7;
          return 1;
        }
        *(undefined4 *)(param_1 + 0x9c) = uVar7;
        return 1;
      }
    }
    else {
      cVar3 = FUN_0010a62e(piVar10,iVar4);
      uVar8 = local_24;
      if (cVar3 == '\0') {
        iVar6 = 1;
        do {
          if ((*(char *)((int)&local_28 + iVar6 + 3) == '\0') &&
             ((*(char *)((int)&local_2c + iVar6 + 3) != '\x01' ||
              (*(char *)((int)&local_30 + iVar6 + 3) != '\x04')))) goto LAB_0019812d;
          iVar6 = iVar6 + 1;
        } while (iVar6 != 5);
        uVar8 = local_24 & local_28;
      }
      cVar3 = FUN_000f57b4(uVar8);
      if (cVar3 != '\0') {
        piVar10[0x27] = uVar8;
        cVar3 = FUN_0010a62e(piVar10,iVar4);
        if (cVar3 == '\0') {
          for (iVar4 = 1; iVar6 = (**(code **)(*piVar10 + 0x14))(piVar10), iVar4 <= iVar6;
              iVar4 = iVar4 + 1) {
            iVar6 = FUN_0010b0f4(piVar10,iVar4);
            (&uStack_48)[iVar4] = *(undefined4 *)(iVar6 + 0x10);
          }
        }
        else {
          piVar9 = local_44;
          for (local_60 = 1; iVar4 = (**(code **)(*piVar10 + 0x14))(piVar10), local_60 <= iVar4;
              local_60 = local_60 + 1) {
            *piVar9 = DAT_001cc77c;
            piVar9 = piVar9 + 1;
          }
        }
        iVar4 = FUN_0010b0f4(param_1,local_68);
        local_30 = *(undefined4 *)(iVar4 + 0x10);
        local_5c = 0;
        do {
          if (*(char *)((int)local_20 + local_5c + -4) == '\0') {
            local_58 = 1;
            local_50 = (undefined1 *)((int)local_44 + local_5c);
            while( true ) {
              iVar4 = (**(code **)(*piVar10 + 0x14))(piVar10);
              if (iVar4 < local_58) break;
              bVar1 = *(byte *)((int)&local_30 + local_5c);
              iVar4 = FUN_0010b0f4(piVar10,local_58);
              *local_50 = *(undefined1 *)(bVar1 + 0x10 + iVar4);
              local_58 = local_58 + 1;
              local_50 = local_50 + 4;
            }
          }
          local_5c = local_5c + 1;
        } while (local_5c != 4);
        local_74 = local_44;
        for (local_54 = 1; iVar4 = (**(code **)(*piVar10 + 0x14))(piVar10), local_54 <= iVar4;
            local_54 = local_54 + 1) {
          iVar4 = *local_74;
          if (local_54 == 0) {
            piVar10[0x27] = iVar4;
          }
          else {
            iVar6 = FUN_0010b0f4(piVar10,local_54);
            *(int *)(iVar6 + 0x10) = iVar4;
          }
          local_74 = local_74 + 1;
        }
        uVar7 = FUN_000f5fea(local_24);
        uVar7 = FUN_000f5b96(DAT_001cc778,uVar7);
        if (local_68 == 0) {
          *(undefined4 *)(param_1 + 0x9c) = uVar7;
          return 1;
        }
        iVar4 = FUN_0010b0f4(param_1,local_68);
        *(undefined4 *)(iVar4 + 0x10) = uVar7;
        return 1;
      }
    }
  }
LAB_0019812d:
  *(int *)(iVar4 + 0x204) = *(int *)(iVar4 + 0x204) + 1;
  return 0;
}

/* FUN_001984c6 @ 0x1984c6 (3879 bytes) */
int FUN_001984c6(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  int *param_3;
  int param_4;
  int param_5;
  int param_6;
  undefined4 param_7;
{
  undefined4 uVar1;
  char cVar2;
  byte bVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  byte bVar10;
  int *local_a8;
  int local_70;
  float local_6c;
  int aiStack_5c [5];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  int *local_24 [5];
  
  local_48 = 0x3f800000;
  local_44 = 0x3f800000;
  local_40 = 0x3f800000;
  local_3c = 0x3f800000;
  local_38 = 0x3f000000;
  local_34 = 0x3f000000;
  local_30 = 0x3f000000;
  local_2c = 0x3f000000;
  if (param_1 == (int *)0x0) {
    return '\0';
  }
  FUN_0010b180(param_1,param_2);
  iVar5 = (**(code **)(*param_1 + 0x14))(param_1);
  if (iVar5 < param_2) {
    return '\0';
  }
  cVar2 = (**(code **)(*param_1 + 0x5c))(param_1);
  if (cVar2 != '\0') {
    return '\0';
  }
  cVar2 = (**(code **)(*param_1 + 0x28))(param_1);
  if (cVar2 != '\0') {
    return '\0';
  }
  if ((*(byte *)(param_1 + 5) & 2) != 0) {
    return '\0';
  }
  cVar2 = (**(code **)(*param_1 + 100))(param_1);
  if (cVar2 != '\0') {
    iVar8 = 1;
    iVar5 = (**(code **)(*param_1 + 0x14))(param_1);
    if (0 < iVar5) {
      do {
        if ((((param_1[iVar8 * 6 + 0x28] & 1U) != 0) || ((param_1[iVar8 * 6 + 0x28] & 2U) != 0)) ||
           (cVar2 = FUN_000f5a1e(param_1,iVar8), cVar2 == '\0')) goto LAB_0019856b;
        iVar8 = iVar8 + 1;
        iVar5 = (**(code **)(*param_1 + 0x14))(param_1);
      } while (iVar8 <= iVar5);
    }
    if (((char)param_1[0x48] == '\0') && (param_1[0x49] == 0)) {
      if (((param_1[0x20] != 0) &&
          ((cVar2 = FUN_0012dfd8(param_1[0x26]), cVar2 != '\0' &&
           ((*(byte *)(param_1 + 5) & 2) == 0)))) &&
         (cVar2 = (**(code **)(*param_1 + 0x50))(param_1), cVar2 == '\0')) {
        iVar5 = 4;
        piVar7 = param_1;
        do {
          if ((byte)((char)piVar7[0x27] - 2U) < 2) goto LAB_0019856b;
          piVar7 = (int *)((int)piVar7 + 1);
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      FUN_0010b0f4(param_1,0);
      iVar5 = FUN_0010b7c8(param_1,0);
      if (((iVar5 == 0) && ((param_1[5] & 2U) == 0)) && ((param_1[5] & 0x200U) == 0)) {
        return '\0';
      }
    }
  }
LAB_0019856b:
  if (*(int *)(param_1[0x22] + 8) == 0x8e) {
    return '\0';
  }
  cVar2 = (**(code **)(*param_3 + 0x5c))(param_3);
  if (cVar2 != '\0') {
    return '\0';
  }
  if ((char)param_3[0x48] != '\0') {
    return '\0';
  }
  cVar2 = ((int (*)())FUN_0019cc9a)(param_1,param_2);
  if (cVar2 != '\0') {
    return '\0';
  }
  uVar6 = param_3[5];
  if ((uVar6 & 0x200) == 0) {
    local_a8 = (int *)0x0;
  }
  else {
    iVar5 = param_3[1];
    FUN_001a7d72(param_3);
    local_24[1] = (int *)FUN_0010a1c2(param_3,*(undefined4 *)(param_4 + 8),1);
    cVar2 = FUN_001679a2(local_24 + 1,1,param_4);
    if (cVar2 == '\0') {
      FUN_000e9596(*(undefined4 *)(iVar5 + 0x158),iVar5,param_3);
      return '\0';
    }
    FUN_000e9596(*(undefined4 *)(iVar5 + 0x158),iVar5,local_24[1]);
    FUN_000e9596(*(undefined4 *)(iVar5 + 0x158),local_24[1],param_3);
    local_a8 = param_3;
    param_3 = local_24[1];
    uVar6 = local_24[1][5];
  }
  if ((uVar6 & 0x200) != 0) {
    return '\0';
  }
  if (0 < param_3[0x21]) {
    iVar5 = 1;
    do {
      piVar7 = (int *)FUN_0010b180(param_3,iVar5);
      cVar2 = (**(code **)(*piVar7 + 0x60))(piVar7);
      if (cVar2 != '\0') {
        return '\0';
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= param_3[0x21]);
  }
  iVar5 = FUN_0010b0f4(param_3,0);
  uVar1 = *(undefined4 *)(iVar5 + 0x10);
  iVar5 = param_3[0x22];
  if (*(int *)(iVar5 + 8) == 0x12) {
    local_24[1] = (int *)FUN_0010b180(param_3,1);
    cVar2 = FUN_0012e014(local_24[1][0x26]);
    if (cVar2 == '\0') {
      if (local_24[1][0x26] == 0x33) {
        iVar5 = FUN_0010b0f4(param_3,1);
        local_24[0] = *(int **)(iVar5 + 0x10);
        iVar5 = 1;
        do {
          bVar10 = *(byte *)(iVar5 + -1 + (int)local_24);
          if (bVar10 != 4) {
            aiStack_5c[iVar5] = local_24[1][(uint)bVar10 * 6 + 8];
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 != 5);
        uVar9 = *(undefined4 *)(param_4 + 0x3a0);
        local_24[1] = (int *)FUN_000f80ae(uVar9,aiStack_5c + 1,local_24);
        if (local_24[1] == (int *)0x0) {
          local_24[1] = (int *)FUN_000f7a2e(uVar9,aiStack_5c + 1,local_24);
        }
        piVar7 = local_24[0];
        if (local_24[1] == (int *)0x0) {
          return '\0';
        }
        iVar5 = FUN_0010b0f4(param_3,1);
        *(int **)(iVar5 + 0x10) = piVar7;
        FUN_0010ba02(param_3,1,local_24[1],0,*(undefined4 *)(param_4 + 8));
      }
      else {
        local_24[1] = (int *)0x0;
      }
    }
    if (local_24[1] == (int *)0x0) {
      return '\0';
    }
    cVar2 = (**(code **)(*local_24[1] + 0x5c))(local_24[1]);
    if (cVar2 != '\0') {
      return '\0';
    }
    if ((*(byte *)(param_3 + 0x2e) & 2) != 0) {
      return '\0';
    }
    if (param_3[0x49] != 0) {
      return '\0';
    }
    cVar2 = FUN_000f7e7e(param_3,2,uVar1,&local_70);
    if ((cVar2 == '\0') || (local_70 != 2)) {
      bVar4 = false;
    }
    else {
      bVar4 = true;
    }
    if (bVar4) {
      if (local_6c != FLOAT_001c5ba4) {
        if ((local_6c != FLOAT_001c5bdc) || (NAN(local_6c) || NAN(FLOAT_001c5bdc))) {
          if ((local_6c != FLOAT_001c5bd4) || (NAN(local_6c) || NAN(FLOAT_001c5bd4))) {
            if ((local_6c != FLOAT_001c5c2c) || (NAN(local_6c) || NAN(FLOAT_001c5c2c)))
            goto LAB_00198c8b;
          }
          cVar2 = ((int (*)())FUN_00197484)(param_1,param_2,param_4);
          if ((cVar2 != '\0') &&
             ((local_6c == FLOAT_001c5bd4) == (bool)(*(byte *)(param_3 + 0x2e) & 1))) {
            iVar5 = FUN_0010a17a(0x99,*(undefined4 *)(param_4 + 8));
            uVar1 = *(undefined4 *)(iVar5 + 0x14c);
            iVar8 = FUN_0010b0f4(iVar5,0);
            *(undefined4 *)(iVar8 + 8) = uVar1;
            *(undefined4 *)(iVar8 + 0xc) = 0x31;
            uVar1 = *(undefined4 *)(param_4 + 8);
            uVar9 = FUN_0010b180(param_3,1);
            FUN_0010ba02(iVar5,1,uVar9,0,uVar1);
            cVar2 = ((int (*)())FUN_001977d8)(param_2,local_6c == FLOAT_001c5c2c,param_1,iVar5,param_3,param_4,
                                 param_5,param_6,param_7,local_a8);
            if (cVar2 != '\0') {
              param_1[0x49] = param_1[0x49] + -1;
              return cVar2;
            }
            return '\0';
          }
          goto LAB_00198c8b;
        }
      }
      bVar4 = local_6c == FLOAT_001c5bdc;
      if ((bool)(*(byte *)(param_3 + 0x2e) & 1) == bVar4) {
        return '\0';
      }
      iVar8 = FUN_0010a17a(0x9c,*(undefined4 *)(param_4 + 8));
      uVar1 = *(undefined4 *)(iVar8 + 0x14c);
      iVar5 = FUN_0010b0f4(iVar8,0);
      *(undefined4 *)(iVar5 + 8) = uVar1;
      *(undefined4 *)(iVar5 + 0xc) = 0x31;
      FUN_0010ba02(iVar8,1,local_24[1],0,*(undefined4 *)(param_4 + 8));
      goto LAB_00198bcf;
    }
LAB_00198c8b:
    local_28 = (int *)FUN_0010b180(param_3,2);
    cVar2 = FUN_0012e014(local_28[0x26]);
    if (cVar2 == '\0') {
      if (local_28[0x26] == 0x33) {
        iVar5 = FUN_0010b0f4(param_3,2);
        local_24[0] = *(int **)(iVar5 + 0x10);
        iVar5 = 1;
        do {
          bVar10 = *(byte *)(iVar5 + -1 + (int)local_24);
          if (bVar10 != 4) {
            aiStack_5c[iVar5] = local_28[(uint)bVar10 * 6 + 8];
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 != 5);
        uVar1 = *(undefined4 *)(param_4 + 0x3a0);
        local_28 = (int *)FUN_000f80ae(uVar1,aiStack_5c + 1,local_24);
        if (local_28 == (int *)0x0) {
          local_28 = (int *)FUN_000f7a2e(uVar1,aiStack_5c + 1,local_24);
        }
        piVar7 = local_24[0];
        if (local_28 == (int *)0x0) {
          return '\0';
        }
        iVar5 = FUN_0010b0f4(param_3,2);
        *(int **)(iVar5 + 0x10) = piVar7;
        FUN_0010ba02(param_3,2,local_28,0,*(undefined4 *)(param_4 + 8));
      }
      else {
        local_28 = (int *)0x0;
      }
    }
    if (local_28 == (int *)0x0) {
      return '\0';
    }
    if ((*(byte *)(param_3 + 0x34) & 2) != 0) {
      return '\0';
    }
    cVar2 = (**(code **)(*local_28 + 0x5c))(local_28);
    if (cVar2 != '\0') {
      return '\0';
    }
    cVar2 = ((int (*)())FUN_00197fb4)(param_3,local_24 + 1,&local_28,*(undefined4 *)(param_4 + 8));
    if (cVar2 == '\0') {
      return '\0';
    }
    if ((*(byte *)(param_3 + 0x34) & 1) == (*(byte *)(param_3 + 0x2e) & 1)) {
      iVar5 = FUN_0010a17a(0x9b,*(undefined4 *)(param_4 + 8));
      uVar1 = *(undefined4 *)(iVar5 + 0x14c);
      iVar8 = FUN_0010b0f4(iVar5,0);
      *(undefined4 *)(iVar8 + 8) = uVar1;
      *(undefined4 *)(iVar8 + 0xc) = 0x31;
      FUN_0010ba02(iVar5,1,local_24[1],0,*(undefined4 *)(param_4 + 8));
      FUN_0010ba02(iVar5,2,local_28,0,*(undefined4 *)(param_4 + 8));
    }
    else {
      iVar5 = FUN_0010a17a(0x9a,*(undefined4 *)(param_4 + 8));
      uVar1 = *(undefined4 *)(iVar5 + 0x14c);
      iVar8 = FUN_0010b0f4(iVar5,0);
      *(undefined4 *)(iVar8 + 8) = uVar1;
      *(undefined4 *)(iVar8 + 0xc) = 0x31;
      FUN_0010ba02(iVar5,1,local_24[1],0,*(undefined4 *)(param_4 + 8));
      FUN_0010ba02(iVar5,2,local_28,0,*(undefined4 *)(param_4 + 8));
    }
    bVar10 = *(byte *)(param_3 + 0x2e) & 1;
    goto LAB_001987e2;
  }
  if (*(int *)(iVar5 + 8) == 0x31) {
    iVar5 = FUN_0010b180(param_3,1);
    uVar9 = 0;
    if (iVar5 != 0) {
      iVar5 = FUN_0010b180(param_3,1);
      uVar9 = *(undefined4 *)(iVar5 + 0x98);
    }
    cVar2 = FUN_0012e014(uVar9);
    if (cVar2 == '\0') {
      iVar5 = param_3[0x22];
    }
    else if ((*(byte *)(param_3 + 0x2e) & 2) == 0) {
      piVar7 = (int *)FUN_0010b180(param_3,1);
      cVar2 = (**(code **)(*piVar7 + 0x5c))(piVar7);
      if ((cVar2 == '\0') && (param_3[0x49] == 1)) {
        if ((*(byte *)(param_3 + 0x2e) & 1) == 0) {
          if ((*(byte *)(param_3 + 0x34) & 1) != 0) goto LAB_00199036;
LAB_0019915a:
          bVar4 = false;
        }
        else {
          if ((*(byte *)(param_3 + 0x34) & 1) != 0) goto LAB_0019915a;
LAB_00199036:
          bVar4 = true;
        }
        iVar8 = FUN_0010a17a(0x9b,*(undefined4 *)(param_4 + 8));
        uVar1 = *(undefined4 *)(iVar8 + 0x14c);
        iVar5 = FUN_0010b0f4(iVar8,0);
        *(undefined4 *)(iVar5 + 8) = uVar1;
        *(undefined4 *)(iVar5 + 0xc) = 0x31;
        uVar1 = *(undefined4 *)(param_4 + 8);
        uVar9 = FUN_0010b180(param_3,1);
        FUN_0010ba02(iVar8,1,uVar9,0,uVar1);
        uVar1 = *(undefined4 *)(param_4 + 8);
        uVar9 = FUN_0010b180(param_3,1);
        FUN_0010ba02(iVar8,2,uVar9,0,uVar1);
LAB_00198bcf:
        cVar2 = ((int (*)())FUN_001977d8)(param_2,bVar4,param_1,iVar8,param_3,param_4,param_5,param_6,param_7,
                             local_a8);
        return cVar2;
      }
      iVar5 = param_3[0x22];
    }
    else {
      iVar5 = param_3[0x22];
    }
  }
  if (*(int *)(iVar5 + 8) != 0x14) {
    return '\0';
  }
  iVar5 = FUN_0010b180(param_3,1);
  if (iVar5 == 0) {
    uVar9 = 0;
  }
  else {
    iVar5 = FUN_0010b180(param_3,1);
    uVar9 = *(undefined4 *)(iVar5 + 0x98);
  }
  cVar2 = FUN_0012e014(uVar9);
  if (cVar2 == '\0') {
    return '\0';
  }
  if ((*(byte *)(param_3 + 0x2e) & 2) != 0) {
    return '\0';
  }
  piVar7 = (int *)FUN_0010b180(param_3,1);
  cVar2 = (**(code **)(*piVar7 + 0x5c))(piVar7);
  if (cVar2 != '\0') {
    return '\0';
  }
  cVar2 = FUN_000f7dda(param_3,2,uVar1,&local_48);
  if (cVar2 == '\0') {
    return '\0';
  }
  cVar2 = FUN_000f7dda(param_3,3,uVar1,&local_38);
  if (cVar2 == '\0') {
    return '\0';
  }
  if (param_3[0x49] != 1) {
    return '\0';
  }
  bVar10 = *(byte *)(param_3 + 0x3a) & 1;
  if ((*(byte *)(param_3 + 0x2e) & 1) == 0) {
    if ((*(byte *)(param_3 + 0x34) & 1) != 0) goto LAB_00198715;
LAB_00199008:
    bVar3 = 0;
  }
  else {
    if ((*(byte *)(param_3 + 0x34) & 1) != 0) goto LAB_00199008;
LAB_00198715:
    bVar3 = 1;
  }
  if (bVar3 == bVar10) {
    return '\0';
  }
  iVar5 = FUN_0010a17a(0x99,*(undefined4 *)(param_4 + 8));
  uVar1 = *(undefined4 *)(iVar5 + 0x14c);
  iVar8 = FUN_0010b0f4(iVar5,0);
  *(undefined4 *)(iVar8 + 8) = uVar1;
  *(undefined4 *)(iVar8 + 0xc) = 0x31;
  uVar1 = *(undefined4 *)(param_4 + 8);
  uVar9 = FUN_0010b180(param_3,1);
  FUN_0010ba02(iVar5,1,uVar9,0,uVar1);
LAB_001987e2:
  cVar2 = ((int (*)())FUN_001977d8)(param_2,bVar10,param_1,iVar5,param_3,param_4,param_5,param_6,param_7,local_a8
                      );
  return cVar2;
}

/* FUN_001993ee @ 0x1993ee (66 bytes) */
int FUN_001993ee(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
  int param_7;
  undefined4 param_8;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_001984c6)(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return uVar1;
}

/* FUN_00199430 @ 0x199430 (1742 bytes) */
int FUN_00199430(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined4 uVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  byte bVar13;
  byte bVar14;
  
  if ((((((param_1 == (int *)0x0) || (*(int *)(*(int *)(param_3 + 0x88) + 8) != 0x12)) ||
        (*(int *)(param_1[0x22] + 8) != 0x12)) ||
       (((cVar2 = FUN_0010a62e(param_3,param_4), cVar2 == '\0' ||
         (*(char *)(param_3 + 0x120) != '\0')) ||
        ((*(int *)(param_3 + 0x124) != 0 || (((char)param_1[0x48] != '\0' || (param_1[0x49] != 0))))
        )))) || ((*(byte *)((int)param_1 + 0x15) & 2) != 0)) ||
     (((*(uint *)(param_3 + 0x14) & 0x200) != 0 || ((*(uint *)(param_3 + 0x14) & 0x40000) != 0)))) {
LAB_00199457:
    cVar2 = ((int (*)())FUN_001984c6)(param_1,param_2,param_3,param_4,1,1,0);
  }
  else {
    iVar5 = FUN_0010b0f4(param_3,0);
    iVar5 = *(int *)(iVar5 + 0x10);
    iVar6 = FUN_0010b0f4(param_1,0);
    if (*(int *)(iVar6 + 0x10) != iVar5) {
      iVar5 = FUN_0010b0f4(param_3,0);
      cVar2 = FUN_000f5f28(*(undefined4 *)(iVar5 + 0x10));
      if (cVar2 == '\0') goto LAB_00199457;
    }
    cVar2 = FUN_000f5a1e(param_1,param_2);
    if (cVar2 == '\0') {
      cVar2 = (**(code **)(*param_1 + 0x60))(param_1);
      if (cVar2 != '\0') {
        return 0;
      }
      iVar5 = FUN_0010b0f4(param_1,param_2);
      uVar8 = *(undefined4 *)(iVar5 + 0x10);
      iVar5 = FUN_0010b0f4(param_1,0);
      uVar1 = *(undefined4 *)(iVar5 + 0x10);
      *(undefined4 *)(param_3 + 0x9c) = uVar1;
      iVar5 = FUN_0010b0f4(param_3,1);
      uVar7 = FUN_000f5610(*(undefined4 *)(iVar5 + 0x10),uVar8);
      iVar5 = FUN_0010b0f4(param_3,1);
      *(undefined4 *)(iVar5 + 0x10) = uVar7;
      iVar5 = FUN_0010b0f4(param_3,2);
      uVar8 = FUN_000f5610(*(undefined4 *)(iVar5 + 0x10),uVar8);
      iVar5 = FUN_0010b0f4(param_3,2);
      *(undefined4 *)(iVar5 + 0x10) = uVar8;
      uVar8 = FUN_000f5fea(uVar1);
      iVar5 = FUN_000f5b96(DAT_001cc778,uVar8);
      if (param_2 == 0) {
        param_1[0x27] = iVar5;
      }
      else {
        iVar6 = FUN_0010b0f4(param_1,param_2);
        *(int *)(iVar6 + 0x10) = iVar5;
      }
    }
    piVar9 = (int *)FUN_0010b180(param_3,1);
    FUN_0010b0f4(param_3,1);
    piVar10 = (int *)FUN_0010b180(param_3,2);
    bVar13 = (byte)*(uint *)(param_3 + 0xd0) & 1;
    bVar3 = (byte)(*(uint *)(param_3 + 0xd0) >> 1) & 1;
    iVar5 = FUN_0010b0f4(param_3,2);
    uVar8 = *(undefined4 *)(iVar5 + 0x10);
    iVar5 = (param_2 == 1) + 1;
    piVar11 = (int *)FUN_0010b180(param_1,iVar5);
    bVar14 = (byte)param_1[iVar5 * 6 + 0x28] & 1;
    bVar4 = (byte)((uint)param_1[iVar5 * 6 + 0x28] >> 1) & 1;
    iVar6 = FUN_0010b0f4(param_1,iVar5);
    uVar1 = *(undefined4 *)(iVar6 + 0x10);
    cVar2 = (**(code **)(*piVar9 + 0x5c))(piVar9);
    if (cVar2 != '\0') {
      return 0;
    }
    cVar2 = (**(code **)(*piVar10 + 0x5c))(piVar10);
    if (cVar2 != '\0') {
      return 0;
    }
    cVar2 = (**(code **)(*piVar11 + 0x5c))(piVar11);
    if (cVar2 != '\0') {
      return 0;
    }
    cVar2 = (**(code **)(*piVar11 + 0x48))(piVar11);
    if ((((cVar2 != '\0') && (cVar2 = (**(code **)(*piVar9 + 0x48))(piVar9), cVar2 == '\0')) &&
        (cVar2 = (**(code **)(*piVar10 + 0x48))(piVar10), cVar2 == '\0')) &&
       ((*(byte *)(param_1 + param_2 * 6 + 0x28) & 2) == 0)) {
      FUN_0010ba02(param_3,2,piVar11,0,*(undefined4 *)(param_4 + 8));
      iVar6 = param_3 + 0xbc;
      FUN_00109c0e(iVar6,1,bVar14);
      FUN_00109c0e(iVar6,2,bVar4);
      iVar12 = FUN_0010b0f4(param_3,2);
      *(undefined4 *)(iVar12 + 0x10) = uVar1;
      FUN_0010ba02(param_1,iVar5,piVar10,0,*(undefined4 *)(param_4 + 8));
      piVar9 = param_1 + iVar5 * 6 + 0x23;
      FUN_00109c0e(piVar9,1,bVar13);
      FUN_00109c0e(piVar9,2,bVar3);
      iVar12 = FUN_0010b0f4(param_1,iVar5);
      *(undefined4 *)(iVar12 + 0x10) = uVar8;
      if ((*(byte *)(param_1 + param_2 * 6 + 0x28) & 1) != 0) {
        FUN_00109c0e(iVar6,1,*(byte *)(param_3 + 0xd0) & 1 ^ 1);
        FUN_00109c0e(piVar9,1,*(byte *)(param_1 + iVar5 * 6 + 0x28) & 1 ^ 1);
      }
      cVar2 = ((int (*)())FUN_001984c6)(param_1,param_2,param_3,param_4,1,1,0);
      if (cVar2 != '\0') {
        return 1;
      }
      FUN_0010ba02(param_3,2,piVar10,0,*(undefined4 *)(param_4 + 8));
      FUN_00109c0e(iVar6,1,bVar13);
      FUN_00109c0e(iVar6,2,bVar3);
      iVar6 = FUN_0010b0f4(param_3,2);
      *(undefined4 *)(iVar6 + 0x10) = uVar8;
      FUN_0010ba02(param_1,iVar5,piVar11,0,*(undefined4 *)(param_4 + 8));
      FUN_00109c0e(piVar9,1,bVar14);
      FUN_00109c0e(piVar9,2,bVar4);
      iVar5 = FUN_0010b0f4(param_1,iVar5);
      *(undefined4 *)(iVar5 + 0x10) = uVar1;
    }
    cVar2 = ((int (*)())FUN_001984c6)(param_1,param_2,param_3,param_4,1,1,0);
  }
  if (cVar2 == '\0') {
    return 0;
  }
  return 1;
}

/* FUN_00199afe @ 0x199afe (3076 bytes) */
int FUN_00199afe(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  char cVar10;
  undefined4 uVar11;
  int *piVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined4 uVar17;
  int iVar18;
  undefined4 uVar19;
  int *piVar20;
  float *pfVar21;
  uint *puVar22;
  uint *puVar23;
  uint uVar24;
  float fVar25;
  float fVar26;
  int local_e8;
  float local_e4;
  int local_c8;
  uint local_50;
  int local_48;
  float local_44;
  float afStack_34 [5];
  float local_20 [4];
  
  cVar10 = (**(code **)(*param_1 + 0x24))(param_1);
  if ((((cVar10 == '\0') ||
       (piVar20 = *(int **)(*(int *)(param_3 + 8) + 0x54),
       cVar10 = (**(code **)(*piVar20 + 0xfc))(piVar20,param_2 + param_1[0x49],0), cVar10 == '\0'))
      || ((*(byte *)((int)param_1 + 0x15) & 2) != 0)) ||
     (((char)param_1[0x48] != '\0' ||
      (cVar10 = (**(code **)(*param_1 + 0x5c))(param_1), cVar10 != '\0')))) {
LAB_00199b1e:
    uVar11 = 0;
  }
  else {
    FUN_001a7e60(param_1[4],FUN_001973ae);
    puVar23 = (uint *)param_1[4];
    if (0 < (int)puVar23[1]) {
      uVar24 = 0;
      do {
        if (uVar24 < *puVar23) {
          uVar1 = puVar23[1];
          if (uVar1 <= uVar24) {
            _memset((void *)(puVar23[2] + uVar1 * 4),0,(uVar24 - uVar1) * 4 + 4);
            puVar23[1] = uVar24 + 1;
          }
          piVar20 = (int *)(puVar23[2] + uVar24 * 4);
        }
        else {
          piVar20 = (int *)FUN_001a7f7c(puVar23,uVar24);
        }
        piVar20 = (int *)*piVar20;
        if ((((*(byte *)((int)piVar20 + 0x15) & 2) != 0) ||
            (cVar10 = (**(code **)(*piVar20 + 0x28))(piVar20), cVar10 != '\0')) ||
           (cVar10 = (**(code **)(*piVar20 + 0x5c))(piVar20), cVar10 != '\0')) goto LAB_00199b1e;
        iVar13 = *(int *)(piVar20[0x22] + 8);
        if (iVar13 == 0x31) {
LAB_0019a4e7:
          if (((piVar20[0x21] != 2) ||
              ((piVar12 = (int *)FUN_0010b180(piVar20,1), param_1 != piVar12 ||
               (piVar12 = (int *)FUN_0010b180(piVar20,2), param_1 != piVar12)))) ||
             (piVar12 = *(int **)(*(int *)(param_3 + 8) + 0x54),
             cVar10 = (**(code **)(*piVar12 + 0xfc))(piVar12,piVar20[0x49] + param_2 * -2,0),
             cVar10 == '\0')) {
            iVar13 = *(int *)(param_3 + 8);
LAB_0019a4f6:
            cVar10 = (**(code **)(**(int **)(iVar13 + 0x54) + 0xfc))
                               (*(int **)(iVar13 + 0x54),piVar20[0x49] - param_2,0);
            goto joined_r0x00199cd5;
          }
        }
        else {
          if (0x31 < iVar13) {
            if ((iVar13 == 0x36) || (iVar13 == 0x66)) goto LAB_0019a4e7;
            if (iVar13 == 0x34) {
LAB_00199c1e:
              piVar12 = (int *)FUN_0010b180(piVar20,1);
              if ((param_1 != piVar12) ||
                 (piVar12 = (int *)FUN_0010b180(piVar20,2), param_1 != piVar12)) {
                if (param_2 < 0) {
                  fVar25 = (float)(1 << (-(byte)param_2 & 0x1f));
                }
                else {
                  fVar25 = FLOAT_001c5ba4 / (float)(1 << ((byte)param_2 & 0x1f));
                }
                pfVar21 = afStack_34 + 1;
                do {
                  *pfVar21 = NAN;
                  pfVar21 = pfVar21 + 1;
                } while (pfVar21 != local_20);
                iVar13 = 1;
                do {
                  afStack_34[iVar13] = fVar25;
                  iVar13 = iVar13 + 1;
                } while (iVar13 != 5);
                piVar20 = *(int **)(*(int *)(param_3 + 8) + 0x54);
                cVar10 = (**(code **)(*piVar20 + 0xe8))
                                   (piVar20,afStack_34 + 1,local_20,DAT_001cc778,
                                    *(int *)(param_3 + 8));
                goto joined_r0x00199cd5;
              }
              iVar13 = *(int *)(param_3 + 8);
              goto LAB_0019a4f6;
            }
            goto LAB_00199b1e;
          }
          if (iVar13 == 0x13) goto LAB_0019a4e7;
          if (iVar13 != 0x14) {
            if (iVar13 == 0x12) goto LAB_00199c1e;
            goto LAB_00199b1e;
          }
          iVar13 = FUN_0010b0f4(piVar20,0);
          cVar10 = FUN_000f7e7e(piVar20,2,*(undefined4 *)(iVar13 + 0x10),&local_48);
          fVar25 = local_44;
          if (((cVar10 == '\0') || (local_48 != 2)) ||
             (piVar20 = (int *)FUN_0010b180(piVar20,1), param_1 != piVar20)) goto LAB_00199b1e;
          if (param_2 < 0) {
            fVar26 = (float)(1 << (-(byte)param_2 & 0x1f));
          }
          else {
            fVar26 = FLOAT_001c5ba4 / (float)(1 << ((byte)param_2 & 0x1f));
          }
          pfVar21 = afStack_34 + 1;
          do {
            *pfVar21 = NAN;
            pfVar21 = pfVar21 + 1;
          } while (local_20 != pfVar21);
          iVar13 = 1;
          do {
            afStack_34[iVar13] = fVar26 * fVar25;
            iVar13 = iVar13 + 1;
          } while (iVar13 != 5);
          piVar20 = *(int **)(*(int *)(param_3 + 8) + 0x54);
          cVar10 = (**(code **)(*piVar20 + 0xe8))
                             (piVar20,afStack_34 + 1,local_20,DAT_001cc778,*(int *)(param_3 + 8));
joined_r0x00199cd5:
          if (cVar10 == '\0') goto LAB_00199b1e;
        }
        uVar24 = uVar24 + 1;
        puVar23 = (uint *)param_1[4];
      } while ((int)uVar24 < (int)puVar23[1]);
    }
    local_50 = puVar23[1] - 1;
    if (-1 < (int)local_50) {
      do {
        if (0 < (int)local_50) {
          uVar24 = local_50 - 1;
          if (uVar24 < *puVar23) {
            uVar1 = puVar23[1];
            puVar22 = puVar23;
            if (uVar1 <= uVar24) {
              _memset((void *)(puVar23[2] + uVar1 * 4),0,(uVar24 - uVar1) * 4 + 4);
              puVar23[1] = local_50;
              puVar22 = (uint *)param_1[4];
            }
            piVar20 = (int *)(puVar23[2] + uVar24 * 4);
          }
          else {
            piVar20 = (int *)FUN_001a7f7c(puVar23,uVar24);
            puVar22 = (uint *)param_1[4];
          }
          iVar13 = *piVar20;
          if (local_50 < *puVar22) {
            uVar24 = puVar22[1];
            if (uVar24 <= local_50) {
              _memset((void *)(puVar22[2] + uVar24 * 4),0,(local_50 - uVar24) * 4 + 4);
              puVar22[1] = local_50 + 1;
            }
            piVar20 = (int *)(puVar22[2] + local_50 * 4);
          }
          else {
            piVar20 = (int *)FUN_001a7f7c(puVar22,local_50);
          }
          if (iVar13 != *piVar20) {
            puVar23 = (uint *)param_1[4];
            goto LAB_00199da4;
          }
          goto LAB_00199d2a;
        }
LAB_00199da4:
        if (local_50 < *puVar23) {
          uVar24 = puVar23[1];
          if (uVar24 <= local_50) {
            _memset((void *)(puVar23[2] + uVar24 * 4),0,(local_50 - uVar24) * 4 + 4);
            puVar23[1] = local_50 + 1;
          }
          piVar20 = (int *)(puVar23[2] + local_50 * 4);
        }
        else {
          piVar20 = (int *)FUN_001a7f7c(puVar23,local_50);
        }
        piVar20 = (int *)*piVar20;
        iVar13 = *(int *)(piVar20[0x22] + 8);
        if (iVar13 == 0x31) {
LAB_0019a1fa:
          if ((piVar20[0x21] == 2) &&
             ((piVar12 = (int *)FUN_0010b180(piVar20,1), param_1 == piVar12 &&
              (piVar12 = (int *)FUN_0010b180(piVar20,2), param_1 == piVar12)))) {
            piVar20[0x49] = piVar20[0x49] + param_2 * -2;
          }
          else {
            piVar20[0x49] = piVar20[0x49] - param_2;
          }
        }
        else if (iVar13 < 0x32) {
          if (iVar13 == 0x13) goto LAB_0019a1fa;
          if (iVar13 == 0x14) {
            iVar13 = FUN_0010b0f4(piVar20,0);
            FUN_000f7e7e(piVar20,2,*(undefined4 *)(iVar13 + 0x10),&local_48);
            if (param_2 < 0) {
              fVar25 = (float)(1 << (-(byte)param_2 & 0x1f));
            }
            else {
              fVar25 = FLOAT_001c5ba4 / (float)(1 << ((byte)param_2 & 0x1f));
            }
            fVar25 = fVar25 * local_44;
            FUN_00109c0e(piVar20 + 0x2f,1,0);
            FUN_00109c0e(piVar20 + 0x2f,2,0);
            FUN_000fa0d2(piVar20,param_3,2,fVar25,fVar25,fVar25,fVar25);
          }
          else if (iVar13 == 0x12) goto LAB_00199df8;
        }
        else {
          if ((iVar13 == 0x36) || (iVar13 == 0x66)) goto LAB_0019a1fa;
          if (iVar13 == 0x34) {
LAB_00199df8:
            piVar12 = (int *)FUN_0010b180(piVar20,1);
            if ((param_1 == piVar12) &&
               (piVar12 = (int *)FUN_0010b180(piVar20,2), param_1 == piVar12)) {
              piVar20[0x49] = piVar20[0x49] - param_2;
            }
            else {
              if (param_2 < 0) {
                local_e4 = (float)(1 << (-(byte)param_2 & 0x1f));
              }
              else {
                local_e4 = FLOAT_001c5ba4 / (float)(1 << ((byte)param_2 & 0x1f));
              }
              iVar13 = piVar20[1];
              iVar2 = piVar20[0x56];
              FUN_001a7d72(piVar20);
              iVar14 = FUN_0010b0f4(piVar20,0);
              iVar14 = *(int *)(iVar14 + 0x10);
              iVar3 = piVar20[0x49];
              iVar9 = piVar20[0x48];
              iVar15 = FUN_00109e42(piVar20,param_3);
              iVar4 = piVar20[4];
              piVar12 = (int *)FUN_0010b180(piVar20,1);
              if (param_1 == piVar12) {
                local_e8 = 1;
                local_c8 = 2;
              }
              else {
                FUN_0010b180(piVar20,2);
                local_e8 = 2;
                local_c8 = 1;
              }
              iVar5 = piVar20[local_e8 * 6 + 0x25];
              iVar6 = piVar20[local_e8 * 6 + 0x26];
              iVar16 = FUN_0010b0f4(piVar20,local_e8);
              uVar11 = *(undefined4 *)(iVar16 + 0x10);
              uVar24 = piVar20[local_e8 * 6 + 0x28];
              uVar17 = FUN_0010b180(piVar20,local_e8);
              iVar16 = piVar20[local_c8 * 6 + 0x25];
              iVar7 = piVar20[local_c8 * 6 + 0x26];
              iVar18 = FUN_0010b0f4(piVar20,local_c8);
              uVar8 = *(undefined4 *)(iVar18 + 0x10);
              uVar1 = piVar20[local_c8 * 6 + 0x28];
              uVar19 = FUN_0010b180(piVar20,local_c8);
              (**(code **)(*piVar20 + 0xc))(piVar20,1,*(undefined4 *)(param_3 + 8));
              FUN_0010da48(piVar20,0x14,*(undefined4 *)(param_3 + 8));
              piVar20[4] = iVar4;
              piVar20[0x25] = piVar20[0x53];
              piVar20[0x26] = 0;
              piVar20[0x27] = iVar14;
              *(char *)(piVar20 + 0x48) = (char)iVar9;
              piVar20[0x49] = iVar3;
              piVar20[0x58] = iVar15 + *(int *)(param_3 + 0x46c);
              FUN_0010ba02(piVar20,1,uVar17,1,*(undefined4 *)(param_3 + 8));
              iVar14 = FUN_0010b0f4(piVar20,1);
              *(int *)(iVar14 + 8) = iVar5;
              *(int *)(iVar14 + 0xc) = iVar6;
              iVar14 = FUN_0010b0f4(piVar20,1);
              *(undefined4 *)(iVar14 + 0x10) = uVar11;
              FUN_00109c0e(piVar20 + 0x29,2,(byte)(uVar24 >> 1) & 1);
              FUN_00109c0e(piVar20 + 0x29,1,(byte)uVar24 & 1);
              FUN_0010ba02(piVar20,3,uVar19,1,*(undefined4 *)(param_3 + 8));
              iVar14 = FUN_0010b0f4(piVar20,3);
              *(int *)(iVar14 + 8) = iVar16;
              *(int *)(iVar14 + 0xc) = iVar7;
              iVar14 = FUN_0010b0f4(piVar20,3);
              *(undefined4 *)(iVar14 + 0x10) = uVar8;
              FUN_00109c0e(piVar20 + 0x35,2,(byte)(uVar1 >> 1) & 1);
              FUN_00109c0e(piVar20 + 0x35,1,(byte)uVar1 & 1);
              FUN_000fa0d2(piVar20,param_3,2,local_e4,local_e4,local_e4,local_e4);
              FUN_000e9596(iVar2,iVar13,piVar20);
            }
          }
        }
LAB_00199d2a:
        local_50 = local_50 - 1;
        if ((int)local_50 < 0) break;
        puVar23 = (uint *)param_1[4];
      } while( true );
    }
    param_1[0x49] = param_1[0x49] + param_2;
    uVar11 = 1;
  }
  return uVar11;
}

/* FUN_0019a70a @ 0x19a70a (1384 bytes) */
int FUN_0019a70a(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint uVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  uint *puVar9;
  int local_48;
  int *local_44;
  uint local_3c;
  int local_38;
  uint local_30;
  undefined4 local_24;
  undefined4 local_20;
  int local_14;
  undefined4 local_10;
  
  if (*(int *)(param_1[0x22] + 8) != 0x31) {
    return;
  }
  iVar4 = FUN_0010b180(param_1,1);
  uVar6 = 0;
  if (iVar4 != 0) {
    iVar4 = FUN_0010b180(param_1,1);
    uVar6 = *(undefined4 *)(iVar4 + 0x98);
  }
  cVar3 = FUN_0012e014(uVar6);
  if (cVar3 == '\0') {
    return;
  }
  piVar5 = (int *)FUN_0010b180(param_1,1);
  cVar3 = (**(code **)(*piVar5 + 0x5c))(piVar5);
  if (cVar3 != '\0') {
    return;
  }
  if ((*(byte *)((int)param_1 + 0x15) & 2) != 0) {
    return;
  }
  if ((char)param_1[0x48] != '\0') {
    return;
  }
  piVar5 = (int *)FUN_0010b180(param_1,1);
  cVar3 = (**(code **)(*piVar5 + 0x48))(piVar5);
  if (cVar3 != '\0') {
    return;
  }
  if (param_1[0x49] == 0) {
    return;
  }
  if (((param_1[0x2e] & 1U) == 0) && ((param_1[0x2e] & 2U) == 0)) {
    iVar4 = FUN_0010b0f4(param_1,1);
    cVar3 = FUN_000f59e0(*(undefined4 *)(iVar4 + 0x10));
    if (cVar3 != '\0') goto LAB_0019a7e8;
  }
  cVar3 = ((int (*)())FUN_001973ce)(param_1);
  if (cVar3 == '\0') {
    return;
  }
LAB_0019a7e8:
  iVar4 = param_1[0x49];
  uVar6 = FUN_0010b180(param_1,1);
  cVar3 = ((int (*)())FUN_00199afe)(uVar6,iVar4,param_2);
  if (cVar3 != '\0') {
    *(int *)(param_2 + 0x160) = *(int *)(param_2 + 0x160) + 1;
    uVar6 = FUN_0010b180(param_1,1);
    puVar9 = (uint *)param_1[4];
    local_3c = puVar9[1] - 1;
    if (-1 < (int)local_3c) {
      do {
        if (local_3c < *puVar9) {
          uVar1 = puVar9[1];
          if (uVar1 <= local_3c) {
            _memset((void *)(puVar9[2] + uVar1 * 4),0,(local_3c - uVar1) * 4 + 4);
            puVar9[1] = local_3c + 1;
          }
          piVar5 = (int *)(puVar9[2] + local_3c * 4);
        }
        else {
          piVar5 = (int *)FUN_001a7f7c(puVar9,local_3c);
        }
        piVar5 = (int *)*piVar5;
        local_44 = piVar5 + 0x23;
        local_48 = 0x80;
        for (local_38 = 0; iVar4 = (**(code **)(*piVar5 + 0x14))(piVar5), local_38 <= iVar4;
            local_38 = local_38 + 1) {
          piVar7 = (int *)FUN_0010b180(piVar5,local_38);
          if (param_1 == piVar7) {
            iVar4 = FUN_0010b0f4(piVar5,local_38);
            uVar2 = *(undefined4 *)(iVar4 + 0x10);
            iVar4 = FUN_0010b0f4(param_1,1);
            iVar4 = FUN_000f5610(*(undefined4 *)(iVar4 + 0x10),uVar2);
            local_3c = local_3c - 1;
            if ((*(int *)(piVar5[0x22] + 8) != 0x8e) ||
               (((cVar3 = FUN_000f59e0(iVar4), cVar3 != '\0' && ((param_1[0x2e] & 1U) == 0)) &&
                ((param_1[0x2e] & 2U) == 0)))) {
              FUN_0010ba02(piVar5,local_38,uVar6,1,*(undefined4 *)(param_2 + 8));
              if (local_38 == 0) {
                piVar5[0x27] = iVar4;
              }
              else {
                iVar8 = FUN_0010b0f4(piVar5,local_38);
                *(int *)(iVar8 + 0x10) = iVar4;
              }
              FUN_00109c0e(local_44,2,(uint)param_1[0x2e] >> 1 & 1);
              if ((*(byte *)(param_1 + 0x2e) & 1) != 0) {
                FUN_00109c0e(local_44,1,*(byte *)(local_48 + 0x20 + (int)piVar5) & 1 ^ 1);
              }
            }
          }
          local_48 = local_48 + 0x18;
          local_44 = local_44 + 6;
        }
        if (((*(byte *)((int)piVar5 + 0x15) & 2) != 0) &&
           (piVar7 = (int *)FUN_0010b180(piVar5,piVar5[0x21]), param_1 == piVar7)) {
          cVar3 = FUN_000f5a1e(param_1,1);
          if (cVar3 == '\0') {
            local_3c = local_3c - 1;
          }
          else {
            local_24 = 0;
            local_20 = 0;
            local_10 = 0;
            FUN_0010a980(piVar5,&local_24);
            uVar2 = *(undefined4 *)(param_2 + 8);
            iVar4 = FUN_0010b180(piVar5,piVar5[0x21]);
            puVar9 = *(uint **)(iVar4 + 0x10);
            if (0 < (int)puVar9[1]) {
              local_30 = 0;
              do {
                if (local_30 < *puVar9) {
                  uVar1 = puVar9[1];
                  if (uVar1 <= local_30) {
                    _memset((void *)(puVar9[2] + uVar1 * 4),0,(local_30 - uVar1) * 4 + 4);
                    puVar9[1] = local_30 + 1;
                  }
                  piVar7 = (int *)(puVar9[2] + local_30 * 4);
                }
                else {
                  piVar7 = (int *)FUN_001a7f7c(puVar9,local_30);
                }
                if (piVar5 == (int *)*piVar7) {
                  FUN_001a7f3c(puVar9,local_30);
                  iVar4 = FUN_0010b180(piVar5,piVar5[0x21]);
                  *(int *)(iVar4 + 0x160) = *(int *)(iVar4 + 0x160) + -1;
                  break;
                }
                local_30 = local_30 + 1;
              } while ((int)local_30 < (int)puVar9[1]);
            }
            FUN_0010ba02(piVar5,piVar5[0x21],0,1,uVar2);
            piVar5[0x21] = piVar5[0x21] + -1;
            piVar5[5] = piVar5[5] & 0xfffffdff;
            FUN_0010c18e(piVar5,uVar6,1,*(undefined4 *)(param_2 + 8));
            iVar4 = local_14;
            if (piVar5[0x21] == 0) {
              piVar5[0x27] = local_14;
              local_3c = local_3c - 1;
            }
            else {
              iVar8 = FUN_0010b0f4(piVar5,piVar5[0x21]);
              *(int *)(iVar8 + 0x10) = iVar4;
              local_3c = local_3c - 1;
            }
          }
        }
        if ((int)local_3c < 0) break;
        puVar9 = (uint *)param_1[4];
      } while( true );
    }
    iVar4 = FUN_00109e42(param_1,param_2);
    if (iVar4 == 0) {
      FUN_001a7d72(param_1);
      (**(code **)(*param_1 + 0xc))(param_1,1,*(undefined4 *)(param_2 + 8));
    }
  }
  return;
}

/* FUN_0019ac72 @ 0x19ac72 (2523 bytes) */
int FUN_0019ac72(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  code *pcVar8;
  undefined4 uVar9;
  uint uVar10;
  char cVar11;
  char cVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  int iVar18;
  int iVar19;
  undefined4 *puVar20;
  int iVar21;
  uint *puVar22;
  uint uVar23;
  int iVar24;
  int iVar25;
  int *local_d4;
  uint local_c8;
  undefined4 local_c4;
  int local_70;
  uint local_64;
  int local_5c;
  int local_54;
  int local_50;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  piVar13 = (int *)FUN_001a5af4(0,0,param_1,param_2);
  iVar3 = piVar13[0x22];
  if (((*(int *)(iVar3 + 8) != 0x24) && (*(int *)(iVar3 + 8) != 0x25)) &&
     (*(int *)(iVar3 + 8) != 0x26)) {
    return;
  }
  cVar11 = ((undefined4 (*)())FUN_00140e9c)(piVar13,2,0x3f800000);
  cVar12 = ((undefined4 (*)())FUN_00140e9c)(piVar13,2,0);
  if (cVar12 == '\0') {
    cVar12 = ((undefined4 (*)())FUN_00140e9c)(piVar13,3,0);
joined_r0x0019adf0:
    if (cVar12 == '\0') {
      return;
    }
    if (cVar11 == '\0') {
      return;
    }
  }
  else {
    cVar12 = ((undefined4 (*)())FUN_00140e9c)(piVar13,3,0x3f800000);
    if (cVar12 == '\0') {
      cVar12 = ((undefined4 (*)())FUN_00140e9c)(piVar13,3,0);
      goto joined_r0x0019adf0;
    }
  }
  if ((*(byte *)((int)piVar13 + 0x15) & 2) != 0) {
    return;
  }
  puVar22 = (uint *)piVar13[4];
  local_c8 = puVar22[1] - 1;
  if (-1 < (int)local_c8) {
    local_50 = local_c8 * 4;
    local_d4 = (int *)0x0;
    uVar23 = local_c8;
    do {
      if (uVar23 < *puVar22) {
        uVar10 = puVar22[1];
        if (uVar10 <= uVar23) {
          _memset((void *)(puVar22[2] + uVar10 * 4),0,(uVar23 - uVar10) * 4 + 4);
          puVar22[1] = uVar23 + 1;
        }
        piVar14 = (int *)(local_50 + puVar22[2]);
      }
      else {
        piVar14 = (int *)FUN_001a7f7c(puVar22,uVar23);
      }
      iVar3 = *piVar14;
      iVar21 = *(int *)(iVar3 + 0x88);
      piVar14 = local_d4;
      if (*(int *)(iVar21 + 8) != 0x13) {
        if (*(int *)(iVar21 + 8) == 0x14) {
          piVar15 = (int *)FUN_0010b180(iVar3,1);
          if ((piVar13 == piVar15) || (piVar15 = (int *)FUN_0010b180(iVar3,2), piVar13 == piVar15))
          goto LAB_0019ad90;
          iVar21 = *(int *)(*(int *)(iVar3 + 0x88) + 8);
        }
        else {
          iVar21 = *(int *)(iVar21 + 8);
        }
        if (iVar21 == 0x12) {
          piVar15 = (int *)FUN_0010b180(iVar3,1);
          piVar14 = (int *)FUN_0010b180(iVar3,2);
          if (piVar13 == piVar15) {
            if ((local_d4 != (int *)0x0) && (local_d4 != piVar14)) goto LAB_0019ae2b;
          }
          else {
            if (piVar13 != piVar14) {
              puVar22 = (uint *)piVar13[4];
              break;
            }
            piVar14 = piVar15;
            if ((local_d4 != (int *)0x0) && (local_d4 != piVar15)) {
              puVar22 = (uint *)piVar13[4];
              break;
            }
          }
        }
      }
LAB_0019ad90:
      local_d4 = piVar14;
      uVar23 = uVar23 - 1;
      local_50 = local_50 + -4;
      if (uVar23 == 0xffffffff) goto LAB_0019ae2b;
      puVar22 = (uint *)piVar13[4];
    } while( true );
  }
LAB_0019ae31:
  iVar3 = *(int *)(param_2 + 0x46c);
  if (-1 < (int)local_c8) {
    local_54 = local_c8 * 4;
    do {
      if (local_c8 < *puVar22) {
        uVar23 = puVar22[1];
        if (uVar23 <= local_c8) {
          _memset((void *)(puVar22[2] + uVar23 * 4),0,(local_c8 - uVar23) * 4 + 4);
          puVar22[1] = local_c8 + 1;
        }
        iVar21 = *(int *)(local_54 + puVar22[2]);
        iVar25 = *(int *)(*(int *)(iVar21 + 0x88) + 8);
      }
      else {
        piVar14 = (int *)FUN_001a7f7c(puVar22,local_c8);
        iVar21 = *piVar14;
        iVar25 = *(int *)(*(int *)(iVar21 + 0x88) + 8);
      }
      if (iVar25 == 0x13) {
        piVar14 = (int *)FUN_0010b180(iVar21,1);
        if (piVar13 == piVar14) {
          local_c4 = 1;
          iVar25 = 2;
        }
        else {
          piVar14 = (int *)FUN_0010b180(iVar21,2);
          if (piVar13 != piVar14) {
            if ((*(byte *)(iVar21 + 0x15) & 2) != 0) {
              FUN_0010b180(iVar21,*(undefined4 *)(iVar21 + 0x84));
            }
            goto LAB_0019ae82;
          }
          local_c4 = 2;
          iVar25 = 1;
        }
        *(int *)(param_2 + 500) = *(int *)(param_2 + 500) + 1;
        FUN_001a7f3c(piVar13[4],local_c8);
        piVar13[0x58] = piVar13[0x58] + -1;
        local_38 = 0;
        local_34 = 0;
        local_24 = 0;
        uVar16 = FUN_0010b0f4(iVar21,0);
        FUN_0010a40a(&local_38,uVar16);
        uVar17 = FUN_0010b180(iVar21,iVar25);
        FUN_0010ba02(iVar21,iVar25,0,1,*(undefined4 *)(param_2 + 8));
        iVar18 = FUN_0010b0f4(iVar21,iVar25);
        iVar18 = *(int *)(iVar18 + 0x10);
        iVar19 = FUN_0010b0f4(iVar21,local_c4);
        local_20[0] = *(undefined4 *)(iVar19 + 0x10);
        uVar23 = *(uint *)(iVar21 + 0xa0 + iVar25 * 0x18);
        iVar25 = piVar13[1];
        uVar16 = *(undefined4 *)(iVar21 + 8);
        iVar19 = piVar13[0x56];
        uVar4 = *(undefined4 *)(iVar21 + 0x158);
        iVar5 = *(int *)(iVar21 + 0x10);
        FUN_001a7d72(piVar13);
        FUN_001a7d72(iVar21);
        iVar6 = *(int *)(iVar21 + 0x14c);
        uVar1 = *(undefined1 *)(iVar21 + 0x120);
        iVar7 = *(int *)(iVar21 + 0x124);
        if ((*(byte *)(iVar21 + 0x15) & 2) == 0) {
          local_70 = 0;
        }
        else {
          local_70 = FUN_0010b180(iVar21,*(undefined4 *)(iVar21 + 0x84));
          uVar9 = *(undefined4 *)(param_2 + 8);
          iVar24 = FUN_0010b180(iVar21,*(undefined4 *)(iVar21 + 0x84));
          puVar22 = *(uint **)(iVar24 + 0x10);
          if (0 < (int)puVar22[1]) {
            local_64 = 0;
            do {
              if (local_64 < *puVar22) {
                uVar10 = puVar22[1];
                if (uVar10 <= local_64) {
                  _memset((void *)(puVar22[2] + uVar10 * 4),0,(local_64 - uVar10) * 4 + 4);
                  puVar22[1] = local_64 + 1;
                }
                piVar14 = (int *)(puVar22[2] + local_64 * 4);
              }
              else {
                piVar14 = (int *)FUN_001a7f7c(puVar22,local_64);
              }
              if (iVar21 == *piVar14) {
                FUN_001a7f3c(puVar22,local_64);
                iVar24 = FUN_0010b180(iVar21,*(undefined4 *)(iVar21 + 0x84));
                *(int *)(iVar24 + 0x160) = *(int *)(iVar24 + 0x160) + -1;
                break;
              }
              local_64 = local_64 + 1;
            } while ((int)local_64 < (int)puVar22[1]);
          }
          FUN_0010ba02(iVar21,*(undefined4 *)(iVar21 + 0x84),0,1,uVar9);
          *(int *)(iVar21 + 0x84) = *(int *)(iVar21 + 0x84) + -1;
          *(uint *)(iVar21 + 0x14) = *(uint *)(iVar21 + 0x14) & 0xfffffdff;
        }
        iVar24 = *(int *)(iVar21 + 0x160) - iVar3;
        if (iVar24 < 0) {
          iVar24 = 0;
        }
        piVar14 = (int *)FUN_00109cd4(piVar13,iVar21,*(undefined4 *)(param_2 + 8),1);
        iVar21 = ~-(uint)(cVar11 == '\0') + 3;
        FUN_0010bc9c(piVar14,0,&local_38,*(undefined4 *)(param_2 + 8));
        piVar14[0x53] = iVar6;
        FUN_000e9596(iVar19,iVar25,piVar13);
        FUN_000e956e(uVar4,uVar16,piVar14);
        *(undefined1 *)(piVar14 + 0x48) = uVar1;
        piVar14[0x49] = iVar7;
        if (local_70 != 0) {
          FUN_0010c18e(piVar14,local_70,1,*(undefined4 *)(param_2 + 8));
        }
        piVar14[4] = iVar5;
        FUN_0010ba02(piVar14,iVar21,uVar17,1,*(undefined4 *)(param_2 + 8));
        piVar14[0x58] = iVar3 + iVar24;
        if (iVar21 == 0) {
          piVar14[0x27] = iVar18;
        }
        else {
          iVar25 = FUN_0010b0f4(piVar14,iVar21);
          *(int *)(iVar25 + 0x10) = iVar18;
        }
        FUN_00109c0e(piVar14 + iVar21 * 6 + 0x23,2,(byte)(uVar23 >> 1) & 1);
        FUN_00109c0e(piVar14 + iVar21 * 6 + 0x23,1,(byte)uVar23 & 1);
        iVar25 = FUN_0010b180(piVar14,1);
        if (iVar3 < *(int *)(iVar25 + 0x160)) {
          *(int *)(iVar25 + 0x160) = *(int *)(iVar25 + 0x160) + 1;
        }
        else {
          *(int *)(iVar25 + 0x160) = iVar3 + 1;
        }
        puVar22 = *(uint **)(iVar25 + 0x10);
        uVar23 = puVar22[1];
        if (uVar23 < *puVar22) {
          _memset((void *)(uVar23 * 4 + puVar22[2]),0,4);
          puVar22[1] = uVar23 + 1;
          puVar20 = (undefined4 *)(uVar23 * 4 + puVar22[2]);
        }
        else {
          puVar20 = (undefined4 *)FUN_001a7f7c(puVar22,uVar23);
        }
        *puVar20 = piVar14;
        local_5c = 0;
        do {
          bVar2 = *(byte *)((int)local_20 + local_5c);
          iVar25 = FUN_0010b0f4(piVar14,0);
          uVar23 = 4;
          if (*(char *)(local_5c + 0x10 + iVar25) != '\x01') {
            uVar23 = (uint)bVar2;
          }
          iVar18 = 1;
          iVar25 = (**(code **)(*piVar14 + 0x14))(piVar14);
          if (0 < iVar25) {
            do {
              if (iVar21 != iVar18) {
                if (uVar23 == 4) {
                  (**(code **)(*piVar14 + 0x88))(piVar14,iVar18,local_5c,4);
                }
                else {
                  pcVar8 = *(code **)(*piVar14 + 0x88);
                  iVar25 = FUN_0010b0f4(piVar13,iVar18);
                  (*pcVar8)(piVar14,iVar18,local_5c,*(undefined1 *)(uVar23 + 0x10 + iVar25));
                }
              }
              iVar18 = iVar18 + 1;
              iVar25 = (**(code **)(*piVar14 + 0x14))(piVar14);
            } while (iVar18 <= iVar25);
          }
          local_5c = local_5c + 1;
        } while (local_5c != 4);
      }
LAB_0019ae82:
      local_c8 = local_c8 - 1;
      local_54 = local_54 + -4;
      if (local_c8 == 0xffffffff) goto LAB_0019af53;
      puVar22 = (uint *)piVar13[4];
    } while( true );
  }
LAB_0019af59:
  if (puVar22[1] != 0) {
    return;
  }
  (**(code **)(*piVar13 + 0xc))(piVar13,1,*(undefined4 *)(param_2 + 8));
  return;
LAB_0019ae2b:
  puVar22 = (uint *)piVar13[4];
  goto LAB_0019ae31;
LAB_0019af53:
  puVar22 = (uint *)piVar13[4];
  goto LAB_0019af59;
}

/* FUN_0019b64e @ 0x19b64e (226 bytes) */
int FUN_0019b64e(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  char cVar1;
  
  if ((*(byte *)(param_2 + 0x14) & 1) != 0) {
    ((int (*)())FUN_0019ac72)(param_2,param_3);
    cVar1 = FUN_000e1402(*(undefined4 *)(param_3 + 8),0x36);
    if ((cVar1 != '\0') && (((int (*)())FUN_001974ee)(param_2,param_3), (*(byte *)(param_2 + 0x14) & 1) == 0)) {
      return;
    }
    cVar1 = FUN_000e1402(*(undefined4 *)(param_3 + 8),0x15);
    if (cVar1 != '\0') {
      FUN_0015e16c(param_2,param_3);
      FUN_0015b45c(param_2,param_3);
    }
    cVar1 = FUN_000e1402(*(undefined4 *)(param_3 + 8),0x16);
    if ((cVar1 != '\0') && (cVar1 = FUN_0010a62e(param_2,param_3), cVar1 == '\0')) {
      FUN_0016c7ac(param_2,param_3);
    }
    cVar1 = FUN_000e1402(*(undefined4 *)(param_3 + 8),0x14);
    if (cVar1 != '\0') {
      ((int (*)())FUN_0019a70a)();
      return;
    }
  }
  return;
}

/* FUN_0019b730 @ 0x19b730 (1429 bytes) */
int FUN_0019b730(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  undefined1 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  char cVar11;
  int iVar12;
  int *piVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  undefined4 uVar17;
  undefined4 local_cc;
  int *local_c8;
  int local_b0;
  
  iVar12 = FUN_0010b0f4(param_1,1);
  uVar17 = *(undefined4 *)(iVar12 + 0x10);
  iVar12 = FUN_0010b0f4(param_1,2);
  local_cc = *(undefined4 *)(iVar12 + 0x10);
  iVar12 = FUN_0010b0f4(param_1,0);
  uVar2 = *(undefined4 *)(iVar12 + 0x10);
  if (*(int *)(*(int *)(param_1 + 0x88) + 8) != 0x12) {
    return;
  }
  cVar11 = FUN_000f5672(uVar17);
  if (cVar11 == '\0') {
    return;
  }
  cVar11 = FUN_000f5672(local_cc);
  if (cVar11 == '\0') {
    return;
  }
  local_c8 = (int *)FUN_0010b180(param_1,1);
  piVar13 = (int *)FUN_0010b180(param_1,2);
  if ((((*(int *)(local_c8[0x22] + 8) == 0x1c) &&
       (cVar11 = FUN_0010a62e(local_c8,param_2), cVar11 != '\0')) &&
      ((*(uint *)(param_1 + 0xb8) & 1) == 0)) &&
     (((*(uint *)(param_1 + 0xb8) & 2) == 0 &&
      (cVar11 = FUN_0014fc32(local_c8,param_2), cVar11 != '\0')))) {
    iVar12 = 2;
  }
  else {
    if (*(int *)(piVar13[0x22] + 8) != 0x1c) {
      return;
    }
    cVar11 = FUN_0010a62e(piVar13,param_2);
    if (cVar11 == '\0') {
      return;
    }
    if ((*(uint *)(param_1 + 0xd0) & 1) != 0) {
      return;
    }
    if ((*(uint *)(param_1 + 0xd0) & 2) != 0) {
      return;
    }
    cVar11 = FUN_0014fc32(piVar13,param_2);
    if (cVar11 == '\0') {
      return;
    }
    iVar12 = 1;
    local_cc = uVar17;
    local_c8 = piVar13;
  }
  uVar14 = FUN_0010b180(param_1,iVar12);
  uVar3 = *(uint *)(param_1 + 0xa0 + iVar12 * 0x18);
  iVar12 = FUN_0010b0f4(param_1,iVar12);
  uVar17 = *(undefined4 *)(iVar12 + 0x10);
  uVar15 = FUN_0010b180(local_c8,1);
  uVar4 = local_c8[0x2e];
  iVar12 = FUN_0010b0f4(local_c8,1);
  uVar5 = *(undefined4 *)(iVar12 + 0x10);
  uVar16 = FUN_0010b180(local_c8,2);
  uVar6 = local_c8[0x34];
  iVar12 = FUN_0010b0f4(local_c8,2);
  uVar7 = *(undefined4 *)(iVar12 + 0x10);
  uVar8 = *(undefined4 *)(param_1 + 4);
  uVar9 = *(undefined4 *)(param_1 + 0x158);
  iVar12 = FUN_00109e42(param_1,param_2);
  uVar1 = *(undefined1 *)(param_1 + 0x120);
  uVar10 = *(undefined4 *)(param_1 + 0x124);
  if ((*(byte *)(param_1 + 0x15) & 2) == 0) {
    local_b0 = 0;
  }
  else {
    local_b0 = FUN_0010b180(param_1,*(undefined4 *)(param_1 + 0x84));
  }
  FUN_001a7d72(param_1);
  FUN_0010da48(param_1,0xa3,param_3);
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x14c);
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = uVar2;
  *(undefined1 *)(param_1 + 0x120) = uVar1;
  *(undefined4 *)(param_1 + 0x124) = uVar10;
  *(int *)(param_1 + 0x160) = iVar12 + *(int *)(param_2 + 0x46c);
  if (local_b0 != 0) {
    FUN_0010c18e(param_1,local_b0,0,param_3);
  }
  FUN_000e9596(uVar9,uVar8,param_1);
  FUN_0010ba02(param_1,1,uVar15,0,*(undefined4 *)(param_2 + 8));
  FUN_00109c0e(param_1 + 0xa4,1,(byte)uVar4 & 1);
  FUN_00109c0e(param_1 + 0xa4,2,(byte)(uVar4 >> 1) & 1);
  iVar12 = FUN_0010b0f4(param_1,1);
  *(undefined4 *)(iVar12 + 0x10) = uVar5;
  FUN_0010ba02(param_1,2,uVar16,0,*(undefined4 *)(param_2 + 8));
  FUN_00109c0e(param_1 + 0xbc,1,(byte)uVar6 & 1);
  FUN_00109c0e(param_1 + 0xbc,2,(byte)(uVar6 >> 1) & 1);
  iVar12 = FUN_0010b0f4(param_1,2);
  *(undefined4 *)(iVar12 + 0x10) = uVar7;
  FUN_0010ba02(param_1,3,uVar14,0,*(undefined4 *)(param_2 + 8));
  FUN_00109c0e(param_1 + 0xd4,1,(byte)uVar3 & 1);
  FUN_00109c0e(param_1 + 0xd4,2,(byte)(uVar3 >> 1) & 1);
  iVar12 = FUN_0010b0f4(param_1,3);
  *(undefined4 *)(iVar12 + 0x10) = uVar17;
  uVar17 = FUN_000f5c30(local_cc);
  iVar12 = FUN_0010b0f4(param_1,3);
  *(undefined4 *)(iVar12 + 0x10) = uVar17;
                    
                    
  (**(code **)(*local_c8 + 0xc))();
  return;
}

/* FUN_0019bcce @ 0x19bcce (1732 bytes) */
int FUN_0019bcce(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int *param_4;
  int param_5;
{
  char cVar1;
  int iVar2;
  undefined1 local_1d;
  undefined1 local_d;
  
  local_d = 0;
  cVar1 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x1b);
  if (cVar1 == '\0') {
    local_1d = 0;
  }
  else {
    local_1d = (**(code **)(*param_4 + 100))(param_4);
    cVar1 = FUN_00156a28(param_4,param_5,&local_d);
    if ((cVar1 != '\0') &&
       (param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4), param_4 == (int *)0x0)) {
      return 1;
    }
    if (((param_2 != 0) &&
        (cVar1 = FUN_00155bf2(param_2,param_3,param_4,param_5,&local_d), cVar1 != '\0')) &&
       (param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4), param_4 == (int *)0x0)) {
      return 1;
    }
  }
  cVar1 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x1c);
  if (cVar1 == '\0') goto LAB_0019bebc;
  cVar1 = FUN_0016502e(param_4,param_5);
  if ((cVar1 != '\0') &&
     (param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4), param_4 == (int *)0x0)) {
    return 1;
  }
  cVar1 = FUN_00164f1e(param_4,param_5);
  if ((cVar1 != '\0') &&
     (param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4), param_4 == (int *)0x0)) {
    return 1;
  }
  iVar2 = (**(code **)(*param_4 + 0x14))(param_4);
  if ((param_3 <= iVar2) && (cVar1 = FUN_00169a44(param_2,param_3,param_4,param_5), cVar1 != '\0'))
  {
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    if (param_4 == (int *)0x0) {
      return 1;
    }
    local_1d = 1;
  }
  cVar1 = FUN_00165e96(param_4,param_5);
  if (cVar1 != '\0') {
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
  }
  cVar1 = FUN_001582e0(param_4,param_5);
  if (cVar1 == '\0') {
    cVar1 = FUN_00159396(param_4,param_5);
    if (cVar1 == '\0') goto LAB_0019bdf4;
LAB_0019c213:
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    cVar1 = FUN_0015a444(param_4,param_5);
    if (cVar1 != '\0') goto LAB_0019c23f;
LAB_0019be0b:
    cVar1 = FUN_0015e33a(param_4,param_5);
    if (cVar1 == '\0') goto LAB_0019be22;
LAB_0019c26b:
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    cVar1 = FUN_00159804(param_4,param_5);
    if (cVar1 != '\0') goto LAB_0019c297;
LAB_0019be39:
    cVar1 = FUN_00172f94(param_4,param_5);
    if (cVar1 == '\0') goto LAB_0019be50;
LAB_0019c2c3:
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    cVar1 = FUN_001735e0(param_4,param_5);
    if (cVar1 != '\0') goto LAB_0019c2ef;
LAB_0019be67:
    cVar1 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x3c);
  }
  else {
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    cVar1 = FUN_00159396(param_4,param_5);
    if (cVar1 != '\0') goto LAB_0019c213;
LAB_0019bdf4:
    cVar1 = FUN_0015a444(param_4,param_5);
    if (cVar1 == '\0') goto LAB_0019be0b;
LAB_0019c23f:
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    cVar1 = FUN_0015e33a(param_4,param_5);
    if (cVar1 != '\0') goto LAB_0019c26b;
LAB_0019be22:
    cVar1 = FUN_00159804(param_4,param_5);
    if (cVar1 == '\0') goto LAB_0019be39;
LAB_0019c297:
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    cVar1 = FUN_00172f94(param_4,param_5);
    if (cVar1 != '\0') goto LAB_0019c2c3;
LAB_0019be50:
    cVar1 = FUN_001735e0(param_4,param_5);
    if (cVar1 == '\0') goto LAB_0019be67;
LAB_0019c2ef:
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    cVar1 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x3c);
  }
  if ((cVar1 != '\0') && (cVar1 = FUN_0016dc48(param_2,param_3,param_4,param_5), cVar1 != '\0')) {
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
  }
  cVar1 = FUN_00159c72(param_4,param_5);
  if (cVar1 != '\0') {
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
  }
  cVar1 = FUN_0016a5c0(param_4,param_5);
  if (cVar1 != '\0') {
    local_1d = 1;
  }
LAB_0019bebc:
  cVar1 = FUN_00165812(param_2,param_3,param_4,param_5);
  if (cVar1 != '\0') {
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    local_1d = 1;
  }
  cVar1 = FUN_00165a1c(param_2,param_3,param_4,param_5);
  if (cVar1 != '\0') {
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    local_1d = 1;
  }
  cVar1 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x1d);
  if (((((cVar1 != '\0') && (cVar1 = FUN_00167f9e(param_4,param_5), cVar1 != '\0')) &&
       (cVar1 = (**(code **)(*param_4 + 100))(param_4), cVar1 != '\0')) &&
      ((param_2 != 0 &&
       (cVar1 = FUN_00155bf2(param_2,param_3,param_4,param_5,&local_d), cVar1 != '\0')))) &&
     (param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4), param_4 == (int *)0x0)) {
    return 1;
  }
  cVar1 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x39);
  if (cVar1 == '\0') {
    cVar1 = FUN_0016b7fa(param_4,1,param_5);
  }
  else {
    ((int (*)())FUN_00197636)(param_4,*(undefined4 *)(param_5 + 8));
    cVar1 = FUN_0016b7fa(param_4,1,param_5);
  }
  if (cVar1 != '\0') {
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
  }
  cVar1 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x39);
  if ((cVar1 != '\0') &&
     (cVar1 = ((int (*)())FUN_00199430)(param_2,param_3,param_4,param_5,*(undefined4 *)(param_5 + 8)),
     cVar1 != '\0')) {
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    local_1d = 1;
  }
  cVar1 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x3b);
  if (cVar1 != '\0') {
    if ((*(byte *)(param_4 + 5) & 1) != 0) {
      ((int (*)())FUN_0019b730)(param_4,param_5,*(undefined4 *)(param_5 + 8));
      return local_1d;
    }
    return local_1d;
  }
  return local_1d;
}

/* FUN_0019c392 @ 0x19c392 (155 bytes) */
int FUN_0019c392(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined1 local_d;
  
  piVar4 = *(int **)(param_2 + 0x378);
  iVar3 = piVar4[2];
  while (iVar3 != 0) {
    cVar1 = (**(code **)(*piVar4 + 0x24))(piVar4);
    if (cVar1 != '\0') {
      iVar3 = piVar4[0x4b];
      iVar2 = FUN_001a7d8a(iVar3 + 0x90);
      if ((((iVar2 < 3) && (iVar2 = FUN_000e97aa(iVar3), iVar2 == 1)) &&
          (iVar3 = FUN_000eac7c(iVar3,0), iVar3 == piVar4[0x4d])) &&
         (cVar1 = FUN_000ea2e0(piVar4,&local_d), cVar1 == '\0')) {
        piVar4 = (int *)FUN_00131fa6(param_2,piVar4);
      }
    }
    piVar4 = (int *)piVar4[2];
    iVar3 = piVar4[2];
  }
  return;
}

/* FUN_0019c42e @ 0x19c42e (1474 bytes) */
int FUN_0019c42e(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  int *param_4;
  int param_5;
{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined1 local_1d;
  undefined1 local_d;
  
  local_d = 0;
  cVar2 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x1b);
  if (cVar2 == '\0') {
    local_1d = 0;
  }
  else {
    local_1d = (**(code **)(*param_4 + 100))(param_4);
    cVar2 = FUN_00156a28(param_4,param_5,&local_d);
    if ((cVar2 != '\0') &&
       (param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4), param_4 == (int *)0x0)) {
      return 1;
    }
    if (((param_2 != 0) &&
        (cVar2 = FUN_00155bf2(param_2,param_3,param_4,param_5,&local_d), cVar2 != '\0')) &&
       (param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4), param_4 == (int *)0x0)) {
      return 1;
    }
  }
  cVar2 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x1c);
  if (cVar2 != '\0') {
    piVar1 = *(int **)(*(int *)(param_5 + 8) + 0x54);
    cVar2 = (**(code **)(*piVar1 + 0x84))(piVar1);
    if (((cVar2 != '\0') && (cVar2 = FUN_0016502e(param_4,param_5), cVar2 != '\0')) &&
       (param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4), param_4 == (int *)0x0)) {
      return 1;
    }
    cVar2 = FUN_00164f1e(param_4,param_5);
    if ((cVar2 != '\0') &&
       (param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4), param_4 == (int *)0x0)) {
      return 1;
    }
    iVar3 = (**(code **)(*param_4 + 0x14))(param_4);
    if ((param_3 <= iVar3) && (cVar2 = FUN_00169a44(param_2,param_3,param_4,param_5), cVar2 != '\0')
       ) {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
      if (param_4 == (int *)0x0) {
        return 1;
      }
      local_1d = 1;
    }
    cVar2 = FUN_00165e96(param_4,param_5);
    if (cVar2 != '\0') {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    }
    cVar2 = FUN_001582e0(param_4,param_5);
    if (cVar2 != '\0') {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    }
    cVar2 = FUN_00157ac6(param_4,param_5,0,1);
    if (cVar2 != '\0') {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    }
    cVar2 = FUN_00157068(param_4,param_5);
    if (cVar2 != '\0') {
      cVar2 = (**(code **)(*param_4 + 100))(param_4);
      if (((cVar2 != '\0') && ((*(byte *)((int)param_4 + 0x15) & 2) == 0)) && (param_2 != 0)) {
        FUN_00155bf2(param_2,param_3,param_4,param_5,&local_d);
      }
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
      if (param_4 == (int *)0x0) {
        return 1;
      }
      local_1d = 1;
    }
    cVar2 = FUN_0015e33a(param_4,param_5);
    if (cVar2 != '\0') {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    }
    cVar2 = FUN_001718da(param_4,param_5);
    if (cVar2 != '\0') {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    }
    cVar2 = FUN_0016f114(param_4,param_5);
    if (cVar2 != '\0') {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    }
    cVar2 = FUN_0016fdba(param_4,param_5);
    if (cVar2 != '\0') {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    }
    cVar2 = FUN_0017102e(param_4,param_5);
    if (cVar2 != '\0') {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    }
    cVar2 = FUN_00156ad8(param_4,param_5);
    if (cVar2 != '\0') {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    }
    cVar2 = FUN_001735e0(param_4,param_5);
    if (cVar2 != '\0') {
      param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
      cVar2 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x1d);
      goto joined_r0x0019c633;
    }
  }
  cVar2 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x1d);
joined_r0x0019c633:
  if ((((cVar2 != '\0') && (cVar2 = FUN_00167f9e(param_4,param_5), cVar2 != '\0')) &&
      ((cVar2 = (**(code **)(*param_4 + 100))(param_4), cVar2 != '\0' &&
       ((param_2 != 0 &&
        (cVar2 = FUN_00155bf2(param_2,param_3,param_4,param_5,&local_d), cVar2 != '\0')))))) &&
     (param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4), param_4 == (int *)0x0)) {
    return 1;
  }
  cVar2 = FUN_000e1402(*(undefined4 *)(param_5 + 8),0x3a);
  if (cVar2 == '\0') {
    return local_1d;
  }
  if ((*(int *)(param_5 + 0x228) < *(int *)(*(int *)(param_5 + 8) + 0x398)) &&
     (cVar2 = FUN_0015114e(param_2,param_3,param_4,param_5), cVar2 != '\0')) {
    param_4 = (int *)FUN_0014fb18(param_2,param_3,param_4);
    local_1d = 1;
  }
  cVar2 = FUN_00151c7c(param_2,param_3,param_4,param_5);
  if (cVar2 != '\0') {
    FUN_0014fb18(param_2,param_3,param_4);
    return 1;
  }
  return local_1d;
}

/* FUN_0019c9f0 @ 0x19c9f0 (79 bytes) */
int FUN_0019c9f0(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  char cVar1;
  
  if ((*(byte *)(param_2 + 0x14) & 1) != 0) {
    cVar1 = FUN_000e1402(*(undefined4 *)(param_3 + 8),0x15);
    if (cVar1 != '\0') {
      FUN_0015e16c(param_2,param_3);
      FUN_0015b45c();
      return;
    }
  }
  return;
}

/* FUN_0019ca40 @ 0x19ca40 (85 bytes) */
int FUN_0019ca40(param_1)
  undefined4 *param_1;
{
  int iVar1;
  undefined4 *puVar2;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  iVar1 = 3;
  puVar2 = param_1;
  do {
    puVar2[6] = 0;
    puVar2[9] = 0;
    *(undefined1 *)(param_1 + 0xc) = 0;
    puVar2 = puVar2 + 1;
    param_1 = (undefined4 *)((int)param_1 + 1);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

/* FUN_0019ca96 @ 0x19ca96 (103 bytes) */
int FUN_0019ca96(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int local_10;
  
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  local_10 = 3;
  puVar1 = param_1;
  puVar2 = param_2;
  do {
    param_1[6] = param_2[6];
    param_1[9] = param_2[9];
    *(undefined1 *)(puVar1 + 0xc) = *(undefined1 *)(puVar2 + 0xc);
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
    puVar2 = (undefined4 *)((int)puVar2 + 1);
    puVar1 = (undefined4 *)((int)puVar1 + 1);
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  return;
}

/* FUN_0019cafe @ 0x19cafe (60 bytes) */
int FUN_0019cafe(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x24) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  ((int (*)())FUN_0019ca40)();
  return;
}

/* FUN_0019cb3a @ 0x19cb3a (24 bytes) */
int FUN_0019cb3a(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  byte bVar1;
  
  bVar1 = (**(code **)(*param_2 + 0x30))(param_2);
  return bVar1 ^ 1;
}

/* FUN_0019cb52 @ 0x19cb52 (73 bytes) */
int FUN_0019cb52(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
  int *param_4;
  int *param_5;
{
  char cVar1;
  undefined1 uVar2;
  
  if (((param_5 != (int *)0x0) && (cVar1 = (**(code **)(*param_5 + 0x4c))(param_5), cVar1 != '\0'))
     && (*param_4 == 0x4030100)) {
    return 1;
  }
  uVar2 = (**(code **)(*param_1 + 0x100))(param_1,param_4);
  return uVar2;
}

/* FUN_0019cb9c @ 0x19cb9c (82 bytes) */
int FUN_0019cb9c(param_1)
  uint param_1;
{
  return *(int *)(&DAT_001cc7a4 +
                 ((param_1 & 0xff) * 0x7d + (param_1 >> 8 & 0xff) * 0x19 +
                  (param_1 >> 0x10 & 0xff) * 5 + (param_1 >> 0x18)) * 0x10) == DAT_001cf004;
}

/* FUN_0019cbee @ 0x19cbee (24 bytes) */
int FUN_0019cbee(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_0019cb9c)(*param_2);
  return uVar1;
}

/* FUN_0019cc06 @ 0x19cc06 (42 bytes) */
int FUN_0019cc06(param_1)
  undefined4 param_1;
{
  undefined1 uVar1;
  
  uVar1 = FUN_000f56f0(param_1,DAT_001cf000);
  return uVar1;
}

/* FUN_0019cc30 @ 0x19cc30 (76 bytes) */
int FUN_0019cc30(param_1)
  undefined4 param_1;
{
  char cVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_001cef20;
  do {
    cVar1 = FUN_000f56f0(*puVar2,param_1);
    if (cVar1 != '\0') {
      return 1;
    }
    puVar2 = puVar2 + 1;
  } while (puVar2 != (undefined4 *)&DAT_001cef70);
  return 0;
}

/* FUN_0019cc7c @ 0x19cc7c (24 bytes) */
int FUN_0019cc7c(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined1 uVar1;
  
  uVar1 = ((int (*)())FUN_0019cc30)(*param_2);
  return uVar1;
}

/* FUN_0019cc94 @ 0x19cc94 (5 bytes) */
int FUN_0019cc94()
{
  return;
}

/* FUN_0019cc9a @ 0x19cc9a (52 bytes) */
int FUN_0019cc9a(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = FUN_0010b180(param_1,param_2);
  if (*(int *)(iVar1 + 0x98) != 0x33) {
    return false;
  }
  return *(int *)(iVar1 + 300) != 3;
}

