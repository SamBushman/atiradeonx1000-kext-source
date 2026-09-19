#include "decls.h"

/* FUN_000243f0 @ 0x243f0 (112 bytes) */
int FUN_000243f0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar2 = ((int (*)())FUN_0002cc30)(param_1,0,6);
  if (iVar2 != 0) {
    iVar3 = param_1 + 0x240;
    uVar4 = *(undefined4 *)(param_1 + 0x244);
    uVar5 = *(undefined4 *)(param_1 + 0x1ee0);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar3,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              (iVar2 + 1) * *(int *)(param_1 + 0x267c) * 5 + (iVar2 + 1) * 2 + 0x16)
    ;
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != FUN_00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = FUN_00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(FUN_000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar4);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    *puVar1 = 0x82c;
    uVar4 = *(undefined4 *)(FUN_00001dc4 + param_1);
    puVar1[2] = 0x821;
    puVar1[3] = 5;
    puVar1[1] = uVar4;
    if (*(char *)(*(int *)(param_1 + 0x244) + 0x20) == '\0') {
      puVar1 = (undefined4 *)FUN_00023700(iVar3,param_2,puVar1 + 4);
      if (iVar2 == 0x24) {
        uVar4 = FUN_00023700(iVar3,param_3,puVar1);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x100,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x200,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x300,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x400,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x500,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x600,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x700,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x800,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x900,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0xa00,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0xb00,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0xc00,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0xd00,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0xe00,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0xf00,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x1000,uVar4);
        uVar4 = FUN_00023700(iVar3,((unsigned char *)0x00001100) + param_3,uVar4);
        uVar4 = FUN_00023700(iVar3,((unsigned char *)0x00001200) + param_3,uVar4);
        uVar4 = FUN_00023700(iVar3,((unsigned char *)0x00001300) + param_3,uVar4);
        uVar4 = FUN_00023700(iVar3,((unsigned char *)0x00001400) + param_3,uVar4);
        uVar4 = FUN_00023700(iVar3,((unsigned char *)0x00001500) + param_3,uVar4);
        uVar4 = FUN_00023700(iVar3,((unsigned char *)0x00001600) + param_3,uVar4);
        uVar4 = FUN_00023700(iVar3,((unsigned char *)0x00001700) + param_3,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x1800,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x1900,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x1a00,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x1b00,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x1c00,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x1d00,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x1e00,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x1f00,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x2000,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x2100,uVar4);
        uVar4 = FUN_00023700(iVar3,param_3 + 0x2200,uVar4);
        puVar1 = (undefined4 *)FUN_00023700(iVar3,param_3 + 0x2300,uVar4);
      }
      else if (0 < iVar2) {
        iVar6 = 0;
        do {
          iVar6 = iVar6 + 1;
          puVar1 = (undefined4 *)FUN_00023700(iVar3,param_3,puVar1);
          param_3 = param_3 + 0x100;
        } while (iVar2 != iVar6);
      }
    }
    else {
      puVar1 = (undefined4 *)FUN_00023870(iVar3,uVar5,param_2,puVar1 + 4);
      if (iVar2 == 0x24) {
        uVar4 = FUN_00023870(iVar3,uVar5,param_3,puVar1);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x100,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x200,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x300,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x400,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x500,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x600,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x700,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x800,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x900,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0xa00,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0xb00,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0xc00,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0xd00,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0xe00,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0xf00,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x1000,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,((unsigned char *)0x00001100) + param_3,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,((unsigned char *)0x00001200) + param_3,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,((unsigned char *)0x00001300) + param_3,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,((unsigned char *)0x00001400) + param_3,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,((unsigned char *)0x00001500) + param_3,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,((unsigned char *)0x00001600) + param_3,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,((unsigned char *)0x00001700) + param_3,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x1800,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x1900,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x1a00,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x1b00,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x1c00,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x1d00,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x1e00,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x1f00,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x2000,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x2100,uVar4);
        uVar4 = FUN_00023870(iVar3,uVar5,param_3 + 0x2200,uVar4);
        puVar1 = (undefined4 *)FUN_00023870(iVar3,uVar5,param_3 + 0x2300,uVar4);
      }
      else if (0 < iVar2) {
        iVar6 = 0;
        do {
          iVar6 = iVar6 + 1;
          puVar1 = (undefined4 *)FUN_00023870(iVar3,uVar5,param_3,puVar1);
          param_3 = param_3 + 0x100;
        } while (iVar2 != iVar6);
      }
    }
    *puVar1 = 0x92b;
    puVar1[3] = 0;
    puVar1[2] = ((unsigned char *)0x00001393);
    puVar1[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar1 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(iVar3);
    return;
  }
  return;
}

/* FUN_00024470 @ 0x24470 (112 bytes) */
int FUN_00024470(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar3 = ((int (*)())FUN_0002cc30)(param_1,0,7,param_3);
  if (iVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar5 = *(undefined4 *)(param_1 + 0x244);
    uVar6 = *(undefined4 *)(param_1 + 0x1ee0);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              iVar3 * *(int *)(param_1 + 0x267c) * 5 + iVar3 * 2 + 0x16);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != FUN_00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = FUN_00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(FUN_000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar5);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar5 = *(undefined4 *)(FUN_00001dc4 + param_1);
    puVar1[2] = 0x821;
    puVar1[3] = 0xd;
    puVar1[1] = uVar5;
    if (*(char *)(*(int *)(param_1 + 0x244) + 0x20) == '\0') {
      if (iVar3 == 0x24) {
        uVar5 = FUN_00023700(iVar4,param_2,puVar2);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x100,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x200,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x300,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x400,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x500,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x600,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x700,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x800,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x900,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xa00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xb00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xc00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xd00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xe00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xf00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1000,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001100) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001200) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001300) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001400) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001500) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001600) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001700) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1800,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1900,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1a00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1b00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1c00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1d00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1e00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1f00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2000,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2100,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2200,uVar5);
        puVar2 = (undefined4 *)FUN_00023700(iVar4,param_2 + 0x2300,uVar5);
      }
      else if (0 < iVar3) {
        iVar7 = 0;
        do {
          iVar7 = iVar7 + 1;
          puVar2 = (undefined4 *)FUN_00023700(iVar4,param_2,puVar2);
          param_2 = param_2 + 0x100;
        } while (iVar3 != iVar7);
      }
    }
    else if (iVar3 == 0x24) {
      uVar5 = FUN_00023870(iVar4,uVar6,param_2,puVar2);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x100,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x200,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x300,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x400,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x500,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x600,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x700,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x800,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x900,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xa00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xb00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xc00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xd00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xe00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xf00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1000,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001100) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001200) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001300) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001400) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001500) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001600) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001700) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1800,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1900,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1a00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1b00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1c00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1d00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1e00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1f00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2000,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2100,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2200,uVar5);
      puVar2 = (undefined4 *)FUN_00023870(iVar4,uVar6,param_2 + 0x2300,uVar5);
    }
    else if (0 < iVar3) {
      iVar7 = 0;
      do {
        iVar7 = iVar7 + 1;
        puVar2 = (undefined4 *)FUN_00023870(iVar4,uVar6,param_2,puVar2);
        param_2 = param_2 + 0x100;
      } while (iVar3 != iVar7);
    }
    *puVar2 = 0x92b;
    puVar2[3] = 0;
    puVar2[2] = ((unsigned char *)0x00001393);
    puVar2[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar2 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(iVar4);
    return;
  }
  return;
}

/* FUN_000244f0 @ 0x244f0 (112 bytes) */
int FUN_000244f0(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar3 = ((int (*)())FUN_0002cc30)(param_1,0,8,param_3);
  if (iVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar5 = *(undefined4 *)(param_1 + 0x244);
    uVar6 = *(undefined4 *)(param_1 + 0x1ee0);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              iVar3 * *(int *)(param_1 + 0x267c) * 5 + iVar3 * 2 + 0x16);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != FUN_00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = FUN_00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(FUN_000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar5);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar5 = *(undefined4 *)(FUN_00001dc4 + param_1);
    puVar1[2] = 0x821;
    puVar1[3] = 0xe;
    puVar1[1] = uVar5;
    if (*(char *)(*(int *)(param_1 + 0x244) + 0x20) == '\0') {
      if (iVar3 == 0x24) {
        uVar5 = FUN_00023700(iVar4,param_2,puVar2);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x100,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x200,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x300,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x400,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x500,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x600,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x700,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x800,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x900,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xa00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xb00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xc00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xd00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xe00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xf00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1000,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001100) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001200) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001300) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001400) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001500) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001600) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001700) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1800,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1900,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1a00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1b00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1c00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1d00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1e00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1f00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2000,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2100,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2200,uVar5);
        puVar2 = (undefined4 *)FUN_00023700(iVar4,param_2 + 0x2300,uVar5);
      }
      else if (0 < iVar3) {
        iVar7 = 0;
        do {
          iVar7 = iVar7 + 1;
          puVar2 = (undefined4 *)FUN_00023700(iVar4,param_2,puVar2);
          param_2 = param_2 + 0x100;
        } while (iVar3 != iVar7);
      }
    }
    else if (iVar3 == 0x24) {
      uVar5 = FUN_00023870(iVar4,uVar6,param_2,puVar2);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x100,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x200,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x300,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x400,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x500,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x600,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x700,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x800,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x900,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xa00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xb00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xc00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xd00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xe00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xf00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1000,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001100) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001200) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001300) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001400) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001500) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001600) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001700) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1800,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1900,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1a00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1b00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1c00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1d00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1e00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1f00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2000,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2100,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2200,uVar5);
      puVar2 = (undefined4 *)FUN_00023870(iVar4,uVar6,param_2 + 0x2300,uVar5);
    }
    else if (0 < iVar3) {
      iVar7 = 0;
      do {
        iVar7 = iVar7 + 1;
        puVar2 = (undefined4 *)FUN_00023870(iVar4,uVar6,param_2,puVar2);
        param_2 = param_2 + 0x100;
      } while (iVar3 != iVar7);
    }
    *puVar2 = 0x92b;
    puVar2[3] = 0;
    puVar2[2] = ((unsigned char *)0x00001393);
    puVar2[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar2 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(iVar4);
    return;
  }
  return;
}

/* FUN_00024570 @ 0x24570 (112 bytes) */
int FUN_00024570(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar3 = ((int (*)())FUN_0002cc30)(param_1,0,9,param_3);
  if (iVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar5 = *(undefined4 *)(param_1 + 0x244);
    uVar6 = *(undefined4 *)(param_1 + 0x1ee0);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              iVar3 * *(int *)(param_1 + 0x267c) * 5 + iVar3 * 2 + 0x16);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != FUN_00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = FUN_00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(FUN_000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar5);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar5 = *(undefined4 *)(FUN_00001dc4 + param_1);
    puVar1[2] = 0x821;
    puVar1[3] = 0xf;
    puVar1[1] = uVar5;
    if (*(char *)(*(int *)(param_1 + 0x244) + 0x20) == '\0') {
      if (iVar3 == 0x24) {
        uVar5 = FUN_00023700(iVar4,param_2,puVar2);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x100,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x200,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x300,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x400,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x500,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x600,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x700,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x800,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x900,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xa00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xb00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xc00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xd00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xe00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xf00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1000,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001100) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001200) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001300) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001400) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001500) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001600) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001700) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1800,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1900,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1a00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1b00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1c00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1d00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1e00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1f00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2000,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2100,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2200,uVar5);
        puVar2 = (undefined4 *)FUN_00023700(iVar4,param_2 + 0x2300,uVar5);
      }
      else if (0 < iVar3) {
        iVar7 = 0;
        do {
          iVar7 = iVar7 + 1;
          puVar2 = (undefined4 *)FUN_00023700(iVar4,param_2,puVar2);
          param_2 = param_2 + 0x100;
        } while (iVar3 != iVar7);
      }
    }
    else if (iVar3 == 0x24) {
      uVar5 = FUN_00023870(iVar4,uVar6,param_2,puVar2);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x100,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x200,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x300,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x400,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x500,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x600,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x700,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x800,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x900,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xa00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xb00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xc00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xd00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xe00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xf00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1000,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001100) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001200) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001300) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001400) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001500) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001600) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001700) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1800,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1900,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1a00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1b00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1c00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1d00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1e00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1f00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2000,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2100,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2200,uVar5);
      puVar2 = (undefined4 *)FUN_00023870(iVar4,uVar6,param_2 + 0x2300,uVar5);
    }
    else if (0 < iVar3) {
      iVar7 = 0;
      do {
        iVar7 = iVar7 + 1;
        puVar2 = (undefined4 *)FUN_00023870(iVar4,uVar6,param_2,puVar2);
        param_2 = param_2 + 0x100;
      } while (iVar3 != iVar7);
    }
    *puVar2 = 0x92b;
    puVar2[3] = 0;
    puVar2[2] = ((unsigned char *)0x00001393);
    puVar2[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar2 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(iVar4);
    return;
  }
  return;
}

/* FUN_000245f0 @ 0x245f0 (108 bytes) */
int FUN_000245f0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  
  uVar3 = ((int (*)())FUN_0002cc30)(param_1,0,9,param_3);
  if (uVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar6 = *(undefined4 *)(param_1 + 0x244);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              *(int *)(param_1 + 0x267c) * uVar3 * 5 + uVar3 * 2 + 0x16,param_2,
                        uVar3,param_4);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != FUN_00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = FUN_00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(FUN_000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar6);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar6 = *(undefined4 *)(FUN_00001dc4 + param_1);
    puVar1[2] = 0x821;
    puVar1[3] = 0xf;
    puVar1[1] = uVar6;
    if (uVar3 != 0) {
      uVar5 = 0;
      do {
        uVar6 = *param_2;
        uVar5 = uVar5 + 1;
        param_2 = param_2 + 1;
        puVar2 = (undefined4 *)FUN_00023700(iVar4,uVar6,puVar2);
      } while (uVar5 < uVar3);
    }
    *puVar2 = 0x92b;
    puVar2[3] = 0;
    puVar2[2] = ((unsigned char *)0x00001393);
    puVar2[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar2 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(iVar4);
    return;
  }
  return;
}

/* FUN_00024670 @ 0x24670 (108 bytes) */
int FUN_00024670(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar3 = ((int (*)())FUN_0002cc30)(param_1,0,0,param_3);
  if (iVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar5 = *(undefined4 *)(param_1 + 0x244);
    uVar6 = *(undefined4 *)(param_1 + 0x1ee0);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              iVar3 * *(int *)(param_1 + 0x267c) * 5 + iVar3 * 2 + 0x16);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != FUN_00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = FUN_00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(FUN_000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar5);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar5 = *(undefined4 *)(FUN_00001dc4 + param_1);
    puVar1[2] = 0x821;
    puVar1[3] = 1;
    puVar1[1] = uVar5;
    if (*(char *)(*(int *)(param_1 + 0x244) + 0x20) == '\0') {
      if (iVar3 == 0x24) {
        uVar5 = FUN_00023700(iVar4,param_2,puVar2);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x100,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x200,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x300,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x400,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x500,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x600,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x700,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x800,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x900,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xa00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xb00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xc00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xd00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xe00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xf00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1000,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001100) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001200) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001300) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001400) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001500) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001600) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001700) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1800,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1900,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1a00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1b00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1c00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1d00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1e00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1f00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2000,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2100,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2200,uVar5);
        puVar2 = (undefined4 *)FUN_00023700(iVar4,param_2 + 0x2300,uVar5);
      }
      else if (0 < iVar3) {
        iVar7 = 0;
        do {
          iVar7 = iVar7 + 1;
          puVar2 = (undefined4 *)FUN_00023700(iVar4,param_2,puVar2);
          param_2 = param_2 + 0x100;
        } while (iVar3 != iVar7);
      }
    }
    else if (iVar3 == 0x24) {
      uVar5 = FUN_00023870(iVar4,uVar6,param_2,puVar2);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x100,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x200,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x300,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x400,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x500,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x600,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x700,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x800,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x900,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xa00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xb00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xc00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xd00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xe00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xf00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1000,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001100) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001200) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001300) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001400) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001500) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001600) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001700) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1800,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1900,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1a00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1b00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1c00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1d00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1e00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1f00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2000,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2100,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2200,uVar5);
      puVar2 = (undefined4 *)FUN_00023870(iVar4,uVar6,param_2 + 0x2300,uVar5);
    }
    else if (0 < iVar3) {
      iVar7 = 0;
      do {
        iVar7 = iVar7 + 1;
        puVar2 = (undefined4 *)FUN_00023870(iVar4,uVar6,param_2,puVar2);
        param_2 = param_2 + 0x100;
      } while (iVar3 != iVar7);
    }
    *puVar2 = 0x92b;
    puVar2[3] = 0;
    puVar2[2] = ((unsigned char *)0x00001393);
    puVar2[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar2 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(iVar4);
    return;
  }
  return;
}

/* FUN_000246f0 @ 0x246f0 (104 bytes) */
int FUN_000246f0(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  
  uVar3 = ((int (*)())FUN_0002cc30)(param_1,0,0,param_3);
  if (uVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar6 = *(undefined4 *)(param_1 + 0x244);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              *(int *)(param_1 + 0x267c) * uVar3 * 5 + uVar3 * 2 + 0x16,param_2,
                        uVar3,0);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != FUN_00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = FUN_00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(FUN_000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar6);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar6 = *(undefined4 *)(FUN_00001dc4 + param_1);
    puVar1[2] = 0x821;
    puVar1[3] = 1;
    puVar1[1] = uVar6;
    if (uVar3 != 0) {
      uVar5 = 0;
      do {
        uVar6 = *param_2;
        uVar5 = uVar5 + 1;
        param_2 = param_2 + 1;
        puVar2 = (undefined4 *)FUN_00023700(iVar4,uVar6,puVar2);
      } while (uVar5 < uVar3);
    }
    *puVar2 = 0x92b;
    puVar2[3] = 0;
    puVar2[2] = ((unsigned char *)0x00001393);
    puVar2[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar2 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(iVar4);
    return;
  }
  return;
}

/* FUN_00024770 @ 0x24770 (108 bytes) */
int FUN_00024770(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar3 = ((int (*)())FUN_0002cc30)(param_1,0,1,param_3);
  if (iVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar5 = *(undefined4 *)(param_1 + 0x244);
    uVar6 = *(undefined4 *)(param_1 + 0x1ee0);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              iVar3 * *(int *)(param_1 + 0x267c) * 5 + iVar3 * 2 + 0x16);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != FUN_00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = FUN_00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(FUN_000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar5);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar5 = *(undefined4 *)(FUN_00001dc4 + param_1);
    puVar1[2] = 0x821;
    puVar1[3] = 2;
    puVar1[1] = uVar5;
    if (*(char *)(*(int *)(param_1 + 0x244) + 0x20) == '\0') {
      if (iVar3 == 0x24) {
        uVar5 = FUN_00023700(iVar4,param_2,puVar2);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x100,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x200,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x300,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x400,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x500,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x600,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x700,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x800,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x900,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xa00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xb00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xc00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xd00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xe00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xf00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1000,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001100) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001200) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001300) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001400) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001500) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001600) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001700) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1800,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1900,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1a00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1b00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1c00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1d00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1e00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1f00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2000,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2100,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2200,uVar5);
        puVar2 = (undefined4 *)FUN_00023700(iVar4,param_2 + 0x2300,uVar5);
      }
      else if (0 < iVar3) {
        iVar7 = 0;
        do {
          iVar7 = iVar7 + 1;
          puVar2 = (undefined4 *)FUN_00023700(iVar4,param_2,puVar2);
          param_2 = param_2 + 0x100;
        } while (iVar3 != iVar7);
      }
    }
    else if (iVar3 == 0x24) {
      uVar5 = FUN_00023870(iVar4,uVar6,param_2,puVar2);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x100,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x200,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x300,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x400,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x500,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x600,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x700,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x800,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x900,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xa00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xb00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xc00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xd00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xe00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xf00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1000,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001100) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001200) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001300) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001400) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001500) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001600) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001700) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1800,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1900,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1a00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1b00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1c00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1d00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1e00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1f00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2000,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2100,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2200,uVar5);
      puVar2 = (undefined4 *)FUN_00023870(iVar4,uVar6,param_2 + 0x2300,uVar5);
    }
    else if (0 < iVar3) {
      iVar7 = 0;
      do {
        iVar7 = iVar7 + 1;
        puVar2 = (undefined4 *)FUN_00023870(iVar4,uVar6,param_2,puVar2);
        param_2 = param_2 + 0x100;
      } while (iVar3 != iVar7);
    }
    *puVar2 = 0x92b;
    puVar2[3] = 0;
    puVar2[2] = ((unsigned char *)0x00001393);
    puVar2[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar2 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(iVar4);
    return;
  }
  return;
}

