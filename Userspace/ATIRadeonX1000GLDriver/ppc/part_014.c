#include "decls.h"

/* FUN_000db128 @ 0xdb128 (156 bytes) */
int FUN_000db128(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  char *param_3;
{
  int iVar1;
  
  iVar1 = 0;
  if (param_3 != (char *)0x0) {
    if (param_2 == 1) {
      iVar1 = (int)*param_3;
    }
    else {
      if (param_2 < 2) {
        if (param_2 == 0) {
          return 0x5f;
        }
      }
      else {
        if (param_2 == 2) {
          return 0x30;
        }
        if (param_2 == 3) {
          return 0x31;
        }
      }
      *param_1 = *param_1 + 1;
      FUN_000da904(param_1,"!!!invalidModComp!!!");
      iVar1 = 0x20;
    }
  }
  return iVar1;
}

/* FUN_000db1c4 @ 0xdb1c4 (304 bytes) */
int FUN_000db1c4(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  int param_3;
{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  char local_38 [36];
  
  if ((param_2 & 0xff) != 0x55) {
    bVar1 = param_3 != 0;
    if (bVar1) {
      pcVar2 = "r";
    }
    else {
      pcVar2 = "x";
    }
    local_38[0] = ((int (*)())FUN_000db128)(param_1,param_2 & 3,pcVar2);
    if (bVar1) {
      pcVar2 = "g";
    }
    else {
      pcVar2 = "y";
    }
    local_38[1] = ((int (*)())FUN_000db128)(param_1,param_2 >> 2 & 3,pcVar2);
    if (bVar1) {
      pcVar2 = "b";
    }
    else {
      pcVar2 = "z";
    }
    local_38[2] = ((int (*)())FUN_000db128)(param_1,param_2 >> 4 & 3,pcVar2);
    if (bVar1) {
      pcVar2 = "a";
    }
    else {
      pcVar2 = "w";
    }
    local_38[3] = ((int (*)())FUN_000db128)(param_1,param_2 >> 6 & 3,pcVar2);
    FUN_000da904(param_1,".");
    iVar3 = 0;
    do {
      FUN_000da904(param_1,"%c",(int)local_38[iVar3]);
      bVar1 = iVar3 != 3;
      iVar3 = iVar3 + 1;
    } while (bVar1);
  }
  return;
}

/* FUN_000db2f4 @ 0xdb2f4 (92 bytes) */
int FUN_000db2f4(param_1)
  int param_1;
{
  undefined4 uVar1;
  undefined1 auStack_58 [76];
  
  uVar1 = **(undefined4 **)(param_1 + 8);
  *(undefined4 **)(param_1 + 8) = *(undefined4 **)(param_1 + 8) + 1;
  FUN_001a32d0(auStack_58,"%lu",uVar1);
  FUN_000da904(param_1,auStack_58);
  return;
}

/* FUN_000db350 @ 0xdb350 (244 bytes) */
int FUN_000db350(param_1, param_2)
  int *param_1;
  uint param_2;
{
  FUN_000da904(param_1,"_cmpval(");
  switch(param_2 >> 0x16 & 7) {
  case 0:
    FUN_000da904(param_1,"0.0");
    break;
  case 1:
    FUN_000da904(param_1,"0.5");
    break;
  case 2:
    FUN_000da904(param_1,"1.0");
    break;
  case 3:
    FUN_000da904(param_1,"-0.5");
    break;
  case 4:
    FUN_000da904(param_1,"-1.0");
    break;
  default:
    *param_1 = *param_1 + 1;
    FUN_000da904(param_1,"!!!invalidCmpVal!!!");
  }
  FUN_000da904(param_1,")");
  return;
}

/* FUN_000db458 @ 0xdb458 (260 bytes) */
int FUN_000db458(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  FUN_000da904(param_1,"_usage(");
  switch(param_2) {
  case 0:
    FUN_000da904(param_1,"pos");
    break;
  case 1:
    FUN_000da904(param_1,"pointsize");
    break;
  case 2:
    FUN_000da904(param_1,"color");
    break;
  case 3:
    FUN_000da904(param_1,"backcolor");
    break;
  case 4:
    FUN_000da904(param_1,"fog");
    break;
  case 5:
    FUN_000da904(param_1,"generic");
    break;
  default:
    *param_1 = *param_1 + 1;
    FUN_000da904(param_1,"!!!invalid!!!");
  }
  FUN_000da904(param_1,")");
  return;
}

/* FUN_000db574 @ 0xdb574 (352 bytes) */
int FUN_000db574(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  uint param_2;
  uint param_3;
  uint param_4;
{
  float fVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_128 [256];
  undefined4 local_28;
  int iStack_24;
  undefined4 local_20;
  uint uStack_1c;
  undefined4 local_18;
  uint uStack_14;
  
  iStack_24 = 1 << (param_4 & 0x3f);
  local_28 = 0x43300000;
  uStack_1c = 0;
  if (1 < param_3) {
    iVar3 = param_3 - 1;
    uStack_1c = 0;
    if (iVar3 != 0) {
      uVar4 = 0;
      uStack_1c = 0;
      do {
        uVar2 = uVar4 & 0x3f;
        uVar4 = uVar4 + 1;
        uStack_1c = uStack_1c | 1 << uVar2;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      uStack_1c = uStack_1c << (param_4 & 0x3f);
    }
    uStack_1c = param_2 & uStack_1c;
  }
  local_20 = 0x43300000;
  uStack_1c = uStack_1c >> (param_4 & 0x3f);
  fVar1 = (float)((double)CONCAT44(0x43300000,uStack_1c) - DOUBLE_001aa250);
  if ((param_2 & 1 << ((param_4 + param_3) - 1 & 0x3f)) != 0) {
    fVar1 = FLOAT_001aa114 - fVar1;
  }
  uStack_14 = 0;
  if (param_4 != 0) {
    uVar4 = 0;
    uStack_14 = 0;
    do {
      uVar2 = uVar4 & 0x3f;
      uVar4 = uVar4 + 1;
      uStack_14 = uStack_14 | 1 << uVar2;
      param_4 = param_4 - 1;
    } while (param_4 != 0);
    uStack_14 = uStack_14 & param_2;
  }
  local_18 = 0x43300000;
  ((char * (*)())FUN_000cdc3c)((double)((float)(DOUBLE_001aa200 /
                               ((double)CONCAT44(0x43300000,iStack_24) - DOUBLE_001aa250)) *
                        (float)((double)CONCAT44(0x43300000,uStack_14) - DOUBLE_001aa250) + fVar1),
               param_1,10,auStack_128);
  FUN_000da904(param_1,auStack_128);
  return;
}

/* FUN_000db6d4 @ 0xdb6d4 (196 bytes) */
int FUN_000db6d4(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  FUN_000da904(param_1,"_xoffset(");
  ((int (*)())FUN_000db574)(param_1,param_2 & 0xff,7,1);
  FUN_000da904(param_1,")");
  FUN_000da904(param_1,"_yoffset(");
  ((int (*)())FUN_000db574)(param_1,param_2 >> 8 & 0xff,7,1);
  FUN_000da904(param_1,")");
  FUN_000da904(param_1,"_zoffset(");
  ((int (*)())FUN_000db574)(param_1,param_2 >> 0x10 & 0xff,7,1);
  FUN_000da904(param_1,")");
  return;
}

/* FUN_000db798 @ 0xdb798 (132 bytes) */
int FUN_000db798(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  uint param_3;
{
  uint uVar1;
  undefined1 auStack_118 [268];
  
  uVar1 = (1 << (param_3 & 0x3f)) - 1;
  param_2 = uVar1 & param_2;
  if ((param_2 & 1 << (param_3 - 1 & 0x3f)) != 0) {
    param_2 = (uVar1 & ~param_2) + 1;
    FUN_000da904(param_1,"-");
  }
  FUN_001a32d0(auStack_118,"%lu",param_2);
  FUN_000da904(param_1,auStack_118);
  return;
}

/* FUN_000db81c @ 0xdb81c (196 bytes) */
int FUN_000db81c(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  
  if ((param_2 & 0x20000000) != 0) {
    FUN_000da904(param_1,"_aoffimmi(");
    uVar1 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    ((int (*)())FUN_000db798)(param_1,uVar1 & 0xf,4);
    FUN_000da904(param_1,",");
    ((int (*)())FUN_000db798)(param_1,uVar1 >> 4 & 0xf,4);
    FUN_000da904(param_1,",");
    ((int (*)())FUN_000db798)(param_1,uVar1 >> 8 & 0xf,4);
    FUN_000da904(param_1,")");
    return;
  }
  return;
}

/* FUN_000db8e0 @ 0xdb8e0 (88 bytes) */
int FUN_000db8e0(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  undefined1 auStack_118 [268];
  
  FUN_001a32d0(auStack_118,"_resource(%d)_sampler(%d)",param_2 >> 0x10 & 0xff,param_2 >> 0x18 & 0x1f
              );
  FUN_000da904(param_1,auStack_118);
  return;
}

/* FUN_000db938 @ 0xdb938 (280 bytes) */
int FUN_000db938(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  FUN_000da904(param_1,"_aniso(");
  switch(param_2) {
  case 0:
    FUN_000da904(param_1,"unknown");
    break;
  case 1:
    FUN_000da904(param_1,"disabled");
    break;
  case 2:
    FUN_000da904(param_1,"1");
    break;
  case 3:
    FUN_000da904(param_1,"2");
    break;
  case 4:
    FUN_000da904(param_1,"4");
    break;
  case 5:
    FUN_000da904(param_1,"8");
    break;
  case 6:
    FUN_000da904(param_1,"16");
    break;
  default:
    *param_1 = *param_1 + 1;
    FUN_000da904(param_1,"!!invalid!!");
  }
  FUN_000da904(param_1,")");
  return;
}

/* FUN_000dba6c @ 0xdba6c (216 bytes) */
int FUN_000dba6c(param_1, param_2)
  int *param_1;
  int param_2;
{
  FUN_000da904(param_1,"_mip(");
  if (param_2 == 1) {
    FUN_000da904(param_1,"point");
  }
  else if (param_2 == 0) {
    FUN_000da904(param_1,"unknown");
  }
  else if (param_2 == 2) {
    FUN_000da904(param_1,"linear");
  }
  else if (param_2 == 3) {
    FUN_000da904(param_1,"base");
  }
  else {
    *param_1 = *param_1 + 1;
    FUN_000da904(param_1,"!!invalid!!");
  }
  FUN_000da904(param_1,")");
  return;
}

/* FUN_000dbb44 @ 0xdbb44 (124 bytes) */
int FUN_000dbb44(param_1, param_2)
  int *param_1;
  int param_2;
{
  if (param_2 == 1) {
    FUN_000da904(param_1,"point");
    return;
  }
  if (param_2 == 0) {
    FUN_000da904(param_1,"unknown");
    return;
  }
  if (param_2 == 2) {
    FUN_000da904(param_1,"linear");
    return;
  }
  if (param_2 == 3) {
    FUN_000da904(param_1,"aniso");
    return;
  }
  *param_1 = *param_1 + 1;
  FUN_000da904(param_1,"!!invalid!!");
  return;
}

/* FUN_000dbbc0 @ 0xdbbc0 (284 bytes) */
int FUN_000dbbc0(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  FUN_000da904(param_1,"_mag(");
  ((int (*)())FUN_000dbb44)(param_1,param_2 & 7);
  FUN_000da904(param_1,")");
  FUN_000da904(param_1,"_min(");
  ((int (*)())FUN_000dbb44)(param_1,param_2 >> 3 & 7);
  FUN_000da904(param_1,")");
  FUN_000da904(param_1,"_volmag(");
  ((int (*)())FUN_000dbb44)(param_1,param_2 >> 6 & 7);
  FUN_000da904(param_1,")");
  FUN_000da904(param_1,"_volmin(");
  ((int (*)())FUN_000dbb44)(param_1,param_2 >> 9 & 7);
  FUN_000da904(param_1,")");
  ((int (*)())FUN_000dba6c)(param_1,param_2 >> 0xc & 7);
  ((int (*)())FUN_000db938)(param_1,param_2 >> 0xf & 7);
  FUN_000da904(param_1,"_lodbias(");
  ((int (*)())FUN_000db574)(param_1,param_2 >> 0x12 & 0x7f,3,4);
  FUN_000da904(param_1,")");
  return;
}

/* FUN_000dbcdc @ 0xdbcdc (192 bytes) */
int FUN_000dbcdc(param_1, param_2)
  int *param_1;
  uint param_2;
{
  uint uVar1;
  
  uVar1 = param_2 >> 0x1a & 3;
  FUN_000da904(param_1,"_shadowmode(");
  if (uVar1 == 1) {
    FUN_000da904(param_1,"z");
  }
  else if (uVar1 == 0) {
    FUN_000da904(param_1,"never");
  }
  else if (uVar1 == 2) {
    FUN_000da904(param_1,"unknown");
  }
  else {
    *param_1 = *param_1 + 1;
    FUN_000da904(param_1,"!!invalid!!");
  }
  FUN_000da904(param_1,")");
  return;
}

/* FUN_000dbd9c @ 0xdbd9c (124 bytes) */
int FUN_000dbd9c(param_1, param_2)
  int *param_1;
  int param_2;
{
  if (param_2 == 1) {
    FUN_000da904(param_1,"0");
    return;
  }
  if (param_2 == 0) {
    FUN_000da904(param_1,"-");
    return;
  }
  if (param_2 == 2) {
    FUN_000da904(param_1,"1");
    return;
  }
  if (param_2 == 3) {
    FUN_000da904(param_1,"*");
    return;
  }
  *param_1 = *param_1 + 1;
  FUN_000da904(param_1,"!!!invalid!!!");
  return;
}

/* FUN_000dbe18 @ 0xdbe18 (284 bytes) */
int FUN_000dbe18(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  undefined1 auStack_38 [40];
  
  ((int (*)())FUN_000db458)(param_1,param_2 >> 0x10 & 0x1f);
  FUN_001a32d0(auStack_38,"_usageIndex(%d)",param_2 >> 0x15 & 0xff);
  FUN_000da904(param_1,auStack_38);
  if ((int)param_2 < 0) {
    uVar1 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    FUN_000da904(param_1,"_x(");
    ((int (*)())FUN_000dbd9c)(param_1,uVar1 & 3);
    FUN_000da904(param_1,")");
    FUN_000da904(param_1,"_y(");
    ((int (*)())FUN_000dbd9c)(param_1,uVar1 >> 2 & 3);
    FUN_000da904(param_1,")");
    FUN_000da904(param_1,"_z(");
    ((int (*)())FUN_000dbd9c)(param_1,uVar1 >> 4 & 3);
    FUN_000da904(param_1,")");
    FUN_000da904(param_1,"_w(");
    ((int (*)())FUN_000dbd9c)(param_1,uVar1 >> 6 & 3);
    FUN_000da904(param_1,")");
  }
  return;
}

/* FUN_000dbf34 @ 0xdbf34 (356 bytes) */
int FUN_000dbf34(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  undefined1 auStack_38 [40];
  
  ((int (*)())FUN_000db458)(param_1,param_2 >> 0x10 & 0x1f);
  FUN_001a32d0(auStack_38,"_usageIndex(%d)",param_2 >> 0x15 & 0xff);
  FUN_000da904(param_1,auStack_38);
  if ((int)param_2 < 0) {
    uVar1 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    FUN_000da904(param_1,"_x(");
    ((int (*)())FUN_000dbd9c)(param_1,uVar1 & 3);
    FUN_000da904(param_1,")");
    FUN_000da904(param_1,"_y(");
    ((int (*)())FUN_000dbd9c)(param_1,uVar1 >> 2 & 3);
    FUN_000da904(param_1,")");
    FUN_000da904(param_1,"_z(");
    ((int (*)())FUN_000dbd9c)(param_1,uVar1 >> 4 & 3);
    FUN_000da904(param_1,")");
    FUN_000da904(param_1,"_w(");
    ((int (*)())FUN_000dbd9c)(param_1,uVar1 >> 6 & 3);
    FUN_000da904(param_1,")");
    if ((uVar1 & 0x100) != 0) {
      FUN_000da904(param_1,"_centroid");
    }
    if ((uVar1 & 0x200) != 0) {
      FUN_000da904(param_1,"_constant");
    }
    if ((uVar1 & 0x400) != 0) {
      FUN_000da904(param_1,"_noperspective");
    }
  }
  return;
}

/* FUN_000dc098 @ 0xdc098 (276 bytes) */
int FUN_000dc098(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  undefined1 auStack_38 [40];
  
  FUN_001a32d0(auStack_38,"_elem(%d)",param_2 >> 0x10 & 0x3f);
  FUN_000da904(param_1,auStack_38);
  if ((int)param_2 < 0) {
    uVar1 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    FUN_000da904(param_1,"_x(");
    ((int (*)())FUN_000dbd9c)(param_1,uVar1 & 3);
    FUN_000da904(param_1,")");
    FUN_000da904(param_1,"_y(");
    ((int (*)())FUN_000dbd9c)(param_1,uVar1 >> 2 & 3);
    FUN_000da904(param_1,")");
    FUN_000da904(param_1,"_z(");
    ((int (*)())FUN_000dbd9c)(param_1,uVar1 >> 4 & 3);
    FUN_000da904(param_1,")");
    FUN_000da904(param_1,"_w(");
    ((int (*)())FUN_000dbd9c)(param_1,uVar1 >> 6 & 3);
    FUN_000da904(param_1,")");
  }
  return;
}

/* FUN_000dc1ac @ 0xdc1ac (280 bytes) */
int FUN_000dc1ac(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  FUN_000da904(param_1,"_x(");
  ((int (*)())FUN_000dbd9c)(param_1,param_2 >> 0x10 & 3);
  FUN_000da904(param_1,")");
  FUN_000da904(param_1,"_y(");
  ((int (*)())FUN_000dbd9c)(param_1,param_2 >> 0x12 & 3);
  FUN_000da904(param_1,")");
  FUN_000da904(param_1,"_z(");
  ((int (*)())FUN_000dbd9c)(param_1,param_2 >> 0x14 & 3);
  FUN_000da904(param_1,")");
  FUN_000da904(param_1,"_w(");
  ((int (*)())FUN_000dbd9c)(param_1,param_2 >> 0x16 & 3);
  FUN_000da904(param_1,")");
  if ((param_2 & 0x1000000) != 0) {
    FUN_000da904(param_1,"_center");
  }
  if ((param_2 & 0x2000000) != 0) {
    FUN_000da904(param_1,"_origin");
    return;
  }
  return;
}

/* FUN_000dc2c4 @ 0xdc2c4 (196 bytes) */
int FUN_000dc2c4(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  switch(param_2) {
  case 0:
    FUN_000da904(param_1,"_type(unknown)");
    return;
  case 1:
    FUN_000da904(param_1,"_type(1d)");
    return;
  case 2:
    FUN_000da904(param_1,"_type(2d)");
    return;
  case 3:
    FUN_000da904(param_1,"_type(3d)");
    return;
  case 4:
    FUN_000da904(param_1,"_type(cubemap)");
    return;
  case 5:
    FUN_000da904(param_1,"_type(2dmsaa)");
    return;
  case 6:
    FUN_000da904(param_1,"_type(4c)");
    return;
  case 7:
    FUN_000da904(param_1,"_type(buffer)");
    return;
  case 8:
    FUN_000da904(param_1,"_type(1darray)");
    return;
  case 9:
    FUN_000da904(param_1,"_type(2darray)");
    return;
  default:
    *param_1 = *param_1 + 1;
    FUN_000da904(param_1,"_type(!!!invalid!!!)");
    return;
  }
}

/* FUN_000dc3b0 @ 0xdc3b0 (164 bytes) */
int FUN_000dc3b0(param_1, param_2)
  int *param_1;
  uint param_2;
{
  char *pcVar1;
  uint uVar2;
  
  uVar2 = param_2 >> 0x1b & 3;
  ((int (*)())FUN_000dc2c4)(param_1,param_2 >> 0x18 & 7);
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
  FUN_000da904(param_1,pcVar1);
  return;
}

/* FUN_000dc454 @ 0xdc454 (104 bytes) */
int FUN_000dc454(param_1, param_2)
  int *param_1;
  int param_2;
{
  if (param_2 == 1) {
    FUN_000da904(param_1,"0");
    return;
  }
  if (param_2 != 0) {
    if (param_2 == 2) {
      FUN_000da904(param_1,"1");
      return;
    }
    *param_1 = *param_1 + 1;
    FUN_000da904(param_1,"!!!invalid!!!");
    return;
  }
  FUN_000da904(param_1,"*");
  return;
}

/* FUN_000dc4bc @ 0xdc4bc (192 bytes) */
int FUN_000dc4bc(param_1, param_2, param_3)
  undefined4 param_1;
  uint param_2;
  undefined4 param_3;
{
  uint uStack0000001c;
  undefined4 uStack00000020;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  FUN_000da904(param_1,"_x(");
  ((int (*)())FUN_000dc454)(param_1,uStack0000001c >> 8 & 3);
  FUN_000da904(param_1,")_y(");
  ((int (*)())FUN_000dc454)(param_1,uStack0000001c >> 10 & 3);
  FUN_000da904(param_1,")_z(");
  ((int (*)())FUN_000dc454)(param_1,uStack0000001c >> 0xc & 3);
  FUN_000da904(param_1,")_w(");
  ((int (*)())FUN_000dc454)(param_1,uStack0000001c >> 0xe & 3);
  FUN_000da904(param_1,")");
  return;
}

/* FUN_000dc57c @ 0xdc57c (220 bytes) */
int FUN_000dc57c(param_1, param_2)
  int *param_1;
  uint param_2;
{
  uint uVar1;
  
  uVar1 = param_2 >> 0x10 & 3;
  FUN_000da904(param_1,"_zeroop(");
  if (uVar1 == 1) {
    FUN_000da904(param_1,"zero");
  }
  else if (uVar1 == 0) {
    FUN_000da904(param_1,"fltmax");
  }
  else if (uVar1 == 2) {
    FUN_000da904(param_1,"infinity");
  }
  else if (uVar1 == 3) {
    FUN_000da904(param_1,"inf_else_max");
  }
  else {
    *param_1 = *param_1 + 1;
    FUN_000da904(param_1,"!!!invalid!!!");
  }
  FUN_000da904(param_1,")");
  return;
}

/* FUN_000dc658 @ 0xdc658 (196 bytes) */
int FUN_000dc658(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  uint uVar1;
  char local_38 [4];
  char local_34 [4];
  char local_30 [4];
  char local_2c [40];
  
  uVar1 = param_2 >> 0x10 & 0x3fff;
  if (uVar1 == 1) {
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__line_strip_001a82c4) + 0));
    *(unsigned int *)local_34 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__line_strip_001a82c4) + 4));
    *(unsigned int *)local_30 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__line_strip_001a82c4) + 8));
  }
  else if (uVar1 == 0) {
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__point_list_001a82b8) + 0));
    *(unsigned int *)local_34 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__point_list_001a82b8) + 4));
    *(unsigned int *)local_30 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__point_list_001a82b8) + 8));
  }
  else if (uVar1 == 2) {
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__triangle_strip_001a82d0) + 0));
    *(unsigned int *)local_34 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__triangle_strip_001a82d0) + 4));
    *(unsigned int *)local_30 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__triangle_strip_001a82d0) + 8));
    (*(unsigned int *)((unsigned char *)&(local_2c) + 0)) = (*(unsigned int *)((unsigned char *)&(s__triangle_strip_001a82d0) + 12));
  }
  FUN_000da904(param_1,local_38);
  return;
}

