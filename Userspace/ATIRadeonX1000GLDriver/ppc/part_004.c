#include "decls.h"

/* FUN_000243f0 @ 0x243f0 (112 bytes) */
void FUN_000243f0(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  double in_stack_ffffffa8;
  
  iVar2 = ((uint (*)())FUN_0002cc30)(param_1,0,6,param_4,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
                       fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffa8);
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
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar4,puVar1);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    *puVar1 = 0x82c;
    uVar4 = *(undefined4 *)(0x00001dc4 + param_1);
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
void FUN_00024470(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  double in_stack_ffffffb8;
  
  iVar3 = ((uint (*)())FUN_0002cc30)(param_1,0,7,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
                       fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffb8);
  if (iVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar5 = *(undefined4 *)(param_1 + 0x244);
    uVar6 = *(undefined4 *)(param_1 + 0x1ee0);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              iVar3 * *(int *)(param_1 + 0x267c) * 5 + iVar3 * 2 + 0x16);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar5,puVar1);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar5 = *(undefined4 *)(0x00001dc4 + param_1);
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
void FUN_000244f0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  double in_stack_ffffffb8;
  
  iVar3 = ((uint (*)())FUN_0002cc30)(param_1,0,8,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
                       fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffb8);
  if (iVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar5 = *(undefined4 *)(param_1 + 0x244);
    uVar6 = *(undefined4 *)(param_1 + 0x1ee0);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              iVar3 * *(int *)(param_1 + 0x267c) * 5 + iVar3 * 2 + 0x16);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar5,puVar1);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar5 = *(undefined4 *)(0x00001dc4 + param_1);
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
void FUN_00024570(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  double in_stack_ffffffb8;
  
  iVar3 = ((uint (*)())FUN_0002cc30)(param_1,0,9,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
                       fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffb8);
  if (iVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar5 = *(undefined4 *)(param_1 + 0x244);
    uVar6 = *(undefined4 *)(param_1 + 0x1ee0);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              iVar3 * *(int *)(param_1 + 0x267c) * 5 + iVar3 * 2 + 0x16);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar5,puVar1);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar5 = *(undefined4 *)(0x00001dc4 + param_1);
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
void FUN_000245f0(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  double in_stack_ffffffb8;
  
  uVar3 = ((uint (*)())FUN_0002cc30)(param_1,0,9,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
                       fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffb8);
  if (uVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar6 = *(undefined4 *)(param_1 + 0x244);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              *(int *)(param_1 + 0x267c) * uVar3 * 5 + uVar3 * 2 + 0x16,param_2,
                        uVar3,param_4);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar6,puVar1);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar6 = *(undefined4 *)(0x00001dc4 + param_1);
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
void FUN_00024670(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  double in_stack_ffffffb8;
  
  iVar3 = ((uint (*)())FUN_0002cc30)(param_1,0,0,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
                       fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffb8);
  if (iVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar5 = *(undefined4 *)(param_1 + 0x244);
    uVar6 = *(undefined4 *)(param_1 + 0x1ee0);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              iVar3 * *(int *)(param_1 + 0x267c) * 5 + iVar3 * 2 + 0x16);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar5,puVar1);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar5 = *(undefined4 *)(0x00001dc4 + param_1);
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
void FUN_000246f0(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  double in_stack_ffffffb8;
  
  uVar3 = ((uint (*)())FUN_0002cc30)(param_1,0,0,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
                       fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffb8);
  if (uVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar6 = *(undefined4 *)(param_1 + 0x244);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              *(int *)(param_1 + 0x267c) * uVar3 * 5 + uVar3 * 2 + 0x16,param_2,
                        uVar3,0);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar6,puVar1);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar6 = *(undefined4 *)(0x00001dc4 + param_1);
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
void FUN_00024770(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  double in_stack_ffffffb8;
  
  iVar3 = ((uint (*)())FUN_0002cc30)(param_1,0,1,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
                       fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffb8);
  if (iVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar5 = *(undefined4 *)(param_1 + 0x244);
    uVar6 = *(undefined4 *)(param_1 + 0x1ee0);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              iVar3 * *(int *)(param_1 + 0x267c) * 5 + iVar3 * 2 + 0x16);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar5,puVar1);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar5 = *(undefined4 *)(0x00001dc4 + param_1);
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
void FUN_000247f0(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  double in_stack_ffffffb8;
  
  uVar3 = ((uint (*)())FUN_0002cc30)(param_1,0,1,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4,
                       fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffb8);
  if (uVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar6 = *(undefined4 *)(param_1 + 0x244);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              *(int *)(param_1 + 0x267c) * uVar3 * 5 + uVar3 * 2 + 0x16,param_2,
                        uVar3,0);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar6,puVar1);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar6 = *(undefined4 *)(0x00001dc4 + param_1);
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
void FUN_00024870(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  double in_stack_ffffffb8;
  
  iVar3 = ((uint (*)())FUN_0002cc30)(param_1,param_4,2,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4
                       ,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffb8);
  if (iVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar5 = *(undefined4 *)(param_1 + 0x244);
    uVar6 = *(undefined4 *)(param_1 + 0x1ee0);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              iVar3 * *(int *)(param_1 + 0x267c) * 5 + iVar3 * 2 + 0x16);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar5,puVar1);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar5 = *(undefined4 *)(0x00001dc4 + param_1);
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
void FUN_000248f0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  double in_stack_ffffffb8;
  
  iVar3 = ((uint (*)())FUN_0002cc30)(param_1,param_4,3,param_3,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4
                       ,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffb8);
  if (iVar3 != 0) {
    iVar4 = param_1 + 0x240;
    uVar5 = *(undefined4 *)(param_1 + 0x244);
    uVar6 = *(undefined4 *)(param_1 + 0x1ee0);
    puVar1 = (undefined4 *)
             (**(code **)(param_1 + 0x2998))
                       (iVar4,(*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) +
                              iVar3 * *(int *)(param_1 + 0x267c) * 5 + iVar3 * 2 + 0x16);
    *(undefined4 **)(param_1 + 0x298c) = puVar1;
    if (*(code **)(param_1 + 0x2680) != 0x00001e24 + param_1) {
      *(code **)(param_1 + 0x2680) = 0x00001e24 + param_1;
      *(int *)(param_1 + 0x2684) = param_1 + 0x1e44;
      *(undefined4 *)(0x000026c8 + param_1 + 4) = *(undefined4 *)(param_1 + 0x1ee4);
      puVar1 = (undefined4 *)((int (*)())FUN_0002c0c0)(uVar5,puVar1);
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar1 = 0x5c8;
      puVar1[1] = 0x10000000;
      puVar1 = puVar1 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    puVar2 = puVar1 + 4;
    *puVar1 = 0x82c;
    uVar5 = *(undefined4 *)(0x00001dc4 + param_1);
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
void FUN_00024970(int param_1,int param_2,int param_3,int param_4,undefined4 param_5,undefined *param_6,uint *param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
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
  double in_stack_ffffff88;
  
  uVar12 = (uint)*(byte *)(param_1 + 8);
  dataCacheBlockTouch(*(undefined4 *)(param_1 + 0x1d8));
  iVar3 = ((uint (*)())FUN_0002cc30)(param_1,1,param_3,param_5,param_5,param_6,fparam_1,fparam_2,fparam_3,fparam_4
                       ,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff88);
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
    uVar6 = *(undefined4 *)(0x00001dc4 + param_1);
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
    *puVar4 = (uint)((unsigned char *)0x00001393U);
    *(uint **)(param_1 + 0x298c) = puVar4 + 2;
    (**(code **)(param_1 + 0x299c))(param_1 + 0x240,puVar4 + 2);
    *(undefined4 *)(param_1 + 0x26d4) = 0;
    *(undefined1 *)(param_1 + 0x2a5e) = 1;
    *(int *)(param_1 + 0x2680) = param_1 + 0x26dc;
    *(int *)(param_1 + 0x2684) = param_1 + 0x26fc;
    ((unsigned char *)0x000027d0)[param_1 + 5] = 1;
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
double FUN_00024fe0(int param_1,int param_2,float *param_3,double fparam_1)
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  float fVar6;
  int iVar7;
  undefined *puVar8;
  dword *pdVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  float *pfVar16;
  dword *pdVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  dword *pdVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  int iVar25;
  int *piVar26;
  uint *puVar27;
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
  
  piVar26 = *(int **)(*(int *)(param_1 + 0x18) + 0x19c);
  bVar1 = piVar26 == (int *)0x0;
  if (bVar1) {
    piVar26 = *(int **)(*(int *)(param_1 + 0x18) + 400);
  }
  iVar14 = piVar26[0xd];
  if (((iVar14 == 0) && (iVar14 = piVar26[0xc], iVar14 == 0)) &&
     (iVar14 = piVar26[0xb], iVar14 == 0)) {
    iVar19 = *piVar26;
    iVar14 = *(int *)(iVar19 + 4);
  }
  else {
    iVar19 = *piVar26;
  }
  iVar7 = *(int *)(iVar14 + 0x6c);
  iVar24 = *(int *)(iVar19 + 0x18);
  puVar27 = (uint *)(iVar14 + *(int *)(iVar14 + 0x2c) * 8);
  iVar19 = *(int *)(iVar14 + 0x28);
  if (param_2 < *(int *)(iVar14 + 0x28)) {
    iVar19 = param_2;
  }
  if (iVar19 < 1) {
LAB_00025b04:
    fVar3 = FLOAT_001aa13c;
    fVar2 = FLOAT_001aa138;
    fVar6 = FLOAT_001aa134;
    iVar14 = piVar26[0xe];
    if (iVar14 != 0) {
      uVar15 = *(uint *)(iVar14 + 0x20);
      if ((uVar15 & 0x4000000) != 0) {
        *param_3 = FLOAT_001aa130;
        param_3[1] = fVar6;
        param_3[2] = fVar2;
        param_3[3] = fVar3;
        param_3 = param_3 + 4;
        uVar15 = *(uint *)(iVar14 + 0x20);
      }
      if ((uVar15 & 0x2000000) != 0) {
        *param_3 = *(float *)(((unsigned char *)0x00002de0) + *(int *)(param_1 + 0x10));
        param_3[1] = *(float *)(((unsigned char *)0x00002de4) + *(int *)(param_1 + 0x10));
        param_3[2] = *(float *)(((unsigned char *)0x00002de8) + *(int *)(param_1 + 0x10));
        param_3[4] = -*(float *)(((unsigned char *)0x00002dfc) + *(int *)(param_1 + 0x10));
        fVar6 = FLOAT_001aa140;
        param_3[5] = *(float *)(((unsigned char *)0x00002df8) + *(int *)(param_1 + 0x10)) *
                     *(float *)(((unsigned char *)0x00002dfc) + *(int *)(param_1 + 0x10));
        fVar2 = FLOAT_001aa144;
        param_3[6] = *(float *)(((unsigned char *)0x00002df0) + *(int *)(param_1 + 0x10)) * fVar6;
        param_3[7] = *(float *)(((unsigned char *)0x00002df0) + *(int *)(param_1 + 0x10)) * fVar2;
      }
    }
    return fparam_1;
  }
  iVar25 = 0;
LAB_00025090:
  dVar5 = DOUBLE_001aa1e0;
  fVar6 = FLOAT_001aa0e8;
  uVar15 = *puVar27;
  uVar20 = uVar15 & 0x1f0000;
  if (uVar20 == 0) goto LAB_00025af0;
  if (uVar20 == 0x110000) {
    pfVar16 = (float *)(iVar14 + iVar7 * 8 + (uint)(ushort)*puVar27 * 0x10);
LAB_0002546c:
    if ((bVar1) || ((uVar15 & 0x1c000000) == 0x4000000)) {
      *param_3 = *pfVar16;
      param_3[1] = pfVar16[1];
      param_3[2] = pfVar16[2];
      param_3[3] = pfVar16[3];
    }
    else if ((uVar15 & 0x1c000000) == 0xc000000) {
      local_78 = 0x43300000;
      fStack_74 = -*pfVar16;
      *param_3 = (float)((double)CONCAT44(0x43300000,-*pfVar16) - DOUBLE_001aa1e0);
      local_70 = 0x43300000;
      fStack_6c = -pfVar16[1];
      param_3[1] = (float)((double)CONCAT44(0x43300000,-pfVar16[1]) - dVar5);
      local_68 = 0x43300000;
      fStack_64 = -pfVar16[2];
      param_3[2] = (float)((double)CONCAT44(0x43300000,-pfVar16[2]) - dVar5);
      local_60 = 0x43300000;
      fStack_5c = -pfVar16[3];
      param_3[3] = (float)((double)CONCAT44(0x43300000,-pfVar16[3]) - dVar5);
    }
    else {
      if (*pfVar16 == 0.0) {
        fVar6 = 0.0;
      }
      else {
        fVar6 = 1.0;
      }
      *param_3 = fVar6;
      if (pfVar16[1] == 0.0) {
        fVar6 = 0.0;
      }
      else {
        fVar6 = 1.0;
      }
      param_3[1] = fVar6;
      if (pfVar16[2] == 0.0) {
        fVar6 = 0.0;
      }
      else {
        fVar6 = 1.0;
      }
      param_3[2] = fVar6;
      if (pfVar16[3] == 0.0) {
        fVar6 = 0.0;
      }
      else {
        fVar6 = 1.0;
      }
      param_3[3] = fVar6;
    }
    goto LAB_00025af0;
  }
  if (uVar20 == 0x10000) {
    pfVar16 = (float *)(iVar24 + (uint)(ushort)*puVar27 * 0x10);
    goto LAB_0002546c;
  }
  if (uVar20 == 0x20000) {
    iVar23 = (uint)(ushort)*puVar27 * 0x10;
    iVar10 = iVar23 + *(int *)(((unsigned char *)0x00004310) + *(int *)(param_1 + 0x10));
    *param_3 = *(float *)(iVar23 + *(int *)(((unsigned char *)0x00004310) + *(int *)(param_1 + 0x10)));
    param_3[1] = *(float *)(iVar10 + 4);
    param_3[2] = *(float *)(iVar10 + 8);
    param_3[3] = *(float *)(iVar10 + 0xc);
    goto LAB_00025af0;
  }
  if (uVar20 == 0x100000) {
    uVar20 = uVar15 >> 0xc & 3;
    uVar22 = uVar15 & 0xff;
    switch(uVar15 >> 8 & 7) {
    default:
      iVar23 = 0;
      break;
    case 1:
      iVar23 = 0xc0;
      break;
    case 2:
      iVar23 = 0x80;
      break;
    case 3:
      iVar23 = (uVar22 + 4) * 0x40;
      break;
    case 4:
      iVar23 = (uVar22 + 0x10) * 0x40;
      break;
    case 5:
      iVar23 = (uVar22 + 8) * 0x40;
    }
    uVar15 = uVar15 >> 0xe & 3;
    iVar10 = *(int *)(param_1 + 0x10) + 0x1860 + iVar23;
    if ((1 < uVar15) && (iVar10 = iVar23 + *(int *)(param_1 + 0x10) + 0x1e60, 3 < uVar15)) {
      iVar10 = 0;
    }
    if (uVar15 < 3) {
      if (uVar15 == 0) {
LAB_000256f4:
        iVar23 = uVar20 * 4;
        iVar11 = iVar10 + iVar23;
        local_90 = *(float *)(iVar10 + iVar23);
        local_8c = *(float *)(iVar11 + 0x10);
        local_88 = *(float *)(iVar11 + 0x20);
        local_84[0] = *(float *)(iVar11 + 0x30);
      }
      else {
        iVar23 = uVar20 * 0x10;
        iVar11 = iVar10 + iVar23;
        local_90 = *(float *)(iVar10 + iVar23);
        local_8c = *(float *)(iVar11 + 4);
        local_88 = *(float *)(iVar11 + 8);
        local_84[0] = *(float *)(iVar11 + 0xc);
      }
    }
    else if (uVar15 == 3) goto LAB_000256f4;
    goto LAB_00025ac8;
  }
  switch(uVar15 >> 0x10 & 0x1f) {
  case 0:
    pdVar21 = (dword *)&local_8c;
    pdVar9 = (dword *)&local_88;
    pdVar17 = (dword *)local_84;
    pfVar16 = &local_90;
    break;
  default:
    goto switchD_00025774_caseD_1;
  case 2:
    pfVar16 = (float *)((uVar15 & 0xffff) * 0x10 +
                       *(int *)(((unsigned char *)0x00004308) + *(int *)(param_1 + 0x10)));
    pdVar21 = (dword *)(pfVar16 + 1);
    pdVar9 = (dword *)(pfVar16 + 2);
    pdVar17 = (dword *)(pfVar16 + 3);
    break;
  case 3:
    uVar20 = uVar15 & 0xff;
    switch(uVar15 >> 8 & 0xf) {
    case 0:
      pfVar16 = (float *)(uVar20 * 0x80 + 0x24c0 + *(int *)(param_1 + 0x10));
      pdVar21 = (dword *)(pfVar16 + 1);
      pdVar9 = (dword *)(pfVar16 + 2);
      pdVar17 = (dword *)(pfVar16 + 3);
      break;
    case 1:
      pfVar16 = (float *)(uVar20 * 0x80 + 0x24d0 + *(int *)(param_1 + 0x10));
      pdVar21 = (dword *)(pfVar16 + 1);
      pdVar9 = (dword *)(pfVar16 + 2);
      pdVar17 = (dword *)(pfVar16 + 3);
      break;
    case 2:
      pfVar16 = (float *)(uVar20 * 0x80 + 0x24e0 + *(int *)(param_1 + 0x10));
      pdVar21 = (dword *)(pfVar16 + 1);
      pdVar9 = (dword *)(pfVar16 + 2);
      pdVar17 = (dword *)(pfVar16 + 3);
      break;
    case 3:
      pfVar16 = (float *)(uVar20 * 0x80 + 0x24f0 + *(int *)(param_1 + 0x10));
      pdVar21 = (dword *)(pfVar16 + 1);
      pdVar9 = (dword *)(pfVar16 + 2);
      pdVar17 = (dword *)(pfVar16 + 3);
      break;
    case 4:
      pfVar16 = (float *)(uVar20 * 0x80 + 0x2500 + *(int *)(param_1 + 0x10));
      pdVar21 = (dword *)(pfVar16 + 1);
      pdVar9 = (dword *)(pfVar16 + 2);
      pdVar17 = (dword *)(pfVar16 + 3);
      break;
    case 5:
      pfVar16 = (float *)(uVar20 * 0x80 + 0x2510 + *(int *)(param_1 + 0x10));
      pdVar21 = (dword *)(pfVar16 + 1);
      pdVar9 = (dword *)(pfVar16 + 2);
      pdVar17 = (dword *)(pfVar16 + 3);
      break;
    case 6:
      iVar23 = uVar20 * 0x80 + *(int *)(param_1 + 0x10);
      fVar2 = *(float *)(iVar23 + 0x24f4);
      fVar3 = *(float *)(iVar23 + 0x24f0);
      fVar4 = *(float *)(iVar23 + 0x24f8) + FLOAT_001aa0e8;
      fparam_1 = _sqrt((double)(fVar4 * fVar4 + fVar3 * fVar3 + fVar2 * fVar2));
      local_84[0] = fVar6;
      fVar6 = (float)(DOUBLE_001aa200 / fparam_1);
      local_88 = fVar4 * fVar6;
      local_90 = fVar3 * fVar6;
      local_8c = fVar2 * fVar6;
      goto LAB_00025ac8;
    case 7:
      pfVar16 = (float *)(uVar20 * 0x80 + 0x2530 + *(int *)(param_1 + 0x10));
      pdVar21 = (dword *)(pfVar16 + 1);
      pdVar9 = (dword *)(pfVar16 + 2);
      pdVar17 = (dword *)(pfVar16 + 3);
      break;
    default:
      goto switchD_00025774_caseD_1;
    }
    break;
  case 4:
    uVar20 = uVar15 >> 9 & 3;
    iVar12 = *(int *)(param_1 + 0x10) + 0x24c0;
    iVar23 = (uVar15 & 0xff) * 0x80;
    iVar10 = (uVar15 >> 8 & 1) * 0x240;
    iVar11 = *(int *)(param_1 + 0x10) + 0x28c0;
    iVar18 = iVar12 + iVar23;
    iVar13 = iVar11 + iVar10;
    if (uVar20 == 1) {
      local_90 = *(float *)(iVar18 + 0x10) * *(float *)(iVar13 + 0x10);
      local_8c = *(float *)(iVar18 + 0x14) * *(float *)(iVar13 + 0x14);
      local_88 = *(float *)(iVar18 + 0x18) * *(float *)(iVar13 + 0x18);
      local_84[0] = *(float *)(iVar13 + 0x1c);
    }
    else if (uVar20 == 2) {
      local_90 = *(float *)(iVar18 + 0x20) * *(float *)(iVar13 + 0x20);
      local_8c = *(float *)(iVar18 + 0x24) * *(float *)(iVar13 + 0x24);
      local_88 = *(float *)(iVar18 + 0x28) * *(float *)(iVar13 + 0x28);
      local_84[0] = *(float *)(iVar13 + 0x2c);
    }
    else {
      if (uVar20 != 0) goto switchD_00025774_caseD_1;
      local_90 = *(float *)(iVar12 + iVar23) * *(float *)(iVar11 + iVar10);
      local_8c = *(float *)(iVar18 + 4) * *(float *)(iVar13 + 4);
      local_88 = *(float *)(iVar18 + 8) * *(float *)(iVar13 + 8);
      local_84[0] = *(float *)(iVar13 + 0xc);
    }
    goto LAB_00025ac8;
  case 5:
    uVar20 = uVar15 & 1;
    switch(uVar15 >> 1 & 7) {
    case 0:
      pfVar16 = (float *)(uVar20 * 0x240 + 0x28c0 + *(int *)(param_1 + 0x10));
      pdVar21 = (dword *)(pfVar16 + 1);
      pdVar9 = (dword *)(pfVar16 + 2);
      pdVar17 = (dword *)(pfVar16 + 3);
      break;
    case 1:
      pfVar16 = (float *)(uVar20 * 0x240 + 0x28d0 + *(int *)(param_1 + 0x10));
      pdVar21 = (dword *)(pfVar16 + 1);
      pdVar9 = (dword *)(pfVar16 + 2);
      pdVar17 = (dword *)(pfVar16 + 3);
      break;
    case 2:
      pfVar16 = (float *)(uVar20 * 0x240 + 0x28e0 + *(int *)(param_1 + 0x10));
      pdVar21 = (dword *)(pfVar16 + 1);
      pdVar9 = (dword *)(pfVar16 + 2);
      pdVar17 = (dword *)(pfVar16 + 3);
      break;
    case 3:
      pfVar16 = (float *)(uVar20 * 0x240 + 0x28f0 + *(int *)(param_1 + 0x10));
      pdVar21 = (dword *)(pfVar16 + 1);
      pdVar9 = (dword *)(pfVar16 + 2);
      pdVar17 = (dword *)(pfVar16 + 3);
      break;
    case 4:
      pfVar16 = (float *)(uVar20 * 0x240 + 0x2900 + *(int *)(param_1 + 0x10));
      pdVar21 = (dword *)(pfVar16 + 1);
      pdVar9 = (dword *)(pfVar16 + 2);
      pdVar17 = (dword *)(pfVar16 + 3);
      break;
    case 5:
      iVar23 = *(int *)(param_1 + 0x10);
      iVar10 = iVar23 + 0x28c0 + uVar20 * 0x240;
      local_90 = *(float *)(iVar23 + 0x24b0) * *(float *)(iVar23 + 0x28c0 + uVar20 * 0x240) +
                 *(float *)(iVar10 + 0x30);
      local_8c = *(float *)(iVar23 + 0x24b4) * *(float *)(iVar10 + 4) + *(float *)(iVar10 + 0x34);
      local_88 = *(float *)(iVar23 + 0x24b8) * *(float *)(iVar10 + 8) + *(float *)(iVar10 + 0x38);
      local_84[0] = *(float *)(iVar10 + 0x1c);
      goto LAB_00025ac8;
    default:
      goto switchD_00025774_caseD_1;
    }
    break;
  case 6:
    iVar23 = *(int *)(param_1 + 0x10);
    pdVar17 = (dword *)(iVar23 + 0x24bc);
    pfVar16 = (float *)(iVar23 + 0x24b0);
    pdVar21 = (dword *)(iVar23 + 0x24b4);
    pdVar9 = (dword *)(iVar23 + 0x24b8);
    break;
  case 7:
    uVar20 = uVar15 >> 5 & 7;
    uVar15 = uVar15 & 0x1f;
    if (uVar20 == 1) {
      iVar23 = *(int *)(param_1 + 0x10);
      puVar8 = ((unsigned char *)0x000039a0) + uVar15 * 0x94;
LAB_00025180:
      pdVar17 = (dword *)(puVar8 + iVar23 + 0x1c);
      pfVar16 = (float *)(puVar8 + iVar23 + 0x10);
      pdVar21 = (dword *)(puVar8 + iVar23 + 0x14);
      pdVar9 = (dword *)(puVar8 + iVar23 + 0x18);
    }
    else {
      if (uVar20 < 2) {
        if (uVar20 == 0) {
          iVar23 = *(int *)(param_1 + 0x10);
          puVar8 = ((unsigned char *)0x00003980) + uVar15 * 0x94;
          goto LAB_0002515c;
        }
        goto switchD_00025774_caseD_1;
      }
      if (uVar20 == 2) {
        iVar23 = *(int *)(param_1 + 0x10);
        puVar8 = ((unsigned char *)0x000039c0) + uVar15 * 0x94;
LAB_000251a4:
        pdVar17 = (dword *)(puVar8 + iVar23 + 0x20);
        pfVar16 = (float *)(puVar8 + iVar23 + 0x14);
        pdVar21 = (dword *)(puVar8 + iVar23 + 0x18);
        pdVar9 = (dword *)(puVar8 + iVar23 + 0x1c);
      }
      else {
        if (uVar20 != 3) goto switchD_00025774_caseD_1;
        iVar23 = *(int *)(param_1 + 0x10);
        puVar8 = ((unsigned char *)0x000039e0) + uVar15 * 0x94;
LAB_000251c8:
        pdVar17 = (dword *)(puVar8 + iVar23 + 0x24);
        pfVar16 = (float *)(puVar8 + iVar23 + 0x18);
        pdVar21 = (dword *)(puVar8 + iVar23 + 0x1c);
        pdVar9 = (dword *)(puVar8 + iVar23 + 0x20);
      }
    }
    break;
  case 8:
    uVar20 = uVar15 >> 5 & 7;
    uVar15 = uVar15 & 0x1f;
    if (uVar20 == 1) {
      iVar23 = *(int *)(param_1 + 0x10);
      puVar8 = ((unsigned char *)0x000039b0) + uVar15 * 0x94;
      goto LAB_00025180;
    }
    if (uVar20 < 2) {
      if (uVar20 == 0) {
        iVar23 = *(int *)(param_1 + 0x10);
        puVar8 = ((unsigned char *)0x00003990) + uVar15 * 0x94;
        goto LAB_0002515c;
      }
    }
    else {
      if (uVar20 == 2) {
        iVar23 = *(int *)(param_1 + 0x10);
        puVar8 = ((unsigned char *)0x000039d0) + uVar15 * 0x94;
        goto LAB_000251a4;
      }
      if (uVar20 == 3) {
        iVar23 = *(int *)(param_1 + 0x10);
        puVar8 = ((unsigned char *)0x000039f0) + uVar15 * 0x94;
        goto LAB_000251c8;
      }
    }
    goto switchD_00025774_caseD_1;
  case 9:
    iVar23 = *(int *)(param_1 + 0x10) + (uVar15 & 0x1f) * 0x7c;
    pfVar16 = (float *)(((unsigned char *)0x000031c0) + iVar23 + 4);
    pdVar17 = (dword *)(((unsigned char *)0x000031c0) + iVar23 + 0x10);
    pdVar9 = (dword *)(((unsigned char *)0x000031c0) + iVar23 + 0xc);
    pdVar21 = (dword *)(((unsigned char *)0x000031c0) + iVar23 + 8);
    break;
  case 10:
    iVar23 = *(int *)(param_1 + 0x10);
    puVar8 = ((unsigned char *)0x00003e20) + (uVar15 & 0xff) * 0x10;
LAB_0002515c:
    pdVar17 = (dword *)(puVar8 + iVar23 + 0x18);
    pfVar16 = (float *)(puVar8 + iVar23 + 0xc);
    pdVar21 = (dword *)(puVar8 + iVar23 + 0x10);
    pdVar9 = (dword *)(puVar8 + iVar23 + 0x14);
    break;
  case 0xb:
    iVar23 = *(int *)(param_1 + 0x10);
    pdVar17 = (dword *)(((unsigned char *)0x00002dec) + iVar23);
    pfVar16 = (float *)(((unsigned char *)0x00002de0) + iVar23);
    pdVar21 = (dword *)(((unsigned char *)0x00002de4) + iVar23);
    pdVar9 = (dword *)(((unsigned char *)0x00002de8) + iVar23);
    break;
  case 0xc:
    iVar23 = *(int *)(param_1 + 0x10);
    pdVar17 = (dword *)(((unsigned char *)0x00002dfc) + iVar23);
    pfVar16 = (float *)(((unsigned char *)0x00002df0) + iVar23);
    pdVar21 = (dword *)(((unsigned char *)0x00002df4) + iVar23);
    pdVar9 = (dword *)(((unsigned char *)0x00002df8) + iVar23);
    break;
  case 0xd:
    iVar23 = *(int *)(param_1 + 0x10);
    pdVar17 = (dword *)(((unsigned char *)0x000030c8) + iVar23);
    pfVar16 = (float *)(((unsigned char *)0x000030bc) + iVar23);
    pdVar21 = (dword *)(((unsigned char *)0x000030c0) + iVar23);
    pdVar9 = (dword *)(((unsigned char *)0x000030c4) + iVar23);
    break;
  case 0xe:
    iVar23 = *(int *)(param_1 + 0x10);
    pdVar17 = (dword *)(((unsigned char *)0x000030d8) + iVar23);
    pfVar16 = (float *)(((unsigned char *)0x000030cc) + iVar23);
    pdVar21 = (dword *)(((unsigned char *)0x000030d0) + iVar23);
    pdVar9 = (dword *)(((unsigned char *)0x000030d4) + iVar23);
    break;
  case 0xf:
    iVar23 = *(int *)(param_1 + 0x10);
    local_90 = (float)*(double *)(0x00001830 + iVar23);
    local_8c = (float)*(double *)(iVar23 + 0x1838);
    local_84[0] = 1.0;
    local_88 = (float)(*(double *)(iVar23 + 0x1838) - *(double *)(0x00001830 + iVar23));
    goto LAB_00025ac8;
  case 0x12:
    local_84[0] = *(float *)(*(int *)(param_1 + 0x10) + 0x24a4);
    local_90 = local_84[0];
    local_8c = local_84[0];
    local_88 = local_84[0];
    goto LAB_00025ac8;
  }
LAB_00025aa8:
  local_90 = *pfVar16;
  local_8c = (float)*pdVar21;
  local_88 = (float)*pdVar9;
  local_84[0] = (float)*pdVar17;
LAB_00025ac8:
  param_3[1] = local_8c;
  param_3[2] = local_88;
  *param_3 = local_90;
  param_3[3] = local_84[0];
LAB_00025af0:
  iVar25 = iVar25 + 1;
  puVar27 = puVar27 + 2;
  param_3 = param_3 + 4;
  if (iVar19 == iVar25) goto LAB_00025b04;
  goto LAB_00025090;
switchD_00025774_caseD_1:
  pfVar16 = (float *)0x0;
  pdVar21 = ((unsigned char *)0x4);
  pdVar9 = ((unsigned char *)0x8);
  pdVar17 = ((unsigned char *)0xc);
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
    _pthread_mutex_lock(*(undefined4 *)(param_1 + 0xc));
    if (*(int *)(param_2 + 0x2c) != 0) {
      _glpFreePPShaderLinearize(*(int *)(param_2 + 0x2c));
      *(undefined4 *)(param_2 + 0x2c) = 0;
    }
    if (*(int *)(param_2 + 0x30) != 0) {
      _glpFreePPShaderToProgram(*(int *)(param_2 + 0x30));
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
    _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
    return;
  }
  return;
}

/* FUN_00025da0 @ 0x25da0 (264 bytes) */
int FUN_00025da0(param_1)
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  _pthread_mutex_lock(*(undefined4 *)(param_1 + 0xc));
  iVar2 = *(int *)(param_1 + 0xc);
  iVar4 = *(int *)(iVar2 + 0x30);
  if (iVar2 + 0x2c != iVar4) {
    do {
      for (piVar5 = *(int **)(iVar4 + 0x18); piVar5 != (int *)(iVar4 + 0x14);
          piVar5 = (int *)piVar5[1]) {
        iVar3 = piVar5[2];
        if (param_1 == iVar3) {
          iVar1 = *(int *)(iVar4 + 0x10);
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
      iVar4 = *(int *)(iVar4 + 4);
    } while (iVar2 + 0x2c != iVar4);
    iVar2 = *(int *)(param_1 + 0xc);
  }
  _pthread_mutex_unlock(iVar2);
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
  bool bVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined4 in_r6;
  undefined4 in_r7;
  int in_r8;
  int in_r9;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  byte *pbVar13;
  int *piVar14;
  int *piVar15;
  
  piVar15 = (int *)(param_1 + 0x240);
  for (piVar6 = (int *)param_2[9]; piVar6 != param_2 + 8; piVar6 = (int *)piVar6[1]) {
    if (param_1 == piVar6[2]) goto LAB_00025f80;
  }
  piVar6 = (int *)_calloc(1,*(int *)(&DAT_001aa4c4 + param_2[7] * 4) + 0x14);
  piVar6[3] = param_2[5] + -1;
  iVar9 = param_2[6];
  piVar6[2] = param_1;
  piVar6[1] = (int)(param_2 + 8);
  in_r9 = iVar9 + -1;
  piVar6[4] = in_r9;
  *piVar6 = param_2[8];
  param_2[8] = (int)piVar6;
  *(int **)(*piVar6 + 4) = piVar6;
LAB_00025f80:
  iVar9 = piVar6[5];
  piVar14 = piVar6 + 5;
  if (iVar9 == 0) {
    FUN_000a0570(piVar15,1,piVar14);
    iVar9 = piVar6[5];
    if (iVar9 != 0) goto LAB_00025fac;
LAB_000263d8:
    uVar8 = 0;
  }
  else {
LAB_00025fac:
    FUN_000a0380(piVar15,0x8804,iVar9,in_r6,in_r7,in_r8,in_r9);
    if (piVar6[3] == param_2[5]) {
      pbVar13 = (byte *)param_2[0xe];
      if (pbVar13 != (byte *)0x0) {
        uVar11 = *(uint *)(pbVar13 + 0x20);
        uVar5 = uVar11 >> 0x1b;
        in_r8 = *(int *)(*param_2 + 0x18);
        if (uVar5 == 0) {
LAB_00026008:
          bVar3 = false;
        }
        else {
          if ((uint)pbVar13[1] == *(uint *)(in_r8 + (uint)*pbVar13 * 0x10)) {
            do {
              uVar5 = uVar5 - 1;
              if (uVar5 == 0) goto LAB_00026008;
              pbVar1 = pbVar13 + 2;
              pbVar2 = pbVar13 + 3;
              pbVar13 = pbVar13 + 2;
            } while ((uint)*pbVar2 == *(uint *)(in_r8 + (uint)*pbVar1 * 0x10));
          }
          bVar3 = true;
        }
        if (((((uVar11 & 0x1000000) != 0) &&
             ((uVar11 >> 0x17 & 1) != (uint)(byte)((unsigned char *)0x00002b7c)[param_1])) ||
            (((uVar11 & 0x400000) == 0 &&
             ((uVar11 >> 0x12 & 0xf) != (*(uint *)(param_1 + 0x1ae4) >> 6 & 0xffff))))) || (bVar3))
        {
          uVar5 = param_2[0xf];
          param_2[0xf] = uVar5 | 1;
          param_2[5] = param_2[5] + 1;
          if ((uVar5 & 2) != 0) {
            param_2[6] = param_2[6] + 1;
          }
          param_2[0xf] = 0;
          bVar3 = piVar6[3] != param_2[5];
          if (bVar3) {
            piVar6[3] = param_2[5];
          }
          goto LAB_000260dc;
        }
      }
LAB_000263c0:
      if (*(char *)(param_2 + 10) != '\0') goto LAB_000263d8;
    }
    else {
      piVar6[3] = param_2[5];
      bVar3 = true;
LAB_000260dc:
      if (!bVar3) goto LAB_000263c0;
      *(undefined1 *)(param_2 + 10) = 0;
      if (param_2[0xb] != 0) {
        _glpFreePPShaderLinearize(param_2[0xb]);
        param_2[0xb] = 0;
      }
      if (param_2[0xc] != 0) {
        _glpFreePPShaderToProgram(param_2[0xc]);
        param_2[0xc] = 0;
      }
      if (param_2[0xd] != 0) {
        param_2[0xd] = 0;
      }
      bVar3 = false;
      uVar5 = 0x1f9;
      FUN_0003f5d0(param_2[0xe]);
      param_2[0xe] = 0;
      while( true ) {
        if (*(short *)*param_2 == -0x74d0) {
          iVar9 = _glpPPShaderLinearize(*(undefined4 *)((short *)*param_2 + 2),uVar5);
          param_2[0xb] = iVar9;
        }
        piVar7 = (int *)FUN_0003f660();
        iVar9 = param_2[0xd];
        if (((iVar9 == 0) && (iVar9 = param_2[0xc], iVar9 == 0)) &&
           (iVar9 = param_2[0xb], iVar9 == 0)) {
          iVar9 = *(int *)(*param_2 + 4);
        }
        *piVar7 = iVar9;
        iVar12 = *(int *)(*param_2 + 0xc);
        piVar7[1] = *(int *)(*param_2 + 8);
        piVar7[2] = iVar12;
        piVar7[3] = *(int *)(*param_2 + 0x18);
        *(uint *)(piVar7[0xd] + 0x20) =
             ((byte)((unsigned char *)0x00002b7c)[param_1] & 1) << 0x17 |
             *(uint *)(piVar7[0xd] + 0x20) & 0xff7fffff;
        iVar10 = piVar7[0xd];
        *(uint *)(iVar10 + 0x20) =
             (*(uint *)(param_1 + 0x1ae4) & 0x3c0) << 0xc | *(uint *)(iVar10 + 0x20) & 0xffc3ffff;
        iVar9 = FUN_00048da0(piVar7);
        if (iVar9 == 0) {
          *piVar15 = 0;
          FUN_0008e2e0(piVar15,0,piVar7[0xb],piVar7[10]);
          bVar3 = *piVar15 == 0;
          bVar4 = !bVar3;
          if (!bVar4) {
            iVar9 = piVar7[0xd];
            piVar7[0xd] = *piVar15;
            param_2[0xe] = iVar9;
            goto LAB_0002639c;
          }
        }
        else {
          bVar4 = !bVar3;
          if (!bVar4) goto LAB_0002639c;
        }
        if ((*(short *)*param_2 != -0x74d0) || ((uVar5 & 6) == 6)) break;
        if ((uVar5 & 4) == 0) {
          uVar5 = uVar5 | 4;
        }
        else if ((uVar5 & 2) == 0) {
          uVar5 = uVar5 & 0xfffffffb | 2;
        }
        if (param_2[0xb] != 0) {
          _glpFreePPShaderLinearize(param_2[0xb]);
          param_2[0xb] = 0;
        }
        if (param_2[0xc] != 0) {
          _glpFreePPShaderToProgram(param_2[0xc]);
          param_2[0xc] = 0;
        }
        if (param_2[0xd] != 0) {
          param_2[0xd] = 0;
        }
        FUN_0003f5d0(param_2[0xe]);
        param_2[0xe] = 0;
        FUN_0003f5e0(piVar7);
      }
      if (bVar4) {
        if (*(short *)*param_2 == -0x74d0) {
          bVar4 = true;
        }
        else {
          *piVar15 = 0;
          iVar9 = param_2[0xd];
          if (((iVar9 == 0) && (iVar9 = param_2[0xc], iVar9 == 0)) &&
             (iVar9 = param_2[0xb], iVar9 == 0)) {
            iVar9 = *(int *)(*param_2 + 4);
          }
          iVar9 = FUN_0000f620(iVar9);
          if (iVar9 == 0) {
            FUN_000a0d70(piVar15,1,piVar14);
            *piVar14 = 0;
            return 0;
          }
          uVar8 = _strlen(iVar9);
          FUN_000a0300(piVar15,0x8804,0x8875,uVar8,iVar9,in_r8,iVar10,iVar12);
          _free(iVar9);
          bVar4 = *piVar15 != 0;
        }
      }
      else {
        bVar4 = false;
      }
LAB_0002639c:
      FUN_0003f5e0(piVar7);
      if (bVar4) {
        *(undefined1 *)(param_2 + 10) = 1;
        return 0;
      }
    }
    uVar8 = 1;
    *(int **)(param_1 + 0x29ec) = piVar6;
  }
  return uVar8;
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
  piVar1 = (int *)_calloc(1,*(int *)(&DAT_001aa4c4 + param_2[7] * 4) + 0x14);
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
        _glpFreePPShaderLinearize(param_2[0xb]);
        param_2[0xb] = 0;
      }
      if (param_2[0xc] != 0) {
        _glpFreePPShaderToProgram(param_2[0xc]);
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
        piVar5 = (int *)_calloc(1,*(int *)(&DAT_001aa4c4 + param_2[7] * 4) + 0x14);
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
  undefined4 uVar3;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar4;
  
  uVar3 = param_3;
  piVar1 = param_4;
  _pthread_mutex_lock(*(undefined4 *)(param_1 + 0xc));
  if (((param_2 != (int *)0x0) && (*param_2 != 0)) && (*(int *)(*param_2 + 4) != 0)) {
    FUN_0000a820(param_1,0xffff,uVar3,piVar1,in_r7,in_r8);
    FUN_000a7ee0(param_1,0xffff);
    ((int (*)())FUN_00026650)(param_1,param_2);
    psVar2 = (short *)*param_2;
    if (psVar2[1] == 0) {
      if (*psVar2 == -0x79e0) {
        for (piVar1 = (int *)param_2[9]; piVar1 != param_2 + 8; piVar1 = (int *)piVar1[1]) {
          if (param_1 == piVar1[2]) goto LAB_00026ae0;
        }
        piVar1 = (int *)_calloc(1,*(int *)(&DAT_001aa4c4 + param_2[7] * 4) + 0x14);
        piVar1[3] = param_2[5] + -1;
        iVar4 = param_2[6];
        piVar1[2] = param_1;
        piVar1[1] = (int)(param_2 + 8);
        piVar1[4] = iVar4 + -1;
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
  _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
  return;
}

/* FUN_00026bf0 @ 0x26bf0 (876 bytes) */
int FUN_00026bf0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  undefined4 param_2;
  int param_3;
  int param_4;
  undefined4 param_5;
{
  byte bVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  int iVar12;
  
  if (param_4 < 4) {
    iVar5 = ((int (*)())FUN_0002bf30)(param_1,param_3,param_4);
  }
  else {
    iVar5 = ((int (*)())FUN_0002bea0)(param_1,param_3,param_4);
  }
  if (iVar5 == 0) {
    return;
  }
  if ((*(uint *)(param_1 + 0x27d8) & 6) == 0) {
    if (*(char *)(param_1 + 0x27d4) == '\0') {
      bVar1 = *(byte *)(*(int *)(((unsigned char *)0x000027cc) + param_1) + 2);
    }
    else {
      bVar1 = *(byte *)(*(int *)(0x000027d0 + param_1) + 2);
    }
    puVar6 = *(undefined4 **)(param_1 + 0x1dc);
    *(undefined4 **)(param_1 + 0x298c) = puVar6;
    if (*(char *)(param_1 + 0x27d4) == '\0') {
      iVar7 = param_1 + 0x2840;
      if (*(int *)(param_1 + 0x2680) != iVar7) {
        uVar10 = *(undefined4 *)(param_1 + 0x28e0);
        iVar12 = param_1 + 0x2860;
        goto LAB_00026ea8;
      }
    }
    else {
      iVar7 = param_1 + 0x28e4;
      if (*(int *)(param_1 + 0x2680) != iVar7) {
        uVar10 = *(undefined4 *)(param_1 + 0x2984);
        iVar12 = param_1 + 0x2904;
LAB_00026ea8:
        *(int *)(param_1 + 0x2680) = iVar7;
        *(int *)(param_1 + 0x2684) = iVar12;
        *(undefined4 *)(0x000026c8 + param_1 + 4) = uVar10;
        puVar6 = (undefined4 *)((int (*)())FUN_0002c0c0)(param_1,puVar6);
      }
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      *puVar6 = 0x5c8;
      puVar6[1] = 0x10000000;
      puVar6 = puVar6 + 2;
      *(undefined1 *)(param_1 + 0x2a42) = 1;
    }
    iVar7 = (uint)bVar1 * iVar5;
    *puVar6 = 0x82c;
    puVar6[1] = *(undefined4 *)(0x00001dc4 + param_1);
    uVar11 = *(uint *)(&DAT_001d9888 + param_3 * 4);
    puVar6[2] = iVar7 * 0x10000 | 0xc0003500;
    puVar6[3] = iVar5 << 0x10 | uVar11 & 0xf | 0x30;
    puVar6[iVar7 + 4] = ((unsigned char *)0x00001393U);
    puVar6[iVar7 + 5] = 0;
    *(undefined4 **)(param_1 + 0x298c) = puVar6 + iVar7 + 6;
    *(undefined4 **)(param_1 + 0x1dc) = puVar6 + iVar7 + 6;
    goto LAB_00026f60;
  }
  uVar11 = *(uint *)(param_1 + 0x283c) & 0x1f;
  if (*(char *)(param_1 + 0x27d4) == '\0') {
    bVar1 = *(byte *)(*(int *)(((unsigned char *)0x000027cc) + param_1) + 2);
  }
  else {
    bVar1 = *(byte *)(*(int *)(0x000027d0 + param_1) + 2);
  }
  iVar12 = *(int *)(param_1 + 0x1ec);
  puVar6 = *(undefined4 **)(param_1 + 0x1dc);
  iVar7 = (uint)bVar1 * iVar5 * 4;
  *(int *)(param_1 + 0x1ec) = iVar12 + iVar7;
  *(undefined4 **)(param_1 + 0x298c) = puVar6;
  puVar3 = *(uint **)(param_1 + 0x1d8);
  *puVar3 = (int)puVar6 - (int)puVar3 >> 2 | *puVar3;
  *(undefined4 **)(param_1 + 0x1d8) = puVar6;
  puVar6[1] = uVar11;
  puVar6[2] = iVar12 - (int)puVar6 >> 2;
  *puVar6 = 0x38000000;
  puVar6[3] = 0;
  if (*(char *)(param_1 + 0x27d4) == '\0') {
    *(int *)(param_1 + 0x26d4) = param_1 + 0x2880;
    *(int *)(param_1 + 0x26d8) = param_1 + 0x28a0;
    *(undefined4 *)(param_1 + 0x26d0) = *(undefined4 *)(param_1 + 0x283c);
    puVar6 = (undefined4 *)((int (*)())FUN_0002c180)(param_1,puVar6 + 4);
    iVar4 = param_1 + 0x2840;
    if (*(int *)(param_1 + 0x2680) != iVar4) {
      iVar2 = param_1 + 0x2860;
      goto LAB_00026d64;
    }
  }
  else {
    *(int *)(param_1 + 0x26d4) = param_1 + 0x2924;
    *(int *)(param_1 + 0x26d8) = param_1 + 0x2944;
    *(undefined4 *)(param_1 + 0x26d0) = *(undefined4 *)(param_1 + 0x283c);
    puVar6 = (undefined4 *)((int (*)())FUN_0002c180)(param_1,puVar6 + 4);
    iVar4 = param_1 + 0x28e4;
    if (*(int *)(param_1 + 0x2680) != iVar4) {
      iVar2 = param_1 + 0x2904;
LAB_00026d64:
      *(int *)(param_1 + 0x2680) = iVar4;
      *(int *)(param_1 + 0x2684) = iVar2;
      puVar6 = (undefined4 *)((int (*)())FUN_0002c0c0)(param_1,puVar6);
    }
  }
  if (*(char *)(param_1 + 0x2a42) != '\0') {
    *puVar6 = 0x5c8;
    puVar6[1] = 0x10000000;
    puVar6 = puVar6 + 2;
    *(undefined1 *)(param_1 + 0x2a42) = 0;
  }
  puVar8 = puVar6 + 6;
  uVar9 = *(uint *)(&DAT_001d9888 + param_3 * 4);
  *puVar6 = 0x82c;
  uVar10 = *(undefined4 *)(0x00001dc4 + param_1);
  puVar6[4] = ((unsigned char *)0x00001393U);
  puVar6[2] = 0xc0003400;
  puVar6[5] = 0;
  puVar6[1] = uVar10;
  puVar6[3] = iVar5 << 0x10 | uVar9 & 0xf | 0x820;
  *(undefined4 **)(param_1 + 0x298c) = puVar8;
  *(undefined4 **)(param_1 + 0x1dc) = puVar8;
  if (((*(uint *)(param_1 + 0x27d8) & 2) != 0) && ((*(uint *)(param_1 + 0x24) & 2) != 0)) {
    FUN_0000b620(param_1,iVar12,iVar7,param_4,param_5,uVar11,0xc0003400,puVar8);
  }
LAB_00026f60:
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  return;
}

/* FUN_00026f80 @ 0x26f80 (460 bytes) */
void FUN_00026f80(int param_1,uint *param_2,uint *param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  double in_stack_ffffff98;
  undefined4 uStack_38;
  int iStack_34;
  uint uStack_30;
  
  puVar4 = param_3;
  if (((unsigned char *)0x00002b80)[param_1] != '\0') {
    puVar4 = param_2;
    fparam_1 = (double)((int (*)())FUN_0002be90)(param_1,1,param_2,param_4,param_5,param_6,param_7);
  }
  if (*(int *)(param_1 + 0x1b68) != 0) {
    ((void (*)())FUN_0002c020)(param_1 + 0x240,param_2,puVar4,param_4,param_5,param_6,param_7,fparam_1,fparam_2,
                 fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff98);
  }
  if ((*param_3 == 0) || (*(int *)(*(int *)(param_1 + 0x14) + 0x120) == 0)) {
    bVar1 = *(byte *)(*(int *)(((unsigned char *)0x000027cc) + param_1) + 2);
    *(undefined1 *)(param_1 + 0x27d4) = 0;
  }
  else {
    bVar1 = *(byte *)(*(int *)(0x000027d0 + param_1) + 2);
    *(undefined1 *)(param_1 + 0x27d4) = 1;
  }
  iVar6 = *(int *)(param_1 + 500);
  uVar5 = *(uint *)(param_1 + 0x1f8);
  if (uVar5 <= (uint)bVar1 * 0x90 + iVar6 + 0x80) {
    uStack_38 = 2;
    uVar5 = *(int *)(param_1 + 0x204) + 1;
    *(uint *)(param_1 + 0x204) = uVar5;
    if (2 < uVar5) {
      if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
        FUN_0001a0f0(param_1,0x1000000);
        iVar6 = *(int *)(param_1 + 500);
      }
      *(undefined4 *)(param_1 + 0x204) = 1;
    }
    *(int *)(*(int *)(param_1 + 0x208) + 0xc) = iVar6 - *(int *)(param_1 + 0x1fc) >> 2;
    _io_connect_method_scalarI_scalarO(*(undefined4 *)(param_1 + 4),0x12,0,0,&iStack_34,&uStack_38);
    uVar3 = *(uint *)(0x000026c8 + param_1);
    *(int *)(param_1 + 0x1fc) = iStack_34;
    uVar5 = iStack_34 + (uStack_30 & 0xfffffffc);
    *(int *)(param_1 + 500) = iStack_34;
    *(uint *)(param_1 + 0x1f8) = uVar5;
    uVar2 = *(undefined4 *)(*(int *)(param_1 + 0x208) + 8);
    *(uint *)(0x000026c8 + param_1) = uVar3 | 1;
    *(undefined4 *)(param_1 + 0x200) = uVar2;
    iVar6 = iStack_34;
  }
  uVar3 = iVar6 + 0x7fU & 0xffffff80;
  *(uint *)(param_1 + 500) = uVar3;
  uVar3 = (((uint)((int)(uVar5 - uVar3) >> 2) / (uint)bVar1) / 0xc) * 0xc;
  uVar5 = 0xfffc;
  if (uVar3 < 0x10000) {
    uVar5 = uVar3;
  }
  *param_3 = uVar5;
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
      bVar1 = *(byte *)(*(int *)(0x000027d0 + param_1) + 2);
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
    uVar4 = *(undefined4 *)(0x00001dc4 + param_1);
    puVar7[4] = ((unsigned char *)0x00001393U);
    puVar7[2] = 0xc0003400;
    puVar7[5] = 0;
    puVar7[1] = uVar4;
    puVar7[3] = iVar5 << 0x10 | uVar2 & 0xf | 0x820;
    *(undefined4 **)(param_1 + 0x1dc) = puVar7 + 6;
  }
  return;
}

/* FUN_000273a0 @ 0x273a0 (1484 bytes) */
uint FUN_000273a0(int param_1,uint *param_2,uint *param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  byte bVar1;
  bool bVar2;
  undefined1 uVar4;
  undefined4 *puVar3;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  undefined4 *puVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  double in_stack_ffffff98;
  
  puVar7 = param_3;
  if (((unsigned char *)0x00002b80)[param_1] != '\0') {
    puVar7 = param_2;
    fparam_1 = (double)((int (*)())FUN_0002be90)(param_1,1,param_2,param_4,param_5,param_6,param_7);
  }
  if (*(int *)(param_1 + 0x1b68) != 0) {
    ((void (*)())FUN_0002c020)(param_1 + 0x240,param_2,puVar7,param_4,param_5,param_6,param_7,fparam_1,fparam_2,
                 fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffff98);
  }
  if ((*param_3 == 0) || (*(int *)(*(int *)(param_1 + 0x14) + 0x120) == 0)) {
    bVar2 = false;
    uVar4 = 0;
    bVar1 = *(byte *)(*(int *)(((unsigned char *)0x000027cc) + param_1) + 2);
  }
  else {
    bVar2 = true;
    uVar4 = 1;
    bVar1 = *(byte *)(*(int *)(0x000027d0 + param_1) + 2);
  }
  uVar16 = (uint)bVar1;
  *(undefined1 *)(param_1 + 0x27d4) = uVar4;
  uVar5 = *(uint *)(param_1 + 0x27d8);
  if (!bVar2) {
    if ((uVar5 & 0x10) != 0) goto LAB_00027478;
LAB_00027458:
    uVar9 = 1;
  }
  else {
    if ((uVar5 & 8) == 0) goto LAB_00027458;
LAB_00027478:
    uVar9 = 2;
  }
  uVar15 = uVar9 | uVar5 & 0x18;
  if (uVar5 != uVar15) {
    *(int *)(param_1 + 0x2680) = param_1 + 0x26dc;
  }
  if ((uVar9 & 2) == 0) {
    if (*(char *)(param_1 + 0x27d4) == '\0') {
      if (*(int *)(param_1 + 0x2680) != param_1 + 0x2840) goto LAB_000276e0;
LAB_000276f8:
      iVar12 = 2;
      iVar11 = 4;
    }
    else {
      if (*(int *)(param_1 + 0x2680) == param_1 + 0x28e4) goto LAB_000276f8;
LAB_000276e0:
      uVar5 = *(int *)(param_1 + 0x267c) + 1U & 0xfffffffe;
      iVar11 = uVar5 + 8;
      iVar12 = uVar5 + 6;
    }
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      iVar11 = iVar12 + 4;
    }
    if ((int)*param_3 < 0xc) {
      uVar5 = uVar16 * 0xc;
      uVar10 = 0xc;
    }
    else {
      uVar10 = ((int)*param_3 / 0xc) * 0xc;
      uVar5 = uVar16 * uVar10;
      if (0x3fff < uVar5) {
        uVar10 = ((0x3fff / uVar16) / 0xc) * 0xc;
        uVar5 = uVar16 * uVar10;
      }
    }
    puVar14 = *(undefined4 **)(param_1 + 0x1dc);
    if (*(undefined4 **)(param_1 + 0x1e0) <=
        puVar14 + uVar5 + iVar11 + 2 + (uint)(*(byte *)(param_1 + 8) >> 1) + 4) {
      FUN_0001a0f0(param_1,0x1000000);
      puVar14 = *(undefined4 **)(param_1 + 0x1dc);
    }
    uVar5 = (int)puVar14 + iVar11 * 4 + 0xf & 0xfffffff0;
    puVar3 = (undefined4 *)(uVar5 + iVar11 * -4);
    *(undefined4 **)(param_1 + 0x1dc) = puVar3;
    for (; puVar14 < puVar3; puVar14 = puVar14 + 1) {
      *puVar14 = 0x80000000;
    }
    if (*param_3 != 0) goto LAB_00027854;
    uVar8 = (((*(int *)(param_1 + 0x1e0) - *(int *)(param_1 + 0x1dc) >> 2) + -1) -
            (uint)(*(byte *)(param_1 + 8) >> 1)) - (iVar11 + 2);
    if (0x600 < uVar8) {
      uVar8 = 0x600;
    }
  }
  else {
    uVar5 = *param_3;
    uVar10 = 0x8b;
    if ((uVar5 != 0) && (uVar10 = 0x1000a, uVar5 < 0x10000)) {
      uVar10 = uVar5 + 0xb;
    }
    uVar8 = (uint)*(byte *)(param_1 + 8);
    iVar12 = 0xc;
    uVar10 = (uVar10 / 0xc) * 0xc;
    uVar17 = uVar16 * uVar10 + (uint)(*(byte *)(param_1 + 8) >> 1) + 0x20;
    if (*(char *)(param_1 + 0x2a42) == '\0') {
      iVar12 = 10;
    }
    uVar18 = iVar12 + ((*(uint *)(param_1 + 0x283c) & 0x1f) + 1 >> 1) * 3 + 3;
    if (!bVar2) {
      if (*(int *)(param_1 + 0x2680) != param_1 + 0x2840) goto LAB_00027540;
    }
    else if (*(int *)(param_1 + 0x2680) != param_1 + 0x28e4) {
LAB_00027540:
      uVar18 = uVar18 + (*(int *)(param_1 + 0x267c) + 1U & 0xfffffffe) + 4;
    }
    uVar5 = *(uint *)(param_1 + 0x1ec);
    if (uVar5 == 0) {
      uVar13 = *(uint *)(param_1 + 0x1dc);
      iVar11 = *(int *)(param_1 + 0x1e0);
      uVar5 = ((int)(iVar11 - uVar13) >> 2) - 1;
      if (uVar5 < uVar18 + uVar17) {
        if (*(int *)(param_1 + 0x1e4) + 0x28U < uVar13) {
          FUN_0001a0f0(param_1,0x1000000);
          uVar8 = (uint)*(byte *)(param_1 + 8);
          uVar13 = *(uint *)(param_1 + 0x1dc);
          iVar11 = *(int *)(param_1 + 0x1e0);
        }
        iVar12 = iVar11 - uVar13;
LAB_00027630:
        uVar5 = (iVar12 >> 2) - 1;
        if (uVar5 < uVar18 + uVar17) {
          uVar17 = uVar5 - uVar18;
        }
      }
      uVar6 = uVar5 >> 2;
      if (uVar5 >> 2 < uVar17) {
        uVar6 = uVar17;
      }
      uVar17 = uVar5 - uVar6;
      if (uVar5 - uVar6 < uVar18) {
        uVar17 = uVar18;
      }
      iVar12 = iVar11 + 0x94;
      *(int *)(param_1 + 0x1f0) = iVar12;
      uVar5 = uVar13 + uVar17 * 4 + 0x9f & 0xfffffff8;
      *(uint *)(param_1 + 0x1e0) = uVar5;
      uVar5 = uVar5 + 0x7f & 0xffffff80;
      *(uint *)(param_1 + 0x1ec) = uVar5;
    }
    else {
      uVar13 = *(uint *)(param_1 + 0x1dc);
      iVar11 = *(int *)(param_1 + 0x1e0);
      iVar12 = *(int *)(param_1 + 0x1f0);
      if ((((int)(iVar11 - uVar13) >> 2) - 1U < uVar18) ||
         ((uint)((int)(iVar12 - uVar5) >> 2) < uVar17)) {
        if (*(int *)(param_1 + 0x1e4) + 0x28U < uVar13) {
          FUN_0001a0f0(param_1,0x1000000);
          uVar8 = (uint)*(byte *)(param_1 + 8);
          uVar13 = *(uint *)(param_1 + 0x1dc);
          iVar11 = *(int *)(param_1 + 0x1e0);
        }
        iVar12 = iVar11 - uVar13;
        goto LAB_00027630;
      }
    }
    uVar8 = ((int)(iVar12 - uVar5) >> 2) - (uVar8 >> 1);
    if (uVar16 * uVar10 <= uVar8) goto LAB_00027854;
  }
  uVar10 = ((uVar8 / uVar16) / 0xc) * 0xc;
LAB_00027854:
  *param_3 = uVar10;
  uVar8 = (uint)*(byte *)(param_1 + 8);
  if (uVar8 != 0x20) {
    if ((*(uint *)(param_1 + 0x27d8) & 1) == 0) {
      uVar17 = *(uint *)(param_1 + 0x2838);
    }
    else {
      uVar17 = *(uint *)(param_1 + 0x2834);
    }
    uVar18 = uVar17;
    if (uVar17 <= uVar5) {
      uVar18 = (uVar5 + uVar8) - 1 & -uVar8;
    }
    uVar16 = uVar5 + uVar16 * uVar10 * 4;
    if (uVar17 <= uVar16) {
      uVar17 = (uVar16 + uVar8) - 1 & -uVar8;
    }
    if (uVar18 < uVar17) {
      uVar10 = uVar17 - uVar18;
      for (uVar16 = uVar10 >> 9; uVar16 != 0; uVar16 = uVar16 - 1) {
        dataCacheBlockClearToZero(uVar18);
        dataCacheBlockClearToZero(uVar18 + uVar8);
        dataCacheBlockClearToZero(uVar18 + uVar8 * 2);
        dataCacheBlockClearToZero(uVar18 + uVar8 * 3);
        uVar18 = uVar18 + 0x200;
      }
      for (uVar16 = uVar10 >> 7 & 3; uVar16 != 0; uVar16 = uVar16 - 1) {
        dataCacheBlockClearToZero(uVar18);
        uVar18 = uVar18 + 0x80;
      }
      if ((uVar9 & 1) == 0) {
        *(uint *)(param_1 + 0x2838) = uVar17;
      }
      else {
        *(uint *)(param_1 + 0x2834) = uVar17;
      }
    }
  }
  *(uint *)(param_1 + 0x27d8) = uVar15;
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
int FUN_00028350(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  uint param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint param_6;
  undefined *param_7;
  int param_8;
  undefined4 param_9;
  undefined4 *param_10;
{
  bool bVar1;
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
  double dVar19;
  undefined *puVar20;
  uint uVar21;
  uint *puVar22;
  int *piVar23;
  int iVar24;
  uint *puVar25;
  undefined4 *puVar26;
  uint uVar27;
  int iVar28;
  uint uVar29;
  undefined4 uVar30;
  undefined4 uVar31;
  undefined4 *puVar32;
  uint uVar33;
  undefined4 uVar34;
  undefined4 uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  int iVar39;
  int iVar40;
  int iVar41;
  char in_RESERVE;
  byte bVar42;
  int iVar43;
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
  
  if (param_6 == 0x1909) {
    iVar41 = 1;
    if (param_7 != ((unsigned char *)0x00001401)) {
      iVar41 = 0x13;
      if ((param_7 == ((unsigned char *)0x00001406)) || (iVar41 = 0x1f, param_7 == ((unsigned char *)0x0000140b)))
      goto LAB_000284b0;
      iVar41 = 0;
      if (param_7 == ((unsigned char *)0x00001403)) {
        iVar41 = 0x19;
        goto LAB_000284b0;
      }
    }
  }
  else if (param_6 < 0x190a) {
    if (param_6 == 0x1907) {
      iVar41 = 5;
      if ((param_7 != (undefined *)0x8363) && (iVar41 = 0x28, param_7 != (undefined *)0x8032)) {
        return 0;
      }
      goto LAB_000284b0;
    }
    if (param_6 < 0x1908) {
      if (param_6 != 0x1906) {
        return 0;
      }
      iVar41 = 2;
      if (param_7 != ((unsigned char *)0x00001401)) {
        iVar41 = 0x14;
        if ((param_7 == ((unsigned char *)0x00001406)) || (iVar41 = 0x20, param_7 == ((unsigned char *)0x0000140b)))
        goto LAB_000284b0;
        iVar41 = 0;
        if (param_7 == ((unsigned char *)0x00001403)) {
          iVar41 = 0x1a;
          goto LAB_000284b0;
        }
      }
      goto LAB_000283c0;
    }
    iVar41 = 0x12;
    if (param_7 == ((unsigned char *)0x00001406)) {
LAB_00028524:
      if (param_7 != (undefined *)0x8367) {
        if (param_7 == ((unsigned char *)0x00001401)) {
          iVar41 = 9;
          goto LAB_000284b0;
        }
        goto LAB_00028510;
      }
      iVar41 = 10;
    }
    else {
      iVar41 = 0x1e;
      if (param_7 != ((unsigned char *)0x0000140b)) {
        iVar41 = 0;
        if (param_7 != (undefined *)0x8035) goto LAB_00028524;
        iVar41 = 9;
      }
LAB_00028510:
      if (param_7 == (undefined *)0x8368) {
        iVar41 = 0x23;
        goto LAB_000284b0;
      }
    }
    if (param_7 == ((unsigned char *)0x00001403)) {
      iVar41 = 0x18;
      goto LAB_000284b0;
    }
  }
  else {
    if (param_6 != 0x80e1) {
      if (param_6 == 0x85b9) {
        iVar41 = 0x27;
        if ((param_7 != (undefined *)0x85ba) && (iVar41 = 0x26, param_7 != (undefined *)0x85bb)) {
          return 0;
        }
        goto LAB_000284b0;
      }
      if (param_6 != 0x190a) {
        return 0;
      }
      iVar41 = 4;
      if (param_7 != ((unsigned char *)0x00001401)) {
        if (param_7 == ((unsigned char *)0x00001406)) {
          iVar41 = 0x16;
          goto LAB_000284b0;
        }
        iVar41 = 0x22;
        if (param_7 == ((unsigned char *)0x0000140b)) goto LAB_000284b0;
        iVar41 = 0;
        if (param_7 == ((unsigned char *)0x00001403)) {
          iVar41 = 0x1c;
          goto LAB_000284b0;
        }
      }
      goto LAB_000283c0;
    }
    iVar41 = 7;
    if (param_7 == (undefined *)0x8366) {
LAB_00028460:
      if (param_7 != (undefined *)0x8035) {
LAB_00028428:
        if (param_7 == ((unsigned char *)0x00001401)) {
          iVar41 = 8;
          goto LAB_000283c0;
        }
        goto LAB_0002844c;
      }
      iVar41 = 8;
LAB_00028474:
      if (param_7 == ((unsigned char *)0x00001406)) {
        iVar41 = 0x11;
        goto LAB_000284b0;
      }
      if (param_7 == ((unsigned char *)0x0000140b)) {
        iVar41 = 0x1d;
        goto LAB_000284b0;
      }
    }
    else {
      if (param_7 == (undefined *)0x8365) {
        iVar41 = 6;
        goto LAB_00028428;
      }
      iVar41 = 0;
      if (param_7 != (undefined *)0x8367) goto LAB_00028460;
      iVar41 = 0xb;
LAB_0002844c:
      if (param_7 != (undefined *)0x8368) goto LAB_00028474;
      iVar41 = 0x24;
    }
    if (param_7 == ((unsigned char *)0x00001403)) {
      iVar41 = 0x17;
      goto LAB_000284b0;
    }
  }
LAB_000283c0:
  if (iVar41 == 0) {
    return 0;
  }
LAB_000284b0:
  if ((((0x1000 < (int)param_4) || (0x1000 < (int)param_5)) || (0x1000 < *(int *)(param_1 + 0x15c)))
     || (0x1000 < *(int *)(param_1 + 0x160))) {
    return 0;
  }
  _pthread_mutex_lock(*(undefined4 *)(param_1 + 0xc));
  puVar22 = &local_108;
  uVar33 = param_4;
  uVar29 = param_5;
  FUN_0000a6e0(param_1,param_6,param_7,param_4,param_5,puVar22,auStack_104,local_100,
               ((unsigned char *)0x00002e50) + *(int *)(param_1 + 0x10));
  uVar38 = param_8 + local_100[0];
  if ((int)param_4 < 1) {
    uVar36 = 1;
    fVar7 = FLOAT_001aa0e8;
  }
  else {
    uStack_f4 = param_4 ^ 0x80000000;
    local_f8 = 0x43300000;
    fVar7 = (float)((double)CONCAT44(0x43300000,uStack_f4) - DOUBLE_001aa1e0);
    uVar36 = param_4;
  }
  if ((int)param_5 < 1) {
    uVar37 = 1;
    fVar2 = FLOAT_001aa0e8;
  }
  else {
    uStack_ec = param_5 ^ 0x80000000;
    local_f0 = 0x43300000;
    fVar2 = (float)((double)CONCAT44(0x43300000,uStack_ec) - DOUBLE_001aa1e0);
    uVar37 = param_5;
  }
  uStack_e4 = param_2 ^ 0x80000000;
  uVar34 = 0x43300000;
  uStack_ac = param_5 + param_3 ^ 0x80000000;
  uStack_b4 = param_3 ^ 0x80000000;
  local_b0 = 0x43300000;
  local_e8 = 0x43300000;
  local_e0 = 0x43300000;
  local_b8 = 0x43300000;
  uStack_c4 = -param_2 ^ 0x80000000;
  uStack_bc = uVar37 - param_3 ^ 0x80000000;
  uStack_dc = param_4 + param_2 ^ 0x80000000;
  local_d8 = 0x43300000;
  local_d0 = 0x43300000;
  local_c8 = 0x43300000;
  local_c0 = 0x43300000;
  uStack_d4 = *(uint *)(param_1 + 0x15c) ^ 0x80000000;
  uStack_cc = *(uint *)(param_1 + 0x160) ^ 0x80000000;
  fVar12 = (float)((double)CONCAT44(0x43300000,uStack_e4) - DOUBLE_001aa1e0) + FLOAT_001aa0d4;
  fVar9 = fVar2 - (float)((double)CONCAT44(0x43300000,uStack_ac) - DOUBLE_001aa1e0);
  fVar11 = (float)((double)CONCAT44(0x43300000,uStack_dc) - DOUBLE_001aa1e0) + FLOAT_001aa0d4;
  fVar14 = fVar12;
  if (fVar12 < 0.0) {
    fVar14 = FLOAT_001aa0d4;
  }
  fVar3 = (float)((double)CONCAT44(0x43300000,uStack_c4) - DOUBLE_001aa1e0);
  fVar4 = (float)((double)CONCAT44(0x43300000,uStack_bc) - DOUBLE_001aa1e0);
  fVar5 = (float)((double)CONCAT44(0x43300000,uStack_d4) - DOUBLE_001aa1e0);
  fVar6 = (float)((double)CONCAT44(0x43300000,uStack_cc) - DOUBLE_001aa1e0);
  fVar16 = FLOAT_001aa0d4;
  if (-fVar12 < 0.0) {
    fVar16 = fVar14;
  }
  fVar12 = fVar2 - (float)((double)CONCAT44(0x43300000,uStack_b4) - DOUBLE_001aa1e0);
  fVar14 = FLOAT_001aa0d4;
  fVar18 = FLOAT_001aa148;
  if (FLOAT_001aa0d4 < fVar9) {
    fVar14 = fVar9;
    fVar18 = -fVar9;
  }
  fVar8 = fVar5 - fVar11;
  fVar9 = fVar6 - fVar12;
  fVar18 = fVar4 + fVar18;
  fVar17 = fVar16 + fVar3;
  if (fVar8 < 0.0) {
    fVar11 = fVar5;
  }
  if (fVar9 < 0.0) {
    fVar12 = fVar6;
  }
  fVar13 = fVar18 - fVar2;
  fVar10 = fVar17;
  if (fVar17 < 0.0) {
    fVar10 = FLOAT_001aa0d4;
  }
  fVar15 = fVar5;
  if (-fVar8 < 0.0) {
    fVar15 = fVar11;
  }
  fVar11 = fVar2;
  if (fVar13 < 0.0) {
    fVar11 = fVar18;
  }
  fVar18 = fVar6;
  if (-fVar9 < 0.0) {
    fVar18 = fVar12;
  }
  fVar9 = FLOAT_001aa0d4;
  if (-fVar17 < 0.0) {
    fVar9 = fVar10;
  }
  fVar3 = fVar15 + fVar3;
  if (-fVar13 < 0.0) {
    fVar11 = fVar2;
  }
  fVar4 = fVar4 - fVar18;
  fVar2 = fVar3 - fVar7;
  fVar12 = fVar4;
  if (fVar4 < 0.0) {
    fVar12 = FLOAT_001aa0d4;
  }
  fVar8 = fVar7;
  if (fVar2 < 0.0) {
    fVar8 = fVar3;
  }
  fVar3 = FLOAT_001aa0d4;
  if (-fVar4 < 0.0) {
    fVar3 = fVar12;
  }
  if (-fVar2 < 0.0) {
    fVar8 = fVar7;
  }
  if ((fVar8 <= fVar9) || (fVar11 <= fVar3)) {
    _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (((((*(int *)param_10[1] != 0) && (iVar24 = FUN_0001e280(param_1,param_10,1), iVar24 == 0)) ||
       ((puVar20 = PTR_DAT_001e88c8, (int *)param_10[2] == (int *)0x0 ||
        ((iVar24 = *(int *)param_10[2], iVar24 == 0 ||
         (uVar27 = *(uint *)*param_10, uVar38 != uVar27)))))) ||
      ((*(char *)(iVar24 + 0x16) != '\x06' && ((param_6 != 0x1908 || (param_7 != ((unsigned char *)0x00001406)))))))
     || (((uVar38 | local_108) & 0x1f) != 0)) {
    _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
    return 0;
  }
  if (uVar27 != 0) {
    FUN_0000b670(param_1,uVar27,uVar37 * local_108,uVar33,uVar29,puVar22,0,uVar34);
  }
  iVar40 = param_1 + 0x240;
  iVar39 = 0xf;
  uVar34 = (**(code **)(param_1 + 0x2998))(iVar40,0x343);
  *(undefined4 *)(param_1 + 0x298c) = uVar34;
  iVar24 = param_1;
  do {
    if (*(int *)(iVar24 + 0x1c8) != 0) {
      uVar34 = ((int (*)())FUN_0002cd50)(param_1,0,iVar39,uVar34);
    }
    iVar39 = iVar39 + -1;
    bVar42 = (iVar39 == 0) << 1;
    iVar24 = iVar24 + -4;
  } while (iVar39 != 0);
  puVar25 = (uint *)((int (*)())FUN_0002cd50)(param_1,0,0,uVar34);
  puVar26 = (undefined4 *)((uint)(puVar25 + 0xb) & 0xffffffe0);
  *puVar25 = (((int)puVar26 - (int)puVar25) + -8) * 0x4000 | 0xc0001000;
  puVar26[-1] = (int)puVar26 - (int)puVar25;
  puVar22 = *(uint **)(param_1 + 0x1d8);
  *puVar22 = (int)puVar26 - (int)puVar22 >> 2 | *puVar22;
  *(undefined4 **)(param_1 + 0x1d8) = puVar26;
  *puVar26 = 0x40000000;
  puVar32 = *(undefined4 **)param_10[2];
  piVar23 = puVar32 + 4;
  do {
    if (in_RESERVE != '\0') {
      iVar24 = storeWordConditionalIndexed(*piVar23 + 0x10000,0,piVar23);
      *piVar23 = iVar24;
      bVar42 = 2;
    }
  } while (!(bool)(bVar42 >> 1 & 1));
  puVar26[2] = *puVar32;
  puVar26[3] = uVar38 - *(int *)*param_10;
  uVar34 = FUN_0000a2f0((uint)*(ushort *)(((unsigned char *)0x00002db8) + *(int *)(param_1 + 0x10)),
                        *(undefined4 *)(param_1 + 0x154));
  puVar26[4] = uVar34;
  _memcpy(puVar26 + 5,PTR_DAT_001e88d0,0x2f4);
  puVar26[0x23] = 0;
  puVar26[0x9f] = 0;
  uVar21 = puVar26[0x8f];
  puVar26[0xa1] =
       param_4 & 0x3ffe | *(uint *)(puVar20 + iVar41 * 0x24 + 0x18) >> 0xb & 0x180000 |
       (*(uint *)(puVar20 + iVar41 * 0x24 + 0x18) & 0x3c00) << 0xb;
  uVar33 = *(uint *)(puVar20 + iVar41 * 0x24 + 0x18) >> 5 & 0x1f;
  puVar26[0x8f] = uVar33 | uVar21 & 0xffffffe0;
  uVar29 = (*(uint *)(puVar20 + iVar41 * 0x24 + 0x18) & 0x18) << 5;
  puVar26[0x8f] = uVar29 | uVar33 | uVar21 & 0xfffffce0;
  uVar38 = (*(uint *)(puVar20 + iVar41 * 0x24 + 0x18) & 6) << 9;
  puVar26[0x8f] = uVar38 | uVar29 | uVar33 | uVar21 & 0xfffff0e0;
  uVar27 = *(uint *)(puVar20 + iVar41 * 0x24 + 0x1c) >> 0x12 & 0x3000;
  puVar26[0x8f] = uVar27 | uVar38 | uVar29 | uVar33 | uVar21 & 0xffffc0e0;
  puVar26[0x8f] =
       *(uint *)(puVar20 + iVar41 * 0x24 + 0x1c) >> 0xe & 0xc000 |
       uVar27 | uVar38 | uVar29 | uVar33 | uVar21 & 0xffff00e0;
  if ((*(uint *)(puVar20 + iVar41 * 0x24 + 0x14) & 0xfc000000) == 0) {
    puVar26[0x5b] = puVar26[0x5b] & 0xfffe3fff | 0x18000;
  }
  uStack_a4 = param_5 ^ 0x80000000;
  puVar26[0xb8] = uVar36 - 1 & 0x1fff | (uVar37 - 1) * 0x2000 & 0x3ffe000;
  dVar19 = DOUBLE_001aa1e0;
  fVar4 = FLOAT_001aa12c;
  fVar12 = FLOAT_001aa10c;
  local_a8 = 0x43300000;
  puVar32 = puVar26 + 0xce;
  fVar5 = FLOAT_001aa0e8 / fVar5;
  fVar2 = FLOAT_001aa0e8 / fVar6;
  puVar26[0xc2] = 0x31080;
  puVar26[199] = ((unsigned char *)0x00001087U);
  fVar7 = (float)((double)CONCAT44(0x43300000,uStack_a4) - dVar19);
  puVar26[0xc5] = fVar15 * fVar5;
  puVar26[0xc3] = fVar16 * fVar5;
  puVar26[0xc6] = fVar2 * (fVar6 - fVar14);
  fVar3 = fVar7 - fVar3;
  puVar26[0xc4] = fVar2 * (fVar6 - fVar18);
  fVar7 = fVar7 - fVar11;
  iVar41 = (int)((fVar8 - fVar9) * fVar4);
  local_a0 = (longlong)iVar41;
  uVar33 = (uint)((fVar3 - fVar7) * fVar4);
  local_98 = (longlong)(int)uVar33;
  puVar26[0xc9] = 0xc0033500;
  puVar26[0xca] = 0x10031;
  puVar26[0xcb] = (fVar9 + fVar8) * fVar12;
  puVar26[0xcc] = (fVar7 + fVar3) * fVar12;
  puVar26[0xcd] = 0;
  puVar26[200] = iVar41 << 0x10 | uVar33;
  puVar26[1] = (int)puVar32 - (int)puVar25 >> 2;
  puVar22 = *(uint **)(param_1 + 0x1d8);
  *puVar22 = (int)puVar32 - (int)puVar22 >> 2 | *puVar22;
  *(undefined4 **)(param_1 + 0x1d8) = puVar32;
  puVar26[0xce] = 0x33000000;
  puVar26[0xcf] = 0;
  puVar26[0xd1] = 10;
  puVar26[0xd0] = ((unsigned char *)0x00001393U);
  puVar26[0xd2] = ((unsigned char *)0x000013c6U);
  puVar26[0xd3] = 3;
  puVar26[0xd4] = 0x5c8;
  puVar26[0xd5] = 0x20000;
  puVar26[0xd6] = (*(unsigned char *)0x000010ea);
  uVar34 = *(undefined4 *)(param_1 + 0x1cfc);
  puVar26[0xd8] = ((unsigned char *)0x000010faU);
  puVar26[0xd7] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x1da0);
  puVar26[0xda] = 0xc0001000;
  puVar26[0xdc] = 0x11004;
  puVar26[0xd9] = uVar34;
  puVar26[0xdd] = *(undefined4 *)(param_1 + 0x1ca8);
  uVar34 = *(undefined4 *)(param_1 + 0x1cac);
  puVar26[0xdf] = ((unsigned char *)0x00001008U);
  puVar26[0xde] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x1ca0);
  puVar26[0xe1] = (*(unsigned char *)0x000010e9);
  puVar26[0xe0] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x1d20);
  puVar26[0xe3] = ((unsigned char *)0x000013c7U);
  puVar26[0xe2] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x1cf0);
  puVar26[0xe5] = ((unsigned char *)0x000013c1U);
  puVar26[0xe4] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x1ce4);
  puVar26[0xe7] = 0x850;
  puVar26[0xe6] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x1dc0);
  puVar26[0xe9] = 0x887;
  puVar26[0xe8] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x1db4);
  puVar26[0x18b] = 0x82c;
  puVar26[0xea] = uVar34;
  uVar34 = *(undefined4 *)(0x00001dc4 + param_1);
  puVar26[0xeb] = ((unsigned char *)0x000010aeU);
  puVar26[0x18c] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x1d70);
  puVar26[0xed] = ((unsigned char *)0x00001394U);
  puVar26[0xec] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x1d30);
  puVar26[0xef] = ((unsigned char *)0x00001380U);
  puVar26[0xf1] = ((unsigned char *)0x00001002U);
  puVar26[0xf0] = 0;
  puVar26[0xee] = uVar34;
  puVar26[0xf2] = *(undefined4 *)(param_1 + 0x1d90);
  uVar34 = *(undefined4 *)(param_1 + 0x1d90);
  puVar26[0xf3] = 0x824;
  puVar26[0xf2] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x1ddc);
  puVar26[0xf5] = 0x825;
  puVar26[0xf4] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x1de0);
  puVar26[0xf7] = 0x82d;
  puVar26[0xf6] = uVar34;
  uVar34 = *(undefined4 *)(0x000026c8 + param_1 + 4);
  puVar26[0xf9] = 0x854;
  puVar26[0xf8] = uVar34;
  uVar34 = **(undefined4 **)(param_1 + 0x2680);
  puVar26[0xfb] = 0x878;
  puVar26[0xfa] = uVar34;
  uVar34 = **(undefined4 **)(param_1 + 0x2684);
  puVar26[0xfd] = ((unsigned char *)0x000013c0U);
  puVar26[0xfc] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x1ce0);
  puVar26[0xff] = ((unsigned char *)0x000012f0U);
  puVar20 = PTR_DAT_001e88c8;
  puVar26[0xfe] = uVar34;
  uVar33 = *(uint *)(param_1 + 0x1d2c);
  puVar26[0x100] = uVar33;
  if ((*(uint *)(puVar20 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x8000) == 0) {
    puVar26[0x100] = uVar33 & 0xfffffffe;
  }
  puVar26[0x101] = ((unsigned char *)0x000012f5U);
  uVar33 = *(uint *)(param_1 + 0x1c8c);
  puVar26[0x102] = uVar33;
  if ((*(uint *)(puVar20 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x8000) == 0) {
    puVar26[0x102] = uVar33 & 0xfffff7ff;
  }
  puVar26[0x103] = ((unsigned char *)0x000010a2U);
  uVar34 = *(undefined4 *)(param_1 + 0x1d7c);
  puVar26[0x105] = ((unsigned char *)0x00001381U);
  puVar26[0x104] = uVar34;
  uVar33 = *(uint *)(param_1 + 0x1cc0);
  puVar26[0x106] = uVar33;
  if ((*(uint *)(puVar20 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x4000) == 0) {
    puVar26[0x106] = uVar33 & 0xfffffffc;
  }
  puVar26[0x107] = ((unsigned char *)0x0000109eU);
  uVar35 = 0xc0221000;
  uVar31 = 0xaaaa;
  uVar30 = 0x110f8;
  iVar39 = 0;
  iVar24 = 0;
  uVar34 = *(undefined4 *)(param_1 + 0x1d6c);
  puVar26[0x109] = ((unsigned char *)0x00001096U);
  puVar26[0x108] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x1df8);
  puVar26[0x10b] = ((unsigned char *)0x00001041U);
  puVar26[0x108] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x29f0);
  puVar26[0x10d] = ((unsigned char *)0x00001046U);
  puVar26[0x10c] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x1dfc);
  puVar26[0x10f] = ((unsigned char *)0x00001094U);
  puVar26[0x127] = ((unsigned char *)0x00001095U);
  puVar26[0x111] = ((unsigned char *)0x00001095U);
  puVar26[0x14d] = ((unsigned char *)0x00001180U);
  puVar26[0x113] = ((unsigned char *)0x00001095U);
  puVar26[0x115] = ((unsigned char *)0x00001095U);
  puVar26[0x117] = ((unsigned char *)0x00001095U);
  puVar26[0x10e] = uVar34;
  puVar26[0x119] = ((unsigned char *)0x00001095U);
  puVar26[0x11b] = ((unsigned char *)0x00001095U);
  puVar26[0x11d] = ((unsigned char *)0x00001095U);
  puVar26[0x11f] = ((unsigned char *)0x00001095U);
  puVar26[0x121] = ((unsigned char *)0x00001095U);
  puVar26[0x123] = ((unsigned char *)0x00001095U);
  puVar26[0x125] = ((unsigned char *)0x00001095U);
  puVar26[0x129] = 0xc0221000;
  puVar26[0x110] = 0;
  puVar26[0x14e] = 2;
  puVar26[0x14f] = ((unsigned char *)0x00001189U);
  puVar26[0x151] = ((unsigned char *)0x00001181U);
  puVar26[0x153] = ((unsigned char *)0x0000118dU);
  puVar26[0x155] = ((unsigned char *)0x0000118eU);
  puVar26[0x157] = ((unsigned char *)0x0000118cU);
  puVar26[0x159] = ((unsigned char *)0x000011a9U);
  uVar34 = *(undefined4 *)(param_1 + 0x257c);
  puVar26[0x15b] = ((unsigned char *)0x000011aaU);
  puVar26[0x15a] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x2580);
  puVar26[0x15d] = ((unsigned char *)0x000011abU);
  puVar26[0x15c] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x2584);
  puVar26[0x15f] = ((unsigned char *)0x000011acU);
  puVar26[0x15e] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x2588);
  puVar26[0x161] = ((unsigned char *)0x000010c0U);
  puVar26[0x160] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x216c);
  puVar26[0x163] = ((unsigned char *)0x000010c1U);
  puVar26[0x165] = ((unsigned char *)0x000010c8U);
  puVar26[0x167] = ((unsigned char *)0x0000101dU);
  puVar26[0x162] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x2128);
  puVar26[0x169] = ((unsigned char *)0x0000138aU);
  puVar26[0x16b] = ((unsigned char *)0x0000138eU);
  puVar26[0x170] = 0;
  puVar26[0x16d] = ((unsigned char *)0x00001040U);
  puVar26[0x16a] = 0;
  puVar26[0x16c] = 0;
  puVar26[0x16e] = 0;
  puVar26[0x168] = uVar34;
  puVar26[0x16f] = (*(unsigned char *)0x00001150);
  puVar26[0x171] = ((unsigned char *)0x00001100U);
  uVar34 = *(undefined4 *)(param_1 + 0x1f1c);
  puVar26[0x173] = ((unsigned char *)0x00001110U);
  puVar26[0x172] = uVar34;
  puVar26[0x174] = *(undefined4 *)(param_1 + 0x1f5c);
  puVar26[0x175] = (*(unsigned char *)0x00001120);
  uVar34 = *(undefined4 *)(param_1 + 0x1f9c);
  puVar26[0x177] = ((unsigned char *)0x00001130U);
  puVar26[0x176] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x1fdc);
  puVar26[0x179] = ((unsigned char *)0x00001140U);
  puVar26[0x178] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x201c);
  puVar26[0x17b] = ((unsigned char *)0x000010f4U);
  puVar26[0x17c] = 0xaaaa;
  puVar26[0x17d] = ((unsigned char *)0x00001383U);
  puVar26[0x17a] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x1d34);
  puVar26[0x17f] = ((unsigned char *)0x00001386U);
  puVar26[0x17e] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x1d38);
  puVar26[0x181] = 0x110f8;
  puVar26[0x180] = uVar34;
  puVar26[0x182] = *(undefined4 *)(param_1 + 0x1d98);
  uVar34 = *(undefined4 *)(param_1 + 0x1d50);
  puVar26[0x184] = ((unsigned char *)0x00001087U);
  puVar26[0x183] = uVar34;
  uVar34 = *(undefined4 *)(param_1 + 0x1f0c);
  puVar26[0x186] = 0x31080;
  puVar26[0x185] = uVar34;
  puVar26[0x187] = *(undefined4 *)(param_1 + 0x1efc);
  puVar26[0x188] = *(undefined4 *)(param_1 + 0x1f04);
  puVar26[0x189] = *(undefined4 *)(param_1 + 0x1f00);
  puVar26[0x18a] = *(undefined4 *)(param_1 + 0x1f08);
  FUN_0004c100(puVar26 + 0xd0,iVar40);
  puVar26 = puVar26 + 0x18d;
  iVar41 = param_1;
  do {
    iVar28 = *(int *)(iVar41 + 0x18c);
    if (iVar28 != 0) {
      iVar43 = 5;
      piVar23 = (int *)(iVar24 + *(int *)(param_1 + 0x18));
      do {
        if (iVar28 == *piVar23) {
          if (*(int *)(iVar28 + 0x34) != 0) goto LAB_0002918c;
          break;
        }
        piVar23 = piVar23 + 1;
        iVar43 = iVar43 + -1;
      } while (iVar43 != 0);
      iVar28 = 0;
    }
LAB_0002918c:
    if ((iVar39 == 0) || (iVar28 != 0)) {
      puVar26 = (undefined4 *)((int (*)())FUN_0002cd50)(param_1,iVar28,iVar39,puVar26);
    }
    bVar1 = iVar39 == 0xf;
    iVar24 = iVar24 + 0x14;
    iVar41 = iVar41 + 4;
    iVar39 = iVar39 + 1;
    if (bVar1) {
      *(undefined4 **)(param_1 + 0x298c) = puVar26;
      (**(code **)(param_1 + 0x299c))(iVar40,puVar26);
      _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
      if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
        FUN_0001a0f0(param_1,0x1000000);
      }
      if (*(int *)*param_10 != 0) {
        FUN_0000b670(param_1,*(int *)*param_10,uVar37 * local_108,puVar26,uVar30,uVar31,param_10,
                     uVar35);
        return 1;
      }
      return 1;
    }
  } while( true );
}

