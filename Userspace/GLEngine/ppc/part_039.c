#include "decls.h"

/* _glFinalCombinerInputNV_Comp @ 0xb423c (100 bytes) */
int _glFinalCombinerInputNV_Comp(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_gleAddListItem(param_1,PTR__glFinalCombinerInputNV_ListExec_001104d4,0x10)
  ;
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[3] = param_5;
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = param_4;
  }
  return puVar1;
}

/* _glCombinerParameterfvNV_CompExec @ 0xb42a0 (64 bytes) */
int _glCombinerParameterfvNV_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  _glCombinerParameterfvNV_Comp(param_1,param_2,param_3);
  _glCombinerParameterfvNV_Exec(param_1,param_2,param_3);
  return;
}

/* _glCombinerStageParameterfvNV_CompExec @ 0xb42e0 (72 bytes) */
int _glCombinerStageParameterfvNV_CompExec(param_1, param_2, param_3, param_4)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  _glCombinerStageParameterfvNV_Comp(param_1,param_2,param_3,param_4);
  _glCombinerStageParameterfvNV_Exec(param_1,param_2,param_3,param_4);
  return;
}

/* _glCombinerParameterfNV_CompExec @ 0xb4328 (72 bytes) */
void _glCombinerParameterfNV_CompExec(undefined4 param_1,undefined4 param_2,double fparam_1)
{
  ((undefined4 * (*)())_glCombinerParameterfNV_Comp)(param_1,param_2,fparam_1);
  ((void (*)())_glCombinerParameterfNV_Exec)(param_1,param_2,fparam_1);
  return;
}

/* _glCombinerParameterivNV_CompExec @ 0xb4370 (64 bytes) */
int _glCombinerParameterivNV_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 in_LR;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  _glCombinerParameterivNV_Comp(param_1,param_2,param_3);
  ((void (*)())_glCombinerParameterivNV_Exec)(param_1,param_2,param_3,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)));
  return;
}

/* _glCombinerParameteriNV_CompExec @ 0xb43b0 (64 bytes) */
int _glCombinerParameteriNV_CompExec(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 in_LR;
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  
  _glCombinerParameteriNV_Comp(param_1,param_2,param_3);
  ((void (*)())_glCombinerParameteriNV_Exec)(param_1,param_2,param_3,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)));
  return;
}

/* _glCombinerInputNV_CompExec @ 0xb43f0 (96 bytes) */
int _glCombinerInputNV_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  _glCombinerInputNV_Comp(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  _glCombinerInputNV_Exec(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}

/* _glCombinerOutputNV_CompExec @ 0xb4450 (140 bytes) */
int _glCombinerOutputNV_CompExec(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  uint param_9;
  uint param_10;
  uint param_11;
{
  _glCombinerOutputNV_Comp
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9 & 0xff,
             param_10 & 0xff,param_11 & 0xff);
  _glCombinerOutputNV_Exec
            (param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9 & 0xff,
             param_10 & 0xff,param_11 & 0xff);
  return;
}

/* _glFinalCombinerInputNV_CompExec @ 0xb44dc (80 bytes) */
int _glFinalCombinerInputNV_CompExec(param_1, param_2, param_3, param_4, param_5)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
{
  ((int (*)())_glFinalCombinerInputNV_Comp)(param_1,param_2,param_3,param_4,param_5);
  _glFinalCombinerInputNV_Exec(param_1,param_2,param_3,param_4,param_5);
  return;
}

/* _glCombinerParameterfvNV_ListExec @ 0xb452c (48 bytes) */
int _glCombinerParameterfvNV_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glCombinerParameterfvNV_Exec(param_1,*param_2,param_2 + 1);
  return 0x14;
}

/* _glCombinerStageParameterfvNV_ListExec @ 0xb455c (52 bytes) */
int _glCombinerStageParameterfvNV_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glCombinerStageParameterfvNV_Exec(param_1,*param_2,param_2[1],param_2 + 2);
  return 0x18;
}

/* _glCombinerParameterfNV_ListExec @ 0xb4590 (44 bytes) */
int _glCombinerParameterfNV_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  ((void (*)())_glCombinerParameterfNV_Exec)(param_1,*param_2,(double)GH_U2F((unsigned int)(param_2[1])));
  return 8;
}

/* _glCombinerParameterivNV_ListExec @ 0xb45bc (48 bytes) */
undefined4 _glCombinerParameterivNV_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10)
{
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  
  ((void (*)())_glCombinerParameterivNV_Exec)(param_1,*param_2,param_2 + 1,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,
             fparam_7,fparam_8,in_stack_ffffffb8,in_stack_ffffffc0);
  return 0x14;
}

/* _glCombinerParameteriNV_ListExec @ 0xb45ec (44 bytes) */
undefined4 _glCombinerParameteriNV_ListExec(undefined4 param_1,undefined4 *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10)
{
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  
  ((void (*)())_glCombinerParameteriNV_Exec)(param_1,*param_2,param_2[1],fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,
             fparam_7,fparam_8,in_stack_ffffffb8,in_stack_ffffffc0);
  return 8;
}

/* _glCombinerInputNV_ListExec @ 0xb4618 (64 bytes) */
int _glCombinerInputNV_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glCombinerInputNV_Exec(param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5]);
  return 0x18;
}

/* _glCombinerOutputNV_ListExec @ 0xb4658 (100 bytes) */
int _glCombinerOutputNV_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glCombinerOutputNV_Exec
            (param_1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5],param_2[6],
             (uint)*(byte *)((int)param_2 + 0x1f),(uint)*(byte *)((int)param_2 + 0x23),
             (uint)*(byte *)((int)param_2 + 0x27));
  return 0x28;
}

/* _glFinalCombinerInputNV_ListExec @ 0xb46bc (56 bytes) */
int _glFinalCombinerInputNV_ListExec(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  _glFinalCombinerInputNV_Exec(param_1,*param_2,param_2[1],param_2[2],param_2[3]);
  return 0x10;
}

/* _gleDecomposePrimitiveVertices @ 0xb46f4 (700 bytes) */
int _gleDecomposePrimitiveVertices(param_1, param_2, param_3, param_4, param_5, param_6)
  int param_1;
  byte *param_2;
  uint param_3;
  int param_4;
  int param_5;
  undefined1 *param_6;
{
  byte bVar1;
  int iVar2;
  ushort uVar3;
  int iVar4;
  undefined1 uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  
  bVar1 = *param_2;
  if (0x24 < (int)param_3) {
    if (*(uint *)(param_1 + 0x7588) < param_3) {
      if (*(int *)(param_1 + 0x758c) != 0) {
        _free(*(int *)(param_1 + 0x758c));
      }
      uVar7 = _malloc(param_3 << 8);
      *(undefined4 *)(param_1 + 0x758c) = uVar7;
      *(uint *)(param_1 + 0x7588) = param_3;
      *param_6 = 1;
    }
    param_5 = *(int *)(param_1 + 0x758c);
  }
  iVar8 = 0;
  if (0 < (int)param_3) {
    do {
      iVar9 = 0;
      if (bVar1 != 0) {
        do {
          iVar2 = iVar9 * 2;
          switch((uint)(*(ushort *)(param_2 + iVar2 + 4) >> 10)) {
          case 0:
            iVar4 = (*(ushort *)(param_2 + iVar2 + 4) >> 8 & 3) + 1;
            if (iVar4 != 0) {
              puVar6 = (undefined4 *)(param_4 + (*(ushort *)(param_2 + iVar2 + 4) & 0x3f) * 4);
              puVar10 = (undefined4 *)(param_5 + 0x20);
              do {
                uVar7 = *puVar6;
                puVar6 = puVar6 + 1;
                *puVar10 = uVar7;
                puVar10 = puVar10 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            break;
          case 1:
            iVar4 = (*(ushort *)(param_2 + iVar2 + 4) >> 8 & 3) + 1;
            if (iVar4 != 0) {
              puVar6 = (undefined4 *)(param_4 + (*(ushort *)(param_2 + iVar2 + 4) & 0x3f) * 4);
              puVar10 = (undefined4 *)(param_5 + 0x40);
              do {
                uVar7 = *puVar6;
                puVar6 = puVar6 + 1;
                *puVar10 = uVar7;
                puVar10 = puVar10 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            break;
          case 2:
            iVar4 = (*(ushort *)(param_2 + iVar2 + 4) >> 8 & 3) + 1;
            if (iVar4 != 0) {
              puVar6 = (undefined4 *)(param_4 + (*(ushort *)(param_2 + iVar2 + 4) & 0x3f) * 4);
              puVar10 = (undefined4 *)(param_5 + 0x30);
              do {
                uVar7 = *puVar6;
                puVar6 = puVar6 + 1;
                *puVar10 = uVar7;
                puVar10 = puVar10 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            break;
          case 3:
            *(undefined4 *)(param_5 + 0x4c) =
                 *(undefined4 *)(param_4 + (*(ushort *)(param_2 + iVar2 + 4) & 0x3f) * 4);
            break;
          case 4:
            iVar4 = (*(ushort *)(param_2 + iVar2 + 4) >> 8 & 3) + 1;
            if (iVar4 != 0) {
              puVar6 = (undefined4 *)(param_4 + (*(ushort *)(param_2 + iVar2 + 4) & 0x3f) * 4);
              puVar10 = (undefined4 *)(param_5 + 0x50);
              do {
                uVar7 = *puVar6;
                puVar6 = puVar6 + 1;
                *puVar10 = uVar7;
                puVar10 = puVar10 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            break;
          case 5:
            iVar4 = (*(ushort *)(param_2 + iVar2 + 4) >> 8 & 3) + 1;
            if (iVar4 != 0) {
              puVar6 = (undefined4 *)(param_4 + (*(ushort *)(param_2 + iVar2 + 4) & 0x3f) * 4);
              puVar10 = (undefined4 *)(param_5 + 0x60);
              do {
                uVar7 = *puVar6;
                puVar6 = puVar6 + 1;
                *puVar10 = uVar7;
                puVar10 = puVar10 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            break;
          case 6:
            uVar3 = *(ushort *)(param_2 + iVar2 + 4) >> 6 & 3;
            iVar2 = (*(ushort *)(param_2 + iVar2 + 4) & 0x3f) * 4;
            if (uVar3 == 1) {
              uVar5 = *(undefined1 *)(param_4 + iVar2);
            }
            else {
              if (uVar3 != 3) break;
              uVar5 = *(undefined1 *)(param_4 + iVar2 + 3);
            }
            *(undefined1 *)(param_5 + 0x7c) = uVar5;
            break;
          case 8:
          case 9:
          case 10:
          case 0xb:
          case 0xc:
          case 0xd:
          case 0xe:
          case 0xf:
            iVar4 = (*(ushort *)(param_2 + iVar2 + 4) >> 8 & 3) + 1;
            if (iVar4 != 0) {
              puVar10 = (undefined4 *)
                        (((*(ushort *)(param_2 + iVar2 + 4) >> 10) - 8) * 0x10 + param_5 + 0x80);
              puVar6 = (undefined4 *)(param_4 + (*(ushort *)(param_2 + iVar2 + 4) & 0x3f) * 4);
              do {
                uVar7 = *puVar6;
                puVar6 = puVar6 + 1;
                *puVar10 = uVar7;
                puVar10 = puVar10 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)(uint)bVar1);
      }
      iVar8 = iVar8 + 1;
      param_5 = param_5 + 0x100;
      param_4 = param_4 + (uint)param_2[2] * 4;
    } while (iVar8 < (int)param_3);
  }
  return;
}

/* _gleVPSetFuncOutputDesc @ 0xb49f0 (548 bytes) */
int _gleVPSetFuncOutputDesc(param_1, param_2, param_3, param_4)
  int param_1;
  uint param_2;
  uint *param_3;
  int param_4;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  uVar1 = (param_2 & 0x3f) << 10 | 0x200000;
  *param_3 = uVar1;
  uVar3 = param_2;
  if (param_4 != 0) {
    uVar3 = param_2 + 1;
  }
  iVar6 = 0;
  *param_3 = uVar1 | uVar3 << 0x18;
  iVar4 = 0;
  uVar1 = param_2;
  if (0 < (int)param_2) {
    do {
      uVar5 = *(uint *)(iVar6 * 8 + param_1);
      if (((uVar5 >> 0x10 & 0xf) == 1) || ((uVar5 & 0xf001f) == 0x90000)) {
        iVar4 = iVar4 + 1;
      }
      iVar6 = iVar6 + 1;
      uVar1 = uVar1 - 1;
    } while (uVar1 != 0);
  }
  iVar7 = 0;
  iVar6 = 0;
  if (0 < (int)param_2) {
    do {
      uVar1 = *(uint *)(iVar7 * 8 + param_1);
      switch(uVar1 >> 0x10 & 0xf) {
      default:
        iVar8 = 0x2e;
        break;
      case 1:
        iVar8 = 0;
LAB_000b4b78:
        iVar9 = iVar6 + 1;
        iVar2 = iVar6;
        goto LAB_000b4c00;
      case 2:
        iVar8 = 2;
        break;
      case 3:
        iVar8 = 4;
        break;
      case 4:
        iVar8 = 1;
        break;
      case 5:
        iVar8 = 3;
        break;
      case 6:
        iVar8 = 5;
        break;
      case 7:
        iVar8 = (uVar1 & 0x1f) + 8;
        break;
      case 9:
        iVar8 = (uVar1 & 0x1f) + 0x10;
        if ((uVar1 & 0x1f) == 0) goto LAB_000b4b78;
        break;
      case 10:
        iVar8 = 0x2e;
        uVar5 = uVar1 & 1;
        switch(uVar1 >> 0xc & 0xf) {
        case 0:
          iVar8 = uVar5 + 0x20;
          break;
        case 1:
          iVar8 = uVar5 + 0x22;
          break;
        case 2:
          iVar8 = uVar5 + 0x24;
          break;
        case 3:
          iVar8 = uVar5 + 0x26;
          break;
        case 4:
          iVar8 = uVar5 + 0x28;
        }
      }
      iVar2 = iVar4;
      iVar4 = iVar4 + 1;
      iVar9 = iVar6;
LAB_000b4c00:
      iVar6 = iVar7 << 4;
      iVar7 = iVar7 + 1;
      *(ushort *)((int)param_3 + iVar2 * 2 + 4) =
           (ushort)(iVar8 << 10) | (ushort)(iVar6 >> 2) | 0x300;
      iVar6 = iVar9;
    } while (iVar7 < (int)param_2);
  }
  if ((int)param_2 < (int)uVar3) {
    *(ushort *)((int)param_3 + iVar4 * 2 + 4) = (ushort)((iVar7 << 4) >> 2) | 0x1b00;
  }
  return;
}

/* _glePPSetFuncNeeds @ 0xb4c54 (160 bytes) */
int _glePPSetFuncNeeds(param_1, param_2)
  int param_1;
  uint param_2;
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  uVar3 = 0;
  if (param_2 != 0) {
    do {
      uVar2 = *(uint *)(uVar3 * 8 + param_1);
      switch(uVar2 >> 0x10 & 0xf) {
      case 2:
        uVar1 = uVar1 | 0x100;
        break;
      case 3:
        uVar1 = uVar1 | 0x200;
        break;
      case 5:
        uVar1 = uVar1 | 0x400;
        break;
      case 7:
        uVar1 = uVar1 | 1 << (uVar2 & 0x1f);
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < param_2);
  }
  return uVar1;
}

/* _gleSetFunctionIDFromList @ 0xb4d14 (408 bytes) */
int _gleSetFunctionIDFromList(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  ushort *puVar5;
  byte *pbVar6;
  ushort uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int local_90 [31];
  int local_14;
  
  uVar2 = *param_3;
  iVar10 = *(int *)(param_1 + 0x4674);
  piVar8 = local_90 + 1;
  uVar3 = uVar2 | 0x70000;
  *param_3 = uVar3;
  local_90[1] = 0;
  *param_3 = uVar3 | *(uint *)(param_2 + 8) >> 2 & 0xff;
  uVar2 = uVar2 >> 0x18;
  pbVar6 = (byte *)(param_2 + 0xd);
  iVar11 = 0x1e;
  do {
    bVar1 = *pbVar6;
    pbVar6 = pbVar6 + 1;
    iVar4 = *piVar8;
    piVar8 = piVar8 + 1;
    *piVar8 = iVar4 + (uint)bVar1;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  local_90[0] = local_14 + (uint)*(byte *)(param_2 + 0x2b);
  if (uVar2 == 0) {
    return;
  }
  puVar5 = (ushort *)((int)param_3 + uVar2 * 2 + 4);
  do {
    uVar7 = *(ushort *)(param_3 + 1);
    iVar11 = 0xe;
    uVar3 = (uint)(uVar7 >> 10);
    if ((uVar3 == 0) || (uVar3 == 0x10)) {
      uVar9 = (uint)*(byte *)(param_2 + uVar3 + 0xc);
      if (uVar9 == 0) {
        if (*(byte *)(param_2 + 0xc) == 0) {
          if (*(byte *)(param_2 + 0x1c) == 0) goto LAB_000b4e5c;
          uVar9 = (int)(uint)*(byte *)(param_2 + 0x1c) >> 2;
          uVar3 = 0x10;
          *(ushort *)(param_3 + 1) = uVar7 & 0x3ff | 0x4000;
        }
        else {
          uVar9 = (int)(uint)*(byte *)(param_2 + 0xc) >> 2;
          *(ushort *)(param_3 + 1) = uVar7 & 0x3ff;
          uVar3 = 0;
        }
      }
      else {
        uVar9 = (int)uVar9 >> 2;
      }
      iVar11 = 6;
LAB_000b4e60:
      uVar7 = (ushort)local_90[uVar3];
    }
    else {
      if (((uVar3 - 1 < 6) || (uVar3 - 8 < 8)) || (uVar3 - 0x11 < 0xf)) {
        uVar9 = (uint)*(byte *)(param_2 + uVar3 + 0xc);
        if (uVar9 == 0) {
LAB_000b4e5c:
          uVar9 = (uint)*(byte *)(iVar10 + 0x400 + uVar3);
        }
        else {
          uVar9 = (int)uVar9 >> 2;
          iVar11 = 5 - ((int)-(uVar3 ^ 6) >> 0x1f);
        }
        goto LAB_000b4e60;
      }
      uVar9 = (uint)(7 < uVar3 - 0x20);
      uVar7 = 0;
    }
    param_3 = (uint *)((int)param_3 + 2);
    *puVar5 = (short)(uVar9 - 1) * 0x4000 | (ushort)(iVar11 << 10) | uVar7;
    puVar5 = puVar5 + 1;
    uVar2 = uVar2 - 1;
    if (uVar2 == 0) {
      return;
    }
  } while( true );
}

/* _gleSetFunctionIDToList @ 0xb4eac (508 bytes) */
int _gleSetFunctionIDToList(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  short sVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ushort *puVar9;
  int iVar10;
  uint *puVar11;
  int iVar12;
  longlong lVar13;
  
  *param_3 = 0;
  if (*(char *)(param_2 + 0x31c) != '\0') {
    *param_3 = 0x800000;
  }
  uVar7 = *(uint *)(param_2 + 0x300);
  iVar10 = 0;
  iVar12 = 0;
  uVar4 = *(uint *)(param_2 + 0x304) & 0xff7fffff;
  do {
    lVar13 = ___ashldi3(0,1,iVar12 + 0x10);
    if ((uVar7 & (uint)((ulonglong)lVar13 >> 0x20)) != 0 || (uVar4 & (uint)lVar13) != 0) {
      iVar10 = iVar10 + 1;
    }
    iVar12 = iVar12 + 1;
  } while (iVar12 < 0x20);
  *param_3 = *param_3 | iVar10 << 0x18;
  iVar12 = *(int *)(param_1 + 0x48dc);
  uVar5 = iVar12 - 0x1400;
  if (((6 < uVar5) && (uVar5 = 7, iVar12 != 0x140a)) &&
     (uVar5 = iVar12 - 0x93f8, 5 < iVar12 - 0x9400U)) {
    uVar5 = 0xe;
  }
  puVar9 = (ushort *)((int)param_3 + iVar10 * 2 + 4);
  *param_3 = *param_3 | (uVar5 & 0xf) << 0x10;
  uVar5 = 0;
  iVar10 = 1;
  puVar11 = param_3 + 1;
  while( true ) {
    lVar13 = ___ashldi3(0,1,iVar10 + 0x10);
    if ((uVar7 & (uint)((ulonglong)lVar13 >> 0x20)) != 0 || (uVar4 & (uint)lVar13) != 0) {
      iVar12 = iVar10 * 0x18 + param_2;
      uVar8 = (uint)*(ushort *)(iVar12 + 8);
      uVar6 = uVar8 - 0x1400;
      sVar1 = *(short *)(iVar12 + 10);
      if (((6 < uVar6) && (uVar6 = 7, uVar8 != 0x140a)) &&
         (uVar6 = uVar8 - 0x93f8, 5 < uVar8 - 0x9400)) {
        uVar6 = 0xe;
      }
      sVar3 = (short)(sVar1 + -1);
      *puVar9 = sVar3 * 0x4000 | (ushort)(uVar6 << 10) | (ushort)*(undefined4 *)(iVar12 + 4);
      uVar2 = (ushort)((int)uVar5 >> 2);
      if (iVar10 == 6) {
        *(ushort *)puVar11 = sVar3 * 0x100 | 0x1800U | uVar2 | 0xc0;
      }
      else {
        *(ushort *)puVar11 = (ushort)(iVar10 << 10) | sVar3 * 0x100 | uVar2;
      }
      puVar9 = puVar9 + 1;
      uVar5 = uVar5 + sVar1 * 4;
      puVar11 = (uint *)((int)puVar11 + 2);
    }
    if (iVar10 == 0) break;
    if (iVar10 < 0x1f) {
      iVar10 = iVar10 + 1;
    }
    else {
      iVar10 = 0;
    }
  }
  *param_3 = *param_3 | (uVar5 & 0x3fc) << 6;
  return;
}

/* _gleRTCAddAChunk_b50a8 @ 0xb50a8 (48 bytes) */
int _gleRTCAddAChunk_b50a8(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = *param_1;
  while (iVar1 != 0) {
    *param_2 = iVar1;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    iVar1 = *param_1;
  }
  return iVar2;
}

/* _gleArrayElemAddPrimitiveFlushFuncCall @ 0xb50d8 (104 bytes) */
int _gleArrayElemAddPrimitiveFlushFuncCall(param_1, param_2)
  uint *param_1;
  uint param_2;
{
  *param_1 = param_2 & 0xffff | 0x39250000;
  param_1[1] = 0x91234858;
  param_1[2] = 0x7d254b78;
  param_1[3] = 0x8103485c;
  param_1[4] = 0x81234a0c;
  param_1[5] = 0x7d2903a6;
  param_1[6] = 0x7c054000;
  param_1[7] = 0x4d828c21;
  return param_1 + 8;
}

/* _gleSetVertexEval1Func @ 0xb5140 (100 bytes) */
int _gleSetVertexEval1Func(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = (undefined4 *)(*_gleBuildVertexFunc)(param_1,2,param_3);
  UNRECOVERED_JUMPTABLE = (code *)*puVar1;
  *(code **)(param_1 + 0x4898) = UNRECOVERED_JUMPTABLE;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3);
  return;
}

/* _gleSetVertexEval2Func @ 0xb51a4 (100 bytes) */
int _gleSetVertexEval2Func(param_1, param_2, param_3)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  undefined4 *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = (undefined4 *)(*_gleBuildVertexFunc)(param_1,2,param_3);
  UNRECOVERED_JUMPTABLE = (code *)*puVar1;
  *(code **)(param_1 + 0x489c) = UNRECOVERED_JUMPTABLE;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,param_2,param_3);
  return;
}

/* _gleGetVertexElemFunc @ 0xb5208 (68 bytes) */
int _gleGetVertexElemFunc(param_1)
  undefined4 param_1;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*_gleBuildVertexFunc)(param_1,4);
  return *puVar1;
}

/* _gleGetVertexToListFunc @ 0xb524c (68 bytes) */
int _gleGetVertexToListFunc(param_1)
  undefined4 param_1;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*_gleBuildVertexFunc)(param_1,3);
  return *puVar1;
}

/* _gleLoadDataElementFromMatNO @ 0xb5290 (256 bytes) */
int _gleLoadDataElementFromMatNO(param_1, param_2, param_3, param_4, param_5)
  uint *param_1;
  int param_2;
  int param_3;
  uint param_4;
  int param_5;
{
  uint uVar1;
  
  if (param_3 == 4) {
    if (param_2 == 1) {
      uVar1 = (param_5 + 0xb) * 0x10000 | param_4 & 0xffff | 0xc0200000;
    }
    else {
      if (param_2 < 2) {
        return param_1;
      }
      uVar1 = (param_5 + 0xb) * 0x10000;
      *param_1 = uVar1 | param_4 & 0xffff | 0xc8200000;
      param_1 = param_1 + 1;
      if (param_2 == 3) {
        uVar1 = uVar1 | param_4 + 8 & 0xffff | 0xc0600000;
      }
      else {
        if (param_2 != 4) {
          return param_1;
        }
        uVar1 = uVar1 | param_4 + 8 & 0xffff | 0xc8600000;
      }
    }
  }
  else {
    uVar1 = (param_5 + 0xb) * 0x10000;
    *param_1 = uVar1 | param_4 & 0xffff | 0xc0200000;
    if (param_2 < 2) {
      return param_1 + 1;
    }
    param_1[1] = uVar1 | param_4 + 4 & 0xffff | 0xc0400000;
    if (param_2 < 3) {
      return param_1 + 2;
    }
    param_1[2] = uVar1 | param_4 + 8 & 0xffff | 0xc0600000;
    param_1 = param_1 + 3;
    if (param_2 != 4) {
      return param_1;
    }
    uVar1 = uVar1 | param_4 + 0xc & 0xffff | 0xc0800000;
  }
  *param_1 = uVar1;
  return param_1 + 1;
}

/* _gleInterpolEyeNO0000 @ 0xb5390 (448 bytes) */
void _gleInterpolEyeNO0000(int param_1,float *param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
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
  uint uVar12;
  
  fVar11 = param_2[0xb];
  fVar2 = *(float *)(param_3 + 0x2c);
  fVar3 = param_2[9];
  fVar4 = param_2[10];
  uVar12 = 0;
  fVar5 = *(float *)(param_3 + 0x24);
  fVar6 = *(float *)(param_3 + 0x28);
  fVar7 = param_2[4];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar2 - (double)fVar11) + (double)fVar11
                        );
  fVar2 = param_2[5];
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = param_2[6];
  fVar11 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar7) + (double)fVar7);
  fVar7 = *(float *)(param_3 + 0x18);
  fVar8 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar3) + (double)fVar3);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[4] = fVar11;
  fVar2 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar2) + (double)fVar2);
  param_4[7] = fVar1;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar10) + (double)fVar10);
  param_4[5] = fVar2;
  param_4[6] = fVar3;
  if (fVar11 < fVar8) {
    uVar12 = 0x10;
  }
  if (fVar1 <= fVar11) {
    uVar12 = uVar12 | 0x20;
  }
  if (fVar2 < fVar8) {
    uVar12 = uVar12 | 4;
  }
  if (fVar1 <= fVar2) {
    uVar12 = uVar12 | 8;
  }
  if (fVar3 < fVar8) {
    uVar12 = uVar12 | 1;
  }
  if (fVar1 < fVar3) {
    uVar12 = uVar12 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar12 | 0x10000)));
  if (uVar12 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar11 = fVar11 * fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar11 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar2 + *(float *)(param_1 + 0x1b84);
    fVar11 = *(float *)(param_1 + 0x1b88);
    fVar2 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar1;
    param_4[2] = fVar2 * fVar3 + fVar11;
  }
  if (param_2 == param_4) {
    return;
  }
  *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
  *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
  *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
  fVar1 = param_2[0x12];
  param_4[0x1d] = param_2[0x1d];
  fVar11 = param_2[0x1e];
  param_4[0x12] = fVar1;
  param_4[0x1e] = fVar11;
  return;
}