/* FUN_000dc71c @ 0xdc71c (268 bytes) */
int FUN_000dc71c(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  char local_38 [4];
  char local_34;
  char acStack_33 [3];
  char local_30 [4];
  char local_2c [40];
  
  switch(param_2 >> 0x10 & 0x3fff) {
  case 0:
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__point_001a82e0) + 0));
    (*(unsigned short *)((unsigned char *)&(acStack_33) + 0)) = (*(unsigned short *)((unsigned char *)&(s__point_001a82e0) + 5));
    local_34 = s__point_001a82e0[4];
    break;
  case 1:
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__line_001a82e8) + 0));
    local_34 = (*(unsigned short *)((unsigned char *)&(s__line_001a82e8) + 4));
    break;
  case 2:
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__triangle_001a82f0) + 0));
    local_34 = (*(unsigned int *)((unsigned char *)&(s__triangle_001a82f0) + 4));
    (*(unsigned short *)((unsigned char *)&(local_30) + 0)) = (*(unsigned short *)((unsigned char *)&(s__triangle_001a82f0) + 8));
    break;
  case 3:
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__line_adj_001a82fc) + 0));
    local_34 = (*(unsigned int *)((unsigned char *)&(s__line_adj_001a82fc) + 4));
    (*(unsigned short *)((unsigned char *)&(local_30) + 0)) = (*(unsigned short *)((unsigned char *)&(s__line_adj_001a82fc) + 8));
    break;
  case 4:
    *(unsigned int *)local_38 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__triangle_adj_001a8308) + 0));
    local_34 = (*(unsigned int *)((unsigned char *)&(s__triangle_adj_001a8308) + 4));
    *(unsigned int *)local_30 = (unsigned int)(*(unsigned int *)((unsigned char *)&(s__triangle_adj_001a8308) + 8));
    (*(unsigned short *)((unsigned char *)&(local_2c) + 0)) = (*(unsigned short *)((unsigned char *)&(s__triangle_adj_001a8308) + 12));
  }
  FUN_000da904(param_1,local_38);
  return;
}