/* FUN_00029290 @ 0x29290 (4 bytes) */
int FUN_00029290(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
  uint param_9;
  int param_10;
{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  void *pvVar9;
  undefined4 *puVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  uint *puVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  int *piVar19;
  int *piVar20;
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
  uVar18 = param_9 & 0xff;
  iVar16 = *(int *)(param_1 + 0x10);
  iVar7 = FUN_0000a2f0((uint)*(ushort *)(((unsigned char *)0x00002db8) + iVar16),*(undefined4 *)(param_1 + 0x154));
  if (((((*(uint *)(((unsigned char *)0x000030b0) + iVar16) & 0x1ff) == 0) &&
       ((*(uint *)(((unsigned char *)0x000030b4) + iVar16) & 0xff0000) == 0)) || (param_6 - 0x1901U < 2)) ||
     (uVar18 == 2)) {
    iVar6 = 0;
    bVar4 = false;
  }
  else if ((*(uint *)(((unsigned char *)0x000030b0) + iVar16) & 2) == 0) {
    if (((*(uint *)(((unsigned char *)0x000030b0) + iVar16) & 4) == 0) ||
       (*(short *)(((unsigned char *)0x00002fe8) + iVar16) != -0x7fea)) goto LAB_000293b0;
    bVar4 = true;
    iVar6 = *(int *)(((unsigned char *)0x00002ff0) + iVar16) + -1;
  }
  else if (*(short *)(((unsigned char *)0x00002fa8) + iVar16) == -0x7fea) {
    bVar4 = true;
    iVar6 = *(int *)(((unsigned char *)0x00002fb0) + iVar16) + -1;
  }
  else {
LAB_000293b0:
    iVar6 = 0;
    bVar4 = true;
  }
  if (param_10 == 0) {
    bVar1 = uVar18 != 2;
    if (bVar1) {
      puVar5 = ((unsigned char *)0x00002e50) + iVar16;
    }
    else {
      puVar5 = (undefined *)0x0;
    }
    puVar13 = &uStack_e8;
    piVar20 = &iStack_e4;
    iVar17 = param_5;
    FUN_0000a6e0(param_1,param_6,param_7,param_4 - iVar6,param_5,puVar13,piVar20,aiStack_e0,puVar5);
    uStack_ac = param_8 + aiStack_e0[0];
    if (param_3 < 0) {
      param_5 = param_5 + param_3;
      iVar6 = param_3 * uStack_e8;
      param_3 = 0;
      uStack_ac = uStack_ac - iVar6;
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
        if (uVar18 == 0) {
          uStack_98 = 0x20000;
        }
        else {
          uStack_98 = 0;
        }
        puVar5 = ((unsigned char *)0x00002e48) + iVar16;
        puStack_94 = ((unsigned char *)0x0007efff);
        if (((unsigned char *)0x00002e68)[iVar16] != '\0') {
          uStack_98 = uStack_98 | 2;
        }
        if (((unsigned char *)0x00002e69)[iVar16] != '\0') {
          uStack_98 = uStack_98 | 8;
        }
      }
      else {
        puVar5 = (undefined *)0x0;
        puStack_94 = (undefined *)0x0;
        uStack_98 = 0;
      }
      uStack_50 = 0;
      uStack_9c = 2;
      puVar11 = auStack_a4;
      puVar12 = auStack_a0;
      uStack_a8 = uStack_e8;
      iStack_90 = param_4;
      iStack_8c = param_5;
      _glgConvertType(param_6,param_7);
      piVar19 = *(int **)(param_1 + 0x150);
      if (piVar19 == (int *)0x0) {
        aiStack_e0[2] = param_2;
        iStack_d4 = param_3;
        iStack_d0 = param_4;
        iStack_cc = param_5;
        if (param_6 == 0x1901) {
          uVar18 = *(uint *)(param_1 + 0x154);
          if ((uVar18 & 0x30000) == 0x30000) {
            if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
              FUN_0001a0f0(param_1,0x1000000);
              uVar18 = *(uint *)(param_1 + 0x154);
            }
            uStack_b8 = (param_4 + 0xf) * 4 & 0xffffffc0;
            uStack_b0 = 0x14;
            uStack_b4 = 0xf;
            if ((uVar18 & 0x2000) == 0) {
LAB_000298a4:
              iStack_c8 = 4;
            }
            else {
LAB_00029878:
              if (iVar7 == 7) {
                iStack_c8 = 10;
              }
              else {
                if (iVar7 != 8) goto LAB_000298a4;
                iStack_c8 = 0xb;
              }
            }
LAB_000299f8:
            if ((bVar4) ||
               ((((bVar1 && (((*(uint *)(((unsigned char *)0x000030b4) + iVar16) & 0xff1) != 0 ||
                             ((*(uint *)((*(unsigned char *)0x00002e68) + iVar16) & 0xffff0000) != 0)))) ||
                 (param_6 - 0x1901U < 2)) ||
                ((((uStack_a8 & 0x3f) != 0 || (0x1fff < (int)uStack_a8)) ||
                 ((uStack_ac & 0x1f) != 0)))))) {
LAB_00029a74:
              uStack_c0 = uStack_b8;
              uVar18 = param_5 * uStack_b8 + 0xfff & 0xfffff000;
              if (*(uint *)(((unsigned char *)0x00002b78) + param_1) < uVar18) {
                if (*(int *)(((unsigned char *)0x00002b74) + param_1) != 0) {
                  _vfree(*(int *)(((unsigned char *)0x00002b74) + param_1));
                }
                pvVar9 = _valloc(uVar18);
                *(uint *)(((unsigned char *)0x00002b78) + param_1) = uVar18;
                *(void **)(((unsigned char *)0x00002b74) + param_1) = pvVar9;
              }
              uStack_c4 = *(uint *)(((unsigned char *)0x00002b74) + param_1);
              if (uStack_c4 == 0) goto LAB_00029bd0;
              bVar1 = false;
            }
            else {
              if ((uVar18 & 0xf) == 4) {
                if ((param_6 != 0x80e1) || (param_7 != 0x8367)) goto LAB_00029a74;
              }
              else if ((((uVar18 & 0xf) != 3) || (param_6 != 0x80e1)) || (param_7 != 0x8366))
              goto LAB_00029a74;
              bVar1 = true;
              uStack_c0 = uStack_a8;
              uStack_c4 = uStack_ac;
            }
            uStack_bc = uStack_c4;
            if (bVar4) {
              iVar14 = *(int *)(param_1 + 0x18);
              iVar7 = *(int *)(*(int *)(iVar14 + 0x140) + 0x30);
              uStack_80 = (uint)*(ushort *)(iVar7 + 0x98);
              uStack_7c = (uint)*(ushort *)(iVar7 + 0x9a);
              uStack_78 = (uint)*(ushort *)(iVar7 + 0x8c);
              uStack_74 = *(undefined4 *)(iVar7 + 0x9c);
              iVar7 = *(int *)(*(int *)(iVar14 + 0x148) + 0x30);
              uStack_70 = (uint)*(ushort *)(iVar7 + 0x98);
              uStack_6c = (uint)*(ushort *)(iVar7 + 0x9a);
              uStack_68 = (uint)*(ushort *)(iVar7 + 0x8c);
              uStack_64 = *(undefined4 *)(iVar7 + 0x9c);
              iVar7 = *(int *)(*(int *)(iVar14 + 0x144) + 0x30);
              uStack_60 = (uint)*(ushort *)(iVar7 + 0x98);
              uStack_5c = (uint)*(ushort *)(iVar7 + 0x9a);
              uStack_58 = (uint)*(ushort *)(iVar7 + 0x8c);
              uStack_54 = *(undefined4 *)(iVar7 + 0x9c);
            }
            iVar7 = _io_connect_method_structureI_structureO
                              (*(undefined4 *)(param_1 + 4),7,aiStack_e0 + 2,0x1c,0,aiStack_e0 + 1);
            if (iVar7 != 0) goto LAB_00029bd0;
            if (!bVar1) {
              _glgProcessPixels(puVar5,&uStack_bc);
              return 1;
            }
          }
        }
        else {
          if (param_6 != 0x1902) {
            iVar6 = FUN_0001a010(param_1,iVar7,puVar11,puVar12,iVar17,puVar13,piVar20);
            if (iVar6 != 0) {
              FUN_000230d0(param_1,0,iVar7,0,0,0,*(undefined4 *)(param_1 + 0x15c),
                           *(undefined4 *)(param_1 + 0x160));
            }
            if (*(int *)(param_1 + 0x1d38) != 0) {
              puVar10 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar14,2);
              puVar10[1] = 0;
              *puVar10 = ((unsigned char *)0x00001386);
              *(undefined4 **)(param_1 + 0x298c) = puVar10 + 2;
              (**(code **)(param_1 + 0x299c))(iVar14);
            }
            if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
              FUN_0001a0f0(param_1,0x1000000);
            }
            if (*(int *)(param_1 + 0x1d38) != 0) {
              puVar10 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar14,2);
              *puVar10 = ((unsigned char *)0x00001386);
              puVar10[1] = *(undefined4 *)(param_1 + 0x1d38);
              *(undefined4 **)(param_1 + 0x298c) = puVar10 + 2;
              (**(code **)(param_1 + 0x299c))(iVar14,puVar10 + 2);
            }
            bVar2 = ((unsigned char *)0x00002b7f)[param_1];
            uVar18 = *(uint *)(param_1 + 0x154);
            uStack_b8 = (param_4 << (*(uint *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x14) & 7)) +
                        0x1fU & 0xffffffe0;
            uStack_b0 = *(uint *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x10) >> 0x16 & 0x1f;
            uStack_b4 = *(uint *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x10) >> 0x1b;
            iStack_c8 = iVar7;
            goto LAB_000299f8;
          }
          uVar18 = *(uint *)(param_1 + 0x154);
          if ((uVar18 & 0x30000) != 0) {
            if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
              FUN_0001a0f0(param_1,0x1000000);
              uVar18 = *(uint *)(param_1 + 0x154);
            }
            if ((uVar18 & 0x20000) == 0) {
              uStack_b0 = 2;
              uStack_b8 = (param_4 + 0x1f) * 2 & 0xffffffc0;
              uStack_b4 = 0xd;
            }
            else {
              uStack_b8 = (param_4 + 0xf) * 4 & 0xffffffc0;
              if ((uVar18 & 0x30000) == 0x30000) {
                uStack_b4 = 0xf;
                uStack_b0 = 0x14;
              }
              else {
                uStack_b4 = 0xd;
                uStack_b0 = 4;
              }
            }
            if ((uVar18 & 0x2000) != 0) goto LAB_00029878;
            goto LAB_000298a4;
          }
        }
      }
      else {
        iVar7 = 5;
        if ((param_6 != 0x1901) && (iVar7 = 4, param_6 != 0x1902)) {
          uStack_98 = uStack_98 | 0x60000;
          puStack_94 = (undefined *)((uint)puStack_94 | 0x68002);
          iVar7 = *(ushort *)(*piVar19 + 0x98) - 0x8ce0;
          if ((bVar1) &&
             (((*(uint *)(puVar5 + 0x268) & 0x1ff) != 0 ||
              ((*(uint *)(puVar5 + 0x26c) & 0xff0000) != 0)))) {
            iVar16 = *(int *)(param_1 + 0x18);
            iVar14 = *(int *)(*(int *)(iVar16 + 0x140) + 0x30);
            uStack_80 = (uint)*(ushort *)(iVar14 + 0x98);
            uStack_7c = (uint)*(ushort *)(iVar14 + 0x9a);
            uStack_78 = (uint)*(ushort *)(iVar14 + 0x8c);
            uStack_74 = *(undefined4 *)(iVar14 + 0x9c);
            iVar14 = *(int *)(*(int *)(iVar16 + 0x148) + 0x30);
            uStack_70 = (uint)*(ushort *)(iVar14 + 0x98);
            uStack_6c = (uint)*(ushort *)(iVar14 + 0x9a);
            uStack_68 = (uint)*(ushort *)(iVar14 + 0x8c);
            uStack_64 = *(undefined4 *)(iVar14 + 0x9c);
            iVar14 = *(int *)(*(int *)(iVar16 + 0x144) + 0x30);
            uStack_60 = (uint)*(ushort *)(iVar14 + 0x98);
            uStack_5c = (uint)*(ushort *)(iVar14 + 0x9a);
            uStack_58 = (uint)*(ushort *)(iVar14 + 0x8c);
            uStack_54 = *(undefined4 *)(iVar14 + 0x9c);
          }
        }
        piVar20 = *(int **)(piVar19[1] + iVar7 * 4);
        if (piVar20 != (int *)0x0) {
          iVar7 = iVar7 * 0x18 + *piVar19;
          uVar3 = *(ushort *)(*piVar20 + 0x18);
          iVar16 = *(int *)(iVar7 + 4);
          iVar14 = *(int *)(iVar7 + 8);
          iVar17 = *(int *)(iVar7 + 0xc);
          iVar7 = iVar14 * 0x18 + iVar16 * 0x168 + piVar20[0xc];
          uVar15 = (uint)*(ushort *)(iVar7 + 0xb2);
          uVar18 = (uint)*(ushort *)(iVar7 + 0xb0);
          _glgConvertType(uVar18,uVar15,&uStack_b4,&uStack_b0);
          iVar6 = *(int *)(param_1 + 0x15c);
          iVar7 = FUN_0000a3f0(uVar18,uVar15);
          uStack_b8 = iVar6 * iVar7;
          iVar6 = uStack_b8 * *(int *)(param_1 + 0x160);
          pvVar9 = _valloc((uint)uVar3 * iVar6);
          FUN_00031340(param_1,piVar20,iVar16,iVar14,uVar18,uVar15,pvVar9,uStack_b8);
          iVar7 = param_3 * uStack_b8;
          iVar14 = FUN_0000a3f0(uVar18,uVar15);
          uStack_bc = (int)pvVar9 + param_2 * iVar14 + iVar17 * iVar6 + iVar7;
          _glgProcessPixels(puVar5,&uStack_bc);
          _vfree(pvVar9);
          return 1;
        }
      }
    }
    uVar8 = 1;
  }
  else {
    if (!bVar4) {
      uVar8 = ((int (*)())FUN_00028350)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,uVar18,
                           param_10);
      return uVar8;
    }