/* _gleInterpolEyeNO0010 @ 0xb5550 (468 bytes) */
void _gleInterpolEyeNO0010(int param_1,float *param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
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
  uint uVar12;
  
  fVar11 = param_2[0xb];
  fVar2 = *(float *)(param_3 + 0x2c);
  fVar3 = param_2[9];
  fVar4 = param_2[10];
  uVar12 = 0;
  fVar5 = *(float *)(param_3 + 0x24);
  fVar6 = *(float *)(param_3 + 0x28);
  fVar7 = param_2[4];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar2 - (double)fVar11) + (double)fVar11
                        );
  fVar2 = param_2[5];
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = param_2[6];
  fVar11 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar7) + (double)fVar7);
  fVar7 = *(float *)(param_3 + 0x18);
  fVar8 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar3) + (double)fVar3);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[4] = fVar11;
  fVar2 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar2) + (double)fVar2);
  param_4[7] = fVar1;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar10) + (double)fVar10);
  param_4[5] = fVar2;
  param_4[6] = fVar3;
  if (fVar11 < fVar8) {
    uVar12 = 0x10;
  }
  if (fVar1 <= fVar11) {
    uVar12 = uVar12 | 0x20;
  }
  if (fVar2 < fVar8) {
    uVar12 = uVar12 | 4;
  }
  if (fVar1 <= fVar2) {
    uVar12 = uVar12 | 8;
  }
  if (fVar3 < fVar8) {
    uVar12 = uVar12 | 1;
  }
  if (fVar1 < fVar3) {
    uVar12 = uVar12 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar12 | 0x10000)));
  if (uVar12 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar11 = fVar11 * fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar11 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar2 + *(float *)(param_1 + 0x1b84);
    fVar11 = *(float *)(param_1 + 0x1b88);
    fVar2 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar1;
    param_4[2] = fVar2 * fVar3 + fVar11;
  }
  param_4[0x13] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x4c) - (double)param_2[0x13]) +
              (double)param_2[0x13]);
  if (param_2 == param_4) {
    return;
  }
  *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
  *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
  *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
  fVar1 = param_2[0x12];
  param_4[0x1d] = param_2[0x1d];
  fVar11 = param_2[0x1e];
  param_4[0x12] = fVar1;
  param_4[0x1e] = fVar11;
  return;
}

/* _gleInterpolEyeNO0100 @ 0xb5724 (616 bytes) */
void _gleInterpolEyeNO0100(int param_1,float *param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  char cVar2;
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
  uint uVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  
  fVar12 = param_2[0xb];
  fVar3 = *(float *)(param_3 + 0x2c);
  fVar4 = param_2[9];
  fVar5 = param_2[10];
  uVar13 = 0;
  fVar6 = *(float *)(param_3 + 0x24);
  fVar7 = *(float *)(param_3 + 0x28);
  fVar8 = param_2[4];
  fVar9 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar12) + (double)fVar12
                        );
  fVar3 = param_2[5];
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = param_2[6];
  fVar12 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar8) + (double)fVar8);
  fVar8 = *(float *)(param_3 + 0x18);
  fVar9 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[4] = fVar12;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar3) + (double)fVar3);
  param_4[7] = fVar1;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar11) + (double)fVar11);
  cVar2 = *(char *)((int)param_2 + 0x7f);
  param_4[5] = fVar3;
  param_4[6] = fVar4;
  if (fVar12 < fVar9) {
    uVar13 = 0x10;
  }
  if (fVar1 <= fVar12) {
    uVar13 = uVar13 | 0x20;
  }
  if (fVar3 < fVar9) {
    uVar13 = uVar13 | 4;
  }
  if (fVar1 <= fVar3) {
    uVar13 = uVar13 | 8;
  }
  if (fVar4 < fVar9) {
    uVar13 = uVar13 | 1;
  }
  if (fVar1 < fVar4) {
    uVar13 = uVar13 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar13 | 0x10000)));
  if (uVar13 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar12 = fVar12 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar12 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar3 + *(float *)(param_1 + 0x1b84);
    fVar12 = *(float *)(param_1 + 0x1b88);
    fVar3 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar1;
    param_4[2] = fVar3 * fVar4 + fVar12;
  }
  dVar16 = (double)param_2[0x20];
  dVar18 = (double)param_2[0x21];
  dVar17 = (double)param_2[0x22];
  dVar22 = (double)param_2[0x23];
  if (cVar2 == '\0') {
    dVar14 = (double)param_2[7];
    dVar22 = (double)(float)(dVar22 * dVar14);
    dVar16 = (double)(float)(dVar16 * dVar14);
    dVar18 = (double)(float)(dVar18 * dVar14);
    dVar17 = (double)(float)(dVar17 * dVar14);
  }
  dVar14 = (double)*(float *)(param_3 + 0x80);
  dVar21 = (double)*(float *)(param_3 + 0x84);
  dVar19 = (double)*(float *)(param_3 + 0x88);
  dVar20 = (double)*(float *)(param_3 + 0x8c);
  if (*(char *)(param_3 + 0x7f) == '\0') {
    dVar15 = (double)*(float *)(param_3 + 0x1c);
    dVar20 = (double)(float)(dVar20 * dVar15);
    dVar14 = (double)(float)(dVar14 * dVar15);
    dVar21 = (double)(float)(dVar21 * dVar15);
    dVar19 = (double)(float)(dVar19 * dVar15);
  }
  fVar1 = (float)(fparam_1 * (double)(float)(dVar14 - dVar16) + dVar16);
  fVar12 = (float)(fparam_1 * (double)(float)(dVar21 - dVar18) + dVar18);
  fVar3 = (float)(fparam_1 * (double)(float)(dVar20 - dVar22) + dVar22);
  fVar4 = (float)(fparam_1 * (double)(float)(dVar19 - dVar17) + dVar17);
  if (uVar13 == 0) {
    fVar5 = param_4[3];
    fVar3 = fVar3 * fVar5;
    fVar1 = fVar1 * fVar5;
    fVar12 = fVar12 * fVar5;
    fVar4 = fVar4 * fVar5;
  }
  param_4[0x20] = fVar1;
  param_4[0x21] = fVar12;
  param_4[0x22] = fVar4;
  param_4[0x23] = fVar3;
  if (param_2 == param_4) {
    return;
  }
  *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
  *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
  *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
  fVar1 = param_2[0x12];
  param_4[0x1d] = param_2[0x1d];
  fVar12 = param_2[0x1e];
  param_4[0x12] = fVar1;
  param_4[0x1e] = fVar12;
  return;
}

/* _gleInterpolEyeNO0100w @ 0xb598c (528 bytes) */
void _gleInterpolEyeNO0100w(int param_1,float *param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
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
  uint uVar12;
  
  fVar11 = param_2[0xb];
  fVar2 = *(float *)(param_3 + 0x2c);
  fVar3 = param_2[9];
  fVar4 = param_2[10];
  uVar12 = 0;
  fVar5 = *(float *)(param_3 + 0x24);
  fVar6 = *(float *)(param_3 + 0x28);
  fVar7 = param_2[4];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar2 - (double)fVar11) + (double)fVar11
                        );
  fVar2 = param_2[5];
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = param_2[6];
  fVar11 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar7) + (double)fVar7);
  fVar7 = *(float *)(param_3 + 0x18);
  fVar8 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar3) + (double)fVar3);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[4] = fVar11;
  fVar2 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar2) + (double)fVar2);
  param_4[7] = fVar1;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar10) + (double)fVar10);
  param_4[5] = fVar2;
  param_4[6] = fVar3;
  if (fVar11 < fVar8) {
    uVar12 = 0x10;
  }
  if (fVar1 <= fVar11) {
    uVar12 = uVar12 | 0x20;
  }
  if (fVar2 < fVar8) {
    uVar12 = uVar12 | 4;
  }
  if (fVar1 <= fVar2) {
    uVar12 = uVar12 | 8;
  }
  if (fVar3 < fVar8) {
    uVar12 = uVar12 | 1;
  }
  if (fVar1 < fVar3) {
    uVar12 = uVar12 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar12 | 0x10000)));
  if (uVar12 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar11 = fVar11 * fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar11 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar2 + *(float *)(param_1 + 0x1b84);
    fVar11 = *(float *)(param_1 + 0x1b88);
    fVar2 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar1;
    param_4[2] = fVar2 * fVar3 + fVar11;
  }
  fVar1 = param_2[0x21];
  fVar11 = param_2[0x22];
  fVar2 = param_2[0x23];
  fVar3 = *(float *)(param_3 + 0x8c);
  fVar4 = *(float *)(param_3 + 0x84);
  fVar5 = *(float *)(param_3 + 0x88);
  param_4[0x20] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x80) - (double)param_2[0x20]) +
              (double)param_2[0x20]);
  param_4[0x23] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar2) + (double)fVar2)
  ;
  param_4[0x21] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1)
  ;
  param_4[0x22] =
       (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar11) + (double)fVar11);
  if (param_2 == param_4) {
    return;
  }
  *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
  *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
  *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
  fVar1 = param_2[0x12];
  param_4[0x1d] = param_2[0x1d];
  fVar11 = param_2[0x1e];
  param_4[0x12] = fVar1;
  param_4[0x1e] = fVar11;
  return;
}

