#include "decls.h"

/* _glFinalCombinerInputNV_Comp @ 0xb423c (100 bytes) */
int _glFinalCombinerInputNV_Comp(glContext, variable, input, mapping, componentUsage)
  undefined4 glContext;
  undefined4 variable;
  undefined4 input;
  undefined4 mapping;
  undefined4 componentUsage;
{
  undefined4 *listRecord;
  
  listRecord = (undefined4 *)_gleAddListItem(glContext,PTR__glFinalCombinerInputNV_ListExec_001104d4,0x10)
  ;
  if (listRecord != (undefined4 *)0x0) {
    listRecord[3] = componentUsage;
    *listRecord = variable;
    listRecord[1] = input;
    listRecord[2] = mapping;
  }
  return listRecord;
}

/* _glCombinerParameterfvNV_CompExec @ 0xb42a0 (64 bytes) */
void _glCombinerParameterfvNV_CompExec(glContext, pname, params)
  undefined4 glContext;
  undefined4 pname;
  undefined4 params;
{
  _glCombinerParameterfvNV_Comp(glContext,pname,params);
  _glCombinerParameterfvNV_Exec(glContext,pname,params);
  return;
}

/* _glCombinerStageParameterfvNV_CompExec @ 0xb42e0 (72 bytes) */
void _glCombinerStageParameterfvNV_CompExec(glContext, stage, pname, params)
  undefined4 glContext;
  undefined4 stage;
  undefined4 pname;
  undefined4 params;
{
  _glCombinerStageParameterfvNV_Comp(glContext,stage,pname,params);
  _glCombinerStageParameterfvNV_Exec(glContext,stage,pname,params);
  return;
}

/* _glCombinerParameterfNV_CompExec @ 0xb4328 (72 bytes) */
void _glCombinerParameterfNV_CompExec(undefined4 glContext,undefined4 pname,float param)
{
  ((undefined4 * (*)())_glCombinerParameterfNV_Comp)(glContext,pname,param);
  ((void (*)())_glCombinerParameterfNV_Exec)(glContext,pname,param);
  return;
}

/* _glCombinerParameterivNV_CompExec @ 0xb4370 (64 bytes) */
void _glCombinerParameterivNV_CompExec(glContext, pname, params)
  undefined4 glContext;
  undefined4 pname;
  undefined4 params;
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
  
  _glCombinerParameterivNV_Comp(glContext,pname,params);
  ((void (*)())_glCombinerParameterivNV_Exec)(glContext,pname,params,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)));
  return;
}

/* _glCombinerParameteriNV_CompExec @ 0xb43b0 (64 bytes) */
void _glCombinerParameteriNV_CompExec(glContext, pname, param)
  undefined4 glContext;
  undefined4 pname;
  undefined4 param;
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
  
  _glCombinerParameteriNV_Comp(glContext,pname,param);
  ((void (*)())_glCombinerParameteriNV_Exec)(glContext,pname,param,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
             (double)CONCAT44(in_LR,(*(undefined4 *)(*(unsigned int *)__builtin_frame_address(0) + 0xc))),(*(double *)(*(unsigned int *)__builtin_frame_address(0) + 0x10)));
  return;
}

/* _glCombinerInputNV_CompExec @ 0xb43f0 (96 bytes) */
void _glCombinerInputNV_CompExec(glContext, stage, portion, variable, input, mapping, componentUsage)
  undefined4 glContext;
  undefined4 stage;
  undefined4 portion;
  undefined4 variable;
  undefined4 input;
  undefined4 mapping;
  undefined4 componentUsage;
{
  _glCombinerInputNV_Comp(glContext,stage,portion,variable,input,mapping,componentUsage);
  _glCombinerInputNV_Exec(glContext,stage,portion,variable,input,mapping,componentUsage);
  return;
}

/* _glCombinerOutputNV_CompExec @ 0xb4450 (140 bytes) */
void _glCombinerOutputNV_CompExec(glContext, stage, portion, abOutput, cdOutput, sumOutput, scale, bias, abDotProduct, cdDotProduct, muxSum)
  undefined4 glContext;
  undefined4 stage;
  undefined4 portion;
  undefined4 abOutput;
  undefined4 cdOutput;
  undefined4 sumOutput;
  undefined4 scale;
  undefined4 bias;
  uint abDotProduct;
  uint cdDotProduct;
  uint muxSum;
{
  _glCombinerOutputNV_Comp
            (glContext,stage,portion,abOutput,cdOutput,sumOutput,scale,bias,abDotProduct & 0xff,
             cdDotProduct & 0xff,muxSum & 0xff);
  _glCombinerOutputNV_Exec
            (glContext,stage,portion,abOutput,cdOutput,sumOutput,scale,bias,abDotProduct & 0xff,
             cdDotProduct & 0xff,muxSum & 0xff);
  return;
}

/* _glFinalCombinerInputNV_CompExec @ 0xb44dc (80 bytes) */
void _glFinalCombinerInputNV_CompExec(glContext, variable, input, mapping, componentUsage)
  undefined4 glContext;
  undefined4 variable;
  undefined4 input;
  undefined4 mapping;
  undefined4 componentUsage;
{
  ((int (*)())_glFinalCombinerInputNV_Comp)(glContext,variable,input,mapping,componentUsage);
  _glFinalCombinerInputNV_Exec(glContext,variable,input,mapping,componentUsage);
  return;
}

/* _glCombinerParameterfvNV_ListExec @ 0xb452c (48 bytes) */
int _glCombinerParameterfvNV_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glCombinerParameterfvNV_Exec(glContext,*listRecord,listRecord + 1);
  return 0x14;
}

/* _glCombinerStageParameterfvNV_ListExec @ 0xb455c (52 bytes) */
int _glCombinerStageParameterfvNV_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glCombinerStageParameterfvNV_Exec(glContext,*listRecord,listRecord[1],listRecord + 2);
  return 0x18;
}

/* _glCombinerParameterfNV_ListExec @ 0xb4590 (44 bytes) */
int _glCombinerParameterfNV_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  ((void (*)())_glCombinerParameterfNV_Exec)(glContext,*listRecord,(double)GH_U2F((unsigned int)(listRecord[1])));
  return 8;
}

/* _glCombinerParameterivNV_ListExec @ 0xb45bc (48 bytes) */
undefined4 _glCombinerParameterivNV_ListExec(undefined4 glContext,undefined4 *listRecord,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10)
{
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  
  ((void (*)())_glCombinerParameterivNV_Exec)(glContext,*listRecord,listRecord + 1,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,
             forwardedFloatArg7,forwardedFloatArg8,in_stack_ffffffb8,in_stack_ffffffc0);
  return 0x14;
}

/* _glCombinerParameteriNV_ListExec @ 0xb45ec (44 bytes) */
undefined4 _glCombinerParameteriNV_ListExec(undefined4 glContext,undefined4 *listRecord,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10)
{
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  
  ((void (*)())_glCombinerParameteriNV_Exec)(glContext,*listRecord,listRecord[1],forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,
             forwardedFloatArg7,forwardedFloatArg8,in_stack_ffffffb8,in_stack_ffffffc0);
  return 8;
}

/* _glCombinerInputNV_ListExec @ 0xb4618 (64 bytes) */
int _glCombinerInputNV_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glCombinerInputNV_Exec(glContext,*listRecord,listRecord[1],listRecord[2],listRecord[3],listRecord[4],listRecord[5]);
  return 0x18;
}

/* _glCombinerOutputNV_ListExec @ 0xb4658 (100 bytes) */
int _glCombinerOutputNV_ListExec(forwardedArg1, param_2)
  undefined4 forwardedArg1;
  undefined4 *param_2;
{
  _glCombinerOutputNV_Exec
            (forwardedArg1,*param_2,param_2[1],param_2[2],param_2[3],param_2[4],param_2[5],param_2[6],
             (uint)*(byte *)((int)param_2 + 0x1f),(uint)*(byte *)((int)param_2 + 0x23),
             (uint)*(byte *)((int)param_2 + 0x27));
  return 0x28;
}

/* _glFinalCombinerInputNV_ListExec @ 0xb46bc (56 bytes) */
int _glFinalCombinerInputNV_ListExec(glContext, listRecord)
  undefined4 glContext;
  undefined4 *listRecord;
{
  _glFinalCombinerInputNV_Exec(glContext,*listRecord,listRecord[1],listRecord[2],listRecord[3]);
  return 0x10;
}

