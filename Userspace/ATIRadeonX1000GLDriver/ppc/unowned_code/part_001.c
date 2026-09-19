#include "decls.h"

/* orph_d9f78 @ 0xd9f78 (8 bytes) */
int orph_d9f78()
{
  return 1;
}

/* orph_da880 @ 0xda880 (40 bytes) */
int orph_da880(param_1)
  undefined4 *param_1;
{
  param_1[0x87] = 0;
  *param_1 = 0;
  param_1[0x84] = 0;
  param_1[0x85] = 0;
  param_1[0x86] = 0;
                    
                    
  (*(code *)PTR_FUN_001e876c)(param_1 + 4,0,0x200);
  return;
}

/* orph_e2084 @ 0xe2084 (8 bytes) */
int orph_e2084(param_1)
  int param_1;
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x310) != 0) {
    FUN_0010defc(*(int *)(param_1 + 0x310),param_1);
    (**(code **)(param_1 + 0x34c))
              (*(undefined4 *)(param_1 + 0x354),*(undefined4 *)(param_1 + 0x310));
  }
  iVar1 = param_1;
  do {
    if (*(int *)(iVar1 + 0x370) != 0) {
      FUN_00193d18();
      (**(code **)(param_1 + 0x34c))
                (*(undefined4 *)(param_1 + 0x354),*(undefined4 *)(iVar1 + 0x370));
      *(undefined4 *)(iVar1 + 0x370) = 0;
    }
    iVar1 = iVar1 + 4;
  } while (iVar1 != param_1 + 0xc);
  return;
}

/* orph_e208c @ 0xe208c (8 bytes) */
int orph_e208c(param_1)
  int param_1;
{
  int iVar1;
  
  if (*(int *)(param_1 + 0x310) != 0) {
    FUN_0010defc(*(int *)(param_1 + 0x310),param_1);
    (**(code **)(param_1 + 0x34c))
              (*(undefined4 *)(param_1 + 0x354),*(undefined4 *)(param_1 + 0x310));
  }
  iVar1 = param_1;
  do {
    if (*(int *)(iVar1 + 0x370) != 0) {
      FUN_00193d18();
      (**(code **)(param_1 + 0x34c))
                (*(undefined4 *)(param_1 + 0x354),*(undefined4 *)(iVar1 + 0x370));
      *(undefined4 *)(iVar1 + 0x370) = 0;
    }
    iVar1 = iVar1 + 4;
  } while (iVar1 != param_1 + 0xc);
  return;
}

/* orph_e2884 @ 0xe2884 (36 bytes) */
int orph_e2884(param_1, param_2)
  int param_1;
  int param_2;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 100))
            (*(int **)(param_2 + 0x20),param_1,param_1 + 0x90,*(undefined4 *)(param_1 + 0xa8));
  return;
}

/* orph_e28a8 @ 0xe28a8 (36 bytes) */
int orph_e28a8(param_1, param_2)
  int param_1;
  int param_2;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x70))
            (*(int **)(param_2 + 0x20),param_1,param_1 + 0x90,*(undefined4 *)(param_1 + 0xa8));
  return;
}

/* orph_e28cc @ 0xe28cc (36 bytes) */
int orph_e28cc(param_1, param_2)
  int param_1;
  int param_2;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x68))
            (*(int **)(param_2 + 0x20),param_1,param_1 + 0x90,*(undefined4 *)(param_1 + 0xa8));
  return;
}

/* orph_e2950 @ 0xe2950 (36 bytes) */
int orph_e2950(param_1, param_2)
  int param_1;
  int param_2;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x60))
            (*(int **)(param_2 + 0x20),param_1,param_1 + 0x90,*(undefined4 *)(param_1 + 0xa8));
  return;
}

/* orph_e2974 @ 0xe2974 (36 bytes) */
int orph_e2974(param_1, param_2)
  int param_1;
  int param_2;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x78))
            (*(int **)(param_2 + 0x20),param_1,param_1 + 0x90,*(undefined4 *)(param_1 + 0xa8));
  return;
}

/* orph_e2998 @ 0xe2998 (36 bytes) */
int orph_e2998(param_1, param_2)
  int param_1;
  int param_2;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x7c))
            (*(int **)(param_2 + 0x20),param_1,param_1 + 0x90,*(undefined4 *)(param_1 + 0xa8));
  return;
}

/* orph_e29bc @ 0xe29bc (36 bytes) */
int orph_e29bc(param_1, param_2)
  int param_1;
  int param_2;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x80))
            (*(int **)(param_2 + 0x20),param_1,param_1 + 0x90,*(undefined4 *)(param_1 + 0xa8));
  return;
}

/* orph_e29e0 @ 0xe29e0 (36 bytes) */
int orph_e29e0(param_1, param_2)
  int param_1;
  int param_2;
{
                    
                    
  (**(code **)(**(int **)(param_2 + 0x20) + 0x84))
            (*(int **)(param_2 + 0x20),param_1,param_1 + 0x90,*(undefined4 *)(param_1 + 0xa8));
  return;
}

/* orph_e7650 @ 0xe7650 (8 bytes) */
int orph_e7650(param_1, param_2)
  undefined4 param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2[2];
  iVar1 = *param_2;
  *(int *)(iVar2 + 4) = param_2[1];
  *(int *)(param_2[1] + 8) = iVar2;
                    
                    
  (**(code **)(iVar1 + 4))();
  return;
}

/* orph_ec1e4 @ 0xec1e4 (8 bytes) */
int orph_ec1e4()
{
  return 0;
}