LAB_00029bd0:
    uVar8 = 0;
  }
  return uVar8;
}

/* FUN_00029294 @ 0x29294 (2376 bytes) */
int FUN_00029294(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  int param_1;
  int param_2;
  int param_3;
  int param_4;
  int param_5;
  int param_6;
  int param_7;
  int param_8;
  uint param_9;
  int param_10;
{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  undefined *puVar5;
  int iVar6;
  dword *pdVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  dword *a2;
  undefined1 *a3;
  undefined4 uVar11;
  uint *a5;
  undefined4 *a1;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  uint uVar22;
  int *piVar23;
  int *piVar24;
  uint uStack_e8;
  int iStack_e4;
  int aiStack_e0 [3];
  int iStack_d4;
  int iStack_d0;
  int iStack_cc;
  dword *pdStack_c8;
  uint uStack_c4;
  uint uStack_c0;
  uint uStack_bc;
  uint uStack_b8;
  uint uStack_b4;
  uint uStack_b0;
  uint uStack_ac;
  uint uStack_a8;
  dword dStack_a4;
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
  
  iVar16 = param_1 + 0x240;
  uStack_84 = 0;
  aiStack_e0[1] = 0;
  uStack_88 = 0;
  uVar22 = param_9 & 0xff;
  iVar20 = *(int *)(param_1 + 0x10);
  pdVar7 = (dword *)FUN_0000a2f0((uint)*(ushort *)(((unsigned char *)0x00002db8) + iVar20),
                                 *(undefined4 *)(param_1 + 0x154));
  if (((((*(uint *)(((unsigned char *)0x000030b0) + iVar20) & 0x1ff) == 0) &&
       ((*(uint *)(((unsigned char *)0x000030b4) + iVar20) & 0xff0000) == 0)) || (param_6 - 0x1901U < 2)) ||
     (uVar22 == 2)) {
    iVar6 = 0;
    bVar4 = false;
  }
  else if ((*(uint *)(((unsigned char *)0x000030b0) + iVar20) & 2) == 0) {
    if (((*(uint *)(((unsigned char *)0x000030b0) + iVar20) & 4) == 0) ||
       (*(short *)(((unsigned char *)0x00002fe8) + iVar20) != -0x7fea)) goto LAB_000293b0;
    bVar4 = true;
    iVar6 = *(int *)(((unsigned char *)0x00002ff0) + iVar20) + -1;
  }
  else if (*(short *)(((unsigned char *)0x00002fa8) + iVar20) == -0x7fea) {
    bVar4 = true;
    iVar6 = *(int *)(((unsigned char *)0x00002fb0) + iVar20) + -1;
  }
  else {
LAB_000293b0:
    iVar6 = 0;
    bVar4 = true;
  }
  if (param_10 == 0) {
    bVar1 = uVar22 != 2;
    if (bVar1) {
      puVar5 = ((unsigned char *)0x00002e50) + iVar20;
    }
    else {
      puVar5 = (undefined *)0x0;
    }
    a5 = &uStack_e8;
    piVar24 = &iStack_e4;
    iVar9 = param_5;
    FUN_0000a6e0(param_1,param_6,param_7,param_4 - iVar6,param_5,a5,piVar24,aiStack_e0,puVar5);
    uVar12 = param_8 + aiStack_e0[0];
    if (param_3 < 0) {
      param_5 = param_5 + param_3;
      iVar6 = param_3 * uStack_e8;
      param_3 = 0;
      uVar12 = uVar12 - iVar6;
    }
    if (param_2 < 0) {
      param_4 = param_4 + param_2;
      iStack_e4 = param_2 * iStack_e4;
      param_2 = 0;
      uVar12 = uVar12 - iStack_e4;
    }
    if (*(int *)(param_1 + 0x160) < param_3 + param_5) {
      param_5 = *(int *)(param_1 + 0x160) - param_3;
    }
    if (*(int *)(param_1 + 0x15c) < param_2 + param_4) {
      param_4 = *(int *)(param_1 + 0x15c) - param_2;
    }
    if ((0 < param_4) && (0 < param_5)) {
      if (bVar1) {
        if (uVar22 == 0) {
          uStack_98 = 0x20000;
        }
        else {
          uStack_98 = 0;
        }
        puVar5 = ((unsigned char *)0x00002e48) + iVar20;
        puStack_94 = ((unsigned char *)0x0007efffU);
        if (((unsigned char *)0x00002e68)[iVar20] != '\0') {
          uStack_98 = uStack_98 | 2;
        }
        if (((unsigned char *)0x00002e69)[iVar20] != '\0') {
          uStack_98 = uStack_98 | 8;
        }
      }
      else {
        puVar5 = (undefined *)0x0;
        puStack_94 = (undefined *)0x0;
        uStack_98 = 0;
      }
      uStack_50 = 0;
      uStack_9c = 2;
      a2 = &dStack_a4;
      a3 = auStack_a0;
      uStack_a8 = uStack_e8;
      uStack_ac = uVar12;
      iStack_90 = param_4;
      iStack_8c = param_5;
      _glgConvertType(param_6,param_7,a2,a3,iVar9,a5,piVar24,uVar12);
      piVar23 = *(int **)(param_1 + 0x150);
      if (piVar23 == (int *)0x0) {
        aiStack_e0[2] = param_2;
        iStack_d4 = param_3;
        iStack_d0 = param_4;
        iStack_cc = param_5;
        if (param_6 == 0x1901) {
          uVar22 = *(uint *)(param_1 + 0x154);
          if ((uVar22 & 0x30000) == 0x30000) {
            if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
              FUN_0001a0f0(param_1,0x1000000);
              uVar22 = *(uint *)(param_1 + 0x154);
            }
            uStack_b8 = (param_4 + 0xf) * 4 & 0xffffffc0;
            uStack_b0 = 0x14;
            uStack_b4 = 0xf;
            if ((uVar22 & 0x2000) == 0) {
LAB_000298a4:
              pdStack_c8 = ((unsigned char *)0x4);
            }
            else {
LAB_00029878:
              if (pdVar7 == (dword *)((int)((unsigned char *)0x4) + 3)) {
                pdStack_c8 = (dword *)((int)((unsigned char *)0x8) + 2);
              }
              else {
                if (pdVar7 != ((unsigned char *)0x8)) goto LAB_000298a4;
                pdStack_c8 = (dword *)((int)((unsigned char *)0x8) + 3);
              }
            }
LAB_000299f8:
            uVar12 = uVar22 & 0xf;
            if ((bVar4) ||
               ((((bVar1 && (((*(uint *)(((unsigned char *)0x000030b4) + iVar20) & 0xff1) != 0 ||
                             ((*(uint *)((*(unsigned char *)0x00002e68) + iVar20) & 0xffff0000) != 0)))) ||
                 (param_6 - 0x1901U < 2)) ||
                ((((uStack_a8 & 0x3f) != 0 || (0x1fff < (int)uStack_a8)) ||
                 ((uStack_ac & 0x1f) != 0)))))) {
LAB_00029a74:
              uVar12 = *(uint *)(((unsigned char *)0x00002b78) + param_1);
              uStack_c0 = uStack_b8;
              uVar13 = param_5 * uStack_b8 + 0xfff & 0xfffff000;
              if (uVar12 < uVar13) {
                if (*(int *)(((unsigned char *)0x00002b74) + param_1) != 0) {
                  _vfree(*(int *)(((unsigned char *)0x00002b74) + param_1));
                }
                uVar8 = _valloc(uVar13);
                *(uint *)(((unsigned char *)0x00002b78) + param_1) = uVar13;
                *(undefined4 *)(((unsigned char *)0x00002b74) + param_1) = uVar8;
              }
              uStack_c4 = *(uint *)(((unsigned char *)0x00002b74) + param_1);
              if (uStack_c4 == 0) goto LAB_00029bd0;
              bVar1 = false;
            }
            else {
              if (uVar12 == 4) {
                if ((param_6 != 0x80e1) || (param_7 != 0x8367)) goto LAB_00029a74;
              }
              else if (((uVar12 != 3) || (param_6 != 0x80e1)) || (param_7 != 0x8366))
              goto LAB_00029a74;
              bVar1 = true;
              uStack_c0 = uStack_a8;
              uStack_c4 = uStack_ac;
            }
            uStack_bc = uStack_c4;
            if (bVar4) {
              uVar22 = *(uint *)(param_1 + 0x18);
              iVar16 = *(int *)(*(int *)(uVar22 + 0x140) + 0x30);
              uStack_80 = (uint)*(ushort *)(iVar16 + 0x98);
              uStack_7c = (uint)*(ushort *)(iVar16 + 0x9a);
              uStack_78 = (uint)*(ushort *)(iVar16 + 0x8c);
              uStack_74 = *(undefined4 *)(iVar16 + 0x9c);
              iVar16 = *(int *)(*(int *)(uVar22 + 0x148) + 0x30);
              uStack_70 = (uint)*(ushort *)(iVar16 + 0x98);
              uStack_6c = (uint)*(ushort *)(iVar16 + 0x9a);
              uStack_68 = (uint)*(ushort *)(iVar16 + 0x8c);
              uStack_64 = *(undefined4 *)(iVar16 + 0x9c);
              uVar12 = *(uint *)(uVar22 + 0x144);
              iVar16 = *(int *)(uVar12 + 0x30);
              uStack_60 = (uint)*(ushort *)(iVar16 + 0x98);
              uStack_5c = (uint)*(ushort *)(iVar16 + 0x9a);
              uStack_58 = (uint)*(ushort *)(iVar16 + 0x8c);
              uStack_54 = *(undefined4 *)(iVar16 + 0x9c);
            }
            piVar24 = aiStack_e0 + 2;
            uVar8 = 0x1c;
            uVar11 = 0;
            piVar23 = aiStack_e0 + 1;
            iVar16 = _io_connect_method_structureI_structureO
                               (*(undefined4 *)(param_1 + 4),7,piVar24,0x1c,0,piVar23);
            if (iVar16 != 0) goto LAB_00029bd0;
            if (!bVar1) {
              _glgProcessPixels(puVar5,&uStack_bc,piVar24,uVar8,uVar11,piVar23,uVar12,uVar22);
              return 1;
            }
          }
        }
        else {
          if (param_6 != 0x1902) {
            iVar6 = FUN_0001a010(param_1,pdVar7,a2,a3,iVar9,a5,piVar24);
            if (iVar6 != 0) {
              a3 = (undefined1 *)0x0;
              iVar9 = 0;
              a5 = (uint *)0x0;
              a2 = pdVar7;
              FUN_000230d0(param_1,0,pdVar7,0,0,0,*(undefined4 *)(param_1 + 0x15c),
                           *(undefined4 *)(param_1 + 0x160));
            }
            if (*(int *)(param_1 + 0x1d38) != 0) {
              puVar10 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar16,2);
              puVar10[1] = 0;
              *puVar10 = ((unsigned char *)0x00001386U);
              *(undefined4 **)(param_1 + 0x298c) = puVar10 + 2;
              (**(code **)(param_1 + 0x299c))(iVar16,puVar10 + 2);
            }
            if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
              FUN_0001a0f0(param_1,0x1000000);
            }
            if (*(int *)(param_1 + 0x1d38) != 0) {
              puVar10 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar16,2);
              a1 = puVar10 + 2;
              *puVar10 = ((unsigned char *)0x00001386U);
              puVar10[1] = *(undefined4 *)(param_1 + 0x1d38);
              *(undefined4 **)(param_1 + 0x298c) = a1;
              (**(code **)(param_1 + 0x299c))(iVar16,a1,a2,a3,iVar9,a5,a1);
            }
            bVar2 = ((unsigned char *)0x00002b7f)[param_1];
            uVar22 = *(uint *)(param_1 + 0x154);
            uStack_b8 = (param_4 << (*(uint *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x14) & 7)) +
                        0x1fU & 0xffffffe0;
            uStack_b0 = *(uint *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x10) >> 0x16 & 0x1f;
            uStack_b4 = *(uint *)(PTR_DAT_001e88c8 + (uint)bVar2 * 0x24 + 0x10) >> 0x1b;
            pdStack_c8 = pdVar7;
            goto LAB_000299f8;
          }
          uVar22 = *(uint *)(param_1 + 0x154);
          if ((uVar22 & 0x30000) != 0) {
            if (*(int *)(param_1 + 0x1e4) + 0x28U < *(uint *)(param_1 + 0x1dc)) {
              FUN_0001a0f0(param_1,0x1000000);
              uVar22 = *(uint *)(param_1 + 0x154);
            }
            if ((uVar22 & 0x20000) == 0) {
              uStack_b0 = 2;
              uStack_b8 = (param_4 + 0x1f) * 2 & 0xffffffc0;
              uStack_b4 = 0xd;
            }
            else {
              uStack_b8 = (param_4 + 0xf) * 4 & 0xffffffc0;
              if ((uVar22 & 0x30000) == 0x30000) {
                uStack_b4 = 0xf;
                uStack_b0 = 0x14;
              }
              else {
                uStack_b4 = 0xd;
                uStack_b0 = 4;
              }
            }
            if ((uVar22 & 0x2000) != 0) goto LAB_00029878;
            goto LAB_000298a4;
          }
        }
      }
      else {
        iVar16 = 5;
        if ((param_6 != 0x1901) && (iVar16 = 4, param_6 != 0x1902)) {
          uStack_98 = uStack_98 | 0x60000;
          puStack_94 = (undefined *)((uint)puStack_94 | 0x68002);
          iVar16 = *(ushort *)(*piVar23 + 0x98) - 0x8ce0;
          if ((bVar1) &&
             (((*(uint *)(puVar5 + 0x268) & 0x1ff) != 0 ||
              ((*(uint *)(puVar5 + 0x26c) & 0xff0000) != 0)))) {
            uVar12 = *(uint *)(param_1 + 0x18);
            iVar20 = *(int *)(*(int *)(uVar12 + 0x140) + 0x30);
            uStack_80 = (uint)*(ushort *)(iVar20 + 0x98);
            uStack_7c = (uint)*(ushort *)(iVar20 + 0x9a);
            uStack_78 = (uint)*(ushort *)(iVar20 + 0x8c);
            uStack_74 = *(undefined4 *)(iVar20 + 0x9c);
            iVar20 = *(int *)(*(int *)(uVar12 + 0x148) + 0x30);
            uStack_70 = (uint)*(ushort *)(iVar20 + 0x98);
            uStack_6c = (uint)*(ushort *)(iVar20 + 0x9a);
            uStack_68 = (uint)*(ushort *)(iVar20 + 0x8c);
            uStack_64 = *(undefined4 *)(iVar20 + 0x9c);
            iVar20 = *(int *)(*(int *)(uVar12 + 0x144) + 0x30);
            uStack_60 = (uint)*(ushort *)(iVar20 + 0x98);
            uStack_5c = (uint)*(ushort *)(iVar20 + 0x9a);
            uStack_58 = (uint)*(ushort *)(iVar20 + 0x8c);
            uStack_54 = *(undefined4 *)(iVar20 + 0x9c);
          }
        }
        piVar24 = *(int **)(piVar23[1] + iVar16 * 4);
        if (piVar24 != (int *)0x0) {
          iVar20 = iVar16 * 0x18 + *piVar23;
          uVar3 = *(ushort *)(*piVar24 + 0x18);
          iVar15 = *(int *)(iVar20 + 4);
          iVar14 = *(int *)(iVar20 + 8);
          iVar21 = *(int *)(iVar20 + 0xc);
          iVar20 = iVar14 * 0x18 + iVar15 * 0x168 + piVar24[0xc];
          uVar18 = (uint)*(ushort *)(iVar20 + 0xb2);
          uVar17 = (uint)*(ushort *)(iVar20 + 0xb0);
          _glgConvertType(uVar17,uVar18,&uStack_b4,&uStack_b0,iVar9,iVar16,*piVar24,uVar12);
          iVar20 = *(int *)(param_1 + 0x15c);
          iVar16 = FUN_0000a3f0(uVar17,uVar18);
          uStack_b8 = iVar20 * iVar16;
          iVar19 = uStack_b8 * *(int *)(param_1 + 0x160);
          iVar6 = _valloc((uint)uVar3 * iVar19);
          uVar22 = uVar17;
          uVar12 = uVar18;
          iVar16 = iVar6;
          uVar13 = uStack_b8;
          FUN_00031340(param_1,piVar24,iVar15,iVar14,uVar17,uVar18,iVar6,uStack_b8);
          iVar20 = param_3 * uStack_b8;
          iVar9 = FUN_0000a3f0(uVar17,uVar18);
          uStack_bc = iVar6 + iVar21 * iVar19 + iVar20 + param_2 * iVar9;
          _glgProcessPixels(puVar5,&uStack_bc,iVar15,iVar14,uVar22,uVar12,iVar16,uVar13);
          _vfree(iVar6);
          return 1;
        }
      }
    }
    uVar8 = 1;
  }
  else {
    if (!bVar4) {
      uVar8 = ((int (*)())FUN_00028350)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,uVar22,
                           param_10);
      return uVar8;
    }