/* _gleDecomposePrimitiveVertices @ 0xb46f4 (700 bytes) */
void _gleDecomposePrimitiveVertices(param_1, param_2, param_3, param_4, param_5, param_6)
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
  int remaining;
  undefined1 uVar5;
  undefined4 *srcCursor;
  undefined4 uVar7;
  int loopIndex;
  int loopIndex2;
  undefined4 *dstCursor;
  undefined4 *dstCursor2;
  
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
  loopIndex = 0;
  if (0 < (int)param_3) {
    do {
      loopIndex2 = 0;
      if (bVar1 != 0) {
        do {
          iVar2 = loopIndex2 * 2;
          switch((uint)(*(ushort *)(param_2 + iVar2 + 4) >> 10)) {
          case 0:
            remaining = (*(ushort *)(param_2 + iVar2 + 4) >> 8 & 3) + 1;
            if (remaining != 0) {
              srcCursor = (undefined4 *)(param_4 + (*(ushort *)(param_2 + iVar2 + 4) & 0x3f) * 4);
              dstCursor = (undefined4 *)(param_5 + 0x20);
              do {
                uVar7 = *srcCursor;
                srcCursor = srcCursor + 1;
                *dstCursor = uVar7;
                dstCursor = dstCursor + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            break;
          case 1:
            remaining = (*(ushort *)(param_2 + iVar2 + 4) >> 8 & 3) + 1;
            if (remaining != 0) {
              srcCursor = (undefined4 *)(param_4 + (*(ushort *)(param_2 + iVar2 + 4) & 0x3f) * 4);
              dstCursor = (undefined4 *)(param_5 + 0x40);
              do {
                uVar7 = *srcCursor;
                srcCursor = srcCursor + 1;
                *dstCursor = uVar7;
                dstCursor = dstCursor + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            break;
          case 2:
            remaining = (*(ushort *)(param_2 + iVar2 + 4) >> 8 & 3) + 1;
            if (remaining != 0) {
              srcCursor = (undefined4 *)(param_4 + (*(ushort *)(param_2 + iVar2 + 4) & 0x3f) * 4);
              dstCursor = (undefined4 *)(param_5 + 0x30);
              do {
                uVar7 = *srcCursor;
                srcCursor = srcCursor + 1;
                *dstCursor = uVar7;
                dstCursor = dstCursor + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            break;
          case 3:
            *(undefined4 *)(param_5 + 0x4c) =
                 *(undefined4 *)(param_4 + (*(ushort *)(param_2 + iVar2 + 4) & 0x3f) * 4);
            break;
          case 4:
            remaining = (*(ushort *)(param_2 + iVar2 + 4) >> 8 & 3) + 1;
            if (remaining != 0) {
              srcCursor = (undefined4 *)(param_4 + (*(ushort *)(param_2 + iVar2 + 4) & 0x3f) * 4);
              dstCursor = (undefined4 *)(param_5 + 0x50);
              do {
                uVar7 = *srcCursor;
                srcCursor = srcCursor + 1;
                *dstCursor = uVar7;
                dstCursor = dstCursor + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            break;
          case 5:
            remaining = (*(ushort *)(param_2 + iVar2 + 4) >> 8 & 3) + 1;
            if (remaining != 0) {
              srcCursor = (undefined4 *)(param_4 + (*(ushort *)(param_2 + iVar2 + 4) & 0x3f) * 4);
              dstCursor = (undefined4 *)(param_5 + 0x60);
              do {
                uVar7 = *srcCursor;
                srcCursor = srcCursor + 1;
                *dstCursor = uVar7;
                dstCursor = dstCursor + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
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
            remaining = (*(ushort *)(param_2 + iVar2 + 4) >> 8 & 3) + 1;
            if (remaining != 0) {
              dstCursor2 = (undefined4 *)
                        (((*(ushort *)(param_2 + iVar2 + 4) >> 10) - 8) * 0x10 + param_5 + 0x80);
              srcCursor = (undefined4 *)(param_4 + (*(ushort *)(param_2 + iVar2 + 4) & 0x3f) * 4);
              do {
                uVar7 = *srcCursor;
                srcCursor = srcCursor + 1;
                *dstCursor2 = uVar7;
                dstCursor2 = dstCursor2 + 1;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
          }
          loopIndex2 = loopIndex2 + 1;
        } while (loopIndex2 < (int)(uint)bVar1);
      }
      loopIndex = loopIndex + 1;
      param_5 = param_5 + 0x100;
      param_4 = param_4 + (uint)param_2[2] * 4;
    } while (loopIndex < (int)param_3);
  }
  return;
}

/* _gleVPSetFuncOutputDesc @ 0xb49f0 (548 bytes) */
void _gleVPSetFuncOutputDesc(param_1, param_2, param_3, param_4)
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
  int loopIndex;
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
  loopIndex = 0;
  iVar6 = 0;
  if (0 < (int)param_2) {
    do {
      uVar1 = *(uint *)(loopIndex * 8 + param_1);
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
      iVar6 = loopIndex << 4;
      loopIndex = loopIndex + 1;
      *(ushort *)((int)param_3 + iVar2 * 2 + 4) =
           (ushort)(iVar8 << 10) | (ushort)(iVar6 >> 2) | 0x300;
      iVar6 = iVar9;
    } while (loopIndex < (int)param_2);
  }
  if ((int)param_2 < (int)uVar3) {
    *(ushort *)((int)param_3 + iVar4 * 2 + 4) = (ushort)((loopIndex << 4) >> 2) | 0x1b00;
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
  uint loopIndex;
  
  uVar1 = 0;
  loopIndex = 0;
  if (param_2 != 0) {
    do {
      uVar2 = *(uint *)(loopIndex * 8 + param_1);
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
      loopIndex = loopIndex + 1;
    } while (loopIndex < param_2);
  }
  return uVar1;
}

/* _gleSetFunctionIDFromList @ 0xb4d14 (408 bytes) */
void _gleSetFunctionIDFromList(param_1, param_2, param_3)
  int param_1;
  int param_2;
  uint *param_3;
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  ushort *dstCursor;
  byte *srcCursor;
  ushort uVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int remaining;
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
  srcCursor = (byte *)(param_2 + 0xd);
  remaining = 0x1e;
  do {
    bVar1 = *srcCursor;
    srcCursor = srcCursor + 1;
    iVar4 = *piVar8;
    piVar8 = piVar8 + 1;
    *piVar8 = iVar4 + (uint)bVar1;
    remaining = remaining + -1;
  } while (remaining != 0);
  local_90[0] = local_14 + (uint)*(byte *)(param_2 + 0x2b);
  if (uVar2 == 0) {
    return;
  }
  dstCursor = (ushort *)((int)param_3 + uVar2 * 2 + 4);
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
    *dstCursor = (short)(uVar9 - 1) * 0x4000 | (ushort)(iVar11 << 10) | uVar7;
    dstCursor = dstCursor + 1;
    uVar2 = uVar2 - 1;
    if (uVar2 == 0) {
      return;
    }
  } while( true );
}

/* _gleSetFunctionIDToList @ 0xb4eac (508 bytes) */
void _gleSetFunctionIDToList(param_1, param_2, param_3)
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
  ushort *dstCursor;
  int loopIndex;
  uint *puVar11;
  int iVar12;
  int loopIndex2;
  longlong lVar13;
  
  *param_3 = 0;
  if (*(char *)(param_2 + 0x31c) != '\0') {
    *param_3 = 0x800000;
  }
  uVar7 = *(uint *)(param_2 + 0x300);
  loopIndex = 0;
  loopIndex2 = 0;
  uVar4 = *(uint *)(param_2 + 0x304) & 0xff7fffff;
  do {
    lVar13 = ___ashldi3(0,1,loopIndex2 + 0x10);
    if ((uVar7 & (uint)((ulonglong)lVar13 >> 0x20)) != 0 || (uVar4 & (uint)lVar13) != 0) {
      loopIndex = loopIndex + 1;
    }
    loopIndex2 = loopIndex2 + 1;
  } while (loopIndex2 < 0x20);
  *param_3 = *param_3 | loopIndex << 0x18;
  iVar12 = *(int *)(param_1 + 0x48dc);
  uVar5 = iVar12 - 0x1400;
  if (((6 < uVar5) && (uVar5 = 7, iVar12 != 0x140a)) &&
     (uVar5 = iVar12 - 0x93f8, 5 < iVar12 - 0x9400U)) {
    uVar5 = 0xe;
  }
  dstCursor = (ushort *)((int)param_3 + loopIndex * 2 + 4);
  *param_3 = *param_3 | (uVar5 & 0xf) << 0x10;
  uVar5 = 0;
  loopIndex = 1;
  puVar11 = param_3 + 1;
  while( true ) {
    lVar13 = ___ashldi3(0,1,loopIndex + 0x10);
    if ((uVar7 & (uint)((ulonglong)lVar13 >> 0x20)) != 0 || (uVar4 & (uint)lVar13) != 0) {
      iVar12 = loopIndex * 0x18 + param_2;
      uVar8 = (uint)*(ushort *)(iVar12 + 8);
      uVar6 = uVar8 - 0x1400;
      sVar1 = *(short *)(iVar12 + 10);
      if (((6 < uVar6) && (uVar6 = 7, uVar8 != 0x140a)) &&
         (uVar6 = uVar8 - 0x93f8, 5 < uVar8 - 0x9400)) {
        uVar6 = 0xe;
      }
      sVar3 = (short)(sVar1 + -1);
      *dstCursor = sVar3 * 0x4000 | (ushort)(uVar6 << 10) | (ushort)*(undefined4 *)(iVar12 + 4);
      uVar2 = (ushort)((int)uVar5 >> 2);
      if (loopIndex == 6) {
        *(ushort *)puVar11 = sVar3 * 0x100 | 0x1800U | uVar2 | 0xc0;
      }
      else {
        *(ushort *)puVar11 = (ushort)(loopIndex << 10) | sVar3 * 0x100 | uVar2;
      }
      dstCursor = dstCursor + 1;
      uVar5 = uVar5 + sVar1 * 4;
      puVar11 = (uint *)((int)puVar11 + 2);
    }
    if (loopIndex == 0) break;
    if (loopIndex < 0x1f) {
      loopIndex = loopIndex + 1;
    }
    else {
      loopIndex = 0;
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
void _gleSetVertexEval1Func(param_1, forwardedArg2, forwardedArg3)
  int param_1;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
{
  undefined4 *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = (undefined4 *)(*_gleBuildVertexFunc)(param_1,2,forwardedArg3);
  UNRECOVERED_JUMPTABLE = (code *)*puVar1;
  *(code **)(param_1 + 0x4898) = UNRECOVERED_JUMPTABLE;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,forwardedArg2,forwardedArg3);
  return;
}

/* _gleSetVertexEval2Func @ 0xb51a4 (100 bytes) */
void _gleSetVertexEval2Func(param_1, forwardedArg2, forwardedArg3)
  int param_1;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
{
  undefined4 *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = (undefined4 *)(*_gleBuildVertexFunc)(param_1,2,forwardedArg3);
  UNRECOVERED_JUMPTABLE = (code *)*puVar1;
  *(code **)(param_1 + 0x489c) = UNRECOVERED_JUMPTABLE;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(param_1,forwardedArg2,forwardedArg3);
  return;
}

/* _gleGetVertexElemFunc @ 0xb5208 (68 bytes) */
int _gleGetVertexElemFunc(forwardedArg1)
  undefined4 forwardedArg1;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*_gleBuildVertexFunc)(forwardedArg1,4);
  return *puVar1;
}

/* _gleGetVertexToListFunc @ 0xb524c (68 bytes) */
int _gleGetVertexToListFunc(forwardedArg1)
  undefined4 forwardedArg1;
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*_gleBuildVertexFunc)(forwardedArg1,3);
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
void _gleInterpolEyeNO0000(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord12;
  float fVar2;
  float windowScaleZ;
  float endWord0b;
  float fVar3;
  float startWord09;
  float startWord0a;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar8;
  float endClipX;
  float endClipY;
  float startClipZ;
  float fVar11;
  float startWord1e;
  float windowBiasZ;
  float startWord0b;
  uint clipOutcode;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar2 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar11 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar8 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar11;
  fVar2 = (edgeT * (endClipY - fVar2) + fVar2);
  outVertex[7] = fVar1;
  fVar3 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = fVar2;
  outVertex[6] = fVar3;
  if (fVar11 < fVar8) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar11) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar2 < fVar8) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar2) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar3 < fVar8) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar3) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar11 = fVar11 * fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar11 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar2 + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar3 + windowBiasZ;
  }
  if (startVertex == outVertex) {
    return;
  }
  *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
  *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
  *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
  startWord12 = startVertex[0x12];
  outVertex[0x1d] = startVertex[0x1d];
  startWord1e = startVertex[0x1e];
  outVertex[0x12] = startWord12;
  outVertex[0x1e] = startWord1e;
  return;
}

/* _gleInterpolEyeNO0010 @ 0xb5550 (468 bytes) */
void _gleInterpolEyeNO0010(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord12;
  float fVar2;
  float windowScaleZ;
  float endWord0b;
  float fVar3;
  float startWord09;
  float startWord0a;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar8;
  float endClipX;
  float endClipY;
  float startClipZ;
  float fVar11;
  float startWord1e;
  float windowBiasZ;
  float startWord0b;
  uint clipOutcode;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar2 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar11 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar8 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar11;
  fVar2 = (edgeT * (endClipY - fVar2) + fVar2);
  outVertex[7] = fVar1;
  fVar3 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = fVar2;
  outVertex[6] = fVar3;
  if (fVar11 < fVar8) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar11) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar2 < fVar8) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar2) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar3 < fVar8) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar3) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar11 = fVar11 * fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar11 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar2 + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar3 + windowBiasZ;
  }
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13]);
  if (startVertex == outVertex) {
    return;
  }
  *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
  *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
  *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
  startWord12 = startVertex[0x12];
  outVertex[0x1d] = startVertex[0x1d];
  startWord1e = startVertex[0x1e];
  outVertex[0x12] = startWord12;
  outVertex[0x1e] = startWord1e;
  return;
}

/* _gleInterpolEyeNO0100 @ 0xb5724 (616 bytes) */
void _gleInterpolEyeNO0100(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord12;
  char cVar2;
  float fVar3;
  float windowScaleZ;
  float endWord0b;
  float fVar4;
  float startWord09;
  float startWord0a;
  float outInvW;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar9;
  float endClipX;
  float endClipY;
  float startClipZ;
  float fVar12;
  float startWord1e;
  float windowBiasZ;
  float startWord0b;
  uint clipOutcode;
  float dVar14;
  float dVar15;
  float dVar16;
  float dVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar3 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar12 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar9 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar12;
  fVar3 = (edgeT * (endClipY - fVar3) + fVar3);
  outVertex[7] = fVar1;
  fVar4 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  cVar2 = *(char *)((int)startVertex + 0x7f);
  outVertex[5] = fVar3;
  outVertex[6] = fVar4;
  if (fVar12 < fVar9) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar12) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar3 < fVar9) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar4 < fVar9) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar4) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar12 = fVar12 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar12 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar3 + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar4 + windowBiasZ;
  }
  dVar16 = (double)startVertex[0x20];
  dVar18 = (double)startVertex[0x21];
  dVar17 = (double)startVertex[0x22];
  dVar22 = (double)startVertex[0x23];
  if (cVar2 == '\0') {
    dVar14 = (double)startVertex[7];
    dVar22 = (double)(dVar22 * dVar14);
    dVar16 = (double)(dVar16 * dVar14);
    dVar18 = (double)(dVar18 * dVar14);
    dVar17 = (double)(dVar17 * dVar14);
  }
  dVar14 = (double)*(float *)(endVertex + 0x80);
  dVar21 = (double)*(float *)(endVertex + 0x84);
  dVar19 = (double)*(float *)(endVertex + 0x88);
  dVar20 = (double)*(float *)(endVertex + 0x8c);
  if (*(char *)(endVertex + 0x7f) == '\0') {
    dVar15 = (double)*(float *)(endVertex + 0x1c);
    dVar20 = (double)(dVar20 * dVar15);
    dVar14 = (double)(dVar14 * dVar15);
    dVar21 = (double)(dVar21 * dVar15);
    dVar19 = (double)(dVar19 * dVar15);
  }
  fVar1 = (edgeT * (dVar14 - dVar16) + dVar16);
  fVar12 = (edgeT * (dVar21 - dVar18) + dVar18);
  fVar3 = (edgeT * (dVar20 - dVar22) + dVar22);
  fVar4 = (edgeT * (dVar19 - dVar17) + dVar17);
  if (clipOutcode == 0) {
    outInvW = outVertex[3];
    fVar3 = fVar3 * outInvW;
    fVar1 = fVar1 * outInvW;
    fVar12 = fVar12 * outInvW;
    fVar4 = fVar4 * outInvW;
  }
  outVertex[0x20] = fVar1;
  outVertex[0x21] = fVar12;
  outVertex[0x22] = fVar4;
  outVertex[0x23] = fVar3;
  if (startVertex == outVertex) {
    return;
  }
  *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
  *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
  *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
  startWord12 = startVertex[0x12];
  outVertex[0x1d] = startVertex[0x1d];
  startWord1e = startVertex[0x1e];
  outVertex[0x12] = startWord12;
  outVertex[0x1e] = startWord1e;
  return;
}

/* _gleInterpolEyeNO0100w @ 0xb598c (528 bytes) */
void _gleInterpolEyeNO0100w(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord12;
  float startWord21;
  float fVar2;
  float startWord23;
  float windowScaleZ;
  float endWord0b;
  float fVar3;
  float endWord23;
  float startWord09;
  float startWord0a;
  float endWord21;
  float endWord09;
  float endWord22;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar8;
  float endClipX;
  float endClipY;
  float startClipZ;
  float fVar11;
  float startWord1e;
  float startWord22;
  float windowBiasZ;
  float startWord0b;
  uint clipOutcode;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar2 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar11 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar8 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar11;
  fVar2 = (edgeT * (endClipY - fVar2) + fVar2);
  outVertex[7] = fVar1;
  fVar3 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = fVar2;
  outVertex[6] = fVar3;
  if (fVar11 < fVar8) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar11) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar2 < fVar8) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar2) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar3 < fVar8) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar3) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar11 = fVar11 * fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar11 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar2 + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar3 + windowBiasZ;
  }
  startWord21 = startVertex[0x21];
  startWord22 = startVertex[0x22];
  startWord23 = startVertex[0x23];
  endWord23 = *(float *)(endVertex + 0x8c);
  endWord21 = *(float *)(endVertex + 0x84);
  endWord22 = *(float *)(endVertex + 0x88);
  outVertex[0x20] =
       (edgeT * (*(float *)(endVertex + 0x80) - startVertex[0x20]) + startVertex[0x20]);
  outVertex[0x23] = (edgeT * (endWord23 - startWord23) + startWord23)
  ;
  outVertex[0x21] = (edgeT * (endWord21 - startWord21) + startWord21)
  ;
  outVertex[0x22] =
       (edgeT * (endWord22 - startWord22) + startWord22);
  if (startVertex == outVertex) {
    return;
  }
  *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
  *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
  *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
  startWord12 = startVertex[0x12];
  outVertex[0x1d] = startVertex[0x1d];
  startWord1e = startVertex[0x1e];
  outVertex[0x12] = startWord12;
  outVertex[0x1e] = startWord1e;
  return;
}

/* _gleInterpolEyeNO0110 @ 0xb5b9c (636 bytes) */
void _gleInterpolEyeNO0110(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord12;
  char cVar2;
  float fVar3;
  float windowScaleZ;
  float endWord0b;
  float fVar4;
  float startWord09;
  float startWord0a;
  float outInvW;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar9;
  float endClipX;
  float endClipY;
  float startClipZ;
  float fVar12;
  float startWord1e;
  float windowBiasZ;
  float startWord0b;
  uint clipOutcode;
  float dVar14;
  float dVar15;
  float dVar16;
  float dVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar3 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar12 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar9 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar12;
  fVar3 = (edgeT * (endClipY - fVar3) + fVar3);
  outVertex[7] = fVar1;
  fVar4 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  cVar2 = *(char *)((int)startVertex + 0x7f);
  outVertex[5] = fVar3;
  outVertex[6] = fVar4;
  if (fVar12 < fVar9) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar12) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar3 < fVar9) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar4 < fVar9) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar4) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar12 = fVar12 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar12 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar3 + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar4 + windowBiasZ;
  }
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13]);
  dVar16 = (double)startVertex[0x20];
  dVar17 = (double)startVertex[0x21];
  dVar18 = (double)startVertex[0x22];
  dVar22 = (double)startVertex[0x23];
  if (cVar2 == '\0') {
    dVar14 = (double)startVertex[7];
    dVar22 = (double)(dVar22 * dVar14);
    dVar16 = (double)(dVar16 * dVar14);
    dVar17 = (double)(dVar17 * dVar14);
    dVar18 = (double)(dVar18 * dVar14);
  }
  dVar14 = (double)*(float *)(endVertex + 0x80);
  dVar20 = (double)*(float *)(endVertex + 0x84);
  dVar21 = (double)*(float *)(endVertex + 0x88);
  dVar19 = (double)*(float *)(endVertex + 0x8c);
  if (*(char *)(endVertex + 0x7f) == '\0') {
    dVar15 = (double)*(float *)(endVertex + 0x1c);
    dVar19 = (double)(dVar19 * dVar15);
    dVar14 = (double)(dVar14 * dVar15);
    dVar20 = (double)(dVar20 * dVar15);
    dVar21 = (double)(dVar21 * dVar15);
  }
  fVar1 = (edgeT * (dVar14 - dVar16) + dVar16);
  fVar12 = (edgeT * (dVar20 - dVar17) + dVar17);
  fVar3 = (edgeT * (dVar19 - dVar22) + dVar22);
  fVar4 = (edgeT * (dVar21 - dVar18) + dVar18);
  if (clipOutcode == 0) {
    outInvW = outVertex[3];
    fVar3 = fVar3 * outInvW;
    fVar1 = fVar1 * outInvW;
    fVar12 = fVar12 * outInvW;
    fVar4 = fVar4 * outInvW;
  }
  outVertex[0x20] = fVar1;
  outVertex[0x21] = fVar12;
  outVertex[0x22] = fVar4;
  outVertex[0x23] = fVar3;
  if (startVertex == outVertex) {
    return;
  }
  *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
  *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
  *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
  startWord12 = startVertex[0x12];
  outVertex[0x1d] = startVertex[0x1d];
  startWord1e = startVertex[0x1e];
  outVertex[0x12] = startWord12;
  outVertex[0x1e] = startWord1e;
  return;
}