/* orph_ed29c @ 0xed29c (8 bytes) */
int orph_ed29c(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
{
  int iVar1;
  int iVar2;
  int iVar3;
  double dVar4;
  undefined4 uStack_38;
  undefined4 auStack_34 [8];
  
  if (param_2 == 0) {
    FUN_000e1534(param_4,0xf);
  }
  iVar1 = FUN_001054ec(param_2,0);
  if (*(int *)(iVar1 + 0x10) != DAT_001aa800) {
    iVar2 = FUN_001043f0(0x31,param_4);
    dVar4 = (double)FLOAT_001aa0d4;
    FUN_000f79c4(dVar4,dVar4,dVar4,(double)FLOAT_001aa0e8,iVar2,*(undefined4 *)(param_4 + 0x6c4),1);
    FUN_001046c8(iVar2,0,*(undefined4 *)(param_2 + 0xa4));
    iVar3 = FUN_001054ec(param_2,0);
    iVar1 = 0;
    auStack_34[0] = *(undefined4 *)(iVar3 + 0x10);
    iVar3 = 4;
    do {
      *(byte *)((int)auStack_34 + iVar1 + -4) =
           (byte)(-(*(byte *)((int)auStack_34 + iVar1) ^ 1) >> 0x1f);
      iVar1 = iVar1 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *(undefined4 *)(iVar2 + 0x9c) = uStack_38;
    FUN_000e76c4(*(undefined4 *)(param_2 + 0x158),iVar2);
    *(int *)(param_2 + 0x9c) = DAT_001aa800;
  }
  return;
}

/* orph_f3bc0 @ 0xf3bc0 (4 bytes) */
int orph_f3bc0(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  bool bVar2;
  
  if (param_2 == 0) {
    iVar1 = FUN_001054ec();
    bVar2 = *(int *)(iVar1 + 0x10) == _UNK_001aa84c;
  }
  else {
    iVar1 = FUN_001054ec();
    bVar2 = *(int *)(iVar1 + 0x10) == _UNK_001aa848;
  }
  return 1 - (uint)bVar2;
}

/* orph_f89b4 @ 0xf89b4 (4 bytes) */
int orph_f89b4(param_1)
  uint param_1;
{
  if (5 < param_1) {
    return 8;
  }
  return *(undefined4 *)(PTR_DAT_001e8b84 + param_1 * 4);
}

/* orph_10451c @ 0x10451c (32 bytes) */
int orph_10451c(param_1, param_2)
  int *param_1;
  int param_2;
{
                    
                    
  (**(code **)(*param_1 + 0xc))
            (param_1,*(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) >> 7 & 1,param_2);
  return;
}

/* orph_10b32c @ 0x10b32c (8 bytes) */
int orph_10b32c(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined8 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  switch(param_2) {
  case 0:
    uVar2 = 0x2a;
    bVar1 = false;
    break;
  case 1:
    uVar2 = 0x27;
    bVar1 = false;
    break;
  case 2:
    uVar2 = 0x29;
    bVar1 = true;
    break;
  case 3:
    uVar2 = 0x28;
    bVar1 = true;
    break;
  case 4:
    uVar2 = 0x29;
    bVar1 = false;
    break;
  case 5:
    uVar2 = 0x28;
    bVar1 = false;
    break;
  default:
    uVar2 = 0;
    bVar1 = false;
  }
  uVar5 = *(undefined4 *)(param_6 + 0x6c4);
  iVar3 = FUN_001043f0(uVar2,param_6);
  iVar4 = FUN_001054ec(iVar3,2 - (uint)!bVar1);
  *(undefined4 *)(iVar4 + 0xc) = param_4;
  *(undefined4 *)(iVar4 + 8) = param_3;
  if (!bVar1) {
    uVar2 = 2;
  }
  else {
    uVar2 = 1;
  }
  FUN_000f79c4(param_1,param_1,param_1,param_1,iVar3,uVar5,uVar2);
  iVar6 = *(int *)(param_6 + 0x3ac) + -1;
  *(int *)(param_6 + 0x3ac) = iVar6;
  iVar4 = FUN_001054ec(iVar3,0);
  uVar2 = _UNK_001af9d8;
  *(undefined4 *)(iVar4 + 0xc) = 0;
  *(int *)(iVar4 + 8) = iVar6;
  *(undefined4 *)(iVar3 + 0x9c) = uVar2;
  return iVar3;
}

/* orph_10b3b4 @ 0x10b3b4 (184 bytes) */
int orph_10b3b4()
{
  int iVar1;
  int iVar2;
  undefined4 unaff_r26;
  undefined4 unaff_r27;
  int unaff_r28;
  undefined4 uVar3;
  int iVar4;
  int unaff_r31;
  
  uVar3 = *(undefined4 *)(unaff_r28 + 0x6c4);
  iVar1 = FUN_001043f0(0x27,unaff_r28);
  iVar2 = FUN_001054ec(iVar1,1);
  *(undefined4 *)(iVar2 + 0xc) = unaff_r27;
  *(undefined4 *)(iVar2 + 8) = unaff_r26;
  FUN_000f79c4(iVar1,uVar3,2);
  iVar4 = *(int *)(unaff_r28 + 0x3ac) + -1;
  *(int *)(unaff_r28 + 0x3ac) = iVar4;
  iVar2 = FUN_001054ec(iVar1,0);
  uVar3 = *(undefined4 *)(unaff_r31 + 0xa469c);
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(int *)(iVar2 + 8) = iVar4;
  *(undefined4 *)(iVar1 + 0x9c) = uVar3;
  return iVar1;
}

/* orph_10b3c0 @ 0x10b3c0 (184 bytes) */
int orph_10b3c0()
{
  int iVar1;
  int iVar2;
  undefined4 unaff_r26;
  undefined4 unaff_r27;
  int unaff_r28;
  undefined4 uVar3;
  int iVar4;
  int unaff_r31;
  
  uVar3 = *(undefined4 *)(unaff_r28 + 0x6c4);
  iVar1 = FUN_001043f0(0x2a,unaff_r28);
  iVar2 = FUN_001054ec(iVar1,1);
  *(undefined4 *)(iVar2 + 0xc) = unaff_r27;
  *(undefined4 *)(iVar2 + 8) = unaff_r26;
  FUN_000f79c4(iVar1,uVar3,2);
  iVar4 = *(int *)(unaff_r28 + 0x3ac) + -1;
  *(int *)(unaff_r28 + 0x3ac) = iVar4;
  iVar2 = FUN_001054ec(iVar1,0);
  uVar3 = *(undefined4 *)(unaff_r31 + 0xa469c);
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(int *)(iVar2 + 8) = iVar4;
  *(undefined4 *)(iVar1 + 0x9c) = uVar3;
  return iVar1;
}

/* orph_10b3cc @ 0x10b3cc (184 bytes) */
int orph_10b3cc()
{
  int iVar1;
  int iVar2;
  undefined4 unaff_r26;
  undefined4 unaff_r27;
  int unaff_r28;
  undefined4 uVar3;
  int iVar4;
  int unaff_r31;
  
  uVar3 = *(undefined4 *)(unaff_r28 + 0x6c4);
  iVar1 = FUN_001043f0(0x28,unaff_r28);
  iVar2 = FUN_001054ec(iVar1,2);
  *(undefined4 *)(iVar2 + 0xc) = unaff_r27;
  *(undefined4 *)(iVar2 + 8) = unaff_r26;
  FUN_000f79c4(iVar1,uVar3,1);
  iVar4 = *(int *)(unaff_r28 + 0x3ac) + -1;
  *(int *)(unaff_r28 + 0x3ac) = iVar4;
  iVar2 = FUN_001054ec(iVar1,0);
  uVar3 = *(undefined4 *)(unaff_r31 + 0xa469c);
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(int *)(iVar2 + 8) = iVar4;
  *(undefined4 *)(iVar1 + 0x9c) = uVar3;
  return iVar1;
}

/* orph_10b3d8 @ 0x10b3d8 (184 bytes) */
int orph_10b3d8()
{
  int iVar1;
  int iVar2;
  undefined4 unaff_r26;
  undefined4 unaff_r27;
  int unaff_r28;
  undefined4 uVar3;
  int iVar4;
  int unaff_r31;
  
  uVar3 = *(undefined4 *)(unaff_r28 + 0x6c4);
  iVar1 = FUN_001043f0(0x29,unaff_r28);
  iVar2 = FUN_001054ec(iVar1,2);
  *(undefined4 *)(iVar2 + 0xc) = unaff_r27;
  *(undefined4 *)(iVar2 + 8) = unaff_r26;
  FUN_000f79c4(iVar1,uVar3,1);
  iVar4 = *(int *)(unaff_r28 + 0x3ac) + -1;
  *(int *)(unaff_r28 + 0x3ac) = iVar4;
  iVar2 = FUN_001054ec(iVar1,0);
  uVar3 = *(undefined4 *)(unaff_r31 + 0xa469c);
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(int *)(iVar2 + 8) = iVar4;
  *(undefined4 *)(iVar1 + 0x9c) = uVar3;
  return iVar1;
}

/* orph_10b3e4 @ 0x10b3e4 (180 bytes) */
int orph_10b3e4()
{
  int iVar1;
  int iVar2;
  undefined4 unaff_r26;
  undefined4 unaff_r27;
  int unaff_r28;
  undefined4 uVar3;
  int iVar4;
  int unaff_r31;
  
  uVar3 = *(undefined4 *)(unaff_r28 + 0x6c4);
  iVar1 = FUN_001043f0(0x28,unaff_r28);
  iVar2 = FUN_001054ec(iVar1,1);
  *(undefined4 *)(iVar2 + 0xc) = unaff_r27;
  *(undefined4 *)(iVar2 + 8) = unaff_r26;
  FUN_000f79c4(iVar1,uVar3,2);
  iVar4 = *(int *)(unaff_r28 + 0x3ac) + -1;
  *(int *)(unaff_r28 + 0x3ac) = iVar4;
  iVar2 = FUN_001054ec(iVar1,0);
  uVar3 = *(undefined4 *)(unaff_r31 + 0xa469c);
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(int *)(iVar2 + 8) = iVar4;
  *(undefined4 *)(iVar1 + 0x9c) = uVar3;
  return iVar1;
}

/* orph_10dcfc @ 0x10dcfc (12 bytes) */
int orph_10dcfc(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  FUN_000e1534(*(undefined4 *)(param_2 + 8),0xf);
  return;
}

/* orph_10ddf4 @ 0x10ddf4 (8 bytes) */
int orph_10ddf4()
{
  return 0xb5;
}

/* orph_12841c @ 0x12841c (20 bytes) */
int orph_12841c(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  FUN_000f4a84(*(undefined4 *)(*(int *)(param_5 + 0x6c4) + 0x3ac),param_3,param_4);
  return;
}

/* orph_128ad4 @ 0x128ad4 (4 bytes) */
int orph_128ad4(param_1, param_2, param_3)
  undefined4 param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  double dVar10;
  
  if (param_2 == 1) {
    iVar6 = *(int *)(param_3 + 0x6c4);
    iVar2 = FUN_00127534(*(undefined4 *)(iVar6 + 0x3ac),0x1b,0,0);
    if (iVar2 != 0) {
      FUN_001041d0(*(undefined4 *)(iVar2 + 0x38),3,3,8,0);
      uVar3 = *(undefined4 *)(iVar6 + 0x3ac);
      iVar5 = *(int *)(param_3 + 0x3ac) + -1;
      *(int *)(param_3 + 0x3ac) = iVar5;
      iVar7 = 0;
      uVar3 = FUN_001275a0(uVar3,0,iVar5,0);
      for (uVar8 = 1; uVar8 <= *(uint *)(*(int *)(iVar2 + 0x14) + 4); uVar8 = uVar8 + 1) {
        iVar5 = *(int *)(iVar7 + *(int *)(*(int *)(iVar2 + 0x14) + 8));
        if (((*(uint *)(iVar5 + 0x14) & 1) != 0) && (iVar9 = 1, 0 < *(int *)(iVar5 + 0x84))) {
          do {
            if (*(int *)(iVar9 * 0x18 + iVar5 + 0x98) == 0x1b) {
              FUN_001046c8(iVar5,iVar9,uVar3);
            }
            iVar9 = iVar9 + 1;
          } while (iVar9 <= *(int *)(iVar5 + 0x84));
        }
        iVar7 = iVar7 + 4;
      }
      iVar5 = FUN_000d9f3c(*(undefined4 *)(param_3 + 0x398),0);
      if (iVar5 == 0) {
        piVar4 = (int *)FUN_001043f0(0x14,param_3);
        FUN_001046c8(piVar4,0,uVar3);
        FUN_001046c8(piVar4,1,iVar2);
        uVar1 = DAT_001aff48;
        iVar5 = FUN_001054ec(piVar4,1);
        dVar10 = (double)FLOAT_001aa108;
        *(undefined4 *)(iVar5 + 0x10) = uVar1;
        FUN_000f79c4(dVar10,dVar10,dVar10,dVar10,piVar4,*(undefined4 *)(param_3 + 0x6c4),2);
        FUN_00103d50(piVar4 + 0x2f,1,1);
        dVar10 = (double)FLOAT_001aa0e8;
        FUN_000f79c4(dVar10,dVar10,dVar10,dVar10,piVar4,*(undefined4 *)(param_3 + 0x6c4),3);
        FUN_001236e4(iVar2,1,piVar4);
        FUN_0012306c(uVar3,piVar4);
        FUN_000e7688(*(undefined4 *)(iVar6 + 0x3a0),piVar4);
        (**(code **)(*piVar4 + 8))(piVar4,param_3);
      }
      else {
        piVar4 = (int *)FUN_001043f0(0x31,param_3);
        FUN_001046c8(piVar4,0,uVar3);
        FUN_001046c8(piVar4,1,iVar2);
        uVar1 = DAT_001affa4;
        iVar5 = FUN_001054ec(piVar4,1);
        *(undefined4 *)(iVar5 + 0x10) = uVar1;
        FUN_001236e4(iVar2,1,piVar4);
        FUN_0012306c(uVar3,piVar4);
        FUN_000e7688(*(undefined4 *)(iVar6 + 0x3a0),piVar4);
        (**(code **)(*piVar4 + 8))(piVar4,param_3);
      }
    }
  }
  return;
}

/* orph_129400 @ 0x129400 (8 bytes) */
int orph_129400()
{
  return 0x20;
}

/* orph_129ea0 @ 0x129ea0 (20 bytes) */
int orph_129ea0(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
{
  FUN_000f4a84(*(undefined4 *)(*(int *)(param_5 + 0x6c4) + 0x3ac),param_3,param_4);
  return;
}

/* orph_12ab70 @ 0x12ab70 (8 bytes) */
int orph_12ab70(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  FUN_000e9294(param_2);
  return;
}

/* orph_12ab78 @ 0x12ab78 (8 bytes) */
int orph_12ab78(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  FUN_000e9294(param_2);
  return;
}

/* orph_12dd48 @ 0x12dd48 (8 bytes) */
int orph_12dd48(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  FUN_0012d2f0(param_2);
  return;
}

/* orph_12dd50 @ 0x12dd50 (8 bytes) */
int orph_12dd50(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  FUN_0012d2f0(param_2);
  return;
}

/* orph_136ec4 @ 0x136ec4 (4 bytes) */
int orph_136ec4(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  uint *puVar5;
  undefined4 uVar6;
  uint uVar7;
  
  param_1[2] = param_2;
  param_1[10] = param_4;
  *param_1 = 0;
  param_1[3] = param_3;
  param_1[0xb] = param_5;
  if (param_3 != 0) {
    iVar1 = FUN_00193e18(*(undefined4 *)(param_5 + 0x378),param_3 << 2);
    param_1[8] = iVar1;
    uVar6 = *(undefined4 *)(param_1[0xb] + 0x378);
    puVar2 = (undefined4 *)FUN_00193e18(uVar6,0x14);
    *puVar2 = uVar6;
    puVar2[1] = 2;
    puVar2[2] = 0;
    puVar2[4] = uVar6;
    uVar6 = FUN_00193e18(uVar6,8);
    puVar2[3] = uVar6;
    iVar4 = 0;
    iVar1 = param_1[3];
    param_1[1] = (int)(puVar2 + 1);
    if (0 < iVar1) {
      do {
        puVar5 = (uint *)param_1[1];
        uVar6 = *(undefined4 *)(param_1[0xb] + 0x378);
        puVar2 = (undefined4 *)FUN_00193e18(uVar6,0x28);
        *puVar2 = uVar6;
        FUN_001351c4(puVar2 + 1,iVar4,0,param_1,param_1[0xb]);
        uVar7 = puVar5[1];
        if (uVar7 < *puVar5) {
          _memset((void *)(uVar7 * 4 + puVar5[2]),0,4);
          puVar3 = (undefined4 *)(uVar7 * 4 + puVar5[2]);
          puVar5[1] = uVar7 + 1;
        }
        else {
          puVar3 = (undefined4 *)FUN_0019423c(puVar5,uVar7);
        }
        *puVar3 = puVar2 + 1;
        iVar4 = iVar4 + 1;
        iVar1 = param_1[3];
      } while (iVar4 < iVar1);
    }
    uVar6 = *(undefined4 *)(param_1[0xb] + 0x378);
    uVar7 = iVar1 * iVar1 - iVar1;
    iVar1 = ((int)uVar7 >> 1) + (uint)((int)uVar7 < 0 && (uVar7 & 1) != 0);
    uVar7 = iVar1 + 0x1fU >> 5;
    puVar2 = (undefined4 *)FUN_00193e18(uVar6,uVar7 * 4 + 0xc);
    puVar3 = puVar2 + 1;
    *puVar2 = uVar6;
    puVar2[1] = uVar7;
    puVar2[2] = iVar1;
    if (uVar7 != 0) {
      puVar2 = puVar3;
      if (uVar7 == 0) {
        uVar7 = 1;
      }
      do {
        puVar2[2] = 0;
        puVar2 = puVar2 + 1;
        uVar7 = uVar7 - 1;
      } while (uVar7 != 0);
    }
    *param_1 = (int)puVar3;
    iVar1 = *(int *)(*(int *)(param_1[0xb] + 0x30c) + 0x14) << 2;
    iVar4 = FUN_00193e18(*(undefined4 *)(param_1[0xb] + 0x378),iVar1);
    param_1[4] = iVar4;
    (**(code **)(**(int **)(param_1[0xb] + 0x30c) + 0x134))(*(int **)(param_1[0xb] + 0x30c),iVar4);
    iVar4 = FUN_00193e18(*(undefined4 *)(param_1[0xb] + 0x378),iVar1);
    param_1[6] = iVar4;
    iVar1 = FUN_00193e18(*(undefined4 *)(param_1[0xb] + 0x378),iVar1);
    iVar4 = param_1[0xb];
    param_1[5] = iVar1;
    if (0 < *(int *)(*(int *)(iVar4 + 0x30c) + 0x14)) {
      iVar1 = 0;
      do {
        iVar4 = iVar1 * 4;
        iVar1 = iVar1 + 1;
        *(undefined4 *)(param_1[6] + iVar4) = 0;
        *(undefined4 *)(param_1[5] + iVar4) = 0;
        iVar4 = param_1[0xb];
      } while (iVar1 < *(int *)(*(int *)(iVar4 + 0x30c) + 0x14));
    }
    uVar6 = *(undefined4 *)(iVar4 + 0x378);
    puVar3 = (undefined4 *)FUN_00193e18(uVar6,0x20c);
    puVar3[1] = 0x80;
    iVar1 = 0x80;
    *puVar3 = uVar6;
    puVar3[2] = 0x1000;
    puVar2 = puVar3 + 1;
    do {
      puVar2[2] = 0;
      puVar2 = puVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    param_1[9] = (int)(puVar3 + 1);
  }
  return;
}

/* orph_14694c @ 0x14694c (4 bytes) */
int orph_14694c(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  int iVar1;
  
  if ((param_3 != 0) && (iVar1 = FUN_00104054(), iVar1 != *(int *)(*(int *)(param_1 + 0x10) + 4))) {
    return 0;
  }
  return 1;
}

/* orph_172474 @ 0x172474 (8 bytes) */
int orph_172474(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  int param_3;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_2 == (undefined4 *)0x0) {
    uVar1 = 0x2b;
    if (param_3 == 0) {
      uVar1 = 0xa6;
    }
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 8) + 0x374);
    param_2 = (undefined4 *)FUN_00193e18(uVar2,0x168);
    *param_2 = uVar2;
    param_2 = param_2 + 1;
    FUN_0010502c(param_2,uVar1,*(undefined4 *)(param_1 + 8));
  }
  else {
    FUN_00104f34(param_2,param_3);
  }
  return param_2;
}

