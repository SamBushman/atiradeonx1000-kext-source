#include "decls.h"

/* FUN_00182f04 @ 0x182f04 (45 bytes) */
int FUN_00182f04(param_1)
  int param_1;
{
  return *(int *)(param_1 + 4) % 0x65;
}

/* FUN_00182f32 @ 0x182f32 (26 bytes) */
int FUN_00182f32(param_1, param_2)
  int param_1;
  int param_2;
{
  return (*(int *)(param_1 + 4) == *(int *)(param_2 + 4)) - 1;
}

/* FUN_00182f4c @ 0x182f4c (50 bytes) */
int FUN_00182f4c(param_1)
  int *param_1;
{
  return (*param_1 * 0x25) % 0x65;
}

/* FUN_00182f7e @ 0x182f7e (24 bytes) */
int FUN_00182f7e(param_1, param_2)
  int *param_1;
  int *param_2;
{
  return (*param_1 == *param_2) - 1;
}

/* FUN_00182f96 @ 0x182f96 (44 bytes) */
int FUN_00182f96(param_1)
  int *param_1;
{
  return *param_1 % 0x65;
}

/* FUN_00182fc2 @ 0x182fc2 (34 bytes) */
int FUN_00182fc2(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  char cVar1;
  
  cVar1 = FUN_00186a7c(*param_1,*param_2);
  return -(uint)(cVar1 == '\0');
}

/* FUN_00182fe4 @ 0x182fe4 (54 bytes) */
int FUN_00182fe4(param_1)
  int param_1;
{
  return *(uint *)(*(int *)(param_1 + 4) + 0xb4) % 0x65;
}

/* FUN_0018301a @ 0x18301a (337 bytes) */
int FUN_0018301a(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  
  iVar6 = *(int *)(param_1 + 4);
  local_14 = iVar6 + 0xb4;
  iVar5 = *(int *)(param_2 + 4);
  local_10 = iVar5 + 0xb4;
  iVar4 = *(int *)(param_1 + 8);
  iVar3 = *(int *)(param_2 + 8);
  piVar1 = *(int **)(iVar6 + 0xb0);
  cVar2 = FUN_001195a6(*(undefined4 *)(iVar6 + 0x238),piVar1);
  if ((((cVar2 != '\0') && (*(int *)(iVar6 + 0xb4) == *(int *)(iVar5 + 0xb4))) &&
      (*(int *)(iVar6 + 0xc0) == *(int *)(iVar5 + 0xc0))) &&
     (*(int *)(iVar6 + 0xc4) == *(int *)(iVar5 + 0xc4))) {
    iVar4 = iVar4 * 4;
    iVar3 = iVar3 * 4;
    iVar6 = iVar3 + 0xb4 + local_10;
    iVar5 = iVar4 + 0xb4 + local_14;
    local_20 = 1;
    local_1c = iVar4 + 0x14 + local_14;
    local_18 = iVar3 + 0x14 + local_10;
    while( true ) {
      iVar4 = (**(code **)(*piVar1 + 0x14))(piVar1);
      if (iVar4 < local_20) {
        return 0;
      }
      cVar2 = FUN_00186a7c(*(undefined4 *)(iVar5 + 0x10),*(undefined4 *)(iVar6 + 0x10));
      if (((cVar2 == '\0') || (*(int *)(local_14 + 0x108) != *(int *)(local_10 + 0x108))) ||
         (*(int *)(local_1c + 0x20) != *(int *)(local_18 + 0x20))) break;
      local_14 = local_14 + 4;
      local_10 = local_10 + 4;
      iVar6 = iVar6 + 0x10;
      iVar5 = iVar5 + 0x10;
      if (*(int *)(local_1c + 0x30) != *(int *)(local_18 + 0x30)) {
        return 0xffffffff;
      }
      local_20 = local_20 + 1;
      local_1c = local_1c + 0x20;
      local_18 = local_18 + 0x20;
    }
  }
  return 0xffffffff;
}

/* FUN_0018316c @ 0x18316c (139 bytes) */
int FUN_0018316c(param_1)
  int param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 1;
  iVar4 = 0;
  iVar1 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0));
  if (0 < iVar1) {
    do {
      piVar2 = (int *)(iVar4 * 0x10 + 0x168 + param_1);
      iVar1 = 4;
      do {
        iVar3 = iVar3 * *piVar2;
        piVar2 = piVar2 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      iVar4 = iVar4 + 1;
      iVar1 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0));
    } while (iVar4 < iVar1);
  }
  return (iVar3 + *(int *)(param_1 + 0xb4)) % 0x65;
}

/* FUN_001831f8 @ 0x1831f8 (75 bytes) */
int FUN_001831f8(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  bool bVar6;
  
  bVar6 = (char *)(param_2 + 0xb4) == (char *)0x0;
  iVar1 = 0x15c;
  pcVar2 = (char *)(param_1 + 0xb4);
  pcVar4 = (char *)(param_2 + 0xb4);
  do {
    pcVar3 = pcVar2;
    pcVar5 = pcVar4;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    pcVar5 = pcVar4 + 1;
    pcVar3 = pcVar2 + 1;
    bVar6 = *pcVar2 == *pcVar4;
    pcVar2 = pcVar3;
    pcVar4 = pcVar5;
  } while (bVar6);
  iVar1 = 0;
  if (!bVar6) {
    iVar1 = (uint)(byte)pcVar3[-1] - (uint)(byte)pcVar5[-1];
  }
  return ~-(uint)(iVar1 == 0);
}

/* FUN_00183244 @ 0x183244 (7 bytes) */
int FUN_00183244()
{
  return 0;
}

/* FUN_0018324c @ 0x18324c (98 bytes) */
int FUN_0018324c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 4;
  iVar1 = param_1;
  iVar2 = param_2;
  while( true ) {
    if (((*(int *)(iVar1 + 0x20) != *(int *)(iVar2 + 0x20)) && (*(int *)(iVar1 + 0x20) != 3)) &&
       (*(int *)(iVar2 + 0x20) != 3)) break;
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + -1;
    if (iVar3 == 0) {
      iVar1 = 2;
      do {
        if (*(int *)(param_1 + 0xb8) != *(int *)(param_2 + 0xb8)) {
          return 0xffffffff;
        }
        param_1 = param_1 + 4;
        param_2 = param_2 + 4;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
      return 0;
    }
  }
  return 0xffffffff;
}

/* FUN_001832ae @ 0x1832ae (81 bytes) */
int FUN_001832ae(param_1)
  int param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  iVar2 = 1;
  do {
    uVar1 = *(uint *)(param_1 + 0x1c + iVar2 * 4);
    if (0x7fffffff < uVar1) {
      uVar1 = -uVar1;
    }
    if ((int)uVar3 < (int)uVar1) {
      uVar3 = uVar1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 != 5);
  return (int)uVar3 % 0x65;
}

/* FUN_00183300 @ 0x183300 (23 bytes) */
int FUN_00183300(param_1)
  int param_1;
{
  *(int *)(param_1 + 0x10c) = *(int *)(param_1 + 0x10c) + 1;
  return;
}

/* FUN_00183318 @ 0x183318 (23 bytes) */
int FUN_00183318(param_1)
  int param_1;
{
  *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x110) + -1;
  return;
}

/* FUN_00183330 @ 0x183330 (14 bytes) */
int FUN_00183330(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x10c);
}

/* FUN_0018333e @ 0x18333e (14 bytes) */
int FUN_0018333e(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x110);
}

/* FUN_0018334c @ 0x18334c (28 bytes) */
int FUN_0018334c(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x10c) = 4;
  *(undefined4 *)(param_1 + 0x110) = 0xfffffffe;
  return;
}

/* FUN_00183368 @ 0x183368 (5 bytes) */
int FUN_00183368()
{
  return;
}

/* FUN_0018336e @ 0x18336e (7 bytes) */
int FUN_0018336e()
{
  return 0;
}

/* FUN_00183376 @ 0x183376 (5 bytes) */
int FUN_00183376()
{
  return;
}

/* FUN_0018337c @ 0x18337c (5 bytes) */
int FUN_0018337c()
{
  return;
}

/* FUN_00183382 @ 0x183382 (88 bytes) */
int FUN_00183382(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = param_1;
  do {
    iVar2 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    cVar1 = *(char *)(iVar4 + 0x10 + iVar2);
    if (cVar1 == '\0') {
      *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar3 + 0x178);
    }
    else if (cVar1 == '\x01') {
      *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar3 + 0x10);
    }
    iVar4 = iVar4 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar4 != 4);
  return;
}

/* FUN_001833da @ 0x1833da (5 bytes) */
int FUN_001833da()
{
  return;
}

/* FUN_001833e0 @ 0x1833e0 (5 bytes) */
int FUN_001833e0()
{
  return;
}

/* FUN_001833e6 @ 0x1833e6 (62 bytes) */
int FUN_001833e6(param_1)
  int param_1;
{
  char cVar1;
  
  cVar1 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x54))(*(int **)(param_1 + 0xb0));
  if ((cVar1 != '\0') && (*(int *)(*(int *)(param_1 + 0xb0) + 0xb0) == 0x2a)) {
    return 1;
  }
  return 0;
}

/* FUN_00183424 @ 0x183424 (341 bytes) */
int FUN_00183424(param_1)
  int param_1;
{
  int *piVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_30;
  undefined4 local_20;
  
  piVar1 = (int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0xa8);
  *piVar1 = *piVar1 + 1;
  local_20 = DAT_001cc71c;
  local_30 = param_1;
  iVar7 = 1;
  do {
    if (*(int *)(param_1 + 0x20) == *(int *)(local_30 + 0x24)) {
      uVar3 = 0;
    }
    else {
      iVar6 = 0;
      iVar5 = param_1;
      do {
        iVar6 = iVar6 + 1;
        if (iVar6 == iVar7) goto joined_r0x001834a2;
        piVar1 = (int *)(iVar5 + 0x24);
        iVar5 = iVar5 + 4;
      } while (*piVar1 != *(int *)(local_30 + 0x24));
      uVar3 = (undefined1)iVar6;
    }
    *(undefined1 *)((int)&local_20 + iVar7) = uVar3;
    *(undefined1 *)(iVar7 + 0x9c + *(int *)(param_1 + 0xb0)) = 1;
joined_r0x001834a2:
    do {
      iVar7 = iVar7 + 1;
      if (iVar7 == 4) {
        uVar4 = FUN_0010dbb8(0x31,*(undefined4 *)(param_1 + 0x238));
        FUN_0010a3c2(uVar4,0,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c));
        FUN_0010a3c2(uVar4,1,*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x8c));
        uVar2 = local_20;
        iVar7 = FUN_0010b0f4(uVar4,1);
        *(undefined4 *)(iVar7 + 0x10) = uVar2;
        FUN_000e9596(*(undefined4 *)(*(int *)(param_1 + 0xb0) + 0x158),*(int *)(param_1 + 0xb0),
                     uVar4);
        FUN_000f0144(*(undefined4 *)(*(int *)(param_1 + 0x238) + 0x3f4),uVar4);
        return 1;
      }
      local_30 = local_30 + 4;
    } while (iVar7 < 1);
  } while( true );
}

