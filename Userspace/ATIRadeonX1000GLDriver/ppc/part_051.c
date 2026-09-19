#include "decls.h"

/* FUN_00195424 @ 0x195424 (56 bytes) */
int FUN_00195424(param_1)
  uint param_1;
{
  return ((param_1 >> 8 & 0xff) == 0) << 2 |
         ((param_1 >> 0x10 & 0xff) == 0) << 1 | param_1 >> 0x18 == 0;
}

/* FUN_0019545c @ 0x19545c (20 bytes) */
int FUN_0019545c(param_1, param_2)
  uint param_1;
  int param_2;
{
  return param_1 | (uint)(param_2 != 0) * 2;
}

/* FUN_00195474 @ 0x195474 (256 bytes) */
int FUN_00195474(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = (**(code **)(*param_2 + 0x14))(param_2);
  if (iVar2 != 0) {
    param_1[6] = 1;
  }
  iVar2 = param_1[0x18];
  (**(code **)(*param_2 + 0x44))(param_2,param_1[4]);
  param_1[6] = 0;
  if (param_2[0x37] != 0) {
    if (iVar2 == param_1[0x18]) {
      iVar2 = param_2[0x34];
      iVar4 = 0;
      for (uVar3 = 1; uVar3 <= *(uint *)(iVar2 + 4); uVar3 = uVar3 + 1) {
        iVar1 = *(int *)(*(int *)(iVar2 + 8) + iVar4);
        if (iVar1 != 0) {
          *(undefined4 *)(iVar1 + 0xdc) = 1;
        }
        iVar4 = iVar4 + 4;
      }
    }
    if (param_1[0x23] == 1) {
      (**(code **)(*param_1 + 0x148))(param_1);
    }
  }
  return;
}

/* FUN_00195574 @ 0x195574 (4 bytes) */
int FUN_00195574()
{
  return;
}

/* FUN_00195578 @ 0x195578 (8 bytes) */
int FUN_00195578()
{
  return 1;
}

/* FUN_00195580 @ 0x195580 (4 bytes) */
int FUN_00195580()
{
  return;
}

/* FUN_00195584 @ 0x195584 (12 bytes) */
int FUN_00195584(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  *param_2 = 0x258f;
  return;
}

/* FUN_00195590 @ 0x195590 (48 bytes) */
int FUN_00195590(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_2 + 4);
  uVar2 = uVar1 >> 0x17 & 0xff;
  if (uVar2 == 0) {
    return 0;
  }
  return uVar1 >> 7 & 0xffff | uVar1 >> 8 & 0x800000 | (uVar2 - 0x40) * 0x10000;
}

/* FUN_001955c0 @ 0x1955c0 (16 bytes) */
int FUN_001955c0(param_1)
  int *param_1;
{
                    
                    
  (**(code **)(*param_1 + 0x104))();
  return;
}

/* FUN_001955d0 @ 0x1955d0 (12 bytes) */
int FUN_001955d0(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  FUN_000e2c78(param_1,param_5,param_4);
  return;
}

/* FUN_001955dc @ 0x1955dc (28 bytes) */
int FUN_001955dc(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  FUN_000e2c78(param_2,param_1,param_3);
  return;
}

/* FUN_001955f8 @ 0x1955f8 (36 bytes) */
int FUN_001955f8(param_1)
  int param_1;
{
  return *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x30c) + 0x40) + 1 < *(int *)(param_1 + 0x60);
}

/* FUN_0019561c @ 0x19561c (8 bytes) */
int FUN_0019561c()
{
  return 0;
}

/* FUN_00195624 @ 0x195624 (4 bytes) */
int FUN_00195624()
{
  return;
}

/* FUN_00195628 @ 0x195628 (4 bytes) */
int FUN_00195628()
{
  return;
}

/* FUN_0019562c @ 0x19562c (4 bytes) */
int FUN_0019562c()
{
  return;
}

/* FUN_00195630 @ 0x195630 (4 bytes) */
int FUN_00195630()
{
  return;
}

/* FUN_00195634 @ 0x195634 (4 bytes) */
int FUN_00195634()
{
  return;
}

/* FUN_00195638 @ 0x195638 (4 bytes) */
int FUN_00195638()
{
  return;
}

/* FUN_0019563c @ 0x19563c (4 bytes) */
int FUN_0019563c()
{
  return;
}

/* FUN_00195640 @ 0x195640 (4 bytes) */
int FUN_00195640()
{
  return;
}

/* FUN_00195650 @ 0x195650 (76 bytes) */
int FUN_00195650(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  param_2 = param_2 * 0x38;
  if ((*(uint *)(PTR_DAT_001e913c + param_2) & 2) != 0) {
    return *(undefined4 *)(PTR_DAT_001e913c + param_2 + 0xc);
  }
  if (*(int *)(PTR_DAT_001e913c + param_2 + 4) == 0) {
    return *(undefined4 *)(PTR_DAT_001e913c + param_2 + 0xc);
  }
  return *(undefined4 *)(PTR_DAT_001e913c + *(int *)(PTR_DAT_001e913c + param_2 + 4) * 0x38 + 0xc);
}

/* FUN_0019569c @ 0x19569c (76 bytes) */
int FUN_0019569c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  param_2 = param_2 * 0x38;
  if ((*(uint *)(PTR_DAT_001e913c + param_2) & 2) == 0) {
    return *(undefined4 *)(PTR_DAT_001e913c + param_2 + 0xc);
  }
  if (*(int *)(PTR_DAT_001e913c + param_2 + 4) == 0) {
    return *(undefined4 *)(PTR_DAT_001e913c + param_2 + 0xc);
  }
  return *(undefined4 *)(PTR_DAT_001e913c + *(int *)(PTR_DAT_001e913c + param_2 + 4) * 0x38 + 0xc);
}

/* FUN_001956e8 @ 0x1956e8 (16 bytes) */
int FUN_001956e8(param_1)
  int *param_1;
{
                    
                    
  (**(code **)(*param_1 + 0x38))();
  return;
}

/* FUN_001956f8 @ 0x1956f8 (4 bytes) */
int FUN_001956f8()
{
  return;
}

/* FUN_001956fc @ 0x1956fc (4 bytes) */
int FUN_001956fc()
{
  return;
}

/* FUN_00195700 @ 0x195700 (4 bytes) */
int FUN_00195700()
{
  return;
}

/* FUN_00195704 @ 0x195704 (4 bytes) */
int FUN_00195704()
{
  return;
}

/* FUN_00195708 @ 0x195708 (4 bytes) */
int FUN_00195708()
{
  return;
}