/* orph_176e0c @ 0x176e0c (20 bytes) */
int orph_176e0c(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = *(undefined4 *)(param_1 + 0x238);
  if ((((param_2 < 1) || (param_3 < 1)) || (iVar2 = FUN_00173330(uVar1,param_2), iVar2 == 0)) ||
     ((iVar3 = FUN_00173330(uVar1,param_3), iVar3 == 0 ||
      (((*(int *)(iVar2 + 0x20) == 0 || (param_3 != *(int *)(iVar2 + 0x24))) &&
       ((*(int *)(iVar3 + 0x20) == 0 || (param_2 != *(int *)(iVar3 + 0x24))))))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}

/* orph_187588 @ 0x187588 (32 bytes) */
int orph_187588(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  FUN_00186a88(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* orph_189660 @ 0x189660 (4 bytes) */
int orph_189660(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
  int *param_4;
  int *param_5;
{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_5 != (int *)0x0) && (iVar1 = (**(code **)(*param_5 + 0x4c))(param_5), iVar1 != 0)) &&
     (*param_4 == 0x10304)) {
    return 1;
  }
                    
                    
  uVar2 = (**(code **)(*param_1 + 0x100))(param_1,param_4);
  return uVar2;
}

/* orph_191708 @ 0x191708 (8 bytes) */
int orph_191708()
{
  return 0x80;
}

/* orph_193a8c @ 0x193a8c (4 bytes) */
int orph_193a8c(param_1, param_2, param_3, param_4)
  int *param_1;
  int param_2;
  int param_3;
  int param_4;
{
  int iVar1;
  
  param_1[1] = param_3;
  *param_1 = param_4;
  param_1[2] = param_2;
  if (param_2 < 3) {
    param_1[5] = 0;
  }
  else {
    iVar1 = FUN_00193e18(*(undefined4 *)(param_4 + 0x370),param_2 << 2);
    param_1[5] = iVar1;
  }
  return;
}

/* orph_193bd0 @ 0x193bd0 (24 bytes) */
int orph_193bd0(param_1)
  int *param_1;
{
  int iVar1;
  void *pvVar2;
  
  if ((void *)param_1[5] == (void *)0x0) {
    return;
  }
  iVar1 = *(int *)(*param_1 + 0x370);
  if ((*(int *)(iVar1 + 0x28) != 0) &&
     (pvVar2 = *(void **)(iVar1 + 0x14), pvVar2 == (void *)param_1[5])) {
    _memset(pvVar2,0,*(int *)(iVar1 + 8) - (int)pvVar2);
    *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(iVar1 + 0x14);
  }
  return;
}

/* orph_1961b0 @ 0x1961b0 (24 bytes) */
int orph_1961b0(param_1)
  int param_1;
{
  if (*(int *)(*(int *)(param_1 + 0xc) + 0x6c4) == 0) {
    return;
  }
  FUN_000e1534(*(int *)(param_1 + 0xc),0xf);
  return;
}

/* orph_197fb4 @ 0x197fb4 (4 bytes) */
int orph_197fb4(param_1, param_2, param_3, param_4, param_5)
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
    *(undefined2 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0xc) = param_5;
    iVar4 = *(int *)(param_1 + 0x60);
    iVar1 = *(int *)(param_1 + 0x58);
    iVar2 = FUN_001054ec(param_4,0);
    uVar3 = FUN_00195424(*(undefined4 *)(iVar2 + 0x10));
    *(undefined1 *)(iVar4 * 0x48 + iVar1 + 0x14) = uVar3;
  }
  if (param_3 != 0) {
    *(undefined2 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0x58) + 0x18) = param_5;
    iVar4 = *(int *)(param_1 + 0x60);
    iVar1 = *(int *)(param_1 + 0x58);
    iVar2 = FUN_001054ec(param_4,0);
    *(bool *)(iVar4 * 0x48 + iVar1 + 0x20) = *(char *)(iVar2 + 0x13) == '\0';
  }
  return;
}