LAB_00029bd0:
    uVar8 = 0;
  }
  return uVar8;
}

/* FUN_00029c00 @ 0x29c00 (1624 bytes) */
int FUN_00029c00(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  float *param_2;
  int param_3;
  int param_4;
  float *param_5;
  int param_6;
  uint param_7;
  uint param_8;
  int param_9;
  int param_10;
  undefined4 param_11;
{
  uint uVar1;
  byte bVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  double dVar6;
  double dVar7;
  float fVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 extraout_r4;
  float *pfVar13;
  float *pfVar14;
  float *pfVar15;
  float *pfVar16;
  float *pfVar17;
  float fVar18;
  undefined4 uVar19;
  int iVar20;
  int iVar21;
  float local_168;
  float local_164;
  float local_160;
  float local_15c;
  undefined4 local_158;
  float local_154;
  float local_150;
  float local_14c;
  float afStack_148 [36];
  undefined4 local_b8;
  undefined4 uStack_b4;
  longlong local_b0;
  undefined4 local_a8;
  float *pfStack_a4;
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
  float *pfStack_74;
  undefined4 local_70;
  uint uStack_6c;
  undefined4 local_68;
  uint uStack_64;
  
  iVar21 = param_1 + 0x240;
  iVar20 = param_3 * param_4;
  uVar19 = *(undefined4 *)(param_1 + 0x248);
  iVar9 = *(int *)(*(int *)(param_1 + 0x244) + 0x10);
  fVar4 = FLOAT_001aa0e8;
  if (*(float *)(((unsigned char *)0x00002e4c) + iVar9) < 0.0) {
    fVar4 = FLOAT_001aa114;
  }
  fVar3 = FLOAT_001aa0e8;
  if (*(float *)(((unsigned char *)0x00002e48) + iVar9) < 0.0) {
    fVar3 = FLOAT_001aa114;
  }
  if (-*(float *)(((unsigned char *)0x00002e4c) + iVar9) < 0.0) {
    fVar4 = FLOAT_001aa0e8;
  }
  if (-*(float *)(((unsigned char *)0x00002e48) + iVar9) < 0.0) {
    fVar3 = FLOAT_001aa0e8;
  }
  if (param_10 != 0x1901) {
    if ((char)param_11 == '\0') {
      pfVar13 = afStack_148;
      iVar9 = param_4;
      pfVar14 = param_5;
      FUN_000a6140(iVar21,(*(uint *)(param_1 + 0x1cf8) ^ 1) & 1 | (uint)(param_10 == 0x1902) << 0xc,
                   pfVar13);
      FUN_0004b480(iVar21,*(uint *)(param_1 + 0x1ae4) >> 6 & 0xffff);
      *(uint *)(param_1 + 0x216c) = *(uint *)(param_1 + 0x216c) & 0xfffff800 | 0x80;
    }
    else {
      pfVar14 = afStack_148;
      pfVar13 = (float *)0x0;
      iVar9 = 0;
      FUN_00086ba0(iVar21,1,0,0,pfVar14);
    }
    iVar12 = iVar20 * 8 + 0x1b;
  }
  else {
    pfVar14 = afStack_148;
    pfVar13 = (float *)0x0;
    iVar9 = 1;
    FUN_00086ba0(iVar21,0,0,1,pfVar14);
    iVar12 = iVar20 * 0x10 + 0x19;
  }
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    iVar12 = iVar12 + 2;
  }
  puVar10 = (undefined4 *)(**(code **)(param_1 + 0x2998))(iVar21,iVar12);
  *(undefined4 **)(param_1 + 0x298c) = puVar10;
  puVar11 = puVar10;
  if (*(char *)(param_1 + 0x2a42) == '\0') {
    puVar11 = puVar10 + 2;
    *puVar10 = 0x5c8;
    puVar10[1] = 0x10000000;
    *(undefined1 *)(param_1 + 0x2a42) = 1;
  }
  *puVar11 = ((unsigned char *)0x000010c0U);
  puVar11[1] = *(undefined4 *)(param_1 + 0x216c);
  puVar11 = (undefined4 *)FUN_00083c90(iVar21,puVar11 + 2);
  dVar6 = DOUBLE_001aa1e0;
  fVar5 = FLOAT_001aa10c;
  pfStack_a4 = (float *)(param_8 ^ 0x80000000);
  local_b8 = 0x43300000;
  pfVar15 = (float *)(puVar11 + 2);
  uVar1 = (uint)(((double)CONCAT44(0x43300000,uVar19) - DOUBLE_001aa250) * DOUBLE_001aa240);
  local_b0 = (longlong)(int)uVar1;
  *puVar11 = ((unsigned char *)0x00001087U);
  puVar11[1] = uVar1 << 0x10 | uVar1 & 0xffff;
  local_158 = 0x3f800000;
  local_a8 = 0x43300000;
  local_160 = fVar5 / *(float *)(param_1 + 0x2a58) +
              (float)((double)CONCAT44(0x43300000,pfStack_a4) - dVar6);
  if (param_10 != 0x1901) {
    pfVar16 = (float *)0xc0003500;
    pfVar15 = (float *)(puVar11 + 4);
    puVar11[2] = iVar20 * 0x80000 | 0xc0003500;
    puVar11[3] = iVar20 * 0x10000 | 0x31;
    if (param_4 != 0) {
      uStack_84 = param_7 ^ 0x80000000;
      local_88 = 0x43300000;
      iVar9 = 0;
      pfVar13 = &local_168;
      fVar5 = (float)((double)CONCAT44(0x43300000,uStack_84) - dVar6) + fVar5;
      do {
        dVar6 = DOUBLE_001aa250;
        fVar18 = FLOAT_001aa0f0;
        local_164 = fVar5;
        if (param_3 != 0) {
          pfVar14 = (float *)0x43300000;
          pfVar17 = param_2;
          iVar20 = param_3;
          do {
            if (param_10 == 0x1902) {
              local_15c = *pfVar17;
              local_154 = *(float *)(param_9 + 0x30);
              local_150 = *(float *)(param_9 + 0x34);
              local_14c = *(float *)(param_9 + 0x38);
              local_168 = *(float *)(param_9 + 0x3c);
            }
            else {
              local_15c = *(float *)(param_9 + 8);
              fVar8 = *pfVar17;
              local_80 = 0x43300000;
              local_78 = 0x43300000;
              local_70 = 0x43300000;
              local_68 = 0x43300000;
              uStack_64 = (uint)fVar8 & 0xff;
              uStack_7c = (uint)fVar8 >> 0x18;
              pfVar16 = (float *)((uint)fVar8 >> 0x10 & 0xff);
              uStack_6c = (uint)fVar8 >> 8 & 0xff;
              local_168 = (float)((double)CONCAT44(0x43300000,uStack_7c) - dVar6) / fVar18;
              local_14c = (float)((double)CONCAT44(0x43300000,uStack_64) - dVar6) / fVar18;
              local_154 = (float)((double)CONCAT44(0x43300000,pfVar16) - dVar6) / fVar18;
              local_150 = (float)((double)CONCAT44(0x43300000,uStack_6c) - dVar6) / fVar18;
              pfStack_74 = pfVar16;
            }
            pfVar17 = (float *)((int)pfVar17 + param_6);
            *pfVar15 = local_164;
            pfVar15[1] = local_160;
            pfVar15[2] = local_15c;
            pfVar15[3] = 1.0;
            pfVar15[4] = local_154;
            pfVar15[5] = local_150;
            pfVar15[6] = local_14c;
            pfVar15[7] = local_168;
            pfVar15 = pfVar15 + 8;
            local_164 = fVar3 + local_164;
            iVar20 = iVar20 + -1;
          } while (iVar20 != 0);
        }
        iVar9 = iVar9 + 1;
        param_2 = (float *)((int)param_2 + (int)param_5);
        local_160 = fVar4 + local_160;
      } while (iVar9 != param_4);
    }
  }
  else {
    fVar18 = GH_U2F((unsigned int)((*(uint *)(param_1 + 0x1ce8) & 0xffff00ff | 0xff00)));
    pfVar16 = pfStack_a4;
    if (param_4 != 0) {
      uStack_9c = param_7 ^ 0x80000000;
      local_a0 = 0x43300000;
      iVar20 = 0;
      fVar5 = fVar5 / *(float *)(param_1 + 0x2a54) +
              (float)((double)CONCAT44(0x43300000,uStack_9c) - dVar6);
      do {
        dVar7 = DOUBLE_001aa250;
        dVar6 = DOUBLE_001aa240;
        local_164 = fVar5;
        if (param_3 != 0) {
          iVar9 = 1;
          pfVar14 = (float *)((unsigned char *)0x00001087U);
          pfVar13 = (float *)0x3f800000;
          pfVar16 = param_2;
          iVar12 = param_3;
          do {
            local_15c = *(float *)(param_9 + 8);
            local_154 = *(float *)(param_9 + 0x30);
            local_150 = *(float *)(param_9 + 0x34);
            local_14c = *(float *)(param_9 + 0x38);
            local_168 = *(float *)(param_9 + 0x3c);
            bVar2 = *(byte *)pfVar16;
            *pfVar15 = GH_U2F((unsigned int)(((unsigned char *)0x000013c2U)));
            pfVar16 = (float *)((int)pfVar16 + param_6);
            fVar18 = GH_U2F((unsigned int)(((uint)bVar2 | (uint)fVar18 & 0xffffff00)));
            pfVar15[1] = fVar18;
            uStack_94 = *(undefined4 *)(param_1 + 0x248);
            local_98 = 0x43300000;
            uVar1 = (uint)(((double)CONCAT44(0x43300000,uStack_94) - dVar7) * dVar6);
            local_90 = (longlong)(int)uVar1;
            pfVar15[5] = 9.19042e-41;
            pfVar15[6] = local_164;
            pfVar15[7] = local_160;
            pfVar15[8] = local_15c;
            pfVar15[2] = GH_U2F((unsigned int)(((unsigned char *)0x00001087U)));
            pfVar15[4] = -2.1282349;
            pfVar15[3] = GH_U2F((unsigned int)((uVar1 << 0x10 | uVar1 & 0xffff)));
            pfVar15[9] = 1.0;
            pfVar15[10] = local_154;
            pfVar15[0xb] = local_150;
            pfVar15[0xc] = local_14c;
            pfVar15[0xd] = local_168;
            pfVar15[0xe] = GH_U2F((unsigned int)(((unsigned char *)0x00001087U)));
            pfVar15[0xf] = *(float *)(param_1 + 0x1f0c);
            pfVar15 = pfVar15 + 0x10;
            local_164 = fVar3 + local_164;
            iVar12 = iVar12 + -1;
          } while (iVar12 != 0);
        }
        iVar20 = iVar20 + 1;
        param_2 = (float *)((int)param_2 + (int)param_5);
        local_160 = fVar4 + local_160;
      } while (param_4 != iVar20);
    }
  }
  *pfVar15 = GH_U2F((unsigned int)(((unsigned char *)0x00001087U)));
  pfVar15[1] = *(float *)(param_1 + 0x1f0c);
  *(float **)(param_1 + 0x298c) = pfVar15 + 2;
  uStack_b4 = uVar19;
  (**(code **)(param_1 + 0x299c))(iVar21,pfVar15 + 2);
  FUN_0009d3b0(iVar21,extraout_r4,pfVar13,iVar9,pfVar14,pfVar15,pfVar16);
  FUN_000872e0(iVar21,afStack_148);
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
  *(undefined4 *)(0x00002748 + param_1 + 4) = uVar3;
  puVar4 = (undefined4 *)FUN_00083c90(param_1,uVar3);
  *puVar4 = ((unsigned char *)0x000010c0U);
  dVar2 = DOUBLE_001aa250;
  puVar4[1] = 0x80;
  uVar1 = (uint)(((double)CONCAT44(0x43300000,uVar5) - dVar2) * DOUBLE_001aa240);
  puVar4[2] = ((unsigned char *)0x00001087U);
  puVar4[4] = ((unsigned char *)0x000012f0U);
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
  *(undefined4 **)(0x00002748 + param_1 + 4) = puVar4 + 0xc;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,puVar4 + 0xc);
  return;
}