/* FUN_000247f0 @ 0x247f0 (104 bytes) */
int FUN_000247f0(param_1, param_2, param_3)
  int param_1;
  undefined4 *param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  
  uVar3 = ((int (*)())FUN_0002cc30)(param_1,0,1,param_3);
  if (uVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar6 = *(undefined4 *)(param_1 + 0x244);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              *(int *)(param_1 + 0x267c) * uVar3 * 5 + uVar3 * 2 + 0x16,param_2,
                        uVar3,0);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != FUN_00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = FUN_00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(FUN_000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar6);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar6 = *(undefined4 *)(FUN_00001dc4 + param_1);
    puVar1[2] = 0x821;
    puVar1[3] = 2;
    puVar1[1] = uVar6;
    if (uVar3 != 0) {
      uVar5 = 0;
      do {
        uVar6 = *param_2;
        uVar5 = uVar5 + 1;
        param_2 = param_2 + 1;
        puVar2 = (undefined4 *)FUN_00023700(iVar4,uVar6,puVar2);
      } while (uVar5 < uVar3);
    }
    *puVar2 = 0x92b;
    puVar2[3] = 0;
    puVar2[2] = ((unsigned char *)0x00001393);
    puVar2[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar2 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(iVar4);
    return;
  }
  return;
}

/* FUN_00024870 @ 0x24870 (112 bytes) */
int FUN_00024870(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar3 = ((int (*)())FUN_0002cc30)(param_1,param_4,2,param_3);
  if (iVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar5 = *(undefined4 *)(param_1 + 0x244);
    uVar6 = *(undefined4 *)(param_1 + 0x1ee0);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              iVar3 * *(int *)(param_1 + 0x267c) * 5 + iVar3 * 2 + 0x16);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != FUN_00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = FUN_00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(FUN_000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar5);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar5 = *(undefined4 *)(FUN_00001dc4 + param_1);
    puVar1[2] = 0x821;
    puVar1[3] = 0xc;
    puVar1[1] = uVar5;
    if (*(char *)(*(int *)(param_1 + 0x244) + 0x20) == '\0') {
      if (iVar3 == 0x24) {
        uVar5 = FUN_00023700(iVar4,param_2,puVar2);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x100,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x200,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x300,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x400,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x500,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x600,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x700,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x800,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x900,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xa00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xb00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xc00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xd00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xe00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xf00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1000,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001100) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001200) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001300) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001400) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001500) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001600) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001700) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1800,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1900,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1a00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1b00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1c00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1d00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1e00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1f00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2000,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2100,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2200,uVar5);
        puVar2 = (undefined4 *)FUN_00023700(iVar4,param_2 + 0x2300,uVar5);
      }
      else if (0 < iVar3) {
        iVar7 = 0;
        do {
          iVar7 = iVar7 + 1;
          puVar2 = (undefined4 *)FUN_00023700(iVar4,param_2,puVar2);
          param_2 = param_2 + 0x100;
        } while (iVar3 != iVar7);
      }
    }
    else if (iVar3 == 0x24) {
      uVar5 = FUN_00023870(iVar4,uVar6,param_2,puVar2);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x100,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x200,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x300,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x400,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x500,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x600,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x700,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x800,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x900,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xa00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xb00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xc00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xd00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xe00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xf00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1000,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001100) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001200) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001300) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001400) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001500) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001600) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001700) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1800,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1900,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1a00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1b00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1c00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1d00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1e00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1f00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2000,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2100,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2200,uVar5);
      puVar2 = (undefined4 *)FUN_00023870(iVar4,uVar6,param_2 + 0x2300,uVar5);
    }
    else if (0 < iVar3) {
      iVar7 = 0;
      do {
        iVar7 = iVar7 + 1;
        puVar2 = (undefined4 *)FUN_00023870(iVar4,uVar6,param_2,puVar2);
        param_2 = param_2 + 0x100;
      } while (iVar3 != iVar7);
    }
    *puVar2 = 0x92b;
    puVar2[3] = 0;
    puVar2[2] = ((unsigned char *)0x00001393);
    puVar2[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar2 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(iVar4);
    return;
  }
  return;
}

/* FUN_000248f0 @ 0x248f0 (112 bytes) */
int FUN_000248f0(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar3 = ((int (*)())FUN_0002cc30)(param_1,param_4,3,param_3);
  if (iVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar5 = *(undefined4 *)(param_1 + 0x244);
    uVar6 = *(undefined4 *)(param_1 + 0x1ee0);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              iVar3 * *(int *)(param_1 + 0x267c) * 5 + iVar3 * 2 + 0x16);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != FUN_00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = FUN_00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(FUN_000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar5);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar5 = *(undefined4 *)(FUN_00001dc4 + param_1);
    puVar1[2] = 0x821;
    puVar1[3] = 3;
    puVar1[1] = uVar5;
    if (*(char *)(*(int *)(param_1 + 0x244) + 0x20) == '\0') {
      if (iVar3 == 0x24) {
        uVar5 = FUN_00023700(iVar4,param_2,puVar2);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x100,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x200,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x300,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x400,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x500,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x600,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x700,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x800,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x900,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xa00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xb00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xc00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xd00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xe00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0xf00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1000,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001100) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001200) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001300) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001400) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001500) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001600) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,((unsigned char *)0x00001700) + param_2,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1800,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1900,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1a00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1b00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1c00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1d00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1e00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x1f00,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2000,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2100,uVar5);
        uVar5 = FUN_00023700(iVar4,param_2 + 0x2200,uVar5);
        puVar2 = (undefined4 *)FUN_00023700(iVar4,param_2 + 0x2300,uVar5);
      }
      else if (0 < iVar3) {
        iVar7 = 0;
        do {
          iVar7 = iVar7 + 1;
          puVar2 = (undefined4 *)FUN_00023700(iVar4,param_2,puVar2);
          param_2 = param_2 + 0x100;
        } while (iVar3 != iVar7);
      }
    }
    else if (iVar3 == 0x24) {
      uVar5 = FUN_00023870(iVar4,uVar6,param_2,puVar2);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x100,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x200,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x300,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x400,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x500,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x600,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x700,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x800,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x900,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xa00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xb00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xc00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xd00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xe00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0xf00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1000,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001100) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001200) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001300) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001400) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001500) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001600) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,((unsigned char *)0x00001700) + param_2,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1800,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1900,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1a00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1b00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1c00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1d00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1e00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x1f00,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2000,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2100,uVar5);
      uVar5 = FUN_00023870(iVar4,uVar6,param_2 + 0x2200,uVar5);
      puVar2 = (undefined4 *)FUN_00023870(iVar4,uVar6,param_2 + 0x2300,uVar5);
    }
    else if (0 < iVar3) {
      iVar7 = 0;
      do {
        iVar7 = iVar7 + 1;
        puVar2 = (undefined4 *)FUN_00023870(iVar4,uVar6,param_2,puVar2);
        param_2 = param_2 + 0x100;
      } while (iVar3 != iVar7);
    }
    *puVar2 = 0x92b;
    puVar2[3] = 0;
    puVar2[2] = ((unsigned char *)0x00001393);
    puVar2[1] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar2 + 4;
                    
                    
    (**(code **)(param_1 + 0x299c))(iVar4);
    return;
  }
  return;
}