/* orph_19aad8 @ 0x19aad8 (28 bytes) */
int orph_19aad8(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
                    
                    
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
  return;
}

/* orph_19d478 @ 0x19d478 (8 bytes) */
int orph_19d478(param_1, param_2, param_3)
  int param_1;
  int *param_2;
  int param_3;
{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  if (param_3 == 0) {
    puVar3 = (undefined4 *)0x0;
    uVar2 = *(uint *)(*(int *)(param_1 + 0x94) + 4);
    uVar1 = uVar2 - 1;
    if (uVar1 < uVar2) {
      puVar3 = (undefined4 *)(uVar1 * 4 + *(int *)(*(int *)(param_1 + 0x94) + 8));
    }
    FUN_000e2bf4(param_2 + 0x24,*puVar3);
  }
                    
                    
  (**(code **)(*param_2 + 0x44))(param_2,*(undefined4 *)(param_1 + 0x10),param_3);
  return;
}

/* orph_19f43c @ 0x19f43c (4 bytes) */
int orph_19f43c(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 uVar4;
  int iVar5;
  
  uVar4 = (undefined1)param_2;
  if (param_2 != -1) goto LAB_0019f708;
  if (param_3 == 0x34) {
LAB_0019f51c:
    uVar4 = 0;
    iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(undefined1 *)(iVar3 + 0x3b) = *(undefined1 *)(iVar3 + 0x3a);
    iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(undefined1 *)(iVar3 + 0x3e) = *(undefined1 *)(iVar3 + 0x3d);
    iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(undefined1 *)(iVar3 + 0x38) = *(undefined1 *)(iVar3 + 0x37);
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x37) = 6;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x3d) = 0;
  }
  else {
    if (param_3 < 0x35) {
      if (param_3 == 0x13) {
LAB_0019f4fc:
        uVar4 = 0;
        *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x38) = 4;
        goto LAB_0019f708;
      }
      if (param_3 < 0x14) {
        if (param_3 == 0x12) goto LAB_0019f51c;
      }
      else {
        if (param_3 == 0x25) {
LAB_0019f5f0:
          iVar5 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          uVar4 = *(undefined1 *)(iVar5 + 0x39);
          *(undefined1 *)(iVar5 + 0x39) = *(undefined1 *)(iVar5 + 0x3a);
          uVar1 = *(undefined1 *)(iVar5 + 0x3c);
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          uVar2 = *(undefined1 *)(iVar5 + 0x36);
          *(undefined1 *)(iVar3 + 0x3c) = *(undefined1 *)(iVar3 + 0x3d);
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(undefined1 *)(iVar3 + 0x36) = *(undefined1 *)(iVar3 + 0x37);
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(undefined1 *)(iVar3 + 0x3a) = *(undefined1 *)(iVar3 + 0x3b);
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(undefined1 *)(iVar3 + 0x3d) = *(undefined1 *)(iVar3 + 0x3e);
          iVar3 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(undefined1 *)(iVar3 + 0x37) = *(undefined1 *)(iVar3 + 0x38);
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x3b) = uVar4
          ;
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x3e) = uVar1
          ;
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x38) = uVar2
          ;
          if (param_3 == 0x9d) {
            uVar4 = 5;
          }
          else {
            uVar4 = 6;
          }
          goto LAB_0019f708;
        }
        if (param_3 == 0x31) {
LAB_0019f5b4:
          uVar4 = 0;
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x37) = 6;
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x38) = 4;
          goto LAB_0019f708;
        }
      }
    }
    else {
      if (param_3 == 0x8b) goto LAB_0019f51c;
      if (param_3 < 0x8c) {
        if (param_3 == 0x36) goto LAB_0019f4fc;
        if (param_3 == 0x66) goto LAB_0019f5b4;
      }
      else {
        if (param_3 == 0x9d) goto LAB_0019f5f0;
        if (param_3 == 0xb4) {
          uVar4 = 0;
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x36) = 4;
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x37) = 4;
          goto LAB_0019f708;
        }
      }
    }
    uVar4 = 0xff;
  }