/* FUN_0018357a @ 0x18357a (130 bytes) */
int FUN_0018357a(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  undefined4 local_20 [4];
  
  local_20[0] = DAT_001cc718;
  iVar2 = 0;
  do {
    iVar1 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    if (*(char *)(iVar2 + 0x10 + iVar1) != '\x01') {
      iVar1 = 0;
      while (*(int *)(param_2 + 0x20 + iVar1 * 4) != *(int *)(param_1 + 0x20 + iVar2 * 4)) {
        iVar1 = iVar1 + 1;
        if (iVar1 == 4) {
          return DAT_001cc718;
        }
      }
      *(char *)((int)local_20 + iVar2) = (char)iVar1;
    }
    iVar2 = iVar2 + 1;
    if (iVar2 == 4) {
      return local_20[0];
    }
  } while( true );
}

/* FUN_001835fc @ 0x1835fc (51 bytes) */
int FUN_001835fc(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = ((int (*)())FUN_0018357a)(param_2,param_1);
  return (iVar1 != DAT_001cc718) - 1;
}

/* FUN_00183630 @ 0x183630 (144 bytes) */
int FUN_00183630(param_1)
  undefined4 *param_1;
{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar3 = param_1;
  do {
    iVar2 = FUN_0010b0f4(param_1[0x2c],0);
    cVar1 = *(char *)(iVar4 + 0x10 + iVar2);
    if (cVar1 == '\0') {
      puVar3[8] = *puVar3;
      puVar3[0x1c] = puVar3[0x14];
      puVar3[0x28] = puVar3[0x20];
    }
    else if (cVar1 == '\x01') {
      if ((*(byte *)(param_1[0x2c] + 0x15) & 2) == 0) {
        puVar3[8] = 2;
      }
      else {
        puVar3[8] = puVar3[4];
        puVar3[0x1c] = puVar3[0x18];
        puVar3[0x28] = puVar3[0x24];
      }
    }
    iVar4 = iVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar4 != 4);
  return;
}

/* FUN_001836c0 @ 0x1836c0 (46 bytes) */
int FUN_001836c0(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  **(undefined4 **)(param_1 + 0x138) = param_2;
  FUN_001a84b2(*(undefined4 *)(param_1 + 300),*(undefined4 *)(param_1 + 0x138));
  return;
}

/* FUN_001836ee @ 0x1836ee (59 bytes) */
int FUN_001836ee(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(*(int *)(param_1 + 0x134) + 4) = param_2;
  **(undefined4 **)(param_1 + 0x134) = 0x7ffffffe;
  FUN_001a84b2(*(undefined4 *)(param_1 + 0x124),*(undefined4 *)(param_1 + 0x134));
  return;
}

/* FUN_0018372a @ 0x18372a (149 bytes) */
int FUN_0018372a(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  cVar1 = FUN_00118f7a(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                       *(undefined4 *)(param_1 + 0x238));
  if (cVar1 != '\0') {
    iVar4 = 0;
    iVar2 = param_1;
    iVar3 = param_1;
    do {
      if (*(char *)(iVar2 + 0x228) != '\0') {
        if (*(int *)(iVar3 + 0x178) < *(int *)(iVar3 + 0x188)) {
          return 0;
        }
        if (*(int *)(iVar3 + 0x188) < *(int *)(iVar3 + 0x178)) {
          FUN_00182eca(*(undefined4 *)(param_1 + 0xb0),param_1 + 0x210,
                       *(undefined4 *)(param_1 + 0x238));
          return 1;
        }
      }
      iVar4 = iVar4 + 1;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 4;
    } while (iVar4 != 4);
  }
  return 0;
}

/* FUN_001837c0 @ 0x1837c0 (131 bytes) */
int FUN_001837c0(param_1)
  int param_1;
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = FUN_001190ce(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                       *(undefined4 *)(param_1 + 0x238));
  if (cVar1 == '\0') {
    iVar2 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0));
    if (iVar2 != 0) {
      iVar2 = 1;
      while( true ) {
        iVar3 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0));
        if (iVar3 < iVar2) {
          return 1;
        }
        cVar1 = FUN_00186bbc(param_1,iVar2);
        if (cVar1 == '\0') break;
        iVar2 = iVar2 + 1;
      }
    }
  }
  return 0;
}

/* FUN_00183844 @ 0x183844 (29 bytes) */
int FUN_00183844(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0x88) + 8) - 0x24U < 3;
}

/* FUN_00183862 @ 0x183862 (266 bytes) */
int FUN_00183862(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  byte bVar7;
  
  piVar2 = *(int **)(*(int *)(param_1 + 0xb0) + 0x8c);
  cVar6 = (**(code **)(*piVar2 + 0x18))(piVar2);
  if (cVar6 != '\0') {
    uVar3 = piVar2[7];
    iVar4 = *(int *)(param_2 + 0x120);
    iVar5 = *(int *)(param_1 + 0xb0);
    if ((((*(int *)(*(int *)(iVar5 + 0x88) + 8) == 0x12) && (*(char *)(iVar5 + 0x120) == '\0')) &&
        ((*(byte *)(iVar5 + 0x15) & 2) == 0)) &&
       (((*(byte *)(iVar5 + 0xb8) & 1) != 0 && ((*(byte *)(iVar5 + 0xd0) & 1) == 0)))) {
      piVar2 = (int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0xa8);
      *piVar2 = *piVar2 + 1;
      FUN_00109c0e(*(int *)(param_1 + 0xb0) + 0xa4,1,0);
      FUN_00109c0e(*(int *)(param_1 + 0xb0) + 0xbc,1,1);
      puVar1 = (uint *)(*(int *)(param_1 + 0xb0) + 0x14);
      *puVar1 = *puVar1 | 0x200000;
      puVar1 = (uint *)(iVar4 + 8 + (uVar3 >> 5) * 4);
      *puVar1 = *puVar1 | 1 << ((byte)uVar3 & 0x1f);
    }
    else {
      bVar7 = (byte)uVar3 & 0x1f;
      puVar1 = (uint *)(iVar4 + 8 + (uVar3 >> 5) * 4);
      *puVar1 = *puVar1 & (-2 << bVar7 | 0xfffffffeU >> 0x20 - bVar7);
    }
  }
  return;
}

/* FUN_0018396c @ 0x18396c (291 bytes) */
int FUN_0018396c(param_1)
  int param_1;
{
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xb0);
  if (*(int *)(*(int *)(iVar2 + 0x88) + 8) == 0x77) {
    iVar2 = FUN_0010b0f4(iVar2,0);
    if (*(int *)(iVar2 + 0x10) == DAT_001cc714) {
      puVar1 = (uint *)(*(int *)(param_1 + 0xb0) + 0x14);
      *puVar1 = *puVar1 & 0xfffffff7;
      (**(code **)(**(int **)(param_1 + 0xb0) + 0xc))
                (*(int **)(param_1 + 0xb0),0,*(undefined4 *)(param_1 + 0x238));
      puVar1 = (uint *)(*(int *)(param_1 + 0xb0) + 0x14);
      *puVar1 = *puVar1 | 0x400;
      return 1;
    }
    iVar2 = *(int *)(param_1 + 0xb0);
  }
  if ((((*(uint *)(iVar2 + 0x14) & 2) != 0) && (*(int *)(iVar2 + 0x98) == 0x3b)) &&
     (*(char *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0x334) == '\0')) {
    *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & 0xffffffef;
    iVar2 = *(int *)(param_1 + 0x238);
    if ((*(byte *)(*(int *)(iVar2 + 0x3f4) + 0x31) & 0x40) == 0) {
      FUN_000f1b60(*(undefined4 *)(iVar2 + 0x3f4),*(undefined4 *)(param_1 + 0xb0));
      iVar2 = *(int *)(param_1 + 0x238);
    }
    (**(code **)(**(int **)(param_1 + 0xb0) + 0xc))(*(int **)(param_1 + 0xb0),0,iVar2);
    puVar1 = (uint *)(*(int *)(param_1 + 0xb0) + 0x14);
    *puVar1 = *puVar1 | 0x400;
    return 1;
  }
  return 0;
}