/* FUN_00024970 @ 0x24970 (1588 bytes) */
int FUN_00024970(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
  undefined *param_6;
  uint *param_7;
{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint *puVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  uVar12 = (uint)*(byte *)(param_1 + 8);
  dataCacheBlockTouch(*(undefined4 *)(param_1 + 0x1d8));
  iVar3 = ((int (*)())FUN_0002cc30)(param_1,1,param_3,param_5,param_5,param_6,*(undefined4 *)(param_1 + 0x1d8));
  if (iVar3 != 0) {
    iVar9 = 5;
    *(undefined4 *)(param_2 + -0x68) = *(undefined4 *)(*(int *)(param_1 + 0x244) + 0x23c);
    if (uVar12 != 0x20) {
      iVar9 = 7;
    }
    iVar8 = iVar3 + 1 >> 1;
    uVar10 = iVar8 + 0x1f;
    uVar11 = uVar10 >> iVar9;
    puVar4 = (uint *)(**(code **)(param_1 + 0x2998))(param_1 + 0x240,uVar10);
    *(uint **)(param_1 + 0x298c) = puVar4;
    if (1 < uVar11) {
      iVar9 = uVar11 - 1;
      uVar10 = uVar12;
      do {
        dataCacheBlockClearToZero((int)puVar4 + uVar10);
        uVar10 = uVar10 + uVar12;
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
    }
    puVar2 = (undefined4 *)((uint)(puVar4 + 0xb) & 0xffffffe0);
    *puVar4 = (((int)puVar2 - (int)puVar4) + -8) * 0x4000 | 0xc0001000;
    puVar2[-1] = (int)puVar2 - (int)puVar4;
    puVar5 = puVar2 + 0xc;
    puVar4 = *(uint **)(param_1 + 0x1d8);
    iVar9 = *(int *)(param_2 + -0x74) * 0x14;
    *puVar4 = (int)puVar2 - (int)puVar4 >> 2 | *puVar4;
    *(undefined4 **)(param_1 + 0x1d8) = puVar2;
    *puVar2 = 0x26000000;
    uVar6 = **(undefined4 **)(param_2 + -100);
    puVar2[2] = 0x20830;
    puVar2[3] = 0x21;
    puVar2[1] = uVar6;
    uVar6 = *(undefined4 *)(iVar9 + 0x1d975c);
    puVar2[6] = 0x10854;
    puVar2[5] = 0;
    puVar2[4] = uVar6;
    puVar2[7] = *(undefined4 *)(iVar9 + 0x1d9760);
    uVar6 = *(undefined4 *)(iVar9 + 0x1d9764);
    puVar2[9] = 0x10878;
    puVar2[8] = uVar6;
    puVar2[10] = *(undefined4 *)(iVar9 + 0x1d9768);
    puVar2[0xb] = *(undefined4 *)(iVar9 + 0x1d976c);
    if (*(char *)(param_1 + 0x2a42) != '\0') {
      puVar5 = puVar2 + 0xe;
      puVar2[0xc] = 0x5c8;
      puVar2[0xd] = 0x10000000;
      *(undefined1 *)(param_1 + 0x2a42) = 0;
    }
    puVar4 = puVar5 + 4;
    uVar12 = *(uint *)(param_3 * 4 + 0x1d97e8);
    *puVar5 = 0x82c;
    uVar6 = *(undefined4 *)(FUN_00001dc4 + param_1);
    puVar5[2] = iVar8 << 0x10 | 0xc0003600;
    puVar5[1] = uVar6;
    puVar5[3] = iVar3 << 0x10 | uVar12 & 0xf | 0x10;
    uVar12 = iVar3 - 1;
    if (param_6 == ((unsigned char *)0x00001403)) {
      uVar10 = 0;
      puVar7 = param_7;
      if (uVar12 != 0) {
        do {
          uVar10 = uVar10 + 2;
          *puVar4 = (uint)*(ushort *)puVar7 - param_4 & 0xffff |
                    ((uint)(ushort)*puVar7 - param_4) * 0x10000;
          puVar4 = puVar4 + 1;
          puVar7 = puVar7 + 1;
        } while (uVar10 < uVar12);
      }
      if ((uVar12 & 1) == 0) {
        *puVar4 = (uint)*(ushort *)(uVar10 * 2 + (int)param_7) - param_4 & 0xffff;
        puVar4 = puVar4 + 1;
      }
    }
    else if (param_6 == ((unsigned char *)0x00001405)) {
      iVar3 = (int)uVar12 >> 4;
      if (param_4 == 0) {
        if (iVar3 != 0) {
          if (iVar3 == 0) {
            iVar3 = 1;
          }
          do {
            uVar10 = param_7[1];
            uVar11 = *param_7;
            puVar4[1] = param_7[2] | param_7[3] << 0x10;
            *puVar4 = uVar10 << 0x10 | uVar11;
            uVar10 = param_7[5];
            uVar11 = param_7[4];
            puVar4[3] = param_7[6] | param_7[7] << 0x10;
            puVar4[2] = uVar10 << 0x10 | uVar11;
            uVar10 = param_7[9];
            uVar11 = param_7[8];
            puVar4[5] = param_7[10] | param_7[0xb] << 0x10;
            puVar4[4] = uVar10 << 0x10 | uVar11;
            puVar7 = param_7 + 0xd;
            uVar10 = param_7[0xf];
            puVar1 = param_7 + 0xc;
            uVar11 = param_7[0xe];
            param_7 = param_7 + 0x10;
            puVar4[6] = *puVar1 | *puVar7 << 0x10;
            puVar4[7] = uVar11 | uVar10 << 0x10;
            puVar4 = puVar4 + 8;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        if ((uVar12 & 0xf) != 0) {
          uVar10 = 0;
          do {
            puVar7 = param_7 + 1;
            uVar10 = uVar10 + 2;
            uVar11 = *param_7;
            param_7 = param_7 + 2;
            *puVar4 = uVar11 | *puVar7 << 0x10;
            puVar4 = puVar4 + 1;
          } while (uVar10 < (uVar12 & 0xf));
        }
        if ((uVar12 & 1) == 0) {
          *puVar4 = (uint)(ushort)*param_7;
          puVar4 = puVar4 + 1;
        }
      }
      else {
        if (iVar3 != 0) {
          if (iVar3 == 0) {
            iVar3 = 1;
          }
          do {
            uVar10 = param_7[1];
            uVar11 = *param_7;
            puVar4[1] = param_7[2] - param_4 | (param_7[3] - param_4) * 0x10000;
            *puVar4 = uVar11 - param_4 | (uVar10 - param_4) * 0x10000;
            uVar10 = param_7[5];
            uVar11 = param_7[4];
            puVar4[3] = (param_7[7] - param_4) * 0x10000 | param_7[6] - param_4 & 0xffff;
            puVar4[2] = (uVar10 - param_4) * 0x10000 | uVar11 - param_4 & 0xffff;
            uVar10 = param_7[9];
            uVar11 = param_7[8];
            puVar4[5] = (param_7[0xb] - param_4) * 0x10000 | param_7[10] - param_4 & 0xffff;
            puVar4[4] = (uVar10 - param_4) * 0x10000 | uVar11 - param_4 & 0xffff;
            puVar7 = param_7 + 0xc;
            puVar1 = param_7 + 0xd;
            uVar11 = param_7[0xe];
            uVar10 = param_7[0xf];
            param_7 = param_7 + 0x10;
            puVar4[6] = (*puVar1 - param_4) * 0x10000 | *puVar7 - param_4 & 0xffff;
            puVar4[7] = (uVar10 - param_4) * 0x10000 | uVar11 - param_4 & 0xffff;
            puVar4 = puVar4 + 8;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        if ((uVar12 & 0xf) != 0) {
          uVar10 = 0;
          do {
            uVar11 = *param_7;
            puVar7 = param_7 + 1;
            uVar10 = uVar10 + 2;
            param_7 = param_7 + 2;
            *puVar4 = (*puVar7 - param_4) * 0x10000 | uVar11 - param_4 & 0xffff;
            puVar4 = puVar4 + 1;
          } while (uVar10 < (uVar12 & 0xf));
        }
        if ((uVar12 & 1) == 0) {
          *puVar4 = *param_7 - param_4 & 0xffff;
          puVar4 = puVar4 + 1;
        }
      }
    }
    else if (param_6 == ((unsigned char *)0x00001401)) {
      uVar10 = 0;
      puVar7 = param_7;
      if (uVar12 != 0) {
        do {
          uVar10 = uVar10 + 2;
          *puVar4 = (uint)*(byte *)puVar7 - param_4 & 0xffff |
                    ((uint)*(byte *)((int)puVar7 + 1) - param_4) * 0x10000;
          puVar4 = puVar4 + 1;
          puVar7 = (uint *)((int)puVar7 + 2);
        } while (uVar10 < uVar12);
      }
      if ((uVar12 & 1) == 0) {
        *puVar4 = (uint)*(byte *)((int)param_7 + uVar10) - param_4 & 0xffff;
        puVar4 = puVar4 + 1;
      }
    }
    puVar4[1] = 0;
    *puVar4 = (uint)((unsigned char *)0x00001393);
    *(uint **)(param_1 + 0x298c) = puVar4 + 2;
    (**(code **)(param_1 + 0x299c))(param_1 + 0x240);
    *(undefined4 *)(param_1 + 0x26d4) = 0;
    *(undefined1 *)(param_1 + 0x2a5e) = 1;
    *(int *)(param_1 + 0x2680) = param_1 + 0x26dc;
    *(int *)(param_1 + 0x2684) = param_1 + 0x26fc;
    ((code **)FUN_000027d0)[param_1 + 5] = (code *)0x1;
  }
  return;
}

/* FUN_00024fb0 @ 0x24fb0 (16 bytes) */
int FUN_00024fb0(param_1)
  int param_1;
{
  *(int *)(param_1 + 0x30) = param_1 + 0x2c;
  *(int *)(param_1 + 0x2c) = param_1 + 0x2c;
  return;
}

/* FUN_00024fc0 @ 0x24fc0 (4 bytes) */
int FUN_00024fc0()
{
  return;
}

/* FUN_00024fd0 @ 0x24fd0 (4 bytes) */
int FUN_00024fd0()
{
  return;
}

/* FUN_00024fe0 @ 0x24fe0 (2908 bytes) */
int FUN_00024fe0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  float *param_3;
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  dword *pdVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  float *pfVar15;
  dword *pdVar16;
  int iVar17;
  int iVar18;
  uint uVar19;
  dword *pdVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  int iVar24;
  int *piVar25;
  uint *puVar26;
  double dVar27;
  undefined8 uVar28;
  float local_90;
  float local_8c;
  float local_88;
  float local_84 [3];
  undefined4 local_78;
  float fStack_74;
  undefined4 local_70;
  float fStack_6c;
  undefined4 local_68;
  float fStack_64;
  undefined4 local_60;
  float fStack_5c;
  
  uVar28 = FUN_001a3264();
  iVar6 = *(int *)((int)((ulonglong)uVar28 >> 0x20) + 0x18);
  piVar25 = *(int **)(iVar6 + 0x19c);
  bVar1 = piVar25 == (int *)0x0;
  if (bVar1) {
    piVar25 = *(int **)(iVar6 + 400);
  }
  iVar6 = piVar25[0xd];
  if (((iVar6 == 0) && (iVar6 = piVar25[0xc], iVar6 == 0)) && (iVar6 = piVar25[0xb], iVar6 == 0)) {
    iVar18 = *piVar25;
    iVar6 = *(int *)(iVar18 + 4);
  }
  else {
    iVar18 = *piVar25;
  }
  iVar7 = *(int *)(iVar6 + 0x6c);
  iVar23 = *(int *)(iVar18 + 0x18);
  puVar26 = (uint *)(iVar6 + *(int *)(iVar6 + 0x2c) * 8);
  iVar18 = *(int *)(iVar6 + 0x28);
  if ((int)uVar28 < *(int *)(iVar6 + 0x28)) {
    iVar18 = (int)uVar28;
  }
  if (iVar18 < 1) {
LAB_00025b04:
    fVar3 = FLOAT_001aa13c;
    fVar2 = FLOAT_001aa138;
    fVar5 = FLOAT_001aa134;
    iVar6 = piVar25[0xe];
    if (iVar6 != 0) {
      uVar14 = *(uint *)(iVar6 + 0x20);
      if ((uVar14 & 0x4000000) != 0) {
        *param_3 = FLOAT_001aa130;
        param_3[1] = fVar5;
        param_3[2] = fVar2;
        param_3[3] = fVar3;
        param_3 = param_3 + 4;
        uVar14 = *(uint *)(iVar6 + 0x20);
      }
      if ((uVar14 & 0x2000000) != 0) {
        *param_3 = *(float *)(((unsigned char *)0x00002de0) + *(int *)(param_1 + 0x10));
        param_3[1] = *(float *)(((unsigned char *)0x00002de4) + *(int *)(param_1 + 0x10));
        param_3[2] = *(float *)(((unsigned char *)0x00002de8) + *(int *)(param_1 + 0x10));
        param_3[4] = -*(float *)(((unsigned char *)0x00002dfc) + *(int *)(param_1 + 0x10));
        fVar5 = FLOAT_001aa140;
        param_3[5] = *(float *)(((unsigned char *)0x00002df8) + *(int *)(param_1 + 0x10)) *
                     *(float *)(((unsigned char *)0x00002dfc) + *(int *)(param_1 + 0x10));
        fVar2 = FLOAT_001aa144;
        param_3[6] = *(float *)(((unsigned char *)0x00002df0) + *(int *)(param_1 + 0x10)) * fVar5;
        param_3[7] = *(float *)(((unsigned char *)0x00002df0) + *(int *)(param_1 + 0x10)) * fVar2;
      }
    }
    return;
  }
  iVar24 = 0;
LAB_00025090:
  dVar27 = DOUBLE_001aa1e0;
  fVar5 = FLOAT_001aa0e8;
  uVar14 = *puVar26;
  uVar19 = uVar14 & 0x1f0000;
  if (uVar19 == 0) goto LAB_00025af0;
  if (uVar19 == 0x110000) {
    pfVar15 = (float *)(iVar6 + iVar7 * 8 + (uint)(ushort)*puVar26 * 0x10);
LAB_0002546c:
    if ((bVar1) || ((uVar14 & 0x1c000000) == 0x4000000)) {
      *param_3 = *pfVar15;
      param_3[1] = pfVar15[1];
      param_3[2] = pfVar15[2];
      param_3[3] = pfVar15[3];
    }
    else if ((uVar14 & 0x1c000000) == 0xc000000) {
      local_78 = 0x43300000;
      fStack_74 = -*pfVar15;
      *param_3 = (float)((double)CONCAT44(0x43300000,-*pfVar15) - DOUBLE_001aa1e0);
      local_70 = 0x43300000;
      fStack_6c = -pfVar15[1];
      param_3[1] = (float)((double)CONCAT44(0x43300000,-pfVar15[1]) - dVar27);
      local_68 = 0x43300000;
      fStack_64 = -pfVar15[2];
      param_3[2] = (float)((double)CONCAT44(0x43300000,-pfVar15[2]) - dVar27);
      local_60 = 0x43300000;
      fStack_5c = -pfVar15[3];
      param_3[3] = (float)((double)CONCAT44(0x43300000,-pfVar15[3]) - dVar27);
    }
    else {
      if (*pfVar15 == 0.0) {
        fVar5 = 0.0;
      }
      else {
        fVar5 = 1.0;
      }
      *param_3 = fVar5;
      if (pfVar15[1] == 0.0) {
        fVar5 = 0.0;
      }
      else {
        fVar5 = 1.0;
      }
      param_3[1] = fVar5;
      if (pfVar15[2] == 0.0) {
        fVar5 = 0.0;
      }
      else {
        fVar5 = 1.0;
      }
      param_3[2] = fVar5;
      if (pfVar15[3] == 0.0) {
        fVar5 = 0.0;
      }
      else {
        fVar5 = 1.0;
      }
      param_3[3] = fVar5;
    }
    goto LAB_00025af0;
  }
  if (uVar19 == 0x10000) {
    pfVar15 = (float *)(iVar23 + (uint)(ushort)*puVar26 * 0x10);
    goto LAB_0002546c;
  }
  if (uVar19 == 0x20000) {
    iVar22 = (uint)(ushort)*puVar26 * 0x10;
    iVar10 = iVar22 + *(int *)(((unsigned char *)0x00004310) + *(int *)(param_1 + 0x10));
    *param_3 = *(float *)(iVar22 + *(int *)(((unsigned char *)0x00004310) + *(int *)(param_1 + 0x10)));
    param_3[1] = *(float *)(iVar10 + 4);
    param_3[2] = *(float *)(iVar10 + 8);
    param_3[3] = *(float *)(iVar10 + 0xc);
    goto LAB_00025af0;
  }
  if (uVar19 == 0x100000) {
    uVar19 = uVar14 >> 0xc & 3;
    uVar21 = uVar14 & 0xff;
    switch(uVar14 >> 8 & 7) {
    default:
      iVar22 = 0;
      break;
    case 1:
      iVar22 = 0xc0;
      break;
    case 2:
      iVar22 = 0x80;
      break;
    case 3:
      iVar22 = (uVar21 + 4) * 0x40;
      break;
    case 4:
      iVar22 = (uVar21 + 0x10) * 0x40;
      break;
    case 5:
      iVar22 = (uVar21 + 8) * 0x40;
    }
    uVar14 = uVar14 >> 0xe & 3;
    iVar10 = *(int *)(param_1 + 0x10) + 0x1860 + iVar22;
    if ((1 < uVar14) && (iVar10 = iVar22 + *(int *)(param_1 + 0x10) + 0x1e60, 3 < uVar14)) {
      iVar10 = 0;
    }
    if (uVar14 < 3) {
      if (uVar14 == 0) {
LAB_000256f4:
        iVar22 = uVar19 * 4;
        iVar11 = iVar10 + iVar22;
        local_90 = *(float *)(iVar10 + iVar22);
        local_8c = *(float *)(iVar11 + 0x10);
        local_88 = *(float *)(iVar11 + 0x20);
        local_84[0] = *(float *)(iVar11 + 0x30);
      }
      else {
        iVar22 = uVar19 * 0x10;
        iVar11 = iVar10 + iVar22;
        local_90 = *(float *)(iVar10 + iVar22);
        local_8c = *(float *)(iVar11 + 4);
        local_88 = *(float *)(iVar11 + 8);
        local_84[0] = *(float *)(iVar11 + 0xc);
      }
    }
    else if (uVar14 == 3) goto LAB_000256f4;
    goto LAB_00025ac8;
  }
  switch(uVar14 >> 0x10 & 0x1f) {
  case 0:
    pdVar20 = (dword *)&local_8c;
    pdVar9 = (dword *)&local_88;
    pdVar16 = (dword *)local_84;
    pfVar15 = &local_90;
    break;
  default:
    goto switchD_00025774_caseD_1;
  case 2:
    pfVar15 = (float *)((uVar14 & 0xffff) * 0x10 +
                       *(int *)(((unsigned char *)0x00004308) + *(int *)(param_1 + 0x10)));
    pdVar20 = (dword *)(pfVar15 + 1);
    pdVar9 = (dword *)(pfVar15 + 2);
    pdVar16 = (dword *)(pfVar15 + 3);
    break;
  case 3:
    uVar19 = uVar14 & 0xff;
    switch(uVar14 >> 8 & 0xf) {
    case 0:
      pfVar15 = (float *)(uVar19 * 0x80 + 0x24c0 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 1:
      pfVar15 = (float *)(uVar19 * 0x80 + 0x24d0 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 2:
      pfVar15 = (float *)(uVar19 * 0x80 + 0x24e0 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 3:
      pfVar15 = (float *)(uVar19 * 0x80 + 0x24f0 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 4:
      pfVar15 = (float *)(uVar19 * 0x80 + 0x2500 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 5:
      pfVar15 = (float *)(uVar19 * 0x80 + 0x2510 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 6:
      iVar22 = uVar19 * 0x80 + *(int *)(param_1 + 0x10);
      fVar2 = *(float *)(iVar22 + 0x24f4);
      fVar3 = *(float *)(iVar22 + 0x24f0);
      fVar4 = *(float *)(iVar22 + 0x24f8) + FLOAT_001aa0e8;
      dVar27 = (double)_sqrt((double)(fVar4 * fVar4 + fVar3 * fVar3 + fVar2 * fVar2));
      local_84[0] = fVar5;
      fVar5 = (float)(DOUBLE_001aa200 / dVar27);
      local_88 = fVar4 * fVar5;
      local_90 = fVar3 * fVar5;
      local_8c = fVar2 * fVar5;
      goto LAB_00025ac8;
    case 7:
      pfVar15 = (float *)(uVar19 * 0x80 + 0x2530 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    default:
      goto switchD_00025774_caseD_1;
    }
    break;
  case 4:
    uVar19 = uVar14 >> 9 & 3;
    iVar12 = *(int *)(param_1 + 0x10) + 0x24c0;
    iVar22 = (uVar14 & 0xff) * 0x80;
    iVar10 = (uVar14 >> 8 & 1) * 0x240;
    iVar11 = *(int *)(param_1 + 0x10) + 0x28c0;
    iVar17 = iVar12 + iVar22;
    iVar13 = iVar11 + iVar10;
    if (uVar19 == 1) {
      local_90 = *(float *)(iVar17 + 0x10) * *(float *)(iVar13 + 0x10);
      local_8c = *(float *)(iVar17 + 0x14) * *(float *)(iVar13 + 0x14);
      local_88 = *(float *)(iVar17 + 0x18) * *(float *)(iVar13 + 0x18);
      local_84[0] = *(float *)(iVar13 + 0x1c);
    }
    else if (uVar19 == 2) {
      local_90 = *(float *)(iVar17 + 0x20) * *(float *)(iVar13 + 0x20);
      local_8c = *(float *)(iVar17 + 0x24) * *(float *)(iVar13 + 0x24);
      local_88 = *(float *)(iVar17 + 0x28) * *(float *)(iVar13 + 0x28);
      local_84[0] = *(float *)(iVar13 + 0x2c);
    }
    else {
      if (uVar19 != 0) goto switchD_00025774_caseD_1;
      local_90 = *(float *)(iVar12 + iVar22) * *(float *)(iVar11 + iVar10);
      local_8c = *(float *)(iVar17 + 4) * *(float *)(iVar13 + 4);
      local_88 = *(float *)(iVar17 + 8) * *(float *)(iVar13 + 8);
      local_84[0] = *(float *)(iVar13 + 0xc);
    }
    goto LAB_00025ac8;
  case 5:
    uVar19 = uVar14 & 1;
    switch(uVar14 >> 1 & 7) {
    case 0:
      pfVar15 = (float *)(uVar19 * 0x240 + 0x28c0 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 1:
      pfVar15 = (float *)(uVar19 * 0x240 + 0x28d0 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 2:
      pfVar15 = (float *)(uVar19 * 0x240 + 0x28e0 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 3:
      pfVar15 = (float *)(uVar19 * 0x240 + 0x28f0 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 4:
      pfVar15 = (float *)(uVar19 * 0x240 + 0x2900 + *(int *)(param_1 + 0x10));
      pdVar20 = (dword *)(pfVar15 + 1);
      pdVar9 = (dword *)(pfVar15 + 2);
      pdVar16 = (dword *)(pfVar15 + 3);
      break;
    case 5:
      iVar22 = *(int *)(param_1 + 0x10);
      iVar10 = iVar22 + 0x28c0 + uVar19 * 0x240;
      local_90 = *(float *)(iVar22 + 0x24b0) * *(float *)(iVar22 + 0x28c0 + uVar19 * 0x240) +
                 *(float *)(iVar10 + 0x30);
      local_8c = *(float *)(iVar22 + 0x24b4) * *(float *)(iVar10 + 4) + *(float *)(iVar10 + 0x34);
      local_88 = *(float *)(iVar22 + 0x24b8) * *(float *)(iVar10 + 8) + *(float *)(iVar10 + 0x38);
      local_84[0] = *(float *)(iVar10 + 0x1c);
      goto LAB_00025ac8;
    default:
      goto switchD_00025774_caseD_1;
    }
    break;
  case 6:
    iVar22 = *(int *)(param_1 + 0x10);
    pdVar16 = (dword *)(iVar22 + 0x24bc);
    pfVar15 = (float *)(iVar22 + 0x24b0);
    pdVar20 = (dword *)(iVar22 + 0x24b4);
    pdVar9 = (dword *)(iVar22 + 0x24b8);
    break;
  case 7:
    uVar19 = uVar14 >> 5 & 7;
    uVar14 = uVar14 & 0x1f;
    if (uVar19 == 1) {
      iVar22 = *(int *)(param_1 + 0x10);
      puVar8 = ((unsigned char *)0x000039a0) + uVar14 * 0x94;
LAB_00025180:
      pdVar16 = (dword *)(puVar8 + iVar22 + 0x1c);
      pfVar15 = (float *)(puVar8 + iVar22 + 0x10);
      pdVar20 = (dword *)(puVar8 + iVar22 + 0x14);
      pdVar9 = (dword *)(puVar8 + iVar22 + 0x18);
    }
    else {
      if (uVar19 < 2) {
        if (uVar19 == 0) {
          iVar22 = *(int *)(param_1 + 0x10);
          puVar8 = ((unsigned char *)0x00003980) + uVar14 * 0x94;
          goto LAB_0002515c;
        }
        goto switchD_00025774_caseD_1;
      }
      if (uVar19 == 2) {
        iVar22 = *(int *)(param_1 + 0x10);
        puVar8 = ((unsigned char *)0x000039c0) + uVar14 * 0x94;
LAB_000251a4:
        pdVar16 = (dword *)(puVar8 + iVar22 + 0x20);
        pfVar15 = (float *)(puVar8 + iVar22 + 0x14);
        pdVar20 = (dword *)(puVar8 + iVar22 + 0x18);
        pdVar9 = (dword *)(puVar8 + iVar22 + 0x1c);
      }
      else {
        if (uVar19 != 3) goto switchD_00025774_caseD_1;
        iVar22 = *(int *)(param_1 + 0x10);
        puVar8 = ((unsigned char *)0x000039e0) + uVar14 * 0x94;
LAB_000251c8:
        pdVar16 = (dword *)(puVar8 + iVar22 + 0x24);
        pfVar15 = (float *)(puVar8 + iVar22 + 0x18);
        pdVar20 = (dword *)(puVar8 + iVar22 + 0x1c);
        pdVar9 = (dword *)(puVar8 + iVar22 + 0x20);
      }
    }
    break;
  case 8:
    uVar19 = uVar14 >> 5 & 7;
    uVar14 = uVar14 & 0x1f;
    if (uVar19 == 1) {
      iVar22 = *(int *)(param_1 + 0x10);
      puVar8 = ((unsigned char *)0x000039b0) + uVar14 * 0x94;
      goto LAB_00025180;
    }
    if (uVar19 < 2) {
      if (uVar19 == 0) {
        iVar22 = *(int *)(param_1 + 0x10);
        puVar8 = ((unsigned char *)0x00003990) + uVar14 * 0x94;
        goto LAB_0002515c;
      }
    }
    else {
      if (uVar19 == 2) {
        iVar22 = *(int *)(param_1 + 0x10);
        puVar8 = ((unsigned char *)0x000039d0) + uVar14 * 0x94;
        goto LAB_000251a4;
      }
      if (uVar19 == 3) {
        iVar22 = *(int *)(param_1 + 0x10);
        puVar8 = ((unsigned char *)0x000039f0) + uVar14 * 0x94;
        goto LAB_000251c8;
      }
    }
    goto switchD_00025774_caseD_1;
  case 9:
    iVar22 = *(int *)(param_1 + 0x10) + (uVar14 & 0x1f) * 0x7c;
    pfVar15 = (float *)(((unsigned char *)0x000031c0) + iVar22 + 4);
    pdVar16 = (dword *)(((unsigned char *)0x000031c0) + iVar22 + 0x10);
    pdVar9 = (dword *)(((unsigned char *)0x000031c0) + iVar22 + 0xc);
    pdVar20 = (dword *)(((unsigned char *)0x000031c0) + iVar22 + 8);
    break;
  case 10:
    iVar22 = *(int *)(param_1 + 0x10);
    puVar8 = ((unsigned char *)0x00003e20) + (uVar14 & 0xff) * 0x10;
LAB_0002515c:
    pdVar16 = (dword *)(puVar8 + iVar22 + 0x18);
    pfVar15 = (float *)(puVar8 + iVar22 + 0xc);
    pdVar20 = (dword *)(puVar8 + iVar22 + 0x10);
    pdVar9 = (dword *)(puVar8 + iVar22 + 0x14);
    break;
  case 0xb:
    iVar22 = *(int *)(param_1 + 0x10);
    pdVar16 = (dword *)(((unsigned char *)0x00002dec) + iVar22);
    pfVar15 = (float *)(((unsigned char *)0x00002de0) + iVar22);
    pdVar20 = (dword *)(((unsigned char *)0x00002de4) + iVar22);
    pdVar9 = (dword *)(((unsigned char *)0x00002de8) + iVar22);
    break;
  case 0xc:
    iVar22 = *(int *)(param_1 + 0x10);
    pdVar16 = (dword *)(((unsigned char *)0x00002dfc) + iVar22);
    pfVar15 = (float *)(((unsigned char *)0x00002df0) + iVar22);
    pdVar20 = (dword *)(((unsigned char *)0x00002df4) + iVar22);
    pdVar9 = (dword *)(((unsigned char *)0x00002df8) + iVar22);
    break;
  case 0xd:
    iVar22 = *(int *)(param_1 + 0x10);
    pdVar16 = (dword *)(((unsigned char *)0x000030c8) + iVar22);
    pfVar15 = (float *)(((unsigned char *)0x000030bc) + iVar22);
    pdVar20 = (dword *)(((unsigned char *)0x000030c0) + iVar22);
    pdVar9 = (dword *)(((unsigned char *)0x000030c4) + iVar22);
    break;
  case 0xe:
    iVar22 = *(int *)(param_1 + 0x10);
    pdVar16 = (dword *)(((unsigned char *)0x000030d8) + iVar22);
    pfVar15 = (float *)(((unsigned char *)0x000030cc) + iVar22);
    pdVar20 = (dword *)(((unsigned char *)0x000030d0) + iVar22);
    pdVar9 = (dword *)(((unsigned char *)0x000030d4) + iVar22);
    break;
  case 0xf:
    iVar22 = *(int *)(param_1 + 0x10);
    local_90 = (float)*(double *)(FUN_00001830 + iVar22);
    local_8c = (float)*(double *)(iVar22 + 0x1838);
    local_84[0] = 1.0;
    local_88 = (float)(*(double *)(iVar22 + 0x1838) - *(double *)(FUN_00001830 + iVar22));
    goto LAB_00025ac8;
  case 0x12:
    local_84[0] = *(float *)(*(int *)(param_1 + 0x10) + 0x24a4);
    local_90 = local_84[0];
    local_8c = local_84[0];
    local_88 = local_84[0];
    goto LAB_00025ac8;
  }
LAB_00025aa8:
  local_90 = *pfVar15;
  local_8c = (float)*pdVar20;
  local_88 = (float)*pdVar9;
  local_84[0] = (float)*pdVar16;
LAB_00025ac8:
  param_3[1] = local_8c;
  param_3[2] = local_88;
  *param_3 = local_90;
  param_3[3] = local_84[0];
LAB_00025af0:
  iVar24 = iVar24 + 1;
  puVar26 = puVar26 + 2;
  param_3 = param_3 + 4;
  if (iVar18 == iVar24) goto LAB_00025b04;
  goto LAB_00025090;
switchD_00025774_caseD_1:
  pfVar15 = (float *)0x0;
  pdVar20 = &MACH_HEADER.cputype;
  pdVar9 = &MACH_HEADER.cpusubtype;
  pdVar16 = &MACH_HEADER.filetype;
  goto LAB_00025aa8;
}

/* FUN_00025bf0 @ 0x25bf0 (408 bytes) */
int FUN_00025bf0(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if (*(int *)(param_2 + 0x1c) != 0) {
    _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
    if (*(int *)(param_2 + 0x2c) != 0) {
      _glpFreePPShaderLinearize();
      *(undefined4 *)(param_2 + 0x2c) = 0;
    }
    if (*(int *)(param_2 + 0x30) != 0) {
      _glpFreePPShaderToProgram();
      *(undefined4 *)(param_2 + 0x30) = 0;
    }
    if (*(int *)(param_2 + 0x34) != 0) {
      *(undefined4 *)(param_2 + 0x34) = 0;
    }
    FUN_0003f5d0(*(undefined4 *)(param_2 + 0x38));
    *(undefined4 *)(param_2 + 0x38) = 0;
    piVar2 = *(int **)(param_2 + 0x24);
    while (piVar2 != (int *)(param_2 + 0x20)) {
      iVar1 = *(int *)(param_2 + 0x1c);
      piVar4 = (int *)piVar2[1];
      if (iVar1 == 2) {
        FUN_000a0d70(piVar2[2] + 0x240,1,piVar2 + 5);
        piVar3 = (int *)piVar2[1];
      }
      else if (iVar1 == 3) {
        FUN_0003e4c0(piVar2[2] + 0x240,piVar2 + 5);
        piVar3 = (int *)piVar2[1];
      }
      else {
        piVar3 = piVar4;
        if (iVar1 == 1) {
          FUN_0003c310(piVar2[2] + 0x240,piVar2 + 5);
          piVar3 = (int *)piVar2[1];
        }
      }
      iVar1 = *piVar2;
      piVar2[2] = 0;
      *(int **)(iVar1 + 4) = piVar3;
      *(int *)piVar2[1] = iVar1;
      _free(piVar2);
      piVar2 = piVar4;
    }
    iVar1 = *(int *)(param_2 + 0xc);
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 4) = *(undefined4 *)(param_2 + 0x10);
      piVar2 = *(int **)(param_2 + 0x10);
      *(undefined4 *)(param_2 + 0x10) = 0;
      *piVar2 = iVar1;
      *(undefined4 *)(param_2 + 0xc) = 0;
    }
    _pthread_mutex_unlock(*(pthread_mutex_t **)(param_1 + 0xc));
    return;
  }
  return;
}

/* FUN_00025da0 @ 0x25da0 (264 bytes) */
int FUN_00025da0(param_1)
  int param_1;
{
  int iVar1;
  pthread_mutex_t *ppVar2;
  int iVar3;
  undefined1 *puVar4;
  int *piVar5;
  
  _pthread_mutex_lock(*(pthread_mutex_t **)(param_1 + 0xc));
  ppVar2 = *(pthread_mutex_t **)(param_1 + 0xc);
  puVar4 = *(undefined1 **)(ppVar2->__opaque + 0x2c);
  if (ppVar2->__opaque + 0x28 != puVar4) {
    do {
      for (piVar5 = *(int **)(puVar4 + 0x18); piVar5 != (int *)(puVar4 + 0x14);
          piVar5 = (int *)piVar5[1]) {
        iVar3 = piVar5[2];
        if (param_1 == iVar3) {
          iVar1 = *(int *)(puVar4 + 0x10);
          if (iVar1 == 2) {
            FUN_000a0d70(iVar3 + 0x240,1,piVar5 + 5);
          }
          else if (iVar1 == 3) {
            FUN_0003e4c0(iVar3 + 0x240,piVar5 + 5);
          }
          else if (iVar1 == 1) {
            FUN_0003c310(iVar3 + 0x240,piVar5 + 5);
          }
          iVar3 = *piVar5;
          piVar5[2] = 0;
          *(int *)(iVar3 + 4) = piVar5[1];
          *(int *)piVar5[1] = iVar3;
          _free(piVar5);
          break;
        }
      }
      puVar4 = *(undefined1 **)(puVar4 + 4);
    } while (ppVar2->__opaque + 0x28 != puVar4);
    ppVar2 = *(pthread_mutex_t **)(param_1 + 0xc);
  }
  _pthread_mutex_unlock(ppVar2);
  return;
}

/* FUN_00025ec0 @ 0x25ec0 (1372 bytes) */
int FUN_00025ec0(param_1, param_2)
  int param_1;
  int *param_2;
{
  byte *pbVar1;
  byte *pbVar2;
  bool bVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  char *pcVar7;
  size_t sVar8;
  undefined4 uVar9;
  int iVar10;
  bool bVar11;
  uint uVar12;
  byte *pbVar13;
  int *piVar14;
  int *piVar15;
  
  piVar15 = (int *)(param_1 + 0x240);
  for (piVar5 = (int *)param_2[9]; piVar5 != param_2 + 8; piVar5 = (int *)piVar5[1]) {
    if (param_1 == piVar5[2]) goto LAB_00025f80;
  }
  piVar5 = _calloc(1,*(int *)(&DAT_001aa4c4 + param_2[7] * 4) + 0x14);
  piVar5[3] = param_2[5] + -1;
  iVar10 = param_2[6];
  piVar5[2] = param_1;
  piVar5[1] = (int)(param_2 + 8);
  piVar5[4] = iVar10 + -1;
  *piVar5 = param_2[8];
  param_2[8] = (int)piVar5;
  *(int **)(*piVar5 + 4) = piVar5;
LAB_00025f80:
  piVar14 = piVar5 + 5;
  if ((piVar5[5] == 0) && (FUN_000a0570(piVar15,1,piVar14), piVar5[5] == 0)) {
LAB_000263d8:
    uVar9 = 0;
  }
  else {
    FUN_000a0380(piVar15,0x8804);
    if (piVar5[3] == param_2[5]) {
      pbVar13 = (byte *)param_2[0xe];
      if (pbVar13 != (byte *)0x0) {
        uVar12 = *(uint *)(pbVar13 + 0x20);
        uVar4 = uVar12 >> 0x1b;
        if (uVar4 == 0) {
LAB_00026008:
          bVar11 = false;
        }
        else {
          if ((uint)pbVar13[1] == *(uint *)(*(int *)(*param_2 + 0x18) + (uint)*pbVar13 * 0x10)) {
            do {
              uVar4 = uVar4 - 1;
              if (uVar4 == 0) goto LAB_00026008;
              pbVar1 = pbVar13 + 2;
              pbVar2 = pbVar13 + 3;
              pbVar13 = pbVar13 + 2;
            } while ((uint)*pbVar2 == *(uint *)(*(int *)(*param_2 + 0x18) + (uint)*pbVar1 * 0x10));
          }
          bVar11 = true;
        }
        if (((((uVar12 & 0x1000000) != 0) &&
             ((uVar12 >> 0x17 & 1) != (uint)(byte)((unsigned char *)0x00002b7c)[param_1])) ||
            (((uVar12 & 0x400000) == 0 &&
             ((uVar12 >> 0x12 & 0xf) != (*(uint *)(param_1 + 0x1ae4) >> 6 & 0xffff))))) || (bVar11))
        {
          uVar4 = param_2[0xf];
          param_2[0xf] = uVar4 | 1;
          param_2[5] = param_2[5] + 1;
          if ((uVar4 & 2) != 0) {
            param_2[6] = param_2[6] + 1;
          }
          param_2[0xf] = 0;
          bVar11 = piVar5[3] != param_2[5];
          if (bVar11) {
            piVar5[3] = param_2[5];
          }
          goto LAB_000260dc;
        }
      }
LAB_000263c0:
      if (*(char *)(param_2 + 10) != '\0') goto LAB_000263d8;
    }
    else {
      piVar5[3] = param_2[5];
      bVar11 = true;
LAB_000260dc:
      if (!bVar11) goto LAB_000263c0;
      *(undefined1 *)(param_2 + 10) = 0;
      if (param_2[0xb] != 0) {
        _glpFreePPShaderLinearize();
        param_2[0xb] = 0;
      }
      if (param_2[0xc] != 0) {
        _glpFreePPShaderToProgram();
        param_2[0xc] = 0;
      }
      if (param_2[0xd] != 0) {
        param_2[0xd] = 0;
      }
      bVar11 = false;
      uVar4 = 0x1f9;
      FUN_0003f5d0(param_2[0xe]);
      param_2[0xe] = 0;
      while( true ) {
        if (*(short *)*param_2 == -0x74d0) {
          iVar10 = _glpPPShaderLinearize(*(undefined4 *)((short *)*param_2 + 2),uVar4);
          param_2[0xb] = iVar10;
        }
        piVar6 = (int *)FUN_0003f660();
        iVar10 = param_2[0xd];
        if (((iVar10 == 0) && (iVar10 = param_2[0xc], iVar10 == 0)) &&
           (iVar10 = param_2[0xb], iVar10 == 0)) {
          iVar10 = *(int *)(*param_2 + 4);
        }
        *piVar6 = iVar10;
        iVar10 = *(int *)(*param_2 + 0xc);
        piVar6[1] = *(int *)(*param_2 + 8);
        piVar6[2] = iVar10;
        piVar6[3] = *(int *)(*param_2 + 0x18);
        *(uint *)(piVar6[0xd] + 0x20) =
             ((byte)((unsigned char *)0x00002b7c)[param_1] & 1) << 0x17 |
             *(uint *)(piVar6[0xd] + 0x20) & 0xff7fffff;
        *(uint *)(piVar6[0xd] + 0x20) =
             (*(uint *)(param_1 + 0x1ae4) & 0x3c0) << 0xc |
             *(uint *)(piVar6[0xd] + 0x20) & 0xffc3ffff;
        iVar10 = FUN_00048da0(piVar6);
        if (iVar10 == 0) {
          *piVar15 = 0;
          FUN_0008e2e0(piVar15,0,piVar6[0xb],piVar6[10]);
          bVar11 = *piVar15 == 0;
          bVar3 = !bVar11;
          if (!bVar3) {
            iVar10 = piVar6[0xd];
            piVar6[0xd] = *piVar15;
            param_2[0xe] = iVar10;
            goto LAB_0002639c;
          }
        }
        else {
          bVar3 = !bVar11;
          if (!bVar3) goto LAB_0002639c;
        }
        if ((*(short *)*param_2 != -0x74d0) || ((uVar4 & 6) == 6)) break;
        if ((uVar4 & 4) == 0) {
          uVar4 = uVar4 | 4;
        }
        else if ((uVar4 & 2) == 0) {
          uVar4 = uVar4 & 0xfffffffb | 2;
        }
        if (param_2[0xb] != 0) {
          _glpFreePPShaderLinearize();
          param_2[0xb] = 0;
        }
        if (param_2[0xc] != 0) {
          _glpFreePPShaderToProgram();
          param_2[0xc] = 0;
        }
        if (param_2[0xd] != 0) {
          param_2[0xd] = 0;
        }
        FUN_0003f5d0(param_2[0xe]);
        param_2[0xe] = 0;
        FUN_0003f5e0(piVar6);
      }
      if (bVar3) {
        if (*(short *)*param_2 == -0x74d0) {
          bVar3 = true;
        }
        else {
          *piVar15 = 0;
          iVar10 = param_2[0xd];
          if (((iVar10 == 0) && (iVar10 = param_2[0xc], iVar10 == 0)) &&
             (iVar10 = param_2[0xb], iVar10 == 0)) {
            iVar10 = *(int *)(*param_2 + 4);
          }
          pcVar7 = (char *)FUN_0000f620(iVar10);
          if (pcVar7 == (char *)0x0) {
            FUN_000a0d70(piVar15,1,piVar14);
            *piVar14 = 0;
            return 0;
          }
          sVar8 = _strlen(pcVar7);
          FUN_000a0300(piVar15,0x8804,0x8875,sVar8,pcVar7);
          _free(pcVar7);
          bVar3 = *piVar15 != 0;
        }
      }
      else {
        bVar3 = false;
      }
LAB_0002639c:
      FUN_0003f5e0(piVar6);
      if (bVar3) {
        *(undefined1 *)(param_2 + 10) = 1;
        return 0;
      }
    }
    uVar9 = 1;
    *(int **)(param_1 + 0x29ec) = piVar5;
  }
  return uVar9;
}

/* FUN_00026440 @ 0x26440 (500 bytes) */
int FUN_00026440(param_1, param_2)
  int param_1;
  int *param_2;
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  for (piVar1 = (int *)param_2[9]; piVar1 != param_2 + 8; piVar1 = (int *)piVar1[1]) {
    if (param_1 == piVar1[2]) goto LAB_000264f0;
  }
  piVar1 = _calloc(1,*(int *)(&DAT_001aa4c4 + param_2[7] * 4) + 0x14);
  piVar1[3] = param_2[5] + -1;
  iVar2 = param_2[6];
  piVar1[2] = param_1;
  piVar1[1] = (int)(param_2 + 8);
  piVar1[4] = iVar2 + -1;
  *piVar1 = param_2[8];
  param_2[8] = (int)piVar1;
  *(int **)(*piVar1 + 4) = piVar1;
LAB_000264f0:
  iVar3 = param_1 + 0x240;
  iVar2 = FUN_0003b5b0(iVar3,piVar1 + 5);
  if (iVar2 != 0) {
    if (piVar1[3] == param_2[5]) {
      iVar2 = FUN_00053070(iVar3);
    }
    else {
      piVar1[3] = param_2[5];
      if (param_2[0xb] != 0) {
        _glpFreePPShaderLinearize();
        param_2[0xb] = 0;
      }
      if (param_2[0xc] != 0) {
        _glpFreePPShaderToProgram();
        param_2[0xc] = 0;
      }
      if (param_2[0xd] != 0) {
        param_2[0xd] = 0;
      }
      FUN_0003f5d0(param_2[0xe]);
      param_2[0xe] = 0;
      if (*(short *)*param_2 == -0x74cf) {
        iVar2 = _glpPPShaderLinearize(*(undefined4 *)((short *)*param_2 + 2),0xff);
        param_2[0xb] = iVar2;
        if (iVar2 != 0) {
          iVar2 = _glpPPShaderToProgram(iVar2,*(undefined4 *)(*param_2 + 0x18),0);
          param_2[0xc] = iVar2;
        }
      }
      iVar2 = param_2[0xd];
      if (((iVar2 == 0) && (iVar2 = param_2[0xc], iVar2 == 0)) && (iVar2 = param_2[0xb], iVar2 == 0)
         ) {
        iVar2 = *(int *)(*param_2 + 4);
      }
      iVar2 = FUN_0003c400(iVar3,iVar2,piVar1 + 5);
    }
    if (iVar2 != 0) {
      *(int **)(param_1 + 0x29e8) = piVar1;
      return 1;
    }
  }
  return 0;
}

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
      uVar2 = ((int (*)())FUN_00026440)(param_1,param_2);
      return uVar2;
    }
    if (*psVar3 == -0x74cf) {
      uVar2 = ((int (*)())FUN_00026440)(param_1,param_2);
      return uVar2 & 0xff;
    }
  }
  else if (psVar3[1] == 1) {
    sVar1 = *psVar3;
    if (sVar1 == -0x77fc) {
      uVar2 = ((int (*)())FUN_00025ec0)(param_1,param_2);
      return uVar2;
    }
    if (sVar1 == -0x74d0) {
      uVar2 = ((int (*)())FUN_00025ec0)(param_1,param_2);
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

/* FUN_00026bf0 @ 0x26bf0 (876 bytes) */
int FUN_00026bf0(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  
  if (param_4 < 4) {
    iVar6 = ((int (*)())FUN_0002bf30)(param_1,param_3,param_4);
  }
  else {
    iVar6 = ((int (*)())FUN_0002bea0)(param_1,param_3,param_4);
  }
  if (iVar6 == 0) {
    return;
  }
  if ((*(uint *)(param_1 + 0x27d8) & 6) == 0) {
    if (*(char *)(param_1 + 0x27d4) == '\0') {
      bVar1 = *(byte *)(*(int *)(((unsigned char *)0x000027cc) + param_1) + 2);
    }
    else {
      bVar1 = *(byte *)(*(int *)(FUN_000027d0 + param_1) + 2);
    }
    puVar7 = *(undefined4 **)(param_1 + 0x1dc);
    *(undefined4 **)(param_1 + 0x298c) = puVar7;
    if (*(char *)(param_1 + 0x27d4) == '\0') {
      iVar8 = param_1 + 0x2840;
      if (*(int *)(param_1 + 0x2680) != iVar8) {
        uVar9 = *(undefined4 *)(param_1 + 0x28e0);
        iVar10 = param_1 + 0x2860;
        goto LAB_00026ea8;
      }
    }
    else {
      iVar8 = param_1 + 0x28e4;
      if (*(int *)(param_1 + 0x2680) != iVar8) {
        uVar9 = *(undefined4 *)(param_1 + 0x2984);
        iVar10 = param_1 + 0x2904;
LAB_00026ea8:
        *(int *)(param_1 + 0x2680) = iVar8;
        *(int *)(param_1 + 0x2684) = iVar10;
        *(undefined4 *)(FUN_000026c8 + param_1 + 4) = uVar9;
        puVar7 = (undefined4 *)((int (*)())FUN_0002c0c0)(param_1,puVar7);
      }
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar7 = 0x5c8;
      puVar7[1] = 0x10000000;
      puVar7 = puVar7 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    iVar8 = (uint)bVar1 * iVar6;
    *puVar7 = 0x82c;
    puVar7[1] = *(undefined4 *)(FUN_00001dc4 + param_1);
    uVar3 = *(uint *)(&DAT_001d9888 + param_3 * 4);
    puVar7[2] = iVar8 * 0x10000 | 0xc0003500;
    puVar7[3] = iVar6 << 0x10 | uVar3 & 0xf | 0x30;
    puVar7[iVar8 + 4] = ((unsigned char *)0x00001393);
    puVar7[iVar8 + 5] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar7 + iVar8 + 6;
    *(undefined4 **)(param_1 + 0x1dc) = puVar7 + iVar8 + 6;
    goto LAB_00026f60;
  }
  uVar3 = *(uint *)(param_1 + 0x283c);
  if (*(char *)(param_1 + 0x27d4) == '\0') {
    bVar1 = *(byte *)(*(int *)(((unsigned char *)0x000027cc) + param_1) + 2);
  }
  else {
    bVar1 = *(byte *)(*(int *)(FUN_000027d0 + param_1) + 2);
  }
  iVar10 = *(int *)(param_1 + 0x1ec);
  puVar7 = *(undefined4 **)(param_1 + 0x1dc);
  iVar8 = (uint)bVar1 * iVar6 * 4;
  *(int *)(param_1 + 0x1ec) = iVar10 + iVar8;
  *(undefined4 **)(param_1 + 0x298c) = puVar7;
  puVar4 = *(uint **)(param_1 + 0x1d8);
  *puVar4 = (int)puVar7 - (int)puVar4 >> 2 | *puVar4;
  *(undefined4 **)(param_1 + 0x1d8) = puVar7;
  puVar7[1] = uVar3 & 0x1f;
  puVar7[2] = iVar10 - (int)puVar7 >> 2;
  *puVar7 = 0x38000000;
  puVar7[3] = 0;
  if (*(char *)(param_1 + 0x27d4) == '\0') {
    *(int *)(param_1 + 0x26d4) = param_1 + 0x2880;
    *(int *)(param_1 + 0x26d8) = param_1 + 0x28a0;
    *(undefined4 *)(param_1 + 0x26d0) = *(undefined4 *)(param_1 + 0x283c);
    puVar7 = (undefined4 *)((int (*)())FUN_0002c180)(param_1,puVar7 + 4);
    iVar5 = param_1 + 0x2840;
    if (*(int *)(param_1 + 0x2680) != iVar5) {
      iVar2 = param_1 + 0x2860;
      goto LAB_00026d64;
    }
  }
  else {
    *(int *)(param_1 + 0x26d4) = param_1 + 0x2924;
    *(int *)(param_1 + 0x26d8) = param_1 + 0x2944;
    *(undefined4 *)(param_1 + 0x26d0) = *(undefined4 *)(param_1 + 0x283c);
    puVar7 = (undefined4 *)((int (*)())FUN_0002c180)(param_1,puVar7 + 4);
    iVar5 = param_1 + 0x28e4;
    if (*(int *)(param_1 + 0x2680) != iVar5) {
      iVar2 = param_1 + 0x2904;
LAB_00026d64:
      *(int *)(param_1 + 0x2680) = iVar5;
      *(int *)(param_1 + 0x2684) = iVar2;
      puVar7 = (undefined4 *)((int (*)())FUN_0002c0c0)(param_1,puVar7);
    }
  }
  if (*(char *)(param_1 + 0x2a42) != '\0') {
    *puVar7 = 0x5c8;
    puVar7[1] = 0x10000000;
    puVar7 = puVar7 + 2;
    *(undefined1 *)(param_1 + 0x2a42) = 0;
  }
  uVar3 = *(uint *)(&DAT_001d9888 + param_3 * 4);
  *puVar7 = 0x82c;
  uVar9 = *(undefined4 *)(FUN_00001dc4 + param_1);
  puVar7[4] = ((unsigned char *)0x00001393);
  puVar7[2] = 0xc0003400;
  puVar7[5] = 0;
  puVar7[1] = uVar9;
  puVar7[3] = iVar6 << 0x10 | uVar3 & 0xf | 0x820;
  *(undefined4 **)(param_1 + 0x298c) = puVar7 + 6;
  *(undefined4 **)(param_1 + 0x1dc) = puVar7 + 6;
  if (((*(uint *)(param_1 + 0x27d8) & 2) != 0) && ((*(uint *)(param_1 + 0x24) & 2) != 0)) {
    FUN_0000b620(param_1,iVar10,iVar8);
  }
LAB_00026f60:
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  return;
}

/* FUN_00026f80 @ 0x26f80 (460 bytes) */
int FUN_00026f80(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint *param_3;
{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uStack_38;
  int iStack_34;
  uint uStack_30;
  
  if (((unsigned char *)0x00002b80)[param_1] != '\0') {
    ((int (*)())FUN_0002be90)(param_1,1,param_2);
  }
  if (*(int *)(param_1 + 0x1b68) != 0) {
    ((int (*)())FUN_0002c020)(param_1 + 0x240,param_2);
  }
  if ((*param_3 == 0) || (*(int *)(*(int *)(param_1 + 0x14) + 0x120) == 0)) {
    bVar1 = *(byte *)(*(int *)(((unsigned char *)0x000027cc) + param_1) + 2);
    *(undefined1 *)(param_1 + 0x27d4) = 0;
  }
  else {
    bVar1 = *(byte *)(*(int *)(FUN_000027d0 + param_1) + 2);
    *(undefined1 *)(param_1 + 0x27d4) = 1;
  }
  iVar5 = *(int *)(param_1 + 500);
  uVar4 = *(uint *)(param_1 + 0x1f8);
  if (uVar4 <= (uint)bVar1 * 0x90 + iVar5 + 0x80) {
    uStack_38 = 2;
    uVar4 = *(int *)(param_1 + 0x204) + 1;
    *(uint *)(param_1 + 0x204) = uVar4;
    if (2 < uVar4) {
      if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
        FUN_0001a0f0(param_1,0x1000000);
        iVar5 = *(int *)(param_1 + 500);
      }
      *(undefined4 *)(param_1 + 0x204) = 1;
    }
    *(int *)(*(int *)(param_1 + 0x208) + 0xc) = iVar5 - *(int *)(param_1 + 0x1fc) >> 2;
    _io_connect_method_scalarI_scalarO(*(undefined4 *)(param_1 + 4),0x12,0,0,&iStack_34,&uStack_38);
    uVar3 = *(uint *)(FUN_000026c8 + param_1);
    *(int *)(param_1 + 0x1fc) = iStack_34;
    uVar4 = iStack_34 + (uStack_30 & 0xfffffffc);
    *(int *)(param_1 + 500) = iStack_34;
    *(uint *)(param_1 + 0x1f8) = uVar4;
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x208) + 8);
    *(uint *)(FUN_000026c8 + param_1) = uVar3 | 1;
    *(undefined4 *)(param_1 + 0x200) = uVar2;
    iVar5 = iStack_34;
  }
  uVar3 = iVar5 + 0x7fU & 0xffffff80;
  *(uint *)(param_1 + 500) = uVar3;
  uVar3 = (((uint)((int)(uVar4 - uVar3) >> 2) / (uint)bVar1) / 0xc) * 0xc;
  uVar4 = 0xfffc;
  if (uVar3 < 0x10000) {
    uVar4 = uVar3;
  }
  *param_3 = uVar4;
  return;
}

/* FUN_00027150 @ 0x27150 (564 bytes) */
int FUN_00027150(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  
  if (param_4 < 4) {
    iVar5 = ((int (*)())FUN_0002bf30)(param_1,param_3,param_4);
  }
  else {
    iVar5 = ((int (*)())FUN_0002bea0)(param_1,param_3,param_4);
  }
  if (iVar5 != 0) {
    uVar2 = *(uint *)(param_1 + 0x283c);
    if (*(char *)(param_1 + 0x27d4) == '\0') {
      bVar1 = *(byte *)(*(int *)(((unsigned char *)0x000027cc) + param_1) + 2);
    }
    else {
      bVar1 = *(byte *)(*(int *)(FUN_000027d0 + param_1) + 2);
    }
    puVar7 = *(undefined4 **)(param_1 + 0x1dc);
    iVar10 = *(int *)(param_1 + 500);
    iVar8 = *(int *)(param_1 + 0x1fc);
    *(uint *)(param_1 + 500) = iVar10 + (uint)bVar1 * iVar5 * 4;
    if (*(undefined4 **)(param_1 + 0x1e0) <= puVar7 + 0x53) {
      FUN_0001a0f0(param_1,0x1000000);
      puVar7 = *(undefined4 **)(param_1 + 0x1dc);
    }
    puVar6 = puVar7;
    if (*(char *)(param_1 + 0x2a42) != '\0') {
      puVar6 = puVar7 + 2;
      *puVar7 = 0x5c8;
      puVar7[1] = 0x10000000;
      *(undefined1 *)(param_1 + 0x2a42) = 0;
    }
    if (*(char *)(param_1 + 0x27d4) == '\0') {
      if (*(int *)(param_1 + 0x2680) != param_1 + 0x2840) {
        *(int *)(param_1 + 0x2680) = param_1 + 0x2840;
        *(int *)(param_1 + 0x2684) = param_1 + 0x2860;
        puVar6 = (undefined4 *)((int (*)())FUN_0002c0c0)(param_1,puVar6);
      }
      puVar3 = *(uint **)(param_1 + 0x1d8);
      iVar11 = param_1 + 0x2880;
      iVar9 = param_1 + 0x28a0;
    }
    else {
      if (*(int *)(param_1 + 0x2680) != param_1 + 0x28e4) {
        *(int *)(param_1 + 0x2680) = param_1 + 0x28e4;
        *(int *)(param_1 + 0x2684) = param_1 + 0x2904;
        puVar6 = (undefined4 *)((int (*)())FUN_0002c0c0)(param_1,puVar6);
      }
      puVar3 = *(uint **)(param_1 + 0x1d8);
      iVar11 = param_1 + 0x2924;
      iVar9 = param_1 + 0x2944;
    }
    *puVar3 = (int)puVar6 - (int)puVar3 >> 2 | *puVar3;
    *(undefined4 **)(param_1 + 0x1d8) = puVar6;
    *puVar6 = 0x36000000;
    uVar4 = *(undefined4 *)(param_1 + 0x200);
    puVar6[2] = uVar2 & 0x1f;
    puVar6[3] = iVar10 - iVar8;
    puVar6[1] = uVar4;
    *(int *)(param_1 + 0x26d4) = iVar11;
    *(int *)(param_1 + 0x26d8) = iVar9;
    *(undefined4 *)(param_1 + 0x26d0) = *(undefined4 *)(param_1 + 0x283c);
    puVar7 = (undefined4 *)((int (*)())FUN_0002c180)(param_1,puVar6 + 4);
    uVar2 = *(uint *)(&DAT_001d9888 + param_3 * 4);
    *puVar7 = 0x82c;
    uVar4 = *(undefined4 *)(FUN_00001dc4 + param_1);
    puVar7[4] = ((unsigned char *)0x00001393);
    puVar7[2] = 0xc0003400;
    puVar7[5] = 0;
    puVar7[1] = uVar4;
    puVar7[3] = iVar5 << 0x10 | uVar2 & 0xf | 0x820;
    *(undefined4 **)(param_1 + 0x1dc) = puVar7 + 6;
  }
  return;
}

/* FUN_000273a0 @ 0x273a0 (1484 bytes) */
int FUN_000273a0(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  uint *param_3;
{
  byte bVar1;
  bool bVar2;
  undefined1 uVar4;
  undefined4 *puVar3;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  undefined4 *puVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  
  if (((unsigned char *)0x00002b80)[param_1] != '\0') {
    ((int (*)())FUN_0002be90)(param_1,1,param_2);
  }
  if (*(int *)(param_1 + 0x1b68) != 0) {
    ((int (*)())FUN_0002c020)(param_1 + 0x240,param_2);
  }
  if ((*param_3 == 0) || (*(int *)(*(int *)(param_1 + 0x14) + 0x120) == 0)) {
    bVar2 = false;
    uVar4 = 0;
    bVar1 = *(byte *)(*(int *)(((unsigned char *)0x000027cc) + param_1) + 2);
  }
  else {
    bVar2 = true;
    uVar4 = 1;
    bVar1 = *(byte *)(*(int *)(FUN_000027d0 + param_1) + 2);
  }
  uVar15 = (uint)bVar1;
  *(undefined1 *)(param_1 + 0x27d4) = uVar4;
  uVar5 = *(uint *)(param_1 + 0x27d8);
  if (!bVar2) {
    if ((uVar5 & 0x10) != 0) goto LAB_00027478;
LAB_00027458:
    uVar8 = 1;
  }
  else {
    if ((uVar5 & 8) == 0) goto LAB_00027458;
LAB_00027478:
    uVar8 = 2;
  }
  uVar14 = uVar8 | uVar5 & 0x18;
  if (uVar5 != uVar14) {
    *(int *)(param_1 + 0x2680) = param_1 + 0x26dc;
  }
  if ((uVar8 & 2) == 0) {
    if (*(char *)(param_1 + 0x27d4) == '\0') {
      if (*(int *)(param_1 + 0x2680) != param_1 + 0x2840) goto LAB_000276e0;
LAB_000276f8:
      iVar11 = 2;
      iVar10 = 4;
    }
    else {
      if (*(int *)(param_1 + 0x2680) == param_1 + 0x28e4) goto LAB_000276f8;
LAB_000276e0:
      uVar5 = *(int *)(param_1 + 0x267c) + 1U & 0xfffffffe;
      iVar10 = uVar5 + 8;
      iVar11 = uVar5 + 6;
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      iVar10 = iVar11 + 4;
    }
    if ((int)*param_3 < 0xc) {
      uVar5 = uVar15 * 0xc;
      uVar9 = 0xc;
    }
    else {
      uVar9 = ((int)*param_3 / 0xc) * 0xc;
      uVar5 = uVar15 * uVar9;
      if (0x3fff < uVar5) {
        uVar9 = ((0x3fff / uVar15) / 0xc) * 0xc;
        uVar5 = uVar15 * uVar9;
      }
    }
    puVar13 = *(undefined4 **)(param_1 + 0x1dc);
    if (*(undefined4 **)(param_1 + 0x1e0) <=
        puVar13 + uVar5 + iVar10 + 2 + (uint)(*(byte *)(param_1 + 8) >> 1) + 4) {
      FUN_0001a0f0(param_1,0x1000000);
      puVar13 = *(undefined4 **)(param_1 + 0x1dc);
    }
    uVar5 = (int)puVar13 + iVar10 * 4 + 0xf & 0xfffffff0;
    puVar3 = (undefined4 *)(uVar5 + iVar10 * -4);
    *(undefined4 **)(param_1 + 0x1dc) = puVar3;
    for (; puVar13 < puVar3; puVar13 = puVar13 + 1) {
      *puVar13 = 0x80000000;
    }
    if (*param_3 != 0) goto LAB_00027854;
    uVar7 = (((*(int *)(param_1 + 0x1e0) - *(int *)(param_1 + 0x1dc) >> 2) + -1) -
            (uint)(*(byte *)(param_1 + 8) >> 1)) - (iVar10 + 2);
    if (0x600 < uVar7) {
      uVar7 = 0x600;
    }
  }
  else {
    uVar5 = *param_3;
    uVar9 = 0x8b;
    if ((uVar5 != 0) && (uVar9 = 0x1000a, uVar5 < 0x10000)) {
      uVar9 = uVar5 + 0xb;
    }
    uVar7 = (uint)*(byte *)(param_1 + 8);
    iVar11 = 0xc;
    uVar9 = (uVar9 / 0xc) * 0xc;
    uVar16 = uVar15 * uVar9 + (uint)(*(byte *)(param_1 + 8) >> 1) + 0x20;
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      iVar11 = 10;
    }
    uVar17 = iVar11 + ((*(uint *)(param_1 + 0x283c) & 0x1f) + 1 >> 1) * 3 + 3;
    if (!bVar2) {
      if (*(int *)(param_1 + 0x2680) != param_1 + 0x2840) goto LAB_00027540;
    }
    else if (*(int *)(param_1 + 0x2680) != param_1 + 0x28e4) {
LAB_00027540:
      uVar17 = uVar17 + (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) + 4;
    }
    uVar5 = *(uint *)(param_1 + 0x1ec);
    if (uVar5 == 0) {
      uVar12 = *(uint *)(param_1 + 0x1dc);
      iVar10 = *(int *)(param_1 + 0x1e0);
      uVar5 = ((int)(iVar10 - uVar12) >> 2) - 1;
      if (uVar5 < uVar17 + uVar16) {
        if (*(int *)(param_1 + 0x1e4) + 0x28U < uVar12) {
          FUN_0001a0f0(param_1,0x1000000);
          uVar7 = (uint)*(byte *)(param_1 + 8);
          uVar12 = *(uint *)(param_1 + 0x1dc);
          iVar10 = *(int *)(param_1 + 0x1e0);
        }
        iVar11 = iVar10 - uVar12;
LAB_00027630:
        uVar5 = (iVar11 >> 2) - 1;
        if (uVar5 < uVar17 + uVar16) {
          uVar16 = uVar5 - uVar17;
        }
      }
      uVar6 = uVar5 >> 2;
      if (uVar5 >> 2 < uVar16) {
        uVar6 = uVar16;
      }
      uVar16 = uVar5 - uVar6;
      if (uVar5 - uVar6 < uVar17) {
        uVar16 = uVar17;
      }
      iVar11 = iVar10 + 0x94;
      *(int *)(param_1 + 0x1f0) = iVar11;
      uVar5 = uVar12 + uVar16 * 4 + 0x9f & 0xfffffff8;
      *(uint *)(param_1 + 0x1e0) = uVar5;
      uVar5 = uVar5 + 0x7f & 0xffffff80;
      *(uint *)(param_1 + 0x1ec) = uVar5;
    }
    else {
      uVar12 = *(uint *)(param_1 + 0x1dc);
      iVar10 = *(int *)(param_1 + 0x1e0);
      iVar11 = *(int *)(param_1 + 0x1f0);
      if ((((int)(iVar10 - uVar12) >> 2) - 1U < uVar17) ||
         ((uint)((int)(iVar11 - uVar5) >> 2) < uVar16)) {
        if (*(int *)(param_1 + 0x1e4) + 0x28U < uVar12) {
          FUN_0001a0f0(param_1,0x1000000);
          uVar7 = (uint)*(byte *)(param_1 + 8);
          uVar12 = *(uint *)(param_1 + 0x1dc);
          iVar10 = *(int *)(param_1 + 0x1e0);
        }
        iVar11 = iVar10 - uVar12;
        goto LAB_00027630;
      }
    }
    uVar7 = ((int)(iVar11 - uVar5) >> 2) - (uVar7 >> 1);
    if (uVar15 * uVar9 <= uVar7) goto LAB_00027854;
  }
  uVar9 = ((uVar7 / uVar15) / 0xc) * 0xc;
LAB_00027854:
  *param_3 = uVar9;
  uVar7 = (uint)*(byte *)(param_1 + 8);
  if (uVar7 != 0x20) {
    if ((*(uint *)(param_1 + 0x27d8) & 1) == 0) {
      uVar16 = *(uint *)(param_1 + 0x2838);
    }
    else {
      uVar16 = *(uint *)(param_1 + 0x2834);
    }
    uVar17 = uVar16;
    if (uVar16 <= uVar5) {
      uVar17 = (uVar5 + uVar7) - 1 & -uVar7;
    }
    uVar15 = uVar5 + uVar15 * uVar9 * 4;
    if (uVar16 <= uVar15) {
      uVar16 = (uVar15 + uVar7) - 1 & -uVar7;
    }
    if (uVar17 < uVar16) {
      uVar9 = uVar16 - uVar17;
      for (uVar15 = uVar9 >> 9; uVar15 != 0; uVar15 = uVar15 - 1) {
        dataCacheBlockClearToZero(uVar17);
        dataCacheBlockClearToZero(uVar17 + uVar7);
        dataCacheBlockClearToZero(uVar17 + uVar7 * 2);
        dataCacheBlockClearToZero(uVar17 + uVar7 * 3);
        uVar17 = uVar17 + 0x200;
      }
      for (uVar15 = uVar9 >> 7 & 3; uVar15 != 0; uVar15 = uVar15 - 1) {
        dataCacheBlockClearToZero(uVar17);
        uVar17 = uVar17 + 0x80;
      }
      if ((uVar8 & 1) == 0) {
        *(uint *)(param_1 + 0x2838) = uVar16;
      }
      else {
        *(uint *)(param_1 + 0x2834) = uVar16;
      }
    }
  }
  *(uint *)(param_1 + 0x27d8) = uVar14;
  return uVar5;
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
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint *puVar17;
  uint uVar18;
  ushort uVar19;
  uint uVar20;
  undefined1 *puVar21;
  undefined1 *puVar22;
  int iVar23;
  uint uVar24;
  int iVar25;
  int iVar26;
  int iVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  int iVar31;
  int iVar32;
  uint uVar33;
  int local_74;
  uint local_70;
  int local_68;
  int local_64;
  int local_60;
  
  *(int *)(param_1 + 0x2440) = param_1 + 0x249c;
  *(int *)(param_1 + 0x2444) = param_1 + 0x24bc;
  *(undefined4 *)(param_1 + 0x2494) = 0;
  iVar31 = *(int *)(param_1 + 4);
  uVar29 = *(uint *)(param_1 + 0x243c);
  if ((((*(char *)(iVar31 + 0x20) == '\0') ||
       (*(int *)(((unsigned char *)0x00003170) + *(int *)(iVar31 + 0x10)) != 0x1b021b02)) || (uVar29 < 2)) ||
     (0x10 < uVar29)) {
    if ((*(int *)(*(int *)(iVar31 + 0x14) + 0x11c) == 0) &&
       (*(int *)(*(int *)(iVar31 + 0x14) + 0x120) == 0)) {
      return;
    }
switchD_00027e30_default:
    *(uint *)(param_1 + 0x2488) = *(uint *)(param_1 + 0x2488) | 2;
    *(undefined4 *)(*(int *)(iVar31 + 0x14) + 0x11c) = 0;
    *(undefined4 *)(*(int *)(iVar31 + 0x14) + 0x120) = 0;
    return;
  }
  if (*(int **)(iVar31 + 0x1cc) == (int *)0x0) {
    iVar27 = 0;
    local_68 = 0;
    local_64 = 0;
    local_60 = 0;
  }
  else {
    local_64 = *(int *)(**(int **)(iVar31 + 0x1cc) + 4);
    iVar27 = *(int *)(iVar31 + 0x29e8) + 0x14;
    local_60 = *(int *)(*(int *)(iVar31 + 0x29e8) + 0x34);
    local_68 = *(int *)(local_64 + 0x24);
  }
  puVar22 = *(undefined1 **)(param_1 + 0x258c);
  iVar7 = **(int **)(*(int *)(iVar31 + 0x18) + 0x194);
  *(undefined1 **)(*(int *)(iVar31 + 0x14) + 0x11c) = puVar22;
  puVar21 = *(undefined1 **)(param_1 + 0x2590);
  *(undefined1 **)(*(int *)(iVar31 + 0x14) + 0x120) = puVar21;
  if (*(char *)(param_1 + 0x2595) != '\0') {
    *(undefined4 *)(*(int *)(iVar31 + 0x14) + 0x120) = 0;
  }
  *(uint *)(param_1 + 0x2488) = *(uint *)(param_1 + 0x2488) | 2;
  iVar14 = param_1;
  for (uVar33 = uVar29 + 1 >> 1; uVar33 != 0; uVar33 = uVar33 - 1) {
    *(undefined4 *)(iVar14 + 0x26a4) = *(undefined4 *)(iVar14 + 0x1be4);
    *(undefined4 *)(iVar14 + 0x26c4) = *(undefined4 *)(iVar14 + 0x1c04);
    *(undefined4 *)(iVar14 + 0x2600) = *(undefined4 *)(iVar14 + 0x1be4);
    *(undefined4 *)(iVar14 + 0x2620) = *(undefined4 *)(iVar14 + 0x1c04);
    iVar14 = iVar14 + 4;
  }
  *(undefined4 *)(param_1 + 0x26a0) = *(undefined4 *)(param_1 + 0x1ca4);
  *(uint *)(param_1 + 0x25fc) = uVar29 & 0x1f | 0x20;
  if (*(int *)(iVar31 + 0x1cc) == 0) {
    iVar14 = *(int *)(param_1 + 4);
  }
  else {
    iVar14 = *(int *)(param_1 + 4);
    uVar33 = 0;
    iVar16 = 0;
    iVar10 = 0x16;
    bVar1 = *(int *)(iVar14 + 0x1cc) == 0;
    do {
      if (bVar1) {
        if ((1 << (uVar33 & 0x3f) & *(uint *)(param_1 + 0x1ca0)) != 0) goto LAB_00027b90;
      }
      else if ((*(int *)(iVar16 + *(int *)(iVar27 + 0x20)) != 0x80) ||
              (*(uint *)(iVar27 + 0x1c) <= uVar33)) {
LAB_00027b90:
        if (bVar1) {
          iVar32 = *(int *)(iVar16 + 0x1d9e58);
        }
        else {
          if (*(uint *)(iVar27 + 0x1c) <= uVar33) goto switchD_00027c3c_default;
          iVar32 = (local_68 + *(int *)(local_60 + iVar16)) * 8;
          uVar24 = *(uint *)(local_64 + iVar32);
          puVar17 = (uint *)(local_64 + iVar32);
          iVar32 = *(int *)(&DAT_001d9eb0 + (uVar24 >> 0xe & 0x3c));
          if (iVar32 == 8) {
            iVar32 = (uVar24 & 0x1f) + 8;
          }
          else if (iVar32 == 0x10) {
            iVar32 = (uVar24 & 0x1f) + 0x10;
          }
          else if (iVar32 == 0x2f) {
            switch(uVar24 >> 0xc & 0xf) {
            case 0:
              iVar32 = (*puVar17 & 1) + 0x20;
              break;
            case 1:
              iVar32 = (*puVar17 & 1) + 0x22;
              break;
            case 2:
              iVar32 = (*puVar17 & 1) + 0x24;
              break;
            case 3:
              iVar32 = (*puVar17 & 1) + 0x26;
              break;
            case 4:
              iVar32 = (*puVar17 & 1) + 0x28;
              break;
            default:
              goto switchD_00027c3c_default;
            }
          }
        }
        if ((iVar32 == 0) || (iVar32 == 0x10)) {
          bVar1 = true;
          goto LAB_00027d04;
        }
      }
switchD_00027c3c_default:
      iVar10 = iVar10 + -1;
      uVar33 = uVar33 + 1;
      iVar16 = iVar16 + 4;
    } while (iVar10 != 0);
  }
  bVar1 = false;
LAB_00027d04:
  iVar25 = 0;
  local_70 = 0;
  uVar33 = 0;
  iVar23 = 0;
  local_74 = 1;
  iVar32 = 0x16;
  uVar24 = 0;
  iVar10 = 0;
  uVar30 = 0;
  iVar26 = 0;
  iVar16 = param_1;
LAB_00027d44:
  bVar2 = *(int *)(iVar14 + 0x1cc) == 0;
  if (bVar2) {
    if ((1 << (uVar24 & 0x3f) & *(uint *)(param_1 + 0x1ca0)) != 0) goto LAB_00027d90;
    goto LAB_00028214;
  }
  if ((*(int *)(iVar26 + *(int *)(iVar27 + 0x20)) == 0x80) && (uVar24 < *(uint *)(iVar27 + 0x1c)))
  goto LAB_00028214;
LAB_00027d90:
  if (bVar2) {
    uVar12 = *(uint *)(iVar26 + 0x1d9e58);
LAB_00027eac:
    if (uVar12 == 0x30) goto switchD_00027e30_default;
    uVar20 = uVar12 & 0xffff;
  }
  else {
    if (uVar24 < *(uint *)(iVar27 + 0x1c)) {
      iVar14 = (local_68 + *(int *)(local_60 + iVar26)) * 8;
      uVar20 = *(uint *)(local_64 + iVar14);
      puVar17 = (uint *)(local_64 + iVar14);
      uVar12 = *(uint *)(&DAT_001d9eb0 + (uVar20 >> 0xe & 0x3c));
      if (uVar12 == 8) {
        uVar12 = (uVar20 & 0x1f) + 8;
      }
      else if (uVar12 == 0x10) {
        uVar12 = (uVar20 & 0x1f) + 0x10;
      }
      else if (uVar12 == 0x2f) {
        switch(uVar20 >> 0xc & 0xf) {
        case 0:
          uVar12 = (*puVar17 & 1) + 0x20;
          break;
        case 1:
          uVar12 = (*puVar17 & 1) + 0x22;
          break;
        case 2:
          uVar12 = (*puVar17 & 1) + 0x24;
          break;
        case 3:
          uVar12 = (*puVar17 & 1) + 0x26;
          break;
        case 4:
          uVar12 = (*puVar17 & 1) + 0x28;
          break;
        default:
          goto switchD_00027e30_default;
        }
      }
      goto LAB_00027eac;
    }
    uVar12 = 2;
    uVar20 = 2;
  }
  if ((bVar1) && ((uVar12 == 0 || (iVar10 = local_74, uVar12 == 0x10)))) {
    iVar10 = 0;
  }
  uVar8 = uVar30 >> 1;
  if (bVar2) {
    uVar18 = *(uint *)(iVar26 + 0x1d9edc) & 0xffff;
  }
  else {
    uVar18 = 3;
  }
  bVar2 = (uVar30 & 1) == 0;
  if (bVar2) {
    iVar14 = uVar8 * 4 + param_1;
    *(uint *)(iVar14 + 0x2640) = (uVar29 & 0x1f) << 10 | *(uint *)(iVar14 + 0x2640) & 0xffff8080 | 4
    ;
  }
  else {
    iVar14 = uVar8 * 4 + param_1;
    *(uint *)(iVar14 + 0x2640) =
         (uVar29 & 0x1f) << 0x1a | *(uint *)(iVar14 + 0x2640) & 0x8080ffff | 0x40000;
  }
  iVar14 = uVar8 * 4;
  uVar6 = (ushort)(uVar20 << 10);
  uVar19 = (ushort)(uVar18 << 8) | uVar6;
  *(int *)(uVar30 * 4 + param_1 + 0x2660) = iVar25;
  *(ushort *)(puVar22 + iVar10 * 2 + 4) = uVar19 | (ushort)iVar25;
  if (*(char *)(param_1 + 0x2595) == '\0') {
    uVar3 = *(ushort *)(uVar12 * 0x18 + iVar7 + 8);
    if (uVar12 < 0x10) {
      uVar33 = *(uint *)(iVar7 + 0x304);
    }
    else {
      uVar33 = *(uint *)(iVar7 + 0x300);
    }
    if ((uVar33 & *(uint *)(&DAT_001d9dd8 + uVar12 * 4)) == 0) {
      uVar33 = 4;
      uVar15 = 4;
      uVar20 = 3;
      uVar18 = 0;
      uVar12 = 0;
      uVar9 = 0;
      uVar11 = 1;
      uVar13 = 2;
      uVar28 = 3;
      uVar8 = 0;
    }
    else {
      iVar4 = ((uVar3 & 0xffff7fff) - 0x1400) * 4;
      iVar5 = (iVar4 + *(short *)(uVar12 * 0x18 + iVar7 + 10) + -1) * 4;
      uVar33 = *(uint *)(&DAT_001d9c4c + iVar5);
      uVar19 = (ushort)(*(int *)(&DAT_001d9cfc + iVar5) << 8) | uVar6;
      uVar12 = (uint)(uVar3 >> 0xf);
      uVar20 = *(uint *)(&DAT_001d9b9c + iVar5) & 0xff;
      uVar8 = *(uint *)(&DAT_001d9dac + iVar4) & 0xffff;
      uVar18 = *(uint *)(&DAT_001d9b70 + iVar4) & 0xff;
      uVar9 = *(uint *)(&DAT_001d9ac0 + iVar5) & 0xff;
      uVar15 = uVar33 & 0xff;
      uVar11 = *(uint *)(&DAT_001d9a10 + iVar5) & 0xff;
      uVar13 = *(uint *)(&DAT_001d9960 + iVar5) & 0xff;
      uVar28 = *(uint *)(&DAT_001d98b0 + iVar5) & 0xff;
    }
    if (bVar2) {
      *(uint *)(iVar14 + param_1 + 0x26e4) =
           uVar15 & 0x7f | *(uint *)(iVar14 + param_1 + 0x26e4) & 0xffffff80;
    }
    else {
      *(uint *)(iVar14 + param_1 + 0x26e4) =
           (uVar15 & 0x7f) << 0x10 | *(uint *)(iVar14 + param_1 + 0x26e4) & 0xff80ffff;
    }
    *(int *)(uVar30 * 4 + param_1 + 0x2704) = iVar23;
    if (bVar2) {
      iVar14 = iVar14 + param_1;
      *(uint *)(iVar14 + 0x26a4) =
           uVar12 << 0xf |
           (uVar18 & 1) << 0xe | uVar20 & 0xf | *(uint *)(iVar14 + 0x26a4) & 0xffff3ff0;
      *(uint *)(iVar14 + 0x26c4) =
           (uVar28 & 7) << 9 |
           (uVar13 & 7) << 6 |
           (uVar11 & 7) << 3 | uVar9 & 7 | *(uint *)(iVar14 + 0x26c4) & 0xfffff000;
    }
    else {
      iVar14 = iVar14 + param_1;
      *(uint *)(iVar14 + 0x26a4) =
           uVar12 << 0x1f |
           (uVar18 & 1) << 0x1e | (uVar20 & 0xf) << 0x10 | *(uint *)(iVar14 + 0x26a4) & 0x3ff0ffff;
      *(uint *)(iVar14 + 0x26c4) =
           (uVar28 & 7) << 0x19 |
           (uVar13 & 7) << 0x16 |
           (uVar11 & 7) << 0x13 | (uVar9 & 7) << 0x10 | *(uint *)(iVar14 + 0x26c4) & 0xf000ffff;
    }
    *(ushort *)(puVar21 + iVar10 * 2 + 4) = uVar19 | (ushort)(uVar8 << 6) | (ushort)iVar23;
  }
  *(uint *)(iVar16 + 0x259c) = uVar30;
  iVar25 = iVar25 + 4;
  iVar23 = iVar23 + uVar33;
  uVar30 = uVar30 + 1;
  local_70 = local_70 + uVar33;
  if (!bVar1) {
    iVar10 = iVar10 + 1;
  }
  else if (iVar10 != 0) {
    local_74 = local_74 + 1;
  }
LAB_00028214:
  if (uVar30 == uVar29) {
LAB_00028238:
    if (*(char *)(param_1 + 0x2595) == '\0') {
      uVar24 = 0;
      bVar1 = false;
      *(uint *)(param_1 + 0x2744) = local_70 & 0x7f | *(uint *)(param_1 + 0x2744) & 0xffffff80;
      uVar33 = uVar29;
      do {
        if (bVar1) {
          iVar27 = (uVar24 & 0x7ffffffe) * 2 + param_1;
          *(uint *)(iVar27 + 0x26e4) =
               (local_70 & 0x7f) << 0x18 | *(uint *)(iVar27 + 0x26e4) & 0x80ffffff;
        }
        else {
          iVar27 = (uVar24 & 0x7ffffffe) * 2 + param_1;
          *(uint *)(iVar27 + 0x26e4) =
               (local_70 & 0x7f) << 8 | *(uint *)(iVar27 + 0x26e4) & 0xffff80ff;
        }
        uVar24 = uVar24 + 1;
        bVar1 = (bool)(bVar1 ^ 1);
        uVar33 = uVar33 - 1;
      } while (uVar33 != 0);
    }
    *puVar22 = (char)uVar29;
    *puVar21 = (char)uVar29;
    puVar22[1] = 0;
    puVar21[1] = 0;
    puVar22[2] = (char)(uVar29 << 2);
    puVar21[2] = (char)local_70;
    if (*(char *)(iVar31 + 8) == ' ') {
      uVar33 = 0x20;
      if (7 < uVar29 << 2) {
        puVar22[1] = puVar22[1] | 0x40;
        uVar33 = (uint)*(byte *)(iVar31 + 8);
      }
      if (uVar33 >> 2 <= local_70) {
        puVar21[1] = puVar21[1] | 0x40;
      }
    }
    *(uint *)(param_1 + 0x2598) = *(uint *)(param_1 + 0x2598) & 0xffffffe7;
    return;
  }
  uVar24 = uVar24 + 1;
  iVar26 = iVar26 + 4;
  iVar16 = iVar16 + 4;
  iVar32 = iVar32 + -1;
  if (iVar32 == 0) goto LAB_00028238;
  iVar14 = *(int *)(param_1 + 4);
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
  undefined4 local_b8;
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
  local_b8 = 0x43300000;
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
  puVar29[0xd6] = (*(unsigned char *)0x000010ea);
  uVar27 = *(undefined4 *)(param_1 + 0x1cfc);
  puVar29[0xd8] = ((unsigned char *)0x000010fa);
  puVar29[0xd7] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1da0);
  puVar29[0xda] = 0xc0001000;
  puVar29[0xdc] = 0x11004;
  puVar29[0xd9] = uVar27;
  puVar29[0xdd] = *(undefined4 *)(param_1 + 0x1ca8);
  uVar27 = *(undefined4 *)(param_1 + 0x1cac);
  puVar29[0xdf] = ((unsigned char *)0x00001008);
  puVar29[0xde] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1ca0);
  puVar29[0xe1] = (*(unsigned char *)0x000010e9);
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
  uVar27 = *(undefined4 *)(param_1 + 0x1dc0);
  puVar29[0xe9] = 0x887;
  puVar29[0xe8] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1db4);
  puVar29[0x18b] = 0x82c;
  puVar29[0xea] = uVar27;
  uVar27 = *(undefined4 *)(FUN_00001dc4 + param_1);
  puVar29[0xeb] = ((unsigned char *)0x000010ae);
  puVar29[0x18c] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1d70);
  puVar29[0xed] = ((unsigned char *)0x00001394);
  puVar29[0xec] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1d30);
  puVar29[0xef] = ((unsigned char *)0x00001380);
  puVar29[0xf1] = ((unsigned char *)0x00001002);
  puVar29[0xf0] = 0;
  puVar29[0xee] = uVar27;
  puVar29[0xf2] = *(undefined4 *)(param_1 + 0x1d90);
  uVar27 = *(undefined4 *)(param_1 + 0x1d90);
  puVar29[0xf3] = 0x824;
  puVar29[0xf2] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1ddc);
  puVar29[0xf5] = 0x825;
  puVar29[0xf4] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1de0);
  puVar29[0xf7] = 0x82d;
  puVar29[0xf6] = uVar27;
  uVar27 = *(undefined4 *)(FUN_000026c8 + param_1 + 4);
  puVar29[0xf9] = 0x854;
  puVar29[0xf8] = uVar27;
  uVar27 = **(undefined4 **)(param_1 + 0x2680);
  puVar29[0xfb] = 0x878;
  puVar29[0xfa] = uVar27;
  uVar27 = **(undefined4 **)(param_1 + 0x2684);
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
  uVar27 = *(undefined4 *)(param_1 + 0x1d7c);
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
  uVar27 = *(undefined4 *)(param_1 + 0x1d6c);
  puVar29[0x109] = ((unsigned char *)0x00001096);
  puVar29[0x108] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1df8);
  puVar29[0x10b] = ((unsigned char *)0x00001041);
  puVar29[0x108] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x29f0);
  puVar29[0x10d] = ((unsigned char *)0x00001046);
  puVar29[0x10c] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x1dfc);
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
  uVar27 = *(undefined4 *)(param_1 + 0x216c);
  puVar29[0x163] = ((unsigned char *)0x000010c1);
  puVar29[0x165] = ((unsigned char *)0x000010c8);
  puVar29[0x167] = ((unsigned char *)0x0000101d);
  puVar29[0x162] = uVar27;
  uVar27 = *(undefined4 *)(param_1 + 0x2128);
  puVar29[0x169] = ((unsigned char *)0x0000138a);
  puVar29[0x16b] = ((unsigned char *)0x0000138e);
  puVar29[0x170] = 0;
  puVar29[0x16d] = ((unsigned char *)0x00001040);
  puVar29[0x16a] = 0;
  puVar29[0x16c] = 0;
  puVar29[0x16e] = 0;
  puVar29[0x168] = uVar27;
  puVar29[0x16f] = (*(unsigned char *)0x00001150);
  puVar29[0x171] = ((unsigned char *)0x00001100);
  uVar27 = *(undefined4 *)(param_1 + 0x1f1c);
  puVar29[0x173] = ((unsigned char *)0x00001110);
  puVar29[0x172] = uVar27;
  puVar29[0x174] = *(undefined4 *)(param_1 + 0x1f5c);
  puVar29[0x175] = (*(unsigned char *)0x00001120);
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
  puVar29[0x182] = *(undefined4 *)(param_1 + 0x1d98);
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

/* FUN_00029290 @ 0x29290 (4 bytes) */
int FUN_00029290(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  void *pvVar10;
  undefined4 *puVar11;
  uint uVar12;
  undefined *puVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int *piVar17;
  int *piVar18;
  char in_stack_0000003b;
  int in_stack_0000003c;
  uint uStack_e8;
  int iStack_e4;
  int aiStack_e0 [3];
  int iStack_d4;
  int iStack_d0;
  int iStack_cc;
  int iStack_c8;
  uint uStack_c4;
  uint uStack_c0;
  uint uStack_bc;
  uint uStack_b8;
  uint uStack_b4;
  uint uStack_b0;
  uint uStack_ac;
  uint uStack_a8;
  undefined1 auStack_a4 [4];
  undefined1 auStack_a0 [4];
  undefined4 uStack_9c;
  uint uStack_98;
  undefined *puStack_94;
  int iStack_90;
  int iStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  uint uStack_80;
  uint uStack_7c;
  uint uStack_78;
  undefined4 uStack_74;
  uint uStack_70;
  uint uStack_6c;
  uint uStack_68;
  undefined4 uStack_64;
  uint uStack_60;
  uint uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  undefined1 uStack_50;
  
  iVar14 = param_1 + 0x240;
  uStack_84 = 0;
  aiStack_e0[1] = 0;
  uStack_88 = 0;
  iVar15 = *(int *)(param_1 + 0x10);
  iVar8 = FUN_0000a2f0(*(undefined2 *)(((unsigned char *)0x00002db8) + iVar15),*(undefined4 *)(param_1 + 0x154));
  if (((((*(uint *)(((unsigned char *)0x000030b0) + iVar15) & 0x1ff) == 0) &&
       ((*(uint *)(((unsigned char *)0x000030b4) + iVar15) & 0xff0000) == 0)) || (param_6 - 0x1901U < 2)) ||
     (in_stack_0000003b == '\x02')) {
    iVar7 = 0;
    bVar6 = false;
  }
  else if ((*(uint *)(((unsigned char *)0x000030b0) + iVar15) & 2) == 0) {
    if (((*(uint *)(((unsigned char *)0x000030b0) + iVar15) & 4) == 0) ||
       (*(short *)(((unsigned char *)0x00002fe8) + iVar15) != -0x7fea)) goto LAB_000293b0;
    bVar6 = true;
    iVar7 = *(int *)(((unsigned char *)0x00002ff0) + iVar15) + -1;
  }
  else if (*(short *)(((unsigned char *)0x00002fa8) + iVar15) == -0x7fea) {
    bVar6 = true;
    iVar7 = *(int *)(((unsigned char *)0x00002fb0) + iVar15) + -1;
  }
  else {
LAB_000293b0:
    iVar7 = 0;
    bVar6 = true;
  }
  if (in_stack_0000003c == 0) {
    bVar1 = in_stack_0000003b != '\x02';
    FUN_0000a6e0(param_1,param_6,param_7,param_4 - iVar7,param_5,&uStack_e8,&iStack_e4,aiStack_e0);
    uStack_ac = param_8 + aiStack_e0[0];
    if (param_3 < 0) {
      param_5 = param_5 + param_3;
      iVar7 = param_3 * uStack_e8;
      param_3 = 0;
      uStack_ac = uStack_ac - iVar7;
    }
    if (param_2 < 0) {
      param_4 = param_4 + param_2;
      iStack_e4 = param_2 * iStack_e4;
      param_2 = 0;
      uStack_ac = uStack_ac - iStack_e4;
    }
    if (*(int *)(param_1 + 0x160) < param_3 + param_5) {
      param_5 = *(int *)(param_1 + 0x160) - param_3;
    }
    if (*(int *)(param_1 + 0x15c) < param_2 + param_4) {
      param_4 = *(int *)(param_1 + 0x15c) - param_2;
    }
    if ((0 < param_4) && (0 < param_5)) {
      if (bVar1) {
        if (in_stack_0000003b == '\0') {
          uStack_98 = 0x20000;
        }
        else {
          uStack_98 = 0;
        }
        puVar13 = ((unsigned char *)0x00002e48) + iVar15;
        puStack_94 = ((unsigned char *)0x0007efff);
        if (((unsigned char *)0x00002e68)[iVar15] != '\0') {
          uStack_98 = uStack_98 | 2;
        }
        if (((unsigned char *)0x00002e69)[iVar15] != '\0') {
          uStack_98 = uStack_98 | 8;
        }
      }
      else {
        puVar13 = (undefined *)0x0;
        puStack_94 = (undefined *)0x0;
        uStack_98 = 0;
      }
      uStack_50 = 0;
      uStack_9c = 2;
      uStack_a8 = uStack_e8;
      iStack_90 = param_4;
      iStack_8c = param_5;
      _glgConvertType(param_6,param_7,auStack_a4,auStack_a0);
      piVar17 = *(int **)(param_1 + 0x150);
      if (piVar17 == (int *)0x0) {
        aiStack_e0[2] = param_2;
        iStack_d4 = param_3;
        iStack_d0 = param_4;
        iStack_cc = param_5;
        if (param_6 == 0x1901) {
          uVar12 = *(uint *)(param_1 + 0x154);
          if ((uVar12 & 0x30000) == 0x30000) {
            if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
              FUN_0001a0f0(param_1,0x1000000);
              uVar12 = *(uint *)(param_1 + 0x154);
            }
            uStack_b8 = (param_4 + 0xf) * 4 & 0xffffffc0;
            uStack_b0 = 0x14;
            uStack_b4 = 0xf;
            if ((uVar12 & 0x2000) == 0) {
LAB_000298a4:
              iStack_c8 = 4;
            }
            else {
LAB_00029878:
              if (iVar8 == 7) {
                iStack_c8 = 10;
              }
              else {
                if (iVar8 != 8) goto LAB_000298a4;
                iStack_c8 = 0xb;
              }
            }
LAB_000299f8:
            if ((bVar6) ||
               ((((bVar1 && (((*(uint *)(((unsigned char *)0x000030b4) + iVar15) & 0xff1) != 0 ||
                             ((*(uint *)((*(unsigned char *)0x00002e68) + iVar15) & 0xffff0000) != 0)))) ||
                 (param_6 - 0x1901U < 2)) ||
                ((((uStack_a8 & 0x3f) != 0 || (0x1fff < (int)uStack_a8)) ||
                 ((uStack_ac & 0x1f) != 0)))))) {
LAB_00029a74:
              uStack_c0 = uStack_b8;
              uVar12 = param_5 * uStack_b8 + 0xfff & 0xfffff000;
              if (*(uint *)(((unsigned char *)0x00002b78) + param_1) < uVar12) {
                if (*(int *)(((unsigned char *)0x00002b74) + param_1) != 0) {
                  _vfree();
                }
                pvVar10 = _valloc(uVar12);
                *(uint *)(((unsigned char *)0x00002b78) + param_1) = uVar12;
                *(void **)(((unsigned char *)0x00002b74) + param_1) = pvVar10;
              }
              uStack_c4 = *(uint *)(((unsigned char *)0x00002b74) + param_1);
              if (uStack_c4 == 0) goto LAB_00029bd0;
              bVar1 = false;
            }
            else {
              if ((uVar12 & 0xf) == 4) {
                if ((param_6 != 0x80e1) || (param_7 != 0x8367)) goto LAB_00029a74;
              }
              else if ((((uVar12 & 0xf) != 3) || (param_6 != 0x80e1)) || (param_7 != 0x8366))
              goto LAB_00029a74;
              bVar1 = true;
              uStack_c0 = uStack_a8;
              uStack_c4 = uStack_ac;
            }
            uStack_bc = uStack_c4;
            if (bVar6) {
              iVar14 = *(int *)(param_1 + 0x18);
              iVar8 = *(int *)(*(int *)(iVar14 + 0x140) + 0x30);
              uStack_80 = (uint)*(ushort *)(iVar8 + 0x98);
              uStack_7c = (uint)*(ushort *)(iVar8 + 0x9a);
              uStack_78 = (uint)*(ushort *)(iVar8 + 0x8c);
              uStack_74 = *(undefined4 *)(iVar8 + 0x9c);
              iVar8 = *(int *)(*(int *)(iVar14 + 0x148) + 0x30);
              uStack_70 = (uint)*(ushort *)(iVar8 + 0x98);
              uStack_6c = (uint)*(ushort *)(iVar8 + 0x9a);
              uStack_68 = (uint)*(ushort *)(iVar8 + 0x8c);
              uStack_64 = *(undefined4 *)(iVar8 + 0x9c);
              iVar8 = *(int *)(*(int *)(iVar14 + 0x144) + 0x30);
              uStack_60 = (uint)*(ushort *)(iVar8 + 0x98);
              uStack_5c = (uint)*(ushort *)(iVar8 + 0x9a);
              uStack_58 = (uint)*(ushort *)(iVar8 + 0x8c);
              uStack_54 = *(undefined4 *)(iVar8 + 0x9c);
            }
            iVar8 = _io_connect_method_structureI_structureO
                              (*(undefined4 *)(param_1 + 4),7,aiStack_e0 + 2,0x1c,0,aiStack_e0 + 1);
            if (iVar8 != 0) goto LAB_00029bd0;
            if (!bVar1) {
              _glgProcessPixels(puVar13,&uStack_bc);
              return 1;
            }
          }
        }
        else {
          if (param_6 != 0x1902) {
            iVar7 = FUN_0001a010(param_1,iVar8);
            if (iVar7 != 0) {
              FUN_000230d0(param_1,0,iVar8,0,0,0,*(undefined4 *)(param_1 + 0x15c),
                           *(undefined4 *)(param_1 + 0x160));
            }
            if (*(int *)(param_1 + 0x1d38) != 0) {
              puVar11 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar14,2);
              puVar11[1] = 0;
              *puVar11 = ((unsigned char *)0x00001386);
              *(undefined4 **)(param_1 + 0x298c) = puVar11 + 2;
              (**(code **)(param_1 + 0x299c))(iVar14);
            }
            if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
              FUN_0001a0f0(param_1,0x1000000);
            }
            if (*(int *)(param_1 + 0x1d38) != 0) {
              puVar11 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar14,2);
              *puVar11 = ((unsigned char *)0x00001386);
              puVar11[1] = *(undefined4 *)(param_1 + 0x1d38);
              *(undefined4 **)(param_1 + 0x298c) = puVar11 + 2;
              (**(code **)(param_1 + 0x299c))(iVar14,puVar11 + 2);
            }
            bVar2 = ((unsigned char *)0x00002b7f)[param_1];
            uVar12 = *(uint *)(param_1 + 0x154);
            uStack_b8 = (param_4 << (*(uint *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x14) & 7)) +
                        0x1fU & 0xffffffe0;
            uStack_b0 = *(uint *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x10) >> 0x16 & 0x1f;
            uStack_b4 = *(uint *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x10) >> 0x1b;
            iStack_c8 = iVar8;
            goto LAB_000299f8;
          }
          uVar12 = *(uint *)(param_1 + 0x154);
          if ((uVar12 & 0x30000) != 0) {
            if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
              FUN_0001a0f0(param_1,0x1000000);
              uVar12 = *(uint *)(param_1 + 0x154);
            }
            if ((uVar12 & 0x20000) == 0) {
              uStack_b0 = 2;
              uStack_b8 = (param_4 + 0x1f) * 2 & 0xffffffc0;
              uStack_b4 = 0xd;
            }
            else {
              uStack_b8 = (param_4 + 0xf) * 4 & 0xffffffc0;
              if ((uVar12 & 0x30000) == 0x30000) {
                uStack_b4 = 0xf;
                uStack_b0 = 0x14;
              }
              else {
                uStack_b4 = 0xd;
                uStack_b0 = 4;
              }
            }
            if ((uVar12 & 0x2000) != 0) goto LAB_00029878;
            goto LAB_000298a4;
          }
        }
      }
      else {
        iVar8 = 5;
        if ((param_6 != 0x1901) && (iVar8 = 4, param_6 != 0x1902)) {
          uStack_98 = uStack_98 | 0x60000;
          puStack_94 = (undefined *)((uint)puStack_94 | 0x68002);
          iVar8 = *(ushort *)(*piVar17 + 0x98) - 0x8ce0;
          if ((bVar1) &&
             (((*(uint *)(puVar13 + 0x268) & 0x1ff) != 0 ||
              ((*(uint *)(puVar13 + 0x26c) & 0xff0000) != 0)))) {
            iVar15 = *(int *)(param_1 + 0x18);
            iVar14 = *(int *)(*(int *)(iVar15 + 0x140) + 0x30);
            uStack_80 = (uint)*(ushort *)(iVar14 + 0x98);
            uStack_7c = (uint)*(ushort *)(iVar14 + 0x9a);
            uStack_78 = (uint)*(ushort *)(iVar14 + 0x8c);
            uStack_74 = *(undefined4 *)(iVar14 + 0x9c);
            iVar14 = *(int *)(*(int *)(iVar15 + 0x148) + 0x30);
            uStack_70 = (uint)*(ushort *)(iVar14 + 0x98);
            uStack_6c = (uint)*(ushort *)(iVar14 + 0x9a);
            uStack_68 = (uint)*(ushort *)(iVar14 + 0x8c);
            uStack_64 = *(undefined4 *)(iVar14 + 0x9c);
            iVar14 = *(int *)(*(int *)(iVar15 + 0x144) + 0x30);
            uStack_60 = (uint)*(ushort *)(iVar14 + 0x98);
            uStack_5c = (uint)*(ushort *)(iVar14 + 0x9a);
            uStack_58 = (uint)*(ushort *)(iVar14 + 0x8c);
            uStack_54 = *(undefined4 *)(iVar14 + 0x9c);
          }
        }
        piVar18 = *(int **)(piVar17[1] + iVar8 * 4);
        if (piVar18 != (int *)0x0) {
          iVar8 = iVar8 * 0x18 + *piVar17;
          uVar3 = *(ushort *)(*piVar18 + 0x18);
          iVar15 = *(int *)(iVar8 + 4);
          iVar14 = *(int *)(iVar8 + 8);
          iVar16 = *(int *)(iVar8 + 0xc);
          iVar8 = iVar14 * 0x18 + iVar15 * 0x168 + piVar18[0xc];
          uVar4 = *(undefined2 *)(iVar8 + 0xb2);
          uVar5 = *(undefined2 *)(iVar8 + 0xb0);
          _glgConvertType(uVar5,uVar4,&uStack_b4,&uStack_b0);
          iVar7 = *(int *)(param_1 + 0x15c);
          iVar8 = FUN_0000a3f0(uVar5,uVar4);
          uStack_b8 = iVar7 * iVar8;
          iVar7 = uStack_b8 * *(int *)(param_1 + 0x160);
          pvVar10 = _valloc((uint)uVar3 * iVar7);
          FUN_00031340(param_1,piVar18,iVar15,iVar14,uVar5,uVar4,pvVar10,uStack_b8);
          param_3 = param_3 * uStack_b8;
          iVar8 = FUN_0000a3f0(uVar5,uVar4);
          uStack_bc = (int)pvVar10 + param_2 * iVar8 + iVar16 * iVar7 + param_3;
          _glgProcessPixels(puVar13,&uStack_bc);
          _vfree(pvVar10);
          return 1;
        }
      }
    }
    uVar9 = 1;
  }
  else {
    if (!bVar6) {
      uVar9 = ((int (*)())FUN_00028350)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
      return uVar9;
    }
LAB_00029bd0:
    uVar9 = 0;
  }
  return uVar9;
}