/* _gleInterpolEyeNO0110w @ 0xb5e18 (548 bytes) */
void _gleInterpolEyeNO0110w(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord12;
  float startWord21;
  float fVar2;
  float startWord23;
  float windowScaleZ;
  float endWord0b;
  float fVar3;
  float endWord23;
  float startWord09;
  float startWord0a;
  float endWord21;
  float endWord09;
  float endWord22;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar8;
  float endClipX;
  float endClipY;
  float startClipZ;
  float fVar11;
  float startWord1e;
  float startWord22;
  float windowBiasZ;
  float startWord0b;
  uint clipOutcode;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar2 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar11 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar8 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar11;
  fVar2 = (edgeT * (endClipY - fVar2) + fVar2);
  outVertex[7] = fVar1;
  fVar3 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = fVar2;
  outVertex[6] = fVar3;
  if (fVar11 < fVar8) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar11) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar2 < fVar8) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar2) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar3 < fVar8) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar3) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar11 = fVar11 * fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar11 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar2 + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar3 + windowBiasZ;
  }
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13]);
  startWord21 = startVertex[0x21];
  startWord22 = startVertex[0x22];
  startWord23 = startVertex[0x23];
  endWord23 = *(float *)(endVertex + 0x8c);
  endWord21 = *(float *)(endVertex + 0x84);
  endWord22 = *(float *)(endVertex + 0x88);
  outVertex[0x20] =
       (edgeT * (*(float *)(endVertex + 0x80) - startVertex[0x20]) + startVertex[0x20]);
  outVertex[0x21] = (edgeT * (endWord21 - startWord21) + startWord21)
  ;
  outVertex[0x23] = (edgeT * (endWord23 - startWord23) + startWord23)
  ;
  outVertex[0x22] =
       (edgeT * (endWord22 - startWord22) + startWord22);
  if (startVertex == outVertex) {
    return;
  }
  *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
  *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
  *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
  startWord12 = startVertex[0x12];
  outVertex[0x1d] = startVertex[0x1d];
  startWord1e = startVertex[0x1e];
  outVertex[0x12] = startWord12;
  outVertex[0x1e] = startWord1e;
  return;
}

/* _gleInterpolEyeNO0200 @ 0xb603c (672 bytes) */
void _gleInterpolEyeNO0200(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord12;
  char cVar2;
  float fVar3;
  float windowBiasZ;
  float endWord0b;
  float fVar4;
  float startWord09;
  float startWord0a;
  float outInvW;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar9;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint uVar12;
  int iVar13;
  float fVar14;
  float startWord1e;
  float windowScaleZ;
  float startWord0b;
  uint texEnableMask;
  uint clipOutcode;
  uint uVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  float dVar23;
  float dVar24;
  float dVar25;
  float dVar26;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar3 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar14 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar9 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar14;
  fVar3 = (edgeT * (endClipY - fVar3) + fVar3);
  outVertex[7] = fVar1;
  fVar4 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  cVar2 = *(char *)((int)startVertex + 0x7f);
  outVertex[5] = fVar3;
  outVertex[6] = fVar4;
  if (fVar14 < fVar9) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar14) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar3 < fVar9) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar4 < fVar9) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar4) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar14 = fVar14 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar14 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar3 + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar4 + windowBiasZ;
  }
  texEnableMask = *(uint *)(glContext + 0x5150);
  uVar17 = 0;
  do {
    uVar12 = texEnableMask >> (uVar17 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        if (startVertex == outVertex) {
          return;
        }
        *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
        *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
        *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
        startWord12 = startVertex[0x12];
        outVertex[0x1d] = startVertex[0x1d];
        startWord1e = startVertex[0x1e];
        outVertex[0x12] = startWord12;
        outVertex[0x1e] = startWord1e;
        return;
      }
    }
    else {
      dVar26 = (double)startVertex[uVar17 * 4 + 0x23];
      dVar20 = (double)startVertex[uVar17 * 4 + 0x20];
      dVar21 = (double)startVertex[uVar17 * 4 + 0x21];
      dVar22 = (double)startVertex[uVar17 * 4 + 0x22];
      if (cVar2 == '\0') {
        dVar18 = (double)startVertex[7];
        dVar26 = (double)(dVar26 * dVar18);
        dVar20 = (double)(dVar20 * dVar18);
        dVar21 = (double)(dVar21 * dVar18);
        dVar22 = (double)(dVar22 * dVar18);
      }
      iVar13 = uVar17 * 0x10 + endVertex;
      dVar23 = (double)*(float *)(iVar13 + 0x8c);
      dVar18 = (double)*(float *)(iVar13 + 0x80);
      dVar25 = (double)*(float *)(iVar13 + 0x84);
      dVar24 = (double)*(float *)(iVar13 + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        dVar19 = (double)*(float *)(endVertex + 0x1c);
        dVar23 = (double)(dVar23 * dVar19);
        dVar18 = (double)(dVar18 * dVar19);
        dVar25 = (double)(dVar25 * dVar19);
        dVar24 = (double)(dVar24 * dVar19);
      }
      fVar1 = (edgeT * (dVar18 - dVar20) + dVar20);
      fVar14 = (edgeT * (dVar25 - dVar21) + dVar21);
      fVar3 = (edgeT * (dVar24 - dVar22) + dVar22);
      fVar4 = (edgeT * (dVar23 - dVar26) + dVar26);
      if (clipOutcode == 0) {
        outInvW = outVertex[3];
        fVar4 = fVar4 * outInvW;
        fVar1 = fVar1 * outInvW;
        fVar14 = fVar14 * outInvW;
        fVar3 = fVar3 * outInvW;
      }
      outVertex[uVar17 * 4 + 0x23] = fVar4;
      outVertex[uVar17 * 4 + 0x20] = fVar1;
      outVertex[uVar17 * 4 + 0x21] = fVar14;
      outVertex[uVar17 * 4 + 0x22] = fVar3;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* _gleInterpolEyeNO0200w @ 0xb62dc (584 bytes) */
void _gleInterpolEyeNO0200w(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startTexCoordQ;
  float startWord12;
  float fVar2;
  float startTexCoordR;
  float windowBiasZ;
  float endWord0b;
  float fVar3;
  float startWord09;
  float fVar4;
  float startWord0a;
  float fVar5;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar8;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint uVar11;
  float fVar12;
  float startTexCoordT;
  float startWord1e;
  float windowScaleZ;
  float startWord0b;
  uint clipOutcode;
  uint texEnableMask;
  uint uVar14;
  int iVar15;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar2 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar12 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar8 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar12;
  fVar2 = (edgeT * (endClipY - fVar2) + fVar2);
  outVertex[7] = fVar1;
  fVar3 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = fVar2;
  outVertex[6] = fVar3;
  if (fVar12 < fVar8) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar12) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar2 < fVar8) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar2) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar3 < fVar8) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar3) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar12 = fVar12 * fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar12 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar2 + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar3 + windowBiasZ;
  }
  texEnableMask = *(uint *)(glContext + 0x5150);
  uVar14 = 0;
  do {
    uVar11 = texEnableMask >> (uVar14 & 0x3f);
    if ((uVar11 & 1) == 0) {
      if (uVar11 == 0) {
        if (startVertex == outVertex) {
          return;
        }
        *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
        *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
        *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
        startWord12 = startVertex[0x12];
        outVertex[0x1d] = startVertex[0x1d];
        startWord1e = startVertex[0x1e];
        outVertex[0x12] = startWord12;
        outVertex[0x1e] = startWord1e;
        return;
      }
    }
    else {
      iVar15 = uVar14 * 0x10 + endVertex;
      startTexCoordQ = startVertex[uVar14 * 4 + 0x23];
      startTexCoordT = startVertex[uVar14 * 4 + 0x21];
      startTexCoordR = startVertex[uVar14 * 4 + 0x22];
      fVar3 = *(float *)(iVar15 + 0x8c);
      fVar4 = *(float *)(iVar15 + 0x84);
      fVar5 = *(float *)(iVar15 + 0x88);
      outVertex[uVar14 * 4 + 0x20] =
           (edgeT * (*(float *)(iVar15 + 0x80) - startVertex[uVar14 * 4 + 0x20]) + startVertex[uVar14 * 4 + 0x20]);
      outVertex[uVar14 * 4 + 0x21] =
           (edgeT * (fVar4 - startTexCoordT) + startTexCoordT);
      outVertex[uVar14 * 4 + 0x22] =
           (edgeT * (fVar5 - startTexCoordR) + startTexCoordR);
      outVertex[uVar14 * 4 + 0x23] =
           (edgeT * (fVar3 - startTexCoordQ) + startTexCoordQ);
    }
    uVar14 = uVar14 + 1;
  } while( true );
}

/* _gleInterpolEyeNO0210 @ 0xb6524 (692 bytes) */
void _gleInterpolEyeNO0210(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord12;
  char cVar2;
  float fVar3;
  float windowBiasZ;
  float endWord0b;
  float fVar4;
  float startWord09;
  float startWord0a;
  float outInvW;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar9;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint uVar12;
  int iVar13;
  float fVar14;
  float startWord1e;
  float windowScaleZ;
  float startWord0b;
  uint texEnableMask;
  uint clipOutcode;
  uint uVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  float dVar23;
  float dVar24;
  float dVar25;
  float dVar26;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar3 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar14 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar9 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar14;
  fVar3 = (edgeT * (endClipY - fVar3) + fVar3);
  outVertex[7] = fVar1;
  fVar4 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  cVar2 = *(char *)((int)startVertex + 0x7f);
  outVertex[5] = fVar3;
  outVertex[6] = fVar4;
  if (fVar14 < fVar9) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar14) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar3 < fVar9) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar4 < fVar9) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar4) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar14 = fVar14 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar14 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar3 + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar4 + windowBiasZ;
  }
  uVar17 = 0;
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13]);
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    uVar12 = texEnableMask >> (uVar17 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        if (startVertex == outVertex) {
          return;
        }
        *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
        *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
        *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
        startWord12 = startVertex[0x12];
        outVertex[0x1d] = startVertex[0x1d];
        startWord1e = startVertex[0x1e];
        outVertex[0x12] = startWord12;
        outVertex[0x1e] = startWord1e;
        return;
      }
    }
    else {
      dVar26 = (double)startVertex[uVar17 * 4 + 0x23];
      dVar20 = (double)startVertex[uVar17 * 4 + 0x20];
      dVar21 = (double)startVertex[uVar17 * 4 + 0x21];
      dVar22 = (double)startVertex[uVar17 * 4 + 0x22];
      if (cVar2 == '\0') {
        dVar18 = (double)startVertex[7];
        dVar26 = (double)(dVar26 * dVar18);
        dVar20 = (double)(dVar20 * dVar18);
        dVar21 = (double)(dVar21 * dVar18);
        dVar22 = (double)(dVar22 * dVar18);
      }
      iVar13 = uVar17 * 0x10 + endVertex;
      dVar23 = (double)*(float *)(iVar13 + 0x8c);
      dVar18 = (double)*(float *)(iVar13 + 0x80);
      dVar24 = (double)*(float *)(iVar13 + 0x84);
      dVar25 = (double)*(float *)(iVar13 + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        dVar19 = (double)*(float *)(endVertex + 0x1c);
        dVar23 = (double)(dVar23 * dVar19);
        dVar18 = (double)(dVar18 * dVar19);
        dVar24 = (double)(dVar24 * dVar19);
        dVar25 = (double)(dVar25 * dVar19);
      }
      fVar1 = (edgeT * (dVar18 - dVar20) + dVar20);
      fVar14 = (edgeT * (dVar24 - dVar21) + dVar21);
      fVar3 = (edgeT * (dVar25 - dVar22) + dVar22);
      fVar4 = (edgeT * (dVar23 - dVar26) + dVar26);
      if (clipOutcode == 0) {
        outInvW = outVertex[3];
        fVar4 = fVar4 * outInvW;
        fVar1 = fVar1 * outInvW;
        fVar14 = fVar14 * outInvW;
        fVar3 = fVar3 * outInvW;
      }
      outVertex[uVar17 * 4 + 0x23] = fVar4;
      outVertex[uVar17 * 4 + 0x20] = fVar1;
      outVertex[uVar17 * 4 + 0x21] = fVar14;
      outVertex[uVar17 * 4 + 0x22] = fVar3;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* _gleInterpolEyeNO0210w @ 0xb67d8 (604 bytes) */
void _gleInterpolEyeNO0210w(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startTexCoordQ;
  float startWord12;
  float fVar2;
  float startTexCoordR;
  float windowBiasZ;
  float endWord0b;
  float fVar3;
  float startWord09;
  float fVar4;
  float startWord0a;
  float fVar5;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar8;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint uVar11;
  float fVar12;
  float startTexCoordT;
  float startWord1e;
  float windowScaleZ;
  float startWord0b;
  uint clipOutcode;
  uint texEnableMask;
  uint uVar14;
  int iVar15;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar2 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar12 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar8 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar12;
  fVar2 = (edgeT * (endClipY - fVar2) + fVar2);
  outVertex[7] = fVar1;
  fVar3 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = fVar2;
  outVertex[6] = fVar3;
  if (fVar12 < fVar8) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar12) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar2 < fVar8) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar2) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar3 < fVar8) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar3) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar12 = fVar12 * fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar12 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar2 + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar3 + windowBiasZ;
  }
  uVar14 = 0;
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13]);
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    uVar11 = texEnableMask >> (uVar14 & 0x3f);
    if ((uVar11 & 1) == 0) {
      if (uVar11 == 0) {
        if (startVertex == outVertex) {
          return;
        }
        *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
        *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
        *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
        startWord12 = startVertex[0x12];
        outVertex[0x1d] = startVertex[0x1d];
        startWord1e = startVertex[0x1e];
        outVertex[0x12] = startWord12;
        outVertex[0x1e] = startWord1e;
        return;
      }
    }
    else {
      iVar15 = uVar14 * 0x10 + endVertex;
      startTexCoordQ = startVertex[uVar14 * 4 + 0x23];
      startTexCoordT = startVertex[uVar14 * 4 + 0x21];
      startTexCoordR = startVertex[uVar14 * 4 + 0x22];
      fVar3 = *(float *)(iVar15 + 0x8c);
      fVar4 = *(float *)(iVar15 + 0x84);
      fVar5 = *(float *)(iVar15 + 0x88);
      outVertex[uVar14 * 4 + 0x20] =
           (edgeT * (*(float *)(iVar15 + 0x80) - startVertex[uVar14 * 4 + 0x20]) + startVertex[uVar14 * 4 + 0x20]);
      outVertex[uVar14 * 4 + 0x21] =
           (edgeT * (fVar4 - startTexCoordT) + startTexCoordT);
      outVertex[uVar14 * 4 + 0x22] =
           (edgeT * (fVar5 - startTexCoordR) + startTexCoordR);
      outVertex[uVar14 * 4 + 0x23] =
           (edgeT * (fVar3 - startTexCoordQ) + startTexCoordQ);
    }
    uVar14 = uVar14 + 1;
  } while( true );
}

