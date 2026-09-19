#include "decls.h"

/* FUN_001a92a4 @ 0x1a92a4 (5 bytes) */
int FUN_001a92a4()
{
  return;
}

/* FUN_001a92aa @ 0x1a92aa (5 bytes) */
int FUN_001a92aa()
{
  return;
}

/* FUN_001a92b0 @ 0x1a92b0 (5 bytes) */
int FUN_001a92b0()
{
  return;
}

/* FUN_001a92b6 @ 0x1a92b6 (5 bytes) */
int FUN_001a92b6()
{
  return;
}

/* FUN_001a92bc @ 0x1a92bc (5 bytes) */
int FUN_001a92bc()
{
  return;
}

/* FUN_001a92c2 @ 0x1a92c2 (5 bytes) */
int FUN_001a92c2()
{
  return;
}

/* FUN_001a92c8 @ 0x1a92c8 (5 bytes) */
int FUN_001a92c8()
{
  return;
}

/* FUN_001a92ce @ 0x1a92ce (5 bytes) */
int FUN_001a92ce()
{
  return;
}

/* FUN_001a92d4 @ 0x1a92d4 (5 bytes) */
int FUN_001a92d4()
{
  return;
}

/* FUN_001a92da @ 0x1a92da (70 bytes) */
int FUN_001a92da(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  byte *pbVar1;
  undefined4 uVar2;
  
  pbVar1 = PTR_DAT_00213a35 + param_2 * 0x38;
  uVar2 = *(undefined4 *)(pbVar1 + 0xc);
  if (((*pbVar1 & 2) == 0) && (*(int *)(pbVar1 + 4) != 0)) {
    uVar2 = *(undefined4 *)(PTR_DAT_00213a35 + *(int *)(pbVar1 + 4) * 0x38 + 0xc);
  }
  return uVar2;
}

/* FUN_001a9320 @ 0x1a9320 (70 bytes) */
int FUN_001a9320(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  byte *pbVar1;
  undefined4 uVar2;
  
  pbVar1 = PTR_DAT_00213a35 + param_2 * 0x38;
  uVar2 = *(undefined4 *)(pbVar1 + 0xc);
  if (((*pbVar1 & 2) != 0) && (*(int *)(pbVar1 + 4) != 0)) {
    uVar2 = *(undefined4 *)(PTR_DAT_00213a35 + *(int *)(pbVar1 + 4) * 0x38 + 0xc);
  }
  return uVar2;
}

/* FUN_001a9366 @ 0x1a9366 (14 bytes) */
int FUN_001a9366(param_1)
  int *param_1;
{
                    
                    
  (**(code **)(*param_1 + 0x38))();
  return;
}

/* FUN_001a937a @ 0x1a937a (5 bytes) */
int FUN_001a937a()
{
  return;
}

/* FUN_001a9380 @ 0x1a9380 (5 bytes) */
int FUN_001a9380()
{
  return;
}

/* FUN_001a9386 @ 0x1a9386 (5 bytes) */
int FUN_001a9386()
{
  return;
}

/* FUN_001a938c @ 0x1a938c (5 bytes) */
int FUN_001a938c()
{
  return;
}

/* FUN_001a9392 @ 0x1a9392 (118 bytes) */
int FUN_001a9392(param_1)
  int param_1;
{
  int iVar1;
  
  *(undefined4 *)(*(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60) * 0x48) = 3;
  iVar1 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60) * 0x48;
  *(undefined2 *)(iVar1 + 0xe) = 0x8000;
  *(undefined2 *)(iVar1 + 0x10) = 0x8000;
  *(undefined2 *)(iVar1 + 0x12) = 0x8000;
  *(undefined1 *)(iVar1 + 0x2a) = 0x14;
  *(undefined1 *)(iVar1 + 0x2b) = 0x14;
  *(undefined1 *)(iVar1 + 0x2c) = 0x14;
  *(undefined1 *)(iVar1 + 0x31) = 0;
  *(undefined2 *)(iVar1 + 0x1a) = 0x8000;
  *(undefined2 *)(iVar1 + 0x1c) = 0x8000;
  *(undefined2 *)(iVar1 + 0x1e) = 0x8000;
  *(undefined1 *)(iVar1 + 0x39) = 0x10;
  *(undefined1 *)(iVar1 + 0x3a) = 0x10;
  *(undefined1 *)(iVar1 + 0x3b) = 0x10;
  *(undefined1 *)(iVar1 + 0x40) = 0;
  return;
}

/* FUN_001a9408 @ 0x1a9408 (70 bytes) */
int FUN_001a9408(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  param_2 = param_2 * 0x48;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + param_2) = 1;
  *(undefined1 *)(param_2 + 10 + *(int *)(param_1 + 0x58)) = param_3;
  *(undefined1 *)(param_2 + 0xb + *(int *)(param_1 + 0x58)) = param_4;
  *(undefined2 *)(param_2 + 6 + *(int *)(param_1 + 0x58)) = param_5;
  *(undefined1 *)(param_2 + 0xd + *(int *)(param_1 + 0x58)) = param_6;
  return;
}

/* FUN_001a944e @ 0x1a944e (70 bytes) */
int FUN_001a944e(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
{
  param_2 = param_2 * 0x48;
  *(undefined4 *)(*(int *)(param_1 + 0x58) + param_2) = 1;
  *(undefined1 *)(param_2 + 8 + *(int *)(param_1 + 0x58)) = param_3;
  *(undefined1 *)(param_2 + 9 + *(int *)(param_1 + 0x58)) = param_4;
  *(undefined2 *)(param_2 + 4 + *(int *)(param_1 + 0x58)) = param_5;
  *(undefined1 *)(param_2 + 0xc + *(int *)(param_1 + 0x58)) = param_6;
  return;
}

/* FUN_001a9494 @ 0x1a9494 (230 bytes) */
int FUN_001a9494(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  uint param_5;
{
  char cVar1;
  uint uVar2;
  
  uVar2 = param_5 & 0xffffff | 0x4000000;
  cVar1 = FUN_000f56f0(uVar2,DAT_001cf05c);
  if (cVar1 == '\0') {
    cVar1 = FUN_000f56f0(uVar2,DAT_001cf058);
    if (cVar1 != '\0') {
      *(undefined4 *)(param_3 + param_2 * 4) = 0x10;
      return;
    }
    cVar1 = FUN_000f56f0(uVar2,DAT_001cf054);
    if (cVar1 == '\0') {
      cVar1 = FUN_000f56f0(uVar2,DAT_001cf050);
      if (cVar1 == '\0') {
        cVar1 = FUN_000f56f0(uVar2,DAT_001cf060);
        if (cVar1 != '\0') {
          *(undefined4 *)(param_3 + param_2 * 4) = 0x13;
        }
      }
      else {
        *(undefined4 *)(param_3 + param_2 * 4) = 0x12;
      }
    }
    else {
      *(undefined4 *)(param_3 + param_2 * 4) = 0x11;
    }
  }
  else {
    *(undefined4 *)(param_3 + param_2 * 4) = 0xf;
  }
  return;
}

/* FUN_001a957a @ 0x1a957a (87 bytes) */
int FUN_001a957a(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  if ((*(unsigned char *)((unsigned char *)&(param_5) + 3)) == '\0') {
    *(undefined4 *)(param_3 + param_2 * 4) = 0xc;
  }
  else {
    if ((*(unsigned char *)((unsigned char *)&(param_5) + 3)) == '\x01') {
      *(undefined4 *)(param_3 + param_2 * 4) = 0xd;
      return;
    }
    if ((*(unsigned char *)((unsigned char *)&(param_5) + 3)) == '\x02') {
      *(undefined4 *)(param_3 + param_2 * 4) = 0xe;
      return;
    }
    if (((*(unsigned char *)((unsigned char *)&(param_5) + 3)) == '\x03') || ((*(unsigned char *)((unsigned char *)&(param_5) + 3)) == '\x04')) {
      *(undefined4 *)(param_3 + param_2 * 4) = 0xf;
      return;
    }
  }
  return;
}

/* FUN_001a95d2 @ 0x1a95d2 (89 bytes) */
int FUN_001a95d2(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  uint param_6;
{
  char cVar1;
  
  cVar1 = FUN_000f56f0(param_6 & 0xffffff | 0x4000000,DAT_001cf060);
  if (cVar1 != '\0') {
    *(int *)(param_3 + param_2 * 4) = param_5 + 0xc;
    return;
  }
  *(int *)(param_3 + param_2 * 4) = param_5 + 0x1d;
  return;
}

/* FUN_001a962c @ 0x1a962c (361 bytes) */
int FUN_001a962c(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  uint param_6;
{
  char cVar1;
  uint uVar2;
  
  param_6 = param_6 & 0xffffff;
  uVar2 = param_6 | 0x4000000;
  cVar1 = FUN_000f56f0(uVar2,DAT_001cf05c);
  if (cVar1 == '\0') {
    cVar1 = FUN_000f56f0(uVar2,DAT_001cf058);
    if (cVar1 != '\0') {
      *(int *)(param_3 + param_2 * 4) = param_5 * 4 + 1;
      return;
    }
    cVar1 = FUN_000f56f0(uVar2,DAT_001cf054);
    if (cVar1 == '\0') {
      cVar1 = FUN_000f56f0(uVar2,DAT_001cf050);
      if (cVar1 == '\0') {
        cVar1 = (char)param_6;
        if (cVar1 == '\x01') {
          *(int *)(param_3 + param_2 * 4) = param_5 + 0x17;
        }
        else if (cVar1 == '\x03') {
          *(int *)(param_3 + param_2 * 4) = param_5 + 0x1d;
        }
        else if (cVar1 == '\x02') {
          *(int *)(param_3 + param_2 * 4) = param_5 + 0x1a;
        }
        else if ((char)(param_6 >> 8) == '\0') {
          *(int *)(param_3 + param_2 * 4) = param_5 + 0x1a;
        }
        else if ((char)(param_6 >> 0x10) == '\0') {
          *(int *)(param_3 + param_2 * 4) = param_5 + 0x17;
        }
        else {
          *(int *)(param_3 + param_2 * 4) = param_5 + 0x1d;
        }
      }
      else {
        *(int *)(param_3 + param_2 * 4) = param_5 * 4 + 3;
      }
    }
    else {
      *(int *)(param_3 + param_2 * 4) = param_5 * 4 + 2;
    }
  }
  else {
    *(int *)(param_3 + param_2 * 4) = param_5 << 2;
  }
  return;
}

/* FUN_001a9796 @ 0x1a9796 (20 bytes) */
int FUN_001a9796(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  *(int *)(param_3 + param_2 * 4) = param_5 + 9;
  return;
}

/* FUN_001a97aa @ 0x1a97aa (66 bytes) */
int FUN_001a97aa(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
  undefined4 param_6;
{
  if ((*(unsigned char *)((unsigned char *)&(param_6) + 3)) == '\0') {
    *(int *)(param_3 + param_2 * 4) = param_5 * 3;
  }
  else {
    if ((*(unsigned char *)((unsigned char *)&(param_6) + 3)) == '\x01') {
      *(int *)(param_3 + param_2 * 4) = param_5 * 3 + 1;
      return;
    }
    if ((*(unsigned char *)((unsigned char *)&(param_6) + 3)) == '\x02') {
      *(int *)(param_3 + param_2 * 4) = param_5 * 3 + 2;
      return;
    }
  }
  return;
}

/* FUN_001a97ec @ 0x1a97ec (348 bytes) */
int FUN_001a97ec(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 1;
LAB_001a97fc:
  do {
    iVar1 = iVar2;
    if (((param_2 >> ((byte)iVar1 & 0x1f) & 1U) != 0) && (-1 < *(int *)(param_3 + iVar1 * 4))) {
      if (iVar1 == 1) {
        *(short *)(*(int *)(param_1 + 0x58) + 0xe + *(int *)(param_1 + 0x60) * 0x48) =
             (short)*(undefined4 *)(param_3 + 4);
        iVar2 = 2;
        goto LAB_001a97fc;
      }
      if (iVar1 == 2) {
        *(short *)(*(int *)(param_1 + 0x58) + 0x10 + *(int *)(param_1 + 0x60) * 0x48) =
             (short)*(undefined4 *)(param_3 + 8);
      }
      else if (iVar1 == 3) {
        *(short *)(*(int *)(param_1 + 0x58) + 0x12 + *(int *)(param_1 + 0x60) * 0x48) =
             (short)*(undefined4 *)(param_3 + 0xc);
        break;
      }
    }
    iVar2 = iVar1 + 1;
  } while (iVar1 + 1 != 4);
  iVar2 = CONCAT22((short)((uint)(iVar1 + 1) >> 0x10),1);
LAB_001a9849:
  do {
    if (((param_4 >> ((byte)iVar2 & 0x1f) & 1U) != 0) && (-1 < *(int *)(param_5 + iVar2 * 4))) {
      if (iVar2 == 1) {
        *(short *)(*(int *)(param_1 + 0x58) + 0x1a + *(int *)(param_1 + 0x60) * 0x48) =
             (short)*(undefined4 *)(param_5 + 4);
        iVar2 = 2;
        goto LAB_001a9849;
      }
      if (iVar2 == 2) {
        *(short *)(*(int *)(param_1 + 0x58) + 0x1c + *(int *)(param_1 + 0x60) * 0x48) =
             (short)*(undefined4 *)(param_5 + 8);
      }
      else if (iVar2 == 3) {
        *(short *)(*(int *)(param_1 + 0x58) + 0x1e + *(int *)(param_1 + 0x60) * 0x48) =
             (short)*(undefined4 *)(param_5 + 0xc);
        return;
      }
    }
    iVar2 = iVar2 + 1;
    if (iVar2 == 4) {
      return;
    }
  } while( true );
}

/* FUN_001a9948 @ 0x1a9948 (442 bytes) */
int FUN_001a9948(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  
  *(undefined4 *)(*(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60) * 0x48) = 3;
  if (param_2 != -1) goto LAB_001a996b;
  if (param_3 == 0x31) {
LAB_001a9a8c:
    *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x3a + *(int *)(param_1 + 0x60) * 0x48) = 0x11;
LAB_001a9a9a:
    *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x3b + *(int *)(param_1 + 0x60) * 0x48) = 0x10;
    param_2 = 0;
  }
  else {
    if (param_3 < 0x32) {
      if (param_3 == 0x13) goto LAB_001a9a9a;
      if (param_3 == 0x25) {
LAB_001a9a0a:
        iVar2 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60) * 0x48;
        uVar4 = *(undefined1 *)(iVar2 + 0x39);
        uVar1 = *(undefined1 *)(iVar2 + 0x3c);
        *(undefined1 *)(iVar2 + 0x39) = *(undefined1 *)(iVar2 + 0x3a);
        iVar2 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60) * 0x48;
        *(undefined1 *)(iVar2 + 0x3c) = *(undefined1 *)(iVar2 + 0x3d);
        iVar2 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60) * 0x48;
        *(undefined1 *)(iVar2 + 0x3a) = *(undefined1 *)(iVar2 + 0x3b);
        iVar2 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60) * 0x48;
        *(undefined1 *)(iVar2 + 0x3d) = *(undefined1 *)(iVar2 + 0x3e);
        *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x3b + *(int *)(param_1 + 0x60) * 0x48) = uVar4;
        *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x3e + *(int *)(param_1 + 0x60) * 0x48) = uVar1;
        param_2 = (param_3 != 0x9d) + 5;
        goto LAB_001a996b;
      }
      if (param_3 == 0x12) {
LAB_001a9ab9:
        iVar2 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60) * 0x48;
        *(undefined1 *)(iVar2 + 0x3b) = *(undefined1 *)(iVar2 + 0x3a);
        iVar2 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60) * 0x48;
        *(undefined1 *)(iVar2 + 0x3e) = *(undefined1 *)(iVar2 + 0x3d);
        *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x3a + *(int *)(param_1 + 0x60) * 0x48) = 0x11;
        *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x3d + *(int *)(param_1 + 0x60) * 0x48) = 0;
        param_2 = 0;
        goto LAB_001a996b;
      }
    }
    else {
      if (param_3 == 0x36) goto LAB_001a9a9a;
      if (param_3 < 0x37) {
        if (param_3 == 0x34) goto LAB_001a9ab9;
      }
      else {
        if (param_3 == 0x66) goto LAB_001a9a8c;
        if (param_3 == 0x9d) goto LAB_001a9a0a;
      }
    }
    param_2 = -1;
  }
