#include "decls.h"

/* _glMapVertexAttrib2fARB_Comp @ 0x7192c (520 bytes) */
void _glMapVertexAttrib2fARB_Comp(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,int param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,int param_11,undefined4 param_12,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 *puVar1;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_f9;
  double in_f10;
  double in_f11;
  double in_f12;
  double in_f13;
  
  if (param_3 == 2) {
    iVar2 = (100 - param_7 * param_11) * -8 + 0x344;
    uVar3 = param_6;
    iVar4 = param_7;
    puVar1 = (undefined4 *)
             _gleAddListItem(param_1,PTR__glMap2VertexAttrib2ARB_ListExec_0011019c,iVar2);
    if (puVar1 == (undefined4 *)0x0) goto LAB_00071b28;
    ((void (*)())_gleMap2VertexAttrib2fLoad)(param_1,extraout_r4_00,iVar2,param_6,param_7,uVar3,iVar4,param_10,param_11,param_12,
               puVar1 + 1,fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,
               in_f11,in_f12,in_f13);
  }
  else if (param_3 < 3) {
    if (param_3 != 1) {
LAB_00071b14:
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x501;
      }
      goto LAB_00071b28;
    }
    iVar2 = (100 - param_7 * param_11) * -4 + 0x1b4;
    uVar3 = param_6;
    iVar4 = param_7;
    puVar1 = (undefined4 *)
             _gleAddListItem(param_1,PTR__glMap2VertexAttrib1ARB_ListExec_001101a0,iVar2);
    if (puVar1 == (undefined4 *)0x0) goto LAB_00071b28;
    ((void (*)())_gleMap2VertexAttrib1fLoad)(param_1,extraout_r4,iVar2,param_6,param_7,uVar3,iVar4,param_10,param_11,param_12,
               puVar1 + 1,fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,
               in_f11,in_f12,in_f13);
  }
  else if (param_3 == 3) {
    iVar2 = (100 - param_7 * param_11) * -0xc + 0x4d4;
    uVar3 = param_6;
    iVar4 = param_7;
    puVar1 = (undefined4 *)
             _gleAddListItem(param_1,PTR__glMap2VertexAttrib3ARB_ListExec_00110198,iVar2);
    if (puVar1 == (undefined4 *)0x0) goto LAB_00071b28;
    ((void (*)())_gleMap2VertexAttrib3fLoad)(param_1,extraout_r4_01,iVar2,param_6,param_7,uVar3,iVar4,param_10,param_11,param_12,
               puVar1 + 1,fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,
               in_f11,in_f12,in_f13);
  }
  else {
    if (param_3 != 4) goto LAB_00071b14;
    iVar2 = (100 - param_7 * param_11) * -0x10 + 0x664;
    uVar3 = param_6;
    iVar4 = param_7;
    puVar1 = (undefined4 *)
             _gleAddListItem(param_1,PTR__glMap2VertexAttrib4ARB_ListExec_00110194,iVar2);
    if (puVar1 == (undefined4 *)0x0) goto LAB_00071b28;
    ((void (*)())_gleMap2VertexAttrib4fLoad)(param_1,extraout_r4_02,iVar2,param_6,param_7,uVar3,iVar4,param_10,param_11,param_12,
               puVar1 + 1,fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,
               in_f11,in_f12,in_f13);
  }
  *puVar1 = param_2;
LAB_00071b28:
  FUN_00008b68();
  return;
}