LAB_0019f708:
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x40) = uVar4;
  if (*(int *)(param_4 + 0x120) != 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x42) = 1;
  }
  iVar5 = *(int *)(param_1 + 0x60);
  iVar3 = *(int *)(param_1 + 0xa8);
  uVar4 = FUN_0019533c(*(undefined4 *)(param_4 + 0x124));
  *(undefined1 *)(iVar5 * 0x48 + iVar3 + 0x41) = uVar4;
  return;
}

/* orph_19fdf0 @ 0x19fdf0 (4 bytes) */
int orph_19fdf0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  
  if (param_2 != 2) {
    if (param_2 != 3) {
      return;
    }
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 6) = 1;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 8) = 1;
  }
  if (param_3 == DAT_001b2d68) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 5) = 1;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 7) = 5;
    return;
  }
  if (param_3 == DAT_001b2d64) {
    uVar3 = 2;
    iVar1 = *(int *)(param_1 + 0xa8);
    iVar2 = *(int *)(param_1 + 0x60) * 0x48;
  }
  else if (param_3 == DAT_001b2d60) {
    uVar3 = 3;
    iVar1 = *(int *)(param_1 + 0xa8);
    iVar2 = *(int *)(param_1 + 0x60) * 0x48;
  }
  else if (param_3 == DAT_001b2d5c) {
    uVar3 = 4;
    iVar1 = *(int *)(param_1 + 0xa8);
    iVar2 = *(int *)(param_1 + 0x60) * 0x48;
  }
  else {
    if (param_3 != DAT_001b2d58) {
      return;
    }
    uVar3 = 5;
    iVar1 = *(int *)(param_1 + 0xa8);
    iVar2 = *(int *)(param_1 + 0x60) * 0x48;
  }
  *(undefined1 *)(iVar2 + iVar1 + 5) = uVar3;
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 7) = uVar3;
  return;
}