/* FUN_00183a90 @ 0x183a90 (270 bytes) */
int FUN_00183a90(param_1, param_2)
  int param_1;
  int param_2;
{
  int *piVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  char cStack_25;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  cVar3 = FUN_000e1402(*(undefined4 *)(param_1 + 0x238),9);
  if (((cVar3 != '\0') &&
      (*(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0xa8) <
       *(int *)(*(int *)(param_1 + 0x238) + 0x38c))) &&
     (iVar2 = *(int *)(param_2 + 0xb0), (*(byte *)(iVar2 + 0x14) & 1) != 0)) {
    iVar4 = FUN_0010b0f4(iVar2,0);
    local_20[0] = *(undefined4 *)(iVar4 + 0x10);
    iVar4 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    local_24 = *(undefined4 *)(iVar4 + 0x10);
    iVar4 = 1;
    while (((&cStack_25)[iVar4] != '\0' || (*(char *)((int)local_20 + iVar4 + -1) != '\x01'))) {
      iVar4 = iVar4 + 1;
      if (iVar4 == 5) {
        piVar1 = (int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0xa8);
        *piVar1 = *piVar1 + 1;
        piVar1 = (int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0x140);
        *piVar1 = *piVar1 + 1;
        FUN_0018fb1c(param_1,iVar2,&DAT_001cc71c,0);
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_00183b9e @ 0x183b9e (179 bytes) */
int FUN_00183b9e(param_1)
  int param_1;
{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_10;
  
  piVar4 = *(int **)(param_1 + 0xb0);
  if (*(int *)(piVar4[0x22] + 8) == 0x8e) {
    uVar2 = (**(code **)(*piVar4 + 0x7c))(piVar4);
    cVar1 = FUN_0012526a(uVar2);
    if (cVar1 == '\0') {
      return;
    }
    piVar4 = *(int **)(param_1 + 0xb0);
  }
  local_10 = 1;
  iVar5 = param_1;
  while( true ) {
    iVar3 = (**(code **)(*piVar4 + 0x14))(piVar4);
    if (iVar3 < local_10) break;
    iVar3 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
    uVar2 = FUN_000f626e(*(undefined4 *)(param_1 + 0xb0),local_10,
                         *(undefined4 *)(*(int *)(param_1 + 0x238) + 0x3f4),
                         *(undefined4 *)(iVar3 + 0x10));
    *(undefined4 *)(iVar5 + 0x228) = uVar2;
    local_10 = local_10 + 1;
    piVar4 = *(int **)(param_1 + 0xb0);
    iVar5 = iVar5 + 4;
  }
  return;
}

/* FUN_00183c52 @ 0x183c52 (171 bytes) */
int FUN_00183c52(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  int iVar2;
  
  param_1[0x2c] = param_2;
  param_1[0x8e] = param_3;
  iVar2 = 4;
  puVar1 = param_1;
  do {
    puVar1[8] = 0;
    puVar1[4] = 0;
    *puVar1 = 0;
    puVar1[0x1c] = 0;
    puVar1[0x18] = 0;
    puVar1[0x14] = 0;
    puVar1[0x28] = 0;
    puVar1[0x24] = 0;
    puVar1[0x20] = 0;
    puVar1[0xc] = 0;
    puVar1[0x10] = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  _memset(param_1 + 0x2d,0,0x15c);
  ((int (*)())FUN_00183b9e)();
  return;
}

/* FUN_00183cfe @ 0x183cfe (171 bytes) */
int FUN_00183cfe(param_1, param_2, param_3)
  undefined4 *param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  int iVar2;
  
  param_1[0x2c] = param_2;
  param_1[0x8e] = param_3;
  iVar2 = 4;
  puVar1 = param_1;
  do {
    puVar1[8] = 0;
    puVar1[4] = 0;
    *puVar1 = 0;
    puVar1[0x1c] = 0;
    puVar1[0x18] = 0;
    puVar1[0x14] = 0;
    puVar1[0x28] = 0;
    puVar1[0x24] = 0;
    puVar1[0x20] = 0;
    puVar1[0xc] = 0;
    puVar1[0x10] = 0;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  _memset(param_1 + 0x2d,0,0x15c);
  ((int (*)())FUN_00183b9e)();
  return;
}

/* FUN_00183daa @ 0x183daa (121 bytes) */
int FUN_00183daa(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = FUN_001190ce(*(undefined4 *)(param_1[0x22] + 8),param_2);
  if (cVar1 == '\0') {
    iVar2 = (**(code **)(*param_1 + 0x14))(param_1);
    if (iVar2 != 0) {
      iVar2 = 1;
      while( true ) {
        iVar3 = (**(code **)(*param_1 + 0x14))(param_1);
        if (iVar3 < iVar2) {
          return 1;
        }
        iVar3 = FUN_0010b0f4(param_1,iVar2);
        cVar1 = FUN_000f5672(*(undefined4 *)(iVar3 + 0x10));
        if (cVar1 == '\0') break;
        iVar2 = iVar2 + 1;
      }
    }
  }
  return 0;
}

/* FUN_00183e24 @ 0x183e24 (142 bytes) */
int FUN_00183e24(param_1, param_2)
  int param_1;
  int param_2;
{
  char cVar1;
  int iVar2;
  int iVar3;
  char cStack_11;
  undefined4 local_10;
  
  if (*(char *)(*(int *)(param_1 + 0xb0) + 0x120) != '\0') {
    cVar1 = FUN_001195a6(*(undefined4 *)(param_1 + 0x238),*(int *)(param_1 + 0xb0));
    if (cVar1 != '\0') {
      iVar3 = 1;
      while( true ) {
        iVar2 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
        local_10 = *(undefined4 *)(iVar2 + 0x10);
        if (((&cStack_11)[iVar3] == '\0') && (*(char *)(iVar3 + -1 + param_2) != '\0')) break;
        iVar3 = iVar3 + 1;
        if (iVar3 == 5) {
          *(undefined1 *)(*(int *)(param_1 + 0xb0) + 0x120) = 0;
          return;
        }
      }
    }
  }
  return;
}

/* FUN_00183eb2 @ 0x183eb2 (270 bytes) */
int FUN_00183eb2(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int *param_2;
  undefined4 param_3;
  int param_4;
{
  char cVar1;
  
  if (*(int *)(param_2[0x22] + 8) == 0x8e) {
    FUN_000eb51a(param_3,param_2[0x23],param_1);
    (**(code **)(*param_2 + 0xc))(param_2,0,*(undefined4 *)(param_4 + 8));
    param_2[5] = param_2[5] | 0x400;
    *(int *)(param_4 + 0x150) = *(int *)(param_4 + 0x150) + 1;
    return 1;
  }
  if (((param_2[5] & 8U) == 0) && ((param_2[5] & 0x10U) == 0)) {
    if (param_2[0x20] != 0) {
      cVar1 = FUN_0012dfd8(param_2[0x26]);
      if ((cVar1 != '\0') && ((*(byte *)(param_2 + 5) & 2) == 0)) {
        cVar1 = (**(code **)(*param_2 + 0x50))(param_2);
        if (cVar1 == '\0') {
          FUN_000eb51a(param_3,param_2[0x23],param_1);
        }
      }
    }
    (**(code **)(*param_2 + 0xc))(param_2,0,*(undefined4 *)(param_4 + 8));
    param_2[5] = param_2[5] | 0x400;
    *(int *)(param_4 + 0x14c) = *(int *)(param_4 + 0x14c) + 1;
    return 1;
  }
  return 0;
}

/* FUN_00183fc0 @ 0x183fc0 (317 bytes) */
int FUN_00183fc0(param_1, param_2)
  int param_1;
  int param_2;
{
  uint *puVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_10;
  
  cVar3 = FUN_000e1402(*(undefined4 *)(param_1 + 0x238),8);
  if ((cVar3 != '\0') &&
     (*(int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0xa8) <
      *(int *)(*(int *)(param_1 + 0x238) + 0x38c))) {
    iVar5 = *(int *)(param_2 + 0xb0);
    if ((*(byte *)(iVar5 + 0x14) & 1) == 0) {
      puVar1 = *(uint **)(*(int *)(iVar5 + 0x8c) + 0x2c);
      uVar2 = puVar1[1];
      uVar6 = uVar2 - 1;
      if (uVar6 < *puVar1) {
        if (uVar2 <= uVar6) {
          _memset((void *)(puVar1[2] + uVar2 * 4),0,(uVar6 - uVar2) * 4 + 4);
          puVar1[1] = uVar2;
        }
        piVar4 = (int *)(puVar1[2] + uVar6 * 4);
      }
      else {
        piVar4 = (int *)FUN_001a7f7c(puVar1,uVar6);
      }
      iVar5 = *(int *)(*piVar4 + 0xb0);
    }
    local_10 = ((int (*)())FUN_0018357a)(param_1,param_2);
    piVar4 = (int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0xa8);
    *piVar4 = *piVar4 + 1;
    piVar4 = (int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0x13c);
    *piVar4 = *piVar4 + 1;
    FUN_0018fb1c(param_1,iVar5,&local_10,0);
    return 1;
  }
  return 0;
}

/* FUN_001840fe @ 0x1840fe (294 bytes) */
int FUN_001840fe(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  
  *(undefined4 *)(*(int *)(param_1 + 0x134) + 4) = 0;
  **(undefined4 **)(param_1 + 0x134) = param_2;
  puVar3 = (undefined4 *)
           FUN_001a84b2(*(undefined4 *)(param_1 + 0x128),*(undefined4 *)(param_1 + 0x134));
  if (puVar3 != (undefined4 *)0x0) {
    return puVar3;
  }
  uVar5 = *(undefined4 *)(param_1 + 0xbc);
  puVar4 = (undefined4 *)FUN_001a7bca(uVar5,0x2c);
  *puVar4 = uVar5;
  puVar3 = puVar4 + 1;
  puVar4[2] = 0;
  *(undefined1 *)(puVar4 + 3) = 0;
  *(undefined1 *)((int)puVar4 + 0xd) = 0;
  puVar4[4] = 0;
  puVar4[5] = 4;
  *(undefined1 *)(puVar4 + 7) = 0;
  puVar4[8] = 0;
  puVar4[1] = param_2;
  uVar5 = ((int (*)())FUN_00183318)(param_1);
  puVar4[2] = uVar5;
  FUN_001a89d8(*(undefined4 *)(param_1 + 0x128),puVar3);
  FUN_001a89d8(*(undefined4 *)(param_1 + 0x124),puVar3);
  puVar1 = *(uint **)(param_1 + 0x11c);
  uVar2 = puVar1[1];
  if (uVar2 < *puVar1) {
    _memset((void *)(uVar2 * 4 + puVar1[2]),0,4);
    puVar1[1] = uVar2 + 1;
    piVar6 = (int *)(uVar2 * 4 + puVar1[2]);
  }
  else {
    piVar6 = (int *)FUN_001a7f7c(puVar1,uVar2);
  }
  *piVar6 = (int)puVar3;
  return puVar3;
}

/* FUN_00184224 @ 0x184224 (2102 bytes) */
int FUN_00184224(param_1)
  int param_1;
{
  uint uVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  char *pcVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  int local_80;
  int local_60;
  int *local_50;
  int local_40;
  int local_38;
  int local_2c;
  int local_28;
  int *local_24;
  int local_20;
  byte bStack_11;
  undefined4 local_10;
  
  local_50 = *(int **)(param_1 + 0xb0);
  *(undefined4 *)(param_1 + 0xb4) = *(undefined4 *)(local_50[0x22] + 8);
  if (local_50[0x20] != 0) {
    cVar3 = FUN_0012dfd8(local_50[0x26]);
    if (cVar3 == '\0') {
      local_50 = *(int **)(param_1 + 0xb0);
    }
    else if ((*(byte *)(local_50 + 5) & 2) == 0) {
      cVar3 = (**(code **)(*local_50 + 0x50))(local_50);
      if (cVar3 == '\0') {
        local_50 = *(int **)(param_1 + 0xb0);
        if ((*(byte *)(local_50 + 5) & 0x40) == 0) {
          *(undefined4 *)(param_1 + 0xbc) = 0;
          *(undefined4 *)(param_1 + 0xb8) = 0;
          goto LAB_00184299;
        }
      }
      else {
        local_50 = *(int **)(param_1 + 0xb0);
      }
    }
    else {
      local_50 = *(int **)(param_1 + 0xb0);
    }
    *(int *)(param_1 + 0xbc) = local_50[0x25];
    *(int *)(param_1 + 0xb8) = local_50[0x26];
  }
LAB_00184299:
  *(uint *)(param_1 + 0xc0) = (uint)*(byte *)(local_50 + 0x48);
  *(int *)(param_1 + 0xc4) = local_50[0x49];
  iVar12 = 1;
  iVar5 = param_1;
  while( true ) {
    iVar4 = (**(code **)(*local_50 + 0x14))(local_50);
    if (iVar4 < iVar12) break;
    uVar8 = FUN_0010b6e4(*(undefined4 *)(param_1 + 0xb0),iVar12);
    *(undefined4 *)(iVar5 + 0x1bc) = uVar8;
    iVar12 = iVar12 + 1;
    local_50 = *(int **)(param_1 + 0xb0);
    iVar5 = iVar5 + 4;
  }
  iVar5 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x7c))(*(int **)(param_1 + 0xb0));
  if (iVar5 == 0) {
    cVar3 = FUN_0011902c(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                         *(undefined4 *)(param_1 + 0x238));
    if ((cVar3 == '\0') ||
       (cVar3 = FUN_0011913a(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xb0) + 0x88) + 8),
                             *(undefined4 *)(param_1 + 0x238)), cVar3 != '\0')) {
      local_38 = 1;
      local_50 = *(int **)(param_1 + 0xb0);
      for (; iVar5 = (**(code **)(*local_50 + 0x14))(local_50), local_38 <= iVar5;
          local_38 = local_38 + 1) {
        local_50 = *(int **)(param_1 + 0xb0);
        puVar11 = *(uint **)(local_50[local_38 * 6 + 0x23] + 0x2c);
        uVar10 = puVar11[1];
        uVar1 = uVar10 - 1;
        if (uVar1 < *puVar11) {
          if (uVar10 <= uVar1) {
            _memset((void *)(puVar11[2] + uVar10 * 4),0,(uVar1 - uVar10) * 4 + 4);
            puVar11[1] = uVar10;
            local_50 = *(int **)(param_1 + 0xb0);
          }
          piVar6 = (int *)(puVar11[2] + uVar1 * 4);
        }
        else {
          piVar6 = (int *)FUN_001a7f7c(puVar11,uVar1);
          local_50 = *(int **)(param_1 + 0xb0);
        }
        iVar5 = *piVar6;
        pcVar9 = (char *)(param_1 + 0x224 + local_38 * 4);
        local_28 = param_1;
        local_24 = (int *)(local_38 * 0x10 + 0x168 + param_1);
        puVar11 = (uint *)(local_38 * 0x20 + 200 + param_1);
        local_2c = 0;
        do {
          if (*pcVar9 != '\0') {
            iVar12 = FUN_0010b0f4(local_50,local_38);
            bVar2 = *(byte *)(local_2c + 0x10 + iVar12);
            if (bVar2 == 4) {
              *(undefined4 *)(local_28 + 0x30) = 0;
              *(undefined4 *)(local_28 + 0x40) = 0;
              local_50 = *(int **)(param_1 + 0xb0);
            }
            else {
              local_60 = *(int *)(iVar5 + 0x20 + (uint)bVar2 * 4);
              if (local_60 < 0) {
                puVar7 = (undefined4 *)((int (*)())FUN_001836ee)(*(undefined4 *)(param_1 + 0x238),local_60);
                uVar8 = ((float (*)())FUN_0011048e)(*(undefined4 *)(param_1 + 0xb0),local_38,*puVar7);
                uVar8 = ((float (*)())FUN_0011042e)(*(undefined4 *)(param_1 + 0xb0),local_38,uVar8);
                iVar12 = ((int (*)())FUN_001840fe)(*(undefined4 *)(param_1 + 0x238),uVar8);
                local_60 = *(int *)(iVar12 + 4);
                local_50 = *(int **)(param_1 + 0xb0);
              }
              else {
                local_50 = *(int **)(param_1 + 0xb0);
                *puVar11 = (uint)(*(byte *)(local_50 + local_38 * 6 + 0x28) & 1);
                puVar11[4] = (uint)local_50[local_38 * 6 + 0x28] >> 1 & 1;
              }
              *local_24 = local_60;
            }
          }
          local_2c = local_2c + 1;
          pcVar9 = pcVar9 + 1;
          local_28 = local_28 + 4;
          local_24 = local_24 + 1;
          puVar11 = puVar11 + 1;
        } while (local_2c != 4);
      }
    }
    else {
      for (local_40 = 1;
          iVar5 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0)),
          local_40 <= iVar5; local_40 = local_40 + 1) {
        local_50 = *(int **)(param_1 + 0xb0);
        puVar11 = *(uint **)(*(int *)((int)local_50 + 0x8c + local_40 * 0x18) + 0x2c);
        uVar1 = puVar11[1];
        uVar10 = uVar1 - 1;
        if (uVar10 < *puVar11) {
          if (uVar1 <= uVar10) {
            _memset((void *)(puVar11[2] + uVar1 * 4),0,(uVar10 - uVar1) * 4 + 4);
            puVar11[1] = uVar1;
            local_50 = *(int **)(param_1 + 0xb0);
          }
          piVar6 = (int *)(puVar11[2] + uVar10 * 4);
        }
        else {
          piVar6 = (int *)FUN_001a7f7c(puVar11,uVar10);
          local_50 = *(int **)(param_1 + 0xb0);
        }
        iVar12 = *piVar6;
        iVar5 = FUN_0010b0f4(local_50,local_40);
        local_10 = *(undefined4 *)(iVar5 + 0x10);
        piVar6 = (int *)(local_40 * 0x10 + 0x168 + param_1);
        puVar11 = (uint *)(local_40 * 0x20 + 200 + param_1);
        local_20 = 1;
        iVar5 = local_40 * 0x18 + 0x80;
        do {
          if ((&bStack_11)[local_20] != 4) {
            local_80 = *(int *)(iVar12 + 0x20 + (uint)(&bStack_11)[local_20] * 4);
            if (local_80 < 0) {
              puVar7 = (undefined4 *)((int (*)())FUN_001836ee)(*(undefined4 *)(param_1 + 0x238),local_80);
              uVar8 = ((float (*)())FUN_0011048e)(*(undefined4 *)(param_1 + 0xb0),local_40,*puVar7);
              uVar8 = ((float (*)())FUN_0011042e)(*(undefined4 *)(param_1 + 0xb0),local_40,uVar8);
              iVar4 = ((int (*)())FUN_001840fe)(*(undefined4 *)(param_1 + 0x238),uVar8);
              local_80 = *(int *)(iVar4 + 4);
            }
            else {
              iVar4 = *(int *)(param_1 + 0xb0);
              *puVar11 = (uint)(*(byte *)(iVar4 + 0x20 + iVar5) & 1);
              puVar11[4] = *(uint *)(iVar4 + 0x20 + iVar5) >> 1 & 1;
            }
            *piVar6 = local_80;
          }
          local_20 = local_20 + 1;
          piVar6 = piVar6 + 1;
          puVar11 = puVar11 + 1;
        } while (local_20 != 5);
      }
    }
  }
  else if (0 < *(int *)(iVar5 + 0x84)) {
    iVar12 = 1;
    iVar4 = FUN_0010b180(iVar5,1);
    do {
      if (iVar4 == 0) {
        puVar7 = (undefined4 *)(iVar12 * 0x10 + 0x168 + param_1);
        iVar4 = 4;
        do {
          *puVar7 = 0;
          puVar7 = puVar7 + 1;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
        if (*(int *)(iVar5 + 0x84) < iVar12 + 1) break;
      }
      else {
        puVar7 = (undefined4 *)(iVar12 * 0x10 + 0x168 + param_1);
        iVar4 = 0;
        do {
          *puVar7 = *(undefined4 *)(iVar4 + *(int *)(*(int *)(iVar5 + 0x138) + iVar12 * 4));
          iVar4 = iVar4 + 4;
          puVar7 = puVar7 + 1;
        } while (iVar4 != 0x10);
        if (*(int *)(iVar5 + 0x84) < iVar12 + 1) break;
      }
      iVar12 = iVar12 + 1;
      iVar4 = FUN_0010b180(iVar5,iVar12);
    } while( true );
  }
  piVar6 = *(int **)(param_1 + 0xb0);
  *(int *)(param_1 + 0x1cc) = piVar6[0x4b];
  *(int *)(param_1 + 0x1d0) = piVar6[0x4c];
  *(int *)(param_1 + 0x1d4) = piVar6[0x4d];
  *(int *)(param_1 + 0x1d8) = piVar6[0x4e];
  *(int *)(param_1 + 0x1dc) = piVar6[0x4f];
  *(int *)(param_1 + 0x1e0) = piVar6[0x50];
  *(int *)(param_1 + 0x1e4) = piVar6[0x51];
  *(int *)(param_1 + 0x1e8) = piVar6[0x52];
  cVar3 = (**(code **)(*piVar6 + 0x30))(piVar6);
  if (cVar3 == '\0') {
    cVar3 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x5c))(*(int **)(param_1 + 0xb0));
    if (cVar3 == '\0') {
      cVar3 = ((int (*)())FUN_001833e6)(param_1);
      if (cVar3 == '\0') {
        local_50 = *(int **)(param_1 + 0xb0);
        if (*(int *)(local_50[0x22] + 8) == 0xf7) {
          *(int *)(param_1 + 0x1d4) = local_50[0x53];
        }
        else if (*(int *)(local_50[0x22] + 8) == 0xb4) {
          *(int *)(param_1 + 0x1d4) = local_50[0x53];
        }
      }
      else {
        local_50 = *(int **)(param_1 + 0xb0);
        *(int *)(param_1 + 0x1d4) = local_50[0x53];
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x1ec) = 1;
      local_50 = *(int **)(param_1 + 0xb0);
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x1dc) = 0;
    local_50 = *(int **)(param_1 + 0xb0);
    puVar7 = (undefined4 *)local_50[0x4f];
    *(undefined4 *)(param_1 + 0x1ec) = *puVar7;
    *(undefined4 *)(param_1 + 0x1f0) = puVar7[1];
    *(undefined4 *)(param_1 + 500) = puVar7[2];
    *(undefined4 *)(param_1 + 0x1f8) = puVar7[3];
    *(undefined4 *)(param_1 + 0x1fc) = puVar7[4];
    *(undefined4 *)(param_1 + 0x200) = puVar7[5];
    *(undefined4 *)(param_1 + 0x204) = puVar7[6];
    *(undefined4 *)(param_1 + 0x208) = puVar7[7];
    *(undefined4 *)(param_1 + 0x20c) = puVar7[8];
  }
  cVar3 = (**(code **)(*local_50 + 0x74))(local_50);
  if (cVar3 != '\0') {
    *(undefined4 *)(*(int *)(param_1 + 0xb0) + 300) = *(undefined4 *)(param_1 + 0x188);
  }
  cVar3 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x78))(*(int **)(param_1 + 0xb0));
  if (cVar3 != '\0') {
    *(undefined4 *)(*(int *)(param_1 + 0xb0) + 300) = *(undefined4 *)(param_1 + 0x188);
  }
  return;
}