/* _glMapVertexAttrib2fARB_Exec @ 0x71b34 (572 bytes) */
void _glMapVertexAttrib2fARB_Exec(int param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5,int param_6,int param_7,undefined4 param_8,undefined4 param_9,int param_10,int param_11,undefined4 param_12,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_r4;
  uint uVar3;
  int iVar4;
  int iVar5;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_f9;
  double in_f10;
  double in_f11;
  double in_f12;
  double in_f13;
  
  uVar3 = param_3;
  iVar4 = param_6;
  iVar5 = param_7;
  iVar2 = _gleGetMapData(param_1);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((((param_2 < 0x10) && (fparam_1 != fparam_2)) && (fparam_3 != fparam_4)) &&
       (((0 < param_7 && (param_7 < 0xb)) && ((0 < param_11 && (param_11 < 0xb)))))) {
      if (param_3 == 2) {
        if ((1 < param_6) && (1 < param_10)) {
          ((void (*)())_gleMap2VertexAttrib2fLoad)(param_1,extraout_r4,uVar3,param_6,param_7,iVar4,iVar5,param_10,param_11,
                     param_12,iVar2 + param_2 * 0x660 + 0x37a8,fparam_1,fparam_2,fparam_3,fparam_4,
                     in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13);
          goto LAB_00071d40;
        }
      }
      else if (param_3 < 3) {
        if (((param_3 == 1) && (0 < param_6)) && (0 < param_10)) {
          ((void (*)())_gleMap2VertexAttrib1fLoad)(param_1,extraout_r4,uVar3,param_6,param_7,iVar4,iVar5,param_10,param_11,
                     param_12,iVar2 + param_2 * 0x660 + 0x37a8,fparam_1,fparam_2,fparam_3,fparam_4,
                     in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13);
          goto LAB_00071d40;
        }
      }
      else if (param_3 == 3) {
        if ((2 < param_6) && (2 < param_10)) {
          ((void (*)())_gleMap2VertexAttrib3fLoad)(param_1,extraout_r4,uVar3,param_6,param_7,iVar4,iVar5,param_10,param_11,
                     param_12,iVar2 + param_2 * 0x660 + 0x37a8,fparam_1,fparam_2,fparam_3,fparam_4,
                     in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13);
          goto LAB_00071d40;
        }
      }
      else if (((param_3 == 4) && (3 < param_6)) && (3 < param_10)) {
        ((void (*)())_gleMap2VertexAttrib4fLoad)(param_1,extraout_r4,uVar3,param_6,param_7,iVar4,iVar5,param_10,param_11,param_12,
                   iVar2 + param_2 * 0x660 + 0x37a8,fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,
                   in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13);
LAB_00071d40:
        *(char *)(param_2 + iVar2 + 0x9db8) = (char)param_3;
        goto LAB_00071d64;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00071d64;
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00071d64;
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
LAB_00071d64:
  FUN_00008b68();
  return;
}

/* _glMapVertexAttrib2fARB_CompExec @ 0x71d70 (164 bytes) */
void _glMapVertexAttrib2fARB_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 in_stack_ffffff98;
  
  ((void (*)())_glMapVertexAttrib2fARB_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,in_stack_ffffff98,
             param_10,param_11,param_12,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glMapVertexAttrib2fARB_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
             param_11,param_12,fparam_1,fparam_2,fparam_3,fparam_4);
  return;
}

/* _glMapVertexAttrib2dARB_Comp @ 0x71e14 (520 bytes) */
void _glMapVertexAttrib2dARB_Comp(int param_1,undefined4 param_2,uint param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,int param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14,int param_15,undefined4 param_16,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 *puVar1;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  int iVar2;
  undefined4 uVar3;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_f9;
  double in_f10;
  double in_f11;
  double in_f12;
  double in_f13;
  undefined4 in_stack_ffffff88;
  undefined4 in_stack_ffffff8c;
  undefined4 in_stack_ffffff90;
  
  if (param_3 == 2) {
    iVar2 = (100 - param_9 * param_15) * -8 + 0x344;
    uVar3 = param_8;
    puVar1 = (undefined4 *)
             _gleAddListItem(param_1,PTR__glMap2VertexAttrib2ARB_ListExec_0011019c,iVar2);
    if (puVar1 == (undefined4 *)0x0) goto LAB_00072010;
    ((void (*)())_gleMap2VertexAttrib2dLoad)(param_1,extraout_r4_00,iVar2,param_4,param_5,param_8,param_9,uVar3,in_stack_ffffff88,
               in_stack_ffffff8c,in_stack_ffffff90,param_14,param_15,param_16,puVar1 + 1,fparam_1,
               fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13)
    ;
  }
  else if (param_3 < 3) {
    if (param_3 != 1) {
LAB_00071ffc:
      if (*(int *)(param_1 + 0x7574) == 0) {
        *(undefined4 *)(param_1 + 0x7574) = 0x501;
      }
      goto LAB_00072010;
    }
    iVar2 = (100 - param_9 * param_15) * -4 + 0x1b4;
    uVar3 = param_8;
    puVar1 = (undefined4 *)
             _gleAddListItem(param_1,PTR__glMap2VertexAttrib1ARB_ListExec_001101a0,iVar2);
    if (puVar1 == (undefined4 *)0x0) goto LAB_00072010;
    ((void (*)())_gleMap2VertexAttrib1dLoad)(param_1,extraout_r4,iVar2,param_4,param_5,param_8,param_9,uVar3,in_stack_ffffff88,
               in_stack_ffffff8c,in_stack_ffffff90,param_14,param_15,param_16,puVar1 + 1,fparam_1,
               fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13)
    ;
  }
  else if (param_3 == 3) {
    iVar2 = (100 - param_9 * param_15) * -0xc + 0x4d4;
    uVar3 = param_8;
    puVar1 = (undefined4 *)
             _gleAddListItem(param_1,PTR__glMap2VertexAttrib3ARB_ListExec_00110198,iVar2);
    if (puVar1 == (undefined4 *)0x0) goto LAB_00072010;
    ((void (*)())_gleMap2VertexAttrib3dLoad)(param_1,extraout_r4_01,iVar2,param_4,param_5,param_8,param_9,uVar3,in_stack_ffffff88,
               in_stack_ffffff8c,in_stack_ffffff90,param_14,param_15,param_16,puVar1 + 1,fparam_1,
               fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13)
    ;
  }
  else {
    if (param_3 != 4) goto LAB_00071ffc;
    iVar2 = (100 - param_9 * param_15) * -0x10 + 0x664;
    uVar3 = param_8;
    puVar1 = (undefined4 *)
             _gleAddListItem(param_1,PTR__glMap2VertexAttrib4ARB_ListExec_00110194,iVar2);
    if (puVar1 == (undefined4 *)0x0) goto LAB_00072010;
    ((void (*)())_gleMap2VertexAttrib4dLoad)(param_1,extraout_r4_02,iVar2,param_4,param_5,param_8,param_9,uVar3,in_stack_ffffff88,
               in_stack_ffffff8c,in_stack_ffffff90,param_14,param_15,param_16,puVar1 + 1,fparam_1,
               fparam_2,fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13)
    ;
  }
  *puVar1 = param_2;
LAB_00072010:
  FUN_00008b68();
  return;
}

/* _glMapVertexAttrib2dARB_Exec @ 0x7201c (572 bytes) */
void _glMapVertexAttrib2dARB_Exec(int param_1,uint param_2,uint param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8,int param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,int param_14,int param_15,undefined4 param_16,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_r4;
  uint uVar3;
  int iVar4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_f9;
  double in_f10;
  double in_f11;
  double in_f12;
  double in_f13;
  undefined4 in_stack_ffffff88;
  undefined4 in_stack_ffffff8c;
  undefined4 in_stack_ffffff90;
  
  uVar3 = param_3;
  iVar4 = param_8;
  iVar2 = _gleGetMapData(param_1);
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((((param_2 < 0x10) && (fparam_1 != fparam_2)) && (fparam_3 != fparam_4)) &&
       (((0 < param_9 && (param_9 < 0xb)) && ((0 < param_15 && (param_15 < 0xb)))))) {
      if (param_3 == 2) {
        if ((1 < param_8) && (1 < param_14)) {
          ((void (*)())_gleMap2VertexAttrib2dLoad)(param_1,extraout_r4,uVar3,param_4,param_5,param_8,param_9,iVar4,
                     in_stack_ffffff88,in_stack_ffffff8c,in_stack_ffffff90,param_14,param_15,
                     param_16,iVar2 + param_2 * 0x660 + 0x37a8,fparam_1,fparam_2,fparam_3,fparam_4,
                     in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13);
          goto LAB_00072228;
        }
      }
      else if (param_3 < 3) {
        if (((param_3 == 1) && (0 < param_8)) && (0 < param_14)) {
          ((void (*)())_gleMap2VertexAttrib1dLoad)(param_1,extraout_r4,uVar3,param_4,param_5,param_8,param_9,iVar4,
                     in_stack_ffffff88,in_stack_ffffff8c,in_stack_ffffff90,param_14,param_15,
                     param_16,iVar2 + param_2 * 0x660 + 0x37a8,fparam_1,fparam_2,fparam_3,fparam_4,
                     in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13);
          goto LAB_00072228;
        }
      }
      else if (param_3 == 3) {
        if ((2 < param_8) && (2 < param_14)) {
          ((void (*)())_gleMap2VertexAttrib3dLoad)(param_1,extraout_r4,uVar3,param_4,param_5,param_8,param_9,iVar4,
                     in_stack_ffffff88,in_stack_ffffff8c,in_stack_ffffff90,param_14,param_15,
                     param_16,iVar2 + param_2 * 0x660 + 0x37a8,fparam_1,fparam_2,fparam_3,fparam_4,
                     in_f5,in_f6,in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13);
          goto LAB_00072228;
        }
      }
      else if (((param_3 == 4) && (3 < param_8)) && (3 < param_14)) {
        ((void (*)())_gleMap2VertexAttrib4dLoad)(param_1,extraout_r4,uVar3,param_4,param_5,param_8,param_9,iVar4,in_stack_ffffff88
                   ,in_stack_ffffff8c,in_stack_ffffff90,param_14,param_15,param_16,
                   iVar2 + param_2 * 0x660 + 0x37a8,fparam_1,fparam_2,fparam_3,fparam_4,in_f5,in_f6,
                   in_f7,in_f8,in_f9,in_f10,in_f11,in_f12,in_f13);
LAB_00072228:
        *(char *)(param_2 + iVar2 + 0x9db8) = (char)param_3;
        goto LAB_0007224c;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_0007224c;
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_0007224c;
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
LAB_0007224c:
  FUN_00008b68();
  return;
}

/* _glMapVertexAttrib2dARB_CompExec @ 0x72258 (168 bytes) */
void _glMapVertexAttrib2dARB_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,undefined4 param_14,undefined4 param_15,undefined4 param_16,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  undefined4 in_stack_ffffff8c;
  undefined4 in_stack_ffffff90;
  undefined4 in_stack_ffffff94;
  undefined4 in_stack_ffffff98;
  
  ((void (*)())_glMapVertexAttrib2dARB_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,
             in_stack_ffffff8c,in_stack_ffffff90,in_stack_ffffff94,in_stack_ffffff98,param_14,
             param_15,param_16,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glMapVertexAttrib2dARB_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,
             param_11,param_12,param_13,param_14,param_15,param_16,fparam_1,fparam_2,fparam_3,
             fparam_4);
  return;
}

/* _glGetMapdv_Exec @ 0x72300 (3736 bytes) */
int _glGetMapdv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  uint param_3;
  double *param_4;
{
  float fVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  float *pfVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  double *pdVar10;
  int iVar11;
  uint uVar12;
  double dVar13;
  
  puVar7 = (uint *)_gleGetMapData(param_1);
  dVar13 = DOUBLE_00108d70;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    switch(param_2) {
    case 0xd90:
      if (param_3 == 0xa01) {
        uVar8 = puVar7[0x70];
LAB_00072910:
        *param_4 = (double)CONCAT44(0x43300000,uVar8) - DOUBLE_00108d70;
        return;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar8 = 0;
          puVar6 = puVar7;
          if (puVar7[0x70] == 0) {
            return;
          }
          do {
            uVar8 = uVar8 + 1;
            *param_4 = (double)GH_U2F((unsigned int)(puVar6[0x74]));
            param_4[1] = (double)GH_U2F((unsigned int)(puVar6[0x75]));
            param_4[2] = (double)GH_U2F((unsigned int)(puVar6[0x76]));
            param_4[3] = (double)GH_U2F((unsigned int)(puVar6[0x77]));
            param_4 = param_4 + 4;
            puVar6 = puVar6 + 4;
          } while (uVar8 < puVar7[0x70]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (double)GH_U2F((unsigned int)(puVar7[0x71]));
        dVar13 = (double)GH_U2F((unsigned int)(puVar7[0x72]));
LAB_00072928:
        param_4[1] = dVar13;
        return;
      }
      break;
    case 0xd91:
      if (param_3 == 0xa01) {
        uVar8 = puVar7[0x9c];
        goto LAB_00072910;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar8 = 0;
          if (puVar7[0x9c] == 0) {
            return;
          }
          pfVar5 = (float *)(puVar7 + 0xa0);
          do {
            fVar1 = *pfVar5;
            uVar8 = uVar8 + 1;
            pfVar5 = pfVar5 + 1;
            *param_4 = (double)fVar1;
            param_4 = param_4 + 1;
          } while (uVar8 < puVar7[0x9c]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (double)GH_U2F((unsigned int)(puVar7[0x9d]));
        dVar13 = (double)GH_U2F((unsigned int)(puVar7[0x9e]));
        goto LAB_00072928;
      }
      break;
    case 0xd92:
      if (param_3 == 0xa01) {
        uVar8 = puVar7[0x4e];
        goto LAB_00072910;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar8 = 0;
          puVar6 = puVar7;
          if (puVar7[0x4e] == 0) {
            return;
          }
          do {
            uVar8 = uVar8 + 1;
            *param_4 = (double)GH_U2F((unsigned int)(puVar6[0x52]));
            param_4[1] = (double)GH_U2F((unsigned int)(puVar6[0x53]));
            param_4[2] = (double)GH_U2F((unsigned int)(puVar6[0x54]));
            param_4 = param_4 + 3;
            puVar6 = puVar6 + 3;
          } while (uVar8 < puVar7[0x4e]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (double)GH_U2F((unsigned int)(puVar7[0x4f]));
        dVar13 = (double)GH_U2F((unsigned int)(puVar7[0x50]));
        goto LAB_00072928;
      }
      break;
    case 0xd93:
      if (param_3 == 0xa01) {
        uVar8 = puVar7[0xaa];
        goto LAB_00072910;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar8 = 0;
          if (puVar7[0xaa] == 0) {
            return;
          }
          pfVar5 = (float *)(puVar7 + 0xae);
          do {
            fVar1 = *pfVar5;
            uVar8 = uVar8 + 1;
            pfVar5 = pfVar5 + 1;
            *param_4 = (double)fVar1;
            param_4 = param_4 + 1;
          } while (uVar8 < puVar7[0xaa]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (double)GH_U2F((unsigned int)(puVar7[0xab]));
        dVar13 = (double)GH_U2F((unsigned int)(puVar7[0xac]));
        goto LAB_00072928;
      }
      break;
    case 0xd94:
      if (param_3 == 0xa01) {
        uVar8 = puVar7[0xb8];
        goto LAB_00072910;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar8 = 0;
          puVar6 = puVar7;
          if (puVar7[0xb8] == 0) {
            return;
          }
          do {
            uVar8 = uVar8 + 1;
            *param_4 = (double)GH_U2F((unsigned int)(puVar6[0xbc]));
            param_4[1] = (double)GH_U2F((unsigned int)(puVar6[0xbd]));
            param_4 = param_4 + 2;
            puVar6 = puVar6 + 2;
          } while (uVar8 < puVar7[0xb8]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (double)GH_U2F((unsigned int)(puVar7[0xb9]));
        dVar13 = (double)GH_U2F((unsigned int)(puVar7[0xba]));
        goto LAB_00072928;
      }
      break;
    case 0xd95:
      if (param_3 == 0xa01) {
        uVar8 = puVar7[0xd0];
        goto LAB_00072910;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar8 = 0;
          puVar6 = puVar7;
          if (puVar7[0xd0] == 0) {
            return;
          }
          do {
            uVar8 = uVar8 + 1;
            *param_4 = (double)GH_U2F((unsigned int)(puVar6[0xd4]));
            param_4[1] = (double)GH_U2F((unsigned int)(puVar6[0xd5]));
            param_4[2] = (double)GH_U2F((unsigned int)(puVar6[0xd6]));
            param_4 = param_4 + 3;
            puVar6 = puVar6 + 3;
          } while (uVar8 < puVar7[0xd0]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (double)GH_U2F((unsigned int)(puVar7[0xd1]));
        dVar13 = (double)GH_U2F((unsigned int)(puVar7[0xd2]));
        goto LAB_00072928;
      }
      break;
    case 0xd96:
      if (param_3 == 0xa01) {
        uVar8 = puVar7[0xf2];
        goto LAB_00072910;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar8 = 0;
          puVar6 = puVar7;
          if (puVar7[0xf2] == 0) {
            return;
          }
          do {
            uVar8 = uVar8 + 1;
            *param_4 = (double)GH_U2F((unsigned int)(puVar6[0xf6]));
            param_4[1] = (double)GH_U2F((unsigned int)(puVar6[0xf7]));
            param_4[2] = (double)GH_U2F((unsigned int)(puVar6[0xf8]));
            param_4[3] = (double)GH_U2F((unsigned int)(puVar6[0xf9]));
            param_4 = param_4 + 4;
            puVar6 = puVar6 + 4;
          } while (uVar8 < puVar7[0xf2]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (double)GH_U2F((unsigned int)(puVar7[0xf3]));
        dVar13 = (double)GH_U2F((unsigned int)(puVar7[0xf4]));
        goto LAB_00072928;
      }
      break;
    case 0xd97:
      if (param_3 == 0xa01) {
        uVar8 = *puVar7;
        goto LAB_00072910;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar8 = 0;
          puVar6 = puVar7;
          if (*puVar7 == 0) {
            return;
          }
          do {
            uVar8 = uVar8 + 1;
            *param_4 = (double)GH_U2F((unsigned int)(puVar6[4]));
            param_4[1] = (double)GH_U2F((unsigned int)(puVar6[5]));
            param_4[2] = (double)GH_U2F((unsigned int)(puVar6[6]));
            param_4 = param_4 + 3;
            puVar6 = puVar6 + 3;
          } while (uVar8 < *puVar7);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (double)GH_U2F((unsigned int)(puVar7[1]));
        dVar13 = (double)GH_U2F((unsigned int)(puVar7[2]));
        goto LAB_00072928;
      }
      break;
    case 0xd98:
      if (param_3 == 0xa01) {
        uVar8 = puVar7[0x22];
        goto LAB_00072910;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar8 = 0;
          puVar6 = puVar7;
          if (puVar7[0x22] == 0) {
            return;
          }
          do {
            uVar8 = uVar8 + 1;
            *param_4 = (double)GH_U2F((unsigned int)(puVar6[0x26]));
            param_4[1] = (double)GH_U2F((unsigned int)(puVar6[0x27]));
            param_4[2] = (double)GH_U2F((unsigned int)(puVar6[0x28]));
            param_4[3] = (double)GH_U2F((unsigned int)(puVar6[0x29]));
            param_4 = param_4 + 4;
            puVar6 = puVar6 + 4;
          } while (uVar8 < puVar7[0x22]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (double)GH_U2F((unsigned int)(puVar7[0x23]));
        dVar13 = (double)GH_U2F((unsigned int)(puVar7[0x24]));
        goto LAB_00072928;
      }
      break;
    case 0xdb0:
      if (param_3 == 0xa01) {
        *param_4 = (double)CONCAT44(0x43300000,puVar7[0x51e]) - DOUBLE_00108d70;
        uVar8 = puVar7[0x51f];
LAB_000731d8:
        param_4[1] = (double)CONCAT44(0x43300000,uVar8) - dVar13;
        return;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = puVar7[0x51f];
          iVar11 = 0;
          uVar8 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar3 = puVar7[0x51e];
          do {
            uVar12 = 0;
            if (uVar3 != 0) {
              pdVar10 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 4;
                iVar4 = uVar8 * uVar3 + uVar12;
                uVar12 = uVar12 + 1;
                *pdVar10 = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 4 + 0x526]));
                pdVar10[1] = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 4 + 0x527]));
                pdVar10[2] = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 4 + 0x528]));
                pdVar10[3] = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 4 + 0x529]));
                uVar3 = puVar7[0x51e];
                pdVar10 = pdVar10 + 4;
              } while (uVar12 < uVar3);
              uVar9 = puVar7[0x51f];
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < uVar9);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (double)GH_U2F((unsigned int)(puVar7[0x520]));
        param_4[1] = (double)GH_U2F((unsigned int)(puVar7[0x521]));
        param_4[2] = (double)GH_U2F((unsigned int)(puVar7[0x522]));
        dVar13 = (double)GH_U2F((unsigned int)(puVar7[0x523]));
LAB_0007320c:
        param_4[3] = dVar13;
        return;
      }
      break;
    case 0xdb1:
      if (param_3 == 0xa01) {
        *param_4 = (double)CONCAT44(0x43300000,puVar7[0x6b6]) - DOUBLE_00108d70;
        uVar8 = puVar7[0x6b7];
        goto LAB_000731d8;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = puVar7[0x6b7];
          iVar11 = 0;
          uVar8 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar3 = puVar7[0x6b6];
          do {
            uVar12 = 0;
            if (uVar3 != 0) {
              pdVar10 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 1;
                iVar4 = uVar8 * uVar3 + uVar12;
                uVar12 = uVar12 + 1;
                *pdVar10 = (double)GH_U2F((unsigned int)(puVar7[iVar4 + 0x6be]));
                pdVar10 = pdVar10 + 1;
                uVar3 = puVar7[0x6b6];
              } while (uVar12 < uVar3);
              uVar9 = puVar7[0x6b7];
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < uVar9);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (double)GH_U2F((unsigned int)(puVar7[0x6b8]));
        param_4[1] = (double)GH_U2F((unsigned int)(puVar7[0x6b9]));
        param_4[2] = (double)GH_U2F((unsigned int)(puVar7[0x6ba]));
        dVar13 = (double)GH_U2F((unsigned int)(puVar7[0x6bb]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb2:
      if (param_3 == 0xa01) {
        *param_4 = (double)CONCAT44(0x43300000,puVar7[0x3ea]) - DOUBLE_00108d70;
        uVar8 = puVar7[0x3eb];
        goto LAB_000731d8;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = puVar7[0x3eb];
          iVar11 = 0;
          uVar8 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar3 = puVar7[0x3ea];
          do {
            uVar12 = 0;
            if (uVar3 != 0) {
              pdVar10 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 3;
                iVar4 = uVar8 * uVar3 + uVar12;
                uVar12 = uVar12 + 1;
                *pdVar10 = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 3 + 0x3f2]));
                pdVar10[1] = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 3 + 0x3f3]));
                pdVar10[2] = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 3 + 0x3f4]));
                uVar3 = puVar7[0x3ea];
                pdVar10 = pdVar10 + 3;
              } while (uVar12 < uVar3);
              uVar9 = puVar7[0x3eb];
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < uVar9);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (double)GH_U2F((unsigned int)(puVar7[0x3ec]));
        param_4[1] = (double)GH_U2F((unsigned int)(puVar7[0x3ed]));
        param_4[2] = (double)GH_U2F((unsigned int)(puVar7[0x3ee]));
        dVar13 = (double)GH_U2F((unsigned int)(puVar7[0x3ef]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb3:
      if (param_3 == 0xa01) {
        *param_4 = (double)CONCAT44(0x43300000,puVar7[0x722]) - DOUBLE_00108d70;
        uVar8 = puVar7[0x723];
        goto LAB_000731d8;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = puVar7[0x723];
          iVar11 = 0;
          uVar8 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar3 = puVar7[0x722];
          do {
            uVar12 = 0;
            if (uVar3 != 0) {
              pdVar10 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 1;
                iVar4 = uVar8 * uVar3 + uVar12;
                uVar12 = uVar12 + 1;
                *pdVar10 = (double)GH_U2F((unsigned int)(puVar7[iVar4 + 0x72a]));
                pdVar10 = pdVar10 + 1;
                uVar3 = puVar7[0x722];
              } while (uVar12 < uVar3);
              uVar9 = puVar7[0x723];
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < uVar9);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (double)GH_U2F((unsigned int)(puVar7[0x724]));
        param_4[1] = (double)GH_U2F((unsigned int)(puVar7[0x725]));
        param_4[2] = (double)GH_U2F((unsigned int)(puVar7[0x726]));
        dVar13 = (double)GH_U2F((unsigned int)(puVar7[0x727]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb4:
      if (param_3 == 0xa01) {
        *param_4 = (double)CONCAT44(0x43300000,puVar7[0x78e]) - DOUBLE_00108d70;
        uVar8 = puVar7[0x78f];
        goto LAB_000731d8;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = puVar7[0x78f];
          iVar11 = 0;
          uVar8 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar3 = puVar7[0x78e];
          do {
            uVar12 = 0;
            if (uVar3 != 0) {
              pdVar10 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 2;
                iVar4 = uVar8 * uVar3 + uVar12;
                uVar12 = uVar12 + 1;
                *pdVar10 = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 2 + 0x796]));
                pdVar10[1] = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 2 + 0x797]));
                uVar3 = puVar7[0x78e];
                pdVar10 = pdVar10 + 2;
              } while (uVar12 < uVar3);
              uVar9 = puVar7[0x78f];
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < uVar9);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (double)GH_U2F((unsigned int)(puVar7[0x790]));
        param_4[1] = (double)GH_U2F((unsigned int)(puVar7[0x791]));
        param_4[2] = (double)GH_U2F((unsigned int)(puVar7[0x792]));
        dVar13 = (double)GH_U2F((unsigned int)(puVar7[0x793]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb5:
      if (param_3 == 0xa01) {
        *param_4 = (double)CONCAT44(0x43300000,puVar7[0x85e]) - DOUBLE_00108d70;
        uVar8 = puVar7[0x85f];
        goto LAB_000731d8;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = puVar7[0x85f];
          iVar11 = 0;
          uVar8 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar3 = puVar7[0x85e];
          do {
            uVar12 = 0;
            if (uVar3 != 0) {
              pdVar10 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 3;
                iVar4 = uVar8 * uVar3 + uVar12;
                uVar12 = uVar12 + 1;
                *pdVar10 = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 3 + 0x866]));
                pdVar10[1] = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 3 + 0x867]));
                pdVar10[2] = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 3 + 0x868]));
                uVar3 = puVar7[0x85e];
                pdVar10 = pdVar10 + 3;
              } while (uVar12 < uVar3);
              uVar9 = puVar7[0x85f];
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < uVar9);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (double)GH_U2F((unsigned int)(puVar7[0x860]));
        param_4[1] = (double)GH_U2F((unsigned int)(puVar7[0x861]));
        param_4[2] = (double)GH_U2F((unsigned int)(puVar7[0x862]));
        dVar13 = (double)GH_U2F((unsigned int)(puVar7[0x863]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb6:
      if (param_3 == 0xa01) {
        *param_4 = (double)CONCAT44(0x43300000,puVar7[0x992]) - DOUBLE_00108d70;
        uVar8 = puVar7[0x993];
        goto LAB_000731d8;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = puVar7[0x993];
          iVar11 = 0;
          uVar8 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar3 = puVar7[0x992];
          do {
            uVar12 = 0;
            if (uVar3 != 0) {
              pdVar10 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 4;
                iVar4 = uVar8 * uVar3 + uVar12;
                uVar12 = uVar12 + 1;
                *pdVar10 = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 4 + 0x99a]));
                pdVar10[1] = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 4 + 0x99b]));
                pdVar10[2] = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 4 + 0x99c]));
                pdVar10[3] = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 4 + 0x99d]));
                uVar3 = puVar7[0x992];
                pdVar10 = pdVar10 + 4;
              } while (uVar12 < uVar3);
              uVar9 = puVar7[0x993];
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < uVar9);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (double)GH_U2F((unsigned int)(puVar7[0x994]));
        param_4[1] = (double)GH_U2F((unsigned int)(puVar7[0x995]));
        param_4[2] = (double)GH_U2F((unsigned int)(puVar7[0x996]));
        dVar13 = (double)GH_U2F((unsigned int)(puVar7[0x997]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb7:
      if (param_3 == 0xa01) {
        *param_4 = (double)CONCAT44(0x43300000,puVar7[0x11e]) - DOUBLE_00108d70;
        uVar8 = puVar7[0x11f];
        goto LAB_000731d8;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = puVar7[0x11f];
          iVar11 = 0;
          uVar8 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar3 = puVar7[0x11e];
          do {
            uVar12 = 0;
            if (uVar3 != 0) {
              pdVar10 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 3;
                iVar4 = uVar8 * uVar3 + uVar12;
                uVar12 = uVar12 + 1;
                *pdVar10 = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 3 + 0x126]));
                pdVar10[1] = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 3 + 0x127]));
                pdVar10[2] = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 3 + 0x128]));
                uVar3 = puVar7[0x11e];
                pdVar10 = pdVar10 + 3;
              } while (uVar12 < uVar3);
              uVar9 = puVar7[0x11f];
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < uVar9);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (double)GH_U2F((unsigned int)(puVar7[0x120]));
        param_4[1] = (double)GH_U2F((unsigned int)(puVar7[0x121]));
        param_4[2] = (double)GH_U2F((unsigned int)(puVar7[0x122]));
        dVar13 = (double)GH_U2F((unsigned int)(puVar7[0x123]));
        goto LAB_0007320c;
      }
      break;
    case 0xdb8:
      if (param_3 == 0xa01) {
        *param_4 = (double)CONCAT44(0x43300000,puVar7[0x252]) - DOUBLE_00108d70;
        uVar8 = puVar7[0x253];
        goto LAB_000731d8;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = puVar7[0x253];
          iVar11 = 0;
          uVar8 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar3 = puVar7[0x252];
          do {
            uVar12 = 0;
            if (uVar3 != 0) {
              pdVar10 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 4;
                iVar4 = uVar8 * uVar3 + uVar12;
                uVar12 = uVar12 + 1;
                *pdVar10 = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 4 + 0x25a]));
                pdVar10[1] = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 4 + 0x25b]));
                pdVar10[2] = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 4 + 0x25c]));
                pdVar10[3] = (double)GH_U2F((unsigned int)(puVar7[iVar4 * 4 + 0x25d]));
                uVar3 = puVar7[0x252];
                pdVar10 = pdVar10 + 4;
              } while (uVar12 < uVar3);
              uVar9 = puVar7[0x253];
            }
            uVar8 = uVar8 + 1;
          } while (uVar8 < uVar9);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (double)GH_U2F((unsigned int)(puVar7[0x254]));
        param_4[1] = (double)GH_U2F((unsigned int)(puVar7[0x255]));
        param_4[2] = (double)GH_U2F((unsigned int)(puVar7[0x256]));
        dVar13 = (double)GH_U2F((unsigned int)(puVar7[599]));
        goto LAB_0007320c;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glGetMapfv_Exec @ 0x7323c (3780 bytes) */
