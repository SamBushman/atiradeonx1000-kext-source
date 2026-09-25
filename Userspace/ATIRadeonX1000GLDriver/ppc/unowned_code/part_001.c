#include "decls.h"

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

/* orph_10451c @ 0x10451c (32 bytes) */
int orph_10451c(param_1, param_2)
  int *param_1;
  int param_2;
{
                    
                    
  (**(code **)(*param_1 + 0xc))
            (param_1,*(uint *)(*(int *)(param_2 + 0x6c4) + 0x30) >> 7 & 1,param_2);
  return;
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
int orph_12841c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  FUN_000f4a84(*(undefined4 *)(*(int *)(param_5 + 0x6c4) + 0x3ac),param_3,param_4,param_4,param_5,
               param_6,param_7);
  return;
}

/* orph_129400 @ 0x129400 (8 bytes) */
int orph_129400()
{
  return 0x20;
}

/* orph_129ea0 @ 0x129ea0 (20 bytes) */
int orph_129ea0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  int param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  FUN_000f4a84(*(undefined4 *)(*(int *)(param_5 + 0x6c4) + 0x3ac),param_3,param_4,param_4,param_5,
               param_6,param_7);
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

/* orph_191708 @ 0x191708 (8 bytes) */
int orph_191708()
{
  return 0x80;
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

/* orph_19aad8 @ 0x19aad8 (28 bytes) */
int orph_19aad8(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  undefined4 param_3;
{
                    
                    
  (**(code **)(*param_1 + 0x34))(param_1,param_3,*(undefined4 *)(param_2 + 0xdc));
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

/* orph_1cd6f0 @ 0x1cd6f0 (8 bytes) */
int orph_1cd6f0()
{
  return 0;
}

/* orph_1cd6f8 @ 0x1cd6f8 (8 bytes) */
int orph_1cd6f8()
{
  return 0;
}

/* orph_1cd700 @ 0x1cd700 (8 bytes) */
int orph_1cd700()
{
  return 0;
}

/* orph_1cd708 @ 0x1cd708 (24 bytes) */
int orph_1cd708(param_1)
  int param_1;
{
  return *(int *)(*(int *)(param_1 + 0x88) + 4) == 4;
}

/* orph_1cd720 @ 0x1cd720 (8 bytes) */
int orph_1cd720()
{
  return 0;
}

/* orph_1cd728 @ 0x1cd728 (8 bytes) */
int orph_1cd728()
{
  return 0;
}

/* orph_1cd730 @ 0x1cd730 (8 bytes) */
int orph_1cd730()
{
  return 0;
}

/* orph_1cd738 @ 0x1cd738 (8 bytes) */
int orph_1cd738()
{
  return 0;
}

/* orph_1cd740 @ 0x1cd740 (8 bytes) */
int orph_1cd740()
{
  return 0;
}

/* orph_1cd748 @ 0x1cd748 (8 bytes) */
int orph_1cd748()
{
  return 0;
}

/* orph_1cd750 @ 0x1cd750 (8 bytes) */
int orph_1cd750()
{
  return 0;
}

/* orph_1cd758 @ 0x1cd758 (8 bytes) */
int orph_1cd758()
{
  return 0;
}

/* orph_1cd760 @ 0x1cd760 (8 bytes) */
int orph_1cd760()
{
  return 0;
}

/* orph_1cd768 @ 0x1cd768 (8 bytes) */
int orph_1cd768()
{
  return 0;
}

/* orph_1cd770 @ 0x1cd770 (8 bytes) */
int orph_1cd770()
{
  return 0;
}

/* orph_1cd778 @ 0x1cd778 (8 bytes) */
int orph_1cd778()
{
  return 0;
}

/* orph_1cd780 @ 0x1cd780 (8 bytes) */
int orph_1cd780()
{
  return 0;
}

/* orph_1cd788 @ 0x1cd788 (8 bytes) */
int orph_1cd788()
{
  return 0;
}

/* orph_1cd790 @ 0x1cd790 (8 bytes) */
int orph_1cd790()
{
  return 0;
}

/* orph_1cd798 @ 0x1cd798 (8 bytes) */
int orph_1cd798()
{
  return 0;
}

/* orph_1cd7a0 @ 0x1cd7a0 (8 bytes) */
int orph_1cd7a0(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x11c) = param_2;
  return;
}

/* orph_1cd7a8 @ 0x1cd7a8 (8 bytes) */
int orph_1cd7a8()
{
  return 1;
}

/* orph_1cd7b0 @ 0x1cd7b0 (8 bytes) */
int orph_1cd7b0()
{
  return 0;
}

/* orph_1cd7b8 @ 0x1cd7b8 (4 bytes) */
int orph_1cd7b8()
{
  return;
}

/* orph_1cd7d8 @ 0x1cd7d8 (20 bytes) */
int orph_1cd7d8(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
{
  *(undefined1 *)(param_2 * 0x18 + param_1 + param_3 + 0x9c) = param_4;
  return;
}

/* orph_1cdbf8 @ 0x1cdbf8 (4 bytes) */
int orph_1cdbf8()
{
  return;
}

/* orph_1cdbfc @ 0x1cdbfc (8 bytes) */
int orph_1cdbfc()
{
  return 0;
}

/* orph_1cdc04 @ 0x1cdc04 (8 bytes) */
int orph_1cdc04()
{
  return 0;
}

/* orph_1cdc0c @ 0x1cdc0c (8 bytes) */
int orph_1cdc0c()
{
  return 0;
}

/* orph_1cdc14 @ 0x1cdc14 (8 bytes) */
int orph_1cdc14()
{
  return 0;
}

/* orph_1cdc1c @ 0x1cdc1c (8 bytes) */
int orph_1cdc1c()
{
  return 0;
}