/* FUN_000dc83c @ 0xdc83c (80 bytes) */
int FUN_000dc83c(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  undefined1 auStack_38 [44];
  
  FUN_001a32d0(auStack_38,"_stage(%d)",param_2 >> 0x10 & 0xff);
  FUN_000da904(param_1,auStack_38);
  return;
}

/* FUN_000dc88c @ 0xdc88c (324 bytes) */
int FUN_000dc88c(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  
  ((int (*)())FUN_000dc83c)();
  if ((int)param_2 < 0) {
    uVar1 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    FUN_000da904(param_1,"_mag(");
    ((int (*)())FUN_000dbb44)(param_1,uVar1 & 7);
    FUN_000da904(param_1,")");
    FUN_000da904(param_1,"_min(");
    ((int (*)())FUN_000dbb44)(param_1,uVar1 >> 3 & 7);
    FUN_000da904(param_1,")");
    ((int (*)())FUN_000db938)(param_1,uVar1 >> 0xf & 7);
  }
  if ((param_2 & 0x40000000) != 0) {
    uVar1 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    FUN_000da904(param_1,"_xoffset(");
    ((int (*)())FUN_000db574)(param_1,uVar1 & 0xff,7,1);
    FUN_000da904(param_1,")");
    FUN_000da904(param_1,"_yoffset(");
    ((int (*)())FUN_000db574)(param_1,uVar1 >> 8 & 0xff,7,1);
    FUN_000da904(param_1,")");
    return;
  }
  return;
}

/* FUN_000dc9d0 @ 0xdc9d0 (36 bytes) */
int FUN_000dc9d0(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  if ((param_2 & 0x10000) == 0) {
    return;
  }
  FUN_000da904(param_1,"_normalize");
  return;
}

/* FUN_000dc9f4 @ 0xdc9f4 (36 bytes) */
int FUN_000dc9f4(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  if ((param_2 & 0x10000) == 0) {
    return;
  }
  FUN_000da904(param_1,"_round");
  return;
}

/* FUN_000dca18 @ 0xdca18 (36 bytes) */
int FUN_000dca18(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  if ((param_2 & 0x1000000) == 0) {
    return;
  }
  FUN_000da904(param_1,"_sample");
  return;
}

/* FUN_000dca3c @ 0xdca3c (36 bytes) */
int FUN_000dca3c(param_1, param_2)
  undefined4 param_1;
  uint param_2;
{
  if ((param_2 & 0x1000000) == 0) {
    return;
  }
  FUN_000da904(param_1,"_centroid");
  return;
}

/* FUN_000dca60 @ 0xdca60 (212 bytes) */
int FUN_000dca60(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined4 uVar1;
  uint uVar2;
  
  ((int (*)())FUN_000dc83c)();
  ((int (*)())FUN_000dca3c)(param_1,param_2);
  if ((param_2 & 0x2000000) != 0) {
    FUN_000da904(param_1,"_absolute");
  }
  ((int (*)())FUN_000dbcdc)(param_1,param_2);
  if ((int)param_2 < 0) {
    uVar2 = **(uint **)(param_1 + 8);
    *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
    ((int (*)())FUN_000dbbc0)(param_1,uVar2);
    if ((uVar2 & 0x2000000) != 0) {
      FUN_000da904(param_1,"_qualitybias");
    }
  }
  if ((param_2 & 0x40000000) != 0) {
    uVar1 = **(undefined4 **)(param_1 + 8);
    *(undefined4 **)(param_1 + 8) = *(undefined4 **)(param_1 + 8) + 1;
    ((int (*)())FUN_000db6d4)(param_1,uVar1);
    return;
  }
  return;
}

/* FUN_000dcb34 @ 0xdcb34 (152 bytes) */
int FUN_000dcb34(param_1, param_2)
  int param_1;
  uint param_2;
{
  undefined4 uVar1;
  
  ((int (*)())FUN_000dc83c)();
  ((int (*)())FUN_000dca3c)(param_1,param_2);
  ((int (*)())FUN_000dbcdc)(param_1,param_2);
  if ((int)param_2 < 0) {
    uVar1 = **(undefined4 **)(param_1 + 8);
    *(undefined4 **)(param_1 + 8) = *(undefined4 **)(param_1 + 8) + 1;
    ((int (*)())FUN_000dbbc0)(param_1,uVar1);
  }
  if ((param_2 & 0x40000000) != 0) {
    uVar1 = **(undefined4 **)(param_1 + 8);
    *(undefined4 **)(param_1 + 8) = *(undefined4 **)(param_1 + 8) + 1;
    ((int (*)())FUN_000db6d4)(param_1,uVar1);
    return;
  }
  return;
}

/* FUN_000dcbcc @ 0xdcbcc (244 bytes) */
int FUN_000dcbcc(param_1, param_2)
  int *param_1;
  uint param_2;
{
  FUN_000da904(param_1,"_matrix(");
  switch(param_2 >> 0x10 & 7) {
  case 0:
    FUN_000da904(param_1,"4x4");
    break;
  case 1:
    FUN_000da904(param_1,"4x3");
    break;
  case 2:
    FUN_000da904(param_1,"3x4");
    break;
  case 3:
    FUN_000da904(param_1,"3x3");
    break;
  case 4:
    FUN_000da904(param_1,"3x2");
    break;
  default:
    *param_1 = *param_1 + 1;
    FUN_000da904(param_1,"!!!invalid!!!");
  }
  FUN_000da904(param_1,")");
  return;
}

/* FUN_000dccd4 @ 0xdccd4 (264 bytes) */
int FUN_000dccd4(param_1, param_2)
  int *param_1;
  uint param_2;
{
  FUN_000da904(param_1,"_relop(");
  switch(param_2 >> 0x10 & 7) {
  case 0:
    FUN_000da904(param_1,"ne");
    break;
  case 1:
    FUN_000da904(param_1,"eq");
    break;
  case 2:
    FUN_000da904(param_1,"ge");
    break;
  case 3:
    FUN_000da904(param_1,"gt");
    break;
  case 4:
    FUN_000da904(param_1,"le");
    break;
  case 5:
    FUN_000da904(param_1,"lt");
    break;
  default:
    *param_1 = *param_1 + 1;
    FUN_000da904(param_1,"!!!invalid!!!");
  }
  FUN_000da904(param_1,")");
  return;
}

/* FUN_000dcdf4 @ 0xdcdf4 (256 bytes) */
int FUN_000dcdf4(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  char local_128;
  char local_127 [15];
  undefined1 auStack_118 [268];
  
  uVar2 = **(uint **)(param_1 + 8);
  *(uint **)(param_1 + 8) = *(uint **)(param_1 + 8) + 1;
  uVar1 = uVar2 >> 0x10 & 0xff;
  if (uVar1 == 1) {
    local_128 = s_ps_001a8390[0];
    local_127[0] = s_ps_001a8390[1];
    local_127[1] = s_ps_001a8390[2];
  }
  else if (uVar1 == 0) {
    local_128 = s_vs_001a838c[0];
    local_127[0] = s_vs_001a838c[1];
    local_127[1] = s_vs_001a838c[2];
  }
  else if (uVar1 == 2) {
    local_128 = s_gs_001a8394[0];
    local_127[0] = s_gs_001a8394[1];
    local_127[1] = s_gs_001a8394[2];
  }
  FUN_001a32d0(auStack_118,"il_%s_%d_%d",&local_128,uVar2 >> 8 & 0xff,uVar2 & 0xff);
  *(uint *)(param_1 + 0x218) = (uint)(uVar1 == 1);
  FUN_000da904(param_1,auStack_118);
  FUN_000da984(param_1);
  return;
}