/* _gleInterpolEyeNO0110 @ 0xb5b9c (636 bytes) */
void _gleInterpolEyeNO0110(int param_1,float *param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  char cVar2;
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
  uint uVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  
  fVar12 = param_2[0xb];
  fVar3 = *(float *)(param_3 + 0x2c);
  fVar4 = param_2[9];
  fVar5 = param_2[10];
  uVar13 = 0;
  fVar6 = *(float *)(param_3 + 0x24);
  fVar7 = *(float *)(param_3 + 0x28);
  fVar8 = param_2[4];
  fVar9 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar12) + (double)fVar12
                        );
  fVar3 = param_2[5];
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = param_2[6];
  fVar12 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar8) + (double)fVar8);
  fVar8 = *(float *)(param_3 + 0x18);
  fVar9 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[4] = fVar12;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar3) + (double)fVar3);
  param_4[7] = fVar1;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar11) + (double)fVar11);
  cVar2 = *(char *)((int)param_2 + 0x7f);
  param_4[5] = fVar3;
  param_4[6] = fVar4;
  if (fVar12 < fVar9) {
    uVar13 = 0x10;
  }
  if (fVar1 <= fVar12) {
    uVar13 = uVar13 | 0x20;
  }
  if (fVar3 < fVar9) {
    uVar13 = uVar13 | 4;
  }
  if (fVar1 <= fVar3) {
    uVar13 = uVar13 | 8;
  }
  if (fVar4 < fVar9) {
    uVar13 = uVar13 | 1;
  }
  if (fVar1 < fVar4) {
    uVar13 = uVar13 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar13 | 0x10000)));
  if (uVar13 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar12 = fVar12 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar12 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar3 + *(float *)(param_1 + 0x1b84);
    fVar12 = *(float *)(param_1 + 0x1b88);
    fVar3 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar1;
    param_4[2] = fVar3 * fVar4 + fVar12;
  }
  param_4[0x13] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x4c) - (double)param_2[0x13]) +
              (double)param_2[0x13]);
  dVar16 = (double)param_2[0x20];
  dVar17 = (double)param_2[0x21];
  dVar18 = (double)param_2[0x22];
  dVar22 = (double)param_2[0x23];
  if (cVar2 == '\0') {
    dVar14 = (double)param_2[7];
    dVar22 = (double)(float)(dVar22 * dVar14);
    dVar16 = (double)(float)(dVar16 * dVar14);
    dVar17 = (double)(float)(dVar17 * dVar14);
    dVar18 = (double)(float)(dVar18 * dVar14);
  }
  dVar14 = (double)*(float *)(param_3 + 0x80);
  dVar20 = (double)*(float *)(param_3 + 0x84);
  dVar21 = (double)*(float *)(param_3 + 0x88);
  dVar19 = (double)*(float *)(param_3 + 0x8c);
  if (*(char *)(param_3 + 0x7f) == '\0') {
    dVar15 = (double)*(float *)(param_3 + 0x1c);
    dVar19 = (double)(float)(dVar19 * dVar15);
    dVar14 = (double)(float)(dVar14 * dVar15);
    dVar20 = (double)(float)(dVar20 * dVar15);
    dVar21 = (double)(float)(dVar21 * dVar15);
  }
  fVar1 = (float)(fparam_1 * (double)(float)(dVar14 - dVar16) + dVar16);
  fVar12 = (float)(fparam_1 * (double)(float)(dVar20 - dVar17) + dVar17);
  fVar3 = (float)(fparam_1 * (double)(float)(dVar19 - dVar22) + dVar22);
  fVar4 = (float)(fparam_1 * (double)(float)(dVar21 - dVar18) + dVar18);
  if (uVar13 == 0) {
    fVar5 = param_4[3];
    fVar3 = fVar3 * fVar5;
    fVar1 = fVar1 * fVar5;
    fVar12 = fVar12 * fVar5;
    fVar4 = fVar4 * fVar5;
  }
  param_4[0x20] = fVar1;
  param_4[0x21] = fVar12;
  param_4[0x22] = fVar4;
  param_4[0x23] = fVar3;
  if (param_2 == param_4) {
    return;
  }
  *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
  *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
  *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
  fVar1 = param_2[0x12];
  param_4[0x1d] = param_2[0x1d];
  fVar12 = param_2[0x1e];
  param_4[0x12] = fVar1;
  param_4[0x1e] = fVar12;
  return;
}

/* _gleInterpolEyeNO0110w @ 0xb5e18 (548 bytes) */
void _gleInterpolEyeNO0110w(int param_1,float *param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
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
  uint uVar12;
  
  fVar11 = param_2[0xb];
  fVar2 = *(float *)(param_3 + 0x2c);
  fVar3 = param_2[9];
  fVar4 = param_2[10];
  uVar12 = 0;
  fVar5 = *(float *)(param_3 + 0x24);
  fVar6 = *(float *)(param_3 + 0x28);
  fVar7 = param_2[4];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar2 - (double)fVar11) + (double)fVar11
                        );
  fVar2 = param_2[5];
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = param_2[6];
  fVar11 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar7) + (double)fVar7);
  fVar7 = *(float *)(param_3 + 0x18);
  fVar8 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar3) + (double)fVar3);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[4] = fVar11;
  fVar2 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar2) + (double)fVar2);
  param_4[7] = fVar1;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar10) + (double)fVar10);
  param_4[5] = fVar2;
  param_4[6] = fVar3;
  if (fVar11 < fVar8) {
    uVar12 = 0x10;
  }
  if (fVar1 <= fVar11) {
    uVar12 = uVar12 | 0x20;
  }
  if (fVar2 < fVar8) {
    uVar12 = uVar12 | 4;
  }
  if (fVar1 <= fVar2) {
    uVar12 = uVar12 | 8;
  }
  if (fVar3 < fVar8) {
    uVar12 = uVar12 | 1;
  }
  if (fVar1 < fVar3) {
    uVar12 = uVar12 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar12 | 0x10000)));
  if (uVar12 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar11 = fVar11 * fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar11 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar2 + *(float *)(param_1 + 0x1b84);
    fVar11 = *(float *)(param_1 + 0x1b88);
    fVar2 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar1;
    param_4[2] = fVar2 * fVar3 + fVar11;
  }
  param_4[0x13] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x4c) - (double)param_2[0x13]) +
              (double)param_2[0x13]);
  fVar1 = param_2[0x21];
  fVar11 = param_2[0x22];
  fVar2 = param_2[0x23];
  fVar3 = *(float *)(param_3 + 0x8c);
  fVar4 = *(float *)(param_3 + 0x84);
  fVar5 = *(float *)(param_3 + 0x88);
  param_4[0x20] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x80) - (double)param_2[0x20]) +
              (double)param_2[0x20]);
  param_4[0x21] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1)
  ;
  param_4[0x23] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar2) + (double)fVar2)
  ;
  param_4[0x22] =
       (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar11) + (double)fVar11);
  if (param_2 == param_4) {
    return;
  }
  *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
  *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
  *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
  fVar1 = param_2[0x12];
  param_4[0x1d] = param_2[0x1d];
  fVar11 = param_2[0x1e];
  param_4[0x12] = fVar1;
  param_4[0x1e] = fVar11;
  return;
}

/* _gleInterpolEyeNO0200 @ 0xb603c (672 bytes) */
void _gleInterpolEyeNO0200(int param_1,float *param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  uint uVar12;
  int iVar13;
  float fVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  
  fVar14 = param_2[0xb];
  fVar3 = *(float *)(param_3 + 0x2c);
  fVar4 = param_2[9];
  fVar5 = param_2[10];
  uVar16 = 0;
  fVar6 = *(float *)(param_3 + 0x24);
  fVar7 = *(float *)(param_3 + 0x28);
  fVar8 = param_2[4];
  fVar9 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar14) + (double)fVar14
                        );
  fVar3 = param_2[5];
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = param_2[6];
  fVar14 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar8) + (double)fVar8);
  fVar8 = *(float *)(param_3 + 0x18);
  fVar9 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[4] = fVar14;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar3) + (double)fVar3);
  param_4[7] = fVar1;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar11) + (double)fVar11);
  cVar2 = *(char *)((int)param_2 + 0x7f);
  param_4[5] = fVar3;
  param_4[6] = fVar4;
  if (fVar14 < fVar9) {
    uVar16 = 0x10;
  }
  if (fVar1 <= fVar14) {
    uVar16 = uVar16 | 0x20;
  }
  if (fVar3 < fVar9) {
    uVar16 = uVar16 | 4;
  }
  if (fVar1 <= fVar3) {
    uVar16 = uVar16 | 8;
  }
  if (fVar4 < fVar9) {
    uVar16 = uVar16 | 1;
  }
  if (fVar1 < fVar4) {
    uVar16 = uVar16 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar16 | 0x10000)));
  if (uVar16 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar14 = fVar14 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar14 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar3 + *(float *)(param_1 + 0x1b84);
    fVar14 = *(float *)(param_1 + 0x1b78);
    fVar3 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar1;
    param_4[2] = fVar14 * fVar4 + fVar3;
  }
  uVar15 = *(uint *)(param_1 + 0x5150);
  uVar17 = 0;
  do {
    uVar12 = uVar15 >> (uVar17 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        if (param_2 == param_4) {
          return;
        }
        *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
        *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
        *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
        fVar1 = param_2[0x12];
        param_4[0x1d] = param_2[0x1d];
        fVar14 = param_2[0x1e];
        param_4[0x12] = fVar1;
        param_4[0x1e] = fVar14;
        return;
      }
    }
    else {
      dVar26 = (double)param_2[uVar17 * 4 + 0x23];
      dVar20 = (double)param_2[uVar17 * 4 + 0x20];
      dVar21 = (double)param_2[uVar17 * 4 + 0x21];
      dVar22 = (double)param_2[uVar17 * 4 + 0x22];
      if (cVar2 == '\0') {
        dVar18 = (double)param_2[7];
        dVar26 = (double)(float)(dVar26 * dVar18);
        dVar20 = (double)(float)(dVar20 * dVar18);
        dVar21 = (double)(float)(dVar21 * dVar18);
        dVar22 = (double)(float)(dVar22 * dVar18);
      }
      iVar13 = uVar17 * 0x10 + param_3;
      dVar23 = (double)*(float *)(iVar13 + 0x8c);
      dVar18 = (double)*(float *)(iVar13 + 0x80);
      dVar25 = (double)*(float *)(iVar13 + 0x84);
      dVar24 = (double)*(float *)(iVar13 + 0x88);
      if (*(char *)(param_3 + 0x7f) == '\0') {
        dVar19 = (double)*(float *)(param_3 + 0x1c);
        dVar23 = (double)(float)(dVar23 * dVar19);
        dVar18 = (double)(float)(dVar18 * dVar19);
        dVar25 = (double)(float)(dVar25 * dVar19);
        dVar24 = (double)(float)(dVar24 * dVar19);
      }
      fVar1 = (float)(fparam_1 * (double)(float)(dVar18 - dVar20) + dVar20);
      fVar14 = (float)(fparam_1 * (double)(float)(dVar25 - dVar21) + dVar21);
      fVar3 = (float)(fparam_1 * (double)(float)(dVar24 - dVar22) + dVar22);
      fVar4 = (float)(fparam_1 * (double)(float)(dVar23 - dVar26) + dVar26);
      if (uVar16 == 0) {
        fVar5 = param_4[3];
        fVar4 = fVar4 * fVar5;
        fVar1 = fVar1 * fVar5;
        fVar14 = fVar14 * fVar5;
        fVar3 = fVar3 * fVar5;
      }
      param_4[uVar17 * 4 + 0x23] = fVar4;
      param_4[uVar17 * 4 + 0x20] = fVar1;
      param_4[uVar17 * 4 + 0x21] = fVar14;
      param_4[uVar17 * 4 + 0x22] = fVar3;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* _gleInterpolEyeNO0200w @ 0xb62dc (584 bytes) */
void _gleInterpolEyeNO0200w(int param_1,float *param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  uint uVar11;
  float fVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  
  fVar12 = param_2[0xb];
  fVar2 = *(float *)(param_3 + 0x2c);
  fVar3 = param_2[9];
  fVar4 = param_2[10];
  uVar13 = 0;
  fVar5 = *(float *)(param_3 + 0x24);
  fVar6 = *(float *)(param_3 + 0x28);
  fVar7 = param_2[4];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar2 - (double)fVar12) + (double)fVar12
                        );
  fVar2 = param_2[5];
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = param_2[6];
  fVar12 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar7) + (double)fVar7);
  fVar7 = *(float *)(param_3 + 0x18);
  fVar8 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar3) + (double)fVar3);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[4] = fVar12;
  fVar2 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar2) + (double)fVar2);
  param_4[7] = fVar1;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar10) + (double)fVar10);
  param_4[5] = fVar2;
  param_4[6] = fVar3;
  if (fVar12 < fVar8) {
    uVar13 = 0x10;
  }
  if (fVar1 <= fVar12) {
    uVar13 = uVar13 | 0x20;
  }
  if (fVar2 < fVar8) {
    uVar13 = uVar13 | 4;
  }
  if (fVar1 <= fVar2) {
    uVar13 = uVar13 | 8;
  }
  if (fVar3 < fVar8) {
    uVar13 = uVar13 | 1;
  }
  if (fVar1 < fVar3) {
    uVar13 = uVar13 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar13 | 0x10000)));
  if (uVar13 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar12 = fVar12 * fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar12 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar2 + *(float *)(param_1 + 0x1b84);
    fVar12 = *(float *)(param_1 + 0x1b78);
    fVar2 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar1;
    param_4[2] = fVar12 * fVar3 + fVar2;
  }
  uVar13 = *(uint *)(param_1 + 0x5150);
  uVar14 = 0;
  do {
    uVar11 = uVar13 >> (uVar14 & 0x3f);
    if ((uVar11 & 1) == 0) {
      if (uVar11 == 0) {
        if (param_2 == param_4) {
          return;
        }
        *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
        *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
        *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
        fVar1 = param_2[0x12];
        param_4[0x1d] = param_2[0x1d];
        fVar12 = param_2[0x1e];
        param_4[0x12] = fVar1;
        param_4[0x1e] = fVar12;
        return;
      }
    }
    else {
      iVar15 = uVar14 * 0x10 + param_3;
      fVar1 = param_2[uVar14 * 4 + 0x23];
      fVar12 = param_2[uVar14 * 4 + 0x21];
      fVar2 = param_2[uVar14 * 4 + 0x22];
      fVar3 = *(float *)(iVar15 + 0x8c);
      fVar4 = *(float *)(iVar15 + 0x84);
      fVar5 = *(float *)(iVar15 + 0x88);
      param_4[uVar14 * 4 + 0x20] =
           (float)(fparam_1 *
                   (double)(float)((double)*(float *)(iVar15 + 0x80) -
                                  (double)param_2[uVar14 * 4 + 0x20]) +
                  (double)param_2[uVar14 * 4 + 0x20]);
      param_4[uVar14 * 4 + 0x21] =
           (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar12) + (double)fVar12);
      param_4[uVar14 * 4 + 0x22] =
           (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar2) + (double)fVar2);
      param_4[uVar14 * 4 + 0x23] =
           (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar1) + (double)fVar1);
    }
    uVar14 = uVar14 + 1;
  } while( true );
}

/* _gleInterpolEyeNO0210 @ 0xb6524 (692 bytes) */
void _gleInterpolEyeNO0210(int param_1,float *param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  uint uVar12;
  int iVar13;
  float fVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  
  fVar14 = param_2[0xb];
  fVar3 = *(float *)(param_3 + 0x2c);
  fVar4 = param_2[9];
  fVar5 = param_2[10];
  uVar16 = 0;
  fVar6 = *(float *)(param_3 + 0x24);
  fVar7 = *(float *)(param_3 + 0x28);
  fVar8 = param_2[4];
  fVar9 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar14) + (double)fVar14
                        );
  fVar3 = param_2[5];
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = param_2[6];
  fVar14 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar8) + (double)fVar8);
  fVar8 = *(float *)(param_3 + 0x18);
  fVar9 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[4] = fVar14;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar3) + (double)fVar3);
  param_4[7] = fVar1;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar11) + (double)fVar11);
  cVar2 = *(char *)((int)param_2 + 0x7f);
  param_4[5] = fVar3;
  param_4[6] = fVar4;
  if (fVar14 < fVar9) {
    uVar16 = 0x10;
  }
  if (fVar1 <= fVar14) {
    uVar16 = uVar16 | 0x20;
  }
  if (fVar3 < fVar9) {
    uVar16 = uVar16 | 4;
  }
  if (fVar1 <= fVar3) {
    uVar16 = uVar16 | 8;
  }
  if (fVar4 < fVar9) {
    uVar16 = uVar16 | 1;
  }
  if (fVar1 < fVar4) {
    uVar16 = uVar16 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar16 | 0x10000)));
  if (uVar16 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar14 = fVar14 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar14 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar3 + *(float *)(param_1 + 0x1b84);
    fVar14 = *(float *)(param_1 + 0x1b78);
    fVar3 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar1;
    param_4[2] = fVar14 * fVar4 + fVar3;
  }
  uVar17 = 0;
  param_4[0x13] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x4c) - (double)param_2[0x13]) +
              (double)param_2[0x13]);
  uVar15 = *(uint *)(param_1 + 0x5150);
  do {
    uVar12 = uVar15 >> (uVar17 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        if (param_2 == param_4) {
          return;
        }
        *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
        *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
        *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
        fVar1 = param_2[0x12];
        param_4[0x1d] = param_2[0x1d];
        fVar14 = param_2[0x1e];
        param_4[0x12] = fVar1;
        param_4[0x1e] = fVar14;
        return;
      }
    }
    else {
      dVar26 = (double)param_2[uVar17 * 4 + 0x23];
      dVar20 = (double)param_2[uVar17 * 4 + 0x20];
      dVar21 = (double)param_2[uVar17 * 4 + 0x21];
      dVar22 = (double)param_2[uVar17 * 4 + 0x22];
      if (cVar2 == '\0') {
        dVar18 = (double)param_2[7];
        dVar26 = (double)(float)(dVar26 * dVar18);
        dVar20 = (double)(float)(dVar20 * dVar18);
        dVar21 = (double)(float)(dVar21 * dVar18);
        dVar22 = (double)(float)(dVar22 * dVar18);
      }
      iVar13 = uVar17 * 0x10 + param_3;
      dVar23 = (double)*(float *)(iVar13 + 0x8c);
      dVar18 = (double)*(float *)(iVar13 + 0x80);
      dVar24 = (double)*(float *)(iVar13 + 0x84);
      dVar25 = (double)*(float *)(iVar13 + 0x88);
      if (*(char *)(param_3 + 0x7f) == '\0') {
        dVar19 = (double)*(float *)(param_3 + 0x1c);
        dVar23 = (double)(float)(dVar23 * dVar19);
        dVar18 = (double)(float)(dVar18 * dVar19);
        dVar24 = (double)(float)(dVar24 * dVar19);
        dVar25 = (double)(float)(dVar25 * dVar19);
      }
      fVar1 = (float)(fparam_1 * (double)(float)(dVar18 - dVar20) + dVar20);
      fVar14 = (float)(fparam_1 * (double)(float)(dVar24 - dVar21) + dVar21);
      fVar3 = (float)(fparam_1 * (double)(float)(dVar25 - dVar22) + dVar22);
      fVar4 = (float)(fparam_1 * (double)(float)(dVar23 - dVar26) + dVar26);
      if (uVar16 == 0) {
        fVar5 = param_4[3];
        fVar4 = fVar4 * fVar5;
        fVar1 = fVar1 * fVar5;
        fVar14 = fVar14 * fVar5;
        fVar3 = fVar3 * fVar5;
      }
      param_4[uVar17 * 4 + 0x23] = fVar4;
      param_4[uVar17 * 4 + 0x20] = fVar1;
      param_4[uVar17 * 4 + 0x21] = fVar14;
      param_4[uVar17 * 4 + 0x22] = fVar3;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* _gleInterpolEyeNO0210w @ 0xb67d8 (604 bytes) */
void _gleInterpolEyeNO0210w(int param_1,float *param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  uint uVar11;
  float fVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  
  fVar12 = param_2[0xb];
  fVar2 = *(float *)(param_3 + 0x2c);
  fVar3 = param_2[9];
  fVar4 = param_2[10];
  uVar13 = 0;
  fVar5 = *(float *)(param_3 + 0x24);
  fVar6 = *(float *)(param_3 + 0x28);
  fVar7 = param_2[4];
  fVar8 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar2 - (double)fVar12) + (double)fVar12
                        );
  fVar2 = param_2[5];
  fVar9 = *(float *)(param_3 + 0x14);
  fVar10 = param_2[6];
  fVar12 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar7) + (double)fVar7);
  fVar7 = *(float *)(param_3 + 0x18);
  fVar8 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar3) + (double)fVar3);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[4] = fVar12;
  fVar2 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar2) + (double)fVar2);
  param_4[7] = fVar1;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar10) + (double)fVar10);
  param_4[5] = fVar2;
  param_4[6] = fVar3;
  if (fVar12 < fVar8) {
    uVar13 = 0x10;
  }
  if (fVar1 <= fVar12) {
    uVar13 = uVar13 | 0x20;
  }
  if (fVar2 < fVar8) {
    uVar13 = uVar13 | 4;
  }
  if (fVar1 <= fVar2) {
    uVar13 = uVar13 | 8;
  }
  if (fVar3 < fVar8) {
    uVar13 = uVar13 | 1;
  }
  if (fVar1 < fVar3) {
    uVar13 = uVar13 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar13 | 0x10000)));
  if (uVar13 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar12 = fVar12 * fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar12 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar2 + *(float *)(param_1 + 0x1b84);
    fVar12 = *(float *)(param_1 + 0x1b78);
    fVar2 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar1;
    param_4[2] = fVar12 * fVar3 + fVar2;
  }
  uVar14 = 0;
  param_4[0x13] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x4c) - (double)param_2[0x13]) +
              (double)param_2[0x13]);
  uVar13 = *(uint *)(param_1 + 0x5150);
  do {
    uVar11 = uVar13 >> (uVar14 & 0x3f);
    if ((uVar11 & 1) == 0) {
      if (uVar11 == 0) {
        if (param_2 == param_4) {
          return;
        }
        *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
        *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
        *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
        fVar1 = param_2[0x12];
        param_4[0x1d] = param_2[0x1d];
        fVar12 = param_2[0x1e];
        param_4[0x12] = fVar1;
        param_4[0x1e] = fVar12;
        return;
      }
    }
    else {
      iVar15 = uVar14 * 0x10 + param_3;
      fVar1 = param_2[uVar14 * 4 + 0x23];
      fVar12 = param_2[uVar14 * 4 + 0x21];
      fVar2 = param_2[uVar14 * 4 + 0x22];
      fVar3 = *(float *)(iVar15 + 0x8c);
      fVar4 = *(float *)(iVar15 + 0x84);
      fVar5 = *(float *)(iVar15 + 0x88);
      param_4[uVar14 * 4 + 0x20] =
           (float)(fparam_1 *
                   (double)(float)((double)*(float *)(iVar15 + 0x80) -
                                  (double)param_2[uVar14 * 4 + 0x20]) +
                  (double)param_2[uVar14 * 4 + 0x20]);
      param_4[uVar14 * 4 + 0x21] =
           (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar12) + (double)fVar12);
      param_4[uVar14 * 4 + 0x22] =
           (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar2) + (double)fVar2);
      param_4[uVar14 * 4 + 0x23] =
           (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar1) + (double)fVar1);
    }
    uVar14 = uVar14 + 1;
  } while( true );
}