/* FUN_00029294 @ 0x29294 (2376 bytes) */
int FUN_00029294(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  bool bVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  void *pvVar10;
  undefined4 *puVar11;
  uint uVar12;
  undefined *puVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  int *piVar17;
  int *piVar18;
  char in_stack_0000003b;
  int in_stack_0000003c;
  uint uStack_e8;
  int iStack_e4;
  int aiStack_e0 [3];
  int iStack_d4;
  int iStack_d0;
  int iStack_cc;
  int iStack_c8;
  uint uStack_c4;
  uint uStack_c0;
  uint uStack_bc;
  uint uStack_b8;
  uint uStack_b4;
  uint uStack_b0;
  uint uStack_ac;
  uint uStack_a8;
  undefined1 auStack_a4 [4];
  undefined1 auStack_a0 [4];
  undefined4 uStack_9c;
  uint uStack_98;
  undefined *puStack_94;
  int iStack_90;
  int iStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  uint uStack_80;
  uint uStack_7c;
  uint uStack_78;
  undefined4 uStack_74;
  uint uStack_70;
  uint uStack_6c;
  uint uStack_68;
  undefined4 uStack_64;
  uint uStack_60;
  uint uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  undefined1 uStack_50;
  
  iVar14 = param_1 + 0x240;
  uStack_84 = 0;
  aiStack_e0[1] = 0;
  uStack_88 = 0;
  iVar15 = *(int *)(param_1 + 0x10);
  iVar8 = FUN_0000a2f0(*(undefined2 *)(((unsigned char *)0x00002db8) + iVar15),*(undefined4 *)(param_1 + 0x154));
  if (((((*(uint *)(((unsigned char *)0x000030b0) + iVar15) & 0x1ff) == 0) &&
       ((*(uint *)(((unsigned char *)0x000030b4) + iVar15) & 0xff0000) == 0)) || (param_6 - 0x1901U < 2)) ||
     (in_stack_0000003b == '\x02')) {
    iVar7 = 0;
    bVar6 = false;
  }
  else if ((*(uint *)(((unsigned char *)0x000030b0) + iVar15) & 2) == 0) {
    if (((*(uint *)(((unsigned char *)0x000030b0) + iVar15) & 4) == 0) ||
       (*(short *)(((unsigned char *)0x00002fe8) + iVar15) != -0x7fea)) goto LAB_000293b0;
    bVar6 = true;
    iVar7 = *(int *)(((unsigned char *)0x00002ff0) + iVar15) + -1;
  }
  else if (*(short *)(((unsigned char *)0x00002fa8) + iVar15) == -0x7fea) {
    bVar6 = true;
    iVar7 = *(int *)(((unsigned char *)0x00002fb0) + iVar15) + -1;
  }
  else {
LAB_000293b0:
    iVar7 = 0;
    bVar6 = true;
  }
  if (in_stack_0000003c == 0) {
    bVar1 = in_stack_0000003b != '\x02';
    FUN_0000a6e0(param_1,param_6,param_7,param_4 - iVar7,param_5,&uStack_e8,&iStack_e4,aiStack_e0);
    uStack_ac = param_8 + aiStack_e0[0];
    if (param_3 < 0) {
      param_5 = param_5 + param_3;
      iVar7 = param_3 * uStack_e8;
      param_3 = 0;
      uStack_ac = uStack_ac - iVar7;
    }
    if (param_2 < 0) {
      param_4 = param_4 + param_2;
      iStack_e4 = param_2 * iStack_e4;
      param_2 = 0;
      uStack_ac = uStack_ac - iStack_e4;
    }
    if (*(int *)(param_1 + 0x160) < param_3 + param_5) {
      param_5 = *(int *)(param_1 + 0x160) - param_3;
    }
    if (*(int *)(param_1 + 0x15c) < param_2 + param_4) {
      param_4 = *(int *)(param_1 + 0x15c) - param_2;
    }
    if ((0 < param_4) && (0 < param_5)) {
      if (bVar1) {
        if (in_stack_0000003b == '\0') {
          uStack_98 = 0x20000;
        }
        else {
          uStack_98 = 0;
        }
        puVar13 = ((unsigned char *)0x00002e48) + iVar15;
        puStack_94 = ((unsigned char *)0x0007efff);
        if (((unsigned char *)0x00002e68)[iVar15] != '\0') {
          uStack_98 = uStack_98 | 2;
        }
        if (((unsigned char *)0x00002e69)[iVar15] != '\0') {
          uStack_98 = uStack_98 | 8;
        }
      }
      else {
        puVar13 = (undefined *)0x0;
        puStack_94 = (undefined *)0x0;
        uStack_98 = 0;
      }
      uStack_50 = 0;
      uStack_9c = 2;
      uStack_a8 = uStack_e8;
      iStack_90 = param_4;
      iStack_8c = param_5;
      _glgConvertType(param_6,param_7,auStack_a4,auStack_a0);
      piVar17 = *(int **)(param_1 + 0x150);
      if (piVar17 == (int *)0x0) {
        aiStack_e0[2] = param_2;
        iStack_d4 = param_3;
        iStack_d0 = param_4;
        iStack_cc = param_5;
        if (param_6 == 0x1901) {
          uVar12 = *(uint *)(param_1 + 0x154);
          if ((uVar12 & 0x30000) == 0x30000) {
            if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
              FUN_0001a0f0(param_1,0x1000000);
              uVar12 = *(uint *)(param_1 + 0x154);
            }
            uStack_b8 = (param_4 + 0xf) * 4 & 0xffffffc0;
            uStack_b0 = 0x14;
            uStack_b4 = 0xf;
            if ((uVar12 & 0x2000) == 0) {
LAB_000298a4:
              iStack_c8 = 4;
            }
            else {
LAB_00029878:
              if (iVar8 == 7) {
                iStack_c8 = 10;
              }
              else {
                if (iVar8 != 8) goto LAB_000298a4;
                iStack_c8 = 0xb;
              }
            }
LAB_000299f8:
            if ((bVar6) ||
               ((((bVar1 && (((*(uint *)(((unsigned char *)0x000030b4) + iVar15) & 0xff1) != 0 ||
                             ((*(uint *)((*(unsigned char *)0x00002e68) + iVar15) & 0xffff0000) != 0)))) ||
                 (param_6 - 0x1901U < 2)) ||
                ((((uStack_a8 & 0x3f) != 0 || (0x1fff < (int)uStack_a8)) ||
                 ((uStack_ac & 0x1f) != 0)))))) {
LAB_00029a74:
              uStack_c0 = uStack_b8;
              uVar12 = param_5 * uStack_b8 + 0xfff & 0xfffff000;
              if (*(uint *)(((unsigned char *)0x00002b78) + param_1) < uVar12) {
                if (*(int *)(((unsigned char *)0x00002b74) + param_1) != 0) {
                  _vfree();
                }
                pvVar10 = _valloc(uVar12);
                *(uint *)(((unsigned char *)0x00002b78) + param_1) = uVar12;
                *(void **)(((unsigned char *)0x00002b74) + param_1) = pvVar10;
              }
              uStack_c4 = *(uint *)(((unsigned char *)0x00002b74) + param_1);
              if (uStack_c4 == 0) goto LAB_00029bd0;
              bVar1 = false;
            }
            else {
              if ((uVar12 & 0xf) == 4) {
                if ((param_6 != 0x80e1) || (param_7 != 0x8367)) goto LAB_00029a74;
              }
              else if ((((uVar12 & 0xf) != 3) || (param_6 != 0x80e1)) || (param_7 != 0x8366))
              goto LAB_00029a74;
              bVar1 = true;
              uStack_c0 = uStack_a8;
              uStack_c4 = uStack_ac;
            }
            uStack_bc = uStack_c4;
            if (bVar6) {
              iVar14 = *(int *)(param_1 + 0x18);
              iVar8 = *(int *)(*(int *)(iVar14 + 0x140) + 0x30);
              uStack_80 = (uint)*(ushort *)(iVar8 + 0x98);
              uStack_7c = (uint)*(ushort *)(iVar8 + 0x9a);
              uStack_78 = (uint)*(ushort *)(iVar8 + 0x8c);
              uStack_74 = *(undefined4 *)(iVar8 + 0x9c);
              iVar8 = *(int *)(*(int *)(iVar14 + 0x148) + 0x30);
              uStack_70 = (uint)*(ushort *)(iVar8 + 0x98);
              uStack_6c = (uint)*(ushort *)(iVar8 + 0x9a);
              uStack_68 = (uint)*(ushort *)(iVar8 + 0x8c);
              uStack_64 = *(undefined4 *)(iVar8 + 0x9c);
              iVar8 = *(int *)(*(int *)(iVar14 + 0x144) + 0x30);
              uStack_60 = (uint)*(ushort *)(iVar8 + 0x98);
              uStack_5c = (uint)*(ushort *)(iVar8 + 0x9a);
              uStack_58 = (uint)*(ushort *)(iVar8 + 0x8c);
              uStack_54 = *(undefined4 *)(iVar8 + 0x9c);
            }
            iVar8 = _io_connect_method_structureI_structureO
                              (*(undefined4 *)(param_1 + 4),7,aiStack_e0 + 2,0x1c,0,aiStack_e0 + 1);
            if (iVar8 != 0) goto LAB_00029bd0;
            if (!bVar1) {
              _glgProcessPixels(puVar13,&uStack_bc);
              return 1;
            }
          }
        }
        else {
          if (param_6 != 0x1902) {
            iVar7 = FUN_0001a010(param_1,iVar8);
            if (iVar7 != 0) {
              FUN_000230d0(param_1,0,iVar8,0,0,0,*(undefined4 *)(param_1 + 0x15c),
                           *(undefined4 *)(param_1 + 0x160));
            }
            if (*(int *)(param_1 + 0x1d38) != 0) {
              puVar11 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar14,2);
              puVar11[1] = 0;
              *puVar11 = ((unsigned char *)0x00001386);
              *(undefined4 **)(param_1 + 0x298c) = puVar11 + 2;
              (**(code **)(param_1 + 0x299c))(iVar14);
            }
            if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
              FUN_0001a0f0(param_1,0x1000000);
            }
            if (*(int *)(param_1 + 0x1d38) != 0) {
              puVar11 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar14,2);
              *puVar11 = ((unsigned char *)0x00001386);
              puVar11[1] = *(undefined4 *)(param_1 + 0x1d38);
              *(undefined4 **)(param_1 + 0x298c) = puVar11 + 2;
              (**(code **)(param_1 + 0x299c))(iVar14,puVar11 + 2);
            }
            bVar2 = ((unsigned char *)0x00002b7f)[param_1];
            uVar12 = *(uint *)(param_1 + 0x154);
            uStack_b8 = (param_4 << (*(uint *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x14) & 7)) +
                        0x1fU & 0xffffffe0;
            uStack_b0 = *(uint *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x10) >> 0x16 & 0x1f;
            uStack_b4 = *(uint *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x10) >> 0x1b;
            iStack_c8 = iVar8;
            goto LAB_000299f8;
          }
          uVar12 = *(uint *)(param_1 + 0x154);
          if ((uVar12 & 0x30000) != 0) {
            if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
              FUN_0001a0f0(param_1,0x1000000);
              uVar12 = *(uint *)(param_1 + 0x154);
            }
            if ((uVar12 & 0x20000) == 0) {
              uStack_b0 = 2;
              uStack_b8 = (param_4 + 0x1f) * 2 & 0xffffffc0;
              uStack_b4 = 0xd;
            }
            else {
              uStack_b8 = (param_4 + 0xf) * 4 & 0xffffffc0;
              if ((uVar12 & 0x30000) == 0x30000) {
                uStack_b4 = 0xf;
                uStack_b0 = 0x14;
              }
              else {
                uStack_b4 = 0xd;
                uStack_b0 = 4;
              }
            }
            if ((uVar12 & 0x2000) != 0) goto LAB_00029878;
            goto LAB_000298a4;
          }
        }
      }
      else {
        iVar8 = 5;
        if ((param_6 != 0x1901) && (iVar8 = 4, param_6 != 0x1902)) {
          uStack_98 = uStack_98 | 0x60000;
          puStack_94 = (undefined *)((uint)puStack_94 | 0x68002);
          iVar8 = *(ushort *)(*piVar17 + 0x98) - 0x8ce0;
          if ((bVar1) &&
             (((*(uint *)(puVar13 + 0x268) & 0x1ff) != 0 ||
              ((*(uint *)(puVar13 + 0x26c) & 0xff0000) != 0)))) {
            iVar15 = *(int *)(param_1 + 0x18);
            iVar14 = *(int *)(*(int *)(iVar15 + 0x140) + 0x30);
            uStack_80 = (uint)*(ushort *)(iVar14 + 0x98);
            uStack_7c = (uint)*(ushort *)(iVar14 + 0x9a);
            uStack_78 = (uint)*(ushort *)(iVar14 + 0x8c);
            uStack_74 = *(undefined4 *)(iVar14 + 0x9c);
            iVar14 = *(int *)(*(int *)(iVar15 + 0x148) + 0x30);
            uStack_70 = (uint)*(ushort *)(iVar14 + 0x98);
            uStack_6c = (uint)*(ushort *)(iVar14 + 0x9a);
            uStack_68 = (uint)*(ushort *)(iVar14 + 0x8c);
            uStack_64 = *(undefined4 *)(iVar14 + 0x9c);
            iVar14 = *(int *)(*(int *)(iVar15 + 0x144) + 0x30);
            uStack_60 = (uint)*(ushort *)(iVar14 + 0x98);
            uStack_5c = (uint)*(ushort *)(iVar14 + 0x9a);
            uStack_58 = (uint)*(ushort *)(iVar14 + 0x8c);
            uStack_54 = *(undefined4 *)(iVar14 + 0x9c);
          }
        }
        piVar18 = *(int **)(piVar17[1] + iVar8 * 4);
        if (piVar18 != (int *)0x0) {
          iVar8 = iVar8 * 0x18 + *piVar17;
          uVar3 = *(ushort *)(*piVar18 + 0x18);
          iVar15 = *(int *)(iVar8 + 4);
          iVar14 = *(int *)(iVar8 + 8);
          iVar16 = *(int *)(iVar8 + 0xc);
          iVar8 = iVar14 * 0x18 + iVar15 * 0x168 + piVar18[0xc];
          uVar4 = *(undefined2 *)(iVar8 + 0xb2);
          uVar5 = *(undefined2 *)(iVar8 + 0xb0);
          _glgConvertType(uVar5,uVar4,&uStack_b4,&uStack_b0);
          iVar7 = *(int *)(param_1 + 0x15c);
          iVar8 = FUN_0000a3f0(uVar5,uVar4);
          uStack_b8 = iVar7 * iVar8;
          iVar7 = uStack_b8 * *(int *)(param_1 + 0x160);
          pvVar10 = _valloc((uint)uVar3 * iVar7);
          FUN_00031340(param_1,piVar18,iVar15,iVar14,uVar5,uVar4,pvVar10,uStack_b8);
          param_3 = param_3 * uStack_b8;
          iVar8 = FUN_0000a3f0(uVar5,uVar4);
          uStack_bc = (int)pvVar10 + param_2 * iVar8 + iVar16 * iVar7 + param_3;
          _glgProcessPixels(puVar13,&uStack_bc);
          _vfree(pvVar10);
          return 1;
        }
      }
    }
    uVar9 = 1;
  }
  else {
    if (!bVar6) {
      uVar9 = ((int (*)())FUN_00028350)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
      return uVar9;
    }
LAB_00029bd0:
    uVar9 = 0;
  }
  return uVar9;
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
  undefined4 local_b8;
  undefined4 uStack_b4;
  longlong local_b0;
  undefined4 local_a8;
  uint uStack_a4;
  undefined4 local_a0;
  uint uStack_9c;
  undefined4 local_98;
  undefined4 uStack_94;
  longlong local_90;
  undefined4 local_88;
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
      *(uint *)(param_1 + 0x216c) = *(uint *)(param_1 + 0x216c) & 0xfffff800 | 0x80;
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
  puVar18[1] = *(undefined4 *)(param_1 + 0x216c);
  puVar18 = (undefined4 *)FUN_00083c90(iVar24,puVar18 + 2);
  dVar11 = DOUBLE_001aa1e0;
  fVar9 = FLOAT_001aa10c;
  uStack_a4 = param_8 ^ 0x80000000;
  local_b8 = 0x43300000;
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
      local_88 = 0x43300000;
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