/* FUN_0019570c @ 0x19570c (136 bytes) */
int FUN_0019570c(param_1)
  int param_1;
{
  int iVar1;
  
  *(undefined4 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58)) = 3;
  iVar1 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
  *(undefined2 *)(iVar1 + 0x12) = 0x8000;
  *(undefined2 *)(iVar1 + 0xe) = 0x8000;
  *(undefined2 *)(iVar1 + 0x10) = 0x8000;
  *(undefined1 *)(iVar1 + 0x2c) = 0x14;
  *(undefined1 *)(iVar1 + 0x31) = 0;
  *(undefined1 *)(iVar1 + 0x2a) = 0x14;
  *(undefined1 *)(iVar1 + 0x2b) = 0x14;
  *(undefined2 *)(iVar1 + 0x1e) = 0x8000;
  *(undefined2 *)(iVar1 + 0x1a) = 0x8000;
  *(undefined2 *)(iVar1 + 0x1c) = 0x8000;
  *(undefined1 *)(iVar1 + 0x40) = 0;
  *(undefined1 *)(iVar1 + 0x3b) = 0x10;
  *(undefined1 *)(iVar1 + 0x39) = 0x10;
  *(undefined1 *)(iVar1 + 0x3a) = 0x10;
  return;
}

/* FUN_00195794 @ 0x195794 (68 bytes) */
int FUN_00195794(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  param_2 = param_2 * 0x48;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + param_2) = 1;
  *(undefined1 *)(param_2 + *(int *)(param_1 + 0x58) + 10) = param_3;
  *(undefined1 *)(param_2 + *(int *)(param_1 + 0x58) + 0xb) = param_4;
  *(undefined2 *)(param_2 + *(int *)(param_1 + 0x58) + 6) = param_5;
  *(undefined1 *)(param_2 + *(int *)(param_1 + 0x58) + 0xd) = param_6;
  return;
}

/* FUN_001957d8 @ 0x1957d8 (68 bytes) */
int FUN_001957d8(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  param_2 = param_2 * 0x48;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + param_2) = 1;
  *(undefined1 *)(param_2 + *(int *)(param_1 + 0x58) + 8) = param_3;
  *(undefined1 *)(param_2 + *(int *)(param_1 + 0x58) + 9) = param_4;
  *(undefined2 *)(param_2 + *(int *)(param_1 + 0x58) + 4) = param_5;
  *(undefined1 *)(param_2 + *(int *)(param_1 + 0x58) + 0xc) = param_6;
  return;
}

/* FUN_0019581c @ 0x19581c (260 bytes) */
int FUN_0019581c(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  uint param_5;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_5 & 0xffffff00 | 4;
  iVar1 = FUN_000f2d18(uVar2,DAT_001b2ac0);
  if (iVar1 == 0) {
    iVar1 = FUN_000f2d18(uVar2,DAT_001b2abc);
    if (iVar1 == 0) {
      iVar1 = FUN_000f2d18(uVar2,DAT_001b2ab8);
      if (iVar1 == 0) {
        iVar1 = FUN_000f2d18(uVar2,DAT_001b2ab4);
        if (iVar1 == 0) {
          iVar1 = FUN_000f2d18(uVar2,DAT_001b2ac4);
          if (iVar1 != 0) {
            *(undefined4 *)(param_2 * 4 + param_3) = 0x13;
          }
        }
        else {
          *(undefined4 *)(param_2 * 4 + param_3) = 0x12;
        }
      }
      else {
        *(undefined4 *)(param_2 * 4 + param_3) = 0x11;
      }
    }
    else {
      *(undefined4 *)(param_2 * 4 + param_3) = 0x10;
    }
  }
  else {
    *(undefined4 *)(param_2 * 4 + param_3) = 0xf;
  }
  return;
}

/* FUN_00195920 @ 0x195920 (108 bytes) */
int FUN_00195920(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  if (param_5 == '\0') {
    *(undefined4 *)(param_2 * 4 + param_3) = 0xc;
    return;
  }
  if (param_5 == '\x01') {
    *(undefined4 *)(param_2 * 4 + param_3) = 0xd;
    return;
  }
  if (param_5 == '\x02') {
    *(undefined4 *)(param_2 * 4 + param_3) = 0xe;
    return;
  }
  if ((param_5 != '\x03') && (param_5 != '\x04')) {
    return;
  }
  *(undefined4 *)(param_2 * 4 + param_3) = 0xf;
  return;
}