LAB_001a996b:
  *(char *)(*(int *)(param_1 + 0x58) + 0x40 + *(int *)(param_1 + 0x60) * 0x48) = (char)param_2;
  if (*(char *)(param_4 + 0x120) != '\0') {
    *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x42 + *(int *)(param_1 + 0x60) * 0x48) = 1;
  }
  iVar2 = *(int *)(param_1 + 0x60);
  iVar3 = *(int *)(param_1 + 0x58);
  uVar4 = FUN_001a8fe0(*(undefined4 *)(param_4 + 0x124));
  *(undefined1 *)(iVar2 * 0x48 + 0x41 + iVar3) = uVar4;
  return;
}

/* FUN_001a9b02 @ 0x1a9b02 (22 bytes) */
int FUN_001a9b02(param_1)
  int param_1;
{
  *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x20 + *(int *)(param_1 + 0x60) * 0x48) = 1;
  return;
}

/* FUN_001a9b18 @ 0x1a9b18 (52 bytes) */
int FUN_001a9b18(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  
  *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;
  iVar1 = *(int *)(param_1 + 100);
  if (iVar1 == *(int *)(param_1 + 0x6c)) {
    iVar2 = *(int *)(param_1 + 0x68);
    if (iVar2 != *(int *)(param_1 + 0x70)) {
      *(int *)(param_1 + 0x7c) = *(int *)(param_1 + 0x7c) + 1;
      *(int *)(param_1 + 0x6c) = iVar1;
      *(int *)(param_1 + 0x70) = iVar2;
      return;
    }
  }
  else {
    iVar2 = *(int *)(param_1 + 0x68);
  }
  *(int *)(param_1 + 0x6c) = iVar1;
  *(int *)(param_1 + 0x70) = iVar2;
  return;
}

/* FUN_001a9b4c @ 0x1a9b4c (125 bytes) */
int FUN_001a9b4c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  
  *(undefined2 *)(*(int *)(param_1 + 0x58) + 0x24) = param_2;
  iVar1 = *(int *)(param_1 + 0x58);
  *(int *)(iVar1 + 8) = *(int *)(param_1 + 0x60) + -1;
  *(undefined2 *)(iVar1 + 0x14) = 1;
  if ((*(int *)(param_1 + 100) == *(int *)(param_1 + 0x6c)) &&
     (*(int *)(param_1 + 0x68) != *(int *)(param_1 + 0x70))) {
    iVar2 = *(int *)(param_1 + 0x7c) + 1;
    *(int *)(param_1 + 0x7c) = iVar2;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x7c);
  }
  *(short *)(iVar1 + 0x1e) = (short)*(int *)(param_1 + 100) + (short)iVar2;
  *(undefined1 *)(iVar1 + 0xd) = 6;
  *(undefined1 *)(iVar1 + 0xc) = 0;
  *(short *)(iVar1 + 0x1c) = (short)*(undefined4 *)(param_1 + 100);
  *(short *)(iVar1 + 0x1a) = (short)*(undefined4 *)(param_1 + 0x68);
  *(short *)(iVar1 + 0x16) = *(short *)(param_1 + 0x88) + 1;
  *(short *)(iVar1 + 0x18) = (short)*(undefined4 *)(param_1 + 0x74);
  *(undefined2 *)(iVar1 + 0x22) = param_3;
  return;
}

/* FUN_001a9bca @ 0x1a9bca (292 bytes) */
int FUN_001a9bca(param_1)
  int *param_1;
{
  void *pvVar1;
  
  if (param_1[0x1d] == 0) {
    pvVar1 = (void *)(param_1[0x18] * 0x48 + param_1[0x16]);
    _memcpy((void *)((int)pvVar1 + 0x48),pvVar1,0x48);
    _memset((void *)(param_1[0x16] + param_1[0x18] * 0x48),0,0x48);
    param_1[0x1d] = 1;
    param_1[0x18] = 2;
    (**(code **)(*param_1 + 0xc4))(param_1,1,0,0,0,0);
    (**(code **)(*param_1 + 200))(param_1,1,0,0,0,0);
    (**(code **)(*param_1 + 0xcc))(param_1,1,0xf);
    (**(code **)(*param_1 + 0xd0))(param_1,1,0xf);
  }
  param_1[0x18] = param_1[0x18] + 1;
  param_1[0x20] = 1;
  param_1[0x21] = 1;
  return;
}

/* FUN_001a9cee @ 0x1a9cee (37 bytes) */
int FUN_001a9cee(param_1)
  int param_1;
{
  undefined4 uStack00000008;
  
  if (*(int *)(*(int *)(param_1 + 0xc) + 0x3f4) != 0) {
    uStack00000008 = 0xf;
    FUN_000e27ca();
    return;
  }
  return;
}

/* FUN_001a9d14 @ 0x1a9d14 (250 bytes) */
int FUN_001a9d14(param_1)
  int *param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  *(int *)(param_1[0x17] + 0x93b8) = param_1[0x24];
  *(int *)(param_1[0x17] + 0x9364) = *(int *)(*(int *)(param_1[3] + 0x3f4) + 0x7c) + 1;
  uVar3 = *(int *)(*(int *)(param_1[3] + 0x3f4) + 0x80) + 1;
  *(undefined4 *)(param_1[0x17] + 0x9368) = *(undefined4 *)(*(int *)(param_1[3] + 0x3f4) + 0x84);
  uVar1 = *(uint *)(param_1[0x17] + 0x9364);
  if (uVar3 < uVar1) {
    uVar3 = uVar1;
  }
  *(uint *)(param_1[0x17] + 0x9364) = uVar3;
  iVar2 = FUN_00137d0a(*(undefined4 *)(param_1[3] + 0x3f4),0);
  if (iVar2 == 0) {
    iVar2 = 0;
    if (param_1[0x18] == param_1[0x1d] + 1) {
LAB_001a9dd0:
      (**(code **)(*param_1 + 0xbc))(param_1);
      (**(code **)(*param_1 + 0xc0))(param_1);
      (**(code **)(*param_1 + 0x15c))(param_1);
      (**(code **)(*param_1 + 0x144))(param_1,param_1[0x1e],iVar2);
      return;
    }
  }
  else {
    iVar2 = iVar2 + -1;
    if (param_1[0x18] == param_1[0x1d] + 1) goto LAB_001a9dd0;
  }
  (**(code **)(*param_1 + 0x144))(param_1,param_1[0x1e],iVar2);
  return;
}

/* FUN_001a9e0e @ 0x1a9e0e (94 bytes) */
int FUN_001a9e0e(param_1, param_2)
  int *param_1;
  int param_2;
{
  undefined4 uVar1;
  
  uVar1 = FUN_00118f66(0x31);
  *(undefined4 *)(param_2 + 0x88) = uVar1;
  if (*(int *)(param_2 + 0x98) != 0x2c) {
                    
                    
    (**(code **)(*param_1 + 0x38))();
    return;
  }
  return;
}

/* FUN_001a9e6c @ 0x1a9e6c (78 bytes) */
int FUN_001a9e6c(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  
  if ((*(int *)(param_3 + 0x98) != 2) && (*(int *)(param_3 + 0x98) != 0xc)) {
                    
                    
    (**(code **)(*param_1 + 0x88))();
    return;
  }
  iVar1 = param_1[0x1e];
  if (param_1[0x1e] < param_2) {
    iVar1 = param_2;
  }
  param_1[0x1e] = iVar1;
                    
                    
  (**(code **)(*param_1 + 0x88))();
  return;
}

/* FUN_001a9eba @ 0x1a9eba (268 bytes) */
int FUN_001a9eba(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  void *pvVar1;
  
  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_4 + 0x54);
  pvVar1 = (void *)FUN_000e2790(param_4,0x963c,param_3);
  *(void **)(param_1 + 0x5c) = pvVar1;
  _memset(pvVar1,0,0x963c);
  *(undefined4 **)(param_1 + 0x58) = *(undefined4 **)(param_1 + 0x5c);
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
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(int *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0x54) = 3;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  **(undefined4 **)(param_1 + 0x5c) = 0;
  *(int *)(*(int *)(param_1 + 0x58) + 4) = *(int *)(*(int *)(param_4 + 0x54) + 0x40) + 1;
  *(undefined4 *)(param_1 + 0x94) = 1;
  *(undefined4 *)(param_1 + 0x98) = 1;
  return;
}

/* FUN_001a9fc6 @ 0x1a9fc6 (88 bytes) */
int FUN_001a9fc6(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_0010b180(param_3,param_2);
  iVar2 = (**(code **)(*piVar1 + 0x80))(piVar1);
  if (*(int *)(iVar2 + 0xb4) == DAT_001cf04c) {
    *(uint *)(FUN_00009369 + *(int *)(param_1 + 0x5c) + 3) =
         *(uint *)(FUN_00009369 + *(int *)(param_1 + 0x5c) + 3) |
         1 << ((byte)*(undefined4 *)(iVar2 + 0x148) & 0x1f);
  }
  return;
}