/* _gleInterpolEyeNO1000 @ 0xb6a34 (476 bytes) */
void _gleInterpolEyeNO1000(int param_1,int param_2,int param_3,float *param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
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
  uint uVar12;
  
  fVar2 = *(float *)(param_2 + 0x2c);
  fVar3 = *(float *)(param_3 + 0x2c);
  fVar4 = *(float *)(param_2 + 0x24);
  fVar5 = *(float *)(param_3 + 0x24);
  fVar6 = *(float *)(param_2 + 0x28);
  fVar7 = *(float *)(param_3 + 0x28);
  fVar8 = *(float *)(param_2 + 0x10);
  fVar9 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) -
                                 (double)*(float *)(param_2 + 0x1c)) +
                 (double)*(float *)(param_2 + 0x1c));
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) -
                                      (double)*(float *)(param_2 + 0x20)) +
                      (double)*(float *)(param_2 + 0x20));
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar2) + (double)fVar2);
  fVar3 = *(float *)(param_2 + 0x14);
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = *(float *)(param_2 + 0x18);
  fVar2 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar8) + (double)fVar8);
  fVar8 = *(float *)(param_3 + 0x18);
  fVar9 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar4) + (double)fVar4);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar6) + (double)fVar6);
  param_4[4] = fVar2;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar3) + (double)fVar3);
  param_4[7] = fVar1;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar11) + (double)fVar11);
  uVar12 = 0;
  param_4[5] = fVar3;
  param_4[6] = fVar4;
  if (fVar2 < fVar9) {
    uVar12 = 0x10;
  }
  if (fVar1 <= fVar2) {
    uVar12 = uVar12 | 0x20;
  }
  if (fVar3 < fVar9) {
    uVar12 = uVar12 | 4;
  }
  if (fVar1 <= fVar3) {
    uVar12 = uVar12 | 8;
  }
  if (fVar4 < fVar9) {
    uVar12 = uVar12 | 1;
  }
  if (fVar1 < fVar4) {
    uVar12 = uVar12 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x7c) << 0x18 | (uint)*(byte *)(param_2 + 0x7e) << 8 |
               uVar12 | 0x10000)));
  if (uVar12 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar2 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar3 + *(float *)(param_1 + 0x1b84);
    fVar2 = *(float *)(param_1 + 0x1b88);
    fVar3 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar1;
    param_4[2] = fVar3 * fVar4 + fVar2;
  }
  fVar1 = *(float *)(param_2 + 0x3c);
  fVar2 = *(float *)(param_2 + 0x34);
  fVar3 = *(float *)(param_2 + 0x38);
  fVar4 = *(float *)(param_3 + 0x3c);
  fVar5 = *(float *)(param_3 + 0x34);
  fVar6 = *(float *)(param_3 + 0x38);
  param_4[0xc] = (float)(fparam_1 *
                         (double)(float)((double)*(float *)(param_3 + 0x30) -
                                        (double)*(float *)(param_2 + 0x30)) +
                        (double)*(float *)(param_2 + 0x30));
  param_4[0xd] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar2) + (double)fVar2);
  param_4[0xf] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1);
  param_4[0xe] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar3) + (double)fVar3);
  return;
}

/* _gleInterpolEyeNO1001 @ 0xb6c10 (480 bytes) */
void _gleInterpolEyeNO1001(int param_1,float *param_2,int param_3,float *param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
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
  uint uVar12;
  
  fVar2 = param_2[0xb];
  fVar3 = *(float *)(param_3 + 0x2c);
  fVar4 = param_2[10];
  fVar5 = *(float *)(param_3 + 0x24);
  fVar6 = param_2[9];
  fVar7 = *(float *)(param_3 + 0x28);
  fVar8 = param_2[4];
  fVar9 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar2) + (double)fVar2);
  fVar3 = param_2[5];
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = param_2[6];
  fVar2 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar8) + (double)fVar8);
  fVar8 = *(float *)(param_3 + 0x18);
  fVar9 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar6) + (double)fVar6);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar4) + (double)fVar4);
  param_4[4] = fVar2;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar3) + (double)fVar3);
  param_4[7] = fVar1;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar11) + (double)fVar11);
  uVar12 = 0;
  param_4[5] = fVar3;
  param_4[6] = fVar4;
  if (fVar2 < fVar9) {
    uVar12 = 0x10;
  }
  if (fVar1 <= fVar2) {
    uVar12 = uVar12 | 0x20;
  }
  if (fVar3 < fVar9) {
    uVar12 = uVar12 | 4;
  }
  if (fVar1 <= fVar3) {
    uVar12 = uVar12 | 8;
  }
  if (fVar4 < fVar9) {
    uVar12 = uVar12 | 1;
  }
  if (fVar1 < fVar4) {
    uVar12 = uVar12 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar12 | 0x10000)));
  if (uVar12 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar2 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar3 + *(float *)(param_1 + 0x1b84);
    fVar2 = *(float *)(param_1 + 0x1b88);
    fVar3 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar1;
    param_4[2] = fVar3 * fVar4 + fVar2;
  }
  fVar1 = param_2[0x10];
  fVar2 = param_2[0x11];
  fVar3 = *(float *)(param_3 + 0x40);
  fVar4 = *(float *)(param_3 + 0x44);
  param_4[0x12] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x48) - (double)param_2[0x12]) +
              (double)param_2[0x12]);
  param_4[0x10] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar1) + (double)fVar1)
  ;
  param_4[0x11] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar2) + (double)fVar2)
  ;
  if (param_2 == param_4) {
    return;
  }
  param_4[0x1d] = param_2[0x1d];
  param_4[0x1e] = param_2[0x1e];
  return;
}

/* _gleInterpolEyeNO1010 @ 0xb6df0 (496 bytes) */
void _gleInterpolEyeNO1010(int param_1,int param_2,int param_3,float *param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
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
  uint uVar12;
  
  fVar2 = *(float *)(param_2 + 0x2c);
  fVar3 = *(float *)(param_3 + 0x2c);
  fVar4 = *(float *)(param_2 + 0x24);
  fVar5 = *(float *)(param_2 + 0x28);
  fVar6 = *(float *)(param_3 + 0x24);
  fVar7 = *(float *)(param_3 + 0x28);
  fVar8 = *(float *)(param_2 + 0x10);
  fVar9 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) -
                                 (double)*(float *)(param_2 + 0x1c)) +
                 (double)*(float *)(param_2 + 0x1c));
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) -
                                      (double)*(float *)(param_2 + 0x20)) +
                      (double)*(float *)(param_2 + 0x20));
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar2) + (double)fVar2);
  fVar3 = *(float *)(param_2 + 0x14);
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = *(float *)(param_2 + 0x18);
  fVar2 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar8) + (double)fVar8);
  fVar8 = *(float *)(param_3 + 0x18);
  fVar9 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[4] = fVar2;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar3) + (double)fVar3);
  param_4[7] = fVar1;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar11) + (double)fVar11);
  uVar12 = 0;
  param_4[5] = fVar3;
  param_4[6] = fVar4;
  if (fVar2 < fVar9) {
    uVar12 = 0x10;
  }
  if (fVar1 <= fVar2) {
    uVar12 = uVar12 | 0x20;
  }
  if (fVar3 < fVar9) {
    uVar12 = uVar12 | 4;
  }
  if (fVar1 <= fVar3) {
    uVar12 = uVar12 | 8;
  }
  if (fVar4 < fVar9) {
    uVar12 = uVar12 | 1;
  }
  if (fVar1 < fVar4) {
    uVar12 = uVar12 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x7c) << 0x18 | (uint)*(byte *)(param_2 + 0x7e) << 8 |
               uVar12 | 0x10000)));
  if (uVar12 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar2 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar3 + *(float *)(param_1 + 0x1b84);
    fVar2 = *(float *)(param_1 + 0x1b88);
    fVar3 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar1;
    param_4[2] = fVar3 * fVar4 + fVar2;
  }
  fVar1 = *(float *)(param_2 + 0x3c);
  fVar2 = *(float *)(param_2 + 0x30);
  fVar3 = *(float *)(param_2 + 0x34);
  fVar4 = *(float *)(param_3 + 0x3c);
  fVar5 = *(float *)(param_3 + 0x30);
  fVar6 = *(float *)(param_2 + 0x38);
  fVar7 = *(float *)(param_3 + 0x34);
  param_4[0x13] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x4c) -
                              (double)*(float *)(param_2 + 0x4c)) +
              (double)*(float *)(param_2 + 0x4c));
  fVar8 = *(float *)(param_3 + 0x38);
  param_4[0xc] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar2) + (double)fVar2);
  param_4[0xd] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar3) + (double)fVar3);
  param_4[0xf] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1);
  param_4[0xe] = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar6) + (double)fVar6);
  return;
}

/* _gleInterpolEyeNO1011 @ 0xb6fe0 (500 bytes) */
void _gleInterpolEyeNO1011(int param_1,float *param_2,int param_3,float *param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
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
  uint uVar12;
  
  fVar2 = param_2[0xb];
  fVar3 = *(float *)(param_3 + 0x2c);
  fVar4 = param_2[9];
  fVar5 = param_2[10];
  fVar6 = *(float *)(param_3 + 0x24);
  fVar7 = *(float *)(param_3 + 0x28);
  fVar8 = param_2[4];
  fVar9 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar2) + (double)fVar2);
  fVar3 = param_2[5];
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = param_2[6];
  fVar2 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar8) + (double)fVar8);
  fVar8 = *(float *)(param_3 + 0x18);
  fVar9 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[4] = fVar2;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar3) + (double)fVar3);
  param_4[7] = fVar1;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar11) + (double)fVar11);
  uVar12 = 0;
  param_4[5] = fVar3;
  param_4[6] = fVar4;
  if (fVar2 < fVar9) {
    uVar12 = 0x10;
  }
  if (fVar1 <= fVar2) {
    uVar12 = uVar12 | 0x20;
  }
  if (fVar3 < fVar9) {
    uVar12 = uVar12 | 4;
  }
  if (fVar1 <= fVar3) {
    uVar12 = uVar12 | 8;
  }
  if (fVar4 < fVar9) {
    uVar12 = uVar12 | 1;
  }
  if (fVar1 < fVar4) {
    uVar12 = uVar12 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar12 | 0x10000)));
  if (uVar12 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar2 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar3 + *(float *)(param_1 + 0x1b84);
    fVar2 = *(float *)(param_1 + 0x1b88);
    fVar3 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar1;
    param_4[2] = fVar3 * fVar4 + fVar2;
  }
  fVar1 = param_2[0x10];
  fVar2 = param_2[0x11];
  fVar3 = *(float *)(param_3 + 0x40);
  fVar4 = *(float *)(param_3 + 0x44);
  fVar5 = param_2[0x12];
  param_4[0x13] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x4c) - (double)param_2[0x13]) +
              (double)param_2[0x13]);
  fVar6 = *(float *)(param_3 + 0x48);
  param_4[0x10] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar1) + (double)fVar1)
  ;
  param_4[0x11] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar2) + (double)fVar2)
  ;
  param_4[0x12] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar5) + (double)fVar5)
  ;
  if (param_2 == param_4) {
    return;
  }
  param_4[0x1d] = param_2[0x1d];
  param_4[0x1e] = param_2[0x1e];
  return;
}

/* FUN_000b71d8 @ 0xb71d8 (636 bytes) */
void FUN_000b71d8(int param_1,int param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,float fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  char cVar2;
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
  uint uVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  
  fVar3 = *(float *)(param_3 + 0x2c);
  fVar4 = *(float *)(param_2 + 0x24);
  fVar5 = *(float *)(param_2 + 0x28);
  uVar13 = 0;
  fVar6 = *(float *)(param_3 + 0x24);
  fVar7 = *(float *)(param_3 + 0x28);
  fVar8 = *(float *)(param_2 + 0x10);
  fVar9 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) -
                                 (double)*(float *)(param_2 + 0x1c)) +
                 (double)*(float *)(param_2 + 0x1c));
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) -
                                      (double)*(float *)(param_2 + 0x20)) +
                      (double)*(float *)(param_2 + 0x20));
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar3 - fparam_6) + fparam_6);
  fVar10 = *(float *)(param_2 + 0x14);
  fVar11 = *(float *)(param_3 + 0x14);
  fVar12 = *(float *)(param_2 + 0x18);
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar8) + (double)fVar8);
  fVar8 = *(float *)(param_3 + 0x18);
  fVar9 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[4] = fVar3;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar11 - (double)fVar10) + (double)fVar10);
  param_4[7] = fVar1;
  fVar5 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar12) + (double)fVar12);
  cVar2 = *(char *)(param_2 + 0x7f);
  param_4[5] = fVar4;
  param_4[6] = fVar5;
  if (fVar3 < fVar9) {
    uVar13 = 0x10;
  }
  if (fVar1 <= fVar3) {
    uVar13 = uVar13 | 0x20;
  }
  if (fVar4 < fVar9) {
    uVar13 = uVar13 | 4;
  }
  if (fVar1 <= fVar4) {
    uVar13 = uVar13 | 8;
  }
  if (fVar5 < fVar9) {
    uVar13 = uVar13 | 1;
  }
  if (fVar1 < fVar5) {
    uVar13 = uVar13 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x7c) << 0x18 | (uint)*(byte *)(param_2 + 0x7e) << 8 |
               uVar13 | 0x10000)));
  if (uVar13 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
      fVar5 = fVar5 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar3 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar4 + *(float *)(param_1 + 0x1b84);
    fVar3 = *(float *)(param_1 + 0x1b88);
    fVar4 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar1;
    param_4[2] = fVar4 * fVar5 + fVar3;
  }
  fVar1 = *(float *)(param_2 + 0x34);
  fVar3 = *(float *)(param_2 + 0x38);
  fVar4 = *(float *)(param_2 + 0x3c);
  fVar5 = *(float *)(param_3 + 0x34);
  fVar6 = *(float *)(param_3 + 0x38);
  fVar7 = *(float *)(param_3 + 0x3c);
  param_4[0xc] = (float)(fparam_1 *
                         (double)(float)((double)*(float *)(param_3 + 0x30) -
                                        (double)*(float *)(param_2 + 0x30)) +
                        (double)*(float *)(param_2 + 0x30));
  param_4[0xd] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar1) + (double)fVar1);
  param_4[0xe] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar3) + (double)fVar3);
  param_4[0xf] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar4) + (double)fVar4);
  dVar16 = (double)*(float *)(param_2 + 0x80);
  dVar18 = (double)*(float *)(param_2 + 0x84);
  dVar17 = (double)*(float *)(param_2 + 0x88);
  dVar19 = (double)*(float *)(param_2 + 0x8c);
  if (cVar2 == '\0') {
    dVar14 = (double)*(float *)(param_2 + 0x1c);
    dVar19 = (double)(float)(dVar19 * dVar14);
    dVar16 = (double)(float)(dVar16 * dVar14);
    dVar18 = (double)(float)(dVar18 * dVar14);
    dVar17 = (double)(float)(dVar17 * dVar14);
  }
  dVar14 = (double)*(float *)(param_3 + 0x80);
  dVar21 = (double)*(float *)(param_3 + 0x84);
  dVar20 = (double)*(float *)(param_3 + 0x88);
  dVar22 = (double)*(float *)(param_3 + 0x8c);
  if (*(char *)(param_3 + 0x7f) == '\0') {
    dVar15 = (double)*(float *)(param_3 + 0x1c);
    dVar22 = (double)(float)(dVar22 * dVar15);
    dVar14 = (double)(float)(dVar14 * dVar15);
    dVar21 = (double)(float)(dVar21 * dVar15);
    dVar20 = (double)(float)(dVar20 * dVar15);
  }
  fVar1 = (float)(fparam_1 * (double)(float)(dVar14 - dVar16) + dVar16);
  fVar3 = (float)(fparam_1 * (double)(float)(dVar21 - dVar18) + dVar18);
  fVar4 = (float)(fparam_1 * (double)(float)(dVar22 - dVar19) + dVar19);
  fVar5 = (float)(fparam_1 * (double)(float)(dVar20 - dVar17) + dVar17);
  if (uVar13 == 0) {
    fVar6 = param_4[3];
    fVar4 = fVar4 * fVar6;
    fVar1 = fVar1 * fVar6;
    fVar3 = fVar3 * fVar6;
    fVar5 = fVar5 * fVar6;
  }
  param_4[0x23] = fVar4;
  param_4[0x20] = fVar1;
  param_4[0x21] = fVar3;
  param_4[0x22] = fVar5;
  return;
}