/* FUN_00184a5a @ 0x184a5a (61 bytes) */
int FUN_00184a5a(param_1)
  int param_1;
{
  _memset((void *)(param_1 + 0xb4),0,0x15c);
  ((int (*)())FUN_00183b9e)(param_1);
  ((int (*)())FUN_00184224)();
  return;
}

/* FUN_00184a98 @ 0x184a98 (178 bytes) */
int FUN_00184a98(param_1)
  int param_1;
{
  char cVar1;
  
  cVar1 = FUN_000e1402(*(undefined4 *)(param_1 + 0x238),9);
  if (cVar1 != '\0') {
    cVar1 = FUN_0018c36c(param_1);
    if (cVar1 != '\0') {
      ((int (*)())FUN_00184a5a)(param_1);
    }
    do {
      cVar1 = FUN_00192b1a(param_1);
    } while (cVar1 != '\0');
    cVar1 = FUN_0018c9fa(param_1);
    if (cVar1 != '\0') {
      ((int (*)())FUN_00184a5a)(param_1);
    }
    cVar1 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x24))(*(int **)(param_1 + 0xb0));
    if ((cVar1 != '\0') && (cVar1 = FUN_0018b844(param_1), cVar1 != '\0')) {
      ((int (*)())FUN_00184a5a)(param_1);
    }
    cVar1 = FUN_0018ce2c(param_1);
    if (cVar1 != '\0') {
      ((int (*)())FUN_00184a5a)(param_1);
    }
    return 1;
  }
  return 0;
}

/* FUN_00184b4a @ 0x184b4a (306 bytes) */
int FUN_00184b4a(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  **(undefined4 **)(param_1 + 0x138) = param_2;
  puVar4 = (undefined4 *)
           FUN_001a84b2(*(undefined4 *)(param_1 + 300),*(undefined4 *)(param_1 + 0x138));
  if (puVar4 != (undefined4 *)0x0) {
    return puVar4;
  }
  uVar1 = *(undefined4 *)(param_1 + 0xbc);
  puVar5 = (undefined4 *)FUN_001a7bca(uVar1,0x34);
  *puVar5 = uVar1;
  puVar4 = puVar5 + 1;
  puVar5[1] = 0;
  puVar5[2] = 0;
  puVar5[3] = 0xffffffff;
  puVar5[4] = 0;
  puVar5[5] = 0;
  *(undefined1 *)(puVar5 + 6) = 0;
  puVar5[7] = 0;
  puVar5[8] = 0;
  *(undefined1 *)(puVar5 + 9) = 0;
  puVar5[10] = 0;
  *(undefined1 *)(puVar5 + 0xb) = 0;
  puVar5[0xc] = 0;
  puVar5[1] = param_2;
  FUN_001a89d8(*(undefined4 *)(param_1 + 300),puVar4);
  puVar2 = *(uint **)(param_1 + 0x120);
  uVar3 = puVar2[1];
  if (uVar3 < *puVar2) {
    _memset((void *)(uVar3 * 4 + puVar2[2]),0,4);
    puVar2[1] = uVar3 + 1;
    *(undefined4 **)(uVar3 * 4 + puVar2[2]) = puVar4;
  }
  else {
    piVar6 = (int *)FUN_001a7f7c(puVar2,uVar3);
    *piVar6 = (int)puVar4;
  }
  return puVar4;
}