/* FUN_0002a260 @ 0x2a260 (356 bytes) */
int FUN_0002a260(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  uint uVar1;
  double dVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  uVar5 = *(undefined4 *)(param_1 + 8);
  FUN_000a6140(param_1,(*(uint *)(param_1 + 0x1ab8) ^ 1) & 1,param_2);
  FUN_0004b480(param_1,*(uint *)(param_1 + 0x18a4) >> 6 & 0xffff);
  uVar3 = (**(code **)(param_1 + 0x2758))(param_1,0x1f);
  *(undefined4 *)(FUN_00002748 + param_1 + 4) = uVar3;
  puVar4 = (undefined4 *)FUN_00083c90(param_1);
  *puVar4 = ((unsigned char *)0x000010c0);
  dVar2 = DOUBLE_001aa250;
  puVar4[1] = 0x80;
  uVar1 = (uint)(((double)CONCAT44(0x43300000,uVar5) - dVar2) * DOUBLE_001aa240);
  puVar4[2] = ((unsigned char *)0x00001087);
  puVar4[4] = ((unsigned char *)0x000012f0);
  puVar4[5] = 0;
  puVar4[3] = uVar1 << 0x10 | uVar1 & 0xffff;
  *(undefined4 *)(param_1 + 0x1b84) = 5;
  *(undefined4 *)(param_1 + 0x1c8c) = *(undefined4 *)(param_1 + 0x2814);
  *(undefined4 *)(param_1 + 0x1c94) = *(undefined4 *)(param_1 + 0x2818);
  puVar4[6] = 0x82c;
  uVar3 = *(undefined4 *)(param_1 + 0x1b84);
  puVar4[8] = 0x766;
  puVar4[7] = uVar3;
  uVar3 = *(undefined4 *)(param_1 + 0x1c8c);
  puVar4[10] = 0x768;
  puVar4[9] = uVar3;
  puVar4[0xb] = *(undefined4 *)(param_1 + 0x1c94);
  *(undefined4 **)(FUN_00002748 + param_1 + 4) = puVar4 + 0xc;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,puVar4 + 0xc);
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
  longlong local_b8;
  longlong local_b0;
  longlong local_a8;
  longlong local_a0;
  longlong local_98;
  longlong local_90;
  longlong local_88;
  
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
        local_b8 = (longlong)iVar22;
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
      local_88 = (longlong)(int)uVar31;
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
      puVar24[0xd5] = (*(unsigned char *)0x000010ea);
      uVar25 = *(undefined4 *)(param_1 + 0x1cfc);
      puVar24[0xd7] = ((unsigned char *)0x000010fa);
      puVar24[0xd6] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1da0);
      puVar24[0xd9] = 0xc0001000;
      puVar24[0xdb] = 0x11004;
      puVar24[0xd8] = uVar25;
      puVar24[0xdc] = *(undefined4 *)(param_1 + 0x1ca8);
      uVar25 = *(undefined4 *)(param_1 + 0x1cac);
      puVar24[0xde] = ((unsigned char *)0x00001008);
      puVar24[0xdd] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1ca0);
      puVar24[0xe0] = (*(unsigned char *)0x000010e9);
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
      uVar25 = *(undefined4 *)(param_1 + 0x1dc0);
      puVar24[0xe8] = 0x887;
      puVar24[0xe7] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1db4);
      puVar24[0x18a] = 0x82c;
      puVar24[0xe9] = uVar25;
      uVar25 = *(undefined4 *)(FUN_00001dc4 + param_1);
      puVar24[0xea] = ((unsigned char *)0x000010ae);
      puVar24[0x18b] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1d70);
      puVar24[0xec] = ((unsigned char *)0x00001394);
      puVar24[0xeb] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1d30);
      puVar24[0xee] = ((unsigned char *)0x00001380);
      puVar24[0xf0] = ((unsigned char *)0x00001002);
      puVar24[0xef] = 0;
      puVar24[0xed] = uVar25;
      puVar24[0xf1] = *(undefined4 *)(param_1 + 0x1d90);
      uVar25 = *(undefined4 *)(param_1 + 0x1d90);
      puVar24[0xf2] = 0x824;
      puVar24[0xf1] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1ddc);
      puVar24[0xf4] = 0x825;
      puVar24[0xf3] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1de0);
      puVar24[0xf6] = 0x82d;
      puVar24[0xf5] = uVar25;
      uVar25 = *(undefined4 *)(FUN_000026c8 + param_1 + 4);
      puVar24[0xf8] = 0x854;
      puVar24[0xf7] = uVar25;
      uVar25 = **(undefined4 **)(param_1 + 0x2680);
      puVar24[0xfa] = 0x878;
      puVar24[0xf9] = uVar25;
      uVar25 = **(undefined4 **)(param_1 + 0x2684);
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
      uVar25 = *(undefined4 *)(param_1 + 0x1d7c);
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
      uVar25 = *(undefined4 *)(param_1 + 0x1d6c);
      puVar24[0x108] = ((unsigned char *)0x00001096);
      puVar24[0x107] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1df8);
      puVar24[0x10a] = ((unsigned char *)0x00001041);
      puVar24[0x107] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x29f0);
      puVar24[0x10c] = ((unsigned char *)0x00001046);
      puVar24[0x10b] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1dfc);
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
      uVar25 = *(undefined4 *)(param_1 + 0x216c);
      puVar24[0x162] = ((unsigned char *)0x000010c1);
      puVar24[0x164] = ((unsigned char *)0x000010c8);
      puVar24[0x166] = ((unsigned char *)0x0000101d);
      puVar24[0x161] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x2128);
      puVar24[0x168] = ((unsigned char *)0x0000138a);
      puVar24[0x16a] = ((unsigned char *)0x0000138e);
      puVar24[0x16f] = 0;
      puVar24[0x16c] = ((unsigned char *)0x00001040);
      puVar24[0x169] = 0;
      puVar24[0x16b] = 0;
      puVar24[0x16d] = 0;
      puVar24[0x167] = uVar25;
      puVar24[0x16e] = (*(unsigned char *)0x00001150);
      puVar24[0x170] = ((unsigned char *)0x00001100);
      uVar25 = *(undefined4 *)(param_1 + 0x1f1c);
      puVar24[0x172] = ((unsigned char *)0x00001110);
      puVar24[0x171] = uVar25;
      puVar24[0x173] = *(undefined4 *)(param_1 + 0x1f5c);
      puVar24[0x174] = (*(unsigned char *)0x00001120);
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
      puVar24[0x181] = *(undefined4 *)(param_1 + 0x1d98);
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
  int *piVar7;
  
  uVar5 = *(uint *)(param_1 + 0x2610);
  iVar2 = *(int *)(param_1 + 0x224) + 0x210;
  piVar7 = (int *)(iVar2 + *param_2 * 0x20);
  iVar6 = piVar7[2];
  iVar3 = piVar7[4];
  iVar4 = piVar7[3];
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
    iVar2 = 0;
    while ((((bVar1 || ((1 < uVar5 && (iVar3 == -1)))) ||
            (((2 < uVar5 && (iVar6 == -1)) || ((3 < uVar5 && (iVar4 == -1)))))) &&
           (bVar1 = iVar2 != 10000, iVar2 = iVar2 + 1, bVar1))) {
      FUN_00009bd0(param_1);
      _usleep(100);
      iVar3 = piVar7[4];
      iVar6 = piVar7[2];
      iVar4 = piVar7[3];
      bVar1 = *piVar7 == -1;
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

/* FUN_0002b740 @ 0x2b740 (172 bytes) */
int FUN_0002b740(param_1, param_2)
  int param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x224);
  iVar2 = iVar4 + 0x210;
  iVar1 = iVar2 + *param_2 * 0x20;
  *(undefined4 *)(iVar2 + *param_2 * 0x20) = 0xffffffff;
  *(undefined4 *)(iVar1 + 0xc) = 0xffffffff;
  *(undefined4 *)(iVar1 + 4) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0xffffffff;
  *(undefined4 *)(iVar1 + 8) = 0xffffffff;
  *(int *)(iVar4 + 8) = *param_2;
  puVar3 = *(undefined4 **)(param_1 + 0x1dc);
  if (*(undefined4 **)(param_1 + 0x1e0) <= puVar3 + 2) {
    FUN_0001a0f0(param_1,0x1000000);
    puVar3 = *(undefined4 **)(param_1 + 0x1dc);
  }
  *(undefined4 **)(param_1 + 0x1dc) = puVar3 + 2;
  puVar3[1] = 0;
  *puVar3 = ((unsigned char *)0x000013d6);
  ((unsigned char *)0x00002b7e)[param_1] = 1;
  FUN_00090470(param_1 + 0x240);
  return;
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