int _glGetMapfv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  uint param_3;
  float *param_4;
{
  float fVar1;
  double dVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  float *pfVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  
  puVar8 = (uint *)_gleGetMapData(param_1);
  dVar2 = DOUBLE_00108d70;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    switch(param_2) {
    case 0xd90:
      if (param_3 == 0xa01) {
        uVar9 = puVar8[0x70];
LAB_0007384c:
        *param_4 = (float)((double)CONCAT44(0x43300000,uVar9) - DOUBLE_00108d70);
        return;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = 0;
          puVar7 = puVar8;
          if (puVar8[0x70] == 0) {
            return;
          }
          do {
            uVar9 = uVar9 + 1;
            *param_4 = GH_U2F((unsigned int)(puVar7[0x74]));
            param_4[1] = GH_U2F((unsigned int)(puVar7[0x75]));
            param_4[2] = GH_U2F((unsigned int)(puVar7[0x76]));
            param_4[3] = GH_U2F((unsigned int)(puVar7[0x77]));
            param_4 = param_4 + 4;
            puVar7 = puVar7 + 4;
          } while (uVar9 < puVar8[0x70]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = GH_U2F((unsigned int)(puVar8[0x71]));
        fVar1 = GH_U2F((unsigned int)(puVar8[0x72]));
LAB_00073868:
        param_4[1] = fVar1;
        return;
      }
      break;
    case 0xd91:
      if (param_3 == 0xa01) {
        uVar9 = puVar8[0x9c];
        goto LAB_0007384c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = 0;
          if (puVar8[0x9c] == 0) {
            return;
          }
          pfVar6 = (float *)(puVar8 + 0xa0);
          do {
            fVar1 = *pfVar6;
            uVar9 = uVar9 + 1;
            pfVar6 = pfVar6 + 1;
            *param_4 = fVar1;
            param_4 = param_4 + 1;
          } while (uVar9 < puVar8[0x9c]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = GH_U2F((unsigned int)(puVar8[0x9d]));
        fVar1 = GH_U2F((unsigned int)(puVar8[0x9e]));
        goto LAB_00073868;
      }
      break;
    case 0xd92:
      if (param_3 == 0xa01) {
        uVar9 = puVar8[0x4e];
        goto LAB_0007384c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = 0;
          puVar7 = puVar8;
          if (puVar8[0x4e] == 0) {
            return;
          }
          do {
            uVar9 = uVar9 + 1;
            *param_4 = GH_U2F((unsigned int)(puVar7[0x52]));
            param_4[1] = GH_U2F((unsigned int)(puVar7[0x53]));
            param_4[2] = GH_U2F((unsigned int)(puVar7[0x54]));
            param_4 = param_4 + 3;
            puVar7 = puVar7 + 3;
          } while (uVar9 < puVar8[0x4e]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = GH_U2F((unsigned int)(puVar8[0x4f]));
        fVar1 = GH_U2F((unsigned int)(puVar8[0x50]));
        goto LAB_00073868;
      }
      break;
    case 0xd93:
      if (param_3 == 0xa01) {
        uVar9 = puVar8[0xaa];
        goto LAB_0007384c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = 0;
          if (puVar8[0xaa] == 0) {
            return;
          }
          pfVar6 = (float *)(puVar8 + 0xae);
          do {
            fVar1 = *pfVar6;
            uVar9 = uVar9 + 1;
            pfVar6 = pfVar6 + 1;
            *param_4 = fVar1;
            param_4 = param_4 + 1;
          } while (uVar9 < puVar8[0xaa]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = GH_U2F((unsigned int)(puVar8[0xab]));
        fVar1 = GH_U2F((unsigned int)(puVar8[0xac]));
        goto LAB_00073868;
      }
      break;
    case 0xd94:
      if (param_3 == 0xa01) {
        uVar9 = puVar8[0xb8];
        goto LAB_0007384c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = 0;
          puVar7 = puVar8;
          if (puVar8[0xb8] == 0) {
            return;
          }
          do {
            uVar9 = uVar9 + 1;
            *param_4 = GH_U2F((unsigned int)(puVar7[0xbc]));
            param_4[1] = GH_U2F((unsigned int)(puVar7[0xbd]));
            param_4 = param_4 + 2;
            puVar7 = puVar7 + 2;
          } while (uVar9 < puVar8[0xb8]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = GH_U2F((unsigned int)(puVar8[0xb9]));
        fVar1 = GH_U2F((unsigned int)(puVar8[0xba]));
        goto LAB_00073868;
      }
      break;
    case 0xd95:
      if (param_3 == 0xa01) {
        uVar9 = puVar8[0xd0];
        goto LAB_0007384c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = 0;
          puVar7 = puVar8;
          if (puVar8[0xd0] == 0) {
            return;
          }
          do {
            uVar9 = uVar9 + 1;
            *param_4 = GH_U2F((unsigned int)(puVar7[0xd4]));
            param_4[1] = GH_U2F((unsigned int)(puVar7[0xd5]));
            param_4[2] = GH_U2F((unsigned int)(puVar7[0xd6]));
            param_4 = param_4 + 3;
            puVar7 = puVar7 + 3;
          } while (uVar9 < puVar8[0xd0]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = GH_U2F((unsigned int)(puVar8[0xd1]));
        fVar1 = GH_U2F((unsigned int)(puVar8[0xd2]));
        goto LAB_00073868;
      }
      break;
    case 0xd96:
      if (param_3 == 0xa01) {
        uVar9 = puVar8[0xf2];
        goto LAB_0007384c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = 0;
          puVar7 = puVar8;
          if (puVar8[0xf2] == 0) {
            return;
          }
          do {
            uVar9 = uVar9 + 1;
            *param_4 = GH_U2F((unsigned int)(puVar7[0xf6]));
            param_4[1] = GH_U2F((unsigned int)(puVar7[0xf7]));
            param_4[2] = GH_U2F((unsigned int)(puVar7[0xf8]));
            param_4[3] = GH_U2F((unsigned int)(puVar7[0xf9]));
            param_4 = param_4 + 4;
            puVar7 = puVar7 + 4;
          } while (uVar9 < puVar8[0xf2]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = GH_U2F((unsigned int)(puVar8[0xf3]));
        fVar1 = GH_U2F((unsigned int)(puVar8[0xf4]));
        goto LAB_00073868;
      }
      break;
    case 0xd97:
      if (param_3 == 0xa01) {
        uVar9 = *puVar8;
        goto LAB_0007384c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = 0;
          puVar7 = puVar8;
          if (*puVar8 == 0) {
            return;
          }
          do {
            uVar9 = uVar9 + 1;
            *param_4 = GH_U2F((unsigned int)(puVar7[4]));
            param_4[1] = GH_U2F((unsigned int)(puVar7[5]));
            param_4[2] = GH_U2F((unsigned int)(puVar7[6]));
            param_4 = param_4 + 3;
            puVar7 = puVar7 + 3;
          } while (uVar9 < *puVar8);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = GH_U2F((unsigned int)(puVar8[1]));
        fVar1 = GH_U2F((unsigned int)(puVar8[2]));
        goto LAB_00073868;
      }
      break;
    case 0xd98:
      if (param_3 == 0xa01) {
        uVar9 = puVar8[0x22];
        goto LAB_0007384c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = 0;
          puVar7 = puVar8;
          if (puVar8[0x22] == 0) {
            return;
          }
          do {
            uVar9 = uVar9 + 1;
            *param_4 = GH_U2F((unsigned int)(puVar7[0x26]));
            param_4[1] = GH_U2F((unsigned int)(puVar7[0x27]));
            param_4[2] = GH_U2F((unsigned int)(puVar7[0x28]));
            param_4[3] = GH_U2F((unsigned int)(puVar7[0x29]));
            param_4 = param_4 + 4;
            puVar7 = puVar7 + 4;
          } while (uVar9 < puVar8[0x22]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = GH_U2F((unsigned int)(puVar8[0x23]));
        fVar1 = GH_U2F((unsigned int)(puVar8[0x24]));
        goto LAB_00073868;
      }
      break;
    case 0xdb0:
      if (param_3 == 0xa01) {
        *param_4 = (float)((double)CONCAT44(0x43300000,puVar8[0x51e]) - DOUBLE_00108d70);
        uVar9 = puVar8[0x51f];
LAB_0007413c:
        param_4[1] = (float)((double)CONCAT44(0x43300000,uVar9) - dVar2);
        return;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar10 = puVar8[0x51f];
          iVar11 = 0;
          uVar9 = 0;
          if (uVar10 == 0) {
            return;
          }
          uVar4 = puVar8[0x51e];
          do {
            uVar12 = 0;
            if (uVar4 != 0) {
              pfVar6 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 4;
                iVar5 = uVar9 * uVar4 + uVar12;
                uVar12 = uVar12 + 1;
                *pfVar6 = GH_U2F((unsigned int)(puVar8[iVar5 * 4 + 0x526]));
                pfVar6[1] = GH_U2F((unsigned int)(puVar8[iVar5 * 4 + 0x527]));
                pfVar6[2] = GH_U2F((unsigned int)(puVar8[iVar5 * 4 + 0x528]));
                pfVar6[3] = GH_U2F((unsigned int)(puVar8[iVar5 * 4 + 0x529]));
                uVar4 = puVar8[0x51e];
                pfVar6 = pfVar6 + 4;
              } while (uVar12 < uVar4);
              uVar10 = puVar8[0x51f];
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar10);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = GH_U2F((unsigned int)(puVar8[0x520]));
        param_4[1] = GH_U2F((unsigned int)(puVar8[0x521]));
        param_4[2] = GH_U2F((unsigned int)(puVar8[0x522]));
        fVar1 = GH_U2F((unsigned int)(puVar8[0x523]));
LAB_00074174:
        param_4[3] = fVar1;
        return;
      }
      break;
    case 0xdb1:
      if (param_3 == 0xa01) {
        *param_4 = (float)((double)CONCAT44(0x43300000,puVar8[0x6b6]) - DOUBLE_00108d70);
        uVar9 = puVar8[0x6b7];
        goto LAB_0007413c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar10 = puVar8[0x6b7];
          iVar11 = 0;
          uVar9 = 0;
          if (uVar10 == 0) {
            return;
          }
          uVar4 = puVar8[0x6b6];
          do {
            uVar12 = 0;
            if (uVar4 != 0) {
              pfVar6 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 1;
                iVar5 = uVar9 * uVar4 + uVar12;
                uVar12 = uVar12 + 1;
                *pfVar6 = GH_U2F((unsigned int)(puVar8[iVar5 + 0x6be]));
                pfVar6 = pfVar6 + 1;
                uVar4 = puVar8[0x6b6];
              } while (uVar12 < uVar4);
              uVar10 = puVar8[0x6b7];
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar10);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = GH_U2F((unsigned int)(puVar8[0x6b8]));
        param_4[1] = GH_U2F((unsigned int)(puVar8[0x6b9]));
        param_4[2] = GH_U2F((unsigned int)(puVar8[0x6ba]));
        fVar1 = GH_U2F((unsigned int)(puVar8[0x6bb]));
        goto LAB_00074174;
      }
      break;
    case 0xdb2:
      if (param_3 == 0xa01) {
        *param_4 = (float)((double)CONCAT44(0x43300000,puVar8[0x3ea]) - DOUBLE_00108d70);
        uVar9 = puVar8[0x3eb];
        goto LAB_0007413c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar10 = puVar8[0x3eb];
          iVar11 = 0;
          uVar9 = 0;
          if (uVar10 == 0) {
            return;
          }
          uVar4 = puVar8[0x3ea];
          do {
            uVar12 = 0;
            if (uVar4 != 0) {
              pfVar6 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 3;
                iVar5 = uVar9 * uVar4 + uVar12;
                uVar12 = uVar12 + 1;
                *pfVar6 = GH_U2F((unsigned int)(puVar8[iVar5 * 3 + 0x3f2]));
                pfVar6[1] = GH_U2F((unsigned int)(puVar8[iVar5 * 3 + 0x3f3]));
                pfVar6[2] = GH_U2F((unsigned int)(puVar8[iVar5 * 3 + 0x3f4]));
                uVar4 = puVar8[0x3ea];
                pfVar6 = pfVar6 + 3;
              } while (uVar12 < uVar4);
              uVar10 = puVar8[0x3eb];
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar10);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = GH_U2F((unsigned int)(puVar8[0x3ec]));
        param_4[1] = GH_U2F((unsigned int)(puVar8[0x3ed]));
        param_4[2] = GH_U2F((unsigned int)(puVar8[0x3ee]));
        fVar1 = GH_U2F((unsigned int)(puVar8[0x3ef]));
        goto LAB_00074174;
      }
      break;
    case 0xdb3:
      if (param_3 == 0xa01) {
        *param_4 = (float)((double)CONCAT44(0x43300000,puVar8[0x722]) - DOUBLE_00108d70);
        uVar9 = puVar8[0x723];
        goto LAB_0007413c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar10 = puVar8[0x723];
          iVar11 = 0;
          uVar9 = 0;
          if (uVar10 == 0) {
            return;
          }
          uVar4 = puVar8[0x722];
          do {
            uVar12 = 0;
            if (uVar4 != 0) {
              pfVar6 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 1;
                iVar5 = uVar9 * uVar4 + uVar12;
                uVar12 = uVar12 + 1;
                *pfVar6 = GH_U2F((unsigned int)(puVar8[iVar5 + 0x72a]));
                pfVar6 = pfVar6 + 1;
                uVar4 = puVar8[0x722];
              } while (uVar12 < uVar4);
              uVar10 = puVar8[0x723];
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar10);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = GH_U2F((unsigned int)(puVar8[0x724]));
        param_4[1] = GH_U2F((unsigned int)(puVar8[0x725]));
        param_4[2] = GH_U2F((unsigned int)(puVar8[0x726]));
        fVar1 = GH_U2F((unsigned int)(puVar8[0x727]));
        goto LAB_00074174;
      }
      break;
    case 0xdb4:
      if (param_3 == 0xa01) {
        *param_4 = (float)((double)CONCAT44(0x43300000,puVar8[0x78e]) - DOUBLE_00108d70);
        uVar9 = puVar8[0x78f];
        goto LAB_0007413c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar10 = puVar8[0x78f];
          iVar11 = 0;
          uVar9 = 0;
          if (uVar10 == 0) {
            return;
          }
          uVar4 = puVar8[0x78e];
          do {
            uVar12 = 0;
            if (uVar4 != 0) {
              pfVar6 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 2;
                iVar5 = uVar9 * uVar4 + uVar12;
                uVar12 = uVar12 + 1;
                *pfVar6 = GH_U2F((unsigned int)(puVar8[iVar5 * 2 + 0x796]));
                pfVar6[1] = GH_U2F((unsigned int)(puVar8[iVar5 * 2 + 0x797]));
                uVar4 = puVar8[0x78e];
                pfVar6 = pfVar6 + 2;
              } while (uVar12 < uVar4);
              uVar10 = puVar8[0x78f];
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar10);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = GH_U2F((unsigned int)(puVar8[0x790]));
        param_4[1] = GH_U2F((unsigned int)(puVar8[0x791]));
        param_4[2] = GH_U2F((unsigned int)(puVar8[0x792]));
        fVar1 = GH_U2F((unsigned int)(puVar8[0x793]));
        goto LAB_00074174;
      }
      break;
    case 0xdb5:
      if (param_3 == 0xa01) {
        *param_4 = (float)((double)CONCAT44(0x43300000,puVar8[0x85e]) - DOUBLE_00108d70);
        uVar9 = puVar8[0x85f];
        goto LAB_0007413c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar10 = puVar8[0x85f];
          iVar11 = 0;
          uVar9 = 0;
          if (uVar10 == 0) {
            return;
          }
          uVar4 = puVar8[0x85e];
          do {
            uVar12 = 0;
            if (uVar4 != 0) {
              pfVar6 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 3;
                iVar5 = uVar9 * uVar4 + uVar12;
                uVar12 = uVar12 + 1;
                *pfVar6 = GH_U2F((unsigned int)(puVar8[iVar5 * 3 + 0x866]));
                pfVar6[1] = GH_U2F((unsigned int)(puVar8[iVar5 * 3 + 0x867]));
                pfVar6[2] = GH_U2F((unsigned int)(puVar8[iVar5 * 3 + 0x868]));
                uVar4 = puVar8[0x85e];
                pfVar6 = pfVar6 + 3;
              } while (uVar12 < uVar4);
              uVar10 = puVar8[0x85f];
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar10);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = GH_U2F((unsigned int)(puVar8[0x860]));
        param_4[1] = GH_U2F((unsigned int)(puVar8[0x861]));
        param_4[2] = GH_U2F((unsigned int)(puVar8[0x862]));
        fVar1 = GH_U2F((unsigned int)(puVar8[0x863]));
        goto LAB_00074174;
      }
      break;
    case 0xdb6:
      if (param_3 == 0xa01) {
        *param_4 = (float)((double)CONCAT44(0x43300000,puVar8[0x992]) - DOUBLE_00108d70);
        uVar9 = puVar8[0x993];
        goto LAB_0007413c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar10 = puVar8[0x993];
          iVar11 = 0;
          uVar9 = 0;
          if (uVar10 == 0) {
            return;
          }
          uVar4 = puVar8[0x992];
          do {
            uVar12 = 0;
            if (uVar4 != 0) {
              pfVar6 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 4;
                iVar5 = uVar9 * uVar4 + uVar12;
                uVar12 = uVar12 + 1;
                *pfVar6 = GH_U2F((unsigned int)(puVar8[iVar5 * 4 + 0x99a]));
                pfVar6[1] = GH_U2F((unsigned int)(puVar8[iVar5 * 4 + 0x99b]));
                pfVar6[2] = GH_U2F((unsigned int)(puVar8[iVar5 * 4 + 0x99c]));
                pfVar6[3] = GH_U2F((unsigned int)(puVar8[iVar5 * 4 + 0x99d]));
                uVar4 = puVar8[0x992];
                pfVar6 = pfVar6 + 4;
              } while (uVar12 < uVar4);
              uVar10 = puVar8[0x993];
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar10);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = GH_U2F((unsigned int)(puVar8[0x994]));
        param_4[1] = GH_U2F((unsigned int)(puVar8[0x995]));
        param_4[2] = GH_U2F((unsigned int)(puVar8[0x996]));
        fVar1 = GH_U2F((unsigned int)(puVar8[0x997]));
        goto LAB_00074174;
      }
      break;
    case 0xdb7:
      if (param_3 == 0xa01) {
        *param_4 = (float)((double)CONCAT44(0x43300000,puVar8[0x11e]) - DOUBLE_00108d70);
        uVar9 = puVar8[0x11f];
        goto LAB_0007413c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar10 = puVar8[0x11f];
          iVar11 = 0;
          uVar9 = 0;
          if (uVar10 == 0) {
            return;
          }
          uVar4 = puVar8[0x11e];
          do {
            uVar12 = 0;
            if (uVar4 != 0) {
              pfVar6 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 3;
                iVar5 = uVar9 * uVar4 + uVar12;
                uVar12 = uVar12 + 1;
                *pfVar6 = GH_U2F((unsigned int)(puVar8[iVar5 * 3 + 0x126]));
                pfVar6[1] = GH_U2F((unsigned int)(puVar8[iVar5 * 3 + 0x127]));
                pfVar6[2] = GH_U2F((unsigned int)(puVar8[iVar5 * 3 + 0x128]));
                uVar4 = puVar8[0x11e];
                pfVar6 = pfVar6 + 3;
              } while (uVar12 < uVar4);
              uVar10 = puVar8[0x11f];
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar10);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = GH_U2F((unsigned int)(puVar8[0x120]));
        param_4[1] = GH_U2F((unsigned int)(puVar8[0x121]));
        param_4[2] = GH_U2F((unsigned int)(puVar8[0x122]));
        fVar1 = GH_U2F((unsigned int)(puVar8[0x123]));
        goto LAB_00074174;
      }
      break;
    case 0xdb8:
      if (param_3 == 0xa01) {
        *param_4 = (float)((double)CONCAT44(0x43300000,puVar8[0x252]) - DOUBLE_00108d70);
        uVar9 = puVar8[0x253];
        goto LAB_0007413c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar10 = puVar8[0x253];
          iVar11 = 0;
          uVar9 = 0;
          if (uVar10 == 0) {
            return;
          }
          uVar4 = puVar8[0x252];
          do {
            uVar12 = 0;
            if (uVar4 != 0) {
              pfVar6 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 4;
                iVar5 = uVar9 * uVar4 + uVar12;
                uVar12 = uVar12 + 1;
                *pfVar6 = GH_U2F((unsigned int)(puVar8[iVar5 * 4 + 0x25a]));
                pfVar6[1] = GH_U2F((unsigned int)(puVar8[iVar5 * 4 + 0x25b]));
                pfVar6[2] = GH_U2F((unsigned int)(puVar8[iVar5 * 4 + 0x25c]));
                pfVar6[3] = GH_U2F((unsigned int)(puVar8[iVar5 * 4 + 0x25d]));
                uVar4 = puVar8[0x252];
                pfVar6 = pfVar6 + 4;
              } while (uVar12 < uVar4);
              uVar10 = puVar8[0x253];
            }
            uVar9 = uVar9 + 1;
          } while (uVar9 < uVar10);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = GH_U2F((unsigned int)(puVar8[0x254]));
        param_4[1] = GH_U2F((unsigned int)(puVar8[0x255]));
        param_4[2] = GH_U2F((unsigned int)(puVar8[0x256]));
        fVar1 = GH_U2F((unsigned int)(puVar8[599]));
        goto LAB_00074174;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glGetMapiv_Exec @ 0x741a4 (5112 bytes) */
int _glGetMapiv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  uint param_3;
  uint *param_4;
{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  float *pfVar8;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  uint uVar12;
  
  puVar6 = (uint *)_gleGetMapData(param_1);
  fVar2 = FLOAT_00108e90;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    switch(param_2) {
    case 0xd90:
      if (param_3 == 0xa01) {
        uVar7 = puVar6[0x70];
LAB_00074a1c:
        *param_4 = uVar7;
        return;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar7 = 0;
          puVar10 = puVar6;
          if (puVar6[0x70] == 0) {
            return;
          }
          do {
            uVar7 = uVar7 + 1;
            *param_4 = (int)(GH_U2F((unsigned int)(puVar10[0x74])) + fVar2);
            param_4[1] = (int)(GH_U2F((unsigned int)(puVar10[0x75])) + fVar2);
            param_4[2] = (int)(GH_U2F((unsigned int)(puVar10[0x76])) + fVar2);
            param_4[3] = (int)(GH_U2F((unsigned int)(puVar10[0x77])) + fVar2);
            param_4 = param_4 + 4;
            puVar10 = puVar10 + 4;
          } while (uVar7 < puVar6[0x70]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (int)(GH_U2F((unsigned int)(puVar6[0x71])) + FLOAT_00108e90);
        fVar1 = GH_U2F((unsigned int)(puVar6[0x72]));
LAB_00074a48:
        param_4[1] = (int)(fVar1 + fVar2);
        return;
      }
      break;
    case 0xd91:
      if (param_3 == 0xa01) {
        uVar7 = puVar6[0x9c];
        goto LAB_00074a1c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar7 = 0;
          if (puVar6[0x9c] == 0) {
            return;
          }
          pfVar8 = (float *)(puVar6 + 0xa0);
          do {
            fVar1 = *pfVar8;
            uVar7 = uVar7 + 1;
            pfVar8 = pfVar8 + 1;
            *param_4 = (int)(fVar1 + fVar2);
            param_4 = param_4 + 1;
          } while (uVar7 < puVar6[0x9c]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (int)(GH_U2F((unsigned int)(puVar6[0x9d])) + FLOAT_00108e90);
        fVar1 = GH_U2F((unsigned int)(puVar6[0x9e]));
        goto LAB_00074a48;
      }
      break;
    case 0xd92:
      if (param_3 == 0xa01) {
        uVar7 = puVar6[0x4e];
        goto LAB_00074a1c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar7 = 0;
          puVar10 = puVar6;
          if (puVar6[0x4e] == 0) {
            return;
          }
          do {
            uVar7 = uVar7 + 1;
            *param_4 = (int)(GH_U2F((unsigned int)(puVar10[0x52])) + fVar2);
            param_4[1] = (int)(GH_U2F((unsigned int)(puVar10[0x53])) + fVar2);
            param_4[2] = (int)(GH_U2F((unsigned int)(puVar10[0x54])) + fVar2);
            param_4 = param_4 + 3;
            puVar10 = puVar10 + 3;
          } while (uVar7 < puVar6[0x4e]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (int)(GH_U2F((unsigned int)(puVar6[0x4f])) + FLOAT_00108e90);
        fVar1 = GH_U2F((unsigned int)(puVar6[0x50]));
        goto LAB_00074a48;
      }
      break;
    case 0xd93:
      if (param_3 == 0xa01) {
        uVar7 = puVar6[0xaa];
        goto LAB_00074a1c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar7 = 0;
          if (puVar6[0xaa] == 0) {
            return;
          }
          pfVar8 = (float *)(puVar6 + 0xae);
          do {
            fVar1 = *pfVar8;
            uVar7 = uVar7 + 1;
            pfVar8 = pfVar8 + 1;
            *param_4 = (int)(fVar1 + fVar2);
            param_4 = param_4 + 1;
          } while (uVar7 < puVar6[0xaa]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (int)(GH_U2F((unsigned int)(puVar6[0xab])) + FLOAT_00108e90);
        fVar1 = GH_U2F((unsigned int)(puVar6[0xac]));
        goto LAB_00074a48;
      }
      break;
    case 0xd94:
      if (param_3 == 0xa01) {
        uVar7 = puVar6[0xb8];
        goto LAB_00074a1c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar7 = 0;
          puVar10 = puVar6;
          if (puVar6[0xb8] == 0) {
            return;
          }
          do {
            uVar7 = uVar7 + 1;
            *param_4 = (int)(GH_U2F((unsigned int)(puVar10[0xbc])) + fVar2);
            param_4[1] = (int)(GH_U2F((unsigned int)(puVar10[0xbd])) + fVar2);
            param_4 = param_4 + 2;
            puVar10 = puVar10 + 2;
          } while (uVar7 < puVar6[0xb8]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (int)(GH_U2F((unsigned int)(puVar6[0xb9])) + FLOAT_00108e90);
        fVar1 = GH_U2F((unsigned int)(puVar6[0xba]));
        goto LAB_00074a48;
      }
      break;
    case 0xd95:
      if (param_3 == 0xa01) {
        uVar7 = puVar6[0xd0];
        goto LAB_00074a1c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar7 = 0;
          puVar10 = puVar6;
          if (puVar6[0xd0] == 0) {
            return;
          }
          do {
            uVar7 = uVar7 + 1;
            *param_4 = (int)(GH_U2F((unsigned int)(puVar10[0xd4])) + fVar2);
            param_4[1] = (int)(GH_U2F((unsigned int)(puVar10[0xd5])) + fVar2);
            param_4[2] = (int)(GH_U2F((unsigned int)(puVar10[0xd6])) + fVar2);
            param_4 = param_4 + 3;
            puVar10 = puVar10 + 3;
          } while (uVar7 < puVar6[0xd0]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (int)(GH_U2F((unsigned int)(puVar6[0xd1])) + FLOAT_00108e90);
        fVar1 = GH_U2F((unsigned int)(puVar6[0xd2]));
        goto LAB_00074a48;
      }
      break;
    case 0xd96:
      if (param_3 == 0xa01) {
        uVar7 = puVar6[0xf2];
        goto LAB_00074a1c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar7 = 0;
          puVar10 = puVar6;
          if (puVar6[0xf2] == 0) {
            return;
          }
          do {
            uVar7 = uVar7 + 1;
            *param_4 = (int)(GH_U2F((unsigned int)(puVar10[0xf6])) + fVar2);
            param_4[1] = (int)(GH_U2F((unsigned int)(puVar10[0xf7])) + fVar2);
            param_4[2] = (int)(GH_U2F((unsigned int)(puVar10[0xf8])) + fVar2);
            param_4[3] = (int)(GH_U2F((unsigned int)(puVar10[0xf9])) + fVar2);
            param_4 = param_4 + 4;
            puVar10 = puVar10 + 4;
          } while (uVar7 < puVar6[0xf2]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (int)(GH_U2F((unsigned int)(puVar6[0xf3])) + FLOAT_00108e90);
        fVar1 = GH_U2F((unsigned int)(puVar6[0xf4]));
        goto LAB_00074a48;
      }
      break;
    case 0xd97:
      if (param_3 == 0xa01) {
        uVar7 = *puVar6;
        goto LAB_00074a1c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar7 = 0;
          puVar10 = puVar6;
          if (*puVar6 == 0) {
            return;
          }
          do {
            uVar7 = uVar7 + 1;
            *param_4 = (int)(GH_U2F((unsigned int)(puVar10[4])) + fVar2);
            param_4[1] = (int)(GH_U2F((unsigned int)(puVar10[5])) + fVar2);
            param_4[2] = (int)(GH_U2F((unsigned int)(puVar10[6])) + fVar2);
            param_4 = param_4 + 3;
            puVar10 = puVar10 + 3;
          } while (uVar7 < *puVar6);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (int)(GH_U2F((unsigned int)(puVar6[1])) + FLOAT_00108e90);
        fVar1 = GH_U2F((unsigned int)(puVar6[2]));
        goto LAB_00074a48;
      }
      break;
    case 0xd98:
      if (param_3 == 0xa01) {
        uVar7 = puVar6[0x22];
        goto LAB_00074a1c;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar7 = 0;
          puVar10 = puVar6;
          if (puVar6[0x22] == 0) {
            return;
          }
          do {
            uVar7 = uVar7 + 1;
            *param_4 = (int)(GH_U2F((unsigned int)(puVar10[0x26])) + fVar2);
            param_4[1] = (int)(GH_U2F((unsigned int)(puVar10[0x27])) + fVar2);
            param_4[2] = (int)(GH_U2F((unsigned int)(puVar10[0x28])) + fVar2);
            param_4[3] = (int)(GH_U2F((unsigned int)(puVar10[0x29])) + fVar2);
            param_4 = param_4 + 4;
            puVar10 = puVar10 + 4;
          } while (uVar7 < puVar6[0x22]);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (int)(GH_U2F((unsigned int)(puVar6[0x23])) + FLOAT_00108e90);
        fVar1 = GH_U2F((unsigned int)(puVar6[0x24]));
        goto LAB_00074a48;
      }
      break;
    case 0xdb0:
      if (param_3 == 0xa01) {
        *param_4 = puVar6[0x51e];
        uVar7 = puVar6[0x51f];
LAB_000755a4:
        param_4[1] = uVar7;
        return;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = puVar6[0x51f];
          iVar11 = 0;
          uVar7 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar4 = puVar6[0x51e];
          do {
            fVar2 = FLOAT_00108e90;
            uVar12 = 0;
            if (uVar4 != 0) {
              puVar10 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 4;
                iVar5 = uVar7 * uVar4 + uVar12;
                uVar12 = uVar12 + 1;
                *puVar10 = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 4 + 0x526])) + fVar2);
                puVar10[1] = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 4 + 0x527])) + fVar2);
                puVar10[2] = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 4 + 0x528])) + fVar2);
                puVar10[3] = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 4 + 0x529])) + fVar2);
                uVar4 = puVar6[0x51e];
                puVar10 = puVar10 + 4;
              } while (uVar12 < uVar4);
              uVar9 = puVar6[0x51f];
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar9);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (int)(GH_U2F((unsigned int)(puVar6[0x520])) + FLOAT_00108e90);
        param_4[1] = (int)(GH_U2F((unsigned int)(puVar6[0x521])) + fVar2);
        param_4[2] = (int)(GH_U2F((unsigned int)(puVar6[0x522])) + fVar2);
        fVar1 = GH_U2F((unsigned int)(puVar6[0x523]));
LAB_00075600:
        param_4[3] = (int)(fVar1 + fVar2);
        return;
      }
      break;
    case 0xdb1:
      if (param_3 == 0xa01) {
        *param_4 = puVar6[0x6b6];
        uVar7 = puVar6[0x6b7];
        goto LAB_000755a4;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = puVar6[0x6b7];
          iVar11 = 0;
          uVar7 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar4 = puVar6[0x6b6];
          do {
            fVar2 = FLOAT_00108e90;
            uVar12 = 0;
            if (uVar4 != 0) {
              puVar10 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 1;
                iVar5 = uVar7 * uVar4 + uVar12;
                uVar12 = uVar12 + 1;
                *puVar10 = (int)(GH_U2F((unsigned int)(puVar6[iVar5 + 0x6be])) + fVar2);
                puVar10 = puVar10 + 1;
                uVar4 = puVar6[0x6b6];
              } while (uVar12 < uVar4);
              uVar9 = puVar6[0x6b7];
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar9);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (int)(GH_U2F((unsigned int)(puVar6[0x6b8])) + FLOAT_00108e90);
        param_4[1] = (int)(GH_U2F((unsigned int)(puVar6[0x6b9])) + fVar2);
        param_4[2] = (int)(GH_U2F((unsigned int)(puVar6[0x6ba])) + fVar2);
        fVar1 = GH_U2F((unsigned int)(puVar6[0x6bb]));
        goto LAB_00075600;
      }
      break;
    case 0xdb2:
      if (param_3 == 0xa01) {
        *param_4 = puVar6[0x3ea];
        uVar7 = puVar6[0x3eb];
        goto LAB_000755a4;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = puVar6[0x3eb];
          iVar11 = 0;
          uVar7 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar4 = puVar6[0x3ea];
          do {
            fVar2 = FLOAT_00108e90;
            uVar12 = 0;
            if (uVar4 != 0) {
              puVar10 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 3;
                iVar5 = uVar7 * uVar4 + uVar12;
                uVar12 = uVar12 + 1;
                *puVar10 = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 3 + 0x3f2])) + fVar2);
                puVar10[1] = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 3 + 0x3f3])) + fVar2);
                puVar10[2] = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 3 + 0x3f4])) + fVar2);
                uVar4 = puVar6[0x3ea];
                puVar10 = puVar10 + 3;
              } while (uVar12 < uVar4);
              uVar9 = puVar6[0x3eb];
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar9);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (int)(GH_U2F((unsigned int)(puVar6[0x3ec])) + FLOAT_00108e90);
        param_4[1] = (int)(GH_U2F((unsigned int)(puVar6[0x3ed])) + fVar2);
        param_4[2] = (int)(GH_U2F((unsigned int)(puVar6[0x3ee])) + fVar2);
        fVar1 = GH_U2F((unsigned int)(puVar6[0x3ef]));
        goto LAB_00075600;
      }
      break;
    case 0xdb3:
      if (param_3 == 0xa01) {
        *param_4 = puVar6[0x722];
        uVar7 = puVar6[0x723];
        goto LAB_000755a4;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = puVar6[0x723];
          iVar11 = 0;
          uVar7 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar4 = puVar6[0x722];
          do {
            fVar2 = FLOAT_00108e90;
            uVar12 = 0;
            if (uVar4 != 0) {
              puVar10 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 1;
                iVar5 = uVar7 * uVar4 + uVar12;
                uVar12 = uVar12 + 1;
                *puVar10 = (int)(GH_U2F((unsigned int)(puVar6[iVar5 + 0x72a])) + fVar2);
                puVar10 = puVar10 + 1;
                uVar4 = puVar6[0x722];
              } while (uVar12 < uVar4);
              uVar9 = puVar6[0x723];
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar9);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (int)(GH_U2F((unsigned int)(puVar6[0x724])) + FLOAT_00108e90);
        param_4[1] = (int)(GH_U2F((unsigned int)(puVar6[0x725])) + fVar2);
        param_4[2] = (int)(GH_U2F((unsigned int)(puVar6[0x726])) + fVar2);
        fVar1 = GH_U2F((unsigned int)(puVar6[0x727]));
        goto LAB_00075600;
      }
      break;
    case 0xdb4:
      if (param_3 == 0xa01) {
        *param_4 = puVar6[0x78e];
        uVar7 = puVar6[0x78f];
        goto LAB_000755a4;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = puVar6[0x78f];
          iVar11 = 0;
          uVar7 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar4 = puVar6[0x78e];
          do {
            fVar2 = FLOAT_00108e90;
            uVar12 = 0;
            if (uVar4 != 0) {
              puVar10 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 2;
                iVar5 = uVar7 * uVar4 + uVar12;
                uVar12 = uVar12 + 1;
                *puVar10 = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 2 + 0x796])) + fVar2);
                puVar10[1] = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 2 + 0x797])) + fVar2);
                uVar4 = puVar6[0x78e];
                puVar10 = puVar10 + 2;
              } while (uVar12 < uVar4);
              uVar9 = puVar6[0x78f];
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar9);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (int)(GH_U2F((unsigned int)(puVar6[0x790])) + FLOAT_00108e90);
        param_4[1] = (int)(GH_U2F((unsigned int)(puVar6[0x791])) + fVar2);
        param_4[2] = (int)(GH_U2F((unsigned int)(puVar6[0x792])) + fVar2);
        fVar1 = GH_U2F((unsigned int)(puVar6[0x793]));
        goto LAB_00075600;
      }
      break;
    case 0xdb5:
      if (param_3 == 0xa01) {
        *param_4 = puVar6[0x85e];
        uVar7 = puVar6[0x85f];
        goto LAB_000755a4;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = puVar6[0x85f];
          iVar11 = 0;
          uVar7 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar4 = puVar6[0x85e];
          do {
            fVar2 = FLOAT_00108e90;
            uVar12 = 0;
            if (uVar4 != 0) {
              puVar10 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 3;
                iVar5 = uVar7 * uVar4 + uVar12;
                uVar12 = uVar12 + 1;
                *puVar10 = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 3 + 0x866])) + fVar2);
                puVar10[1] = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 3 + 0x867])) + fVar2);
                puVar10[2] = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 3 + 0x868])) + fVar2);
                uVar4 = puVar6[0x85e];
                puVar10 = puVar10 + 3;
              } while (uVar12 < uVar4);
              uVar9 = puVar6[0x85f];
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar9);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (int)(GH_U2F((unsigned int)(puVar6[0x860])) + FLOAT_00108e90);
        param_4[1] = (int)(GH_U2F((unsigned int)(puVar6[0x861])) + fVar2);
        param_4[2] = (int)(GH_U2F((unsigned int)(puVar6[0x862])) + fVar2);
        fVar1 = GH_U2F((unsigned int)(puVar6[0x863]));
        goto LAB_00075600;
      }
      break;
    case 0xdb6:
      if (param_3 == 0xa01) {
        *param_4 = puVar6[0x992];
        uVar7 = puVar6[0x993];
        goto LAB_000755a4;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = puVar6[0x993];
          iVar11 = 0;
          uVar7 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar4 = puVar6[0x992];
          do {
            fVar2 = FLOAT_00108e90;
            uVar12 = 0;
            if (uVar4 != 0) {
              puVar10 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 4;
                iVar5 = uVar7 * uVar4 + uVar12;
                uVar12 = uVar12 + 1;
                *puVar10 = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 4 + 0x99a])) + fVar2);
                puVar10[1] = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 4 + 0x99b])) + fVar2);
                puVar10[2] = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 4 + 0x99c])) + fVar2);
                puVar10[3] = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 4 + 0x99d])) + fVar2);
                uVar4 = puVar6[0x992];
                puVar10 = puVar10 + 4;
              } while (uVar12 < uVar4);
              uVar9 = puVar6[0x993];
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar9);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (int)(GH_U2F((unsigned int)(puVar6[0x994])) + FLOAT_00108e90);
        param_4[1] = (int)(GH_U2F((unsigned int)(puVar6[0x995])) + fVar2);
        param_4[2] = (int)(GH_U2F((unsigned int)(puVar6[0x996])) + fVar2);
        fVar1 = GH_U2F((unsigned int)(puVar6[0x997]));
        goto LAB_00075600;
      }
      break;
    case 0xdb7:
      if (param_3 == 0xa01) {
        *param_4 = puVar6[0x11e];
        uVar7 = puVar6[0x11f];
        goto LAB_000755a4;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = puVar6[0x11f];
          iVar11 = 0;
          uVar7 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar4 = puVar6[0x11e];
          do {
            fVar2 = FLOAT_00108e90;
            uVar12 = 0;
            if (uVar4 != 0) {
              puVar10 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 3;
                iVar5 = uVar7 * uVar4 + uVar12;
                uVar12 = uVar12 + 1;
                *puVar10 = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 3 + 0x126])) + fVar2);
                puVar10[1] = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 3 + 0x127])) + fVar2);
                puVar10[2] = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 3 + 0x128])) + fVar2);
                uVar4 = puVar6[0x11e];
                puVar10 = puVar10 + 3;
              } while (uVar12 < uVar4);
              uVar9 = puVar6[0x11f];
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar9);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (int)(GH_U2F((unsigned int)(puVar6[0x120])) + FLOAT_00108e90);
        param_4[1] = (int)(GH_U2F((unsigned int)(puVar6[0x121])) + fVar2);
        param_4[2] = (int)(GH_U2F((unsigned int)(puVar6[0x122])) + fVar2);
        fVar1 = GH_U2F((unsigned int)(puVar6[0x123]));
        goto LAB_00075600;
      }
      break;
    case 0xdb8:
      if (param_3 == 0xa01) {
        *param_4 = puVar6[0x252];
        uVar7 = puVar6[0x253];
        goto LAB_000755a4;
      }
      if (param_3 < 0xa02) {
        if (param_3 == 0xa00) {
          uVar9 = puVar6[0x253];
          iVar11 = 0;
          uVar7 = 0;
          if (uVar9 == 0) {
            return;
          }
          uVar4 = puVar6[0x252];
          do {
            fVar2 = FLOAT_00108e90;
            uVar12 = 0;
            if (uVar4 != 0) {
              puVar10 = param_4 + iVar11;
              do {
                iVar11 = iVar11 + 4;
                iVar5 = uVar7 * uVar4 + uVar12;
                uVar12 = uVar12 + 1;
                *puVar10 = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 4 + 0x25a])) + fVar2);
                puVar10[1] = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 4 + 0x25b])) + fVar2);
                puVar10[2] = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 4 + 0x25c])) + fVar2);
                puVar10[3] = (int)(GH_U2F((unsigned int)(puVar6[iVar5 * 4 + 0x25d])) + fVar2);
                uVar4 = puVar6[0x252];
                puVar10 = puVar10 + 4;
              } while (uVar12 < uVar4);
              uVar9 = puVar6[0x253];
            }
            uVar7 = uVar7 + 1;
          } while (uVar7 < uVar9);
          return;
        }
      }
      else if (param_3 == 0xa02) {
        *param_4 = (int)(GH_U2F((unsigned int)(puVar6[0x254])) + FLOAT_00108e90);
        param_4[1] = (int)(GH_U2F((unsigned int)(puVar6[0x255])) + fVar2);
        param_4[2] = (int)(GH_U2F((unsigned int)(puVar6[0x256])) + fVar2);
        fVar1 = GH_U2F((unsigned int)(puVar6[599]));
        goto LAB_00075600;
      }
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x500;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glMapGrid1_ListExec @ 0x75640 (48 bytes) */
undefined4 _glMapGrid1_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  double in_stack_ffffffd0;
  
  ((void (*)())_glMapGrid1d_Exec)(param_1,*param_2,(double)GH_U2F((unsigned int)(param_2[1])),(double)GH_U2F((unsigned int)(param_2[2])),fparam_3,
                    fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffb8,in_stack_ffffffc0
                    ,in_stack_ffffffc8,in_stack_ffffffd0);
  return 0x10;
}