/* FUN_0019598c @ 0x19598c (112 bytes) */
int FUN_0019598c(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  uint param_6;
{
  int iVar1;
  
  iVar1 = FUN_000f2d18(param_6 & 0xffffff00 | 4,DAT_001b2ac4);
  if (iVar1 == 0) {
    *(int *)(param_2 * 4 + param_3) = param_5 + 0x1d;
  }
  else {
    *(int *)(param_2 * 4 + param_3) = param_5 + 0xc;
  }
  return;
}

/* FUN_001959fc @ 0x1959fc (336 bytes) */
int FUN_001959fc(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  uint param_6;
{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_6 & 0xffffff00 | 4;
  iVar1 = FUN_000f2d18(uVar2,DAT_001b2ac0);
  if (iVar1 != 0) {
    *(int *)(param_2 * 4 + param_3) = param_5 << 2;
    return;
  }
  iVar1 = FUN_000f2d18(uVar2,DAT_001b2abc);
  if (iVar1 != 0) {
    *(int *)(param_3 + param_2 * 4) = param_5 * 4 + 1;
    return;
  }
  iVar1 = FUN_000f2d18(uVar2,DAT_001b2ab8);
  if (iVar1 != 0) {
    *(int *)(param_3 + param_2 * 4) = param_5 * 4 + 2;
    return;
  }
  iVar1 = FUN_000f2d18(uVar2,DAT_001b2ab4);
  if (iVar1 != 0) {
    *(int *)(param_3 + param_2 * 4) = param_5 * 4 + 3;
    return;
  }
  uVar2 = param_6 >> 0x18;
  if (uVar2 == 1) {
LAB_00195b1c:
    *(int *)(param_2 * 4 + param_3) = param_5 + 0x17;
  }
  else {
    if (uVar2 != 3) {
      if ((uVar2 == 2) || ((param_6 >> 0x10 & 0xff) == 0)) {
        *(int *)(param_2 * 4 + param_3) = param_5 + 0x1a;
        return;
      }
      if ((param_6 >> 8 & 0xff) == 0) goto LAB_00195b1c;
    }
    *(int *)(param_2 * 4 + param_3) = param_5 + 0x1d;
  }
  return;
}

/* FUN_00195b4c @ 0x195b4c (16 bytes) */
int FUN_00195b4c(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  *(int *)(param_2 * 4 + param_3) = param_5 + 9;
  return;
}

/* FUN_00195b5c @ 0x195b5c (84 bytes) */
int FUN_00195b5c(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  int param_6;
{
  if (param_6 == '\0') {
    *(int *)(param_3 + param_2 * 4) = param_5 * 3;
    return;
  }
  if (param_6 == '\x01') {
    *(int *)(param_3 + param_2 * 4) = param_5 * 3 + 1;
    return;
  }
  if (param_6 != '\x02') {
    return;
  }
  *(int *)(param_3 + param_2 * 4) = param_5 * 3 + 2;
  return;
}

/* FUN_00195bb0 @ 0x195bb0 (316 bytes) */
int FUN_00195bb0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 1;
  iVar2 = param_3;
  do {
    if (((param_2 >> (uVar3 & 0x3f) & 1U) != 0) && (-1 < *(int *)(iVar2 + 4))) {
      if (uVar3 == 1) {
        *(short *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0xe) =
             (short)*(undefined4 *)(param_3 + 4);
      }
      else if (uVar3 == 2) {
        *(short *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x10) =
             (short)*(undefined4 *)(param_3 + 8);
      }
      else if (uVar3 == 3) {
        *(short *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x12) =
             (short)*(undefined4 *)(param_3 + 0xc);
      }
    }
    bVar1 = uVar3 != 3;
    iVar2 = iVar2 + 4;
    uVar3 = uVar3 + 1;
  } while (bVar1);
  uVar3 = 1;
  iVar2 = param_5;
  do {
    if (((param_4 >> (uVar3 & 0x3f) & 1U) != 0) && (-1 < *(int *)(iVar2 + 4))) {
      if (uVar3 == 1) {
        *(short *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x1a) =
             (short)*(undefined4 *)(param_5 + 4);
      }
      else if (uVar3 == 2) {
        *(short *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x1c) =
             (short)*(undefined4 *)(param_5 + 8);
      }
      else if (uVar3 == 3) {
        *(short *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x1e) =
             (short)*(undefined4 *)(param_5 + 0xc);
      }
    }
    bVar1 = uVar3 != 3;
    iVar2 = iVar2 + 4;
    uVar3 = uVar3 + 1;
  } while (bVar1);
  return;
}

/* FUN_00195cec @ 0x195cec (644 bytes) */
int FUN_00195cec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  
  uVar3 = (undefined1)param_2;
  *(undefined4 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58)) = 3;
  if (param_2 != -1) goto LAB_00195f08;
  if (param_3 == 0x31) {
LAB_00195e0c:
    uVar3 = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3a) = 0x11;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3b) = 0x10;
    goto LAB_00195f08;
  }
  if (param_3 < 0x32) {
    if (param_3 != 0x13) {
      if (param_3 == 0x25) {
LAB_00195e48:
        iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
        uVar3 = *(undefined1 *)(iVar2 + 0x39);
        *(undefined1 *)(iVar2 + 0x39) = *(undefined1 *)(iVar2 + 0x3a);
        iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
        uVar1 = *(undefined1 *)(iVar2 + 0x3c);
        *(undefined1 *)(iVar4 + 0x3c) = *(undefined1 *)(iVar4 + 0x3d);
        iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
        *(undefined1 *)(iVar2 + 0x3a) = *(undefined1 *)(iVar2 + 0x3b);
        iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
        *(undefined1 *)(iVar2 + 0x3d) = *(undefined1 *)(iVar2 + 0x3e);
        *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3b) = uVar3;
        *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3e) = uVar1;
        if (param_3 == 0x9d) {
          uVar3 = 5;
        }
        else {
          uVar3 = 6;
        }
        goto LAB_00195f08;
      }
      if (param_3 != 0x12) goto LAB_00195d6c;
LAB_00195d94:
      uVar3 = 0;
      iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
      *(undefined1 *)(iVar2 + 0x3b) = *(undefined1 *)(iVar2 + 0x3a);
      iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
      *(undefined1 *)(iVar2 + 0x3e) = *(undefined1 *)(iVar2 + 0x3d);
      *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3a) = 0x11;
      *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3d) = 0;
      goto LAB_00195f08;
    }
  }
  else if (param_3 != 0x36) {
    if (param_3 < 0x37) {
      if (param_3 == 0x34) goto LAB_00195d94;
    }
    else {
      if (param_3 == 0x66) goto LAB_00195e0c;
      if (param_3 == 0x9d) goto LAB_00195e48;
    }
LAB_00195d6c:
    uVar3 = 0xff;
    goto LAB_00195f08;
  }
  uVar3 = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3b) = 0x10;
LAB_00195f08:
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x40) = uVar3;
  if (*(int *)(param_4 + 0x120) != 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x42) = 1;
  }
  iVar4 = *(int *)(param_1 + 0x60);
  iVar2 = *(int *)(param_1 + 0x58);
  uVar3 = FUN_0019533c(*(undefined4 *)(param_4 + 0x124));
  *(undefined1 *)(iVar4 * 0x48 + iVar2 + 0x41) = uVar3;
  return;
}

/* FUN_00195f70 @ 0x195f70 (28 bytes) */
int FUN_00195f70(param_1)
  int param_1;
{
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x20) = 1;
  return;
}

/* FUN_00195f8c @ 0x195f8c (76 bytes) */
int FUN_00195f8c(param_1)
  int param_1;
{
  int iVar1;
  
  *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
  if (*(int *)(param_1 + 100) == *(int *)(param_1 + 0x6c)) {
    iVar1 = *(int *)(param_1 + 0x68);
    if (iVar1 != *(int *)(param_1 + 0x70)) {
      *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + 1;
    }
  }
  else {
    iVar1 = *(int *)(param_1 + 0x68);
  }
  *(int *)(param_1 + 0x70) = iVar1;
  *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 100);
  return;
}

/* FUN_00195fd8 @ 0x195fd8 (152 bytes) */
int FUN_00195fd8(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  *(undefined2 *)(*(int *)(param_1 + 0x58) + 0x24) = param_2;
  iVar3 = *(int *)(param_1 + 0x58);
  *(int *)(iVar3 + 8) = *(int *)(param_1 + 0x60) + -1;
  *(undefined2 *)(iVar3 + 0x14) = 1;
  if ((*(int *)(param_1 + 100) == *(int *)(param_1 + 0x6c)) &&
     (*(int *)(param_1 + 0x68) != *(int *)(param_1 + 0x70))) {
    iVar2 = *(int *)(param_1 + 0x7c) + 1;
    *(int *)(param_1 + 0x7c) = iVar2;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x7c);
  }
  *(short *)(iVar3 + 0x1e) = (short)*(int *)(param_1 + 100) + (short)iVar2;
  *(undefined1 *)(iVar3 + 0xd) = 6;
  *(undefined1 *)(iVar3 + 0xc) = 0;
  *(short *)(iVar3 + 0x1c) = (short)*(undefined4 *)(param_1 + 100);
  *(short *)(iVar3 + 0x1a) = (short)*(undefined4 *)(param_1 + 0x68);
  *(short *)(iVar3 + 0x16) = (short)*(undefined4 *)(param_1 + 0x88) + 1;
  uVar1 = *(undefined4 *)(param_1 + 0x74);
  *(undefined2 *)(iVar3 + 0x22) = param_3;
  *(short *)(iVar3 + 0x18) = (short)uVar1;
  return;
}