/* FUN_0002a3d0 @ 0x2a3d0 (3968 bytes) */
int FUN_0002a3d0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  undefined *param_6;
  int param_7;
  int param_8;
  undefined4 *param_9;
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
  uint uVar17;
  undefined *puVar18;
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
  
  if (param_5 == 0x1909) {
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
  else if (param_5 < 0x190a) {
    if (param_5 == 0x1907) {
      iVar32 = 5;
      if ((param_6 != (undefined *)0x8363) && (iVar32 = 0x28, param_6 != (undefined *)0x8032)) {
        return 0;
      }
    }
    else if (param_5 < 0x1908) {
      if (param_5 != 0x1906) {
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
  else if (param_5 == 0x80e1) {
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
  else if (param_5 == 0x85b9) {
    iVar32 = 0x27;
    if ((param_6 != (undefined *)0x85ba) && (iVar32 = 0x26, param_6 != (undefined *)0x85bb)) {
      return 0;
    }
  }
  else {
    if (param_5 != 0x190a) {
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
  _pthread_mutex_lock(*(undefined4 *)(param_1 + 0xc));
  if (param_8 == 0) {
    puVar18 = ((unsigned char *)0x00002e6c) + *(int *)(param_1 + 0x10);
  }
  else {
    puVar18 = (undefined *)0x0;
  }
  FUN_0000a6e0(param_1,param_5,param_6,param_3,param_4,&local_108,auStack_104,local_100,puVar18);
  iVar26 = *(int *)*param_9;
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
      if (((((*(int *)param_9[1] != 0) && (iVar22 = FUN_0001e280(param_1,param_9,1), iVar22 == 0))
           || ((puVar18 = PTR_DAT_001e88c8, (int *)param_9[2] == (int *)0x0 ||
               (iVar22 = *(int *)param_9[2], iVar22 == 0)))) ||
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
      puVar30 = *(undefined4 **)param_9[2];
      piVar21 = puVar30 + 4;
      do {
        if (in_RESERVE != '\0') {
          iVar22 = storeWordConditionalIndexed(*piVar21 + 0x10000,0,piVar21);
          *piVar21 = iVar22;
          bVar35 = 2;
        }
        puVar16 = PTR_DAT_001e88d0;
      } while (!(bool)(bVar35 >> 1 & 1));
      puVar24[2] = *puVar30;
      puVar24[3] = uVar31 - *(int *)*param_9;
      _memcpy(puVar24 + 4,puVar16,0x2f4);
      fVar6 = fVar12 - fVar8;
      dVar40 = (double)fVar6;
      fVar2 = fVar4 - fVar5;
      dVar41 = (double)fVar2;
      dVar37 = (double)FLOAT_001aa0e8;
      puVar24[0x22] = 0;
      dVar39 = DOUBLE_001aa1e8;
      dVar38 = (double)(float)(dVar40 - dVar37);
      bVar1 = DOUBLE_001aa1e8 <= dVar38;
      puVar24[0xa4] = *(uint *)(puVar18 + iVar32 * 0x24 + 0x18) >> 0x1e | puVar24[0xa4] & 0xfffffffc
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
      uVar20 = *(uint *)(puVar18 + iVar32 * 0x24 + 0x1c);
      uVar28 = *(uint *)(puVar18 + iVar32 * 0x24 + 0x20);
      puVar24[0xac] =
           uVar20 >> 7 & 0x1f | uVar28 >> 3 & 0x400000 | (uVar20 & 0x70) << 5 |
           (uVar20 & 0xe) << 0xb | uVar28 >> 0xe & 0x38000 | uVar28 >> 8 & 0x1c0000;
      puVar16 = PTR_DAT_001e88c8;
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
      uVar17 = puVar24[0x8e];
      puVar24[0xae] =
           ((int)local_108 >> (*(uint *)(puVar18 + iVar32 * 0x24 + 0x14) & 7)) - 1U & 0x3fff |
           (iVar22 + -1) * 0x10 & 0xffff8000U | (iVar34 + -1) * 0x20 & 0xffff0000U;
      puVar24[0xa4] = (uVar31 - iVar26) * 0x20 | puVar24[0xa4] & 0x1f;
      bVar35 = ((unsigned char *)0x00002b7f)[param_1];
      uVar31 = (*(uint *)(puVar16 + (uint)bVar35 * 0x24 + 0x18) & 0x18) << 5;
      puVar24[0x8e] = uVar31 | uVar17 & 0xfffffcff;
      uVar20 = (*(uint *)(puVar16 + (uint)bVar35 * 0x24 + 0x18) & 6) << 9;
      puVar24[0x8e] = uVar20 | uVar31 | uVar17 & 0xfffff0ff;
      uVar28 = *(uint *)(puVar16 + (uint)bVar35 * 0x24 + 0x1c) >> 0x12 & 0x3000;
      puVar24[0x8e] = uVar28 | uVar20 | uVar31 | uVar17 & 0xffffc0ff;
      uVar7 = *(uint *)(puVar16 + (uint)bVar35 * 0x24 + 0x1c) >> 0xe & 0xc000;
      puVar24[0x8e] = uVar7 | uVar28 | uVar20 | uVar31 | uVar17 & 0xffff00ff;
      puVar24[0x8e] =
           *(uint *)(puVar16 + (uint)bVar35 * 0x24 + 0x18) >> 5 & 0x1f |
           uVar7 | uVar28 | uVar20 | uVar31 | uVar17 & 0xffff00e0;
      if ((*(uint *)(puVar16 + (uint)bVar35 * 0x24 + 0x14) & 0xfc000000) == 0) {
        puVar24[0x5a] = puVar24[0x5a] & 0xfffe3fff | 0x18000;
      }
      fVar14 = FLOAT_001aa12c;
      fVar13 = FLOAT_001aa10c;
      puVar30 = puVar24 + 0xcd;
      fVar6 = (float)((double)FLOAT_001aa0e8 / dVar41);
      fVar2 = (float)((double)FLOAT_001aa0e8 / dVar40);
      puVar24[0xb7] = uVar27 - 1 & 0x1fff | (uVar29 - 1) * 0x2000 & 0x3ffe000;
      puVar24[0xc1] = 0x31080;
      puVar24[0xc6] = ((unsigned char *)0x00001087U);
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
      puVar24[0xcf] = ((unsigned char *)0x00001393U);
      puVar24[0xd0] = 10;
      puVar24[0xd1] = ((unsigned char *)0x000013c6U);
      puVar24[0xd2] = 3;
      puVar24[0xd3] = 0x5c8;
      puVar24[0xd4] = 0x20000;
      puVar24[0xd5] = (*(unsigned char *)0x000010ea);
      uVar25 = *(undefined4 *)(param_1 + 0x1cfc);
      puVar24[0xd7] = ((unsigned char *)0x000010faU);
      puVar24[0xd6] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1da0);
      puVar24[0xd9] = 0xc0001000;
      puVar24[0xdb] = 0x11004;
      puVar24[0xd8] = uVar25;
      puVar24[0xdc] = *(undefined4 *)(param_1 + 0x1ca8);
      uVar25 = *(undefined4 *)(param_1 + 0x1cac);
      puVar24[0xde] = ((unsigned char *)0x00001008U);
      puVar24[0xdd] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1ca0);
      puVar24[0xe0] = (*(unsigned char *)0x000010e9);
      puVar24[0xdf] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1d20);
      puVar24[0xe2] = ((unsigned char *)0x000013c7U);
      puVar24[0xe1] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1cf0);
      puVar24[0xe4] = ((unsigned char *)0x000013c1U);
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
      uVar25 = *(undefined4 *)(0x00001dc4 + param_1);
      puVar24[0xea] = ((unsigned char *)0x000010aeU);
      puVar24[0x18b] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1d70);
      puVar24[0xec] = ((unsigned char *)0x00001394U);
      puVar24[0xeb] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1d30);
      puVar24[0xee] = ((unsigned char *)0x00001380U);
      puVar24[0xf0] = ((unsigned char *)0x00001002U);
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
      uVar25 = *(undefined4 *)(0x000026c8 + param_1 + 4);
      puVar24[0xf8] = 0x854;
      puVar24[0xf7] = uVar25;
      uVar25 = **(undefined4 **)(param_1 + 0x2680);
      puVar24[0xfa] = 0x878;
      puVar24[0xf9] = uVar25;
      uVar25 = **(undefined4 **)(param_1 + 0x2684);
      puVar24[0xfc] = ((unsigned char *)0x000013c0U);
      puVar24[0xfb] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1ce0);
      puVar24[0xfe] = ((unsigned char *)0x000012f0U);
      puVar24[0xfd] = uVar25;
      uVar31 = *(uint *)(param_1 + 0x1d2c);
      puVar24[0xff] = uVar31;
      if ((*(uint *)(puVar16 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x8000) == 0) {
        puVar24[0xff] = uVar31 & 0xfffffffe;
      }
      puVar24[0x100] = ((unsigned char *)0x000012f5U);
      uVar31 = *(uint *)(param_1 + 0x1c8c);
      puVar24[0x101] = uVar31;
      if ((*(uint *)(puVar16 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x8000) == 0) {
        puVar24[0x101] = uVar31 & 0xfffff7ff;
      }
      puVar24[0x102] = ((unsigned char *)0x000010a2U);
      uVar25 = *(undefined4 *)(param_1 + 0x1d7c);
      puVar24[0x104] = ((unsigned char *)0x00001381U);
      puVar24[0x103] = uVar25;
      uVar31 = *(uint *)(param_1 + 0x1cc0);
      puVar24[0x105] = uVar31;
      if ((*(uint *)(puVar16 + (uint)(byte)((unsigned char *)0x00002b7f)[param_1] * 0x24 + 0x18) & 0x4000) == 0) {
        puVar24[0x105] = uVar31 & 0xfffffffc;
      }
      puVar24[0x106] = ((unsigned char *)0x0000109eU);
      iVar22 = 0;
      iVar26 = 0;
      uVar25 = *(undefined4 *)(param_1 + 0x1d6c);
      puVar24[0x108] = ((unsigned char *)0x00001096U);
      puVar24[0x107] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1df8);
      puVar24[0x10a] = ((unsigned char *)0x00001041U);
      puVar24[0x107] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x29f0);
      puVar24[0x10c] = ((unsigned char *)0x00001046U);
      puVar24[0x10b] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1dfc);
      puVar24[0x10e] = ((unsigned char *)0x00001094U);
      puVar24[0x126] = ((unsigned char *)0x00001095U);
      puVar24[0x110] = ((unsigned char *)0x00001095U);
      puVar24[0x14c] = ((unsigned char *)0x00001180U);
      puVar24[0x112] = ((unsigned char *)0x00001095U);
      puVar24[0x114] = ((unsigned char *)0x00001095U);
      puVar24[0x116] = ((unsigned char *)0x00001095U);
      puVar24[0x10d] = uVar25;
      puVar24[0x118] = ((unsigned char *)0x00001095U);
      puVar24[0x11a] = ((unsigned char *)0x00001095U);
      puVar24[0x11c] = ((unsigned char *)0x00001095U);
      puVar24[0x11e] = ((unsigned char *)0x00001095U);
      puVar24[0x120] = ((unsigned char *)0x00001095U);
      puVar24[0x122] = ((unsigned char *)0x00001095U);
      puVar24[0x124] = ((unsigned char *)0x00001095U);
      puVar24[0x128] = 0xc0221000;
      puVar24[0x10f] = 0;
      puVar24[0x14d] = 2;
      puVar24[0x14e] = ((unsigned char *)0x00001189U);
      puVar24[0x150] = ((unsigned char *)0x00001181U);
      puVar24[0x152] = ((unsigned char *)0x0000118dU);
      puVar24[0x154] = ((unsigned char *)0x0000118eU);
      puVar24[0x156] = ((unsigned char *)0x0000118cU);
      puVar24[0x158] = ((unsigned char *)0x000011a9U);
      uVar25 = *(undefined4 *)(param_1 + 0x257c);
      puVar24[0x15a] = ((unsigned char *)0x000011aaU);
      puVar24[0x159] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x2580);
      puVar24[0x15c] = ((unsigned char *)0x000011abU);
      puVar24[0x15b] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x2584);
      puVar24[0x15e] = ((unsigned char *)0x000011acU);
      puVar24[0x15d] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x2588);
      puVar24[0x160] = ((unsigned char *)0x000010c0U);
      puVar24[0x15f] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x216c);
      puVar24[0x162] = ((unsigned char *)0x000010c1U);
      puVar24[0x164] = ((unsigned char *)0x000010c8U);
      puVar24[0x166] = ((unsigned char *)0x0000101dU);
      puVar24[0x161] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x2128);
      puVar24[0x168] = ((unsigned char *)0x0000138aU);
      puVar24[0x16a] = ((unsigned char *)0x0000138eU);
      puVar24[0x16f] = 0;
      puVar24[0x16c] = ((unsigned char *)0x00001040U);
      puVar24[0x169] = 0;
      puVar24[0x16b] = 0;
      puVar24[0x16d] = 0;
      puVar24[0x167] = uVar25;
      puVar24[0x16e] = (*(unsigned char *)0x00001150);
      puVar24[0x170] = ((unsigned char *)0x00001100U);
      uVar25 = *(undefined4 *)(param_1 + 0x1f1c);
      puVar24[0x172] = ((unsigned char *)0x00001110U);
      puVar24[0x171] = uVar25;
      puVar24[0x173] = *(undefined4 *)(param_1 + 0x1f5c);
      puVar24[0x174] = (*(unsigned char *)0x00001120);
      uVar25 = *(undefined4 *)(param_1 + 0x1f9c);
      puVar24[0x176] = ((unsigned char *)0x00001130U);
      puVar24[0x175] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1fdc);
      puVar24[0x178] = ((unsigned char *)0x00001140U);
      puVar24[0x177] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x201c);
      puVar24[0x17a] = ((unsigned char *)0x000010f4U);
      puVar24[0x17b] = 0xaaaa;
      puVar24[0x17c] = ((unsigned char *)0x00001383U);
      puVar24[0x179] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1d34);
      puVar24[0x17e] = ((unsigned char *)0x00001386U);
      puVar24[0x17d] = uVar25;
      uVar25 = *(undefined4 *)(param_1 + 0x1d38);
      puVar24[0x180] = 0x110f8;
      puVar24[0x17f] = uVar25;
      puVar24[0x181] = *(undefined4 *)(param_1 + 0x1d98);
      uVar25 = *(undefined4 *)(param_1 + 0x1d50);
      puVar24[0x183] = ((unsigned char *)0x00001087U);
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
          puVar24 = (undefined4 *)((int (*)())FUN_0002cd50)(param_1,iVar34,iVar22,puVar24);
        }
        bVar1 = iVar22 != 0xf;
        iVar26 = iVar26 + 0x14;
        iVar32 = iVar32 + 4;
        iVar22 = iVar22 + 1;
      } while (bVar1);
      *(undefined4 **)(param_1 + 0x298c) = puVar24;
      (**(code **)(param_1 + 0x299c))(iVar33,puVar24);
    }
    _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
    uVar25 = 1;
  }
  else {
LAB_0002a9a0:
    _pthread_mutex_unlock(*(undefined4 *)(param_1 + 0xc));
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
void FUN_0002b740(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  int iVar1;
  int *extraout_r4;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 in_LR;
  
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
    fparam_1 = (double)FUN_0001a0f0(param_1,0x1000000);
    puVar3 = *(undefined4 **)(param_1 + 0x1dc);
    param_2 = extraout_r4;
  }
  *(undefined4 **)(param_1 + 0x1dc) = puVar3 + 2;
  puVar3[1] = 0;
  *puVar3 = ((unsigned char *)0x000013d6U);
  ((unsigned char *)0x00002b7e)[param_1] = 1;
  ((void (*)())FUN_00090470)(param_1 + 0x240,param_2,param_3,param_4,param_5,param_6,puVar3,fparam_1,fparam_2,
               fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
               (double)CONCAT44(in_LR,(*(unsigned int *)((unsigned char *)&(fparam_9) + 4))));
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
          *puVar10 = ((unsigned char *)0x000010b2U);
          puVar10[2] = ((unsigned char *)0x000013d7U);
          puVar10[3] = 0;
          puVar10[1] = 1 << (uVar6 & 0x3f);
          uVar6 = uVar6 + 1;
          puVar10 = puVar10 + 4;
          uVar7 = uVar7 - 1;
        } while (uVar7 != 0);
      }
      param_2 = puVar10 + 2;
      *puVar10 = ((unsigned char *)0x000010b2U);
      puVar10[1] = 0xf;
    }
    else {
      puVar9[5] = 0;
      puVar9[4] = ((unsigned char *)0x000013c5U);
      uVar6 = 0;
      iVar16 = 2;
      puVar13 = puVar9 + 6;
      do {
        puVar9 = puVar13;
        *puVar9 = ((unsigned char *)0x000012faU);
        puVar9[2] = ((unsigned char *)0x000013d7U);
        puVar9[3] = 0;
        puVar9[1] = 1 << (uVar6 & 0x3f);
        uVar6 = uVar6 + 1;
        iVar16 = iVar16 + -1;
        puVar13 = puVar9 + 4;
      } while (iVar16 != 0);
      puVar9[4] = ((unsigned char *)0x000012faU);
      puVar9[7] = uVar12;
      param_2 = puVar9 + 8;
      puVar9[5] = 3;
      puVar9[6] = ((unsigned char *)0x000013c5U);
    }
    *piVar8 = 1;
  }
  return param_2;
}