/* FUN_001aa01e @ 0x1aa01e (807 bytes) */
int FUN_001aa01e(param_1, param_2)
  int *param_1;
  int param_2;
{
  uint *puVar1;
  code *pcVar2;
  uint uVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  uint local_14;
  byte local_10;
  
  local_14 = 0;
  iVar8 = 0;
  do {
    iVar5 = FUN_0010b0f4(param_2,0);
    if (*(char *)(iVar8 + 0x10 + iVar5) == '\x01') {
      local_14 = local_14 | 1 << ((byte)iVar8 & 0x1f);
    }
    iVar8 = iVar8 + 1;
  } while (iVar8 != 4);
  if ((*(int *)(param_2 + 0x144) == 0x16) || (*(int *)(param_2 + 0x144) == 0x17)) {
    pcVar2 = *(code **)(*param_1 + 0xc4);
    uVar6 = FUN_0013c4e0(*(undefined4 *)(param_1[3] + 0x3f4),param_2);
    uVar7 = FUN_001139a8(*(undefined4 *)(param_2 + 0x144),*(undefined4 *)(param_2 + 0x148));
    (*pcVar2)(param_1,param_1[0x25],uVar7,1,uVar6,0);
    iVar8 = *param_1;
  }
  else if (*(int *)(param_2 + 0x144) == 0x1b) {
    pcVar2 = *(code **)(*param_1 + 0xc4);
    uVar6 = FUN_0013c4e0(*(undefined4 *)(param_1[3] + 0x3f4),param_2);
    cVar4 = FUN_000d920a(*(undefined4 *)(param_1[3] + 0xdc),0);
    (*pcVar2)(param_1,param_1[0x25],*(undefined4 *)(param_2 + 0x148),(-(cVar4 == '\0') & 2U) + 1,
              uVar6,0);
    iVar8 = *param_1;
  }
  else {
    if (*(int *)(param_2 + 0x144) != 0x23) {
      iVar8 = *(int *)(param_2 + 0x148);
      pcVar2 = *(code **)(*param_1 + 200);
      uVar3 = *(uint *)(param_2 + 0x13c);
      uVar6 = FUN_0013c4e0(*(undefined4 *)(param_1[3] + 0x3f4),param_2);
      (*pcVar2)(param_1,param_1[0x26],iVar8,1,uVar6,(uVar3 ^ 1) & 1);
      (**(code **)(*param_1 + 0xcc))(param_1,param_1[0x26],local_14);
      param_1[0x26] = param_1[0x26] + 1;
      iVar5 = param_1[3];
      if (*(int *)(*(int *)(iVar5 + 0x3f4) + 0x80) < iVar8) {
        *(int *)(*(int *)(iVar5 + 0x3f4) + 0x80) = iVar8;
        iVar5 = param_1[3];
      }
      local_10 = (byte)iVar8;
      puVar1 = (uint *)(*(int *)(iVar5 + 0x3f4) + 0x88);
      *puVar1 = *puVar1 | 1 << (local_10 & 0x1f);
      iVar8 = param_1[0x25];
      goto LAB_001aa15c;
    }
    pcVar2 = *(code **)(*param_1 + 0xc4);
    uVar6 = FUN_0013c4e0(*(undefined4 *)(param_1[3] + 0x3f4),param_2);
    (*pcVar2)(param_1,param_1[0x25],*(undefined4 *)(param_2 + 0x148),2,uVar6,0);
    iVar8 = *param_1;
  }
  (**(code **)(iVar8 + 0xd0))(param_1,param_1[0x25],local_14);
  iVar8 = param_1[0x25] + 1;
  param_1[0x25] = iVar8;
LAB_001aa15c:
  iVar5 = param_1[0x26];
  if (iVar5 < iVar8) {
    param_1[0x1d] = iVar8 + -1;
    param_1[0x18] = iVar8;
    return;
  }
  param_1[0x1d] = iVar5 + -1;
  param_1[0x18] = iVar5;
  return;
}

/* FUN_001aa346 @ 0x1aa346 (123 bytes) */
int FUN_001aa346(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar2 = (int *)FUN_0010b180(param_2,param_3);
  if (((((piVar2[0x20] == 0) || (cVar1 = FUN_0012dfd8(piVar2[0x26]), cVar1 == '\0')) ||
       ((*(byte *)(piVar2 + 5) & 2) != 0)) ||
      (cVar1 = (**(code **)(*piVar2 + 0x50))(piVar2), cVar1 != '\0')) &&
     (cVar1 = (**(code **)(*piVar2 + 0x50))(piVar2), cVar1 == '\0')) {
    return 0;
  }
  uVar3 = FUN_0013c4e0();
  return uVar3;
}

/* FUN_001aa3c2 @ 0x1aa3c2 (542 bytes) */
int FUN_001aa3c2(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  int *param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  int param_6;
  int param_7;
  undefined4 param_8;
  int param_9;
{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_14;
  
  iVar4 = 1;
  local_14 = 0x98;
  do {
    iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
    if (iVar3 < iVar4) {
      return;
    }
    if (iVar4 == 1) {
      if (param_3 != 0) {
        *(char *)(*(int *)(param_1 + 0x58) + 0x2a + *(int *)(param_1 + 0x60) * 0x48) =
             (char)*(undefined4 *)(param_4 + 4);
      }
      if (param_6 != 0) {
        *(char *)(*(int *)(param_1 + 0x58) + 0x39 + *(int *)(param_1 + 0x60) * 0x48) =
             (char)*(undefined4 *)(param_7 + 4);
      }
    }
    else if (iVar4 == 2) {
      if (param_3 != 0) {
        *(char *)(*(int *)(param_1 + 0x58) + 0x2b + *(int *)(param_1 + 0x60) * 0x48) =
             (char)*(undefined4 *)(param_4 + 8);
      }
      if (param_6 != 0) {
        *(char *)(*(int *)(param_1 + 0x58) + 0x3a + *(int *)(param_1 + 0x60) * 0x48) =
             (char)*(undefined4 *)(param_7 + 8);
      }
    }
    else if ((iVar4 == 3) && (param_9 == '\0')) {
      if (param_3 != 0) {
        *(char *)(*(int *)(param_1 + 0x58) + 0x2c + *(int *)(param_1 + 0x60) * 0x48) =
             (char)*(undefined4 *)(param_4 + 0xc);
      }
      if (param_6 != 0) {
        *(char *)(*(int *)(param_1 + 0x58) + 0x3b + *(int *)(param_1 + 0x60) * 0x48) =
             (char)*(undefined4 *)(param_7 + 0xc);
      }
    }
    uVar1 = *(uint *)(local_14 + 0x20 + (int)param_2);
    uVar2 = FUN_001a90e8(uVar1 & 1,uVar1 >> 1 & 1);
    if (param_6 != 0) {
      if (param_9 == '\0') {
        if (iVar4 == 1) goto LAB_001aa587;
        if (iVar4 == 2) {
          *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x3d + *(int *)(param_1 + 0x60) * 0x48) = uVar2
          ;
        }
        else if (iVar4 == 3) {
          *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x3e + *(int *)(param_1 + 0x60) * 0x48) = uVar2
          ;
        }
      }
      else if (iVar4 == 3) {
LAB_001aa587:
        *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x3c + *(int *)(param_1 + 0x60) * 0x48) = uVar2;
      }
    }
    if (param_3 != 0) {
      if (iVar4 == 1) {
        *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x2d + *(int *)(param_1 + 0x60) * 0x48) = uVar2;
      }
      else if (iVar4 == 2) {
        *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x2e + *(int *)(param_1 + 0x60) * 0x48) = uVar2;
      }
      else if ((iVar4 == 3) && (param_9 == '\0')) {
        *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x2f + *(int *)(param_1 + 0x60) * 0x48) = uVar2;
      }
    }
    iVar4 = iVar4 + 1;
    local_14 = local_14 + 0x18;
  } while( true );
}

/* FUN_001aa5e0 @ 0x1aa5e0 (442 bytes) */
int FUN_001aa5e0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  
  *(undefined4 *)(*(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60) * 0x48) = 3;
  if (param_2 != -1) goto LAB_001aa603;
  if (param_3 == 0x31) {
LAB_001aa724:
    *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x2b + *(int *)(param_1 + 0x60) * 0x48) = 0x15;
LAB_001aa732:
    *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x2c + *(int *)(param_1 + 0x60) * 0x48) = 0x14;
    param_2 = 0;
  }
  else {
    if (param_3 < 0x32) {
      if (param_3 == 0x13) goto LAB_001aa732;
      if (param_3 == 0x25) {
LAB_001aa6a2:
        iVar2 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60) * 0x48;
        uVar4 = *(undefined1 *)(iVar2 + 0x2a);
        uVar1 = *(undefined1 *)(iVar2 + 0x2d);
        *(undefined1 *)(iVar2 + 0x2a) = *(undefined1 *)(iVar2 + 0x2b);
        iVar2 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60) * 0x48;
        *(undefined1 *)(iVar2 + 0x2d) = *(undefined1 *)(iVar2 + 0x2e);
        iVar2 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60) * 0x48;
        *(undefined1 *)(iVar2 + 0x2b) = *(undefined1 *)(iVar2 + 0x2c);
        iVar2 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60) * 0x48;
        *(undefined1 *)(iVar2 + 0x2e) = *(undefined1 *)(iVar2 + 0x2f);
        *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x2c + *(int *)(param_1 + 0x60) * 0x48) = uVar4;
        *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x2f + *(int *)(param_1 + 0x60) * 0x48) = uVar1;
        param_2 = (param_3 != 0x9d) + 7;
        goto LAB_001aa603;
      }
      if (param_3 == 0x12) {
LAB_001aa751:
        iVar2 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60) * 0x48;
        *(undefined1 *)(iVar2 + 0x2c) = *(undefined1 *)(iVar2 + 0x2b);
        iVar2 = *(int *)(param_1 + 0x58) + *(int *)(param_1 + 0x60) * 0x48;
        *(undefined1 *)(iVar2 + 0x2f) = *(undefined1 *)(iVar2 + 0x2e);
        *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x2b + *(int *)(param_1 + 0x60) * 0x48) = 0x15;
        *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x2e + *(int *)(param_1 + 0x60) * 0x48) = 0;
        param_2 = 0;
        goto LAB_001aa603;
      }
    }
    else {
      if (param_3 == 0x36) goto LAB_001aa732;
      if (param_3 < 0x37) {
        if (param_3 == 0x34) goto LAB_001aa751;
      }
      else {
        if (param_3 == 0x66) goto LAB_001aa724;
        if (param_3 == 0x9d) goto LAB_001aa6a2;
      }
    }
    param_2 = -1;
  }
LAB_001aa603:
  *(char *)(*(int *)(param_1 + 0x58) + 0x31 + *(int *)(param_1 + 0x60) * 0x48) = (char)param_2;
  if (*(char *)(param_4 + 0x120) != '\0') {
    *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x33 + *(int *)(param_1 + 0x60) * 0x48) = 1;
  }
  iVar2 = *(int *)(param_1 + 0x60);
  iVar3 = *(int *)(param_1 + 0x58);
  uVar4 = FUN_001a8fe0(*(undefined4 *)(param_4 + 0x124));
  *(undefined1 *)(iVar2 * 0x48 + 0x32 + iVar3) = uVar4;
  return;
}

/* FUN_001aa79a @ 0x1aa79a (65 bytes) */
int FUN_001aa79a(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0xbc);
  puVar2 = (undefined4 *)FUN_001a7bca(uVar1,0xac);
  *puVar2 = uVar1;
  *(undefined1 *)(puVar2 + 7) = 0;
  puVar2[1] = &PTR_FUN_001fde28;
  return puVar2 + 1;
}

/* FUN_001aa7dc @ 0x1aa7dc (46 bytes) */
int FUN_001aa7dc(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fde28;
  param_1[0x17] = 0;
  param_1[0x16] = 0;
  *param_1 = PTR_DAT_00213a45 + 8;
  return;
}

/* FUN_001aa80a @ 0x1aa80a (46 bytes) */
int FUN_001aa80a(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fde28;
  param_1[0x17] = 0;
  param_1[0x16] = 0;
  *param_1 = PTR_DAT_00213a45 + 8;
  return;
}

/* FUN_001aa838 @ 0x1aa838 (76 bytes) */
int FUN_001aa838(param_1)
  undefined4 *param_1;
{
  *param_1 = &PTR_FUN_001fde28;
  param_1[0x17] = 0;
  param_1[0x16] = 0;
  *param_1 = PTR_DAT_00213a45 + 8;
  if (param_1 != (undefined4 *)0x0) {
    FUN_001a7aba(param_1[-1],param_1 + -1);
  }
  return;
}