/* FUN_000dcef4 @ 0xdcef4 (640 bytes) */
int FUN_000dcef4(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  char *pcVar1;
  
  switch(param_2) {
  case 0:
    FUN_000da904(param_1,"b");
    return;
  case 1:
    FUN_000da904(param_1,"c");
    return;
  case 2:
    FUN_000da904(param_1,"i");
    return;
  case 3:
    FUN_000da904(param_1,"a");
    return;
  case 4:
    FUN_000da904(param_1,"r");
    return;
  case 5:
  case 0x1e:
    FUN_000da904(param_1,"v");
    return;
  case 6:
    FUN_000da904(param_1,"vIndex");
    return;
  default:
    pcVar1 = "!!!invalidRegType!!!";
    *param_1 = *param_1 + 1;
    break;
  case 8:
    FUN_000da904(param_1,"vBaryCoord");
    return;
  case 9:
    FUN_000da904(param_1,"vPrimIndex");
    return;
  case 10:
    FUN_000da904(param_1,"vQuadIndex");
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
    FUN_000da904(param_1,"oSprite");
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
    FUN_000da904(param_1,"vFace");
    return;
  case 0x16:
    FUN_000da904(param_1,"vWinCoord");
    return;
  case 0x17:
    FUN_000da904(param_1,"oC");
    return;
  case 0x18:
    FUN_000da904(param_1,"oDepth");
    return;
  case 0x19:
    FUN_000da904(param_1,"oClip");
    return;
  case 0x1b:
    FUN_000da904(param_1,"x");
    return;
  case 0x1c:
    FUN_000da904(param_1,"cb");
    return;
  case 0x1d:
    FUN_000da904(param_1,"l");
    return;
  case 0x1f:
    FUN_000da904(param_1,"o");
    return;
  case 0x20:
    FUN_000da904(param_1,"icb");
    return;
  }
  FUN_000da904(param_1,pcVar1);
  return;
}

/* FUN_000dd1f8 @ 0xdd1f8 (1220 bytes) */
int FUN_000dd1f8(param_1)
  int *param_1;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 uVar5;
  uint unaff_r23;
  uint uVar6;
  uint uVar7;
  uint unaff_r28;
  uint uVar8;
  uint uVar9;
  undefined1 auStack_b8 [64];
  undefined2 local_78 [36];
  
  puVar4 = (uint *)param_1[2];
  uVar9 = *puVar4;
  param_1[2] = (int)(puVar4 + 1);
  bVar1 = (uVar9 & 0x400000) == 0;
  if (!bVar1) {
    unaff_r28 = puVar4[1];
    param_1[2] = (int)(puVar4 + 2);
  }
  uVar7 = uVar9 & 0x1800000;
  if (uVar7 == 0x800000) {
    unaff_r23 = *(uint *)param_1[2];
    param_1[2] = (int)((uint *)param_1[2] + 1);
  }
  uVar6 = uVar9 >> 0x19 & 1;
  uVar3 = uVar9 & 0x2000000;
  if (uVar6 != 0xffffffff) {
    bVar2 = false;
    uVar8 = 0;
    do {
      ((int (*)())FUN_000dcef4)(param_1,uVar9 >> 0x10 & 0x3f);
      if (((undefined4 *)(uVar9 & 0x3f0000) == &DAT_001b0000) ||
         ((undefined4 *)(uVar9 & 0x3f0000) == (undefined4 *)0x1c0000)) {
        FUN_001a32d0(auStack_b8,"%d",uVar9 & 0xffff);
        bVar2 = true;
        FUN_000da904(param_1,auStack_b8);
      }
LAB_000dd324:
      if (uVar7 == 0) {
        if (bVar2) {
          uVar5 = 0;
          if ((uVar9 & 0x4000000) != 0) {
            uVar5 = *(undefined4 *)param_1[2];
            param_1[2] = (int)((undefined4 *)param_1[2] + 1);
          }
          FUN_001a32d0(auStack_b8,"[%lu]",uVar5);
          FUN_000da904(param_1,auStack_b8);
        }
        else {
          if (uVar3 == 0) {
            FUN_001a32d0(auStack_b8,"%d",uVar9 & 0xffff);
          }
          else {
            FUN_001a32d0(auStack_b8,"[%d]",uVar9 & 0xffff);
          }
          FUN_000da904(param_1,auStack_b8);
        }
      }
      else {
        if (uVar7 == 0x800000) {
          FUN_000da904(param_1,"[");
          if ((unaff_r23 & 0x10000) == 0) {
            FUN_001a32d0(auStack_b8,"a%d",unaff_r23 & 0xffff);
            FUN_000da904(param_1,auStack_b8);
            if ((unaff_r23 & 0xe0000) != 0) {
              uVar5 = FUN_000da8fc(param_1,uVar9);
              uVar5 = FUN_000dac4c(param_1,unaff_r23 >> 0x11 & 7,uVar5);
              FUN_001a32d0(auStack_b8,".%c",uVar5);
              FUN_000da904(param_1,auStack_b8);
            }
          }
          else {
            FUN_000da904(param_1,"al");
          }
          if (bVar2) {
            uVar5 = 0;
            if ((uVar9 & 0x4000000) != 0) {
              uVar5 = *(undefined4 *)param_1[2];
              param_1[2] = (int)((undefined4 *)param_1[2] + 1);
            }
LAB_000dd4f0:
            FUN_001a32d0(local_78,"+%lu",uVar5);
            FUN_000da904(param_1,local_78);
          }
          else if ((uVar9 & 0xffff) != 0) {
            FUN_001a32d0(auStack_b8,"+%d");
            FUN_000da904(param_1,auStack_b8);
          }
        }
        else {
          if (uVar7 != 0x1000000) goto LAB_000dd51c;
          local_78[0] = 0x5b00;
          FUN_000da904(param_1,local_78);
          ((int (*)())FUN_000dd1f8)(param_1);
          if ((uVar9 & 0x4000000) != 0) {
            uVar5 = *(undefined4 *)param_1[2];
            param_1[2] = (int)((undefined4 *)param_1[2] + 1);
            goto LAB_000dd4f0;
          }
        }
        FUN_000da904(param_1,"]");
      }
LAB_000dd51c:
      uVar8 = uVar8 + 1;
      if (uVar6 + 1 <= uVar8) goto LAB_000dd530;
    } while (uVar8 == 0);
    puVar4 = (uint *)param_1[2];
    uVar9 = *puVar4;
    param_1[2] = (int)(puVar4 + 1);
    if ((uVar9 & 0x400000) != 0) {
      unaff_r28 = puVar4[1];
      param_1[2] = (int)(puVar4 + 2);
    }
    uVar7 = uVar9 & 0x1800000;
    uVar6 = uVar9 >> 0x19 & 1;
    if (uVar7 == 0x800000) {
      unaff_r23 = *(uint *)param_1[2];
      param_1[2] = (int)((uint *)param_1[2] + 1);
    }
    goto LAB_000dd324;
  }
LAB_000dd530:
  if (bVar1) {
    return;
  }
  uVar5 = FUN_000da8fc(param_1,uVar9);
  FUN_000dad30(param_1,unaff_r28,uVar5);
  FUN_000daab0(param_1,unaff_r28,uVar5);
  if ((unaff_r28 & 0x10000) != 0) {
    FUN_000da904(param_1,"_invert");
  }
  if ((unaff_r28 & 0x80000) != 0) {
    FUN_000da904(param_1,"_sign");
  }
  if ((unaff_r28 & 0x100000) != 0) {
    FUN_000da904(param_1,"_abs");
  }
  if ((unaff_r28 & 0x20000) != 0) {
    FUN_000da904(param_1,"_bias");
  }
  if ((unaff_r28 & 0x40000) != 0) {
    FUN_000da904(param_1,"_x2");
  }
  if ((unaff_r28 & 0xe00000) == 0) {
    return;
  }
  FUN_000da904(param_1,"_divcomp(");
  uVar9 = unaff_r28 >> 0x15 & 7;
  if (uVar9 == 2) {
    FUN_000da904(param_1,"z");
    goto LAB_000dd630;
  }
  if (uVar9 < 3) {
    if (uVar9 == 1) {
      FUN_000da904(param_1,"y");
      goto LAB_000dd630;
    }
  }
  else {
    if (uVar9 == 3) {
      FUN_000da904(param_1,"w");
      goto LAB_000dd630;
    }
    if (uVar9 == 4) {
      FUN_000da904(param_1,"unknown");
      goto LAB_000dd630;
    }
  }
  FUN_000da904(param_1,"!!!invalid!!!");
  *param_1 = *param_1 + 1;
LAB_000dd630:
  FUN_000da904(param_1,")");
  return;
}

/* FUN_000dd6bc @ 0xdd6bc (988 bytes) */
int FUN_000dd6bc(param_1)
  int *param_1;
{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint *puVar6;
  undefined4 uVar7;
  int iVar8;
  uint unaff_r24;
  uint unaff_r25;
  uint uVar9;
  undefined1 auStack_b8 [64];
  undefined1 auStack_78 [84];
  
  puVar6 = (uint *)param_1[2];
  uVar9 = *puVar6;
  param_1[2] = (int)(puVar6 + 1);
  bVar1 = (uVar9 >> 0x16 & 1) == 0;
  if (!bVar1) {
    unaff_r25 = puVar6[1];
    param_1[2] = (int)(puVar6 + 2);
  }
  uVar3 = uVar9 & 0x1800000;
  if (uVar3 == 0x800000) {
    unaff_r24 = *(uint *)param_1[2];
    param_1[2] = (int)((uint *)param_1[2] + 1);
  }
  if (!bVar1) {
    FUN_000dae5c(param_1,unaff_r25);
  }
  FUN_000da904(param_1," ");
  uVar5 = FUN_000da8f4(param_1,uVar9);
  ((int (*)())FUN_000dcef4)(param_1,uVar9 >> 0x10 & 0x3f);
  if ((uVar9 & 0x23f0000) == 0x21e0000) {
    FUN_001a32d0(auStack_b8,"[%d]",uVar9 & 0xffff);
    FUN_000da904(param_1,auStack_b8);
    uVar9 = *(uint *)param_1[2];
    param_1[2] = (int)((uint *)param_1[2] + 1);
    FUN_001a32d0(auStack_b8,"[%d]",uVar9 & 0xffff);
    FUN_000da904(param_1,auStack_b8);
    bVar1 = (uVar9 & 0x400000) == 0;
  }
  else {
    puVar4 = (undefined4 *)(uVar9 & 0x3f0000);
    if (puVar4 == (undefined4 *)0x1f0000) {
      if ((uVar3 == 0x800000) || (bVar2 = false, uVar3 == 0x1000000)) {
        bVar2 = true;
      }
    }
    else if ((puVar4 == &DAT_001b0000) || (bVar2 = false, puVar4 == (undefined4 *)0x1c0000)) {
      FUN_001a32d0(auStack_b8,"%d",uVar9 & 0xffff);
      bVar2 = true;
      FUN_000da904(param_1,auStack_b8);
    }
    if (uVar3 == 0) {
      if (bVar2) {
        uVar7 = 0;
        if ((uVar9 & 0x4000000) != 0) {
          uVar7 = *(undefined4 *)param_1[2];
          param_1[2] = (int)((undefined4 *)param_1[2] + 1);
        }
        FUN_001a32d0(auStack_b8,"[%lu]",uVar7);
        FUN_000da904(param_1,auStack_b8);
      }
      else {
        FUN_001a32d0(auStack_b8,"%d",uVar9 & 0xffff);
        FUN_000da904(param_1,auStack_b8);
      }
    }
    else {
      if (uVar3 == 0x800000) {
        FUN_000da904(param_1,"[");
        if ((unaff_r24 & 0x10000) == 0) {
          FUN_001a32d0(auStack_b8,"a%d",unaff_r24 & 0xffff);
          FUN_000da904(param_1,auStack_b8);
          if ((unaff_r24 & 0xe0000) != 0) {
            uVar7 = FUN_000da8f4(param_1,uVar9);
            uVar7 = FUN_000dac4c(param_1,unaff_r24 >> 0x11 & 7,uVar7);
            FUN_001a32d0(auStack_b8,".%c",uVar7);
            FUN_000da904(param_1,auStack_b8);
          }
        }
        else {
          FUN_000da904(param_1,"al");
        }
        if (bVar2) {
          uVar7 = 0;
          if ((uVar9 & 0x4000000) != 0) {
            uVar7 = *(undefined4 *)param_1[2];
            param_1[2] = (int)((undefined4 *)param_1[2] + 1);
          }
          FUN_001a32d0(auStack_78,"+%lu",uVar7);
        }
        else if ((uVar9 & 0xffff) != 0) {
          FUN_001a32d0(auStack_b8,"+%d");
          FUN_000da904(param_1,auStack_b8);
        }
      }
      else {
        if (uVar3 != 0x1000000) goto joined_r0x000dda5c;
        if ((!bVar2) && (puVar4 != (undefined4 *)0x1f0000)) {
          FUN_000da904(param_1,
                       "Error! Field relative_address == IL_ADDR_REG_RELATIVE not supported for this reg type."
                      );
          *param_1 = *param_1 + 1;
          goto joined_r0x000dda5c;
        }
        FUN_000da904(param_1,"[");
        ((int (*)())FUN_000dd1f8)(param_1);
        if ((uVar9 & 0x4000000) != 0) {
          iVar8 = *(int *)param_1[2];
          param_1[2] = (int)((int *)param_1[2] + 1);
          if (puVar4 == (undefined4 *)0x1f0000) {
            iVar8 = iVar8 + (uVar9 & 0xffff);
          }
          FUN_001a32d0(auStack_78,"+%lu",iVar8);
          FUN_000da904(param_1,auStack_78);
        }
      }
      FUN_000da904(param_1,"]");
    }
  }
joined_r0x000dda5c:
  if (!bVar1) {
    ((int (*)())FUN_000db1c4)(param_1,unaff_r25,uVar5);
  }
  return;
}