/* orph_1a00b4 @ 0x1a00b4 (4 bytes) */
int orph_1a00b4(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 uVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  uVar3 = (undefined1)param_2;
  if (param_2 != -1) goto LAB_001a0654;
  if (param_3 == 0x34) {
LAB_001a0260:
    uVar3 = 0;
    iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(undefined1 *)(iVar4 + 0x2c) = *(undefined1 *)(iVar4 + 0x2b);
    iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(undefined1 *)(iVar4 + 0x2f) = *(undefined1 *)(iVar4 + 0x2e);
    iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(uint *)(iVar4 + 0x28) =
         (*(uint *)(iVar4 + 0x24) & 0xe000) << 0x10 | *(uint *)(iVar4 + 0x28) & 0x1fffffff;
    iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(uint *)(iVar4 + 0x28) =
         (*(uint *)(iVar4 + 0x24) & 0x1c00) << 0x10 | *(uint *)(iVar4 + 0x28) & 0xe3ffffff;
    iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(uint *)(iVar4 + 0x28) =
         (*(uint *)(iVar4 + 0x24) & 0x380) << 0x10 | *(uint *)(iVar4 + 0x28) & 0xfc7fffff;
    iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xffff1fff | 0xc000;
    iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xffffe3ff | 0x1800;
    iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
    *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xfffffc7f | 0x300;
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x2e) = 0;
  }
  else {
    if (param_3 < 0x35) {
      if (param_3 == 0x13) {
LAB_001a0200:
        uVar3 = 0;
        iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
        *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0x1fffffff | 0x80000000;
        iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
        *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xe3ffffff | 0x10000000;
        iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
        *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xfc7fffff | 0x2000000;
        goto LAB_001a0654;
      }
      if (param_3 < 0x14) {
        if (param_3 == 0x12) goto LAB_001a0260;
      }
      else {
        if (param_3 == 0x25) {
LAB_001a044c:
          iVar6 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          uVar3 = *(undefined1 *)(iVar6 + 0x2a);
          *(undefined1 *)(iVar6 + 0x2a) = *(undefined1 *)(iVar6 + 0x2b);
          uVar5 = *(uint *)(iVar6 + 0x24);
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          uVar1 = *(undefined1 *)(iVar6 + 0x2d);
          *(undefined1 *)(iVar4 + 0x2d) = *(undefined1 *)(iVar4 + 0x2e);
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          uVar2 = *(uint *)(iVar4 + 0x24);
          *(uint *)(iVar4 + 0x24) = (uVar2 & 0x1c00) << 0x10 | uVar2 & 0xe3ffffff;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          uVar2 = *(uint *)(iVar4 + 0x24);
          *(uint *)(iVar4 + 0x24) = (uVar2 & 0x380) << 0x10 | uVar2 & 0xfc7fffff;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          uVar2 = *(uint *)(iVar4 + 0x24);
          *(uint *)(iVar4 + 0x24) = (uVar2 & 0xe000) << 0x10 | uVar2 & 0x1fffffff;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(undefined1 *)(iVar4 + 0x2b) = *(undefined1 *)(iVar4 + 0x2c);
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(undefined1 *)(iVar4 + 0x2e) = *(undefined1 *)(iVar4 + 0x2f);
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x24) =
               *(uint *)(iVar4 + 0x28) >> 0x10 & 0xe000 | *(uint *)(iVar4 + 0x24) & 0xffff1fff;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x24) =
               *(uint *)(iVar4 + 0x28) >> 0x10 & 0x1c00 | *(uint *)(iVar4 + 0x24) & 0xffffe3ff;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x24) =
               *(uint *)(iVar4 + 0x28) >> 0x10 & 0x380 | *(uint *)(iVar4 + 0x24) & 0xfffffc7f;
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x2c) = uVar3
          ;
          *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x2f) = uVar1
          ;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x28) = uVar5 & 0xe0000000 | *(uint *)(iVar4 + 0x28) & 0x1fffffff;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x28) = uVar5 & 0x1c000000 | *(uint *)(iVar4 + 0x28) & 0xe3ffffff;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x28) = uVar5 & 0x3800000 | *(uint *)(iVar4 + 0x28) & 0xfc7fffff;
          if (param_3 == 0x9d) {
            uVar3 = 7;
          }
          else {
            uVar3 = 8;
          }
          goto LAB_001a0654;
        }
        if (param_3 == 0x31) {
LAB_001a0390:
          uVar3 = 0;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xffff1fff | 0xc000;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xffffe3ff | 0x1800;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xfffffc7f | 0x300;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0x1fffffff | 0x80000000;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xe3ffffff | 0x10000000;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xfc7fffff | 0x2000000;
          goto LAB_001a0654;
        }
      }
    }
    else {
      if (param_3 == 0x8b) goto LAB_001a0260;
      if (param_3 < 0x8c) {
        if (param_3 == 0x36) goto LAB_001a0200;
        if (param_3 == 0x66) goto LAB_001a0390;
      }
      else {
        if (param_3 == 0x9d) goto LAB_001a044c;
        if (param_3 == 0xb4) {
          *(undefined4 *)(param_1 + 0x9c) = 1;
          uVar3 = 0;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xfc7fffff | 0x3000000;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xffff1fff | 0xc000;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x24) = *(uint *)(iVar4 + 0x24) & 0xffffe3ff | 0x1800;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0x1fffffff | 0x80000000;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xfc7fffff | 0x2000000;
          iVar4 = *(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8);
          *(uint *)(iVar4 + 0x28) = *(uint *)(iVar4 + 0x28) & 0xe3ffffff | 0x10000000;
          goto LAB_001a0654;
        }
      }
    }
    uVar3 = 0xff;
  }