/* FUN_001aa884 @ 0x1aa884 (977 bytes) */
int FUN_001aa884(param_1, param_2, param_3)
  undefined4 param_1;
  int *param_2;
  undefined4 param_3;
{
  char cVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int *piVar8;
  int *piVar9;
  int local_10;
  
  iVar3 = param_2[0x22];
  if ((((*(int *)(iVar3 + 8) == 0x9e) || (*(int *)(iVar3 + 8) == 0xa0)) ||
      (*(int *)(iVar3 + 8) == 0x9f)) || (*(int *)(iVar3 + 8) == 0xa1)) {
    iVar3 = FUN_0010b0f4(param_2,0);
    if (((*(char *)(iVar3 + 0x10) == '\0') ||
        (iVar3 = FUN_0010b0f4(param_2,0), *(char *)(iVar3 + 0x11) == '\0')) ||
       (iVar3 = FUN_0010b0f4(param_2,0), *(char *)(iVar3 + 0x12) == '\0')) {
      uVar6 = FUN_0010b180(param_2,1);
      cVar1 = FUN_001a05b0(param_3,uVar6,0);
      if (cVar1 == '\0') {
        return 0;
      }
    }
    iVar3 = FUN_0010b0f4(param_2,0);
    if (*(char *)(iVar3 + 0x13) == '\0') {
      uVar6 = FUN_0010b180(param_2,1);
      cVar1 = FUN_001a05b0(param_3,uVar6,1);
      if (cVar1 == '\0') {
        return 0;
      }
    }
  }
  else {
    local_10 = 1;
    iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
    if (0 < iVar3) {
      do {
        piVar4 = (int *)FUN_0010b180(param_2,local_10);
        cVar1 = (**(code **)(*piVar4 + 0x60))(piVar4);
        iVar3 = local_10;
        piVar9 = param_2;
        if (cVar1 != '\0') {
          piVar8 = (int *)FUN_0010b180(piVar4,1);
          iVar3 = 1;
          piVar9 = piVar4;
          piVar4 = piVar8;
        }
        iVar3 = FUN_0010b0f4(piVar9,iVar3);
        uVar5 = FUN_000f5bdc(*(undefined4 *)(iVar3 + 0x10));
        cVar1 = (**(code **)(*piVar4 + 0x5c))(piVar4);
        cVar2 = (char)(uVar5 >> 0x18);
        if (cVar1 == '\0') {
          if ((piVar4[0x26] != 0x33) || (piVar4[0x4b] == 3)) {
            if ((uVar5 & 0xffffff) == 0) {
              if (cVar2 == '\0') goto LAB_001aa957;
              cVar1 = FUN_0019fada(param_3,piVar4,1);
            }
            else if (cVar2 == '\0') {
              cVar1 = FUN_0019fada(param_3,piVar4,0);
            }
            else {
              cVar1 = FUN_0019fbfe(param_3,piVar4,piVar4);
            }
joined_r0x001aaae9:
            if (cVar1 == '\0') {
              return 0;
            }
          }
        }
        else {
          if ((uVar5 & 0xffffff) != 0) {
            iVar3 = (**(code **)(*piVar4 + 0x14))(piVar4);
            if (iVar3 == 1) {
              uVar6 = FUN_0010b180(piVar4,1);
              cVar1 = FUN_001a05b0(param_3,uVar6,0);
            }
            else {
              uVar6 = FUN_0010b180(piVar4,2);
              uVar7 = FUN_0010b180(piVar4,1);
              cVar1 = FUN_0019fff2(param_3,uVar7,uVar6,0);
            }
            if (cVar1 == '\0') {
              return 0;
            }
          }
          if (cVar2 != '\0') {
            iVar3 = (**(code **)(*piVar4 + 0x14))(piVar4);
            if (iVar3 == 1) {
              uVar6 = FUN_0010b180(piVar4,1);
              cVar1 = FUN_001a05b0(param_3,uVar6,1);
            }
            else {
              uVar6 = FUN_0010b180(piVar4,2);
              uVar7 = FUN_0010b180(piVar4,1);
              cVar1 = FUN_0019fff2(param_3,uVar7,uVar6,1);
            }
            goto joined_r0x001aaae9;
          }
        }
LAB_001aa957:
        local_10 = local_10 + 1;
        iVar3 = (**(code **)(*param_2 + 0x14))(param_2);
      } while (local_10 <= iVar3);
    }
  }
  return 1;
}

/* FUN_001aac56 @ 0x1aac56 (1524 bytes) */
int FUN_001aac56(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  code *pcVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  char cVar8;
  uint uVar9;
  undefined4 uVar10;
  int *piVar11;
  int *piVar12;
  int iVar13;
  char local_69;
  int *local_68;
  undefined1 local_54 [55];
  char local_1d [13];
  
  local_69 = param_3;
  local_68 = *(int **)(param_2 + 8);
  if (local_68[2] == 0) {
    return;
  }
  bVar2 = false;
  do {
    cVar8 = (**(code **)(*param_1 + 8))(param_1);
    if (cVar8 != '\0') {
      FUN_000e27ca(param_1[3],5);
    }
    iVar13 = param_1[3];
    if (**(char **)(iVar13 + 0x3f4) == '\0') {
      piVar12 = (int *)FUN_000e514a(param_1[4],param_2,local_68,local_1d);
      if (piVar12 == (int *)0x0) {
        iVar13 = param_1[3];
      }
      else if (local_1d[0] == '\0') {
        iVar13 = param_1[3];
      }
      else {
        iVar13 = param_1[3];
        local_68 = piVar12;
      }
    }
    cVar8 = FUN_0010c6ee(local_68,*(undefined4 *)(iVar13 + 0x3f4));
    if ((((cVar8 == '\0') || (uVar9 = local_68[5], (uVar9 & 4) != 0)) || ((int)uVar9 < 0)) ||
       ((uVar9 & 0x1000) != 0)) {
      FUN_0019ca40(local_54);
      if (local_68 == (int *)0x0) {
        bVar3 = false;
      }
      else {
        bVar3 = false;
        piVar12 = local_68;
        do {
          uVar9 = piVar12[5];
          if ((uVar9 & 1) == 0) {
LAB_001aacf5:
            piVar12 = (int *)piVar12[2];
          }
          else {
            if ((char)uVar9 < '\0') {
              bVar3 = true;
            }
            if ((uVar9 & 0x10000) != 0) goto LAB_001aacf5;
            ((int (*)())FUN_001aa884)(param_1,piVar12,local_54);
            uVar9 = piVar12[5];
            piVar12 = (int *)piVar12[2];
          }
        } while ((piVar12 != (int *)0x0) && ((uVar9 & 4) != 0));
      }
      FUN_0019f54e(local_54,param_1 + 7);
      if (local_68 != (int *)0x0) {
        bVar5 = false;
        bVar7 = false;
        bVar4 = false;
        bVar6 = false;
        piVar12 = local_68;
        do {
          uVar9 = piVar12[5];
          if ((uVar9 & 1) == 0) {
LAB_001aad7a:
            piVar12 = (int *)piVar12[2];
          }
          else {
            pcVar1 = *(code **)(*param_1 + 0x13c);
            uVar10 = FUN_0010b756(piVar12);
            (*pcVar1)(param_1,piVar12[0x47],uVar10);
            if ((piVar12[5] & 0x10000U) == 0) {
              if ((piVar12[5] & 2U) == 0) {
LAB_001aadf6:
                cVar8 = (**(code **)(*piVar12 + 0x28))(piVar12);
                if (cVar8 == '\0') {
                  if (!bVar5) {
                    (**(code **)(*param_1 + 0xc0))(param_1);
                    bVar5 = true;
                  }
                  if (param_1[0x23] == 0) {
                    *(undefined4 *)(*(int *)(param_1[3] + 0x3f4) + 0x3c0) = 1;
                    param_1[0x23] = 2;
                  }
                  else if (param_1[0x23] == 1) {
                    param_1[0x23] = 2;
                    (**(code **)(*param_1 + 0x148))(param_1);
                  }
                  if (!bVar2) {
                    bVar4 = true;
                    goto LAB_001aae31;
                  }
                  bVar4 = true;
                }
                else {
                  iVar13 = param_1[0x23];
                  if (iVar13 == 0) {
                    param_1[0x23] = 1;
                    (**(code **)(*param_1 + 0x134))(param_1);
                  }
                  else {
                    if (iVar13 != 2) {
                      if ((iVar13 != 1) || ((*(byte *)((int)piVar12 + 0x15) & 0x10) == 0))
                      goto LAB_001aae29;
                      (**(code **)(*param_1 + 0x148))(param_1);
                    }
                    param_1[0x23] = 1;
                    (**(code **)(*param_1 + 0x134))(param_1);
                    (**(code **)(*param_1 + 0x138))(param_1);
                  }
LAB_001aae29:
                  bVar2 = false;
                  bVar6 = true;
LAB_001aae31:
                  if (*(int *)(piVar12[0x22] + 8) == 0xb4) {
                    piVar12[5] = piVar12[5] | 0x1000;
                  }
                }
                (**(code **)(*piVar12 + 0x1c))(piVar12,param_1,0,param_1[3]);
                if (!bVar2) {
                  if (((piVar12[5] & 0x1000U) == 0) && (local_69 == '\0')) {
                    if ((piVar12[5] & 2U) != 0) {
                      (**(code **)(*param_1 + 0x14c))(param_1);
                      cVar8 = (**(code **)(*piVar12 + 0x28))(piVar12);
                      goto joined_r0x001aae92;
                    }
                  }
                  else {
                    (**(code **)(*param_1 + 0x14c))(param_1);
                    cVar8 = (**(code **)(*piVar12 + 0x28))(piVar12);
joined_r0x001aae92:
                    if (cVar8 == '\0') {
                      bVar2 = true;
                      local_69 = '\0';
                      goto LAB_001aaea0;
                    }
                  }
                  bVar2 = false;
                  local_69 = '\0';
                }
LAB_001aaea0:
                if (bVar3) {
                  (**(code **)(*param_1 + 0x114))(param_1);
                }
                if ((char)param_1[6] != '\0') {
                  (**(code **)(*param_1 + 0x140))(param_1);
                }
                (**(code **)(*piVar12 + 0x20))(piVar12,param_1,0,param_1[3]);
                cVar8 = (**(code **)(*piVar12 + 0x28))(piVar12);
                if (cVar8 != '\0') {
                  param_1[0x1a] = param_1[0x1a] + 1;
                  (**(code **)(*param_1 + 0x15c))(param_1);
                  uVar9 = piVar12[5];
                  goto LAB_001aad7a;
                }
                goto LAB_001aaee1;
              }
              piVar11 = (int *)FUN_0010b180(piVar12,1);
              cVar8 = (**(code **)(*piVar11 + 0x50))(piVar11);
              if ((cVar8 == '\0') ||
                 (iVar13 = FUN_0010b0f4(piVar12,0), *(int *)(iVar13 + 0x10) != DAT_001cf068))
              goto LAB_001aadf6;
              uVar9 = piVar12[5];
            }
            else {
              cVar8 = (**(code **)(*piVar12 + 0x5c))(piVar12);
              if (cVar8 != '\0') {
                bVar7 = true;
              }
              cVar8 = (**(code **)(*piVar12 + 0x48))(piVar12);
              if (cVar8 != '\0') {
                FUN_001a9218(param_1,piVar12,param_1[3]);
              }
              cVar8 = (**(code **)(*piVar12 + 0x4c))(piVar12);
              if (cVar8 != '\0') {
                ((int (*)())FUN_001aa01e)(param_1,piVar12,param_1[3]);
              }
              cVar8 = (**(code **)(*piVar12 + 0x38))(piVar12);
              if ((cVar8 != '\0') && (param_1[0x23] == 1)) {
                (**(code **)(*param_1 + 0x148))(param_1);
                uVar9 = piVar12[5];
                goto LAB_001aad7a;
              }
LAB_001aaee1:
              uVar9 = piVar12[5];
            }
            piVar12 = (int *)piVar12[2];
          }
        } while ((piVar12 != (int *)0x0) && ((uVar9 & 4) != 0));
        if (bVar4) {
          (**(code **)(*param_1 + 0x15c))(param_1);
          param_1[0x19] = param_1[0x19] + 1;
        }
        else if ((!bVar6) && (bVar7)) {
          (**(code **)(*param_1 + 0x110))(param_1);
        }
      }
    }
    else {
      *(int *)(param_1[4] + 0xc) = *(int *)(param_1[4] + 0xc) + 1;
    }
    uVar9 = local_68[5];
    local_68 = (int *)local_68[2];
    iVar13 = local_68[2];
    while( true ) {
      if (iVar13 == 0) {
        return;
      }
      if ((uVar9 & 4) == 0) break;
      uVar9 = local_68[5];
      local_68 = (int *)local_68[2];
      iVar13 = local_68[2];
    }
  } while( true );
}

/* FUN_001ab24a @ 0x1ab24a (684 bytes) */
int FUN_001ab24a(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  char *param_2;
  undefined4 *param_3;
  int param_4;
  undefined4 *param_5;
  undefined4 *param_6;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  *param_3 = 0;
  param_3[1] = 0;
  param_2[0] = '\0';
  param_2[1] = '\0';
  param_2[2] = '\0';
  param_2[3] = '\0';
  param_2[4] = '\0';
  param_2[5] = '\0';
  param_2[6] = '\0';
  param_2[7] = '\0';
  iVar2 = *(int *)(*(int *)(param_4 + 0x88) + 8);
  if (iVar2 == 0x35) {
    FUN_00109c0e(param_4 + 0xbc,1,*(byte *)(param_4 + 0xd0) & 1 ^ 1);
    uVar3 = FUN_00118f66(0x34);
    *(undefined4 *)(param_4 + 0x88) = uVar3;
    iVar2 = 0x34;
  }
  uVar3 = *(undefined4 *)(PTR_DAT_00213a35 + iVar2 * 0x38 + 0x34);
  uVar1 = ((int (*)())FUN_001a92da)(param_1[0x29],iVar2);
  *param_5 = uVar1;
  uVar1 = ((int (*)())FUN_001a9320)(param_1[0x29],iVar2);
  *param_6 = uVar1;
  iVar2 = FUN_0010b0f4(param_4,0);
  param_1[0x28] = *(int *)(iVar2 + 0x10);
  switch(uVar3) {
  case 0:
    if ((((char)param_1[0x28] == '\0') || (*(char *)((int)param_1 + 0xa1) == '\0')) ||
       (*(char *)((int)param_1 + 0xa2) == '\0')) {
      uVar4 = 1;
    }
    else {
      uVar4 = 0;
    }
    if (*(char *)((int)param_1 + 0xa3) == '\0') {
      uVar4 = uVar4 | 2;
    }
    *param_2 = -((char)param_1[0x28] == '\0');
    param_2[1] = -(*(char *)((int)param_1 + 0xa1) == '\0');
    param_2[2] = -(*(char *)((int)param_1 + 0xa2) == '\0');
    *(char *)((int)param_3 + 3) = -(*(char *)((int)param_1 + 0xa3) == '\0');
    break;
  case 1:
    if (*(char *)((int)param_1 + 0xa3) == '\0') {
      *param_6 = 1;
      uVar4 = 7;
    }
    else {
      uVar4 = 5;
    }
    *param_2 = -1;
    param_2[1] = -1;
    param_2[6] = -1;
    break;
  case 2:
    if (*(char *)((int)param_1 + 0xa3) == '\0') {
      *param_6 = 1;
      uVar4 = 3;
    }
    else {
      uVar4 = 1;
    }
    *param_2 = -1;
    param_2[1] = -1;
    param_2[2] = -1;
    break;
  case 3:
    uVar4 = 3;
    goto LAB_001ab378;
  default:
    uVar4 = 0;
    break;
  case 5:
    if ((((char)param_1[0x28] == '\0') || (*(char *)((int)param_1 + 0xa1) == '\0')) ||
       (*(char *)((int)param_1 + 0xa2) == '\0')) {
      *param_5 = 10;
      (**(code **)(*param_1 + 0x150))(param_1,10);
      uVar4 = 0xb;
    }
    else {
      uVar4 = 2;
    }
    *(undefined1 *)((int)param_3 + 3) = 0xff;
    break;
  case 8:
    uVar4 = 0x13;
LAB_001ab378:
    *param_6 = 1;
    *param_2 = -1;
    param_2[1] = -1;
    param_2[2] = -1;
    *(undefined1 *)((int)param_3 + 3) = 0xff;
    return uVar4;
  }
  return uVar4;
}

