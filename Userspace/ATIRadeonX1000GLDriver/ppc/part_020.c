#include "decls.h"

/* FUN_000dbcdc @ 0xdbcdc (192 bytes) */
int FUN_000dbcdc(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  uint uVar1;
  
  uVar1 = param_2 >> 0x1a & 3;
  FUN_000da904(param_1,"_shadowmode(",param_3,param_4,param_5,param_6,param_7,param_8);
  if (uVar1 == 1) {
    FUN_000da904(param_1,"z",param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else if (uVar1 == 0) {
    FUN_000da904(param_1,"never",param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else if (uVar1 == 2) {
    FUN_000da904(param_1,"unknown",param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else {
    *param_1 = *param_1 + 1;
    FUN_000da904(param_1,"!!invalid!!",param_3,param_4,param_5,param_6,param_7,param_8);
  }
  FUN_000da904(param_1,")",param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_000dbd9c @ 0xdbd9c (124 bytes) */
int FUN_000dbd9c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if (param_2 == 1) {
    FUN_000da904(param_1,"0",param_3,param_4,param_5,param_6,param_7,0xdbda8);
    return;
  }
  if (param_2 == 0) {
    FUN_000da904(param_1,"-",param_3,param_4,param_5,param_6,param_7,0xdbda8);
    return;
  }
  if (param_2 == 2) {
    FUN_000da904(param_1,"1",param_3,param_4,param_5,param_6,param_7,0xdbda8);
    return;
  }
  if (param_2 == 3) {
    FUN_000da904(param_1,"*",param_3,param_4,param_5,param_6,param_7,0xdbda8);
    return;
  }
  *param_1 = *param_1 + 1;
  FUN_000da904(param_1,"!!!invalid!!!",param_3,param_4,param_5,param_6,param_7,0xdbda8);
  return;
}

/* FUN_000dbe18 @ 0xdbe18 (284 bytes) */
int FUN_000dbe18(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  uint uVar1;
  uint uVar2;
  undefined1 auStack_38 [40];
  
  FUN_000db458(param_1,param_2 >> 0x10 & 0x1f,param_3,param_4,param_5,param_6,param_7,param_8);
  uVar1 = param_2 >> 0x15 & 0xff;
  FUN_001a32d0(auStack_38,"_usageIndex(%d)",uVar1,param_4,param_5,param_6,param_7,param_8);
  FUN_000da904(param_1,auStack_38,uVar1,param_4,param_5,param_6,param_7,param_8);
  if ((int)param_2 < 0) {
    uVar2 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    FUN_000da904(param_1,"_x(",uVar1,param_4,param_5,param_6,param_7,param_8);
    ((int (*)())FUN_000dbd9c)(param_1,uVar2 & 3,uVar1,param_4,param_5,param_6,param_7);
    FUN_000da904(param_1,")",uVar1,param_4,param_5,param_6,param_7,param_8);
    FUN_000da904(param_1,"_y(",uVar1,param_4,param_5,param_6,param_7,param_8);
    ((int (*)())FUN_000dbd9c)(param_1,uVar2 >> 2 & 3,uVar1,param_4,param_5,param_6,param_7);
    FUN_000da904(param_1,")",uVar1,param_4,param_5,param_6,param_7,param_8);
    FUN_000da904(param_1,"_z(",uVar1,param_4,param_5,param_6,param_7,param_8);
    ((int (*)())FUN_000dbd9c)(param_1,uVar2 >> 4 & 3,uVar1,param_4,param_5,param_6,param_7);
    FUN_000da904(param_1,")",uVar1,param_4,param_5,param_6,param_7,param_8);
    FUN_000da904(param_1,"_w(",uVar1,param_4,param_5,param_6,param_7,param_8);
    ((int (*)())FUN_000dbd9c)(param_1,uVar2 >> 6 & 3,uVar1,param_4,param_5,param_6,param_7);
    FUN_000da904(param_1,")",uVar1,param_4,param_5,param_6,param_7,param_8);
  }
  return;
}

/* FUN_000dbf34 @ 0xdbf34 (356 bytes) */
int FUN_000dbf34(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  uint uVar1;
  uint uVar2;
  undefined1 auStack_38 [40];
  
  FUN_000db458(param_1,param_2 >> 0x10 & 0x1f,param_3,param_4,param_5,param_6,param_7,param_8);
  uVar1 = param_2 >> 0x15 & 0xff;
  FUN_001a32d0(auStack_38,"_usageIndex(%d)",uVar1,param_4,param_5,param_6,param_7,param_8);
  FUN_000da904(param_1,auStack_38,uVar1,param_4,param_5,param_6,param_7,param_8);
  if ((int)param_2 < 0) {
    uVar2 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    FUN_000da904(param_1,"_x(",uVar1,param_4,param_5,param_6,param_7,param_8);
    ((int (*)())FUN_000dbd9c)(param_1,uVar2 & 3,uVar1,param_4,param_5,param_6,param_7);
    FUN_000da904(param_1,")",uVar1,param_4,param_5,param_6,param_7,param_8);
    FUN_000da904(param_1,"_y(",uVar1,param_4,param_5,param_6,param_7,param_8);
    ((int (*)())FUN_000dbd9c)(param_1,uVar2 >> 2 & 3,uVar1,param_4,param_5,param_6,param_7);
    FUN_000da904(param_1,")",uVar1,param_4,param_5,param_6,param_7,param_8);
    FUN_000da904(param_1,"_z(",uVar1,param_4,param_5,param_6,param_7,param_8);
    ((int (*)())FUN_000dbd9c)(param_1,uVar2 >> 4 & 3,uVar1,param_4,param_5,param_6,param_7);
    FUN_000da904(param_1,")",uVar1,param_4,param_5,param_6,param_7,param_8);
    FUN_000da904(param_1,"_w(",uVar1,param_4,param_5,param_6,param_7,param_8);
    ((int (*)())FUN_000dbd9c)(param_1,uVar2 >> 6 & 3,uVar1,param_4,param_5,param_6,param_7);
    FUN_000da904(param_1,")",uVar1,param_4,param_5,param_6,param_7,param_8);
    if ((uVar2 & 0x100) != 0) {
      FUN_000da904(param_1,"_centroid",uVar1,param_4,param_5,param_6,param_7,param_8);
    }
    if ((uVar2 & 0x200) != 0) {
      FUN_000da904(param_1,"_constant",uVar1,param_4,param_5,param_6,param_7,param_8);
    }
    if ((uVar2 & 0x400) != 0) {
      FUN_000da904(param_1,"_noperspective",uVar1,param_4,param_5,param_6,param_7,param_8);
    }
  }
  return;
}

/* FUN_000dc098 @ 0xdc098 (276 bytes) */
int FUN_000dc098(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  uint uVar1;
  uint uVar2;
  undefined1 auStack_38 [40];
  
  uVar1 = param_2 >> 0x10 & 0x3f;
  FUN_001a32d0(auStack_38,"_elem(%d)",uVar1,param_4,param_5,param_6,param_7,param_8);
  FUN_000da904(param_1,auStack_38,uVar1,param_4,param_5,param_6,param_7,param_8);
  if ((int)param_2 < 0) {
    uVar2 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    FUN_000da904(param_1,"_x(",uVar1,param_4,param_5,param_6,param_7,param_8);
    ((int (*)())FUN_000dbd9c)(param_1,uVar2 & 3,uVar1,param_4,param_5,param_6,param_7);
    FUN_000da904(param_1,")",uVar1,param_4,param_5,param_6,param_7,param_8);
    FUN_000da904(param_1,"_y(",uVar1,param_4,param_5,param_6,param_7,param_8);
    ((int (*)())FUN_000dbd9c)(param_1,uVar2 >> 2 & 3,uVar1,param_4,param_5,param_6,param_7);
    FUN_000da904(param_1,")",uVar1,param_4,param_5,param_6,param_7,param_8);
    FUN_000da904(param_1,"_z(",uVar1,param_4,param_5,param_6,param_7,param_8);
    ((int (*)())FUN_000dbd9c)(param_1,uVar2 >> 4 & 3,uVar1,param_4,param_5,param_6,param_7);
    FUN_000da904(param_1,")",uVar1,param_4,param_5,param_6,param_7,param_8);
    FUN_000da904(param_1,"_w(",uVar1,param_4,param_5,param_6,param_7,param_8);
    ((int (*)())FUN_000dbd9c)(param_1,uVar2 >> 6 & 3,uVar1,param_4,param_5,param_6,param_7);
    FUN_000da904(param_1,")",uVar1,param_4,param_5,param_6,param_7,param_8);
  }
  return;
}

/* FUN_000dc1ac @ 0xdc1ac (280 bytes) */
int FUN_000dc1ac(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  FUN_000da904(param_1,"_x(",param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000dbd9c)(param_1,param_2 >> 0x10 & 3,param_3,param_4,param_5,param_6,param_7);
  FUN_000da904(param_1,")",param_3,param_4,param_5,param_6,param_7,param_8);
  FUN_000da904(param_1,"_y(",param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000dbd9c)(param_1,param_2 >> 0x12 & 3,param_3,param_4,param_5,param_6,param_7);
  FUN_000da904(param_1,")",param_3,param_4,param_5,param_6,param_7,param_8);
  FUN_000da904(param_1,"_z(",param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000dbd9c)(param_1,param_2 >> 0x14 & 3,param_3,param_4,param_5,param_6,param_7);
  FUN_000da904(param_1,")",param_3,param_4,param_5,param_6,param_7,param_8);
  FUN_000da904(param_1,"_w(",param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000dbd9c)(param_1,param_2 >> 0x16 & 3,param_3,param_4,param_5,param_6,param_7);
  FUN_000da904(param_1,")",param_3,param_4,param_5,param_6,param_7,param_8);
  if ((param_2 & 0x1000000) != 0) {
    FUN_000da904(param_1,"_center",param_3,param_4,param_5,param_6,param_7,param_8);
  }
  if ((param_2 & 0x2000000) != 0) {
    FUN_000da904(param_1,"_origin",param_3,param_4,param_5,param_6,param_7,param_8);
    return;
  }
  return;
}

/* FUN_000dc2c4 @ 0xdc2c4 (196 bytes) */
int FUN_000dc2c4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int iVar1;
  
  if (param_2 < 10) {
    iVar1 = 0;
    switch(param_2) {
    case 0:
      FUN_000da904(param_1,"_type(unknown)",param_3,param_4,param_5,param_6,iVar1,0xdc2d0);
      return;
    case 1:
      FUN_000da904(param_1,"_type(1d)",param_3,param_4,param_5,param_6,iVar1,0xdc2d0);
      return;
    case 2:
      FUN_000da904(param_1,"_type(2d)",param_3,param_4,param_5,param_6,iVar1,0xdc2d0);
      return;
    case 3:
      FUN_000da904(param_1,"_type(3d)",param_3,param_4,param_5,param_6,iVar1,0xdc2d0);
      return;
    case 4:
      FUN_000da904(param_1,"_type(cubemap)",param_3,param_4,param_5,param_6,iVar1,0xdc2d0);
      return;
    case 5:
      FUN_000da904(param_1,"_type(2dmsaa)",param_3,param_4,param_5,param_6,iVar1,0xdc2d0);
      return;
    case 6:
      FUN_000da904(param_1,"_type(4c)",param_3,param_4,param_5,param_6,iVar1,0xdc2d0);
      return;
    case 7:
      FUN_000da904(param_1,"_type(buffer)",param_3,param_4,param_5,param_6,iVar1,0xdc2d0);
      return;
    case 8:
      FUN_000da904(param_1,"_type(1darray)",param_3,param_4,param_5,param_6,iVar1,0xdc2d0);
      return;
    case 9:
      FUN_000da904(param_1,"_type(2darray)",param_3,param_4,param_5,param_6,iVar1,0xdc2d0);
      return;
    }
  }
  *param_1 = *param_1 + 1;
  FUN_000da904(param_1,"_type(!!!invalid!!!)",param_3,param_4,param_5,param_6,param_7,0xdc2d0);
  return;
}

/* FUN_000dc3b0 @ 0xdc3b0 (164 bytes) */
int FUN_000dc3b0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  char *pcVar1;
  undefined4 in_r10;
  uint uVar2;
  
  uVar2 = param_2 >> 0x1b & 3;
  ((int (*)())FUN_000dc2c4)(param_1,param_2 >> 0x18 & 7,param_3,param_4,param_5,param_6,param_7);
  if (uVar2 == 1) {
    pcVar1 = "_coordmode(normalized)";
  }
  else if (uVar2 == 0) {
    pcVar1 = "_coordmode(unknown)";
  }
  else if (uVar2 == 2) {
    pcVar1 = "_coordmode(unnormalized)";
  }
  else {
    pcVar1 = "_coordmode(!!!invalid!!!)";
    *param_1 = *param_1 + 1;
  }
  FUN_000da904(param_1,pcVar1,param_3,param_4,param_5,param_6,param_7,in_r10);
  return;
}

/* FUN_000dc454 @ 0xdc454 (104 bytes) */
int FUN_000dc454(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if (param_2 == 1) {
    FUN_000da904(param_1,"0",param_3,param_4,param_5,param_6,param_7,0xdc460);
    return;
  }
  if (param_2 != 0) {
    if (param_2 == 2) {
      FUN_000da904(param_1,"1",param_3,param_4,param_5,param_6,param_7,0xdc460);
      return;
    }
    *param_1 = *param_1 + 1;
    FUN_000da904(param_1,"!!!invalid!!!",param_3,param_4,param_5,param_6,param_7,0xdc460);
    return;
  }
  FUN_000da904(param_1,"*",param_3,param_4,param_5,param_6,param_7,0xdc460);
  return;
}

/* FUN_000dc4bc @ 0xdc4bc (192 bytes) */
int FUN_000dc4bc(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  uint uStack0000001c;
  undefined4 uStack00000020;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  FUN_000da904(param_1,"_x(",param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000dc454)(param_1,uStack0000001c >> 8 & 3,param_3,param_4,param_5,param_6,param_7);
  FUN_000da904(param_1,")_y(",param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000dc454)(param_1,uStack0000001c >> 10 & 3,param_3,param_4,param_5,param_6,param_7);
  FUN_000da904(param_1,")_z(",param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000dc454)(param_1,uStack0000001c >> 0xc & 3,param_3,param_4,param_5,param_6,param_7);
  FUN_000da904(param_1,")_w(",param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000dc454)(param_1,uStack0000001c >> 0xe & 3,param_3,param_4,param_5,param_6,param_7);
  FUN_000da904(param_1,")",param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_000dc57c @ 0xdc57c (220 bytes) */
int FUN_000dc57c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  uint uVar1;
  
  uVar1 = param_2 >> 0x10 & 3;
  FUN_000da904(param_1,"_zeroop(",param_3,param_4,param_5,param_6,param_7,param_8);
  if (uVar1 == 1) {
    FUN_000da904(param_1,"zero",param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else if (uVar1 == 0) {
    FUN_000da904(param_1,"fltmax",param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else if (uVar1 == 2) {
    FUN_000da904(param_1,"infinity",param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else if (uVar1 == 3) {
    FUN_000da904(param_1,"inf_else_max",param_3,param_4,param_5,param_6,param_7,param_8);
  }
  else {
    *param_1 = *param_1 + 1;
    FUN_000da904(param_1,"!!!invalid!!!",param_3,param_4,param_5,param_6,param_7,param_8);
  }
  FUN_000da904(param_1,")",param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_000dc658 @ 0xdc658 (196 bytes) */
int FUN_000dc658(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  char *param_7;
  undefined4 param_8;
{
  uint uVar1;
  char local_38 [4];
  char local_34 [4];
  char local_30 [4];
  char local_2c [40];
  
  uVar1 = param_2 >> 0x10 & 0x3fff;
  if (uVar1 == 1) {
    param_7 = "_line_strip";
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__line_strip_001a82c4) + 0));
    *(unsigned int *)local_34 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__line_strip_001a82c4) + 4));
    *(unsigned int *)local_30 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__line_strip_001a82c4) + 8));
  }
  else if (uVar1 == 0) {
    param_7 = "_point_list";
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__point_list_001a82b8) + 0));
    *(unsigned int *)local_34 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__point_list_001a82b8) + 4));
    *(unsigned int *)local_30 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__point_list_001a82b8) + 8));
  }
  else if (uVar1 == 2) {
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__triangle_strip_001a82d0) + 0));
    *(unsigned int *)local_34 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__triangle_strip_001a82d0) + 4));
    *(unsigned int *)local_30 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__triangle_strip_001a82d0) + 8));
    (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = (*(unsigned int *)((unsigned char *)&(s__triangle_strip_001a82d0) + 12));
    param_7 = (char *)(*(unsigned int *)((unsigned char *)&(s__triangle_strip_001a82d0) + 0));
    param_8 = (*(unsigned int *)((unsigned char *)&(s__triangle_strip_001a82d0) + 12));
  }
  FUN_000da904(param_1,local_38,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_000dc71c @ 0xdc71c (268 bytes) */
int FUN_000dc71c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  char *param_7;
  uint param_8;
{
  char local_38 [4];
  char local_34;
  char acStack_33 [3];
  char local_30 [4];
  char local_2c [40];
  
  switch(param_2 >> 0x10 & 0x3fff) {
  case 0:
    param_7 = "_point";
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__point_001a82e0) + 0));
    (*(unsigned short *)((unsigned char *)&(acStack_33) + 0)) = (*(unsigned short *)((unsigned char *)&(s__point_001a82e0) + 5));
    local_34 = s__point_001a82e0[4];
    break;
  case 1:
    param_7 = "_line";
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__line_001a82e8) + 0));
    local_34 = (*(unsigned short *)((unsigned char *)&(s__line_001a82e8) + 4));
    break;
  case 2:
    param_7 = "_triangle";
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__triangle_001a82f0) + 0));
    local_34 = (*(unsigned int *)((unsigned char *)&(s__triangle_001a82f0) + 4));
    (*(unsigned short *)((unsigned char *)&(local_30) + 0)) = (*(unsigned short *)((unsigned char *)&(s__triangle_001a82f0) + 8));
    break;
  case 3:
    param_7 = "_line_adj";
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__line_adj_001a82fc) + 0));
    local_34 = (*(unsigned int *)((unsigned char *)&(s__line_adj_001a82fc) + 4));
    (*(unsigned short *)((unsigned char *)&(local_30) + 0)) = (*(unsigned short *)((unsigned char *)&(s__line_adj_001a82fc) + 8));
    break;
  case 4:
    param_8 = (uint)(ushort)(*(unsigned short *)((unsigned char *)&(s__triangle_adj_001a8308) + 12));
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__triangle_adj_001a8308) + 0));
    local_34 = (*(unsigned int *)((unsigned char *)&(s__triangle_adj_001a8308) + 4));
    *(unsigned int *)local_30 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__triangle_adj_001a8308) + 8));
    (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) = (*(unsigned short *)((unsigned char *)&(s__triangle_adj_001a8308) + 12));
    param_7 = (char *)(*(unsigned int *)((unsigned char *)&(s__triangle_adj_001a8308) + 0));
  }
  FUN_000da904(param_1,local_38,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_000dc83c @ 0xdc83c (80 bytes) */
int FUN_000dc83c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  uint uVar1;
  undefined1 auStack_38 [44];
  
  uVar1 = param_2 >> 0x10 & 0xff;
  FUN_001a32d0(auStack_38,"_stage(%d)",uVar1,param_4,param_5,param_6,param_7,param_8);
  FUN_000da904(param_1,auStack_38,uVar1,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_000dc88c @ 0xdc88c (324 bytes) */
int FUN_000dc88c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  undefined4 uVar2;
  uint uVar3;
  double dVar4;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  
  ((int (*)())FUN_000dc83c)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if ((int)param_2 < 0) {
    uVar3 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    FUN_000da904(param_1,"_mag(",param_3,param_4,param_5,param_6,param_7,param_8);
    FUN_000dbb44(param_1,uVar3 & 7,param_3,param_4,param_5,param_6,param_7);
    FUN_000da904(param_1,")",param_3,param_4,param_5,param_6,param_7,param_8);
    FUN_000da904(param_1,"_min(",param_3,param_4,param_5,param_6,param_7,param_8);
    FUN_000dbb44(param_1,uVar3 >> 3 & 7,param_3,param_4,param_5,param_6,param_7);
    FUN_000da904(param_1,")",param_3,param_4,param_5,param_6,param_7,param_8);
    FUN_000db938(param_1,uVar3 >> 0xf & 7,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  if ((param_2 & 0x40000000) != 0) {
    uVar3 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    dVar4 = (double)FUN_000da904(param_1,"_xoffset(",param_3,param_4,param_5,param_6,param_7,param_8
                                );
    uVar1 = 7;
    uVar2 = 1;
    ((void (*)())FUN_000db574)(param_1,uVar3 & 0xff,7,1,dVar4,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                 in_stack_ffffffa8,in_stack_ffffffb0,in_stack_ffffffb8,in_stack_ffffffc0);
    FUN_000da904(param_1,")",uVar1,uVar2,param_5,param_6,param_7,param_8);
    dVar4 = (double)FUN_000da904(param_1,"_yoffset(",uVar1,uVar2,param_5,param_6,param_7,param_8);
    uVar1 = 7;
    uVar2 = 1;
    ((void (*)())FUN_000db574)(param_1,uVar3 >> 8 & 0xff,7,1,dVar4,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                 in_stack_ffffffa8,in_stack_ffffffb0,in_stack_ffffffb8,in_stack_ffffffc0);
    FUN_000da904(param_1,")",uVar1,uVar2,param_5,param_6,param_7,param_8);
    return;
  }
  return;
}

/* FUN_000dc9d0 @ 0xdc9d0 (36 bytes) */
int FUN_000dc9d0(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if ((param_2 & 0x10000) == 0) {
    return;
  }
  FUN_000da904(param_1,"_normalize",param_3,param_4,param_5,param_6,param_7,0xdc9d8);
  return;
}

/* FUN_000dc9f4 @ 0xdc9f4 (36 bytes) */
int FUN_000dc9f4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if ((param_2 & 0x10000) == 0) {
    return;
  }
  FUN_000da904(param_1,"_round",param_3,param_4,param_5,param_6,param_7,0xdc9fc);
  return;
}

/* FUN_000dca18 @ 0xdca18 (36 bytes) */
int FUN_000dca18(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if ((param_2 & 0x1000000) == 0) {
    return;
  }
  FUN_000da904(param_1,"_sample",param_3,param_4,param_5,param_6,param_7,0xdca20);
  return;
}

/* FUN_000dca3c @ 0xdca3c (36 bytes) */
int FUN_000dca3c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if ((param_2 & 0x1000000) == 0) {
    return;
  }
  FUN_000da904(param_1,"_centroid",param_3,param_4,param_5,param_6,param_7,0xdca44);
  return;
}

/* FUN_000dca60 @ 0xdca60 (212 bytes) */
int FUN_000dca60(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  uint uVar2;
  
  ((int (*)())FUN_000dc83c)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000dca3c)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  if ((param_2 & 0x2000000) != 0) {
    FUN_000da904(param_1,"_absolute",param_3,param_4,param_5,param_6,param_7,param_8);
  }
  ((int (*)())FUN_000dbcdc)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if ((int)param_2 < 0) {
    uVar2 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    FUN_000dbbc0(param_1,uVar2,param_3,param_4,param_5,param_6,param_7,param_8);
    if ((uVar2 & 0x2000000) != 0) {
      FUN_000da904(param_1,"_qualitybias",param_3,param_4,param_5,param_6,param_7,param_8);
    }
  }
  if ((param_2 & 0x40000000) != 0) {
    uVar1 = **(undefined4 **)(param_1 + 8);
    *(undefined4 **)(param_1 + 8) = *(undefined4 **)(param_1 + 8) + 1;
    FUN_000db6d4(param_1,uVar1,param_3,param_4,param_5,param_6,param_7,param_8);
    return;
  }
  return;
}