/* _gleInterpolEyeNO1000 @ 0xb6a34 (476 bytes) */
void _gleInterpolEyeNO1000(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord0f;
  float fVar2;
  float startWord0d;
  float windowBiasZ;
  float startWord0b;
  float fVar3;
  float startWord0e;
  float windowScaleZ;
  float endWord0b;
  float fVar4;
  float endWord0f;
  float startWord09;
  float endWord09;
  float endWord0d;
  float startWord0a;
  float endWord0e;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar9;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint clipOutcode;
  
  startWord0b = *(float *)(startVertex + 0x2c);
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = *(float *)(startVertex + 0x24);
  endWord09 = *(float *)(endVertex + 0x24);
  startWord0a = *(float *)(startVertex + 0x28);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = *(float *)(startVertex + 0x10);
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar3 = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  fVar2 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar9 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar2;
  fVar3 = (edgeT * (endClipY - fVar3) + fVar3);
  outVertex[7] = fVar1;
  fVar4 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  clipOutcode = 0;
  outVertex[5] = fVar3;
  outVertex[6] = fVar4;
  if (fVar2 < fVar9) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar2) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar3 < fVar9) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar4 < fVar9) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar4) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar2 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar3 + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar4 + windowBiasZ;
  }
  startWord0f = *(float *)(startVertex + 0x3c);
  startWord0d = *(float *)(startVertex + 0x34);
  startWord0e = *(float *)(startVertex + 0x38);
  endWord0f = *(float *)(endVertex + 0x3c);
  endWord0d = *(float *)(endVertex + 0x34);
  endWord0e = *(float *)(endVertex + 0x38);
  outVertex[0xc] = (edgeT * (*(float *)(endVertex + 0x30) - *(float *)(startVertex + 0x30)) + *(float *)(startVertex + 0x30));
  outVertex[0xd] = (edgeT * (endWord0d - startWord0d) + startWord0d);
  outVertex[0xf] = (edgeT * (endWord0f - startWord0f) + startWord0f);
  outVertex[0xe] = (edgeT * (endWord0e - startWord0e) + startWord0e);
  return;
}

/* _gleInterpolEyeNO1001 @ 0xb6c10 (480 bytes) */
void _gleInterpolEyeNO1001(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord10;
  float fVar2;
  float startWord11;
  float windowBiasZ;
  float startWord0b;
  float fVar3;
  float endWord10;
  float windowScaleZ;
  float endWord0b;
  float fVar4;
  float endWord11;
  float startWord0a;
  float endWord09;
  float startWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar9;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint clipOutcode;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord0a = startVertex[10];
  endWord09 = *(float *)(endVertex + 0x24);
  startWord09 = startVertex[9];
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar3 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar2 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar9 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar2;
  fVar3 = (edgeT * (endClipY - fVar3) + fVar3);
  outVertex[7] = fVar1;
  fVar4 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  clipOutcode = 0;
  outVertex[5] = fVar3;
  outVertex[6] = fVar4;
  if (fVar2 < fVar9) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar2) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar3 < fVar9) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar4 < fVar9) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar4) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar2 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar3 + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar4 + windowBiasZ;
  }
  startWord10 = startVertex[0x10];
  startWord11 = startVertex[0x11];
  endWord10 = *(float *)(endVertex + 0x40);
  endWord11 = *(float *)(endVertex + 0x44);
  outVertex[0x12] =
       (edgeT * (*(float *)(endVertex + 0x48) - startVertex[0x12]) + startVertex[0x12]);
  outVertex[0x10] = (edgeT * (endWord10 - startWord10) + startWord10)
  ;
  outVertex[0x11] = (edgeT * (endWord11 - startWord11) + startWord11)
  ;
  if (startVertex == outVertex) {
    return;
  }
  outVertex[0x1d] = startVertex[0x1d];
  outVertex[0x1e] = startVertex[0x1e];
  return;
}

/* _gleInterpolEyeNO1010 @ 0xb6df0 (496 bytes) */
void _gleInterpolEyeNO1010(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord0f;
  float fVar2;
  float startWord0c;
  float windowBiasZ;
  float startWord0b;
  float fVar3;
  float startWord0d;
  float windowScaleZ;
  float endWord0b;
  float fVar4;
  float endWord0f;
  float startWord09;
  float startWord0a;
  float endWord0c;
  float endWord09;
  float startWord0e;
  float endWord0a;
  float endWord0d;
  float startClipX;
  float endWord0e;
  float endClipZ;
  float fVar9;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint clipOutcode;
  
  startWord0b = *(float *)(startVertex + 0x2c);
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = *(float *)(startVertex + 0x24);
  startWord0a = *(float *)(startVertex + 0x28);
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = *(float *)(startVertex + 0x10);
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar3 = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  fVar2 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar9 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar2;
  fVar3 = (edgeT * (endClipY - fVar3) + fVar3);
  outVertex[7] = fVar1;
  fVar4 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  clipOutcode = 0;
  outVertex[5] = fVar3;
  outVertex[6] = fVar4;
  if (fVar2 < fVar9) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar2) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar3 < fVar9) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar4 < fVar9) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar4) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar2 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar3 + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar4 + windowBiasZ;
  }
  startWord0f = *(float *)(startVertex + 0x3c);
  startWord0c = *(float *)(startVertex + 0x30);
  startWord0d = *(float *)(startVertex + 0x34);
  endWord0f = *(float *)(endVertex + 0x3c);
  endWord0c = *(float *)(endVertex + 0x30);
  startWord0e = *(float *)(startVertex + 0x38);
  endWord0d = *(float *)(endVertex + 0x34);
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - *(float *)(startVertex + 0x4c)) + *(float *)(startVertex + 0x4c));
  endWord0e = *(float *)(endVertex + 0x38);
  outVertex[0xc] = (edgeT * (endWord0c - startWord0c) + startWord0c);
  outVertex[0xd] = (edgeT * (endWord0d - startWord0d) + startWord0d);
  outVertex[0xf] = (edgeT * (endWord0f - startWord0f) + startWord0f);
  outVertex[0xe] = (edgeT * (endWord0e - startWord0e) + startWord0e);
  return;
}

/* _gleInterpolEyeNO1011 @ 0xb6fe0 (500 bytes) */
void _gleInterpolEyeNO1011(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord10;
  float fVar2;
  float startWord11;
  float windowBiasZ;
  float startWord0b;
  float fVar3;
  float endWord10;
  float windowScaleZ;
  float endWord0b;
  float fVar4;
  float endWord11;
  float startWord09;
  float startWord0a;
  float startWord12;
  float endWord09;
  float endWord12;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar9;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint clipOutcode;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar3 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar2 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar9 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar2;
  fVar3 = (edgeT * (endClipY - fVar3) + fVar3);
  outVertex[7] = fVar1;
  fVar4 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  clipOutcode = 0;
  outVertex[5] = fVar3;
  outVertex[6] = fVar4;
  if (fVar2 < fVar9) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar2) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar3 < fVar9) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar4 < fVar9) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar4) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar2 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar3 + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar4 + windowBiasZ;
  }
  startWord10 = startVertex[0x10];
  startWord11 = startVertex[0x11];
  endWord10 = *(float *)(endVertex + 0x40);
  endWord11 = *(float *)(endVertex + 0x44);
  startWord12 = startVertex[0x12];
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13]);
  endWord12 = *(float *)(endVertex + 0x48);
  outVertex[0x10] = (edgeT * (endWord10 - startWord10) + startWord10)
  ;
  outVertex[0x11] = (edgeT * (endWord11 - startWord11) + startWord11)
  ;
  outVertex[0x12] = (edgeT * (endWord12 - startWord12) + startWord12)
  ;
  if (startVertex == outVertex) {
    return;
  }
  outVertex[0x1d] = startVertex[0x1d];
  outVertex[0x1e] = startVertex[0x1e];
  return;
}

/* _gleInterpolEyeNO1100_body @ 0xb71d8 (636 bytes) */
void _gleInterpolEyeNO1100_body(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,float fparam_6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord0d;
  char cVar2;
  float fVar3;
  float startWord0e;
  float windowBiasZ;
  float endWord0b;
  float fVar4;
  float startWord0f;
  float windowScaleZ;
  float startWord09;
  float fVar5;
  float endWord0d;
  float startWord0a;
  float endWord09;
  float outInvW;
  float endWord0e;
  float endWord0a;
  float endWord0f;
  float startClipX;
  float endClipZ;
  float fVar9;
  float endClipX;
  float startClipY;
  float endClipY;
  float startClipZ;
  uint clipOutcode;
  float dVar14;
  float dVar15;
  float dVar16;
  float dVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = *(float *)(startVertex + 0x24);
  startWord0a = *(float *)(startVertex + 0x28);
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = *(float *)(startVertex + 0x10);
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - fparam_6) + fparam_6);
  startClipY = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  fVar3 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar9 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar3;
  fVar4 = (edgeT * (endClipY - startClipY) + startClipY);
  outVertex[7] = fVar1;
  fVar5 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  cVar2 = *(char *)(startVertex + 0x7f);
  outVertex[5] = fVar4;
  outVertex[6] = fVar5;
  if (fVar3 < fVar9) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar4 < fVar9) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar4) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar5 < fVar9) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar5) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
      fVar5 = fVar5 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar3 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar4 + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar5 + windowBiasZ;
  }
  startWord0d = *(float *)(startVertex + 0x34);
  startWord0e = *(float *)(startVertex + 0x38);
  startWord0f = *(float *)(startVertex + 0x3c);
  endWord0d = *(float *)(endVertex + 0x34);
  endWord0e = *(float *)(endVertex + 0x38);
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0xc] = (edgeT * (*(float *)(endVertex + 0x30) - *(float *)(startVertex + 0x30)) + *(float *)(startVertex + 0x30));
  outVertex[0xd] = (edgeT * (endWord0d - startWord0d) + startWord0d);
  outVertex[0xe] = (edgeT * (endWord0e - startWord0e) + startWord0e);
  outVertex[0xf] = (edgeT * (endWord0f - startWord0f) + startWord0f);
  dVar16 = (double)*(float *)(startVertex + 0x80);
  dVar18 = (double)*(float *)(startVertex + 0x84);
  dVar17 = (double)*(float *)(startVertex + 0x88);
  dVar19 = (double)*(float *)(startVertex + 0x8c);
  if (cVar2 == '\0') {
    dVar14 = (double)*(float *)(startVertex + 0x1c);
    dVar19 = (double)(dVar19 * dVar14);
    dVar16 = (double)(dVar16 * dVar14);
    dVar18 = (double)(dVar18 * dVar14);
    dVar17 = (double)(dVar17 * dVar14);
  }
  dVar14 = (double)*(float *)(endVertex + 0x80);
  dVar21 = (double)*(float *)(endVertex + 0x84);
  dVar20 = (double)*(float *)(endVertex + 0x88);
  dVar22 = (double)*(float *)(endVertex + 0x8c);
  if (*(char *)(endVertex + 0x7f) == '\0') {
    dVar15 = (double)*(float *)(endVertex + 0x1c);
    dVar22 = (double)(dVar22 * dVar15);
    dVar14 = (double)(dVar14 * dVar15);
    dVar21 = (double)(dVar21 * dVar15);
    dVar20 = (double)(dVar20 * dVar15);
  }
  fVar1 = (edgeT * (dVar14 - dVar16) + dVar16);
  fVar3 = (edgeT * (dVar21 - dVar18) + dVar18);
  fVar4 = (edgeT * (dVar22 - dVar19) + dVar19);
  fVar5 = (edgeT * (dVar20 - dVar17) + dVar17);
  if (clipOutcode == 0) {
    outInvW = outVertex[3];
    fVar4 = fVar4 * outInvW;
    fVar1 = fVar1 * outInvW;
    fVar3 = fVar3 * outInvW;
    fVar5 = fVar5 * outInvW;
  }
  outVertex[0x23] = fVar4;
  outVertex[0x20] = fVar1;
  outVertex[0x21] = fVar3;
  outVertex[0x22] = fVar5;
  return;
}