/* FUN_001ab51e @ 0x1ab51e (675 bytes) */
int FUN_001ab51e(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined2 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  undefined1 local_20;
  
  piVar5 = (int *)FUN_0010b180(param_2,1);
  uVar4 = FUN_0013c4e0(*(undefined4 *)(param_4 + 0x3f4),piVar5);
  cVar3 = (**(code **)(**(int **)(param_4 + 0x54) + 0x7c))(*(int **)(param_4 + 0x54),param_2);
  if (cVar3 == '\0') {
    FUN_0010b0f4(param_2,0);
  }
  *(undefined4 *)(param_1[0x16] + param_1[0x18] * 0x48) = 2;
  *(undefined2 *)(param_1[0x16] + 0xe + param_1[0x18] * 0x48) = uVar4;
  iVar7 = *(int *)(*(int *)(param_2 + 0x88) + 8);
  iVar1 = *(int *)(param_2 + 0x134);
  if (iVar7 == 0x77) {
    *(undefined2 *)(param_1[0x16] + 0xc + param_1[0x18] * 0x48) = 0;
    *(undefined4 *)(FUN_00009369 + param_1[0x17] + 7) = 1;
    *(undefined1 *)(param_1[0x16] + 0x19 + param_1[0x18] * 0x48) = 0;
    iVar6 = (**(code **)(*piVar5 + 0x80))(piVar5);
  }
  else {
    local_20 = (undefined1)iVar1;
    *(undefined1 *)(param_1[0x16] + 0x19 + param_1[0x18] * 0x48) = local_20;
    iVar6 = param_1[0x18];
    iVar2 = param_1[0x16];
    uVar4 = FUN_0013c4e0(*(undefined4 *)(param_4 + 0x3f4),param_2);
    *(undefined2 *)(iVar2 + iVar6 * 0x48 + 0xc) = uVar4;
    iVar6 = (**(code **)(*piVar5 + 0x80))(piVar5);
  }
  if (iVar6 == 0) {
    *(undefined4 *)(param_1[0x17] + 0x9378 + iVar1 * 4) = 1;
  }
  if (*(int *)(PTR_DAT_00213a35 + iVar7 * 0x38 + 0xc) != -1) {
    *(char *)(param_1[0x16] + 0x1a + param_1[0x18] * 0x48) =
         (char)*(int *)(PTR_DAT_00213a35 + iVar7 * 0x38 + 0xc);
  }
  iVar1 = *(int *)(*(int *)(*(int *)(param_4 + 0x3f4) + 0x78) + 4 + iVar1 * 0xc);
  if (iVar1 == 2) {
    bVar8 = 0xc;
  }
  else if (iVar1 == 3) {
    bVar8 = 8;
  }
  else if (iVar1 == 1) {
    bVar8 = 0xe;
  }
  else {
    bVar8 = 0;
  }
  if (iVar7 == 0x77) {
    *(undefined1 *)(param_1[0x16] + 0x1f + param_1[0x18] * 0x48) = 0;
    piVar5 = (int *)FUN_0010b180(param_2,1);
    iVar7 = (**(code **)(*piVar5 + 0x80))(piVar5);
  }
  else {
    if (iVar7 - 0x75U < 2) {
      *(byte *)(param_1[0x16] + 0x1f + param_1[0x18] * 0x48) = bVar8 & 7;
    }
    else {
      *(byte *)(param_1[0x16] + 0x1f + param_1[0x18] * 0x48) = bVar8;
    }
    piVar5 = (int *)FUN_0010b180(param_2,1);
    iVar7 = (**(code **)(*piVar5 + 0x80))(piVar5);
  }
  if (iVar7 != 0) {
                    
                    
    (**(code **)(*param_1 + 0x154))();
    return;
  }
  return;
}