/* FUN_00184c7c @ 0x184c7c (186 bytes) */
int FUN_00184c7c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int local_10;
  
  if (param_3 <= (int)param_2) {
    local_10 = param_2 * 4;
    do {
      puVar2 = *(uint **)(param_4 + 0x400);
      if (param_2 < *puVar2) {
        uVar1 = puVar2[1];
        if (uVar1 <= param_2) {
          _memset((void *)(puVar2[2] + uVar1 * 4),0,(param_2 - uVar1) * 4 + 4);
          puVar2[1] = param_2 + 1;
        }
        iVar4 = FUN_001a84b2(*(undefined4 *)(local_10 + puVar2[2]),param_1);
      }
      else {
        puVar3 = (undefined4 *)FUN_001a7f7c(puVar2,param_2);
        iVar4 = FUN_001a84b2(*puVar3,param_1);
      }
      if (iVar4 != 0) {
        return iVar4;
      }
      param_2 = param_2 - 1;
      local_10 = local_10 + -4;
    } while (param_3 <= (int)param_2);
  }
  return 0;
}

/* FUN_00184d36 @ 0x184d36 (186 bytes) */
int FUN_00184d36(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int local_10;
  
  if (param_3 <= (int)param_2) {
    local_10 = param_2 * 4;
    do {
      puVar2 = *(uint **)(param_4 + 0x3fc);
      if (param_2 < *puVar2) {
        uVar1 = puVar2[1];
        if (uVar1 <= param_2) {
          _memset((void *)(puVar2[2] + uVar1 * 4),0,(param_2 - uVar1) * 4 + 4);
          puVar2[1] = param_2 + 1;
        }
        iVar4 = FUN_001a84b2(*(undefined4 *)(local_10 + puVar2[2]),param_1);
      }
      else {
        puVar3 = (undefined4 *)FUN_001a7f7c(puVar2,param_2);
        iVar4 = FUN_001a84b2(*puVar3,param_1);
      }
      if (iVar4 != 0) {
        return iVar4;
      }
      param_2 = param_2 - 1;
      local_10 = local_10 + -4;
    } while (param_3 <= (int)param_2);
  }
  return 0;
}

/* FUN_00184df0 @ 0x184df0 (466 bytes) */
int FUN_00184df0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  char cVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  int local_20;
  
  cVar4 = FUN_000e1402(*(undefined4 *)(param_1 + 0x238),9);
  if ((cVar4 != '\0') &&
     (iVar9 = *(int *)(param_1 + 0x238),
     *(int *)(*(int *)(iVar9 + 0x3f4) + 0xa8) < *(int *)(iVar9 + 0x38c))) {
    uVar1 = *(undefined4 *)(iVar9 + 0xbc);
    puVar5 = (undefined4 *)FUN_001a7bca(uVar1,0x240);
    *puVar5 = uVar1;
    puVar5[0x2d] = *(undefined4 *)(param_1 + 0xb0);
    local_20 = 0;
    puVar8 = puVar5 + 1;
    iVar9 = param_1;
    do {
      iVar6 = FUN_0010b0f4(*(undefined4 *)(param_1 + 0xb0),0);
      if (*(char *)(local_20 + 0x10 + iVar6) == '\x01') {
        puVar8[8] = 3;
      }
      else {
        puVar8[8] = *(undefined4 *)(iVar9 + 0x20);
      }
      local_20 = local_20 + 1;
      puVar8 = puVar8 + 1;
      iVar9 = iVar9 + 4;
    } while (local_20 != 4);
    iVar9 = ((int (*)())FUN_00184d36)(puVar5 + 1,param_2,param_3,
                         *(undefined4 *)(*(int *)(param_1 + 0x238) + 0x3f4));
    if (iVar9 != 0) {
      iVar9 = *(int *)(iVar9 + 0xb0);
      if ((*(byte *)(iVar9 + 0x14) & 1) == 0) {
        puVar2 = *(uint **)(*(int *)(iVar9 + 0x8c) + 0x2c);
        uVar3 = puVar2[1];
        uVar10 = uVar3 - 1;
        if (uVar10 < *puVar2) {
          if (uVar3 <= uVar10) {
            _memset((void *)(puVar2[2] + uVar3 * 4),0,(uVar10 - uVar3) * 4 + 4);
            puVar2[1] = uVar3;
          }
          piVar7 = (int *)(puVar2[2] + uVar10 * 4);
        }
        else {
          piVar7 = (int *)FUN_001a7f7c(puVar2,uVar10);
        }
        iVar9 = *(int *)(*piVar7 + 0xb0);
      }
      piVar7 = (int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0xa8);
      *piVar7 = *piVar7 + 1;
      piVar7 = (int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0x144);
      *piVar7 = *piVar7 + 1;
      FUN_0018fb1c(param_1,iVar9,&DAT_001cc71c,0);
      return 1;
    }
  }
  return 0;
}

/* FUN_00184fc2 @ 0x184fc2 (526 bytes) */
int FUN_00184fc2(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  int param_3;
{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int local_2c;
  int local_28;
  int local_20;
  int local_10;
  
  puVar1 = *(uint **)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0x404);
  local_20 = 1;
  local_28 = 0x98;
  local_2c = 0x18;
  iVar5 = (**(code **)(**(int **)(param_1 + 0xb0) + 0x14))(*(int **)(param_1 + 0xb0));
  if (0 < iVar5) {
    do {
      piVar8 = *(int **)(local_2c + *(int *)(param_1 + 0xb0) + 0x8c);
      cVar4 = (**(code **)(*piVar8 + 0x18))(piVar8);
      if (cVar4 == '\0') {
        piVar8 = *(int **)(param_1 + 0xb0);
      }
      else {
        uVar2 = piVar8[7];
        if ((int)param_2 < param_3) {
          piVar8 = *(int **)(param_1 + 0xb0);
        }
        else {
          local_10 = param_2 << 2;
          uVar9 = param_2;
          do {
            if (uVar9 < *puVar1) {
              uVar3 = puVar1[1];
              if (uVar3 <= uVar9) {
                _memset((void *)(puVar1[2] + uVar3 * 4),0,(uVar9 - uVar3) * 4 + 4);
                puVar1[1] = uVar9 + 1;
              }
              piVar6 = (int *)(local_10 + puVar1[2]);
            }
            else {
              piVar6 = (int *)FUN_001a7f7c(puVar1,uVar9);
            }
            iVar5 = *(int *)(*piVar6 + 0xc4);
            uVar3 = *(uint *)(iVar5 + 4);
            if (0 < (int)uVar3) {
              uVar7 = 0;
              do {
                if (uVar3 <= uVar7) {
                  if (piVar8 != (int *)MACH_HEADER.magic) goto LAB_00185097;
LAB_001850b2:
                  if ((*(uint *)(*(int *)(*piVar6 + 0x120) + 8 + (uVar2 >> 5) * 4) >>
                       ((byte)uVar2 & 0x1f) & 1) != 0) {
                    piVar8 = *(int **)(param_1 + 0xb0);
                    if ((*(byte *)((int)piVar8 + local_28 + 0x20) & 2) == 0) {
                      piVar8 = (int *)(*(int *)(*(int *)(param_1 + 0x238) + 0x3f4) + 0xa8);
                      *piVar8 = *piVar8 + 1;
                      FUN_00109c0e(*(int *)(param_1 + 0xb0) + 0xc + local_28,1,
                                   *(byte *)(*(int *)(param_1 + 0xb0) + 0x20 + local_28) & 1 ^ 1);
                      piVar8 = *(int **)(param_1 + 0xb0);
                    }
                    goto LAB_001850ee;
                  }
                  break;
                }
                if (piVar8 == *(int **)(*(int *)(iVar5 + 8) + uVar7 * 4)) goto LAB_001850b2;
LAB_00185097:
                uVar7 = uVar7 + 1;
              } while (uVar3 != uVar7);
            }
            uVar9 = uVar9 - 1;
            local_10 = local_10 + -4;
          } while (param_3 <= (int)uVar9);
          piVar8 = *(int **)(param_1 + 0xb0);
        }
      }
LAB_001850ee:
      local_20 = local_20 + 1;
      local_2c = local_2c + 0x18;
      local_28 = local_28 + 0x18;
      iVar5 = (**(code **)(*piVar8 + 0x14))(piVar8);
    } while (local_20 <= iVar5);
  }
  return;
}

/* FUN_001851d0 @ 0x1851d0 (371 bytes) */
int FUN_001851d0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  uint *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  *(undefined4 *)(*(int *)(param_1 + 0x138) + 4) = param_3;
  *(undefined4 *)(*(int *)(param_1 + 0x138) + 8) = param_2;
  puVar3 = (undefined4 *)
           FUN_001a84b2(*(undefined4 *)(param_1 + 0x130),*(undefined4 *)(param_1 + 0x138));
  if (puVar3 != (undefined4 *)0x0) {
    return puVar3;
  }
  uVar4 = *(undefined4 *)(param_1 + 0xbc);
  puVar3 = (undefined4 *)FUN_001a7bca(uVar4,0x34);
  *puVar3 = uVar4;
  puVar5 = puVar3 + 1;
  puVar3[1] = 0;
  puVar3[2] = 0;
  puVar3[3] = 0xffffffff;
  puVar3[4] = 0;
  puVar3[5] = 0;
  *(undefined1 *)(puVar3 + 6) = 0;
  puVar3[7] = 0;
  puVar3[8] = 0;
  *(undefined1 *)(puVar3 + 9) = 0;
  puVar3[10] = 0;
  *(undefined1 *)(puVar3 + 0xb) = 0;
  puVar3[0xc] = 0;
  uVar4 = ((int (*)())FUN_00183300)(param_1);
  puVar3[1] = uVar4;
  puVar3[2] = param_3;
  puVar3[3] = param_2;
  FUN_001a89d8(*(undefined4 *)(param_1 + 300),puVar5);
  FUN_001a89d8(*(undefined4 *)(param_1 + 0x130),puVar5);
  puVar1 = *(uint **)(param_1 + 0x120);
  uVar2 = puVar1[1];
  if (uVar2 < *puVar1) {
    _memset((void *)(uVar2 * 4 + puVar1[2]),0,4);
    puVar1[1] = uVar2 + 1;
    *(undefined4 **)(uVar2 * 4 + puVar1[2]) = puVar5;
  }
  else {
    puVar3 = (undefined4 *)FUN_001a7f7c(puVar1,uVar2);
    *puVar3 = puVar5;
  }
  return puVar5;
}