/* _gleInterpolEyeNO1100w_body @ 0xb7458 (548 bytes) */
void _gleInterpolEyeNO1100w_body(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,float fparam_4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord23;
  float startWord0d;
  float fVar2;
  float startWord21;
  float startWord0e;
  float windowBiasZ;
  float endWord0b;
  float fVar3;
  float startWord22;
  float startWord0f;
  float windowScaleZ;
  float startWord09;
  float fVar4;
  float endWord23;
  float endWord0d;
  float startWord0a;
  float endWord09;
  float endWord21;
  float endWord0e;
  float endWord0a;
  float endWord22;
  float endWord0f;
  float startClipX;
  float endClipZ;
  float fVar8;
  float endClipX;
  float startClipY;
  float endClipY;
  float startClipZ;
  uint clipOutcode;
  
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = *(float *)(startVertex + 0x24);
  startWord0a = *(float *)(startVertex + 0x28);
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = *(float *)(startVertex + 0x10);
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - fparam_4) + fparam_4);
  startClipY = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  fVar2 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar8 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar2;
  fVar3 = (edgeT * (endClipY - startClipY) + startClipY);
  outVertex[7] = fVar1;
  fVar4 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = fVar3;
  outVertex[6] = fVar4;
  if (fVar2 < fVar8) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar2) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar3 < fVar8) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar4 < fVar8) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar4) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar2 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar3 + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar4 + windowBiasZ;
  }
  startWord0d = *(float *)(startVertex + 0x34);
  startWord0e = *(float *)(startVertex + 0x38);
  startWord0f = *(float *)(startVertex + 0x3c);
  endWord0d = *(float *)(endVertex + 0x34);
  endWord0e = *(float *)(endVertex + 0x38);
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0xc] = (edgeT * (*(float *)(endVertex + 0x30) - *(float *)(startVertex + 0x30)) + *(float *)(startVertex + 0x30));
  outVertex[0xd] = (edgeT * (endWord0d - startWord0d) + startWord0d);
  outVertex[0xe] = (edgeT * (endWord0e - startWord0e) + startWord0e);
  outVertex[0xf] = (edgeT * (endWord0f - startWord0f) + startWord0f);
  startWord23 = *(float *)(startVertex + 0x8c);
  startWord21 = *(float *)(startVertex + 0x84);
  startWord22 = *(float *)(startVertex + 0x88);
  endWord23 = *(float *)(endVertex + 0x8c);
  endWord21 = *(float *)(endVertex + 0x84);
  endWord22 = *(float *)(endVertex + 0x88);
  outVertex[0x20] =
       (edgeT * (*(float *)(endVertex + 0x80) - *(float *)(startVertex + 0x80)) + *(float *)(startVertex + 0x80));
  outVertex[0x21] = (edgeT * (endWord21 - startWord21) + startWord21)
  ;
  outVertex[0x23] = (edgeT * (endWord23 - startWord23) + startWord23)
  ;
  outVertex[0x22] = (edgeT * (endWord22 - startWord22) + startWord22)
  ;
  return;
}

/* _gleInterpolEyeNO1101 @ 0xb767c (648 bytes) */
void _gleInterpolEyeNO1101(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord10;
  char cVar2;
  float fVar3;
  float startWord11;
  float windowBiasZ;
  float startWord0b;
  float fVar4;
  float endWord10;
  float windowScaleZ;
  float endWord0b;
  float fVar5;
  float endWord11;
  float startWord09;
  float startWord0a;
  float outInvW;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar10;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint clipOutcode;
  float dVar14;
  float dVar15;
  float dVar16;
  float dVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar4 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar3 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar10 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar3;
  fVar4 = (edgeT * (endClipY - fVar4) + fVar4);
  outVertex[7] = fVar1;
  fVar5 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  cVar2 = *(char *)((int)startVertex + 0x7f);
  clipOutcode = 0;
  outVertex[5] = fVar4;
  outVertex[6] = fVar5;
  if (fVar3 < fVar10) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar4 < fVar10) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar4) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar5 < fVar10) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar5) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
      fVar5 = fVar5 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar3 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar4 + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar5 + windowBiasZ;
  }
  dVar16 = (double)startVertex[0x20];
  dVar17 = (double)startVertex[0x21];
  dVar18 = (double)startVertex[0x22];
  dVar22 = (double)startVertex[0x23];
  if (cVar2 == '\0') {
    dVar14 = (double)startVertex[7];
    dVar22 = (double)(dVar22 * dVar14);
    dVar16 = (double)(dVar16 * dVar14);
    dVar17 = (double)(dVar17 * dVar14);
    dVar18 = (double)(dVar18 * dVar14);
  }
  dVar21 = (double)*(float *)(endVertex + 0x80);
  dVar14 = (double)*(float *)(endVertex + 0x84);
  dVar20 = (double)*(float *)(endVertex + 0x88);
  dVar19 = (double)*(float *)(endVertex + 0x8c);
  if (*(char *)(endVertex + 0x7f) == '\0') {
    dVar15 = (double)*(float *)(endVertex + 0x1c);
    dVar19 = (double)(dVar19 * dVar15);
    dVar21 = (double)(dVar21 * dVar15);
    dVar14 = (double)(dVar14 * dVar15);
    dVar20 = (double)(dVar20 * dVar15);
  }
  fVar1 = (edgeT * (dVar21 - dVar16) + dVar16);
  fVar3 = (edgeT * (dVar14 - dVar17) + dVar17);
  fVar4 = (edgeT * (dVar20 - dVar18) + dVar18);
  fVar5 = (edgeT * (dVar19 - dVar22) + dVar22);
  if (clipOutcode == 0) {
    outInvW = outVertex[3];
    fVar5 = fVar5 * outInvW;
    fVar1 = fVar1 * outInvW;
    fVar3 = fVar3 * outInvW;
    fVar4 = fVar4 * outInvW;
  }
  outVertex[0x20] = fVar1;
  outVertex[0x21] = fVar3;
  outVertex[0x22] = fVar4;
  outVertex[0x23] = fVar5;
  startWord10 = startVertex[0x10];
  startWord11 = startVertex[0x11];
  endWord10 = *(float *)(endVertex + 0x40);
  endWord11 = *(float *)(endVertex + 0x44);
  outVertex[0x12] =
       (edgeT * (*(float *)(endVertex + 0x48) - startVertex[0x12]) + startVertex[0x12]);
  outVertex[0x10] = (edgeT * (endWord10 - startWord10) + startWord10)
  ;
  outVertex[0x11] = (edgeT * (endWord11 - startWord11) + startWord11)
  ;
  if (startVertex == outVertex) {
    return;
  }
  outVertex[0x1d] = startVertex[0x1d];
  outVertex[0x1e] = startVertex[0x1e];
  return;
}

/* _gleInterpolEyeNO1101w @ 0xb7904 (560 bytes) */
void _gleInterpolEyeNO1101w(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord10;
  float startWord21;
  float fVar2;
  float startWord11;
  float startWord22;
  float windowBiasZ;
  float startWord0b;
  float fVar3;
  float endWord10;
  float startWord23;
  float windowScaleZ;
  float endWord0b;
  float fVar4;
  float endWord11;
  float endWord21;
  float startWord09;
  float startWord0a;
  float endWord22;
  float endWord09;
  float endWord23;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar9;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint clipOutcode;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar3 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar2 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar9 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar2;
  fVar3 = (edgeT * (endClipY - fVar3) + fVar3);
  outVertex[7] = fVar1;
  fVar4 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  clipOutcode = 0;
  outVertex[5] = fVar3;
  outVertex[6] = fVar4;
  if (fVar2 < fVar9) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar2) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar3 < fVar9) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar4 < fVar9) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar4) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar2 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar3 + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar4 + windowBiasZ;
  }
  startWord21 = startVertex[0x21];
  startWord22 = startVertex[0x22];
  startWord23 = startVertex[0x23];
  endWord21 = *(float *)(endVertex + 0x84);
  endWord22 = *(float *)(endVertex + 0x88);
  endWord23 = *(float *)(endVertex + 0x8c);
  outVertex[0x20] =
       (edgeT * (*(float *)(endVertex + 0x80) - startVertex[0x20]) + startVertex[0x20]);
  outVertex[0x21] = (edgeT * (endWord21 - startWord21) + startWord21)
  ;
  outVertex[0x22] = (edgeT * (endWord22 - startWord22) + startWord22)
  ;
  outVertex[0x23] = (edgeT * (endWord23 - startWord23) + startWord23)
  ;
  startWord10 = startVertex[0x10];
  startWord11 = startVertex[0x11];
  endWord10 = *(float *)(endVertex + 0x40);
  endWord11 = *(float *)(endVertex + 0x44);
  outVertex[0x12] =
       (edgeT * (*(float *)(endVertex + 0x48) - startVertex[0x12]) + startVertex[0x12]);
  outVertex[0x10] = (edgeT * (endWord10 - startWord10) + startWord10)
  ;
  outVertex[0x11] = (edgeT * (endWord11 - startWord11) + startWord11)
  ;
  if (startVertex == outVertex) {
    return;
  }
  outVertex[0x1d] = startVertex[0x1d];
  outVertex[0x1e] = startVertex[0x1e];
  return;
}

/* _gleInterpolEyeNO1110_body @ 0xb7b38 (656 bytes) */
void _gleInterpolEyeNO1110_body(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,float fparam_5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord0c;
  char cVar2;
  float fVar3;
  float startWord0d;
  float windowBiasZ;
  float endWord0b;
  float fVar4;
  float startWord0f;
  float windowScaleZ;
  float startWord09;
  float fVar5;
  float endWord0c;
  float startWord0a;
  float endWord09;
  float outInvW;
  float endWord0d;
  float endWord0a;
  float startWord0e;
  float startClipX;
  float endWord0f;
  float endClipZ;
  float fVar9;
  float endWord0e;
  float endClipX;
  float startClipY;
  float endClipY;
  float startClipZ;
  uint clipOutcode;
  float dVar14;
  float dVar15;
  float dVar16;
  float dVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = *(float *)(startVertex + 0x24);
  startWord0a = *(float *)(startVertex + 0x28);
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = *(float *)(startVertex + 0x10);
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - fparam_5) + fparam_5);
  startClipY = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  fVar3 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar9 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar3;
  fVar4 = (edgeT * (endClipY - startClipY) + startClipY);
  outVertex[7] = fVar1;
  fVar5 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  cVar2 = *(char *)(startVertex + 0x7f);
  outVertex[5] = fVar4;
  outVertex[6] = fVar5;
  if (fVar3 < fVar9) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar4 < fVar9) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar4) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar5 < fVar9) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar5) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
      fVar5 = fVar5 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar3 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar4 + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar5 + windowBiasZ;
  }
  startWord0c = *(float *)(startVertex + 0x30);
  startWord0d = *(float *)(startVertex + 0x34);
  startWord0f = *(float *)(startVertex + 0x3c);
  endWord0c = *(float *)(endVertex + 0x30);
  endWord0d = *(float *)(endVertex + 0x34);
  startWord0e = *(float *)(startVertex + 0x38);
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - *(float *)(startVertex + 0x4c)) + *(float *)(startVertex + 0x4c));
  endWord0e = *(float *)(endVertex + 0x38);
  outVertex[0xc] = (edgeT * (endWord0c - startWord0c) + startWord0c);
  outVertex[0xd] = (edgeT * (endWord0d - startWord0d) + startWord0d);
  outVertex[0xf] = (edgeT * (endWord0f - startWord0f) + startWord0f);
  outVertex[0xe] = (edgeT * (endWord0e - startWord0e) + startWord0e);
  dVar16 = (double)*(float *)(startVertex + 0x80);
  dVar17 = (double)*(float *)(startVertex + 0x84);
  dVar20 = (double)*(float *)(startVertex + 0x88);
  dVar18 = (double)*(float *)(startVertex + 0x8c);
  if (cVar2 == '\0') {
    dVar14 = (double)*(float *)(startVertex + 0x1c);
    dVar18 = (double)(dVar18 * dVar14);
    dVar16 = (double)(dVar16 * dVar14);
    dVar17 = (double)(dVar17 * dVar14);
    dVar20 = (double)(dVar20 * dVar14);
  }
  dVar14 = (double)*(float *)(endVertex + 0x80);
  dVar19 = (double)*(float *)(endVertex + 0x84);
  dVar22 = (double)*(float *)(endVertex + 0x88);
  dVar21 = (double)*(float *)(endVertex + 0x8c);
  if (*(char *)(endVertex + 0x7f) == '\0') {
    dVar15 = (double)*(float *)(endVertex + 0x1c);
    dVar21 = (double)(dVar21 * dVar15);
    dVar14 = (double)(dVar14 * dVar15);
    dVar19 = (double)(dVar19 * dVar15);
    dVar22 = (double)(dVar22 * dVar15);
  }
  fVar1 = (edgeT * (dVar14 - dVar16) + dVar16);
  fVar3 = (edgeT * (dVar19 - dVar17) + dVar17);
  fVar4 = (edgeT * (dVar21 - dVar18) + dVar18);
  fVar5 = (edgeT * (dVar22 - dVar20) + dVar20);
  if (clipOutcode == 0) {
    outInvW = outVertex[3];
    fVar4 = fVar4 * outInvW;
    fVar1 = fVar1 * outInvW;
    fVar3 = fVar3 * outInvW;
    fVar5 = fVar5 * outInvW;
  }
  outVertex[0x23] = fVar4;
  outVertex[0x20] = fVar1;
  outVertex[0x21] = fVar3;
  outVertex[0x22] = fVar5;
  return;
}

/* _gleInterpolEyeNO1110w_body @ 0xb7dcc (568 bytes) */
void _gleInterpolEyeNO1110w_body(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,float fparam_4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord23;
  float startWord0c;
  float fVar2;
  float startWord21;
  float startWord0d;
  float windowBiasZ;
  float endWord0b;
  float fVar3;
  float startWord22;
  float startWord0f;
  float windowScaleZ;
  float startWord09;
  float fVar4;
  float endWord23;
  float endWord0c;
  float startWord0a;
  float endWord09;
  float endWord21;
  float endWord0d;
  float endWord0a;
  float endWord22;
  float startWord0e;
  float startClipX;
  float endWord0f;
  float endClipZ;
  float fVar8;
  float endWord0e;
  float endClipX;
  float startClipY;
  float endClipY;
  float startClipZ;
  uint clipOutcode;
  
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = *(float *)(startVertex + 0x24);
  startWord0a = *(float *)(startVertex + 0x28);
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = *(float *)(startVertex + 0x10);
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - fparam_4) + fparam_4);
  startClipY = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  fVar2 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar8 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar2;
  fVar3 = (edgeT * (endClipY - startClipY) + startClipY);
  outVertex[7] = fVar1;
  fVar4 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = fVar3;
  outVertex[6] = fVar4;
  if (fVar2 < fVar8) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar2) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar3 < fVar8) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar4 < fVar8) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar4) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar2 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar3 + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar4 + windowBiasZ;
  }
  startWord0c = *(float *)(startVertex + 0x30);
  startWord0d = *(float *)(startVertex + 0x34);
  startWord0f = *(float *)(startVertex + 0x3c);
  endWord0c = *(float *)(endVertex + 0x30);
  endWord0d = *(float *)(endVertex + 0x34);
  startWord0e = *(float *)(startVertex + 0x38);
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - *(float *)(startVertex + 0x4c)) + *(float *)(startVertex + 0x4c));
  endWord0e = *(float *)(endVertex + 0x38);
  outVertex[0xc] = (edgeT * (endWord0c - startWord0c) + startWord0c);
  outVertex[0xd] = (edgeT * (endWord0d - startWord0d) + startWord0d);
  outVertex[0xf] = (edgeT * (endWord0f - startWord0f) + startWord0f);
  outVertex[0xe] = (edgeT * (endWord0e - startWord0e) + startWord0e);
  startWord23 = *(float *)(startVertex + 0x8c);
  startWord21 = *(float *)(startVertex + 0x84);
  startWord22 = *(float *)(startVertex + 0x88);
  endWord23 = *(float *)(endVertex + 0x8c);
  endWord21 = *(float *)(endVertex + 0x84);
  endWord22 = *(float *)(endVertex + 0x88);
  outVertex[0x20] =
       (edgeT * (*(float *)(endVertex + 0x80) - *(float *)(startVertex + 0x80)) + *(float *)(startVertex + 0x80));
  outVertex[0x21] = (edgeT * (endWord21 - startWord21) + startWord21)
  ;
  outVertex[0x23] = (edgeT * (endWord23 - startWord23) + startWord23)
  ;
  outVertex[0x22] = (edgeT * (endWord22 - startWord22) + startWord22)
  ;
  return;
}