/* _glMapGrid1f_Comp @ 0x75670 (224 bytes) */
int _glMapGrid1f_Comp(int param_1,uint param_2,double fparam_1,double fparam_2)
{
  undefined4 uVar1;
  uint *puVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (0 < (int)param_2) {
      puVar2 = (uint *)_gleAddListItem(param_1,PTR__glMapGrid1_ListExec_001101c8,0x10);
      if (puVar2 == (uint *)0x0) {
        return 0;
      }
      *puVar2 = param_2;
      puVar2[1] = (uint)GH_F2U((float)fparam_1);
      puVar2[2] = (uint)GH_F2U((float)fparam_2);
      puVar2[3] = (uint)(int)((float)(fparam_2 - fparam_1) /
                        (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58)
                        );
      return (int)puVar2;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return param_1;
    }
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return param_1;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return param_1;
}

/* _glMapGrid1f_Exec @ 0x75750 (144 bytes) */
void _glMapGrid1f_Exec(int param_1,uint param_2,float fparam_1,float fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  double dVar1;
  undefined4 uVar2;
  
  dVar1 = DOUBLE_00108d58;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (0 < (int)param_2) {
      *(uint *)(0x74a4 + param_1 + 4) = param_2;
      *(float *)(param_1 + 0x74ac) = (float)fparam_1;
      *(float *)(param_1 + 0x74b0) = (float)fparam_2;
      *(float *)(param_1 + 0x74b4) =
           (float)(fparam_2 - fparam_1) /
           (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - dVar1);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glMapGrid1f_CompExec @ 0x757e0 (88 bytes) */
void _glMapGrid1f_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1,double fparam_2)
{
  undefined4 in_LR;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glMapGrid1f_Comp)(param_1,param_2,fparam_1,fparam_2);
  ((void (*)())_glMapGrid1f_Exec)(param_1,param_2,fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                    (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)));
  return;
}