/* FUN_000b7458 @ 0xb7458 (548 bytes) */
void FUN_000b7458(int param_1,int param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
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
  uint uVar12;
  
  fVar2 = *(float *)(param_3 + 0x2c);
  fVar3 = *(float *)(param_2 + 0x24);
  fVar4 = *(float *)(param_2 + 0x28);
  uVar12 = 0;
  fVar5 = *(float *)(param_3 + 0x24);
  fVar6 = *(float *)(param_3 + 0x28);
  fVar7 = *(float *)(param_2 + 0x10);
  fVar8 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) -
                                 (double)*(float *)(param_2 + 0x1c)) +
                 (double)*(float *)(param_2 + 0x1c));
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) -
                                      (double)*(float *)(param_2 + 0x20)) +
                      (double)*(float *)(param_2 + 0x20));
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar2 - fparam_4) + fparam_4);
  fVar9 = *(float *)(param_2 + 0x14);
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = *(float *)(param_2 + 0x18);
  fVar2 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar7) + (double)fVar7);
  fVar7 = *(float *)(param_3 + 0x18);
  fVar8 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar3) + (double)fVar3);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[4] = fVar2;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar9) + (double)fVar9);
  param_4[7] = fVar1;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar11) + (double)fVar11);
  param_4[5] = fVar3;
  param_4[6] = fVar4;
  if (fVar2 < fVar8) {
    uVar12 = 0x10;
  }
  if (fVar1 <= fVar2) {
    uVar12 = uVar12 | 0x20;
  }
  if (fVar3 < fVar8) {
    uVar12 = uVar12 | 4;
  }
  if (fVar1 <= fVar3) {
    uVar12 = uVar12 | 8;
  }
  if (fVar4 < fVar8) {
    uVar12 = uVar12 | 1;
  }
  if (fVar1 < fVar4) {
    uVar12 = uVar12 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x7c) << 0x18 | (uint)*(byte *)(param_2 + 0x7e) << 8 |
               uVar12 | 0x10000)));
  if (uVar12 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar2 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar3 + *(float *)(param_1 + 0x1b84);
    fVar2 = *(float *)(param_1 + 0x1b88);
    fVar3 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar1;
    param_4[2] = fVar3 * fVar4 + fVar2;
  }
  fVar1 = *(float *)(param_2 + 0x34);
  fVar2 = *(float *)(param_2 + 0x38);
  fVar3 = *(float *)(param_2 + 0x3c);
  fVar4 = *(float *)(param_3 + 0x34);
  fVar5 = *(float *)(param_3 + 0x38);
  fVar6 = *(float *)(param_3 + 0x3c);
  param_4[0xc] = (float)(fparam_1 *
                         (double)(float)((double)*(float *)(param_3 + 0x30) -
                                        (double)*(float *)(param_2 + 0x30)) +
                        (double)*(float *)(param_2 + 0x30));
  param_4[0xd] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1);
  param_4[0xe] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar2) + (double)fVar2);
  param_4[0xf] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar3) + (double)fVar3);
  fVar1 = *(float *)(param_2 + 0x8c);
  fVar2 = *(float *)(param_2 + 0x84);
  fVar3 = *(float *)(param_2 + 0x88);
  fVar4 = *(float *)(param_3 + 0x8c);
  fVar5 = *(float *)(param_3 + 0x84);
  fVar6 = *(float *)(param_3 + 0x88);
  param_4[0x20] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x80) -
                              (double)*(float *)(param_2 + 0x80)) +
              (double)*(float *)(param_2 + 0x80));
  param_4[0x21] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar2) + (double)fVar2)
  ;
  param_4[0x23] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1)
  ;
  param_4[0x22] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar3) + (double)fVar3)
  ;
  return;
}

/* _gleInterpolEyeNO1101 @ 0xb767c (648 bytes) */
void _gleInterpolEyeNO1101(int param_1,float *param_2,int param_3,float *param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  char cVar2;
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
  uint uVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  
  fVar3 = param_2[0xb];
  fVar4 = *(float *)(param_3 + 0x2c);
  fVar5 = param_2[9];
  fVar6 = param_2[10];
  fVar7 = *(float *)(param_3 + 0x24);
  fVar8 = *(float *)(param_3 + 0x28);
  fVar9 = param_2[4];
  fVar10 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar3) + (double)fVar3);
  fVar4 = param_2[5];
  fVar11 = *(float *)(param_3 + 0x14);
  fVar12 = param_2[6];
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar9) + (double)fVar9);
  fVar9 = *(float *)(param_3 + 0x18);
  fVar10 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar6) + (double)fVar6);
  param_4[4] = fVar3;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar11 - (double)fVar4) + (double)fVar4);
  param_4[7] = fVar1;
  fVar5 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar12) + (double)fVar12);
  cVar2 = *(char *)((int)param_2 + 0x7f);
  uVar13 = 0;
  param_4[5] = fVar4;
  param_4[6] = fVar5;
  if (fVar3 < fVar10) {
    uVar13 = 0x10;
  }
  if (fVar1 <= fVar3) {
    uVar13 = uVar13 | 0x20;
  }
  if (fVar4 < fVar10) {
    uVar13 = uVar13 | 4;
  }
  if (fVar1 <= fVar4) {
    uVar13 = uVar13 | 8;
  }
  if (fVar5 < fVar10) {
    uVar13 = uVar13 | 1;
  }
  if (fVar1 < fVar5) {
    uVar13 = uVar13 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar13 | 0x10000)));
  if (uVar13 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
      fVar5 = fVar5 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar3 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar4 + *(float *)(param_1 + 0x1b84);
    fVar3 = *(float *)(param_1 + 0x1b88);
    fVar4 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar1;
    param_4[2] = fVar4 * fVar5 + fVar3;
  }
  dVar16 = (double)param_2[0x20];
  dVar17 = (double)param_2[0x21];
  dVar18 = (double)param_2[0x22];
  dVar22 = (double)param_2[0x23];
  if (cVar2 == '\0') {
    dVar14 = (double)param_2[7];
    dVar22 = (double)(float)(dVar22 * dVar14);
    dVar16 = (double)(float)(dVar16 * dVar14);
    dVar17 = (double)(float)(dVar17 * dVar14);
    dVar18 = (double)(float)(dVar18 * dVar14);
  }
  dVar21 = (double)*(float *)(param_3 + 0x80);
  dVar14 = (double)*(float *)(param_3 + 0x84);
  dVar20 = (double)*(float *)(param_3 + 0x88);
  dVar19 = (double)*(float *)(param_3 + 0x8c);
  if (*(char *)(param_3 + 0x7f) == '\0') {
    dVar15 = (double)*(float *)(param_3 + 0x1c);
    dVar19 = (double)(float)(dVar19 * dVar15);
    dVar21 = (double)(float)(dVar21 * dVar15);
    dVar14 = (double)(float)(dVar14 * dVar15);
    dVar20 = (double)(float)(dVar20 * dVar15);
  }
  fVar1 = (float)(fparam_1 * (double)(float)(dVar21 - dVar16) + dVar16);
  fVar3 = (float)(fparam_1 * (double)(float)(dVar14 - dVar17) + dVar17);
  fVar4 = (float)(fparam_1 * (double)(float)(dVar20 - dVar18) + dVar18);
  fVar5 = (float)(fparam_1 * (double)(float)(dVar19 - dVar22) + dVar22);
  if (uVar13 == 0) {
    fVar6 = param_4[3];
    fVar5 = fVar5 * fVar6;
    fVar1 = fVar1 * fVar6;
    fVar3 = fVar3 * fVar6;
    fVar4 = fVar4 * fVar6;
  }
  param_4[0x20] = fVar1;
  param_4[0x21] = fVar3;
  param_4[0x22] = fVar4;
  param_4[0x23] = fVar5;
  fVar1 = param_2[0x10];
  fVar3 = param_2[0x11];
  fVar4 = *(float *)(param_3 + 0x40);
  fVar5 = *(float *)(param_3 + 0x44);
  param_4[0x12] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x48) - (double)param_2[0x12]) +
              (double)param_2[0x12]);
  param_4[0x10] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1)
  ;
  param_4[0x11] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar3) + (double)fVar3)
  ;
  if (param_2 == param_4) {
    return;
  }
  param_4[0x1d] = param_2[0x1d];
  param_4[0x1e] = param_2[0x1e];
  return;
}

/* _gleInterpolEyeNO1101w @ 0xb7904 (560 bytes) */
void _gleInterpolEyeNO1101w(int param_1,float *param_2,int param_3,float *param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
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
  uint uVar12;
  
  fVar2 = param_2[0xb];
  fVar3 = *(float *)(param_3 + 0x2c);
  fVar4 = param_2[9];
  fVar5 = param_2[10];
  fVar6 = *(float *)(param_3 + 0x24);
  fVar7 = *(float *)(param_3 + 0x28);
  fVar8 = param_2[4];
  fVar9 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar2) + (double)fVar2);
  fVar3 = param_2[5];
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = param_2[6];
  fVar2 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar8) + (double)fVar8);
  fVar8 = *(float *)(param_3 + 0x18);
  fVar9 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[4] = fVar2;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar3) + (double)fVar3);
  param_4[7] = fVar1;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar11) + (double)fVar11);
  uVar12 = 0;
  param_4[5] = fVar3;
  param_4[6] = fVar4;
  if (fVar2 < fVar9) {
    uVar12 = 0x10;
  }
  if (fVar1 <= fVar2) {
    uVar12 = uVar12 | 0x20;
  }
  if (fVar3 < fVar9) {
    uVar12 = uVar12 | 4;
  }
  if (fVar1 <= fVar3) {
    uVar12 = uVar12 | 8;
  }
  if (fVar4 < fVar9) {
    uVar12 = uVar12 | 1;
  }
  if (fVar1 < fVar4) {
    uVar12 = uVar12 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar12 | 0x10000)));
  if (uVar12 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar2 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar3 + *(float *)(param_1 + 0x1b84);
    fVar2 = *(float *)(param_1 + 0x1b88);
    fVar3 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar1;
    param_4[2] = fVar3 * fVar4 + fVar2;
  }
  fVar1 = param_2[0x21];
  fVar2 = param_2[0x22];
  fVar3 = param_2[0x23];
  fVar4 = *(float *)(param_3 + 0x84);
  fVar5 = *(float *)(param_3 + 0x88);
  fVar6 = *(float *)(param_3 + 0x8c);
  param_4[0x20] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x80) - (double)param_2[0x20]) +
              (double)param_2[0x20]);
  param_4[0x21] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1)
  ;
  param_4[0x22] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar2) + (double)fVar2)
  ;
  param_4[0x23] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar3) + (double)fVar3)
  ;
  fVar1 = param_2[0x10];
  fVar2 = param_2[0x11];
  fVar3 = *(float *)(param_3 + 0x40);
  fVar4 = *(float *)(param_3 + 0x44);
  param_4[0x12] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x48) - (double)param_2[0x12]) +
              (double)param_2[0x12]);
  param_4[0x10] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar1) + (double)fVar1)
  ;
  param_4[0x11] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar2) + (double)fVar2)
  ;
  if (param_2 == param_4) {
    return;
  }
  param_4[0x1d] = param_2[0x1d];
  param_4[0x1e] = param_2[0x1e];
  return;
}

/* FUN_000b7b38 @ 0xb7b38 (656 bytes) */
void FUN_000b7b38(int param_1,int param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,double fparam_4,float fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  char cVar2;
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
  uint uVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  
  fVar3 = *(float *)(param_3 + 0x2c);
  fVar4 = *(float *)(param_2 + 0x24);
  fVar5 = *(float *)(param_2 + 0x28);
  uVar13 = 0;
  fVar6 = *(float *)(param_3 + 0x24);
  fVar7 = *(float *)(param_3 + 0x28);
  fVar8 = *(float *)(param_2 + 0x10);
  fVar9 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) -
                                 (double)*(float *)(param_2 + 0x1c)) +
                 (double)*(float *)(param_2 + 0x1c));
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) -
                                      (double)*(float *)(param_2 + 0x20)) +
                      (double)*(float *)(param_2 + 0x20));
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar3 - fparam_5) + fparam_5);
  fVar10 = *(float *)(param_2 + 0x14);
  fVar11 = *(float *)(param_3 + 0x14);
  fVar12 = *(float *)(param_2 + 0x18);
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar8) + (double)fVar8);
  fVar8 = *(float *)(param_3 + 0x18);
  fVar9 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[4] = fVar3;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar11 - (double)fVar10) + (double)fVar10);
  param_4[7] = fVar1;
  fVar5 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar12) + (double)fVar12);
  cVar2 = *(char *)(param_2 + 0x7f);
  param_4[5] = fVar4;
  param_4[6] = fVar5;
  if (fVar3 < fVar9) {
    uVar13 = 0x10;
  }
  if (fVar1 <= fVar3) {
    uVar13 = uVar13 | 0x20;
  }
  if (fVar4 < fVar9) {
    uVar13 = uVar13 | 4;
  }
  if (fVar1 <= fVar4) {
    uVar13 = uVar13 | 8;
  }
  if (fVar5 < fVar9) {
    uVar13 = uVar13 | 1;
  }
  if (fVar1 < fVar5) {
    uVar13 = uVar13 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x7c) << 0x18 | (uint)*(byte *)(param_2 + 0x7e) << 8 |
               uVar13 | 0x10000)));
  if (uVar13 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
      fVar5 = fVar5 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar3 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar4 + *(float *)(param_1 + 0x1b84);
    fVar3 = *(float *)(param_1 + 0x1b88);
    fVar4 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar1;
    param_4[2] = fVar4 * fVar5 + fVar3;
  }
  fVar1 = *(float *)(param_2 + 0x30);
  fVar3 = *(float *)(param_2 + 0x34);
  fVar4 = *(float *)(param_2 + 0x3c);
  fVar5 = *(float *)(param_3 + 0x30);
  fVar6 = *(float *)(param_3 + 0x34);
  fVar7 = *(float *)(param_2 + 0x38);
  fVar8 = *(float *)(param_3 + 0x3c);
  param_4[0x13] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x4c) -
                              (double)*(float *)(param_2 + 0x4c)) +
              (double)*(float *)(param_2 + 0x4c));
  fVar9 = *(float *)(param_3 + 0x38);
  param_4[0xc] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar1) + (double)fVar1);
  param_4[0xd] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar3) + (double)fVar3);
  param_4[0xf] = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar4) + (double)fVar4);
  param_4[0xe] = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar7) + (double)fVar7);
  dVar16 = (double)*(float *)(param_2 + 0x80);
  dVar17 = (double)*(float *)(param_2 + 0x84);
  dVar20 = (double)*(float *)(param_2 + 0x88);
  dVar18 = (double)*(float *)(param_2 + 0x8c);
  if (cVar2 == '\0') {
    dVar14 = (double)*(float *)(param_2 + 0x1c);
    dVar18 = (double)(float)(dVar18 * dVar14);
    dVar16 = (double)(float)(dVar16 * dVar14);
    dVar17 = (double)(float)(dVar17 * dVar14);
    dVar20 = (double)(float)(dVar20 * dVar14);
  }
  dVar14 = (double)*(float *)(param_3 + 0x80);
  dVar19 = (double)*(float *)(param_3 + 0x84);
  dVar22 = (double)*(float *)(param_3 + 0x88);
  dVar21 = (double)*(float *)(param_3 + 0x8c);
  if (*(char *)(param_3 + 0x7f) == '\0') {
    dVar15 = (double)*(float *)(param_3 + 0x1c);
    dVar21 = (double)(float)(dVar21 * dVar15);
    dVar14 = (double)(float)(dVar14 * dVar15);
    dVar19 = (double)(float)(dVar19 * dVar15);
    dVar22 = (double)(float)(dVar22 * dVar15);
  }
  fVar1 = (float)(fparam_1 * (double)(float)(dVar14 - dVar16) + dVar16);
  fVar3 = (float)(fparam_1 * (double)(float)(dVar19 - dVar17) + dVar17);
  fVar4 = (float)(fparam_1 * (double)(float)(dVar21 - dVar18) + dVar18);
  fVar5 = (float)(fparam_1 * (double)(float)(dVar22 - dVar20) + dVar20);
  if (uVar13 == 0) {
    fVar6 = param_4[3];
    fVar4 = fVar4 * fVar6;
    fVar1 = fVar1 * fVar6;
    fVar3 = fVar3 * fVar6;
    fVar5 = fVar5 * fVar6;
  }
  param_4[0x23] = fVar4;
  param_4[0x20] = fVar1;
  param_4[0x21] = fVar3;
  param_4[0x22] = fVar5;
  return;
}