/* FUN_0002bbc4 @ 0x2bbc4 (564 bytes) */
void FUN_0002bbc4(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 *extraout_r4;
  undefined4 *puVar7;
  undefined *puVar8;
  uint *puVar9;
  int iVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  undefined4 *puVar14;
  int iVar15;
  int iVar16;
  char in_RESERVE;
  byte in_cr0;
  undefined4 in_LR;
  
  iVar16 = *(int *)(param_1 + 0x2610);
  iVar15 = *(int *)(param_1 + 0x261c);
  uVar13 = *(undefined4 *)(param_1 + 0x1cf8);
  puVar14 = (undefined4 *)**(undefined4 **)(param_1 + 0x234);
  if (iVar16 == 1) {
    if (iVar15 == 2) {
      iVar16 = 2;
      iVar10 = 8;
    }
    else {
      iVar10 = 4;
    }
  }
  else {
    iVar10 = iVar16 << 2;
  }
  piVar3 = puVar14 + 4;
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 0x10000,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  puVar9 = *(uint **)(param_1 + 0x1dc);
  puVar7 = param_2;
  if (*(uint **)(param_1 + 0x1e0) <= puVar9 + iVar10 + 0x15) {
    fparam_1 = (double)FUN_0001a0f0(param_1,0x1000000);
    puVar9 = *(uint **)(param_1 + 0x1dc);
    puVar7 = extraout_r4;
  }
  puVar8 = (undefined *)0x0;
  puVar2 = (undefined4 *)((uint)(puVar9 + 0xb) & 0xffffffe0);
  puVar12 = puVar2 + 4;
  *puVar9 = (((int)puVar2 - (int)puVar9) + -8) * 0x4000 | 0xc0001000;
  puVar2[-1] = (int)puVar2 - (int)puVar9;
  puVar4 = *(uint **)(param_1 + 0x1d8);
  puVar11 = (undefined4 *)*puVar4;
  *puVar4 = (int)puVar2 - (int)puVar4 >> 2 | (uint)puVar11;
  *(undefined4 **)(param_1 + 0x1d8) = puVar2;
  *puVar2 = 0x3b000000;
  uVar5 = *puVar14;
  puVar2[2] = 0;
  puVar2[1] = uVar5;
  puVar2[3] = *param_2;
  if (iVar15 == 2) {
    puVar2[5] = 0;
    puVar2[4] = ((unsigned char *)0x000013c5U);
    uVar6 = 0;
    puVar8 = ((unsigned char *)0x000012faU);
    puVar9 = (uint *)((int)((unsigned char *)0x0) + 1);
    iVar15 = 2;
    puVar11 = puVar2 + 6;
    do {
      puVar14 = puVar11;
      *puVar14 = ((unsigned char *)0x000012faU);
      puVar14[2] = ((unsigned char *)0x000013d7U);
      puVar14[3] = 0;
      puVar14[1] = 1 << (uVar6 & 0x3f);
      uVar6 = uVar6 + 1;
      puVar11 = puVar14 + 4;
      iVar15 = iVar15 + -1;
    } while (iVar15 != 0);
    *puVar11 = ((unsigned char *)0x000012faU);
    puVar14[7] = uVar13;
    puVar12 = puVar14 + 8;
    puVar14[5] = 3;
    puVar14[6] = ((unsigned char *)0x000013c5U);
  }
  else {
    if (iVar16 != 0) {
      uVar6 = 0;
      puVar8 = ((unsigned char *)0x000010b2U);
      puVar9 = (uint *)((int)((unsigned char *)0x0) + 1);
      puVar11 = (undefined4 *)0x0;
      do {
        *puVar12 = ((unsigned char *)0x000010b2U);
        puVar12[2] = ((unsigned char *)0x000013d7U);
        puVar12[3] = 0;
        puVar12[1] = 1 << (uVar6 & 0x3f);
        uVar6 = uVar6 + 1;
        puVar12 = puVar12 + 4;
        iVar16 = iVar16 + -1;
      } while (iVar16 != 0);
    }
    *puVar12 = ((unsigned char *)0x000010b2U);
    puVar12[1] = 0xf;
    puVar12 = puVar12 + 2;
  }
  *(undefined4 **)(param_1 + 0x1dc) = puVar12;
  ((unsigned char *)0x00002b7e)[param_1] = 0;
  ((void (*)())FUN_00090470)(param_1 + 0x240,puVar7,param_3,param_4,puVar8,puVar9,puVar11,fparam_1,fparam_2,
               fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,
               (double)CONCAT44(in_LR,(*(unsigned int *)((unsigned char *)&(fparam_9) + 4))));
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
  return *(undefined4 *)(0x00002748 + param_1 + 4);
}