/* FUN_00196070 @ 0x196070 (320 bytes) */
int FUN_00196070(param_1)
  int *param_1;
{
  void *pvVar1;
  
  if (param_1[0x1d] == 0) {
    pvVar1 = (void *)(param_1[0x16] + param_1[0x18] * 0x48);
    _memcpy((void *)((int)pvVar1 + 0x48),pvVar1,0x48);
    _memset((void *)(param_1[0x18] * 0x48 + param_1[0x16]),0,0x48);
    param_1[0x18] = 2;
    param_1[0x1d] = 1;
    (**(code **)(*param_1 + 0xc4))(param_1,1,0,0,0,0);
    (**(code **)(*param_1 + 200))(param_1,1,0,0,0,0);
    (**(code **)(*param_1 + 0xcc))(param_1,1,0xf);
    (**(code **)(*param_1 + 0xd0))(param_1,1,0xf);
  }
  param_1[0x21] = 1;
  param_1[0x20] = 1;
  param_1[0x18] = param_1[0x18] + 1;
  return;
}

/* FUN_001961c8 @ 0x1961c8 (296 bytes) */
int FUN_001961c8(param_1)
  int *param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  *(int *)(param_1[0x17] + 0x93b8) = param_1[0x24];
  *(int *)(param_1[0x17] + 0x9364) = *(int *)(*(int *)(param_1[3] + 0x6c4) + 0x7c) + 1;
  iVar2 = *(int *)(*(int *)(param_1[3] + 0x6c4) + 0x80);
  *(undefined4 *)(param_1[0x17] + 0x9368) = *(undefined4 *)(*(int *)(param_1[3] + 0x6c4) + 0x84);
  uVar3 = iVar2 + 1;
  uVar1 = *(uint *)(param_1[0x17] + 0x9364);
  if (uVar3 < uVar1) {
    uVar3 = uVar1;
  }
  *(uint *)(param_1[0x17] + 0x9364) = uVar3;
  iVar4 = 0;
  iVar2 = FUN_0013061c(*(undefined4 *)(param_1[3] + 0x6c4),0);
  if (iVar2 != 0) {
    iVar4 = iVar2 + -1;
  }
  if (param_1[0x18] == param_1[0x1d] + 1) {
    (**(code **)(*param_1 + 0xbc))(param_1);
    (**(code **)(*param_1 + 0xc0))(param_1);
    (**(code **)(*param_1 + 0x15c))(param_1);
  }
                    
                    
  (**(code **)(*param_1 + 0x144))(param_1,param_1[0x1e],iVar4);
  return;
}

/* FUN_001962f0 @ 0x1962f0 (128 bytes) */
int FUN_001962f0(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  
  uVar1 = FUN_00112f54(0x31);
  *(undefined4 *)(param_2 + 0x88) = uVar1;
  if (*(int *)(param_2 + 0x98) != 0x2c) {
                    
                    
    (**(code **)(*param_1 + 0x38))(param_1,param_2,param_3,param_4);
    return;
  }
  return;
}

/* FUN_00196370 @ 0x196370 (64 bytes) */
int FUN_00196370(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  if ((*(int *)(param_3 + 0x98) == 2) || (*(int *)(param_3 + 0x98) == 0xc)) {
    iVar1 = param_1[0x1e];
    if (param_1[0x1e] < param_2) {
      iVar1 = param_2;
    }
    param_1[0x1e] = iVar1;
  }
                    
                    
  (**(code **)(*param_1 + 0x88))(param_1,param_3);
  return;
}

/* FUN_001963b0 @ 0x1963b0 (236 bytes) */
int FUN_001963b0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_4 + 0x30c);
  pvVar1 = (void *)FUN_000e14e4(param_4,0x963c);
  *(void **)(param_1 + 0x5c) = pvVar1;
  _memset(pvVar1,0,0x963c);
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x54) = 3;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x60) = 1;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 1;
  *(undefined4 *)(param_1 + 0x84) = 1;
  *(int *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  **(undefined4 **)(param_1 + 0x58) = 0;
  *(int *)(*(int *)(param_1 + 0x58) + 4) = *(int *)(*(int *)(param_4 + 0x30c) + 0x40) + 1;
  *(undefined4 *)(param_1 + 0x98) = 1;
  *(undefined4 *)(param_1 + 0x94) = 1;
  return;
}

/* FUN_0019649c @ 0x19649c (128 bytes) */
int FUN_0019649c(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_00105594(param_3);
  iVar2 = (**(code **)(*piVar1 + 0x80))();
  if (*(int *)(iVar2 + 0xb4) == DAT_001b2ab0) {
    *(uint *)(*(int *)(param_1 + 0x5c) + 0x936c) =
         1 << (*(uint *)(iVar2 + 0x148) & 0x3f) | *(uint *)(*(int *)(param_1 + 0x5c) + 0x936c);
  }
  return;
}