/* _gleInterpolEyeNO1111 @ 0xb8004 (668 bytes) */
void _gleInterpolEyeNO1111(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord10;
  char cVar2;
  float fVar3;
  float startWord11;
  float windowBiasZ;
  float startWord0b;
  float fVar4;
  float endWord10;
  float windowScaleZ;
  float endWord0b;
  float fVar5;
  float endWord11;
  float startWord09;
  float startWord0a;
  float outInvW;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar10;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint clipOutcode;
  float dVar14;
  float dVar15;
  float dVar16;
  float dVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar4 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar3 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar10 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar3;
  fVar4 = (edgeT * (endClipY - fVar4) + fVar4);
  outVertex[7] = fVar1;
  fVar5 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  cVar2 = *(char *)((int)startVertex + 0x7f);
  clipOutcode = 0;
  outVertex[5] = fVar4;
  outVertex[6] = fVar5;
  if (fVar3 < fVar10) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar4 < fVar10) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar4) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar5 < fVar10) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar5) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
      fVar5 = fVar5 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar3 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar4 + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar5 + windowBiasZ;
  }
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13]);
  dVar16 = (double)startVertex[0x20];
  dVar17 = (double)startVertex[0x21];
  dVar20 = (double)startVertex[0x22];
  dVar22 = (double)startVertex[0x23];
  if (cVar2 == '\0') {
    dVar14 = (double)startVertex[7];
    dVar22 = (double)(dVar22 * dVar14);
    dVar16 = (double)(dVar16 * dVar14);
    dVar17 = (double)(dVar17 * dVar14);
    dVar20 = (double)(dVar20 * dVar14);
  }
  dVar19 = (double)*(float *)(endVertex + 0x80);
  dVar14 = (double)*(float *)(endVertex + 0x84);
  dVar21 = (double)*(float *)(endVertex + 0x88);
  dVar18 = (double)*(float *)(endVertex + 0x8c);
  if (*(char *)(endVertex + 0x7f) == '\0') {
    dVar15 = (double)*(float *)(endVertex + 0x1c);
    dVar18 = (double)(dVar18 * dVar15);
    dVar19 = (double)(dVar19 * dVar15);
    dVar14 = (double)(dVar14 * dVar15);
    dVar21 = (double)(dVar21 * dVar15);
  }
  fVar1 = (edgeT * (dVar19 - dVar16) + dVar16);
  fVar3 = (edgeT * (dVar14 - dVar17) + dVar17);
  fVar4 = (edgeT * (dVar21 - dVar20) + dVar20);
  fVar5 = (edgeT * (dVar18 - dVar22) + dVar22);
  if (clipOutcode == 0) {
    outInvW = outVertex[3];
    fVar5 = fVar5 * outInvW;
    fVar1 = fVar1 * outInvW;
    fVar3 = fVar3 * outInvW;
    fVar4 = fVar4 * outInvW;
  }
  outVertex[0x20] = fVar1;
  outVertex[0x21] = fVar3;
  outVertex[0x22] = fVar4;
  outVertex[0x23] = fVar5;
  startWord10 = startVertex[0x10];
  startWord11 = startVertex[0x11];
  endWord10 = *(float *)(endVertex + 0x40);
  endWord11 = *(float *)(endVertex + 0x44);
  outVertex[0x12] =
       (edgeT * (*(float *)(endVertex + 0x48) - startVertex[0x12]) + startVertex[0x12]);
  outVertex[0x10] = (edgeT * (endWord10 - startWord10) + startWord10)
  ;
  outVertex[0x11] = (edgeT * (endWord11 - startWord11) + startWord11)
  ;
  if (startVertex == outVertex) {
    return;
  }
  outVertex[0x1d] = startVertex[0x1d];
  outVertex[0x1e] = startVertex[0x1e];
  return;
}

/* _gleInterpolEyeNO1111w @ 0xb82a0 (580 bytes) */
void _gleInterpolEyeNO1111w(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord10;
  float startWord21;
  float fVar2;
  float startWord11;
  float startWord22;
  float windowBiasZ;
  float startWord0b;
  float fVar3;
  float endWord10;
  float startWord23;
  float windowScaleZ;
  float endWord0b;
  float fVar4;
  float endWord11;
  float endWord21;
  float startWord09;
  float startWord0a;
  float endWord22;
  float endWord09;
  float endWord23;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar9;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint clipOutcode;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar3 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar2 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar9 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar2;
  fVar3 = (edgeT * (endClipY - fVar3) + fVar3);
  outVertex[7] = fVar1;
  fVar4 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  clipOutcode = 0;
  outVertex[5] = fVar3;
  outVertex[6] = fVar4;
  if (fVar2 < fVar9) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar2) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar3 < fVar9) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar4 < fVar9) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar4) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar2 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar3 + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar4 + windowBiasZ;
  }
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13]);
  startWord21 = startVertex[0x21];
  startWord22 = startVertex[0x22];
  startWord23 = startVertex[0x23];
  endWord21 = *(float *)(endVertex + 0x84);
  endWord22 = *(float *)(endVertex + 0x88);
  endWord23 = *(float *)(endVertex + 0x8c);
  outVertex[0x20] =
       (edgeT * (*(float *)(endVertex + 0x80) - startVertex[0x20]) + startVertex[0x20]);
  outVertex[0x21] = (edgeT * (endWord21 - startWord21) + startWord21)
  ;
  outVertex[0x22] = (edgeT * (endWord22 - startWord22) + startWord22)
  ;
  outVertex[0x23] = (edgeT * (endWord23 - startWord23) + startWord23)
  ;
  startWord10 = startVertex[0x10];
  startWord11 = startVertex[0x11];
  endWord10 = *(float *)(endVertex + 0x40);
  endWord11 = *(float *)(endVertex + 0x44);
  outVertex[0x12] =
       (edgeT * (*(float *)(endVertex + 0x48) - startVertex[0x12]) + startVertex[0x12]);
  outVertex[0x10] = (edgeT * (endWord10 - startWord10) + startWord10)
  ;
  outVertex[0x11] = (edgeT * (endWord11 - startWord11) + startWord11)
  ;
  if (startVertex == outVertex) {
    return;
  }
  outVertex[0x1d] = startVertex[0x1d];
  outVertex[0x1e] = startVertex[0x1e];
  return;
}

/* _gleInterpolEyeNO1200_body @ 0xb84e8 (688 bytes) */
void _gleInterpolEyeNO1200_body(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,float fparam_4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord0d;
  char cVar2;
  float fVar3;
  float startWord0e;
  float windowScaleZ;
  float endWord0b;
  float fVar4;
  float startWord0f;
  float windowBiasZ;
  float startWord09;
  float fVar5;
  float endWord0d;
  float startWord0a;
  float endWord09;
  float outInvW;
  float endWord0e;
  float endWord0a;
  float endWord0f;
  float startClipX;
  float endClipZ;
  float fVar9;
  float endClipX;
  float startClipY;
  float endClipY;
  float startClipZ;
  uint uVar13;
  int iVar14;
  uint texEnableMask;
  uint clipOutcode;
  uint uVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  float dVar23;
  float dVar24;
  float dVar25;
  float dVar26;
  
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = *(float *)(startVertex + 0x24);
  startWord0a = *(float *)(startVertex + 0x28);
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = *(float *)(startVertex + 0x10);
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - fparam_4) + fparam_4);
  startClipY = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  fVar3 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar9 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar3;
  fVar4 = (edgeT * (endClipY - startClipY) + startClipY);
  outVertex[7] = fVar1;
  fVar5 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  cVar2 = *(char *)(startVertex + 0x7f);
  outVertex[5] = fVar4;
  outVertex[6] = fVar5;
  if (fVar3 < fVar9) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar4 < fVar9) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar4) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar5 < fVar9) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar5) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
      fVar5 = fVar5 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar3 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar4 + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar5 + windowBiasZ;
  }
  startWord0d = *(float *)(startVertex + 0x34);
  uVar17 = 0;
  startWord0e = *(float *)(startVertex + 0x38);
  startWord0f = *(float *)(startVertex + 0x3c);
  endWord0d = *(float *)(endVertex + 0x34);
  endWord0e = *(float *)(endVertex + 0x38);
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0xc] = (edgeT * (*(float *)(endVertex + 0x30) - *(float *)(startVertex + 0x30)) + *(float *)(startVertex + 0x30));
  outVertex[0xd] = (edgeT * (endWord0d - startWord0d) + startWord0d);
  outVertex[0xe] = (edgeT * (endWord0e - startWord0e) + startWord0e);
  outVertex[0xf] = (edgeT * (endWord0f - startWord0f) + startWord0f);
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    uVar13 = texEnableMask >> (uVar17 & 0x3f);
    if ((uVar13 & 1) == 0) {
      if (uVar13 == 0) {
        return;
      }
    }
    else {
      iVar14 = uVar17 * 0x10 + startVertex;
      dVar21 = (double)*(float *)(iVar14 + 0x8c);
      dVar20 = (double)*(float *)(iVar14 + 0x80);
      dVar22 = (double)*(float *)(iVar14 + 0x84);
      dVar23 = (double)*(float *)(iVar14 + 0x88);
      if (cVar2 == '\0') {
        dVar18 = (double)*(float *)(startVertex + 0x1c);
        dVar21 = (double)(dVar21 * dVar18);
        dVar20 = (double)(dVar20 * dVar18);
        dVar22 = (double)(dVar22 * dVar18);
        dVar23 = (double)(dVar23 * dVar18);
      }
      iVar14 = uVar17 * 0x10 + endVertex;
      dVar26 = (double)*(float *)(iVar14 + 0x8c);
      dVar18 = (double)*(float *)(iVar14 + 0x80);
      dVar25 = (double)*(float *)(iVar14 + 0x84);
      dVar24 = (double)*(float *)(iVar14 + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        dVar19 = (double)*(float *)(endVertex + 0x1c);
        dVar26 = (double)(dVar26 * dVar19);
        dVar18 = (double)(dVar18 * dVar19);
        dVar25 = (double)(dVar25 * dVar19);
        dVar24 = (double)(dVar24 * dVar19);
      }
      fVar1 = (edgeT * (dVar18 - dVar20) + dVar20);
      fVar3 = (edgeT * (dVar25 - dVar22) + dVar22);
      fVar4 = (edgeT * (dVar24 - dVar23) + dVar23);
      fVar5 = (edgeT * (dVar26 - dVar21) + dVar21);
      if (clipOutcode == 0) {
        outInvW = outVertex[3];
        fVar5 = fVar5 * outInvW;
        fVar1 = fVar1 * outInvW;
        fVar3 = fVar3 * outInvW;
        fVar4 = fVar4 * outInvW;
      }
      outVertex[uVar17 * 4 + 0x23] = fVar5;
      outVertex[uVar17 * 4 + 0x20] = fVar1;
      outVertex[uVar17 * 4 + 0x21] = fVar3;
      outVertex[uVar17 * 4 + 0x22] = fVar4;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* _gleInterpolEyeNO1200w_body @ 0xb879c (600 bytes) */
void _gleInterpolEyeNO1200w_body(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,float fparam_3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord0d;
  float fVar2;
  float startWord0e;
  float windowScaleZ;
  float endWord0b;
  float fVar3;
  float startWord0f;
  float windowBiasZ;
  float startWord09;
  float fVar4;
  float endWord0d;
  float startWord0a;
  float fVar5;
  float endWord0e;
  float endWord09;
  float fVar6;
  float endWord0f;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar8;
  float endClipX;
  float startClipY;
  float endClipY;
  float startClipZ;
  uint uVar12;
  uint clipOutcode;
  uint texEnableMask;
  int iVar14;
  uint uVar15;
  int iVar16;
  
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = *(float *)(startVertex + 0x24);
  startWord0a = *(float *)(startVertex + 0x28);
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = *(float *)(startVertex + 0x10);
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - fparam_3) + fparam_3);
  startClipY = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  fVar2 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar8 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar2;
  fVar3 = (edgeT * (endClipY - startClipY) + startClipY);
  outVertex[7] = fVar1;
  fVar4 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = fVar3;
  outVertex[6] = fVar4;
  if (fVar2 < fVar8) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar2) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar3 < fVar8) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar4 < fVar8) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar4) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar2 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar3 + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar4 + windowBiasZ;
  }
  uVar15 = 0;
  startWord0d = *(float *)(startVertex + 0x34);
  startWord0e = *(float *)(startVertex + 0x38);
  startWord0f = *(float *)(startVertex + 0x3c);
  endWord0d = *(float *)(endVertex + 0x34);
  endWord0e = *(float *)(endVertex + 0x38);
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0xc] = (edgeT * (*(float *)(endVertex + 0x30) - *(float *)(startVertex + 0x30)) + *(float *)(startVertex + 0x30));
  outVertex[0xd] = (edgeT * (endWord0d - startWord0d) + startWord0d);
  outVertex[0xe] = (edgeT * (endWord0e - startWord0e) + startWord0e);
  outVertex[0xf] = (edgeT * (endWord0f - startWord0f) + startWord0f);
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    uVar12 = texEnableMask >> (uVar15 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        return;
      }
    }
    else {
      iVar14 = uVar15 * 0x10 + startVertex;
      iVar16 = uVar15 * 0x10 + endVertex;
      fVar1 = *(float *)(iVar14 + 0x8c);
      fVar2 = *(float *)(iVar14 + 0x84);
      fVar3 = *(float *)(iVar14 + 0x88);
      fVar4 = *(float *)(iVar16 + 0x8c);
      fVar5 = *(float *)(iVar16 + 0x84);
      fVar6 = *(float *)(iVar16 + 0x88);
      outVertex[uVar15 * 4 + 0x20] =
           (edgeT * (*(float *)(iVar16 + 0x80) - *(float *)(iVar14 + 0x80)) + *(float *)(iVar14 + 0x80));
      outVertex[uVar15 * 4 + 0x21] =
           (edgeT * (fVar5 - fVar2) + fVar2);
      outVertex[uVar15 * 4 + 0x22] =
           (edgeT * (fVar6 - fVar3) + fVar3);
      outVertex[uVar15 * 4 + 0x23] =
           (edgeT * (fVar4 - fVar1) + fVar1);
    }
    uVar15 = uVar15 + 1;
  } while( true );
}