/* FUN_000dda98 @ 0xdda98 (124 bytes) */
int FUN_000dda98(param_1)
  undefined4 param_1;
{
  ((int (*)())FUN_000dd6bc)();
  FUN_000da904(param_1,", ");
  ((int (*)())FUN_000dd1f8)(param_1);
  FUN_000da904(param_1,", ");
  ((int (*)())FUN_000dd1f8)(param_1);
  FUN_000da904(param_1,", ");
  ((int (*)())FUN_000dd1f8)(param_1);
  FUN_000da984(param_1);
  return;
}

/* FUN_000ddb14 @ 0xddb14 (104 bytes) */
int FUN_000ddb14(param_1)
  undefined4 param_1;
{
  ((int (*)())FUN_000dd6bc)();
  FUN_000da904(param_1,", ");
  ((int (*)())FUN_000dd1f8)(param_1);
  FUN_000da904(param_1,", ");
  ((int (*)())FUN_000dd1f8)(param_1);
  FUN_000da984(param_1);
  return;
}

/* FUN_000ddb7c @ 0xddb7c (80 bytes) */
int FUN_000ddb7c(param_1)
  undefined4 param_1;
{
  ((int (*)())FUN_000dd6bc)();
  FUN_000da904(param_1,", ");
  ((int (*)())FUN_000dd1f8)(param_1);
  FUN_000da984(param_1);
  return;
}