/* FUN_0002be80 @ 0x2be80 (4 bytes) */
int FUN_0002be80()
{
  return;
}

/* FUN_0002be90 @ 0x2be90 (12 bytes) */
int FUN_0002be90(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  FUN_000a3be0(param_1 + 0x240,param_3,param_3,param_4,param_5,param_6,param_7);
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
void FUN_0002c020(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,uint param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  uint uVar1;
  int iVar2;
  double in_stack_ffffffb8;
  
  uVar1 = *(uint *)(param_1 + 0x1874);
  *(uint *)(param_1 + 0x1874) = uVar1 & 0x3fffffff;
  if ((param_2 == 0) && (param_7 = *(uint *)(param_1 + 0x1928) & 2, param_7 != 0)) {
    iVar2 = 1;
    *(uint *)(param_1 + 0x1874) = uVar1 & 0x3fffffff | 0x80000000;
  }
  else {
    iVar2 = 0;
  }
  if (iVar2 != *(int *)(param_1 + 0x192c)) {
    ((void (*)())FUN_00083c80)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,fparam_1,fparam_2,fparam_3,
                 fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffb8);
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
  puVar5[1] = *(uint *)(0x000026c8 + param_1 + 4);
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
  ushort *puVar1;
  bool bVar2;
  code *pcVar3;
  uint *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  undefined4 local_48;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  
  uVar8 = param_2[3];
  iVar10 = *(int *)(param_1 + 4);
  uVar7 = (uint)((uVar8 & 0x10000000) != *(uint *)(param_1 + 0x2780));
  if ((((*param_2 == 0) && (param_2[1] == 0)) && (param_2[2] == 0)) &&
     ((((uVar8 & 0xffefffff) == 0 && (param_2[4] == 0)) && (uVar7 == 0)))) {
LAB_0002c610:
    uVar7 = *(uint *)(param_1 + 0x2488);
  }
  else {
    if ((((param_2[2] & 0x3f000008) != 0) || ((uVar8 & 0x4c00003) != 0)) ||
       ((*(char *)(iVar10 + 0x2a43) != '\0' || (uVar7 != 0)))) {
      FUN_00090990(param_1,param_2);
      FUN_00090840(param_1);
    }
    if (*(char *)(iVar10 + 0x20) == '\0') {
      FUN_000a7d10(param_1);
    }
    FUN_00065370(param_1);
    FUN_00090960(param_1);
    uVar8 = *param_2;
    if (((uVar8 & 0x20000000) != 0) || (*(char *)(iVar10 + 0x2a43) != '\0')) {
      FUN_00022eb0(iVar10,0);
      uVar8 = *param_2;
    }
    if ((((uVar8 & 0x180) != 0) || (*(char *)(iVar10 + 0x2a43) != '\0')) &&
       (*(int *)(iVar10 + 0x150) == 0)) {
      iVar9 = *(int *)(param_1 + 4);
      iVar11 = 0;
      iVar13 = *(int *)(iVar9 + 0x10);
      iVar12 = param_1;
      do {
        puVar1 = (ushort *)(((unsigned char *)0x00002dba) + iVar13);
        iVar13 = iVar13 + 2;
        uVar5 = FUN_00016fc0((uint)*puVar1,*(undefined4 *)(iVar9 + 0x154));
        bVar2 = iVar11 != 3;
        iVar11 = iVar11 + 1;
        *(undefined4 *)(iVar12 + 0x2460) = uVar5;
        iVar12 = iVar12 + 4;
      } while (bVar2);
      puVar6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x22d);
      iVar12 = *(int *)(param_1 + 0x2460);
      *(undefined4 **)(0x00002748 + param_1 + 4) = puVar6;
      if (((iVar12 == 1) && (uVar8 = *(uint *)(iVar9 + 0x154), (uVar8 & 0x800) == 0)) &&
         (((uVar8 & 0x20) != 0 && ((uVar8 & 0x400) != 0)))) {
        (**(code **)(param_1 + 0x275c))(param_1,puVar6);
        if (*(int *)(iVar9 + 0x1e4) + 0x28U < *(uint *)(iVar9 + 0x1dc)) {
          FUN_0001a0f0(iVar9,0x1000000);
        }
        in_r5 = &local_48;
        in_r6 = 4;
        uVar7 = 0xffff3fc0;
        in_r7 = 0;
        in_r8 = 0;
        uVar8 = *(uint *)(iVar9 + 0x3c) | 0x800;
        *(uint *)(iVar9 + 0x154) = uVar8;
        *(uint *)(iVar9 + 0x3c) = uVar8;
        local_48 = *(undefined4 *)(*(int *)(iVar9 + 0xf8) + 8);
        local_44 = *(uint *)(iVar9 + 0x3c) & 0xffff3fc0;
        local_40 = *(undefined4 *)(iVar9 + 0xfc);
        local_3c = *(undefined4 *)(iVar9 + 0x100);
        _io_connect_method_scalarI_structureI(*(undefined4 *)(iVar9 + 4),0,in_r5,4,0,0);
        puVar6 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x22d);
        iVar12 = *(int *)(param_1 + 0x2460);
        *(undefined4 **)(0x00002748 + param_1 + 4) = puVar6;
      }
      iVar12 = FUN_0001a010(iVar9,iVar12,in_r5,in_r6,in_r7,in_r8,uVar7);
      if (iVar12 == 0) {
        puVar4 = *(uint **)(iVar9 + 0x1d8);
        *puVar4 = (int)puVar6 - (int)puVar4 >> 2 | *puVar4;
        *(undefined4 **)(iVar9 + 0x1d8) = puVar6;
        *puVar6 = 0x29000000;
        puVar6[1] = *(undefined4 *)(param_1 + 0x2460);
        puVar6[2] = *(undefined4 *)(param_1 + 0x2464);
        puVar6[3] = *(undefined4 *)(param_1 + 0x2468);
        uVar5 = *(undefined4 *)(param_1 + 0x246c);
        puVar6[5] = 0x11;
        puVar6[4] = uVar5;
        puVar6[6] = *(undefined4 *)(param_1 + 0x1ae0);
        puVar6[7] = *(undefined4 *)(param_1 + 0x1ab0);
      }
      else {
        puVar4 = *(uint **)(iVar9 + 0x1d8);
        *puVar4 = (int)puVar6 - (int)puVar4 >> 2 | *puVar4;
        *(undefined4 **)(iVar9 + 0x1d8) = puVar6;
        *puVar6 = 0x29000000;
        uVar5 = *(undefined4 *)(param_1 + 0x2460);
        puVar6[4] = 0x11;
        puVar6[5] = 0x10;
        puVar6[2] = 0x11;
        puVar6[3] = 0x11;
        puVar6[1] = uVar5;
        puVar6[6] = *(undefined4 *)(param_1 + 0x1ae0);
        puVar6[7] = *(undefined4 *)(param_1 + 0x1ab0);
      }
      pcVar3 = *(code **)(param_1 + 0x275c);
      *(undefined4 **)(0x00002748 + param_1 + 4) = puVar6 + 0x39;
      (*pcVar3)(param_1);
    }
    if (*(short *)((int)param_2 + 6) != 0) {
      ((int (*)())FUN_0002ce40)(param_1,param_2);
    }
    if (*(char *)(param_1 + 0x2435) == '\0') goto LAB_0002c610;
    *(int *)(param_1 + 0x2440) = param_1 + 0x249c;
    *(int *)(param_1 + 0x2444) = param_1 + 0x24bc;
    *(undefined4 *)(param_1 + 0x2494) = 0;
    uVar7 = *(uint *)(param_1 + 0x2488) | 4;
    *(uint *)(param_1 + 0x2488) = uVar7;
  }
  if (((uVar7 & 4) == 0) && (*(char *)(param_1 + 0x247d) == '\0')) {
    if (*(char *)(param_1 + 0x2595) == '\0') {
      uVar7 = param_2[3] & 0x100000;
    }
    else {
      uVar7 = *(uint *)(*(int *)(iVar10 + 0x14) + 0x120);
    }
    if ((uVar7 == 0) && ((*param_2 & 0x800000) == 0)) goto LAB_0002c67c;
  }
  ((int (*)())FUN_00027990)(param_1);