/* FUN_0019651c @ 0x19651c (640 bytes) */
int FUN_0019651c(param_1, param_2)
  int *param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  
  uVar6 = 0;
  uVar9 = 0;
  do {
    iVar2 = FUN_001054ec(param_2,0);
    if (*(char *)(uVar9 + iVar2 + 0x10) == '\x01') {
      uVar6 = uVar6 | 1 << (uVar9 & 0x3f);
    }
    bVar1 = uVar9 != 3;
    uVar9 = uVar9 + 1;
  } while (bVar1);
  iVar2 = *(int *)(param_2 + 0x144);
  if ((iVar2 == 0x16) || (iVar2 == 0x17)) {
    pcVar7 = *(code **)(*param_1 + 0xc4);
    iVar8 = param_1[0x25];
    uVar3 = FUN_0010e40c(iVar2,*(undefined4 *)(param_2 + 0x148));
    uVar4 = thunk_FUN_00134de8(*(undefined4 *)(param_1[3] + 0x6c4),param_2);
    uVar5 = 1;
  }
  else if (iVar2 == 0x1b) {
    uVar5 = 1;
    pcVar7 = *(code **)(*param_1 + 0xc4);
    iVar8 = param_1[0x25];
    uVar3 = *(undefined4 *)(param_2 + 0x148);
    iVar2 = FUN_000d9f3c(*(undefined4 *)(param_1[3] + 0x398),0);
    if (iVar2 == 0) {
      uVar5 = 3;
    }
    uVar4 = thunk_FUN_00134de8(*(undefined4 *)(param_1[3] + 0x6c4),param_2);
  }
  else {
    if (iVar2 != 0x23) {
      pcVar7 = *(code **)(*param_1 + 200);
      uVar9 = *(uint *)(param_2 + 0x148);
      iVar2 = param_1[0x26];
      uVar3 = thunk_FUN_00134de8(*(undefined4 *)(param_1[3] + 0x6c4),param_2);
      (*pcVar7)(param_1,iVar2,uVar9,1,uVar3,(*(uint *)(param_2 + 0x13c) ^ 1) & 1);
      (**(code **)(*param_1 + 0xcc))(param_1,param_1[0x26],uVar6);
      iVar2 = param_1[3];
      param_1[0x26] = param_1[0x26] + 1;
      if (*(int *)(*(int *)(iVar2 + 0x6c4) + 0x80) < (int)uVar9) {
        *(uint *)(*(int *)(iVar2 + 0x6c4) + 0x80) = uVar9;
        iVar2 = param_1[3];
      }
      *(uint *)(*(int *)(iVar2 + 0x6c4) + 0x88) =
           1 << (uVar9 & 0x3f) | *(uint *)(*(int *)(iVar2 + 0x6c4) + 0x88);
      iVar2 = param_1[0x25];
      goto LAB_0019675c;
    }
    pcVar7 = *(code **)(*param_1 + 0xc4);
    iVar8 = param_1[0x25];
    uVar3 = *(undefined4 *)(param_2 + 0x148);
    uVar4 = thunk_FUN_00134de8(*(undefined4 *)(param_1[3] + 0x6c4),param_2);
    uVar5 = 2;
  }
  (*pcVar7)(param_1,iVar8,uVar3,uVar5,uVar4,0);
  (**(code **)(*param_1 + 0xd0))(param_1,param_1[0x25],uVar6);
  iVar2 = param_1[0x25] + 1;
  param_1[0x25] = iVar2;
LAB_0019675c:
  if (iVar2 <= param_1[0x26]) {
    iVar2 = param_1[0x26];
  }
  param_1[0x1d] = iVar2 + -1;
  param_1[0x18] = iVar2;
  return;
}

/* FUN_0019679c @ 0x19679c (188 bytes) */
int FUN_0019679c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_00105594(param_2,param_3);
  if (((((piVar1[0x20] == 0) || (iVar2 = FUN_00126760(piVar1[0x26]), iVar2 == 0)) ||
       ((piVar1[5] & 2U) != 0)) || (iVar2 = (**(code **)(*piVar1 + 0x50))(piVar1), iVar2 != 0)) &&
     (iVar2 = (**(code **)(*piVar1 + 0x50))(piVar1), iVar2 == 0)) {
    return;
  }
  thunk_FUN_00134de8(*(undefined4 *)(param_4 + 0x6c4),piVar1);
  return;
}

/* FUN_00196858 @ 0x196858 (640 bytes) */
int FUN_00196858(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int *param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
  int param_7;
{
  bool bVar1;
  bool bVar2;
  undefined1 uVar4;
  int iVar3;
  uint *puVar5;
  int iVar6;
  int in_stack_00000038;
  
  iVar6 = 1;
  bVar1 = in_stack_00000038 == 0;
  puVar5 = (uint *)(param_2 + 0x2e);
  do {
    iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar3 < iVar6) {
      return;
    }
    bVar2 = iVar6 != 1;
    if (bVar2) {
      if (iVar6 == 2) {
        if (param_3 != 0) {
          *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2b) =
               (char)*(undefined4 *)(param_4 + 8);
        }
        if (param_6 != 0) {
          *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3a) =
               (char)*(undefined4 *)(param_7 + 8);
        }
      }
      else if ((iVar6 == 3) && (bVar1)) {
        if (param_3 != 0) {
          *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2c) =
               (char)*(undefined4 *)(param_4 + 0xc);
        }
        if (param_6 != 0) {
          *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3b) =
               (char)*(undefined4 *)(param_7 + 0xc);
        }
      }
    }
    else {
      if (param_3 != 0) {
        *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2a) =
             (char)*(undefined4 *)(param_4 + 4);
      }
      if (param_6 != 0) {
        *(char *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x39) =
             (char)*(undefined4 *)(param_7 + 4);
      }
    }
    uVar4 = ((int (*)())FUN_0019545c)(*puVar5 & 1,*puVar5 >> 1 & 1);
    if (param_6 != 0) {
      if (bVar1) {
        if (!bVar2) goto LAB_001969d4;
        if (iVar6 == 2) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3d) = uVar4
          ;
        }
        else if (iVar6 == 3) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3e) = uVar4
          ;
        }
      }
      else if (iVar6 == 3) {
LAB_001969d4:
        *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x3c) = uVar4;
      }
    }
    if (param_3 != 0) {
      if (bVar2) {
        if (iVar6 == 2) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2e) = uVar4
          ;
        }
        else if ((iVar6 == 3) && (bVar1)) {
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2f) = uVar4
          ;
        }
      }
      else {
        *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2d) = uVar4;
      }
    }
    iVar6 = iVar6 + 1;
    puVar5 = puVar5 + 6;
  } while( true );
}

/* FUN_00196ad8 @ 0x196ad8 (644 bytes) */
int FUN_00196ad8(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  
  uVar3 = (undefined1)param_2;
  *(undefined4 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58)) = 3;
  if (param_2 != -1) goto LAB_00196cf4;
  if (param_3 == 0x31) {
LAB_00196bf8:
    uVar3 = 0;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2b) = 0x15;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2c) = 0x14;
    goto LAB_00196cf4;
  }
  if (param_3 < 0x32) {
    if (param_3 != 0x13) {
      if (param_3 == 0x25) {
LAB_00196c34:
        iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
        uVar3 = *(undefined1 *)(iVar2 + 0x2a);
        *(undefined1 *)(iVar2 + 0x2a) = *(undefined1 *)(iVar2 + 0x2b);
        iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
        uVar1 = *(undefined1 *)(iVar2 + 0x2d);
        *(undefined1 *)(iVar4 + 0x2d) = *(undefined1 *)(iVar4 + 0x2e);
        iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
        *(undefined1 *)(iVar2 + 0x2b) = *(undefined1 *)(iVar2 + 0x2c);
        iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
        *(undefined1 *)(iVar2 + 0x2e) = *(undefined1 *)(iVar2 + 0x2f);
        *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2c) = uVar3;
        *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2f) = uVar1;
        if (param_3 == 0x9d) {
          uVar3 = 7;
        }
        else {
          uVar3 = 8;
        }
        goto LAB_00196cf4;
      }
      if (param_3 != 0x12) goto LAB_00196b58;