/* FUN_00185344 @ 0x185344 (3265 bytes) */
int FUN_00185344(param_1)
  int *param_1;
{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  int *local_54;
  undefined1 *local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined1 local_39;
  int local_38;
  int local_34;
  int *local_30;
  undefined1 auStack_21 [17];
  
  auStack_21[1] = 1;
  auStack_21[2] = 1;
  auStack_21[3] = 1;
  auStack_21[4] = 1;
  piVar8 = (int *)param_1[0x2c];
  if (*(int *)(piVar8[0x22] + 8) == 0x8e) {
    uVar5 = (**(code **)(*piVar8 + 0x7c))(piVar8);
    cVar4 = FUN_0012526a(uVar5);
    if (cVar4 == '\0') goto LAB_0018538e;
    cVar4 = FUN_0010b1aa(param_1[0x2c]);
  }
  else {
    cVar4 = FUN_0010b1aa(piVar8);
  }
  if ((((cVar4 != '\0') || (cVar4 = FUN_0010a320(param_1[0x2c]), cVar4 != '\0')) ||
      (piVar8 = (int *)param_1[0x2c], *(int *)(piVar8[0x22] + 8) == 0xb4)) ||
     ((cVar4 = (**(code **)(*piVar8 + 0x6c))(piVar8), cVar4 != '\0' ||
      (cVar4 = (**(code **)(*(int *)param_1[0x2c] + 0x58))((int *)param_1[0x2c]), cVar4 != '\0'))))
  {
LAB_0018538e:
    local_4c = 0;
    piVar8 = param_1;
    do {
      uVar5 = ((int (*)())FUN_00183300)(param_1[0x8e]);
      piVar6 = (int *)((int (*)())FUN_00184b4a)(param_1[0x8e],uVar5);
      piVar6[1] = (int)param_1;
      piVar6[2] = local_4c;
      FUN_001a89d8(*(undefined4 *)(param_1[0x8e] + 300),piVar6);
      FUN_001a89d8(*(undefined4 *)(param_1[0x8e] + 0x130),piVar6);
      *piVar8 = *piVar6;
      local_4c = local_4c + 1;
      piVar8 = piVar8 + 1;
    } while (local_4c != 4);
    return;
  }
  cVar4 = (**(code **)(*(int *)param_1[0x2c] + 0x60))((int *)param_1[0x2c]);
  if (cVar4 != '\0') {
    local_30 = param_1;
    iVar11 = 0;
    iVar7 = param_1[0x2c];
    do {
      iVar7 = FUN_0010b0f4(iVar7,0);
      if (*(char *)(iVar11 + 0x10 + iVar7) == '\x01') {
        iVar7 = param_1[0x2c];
      }
      else {
        iVar7 = param_1[0x2c];
        if (0 < *(int *)(iVar7 + 0x84)) {
          local_48 = 1;
          local_54 = param_1 + iVar11 + 0x5e;
          do {
            iVar7 = FUN_0010b0f4(iVar7,local_48);
            if (*(char *)(iVar11 + 0x10 + iVar7) != '\x04') {
              *local_30 = *local_54;
              iVar7 = param_1[0x2c];
              break;
            }
            local_48 = local_48 + 1;
            local_54 = local_54 + 4;
            iVar7 = param_1[0x2c];
          } while (local_48 <= *(int *)(iVar7 + 0x84));
        }
      }
      iVar11 = iVar11 + 1;
      local_30 = local_30 + 1;
      if (iVar11 == 4) {
        local_44 = 0;
        iVar7 = FUN_0010b0f4(iVar7,0);
        cVar4 = *(char *)(iVar7 + 0x10);
        piVar8 = param_1;
        while( true ) {
          if (cVar4 == '\x01') {
            *piVar8 = 2;
          }
          piVar8 = piVar8 + 1;
          if (local_44 + 1 == 4) break;
          iVar7 = FUN_0010b0f4(param_1[0x2c],0);
          cVar4 = *(char *)(local_44 + 0x11 + iVar7);
          local_44 = local_44 + 1;
        }
        return;
      }
    } while( true );
  }
  cVar4 = (**(code **)(*(int *)param_1[0x2c] + 0x50))((int *)param_1[0x2c]);
  if (cVar4 != '\0') {
    iVar7 = 4;
    piVar8 = param_1;
    do {
      *piVar8 = 1;
      piVar8 = piVar8 + 1;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    goto LAB_001855ac;
  }
  cVar4 = (**(code **)(*(int *)param_1[0x2c] + 0x48))((int *)param_1[0x2c]);
  if (cVar4 == '\0') {
    iVar7 = param_1[0x2c];
  }
  else {
    iVar7 = param_1[0x2c];
    if (((*(int *)(iVar7 + 0x98) == 2) || (*(int *)(iVar7 + 0x98) == 0xc)) ||
       (*(int *)(iVar7 + 0x98) == 0x33)) {
      local_40 = 0;
      piVar8 = param_1;
      while( true ) {
        if (((int)*(char *)(iVar7 + 0x15c) >> ((byte)local_40 & 0x1f) & 1U) == 0) {
          piVar6 = (int *)((int (*)())FUN_001851d0)(param_1[0x8e],local_40,param_1);
          piVar8[0x10] = (int)piVar6;
          *piVar8 = *piVar6;
        }
        else {
          iVar7 = FUN_00188d2e(param_1,local_40);
          *piVar8 = *(int *)(iVar7 + 4);
        }
        local_40 = local_40 + 1;
        piVar8 = piVar8 + 1;
        if (local_40 == 4) break;
        iVar7 = param_1[0x2c];
      }
      goto LAB_001855ac;
    }
  }
  cVar4 = FUN_0011902c(*(undefined4 *)(*(int *)(iVar7 + 0x88) + 8),param_1[0x8e]);
  if ((cVar4 == '\0') ||
     (cVar4 = FUN_0011913a(*(undefined4 *)(*(int *)(param_1[0x2c] + 0x88) + 8),param_1[0x8e]),
     cVar4 != '\0')) {
    cVar4 = FUN_00119104(*(undefined4 *)(*(int *)(param_1[0x2c] + 0x88) + 8),param_1[0x8e]);
    if (cVar4 == '\0') {
      cVar4 = ((int (*)())FUN_00183daa)(param_1[0x2c],param_1[0x8e]);
      if (cVar4 == '\0') {
        cVar4 = ((int (*)())FUN_001837c0)(param_1);
        if (cVar4 == '\0') {
          iVar7 = param_1[0x2c];
          cVar4 = ((int (*)())FUN_0018336e)(iVar7);
          if (cVar4 == '\0') {
            piVar8 = param_1 + 0x5a;
            local_39 = 0;
            local_38 = 0;
            puVar1 = auStack_21 + 1;
            do {
              iVar7 = FUN_0010b0f4(iVar7,0);
              if (*(char *)(local_38 + 0x10 + iVar7) != '\x01') {
                piVar6 = (int *)param_1[0x2c];
                if (*(int *)(piVar6[0x22] + 8) == 0x8e) {
                  cVar4 = FUN_0018a204(param_1,local_38);
                  if (cVar4 == '\0') {
                    piVar6 = (int *)((int (*)())FUN_001851d0)(param_1[0x8e],local_38,param_1);
                    iVar7 = *piVar6;
                  }
                  else {
                    iVar7 = piVar8[4];
                  }
LAB_00185e1c:
                  piVar8[-0x5a] = iVar7;
                }
                else {
                  cVar4 = (**(code **)(*piVar6 + 100))(piVar6);
                  if (cVar4 == '\0') {
                    cVar4 = ((int (*)())FUN_00183844)(param_1[0x2c]);
                    if (cVar4 == '\0') {
                      iVar7 = piVar8[-0x4e];
                      if (iVar7 == 0) goto LAB_00185d02;
LAB_00185e19:
                      iVar7 = *(int *)(iVar7 + 4);
                      goto LAB_00185e1c;
                    }
                    if (piVar8[4] < 0) {
                      puVar9 = (undefined4 *)((int (*)())FUN_001836ee)(param_1[0x8e],piVar8[4]);
                      cVar4 = ((bool (*)())FUN_00110958)(param_1[0x2c],*puVar9,0);
                      iVar11 = ~-(uint)(cVar4 == '\0') + 3;
                      iVar7 = param_1[local_38 + iVar11 * 4 + 0x5a];
                      if (iVar7 < 0) {
                        puVar9 = (undefined4 *)((int (*)())FUN_001836ee)(param_1[0x8e],iVar7);
                        iVar7 = ((float (*)())FUN_001100e2)(param_1[0x2c],*puVar9);
                        iVar11 = ((float (*)())FUN_001102fa)(param_1[0x2c],iVar7);
                        if (iVar11 != iVar7) {
                          local_39 = 1;
                          iVar7 = iVar11;
                        }
                        iVar7 = ((int (*)())FUN_001840fe)(param_1[0x8e],iVar7);
                        iVar7 = *(int *)(iVar7 + 4);
                        iVar11 = FUN_0010b0f4(param_1[0x2c],0);
                        if (*(char *)(local_38 + 0x10 + iVar11) == '\0') {
                          puVar1[local_38] = local_39;
                        }
                        goto LAB_00185de4;
                      }
                      iVar10 = param_1[0x2c];
                      if ((((*(char *)(iVar10 + 0x120) == '\0') && (*(int *)(iVar10 + 0x124) == 0))
                          && (uVar3 = *(uint *)(iVar10 + 0xa0 + iVar11 * 0x18), (uVar3 & 1) == 0))
                         && ((uVar3 & 2) == 0)) {
                        piVar8[-0x5a] = iVar7;
                        iVar11 = FUN_001875a8(param_1,iVar7);
                        piVar8[-0x3a] = iVar11;
                        iVar7 = FUN_001875d4(param_1,iVar7);
                        piVar8[-0x46] = iVar7;
                        goto LAB_00185b3e;
                      }
                      FUN_0018874c(param_1,local_38);
                    }
                    else {
                      iVar7 = piVar8[-0x4e];
                      if (iVar7 != 0) goto LAB_00185e19;
                      FUN_0018874c(param_1,local_38);
                    }
LAB_00185d28:
                    FUN_00188a68(param_1,local_38,puVar1);
                    piVar6 = (int *)piVar8[-0x4a];
                    piVar8[-0x5a] = *piVar6;
                    piVar8[-0x3a] = piVar6[3];
                    piVar8[-0x46] = piVar6[4];
                  }
                  else {
                    iVar7 = piVar8[4];
                    if (iVar7 < 0) {
                      puVar9 = (undefined4 *)((int (*)())FUN_001836ee)(param_1[0x8e],iVar7);
                      iVar7 = ((float (*)())FUN_001100e2)(param_1[0x2c],*puVar9);
                      iVar11 = ((float (*)())FUN_001102fa)(param_1[0x2c],iVar7);
                      if (iVar11 != iVar7) {
                        local_39 = 1;
                        iVar7 = iVar11;
                      }
                      iVar7 = ((int (*)())FUN_001840fe)(param_1[0x8e],iVar7);
                      iVar7 = *(int *)(iVar7 + 4);
                      iVar11 = FUN_0010b0f4(param_1[0x2c],0);
                      if (*(char *)(local_38 + 0x10 + iVar11) == '\0') {
                        puVar1[local_38] = local_39;
                      }
LAB_00185de4:
                      piVar8[-0x5a] = iVar7;
                    }
                    else {
                      iVar11 = param_1[0x2c];
                      if (((*(char *)(iVar11 + 0x120) != '\0') || (*(int *)(iVar11 + 0x124) != 0))
                         || (((*(uint *)(iVar11 + 0xb8) & 1) != 0 ||
                             ((*(uint *)(iVar11 + 0xb8) & 2) != 0)))) {
LAB_00185d02:
                        FUN_0018874c(param_1,local_38);
                        goto LAB_00185d28;
                      }
                      piVar8[-0x5a] = iVar7;
                      iVar11 = FUN_001875a8(param_1,iVar7);
                      piVar8[-0x3a] = iVar11;
                      iVar7 = FUN_001875d4(param_1,iVar7);
                      piVar8[-0x46] = iVar7;
                    }
                  }
                }
              }
LAB_00185b3e:
              local_38 = local_38 + 1;
              piVar8 = piVar8 + 1;
              if (local_38 == 4) goto LAB_001855ac;
              iVar7 = param_1[0x2c];
            } while( true );
          }
        }
        else {
          iVar7 = param_1[0x2c];
        }
      }
      else {
        iVar7 = param_1[0x2c];
      }
    }
    else {
      iVar7 = param_1[0x2c];
    }
  }
  else {
    iVar7 = param_1[0x2c];
  }
  iVar7 = FUN_0010b0f4(iVar7,0);
  if (*(int *)(iVar7 + 0x10) == DAT_001cc714) {
    iVar7 = 0;
  }
  else {
    iVar7 = FUN_0010b0f4(param_1[0x2c],0);
    iVar7 = FUN_000f5950(*(undefined4 *)(iVar7 + 0x10));
  }
  cVar4 = (**(code **)(*(int *)param_1[0x2c] + 100))((int *)param_1[0x2c]);
  if (cVar4 == '\0') {
    cVar4 = ((int (*)())FUN_00183844)(param_1[0x2c]);
    if (cVar4 == '\0') {
      iVar11 = param_1[iVar7 + 0xc];
      if (iVar11 != 0) {
LAB_001859cb:
        iVar11 = *(int *)(iVar11 + 4);
        local_34 = 0;
        iVar7 = 0;
        goto LAB_00185779;
      }
      FUN_0018874c(param_1,iVar7);
      FUN_00188a68(param_1,iVar7,auStack_21 + 1);
      iVar11 = 1;
      piVar8 = param_1;
      do {
        piVar8[0x10] = param_1[iVar7 + 0x10];
        (auStack_21 + 1)[iVar11 + -1] = auStack_21[iVar7 + 1];
        iVar11 = iVar11 + 1;
        piVar8 = piVar8 + 1;
      } while (iVar11 != 5);
    }
    else if (param_1[iVar7 + 0x5e] < 0) {
      puVar9 = (undefined4 *)((int (*)())FUN_001836ee)(param_1[0x8e],param_1[iVar7 + 0x5e]);
      cVar4 = ((bool (*)())FUN_00110958)(param_1[0x2c],*puVar9,0);
      iVar10 = ~-(uint)(cVar4 == '\0') + 3;
      iVar11 = param_1[iVar7 + iVar10 * 4 + 0x5a];
      if (iVar11 < 0) {
        puVar9 = (undefined4 *)((int (*)())FUN_001836ee)(param_1[0x8e],iVar11);
        iVar7 = ((float (*)())FUN_001100e2)(param_1[0x2c],*puVar9);
        goto LAB_00185925;
      }
      iVar2 = param_1[0x2c];
      if (((*(char *)(iVar2 + 0x120) == '\0') && (*(int *)(iVar2 + 0x124) == 0)) &&
         ((uVar3 = *(uint *)(iVar2 + 0xa0 + iVar10 * 0x18), (uVar3 & 1) == 0 && ((uVar3 & 2) == 0)))
         ) goto LAB_00185755;
      FUN_0018874c(param_1,iVar7);
      FUN_00188a68(param_1,iVar7,auStack_21 + 1);
      iVar11 = 1;
      piVar8 = param_1;
      do {
        piVar8[0x10] = param_1[iVar7 + 0x10];
        (auStack_21 + 1)[iVar11 + -1] = auStack_21[iVar7 + 1];
        iVar11 = iVar11 + 1;
        piVar8 = piVar8 + 1;
      } while (iVar11 != 5);
    }
    else {
      iVar11 = param_1[iVar7 + 0xc];
      if (iVar11 != 0) goto LAB_001859cb;
      FUN_0018874c(param_1,iVar7);
      FUN_00188a68(param_1,iVar7,auStack_21 + 1);
      iVar11 = 1;
      piVar8 = param_1;
      do {
        piVar8[0x10] = param_1[iVar7 + 0x10];
        (auStack_21 + 1)[iVar11 + -1] = auStack_21[iVar7 + 1];
        iVar11 = iVar11 + 1;
        piVar8 = piVar8 + 1;
      } while (iVar11 != 5);
    }
LAB_001857d2:
    piVar8 = (int *)param_1[iVar7 + 0x10];
    iVar11 = *piVar8;
    local_34 = piVar8[3];
    iVar7 = piVar8[4];
  }
  else {
    iVar11 = param_1[iVar7 + 0x5e];
    if (iVar11 < 0) {
      puVar9 = (undefined4 *)((int (*)())FUN_001836ee)(param_1[0x8e],iVar11);
      iVar7 = ((float (*)())FUN_001100e2)(param_1[0x2c],*puVar9);
LAB_00185925:
      iVar11 = ((float (*)())FUN_001102fa)(param_1[0x2c],iVar7);
      bVar12 = iVar11 != iVar7;
      if (bVar12) {
        iVar7 = iVar11;
      }
      iVar7 = ((int (*)())FUN_001840fe)(param_1[0x8e],iVar7);
      iVar11 = *(int *)(iVar7 + 4);
      if ((*(char *)(param_1[0x2c] + 0x120) == '\0') || (bVar12)) {
        local_34 = 0;
        iVar7 = 0;
      }
      else {
        *(undefined1 *)(param_1[0x2c] + 0x120) = 0;
        local_34 = 0;
        iVar7 = 0;
      }
    }
    else {
      iVar10 = param_1[0x2c];
      if ((((*(char *)(iVar10 + 0x120) != '\0') || (*(int *)(iVar10 + 0x124) != 0)) ||
          ((*(uint *)(iVar10 + 0xb8) & 1) != 0)) || ((*(uint *)(iVar10 + 0xb8) & 2) != 0)) {
        FUN_0018874c(param_1,iVar7);
        FUN_00188a68(param_1,iVar7,auStack_21 + 1);
        goto LAB_001857d2;
      }
LAB_00185755:
      local_34 = FUN_001875a8(param_1,iVar11);
      iVar7 = FUN_001875d4(param_1,iVar11);
    }
  }
LAB_00185779:
  iVar10 = 0;
  piVar8 = param_1;
  do {
    *piVar8 = iVar11;
    piVar8[0x20] = local_34;
    piVar8[0x14] = iVar7;
    iVar10 = iVar10 + 1;
    piVar8 = piVar8 + 1;
  } while (iVar10 != 4);
LAB_001855ac:
  local_50 = auStack_21 + 1;
  ((int (*)())FUN_00183e24)(param_1,local_50);
  FUN_001878ea(param_1);
  FUN_00187812(param_1);
  return;
}

/* FUN_00186006 @ 0x186006 (343 bytes) */
int FUN_00186006(param_1, param_2, param_3, param_4)
  undefined4 *param_1;
  uint param_2;
  int param_3;
  int param_4;
{
  uint uVar1;
  uint *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int local_10;
  
  if (param_3 <= (int)param_2) {
    local_10 = param_2 << 2;
    uVar5 = param_2;
    do {
      puVar2 = *(uint **)(param_4 + 0x3f8);
      if (uVar5 < *puVar2) {
        uVar1 = puVar2[1];
        if (uVar1 <= uVar5) {
          _memset((void *)(puVar2[2] + uVar1 * 4),0,(uVar5 - uVar1) * 4 + 4);
          puVar2[1] = uVar5 + 1;
        }
        puVar3 = (undefined4 *)FUN_001a84b2(*(undefined4 *)(local_10 + puVar2[2]),param_1);
      }
      else {
        puVar3 = (undefined4 *)FUN_001a7f7c(puVar2,uVar5);
        puVar3 = (undefined4 *)FUN_001a84b2(*puVar3,param_1);
      }
      if (puVar3 != (undefined4 *)0x0) {
        puVar4 = puVar3;
        do {
          *param_1 = *puVar4;
          puVar4 = puVar4 + 1;
          param_1 = param_1 + 1;
        } while (puVar4 != puVar3 + 4);
        return puVar3;
      }
      uVar5 = uVar5 - 1;
      local_10 = local_10 + -4;
    } while (param_3 <= (int)uVar5);
  }
  ((int (*)())FUN_00185344)(param_1);
  puVar2 = *(uint **)(param_4 + 0x3f8);
  if (param_2 < *puVar2) {
    uVar5 = puVar2[1];
    if (uVar5 <= param_2) {
      _memset((void *)(puVar2[2] + uVar5 * 4),0,(param_2 - uVar5) * 4 + 4);
      puVar2[1] = param_2 + 1;
    }
    puVar3 = (undefined4 *)(puVar2[2] + param_2 * 4);
  }
  else {
    puVar3 = (undefined4 *)FUN_001a7f7c(puVar2,param_2);
  }
  FUN_001a89d8(*puVar3,param_1);
  return (undefined4 *)0x0;
}

/* FUN_0018615e @ 0x18615e (287 bytes) */
int FUN_0018615e(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  
  *(undefined4 *)(*(int *)(param_1 + 0x134) + 4) = param_3;
  **(undefined4 **)(param_1 + 0x134) = param_2;
  puVar4 = (undefined4 *)
           FUN_001a84b2(*(undefined4 *)(param_1 + 0x128),*(undefined4 *)(param_1 + 0x134));
  if (puVar4 != (undefined4 *)0x0) {
    return puVar4;
  }
  uVar1 = *(undefined4 *)(param_1 + 0xbc);
  puVar5 = (undefined4 *)FUN_001a7bca(uVar1,0x2c);
  *puVar5 = uVar1;
  puVar4 = puVar5 + 1;
  *(undefined1 *)(puVar5 + 3) = 0;
  *(undefined1 *)((int)puVar5 + 0xd) = 0;
  puVar5[4] = 0;
  puVar5[5] = 4;
  *(undefined1 *)(puVar5 + 7) = 0;
  puVar5[8] = 0;
  puVar5[1] = param_2;
  puVar5[2] = param_3;
  FUN_001a89d8(*(undefined4 *)(param_1 + 0x128),puVar4);
  FUN_001a89d8(*(undefined4 *)(param_1 + 0x124),puVar4);
  puVar2 = *(uint **)(param_1 + 0x11c);
  uVar3 = puVar2[1];
  if (uVar3 < *puVar2) {
    _memset((void *)(uVar3 * 4 + puVar2[2]),0,4);
    puVar2[1] = uVar3 + 1;
    piVar6 = (int *)(uVar3 * 4 + puVar2[2]);
  }
  else {
    piVar6 = (int *)FUN_001a7f7c(puVar2,uVar3);
  }
  *piVar6 = (int)puVar4;
  return puVar4;
}

/* FUN_0018627e @ 0x18627e (728 bytes) */
int FUN_0018627e(param_1)
  undefined4 *param_1;
{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  int iVar9;
  int local_24;
  undefined4 local_10;
  
  iVar6 = param_1[0x2c];
  if ((*(byte *)(iVar6 + 0x15) & 2) == 0) {
    iVar6 = 0;
    do {
      param_1[4] = 1;
      iVar6 = iVar6 + 1;
      param_1 = param_1 + 1;
    } while (iVar6 != 4);
    return;
  }
  puVar2 = *(uint **)(*(int *)(iVar6 + 0x8c + *(int *)(iVar6 + 0x84) * 0x18) + 0x2c);
  uVar3 = puVar2[1];
  uVar1 = uVar3 - 1;
  if (uVar1 < *puVar2) {
    if (uVar3 <= uVar1) {
      _memset((void *)(puVar2[2] + uVar3 * 4),0,(uVar1 - uVar3) * 4 + 4);
      puVar2[1] = uVar3;
      iVar6 = param_1[0x2c];
    }
    piVar7 = (int *)(puVar2[2] + uVar1 * 4);
  }
  else {
    piVar7 = (int *)FUN_001a7f7c(puVar2,uVar1);
    iVar6 = param_1[0x2c];
  }
  iVar9 = *piVar7;
  iVar6 = FUN_0010b0f4(iVar6,0);
  local_10 = *(undefined4 *)(iVar6 + 0x10);
  local_24 = 0;
  puVar8 = param_1;
  do {
    uVar4 = *(undefined4 *)(iVar9 + 0x20);
    if (*(char *)((int)&local_10 + local_24) == '\x01') {
      cVar5 = FUN_00186a7c(*puVar8,uVar4);
      if (cVar5 != '\0') {
        cVar5 = (**(code **)(*(int *)param_1[0x2c] + 100))((int *)param_1[0x2c]);
        if (cVar5 == '\0') {
          cVar5 = FUN_0011902c(*(undefined4 *)(*(int *)(param_1[0x2c] + 0x88) + 8),param_1[0x8e]);
          if (cVar5 == '\0') {
LAB_00186404:
            cVar5 = FUN_00119104(*(undefined4 *)(*(int *)(param_1[0x2c] + 0x88) + 8),param_1[0x8e]);
            if (cVar5 == '\0') goto LAB_0018630a;
          }
          else {
            cVar5 = FUN_0011913a(*(undefined4 *)(*(int *)(param_1[0x2c] + 0x88) + 8),param_1[0x8e]);
            if (cVar5 != '\0') goto LAB_00186404;
          }
          cVar5 = FUN_000e1402(param_1[0x8e],0x30);
          if ((cVar5 == '\0') || (local_24 != 3)) {
            cVar5 = FUN_00119562(param_1[0x8e],param_1[0x2c]);
            if (cVar5 == '\0') {
              piVar7 = (int *)(*(int *)(param_1[0x8e] + 0x3f4) + 0xa8);
              *piVar7 = *piVar7 + 1;
              *(undefined1 *)(local_24 + 0x9c + param_1[0x2c]) = 0;
            }
          }
        }
      }
    }
LAB_0018630a:
    puVar8[4] = uVar4;
    puVar8[0x18] = *(undefined4 *)(iVar9 + 0x70);
    puVar8[0x24] = *(undefined4 *)(iVar9 + 0xa0);
    local_24 = local_24 + 1;
    iVar9 = iVar9 + 4;
    puVar8 = puVar8 + 1;
    if (local_24 == 4) {
      cVar5 = FUN_000f59aa(param_1[0x2c]);
      if (cVar5 == '\0') {
        cVar5 = FUN_0010b1aa(param_1[0x2c]);
        if (cVar5 == '\0') {
          piVar7 = (int *)(*(int *)(param_1[0x8e] + 0x3f4) + 0xa8);
          *piVar7 = *piVar7 + 1;
          iVar6 = param_1[0x2c];
          FUN_0010ba02(iVar6,*(undefined4 *)(iVar6 + 0x84),0,0,param_1[0x8e]);
          *(int *)(iVar6 + 0x84) = *(int *)(iVar6 + 0x84) + -1;
          *(uint *)(iVar6 + 0x14) = *(uint *)(iVar6 + 0x14) & 0xfffffdff;
          return;
        }
      }
      return;
    }
  } while( true );
}

/* FUN_00186556 @ 0x186556 (1318 bytes) */
int FUN_00186556(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint param_2;
  undefined4 param_3;
  int *param_4;
  undefined4 param_5;
{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  
  cVar4 = FUN_000e1402(*(undefined4 *)(param_1 + 8),7);
  if (cVar4 == '\0') {
    return 0;
  }
  if (*(int *)(*(int *)(param_1 + 8) + 0x388) <= *(int *)(param_1 + 0x14c)) {
    return 0;
  }
  FUN_00182e78(*param_4,param_2,param_3,param_5);
  ((int (*)())FUN_00184224)(*param_4);
  iVar5 = *param_4;
  if (*(int *)(*(int *)(*(int *)(iVar5 + 0xb0) + 0x88) + 8) != 0x8e) {
    cVar4 = ((int (*)())FUN_00184a98)(iVar5);
    if (cVar4 == '\0') {
      iVar5 = *param_4;
    }
    else {
      cVar4 = FUN_00125e68(param_1,*(undefined4 *)(*param_4 + 0xb0),param_5);
      if (cVar4 != '\0') {
        return 1;
      }
      iVar5 = *param_4;
    }
  }
  cVar4 = ((int (*)())FUN_0018396c)(iVar5);
  if (cVar4 != '\0') {
    return 1;
  }
  FUN_0019345e(*param_4);
  cVar4 = ((int (*)())FUN_0018372a)(*param_4);
  if (cVar4 != '\0') {
    ((int (*)())FUN_00184a5a)(*param_4);
  }
  iVar5 = ((int (*)())FUN_00186006)(*param_4,param_2,param_3,param_1);
  ((int (*)())FUN_0018627e)(*param_4);
  ((int (*)())FUN_00183630)(*param_4);
  iVar6 = ((int (*)())FUN_00184d36)(*param_4,param_2,param_3,param_1);
  if (iVar6 != 0) {
    cVar4 = ((int (*)())FUN_00183eb2)(iVar6,*(undefined4 *)(*param_4 + 0xb0),param_5,param_1);
    if (cVar4 == '\0') {
      return 0;
    }
    *param_4 = iVar6;
    cVar4 = (**(code **)(**(int **)(iVar6 + 0xb0) + 100))(*(int **)(iVar6 + 0xb0));
    if (cVar4 == '\0') {
      iVar5 = *(int *)(*param_4 + 0xb0);
      if (*(int *)(param_1 + 0x46c) < *(int *)(iVar5 + 0x160)) {
        *(int *)(iVar5 + 0x160) = *(int *)(iVar5 + 0x160) + 1;
        return 1;
      }
      *(int *)(iVar5 + 0x160) = *(int *)(param_1 + 0x46c) + 1;
      return 1;
    }
    return 1;
  }
  cVar4 = (**(code **)(**(int **)(*param_4 + 0xb0) + 100))(*(int **)(*param_4 + 0xb0));
  if ((((cVar4 == '\0') &&
       (cVar4 = (**(code **)(**(int **)(*param_4 + 0xb0) + 0x68))(*(int **)(*param_4 + 0xb0)),
       cVar4 == '\0')) && (cVar4 = ((int (*)())FUN_001833e6)(*param_4), cVar4 == '\0')) &&
     (cVar4 = FUN_000e1402(*(undefined4 *)(param_1 + 8),8), cVar4 != '\0')) {
    iVar6 = ((int (*)())FUN_00184c7c)(*param_4,param_2,param_3,param_1);
    if ((iVar6 == 0) || (cVar4 = ((int (*)())FUN_00183fc0)(*param_4,iVar6), cVar4 == '\0')) {
      iVar6 = *param_4;
      piVar3 = *(int **)(iVar6 + 0xb0);
      if (piVar3[0x20] == 0) goto LAB_0018675b;
      cVar4 = FUN_0012dfd8(piVar3[0x26]);
      if (((cVar4 != '\0') && ((*(byte *)(piVar3 + 5) & 2) == 0)) &&
         (cVar4 = (**(code **)(*piVar3 + 0x50))(piVar3), cVar4 == '\0')) {
        puVar1 = *(uint **)(param_1 + 0x400);
        if (param_2 < *puVar1) {
          uVar2 = puVar1[1];
          if (uVar2 <= param_2) {
            _memset((void *)(puVar1[2] + uVar2 * 4),0,(param_2 - uVar2) * 4 + 4);
            puVar1[1] = param_2 + 1;
          }
          puVar7 = (undefined4 *)(puVar1[2] + param_2 * 4);
        }
        else {
          puVar7 = (undefined4 *)FUN_001a7f7c(puVar1,param_2);
        }
        FUN_001a89d8(*puVar7,*param_4);
        iVar6 = *param_4;
        goto LAB_0018675b;
      }
    }
    else {
      iVar6 = *(int *)(*param_4 + 0xb0);
      iVar8 = FUN_0012a37e(*(undefined4 *)(iVar6 + 0xa4),*(undefined4 *)(param_1 + 0x394),
                           *(undefined4 *)(param_1 + 8));
      if ((iVar6 == *(int *)(iVar8 + 0xb0)) &&
         (cVar4 = FUN_00125e68(param_1,*(undefined4 *)(*param_4 + 0xb0),param_5), cVar4 != '\0')) {
        return 1;
      }
    }
  }
  iVar6 = *param_4;
LAB_0018675b:
  cVar4 = (**(code **)(**(int **)(iVar6 + 0xb0) + 100))(*(int **)(iVar6 + 0xb0));
  if ((((cVar4 == '\0') &&
       (cVar4 = (**(code **)(**(int **)(*param_4 + 0xb0) + 0x68))(*(int **)(*param_4 + 0xb0)),
       cVar4 == '\0')) && (cVar4 = ((int (*)())FUN_001833e6)(*param_4), cVar4 == '\0')) &&
     (((iVar5 != 0 && (cVar4 = ((int (*)())FUN_00183a90)(*param_4,iVar5), cVar4 != '\0')) ||
      (cVar4 = ((int (*)())FUN_00184df0)(*param_4,param_2,param_3), cVar4 != '\0')))) {
    iVar5 = *(int *)(*param_4 + 0xb0);
    iVar6 = FUN_0012a37e(*(undefined4 *)(iVar5 + 0xa4),*(undefined4 *)(param_1 + 0x394),
                         *(undefined4 *)(param_1 + 8));
    if ((iVar5 == *(int *)(iVar6 + 0xb0)) &&
       (cVar4 = FUN_00125e68(param_1,iVar5,param_5), cVar4 != '\0')) {
      return 1;
    }
  }
  cVar4 = (**(code **)(**(int **)(*param_4 + 0xb0) + 0x68))(*(int **)(*param_4 + 0xb0));
  if (cVar4 != '\0') {
    return 0;
  }
  puVar1 = *(uint **)(param_1 + 0x3fc);
  if (param_2 < *puVar1) {
    uVar2 = puVar1[1];
    if (uVar2 <= param_2) {
      _memset((void *)(puVar1[2] + uVar2 * 4),0,(param_2 - uVar2) * 4 + 4);
      puVar1[1] = param_2 + 1;
    }
    puVar7 = (undefined4 *)(puVar1[2] + param_2 * 4);
  }
  else {
    puVar7 = (undefined4 *)FUN_001a7f7c(puVar1,param_2);
  }
  FUN_001a89d8(*puVar7,*param_4);
  return 0;
}