/* _glMapGrid1d_Comp @ 0x75838 (232 bytes) */
int _glMapGrid1d_Comp(int param_1,uint param_2,double fparam_1,double fparam_2)
{
  undefined4 uVar1;
  uint *puVar2;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (0 < (int)param_2) {
      puVar2 = (uint *)_gleAddListItem(param_1,PTR__glMapGrid1_ListExec_001101c8,0x10);
      if (puVar2 == (uint *)0x0) {
        return 0;
      }
      *puVar2 = param_2;
      puVar2[1] = (uint)GH_F2U((float)fparam_1);
      puVar2[2] = (uint)GH_F2U((float)fparam_2);
      puVar2[3] = (uint)GH_F2U((float)((fparam_2 - fparam_1) /
                               ((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58)
                               ));
      return (int)puVar2;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return param_1;
    }
    uVar1 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return param_1;
    }
    uVar1 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return param_1;
}

/* _glMapGrid1d_Exec @ 0x75920 (152 bytes) */
void _glMapGrid1d_Exec(int param_1,uint param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  double dVar1;
  undefined4 uVar2;
  
  dVar1 = DOUBLE_00108d58;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if (0 < (int)param_2) {
      *(uint *)(0x74a4 + param_1 + 4) = param_2;
      *(float *)(param_1 + 0x74ac) = (float)fparam_1;
      *(float *)(param_1 + 0x74b0) = (float)fparam_2;
      *(float *)(param_1 + 0x74b4) =
           (float)((fparam_2 - fparam_1) /
                  ((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - dVar1));
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glMapGrid1d_CompExec @ 0x759b8 (88 bytes) */
void _glMapGrid1d_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1,double fparam_2)
{
  undefined4 in_LR;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glMapGrid1d_Comp)(param_1,param_2,fparam_1,fparam_2);
  ((void (*)())_glMapGrid1d_Exec)(param_1,param_2,fparam_1,fparam_2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
                    (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)));
  return;
}