/* _gleInterpolEyeNO1201 @ 0xb89f4 (704 bytes) */
void _gleInterpolEyeNO1201(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord10;
  char cVar2;
  float fVar3;
  float startWord11;
  float windowScaleZ;
  float startWord0b;
  float fVar4;
  float endWord10;
  float windowBiasZ;
  float endWord0b;
  float fVar5;
  float endWord11;
  float startWord09;
  float startWord0a;
  float outInvW;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar10;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint uVar13;
  int iVar14;
  uint texEnableMask;
  uint clipOutcode;
  uint uVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  float dVar23;
  float dVar24;
  float dVar25;
  float dVar26;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar4 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar3 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar10 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar3;
  fVar4 = (edgeT * (endClipY - fVar4) + fVar4);
  outVertex[7] = fVar1;
  fVar5 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  cVar2 = *(char *)((int)startVertex + 0x7f);
  clipOutcode = 0;
  outVertex[5] = fVar4;
  outVertex[6] = fVar5;
  if (fVar3 < fVar10) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar4 < fVar10) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar4) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar5 < fVar10) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar5) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
      fVar5 = fVar5 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar3 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar4 + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar5 + windowBiasZ;
  }
  texEnableMask = *(uint *)(glContext + 0x5150);
  uVar17 = 0;
  do {
    uVar13 = texEnableMask >> (uVar17 & 0x3f);
    if ((uVar13 & 1) == 0) {
      if (uVar13 == 0) {
        startWord10 = startVertex[0x10];
        startWord11 = startVertex[0x11];
        endWord10 = *(float *)(endVertex + 0x40);
        endWord11 = *(float *)(endVertex + 0x44);
        outVertex[0x12] =
             (edgeT * (*(float *)(endVertex + 0x48) - startVertex[0x12]) + startVertex[0x12]);
        outVertex[0x10] =
             (edgeT * (endWord10 - startWord10) + startWord10);
        outVertex[0x11] =
             (edgeT * (endWord11 - startWord11) + startWord11);
        if (startVertex == outVertex) {
          return;
        }
        outVertex[0x1d] = startVertex[0x1d];
        outVertex[0x1e] = startVertex[0x1e];
        return;
      }
    }
    else {
      dVar26 = (double)startVertex[uVar17 * 4 + 0x23];
      dVar20 = (double)startVertex[uVar17 * 4 + 0x20];
      dVar21 = (double)startVertex[uVar17 * 4 + 0x21];
      dVar22 = (double)startVertex[uVar17 * 4 + 0x22];
      if (cVar2 == '\0') {
        dVar18 = (double)startVertex[7];
        dVar26 = (double)(dVar26 * dVar18);
        dVar20 = (double)(dVar20 * dVar18);
        dVar21 = (double)(dVar21 * dVar18);
        dVar22 = (double)(dVar22 * dVar18);
      }
      iVar14 = uVar17 * 0x10 + endVertex;
      dVar23 = (double)*(float *)(iVar14 + 0x8c);
      dVar25 = (double)*(float *)(iVar14 + 0x80);
      dVar18 = (double)*(float *)(iVar14 + 0x84);
      dVar24 = (double)*(float *)(iVar14 + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        dVar19 = (double)*(float *)(endVertex + 0x1c);
        dVar23 = (double)(dVar23 * dVar19);
        dVar25 = (double)(dVar25 * dVar19);
        dVar18 = (double)(dVar18 * dVar19);
        dVar24 = (double)(dVar24 * dVar19);
      }
      fVar1 = (edgeT * (dVar25 - dVar20) + dVar20);
      fVar3 = (edgeT * (dVar18 - dVar21) + dVar21);
      fVar4 = (edgeT * (dVar24 - dVar22) + dVar22);
      fVar5 = (edgeT * (dVar23 - dVar26) + dVar26);
      if (clipOutcode == 0) {
        outInvW = outVertex[3];
        fVar5 = fVar5 * outInvW;
        fVar1 = fVar1 * outInvW;
        fVar3 = fVar3 * outInvW;
        fVar4 = fVar4 * outInvW;
      }
      outVertex[uVar17 * 4 + 0x23] = fVar5;
      outVertex[uVar17 * 4 + 0x20] = fVar1;
      outVertex[uVar17 * 4 + 0x21] = fVar3;
      outVertex[uVar17 * 4 + 0x22] = fVar4;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* _gleInterpolEyeNO1201w @ 0xb8cb4 (616 bytes) */
void _gleInterpolEyeNO1201w(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startTexCoordQ;
  float startWord10;
  float fVar2;
  float startTexCoordT;
  float startWord11;
  float windowScaleZ;
  float startWord0b;
  float fVar3;
  float startTexCoordR;
  float endWord10;
  float windowBiasZ;
  float endWord0b;
  float fVar4;
  float endWord11;
  float startWord09;
  float fVar5;
  float startWord0a;
  float fVar6;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar9;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint uVar12;
  uint clipOutcode;
  uint texEnableMask;
  uint uVar14;
  int iVar15;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar3 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar2 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar9 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar2;
  fVar3 = (edgeT * (endClipY - fVar3) + fVar3);
  outVertex[7] = fVar1;
  fVar4 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  clipOutcode = 0;
  outVertex[5] = fVar3;
  outVertex[6] = fVar4;
  if (fVar2 < fVar9) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar2) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar3 < fVar9) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar4 < fVar9) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar4) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar2 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar3 + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar4 + windowBiasZ;
  }
  texEnableMask = *(uint *)(glContext + 0x5150);
  uVar14 = 0;
  do {
    uVar12 = texEnableMask >> (uVar14 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        startWord10 = startVertex[0x10];
        startWord11 = startVertex[0x11];
        endWord10 = *(float *)(endVertex + 0x40);
        endWord11 = *(float *)(endVertex + 0x44);
        outVertex[0x12] =
             (edgeT * (*(float *)(endVertex + 0x48) - startVertex[0x12]) + startVertex[0x12]);
        outVertex[0x10] =
             (edgeT * (endWord10 - startWord10) + startWord10);
        outVertex[0x11] =
             (edgeT * (endWord11 - startWord11) + startWord11);
        if (startVertex == outVertex) {
          return;
        }
        outVertex[0x1d] = startVertex[0x1d];
        outVertex[0x1e] = startVertex[0x1e];
        return;
      }
    }
    else {
      iVar15 = uVar14 * 0x10 + endVertex;
      startTexCoordQ = startVertex[uVar14 * 4 + 0x23];
      startTexCoordT = startVertex[uVar14 * 4 + 0x21];
      startTexCoordR = startVertex[uVar14 * 4 + 0x22];
      fVar4 = *(float *)(iVar15 + 0x8c);
      fVar5 = *(float *)(iVar15 + 0x84);
      fVar6 = *(float *)(iVar15 + 0x88);
      outVertex[uVar14 * 4 + 0x20] =
           (edgeT * (*(float *)(iVar15 + 0x80) - startVertex[uVar14 * 4 + 0x20]) + startVertex[uVar14 * 4 + 0x20]);
      outVertex[uVar14 * 4 + 0x21] =
           (edgeT * (fVar5 - startTexCoordT) + startTexCoordT);
      outVertex[uVar14 * 4 + 0x22] =
           (edgeT * (fVar6 - startTexCoordR) + startTexCoordR);
      outVertex[uVar14 * 4 + 0x23] =
           (edgeT * (fVar4 - startTexCoordQ) + startTexCoordQ);
    }
    uVar14 = uVar14 + 1;
  } while( true );
}

/* _gleInterpolEyeNO1210_body @ 0xb8f20 (708 bytes) */
void _gleInterpolEyeNO1210_body(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,float fparam_4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord0c;
  char cVar2;
  float fVar3;
  float startWord0d;
  float windowScaleZ;
  float endWord0b;
  float fVar4;
  float startWord0f;
  float windowBiasZ;
  float startWord09;
  float fVar5;
  float endWord0c;
  float startWord0a;
  float endWord09;
  float outInvW;
  float endWord0d;
  float endWord0a;
  float startWord0e;
  float startClipX;
  float endWord0f;
  float endClipZ;
  float fVar9;
  float endWord0e;
  float endClipX;
  float startClipY;
  float endClipY;
  float startClipZ;
  uint uVar13;
  int iVar14;
  uint texEnableMask;
  uint clipOutcode;
  uint uVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  float dVar23;
  float dVar24;
  float dVar25;
  float dVar26;
  
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = *(float *)(startVertex + 0x24);
  startWord0a = *(float *)(startVertex + 0x28);
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = *(float *)(startVertex + 0x10);
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - fparam_4) + fparam_4);
  startClipY = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  fVar3 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar9 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar3;
  fVar4 = (edgeT * (endClipY - startClipY) + startClipY);
  outVertex[7] = fVar1;
  fVar5 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  cVar2 = *(char *)(startVertex + 0x7f);
  outVertex[5] = fVar4;
  outVertex[6] = fVar5;
  if (fVar3 < fVar9) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar4 < fVar9) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar4) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar5 < fVar9) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar5) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
      fVar5 = fVar5 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar3 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar4 + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar5 + windowBiasZ;
  }
  uVar17 = 0;
  startWord0c = *(float *)(startVertex + 0x30);
  startWord0d = *(float *)(startVertex + 0x34);
  startWord0f = *(float *)(startVertex + 0x3c);
  endWord0c = *(float *)(endVertex + 0x30);
  endWord0d = *(float *)(endVertex + 0x34);
  startWord0e = *(float *)(startVertex + 0x38);
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - *(float *)(startVertex + 0x4c)) + *(float *)(startVertex + 0x4c));
  endWord0e = *(float *)(endVertex + 0x38);
  outVertex[0xc] = (edgeT * (endWord0c - startWord0c) + startWord0c);
  outVertex[0xd] = (edgeT * (endWord0d - startWord0d) + startWord0d);
  outVertex[0xf] = (edgeT * (endWord0f - startWord0f) + startWord0f);
  outVertex[0xe] = (edgeT * (endWord0e - startWord0e) + startWord0e);
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    uVar13 = texEnableMask >> (uVar17 & 0x3f);
    if ((uVar13 & 1) == 0) {
      if (uVar13 == 0) {
        return;
      }
    }
    else {
      iVar14 = uVar17 * 0x10 + startVertex;
      dVar21 = (double)*(float *)(iVar14 + 0x8c);
      dVar20 = (double)*(float *)(iVar14 + 0x80);
      dVar22 = (double)*(float *)(iVar14 + 0x84);
      dVar24 = (double)*(float *)(iVar14 + 0x88);
      if (cVar2 == '\0') {
        dVar18 = (double)*(float *)(startVertex + 0x1c);
        dVar21 = (double)(dVar21 * dVar18);
        dVar20 = (double)(dVar20 * dVar18);
        dVar22 = (double)(dVar22 * dVar18);
        dVar24 = (double)(dVar24 * dVar18);
      }
      iVar14 = uVar17 * 0x10 + endVertex;
      dVar25 = (double)*(float *)(iVar14 + 0x8c);
      dVar18 = (double)*(float *)(iVar14 + 0x80);
      dVar23 = (double)*(float *)(iVar14 + 0x84);
      dVar26 = (double)*(float *)(iVar14 + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        dVar19 = (double)*(float *)(endVertex + 0x1c);
        dVar25 = (double)(dVar25 * dVar19);
        dVar18 = (double)(dVar18 * dVar19);
        dVar23 = (double)(dVar23 * dVar19);
        dVar26 = (double)(dVar26 * dVar19);
      }
      fVar1 = (edgeT * (dVar18 - dVar20) + dVar20);
      fVar3 = (edgeT * (dVar23 - dVar22) + dVar22);
      fVar4 = (edgeT * (dVar26 - dVar24) + dVar24);
      fVar5 = (edgeT * (dVar25 - dVar21) + dVar21);
      if (clipOutcode == 0) {
        outInvW = outVertex[3];
        fVar5 = fVar5 * outInvW;
        fVar1 = fVar1 * outInvW;
        fVar3 = fVar3 * outInvW;
        fVar4 = fVar4 * outInvW;
      }
      outVertex[uVar17 * 4 + 0x23] = fVar5;
      outVertex[uVar17 * 4 + 0x20] = fVar1;
      outVertex[uVar17 * 4 + 0x21] = fVar3;
      outVertex[uVar17 * 4 + 0x22] = fVar4;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* _gleInterpolEyeNO1210w_body @ 0xb91e8 (620 bytes) */
void _gleInterpolEyeNO1210w_body(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,float fparam_3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord0c;
  float fVar2;
  float startWord0d;
  float windowScaleZ;
  float endWord0b;
  float fVar3;
  float startWord0f;
  float windowBiasZ;
  float startWord09;
  float fVar4;
  float endWord0c;
  float startWord0a;
  float fVar5;
  float endWord0d;
  float endWord09;
  float fVar6;
  float startWord0e;
  float endWord0a;
  float startClipX;
  float endWord0f;
  float endClipZ;
  float fVar8;
  float endWord0e;
  float endClipX;
  float startClipY;
  float endClipY;
  float startClipZ;
  uint uVar12;
  uint clipOutcode;
  uint texEnableMask;
  int iVar14;
  uint uVar15;
  int iVar16;
  
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = *(float *)(startVertex + 0x24);
  startWord0a = *(float *)(startVertex + 0x28);
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = *(float *)(startVertex + 0x10);
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - fparam_3) + fparam_3);
  startClipY = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  fVar2 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar8 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar2;
  fVar3 = (edgeT * (endClipY - startClipY) + startClipY);
  outVertex[7] = fVar1;
  fVar4 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = fVar3;
  outVertex[6] = fVar4;
  if (fVar2 < fVar8) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar2) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar3 < fVar8) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar4 < fVar8) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar4) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar2 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar3 + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar4 + windowBiasZ;
  }
  uVar15 = 0;
  startWord0c = *(float *)(startVertex + 0x30);
  startWord0d = *(float *)(startVertex + 0x34);
  startWord0f = *(float *)(startVertex + 0x3c);
  endWord0c = *(float *)(endVertex + 0x30);
  endWord0d = *(float *)(endVertex + 0x34);
  startWord0e = *(float *)(startVertex + 0x38);
  endWord0f = *(float *)(endVertex + 0x3c);
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - *(float *)(startVertex + 0x4c)) + *(float *)(startVertex + 0x4c));
  endWord0e = *(float *)(endVertex + 0x38);
  outVertex[0xc] = (edgeT * (endWord0c - startWord0c) + startWord0c);
  outVertex[0xd] = (edgeT * (endWord0d - startWord0d) + startWord0d);
  outVertex[0xf] = (edgeT * (endWord0f - startWord0f) + startWord0f);
  outVertex[0xe] = (edgeT * (endWord0e - startWord0e) + startWord0e);
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    uVar12 = texEnableMask >> (uVar15 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        return;
      }
    }
    else {
      iVar14 = uVar15 * 0x10 + startVertex;
      iVar16 = uVar15 * 0x10 + endVertex;
      fVar1 = *(float *)(iVar14 + 0x8c);
      fVar2 = *(float *)(iVar14 + 0x84);
      fVar3 = *(float *)(iVar14 + 0x88);
      fVar4 = *(float *)(iVar16 + 0x8c);
      fVar5 = *(float *)(iVar16 + 0x84);
      fVar6 = *(float *)(iVar16 + 0x88);
      outVertex[uVar15 * 4 + 0x20] =
           (edgeT * (*(float *)(iVar16 + 0x80) - *(float *)(iVar14 + 0x80)) + *(float *)(iVar14 + 0x80));
      outVertex[uVar15 * 4 + 0x21] =
           (edgeT * (fVar5 - fVar2) + fVar2);
      outVertex[uVar15 * 4 + 0x22] =
           (edgeT * (fVar6 - fVar3) + fVar3);
      outVertex[uVar15 * 4 + 0x23] =
           (edgeT * (fVar4 - fVar1) + fVar1);
    }
    uVar15 = uVar15 + 1;
  } while( true );
}