LAB_00196b80:
      uVar3 = 0;
      iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
      *(undefined1 *)(iVar2 + 0x2c) = *(undefined1 *)(iVar2 + 0x2b);
      iVar2 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58);
      *(undefined1 *)(iVar2 + 0x2f) = *(undefined1 *)(iVar2 + 0x2e);
      *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2b) = 0x15;
      *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2e) = 0;
      goto LAB_00196cf4;
    }
  }
  else if (param_3 != 0x36) {
    if (param_3 < 0x37) {
      if (param_3 == 0x34) goto LAB_00196b80;
    }
    else {
      if (param_3 == 0x66) goto LAB_00196bf8;
      if (param_3 == 0x9d) goto LAB_00196c34;
    }
LAB_00196b58:
    uVar3 = 0xff;
    goto LAB_00196cf4;
  }
  uVar3 = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x2c) = 0x14;
LAB_00196cf4:
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x31) = uVar3;
  if (*(int *)(param_4 + 0x120) != 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x33) = 1;
  }
  iVar4 = *(int *)(param_1 + 0x60);
  iVar2 = *(int *)(param_1 + 0x58);
  uVar3 = FUN_0019533c(*(undefined4 *)(param_4 + 0x124));
  *(undefined1 *)(iVar4 * 0x48 + iVar2 + 0x32) = uVar3;
  return;
}

/* FUN_00196d5c @ 0x196d5c (96 bytes) */
int FUN_00196d5c(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(param_2 + 0x378);
  puVar1 = (undefined4 *)FUN_00193e18(uVar2,0xac);
  *puVar1 = uVar2;
  puVar1[1] = &PTR_FUN_001eb6a0;
  puVar1[7] = 0;
  return puVar1 + 1;
}