LAB_0002c67c:
  if ((((param_2[3] & 0x100000) != 0) || ((*(uint *)(param_1 + 0x2488) & 4) != 0)) ||
     (*(char *)(param_1 + 0x247d) != '\0')) {
    FUN_0001fd00(param_1);
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
  int *piVar1;
  undefined *puVar2;
  uint uVar3;
  int *piVar4;
  undefined1 uVar6;
  undefined4 uVar5;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffff78;
  double in_stack_ffffff80;
  double in_stack_ffffff88;
  double in_stack_ffffff90;
  double in_stack_ffffff98;
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
  
  iVar10 = param_1 + 0x240;
  _memset(iVar10,0,0x2950);
  ((unsigned char *)0x00002b7d)[param_1] = 0;
  ((unsigned char *)0x00002b7c)[param_1] = 1;
  *(uint *)(param_1 + 0x258c) = *(uint *)(param_1 + 0x258c) & 0xfffffffc | 1;
  uVar6 = FUN_0002f410(*(undefined4 *)(param_1 + 0x154));
  ((unsigned char *)0x00002b7f)[param_1] = uVar6;
  *(int *)(param_1 + 0x2680) = param_1 + 0x26dc;
  *(int *)(param_1 + 0x2684) = param_1 + 0x26fc;
  *(undefined4 *)(param_1 + 0x1ec) = 0;
  *(undefined4 *)(param_1 + 0x1f0) = 0;
  uVar5 = _malloc(0x44);
  *(undefined4 *)(((unsigned char *)0x000027cc) + param_1) = uVar5;
  _memset(uVar5,0,0x44);
  uVar5 = _malloc(0x44);
  *(undefined4 *)(0x000027d0 + param_1) = uVar5;
  _memset(uVar5,0,0x44);
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
  uVar5 = 0;
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
  FUN_000a0f90(iVar10);
  fparam_1 = (double)FUN_00052cc0(iVar10);
  *(undefined4 *)(((unsigned char *)0x00002b74) + param_1) = 0;
  *(undefined4 *)(param_1 + 0x26a0) = 0;
  *(undefined4 *)(param_1 + 0x26b0) = 0;
  *(undefined4 *)(((unsigned char *)0x00002b78) + param_1) = 0;
  iVar11 = 0x10;
  iVar8 = iVar10;
  do {
    *(undefined1 *)(iVar8 + 0x2784) = 0;
    iVar8 = iVar8 + 1;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  ((unsigned char *)0x00002b82)[param_1] = 0;
  puVar2 = PTR_DAT_001e8994;
  *(undefined4 *)(0x000026c8 + param_1) = 7;
  uVar7 = 0;
  *(undefined1 *)(param_1 + 0x2a43) = 1;
  *(undefined1 *)(param_1 + 0x26bd) = 1;
  iVar8 = 0x10;
  piVar1 = (int *)((uint)(puVar2 + 0xc) & 0xfffffff3);
  *(int **)PTR_DAT_001e88cc = piVar1;
  piVar4 = piVar1;
  do {
    uVar3 = uVar7 << 8 | uVar7;
    uVar7 = uVar7 + 1;
    uVar3 = uVar3 | uVar3 << 0x10;
    *piVar4 = uVar3 + 0x2030001;
    piVar4[3] = uVar3 + 0xe0f0c0d;
    piVar4[1] = uVar3 + 0x6070405;
    piVar4[2] = uVar3 + 0xa0b0809;
    piVar4 = piVar4 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  uVar3 = 0xffffffff;
  uVar9 = 0xffffffa0;
  iVar11 = 0x10;
  iVar8 = 0;
  piVar4 = piVar1;
  while( true ) {
    piVar4[0x40] = uVar3;
    uVar3 = 0xffffffff;
    if ((4 < iVar8) && (uVar3 = 0, iVar8 < 8)) {
      uVar3 = 0xffffffff >> (uVar9 + 0x40 & 0x3f);
    }
    piVar4[0x41] = uVar3;
    uVar3 = 0xffffffff;
    if ((8 < iVar8) && (uVar3 = 0, iVar8 < 0xc)) {
      uVar3 = 0xffffffff >> (uVar9 + 0x20 & 0x3f);
    }
    piVar4[0x42] = uVar3;
    uVar3 = 0xffffffff;
    if (0xc < iVar8) {
      uVar3 = 0xffffffff >> (uVar9 & 0x3f);
    }
    piVar4[0x43] = uVar3;
    iVar8 = iVar8 + 1;
    piVar4 = piVar4 + 4;
    uVar9 = uVar9 + 8;
    iVar11 = iVar11 + -1;
    if (iVar11 == 0) break;
    uVar3 = 0xffffffff;
    if ((0 < iVar8) && (uVar3 = 0, iVar8 < 4)) {
      uVar3 = 0xffffffff >> (iVar8 * 8 & 0x38U);
    }
  }
  ((unsigned char *)0x00002b88)[param_1] = 1;
  local_54 = DAT_001aa4e8;
  local_50 = DAT_001aa4ec;
  local_44 = DAT_001aa4f8;
  local_4c = DAT_001aa4f0;
  local_48 = DAT_001aa4f4;
  ((void (*)())FUN_000a9ac0)(iVar10,&local_54,uVar5,piVar1,uVar7,DAT_001aa4f8,DAT_001aa4e8,DAT_001aa4f4,fparam_1,
               in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,in_stack_ffffff78,in_stack_ffffff80,
               in_stack_ffffff88,in_stack_ffffff90,in_stack_ffffff98);
  ((int (*)())FUN_0002c6c0)(param_1);
  return;
}

/* FUN_0002cb40 @ 0x2cb40 (200 bytes) */
int FUN_0002cb40(param_1)
  int param_1;
{
  if (*(int *)(((unsigned char *)0x000027cc) + param_1) != 0) {
    _free(*(int *)(((unsigned char *)0x000027cc) + param_1));
  }
  if (*(int *)(0x000027d0 + param_1) != 0) {
    _free(*(int *)(0x000027d0 + param_1));
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
    _vfree(*(int *)(((unsigned char *)0x00002b74) + param_1));
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
uint FUN_0002cc30(int param_1,undefined4 param_2,uint param_3,uint param_4,undefined4 param_5,undefined4 param_6,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint in_r9;
  uint uVar4;
  double extraout_f1;
  double in_stack_ffffffa8;
  
  uVar3 = param_4;
  if ((int)param_4 < 4) {
    uVar4 = ((int (*)())FUN_0002bf30)(param_1,param_3,param_4);
    uVar2 = param_4;
    fparam_1 = extraout_f1;
  }
  else {
    in_r9 = param_3 & 1;
    iVar1 = (param_3 >> 3 & 1) + (param_3 >> 2 & 1) + (param_3 >> 1 & 1) + in_r9;
    uVar2 = param_3;
    uVar4 = param_4;
    if (((iVar1 == 2) || (iVar1 == 0)) || (param_3 == 2)) goto LAB_0002cce8;
    if (iVar1 == 3) {
      uVar4 = param_4 & 0xfffffffc;
    }
    else if (param_3 == 4) {
      uVar4 = ((int)param_4 / 3) * 3;
    }
    else {
      uVar4 = param_4 & 0xfffffffe;
    }
  }
  if (uVar4 == 0) {
    return 0;
  }
LAB_0002cce8:
  if (((unsigned char *)0x00002b80)[param_1] != '\0') {
    fparam_1 = (double)FUN_000a3be0(param_1 + 0x240,param_3,uVar2,uVar3,param_5,param_6,in_r9);
  }
  if (*(int *)(param_1 + 0x1b68) != 0) {
    ((void (*)())FUN_0002c020)(param_1 + 0x240,param_3,uVar2,uVar3,param_5,param_6,in_r9,fparam_1,fparam_2,
                 fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffa8);
  }
  *(undefined1 *)(param_1 + 0x2a5e) = 1;
  return uVar4;
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
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 *a1;
  int iVar4;
  uint a6;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  iVar5 = *(int *)(param_1 + 4);
  iVar6 = iVar5;
  for (uVar7 = (uint)*(ushort *)(param_2 + 6); uVar7 != 0; uVar7 = uVar7 >> 1) {
    if (((((uVar7 & 1) != 0) && (iVar4 = *(int *)(iVar6 + 0x18c), iVar4 != 0)) &&
        (*(short *)(*(int *)(iVar4 + 0x30) + 2) == 0x1902)) && (*(char *)(iVar4 + 200) == '\x01')) {
      puVar2 = (undefined4 *)(**(code **)(param_1 + 0x2758))(param_1,0x3fa);
      *(undefined4 **)(0x00002748 + param_1 + 4) = puVar2;
      a1 = puVar2 + 0x3f8;
      puVar1 = *(uint **)(iVar5 + 0x1d8);
      *puVar1 = (int)puVar2 - (int)puVar1 >> 2 | *puVar1;
      *(undefined4 **)(iVar5 + 0x1d8) = puVar2;
      *puVar2 = 0x45000000;
      puVar2[1] = 0x3ed;
      puVar2[2] = 0xd;
      puVar2[3] = **(undefined4 **)(*(int *)(iVar6 + 0x18c) + 0x34);
      a6 = (uint)*(byte *)(*(int *)(iVar6 + 0x18c) + 0x38);
      puVar2[0x3ed] = ((unsigned char *)0x000013c4U);
      puVar2[4] = a6;
      puVar2[0x3f6] = ((unsigned char *)0x000013caU);
      puVar2[0x3f4] = ((unsigned char *)0x000013ccU);
      puVar2[0x3ef] = 0x113c8;
      puVar2[0x3f2] = ((unsigned char *)0x000013cdU);
      *(undefined4 **)(0x00002748 + param_1 + 4) = a1;
      (**(code **)(param_1 + 0x275c))(param_1,a1,in_r5,in_r6,a1,0x113c8,a6,puVar2 + 0x3ed);
      if (*(int *)(iVar5 + 0x1e4) + 0x28U < *(uint *)(iVar5 + 0x1dc)) {
        FUN_0001a0f0(iVar5,0x1000000);
      }
      *(undefined1 *)(*(int *)(iVar6 + 0x18c) + 200) = 0;
    }
    iVar6 = iVar6 + 4;
  }
  uVar7 = (uint)*(ushort *)(param_2 + 6);
  uVar3 = (**(code **)(param_1 + 0x2758))(param_1,0x96);
  *(undefined4 *)(0x00002748 + param_1 + 4) = uVar3;
  if (uVar7 != 0) {
    iVar4 = 0;
    iVar6 = iVar5;
    do {
      if ((uVar7 & 1) != 0) {
        uVar3 = ((int (*)())FUN_0002cd50)(iVar5,*(undefined4 *)(iVar6 + 0x18c),iVar4,uVar3);
      }
      uVar7 = uVar7 >> 1;
      iVar4 = iVar4 + 1;
      iVar6 = iVar6 + 4;
    } while (uVar7 != 0);
  }
  *(undefined4 *)(0x00002748 + param_1 + 4) = uVar3;
                    
                    
  (**(code **)(param_1 + 0x275c))(param_1,uVar3);
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
void FUN_0002d2b0(int param_1,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
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
  double fparam_1_00;
  float fStack0000001c;
  float fStack00000028;
  
  fStack00000028 = (float)fparam_4;
  fStack0000001c = (float)fparam_1;
  if (*(char *)(param_1 + 0x37) == '\0') {
    return;
  }
  dVar7 = (double)FLOAT_001aa0d4;
  dVar11 = DOUBLE_001aa228;
  if ((dVar7 <= fparam_1) &&
     (dVar7 = fparam_1, dVar11 = fparam_1, (double)FLOAT_001aa0e8 < fparam_1)) {
    dVar7 = (double)FLOAT_001aa0e8;
    dVar11 = DOUBLE_001aa200;
  }
  dVar8 = (double)FLOAT_001aa0d4;
  dVar12 = DOUBLE_001aa228;
  if ((dVar8 <= fparam_2) &&
     (dVar8 = fparam_2, dVar12 = fparam_2, (double)FLOAT_001aa0e8 < fparam_2)) {
    dVar8 = (double)FLOAT_001aa0e8;
    dVar12 = DOUBLE_001aa200;
  }
  dVar9 = (double)FLOAT_001aa0d4;
  dVar13 = DOUBLE_001aa228;
  if ((dVar9 <= fparam_3) &&
     (dVar9 = fparam_3, dVar13 = fparam_3, (double)FLOAT_001aa0e8 < fparam_3)) {
    dVar9 = (double)FLOAT_001aa0e8;
    dVar13 = DOUBLE_001aa200;
  }
  fparam_1_00 = (double)fStack00000028;
  dVar10 = (double)FLOAT_001aa0d4;
  dVar14 = DOUBLE_001aa228;
  if ((dVar10 <= fparam_1_00) &&
     (dVar10 = fparam_1_00, dVar14 = fparam_1_00, (double)FLOAT_001aa0e8 < fparam_1_00)) {
    dVar10 = (double)FLOAT_001aa0e8;
    dVar14 = DOUBLE_001aa200;
  }
  dVar11 = dVar11 * DOUBLE_001aa258;
  if (DOUBLE_001aa1e8 <= dVar11) {
    fVar2 = GH_U2F((unsigned int)(((int)(dVar11 - DOUBLE_001aa1e8) + -0x80000000)));
  }
  else {
    fVar2 = GH_U2F((unsigned int)((int)dVar11));
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
    fVar6 = GH_U2F((unsigned int)(((int)(dVar14 - DOUBLE_001aa1e8) + -0x80000000)));
  }
  else {
    fVar6 = GH_U2F((unsigned int)((int)dVar14));
  }
  switch(*(char *)(param_1 + 0x37)) {
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
    fVar6 = GH_U2F((unsigned int)(((uint)fVar2 | (int)fVar6 << 8)));
    break;
  case '\x05':
    fVar6 = GH_U2F((unsigned int)((((uint)fVar2 & 0xf8) << 8 | (uVar3 & 0xfc) << 3 | uVar4 >> 3)));
    break;
  case '\x06':
    fVar6 = GH_U2F((unsigned int)((((uint)fVar6 & 0xf0) << 8 | ((uint)fVar2 & 0xf0) << 4 | uVar3 & 0xf0 |
                   uVar4 >> 4)));
    break;
  case '\a':
    fVar6 = GH_U2F((unsigned int)((((uint)fVar6 & 0x80) << 8 | ((uint)fVar2 & 0xf8) << 7 | (uVar3 & 0xf8) << 2 |
                   uVar4 >> 3)));
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
    fVar6 = (float)(uVar4 | (int)GH_F2U(fVar6) << 0x18 | (int)GH_F2U(fVar2) << 0x10 | uVar3 << 8);
    break;
  case '\t':
  case '\n':
  case '\x12':
  case '\x18':
  case '\x1e':
    fVar6 = GH_U2F((unsigned int)(((uint)fVar2 | uVar3 << 8 | (int)fVar6 << 0x18 | uVar4 << 0x10)));
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
    fVar6 = GH_U2F((unsigned int)((uVar3 | uVar3 << 0x10)));
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
    fVar6 = GH_U2F((unsigned int)((uVar3 & 0xffff | iVar1 << 0x10)));
    break;
  case '\x1f':
  case '!':
    uVar3 = ((uint (*)())FUN_0001d7c0)(fparam_1);
    fVar6 = GH_U2F((unsigned int)((uVar3 << 0x10 | uVar3)));
    break;
  case ' ':
    uVar3 = ((uint (*)())FUN_0001d7c0)(fparam_1_00);
    fVar6 = GH_U2F((unsigned int)((uVar3 << 0x10 | uVar3)));
    break;
  case '\"':
    uVar3 = ((uint (*)())FUN_0001d7c0)(fparam_1);
    iVar1 = ((uint (*)())FUN_0001d7c0)((double)fStack00000028);
    fVar6 = GH_U2F((unsigned int)((uVar3 | iVar1 << 0x10)));
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
    fVar6 = GH_U2F((unsigned int)((uVar3 | uVar4 | (uVar5 & 0x3ff) << 10)));
    break;
  case '(':
    fVar6 = GH_U2F((unsigned int)(((uint)fVar2 & 0xe0 | uVar3 >> 3 & 0x1c | uVar4 >> 6)));
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
    fVar6 = GH_U2F((unsigned int)((iVar1 << 8)));
  }
  *(float *)(param_1 + 0x28) = fVar6;
  return;
}