/* FUN_000b7dcc @ 0xb7dcc (568 bytes) */
void FUN_000b7dcc(int param_1,int param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
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
  uint uVar12;
  
  fVar2 = *(float *)(param_3 + 0x2c);
  fVar3 = *(float *)(param_2 + 0x24);
  fVar4 = *(float *)(param_2 + 0x28);
  uVar12 = 0;
  fVar5 = *(float *)(param_3 + 0x24);
  fVar6 = *(float *)(param_3 + 0x28);
  fVar7 = *(float *)(param_2 + 0x10);
  fVar8 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) -
                                 (double)*(float *)(param_2 + 0x1c)) +
                 (double)*(float *)(param_2 + 0x1c));
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) -
                                      (double)*(float *)(param_2 + 0x20)) +
                      (double)*(float *)(param_2 + 0x20));
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar2 - fparam_4) + fparam_4);
  fVar9 = *(float *)(param_2 + 0x14);
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = *(float *)(param_2 + 0x18);
  fVar2 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar7) + (double)fVar7);
  fVar7 = *(float *)(param_3 + 0x18);
  fVar8 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar3) + (double)fVar3);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[4] = fVar2;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar9) + (double)fVar9);
  param_4[7] = fVar1;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar11) + (double)fVar11);
  param_4[5] = fVar3;
  param_4[6] = fVar4;
  if (fVar2 < fVar8) {
    uVar12 = 0x10;
  }
  if (fVar1 <= fVar2) {
    uVar12 = uVar12 | 0x20;
  }
  if (fVar3 < fVar8) {
    uVar12 = uVar12 | 4;
  }
  if (fVar1 <= fVar3) {
    uVar12 = uVar12 | 8;
  }
  if (fVar4 < fVar8) {
    uVar12 = uVar12 | 1;
  }
  if (fVar1 < fVar4) {
    uVar12 = uVar12 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x7c) << 0x18 | (uint)*(byte *)(param_2 + 0x7e) << 8 |
               uVar12 | 0x10000)));
  if (uVar12 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar2 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar3 + *(float *)(param_1 + 0x1b84);
    fVar2 = *(float *)(param_1 + 0x1b88);
    fVar3 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar1;
    param_4[2] = fVar3 * fVar4 + fVar2;
  }
  fVar1 = *(float *)(param_2 + 0x30);
  fVar2 = *(float *)(param_2 + 0x34);
  fVar3 = *(float *)(param_2 + 0x3c);
  fVar4 = *(float *)(param_3 + 0x30);
  fVar5 = *(float *)(param_3 + 0x34);
  fVar6 = *(float *)(param_2 + 0x38);
  fVar7 = *(float *)(param_3 + 0x3c);
  param_4[0x13] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x4c) -
                              (double)*(float *)(param_2 + 0x4c)) +
              (double)*(float *)(param_2 + 0x4c));
  fVar8 = *(float *)(param_3 + 0x38);
  param_4[0xc] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1);
  param_4[0xd] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar2) + (double)fVar2);
  param_4[0xf] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar3) + (double)fVar3);
  param_4[0xe] = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar6) + (double)fVar6);
  fVar1 = *(float *)(param_2 + 0x8c);
  fVar2 = *(float *)(param_2 + 0x84);
  fVar3 = *(float *)(param_2 + 0x88);
  fVar4 = *(float *)(param_3 + 0x8c);
  fVar5 = *(float *)(param_3 + 0x84);
  fVar6 = *(float *)(param_3 + 0x88);
  param_4[0x20] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x80) -
                              (double)*(float *)(param_2 + 0x80)) +
              (double)*(float *)(param_2 + 0x80));
  param_4[0x21] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar2) + (double)fVar2)
  ;
  param_4[0x23] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1)
  ;
  param_4[0x22] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar3) + (double)fVar3)
  ;
  return;
}

/* _gleInterpolEyeNO1111 @ 0xb8004 (668 bytes) */
void _gleInterpolEyeNO1111(int param_1,float *param_2,int param_3,float *param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  char cVar2;
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
  uint uVar13;
  double dVar14;
  double dVar15;
  double dVar16;
  double dVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  
  fVar3 = param_2[0xb];
  fVar4 = *(float *)(param_3 + 0x2c);
  fVar5 = param_2[9];
  fVar6 = param_2[10];
  fVar7 = *(float *)(param_3 + 0x24);
  fVar8 = *(float *)(param_3 + 0x28);
  fVar9 = param_2[4];
  fVar10 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar3) + (double)fVar3);
  fVar4 = param_2[5];
  fVar11 = *(float *)(param_3 + 0x14);
  fVar12 = param_2[6];
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar9) + (double)fVar9);
  fVar9 = *(float *)(param_3 + 0x18);
  fVar10 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar6) + (double)fVar6);
  param_4[4] = fVar3;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar11 - (double)fVar4) + (double)fVar4);
  param_4[7] = fVar1;
  fVar5 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar12) + (double)fVar12);
  cVar2 = *(char *)((int)param_2 + 0x7f);
  uVar13 = 0;
  param_4[5] = fVar4;
  param_4[6] = fVar5;
  if (fVar3 < fVar10) {
    uVar13 = 0x10;
  }
  if (fVar1 <= fVar3) {
    uVar13 = uVar13 | 0x20;
  }
  if (fVar4 < fVar10) {
    uVar13 = uVar13 | 4;
  }
  if (fVar1 <= fVar4) {
    uVar13 = uVar13 | 8;
  }
  if (fVar5 < fVar10) {
    uVar13 = uVar13 | 1;
  }
  if (fVar1 < fVar5) {
    uVar13 = uVar13 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar13 | 0x10000)));
  if (uVar13 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
      fVar5 = fVar5 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar3 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar4 + *(float *)(param_1 + 0x1b84);
    fVar3 = *(float *)(param_1 + 0x1b88);
    fVar4 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar1;
    param_4[2] = fVar4 * fVar5 + fVar3;
  }
  param_4[0x13] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x4c) - (double)param_2[0x13]) +
              (double)param_2[0x13]);
  dVar16 = (double)param_2[0x20];
  dVar17 = (double)param_2[0x21];
  dVar20 = (double)param_2[0x22];
  dVar22 = (double)param_2[0x23];
  if (cVar2 == '\0') {
    dVar14 = (double)param_2[7];
    dVar22 = (double)(float)(dVar22 * dVar14);
    dVar16 = (double)(float)(dVar16 * dVar14);
    dVar17 = (double)(float)(dVar17 * dVar14);
    dVar20 = (double)(float)(dVar20 * dVar14);
  }
  dVar19 = (double)*(float *)(param_3 + 0x80);
  dVar14 = (double)*(float *)(param_3 + 0x84);
  dVar21 = (double)*(float *)(param_3 + 0x88);
  dVar18 = (double)*(float *)(param_3 + 0x8c);
  if (*(char *)(param_3 + 0x7f) == '\0') {
    dVar15 = (double)*(float *)(param_3 + 0x1c);
    dVar18 = (double)(float)(dVar18 * dVar15);
    dVar19 = (double)(float)(dVar19 * dVar15);
    dVar14 = (double)(float)(dVar14 * dVar15);
    dVar21 = (double)(float)(dVar21 * dVar15);
  }
  fVar1 = (float)(fparam_1 * (double)(float)(dVar19 - dVar16) + dVar16);
  fVar3 = (float)(fparam_1 * (double)(float)(dVar14 - dVar17) + dVar17);
  fVar4 = (float)(fparam_1 * (double)(float)(dVar21 - dVar20) + dVar20);
  fVar5 = (float)(fparam_1 * (double)(float)(dVar18 - dVar22) + dVar22);
  if (uVar13 == 0) {
    fVar6 = param_4[3];
    fVar5 = fVar5 * fVar6;
    fVar1 = fVar1 * fVar6;
    fVar3 = fVar3 * fVar6;
    fVar4 = fVar4 * fVar6;
  }
  param_4[0x20] = fVar1;
  param_4[0x21] = fVar3;
  param_4[0x22] = fVar4;
  param_4[0x23] = fVar5;
  fVar1 = param_2[0x10];
  fVar3 = param_2[0x11];
  fVar4 = *(float *)(param_3 + 0x40);
  fVar5 = *(float *)(param_3 + 0x44);
  param_4[0x12] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x48) - (double)param_2[0x12]) +
              (double)param_2[0x12]);
  param_4[0x10] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1)
  ;
  param_4[0x11] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar3) + (double)fVar3)
  ;
  if (param_2 == param_4) {
    return;
  }
  param_4[0x1d] = param_2[0x1d];
  param_4[0x1e] = param_2[0x1e];
  return;
}

/* _gleInterpolEyeNO1111w @ 0xb82a0 (580 bytes) */
void _gleInterpolEyeNO1111w(int param_1,float *param_2,int param_3,float *param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
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
  uint uVar12;
  
  fVar2 = param_2[0xb];
  fVar3 = *(float *)(param_3 + 0x2c);
  fVar4 = param_2[9];
  fVar5 = param_2[10];
  fVar6 = *(float *)(param_3 + 0x24);
  fVar7 = *(float *)(param_3 + 0x28);
  fVar8 = param_2[4];
  fVar9 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar2) + (double)fVar2);
  fVar3 = param_2[5];
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = param_2[6];
  fVar2 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar8) + (double)fVar8);
  fVar8 = *(float *)(param_3 + 0x18);
  fVar9 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[4] = fVar2;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar3) + (double)fVar3);
  param_4[7] = fVar1;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar11) + (double)fVar11);
  uVar12 = 0;
  param_4[5] = fVar3;
  param_4[6] = fVar4;
  if (fVar2 < fVar9) {
    uVar12 = 0x10;
  }
  if (fVar1 <= fVar2) {
    uVar12 = uVar12 | 0x20;
  }
  if (fVar3 < fVar9) {
    uVar12 = uVar12 | 4;
  }
  if (fVar1 <= fVar3) {
    uVar12 = uVar12 | 8;
  }
  if (fVar4 < fVar9) {
    uVar12 = uVar12 | 1;
  }
  if (fVar1 < fVar4) {
    uVar12 = uVar12 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar12 | 0x10000)));
  if (uVar12 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar2 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar3 + *(float *)(param_1 + 0x1b84);
    fVar2 = *(float *)(param_1 + 0x1b88);
    fVar3 = *(float *)(param_1 + 0x1b78);
    param_4[3] = fVar1;
    param_4[2] = fVar3 * fVar4 + fVar2;
  }
  param_4[0x13] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x4c) - (double)param_2[0x13]) +
              (double)param_2[0x13]);
  fVar1 = param_2[0x21];
  fVar2 = param_2[0x22];
  fVar3 = param_2[0x23];
  fVar4 = *(float *)(param_3 + 0x84);
  fVar5 = *(float *)(param_3 + 0x88);
  fVar6 = *(float *)(param_3 + 0x8c);
  param_4[0x20] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x80) - (double)param_2[0x20]) +
              (double)param_2[0x20]);
  param_4[0x21] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1)
  ;
  param_4[0x22] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar2) + (double)fVar2)
  ;
  param_4[0x23] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar3) + (double)fVar3)
  ;
  fVar1 = param_2[0x10];
  fVar2 = param_2[0x11];
  fVar3 = *(float *)(param_3 + 0x40);
  fVar4 = *(float *)(param_3 + 0x44);
  param_4[0x12] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x48) - (double)param_2[0x12]) +
              (double)param_2[0x12]);
  param_4[0x10] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar1) + (double)fVar1)
  ;
  param_4[0x11] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar2) + (double)fVar2)
  ;
  if (param_2 == param_4) {
    return;
  }
  param_4[0x1d] = param_2[0x1d];
  param_4[0x1e] = param_2[0x1e];
  return;
}

/* FUN_000b84e8 @ 0xb84e8 (688 bytes) */
void FUN_000b84e8(int param_1,int param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  char cVar2;
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
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  
  fVar3 = *(float *)(param_3 + 0x2c);
  fVar4 = *(float *)(param_2 + 0x24);
  fVar5 = *(float *)(param_2 + 0x28);
  uVar16 = 0;
  fVar6 = *(float *)(param_3 + 0x24);
  fVar7 = *(float *)(param_3 + 0x28);
  fVar8 = *(float *)(param_2 + 0x10);
  fVar9 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) -
                                 (double)*(float *)(param_2 + 0x1c)) +
                 (double)*(float *)(param_2 + 0x1c));
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) -
                                      (double)*(float *)(param_2 + 0x20)) +
                      (double)*(float *)(param_2 + 0x20));
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar3 - fparam_4) + fparam_4);
  fVar10 = *(float *)(param_2 + 0x14);
  fVar11 = *(float *)(param_3 + 0x14);
  fVar12 = *(float *)(param_2 + 0x18);
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar8) + (double)fVar8);
  fVar8 = *(float *)(param_3 + 0x18);
  fVar9 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[4] = fVar3;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar11 - (double)fVar10) + (double)fVar10);
  param_4[7] = fVar1;
  fVar5 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar12) + (double)fVar12);
  cVar2 = *(char *)(param_2 + 0x7f);
  param_4[5] = fVar4;
  param_4[6] = fVar5;
  if (fVar3 < fVar9) {
    uVar16 = 0x10;
  }
  if (fVar1 <= fVar3) {
    uVar16 = uVar16 | 0x20;
  }
  if (fVar4 < fVar9) {
    uVar16 = uVar16 | 4;
  }
  if (fVar1 <= fVar4) {
    uVar16 = uVar16 | 8;
  }
  if (fVar5 < fVar9) {
    uVar16 = uVar16 | 1;
  }
  if (fVar1 < fVar5) {
    uVar16 = uVar16 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x7c) << 0x18 | (uint)*(byte *)(param_2 + 0x7e) << 8 |
               uVar16 | 0x10000)));
  if (uVar16 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
      fVar5 = fVar5 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar3 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar4 + *(float *)(param_1 + 0x1b84);
    fVar3 = *(float *)(param_1 + 0x1b78);
    fVar4 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar1;
    param_4[2] = fVar3 * fVar5 + fVar4;
  }
  fVar1 = *(float *)(param_2 + 0x34);
  uVar17 = 0;
  fVar3 = *(float *)(param_2 + 0x38);
  fVar4 = *(float *)(param_2 + 0x3c);
  fVar5 = *(float *)(param_3 + 0x34);
  fVar6 = *(float *)(param_3 + 0x38);
  fVar7 = *(float *)(param_3 + 0x3c);
  param_4[0xc] = (float)(fparam_1 *
                         (double)(float)((double)*(float *)(param_3 + 0x30) -
                                        (double)*(float *)(param_2 + 0x30)) +
                        (double)*(float *)(param_2 + 0x30));
  param_4[0xd] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar1) + (double)fVar1);
  param_4[0xe] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar3) + (double)fVar3);
  param_4[0xf] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar4) + (double)fVar4);
  uVar15 = *(uint *)(param_1 + 0x5150);
  do {
    uVar13 = uVar15 >> (uVar17 & 0x3f);
    if ((uVar13 & 1) == 0) {
      if (uVar13 == 0) {
        return;
      }
    }
    else {
      iVar14 = uVar17 * 0x10 + param_2;
      dVar21 = (double)*(float *)(iVar14 + 0x8c);
      dVar20 = (double)*(float *)(iVar14 + 0x80);
      dVar22 = (double)*(float *)(iVar14 + 0x84);
      dVar23 = (double)*(float *)(iVar14 + 0x88);
      if (cVar2 == '\0') {
        dVar18 = (double)*(float *)(param_2 + 0x1c);
        dVar21 = (double)(float)(dVar21 * dVar18);
        dVar20 = (double)(float)(dVar20 * dVar18);
        dVar22 = (double)(float)(dVar22 * dVar18);
        dVar23 = (double)(float)(dVar23 * dVar18);
      }
      iVar14 = uVar17 * 0x10 + param_3;
      dVar26 = (double)*(float *)(iVar14 + 0x8c);
      dVar18 = (double)*(float *)(iVar14 + 0x80);
      dVar25 = (double)*(float *)(iVar14 + 0x84);
      dVar24 = (double)*(float *)(iVar14 + 0x88);
      if (*(char *)(param_3 + 0x7f) == '\0') {
        dVar19 = (double)*(float *)(param_3 + 0x1c);
        dVar26 = (double)(float)(dVar26 * dVar19);
        dVar18 = (double)(float)(dVar18 * dVar19);
        dVar25 = (double)(float)(dVar25 * dVar19);
        dVar24 = (double)(float)(dVar24 * dVar19);
      }
      fVar1 = (float)(fparam_1 * (double)(float)(dVar18 - dVar20) + dVar20);
      fVar3 = (float)(fparam_1 * (double)(float)(dVar25 - dVar22) + dVar22);
      fVar4 = (float)(fparam_1 * (double)(float)(dVar24 - dVar23) + dVar23);
      fVar5 = (float)(fparam_1 * (double)(float)(dVar26 - dVar21) + dVar21);
      if (uVar16 == 0) {
        fVar6 = param_4[3];
        fVar5 = fVar5 * fVar6;
        fVar1 = fVar1 * fVar6;
        fVar3 = fVar3 * fVar6;
        fVar4 = fVar4 * fVar6;
      }
      param_4[uVar17 * 4 + 0x23] = fVar5;
      param_4[uVar17 * 4 + 0x20] = fVar1;
      param_4[uVar17 * 4 + 0x21] = fVar3;
      param_4[uVar17 * 4 + 0x22] = fVar4;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* FUN_000b879c @ 0xb879c (600 bytes) */
void FUN_000b879c(int param_1,int param_2,int param_3,float *param_4,float fparam_1,double fparam_2,float fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
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
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  
  fVar2 = *(float *)(param_3 + 0x2c);
  fVar3 = *(float *)(param_2 + 0x24);
  fVar4 = *(float *)(param_2 + 0x28);
  uVar13 = 0;
  fVar5 = *(float *)(param_3 + 0x24);
  fVar6 = *(float *)(param_3 + 0x28);
  fVar7 = *(float *)(param_2 + 0x10);
  fVar8 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) -
                                 (double)*(float *)(param_2 + 0x1c)) +
                 (double)*(float *)(param_2 + 0x1c));
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) -
                                      (double)*(float *)(param_2 + 0x20)) +
                      (double)*(float *)(param_2 + 0x20));
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar2 - fparam_3) + fparam_3);
  fVar9 = *(float *)(param_2 + 0x14);
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = *(float *)(param_2 + 0x18);
  fVar2 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar7) + (double)fVar7);
  fVar7 = *(float *)(param_3 + 0x18);
  fVar8 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar3) + (double)fVar3);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[4] = fVar2;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar9) + (double)fVar9);
  param_4[7] = fVar1;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar11) + (double)fVar11);
  param_4[5] = fVar3;
  param_4[6] = fVar4;
  if (fVar2 < fVar8) {
    uVar13 = 0x10;
  }
  if (fVar1 <= fVar2) {
    uVar13 = uVar13 | 0x20;
  }
  if (fVar3 < fVar8) {
    uVar13 = uVar13 | 4;
  }
  if (fVar1 <= fVar3) {
    uVar13 = uVar13 | 8;
  }
  if (fVar4 < fVar8) {
    uVar13 = uVar13 | 1;
  }
  if (fVar1 < fVar4) {
    uVar13 = uVar13 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x7c) << 0x18 | (uint)*(byte *)(param_2 + 0x7e) << 8 |
               uVar13 | 0x10000)));
  if (uVar13 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar2 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar3 + *(float *)(param_1 + 0x1b84);
    fVar2 = *(float *)(param_1 + 0x1b78);
    fVar3 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar1;
    param_4[2] = fVar2 * fVar4 + fVar3;
  }
  uVar15 = 0;
  fVar1 = *(float *)(param_2 + 0x34);
  fVar2 = *(float *)(param_2 + 0x38);
  fVar3 = *(float *)(param_2 + 0x3c);
  fVar4 = *(float *)(param_3 + 0x34);
  fVar5 = *(float *)(param_3 + 0x38);
  fVar6 = *(float *)(param_3 + 0x3c);
  param_4[0xc] = (float)(fparam_1 *
                         (double)(float)((double)*(float *)(param_3 + 0x30) -
                                        (double)*(float *)(param_2 + 0x30)) +
                        (double)*(float *)(param_2 + 0x30));
  param_4[0xd] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1);
  param_4[0xe] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar2) + (double)fVar2);
  param_4[0xf] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar3) + (double)fVar3);
  uVar13 = *(uint *)(param_1 + 0x5150);
  do {
    uVar12 = uVar13 >> (uVar15 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        return;
      }
    }
    else {
      iVar14 = uVar15 * 0x10 + param_2;
      iVar16 = uVar15 * 0x10 + param_3;
      fVar1 = *(float *)(iVar14 + 0x8c);
      fVar2 = *(float *)(iVar14 + 0x84);
      fVar3 = *(float *)(iVar14 + 0x88);
      fVar4 = *(float *)(iVar16 + 0x8c);
      fVar5 = *(float *)(iVar16 + 0x84);
      fVar6 = *(float *)(iVar16 + 0x88);
      param_4[uVar15 * 4 + 0x20] =
           (float)(fparam_1 *
                   (double)(float)((double)*(float *)(iVar16 + 0x80) -
                                  (double)*(float *)(iVar14 + 0x80)) +
                  (double)*(float *)(iVar14 + 0x80));
      param_4[uVar15 * 4 + 0x21] =
           (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar2) + (double)fVar2);
      param_4[uVar15 * 4 + 0x22] =
           (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar3) + (double)fVar3);
      param_4[uVar15 * 4 + 0x23] =
           (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1);
    }
    uVar15 = uVar15 + 1;
  } while( true );
}