LAB_001a0654:
  *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x31) = uVar3;
  if (*(int *)(param_4 + 0x120) != 0) {
    *(undefined1 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x33) = 1;
  }
  iVar6 = *(int *)(param_1 + 0x60);
  iVar4 = *(int *)(param_1 + 0xa8);
  uVar3 = FUN_0019533c(*(undefined4 *)(param_4 + 0x124));
  *(undefined1 *)(iVar6 * 0x48 + iVar4 + 0x32) = uVar3;
  return;
}

/* orph_1a184c @ 0x1a184c (4 bytes) */
int orph_1a184c(param_1, param_2, param_3, param_4, param_5)
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
    *(undefined2 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0xc) = param_5;
    iVar4 = *(int *)(param_1 + 0x60);
    iVar1 = *(int *)(param_1 + 0xa8);
    iVar2 = FUN_001054ec(param_4,0);
    uVar3 = FUN_00195424(*(undefined4 *)(iVar2 + 0x10));
    *(undefined1 *)(iVar4 * 0x48 + iVar1 + 0x14) = uVar3;
  }
  if (param_3 != 0) {
    *(undefined2 *)(*(int *)(param_1 + 0x60) * 0x48 + *(int *)(param_1 + 0xa8) + 0x18) = param_5;
    iVar4 = *(int *)(param_1 + 0x60);
    iVar1 = *(int *)(param_1 + 0xa8);
    iVar2 = FUN_001054ec(param_4,0);
    *(bool *)(iVar4 * 0x48 + iVar1 + 0x20) = *(char *)(iVar2 + 0x13) == '\0';
  }
  return;
}