/* FUN_001ab7c2 @ 0x1ab7c2 (180 bytes) */
int FUN_001ab7c2(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  float fVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_20 [4];
  
  iVar2 = FUN_0010b180(param_5,param_2);
  iVar3 = FUN_0010b0f4(param_5,param_2);
  local_20[0] = *(undefined4 *)(iVar3 + 0x10);
  iVar3 = 0;
  do {
    if (*(byte *)((int)local_20 + iVar3) < 4) {
      uVar4 = (uint)*(byte *)((int)local_20 + iVar3);
      goto LAB_001ab80c;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 4);
  uVar4 = 0;
LAB_001ab80c:
  fVar1 = *(float *)(iVar2 + 0x20 + uVar4 * 0x18);
  if ((fVar1 != FLOAT_001c5b9c) || (NAN(fVar1) || NAN(FLOAT_001c5b9c))) {
    if ((fVar1 == FLOAT_001c5bd4) && (!NAN(fVar1) && !NAN(FLOAT_001c5bd4))) {
      *(undefined4 *)(param_3 + param_2 * 4) = 0x16;
      return;
    }
    if ((fVar1 == FLOAT_001c5ba4) && (!NAN(fVar1) && !NAN(FLOAT_001c5ba4))) {
      *(undefined4 *)(param_3 + param_2 * 4) = 0x15;
      return;
    }
  }
  else {
    *(undefined4 *)(param_3 + param_2 * 4) = 0x14;
  }
  return;
}

/* FUN_001ab876 @ 0x1ab876 (180 bytes) */
int FUN_001ab876(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  float fVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_20 [4];
  
  iVar2 = FUN_0010b180(param_5,param_2);
  iVar3 = FUN_0010b0f4(param_5,param_2);
  local_20[0] = *(undefined4 *)(iVar3 + 0x10);
  iVar3 = 0;
  do {
    if (*(byte *)((int)local_20 + iVar3) < 4) {
      uVar4 = (uint)*(byte *)((int)local_20 + iVar3);
      goto LAB_001ab8c0;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 4);
  uVar4 = 0;
LAB_001ab8c0:
  fVar1 = *(float *)(iVar2 + 0x20 + uVar4 * 0x18);
  if ((fVar1 != FLOAT_001c5b9c) || (NAN(fVar1) || NAN(FLOAT_001c5b9c))) {
    if ((fVar1 == FLOAT_001c5bd4) && (!NAN(fVar1) && !NAN(FLOAT_001c5bd4))) {
      *(undefined4 *)(param_3 + param_2 * 4) = 0x12;
      return;
    }
    if ((fVar1 == FLOAT_001c5ba4) && (!NAN(fVar1) && !NAN(FLOAT_001c5ba4))) {
      *(undefined4 *)(param_3 + param_2 * 4) = 0x11;
      return;
    }
  }
  else {
    *(undefined4 *)(param_3 + param_2 * 4) = 0x10;
  }
  return;
}

/* FUN_001ab92a @ 0x1ab92a (155 bytes) */
int FUN_001ab92a(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  int param_5;
{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  
  if (param_2 != 0) {
    *(undefined2 *)(*(int *)(param_1 + 0x58) + 0xc + *(int *)(param_1 + 0x60) * 0x48) = param_5;
    iVar1 = *(int *)(param_1 + 0x60);
    iVar2 = *(int *)(param_1 + 0x58);
    iVar4 = FUN_0010b0f4(param_4,0);
    uVar3 = FUN_001a90b8(*(undefined4 *)(iVar4 + 0x10));
    *(undefined1 *)(iVar2 + iVar1 * 0x48 + 0x14) = uVar3;
  }
  if (param_3 != 0) {
    *(undefined2 *)(*(int *)(param_1 + 0x58) + 0x18 + *(int *)(param_1 + 0x60) * 0x48) = param_5;
    iVar1 = *(int *)(param_1 + 0x60);
    iVar2 = *(int *)(param_1 + 0x58);
    iVar4 = FUN_0010b0f4(param_4,0);
    *(bool *)(iVar2 + iVar1 * 0x48 + 0x20) = *(char *)(iVar4 + 0x13) == '\0';
  }
  return;
}

/* FUN_001ab9c6 @ 0x1ab9c6 (258 bytes) */
int FUN_001ab9c6(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  undefined1 local_10;
  
  iVar1 = *(int *)(param_4 + 0x98);
  iVar2 = *(int *)(param_4 + 0x94);
  if (iVar1 == 9) {
    iVar4 = iVar2 + 1;
    iVar5 = *(int *)(*(int *)(param_1 + 0x5c) + 0x9374);
    if (iVar4 <= iVar5) {
      iVar4 = iVar5;
    }
    *(int *)(*(int *)(param_1 + 0x5c) + 0x9374) = iVar4;
  }
  local_10 = (undefined1)iVar2;
  if ((param_2 != '\0') && (iVar1 != 8)) {
    *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x16 + *(int *)(param_1 + 0x60) * 0x48) = local_10;
    iVar2 = *(int *)(param_1 + 0x60);
    iVar5 = *(int *)(param_1 + 0x58);
    iVar4 = FUN_0010b0f4(param_4,0);
    uVar3 = FUN_001a90b8(*(undefined4 *)(iVar4 + 0x10));
    *(undefined1 *)(iVar5 + iVar2 * 0x48 + 0x15) = uVar3;
  }
  if (param_3 != '\0') {
    *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x22 + *(int *)(param_1 + 0x60) * 0x48) = local_10;
    if (iVar1 == 8) {
      *(undefined1 *)(*(int *)(param_1 + 0x58) + 0x23 + *(int *)(param_1 + 0x60) * 0x48) = 1;
      return;
    }
    iVar1 = *(int *)(param_1 + 0x60);
    iVar2 = *(int *)(param_1 + 0x58);
    iVar5 = FUN_0010b0f4(param_4,0);
    *(bool *)(iVar2 + iVar1 * 0x48 + 0x21) = *(char *)(iVar5 + 0x13) == '\0';
  }
  return;
}

/* FUN_001abac8 @ 0x1abac8 (9545 bytes) */
int FUN_001abac8(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  bool bVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  char cVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  int *piVar13;
  int *piVar14;
  int iVar15;
  uint uVar16;
  undefined4 uVar17;
  byte bVar18;
  byte bVar19;
  int iVar20;
  code *pcVar21;
  bool bVar22;
  bool bVar23;
  int local_11c;
  int local_108;
  int local_104;
  int local_f4;
  int local_f0;
  char local_ea;
  int *local_e8;
  int local_e0;
  int local_dc;
  int local_d4;
  int local_d0;
  int local_cc;
  int local_c8;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int *local_a4;
  int *local_a0;
  int *local_9c;
  int *local_98;
  int *local_94;
  char local_90;
  char local_8e;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 auStack_6c [5];
  undefined4 local_58 [4];
  undefined4 local_48 [4];
  undefined4 local_38 [4];
  int local_28;
  undefined4 local_24;
  undefined4 local_20 [4];
  
  uVar9 = ((int (*)())FUN_001ab24a)(param_1,&local_88,&local_78,param_2,local_20,&local_24);
  iVar1 = *(int *)(param_2[0x22] + 8);
  bVar19 = (byte)uVar9 & 1;
  uVar10 = uVar9 >> 1;
  bVar18 = (byte)uVar10 & 1;
  uVar11 = uVar9 >> 4;
  iVar20 = 1;
  puVar4 = auStack_6c + 1;
  puVar5 = auStack_6c + 9;
  puVar6 = auStack_6c + 0xd;
  puVar7 = auStack_6c + 5;
  do {
    auStack_6c[iVar20] = 0;
    auStack_6c[iVar20 + 8] = 0;
    auStack_6c[iVar20 + 0xc] = 0;
    auStack_6c[iVar20 + 4] = 0;
    iVar20 = iVar20 + 1;
  } while (iVar20 != 5);
  local_f4 = (**(code **)(*param_2 + 0x14))(param_2);
  if (iVar1 == 0xb4) {
    local_f4 = 3;
  }
  else if (local_f4 < 1) goto LAB_001abbeb;
  local_f0 = 1;
  local_11c = 0x98;
  do {
    iVar20 = FUN_0010b0f4(param_2,local_f0);
    local_104 = *(int *)(iVar20 + 0x10);
    local_28 = -1;
    piVar13 = (int *)FUN_0010b180(param_2,local_f0);
    local_108 = DAT_001cf05c;
    cVar8 = (**(code **)(*piVar13 + 0x60))(piVar13);
    if (cVar8 == '\0') {
      bVar2 = false;
      local_e8 = (int *)0x0;
      piVar14 = piVar13;
    }
    else {
      iVar20 = FUN_0010b0f4(piVar13,1);
      uVar12 = *(undefined4 *)(iVar20 + 0x10);
      iVar20 = FUN_0010b0f4(param_2,local_f0);
      local_108 = *(int *)(iVar20 + 0x10);
      local_104 = FUN_000f5610(uVar12,local_108);
      piVar14 = (int *)FUN_0010b180(piVar13,1);
      FUN_0010ba02(param_2,local_f0,piVar14,0,param_1[3]);
      local_e8 = piVar13;
      if (local_f0 == 0) {
        param_2[0x27] = local_104;
        bVar2 = true;
      }
      else {
        iVar20 = FUN_0010b0f4(param_2,local_f0);
        *(int *)(iVar20 + 0x10) = local_104;
        bVar2 = true;
      }
    }
    if (piVar14[0x26] != 0x2c) {
      if (piVar14[0x26] == 0x29) {
        local_28 = (**(code **)(*param_1 + 0x158))(param_1,param_2,local_f0,param_1[3]);
        uVar12 = local_88;
        uVar17 = local_84;
        uVar3 = local_38[2];
joined_r0x001ac018:
        local_38[2] = uVar3;
        if ((local_f0 == 3) && (local_38[2] = 0x11, (uVar11 & 1) == 0)) {
          local_38[2] = uVar3;
        }
        local_88 = uVar12;
        local_84 = uVar17;
        if ((uVar9 & 1) != 0) {
          if (local_f0 == 3) {
            if ((uVar11 & 1) != 0) goto joined_r0x001abe60;
            if ((uVar9 >> 2 & 1) == 0) goto LAB_001ac043;
            local_ea = FUN_001a8ff4(local_104,uVar17);
            cVar8 = FUN_001a905c(local_104,uVar17);
          }
          else {
LAB_001ac043:
            local_ea = FUN_001a8ff4(local_104,uVar12);
            cVar8 = FUN_001a905c(local_104,uVar12);
          }
          puVar4[local_f0] = 0x14;
          iVar20 = local_f0;
          if (local_ea == '\0') {
            if (cVar8 != '\0') {
              local_9c = param_1;
              local_c8 = 1;
              do {
                local_b0 = local_c8 + -1;
                piVar13 = (int *)local_9c[7];
                if ((piVar14 == piVar13) ||
                   (((((piVar13 != (int *)0x0 && (piVar14 != (int *)0x0)) && (piVar13[0x20] != 0))
                     && (((cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 != '\0' &&
                          ((*(byte *)(piVar13 + 5) & 2) == 0)) &&
                         ((cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 == '\0' &&
                          ((piVar14[0x20] != 0 &&
                           (cVar8 = FUN_0012dfd8(piVar14[0x26]), cVar8 != '\0')))))))) &&
                    (((*(byte *)(piVar14 + 5) & 2) == 0 &&
                     ((((cVar8 = (**(code **)(*piVar14 + 0x50))(piVar14), cVar8 == '\0' &&
                        ((*(byte *)(local_9c[7] + 0x14) & 0x40) != 0)) &&
                       ((*(byte *)(piVar14 + 5) & 0x40) != 0)) &&
                      (*(int *)(local_9c[7] + 0x94) == piVar14[0x25])))))))) {
                  param_1[local_c8 + 0xd] = local_28;
                  param_1[0x20] = param_1[0x20] | 1 << ((byte)local_c8 & 0x1f);
                  goto LAB_001ac45d;
                }
                local_c8 = local_c8 + 1;
                local_9c = local_9c + 1;
              } while (local_c8 != 4);
              local_b0 = 3;
LAB_001ac45d:
              pcVar21 = *(code **)(*param_1 + 0xf8);
              if (local_f0 == 3) {
                iVar20 = (-(uint)((uVar11 & 1) == 0) & 2) + 1;
              }
              goto LAB_001ac48b;
            }
          }
          else if (cVar8 == '\0') {
            local_98 = param_1;
            local_cc = 1;
            do {
              local_a8 = local_cc + -1;
              piVar13 = (int *)local_98[10];
              if ((piVar14 == piVar13) ||
                 (((((((piVar13 != (int *)0x0 && (piVar14 != (int *)0x0)) && (piVar13[0x20] != 0))
                     && ((cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 != '\0' &&
                         ((*(byte *)(piVar13 + 5) & 2) == 0)))) &&
                    (cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 == '\0')) &&
                   ((piVar14[0x20] != 0 && (cVar8 = FUN_0012dfd8(piVar14[0x26]), cVar8 != '\0'))))
                  && ((((*(byte *)(piVar14 + 5) & 2) == 0 &&
                       (((cVar8 = (**(code **)(*piVar14 + 0x50))(piVar14), cVar8 == '\0' &&
                         ((*(byte *)(local_98[10] + 0x14) & 0x40) != 0)) &&
                        ((*(byte *)(piVar14 + 5) & 0x40) != 0)))) &&
                      (*(int *)(local_98[10] + 0x94) == piVar14[0x25])))))) {
                param_1[local_cc + 0x11] = local_28;
                param_1[0x21] = param_1[0x21] | 1 << ((byte)local_cc & 0x1f);
                goto LAB_001ac105;
              }
              local_cc = local_cc + 1;
              local_98 = local_98 + 1;
            } while (local_cc != 4);
            local_a8 = 3;
LAB_001ac105:
            (**(code **)(*param_1 + 0xf4))(param_1,local_f0,puVar4,puVar5,local_a8,local_104);
          }
          else {
            local_94 = param_1;
            local_d0 = 1;
            do {
              local_ac = local_d0 + -1;
              piVar13 = (int *)local_94[7];
              if (((piVar14 == piVar13) ||
                  (((piVar13 != (int *)0x0 && (piVar14 != (int *)0x0)) &&
                   (((((piVar13[0x20] != 0 &&
                       ((cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 != '\0' &&
                        ((*(byte *)(piVar13 + 5) & 2) == 0)))) &&
                      (cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 == '\0')) &&
                     (((piVar14[0x20] != 0 && (cVar8 = FUN_0012dfd8(piVar14[0x26]), cVar8 != '\0'))
                      && ((*(byte *)(piVar14 + 5) & 2) == 0)))) &&
                    (((cVar8 = (**(code **)(*piVar14 + 0x50))(piVar14), cVar8 == '\0' &&
                      ((*(byte *)(local_94[7] + 0x14) & 0x40) != 0)) &&
                     (((*(byte *)(piVar14 + 5) & 0x40) != 0 &&
                      (*(int *)(local_94[7] + 0x94) == piVar14[0x25])))))))))) &&
                 ((piVar13 = (int *)local_94[10], piVar14 == piVar13 ||
                  ((((piVar13 != (int *)0x0 && (piVar14 != (int *)0x0)) &&
                    ((piVar13[0x20] != 0 &&
                     (((cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 != '\0' &&
                       ((*(byte *)(piVar13 + 5) & 2) == 0)) &&
                      (cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 == '\0')))))) &&
                   (((((piVar14[0x20] != 0 && (cVar8 = FUN_0012dfd8(piVar14[0x26]), cVar8 != '\0'))
                      && ((*(byte *)(piVar14 + 5) & 2) == 0)) &&
                     ((cVar8 = (**(code **)(*piVar14 + 0x50))(piVar14), cVar8 == '\0' &&
                      ((*(byte *)(local_94[10] + 0x14) & 0x40) != 0)))) &&
                    (((*(byte *)(piVar14 + 5) & 0x40) != 0 &&
                     (*(int *)(local_94[10] + 0x94) == piVar14[0x25])))))))))) {
                param_1[local_d0 + 0xd] = local_28;
                param_1[local_d0 + 0x11] = local_28;
                uVar16 = 1 << ((byte)local_d0 & 0x1f);
                param_1[0x20] = param_1[0x20] | uVar16;
                param_1[0x21] = param_1[0x21] | uVar16;
                goto LAB_001ac5a1;
              }
              local_d0 = local_d0 + 1;
              local_94 = local_94 + 1;
            } while (local_d0 != 4);
            local_ac = 3;
LAB_001ac5a1:
            (**(code **)(*param_1 + 0xf4))(param_1,local_f0,puVar4,puVar5,local_ac,local_104);
            pcVar21 = *(code **)(*param_1 + 0xf8);
            local_b0 = local_ac;
            if (local_f0 == 3) {
              iVar20 = (-(uint)((uVar11 & 1) == 0) & 2) + 1;
            }
LAB_001ac48b:
            (*pcVar21)(param_1,iVar20,puVar4,puVar5,local_b0,local_104);
          }
        }
joined_r0x001abe60:
        if ((uVar10 & 1) != 0) {
          iVar20 = FUN_0010b0f4(param_2,local_f0);
          uVar3 = local_74;
          uVar17 = local_78;
          uVar12 = *(undefined4 *)(iVar20 + 0x10);
          if ((local_f0 == 3) && ((uVar9 >> 2 & 1) != 0)) {
            local_90 = FUN_001a8ff4(uVar12,local_74);
            local_8e = FUN_001a905c(uVar12,uVar3);
          }
          else {
            local_90 = FUN_001a8ff4(uVar12,local_78);
            local_8e = FUN_001a905c(uVar12,uVar17);
          }
          puVar6[local_f0] = 0x10;
          if (local_90 != '\0') {
            local_a0 = param_1;
            local_c0 = 1;
            do {
              local_b8 = local_c0 + -1;
              piVar13 = (int *)local_a0[10];
              if ((piVar14 == piVar13) ||
                 ((((piVar13 != (int *)0x0 && (piVar14 != (int *)0x0)) &&
                   ((piVar13[0x20] != 0 &&
                    (((cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 != '\0' &&
                      ((*(byte *)(piVar13 + 5) & 2) == 0)) &&
                     (cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 == '\0')))))) &&
                  (((piVar14[0x20] != 0 && (cVar8 = FUN_0012dfd8(piVar14[0x26]), cVar8 != '\0')) &&
                   (((*(byte *)(piVar14 + 5) & 2) == 0 &&
                    (((cVar8 = (**(code **)(*piVar14 + 0x50))(piVar14), cVar8 == '\0' &&
                      ((*(byte *)(local_a0[10] + 0x14) & 0x40) != 0)) &&
                     (((*(byte *)(piVar14 + 5) & 0x40) != 0 &&
                      (*(int *)(local_a0[10] + 0x94) == piVar14[0x25])))))))))))) {
                param_1[local_c0 + 0x11] = local_28;
                param_1[0x21] = param_1[0x21] | 1 << ((byte)local_c0 & 0x1f);
                goto LAB_001ac23f;
              }
              local_c0 = local_c0 + 1;
              local_a0 = local_a0 + 1;
            } while (local_c0 != 4);
            local_b8 = 3;
LAB_001ac23f:
            iVar20 = local_f0;
            if (local_f0 == 3) {
              iVar20 = (-(uint)((uVar11 & 1) == 0) & 2) + 1;
            }
            (**(code **)(*param_1 + 0xfc))(param_1,iVar20,puVar6,puVar7,local_b8,uVar12);
          }
          if (local_8e != '\0') {
            local_a4 = param_1;
            local_bc = 1;
            do {
              local_b4 = local_bc + -1;
              piVar13 = (int *)local_a4[7];
              if ((piVar14 == piVar13) ||
                 ((((((piVar13 != (int *)0x0 && (piVar14 != (int *)0x0)) && (piVar13[0x20] != 0)) &&
                    ((cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 != '\0' &&
                     ((*(byte *)(piVar13 + 5) & 2) == 0)))) &&
                   ((cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 == '\0' &&
                    ((piVar14[0x20] != 0 && (cVar8 = FUN_0012dfd8(piVar14[0x26]), cVar8 != '\0')))))
                   ) && (((*(byte *)(piVar14 + 5) & 2) == 0 &&
                         ((((cVar8 = (**(code **)(*piVar14 + 0x50))(piVar14), cVar8 == '\0' &&
                            ((*(byte *)(local_a4[7] + 0x14) & 0x40) != 0)) &&
                           ((*(byte *)(piVar14 + 5) & 0x40) != 0)) &&
                          (*(int *)(local_a4[7] + 0x94) == piVar14[0x25])))))))) {
                param_1[local_bc + 0xd] = local_28;
                param_1[0x20] = param_1[0x20] | 1 << ((byte)local_bc & 0x1f);
                goto LAB_001ac308;
              }
              local_bc = local_bc + 1;
              local_a4 = local_a4 + 1;
            } while (local_bc != 4);
            local_b4 = 3;
LAB_001ac308:
            iVar20 = local_f0;
            if (local_f0 == 3) {
              iVar20 = (-(uint)((uVar11 & 1) == 0) & 2) + 1;
            }
            (**(code **)(*param_1 + 0x100))(param_1,iVar20,puVar6,puVar7,local_b4,uVar12);
          }
        }
      }
      else {
        if ((((piVar14[0x20] != 0) && (cVar8 = FUN_0012dfd8(piVar14[0x26]), cVar8 != '\0')) &&
            ((*(byte *)(piVar14 + 5) & 2) == 0)) &&
           (cVar8 = (**(code **)(*piVar14 + 0x50))(piVar14), cVar8 == '\0')) {
          local_28 = FUN_0013c422(*(undefined4 *)(param_1[3] + 0x3f4),piVar14);
          iVar20 = (**(code **)(*piVar14 + 0x80))(piVar14);
          uVar12 = local_88;
          uVar17 = local_84;
          uVar3 = local_38[2];
          if (iVar20 != 0) {
            (**(code **)(*param_1 + 0x154))(param_1,local_f0,param_2,param_1[3]);
            uVar12 = local_88;
            uVar17 = local_84;
            uVar3 = local_38[2];
          }
          goto joined_r0x001ac018;
        }
        cVar8 = (**(code **)(*piVar14 + 0x50))(piVar14);
        if (cVar8 != '\0') {
          local_28 = FUN_0013c4e0(*(undefined4 *)(param_1[3] + 0x3f4),piVar14);
          uVar12 = local_88;
          uVar17 = local_84;
          uVar3 = local_38[2];
          goto joined_r0x001ac018;
        }
        cVar8 = (**(code **)(*piVar14 + 0x48))(piVar14);
        if (cVar8 != '\0') {
          if (piVar14[0x26] == 0x33) {
            cVar8 = (**(code **)(*param_1 + 0xdc))(param_1,piVar14,&local_28);
            uVar12 = local_88;
            uVar17 = local_84;
            uVar3 = local_38[2];
            if (cVar8 == '\0') {
              if ((local_f0 == 3) && ((uVar11 & 1) != 0)) {
                local_38[2] = 0x11;
                (**(code **)(*param_1 + 0xd8))(param_1,3,puVar6,puVar7,param_2);
              }
              else {
                if ((uVar9 & 1) != 0) {
                  (**(code **)(*param_1 + 0xd4))(param_1,local_f0,puVar4,puVar5,param_2);
                }
                if ((uVar10 & 1) != 0) {
                  (**(code **)(*param_1 + 0xd8))(param_1,local_f0,puVar6,puVar7,param_2);
                }
              }
              goto LAB_001abe66;
            }
          }
          else {
            local_28 = piVar14[0x25];
            ((int (*)())FUN_001a9e6c)(param_1,local_28,piVar14);
            local_28 = (**(code **)(*param_1 + 0xe0))(param_1,local_28);
            uVar12 = local_88;
            uVar17 = local_84;
            uVar3 = local_38[2];
          }
          goto joined_r0x001ac018;
        }
        cVar8 = (**(code **)(*piVar14 + 0x5c))(piVar14);
        uVar12 = local_88;
        uVar17 = local_84;
        uVar3 = local_38[2];
        if (cVar8 == '\0') goto joined_r0x001ac018;
        if ((local_f0 == 3) && ((uVar11 & 1) != 0)) {
          local_38[2] = 0x11;
          (**(code **)(*param_1 + 0xf0))(param_1,1,puVar6,puVar7,local_104);
        }
        else {
          if ((uVar9 & 1) != 0) {
            (**(code **)(*param_1 + 0xec))(param_1,local_f0,puVar4,puVar5,local_104);
          }
          if ((uVar10 & 1) != 0) {
            (**(code **)(*param_1 + 0xf0))(param_1,local_f0,puVar6,puVar7,local_104);
          }
        }
        uVar16 = FUN_000f5bdc(local_104);
        bVar22 = (uVar16 & 0xffffff) != 0;
        bVar23 = (char)(uVar16 >> 0x18) != '\0';
        iVar20 = *(int *)(piVar14[0x22] + 8);
        iVar15 = (**(code **)(*piVar14 + 0x14))(piVar14);
        if (bVar22) {
          param_1[0x20] = param_1[0x20] | iVar15 * 4 - 2U;
          (**(code **)(*param_1 + 0xe4))
                    (param_1,*(undefined4 *)(PTR_DAT_00213a35 + iVar20 * 0x38 + 0xc));
        }
        if (bVar23) {
          param_1[0x21] = param_1[0x21] | iVar15 * 4 - 2U;
          (**(code **)(*param_1 + 0xe8))
                    (param_1,*(undefined4 *)(PTR_DAT_00213a35 + iVar20 * 0x38 + 0xc));
        }
        if (iVar15 < 2) {
          if (iVar15 != 1) goto LAB_001abe66;
          piVar13 = (int *)FUN_0010b180(piVar14,1);
          if (((piVar13[0x20] == 0) || (cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 == '\0')) ||
             (((*(byte *)(piVar13 + 5) & 2) != 0 ||
              (cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 != '\0')))) {
            piVar13 = (int *)FUN_0010b180(piVar14,1);
            cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13);
            if (cVar8 != '\0') goto LAB_001acfe8;
            piVar13 = (int *)FUN_0010b180(piVar14,1);
            cVar8 = (**(code **)(*piVar13 + 0x48))(piVar13);
            if (cVar8 == '\0') {
              local_d4 = 0;
            }
            else {
              iVar20 = FUN_0010b180(piVar14,1);
              uVar12 = *(undefined4 *)(iVar20 + 0x94);
              uVar17 = FUN_0010b180(piVar14,1);
              ((int (*)())FUN_001a9e6c)(param_1,uVar12,uVar17);
              local_d4 = (**(code **)(*param_1 + 0xe0))(param_1,uVar12);
            }
          }
          else {
LAB_001acfe8:
            uVar12 = FUN_0010b180(piVar14,1);
            local_d4 = FUN_0013c4e0(*(undefined4 *)(param_1[3] + 0x3f4),uVar12);
          }
          if (bVar22) {
            iVar20 = FUN_0010b180(piVar14,1);
            if ((((iVar20 != param_1[7]) && (iVar20 = FUN_0010b180(piVar14,1), iVar20 != 0)) &&
                (param_1[7] != 0)) &&
               ((((piVar13 = (int *)FUN_0010b180(piVar14,1), piVar13[0x20] != 0 &&
                  (cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 != '\0')) &&
                 (((*(byte *)(piVar13 + 5) & 2) == 0 &&
                  ((cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 == '\0' &&
                   (piVar13 = (int *)param_1[7], piVar13[0x20] != 0)))))) &&
                ((cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 != '\0' &&
                 (((((*(byte *)(piVar13 + 5) & 2) == 0 &&
                    (cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 == '\0')) &&
                   (iVar20 = FUN_0010b180(piVar14,1), (*(byte *)(iVar20 + 0x14) & 0x40) != 0)) &&
                  ((*(byte *)(param_1[7] + 0x14) & 0x40) != 0)))))))) {
              FUN_0010b180(piVar14,1);
            }
            param_1[0xe] = local_d4;
          }
          if (bVar23) {
            iVar20 = FUN_0010b180(piVar14,1);
            if (((((((iVar20 != param_1[10]) && (iVar20 = FUN_0010b180(piVar14,1), iVar20 != 0)) &&
                   ((param_1[10] != 0 &&
                    ((piVar13 = (int *)FUN_0010b180(piVar14,1), piVar13[0x20] != 0 &&
                     (cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 != '\0')))))) &&
                  ((*(byte *)(piVar13 + 5) & 2) == 0)) &&
                 (((cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 == '\0' &&
                   (piVar13 = (int *)param_1[10], piVar13[0x20] != 0)) &&
                  (cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 != '\0')))) &&
                (((*(byte *)(piVar13 + 5) & 2) == 0 &&
                 (cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 == '\0')))) &&
               ((iVar20 = FUN_0010b180(piVar14,1), (*(byte *)(iVar20 + 0x14) & 0x40) != 0 &&
                ((*(byte *)(param_1[10] + 0x14) & 0x40) != 0)))) {
              FUN_0010b180(piVar14,1);
            }
            param_1[0x12] = local_d4;
          }
        }
        else {
          piVar13 = (int *)FUN_0010b180(piVar14,1);
          if (((piVar13[0x20] == 0) || (cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 == '\0')) ||
             (((*(byte *)(piVar13 + 5) & 2) != 0 ||
              (cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 != '\0')))) {
            piVar13 = (int *)FUN_0010b180(piVar14,1);
            cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13);
            if (cVar8 != '\0') goto LAB_001ac7f8;
            piVar13 = (int *)FUN_0010b180(piVar14,1);
            cVar8 = (**(code **)(*piVar13 + 0x48))(piVar13);
            if (cVar8 == '\0') {
              local_e0 = 0;
            }
            else {
              iVar15 = FUN_0010b180(piVar14,1);
              uVar12 = *(undefined4 *)(iVar15 + 0x94);
              uVar17 = FUN_0010b180(piVar14,1);
              ((int (*)())FUN_001a9e6c)(param_1,uVar12,uVar17);
              local_e0 = (**(code **)(*param_1 + 0xe0))(param_1,uVar12);
            }
          }
          else {
LAB_001ac7f8:
            uVar12 = FUN_0010b180(piVar14,1);
            local_e0 = FUN_0013c4e0(*(undefined4 *)(param_1[3] + 0x3f4),uVar12);
          }
          piVar13 = (int *)FUN_0010b180(piVar14,2);
          if ((((piVar13[0x20] == 0) || (cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 == '\0')) ||
              ((*(byte *)(piVar13 + 5) & 2) != 0)) ||
             (cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 != '\0')) {
            piVar13 = (int *)FUN_0010b180(piVar14,2);
            cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13);
            if (cVar8 != '\0') goto LAB_001ac866;
            piVar13 = (int *)FUN_0010b180(piVar14,2);
            cVar8 = (**(code **)(*piVar13 + 0x48))(piVar13);
            if (cVar8 == '\0') {
              local_dc = 0;
            }
            else {
              iVar15 = FUN_0010b180(piVar14,2);
              uVar12 = *(undefined4 *)(iVar15 + 0x94);
              uVar17 = FUN_0010b180(piVar14,2);
              ((int (*)())FUN_001a9e6c)(param_1,uVar12,uVar17);
              local_dc = (**(code **)(*param_1 + 0xe0))(param_1,uVar12);
            }
          }
          else {
LAB_001ac866:
            uVar12 = FUN_0010b180(piVar14,2);
            local_dc = FUN_0013c4e0(*(undefined4 *)(param_1[3] + 0x3f4),uVar12);
          }
          if (bVar22) {
            iVar15 = FUN_0010b180(piVar14,1);
            if (((iVar15 != param_1[8]) &&
                ((((iVar15 = FUN_0010b180(piVar14,1), iVar15 == 0 || (param_1[8] == 0)) ||
                  (((piVar13 = (int *)FUN_0010b180(piVar14,1), piVar13[0x20] == 0 ||
                    ((cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 == '\0' ||
                     ((*(byte *)(piVar13 + 5) & 2) != 0)))) ||
                   (cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 != '\0')))) ||
                 ((((((piVar13 = (int *)param_1[8], piVar13[0x20] == 0 ||
                      (cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 == '\0')) ||
                     ((*(byte *)(piVar13 + 5) & 2) != 0)) ||
                    ((cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 != '\0' ||
                     (iVar15 = FUN_0010b180(piVar14,1), (*(byte *)(iVar15 + 0x14) & 0x40) == 0))))
                   || ((*(byte *)(param_1[8] + 0x14) & 0x40) == 0)) ||
                  (iVar15 = FUN_0010b180(piVar14,1),
                  *(int *)(iVar15 + 0x94) != *(int *)(param_1[8] + 0x94))))))) ||
               ((iVar15 = FUN_0010b180(piVar14,2), iVar15 != param_1[7] &&
                (((((iVar15 = FUN_0010b180(piVar14,2), iVar15 == 0 || (param_1[7] == 0)) ||
                   ((piVar13 = (int *)FUN_0010b180(piVar14,2), piVar13[0x20] == 0 ||
                    (((cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 == '\0' ||
                      ((*(byte *)(piVar13 + 5) & 2) != 0)) ||
                     (cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 != '\0')))))) ||
                  ((piVar13 = (int *)param_1[7], piVar13[0x20] == 0 ||
                   (cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 == '\0')))) ||
                 (((*(byte *)(piVar13 + 5) & 2) != 0 ||
                  (((cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 != '\0' ||
                    (iVar15 = FUN_0010b180(piVar14,2), (*(byte *)(iVar15 + 0x14) & 0x40) == 0)) ||
                   (((*(byte *)(param_1[7] + 0x14) & 0x40) == 0 ||
                    (iVar15 = FUN_0010b180(piVar14,2),
                    *(int *)(iVar15 + 0x94) != *(int *)(param_1[7] + 0x94))))))))))))) {
              iVar15 = FUN_0010b180(piVar14,1);
              if (((iVar15 == param_1[7]) ||
                  (((((iVar15 = FUN_0010b180(piVar14,1), iVar15 != 0 && (param_1[7] != 0)) &&
                     (piVar13 = (int *)FUN_0010b180(piVar14,1), piVar13[0x20] != 0)) &&
                    (((cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 != '\0' &&
                      ((*(byte *)(piVar13 + 5) & 2) == 0)) &&
                     ((cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 == '\0' &&
                      ((piVar13 = (int *)param_1[7], piVar13[0x20] != 0 &&
                       (cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 != '\0')))))))) &&
                   (((*(byte *)(piVar13 + 5) & 2) == 0 &&
                    ((((cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 == '\0' &&
                       (iVar15 = FUN_0010b180(piVar14,1), (*(byte *)(iVar15 + 0x14) & 0x40) != 0))
                      && ((*(byte *)(param_1[7] + 0x14) & 0x40) != 0)) &&
                     (iVar15 = FUN_0010b180(piVar14,1),
                     *(int *)(iVar15 + 0x94) == *(int *)(param_1[7] + 0x94))))))))) &&
                 ((iVar15 = FUN_0010b180(piVar14,2), iVar15 == param_1[8] ||
                  (((((iVar15 = FUN_0010b180(piVar14,2), iVar15 != 0 && (param_1[8] != 0)) &&
                     ((piVar13 = (int *)FUN_0010b180(piVar14,2), piVar13[0x20] != 0 &&
                      ((cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 != '\0' &&
                       ((*(byte *)(piVar13 + 5) & 2) == 0)))))) &&
                    (cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 == '\0')) &&
                   ((((piVar13 = (int *)param_1[8], piVar13[0x20] != 0 &&
                      (cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 != '\0')) &&
                     ((*(byte *)(piVar13 + 5) & 2) == 0)) &&
                    (((cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 == '\0' &&
                      (iVar15 = FUN_0010b180(piVar14,2), (*(byte *)(iVar15 + 0x14) & 0x40) != 0)) &&
                     (((*(byte *)(param_1[8] + 0x14) & 0x40) != 0 &&
                      (iVar15 = FUN_0010b180(piVar14,2),
                      *(int *)(iVar15 + 0x94) == *(int *)(param_1[8] + 0x94))))))))))))) {
                param_1[0xe] = local_e0;
                param_1[0xf] = local_dc;
                if ((iVar20 == 0x9a) && ((*(byte *)(local_11c + 0x20 + (int)param_2) & 2) == 0)) {
                  bVar22 = true;
                  goto LAB_001ac8a8;
                }
              }
              goto LAB_001ac8a1;
            }
            param_1[0xf] = local_e0;
            param_1[0xe] = local_dc;
            bVar22 = false;
          }
          else {
LAB_001ac8a1:
            bVar22 = false;
          }
LAB_001ac8a8:
          if (bVar23) {
            iVar15 = FUN_0010b180(piVar14,1);
            if (((iVar15 != param_1[0xb]) &&
                ((((((iVar15 = FUN_0010b180(piVar14,1), iVar15 == 0 || (param_1[0xb] == 0)) ||
                    (piVar13 = (int *)FUN_0010b180(piVar14,1), piVar13[0x20] == 0)) ||
                   (((cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 == '\0' ||
                     ((*(byte *)(piVar13 + 5) & 2) != 0)) ||
                    ((cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 != '\0' ||
                     ((piVar13 = (int *)param_1[0xb], piVar13[0x20] == 0 ||
                      (cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 == '\0')))))))) ||
                  ((*(byte *)(piVar13 + 5) & 2) != 0)) ||
                 ((((cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 != '\0' ||
                    (iVar15 = FUN_0010b180(piVar14,1), (*(byte *)(iVar15 + 0x14) & 0x40) == 0)) ||
                   ((*(byte *)(param_1[0xb] + 0x14) & 0x40) == 0)) ||
                  (iVar15 = FUN_0010b180(piVar14,1),
                  *(int *)(iVar15 + 0x94) != *(int *)(param_1[0xb] + 0x94))))))) ||
               ((iVar15 = FUN_0010b180(piVar14,2), iVar15 != param_1[10] &&
                ((((iVar15 = FUN_0010b180(piVar14,2), iVar15 == 0 || (param_1[10] == 0)) ||
                  ((((piVar13 = (int *)FUN_0010b180(piVar14,2), piVar13[0x20] == 0 ||
                     ((cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 == '\0' ||
                      ((*(byte *)(piVar13 + 5) & 2) != 0)))) ||
                    (cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 != '\0')) ||
                   (((piVar13 = (int *)param_1[10], piVar13[0x20] == 0 ||
                     (cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 == '\0')) ||
                    ((*(byte *)(piVar13 + 5) & 2) != 0)))))) ||
                 (((cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 != '\0' ||
                   (iVar15 = FUN_0010b180(piVar14,2), (*(byte *)(iVar15 + 0x14) & 0x40) == 0)) ||
                  (((*(byte *)(param_1[10] + 0x14) & 0x40) == 0 ||
                   (iVar15 = FUN_0010b180(piVar14,2),
                   *(int *)(iVar15 + 0x94) != *(int *)(param_1[10] + 0x94))))))))))) {
              iVar15 = FUN_0010b180(piVar14,1);
              if (((iVar15 == param_1[10]) ||
                  (((iVar15 = FUN_0010b180(piVar14,1), iVar15 != 0 && (param_1[10] != 0)) &&
                   ((((piVar13 = (int *)FUN_0010b180(piVar14,1), piVar13[0x20] != 0 &&
                      (((cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 != '\0' &&
                        ((*(byte *)(piVar13 + 5) & 2) == 0)) &&
                       (cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 == '\0')))) &&
                     (((piVar13 = (int *)param_1[10], piVar13[0x20] != 0 &&
                       (cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 != '\0')) &&
                      ((*(byte *)(piVar13 + 5) & 2) == 0)))) &&
                    (((cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 == '\0' &&
                      (iVar15 = FUN_0010b180(piVar14,1), (*(byte *)(iVar15 + 0x14) & 0x40) != 0)) &&
                     (((*(byte *)(param_1[10] + 0x14) & 0x40) != 0 &&
                      (iVar15 = FUN_0010b180(piVar14,1),
                      *(int *)(iVar15 + 0x94) == *(int *)(param_1[10] + 0x94))))))))))) &&
                 ((iVar15 = FUN_0010b180(piVar14,2), iVar15 == param_1[0xb] ||
                  (((((((iVar15 = FUN_0010b180(piVar14,2), iVar15 != 0 && (param_1[0xb] != 0)) &&
                       (piVar13 = (int *)FUN_0010b180(piVar14,2), piVar13[0x20] != 0)) &&
                      ((cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 != '\0' &&
                       ((*(byte *)(piVar13 + 5) & 2) == 0)))) &&
                     (cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 == '\0')) &&
                    ((piVar13 = (int *)param_1[0xb], piVar13[0x20] != 0 &&
                     (cVar8 = FUN_0012dfd8(piVar13[0x26]), cVar8 != '\0')))) &&
                   ((((*(byte *)(piVar13 + 5) & 2) == 0 &&
                     (((cVar8 = (**(code **)(*piVar13 + 0x50))(piVar13), cVar8 == '\0' &&
                       (iVar15 = FUN_0010b180(piVar14,2), (*(byte *)(iVar15 + 0x14) & 0x40) != 0))
                      && ((*(byte *)(param_1[0xb] + 0x14) & 0x40) != 0)))) &&
                    (iVar15 = FUN_0010b180(piVar14,2),
                    *(int *)(iVar15 + 0x94) == *(int *)(param_1[0xb] + 0x94))))))))) {
                param_1[0x12] = local_e0;
                param_1[0x13] = local_dc;
                if ((iVar20 == 0x9a) && ((*(byte *)(local_11c + 0x20 + (int)param_2) & 2) == 0)) {
                  bVar23 = true;
                  goto LAB_001ac8b7;
                }
              }
              goto LAB_001ac8b5;
            }
            param_1[0x13] = local_e0;
            param_1[0x12] = local_dc;
            bVar23 = false;
          }
          else {
LAB_001ac8b5:
            bVar23 = false;
          }
LAB_001ac8b7:
          if ((bVar22) || (bVar23)) {
            FUN_00109c0e((int)param_2 + local_11c + 0xc,1,
                         *(byte *)(local_11c + 0x20 + (int)param_2) & 1 ^ 1);
          }
        }
      }
LAB_001abe66:
      if (bVar2) {
        if ((uVar10 & 1) != 0) {
          (**(code **)(*param_1 + 0x10c))(param_1,local_f0,puVar7,local_e8,local_108);
        }
        if ((uVar9 & 1) != 0) {
          (**(code **)(*param_1 + 0x108))(param_1,local_f0,puVar5,local_e8,local_108);
        }
        FUN_0010ba02(param_2,local_f0,local_e8,0,param_1[3]);
        if (local_f0 == 0) {
          param_2[0x27] = local_108;
        }
        else {
          iVar20 = FUN_0010b0f4(param_2,local_f0);
          *(int *)(iVar20 + 0x10) = local_108;
        }
      }
    }
    local_f0 = local_f0 + 1;
    local_11c = local_11c + 0x18;
  } while (local_f0 <= local_f4);