/* FUN_0002bbc4 @ 0x2bbc4 (564 bytes) */
int FUN_0002bbc4(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  char in_RESERVE;
  byte in_cr0;
  
  iVar12 = *(int *)(param_1 + 0x2610);
  iVar11 = *(int *)(param_1 + 0x261c);
  uVar9 = *(undefined4 *)(param_1 + 0x1cf8);
  puVar10 = (undefined4 *)**(undefined4 **)(param_1 + 0x234);
  if (iVar12 == 1) {
    if (iVar11 == 2) {
      iVar12 = 2;
      iVar6 = 8;
    }
    else {
      iVar6 = 4;
    }
  }
  else {
    iVar6 = iVar12 << 2;
  }
  piVar2 = puVar10 + 4;
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar2 + 0x10000,0,piVar2);
      *piVar2 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  puVar5 = *(uint **)(param_1 + 0x1dc);
  if (*(uint **)(param_1 + 0x1e0) <= puVar5 + iVar6 + 0x15) {
    FUN_0001a0f0(param_1,0x1000000);
    puVar5 = *(uint **)(param_1 + 0x1dc);
  }
  puVar7 = (undefined4 *)((uint)(puVar5 + 0xb) & 0xffffffe0);
  puVar8 = puVar7 + 4;
  *puVar5 = (((int)puVar7 - (int)puVar5) + -8) * 0x4000 | 0xc0001000;
  puVar7[-1] = (int)puVar7 - (int)puVar5;
  puVar5 = *(uint **)(param_1 + 0x1d8);
  *puVar5 = (int)puVar7 - (int)puVar5 >> 2 | *puVar5;
  *(undefined4 **)(param_1 + 0x1d8) = puVar7;
  *puVar7 = 0x3b000000;
  uVar3 = *puVar10;
  puVar7[2] = 0;
  puVar7[1] = uVar3;
  puVar7[3] = *param_2;
  if (iVar11 == 2) {
    puVar7[5] = 0;
    puVar7[4] = ((unsigned char *)0x000013c5);
    uVar4 = 0;
    iVar11 = 2;
    puVar10 = puVar7 + 6;
    do {
      puVar7 = puVar10;
      *puVar7 = ((unsigned char *)0x000012fa);
      puVar7[2] = ((unsigned char *)0x000013d7);
      puVar7[3] = 0;
      puVar7[1] = 1 << (uVar4 & 0x3f);
      uVar4 = uVar4 + 1;
      iVar11 = iVar11 + -1;
      puVar10 = puVar7 + 4;
    } while (iVar11 != 0);
    puVar7[4] = ((unsigned char *)0x000012fa);
    puVar7[7] = uVar9;
    puVar8 = puVar7 + 8;
    puVar7[5] = 3;
    puVar7[6] = ((unsigned char *)0x000013c5);
  }
  else {
    if (iVar12 != 0) {
      uVar4 = 0;
      do {
        *puVar8 = ((unsigned char *)0x000010b2);
        puVar8[2] = ((unsigned char *)0x000013d7);
        puVar8[3] = 0;
        puVar8[1] = 1 << (uVar4 & 0x3f);
        uVar4 = uVar4 + 1;
        puVar8 = puVar8 + 4;
        iVar12 = iVar12 + -1;
      } while (iVar12 != 0);
    }
    *puVar8 = ((unsigned char *)0x000010b2);
    puVar8[1] = 0xf;
    puVar8 = puVar8 + 2;
  }
  *(undefined4 **)(param_1 + 0x1dc) = puVar8;
  ((unsigned char *)0x00002b7e)[param_1] = 0;
  FUN_00090470(param_1 + 0x240);
  return;
}