/* FUN_000dcb34 @ 0xdcb34 (152 bytes) */
int FUN_000dcb34(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  
  ((int (*)())FUN_000dc83c)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000dca3c)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  ((int (*)())FUN_000dbcdc)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  if ((int)param_2 < 0) {
    uVar1 = **(undefined4 **)(param_1 + 8);
    *(undefined4 **)(param_1 + 8) = *(undefined4 **)(param_1 + 8) + 1;
    FUN_000dbbc0(param_1,uVar1,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  if ((param_2 & 0x40000000) != 0) {
    uVar1 = **(undefined4 **)(param_1 + 8);
    *(undefined4 **)(param_1 + 8) = *(undefined4 **)(param_1 + 8) + 1;
    FUN_000db6d4(param_1,uVar1,param_3,param_4,param_5,param_6,param_7,param_8);
    return;
  }
  return;
}

/* FUN_000dcbcc @ 0xdcbcc (244 bytes) */
int FUN_000dcbcc(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
  undefined4 param_8;
{
  uint uVar1;
  
  FUN_000da904(param_1,"_matrix(",param_3,param_4,param_5,param_6,param_7,param_8);
  uVar1 = param_2 >> 0x10 & 7;
  if (uVar1 < 5) {
    param_7 = 0;
    switch(uVar1) {
    case 0:
      FUN_000da904(param_1,"4x4",param_3,param_4,param_5,param_6,param_7,param_8);
      break;
    case 1:
      FUN_000da904(param_1,"4x3",param_3,param_4,param_5,param_6,param_7,param_8);
      break;
    case 2:
      FUN_000da904(param_1,"3x4",param_3,param_4,param_5,param_6,param_7,param_8);
      break;
    case 3:
      FUN_000da904(param_1,"3x3",param_3,param_4,param_5,param_6,param_7,param_8);
      break;
    case 4:
      FUN_000da904(param_1,"3x2",param_3,param_4,param_5,param_6,param_7,param_8);
    }
  }
  else {
    *param_1 = *param_1 + 1;
    FUN_000da904(param_1,"!!!invalid!!!",param_3,param_4,param_5,param_6,param_7,param_8);
  }
  FUN_000da904(param_1,")",param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_000dccd4 @ 0xdccd4 (264 bytes) */
int FUN_000dccd4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
  undefined4 param_8;
{
  uint uVar1;
  
  FUN_000da904(param_1,"_relop(",param_3,param_4,param_5,param_6,param_7,param_8);
  uVar1 = param_2 >> 0x10 & 7;
  if (uVar1 < 6) {
    param_7 = 0;
    switch(uVar1) {
    case 0:
      FUN_000da904(param_1,"ne",param_3,param_4,param_5,param_6,param_7,param_8);
      break;
    case 1:
      FUN_000da904(param_1,"eq",param_3,param_4,param_5,param_6,param_7,param_8);
      break;
    case 2:
      FUN_000da904(param_1,"ge",param_3,param_4,param_5,param_6,param_7,param_8);
      break;
    case 3:
      FUN_000da904(param_1,"gt",param_3,param_4,param_5,param_6,param_7,param_8);
      break;
    case 4:
      FUN_000da904(param_1,"le",param_3,param_4,param_5,param_6,param_7,param_8);
      break;
    case 5:
      FUN_000da904(param_1,"lt",param_3,param_4,param_5,param_6,param_7,param_8);
    }
  }
  else {
    *param_1 = *param_1 + 1;
    FUN_000da904(param_1,"!!!invalid!!!",param_3,param_4,param_5,param_6,param_7,param_8);
  }
  FUN_000da904(param_1,")",param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_000dcdf4 @ 0xdcdf4 (256 bytes) */
int FUN_000dcdf4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  char *param_7;
  undefined4 param_8;
{
  uint uVar1;
  undefined4 extraout_r4;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  char local_128;
  char local_127 [15];
  undefined1 auStack_118 [268];
  
  uVar3 = **(uint **)(param_1 + 8);
  *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
  uVar1 = uVar3 >> 0x10 & 0xff;
  if (uVar1 == 1) {
    param_7 = "ps";
    local_128 = s_ps_001a8390[0];
    local_127[0] = s_ps_001a8390[1];
    local_127[1] = s_ps_001a8390[2];
  }
  else if (uVar1 == 0) {
    param_7 = "vs";
    local_128 = s_vs_001a838c[0];
    local_127[0] = s_vs_001a838c[1];
    local_127[1] = s_vs_001a838c[2];
  }
  else if (uVar1 == 2) {
    param_7 = "gs";
    local_128 = s_gs_001a8394[0];
    local_127[0] = s_gs_001a8394[1];
    local_127[1] = s_gs_001a8394[2];
  }
  uVar4 = uVar3 & 0xff;
  pcVar2 = &local_128;
  uVar3 = uVar3 >> 8 & 0xff;
  FUN_001a32d0(auStack_118,"il_%s_%d_%d",pcVar2,uVar3,uVar4,param_6,param_7,param_8);
  *(uint *)(param_1 + 0x218) = (uint)(uVar1 == 1);
  FUN_000da904(param_1,auStack_118,pcVar2,uVar3,uVar4,param_6,param_7,param_8);
  FUN_000da984(param_1,extraout_r4,pcVar2,uVar3,uVar4,param_6,param_7,param_8);
  return;
}

/* FUN_000dcef4 @ 0xdcef4 (640 bytes) */
int FUN_000dcef4(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  uint param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
{
  char *pcVar1;
  
  if (0x20 < param_2) {
switchD_000dcf24_caseD_7:
    pcVar1 = "!!!invalidRegType!!!";
    *param_1 = *param_1 + 1;
    goto LAB_000dd1f4;
  }
  param_7 = 0;
  switch(param_2) {
  case 0:
    FUN_000da904(param_1,"b",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 1:
    FUN_000da904(param_1,"c",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 2:
    FUN_000da904(param_1,"i",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 3:
    FUN_000da904(param_1,"a",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 4:
    FUN_000da904(param_1,"r",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  default:
    FUN_000da904(param_1,"v",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 6:
    FUN_000da904(param_1,"vIndex",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 7:
  case 0x1a:
    goto switchD_000dcf24_caseD_7;
  case 8:
    FUN_000da904(param_1,"vBaryCoord",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 9:
    FUN_000da904(param_1,"vPrimIndex",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 10:
    FUN_000da904(param_1,"vQuadIndex",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 0xb:
    if (param_1[0x86] == 0) {
      pcVar1 = "o";
      break;
    }
    goto LAB_000dd09c;
  case 0xc:
    if (param_1[0x86] != 0) {
      pcVar1 = "vPixIn";
      break;
    }
LAB_000dd09c:
    pcVar1 = "!!!invalidRegUsage(oVtxOut)!!!";
    break;
  case 0xd:
    FUN_000da904(param_1,"oSprite",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 0xe:
    if (param_1[0x86] == 0) {
      pcVar1 = "oPos";
    }
    else {
      pcVar1 = "!!!invalidRegUsage(oPos)!!!";
    }
    break;
  case 0xf:
    if (param_1[0x86] == 0) {
      pcVar1 = "oInterp";
    }
    else {
      pcVar1 = "vInterp";
    }
    break;
  case 0x10:
    if (param_1[0x86] == 0) {
      pcVar1 = "oFog";
    }
    else {
      pcVar1 = "vFog";
    }
    break;
  case 0x11:
    if (param_1[0x86] == 0) {
      pcVar1 = "oT";
    }
    else {
      pcVar1 = "vT";
    }
    break;
  case 0x12:
    if (param_1[0x86] == 0) {
      pcVar1 = "oPriColor";
    }
    else {
      pcVar1 = "vPriColor";
    }
    break;
  case 0x13:
    if (param_1[0x86] == 0) {
      pcVar1 = "oSecColor";
    }
    else {
      pcVar1 = "vSecColor";
    }
    break;
  case 0x14:
    if (param_1[0x86] == 0) {
      pcVar1 = "!!!invalidRegUsage(oSpritCoord)!!!";
    }
    else {
      pcVar1 = "vSpriteCoord";
    }
    break;
  case 0x15:
    FUN_000da904(param_1,"vFace",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 0x16:
    FUN_000da904(param_1,"vWinCoord",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 0x17:
    FUN_000da904(param_1,"oC",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 0x18:
    FUN_000da904(param_1,"oDepth",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 0x19:
    FUN_000da904(param_1,"oClip",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 0x1b:
    FUN_000da904(param_1,"x",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 0x1c:
    FUN_000da904(param_1,"cb",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 0x1d:
    FUN_000da904(param_1,"l",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 0x1f:
    FUN_000da904(param_1,"o",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  case 0x20:
    FUN_000da904(param_1,"icb",param_3,param_4,param_5,param_6,param_7,0xdcf00);
    return;
  }
LAB_000dd1f4:
  FUN_000da904(param_1,pcVar1,param_3,param_4,param_5,param_6,param_7,0xdcf00);
  return;
}

/* FUN_000dd1f8 @ 0xdd1f8 (1220 bytes) */
int FUN_000dd1f8(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  undefined4 param_2;
  uint param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  uint *param_7;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  uint *puVar5;
  undefined4 extraout_r4;
  uint uVar6;
  undefined4 in_r10;
  uint unaff_r23;
  uint uVar7;
  uint uVar8;
  uint unaff_r28;
  uint uVar9;
  uint uVar10;
  undefined1 auStack_b8 [64];
  undefined2 local_78 [36];
  
  puVar5 = (uint *)param_1[2];
  uVar10 = *puVar5;
  param_1[2] = (int)(puVar5 + 1);
  bVar1 = (uVar10 & 0x400000) == 0;
  if (!bVar1) {
    unaff_r28 = puVar5[1];
    param_1[2] = (int)(puVar5 + 2);
  }
  uVar8 = uVar10 & 0x1800000;
  if (uVar8 == 0x800000) {
    unaff_r23 = *(uint *)param_1[2];
    param_1[2] = (int)((uint *)param_1[2] + 1);
  }
  uVar7 = uVar10 >> 0x19 & 1;
  uVar3 = uVar10 & 0x2000000;
  if (uVar7 != 0xffffffff) {
    bVar2 = false;
    uVar9 = 0;
    do {
      ((int (*)())FUN_000dcef4)(param_1,uVar10 >> 0x10 & 0x3f,param_3,param_4,param_5,param_6,param_7);
      if (((undefined4 *)(uVar10 & 0x3f0000) == 0x001b0000) ||
         ((undefined4 *)(uVar10 & 0x3f0000) == (undefined4 *)0x1c0000)) {
        param_3 = uVar10 & 0xffff;
        FUN_001a32d0(auStack_b8,"%d",param_3,param_4,param_5,param_6,param_7,in_r10);
        bVar2 = true;
        FUN_000da904(param_1,auStack_b8,param_3,param_4,param_5,param_6,param_7,in_r10);
      }
LAB_000dd324:
      if (uVar8 == 0) {
        if (bVar2) {
          param_3 = 0;
          if ((uVar10 & 0x4000000) != 0) {
            param_3 = *(uint *)param_1[2];
            param_1[2] = (int)((uint *)param_1[2] + 1);
          }
          FUN_001a32d0(auStack_b8,"[%lu]",param_3,param_4,param_5,param_6,param_7,in_r10);
          FUN_000da904(param_1,auStack_b8,param_3,param_4,param_5,param_6,param_7,in_r10);
        }
        else {
          if (uVar3 == 0) {
            param_3 = uVar10 & 0xffff;
            FUN_001a32d0(auStack_b8,"%d",param_3,param_4,param_5,param_6,param_7,in_r10);
          }
          else {
            param_3 = uVar10 & 0xffff;
            FUN_001a32d0(auStack_b8,"[%d]",param_3,param_4,param_5,param_6,param_7,in_r10);
          }
          FUN_000da904(param_1,auStack_b8,param_3,param_4,param_5,param_6,param_7,in_r10);
        }
      }
      else {
        if (uVar8 == 0x800000) {
          FUN_000da904(param_1,"[",param_3,param_4,param_5,param_6,param_7,in_r10);
          if ((unaff_r23 & 0x10000) == 0) {
            uVar6 = unaff_r23 & 0xffff;
            FUN_001a32d0(auStack_b8,"a%d",uVar6,param_4,param_5,param_6,param_7,in_r10);
            FUN_000da904(param_1,auStack_b8,uVar6,param_4,param_5,param_6,param_7,in_r10);
            if ((unaff_r23 & 0xe0000) != 0) {
              uVar4 = FUN_000da8fc(param_1,uVar10);
              uVar4 = FUN_000dac4c(param_1,unaff_r23 >> 0x11 & 7,uVar4,param_4,param_5,param_6,
                                   param_7,in_r10);
              FUN_001a32d0(auStack_b8,".%c",uVar4,param_4,param_5,param_6,param_7,in_r10);
              FUN_000da904(param_1,auStack_b8,uVar4,param_4,param_5,param_6,param_7,in_r10);
            }
          }
          else {
            FUN_000da904(param_1,"al",param_3,param_4,param_5,param_6,param_7,in_r10);
          }
          if (bVar2) {
            param_3 = 0;
            if ((uVar10 & 0x4000000) != 0) {
              param_3 = *(uint *)param_1[2];
              param_1[2] = (int)((uint *)param_1[2] + 1);
            }
LAB_000dd4f0:
            FUN_001a32d0(local_78,"+%lu",param_3,param_4,param_5,param_6,param_7,in_r10);
            FUN_000da904(param_1,local_78,param_3,param_4,param_5,param_6,param_7,in_r10);
          }
          else {
            param_3 = uVar10 & 0xffff;
            if (param_3 != 0) {
              FUN_001a32d0(auStack_b8,"+%d",param_3,param_4,param_5,param_6,param_7,in_r10);
              FUN_000da904(param_1,auStack_b8,param_3,param_4,param_5,param_6,param_7,in_r10);
            }
          }
        }
        else {
          if (uVar8 != 0x1000000) goto LAB_000dd51c;
          local_78[0] = 0x5b00;
          FUN_000da904(param_1,local_78,param_3,param_4,param_5,param_6,param_7,in_r10);
          ((int (*)())FUN_000dd1f8)(param_1,extraout_r4,param_3,param_4,param_5,param_6,param_7);
          if ((uVar10 & 0x4000000) != 0) {
            param_3 = *(uint *)param_1[2];
            param_1[2] = (int)((uint *)param_1[2] + 1);
            goto LAB_000dd4f0;
          }
        }
        FUN_000da904(param_1,"]",param_3,param_4,param_5,param_6,param_7,in_r10);
      }
LAB_000dd51c:
      uVar9 = uVar9 + 1;
      if (uVar7 + 1 <= uVar9) goto LAB_000dd530;
    } while (uVar9 == 0);
    param_7 = (uint *)param_1[2];
    uVar10 = *param_7;
    param_1[2] = (int)(param_7 + 1);
    if ((uVar10 & 0x400000) != 0) {
      unaff_r28 = param_7[1];
      param_1[2] = (int)(param_7 + 2);
    }
    uVar8 = uVar10 & 0x1800000;
    uVar7 = uVar10 >> 0x19 & 1;
    if (uVar8 == 0x800000) {
      unaff_r23 = *(uint *)param_1[2];
      param_1[2] = (int)((uint *)param_1[2] + 1);
    }
    goto LAB_000dd324;
  }
LAB_000dd530:
  if (bVar1) {
    return;
  }
  uVar4 = FUN_000da8fc(param_1,uVar10);
  FUN_000dad30(param_1,unaff_r28,uVar4,param_4,param_5,param_6,param_7,in_r10);
  FUN_000daab0(param_1,unaff_r28,uVar4,param_4,param_5,param_6,param_7,in_r10);
  if ((unaff_r28 & 0x10000) != 0) {
    FUN_000da904(param_1,"_invert",uVar4,param_4,param_5,param_6,param_7,in_r10);
  }
  if ((unaff_r28 & 0x80000) != 0) {
    FUN_000da904(param_1,"_sign",uVar4,param_4,param_5,param_6,param_7,in_r10);
  }
  if ((unaff_r28 & 0x100000) != 0) {
    FUN_000da904(param_1,"_abs",uVar4,param_4,param_5,param_6,param_7,in_r10);
  }
  if ((unaff_r28 & 0x20000) != 0) {
    FUN_000da904(param_1,"_bias",uVar4,param_4,param_5,param_6,param_7,in_r10);
  }
  if ((unaff_r28 & 0x40000) != 0) {
    FUN_000da904(param_1,"_x2",uVar4,param_4,param_5,param_6,param_7,in_r10);
  }
  if ((unaff_r28 & 0xe00000) == 0) {
    return;
  }
  FUN_000da904(param_1,"_divcomp(",uVar4,param_4,param_5,param_6,param_7,in_r10);
  uVar10 = unaff_r28 >> 0x15 & 7;
  if (uVar10 == 2) {
    FUN_000da904(param_1,"z",uVar4,param_4,param_5,param_6,param_7,in_r10);
    goto LAB_000dd630;
  }
  if (uVar10 < 3) {
    if (uVar10 == 1) {
      FUN_000da904(param_1,"y",uVar4,param_4,param_5,param_6,param_7,in_r10);
      goto LAB_000dd630;
    }
  }
  else {
    if (uVar10 == 3) {
      FUN_000da904(param_1,"w",uVar4,param_4,param_5,param_6,param_7,in_r10);
      goto LAB_000dd630;
    }
    if (uVar10 == 4) {
      FUN_000da904(param_1,"unknown",uVar4,param_4,param_5,param_6,param_7,in_r10);
      goto LAB_000dd630;
    }
  }
  FUN_000da904(param_1,"!!!invalid!!!",uVar4,param_4,param_5,param_6,param_7,in_r10);
  *param_1 = *param_1 + 1;
LAB_000dd630:
  FUN_000da904(param_1,")",uVar4,param_4,param_5,param_6,param_7,in_r10);
  return;
}

/* FUN_000dd6bc @ 0xdd6bc (988 bytes) */
int FUN_000dd6bc(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  undefined4 param_2;
  uint param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  bool bVar1;
  bool bVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint *puVar5;
  undefined4 extraout_r4;
  undefined4 uVar6;
  uint unaff_r24;
  uint unaff_r25;
  uint uVar7;
  uint uVar8;
  undefined1 auStack_b8 [64];
  undefined1 auStack_78 [84];
  
  puVar5 = (uint *)param_1[2];
  uVar7 = *puVar5;
  param_1[2] = (int)(puVar5 + 1);
  bVar1 = (uVar7 >> 0x16 & 1) == 0;
  if (!bVar1) {
    unaff_r25 = puVar5[1];
    param_1[2] = (int)(puVar5 + 2);
  }
  uVar8 = uVar7 & 0x1800000;
  if (uVar8 == 0x800000) {
    unaff_r24 = *(uint *)param_1[2];
    param_1[2] = (int)((uint *)param_1[2] + 1);
  }
  if (!bVar1) {
    FUN_000dae5c(param_1,unaff_r25,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  FUN_000da904(param_1," ",param_3,param_4,param_5,param_6,param_7,param_8);
  uVar4 = FUN_000da8f4(param_1,uVar7);
  ((int (*)())FUN_000dcef4)(param_1,uVar7 >> 0x10 & 0x3f,param_3,param_4,param_5,param_6,param_7);
  if ((uVar7 & 0x23f0000) == 0x21e0000) {
    uVar7 = uVar7 & 0xffff;
    FUN_001a32d0(auStack_b8,"[%d]",uVar7,param_4,param_5,param_6,param_7,param_8);
    FUN_000da904(param_1,auStack_b8,uVar7,param_4,param_5,param_6,param_7,param_8);
    uVar8 = *(uint *)param_1[2];
    param_1[2] = (int)((uint *)param_1[2] + 1);
    uVar7 = uVar8 & 0xffff;
    FUN_001a32d0(auStack_b8,"[%d]",uVar7,param_4,param_5,param_6,param_7,param_8);
    FUN_000da904(param_1,auStack_b8,uVar7,param_4,param_5,param_6,param_7,param_8);
    bVar1 = (uVar8 & 0x400000) == 0;
  }
  else {
    puVar3 = (undefined4 *)(uVar7 & 0x3f0000);
    if (puVar3 == (undefined4 *)0x1f0000) {
      if ((uVar8 == 0x800000) || (bVar2 = false, uVar8 == 0x1000000)) {
        bVar2 = true;
      }
    }
    else if ((puVar3 == 0x001b0000) || (bVar2 = false, puVar3 == (undefined4 *)0x1c0000)) {
      param_3 = uVar7 & 0xffff;
      FUN_001a32d0(auStack_b8,"%d",param_3,param_4,param_5,param_6,param_7,param_8);
      bVar2 = true;
      FUN_000da904(param_1,auStack_b8,param_3,param_4,param_5,param_6,param_7,param_8);
    }
    if (uVar8 == 0) {
      if (bVar2) {
        uVar6 = 0;
        if ((uVar7 & 0x4000000) != 0) {
          uVar6 = *(undefined4 *)param_1[2];
          param_1[2] = (int)((undefined4 *)param_1[2] + 1);
        }
        FUN_001a32d0(auStack_b8,"[%lu]",uVar6,param_4,param_5,param_6,param_7,param_8);
        FUN_000da904(param_1,auStack_b8,uVar6,param_4,param_5,param_6,param_7,param_8);
      }
      else {
        uVar7 = uVar7 & 0xffff;
        FUN_001a32d0(auStack_b8,"%d",uVar7,param_4,param_5,param_6,param_7,param_8);
        FUN_000da904(param_1,auStack_b8,uVar7,param_4,param_5,param_6,param_7,param_8);
      }
    }
    else {
      if (uVar8 == 0x800000) {
        FUN_000da904(param_1,"[",param_3,param_4,param_5,param_6,param_7,param_8);
        if ((unaff_r24 & 0x10000) == 0) {
          uVar8 = unaff_r24 & 0xffff;
          FUN_001a32d0(auStack_b8,"a%d",uVar8,param_4,param_5,param_6,param_7,param_8);
          FUN_000da904(param_1,auStack_b8,uVar8,param_4,param_5,param_6,param_7,param_8);
          if ((unaff_r24 & 0xe0000) != 0) {
            uVar6 = FUN_000da8f4(param_1,uVar7);
            uVar6 = FUN_000dac4c(param_1,unaff_r24 >> 0x11 & 7,uVar6,param_4,param_5,param_6,param_7
                                 ,param_8);
            FUN_001a32d0(auStack_b8,".%c",uVar6,param_4,param_5,param_6,param_7,param_8);
            FUN_000da904(param_1,auStack_b8,uVar6,param_4,param_5,param_6,param_7,param_8);
          }
        }
        else {
          FUN_000da904(param_1,"al",param_3,param_4,param_5,param_6,param_7,param_8);
        }
        if (bVar2) {
          param_3 = 0;
          if ((uVar7 & 0x4000000) != 0) {
            param_3 = *(uint *)param_1[2];
            param_1[2] = (int)((uint *)param_1[2] + 1);
          }
          FUN_001a32d0(auStack_78,"+%lu",param_3,param_4,param_5,param_6,param_7,param_8);
        }
        else {
          param_3 = uVar7 & 0xffff;
          if (param_3 != 0) {
            FUN_001a32d0(auStack_b8,"+%d",param_3,param_4,param_5,param_6,param_7,param_8);
            FUN_000da904(param_1,auStack_b8,param_3,param_4,param_5,param_6,param_7,param_8);
          }
        }
      }
      else {
        if (uVar8 != 0x1000000) goto joined_r0x000dda5c;
        if ((!bVar2) && (puVar3 != (undefined4 *)0x1f0000)) {
          FUN_000da904(param_1,
                       "Error! Field relative_address == IL_ADDR_REG_RELATIVE not supported for this reg type."
                       ,param_3,param_4,param_5,param_6,param_7,param_8);
          *param_1 = *param_1 + 1;
          goto joined_r0x000dda5c;
        }
        FUN_000da904(param_1,"[",param_3,param_4,param_5,param_6,param_7,param_8);
        ((int (*)())FUN_000dd1f8)(param_1,extraout_r4,param_3,param_4,param_5,param_6,param_7);
        if ((uVar7 & 0x4000000) != 0) {
          param_3 = *(uint *)param_1[2];
          param_1[2] = (int)((uint *)param_1[2] + 1);
          if (puVar3 == (undefined4 *)0x1f0000) {
            param_3 = param_3 + (uVar7 & 0xffff);
          }
          FUN_001a32d0(auStack_78,"+%lu",param_3,param_4,param_5,param_6,param_7,param_8);
          FUN_000da904(param_1,auStack_78,param_3,param_4,param_5,param_6,param_7,param_8);
        }
      }
      FUN_000da904(param_1,"]",param_3,param_4,param_5,param_6,param_7,param_8);
    }
  }
joined_r0x000dda5c:
  if (!bVar1) {
    FUN_000db1c4(param_1,unaff_r25,uVar4,param_4,param_5,param_6,param_7,param_8);
  }
  return;
}

/* FUN_000dda98 @ 0xdda98 (124 bytes) */
int FUN_000dda98(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  
  ((int (*)())FUN_000dd6bc)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  FUN_000da904(param_1,", ",param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000dd1f8)(param_1,extraout_r4,param_3,param_4,param_5,param_6,param_7);
  FUN_000da904(param_1,", ",param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_00,param_3,param_4,param_5,param_6,param_7);
  FUN_000da904(param_1,", ",param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_01,param_3,param_4,param_5,param_6,param_7);
  FUN_000da984(param_1,extraout_r4_02,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_000ddb14 @ 0xddb14 (104 bytes) */
int FUN_000ddb14(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  
  ((int (*)())FUN_000dd6bc)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  FUN_000da904(param_1,", ",param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000dd1f8)(param_1,extraout_r4,param_3,param_4,param_5,param_6,param_7);
  FUN_000da904(param_1,", ",param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_00,param_3,param_4,param_5,param_6,param_7);
  FUN_000da984(param_1,extraout_r4_01,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_000ddb7c @ 0xddb7c (80 bytes) */
int FUN_000ddb7c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  
  ((int (*)())FUN_000dd6bc)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  FUN_000da904(param_1,", ",param_3,param_4,param_5,param_6,param_7,param_8);
  ((int (*)())FUN_000dd1f8)(param_1,extraout_r4,param_3,param_4,param_5,param_6,param_7);
  FUN_000da984(param_1,extraout_r4_00,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_000ddbcc @ 0xddbcc (10080 bytes) */
int FUN_000ddbcc(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
{
  char cVar1;
  undefined4 *puVar2;
  float *pfVar3;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  undefined4 extraout_r4_08;
  undefined4 extraout_r4_09;
  undefined4 extraout_r4_10;
  undefined4 extraout_r4_11;
  undefined4 extraout_r4_12;
  undefined4 extraout_r4_13;
  undefined4 extraout_r4_14;
  undefined4 extraout_r4_15;
  undefined4 extraout_r4_16;
  undefined4 extraout_r4_17;
  undefined4 extraout_r4_18;
  undefined4 extraout_r4_19;
  undefined4 extraout_r4_20;
  undefined4 extraout_r4_21;
  undefined4 extraout_r4_22;
  undefined4 extraout_r4_23;
  undefined4 extraout_r4_24;
  undefined4 extraout_r4_25;
  undefined4 extraout_r4_26;
  undefined4 extraout_r4_27;
  undefined4 extraout_r4_28;
  undefined4 extraout_r4_29;
  undefined4 extraout_r4_30;
  undefined4 extraout_r4_31;
  undefined4 extraout_r4_32;
  undefined4 extraout_r4_33;
  undefined4 extraout_r4_34;
  undefined4 extraout_r4_35;
  undefined4 extraout_r4_36;
  undefined4 extraout_r4_37;
  undefined4 extraout_r4_38;
  undefined4 extraout_r4_39;
  undefined4 extraout_r4_40;
  undefined4 extraout_r4_41;
  undefined4 extraout_r4_42;
  undefined4 extraout_r4_43;
  undefined4 extraout_r4_44;
  undefined4 extraout_r4_45;
  undefined4 extraout_r4_46;
  undefined4 extraout_r4_47;
  undefined4 extraout_r4_48;
  undefined4 extraout_r4_49;
  undefined4 extraout_r4_50;
  undefined4 extraout_r4_51;
  undefined4 extraout_r4_52;
  undefined4 extraout_r4_53;
  undefined4 extraout_r4_54;
  undefined4 extraout_r4_55;
  undefined4 extraout_r4_56;
  undefined4 extraout_r4_57;
  undefined4 extraout_r4_58;
  undefined4 extraout_r4_59;
  undefined4 extraout_r4_60;
  undefined4 extraout_r4_61;
  undefined4 extraout_r4_62;
  undefined4 extraout_r4_63;
  undefined4 extraout_r4_64;
  undefined4 extraout_r4_65;
  undefined4 extraout_r4_66;
  undefined4 extraout_r4_67;
  undefined4 extraout_r4_68;
  undefined4 extraout_r4_69;
  undefined4 extraout_r4_70;
  undefined4 extraout_r4_71;
  undefined4 extraout_r4_72;
  undefined4 extraout_r4_73;
  undefined4 extraout_r4_74;
  undefined4 extraout_r4_75;
  undefined4 extraout_r4_76;
  undefined4 extraout_r4_77;
  undefined4 extraout_r4_78;
  undefined4 extraout_r4_79;
  undefined4 extraout_r4_80;
  undefined4 extraout_r4_81;
  undefined4 extraout_r4_82;
  undefined4 extraout_r4_83;
  undefined4 extraout_r4_84;
  undefined4 extraout_r4_85;
  undefined4 extraout_r4_86;
  undefined4 extraout_r4_87;
  undefined4 extraout_r4_88;
  undefined4 extraout_r4_89;
  undefined4 extraout_r4_90;
  undefined4 extraout_r4_91;
  undefined4 extraout_r4_92;
  undefined4 extraout_r4_93;
  undefined4 extraout_r4_94;
  undefined4 extraout_r4_95;
  undefined4 extraout_r4_96;
  undefined4 extraout_r4_97;
  undefined4 extraout_r4_98;
  undefined4 extraout_r4_99;
  undefined4 extraout_r4_x00100;
  undefined4 extraout_r4_x00101;
  undefined4 extraout_r4_x00102;
  undefined4 extraout_r4_x00103;
  undefined4 extraout_r4_x00104;
  undefined4 extraout_r4_x00105;
  undefined4 extraout_r4_x00106;
  undefined4 extraout_r4_x00107;
  undefined4 extraout_r4_x00108;
  undefined4 extraout_r4_x00109;
  undefined4 extraout_r4_x00110;
  undefined4 extraout_r4_x00111;
  undefined4 extraout_r4_x00112;
  undefined4 extraout_r4_x00113;
  undefined4 extraout_r4_x00114;
  undefined4 extraout_r4_x00115;
  undefined4 extraout_r4_x00116;
  undefined4 extraout_r4_x00117;
  undefined4 extraout_r4_x00118;
  undefined4 extraout_r4_x00119;
  undefined4 extraout_r4_x00120;
  undefined4 extraout_r4_x00121;
  undefined4 extraout_r4_x00122;
  undefined4 extraout_r4_x00123;
  undefined4 extraout_r4_x00124;
  undefined4 extraout_r4_x00125;
  undefined4 extraout_r4_x00126;
  undefined4 extraout_r4_x00127;
  undefined4 extraout_r4_x00128;
  undefined4 extraout_r4_x00129;
  undefined4 extraout_r4_x00130;
  undefined4 extraout_r4_x00131;
  undefined4 extraout_r4_x00132;
  undefined4 extraout_r4_x00133;
  undefined4 extraout_r4_x00134;
  undefined4 extraout_r4_x00135;
  undefined4 extraout_r4_x00136;
  undefined4 extraout_r4_x00137;
  undefined4 extraout_r4_x00138;
  undefined4 extraout_r4_x00139;
  undefined4 extraout_r4_x00140;
  undefined4 extraout_r4_x00141;
  undefined4 extraout_r4_x00142;
  undefined4 extraout_r4_x00143;
  undefined4 extraout_r4_x00144;
  undefined4 extraout_r4_x00145;
  undefined4 extraout_r4_x00146;
  undefined4 extraout_r4_x00147;
  undefined4 extraout_r4_x00148;
  undefined4 extraout_r4_x00149;
  undefined4 extraout_r4_x00150;
  undefined4 extraout_r4_x00151;
  undefined4 extraout_r4_x00152;
  undefined4 extraout_r4_x00153;
  undefined4 extraout_r4_x00154;
  undefined4 extraout_r4_x00155;
  undefined4 extraout_r4_x00156;
  undefined4 extraout_r4_x00157;
  undefined4 extraout_r4_x00158;
  undefined4 extraout_r4_x00159;
  undefined4 extraout_r4_x00160;
  undefined4 extraout_r4_x00161;
  undefined4 extraout_r4_x00162;
  undefined4 extraout_r4_x00163;
  undefined4 extraout_r4_x00164;
  undefined4 extraout_r4_x00165;
  undefined4 extraout_r4_x00166;
  undefined4 extraout_r4_x00167;
  undefined4 extraout_r4_x00168;
  undefined4 extraout_r4_x00169;
  char *pcVar4;
  undefined4 extraout_r4_x00170;
  undefined4 extraout_r4_x00171;
  undefined4 extraout_r4_x00172;
  undefined4 extraout_r4_x00173;
  undefined4 extraout_r4_x00174;
  undefined4 extraout_r4_x00175;
  undefined4 extraout_r4_x00176;
  undefined4 extraout_r4_x00177;
  undefined4 extraout_r4_x00178;
  undefined4 extraout_r4_x00179;
  undefined4 extraout_r4_x00180;
  undefined4 extraout_r4_x00181;
  undefined4 extraout_r4_x00182;
  undefined4 extraout_r4_x00183;
  undefined4 extraout_r4_x00184;
  undefined4 extraout_r4_x00185;
  undefined4 extraout_r4_x00186;
  undefined4 extraout_r4_x00187;
  undefined4 extraout_r4_x00188;
  undefined4 extraout_r4_x00189;
  undefined4 extraout_r4_x00190;
  undefined4 extraout_r4_x00191;
  undefined4 extraout_r4_x00192;
  undefined4 extraout_r4_x00193;
  undefined4 extraout_r4_x00194;
  undefined4 extraout_r4_x00195;
  undefined4 extraout_r4_x00196;
  undefined4 extraout_r4_x00197;
  undefined4 extraout_r4_x00198;
  undefined4 extraout_r4_x00199;
  undefined4 extraout_r4_x00200;
  undefined4 extraout_r4_x00201;
  undefined4 extraout_r4_x00202;
  undefined4 extraout_r4_x00203;
  undefined4 extraout_r4_x00204;
  undefined4 extraout_r4_x00205;
  undefined4 extraout_r4_x00206;
  undefined4 extraout_r4_x00207;
  undefined4 extraout_r4_x00208;
  undefined4 extraout_r4_x00209;
  undefined4 extraout_r4_x00210;
  undefined4 extraout_r4_x00211;
  undefined4 extraout_r4_x00212;
  undefined4 extraout_r4_x00213;
  undefined4 extraout_r4_x00214;
  undefined4 extraout_r4_x00215;
  undefined4 extraout_r4_x00216;
  undefined4 extraout_r4_x00217;
  undefined4 extraout_r4_x00218;
  undefined4 extraout_r4_x00219;
  undefined4 extraout_r4_x00220;
  undefined4 extraout_r4_x00221;
  undefined4 extraout_r4_x00222;
  undefined4 extraout_r4_x00223;
  undefined4 extraout_r4_x00224;
  undefined4 extraout_r4_x00225;
  undefined4 extraout_r4_x00226;
  undefined4 extraout_r4_x00227;
  undefined4 extraout_r4_x00228;
  undefined4 extraout_r4_x00229;
  undefined4 extraout_r4_x00230;
  undefined4 extraout_r4_x00231;
  undefined4 extraout_r4_x00232;
  undefined4 extraout_r4_x00233;
  undefined4 extraout_r4_x00234;
  undefined4 extraout_r4_x00235;
  undefined4 extraout_r4_x00236;
  undefined4 extraout_r4_x00237;
  undefined4 extraout_r4_x00238;
  undefined4 extraout_r4_x00239;
  undefined4 extraout_r4_x00240;
  undefined4 extraout_r4_x00241;
  undefined4 extraout_r4_x00242;
  char *pcVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 uVar11;
  float fVar12;
  float fVar13;
  undefined4 *puVar14;
  uint *puVar15;
  uint *puVar16;
  float fVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  uint local_198;
  undefined4 local_194;
  char local_134;
  char local_133;
  char acStack_132 [266];
  undefined4 local_28;
  
  puVar16 = (uint *)param_1[2];
  uVar18 = *puVar16;
  puVar15 = puVar16 + 1;
  param_1[2] = (int)puVar15;
  uVar7 = uVar18 & 0xffff;
  if (uVar7 < 0xbf) {
    param_7 = 0;
    switch(uVar7) {
    default:
      goto switchD_000ddc1c_caseD_0;
    case 1:
      pcVar5 = "abs";
      FUN_000da9fc(param_1,param_1[0x87],"abs",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_01,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 2:
      pcVar5 = "acos";
      FUN_000da9fc(param_1,param_1[0x87],"acos",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_02,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 3:
      pcVar5 = "add";
      FUN_000da9fc(param_1,param_1[0x87],"add",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_44,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 4:
      pcVar5 = "asin";
      FUN_000da9fc(param_1,param_1[0x87],"asin",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_04,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 5:
      pcVar5 = "atan";
      FUN_000da9fc(param_1,param_1[0x87],"atan",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_05,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 6:
      pcVar5 = "break";
      FUN_000da9fc(param_1,param_1[0x87],"break",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00111,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 7:
      pcVar5 = "breakc";
      FUN_000da9fc(param_1,param_1[0x87],"breakc",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dccd4)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00112,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da904(param_1,", ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00113,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00114,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 8:
      pcVar5 = "call";
      FUN_000da9fc(param_1,param_1[0x87],"call",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000db2f4(param_1,extraout_r4_x00119,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00120,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 9:
      pcVar5 = "callnz";
      FUN_000da9fc(param_1,param_1[0x87],"callnz",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00121,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da904(param_1,", ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000db2f4(param_1,extraout_r4_x00122,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00123,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 10:
      pcVar5 = "clamp";
      FUN_000da9fc(param_1,param_1[0x87],"clamp",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dda98)(param_1,extraout_r4_56,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xb:
      pcVar5 = "clg";
      FUN_000da9fc(param_1,param_1[0x87],"clg",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_06,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xc:
      pcVar5 = "cmov";
      FUN_000da9fc(param_1,param_1[0x87],"cmov",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_07,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xd:
      pcVar5 = "cmp";
      FUN_000da9fc(param_1,param_1[0x87],"cmp",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dccd4)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000db350(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dda98)(param_1,extraout_r4_57,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xe:
      pcVar5 = "colorclamp";
      FUN_000da9fc(param_1,param_1[0x87],"colorclamp",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_09,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xf:
      uVar7 = *puVar15;
      param_1[2] = (int)(puVar16 + 2);
      iVar21 = (uVar7 & 0xffff) * 4;
      pcVar4 = " ); ";
      FUN_000da9fc(param_1,param_1[0x87]," ); ",param_4,param_5,param_6,param_7,puVar15);
      pcVar5 = (char *)param_1[2];
      iVar19 = 0;
      uVar6 = extraout_r4_x00241;
      if ((uVar7 & 0xffff) != 0) {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        pcVar4 = (char *)(int)cVar1;
        iVar19 = 1;
        if (pcVar4 != (char *)0x0) {
          iVar20 = 1;
          do {
            FUN_000da904(param_1,"%c",pcVar4,param_4,param_5,param_6,param_7,puVar15);
            iVar19 = iVar21;
            uVar6 = extraout_r4_x00242;
            if (iVar20 == iVar21) break;
            cVar1 = *pcVar5;
            iVar20 = iVar20 + 1;
            pcVar5 = pcVar5 + 1;
            pcVar4 = (char *)(int)cVar1;
            iVar19 = iVar20;
          } while (pcVar4 != (char *)0x0);
        }
      }
      for (iVar21 = iVar21 - iVar19; iVar21 != 0; iVar21 = iVar21 + -1) {
        pcVar5 = pcVar5 + 1;
      }
      param_1[2] = (int)pcVar5;
      FUN_000da984(param_1,uVar6,pcVar4,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x10:
      pcVar5 = "continue";
      FUN_000da9fc(param_1,param_1[0x87],"continue",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00130,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x11:
      pcVar5 = "continuec";
      FUN_000da9fc(param_1,param_1[0x87],"continuec",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dccd4)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00131,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da904(param_1,", ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00132,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00133,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x12:
      pcVar5 = "cos";
      FUN_000da9fc(param_1,param_1[0x87],"cos",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_10,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x13:
      pcVar5 = "crs";
      FUN_000da9fc(param_1,param_1[0x87],"crs",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_45,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x14:
      pcVar5 = "dclarray";
      FUN_000da9fc(param_1,param_1[0x87],"dclarray",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00180,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da904(param_1,", ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00181,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00182,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x15:
      local_198 = uVar18;
      FUN_000da9fc(param_1,param_1[0x87],"dcldef",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dc4bc)(param_1,local_198,local_194,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd6bc)(param_1,extraout_r4_x00202,local_194,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00203,local_194,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x16:
      pcVar5 = "dclpi";
      FUN_000da9fc(param_1,param_1[0x87],"dclpi",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dc1ac)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd6bc)(param_1,extraout_r4_x00191,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00192,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x17:
      pcVar5 = "dclpin";
      FUN_000da9fc(param_1,param_1[0x87],"dclpin",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dbf34)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd6bc)(param_1,extraout_r4_x00193,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00194,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x18:
      FUN_000da9fc(param_1,param_1[0x87],"dclpp",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da9fc(param_1,param_1[0x87],"dclv",param_4,param_5,param_6,param_7,puVar15);
      uVar7 = uVar18 >> 0x10 & 0xff;
      FUN_001a32d0(&local_198,"_param(%d)",uVar7,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1,&local_198,uVar7,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd6bc)(param_1,extraout_r4_x00195,uVar7,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00196,uVar7,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x19:
      pcVar5 = "dclpt";
      FUN_000da9fc(param_1,param_1[0x87],"dclpt",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dc3b0)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7);
      ((int (*)())FUN_000dc83c)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00201,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x1a:
      pcVar5 = "dclv";
      FUN_000da9fc(param_1,param_1[0x87],"dclv",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dc098)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd6bc)(param_1,extraout_r4_x00197,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00198,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x1b:
      pcVar5 = "dclvout";
      FUN_000da9fc(param_1,param_1[0x87],"dclvout",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dbe18)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd6bc)(param_1,extraout_r4_x00199,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00200,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x1c:
      pcVar5 = "def";
      FUN_000da9fc(param_1,param_1[0x87],"def",param_4,param_5,param_6,param_7,puVar15);
      if ((*(uint *)param_1[2] & 0x3f0000) == 0x10000) {
        puVar16 = &local_198;
        uVar6 = ((int (*)())FUN_000dd6bc)(param_1,extraout_r4_x00204,pcVar5,param_4,param_5,param_6,param_7,
                             puVar15);
        pfVar3 = (float *)param_1[2];
        puVar15 = (uint *)0x19dbd8;
        fVar12 = *pfVar3;
        param_1[2] = (int)(pfVar3 + 1);
        fVar17 = pfVar3[1];
        param_1[2] = (int)(pfVar3 + 2);
        fVar13 = pfVar3[2];
        param_1[2] = (int)(pfVar3 + 3);
        puVar14 = (*(undefined4 * *)(pfVar3 + (3)));
        param_1[2] = (int)(pfVar3 + 4);
        local_134 = s___001a44f4[0];
        local_133 = s___001a44f4[1];
        acStack_132[0] = s___001a44f4[2];
        puVar2 = puVar14;
        ((char * (*)())FUN_000cdc3c)(uVar6,10,puVar16,(double)fVar12);
        iVar21 = FUN_001a32d0(acStack_132,"%s, ",puVar16,param_4,param_5,param_6,puVar2,puVar15);
        pcVar5 = acStack_132 + iVar21;
        ((char * (*)())FUN_000cdc3c)(iVar21,10,puVar16,(double)fVar17);
        iVar21 = FUN_001a32d0(pcVar5,"%s, ",puVar16,param_4,param_5,param_6,puVar2,puVar15);
        ((char * (*)())FUN_000cdc3c)(iVar21,10,puVar16,(double)fVar13);
        iVar19 = FUN_001a32d0(pcVar5 + iVar21,"%s, ",puVar16,param_4,param_5,param_6,puVar2,puVar15)
        ;
        ((char * (*)())FUN_000cdc3c)(iVar19,10,puVar16,(double)GH_U2F((unsigned int)(puVar14)));
        FUN_001a32d0(pcVar5 + iVar21 + iVar19,"%s",puVar16,param_4,param_5,param_6,puVar2,puVar15);
      }
      else {
        ((int (*)())FUN_000dd6bc)(param_1,extraout_r4_x00204,pcVar5,param_4,param_5,param_6,param_7,puVar15);
        puVar14 = (undefined4 *)param_1[2];
        puVar16 = (uint *)*puVar14;
        puVar2 = puVar14 + 2;
        param_1[2] = (int)(puVar14 + 1);
        param_4 = puVar14[1];
        param_1[2] = (int)puVar2;
        param_5 = puVar14[2];
        param_1[2] = (int)(puVar14 + 3);
        param_6 = puVar14[3];
        param_1[2] = (int)(puVar14 + 4);
        FUN_001a32d0(&local_134,", %lu, %lu, %lu, %lu",puVar16,param_4,param_5,param_6,puVar2,
                     puVar15);
      }
      FUN_000da904(param_1,&local_134,puVar16,param_4,param_5,param_6,puVar2,puVar15);
      FUN_000da984(param_1,extraout_r4_x00205,puVar16,param_4,param_5,param_6,puVar2,puVar15);
      local_28 = 1;
      break;
    case 0x1d:
      pcVar5 = "defb";
      FUN_000da9fc(param_1,param_1[0x87],"defb",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd6bc)(param_1,extraout_r4_x00206,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      uVar6 = *(undefined4 *)param_1[2];
      param_1[2] = (int)((undefined4 *)param_1[2] + 1);
      FUN_001a32d0(&local_198,", %lu",uVar6,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1,&local_198,uVar6,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00207,uVar6,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x1e:
      pcVar5 = "det";
      FUN_000da9fc(param_1,param_1[0x87],"det",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_x00104,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x1f:
      pcVar5 = "dist";
      FUN_000da9fc(param_1,param_1[0x87],"dist",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_46,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x20:
      pcVar5 = "div";
      FUN_000da9fc(param_1,param_1[0x87],"div",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dc57c)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_58,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x21:
      pcVar5 = "dp2add";
      FUN_000da9fc(param_1,param_1[0x87],"dp2add",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dda98)(param_1,extraout_r4_60,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x22:
      pcVar5 = "dp3";
      FUN_000da9fc(param_1,param_1[0x87],"dp3",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_47,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x23:
      pcVar5 = "dp4";
      FUN_000da9fc(param_1,param_1[0x87],"dp4",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_48,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x24:
      pcVar5 = "dst";
      FUN_000da9fc(param_1,param_1[0x87],"dst",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_49,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x25:
      pcVar5 = "dsx";
      FUN_000da9fc(param_1,param_1[0x87],"dsx",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dca3c)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_61,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x26:
      pcVar5 = "dsy";
      FUN_000da9fc(param_1,param_1[0x87],"dsy",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dca3c)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_62,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x27:
      FUN_000da8e0(param_1,param_1[0x87] + -1);
      pcVar5 = "else";
      FUN_000da9fc(param_1,param_1[0x87],"else",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da8e0(param_1,param_1[0x87] + 1);
      FUN_000da984(param_1,extraout_r4_x00138,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x28:
      pcVar5 = "end";
      FUN_000da9fc(param_1,param_1[0x87],"end",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00150,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 0;
      break;
    case 0x29:
      FUN_000da8e0(param_1,param_1[0x87] + -1);
      pcVar5 = "endif";
      FUN_000da9fc(param_1,param_1[0x87],"endif",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00152,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x2a:
      FUN_000da8e0(param_1,param_1[0x87] + -1);
      pcVar5 = "endloop";
      FUN_000da9fc(param_1,param_1[0x87],"endloop",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00153,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x2b:
      pcVar5 = "endmain";
      FUN_000da9fc(param_1,param_1[0x87],"endmain",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00139,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x2c:
      pcVar5 = "exn";
      FUN_000da9fc(param_1,param_1[0x87],"exn",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_13,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x2d:
      pcVar5 = "exp";
      FUN_000da9fc(param_1,param_1[0x87],"exp",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_15,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x2e:
      pcVar5 = "expp";
      FUN_000da9fc(param_1,param_1[0x87],"expp",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_16,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x2f:
      pcVar5 = "faceforward";
      FUN_000da9fc(param_1,param_1[0x87],"faceforward",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dda98)(param_1,extraout_r4_63,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x30:
      pcVar5 = "flr";
      FUN_000da9fc(param_1,param_1[0x87],"flr",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_17,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x31:
      pcVar5 = "frc";
      FUN_000da9fc(param_1,param_1[0x87],"frc",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x32:
      pcVar5 = "func";
      FUN_000da9fc(param_1,param_1[0x87],"func",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da8e0(param_1,param_1[0x87] + 1);
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000db2f4(param_1,extraout_r4_x00154,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00155,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x33:
      pcVar5 = "fwidth";
      FUN_000da9fc(param_1,param_1[0x87],"fwidth",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_19,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x34:
      pcVar5 = "ifc";
      FUN_000da9fc(param_1,param_1[0x87],"ifc",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da8e0(param_1,param_1[0x87] + 1);
      ((int (*)())FUN_000dccd4)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00156,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da904(param_1,", ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00157,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00158,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x35:
      pcVar5 = "ifnz ";
      FUN_000da9fc(param_1,param_1[0x87],"ifnz ",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da8e0(param_1,param_1[0x87] + 1);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00164,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00165,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x36:
    case 0x43:
      FUN_000da9fc(param_1,param_1[0x87],"memimport",param_4,param_5,param_6,param_7,puVar15);
      uVar7 = uVar18 >> 0x10 & 0x3f;
      FUN_001a32d0(&local_198,"_elem(%d)",uVar7,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1,&local_198,uVar7,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_x00237,uVar7,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x37:
      pcVar5 = "kill";
      FUN_000da9fc(param_1,param_1[0x87],"kill",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dc83c)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dca18)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00109,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00110,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x38:
      pcVar5 = "len";
      FUN_000da9fc(param_1,param_1[0x87],"len",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_21,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x39:
      pcVar5 = "lit";
      FUN_000da9fc(param_1,param_1[0x87],"lit",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_22,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x3a:
      pcVar5 = "ln";
      FUN_000da9fc(param_1,param_1[0x87],"ln",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dc57c)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_64,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x3b:
      pcVar5 = "lod";
      FUN_000da9fc(param_1,param_1[0x87],"lod",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dc83c)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_x00231,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x3c:
      pcVar5 = "log";
      FUN_000da9fc(param_1,param_1[0x87],"log",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dc57c)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_65,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x3d:
      pcVar5 = "logp";
      FUN_000da9fc(param_1,param_1[0x87],"logp",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dc57c)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_66,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x3e:
      pcVar5 = "loop";
      FUN_000da9fc(param_1,param_1[0x87],"loop",param_4,param_5,param_6,param_7,puVar15);
      if ((uVar18 & 0x10000) == 0) {
        pcVar4 = " ";
      }
      else {
        pcVar4 = "_rep ";
      }
      FUN_000da904(param_1,pcVar4,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da8e0(param_1,param_1[0x87] + 1);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00170,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00171,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x3f:
      pcVar5 = "lrp";
      FUN_000da9fc(param_1,param_1[0x87],"lrp",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dda98)(param_1,extraout_r4_67,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x40:
      pcVar5 = "mad";
      FUN_000da9fc(param_1,param_1[0x87],"mad",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dda98)(param_1,extraout_r4_68,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x41:
      pcVar5 = "max";
      FUN_000da9fc(param_1,param_1[0x87],"max",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_50,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x42:
      FUN_000da9fc(param_1,param_1[0x87],"memexport",param_4,param_5,param_6,param_7,puVar15);
      uVar10 = uVar18 >> 0x17 & 0x3f;
      uVar7 = uVar18 >> 0x10 & 0x3f;
      uVar18 = uVar18 >> 0x16 & 1;
      FUN_001a32d0(&local_198,"_exportStream(%d)_stateStride(%d)_elemOffset(%d)",uVar7,uVar18,uVar10
                   ,param_6,param_7,puVar15);
      FUN_000da904(param_1,&local_198,uVar7,uVar18,uVar10,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_x00240,uVar7,uVar18,uVar10,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x44:
      pcVar5 = "min";
      FUN_000da9fc(param_1,param_1[0x87],"min",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_51,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x45:
      pcVar5 = "mmul";
      FUN_000da9fc(param_1,param_1[0x87],"mmul",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dcbcc)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_95,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x46:
      pcVar5 = "mod";
      FUN_000da9fc(param_1,param_1[0x87],"mod",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_52,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x47:
      pcVar5 = "mov";
      FUN_000da9fc(param_1,param_1[0x87],"mov",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_25,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x48:
      pcVar5 = "mova";
      FUN_000da9fc(param_1,param_1[0x87],"mova",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dc9f4)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_96,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x49:
      pcVar5 = "mul";
      FUN_000da9fc(param_1,param_1[0x87],"mul",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_53,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x4a:
      pcVar5 = "noise";
      FUN_000da9fc(param_1,param_1[0x87],"noise",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_26,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x4b:
      pcVar5 = "nop";
      FUN_000da9fc(param_1,param_1[0x87],"nop",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00173,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x4c:
      pcVar5 = "nrm";
      FUN_000da9fc(param_1,param_1[0x87],"nrm",param_4,param_5,param_6,param_7,puVar15);
      if ((uVar18 & 0x40000) != 0) {
        FUN_000da904(param_1,"_nrm4",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      }
      ((int (*)())FUN_000dc57c)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_97,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x4d:
      pcVar5 = "pireduce";
      FUN_000da9fc(param_1,param_1[0x87],"pireduce",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_28,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x4e:
      pcVar5 = "pow";
      FUN_000da9fc(param_1,param_1[0x87],"pow",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_54,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x50:
      pcVar5 = "project";
      FUN_000da9fc(param_1,param_1[0x87],"project",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dc83c)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_98,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x51:
      pcVar5 = "rcp";
      FUN_000da9fc(param_1,param_1[0x87],"rcp",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dc57c)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_99,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x52:
      pcVar5 = "reflect";
      FUN_000da9fc(param_1,param_1[0x87],"reflect",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dc9d0)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_x00100,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x53:
      FUN_000da8e0(param_1,param_1[0x87] + -1);
      pcVar5 = "ret";
      FUN_000da9fc(param_1,param_1[0x87],"ret",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00174,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x54:
      pcVar5 = "rnd";
      FUN_000da9fc(param_1,param_1[0x87],"rnd",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_29,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x55:
      pcVar5 = "rsq";
      FUN_000da9fc(param_1,param_1[0x87],"rsq",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dc57c)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_x00101,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x56:
      pcVar5 = "set";
      FUN_000da9fc(param_1,param_1[0x87],"set",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dccd4)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_x00102,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x57:
      pcVar5 = "sgn";
      FUN_000da9fc(param_1,param_1[0x87],"sgn",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_38,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x58:
      pcVar5 = "sin";
      FUN_000da9fc(param_1,param_1[0x87],"sin",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_39,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x59:
      pcVar5 = "sincos";
      FUN_000da9fc(param_1,param_1[0x87],"sincos",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_40,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x5a:
      pcVar5 = "sqrt";
      FUN_000da9fc(param_1,param_1[0x87],"sqrt",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_41,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x5b:
      pcVar5 = "sub";
      FUN_000da9fc(param_1,param_1[0x87],"sub",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_55,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x5c:
      pcVar5 = "tan";
      FUN_000da9fc(param_1,param_1[0x87],"tan",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_42,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x5d:
      pcVar5 = "texld";
      FUN_000da9fc(param_1,param_1[0x87],"texld",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dcb34)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_x00232,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x5e:
      pcVar5 = "texldb";
      FUN_000da9fc(param_1,param_1[0x87],"texldb",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dca60)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_x00233,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x5f:
      pcVar5 = "texldd";
      FUN_000da9fc(param_1,param_1[0x87],"texldd",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dcb34)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dda98)(param_1,extraout_r4_x00234,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x60:
      pcVar5 = "texldms";
      FUN_000da9fc(param_1,param_1[0x87],"texldms",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dc88c)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_x00235,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x61:
      pcVar5 = "texweight";
      FUN_000da9fc(param_1,param_1[0x87],"texweight",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dc83c)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dca3c)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_x00236,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x62:
      pcVar5 = "transpose";
      FUN_000da9fc(param_1,param_1[0x87],"transpose",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_x00103,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 99:
      pcVar5 = "trc";
      FUN_000da9fc(param_1,param_1[0x87],"trc",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_43,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 100:
      pcVar5 = "dxsincos";
      FUN_000da9fc(param_1,param_1[0x87],"dxsincos",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dda98)(param_1,extraout_r4_11,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x65:
      pcVar5 = "break_logicalz";
      FUN_000da9fc(param_1,param_1[0x87],"break_logicalz",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00115,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00116,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x66:
      pcVar5 = "break_logicalnz";
      FUN_000da9fc(param_1,param_1[0x87],"break_logicalnz",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00117,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00118,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x67:
      pcVar5 = "call_logicalz";
      FUN_000da9fc(param_1,param_1[0x87],"call_logicalz",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00124,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da904(param_1,", ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000db2f4(param_1,extraout_r4_x00125,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00126,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x68:
      pcVar5 = "call_logicalnz";
      FUN_000da9fc(param_1,param_1[0x87],"call_logicalnz",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00127,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da904(param_1,", ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000db2f4(param_1,extraout_r4_x00128,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00129,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x69:
      pcVar5 = "case ";
      FUN_000da9fc(param_1,param_1[0x87],"case ",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      uVar6 = *(undefined4 *)param_1[2];
      param_1[2] = (int)((undefined4 *)param_1[2] + 1);
      FUN_001a32d0(&local_198,"%lu",uVar6,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1,&local_198,uVar6,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00163,uVar6,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x6a:
      pcVar5 = "continue_logicalz";
      FUN_000da9fc(param_1,param_1[0x87],"continue_logicalz",param_4,param_5,param_6,param_7,puVar15
                  );
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00134,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00135,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x6b:
      pcVar5 = "continue_logicalnz";
      FUN_000da9fc(param_1,param_1[0x87],"continue_logicalnz",param_4,param_5,param_6,param_7,
                   puVar15);
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00136,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00137,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x6c:
      pcVar5 = "default";
      FUN_000da9fc(param_1,param_1[0x87],"default",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00162,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x6d:
      pcVar5 = "endswitch";
      FUN_000da9fc(param_1,param_1[0x87],"endswitch",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00161,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x6e:
      pcVar5 = "endfunc";
      FUN_000da9fc(param_1,param_1[0x87],"endfunc",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00151,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x6f:
      pcVar5 = "if_logicalz ";
      FUN_000da9fc(param_1,param_1[0x87],"if_logicalz ",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da8e0(param_1,param_1[0x87] + 1);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00166,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00167,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x70:
      pcVar5 = "if_logicalnz ";
      FUN_000da9fc(param_1,param_1[0x87],"if_logicalnz ",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da8e0(param_1,param_1[0x87] + 1);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00168,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00169,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x71:
      pcVar5 = "whileloop";
      FUN_000da9fc(param_1,param_1[0x87],"whileloop",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00172,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da8e0(param_1,param_1[0x87] + 1);
      local_28 = 1;
      break;
    case 0x72:
      pcVar5 = "switch";
      FUN_000da9fc(param_1,param_1[0x87],"switch",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00159,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00160,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x73:
      pcVar5 = "ret_dyn";
      FUN_000da9fc(param_1,param_1[0x87],"ret_dyn",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00175,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x74:
      pcVar5 = "ret_logicalz ";
      FUN_000da9fc(param_1,param_1[0x87],"ret_logicalz ",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00176,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00177,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x75:
      pcVar5 = "ret_logicalnz ";
      FUN_000da9fc(param_1,param_1[0x87],"ret_logicalnz ",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00178,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00179,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x76:
      if ((int)uVar18 < 0) {
        FUN_000da9fc(param_1,param_1[0x87],"dcl_immed_cb",param_4,param_5,param_6,param_7,puVar15);
        iVar19 = *(int *)param_1[2];
        param_1[2] = (int)((int *)param_1[2] + 1);
        iVar21 = iVar19;
        FUN_001a32d0(&local_198,"count = %d ",iVar19,param_4,param_5,param_6,param_7,puVar15);
        FUN_000da904(param_1,&local_198,iVar21,param_4,param_5,param_6,param_7,puVar15);
        FUN_000da984(param_1,extraout_r4_x00185,iVar21,param_4,param_5,param_6,param_7,puVar15);
        if (0 < iVar19) {
          iVar21 = 0;
          do {
            iVar21 = iVar21 + 1;
            uVar6 = *(undefined4 *)param_1[2];
            param_1[2] = (int)((undefined4 *)param_1[2] + 1);
            FUN_001a32d0(&local_198," 0x%x ",uVar6,param_4,param_5,param_6,param_7,puVar15);
            puVar16 = &local_198;
            FUN_000da9fc(param_1,param_1[0x87] + 1,&local_198,param_4,param_5,param_6,param_7,
                         puVar15);
            FUN_000da984(param_1,extraout_r4_x00186,puVar16,param_4,param_5,param_6,param_7,puVar15)
            ;
          } while (iVar19 != iVar21);
        }
        local_28 = 1;
      }
      else {
        pcVar5 = "dcl_cb";
        FUN_000da9fc(param_1,param_1[0x87],"dcl_cb",param_4,param_5,param_6,param_7,puVar15);
        FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
        ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00187,pcVar5,param_4,param_5,param_6,param_7);
        FUN_000da984(param_1,extraout_r4_x00188,pcVar5,param_4,param_5,param_6,param_7,puVar15);
        local_28 = 1;
      }
      break;
    case 0x77:
      pcVar5 = "dcl_indexed_temp_array";
      FUN_000da9fc(param_1,param_1[0x87],"dcl_indexed_temp_array",param_4,param_5,param_6,param_7,
                   puVar15);
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00183,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00184,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x78:
      pcVar5 = "dcl_input_primitive";
      FUN_000da9fc(param_1,param_1[0x87],"dcl_input_primitive",param_4,param_5,param_6,param_7,
                   puVar15);
      ((int (*)())FUN_000dc71c)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00222,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x79:
      pcVar5 = "dcl_literal";
      FUN_000da9fc(param_1,param_1[0x87],"dcl_literal",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00189,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da904(param_1,",",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      puVar2 = (undefined4 *)param_1[2];
      uVar6 = *puVar2;
      puVar14 = puVar2 + 2;
      param_1[2] = (int)(puVar2 + 1);
      uVar8 = puVar2[1];
      param_1[2] = (int)puVar14;
      uVar9 = puVar2[2];
      param_1[2] = (int)(puVar2 + 3);
      uVar11 = puVar2[3];
      param_1[2] = (int)(puVar2 + 4);
      FUN_001a32d0(&local_134," 0x%08lX, 0x%08lX, 0x%08lX, 0x%08lX",uVar6,uVar8,uVar9,uVar11,puVar14
                   ,puVar15);
      FUN_000da904(param_1,&local_134,uVar6,uVar8,uVar9,uVar11,puVar14,puVar15);
      FUN_000da984(param_1,extraout_r4_x00190,uVar6,uVar8,uVar9,uVar11,puVar14,puVar15);
      local_28 = 1;
      break;
    case 0x7a:
      FUN_000da9fc(param_1,param_1[0x87],"dcl_max_output_vertex_count",param_4,param_5,param_6,
                   param_7,puVar15);
      uVar7 = uVar18 >> 0x10 & 0x3fff;
      FUN_001a32d0(&local_198,"(%d)",uVar7,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1,&local_198,uVar7,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00208,uVar7,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x7b:
      pcVar5 = "dcl_odepth";
      FUN_000da9fc(param_1,param_1[0x87],"dcl_odepth",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00224,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x7c:
      pcVar5 = "dcl_output_topology";
      FUN_000da9fc(param_1,param_1[0x87],"dcl_output_topology",param_4,param_5,param_6,param_7,
                   puVar15);
      ((int (*)())FUN_000dc658)(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00209,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x7d:
      pcVar5 = "dcl_output";
      FUN_000da9fc(param_1,param_1[0x87],"dcl_output",param_4,param_5,param_6,param_7,puVar15);
      uVar7 = uVar18 >> 0x10 & 0x3fff;
      uVar6 = extraout_r4_x00210;
      if (uVar7 < 0x13) {
        FUN_000da904(param_1,(PTR_s__position_001dc3f4)[uVar7],pcVar5,param_4,param_5,param_6,
                     param_7,puVar15);
        uVar6 = extraout_r4_x00211;
      }
      ((int (*)())FUN_000dd6bc)(param_1,uVar6,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00212,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x7e:
      pcVar5 = "dcl_input";
      FUN_000da9fc(param_1,param_1[0x87],"dcl_input",param_4,param_5,param_6,param_7,puVar15);
      uVar6 = extraout_r4_x00213;
      if ((uVar18 & 0x7c000) != 0x14000) {
        FUN_000da904(param_1,*(undefined4 *)
                              ((int)PTR_s__position_001dc3f4 + (uVar18 >> 0xc & 0x7c)),pcVar5,
                     param_4,param_5,param_6,param_7,puVar15);
        uVar6 = extraout_r4_x00214;
      }
      uVar7 = uVar18 >> 0x13 & 7;
      if (uVar7 < 6) {
        param_7 = 0;
        switch(uVar7) {
        case 1:
          FUN_000da904(param_1,"_interp(constant)",pcVar5,param_4,param_5,param_6,param_7,puVar15);
          uVar6 = extraout_r4_x00215;
          break;
        case 2:
          FUN_000da904(param_1,"_interp(linear)",pcVar5,param_4,param_5,param_6,param_7,puVar15);
          uVar6 = extraout_r4_x00216;
          break;
        case 3:
          FUN_000da904(param_1,"_interp(linear_centroid)",pcVar5,param_4,param_5,param_6,param_7,
                       puVar15);
          uVar6 = extraout_r4_x00217;
          break;
        case 4:
          FUN_000da904(param_1,"_interp(linear_noperspective)",pcVar5,param_4,param_5,param_6,
                       param_7,puVar15);
          uVar6 = extraout_r4_x00218;
          break;
        case 5:
          FUN_000da904(param_1,"_interp(linear_noperspective_centroid)",pcVar5,param_4,param_5,
                       param_6,param_7,puVar15);
          uVar6 = extraout_r4_x00219;
        }
      }
      else {
        FUN_000da904(param_1,"!!!bad interp mode!!!",pcVar5,param_4,param_5,param_6,param_7,puVar15)
        ;
        *param_1 = *param_1 + 1;
        uVar6 = extraout_r4_x00220;
      }
      ((int (*)())FUN_000dd6bc)(param_1,uVar6,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00221,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x7f:
      pcVar5 = "dcl_vprim";
      FUN_000da9fc(param_1,param_1[0x87],"dcl_vprim",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00223,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x80:
      FUN_000da9fc(param_1,param_1[0x87],"dcl_resource",param_4,param_5,param_6,param_7,puVar15);
      uVar7 = uVar18 >> 0x10 & 0xff;
      FUN_001a32d0(&local_134,"_id(%d)",uVar7,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1,&local_134,uVar7,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dc2c4)(param_1,uVar18 >> 0x18 & 0xf,uVar7,param_4,param_5,param_6,param_7);
      FUN_000db048(param_1,extraout_r4_x00225,uVar7,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00226,uVar7,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x81:
      pcVar5 = "cut";
      FUN_000da9fc(param_1,param_1[0x87],"cut",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00141,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x82:
      pcVar5 = "discard_logicalz";
      FUN_000da9fc(param_1,param_1[0x87],"discard_logicalz",param_4,param_5,param_6,param_7,puVar15)
      ;
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00227,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00228,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x83:
      pcVar5 = "discard_logicalnz";
      FUN_000da9fc(param_1,param_1[0x87],"discard_logicalnz",param_4,param_5,param_6,param_7,puVar15
                  );
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4_x00229,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_x00230,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x84:
      pcVar5 = "emit";
      FUN_000da9fc(param_1,param_1[0x87],"emit",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00140,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x85:
      pcVar5 = "emitcut";
      FUN_000da9fc(param_1,param_1[0x87],"emitcut",param_4,param_5,param_6,param_7,puVar15);
      FUN_000da984(param_1,extraout_r4_x00142,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x86:
      FUN_000da9fc(param_1,param_1[0x87],"load",param_4,param_5,param_6,param_7,puVar15);
      uVar7 = uVar18 >> 0x10 & 0x1fff;
      FUN_001a32d0(&local_134,"_id(%d)",uVar7,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1,&local_134,uVar7,param_4,param_5,param_6,param_7,puVar15);
      FUN_000db81c(param_1,uVar18,uVar7,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_x00143,uVar7,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x87:
      FUN_000da9fc(param_1,param_1[0x87],"resinfo",param_4,param_5,param_6,param_7,puVar15);
      uVar7 = uVar18 >> 0x10 & 0xfff;
      FUN_001a32d0(&local_134,"_id(%d)",uVar7,param_4,param_5,param_6,param_7,puVar15);
      FUN_000da904(param_1,&local_134,uVar7,param_4,param_5,param_6,param_7,puVar15);
      uVar6 = extraout_r4_x00238;
      if ((uVar18 & 0x10000000) != 0) {
        FUN_000da904(param_1,"_uint",uVar7,param_4,param_5,param_6,param_7,puVar15);
        uVar6 = extraout_r4_x00239;
      }
      ((int (*)())FUN_000ddb7c)(param_1,uVar6,uVar7,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x88:
      pcVar5 = "sample";
      FUN_000da9fc(param_1,param_1[0x87],"sample",param_4,param_5,param_6,param_7,puVar15);
      FUN_000db8e0(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000db81c(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_x00144,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x89:
      pcVar5 = "sample_b";
      FUN_000da9fc(param_1,param_1[0x87],"sample_b",param_4,param_5,param_6,param_7,puVar15);
      FUN_000db8e0(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000db81c(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_x00146,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x8a:
      pcVar5 = "sample_g";
      FUN_000da9fc(param_1,param_1[0x87],"sample_g",param_4,param_5,param_6,param_7,puVar15);
      FUN_000db8e0(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000db81c(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dda98)(param_1,extraout_r4_x00145,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x8b:
      pcVar5 = "sample_l";
      FUN_000da9fc(param_1,param_1[0x87],"sample_l",param_4,param_5,param_6,param_7,puVar15);
      FUN_000db8e0(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000db81c(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_x00147,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x8c:
      pcVar5 = "sample_c";
      FUN_000da9fc(param_1,param_1[0x87],"sample_c",param_4,param_5,param_6,param_7,puVar15);
      FUN_000db8e0(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000db81c(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_x00148,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x8d:
      pcVar5 = "sample_c_lz";
      FUN_000da9fc(param_1,param_1[0x87],"sample_c_lz",param_4,param_5,param_6,param_7,puVar15);
      FUN_000db8e0(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      FUN_000db81c(param_1,uVar18,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_x00149,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x8e:
      pcVar5 = "inot";
      FUN_000da9fc(param_1,param_1[0x87],"inot",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_x00105,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x8f:
      pcVar5 = "ior";
      FUN_000da9fc(param_1,param_1[0x87],"ior",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_x00106,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x90:
      pcVar5 = "ixor";
      FUN_000da9fc(param_1,param_1[0x87],"ixor",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_x00107,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x91:
      pcVar5 = "iadd";
      FUN_000da9fc(param_1,param_1[0x87],"iadd",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_x00108,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x92:
      pcVar5 = "imad";
      FUN_000da9fc(param_1,param_1[0x87],"imad",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dda98)(param_1,extraout_r4_69,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x93:
      pcVar5 = "imax";
      FUN_000da9fc(param_1,param_1[0x87],"imax",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_70,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x94:
      pcVar5 = "imin";
      FUN_000da9fc(param_1,param_1[0x87],"imin",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_71,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x95:
      pcVar5 = "imul";
      FUN_000da9fc(param_1,param_1[0x87],"imul",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_72,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x96:
      pcVar5 = "imul_high";
      FUN_000da9fc(param_1,param_1[0x87],"imul_high",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_73,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x97:
      pcVar5 = "ieq";
      FUN_000da9fc(param_1,param_1[0x87],"ieq",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_74,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x98:
      pcVar5 = "ige";
      FUN_000da9fc(param_1,param_1[0x87],"ige",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_75,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x99:
      pcVar5 = "ilt";
      FUN_000da9fc(param_1,param_1[0x87],"ilt",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_76,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x9a:
      pcVar5 = "inegate";
      FUN_000da9fc(param_1,param_1[0x87],"inegate",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_77,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x9b:
      pcVar5 = "ine";
      FUN_000da9fc(param_1,param_1[0x87],"ine",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_78,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x9c:
      pcVar5 = "ishl";
      FUN_000da9fc(param_1,param_1[0x87],"ishl",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_79,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x9d:
      pcVar5 = "ishr";
      FUN_000da9fc(param_1,param_1[0x87],"ishr",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_80,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x9e:
      pcVar5 = "ushr";
      FUN_000da9fc(param_1,param_1[0x87],"ushr",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_81,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0x9f:
      pcVar5 = "udiv";
      FUN_000da9fc(param_1,param_1[0x87],"udiv",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_82,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xa0:
      pcVar5 = "umod";
      FUN_000da9fc(param_1,param_1[0x87],"umod",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_83,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xa1:
      pcVar5 = "umad";
      FUN_000da9fc(param_1,param_1[0x87],"umad",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dda98)(param_1,extraout_r4_84,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xa2:
      pcVar5 = "umax";
      FUN_000da9fc(param_1,param_1[0x87],"umax",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_85,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xa3:
      pcVar5 = "umin";
      FUN_000da9fc(param_1,param_1[0x87],"umin",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_86,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xa4:
      pcVar5 = "ult";
      FUN_000da9fc(param_1,param_1[0x87],"ult",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_87,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xa5:
      pcVar5 = "uge";
      FUN_000da9fc(param_1,param_1[0x87],"uge",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_88,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xa6:
      pcVar5 = "umul";
      FUN_000da9fc(param_1,param_1[0x87],"umul",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_89,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xa7:
      pcVar5 = "umul_high";
      FUN_000da9fc(param_1,param_1[0x87],"umul_high",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_90,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xa8:
      pcVar5 = "ftoi";
      FUN_000da9fc(param_1,param_1[0x87],"ftoi",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_91,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xa9:
      pcVar5 = "ftou";
      FUN_000da9fc(param_1,param_1[0x87],"ftou",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_92,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xaa:
      pcVar5 = "itof";
      FUN_000da9fc(param_1,param_1[0x87],"itof",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_93,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xab:
      pcVar5 = "utof";
      FUN_000da9fc(param_1,param_1[0x87],"utof",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_94,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xac:
      pcVar5 = "and";
      FUN_000da9fc(param_1,param_1[0x87],"and",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_03,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xad:
      pcVar5 = "cmov_logical";
      FUN_000da9fc(param_1,param_1[0x87],"cmov_logical",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dda98)(param_1,extraout_r4_08,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xae:
      pcVar5 = "eq";
      FUN_000da9fc(param_1,param_1[0x87],"eq",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_12,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xaf:
      pcVar5 = "exp_vec";
      FUN_000da9fc(param_1,param_1[0x87],"exp_vec",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_14,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xb0:
      pcVar5 = "ge";
      FUN_000da9fc(param_1,param_1[0x87],"ge",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_20,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xb1:
      pcVar5 = "log_vec";
      FUN_000da9fc(param_1,param_1[0x87],"log_vec",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_23,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xb2:
      pcVar5 = "lt";
      FUN_000da9fc(param_1,param_1[0x87],"lt",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_24,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xb3:
      pcVar5 = "ne";
      FUN_000da9fc(param_1,param_1[0x87],"ne",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_27,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xb4:
      pcVar5 = "round_nearest";
      FUN_000da9fc(param_1,param_1[0x87],"round_nearest",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_30,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xb5:
      pcVar5 = "round_neginf";
      FUN_000da9fc(param_1,param_1[0x87],"round_neginf",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_31,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xb6:
      pcVar5 = "round_plusinf";
      FUN_000da9fc(param_1,param_1[0x87],"round_plusinf",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_32,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xb7:
      pcVar5 = "round_zero";
      FUN_000da9fc(param_1,param_1[0x87],"round_zero",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_33,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xb8:
      pcVar5 = "rsq_vec";
      FUN_000da9fc(param_1,param_1[0x87],"rsq_vec",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_34,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xb9:
      pcVar5 = "sin_vec";
      FUN_000da9fc(param_1,param_1[0x87],"sin_vec",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_35,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xba:
      pcVar5 = "cos_vec";
      FUN_000da9fc(param_1,param_1[0x87],"cos_vec",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_36,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xbb:
      pcVar5 = "sqrt_vec";
      FUN_000da9fc(param_1,param_1[0x87],"sqrt_vec",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb7c)(param_1,extraout_r4_37,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xbc:
      pcVar5 = "dp2";
      FUN_000da9fc(param_1,param_1[0x87],"dp2",param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000ddb14)(param_1,extraout_r4_59,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
      break;
    case 0xbe:
      pcVar5 = "scatter";
      FUN_000da9fc(param_1,param_1[0x87],"scatter",param_4,param_5,param_6,param_7,puVar15);
      if ((uVar18 & 0x3fff0000) != 0) {
        FUN_000da904(param_1,"_quad",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      }
      FUN_000da904(param_1," ",pcVar5,param_4,param_5,param_6,param_7,puVar15);
      ((int (*)())FUN_000dd1f8)(param_1,extraout_r4,pcVar5,param_4,param_5,param_6,param_7);
      FUN_000da984(param_1,extraout_r4_00,pcVar5,param_4,param_5,param_6,param_7,puVar15);
      local_28 = 1;
    }
  }
  else {
switchD_000ddc1c_caseD_0:
    *param_1 = *param_1 + 1;
    FUN_000da904(param_1,"!!!unknownOpcode!!!",param_3,param_4,param_5,param_6,param_7,puVar15);
    local_28 = 1;
  }
  return local_28;
}

/* FUN_000e0640 @ 0xe0640 (84 bytes) */
int FUN_000e0640(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined8 uVar1;
  
  do {
    if ((uint)(*(int *)(param_1 + 0xc) * 4 + *(int *)(param_1 + 4)) <= *(uint *)(param_1 + 8)) {
      return;
    }
    uVar1 = ((int (*)())FUN_000ddbcc)(param_1,param_2,param_3,param_4,param_5,param_6,*(int *)(param_1 + 4));
    param_2 = (undefined4)uVar1;
  } while ((int)((ulonglong)uVar1 >> 0x20) != 0);
  return;
}

/* FUN_000e0694 @ 0xe0694 (68 bytes) */
int FUN_000e0694(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_2;
  FUN_000da8d0(param_1);
  ((int (*)())FUN_000dcdf4)(param_1,extraout_r4,param_3,in_r6,in_r7,in_r8,in_r9,in_r10);
  ((int (*)())FUN_000e0640)(param_1,extraout_r4_00,param_3,in_r6,in_r7,in_r8);
  return;
}

/* FUN_000e06d8 @ 0xe06d8 (104 bytes) */
int FUN_000e06d8(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  int param_2;
  int param_3;
  int param_4;
{
  undefined1 auStack_248 [528];
  int local_38;
  undefined4 local_34;
  
  if (((param_4 != 0) && (param_2 != 0)) && (param_3 != 0)) {
    FUN_000da8a8(auStack_248);
    local_38 = param_4;
    local_34 = param_1;
    ((int (*)())FUN_000e0694)(auStack_248,param_2,param_3);
  }
  return;
}

/* FUN_000e0740 @ 0xe0740 (80 bytes) */
int FUN_000e0740(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 extraout_r4;
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0xc) = param_3;
  uVar1 = 0x200;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_2;
  _memset(param_1 + 0x10,0,0x200);
  *(undefined4 *)(param_1 + 0x218) = 0;
  ((int (*)())FUN_000e0640)(param_1,extraout_r4,uVar1,param_4,param_5,param_6);
  return;
}

/* FUN_000e0794 @ 0xe0794 (36 bytes) */
int FUN_000e0794(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = ((int)param_2 >> 3) + param_1;
  *(byte *)(iVar1 + 0x59c) = (byte)(1 << (param_2 & 7)) | *(byte *)(iVar1 + 0x59c);
  return;
}

/* FUN_000e07b8 @ 0xe07b8 (36 bytes) */
int FUN_000e07b8(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = ((int)param_2 >> 3) + param_1;
  *(byte *)(iVar1 + 0x59c) =
       ((byte)(-2 << (param_2 & 7)) | (byte)(0xfffffffe >> 0x20 - (param_2 & 7))) &
       *(byte *)(iVar1 + 0x59c);
  return;
}

/* FUN_000e07dc @ 0xe07dc (84 bytes) */
int FUN_000e07dc(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  if ((((int)*(char *)(((int)param_2 >> 3) + param_1 + 0x59c) >> (param_2 & 7) & 1U) != 0) &&
     (iVar1 = FUN_0010dc9c(*(undefined4 *)(param_1 + 0x30c),param_2), iVar1 != 0)) {
    return 1;
  }
  return 0;
}

/* FUN_000e0830 @ 0xe0830 (32 bytes) */
int FUN_000e0830(param_1, param_2, param_3)
  int param_1;
  int param_2;
  int param_3;
{
  if ((param_2 == 0) && (*(int *)(param_1 + 0x64c) == param_3)) {
    return 1;
  }
  return 0;
}

/* FUN_000e0850 @ 0xe0850 (1112 bytes) */
int FUN_000e0850(param_1)
  int param_1;
{
  ((int (*)())FUN_000e07b8)(param_1,0);
  ((int (*)())FUN_000e0794)(param_1,1);
  ((int (*)())FUN_000e0794)(param_1,2);
  ((int (*)())FUN_000e0794)(param_1,3);
  ((int (*)())FUN_000e07b8)(param_1,4);
  ((int (*)())FUN_000e0794)(param_1,5);
  ((int (*)())FUN_000e0794)(param_1,6);
  ((int (*)())FUN_000e0794)(param_1,7);
  ((int (*)())FUN_000e07b8)(param_1,8);
  ((int (*)())FUN_000e0794)(param_1,9);
  ((int (*)())FUN_000e0794)(param_1,10);
  ((int (*)())FUN_000e07b8)(param_1,0xb);
  ((int (*)())FUN_000e0794)(param_1,0xc);
  ((int (*)())FUN_000e07b8)(param_1,0xd);
  ((int (*)())FUN_000e0794)(param_1,0xe);
  ((int (*)())FUN_000e0794)(param_1,0xf);
  ((int (*)())FUN_000e07b8)(param_1,0x10);
  ((int (*)())FUN_000e0794)(param_1,0x11);
  ((int (*)())FUN_000e07b8)(param_1,0x12);
  ((int (*)())FUN_000e0794)(param_1,0x13);
  ((int (*)())FUN_000e0794)(param_1,0x14);
  ((int (*)())FUN_000e0794)(param_1,0x15);
  ((int (*)())FUN_000e0794)(param_1,0x16);
  ((int (*)())FUN_000e0794)(param_1,0x17);
  ((int (*)())FUN_000e0794)(param_1,0x18);
  ((int (*)())FUN_000e0794)(param_1,0x19);
  ((int (*)())FUN_000e0794)(param_1,0x1a);
  ((int (*)())FUN_000e0794)(param_1,0x1b);
  ((int (*)())FUN_000e0794)(param_1,0x1c);
  ((int (*)())FUN_000e0794)(param_1,0x1d);
  ((int (*)())FUN_000e0794)(param_1,0x1e);
  ((int (*)())FUN_000e0794)(param_1,0x1f);
  ((int (*)())FUN_000e0794)(param_1,0x20);
  ((int (*)())FUN_000e0794)(param_1,0x21);
  ((int (*)())FUN_000e0794)(param_1,0x22);
  ((int (*)())FUN_000e0794)(param_1,0x23);
  ((int (*)())FUN_000e0794)(param_1,0x24);
  ((int (*)())FUN_000e0794)(param_1,0x25);
  ((int (*)())FUN_000e0794)(param_1,0x26);
  ((int (*)())FUN_000e0794)(param_1,0x27);
  ((int (*)())FUN_000e0794)(param_1,0x28);
  ((int (*)())FUN_000e0794)(param_1,0x29);
  ((int (*)())FUN_000e07b8)(param_1,0x2a);
  ((int (*)())FUN_000e07b8)(param_1,0x2b);
  ((int (*)())FUN_000e07b8)(param_1,0x2c);
  ((int (*)())FUN_000e0794)(param_1,0x2e);
  ((int (*)())FUN_000e0794)(param_1,0x2f);
  ((int (*)())FUN_000e07b8)(param_1,0x4e);
  ((int (*)())FUN_000e07b8)(param_1,0x4f);
  ((int (*)())FUN_000e0794)(param_1,0x30);
  ((int (*)())FUN_000e0794)(param_1,0x31);
  ((int (*)())FUN_000e0794)(param_1,0x32);
  ((int (*)())FUN_000e0794)(param_1,0x33);
  ((int (*)())FUN_000e07b8)(param_1,0x34);
  ((int (*)())FUN_000e0794)(param_1,0x35);
  ((int (*)())FUN_000e07b8)(param_1,0x36);
  ((int (*)())FUN_000e07b8)(param_1,0x37);
  ((int (*)())FUN_000e0794)(param_1,0x38);
  ((int (*)())FUN_000e0794)(param_1,0x39);
  ((int (*)())FUN_000e0794)(param_1,0x3a);
  ((int (*)())FUN_000e0794)(param_1,0x3b);
  ((int (*)())FUN_000e0794)(param_1,0x3c);
  ((int (*)())FUN_000e0794)(param_1,0x3d);
  ((int (*)())FUN_000e07b8)(param_1,0x3e);
  ((int (*)())FUN_000e0794)(param_1,0x3f);
  ((int (*)())FUN_000e07b8)(param_1,0x40);
  ((int (*)())FUN_000e0794)(param_1,0x41);
  ((int (*)())FUN_000e0794)(param_1,0x42);
  ((int (*)())FUN_000e0794)(param_1,0x43);
  ((int (*)())FUN_000e07b8)(param_1,0x44);
  ((int (*)())FUN_000e0794)(param_1,0x45);
  ((int (*)())FUN_000e07b8)(param_1,0x46);
  ((int (*)())FUN_000e0794)(param_1,0x47);
  ((int (*)())FUN_000e0794)(param_1,0x48);
  ((int (*)())FUN_000e0794)(param_1,0x49);
  ((int (*)())FUN_000e0794)(param_1,0x4a);
  ((int (*)())FUN_000e0794)(param_1,0x4b);
  ((int (*)())FUN_000e07b8)(param_1,0x4c);
  ((int (*)())FUN_000e0794)(param_1,0x4d);
  *(undefined4 *)(param_1 + 0x64c) = 2;
  *(undefined4 *)(param_1 + 0x6b4) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x67c) = 100;
  *(undefined4 *)(param_1 + 0x6ac) = 4;
  *(undefined4 *)(param_1 + 0x650) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x654) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x658) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x65c) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x660) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x664) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x668) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x670) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x66c) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x674) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x678) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x680) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x684) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x688) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x68c) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x690) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x694) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x698) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x69c) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x6a0) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x6a4) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x6a8) = 0x7fffffff;
  *(undefined4 *)(param_1 + 0x6b0) = 0x7fffffff;
  return;
}

/* FUN_000e0ca8 @ 0xe0ca8 (28 bytes) */
int FUN_000e0ca8(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x318) = 0;
  *(undefined4 *)(param_1 + 0x478) = 0x400;
  *(undefined4 *)(param_1 + 0x47c) = 0;
  *(undefined4 *)(param_1 + 0x480) = 0;
  return;
}

/* FUN_000e0cc8 @ 0xe0cc8 (8 bytes) */
int FUN_000e0cc8(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  return param_2 >> 0x18 & 1;
}

/* FUN_000e0cd0 @ 0xe0cd0 (308 bytes) */
int FUN_000e0cd0(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = ((int (*)())FUN_000e0cc8)(param_1,param_2);
  if (iVar1 != 0) {
    ((int (*)())FUN_000e07b8)(param_1,9);
    ((int (*)())FUN_000e07b8)(param_1,0x14);
    ((int (*)())FUN_000e07b8)(param_1,0x1c);
    ((int (*)())FUN_000e07b8)(param_1,0x1d);
    ((int (*)())FUN_000e07b8)(param_1,0x39);
    ((int (*)())FUN_000e07b8)(param_1,0x3b);
    ((int (*)())FUN_000e07b8)(param_1,0x42);
    ((int (*)())FUN_000e07b8)(param_1,0x27);
  }
  if ((param_2 & 0x100000) != 0) {
    ((int (*)())FUN_000e0794)(param_1,0x2a);
  }
  if ((param_2 & 0x200000) != 0) {
    ((int (*)())FUN_000e0794)(param_1,0x2b);
  }
  if ((param_2 & 0x200) != 0) {
    ((int (*)())FUN_000e07b8)(param_1,0x3f);
  }
  if ((param_2 & 0x800) != 0) {
    ((int (*)())FUN_000e07b8)(param_1,0x37);
  }
  if ((param_2 & 0x1000) != 0) {
    ((int (*)())FUN_000e0794)(param_1,0x3e);
  }
  if ((param_2 & 0x2000) != 0) {
    ((int (*)())FUN_000e0794)(param_1,0x4e);
  }
  if ((param_2 & 0x4000) != 0) {
    ((int (*)())FUN_000e0794)(param_1,0x4f);
    return;
  }
  return;
}

/* FUN_000e0e0c @ 0xe0e0c (28 bytes) */
int FUN_000e0e0c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  return;
}

/* FUN_000e0e28 @ 0xe0e28 (116 bytes) */
int FUN_000e0e28(param_1)
  int param_1;
{
  int iVar1;
  undefined1 auStack_b8 [128];
  undefined1 local_38;
  
  if (0 < *(int *)(param_1 + 0x3a4)) {
    iVar1 = 0;
    do {
      _memcpy(auStack_b8,iVar1 + *(int *)(param_1 + 0x3a0),0x80);
      iVar1 = iVar1 + 0x80;
      local_38 = 0;
    } while (iVar1 < *(int *)(param_1 + 0x3a4));
  }
  *(undefined4 *)(param_1 + 0x3a8) = 0;
  *(undefined4 *)(param_1 + 0x3a4) = 0;
  return;
}

/* FUN_000e0e9c @ 0xe0e9c (4 bytes) */
int FUN_000e0e9c()
{
  return;
}

/* FUN_000e0ea0 @ 0xe0ea0 (28 bytes) */
int FUN_000e0ea0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  return;
}

/* FUN_000e0ebc @ 0xe0ebc (44 bytes) */
int FUN_000e0ebc(param_1)
  int param_1;
{
  if ((((param_1 != 0x20) && (param_1 != 9)) && (param_1 != 10)) && (param_1 != 0xd)) {
    return 0;
  }
  return 1;
}

/* FUN_000e0ee8 @ 0xe0ee8 (1184 bytes) */
int FUN_000e0ee8(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined **ppuVar5;
  
  uVar2 = _strlen(param_2);
  ppuVar5 = &PTR_s_OPT_IGNORE_DEFINED_CONSTANTS_001dc444;
  iVar4 = 0;
  while (iVar3 = _strncmp(*ppuVar5,param_2,uVar2), iVar3 != 0) {
    bVar1 = iVar4 == 0x4f;
    ppuVar5 = ppuVar5 + 1;
    iVar4 = iVar4 + 1;
    if (bVar1) {
      iVar4 = _strncmp("opt_flatten_if_state",param_2,uVar2);
      if (iVar4 == 0) {
        *(int *)(param_1 + 0x64c) = param_3;
      }
      else {
        iVar4 = _strncmp("max_copy_folds",param_2,uVar2);
        if (iVar4 == 0) {
          *(int *)(param_1 + 0x650) = param_3;
        }
        else {
          iVar4 = _strncmp("max_vn_kills",param_2,uVar2);
          if (iVar4 == 0) {
            *(int *)(param_1 + 0x654) = param_3;
          }
          else {
            iVar4 = _strncmp("max_vn_transforms",param_2,uVar2);
            if (iVar4 == 0) {
              *(int *)(param_1 + 0x658) = param_3;
            }
            else {
              iVar4 = _strncmp("max_copy_merges",param_2,uVar2);
              if (iVar4 == 0) {
                *(int *)(param_1 + 0x65c) = param_3;
              }
              else {
                iVar4 = _strncmp("max_copy_props",param_2,uVar2);
                if (iVar4 == 0) {
                  *(int *)(param_1 + 0x660) = param_3;
                }
                else {
                  iVar4 = _strncmp("max_mix_insts",param_2,uVar2);
                  if (iVar4 == 0) {
                    *(int *)(param_1 + 0x664) = param_3;
                  }
                  else {
                    iVar4 = _strncmp("max_presubs",param_2,uVar2);
                    if (iVar4 == 0) {
                      *(int *)(param_1 + 0x668) = param_3;
                    }
                    else {
                      iVar4 = _strncmp("max_mov_and_shift",param_2,uVar2);
                      if (iVar4 == 0) {
                        *(int *)(param_1 + 0x670) = param_3;
                      }
                      else {
                        iVar4 = _strncmp("max_useless_phis",param_2,uVar2);
                        if (iVar4 == 0) {
                          *(int *)(param_1 + 0x66c) = param_3;
                        }
                        else {
                          iVar4 = _strncmp("max_balance_conversions",param_2,uVar2);
                          if (iVar4 == 0) {
                            *(int *)(param_1 + 0x674) = param_3;
                          }
                          else {
                            iVar4 = _strncmp("max_coalesce_loops",param_2,uVar2);
                            if (iVar4 == 0) {
                              *(int *)(param_1 + 0x678) = param_3;
                            }
                            else {
                              iVar4 = _strncmp("max_spill_loops",param_2,uVar2);
                              if (iVar4 == 0) {
                                *(int *)(param_1 + 0x67c) = param_3;
                              }
                              else {
                                iVar4 = _strncmp("max_inst_hoists",param_2,uVar2);
                                if (iVar4 == 0) {
                                  *(int *)(param_1 + 0x680) = param_3;
                                }
                                else {
                                  iVar4 = _strncmp("max_mad_mul_to_d2a",param_2,uVar2);
                                  if (iVar4 == 0) {
                                    *(int *)(param_1 + 0x684) = param_3;
                                  }
                                  else {
                                    iVar4 = _strncmp("max_mad_d2a_to_dp3",param_2,uVar2);
                                    if (iVar4 == 0) {
                                      *(int *)(param_1 + 0x688) = param_3;
                                    }
                                    else {
                                      iVar4 = _strncmp("max_add_add_to_dp3",param_2,uVar2);
                                      if (iVar4 == 0) {
                                        *(int *)(param_1 + 0x68c) = param_3;
                                      }
                                      else {
                                        iVar4 = _strncmp("max_add_mul_to_mad",param_2,uVar2);
                                        if (iVar4 == 0) {
                                          *(int *)(param_1 + 0x690) = param_3;
                                        }
                                        else {
                                          iVar4 = _strncmp("max_add_mad_mul_to_mov_mad_mad",param_2,
                                                           uVar2);
                                          if (iVar4 == 0) {
                                            *(int *)(param_1 + 0x694) = param_3;
                                          }
                                          else {
                                            iVar4 = _strncmp("max_reassociate",param_2,uVar2);
                                            if (iVar4 == 0) {
                                              *(int *)(param_1 + 0x698) = param_3;
                                            }
                                            else {
                                              iVar4 = _strncmp("max_reconst_alu",param_2,uVar2);
                                              if (iVar4 == 0) {
                                                *(int *)(param_1 + 0x69c) = param_3;
                                              }
                                              else {
                                                iVar4 = _strncmp("max_remove_cnd_input",param_2,
                                                                 uVar2);
                                                if (iVar4 == 0) {
                                                  *(int *)(param_1 + 0x6a0) = param_3;
                                                }
                                                else {
                                                  iVar4 = _strncmp("max_r600_minimize_cf_attempts",
                                                                   param_2,uVar2);
                                                  if (iVar4 == 0) {
                                                    *(int *)(param_1 + 0x6a4) = param_3;
                                                  }
                                                  else {
                                                    iVar4 = _strncmp("max_flatten_if",param_2,uVar2)
                                                    ;
                                                    if (iVar4 == 0) {
                                                      *(int *)(param_1 + 0x6a8) = param_3;
                                                    }
                                                    else {
                                                      iVar4 = _strncmp("rearrange_tree_depth",
                                                                       param_2,uVar2);
                                                      if (iVar4 == 0) {
                                                        *(int *)(param_1 + 0x6ac) = param_3;
                                                      }
                                                      else {
                                                        iVar4 = _strncmp("limit_registers",param_2,
                                                                         uVar2);
                                                        if (iVar4 == 0) {
                                                          *(int *)(param_1 + 0x6b0) = param_3;
                                                        }
                                                        else {
                                                          iVar4 = _strncmp("limit_instructions",
                                                                           param_2,uVar2);
                                                          if (iVar4 == 0) {
                                                            *(int *)(param_1 + 0x6b4) = param_3;
                                                          }
                                                        }
                                                      }
                                                    }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      return;
    }
  }
  if (param_3 != 0) {
    ((int (*)())FUN_000e0794)(param_1,iVar4);
    return;
  }
  ((int (*)())FUN_000e07b8)(param_1,iVar4);
  return;
}

/* FUN_000e1388 @ 0xe1388 (4 bytes) */
int FUN_000e1388()
{
  return;
}

/* FUN_000e138c @ 0xe138c (28 bytes) */
int FUN_000e138c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  return;
}

/* FUN_000e13a8 @ 0xe13a8 (12 bytes) */
int FUN_000e13a8(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x31c) = 1;
  return;
}

/* FUN_000e13b4 @ 0xe13b4 (152 bytes) */
int FUN_000e13b4(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x334) = 1;
  *(undefined4 *)(param_1 + 0x3c4) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x324) = 0;
  *(undefined4 *)(param_1 + 0x32c) = 0;
  *(undefined4 *)(param_1 + 0x330) = 0;
  *(undefined4 *)(param_1 + 0x338) = 0;
  *(undefined4 *)(param_1 + 0x33c) = 0;
  *(undefined4 *)(param_1 + 0x340) = 0;
  *(undefined4 *)(param_1 + 0x344) = 0;
  *(undefined4 *)(param_1 + 0x348) = 0;
  *(undefined4 *)(param_1 + 0x3ac) = 0;
  *(undefined4 *)(param_1 + 0x3b0) = 0;
  *(undefined4 *)(param_1 + 0x3b4) = 0;
  *(undefined4 *)(param_1 + 0x3b8) = 0;
  *(undefined4 *)(param_1 + 0x3bc) = 0;
  *(undefined4 *)(param_1 + 0x3c0) = 0;
  FUN_00172f0c(param_1);
  *(undefined4 *)(param_1 + 0x3d0) = 0;
  *(undefined4 *)(param_1 + 0x648) = 0;
  if (*(int *)(param_1 + 0x318) == 0) {
    *(undefined4 *)(param_1 + 0x6bc) = 0;
    *(undefined4 *)(param_1 + 0x39c) = 0;
    *(undefined4 *)(param_1 + 0x6b8) = 0;
  }
  return;
}

/* FUN_000e144c @ 0xe144c (24 bytes) */
int FUN_000e144c(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  *(undefined4 *)(param_1 + 0x594) = param_7;
  *(undefined4 *)(param_1 + 0x588) = param_2;
  *(undefined4 *)(param_1 + 0x58c) = param_4;
  *(undefined4 *)(param_1 + 0x590) = param_5;
  *(undefined4 *)(param_1 + 0x598) = param_6;
  return;
}

/* FUN_000e1464 @ 0xe1464 (28 bytes) */
int FUN_000e1464()
{
  return "timer.out";
}

/* FUN_000e1484 @ 0xe1484 (80 bytes) */
int FUN_000e1484(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 0x584) != 0) {
    (**(code **)(param_1 + 0x34c))(*(undefined4 *)(param_1 + 0x354));
    *(undefined4 *)(param_1 + 0x584) = 0;
  }
  return;
}

/* FUN_000e14d4 @ 0xe14d4 (16 bytes) */
int FUN_000e14d4(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  *(undefined4 *)(param_2 * 4 + param_1 + 0x534) = param_3;
  return;
}

/* FUN_000e14e4 @ 0xe14e4 (80 bytes) */
int FUN_000e14e4(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(**(int **)(param_1 + 0x30c) + 0x174))
                    (*(int **)(param_1 + 0x30c),param_2,param_3,param_1);
  *(undefined4 *)(param_3 * 4 + param_1 + 0x4d4) = uVar1;
  return;
}

/* FUN_000e1534 @ 0xe1534 (48 bytes) */
int FUN_000e1534(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 == 0) {
    *(undefined4 *)(param_1 + 0x314) = 1;
  }
  else {
    *(int *)(param_1 + 0x314) = param_2;
  }
                    
  _longjmp(*(undefined4 *)(param_1 + 4),1);
}

/* FUN_000e1564 @ 0xe1564 (84 bytes) */
int FUN_000e1564(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  iVar1 = (**(code **)(param_1 + 0x350))(*(undefined4 *)(param_1 + 0x354),param_2);
  if (iVar1 == 0) {
    ((int (*)())FUN_000e1534)(param_1,2);
  }
  return iVar1;
}