/* FUN_00196dbc @ 0x196dbc (64 bytes) */
int FUN_00196dbc(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e914c;
  param_1[0x16] = 0;
  *param_1 = &PTR_FUN_001eb6a0;
  param_1[0x17] = 0;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00196dfc @ 0x196dfc (64 bytes) */
int FUN_00196dfc(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e914c;
  param_1[0x16] = 0;
  *param_1 = &PTR_FUN_001eb6a0;
  param_1[0x17] = 0;
  *param_1 = puVar1 + 8;
  return;
}

/* FUN_00196e3c @ 0x196e3c (84 bytes) */
int FUN_00196e3c(param_1)
  undefined4 *param_1;
{
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  *param_1 = &PTR_FUN_001eb6a0;
  *param_1 = PTR_DAT_001e914c + 8;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  FUN_00193cc0(param_1[-1],param_1 + -1);
  return;
}

/* FUN_00196e90 @ 0x196e90 (872 bytes) */
int FUN_00196e90(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  undefined4 param_3;
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  int iVar9;
  uint local_28 [3];
  
  iVar2 = *(int *)(param_2[0x22] + 8);
  if ((((iVar2 == 0x9e) || (iVar2 == 0xa0)) || (iVar2 == 0x9f)) || (iVar9 = 1, iVar2 == 0xa1)) {
    iVar2 = FUN_001054ec(param_2,0);
    if (((*(char *)(iVar2 + 0x10) == '\0') ||
        (iVar2 = FUN_001054ec(param_2,0), *(char *)(iVar2 + 0x11) == '\0')) ||
       (iVar2 = FUN_001054ec(param_2,0), *(char *)(iVar2 + 0x12) == '\0')) {
      uVar4 = FUN_00105594(param_2,1);
      iVar2 = FUN_0018d388(param_3,uVar4,0);
      if (iVar2 == 0) {
        return 0;
      }
    }
    iVar2 = FUN_001054ec(param_2,0);
    if (*(char *)(iVar2 + 0x13) == '\0') {
      uVar4 = FUN_00105594(param_2,1);
      iVar2 = FUN_0018d388(param_3,uVar4,1);
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  else {
    for (; iVar2 = (**(code **)(*param_2 + 0x14))(param_2), iVar9 <= iVar2; iVar9 = iVar9 + 1) {
      piVar5 = (int *)FUN_00105594(param_2,iVar9);
      iVar6 = (**(code **)(*piVar5 + 0x60))();
      piVar3 = param_2;
      iVar2 = iVar9;
      if (iVar6 != 0) {
        piVar7 = (int *)FUN_00105594(piVar5,1);
        piVar3 = piVar5;
        iVar2 = 1;
        piVar5 = piVar7;
      }
      iVar2 = FUN_001054ec(piVar3,iVar2);
      FUN_000f3398(local_28,*(undefined4 *)(iVar2 + 0x10));
      uVar1 = local_28[0];
      iVar2 = (**(code **)(*piVar5 + 0x5c))(piVar5);
      if (iVar2 == 0) {
        if ((piVar5[0x26] != 0x33) || (piVar5[0x4b] == 3)) {
          if ((uVar1 & 0xffffff00) == 0) {
            if ((uVar1 & 0xff) == 0) goto LAB_001971a8;
            iVar2 = FUN_0018c7f4(param_3,piVar5,1);
          }
          else if ((uVar1 & 0xff) == 0) {
            iVar2 = FUN_0018c7f4(param_3,piVar5,0);
          }
          else {
            iVar2 = FUN_0018c980(param_3,piVar5,piVar5);
          }
joined_r0x00197160:
          if (iVar2 == 0) {
            return 0;
          }
        }
      }
      else {
        if ((uVar1 & 0xffffff00) != 0) {
          iVar2 = (**(code **)(*piVar5 + 0x14))(piVar5);
          if (iVar2 == 1) {
            uVar4 = FUN_00105594(piVar5,1);
            iVar2 = FUN_0018d388(param_3,uVar4,0);
          }
          else {
            uVar4 = FUN_00105594(piVar5,1);
            uVar8 = FUN_00105594(piVar5,2);
            iVar2 = FUN_0018cdd8(param_3,uVar4,uVar8,0);
          }
          if (iVar2 == 0) {
            return 0;
          }
        }
        if ((uVar1 & 0xff) != 0) {
          iVar2 = (**(code **)(*piVar5 + 0x14))(piVar5);
          if (iVar2 == 1) {
            uVar4 = FUN_00105594(piVar5,1);
            iVar2 = FUN_0018d388(param_3,uVar4,1);
          }
          else {
            uVar4 = FUN_00105594(piVar5,1);
            uVar8 = FUN_00105594(piVar5,2);
            iVar2 = FUN_0018cdd8(param_3,uVar4,uVar8,1);
          }
          goto joined_r0x00197160;
        }
      }
LAB_001971a8: ;
    }
  }
  return 1;
}

/* FUN_001971f8 @ 0x1971f8 (1652 bytes) */
int FUN_001971f8(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  uint *puVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  int *piVar14;
  code *pcVar15;
  int local_88;
  undefined1 auStack_84 [60];
  undefined4 local_48 [2];
  
  piVar14 = *(int **)(param_2 + 8);
  bVar3 = false;
  if (piVar14[2] == 0) {
    return;
  }
  do {
    iVar11 = (**(code **)(*param_1 + 8))(param_1);
    if (iVar11 != 0) {
      FUN_000e1534(param_1[3],5);
    }
    iVar11 = param_1[3];
    if (**(int **)(iVar11 + 0x6c4) == 0) {
      piVar12 = (int *)FUN_000e3b88(param_1[4],param_2,piVar14,&local_88);
      if ((piVar12 == (int *)0x0) || (local_88 == 0)) {
        iVar11 = param_1[3];
      }
      else {
        iVar11 = param_1[3];
        piVar14 = piVar12;
      }
    }
    iVar11 = FUN_00106cf8(piVar14,*(undefined4 *)(iVar11 + 0x6c4));
    piVar12 = piVar14;
    if ((((iVar11 == 0) || (uVar9 = piVar14[5], (uVar9 & 4) != 0)) || ((int)uVar9 < 0)) ||
       ((uVar9 & 0x1000) != 0)) {
      FUN_00189560(auStack_84);
      if (piVar14 == (int *)0x0) {
        bVar5 = false;
      }
      else {
        bVar5 = false;
        piVar10 = piVar14;
        do {
          uVar9 = piVar10[5];
          if ((uVar9 & 1) != 0) {
            if ((uVar9 & 0x80) != 0) {
              bVar5 = true;
            }
            if ((uVar9 & 0x10000) == 0) {
              ((int (*)())FUN_00196e90)(param_1,piVar10,auStack_84);
              uVar9 = piVar10[5];
            }
          }
          piVar10 = (int *)piVar10[2];
        } while ((piVar10 != (int *)0x0) && ((uVar9 & 4) != 0));
      }
      FUN_0018c1c8(auStack_84,param_1 + 7);
      if (piVar14 == (int *)0x0) {
LAB_00197808:
        piVar10 = (int *)piVar14[2];
      }
      else {
        bVar2 = false;
        bVar8 = false;
        bVar6 = false;
        bVar7 = false;
        piVar10 = piVar14;
        do {
          uVar9 = piVar10[5];
          if ((uVar9 & 1) != 0) {
            iVar11 = piVar10[0x47];
            pcVar15 = *(code **)(*param_1 + 0x13c);
            FUN_00105d04(local_48,piVar10);
            (*pcVar15)(param_1,iVar11,local_48[0]);
            if ((piVar10[5] & 0x10000U) == 0) {
              if ((piVar10[5] & 2U) != 0) {
                piVar13 = (int *)FUN_00105594(piVar10,1);
                iVar11 = (**(code **)(*piVar13 + 0x50))();
                if ((iVar11 != 0) &&
                   (iVar11 = FUN_001054ec(piVar10,0), *(int *)(iVar11 + 0x10) == DAT_001b2acc))
                goto LAB_00197784;
              }
              iVar11 = (**(code **)(*piVar10 + 0x28))(piVar10);
              if (iVar11 == 0) {
                if (!bVar2) {
                  bVar2 = true;
                  (**(code **)(*param_1 + 0xc0))(param_1);
                }
                if (param_1[0x23] == 0) {
                  *(undefined4 *)(*(int *)(param_1[3] + 0x6c4) + 0x3cc) = 1;
                  param_1[0x23] = 2;
                }
                else if (param_1[0x23] == 1) {
                  param_1[0x23] = 2;
                  (**(code **)(*param_1 + 0x148))(param_1);
                }
                bVar4 = !bVar3;
                if (bVar4) {
                  bVar6 = true;
                  goto LAB_00197624;
                }
                bVar6 = true;
              }
              else {
                iVar11 = param_1[0x23];
                if (iVar11 == 0) {
                  param_1[0x23] = 1;
                  (**(code **)(*param_1 + 0x134))(param_1);
                }
                else {
                  if (iVar11 != 2) {
                    if ((iVar11 != 1) || ((piVar10[5] & 0x1000U) == 0)) goto LAB_0019752c;
                    (**(code **)(*param_1 + 0x148))(param_1);
                  }
                  param_1[0x23] = 1;
                  (**(code **)(*param_1 + 0x134))(param_1);
                  (**(code **)(*param_1 + 0x138))(param_1);
                }
LAB_0019752c:
                bVar3 = false;
                bVar7 = true;
                bVar4 = true;
LAB_00197624:
                if (*(int *)(piVar10[0x22] + 8) == 0xb4) {
                  piVar10[5] = piVar10[5] | 0x1000;
                }
              }
              (**(code **)(*piVar10 + 0x1c))(piVar10,param_1,0,param_1[3]);
              if (bVar4) {
                if ((((piVar10[5] & 0x1000U) != 0) || (param_3 != 0)) || ((piVar10[5] & 2U) != 0)) {
                  (**(code **)(*param_1 + 0x14c))(param_1);
                  iVar11 = (**(code **)(*piVar10 + 0x28))(piVar10);
                  if (iVar11 == 0) {
                    bVar3 = true;
                    param_3 = 0;
                    goto LAB_001976d0;
                  }
                }
                bVar3 = false;
                param_3 = 0;
              }
LAB_001976d0:
              if (bVar5) {
                (**(code **)(*param_1 + 0x114))(param_1);
              }
              if (param_1[6] != 0) {
                (**(code **)(*param_1 + 0x140))(param_1);
              }
              (**(code **)(*piVar10 + 0x20))(piVar10,param_1,0,param_1[3]);
              iVar11 = (**(code **)(*piVar10 + 0x28))(piVar10);
              if (iVar11 != 0) {
                param_1[0x1a] = param_1[0x1a] + 1;
                (**(code **)(*param_1 + 0x15c))(param_1);
                uVar9 = piVar10[5];
                goto LAB_00197788;
              }
            }
            else {
              iVar11 = (**(code **)(*piVar10 + 0x5c))(piVar10);
              if (iVar11 != 0) {
                bVar8 = true;
              }
              iVar11 = (**(code **)(*piVar10 + 0x48))(piVar10);
              if (iVar11 != 0) {
                ((int (*)())FUN_001955c0)(param_1,piVar10,param_1[3]);
              }
              iVar11 = (**(code **)(*piVar10 + 0x4c))(piVar10);
              if (iVar11 != 0) {
                ((int (*)())FUN_0019651c)(param_1,piVar10,param_1[3]);
              }
              iVar11 = (**(code **)(*piVar10 + 0x38))(piVar10);
              if ((iVar11 != 0) && (param_1[0x23] == 1)) {
                (**(code **)(*param_1 + 0x148))(param_1);
                uVar9 = piVar10[5];
                goto LAB_00197788;
              }
            }
LAB_00197784:
            uVar9 = piVar10[5];
          }
LAB_00197788:
          piVar10 = (int *)piVar10[2];
        } while ((piVar10 != (int *)0x0) && ((uVar9 & 4) != 0));
        if (bVar6) {
          (**(code **)(*param_1 + 0x15c))(param_1);
          param_1[0x19] = param_1[0x19] + 1;
          piVar10 = (int *)piVar14[2];
        }
        else {
          if ((bVar7) || (!bVar8)) goto LAB_00197808;
          (**(code **)(*param_1 + 0x110))(param_1);
          piVar10 = (int *)piVar14[2];
        }
      }
    }
    else {
      *(int *)(param_1[4] + 0xc) = *(int *)(param_1[4] + 0xc) + 1;
      piVar10 = (int *)piVar14[2];
    }
    do {
      piVar14 = piVar10;
      puVar1 = (uint *)(piVar12 + 5);
      if ((int *)piVar14[2] == (int *)0x0) {
        return;
      }
      piVar10 = (int *)piVar14[2];
      piVar12 = piVar14;
    } while ((*puVar1 & 4) != 0);
  } while( true );
}

/* FUN_0019786c @ 0x19786c (672 bytes) */
int FUN_0019786c(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  undefined4 *param_2;
  undefined4 *param_3;
  int param_4;
  undefined4 *param_5;
  undefined4 *param_6;
{
  char cVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 uVar5;
  char cVar6;
  undefined4 uVar7;
  int iVar8;
  
  *param_3 = 0;
  param_3[1] = 0;
  *param_2 = 0;
  param_2[1] = 0;
  iVar8 = *(int *)(*(int *)(param_4 + 0x88) + 8);
  if (iVar8 == 0x35) {
    FUN_00103d50(param_4 + 0xbc,1,*(uint *)(param_4 + 0xd0) & 1 ^ 1);
    uVar3 = FUN_00112f54(0x34);
    iVar8 = 0x34;
    *(undefined4 *)(param_4 + 0x88) = uVar3;
  }
  uVar7 = *(undefined4 *)(PTR_DAT_001e913c + iVar8 * 0x38 + 0x34);
  uVar3 = ((int (*)())FUN_00195650)(param_1[0x29],iVar8);
  *param_5 = uVar3;
  uVar3 = ((int (*)())FUN_0019569c)(param_1[0x29],iVar8);
  *param_6 = uVar3;
  iVar8 = FUN_001054ec(param_4,0);
  param_1[0x28] = *(int *)(iVar8 + 0x10);
  switch(uVar7) {
  case 0:
    if (*(char *)(param_1 + 0x28) == '\0') {
      cVar2 = *(char *)((int)param_1 + 0xa1);
      cVar6 = *(char *)((int)param_1 + 0xa2);
LAB_001979d4:
      uVar4 = 1;
    }
    else {
      cVar2 = *(char *)((int)param_1 + 0xa1);
      if (cVar2 == '\0') {
        cVar6 = *(char *)((int)param_1 + 0xa2);
        goto LAB_001979d4;
      }
      cVar6 = *(char *)((int)param_1 + 0xa2);
      uVar4 = 0;
      if (cVar6 == '\0') goto LAB_001979d4;
    }
    cVar1 = *(char *)((int)param_1 + 0xa3);
    if (cVar1 == '\0') {
      uVar4 = uVar4 | 2;
    }
    if (*(char *)(param_1 + 0x28) == '\0') {
      uVar5 = 0xff;
    }
    else {
      uVar5 = 0;
    }
    *(undefined1 *)param_2 = uVar5;
    uVar5 = 0xff;
    if (cVar2 != '\0') {
      uVar5 = 0;
    }
    *(undefined1 *)((int)param_2 + 1) = uVar5;
    uVar5 = 0xff;
    if (cVar6 != '\0') {
      uVar5 = 0;
    }
    *(undefined1 *)((int)param_2 + 2) = uVar5;
    uVar5 = 0xff;
    if (cVar1 != '\0') {
      uVar5 = 0;
    }
    goto LAB_00197b18;
  case 1:
    uVar4 = 5;
    if (*(char *)((int)param_1 + 0xa3) == '\0') {
      uVar4 = 7;
      *param_6 = 1;
    }
    *(undefined1 *)((int)param_2 + 6) = 0xff;
    *(undefined1 *)((int)param_2 + 1) = 0xff;
    *(undefined1 *)param_2 = 0xff;
    break;
  case 2:
    uVar4 = 1;
    if (*(char *)((int)param_1 + 0xa3) == '\0') {
      uVar4 = 3;
      *param_6 = 1;
    }
    *(undefined1 *)((int)param_2 + 2) = 0xff;
    *(undefined1 *)param_2 = 0xff;
    *(undefined1 *)((int)param_2 + 1) = 0xff;
    break;
  case 3:
    uVar4 = 3;
    goto LAB_00197aa4;
  default:
    uVar4 = 0;
    break;
  case 5:
    if (((*(char *)(param_1 + 0x28) == '\0') || (*(char *)((int)param_1 + 0xa1) == '\0')) ||
       (uVar4 = 2, *(char *)((int)param_1 + 0xa2) == '\0')) {
      *param_5 = 10;
      (**(code **)(*param_1 + 0x150))(param_1,10);
      uVar4 = 0xb;
    }
    uVar5 = 0xff;
LAB_00197b18:
    *(undefined1 *)((int)param_3 + 3) = uVar5;
    break;
  case 8:
    uVar4 = 0x13;
LAB_00197aa4:
    *param_6 = 1;
    *(undefined1 *)((int)param_3 + 3) = 0xff;
    *(undefined1 *)((int)param_2 + 2) = 0xff;
    *(undefined1 *)param_2 = 0xff;
    *(undefined1 *)((int)param_2 + 1) = 0xff;
  }
  return uVar4;
}