LAB_001abbeb:
  (**(code **)(*param_1 + 0x118))(param_1,param_1[0x20],param_1 + 0xd,param_1[0x21],param_1 + 0x11);
  (**(code **)(*param_1 + 0x11c))
            (param_1,param_2,bVar19,puVar4,puVar5,bVar18,puVar6,puVar7,(byte)uVar11 & 1);
  if (param_2[0x26] == 0x2c) {
    (**(code **)(*param_1 + 0x124))(param_1,bVar19,bVar18,param_2);
  }
  else if (((((param_2[0x20] == 0) || (cVar8 = FUN_0012dfd8(param_2[0x26]), cVar8 == '\0')) ||
            ((*(byte *)(param_2 + 5) & 2) != 0)) ||
           (cVar8 = (**(code **)(*param_2 + 0x50))(param_2), cVar8 != '\0')) &&
          (cVar8 = (**(code **)(*param_2 + 0x50))(param_2), cVar8 == '\0')) {
    if ((param_2[5] & 2U) == 0) {
      if ((param_2[5] & 0x80000U) != 0) {
        (**(code **)(*param_1 + 0x128))(param_1,bVar19,bVar18,param_2);
      }
    }
    else {
      (**(code **)(*param_1 + 0x124))(param_1,bVar19,bVar18,param_2);
    }
  }
  else {
    pcVar21 = *(code **)(*param_1 + 0x120);
    uVar12 = FUN_0013c4e0(*(undefined4 *)(param_1[3] + 0x3f4),param_2);
    (*pcVar21)(param_1,bVar19,bVar18,param_2,uVar12);
  }
  if ((uVar9 & 1) != 0) {
    (**(code **)(*param_1 + 300))(param_1,local_20[0],iVar1,param_2);
  }
  if ((uVar10 & 1) != 0) {
    (**(code **)(*param_1 + 0x130))(param_1,local_24,iVar1,param_2);
  }
  return;
}