/* _glMapGrid2_ListExec @ 0x75a10 (60 bytes) */
undefined4 _glMapGrid2_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  double in_stack_ffffffc8;
  
  ((void (*)())_glMapGrid2d_Exec)(param_1,*param_2,in_r5,in_r6,in_r7,in_r8,param_2[4],(double)GH_U2F((unsigned int)(param_2[1])),
                    (double)GH_U2F((unsigned int)(param_2[2])),(double)GH_U2F((unsigned int)(param_2[5])),(double)GH_U2F((unsigned int)(param_2[6])),
                    fparam_5,fparam_6,fparam_7,fparam_8,in_stack_ffffffa8,in_stack_ffffffb0,
                    in_stack_ffffffb8,in_stack_ffffffc0,in_stack_ffffffc8);
  return 0x20;
}

/* _glMapGrid2f_Comp @ 0x75a4c (268 bytes) */
void _glMapGrid2f_Comp(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  double dVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((0 < (int)param_2) && (0 < (int)param_5)) {
      puVar3 = (uint *)_gleAddListItem(param_1,PTR__glMapGrid2_ListExec_001101cc,0x20);
      if (puVar3 != (uint *)0x0) {
        *puVar3 = param_2;
        puVar3[1] = (uint)GH_F2U((float)fparam_1);
        puVar3[2] = (uint)GH_F2U((float)fparam_2);
        dVar1 = DOUBLE_00108d58;
        puVar3[4] = param_5;
        puVar3[5] = (uint)GH_F2U((float)fparam_3);
        puVar3[6] = (uint)GH_F2U((float)fparam_4);
        puVar3[3] = (uint)(int)((float)(fparam_2 - fparam_1) /
                          (float)((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - dVar1));
        puVar3[7] = (uint)(int)((float)(fparam_4 - fparam_3) /
                          (float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - dVar1));
      }
      goto LAB_00075b4c;
    }
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00075b4c;
    uVar2 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00075b4c;
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
LAB_00075b4c:
  FUN_00008b68();
  return;
}

/* _glMapGrid2f_Exec @ 0x75b58 (196 bytes) */
void _glMapGrid2f_Exec(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint param_5,float fparam_1,float fparam_2,float fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11)
{
  double dVar1;
  undefined4 uVar2;
  double dVar3;
  
  dVar1 = DOUBLE_00108d58;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((0 < (int)param_2) && (0 < (int)param_5)) {
      dVar3 = (double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58;
      *(uint *)(param_1 + 0x74b8) = param_2;
      *(float *)(param_1 + 0x74bc) = (float)fparam_1;
      *(float *)(param_1 + 0x74c0) = (float)fparam_2;
      *(uint *)(param_1 + 0x74c8) = param_5;
      *(float *)(param_1 + 0x74cc) = (float)fparam_3;
      *(float *)(param_1 + 0x74d0) = (float)fparam_4;
      *(float *)(param_1 + 0x74c4) = (float)(fparam_2 - fparam_1) / (float)dVar3;
      *(float *)(param_1 + 0x74d4) =
           (float)(fparam_4 - fparam_3) /
           (float)((double)CONCAT44(0x43300000,param_5 ^ 0x80000000) - dVar1);
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glMapGrid2f_CompExec @ 0x75c1c (112 bytes) */
void _glMapGrid2f_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((void (*)())_glMapGrid2f_Comp)(param_1,param_2,param_3,param_4,param_5,fparam_1,fparam_2,fparam_3,fparam_4);
  ((void (*)())_glMapGrid2f_Exec)(param_1,param_2,param_3,param_4,param_5,fparam_1,fparam_2,fparam_3,fparam_4,
                    in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)));
  return;
}

/* _glMapGrid2d_Comp @ 0x75c8c (284 bytes) */
void _glMapGrid2d_Comp(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,uint param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  double dVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((0 < (int)param_2) && (0 < (int)param_7)) {
      puVar3 = (uint *)_gleAddListItem(param_1,PTR__glMapGrid2_ListExec_001101cc,0x20);
      if (puVar3 != (uint *)0x0) {
        *puVar3 = param_2;
        puVar3[1] = (uint)GH_F2U((float)fparam_1);
        puVar3[2] = (uint)GH_F2U((float)fparam_2);
        dVar1 = DOUBLE_00108d58;
        puVar3[5] = (uint)GH_F2U((float)fparam_3);
        puVar3[6] = (uint)GH_F2U((float)fparam_4);
        puVar3[4] = param_7;
        puVar3[3] = (uint)GH_F2U((float)((fparam_2 - fparam_1) /
                                 ((double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - dVar1)));
        puVar3[7] = (uint)GH_F2U((float)((fparam_4 - fparam_3) /
                                 ((double)CONCAT44(0x43300000,param_7 ^ 0x80000000) - dVar1)));
      }
      goto LAB_00075d9c;
    }
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00075d9c;
    uVar2 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) goto LAB_00075d9c;
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
LAB_00075d9c:
  FUN_00008b68();
  return;
}

/* _glMapGrid2d_Exec @ 0x75da8 (212 bytes) */
void _glMapGrid2d_Exec(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,uint param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  double dVar1;
  undefined4 uVar2;
  double dVar3;
  
  dVar1 = DOUBLE_00108d58;
  if (*(short *)(param_1 + 0x4a10) < 0) {
    if ((0 < (int)param_2) && (0 < (int)param_7)) {
      dVar3 = (double)CONCAT44(0x43300000,param_2 ^ 0x80000000) - DOUBLE_00108d58;
      *(uint *)(param_1 + 0x74b8) = param_2;
      *(float *)(param_1 + 0x74bc) = (float)fparam_1;
      *(uint *)(param_1 + 0x74c8) = param_7;
      *(float *)(param_1 + 0x74cc) = (float)fparam_3;
      *(float *)(param_1 + 0x74c4) = (float)((fparam_2 - fparam_1) / dVar3);
      *(float *)(param_1 + 0x74d4) =
           (float)((fparam_4 - fparam_3) /
                  ((double)CONCAT44(0x43300000,param_7 ^ 0x80000000) - dVar1));
      *(float *)(param_1 + 0x74c0) = (float)fparam_2;
      *(float *)(param_1 + 0x74d0) = (float)fparam_4;
      return;
    }
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x501;
  }
  else {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar2 = 0x502;
  }
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glMapGrid2d_CompExec @ 0x75e7c (112 bytes) */
void _glMapGrid2d_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,undefined4 param_6,undefined4 param_7,double fparam_1,double fparam_2,double fparam_3,double fparam_4)
{
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((void (*)())_glMapGrid2d_Comp)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,fparam_1,fparam_2,
                    fparam_3,fparam_4);
  ((void (*)())_glMapGrid2d_Exec)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,fparam_1,fparam_2,
                    fparam_3,fparam_4,in_f5,in_f6,in_f7,in_f8,(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x8)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)),
                    (*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x18)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x20)),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)));
  return;
}

/* _glIndexMask_ListExec @ 0x75eec (40 bytes) */
int _glIndexMask_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glIndexMask_Exec)(param_1,*param_2);
  return 4;
}