/* FUN_0002be00 @ 0x2be00 (88 bytes) */
int FUN_0002be00(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  iVar1 = *(int *)(iVar2 + 0x1dc);
  if (*(uint *)(iVar2 + 0x1e0) <= (uint)(param_2 * 4 + iVar1)) {
    FUN_0001a0f0(iVar2,0x1000000);
    iVar1 = *(int *)(iVar2 + 0x1dc);
  }
  return iVar1;
}

/* FUN_0002be60 @ 0x2be60 (12 bytes) */
int FUN_0002be60(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x1dc) = param_2;
  return;
}

/* FUN_0002be70 @ 0x2be70 (8 bytes) */
int FUN_0002be70(param_1)
  int param_1;
{
  return *(undefined4 *)(FUN_00002748 + param_1 + 4);
}

/* FUN_0002be80 @ 0x2be80 (4 bytes) */
int FUN_0002be80()
{
  return;
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
  uVar7 = *(int *)(param_1 + 0x267c) + 1U >> 1;
  uVar1 = (uVar7 - 1) * 0x10000;
  *param_2 = uVar1 | 0x854;
  if (uVar7 != 0) {
    iVar4 = 0;
    uVar6 = uVar7;
    do {
      iVar2 = iVar4 * 4;
      iVar4 = iVar4 + 1;
      *puVar3 = *(uint *)(iVar2 + *(int *)(param_1 + 0x2680));
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
      *puVar5 = *(uint *)(iVar2 + *(int *)(param_1 + 0x2684));
      puVar5 = puVar5 + 1;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
  }
  *puVar5 = 0x82d;
  puVar5[1] = *(uint *)(FUN_000026c8 + param_1 + 4);
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
  iVar3 = (int)((*(uint *)(param_1 + 0x26d0) & 0x1f) + 1) >> 1;
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
      *puVar5 = *(uint *)(iVar1 + *(int *)(param_1 + 0x26d4));
      puVar5[1] = *(uint *)(*(int *)(param_1 + 0x26d8) + iVar4);
      iVar1 = *(int *)(param_1 + 0x26d8) + iVar4;
      iVar4 = iVar4 + 8;
      puVar5[2] = *(uint *)(iVar1 + 4);
      puVar5 = puVar5 + 3;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  *puVar5 = 0x830;
  puVar5[1] = *(uint *)(param_1 + 0x26d0);
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
  *(code **)(param_1 + 0x2998) = FUN_0002be70;
  *(code **)(param_1 + 0x299c) = FUN_0002be80;
  *(undefined4 **)(param_1 + 0x298c) = puVar1 + 8;
  FUN_00050300(param_1 + 0x240);
  *puVar1 = *(undefined4 *)(param_1 + 0x1d20);
  puVar1[1] = *(undefined4 *)(param_1 + 0x1cf0);
  puVar1[5] = *(int *)(param_1 + 0x298c) - (int)(puVar1 + 8) >> 2;
  *(code **)(param_1 + 0x299c) = FUN_0002be60;
  *(code **)(param_1 + 0x2998) = FUN_0002be00;
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
  uVar5 = FUN_0002f410(*(undefined4 *)(param_1 + 0x154));
  ((unsigned char *)0x00002b7f)[param_1] = uVar5;
  *(int *)(param_1 + 0x2680) = param_1 + 0x26dc;
  *(int *)(param_1 + 0x2684) = param_1 + 0x26fc;
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
  *(undefined4 *)(param_1 + 0x26a0) = 0;
  *(undefined4 *)(param_1 + 0x26b0) = 0;
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
  *(undefined4 *)(FUN_000026c8 + param_1) = 7;
  uVar6 = 0;
  *(undefined1 *)(param_1 + 0x2a43) = 1;
  *(undefined1 *)(param_1 + 0x26bd) = 1;
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
  ((int (*)())FUN_00025da0)(param_1);
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
  uint param_2;
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  uVar2 = *(uint *)(param_1 + 0x18) & 0xfff07fff;
  *(uint *)(param_1 + 0x18) = uVar2;
  if ((uVar1 & 0xe00000) == 0) {
    *(uint *)(param_1 + 0x18) = uVar2;
    if (param_2 == 0x2700) {
      uVar2 = uVar1 & 0xffff87ff | 0x2800;
      *(uint *)(param_1 + 0x14) = uVar2;
    }
    else {
      uVar2 = uVar1;
      if (param_2 < 0x2701) {
        if (param_2 == 0x2600) {
          uVar2 = uVar1 & 0xffff87ff | 0x800;
          *(uint *)(param_1 + 0x14) = uVar2;
        }
        else if (param_2 == 0x2601) {
          uVar2 = uVar1 & 0xffff87ff | 0x1000;
          *(uint *)(param_1 + 0x14) = uVar2;
        }
      }
      else if (param_2 == 0x2702) {
        uVar2 = uVar1 & 0xffff87ff | 0x4800;
        *(uint *)(param_1 + 0x14) = uVar2;
      }
      else if (param_2 < 0x2702) {
        uVar2 = uVar1 & 0xffff87ff | 0x3000;
        *(uint *)(param_1 + 0x14) = uVar2;
      }
      else if (param_2 == 0x2703) {
        uVar2 = uVar1 & 0xffff87ff | 0x5000;
        *(uint *)(param_1 + 0x14) = uVar2;
      }
    }
    goto LAB_0002d190;
  }
  uVar2 = uVar1 & 0xffffe7ff | 0x1800;
  *(uint *)(param_1 + 0x14) = uVar2;
  if (param_2 == 0x2700) {
LAB_0002d0a0:
    uVar2 = uVar1 & 0xffff87ff | 0x3800;
    *(uint *)(param_1 + 0x14) = uVar2;
  }
  else {
    if (param_2 < 0x2701) {
      if (param_2 - 0x2600 < 2) {
        uVar2 = uVar1 & 0xffff87ff | 0x1800;
        *(uint *)(param_1 + 0x14) = uVar2;
      }
      goto LAB_0002d190;
    }
    if (param_2 != 0x2702) {
      if (param_2 < 0x2702) goto LAB_0002d0a0;
      if (param_2 != 0x2703) goto LAB_0002d190;
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

