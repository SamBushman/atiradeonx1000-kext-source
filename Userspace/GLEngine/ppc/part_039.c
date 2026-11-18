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
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  _glCombinerParameterivNV_Comp(glContext,pname,params);
  ((void (*)())_glCombinerParameterivNV_Exec)(glContext,pname,params,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
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
  double incomingFpr2;
  double incomingFpr3;
  double incomingFpr4;
  double incomingFpr5;
  double incomingFpr6;
  double incomingFpr7;
  double incomingFpr8;
  
  _glCombinerParameteriNV_Comp(glContext,pname,param);
  ((void (*)())_glCombinerParameteriNV_Exec)(glContext,pname,param,fparam_1,incomingFpr2,incomingFpr3,incomingFpr4,incomingFpr5,incomingFpr6,incomingFpr7,incomingFpr8,
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
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  
  ((void (*)())_glCombinerParameterivNV_Exec)(glContext,*listRecord,listRecord + 1,forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,
             forwardedFloatArg7,forwardedFloatArg8,incomingStack_ffffffb8,incomingStack_ffffffc0);
  return 0x14;
}

/* _glCombinerParameteriNV_ListExec @ 0xb45ec (44 bytes) */
undefined4 _glCombinerParameteriNV_ListExec(undefined4 glContext,undefined4 *listRecord,double forwardedFloatArg1,double forwardedFloatArg2,double forwardedFloatArg3,double forwardedFloatArg4,double forwardedFloatArg5,double forwardedFloatArg6,double forwardedFloatArg7,double forwardedFloatArg8,double unusedFloatArg9,double unusedFloatArg10)
{
  double incomingStack_ffffffb8;
  double incomingStack_ffffffc0;
  
  ((void (*)())_glCombinerParameteriNV_Exec)(glContext,*listRecord,listRecord[1],forwardedFloatArg1,forwardedFloatArg2,forwardedFloatArg3,forwardedFloatArg4,forwardedFloatArg5,forwardedFloatArg6,
             forwardedFloatArg7,forwardedFloatArg8,incomingStack_ffffffb8,incomingStack_ffffffc0);
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
int _glCombinerOutputNV_ListExec(forwardedArg1, listRecord)
  undefined4 forwardedArg1;
  undefined4 *listRecord;
{
  _glCombinerOutputNV_Exec
            (forwardedArg1,*listRecord,listRecord[1],listRecord[2],listRecord[3],listRecord[4],listRecord[5],listRecord[6],
             (uint)*(byte *)((int)listRecord + 0x1f),(uint)*(byte *)((int)listRecord + 0x23),
             (uint)*(byte *)((int)listRecord + 0x27));
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
void _gleVPSetFuncOutputDesc(outputRecords, outputCount, funcDesc, extraOutput)
  int outputRecords;
  uint outputCount;
  uint *funcDesc;
  int extraOutput;
{
  uint descHeaderThenOutputRecord;
  int streamWordIndex;
  uint streamCount;
  int trailingIndex;
  uint recordKindThenRecordBit0;
  int recordIndexThenLeadingIndex;
  int loopIndex;
  int streamType;
  int leadingIndexNext;
  
  descHeaderThenOutputRecord = (outputCount & 0x3f) << 10 | 0x200000;
  *funcDesc = descHeaderThenOutputRecord;
  streamCount = outputCount;
  if (extraOutput != 0) {
    streamCount = outputCount + 1;
  }
  recordIndexThenLeadingIndex = 0;
  *funcDesc = descHeaderThenOutputRecord | streamCount << 0x18;
  trailingIndex = 0;
  descHeaderThenOutputRecord = outputCount;
  if (0 < (int)outputCount) {
    do {
      recordKindThenRecordBit0 = *(uint *)(recordIndexThenLeadingIndex * 8 + outputRecords);
      if (((recordKindThenRecordBit0 >> 0x10 & 0xf) == 1) || ((recordKindThenRecordBit0 & 0xf001f) == 0x90000)) {
        trailingIndex = trailingIndex + 1;
      }
      recordIndexThenLeadingIndex = recordIndexThenLeadingIndex + 1;
      descHeaderThenOutputRecord = descHeaderThenOutputRecord - 1;
    } while (descHeaderThenOutputRecord != 0);
  }
  loopIndex = 0;
  recordIndexThenLeadingIndex = 0;
  if (0 < (int)outputCount) {
    do {
      descHeaderThenOutputRecord = *(uint *)(loopIndex * 8 + outputRecords);
      switch(descHeaderThenOutputRecord >> 0x10 & 0xf) {
      default:
        streamType = 0x2e;
        break;
      case 1:
        streamType = 0;
LAB_000b4b78:
        leadingIndexNext = recordIndexThenLeadingIndex + 1;
        streamWordIndex = recordIndexThenLeadingIndex;
        goto LAB_000b4c00;
      case 2:
        streamType = 2;
        break;
      case 3:
        streamType = 4;
        break;
      case 4:
        streamType = 1;
        break;
      case 5:
        streamType = 3;
        break;
      case 6:
        streamType = 5;
        break;
      case 7:
        streamType = (descHeaderThenOutputRecord & 0x1f) + 8;
        break;
      case 9:
        streamType = (descHeaderThenOutputRecord & 0x1f) + 0x10;
        if ((descHeaderThenOutputRecord & 0x1f) == 0) goto LAB_000b4b78;
        break;
      case 10:
        streamType = 0x2e;
        recordKindThenRecordBit0 = descHeaderThenOutputRecord & 1;
        switch(descHeaderThenOutputRecord >> 0xc & 0xf) {
        case 0:
          streamType = recordKindThenRecordBit0 + 0x20;
          break;
        case 1:
          streamType = recordKindThenRecordBit0 + 0x22;
          break;
        case 2:
          streamType = recordKindThenRecordBit0 + 0x24;
          break;
        case 3:
          streamType = recordKindThenRecordBit0 + 0x26;
          break;
        case 4:
          streamType = recordKindThenRecordBit0 + 0x28;
        }
      }
      streamWordIndex = trailingIndex;
      trailingIndex = trailingIndex + 1;
      leadingIndexNext = recordIndexThenLeadingIndex;
LAB_000b4c00:
      recordIndexThenLeadingIndex = loopIndex << 4;
      loopIndex = loopIndex + 1;
      *(ushort *)((int)funcDesc + streamWordIndex * 2 + 4) =
           (ushort)(streamType << 10) | (ushort)(recordIndexThenLeadingIndex >> 2) | 0x300;
      recordIndexThenLeadingIndex = leadingIndexNext;
    } while (loopIndex < (int)outputCount);
  }
  if ((int)outputCount < (int)streamCount) {
    *(ushort *)((int)funcDesc + trailingIndex * 2 + 4) = (ushort)((loopIndex << 4) >> 2) | 0x1b00;
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
void _gleSetFunctionIDFromList(glContext, streamSizes, funcDesc)
  int glContext;
  int streamSizes;
  uint *funcDesc;
{
  byte slotSize;
  uint streamCount;
  uint headerWithOutputs;
  uint streamSlot;
  int runningSize;
  ushort *dstCursor;
  byte *srcCursor;
  ushort streamWord;
  ushort slotOffset;
  int *offsetCursor;
  uint componentCount;
  int arrayDefaults;
  int streamType;
  int remaining;
  int slotOffsets [31];
  int local_14;
  
  streamCount = *funcDesc;
  arrayDefaults = *(int *)(glContext + 0x4674);
  offsetCursor = slotOffsets + 1;
  headerWithOutputs = streamCount | 0x70000;
  *funcDesc = headerWithOutputs;
  slotOffsets[1] = 0;
  *funcDesc = headerWithOutputs | *(uint *)(streamSizes + 8) >> 2 & 0xff;
  streamCount = streamCount >> 0x18;
  srcCursor = (byte *)(streamSizes + 0xd);
  remaining = 0x1e;
  do {
    slotSize = *srcCursor;
    srcCursor = srcCursor + 1;
    runningSize = *offsetCursor;
    offsetCursor = offsetCursor + 1;
    *offsetCursor = runningSize + (uint)slotSize;
    remaining = remaining + -1;
  } while (remaining != 0);
  slotOffsets[0] = local_14 + (uint)*(byte *)(streamSizes + 0x2b);
  if (streamCount == 0) {
    return;
  }
  dstCursor = (ushort *)((int)funcDesc + streamCount * 2 + 4);
  do {
    streamWord = *(ushort *)(funcDesc + 1);
    streamType = 0xe;
    streamSlot = (uint)(streamWord >> 10);
    if ((streamSlot == 0) || (streamSlot == 0x10)) {
      componentCount = (uint)*(byte *)(streamSizes + streamSlot + 0xc);
      if (componentCount == 0) {
        if (*(byte *)(streamSizes + 0xc) == 0) {
          if (*(byte *)(streamSizes + 0x1c) == 0) goto LAB_000b4e5c;
          componentCount = (int)(uint)*(byte *)(streamSizes + 0x1c) >> 2;
          streamSlot = 0x10;
          *(ushort *)(funcDesc + 1) = streamWord & 0x3ff | 0x4000;
        }
        else {
          componentCount = (int)(uint)*(byte *)(streamSizes + 0xc) >> 2;
          *(ushort *)(funcDesc + 1) = streamWord & 0x3ff;
          streamSlot = 0;
        }
      }
      else {
        componentCount = (int)componentCount >> 2;
      }
      streamType = 6;
LAB_000b4e60:
      slotOffset = (ushort)slotOffsets[streamSlot];
    }
    else {
      if (((streamSlot - 1 < 6) || (streamSlot - 8 < 8)) || (streamSlot - 0x11 < 0xf)) {
        componentCount = (uint)*(byte *)(streamSizes + streamSlot + 0xc);
        if (componentCount == 0) {
LAB_000b4e5c:
          componentCount = (uint)*(byte *)(arrayDefaults + 0x400 + streamSlot);
        }
        else {
          componentCount = (int)componentCount >> 2;
          streamType = 5 - ((int)-(streamSlot ^ 6) >> 0x1f);
        }
        goto LAB_000b4e60;
      }
      componentCount = (uint)(7 < streamSlot - 0x20);
      slotOffset = 0;
    }
    funcDesc = (uint *)((int)funcDesc + 2);
    *dstCursor = (short)(componentCount - 1) * 0x4000 | (ushort)(streamType << 10) | slotOffset;
    dstCursor = dstCursor + 1;
    streamCount = streamCount - 1;
    if (streamCount == 0) {
      return;
    }
  } while( true );
}

/* _gleSetFunctionIDToList @ 0xb4eac (508 bytes) */
void _gleSetFunctionIDToList(glContext, param_2, param_3)
  int glContext;
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
  iVar12 = *(int *)(glContext + 0x48dc);
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
int _gleRTCAddAChunk_b50a8(srcCursor, dstCursor)
  int *srcCursor;
  int *dstCursor;
{
  int word;
  int copiedWords;
  
  copiedWords = 0;
  word = *srcCursor;
  while (word != 0) {
    *dstCursor = word;
    copiedWords = copiedWords + 1;
    srcCursor = srcCursor + 1;
    dstCursor = dstCursor + 1;
    word = *srcCursor;
  }
  return copiedWords;
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
void _gleSetVertexEval1Func(glContext, forwardedArg2, forwardedArg3)
  int glContext;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
{
  undefined4 *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = (undefined4 *)(*_gleBuildVertexFunc)(glContext,2,forwardedArg3);
  UNRECOVERED_JUMPTABLE = (code *)*puVar1;
  *(code **)(glContext + 0x4898) = UNRECOVERED_JUMPTABLE;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(glContext,forwardedArg2,forwardedArg3);
  return;
}

/* _gleSetVertexEval2Func @ 0xb51a4 (100 bytes) */
void _gleSetVertexEval2Func(glContext, forwardedArg2, forwardedArg3)
  int glContext;
  undefined4 forwardedArg2;
  undefined4 forwardedArg3;
{
  undefined4 *puVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  puVar1 = (undefined4 *)(*_gleBuildVertexFunc)(glContext,2,forwardedArg3);
  UNRECOVERED_JUMPTABLE = (code *)*puVar1;
  *(code **)(glContext + 0x489c) = UNRECOVERED_JUMPTABLE;
                    
                    
  (*UNRECOVERED_JUMPTABLE)(glContext,forwardedArg2,forwardedArg3);
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
int _gleLoadDataElementFromMatNO(instrCursor, componentCount, doubleFlag, sourceOffset, baseRegisterSelect)
  uint *instrCursor;
  int componentCount;
  int doubleFlag;
  uint sourceOffset;
  int baseRegisterSelect;
{
  uint instrWord;
  
  if (doubleFlag == 4) {
    if (componentCount == 1) {
      instrWord = (baseRegisterSelect + 0xb) * 0x10000 | sourceOffset & 0xffff | 0xc0200000;
    }
    else {
      if (componentCount < 2) {
        return instrCursor;
      }
      instrWord = (baseRegisterSelect + 0xb) * 0x10000;
      *instrCursor = instrWord | sourceOffset & 0xffff | 0xc8200000;
      instrCursor = instrCursor + 1;
      if (componentCount == 3) {
        instrWord = instrWord | sourceOffset + 8 & 0xffff | 0xc0600000;
      }
      else {
        if (componentCount != 4) {
          return instrCursor;
        }
        instrWord = instrWord | sourceOffset + 8 & 0xffff | 0xc8600000;
      }
    }
  }
  else {
    instrWord = (baseRegisterSelect + 0xb) * 0x10000;
    *instrCursor = instrWord | sourceOffset & 0xffff | 0xc0200000;
    if (componentCount < 2) {
      return instrCursor + 1;
    }
    instrCursor[1] = instrWord | sourceOffset + 4 & 0xffff | 0xc0400000;
    if (componentCount < 3) {
      return instrCursor + 2;
    }
    instrCursor[2] = instrWord | sourceOffset + 8 & 0xffff | 0xc0600000;
    instrCursor = instrCursor + 3;
    if (componentCount != 4) {
      return instrCursor;
    }
    instrWord = instrWord | sourceOffset + 0xc & 0xffff | 0xc0800000;
  }
  *instrCursor = instrWord;
  return instrCursor + 1;
}

/* _gleInterpolEyeNO0000 @ 0xb5390 (448 bytes) */
void _gleInterpolEyeNO0000(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float startWord12;
  float clipYThenNdcY;
  float windowScaleZ;
  float endWord0b;
  float clipZThenNdcZ;
  float startWord09;
  float startWord0a;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float endClipY;
  float startClipZ;
  float clipXThenNdcX;
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
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
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
  float clipWThenInvW;
  float startWord12;
  float clipYThenNdcY;
  float windowScaleZ;
  float endWord0b;
  float clipZThenNdcZ;
  float startWord09;
  float startWord0a;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float endClipY;
  float startClipZ;
  float clipXThenNdcX;
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
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
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
  float clipWThenInvW;
  float outTexCoordS;
  float startWord12;
  char startFlagByte7f;
  float clipYThenNdcY;
  float outTexCoordQ;
  float windowScaleZ;
  float endWord0b;
  float clipZThenNdcZ;
  float outTexCoordR;
  float startWord09;
  float startWord0a;
  float outInvW;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float endClipY;
  float startClipZ;
  float clipXThenNdcX;
  float outTexCoordT;
  float startWord1e;
  float windowBiasZ;
  float startWord0b;
  uint clipOutcode;
  float startClipW;
  float endTexCoordS;
  float endClipW;
  float startTexCoordS;
  float startTexCoordR;
  float startTexCoordT;
  float endTexCoordR;
  float endTexCoordQ;
  float endTexCoordT;
  float startTexCoordQ;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  startFlagByte7f = *(char *)((int)startVertex + 0x7f);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  startTexCoordS = (double)startVertex[0x20];
  startTexCoordT = (double)startVertex[0x21];
  startTexCoordR = (double)startVertex[0x22];
  startTexCoordQ = (double)startVertex[0x23];
  if (startFlagByte7f == '\0') {
    startClipW = (double)startVertex[7];
    startTexCoordQ = (double)(startTexCoordQ * startClipW);
    startTexCoordS = (double)(startTexCoordS * startClipW);
    startTexCoordT = (double)(startTexCoordT * startClipW);
    startTexCoordR = (double)(startTexCoordR * startClipW);
  }
  endTexCoordS = (double)*(float *)(endVertex + 0x80);
  endTexCoordT = (double)*(float *)(endVertex + 0x84);
  endTexCoordR = (double)*(float *)(endVertex + 0x88);
  endTexCoordQ = (double)*(float *)(endVertex + 0x8c);
  if (*(char *)(endVertex + 0x7f) == '\0') {
    endClipW = (double)*(float *)(endVertex + 0x1c);
    endTexCoordQ = (double)(endTexCoordQ * endClipW);
    endTexCoordS = (double)(endTexCoordS * endClipW);
    endTexCoordT = (double)(endTexCoordT * endClipW);
    endTexCoordR = (double)(endTexCoordR * endClipW);
  }
  outTexCoordS = (edgeT * (endTexCoordS - startTexCoordS) + startTexCoordS);
  outTexCoordT = (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
  outTexCoordQ = (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
  outTexCoordR = (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
  if (clipOutcode == 0) {
    outInvW = outVertex[3];
    outTexCoordQ = outTexCoordQ * outInvW;
    outTexCoordS = outTexCoordS * outInvW;
    outTexCoordT = outTexCoordT * outInvW;
    outTexCoordR = outTexCoordR * outInvW;
  }
  outVertex[0x20] = outTexCoordS;
  outVertex[0x21] = outTexCoordT;
  outVertex[0x22] = outTexCoordR;
  outVertex[0x23] = outTexCoordQ;
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
  float clipWThenInvW;
  float startWord12;
  float startWord21;
  float clipYThenNdcY;
  float startWord23;
  float windowScaleZ;
  float endWord0b;
  float clipZThenNdcZ;
  float endWord23;
  float startWord09;
  float startWord0a;
  float endWord21;
  float endWord09;
  float endWord22;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float endClipY;
  float startClipZ;
  float clipXThenNdcX;
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
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
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
  float clipWThenInvW;
  float outTexCoordS;
  float startWord12;
  char startFlagByte7f;
  float clipYThenNdcY;
  float outTexCoordQ;
  float windowScaleZ;
  float endWord0b;
  float clipZThenNdcZ;
  float outTexCoordR;
  float startWord09;
  float startWord0a;
  float outInvW;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float endClipY;
  float startClipZ;
  float clipXThenNdcX;
  float outTexCoordT;
  float startWord1e;
  float windowBiasZ;
  float startWord0b;
  uint clipOutcode;
  float startClipW;
  float endTexCoordS;
  float endClipW;
  float startTexCoordS;
  float startTexCoordT;
  float startTexCoordR;
  float endTexCoordQ;
  float endTexCoordT;
  float endTexCoordR;
  float startTexCoordQ;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  startFlagByte7f = *(char *)((int)startVertex + 0x7f);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13]);
  startTexCoordS = (double)startVertex[0x20];
  startTexCoordT = (double)startVertex[0x21];
  startTexCoordR = (double)startVertex[0x22];
  startTexCoordQ = (double)startVertex[0x23];
  if (startFlagByte7f == '\0') {
    startClipW = (double)startVertex[7];
    startTexCoordQ = (double)(startTexCoordQ * startClipW);
    startTexCoordS = (double)(startTexCoordS * startClipW);
    startTexCoordT = (double)(startTexCoordT * startClipW);
    startTexCoordR = (double)(startTexCoordR * startClipW);
  }
  endTexCoordS = (double)*(float *)(endVertex + 0x80);
  endTexCoordT = (double)*(float *)(endVertex + 0x84);
  endTexCoordR = (double)*(float *)(endVertex + 0x88);
  endTexCoordQ = (double)*(float *)(endVertex + 0x8c);
  if (*(char *)(endVertex + 0x7f) == '\0') {
    endClipW = (double)*(float *)(endVertex + 0x1c);
    endTexCoordQ = (double)(endTexCoordQ * endClipW);
    endTexCoordS = (double)(endTexCoordS * endClipW);
    endTexCoordT = (double)(endTexCoordT * endClipW);
    endTexCoordR = (double)(endTexCoordR * endClipW);
  }
  outTexCoordS = (edgeT * (endTexCoordS - startTexCoordS) + startTexCoordS);
  outTexCoordT = (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
  outTexCoordQ = (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
  outTexCoordR = (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
  if (clipOutcode == 0) {
    outInvW = outVertex[3];
    outTexCoordQ = outTexCoordQ * outInvW;
    outTexCoordS = outTexCoordS * outInvW;
    outTexCoordT = outTexCoordT * outInvW;
    outTexCoordR = outTexCoordR * outInvW;
  }
  outVertex[0x20] = outTexCoordS;
  outVertex[0x21] = outTexCoordT;
  outVertex[0x22] = outTexCoordR;
  outVertex[0x23] = outTexCoordQ;
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
  float clipWThenInvW;
  float startWord12;
  float startWord21;
  float clipYThenNdcY;
  float startWord23;
  float windowScaleZ;
  float endWord0b;
  float clipZThenNdcZ;
  float endWord23;
  float startWord09;
  float startWord0a;
  float endWord21;
  float endWord09;
  float endWord22;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float endClipY;
  float startClipZ;
  float clipXThenNdcX;
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
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
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
  float clipWThenInvW;
  float outTexCoordS;
  float startWord12;
  char startFlagByte7f;
  float clipYThenNdcY;
  float outTexCoordR;
  float windowBiasZ;
  float endWord0b;
  float clipZThenNdcZ;
  float outTexCoordQ;
  float startWord09;
  float startWord0a;
  float outInvW;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint texMaskRemaining;
  int endVertexAtUnit;
  float clipXThenNdcX;
  float outTexCoordT;
  float startWord1e;
  float windowScaleZ;
  float startWord0b;
  uint texEnableMask;
  uint clipOutcode;
  uint texUnit;
  float startClipW;
  float endTexCoordS;
  float endClipW;
  float startTexCoordS;
  float startTexCoordT;
  float startTexCoordR;
  float endTexCoordQ;
  float endTexCoordR;
  float endTexCoordT;
  float startTexCoordQ;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  startFlagByte7f = *(char *)((int)startVertex + 0x7f);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texEnableMask = *(uint *)(glContext + 0x5150);
  texUnit = 0;
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
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
      startTexCoordQ = (double)startVertex[texUnit * 4 + 0x23];
      startTexCoordS = (double)startVertex[texUnit * 4 + 0x20];
      startTexCoordT = (double)startVertex[texUnit * 4 + 0x21];
      startTexCoordR = (double)startVertex[texUnit * 4 + 0x22];
      if (startFlagByte7f == '\0') {
        startClipW = (double)startVertex[7];
        startTexCoordQ = (double)(startTexCoordQ * startClipW);
        startTexCoordS = (double)(startTexCoordS * startClipW);
        startTexCoordT = (double)(startTexCoordT * startClipW);
        startTexCoordR = (double)(startTexCoordR * startClipW);
      }
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      endTexCoordQ = (double)*(float *)(endVertexAtUnit + 0x8c);
      endTexCoordS = (double)*(float *)(endVertexAtUnit + 0x80);
      endTexCoordT = (double)*(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = (double)*(float *)(endVertexAtUnit + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        endClipW = (double)*(float *)(endVertex + 0x1c);
        endTexCoordQ = (double)(endTexCoordQ * endClipW);
        endTexCoordS = (double)(endTexCoordS * endClipW);
        endTexCoordT = (double)(endTexCoordT * endClipW);
        endTexCoordR = (double)(endTexCoordR * endClipW);
      }
      outTexCoordS = (edgeT * (endTexCoordS - startTexCoordS) + startTexCoordS);
      outTexCoordT = (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
      outTexCoordR = (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
      outTexCoordQ = (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
      if (clipOutcode == 0) {
        outInvW = outVertex[3];
        outTexCoordQ = outTexCoordQ * outInvW;
        outTexCoordS = outTexCoordS * outInvW;
        outTexCoordT = outTexCoordT * outInvW;
        outTexCoordR = outTexCoordR * outInvW;
      }
      outVertex[texUnit * 4 + 0x23] = outTexCoordQ;
      outVertex[texUnit * 4 + 0x20] = outTexCoordS;
      outVertex[texUnit * 4 + 0x21] = outTexCoordT;
      outVertex[texUnit * 4 + 0x22] = outTexCoordR;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolEyeNO0200w @ 0xb62dc (584 bytes) */
void _gleInterpolEyeNO0200w(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float startTexCoordQ;
  float startWord12;
  float clipYThenNdcY;
  float startTexCoordR;
  float windowBiasZ;
  float endWord0b;
  float clipZThenNdcZ;
  float endTexCoordQ;
  float startWord09;
  float endTexCoordT;
  float startWord0a;
  float endTexCoordR;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint texMaskRemaining;
  float clipXThenNdcX;
  float startTexCoordT;
  float startWord1e;
  float windowScaleZ;
  float startWord0b;
  uint clipOutcode;
  uint texEnableMask;
  uint texUnit;
  int endVertexAtUnit;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texEnableMask = *(uint *)(glContext + 0x5150);
  texUnit = 0;
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
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
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      startTexCoordQ = startVertex[texUnit * 4 + 0x23];
      startTexCoordT = startVertex[texUnit * 4 + 0x21];
      startTexCoordR = startVertex[texUnit * 4 + 0x22];
      endTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      outVertex[texUnit * 4 + 0x20] =
           (edgeT * (*(float *)(endVertexAtUnit + 0x80) - startVertex[texUnit * 4 + 0x20]) + startVertex[texUnit * 4 + 0x20]);
      outVertex[texUnit * 4 + 0x21] =
           (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
      outVertex[texUnit * 4 + 0x22] =
           (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
      outVertex[texUnit * 4 + 0x23] =
           (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolEyeNO0210 @ 0xb6524 (692 bytes) */
void _gleInterpolEyeNO0210(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float outTexCoordS;
  float startWord12;
  char startFlagByte7f;
  float clipYThenNdcY;
  float outTexCoordR;
  float windowBiasZ;
  float endWord0b;
  float clipZThenNdcZ;
  float outTexCoordQ;
  float startWord09;
  float startWord0a;
  float outInvW;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint texMaskRemaining;
  int endVertexAtUnit;
  float clipXThenNdcX;
  float outTexCoordT;
  float startWord1e;
  float windowScaleZ;
  float startWord0b;
  uint texEnableMask;
  uint clipOutcode;
  uint texUnit;
  float startClipW;
  float endTexCoordS;
  float endClipW;
  float startTexCoordS;
  float startTexCoordT;
  float startTexCoordR;
  float endTexCoordQ;
  float endTexCoordT;
  float endTexCoordR;
  float startTexCoordQ;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  startFlagByte7f = *(char *)((int)startVertex + 0x7f);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13]);
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
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
      startTexCoordQ = (double)startVertex[texUnit * 4 + 0x23];
      startTexCoordS = (double)startVertex[texUnit * 4 + 0x20];
      startTexCoordT = (double)startVertex[texUnit * 4 + 0x21];
      startTexCoordR = (double)startVertex[texUnit * 4 + 0x22];
      if (startFlagByte7f == '\0') {
        startClipW = (double)startVertex[7];
        startTexCoordQ = (double)(startTexCoordQ * startClipW);
        startTexCoordS = (double)(startTexCoordS * startClipW);
        startTexCoordT = (double)(startTexCoordT * startClipW);
        startTexCoordR = (double)(startTexCoordR * startClipW);
      }
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      endTexCoordQ = (double)*(float *)(endVertexAtUnit + 0x8c);
      endTexCoordS = (double)*(float *)(endVertexAtUnit + 0x80);
      endTexCoordT = (double)*(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = (double)*(float *)(endVertexAtUnit + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        endClipW = (double)*(float *)(endVertex + 0x1c);
        endTexCoordQ = (double)(endTexCoordQ * endClipW);
        endTexCoordS = (double)(endTexCoordS * endClipW);
        endTexCoordT = (double)(endTexCoordT * endClipW);
        endTexCoordR = (double)(endTexCoordR * endClipW);
      }
      outTexCoordS = (edgeT * (endTexCoordS - startTexCoordS) + startTexCoordS);
      outTexCoordT = (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
      outTexCoordR = (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
      outTexCoordQ = (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
      if (clipOutcode == 0) {
        outInvW = outVertex[3];
        outTexCoordQ = outTexCoordQ * outInvW;
        outTexCoordS = outTexCoordS * outInvW;
        outTexCoordT = outTexCoordT * outInvW;
        outTexCoordR = outTexCoordR * outInvW;
      }
      outVertex[texUnit * 4 + 0x23] = outTexCoordQ;
      outVertex[texUnit * 4 + 0x20] = outTexCoordS;
      outVertex[texUnit * 4 + 0x21] = outTexCoordT;
      outVertex[texUnit * 4 + 0x22] = outTexCoordR;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolEyeNO0210w @ 0xb67d8 (604 bytes) */
void _gleInterpolEyeNO0210w(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float startTexCoordQ;
  float startWord12;
  float clipYThenNdcY;
  float startTexCoordR;
  float windowBiasZ;
  float endWord0b;
  float clipZThenNdcZ;
  float endTexCoordQ;
  float startWord09;
  float endTexCoordT;
  float startWord0a;
  float endTexCoordR;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint texMaskRemaining;
  float clipXThenNdcX;
  float startTexCoordT;
  float startWord1e;
  float windowScaleZ;
  float startWord0b;
  uint clipOutcode;
  uint texEnableMask;
  uint texUnit;
  int endVertexAtUnit;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13]);
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
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
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      startTexCoordQ = startVertex[texUnit * 4 + 0x23];
      startTexCoordT = startVertex[texUnit * 4 + 0x21];
      startTexCoordR = startVertex[texUnit * 4 + 0x22];
      endTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      outVertex[texUnit * 4 + 0x20] =
           (edgeT * (*(float *)(endVertexAtUnit + 0x80) - startVertex[texUnit * 4 + 0x20]) + startVertex[texUnit * 4 + 0x20]);
      outVertex[texUnit * 4 + 0x21] =
           (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
      outVertex[texUnit * 4 + 0x22] =
           (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
      outVertex[texUnit * 4 + 0x23] =
           (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolEyeNO1000 @ 0xb6a34 (476 bytes) */
void _gleInterpolEyeNO1000(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float startWord0f;
  float clipXThenNdcX;
  float startWord0d;
  float windowBiasZ;
  float startWord0b;
  float clipYThenNdcY;
  float startWord0e;
  float windowScaleZ;
  float endWord0b;
  float clipZThenNdcZ;
  float endWord0f;
  float startWord09;
  float endWord09;
  float endWord0d;
  float startWord0a;
  float endWord0e;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
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
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  clipOutcode = 0;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
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
  float clipWThenInvW;
  float startWord10;
  float clipXThenNdcX;
  float startWord11;
  float windowBiasZ;
  float startWord0b;
  float clipYThenNdcY;
  float endWord10;
  float windowScaleZ;
  float endWord0b;
  float clipZThenNdcZ;
  float endWord11;
  float startWord0a;
  float endWord09;
  float startWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
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
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  clipOutcode = 0;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
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
  float clipWThenInvW;
  float startWord0f;
  float clipXThenNdcX;
  float startWord0c;
  float windowBiasZ;
  float startWord0b;
  float clipYThenNdcY;
  float startWord0d;
  float windowScaleZ;
  float endWord0b;
  float clipZThenNdcZ;
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
  float negClipW;
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
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  clipOutcode = 0;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
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
  float clipWThenInvW;
  float startWord10;
  float clipXThenNdcX;
  float startWord11;
  float windowBiasZ;
  float startWord0b;
  float clipYThenNdcY;
  float endWord10;
  float windowScaleZ;
  float endWord0b;
  float clipZThenNdcZ;
  float endWord11;
  float startWord09;
  float startWord0a;
  float startWord12;
  float endWord09;
  float endWord12;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
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
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  clipOutcode = 0;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
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
void _gleInterpolEyeNO1100_body(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,float incomingFpr6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float outTexCoordS;
  float startWord0d;
  char startFlagByte7f;
  float clipXThenNdcX;
  float outTexCoordT;
  float startWord0e;
  float windowBiasZ;
  float endWord0b;
  float clipYThenNdcY;
  float outTexCoordQ;
  float startWord0f;
  float windowScaleZ;
  float startWord09;
  float clipZThenNdcZ;
  float outTexCoordR;
  float endWord0d;
  float startWord0a;
  float endWord09;
  float outInvW;
  float endWord0e;
  float endWord0a;
  float endWord0f;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float startClipY;
  float endClipY;
  float startClipZ;
  uint clipOutcode;
  float startClipW;
  float endTexCoordS;
  float endClipW;
  float startTexCoordS;
  float startTexCoordR;
  float startTexCoordT;
  float startTexCoordQ;
  float endTexCoordR;
  float endTexCoordT;
  float endTexCoordQ;
  
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = *(float *)(startVertex + 0x24);
  startWord0a = *(float *)(startVertex + 0x28);
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = *(float *)(startVertex + 0x10);
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - incomingFpr6) + incomingFpr6);
  startClipY = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - startClipY) + startClipY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  startFlagByte7f = *(char *)(startVertex + 0x7f);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
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
  startTexCoordS = (double)*(float *)(startVertex + 0x80);
  startTexCoordT = (double)*(float *)(startVertex + 0x84);
  startTexCoordR = (double)*(float *)(startVertex + 0x88);
  startTexCoordQ = (double)*(float *)(startVertex + 0x8c);
  if (startFlagByte7f == '\0') {
    startClipW = (double)*(float *)(startVertex + 0x1c);
    startTexCoordQ = (double)(startTexCoordQ * startClipW);
    startTexCoordS = (double)(startTexCoordS * startClipW);
    startTexCoordT = (double)(startTexCoordT * startClipW);
    startTexCoordR = (double)(startTexCoordR * startClipW);
  }
  endTexCoordS = (double)*(float *)(endVertex + 0x80);
  endTexCoordT = (double)*(float *)(endVertex + 0x84);
  endTexCoordR = (double)*(float *)(endVertex + 0x88);
  endTexCoordQ = (double)*(float *)(endVertex + 0x8c);
  if (*(char *)(endVertex + 0x7f) == '\0') {
    endClipW = (double)*(float *)(endVertex + 0x1c);
    endTexCoordQ = (double)(endTexCoordQ * endClipW);
    endTexCoordS = (double)(endTexCoordS * endClipW);
    endTexCoordT = (double)(endTexCoordT * endClipW);
    endTexCoordR = (double)(endTexCoordR * endClipW);
  }
  outTexCoordS = (edgeT * (endTexCoordS - startTexCoordS) + startTexCoordS);
  outTexCoordT = (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
  outTexCoordQ = (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
  outTexCoordR = (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
  if (clipOutcode == 0) {
    outInvW = outVertex[3];
    outTexCoordQ = outTexCoordQ * outInvW;
    outTexCoordS = outTexCoordS * outInvW;
    outTexCoordT = outTexCoordT * outInvW;
    outTexCoordR = outTexCoordR * outInvW;
  }
  outVertex[0x23] = outTexCoordQ;
  outVertex[0x20] = outTexCoordS;
  outVertex[0x21] = outTexCoordT;
  outVertex[0x22] = outTexCoordR;
  return;
}

/* _gleInterpolEyeNO1100w_body @ 0xb7458 (548 bytes) */
void _gleInterpolEyeNO1100w_body(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,float incomingFpr4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float startWord23;
  float startWord0d;
  float clipXThenNdcX;
  float startWord21;
  float startWord0e;
  float windowBiasZ;
  float endWord0b;
  float clipYThenNdcY;
  float startWord22;
  float startWord0f;
  float windowScaleZ;
  float startWord09;
  float clipZThenNdcZ;
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
  float negClipW;
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
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - incomingFpr4) + incomingFpr4);
  startClipY = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - startClipY) + startClipY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
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
  float clipWThenInvW;
  float outTexCoordS;
  float startWord10;
  char startFlagByte7f;
  float clipXThenNdcX;
  float outTexCoordT;
  float startWord11;
  float windowBiasZ;
  float startWord0b;
  float clipYThenNdcY;
  float outTexCoordR;
  float endWord10;
  float windowScaleZ;
  float endWord0b;
  float clipZThenNdcZ;
  float outTexCoordQ;
  float endWord11;
  float startWord09;
  float startWord0a;
  float outInvW;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint clipOutcode;
  float startClipW;
  float endTexCoordT;
  float endClipW;
  float startTexCoordS;
  float startTexCoordT;
  float startTexCoordR;
  float endTexCoordQ;
  float endTexCoordR;
  float endTexCoordS;
  float startTexCoordQ;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  startFlagByte7f = *(char *)((int)startVertex + 0x7f);
  clipOutcode = 0;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  startTexCoordS = (double)startVertex[0x20];
  startTexCoordT = (double)startVertex[0x21];
  startTexCoordR = (double)startVertex[0x22];
  startTexCoordQ = (double)startVertex[0x23];
  if (startFlagByte7f == '\0') {
    startClipW = (double)startVertex[7];
    startTexCoordQ = (double)(startTexCoordQ * startClipW);
    startTexCoordS = (double)(startTexCoordS * startClipW);
    startTexCoordT = (double)(startTexCoordT * startClipW);
    startTexCoordR = (double)(startTexCoordR * startClipW);
  }
  endTexCoordS = (double)*(float *)(endVertex + 0x80);
  endTexCoordT = (double)*(float *)(endVertex + 0x84);
  endTexCoordR = (double)*(float *)(endVertex + 0x88);
  endTexCoordQ = (double)*(float *)(endVertex + 0x8c);
  if (*(char *)(endVertex + 0x7f) == '\0') {
    endClipW = (double)*(float *)(endVertex + 0x1c);
    endTexCoordQ = (double)(endTexCoordQ * endClipW);
    endTexCoordS = (double)(endTexCoordS * endClipW);
    endTexCoordT = (double)(endTexCoordT * endClipW);
    endTexCoordR = (double)(endTexCoordR * endClipW);
  }
  outTexCoordS = (edgeT * (endTexCoordS - startTexCoordS) + startTexCoordS);
  outTexCoordT = (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
  outTexCoordR = (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
  outTexCoordQ = (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
  if (clipOutcode == 0) {
    outInvW = outVertex[3];
    outTexCoordQ = outTexCoordQ * outInvW;
    outTexCoordS = outTexCoordS * outInvW;
    outTexCoordT = outTexCoordT * outInvW;
    outTexCoordR = outTexCoordR * outInvW;
  }
  outVertex[0x20] = outTexCoordS;
  outVertex[0x21] = outTexCoordT;
  outVertex[0x22] = outTexCoordR;
  outVertex[0x23] = outTexCoordQ;
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
  float clipWThenInvW;
  float startWord10;
  float startWord21;
  float clipXThenNdcX;
  float startWord11;
  float startWord22;
  float windowBiasZ;
  float startWord0b;
  float clipYThenNdcY;
  float endWord10;
  float startWord23;
  float windowScaleZ;
  float endWord0b;
  float clipZThenNdcZ;
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
  float negClipW;
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
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  clipOutcode = 0;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
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
void _gleInterpolEyeNO1110_body(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,float incomingFpr5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float outTexCoordS;
  float startWord0c;
  char startFlagByte7f;
  float clipXThenNdcX;
  float outTexCoordT;
  float startWord0d;
  float windowBiasZ;
  float endWord0b;
  float clipYThenNdcY;
  float outTexCoordQ;
  float startWord0f;
  float windowScaleZ;
  float startWord09;
  float clipZThenNdcZ;
  float outTexCoordR;
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
  float negClipW;
  float endWord0e;
  float endClipX;
  float startClipY;
  float endClipY;
  float startClipZ;
  uint clipOutcode;
  float startClipW;
  float endTexCoordS;
  float endClipW;
  float startTexCoordS;
  float startTexCoordT;
  float startTexCoordQ;
  float endTexCoordT;
  float startTexCoordR;
  float endTexCoordQ;
  float endTexCoordR;
  
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = *(float *)(startVertex + 0x24);
  startWord0a = *(float *)(startVertex + 0x28);
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = *(float *)(startVertex + 0x10);
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - incomingFpr5) + incomingFpr5);
  startClipY = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - startClipY) + startClipY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  startFlagByte7f = *(char *)(startVertex + 0x7f);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
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
  startTexCoordS = (double)*(float *)(startVertex + 0x80);
  startTexCoordT = (double)*(float *)(startVertex + 0x84);
  startTexCoordR = (double)*(float *)(startVertex + 0x88);
  startTexCoordQ = (double)*(float *)(startVertex + 0x8c);
  if (startFlagByte7f == '\0') {
    startClipW = (double)*(float *)(startVertex + 0x1c);
    startTexCoordQ = (double)(startTexCoordQ * startClipW);
    startTexCoordS = (double)(startTexCoordS * startClipW);
    startTexCoordT = (double)(startTexCoordT * startClipW);
    startTexCoordR = (double)(startTexCoordR * startClipW);
  }
  endTexCoordS = (double)*(float *)(endVertex + 0x80);
  endTexCoordT = (double)*(float *)(endVertex + 0x84);
  endTexCoordR = (double)*(float *)(endVertex + 0x88);
  endTexCoordQ = (double)*(float *)(endVertex + 0x8c);
  if (*(char *)(endVertex + 0x7f) == '\0') {
    endClipW = (double)*(float *)(endVertex + 0x1c);
    endTexCoordQ = (double)(endTexCoordQ * endClipW);
    endTexCoordS = (double)(endTexCoordS * endClipW);
    endTexCoordT = (double)(endTexCoordT * endClipW);
    endTexCoordR = (double)(endTexCoordR * endClipW);
  }
  outTexCoordS = (edgeT * (endTexCoordS - startTexCoordS) + startTexCoordS);
  outTexCoordT = (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
  outTexCoordQ = (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
  outTexCoordR = (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
  if (clipOutcode == 0) {
    outInvW = outVertex[3];
    outTexCoordQ = outTexCoordQ * outInvW;
    outTexCoordS = outTexCoordS * outInvW;
    outTexCoordT = outTexCoordT * outInvW;
    outTexCoordR = outTexCoordR * outInvW;
  }
  outVertex[0x23] = outTexCoordQ;
  outVertex[0x20] = outTexCoordS;
  outVertex[0x21] = outTexCoordT;
  outVertex[0x22] = outTexCoordR;
  return;
}

/* _gleInterpolEyeNO1110w_body @ 0xb7dcc (568 bytes) */
void _gleInterpolEyeNO1110w_body(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,float incomingFpr4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float startWord23;
  float startWord0c;
  float clipXThenNdcX;
  float startWord21;
  float startWord0d;
  float windowBiasZ;
  float endWord0b;
  float clipYThenNdcY;
  float startWord22;
  float startWord0f;
  float windowScaleZ;
  float startWord09;
  float clipZThenNdcZ;
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
  float negClipW;
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
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - incomingFpr4) + incomingFpr4);
  startClipY = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - startClipY) + startClipY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
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
  float clipWThenInvW;
  float outTexCoordS;
  float startWord10;
  char startFlagByte7f;
  float clipXThenNdcX;
  float outTexCoordT;
  float startWord11;
  float windowBiasZ;
  float startWord0b;
  float clipYThenNdcY;
  float outTexCoordR;
  float endWord10;
  float windowScaleZ;
  float endWord0b;
  float clipZThenNdcZ;
  float outTexCoordQ;
  float endWord11;
  float startWord09;
  float startWord0a;
  float outInvW;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint clipOutcode;
  float startClipW;
  float endTexCoordT;
  float endClipW;
  float startTexCoordS;
  float startTexCoordT;
  float endTexCoordQ;
  float endTexCoordS;
  float startTexCoordR;
  float endTexCoordR;
  float startTexCoordQ;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  startFlagByte7f = *(char *)((int)startVertex + 0x7f);
  clipOutcode = 0;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13]);
  startTexCoordS = (double)startVertex[0x20];
  startTexCoordT = (double)startVertex[0x21];
  startTexCoordR = (double)startVertex[0x22];
  startTexCoordQ = (double)startVertex[0x23];
  if (startFlagByte7f == '\0') {
    startClipW = (double)startVertex[7];
    startTexCoordQ = (double)(startTexCoordQ * startClipW);
    startTexCoordS = (double)(startTexCoordS * startClipW);
    startTexCoordT = (double)(startTexCoordT * startClipW);
    startTexCoordR = (double)(startTexCoordR * startClipW);
  }
  endTexCoordS = (double)*(float *)(endVertex + 0x80);
  endTexCoordT = (double)*(float *)(endVertex + 0x84);
  endTexCoordR = (double)*(float *)(endVertex + 0x88);
  endTexCoordQ = (double)*(float *)(endVertex + 0x8c);
  if (*(char *)(endVertex + 0x7f) == '\0') {
    endClipW = (double)*(float *)(endVertex + 0x1c);
    endTexCoordQ = (double)(endTexCoordQ * endClipW);
    endTexCoordS = (double)(endTexCoordS * endClipW);
    endTexCoordT = (double)(endTexCoordT * endClipW);
    endTexCoordR = (double)(endTexCoordR * endClipW);
  }
  outTexCoordS = (edgeT * (endTexCoordS - startTexCoordS) + startTexCoordS);
  outTexCoordT = (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
  outTexCoordR = (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
  outTexCoordQ = (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
  if (clipOutcode == 0) {
    outInvW = outVertex[3];
    outTexCoordQ = outTexCoordQ * outInvW;
    outTexCoordS = outTexCoordS * outInvW;
    outTexCoordT = outTexCoordT * outInvW;
    outTexCoordR = outTexCoordR * outInvW;
  }
  outVertex[0x20] = outTexCoordS;
  outVertex[0x21] = outTexCoordT;
  outVertex[0x22] = outTexCoordR;
  outVertex[0x23] = outTexCoordQ;
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
  float clipWThenInvW;
  float startWord10;
  float startWord21;
  float clipXThenNdcX;
  float startWord11;
  float startWord22;
  float windowBiasZ;
  float startWord0b;
  float clipYThenNdcY;
  float endWord10;
  float startWord23;
  float windowScaleZ;
  float endWord0b;
  float clipZThenNdcZ;
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
  float negClipW;
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
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  clipOutcode = 0;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
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
void _gleInterpolEyeNO1200_body(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,float incomingFpr4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float outTexCoordS;
  float startWord0d;
  char startFlagByte7f;
  float clipXThenNdcX;
  float outTexCoordT;
  float startWord0e;
  float windowScaleZ;
  float endWord0b;
  float clipYThenNdcY;
  float outTexCoordR;
  float startWord0f;
  float windowBiasZ;
  float startWord09;
  float clipZThenNdcZ;
  float outTexCoordQ;
  float endWord0d;
  float startWord0a;
  float endWord09;
  float outInvW;
  float endWord0e;
  float endWord0a;
  float endWord0f;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float startClipY;
  float endClipY;
  float startClipZ;
  uint texMaskRemaining;
  int endVertexAtUnit;
  uint texEnableMask;
  uint clipOutcode;
  uint texUnit;
  float startClipW;
  float endTexCoordS;
  float endClipW;
  float endTexCoordS2;
  float endTexCoordQ;
  float endTexCoordT;
  float endTexCoordR;
  float endTexCoordR2;
  float endTexCoordT2;
  float endTexCoordQ2;
  
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = *(float *)(startVertex + 0x24);
  startWord0a = *(float *)(startVertex + 0x28);
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = *(float *)(startVertex + 0x10);
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - incomingFpr4) + incomingFpr4);
  startClipY = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - startClipY) + startClipY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  startFlagByte7f = *(char *)(startVertex + 0x7f);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  startWord0d = *(float *)(startVertex + 0x34);
  texUnit = 0;
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
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        return;
      }
    }
    else {
      endVertexAtUnit = texUnit * 0x10 + startVertex;
      endTexCoordQ = (double)*(float *)(endVertexAtUnit + 0x8c);
      endTexCoordS2 = (double)*(float *)(endVertexAtUnit + 0x80);
      endTexCoordT = (double)*(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = (double)*(float *)(endVertexAtUnit + 0x88);
      if (startFlagByte7f == '\0') {
        startClipW = (double)*(float *)(startVertex + 0x1c);
        endTexCoordQ = (double)(endTexCoordQ * startClipW);
        endTexCoordS2 = (double)(endTexCoordS2 * startClipW);
        endTexCoordT = (double)(endTexCoordT * startClipW);
        endTexCoordR = (double)(endTexCoordR * startClipW);
      }
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      endTexCoordQ2 = (double)*(float *)(endVertexAtUnit + 0x8c);
      endTexCoordS = (double)*(float *)(endVertexAtUnit + 0x80);
      endTexCoordT2 = (double)*(float *)(endVertexAtUnit + 0x84);
      endTexCoordR2 = (double)*(float *)(endVertexAtUnit + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        endClipW = (double)*(float *)(endVertex + 0x1c);
        endTexCoordQ2 = (double)(endTexCoordQ2 * endClipW);
        endTexCoordS = (double)(endTexCoordS * endClipW);
        endTexCoordT2 = (double)(endTexCoordT2 * endClipW);
        endTexCoordR2 = (double)(endTexCoordR2 * endClipW);
      }
      outTexCoordS = (edgeT * (endTexCoordS - endTexCoordS2) + endTexCoordS2);
      outTexCoordT = (edgeT * (endTexCoordT2 - endTexCoordT) + endTexCoordT);
      outTexCoordR = (edgeT * (endTexCoordR2 - endTexCoordR) + endTexCoordR);
      outTexCoordQ = (edgeT * (endTexCoordQ2 - endTexCoordQ) + endTexCoordQ);
      if (clipOutcode == 0) {
        outInvW = outVertex[3];
        outTexCoordQ = outTexCoordQ * outInvW;
        outTexCoordS = outTexCoordS * outInvW;
        outTexCoordT = outTexCoordT * outInvW;
        outTexCoordR = outTexCoordR * outInvW;
      }
      outVertex[texUnit * 4 + 0x23] = outTexCoordQ;
      outVertex[texUnit * 4 + 0x20] = outTexCoordS;
      outVertex[texUnit * 4 + 0x21] = outTexCoordT;
      outVertex[texUnit * 4 + 0x22] = outTexCoordR;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolEyeNO1200w_body @ 0xb879c (600 bytes) */
void _gleInterpolEyeNO1200w_body(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,float incomingFpr3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float startTexCoordQ;
  float startWord0d;
  float clipXThenNdcX;
  float startTexCoordT;
  float startWord0e;
  float windowScaleZ;
  float endWord0b;
  float clipYThenNdcY;
  float startTexCoordR;
  float startWord0f;
  float windowBiasZ;
  float startWord09;
  float clipZThenNdcZ;
  float endTexCoordQ;
  float endWord0d;
  float startWord0a;
  float endTexCoordT;
  float endWord0e;
  float endWord09;
  float endTexCoordR;
  float endWord0f;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float startClipY;
  float endClipY;
  float startClipZ;
  uint texMaskRemaining;
  uint clipOutcode;
  uint texEnableMask;
  int startVertexAtUnit;
  uint texUnit;
  int endVertexAtUnit;
  
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = *(float *)(startVertex + 0x24);
  startWord0a = *(float *)(startVertex + 0x28);
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = *(float *)(startVertex + 0x10);
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - incomingFpr3) + incomingFpr3);
  startClipY = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - startClipY) + startClipY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
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
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        return;
      }
    }
    else {
      startVertexAtUnit = texUnit * 0x10 + startVertex;
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      startTexCoordQ = *(float *)(startVertexAtUnit + 0x8c);
      startTexCoordT = *(float *)(startVertexAtUnit + 0x84);
      startTexCoordR = *(float *)(startVertexAtUnit + 0x88);
      endTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      outVertex[texUnit * 4 + 0x20] =
           (edgeT * (*(float *)(endVertexAtUnit + 0x80) - *(float *)(startVertexAtUnit + 0x80)) + *(float *)(startVertexAtUnit + 0x80));
      outVertex[texUnit * 4 + 0x21] =
           (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
      outVertex[texUnit * 4 + 0x22] =
           (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
      outVertex[texUnit * 4 + 0x23] =
           (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolEyeNO1201 @ 0xb89f4 (704 bytes) */
void _gleInterpolEyeNO1201(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float outTexCoordS;
  float startWord10;
  char startFlagByte7f;
  float clipXThenNdcX;
  float outTexCoordT;
  float startWord11;
  float windowScaleZ;
  float startWord0b;
  float clipYThenNdcY;
  float outTexCoordR;
  float endWord10;
  float windowBiasZ;
  float endWord0b;
  float clipZThenNdcZ;
  float outTexCoordQ;
  float endWord11;
  float startWord09;
  float startWord0a;
  float outInvW;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint texMaskRemaining;
  int endVertexAtUnit;
  uint texEnableMask;
  uint clipOutcode;
  uint texUnit;
  float startClipW;
  float endTexCoordT;
  float endClipW;
  float startTexCoordS;
  float startTexCoordT;
  float startTexCoordR;
  float endTexCoordQ;
  float endTexCoordR;
  float endTexCoordS;
  float startTexCoordQ;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  startFlagByte7f = *(char *)((int)startVertex + 0x7f);
  clipOutcode = 0;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texEnableMask = *(uint *)(glContext + 0x5150);
  texUnit = 0;
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
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
      startTexCoordQ = (double)startVertex[texUnit * 4 + 0x23];
      startTexCoordS = (double)startVertex[texUnit * 4 + 0x20];
      startTexCoordT = (double)startVertex[texUnit * 4 + 0x21];
      startTexCoordR = (double)startVertex[texUnit * 4 + 0x22];
      if (startFlagByte7f == '\0') {
        startClipW = (double)startVertex[7];
        startTexCoordQ = (double)(startTexCoordQ * startClipW);
        startTexCoordS = (double)(startTexCoordS * startClipW);
        startTexCoordT = (double)(startTexCoordT * startClipW);
        startTexCoordR = (double)(startTexCoordR * startClipW);
      }
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      endTexCoordQ = (double)*(float *)(endVertexAtUnit + 0x8c);
      endTexCoordS = (double)*(float *)(endVertexAtUnit + 0x80);
      endTexCoordT = (double)*(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = (double)*(float *)(endVertexAtUnit + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        endClipW = (double)*(float *)(endVertex + 0x1c);
        endTexCoordQ = (double)(endTexCoordQ * endClipW);
        endTexCoordS = (double)(endTexCoordS * endClipW);
        endTexCoordT = (double)(endTexCoordT * endClipW);
        endTexCoordR = (double)(endTexCoordR * endClipW);
      }
      outTexCoordS = (edgeT * (endTexCoordS - startTexCoordS) + startTexCoordS);
      outTexCoordT = (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
      outTexCoordR = (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
      outTexCoordQ = (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
      if (clipOutcode == 0) {
        outInvW = outVertex[3];
        outTexCoordQ = outTexCoordQ * outInvW;
        outTexCoordS = outTexCoordS * outInvW;
        outTexCoordT = outTexCoordT * outInvW;
        outTexCoordR = outTexCoordR * outInvW;
      }
      outVertex[texUnit * 4 + 0x23] = outTexCoordQ;
      outVertex[texUnit * 4 + 0x20] = outTexCoordS;
      outVertex[texUnit * 4 + 0x21] = outTexCoordT;
      outVertex[texUnit * 4 + 0x22] = outTexCoordR;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolEyeNO1201w @ 0xb8cb4 (616 bytes) */
void _gleInterpolEyeNO1201w(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float startTexCoordQ;
  float startWord10;
  float clipXThenNdcX;
  float startTexCoordT;
  float startWord11;
  float windowScaleZ;
  float startWord0b;
  float clipYThenNdcY;
  float startTexCoordR;
  float endWord10;
  float windowBiasZ;
  float endWord0b;
  float clipZThenNdcZ;
  float endTexCoordQ;
  float endWord11;
  float startWord09;
  float endTexCoordT;
  float startWord0a;
  float endTexCoordR;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint texMaskRemaining;
  uint clipOutcode;
  uint texEnableMask;
  uint texUnit;
  int endVertexAtUnit;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  clipOutcode = 0;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texEnableMask = *(uint *)(glContext + 0x5150);
  texUnit = 0;
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
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
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      startTexCoordQ = startVertex[texUnit * 4 + 0x23];
      startTexCoordT = startVertex[texUnit * 4 + 0x21];
      startTexCoordR = startVertex[texUnit * 4 + 0x22];
      endTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      outVertex[texUnit * 4 + 0x20] =
           (edgeT * (*(float *)(endVertexAtUnit + 0x80) - startVertex[texUnit * 4 + 0x20]) + startVertex[texUnit * 4 + 0x20]);
      outVertex[texUnit * 4 + 0x21] =
           (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
      outVertex[texUnit * 4 + 0x22] =
           (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
      outVertex[texUnit * 4 + 0x23] =
           (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolEyeNO1210_body @ 0xb8f20 (708 bytes) */
void _gleInterpolEyeNO1210_body(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,float incomingFpr4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float outTexCoordS;
  float startWord0c;
  char startFlagByte7f;
  float clipXThenNdcX;
  float outTexCoordT;
  float startWord0d;
  float windowScaleZ;
  float endWord0b;
  float clipYThenNdcY;
  float outTexCoordR;
  float startWord0f;
  float windowBiasZ;
  float startWord09;
  float clipZThenNdcZ;
  float outTexCoordQ;
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
  float negClipW;
  float endWord0e;
  float endClipX;
  float startClipY;
  float endClipY;
  float startClipZ;
  uint texMaskRemaining;
  int endVertexAtUnit;
  uint texEnableMask;
  uint clipOutcode;
  uint texUnit;
  float startClipW;
  float endTexCoordS;
  float endClipW;
  float endTexCoordS2;
  float endTexCoordQ;
  float endTexCoordT;
  float endTexCoordT2;
  float endTexCoordR;
  float endTexCoordQ2;
  float endTexCoordR2;
  
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = *(float *)(startVertex + 0x24);
  startWord0a = *(float *)(startVertex + 0x28);
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = *(float *)(startVertex + 0x10);
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - incomingFpr4) + incomingFpr4);
  startClipY = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - startClipY) + startClipY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  startFlagByte7f = *(char *)(startVertex + 0x7f);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
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
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        return;
      }
    }
    else {
      endVertexAtUnit = texUnit * 0x10 + startVertex;
      endTexCoordQ = (double)*(float *)(endVertexAtUnit + 0x8c);
      endTexCoordS2 = (double)*(float *)(endVertexAtUnit + 0x80);
      endTexCoordT = (double)*(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = (double)*(float *)(endVertexAtUnit + 0x88);
      if (startFlagByte7f == '\0') {
        startClipW = (double)*(float *)(startVertex + 0x1c);
        endTexCoordQ = (double)(endTexCoordQ * startClipW);
        endTexCoordS2 = (double)(endTexCoordS2 * startClipW);
        endTexCoordT = (double)(endTexCoordT * startClipW);
        endTexCoordR = (double)(endTexCoordR * startClipW);
      }
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      endTexCoordQ2 = (double)*(float *)(endVertexAtUnit + 0x8c);
      endTexCoordS = (double)*(float *)(endVertexAtUnit + 0x80);
      endTexCoordT2 = (double)*(float *)(endVertexAtUnit + 0x84);
      endTexCoordR2 = (double)*(float *)(endVertexAtUnit + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        endClipW = (double)*(float *)(endVertex + 0x1c);
        endTexCoordQ2 = (double)(endTexCoordQ2 * endClipW);
        endTexCoordS = (double)(endTexCoordS * endClipW);
        endTexCoordT2 = (double)(endTexCoordT2 * endClipW);
        endTexCoordR2 = (double)(endTexCoordR2 * endClipW);
      }
      outTexCoordS = (edgeT * (endTexCoordS - endTexCoordS2) + endTexCoordS2);
      outTexCoordT = (edgeT * (endTexCoordT2 - endTexCoordT) + endTexCoordT);
      outTexCoordR = (edgeT * (endTexCoordR2 - endTexCoordR) + endTexCoordR);
      outTexCoordQ = (edgeT * (endTexCoordQ2 - endTexCoordQ) + endTexCoordQ);
      if (clipOutcode == 0) {
        outInvW = outVertex[3];
        outTexCoordQ = outTexCoordQ * outInvW;
        outTexCoordS = outTexCoordS * outInvW;
        outTexCoordT = outTexCoordT * outInvW;
        outTexCoordR = outTexCoordR * outInvW;
      }
      outVertex[texUnit * 4 + 0x23] = outTexCoordQ;
      outVertex[texUnit * 4 + 0x20] = outTexCoordS;
      outVertex[texUnit * 4 + 0x21] = outTexCoordT;
      outVertex[texUnit * 4 + 0x22] = outTexCoordR;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolEyeNO1210w_body @ 0xb91e8 (620 bytes) */
void _gleInterpolEyeNO1210w_body(int glContext,int startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,float incomingFpr3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float startTexCoordQ;
  float startWord0c;
  float clipXThenNdcX;
  float startTexCoordT;
  float startWord0d;
  float windowScaleZ;
  float endWord0b;
  float clipYThenNdcY;
  float startTexCoordR;
  float startWord0f;
  float windowBiasZ;
  float startWord09;
  float clipZThenNdcZ;
  float endTexCoordQ;
  float endWord0c;
  float startWord0a;
  float endTexCoordT;
  float endWord0d;
  float endWord09;
  float endTexCoordR;
  float startWord0e;
  float endWord0a;
  float startClipX;
  float endWord0f;
  float endClipZ;
  float negClipW;
  float endWord0e;
  float endClipX;
  float startClipY;
  float endClipY;
  float startClipZ;
  uint texMaskRemaining;
  uint clipOutcode;
  uint texEnableMask;
  int startVertexAtUnit;
  uint texUnit;
  int endVertexAtUnit;
  
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = *(float *)(startVertex + 0x24);
  startWord0a = *(float *)(startVertex + 0x28);
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = *(float *)(startVertex + 0x10);
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - *(float *)(startVertex + 0x1c)) + *(float *)(startVertex + 0x1c));
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - *(float *)(startVertex + 0x20)) + *(float *)(startVertex + 0x20));
  outVertex[0xb] = (edgeT * (endWord0b - incomingFpr3) + incomingFpr3);
  startClipY = *(float *)(startVertex + 0x14);
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = *(float *)(startVertex + 0x18);
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - startClipY) + startClipY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x7c) << 0x18 | (uint)*(byte *)(startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
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
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
        return;
      }
    }
    else {
      startVertexAtUnit = texUnit * 0x10 + startVertex;
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      startTexCoordQ = *(float *)(startVertexAtUnit + 0x8c);
      startTexCoordT = *(float *)(startVertexAtUnit + 0x84);
      startTexCoordR = *(float *)(startVertexAtUnit + 0x88);
      endTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      outVertex[texUnit * 4 + 0x20] =
           (edgeT * (*(float *)(endVertexAtUnit + 0x80) - *(float *)(startVertexAtUnit + 0x80)) + *(float *)(startVertexAtUnit + 0x80));
      outVertex[texUnit * 4 + 0x21] =
           (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
      outVertex[texUnit * 4 + 0x22] =
           (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
      outVertex[texUnit * 4 + 0x23] =
           (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolEyeNO1211 @ 0xb9454 (724 bytes) */
void _gleInterpolEyeNO1211(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float outTexCoordS;
  float startWord10;
  char startFlagByte7f;
  float clipXThenNdcX;
  float outTexCoordT;
  float startWord11;
  float windowScaleZ;
  float startWord0b;
  float clipYThenNdcY;
  float outTexCoordR;
  float endWord10;
  float windowBiasZ;
  float endWord0b;
  float clipZThenNdcZ;
  float outTexCoordQ;
  float endWord11;
  float startWord09;
  float startWord0a;
  float outInvW;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint texMaskRemaining;
  int endVertexAtUnit;
  uint texEnableMask;
  uint clipOutcode;
  uint texUnit;
  float startClipW;
  float endTexCoordT;
  float endClipW;
  float startTexCoordS;
  float startTexCoordT;
  float endTexCoordQ;
  float endTexCoordS;
  float startTexCoordR;
  float endTexCoordR;
  float startTexCoordQ;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  startFlagByte7f = *(char *)((int)startVertex + 0x7f);
  clipOutcode = 0;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13]);
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
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
      startTexCoordQ = (double)startVertex[texUnit * 4 + 0x23];
      startTexCoordS = (double)startVertex[texUnit * 4 + 0x20];
      startTexCoordT = (double)startVertex[texUnit * 4 + 0x21];
      startTexCoordR = (double)startVertex[texUnit * 4 + 0x22];
      if (startFlagByte7f == '\0') {
        startClipW = (double)startVertex[7];
        startTexCoordQ = (double)(startTexCoordQ * startClipW);
        startTexCoordS = (double)(startTexCoordS * startClipW);
        startTexCoordT = (double)(startTexCoordT * startClipW);
        startTexCoordR = (double)(startTexCoordR * startClipW);
      }
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      endTexCoordQ = (double)*(float *)(endVertexAtUnit + 0x8c);
      endTexCoordS = (double)*(float *)(endVertexAtUnit + 0x80);
      endTexCoordT = (double)*(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = (double)*(float *)(endVertexAtUnit + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        endClipW = (double)*(float *)(endVertex + 0x1c);
        endTexCoordQ = (double)(endTexCoordQ * endClipW);
        endTexCoordS = (double)(endTexCoordS * endClipW);
        endTexCoordT = (double)(endTexCoordT * endClipW);
        endTexCoordR = (double)(endTexCoordR * endClipW);
      }
      outTexCoordS = (edgeT * (endTexCoordS - startTexCoordS) + startTexCoordS);
      outTexCoordT = (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
      outTexCoordR = (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
      outTexCoordQ = (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
      if (clipOutcode == 0) {
        outInvW = outVertex[3];
        outTexCoordQ = outTexCoordQ * outInvW;
        outTexCoordS = outTexCoordS * outInvW;
        outTexCoordT = outTexCoordT * outInvW;
        outTexCoordR = outTexCoordR * outInvW;
      }
      outVertex[texUnit * 4 + 0x23] = outTexCoordQ;
      outVertex[texUnit * 4 + 0x20] = outTexCoordS;
      outVertex[texUnit * 4 + 0x21] = outTexCoordT;
      outVertex[texUnit * 4 + 0x22] = outTexCoordR;
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolEyeNO1211w @ 0xb9728 (636 bytes) */
void _gleInterpolEyeNO1211w(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float startTexCoordQ;
  float startWord10;
  float clipXThenNdcX;
  float startTexCoordT;
  float startWord11;
  float windowScaleZ;
  float startWord0b;
  float clipYThenNdcY;
  float startTexCoordR;
  float endWord10;
  float windowBiasZ;
  float endWord0b;
  float clipZThenNdcZ;
  float endTexCoordQ;
  float endWord11;
  float startWord09;
  float endTexCoordT;
  float startWord0a;
  float endTexCoordR;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint texMaskRemaining;
  uint clipOutcode;
  uint texEnableMask;
  uint texUnit;
  int endVertexAtUnit;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  clipOutcode = 0;
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  texUnit = 0;
  outVertex[0x13] =
       (edgeT * (*(float *)(endVertex + 0x4c) - startVertex[0x13]) + startVertex[0x13]);
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
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
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      startTexCoordQ = startVertex[texUnit * 4 + 0x23];
      startTexCoordT = startVertex[texUnit * 4 + 0x21];
      startTexCoordR = startVertex[texUnit * 4 + 0x22];
      endTexCoordQ = *(float *)(endVertexAtUnit + 0x8c);
      endTexCoordT = *(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = *(float *)(endVertexAtUnit + 0x88);
      outVertex[texUnit * 4 + 0x20] =
           (edgeT * (*(float *)(endVertexAtUnit + 0x80) - startVertex[texUnit * 4 + 0x20]) + startVertex[texUnit * 4 + 0x20]);
      outVertex[texUnit * 4 + 0x21] =
           (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
      outVertex[texUnit * 4 + 0x22] =
           (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
      outVertex[texUnit * 4 + 0x23] =
           (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
    }
    texUnit = texUnit + 1;
  } while( true );
}

/* _gleInterpolEyeAllFlat @ 0xb99a4 (728 bytes) */
void _gleInterpolEyeAllFlat(int glContext,float *startVertex,int endVertex,float *outVertex,float edgeT,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  float clipWThenInvW;
  float outTexCoordS;
  float startWord16;
  float startWord13;
  char startFlagByte7f;
  float clipYThenNdcY;
  float outTexCoordR;
  float windowBiasZ;
  float endWord0b;
  float clipZThenNdcZ;
  float outTexCoordQ;
  float startWord09;
  float startWord0a;
  float outInvW;
  float endWord09;
  float endWord0a;
  float startClipX;
  float endClipZ;
  float negClipW;
  float endClipX;
  float endClipY;
  float startClipZ;
  uint texMaskRemaining;
  int endVertexAtUnit;
  float clipXThenNdcX;
  float outTexCoordT;
  float startWord1e;
  float endWord13;
  float windowScaleZ;
  float startWord0b;
  uint texEnableMask;
  uint clipOutcode;
  uint texUnit;
  float startClipW;
  float endTexCoordS;
  float endClipW;
  float startTexCoordS;
  float startTexCoordT;
  float startTexCoordR;
  float endTexCoordQ;
  float endTexCoordR;
  float endTexCoordT;
  float startTexCoordQ;
  
  startWord0b = startVertex[0xb];
  endWord0b = *(float *)(endVertex + 0x2c);
  startWord09 = startVertex[9];
  startWord0a = startVertex[10];
  clipOutcode = 0;
  endWord09 = *(float *)(endVertex + 0x24);
  endWord0a = *(float *)(endVertex + 0x28);
  startClipX = startVertex[4];
  endClipX = *(float *)(endVertex + 0x10);
  clipWThenInvW = (edgeT * (*(float *)(endVertex + 0x1c) - startVertex[7]) + startVertex[7]);
  outVertex[8] = (edgeT * (*(float *)(endVertex + 0x20) - startVertex[8]) + startVertex[8]);
  outVertex[0xb] = (edgeT * (endWord0b - startWord0b) + startWord0b);
  clipYThenNdcY = startVertex[5];
  endClipY = *(float *)(endVertex + 0x14);
  startClipZ = startVertex[6];
  clipXThenNdcX = (edgeT * (endClipX - startClipX) + startClipX);
  endClipZ = *(float *)(endVertex + 0x18);
  negClipW = -clipWThenInvW;
  outVertex[9] = (edgeT * (endWord09 - startWord09) + startWord09);
  outVertex[10] = (edgeT * (endWord0a - startWord0a) + startWord0a);
  outVertex[4] = clipXThenNdcX;
  clipYThenNdcY = (edgeT * (endClipY - clipYThenNdcY) + clipYThenNdcY);
  outVertex[7] = clipWThenInvW;
  clipZThenNdcZ = (edgeT * (endClipZ - startClipZ) + startClipZ);
  startFlagByte7f = *(char *)((int)startVertex + 0x7f);
  outVertex[5] = clipYThenNdcY;
  outVertex[6] = clipZThenNdcZ;
  if (clipXThenNdcX < negClipW) {
    clipOutcode = 0x10;
  }
  if (clipWThenInvW <= clipXThenNdcX) {
    clipOutcode = clipOutcode | 0x20;
  }
  if (clipYThenNdcY < negClipW) {
    clipOutcode = clipOutcode | 4;
  }
  if (clipWThenInvW <= clipYThenNdcY) {
    clipOutcode = clipOutcode | 8;
  }
  if (clipZThenNdcZ < negClipW) {
    clipOutcode = clipOutcode | 1;
  }
  if (clipWThenInvW < clipZThenNdcZ) {
    clipOutcode = clipOutcode | 2;
  }
  outVertex[0x1f] =
       GH_U2F((unsigned int)(((uint)*(byte *)(startVertex + 0x1f) << 0x18 | (uint)*(byte *)((int)startVertex + 0x7e) << 8 |
               clipOutcode | 0x10000)));
  if (clipOutcode == 0) {
    if (clipWThenInvW != FLOAT_00108e54) {
      clipWThenInvW = FLOAT_00108e54 / clipWThenInvW;
      clipXThenNdcX = clipXThenNdcX * clipWThenInvW;
      clipYThenNdcY = clipYThenNdcY * clipWThenInvW;
      clipZThenNdcZ = clipZThenNdcZ * clipWThenInvW;
    }
    *outVertex = *(float *)(glContext + 0x1b70) * clipXThenNdcX + *(float *)(glContext + 0x1b80);
    outVertex[1] = *(float *)(glContext + 0x1b74) * clipYThenNdcY + *(float *)(glContext + 0x1b84);
    windowScaleZ = *(float *)(glContext + 0x1b78);
    windowBiasZ = *(float *)(glContext + 0x1b88);
    outVertex[3] = clipWThenInvW;
    outVertex[2] = windowScaleZ * clipZThenNdcZ + windowBiasZ;
  }
  startWord13 = startVertex[0x13];
  texUnit = 0;
  endWord13 = *(float *)(endVertex + 0x4c);
  outVertex[0x17] =
       (edgeT * (*(float *)(endVertex + 0x5c) - startVertex[0x17]) + startVertex[0x17]);
  outVertex[0x13] =
       (edgeT * (endWord13 - startWord13) + startWord13);
  texEnableMask = *(uint *)(glContext + 0x5150);
  do {
    texMaskRemaining = texEnableMask >> (texUnit & 0x3f);
    if ((texMaskRemaining & 1) == 0) {
      if (texMaskRemaining == 0) {
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
      startTexCoordQ = (double)startVertex[texUnit * 4 + 0x23];
      startTexCoordS = (double)startVertex[texUnit * 4 + 0x20];
      startTexCoordT = (double)startVertex[texUnit * 4 + 0x21];
      startTexCoordR = (double)startVertex[texUnit * 4 + 0x22];
      if (startFlagByte7f == '\0') {
        startClipW = (double)startVertex[7];
        startTexCoordQ = (double)(startTexCoordQ * startClipW);
        startTexCoordS = (double)(startTexCoordS * startClipW);
        startTexCoordT = (double)(startTexCoordT * startClipW);
        startTexCoordR = (double)(startTexCoordR * startClipW);
      }
      endVertexAtUnit = texUnit * 0x10 + endVertex;
      endTexCoordQ = (double)*(float *)(endVertexAtUnit + 0x8c);
      endTexCoordS = (double)*(float *)(endVertexAtUnit + 0x80);
      endTexCoordT = (double)*(float *)(endVertexAtUnit + 0x84);
      endTexCoordR = (double)*(float *)(endVertexAtUnit + 0x88);
      if (*(char *)(endVertex + 0x7f) == '\0') {
        endClipW = (double)*(float *)(endVertex + 0x1c);
        endTexCoordQ = (double)(endTexCoordQ * endClipW);
        endTexCoordS = (double)(endTexCoordS * endClipW);
        endTexCoordT = (double)(endTexCoordT * endClipW);
        endTexCoordR = (double)(endTexCoordR * endClipW);
      }
      outTexCoordS = (edgeT * (endTexCoordS - startTexCoordS) + startTexCoordS);
      outTexCoordT = (edgeT * (endTexCoordT - startTexCoordT) + startTexCoordT);
      outTexCoordR = (edgeT * (endTexCoordR - startTexCoordR) + startTexCoordR);
      outTexCoordQ = (edgeT * (endTexCoordQ - startTexCoordQ) + startTexCoordQ);
      if (clipOutcode == 0) {
        outInvW = outVertex[3];
        outTexCoordQ = outTexCoordQ * outInvW;
        outTexCoordS = outTexCoordS * outInvW;
        outTexCoordT = outTexCoordT * outInvW;
        outTexCoordR = outTexCoordR * outInvW;
      }
      outVertex[texUnit * 4 + 0x23] = outTexCoordQ;
      outVertex[texUnit * 4 + 0x20] = outTexCoordS;
      outVertex[texUnit * 4 + 0x21] = outTexCoordT;
      outVertex[texUnit * 4 + 0x22] = outTexCoordR;
    }
    texUnit = texUnit + 1;
  } while( true );
}