/* _glIndexMask_Comp @ 0x75f14 (76 bytes) */
int _glIndexMask_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glIndexMask_ListExec_001101e0,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glIndexMask_Exec @ 0x75f60 (56 bytes) */
int _glIndexMask_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  if (*(short *)(param_1 + 0x4a10) < 0) {
    *(undefined4 *)(param_1 + 0x3194) = param_2;
    *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x40000;
    return;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  *(undefined4 *)(param_1 + 0x7574) = 0x502;
  return;
}

/* _glIndexMask_CompExec @ 0x75f98 (56 bytes) */
int _glIndexMask_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glIndexMask_Comp)(param_1,param_2);
  ((int (*)())_glIndexMask_Exec)(param_1,param_2);
  return;
}

/* _glColorMask_ListExec @ 0x75fd0 (56 bytes) */
int _glColorMask_ListExec(param_1, param_2)
  undefined4 param_1;
  byte *param_2;
{
  _glColorMask_Exec(param_1,(uint)*param_2,(uint)param_2[1],(uint)param_2[2],(uint)param_2[3]);
  return 4;
}

/* _glStencilMask_ListExec @ 0x76008 (40 bytes) */
int _glStencilMask_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glStencilMask_Exec(param_1,*param_2);
  return 4;
}

/* _glStencilMask_Comp @ 0x76030 (76 bytes) */
int _glStencilMask_Comp(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glStencilMask_ListExec_001101d4,4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glStencilMask_CompExec @ 0x7607c (56 bytes) */
int _glStencilMask_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glStencilMask_Comp)(param_1,param_2);
  _glStencilMask_Exec(param_1,param_2);
  return;
}

/* _glStencilMaskSeparate_ListExec @ 0x760b4 (44 bytes) */
int _glStencilMaskSeparate_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((int (*)())_glStencilMaskSeparate_Exec)(param_1,*param_2,param_2[1]);
  return 8;
}

/* _glStencilMaskSeparate_Comp @ 0x760e0 (84 bytes) */
int _glStencilMaskSeparate_Comp(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glStencilMaskSeparate_ListExec_001101d0,8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = param_3;
    *puVar1 = param_2;
  }
  return puVar1;
}

/* _glStencilMaskSeparate_Exec @ 0x76134 (132 bytes) */
int _glStencilMaskSeparate_Exec(param_1, param_2, param_3)
  int param_1;
  uint param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar1 = 0x502;
    goto LAB_000761a0;
  }
  if (param_2 == 0x405) {
    *(undefined4 *)(param_1 + 0x319c) = param_3;
    goto LAB_000761a8;
  }
  if (param_2 < 0x406) {
    if (param_2 == 0x404) {
LAB_00076188:
      *(undefined4 *)(param_1 + 0x3198) = param_3;
LAB_000761a8:
      *(uint *)(param_1 + 0x310) = *(uint *)(param_1 + 0x310) | 0x100000;
      return;
    }
  }
  else if (param_2 == 0x408) {
    *(undefined4 *)(param_1 + 0x319c) = param_3;
    goto LAB_00076188;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x500;
LAB_000761a0:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glStencilMaskSeparate_CompExec @ 0x761b8 (64 bytes) */
int _glStencilMaskSeparate_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  ((int (*)())_glStencilMaskSeparate_Comp)(param_1,param_2,param_3);
  ((int (*)())_glStencilMaskSeparate_Exec)(param_1,param_2,param_3);
  return;
}

/* _glMaterialf_ListExec @ 0x761f8 (52 bytes) */
undefined4 _glMaterialf_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_glMaterialf_Exec)(param_1,*param_2,param_2[1],(double)GH_U2F((unsigned int)(param_2[2])),fparam_2,fparam_3,fparam_4
                    ,fparam_5,fparam_6,fparam_7,fparam_8);
  return 0xc;
}

/* _glMaterialf_Comp @ 0x7622c (100 bytes) */
undefined4 * _glMaterialf_Comp(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glMaterialf_ListExec_001101f0,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = (float)fparam_1;
    *puVar1 = param_2;
    puVar1[1] = param_3;
  }
  return puVar1;
}

/* _glMaterialf_CompExec @ 0x76290 (80 bytes) */
void _glMaterialf_CompExec(undefined4 param_1,undefined4 param_2,undefined4 param_3,double fparam_1)
{
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((undefined4 * (*)())_glMaterialf_Comp)(param_1,param_2,param_3,fparam_1);
  ((void (*)())_glMaterialf_Exec)(param_1,param_2,param_3,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8);
  return;
}

/* _glMateriali_ListExec @ 0x762e0 (52 bytes) */
undefined4 _glMateriali_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_glMateriali_Exec)(param_1,*param_2,param_2[1],param_2[2],fparam_1,fparam_2,fparam_3,fparam_4,
                    fparam_5,fparam_6,fparam_7,fparam_8);
  return 0xc;
}

/* _glMateriali_Comp @ 0x76314 (92 bytes) */
int _glMateriali_Comp(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glMateriali_ListExec_001101e8,0xc);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[2] = param_4;
    *puVar1 = param_2;
    puVar1[1] = param_3;
  }
  return puVar1;
}

/* _glMateriali_Exec @ 0x76370 (356 bytes) */
void _glMateriali_Exec(int param_1,uint param_2,int param_3,uint param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  undefined4 uVar1;
  
  if (((*(char *)(param_1 + 0x7580) != '\0') && (-1 < *(short *)(param_1 + 0x4a10))) &&
     (*(char *)(param_1 + 0x4664) == '\0')) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  }
  if (param_3 == 0x1601) {
    if (((int)param_4 < 0) || (*(int *)(*(int *)(param_1 + 0x468c) + 0xa0) < (int)param_4)) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar1 = 0x501;
      goto LAB_000764bc;
    }
    if (param_2 == 0x405) {
      ((void (*)())_gleLightMaterialShineChange_B)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) -
                                        DOUBLE_00108d58));
      return;
    }
    if (param_2 < 0x406) {
      if (param_2 == 0x404) {
        ((void (*)())_gleLightMaterialShineChange_F)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) -
                                          DOUBLE_00108d58));
        return;
      }
    }
    else if (param_2 == 0x408) {
      ((void (*)())_gleLightMaterialShineChange_FB)(param_1,(double)(float)((double)CONCAT44(0x43300000,param_4 ^ 0x80000000) -
                                        DOUBLE_00108d58));
      return;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar1 = 0x500;
LAB_000764bc:
  *(undefined4 *)(param_1 + 0x7574) = uVar1;
  return;
}

/* _glMateriali_CompExec @ 0x764d4 (72 bytes) */
int _glMateriali_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glMateriali_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glMateriali_Exec)(param_1,param_2,param_3,param_4,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,
                    in_f8);
  return;
}

/* _glMaterialiv_ListExec @ 0x7651c (52 bytes) */
undefined4 _glMaterialiv_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  ((void (*)())_glMaterialiv_Exec)(param_1,*param_2,param_2[1],param_2 + 2,fparam_1,fparam_2,fparam_3,fparam_4,
                     fparam_5,fparam_6,fparam_7,fparam_8);
  return 0x18;
}

/* _glMaterialiv_Comp @ 0x76550 (284 bytes) */
int _glMaterialiv_Comp(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined *param_3;
  undefined4 *param_4;
{
  undefined *puVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)_gleAddListItem(param_1,PTR__glMaterialiv_ListExec_001101e4,0x18);
  if (puVar2 == (undefined4 *)0x0) {
    return puVar2;
  }
  if (param_3 != (undefined *)0x1600) {
    if (param_3 < (undefined *)0x1601) {
      if (param_3 != ((unsigned char *)0x00001201)) {
        if (((unsigned char *)0x00001201) < param_3) {
          puVar1 = ((unsigned char *)0x00001202);
        }
        else {
          puVar1 = ((unsigned char *)0x00001200);
        }
        if (param_3 != puVar1) goto LAB_00076644;
      }
    }
    else if (param_3 != (undefined *)0x1602) {
      if (param_3 < (undefined *)0x1602) {
        *puVar2 = param_2;
        puVar2[1] = param_3;
        puVar2[2] = *param_4;
        return puVar2;
      }
      if (param_3 == (undefined *)0x1603) {
        *puVar2 = param_2;
        puVar2[1] = 0x1603;
        puVar2[2] = *param_4;
        puVar2[3] = param_4[1];
        puVar2[4] = param_4[2];
        return puVar2;
      }
LAB_00076644:
      if (*(int *)(param_1 + 0x7574) != 0) {
        return puVar2;
      }
      *(undefined4 *)(param_1 + 0x7574) = 0x500;
      return puVar2;
    }
  }
  *puVar2 = param_2;
  puVar2[1] = param_3;
  puVar2[2] = *param_4;
  puVar2[3] = param_4[1];
  puVar2[4] = param_4[2];
  puVar2[5] = param_4[3];
  return puVar2;
}