/* FUN_001ae012 @ 0x1ae012 (10 bytes) */
int FUN_001ae012(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_1 <= param_2) {
    param_1 = param_2;
  }
  return param_1;
}

/* FUN_001ae01c @ 0x1ae01c (95 bytes) */
int FUN_001ae01c(param_1)
  int param_1;
{
  **(undefined4 **)(param_1 + 0x50) =
       *(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 0x54) + 0x40);
  *(uint *)(*(int *)(param_1 + 0x50) + 0xc) = (uint)*(byte *)(param_1 + 0x24);
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x10) = *(undefined4 *)(param_1 + 0x58);
  *(int *)(*(int *)(param_1 + 0x50) + 0x14) = *(int *)(param_1 + 0x34) + 1;
  *(int *)(*(int *)(param_1 + 0x50) + 0x18) = *(int *)(param_1 + 0x38) + 1;
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(*(int *)(param_1 + 0x50) + 0x20) = *(undefined4 *)(param_1 + 0x30);
  *(int *)(*(int *)(param_1 + 0x50) + 0x24) = *(int *)(param_1 + 0x4c) + 1;
  return;
}

/* FUN_001ae07c @ 0x1ae07c (21 bytes) */
int FUN_001ae07c(param_1)
  int param_1;
{
  *(undefined1 *)(*(int *)(param_1 + 0x58) * 0x10 + *(int *)(param_1 + 0x44)) = 0;
  return;
}

/* FUN_001ae092 @ 0x1ae092 (28 bytes) */
int FUN_001ae092(param_1)
  int param_1;
{
  ((int (*)())FUN_001ae07c)(param_1);
  *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0x58) + 1;
  return;
}

/* FUN_001ae0ae @ 0x1ae0ae (174 bytes) */
int FUN_001ae0ae(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  FUN_000e1c3e(*(undefined4 *)(param_1 + 0xc),
               "Assembler : emits %d cf, %d alu -> %d total instruction(s)\n",
               *(int *)(param_1 + 0x5c),*(int *)(param_1 + 0x58),
               *(int *)(param_1 + 0x5c) + *(int *)(param_1 + 0x58));
  FUN_000e1c3e(*(undefined4 *)(param_1 + 0xc),
               "INFO:# of control flow %d, # of exec %d instructions\n",
               *(undefined4 *)(param_1 + 0x5c),*(undefined4 *)(param_1 + 0x58));
  if (param_2 == '\0') {
    iVar1 = *(int *)(param_1 + 0x78);
    if (iVar1 == 0) {
      iVar2 = 0;
      iVar3 = *(int *)(param_1 + 0x74);
    }
    else {
      iVar3 = *(int *)(param_1 + 0x74);
      iVar2 = (iVar3 * 100) / iVar1;
    }
    FUN_000e1c3e(*(undefined4 *)(param_1 + 0xc),
                 "Assembler : of %d candidate alu instruction(s), %d are packed (%%%d)\n",iVar1,
                 iVar3,iVar2);
  }
  return;
}

/* FUN_001ae15c @ 0x1ae15c (26 bytes) */
int FUN_001ae15c(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
                    
                    
  (**(code **)(*param_2 + 0x44))();
  return;
}