/* orph_1cd664 @ 0x1cd664 (56 bytes) */
int orph_1cd664(param_1)
  undefined4 *param_1;
{
  undefined4 *puVar1;
  int iVar2;
  
  *param_1 = &PTR_FUN_001e9a40;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  iVar2 = param_1[-1];
  if ((*(int *)(iVar2 + 0x28) != 0) &&
     (puVar1 = *(undefined4 **)(iVar2 + 0x14), puVar1 == param_1 + -1)) {
    _memset(puVar1,0,*(int *)(iVar2 + 8) - (int)puVar1);
    *(undefined4 *)(iVar2 + 8) = *(undefined4 *)(iVar2 + 0x14);
  }
  return;
}

/* orph_1cd69c @ 0x1cd69c (4 bytes) */
int orph_1cd69c()
{
  return;
}

/* orph_1cd6a0 @ 0x1cd6a0 (4 bytes) */
int orph_1cd6a0()
{
  return;
}

/* orph_1cd6a4 @ 0x1cd6a4 (4 bytes) */
int orph_1cd6a4()
{
  return;
}

/* orph_1cd6a8 @ 0x1cd6a8 (8 bytes) */
int orph_1cd6a8(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0x80);
}

/* orph_1cd6b0 @ 0x1cd6b0 (4 bytes) */
int orph_1cd6b0()
{
  return;
}

/* orph_1cd6b4 @ 0x1cd6b4 (44 bytes) */
int orph_1cd6b4(param_1)
  int param_1;
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0x88) + 4);
  if (((iVar1 != 6) && (iVar1 != 7)) && (iVar1 != 8)) {
    return 0;
  }
  return 1;
}

/* orph_1cd6e0 @ 0x1cd6e0 (8 bytes) */
int orph_1cd6e0()
{
  return 0;
}

/* orph_1cd6e8 @ 0x1cd6e8 (8 bytes) */
int orph_1cd6e8()
{
  return 0;
}