/* _gleInterpolEyeNO1201 @ 0xb89f4 (704 bytes) */
void _gleInterpolEyeNO1201(int param_1,float *param_2,int param_3,float *param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  char cVar2;
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
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  
  fVar3 = param_2[0xb];
  fVar4 = *(float *)(param_3 + 0x2c);
  fVar5 = param_2[9];
  fVar6 = param_2[10];
  fVar7 = *(float *)(param_3 + 0x24);
  fVar8 = *(float *)(param_3 + 0x28);
  fVar9 = param_2[4];
  fVar10 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar3) + (double)fVar3);
  fVar4 = param_2[5];
  fVar11 = *(float *)(param_3 + 0x14);
  fVar12 = param_2[6];
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar9) + (double)fVar9);
  fVar9 = *(float *)(param_3 + 0x18);
  fVar10 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar6) + (double)fVar6);
  param_4[4] = fVar3;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar11 - (double)fVar4) + (double)fVar4);
  param_4[7] = fVar1;
  fVar5 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar12) + (double)fVar12);
  cVar2 = *(char *)((int)param_2 + 0x7f);
  uVar16 = 0;
  param_4[5] = fVar4;
  param_4[6] = fVar5;
  if (fVar3 < fVar10) {
    uVar16 = 0x10;
  }
  if (fVar1 <= fVar3) {
    uVar16 = uVar16 | 0x20;
  }
  if (fVar4 < fVar10) {
    uVar16 = uVar16 | 4;
  }
  if (fVar1 <= fVar4) {
    uVar16 = uVar16 | 8;
  }
  if (fVar5 < fVar10) {
    uVar16 = uVar16 | 1;
  }
  if (fVar1 < fVar5) {
    uVar16 = uVar16 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar16 | 0x10000)));
  if (uVar16 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
      fVar5 = fVar5 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar3 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar4 + *(float *)(param_1 + 0x1b84);
    fVar3 = *(float *)(param_1 + 0x1b78);
    fVar4 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar1;
    param_4[2] = fVar3 * fVar5 + fVar4;
  }
  uVar15 = *(uint *)(param_1 + 0x5150);
  uVar17 = 0;
  do {
    uVar13 = uVar15 >> (uVar17 & 0x3f);
    if ((uVar13 & 1) == 0) {
      if (uVar13 == 0) {
        fVar1 = param_2[0x10];
        fVar3 = param_2[0x11];
        fVar4 = *(float *)(param_3 + 0x40);
        fVar5 = *(float *)(param_3 + 0x44);
        param_4[0x12] =
             (float)(fparam_1 *
                     (double)(float)((double)*(float *)(param_3 + 0x48) - (double)param_2[0x12]) +
                    (double)param_2[0x12]);
        param_4[0x10] =
             (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1);
        param_4[0x11] =
             (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar3) + (double)fVar3);
        if (param_2 == param_4) {
          return;
        }
        param_4[0x1d] = param_2[0x1d];
        param_4[0x1e] = param_2[0x1e];
        return;
      }
    }
    else {
      dVar26 = (double)param_2[uVar17 * 4 + 0x23];
      dVar20 = (double)param_2[uVar17 * 4 + 0x20];
      dVar21 = (double)param_2[uVar17 * 4 + 0x21];
      dVar22 = (double)param_2[uVar17 * 4 + 0x22];
      if (cVar2 == '\0') {
        dVar18 = (double)param_2[7];
        dVar26 = (double)(float)(dVar26 * dVar18);
        dVar20 = (double)(float)(dVar20 * dVar18);
        dVar21 = (double)(float)(dVar21 * dVar18);
        dVar22 = (double)(float)(dVar22 * dVar18);
      }
      iVar14 = uVar17 * 0x10 + param_3;
      dVar23 = (double)*(float *)(iVar14 + 0x8c);
      dVar25 = (double)*(float *)(iVar14 + 0x80);
      dVar18 = (double)*(float *)(iVar14 + 0x84);
      dVar24 = (double)*(float *)(iVar14 + 0x88);
      if (*(char *)(param_3 + 0x7f) == '\0') {
        dVar19 = (double)*(float *)(param_3 + 0x1c);
        dVar23 = (double)(float)(dVar23 * dVar19);
        dVar25 = (double)(float)(dVar25 * dVar19);
        dVar18 = (double)(float)(dVar18 * dVar19);
        dVar24 = (double)(float)(dVar24 * dVar19);
      }
      fVar1 = (float)(fparam_1 * (double)(float)(dVar25 - dVar20) + dVar20);
      fVar3 = (float)(fparam_1 * (double)(float)(dVar18 - dVar21) + dVar21);
      fVar4 = (float)(fparam_1 * (double)(float)(dVar24 - dVar22) + dVar22);
      fVar5 = (float)(fparam_1 * (double)(float)(dVar23 - dVar26) + dVar26);
      if (uVar16 == 0) {
        fVar6 = param_4[3];
        fVar5 = fVar5 * fVar6;
        fVar1 = fVar1 * fVar6;
        fVar3 = fVar3 * fVar6;
        fVar4 = fVar4 * fVar6;
      }
      param_4[uVar17 * 4 + 0x23] = fVar5;
      param_4[uVar17 * 4 + 0x20] = fVar1;
      param_4[uVar17 * 4 + 0x21] = fVar3;
      param_4[uVar17 * 4 + 0x22] = fVar4;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* _gleInterpolEyeNO1201w @ 0xb8cb4 (616 bytes) */
void _gleInterpolEyeNO1201w(int param_1,float *param_2,int param_3,float *param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
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
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  
  fVar2 = param_2[0xb];
  fVar3 = *(float *)(param_3 + 0x2c);
  fVar4 = param_2[9];
  fVar5 = param_2[10];
  fVar6 = *(float *)(param_3 + 0x24);
  fVar7 = *(float *)(param_3 + 0x28);
  fVar8 = param_2[4];
  fVar9 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar2) + (double)fVar2);
  fVar3 = param_2[5];
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = param_2[6];
  fVar2 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar8) + (double)fVar8);
  fVar8 = *(float *)(param_3 + 0x18);
  fVar9 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[4] = fVar2;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar3) + (double)fVar3);
  param_4[7] = fVar1;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar11) + (double)fVar11);
  uVar13 = 0;
  param_4[5] = fVar3;
  param_4[6] = fVar4;
  if (fVar2 < fVar9) {
    uVar13 = 0x10;
  }
  if (fVar1 <= fVar2) {
    uVar13 = uVar13 | 0x20;
  }
  if (fVar3 < fVar9) {
    uVar13 = uVar13 | 4;
  }
  if (fVar1 <= fVar3) {
    uVar13 = uVar13 | 8;
  }
  if (fVar4 < fVar9) {
    uVar13 = uVar13 | 1;
  }
  if (fVar1 < fVar4) {
    uVar13 = uVar13 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar13 | 0x10000)));
  if (uVar13 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar2 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar3 + *(float *)(param_1 + 0x1b84);
    fVar2 = *(float *)(param_1 + 0x1b78);
    fVar3 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar1;
    param_4[2] = fVar2 * fVar4 + fVar3;
  }
  uVar13 = *(uint *)(param_1 + 0x5150);
  uVar14 = 0;
  do {
    uVar12 = uVar13 >> (uVar14 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        fVar1 = param_2[0x10];
        fVar2 = param_2[0x11];
        fVar3 = *(float *)(param_3 + 0x40);
        fVar4 = *(float *)(param_3 + 0x44);
        param_4[0x12] =
             (float)(fparam_1 *
                     (double)(float)((double)*(float *)(param_3 + 0x48) - (double)param_2[0x12]) +
                    (double)param_2[0x12]);
        param_4[0x10] =
             (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar1) + (double)fVar1);
        param_4[0x11] =
             (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar2) + (double)fVar2);
        if (param_2 == param_4) {
          return;
        }
        param_4[0x1d] = param_2[0x1d];
        param_4[0x1e] = param_2[0x1e];
        return;
      }
    }
    else {
      iVar15 = uVar14 * 0x10 + param_3;
      fVar1 = param_2[uVar14 * 4 + 0x23];
      fVar2 = param_2[uVar14 * 4 + 0x21];
      fVar3 = param_2[uVar14 * 4 + 0x22];
      fVar4 = *(float *)(iVar15 + 0x8c);
      fVar5 = *(float *)(iVar15 + 0x84);
      fVar6 = *(float *)(iVar15 + 0x88);
      param_4[uVar14 * 4 + 0x20] =
           (float)(fparam_1 *
                   (double)(float)((double)*(float *)(iVar15 + 0x80) -
                                  (double)param_2[uVar14 * 4 + 0x20]) +
                  (double)param_2[uVar14 * 4 + 0x20]);
      param_4[uVar14 * 4 + 0x21] =
           (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar2) + (double)fVar2);
      param_4[uVar14 * 4 + 0x22] =
           (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar3) + (double)fVar3);
      param_4[uVar14 * 4 + 0x23] =
           (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1);
    }
    uVar14 = uVar14 + 1;
  } while( true );
}

/* FUN_000b8f20 @ 0xb8f20 (708 bytes) */
void FUN_000b8f20(int param_1,int param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,float fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  char cVar2;
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
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  
  fVar3 = *(float *)(param_3 + 0x2c);
  fVar4 = *(float *)(param_2 + 0x24);
  fVar5 = *(float *)(param_2 + 0x28);
  uVar16 = 0;
  fVar6 = *(float *)(param_3 + 0x24);
  fVar7 = *(float *)(param_3 + 0x28);
  fVar8 = *(float *)(param_2 + 0x10);
  fVar9 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) -
                                 (double)*(float *)(param_2 + 0x1c)) +
                 (double)*(float *)(param_2 + 0x1c));
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) -
                                      (double)*(float *)(param_2 + 0x20)) +
                      (double)*(float *)(param_2 + 0x20));
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar3 - fparam_4) + fparam_4);
  fVar10 = *(float *)(param_2 + 0x14);
  fVar11 = *(float *)(param_3 + 0x14);
  fVar12 = *(float *)(param_2 + 0x18);
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar8) + (double)fVar8);
  fVar8 = *(float *)(param_3 + 0x18);
  fVar9 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[4] = fVar3;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar11 - (double)fVar10) + (double)fVar10);
  param_4[7] = fVar1;
  fVar5 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar12) + (double)fVar12);
  cVar2 = *(char *)(param_2 + 0x7f);
  param_4[5] = fVar4;
  param_4[6] = fVar5;
  if (fVar3 < fVar9) {
    uVar16 = 0x10;
  }
  if (fVar1 <= fVar3) {
    uVar16 = uVar16 | 0x20;
  }
  if (fVar4 < fVar9) {
    uVar16 = uVar16 | 4;
  }
  if (fVar1 <= fVar4) {
    uVar16 = uVar16 | 8;
  }
  if (fVar5 < fVar9) {
    uVar16 = uVar16 | 1;
  }
  if (fVar1 < fVar5) {
    uVar16 = uVar16 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x7c) << 0x18 | (uint)*(byte *)(param_2 + 0x7e) << 8 |
               uVar16 | 0x10000)));
  if (uVar16 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
      fVar5 = fVar5 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar3 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar4 + *(float *)(param_1 + 0x1b84);
    fVar3 = *(float *)(param_1 + 0x1b78);
    fVar4 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar1;
    param_4[2] = fVar3 * fVar5 + fVar4;
  }
  uVar17 = 0;
  fVar1 = *(float *)(param_2 + 0x30);
  fVar3 = *(float *)(param_2 + 0x34);
  fVar4 = *(float *)(param_2 + 0x3c);
  fVar5 = *(float *)(param_3 + 0x30);
  fVar6 = *(float *)(param_3 + 0x34);
  fVar7 = *(float *)(param_2 + 0x38);
  fVar8 = *(float *)(param_3 + 0x3c);
  param_4[0x13] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x4c) -
                              (double)*(float *)(param_2 + 0x4c)) +
              (double)*(float *)(param_2 + 0x4c));
  fVar9 = *(float *)(param_3 + 0x38);
  param_4[0xc] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar1) + (double)fVar1);
  param_4[0xd] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar3) + (double)fVar3);
  param_4[0xf] = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar4) + (double)fVar4);
  param_4[0xe] = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar7) + (double)fVar7);
  uVar15 = *(uint *)(param_1 + 0x5150);
  do {
    uVar13 = uVar15 >> (uVar17 & 0x3f);
    if ((uVar13 & 1) == 0) {
      if (uVar13 == 0) {
        return;
      }
    }
    else {
      iVar14 = uVar17 * 0x10 + param_2;
      dVar21 = (double)*(float *)(iVar14 + 0x8c);
      dVar20 = (double)*(float *)(iVar14 + 0x80);
      dVar22 = (double)*(float *)(iVar14 + 0x84);
      dVar24 = (double)*(float *)(iVar14 + 0x88);
      if (cVar2 == '\0') {
        dVar18 = (double)*(float *)(param_2 + 0x1c);
        dVar21 = (double)(float)(dVar21 * dVar18);
        dVar20 = (double)(float)(dVar20 * dVar18);
        dVar22 = (double)(float)(dVar22 * dVar18);
        dVar24 = (double)(float)(dVar24 * dVar18);
      }
      iVar14 = uVar17 * 0x10 + param_3;
      dVar25 = (double)*(float *)(iVar14 + 0x8c);
      dVar18 = (double)*(float *)(iVar14 + 0x80);
      dVar23 = (double)*(float *)(iVar14 + 0x84);
      dVar26 = (double)*(float *)(iVar14 + 0x88);
      if (*(char *)(param_3 + 0x7f) == '\0') {
        dVar19 = (double)*(float *)(param_3 + 0x1c);
        dVar25 = (double)(float)(dVar25 * dVar19);
        dVar18 = (double)(float)(dVar18 * dVar19);
        dVar23 = (double)(float)(dVar23 * dVar19);
        dVar26 = (double)(float)(dVar26 * dVar19);
      }
      fVar1 = (float)(fparam_1 * (double)(float)(dVar18 - dVar20) + dVar20);
      fVar3 = (float)(fparam_1 * (double)(float)(dVar23 - dVar22) + dVar22);
      fVar4 = (float)(fparam_1 * (double)(float)(dVar26 - dVar24) + dVar24);
      fVar5 = (float)(fparam_1 * (double)(float)(dVar25 - dVar21) + dVar21);
      if (uVar16 == 0) {
        fVar6 = param_4[3];
        fVar5 = fVar5 * fVar6;
        fVar1 = fVar1 * fVar6;
        fVar3 = fVar3 * fVar6;
        fVar4 = fVar4 * fVar6;
      }
      param_4[uVar17 * 4 + 0x23] = fVar5;
      param_4[uVar17 * 4 + 0x20] = fVar1;
      param_4[uVar17 * 4 + 0x21] = fVar3;
      param_4[uVar17 * 4 + 0x22] = fVar4;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* FUN_000b91e8 @ 0xb91e8 (620 bytes) */
void FUN_000b91e8(int param_1,int param_2,int param_3,float *param_4,float fparam_1,double fparam_2,float fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
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
  uint uVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  
  fVar2 = *(float *)(param_3 + 0x2c);
  fVar3 = *(float *)(param_2 + 0x24);
  fVar4 = *(float *)(param_2 + 0x28);
  uVar13 = 0;
  fVar5 = *(float *)(param_3 + 0x24);
  fVar6 = *(float *)(param_3 + 0x28);
  fVar7 = *(float *)(param_2 + 0x10);
  fVar8 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) -
                                 (double)*(float *)(param_2 + 0x1c)) +
                 (double)*(float *)(param_2 + 0x1c));
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) -
                                      (double)*(float *)(param_2 + 0x20)) +
                      (double)*(float *)(param_2 + 0x20));
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar2 - fparam_3) + fparam_3);
  fVar9 = *(float *)(param_2 + 0x14);
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = *(float *)(param_2 + 0x18);
  fVar2 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar7) + (double)fVar7);
  fVar7 = *(float *)(param_3 + 0x18);
  fVar8 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar3) + (double)fVar3);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[4] = fVar2;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar9) + (double)fVar9);
  param_4[7] = fVar1;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar11) + (double)fVar11);
  param_4[5] = fVar3;
  param_4[6] = fVar4;
  if (fVar2 < fVar8) {
    uVar13 = 0x10;
  }
  if (fVar1 <= fVar2) {
    uVar13 = uVar13 | 0x20;
  }
  if (fVar3 < fVar8) {
    uVar13 = uVar13 | 4;
  }
  if (fVar1 <= fVar3) {
    uVar13 = uVar13 | 8;
  }
  if (fVar4 < fVar8) {
    uVar13 = uVar13 | 1;
  }
  if (fVar1 < fVar4) {
    uVar13 = uVar13 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x7c) << 0x18 | (uint)*(byte *)(param_2 + 0x7e) << 8 |
               uVar13 | 0x10000)));
  if (uVar13 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar2 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar3 + *(float *)(param_1 + 0x1b84);
    fVar2 = *(float *)(param_1 + 0x1b78);
    fVar3 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar1;
    param_4[2] = fVar2 * fVar4 + fVar3;
  }
  uVar15 = 0;
  fVar1 = *(float *)(param_2 + 0x30);
  fVar2 = *(float *)(param_2 + 0x34);
  fVar3 = *(float *)(param_2 + 0x3c);
  fVar4 = *(float *)(param_3 + 0x30);
  fVar5 = *(float *)(param_3 + 0x34);
  fVar6 = *(float *)(param_2 + 0x38);
  fVar7 = *(float *)(param_3 + 0x3c);
  param_4[0x13] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x4c) -
                              (double)*(float *)(param_2 + 0x4c)) +
              (double)*(float *)(param_2 + 0x4c));
  fVar8 = *(float *)(param_3 + 0x38);
  param_4[0xc] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1);
  param_4[0xd] = (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar2) + (double)fVar2);
  param_4[0xf] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar3) + (double)fVar3);
  param_4[0xe] = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar6) + (double)fVar6);
  uVar13 = *(uint *)(param_1 + 0x5150);
  do {
    uVar12 = uVar13 >> (uVar15 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        return;
      }
    }
    else {
      iVar14 = uVar15 * 0x10 + param_2;
      iVar16 = uVar15 * 0x10 + param_3;
      fVar1 = *(float *)(iVar14 + 0x8c);
      fVar2 = *(float *)(iVar14 + 0x84);
      fVar3 = *(float *)(iVar14 + 0x88);
      fVar4 = *(float *)(iVar16 + 0x8c);
      fVar5 = *(float *)(iVar16 + 0x84);
      fVar6 = *(float *)(iVar16 + 0x88);
      param_4[uVar15 * 4 + 0x20] =
           (float)(fparam_1 *
                   (double)(float)((double)*(float *)(iVar16 + 0x80) -
                                  (double)*(float *)(iVar14 + 0x80)) +
                  (double)*(float *)(iVar14 + 0x80));
      param_4[uVar15 * 4 + 0x21] =
           (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar2) + (double)fVar2);
      param_4[uVar15 * 4 + 0x22] =
           (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar3) + (double)fVar3);
      param_4[uVar15 * 4 + 0x23] =
           (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1);
    }
    uVar15 = uVar15 + 1;
  } while( true );
}