/* _gleInterpolEyeNO1211 @ 0xb9454 (724 bytes) */
void _gleInterpolEyeNO1211(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord10;
  char cVar2;
  float fVar3;
  float startWord11;
  float windowScaleZ;
  float startWord0b;
  float fVar4;
  float endWord10;
  float windowBiasZ;
  float endWord0b;
  float fVar5;
  float endWord11;
  float startWord09;
  float startWord0a;
  float outInvW;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar10;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint uVar13;
  int iVar14;
  uint texEnableMask;
  uint clipOutcode;
  uint uVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  float dVar23;
  float dVar24;
  float dVar25;
  float dVar26;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar4 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar3 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar10 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar3;
  fVar4 = (edgeT * (endClipY - fVar4) + fVar4);
  outVertex[7] = fVar1;
  fVar5 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  cVar2 = *(char *)((int)startVertex + 0x7f);
  clipOutcode = 0;
  outVertex[5] = fVar4;
  outVertex[6] = fVar5;
  if (fVar3 < fVar10) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar4 < fVar10) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar4) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar5 < fVar10) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar5) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
      fVar5 = fVar5 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar3 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar4 + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar5 + windowBiasZ;
  }
  uVar17 = 0;
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13]);
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    uVar13 = texEnableMask >> (uVar17 & 0x3f);
    if ((uVar13 & 1) == 0) {
      if (uVar13 == 0) {
        startWord10 = startVertex[0x10];
        startWord11 = startVertex[0x11];
        endWord10 = *(float *)(endVertex + 0x40);
        endWord11 = *(float *)(endVertex + 0x44);
        outVertex[0x12] =
             (edgeT * (*(float *)(endVertex + 0x48) - startVertex[0x12]) + startVertex[0x12]);
        outVertex[0x10] =
             (edgeT * (endWord10 - startWord10) + startWord10);
        outVertex[0x11] =
             (edgeT * (endWord11 - startWord11) + startWord11);
        if (startVertex == outVertex) {
          return;
        }
        outVertex[0x1d] = startVertex[0x1d];
        outVertex[0x1e] = startVertex[0x1e];
        return;
      }
    }
    else {
      dVar26 = (double)startVertex[uVar17 * 4 + 0x23];
      dVar20 = (double)startVertex[uVar17 * 4 + 0x20];
      dVar21 = (double)startVertex[uVar17 * 4 + 0x21];
      dVar24 = (double)startVertex[uVar17 * 4 + 0x22];
      if (cVar2 == '\0') {
        dVar18 = (double)startVertex[7];
        dVar26 = (double)(dVar26 * dVar18);
        dVar20 = (double)(dVar20 * dVar18);
        dVar21 = (double)(dVar21 * dVar18);
        dVar24 = (double)(dVar24 * dVar18);
      }
      iVar14 = uVar17 * 0x10 + endVertex;
      dVar22 = (double)*(float *)(iVar14 + 0x8c);
      dVar23 = (double)*(float *)(iVar14 + 0x80);
      dVar18 = (double)*(float *)(iVar14 + 0x84);
      dVar25 = (double)*(float *)(iVar14 + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        dVar19 = (double)*(float *)(endVertex + 0x1c);
        dVar22 = (double)(dVar22 * dVar19);
        dVar23 = (double)(dVar23 * dVar19);
        dVar18 = (double)(dVar18 * dVar19);
        dVar25 = (double)(dVar25 * dVar19);
      }
      fVar1 = (edgeT * (dVar23 - dVar20) + dVar20);
      fVar3 = (edgeT * (dVar18 - dVar21) + dVar21);
      fVar4 = (edgeT * (dVar25 - dVar24) + dVar24);
      fVar5 = (edgeT * (dVar22 - dVar26) + dVar26);
      if (clipOutcode == 0) {
        outInvW = outVertex[3];
        fVar5 = fVar5 * outInvW;
        fVar1 = fVar1 * outInvW;
        fVar3 = fVar3 * outInvW;
        fVar4 = fVar4 * outInvW;
      }
      outVertex[uVar17 * 4 + 0x23] = fVar5;
      outVertex[uVar17 * 4 + 0x20] = fVar1;
      outVertex[uVar17 * 4 + 0x21] = fVar3;
      outVertex[uVar17 * 4 + 0x22] = fVar4;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

/* _gleInterpolEyeNO1211w @ 0xb9728 (636 bytes) */
void _gleInterpolEyeNO1211w(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startTexCoordQ;
  float startWord10;
  float fVar2;
  float startTexCoordT;
  float startWord11;
  float windowScaleZ;
  float startWord0b;
  float fVar3;
  float startTexCoordR;
  float endWord10;
  float windowBiasZ;
  float endWord0b;
  float fVar4;
  float endWord11;
  float startWord09;
  float fVar5;
  float startWord0a;
  float fVar6;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar9;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint uVar12;
  uint clipOutcode;
  uint texEnableMask;
  uint uVar14;
  int iVar15;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar3 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar2 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar9 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar2;
  fVar3 = (edgeT * (endClipY - fVar3) + fVar3);
  outVertex[7] = fVar1;
  fVar4 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  clipOutcode = 0;
  outVertex[5] = fVar3;
  outVertex[6] = fVar4;
  if (fVar2 < fVar9) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar2) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar3 < fVar9) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar4 < fVar9) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar4) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar2 = fVar2 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar2 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar3 + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar4 + windowBiasZ;
  }
  uVar14 = 0;
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13]);
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    uVar12 = texEnableMask >> (uVar14 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        startWord10 = startVertex[0x10];
        startWord11 = startVertex[0x11];
        endWord10 = *(float *)(endVertex + 0x40);
        endWord11 = *(float *)(endVertex + 0x44);
        outVertex[0x12] =
             (edgeT * (*(float *)(endVertex + 0x48) - startVertex[0x12]) + startVertex[0x12]);
        outVertex[0x10] =
             (edgeT * (endWord10 - startWord10) + startWord10);
        outVertex[0x11] =
             (edgeT * (endWord11 - startWord11) + startWord11);
        if (startVertex == outVertex) {
          return;
        }
        outVertex[0x1d] = startVertex[0x1d];
        outVertex[0x1e] = startVertex[0x1e];
        return;
      }
    }
    else {
      iVar15 = uVar14 * 0x10 + endVertex;
      startTexCoordQ = startVertex[uVar14 * 4 + 0x23];
      startTexCoordT = startVertex[uVar14 * 4 + 0x21];
      startTexCoordR = startVertex[uVar14 * 4 + 0x22];
      fVar4 = *(float *)(iVar15 + 0x8c);
      fVar5 = *(float *)(iVar15 + 0x84);
      fVar6 = *(float *)(iVar15 + 0x88);
      outVertex[uVar14 * 4 + 0x20] =
           (edgeT * (*(float *)(iVar15 + 0x80) - startVertex[uVar14 * 4 + 0x20]) + startVertex[uVar14 * 4 + 0x20]);
      outVertex[uVar14 * 4 + 0x21] =
           (edgeT * (fVar5 - startTexCoordT) + startTexCoordT);
      outVertex[uVar14 * 4 + 0x22] =
           (edgeT * (fVar6 - startTexCoordR) + startTexCoordR);
      outVertex[uVar14 * 4 + 0x23] =
           (edgeT * (fVar4 - startTexCoordQ) + startTexCoordQ);
    }
    uVar14 = uVar14 + 1;
  } while( true );
}

/* _gleInterpolEyeAllFlat @ 0xb99a4 (728 bytes) */
void _gleInterpolEyeAllFlat(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float fVar1;
  float startWord16;
  float startWord13;
  char cVar2;
  float fVar3;
  float windowBiasZ;
  float endWord0b;
  float fVar4;
  float startWord09;
  float startWord0a;
  float outInvW;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float fVar9;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint uVar12;
  int iVar13;
  float fVar14;
  float startWord1e;
  float endWord13;
  float windowScaleZ;
  float startWord0b;
  uint texEnableMask;
  uint clipOutcode;
  uint uVar17;
  float dVar18;
  float dVar19;
  float dVar20;
  float dVar21;
  float dVar22;
  float dVar23;
  float dVar24;
  float dVar25;
  float dVar26;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  fVar1 = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  fVar3 = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  fVar14 = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  fVar9 = -fVar1;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = fVar14;
  fVar3 = (edgeT * (endClipY - fVar3) + fVar3);
  outVertex[7] = fVar1;
  fVar4 = (edgeT * (endClipZ - startClipZ) + startClipZ);
  cVar2 = *(char *)((int)startVertex + 0x7f);
  outVertex[5] = fVar3;
  outVertex[6] = fVar4;
  if (fVar14 < fVar9) {
    clipOutcode = 0x10;
  }
  if (fVar1 <= fVar14) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (fVar3 < fVar9) {
    clipOutcode = clipOutcode | 4;
  }
  if (fVar1 <= fVar3) {
    clipOutcode = clipOutcode | 8;
  }
  if (fVar4 < fVar9) {
    clipOutcode = clipOutcode | 1;
  }
  if (fVar1 < fVar4) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (fVar1 != FLOAT_00108e54) {
      fVar1 = FLOAT_00108e54 / fVar1;
      fVar14 = fVar14 * fVar1;
      fVar3 = fVar3 * fVar1;
      fVar4 = fVar4 * fVar1;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * fVar14 + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * fVar3 + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = fVar1;
    outVertex[2] = windowScaleZ * fVar4 + windowBiasZ;
  }
  startWord13 = startVertex[0x13];
  uVar17 = 0;
  endWord13 = *(float *)(endVertex + 0x4c);
  outVertex[0x17] =
       (edgeT * (*(float *)(endVertex + 0x5c) - startVertex[0x17]) + startVertex[0x17]);
  outVertex[0x13] =
       (edgeT * (endWord13 - startWord13) + startWord13);
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    uVar12 = texEnableMask >> (uVar17 & 0x3f);
    if ((uVar12 & 1) == 0) {
      if (uVar12 == 0) {
        if (startVertex == outVertex) {
          return;
        }
        *(undefined8 *)(outVertex + 0xc) = *(undefined8 *)(startVertex + 0xc);
        *(undefined8 *)(outVertex + 0xe) = *(undefined8 *)(startVertex + 0xe);
        *(undefined8 *)(outVertex + 0x10) = *(undefined8 *)(startVertex + 0x10);
        outVertex[0x12] = startVertex[0x12];
        *(undefined8 *)(outVertex + 0x14) = *(undefined8 *)(startVertex + 0x14);
        startWord16 = startVertex[0x16];
        outVertex[0x1d] = startVertex[0x1d];
        startWord1e = startVertex[0x1e];
        outVertex[0x16] = startWord16;
        outVertex[0x1e] = startWord1e;
        return;
      }
    }
    else {
      dVar26 = (double)startVertex[uVar17 * 4 + 0x23];
      dVar20 = (double)startVertex[uVar17 * 4 + 0x20];
      dVar21 = (double)startVertex[uVar17 * 4 + 0x21];
      dVar22 = (double)startVertex[uVar17 * 4 + 0x22];
      if (cVar2 == '\0') {
        dVar18 = (double)startVertex[7];
        dVar26 = (double)(dVar26 * dVar18);
        dVar20 = (double)(dVar20 * dVar18);
        dVar21 = (double)(dVar21 * dVar18);
        dVar22 = (double)(dVar22 * dVar18);
      }
      iVar13 = uVar17 * 0x10 + endVertex;
      dVar23 = (double)*(float *)(iVar13 + 0x8c);
      dVar18 = (double)*(float *)(iVar13 + 0x80);
      dVar25 = (double)*(float *)(iVar13 + 0x84);
      dVar24 = (double)*(float *)(iVar13 + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        dVar19 = (double)*(float *)(endVertex + 0x1c);
        dVar23 = (double)(dVar23 * dVar19);
        dVar18 = (double)(dVar18 * dVar19);
        dVar25 = (double)(dVar25 * dVar19);
        dVar24 = (double)(dVar24 * dVar19);
      }
      fVar1 = (edgeT * (dVar18 - dVar20) + dVar20);
      fVar14 = (edgeT * (dVar25 - dVar21) + dVar21);
      fVar3 = (edgeT * (dVar24 - dVar22) + dVar22);
      fVar4 = (edgeT * (dVar23 - dVar26) + dVar26);
      if (clipOutcode == 0) {
        outInvW = outVertex[3];
        fVar4 = fVar4 * outInvW;
        fVar1 = fVar1 * outInvW;
        fVar14 = fVar14 * outInvW;
        fVar3 = fVar3 * outInvW;
      }
      outVertex[uVar17 * 4 + 0x23] = fVar4;
      outVertex[uVar17 * 4 + 0x20] = fVar1;
      outVertex[uVar17 * 4 + 0x21] = fVar14;
      outVertex[uVar17 * 4 + 0x22] = fVar3;
    }
    uVar17 = uVar17 + 1;
  } while( true );
}