/* _glMaterialiv_Exec @ 0x7666c (1968 bytes) */
void _glMaterialiv_Exec(int param_1,uint param_2,undefined *param_3,uint *param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8)
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  uint uStack_2c;
  
  if (((*(char *)(param_1 + 0x7580) != '\0') && (-1 < *(short *)(param_1 + 0x4a10))) &&
     (*(char *)(param_1 + 0x4664) == '\0')) {
    ((undefined4 (*)())_gleForceToSoftwareTCL)(param_1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,fparam_8);
  }
  if (param_3 == (undefined *)0x1600) {
    local_30 = 0x43300000;
    uStack_2c = param_4[3] ^ 0x80000000;
    local_40 = (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58) *
               FLOAT_00108e68 + FLOAT_00108e6c;
    local_3c = (float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - DOUBLE_00108d58) *
               FLOAT_00108e68 + FLOAT_00108e6c;
    local_34 = (float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58) * FLOAT_00108e68 +
               FLOAT_00108e6c;
    local_38 = (float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - DOUBLE_00108d58) *
               FLOAT_00108e68 + FLOAT_00108e6c;
    if (param_2 == 0x405) {
      _gleLightMaterialRGBAChange_B_E(param_1,&local_40);
      goto LAB_00076dd8;
    }
    if (param_2 < 0x406) {
      if (param_2 == 0x404) {
        _gleLightMaterialRGBAChange_F_E(param_1,&local_40);
        goto LAB_00076dd8;
      }
    }
    else if (param_2 == 0x408) {
      _gleLightMaterialRGBAChange_FB_E(param_1,&local_40);
      goto LAB_00076dd8;
    }
  }
  else if (param_3 < (undefined *)0x1601) {
    if (param_3 == ((unsigned char *)0x00001201)) {
      local_30 = 0x43300000;
      uStack_2c = param_4[3] ^ 0x80000000;
      local_40 = (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58) *
                 FLOAT_00108e68 + FLOAT_00108e6c;
      local_3c = (float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - DOUBLE_00108d58) *
                 FLOAT_00108e68 + FLOAT_00108e6c;
      local_34 = (float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58) * FLOAT_00108e68
                 + FLOAT_00108e6c;
      local_38 = (float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - DOUBLE_00108d58) *
                 FLOAT_00108e68 + FLOAT_00108e6c;
      if (param_2 == 0x405) {
        _gleLightMaterialRGBAChange_B_D(param_1,&local_40);
        goto LAB_00076dd8;
      }
      if (param_2 < 0x406) {
        if (param_2 == 0x404) {
          _gleLightMaterialRGBAChange_F_D(param_1,&local_40);
          goto LAB_00076dd8;
        }
      }
      else if (param_2 == 0x408) {
        _gleLightMaterialRGBAChange_FB_D(param_1,&local_40);
        goto LAB_00076dd8;
      }
    }
    else if (((unsigned char *)0x00001201) < param_3) {
      if (param_3 == ((unsigned char *)0x00001202)) {
        local_30 = 0x43300000;
        uStack_2c = param_4[3] ^ 0x80000000;
        local_40 = (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58) *
                   FLOAT_00108e68 + FLOAT_00108e6c;
        local_3c = (float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - DOUBLE_00108d58) *
                   FLOAT_00108e68 + FLOAT_00108e6c;
        local_34 = (float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58) *
                   FLOAT_00108e68 + FLOAT_00108e6c;
        local_38 = (float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - DOUBLE_00108d58) *
                   FLOAT_00108e68 + FLOAT_00108e6c;
        if (param_2 == 0x405) {
          _gleLightMaterialRGBAChange_B_S(param_1,&local_40);
          goto LAB_00076dd8;
        }
        if (param_2 < 0x406) {
          if (param_2 == 0x404) {
            _gleLightMaterialRGBAChange_F_S(param_1,&local_40);
            goto LAB_00076dd8;
          }
        }
        else if (param_2 == 0x408) {
          _gleLightMaterialRGBAChange_FB_S(param_1,&local_40);
          goto LAB_00076dd8;
        }
      }
    }
    else if (param_3 == ((unsigned char *)0x00001200)) {
      local_30 = 0x43300000;
      uStack_2c = param_4[3] ^ 0x80000000;
      local_40 = (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58) *
                 FLOAT_00108e68 + FLOAT_00108e6c;
      local_3c = (float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - DOUBLE_00108d58) *
                 FLOAT_00108e68 + FLOAT_00108e6c;
      local_34 = (float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58) * FLOAT_00108e68
                 + FLOAT_00108e6c;
      local_38 = (float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - DOUBLE_00108d58) *
                 FLOAT_00108e68 + FLOAT_00108e6c;
      if (param_2 == 0x405) {
        _gleLightMaterialRGBAChange_B_A(param_1,&local_40);
        goto LAB_00076dd8;
      }
      if (param_2 < 0x406) {
        if (param_2 == 0x404) {
          _gleLightMaterialRGBAChange_F_A(param_1,&local_40);
          goto LAB_00076dd8;
        }
      }
      else if (param_2 == 0x408) {
        _gleLightMaterialRGBAChange_FB_A(param_1,&local_40);
        goto LAB_00076dd8;
      }
    }
  }
  else if (param_3 == (undefined *)0x1602) {
    local_30 = 0x43300000;
    uStack_2c = param_4[3] ^ 0x80000000;
    local_40 = (float)((double)CONCAT44(0x43300000,*param_4 ^ 0x80000000) - DOUBLE_00108d58) *
               FLOAT_00108e68 + FLOAT_00108e6c;
    local_3c = (float)((double)CONCAT44(0x43300000,param_4[1] ^ 0x80000000) - DOUBLE_00108d58) *
               FLOAT_00108e68 + FLOAT_00108e6c;
    local_34 = (float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58) * FLOAT_00108e68 +
               FLOAT_00108e6c;
    local_38 = (float)((double)CONCAT44(0x43300000,param_4[2] ^ 0x80000000) - DOUBLE_00108d58) *
               FLOAT_00108e68 + FLOAT_00108e6c;
    if (param_2 == 0x405) {
      _gleLightMaterialRGBAChange_B_AD(param_1,&local_40);
      goto LAB_00076dd8;
    }
    if (param_2 < 0x406) {
      if (param_2 == 0x404) {
        _gleLightMaterialRGBAChange_F_AD(param_1,&local_40);
        goto LAB_00076dd8;
      }
    }
    else if (param_2 == 0x408) {
      _gleLightMaterialRGBAChange_FB_AD(param_1,&local_40);
      goto LAB_00076dd8;
    }
  }
  else if (param_3 < (undefined *)0x1602) {
    uStack_2c = *param_4;
    if (((int)uStack_2c < 0) || (*(int *)(*(int *)(param_1 + 0x468c) + 0xa0) < (int)uStack_2c)) {
      if (*(int *)(param_1 + 0x7574) != 0) {
        return;
      }
      uVar2 = 0x501;
      goto LAB_00076dd0;
    }
    if (param_2 == 0x405) {
      uStack_2c = uStack_2c ^ 0x80000000;
      local_30 = 0x43300000;
      ((void (*)())_gleLightMaterialShineChange_B)(param_1,(double)(float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58));
      goto LAB_00076dd8;
    }
    if (param_2 < 0x406) {
      if (param_2 == 0x404) {
        uStack_2c = uStack_2c ^ 0x80000000;
        local_30 = 0x43300000;
        ((void (*)())_gleLightMaterialShineChange_F)(param_1,(double)(float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58)
                  );
        goto LAB_00076dd8;
      }
    }
    else if (param_2 == 0x408) {
      uStack_2c = uStack_2c ^ 0x80000000;
      local_30 = 0x43300000;
      ((void (*)())_gleLightMaterialShineChange_FB)(param_1,(double)(float)((double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58));
      goto LAB_00076dd8;
    }
  }
  else if (param_3 == (undefined *)0x1603) {
    local_30 = 0x43300000;
    uStack_2c = param_4[2] * 0x101 ^ 0x80000000;
    dVar7 = (double)CONCAT44(0x43300000,*param_4 * 0x101 ^ 0x80000000) - DOUBLE_00108d58;
    dVar6 = (double)CONCAT44(0x43300000,uStack_2c) - DOUBLE_00108d58;
    dVar8 = (double)CONCAT44(0x43300000,param_4[1] * 0x101 ^ 0x80000000) - DOUBLE_00108d58;
    if (param_2 == 0x405) {
      uVar5 = 1;
      uVar3 = 1;
LAB_00076d88:
      if (uVar3 <= uVar5) {
        iVar1 = (uVar5 + 1) - uVar3;
        iVar4 = uVar3 * 0x10 + param_1;
        do {
          *(float *)(iVar4 + 0x2f0) = (float)dVar7;
          *(float *)(iVar4 + 0x2f4) = (float)dVar8;
          *(float *)(iVar4 + 0x2f8) = (float)dVar6;
          iVar4 = iVar4 + 0x10;
          iVar1 = iVar1 + -1;
        } while (iVar1 != 0);
      }
LAB_00076dd8:
      if (((*(char *)(param_1 + 0x4df8) != '\0') && (param_3 != (undefined *)0x1601)) &&
         (param_3 != (undefined *)0x1603)) {
        (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
      }
      return;
    }
    if (param_2 < 0x406) {
      if (param_2 == 0x404) {
        uVar5 = 0;
        uVar3 = 0;
        goto LAB_00076d88;
      }
    }
    else if (param_2 == 0x408) {
      uVar3 = 0;
      uVar5 = 1;
      goto LAB_00076d88;
    }
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar2 = 0x500;
LAB_00076dd0:
  *(undefined4 *)(param_1 + 0x7574) = uVar2;
  return;
}

/* _glMaterialiv_CompExec @ 0x76e1c (72 bytes) */
int _glMaterialiv_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  ((int (*)())_glMaterialiv_Comp)(param_1,param_2,param_3,param_4);
  ((void (*)())_glMaterialiv_Exec)(param_1,param_2,param_3,param_4,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,
                     in_f8);
  return;
}

/* _glGetMaterialfv_Exec @ 0x76e64 (584 bytes) */
int _glGetMaterialfv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined *param_3;
  float *param_4;
{
  float fVar1;
  double dVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar3 = 0x502;
    goto LAB_00077094;
  }
  if ((*(char *)(param_1 + 0x30ab) != '\0') && (*(char *)(param_1 + 0x4df8) == '\0')) {
    (**(code **)(param_1 + 0x4de0))(param_1,param_1 + 0x2a0);
  }
  dVar2 = DOUBLE_00108d98;
  if (param_2 == 0x404) {
    iVar4 = 0;
LAB_00076ef4:
    if (param_3 == ((unsigned char *)0x00001202)) {
      iVar4 = iVar4 * 4 + param_1;
      *param_4 = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x20);
      param_4[1] = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x24);
      param_4[2] = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x28);
      fVar1 = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x2c);
      goto LAB_0007701c;
    }
    if (((unsigned char *)0x00001202) < param_3) {
      if (param_3 == (undefined *)0x1601) {
        *param_4 = *(float *)(*(int *)(iVar4 * 4 + param_1 + 0x4dd0) + 0x40);
        return;
      }
      if (param_3 < (undefined *)0x1602) {
        if (param_3 == (undefined *)0x1600) {
          iVar4 = iVar4 * 4 + param_1;
          *param_4 = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x30);
          param_4[1] = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x34);
          param_4[2] = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x38);
          fVar1 = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x3c);
          goto LAB_0007701c;
        }
      }
      else if (param_3 == (undefined *)0x1603) {
        iVar4 = iVar4 * 0x10 + param_1;
        *param_4 = (float)((double)*(float *)(iVar4 + 0x2f0) * DOUBLE_00108d98);
        param_4[1] = (float)((double)*(float *)(iVar4 + 0x2f4) * dVar2);
        param_4[2] = (float)((double)*(float *)(iVar4 + 0x2f8) * dVar2);
        return;
      }
    }
    else {
      if (param_3 == ((unsigned char *)0x00001200)) {
        iVar4 = iVar4 * 4 + param_1;
        *param_4 = **(float **)(iVar4 + 0x4dd0);
        param_4[1] = *(float *)(*(int *)(iVar4 + 0x4dd0) + 4);
        param_4[2] = *(float *)(*(int *)(iVar4 + 0x4dd0) + 8);
        fVar1 = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0xc);
LAB_0007701c:
        param_4[3] = fVar1;
        return;
      }
      if (param_3 == ((unsigned char *)0x00001201)) {
        iVar4 = iVar4 * 4 + param_1;
        *param_4 = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x10);
        param_4[1] = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x14);
        param_4[2] = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x18);
        fVar1 = *(float *)(*(int *)(iVar4 + 0x4dd0) + 0x1c);
        goto LAB_0007701c;
      }
    }
  }
  else if (param_2 == 0x405) {
    iVar4 = 1;
    goto LAB_00076ef4;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar3 = 0x500;
LAB_00077094:
  *(undefined4 *)(param_1 + 0x7574) = uVar3;
  return;
}

/* _glGetMaterialiv_Exec @ 0x770ac (832 bytes) */
int _glGetMaterialiv_Exec(param_1, param_2, param_3, param_4)
  int param_1;
  int param_2;
  undefined *param_3;
  int *param_4;
{
  float fVar1;
  double dVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  int iVar6;
  
  fVar4 = FLOAT_00108e94;
  fVar3 = FLOAT_00108e90;
  dVar2 = DOUBLE_00108d98;
  if (-1 < *(short *)(param_1 + 0x4a10)) {
    if (*(int *)(param_1 + 0x7574) != 0) {
      return;
    }
    uVar5 = 0x502;
    goto LAB_00077110;
  }
  if (param_2 == 0x404) {
    iVar6 = 0;
LAB_00077118:
    if (param_3 == ((unsigned char *)0x00001202)) {
      iVar6 = iVar6 * 4 + param_1;
      *param_4 = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x20) * FLOAT_00108e94 - FLOAT_00108e90
                      );
      param_4[1] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x24) * fVar4 - fVar3);
      param_4[2] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x28) * fVar4 - fVar3);
      fVar1 = *(float *)(*(int *)(iVar6 + 0x4dd0) + 0x2c);
      goto LAB_00077254;
    }
    if (((unsigned char *)0x00001202) < param_3) {
      if (param_3 == (undefined *)0x1601) {
        *param_4 = (int)(*(float *)(*(int *)(iVar6 * 4 + param_1 + 0x4dd0) + 0x40) + FLOAT_00108e90)
        ;
        return;
      }
      if (param_3 < (undefined *)0x1602) {
        if (param_3 == (undefined *)0x1600) {
          iVar6 = iVar6 * 4 + param_1;
          *param_4 = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x30) * FLOAT_00108e94 -
                          FLOAT_00108e90);
          param_4[1] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x34) * fVar4 - fVar3);
          param_4[2] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x38) * fVar4 - fVar3);
          fVar1 = *(float *)(*(int *)(iVar6 + 0x4dd0) + 0x3c);
          goto LAB_00077254;
        }
      }
      else if (param_3 == (undefined *)0x1603) {
        iVar6 = iVar6 * 0x10 + param_1;
        *param_4 = (int)((double)*(float *)(iVar6 + 0x2f0) * DOUBLE_00108d98);
        param_4[1] = (int)((double)*(float *)(iVar6 + 0x2f4) * dVar2);
        param_4[2] = (int)((double)*(float *)(iVar6 + 0x2f8) * dVar2);
        return;
      }
    }
    else {
      if (param_3 == ((unsigned char *)0x00001200)) {
        iVar6 = iVar6 * 4 + param_1;
        *param_4 = (int)(**(float **)(iVar6 + 0x4dd0) * FLOAT_00108e94 - FLOAT_00108e90);
        param_4[1] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 4) * fVar4 - fVar3);
        param_4[2] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 8) * fVar4 - fVar3);
        fVar1 = *(float *)(*(int *)(iVar6 + 0x4dd0) + 0xc);
LAB_00077254:
        param_4[3] = (int)(fVar1 * fVar4 - fVar3);
        return;
      }
      if (param_3 == ((unsigned char *)0x00001201)) {
        iVar6 = iVar6 * 4 + param_1;
        *param_4 = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x10) * FLOAT_00108e94 -
                        FLOAT_00108e90);
        param_4[1] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x14) * fVar4 - fVar3);
        param_4[2] = (int)(*(float *)(*(int *)(iVar6 + 0x4dd0) + 0x18) * fVar4 - fVar3);
        fVar1 = *(float *)(*(int *)(iVar6 + 0x4dd0) + 0x1c);
        goto LAB_00077254;
      }
    }
  }
  else if (param_2 == 0x405) {
    iVar6 = 1;
    goto LAB_00077118;
  }
  if (*(int *)(param_1 + 0x7574) != 0) {
    return;
  }
  uVar5 = 0x500;
LAB_00077110:
  *(undefined4 *)(param_1 + 0x7574) = uVar5;
  return;
}

/* _glLoadIdentity_ListExec @ 0x773ec (36 bytes) */
int _glLoadIdentity_ListExec(param_1)
  undefined4 param_1;
{
  _glLoadIdentity_Exec(param_1);
  return 0;
}

/* _glLoadIdentity_Comp @ 0x77410 (32 bytes) */
int _glLoadIdentity_Comp(param_1)
  undefined4 param_1;
{
  undefined4 uVar1;
  
  uVar1 = _gleAddListItem(param_1,PTR__glLoadIdentity_ListExec_0011020c,0);
  return uVar1;
}

/* _glLoadIdentity_CompExec @ 0x77430 (48 bytes) */
int _glLoadIdentity_CompExec(param_1)
  undefined4 param_1;
{
  ((int (*)())_glLoadIdentity_Comp)(param_1);
  _glLoadIdentity_Exec(param_1);
  return;
}

/* _glLoadMatrixd_ListExec @ 0x77460 (36 bytes) */
int _glLoadMatrixd_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  _glLoadMatrixd_Exec(param_1,param_2);
  return 0x80;
}

/* _glLoadMatrixd_Comp @ 0x77484 (100 bytes) */
int _glLoadMatrixd_Comp(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _gleAddListItem(param_1,PTR__glLoadMatrixd_ListExec_00110208,0x80);
  if (iVar2 != 0) {
    iVar1 = 0;
    iVar3 = 0x10;
    do {
      *(undefined8 *)(iVar1 + iVar2) = *(undefined8 *)(iVar1 + param_2);
      iVar1 = iVar1 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar2;
}

/* _glLoadMatrixd_CompExec @ 0x774e8 (56 bytes) */
int _glLoadMatrixd_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glLoadMatrixd_Comp)(param_1,param_2);
  _glLoadMatrixd_Exec(param_1,param_2);
  return;
}

/* _glLoadMatrixf_ListExec @ 0x77520 (36 bytes) */
int _glLoadMatrixf_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  _glLoadMatrixf_Exec(param_1,param_2);
  return 0x40;
}

/* _glLoadMatrixf_Comp @ 0x77544 (100 bytes) */
int _glLoadMatrixf_Comp(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _gleAddListItem(param_1,PTR__glLoadMatrixf_ListExec_00110204,0x40);
  if (iVar2 != 0) {
    iVar1 = 0;
    iVar3 = 0x10;
    do {
      *(undefined4 *)(iVar1 + iVar2) = *(undefined4 *)(iVar1 + param_2);
      iVar1 = iVar1 + 4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar2;
}

/* _glLoadMatrixf_CompExec @ 0x775a8 (56 bytes) */
int _glLoadMatrixf_CompExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glLoadMatrixf_Comp)(param_1,param_2);
  _glLoadMatrixf_Exec(param_1,param_2);
  return;
}

/* _glLoadTransposeMatrixd_ListExec @ 0x775e0 (36 bytes) */
int _glLoadTransposeMatrixd_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  ((int (*)())_glLoadTransposeMatrixd_Exec)(param_1,param_2);
  return 0x80;
}

/* _glLoadTransposeMatrixd_Comp @ 0x77604 (100 bytes) */
int _glLoadTransposeMatrixd_Comp(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _gleAddListItem(param_1,PTR__glLoadTransposeMatrixd_ListExec_00110200,0x80);
  if (iVar2 != 0) {
    iVar1 = 0;
    iVar3 = 0x10;
    do {
      *(undefined8 *)(iVar1 + iVar2) = *(undefined8 *)(iVar1 + param_2);
      iVar1 = iVar1 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return iVar2;
}

/* _glLoadTransposeMatrixd_Exec @ 0x77668 (128 bytes) */
int _glLoadTransposeMatrixd_Exec(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  if ((*(short *)(param_1 + 0x4a10) < 0) && (*(int *)(param_1 + 0x4ff4) < 0x18)) {
    param_2 = _gleLoadTransposeMatrixd(param_2,*(undefined4 *)(param_1 + 0x4fec));
    *(uint *)(param_1 + 0x50ac) = *(uint *)(param_1 + 0x50ac) | *(uint *)(param_1 + 0x50a8);
    *(uint *)(param_1 + 0x50b0) = *(uint *)(param_1 + 0x50b0) | *(uint *)(param_1 + 0x50a8);
  }
  else if (*(int *)(param_1 + 0x7574) == 0) {
    *(undefined4 *)(param_1 + 0x7574) = 0x502;
  }
  return param_2;
}