/* FUN_000ddbcc @ 0xddbcc (10080 bytes) */
int FUN_000ddbcc(param_1)
  int *param_1;
{
  char cVar1;
  undefined4 *puVar2;
  float *pfVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  uint *puVar12;
  float fVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint local_198;
  undefined4 local_194;
  char local_134;
  char local_133;
  char acStack_132 [266];
  undefined4 local_28;
  
  puVar12 = (uint *)param_1[2];
  uVar14 = *puVar12;
  param_1[2] = (int)(puVar12 + 1);
  switch(uVar14 & 0xffff) {
  default:
    *param_1 = *param_1 + 1;
    FUN_000da904(param_1,"!!!unknownOpcode!!!");
    local_28 = 1;
    break;
  case 1:
    FUN_000da9fc(param_1,param_1[0x87],"abs");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 2:
    FUN_000da9fc(param_1,param_1[0x87],"acos");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 3:
    FUN_000da9fc(param_1,param_1[0x87],"add");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 4:
    FUN_000da9fc(param_1,param_1[0x87],"asin");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 5:
    FUN_000da9fc(param_1,param_1[0x87],"atan");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 6:
    FUN_000da9fc(param_1,param_1[0x87],"break");
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 7:
    FUN_000da9fc(param_1,param_1[0x87],"breakc");
    ((int (*)())FUN_000dccd4)(param_1,uVar14);
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da904(param_1,", ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 8:
    FUN_000da9fc(param_1,param_1[0x87],"call");
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000db2f4)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 9:
    FUN_000da9fc(param_1,param_1[0x87],"callnz");
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da904(param_1,", ");
    ((int (*)())FUN_000db2f4)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 10:
    FUN_000da9fc(param_1,param_1[0x87],"clamp");
    ((int (*)())FUN_000dda98)(param_1);
    local_28 = 1;
    break;
  case 0xb:
    FUN_000da9fc(param_1,param_1[0x87],"clg");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0xc:
    FUN_000da9fc(param_1,param_1[0x87],"cmov");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0xd:
    FUN_000da9fc(param_1,param_1[0x87],"cmp");
    ((int (*)())FUN_000dccd4)(param_1,uVar14);
    ((int (*)())FUN_000db350)(param_1,uVar14);
    ((int (*)())FUN_000dda98)(param_1);
    local_28 = 1;
    break;
  case 0xe:
    FUN_000da9fc(param_1,param_1[0x87],"colorclamp");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0xf:
    uVar14 = puVar12[1];
    param_1[2] = (int)(puVar12 + 2);
    uVar14 = uVar14 & 0xffff;
    iVar15 = uVar14 * 4;
    FUN_000da9fc(param_1,param_1[0x87]," ); ");
    pcVar4 = (char *)param_1[2];
    iVar17 = 0;
    if (uVar14 != 0) {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      iVar17 = 1;
      if (cVar1 != '\0') {
        iVar16 = 1;
        do {
          FUN_000da904(param_1,"%c");
          iVar17 = iVar15;
          if (iVar16 == iVar15) break;
          cVar1 = *pcVar4;
          iVar16 = iVar16 + 1;
          pcVar4 = pcVar4 + 1;
          iVar17 = iVar16;
        } while (cVar1 != '\0');
      }
    }
    for (iVar15 = iVar15 - iVar17; iVar15 != 0; iVar15 = iVar15 + -1) {
      pcVar4 = pcVar4 + 1;
    }
    param_1[2] = (int)pcVar4;
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x10:
    FUN_000da9fc(param_1,param_1[0x87],"continue");
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x11:
    FUN_000da9fc(param_1,param_1[0x87],"continuec");
    ((int (*)())FUN_000dccd4)(param_1,uVar14);
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da904(param_1,", ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x12:
    FUN_000da9fc(param_1,param_1[0x87],"cos");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x13:
    FUN_000da9fc(param_1,param_1[0x87],"crs");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x14:
    FUN_000da9fc(param_1,param_1[0x87],"dclarray");
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da904(param_1,", ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x15:
    local_198 = uVar14;
    FUN_000da9fc(param_1,param_1[0x87],"dcldef");
    ((int (*)())FUN_000dc4bc)(param_1,local_198,local_194);
    ((int (*)())FUN_000dd6bc)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x16:
    FUN_000da9fc(param_1,param_1[0x87],"dclpi");
    ((int (*)())FUN_000dc1ac)(param_1,uVar14);
    ((int (*)())FUN_000dd6bc)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x17:
    FUN_000da9fc(param_1,param_1[0x87],"dclpin");
    ((int (*)())FUN_000dbf34)(param_1,uVar14);
    ((int (*)())FUN_000dd6bc)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x18:
    FUN_000da9fc(param_1,param_1[0x87],"dclpp");
    FUN_000da9fc(param_1,param_1[0x87],"dclv");
    FUN_001a32d0(&local_198,"_param(%d)",uVar14 >> 0x10 & 0xff);
    FUN_000da904(param_1,&local_198);
    ((int (*)())FUN_000dd6bc)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x19:
    FUN_000da9fc(param_1,param_1[0x87],"dclpt");
    ((int (*)())FUN_000dc3b0)(param_1,uVar14);
    ((int (*)())FUN_000dc83c)(param_1,uVar14);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x1a:
    FUN_000da9fc(param_1,param_1[0x87],"dclv");
    ((int (*)())FUN_000dc098)(param_1,uVar14);
    ((int (*)())FUN_000dd6bc)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x1b:
    FUN_000da9fc(param_1,param_1[0x87],"dclvout");
    ((int (*)())FUN_000dbe18)(param_1,uVar14);
    ((int (*)())FUN_000dd6bc)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x1c:
    FUN_000da9fc(param_1,param_1[0x87],"def");
    if ((*(uint *)param_1[2] & 0x3f0000) == 0x10000) {
      uVar5 = ((int (*)())FUN_000dd6bc)(param_1);
      pfVar3 = (float *)param_1[2];
      fVar9 = *pfVar3;
      param_1[2] = (int)(pfVar3 + 1);
      fVar13 = pfVar3[1];
      param_1[2] = (int)(pfVar3 + 2);
      fVar10 = pfVar3[2];
      param_1[2] = (int)(pfVar3 + 3);
      fVar11 = pfVar3[3];
      param_1[2] = (int)(pfVar3 + 4);
      local_134 = s___001a44f4[0];
      local_133 = s___001a44f4[1];
      acStack_132[0] = s___001a44f4[2];
      ((char * (*)())FUN_000cdc3c)((double)fVar9,uVar5,10,&local_198);
      iVar15 = FUN_001a32d0(acStack_132,"%s, ",&local_198);
      pcVar4 = acStack_132 + iVar15;
      ((char * (*)())FUN_000cdc3c)((double)fVar13,iVar15,10,&local_198);
      iVar15 = FUN_001a32d0(pcVar4,"%s, ",&local_198);
      ((char * (*)())FUN_000cdc3c)((double)fVar10,iVar15,10,&local_198);
      iVar17 = FUN_001a32d0(pcVar4 + iVar15,"%s, ",&local_198);
      ((char * (*)())FUN_000cdc3c)((double)fVar11,iVar17,10,&local_198);
      FUN_001a32d0(pcVar4 + iVar15 + iVar17,"%s",&local_198);
    }
    else {
      ((int (*)())FUN_000dd6bc)(param_1);
      puVar2 = (undefined4 *)param_1[2];
      uVar5 = *puVar2;
      param_1[2] = (int)(puVar2 + 1);
      uVar6 = puVar2[1];
      param_1[2] = (int)(puVar2 + 2);
      uVar7 = puVar2[2];
      param_1[2] = (int)(puVar2 + 3);
      uVar8 = puVar2[3];
      param_1[2] = (int)(puVar2 + 4);
      FUN_001a32d0(&local_134,", %lu, %lu, %lu, %lu",uVar5,uVar6,uVar7,uVar8);
    }
    FUN_000da904(param_1,&local_134);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x1d:
    FUN_000da9fc(param_1,param_1[0x87],"defb");
    ((int (*)())FUN_000dd6bc)(param_1);
    uVar5 = *(undefined4 *)param_1[2];
    param_1[2] = (int)((undefined4 *)param_1[2] + 1);
    FUN_001a32d0(&local_198,", %lu",uVar5);
    FUN_000da904(param_1,&local_198);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x1e:
    FUN_000da9fc(param_1,param_1[0x87],"det");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x1f:
    FUN_000da9fc(param_1,param_1[0x87],"dist");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x20:
    FUN_000da9fc(param_1,param_1[0x87],"div");
    ((int (*)())FUN_000dc57c)(param_1,uVar14);
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x21:
    FUN_000da9fc(param_1,param_1[0x87],"dp2add");
    ((int (*)())FUN_000dda98)(param_1);
    local_28 = 1;
    break;
  case 0x22:
    FUN_000da9fc(param_1,param_1[0x87],"dp3");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x23:
    FUN_000da9fc(param_1,param_1[0x87],"dp4");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x24:
    FUN_000da9fc(param_1,param_1[0x87],"dst");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x25:
    FUN_000da9fc(param_1,param_1[0x87],"dsx");
    ((int (*)())FUN_000dca3c)(param_1,uVar14);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x26:
    FUN_000da9fc(param_1,param_1[0x87],"dsy");
    ((int (*)())FUN_000dca3c)(param_1,uVar14);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x27:
    FUN_000da8e0(param_1,param_1[0x87] + -1);
    FUN_000da9fc(param_1,param_1[0x87],"else");
    FUN_000da8e0(param_1,param_1[0x87] + 1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x28:
    FUN_000da9fc(param_1,param_1[0x87],"end");
    FUN_000da984(param_1);
    local_28 = 0;
    break;
  case 0x29:
    FUN_000da8e0(param_1,param_1[0x87] + -1);
    FUN_000da9fc(param_1,param_1[0x87],"endif");
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x2a:
    FUN_000da8e0(param_1,param_1[0x87] + -1);
    FUN_000da9fc(param_1,param_1[0x87],"endloop");
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x2b:
    FUN_000da9fc(param_1,param_1[0x87],"endmain");
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x2c:
    FUN_000da9fc(param_1,param_1[0x87],"exn");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x2d:
    FUN_000da9fc(param_1,param_1[0x87],"exp");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x2e:
    FUN_000da9fc(param_1,param_1[0x87],"expp");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x2f:
    FUN_000da9fc(param_1,param_1[0x87],"faceforward");
    ((int (*)())FUN_000dda98)(param_1);
    local_28 = 1;
    break;
  case 0x30:
    FUN_000da9fc(param_1,param_1[0x87],"flr");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x31:
    FUN_000da9fc(param_1,param_1[0x87],"frc");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x32:
    FUN_000da9fc(param_1,param_1[0x87],"func");
    FUN_000da8e0(param_1,param_1[0x87] + 1);
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000db2f4)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x33:
    FUN_000da9fc(param_1,param_1[0x87],"fwidth");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x34:
    FUN_000da9fc(param_1,param_1[0x87],"ifc");
    FUN_000da8e0(param_1,param_1[0x87] + 1);
    ((int (*)())FUN_000dccd4)(param_1,uVar14);
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da904(param_1,", ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x35:
    FUN_000da9fc(param_1,param_1[0x87],"ifnz ");
    FUN_000da8e0(param_1,param_1[0x87] + 1);
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x36:
  case 0x43:
    FUN_000da9fc(param_1,param_1[0x87],"memimport");
    FUN_001a32d0(&local_198,"_elem(%d)",uVar14 >> 0x10 & 0x3f);
    FUN_000da904(param_1,&local_198);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x37:
    FUN_000da9fc(param_1,param_1[0x87],"kill");
    ((int (*)())FUN_000dc83c)(param_1,uVar14);
    ((int (*)())FUN_000dca18)(param_1,uVar14);
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x38:
    FUN_000da9fc(param_1,param_1[0x87],"len");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x39:
    FUN_000da9fc(param_1,param_1[0x87],"lit");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x3a:
    FUN_000da9fc(param_1,param_1[0x87],"ln");
    ((int (*)())FUN_000dc57c)(param_1,uVar14);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x3b:
    FUN_000da9fc(param_1,param_1[0x87],"lod");
    ((int (*)())FUN_000dc83c)(param_1,uVar14);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x3c:
    FUN_000da9fc(param_1,param_1[0x87],"log");
    ((int (*)())FUN_000dc57c)(param_1,uVar14);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x3d:
    FUN_000da9fc(param_1,param_1[0x87],"logp");
    ((int (*)())FUN_000dc57c)(param_1,uVar14);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x3e:
    FUN_000da9fc(param_1,param_1[0x87],"loop");
    if ((uVar14 & 0x10000) == 0) {
      pcVar4 = " ";
    }
    else {
      pcVar4 = "_rep ";
    }
    FUN_000da904(param_1,pcVar4);
    FUN_000da8e0(param_1,param_1[0x87] + 1);
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x3f:
    FUN_000da9fc(param_1,param_1[0x87],"lrp");
    ((int (*)())FUN_000dda98)(param_1);
    local_28 = 1;
    break;
  case 0x40:
    FUN_000da9fc(param_1,param_1[0x87],"mad");
    ((int (*)())FUN_000dda98)(param_1);
    local_28 = 1;
    break;
  case 0x41:
    FUN_000da9fc(param_1,param_1[0x87],"max");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x42:
    FUN_000da9fc(param_1,param_1[0x87],"memexport");
    FUN_001a32d0(&local_198,"_exportStream(%d)_stateStride(%d)_elemOffset(%d)",uVar14 >> 0x10 & 0x3f
                 ,uVar14 >> 0x16 & 1,uVar14 >> 0x17 & 0x3f);
    FUN_000da904(param_1,&local_198);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x44:
    FUN_000da9fc(param_1,param_1[0x87],"min");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x45:
    FUN_000da9fc(param_1,param_1[0x87],"mmul");
    ((int (*)())FUN_000dcbcc)(param_1,uVar14);
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x46:
    FUN_000da9fc(param_1,param_1[0x87],"mod");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x47:
    FUN_000da9fc(param_1,param_1[0x87],"mov");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x48:
    FUN_000da9fc(param_1,param_1[0x87],"mova");
    ((int (*)())FUN_000dc9f4)(param_1,uVar14);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x49:
    FUN_000da9fc(param_1,param_1[0x87],"mul");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x4a:
    FUN_000da9fc(param_1,param_1[0x87],"noise");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x4b:
    FUN_000da9fc(param_1,param_1[0x87],"nop");
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x4c:
    FUN_000da9fc(param_1,param_1[0x87],"nrm");
    if ((uVar14 & 0x40000) != 0) {
      FUN_000da904(param_1,"_nrm4");
    }
    ((int (*)())FUN_000dc57c)(param_1,uVar14);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x4d:
    FUN_000da9fc(param_1,param_1[0x87],"pireduce");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x4e:
    FUN_000da9fc(param_1,param_1[0x87],"pow");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x50:
    FUN_000da9fc(param_1,param_1[0x87],"project");
    ((int (*)())FUN_000dc83c)(param_1,uVar14);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x51:
    FUN_000da9fc(param_1,param_1[0x87],"rcp");
    ((int (*)())FUN_000dc57c)(param_1,uVar14);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x52:
    FUN_000da9fc(param_1,param_1[0x87],"reflect");
    ((int (*)())FUN_000dc9d0)(param_1,uVar14);
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x53:
    FUN_000da8e0(param_1,param_1[0x87] + -1);
    FUN_000da9fc(param_1,param_1[0x87],"ret");
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x54:
    FUN_000da9fc(param_1,param_1[0x87],"rnd");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x55:
    FUN_000da9fc(param_1,param_1[0x87],"rsq");
    ((int (*)())FUN_000dc57c)(param_1,uVar14);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x56:
    FUN_000da9fc(param_1,param_1[0x87],"set");
    ((int (*)())FUN_000dccd4)(param_1,uVar14);
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x57:
    FUN_000da9fc(param_1,param_1[0x87],"sgn");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x58:
    FUN_000da9fc(param_1,param_1[0x87],"sin");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x59:
    FUN_000da9fc(param_1,param_1[0x87],"sincos");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x5a:
    FUN_000da9fc(param_1,param_1[0x87],"sqrt");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x5b:
    FUN_000da9fc(param_1,param_1[0x87],"sub");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x5c:
    FUN_000da9fc(param_1,param_1[0x87],"tan");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x5d:
    FUN_000da9fc(param_1,param_1[0x87],"texld");
    ((int (*)())FUN_000dcb34)(param_1,uVar14);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x5e:
    FUN_000da9fc(param_1,param_1[0x87],"texldb");
    ((int (*)())FUN_000dca60)(param_1,uVar14);
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x5f:
    FUN_000da9fc(param_1,param_1[0x87],"texldd");
    ((int (*)())FUN_000dcb34)(param_1,uVar14);
    ((int (*)())FUN_000dda98)(param_1);
    local_28 = 1;
    break;
  case 0x60:
    FUN_000da9fc(param_1,param_1[0x87],"texldms");
    ((int (*)())FUN_000dc88c)(param_1,uVar14);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x61:
    FUN_000da9fc(param_1,param_1[0x87],"texweight");
    ((int (*)())FUN_000dc83c)(param_1,uVar14);
    ((int (*)())FUN_000dca3c)(param_1,uVar14);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x62:
    FUN_000da9fc(param_1,param_1[0x87],"transpose");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 99:
    FUN_000da9fc(param_1,param_1[0x87],"trc");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 100:
    FUN_000da9fc(param_1,param_1[0x87],"dxsincos");
    ((int (*)())FUN_000dda98)(param_1);
    local_28 = 1;
    break;
  case 0x65:
    FUN_000da9fc(param_1,param_1[0x87],"break_logicalz");
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x66:
    FUN_000da9fc(param_1,param_1[0x87],"break_logicalnz");
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x67:
    FUN_000da9fc(param_1,param_1[0x87],"call_logicalz");
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da904(param_1,", ");
    ((int (*)())FUN_000db2f4)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x68:
    FUN_000da9fc(param_1,param_1[0x87],"call_logicalnz");
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da904(param_1,", ");
    ((int (*)())FUN_000db2f4)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x69:
    FUN_000da9fc(param_1,param_1[0x87],"case ");
    FUN_000da904(param_1," ");
    uVar5 = *(undefined4 *)param_1[2];
    param_1[2] = (int)((undefined4 *)param_1[2] + 1);
    FUN_001a32d0(&local_198,"%lu",uVar5);
    FUN_000da904(param_1,&local_198);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x6a:
    FUN_000da9fc(param_1,param_1[0x87],"continue_logicalz");
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x6b:
    FUN_000da9fc(param_1,param_1[0x87],"continue_logicalnz");
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x6c:
    FUN_000da9fc(param_1,param_1[0x87],"default");
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x6d:
    FUN_000da9fc(param_1,param_1[0x87],"endswitch");
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x6e:
    FUN_000da9fc(param_1,param_1[0x87],"endfunc");
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x6f:
    FUN_000da9fc(param_1,param_1[0x87],"if_logicalz ");
    FUN_000da8e0(param_1,param_1[0x87] + 1);
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x70:
    FUN_000da9fc(param_1,param_1[0x87],"if_logicalnz ");
    FUN_000da8e0(param_1,param_1[0x87] + 1);
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x71:
    FUN_000da9fc(param_1,param_1[0x87],"whileloop");
    FUN_000da984(param_1);
    FUN_000da8e0(param_1,param_1[0x87] + 1);
    local_28 = 1;
    break;
  case 0x72:
    FUN_000da9fc(param_1,param_1[0x87],"switch");
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x73:
    FUN_000da9fc(param_1,param_1[0x87],"ret_dyn");
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x74:
    FUN_000da9fc(param_1,param_1[0x87],"ret_logicalz ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x75:
    FUN_000da9fc(param_1,param_1[0x87],"ret_logicalnz ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x76:
    if ((int)uVar14 < 0) {
      FUN_000da9fc(param_1,param_1[0x87],"dcl_immed_cb");
      iVar15 = *(int *)param_1[2];
      param_1[2] = (int)((int *)param_1[2] + 1);
      FUN_001a32d0(&local_198,"count = %d ",iVar15);
      FUN_000da904(param_1,&local_198);
      FUN_000da984(param_1);
      if (0 < iVar15) {
        iVar17 = 0;
        do {
          iVar17 = iVar17 + 1;
          uVar5 = *(undefined4 *)param_1[2];
          param_1[2] = (int)((undefined4 *)param_1[2] + 1);
          FUN_001a32d0(&local_198," 0x%x ",uVar5);
          FUN_000da9fc(param_1,param_1[0x87] + 1,&local_198);
          FUN_000da984(param_1);
        } while (iVar15 != iVar17);
      }
      local_28 = 1;
    }
    else {
      FUN_000da9fc(param_1,param_1[0x87],"dcl_cb");
      FUN_000da904(param_1," ");
      ((int (*)())FUN_000dd1f8)(param_1);
      FUN_000da984(param_1);
      local_28 = 1;
    }
    break;
  case 0x77:
    FUN_000da9fc(param_1,param_1[0x87],"dcl_indexed_temp_array");
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x78:
    FUN_000da9fc(param_1,param_1[0x87],"dcl_input_primitive");
    ((int (*)())FUN_000dc71c)(param_1,uVar14);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x79:
    FUN_000da9fc(param_1,param_1[0x87],"dcl_literal");
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da904(param_1,",");
    puVar2 = (undefined4 *)param_1[2];
    uVar5 = *puVar2;
    param_1[2] = (int)(puVar2 + 1);
    uVar6 = puVar2[1];
    param_1[2] = (int)(puVar2 + 2);
    uVar7 = puVar2[2];
    param_1[2] = (int)(puVar2 + 3);
    uVar8 = puVar2[3];
    param_1[2] = (int)(puVar2 + 4);
    FUN_001a32d0(&local_134," 0x%08lX, 0x%08lX, 0x%08lX, 0x%08lX",uVar5,uVar6,uVar7,uVar8);
    FUN_000da904(param_1,&local_134);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x7a:
    FUN_000da9fc(param_1,param_1[0x87],"dcl_max_output_vertex_count");
    FUN_001a32d0(&local_198,"(%d)",uVar14 >> 0x10 & 0x3fff);
    FUN_000da904(param_1,&local_198);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x7b:
    FUN_000da9fc(param_1,param_1[0x87],"dcl_odepth");
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x7c:
    FUN_000da9fc(param_1,param_1[0x87],"dcl_output_topology");
    ((int (*)())FUN_000dc658)(param_1,uVar14);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x7d:
    FUN_000da9fc(param_1,param_1[0x87],"dcl_output");
    uVar14 = uVar14 >> 0x10 & 0x3fff;
    if (uVar14 < 0x13) {
      FUN_000da904(param_1,(PTR_s__position_001dc3f4)[uVar14]);
    }
    ((int (*)())FUN_000dd6bc)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x7e:
    FUN_000da9fc(param_1,param_1[0x87],"dcl_input");
    if ((uVar14 & 0x7c000) != 0x14000) {
      FUN_000da904(param_1,*(undefined4 *)((int)PTR_s__position_001dc3f4 + (uVar14 >> 0xc & 0x7c)))
      ;
    }
    switch(uVar14 >> 0x13 & 7) {
    case 0:
      break;
    case 1:
      FUN_000da904(param_1,"_interp(constant)");
      break;
    case 2:
      FUN_000da904(param_1,"_interp(linear)");
      break;
    case 3:
      FUN_000da904(param_1,"_interp(linear_centroid)");
      break;
    case 4:
      FUN_000da904(param_1,"_interp(linear_noperspective)");
      break;
    case 5:
      FUN_000da904(param_1,"_interp(linear_noperspective_centroid)");
      break;
    default:
      FUN_000da904(param_1,"!!!bad interp mode!!!");
      *param_1 = *param_1 + 1;
    }
    ((int (*)())FUN_000dd6bc)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x7f:
    FUN_000da9fc(param_1,param_1[0x87],"dcl_vprim");
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x80:
    FUN_000da9fc(param_1,param_1[0x87],"dcl_resource");
    FUN_001a32d0(&local_134,"_id(%d)",uVar14 >> 0x10 & 0xff);
    FUN_000da904(param_1,&local_134);
    ((int (*)())FUN_000dc2c4)(param_1,uVar14 >> 0x18 & 0xf);
    FUN_000db048(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x81:
    FUN_000da9fc(param_1,param_1[0x87],"cut");
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x82:
    FUN_000da9fc(param_1,param_1[0x87],"discard_logicalz");
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x83:
    FUN_000da9fc(param_1,param_1[0x87],"discard_logicalnz");
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x84:
    FUN_000da9fc(param_1,param_1[0x87],"emit");
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x85:
    FUN_000da9fc(param_1,param_1[0x87],"emitcut");
    FUN_000da984(param_1);
    local_28 = 1;
    break;
  case 0x86:
    FUN_000da9fc(param_1,param_1[0x87],"load");
    FUN_001a32d0(&local_134,"_id(%d)",uVar14 >> 0x10 & 0x1fff);
    FUN_000da904(param_1,&local_134);
    ((int (*)())FUN_000db81c)(param_1,uVar14);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x87:
    FUN_000da9fc(param_1,param_1[0x87],"resinfo");
    FUN_001a32d0(&local_134,"_id(%d)",uVar14 >> 0x10 & 0xfff);
    FUN_000da904(param_1,&local_134);
    if ((uVar14 & 0x10000000) != 0) {
      FUN_000da904(param_1,"_uint");
    }
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x88:
    FUN_000da9fc(param_1,param_1[0x87],"sample");
    ((int (*)())FUN_000db8e0)(param_1,uVar14);
    ((int (*)())FUN_000db81c)(param_1,uVar14);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x89:
    FUN_000da9fc(param_1,param_1[0x87],"sample_b");
    ((int (*)())FUN_000db8e0)(param_1,uVar14);
    ((int (*)())FUN_000db81c)(param_1,uVar14);
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x8a:
    FUN_000da9fc(param_1,param_1[0x87],"sample_g");
    ((int (*)())FUN_000db8e0)(param_1,uVar14);
    ((int (*)())FUN_000db81c)(param_1,uVar14);
    ((int (*)())FUN_000dda98)(param_1);
    local_28 = 1;
    break;
  case 0x8b:
    FUN_000da9fc(param_1,param_1[0x87],"sample_l");
    ((int (*)())FUN_000db8e0)(param_1,uVar14);
    ((int (*)())FUN_000db81c)(param_1,uVar14);
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x8c:
    FUN_000da9fc(param_1,param_1[0x87],"sample_c");
    ((int (*)())FUN_000db8e0)(param_1,uVar14);
    ((int (*)())FUN_000db81c)(param_1,uVar14);
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x8d:
    FUN_000da9fc(param_1,param_1[0x87],"sample_c_lz");
    ((int (*)())FUN_000db8e0)(param_1,uVar14);
    ((int (*)())FUN_000db81c)(param_1,uVar14);
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x8e:
    FUN_000da9fc(param_1,param_1[0x87],"inot");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x8f:
    FUN_000da9fc(param_1,param_1[0x87],"ior");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x90:
    FUN_000da9fc(param_1,param_1[0x87],"ixor");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x91:
    FUN_000da9fc(param_1,param_1[0x87],"iadd");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x92:
    FUN_000da9fc(param_1,param_1[0x87],"imad");
    ((int (*)())FUN_000dda98)(param_1);
    local_28 = 1;
    break;
  case 0x93:
    FUN_000da9fc(param_1,param_1[0x87],"imax");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x94:
    FUN_000da9fc(param_1,param_1[0x87],"imin");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x95:
    FUN_000da9fc(param_1,param_1[0x87],"imul");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x96:
    FUN_000da9fc(param_1,param_1[0x87],"imul_high");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x97:
    FUN_000da9fc(param_1,param_1[0x87],"ieq");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x98:
    FUN_000da9fc(param_1,param_1[0x87],"ige");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x99:
    FUN_000da9fc(param_1,param_1[0x87],"ilt");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x9a:
    FUN_000da9fc(param_1,param_1[0x87],"inegate");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0x9b:
    FUN_000da9fc(param_1,param_1[0x87],"ine");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x9c:
    FUN_000da9fc(param_1,param_1[0x87],"ishl");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x9d:
    FUN_000da9fc(param_1,param_1[0x87],"ishr");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x9e:
    FUN_000da9fc(param_1,param_1[0x87],"ushr");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0x9f:
    FUN_000da9fc(param_1,param_1[0x87],"udiv");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0xa0:
    FUN_000da9fc(param_1,param_1[0x87],"umod");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0xa1:
    FUN_000da9fc(param_1,param_1[0x87],"umad");
    ((int (*)())FUN_000dda98)(param_1);
    local_28 = 1;
    break;
  case 0xa2:
    FUN_000da9fc(param_1,param_1[0x87],"umax");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0xa3:
    FUN_000da9fc(param_1,param_1[0x87],"umin");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0xa4:
    FUN_000da9fc(param_1,param_1[0x87],"ult");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0xa5:
    FUN_000da9fc(param_1,param_1[0x87],"uge");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0xa6:
    FUN_000da9fc(param_1,param_1[0x87],"umul");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0xa7:
    FUN_000da9fc(param_1,param_1[0x87],"umul_high");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0xa8:
    FUN_000da9fc(param_1,param_1[0x87],"ftoi");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0xa9:
    FUN_000da9fc(param_1,param_1[0x87],"ftou");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0xaa:
    FUN_000da9fc(param_1,param_1[0x87],"itof");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0xab:
    FUN_000da9fc(param_1,param_1[0x87],"utof");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0xac:
    FUN_000da9fc(param_1,param_1[0x87],"and");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0xad:
    FUN_000da9fc(param_1,param_1[0x87],"cmov_logical");
    ((int (*)())FUN_000dda98)(param_1);
    local_28 = 1;
    break;
  case 0xae:
    FUN_000da9fc(param_1,param_1[0x87],"eq");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0xaf:
    FUN_000da9fc(param_1,param_1[0x87],"exp_vec");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0xb0:
    FUN_000da9fc(param_1,param_1[0x87],"ge");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0xb1:
    FUN_000da9fc(param_1,param_1[0x87],"log_vec");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0xb2:
    FUN_000da9fc(param_1,param_1[0x87],"lt");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0xb3:
    FUN_000da9fc(param_1,param_1[0x87],"ne");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0xb4:
    FUN_000da9fc(param_1,param_1[0x87],"round_nearest");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0xb5:
    FUN_000da9fc(param_1,param_1[0x87],"round_neginf");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0xb6:
    FUN_000da9fc(param_1,param_1[0x87],"round_plusinf");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0xb7:
    FUN_000da9fc(param_1,param_1[0x87],"round_zero");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0xb8:
    FUN_000da9fc(param_1,param_1[0x87],"rsq_vec");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0xb9:
    FUN_000da9fc(param_1,param_1[0x87],"sin_vec");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0xba:
    FUN_000da9fc(param_1,param_1[0x87],"cos_vec");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0xbb:
    FUN_000da9fc(param_1,param_1[0x87],"sqrt_vec");
    ((int (*)())FUN_000ddb7c)(param_1);
    local_28 = 1;
    break;
  case 0xbc:
    FUN_000da9fc(param_1,param_1[0x87],"dp2");
    ((int (*)())FUN_000ddb14)(param_1);
    local_28 = 1;
    break;
  case 0xbe:
    FUN_000da9fc(param_1,param_1[0x87],"scatter");
    if ((uVar14 & 0x3fff0000) != 0) {
      FUN_000da904(param_1,"_quad");
    }
    FUN_000da904(param_1," ");
    ((int (*)())FUN_000dd1f8)(param_1);
    FUN_000da984(param_1);
    local_28 = 1;
  }
  return local_28;
}

/* FUN_000e0640 @ 0xe0640 (84 bytes) */
int FUN_000e0640(param_1)
  int param_1;
{
  int iVar1;
  
  do {
    if ((uint)(*(int *)(param_1 + 0xc) * 4 + *(int *)(param_1 + 4)) <= *(uint *)(param_1 + 8)) {
      return;
    }
    iVar1 = ((int (*)())FUN_000ddbcc)(param_1);
  } while (iVar1 != 0);
  return;
}

/* FUN_000e0694 @ 0xe0694 (68 bytes) */
int FUN_000e0694(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_2;
  FUN_000da8d0();
  ((int (*)())FUN_000dcdf4)(param_1);
  ((int (*)())FUN_000e0640)(param_1);
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
int FUN_000e0740(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  *(undefined4 *)(param_1 + 0xc) = param_3;
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_2;
  _memset((void *)(param_1 + 0x10),0,0x200);
  *(undefined4 *)(param_1 + 0x218) = 0;
  ((int (*)())FUN_000e0640)(param_1);
  return;
}

/* FUN_000e0794 @ 0xe0794 (36 bytes) */
int FUN_000e0794(param_1, param_2)
  int param_1;
  uint param_2;
{
  param_1 = ((int)param_2 >> 3) + param_1;
  *(byte *)(param_1 + 0x59c) = (byte)(1 << (param_2 & 7)) | *(byte *)(param_1 + 0x59c);
  return;
}

/* FUN_000e07b8 @ 0xe07b8 (36 bytes) */
int FUN_000e07b8(param_1, param_2)
  int param_1;
  uint param_2;
{
  param_1 = ((int)param_2 >> 3) + param_1;
  *(byte *)(param_1 + 0x59c) =
       ((byte)(-2 << (param_2 & 7)) | (byte)(0xfffffffe >> 0x20 - (param_2 & 7))) &
       *(byte *)(param_1 + 0x59c);
  return;
}

/* FUN_000e07dc @ 0xe07dc (84 bytes) */
int FUN_000e07dc(param_1, param_2)
  int param_1;
  uint param_2;
{
  int iVar1;
  
  if ((((int)*(char *)(((int)param_2 >> 3) + param_1 + 0x59c) >> (param_2 & 7) & 1U) != 0) &&
     (iVar1 = FUN_0010dc9c(*(undefined4 *)(param_1 + 0x30c)), iVar1 != 0)) {
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
  
  iVar1 = ((int (*)())FUN_000e0cc8)();
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
int FUN_000e0e0c()
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
      _memcpy(auStack_b8,(void *)(iVar1 + *(int *)(param_1 + 0x3a0)),0x80);
      iVar1 = iVar1 + 0x80;
      local_38 = 0;
    } while (iVar1 < *(int *)(param_1 + 0x3a4));
  }
  *(undefined4 *)(param_1 + 0x3a8) = 0;
  *(undefined4 *)(param_1 + 0x3a4) = 0;
  return;
}

/* FUN_000e0ee8 @ 0xe0ee8 (1184 bytes) */
int FUN_000e0ee8(param_1, param_2, param_3)
  int param_1;
  char *param_2;
  int param_3;
{
  bool bVar1;
  size_t sVar2;
  int iVar3;
  int iVar4;
  undefined **ppuVar5;
  
  sVar2 = _strlen(param_2);
  ppuVar5 = &PTR_s_OPT_IGNORE_DEFINED_CONSTANTS_001dc444;
  iVar4 = 0;
  while (iVar3 = _strncmp(*ppuVar5,param_2,sVar2), iVar3 != 0) {
    bVar1 = iVar4 == 0x4f;
    ppuVar5 = ppuVar5 + 1;
    iVar4 = iVar4 + 1;
    if (bVar1) {
      iVar4 = _strncmp("opt_flatten_if_state",param_2,sVar2);
      if (iVar4 == 0) {
        *(int *)(param_1 + 0x64c) = param_3;
      }
      else {
        iVar4 = _strncmp("max_copy_folds",param_2,sVar2);
        if (iVar4 == 0) {
          *(int *)(param_1 + 0x650) = param_3;
        }
        else {
          iVar4 = _strncmp("max_vn_kills",param_2,sVar2);
          if (iVar4 == 0) {
            *(int *)(param_1 + 0x654) = param_3;
          }
          else {
            iVar4 = _strncmp("max_vn_transforms",param_2,sVar2);
            if (iVar4 == 0) {
              *(int *)(param_1 + 0x658) = param_3;
            }
            else {
              iVar4 = _strncmp("max_copy_merges",param_2,sVar2);
              if (iVar4 == 0) {
                *(int *)(param_1 + 0x65c) = param_3;
              }
              else {
                iVar4 = _strncmp("max_copy_props",param_2,sVar2);
                if (iVar4 == 0) {
                  *(int *)(param_1 + 0x660) = param_3;
                }
                else {
                  iVar4 = _strncmp("max_mix_insts",param_2,sVar2);
                  if (iVar4 == 0) {
                    *(int *)(param_1 + 0x664) = param_3;
                  }
                  else {
                    iVar4 = _strncmp("max_presubs",param_2,sVar2);
                    if (iVar4 == 0) {
                      *(int *)(param_1 + 0x668) = param_3;
                    }
                    else {
                      iVar4 = _strncmp("max_mov_and_shift",param_2,sVar2);
                      if (iVar4 == 0) {
                        *(int *)(param_1 + 0x670) = param_3;
                      }
                      else {
                        iVar4 = _strncmp("max_useless_phis",param_2,sVar2);
                        if (iVar4 == 0) {
                          *(int *)(param_1 + 0x66c) = param_3;
                        }
                        else {
                          iVar4 = _strncmp("max_balance_conversions",param_2,sVar2);
                          if (iVar4 == 0) {
                            *(int *)(param_1 + 0x674) = param_3;
                          }
                          else {
                            iVar4 = _strncmp("max_coalesce_loops",param_2,sVar2);
                            if (iVar4 == 0) {
                              *(int *)(param_1 + 0x678) = param_3;
                            }
                            else {
                              iVar4 = _strncmp("max_spill_loops",param_2,sVar2);
                              if (iVar4 == 0) {
                                *(int *)(param_1 + 0x67c) = param_3;
                              }
                              else {
                                iVar4 = _strncmp("max_inst_hoists",param_2,sVar2);
                                if (iVar4 == 0) {
                                  *(int *)(param_1 + 0x680) = param_3;
                                }
                                else {
                                  iVar4 = _strncmp("max_mad_mul_to_d2a",param_2,sVar2);
                                  if (iVar4 == 0) {
                                    *(int *)(param_1 + 0x684) = param_3;
                                  }
                                  else {
                                    iVar4 = _strncmp("max_mad_d2a_to_dp3",param_2,sVar2);
                                    if (iVar4 == 0) {
                                      *(int *)(param_1 + 0x688) = param_3;
                                    }
                                    else {
                                      iVar4 = _strncmp("max_add_add_to_dp3",param_2,sVar2);
                                      if (iVar4 == 0) {
                                        *(int *)(param_1 + 0x68c) = param_3;
                                      }
                                      else {
                                        iVar4 = _strncmp("max_add_mul_to_mad",param_2,sVar2);
                                        if (iVar4 == 0) {
                                          *(int *)(param_1 + 0x690) = param_3;
                                        }
                                        else {
                                          iVar4 = _strncmp("max_add_mad_mul_to_mov_mad_mad",param_2,
                                                           sVar2);
                                          if (iVar4 == 0) {
                                            *(int *)(param_1 + 0x694) = param_3;
                                          }
                                          else {
                                            iVar4 = _strncmp("max_reassociate",param_2,sVar2);
                                            if (iVar4 == 0) {
                                              *(int *)(param_1 + 0x698) = param_3;
                                            }
                                            else {
                                              iVar4 = _strncmp("max_reconst_alu",param_2,sVar2);
                                              if (iVar4 == 0) {
                                                *(int *)(param_1 + 0x69c) = param_3;
                                              }
                                              else {
                                                iVar4 = _strncmp("max_remove_cnd_input",param_2,
                                                                 sVar2);
                                                if (iVar4 == 0) {
                                                  *(int *)(param_1 + 0x6a0) = param_3;
                                                }
                                                else {
                                                  iVar4 = _strncmp("max_r600_minimize_cf_attempts",
                                                                   param_2,sVar2);
                                                  if (iVar4 == 0) {
                                                    *(int *)(param_1 + 0x6a4) = param_3;
                                                  }
                                                  else {
                                                    iVar4 = _strncmp("max_flatten_if",param_2,sVar2)
                                                    ;
                                                    if (iVar4 == 0) {
                                                      *(int *)(param_1 + 0x6a8) = param_3;
                                                    }
                                                    else {
                                                      iVar4 = _strncmp("rearrange_tree_depth",
                                                                       param_2,sVar2);
                                                      if (iVar4 == 0) {
                                                        *(int *)(param_1 + 0x6ac) = param_3;
                                                      }
                                                      else {
                                                        iVar4 = _strncmp("limit_registers",param_2,
                                                                         sVar2);
                                                        if (iVar4 == 0) {
                                                          *(int *)(param_1 + 0x6b0) = param_3;
                                                        }
                                                        else {
                                                          iVar4 = _strncmp("limit_instructions",
                                                                           param_2,sVar2);
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