/* _gleInterpolEyeNO1211 @ 0xb9454 (724 bytes) */
void _gleInterpolEyeNO1211(int param_1,float *param_2,int param_3,float *param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  char cVar2;
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
  uint uVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  
  fVar3 = param_2[0xb];
  fVar4 = *(float *)(param_3 + 0x2c);
  fVar5 = param_2[9];
  fVar6 = param_2[10];
  fVar7 = *(float *)(param_3 + 0x24);
  fVar8 = *(float *)(param_3 + 0x28);
  fVar9 = param_2[4];
  fVar10 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar3) + (double)fVar3);
  fVar4 = param_2[5];
  fVar11 = *(float *)(param_3 + 0x14);
  fVar12 = param_2[6];
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar9) + (double)fVar9);
  fVar9 = *(float *)(param_3 + 0x18);
  fVar10 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar6) + (double)fVar6);
  param_4[4] = fVar3;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar11 - (double)fVar4) + (double)fVar4);
  param_4[7] = fVar1;
  fVar5 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar12) + (double)fVar12);
  cVar2 = *(char *)((int)param_2 + 0x7f);
  uVar16 = 0;
  param_4[5] = fVar4;
  param_4[6] = fVar5;
  if (fVar3 < fVar10) {
    uVar16 = 0x10;
  }
  if (fVar1 <= fVar3) {
    uVar16 = uVar16 | 0x20;
  }
  if (fVar4 < fVar10) {
    uVar16 = uVar16 | 4;
  }
  if (fVar1 <= fVar4) {
    uVar16 = uVar16 | 8;
  }
  if (fVar5 < fVar10) {
    uVar16 = uVar16 | 1;
  }
  if (fVar1 < fVar5) {
    uVar16 = uVar16 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar16 | 0x10000)));
  if (uVar16 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
      fVar5 = fVar5 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar3 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar4 + *(float *)(param_1 + 0x1b84);
    fVar3 = *(float *)(param_1 + 0x1b78);
    fVar4 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar1;
    param_4[2] = fVar3 * fVar5 + fVar4;
  }
  uVar17 = 0;
  param_4[0x13] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x4c) - (double)param_2[0x13]) +
              (double)param_2[0x13]);
  uVar15 = *(uint *)(param_1 + 0x5150);
  do {
    uVar13 = uVar15 >> (uVar17 & 0x3f);
    if ((uVar13 & 1) == 0) {
      if (uVar13 == 0) {
        fVar1 = param_2[0x10];
        fVar3 = param_2[0x11];
        fVar4 = *(float *)(param_3 + 0x40);
        fVar5 = *(float *)(param_3 + 0x44);
        param_4[0x12] =
             (float)(fparam_1 *
                     (double)(float)((double)*(float *)(param_3 + 0x48) - (double)param_2[0x12]) +
                    (double)param_2[0x12]);
        param_4[0x10] =
             (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1);
        param_4[0x11] =
             (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar3) + (double)fVar3);
        if (param_2 == param_4) {
          return;
        }
        param_4[0x1d] = param_2[0x1d];
        param_4[0x1e] = param_2[0x1e];
        return;
      }
    }
    else {
      dVar26 = (double)param_2[uVar17 * 4 + 0x23];
      dVar20 = (double)param_2[uVar17 * 4 + 0x20];
      dVar21 = (double)param_2[uVar17 * 4 + 0x21];
      dVar24 = (double)param_2[uVar17 * 4 + 0x22];
      if (cVar2 == '\0') {
        dVar18 = (double)param_2[7];
        dVar26 = (double)(float)(dVar26 * dVar18);
        dVar20 = (double)(float)(dVar20 * dVar18);
        dVar21 = (double)(float)(dVar21 * dVar18);
        dVar24 = (double)(float)(dVar24 * dVar18);
      }
      iVar14 = uVar17 * 0x10 + param_3;
      dVar22 = (double)*(float *)(iVar14 + 0x8c);
      dVar23 = (double)*(float *)(iVar14 + 0x80);
      dVar18 = (double)*(float *)(iVar14 + 0x84);
      dVar25 = (double)*(float *)(iVar14 + 0x88);
      if (*(char *)(param_3 + 0x7f) == '\0') {
        dVar19 = (double)*(float *)(param_3 + 0x1c);
        dVar22 = (double)(float)(dVar22 * dVar19);
        dVar23 = (double)(float)(dVar23 * dVar19);
        dVar18 = (double)(float)(dVar18 * dVar19);
        dVar25 = (double)(float)(dVar25 * dVar19);
      }
      fVar1 = (float)(fparam_1 * (double)(float)(dVar23 - dVar20) + dVar20);
      fVar3 = (float)(fparam_1 * (double)(float)(dVar18 - dVar21) + dVar21);
      fVar4 = (float)(fparam_1 * (double)(float)(dVar25 - dVar24) + dVar24);
      fVar5 = (float)(fparam_1 * (double)(float)(dVar22 - dVar26) + dVar26);
      if (uVar16 == 0) {
        fVar6 = param_4[3];
        fVar5 = fVar5 * fVar6;
        fVar1 = fVar1 * fVar6;
        fVar3 = fVar3 * fVar6;
        fVar4 = fVar4 * fVar6;
      }
      param_4[uVar17 * 4 + 0x23] = fVar5;
      param_4[uVar17 * 4 + 0x20] = fVar1;
      param_4[uVar17 * 4 + 0x21] = fVar3;
      param_4[uVar17 * 4 + 0x22] = fVar4;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* _gleInterpolEyeNO1211w @ 0xb9728 (636 bytes) */
void _gleInterpolEyeNO1211w(int param_1,float *param_2,int param_3,float *param_4,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
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
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  
  fVar2 = param_2[0xb];
  fVar3 = *(float *)(param_3 + 0x2c);
  fVar4 = param_2[9];
  fVar5 = param_2[10];
  fVar6 = *(float *)(param_3 + 0x24);
  fVar7 = *(float *)(param_3 + 0x28);
  fVar8 = param_2[4];
  fVar9 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar2) + (double)fVar2);
  fVar3 = param_2[5];
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = param_2[6];
  fVar2 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar8) + (double)fVar8);
  fVar8 = *(float *)(param_3 + 0x18);
  fVar9 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[4] = fVar2;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar3) + (double)fVar3);
  param_4[7] = fVar1;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar11) + (double)fVar11);
  uVar13 = 0;
  param_4[5] = fVar3;
  param_4[6] = fVar4;
  if (fVar2 < fVar9) {
    uVar13 = 0x10;
  }
  if (fVar1 <= fVar2) {
    uVar13 = uVar13 | 0x20;
  }
  if (fVar3 < fVar9) {
    uVar13 = uVar13 | 4;
  }
  if (fVar1 <= fVar3) {
    uVar13 = uVar13 | 8;
  }
  if (fVar4 < fVar9) {
    uVar13 = uVar13 | 1;
  }
  if (fVar1 < fVar4) {
    uVar13 = uVar13 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar13 | 0x10000)));
  if (uVar13 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar2 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar3 + *(float *)(param_1 + 0x1b84);
    fVar2 = *(float *)(param_1 + 0x1b78);
    fVar3 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar1;
    param_4[2] = fVar2 * fVar4 + fVar3;
  }
  uVar14 = 0;
  param_4[0x13] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x4c) - (double)param_2[0x13]) +
              (double)param_2[0x13]);
  uVar13 = *(uint *)(param_1 + 0x5150);
  do {
    uVar12 = uVar13 >> (uVar14 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        fVar1 = param_2[0x10];
        fVar2 = param_2[0x11];
        fVar3 = *(float *)(param_3 + 0x40);
        fVar4 = *(float *)(param_3 + 0x44);
        param_4[0x12] =
             (float)(fparam_1 *
                     (double)(float)((double)*(float *)(param_3 + 0x48) - (double)param_2[0x12]) +
                    (double)param_2[0x12]);
        param_4[0x10] =
             (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar1) + (double)fVar1);
        param_4[0x11] =
             (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar2) + (double)fVar2);
        if (param_2 == param_4) {
          return;
        }
        param_4[0x1d] = param_2[0x1d];
        param_4[0x1e] = param_2[0x1e];
        return;
      }
    }
    else {
      iVar15 = uVar14 * 0x10 + param_3;
      fVar1 = param_2[uVar14 * 4 + 0x23];
      fVar2 = param_2[uVar14 * 4 + 0x21];
      fVar3 = param_2[uVar14 * 4 + 0x22];
      fVar4 = *(float *)(iVar15 + 0x8c);
      fVar5 = *(float *)(iVar15 + 0x84);
      fVar6 = *(float *)(iVar15 + 0x88);
      param_4[uVar14 * 4 + 0x20] =
           (float)(fparam_1 *
                   (double)(float)((double)*(float *)(iVar15 + 0x80) -
                                  (double)param_2[uVar14 * 4 + 0x20]) +
                  (double)param_2[uVar14 * 4 + 0x20]);
      param_4[uVar14 * 4 + 0x21] =
           (float)(fparam_1 * (double)(float)((double)fVar5 - (double)fVar2) + (double)fVar2);
      param_4[uVar14 * 4 + 0x22] =
           (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar3) + (double)fVar3);
      param_4[uVar14 * 4 + 0x23] =
           (float)(fparam_1 * (double)(float)((double)fVar4 - (double)fVar1) + (double)fVar1);
    }
    uVar14 = uVar14 + 1;
  } while( true );
}

/* _gleInterpolEyeAllFlat @ 0xb99a4 (728 bytes) */
void _gleInterpolEyeAllFlat(int param_1,float *param_2,int param_3,float *param_4,float fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float fVar1;
  char cVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  uint uVar12;
  int iVar13;
  float fVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  double dVar18;
  double dVar19;
  double dVar20;
  double dVar21;
  double dVar22;
  double dVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  
  fVar14 = param_2[0xb];
  fVar3 = *(float *)(param_3 + 0x2c);
  fVar4 = param_2[9];
  fVar5 = param_2[10];
  uVar16 = 0;
  fVar6 = *(float *)(param_3 + 0x24);
  fVar7 = *(float *)(param_3 + 0x28);
  fVar8 = param_2[4];
  fVar9 = *(float *)(param_3 + 0x10);
  fVar1 = (float)(fparam_1 *
                  (double)(float)((double)*(float *)(param_3 + 0x1c) - (double)param_2[7]) +
                 (double)param_2[7]);
  param_4[8] = (float)(fparam_1 *
                       (double)(float)((double)*(float *)(param_3 + 0x20) - (double)param_2[8]) +
                      (double)param_2[8]);
  param_4[0xb] = (float)(fparam_1 * (double)(float)((double)fVar3 - (double)fVar14) + (double)fVar14
                        );
  fVar3 = param_2[5];
  fVar10 = *(float *)(param_3 + 0x14);
  fVar11 = param_2[6];
  fVar14 = (float)(fparam_1 * (double)(float)((double)fVar9 - (double)fVar8) + (double)fVar8);
  fVar8 = *(float *)(param_3 + 0x18);
  fVar9 = -fVar1;
  param_4[9] = (float)(fparam_1 * (double)(float)((double)fVar6 - (double)fVar4) + (double)fVar4);
  param_4[10] = (float)(fparam_1 * (double)(float)((double)fVar7 - (double)fVar5) + (double)fVar5);
  param_4[4] = fVar14;
  fVar3 = (float)(fparam_1 * (double)(float)((double)fVar10 - (double)fVar3) + (double)fVar3);
  param_4[7] = fVar1;
  fVar4 = (float)(fparam_1 * (double)(float)((double)fVar8 - (double)fVar11) + (double)fVar11);
  cVar2 = *(char *)((int)param_2 + 0x7f);
  param_4[5] = fVar3;
  param_4[6] = fVar4;
  if (fVar14 < fVar9) {
    uVar16 = 0x10;
  }
  if (fVar1 <= fVar14) {
    uVar16 = uVar16 | 0x20;
  }
  if (fVar3 < fVar9) {
    uVar16 = uVar16 | 4;
  }
  if (fVar1 <= fVar3) {
    uVar16 = uVar16 | 8;
  }
  if (fVar4 < fVar9) {
    uVar16 = uVar16 | 1;
  }
  if (fVar1 < fVar4) {
    uVar16 = uVar16 | 2;
  }
  param_4[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(param_2 + 0x1f) << 0x18 | (uint)*(byte *)((int)param_2 + 0x7e) << 8 |
               uVar16 | 0x10000)));
  if (uVar16 == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar14 = fVar14 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *param_4 = *(float *)(param_1 + 0x1b70) * fVar14 + *(float *)(param_1 + 0x1b80);
    param_4[1] = *(float *)(param_1 + 0x1b74) * fVar3 + *(float *)(param_1 + 0x1b84);
    fVar14 = *(float *)(param_1 + 0x1b78);
    fVar3 = *(float *)(param_1 + 0x1b88);
    param_4[3] = fVar1;
    param_4[2] = fVar14 * fVar4 + fVar3;
  }
  fVar1 = param_2[0x13];
  uVar17 = 0;
  fVar14 = *(float *)(param_3 + 0x4c);
  param_4[0x17] =
       (float)(fparam_1 *
               (double)(float)((double)*(float *)(param_3 + 0x5c) - (double)param_2[0x17]) +
              (double)param_2[0x17]);
  param_4[0x13] =
       (float)(fparam_1 * (double)(float)((double)fVar14 - (double)fVar1) + (double)fVar1);
  uVar15 = *(uint *)(param_1 + 0x5150);
  do {
    uVar12 = uVar15 >> (uVar17 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        if (param_2 == param_4) {
          return;
        }
        *(undefined8 *)(param_4 + 0xc) = *(undefined8 *)(param_2 + 0xc);
        *(undefined8 *)(param_4 + 0xe) = *(undefined8 *)(param_2 + 0xe);
        *(undefined8 *)(param_4 + 0x10) = *(undefined8 *)(param_2 + 0x10);
        param_4[0x12] = param_2[0x12];
        *(undefined8 *)(param_4 + 0x14) = *(undefined8 *)(param_2 + 0x14);
        fVar1 = param_2[0x16];
        param_4[0x1d] = param_2[0x1d];
        fVar14 = param_2[0x1e];
        param_4[0x16] = fVar1;
        param_4[0x1e] = fVar14;
        return;
      }
    }
    else {
      dVar26 = (double)param_2[uVar17 * 4 + 0x23];
      dVar20 = (double)param_2[uVar17 * 4 + 0x20];
      dVar21 = (double)param_2[uVar17 * 4 + 0x21];
      dVar22 = (double)param_2[uVar17 * 4 + 0x22];
      if (cVar2 == '\0') {
        dVar18 = (double)param_2[7];
        dVar26 = (double)(float)(dVar26 * dVar18);
        dVar20 = (double)(float)(dVar20 * dVar18);
        dVar21 = (double)(float)(dVar21 * dVar18);
        dVar22 = (double)(float)(dVar22 * dVar18);
      }
      iVar13 = uVar17 * 0x10 + param_3;
      dVar23 = (double)*(float *)(iVar13 + 0x8c);
      dVar18 = (double)*(float *)(iVar13 + 0x80);
      dVar25 = (double)*(float *)(iVar13 + 0x84);
      dVar24 = (double)*(float *)(iVar13 + 0x88);
      if (*(char *)(param_3 + 0x7f) == '\0') {
        dVar19 = (double)*(float *)(param_3 + 0x1c);
        dVar23 = (double)(float)(dVar23 * dVar19);
        dVar18 = (double)(float)(dVar18 * dVar19);
        dVar25 = (double)(float)(dVar25 * dVar19);
        dVar24 = (double)(float)(dVar24 * dVar19);
      }
      fVar1 = (float)(fparam_1 * (double)(float)(dVar18 - dVar20) + dVar20);
      fVar14 = (float)(fparam_1 * (double)(float)(dVar25 - dVar21) + dVar21);
      fVar3 = (float)(fparam_1 * (double)(float)(dVar24 - dVar22) + dVar22);
      fVar4 = (float)(fparam_1 * (double)(float)(dVar23 - dVar26) + dVar26);
      if (uVar16 == 0) {
        fVar5 = param_4[3];
        fVar4 = fVar4 * fVar5;
        fVar1 = fVar1 * fVar5;
        fVar14 = fVar14 * fVar5;
        fVar3 = fVar3 * fVar5;
      }
      param_4[uVar17 * 4 + 0x23] = fVar4;
      param_4[uVar17 * 4 + 0x20] = fVar1;
      param_4[uVar17 * 4 + 0x21] = fVar14;
      param_4[uVar17 * 4 + 0x22] = fVar3;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

