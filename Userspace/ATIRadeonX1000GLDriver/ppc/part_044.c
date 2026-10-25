#include "decls.h"

/* FUN_00158988 @ 0x158988 (496 bytes) */
int FUN_00158988(param_1, inst, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int *inst;
  int param_3;
  undefined4 param_4;
  uint param_5;
  int param_6;
{
  int operandRecord;
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint local_28 [5];
  
  *(int *)(param_6 + 0x1ac) = *(int *)(param_6 + 0x1ac) + 1;
LAB_001589b0:
  do {
    iVar2 = (**(code **)(*inst + 100))(inst);
    if (iVar2 == 0) {
LAB_00158b48:
      iVar2 = inst[0x49];
LAB_00158b4c:
      uVar1 = inst[5];
    }
    else {
      for (iVar2 = 1; iVar3 = (**(code **)(*inst + 0x14))(inst), iVar2 <= iVar3;
          iVar2 = iVar2 + 1) {
        if ((inst[iVar2 * 6 + 0x28] & 1U) != 0) goto LAB_00158b48;
        if (((inst[iVar2 * 6 + 0x28] & 2U) != 0) ||
           (iVar3 = IRInst__isSourceSelectIdentity(inst,iVar2), iVar3 == 0)) goto LAB_00158b3c;
      }
      if (inst[0x48] == 0) {
        iVar2 = inst[0x49];
        if (iVar2 != 0) goto LAB_00158b4c;
        if ((((inst[0x20] != 0) && (iVar2 = RegKind__flagBit0(inst[0x26]), iVar2 != 0)) &&
            ((inst[5] & 2U) == 0)) &&
           (iVar2 = (**(code **)(*inst + 0x50))(inst), iVar2 == 0)) {
          iVar2 = 4;
          piVar4 = inst;
          do {
            if ((uint)(*(byte *)(piVar4 + 0x27) - 2) < 2) goto LAB_00158b48;
            piVar4 = (int *)((int)piVar4 + 1);
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
        IRInst__getOperandRecord(inst,0);
        iVar2 = IRInst__operandKindClass(inst,0);
        if (iVar2 != 0) goto LAB_00158b48;
        uVar1 = inst[5];
        if (((uVar1 & 2) == 0) && ((uVar1 & 0x200) == 0)) {
          inst = (int *)IRInst__getOperandSource(inst,1);
          goto LAB_001589b0;
        }
        iVar2 = inst[0x49];
      }
      else {
LAB_00158b3c:
        iVar2 = inst[0x49];
        uVar1 = inst[5];
      }
    }
    inst[0x49] = param_3 + iVar2;
    while( true ) {
      if ((uVar1 & 0x200) == 0) {
        return;
      }
      inst = (int *)IRInst__getOperandSource(inst,inst[0x21]);
      operandRecord = IRInst__getOperandRecord(inst,0);
      WriteMask__fromSelectWord(local_28,*(undefined4 *)(operandRecord + 0x10));
      if ((param_5 & local_28[0]) != 0) break;
      uVar1 = inst[5];
    }
  } while( true );
}

/* FUN_00158b78 @ 0x158b78 (196 bytes) */
int FUN_00158b78(param_1, param_2, inst, param_4, param_5, param_6)
  undefined4 param_1;
  int *param_2;
  undefined4 inst;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*param_2 + 100))(param_2,param_2,inst,param_4,param_5,param_6);
  if ((((iVar1 != 0) && (param_2[0x48] == 0)) && ((param_2[5] & 0x200U) == 0)) &&
     ((iVar1 = param_2[0x49], iVar1 != 0 &&
      (iVar2 = FUN_0015800c(param_1,inst,iVar1,param_5,param_6,param_4), iVar2 != 0)))) {
    ((int (*)())FUN_00158988)(param_2,inst,iVar1,param_5,param_6,param_4);
    param_2[0x49] = 0;
  }
  return;
}

/* Inst__distributeResultScale @ 0x158c3c (2424 bytes) */
int Inst__distributeResultScale(rootInst, program)
  int rootInst;
  int program;
{
  int pushByteOffset4;
  int canApply3;
  int pushByteOffset3;
  int pushByteOffset2;
  int canApply2;
  int addrMode2;
  int lanesLeft2;
  int flagResult2;
  int srcIndex2;
  int isMov2;
  int addrMode;
  int lanesLeft;
  int flagResult;
  int srcIndex;
  int isMov;
  int singleUse2;
  int canApply;
  int singleUse1;
  int scale;
  uint operandFlags2;
  uint operandFlags;
  uint topIndex;
  int *topSlot;
  undefined4 sourceDef2;
  int operandRecord2;
  int sourceDef;
  int *operandVReg;
  undefined4 src1ReadMaskCopy;
  undefined4 src2ReadMaskCopy;
  int *pushSlot;
  int operandRecord;
  int *callResult;
  undefined4 *pushedSlot;
  undefined4 src3ReadMaskCopy;
  undefined4 operandVReg2;
  uint pushIndex;
  int *laneByteCursor;
  undefined4 changedRoot;
  undefined4 destSelect;
  int pushByteOffset;
  int opcode;
  uint *operandFlagsPtr;
  int curInst;
  /* NOTE (issue #64): local_68/local_64/local_60 are passed by address (&local_68) to Arena__alloc/
   * Vector__removeAt/Vector__elementRefGrow as one contiguous 3-word vector struct (capacity, count, data-ptr).
   * Ghidra split it into 3 separate scalar locals, which -O0 does NOT lay out contiguously (confirmed
   * live: real stack deltas were 0x44/0x4 bytes, not 4/4) - forced into one array so the compiler
   * can't reorder/pad between them. */
  undefined4 local_68vec_158c3c[3];
#define local_68_vec local_68vec_158c3c[0]
#define local_64_vec local_68vec_158c3c[1]
#define local_60_vec local_68vec_158c3c[2]
  undefined4 worklistArena;
  undefined4 src1ReadMask;
  undefined4 src2ReadMask;
  undefined4 src3ReadMask [6];
  
  worklistArena = *(undefined4 *)(*(int *)(program + 8) + 0x378);
  local_68_vec = 2;
  local_64_vec = 0;
  local_60_vec = Arena__alloc(worklistArena,8);
  pushIndex = local_64_vec;
  if (local_64_vec < local_68_vec) {
    pushByteOffset = local_64_vec * 4;
    _memset(local_60_vec + pushByteOffset,0,4);
    local_64_vec = pushIndex + 1;
    pushSlot = (int *)(pushByteOffset + local_60_vec);
  }
  else {
    pushSlot = (int *)Vector__elementRefGrow(&local_68_vec,local_64_vec);
  }
  *pushSlot = rootInst;
  changedRoot = 0;
  do {
    topIndex = local_64_vec - 1;
    topSlot = (int *)0x0;
    if (topIndex < local_64_vec) {
      topSlot = (int *)(topIndex * 4 + local_60_vec);
    }
    curInst = *topSlot;
    Vector__removeAt(&local_68_vec,topIndex);
    scale = *(int *)(curInst + 0x124);
    opcode = *(int *)(*(int *)(curInst + 0x88) + 8);
    if (opcode - 0x12U < 3) {
      operandRecord = IRInst__getOperandRecord(curInst,0);
      destSelect = *(undefined4 *)(operandRecord + 0x10);
      operandRecord = IRInst__getOperandRecord(curInst,1);
      SelectWord__readMask(&src1ReadMask,*(undefined4 *)(operandRecord + 0x10));
      src1ReadMaskCopy = src1ReadMask;
      operandRecord = IRInst__getOperandRecord(curInst,2);
      SelectWord__readMask(&src2ReadMask,*(undefined4 *)(operandRecord + 0x10));
      src2ReadMaskCopy = src2ReadMask;
      operandVReg = (int *)IRInst__getOperandSource(curInst,1);
      callResult = (int *)IRInst__getOperandSource(curInst,2);
      if (opcode == 0x13) {
        singleUse1 = IRInst__hasSingleUse(operandVReg,program);
        if ((singleUse1 != 0) && (singleUse1 = IRInst__hasSingleUse(callResult,program), singleUse1 != 0)) {
          ((int (*)())FUN_00158b78)(curInst,operandVReg,callResult,program,destSelect,src2ReadMaskCopy);
          ((int (*)())FUN_00158b78)(curInst,callResult,operandVReg,program,destSelect,src1ReadMaskCopy);
        }
        if (scale != 0) {
          canApply = FUN_0015800c(curInst,operandVReg,scale,destSelect,src1ReadMaskCopy,program);
          if (canApply == 0) {
            canApply = FUN_0015800c(curInst,callResult,scale,destSelect,src2ReadMaskCopy,program);
            if (canApply != 0) {
              ((int (*)())FUN_00158988)(curInst,callResult,scale,destSelect,src2ReadMaskCopy,program);
              *(undefined4 *)(curInst + 0x124) = 0;
              goto LAB_00158fc8;
            }
          }
          else {
            ((int (*)())FUN_00158988)(curInst,operandVReg,scale,destSelect,src1ReadMaskCopy,program);
            pushIndex = local_64_vec;
            *(undefined4 *)(curInst + 0x124) = 0;
            if (local_64_vec < local_68_vec) {
              pushByteOffset = local_64_vec * 4;
              _memset(pushByteOffset + local_60_vec,0,4);
              local_64_vec = pushIndex + 1;
              pushedSlot = (undefined4 *)(pushByteOffset + local_60_vec);
            }
            else {
              pushedSlot = (undefined4 *)Vector__elementRefGrow(&local_68_vec,local_64_vec);
            }
            *pushedSlot = operandVReg;
          }
        }
      }
      else if (opcode == 0x14) {
        singleUse2 = IRInst__hasSingleUse(operandVReg,program);
        if ((singleUse2 != 0) && (singleUse2 = IRInst__hasSingleUse(callResult,program), singleUse2 != 0)) {
          ((int (*)())FUN_00158b78)(curInst,operandVReg,callResult,program,destSelect,src2ReadMaskCopy);
          ((int (*)())FUN_00158b78)(curInst,callResult,operandVReg,program,destSelect,src1ReadMaskCopy);
          isMov = (**(code **)(*operandVReg + 100))(operandVReg);
          if (isMov != 0) {
            operandFlagsPtr = (uint *)(operandVReg + 0x2e);
            for (srcIndex = 1; operandRecord = (**(code **)(*operandVReg + 0x14))(operandVReg), srcIndex <= operandRecord;
                srcIndex = srcIndex + 1) {
              operandFlags = *operandFlagsPtr;
              operandFlagsPtr = operandFlagsPtr + 6;
              if ((((operandFlags & 1) != 0) || ((operandFlags & 2) != 0)) ||
                 (operandRecord = IRInst__isSourceSelectIdentity(operandVReg,srcIndex), operandRecord == 0)) goto LAB_00159218;
            }
            if ((operandVReg[0x48] == 0) && (operandVReg[0x49] == 0)) {
              if (((operandVReg[0x20] != 0) &&
                  ((flagResult = RegKind__flagBit0(operandVReg[0x26]), flagResult != 0 && ((operandVReg[5] & 2U) == 0))))
                 && (flagResult = (**(code **)(*operandVReg + 0x50))(operandVReg), flagResult == 0)) {
                lanesLeft = 4;
                laneByteCursor = operandVReg;
                do {
                  if ((uint)(*(byte *)(laneByteCursor + 0x27) - 2) < 2) goto LAB_00159218;
                  laneByteCursor = (int *)((int)laneByteCursor + 1);
                  lanesLeft = lanesLeft + -1;
                } while (lanesLeft != 0);
              }
              IRInst__getOperandRecord(operandVReg,0);
              addrMode = IRInst__operandKindClass(operandVReg,0);
              if (((addrMode == 0) && ((operandVReg[5] & 2U) == 0)) && ((operandVReg[5] & 0x200U) == 0)) {
                *(int *)(program + 0x17c) = *(int *)(program + 0x17c) + 1;
                sourceDef2 = IRInst__getOperandSource(operandVReg,1);
                IRInst__setOperandSource(curInst,1,sourceDef2,0,*(undefined4 *)(program + 8));
                sourceDef = IRInst__getOperandSource(operandVReg,1);
                if (*(int *)(program + 0x478) < *(int *)(sourceDef + 0x160)) {
                  *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
                }
                else {
                  *(int *)(sourceDef + 0x160) = *(int *)(program + 0x478) + 1;
                }
                IRInst__dropCounterAndDeleteIfUnused(operandVReg,*(undefined4 *)(program + 8));
              }
            }
          }
LAB_00159218:
          isMov2 = (**(code **)(*callResult + 100))(callResult);
          if (isMov2 != 0) {
            operandFlagsPtr = (uint *)(callResult + 0x2e);
            for (srcIndex2 = 1; operandRecord = (**(code **)(*callResult + 0x14))(callResult), srcIndex2 <= operandRecord;
                srcIndex2 = srcIndex2 + 1) {
              operandFlags2 = *operandFlagsPtr;
              operandFlagsPtr = operandFlagsPtr + 6;
              if ((((operandFlags2 & 1) != 0) || ((operandFlags2 & 2) != 0)) ||
                 (operandRecord = IRInst__isSourceSelectIdentity(callResult,srcIndex2), operandRecord == 0)) goto LAB_001593b8;
            }
            if ((callResult[0x48] == 0) && (callResult[0x49] == 0)) {
              if ((callResult[0x20] != 0) &&
                 (((flagResult2 = RegKind__flagBit0(callResult[0x26]), flagResult2 != 0 && ((callResult[5] & 2U) == 0)) &&
                  (flagResult2 = (**(code **)(*callResult + 0x50))(callResult), flagResult2 == 0)))) {
                lanesLeft2 = 4;
                laneByteCursor = callResult;
                do {
                  if ((uint)(*(byte *)(laneByteCursor + 0x27) - 2) < 2) goto LAB_001593b8;
                  laneByteCursor = (int *)((int)laneByteCursor + 1);
                  lanesLeft2 = lanesLeft2 + -1;
                } while (lanesLeft2 != 0);
              }
              IRInst__getOperandRecord(callResult,0);
              addrMode2 = IRInst__operandKindClass(callResult,0);
              if (((addrMode2 == 0) && ((callResult[5] & 2U) == 0)) && ((callResult[5] & 0x200U) == 0)) {
                *(int *)(program + 0x17c) = *(int *)(program + 0x17c) + 1;
                sourceDef2 = IRInst__getOperandSource(callResult,1);
                IRInst__setOperandSource(curInst,2,sourceDef2,0,*(undefined4 *)(program + 8));
                sourceDef = IRInst__getOperandSource(callResult,1);
                if (*(int *)(program + 0x478) < *(int *)(sourceDef + 0x160)) {
                  *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
                }
                else {
                  *(int *)(sourceDef + 0x160) = *(int *)(program + 0x478) + 1;
                }
                IRInst__dropCounterAndDeleteIfUnused(callResult,*(undefined4 *)(program + 8));
              }
            }
          }
        }
LAB_001593b8:
        if (scale != 0) {
          operandVReg2 = IRInst__getOperandSource(curInst,3);
          operandRecord2 = IRInst__getOperandRecord(curInst,3);
          SelectWord__readMask(src3ReadMask,*(undefined4 *)(operandRecord2 + 0x10));
          src3ReadMaskCopy = src3ReadMask[0];
          canApply2 = FUN_0015800c(curInst,operandVReg2,scale,destSelect,src3ReadMask[0],program);
          if (canApply2 != 0) {
            canApply2 = FUN_0015800c(curInst,operandVReg,scale,destSelect,src1ReadMaskCopy,program);
            if (canApply2 == 0) {
              canApply2 = FUN_0015800c(curInst,callResult,scale,destSelect,src2ReadMaskCopy,program);
              if (canApply2 == 0) break;
              ((int (*)())FUN_00158988)(curInst,callResult,scale,destSelect,src2ReadMaskCopy,program);
              pushIndex = local_64_vec;
              *(undefined4 *)(curInst + 0x124) = 0;
              if (local_64_vec < local_68_vec) {
                pushByteOffset2 = local_64_vec * 4;
                _memset(pushByteOffset2 + local_60_vec,0,4);
                local_64_vec = pushIndex + 1;
                pushedSlot = (undefined4 *)(pushByteOffset2 + local_60_vec);
              }
              else {
                pushedSlot = (undefined4 *)Vector__elementRefGrow(&local_68_vec,local_64_vec);
              }
              *pushedSlot = callResult;
            }
            else {
              ((int (*)())FUN_00158988)(curInst,operandVReg,scale,destSelect,src1ReadMaskCopy,program);
              pushIndex = local_64_vec;
              *(undefined4 *)(curInst + 0x124) = 0;
              if (local_64_vec < local_68_vec) {
                pushByteOffset3 = local_64_vec * 4;
                _memset(pushByteOffset3 + local_60_vec,0,4);
                local_64_vec = pushIndex + 1;
                pushedSlot = (undefined4 *)(pushByteOffset3 + local_60_vec);
              }
              else {
                pushedSlot = (undefined4 *)Vector__elementRefGrow(&local_68_vec,local_64_vec);
              }
              *pushedSlot = operandVReg;
            }
            ((int (*)())FUN_00158988)(curInst,operandVReg2,scale,destSelect,src3ReadMaskCopy,program);
            pushIndex = local_64_vec;
            if (local_64_vec < local_68_vec) {
              pushByteOffset = local_64_vec * 4;
              _memset(pushByteOffset + local_60_vec,0,4);
              local_64_vec = pushIndex + 1;
              pushedSlot = (undefined4 *)(pushByteOffset + local_60_vec);
            }
            else {
              pushedSlot = (undefined4 *)Vector__elementRefGrow(&local_68_vec,local_64_vec);
            }
            *pushedSlot = operandVReg2;
          }
        }
      }
      else if (((opcode == 0x12) && (scale != 0)) &&
              ((canApply3 = FUN_0015800c(curInst,operandVReg,scale,destSelect,src1ReadMaskCopy,program), canApply3 != 0 &&
               (canApply3 = FUN_0015800c(curInst,callResult,scale,destSelect,src2ReadMaskCopy,program), canApply3 != 0)))) {
        *(undefined4 *)(curInst + 0x124) = 0;
        if (rootInst == curInst) {
          changedRoot = 1;
        }
        ((int (*)())FUN_00158988)(curInst,operandVReg,scale,destSelect,src1ReadMaskCopy,program);
        pushIndex = local_64_vec;
        if (local_64_vec < local_68_vec) {
          pushByteOffset4 = local_64_vec * 4;
          _memset(pushByteOffset4 + local_60_vec,0,4);
          local_64_vec = pushIndex + 1;
          pushedSlot = (undefined4 *)(pushByteOffset4 + local_60_vec);
        }
        else {
          pushedSlot = (undefined4 *)Vector__elementRefGrow(&local_68_vec,local_64_vec);
        }
        *pushedSlot = operandVReg;
        if (operandVReg != callResult) {
          ((int (*)())FUN_00158988)(curInst,callResult,scale,destSelect,src2ReadMaskCopy,program);
LAB_00158fc8:
          pushIndex = local_64_vec;
          if (local_64_vec < local_68_vec) {
            pushByteOffset = local_64_vec * 4;
            _memset(pushByteOffset + local_60_vec,0,4);
            local_64_vec = pushIndex + 1;
            pushedSlot = (undefined4 *)(pushByteOffset + local_60_vec);
          }
          else {
            pushedSlot = (undefined4 *)Vector__elementRefGrow(&local_68_vec,local_64_vec);
          }
          *pushedSlot = callResult;
        }
      }
    }
  } while (local_64_vec != 0);
  Arena__free(worklistArena,local_60_vec);
  return changedRoot;
}

/* Inst__foldCndWithConstantCondition @ 0x1595f0 (420 bytes) */
int Inst__foldCndWithConstantCondition(inst, program)
  undefined4 inst;
  int program;
{
  bool moreLanes;
  undefined4 mixSourceIndex;
  int isMix;
  int prevChoice;
  int flagBit7Result;
  int operandRecord3;
  int operandRecord2;
  bool choiceMismatch;
  int isCndOp;
  int operandRecord;
  int *a0;
  int laneChoice;
  undefined4 result;
  int lane;
  uint laneComponent;
  undefined4 condSelectWord [4];
  undefined4 absValue;
  float modifiedValue;
  
  isCndOp = IRInst__isCndFloatOp(inst);
  if (isCndOp == 0) {
LAB_0015977c:
    result = 0;
  }
  else {
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    condSelectWord[0] = *(undefined4 *)(operandRecord2 + 0x10);
    lane = 0;
    prevChoice = -1;
    do {
      operandRecord = IRInst__getOperandRecord(inst,0);
      laneChoice = prevChoice;
      if (*(char *)(lane + operandRecord + 0x10) != '\x01') {
        laneComponent = (uint)*(byte *)((int)condSelectWord + lane);
        a0 = (int *)IRInst__getOperandSource(inst,1);
        isMix = (**(code **)(*a0 + 0x60))(a0);
        if (isMix != 0) {
          mixSourceIndex = IRInst__firstOperandWithSelectNot4(a0,laneComponent);
          operandRecord3 = IRInst__getOperandRecord(a0,mixSourceIndex);
          laneComponent = (uint)*(byte *)(laneComponent + operandRecord3 + 0x10);
          a0 = (int *)IRInst__getOperandSource(a0,mixSourceIndex);
        }
        flagBit7Result = RegKind__flagBit7(a0[0x26]);
        if ((flagBit7Result == 0) || (((int)*(char *)(a0 + 0x57) >> (laneComponent & 0x3f) & 1U) == 0))
        goto LAB_0015977c;
        IRInst__applyAbsModifier(&absValue,inst,1,a0[laneComponent * 6 + 8]);
        IRInst__applyNegateModifier(&modifiedValue,inst,1,absValue);
        laneChoice = ((bool (*)())evaluateCompareFloats)(inst,(double)modifiedValue,0.0);
        laneChoice = (laneChoice == 0) + 2;
        if ((prevChoice != -1) && (choiceMismatch = laneChoice != prevChoice, laneChoice = prevChoice, choiceMismatch)) goto LAB_0015977c;
      }
      moreLanes = lane != 3;
      lane = lane + 1;
      prevChoice = laneChoice;
    } while (moreLanes);
    *(int *)(program + 0x1ec) = *(int *)(program + 0x1ec) + 1;
    IRInst__replaceWithMovOfSource(inst,laneChoice,0,*(undefined4 *)(program + 8));
    result = 1;
  }
  return result;
}

/* FUN_00159794 @ 0x159794 (964 bytes) */
int FUN_00159794(inst, param_2, param_3)
  int inst;
  int param_2;
  uint param_3;
{
  int cloneResult;
  undefined4 opcodeInfo;
  undefined4 opcodeInfo2;
  int sourceDef2;
  int operandRecord;
  int sourceDef;
  int loopIndex;
  uint uVar1;
  int opcodeInfo1;
  undefined4 uVar3;
  int iVar4;
  int *operandVReg;
  int operandVReg2;
  undefined4 uVar7;
  int iVar8;
  int program;
  undefined4 uVar10;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28 [2];
  
  opcodeInfo1 = *(int *)(inst + 0x88);
  local_2c = 0x3f000000;
  local_38 = 0x3f000000;
  local_34 = 0x3f000000;
  local_30 = 0x3f000000;
  if (*(int *)(opcodeInfo1 + 8) == 0x24) {
    opcodeInfo = Opcode__getInfo(0x25);
    *(undefined4 *)(inst + 0x88) = opcodeInfo;
    IROperand__setModifierBits(inst + 0xa4,1,1);
    IROperand__setModifierBits(inst + 0xa4,2,1);
    opcodeInfo1 = *(int *)(inst + 0x88);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
    if (*(int *)(opcodeInfo1 + 8) == 0x26) {
      uVar3 = 1;
      opcodeInfo2 = Opcode__getInfo(0x25);
      *(undefined4 *)(inst + 0x88) = opcodeInfo2;
      IROperand__setModifierBits(inst + 0xa4,1,*(uint *)(inst + 0xb8) & 1 ^ 1);
      IRInst__swapOperands(inst,2,3,param_3);
      opcodeInfo1 = *(int *)(inst + 0x88);
    }
  }
  if (((*(int *)(opcodeInfo1 + 8) == 0x25) && ((*(uint *)(*(int *)(param_3 + 0x6c4) + 0x30) & 8) != 0)) &&
     (param_2 != 0)) {
    sourceDef = IRInst__getOperandSource(inst,1);
    operandRecord = IRInst__getOperandRecord(sourceDef,0);
    uVar10 = *(undefined4 *)(operandRecord + 0x10);
    if ((((*(uint *)(inst + 0xb8) & 2) == 0) && (*(int *)(*(int *)(sourceDef + 0x88) + 8) == 0x12))
       && (((*(uint *)(sourceDef + 0x14) & 0x200) == 0 &&
           ((*(int *)(sourceDef + 0x120) == 0 && (*(int *)(sourceDef + 0x124) == 0)))))) {
      sourceDef2 = IRInst__getOperandSource(sourceDef,1);
      uVar7 = 0;
      if (sourceDef2 != 0) {
        sourceDef2 = IRInst__getOperandSource(sourceDef,1);
        uVar7 = *(undefined4 *)(sourceDef2 + 0x98);
      }
      iVar4 = FUN_001267b8(uVar7);
      if (iVar4 == 0) {
        operandVReg = (int *)IRInst__getOperandSource(sourceDef,1);
        iVar4 = (**(code **)(*operandVReg + 0x5c))(operandVReg);
        if (iVar4 == 0) {
          return uVar3;
        }
      }
      if (((((*(uint *)(sourceDef + 0xb8) & 2) == 0) &&
           (uVar1 = *(uint *)(inst + 0xb8) & 1, uVar1 == (*(uint *)(sourceDef + 0xd0) & 1))) &&
          (uVar1 != (*(uint *)(sourceDef + 0xb8) & 1))) &&
         (iVar4 = IRInst__sourceMatchesConstant(sourceDef,2,uVar10,&local_38), iVar4 != 0)) {
        opcodeInfo = Opcode__getInfo(0x9d);
        *(undefined4 *)(inst + 0x88) = opcodeInfo;
        operandRecord = IRInst__getOperandRecord(sourceDef,1);
        uVar3 = *(undefined4 *)(operandRecord + 0x10);
        operandRecord = IRInst__getOperandRecord(inst,1);
        SelectWord__compose(local_28,uVar3,*(undefined4 *)(operandRecord + 0x10));
        operandRecord = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord + 0x10) = local_28[0];
        IROperand__setModifierBits(inst + 0xa4,1,0);
        IRInst__swapOperands(inst,2,3,param_3);
        program = *(int *)(param_3 + 0x6c4);
        iVar8 = *(int *)(program + 0x478);
        operandVReg = (int *)IRInst__getOperandSource(sourceDef,1);
        iVar4 = (**(code **)(*operandVReg + 0x5c))(operandVReg);
        if ((iVar4 == 0) || (iVar4 = IRInst__hasSingleUse(operandVReg,program), iVar4 != 0)) {
          IRInst__setOperandSource(inst,1,operandVReg,0,param_3);
          if (iVar8 < operandVReg[0x58]) {
            operandVReg[0x58] = operandVReg[0x58] + 1;
          }
          else {
            operandVReg[0x58] = iVar8 + 1;
          }
        }
        else {
          cloneResult = IRInst__clone(operandVReg,param_3,0);
          *(undefined4 *)(cloneResult + 0x94) = *(undefined4 *)(cloneResult + 0x14c);
          Block__insertInstAfter(operandVReg[0x56],operandVReg,cloneResult);
          IRInst__setOperandSource(inst,1,cloneResult,0,param_3);
          *(int *)(cloneResult + 0x160) = *(int *)(program + 0x478) + 1;
          if (0 < *(int *)(cloneResult + 0x84)) {
            loopIndex = 1;
            do {
              operandVReg2 = IRInst__getOperandSource(cloneResult,loopIndex);
              if (iVar8 < *(int *)(operandVReg2 + 0x160)) {
                *(int *)(operandVReg2 + 0x160) = *(int *)(operandVReg2 + 0x160) + 1;
              }
              else {
                *(int *)(operandVReg2 + 0x160) = iVar8 + 1;
              }
              loopIndex = loopIndex + 1;
            } while (loopIndex <= *(int *)(cloneResult + 0x84));
          }
        }
        IRInst__dropCounterAndDeleteIfUnused(sourceDef,param_3);
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}

/* FUN_00159b58 @ 0x159b58 (2844 bytes) */
int FUN_00159b58(node, param_2, pass)
  int node;
  undefined4 param_2;
  int pass;
{
  uint source1Flags;
  uint set;
  int operandIndex3;
  int operandIndex2;
  int operandIndex;
  int inst;
  int uniformSourceConstant2;
  int uniformSourceConstant3;
  int hasSingleUse;
  int uniformSourceConstant;
  undefined4 sourceDef3;
  int sourceDef2;
  int operandRecord;
  int operandRecord3;
  int sourceDef4;
  int sourceDef;
  int operandRecord2;
  int *operandVReg;
  float fVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 a1;
  uint uVar7;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  double fparam_1;
  undefined1 auStack_118 [4];
  undefined4 param_3_w;
  undefined1 auStack_100 [4];
  undefined4 param_3_w2;
  undefined1 auStack_e8 [4];
  float local_e4;
  undefined1 auStack_d0 [4];
  float local_cc;
  undefined1 auStack_b8 [4];
  float local_b4;
  undefined1 auStack_a0 [4];
  float local_9c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  float local_70;
  float local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c [3];
  float local_50;
  
  uVar12 = *(uint *)(pass + 8);
  if ((((*(int *)(*(int *)(uVar12 + 0x6c4) + 0x214) + *(int *)(*(int *)(uVar12 + 0x6c4) + 0x218) <
         *(int *)(uVar12 + 0x6a0)) && (node != 0)) && (0 < *(int *)(node + 0x84))) &&
     (inst = IRInst__getOperandSource(node,1), inst != 0)) {
    ((int (*)())FUN_00159794)(node,param_2,uVar12);
    ((int (*)())FUN_00159794)(inst,param_2,uVar12);
    iVar8 = *(int *)(node + 0x88);
    if ((*(int *)(iVar8 + 8) == 0x25) && (*(int *)(*(int *)(inst + 0x88) + 8) == 0x25)) {
      iVar8 = IRInst__sourceLanesAllWritten(node,1);
      if (iVar8 != 0) {
        operandRecord = IRInst__getOperandRecord(inst,0);
        uniformSourceConstant2 = IRInst__getUniformSourceConstant(inst,2,*(undefined4 *)(operandRecord + 0x10),auStack_118);
        if (uniformSourceConstant2 != 0) {
          operandRecord = IRInst__getOperandRecord(inst,0);
          uniformSourceConstant2 = IRInst__getUniformSourceConstant(inst,3,*(undefined4 *)(operandRecord + 0x10),auStack_100);
          if (uniformSourceConstant2 != 0) {
            *(int *)(pass + 0x214) = *(int *)(pass + 0x214) + 1;
            operandVReg = (int *)IRInst__getOperandSource(inst,1);
            iVar8 = (**(code **)(*operandVReg + 0x5c))(operandVReg);
            piVar4 = operandVReg;
            if ((iVar8 != 0) && (iVar8 = IRInst__hasSingleUse(operandVReg,pass), iVar8 == 0)) {
              piVar4 = (int *)IRInst__clone(operandVReg,uVar12,0);
              piVar4[0x25] = piVar4[0x53];
              Block__insertInstAfter(operandVReg[0x56],operandVReg,piVar4);
              piVar4[0x58] = *(int *)(pass + 0x478);
              if (0 < piVar4[0x21]) {
                operandIndex2 = 1;
                do {
                  sourceDef4 = IRInst__getOperandSource(piVar4,operandIndex2);
                  if (*(int *)(pass + 0x478) < *(int *)(sourceDef4 + 0x160)) {
                    *(int *)(sourceDef4 + 0x160) = *(int *)(sourceDef4 + 0x160) + 1;
                  }
                  else {
                    *(int *)(sourceDef4 + 0x160) = *(int *)(pass + 0x478) + 1;
                  }
                  operandIndex2 = operandIndex2 + 1;
                } while (operandIndex2 <= piVar4[0x21]);
              }
            }
            IRInst__scaleByOutputScale(&local_88,inst,param_3_w);
            IRInst__scaleByOutputScale(&local_84,inst,param_3_w2);
            IRInst__clampOutputValue(&local_80,inst,local_88);
            IRInst__clampOutputValue(&local_7c,inst,local_84);
            IRInst__applyAbsModifier(&local_78,node,1,local_80);
            IRInst__applyAbsModifier(&local_74,node,1,local_7c);
            IRInst__applyNegateModifier(&local_70,node,1,local_78);
            uVar5 = 1;
            IRInst__applyNegateModifier(&local_6c,node,1,local_74);
            local_50 = local_70;
            if ((0.0 <= local_70) || (local_50 = local_6c, 0.0 <= local_6c)) {
              if ((0.0 > local_70) || (local_50 = local_6c, local_6c < 0.0)) {
                source1Flags = *(uint *)(inst + 0xb8);
                iVar8 = (**(code **)(*piVar4 + 0x5c))
                                  (piVar4,a1,uVar5,local_74,in_r7,in_r8,*(code **)(*piVar4 + 0x5c));
                piVar3 = piVar4;
                if (iVar8 != 0) {
                  iVar6 = *(int *)(pass + 0x478);
                  piVar3 = (int *)IRInst__clone(piVar4,*(undefined4 *)(pass + 8),0);
                  iVar10 = piVar3[0x53];
                  operandRecord = IRInst__getOperandRecord(piVar3,0);
                  *(int *)(operandRecord + 8) = iVar10;
                  piVar3[0x58] = iVar6;
                  for (operandIndex3 = 1; iVar10 = (**(code **)(*piVar3 + 0x14))(piVar3), operandIndex3 <= iVar10;
                      operandIndex3 = operandIndex3 + 1) {
                    iVar10 = IRInst__getOperandSource(piVar3,operandIndex3);
                    if (iVar6 < *(int *)(iVar10 + 0x160)) {
                      *(int *)(iVar10 + 0x160) = *(int *)(iVar10 + 0x160) + 1;
                    }
                    else {
                      *(int *)(iVar10 + 0x160) = iVar6 + 1;
                    }
                  }
                  Block__insertInstBefore(piVar4[0x56],piVar4,piVar3);
                }
                IRInst__setOperandSource(node,1,piVar3,0,uVar12);
                if (*(int *)(pass + 0x478) < piVar3[0x58]) {
                  piVar3[0x58] = piVar3[0x58] + 1;
                }
                else {
                  piVar3[0x58] = *(int *)(pass + 0x478) + 1;
                }
                IROperand__setModifierBits(node + 0xa4,1,source1Flags & 1);
                IROperand__setModifierBits(node + 0xa4,2,source1Flags >> 1 & 1);
                operandRecord = IRInst__getOperandRecord(inst,1);
                uVar5 = *(undefined4 *)(operandRecord + 0x10);
                operandRecord = IRInst__getOperandRecord(node,1);
                SelectWord__compose(&local_68,uVar5,*(undefined4 *)(operandRecord + 0x10));
                operandRecord = IRInst__getOperandRecord(node,1);
                *(undefined4 *)(operandRecord + 0x10) = local_68;
                if ((local_70 < 0.0) || (local_50 = local_6c, 0.0 <= local_6c)) {
                  IRInst__swapOperands(node,2,3,uVar12);
                }
                uVar5 = IRInst__dropCounterAndDeleteIfUnused(inst,uVar12);
                return uVar5;
              }
              uVar5 = 2;
            }
            else {
              uVar5 = 3;
            }
            IRInst__replaceWithMovOfSource(node,uVar5,0,uVar12);
            return 0;
          }
        }
      }
      iVar8 = *(int *)(node + 0x88);
    }
    if (*(int *)(iVar8 + 8) == 0x8b) {
      iVar8 = *(int *)(node + 300);
      operandRecord2 = IRInst__getOperandRecord(node,0);
      uniformSourceConstant = IRInst__getUniformSourceConstant(node,2,*(undefined4 *)(operandRecord2 + 0x10),auStack_e8);
      if (uniformSourceConstant == 0) {
        operandRecord2 = IRInst__getOperandRecord(node,0);
        uniformSourceConstant = IRInst__getUniformSourceConstant(node,1,*(undefined4 *)(operandRecord2 + 0x10),auStack_e8);
        if (uniformSourceConstant == 0) {
          return 0;
        }
        IRInst__swapOperands(node,1,2,uVar12);
        iVar8 = *(int *)(PTR_DAT_001e90f8 + iVar8 * 4);
        *(int *)(node + 300) = iVar8;
      }
      sourceDef = IRInst__getOperandSource(node,1);
      if (((*(uint *)(node + 0xb8) & 2) == 0) && ((*(uint *)(node + 0xd0) & 2) == 0)) {
        if ((*(int *)(*(int *)(sourceDef + 0x88) + 8) == 0x12) &&
           (((local_e4 == 0.0 && (*(int *)(sourceDef + 0x120) == 0)) &&
            ((*(uint *)(sourceDef + 0x14) & 0x200) == 0)))) {
          operandRecord = IRInst__getOperandRecord(node,1);
          uVar9 = *(undefined4 *)(operandRecord + 0x10);
          *(int *)(pass + 0x218) = *(int *)(pass + 0x218) + 1;
          sourceDef3 = IRInst__getOperandSource(node,2);
          IRInst__dropCounterAndDeleteIfUnused(sourceDef3,uVar12);
          sourceDef3 = IRInst__getOperandSource(sourceDef,1);
          IRInst__setOperandSource(node,1,sourceDef3,0,uVar12);
          operandRecord = IRInst__getOperandRecord(sourceDef,1);
          SelectWord__compose(&local_64,*(undefined4 *)(operandRecord + 0x10),uVar9);
          operandRecord = IRInst__getOperandRecord(node,1);
          *(undefined4 *)(operandRecord + 0x10) = local_64;
          sourceDef2 = IRInst__getOperandSource(sourceDef,1);
          if (*(int *)(pass + 0x478) < *(int *)(sourceDef2 + 0x160)) {
            *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + 1;
          }
          else {
            *(int *)(sourceDef2 + 0x160) = *(int *)(pass + 0x478) + 1;
          }
          IROperand__setModifierBits(node + 0xa4,2,*(uint *)(sourceDef + 0xb8) >> 1 & 1);
          sourceDef3 = IRInst__getOperandSource(sourceDef,2);
          IRInst__setOperandSource(node,2,sourceDef3,0,uVar12);
          operandRecord = IRInst__getOperandRecord(sourceDef,2);
          SelectWord__compose(&local_60,*(undefined4 *)(operandRecord + 0x10),uVar9);
          operandRecord = IRInst__getOperandRecord(node,2);
          *(undefined4 *)(operandRecord + 0x10) = local_60;
          sourceDef2 = IRInst__getOperandSource(sourceDef,2);
          if (*(int *)(pass + 0x478) < *(int *)(sourceDef2 + 0x160)) {
            *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + 1;
          }
          else {
            *(int *)(sourceDef2 + 0x160) = *(int *)(pass + 0x478) + 1;
          }
          IROperand__setModifierBits(node + 0xbc,2,*(uint *)(sourceDef + 0xd0) >> 1 & 1);
          uVar11 = *(uint *)(node + 0xb8) & 1;
          set = uVar11;
          if ((*(uint *)(sourceDef + 0xb8) & 1) != 0) {
            set = uVar11 ^ 1;
          }
          if ((*(uint *)(sourceDef + 0xd0) & 1) != 0) {
            uVar11 = uVar11 ^ 1;
          }
          IROperand__setModifierBits(node + 0xa4,1,set);
          IROperand__setModifierBits(node + 0xbc,1,uVar11 ^ 1);
          uVar5 = IRInst__dropCounterAndDeleteIfUnused(sourceDef,uVar12);
          return uVar5;
        }
        operandRecord3 = IRInst__getOperandRecord(node,0);
        iVar6 = IRInst__getUniformSourceConstant(node,2,*(undefined4 *)(operandRecord3 + 0x10),auStack_d0);
        if (((*(int *)(*(int *)(sourceDef + 0x88) + 8) == 0x25) && (iVar6 != 0)) &&
           ((local_cc == 0.0 &&
            (((*(uint *)(sourceDef + 0x14) & 0x200) == 0 ||
             (iVar6 = FUN_000f45f8(node,1,sourceDef,pass), iVar6 != 0)))))) {
          operandRecord3 = IRInst__getOperandRecord(sourceDef,0);
          uniformSourceConstant3 = IRInst__getUniformSourceConstant(sourceDef,2,*(undefined4 *)(operandRecord3 + 0x10),auStack_b8);
          if (uniformSourceConstant3 != 0) {
            operandRecord3 = IRInst__getOperandRecord(sourceDef,0);
            uniformSourceConstant3 = IRInst__getUniformSourceConstant(sourceDef,3,*(undefined4 *)(operandRecord3 + 0x10),auStack_a0);
            if (uniformSourceConstant3 != 0) {
              *(int *)(pass + 0x218) = *(int *)(pass + 0x218) + 1;
              switch(iVar8) {
              case 0:
                uVar11 = (uint)(local_e4 == local_9c);
                uVar7 = (uint)(local_e4 == local_b4);
                break;
              case 1:
                uVar11 = (uint)(local_e4 != local_9c);
                uVar7 = (uint)(local_e4 != local_b4);
                break;
              case 2:
                uVar11 = (uint)(local_e4 < local_9c);
                uVar7 = (uint)(local_e4 < local_b4);
                break;
              case 3:
                uVar11 = (uint)(local_e4 <= local_9c);
                uVar7 = (uint)(local_e4 <= local_b4);
                break;
              case 4:
                uVar11 = (uint)(local_9c < local_e4);
                uVar7 = (uint)(local_b4 < local_e4);
                break;
              case 5:
                uVar11 = (uint)(local_9c <= local_e4);
                uVar7 = (uint)(local_b4 <= local_e4);
                break;
              default:
                goto switchD_0015a394_default;
              }
              operandRecord = IRInst__getOperandRecord(sourceDef,1);
              uVar5 = *(undefined4 *)(operandRecord + 0x10);
              operandRecord = IRInst__getOperandRecord(node,1);
              SelectWord__compose(local_5c,uVar5,*(undefined4 *)(operandRecord + 0x10));
              IRInst__copyOperandFrom(node,1,sourceDef,1);
              operandRecord = IRInst__getOperandRecord(node,1);
              *(undefined4 *)(operandRecord + 0x10) = local_5c[0];
              if (uVar7 == uVar11) {
                if (uVar7 == 0) {
                  fVar1 = 1.0;
                }
                else {
                  fVar1 = 0.0;
                }
                fparam_1 = (double)fVar1;
                piVar4 = (int *)0x0;
                ((void (*)())IRInst__makeLiteralVec4Float)(node,pass,1,fparam_1,fparam_1,fparam_1,fparam_1);
              }
              else {
                piVar4 = (int *)IRInst__getOperandSource(sourceDef,1);
                if (*(int *)(pass + 0x478) < piVar4[0x58]) {
                  piVar4[0x58] = piVar4[0x58] + 1;
                }
                else {
                  piVar4[0x58] = *(int *)(pass + 0x478) + 1;
                }
                *(uint *)(node + 300) = (uVar7 ^ 1) + 3;
              }
              uVar5 = IRInst__dropCounterAndDeleteIfUnused(sourceDef,uVar12);
              if (piVar4 == (int *)0x0) {
                return uVar5;
              }
              iVar2 = (**(code **)(*piVar4 + 0x5c))(piVar4);
              if (iVar2 == 0) {
                return uVar5;
              }
              hasSingleUse = IRInst__hasSingleUse(piVar4,pass);
              if (hasSingleUse == 0) {
                iVar8 = *(int *)(pass + 0x478);
                piVar4[0x58] = piVar4[0x58] + -1;
                iVar6 = iVar8 + 1;
                piVar4 = (int *)IRInst__clone(piVar4,*(undefined4 *)(pass + 8),0);
                iVar10 = piVar4[0x53];
                operandRecord2 = IRInst__getOperandRecord(piVar4,0);
                *(int *)(operandRecord2 + 8) = iVar10;
                piVar4[0x58] = iVar6;
                for (operandIndex = 1; iVar10 = (**(code **)(*piVar4 + 0x14))(piVar4), operandIndex <= iVar10;
                    operandIndex = operandIndex + 1) {
                  iVar10 = IRInst__getOperandSource(piVar4,operandIndex);
                  if (iVar8 < *(int *)(iVar10 + 0x160)) {
                    *(int *)(iVar10 + 0x160) = *(int *)(iVar10 + 0x160) + 1;
                  }
                  else {
                    *(int *)(iVar10 + 0x160) = iVar6;
                  }
                }
                IRInst__setOperandSource(node,1,piVar4,0,uVar12);
                Block__insertInstBefore(*(undefined4 *)(node + 0x158),node,piVar4);
                return uVar5;
              }
              return uVar5;
            }
          }
        }
      }
    }
  }
switchD_0015a394_default:
  return 0;
}

/* Inst__takeOutCommonFactor @ 0x15a68c (3608 bytes) */
int Inst__takeOutCommonFactor(param_1, pass)
  int param_1;
  int pass;
{
  uint vectorFilledCount2;
  uint vectorFilledCount;
  undefined4 operandIndex11;
  uint *vector6;
  uint *vector5;
  int *inst9;
  int *inst7;
  int *newSource3;
  int *vector4;
  int *vector3;
  int *vector2;
  int *inst6;
  int *vector;
  int operandIndex9;
  int operandIndex8;
  int operandIndex7;
  int operandIndex6;
  int operandIndex5;
  int operandIndex3;
  int inst5;
  int inst4;
  int inst3;
  int inst2;
  int inst1;
  int operandIndex2;
  int allocation;
  int hasSingleUse;
  undefined4 operandRecord3;
  undefined4 sourceDef;
  int operandRecord2;
  int operandRecord;
  int sourceDef2;
  int *operandVReg2;
  int *operandVReg;
  bool bVar1;
  bool bVar2;
  int allocation2;
  int allocation3;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  int operandIndex;
  int operandVReg3;
  void *inst;
  undefined4 in_r6;
  undefined4 compilerCtx;
  undefined4 in_r8;
  code *a7;
  int iVar17;
  uint uVar18;
  int iVar19;
  int *piVar20;
  int *piVar21;
  int *piVar22;
  undefined4 uVar23;
  uint uVar24;
  uint *puVar25;
  int *inst8;
  int operandIndex4;
  int iStack00000018;
  undefined4 local_88;
  undefined4 local_84;
  int local_80;
  undefined4 newSource2;
  undefined4 newSource;
  int local_74;
  int local_70;
  uint set;
  int local_68;
  int operandIndex10;
  int *local_60;
  int local_5c;
  int local_58;
  int local_54;
  
  uVar18 = *(uint *)(*(int *)(param_1 + 0x10) + 4);
  iVar5 = uVar18 << 2;
  iStack00000018 = param_1;
  allocation2 = Arena__alloc(*(undefined4 *)(*(int *)(pass + 8) + 0x378),iVar5);
  allocation3 = Arena__alloc(*(undefined4 *)(*(int *)(pass + 8) + 0x378),iVar5);
  allocation = Arena__alloc(*(undefined4 *)(*(int *)(pass + 8) + 0x378),iVar5);
  if (0 < (int)uVar18) {
    uVar24 = 0;
    iVar17 = 0;
    iVar19 = 0;
    do {
      vector5 = *(uint **)(iStack00000018 + 0x10);
      if (uVar24 < *vector5) {
        vectorFilledCount = vector5[1];
        if (vectorFilledCount <= uVar24) {
          _memset(vectorFilledCount * 4 + vector5[2],0,(uVar24 - vectorFilledCount) * 4 + 4);
          vector5[1] = uVar24 + 1;
        }
        puVar7 = (undefined4 *)(iVar19 + vector5[2]);
      }
      else {
        puVar7 = (undefined4 *)Vector__elementRefGrow(vector5,uVar24);
      }
      uVar24 = uVar24 + 1;
      inst7 = (int *)*puVar7;
      bVar2 = false;
      *(int **)(iVar19 + allocation2) = inst7;
      *(undefined4 *)(iVar19 + allocation3) = 0;
      *(undefined4 *)(iVar19 + allocation) = 0;
      while ((((*(int *)(inst7[0x22] + 8) == 0x13 && ((inst7[5] & 0x200U) == 0)) &&
              (operandIndex8 = IRInst__hasSingleUse(inst7,pass), operandIndex8 != 0)) && (inst7[0x48] == 0))) {
        vector = (int *)inst7[4];
        if (*vector == 0) {
          puVar7 = (undefined4 *)Vector__elementRefGrow(vector,0);
        }
        else {
          if (vector[1] == 0) {
            *(undefined4 *)vector[2] = 0;
            vector[1] = 1;
          }
          puVar7 = (undefined4 *)vector[2];
        }
        inst6 = (int *)*puVar7;
        bVar1 = false;
        puVar25 = (uint *)(inst6 + 0x2e);
        for (operandIndex8 = 1; iVar8 = (**(code **)(*inst6 + 0x14))(inst6), operandIndex8 <= iVar8;
            operandIndex8 = operandIndex8 + 1) {
          operandVReg = (int *)IRInst__getOperandSource(inst6,operandIndex8);
          if (inst7 == operandVReg) {
            operandRecord2 = IRInst__getOperandRecord(inst6,operandIndex8);
            iVar8 = SelectWord__isIdentity(*(undefined4 *)(operandRecord2 + 0x10));
            if ((iVar8 == 0) || ((*puVar25 & 2) != 0)) {
              bVar1 = true;
            }
            *(int *)(iVar19 + allocation) = operandIndex8;
          }
          puVar25 = puVar25 + 6;
        }
        if (bVar1) break;
        bVar2 = true;
        inst7 = inst6;
      }
      if (bVar2) {
        if (((inst7[5] & 0x200U) != 0) ||
           ((*(int *)(inst7[0x22] + 8) != 0x12 && (*(int *)(inst7[0x22] + 8) != 0x14))))
        goto LAB_0015a760;
        *(undefined4 *)(iVar19 + allocation3) = inst7;
        iVar17 = iVar17 + 1;
      }
      else if (((*(int *)(inst7[0x22] + 8) == 0x14) && ((inst7[5] & 0x200U) == 0)) &&
              ((operandIndex8 = IRInst__getOperandSource(inst7,1), iStack00000018 == operandIndex8 ||
               (operandIndex8 = IRInst__getOperandSource(inst7,2), iStack00000018 == operandIndex8)))) {
        *(undefined4 *)(iVar19 + allocation3) = inst7;
        iVar8 = IRInst__getOperandSource(inst7,1);
        operandIndex8 = 2;
        if (iStack00000018 == iVar8) {
          operandIndex8 = 1;
        }
        iVar17 = iVar17 + 1;
        *(int *)(iVar19 + allocation) = operandIndex8;
      }
      else {
LAB_0015a760:
        *(undefined4 *)(iVar19 + allocation2) = 0;
      }
      iVar19 = iVar19 + 4;
    } while (uVar18 != uVar24);
    if (1 < iVar17) {
      iVar17 = 0;
      uVar23 = 0;
      do {
        iVar19 = iVar17 * 4;
        piVar21 = (int *)(allocation2 + iVar19);
        if ((*(int *)(allocation2 + iVar19) == 0) ||
           ((*(uint *)(*(int *)(allocation2 + iVar19) + 0x14) & 1) == 0)) {
LAB_0015a9bc:
          iVar17 = iVar17 + 1;
        }
        else {
          local_60 = (int *)(allocation3 + iVar19);
          operandIndex9 = 1;
          if ((*(uint *)(*(int *)(allocation3 + iVar19) + 0x14) & 1) == 0) goto LAB_0015a9bc;
          for (; iVar8 = (**(code **)(*(int *)*piVar21 + 0x14))((int *)*piVar21), operandIndex9 <= iVar8;
              operandIndex9 = operandIndex9 + 1) {
            iVar8 = IRInst__getOperandSource(*piVar21,operandIndex9);
            if (iStack00000018 == iVar8) {
              iVar8 = IRInst__getOperandRecord(*piVar21,operandIndex9);
              local_5c = *(int *)(iVar8 + 0x10);
              set = *(uint *)(operandIndex9 * 0x18 + *piVar21 + 0xa0) >> 1 & 1;
              local_68 = operandIndex9;
              goto LAB_0015aa4c;
            }
          }
          local_68 = 0;
          set = 0;
LAB_0015aa4c:
          local_70 = iVar17 + 1;
          iVar17 = local_70;
          if (local_70 < (int)uVar18) {
            iVar17 = local_70 * 4;
            piVar22 = (int *)(allocation3 + iVar17);
            piVar20 = (int *)(allocation2 + iVar17);
            operandIndex10 = 3 - local_68;
            piVar10 = (int *)(allocation + iVar17);
            iVar9 = 0;
            local_54 = operandIndex10 * 0x18 + 0x80;
            do {
              piVar11 = (int *)*piVar20;
              if ((((piVar11 != (int *)0x0) && ((piVar11[5] & 1U) != 0)) &&
                  ((*(uint *)(*piVar22 + 0x14) & 1) != 0)) &&
                 ((piVar11 != (int *)*piVar21 && (*local_60 == *piVar22)))) {
                if ((*(int *)(allocation + iVar19) != *piVar10) &&
                   (((*(int *)(*(int *)(*local_60 + 0x88) + 8) != 0x14 ||
                     (*(int *)(allocation + iVar19) == 3)) || (*piVar10 == 3)))) {
                  uVar24 = 0;
                  for (operandIndex2 = 1; iVar8 = (**(code **)(*piVar11 + 0x14))(piVar11), operandIndex2 <= iVar8;
                      operandIndex2 = operandIndex2 + 1) {
                    iVar8 = IRInst__getOperandSource(*piVar20,operandIndex2);
                    if (iStack00000018 == iVar8) {
                      iVar8 = IRInst__getOperandRecord(*piVar20,operandIndex2);
                      local_58 = *(int *)(iVar8 + 0x10);
                      piVar11 = (int *)*piVar20;
                      uVar24 = (uint)piVar11[operandIndex2 * 6 + 0x28] >> 1 & 1;
                      if ((local_58 == local_5c) && (uVar6 = set, set == uVar24))
                      goto LAB_0015abb0;
                    }
                    else {
                      piVar11 = (int *)*piVar20;
                    }
                  }
                  local_74 = 0;
                  uVar6 = uVar24;
                  operandIndex2 = local_74;
LAB_0015abb0:
                  local_74 = operandIndex2;
                  if ((local_58 == local_5c) && (set == uVar6)) {
                    *(int *)(pass + 0x1cc) = *(int *)(pass + 0x1cc) + 1;
                    inst1 = *piVar21;
                    if (inst1 != *local_60) {
                      vector2 = *(int **)(inst1 + 0x10);
                      if (*vector2 == 0) {
                        puVar7 = (undefined4 *)Vector__elementRefGrow(vector2,0);
                        inst1 = *piVar21;
                      }
                      else {
                        if (vector2[1] == 0) {
                          *(undefined4 *)vector2[2] = 0;
                          vector2[1] = 1;
                          inst1 = *piVar21;
                        }
                        puVar7 = (undefined4 *)vector2[2];
                      }
                      inst8 = (int *)*puVar7;
                      piVar13 = inst8 + 0x26;
                      newSource = IRInst__getOperandSource(inst1,operandIndex10);
                      operandRecord = IRInst__getOperandRecord(*piVar21,operandIndex10);
                      piVar11 = (int *)*piVar21;
                      iVar17 = *(int *)(operandRecord + 0x10);
                      uVar6 = *(uint *)((int)piVar11 + local_54 + 0x20);
                      uVar24 = piVar11[local_68 * 6 + 0x28];
                      (**(code **)(*piVar11 + 0xc))
                                (piVar11,1,*(undefined4 *)(pass + 8),in_r6,compilerCtx,in_r8,uVar6,
                                 *(code **)(*piVar11 + 0xc));
                      for (operandIndex5 = 1; iVar12 = (**(code **)(*inst8 + 0x14))(inst8),
                          operandIndex5 <= iVar12; operandIndex5 = operandIndex5 + 1) {
                        iVar12 = IRInst__getOperandSource(inst8,operandIndex5);
                        if (iVar12 == *piVar21) {
                          compilerCtx = *(undefined4 *)(pass + 8);
                          in_r6 = 1;
                          IRInst__setOperandSource(inst8,operandIndex5,newSource,1,compilerCtx);
                          if (operandIndex5 == 0) {
                            inst8[0x27] = iVar17;
                          }
                          else {
                            iVar12 = IRInst__getOperandRecord(inst8,operandIndex5);
                            *(int *)(iVar12 + 0x10) = iVar17;
                          }
                          IROperand__setModifierBits(piVar13 + 3,2,uVar6 >> 1 & 1);
                          IROperand__setModifierBits(piVar13 + 3,1,(uVar24 ^ uVar6) & 1 ^ piVar13[8] & 1U);
                        }
                        piVar13 = piVar13 + 6;
                      }
                    }
                    inst2 = *piVar20;
                    if (inst2 != *piVar22) {
                      vector3 = *(int **)(inst2 + 0x10);
                      if (*vector3 == 0) {
                        puVar7 = (undefined4 *)Vector__elementRefGrow(vector3,0);
                        inst2 = *piVar20;
                      }
                      else {
                        if (vector3[1] == 0) {
                          *(undefined4 *)vector3[2] = 0;
                          vector3[1] = 1;
                          inst2 = *piVar20;
                        }
                        puVar7 = (undefined4 *)vector3[2];
                      }
                      inst9 = (int *)*puVar7;
                      operandIndex6 = 3 - local_74;
                      piVar13 = inst9 + 0x26;
                      newSource2 = IRInst__getOperandSource(inst2,operandIndex6);
                      operandRecord = IRInst__getOperandRecord(*piVar20,operandIndex6);
                      piVar11 = (int *)*piVar20;
                      iVar17 = *(int *)(operandRecord + 0x10);
                      a7 = *(code **)(*piVar11 + 0xc);
                      uVar6 = piVar11[operandIndex6 * 6 + 0x28];
                      uVar24 = piVar11[local_74 * 6 + 0x28];
                      (*a7)(piVar11,1,*(undefined4 *)(pass + 8),in_r6,compilerCtx,in_r8,*piVar11,a7);
                      for (operandIndex7 = 1; iVar12 = (**(code **)(*inst9 + 0x14))(inst9),
                          operandIndex7 <= iVar12; operandIndex7 = operandIndex7 + 1) {
                        iVar12 = IRInst__getOperandSource(inst9,operandIndex7);
                        if (iVar12 == *piVar20) {
                          IRInst__setOperandSource(inst9,operandIndex7,newSource2,1,*(undefined4 *)(pass + 8));
                          if (operandIndex7 == 0) {
                            inst9[0x27] = iVar17;
                          }
                          else {
                            iVar12 = IRInst__getOperandRecord(inst9,operandIndex7);
                            *(int *)(iVar12 + 0x10) = iVar17;
                          }
                          IROperand__setModifierBits(piVar13 + 3,2,uVar6 >> 1 & 1);
                          IROperand__setModifierBits(piVar13 + 3,1,(uVar24 ^ uVar6) & 1 ^ piVar13[8] & 1U);
                        }
                        piVar13 = piVar13 + 6;
                      }
                    }
                    piVar11 = IRInst__create(0x13,*(undefined4 *)(pass + 8));
                    IRInst__setOperandSource(piVar11,1,iStack00000018,1,*(undefined4 *)(pass + 8));
                    operandRecord = IRInst__getOperandRecord(piVar11,1);
                    *(int *)(operandRecord + 0x10) = local_5c;
                    IROperand__setModifierBits(piVar11 + 0x29,2,set);
                    piVar11[0x26] = 0;
                    piVar11[0x25] = piVar11[0x53];
                    operandRecord = IRInst__getOperandRecord(*piVar22,0);
                    piVar11[0x27] = *(int *)(operandRecord + 0x10);
                    piVar11[0x48] = *(int *)(*piVar22 + 0x120);
                    piVar11[0x49] = *(int *)(*piVar22 + 0x124);
                    iVar17 = *piVar22;
                    iVar8 = *(int *)(*(int *)(iVar17 + 0x10) + 4);
                    uVar24 = iVar8 - 1;
                    if (-1 < (int)uVar24) {
                      iVar12 = uVar24 * 4;
                      local_80 = 0;
                      do {
                        vector6 = *(uint **)(iVar17 + 0x10);
                        if (uVar24 < *vector6) {
                          vectorFilledCount2 = vector6[1];
                          if (vectorFilledCount2 <= uVar24) {
                            _memset(vectorFilledCount2 * 4 + vector6[2],0,(uVar24 - vectorFilledCount2) * 4 + 4);
                            vector6[1] = uVar24 + 1;
                          }
                          piVar13 = (int *)(iVar12 + vector6[2]);
                        }
                        else {
                          piVar13 = (int *)Vector__elementRefGrow(vector6,uVar24);
                        }
                        inst3 = *piVar13;
                        operandIndex4 = *(int *)(inst3 + 0x84);
                        if ((*(uint *)(inst3 + 0x14) & 0x200) == 0) {
LAB_0015b040:
                          if (0 < operandIndex4) {
                            operandIndex = 1;
                            do {
                              operandVReg3 = IRInst__getOperandSource(inst3,operandIndex);
                              if (operandVReg3 == *piVar22) {
                                IRInst__setOperandSource(inst3,operandIndex,piVar11,1,*(undefined4 *)(pass + 8));
                                break;
                              }
                              operandIndex = operandIndex + 1;
                            } while (operandIndex <= operandIndex4);
                          }
                        }
                        else {
                          sourceDef2 = IRInst__getOperandSource(inst3,operandIndex4);
                          operandIndex4 = operandIndex4 + -1;
                          if (sourceDef2 != *piVar22) goto LAB_0015b040;
                          IRInst__setExtraOperandSource(inst3,piVar11,1,*(undefined4 *)(pass + 8));
                        }
                        uVar24 = uVar24 - 1;
                        iVar12 = iVar12 + -4;
                        local_80 = local_80 + 1;
                        if (iVar8 == local_80) break;
                        iVar17 = *piVar22;
                      } while( true );
                    }
                    operandRecord = IRInst__getOperandRecord(piVar11,0);
                    WriteMask__fromSelectWord(&local_88,*(undefined4 *)(operandRecord + 0x10));
                    SelectWord__maskUnused(&local_84,0x10203,local_88);
                    uVar23 = local_84;
                    operandRecord = IRInst__getOperandRecord(piVar11,2);
                    *(undefined4 *)(operandRecord + 0x10) = uVar23;
                    Block__insertInstAfter(*(undefined4 *)(*piVar22 + 0x158),*piVar22,piVar11);
                    if (*piVar21 == *local_60) {
                      newSource3 = (int *)*piVar22;
LAB_0015b134:
                      (**(code **)(*newSource3 + 0xc))(newSource3,1,*(undefined4 *)(pass + 8));
                      inst = IRInst__create(0x12,*(undefined4 *)(pass + 8));
                      sourceDef = IRInst__getOperandSource(*piVar22,3);
                      IRInst__setOperandSource(inst,2,sourceDef,1,*(undefined4 *)(pass + 8));
                      operandRecord3 = IRInst__getOperandRecord(*piVar22,3);
                      IRInst__getOrCreateOperandRecord(inst,2,operandRecord3,*(undefined4 *)(pass + 8));
                      if ((*piVar21 == *local_60) && (local_68 == 1)) {
                        inst4 = *piVar22;
LAB_0015b1ec:
                        sourceDef = IRInst__getOperandSource(inst4,2);
                        IRInst__setOperandSource(inst,1,sourceDef,1,*(undefined4 *)(pass + 8));
                        inst5 = *piVar22;
                        operandIndex11 = 2;
                      }
                      else {
                        inst4 = *piVar22;
                        if ((*piVar20 == inst4) && (local_74 == 1)) goto LAB_0015b1ec;
                        sourceDef = IRInst__getOperandSource(inst4,1);
                        IRInst__setOperandSource(inst,1,sourceDef,1,*(undefined4 *)(pass + 8));
                        inst5 = *piVar22;
                        operandIndex11 = 1;
                      }
                      operandRecord3 = IRInst__getOperandRecord(inst5,operandIndex11);
                      IRInst__getOrCreateOperandRecord(inst,1,operandRecord3,*(undefined4 *)(pass + 8));
                      IROperand__setModifierBits((int)inst + 0xa4,1,
                                   (*(uint *)(*piVar22 + 0xd0) ^ *(uint *)(*piVar22 + 0xb8)) & 1);
                      *(undefined4 *)((int)inst + 0x98) = 0;
                      *(undefined4 *)((int)inst + 0x94) = *(undefined4 *)((int)inst + 0x14c);
                      operandRecord = IRInst__getOperandRecord(*piVar22,0);
                      in_r6 = 1;
                      *(undefined4 *)((int)inst + 0x9c) = *(undefined4 *)(operandRecord + 0x10);
                      compilerCtx = *(undefined4 *)(pass + 8);
                      IRInst__setOperandSource(piVar11,2,inst,1,compilerCtx);
                      Block__insertInstBefore(piVar11[0x56],piVar11,inst);
                    }
                    else {
                      newSource3 = (int *)*piVar22;
                      if ((int *)*piVar20 == newSource3) goto LAB_0015b134;
                      compilerCtx = *(undefined4 *)(pass + 8);
                      in_r6 = 1;
                      IRInst__setOperandSource(piVar11,2,newSource3,1,compilerCtx);
                      *(undefined4 *)(*piVar22 + 0x120) = 0;
                      *(undefined4 *)(*piVar22 + 0x124) = 0;
                    }
                    *piVar20 = (int)piVar11;
                    *piVar22 = 0;
                    *piVar10 = 0;
                    while (newSource3 = piVar11, *(int *)(newSource3[0x22] + 8) == 0x13) {
                      uVar24 = newSource3[5];
                      if ((uVar24 & 0x200) != 0) goto LAB_0015b3f0;
                      hasSingleUse = IRInst__hasSingleUse(newSource3,pass);
                      if ((hasSingleUse == 0) || (newSource3[0x48] != 0)) break;
                      vector4 = (int *)newSource3[4];
                      if (*vector4 == 0) {
                        puVar7 = (undefined4 *)Vector__elementRefGrow(vector4,0);
                      }
                      else {
                        if (vector4[1] == 0) {
                          *(undefined4 *)vector4[2] = 0;
                          vector4[1] = 1;
                        }
                        puVar7 = (undefined4 *)vector4[2];
                      }
                      piVar11 = (int *)*puVar7;
                      bVar2 = false;
                      puVar25 = (uint *)(piVar11 + 0x2e);
                      for (operandIndex3 = 1; iVar8 = (**(code **)(*piVar11 + 0x14))(piVar11),
                          operandIndex3 <= iVar8; operandIndex3 = operandIndex3 + 1) {
                        operandVReg2 = (int *)IRInst__getOperandSource(piVar11,operandIndex3);
                        if (operandVReg2 == newSource3) {
                          operandRecord2 = IRInst__getOperandRecord(piVar11,operandIndex3);
                          iVar8 = SelectWord__isIdentity(*(undefined4 *)(operandRecord2 + 0x10));
                          if ((iVar8 == 0) || ((*puVar25 & 2) != 0)) {
                            bVar2 = true;
                          }
                          *piVar10 = operandIndex3;
                        }
                        puVar25 = puVar25 + 6;
                      }
                      if (bVar2) break;
                    }
                    uVar24 = newSource3[5];
LAB_0015b3f0:
                    if (((uVar24 & 0x200) == 0) &&
                       ((*(int *)(newSource3[0x22] + 8) == 0x12 ||
                        (*(int *)(newSource3[0x22] + 8) == 0x14)))) {
                      *piVar22 = (int)newSource3;
                    }
                    else {
                      *piVar20 = 0;
                    }
                    if ((*(uint *)(*piVar21 + 0x14) & 1) == 0) {
                      uVar23 = 1;
                      iVar17 = local_70;
                      break;
                    }
                    uVar23 = 1;
                  }
                }
              }
              iVar9 = iVar9 + 1;
              piVar20 = piVar20 + 1;
              piVar10 = piVar10 + 1;
              piVar22 = piVar22 + 1;
              iVar17 = local_70;
            } while (uVar18 - local_70 != iVar9);
          }
        }
        if ((int)uVar18 <= iVar17) {
          Arena__free(*(undefined4 *)(*(int *)(pass + 8) + 0x378),allocation);
          Arena__free(*(undefined4 *)(*(int *)(pass + 8) + 0x378),allocation3);
          Arena__free(*(undefined4 *)(*(int *)(pass + 8) + 0x378),allocation2);
          return uVar23;
        }
      } while( true );
    }
  }
  return 0;
}

/* FUN_0015b4a4 @ 0x15b4a4 (1044 bytes) */
int FUN_0015b4a4(inst, param_2)
  int inst;
  int param_2;
{
  uint vectorFilledCount2;
  uint vectorFilledCount;
  uint *vector2;
  int *inst2;
  int operandIndex;
  int inst1;
  int isIdentity;
  int operandRecord2;
  uint loopIndex;
  bool bVar1;
  byte bVar2;
  int iVar3;
  int *a0;
  int *piVar4;
  undefined4 *puVar5;
  int *operandVReg;
  int operandRecord;
  uint uVar8;
  int operandIndex2;
  uint uVar10;
  uint *vector;
  int iVar12;
  undefined4 local_48;
  byte local_44 [24];
  
  if (*(int *)(*(int *)(inst + 0x88) + 8) == 0x31) {
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    isIdentity = SelectWord__isIdentity(*(undefined4 *)(operandRecord2 + 0x10));
    if (isIdentity == 0) {
      a0 = (int *)IRInst__getOperandSource(inst,1);
      iVar3 = (**(code **)(*a0 + 0x5c))(a0);
      if (((iVar3 == 0) && ((a0[5] & 0x200U) == 0)) &&
         ((iVar3 = FUN_0011379c(*(undefined4 *)(param_2 + 8),a0), iVar3 != 0 ||
          (iVar3 = OpcodeTraits__flagBit8(*(undefined4 *)(a0[0x22] + 8),*(undefined4 *)(param_2 + 8)),
          iVar3 != 0)))) {
        operandRecord2 = IRInst__getOperandRecord(inst,1);
        uVar8 = 0;
        local_48 = *(undefined4 *)(operandRecord2 + 0x10);
        do {
          iVar3 = IRInst__getOperandRecord(inst,0);
          if ((((*(char *)(uVar8 + iVar3 + 0x10) != '\x01') &&
               (uVar10 = (uint)local_44[uVar8 - 4], uVar10 != 4)) && (uVar8 != uVar10)) &&
             (iVar3 = IRInst__getOperandRecord(a0,0), *(char *)(uVar10 + iVar3 + 0x10) != '\x01')) {
            return;
          }
          bVar1 = uVar8 != 3;
          uVar8 = uVar8 + 1;
        } while (bVar1);
        vector = (uint *)a0[4];
        uVar10 = 0;
        vectorFilledCount = vector[1];
        if (vectorFilledCount != 0) {
          do {
            if (uVar10 < *vector) {
              if (vectorFilledCount <= uVar10) {
                _memset(vectorFilledCount * 4 + vector[2],0,(uVar10 - vectorFilledCount) * 4 + 4);
                vector[1] = uVar10 + 1;
              }
              piVar4 = (int *)(uVar10 * 4 + vector[2]);
            }
            else {
              piVar4 = (int *)Vector__elementRefGrow(vector,uVar10);
            }
            inst1 = *piVar4;
            if (((*(uint *)(inst1 + 0x14) & 0x200) != 0) &&
               (piVar4 = (int *)IRInst__getOperandSource(inst1,*(undefined4 *)(inst1 + 0x84)), a0 == piVar4)) {
              return;
            }
            vector = (uint *)a0[4];
            uVar10 = uVar10 + 1;
            vectorFilledCount = vector[1];
          } while (uVar10 < vectorFilledCount);
        }
        *(int *)(param_2 + 0x164) = *(int *)(param_2 + 0x164) + 1;
        local_44[0] = 4;
        local_44[1] = 4;
        local_44[2] = 4;
        local_44[3] = 4;
        loopIndex = 0;
        IRInst__getOperandRecord(a0,0);
        piVar4 = a0;
        do {
          operandRecord2 = IRInst__getOperandRecord(inst,0);
          if (*(char *)(loopIndex + operandRecord2 + 0x10) != '\x01') {
            bVar2 = local_44[loopIndex - 4];
            uVar10 = (uint)bVar2;
            if ((uVar10 != 4) && (uVar10 != loopIndex)) {
              operandIndex2 = 1;
              iVar3 = FUN_0011379c(*(undefined4 *)(param_2 + 8),a0);
              if (iVar3 != 0) {
                for (; iVar3 = (**(code **)(*a0 + 0x14))(a0), operandIndex2 <= iVar3; operandIndex2 = operandIndex2 + 1) {
                  iVar3 = IRInst__getOperandRecord(a0,operandIndex2);
                  (**(code **)(*a0 + 0x88))(a0,operandIndex2,loopIndex,*(undefined1 *)(uVar10 + iVar3 + 0x10));
                }
              }
              operandRecord2 = IRInst__getOperandRecord(a0,0);
              if (*(char *)(loopIndex + operandRecord2 + 0x10) != '\0') {
                *(undefined1 *)(piVar4 + 0x27) = 0;
              }
              local_44[loopIndex] = bVar2;
            }
          }
          bVar1 = loopIndex != 3;
          piVar4 = (int *)((int)piVar4 + 1);
          loopIndex = loopIndex + 1;
        } while (bVar1);
        vector2 = (uint *)a0[4];
        uVar10 = 0;
        vectorFilledCount2 = vector2[1];
        if (vectorFilledCount2 != 0) {
          do {
            if (uVar10 < *vector2) {
              if (vectorFilledCount2 <= uVar10) {
                _memset(vectorFilledCount2 * 4 + vector2[2],0,(uVar10 - vectorFilledCount2) * 4 + 4);
                vector2[1] = uVar10 + 1;
              }
              puVar5 = (undefined4 *)(uVar10 * 4 + vector2[2]);
            }
            else {
              puVar5 = (undefined4 *)Vector__elementRefGrow(vector2,uVar10);
            }
            uVar10 = uVar10 + 1;
            inst2 = (int *)*puVar5;
            for (operandIndex = 1; operandIndex2 = (**(code **)(*inst2 + 0x14))(inst2), operandIndex <= operandIndex2;
                operandIndex = operandIndex + 1) {
              operandVReg = (int *)IRInst__getOperandSource(inst2,operandIndex);
              if (a0 == operandVReg) {
                operandIndex2 = 0;
                do {
                  operandRecord = IRInst__getOperandRecord(inst2,operandIndex);
                  iVar12 = 3;
                  if (*(byte *)(operandIndex2 + operandRecord + 0x10) == local_44[operandIndex2]) {
                    (**(code **)(*inst2 + 0x88))(inst2,operandIndex,operandIndex2,operandIndex2);
                  }
                  else {
                    do {
                      iVar12 = iVar12 + -1;
                    } while (iVar12 != 0);
                  }
                  bVar1 = operandIndex2 != 3;
                  operandIndex2 = operandIndex2 + 1;
                } while (bVar1);
              }
            }
            vector2 = (uint *)a0[4];
            vectorFilledCount2 = vector2[1];
          } while (uVar10 < vectorFilledCount2);
        }
      }
    }
  }
  return;
}

/* FUN_0015b8b8 @ 0x15b8b8 (188 bytes) */
int FUN_0015b8b8(param_1, param_2)
  int *param_1;
  int param_2;
{
  int operandRecord;
  int iVar1;
  int inst;
  
  inst = *param_1;
  while( true ) {
    if (((inst == 0) ||
        (((iVar1 = *(int *)(*(int *)(inst + 0x88) + 8), iVar1 != 0x3a && (iVar1 != 0x3b)) ||
         ((*(uint *)(inst + 0xb8) & 1) != 0)))) || (*(int *)(inst + 0x120) != 0)) {
      return 0;
    }
    operandRecord = IRInst__getOperandRecord(inst,0);
    iVar1 = SelectWord__splatComponent(*(undefined4 *)(operandRecord + 0x10));
    if (iVar1 < 0) {
      return 0;
    }
    if (iVar1 == param_2) break;
    if ((*(uint *)(inst + 0x14) & 0x200) == 0) {
      return 0;
    }
    inst = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
  }
  *param_1 = inst;
  return 1;
}

/* FUN_0015b974 @ 0x15b974 (972 bytes) */
int FUN_0015b974(inst, param_2, param_3, param_4, param_5)
  int inst;
  undefined4 *param_2;
  undefined4 *param_3;
  uint *param_4;
  uint *param_5;
{
  int *inst2;
  int uniformSourceConstant;
  undefined4 sourceDef;
  int operandRecord;
  int *operandVReg;
  int iVar1;
  undefined4 operandIndex;
  int *inst1;
  undefined4 srcIndex;
  uint uVar5;
  int *piVar6;
  int iVar7;
  int *local_68;
  int *local_64;
  undefined1 auStack_60 [4];
  float local_5c;
  longlong local_48;
  undefined4 local_40;
  uint uStack_3c;
  
  if (*(int *)(*(int *)(inst + 0x88) + 8) == 0x37) {
    operandRecord = IRInst__getOperandRecord(inst,0);
    iVar1 = SelectWord__splatComponent(*(undefined4 *)(operandRecord + 0x10));
    if ((((-1 < iVar1) && (local_68 = (int *)IRInst__getOperandSource(inst,1), local_68[0x48] == 0)) &&
        ((*(uint *)(inst + 0xb8) & 1) == 0)) && ((*(uint *)(inst + 0xb8) & 2) == 0)) {
      operandRecord = IRInst__getOperandRecord(inst,1);
      uVar5 = (uint)*(byte *)(operandRecord + 0x13);
      iVar7 = *(int *)(local_68[0x22] + 8);
      iVar1 = ((int (*)())FUN_0015b8b8)(&local_68,uVar5);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(*local_68 + 100))(local_68);
        if (iVar1 == 0) {
          if (iVar7 == 0x13) {
            if ((local_68[0x2e] & 1U) != 0) {
              return 0;
            }
            if ((local_68[0x2e] & 2U) != 0) {
              return 0;
            }
            if ((local_68[0x34] & 1U) != 0) {
              return 0;
            }
            if ((local_68[0x34] & 2U) != 0) {
              return 0;
            }
            local_64 = (int *)IRInst__getOperandSource(local_68,1);
            operandVReg = (int *)IRInst__getOperandSource(local_68,2);
            iVar1 = (**(code **)(*operandVReg + 0x48))(operandVReg);
            if (iVar1 == 0) {
              iVar1 = (**(code **)(*local_64 + 0x48))(local_64);
              if (iVar1 == 0) {
                return 0;
              }
              operandIndex = 2;
              srcIndex = 1;
              piVar6 = local_64;
              local_64 = operandVReg;
            }
            else {
              operandIndex = 1;
              srcIndex = 2;
              piVar6 = operandVReg;
            }
            operandRecord = IRInst__getOperandRecord(local_68,operandIndex);
            iVar1 = ((int (*)())FUN_0015b8b8)(&local_64,(uint)*(byte *)(uVar5 + operandRecord + 0x10));
            inst1 = local_68;
            if (iVar1 == 0) {
              return 0;
            }
            operandRecord = IRInst__getOperandRecord(local_68,0);
            uniformSourceConstant = IRInst__getUniformSourceConstant(inst1,srcIndex,*(undefined4 *)(operandRecord + 0x10),auStack_60);
            if (uniformSourceConstant == 0) {
              *param_3 = piVar6;
            }
            else {
              local_40 = 0x43300000;
              uVar5 = (uint)(int)local_5c;
              local_48 = (longlong)(int)uVar5;
              uStack_3c = uVar5 ^ 0x80000000;
              if (local_5c != (float)((double)CONCAT44(0x43300000,uStack_3c) - 4503601774854144.0))
              {
                return 0;
              }
              *param_4 = uVar5;
              *param_3 = 0;
            }
            sourceDef = IRInst__getOperandSource(local_64,1);
            *param_2 = sourceDef;
            inst2 = local_64;
            goto LAB_0015bc04;
          }
          if ((iVar7 != 0x12) && (iVar7 != 0x9b)) {
            return 0;
          }
          local_64 = (int *)IRInst__getOperandSource(local_68,1);
          operandVReg = (int *)IRInst__getOperandSource(local_68,2);
          if (operandVReg != local_64) {
            return 0;
          }
          if ((local_68[0x2e] & 1U) != 0) {
            return 0;
          }
          if ((local_68[0x2e] & 2U) != 0) {
            return 0;
          }
          if ((local_68[0x34] & 1U) != 0) {
            return 0;
          }
          if ((local_68[0x34] & 2U) != 0) {
            return 0;
          }
          operandRecord = IRInst__getOperandRecord(local_68,1);
          iVar7 = *(int *)(operandRecord + 0x10);
          operandRecord = IRInst__getOperandRecord(local_68,2);
          if (iVar7 != *(int *)(operandRecord + 0x10)) {
            return 0;
          }
          operandRecord = IRInst__getOperandRecord(local_68,1);
          iVar1 = ((int (*)())FUN_0015b8b8)(&local_64,(uint)*(byte *)(uVar5 + operandRecord + 0x10));
          if (iVar1 == 0) {
            return 0;
          }
          uVar5 = 2;
        }
        else {
          local_64 = (int *)IRInst__getOperandSource(local_68,1);
          if ((local_68[0x2e] & 1U) != 0) {
            return 0;
          }
          if ((local_68[0x2e] & 2U) != 0) {
            return 0;
          }
          iVar1 = ((int (*)())FUN_0015b8b8)(&local_64,uVar5);
          if (iVar1 == 0) {
            return 0;
          }
          uVar5 = 1 << (local_64[0x49] + local_68[0x49] & 0x3fU);
        }
        *param_4 = uVar5;
        *param_3 = 0;
        sourceDef = IRInst__getOperandSource(local_64,1);
        *param_2 = sourceDef;
        inst2 = local_64;
      }
      else {
        *param_4 = 1 << (local_68[0x49] & 0x3fU);
        *param_3 = 0;
        sourceDef = IRInst__getOperandSource(local_68,1);
        *param_2 = sourceDef;
        inst2 = local_68;
      }
LAB_0015bc04:
      operandRecord = IRInst__getOperandRecord(inst2,1);
      *param_5 = (uint)*(byte *)(operandRecord + 0x13);
      return 1;
    }
  }
  return 0;
}

/* Inst__mergeAddAndMadSharedOperands @ 0x15bd40 (2452 bytes) */
int Inst__mergeAddAndMadSharedOperands(node, pass)
  int node;
  int pass;
{
  int isMixResult4;
  int isMixResult3;
  int srcCount;
  int prevNode;
  int lanesLeft2;
  int allocatedRegister;
  int laneIdx;
  int addSrc2Resolved;
  int depthAboveBase;
  int addSrc1Resolved;
  int isMixResult2;
  int isMixResult1;
  int laneScan;
  int laneD;
  int laneC;
  int laneB;
  int laneA;
  int isMixResult;
  int madInst;
  int firstUnwrittenComponentResult;
  int operandRecord3;
  int sourceDef;
  int operandRecord2;
  int sourceDef2;
  int operandRecord;
  int *operandVReg;
  int *operandVReg4;
  bool moreLanes;
  uint madSrc2Negate;
  uint madSrc3Negate;
  uint madSrc1Negate;
  uint addSrc1Negate;
  uint addSrc2Negate;
  int nodeOpcode;
  uint madSrc1Abs;
  int otherOpcode;
  uint addSrc2Abs;
  int operandVReg5;
  int lanesLeft;
  int *mergedInst;
  int madSrc1Resolved;
  int madSrc2Resolved;
  int madSrc3Resolved;
  int addInst;
  int *operandVReg2;
  int *operandVReg3;
  int *literalInst;
  uint madSrc3Abs;
  uint addSrc1Abs;
  undefined4 madIndexForAddSrc1;
  undefined4 madIndexForAddSrc2;
  undefined4 freeMadIndex;
  uint madSrc2Abs;
  int *lanePtr;
  int mergedDestSelect;
  undefined4 madDestSelect;
  undefined4 addDestSelect;
  int addDestSelectCopy;
  undefined4 addSrc1Select;
  undefined4 addSrc2Select;
  undefined4 madFreeSelect;
  undefined4 lastOperandRecord;
  int lastOperandSource;
  undefined4 lastOperandRecord5;
  
  if ((*(uint *)(node + 0x14) & 0x200) == 0) {
    return 0;
  }
  operandVReg5 = IRInst__getOperandSource(node,*(undefined4 *)(node + 0x84));
  if (operandVReg5 == 0) {
    return 0;
  }
  if ((*(uint *)(*(int *)(*(int *)(pass + 8) + 0x30c) + 8) & 0x100) == 0) {
    return 0;
  }
  nodeOpcode = *(int *)(*(int *)(node + 0x88) + 8);
  otherOpcode = *(int *)(*(int *)(operandVReg5 + 0x88) + 8);
  if (nodeOpcode == 0x12) {
    madInst = operandVReg5;
    addInst = node;
    if (otherOpcode != 0x14) {
      return 0;
    }
  }
  else {
    if (nodeOpcode != 0x14) {
      return 0;
    }
    madInst = node;
    addInst = operandVReg5;
    if (otherOpcode != 0x12) {
      return 0;
    }
  }
  if (*(int *)(addInst + 0x120) != *(int *)(madInst + 0x120)) {
    return 0;
  }
  if (*(int *)(addInst + 0x124) != *(int *)(madInst + 0x124)) {
    return 0;
  }
  operandRecord3 = IRInst__getOperandRecord(addInst,0);
  addDestSelect = *(undefined4 *)(operandRecord3 + 0x10);
  operandRecord = IRInst__getOperandRecord(madInst,0);
  laneScan = 0;
  madDestSelect = *(undefined4 *)(operandRecord + 0x10);
  lanesLeft = 4;
  do {
    if ((*(char *)((int)&addDestSelect + laneScan) != '\x01') &&
       (*(char *)((int)&madDestSelect + laneScan) != '\x01')) {
      return 0;
    }
    laneScan = laneScan + 1;
    lanesLeft = lanesLeft + -1;
  } while (lanesLeft != 0);
  operandVReg4 = (int *)IRInst__getOperandSource(addInst,1);
  isMixResult1 = (**(code **)(*operandVReg4 + 0x60))(operandVReg4);
  if (isMixResult1 != 0) {
    return 0;
  }
  operandVReg4 = (int *)IRInst__getOperandSource(addInst,2);
  isMixResult2 = (**(code **)(*operandVReg4 + 0x60))(operandVReg4);
  if (isMixResult2 != 0) {
    return 0;
  }
  addSrc1Resolved = IRInst__getOperandSourceThroughMix(addInst,1);
  addSrc2Resolved = IRInst__getOperandSourceThroughMix(addInst,2);
  madSrc1Resolved = IRInst__getOperandSourceThroughMix(madInst,1);
  madSrc2Resolved = IRInst__getOperandSourceThroughMix(madInst,2);
  madSrc3Resolved = IRInst__getOperandSourceThroughMix(madInst,3);
  madSrc2Negate = *(uint *)(madInst + 0xd0) & 1;
  madSrc3Negate = *(uint *)(madInst + 0xe8) & 1;
  madSrc1Negate = *(uint *)(madInst + 0xb8) & 1;
  madSrc2Abs = *(uint *)(madInst + 0xd0) >> 1 & 1;
  madSrc3Abs = *(uint *)(madInst + 0xe8) >> 1 & 1;
  addSrc1Negate = *(uint *)(addInst + 0xb8) & 1;
  addSrc2Negate = *(uint *)(addInst + 0xd0) & 1;
  madSrc1Abs = *(uint *)(madInst + 0xb8) >> 1 & 1;
  addSrc1Abs = *(uint *)(addInst + 0xb8) >> 1 & 1;
  addSrc2Abs = *(uint *)(addInst + 0xd0) >> 1 & 1;
  if ((((addSrc1Resolved == madSrc1Resolved) && (addSrc2Resolved == madSrc3Resolved)) && (madSrc1Abs == addSrc1Abs)) &&
     ((madSrc3Abs == addSrc2Abs && (madSrc3Negate == addSrc2Negate)))) {
    if (madSrc2Negate == 0) {
      if (madSrc1Negate != addSrc1Negate) goto LAB_0015bf6c;
    }
    else if (madSrc1Negate == addSrc1Negate) goto LAB_0015bf6c;
    madIndexForAddSrc1 = 1;
    madIndexForAddSrc2 = 3;
    freeMadIndex = 2;
    goto LAB_0015c078;
  }
LAB_0015bf6c:
  if (((addSrc1Resolved == madSrc2Resolved) && (addSrc2Resolved == madSrc3Resolved)) &&
     ((madSrc2Abs == addSrc1Abs && ((madSrc3Abs == addSrc2Abs && (madSrc3Negate == addSrc2Negate)))))) {
    if (madSrc1Negate == 0) {
      if (madSrc2Negate != addSrc1Negate) goto LAB_0015bfb0;
    }
    else if (madSrc2Negate == addSrc1Negate) goto LAB_0015bfb0;
    madIndexForAddSrc1 = 2;
    madIndexForAddSrc2 = 3;
    freeMadIndex = 1;
    goto LAB_0015c078;
  }
LAB_0015bfb0:
  if ((((addSrc2Resolved == madSrc1Resolved) && (addSrc1Resolved == madSrc3Resolved)) && (madSrc1Abs == addSrc2Abs)) &&
     ((madSrc3Abs == addSrc1Abs && (madSrc3Negate == addSrc1Negate)))) {
    if (madSrc2Negate == 0) {
      if (madSrc1Negate != addSrc2Negate) goto LAB_0015bff4;
    }
    else if (madSrc1Negate == addSrc2Negate) goto LAB_0015bff4;
    madIndexForAddSrc1 = 3;
    madIndexForAddSrc2 = 1;
    freeMadIndex = 2;
  }
  else {
LAB_0015bff4:
    if (addSrc2Resolved != madSrc2Resolved) {
      return 0;
    }
    if (addSrc1Resolved != madSrc3Resolved) {
      return 0;
    }
    if (madSrc2Abs != addSrc2Abs) {
      return 0;
    }
    if (madSrc3Abs != addSrc1Abs) {
      return 0;
    }
    if (madSrc3Negate != addSrc1Negate) {
      return 0;
    }
    if (madSrc1Negate == 0) {
      if (madSrc2Negate != addSrc2Negate) {
        return 0;
      }
    }
    else if (madSrc2Negate == addSrc2Negate) {
      return 0;
    }
    madIndexForAddSrc1 = 3;
    madIndexForAddSrc2 = 2;
    freeMadIndex = 1;
  }
LAB_0015c078:
  lastOperandRecord5 = 0;
  lastOperandRecord = 0;
  lastOperandSource = 0;
  if ((*(uint *)(operandVReg5 + 0x14) & 0x200) != 0) {
    IRInst__readLastOperand(operandVReg5,&lastOperandRecord);
  }
  depthAboveBase = *(int *)(addInst + 0x160) - *(int *)(pass + 0x478);
  if (depthAboveBase < 0) {
    depthAboveBase = 0;
  }
  if (addInst == node) {
    operandRecord = IRInst__getOperandRecord(addInst,0);
    addDestSelectCopy = *(int *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(addInst,1);
    addSrc1Select = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(addInst,2);
    addSrc2Select = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(madInst,freeMadIndex);
    madFreeSelect = *(undefined4 *)(operandRecord + 0x10);
    lanesLeft2 = 4;
    mergedDestSelect = addDestSelectCopy;
    laneIdx = 0;
    do {
      if (*(char *)((int)&madDestSelect + laneIdx) != '\x01') {
        *(char *)((int)&mergedDestSelect + laneIdx) = *(char *)((int)&madDestSelect + laneIdx);
      }
      laneIdx = laneIdx + 1;
      lanesLeft2 = lanesLeft2 + -1;
    } while (lanesLeft2 != 0);
    sourceDef2 = IRInst__getOperandSource(addInst,1);
    *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + -1;
    sourceDef2 = IRInst__getOperandSource(addInst,2);
    prevNode = *(int *)(addInst + 4);
    *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + -1;
    DList__unlink(addInst);
    mergedInst = (int *)IRInst__cloneInto(madInst,addInst,*(undefined4 *)(pass + 8),0);
    Block__insertInstAfter(*(undefined4 *)(prevNode + 0x158),prevNode,mergedInst);
    allocatedRegister = mergedInst[0x53];
    mergedInst[0x27] = mergedDestSelect;
    operandRecord2 = IRInst__getOperandRecord(mergedInst,0);
    *(int *)(operandRecord2 + 8) = allocatedRegister;
    operandVReg2 = (int *)IRInst__getOperandSource(madInst,madIndexForAddSrc1);
    operandVReg3 = (int *)IRInst__getOperandSource(madInst,madIndexForAddSrc2);
    operandVReg = (int *)IRInst__getOperandSource(madInst,freeMadIndex);
    isMixResult = (**(code **)(*operandVReg + 0x60))(operandVReg);
    if (isMixResult == 0) {
      literalInst = (int *)IRLoadConst__vslot73(0xa2,*(undefined4 *)(pass + 8));
      Block__insertInstBefore(mergedInst[0x56],mergedInst,literalInst);
      literalInst[0x21] = 1;
      literalInst[0x25] = literalInst[0x53];
      literalInst[0x26] = 0x36;
      literalInst[0x27] = mergedDestSelect;
      sourceDef = IRInst__getOperandSource(mergedInst,freeMadIndex);
      IRInst__setOperandSource(literalInst,1,sourceDef,0,*(undefined4 *)(pass + 8));
      if (*(int *)(pass + 0x478) < *(int *)(sourceDef + 0x160)) {
        *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
      }
      else {
        *(int *)(sourceDef + 0x160) = *(int *)(pass + 0x478) + 1;
      }
      laneA = 0;
      do {
        if (*(char *)((int)&madDestSelect + laneA) != '\x01') {
          (**(code **)(*literalInst + 0x88))(literalInst,1,laneA,*(undefined1 *)((int)&madFreeSelect + laneA));
          (**(code **)(*mergedInst + 0x88))(mergedInst,freeMadIndex,laneA,laneA);
        }
        moreLanes = laneA != 3;
        laneA = laneA + 1;
      } while (moreLanes);
      literalInst[0x21] = 2;
      laneB = 0;
      ((void (*)())IRInst__makeLiteralVec4Float)(literalInst,pass,2,1.0,1.0,1.0,1.0);
      do {
        if (*(char *)((int)&addDestSelectCopy + laneB) != '\x01') {
          (**(code **)(*literalInst + 0x88))(literalInst,1,laneB,4);
          (**(code **)(*literalInst + 0x88))(literalInst,2,laneB,laneB);
        }
        moreLanes = laneB != 3;
        laneB = laneB + 1;
      } while (moreLanes);
      IRInst__setOperandSource(mergedInst,freeMadIndex,literalInst,0,*(undefined4 *)(pass + 8));
      literalInst[0x58] = *(int *)(pass + 0x478) + 1;
    }
    else {
      srcCount = operandVReg[0x21];
      laneC = 0;
      lanePtr = operandVReg;
      do {
        if (*(char *)((int)&addDestSelectCopy + laneC) != '\x01') {
          srcCount = srcCount + 1;
          operandVReg[0x21] = srcCount;
          ((void (*)())IRInst__makeLiteralVec4Float)(operandVReg,pass,srcCount,1.0,1.0,1.0,1.0);
          (**(code **)(*operandVReg + 0x88))(operandVReg,srcCount,laneC,laneC);
          *(undefined1 *)(lanePtr + 0x27) = 0;
        }
        moreLanes = laneC != 3;
        lanePtr = (int *)((int)lanePtr + 1);
        laneC = laneC + 1;
      } while (moreLanes);
      if (*(int *)(pass + 0x478) < operandVReg[0x58]) {
        operandVReg[0x58] = operandVReg[0x58] + 1;
      }
      else {
        operandVReg[0x58] = *(int *)(pass + 0x478) + 1;
      }
    }
    laneD = 0;
    do {
      if (*(char *)((int)&addDestSelectCopy + laneD) != '\x01') {
        isMixResult3 = (**(code **)(*operandVReg2 + 0x60))(operandVReg2);
        if (isMixResult3 == 0) {
          (**(code **)(*mergedInst + 0x88))
                    (mergedInst,madIndexForAddSrc1,laneD,*(undefined1 *)((int)&addSrc1Select + laneD));
        }
        else {
          operandRecord2 = IRInst__getOperandRecord(operandVReg2,0);
          firstUnwrittenComponentResult = SelectWord__firstUnwrittenComponent(*(undefined4 *)(operandRecord2 + 0x10));
          (**(code **)(*operandVReg2 + 0x88))(operandVReg2,1,firstUnwrittenComponentResult,*(undefined1 *)((int)&addSrc1Select + laneD));
          (**(code **)(*mergedInst + 0x88))(mergedInst,madIndexForAddSrc1,laneD,firstUnwrittenComponentResult);
          *(undefined1 *)((int)operandVReg2 + firstUnwrittenComponentResult + 0x9c) = 0;
        }
        isMixResult4 = (**(code **)(*operandVReg3 + 0x60))(operandVReg3);
        if (isMixResult4 == 0) {
          (**(code **)(*mergedInst + 0x88))
                    (mergedInst,madIndexForAddSrc2,laneD,*(undefined1 *)((int)&addSrc2Select + laneD));
        }
        else {
          operandRecord2 = IRInst__getOperandRecord(operandVReg3,0);
          firstUnwrittenComponentResult = SelectWord__firstUnwrittenComponent(*(undefined4 *)(operandRecord2 + 0x10));
          (**(code **)(*operandVReg3 + 0x88))(operandVReg3,1,firstUnwrittenComponentResult,*(undefined1 *)((int)&addSrc2Select + laneD));
          (**(code **)(*mergedInst + 0x88))(mergedInst,madIndexForAddSrc2,laneD,firstUnwrittenComponentResult);
          *(undefined1 *)((int)operandVReg3 + firstUnwrittenComponentResult + 0x9c) = 0;
        }
        (**(code **)(*mergedInst + 0x88))(mergedInst,freeMadIndex,laneD,laneD);
      }
      moreLanes = laneD != 3;
      laneD = laneD + 1;
    } while (moreLanes);
    if (*(int *)(pass + 0x478) < operandVReg2[0x58]) {
      operandVReg2[0x58] = operandVReg2[0x58] + 1;
    }
    else {
      operandVReg2[0x58] = *(int *)(pass + 0x478) + 1;
    }
    if (*(int *)(pass + 0x478) < operandVReg3[0x58]) {
      operandVReg3[0x58] = operandVReg3[0x58] + 1;
    }
    else {
      operandVReg3[0x58] = *(int *)(pass + 0x478) + 1;
    }
    if (lastOperandSource != 0) {
      IRInst__setLastOperandFromRecord(mergedInst,&lastOperandRecord,0,*(undefined4 *)(pass + 8));
      if (*(int *)(pass + 0x478) < *(int *)(lastOperandSource + 0x160)) {
        *(int *)(lastOperandSource + 0x160) = *(int *)(lastOperandSource + 0x160) + 1;
      }
      else {
        *(int *)(lastOperandSource + 0x160) = *(int *)(pass + 0x478) + 1;
      }
    }
    mergedInst[0x58] = depthAboveBase + *(int *)(pass + 0x478);
    IRInst__dropCounterAndDeleteIfUnused(operandVReg5,*(undefined4 *)(pass + 8));
  }
  return 0;
}

/* Inst__collapseAlgebraic_0015c6d4 @ 0x15c6d4 (2012 bytes) */
int Inst__collapseAlgebraic_0015c6d4(inst, program)
  int *inst;
  int program;
{
  undefined4 compilerCtx;
  int operandIndex;
  int uniformSourceConstant;
  int hasSingleUse;
  int splitRgbAlphaEnabled;
  int operandRecord5;
  int sourceDef2;
  int sourceDef;
  int operandRecord3;
  int operandRecord4;
  uint loopIndex;
  bool bVar1;
  bool bVar2;
  float fVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  uint vectorFilledCount;
  int *piVar8;
  int *piVar9;
  int operandRecord;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  undefined4 uVar14;
  int iVar15;
  uint loopIndex2;
  uint uVar17;
  uint *vector;
  double fparam_1;
  undefined8 operandRecord2;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 auStack_78 [4];
  float local_74;
  
  if ((inst[5] & 0x200U) == 0) {
    return 0;
  }
  operandIndex = IRInst__getOperandSource(inst,inst[0x21]);
  if (operandIndex == 0) {
    return 0;
  }
  if ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x100) == 0) {
    return 0;
  }
  iVar15 = *(int *)(inst[0x22] + 8);
  if (2 < iVar15 - 0x12U) {
    return 0;
  }
  if (inst[0x48] != 0) {
    return 0;
  }
  uVar17 = 1;
  if (inst[0x49] != 0) {
    return 0;
  }
LAB_0015c82c:
  iVar6 = (**(code **)(*inst + 0x14))(inst);
  if (iVar6 < (int)uVar17) {
    return 0;
  }
  sourceDef2 = IRInst__getOperandSource(inst,uVar17);
  if ((sourceDef2 == operandIndex) && ((inst[uVar17 * 6 + 0x28] & 2U) == 0)) {
    if (iVar15 == 0x12) {
      if ((inst[uVar17 * 6 + 0x28] & 1U) == 0) {
        uVar11 = uVar17 ^ 3;
        uVar13 = 0xffffffff;
LAB_0015c79c:
        if ((int)uVar17 < 0) {
          return 0;
        }
        uVar12 = 0xffffffff;
LAB_0015c880:
        operandRecord3 = IRInst__getOperandRecord(inst,0);
        local_88 = *(int *)(operandRecord3 + 0x10);
        operandRecord2 = IRInst__getOperandRecord(inst,uVar17);
        local_84 = *(undefined4 *)((int)((ulonglong)operandRecord2 >> 0x20) + 0x10);
        iVar5 = (**(code **)(*inst + 0x14))
                          (inst,(int)operandRecord2,in_r5,in_r6,in_r7,in_r8,*(code **)(*inst + 0x14));
        operandRecord3 = IRInst__getOperandRecord(inst,iVar5 + 1);
        local_80 = *(undefined4 *)(operandRecord3 + 0x10);
        splitRgbAlphaEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x30);
        if (splitRgbAlphaEnabled != 0) {
          if ((char)local_88 == '\0') {
            return 0;
          }
          if ((char)local_80 != '\x04') {
            return 0;
          }
        }
        iVar5 = 0;
        iVar15 = 4;
        do {
          if (*(char *)((int)&local_88 + iVar5) == '\0') {
            if (*(char *)((int)&local_80 + iVar5) != '\x04') {
              return 0;
            }
          }
          else if (*(char *)((int)&local_80 + iVar5) != '\x04') {
            *(undefined1 *)((int)&local_88 + iVar5) = 0;
            *(char *)((int)&local_84 + iVar5) = (char)iVar5;
          }
          uVar14 = local_84;
          iVar5 = iVar5 + 1;
          iVar15 = iVar15 + -1;
        } while (iVar15 != 0);
        operandRecord3 = IRInst__getOperandRecord(inst,uVar17);
        *(undefined4 *)(operandRecord3 + 0x10) = uVar14;
        inst[0x27] = local_88;
        sourceDef = IRInst__getOperandSource(inst,uVar17);
        *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
        compilerCtx = *(undefined4 *)(program + 8);
        uVar17 = *(uint *)(program + 0x30) >> 7 & 1;
        if (uVar17 != 0) {
          sourceDef = IRInst__getOperandSource(inst,inst[0x21]);
          vector = *(uint **)(sourceDef + 0x10);
          vectorFilledCount = vector[1];
          if (0 < (int)vectorFilledCount) {
            loopIndex2 = 0;
            do {
              if (loopIndex2 < *vector) {
                if (vectorFilledCount <= loopIndex2) {
                  _memset(vectorFilledCount * 4 + vector[2],0,(loopIndex2 - vectorFilledCount) * 4 + 4);
                  vector[1] = loopIndex2 + 1;
                }
                piVar8 = (int *)(loopIndex2 * 4 + vector[2]);
              }
              else {
                piVar8 = (int *)Vector__elementRefGrow(vector,loopIndex2);
              }
              if (inst == (int *)*piVar8) {
                Vector__removeAt(vector,loopIndex2);
                sourceDef = IRInst__getOperandSource(inst,inst[0x21]);
                *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
                break;
              }
              vectorFilledCount = vector[1];
              loopIndex2 = loopIndex2 + 1;
            } while ((int)loopIndex2 < (int)vectorFilledCount);
          }
        }
        loopIndex = 1;
        IRInst__setOperandSource(inst,inst[0x21],0,uVar17,compilerCtx);
        inst[0x21] = inst[0x21] + -1;
        inst[5] = inst[5] & 0xfffffdff;
        do {
          operandIndex = (**(code **)(*inst + 0x14))(inst);
          if (operandIndex < (int)loopIndex) {
            return 0;
          }
          if (loopIndex == uVar13) {
            fVar3 = 1.0;
LAB_0015ca9c:
            fparam_1 = (double)fVar3;
            piVar8 = (int *)IRInst__getOperandSource(inst,loopIndex);
            operandRecord3 = IRInst__getOperandRecord(inst,loopIndex);
            local_7c = *(undefined4 *)(operandRecord3 + 0x10);
            iVar5 = (**(code **)(*piVar8 + 0x60))(piVar8);
            if (iVar5 == 0) {
              operandIndex = 0;
              piVar9 = (int *)IRLoadConst__vslot73(0xa2,*(undefined4 *)(program + 8));
              Block__insertInstBefore(inst[0x56],inst,piVar9);
              piVar9[0x21] = 1;
              piVar9[0x25] = piVar9[0x53];
              piVar9[0x26] = 0x36;
              piVar9[0x27] = local_88;
              IRInst__setOperandSource(piVar9,1,piVar8,0,*(undefined4 *)(program + 8));
              piVar9[0x21] = 2;
              ((void (*)())IRInst__makeLiteralVec4Float)(piVar9,program,2,fparam_1,fparam_1,fparam_1,fparam_1);
              do {
                if (*(char *)((int)&local_88 + operandIndex) != '\x01') {
                  if (*(char *)((int)&local_80 + operandIndex) == '\x04') {
                    (**(code **)(*piVar9 + 0x88))(piVar9,1,operandIndex,auStack_78[operandIndex + -4]);
                    uVar14 = 2;
                    pcVar4 = *(code **)(*piVar9 + 0x88);
                  }
                  else {
                    (**(code **)(*piVar9 + 0x88))(piVar9,2,operandIndex,operandIndex);
                    uVar14 = 1;
                    pcVar4 = *(code **)(*piVar9 + 0x88);
                  }
                  (*pcVar4)(piVar9,uVar14,operandIndex,4);
                  (**(code **)(*inst + 0x88))(inst,loopIndex,operandIndex,operandIndex);
                }
                bVar1 = operandIndex != 3;
                operandIndex = operandIndex + 1;
              } while (bVar1);
              IRInst__setOperandSource(inst,loopIndex,piVar9,0,*(undefined4 *)(program + 8));
              piVar9[0x58] = *(int *)(program + 0x478) + 1;
            }
            else {
              hasSingleUse = IRInst__hasSingleUse(piVar8,program);
              if (hasSingleUse == 0) {
                piVar8 = (int *)IRInst__clone(piVar8,*(undefined4 *)(program + 8),0);
                Block__insertInstBefore(inst[0x56],inst,piVar8);
                piVar8[0x58] = *(int *)(program + 0x478) + 1;
              }
              operandIndex = piVar8[0x21];
              if (1 < operandIndex) {
                bVar1 = false;
                iVar15 = 2;
                do {
                  operandRecord3 = IRInst__getOperandRecord(piVar8,0);
                  uniformSourceConstant = IRInst__getUniformSourceConstant(piVar8,iVar15,*(undefined4 *)(operandRecord3 + 0x10),auStack_78);
                  if ((uniformSourceConstant != 0) && (fparam_1 == (double)local_74)) {
                    operandIndex = -1;
                    iVar6 = 0;
                    do {
                      operandRecord = IRInst__getOperandRecord(piVar8,iVar15);
                      if (*(char *)(iVar6 + operandRecord + 0x10) != '\x04') {
                        operandIndex = iVar6;
                      }
                      bVar2 = iVar6 != 3;
                      iVar6 = iVar6 + 1;
                    } while (bVar2);
                    iVar6 = 0;
                    do {
                      if (*(char *)((int)&local_80 + iVar6) != '\x04') {
                        bVar1 = true;
                        (**(code **)(*inst + 0x88))(inst,loopIndex,iVar6,operandIndex);
                      }
                      bVar2 = iVar6 != 3;
                      iVar6 = iVar6 + 1;
                    } while (bVar2);
                    if (bVar1) goto LAB_0015ce60;
                  }
                  operandIndex = piVar8[0x21];
                  iVar15 = iVar15 + 1;
                } while (iVar15 <= operandIndex);
                if (bVar1) goto LAB_0015ce60;
              }
              operandIndex = operandIndex + 1;
              piVar8[0x21] = operandIndex;
              ((void (*)())IRInst__makeLiteralVec4Float)(piVar8,program,operandIndex,fparam_1,fparam_1,fparam_1,fparam_1);
              operandRecord4 = IRInst__getOperandRecord(piVar8,operandIndex);
              *(undefined4 *)(operandRecord4 + 0x10) = 0x4040404;
              iVar15 = 0;
              do {
                operandRecord5 = IRInst__getOperandRecord(piVar8,0);
                if (*(char *)(iVar15 + operandRecord5 + 0x10) != '\0') {
                  (**(code **)(*piVar8 + 0x88))(piVar8,operandIndex,iVar15,iVar15);
                  *(undefined1 *)((int)piVar8 + iVar15 + 0x9c) = 0;
                  goto LAB_0015ce20;
                }
                bVar1 = iVar15 != 3;
                iVar15 = iVar15 + 1;
              } while (bVar1);
              iVar15 = -1;
LAB_0015ce20:
              operandIndex = 0;
              do {
                if (*(char *)((int)&local_80 + operandIndex) != '\x04') {
                  (**(code **)(*inst + 0x88))(inst,loopIndex,operandIndex,iVar15);
                }
                bVar1 = operandIndex != 3;
                operandIndex = operandIndex + 1;
              } while (bVar1);
            }
          }
          else if ((loopIndex == uVar11) || (loopIndex == uVar12)) {
            fVar3 = 0.0;
            goto LAB_0015ca9c;
          }
LAB_0015ce60:
          loopIndex = loopIndex + 1;
        } while( true );
      }
    }
    else if (iVar15 == 0x13) {
      if ((inst[0x2e] & 1U) == (inst[0x34] & 1U)) {
        uVar13 = uVar17 ^ 3;
        uVar11 = 0xffffffff;
        goto LAB_0015c79c;
      }
    }
    else if (iVar15 == 0x14) {
      if (uVar17 == 3) {
        if ((inst[0x3a] & 1U) == 0) {
          uVar17 = 3;
          uVar11 = 1;
          uVar12 = 2;
          uVar13 = 0xffffffff;
          goto LAB_0015c880;
        }
      }
      else if (((int)uVar17 < 3) && ((inst[0x2e] & 1U) == (inst[0x34] & 1U))) {
        uVar13 = uVar17 ^ 3;
        uVar11 = 3;
        goto LAB_0015c79c;
      }
    }
  }
  uVar17 = uVar17 + 1;
  goto LAB_0015c82c;
}

/* Inst__collapseAlgebraic_0015ceb0 @ 0x15ceb0 (3720 bytes) */
int Inst__collapseAlgebraic_0015ceb0(node, pass)
  int *node;
  int pass;
{
  uint trackUses;
  int *inst2;
  int *inst;
  int operandIndex4;
  int newSource3;
  int newSource2;
  int newSource;
  int operandIndex3;
  int operandIndex2;
  int afterInst2;
  int afterInst;
  int operandIndex;
  undefined4 sourceDef;
  undefined4 operandRecord;
  int sourceDef6;
  int operandRecord3;
  int sourceDef3;
  int operandRecord4;
  int sourceDef2;
  int operandRecord6;
  int sourceDef5;
  int operandRecord2;
  int sourceDef4;
  int operandRecord8;
  int operandRecord7;
  int operandRecord5;
  int *operandVReg3;
  int *operandVReg;
  int *operandVReg4;
  bool bVar1;
  char cVar2;
  bool bVar3;
  bool bVar4;
  code *pcVar5;
  int iVar6;
  int *a0;
  int iVar7;
  int *piVar8;
  int *piVar9;
  int *operandVReg2;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int iVar21;
  int iVar22;
  int *piVar23;
  int iVar24;
  int iVar25;
  int local_108;
  int local_104;
  int local_100;
  int local_fc;
  int local_f8;
  int local_f4 [3];
  int local_e8 [5];
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_8c;
  undefined4 local_88;
  int local_84;
  undefined4 local_74;
  int local_68;
  int *local_64;
  undefined *local_60;
  
  if ((node[5] & 0x200U) == 0) {
    return 0;
  }
  a0 = (int *)IRInst__getOperandSource(node,node[0x21]);
  if (a0 == (int *)0x0) {
    return 0;
  }
  if ((*(uint *)(*(int *)(*(int *)(pass + 8) + 0x30c) + 8) & 0x100) == 0) {
    return 0;
  }
  iVar24 = *(int *)(a0[0x22] + 8);
  if (*(int *)(node[0x22] + 8) == 0x12) {
    if (iVar24 == 0x12) {
      operandVReg = (int *)IRInst__getOperandSource(node,1);
      piVar9 = (int *)IRInst__getOperandSource(node,2);
      operandVReg2 = (int *)IRInst__getOperandSource(a0,1);
      piVar15 = (int *)IRInst__getOperandSource(a0,2);
      bVar1 = operandVReg == piVar15;
      if (bVar1) {
        bVar1 = piVar9 == operandVReg2;
        IRInst__swapOperands(a0,1,2,*(uint *)(pass + 8));
        bVar4 = true;
        bVar3 = false;
        piVar23 = operandVReg;
        piVar15 = operandVReg2;
      }
      else {
        piVar23 = piVar9;
        if (piVar9 == operandVReg2) {
          IRInst__swapOperands(node,1,2,*(uint *)(pass + 8));
          bVar4 = false;
          bVar3 = true;
          piVar9 = operandVReg;
        }
        else {
          bVar1 = piVar9 == piVar15;
          if (bVar1) {
            bVar1 = operandVReg == operandVReg2;
            IRInst__swapOperands(a0,1,2,*(uint *)(pass + 8));
            IRInst__swapOperands(node,1,2,*(uint *)(pass + 8));
            bVar4 = true;
            bVar3 = true;
            piVar15 = operandVReg2;
            piVar9 = operandVReg;
          }
          else {
            if (operandVReg != operandVReg2) {
              return 0;
            }
            bVar4 = false;
            bVar3 = false;
            piVar23 = operandVReg2;
          }
        }
      }
      operandRecord2 = IRInst__getOperandRecord(node,0);
      local_fc = *(int *)(operandRecord2 + 0x10);
      operandRecord2 = IRInst__getOperandRecord(a0,0);
      local_100 = *(int *)(operandRecord2 + 0x10);
      if ((((!bVar1) && (a0[0x49] == node[0x49])) && (a0[0x48] == node[0x48])) &&
         ((local_fc != 0x1010100 && (*(int *)(operandRecord2 + 0x10) != 0x1010100)))) {
        newSource3 = 4;
        local_64 = &local_100;
        iVar24 = 0;
        do {
          if ((*(char *)(iVar24 + (int)&local_100) != '\x01') &&
             (*(char *)((int)&local_fc + iVar24) != '\x01')) goto LAB_0015d1a4;
          iVar24 = iVar24 + 1;
          newSource3 = newSource3 + -1;
        } while (newSource3 != 0);
        if (((((a0[0x2e] & 1U) == (node[0x2e] & 1U)) && ((a0[0x34] & 1U) == (node[0x34] & 1U))
             ) && (((uint)a0[0x2e] >> 1 & 1) == ((uint)node[0x2e] >> 1 & 1))) &&
           (iVar24 = Inst__opcodeOrSourcesDiffer(piVar15,piVar9), iVar24 == 0)) {
          *(int *)(pass + 0x280) = *(int *)(pass + 0x280) + 1;
          SelectWord__mergeWrittenLanes(&local_68,local_100,local_fc);
          local_104 = local_68;
          piVar9 = (int *)((int (*)())IRInst__createWithConstantOperands)(2,local_68,piVar9,pass,*(undefined4 *)(pass + 8),1.0);
          if (*(int *)(pass + 0x478) < piVar15[0x58]) {
            piVar15[0x58] = piVar15[0x58] + 1;
          }
          else {
            piVar15[0x58] = *(int *)(pass + 0x478) + 1;
          }
          piVar15 = (int *)((int (*)())IRInst__createWithConstantOperands)(2,local_104,piVar15,pass,*(undefined4 *)(pass + 8),1.0
                                       );
          operandRecord2 = IRInst__getOperandRecord(node,2);
          uVar12 = *(undefined4 *)(operandRecord2 + 0x10);
          operandRecord2 = IRInst__getOperandRecord(piVar9,1);
          *(undefined4 *)(operandRecord2 + 0x10) = uVar12;
          operandRecord2 = IRInst__getOperandRecord(a0,2);
          uVar12 = *(undefined4 *)(operandRecord2 + 0x10);
          operandRecord2 = IRInst__getOperandRecord(piVar15,1);
          *(undefined4 *)(operandRecord2 + 0x10) = uVar12;
          local_a0 = 0;
          local_9c = 0;
          local_8c = 0;
          local_e8[0] = 0;
          local_e8[1] = 0;
          local_d4 = 0;
          local_b8 = 0;
          local_b4 = 0;
          local_a4 = 0;
          local_d0 = 0;
          local_cc = 0;
          local_bc = 0;
          operandRecord = IRInst__getOperandRecord(a0,1);
          IROperand__copyFrom(&local_a0,operandRecord);
          operandRecord = IRInst__getOperandRecord(a0,2);
          IROperand__copyFrom(local_e8,operandRecord);
          operandRecord = IRInst__getOperandRecord(node,1);
          IROperand__copyFrom(&local_b8,operandRecord);
          operandRecord = IRInst__getOperandRecord(node,2);
          IROperand__copyFrom(&local_d0,operandRecord);
          operandRecord2 = IRInst__getOperandRecord(node,1);
          local_f8 = *(int *)(operandRecord2 + 0x10);
          operandRecord2 = IRInst__getOperandRecord(a0,1);
          local_108 = *(int *)(operandRecord2 + 0x10);
          local_f4[0] = 0;
          local_f4[1] = 0;
          local_f4[2] = 0;
          IRInst__saveCounters(node,local_f4,0xffffffff);
          local_88 = 0;
          local_84 = 0;
          local_74 = 0;
          if ((a0[5] & 0x200U) != 0) {
            IRInst__readLastOperand(a0,&local_88);
          }
          afterInst2 = node[1];
          DList__unlink(node);
          IRInst__reinitAsTrinary(node,0x14,*(undefined4 *)(pass + 8));
          Block__insertInstAfter(*(undefined4 *)(afterInst2 + 0x158),afterInst2,node);
          IRInst__restoreCounters(node,local_f4);
          iVar24 = a0[0x49];
          node[0x48] = a0[0x48];
          node[0x49] = iVar24;
          operandRecord = IRInst__getOperandRecord(node,3);
          IROperand__copyFrom(operandRecord,&local_b8);
          operandRecord = IRInst__getOperandRecord(node,1);
          IROperand__copyFrom(operandRecord,&local_d0);
          operandRecord = IRInst__getOperandRecord(node,2);
          IROperand__copyFrom(operandRecord,local_e8);
          IRInst__setOperandSource(node,1,piVar9,0,*(undefined4 *)(pass + 8));
          IRInst__setOperandSource(node,2,piVar15,0,*(undefined4 *)(pass + 8));
          IROperand__setModifierBits(node + 0x29,1,0);
          node[0x26] = 0;
          iVar24 = 0;
          node[0x25] = node[0x53];
          node[0x27] = local_104;
          do {
            if (*(char *)((int)&local_104 + iVar24) == '\0') {
              (**(code **)(*node + 0x88))(node,1,iVar24,iVar24);
              (**(code **)(*node + 0x88))(node,2,iVar24,iVar24);
              operandRecord3 = IRInst__getOperandRecord(piVar15,1);
              cVar2 = *(char *)(iVar24 + operandRecord3 + 0x10);
              newSource3 = IRInst__getOperandRecord(piVar9,1);
              if (cVar2 == '\x04') {
                if (*(char *)(iVar24 + newSource3 + 0x10) == '\x04') goto LAB_0015d5cc;
                (**(code **)(*piVar15 + 0x88))(piVar15,2,iVar24,iVar24);
                piVar8 = &local_f8;
                pcVar5 = *(code **)(*node + 0x88);
              }
              else {
                (**(code **)(*piVar9 + 0x88))(piVar9,2,iVar24,iVar24);
                piVar8 = &local_108;
                pcVar5 = *(code **)(*node + 0x88);
              }
              (*pcVar5)(node,3,iVar24,*(undefined1 *)(iVar24 + (int)piVar8));
            }
            else {
              (**(code **)(*node + 0x88))(node,1,iVar24,4);
              (**(code **)(*node + 0x88))(node,2,iVar24,4);
              (**(code **)(*node + 0x88))(node,3,iVar24,4);
            }
LAB_0015d5cc:
            bVar1 = iVar24 == 3;
            iVar24 = iVar24 + 1;
            if (bVar1) {
              Block__insertInstBefore(node[0x56],node,piVar15);
              Block__insertInstBefore(node[0x56],node,piVar9);
              if (local_84 != 0) {
                IRInst__setLastOperandFromRecord(node,&local_88,0,*(undefined4 *)(pass + 8));
                if (*(int *)(pass + 0x478) < *(int *)(local_84 + 0x160)) {
                  *(int *)(local_84 + 0x160) = *(int *)(local_84 + 0x160) + 1;
                }
                else {
                  *(int *)(local_84 + 0x160) = *(int *)(pass + 0x478) + 1;
                }
              }
              for (operandIndex2 = 1; newSource3 = (**(code **)(*a0 + 0x14))(a0), operandIndex2 <= newSource3;
                  operandIndex2 = operandIndex2 + 1) {
                operandVReg = (int *)IRInst__getOperandSource(a0,operandIndex2);
                if ((((a0[5] & 1U) == 0) ||
                    (newSource3 = (**(code **)(*operandVReg + 0x5c))(operandVReg), newSource3 == 0)) ||
                   (newSource3 = IRInst__hasSingleUse(operandVReg,pass), newSource3 != 0)) {
                  newSource3 = (**(code **)(*operandVReg + 0x60))(operandVReg);
                  if (((newSource3 != 0) && ((a0[5] & 1U) == 0)) && (piVar23 != operandVReg)) {
                    IRInst__dropCounterAndDeleteIfUnused(operandVReg,*(undefined4 *)(pass + 8));
                  }
                }
                else {
                  IRInst__hasTwoUses(operandVReg,pass);
                  uVar17 = *(uint *)(pass + 0x30) >> 7 & 1;
                  newSource3 = IRInst__cloneIfPresub(operandVReg,pass,uVar17);
                  IRInst__setOperandSource(a0,operandIndex2,newSource3,0,*(undefined4 *)(pass + 8));
                  if (uVar17 == 0) {
                    if (*(int *)(pass + 0x478) < *(int *)(newSource3 + 0x160)) {
                      *(int *)(newSource3 + 0x160) = *(int *)(newSource3 + 0x160) + 1;
                    }
                    else {
                      *(int *)(newSource3 + 0x160) = *(int *)(pass + 0x478) + 1;
                    }
                  }
                  operandVReg[0x58] = operandVReg[0x58] + -1;
                }
              }
              operandVReg = (int *)IRInst__getOperandSource(piVar9,1);
              iVar24 = (**(code **)(*operandVReg + 0x60))(operandVReg);
              if (iVar24 != 0) {
                sourceDef = IRInst__getOperandSource(piVar9,1);
                FUN_0010c670(sourceDef,piVar9,*(undefined4 *)(pass + 8));
              }
              operandVReg3 = (int *)IRInst__getOperandSource(piVar15,1);
              iVar24 = (**(code **)(*operandVReg3 + 0x60))(operandVReg3);
              if (iVar24 != 0) {
                sourceDef = IRInst__getOperandSource(piVar15,1);
                FUN_0010c670(sourceDef,piVar15,*(undefined4 *)(pass + 8));
              }
              IRInst__dropCounterAndDeleteIfUnused(a0,*(undefined4 *)(pass + 8));
              if (bVar4) {
                IRInst__swapOperands(a0,1,2,*(uint *)(pass + 8));
                return 1;
              }
              return 1;
            }
          } while( true );
        }
      }
LAB_0015d1a4:
      if (bVar4) {
        IRInst__swapOperands(a0,1,2,*(uint *)(pass + 8));
      }
      if (!bVar3) {
        return 0;
      }
      IRInst__swapOperands(node,1,2,*(uint *)(pass + 8));
      return 0;
    }
    iVar7 = (**(code **)(*a0 + 100))(a0);
    inst = a0;
    inst2 = node;
    if (iVar7 != 0) goto LAB_0015cf80;
  }
  iVar7 = (**(code **)(*node + 100))(node);
  if (iVar7 == 0) {
    return 0;
  }
  inst = node;
  inst2 = a0;
  if (iVar24 != 0x12) {
    return 0;
  }
LAB_0015cf80:
  sourceDef5 = IRInst__getOperandSource(inst,1);
  sourceDef6 = IRInst__getOperandSource(inst2,1);
  if (sourceDef5 == sourceDef6) {
    operandIndex3 = 1;
    operandIndex4 = 2;
  }
  else {
    sourceDef5 = IRInst__getOperandSource(inst,1);
    sourceDef6 = IRInst__getOperandSource(inst2,2);
    if (sourceDef5 != sourceDef6) {
      return 0;
    }
    operandIndex3 = 2;
    operandIndex4 = 1;
  }
  operandRecord5 = IRInst__getOperandRecord(node,0);
  local_108 = *(int *)(operandRecord5 + 0x10);
  operandRecord5 = IRInst__getOperandRecord(a0,0);
  local_104 = *(int *)(operandRecord5 + 0x10);
  if ((a0[0x49] == node[0x49]) && (a0[0x48] == node[0x48])) {
    if (((inst[0x2e] & 1U) == (inst2[operandIndex3 * 6 + 0x28] & 1U)) &&
       (((uint)inst[0x2e] >> 1 & 1) == ((uint)inst2[operandIndex3 * 6 + 0x28] >> 1 & 1))) {
      iVar6 = 0;
      iVar25 = 4;
      do {
        if ((*(char *)((int)&local_104 + iVar6) != '\x01') &&
           (*(char *)((int)&local_108 + iVar6) != '\x01')) {
          return 0;
        }
        iVar6 = iVar6 + 1;
        iVar25 = iVar25 + -1;
      } while (iVar25 != 0);
      if ((local_108 != 0x1010100) && (*(int *)(operandRecord5 + 0x10) != 0x1010100)) {
        *(int *)(pass + 0x280) = *(int *)(pass + 0x280) + 1;
        iVar11 = node[0x58] - *(int *)(pass + 0x478);
        trackUses = *(uint *)(pass + 0x30) >> 7 & 1;
        if (iVar11 < 0) {
          iVar11 = 0;
        }
        iVar25 = 4;
        iVar18 = node[4];
        iVar19 = node[0x53];
        iVar20 = node[0x26];
        iVar21 = node[0x48];
        iVar6 = 0;
        iVar22 = node[0x49];
        local_64 = &local_100;
        local_100 = local_108;
        do {
          if (*(char *)((int)&local_104 + iVar6) != '\x01') {
            *(char *)(iVar6 + (int)&local_100) = *(char *)((int)&local_104 + iVar6);
          }
          iVar6 = iVar6 + 1;
          iVar25 = iVar25 + -1;
        } while (iVar25 != 0);
        operandRecord6 = IRInst__getOperandRecord(inst2,operandIndex4);
        iVar6 = 0;
        local_fc = *(int *)(operandRecord6 + 0x10);
        iVar25 = 4;
        do {
          if (*(char *)(iVar6 + (int)local_64) == '\0') {
            *(char *)((int)&local_fc + iVar6) = (char)iVar6;
          }
          iVar6 = iVar6 + 1;
          iVar25 = iVar25 + -1;
        } while (iVar25 != 0);
        operandRecord4 = IRInst__getOperandRecord(inst2,operandIndex3);
        local_e8[0] = *(int *)(operandRecord4 + 0x10);
        operandRecord6 = IRInst__getOperandRecord(inst,1);
        iVar6 = 0;
        local_f8 = *(int *)(operandRecord6 + 0x10);
        iVar25 = 4;
        do {
          if (*(char *)((int)local_e8 + iVar6) == '\x04') {
            *(undefined1 *)((int)local_e8 + iVar6) = *(undefined1 *)((int)&local_f8 + iVar6);
          }
          iVar6 = iVar6 + 1;
          iVar25 = iVar25 + -1;
        } while (iVar25 != 0);
        sourceDef = IRInst__getOperandSource(inst2,operandIndex4);
        newSource = IRInst__cloneIfPresub(sourceDef,pass,trackUses);
        sourceDef2 = IRInst__getOperandSource(inst2,operandIndex3);
        iVar13 = IRLoadConst__vslot73(0xa2,*(undefined4 *)(pass + 8));
        Block__insertInstBefore(node[0x56],node,iVar13);
        *(undefined4 *)(iVar13 + 0x84) = 1;
        *(undefined4 *)(iVar13 + 0x94) = *(undefined4 *)(iVar13 + 0x14c);
        *(undefined4 *)(iVar13 + 0x98) = 0x36;
        *(int *)(iVar13 + 0x9c) = local_100;
        IRInst__setOperandSource(iVar13,1,newSource,0,*(undefined4 *)(pass + 8));
        operandRecord7 = IRInst__getOperandRecord(inst2,operandIndex4);
        uVar12 = *(undefined4 *)(operandRecord7 + 0x10);
        operandRecord7 = IRInst__getOperandRecord(iVar13,1);
        *(undefined4 *)(operandRecord7 + 0x10) = uVar12;
        if (*(int *)(pass + 0x478) < *(int *)(newSource + 0x160)) {
          *(int *)(newSource + 0x160) = *(int *)(newSource + 0x160) + 1;
        }
        else {
          *(int *)(newSource + 0x160) = *(int *)(pass + 0x478) + 1;
        }
        *(undefined4 *)(iVar13 + 0x84) = 2;
        ((void (*)())IRInst__makeLiteralVec4Float)(iVar13,pass,2,0.0,0.0,0.0,0.0);
        operandRecord4 = IRInst__getOperandRecord(inst,1);
        uVar12 = *(undefined4 *)(operandRecord4 + 0x10);
        operandRecord4 = IRInst__getOperandRecord(iVar13,2);
        *(undefined4 *)(operandRecord4 + 0x10) = uVar12;
        sourceDef3 = IRInst__getOperandSource(iVar13,2);
        if (*(int *)(pass + 0x478) < *(int *)(sourceDef3 + 0x160)) {
          *(int *)(sourceDef3 + 0x160) = *(int *)(sourceDef3 + 0x160) + 1;
        }
        else {
          *(int *)(sourceDef3 + 0x160) = *(int *)(pass + 0x478) + 1;
        }
        *(undefined4 *)(iVar13 + 0x160) = *(undefined4 *)(pass + 0x478);
        operandVReg4 = (int *)IRInst__getOperandSource(iVar13,1);
        iVar6 = (**(code **)(*operandVReg4 + 0x60))(operandVReg4);
        if (iVar6 != 0) {
          sourceDef = IRInst__getOperandSource(iVar13,1);
          FUN_0010c670(sourceDef,iVar13,*(undefined4 *)(pass + 8));
        }
        newSource2 = 0;
        local_60 = &DAT_001acec0;
        local_f4[0] = 0x4040404;
        if (((a0[5] & 0x200U) != 0) && (newSource2 = IRInst__getOperandSource(a0,a0[0x21]), newSource2 != 0)) {
          operandRecord8 = IRInst__getOperandRecord(node,node[0x21]);
          iVar14 = 0;
          local_f4[0] = *(int *)(operandRecord8 + 0x10);
          iVar16 = 4;
          do {
            if (*(char *)(iVar14 + (int)local_64) == '\0') {
              *(undefined1 *)((int)local_f4 + iVar14) = 4;
            }
            iVar14 = iVar14 + 1;
            iVar16 = iVar16 + -1;
          } while (iVar16 != 0);
        }
        if (0 < node[0x21]) {
          operandIndex = 1;
          do {
            sourceDef4 = IRInst__getOperandSource(node,operandIndex);
            *(int *)(sourceDef4 + 0x160) = *(int *)(sourceDef4 + 0x160) + -1;
            if (trackUses != 0) {
              sourceDef4 = IRInst__getOperandSource(node,operandIndex);
              Vector__removeValue(*(undefined4 *)(sourceDef4 + 0x10),node);
            }
            operandIndex = operandIndex + 1;
          } while (operandIndex <= node[0x21]);
        }
        local_a4 = 0;
        local_d0 = 0;
        local_cc = 0;
        local_bc = 0;
        local_b8 = 0;
        local_b4 = 0;
        operandRecord = IRInst__getOperandRecord(inst2,operandIndex4);
        IROperand__copyFrom(&local_d0,operandRecord);
        operandRecord = IRInst__getOperandRecord(inst2,operandIndex3);
        IROperand__copyFrom(&local_b8,operandRecord);
        afterInst = node[1];
        DList__unlink(node);
        IRInst__reinitAsBinary(node,0x12,*(undefined4 *)(pass + 8));
        bVar1 = trackUses == 0;
        Block__insertInstAfter(*(undefined4 *)(afterInst + 0x158),afterInst,node);
        iVar14 = *(int *)(pass + 0x478);
        node[4] = iVar18;
        node[0x58] = iVar11 + iVar14;
        node[0x27] = local_100;
        node[0x48] = iVar21;
        node[0x49] = iVar22;
        node[0x25] = iVar19;
        node[0x26] = iVar20;
        operandRecord = IRInst__getOperandRecord(node,operandIndex4);
        IROperand__copyModifiersAndSelect(operandRecord,&local_d0);
        IRInst__setOperandSource(node,operandIndex4,iVar13,0,*(undefined4 *)(pass + 8));
        iVar11 = local_fc;
        if (bVar1) {
          if (*(int *)(pass + 0x478) < *(int *)(iVar13 + 0x160)) {
            *(int *)(iVar13 + 0x160) = *(int *)(iVar13 + 0x160) + 1;
          }
          else {
            *(int *)(iVar13 + 0x160) = *(int *)(pass + 0x478) + 1;
          }
        }
        if (operandIndex4 == 0) {
          node[0x27] = local_fc;
        }
        else {
          operandRecord3 = IRInst__getOperandRecord(node,operandIndex4);
          *(int *)(operandRecord3 + 0x10) = iVar11;
        }
        operandRecord = IRInst__getOperandRecord(node,operandIndex3);
        IROperand__copyModifiersAndSelect(operandRecord,&local_b8);
        IRInst__setOperandSource(node,operandIndex3,sourceDef2,0,*(undefined4 *)(pass + 8));
        iVar7 = local_e8[0];
        if (bVar1) {
          if (*(int *)(pass + 0x478) < *(int *)(sourceDef2 + 0x160)) {
            *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + 1;
          }
          else {
            *(int *)(sourceDef2 + 0x160) = *(int *)(pass + 0x478) + 1;
          }
        }
        if (operandIndex3 == 0) {
          node[0x27] = local_e8[0];
        }
        else {
          operandRecord2 = IRInst__getOperandRecord(node,operandIndex3);
          *(int *)(operandRecord2 + 0x10) = iVar7;
        }
        if ((newSource2 != 0) && (local_f4[0] != *(int *)(((unsigned char *)0x00003190U) + (int)local_60))) {
          IRInst__setExtraOperandSource(node,newSource2,trackUses,*(undefined4 *)(pass + 8));
          iVar24 = local_f4[0];
          operandRecord3 = IRInst__getOperandRecord(node,3);
          *(int *)(operandRecord3 + 0x10) = iVar24;
          if (bVar1) {
            if (*(int *)(pass + 0x478) < *(int *)(newSource2 + 0x160)) {
              *(int *)(newSource2 + 0x160) = *(int *)(newSource2 + 0x160) + 1;
            }
            else {
              *(int *)(newSource2 + 0x160) = *(int *)(pass + 0x478) + 1;
            }
          }
        }
        IRInst__deleteIfUnused(a0,*(undefined4 *)(pass + 8),0);
        return 0;
      }
    }
  }
  return 0;
}

/* Inst__collapseMulOfExps @ 0x15df44 (600 bytes) */
int Inst__collapseMulOfExps(inst, program)
  int *inst;
  int program;
{
  bool moreLanes;
  int lane;
  int saturate;
  int operandRecord;
  int operandRecord2;
  int operandRecord3;
  bool signsDiffer;
  undefined4 sourceSelect;
  int depthBase;
  int *operandVReg;
  int *operandVReg2;
  int hasSingleUse;
  int *inst2;
  int addDestSelect;
  int inst3;
  int parentBlock;
  int resultScale;
  int allocatedRegister;
  int depthAboveBase;
  int destRegister;
  int destRegisterOffset;
  int destSelect;
  
  if (*(int *)(inst[0x22] + 8) == 0x13) {
    operandVReg = (int *)IRInst__getOperandSource(inst,1);
    operandVReg2 = (int *)IRInst__getOperandSource(inst,2);
    if ((((((*(int *)(operandVReg[0x22] + 8) == 0x37) &&
           (hasSingleUse = IRInst__hasSingleUse(operandVReg,program), hasSingleUse != 0)) && ((operandVReg[5] & 0x200U) == 0)) &&
         ((operandVReg[0x48] == 0 && (operandVReg[0x49] == 0)))) &&
        ((*(int *)(operandVReg2[0x22] + 8) == 0x37 &&
         ((hasSingleUse = IRInst__hasSingleUse(operandVReg2,program), hasSingleUse != 0 && ((operandVReg2[5] & 0x200U) == 0)))))) &&
       ((operandVReg2[0x48] == 0 && (operandVReg2[0x49] == 0)))) {
      depthAboveBase = inst[0x58] - *(int *)(program + 0x478);
      saturate = inst[0x48];
      resultScale = inst[0x49];
      allocatedRegister = inst[0x53];
      if (depthAboveBase < 0) {
        depthAboveBase = 0;
      }
      destRegister = inst[0x25];
      signsDiffer = ((inst[0x34] ^ inst[0x2e]) & 1U) != 0;
      destRegisterOffset = inst[0x26];
      operandRecord = IRInst__getOperandRecord(inst,0);
      destSelect = *(int *)(operandRecord + 0x10);
      inst3 = IRInst__create(0x12,*(undefined4 *)(program + 8));
      IRInst__copyOperandFrom(inst3,1,operandVReg,1);
      IRInst__copyOperandFrom(inst3,2,operandVReg2,1);
      addDestSelect = DAT_001b0054;
      depthBase = *(int *)(program + 0x478);
      *(undefined4 *)(inst3 + 0x94) = *(undefined4 *)(inst3 + 0x14c);
      *(undefined4 *)(inst3 + 0x98) = 0;
      *(int *)(inst3 + 0x9c) = addDestSelect;
      parentBlock = inst[0x56];
      *(int *)(inst3 + 0x160) = depthBase + 1;
      Block__insertInstBefore(parentBlock,inst,inst3);
      if (signsDiffer) {
        inst2 = (int *)IRInst__create(0x37,*(undefined4 *)(program + 8));
        depthBase = *(int *)(program + 0x478);
        inst2[0x27] = addDestSelect;
        inst2[0x58] = depthBase + 1;
        inst2[0x25] = inst2[0x53];
        sourceSelect = DAT_001b0050;
        inst2[0x26] = 0;
        operandRecord = IRInst__getOperandRecord(inst2,1);
        *(undefined4 *)(operandRecord + 0x10) = sourceSelect;
        (**(code **)(*inst2 + 0x88))(inst2,1,3,3);
        Block__insertInstBefore(inst[0x56],inst,inst2);
        DList__unlink(inst);
        IRInst__reinitAsMov(inst,0x31,*(undefined4 *)(program + 8));
        IRInst__setOperandSource(inst,1,inst2,0,*(undefined4 *)(program + 8));
        Block__insertInstAfter(inst2[0x56],inst2,inst);
        IROperand__setModifierBits(inst + 0x29,1,1);
      }
      else {
        DList__unlink(inst);
        IRInst__reinitAsUnary(inst,0x37,*(undefined4 *)(program + 8));
        Block__insertInstAfter(*(undefined4 *)(inst3 + 0x158),inst3,inst);
        inst2 = inst;
      }
      IRInst__setOperandSource(inst2,1,inst3,0,*(undefined4 *)(program + 8));
      inst[0x48] = saturate;
      inst[0x49] = resultScale;
      inst[0x53] = allocatedRegister;
      inst[0x58] = depthAboveBase + *(int *)(program + 0x478);
      operandRecord2 = IRInst__getOperandRecord(inst,0);
      inst[0x27] = destSelect;
      *(int *)(operandRecord2 + 0xc) = destRegisterOffset;
      *(int *)(operandRecord2 + 8) = destRegister;
      if (signsDiffer) {
        lane = 0;
        do {
          operandRecord3 = IRInst__getOperandRecord(inst,0);
          if (*(char *)(lane + operandRecord3 + 0x10) != '\x01') {
            (**(code **)(*inst + 0x88))(inst,1,lane,3);
          }
          moreLanes = lane != 3;
          lane = lane + 1;
        } while (moreLanes);
      }
      (**(code **)(*operandVReg + 0xc))(operandVReg,0,*(undefined4 *)(program + 8));
      (**(code **)(*operandVReg2 + 0xc))(operandVReg2,0,*(undefined4 *)(program + 8));
      return 1;
    }
  }
  return 0;
}

/* IRInst__getOtherOperandIfConstant @ 0x15e2f4 (416 bytes) */
undefined4 IRInst__getOtherOperandIfConstant(int inst,int param_2,undefined4 param_3,undefined4 compilerCtx,double fparam_1)
{
  undefined4 sourceDef;
  int operandRecord;
  int uniformSourceConstant;
  undefined4 operandVReg;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 auStack_48 [4];
  float local_44;
  
  if (((((*(int *)(inst + 0x120) == 0) && (*(int *)(inst + 0x124) == 0)) &&
       ((*(uint *)(inst + 0xb8) & 1) == 0)) &&
      (((*(uint *)(inst + 0xb8) & 2) == 0 && ((*(uint *)(inst + 0xd0) & 1) == 0)))) &&
     (((*(uint *)(inst + 0xd0) & 2) == 0 && (*(int *)(*(int *)(inst + 0x88) + 8) == param_2)))
     ) {
    operandRecord = IRInst__getOperandRecord(inst,0);
    uniformSourceConstant = IRInst__getUniformSourceConstant(inst,1,*(undefined4 *)(operandRecord + 0x10),auStack_48);
    if ((uniformSourceConstant != 0) && (fparam_1 == (double)local_44)) {
      operandVReg = IRInst__getOperandSource(inst,2);
      operandRecord = IRInst__getOperandRecord(inst,2);
      uVar4 = *(undefined4 *)(operandRecord + 0x10);
      sourceDef = IRInst__getOperandSource(inst,1);
      IRInst__setOperandSource(inst,2,sourceDef,0,compilerCtx);
      operandRecord = IRInst__getOperandRecord(inst,1);
      uVar3 = *(undefined4 *)(operandRecord + 0x10);
      operandRecord = IRInst__getOperandRecord(inst,2);
      *(undefined4 *)(operandRecord + 0x10) = uVar3;
      IRInst__setOperandSource(inst,1,operandVReg,0,compilerCtx);
      operandRecord = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord + 0x10) = uVar4;
      return operandVReg;
    }
    operandRecord = IRInst__getOperandRecord(inst,0);
    uniformSourceConstant = IRInst__getUniformSourceConstant(inst,2,*(undefined4 *)(operandRecord + 0x10),auStack_48);
    if ((uniformSourceConstant != 0) && ((double)local_44 == fparam_1)) {
      operandVReg = IRInst__getOperandSource(inst,1);
      return operandVReg;
    }
  }
  return 0;
}

/* Inst__collapseClampToSaturate @ 0x15e494 (772 bytes) */
int Inst__collapseClampToSaturate(inst, program)
  int *inst;
  int program;
{
  int depthBase;
  undefined4 parentBlock;
  undefined4 remappedSelect;
  int lane;
  int srcIndexOut;
  int srcIndexInst;
  int srcIndexProducer;
  int producerCheck;
  int middleInst;
  bool identitySwizzle;
  int outRecord;
  int lanesLeft;
  int sourceCountLimit;
  int cloneResult;
  int isSourceSelectIdentity2;
  int isSourceSelectIdentity;
  undefined4 operandRecord5;
  undefined4 operandRecord7;
  int sourceDef;
  int operandRecord6;
  int operandRecord2;
  int operandRecord3;
  int operandRecord4;
  int loopIndex;
  bool moreLanes;
  byte srcSelectByte;
  int hwSupport;
  int *clampedValue;
  int depthAboveBase;
  undefined4 extraSelect;
  int producerResultMode;
  int isPresub;
  int *operandVReg;
  int operandRecord;
  int operandVReg2;
  undefined4 allocatedRegister;
  undefined4 in_r5;
  int nextNode;
  int extraSource;
  int depthBasePlusOne;
  int compiler;
  int lane2;
  undefined4 destSelectWord;
  byte remapSelect [4];
  undefined4 srcSelectWord;
  undefined4 newSelectWord;
  undefined4 savedDestRecord;
  undefined4 savedDestRecord1;
  undefined4 savedDestRecord5;
  
  compiler = *(int *)(program + 8);
  hwSupport = (**(code **)(**(int **)(compiler + 0x30c) + 0x80))(*(int **)(compiler + 0x30c),program);
  if (hwSupport == 0) {
    return 0;
  }
  middleInst = ((undefined4 (*)())IRInst__getOtherOperandIfConstant)(inst,0x17,in_r5,compiler,0.0);
  if (middleInst == 0) {
    middleInst = ((undefined4 (*)())IRInst__getOtherOperandIfConstant)(inst,0x19,in_r5,compiler,1.0);
    if (middleInst == 0) {
      return 0;
    }
    clampedValue = (int *)((undefined4 (*)())IRInst__getOtherOperandIfConstant)(middleInst,0x17,in_r5,compiler,0.0);
  }
  else {
    clampedValue = (int *)((undefined4 (*)())IRInst__getOtherOperandIfConstant)(middleInst,0x19,in_r5,compiler,1.0);
  }
  if (clampedValue == (int *)0x0) {
    return 0;
  }
  if ((*(uint *)(middleInst + 0x14) & 0x200) != 0) {
    return 0;
  }
  if ((clampedValue[5] & 0x200U) != 0) {
    return 0;
  }
  *(int *)(program + 0x1a8) = *(int *)(program + 0x1a8) + 1;
  operandRecord2 = IRInst__getOperandRecord(inst,0);
  lane2 = 0;
  remapSelect[0] = 4;
  remapSelect[1] = 4;
  remapSelect[2] = 4;
  remapSelect[3] = 4;
  destSelectWord = *(undefined4 *)(operandRecord2 + 0x10);
  do {
    if (*(char *)((int)&destSelectWord + lane2) != '\x01') {
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      srcSelectByte = *(byte *)(lane2 + operandRecord2 + 0x10);
      operandRecord2 = IRInst__getOperandRecord(middleInst,1);
      remapSelect[lane2] = *(byte *)((uint)srcSelectByte + operandRecord2 + 0x10);
    }
    moreLanes = lane2 != 3;
    lane2 = lane2 + 1;
  } while (moreLanes);
  depthBase = *(int *)(program + 0x478);
  depthAboveBase = inst[0x58] - depthBase;
  if (depthAboveBase < 0) {
    depthAboveBase = 0;
  }
  savedDestRecord5 = 0;
  savedDestRecord = 0;
  savedDestRecord1 = 0;
  operandRecord5 = IRInst__getOperandRecord(inst,0);
  IROperand__copyFrom(&savedDestRecord,operandRecord5);
  nextNode = inst[2];
  if (depthBase < clampedValue[0x58]) {
    clampedValue[0x58] = clampedValue[0x58] + 1;
  }
  else {
    clampedValue[0x58] = depthBase + 1;
  }
  IRInst__dropCounterAndDeleteIfUnused(middleInst,compiler);
  extraSource = 0;
  if ((inst[5] & 0x200U) != 0) {
    extraSource = IRInst__getOperandSource(inst,inst[0x21]);
  }
  extraSelect = 0x10203;
  if (extraSource != 0) {
    operandRecord6 = IRInst__getOperandRecord(inst,inst[0x21]);
    extraSelect = *(undefined4 *)(operandRecord6 + 0x10);
  }
  DList__unlink(inst);
  producerResultMode = OpcodeInfo__getResultMode(clampedValue[0x22],clampedValue,program);
  isSourceSelectIdentity2 = IRInst__isSourceSelectIdentity(inst,1);
  if (isSourceSelectIdentity2 != 0) {
    isSourceSelectIdentity = IRInst__isSourceSelectIdentity(middleInst,1);
    identitySwizzle = true;
    if (isSourceSelectIdentity != 0) goto LAB_0015e6ec;
  }
  identitySwizzle = false;
LAB_0015e6ec:
  producerCheck = (**(code **)(*clampedValue + 0x24))(clampedValue);
  if (((producerCheck == 0) || (producerCheck = IRInst__hasSingleUse(clampedValue,program), producerCheck == 0)) ||
     ((identitySwizzle = !identitySwizzle, identitySwizzle &&
      ((((producerResultMode != 0 && (producerResultMode != 3)) && (producerResultMode != 4)) && ((producerResultMode != 5 && (producerResultMode != 7)))))))) {
    IRInst__reinitAsMov(inst,0x31,compiler);
    producerResultMode = 0;
    identitySwizzle = true;
    IRInst__setOperandSource(inst,1,clampedValue,0,compiler);
    operandRecord3 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord3 + 0x10) = 0x10203;
  }
  else {
    srcIndexProducer = 1;
    if (0 < clampedValue[0x21]) {
      do {
        sourceDef = IRInst__getOperandSource(clampedValue,srcIndexProducer);
        if (depthBase < *(int *)(sourceDef + 0x160)) {
          *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
        }
        else {
          *(int *)(sourceDef + 0x160) = depthBase + 1;
        }
        srcIndexProducer = srcIndexProducer + 1;
      } while (srcIndexProducer <= clampedValue[0x21]);
    }
    inst = (int *)IRInst__cloneInto(clampedValue,inst,compiler,0);
    IRInst__dropCounterAndDeleteIfUnused(clampedValue,compiler);
    if (((clampedValue[5] & 1U) != 0) && (srcIndexInst = 1, 0 < clampedValue[0x21])) {
      do {
        operandVReg = (int *)IRInst__getOperandSource(inst,srcIndexInst);
        isPresub = (**(code **)(*operandVReg + 0x5c))();
        if (isPresub != 0) {
          depthBasePlusOne = depthBase + 1;
          operandVReg[0x58] = depthBasePlusOne;
          cloneResult = IRInst__clone(operandVReg,compiler,0);
          IRInst__setOperandSource(inst,srcIndexInst,cloneResult,0,compiler);
          Block__insertInstAfter(operandVReg[0x56],operandVReg,cloneResult);
          allocatedRegister = *(undefined4 *)(cloneResult + 0x14c);
          *(int *)(cloneResult + 0x160) = depthBasePlusOne;
          operandRecord = IRInst__getOperandRecord(cloneResult,0);
          *(undefined4 *)(operandRecord + 8) = allocatedRegister;
          if (0 < *(int *)(cloneResult + 0x84)) {
            loopIndex = 1;
            do {
              operandVReg2 = IRInst__getOperandSource(cloneResult,loopIndex);
              if (depthBase < *(int *)(operandVReg2 + 0x160)) {
                *(int *)(operandVReg2 + 0x160) = *(int *)(operandVReg2 + 0x160) + 1;
              }
              else {
                *(int *)(operandVReg2 + 0x160) = depthBasePlusOne;
              }
              loopIndex = loopIndex + 1;
            } while (loopIndex <= *(int *)(cloneResult + 0x84));
          }
        }
        srcIndexInst = srcIndexInst + 1;
      } while (srcIndexInst <= clampedValue[0x21]);
    }
  }
  inst[0x58] = depthBase + depthAboveBase;
  operandRecord7 = IRInst__getOperandRecord(inst,0);
  IROperand__copyFrom(operandRecord7,&savedDestRecord);
  parentBlock = *(undefined4 *)(nextNode + 0x158);
  inst[0x48] = 1;
  Block__insertInstBefore(parentBlock,nextNode,inst);
  if (extraSource != 0) {
    IRInst__setExtraOperandSource(inst,extraSource,0,compiler);
    operandRecord3 = IRInst__getOperandRecord(inst,inst[0x21]);
    *(undefined4 *)(operandRecord3 + 0x10) = extraSelect;
  }
  if ((identitySwizzle) && (producerResultMode == 0)) {
    for (srcIndexOut = 1; sourceCountLimit = (**(code **)(*inst + 0x14))(inst), srcIndexOut <= sourceCountLimit;
        srcIndexOut = srcIndexOut + 1) {
      operandRecord4 = IRInst__getOperandRecord(inst,srcIndexOut);
      lane = 0;
      newSelectWord = 0x4040404;
      srcSelectWord = *(undefined4 *)(operandRecord4 + 0x10);
      lanesLeft = 4;
      do {
        if (*(char *)((int)&destSelectWord + lane) == '\0') {
          *(undefined1 *)((int)&newSelectWord + lane) =
               *(undefined1 *)((int)&srcSelectWord + (uint)remapSelect[lane]);
        }
        remappedSelect = newSelectWord;
        lane = lane + 1;
        lanesLeft = lanesLeft + -1;
      } while (lanesLeft != 0);
      outRecord = IRInst__getOperandRecord(inst,srcIndexOut);
      *(undefined4 *)(outRecord + 0x10) = remappedSelect;
    }
  }
  return 1;
}

/* Inst__tryMix @ 0x15ea3c (696 bytes) */
int Inst__tryMix(consumer, consumerSrcIndex, node, pass)
  int consumer;
  undefined4 consumerSrcIndex;
  int *node;
  int pass;
{
  undefined4 src1Select;
  undefined4 compilerArg;
  undefined4 src2Select;
  undefined4 mixSrc2Select;
  undefined4 cloneDestSelect;
  int laneIndex8;
  int srcSelect;
  int lanesLeft5;
  int lanesLeft4;
  int lanesLeft3;
  int prevNode3;
  int laneIndex6;
  int laneIndex5;
  int laneIndex4;
  int prevNode2;
  int lanesLeft2;
  int lanesLeft;
  int availableResult;
  int destRecord;
  int laneIndex9;
  int isMovResult;
  int srcSelectOut;
  int srcCount;
  int srcIndex;
  int src2SelectOut;
  int isMixResult;
  int laneIndex3;
  int laneIndex2;
  int checkResult3;
  int checkResult2;
  int passArgCopy;
  int laneIndex;
  bool noLaneOverlap;
  int cloneResult;
  undefined4 sourceDef3;
  undefined4 sourceDef;
  int operandRecord4;
  int operandRecord3;
  int operandRecord2;
  int sourceDef2;
  int operandRecord;
  bool moreLanes;
  bool moreLanes2;
  int checkResult;
  int *operandVReg;
  int prevNode;
  undefined4 prevBlock;
  int laneIndex7;
  int clearIndex;
  undefined4 a1;
  undefined4 nodeSrc1Select;
  undefined4 in_r7;
  undefined4 in_r8;
  int nextIndex;
  uint zeroWord;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 foldStatus;
  undefined4 srcDestSelect;
  int local_68;
  undefined4 local_64;
  int local_60;
  uint savedCounters0;
  uint savedCounters1;
  uint savedCounters2;
  undefined4 destWriteMask1;
  undefined4 maskedSelect1;
  undefined4 destWriteMask2;
  undefined4 maskedSelect2 [3];
  
  foldStatus = 0;
  if ((((consumer != 0) && (*(int *)(*(int *)(consumer + 0x88) + 8) != 0x8e)) &&
      ((node[5] & 0x200U) != 0)) && (checkResult = RegKind__flagBit0(node[0x26]), checkResult != 0)) {
    checkResult = (**(code **)(*node + 100))(node);
    if (((checkResult == 0) || (node[0x48] != 0)) ||
       ((node[0x49] != 0 || (((node[0x2e] & 1U) != 0 || ((node[0x2e] & 2U) != 0)))))) {
      checkResult = (**(code **)(*node + 100))(node);
      if (checkResult == 0) {
        operandVReg = (int *)IRInst__getOperandSource(node,node[0x21]);
        checkResult = (**(code **)(*operandVReg + 100))();
        if ((((checkResult != 0) && ((operandVReg[5] & 0x200U) == 0)) && (operandVReg[0x48] == 0)) &&
           (((operandVReg[0x49] == 0 && ((operandVReg[0x2e] & 1U) == 0)) &&
            ((zeroWord = operandVReg[0x2e] & 2, zeroWord == 0 &&
             (checkResult = FUN_000f5a0c(operandVReg,1,operandVReg,pass), checkResult != 0)))))) {
          *(int *)(pass + 0x228) = *(int *)(pass + 0x228) + 1;
          prevNode = node[1];
          DList__unlink(node);
          savedCounters0 = zeroWord;
          savedCounters1 = zeroWord;
          savedCounters2 = zeroWord;
          IRInst__saveCounters(node,&savedCounters0,0xffffffff);
          cloneResult = IRInst__clone(node,*(undefined4 *)(pass + 8),0);
          *(int *)(cloneResult + 0x160) = *(int *)(pass + 0x478) + 1;
          *(undefined4 *)(cloneResult + 0x94) = *(undefined4 *)(cloneResult + 0x14c);
          IRInst__setOperandSource(cloneResult,*(undefined4 *)(cloneResult + 0x84),0,0,*(undefined4 *)(pass + 8));
          prevBlock = *(undefined4 *)(prevNode + 0x158);
          *(int *)(cloneResult + 0x84) = *(int *)(cloneResult + 0x84) + -1;
          *(uint *)(cloneResult + 0x14) = *(uint *)(cloneResult + 0x14) & 0xfffffdff;
          Block__insertInstAfter(prevBlock,prevNode,cloneResult);
          IRMix__ctor_10a1c0(node,0xa2,*(undefined4 *)(pass + 8));
          laneIndex7 = 0;
          Block__insertInstAfter(*(undefined4 *)(cloneResult + 0x158),cloneResult,node);
          operandRecord2 = IRInst__getOperandRecord(cloneResult,0);
          cloneDestSelect = *(undefined4 *)(operandRecord2 + 0x10);
          operandRecord2 = IRInst__getOperandRecord(cloneResult,0);
          local_68 = *(int *)(operandRecord2 + 0x10);
          operandRecord2 = IRInst__getOperandRecord(operandVReg,0);
          local_64 = *(undefined4 *)(operandRecord2 + 0x10);
          do {
            operandRecord2 = IRInst__getOperandRecord(cloneResult,0);
            if (*(char *)(laneIndex7 + operandRecord2 + 0x10) != '\x01') {
              *(undefined1 *)((int)&local_64 + laneIndex7) = 1;
            }
            moreLanes2 = laneIndex7 != 3;
            laneIndex7 = laneIndex7 + 1;
          } while (moreLanes2);
          operandRecord3 = IRInst__getOperandRecord(operandVReg,0);
          laneIndex9 = 0;
          srcDestSelect = *(undefined4 *)(operandRecord3 + 0x10);
          lanesLeft3 = 4;
          do {
            if (*(char *)((int)&srcDestSelect + laneIndex9) != '\x01') {
              *(char *)((int)&local_68 + laneIndex9) = *(char *)((int)&srcDestSelect + laneIndex9);
            }
            laneIndex9 = laneIndex9 + 1;
            lanesLeft3 = lanesLeft3 + -1;
          } while (lanesLeft3 != 0);
          node[0x27] = local_68;
          node[0x25] = node[0x53];
          node[0x26] = 0x36;
          IRInst__restoreCounters(node,&savedCounters0);
          node[0x21] = 2;
          IRInst__setOperandSource(node,1,cloneResult,0,*(undefined4 *)(pass + 8));
          WriteMask__fromSelectWord(&destWriteMask1,cloneDestSelect);
          SelectWord__maskUnused(&maskedSelect1,0x10203,destWriteMask1);
          operandRecord = IRInst__getOperandRecord(node,1);
          *(undefined4 *)(operandRecord + 0x10) = maskedSelect1;
          sourceDef = IRInst__getOperandSource(operandVReg,1);
          IRInst__setOperandSource(node,2,sourceDef,0,*(undefined4 *)(pass + 8));
          operandRecord = IRInst__getOperandRecord(operandVReg,1);
          mixSrc2Select = *(undefined4 *)(operandRecord + 0x10);
          WriteMask__fromSelectWord(&destWriteMask2,local_64);
          SelectWord__maskUnused(maskedSelect2,mixSrc2Select,destWriteMask2);
          operandRecord = IRInst__getOperandRecord(node,2);
          *(undefined4 *)(operandRecord + 0x10) = maskedSelect2[0];
          IRInst__dropCounterAndDeleteIfUnused(operandVReg,*(undefined4 *)(pass + 8));
          ((int (*)())Inst__foldProducerIntoConsumer)(consumer,consumerSrcIndex,node,pass,&foldStatus);
          return 1;
        }
      }
    }
    else {
      noLaneOverlap = true;
      laneIndex = 0;
      operandVReg = (int *)IRInst__getOperandSource(node,node[0x21]);
      do {
        destRecord = IRInst__getOperandRecord(node,0);
        if (((*(char *)(laneIndex + destRecord + 0x10) == '\x01') &&
            (destRecord = IRInst__getOperandRecord(operandVReg,0), *(char *)(laneIndex + destRecord + 0x10) == '\x01')) &&
           ((operandVReg[5] & 0x200U) != 0)) {
          noLaneOverlap = false;
        }
        moreLanes = laneIndex != 3;
        laneIndex = laneIndex + 1;
      } while (moreLanes);
      if (noLaneOverlap) {
        passArgCopy = pass;
        availableResult = FUN_000f5a0c(node,1,node,pass);
        if (availableResult == 0) {
          checkResult2 = (**(code **)(*operandVReg + 100))(operandVReg);
          if (checkResult2 == 0) {
            return 0;
          }
          zeroWord = operandVReg[5] & 0x200;
          if (zeroWord != 0) {
            return 0;
          }
          checkResult3 = FUN_000f5a0c(operandVReg,1,operandVReg,pass);
          if (checkResult3 == 0) {
            return 0;
          }
          *(int *)(pass + 0x228) = *(int *)(pass + 0x228) + 1;
          savedCounters0 = zeroWord;
          savedCounters1 = zeroWord;
          savedCounters2 = zeroWord;
          IRInst__saveCounters(node,&savedCounters0,0xffffffff);
          sourceDef = IRInst__getOperandSource(node,1);
          operandRecord = IRInst__getOperandRecord(node,0);
          local_60 = *(int *)(operandRecord + 0x10);
          operandRecord2 = IRInst__getOperandRecord(operandVReg,1);
          laneIndex2 = 0;
          local_64 = *(undefined4 *)(operandRecord2 + 0x10);
          lanesLeft = 4;
          do {
            if (*(char *)((int)&local_60 + laneIndex2) != '\x01') {
              *(undefined1 *)((int)&local_64 + laneIndex2) = 4;
            }
            laneIndex2 = laneIndex2 + 1;
            lanesLeft = lanesLeft + -1;
          } while (lanesLeft != 0);
          operandRecord2 = IRInst__getOperandRecord(operandVReg,0);
          laneIndex3 = 0;
          local_78 = *(undefined4 *)(operandRecord2 + 0x10);
          lanesLeft2 = 4;
          do {
            if (*(char *)((int)&local_78 + laneIndex3) != '\x01') {
              *(char *)((int)&local_60 + laneIndex3) = *(char *)((int)&local_78 + laneIndex3);
            }
            laneIndex3 = laneIndex3 + 1;
            lanesLeft2 = lanesLeft2 + -1;
          } while (lanesLeft2 != 0);
          operandRecord = IRInst__getOperandRecord(node,1);
          prevNode2 = node[1];
          nodeSrc1Select = *(undefined4 *)(operandRecord + 0x10);
          DList__unlink(node);
          IRMix__ctor_10a1c0(node,0xa2,*(undefined4 *)(pass + 8));
          IRInst__restoreCounters(node,&savedCounters0);
          node[0x26] = 0x36;
          node[0x25] = node[0x53];
          node[0x27] = local_60;
          node[0x21] = 2;
          IRInst__setOperandSource(node,1,sourceDef,0,*(undefined4 *)(pass + 8));
          operandRecord = IRInst__getOperandRecord(node,1);
          *(undefined4 *)(operandRecord + 0x10) = nodeSrc1Select;
          sourceDef = IRInst__getOperandSource(operandVReg,1);
          IRInst__setOperandSource(node,2,sourceDef,0,*(undefined4 *)(pass + 8));
          src2Select = local_64;
          operandRecord = IRInst__getOperandRecord(node,2);
          *(undefined4 *)(operandRecord + 0x10) = src2Select;
          Block__insertInstAfter(*(undefined4 *)(prevNode2 + 0x158),prevNode2,node);
          IRInst__dropCounterAndDeleteIfUnused(operandVReg,*(undefined4 *)(pass + 8));
        }
        else {
          *(int *)(pass + 0x228) = *(int *)(pass + 0x228) + 1;
          savedCounters2 = 0;
          savedCounters0 = 0;
          savedCounters1 = 0;
          IRInst__saveCounters(node,&savedCounters0,0xffffffff);
          sourceDef = IRInst__getOperandSource(node,1);
          operandRecord2 = IRInst__getOperandRecord(node,0);
          local_68 = *(int *)(operandRecord2 + 0x10);
          operandRecord3 = IRInst__getOperandRecord(operandVReg,0);
          laneIndex4 = 0;
          local_74 = *(undefined4 *)(operandRecord3 + 0x10);
          lanesLeft4 = 4;
          do {
            if (*(char *)((int)&local_74 + laneIndex4) != '\x01') {
              *(char *)((int)&local_68 + laneIndex4) = *(char *)((int)&local_74 + laneIndex4);
            }
            laneIndex4 = laneIndex4 + 1;
            lanesLeft4 = lanesLeft4 + -1;
          } while (lanesLeft4 != 0);
          laneIndex5 = 0;
          local_64 = 0x10203;
          do {
            operandRecord3 = IRInst__getOperandRecord(node,0);
            if (*(char *)(laneIndex5 + operandRecord3 + 0x10) != '\x01') {
              *(undefined1 *)((int)&local_64 + laneIndex5) = 4;
            }
            moreLanes2 = laneIndex5 != 3;
            laneIndex5 = laneIndex5 + 1;
          } while (moreLanes2);
          laneIndex6 = 0;
          lanesLeft5 = 4;
          do {
            if (*(char *)((int)&local_68 + laneIndex6) == '\x01') {
              *(undefined1 *)((int)&local_64 + laneIndex6) = 4;
            }
            laneIndex6 = laneIndex6 + 1;
            lanesLeft5 = lanesLeft5 + -1;
          } while (lanesLeft5 != 0);
          operandRecord2 = IRInst__getOperandRecord(node,1);
          local_60 = *(int *)(operandRecord2 + 0x10);
          prevNode3 = node[1];
          DList__unlink(node);
          compilerArg = *(undefined4 *)(pass + 8);
          IRMix__ctor_10a1c0(node,0xa2,compilerArg);
          IRInst__restoreCounters(node,&savedCounters0);
          node[0x26] = 0x36;
          node[0x25] = node[0x53];
          node[0x27] = local_68;
          isMixResult = (**(code **)(*operandVReg + 0x60))(operandVReg,a1,compilerArg,passArgCopy,in_r7,in_r8,local_68);
          if (isMixResult == 0) {
            node[0x21] = 2;
            IRInst__setOperandSource(node,1,operandVReg,0,*(undefined4 *)(pass + 8));
            src1Select = local_64;
            operandRecord = IRInst__getOperandRecord(node,1);
            *(undefined4 *)(operandRecord + 0x10) = src1Select;
            IRInst__setOperandSource(node,2,sourceDef,0,*(undefined4 *)(pass + 8));
            src2SelectOut = local_60;
            operandRecord3 = IRInst__getOperandRecord(node,2);
            *(int *)(operandRecord3 + 0x10) = src2SelectOut;
          }
          else {
            node[0x21] = operandVReg[0x21] + 1;
            if (0 < operandVReg[0x21]) {
              srcIndex = 1;
              do {
                sourceDef3 = IRInst__getOperandSource(operandVReg,srcIndex);
                IRInst__setOperandSource(node,srcIndex,sourceDef3,0,*(undefined4 *)(pass + 8));
                operandRecord3 = IRInst__getOperandRecord(operandVReg,srcIndex);
                srcSelect = *(int *)(operandRecord3 + 0x10);
                if (srcIndex == 0) {
                  node[0x27] = srcSelect;
                }
                else {
                  operandRecord4 = IRInst__getOperandRecord(node,srcIndex);
                  *(int *)(operandRecord4 + 0x10) = srcSelect;
                }
                srcIndex = srcIndex + 1;
              } while (srcIndex <= operandVReg[0x21]);
            }
            operandVReg[0x58] = operandVReg[0x58] + -1;
            sourceDef2 = IRInst__getOperandSource(operandVReg,1);
            if (*(int *)(pass + 0x478) < *(int *)(sourceDef2 + 0x160)) {
              *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + 1;
            }
            else {
              *(int *)(sourceDef2 + 0x160) = *(int *)(pass + 0x478) + 1;
            }
            srcCount = node[0x21];
            laneIndex8 = 0;
            do {
              if ((*(char *)((int)&local_60 + laneIndex8) != '\x04') && (0 < srcCount)) {
                clearIndex = 1;
                do {
                  nextIndex = clearIndex + 1;
                  (**(code **)(*node + 0x88))(node,clearIndex,laneIndex8,4);
                  srcCount = node[0x21];
                  clearIndex = nextIndex;
                } while (nextIndex <= srcCount);
              }
              moreLanes2 = laneIndex8 != 3;
              laneIndex8 = laneIndex8 + 1;
            } while (moreLanes2);
            IRInst__setOperandSource(node,srcCount,sourceDef,0,*(undefined4 *)(pass + 8));
            srcSelectOut = local_60;
            if (node[0x21] == 0) {
              node[0x27] = local_60;
            }
            else {
              operandRecord3 = IRInst__getOperandRecord(node,node[0x21]);
              *(int *)(operandRecord3 + 0x10) = srcSelectOut;
            }
          }
          Block__insertInstAfter(*(undefined4 *)(prevNode3 + 0x158),prevNode3,node);
          IRInst__deleteIfUnused(operandVReg,*(undefined4 *)(pass + 8),0);
          isMovResult = (**(code **)(*operandVReg + 100))(operandVReg);
          if (isMovResult == 0) {
            return 1;
          }
        }
        ((int (*)())Inst__foldProducerIntoConsumer)(consumer,consumerSrcIndex,node,pass,&foldStatus);
        return 1;
      }
    }
  }
  return 0;
}

/* FUN_0015f44c @ 0x15f44c (2576 bytes) */
int FUN_0015f44c(inst, operandIndex7, node, pass)
  int inst;
  undefined4 operandIndex7;
  int *node;
  int pass;
{
  undefined4 block2;
  undefined4 compilerCtx2;
  undefined4 inst1;
  undefined4 compilerCtx;
  undefined4 block;
  int operandIndex6;
  int operandIndex5;
  int operandIndex4;
  int operandIndex3;
  int operandIndex2;
  int operandIndex;
  int cloneResult;
  undefined4 sourceDef3;
  int operandRecord4;
  int sourceDef;
  int sourceDef4;
  int operandRecord3;
  int operandRecord5;
  int operandRecord6;
  int sourceDef2;
  int operandRecord2;
  int *operandVReg;
  bool bVar1;
  bool bVar2;
  bool bVar3;
  byte bVar4;
  float fVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int operandRecord;
  int iVar11;
  undefined4 uVar12;
  undefined4 in_r8;
  undefined4 uVar13;
  uint uVar14;
  undefined4 uVar15;
  int iVar16;
  int *piVar17;
  int iVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  double fparam_1;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  int local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  int local_ac;
  undefined4 local_a8;
  int local_a0 [5];
  undefined4 *local_8c;
  undefined4 *local_88;
  undefined4 *local_84;
  undefined4 *local_80;
  undefined4 *local_7c;
  undefined4 local_70;
  
  piVar17 = (int *)0x0;
  if ((node[5] & 0x200U) != 0) {
    piVar17 = (int *)IRInst__getOperandSource(node,node[0x21]);
  }
  compilerCtx2 = *(undefined4 *)(pass + 8);
  if ((piVar17 == (int *)0x0) || (iVar6 = (**(code **)(*piVar17 + 0x60))(piVar17), iVar6 == 0)) {
    if ((inst != 0) &&
       (((node != (int *)0x0 && (*(int *)(*(int *)(inst + 0x88) + 8) == 0x8e)) &&
        (iVar6 = (**(code **)(*node + 0x60))(node), iVar6 != 0)))) {
      iVar11 = IRMov__new_1084b8(0x31,*(undefined4 *)(pass + 8));
      iVar6 = *(int *)(pass + 0x478);
      *(undefined4 *)(iVar11 + 0x98) = 0;
      *(int *)(iVar11 + 0x160) = iVar6 + 1;
      *(undefined4 *)(iVar11 + 0x94) = *(undefined4 *)(iVar11 + 0x14c);
      IRInst__setOperandSource(iVar11,1,node,0,*(undefined4 *)(pass + 8));
      operandRecord3 = IRInst__getOperandRecord(node,0);
      *(undefined4 *)(iVar11 + 0x9c) = *(undefined4 *)(operandRecord3 + 0x10);
      FUN_000f4698(iVar11,1,pass);
      Block__insertInstAfter(node[0x56],node,iVar11);
      *(uint *)(iVar11 + 0x14) = *(uint *)(iVar11 + 0x14) | 0x80000000;
      IRInst__setOperandSource(inst,operandIndex7,iVar11,0,*(undefined4 *)(pass + 8));
      return 0;
    }
    return 0;
  }
  operandRecord3 = IRInst__getOperandRecord(node,node[0x21]);
  inst1 = *(undefined4 *)(operandRecord3 + 0x10);
  operandRecord3 = IRInst__getOperandRecord(piVar17,0);
  local_c8 = *(undefined4 *)(operandRecord3 + 0x10);
  if (0 < node[0x21]) {
    operandIndex5 = 1;
    do {
      iVar11 = IRInst__getOperandSource(node,operandIndex5);
      if ((*(int *)(iVar11 + 0x98) != 0x33) ||
         (iVar11 = IRInst__getOperandSource(node,operandIndex5), *(int *)(iVar11 + 300) == 3)) {
        bVar1 = true;
        goto LAB_0015f564;
      }
      operandIndex5 = operandIndex5 + 1;
    } while (operandIndex5 <= node[0x21]);
  }
  bVar1 = false;
LAB_0015f564:
  iVar6 = *(int *)(node[0x22] + 8);
  if (!bVar1) goto LAB_0015fd14;
  operandVReg = (int *)IRInst__getOperandSource(piVar17,1);
  if (((operandVReg[0x20] == 0) || (iVar11 = RegKind__flagBit0(operandVReg[0x26]), iVar11 == 0)) ||
     (((operandVReg[5] & 2U) != 0 || (iVar11 = (**(code **)(*operandVReg + 0x50))(operandVReg), iVar11 != 0)))) {
    operandRecord2 = IRInst__getOperandRecord(piVar17,1);
    uVar12 = *(undefined4 *)(operandRecord2 + 0x10);
    operandRecord2 = IRInst__getOperandRecord(node,0);
    iVar11 = FUN_00146624(uVar12,*(undefined4 *)(operandRecord2 + 0x10));
    if (iVar11 != 0) goto LAB_0015f5cc;
  }
  else {
LAB_0015f5cc:
    if (iVar6 - 0x12U < 3) {
      iVar11 = (**(code **)(*piVar17 + 0x14))(piVar17);
      local_a0[1] = 0;
      local_b0 = 0;
      local_ac = 0;
      if (iVar11 < 1) {
        local_a0[2] = 0;
        local_a0[4] = 0;
        local_a0[3] = 0;
        goto LAB_0015f7bc;
      }
      operandIndex2 = 1;
      local_a0[4] = 0;
      uVar14 = 0;
      local_a0[3] = 0;
      do {
        sourceDef = IRInst__getOperandSource(piVar17,operandIndex2);
        if (*(int *)(sourceDef + 0x98) == 0x33) {
          iVar18 = IRInst__getOperandRecord(piVar17,operandIndex2);
          uVar21 = 0;
          local_bc = *(undefined4 *)(iVar18 + 0x10);
          do {
            bVar4 = *(byte *)((int)&local_bc + uVar21);
            if ((bVar4 != 4) &&
               (iVar18 = IRInst__getOperandRecord(node,0), *(char *)(uVar21 + iVar18 + 0x10) == '\x01')) {
              fVar5 = *(float *)((uint)bVar4 * 0x18 + sourceDef + 0x20);
              local_70 = 0;
              if (fVar5 == 0.0) {
                local_a0[3] = local_a0[3] | 1 << (uVar21 & 0x3f);
              }
              else {
                local_70 = 0x3f800000;
                if (fVar5 == 1.0) {
                  local_a0[4] = local_a0[4] | 1 << (uVar21 & 0x3f);
                }
                else {
                  uVar14 = uVar14 | 1 << (uVar21 & 0x3f);
                }
              }
            }
            bVar1 = uVar21 != 3;
            uVar21 = uVar21 + 1;
          } while (bVar1);
        }
        else {
          IRInst__readLastOperand(node,&local_b0);
          local_ac = sourceDef;
        }
        operandIndex2 = operandIndex2 + 1;
      } while (operandIndex2 <= iVar11);
      local_a0[2] = 0;
      if ((local_a0[4] != 0) &&
         ((1 < iVar6 - 0x13U || (local_a0[2] = 6, (node[0x2e] & 1U) != (node[0x34] & 1U))))) {
        if (iVar6 == 0x12) {
          local_a0[2] = 2;
          if ((node[0x34] & 1U) != 0) {
            uVar21 = node[0x2e];
            local_a0[2] = 4;
            goto joined_r0x0015f784;
          }
        }
        else {
          if (iVar6 == 0x14) {
            uVar21 = node[0x3a];
            local_a0[2] = 1;
joined_r0x0015f784:
            if ((uVar21 & 1) == 0) goto LAB_0015f7a8;
          }
          local_a0[2] = -1;
        }
      }
LAB_0015f7a8:
      if ((uVar14 == 0) && (-1 < local_a0[2])) {
LAB_0015f7bc:
        uVar14 = 2;
        bVar1 = local_a0[4] == 0;
        operandRecord2 = IRInst__getOperandRecord(node,0);
        local_8c = &local_bc;
        local_88 = &local_c8;
        local_bc = *(undefined4 *)(operandRecord2 + 0x10);
        local_84 = local_8c;
        local_80 = local_88;
        local_7c = local_8c;
        do {
          operandIndex3 = 3 - uVar14;
          iVar11 = (**(code **)(*node + 0x14))(node);
          if (iVar11 < operandIndex3) {
            IRInst__setOperandSource(node,node[0x21],0,0,compilerCtx2);
            node[0x21] = node[0x21] + -1;
            node[5] = node[5] & 0xfffffdff;
            if (local_ac != 0) {
              operandRecord3 = IRInst__getOperandRecord(node,0);
              iVar11 = 0;
              piVar7 = local_a0;
              local_b8 = *(int *)(operandRecord3 + 0x10);
              iVar6 = 4;
              do {
                if (*(char *)((int)&local_b8 + iVar11) != '\x01') {
                  *(undefined1 *)piVar7 = 4;
                }
                iVar11 = iVar11 + 1;
                piVar7 = (int *)((int)piVar7 + 1);
                iVar6 = iVar6 + -1;
              } while (iVar6 != 0);
              if (local_a0[0] != 0x4040404) {
                IRInst__setLastOperandFromRecord(node,&local_b0,0,compilerCtx2);
                if (*(int *)(pass + 0x478) < *(int *)(local_ac + 0x160)) {
                  *(int *)(local_ac + 0x160) = *(int *)(local_ac + 0x160) + 1;
                }
                else {
                  *(int *)(local_ac + 0x160) = *(int *)(pass + 0x478) + 1;
                }
              }
            }
            (**(code **)(*node + 0x14))(node);
            IRInst__dropCounterAndDeleteIfUnused(piVar17,compilerCtx2);
            return 1;
          }
          inst1 = IRInst__getOperandSource(node,operandIndex3);
          if ((bVar1) || ((local_a0[3] == 0 && (iVar6 == 0x13)))) {
            uVar21 = local_a0[2] >> (uVar14 & 0x3f);
            if ((uVar21 & 1) == 0) goto LAB_0015f88c;
            iVar11 = 2;
            fparam_1 = 1.0;
          }
          else {
            uVar21 = local_a0[2] >> (uVar14 & 0x3f);
            if ((uVar21 & 1) == 0) {
LAB_0015f88c:
              iVar11 = 2;
              fparam_1 = 0.0;
            }
            else {
              iVar11 = 3;
              fparam_1 = 1.0;
            }
          }
          bVar3 = local_a0[3] != 0;
          iVar18 = 0;
          piVar8 = (int *)((int (*)())IRInst__createWithConstantOperands)(iVar11,0x1010101,inst1,pass,compilerCtx2,fparam_1);
          operandRecord4 = IRInst__getOperandRecord(node,operandIndex3);
          local_b8 = *(int *)(operandRecord4 + 0x10);
          piVar7 = piVar8;
          do {
            if (*(char *)((int)&local_b8 + iVar18) != '\x04') {
              (**(code **)(*piVar8 + 0x88))(piVar8,1,iVar18);
              *(undefined1 *)(piVar7 + 0x27) = 0;
              (**(code **)(*node + 0x88))(node,operandIndex3,iVar18,iVar18);
            }
            bVar2 = iVar18 != 3;
            piVar7 = (int *)((int)piVar7 + 1);
            iVar18 = iVar18 + 1;
          } while (bVar2);
          iVar9 = -1;
          iVar18 = -1;
          iVar19 = 0;
          piVar7 = piVar8;
          do {
            operandRecord = IRInst__getOperandRecord(piVar8,1);
            if ((*(char *)(iVar19 + operandRecord + 0x10) == '\x04') &&
               (*(char *)(iVar19 + (int)local_8c) == '\x01')) {
              if ((iVar11 == 3) || (fparam_1 == 1.0)) {
                if (iVar9 < 0) {
                  (**(code **)(*piVar8 + 0x88))(piVar8,2,iVar19,iVar19);
                  *(undefined1 *)(piVar7 + 0x27) = 0;
                  iVar9 = iVar19;
                  goto LAB_0015fa2c;
                }
                if (iVar11 != 3) goto LAB_0015f9e8;
              }
              else {
LAB_0015f9e8:
                if (fparam_1 != 0.0) break;
              }
              if (-1 < iVar18) break;
              (**(code **)(*piVar8 + 0x88))(piVar8,iVar11,iVar19,iVar19);
              *(undefined1 *)(piVar7 + 0x27) = 0;
              iVar18 = iVar19;
            }
LAB_0015fa2c:
            bVar2 = iVar19 != 3;
            piVar7 = (int *)((int)piVar7 + 1);
            iVar19 = iVar19 + 1;
          } while (bVar2);
          if (!bVar1) {
            uVar20 = 0;
            piVar7 = node;
            do {
              if ((((local_a0[4] >> (uVar20 & 0x3f) & 1U) != 0) &&
                  (*(char *)(uVar20 + (int)local_88) != '\x01')) &&
                 (*(char *)(uVar20 + (int)local_84) == '\x01')) {
                if ((uVar21 & 1) == 0) {
                  (**(code **)(*node + 0x88))(node,operandIndex3,uVar20,iVar18);
                }
                else {
                  (**(code **)(*node + 0x88))(node,operandIndex3,uVar20,iVar9);
                }
                *(undefined1 *)(piVar7 + 0x27) = 0;
              }
              bVar2 = uVar20 != 3;
              piVar7 = (int *)((int)piVar7 + 1);
              uVar20 = uVar20 + 1;
            } while (bVar2);
          }
          if (bVar3) {
            uVar21 = 0;
            piVar7 = node;
            do {
              if ((((local_a0[3] >> (uVar21 & 0x3f) & 1U) != 0) &&
                  (*(char *)(uVar21 + (int)local_80) != '\x01')) &&
                 (*(char *)(uVar21 + (int)local_7c) == '\x01')) {
                (**(code **)(*node + 0x88))(node,operandIndex3,uVar21,iVar18);
                *(undefined1 *)(piVar7 + 0x27) = 0;
              }
              bVar3 = uVar21 != 3;
              piVar7 = (int *)((int)piVar7 + 1);
              uVar21 = uVar21 + 1;
            } while (bVar3);
          }
          operandVReg = (int *)IRInst__getOperandSource(piVar8,1);
          iVar11 = (**(code **)(*operandVReg + 0x60))(operandVReg);
          if (iVar11 != 0) {
            inst1 = IRInst__getOperandSource(piVar8,1);
            FUN_0010c670(inst1,piVar8,compilerCtx2);
          }
          uVar14 = uVar14 - 1;
          Block__insertInstBefore(node[0x56],node,piVar8);
          IRInst__setOperandSource(node,operandIndex3,piVar8,0,compilerCtx2);
        } while( true );
      }
    }
  }
  if ((piVar17[0x26] != 0x33) ||
     (iVar6 = IRInst__getOperandSource(node,node[0x21]), *(int *)(iVar6 + 300) == 3)) {
    iVar11 = IRMov__new_1084b8(0x31,*(undefined4 *)(pass + 8));
    iVar6 = *(int *)(pass + 0x478);
    *(undefined4 *)(iVar11 + 0x98) = 0;
    *(int *)(iVar11 + 0x160) = iVar6 + 1;
    *(undefined4 *)(iVar11 + 0x94) = *(undefined4 *)(iVar11 + 0x14c);
    IRInst__setOperandSource(iVar11,1,piVar17,0,*(undefined4 *)(pass + 8));
    sourceDef3 = IRInst__getOperandSource(node,node[0x21]);
    operandRecord3 = IRInst__getOperandRecord(sourceDef3,0);
    *(undefined4 *)(iVar11 + 0x9c) = *(undefined4 *)(operandRecord3 + 0x10);
    FUN_000f4698(iVar11,1,pass);
    operandIndex6 = node[0x21];
    *(uint *)(iVar11 + 0x14) = *(uint *)(iVar11 + 0x14) | 0x80000000;
    sourceDef4 = IRInst__getOperandSource(node,operandIndex6);
    block = *(undefined4 *)(sourceDef4 + 0x158);
    sourceDef3 = IRInst__getOperandSource(node,node[0x21]);
    Block__insertInstAfter(block,sourceDef3,iVar11);
    IRInst__setExtraOperandSource(node,iVar11,0,*(undefined4 *)(pass + 8));
    operandRecord3 = IRInst__getOperandRecord(node,node[0x21]);
    *(undefined4 *)(operandRecord3 + 0x10) = inst1;
    return 1;
  }
LAB_0015fd14:
  compilerCtx = *(undefined4 *)(pass + 8);
  uVar15 = 0;
  uVar13 = 0;
  IRInst__setOperandSource(node,node[0x21],0,0,compilerCtx);
  iVar6 = piVar17[0x58];
  node[0x21] = node[0x21] + -1;
  node[5] = node[5] & 0xfffffdff;
  piVar17[0x58] = iVar6 + -1;
  iVar6 = IRInst__hasNoUses(piVar17,pass,uVar15,uVar13,compilerCtx,in_r8,iVar6 + -1);
  bVar1 = iVar6 != 0;
  if (bVar1) {
    (**(code **)(*piVar17 + 0xc))(piVar17,0,*(undefined4 *)(pass + 8));
  }
  local_a8 = 0;
  local_b0 = 0;
  local_ac = 0;
  IRInst__saveCounters(node,&local_b0,0xffffffff);
  cloneResult = IRInst__clone(node,*(undefined4 *)(pass + 8),0);
  Block__insertInstAfter(*(undefined4 *)(node[1] + 0x158),node[1],cloneResult);
  *(int *)(cloneResult + 0x160) = *(int *)(pass + 0x478) + 1;
  *(undefined4 *)(cloneResult + 0x94) = *(undefined4 *)(cloneResult + 0x14c);
  IRMix__ctor_10a1c0(node,0xa2,*(undefined4 *)(pass + 8));
  block2 = *(undefined4 *)(cloneResult + 0x158);
  node[0x21] = piVar17[0x21] + 1;
  Block__insertInstAfter(block2,cloneResult,node);
  operandRecord2 = IRInst__getOperandRecord(cloneResult,0);
  local_b8 = *(int *)(operandRecord2 + 0x10);
  operandRecord2 = IRInst__getOperandRecord(piVar17,0);
  iVar16 = 0;
  local_c0 = *(undefined4 *)(operandRecord2 + 0x10);
  iVar11 = 4;
  do {
    if (*(char *)((int)&local_c0 + iVar16) != '\x01') {
      *(char *)((int)&local_b8 + iVar16) = *(char *)((int)&local_c0 + iVar16);
    }
    iVar16 = iVar16 + 1;
    iVar11 = iVar11 + -1;
  } while (iVar11 != 0);
  sourceDef2 = IRInst__getOperandSource(piVar17,1);
  if (*(int *)(sourceDef2 + 0x98) == 0) {
    IRInst__setExtraOperandSource(cloneResult,sourceDef2,0,*(undefined4 *)(pass + 8));
    if (!bVar1) {
      if (*(int *)(pass + 0x478) < *(int *)(sourceDef2 + 0x160)) {
        *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + 1;
      }
      else {
        *(int *)(sourceDef2 + 0x160) = *(int *)(pass + 0x478) + 1;
      }
    }
    node[0x21] = node[0x21] + -1;
    IRInst__setOperandSource(node,1,cloneResult,0,*(undefined4 *)(pass + 8));
    operandRecord2 = IRInst__getOperandRecord(node,1);
    operandIndex4 = 2;
    *(undefined4 *)(operandRecord2 + 0x10) = 0x10203;
  }
  else {
    IRInst__setOperandSource(node,2,cloneResult,0,*(undefined4 *)(pass + 8));
    operandRecord6 = IRInst__getOperandRecord(node,2);
    *(undefined4 *)(operandRecord6 + 0x10) = 0x10203;
    IRInst__setOperandSource(node,1,sourceDef2,0,*(undefined4 *)(pass + 8));
    operandRecord2 = IRInst__getOperandRecord(piVar17,1);
    uVar15 = *(undefined4 *)(operandRecord2 + 0x10);
    operandRecord2 = IRInst__getOperandRecord(node,1);
    operandIndex4 = 3;
    *(undefined4 *)(operandRecord2 + 0x10) = uVar15;
  }
  operandRecord2 = IRInst__getOperandRecord(cloneResult,0);
  local_b4 = *(undefined4 *)(operandRecord2 + 0x10);
  if (1 < piVar17[0x21]) {
    operandIndex = 2;
    do {
      sourceDef3 = IRInst__getOperandSource(piVar17,operandIndex);
      IRInst__setOperandSource(node,operandIndex4,sourceDef3,0,*(undefined4 *)(pass + 8));
      if (!bVar1) {
        sourceDef = IRInst__getOperandSource(piVar17,operandIndex);
        if (*(int *)(pass + 0x478) < *(int *)(sourceDef + 0x160)) {
          *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
        }
        else {
          *(int *)(sourceDef + 0x160) = *(int *)(pass + 0x478) + 1;
        }
      }
      operandRecord4 = IRInst__getOperandRecord(piVar17,operandIndex);
      iVar9 = *(int *)(operandRecord4 + 0x10);
      if (operandIndex4 == 0) {
        node[0x27] = iVar9;
      }
      else {
        operandRecord5 = IRInst__getOperandRecord(node,operandIndex4);
        *(int *)(operandRecord5 + 0x10) = iVar9;
      }
      operandRecord5 = IRInst__getOperandRecord(piVar17,operandIndex);
      iVar9 = 0;
      local_bc = *(undefined4 *)(operandRecord5 + 0x10);
      iVar18 = 4;
      do {
        if (*(char *)((int)&local_b4 + iVar9) != '\x04') {
          *(undefined1 *)((int)&local_bc + iVar9) = 4;
        }
        uVar15 = local_bc;
        iVar9 = iVar9 + 1;
        iVar18 = iVar18 + -1;
      } while (iVar18 != 0);
      operandIndex = operandIndex + 1;
      operandRecord4 = IRInst__getOperandRecord(node,operandIndex4);
      operandIndex4 = operandIndex4 + 1;
      *(undefined4 *)(operandRecord4 + 0x10) = uVar15;
    } while (operandIndex <= piVar17[0x21]);
  }
  node[0x27] = local_b8;
  node[0x25] = node[0x53];
  node[0x26] = 0x36;
  IRInst__restoreCounters(node,&local_b0);
  node[0x56] = *(int *)(cloneResult + 0x158);
  local_c4 = 0;
  Inst__tryCopyPropagate(node,pass,&local_c4);
  ((int (*)())Inst__foldProducerIntoConsumer)(inst,operandIndex7,node,pass,&local_c4);
  return 1;
}

/* Inst__foldProducerIntoConsumer @ 0x160320 (2960 bytes) */
int Inst__foldProducerIntoConsumer(node, operandIndex, inst, pass, param_5)
  int *node;
  int operandIndex;
  int *inst;
  int pass;
  undefined4 *param_5;
{
  int hasSingleUse;
  int isSourceSelectIdentity;
  int flagBit0Result;
  int flagBit7Result;
  undefined4 sourceDef4;
  int *sourceDef;
  int operandRecord3;
  int operandRecord2;
  int sourceDef3;
  int sourceDef2;
  int operandRecord;
  uint uVar1;
  int iVar2;
  int iVar3;
  int operandVReg2;
  int iVar5;
  undefined4 uVar6;
  int *operandVReg;
  int *piVar8;
  undefined4 local_64;
  undefined4 local_60;
  uint local_5c;
  undefined4 local_58;
  uint local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint local_48;
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [4];
  uint local_30;
  uint local_2c;
  uint local_28;
  undefined4 local_24;
  
  iVar2 = (**(code **)(*inst + 0x60))(inst,operandIndex,inst,pass,param_5);
  if (iVar2 != 0) {
    inst = (int *)IRInst__getOperandSource(inst,1);
  }
  iVar2 = (**(code **)(*inst + 100))(inst);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = RegKind__flagBit0(inst[0x26]);
  if (iVar2 == 0) {
    return 0;
  }
  if (((((inst[5] & 0x200U) != 0) && (iVar2 = IRInst__isSourceSelectIdentity(inst,1), iVar2 != 0)) &&
      (inst[0x48] == 0)) &&
     (((inst[0x49] == 0 && ((inst[0x2e] & 1U) == 0)) && ((inst[0x2e] & 2U) == 0)))) {
    if (((inst[0x20] != 0) && (iVar2 = RegKind__flagBit0(inst[0x26]), iVar2 != 0)) &&
       (((inst[5] & 2U) == 0 && (iVar2 = (**(code **)(*inst + 0x50))(inst), iVar2 == 0))))
    {
      iVar2 = 4;
      piVar8 = inst;
      do {
        if ((uint)(*(byte *)(piVar8 + 0x27) - 2) < 2) goto LAB_001605dc;
        piVar8 = (int *)((int)piVar8 + 1);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    if (*(int *)(pass + 0x17c) < *(int *)(*(int *)(pass + 8) + 0x660)) {
      sourceDef3 = IRInst__getOperandSource(inst,1);
      operandVReg2 = IRInst__getOperandSource(inst,inst[0x21]);
      operandRecord = IRInst__getOperandRecord(inst,0);
      local_60 = *(undefined4 *)(operandRecord + 0x10);
      operandRecord3 = IRInst__getOperandRecord(operandVReg2,0);
      iVar2 = 0;
      local_64 = *(undefined4 *)(operandRecord3 + 0x10);
      iVar5 = 4;
      do {
        if ((*(char *)((int)&local_60 + iVar2) != '\x01') &&
           (*(char *)((int)&local_64 + iVar2) != '\x01')) goto LAB_001605dc;
        iVar2 = iVar2 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      if (((*(uint *)(operandVReg2 + 0x14) & 0x200) != 0) &&
         (iVar2 = IRInst__getOperandSource(operandVReg2,*(undefined4 *)(operandVReg2 + 0x84)), sourceDef3 == iVar2)) {
        *(int *)(pass + 0x17c) = *(int *)(pass + 0x17c) + 1;
        iVar2 = (**(code **)(*node + 0x14))(node);
        if ((iVar2 < operandIndex) &&
           (((node[5] & 0x200U) != 0 &&
            (piVar8 = (int *)IRInst__getOperandSource(node,node[0x21]), inst == piVar8)))) {
          IRInst__setExtraOperandSource(node,operandVReg2,0,*(undefined4 *)(pass + 8));
          iVar3 = *(int *)(pass + 0x478);
          iVar2 = *(int *)(operandVReg2 + 0x160);
          if (iVar3 < iVar2) {
LAB_00160588:
            *(int *)(operandVReg2 + 0x160) = iVar2 + 1;
            goto LAB_00160590;
          }
        }
        else {
          IRInst__setOperandSource(node,operandIndex,operandVReg2,0,*(undefined4 *)(pass + 8));
          iVar3 = *(int *)(pass + 0x478);
          iVar2 = *(int *)(operandVReg2 + 0x160);
          if (iVar3 < iVar2) goto LAB_00160588;
        }
        *(int *)(operandVReg2 + 0x160) = iVar3 + 1;
LAB_00160590:
        IRInst__dropCounterAndDeleteIfUnused(inst,*(undefined4 *)(pass + 8));
        *param_5 = 1;
        return 1;
      }
    }
  }
LAB_001605dc:
  iVar2 = (**(code **)(*node + 0x14))(node);
  if (operandIndex <= iVar2) {
    iVar2 = (**(code **)(*node + 0x14))(node);
    if (((operandIndex <= iVar2) && (inst[0x48] == 0)) && (inst[0x49] == 0)) {
      if (((inst[0x20] != 0) && (iVar2 = RegKind__flagBit0(inst[0x26]), iVar2 != 0)) &&
         (((inst[5] & 2U) == 0 && (iVar2 = (**(code **)(*inst + 0x50))(inst), iVar2 == 0)))
         ) {
        iVar2 = 4;
        piVar8 = inst;
        do {
          if ((uint)(*(byte *)(piVar8 + 0x27) - 2) < 2) {
            return 0;
          }
          piVar8 = (int *)((int)piVar8 + 1);
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      IRInst__getOperandRecord(inst,0);
      iVar2 = IRInst__operandKindClass(inst,0);
      if (((iVar2 == 0) && (*(int *)(node[0x22] + 8) != 0x8e)) &&
         (iVar2 = (**(code **)(*node + 0x60))(node), iVar2 == 0)) {
        iVar2 = (**(code **)(*node + 0x28))(node);
        if (iVar2 != 0) {
          sourceDef = (int *)IRInst__getOperandSource(inst,1);
          iVar2 = (**(code **)(*sourceDef + 0x5c))(sourceDef);
          if (iVar2 != 0) {
            return 0;
          }
        }
        iVar2 = (**(code **)(*node + 0x28))(node);
        if (iVar2 != 0) {
          sourceDef2 = IRInst__getOperandSource(inst,1);
          if (sourceDef2 == 0) {
            iVar2 = inst[0x2c];
          }
          else {
            sourceDef2 = IRInst__getOperandSource(inst,1);
            iVar2 = *(int *)(sourceDef2 + 0x98);
          }
          flagBit7Result = RegKind__flagBit7(iVar2);
          if (flagBit7Result != 0) {
            return 0;
          }
        }
        if (*(int *)(pass + 0x17c) < *(int *)(*(int *)(pass + 8) + 0x660)) {
          sourceDef = (int *)IRInst__getOperandSource(node,operandIndex);
          if (inst == sourceDef) {
            operandRecord = IRInst__getOperandRecord(sourceDef,0);
            WriteMask__fromSelectWord(&local_30,*(undefined4 *)(operandRecord + 0x10));
            local_5c = local_30;
          }
          else {
            iVar2 = (**(code **)(*sourceDef + 0x60))(sourceDef);
            if (iVar2 == 0) {
              return 0;
            }
            operandVReg = (int *)IRInst__getOperandSource(sourceDef,1);
            if (inst != operandVReg) {
              return 0;
            }
            operandRecord = IRInst__getOperandRecord(sourceDef,0);
            WriteMask__fromSelectWord(&local_2c,*(undefined4 *)(operandRecord + 0x10));
            local_5c = local_2c;
          }
          operandRecord = IRInst__getOperandRecord(inst,1);
          local_58 = *(undefined4 *)(operandRecord + 0x10);
          if ((inst[5] & 0x200U) == 0) {
            operandRecord = IRInst__getOperandRecord(node,operandIndex);
            SelectWord__readMask(&local_28,*(undefined4 *)(operandRecord + 0x10));
            local_54 = local_28;
            if (((local_5c << 0x18 | (local_5c >> 8 & 0xff) << 0x10 | (local_5c >> 0x10 & 0xff) << 8
                 | local_5c >> 0x18) <
                 (local_28 << 0x18 | (local_28 >> 8 & 0xff) << 0x10 | (local_28 >> 0x10 & 0xff) << 8
                 | local_28 >> 0x18)) && ((node[5] & 2U) != 0)) {
              operandRecord = IRInst__getOperandRecord(inst,0);
              node[0x27] = *(int *)(operandRecord + 0x10);
            }
          }
          else {
            sourceDef = (int *)IRInst__getOperandSource(inst,inst[0x21]);
            operandVReg = (int *)IRInst__getOperandSource(inst,1);
            if (((sourceDef == operandVReg) && ((inst[0x2e] & 2U) == 0)) && ((inst[0x2e] & 1U) == 0))
            {
              iVar2 = 0;
              iVar3 = 4;
              do {
                if (*(char *)((int)&local_5c + iVar2) == '\0') {
                  *(undefined1 *)((int)&local_58 + iVar2) =
                       *(undefined1 *)((int)&DAT_001b004c + iVar2);
                }
                iVar2 = iVar2 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
            else {
              iVar2 = (**(code **)(*sourceDef + 100))(sourceDef);
              if (iVar2 == 0) {
                return 0;
              }
              sourceDef2 = IRInst__getOperandSource(inst,1);
              sourceDef3 = IRInst__getOperandSource(sourceDef,1);
              if (sourceDef2 != sourceDef3) {
                return 0;
              }
              if (((uint)inst[0x2e] >> 1 & 1) != ((uint)sourceDef[0x2e] >> 1 & 1)) {
                return 0;
              }
              if ((inst[0x2e] & 1U) != (sourceDef[0x2e] & 1U)) {
                return 0;
              }
              if (sourceDef[0x48] != 0) {
                return 0;
              }
              if (sourceDef[0x49] != 0) {
                return 0;
              }
              operandRecord = IRInst__getOperandRecord(sourceDef,0);
              local_54 = *(uint *)(operandRecord + 0x10);
              operandRecord = IRInst__getOperandRecord(sourceDef,1);
              local_50 = *(undefined4 *)(operandRecord + 0x10);
              operandRecord = IRInst__getOperandRecord(node,operandIndex);
              SelectWord__readMask(&local_24,*(undefined4 *)(operandRecord + 0x10));
              iVar2 = 0;
              local_4c = local_24;
              iVar3 = 4;
              do {
                if ((*(char *)((int)&local_4c + iVar2) != '\0') &&
                   (*(char *)((int)&local_5c + iVar2) == '\0')) {
                  if (*(char *)((int)&local_54 + iVar2) != '\0') {
                    return 0;
                  }
                  *(undefined1 *)((int)&local_58 + iVar2) = *(undefined1 *)((int)&local_50 + iVar2);
                }
                iVar2 = iVar2 + 1;
                iVar3 = iVar3 + -1;
              } while (iVar3 != 0);
            }
          }
          iVar2 = FUN_00149de4(node,operandIndex,inst,&local_58,*(undefined4 *)(pass + 8));
          if (iVar2 != 0) goto LAB_00160e58;
        }
      }
    }
    return 0;
  }
  if ((node[5] & 0x200U) == 0) {
    return 0;
  }
  sourceDef = (int *)IRInst__getOperandSource(node,node[0x21]);
  if (inst != sourceDef) {
    return 0;
  }
  if ((inst[5] & 0x200U) != 0) {
    return 0;
  }
  if (inst[0x48] != 0) {
    return 0;
  }
  if (inst[0x49] != 0) {
    return 0;
  }
  if ((inst[0x2e] & 1U) != 0) {
    return 0;
  }
  if ((inst[0x2e] & 2U) != 0) {
    return 0;
  }
  if (((inst[0x20] != 0) && (iVar2 = RegKind__flagBit0(inst[0x26]), iVar2 != 0)) &&
     (((inst[5] & 2U) == 0 && (iVar2 = (**(code **)(*inst + 0x50))(inst), iVar2 == 0)))) {
    iVar2 = 4;
    piVar8 = inst;
    do {
      if ((uint)(*(byte *)(piVar8 + 0x27) - 2) < 2) {
        return 0;
      }
      piVar8 = (int *)((int)piVar8 + 1);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  IRInst__getOperandRecord(inst,0);
  iVar2 = IRInst__operandKindClass(inst,0);
  if (iVar2 != 0) {
    return 0;
  }
  sourceDef = (int *)IRInst__getOperandSource(inst,1);
  if (sourceDef[0x20] == 0) {
    return 0;
  }
  flagBit0Result = RegKind__flagBit0(sourceDef[0x26]);
  if (flagBit0Result == 0) {
    return 0;
  }
  if ((sourceDef[5] & 2U) != 0) {
    return 0;
  }
  iVar2 = (**(code **)(*sourceDef + 0x50))(sourceDef);
  if (iVar2 != 0) {
    return 0;
  }
  isSourceSelectIdentity = IRInst__isSourceSelectIdentity(inst,1);
  if (isSourceSelectIdentity == 0) {
    return 0;
  }
  sourceDef = (int *)IRInst__getOperandSource(inst,1);
  iVar2 = (**(code **)(*sourceDef + 0x5c))(sourceDef);
  if (iVar2 != 0) {
    return 0;
  }
  if (*(int *)(*(int *)(pass + 8) + 0x660) <= *(int *)(pass + 0x17c)) {
    return 0;
  }
  operandRecord = IRInst__getOperandRecord(inst,0);
  WriteMask__fromSelectWord(auStack_38,*(undefined4 *)(operandRecord + 0x10));
  operandRecord = IRInst__getOperandRecord(node,0);
  FUN_000f3968(auStack_34,*(undefined4 *)(operandRecord + 0x10),0x1010101);
  *(int *)(pass + 0x17c) = *(int *)(pass + 0x17c) + 1;
  hasSingleUse = IRInst__hasSingleUse(inst,pass);
  if (hasSingleUse == 0) {
    sourceDef4 = IRInst__getOperandSource(inst,1);
    IRInst__setExtraOperandSource(node,sourceDef4,0,*(undefined4 *)(pass + 8));
    inst[0x58] = inst[0x58] + -1;
    sourceDef2 = IRInst__getOperandSource(inst,1);
    if (*(int *)(pass + 0x478) < *(int *)(sourceDef2 + 0x160)) {
      *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + 1;
    }
    else {
      *(int *)(sourceDef2 + 0x160) = *(int *)(pass + 0x478) + 1;
    }
    goto LAB_00160e58;
  }
  iVar2 = (**(code **)(*node + 100))(node);
  if (iVar2 == 0) {
LAB_0016086c:
    sourceDef4 = IRInst__getOperandSource(inst,1);
    IRInst__setExtraOperandSource(node,sourceDef4,0,*(undefined4 *)(pass + 8));
  }
  else {
    sourceDef2 = IRInst__getOperandSource(node,1);
    sourceDef3 = IRInst__getOperandSource(inst,1);
    if (((sourceDef2 != sourceDef3) || (node[0x48] != inst[0x48])) || (node[0x49] != inst[0x49]))
    goto LAB_0016086c;
    if (((node[0x2e] & 1U) != (inst[0x2e] & 1U)) ||
       (((uint)node[0x2e] >> 1 & 1) != ((uint)inst[0x2e] >> 1 & 1))) goto LAB_0016086c;
    operandRecord = IRInst__getOperandRecord(inst,0);
    uVar1 = *(uint *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(node,0);
    local_48 = *(uint *)(operandRecord + 0x10);
    uVar1 = (uVar1 << 0x18 | (uVar1 >> 8 & 0xff) << 0x10 | (uVar1 >> 0x10 & 0xff) << 8 |
            uVar1 >> 0x18) &
            (local_48 << 0x18 | (local_48 >> 8 & 0xff) << 0x10 | (local_48 >> 0x10 & 0xff) << 8 |
            local_48 >> 0x18);
    local_54 = uVar1 << 0x18 | (uVar1 & 0xff00) << 8 | uVar1 >> 8 & 0xff00 | uVar1 >> 0x18;
    node[0x27] = local_54;
    operandRecord = IRInst__getOperandRecord(node,1);
    local_58 = *(undefined4 *)(operandRecord + 0x10);
    operandRecord2 = IRInst__getOperandRecord(inst,1);
    iVar2 = 0;
    local_5c = *(uint *)(operandRecord2 + 0x10);
    iVar3 = 4;
    do {
      if (*(char *)((int)&local_58 + iVar2) == '\x04') {
        *(undefined1 *)((int)&local_58 + iVar2) = *(undefined1 *)((int)&local_5c + iVar2);
      }
      uVar6 = local_58;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    operandRecord = IRInst__getOperandRecord(node,1);
    *(undefined4 *)(operandRecord + 0x10) = uVar6;
    IRInst__setOperandSource(node,node[0x21],0,0,*(undefined4 *)(pass + 8));
    node[0x21] = node[0x21] + -1;
    node[5] = node[5] & 0xfffffdff;
    sourceDef2 = IRInst__getOperandSource(node,1);
    *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + -1;
  }
  (**(code **)(*inst + 0xc))(inst,0,*(undefined4 *)(pass + 8));
LAB_00160e58:
  *param_5 = 1;
  return 1;
}

/* FUN_00160eb0 @ 0x160eb0 (2064 bytes) */
int FUN_00160eb0(param_1, param_2, inst, program)
  undefined4 param_1;
  undefined4 param_2;
  int inst;
  int program;
{
  int afterInst;
  int powOfConstEnabled;
  int sourceDef;
  int operandRecord3;
  int operandRecord2;
  int operandRecord;
  int operandRecord4;
  int loopIndex;
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *inst1;
  int iVar8;
  int iVar9;
  int iVar10;
  int saturate;
  int *newSource;
  int *inst3;
  int *piVar14;
  int iVar15;
  undefined4 local_98;
  int *local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  undefined1 local_74 [3];
  undefined1 uStack_71;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  int *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_48;
  int local_44;
  
  powOfConstEnabled = Compiler__isOptionEnabled(*(undefined4 *)(program + 8),0x1e);
  if ((powOfConstEnabled != 0) && ((*(uint *)(inst + 0x14) & 0x400000) == 0)) {
    local_78 = 0;
    local_6c = 4;
    local_94 = (int *)0x0;
    local_90 = 0;
    local_88 = 0;
    local_84 = 0;
    local_80 = 0;
    local_7c = 0;
    local_70 = 4;
    iVar4 = ((int (*)())FUN_0015b974)(inst,&local_64,&local_8c,&local_80,local_74);
    if ((iVar4 != 0) && ((-1 < local_80 && (local_80 < 3)))) {
      operandRecord = IRInst__getOperandRecord(inst,0);
      iVar4 = *(int *)(operandRecord + 0x10);
      operandRecord2 = IRInst__getOperandRecord(inst,0);
      piVar14 = (int *)0x0;
      iVar5 = SelectWord__splatComponent(*(undefined4 *)(operandRecord2 + 0x10));
      if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
        piVar14 = (int *)IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
      }
      bVar1 = piVar14 == (int *)0x0;
      saturate = *(int *)(inst + 0x120);
      if (bVar1) {
        inst3 = (int *)0x0;
        newSource = (int *)0x0;
        local_78 = local_80;
        iVar6 = -1;
        local_7c = local_80;
        iVar8 = -1;
      }
      else {
        iVar6 = IRInst__hasSingleUse(piVar14,program);
        if (((((iVar6 == 0) ||
              (iVar6 = ((int (*)())FUN_0015b974)(piVar14,&local_94,&local_88,&local_7c,&local_70), iVar6 == 0))
             || (local_8c != local_88)) ||
            ((iVar6 = FUN_0014700c(local_64,local_94), iVar6 == 0 || (local_80 != local_7c)))) ||
           (saturate != piVar14[0x48])) {
          bVar1 = true;
          inst3 = (int *)0x0;
          iVar6 = -1;
          iVar8 = -1;
          local_94 = (int *)0x0;
          newSource = piVar14;
          piVar14 = (int *)0x0;
          local_7c = local_80;
          local_78 = local_80;
        }
        else {
          operandRecord3 = IRInst__getOperandRecord(piVar14,0);
          SelectWord__mergeWrittenLanes(&local_48,iVar4,*(undefined4 *)(operandRecord3 + 0x10));
          operandRecord = IRInst__getOperandRecord(piVar14,0);
          iVar6 = SelectWord__splatComponent(*(undefined4 *)(operandRecord + 0x10));
          iVar4 = local_48;
          if (((piVar14[5] & 0x200U) == 0) ||
             (inst1 = (int *)IRInst__getOperandSource(piVar14,piVar14[0x21]), inst1 == (int *)0x0)) {
            inst3 = (int *)0x0;
            iVar8 = -1;
            local_78 = local_80;
            newSource = (int *)0x0;
          }
          else {
            iVar8 = IRInst__hasSingleUse(inst1,program);
            if ((((iVar8 == 0) ||
                 (iVar8 = ((int (*)())FUN_0015b974)(inst1,&local_90,&local_84,&local_78,&local_6c), iVar8 == 0))
                || (local_88 != local_84)) ||
               (((iVar8 = FUN_0014700c(local_94,local_90), iVar8 == 0 || (local_80 != local_78)) ||
                (saturate != inst1[0x48])))) {
              inst3 = (int *)0x0;
              iVar8 = -1;
              local_90 = 0;
              newSource = inst1;
              local_78 = local_80;
            }
            else {
              operandRecord = IRInst__getOperandRecord(inst1,0);
              SelectWord__mergeWrittenLanes(&local_44,local_48,*(undefined4 *)(operandRecord + 0x10));
              operandRecord = IRInst__getOperandRecord(inst1,0);
              iVar8 = SelectWord__splatComponent(*(undefined4 *)(operandRecord + 0x10));
              iVar4 = local_44;
              newSource = (int *)0x0;
              inst3 = inst1;
            }
          }
        }
      }
      if (local_8c == 0) {
        iVar9 = (**(code **)(*local_64 + 0x5c))(local_64);
        if (iVar9 != 0) {
          local_64[0x27] = iVar4;
          loopIndex = 1;
          while( true ) {
            iVar10 = (**(code **)(*local_64 + 0x14))(local_64);
            if (iVar10 < loopIndex) break;
            operandRecord4 = IRInst__getOperandRecord(local_64,loopIndex);
            *(undefined4 *)(operandRecord4 + 0x10) = 0x10203;
            (**(code **)(*local_64 + 0x88))(local_64,loopIndex,3,4);
            loopIndex = loopIndex + 1;
          }
        }
        FUN_00147704(inst,piVar14,inst3,program);
        if (bVar1) {
          iVar9 = 0;
        }
        else {
          iVar9 = 1;
          (**(code **)(*piVar14 + 0xc))(piVar14,0,*(undefined4 *)(program + 8));
          if (inst3 != (int *)0x0) {
            iVar9 = 2;
            (**(code **)(*inst3 + 0xc))(inst3,0,*(undefined4 *)(program + 8));
          }
        }
        if (local_80 == 2) {
          iVar9 = iVar9 + -1;
        }
        iVar10 = (**(code **)(*local_64 + 0x5c))(local_64);
        if (iVar10 == 0) {
          if (local_94 == (int *)0x0) {
            local_94 = local_64;
          }
          if (iVar9 < 0) {
            if (*(int *)(program + 0x478) < local_64[0x58]) {
              local_64[0x58] = local_64[0x58] + 1;
            }
            else {
              local_64[0x58] = *(int *)(program + 0x478) + 1;
            }
          }
          else if (0 < iVar9) {
            do {
              local_64[0x58] = local_64[0x58] + -1;
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
        }
        else if (local_94 == (int *)0x0) {
          if (iVar9 < 0) {
            iVar10 = *(int *)(program + 0x478);
            local_94 = (int *)IRInst__clone(local_64,*(undefined4 *)(program + 8),0);
            iVar15 = iVar10 + 1;
            local_94[0x26] = 0x31;
            local_94[0x25] = local_94[0x53];
            Block__insertInstAfter(local_64[0x56],local_64,local_94);
            local_94[0x58] = iVar15;
            sourceDef = IRInst__getOperandSource(local_94,1);
            if (iVar10 < *(int *)(sourceDef + 0x160)) {
              *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
            }
            else {
              *(int *)(sourceDef + 0x160) = iVar15;
            }
            if (1 < local_94[0x21]) {
              sourceDef = IRInst__getOperandSource(local_94,2);
              if (iVar10 < *(int *)(sourceDef + 0x160)) {
                *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
              }
              else {
                *(int *)(sourceDef + 0x160) = iVar15;
              }
            }
          }
        }
        else if ((0 < iVar9) &&
                ((local_90 == 0 ||
                 (IRInst__dropCounterAndDeleteIfUnused(local_90,*(undefined4 *)(program + 8)), 0 < iVar9 + -1)))) {
          IRInst__dropCounterAndDeleteIfUnused(local_94,*(undefined4 *)(program + 8));
        }
        local_68 = 0x4040404;
        *(undefined1 *)((int)&local_68 + iVar5) = uStack_71;
        if (-1 < iVar6) {
          *(char *)((int)&local_68 + iVar6) = (char)local_70;
        }
        if (-1 < iVar8) {
          *(char *)((int)&local_68 + iVar8) = (char)local_6c;
        }
        local_60 = 0;
        local_5c = 0;
        local_58 = 0;
        afterInst = *(int *)(inst + 4);
        IRInst__saveCounters(inst,&local_60,0xffffffff);
        DList__unlink(inst);
        local_98 = 0;
        if (local_80 == 0) {
          IRInst__reinitAsMov(inst,0x31,*(undefined4 *)(program + 8));
          *(int *)(inst + 0x9c) = iVar4;
          Block__insertInstAfter(*(undefined4 *)(afterInst + 0x158),afterInst,inst);
          ((void (*)())IRInst__makeLiteralVec4Float)(inst,program,1,1.0,1.0,1.0,1.0);
          IRInst__restoreCounters(inst,&local_60);
          if (newSource != (int *)0x0) {
            IRInst__setExtraOperandSource(inst,newSource,0,*(undefined4 *)(program + 8));
          }
        }
        else {
          if (local_80 != 1) {
            IRInst__reinitAsBinary(inst,0x13,*(undefined4 *)(program + 8));
            *(int *)(inst + 0x9c) = iVar4;
            IRInst__restoreCounters(inst,&local_60);
            Block__insertInstAfter(*(undefined4 *)(afterInst + 0x158),afterInst,inst);
            IRInst__setOperandSource(inst,1,local_64,0,*(undefined4 *)(program + 8));
            IRInst__setOperandSource(inst,2,local_94,0,*(undefined4 *)(program + 8));
            uVar2 = local_68;
            operandRecord = IRInst__getOperandRecord(inst,1);
            uVar3 = local_68;
            *(undefined4 *)(operandRecord + 0x10) = uVar2;
            operandRecord = IRInst__getOperandRecord(inst,2);
            *(undefined4 *)(operandRecord + 0x10) = uVar3;
            if (newSource != (int *)0x0) {
              IRInst__setExtraOperandSource(inst,newSource,0,*(undefined4 *)(program + 8));
            }
            *(undefined4 *)(inst + 0x98) = 0;
            *(int *)(inst + 0x120) = saturate;
            *(undefined4 *)(inst + 0x94) = *(undefined4 *)(inst + 0x14c);
            return 1;
          }
          IRInst__reinitAsMov(inst,0x31,*(undefined4 *)(program + 8));
          IRInst__restoreCounters(inst,&local_60);
          *(int *)(inst + 0x9c) = iVar4;
          Block__insertInstAfter(*(undefined4 *)(afterInst + 0x158),afterInst,inst);
          IRInst__setOperandSource(inst,1,local_64,0,*(undefined4 *)(program + 8));
          uVar2 = local_68;
          operandRecord = IRInst__getOperandRecord(inst,1);
          *(undefined4 *)(operandRecord + 0x10) = uVar2;
          IROperand__setModifierBits(inst + 0xa4,2,1);
          *(undefined4 *)(inst + 0x98) = 0;
          *(undefined4 *)(inst + 0x94) = *(undefined4 *)(inst + 0x14c);
          if (newSource != (int *)0x0) {
            IRInst__setExtraOperandSource(inst,newSource,0,*(undefined4 *)(program + 8));
          }
          *(int *)(inst + 0x120) = saturate;
        }
        ((int (*)())Inst__foldProducerIntoConsumer)(param_1,param_2,inst,program,&local_98);
        return 1;
      }
      if (!bVar1) {
        FUN_000da09c(*(undefined4 *)(*(int *)(program + 8) + 0x398),*(uint *)(program + 0x30) & 1);
      }
      return 1;
    }
  }
  return 0;
}

/* FUN_00161748 @ 0x161748 (2688 bytes) */
int FUN_00161748(inst, inst2, pass)
  int *inst;
  int *inst2;
  int pass;
{
  uint source1Flags;
  int saturate;
  int resultScaleCode;
  int cloneResult;
  int splitRgbAlphaEnabled;
  undefined4 sourceDef5;
  undefined4 sourceDef;
  int operandRecord2;
  int sourceDef4;
  int sourceDef3;
  int operandRecord;
  int sourceDef2;
  int operandRecord3;
  bool bVar1;
  bool bVar2;
  undefined1 uVar3;
  bool bVar4;
  code *pcVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int *piVar12;
  int iVar13;
  int *operandVReg;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78 [6];
  undefined4 local_60;
  int local_58 [5];
  
  iVar7 = (**(code **)(*inst + 100))(inst,inst2,pass);
  if ((iVar7 != 0) && (iVar7 = (**(code **)(*inst2 + 100))(inst2), iVar7 != 0)) {
    sourceDef = IRInst__getOperandSource(inst,1);
    sourceDef5 = IRInst__getOperandSource(inst2,1);
    iVar7 = Inst__opcodeOrSourcesDiffer(sourceDef,sourceDef5);
    if (iVar7 == 0) {
      sourceDef4 = IRInst__getOperandSource(inst,1);
      iVar10 = IRInst__getOperandSource(inst2,1);
      if (sourceDef4 != iVar10) {
        sourceDef = IRInst__getOperandSource(inst,1);
        uVar9 = *(undefined4 *)(pass + 8);
        operandRecord2 = IRInst__getOperandRecord(inst,1);
        iVar7 = IRInst__allSelectsAreHwConstants(sourceDef,uVar9,*(undefined4 *)(operandRecord2 + 0x10),in_r6,in_r7,in_r8,in_r9);
        sourceDef = IRInst__getOperandSource(inst2,1);
        uVar9 = *(undefined4 *)(pass + 8);
        bVar1 = iVar7 == 0;
        operandRecord2 = IRInst__getOperandRecord(inst2,1);
        iVar7 = IRInst__allSelectsAreHwConstants(sourceDef,uVar9,*(undefined4 *)(operandRecord2 + 0x10),in_r6,in_r7,in_r8,in_r9);
        if ((!bVar1) || (iVar7 != 0)) {
          if (((inst[0x2e] & 1U) != (inst2[0x2e] & 1U)) &&
             ((iVar7 == 0 || (iVar10 = FUN_00151318(inst2), iVar10 == 0)))) {
            if (bVar1) {
              return 0;
            }
            iVar10 = FUN_00151318(inst);
            if (iVar10 == 0) {
              return 0;
            }
            if ((((uint)inst[0x2e] >> 1 & 1) != ((uint)inst2[0x2e] >> 1 & 1)) &&
               ((((inst[0x2e] & 2U) == 0 || (iVar7 == 0)) && ((inst2[0x2e] & 2U) == 0)))) {
              return 0;
            }
          }
          if ((((inst2[0x48] == inst[0x48]) || ((inst2[0x48] != 0 && (iVar7 != 0)))) ||
              ((inst[0x48] != 0 && (!bVar1)))) &&
             (((inst[0x49] == inst2[0x49] ||
               ((iVar7 != 0 && (iVar10 = FUN_00151318(inst2), iVar10 != 0)))) ||
              ((!bVar1 && (iVar10 = FUN_00151318(inst), iVar10 != 0)))))) {
            operandRecord3 = IRInst__getOperandRecord(inst,0);
            local_88 = *(undefined4 *)(operandRecord3 + 0x10);
            operandRecord = IRInst__getOperandRecord(inst2,0);
            iVar10 = 0;
            local_84 = *(undefined4 *)(operandRecord + 0x10);
            iVar11 = 4;
            do {
              if ((*(char *)((int)&local_88 + iVar10) != '\x01') &&
                 (*(char *)((int)&local_84 + iVar10) != '\x01')) {
                return 0;
              }
              iVar10 = iVar10 + 1;
              iVar11 = iVar11 + -1;
            } while (iVar11 != 0);
            splitRgbAlphaEnabled = Compiler__isOptionEnabled(*(undefined4 *)(pass + 8),0x30);
            if ((splitRgbAlphaEnabled == 0) || (((char)local_88 != '\0' && ((char)local_84 != '\0')))) {
              resultScaleCode = inst2[0x49];
              if ((inst[0x49] != resultScaleCode) && (iVar7 != 0)) {
                iVar10 = FUN_00151318(inst2);
                if (iVar10 == 0) {
                  resultScaleCode = inst2[0x49];
                }
                else {
                  resultScaleCode = inst[0x49];
                }
              }
              bVar4 = iVar7 == 0;
              saturate = inst2[0x48];
              if ((inst[0x48] != saturate) && (!bVar4)) {
                iVar7 = FUN_00151318(inst2);
                if (iVar7 == 0) {
                  saturate = inst2[0x48];
                }
                else {
                  saturate = inst[0x48];
                }
              }
              uVar17 = inst[0x2e];
              source1Flags = inst2[0x2e];
              uVar16 = uVar17 & 1;
              if (uVar16 != (source1Flags & 1)) {
                if ((bVar4) || (iVar11 = FUN_00151318(inst2), iVar11 == 0)) {
                  if ((bVar1) || (iVar11 = FUN_00151318(inst), iVar11 == 0)) {
                    uVar17 = inst[0x2e];
                    uVar16 = 0;
                    source1Flags = inst2[0x2e];
                  }
                  else {
                    source1Flags = inst2[0x2e];
                    uVar17 = inst[0x2e];
                    uVar16 = source1Flags & 1;
                  }
                }
                else {
                  uVar17 = inst[0x2e];
                  source1Flags = inst2[0x2e];
                  uVar16 = uVar17 & 1;
                }
              }
              uVar6 = source1Flags >> 1 & 1;
              uVar17 = uVar17 >> 1 & 1;
              uVar15 = uVar6;
              if (((uVar17 != uVar6) && (uVar15 = uVar17, bVar4)) && (uVar15 = uVar6, bVar1)) {
                uVar15 = 0;
              }
              operandRecord = IRInst__getOperandRecord(inst,1);
              local_80 = *(undefined4 *)(operandRecord + 0x10);
              operandRecord = IRInst__getOperandRecord(inst2,1);
              local_7c = *(undefined4 *)(operandRecord + 0x10);
              SelectWord__mergeWrittenLanes(local_58,local_84,local_88);
              local_78[0] = local_58[0];
              piVar12 = (int *)IRLoadConst__vslot73(0xa2,*(undefined4 *)(pass + 8));
              piVar12[0x26] = 0x36;
              piVar12[0x25] = piVar12[0x53];
              piVar12[0x21] = 2;
              if (bVar4) {
                sourceDef = IRInst__getOperandSource(inst2,1);
              }
              else {
                sourceDef = IRInst__getOperandSource(inst,1);
              }
              IRInst__setOperandSource(piVar12,1,sourceDef,0,*(undefined4 *)(pass + 8));
              sourceDef3 = IRInst__getOperandSource(piVar12,1);
              if (*(int *)(pass + 0x478) < *(int *)(sourceDef3 + 0x160)) {
                *(int *)(sourceDef3 + 0x160) = *(int *)(sourceDef3 + 0x160) + 1;
              }
              else {
                *(int *)(sourceDef3 + 0x160) = *(int *)(pass + 0x478) + 1;
              }
              if (bVar4) {
                sourceDef = IRInst__getOperandSource(inst,1);
              }
              else {
                sourceDef = IRInst__getOperandSource(inst2,1);
              }
              IRInst__setOperandSource(piVar12,2,sourceDef,0,*(undefined4 *)(pass + 8));
              sourceDef3 = IRInst__getOperandSource(piVar12,2);
              if (*(int *)(pass + 0x478) < *(int *)(sourceDef3 + 0x160)) {
                *(int *)(sourceDef3 + 0x160) = *(int *)(sourceDef3 + 0x160) + 1;
              }
              else {
                *(int *)(sourceDef3 + 0x160) = *(int *)(pass + 0x478) + 1;
              }
              sourceDef3 = IRInst__getOperandSource(inst,1);
              *(int *)(sourceDef3 + 0x160) = *(int *)(sourceDef3 + 0x160) + -1;
              IRInst__setOperandSource(inst,1,piVar12,0,*(undefined4 *)(pass + 8));
              piVar12[0x58] = *(int *)(pass + 0x478) + 1;
              piVar12[0x27] = 0x1010101;
              operandRecord = IRInst__getOperandRecord(piVar12,1);
              *(undefined4 *)(operandRecord + 0x10) = 0x4040404;
              operandRecord = IRInst__getOperandRecord(piVar12,2);
              *(undefined4 *)(operandRecord + 0x10) = 0x10203;
              operandRecord = IRInst__getOperandRecord(inst,1);
              *(undefined4 *)(operandRecord + 0x10) = 0x4040404;
              if (bVar4) {
                uVar9 = 1;
                uVar8 = 2;
              }
              else {
                uVar9 = 2;
                uVar8 = 1;
              }
              uVar17 = 0;
              iVar11 = 0;
              do {
                iVar13 = IRInst__getOperandRecord(inst,0);
                if ((*(char *)(iVar11 + iVar13 + 0x10) != '\0') || ((!bVar1 && (bVar4)))) {
                  iVar13 = IRInst__getOperandRecord(inst2,0);
                  if ((*(char *)(iVar11 + iVar13 + 0x10) == '\0') && (bVar4)) {
                    uVar6 = (uint)*(byte *)((int)&local_7c + iVar11);
                    (**(code **)(*piVar12 + 0x88))(piVar12,uVar9,uVar6,uVar6);
                    (**(code **)(*piVar12 + 0x88))(piVar12,uVar8,uVar6,4);
                    *(undefined1 *)((int)piVar12 + uVar6 + 0x9c) = 0;
                    pcVar5 = *(code **)(*inst + 0x88);
                    goto LAB_00161e24;
                  }
                  (**(code **)(*piVar12 + 0x88))(piVar12,2,iVar11,4);
                }
                else {
                  IRInst__getOperandRecord(inst2,0);
                  uVar6 = (uint)*(byte *)((int)&local_80 + iVar11);
                  (**(code **)(*piVar12 + 0x88))(piVar12,uVar8,uVar6,uVar6);
                  *(undefined1 *)((int)piVar12 + uVar6 + 0x9c) = 0;
                  (**(code **)(*piVar12 + 0x88))(piVar12,uVar9,uVar6,4);
                  pcVar5 = *(code **)(*inst + 0x88);
LAB_00161e24:
                  uVar17 = uVar17 | 1 << (uVar6 & 0x3f);
                  (*pcVar5)(inst,1,iVar11,uVar6);
                }
                bVar2 = iVar11 == 3;
                iVar11 = iVar11 + 1;
                if (bVar2) {
                  iVar11 = 0;
                  do {
                    if ((*(char *)((int)local_78 + iVar11) == '\0') &&
                       (iVar13 = IRInst__getOperandRecord(inst,1),
                       *(char *)(iVar11 + iVar13 + 0x10) == '\x04')) {
                      if ((uVar17 & 1) == 0) {
                        iVar13 = 0;
                        uVar6 = 1;
                      }
                      else if ((uVar17 & 2) == 0) {
                        iVar13 = 1;
                        uVar6 = 2;
                      }
                      else if ((uVar17 & 4) == 0) {
                        iVar13 = 2;
                        uVar6 = 4;
                      }
                      else {
                        iVar13 = 3;
                        uVar6 = 0;
                      }
                      uVar17 = uVar17 ^ uVar6;
                      (**(code **)(*inst + 0x88))(inst,1,iVar11,iVar13);
                      if (bVar4) {
                        uVar3 = *(undefined1 *)((int)&local_80 + iVar11);
                      }
                      else {
                        uVar3 = *(undefined1 *)((int)&local_7c + iVar11);
                      }
                      (**(code **)(*piVar12 + 0x88))(piVar12,2,iVar13,uVar3);
                      *(undefined1 *)((int)piVar12 + iVar13 + 0x9c) = 0;
                    }
                    bVar1 = iVar11 != 3;
                    iVar11 = iVar11 + 1;
                  } while (bVar1);
                  Block__insertInstBefore(inst[0x56],inst,piVar12);
                  inst[0x27] = local_78[0];
                  IROperand__setModifierBits(inst + 0x29,1,uVar16);
                  IROperand__setModifierBits(inst + 0x29,2,uVar15);
                  inst[0x49] = resultScaleCode;
                  inst[0x48] = saturate;
                  IRInst__setOperandSource(inst,inst[0x21],0,0,*(undefined4 *)(pass + 8));
                  inst[5] = inst[5] & 0xfffffdff;
                  uVar16 = inst2[5];
                  inst[0x21] = inst[0x21] + -1;
                  if ((uVar16 & 0x200) != 0) {
                    sourceDef4 = IRInst__getOperandSource(inst2,inst2[0x21]);
                    local_60 = 0;
                    local_78[1] = 0;
                    local_78[2] = 0;
                    IRInst__readLastOperand(inst2,local_78 + 1);
                    IRInst__setLastOperandFromRecord(inst,local_78 + 1,0,*(undefined4 *)(pass + 8));
                    if (*(int *)(pass + 0x478) < *(int *)(sourceDef4 + 0x160)) {
                      *(int *)(sourceDef4 + 0x160) = *(int *)(sourceDef4 + 0x160) + 1;
                    }
                    else {
                      *(int *)(sourceDef4 + 0x160) = *(int *)(pass + 0x478) + 1;
                    }
                  }
                  operandVReg = (int *)IRInst__getOperandSource(piVar12,1);
                  iVar7 = (**(code **)(*operandVReg + 0x60))(operandVReg);
                  if (iVar7 != 0) {
                    sourceDef = IRInst__getOperandSource(piVar12,1);
                    FUN_0010c670(sourceDef,piVar12,*(undefined4 *)(pass + 8));
                  }
                  IRInst__dropCounterAndDeleteIfUnused(inst2,*(undefined4 *)(pass + 8));
                  if ((inst2[5] & 1U) != 0) {
                    operandVReg = (int *)IRInst__getOperandSource(piVar12,1);
                    iVar7 = (**(code **)(*operandVReg + 0x5c))(operandVReg);
                    if (iVar7 != 0) {
                      sourceDef = IRInst__getOperandSource(piVar12,1);
                      cloneResult = IRInst__clone(sourceDef,*(undefined4 *)(pass + 8),0);
                      iVar11 = *(int *)(pass + 0x478);
                      *(undefined4 *)(cloneResult + 0x94) = *(undefined4 *)(cloneResult + 0x14c);
                      *(undefined4 *)(cloneResult + 0x98) = 0x31;
                      sourceDef2 = IRInst__getOperandSource(piVar12,1);
                      uVar9 = *(undefined4 *)(sourceDef2 + 0x158);
                      sourceDef = IRInst__getOperandSource(piVar12,1);
                      iVar13 = iVar11 + 1;
                      Block__insertInstAfter(uVar9,sourceDef,cloneResult);
                      *(int *)(cloneResult + 0x160) = iVar13;
                      sourceDef2 = IRInst__getOperandSource(piVar12,1);
                      *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + -1;
                      sourceDef2 = IRInst__getOperandSource(cloneResult,1);
                      if (iVar11 < *(int *)(sourceDef2 + 0x160)) {
                        *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + 1;
                      }
                      else {
                        *(int *)(sourceDef2 + 0x160) = iVar13;
                      }
                      if (1 < *(int *)(cloneResult + 0x84)) {
                        sourceDef2 = IRInst__getOperandSource(cloneResult,2);
                        if (iVar11 < *(int *)(sourceDef2 + 0x160)) {
                          *(int *)(sourceDef2 + 0x160) = *(int *)(sourceDef2 + 0x160) + 1;
                        }
                        else {
                          *(int *)(sourceDef2 + 0x160) = iVar13;
                        }
                      }
                      IRInst__setOperandSource(piVar12,1,cloneResult,0,*(undefined4 *)(pass + 8));
                      return 1;
                    }
                  }
                  return 1;
                }
              } while( true );
            }
          }
        }
      }
    }
  }
  return 0;
}

/* FUN_001621c8 @ 0x1621c8 (2404 bytes) */
int FUN_001621c8(inst, inst2, pass)
  int *inst;
  int *inst2;
  int pass;
{
  uint source1Flags2;
  uint source1Flags;
  int *afterInst;
  int newSource2;
  int newSource;
  int firstWrittenComponentResult;
  int definingField1282;
  int definingField128;
  int flagBit7Result;
  int splitRgbAlphaEnabled;
  undefined4 sourceDef4;
  int operandRecord3;
  int sourceDef3;
  int sourceDef;
  int operandRecord2;
  int operandRecord;
  int sourceDef2;
  int useCount;
  int operandRecord4;
  bool bVar1;
  bool bVar2;
  undefined1 uVar3;
  float *pfVar4;
  uint source1Flags3;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  undefined4 uVar10;
  int iVar11;
  float *pfVar12;
  uint uVar13;
  uint uVar14;
  int saturate;
  int iVar16;
  int *inst1;
  int *inst3;
  int destRegisterOffset;
  int destRegister;
  double dVar21;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  int local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  float local_b8 [4];
  float local_a8 [4];
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_84;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 *local_68;
  
  iVar6 = (**(code **)(*inst + 100))(inst,inst2,pass);
  if (iVar6 == 0) {
    return 0;
  }
  iVar6 = (**(code **)(*inst2 + 100))(inst2);
  if (iVar6 == 0) {
    return 0;
  }
  sourceDef2 = IRInst__getOperandSource(inst2,1);
  if (sourceDef2 == 0) {
    iVar6 = inst2[0x2c];
  }
  else {
    sourceDef2 = IRInst__getOperandSource(inst2,1);
    iVar6 = *(int *)(sourceDef2 + 0x98);
  }
  flagBit7Result = RegKind__flagBit7(iVar6);
  if (flagBit7Result == 0) {
    return 0;
  }
  operandRecord = IRInst__getOperandRecord(inst,0);
  local_d8 = *(int *)(operandRecord + 0x10);
  operandRecord2 = IRInst__getOperandRecord(inst2,0);
  iVar6 = 0;
  local_d4 = *(undefined4 *)(operandRecord2 + 0x10);
  iVar7 = 4;
  do {
    if ((*(char *)((int)&local_d8 + iVar6) != '\x01') &&
       (*(char *)((int)&local_d4 + iVar6) != '\x01')) {
      return 0;
    }
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  splitRgbAlphaEnabled = Compiler__isOptionEnabled(*(undefined4 *)(pass + 8),0x30);
  if (splitRgbAlphaEnabled != 0) {
    if ((char)local_d8 == '\0') {
      return 0;
    }
    if ((char)local_d4 == '\0') {
      return 0;
    }
  }
  if (inst2[0x48] != 0) {
    return 0;
  }
  iVar16 = inst[0x49];
  iVar6 = inst2[0x49];
  sourceDef = IRInst__getOperandSource(inst,1);
  sourceDef3 = IRInst__getOperandSource(inst2,1);
  if (sourceDef == sourceDef3) {
    source1Flags = inst[0x2e];
    if (((inst2[0x2e] & 1U) == (source1Flags & 1)) &&
       (((uint)inst2[0x2e] >> 1 & 1) == (source1Flags >> 1 & 1))) {
      definingField128 = IRInst__getDefiningField128(inst2,1);
      definingField1282 = IRInst__getDefiningField128(inst,1);
      if ((definingField128 == definingField1282) && (iVar16 == iVar6)) {
        operandRecord = IRInst__getOperandRecord(inst,1);
        local_d0 = *(undefined4 *)(operandRecord + 0x10);
        operandRecord = IRInst__getOperandRecord(inst2,1);
        local_cc = *(undefined4 *)(operandRecord + 0x10);
        local_c8 = 0x4040404;
        iVar6 = 0;
        iVar7 = 4;
        do {
          if (*(char *)((int)&local_d8 + iVar6) == '\0') {
            *(undefined1 *)((int)&local_c8 + iVar6) = *(undefined1 *)((int)&local_d0 + iVar6);
          }
          else if (*(char *)((int)&local_d4 + iVar6) == '\0') {
            *(undefined1 *)((int)&local_c8 + iVar6) = *(undefined1 *)((int)&local_cc + iVar6);
          }
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        iVar6 = 0;
        iVar7 = 4;
        do {
          if (*(char *)((int)&local_d4 + iVar6) != '\x01') {
            *(char *)((int)&local_d8 + iVar6) = *(char *)((int)&local_d4 + iVar6);
          }
          uVar10 = local_c8;
          iVar6 = iVar6 + 1;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        inst[0x27] = local_d8;
        operandRecord = IRInst__getOperandRecord(inst,1);
        *(undefined4 *)(operandRecord + 0x10) = uVar10;
        iVar6 = 0;
        IRInst__setOperandSource(inst,inst[0x21],0,0,*(undefined4 *)(pass + 8));
        inst[5] = inst[5] & 0xfffffdff;
        uVar13 = inst2[5];
        inst[0x21] = inst[0x21] + -1;
        if ((uVar13 & 0x200) != 0) {
          iVar6 = IRInst__getOperandSource(inst2,inst2[0x21]);
          uVar13 = inst2[5];
        }
        local_84 = 0;
        local_98 = 0;
        local_94 = 0;
        if ((uVar13 & 0x200) != 0) {
          IRInst__readLastOperand(inst2,&local_98);
        }
        if (iVar6 != 0) {
          IRInst__setLastOperandFromRecord(inst,&local_98,0,*(undefined4 *)(pass + 8));
          if (*(int *)(pass + 0x478) < *(int *)(iVar6 + 0x160)) {
            *(int *)(iVar6 + 0x160) = *(int *)(iVar6 + 0x160) + 1;
          }
          else {
            *(int *)(iVar6 + 0x160) = *(int *)(pass + 0x478) + 1;
          }
        }
        IRInst__dropCounterAndDeleteIfUnused(inst2,*(undefined4 *)(pass + 8));
        return 1;
      }
      goto LAB_00162370;
    }
  }
  else {
LAB_00162370:
    source1Flags = inst[0x2e];
  }
  if (((((source1Flags & 1) == 0) && ((source1Flags & 2) == 0)) && (inst[0x48] == 0)) && (inst[0x49] == 0)
     ) {
    bVar2 = true;
    iVar7 = 0;
    do {
      iVar8 = IRInst__getOperandRecord(inst,0);
      if ((*(char *)(iVar7 + iVar8 + 0x10) == '\x01') &&
         (iVar8 = IRInst__getOperandRecord(inst2,0), *(char *)(iVar7 + iVar8 + 0x10) == '\x01')) {
        bVar2 = false;
      }
      bVar1 = iVar7 != 3;
      iVar7 = iVar7 + 1;
    } while (bVar1);
    if ((bVar2) &&
       ((iVar7 = FUN_000f5a0c(inst,1,inst,pass), iVar7 != 0 ||
        (((inst2[5] & 0x200U) == 0 &&
         (iVar7 = FUN_000f5a0c(inst2,1,inst2,pass), iVar7 != 0)))))) {
      return 0;
    }
  }
  iVar7 = 4;
  pfVar12 = local_a8;
  pfVar4 = local_b8;
  do {
    *pfVar4 = GH_U2F(0x7fff0000U);
    pfVar4 = pfVar4 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  inst1 = inst;
  inst3 = inst2;
  if (iVar6 == 0) {
    iVar6 = iVar16;
    if (iVar16 == 0) {
      iVar6 = 0;
      pfVar4 = local_b8;
      do {
        operandRecord2 = IRInst__getOperandRecord(inst2,0);
        if (*(char *)(iVar6 + operandRecord2 + 0x10) == '\x01') {
          *pfVar4 = 0.0;
        }
        else {
          operandRecord2 = IRInst__getOperandRecord(inst2,1);
          uVar13 = (uint)*(byte *)(iVar6 + operandRecord2 + 0x10);
          sourceDef = IRInst__getOperandSource(inst2,1);
          if (((int)*(char *)(sourceDef + 0x15c) >> (uVar13 & 0x3f) & 1U) == 0) {
            return 0;
          }
          *pfVar4 = *(float *)(uVar13 * 0x18 + sourceDef + 0x20);
        }
        bVar2 = iVar6 != 3;
        pfVar4 = pfVar4 + 1;
        iVar6 = iVar6 + 1;
      } while (bVar2);
      iVar16 = 0;
      goto LAB_001627ec;
    }
  }
  else {
    inst1 = inst2;
    inst3 = inst;
    if (iVar16 != 0) {
      iVar7 = 0;
      dVar21 = (double)((double (*)())outputScaleFromExponent)(iVar6);
      pfVar4 = local_b8;
      do {
        operandRecord = IRInst__getOperandRecord(inst2,0);
        if (*(char *)(iVar7 + operandRecord + 0x10) == '\x01') {
          *pfVar4 = 0.0;
        }
        else {
          operandRecord = IRInst__getOperandRecord(inst2,1);
          uVar13 = (uint)*(byte *)(iVar7 + operandRecord + 0x10);
          sourceDef2 = IRInst__getOperandSource(inst2,1);
          if (((int)*(char *)(sourceDef2 + 0x15c) >> (uVar13 & 0x3f) & 1U) == 0) {
            return 0;
          }
          *pfVar4 = (float)(dVar21 * (double)*(float *)(uVar13 * 0x18 + sourceDef2 + 0x20));
        }
        bVar2 = iVar7 != 3;
        pfVar4 = pfVar4 + 1;
        iVar7 = iVar7 + 1;
        inst1 = inst;
        inst3 = inst2;
      } while (bVar2);
      goto LAB_001627ec;
    }
  }
  iVar16 = iVar6;
  iVar6 = 0;
  dVar21 = (double)((double (*)())outputScaleFromExponent)(iVar16);
  pfVar4 = local_b8;
  do {
    operandRecord2 = IRInst__getOperandRecord(inst3,0);
    if (*(char *)(iVar6 + operandRecord2 + 0x10) == '\x01') {
      *pfVar4 = 0.0;
    }
    else {
      operandRecord2 = IRInst__getOperandRecord(inst3,1);
      uVar13 = (uint)*(byte *)(iVar6 + operandRecord2 + 0x10);
      sourceDef = IRInst__getOperandSource(inst3,1);
      if (((int)*(char *)(sourceDef + 0x15c) >> (uVar13 & 0x3f) & 1U) == 0) {
        return 0;
      }
      *pfVar4 = (float)(dVar21 * (double)*(float *)(uVar13 * 0x18 + sourceDef + 0x20));
    }
    bVar2 = iVar6 != 3;
    pfVar4 = pfVar4 + 1;
    iVar6 = iVar6 + 1;
  } while (bVar2);
LAB_001627ec:
  local_68 = &local_98;
  iVar6 = 4;
  pfVar4 = pfVar12;
  do {
    *pfVar4 = GH_U2F(0x7fff0000U);
    pfVar4 = pfVar4 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  dVar21 = (double)((double (*)())outputScaleFromExponent)(iVar16);
  iVar6 = 0;
  local_c4 = local_d8;
  iVar7 = 4;
  do {
    if (*(char *)((int)&local_d4 + iVar6) != '\x01') {
      *(char *)((int)&local_c4 + iVar6) = *(char *)((int)&local_d4 + iVar6);
    }
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  iVar6 = 0;
  pfVar4 = pfVar12;
  do {
    operandRecord2 = IRInst__getOperandRecord(inst,0);
    if (*(char *)(iVar6 + operandRecord2 + 0x10) == '\0') {
      *pfVar4 = (float)dVar21;
    }
    else {
      IRInst__getOperandRecord(inst2,0);
      *pfVar4 = 0.0;
    }
    bVar2 = iVar6 != 3;
    pfVar4 = pfVar4 + 1;
    iVar6 = iVar6 + 1;
  } while (bVar2);
  WriteMask__fromSelectWord(&local_78,local_c4);
  SelectWord__maskUnused(&local_74,0x10203,local_78);
  local_c0 = local_74;
  piVar9 = *(int **)(*(int *)(pass + 8) + 0x30c);
  newSource = (**(code **)(*piVar9 + 0x154))(piVar9,pass,pfVar12,&local_c0);
  WriteMask__fromSelectWord(&local_70,local_c4);
  SelectWord__maskUnused(&local_6c,0x10203,local_70);
  local_bc = local_6c;
  piVar9 = *(int **)(*(int *)(pass + 8) + 0x30c);
  newSource2 = (**(code **)(*piVar9 + 0x154))(piVar9,pass,local_b8,&local_bc);
  if ((newSource != 0) && (newSource2 != 0)) {
    if (*(int *)(pass + 0x478) < *(int *)(newSource + 0x160)) {
      *(int *)(newSource + 0x160) = *(int *)(newSource + 0x160) + 1;
    }
    else {
      *(int *)(newSource + 0x160) = *(int *)(pass + 0x478) + 1;
    }
    if (*(int *)(pass + 0x478) < *(int *)(newSource2 + 0x160)) {
      *(int *)(newSource2 + 0x160) = *(int *)(newSource2 + 0x160) + 1;
    }
    else {
      *(int *)(newSource2 + 0x160) = *(int *)(pass + 0x478) + 1;
    }
    *(undefined4 *)(newSource2 + 0x9c) = 0;
    saturate = inst1[0x48];
    useCount = IRInst__useCount(inst,pass);
    sourceDef4 = IRInst__getOperandSource(inst1,1);
    operandRecord3 = IRInst__getOperandRecord(inst1,1);
    local_c8 = *(undefined4 *)(operandRecord3 + 0x10);
    operandRecord3 = IRInst__getOperandRecord(inst1,0);
    firstWrittenComponentResult = SelectWord__firstWrittenComponent(*(undefined4 *)(operandRecord3 + 0x10));
    operandRecord4 = IRInst__getOperandRecord(inst1,1);
    uVar3 = *(undefined1 *)(firstWrittenComponentResult + operandRecord4 + 0x10);
    iVar11 = 4;
    iVar8 = 0;
    do {
      if (*(char *)((int)&local_c4 + iVar8) == '\0') {
        if (*pfVar12 == 0.0) {
          *(undefined1 *)((int)&local_c8 + iVar8) = uVar3;
        }
        else if (*(char *)((int)&local_c8 + iVar8) == '\x04') {
          *(char *)((int)&local_c8 + iVar8) = (char)iVar8;
        }
      }
      else {
        *(undefined1 *)((int)&local_c8 + iVar8) = 4;
      }
      iVar8 = iVar8 + 1;
      pfVar12 = pfVar12 + 1;
      iVar11 = iVar11 + -1;
    } while (iVar11 != 0);
    uVar14 = inst2[5];
    iVar8 = 0;
    source1Flags2 = inst1[0x2e];
    source1Flags3 = inst3[0x2e];
    if ((uVar14 & 0x200) != 0) {
      iVar8 = IRInst__getOperandSource(inst2,inst2[0x21]);
      uVar14 = inst2[5];
    }
    local_84 = 0;
    local_98 = 0;
    local_94 = 0;
    if ((uVar14 & 0x200) != 0) {
      IRInst__readLastOperand(inst2,local_68);
    }
    afterInst = (int *)inst[1];
    uVar14 = inst[5];
    destRegisterOffset = inst[0x26];
    destRegister = inst[0x25];
    iVar11 = inst[3];
    if (inst2 == afterInst) {
      afterInst = (int *)inst2[1];
    }
    DList__unlink(inst);
    IRInst__reinitAsTrinary(inst,0x14,*(undefined4 *)(pass + 8));
    inst[0x25] = destRegister;
    inst[0x26] = destRegisterOffset;
    if ((uVar14 & 2) != 0) {
      inst[5] = inst[5] | 2;
    }
    inst[3] = iVar11;
    inst[0x27] = local_c4;
    inst[0x49] = 0;
    inst[0x48] = saturate;
    IRInst__setOperandSource(inst,1,sourceDef4,0,*(undefined4 *)(pass + 8));
    uVar10 = local_c8;
    operandRecord4 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(operandRecord4 + 0x10) = uVar10;
    IROperand__setModifierBits(inst + 0x29,1,source1Flags2 & 1);
    IROperand__setModifierBits(inst + 0x29,2,source1Flags2 >> 1 & 1);
    IRInst__setOperandSource(inst,2,newSource,0,*(undefined4 *)(pass + 8));
    uVar10 = local_c0;
    operandRecord = IRInst__getOperandRecord(inst,2);
    *(undefined4 *)(operandRecord + 0x10) = uVar10;
    IRInst__setOperandSource(inst,3,newSource2,0,*(undefined4 *)(pass + 8));
    uVar10 = local_bc;
    operandRecord = IRInst__getOperandRecord(inst,3);
    *(undefined4 *)(operandRecord + 0x10) = uVar10;
    IROperand__setModifierBits(inst + 0x35,1,source1Flags3 & 1);
    IROperand__setModifierBits(inst + 0x35,2,source1Flags3 >> 1 & 1);
    inst[0x58] = useCount + *(int *)(pass + 0x478);
    if (iVar8 != 0) {
      IRInst__setLastOperandFromRecord(inst,local_68,0,*(undefined4 *)(pass + 8));
      if (*(int *)(pass + 0x478) < *(int *)(iVar8 + 0x160)) {
        *(int *)(iVar8 + 0x160) = *(int *)(iVar8 + 0x160) + 1;
      }
      else {
        *(int *)(iVar8 + 0x160) = *(int *)(pass + 0x478) + 1;
      }
    }
    Block__insertInstAfter(afterInst[0x56],afterInst,inst);
    IRInst__dropCounterAndDeleteIfUnused(inst2,*(undefined4 *)(pass + 8));
    return 1;
  }
  return 1;
}

/* Inst__collapseIntoExtraSourceDispatch @ 0x162cc0 (316 bytes) */
int Inst__collapseIntoExtraSourceDispatch(inst, program)
  int *inst;
  int program;
{
  int collapseResult;
  undefined4 operandVReg;
  
  collapseResult = (**(code **)(*inst + 100))(inst,program);
  if ((((collapseResult != 0) || (*(int *)(inst[0x22] + 8) == 0x13)) && ((inst[5] & 0x200U) != 0)) &&
     ((*(uint *)(*(int *)(*(int *)(program + 8) + 0x30c) + 8) & 0x100) != 0)) {
    operandVReg = IRInst__getOperandSource(inst,inst[0x21]);
    collapseResult = ((int (*)())FUN_00161748)(inst,operandVReg,program);
    if (((((collapseResult != 0) || (collapseResult = FUN_00151a74(inst,operandVReg,program), collapseResult != 0)) ||
         ((collapseResult = FUN_001524b8(inst,operandVReg,program), collapseResult != 0 ||
          ((collapseResult = FUN_00151370(inst,operandVReg,program), collapseResult != 0 ||
           (collapseResult = FUN_001541f0(inst,operandVReg,program), collapseResult != 0)))))) ||
        (collapseResult = FUN_00152ea8(inst,operandVReg,program), collapseResult != 0)) ||
       (collapseResult = ((int (*)())FUN_001621c8)(inst,operandVReg,program), collapseResult != 0)) {
      return 1;
    }
  }
  return 0;
}

/* FUN_00162dfc @ 0x162dfc (1532 bytes) */
int FUN_00162dfc(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  int param_3;
{
  int inst4;
  int newSource;
  int inst3;
  int operandIndex3;
  int operandIndex2;
  int operandIndex;
  int inst2;
  int inst;
  int *operandVReg;
  bool bVar1;
  int iVar2;
  int *callResult;
  int iVar4;
  int *piVar5;
  uint uVar6;
  undefined4 uVar7;
  int operandIndex4;
  undefined1 *puVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  int local_6c [6];
  undefined4 local_54 [10];
  
  inst = FUN_0011379c(*(undefined4 *)(param_3 + 8),*param_1);
  if ((inst != 0) && (inst = *param_1, (*(uint *)(inst + 0x14) & 0x200) != 0)) {
    callResult = (int *)IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
    if (*(int *)(*(int *)(*param_1 + 0x88) + 8) == *(int *)(callResult[0x22] + 8)) {
      iVar2 = IRInst__getOperandRecord(*param_1,0);
      local_84 = *(undefined4 *)(iVar2 + 0x10);
      iVar4 = IRInst__getOperandRecord(callResult,0);
      iVar2 = 0;
      local_88 = *(undefined4 *)(iVar4 + 0x10);
      iVar4 = 4;
      do {
        if ((*(char *)((int)&local_84 + iVar2) != '\x01') &&
           (*(char *)((int)&local_88 + iVar2) != '\x01')) {
          return 0;
        }
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      inst2 = *param_1;
      if ((*(int *)(inst2 + 0x120) == callResult[0x48]) && (*(int *)(inst2 + 0x124) == callResult[0x49])) {
        if (param_2 == 0) {
          inst2 = FUN_00156cb8(inst2,callResult,param_3);
          if (inst2 == 0) {
            return 0;
          }
          inst2 = *param_1;
        }
        iVar11 = 5;
        iVar4 = 0;
        piVar5 = local_6c;
        do {
          *piVar5 = iVar4;
          piVar5 = piVar5 + 1;
          iVar4 = iVar4 + 1;
          iVar11 = iVar11 + -1;
        } while (iVar11 != 0);
        inst2 = OpcodeTraits__flagBit0(*(undefined4 *)(*(int *)(inst2 + 0x88) + 8),
                             *(undefined4 *)(param_3 + 8));
        if (inst2 != 0) {
          iVar2 = IRInst__getOperandSource(*param_1,1);
          iVar4 = IRInst__getOperandSource(callResult,2);
          if (iVar2 == iVar4) {
            iVar2 = IRInst__getOperandSource(*param_1,2);
            iVar4 = IRInst__getOperandSource(callResult,1);
            if (iVar2 == iVar4) {
              local_6c[1] = 2;
              local_6c[2] = 1;
            }
          }
        }
        for (operandIndex = 1; iVar4 = (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1),
            operandIndex <= iVar4; operandIndex = operandIndex + 1) {
          iVar4 = IRInst__getOperandSource(*param_1,operandIndex);
          operandIndex4 = local_6c[operandIndex];
          iVar11 = IRInst__getOperandSource(callResult,operandIndex4);
          if (iVar4 != iVar11) {
            return 0;
          }
          uVar6 = *(uint *)(operandIndex * 0x18 + *param_1 + 0xa0);
          if ((uVar6 & 1) != (callResult[operandIndex4 * 6 + 0x28] & 1U)) {
            return 0;
          }
          if ((uVar6 >> 1 & 1) != ((uint)callResult[operandIndex4 * 6 + 0x28] >> 1 & 1)) {
            return 0;
          }
          operandVReg = (int *)IRInst__getOperandSource(*param_1,operandIndex);
          iVar4 = (**(code **)(*operandVReg + 0x48))(operandVReg);
          if (iVar4 != 0) {
            iVar4 = IRInst__getOperandRecord(*param_1,operandIndex);
            local_70 = *(undefined4 *)(iVar4 + 0x10);
            iVar4 = IRInst__getOperandRecord(callResult,operandIndex4);
            local_80 = *(undefined4 *)(iVar4 + 0x10);
            piVar5 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
            iVar4 = (**(code **)(*piVar5 + 0x100))(piVar5,&local_70);
            if (iVar4 != 0) {
              piVar5 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
              iVar4 = (**(code **)(*piVar5 + 0x100))(piVar5,&local_80);
              if (iVar4 != 0) {
                iVar4 = 0;
                local_7c = local_70;
                iVar11 = 4;
                do {
                  if (*(char *)(iVar4 + (int)&local_80) == '\x04') {
                    *(undefined1 *)(iVar4 + (int)&local_80) =
                         *(undefined1 *)((int)&local_7c + iVar4);
                  }
                  iVar4 = iVar4 + 1;
                  iVar11 = iVar11 + -1;
                } while (iVar11 != 0);
                piVar5 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
                iVar4 = (**(code **)(*piVar5 + 0x100))(piVar5,&local_80);
                if (iVar4 == 0) {
                  return 0;
                }
              }
            }
          }
        }
        iVar2 = IRInst__getOperandRecord(*param_1,0);
        puVar10 = local_54;
        local_78 = *(undefined4 *)(iVar2 + 0x10);
        for (operandIndex2 = 1; iVar4 = (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1),
            operandIndex2 <= iVar4; operandIndex2 = operandIndex2 + 1) {
          iVar4 = IRInst__getOperandRecord(*param_1,operandIndex2);
          *puVar10 = *(undefined4 *)(iVar4 + 0x10);
          puVar10 = puVar10 + 1;
        }
        iVar2 = 0;
        do {
          iVar4 = IRInst__getOperandRecord(callResult,0);
          if (*(char *)(iVar2 + iVar4 + 0x10) != '\x01') {
            iVar4 = IRInst__getOperandRecord(callResult,0);
            iVar11 = 1;
            piVar5 = local_6c;
            *(undefined1 *)((int)&local_78 + iVar2) = *(undefined1 *)(iVar2 + iVar4 + 0x10);
            puVar9 = (undefined1 *)((int)local_54 + iVar2);
            while( true ) {
              piVar5 = piVar5 + 1;
              iVar4 = (**(code **)(*callResult + 0x14))(callResult);
              if (iVar4 < iVar11) break;
              iVar11 = iVar11 + 1;
              iVar4 = IRInst__getOperandRecord(callResult,*piVar5);
              *puVar9 = *(undefined1 *)(iVar2 + iVar4 + 0x10);
              puVar9 = puVar9 + 4;
            }
          }
          bVar1 = iVar2 != 3;
          iVar2 = iVar2 + 1;
        } while (bVar1);
        iVar4 = 0;
        iVar2 = IRInst__getOperandRecord(*param_1,*(undefined4 *)(*param_1 + 0x84));
        local_74 = *(undefined4 *)(iVar2 + 0x10);
        do {
          iVar2 = IRInst__getOperandRecord(callResult,0);
          if (*(char *)(iVar4 + iVar2 + 0x10) != '\x01') {
            *(undefined1 *)((int)&local_74 + iVar4) = 4;
          }
          bVar1 = iVar4 != 3;
          iVar4 = iVar4 + 1;
        } while (bVar1);
        iVar2 = 1;
        puVar10 = local_54;
        while( true ) {
          iVar4 = (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1);
          if (iVar4 < iVar2) {
            puVar10 = local_54;
            *(undefined4 *)(*param_1 + 0x9c) = local_78;
            for (operandIndex3 = 1; iVar4 = (**(code **)(*(int *)*param_1 + 0x14))((int *)*param_1),
                operandIndex3 <= iVar4; operandIndex3 = operandIndex3 + 1) {
              uVar7 = *puVar10;
              iVar4 = IRInst__getOperandRecord(*param_1,operandIndex3);
              puVar10 = puVar10 + 1;
              *(undefined4 *)(iVar4 + 0x10) = uVar7;
            }
            if ((callResult[5] & 0x200U) == 0) {
              inst3 = *param_1;
              IRInst__setOperandSource(inst3,*(undefined4 *)(inst3 + 0x84),0,0,*(undefined4 *)(param_3 + 8));
              *(int *)(inst3 + 0x84) = *(int *)(inst3 + 0x84) + -1;
              *(uint *)(inst3 + 0x14) = *(uint *)(inst3 + 0x14) & 0xfffffdff;
              return 1;
            }
            newSource = IRInst__getOperandSource(callResult,callResult[0x21]);
            IRInst__setExtraOperandSource(*param_1,newSource,0,*(undefined4 *)(param_3 + 8));
            uVar7 = local_74;
            inst4 = *param_1;
            if (*(int *)(inst4 + 0x84) == 0) {
              *(undefined4 *)(inst4 + 0x9c) = local_74;
            }
            else {
              inst4 = IRInst__getOperandRecord(inst4,*(int *)(inst4 + 0x84));
              *(undefined4 *)(inst4 + 0x10) = uVar7;
            }
            if (*(int *)(newSource + 0x160) <= *(int *)(param_3 + 0x478)) {
              *(int *)(newSource + 0x160) = *(int *)(param_3 + 0x478) + 1;
              return 1;
            }
            *(int *)(newSource + 0x160) = *(int *)(newSource + 0x160) + 1;
            return 1;
          }
          piVar5 = *(int **)(*(int *)(param_3 + 8) + 0x30c);
          iVar4 = (**(code **)(*piVar5 + 0x100))(piVar5,puVar10);
          if (iVar4 == 0) break;
          iVar2 = iVar2 + 1;
          puVar10 = puVar10 + 1;
        }
      }
    }
  }
  return 0;
}

/* Inst__tryCollapseSimilar @ 0x1633f8 (128 bytes) */
int Inst__tryCollapseSimilar(inst, param_2, param_3, param_4, param_5, param_6, param_7)
  int inst;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  unsigned int ghidra_home[8] = { inst, param_2, param_3, param_4, param_5, param_6, param_7, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  int callResult;
  undefined4 inst1;
  
  inst1 = 0;
  (*(int *)((unsigned char *)ghidra_home + 0)) = inst;
  if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
    inst1 = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
  }
  callResult = ((int (*)())FUN_00162dfc)(&(*(unsigned int *)((unsigned char *)ghidra_home + 0)),0,param_2);
  if (callResult != 0) {
    *(int *)(param_2 + 0x1fc) = *(int *)(param_2 + 0x1fc) + 1;
    IRInst__dropCounterAndDeleteIfUnused(inst1,*(undefined4 *)(param_2 + 8));
  }
  return callResult != 0;
}

/* Inst__hoistScalarMulOutOfDot @ 0x163478 (1308 bytes) */
int Inst__hoistScalarMulOutOfDot(consumer, consumerSrcIndex, inst, program)
  undefined4 consumer;
  undefined4 consumerSrcIndex;
  int *inst;
  int program;
{
  undefined4 scalarOperandIndex;
  undefined4 vectorOperandIndex;
  int lanesLeft2;
  int newDot;
  int scalarDef;
  int isSplatResult;
  int mulSelectRecord;
  int savedSaturate;
  int savedResultScale;
  int mulOperandRecord;
  int laneIndex2;
  int newDotRecord;
  int laneIndex;
  int mulInst;
  int srcCountBound;
  bool moreLanes;
  int laneScan;
  int operandRecord;
  int singleUse;
  int vectorDef;
  int *newMul;
  undefined1 scalarSelectByte;
  undefined4 src2SelectWord;
  undefined4 src1SelectWord;
  undefined4 compiler;
  int dotOpcode;
  undefined4 result;
  int nextNode;
  int lanesLeft;
  int destSelectWord;
  undefined4 scalarSelect;
  undefined4 mulVectorSelect;
  undefined4 dotOperandSelect;
  undefined4 savedCounters0;
  undefined4 savedCounters1;
  undefined4 savedCounters2;
  undefined4 lastOperandRecord;
  int lastOperandSource;
  undefined4 lastOperandRecord5;
  
  compiler = *(undefined4 *)(program + 8);
  dotOpcode = *(int *)(inst[0x22] + 8);
  operandRecord = IRInst__getOperandRecord(inst,0);
  destSelectWord = *(int *)(operandRecord + 0x10);
  if ((dotOpcode - 0x1cU < 2) && (operandRecord = SelectWord__isSingleComponentConstant(destSelectWord), operandRecord != 0)) {
    result = 0;
    for (operandRecord = 1; srcCountBound = (**(code **)(*inst + 0x14))(inst), operandRecord <= srcCountBound;
        operandRecord = operandRecord + 1) {
      mulInst = IRInst__getOperandSource(inst,operandRecord);
      if ((((*(int *)(*(int *)(mulInst + 0x88) + 8) == 0x13) &&
           (singleUse = IRInst__hasSingleUse(mulInst,program), singleUse != 0)) && (*(int *)(mulInst + 0x124) == 0))
         && ((*(int *)(mulInst + 0x120) == 0 && ((*(uint *)(mulInst + 0x14) & 0x200) == 0)))) {
        mulSelectRecord = IRInst__getOperandRecord(mulInst,1);
        src1SelectWord = *(undefined4 *)(mulSelectRecord + 0x10);
        mulSelectRecord = IRInst__getOperandRecord(mulInst,2);
        src2SelectWord = *(undefined4 *)(mulSelectRecord + 0x10);
        isSplatResult = SelectWord__isSplat(src1SelectWord);
        if ((isSplatResult == 0) || (isSplatResult = SelectWord__isSplat(src2SelectWord), isSplatResult == 0)) {
          isSplatResult = SelectWord__isSplat(src1SelectWord);
          if (isSplatResult == 0) {
            isSplatResult = SelectWord__isSplat(src2SelectWord);
            if (isSplatResult == 0) goto LAB_00163950;
            scalarDef = IRInst__getOperandSource(mulInst,2);
            vectorDef = IRInst__getOperandSource(mulInst,1);
            scalarOperandIndex = 2;
            scalarSelect = src2SelectWord;
            vectorOperandIndex = 1;
          }
          else {
            scalarDef = IRInst__getOperandSource(mulInst,1);
            scalarSelect = src1SelectWord;
            vectorDef = IRInst__getOperandSource(mulInst,2);
            scalarOperandIndex = 1;
            vectorOperandIndex = 2;
          }
          laneScan = 0;
          lanesLeft = 4;
          do {
            if (*(char *)((int)&scalarSelect + laneScan) != '\x04') {
              scalarSelectByte = *(undefined1 *)((int)&scalarSelect + laneScan);
              goto LAB_00163628;
            }
            laneScan = laneScan + 1;
            lanesLeft = lanesLeft + -1;
          } while (lanesLeft != 0);
          scalarSelectByte = 0;
LAB_00163628:
          mulOperandRecord = IRInst__getOperandRecord(mulInst,vectorOperandIndex);
          mulVectorSelect = *(undefined4 *)(mulOperandRecord + 0x10);
          mulOperandRecord = IRInst__getOperandRecord(inst,operandRecord);
          dotOperandSelect = *(undefined4 *)(mulOperandRecord + 0x10);
          *(int *)(program + 0x284) = *(int *)(program + 0x284) + 1;
          if (*(int *)(program + 0x478) < *(int *)(vectorDef + 0x160)) {
            *(int *)(vectorDef + 0x160) = *(int *)(vectorDef + 0x160) + 1;
          }
          else {
            *(int *)(vectorDef + 0x160) = *(int *)(program + 0x478) + 1;
          }
          if (*(int *)(program + 0x478) < *(int *)(scalarDef + 0x160)) {
            *(int *)(scalarDef + 0x160) = *(int *)(scalarDef + 0x160) + 1;
          }
          else {
            *(int *)(scalarDef + 0x160) = *(int *)(program + 0x478) + 1;
          }
          lastOperandRecord = 0;
          lastOperandSource = 0;
          lastOperandRecord5 = 0;
          if ((inst[5] & 0x200U) != 0) {
            IRInst__readLastOperand(inst,&lastOperandRecord);
            IRInst__setOperandSource(inst,inst[0x21],0,0,compiler);
            inst[0x21] = inst[0x21] + -1;
            inst[5] = inst[5] & 0xfffffdff;
          }
          savedCounters0 = 0;
          savedCounters1 = 0;
          savedCounters2 = 0;
          IRInst__saveCounters(inst,&savedCounters0,0xffffffff);
          savedResultScale = inst[0x49];
          savedSaturate = inst[0x48];
          inst[0x49] = 0;
          inst[0x48] = 0;
          nextNode = inst[2];
          DList__unlink(inst);
          newDot = IRInst__clone(inst,compiler,0);
          *(undefined4 *)(newDot + 0x98) = 0;
          *(undefined4 *)(newDot + 0x94) = *(undefined4 *)(newDot + 0x14c);
          newMul = (int *)IRInst__cloneInto(mulInst,inst,compiler,0);
          newMul[0x26] = 0;
          newMul[0x25] = newMul[0x53];
          IRInst__setOperandSource(newMul,vectorOperandIndex,newDot,0,compiler);
          IRInst__dropCounterAndDeleteIfUnused(mulInst,compiler);
          Block__insertInstBefore(*(undefined4 *)(nextNode + 0x158),nextNode,newDot);
          Block__insertInstAfter(*(undefined4 *)(newDot + 0x158),newDot,newMul);
          if ((operandRecord == 1) && (nextNode = IRInst__getOperandSource(newDot,2), mulInst == nextNode)) {
            IRInst__setOperandSource(newDot,2,vectorDef,0,compiler);
          }
          IRInst__setOperandSource(newDot,operandRecord,vectorDef,0,compiler);
          lanesLeft2 = 4;
          laneIndex = 0;
          do {
            if (*(byte *)((int)&dotOperandSelect + laneIndex) != 4) {
              *(undefined1 *)((int)&dotOperandSelect + laneIndex) =
                   *(undefined1 *)((int)&mulVectorSelect + (uint)*(byte *)((int)&dotOperandSelect + laneIndex));
            }
            src1SelectWord = dotOperandSelect;
            laneIndex = laneIndex + 1;
            lanesLeft2 = lanesLeft2 + -1;
          } while (lanesLeft2 != 0);
          if (operandRecord == 0) {
            *(undefined4 *)(newDot + 0x9c) = dotOperandSelect;
          }
          else {
            newDotRecord = IRInst__getOperandRecord(newDot,operandRecord);
            *(undefined4 *)(newDotRecord + 0x10) = src1SelectWord;
          }
          *(int *)(newDot + 0x160) = *(int *)(program + 0x478) + 1;
          if (lastOperandSource != 0) {
            IRInst__setLastOperandFromRecord(newMul,&lastOperandRecord,0,compiler);
          }
          IRInst__restoreCounters(newMul,&savedCounters0);
          newMul[0x48] = savedSaturate;
          newMul[0x49] = savedResultScale;
          laneIndex2 = 0;
          newMul[0x27] = destSelectWord;
          do {
            if (*(char *)((int)&destSelectWord + laneIndex2) == '\x01') {
              (**(code **)(*newMul + 0x88))(newMul,1,laneIndex2,4);
              (**(code **)(*newMul + 0x88))(newMul,2,laneIndex2,4);
            }
            else {
              (**(code **)(*newMul + 0x88))(newMul,scalarOperandIndex,laneIndex2,scalarSelectByte);
              (**(code **)(*newMul + 0x88))(newMul,vectorOperandIndex,laneIndex2,laneIndex2);
            }
            moreLanes = laneIndex2 != 3;
            laneIndex2 = laneIndex2 + 1;
          } while (moreLanes);
          result = 1;
        }
      }
LAB_00163950: ;
    }
  }
  else {
    result = 0;
  }
  return result;
}

/* Inst__mergeMovAndMadByLanes @ 0x163994 (3864 bytes) */
int Inst__mergeMovAndMadByLanes(node, pass)
  int node;
  int pass;
{
  int laneE;
  int laneD;
  int newSrcIndexB;
  int selectLaneB;
  int srcCountB;
  int laneC;
  int isMixB;
  int laneB;
  int newSrcIndexA;
  int selectLaneA;
  int srcCountA;
  int laneA;
  int isMixA;
  int *mergedInst;
  uint useIndex;
  uint useCount;
  uint trackUseLists;
  int lanesLeft3;
  int madSrc1Resolved;
  int lanesLeft2;
  int laneScan5;
  int laneScan4;
  int laneScan3;
  int movSrcResolved;
  int isMixResult2;
  int laneScan2;
  int laneScan;
  int isMixResult;
  int srcIndexB;
  int selectedLane;
  int srcIndexA;
  int allocatedRegister;
  int prevNode;
  int movInst;
  bool foundConstant;
  int uniformSourceConstant;
  int hasSingleUse;
  int firstUnwrittenComponentResult;
  int splitRgbAlphaEnabled;
  int sourceDef;
  int operandRecord2;
  int sourceDef2;
  int operandRecord4;
  int sourceDef3;
  int operandRecord;
  int operandRecord3;
  bool moreLanes;
  bool moreLanes2;
  int movDepthAboveBase;
  int madInst;
  int *operandVReg;
  int madSrc2Resolved;
  int madSrc3Resolved;
  int *madSrcA;
  int *madSrcB;
  uint madSrc2Negate;
  int *vectorSlot;
  uint movAbs;
  undefined4 matchedSrcIndex;
  undefined4 otherIndexA;
  undefined4 otherIndexB;
  undefined4 compilerArg;
  uint madSrc1Negate;
  uint movNegate;
  int nodeOpcode;
  uint *useVector;
  int extraOpcode;
  int lanesLeft;
  double fparam_1;
  undefined4 extraSourceSelect;
  undefined4 movDestSelect;
  undefined4 madDestSelect;
  undefined4 madOtherSelectB;
  int mergedDestSelect;
  undefined4 movSrc1Select;
  undefined4 madOtherSelectA;
  undefined4 lastOperandRecord;
  int lastOperandSource;
  undefined4 lastOperandRecord5;
  undefined4 local_84;
  float local_80;
  
  if ((*(uint *)(node + 0x14) & 0x200) == 0) {
    return 0;
  }
  sourceDef2 = IRInst__getOperandSource(node,*(undefined4 *)(node + 0x84));
  if (sourceDef2 == 0) {
    return 0;
  }
  if ((*(uint *)(*(int *)(*(int *)(pass + 8) + 0x30c) + 8) & 0x100) == 0) {
    return 0;
  }
  nodeOpcode = *(int *)(*(int *)(node + 0x88) + 8);
  extraOpcode = *(int *)(*(int *)(sourceDef2 + 0x88) + 8);
  operandRecord2 = IRInst__getOperandRecord(node,*(undefined4 *)(node + 0x84));
  extraSourceSelect = *(undefined4 *)(operandRecord2 + 0x10);
  if (nodeOpcode == 0x31) {
    if (extraOpcode != 0x14) {
      return 0;
    }
    operandRecord2 = IRInst__getOperandRecord(node,0);
    laneScan = 0;
    local_84 = *(undefined4 *)(operandRecord2 + 0x10);
    lanesLeft = 4;
    do {
      if (*(char *)((int)&extraSourceSelect + laneScan) == '\x04') {
        if (*(char *)((int)&local_84 + laneScan) == '\0') {
          *(char *)((int)&extraSourceSelect + laneScan) = (char)laneScan;
        }
      }
      else {
        *(undefined1 *)((int)&extraSourceSelect + laneScan) = 4;
      }
      laneScan = laneScan + 1;
      lanesLeft = lanesLeft + -1;
      madInst = sourceDef2;
      movInst = node;
    } while (lanesLeft != 0);
  }
  else {
    if (nodeOpcode != 0x14) {
      return 0;
    }
    madInst = node;
    movInst = sourceDef2;
    if (extraOpcode != 0x31) {
      return 0;
    }
  }
  if (*(int *)(movInst + 0x120) != *(int *)(madInst + 0x120)) {
    return 0;
  }
  if (*(int *)(movInst + 0x124) != *(int *)(madInst + 0x124)) {
    return 0;
  }
  operandRecord = IRInst__getOperandRecord(movInst,0);
  movDestSelect = *(int *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(madInst,0);
  madDestSelect = *(undefined4 *)(operandRecord + 0x10);
  splitRgbAlphaEnabled = Compiler__isOptionEnabled(*(undefined4 *)(pass + 8),0x30);
  if (splitRgbAlphaEnabled != 0) {
    if ((char)movDestSelect == '\0') {
      return 0;
    }
    if ((char)madDestSelect == '\0') {
      return 0;
    }
  }
  laneScan2 = 0;
  lanesLeft2 = 4;
  do {
    if ((*(char *)((int)&movDestSelect + laneScan2) != '\x01') &&
       (*(char *)((int)&madDestSelect + laneScan2) != '\x01')) {
      return 0;
    }
    laneScan2 = laneScan2 + 1;
    lanesLeft2 = lanesLeft2 + -1;
  } while (lanesLeft2 != 0);
  operandVReg = (int *)IRInst__getOperandSource(movInst,1);
  isMixResult2 = (**(code **)(*operandVReg + 0x60))(operandVReg);
  if (isMixResult2 != 0) {
    return 0;
  }
  movSrcResolved = IRInst__getOperandSourceThroughMix(movInst,1);
  madSrc1Resolved = IRInst__getOperandSourceThroughMix(madInst,1);
  madSrc2Resolved = IRInst__getOperandSourceThroughMix(madInst,2);
  madSrc3Resolved = IRInst__getOperandSourceThroughMix(madInst,3);
  madSrc1Negate = *(uint *)(madInst + 0xb8) & 1;
  madSrc2Negate = *(uint *)(madInst + 0xd0) & 1;
  movNegate = *(uint *)(movInst + 0xb8) & 1;
  movAbs = *(uint *)(movInst + 0xb8) >> 1 & 1;
  if ((movSrcResolved == madSrc1Resolved) && ((*(uint *)(madInst + 0xb8) >> 1 & 1) == movAbs)) {
    if (movNegate == 0) {
      if (madSrc1Negate != madSrc2Negate) goto LAB_00163c00;
    }
    else if (madSrc1Negate == madSrc2Negate) goto LAB_00163c00;
    matchedSrcIndex = 1;
    fparam_1 = 1.0;
    otherIndexA = 2;
    otherIndexB = 3;
  }
  else {
LAB_00163c00:
    if ((movSrcResolved == madSrc2Resolved) && ((*(uint *)(madInst + 0xd0) >> 1 & 1) == movAbs)) {
      if (movNegate == 0) {
        if (madSrc1Negate != madSrc2Negate) goto LAB_00163c2c;
      }
      else if (madSrc1Negate == madSrc2Negate) goto LAB_00163c2c;
      matchedSrcIndex = 2;
      fparam_1 = 1.0;
      otherIndexA = 1;
      otherIndexB = 3;
    }
    else {
LAB_00163c2c:
      if (movSrcResolved != madSrc3Resolved) {
        return 0;
      }
      if ((*(uint *)(madInst + 0xe8) >> 1 & 1) != movAbs) {
        return 0;
      }
      if ((*(uint *)(madInst + 0xe8) & 1) != movNegate) {
        return 0;
      }
      matchedSrcIndex = 3;
      fparam_1 = 0.0;
      otherIndexA = 1;
      otherIndexB = 2;
    }
  }
  lastOperandRecord5 = 0;
  lastOperandRecord = 0;
  lastOperandSource = 0;
  if ((*(uint *)(sourceDef2 + 0x14) & 0x200) != 0) {
    IRInst__readLastOperand(sourceDef2,&lastOperandRecord);
  }
  movDepthAboveBase = *(int *)(movInst + 0x160) - *(int *)(pass + 0x478);
  if (movDepthAboveBase < 0) {
    movDepthAboveBase = 0;
  }
  operandRecord = IRInst__getOperandRecord(movInst,1);
  movSrc1Select = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(madInst,otherIndexA);
  madOtherSelectA = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(madInst,otherIndexB);
  madOtherSelectB = *(undefined4 *)(operandRecord + 0x10);
  lanesLeft3 = 4;
  mergedDestSelect = movDestSelect;
  laneScan3 = 0;
  do {
    if (*(char *)((int)&madDestSelect + laneScan3) != '\x01') {
      *(char *)((int)&mergedDestSelect + laneScan3) = *(char *)((int)&madDestSelect + laneScan3);
    }
    laneScan3 = laneScan3 + 1;
    lanesLeft3 = lanesLeft3 + -1;
  } while (lanesLeft3 != 0);
  IRInst__dropCounterAndDeleteIfUnused(movInst,*(undefined4 *)(pass + 8));
  operandVReg = (int *)IRInst__getOperandSource(madInst,matchedSrcIndex);
  madSrcA = (int *)IRInst__getOperandSource(madInst,otherIndexA);
  madSrcB = (int *)IRInst__getOperandSource(madInst,otherIndexB);
  prevNode = *(int *)(node + 4);
  DList__unlink(node);
  if ((*(uint *)(madInst + 0x14) & 0x200) != 0) {
    compilerArg = *(undefined4 *)(pass + 8);
    trackUseLists = *(uint *)(pass + 0x30) >> 7 & 1;
    if (trackUseLists != 0) {
      sourceDef3 = IRInst__getOperandSource(madInst,*(undefined4 *)(madInst + 0x84));
      useVector = *(uint **)(sourceDef3 + 0x10);
      useCount = useVector[1];
      if (0 < (int)useCount) {
        useIndex = 0;
        do {
          if (useIndex < *useVector) {
            if (useCount <= useIndex) {
              _memset(useCount * 4 + useVector[2],0,(useIndex - useCount) * 4 + 4);
              useVector[1] = useIndex + 1;
            }
            vectorSlot = (int *)(useIndex * 4 + useVector[2]);
          }
          else {
            vectorSlot = (int *)Vector__elementRefGrow(useVector,useIndex);
          }
          if (madInst == *vectorSlot) {
            Vector__removeAt(useVector,useIndex);
            sourceDef3 = IRInst__getOperandSource(madInst,*(undefined4 *)(madInst + 0x84));
            *(int *)(sourceDef3 + 0x160) = *(int *)(sourceDef3 + 0x160) + -1;
            break;
          }
          useCount = useVector[1];
          useIndex = useIndex + 1;
        } while ((int)useIndex < (int)useCount);
      }
    }
    IRInst__setOperandSource(madInst,*(undefined4 *)(madInst + 0x84),0,trackUseLists,compilerArg);
    *(int *)(madInst + 0x84) = *(int *)(madInst + 0x84) + -1;
    *(uint *)(madInst + 0x14) = *(uint *)(madInst + 0x14) & 0xfffffdff;
  }
  mergedInst = (int *)IRInst__cloneInto(madInst,node,*(undefined4 *)(pass + 8),0);
  Block__insertInstAfter(*(undefined4 *)(prevNode + 0x158),prevNode,mergedInst);
  allocatedRegister = mergedInst[0x53];
  mergedInst[0x27] = mergedDestSelect;
  operandRecord2 = IRInst__getOperandRecord(mergedInst,0);
  *(int *)(operandRecord2 + 8) = allocatedRegister;
  isMixA = (**(code **)(*madSrcA + 0x60))(madSrcA);
  if (isMixA == 0) {
    madSrcA = (int *)IRLoadConst__vslot73(0xa2,*(undefined4 *)(pass + 8));
    Block__insertInstBefore(mergedInst[0x56],mergedInst,madSrcA);
    madSrcA[0x21] = 1;
    madSrcA[0x25] = madSrcA[0x53];
    madSrcA[0x26] = 0x36;
    madSrcA[0x27] = mergedDestSelect;
    sourceDef = IRInst__getOperandSource(mergedInst,otherIndexA);
    IRInst__setOperandSource(madSrcA,1,sourceDef,0,*(undefined4 *)(pass + 8));
    if (*(int *)(pass + 0x478) < *(int *)(sourceDef + 0x160)) {
      *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
    }
    else {
      *(int *)(sourceDef + 0x160) = *(int *)(pass + 0x478) + 1;
    }
    madSrcA[0x21] = 2;
    laneA = 0;
    ((void (*)())IRInst__makeLiteralVec4Float)(madSrcA,pass,2,fparam_1,fparam_1,fparam_1,fparam_1);
    do {
      if (*(char *)((int)&madDestSelect + laneA) != '\x01') {
        (**(code **)(*madSrcA + 0x88))(madSrcA,1,laneA,*(undefined1 *)((int)&madOtherSelectA + laneA));
        (**(code **)(*madSrcA + 0x88))(madSrcA,2,laneA,4);
        (**(code **)(*mergedInst + 0x88))(mergedInst,otherIndexA,laneA,laneA);
      }
      moreLanes = laneA != 3;
      laneA = laneA + 1;
    } while (moreLanes);
    laneA = 0;
    do {
      if (*(char *)((int)&movDestSelect + laneA) != '\x01') {
        (**(code **)(*madSrcA + 0x88))(madSrcA,1,laneA,4);
        (**(code **)(*madSrcA + 0x88))(madSrcA,2,laneA,laneA);
        (**(code **)(*mergedInst + 0x88))(mergedInst,otherIndexA,laneA,laneA);
      }
      moreLanes = laneA != 3;
      laneA = laneA + 1;
    } while (moreLanes);
    IRInst__setOperandSource(mergedInst,otherIndexA,madSrcA,0,*(undefined4 *)(pass + 8));
    madSrcA[0x58] = *(int *)(pass + 0x478) + 1;
  }
  else {
    hasSingleUse = IRInst__hasSingleUse(madSrcA,pass);
    if (hasSingleUse == 0) {
      madSrcA[0x58] = madSrcA[0x58] + -1;
      madSrcA = (int *)IRInst__clone(madSrcA,*(undefined4 *)(pass + 8),0);
      Block__insertInstBefore(*(undefined4 *)(node + 0x158),node,madSrcA);
      madSrcA[0x58] = *(int *)(pass + 0x478) + 1;
    }
    srcCountA = madSrcA[0x21];
    if (1 < srcCountA) {
      foundConstant = false;
      srcIndexA = 2;
      do {
        operandRecord2 = IRInst__getOperandRecord(madSrcA,0);
        uniformSourceConstant = IRInst__getUniformSourceConstant(madSrcA,srcIndexA,*(undefined4 *)(operandRecord2 + 0x10),&local_84);
        if ((uniformSourceConstant != 0) && (fparam_1 == (double)local_80)) {
          selectLaneA = -1;
          laneScan4 = 0;
          do {
            operandRecord4 = IRInst__getOperandRecord(madSrcA,srcIndexA);
            if (*(char *)(laneScan4 + operandRecord4 + 0x10) != '\x04') {
              selectLaneA = laneScan4;
            }
            moreLanes2 = laneScan4 != 3;
            laneScan4 = laneScan4 + 1;
          } while (moreLanes2);
          laneScan4 = 0;
          do {
            if (*(char *)((int)&extraSourceSelect + laneScan4) != '\x04') {
              foundConstant = true;
              (**(code **)(*mergedInst + 0x88))(mergedInst,otherIndexA,laneScan4,selectLaneA);
            }
            moreLanes2 = laneScan4 != 3;
            laneScan4 = laneScan4 + 1;
          } while (moreLanes2);
          if (foundConstant) goto LAB_00164300;
        }
        srcCountA = madSrcA[0x21];
        srcIndexA = srcIndexA + 1;
      } while (srcIndexA <= srcCountA);
      if (foundConstant) goto LAB_00164300;
    }
    newSrcIndexA = srcCountA + 1;
    madSrcA[0x21] = newSrcIndexA;
    ((void (*)())IRInst__makeLiteralVec4Float)(madSrcA,pass,newSrcIndexA,fparam_1,fparam_1,fparam_1,fparam_1);
    operandRecord3 = IRInst__getOperandRecord(madSrcA,newSrcIndexA);
    *(undefined4 *)(operandRecord3 + 0x10) = 0x4040404;
    selectedLane = 0;
    do {
      operandRecord = IRInst__getOperandRecord(madSrcA,0);
      if (*(char *)(selectedLane + operandRecord + 0x10) != '\0') {
        (**(code **)(*madSrcA + 0x88))(madSrcA,newSrcIndexA,selectedLane,selectedLane);
        *(undefined1 *)((int)madSrcA + selectedLane + 0x9c) = 0;
        goto LAB_001642bc;
      }
      moreLanes = selectedLane != 3;
      selectedLane = selectedLane + 1;
    } while (moreLanes);
    selectedLane = -1;
LAB_001642bc:
    laneB = 0;
    do {
      if (*(char *)((int)&extraSourceSelect + laneB) != '\x04') {
        (**(code **)(*mergedInst + 0x88))(mergedInst,otherIndexA,laneB,selectedLane);
      }
      moreLanes = laneB != 3;
      laneB = laneB + 1;
    } while (moreLanes);
  }
LAB_00164300:
  isMixB = (**(code **)(*madSrcB + 0x60))(madSrcB);
  if (isMixB == 0) {
    madSrcA = (int *)IRLoadConst__vslot73(0xa2,*(undefined4 *)(pass + 8));
    Block__insertInstBefore(mergedInst[0x56],mergedInst,madSrcA);
    madSrcA[0x21] = 1;
    madSrcA[0x25] = madSrcA[0x53];
    madSrcA[0x26] = 0x36;
    madSrcA[0x27] = mergedDestSelect;
    sourceDef = IRInst__getOperandSource(mergedInst,otherIndexB);
    IRInst__setOperandSource(madSrcA,1,sourceDef,0,*(undefined4 *)(pass + 8));
    if (*(int *)(pass + 0x478) < *(int *)(sourceDef + 0x160)) {
      *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + 1;
    }
    else {
      *(int *)(sourceDef + 0x160) = *(int *)(pass + 0x478) + 1;
    }
    madSrcA[0x21] = 2;
    laneC = 0;
    ((void (*)())IRInst__makeLiteralVec4Float)(madSrcA,pass,2,0.0,0.0,0.0,0.0);
    do {
      if (*(char *)((int)&madDestSelect + laneC) != '\x01') {
        (**(code **)(*madSrcA + 0x88))(madSrcA,1,laneC,*(undefined1 *)((int)&madOtherSelectB + laneC));
        (**(code **)(*madSrcA + 0x88))(madSrcA,2,laneC,4);
        (**(code **)(*mergedInst + 0x88))(mergedInst,otherIndexB,laneC,laneC);
      }
      moreLanes = laneC != 3;
      laneC = laneC + 1;
    } while (moreLanes);
    laneC = 0;
    do {
      if (*(char *)((int)&movDestSelect + laneC) != '\x01') {
        (**(code **)(*madSrcA + 0x88))(madSrcA,1,laneC,4);
        (**(code **)(*madSrcA + 0x88))(madSrcA,2,laneC,laneC);
        (**(code **)(*mergedInst + 0x88))(mergedInst,otherIndexB,laneC,laneC);
      }
      moreLanes = laneC != 3;
      laneC = laneC + 1;
    } while (moreLanes);
    IRInst__setOperandSource(mergedInst,otherIndexB,madSrcA,0,*(undefined4 *)(pass + 8));
    madSrcA[0x58] = *(int *)(pass + 0x478) + 1;
  }
  else {
    hasSingleUse = IRInst__hasSingleUse(madSrcB,pass);
    if (hasSingleUse == 0) {
      madSrcB[0x58] = madSrcB[0x58] + -1;
      madSrcB = (int *)IRInst__clone(madSrcB,*(undefined4 *)(pass + 8),0);
      Block__insertInstBefore(*(undefined4 *)(node + 0x158),node,madSrcB);
      madSrcB[0x58] = *(int *)(pass + 0x478) + 1;
    }
    srcCountB = madSrcB[0x21];
    if (1 < srcCountB) {
      foundConstant = false;
      srcIndexB = 2;
      do {
        operandRecord2 = IRInst__getOperandRecord(madSrcB,0);
        uniformSourceConstant = IRInst__getUniformSourceConstant(madSrcB,srcIndexB,*(undefined4 *)(operandRecord2 + 0x10),&local_84);
        if ((uniformSourceConstant != 0) && (local_80 == 0.0)) {
          selectLaneB = -1;
          laneScan5 = 0;
          do {
            operandRecord4 = IRInst__getOperandRecord(madSrcB,srcIndexB);
            if (*(char *)(laneScan5 + operandRecord4 + 0x10) != '\x04') {
              selectLaneB = laneScan5;
            }
            moreLanes2 = laneScan5 != 3;
            laneScan5 = laneScan5 + 1;
          } while (moreLanes2);
          laneScan5 = 0;
          do {
            if (*(char *)((int)&extraSourceSelect + laneScan5) != '\x04') {
              foundConstant = true;
              (**(code **)(*mergedInst + 0x88))(mergedInst,otherIndexB,laneScan5,selectLaneB);
            }
            moreLanes2 = laneScan5 != 3;
            laneScan5 = laneScan5 + 1;
          } while (moreLanes2);
          if (foundConstant) goto LAB_00164744;
        }
        srcCountB = madSrcB[0x21];
        srcIndexB = srcIndexB + 1;
      } while (srcIndexB <= srcCountB);
      if (foundConstant) goto LAB_00164744;
    }
    newSrcIndexB = srcCountB + 1;
    madSrcB[0x21] = newSrcIndexB;
    ((void (*)())IRInst__makeLiteralVec4Float)(madSrcB,pass,newSrcIndexB,0.0,0.0,0.0,0.0);
    operandRecord3 = IRInst__getOperandRecord(madSrcB,newSrcIndexB);
    *(undefined4 *)(operandRecord3 + 0x10) = 0x4040404;
    selectedLane = 0;
    do {
      operandRecord = IRInst__getOperandRecord(madSrcB,0);
      if (*(char *)(selectedLane + operandRecord + 0x10) != '\0') {
        (**(code **)(*madSrcB + 0x88))(madSrcB,newSrcIndexB,selectedLane,selectedLane);
        *(undefined1 *)((int)madSrcB + selectedLane + 0x9c) = 0;
        goto LAB_00164700;
      }
      moreLanes = selectedLane != 3;
      selectedLane = selectedLane + 1;
    } while (moreLanes);
    selectedLane = -1;
LAB_00164700:
    laneD = 0;
    do {
      if (*(char *)((int)&extraSourceSelect + laneD) != '\x04') {
        (**(code **)(*mergedInst + 0x88))(mergedInst,otherIndexB,laneD,selectedLane);
      }
      moreLanes = laneD != 3;
      laneD = laneD + 1;
    } while (moreLanes);
  }
LAB_00164744:
  laneE = 0;
  do {
    if (*(char *)((int)&movDestSelect + laneE) != '\x01') {
      isMixResult = (**(code **)(*operandVReg + 0x60))(operandVReg);
      if (isMixResult == 0) {
        (**(code **)(*mergedInst + 0x88))(mergedInst,matchedSrcIndex,laneE,*(undefined1 *)((int)&movSrc1Select + laneE))
        ;
      }
      else {
        operandRecord3 = IRInst__getOperandRecord(operandVReg,0);
        firstUnwrittenComponentResult = SelectWord__firstUnwrittenComponent(*(undefined4 *)(operandRecord3 + 0x10));
        (**(code **)(*operandVReg + 0x88))(operandVReg,1,firstUnwrittenComponentResult,*(undefined1 *)((int)&movSrc1Select + laneE));
        (**(code **)(*mergedInst + 0x88))(mergedInst,matchedSrcIndex,laneE,firstUnwrittenComponentResult);
        *(undefined1 *)((int)operandVReg + firstUnwrittenComponentResult + 0x9c) = 0;
      }
    }
    moreLanes = laneE != 3;
    laneE = laneE + 1;
  } while (moreLanes);
  if (*(int *)(pass + 0x478) < operandVReg[0x58]) {
    operandVReg[0x58] = operandVReg[0x58] + 1;
  }
  else {
    operandVReg[0x58] = *(int *)(pass + 0x478) + 1;
  }
  if (lastOperandSource != 0) {
    IRInst__setLastOperandFromRecord(mergedInst,&lastOperandRecord,0,*(undefined4 *)(pass + 8));
    if (*(int *)(pass + 0x478) < *(int *)(lastOperandSource + 0x160)) {
      *(int *)(lastOperandSource + 0x160) = *(int *)(lastOperandSource + 0x160) + 1;
    }
    else {
      *(int *)(lastOperandSource + 0x160) = *(int *)(pass + 0x478) + 1;
    }
  }
  mergedInst[0x58] = movDepthAboveBase + *(int *)(pass + 0x478);
  return 0;
}

/* Scheduler__compareNodes @ 0x1648ac (456 bytes) */
int Scheduler__compareNodes(scheduler, nodeA, nodeB, rankArg)
  int scheduler;
  int nodeA;
  int nodeB;
  uint rankArg;
{
  int rankBOrDifference;
  int rankA;
  
  if (*(int *)(scheduler + 0x20) == 0) {
    if (*(int *)(scheduler + 0x24) == 0) {
      rankBOrDifference = *(int *)(nodeA + 0x1c);
      if (rankBOrDifference == *(int *)(nodeB + 0x1c)) {
        rankBOrDifference = *(int *)(nodeA + 0x14) - *(int *)(nodeB + 0x14);
        if (rankBOrDifference != 0) {
          return rankBOrDifference;
        }
        rankBOrDifference = *(int *)(nodeB + 0x5c);
        if (*(int *)(nodeA + 0x5c) == rankBOrDifference) {
          rankBOrDifference = nodeB;
          rankA = (**(code **)(**(int **)(scheduler + 8) + 0x60))
                            (*(int **)(scheduler + 8),nodeA,nodeB,rankArg);
          rankBOrDifference = (**(code **)(**(int **)(scheduler + 8) + 0x60))
                            (*(int **)(scheduler + 8),nodeB,rankBOrDifference,rankArg);
          if (rankA - rankBOrDifference != 0) {
            return rankA - rankBOrDifference;
          }
          rankBOrDifference = *(int *)(nodeA + 0xc) - *(int *)(nodeB + 0xc);
          goto joined_r0x00164a48;
        }
      }
    }
    else {
      rankBOrDifference = *(int *)(nodeA + 0x1c);
      if (rankBOrDifference == *(int *)(nodeB + 0x1c)) {
        rankBOrDifference = nodeB;
        rankA = (**(code **)(**(int **)(scheduler + 8) + 100))
                          (*(int **)(scheduler + 8),nodeA,nodeB,rankArg);
        rankBOrDifference = (**(code **)(**(int **)(scheduler + 8) + 100))
                          (*(int **)(scheduler + 8),nodeB,rankBOrDifference,rankArg);
        if (rankA - rankBOrDifference != 0) {
          return rankA - rankBOrDifference;
        }
        rankBOrDifference = *(int *)(nodeA + 0xc) - *(int *)(nodeB + 0xc);
        if (rankBOrDifference != 0) {
          return rankBOrDifference;
        }
        rankBOrDifference = *(int *)(nodeA + 0x14) - *(int *)(nodeB + 0x14);
joined_r0x00164a48:
        if (rankBOrDifference != 0) {
          return rankBOrDifference;
        }
        return *(int *)(nodeB + 0x10) - *(int *)(nodeA + 0x10);
      }
    }
  }
  else {
    rankBOrDifference = *(int *)(nodeA + 0x10) - *(int *)(nodeB + 0x10);
    if (rankBOrDifference != 0) {
      return -rankBOrDifference;
    }
    rankBOrDifference = *(int *)(nodeA + 0xc) - *(int *)(nodeB + 0xc);
    if (rankBOrDifference != 0) {
      return rankBOrDifference;
    }
    rankBOrDifference = *(int *)(nodeA + 0x1c);
    if (rankBOrDifference == *(int *)(nodeB + 0x1c)) {
      rankBOrDifference = *(int *)(nodeA + 0x14) - *(int *)(nodeB + 0x14);
      if (rankBOrDifference != 0) {
        return rankBOrDifference;
      }
      rankBOrDifference = *(int *)(nodeB + 0x5c);
      if (*(int *)(nodeA + 0x5c) == rankBOrDifference) {
        return 0;
      }
    }
  }
  rankA = -1;
  if (rankBOrDifference != 0) {
    rankA = 1;
  }
  return rankA;
}

/* Scheduler__updateFetchBatchMode @ 0x164a74 (312 bytes) */
int Scheduler__updateFetchBatchMode(scheduler, topFetchCount, maxFetchDepth)
  int scheduler;
  int topFetchCount;
  int maxFetchDepth;
{
  int cyclesSinceBatchEnd;
  int isEmpty;
  int listEmpty;
  
  if (*(int *)(scheduler + 0x118) != 0) {
    listEmpty = DList__isEmpty(scheduler + 0x34);
    if (listEmpty == 0) {
      if ((*(int *)(scheduler + 0x28) <= *(int *)(scheduler + 300)) &&
         (listEmpty = DList__isEmpty(scheduler + 0x4c), listEmpty == 0)) {
        *(uint *)(scheduler + 0x118) = (uint)(*(int *)(scheduler + 0x110) <= maxFetchDepth);
      }
    }
    else {
      *(undefined4 *)(scheduler + 0x118) = 0;
    }
    if (*(int *)(scheduler + 0x118) != 0) {
      return;
    }
    *(undefined4 *)(scheduler + 0x124) = *(undefined4 *)(scheduler + 0x2c);
    return;
  }
  isEmpty = DList__isEmpty(scheduler + 0x4c);
  if (isEmpty == 0) {
    isEmpty = DList__isEmpty(scheduler + 0x34);
    if ((isEmpty != 0) ||
       ((*(int *)(scheduler + 0x120) < *(int *)(scheduler + 0x11c) &&
        (topFetchCount < *(int *)(scheduler + 0x28))))) goto LAB_00164b7c;
    cyclesSinceBatchEnd = *(int *)(scheduler + 0x2c) - *(int *)(scheduler + 0x124);
    if (cyclesSinceBatchEnd < 8) {
      *(uint *)(scheduler + 0x118) = (uint)(*(int *)(scheduler + 0x110) - cyclesSinceBatchEnd < maxFetchDepth);
      goto LAB_00164b7c;
    }
  }
  *(undefined4 *)(scheduler + 0x118) = 1;
LAB_00164b7c:
  if (*(int *)(scheduler + 0x118) != 0) {
    *(undefined4 *)(scheduler + 300) = 0;
    *(undefined4 *)(scheduler + 0x128) = *(undefined4 *)(scheduler + 0x120);
  }
  return;
}

/* VRegKey__equals @ 0x164bac (44 bytes) */
int VRegKey__equals(instA, instB)
  int instA;
  int instB;
{
  if ((*(int *)(instA + 0x94) == *(int *)(instB + 0x94)) &&
     (*(int *)(instA + 0x98) == *(int *)(instB + 0x98))) {
    return 0;
  }
  return 0xffffffff;
}

/* VRegKey__hash @ 0x164bd8 (20 bytes) */
int VRegKey__hash(inst)
  int inst;
{
  return *(int *)(inst + 0x98) * 0x10000 + *(int *)(inst + 0x94);
}

/* Scheduler__findFreeHwRegister @ 0x164bec (520 bytes) */
int Scheduler__findFreeHwRegister(scheduler, componentMask, cycle, useConstantFile)
  int *scheduler;
  undefined4 componentMask;
  int cycle;
  int useConstantFile;
{
  int *target;
  int highWater;
  unsigned int ghidra_home[8] = { scheduler, componentMask, cycle, useConstantFile, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  int *arraySlot;
  bool isTempFile;
  int slack;
  int *arrayCursor;
  uint registerCount;
  uint candidateReg;
  uint bestReg;
  uint reg;
  int arrayByteOffset;
  char *requestedMaskCursor;
  int minSlack;
  int componentByteOffset;
  int bestSlack;
  int componentsLeft;
  int lastUseArrays [6];
  
  isTempFile = useConstantFile == 0;
  (*(unsigned int *)((unsigned char *)ghidra_home + 4)) = componentMask;
  if (isTempFile) {
    bestSlack = 4;
    arrayByteOffset = 0;
    arrayCursor = scheduler;
    do {
      arraySlot = arrayCursor + 0x54;
      arrayCursor = arrayCursor + 1;
      *(int *)((int)lastUseArrays + arrayByteOffset) = *arraySlot;
      arrayByteOffset = arrayByteOffset + 4;
      bestSlack = bestSlack + -1;
    } while (bestSlack != 0);
    registerCount = scheduler[0x51];
    highWater = scheduler[0x68];
  }
  else {
    bestSlack = 4;
    arrayByteOffset = 0;
    arrayCursor = scheduler;
    do {
      arraySlot = arrayCursor + 0x58;
      arrayCursor = arrayCursor + 1;
      *(int *)((int)lastUseArrays + arrayByteOffset) = *arraySlot;
      arrayByteOffset = arrayByteOffset + 4;
      bestSlack = bestSlack + -1;
    } while (bestSlack != 0);
    target = *(int **)(*scheduler + 0x30c);
    registerCount = (**(code **)(*target + 0x13c))(target,*scheduler);
    highWater = scheduler[0x69];
  }
  candidateReg = 0xffffffff;
  if (0 < (int)registerCount) {
    bestSlack = 0x7fffffff;
    bestReg = candidateReg;
    reg = 0;
    do {
      candidateReg = reg;
      if ((!isTempFile) ||
         ((*(uint *)((candidateReg >> 3 & 0x1ffffffc) + scheduler[0x4c] + 8) >> (candidateReg & 0x1f) & 1) != 0)) {
        if (highWater < (int)candidateReg) {
          if (-1 < (int)bestReg) goto LAB_00164d6c;
          break;
        }
        componentsLeft = 4;
        minSlack = 0x7fffffff;
        requestedMaskCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
        componentByteOffset = 0;
        do {
          if (*requestedMaskCursor != '\0') {
            slack = cycle - *(int *)(*(int *)((int)lastUseArrays + componentByteOffset) + candidateReg * 4);
            if (slack < minSlack) {
              minSlack = slack;
            }
            if (minSlack < 0) goto LAB_00164d58;
          }
          requestedMaskCursor = requestedMaskCursor + 1;
          componentByteOffset = componentByteOffset + 4;
          componentsLeft = componentsLeft + -1;
        } while (componentsLeft != 0);
        if ((-1 < minSlack) && (minSlack < bestSlack)) {
          bestReg = candidateReg;
          bestSlack = minSlack;
        }
      }
LAB_00164d58:
      reg = candidateReg + 1;
      candidateReg = bestReg;
    } while (registerCount != reg);
    bestReg = candidateReg;
    if (-1 < (int)candidateReg) {
LAB_00164d6c:
      candidateReg = bestReg;
      if (isTempFile) {
        registerCount = scheduler[0x68];
        if (scheduler[0x68] < (int)candidateReg) {
          registerCount = candidateReg;
        }
        scheduler[0x68] = registerCount;
      }
      else {
        registerCount = scheduler[0x69];
        if (scheduler[0x69] < (int)candidateReg) {
          registerCount = candidateReg;
        }
        scheduler[0x69] = registerCount;
      }
      bestSlack = 4;
      requestedMaskCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 4));
      arrayByteOffset = 0;
      do {
        if (*requestedMaskCursor != '\0') {
          *(int *)(*(int *)((int)lastUseArrays + arrayByteOffset) + candidateReg * 4) = scheduler[0xb];
        }
        requestedMaskCursor = requestedMaskCursor + 1;
        arrayByteOffset = arrayByteOffset + 4;
        bestSlack = bestSlack + -1;
      } while (bestSlack != 0);
    }
  }
  return candidateReg;
}

/* IRInst__needsNoSchedulerNode @ 0x164df4 (136 bytes) */
int IRInst__needsNoSchedulerNode(inst)
  int *inst;
{
  int opcodeInfo;
  int iVar1;
  
  iVar1 = (**(code **)(*inst + 0x7c))(inst);
  if (iVar1 == 0) {
    if ((inst[5] & 0x8000U) == 0) {
      opcodeInfo = inst[0x22];
    }
    else {
      opcodeInfo = inst[0x22];
      if ((*(int *)(opcodeInfo + 4) != 1) && (inst[0x21] == 0)) {
        return 1;
      }
    }
    if (*(int *)(opcodeInfo + 8) != 0xa4) {
      return 0;
    }
  }
  return 1;
}

/* Scheduler__getDependencyLatency @ 0x164e7c (324 bytes) */
int Scheduler__getDependencyLatency(scheduler, producerInst, consumerInst, operandIndexA, operandIndexB, dependencyKind)
  int scheduler;
  int *producerInst;
  int *consumerInst;
  undefined4 operandIndexA;
  undefined4 operandIndexB;
  int dependencyKind;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 modelLatency [6];
  
  if (dependencyKind == 0) {
    iVar1 = (**(code **)(**(int **)(scheduler + 8) + 0x54))
                      (*(int **)(scheduler + 8),producerInst,consumerInst,modelLatency);
    if (iVar1 != 0) {
      return modelLatency[0];
    }
    if ((((*(int *)(producerInst[0x22] + 4) != 1) &&
         ((iVar1 = (**(code **)(*consumerInst + 0x54))(consumerInst), iVar1 == 0 ||
          (iVar1 = IRInst__isProjectionOfClass26or3a(consumerInst), iVar1 != 0)))) &&
        ((iVar1 = (**(code **)(*consumerInst + 0x5c))(consumerInst), iVar1 == 0 ||
         (iVar1 = (**(code **)(*producerInst + 0x28))(producerInst), iVar1 == 0)))) &&
       ((iVar1 = (**(code **)(*consumerInst + 0x60))(consumerInst), iVar1 == 0 &&
        (iVar1 = IRInst__isProjectionOfClass44(producerInst), iVar1 == 0)))) {
      uVar2 = (**(code **)(**(int **)(scheduler + 8) + 0x78))(*(int **)(scheduler + 8));
      return uVar2;
    }
  }
  else if (dependencyKind == 1) {
    return 1;
  }
  return 0;
}

/* IRInst__writesTrackedRegister @ 0x164fc0 (84 bytes) */
int IRInst__writesTrackedRegister(param_1)
  int param_1;
{
  int iVar1;
  
  if ((0 < *(int *)(param_1 + 0x80)) &&
     ((((*(int *)(*(int *)(param_1 + 0x88) + 4) == 1 || ((*(uint *)(param_1 + 0x14) & 0x40) != 0))
       || (iVar1 = *(int *)(param_1 + 0x98), iVar1 == 0x20)) || ((iVar1 == 0x21 || (iVar1 == 0x22)))
      ))) {
    return 1;
  }
  return 0;
}

/* Scheduler__computeBlockRegisterSets @ 0x165014 (1520 bytes) */
int Scheduler__computeBlockRegisterSets(scheduler)
  int *scheduler;
{
  int operandIndex;
  int *liveInCursor;
  int wordsLeft;
  int *liveOutCursor;
  int successorSetCursor;
  int successorBlock;
  int successorByteOffset;
  int *blockRecord;
  int *predBlockRef2;
  int wordAddress2;
  int wordAddress;
  int isPhi2;
  int isPhi;
  int innerSource;
  int *mixSource;
  int *sourceDef;
  int operandNumber;
  int *nextInst;
  int blockNumber;
  uint successorNumber;
  uint operandOrdinal;
  int blockArray;
  int operandByteOffset;
  int nextBlock;
  int registerCount;
  uint *setWord;
  uint *setWord2;
  bool changed;
  uint registerId;
  int *piVar5;
  int program;
  undefined4 *allocation;
  int iVar8;
  int operandIndex2;
  int *followingInst;
  int iVar11;
  int iVar12;
  int isPhi3;
  undefined4 *bitSet;
  int *predBlockRef;
  int *inst;
  int block;
  undefined4 arena;
  uint wordCount;
  
  program = scheduler[1];
  block = *(int *)(program + 900);
  if (*(int *)(block + 8) != 0) {
    do {
      registerCount = scheduler[0x51];
      wordCount = registerCount + 0x1fU >> 5;
      arena = *(undefined4 *)(*scheduler + 0x378);
      allocation = (undefined4 *)Arena__alloc(arena,wordCount * 4 + 0xc);
      bitSet = allocation + 1;
      *allocation = arena;
      allocation[1] = wordCount;
      allocation[2] = registerCount;
      if (wordCount != 0) {
        allocation = bitSet;
        if (wordCount == 0) {
          wordCount = 1;
        }
        do {
          allocation[2] = 0;
          allocation = allocation + 1;
          wordCount = wordCount - 1;
        } while (wordCount != 0);
      }
      *(undefined4 **)(block + 0x104) = bitSet;
      registerCount = scheduler[0x51];
      wordCount = registerCount + 0x1fU >> 5;
      arena = *(undefined4 *)(*scheduler + 0x378);
      allocation = (undefined4 *)Arena__alloc(arena,wordCount * 4 + 0xc);
      bitSet = allocation + 1;
      *allocation = arena;
      allocation[1] = wordCount;
      allocation[2] = registerCount;
      if (wordCount != 0) {
        allocation = bitSet;
        if (wordCount == 0) {
          wordCount = 1;
        }
        do {
          allocation[2] = 0;
          allocation = allocation + 1;
          wordCount = wordCount - 1;
        } while (wordCount != 0);
      }
      *(undefined4 **)(block + 0x100) = bitSet;
      *(undefined4 *)(block + 0x118) = *(undefined4 *)(scheduler[1] + 0x474);
      block = *(int *)(block + 8);
    } while (*(int *)(block + 8) != 0);
    program = scheduler[1];
  }
  *(int *)(program + 0x474) = *(int *)(program + 0x474) + 1;
  iVar8 = scheduler[1];
  nextBlock = *(int *)(*(int *)(iVar8 + 900) + 8);
  block = *(int *)(iVar8 + 900);
  if (nextBlock != 0) {
    do {
      iVar8 = nextBlock;
      nextInst = (int *)(*(int **)(block + 0x98))[2];
      inst = *(int **)(block + 0x98);
      if (nextInst != (int *)0x0) {
        do {
          followingInst = nextInst;
          if (((inst[5] & 1U) != 0) && (0 < inst[0x21])) {
            operandNumber = 1;
            operandOrdinal = 0;
            operandByteOffset = 0;
            do {
              sourceDef = (int *)IRInst__getOperandSource(inst,operandNumber);
              if (((sourceDef[5] & 0x40U) == 0) || (operandIndex2 = RegKind__flagBit0(sourceDef[0x26]), operandIndex2 == 0)) {
                operandIndex2 = (**(code **)(*sourceDef + 0x5c))(sourceDef);
                if (((operandIndex2 != 0) || (operandIndex2 = (**(code **)(*sourceDef + 0x60))(sourceDef), operandIndex2 != 0)) &&
                   (0 < sourceDef[0x21])) {
                  operandIndex2 = 1;
                  do {
                    mixSource = (int *)IRInst__getOperandSource(sourceDef,operandIndex2);
                    iVar11 = (**(code **)(*mixSource + 0x5c))(mixSource);
                    if (iVar11 == 0) {
                      if (((mixSource[5] & 0x40U) != 0) &&
                         (iVar11 = RegKind__flagBit0(mixSource[0x26]), iVar11 != 0)) {
                        isPhi2 = (**(code **)(*inst + 0x7c))(inst);
                        if (isPhi2 == 0) {
                          registerId = mixSource[0x25];
                          wordAddress = (registerId >> 3 & 0x1ffffffc) + *(int *)(block + 0x100);
                        }
                        else {
                          predBlockRef = (int *)0x0;
                          if (operandOrdinal < *(uint *)(*(int *)(block + 0xd4) + 4)) {
                            predBlockRef = (int *)(operandByteOffset + *(int *)(*(int *)(block + 0xd4) + 8));
                          }
                          registerId = mixSource[0x25];
                          wordAddress = (registerId >> 3 & 0x1ffffffc) + *(int *)(*predBlockRef + 0x104);
                        }
                        *(uint *)(wordAddress + 8) = 1 << (registerId & 0x1f) | *(uint *)(wordAddress + 8);
                      }
                    }
                    else if (0 < mixSource[0x21]) {
                      operandIndex = 1;
                      do {
                        innerSource = IRInst__getOperandSource(mixSource,operandIndex);
                        if (((*(uint *)(innerSource + 0x14) & 0x40) != 0) &&
                           (isPhi3 = RegKind__flagBit0(*(undefined4 *)(innerSource + 0x98)), isPhi3 != 0)) {
                          isPhi3 = (**(code **)(*inst + 0x7c))(inst);
                          if (isPhi3 == 0) {
                            registerId = *(uint *)(innerSource + 0x94);
                            wordAddress2 = (registerId >> 3 & 0x1ffffffc) + *(int *)(block + 0x100);
                          }
                          else {
                            predBlockRef = (int *)0x0;
                            if (operandOrdinal < *(uint *)(*(int *)(block + 0xd4) + 4)) {
                              predBlockRef = (int *)(operandByteOffset + *(int *)(*(int *)(block + 0xd4) + 8));
                            }
                            registerId = *(uint *)(innerSource + 0x94);
                            wordAddress2 = (registerId >> 3 & 0x1ffffffc) + *(int *)(*predBlockRef + 0x104);
                          }
                          *(uint *)(wordAddress2 + 8) = 1 << (registerId & 0x1f) | *(uint *)(wordAddress2 + 8);
                        }
                        operandIndex = operandIndex + 1;
                      } while (operandIndex <= mixSource[0x21]);
                    }
                    operandIndex2 = operandIndex2 + 1;
                  } while (operandIndex2 <= sourceDef[0x21]);
                }
              }
              else {
                isPhi = (**(code **)(*inst + 0x7c))(inst);
                if (isPhi == 0) {
                  registerId = sourceDef[0x25];
                  operandIndex2 = (registerId >> 3 & 0x1ffffffc) + *(int *)(block + 0x100);
                }
                else {
                  predBlockRef2 = (int *)0x0;
                  if (operandOrdinal < *(uint *)(*(int *)(block + 0xd4) + 4)) {
                    predBlockRef2 = (int *)(operandByteOffset + *(int *)(*(int *)(block + 0xd4) + 8));
                  }
                  registerId = sourceDef[0x25];
                  operandIndex2 = (registerId >> 3 & 0x1ffffffc) + *(int *)(*predBlockRef2 + 0x104);
                }
                *(uint *)(operandIndex2 + 8) = 1 << (registerId & 0x1f) | *(uint *)(operandIndex2 + 8);
              }
              operandNumber = operandNumber + 1;
              operandOrdinal = operandOrdinal + 1;
              operandByteOffset = operandByteOffset + 4;
            } while (operandNumber <= inst[0x21]);
            followingInst = (int *)inst[2];
          }
          nextInst = (int *)followingInst[2];
          inst = followingInst;
        } while ((int *)followingInst[2] != (int *)0x0);
        iVar8 = *(int *)(block + 8);
      }
      nextBlock = *(int *)(iVar8 + 8);
      block = iVar8;
    } while (*(int *)(iVar8 + 8) != 0);
    iVar8 = scheduler[1];
  }
  blockArray = FUN_000ec5b8(iVar8);
  do {
    changed = false;
    for (blockNumber = 1; iVar8 = DList__count(scheduler[1] + 0x37c), blockNumber <= iVar8; blockNumber = blockNumber + 1)
    {
      blockRecord = *(int **)(blockArray + blockNumber * 4);
      iVar8 = (**(code **)(*blockRecord + 0x20))(blockRecord);
      if (iVar8 == 0) {
        successorByteOffset = 0;
        for (successorNumber = 1; successorNumber <= *(uint *)(blockRecord[0x34] + 4); successorNumber = successorNumber + 1) {
          successorBlock = *(int *)(*(int *)(blockRecord[0x34] + 8) + successorByteOffset);
          if (successorBlock != 0) {
            liveOutCursor = (int *)blockRecord[0x41];
            successorSetCursor = *(int *)(successorBlock + 0x100);
            wordsLeft = *liveOutCursor;
            if (wordsLeft != 0) {
              if (wordsLeft == 0) {
                wordsLeft = 1;
              }
              do {
                setWord = (uint *)(successorSetCursor + 8);
                successorSetCursor = successorSetCursor + 4;
                liveOutCursor[2] = liveOutCursor[2] | *setWord;
                liveOutCursor = liveOutCursor + 1;
                wordsLeft = wordsLeft + -1;
              } while (wordsLeft != 0);
            }
          }
          successorByteOffset = successorByteOffset + 4;
        }
        liveInCursor = (int *)blockRecord[0x40];
        iVar8 = blockRecord[0x41];
        wordsLeft = *liveInCursor;
        if (wordsLeft != 0) {
          iVar11 = iVar8;
          piVar5 = liveInCursor;
          iVar12 = wordsLeft;
          if ((liveInCursor[2] | *(uint *)(iVar8 + 8)) == liveInCursor[2]) {
            do {
              if (iVar12 + -1 == 0) goto LAB_001655a8;
              setWord = (uint *)(piVar5 + 3);
              setWord2 = (uint *)(iVar11 + 0xc);
              iVar11 = iVar11 + 4;
              piVar5 = piVar5 + 1;
              iVar12 = iVar12 + -1;
            } while ((*setWord | *setWord2) == *setWord);
          }
          if (wordsLeft != 0) {
            if (wordsLeft == 0) {
              wordsLeft = 1;
            }
            do {
              setWord = (uint *)(iVar8 + 8);
              iVar8 = iVar8 + 4;
              liveInCursor[2] = liveInCursor[2] | *setWord;
              liveInCursor = liveInCursor + 1;
              wordsLeft = wordsLeft + -1;
            } while (wordsLeft != 0);
          }
          changed = true;
        }
      }
LAB_001655a8: ;
    }
    if (!changed) {
      return;
    }
  } while( true );
}

/* FUN_00165604 @ 0x165604 (388 bytes) */
int FUN_00165604(param_1, inst)
  int param_1;
  int *inst;
{
  int operandRecord2;
  int sourceDef;
  int sourceDef2;
  int operandRecord;
  int loopIndex;
  int iVar1;
  int iVar2;
  int loopIndex2;
  int iVar4;
  int *inst1;
  
  loopIndex2 = 0;
  do {
    iVar1 = loopIndex2 * 4 + param_1;
    inst1 = *(int **)(iVar1 + 0x10);
    if (inst1 == (int *)0x0) {
      *(int **)(iVar1 + 0x10) = inst;
      return inst;
    }
    if (((*(int *)(inst1[0x22] + 8) == *(int *)(inst[0x22] + 8)) &&
        (inst1[0x48] == inst[0x48])) && (inst1[0x49] == inst[0x49])) {
      operandRecord = IRInst__getOperandRecord(inst1,0);
      iVar4 = *(int *)(operandRecord + 0x10);
      operandRecord = IRInst__getOperandRecord(inst,0);
      if (iVar4 == *(int *)(operandRecord + 0x10)) {
        loopIndex = 1;
        while( true ) {
          iVar4 = (**(code **)(*inst1 + 0x14))(inst1);
          if (iVar4 < loopIndex) {
            return inst1;
          }
          sourceDef = IRInst__getOperandSource(inst1,loopIndex);
          sourceDef2 = IRInst__getOperandSource(inst,loopIndex);
          if (sourceDef != sourceDef2) break;
          if (((inst1[loopIndex * 6 + 0x28] & 1U) != (inst[loopIndex * 6 + 0x28] & 1U)) ||
             (((uint)inst1[loopIndex * 6 + 0x28] >> 1 & 1) !=
              ((uint)inst[loopIndex * 6 + 0x28] >> 1 & 1))) break;
          operandRecord2 = IRInst__getOperandRecord(inst1,loopIndex);
          iVar2 = *(int *)(operandRecord2 + 0x10);
          operandRecord2 = IRInst__getOperandRecord(inst,loopIndex);
          if (iVar2 != *(int *)(operandRecord2 + 0x10)) break;
          loopIndex = loopIndex + 1;
        }
      }
    }
    loopIndex2 = loopIndex2 + 1;
    if (0x1f < loopIndex2) {
      return inst;
    }
  } while( true );
}

/* FUN_00165788 @ 0x165788 (628 bytes) */
int FUN_00165788(inst, param_2)
  int *inst;
  undefined4 param_2;
{
  undefined4 operandIndex4;
  int operandIndex2;
  int operandIndex;
  undefined4 sourceDef;
  int operandRecord2;
  int *operandVReg;
  int *operandVReg2;
  undefined4 operandIndex3;
  int operandRecord;
  int iVar5;
  int loopIndex;
  int iVar7;
  undefined4 uVar8;
  
  loopIndex = 1;
  do {
    iVar5 = (**(code **)(*inst + 0x14))(inst);
    if (iVar5 < loopIndex) {
      return;
    }
    operandVReg = (int *)IRInst__getOperandSource(inst,loopIndex);
    iVar5 = (**(code **)(*inst + 0x60))(inst);
    if ((iVar5 == 0) && (iVar5 = (**(code **)(*operandVReg + 0x5c))(operandVReg), iVar5 != 0)) {
LAB_00165840:
      iVar7 = 1;
      iVar5 = (**(code **)(*operandVReg + 0x60))(operandVReg);
      if ((iVar5 != 0) || (iVar7 = (**(code **)(*operandVReg + 0x14))(operandVReg), 0 < iVar7)) {
        operandIndex = 1;
        do {
          sourceDef = IRInst__getOperandSource(operandVReg,operandIndex);
          operandIndex3 = (**(code **)(*inst + 0x94))(inst,sourceDef,param_2);
          operandRecord = IRInst__getOperandRecord(operandVReg,operandIndex);
          operandIndex = operandIndex + 1;
          uVar8 = *(undefined4 *)(operandRecord + 0x10);
          operandRecord = IRInst__getOperandRecord(inst,operandIndex3);
          *(undefined4 *)(operandRecord + 0x10) = uVar8;
        } while (operandIndex <= iVar7);
      }
    }
    else {
      iVar5 = (**(code **)(*operandVReg + 0x60))(operandVReg);
      if (iVar5 != 0) {
        operandVReg2 = (int *)IRInst__getOperandSource(operandVReg,1);
        iVar5 = (**(code **)(*operandVReg2 + 0x5c))(operandVReg2);
        if (iVar5 == 0) goto LAB_00165840;
      }
      iVar5 = (**(code **)(*operandVReg + 0x60))(operandVReg);
      if (iVar5 != 0) {
        operandVReg2 = (int *)IRInst__getOperandSource(operandVReg,1);
        iVar5 = (**(code **)(*operandVReg2 + 0x5c))(operandVReg2);
        if (iVar5 != 0) {
          operandVReg = (int *)IRInst__getOperandSource(operandVReg,1);
          for (operandIndex2 = 1; iVar7 = (**(code **)(*operandVReg + 0x14))(operandVReg), operandIndex2 <= iVar7;
              operandIndex2 = operandIndex2 + 1) {
            sourceDef = IRInst__getOperandSource(operandVReg,operandIndex2);
            operandIndex4 = (**(code **)(*inst + 0x94))(inst,sourceDef,param_2);
            operandRecord2 = IRInst__getOperandRecord(operandVReg,operandIndex2);
            uVar8 = *(undefined4 *)(operandRecord2 + 0x10);
            iVar7 = IRInst__getOperandRecord(inst,operandIndex4);
            *(undefined4 *)(iVar7 + 0x10) = uVar8;
          }
        }
      }
    }
    loopIndex = loopIndex + 1;
  } while( true );
}

/* Scheduler__assignFreshVirtualRegister @ 0x1659fc (384 bytes) */
int Scheduler__assignFreshVirtualRegister(scheduler, node)
  int *scheduler;
  int node;
{
  int memberInst;
  int componentIndex;
  int newRegId2;
  int counterCursor;
  int newRegId;
  int componentsLeft;
  uint memberFlags;
  int nodeInstAlias;
  int flagBit0Result;
  char *groupRecord;
  char *laneByteCursor;
  char *memberSlotCursor;
  int *inst;
  int componentsLeft2;
  
  inst = *(int **)(node + 0x38);
  if (((((inst[5] & 0x20U) == 0) && (inst[0x20] != 0)) &&
      (flagBit0Result = RegKind__flagBit0(inst[0x26]), flagBit0Result != 0)) && ((inst[5] & 2U) == 0)) {
    (**(code **)(*inst + 0x50))(inst);
  }
  groupRecord = *(char **)(node + 0x60);
  if (groupRecord == (char *)0x0) {
    nodeInstAlias = *(int *)(node + 0x38);
    componentsLeft2 = 4;
    counterCursor = node;
    do {
      if ((*(char *)(nodeInstAlias + 0xc) != '\0') && (0 < *(int *)(counterCursor + 0x48))) {
        return;
      }
      nodeInstAlias = nodeInstAlias + 1;
      counterCursor = counterCursor + 4;
      componentsLeft2 = componentsLeft2 + -1;
    } while (componentsLeft2 != 0);
    newRegId2 = *(int *)(*scheduler + 0x3c4) + 1;
    *(int *)(*scheduler + 0x3c4) = newRegId2;
    *(int *)(*(int *)(node + 0x38) + 0x94) = newRegId2;
    *(uint *)(*(int *)(node + 0x38) + 0x14) =
         *(uint *)(*(int *)(node + 0x38) + 0x14) & 0xffffffbf;
  }
  else {
    componentsLeft = 4;
    componentIndex = 0;
    laneByteCursor = groupRecord;
    memberSlotCursor = groupRecord;
    do {
      if (((*laneByteCursor != '\0') && (*(int *)(memberSlotCursor + 0x18) != 0)) &&
         (0 < *(int *)(componentIndex * 4 + *(int *)(memberSlotCursor + 0x18) + 0x48))) {
        return;
      }
      componentIndex = componentIndex + 1;
      laneByteCursor = laneByteCursor + 1;
      memberSlotCursor = memberSlotCursor + 4;
      componentsLeft = componentsLeft + -1;
    } while (componentsLeft != 0);
    newRegId = *(int *)(*scheduler + 0x3c4) + 1;
    *(int *)(*scheduler + 0x3c4) = newRegId;
    for (memberInst = *(int *)(*(int *)(groupRecord + 8) + 0x38); memberInst != 0;
        memberInst = IRInst__getOperandSource(memberInst,*(undefined4 *)(memberInst + 0x84))) {
      memberFlags = *(uint *)(memberInst + 0x14);
      *(int *)(memberInst + 0x94) = newRegId;
      *(uint *)(memberInst + 0x14) = memberFlags & 0xffffffbf;
      if ((memberFlags & 0x200) == 0) {
        return;
      }
    }
  }
  return;
}

/* Scheduler__addDataDependencyEdge @ 0x165b7c (448 bytes) */
int Scheduler__addDataDependencyEdge(scheduler, fromNode, toNode, operandIndex, subOperandIndex, componentMask, param_7)
  int *scheduler;
  int fromNode;
  int toNode;
  undefined4 operandIndex;
  undefined4 subOperandIndex;
  undefined4 componentMask;
  uint param_7;
{
  undefined4 arena;
  uint *toPredEdges;
  unsigned int ghidra_home[8] = { scheduler, fromNode, toNode, operandIndex, subOperandIndex, componentMask, param_7, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  undefined4 *edgeAlloc;
  undefined4 latency;
  undefined4 *appendSlot;
  undefined4 a2;
  undefined4 a3;
  undefined4 a5;
  undefined4 a6;
  char *maskByte;
  uint vectorCount;
  uint *fromSuccEdges;
  undefined4 uVar7;
  int componentsLeft;
  
  arena = *(undefined4 *)(*scheduler + 0x378);
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = componentMask;
  edgeAlloc = (undefined4 *)Arena__alloc(arena,0x24);
  a6 = 0x1010101;
  *edgeAlloc = arena;
  edgeAlloc[4] = 1;
  a3 = 0;
  edgeAlloc[7] = 0x1010101;
  a5 = 0;
  edgeAlloc[1] = fromNode;
  edgeAlloc[3] = 0;
  edgeAlloc[5] = 0;
  edgeAlloc[6] = 0;
  edgeAlloc[8] = 0;
  edgeAlloc[2] = toNode;
  a2 = *(undefined4 *)(toNode + 0x38);
  uVar7 = operandIndex;
  latency = ((int (*)())Scheduler__getDependencyLatency)(scheduler,*(undefined4 *)(fromNode + 0x38),a2,0,operandIndex,0);
  edgeAlloc[5] = operandIndex;
  edgeAlloc[4] = latency;
  edgeAlloc[6] = subOperandIndex;
  uVar7 = (**(code **)(*(int *)scheduler[3] + 0x20))
                    ((int *)scheduler[3],*(undefined4 *)(fromNode + 0x38),a2,a3,uVar7,a5,a6);
  edgeAlloc[8] = uVar7;
  edgeAlloc[7] = (*(unsigned int *)((unsigned char *)ghidra_home + 20));
  fromSuccEdges = *(uint **)(fromNode + 0x40);
  vectorCount = fromSuccEdges[1];
  if (vectorCount < *fromSuccEdges) {
    _memset(vectorCount * 4 + fromSuccEdges[2],0,4);
    appendSlot = (undefined4 *)(vectorCount * 4 + fromSuccEdges[2]);
    fromSuccEdges[1] = vectorCount + 1;
  }
  else {
    appendSlot = (undefined4 *)Vector__elementRefGrow(fromSuccEdges,vectorCount);
  }
  *appendSlot = edgeAlloc + 1;
  toPredEdges = *(uint **)(toNode + 0x44);
  vectorCount = toPredEdges[1];
  if (vectorCount < *toPredEdges) {
    _memset(vectorCount * 4 + toPredEdges[2],0,4);
    appendSlot = (undefined4 *)(vectorCount * 4 + toPredEdges[2]);
    toPredEdges[1] = vectorCount + 1;
  }
  else {
    appendSlot = (undefined4 *)Vector__elementRefGrow(toPredEdges,vectorCount);
  }
  *appendSlot = edgeAlloc + 1;
  componentsLeft = 4;
  maskByte = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 20));
  do {
    if (*maskByte != '\0') {
      *(int *)(fromNode + 0x48) = *(int *)(fromNode + 0x48) + 1;
    }
    maskByte = maskByte + 1;
    fromNode = fromNode + 4;
    componentsLeft = componentsLeft + -1;
  } while (componentsLeft != 0);
  *(int *)(toNode + 0x34) = *(int *)(toNode + 0x34) + 1;
  return;
}

/* Scheduler__createNode @ 0x165d3c (504 bytes) */
int Scheduler__createNode(scheduler, inst, priorityRecord, readyCycle)
  int *scheduler;
  int inst;
  undefined4 *priorityRecord;
  undefined4 readyCycle;
{
  undefined4 arena;
  undefined4 priorityPosition;
  undefined4 resourceClass;
  undefined4 nodeIndex;
  undefined4 *appendSlot;
  undefined4 arenaAt378;
  undefined4 *vectorAlloc;
  undefined *nodeVtableBase;
  undefined *nodeVtableTemp;
  undefined4 *nodeAlloc;
  undefined4 *zeroCursor;
  undefined4 priorityDepth;
  undefined4 priorityDescendantsB;
  undefined4 priorityDescendantsA;
  uint vectorCount;
  undefined4 uVar9;
  uint *nodeVector;
  undefined4 uVar11;
  undefined4 *node;
  int fieldsLeft;
  
  nodeIndex = *(undefined4 *)(scheduler[6] + 4);
  *(undefined4 *)(inst + 0x150) = nodeIndex;
  arena = *(undefined4 *)(*scheduler + 0x378);
  nodeAlloc = (undefined4 *)Arena__alloc(arena,0x74);
  nodeVtableBase = PTR_DAT_001e9138;
  node = nodeAlloc + 1;
  nodeVtableTemp = PTR_DAT_001e8b48 + 8;
  *nodeAlloc = arena;
  nodeAlloc[1] = nodeVtableTemp;
  nodeAlloc[0xc] = 0xffffffff;
  nodeAlloc[1] = nodeVtableBase + 8;
  nodeAlloc[0x10] = nodeIndex;
  fieldsLeft = 4;
  nodeAlloc[0x1c] = 0;
  nodeAlloc[2] = 0;
  nodeAlloc[3] = 0;
  nodeAlloc[0xd] = 0;
  nodeAlloc[0xe] = 0;
  nodeAlloc[0xf] = inst;
  nodeAlloc[0x11] = 0;
  nodeAlloc[0x12] = 0;
  nodeAlloc[0x17] = 0;
  nodeAlloc[0x18] = 0;
  nodeAlloc[0x19] = 0;
  nodeAlloc[0x1a] = 0;
  nodeAlloc[0x1b] = 0;
  zeroCursor = node;
  do {
    zeroCursor[0x12] = 0;
    zeroCursor = zeroCursor + 1;
    fieldsLeft = fieldsLeft + -1;
  } while (fieldsLeft != 0);
  nodeAlloc[4] = 0;
  nodeAlloc[7] = 1;
  nodeAlloc[5] = 0;
  nodeAlloc[6] = 1;
  nodeAlloc[8] = 0;
  nodeAlloc[9] = 0;
  nodeAlloc[10] = 0;
  nodeAlloc[0xb] = 0;
  resourceClass = (**(code **)(*(int *)scheduler[2] + 0x4c))((int *)scheduler[2],inst);
  nodeAlloc[0x17] = resourceClass;
  arenaAt378 = *(undefined4 *)(*scheduler + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  uVar9 = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = uVar9;
  nodeAlloc[0x12] = vectorAlloc + 1;
  arenaAt378 = *(undefined4 *)(*scheduler + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arenaAt378,0x14);
  *vectorAlloc = arenaAt378;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arenaAt378;
  vectorAlloc[2] = 0;
  uVar9 = Arena__alloc(arenaAt378,8);
  vectorAlloc[3] = uVar9;
  nodeAlloc[0x11] = vectorAlloc + 1;
  nodeAlloc[0xc] = 0xffffffff;
  nodeAlloc[0xe] = 0;
  nodeAlloc[0xd] = readyCycle;
  uVar11 = priorityRecord[7];
  priorityPosition = priorityRecord[1];
  priorityDepth = priorityRecord[2];
  priorityDescendantsA = priorityRecord[5];
  priorityDescendantsB = priorityRecord[6];
  nodeAlloc[4] = *priorityRecord;
  nodeAlloc[5] = priorityPosition;
  nodeAlloc[6] = priorityDepth;
  nodeAlloc[9] = priorityDescendantsA;
  nodeAlloc[10] = priorityDescendantsB;
  nodeAlloc[0xb] = uVar11;
  nodeVector = (uint *)scheduler[6];
  vectorCount = nodeVector[1];
  if (vectorCount < *nodeVector) {
    _memset((void *)(vectorCount * 4 + nodeVector[2]),0,4);
    nodeVector[1] = vectorCount + 1;
    appendSlot = (undefined4 *)(vectorCount * 4 + nodeVector[2]);
  }
  else {
    appendSlot = (undefined4 *)Vector__elementRefGrow(nodeVector,vectorCount);
  }
  *appendSlot = node;
  SchedModel__countIssuedNode(scheduler[2],node);
  return node;
}

/* Scheduler__findOrCreateExternalNode @ 0x165fa8 (632 bytes) */
int Scheduler__findOrCreateExternalNode(scheduler, inst)
  int *scheduler;
  int inst;
{
  undefined4 *zeroCursor;
  int *appendSlot;
  uint vectorCount;
  undefined4 *vectorAlloc;
  undefined *nodeVtableBase;
  undefined *nodeVtableTemp;
  int *nodeSlot;
  uint externalIndexOrCount;
  undefined4 *nodeSlotAlias;
  undefined4 *nodeAlloc;
  uint loopIndex;
  undefined4 *node;
  uint *externalNodesReloaded;
  undefined4 arena;
  uint externalCount;
  uint *externalNodes;
  int fieldsLeft;
  
  externalCount = ((uint *)scheduler[5])[1];
  externalIndexOrCount = 0;
  if (externalCount != 0) {
    loopIndex = 0;
    externalNodes = (uint *)scheduler[5];
    externalIndexOrCount = externalCount;
    do {
      if (loopIndex < *externalNodes) {
        externalNodesReloaded = externalNodes;
        if (externalIndexOrCount <= loopIndex) {
          _memset(externalIndexOrCount * 4 + externalNodes[2],0,(loopIndex - externalIndexOrCount) * 4 + 4);
          externalNodes[1] = loopIndex + 1;
          externalNodesReloaded = (uint *)scheduler[5];
        }
        nodeSlot = (int *)(loopIndex * 4 + externalNodes[2]);
      }
      else {
        nodeSlot = (int *)Vector__elementRefGrow(externalNodes,loopIndex);
        externalNodesReloaded = (uint *)scheduler[5];
      }
      if (inst == *(int *)(*nodeSlot + 0x38)) {
        if (loopIndex < *externalNodesReloaded) {
          vectorCount = externalNodesReloaded[1];
          if (vectorCount <= loopIndex) {
            _memset(vectorCount * 4 + externalNodesReloaded[2],0,(loopIndex - vectorCount) * 4 + 4);
            externalNodesReloaded[1] = loopIndex + 1;
          }
          nodeSlotAlias = (undefined4 *)(loopIndex * 4 + externalNodesReloaded[2]);
        }
        else {
          nodeSlotAlias = (undefined4 *)Vector__elementRefGrow(externalNodesReloaded,loopIndex);
        }
        return (undefined4 *)*nodeSlotAlias;
      }
      externalIndexOrCount = externalNodesReloaded[1];
      loopIndex = loopIndex + 1;
      externalNodes = externalNodesReloaded;
    } while (loopIndex < externalIndexOrCount);
  }
  arena = *(undefined4 *)(*scheduler + 0x378);
  nodeAlloc = (undefined4 *)Arena__alloc(arena,0x74);
  nodeVtableBase = PTR_DAT_001e9138;
  node = nodeAlloc + 1;
  nodeVtableTemp = PTR_DAT_001e8b48 + 8;
  *nodeAlloc = arena;
  nodeAlloc[1] = nodeVtableTemp;
  nodeAlloc[0xc] = 0xffffffff;
  nodeAlloc[1] = nodeVtableBase + 8;
  nodeAlloc[0xf] = inst;
  fieldsLeft = 4;
  nodeAlloc[0x10] = externalIndexOrCount;
  nodeAlloc[0x1c] = 0;
  nodeAlloc[2] = 0;
  nodeAlloc[3] = 0;
  nodeAlloc[0xd] = 0;
  nodeAlloc[0xe] = 0;
  nodeAlloc[0x11] = 0;
  nodeAlloc[0x12] = 0;
  nodeAlloc[0x17] = 0;
  nodeAlloc[0x18] = 0;
  nodeAlloc[0x19] = 0;
  nodeAlloc[0x1a] = 0;
  nodeAlloc[0x1b] = 0;
  zeroCursor = node;
  do {
    zeroCursor[0x12] = 0;
    zeroCursor = zeroCursor + 1;
    fieldsLeft = fieldsLeft + -1;
  } while (fieldsLeft != 0);
  nodeAlloc[4] = 0;
  nodeAlloc[7] = 1;
  nodeAlloc[5] = 0;
  nodeAlloc[6] = 1;
  nodeAlloc[8] = 0;
  nodeAlloc[9] = 0;
  nodeAlloc[10] = 0;
  nodeAlloc[0xb] = 0;
  arena = *(undefined4 *)(*scheduler + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arena,0x14);
  *vectorAlloc = arena;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arena;
  vectorAlloc[2] = 0;
  arena = Arena__alloc(arena,8);
  vectorAlloc[3] = arena;
  nodeAlloc[0x12] = vectorAlloc + 1;
  arena = *(undefined4 *)(*scheduler + 0x378);
  vectorAlloc = (undefined4 *)Arena__alloc(arena,0x14);
  *vectorAlloc = arena;
  vectorAlloc[1] = 2;
  vectorAlloc[4] = arena;
  vectorAlloc[2] = 0;
  arena = Arena__alloc(arena,8);
  vectorAlloc[3] = arena;
  nodeAlloc[0x11] = vectorAlloc + 1;
  nodeAlloc[0xc] = 0;
  externalNodes = (uint *)scheduler[5];
  vectorCount = externalNodes[1];
  if (vectorCount < *externalNodes) {
    _memset(vectorCount * 4 + externalNodes[2],0,4);
    appendSlot = (int *)(vectorCount * 4 + externalNodes[2]);
    externalNodes[1] = vectorCount + 1;
  }
  else {
    appendSlot = (int *)Vector__elementRefGrow(externalNodes,vectorCount);
  }
  *appendSlot = (int)node;
  return node;
}

/* Scheduler__expandPresubToAdd @ 0x16629c (1448 bytes) */
int Scheduler__expandPresubToAdd(scheduler)
  undefined4 *scheduler;
{
  undefined4 specialFlag;
  undefined4 newResourceClass;
  undefined4 origSrc2Select;
  uint consumerPredCount;
  uint succCount;
  uint *consumerPredEdgeVector;
  uint *succEdgeVector;
  int edgeByteOffset2;
  int consumerNode;
  int componentsLeft2;
  int newInstId;
  int succEdgeValue;
  int predEdgeValue;
  int edgeByteOffset;
  int isFetchClass;
  int counterCursor2;
  int modelSpecial;
  int canAddResult;
  int origInst;
  int counterCursor;
  int nextNode;
  int *consumerPredEdge;
  int *succEdge;
  int *predEdge;
  int balanceEnabled;
  undefined4 sourceDef;
  int operandRecord;
  uint loopIndex;
  uint loopIndex2;
  int consumerPendingPreds;
  int numSources;
  undefined4 origSrc1Select;
  undefined4 *predEdgeRef;
  uint vectorLength2;
  uint vectorLength3;
  int componentIndex;
  int producerCounterCursor;
  int *edgeMaskCursor;
  uint vectorLength;
  uint loopIndex3;
  uint predCount;
  int node;
  int *newAddInst;
  uint succReverseIndex;
  uint consumerPredReverseIndex;
  uint *predEdgeVector;
  int componentsLeft;
  int componentsLeft3;
  int unconsumedMask [4];
  int writeMaskBytes [4];
  
  newAddInst = (int *)0x0;
  node = scheduler[0x27];
  do {
    while( true ) {
      if (*(int *)(node + 8) == 0) {
        if (newAddInst != (int *)0x0) {
          (**(code **)(*newAddInst + 4))(newAddInst);
        }
        return 0;
      }
      numSources = (**(code **)(**(int **)(node + 0x38) + 0x14))(*(int **)(node + 0x38));
      if (1 < numSources) break;
LAB_00166334:
      nextNode = *(int *)(node + 8);
      DList__unlink(node);
      node = nextNode;
    }
    componentIndex = 0;
    unconsumedMask[0] = 0x1010101;
    componentsLeft = 4;
    counterCursor = node;
    do {
      if (0 < *(int *)(counterCursor + 0x48)) {
        *(undefined1 *)((int)unconsumedMask + componentIndex) = 0;
      }
      componentIndex = componentIndex + 1;
      counterCursor = counterCursor + 4;
      componentsLeft = componentsLeft + -1;
    } while (componentsLeft != 0);
    if (unconsumedMask[0] == 0x1010101) goto LAB_00166334;
    origInst = *(int *)(node + 0x38);
    if (newAddInst == (int *)0x0) {
      newAddInst = IRInst__create(0x12,*scheduler);
    }
    newInstId = newAddInst[0x53];
    operandRecord = IRInst__getOperandRecord(newAddInst,0);
    *(undefined4 *)(operandRecord + 0xc) = 0;
    *(int *)(operandRecord + 8) = newInstId;
    operandRecord = IRInst__getOperandRecord(origInst,0);
    newAddInst[0x27] = *(int *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(newAddInst,0);
    WriteMask__fromSelectWord(writeMaskBytes,*(undefined4 *)(operandRecord + 0x10));
    newAddInst[3] = writeMaskBytes[0];
    sourceDef = IRInst__getOperandSource(origInst,1);
    IRInst__setOperandSource(newAddInst,1,sourceDef,0,*scheduler);
    operandRecord = IRInst__getOperandRecord(origInst,1);
    origSrc1Select = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(newAddInst,1);
    *(undefined4 *)(operandRecord + 0x10) = origSrc1Select;
    sourceDef = IRInst__getOperandSource(origInst,2);
    IRInst__setOperandSource(newAddInst,2,sourceDef,0,*scheduler);
    operandRecord = IRInst__getOperandRecord(origInst,2);
    origSrc2Select = *(undefined4 *)(operandRecord + 0x10);
    operandRecord = IRInst__getOperandRecord(newAddInst,2);
    *(undefined4 *)(operandRecord + 0x10) = origSrc2Select;
    IROperand__setModifierBits(newAddInst + 0x2f,1,(uint)(*(int *)(*(int *)(origInst + 0x88) + 8) == 0x9a));
    canAddResult = (**(code **)(*(int *)scheduler[2] + 0xc))((int *)scheduler[2],newAddInst);
    if (canAddResult != 0) {
      *(int **)(node + 0x38) = newAddInst;
      *(undefined4 *)(node + 0x2c) = 0xffffffff;
      newResourceClass = (**(code **)(*(int *)scheduler[2] + 0x4c))((int *)scheduler[2],newAddInst);
      *(undefined4 *)(node + 0x58) = newResourceClass;
      balanceEnabled = Compiler__isOptionEnabled(*scheduler,0x28);
      if (balanceEnabled != 0) {
        modelSpecial = (**(code **)(*(int *)scheduler[2] + 0x34))((int *)scheduler[2],node);
        specialFlag = 1;
        if (modelSpecial != 0) goto LAB_001664ec;
      }
      specialFlag = 0;
LAB_001664ec:
      *(undefined4 *)(node + 0x5c) = specialFlag;
      loopIndex = 0;
      SchedModel__countIssuedNode(scheduler[2],node);
      predEdgeVector = *(uint **)(node + 0x44);
      predCount = predEdgeVector[1];
      if (0 < (int)predCount) {
        while( true ) {
          if (loopIndex < *predEdgeVector) {
            vectorLength = predEdgeVector[1];
            if (vectorLength <= loopIndex) {
              _memset(vectorLength * 4 + predEdgeVector[2],0,(loopIndex - vectorLength) * 4 + 4);
              predEdgeVector[1] = loopIndex + 1;
            }
            predEdgeRef = (undefined4 *)(loopIndex * 4 + predEdgeVector[2]);
          }
          else {
            predEdgeRef = (undefined4 *)Vector__elementRefGrow(predEdgeVector,loopIndex);
          }
          loopIndex = loopIndex + 1;
          predEdge = (int *)*predEdgeRef;
          if (predEdge[2] == 0) {
            predEdgeValue = *predEdge;
            componentsLeft2 = 4;
            counterCursor2 = predEdgeValue;
            edgeMaskCursor = predEdge;
            do {
              if (*(char *)(edgeMaskCursor + 6) != '\0') {
                *(int *)(counterCursor2 + 0x48) = *(int *)(counterCursor2 + 0x48) + 1;
              }
              edgeMaskCursor = (int *)((int)edgeMaskCursor + 1);
              counterCursor2 = counterCursor2 + 4;
              componentsLeft2 = componentsLeft2 + -1;
            } while (componentsLeft2 != 0);
            isFetchClass = (**(code **)(*(int *)scheduler[3] + 0x20))
                              ((int *)scheduler[3],*(undefined4 *)(predEdgeValue + 0x38));
            predEdge[7] = isFetchClass;
          }
          if (predCount == loopIndex) break;
          predEdgeVector = *(uint **)(node + 0x44);
        }
      }
      succEdgeVector = *(uint **)(node + 0x40);
      succCount = succEdgeVector[1];
      succReverseIndex = succCount - 1;
      if (-1 < (int)succReverseIndex) {
        edgeByteOffset = succReverseIndex * 4;
        loopIndex2 = 0;
        while( true ) {
          if (succReverseIndex < *succEdgeVector) {
            vectorLength2 = succEdgeVector[1];
            if (vectorLength2 <= succReverseIndex) {
              _memset(vectorLength2 * 4 + succEdgeVector[2],0,(succReverseIndex - vectorLength2) * 4 + 4);
              succEdgeVector[1] = succReverseIndex + 1;
            }
            succEdge = (int *)(edgeByteOffset + succEdgeVector[2]);
          }
          else {
            succEdge = (int *)Vector__elementRefGrow(succEdgeVector,succReverseIndex);
          }
          succEdgeValue = *succEdge;
          consumerNode = *(int *)(succEdgeValue + 4);
          if (*(int *)(consumerNode + 0x2c) < 0) {
            if (*(int *)(succEdgeValue + 8) == 0) {
              IRInst__setOperandSource(*(undefined4 *)(consumerNode + 0x38),*(undefined4 *)(succEdgeValue + 0x10),
                           *(undefined4 *)(node + 0x38),0,*scheduler);
              consumerPendingPreds = *(int *)(consumerNode + 0x34);
              if (consumerPendingPreds == 0) {
                DList__unlink(consumerNode);
                consumerPendingPreds = *(int *)(consumerNode + 0x34);
              }
              consumerPredEdgeVector = *(uint **)(consumerNode + 0x44);
              *(int *)(consumerNode + 0x34) = consumerPendingPreds + 1;
              consumerPredCount = consumerPredEdgeVector[1];
              consumerPredReverseIndex = consumerPredCount - 1;
              if (-1 < (int)consumerPredReverseIndex) {
                edgeByteOffset2 = consumerPredReverseIndex * 4;
                loopIndex3 = 0;
                while( true ) {
                  if (consumerPredReverseIndex < *consumerPredEdgeVector) {
                    vectorLength3 = consumerPredEdgeVector[1];
                    if (vectorLength3 <= consumerPredReverseIndex) {
                      _memset(vectorLength3 * 4 + consumerPredEdgeVector[2],0,(consumerPredReverseIndex - vectorLength3) * 4 + 4);
                      consumerPredEdgeVector[1] = consumerPredReverseIndex + 1;
                    }
                    consumerPredEdge = (int *)(edgeByteOffset2 + consumerPredEdgeVector[2]);
                  }
                  else {
                    consumerPredEdge = (int *)Vector__elementRefGrow(consumerPredEdgeVector,consumerPredReverseIndex);
                  }
                  consumerPredEdge = (int *)*consumerPredEdge;
                  if (((consumerPredEdge[2] == 0) && (consumerPredEdge[4] == *(int *)(succEdgeValue + 0x10))) &&
                     (0 < consumerPredEdge[5])) {
                    producerCounterCursor = *consumerPredEdge;
                    componentsLeft3 = 4;
                    do {
                      if (*(char *)(consumerPredEdge + 6) != '\0') {
                        *(int *)(producerCounterCursor + 0x48) = *(int *)(producerCounterCursor + 0x48) + -1;
                      }
                      consumerPredEdge = (int *)((int)consumerPredEdge + 1);
                      producerCounterCursor = producerCounterCursor + 4;
                      componentsLeft3 = componentsLeft3 + -1;
                    } while (componentsLeft3 != 0);
                    Vector__removeAt(*(undefined4 *)(consumerNode + 0x44),consumerPredReverseIndex);
                  }
                  loopIndex3 = loopIndex3 + 1;
                  consumerPredReverseIndex = consumerPredReverseIndex - 1;
                  edgeByteOffset2 = edgeByteOffset2 + -4;
                  if (consumerPredCount == loopIndex3) break;
                  consumerPredEdgeVector = *(uint **)(consumerNode + 0x44);
                }
              }
            }
          }
          else {
            (**(code **)(**(int **)(consumerNode + 0x38) + 0x60))(*(int **)(consumerNode + 0x38));
            Vector__removeAt(*(undefined4 *)(node + 0x40),succReverseIndex);
          }
          loopIndex2 = loopIndex2 + 1;
          succReverseIndex = succReverseIndex - 1;
          edgeByteOffset = edgeByteOffset + -4;
          if (succCount == loopIndex2) break;
          succEdgeVector = *(uint **)(node + 0x40);
        }
      }
      DList__unlink(node);
      return node;
    }
    node = *(int *)(node + 8);
  } while( true );
}

/* Scheduler__copyFetchInEdge @ 0x166844 (456 bytes) */
int Scheduler__copyFetchInEdge(scheduler, fromNode, toNode)
  int *scheduler;
  int fromNode;
  int toNode;
{
  uint vectorCount;
  uint *toPredEdges;
  int counterAddress;
  undefined4 edgeConst;
  int producerNode;
  uint vectorCount2;
  undefined4 *edgeAlloc;
  undefined4 *appendSlot;
  int edgeLatency;
  int componentIndex;
  int edgeLaneBytes;
  int *edgeCompCursor;
  uint predEdgeCount;
  int *sourceEdge;
  uint *fromPredEdges;
  undefined4 arena;
  uint loopIndex;
  int componentsLeft;
  
  loopIndex = 0;
  fromPredEdges = *(uint **)(fromNode + 0x44);
  predEdgeCount = fromPredEdges[1];
  if (0 < (int)predEdgeCount) {
    while( true ) {
      if (loopIndex < *fromPredEdges) {
        vectorCount2 = fromPredEdges[1];
        if (vectorCount2 <= loopIndex) {
          _memset(vectorCount2 * 4 + fromPredEdges[2],0,(loopIndex - vectorCount2) * 4 + 4);
          fromPredEdges[1] = loopIndex + 1;
        }
        edgeAlloc = (undefined4 *)(loopIndex * 4 + fromPredEdges[2]);
      }
      else {
        edgeAlloc = (undefined4 *)Vector__elementRefGrow(fromPredEdges,loopIndex);
      }
      sourceEdge = (int *)*edgeAlloc;
      if (sourceEdge[7] == 1) {
        arena = *(undefined4 *)(*scheduler + 0x378);
        edgeAlloc = (undefined4 *)Arena__alloc(arena,0x24);
        edgeConst = DAT_001b0194;
        *edgeAlloc = arena;
        edgeAlloc[1] = 0;
        componentIndex = 0;
        edgeAlloc[7] = edgeConst;
        edgeAlloc[4] = 1;
        edgeLaneBytes = sourceEdge[6];
        producerNode = *sourceEdge;
        edgeLatency = sourceEdge[3];
        edgeAlloc[3] = 0;
        edgeAlloc[5] = 0;
        edgeAlloc[6] = 0;
        edgeAlloc[8] = 0;
        componentsLeft = 4;
        edgeAlloc[7] = edgeLaneBytes;
        edgeAlloc[1] = producerNode;
        edgeAlloc[4] = edgeLatency;
        edgeAlloc[2] = toNode;
        edgeCompCursor = sourceEdge;
        do {
          if (*(char *)(edgeCompCursor + 6) != '\0') {
            counterAddress = componentIndex * 4 + *sourceEdge;
            *(int *)(counterAddress + 0x48) = *(int *)(counterAddress + 0x48) + 1;
          }
          componentIndex = componentIndex + 1;
          edgeCompCursor = (int *)((int)edgeCompCursor + 1);
          componentsLeft = componentsLeft + -1;
        } while (componentsLeft != 0);
        edgeAlloc[8] = 1;
        toPredEdges = *(uint **)(toNode + 0x44);
        vectorCount = toPredEdges[1];
        if (vectorCount < *toPredEdges) {
          _memset(vectorCount * 4 + toPredEdges[2],0,4);
          appendSlot = (undefined4 *)(vectorCount * 4 + toPredEdges[2]);
          toPredEdges[1] = vectorCount + 1;
        }
        else {
          appendSlot = (undefined4 *)Vector__elementRefGrow(toPredEdges,vectorCount);
        }
        *appendSlot = edgeAlloc + 1;
        return;
      }
      loopIndex = loopIndex + 1;
      if (predEdgeCount == loopIndex) break;
      fromPredEdges = *(uint **)(fromNode + 0x44);
    }
  }
  return;
}

/* Scheduler__hasOtherFlaggedProducer @ 0x166a0c (412 bytes) */
int Scheduler__hasOtherFlaggedProducer(param_1, node)
  undefined4 param_1;
  int node;
{
  uint consumerPredCount;
  uint *consumerPredEdges;
  int *otherPredEdge;
  uint vectorCount;
  int *succEdgeSlot;
  uint vectorCount2;
  uint succEdgeCount;
  int consumerNode;
  uint loopIndex;
  int succEdge;
  uint loopIndex2;
  uint *succEdges;
  
  loopIndex = 0;
  succEdges = *(uint **)(node + 0x40);
  succEdgeCount = succEdges[1];
  if (0 < (int)succEdgeCount) {
    while( true ) {
      if (loopIndex < *succEdges) {
        vectorCount = succEdges[1];
        if (vectorCount <= loopIndex) {
          _memset(vectorCount * 4 + succEdges[2],0,(loopIndex - vectorCount) * 4 + 4);
          succEdges[1] = loopIndex + 1;
        }
        succEdgeSlot = (int *)(loopIndex * 4 + succEdges[2]);
      }
      else {
        succEdgeSlot = (int *)Vector__elementRefGrow(succEdges,loopIndex);
      }
      succEdge = *succEdgeSlot;
      if (*(int *)(succEdge + 8) == 0) {
        consumerNode = *(int *)(succEdge + 4);
        loopIndex2 = 0;
        consumerPredEdges = *(uint **)(consumerNode + 0x44);
        consumerPredCount = consumerPredEdges[1];
        if (0 < (int)consumerPredCount) {
          while( true ) {
            if (loopIndex2 < *consumerPredEdges) {
              vectorCount2 = consumerPredEdges[1];
              if (vectorCount2 <= loopIndex2) {
                _memset(vectorCount2 * 4 + consumerPredEdges[2],0,(loopIndex2 - vectorCount2) * 4 + 4);
                consumerPredEdges[1] = loopIndex2 + 1;
              }
              otherPredEdge = (int *)(loopIndex2 * 4 + consumerPredEdges[2]);
            }
            else {
              otherPredEdge = (int *)Vector__elementRefGrow(consumerPredEdges,loopIndex2);
            }
            otherPredEdge = (int *)*otherPredEdge;
            if ((((otherPredEdge[2] == 0) && (node != *otherPredEdge)) && (otherPredEdge[4] == *(int *)(succEdge + 0x10))
                ) && ((otherPredEdge[5] == *(int *)(succEdge + 0x14) &&
                      ((*(uint *)(*(int *)(*otherPredEdge + 0x38) + 0x14) & 0x40) != 0)))) {
              return 1;
            }
            loopIndex2 = loopIndex2 + 1;
            if (consumerPredCount == loopIndex2) break;
            consumerPredEdges = *(uint **)(consumerNode + 0x44);
          }
        }
      }
      loopIndex = loopIndex + 1;
      if (succEdgeCount == loopIndex) break;
      succEdges = *(uint **)(node + 0x40);
    }
  }
  return 0;
}

/* Scheduler__isNodeReady @ 0x166ba8 (340 bytes) */
int Scheduler__isNodeReady(scheduler, node)
  int scheduler;
  int node;
{
  int iVar1;
  uint vectorCount;
  undefined4 *edgeSlot;
  int producerIsFetchClass;
  undefined4 isReady;
  uint predEdgeCount;
  uint edgeIndex;
  uint *predecessorEdges;
  int *edge;
  
  if (*(int *)(scheduler + 0x2c) < *(int *)(node + 0x30)) {
LAB_00166ce4:
    isReady = 0;
  }
  else {
    iVar1 = (**(code **)(**(int **)(scheduler + 0xc) + 0x20))
                      (*(int **)(scheduler + 0xc),*(undefined4 *)(node + 0x38));
    if (iVar1 != 0) {
      predecessorEdges = *(uint **)(node + 0x44);
      edgeIndex = 0;
      predEdgeCount = predecessorEdges[1];
      if (0 < (int)predEdgeCount) {
        while( true ) {
          if (edgeIndex < *predecessorEdges) {
            vectorCount = predecessorEdges[1];
            if (vectorCount <= edgeIndex) {
              _memset(vectorCount * 4 + predecessorEdges[2],0,(edgeIndex - vectorCount) * 4 + 4);
              predecessorEdges[1] = edgeIndex + 1;
            }
            edgeSlot = (undefined4 *)(edgeIndex * 4 + predecessorEdges[2]);
          }
          else {
            edgeSlot = (undefined4 *)Vector__elementRefGrow(predecessorEdges,edgeIndex);
          }
          edge = (int *)*edgeSlot;
          if ((((edge[2] == 0) &&
               (iVar1 = *edge,
               *(int *)(*(int *)(iVar1 + 0x38) + 0x158) == *(int *)(scheduler + 0x10))) &&
              (producerIsFetchClass = (**(code **)(**(int **)(scheduler + 0xc) + 0x20))(*(int **)(scheduler + 0xc)),
              producerIsFetchClass != 0)) &&
             ((edge[7] != 0 && (*(int *)(scheduler + 0x124) <= *(int *)(iVar1 + 0x2c)))))
          goto LAB_00166ce4;
          edgeIndex = edgeIndex + 1;
          if (predEdgeCount == edgeIndex) break;
          predecessorEdges = *(uint **)(node + 0x44);
        }
      }
    }
    isReady = 1;
  }
  return isReady;
}

/* Scheduler__freeNodes @ 0x166cfc (1024 bytes) */
int Scheduler__freeNodes(scheduler)
  int scheduler;
{
  uint succEdgeCount;
  int predVectorHeader;
  int succVectorHeader;
  int groupRecord;
  uint vectorCount;
  undefined4 *nodeSlot;
  uint vectorCount2;
  int *edgeSlot;
  int edgeAlloc;
  uint nodeCount;
  int *node;
  uint loopIndex;
  uint loopIndex2;
  uint *vector;
  
  loopIndex = 0;
  DList__isEmpty(scheduler + 0x34);
  DList__isEmpty(scheduler + 0x4c);
  DList__isEmpty(scheduler + 100);
  DList__isEmpty(scheduler + 0x7c);
  DList__initSentinel(scheduler + 0x94);
  vector = *(uint **)(scheduler + 0x18);
  nodeCount = vector[1];
  if (0 < (int)nodeCount) {
    while( true ) {
      if (loopIndex < *vector) {
        vectorCount = vector[1];
        if (vectorCount <= loopIndex) {
          _memset(vectorCount * 4 + vector[2],0,(loopIndex - vectorCount) * 4 + 4);
          vector[1] = loopIndex + 1;
        }
        nodeSlot = (undefined4 *)(loopIndex * 4 + vector[2]);
      }
      else {
        nodeSlot = (undefined4 *)Vector__elementRefGrow(vector,loopIndex);
      }
      loopIndex = loopIndex + 1;
      node = (int *)*nodeSlot;
      /* issue #76: same shared scheduler[0x18] array gap as elsewhere - skip a never-populated
       * slot instead of dereferencing it. */
      if (node == (int *)0x0) goto LAB_issue76_skip_166cfc;
      loopIndex2 = 0;
      *(undefined4 *)(node[0xe] + 0x150) = 0;
      vector = (uint *)node[0x10];
      succEdgeCount = vector[1];
      if (0 < (int)succEdgeCount) {
        while( true ) {
          if (loopIndex2 < *vector) {
            vectorCount2 = vector[1];
            if (vectorCount2 <= loopIndex2) {
              _memset(vectorCount2 * 4 + vector[2],0,(loopIndex2 - vectorCount2) * 4 + 4);
              vector[1] = loopIndex2 + 1;
            }
            edgeSlot = (int *)(loopIndex2 * 4 + vector[2]);
          }
          else {
            edgeSlot = (int *)Vector__elementRefGrow(vector,loopIndex2);
          }
          loopIndex2 = loopIndex2 + 1;
          edgeAlloc = *edgeSlot;
          if (edgeAlloc != 0) {
            Arena__free(*(undefined4 *)(edgeAlloc + -4),edgeAlloc + -4);
          }
          if (succEdgeCount == loopIndex2) break;
          vector = (uint *)node[0x10];
        }
      }
      groupRecord = node[0x18];
      if (groupRecord != 0) {
        *(int *)(groupRecord + 0x10) = *(int *)(groupRecord + 0x10) + -1;
        groupRecord = node[0x18];
        if ((*(int *)(groupRecord + 0x10) < 1) && (groupRecord != 0)) {
          Arena__free(*(undefined4 *)(groupRecord + -4),groupRecord + -4);
        }
      }
      succVectorHeader = node[0x10];
      if (succVectorHeader != 0) {
        Arena__free(*(undefined4 *)(succVectorHeader + 0xc),*(undefined4 *)(succVectorHeader + 8));
        Arena__free(*(undefined4 *)(succVectorHeader + -4),succVectorHeader + -4);
      }
      predVectorHeader = node[0x11];
      if (predVectorHeader != 0) {
        Arena__free(*(undefined4 *)(predVectorHeader + 0xc),*(undefined4 *)(predVectorHeader + 8));
        Arena__free(*(undefined4 *)(predVectorHeader + -4),predVectorHeader + -4);
      }
      (**(code **)(*node + 4))(node);
LAB_issue76_skip_166cfc:
      if (nodeCount == loopIndex) break;
      vector = *(uint **)(scheduler + 0x18);
    }
  }
  vector = *(uint **)(scheduler + 0x14);
  loopIndex = 0;
  nodeCount = vector[1];
  if (0 < (int)nodeCount) {
    while( true ) {
      if (loopIndex < *vector) {
        vectorCount = vector[1];
        if (vectorCount <= loopIndex) {
          _memset(vectorCount * 4 + vector[2],0,(loopIndex - vectorCount) * 4 + 4);
          vector[1] = loopIndex + 1;
        }
        nodeSlot = (undefined4 *)(loopIndex * 4 + vector[2]);
      }
      else {
        nodeSlot = (undefined4 *)Vector__elementRefGrow(vector,loopIndex);
      }
      loopIndex = loopIndex + 1;
      node = (int *)*nodeSlot;
      loopIndex2 = 0;
      vector = (uint *)node[0x10];
      succEdgeCount = vector[1];
      if (0 < (int)succEdgeCount) {
        while( true ) {
          if (loopIndex2 < *vector) {
            vectorCount2 = vector[1];
            if (vectorCount2 <= loopIndex2) {
              _memset(vectorCount2 * 4 + vector[2],0,(loopIndex2 - vectorCount2) * 4 + 4);
              vector[1] = loopIndex2 + 1;
            }
            edgeSlot = (int *)(loopIndex2 * 4 + vector[2]);
          }
          else {
            edgeSlot = (int *)Vector__elementRefGrow(vector,loopIndex2);
          }
          loopIndex2 = loopIndex2 + 1;
          edgeAlloc = *edgeSlot;
          if (edgeAlloc != 0) {
            Arena__free(*(undefined4 *)(edgeAlloc + -4),edgeAlloc + -4);
          }
          if (succEdgeCount == loopIndex2) break;
          vector = (uint *)node[0x10];
        }
      }
      groupRecord = node[0x18];
      if (groupRecord != 0) {
        *(int *)(groupRecord + 0x10) = *(int *)(groupRecord + 0x10) + -1;
        groupRecord = node[0x18];
        if ((*(int *)(groupRecord + 0x10) < 1) && (groupRecord != 0)) {
          Arena__free(*(undefined4 *)(groupRecord + -4),groupRecord + -4);
        }
      }
      succVectorHeader = node[0x10];
      if (succVectorHeader != 0) {
        Arena__free(*(undefined4 *)(succVectorHeader + 0xc),*(undefined4 *)(succVectorHeader + 8));
        Arena__free(*(undefined4 *)(succVectorHeader + -4),succVectorHeader + -4);
      }
      predVectorHeader = node[0x11];
      if (predVectorHeader != 0) {
        Arena__free(*(undefined4 *)(predVectorHeader + 0xc),*(undefined4 *)(predVectorHeader + 8));
        Arena__free(*(undefined4 *)(predVectorHeader + -4),predVectorHeader + -4);
      }
      (**(code **)(*node + 4))(node);
      if (nodeCount == loopIndex) break;
      vector = *(uint **)(scheduler + 0x14);
    }
  }
  *(undefined4 *)(*(int *)(scheduler + 0x18) + 4) = 0;
  *(undefined4 *)(*(int *)(scheduler + 0x14) + 4) = 0;
  return;
}

/* Scheduler__computeNodePriorities @ 0x1670fc (2424 bytes) */
int Scheduler__computeNodePriorities(scheduler)
  int *scheduler;
{
  undefined4 arena;
  uint *heightCursor;
  uint *predEdges;
  uint *succEdges;
  int *descendantNodeSlot;
  int *predEdge;
  int *succEdgeSlot;
  int *nodeSlot;
  uint descendantBit;
  uint predEdgeIndex;
  uint fetchSlotWordOffset;
  uint descendantBits;
  uint descendantNodeIndex;
  uint fetchSlot;
  uint succEdgeIndex;
  int sortIndex;
  int bucketCount;
  int descendantByteOffset;
  int threadIsFetchClass;
  int producerCountCursor;
  int resourceSlot10Result;
  int isTextureFetch;
  int nodeHeight;
  int nodeDepth;
  int selectsRewritable;
  int bucketsLeft;
  int targetDepth;
  int minPriority;
  int priorityThreshold;
  int halfTotal;
  int largestBucket;
  int maxNodeHeight;
  int nodeByteOffset;
  int wordsLeft;
  int zeroOffset;
  bool hasDeepFetch;
  bool bVar1;
  bool moreBits;
  int balanceEnabled;
  int *bitSetCursor;
  undefined4 *allocation;
  int descendantMasks;
  uint vectorCount;
  int edge;
  uint vectorCount2;
  int nextNodeByteOffset;
  int iVar11;
  int node;
  int *usedFetchSlots;
  uint processedCount;
  uint nodeIndex;
  uint *descendantMask;
  uint succEdgeCount;
  uint nodeCount;
  undefined4 uVar19;
  uint *allNodes;
  int maxHeight;
  int neighbourNode;
  uint heightHistogram [4];
  int maxDepth;
  uint totalNodes;
  
  arena = *(undefined4 *)(*scheduler + 0x378);
  nodeCount = *(uint *)(scheduler[6] + 4);
  allocation = (undefined4 *)Arena__alloc(arena,0x10);
  usedFetchSlots = allocation + 1;
  allocation[1] = 1;
  *allocation = arena;
  allocation[2] = 0x20;
  iVar11 = 0;
  bitSetCursor = usedFetchSlots;
  do {
    bVar1 = iVar11 == -1;
    bitSetCursor[2] = 0;
    iVar11 = iVar11 + 1;
    bitSetCursor = bitSetCursor + 1;
  } while (bVar1);
  descendantMasks = Arena__alloc(*(undefined4 *)(*scheduler + 0x378),nodeCount << 2);
  wordsLeft = *usedFetchSlots;
  if (wordsLeft != 0) {
    bitSetCursor = usedFetchSlots;
    if (wordsLeft == 0) {
      wordsLeft = 1;
    }
    do {
      bitSetCursor[2] = 0;
      bitSetCursor = bitSetCursor + 1;
      wordsLeft = wordsLeft + -1;
    } while (wordsLeft != 0);
  }
  SchedModel__resetCounters(scheduler[2]);
  maxHeight = 4;
  zeroOffset = 0;
  do {
    *(undefined4 *)(zeroOffset + (int)heightHistogram) = 0;
    zeroOffset = zeroOffset + 4;
    maxHeight = maxHeight + -1;
  } while (maxHeight != 0);
  nodeIndex = nodeCount - 1;
  if ((int)nodeIndex < 0) {
    maxHeight = 0;
    hasDeepFetch = false;
    maxDepth = 0;
  }
  else {
    nodeByteOffset = nodeIndex * 4;
    nextNodeByteOffset = nodeByteOffset + 4;
    descendantMask = (uint *)(descendantMasks + nodeByteOffset);
    maxHeight = 0;
    hasDeepFetch = false;
    maxDepth = 0;
    processedCount = 0;
    totalNodes = nodeCount;
    do {
      allNodes = (uint *)scheduler[6];
      if (nodeIndex < *allNodes) {
        vectorCount = allNodes[1];
        if (vectorCount <= nodeIndex) {
          _memset(vectorCount * 4 + allNodes[2],0,(nodeIndex - vectorCount) * 4 + 4);
          allNodes[1] = nodeCount;
        }
        nodeSlot = (int *)(nodeByteOffset + allNodes[2]);
      }
      else {
        nodeSlot = (int *)Vector__elementRefGrow(allNodes,nodeIndex);
      }
      node = *nodeSlot;
      /* issue #76: same shared-array gap as Scheduler__buildDependencyGraph/Scheduler__buildCoScheduleGroups - skip a never-populated
       * scheduler[6] slot instead of dereferencing/passing it on as a live format object. */
      if (node == 0) goto LAB_issue76_skip_1670fc;
      balanceEnabled = Compiler__isOptionEnabled(*scheduler,0x28);
      if (balanceEnabled == 0) {
LAB_001672b8:
        uVar19 = 0;
      }
      else {
        selectsRewritable = (**(code **)(*(int *)scheduler[2] + 0x34))((int *)scheduler[2],node);
        uVar19 = 1;
        if (selectsRewritable == 0) goto LAB_001672b8;
      }
      *(undefined4 *)(node + 0x5c) = uVar19;
      succEdgeIndex = 0;
      uVar19 = (**(code **)(*(int *)scheduler[2] + 0x4c))
                         ((int *)scheduler[2],*(undefined4 *)(node + 0x38));
      *(undefined4 *)(node + 0x58) = uVar19;
      (**(code **)(*(int *)scheduler[2] + 0x48))((int *)scheduler[2],node);
      (**(code **)(*(int *)scheduler[2] + 0x44))((int *)scheduler[2],node);
      SchedModel__countIssuedNode(scheduler[2],node);
      *descendantMask = 0;
      succEdges = *(uint **)(node + 0x40);
      succEdgeCount = succEdges[1];
      if (0 < (int)succEdgeCount) {
        while( true ) {
          if (succEdgeIndex < *succEdges) {
            vectorCount2 = succEdges[1];
            if (vectorCount2 <= succEdgeIndex) {
              _memset(vectorCount2 * 4 + succEdges[2],0,(succEdgeIndex - vectorCount2) * 4 + 4);
              succEdges[1] = succEdgeIndex + 1;
            }
            succEdgeSlot = (int *)(succEdgeIndex * 4 + succEdges[2]);
          }
          else {
            succEdgeSlot = (int *)Vector__elementRefGrow(succEdges,succEdgeIndex);
          }
          succEdgeIndex = succEdgeIndex + 1;
          edge = *succEdgeSlot;
          nodeDepth = *(int *)(node + 0x14);
          neighbourNode = *(int *)(edge + 4);
          *(int *)(neighbourNode + 0x34) = *(int *)(neighbourNode + 0x34) + 1;
          edge = *(int *)(edge + 0xc) + *(int *)(neighbourNode + 0x14);
          if (nodeDepth < edge) {
            nodeDepth = edge;
          }
          edge = *(int *)(neighbourNode + 0x3c);
          *(int *)(node + 0x14) = nodeDepth;
          if ((int)nodeIndex < edge) {
            descendantBits = *(int *)(descendantMasks + edge * 4) << (edge - nodeIndex & 0x3f) | *descendantMask;
            *descendantMask = descendantBits;
            *descendantMask = descendantBits | 1 << ((*(int *)(neighbourNode + 0x3c) - nodeIndex) - 1 & 0x3f);
          }
          if (succEdgeCount == succEdgeIndex) break;
          succEdges = *(uint **)(node + 0x40);
        }
      }
      nodeHeight = *(int *)(node + 0xc);
      if (maxHeight < nodeHeight) {
        maxHeight = nodeHeight;
      }
      if (*(int *)(*(int *)(*scheduler + 0x30c) + 0x54) <= maxHeight) {
        Compiler__fail(*scheduler,0xf);
      }
      edge = (**(code **)(*(int *)scheduler[3] + 0x20))
                        ((int *)scheduler[3],*(undefined4 *)(node + 0x38));
      if ((edge != 0) ||
         (edge = (**(code **)(*(int *)scheduler[3] + 0x24))
                            ((int *)scheduler[3],*(undefined4 *)(node + 0x38)), edge != 0)) {
        if (nodeHeight < 4) {
          heightHistogram[nodeHeight] = heightHistogram[nodeHeight] + 1;
        }
        if (0 < nodeHeight) {
          hasDeepFetch = true;
        }
        scheduler[0x65] = scheduler[0x65] + 1;
        isTextureFetch = (**(code **)(**(int **)(node + 0x38) + 0x30))(*(int **)(node + 0x38));
        if (isTextureFetch != 0) {
          fetchSlot = *(uint *)(*(int *)(node + 0x38) + 0x134);
          if ((int)fetchSlot < 0x20) {
            if ((int)fetchSlot < 0) goto LAB_0016753c;
          }
          else {
            Compiler__fail(*scheduler,0xf);
          }
          fetchSlotWordOffset = fetchSlot >> 3 & 0x1ffffffc;
          *(uint *)((int)usedFetchSlots + fetchSlotWordOffset + 8) =
               1 << (fetchSlot & 0x1f) | *(uint *)((int)usedFetchSlots + fetchSlotWordOffset + 8);
        }
      }
LAB_0016753c:
      *(uint *)(node + 0x10) = nodeIndex;
      if (*(int *)(node + 0x1c) == 0) {
        resourceSlot10Result = (**(code **)(*(int *)scheduler[2] + 0x28))
                          ((int *)scheduler[2],*(undefined4 *)(node + 0x38));
        uVar19 = 0;
        if (resourceSlot10Result != 0) goto LAB_00167574;
      }
      else {
LAB_00167574:
        uVar19 = 1;
      }
      predEdges = *(uint **)(node + 0x44);
      predEdgeIndex = 0;
      *(undefined4 *)(node + 0x1c) = uVar19;
      vectorCount = predEdges[1];
      if (0 < (int)vectorCount) {
        do {
          if (predEdgeIndex < *predEdges) {
            vectorCount2 = predEdges[1];
            if (vectorCount2 <= predEdgeIndex) {
              _memset(vectorCount2 * 4 + predEdges[2],0,(predEdgeIndex - vectorCount2) * 4 + 4);
              predEdges[1] = predEdgeIndex + 1;
            }
            predEdge = (int *)(predEdgeIndex * 4 + predEdges[2]);
          }
          else {
            predEdge = (int *)Vector__elementRefGrow(predEdges,predEdgeIndex);
          }
          predEdgeIndex = predEdgeIndex + 1;
          predEdge = (int *)*predEdge;
          if (predEdge[2] == 0) {
            edge = *predEdge;
            neighbourNode = 4;
            producerCountCursor = edge;
            do {
              if (*(char *)(predEdge + 6) != '\0') {
                *(int *)(producerCountCursor + 0x48) = *(int *)(producerCountCursor + 0x48) + 1;
              }
              predEdge = (int *)((int)predEdge + 1);
              producerCountCursor = producerCountCursor + 4;
              neighbourNode = neighbourNode + -1;
            } while (neighbourNode != 0);
            if ((*(int *)(edge + 0x1c) != 0) || (uVar19 = 0, *(int *)(node + 0x1c) != 0)) {
              uVar19 = 1;
            }
            *(undefined4 *)(edge + 0x1c) = uVar19;
            threadIsFetchClass = (**(code **)(*(int *)scheduler[3] + 0x20))
                              ((int *)scheduler[3],*(undefined4 *)(node + 0x38));
            if ((threadIsFetchClass == 0) &&
               (threadIsFetchClass = (**(code **)(*(int *)scheduler[3] + 0x24))
                                  ((int *)scheduler[3],*(undefined4 *)(node + 0x38)), threadIsFetchClass == 0)) {
              neighbourNode = *(int *)(edge + 0xc);
              nodeHeight = *(int *)(node + 0xc);
              if (neighbourNode < *(int *)(node + 0xc)) {
LAB_001676d0:
                neighbourNode = nodeHeight;
              }
            }
            else {
              neighbourNode = *(int *)(edge + 0xc);
              nodeHeight = *(int *)(node + 0xc) + 1;
              if (neighbourNode < nodeHeight) goto LAB_001676d0;
            }
            *(int *)(edge + 0xc) = neighbourNode;
          }
          if (vectorCount == predEdgeIndex) break;
          predEdges = *(uint **)(node + 0x44);
        } while( true );
      }
      descendantBit = 0;
      descendantByteOffset = nextNodeByteOffset;
      descendantNodeIndex = nodeCount;
      do {
        if ((1 << (descendantBit & 0x3f) & *descendantMask) != 0) {
          allNodes = (uint *)scheduler[6];
          if (descendantNodeIndex < *allNodes) {
            vectorCount2 = allNodes[1];
            if (vectorCount2 <= descendantNodeIndex) {
              _memset(vectorCount2 * 4 + allNodes[2],0,(descendantNodeIndex - vectorCount2) * 4 + 4);
              allNodes[1] = descendantNodeIndex + 1;
            }
            descendantNodeSlot = (int *)(descendantByteOffset + allNodes[2]);
          }
          else {
            descendantNodeSlot = (int *)Vector__elementRefGrow(allNodes,descendantNodeIndex);
          }
          /* issue #76: same shared-array gap as elsewhere in this function - *descendantNodeSlot (the
           * slot's own stored format pointer, not descendantNodeSlot itself) can legitimately still be an
           * unpopulated 0. */
          if (*descendantNodeSlot == 0) goto LAB_issue76_skip_1670fc_inner;
          if (*(int *)(*descendantNodeSlot + 0x5c) == 0) {
            edge = *(int *)(*descendantNodeSlot + 0x58);
            if (edge == 1) {
              *(int *)(node + 0x24) = *(int *)(node + 0x24) + 1;
            }
            else if (edge == 2) {
              *(int *)(node + 0x28) = *(int *)(node + 0x28) + 1;
            }
          }
          else {
            *(int *)(node + 0x20) = *(int *)(node + 0x20) + 1;
          }
        }
LAB_issue76_skip_1670fc_inner:
        descendantNodeIndex = descendantNodeIndex + 1;
        moreBits = descendantBit != 0x1f;
        descendantByteOffset = descendantByteOffset + 4;
        descendantBit = descendantBit + 1;
      } while (moreBits);
      if (maxDepth < *(int *)(node + 0x14)) {
        maxDepth = *(int *)(node + 0x14);
      }
LAB_issue76_skip_1670fc:
      processedCount = processedCount + 1;
      nodeIndex = nodeIndex - 1;
      nodeCount = nodeCount - 1;
      nextNodeByteOffset = nextNodeByteOffset + -4;
      descendantMask = descendantMask + -1;
      nodeByteOffset = nodeByteOffset + -4;
    } while (processedCount != totalNodes);
  }
  targetDepth = (**(code **)(*(int *)scheduler[2] + 0x5c))((int *)scheduler[2]);
  scheduler[0x44] = maxDepth;
  scheduler[0x45] = targetDepth;
  scheduler[9] = (uint)(maxDepth <= targetDepth);
  maxNodeHeight = *(int *)(*(int *)(*scheduler + 0x30c) + 0x54);
  if (4 < maxNodeHeight) {
    bucketsLeft = 4;
    scheduler[10] = 8;
    largestBucket = 0;
    maxHeight = 0;
    do {
      bucketCount = *(int *)(maxHeight + (int)heightHistogram);
      if (largestBucket < bucketCount) {
        largestBucket = bucketCount;
      }
      maxHeight = maxHeight + 4;
      bucketsLeft = bucketsLeft + -1;
    } while (bucketsLeft != 0);
    largestBucket = (**(code **)(*(int *)scheduler[2] + 0x58))((int *)scheduler[2],largestBucket,maxDepth);
    scheduler[8] = largestBucket;
    goto LAB_00167a18;
  }
  if (-1 < maxHeight) {
    sortIndex = 0;
    descendantMask = heightHistogram;
    do {
      sortIndex = sortIndex + 1;
      if (sortIndex <= maxHeight) {
        heightCursor = heightHistogram + sortIndex;
        node = sortIndex;
        do {
          nodeCount = *descendantMask;
          if ((int)nodeCount < (int)*heightCursor) {
            *descendantMask = *heightCursor;
            *heightCursor = nodeCount;
          }
          node = node + 1;
          heightCursor = heightCursor + 1;
        } while (node <= maxHeight);
      }
      descendantMask = descendantMask + 1;
    } while (sortIndex <= maxHeight);
  }
  maxNodeHeight = maxNodeHeight - maxHeight;
  if (maxNodeHeight + -1 < 1) {
    scheduler[10] = heightHistogram[0];
  }
  else {
    nodeCount = heightHistogram[1];
    if ((int)heightHistogram[1] < (int)heightHistogram[0] / maxNodeHeight) {
      nodeCount = (int)heightHistogram[0] / maxNodeHeight;
    }
    scheduler[10] = nodeCount;
    if ((int)(maxNodeHeight * nodeCount) < (int)heightHistogram[0]) {
      scheduler[10] = nodeCount + 1;
    }
    if ((maxNodeHeight + -1 == 2) && ((int)heightHistogram[0] < (int)(heightHistogram[1] << 1))) {
      halfTotal = ((int)heightHistogram[0] >> 1) + (uint)((int)heightHistogram[0] < 0 && (heightHistogram[0] & 1) != 0);
      if ((int)heightHistogram[2] < halfTotal) {
        heightHistogram[2] = halfTotal;
      }
      if ((int)(heightHistogram[2] << 1) < (int)heightHistogram[0]) {
        heightHistogram[2] = heightHistogram[2] + 1;
      }
      if ((int)heightHistogram[2] < scheduler[10]) {
        scheduler[10] = heightHistogram[2];
      }
    }
  }
  priorityThreshold = (**(code **)(*(int *)scheduler[2] + 0x58))((int *)scheduler[2],heightHistogram[0],maxDepth,targetDepth);
  scheduler[8] = priorityThreshold;
  if (priorityThreshold == 0) {
    if ((hasDeepFetch) && (priorityThreshold = allocation[2], priorityThreshold != 0)) {
      nodeIndex = 0;
      nodeCount = 0;
      do {
        if ((*(uint *)((int)usedFetchSlots + (nodeIndex >> 3 & 0x1ffffffc) + 8) >> (nodeIndex & 0x1f) & 1) != 0)
        {
          nodeCount = nodeCount + 1;
        }
        nodeIndex = nodeIndex + 1;
        priorityThreshold = priorityThreshold + -1;
      } while (priorityThreshold != 0);
      if (6 < nodeCount) goto LAB_00167a04;
    }
    minPriority = scheduler[10];
    if (minPriority < 0x400) {
      minPriority = 0x400;
    }
  }
  else {
LAB_00167a04:
    minPriority = scheduler[10];
    if (minPriority < 1) {
      minPriority = 1;
    }
  }
  scheduler[10] = minPriority;
LAB_00167a18:
  if (usedFetchSlots != (int *)0x0) {
    Arena__free(*allocation,allocation);
  }
  return Arena__free(*(undefined4 *)(*scheduler + 0x378),descendantMasks);
}

/* SchedNode__getLastConsumerCycle @ 0x167a74 (244 bytes) */
int SchedNode__getLastConsumerCycle(node, component)
  int node;
  int component;
{
  uint uVar1;
  int *piVar2;
  int edge;
  uint uVar4;
  int latestCycle;
  uint loopIndex;
  uint *successorEdges;
  
  loopIndex = 0;
  successorEdges = *(uint **)(node + 0x40);
  latestCycle = *(int *)(node + 0x2c);
  uVar4 = successorEdges[1];
  if (0 < (int)uVar4) {
    while( true ) {
      if (loopIndex < *successorEdges) {
        uVar1 = successorEdges[1];
        if (uVar1 <= loopIndex) {
          _memset(uVar1 * 4 + successorEdges[2],0,(loopIndex - uVar1) * 4 + 4);
          successorEdges[1] = loopIndex + 1;
        }
        piVar2 = (int *)(loopIndex * 4 + successorEdges[2]);
      }
      else {
        piVar2 = (int *)Vector__elementRefGrow(successorEdges,loopIndex);
      }
      loopIndex = loopIndex + 1;
      edge = *piVar2;
      if (((*(int *)(edge + 8) == 0) && (*(char *)(component + edge + 0x18) != '\0')) &&
         (edge = *(int *)(*(int *)(edge + 4) + 0x2c), latestCycle < edge)) {
        latestCycle = edge;
      }
      if (uVar4 == loopIndex) break;
      successorEdges = *(uint **)(node + 0x40);
    }
  }
  return latestCycle;
}

/* Scheduler__findFreeTempRegister @ 0x167b68 (692 bytes) */
int Scheduler__findFreeTempRegister(scheduler, registerFile, componentMask)
  int *scheduler;
  int registerFile;
  undefined4 componentMask;
{
  int wasteCount;
  int componentIndex;
  bool componentFree;
  unsigned int ghidra_home[8] = { scheduler, registerFile, componentMask, 0, 0, 0, 0, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  bool isLiveOut;
  char requestedByte;
  int *hwLimits;
  uint firstReg;
  uint endReg;
  int writerNode;
  int componentNumber;
  int bestWaste;
  int highWater;
  uint bestReg;
  char *requestedMaskCursor;
  int regByteOffset;
  uint reg;
  int componentsLeft;
  uint busyMask [7];
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = componentMask;
  if (registerFile != 1) {
    firstReg = 0;
    hwLimits = *(int **)(*scheduler + 0x30c);
    endReg = (**(code **)(*hwLimits + 0x138))(hwLimits,*scheduler);
    highWater = scheduler[0x66];
  }
  else {
    hwLimits = *(int **)(*scheduler + 0x30c);
    firstReg = (**(code **)(*hwLimits + 0x138))(hwLimits,*scheduler);
    endReg = scheduler[0x51];
    highWater = firstReg + scheduler[0x67];
  }
  bestReg = 0xffffffff;
  if ((int)firstReg < (int)endReg) {
    regByteOffset = firstReg << 2;
    bestWaste = 4;
    reg = firstReg;
    do {
      isLiveOut = (*(uint *)((reg >> 3 & 0x1ffffffc) + scheduler[0x4c] + 8) >> (reg & 0x1f) & 1) !=
              0;
      if ((isLiveOut) && (highWater < (int)reg)) {
        if ((int)bestReg < 0) {
          bestReg = reg;
        }
        break;
      }
      busyMask[0] = 0;
      componentNumber = 0;
      componentsLeft = 4;
      hwLimits = scheduler;
      do {
        writerNode = *(int *)(hwLimits[0x4d] + regByteOffset);
        if (((writerNode != 0) && (0 < *(int *)(componentNumber * 4 + writerNode + 0x48))) &&
           (*(uint **)(writerNode + 0x60) != (uint *)0x0)) {
          busyMask[0] = busyMask[0] | **(uint **)(writerNode + 0x60);
        }
        componentNumber = componentNumber + 1;
        hwLimits = hwLimits + 1;
        componentsLeft = componentsLeft + -1;
      } while (componentsLeft != 0);
      if (isLiveOut) {
        componentIndex = 0;
        wasteCount = 0;
        requestedMaskCursor = (char *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
        hwLimits = scheduler;
        do {
          if ((*(char *)((int)busyMask + componentIndex) == '\0') &&
             ((*(int *)(hwLimits[0x4d] + regByteOffset) == 0 ||
              (*(int *)(componentIndex * 4 + *(int *)(hwLimits[0x4d] + regByteOffset) + 0x48) < 1)))) {
            requestedByte = *requestedMaskCursor;
            if (requestedByte == '\0') {
              wasteCount = wasteCount + 1;
            }
LAB_00167d14:
            if (((requestedByte != '\0') && (writerNode = *(int *)(scheduler[1] + 0x38), writerNode != 0)) &&
               ((*(uint *)(writerNode + 0x94) == reg &&
                ((((writerNode = FUN_000f313c(writerNode,componentIndex), writerNode != 0 &&
                   (writerNode = *(int *)(hwLimits[0x4d] + regByteOffset), writerNode != 0)) &&
                  (*(int *)(writerNode + 0x38) == *(int *)(scheduler[1] + 0x38))) &&
                 (writerNode = ((int (*)())SchedNode__getLastConsumerCycle)(writerNode,componentIndex), writerNode == scheduler[0xb])))))) goto LAB_00167cf0;
            componentFree = true;
          }
          else {
            requestedByte = '\0';
            if (*requestedMaskCursor == '\0') goto LAB_00167d14;
LAB_00167cf0:
            componentFree = false;
          }
          componentIndex = componentIndex + 1;
          if (!componentFree) goto LAB_00167db4;
          requestedMaskCursor = requestedMaskCursor + 1;
          hwLimits = hwLimits + 1;
        } while (componentIndex != 4);
        if (((int)bestReg < 0) || (wasteCount < bestWaste)) {
          bestWaste = wasteCount;
          bestReg = reg;
        }
      }
LAB_00167db4:
      reg = reg + 1;
      regByteOffset = regByteOffset + 4;
    } while (reg != endReg);
  }
  if (registerFile != 1) {
    highWater = scheduler[0x66];
    if (scheduler[0x66] < (int)(bestReg - firstReg)) {
      highWater = bestReg - firstReg;
    }
    scheduler[0x66] = highWater;
  }
  else {
    highWater = scheduler[0x67];
    if (scheduler[0x67] < (int)(bestReg - firstReg)) {
      highWater = bestReg - firstReg;
    }
    scheduler[0x67] = highWater;
  }
  return bestReg;
}

/* Scheduler__createCopyNode @ 0x167e1c (216 bytes) */
int Scheduler__createCopyNode(scheduler, sourceInst, writeMask, readyCycle, priorityRecord)
  int *scheduler;
  int sourceInst;
  undefined4 writeMask;
  undefined4 readyCycle;
  undefined4 priorityRecord;
{
  uint uVar1;
  int inst;
  undefined4 callResult;
  int iVar4;
  undefined4 local_28 [2];
  
  iVar4 = *(int *)(*scheduler + 0x6c4);
  inst = IRInst__create(0x31,*scheduler);
  *(undefined4 *)(inst + 0x98) = 0;
  *(undefined4 *)(inst + 0x94) = *(undefined4 *)(inst + 0x14c);
  *(undefined4 *)(inst + 0x9c) = writeMask;
  IRInst__setOperandSource(inst,1,sourceInst,0,*scheduler);
  WriteMask__fromSelectWord(local_28,writeMask);
  uVar1 = *(uint *)(sourceInst + 0x14);
  *(undefined4 *)(inst + 0xc) = local_28[0];
  if ((uVar1 & 0x20) == 0) {
    *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) & 0xffffffdf;
  }
  else {
    *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) | 0x20;
  }
  IRInst__clearSourceSelectsOfUnwrittenComponents(inst);
  *(int *)(iVar4 + 0x23c) = *(int *)(iVar4 + 0x23c) + 1;
  callResult = ((int (*)())Scheduler__createNode)(scheduler,inst,priorityRecord,readyCycle);
  return callResult;
}

/* Scheduler__insertOperandCopy @ 0x167ef4 (1396 bytes) */
int Scheduler__insertOperandCopy(scheduler, node)
  int *scheduler;
  int node;
{
  int sourceRegId;
  int isMix;
  undefined4 sourceDef2;
  int operandRecord3;
  int loopIndex;
  int copyNode;
  int *operandVReg;
  undefined4 uVar3;
  int operandRecord;
  int operandCount;
  int fileBase0;
  int fileBase1;
  uint in_r9;
  uint operandBlock;
  int *inst;
  int compiler;
  int *target;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 readMaskOut [3];
  
  inst = *(int **)(node + 0x38);
  copyNode = (**(code **)(*inst + 0x14))(inst,node);
  if ((copyNode < 3) || (*(int *)(inst[0x22] + 8) == 0x14)) goto LAB_00168120;
  copyNode = IRInst__getOperandSource(inst,1);
  if (*(int *)(copyNode + 0x98) != 0) {
    operandVReg = (int *)IRInst__getOperandSource(inst,1);
    copyNode = (**(code **)(*operandVReg + 0x60))(operandVReg);
    if (copyNode == 0) goto LAB_00168120;
    sourceDef2 = IRInst__getOperandSource(inst,1);
    copyNode = IRInst__getOperandSource(sourceDef2,1);
    if (*(int *)(copyNode + 0x98) != 0) goto LAB_00168120;
  }
  copyNode = IRInst__getOperandSource(inst,2);
  if (*(int *)(copyNode + 0x98) != 0) {
    operandVReg = (int *)IRInst__getOperandSource(inst,2);
    copyNode = (**(code **)(*operandVReg + 0x60))(operandVReg);
    if (copyNode == 0) goto LAB_00168120;
    sourceDef2 = IRInst__getOperandSource(inst,2);
    copyNode = IRInst__getOperandSource(sourceDef2,1);
    if (*(int *)(copyNode + 0x98) != 0) goto LAB_00168120;
  }
  copyNode = IRInst__getOperandSource(inst,3);
  if (*(int *)(copyNode + 0x98) != 0) {
    operandVReg = (int *)IRInst__getOperandSource(inst,3);
    copyNode = (**(code **)(*operandVReg + 0x60))(operandVReg);
    if (copyNode != 0) {
      sourceDef2 = IRInst__getOperandSource(inst,3);
      copyNode = IRInst__getOperandSource(sourceDef2,1);
      if (*(int *)(copyNode + 0x98) == 0) goto LAB_00168060;
    }
LAB_00168120:
    copyNode = -1;
    for (loopIndex = 1; operandCount = (**(code **)(*inst + 0x14))(inst), loopIndex <= operandCount; loopIndex = loopIndex + 1) {
      operandVReg = (int *)IRInst__getOperandSource(inst,loopIndex);
      operandCount = (**(code **)(*operandVReg + 0x60))(operandVReg);
      if (operandCount != 0) {
        operandVReg = (int *)IRInst__getOperandSource(operandVReg,1);
      }
      if (operandVReg[0x26] == 1) {
        operandCount = operandVReg[0x25];
        if ((operandVReg[5] & 0x40U) == 0) {
          compiler = *scheduler;
          target = *(int **)(compiler + 0x30c);
          fileBase0 = (**(code **)(*target + 0x138))(target,compiler);
          fileBase1 = (**(code **)(*target + 0x140))(target,compiler);
          compiler = (**(code **)(*target + 0x13c))(target,compiler);
          operandCount = operandCount + fileBase0 + fileBase1 + compiler;
        }
        if (copyNode < 0) {
          copyNode = operandCount;
        }
        if (((*(int *)(operandVReg[0x22] + 8) != 0x8e) || ((operandVReg[5] & 0x40U) != 0)) &&
           ((operandVReg[0x56] == scheduler[4] ||
            (*(int *)(scheduler[1] + 0x474) == *(int *)(operandVReg[0x56] + 0x118))))) {
          copyNode = operandCount;
        }
      }
    }
    loopIndex = 1;
    do {
      operandCount = (**(code **)(*inst + 0x14))(inst);
      if (operandCount < loopIndex) {
        return 0;
      }
      operandVReg = (int *)IRInst__getOperandSource(inst,loopIndex);
      isMix = (**(code **)(*operandVReg + 0x60))(operandVReg);
      if (isMix != 0) {
        operandVReg = (int *)IRInst__getOperandSource(operandVReg,1);
      }
      if (operandVReg[0x26] == 1) {
        sourceRegId = operandVReg[0x25];
        if ((operandVReg[5] & 0x40U) == 0) {
          compiler = *scheduler;
          target = *(int **)(compiler + 0x30c);
          fileBase0 = (**(code **)(*target + 0x138))(target,compiler);
          fileBase1 = (**(code **)(*target + 0x140))(target,compiler);
          compiler = (**(code **)(*target + 0x13c))(target,compiler);
          sourceRegId = sourceRegId + fileBase0 + fileBase1 + compiler;
        }
        if (sourceRegId != copyNode) {
          if (((*(int *)(operandVReg[0x22] + 8) != 0x8e) || ((operandVReg[5] & 0x40U) != 0)) &&
             ((operandBlock = operandVReg[0x56], operandBlock == scheduler[4] ||
              (operandBlock = *(uint *)(operandBlock + 0x118), *(uint *)(scheduler[1] + 0x474) == operandBlock)))) {
            copyNode = IRInst__getOperandRecord(inst,loopIndex);
            FUN_000f32cc(&local_40,*(undefined4 *)(copyNode + 0x10));
            sourceDef2 = IRInst__getOperandSource(inst,loopIndex);
            copyNode = ((int (*)())Scheduler__createCopyNode)(scheduler,sourceDef2,local_40,scheduler[0xb],node + 0xc);
            IRInst__setOperandSource(inst,loopIndex,*(undefined4 *)(copyNode + 0x38),0,*scheduler);
            operandRecord3 = IRInst__getOperandRecord(inst,loopIndex);
            SelectWord__readMask(readMaskOut,*(undefined4 *)(operandRecord3 + 0x10));
            ((int (*)())Scheduler__addDataDependencyEdge)(scheduler,copyNode,node,loopIndex,0,readMaskOut[0],operandBlock);
            DList__unlink(node);
            return copyNode;
          }
          operandVReg[0x26] = 0;
        }
      }
      loopIndex = loopIndex + 1;
    } while( true );
  }
LAB_00168060:
  sourceDef2 = IRInst__getOperandSource(inst,1);
  copyNode = IRInst__getOperandRecord(inst,1);
  FUN_000f32cc(&local_48,*(undefined4 *)(copyNode + 0x10));
  copyNode = ((int (*)())Scheduler__createCopyNode)(scheduler,sourceDef2,local_48,scheduler[0xb],node + 0xc);
  IRInst__setOperandSource(inst,1,*(undefined4 *)(copyNode + 0x38),0,*scheduler);
  operandRecord = IRInst__getOperandRecord(inst,1);
  SelectWord__readMask(&local_44,*(undefined4 *)(operandRecord + 0x10));
  ((int (*)())Scheduler__addDataDependencyEdge)(scheduler,copyNode,node,1,0,local_44,in_r9);
  uVar3 = *(undefined4 *)(*(int *)(copyNode + 0x38) + 0x94);
  operandRecord = IRInst__getOperandRecord(*(int *)(copyNode + 0x38),0);
  *(undefined4 *)(operandRecord + 8) = uVar3;
  *(undefined4 *)(operandRecord + 0xc) = 1;
  *(undefined4 *)(copyNode + 100) = 1;
  DList__unlink(node);
  return copyNode;
}

/* Scheduler__addOperandDependencyEdges @ 0x168468 (2328 bytes) */
int Scheduler__addOperandDependencyEdges(scheduler, consumerNode, inst, operandIndex, subOperandIndex)
  int *scheduler;
  int consumerNode;
  int *inst;
  int operandIndex;
  int subOperandIndex;
{
  undefined4 arena;
  uint remainingLanes;
  uint vectorCount2;
  undefined4 *singleEdgeAlloc;
  undefined4 *edgeListCursor;
  uint *writerAPredEdges;
  uint *writerBSuccEdges;
  uint *consumerPredEdges;
  uint *producerSuccEdges;
  int *edgeB;
  int *edgeListSlot;
  int *appendSlot2;
  int *appendSlot;
  int *maskSource;
  int edgeCount;
  int isMix;
  int partialWriterB;
  int partialWriterA;
  int operandRecord;
  int *operandVReg2;
  int *operandVReg;
  bool hasSubOperand;
  bool producerInBlock;
  int *edgeA;
  int producerNode;
  int effectiveOperandIndex;
  undefined4 *maskCursor;
  int *producerSlot;
  undefined4 operandVReg3;
  undefined4 *edgeAlloc;
  int *currentSource;
  int isPresub;
  uint vectorCount;
  undefined4 *edge;
  undefined4 *appendSlot3;
  int numSources;
  int isExternalProducer;
  uint producerIndex;
  undefined4 uVar18;
  uint *allNodes;
  undefined4 local_88;
  undefined4 coveredLanes;
  undefined4 edgeList [6];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  uint local_58 [4];
  
  hasSubOperand = 0 < subOperandIndex;
  if (hasSubOperand) {
    operandVReg = (int *)IRInst__getOperandSource(inst,subOperandIndex);
    effectiveOperandIndex = subOperandIndex;
  }
  else {
    operandVReg = (int *)IRInst__getOperandSource(inst,operandIndex);
    effectiveOperandIndex = operandIndex;
  }
  if ((operandVReg[0x56] == scheduler[4]) && (producerNode = ((int (*)())IRInst__needsNoSchedulerNode)(operandVReg), producerNode == 0)) {
    allNodes = (uint *)scheduler[6];
    producerIndex = operandVReg[0x54];
    if (producerIndex < *allNodes) {
      vectorCount = allNodes[1];
      if (vectorCount <= producerIndex) {
        _memset(vectorCount * 4 + allNodes[2],0,(producerIndex - vectorCount) * 4 + 4);
        allNodes[1] = producerIndex + 1;
      }
      producerSlot = (int *)(producerIndex * 4 + allNodes[2]);
    }
    else {
      producerSlot = (int *)Vector__elementRefGrow(allNodes,producerIndex);
    }
    producerNode = *producerSlot;
    isExternalProducer = 0;
  }
  else {
    producerNode = ((int (*)())Scheduler__findOrCreateExternalNode)(scheduler,operandVReg);
    isExternalProducer = 1;
  }
  if (((inst[5] & 0x200U) == 0) || (effectiveOperandIndex != inst[0x21])) {
    numSources = (**(code **)(*inst + 0x14))(inst);
    if (effectiveOperandIndex <= numSources) {
      operandRecord = IRInst__getOperandRecord(inst,effectiveOperandIndex);
      uVar18 = *(undefined4 *)(operandRecord + 0x10);
      if (hasSubOperand) {
        operandRecord = IRInst__getOperandRecord(*(undefined4 *)(consumerNode + 0x38),operandIndex);
        SelectWord__readMask(&local_68,*(undefined4 *)(operandRecord + 0x10));
        operandVReg2 = (int *)IRInst__getOperandSource(*(undefined4 *)(consumerNode + 0x38),operandIndex);
        if (inst != operandVReg2) {
          operandVReg2 = (int *)IRInst__getOperandSource(*(undefined4 *)(consumerNode + 0x38),operandIndex);
          isMix = (**(code **)(*operandVReg2 + 0x60))(operandVReg2);
          if (isMix != 0) {
            operandVReg3 = IRInst__getOperandSource(*(undefined4 *)(consumerNode + 0x38),operandIndex);
            IRInst__getOperandSource(operandVReg3,1);
          }
          operandVReg3 = IRInst__getOperandSource(*(undefined4 *)(consumerNode + 0x38),operandIndex);
          operandRecord = IRInst__getOperandRecord(operandVReg3,1);
          SelectWord__maskUnused(&local_64,*(undefined4 *)(operandRecord + 0x10),local_68);
          SelectWord__readMask(&local_60,local_64);
          local_68 = local_60;
        }
        SelectWord__maskUnused(&local_5c,uVar18,local_68);
        uVar18 = local_5c;
      }
      SelectWord__readMask(local_58,uVar18);
      producerInBlock = isExternalProducer == 0;
      local_88 = local_58[0];
      edgeCount = 0;
      maskCursor = &local_88;
LAB_00168844:
      edgeListSlot = maskCursor + 2;
      do {
        coveredLanes = operandVReg[3] & local_88;
        if ((operandVReg[3] & local_88) != 0) {
          arena = *(undefined4 *)(*scheduler + 0x378);
          edgeAlloc = (undefined4 *)Arena__alloc(arena,0x24);
          edge = edgeAlloc + 1;
          *edgeAlloc = arena;
          edgeAlloc[1] = producerNode;
          edgeAlloc[4] = 1;
          edgeAlloc[7] = 0x1010101;
          edgeAlloc[3] = 0;
          edgeAlloc[5] = 0;
          edgeAlloc[6] = 0;
          edgeAlloc[8] = 0;
          edgeAlloc[2] = consumerNode;
          uVar18 = ((int (*)())Scheduler__getDependencyLatency)(scheduler,operandVReg,inst,0,operandIndex,0);
          edgeAlloc[4] = uVar18;
          edgeAlloc[5] = operandIndex;
          edgeAlloc[6] = subOperandIndex;
          edgeAlloc[7] = coveredLanes;
          if (((edgeCount == 0) && (currentSource = (int *)IRInst__getOperandSource(inst,effectiveOperandIndex), operandVReg != currentSource))
             && ((isPresub = (**(code **)(*inst + 0x5c))(inst), isPresub == 0 || (!hasSubOperand)))) {
            IRInst__setOperandSource(inst,effectiveOperandIndex,operandVReg,0,*scheduler);
          }
          if ((*(uint *)(*(int *)(consumerNode + 0x38) + 0x14) & 0x8000) == 0) {
            isPresub = (**(code **)(*operandVReg + 0x54))(operandVReg);
            maskSource = operandVReg;
            if ((isPresub != 0) && (operandVReg[0x21] != 0)) {
              maskSource = (int *)IRInst__getOperandSource(operandVReg,1);
            }
            uVar18 = (**(code **)(*(int *)scheduler[3] + 0x20))((int *)scheduler[3],maskSource);
            edgeAlloc[8] = uVar18;
          }
          producerSuccEdges = *(uint **)(producerNode + 0x40);
          vectorCount2 = producerSuccEdges[1];
          if (vectorCount2 < *producerSuccEdges) {
            _memset(vectorCount2 * 4 + producerSuccEdges[2],0,4);
            appendSlot = (int *)(vectorCount2 * 4 + producerSuccEdges[2]);
            producerSuccEdges[1] = vectorCount2 + 1;
          }
          else {
            appendSlot = (int *)Vector__elementRefGrow(producerSuccEdges,vectorCount2);
          }
          *appendSlot = (int)edge;
          consumerPredEdges = *(uint **)(consumerNode + 0x44);
          vectorCount2 = consumerPredEdges[1];
          if (vectorCount2 < *consumerPredEdges) {
            _memset(vectorCount2 * 4 + consumerPredEdges[2],0,4);
            appendSlot = (int *)(vectorCount2 * 4 + consumerPredEdges[2]);
            consumerPredEdges[1] = vectorCount2 + 1;
          }
          else {
            appendSlot = (int *)Vector__elementRefGrow(consumerPredEdges,vectorCount2);
          }
          *appendSlot = (int)edge;
          edgeCount = edgeCount + 1;
          *edgeListSlot = (int)edge;
          maskCursor = maskCursor + 1;
          edgeListSlot = edgeListSlot + 1;
        }
        if (producerInBlock) {
          remainingLanes = ((uint)*(byte *)((int)&local_88 + isExternalProducer + 3) << 0x18 |
                    (uint)*(byte *)((int)&local_88 + isExternalProducer + 2) << 0x10 |
                    (uint)*(byte *)((int)&local_88 + isExternalProducer + 1) << 8 |
                   (uint)*(byte *)(isExternalProducer + (int)&local_88)) -
                   ((uint)*(byte *)((int)edgeList + isExternalProducer + -1) << 0x18 |
                    (uint)*(byte *)((int)edgeList + isExternalProducer + -2) << 0x10 |
                    (uint)*(byte *)((int)edgeList + isExternalProducer + -3) << 8 |
                   (uint)*(byte *)((int)edgeList + isExternalProducer + -4));
          local_88 = remainingLanes * 0x1000000 | (remainingLanes & 0xff00) << 8 | remainingLanes >> 8 & 0xff00 |
                     remainingLanes >> 0x18;
        }
        else {
          local_88 = 0;
        }
        if ((local_88 == 0) || ((operandVReg[5] & 0x200U) == 0)) {
LAB_00168ab0:
          if (edgeCount < 1) {
            return;
          }
          effectiveOperandIndex = 0;
          edgeListCursor = edgeList;
          do {
            effectiveOperandIndex = effectiveOperandIndex + 1;
            if (effectiveOperandIndex < edgeCount) {
              edgeA = (int *)*edgeListCursor;
              edgeAlloc = edgeList + effectiveOperandIndex;
              producerNode = 0;
              do {
                edgeB = (int *)*edgeAlloc;
                if ((*(uint *)(*(int *)(*edgeA + 0x38) + 0xc) &
                    *(uint *)(*(int *)(*edgeB + 0x38) + 0xc)) != 0) {
                  arena = *(undefined4 *)(*scheduler + 0x378);
                  edge = (undefined4 *)Arena__alloc(arena,0x24);
                  *edge = arena;
                  edge[1] = 0;
                  partialWriterB = *edgeB;
                  edge[1] = partialWriterB;
                  partialWriterA = *edgeA;
                  edge[4] = 1;
                  edge[7] = 0x1010101;
                  edge[3] = 3;
                  edge[2] = partialWriterA;
                  edge[5] = 0;
                  edge[6] = 0;
                  edge[8] = 0;
                  uVar18 = ((int (*)())Scheduler__getDependencyLatency)(scheduler,*(undefined4 *)(partialWriterB + 0x38),
                                        *(undefined4 *)(partialWriterA + 0x38),0,0,3);
                  partialWriterB = *edgeB;
                  partialWriterA = *edgeA;
                  edge[4] = uVar18;
                  edge[7] = *(uint *)(*(int *)(partialWriterA + 0x38) + 0xc) &
                               *(uint *)(*(int *)(partialWriterB + 0x38) + 0xc);
                  writerBSuccEdges = *(uint **)(edge[1] + 0x40);
                  vectorCount2 = writerBSuccEdges[1];
                  if (vectorCount2 < *writerBSuccEdges) {
                    _memset(vectorCount2 * 4 + writerBSuccEdges[2],0,4);
                    appendSlot3 = (undefined4 *)(vectorCount2 * 4 + writerBSuccEdges[2]);
                    writerBSuccEdges[1] = vectorCount2 + 1;
                  }
                  else {
                    appendSlot3 = (undefined4 *)Vector__elementRefGrow(writerBSuccEdges,vectorCount2);
                  }
                  *appendSlot3 = edge + 1;
                  writerAPredEdges = *(uint **)(edge[2] + 0x44);
                  vectorCount2 = writerAPredEdges[1];
                  if (vectorCount2 < *writerAPredEdges) {
                    _memset(vectorCount2 * 4 + writerAPredEdges[2],0,4);
                    appendSlot3 = (undefined4 *)(vectorCount2 * 4 + writerAPredEdges[2]);
                    writerAPredEdges[1] = vectorCount2 + 1;
                  }
                  else {
                    appendSlot3 = (undefined4 *)Vector__elementRefGrow(writerAPredEdges,vectorCount2);
                  }
                  *appendSlot3 = edge + 1;
                }
                producerNode = producerNode + 1;
                edgeAlloc = edgeAlloc + 1;
              } while (edgeCount - effectiveOperandIndex != producerNode);
            }
            edgeListCursor = edgeListCursor + 1;
          } while (effectiveOperandIndex != edgeCount);
          return;
        }
        currentSource = (int *)IRInst__getOperandSource(operandVReg,operandVReg[0x21]);
        producerNode = (**(code **)(*currentSource + 0x50))(currentSource);
        if (producerNode != 0) goto LAB_00168ab0;
        operandVReg = (int *)IRInst__getOperandSource(operandVReg,operandVReg[0x21]);
        if ((operandVReg[0x56] == scheduler[4]) && (producerNode = ((int (*)())IRInst__needsNoSchedulerNode)(operandVReg), producerNode == 0))
        goto LAB_00168b48;
        isExternalProducer = 1;
        producerInBlock = false;
        producerNode = ((int (*)())Scheduler__findOrCreateExternalNode)(scheduler,operandVReg);
      } while( true );
    }
    arena = *(undefined4 *)(*scheduler + 0x378);
    singleEdgeAlloc = (undefined4 *)Arena__alloc(arena,0x24);
    *singleEdgeAlloc = arena;
    singleEdgeAlloc[4] = 1;
    singleEdgeAlloc[1] = producerNode;
    singleEdgeAlloc[7] = 0x1010101;
    singleEdgeAlloc[3] = 0;
    singleEdgeAlloc[5] = 0;
    singleEdgeAlloc[6] = 0;
    singleEdgeAlloc[8] = 0;
    singleEdgeAlloc[2] = consumerNode;
    uVar18 = ((int (*)())Scheduler__getDependencyLatency)(scheduler,operandVReg,inst,0,operandIndex,0);
    singleEdgeAlloc[5] = operandIndex;
    singleEdgeAlloc[4] = uVar18;
    singleEdgeAlloc[6] = subOperandIndex;
    singleEdgeAlloc[7] = operandVReg[3];
  }
  else {
    IRInst__getOperandSource(inst,effectiveOperandIndex);
    effectiveOperandIndex = Compiler__isOptionEnabled(*scheduler,0x26);
    if (((effectiveOperandIndex != 0) && (effectiveOperandIndex = Compiler__isOptionEnabled(*scheduler,0x25), effectiveOperandIndex != 0)) &&
       ((inst[5] & 0x20U) == 0)) {
      return;
    }
    arena = *(undefined4 *)(*scheduler + 0x378);
    singleEdgeAlloc = (undefined4 *)Arena__alloc(arena,0x24);
    *singleEdgeAlloc = arena;
    singleEdgeAlloc[4] = 1;
    singleEdgeAlloc[1] = producerNode;
    singleEdgeAlloc[3] = 3;
    singleEdgeAlloc[7] = 0x1010101;
    singleEdgeAlloc[8] = 0;
    singleEdgeAlloc[5] = 0;
    singleEdgeAlloc[6] = 0;
    singleEdgeAlloc[2] = consumerNode;
    uVar18 = ((int (*)())Scheduler__getDependencyLatency)(scheduler,operandVReg,inst,0,0,3);
    singleEdgeAlloc[4] = uVar18;
    singleEdgeAlloc[7] = inst[3];
  }
  producerSuccEdges = *(uint **)(producerNode + 0x40);
  vectorCount2 = producerSuccEdges[1];
  if (vectorCount2 < *producerSuccEdges) {
    _memset(vectorCount2 * 4 + producerSuccEdges[2],0,4);
    appendSlot2 = (int *)(vectorCount2 * 4 + producerSuccEdges[2]);
    producerSuccEdges[1] = vectorCount2 + 1;
  }
  else {
    appendSlot2 = (int *)Vector__elementRefGrow(producerSuccEdges,vectorCount2);
  }
  *appendSlot2 = (int)(singleEdgeAlloc + 1);
  consumerPredEdges = *(uint **)(consumerNode + 0x44);
  vectorCount2 = consumerPredEdges[1];
  if (vectorCount2 < *consumerPredEdges) {
    _memset(vectorCount2 * 4 + consumerPredEdges[2],0,4);
    appendSlot2 = (int *)(vectorCount2 * 4 + consumerPredEdges[2]);
    consumerPredEdges[1] = vectorCount2 + 1;
  }
  else {
    appendSlot2 = (int *)Vector__elementRefGrow(consumerPredEdges,vectorCount2);
  }
  *appendSlot2 = (int)(singleEdgeAlloc + 1);
  return;
LAB_00168b48:
  allNodes = (uint *)scheduler[6];
  producerIndex = operandVReg[0x54];
  if (producerIndex < *allNodes) {
    vectorCount = allNodes[1];
    if (vectorCount <= producerIndex) {
      _memset(vectorCount * 4 + allNodes[2],0,(producerIndex - vectorCount) * 4 + 4);
      allNodes[1] = producerIndex + 1;
    }
    producerSlot = (int *)(producerIndex * 4 + allNodes[2]);
  }
  else {
    producerSlot = (int *)Vector__elementRefGrow(allNodes,producerIndex);
  }
  producerNode = *producerSlot;
  goto LAB_00168844;
}

/* Scheduler__transformDotProduct @ 0x168d80 (2668 bytes) */
int Scheduler__transformDotProduct(scheduler, node)
  int *scheduler;
  int node;
{
  int pendingPreds;
  int selectsRewritable;
  undefined4 latency;
  undefined4 edgeConst;
  undefined4 specialFlag;
  undefined4 resourceClass;
  undefined4 selectWord;
  uint *nodePredEdges;
  uint vectorCount;
  uint source1SelectWord;
  int nextLane2;
  int lane2;
  int lane;
  int balanceEnabled;
  int operandRecord;
  int operandRecord3;
  int operandRecord2;
  undefined1 laneSelect;
  undefined *selectTable;
  uint source2SelectWord;
  uint instFlags;
  int helperOpcode;
  int helperInst;
  int helperNode;
  int savedWriteMask;
  undefined4 selectConst;
  undefined4 *edgeAlloc;
  undefined4 *appendSlot;
  int savedField120;
  int savedField124;
  uint savedFlag20;
  int savedRegKind;
  int savedRegId;
  uint hasHardwareRegister;
  int savedDestSelect;
  int *resultInst;
  undefined1 *source1SelectCursor;
  undefined1 *source2SelectCursor;
  undefined4 arena;
  int nextLane;
  uint *helperSuccEdges;
  int *inst;
  undefined4 *edgeRecord;
  int outCount;
  int outSelector;
  undefined4 source1Select;
  undefined4 source2Select;
  int extraSource;
  uint source2Abs;
  uint source1Abs;
  uint source2Negate;
  uint source1Negate;
  undefined4 source2Def;
  undefined4 source1Def;
  
  inst = *(int **)(node + 0x38);
  helperInst = (**(code **)(*(int *)scheduler[2] + 0x40))((int *)scheduler[2],inst,&outCount,&outSelector);
  if (helperInst == 0) {
    return 0;
  }
  scheduler[0x6a] = scheduler[0x6a] + 1;
  helperNode = ((int (*)())Scheduler__createNode)(scheduler,helperInst,node + 0xc,*(undefined4 *)(node + 0x30));
  source1Def = IRInst__getOperandSource(inst,1);
  source2Def = IRInst__getOperandSource(inst,2);
  operandRecord = IRInst__getOperandRecord(inst,1);
  source1Select = *(uint *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(inst,2);
  source2Select = *(uint *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(inst,0);
  instFlags = inst[5];
  source1Negate = inst[0x2e] & 1;
  source1Abs = (uint)inst[0x2e] >> 1 & 1;
  source2Negate = inst[0x34] & 1;
  source2Abs = (uint)inst[0x34] >> 1 & 1;
  savedDestSelect = *(int *)(operandRecord + 0x10);
  hasHardwareRegister = instFlags >> 1 & 1;
  savedFlag20 = instFlags >> 5 & 1;
  savedRegKind = inst[0x26];
  savedRegId = inst[0x25];
  savedField120 = inst[0x48];
  savedField124 = inst[0x49];
  savedWriteMask = inst[3];
  extraSource = 0;
  if ((instFlags & 0x200) != 0) {
    extraSource = IRInst__getOperandSource(inst,inst[0x21]);
  }
  helperOpcode = *(int *)(*(int *)(helperInst + 0x88) + 8);
  resultInst = inst;
  if (helperOpcode == 0x13) {
    SchedModel__uncountNode(scheduler[2],node);
    if (*(int *)(inst[0x22] + 8) == 0x1c) {
      IRInst__reinitAsTrinary(inst,0x1e,*scheduler);
      IRInst__setOperandSource(inst,3,helperInst,0,*scheduler);
      selectConst = DAT_001b01a0;
      operandRecord3 = IRInst__getOperandRecord(inst,3);
      *(undefined4 *)(operandRecord3 + 0x10) = selectConst;
      (**(code **)(*inst + 0x88))(inst,3,2,outSelector);
      source1SelectWord = source1Select;
      operandRecord3 = IRInst__getOperandRecord(inst,1);
      source2SelectWord = source2Select;
      *(uint *)(operandRecord3 + 0x10) = source1SelectWord;
      operandRecord3 = IRInst__getOperandRecord(inst,2);
      *(uint *)(operandRecord3 + 0x10) = source2SelectWord;
      if (outCount < 2) {
        source1SelectCursor = (undefined1 *)((int)&source1Select + outCount + 1);
        source2SelectCursor = (undefined1 *)((int)&source2Select + outCount + 1);
        lane = outCount;
        do {
          nextLane = lane + 1;
          laneSelect = *source1SelectCursor;
          source1SelectCursor = source1SelectCursor + 1;
          (**(code **)(*inst + 0x88))(inst,1,lane,laneSelect);
          laneSelect = *source2SelectCursor;
          source2SelectCursor = source2SelectCursor + 1;
          (**(code **)(*inst + 0x88))(inst,2,lane,laneSelect);
          lane = nextLane;
        } while (nextLane != 2);
      }
      (**(code **)(*inst + 0x88))(inst,1,2,4);
      (**(code **)(*inst + 0x88))(inst,2,2,4);
    }
    else {
      resultInst = (int *)0x0;
      if (*(int *)(inst[0x22] + 8) == 0x1d) {
        IRInst__reinitAsTrinary(inst,0xa3,*scheduler);
        IRInst__setOperandSource(inst,3,helperInst,0,*scheduler);
        selectConst = DAT_001b01a0;
        operandRecord3 = IRInst__getOperandRecord(inst,3);
        *(undefined4 *)(operandRecord3 + 0x10) = selectConst;
        (**(code **)(*inst + 0x88))(inst,3,3,outSelector);
        source1SelectWord = source1Select;
        operandRecord3 = IRInst__getOperandRecord(inst,1);
        source2SelectWord = source2Select;
        *(uint *)(operandRecord3 + 0x10) = source1SelectWord;
        operandRecord3 = IRInst__getOperandRecord(inst,2);
        *(uint *)(operandRecord3 + 0x10) = source2SelectWord;
        if (outCount < 3) {
          source1SelectCursor = (undefined1 *)((int)&source1Select + outCount + 1);
          source2SelectCursor = (undefined1 *)((int)&source2Select + outCount + 1);
          lane = outCount;
          do {
            nextLane = lane + 1;
            laneSelect = *source1SelectCursor;
            source1SelectCursor = source1SelectCursor + 1;
            (**(code **)(*inst + 0x88))(inst,1,lane,laneSelect);
            laneSelect = *source2SelectCursor;
            source2SelectCursor = source2SelectCursor + 1;
            (**(code **)(*inst + 0x88))(inst,2,lane,laneSelect);
            lane = nextLane;
          } while (nextLane != 3);
        }
        (**(code **)(*inst + 0x88))(inst,1,3,4);
        (**(code **)(*inst + 0x88))(inst,2,3,4);
        resultInst = inst;
      }
    }
    if (hasHardwareRegister == 0) {
      resultInst[0x25] = savedRegId;
      resultInst[0x26] = savedRegKind;
      if (savedFlag20 == 0) {
        resultInst[5] = resultInst[5] & 0xffffffdf;
      }
      else {
        resultInst[5] = resultInst[5] | 0x20;
      }
    }
    else {
      IRInst__setHardwareRegisterAndAdd(resultInst,scheduler[1],savedRegKind,savedRegId);
    }
    resultInst[0x27] = savedDestSelect;
    resultInst[0x48] = savedField120;
    resultInst[0x49] = savedField124;
    resultInst[3] = savedWriteMask;
    IRInst__setOperandSource(resultInst,1,source1Def,0,*scheduler);
    IROperand__setModifierBits(resultInst + 0x29,2,source1Abs);
    IROperand__setModifierBits(resultInst + 0x29,1,source1Negate);
    IRInst__setOperandSource(resultInst,2,source2Def,0,*scheduler);
    IROperand__setModifierBits(resultInst + 0x2f,2,source2Abs);
    IROperand__setModifierBits(resultInst + 0x2f,1,source2Negate);
  }
  else {
    if (helperOpcode != 0x14) {
      if (helperOpcode != 0x1c) {
        return helperNode;
      }
      SchedModel__uncountNode(scheduler[2],node);
      IRInst__reinitAsTrinary(inst,0x14,*scheduler);
      if (hasHardwareRegister == 0) {
        inst[0x25] = savedRegId;
        inst[0x26] = savedRegKind;
        if (savedFlag20 == 0) {
          inst[5] = inst[5] & 0xffffffdf;
        }
        else {
          inst[5] = inst[5] | 0x20;
        }
      }
      else {
        IRInst__setHardwareRegisterAndAdd(inst,scheduler[1],savedRegKind,savedRegId);
      }
      inst[0x48] = savedField120;
      inst[0x49] = savedField124;
      inst[3] = savedWriteMask;
      IRInst__setOperandSource(inst,1,source1Def,0,*scheduler);
      IROperand__setModifierBits(inst + 0x29,2,source1Abs);
      IROperand__setModifierBits(inst + 0x29,1,source1Negate);
      IRInst__setOperandSource(inst,2,source2Def,0,*scheduler);
      IROperand__setModifierBits(inst + 0x2f,2,source2Abs);
      IROperand__setModifierBits(inst + 0x2f,1,source2Negate);
      IRInst__setOperandSource(inst,3,helperInst,0,*scheduler);
      inst[0x27] = savedDestSelect;
      selectTable = PTR_DAT_001e8b8c;
      selectWord = *(undefined4 *)(PTR_DAT_001e8b8c + (source1Select & 0xff) * 4);
      operandRecord = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord + 0x10) = selectWord;
      selectWord = *(undefined4 *)(selectTable + (source2Select & 0xff) * 4);
      operandRecord = IRInst__getOperandRecord(inst,2);
      *(undefined4 *)(operandRecord + 0x10) = selectWord;
      selectConst = UNK_001b019c;
      operandRecord = IRInst__getOperandRecord(inst,3);
      *(undefined4 *)(operandRecord + 0x10) = selectConst;
      IRInst__clearSourceSelectsOfUnwrittenComponents(inst);
      if (extraSource != 0) {
        IRInst__setExtraOperandSource(inst,extraSource,0,*scheduler);
      }
      resourceClass = (**(code **)(*(int *)scheduler[2] + 0x4c))((int *)scheduler[2],inst);
      *(undefined4 *)(node + 0x58) = resourceClass;
      balanceEnabled = Compiler__isOptionEnabled(*scheduler,0x28);
      if (balanceEnabled != 0) {
        selectsRewritable = (**(code **)(*(int *)scheduler[2] + 0x34))((int *)scheduler[2],node);
        specialFlag = 1;
        if (selectsRewritable != 0) goto code_r0x001699c4;
      }
      specialFlag = 0;
code_r0x001699c4:
      *(undefined4 *)(node + 0x5c) = specialFlag;
      (**(code **)(*(int *)scheduler[2] + 0x48))((int *)scheduler[2],node);
      SchedModel__countIssuedNode(scheduler[2],node);
      arena = *(undefined4 *)(*scheduler + 0x378);
      edgeAlloc = (undefined4 *)Arena__alloc(arena,0x24);
      edgeConst = DAT_001b0194;
      *edgeAlloc = arena;
      edgeAlloc[1] = helperNode;
      edgeAlloc[7] = edgeConst;
      edgeAlloc[3] = 0;
      edgeAlloc[4] = 1;
      edgeAlloc[5] = 0;
      edgeAlloc[6] = 0;
      edgeAlloc[8] = 0;
      edgeAlloc[2] = node;
      latency = ((int (*)())Scheduler__getDependencyLatency)(scheduler,helperInst,inst,0,3,0);
      edgeAlloc[4] = latency;
      edgeAlloc[5] = 3;
      edgeAlloc[7] = 0;
      *(undefined1 *)(edgeAlloc + 7) = 1;
      helperSuccEdges = *(uint **)(helperNode + 0x40);
      vectorCount = helperSuccEdges[1];
      if (vectorCount < *helperSuccEdges) {
        _memset(vectorCount * 4 + helperSuccEdges[2],0,4);
        inst = (int *)(vectorCount * 4 + helperSuccEdges[2]);
        helperSuccEdges[1] = vectorCount + 1;
      }
      else {
        inst = (int *)Vector__elementRefGrow(helperSuccEdges,vectorCount);
      }
      *inst = (int)(edgeAlloc + 1);
      nodePredEdges = *(uint **)(node + 0x44);
      vectorCount = nodePredEdges[1];
      if (vectorCount < *nodePredEdges) {
        _memset(vectorCount * 4 + nodePredEdges[2],0,4);
        inst = (int *)(vectorCount * 4 + nodePredEdges[2]);
        nodePredEdges[1] = vectorCount + 1;
      }
      else {
        inst = (int *)Vector__elementRefGrow(nodePredEdges,vectorCount);
      }
      *inst = (int)(edgeAlloc + 1);
      ((int (*)())Scheduler__copyFetchInEdge)(scheduler,node,helperNode);
      pendingPreds = *(int *)(node + 0x34);
      helperInst = *(int *)(node + 0x30);
      *(undefined4 *)(helperNode + 0x48) = 1;
      *(int *)(node + 0x34) = pendingPreds + 1;
      if (helperInst < scheduler[0xb] + edgeAlloc[4]) {
        helperInst = scheduler[0xb] + edgeAlloc[4];
      }
      *(int *)(node + 0x30) = helperInst;
      return helperNode;
    }
    SchedModel__uncountNode(scheduler[2],node);
    if (*(int *)(inst[0x22] + 8) == 0x1e) {
      IRInst__reinitAsTrinary(inst,0x14,*scheduler);
      inst[0x27] = savedDestSelect;
      selectTable = PTR_DAT_001e8b8c;
      selectWord = *(undefined4 *)
               (PTR_DAT_001e8b8c + (uint)*(byte *)((int)&source1Select + (1 - outCount)) * 4);
      operandRecord2 = IRInst__getOperandRecord(inst,1);
      *(undefined4 *)(operandRecord2 + 0x10) = selectWord;
      selectWord = *(undefined4 *)(selectTable + (uint)*(byte *)((int)&source2Select + (1 - outCount)) * 4);
      operandRecord2 = IRInst__getOperandRecord(inst,2);
      *(undefined4 *)(operandRecord2 + 0x10) = selectWord;
      selectWord = *(undefined4 *)(selectTable + outSelector * 4);
      operandRecord2 = IRInst__getOperandRecord(inst,3);
      *(undefined4 *)(operandRecord2 + 0x10) = selectWord;
      IRInst__clearSourceSelectsOfUnwrittenComponents(inst);
    }
    else {
      resultInst = (int *)0x0;
      if (*(int *)(inst[0x22] + 8) == 0xa3) {
        IRInst__reinitAsTrinary(inst,0x1e,*scheduler);
        source1SelectWord = source1Select;
        inst[0x27] = savedDestSelect;
        operandRecord2 = IRInst__getOperandRecord(inst,1);
        source2SelectWord = source2Select;
        *(uint *)(operandRecord2 + 0x10) = source1SelectWord;
        operandRecord2 = IRInst__getOperandRecord(inst,2);
        *(uint *)(operandRecord2 + 0x10) = source2SelectWord;
        if (outCount < 2) {
          source1SelectCursor = (undefined1 *)((int)&source1Select + outCount + 1);
          source2SelectCursor = (undefined1 *)((int)&source2Select + outCount + 1);
          lane2 = outCount;
          do {
            nextLane2 = lane2 + 1;
            laneSelect = *source1SelectCursor;
            source1SelectCursor = source1SelectCursor + 1;
            (**(code **)(*inst + 0x88))(inst,1,lane2,laneSelect);
            laneSelect = *source2SelectCursor;
            source2SelectCursor = source2SelectCursor + 1;
            (**(code **)(*inst + 0x88))(inst,2,lane2,laneSelect);
            lane2 = nextLane2;
          } while (nextLane2 != 2);
        }
        (**(code **)(*inst + 0x88))(inst,1,2,4);
        (**(code **)(*inst + 0x88))(inst,2,2,4);
        selectConst = DAT_001b01a0;
        operandRecord2 = IRInst__getOperandRecord(inst,3);
        *(undefined4 *)(operandRecord2 + 0x10) = selectConst;
        (**(code **)(*inst + 0x88))(inst,3,2,outSelector);
        resultInst = inst;
      }
    }
    if (hasHardwareRegister == 0) {
      resultInst[0x25] = savedRegId;
      resultInst[0x26] = savedRegKind;
      if (savedFlag20 == 0) {
        resultInst[5] = resultInst[5] & 0xffffffdf;
      }
      else {
        resultInst[5] = resultInst[5] | 0x20;
      }
    }
    else {
      IRInst__setHardwareRegisterAndAdd(resultInst,scheduler[1],savedRegKind,savedRegId);
    }
    resultInst[0x48] = savedField120;
    resultInst[0x49] = savedField124;
    resultInst[3] = savedWriteMask;
    IRInst__setOperandSource(resultInst,1,source1Def,0,*scheduler);
    IROperand__setModifierBits(resultInst + 0x29,2,source1Abs);
    IROperand__setModifierBits(resultInst + 0x29,1,source1Negate);
    IRInst__setOperandSource(resultInst,2,source2Def,0,*scheduler);
    IROperand__setModifierBits(resultInst + 0x2f,2,source2Abs);
    IROperand__setModifierBits(resultInst + 0x2f,1,source2Negate);
    IRInst__setOperandSource(resultInst,3,helperInst,0,*scheduler);
  }
  if (extraSource != 0) {
    IRInst__setExtraOperandSource(resultInst,extraSource,0,*scheduler);
  }
  resourceClass = (**(code **)(*(int *)scheduler[2] + 0x4c))((int *)scheduler[2],resultInst);
  *(undefined4 *)(node + 0x58) = resourceClass;
  balanceEnabled = Compiler__isOptionEnabled(*scheduler,0x28);
  if (balanceEnabled != 0) {
    selectsRewritable = (**(code **)(*(int *)scheduler[2] + 0x34))((int *)scheduler[2],node);
    specialFlag = 1;
    if (selectsRewritable != 0) goto LAB_00169620;
  }
  specialFlag = 0;
LAB_00169620:
  *(undefined4 *)(node + 0x5c) = specialFlag;
  (**(code **)(*(int *)scheduler[2] + 0x48))((int *)scheduler[2],node);
  SchedModel__countIssuedNode(scheduler[2],node);
  arena = *(undefined4 *)(*scheduler + 0x378);
  edgeAlloc = (undefined4 *)Arena__alloc(arena,0x24);
  edgeConst = DAT_001b0194;
  edgeRecord = edgeAlloc + 1;
  *edgeAlloc = arena;
  edgeAlloc[1] = helperNode;
  edgeAlloc[7] = edgeConst;
  edgeAlloc[3] = 0;
  edgeAlloc[4] = 1;
  edgeAlloc[5] = 0;
  edgeAlloc[6] = 0;
  edgeAlloc[8] = 0;
  edgeAlloc[2] = node;
  latency = ((int (*)())Scheduler__getDependencyLatency)(scheduler,helperInst,resultInst,0,3,0);
  edgeAlloc[4] = latency;
  edgeAlloc[5] = 3;
  edgeAlloc[7] = 0;
  *(undefined1 *)((int)edgeRecord + outSelector + 0x18) = 1;
  helperSuccEdges = *(uint **)(helperNode + 0x40);
  vectorCount = helperSuccEdges[1];
  if (vectorCount < *helperSuccEdges) {
    _memset(vectorCount * 4 + helperSuccEdges[2],0,4);
    appendSlot = (undefined4 *)(vectorCount * 4 + helperSuccEdges[2]);
    helperSuccEdges[1] = vectorCount + 1;
  }
  else {
    appendSlot = (undefined4 *)Vector__elementRefGrow(helperSuccEdges,vectorCount);
  }
  *appendSlot = edgeRecord;
  nodePredEdges = *(uint **)(node + 0x44);
  vectorCount = nodePredEdges[1];
  if (vectorCount < *nodePredEdges) {
    _memset(vectorCount * 4 + nodePredEdges[2],0,4);
    appendSlot = (undefined4 *)(vectorCount * 4 + nodePredEdges[2]);
    nodePredEdges[1] = vectorCount + 1;
  }
  else {
    appendSlot = (undefined4 *)Vector__elementRefGrow(nodePredEdges,vectorCount);
  }
  *appendSlot = edgeRecord;
  ((int (*)())Scheduler__copyFetchInEdge)(scheduler,node,helperNode);
  *(int *)(node + 0x34) = *(int *)(node + 0x34) + 1;
  *(undefined4 *)(outSelector * 4 + helperNode + 0x48) = 1;
  helperInst = *(int *)(node + 0x30);
  if (*(int *)(node + 0x30) < scheduler[0xb] + edgeAlloc[4]) {
    helperInst = scheduler[0xb] + edgeAlloc[4];
  }
  *(int *)(node + 0x30) = helperInst;
  return helperNode;
}

/* Scheduler__packDotProductCandidates @ 0x169b70 (680 bytes) */
int Scheduler__packDotProductCandidates(scheduler)
  int scheduler;
{
  int nextCandidate;
  int nextSortedNode;
  int sortedCursor;
  int *predEdgeSlot;
  uint *predEdges;
  uint loopIndex;
  int iVar1;
  uint vectorCount;
  int *nodeSlot;
  uint vectorCount2;
  int canAdd;
  int node;
  uint nodeCount;
  uint nodeIndex;
  uint predEdgeCount;
  uint *allNodes;
  int priority;
  /* NOTE (issue #64): auStack_48 was declared 8 bytes, but DListNode__init's sentinel-list init writes through
   * +0x14 (6 words) - confirmed live/via stock disasm: it writes local_40 (frame+0x40, i.e. auStack_48+8) as
   * part of the SAME sentinel struct (the self-referential "list head" pointer), not a separately-initialized
   * local. -O0 doesn't lay declared locals contiguously, so the two must be one buffer (classic stack-split
   * artifact, same class as the Scheduler__scheduleBlock/Scheduler__run fixes already landed on this issue). */
  undefined4 auStack_48_vec169b70[6];
#define auStack_48 ((unsigned char *)auStack_48_vec169b70)
#define local_40 ((int)auStack_48_vec169b70[2])
  
  nodeIndex = 0;
  DListNode__init(auStack_48);
  allNodes = *(uint **)(scheduler + 0x18);
  nodeCount = allNodes[1];
  if (0 < (int)nodeCount) {
    do {
      if (nodeIndex < *allNodes) {
        vectorCount = allNodes[1];
        if (vectorCount <= nodeIndex) {
          _memset(vectorCount * 4 + allNodes[2],0,(nodeIndex - vectorCount) * 4 + 4);
          allNodes[1] = nodeIndex + 1;
        }
        nodeSlot = (int *)(nodeIndex * 4 + allNodes[2]);
      }
      else {
        nodeSlot = (int *)Vector__elementRefGrow(allNodes,nodeIndex);
      }
      node = *nodeSlot;
      /* issue #76: same shared-array gap as Scheduler__buildDependencyGraph/Scheduler__buildCoScheduleGroups/Scheduler__computeNodePriorities - skip a
       * never-populated scheduler[0x18]-array slot instead of dereferencing it. */
      if (node == 0) goto LAB_issue76_skip_169b70;
      loopIndex = 0;
      predEdges = *(uint **)(node + 0x44);
      predEdgeCount = predEdges[1];
      if (0 < (int)predEdgeCount) {
        while( true ) {
          if (loopIndex < *predEdges) {
            vectorCount2 = predEdges[1];
            if (vectorCount2 <= loopIndex) {
              _memset(vectorCount2 * 4 + predEdges[2],0,(loopIndex - vectorCount2) * 4 + 4);
              predEdges[1] = loopIndex + 1;
            }
            predEdgeSlot = (int *)(loopIndex * 4 + predEdges[2]);
          }
          else {
            predEdgeSlot = (int *)Vector__elementRefGrow(predEdges,loopIndex);
          }
          loopIndex = loopIndex + 1;
          iVar1 = *(int *)(*(int *)*predEdgeSlot + 0x18) + ((int *)*predEdgeSlot)[3];
          priority = *(int *)(node + 0x18);
          if (*(int *)(node + 0x18) < iVar1) {
            priority = iVar1;
          }
          *(int *)(node + 0x18) = priority;
          if (predEdgeCount == loopIndex) break;
          predEdges = *(uint **)(node + 0x44);
        }
      }
      sortedCursor = local_40;
      if ((*(uint *)(*(int *)(node + 0x38) + 0x14) & 2) != 0) {
        do {
          iVar1 = sortedCursor;
          nextSortedNode = 0;
          if (*(int *)(iVar1 + 8) == 0) goto LAB_00169d08;
          sortedCursor = *(int *)(iVar1 + 8);
        } while (*(int *)(node + 0x18) <= *(int *)(iVar1 + 0x18));
        DList__insertBefore(node,iVar1);
        nextSortedNode = *(int *)(iVar1 + 8);
LAB_00169d08:
        if (nextSortedNode == 0) {
          DList__pushBack(auStack_48,node);
        }
      }
LAB_issue76_skip_169b70:
      nodeIndex = nodeIndex + 1;
      if (nodeCount == nodeIndex) break;
      allNodes = *(uint **)(scheduler + 0x18);
    } while( true );
  }
  *(undefined4 *)(scheduler + 0xf4) = 0;
  while (node = DList__isEmpty(auStack_48), node == 0) {
    (**(code **)(**(int **)(scheduler + 8) + 8))(*(int **)(scheduler + 8));
    node = local_40;
    (**(code **)(**(int **)(scheduler + 8) + 0x10))
              (*(int **)(scheduler + 8),*(undefined4 *)(local_40 + 0x38));
    nextCandidate = *(int *)(node + 8);
    DList__unlink(node);
    while (iVar1 = nextCandidate, nextCandidate = *(int *)(iVar1 + 8), nextCandidate != 0) {
      canAdd = (**(code **)(**(int **)(scheduler + 8) + 0xc))
                        (*(int **)(scheduler + 8),*(undefined4 *)(iVar1 + 0x38));
      if (canAdd != 0) {
        (**(code **)(**(int **)(scheduler + 8) + 0x10))
                  (*(int **)(scheduler + 8),*(undefined4 *)(iVar1 + 0x38));
        *(undefined4 *)(iVar1 + 0x68) = 1;
        *(int *)(scheduler + 0xf4) = *(int *)(scheduler + 0xf4) + 1;
        *(undefined4 *)(node + 0x68) = 1;
        DList__unlink(iVar1);
      }
    }
    if (*(int *)(node + 0x68) != 0) {
      *(int *)(scheduler + 0xf4) = *(int *)(scheduler + 0xf4) + 1;
    }
  }
  return;
}

/* Scheduler__markGlobalValues @ 0x169e30 (1848 bytes) */
int Scheduler__markGlobalValues(scheduler)
  int *scheduler;
{
  int element;
  undefined4 rootValue;
  int *selectCursor;
  int *nextInst;
  int *followingInst;
  int *inst2;
  int instCount;
  int globalCount;
  int block;
  int root;
  int numSources;
  int innerOperandNumber;
  int isPresub;
  int sourceRoot;
  int selectsLeft;
  int rootOfDest;
  int isMov;
  int operandNumber;
  int isPhi;
  int blockSlot5Result;
  int program;
  int registerArraySize;
  int sourceDef3;
  int sourceDef2;
  int operandRecord;
  int sourceDef;
  int *operandVReg2;
  int *operandVReg;
  int loopIndex;
  uint instFlags;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *inst3;
  int iVar6;
  int unionFindParents;
  int rootIsGlobal;
  int innerIsPresub;
  int lowRoot;
  int compilerCtx;
  undefined4 in_r8;
  int *nextBlock;
  undefined4 in_r10;
  int *block2;
  undefined4 sourceRegId;
  int inst;
  int writeMask [3];
  
  registerArraySize = *(int *)(*scheduler + 0x324) << 2;
  unionFindParents = Arena__alloc(*(undefined4 *)(*scheduler + 0x378),registerArraySize);
  rootIsGlobal = Arena__alloc(*(undefined4 *)(*scheduler + 0x378),registerArraySize);
  program = scheduler[1];
  nextBlock = (int *)(*(int **)(program + 900))[2];
  block2 = *(int **)(program + 900);
  if (nextBlock != (int *)0x0) {
    do {
      piVar4 = nextBlock;
      nextInst = (int *)((int *)block2[0x26])[2];
      inst3 = (int *)block2[0x26];
      if (nextInst != (int *)0x0) {
        do {
          piVar4 = nextInst;
          if ((inst3[5] & 1U) != 0) {
            *(int *)(unionFindParents + inst3[0x53] * 4) = inst3[0x53];
            *(undefined4 *)(inst3[0x53] * 4 + rootIsGlobal) = 0;
            operandRecord = IRInst__getOperandRecord(inst3,0);
            WriteMask__fromSelectWord(writeMask,*(undefined4 *)(operandRecord + 0x10));
            inst3[3] = writeMask[0];
            compilerCtx = *scheduler;
            IRInst__setOperandSource(inst3,0,0,0,compilerCtx);
            blockSlot5Result = (**(code **)(*block2 + 0x14))(block2);
            if (blockSlot5Result != 0) {
              inst3[5] = inst3[5] | 0x20;
            }
            isPhi = (**(code **)(*inst3 + 0x7c))(inst3);
            if (isPhi == 0) {
              if ((*(int *)(inst3[0x22] + 8) == 0x32) &&
                 (isPhi = (**(code **)(**(int **)(*scheduler + 0x30c) + 0xd0))
                                    (*(int **)(*scheduler + 0x30c)), isPhi == 0)) {
                piVar4 = (int *)inst3[2];
                inst3[5] = inst3[5] | 0x20;
                goto LAB_0016a118;
              }
              if (0 < inst3[0x21]) {
                operandNumber = 1;
                do {
                  operandVReg = (int *)IRInst__getOperandSource(inst3,operandNumber);
                  isPresub = (**(code **)(*operandVReg + 0x5c))(operandVReg);
                  if ((isPresub == 0) && (isPresub = (**(code **)(*operandVReg + 0x60))(operandVReg), isPresub == 0))
                  {
                    if (operandVReg[0x56] != inst3[0x56]) {
                      operandVReg[5] = operandVReg[5] | 0x20;
                    }
                  }
                  else if (0 < operandVReg[0x21]) {
                    innerOperandNumber = 1;
                    do {
                      operandVReg2 = (int *)IRInst__getOperandSource(operandVReg,innerOperandNumber);
                      innerIsPresub = (**(code **)(*operandVReg2 + 0x5c))(operandVReg2);
                      if (innerIsPresub == 0) {
                        if (operandVReg2[0x56] != inst3[0x56]) {
                          operandVReg2[5] = operandVReg2[5] | 0x20;
                        }
                      }
                      else if (0 < operandVReg2[0x21]) {
                        loopIndex = 1;
                        do {
                          sourceDef = IRInst__getOperandSource(operandVReg2,loopIndex);
                          if (*(int *)(sourceDef + 0x158) != inst3[0x56]) {
                            *(uint *)(sourceDef + 0x14) = *(uint *)(sourceDef + 0x14) | 0x20;
                          }
                          loopIndex = loopIndex + 1;
                        } while (loopIndex <= operandVReg2[0x21]);
                      }
                      innerOperandNumber = innerOperandNumber + 1;
                    } while (innerOperandNumber <= operandVReg[0x21]);
                  }
                  operandNumber = operandNumber + 1;
                } while (operandNumber <= inst3[0x21]);
              }
            }
            else {
              inst3[5] = inst3[5] | 0x20;
              if (0 < inst3[0x21]) {
                operandNumber = 1;
                do {
                  sourceDef3 = IRInst__getOperandSource(inst3,operandNumber);
                  numSources = inst3[0x21];
                  operandNumber = operandNumber + 1;
                  *(uint *)(sourceDef3 + 0x14) = *(uint *)(sourceDef3 + 0x14) | 0x20;
                } while (operandNumber <= numSources);
              }
            }
            piVar4 = (int *)inst3[2];
          }
LAB_0016a118:
          nextInst = (int *)piVar4[2];
          inst3 = piVar4;
        } while ((int *)piVar4[2] != (int *)0x0);
        piVar4 = (int *)block2[2];
      }
      nextBlock = (int *)piVar4[2];
      block2 = piVar4;
    } while ((int *)piVar4[2] != (int *)0x0);
    program = scheduler[1];
  }
  element = *(int *)(*(int *)(program + 900) + 8);
  block = *(int *)(program + 900);
  if (element != 0) {
    do {
      iVar2 = element;
      nextInst = (int *)(*(int **)(block + 0x98))[2];
      inst2 = *(int **)(block + 0x98);
      if (nextInst != (int *)0x0) {
        do {
          followingInst = nextInst;
          if ((inst2[5] & 1U) != 0) {
            if ((inst2[5] & 0x200U) == 0) {
              isMov = (**(code **)(*inst2 + 100))(inst2);
              if (isMov == 0) {
LAB_0016a1fc:
                instFlags = inst2[5];
LAB_0016a200:
                if ((instFlags & 0x20) != 0) {
                  rootOfDest = disjointSetFindRoot(inst2[0x53],unionFindParents);
                  *(undefined4 *)(rootOfDest * 4 + rootIsGlobal) = 1;
                }
                followingInst = (int *)inst2[2];
                goto LAB_0016a42c;
              }
              for (operandNumber = 1; element = (**(code **)(*inst2 + 0x14))(inst2), operandNumber <= element;
                  operandNumber = operandNumber + 1) {
                if ((((inst2[operandNumber * 6 + 0x28] & 1U) != 0) ||
                    ((inst2[operandNumber * 6 + 0x28] & 2U) != 0)) ||
                   (element = IRInst__isSourceSelectIdentity(inst2,operandNumber), element == 0)) goto LAB_0016a1fc;
              }
              if ((inst2[0x48] != 0) || (inst2[0x49] != 0)) goto LAB_0016a1fc;
              if (((inst2[0x20] != 0) &&
                  ((operandNumber = RegKind__flagBit0(inst2[0x26]), operandNumber != 0 && ((inst2[5] & 2U) == 0))))
                 && (operandNumber = (**(code **)(*inst2 + 0x50))(inst2), operandNumber == 0)) {
                selectsLeft = 4;
                selectCursor = inst2;
                do {
                  if ((uint)(*(byte *)(selectCursor + 0x27) - 2) < 2) goto LAB_0016a1fc;
                  selectCursor = (int *)((int)selectCursor + 1);
                  selectsLeft = selectsLeft + -1;
                } while (selectsLeft != 0);
              }
              IRInst__getOperandRecord(inst2,0);
              iVar2 = IRInst__operandKindClass(inst2,0);
              if (iVar2 != 0) goto LAB_0016a1fc;
              instFlags = inst2[5];
              if (((instFlags & 2) != 0) || ((instFlags & 0x200) != 0)) goto LAB_0016a200;
              element = inst2[0x53];
              sourceDef2 = IRInst__getOperandSource(inst2,1);
              sourceRegId = *(undefined4 *)(sourceDef2 + 0x14c);
              element = disjointSetFindRoot(element,unionFindParents);
              sourceRoot = disjointSetFindRoot(sourceRegId,unionFindParents);
              if (((*(int *)(rootIsGlobal + sourceRoot * 4) == 0) && (*(int *)(rootIsGlobal + element * 4) == 0)) &&
                 ((inst2[5] & 0x20U) == 0)) {
                sourceDef = IRInst__getOperandSource(inst2,1);
                rootValue = 0;
                if ((*(uint *)(sourceDef + 0x14) & 0x20) != 0) goto LAB_0016a3d8;
              }
              else {
LAB_0016a3d8:
                rootValue = 1;
              }
              *(undefined4 *)(rootIsGlobal + sourceRoot * 4) = rootValue;
              *(undefined4 *)(rootIsGlobal + element * 4) = rootValue;
              lowRoot = element;
              if (sourceRoot <= element) goto LAB_0016a3ec;
            }
            else {
              element = inst2[0x53];
              sourceDef2 = IRInst__getOperandSource(inst2,inst2[0x21]);
              sourceRegId = *(undefined4 *)(sourceDef2 + 0x14c);
              element = disjointSetFindRoot(element,unionFindParents);
              sourceRoot = disjointSetFindRoot(sourceRegId,unionFindParents);
              if (((*(int *)(rootIsGlobal + sourceRoot * 4) == 0) && (*(int *)(rootIsGlobal + element * 4) == 0)) &&
                 ((inst2[5] & 0x20U) == 0)) {
                sourceDef = IRInst__getOperandSource(inst2,inst2[0x21]);
                rootValue = 0;
                if ((*(uint *)(sourceDef + 0x14) & 0x20) != 0) goto LAB_0016a20c;
              }
              else {
LAB_0016a20c:
                rootValue = 1;
              }
              *(undefined4 *)(rootIsGlobal + sourceRoot * 4) = rootValue;
              *(undefined4 *)(rootIsGlobal + element * 4) = rootValue;
              lowRoot = element;
              if (sourceRoot <= element) {
LAB_0016a3ec:
                lowRoot = sourceRoot;
                sourceRoot = element;
              }
            }
            storeIndexedWord(lowRoot,sourceRoot,unionFindParents);
            followingInst = (int *)inst2[2];
          }
LAB_0016a42c:
          nextInst = (int *)followingInst[2];
          inst2 = followingInst;
        } while ((int *)followingInst[2] != (int *)0x0);
        iVar2 = *(int *)(block + 8);
      }
      element = *(int *)(iVar2 + 8);
      block = iVar2;
    } while (*(int *)(iVar2 + 8) != 0);
    program = scheduler[1];
  }
  iVar3 = *(int *)(*(int *)(program + 900) + 8);
  if (iVar3 == 0) {
    instCount = 0;
    globalCount = 0;
  }
  else {
    instCount = 0;
    globalCount = 0;
    program = *(int *)(program + 900);
    do {
      iVar6 = iVar3;
      iVar3 = *(int *)(*(int *)(program + 0x98) + 8);
      inst = *(int *)(program + 0x98);
      if (iVar3 != 0) {
        do {
          iVar6 = iVar3;
          if ((*(uint *)(inst + 0x14) & 1) != 0) {
            root = disjointSetFindRoot(*(undefined4 *)(inst + 0x14c),unionFindParents);
            if (*(int *)(root * 4 + rootIsGlobal) == 0) {
              instFlags = *(uint *)(inst + 0x14) & 0xffffffdf;
              *(uint *)(inst + 0x14) = instFlags;
            }
            else {
              instFlags = *(uint *)(inst + 0x14) | 0x20;
              *(uint *)(inst + 0x14) = instFlags;
            }
            if ((instFlags & 0x20) != 0) {
              globalCount = globalCount + 1;
            }
            iVar6 = *(int *)(inst + 8);
            instCount = instCount + 1;
          }
          iVar3 = *(int *)(iVar6 + 8);
          inst = iVar6;
        } while (*(int *)(iVar6 + 8) != 0);
        iVar6 = *(int *)(program + 8);
      }
      iVar3 = *(int *)(iVar6 + 8);
      program = iVar6;
    } while (*(int *)(iVar6 + 8) != 0);
  }
  Compiler__logf(*scheduler,"Scheduler : %d out of %d instructions are marked global\n",globalCount,instCount,
               compilerCtx,in_r8,0,in_r10);
  Arena__free(*(undefined4 *)(*scheduler + 0x378),rootIsGlobal);
  return Arena__free(*(undefined4 *)(*scheduler + 0x378),unionFindParents);
}

/* Scheduler__buildDependencyGraph @ 0x16a568 (6052 bytes) */
int Scheduler__buildDependencyGraph(scheduler, block)
  int *scheduler;
  int block;
{
  undefined4 vectorData;
  undefined4 arena;
  int resourceSlot10Result;
  uint *listNodePredEdges;
  int listNext;
  int listNode;
  int threadIsFetchClass;
  uint *slot10PredEdges;
  int isAlu;
  uint *slot11PredEdges;
  int isFetch;
  uint *readerWriterPredEdges;
  int readerWriterNode;
  int *writerNodeSlot;
  uint readerWriterIndex;
  int *readerWriterInst;
  int sourceWritesTracked;
  int sourceNumber;
  uint *carriedSlot11PredEdges;
  int threadSlot11Result;
  uint *carriedSlot10PredEdges;
  int threadSlot10Result;
  uint *laterWriterPredEdges;
  int *edgeAppendSlot;
  uint vectorCount;
  uint *curSuccEdges;
  int laterWriterNode;
  int *laterWriterNodeSlot;
  uint laterWriterIndex;
  int laterWriterInst;
  int writesTrackedRegister;
  int carriedSlot11Node;
  int carriedSlot10Node;
  int *curInst;
  undefined4 *hashAlloc;
  undefined4 *succVectorAlloc;
  undefined4 *predVectorAlloc;
  undefined4 *zeroCursor;
  uint countWord;
  uint *prevNodeSuccEdges;
  int prevNode;
  uint lengthWord;
  uint prevNodeIndex;
  uint *chainNodeSuccEdges;
  int chainNodeInst;
  int chainNode;
  int *nodeSlot;
  uint *allNodes;
  uint chainStep;
  uint chainIndex;
  uint *loopIndexPredEdges;
  int *appendSlot;
  uint *producerSuccEdges;
  undefined4 *edgeAlloc;
  int loopIndexProducer;
  uint innerEdgeIndex;
  int operandProducer;
  uint predEdgeIndex;
  uint *nodePredEdges;
  int sourceIsLoopIndexLoad;
  int sourceOperandIndex;
  int targetSlot53Result;
  int isProjectionOfClass26or3a;
  int isMix;
  int isPresub;
  int *presubSource;
  int *sourceDef;
  int hashBuckets;
  int sizeAttemptsLeft;
  int schedulerAllocRegEnabled;
  int isUndefined;
  int flagBit0Result;
  int newVirtualReg;
  int prevNodeInst;
  int nodeByteOffset;
  int isProjectionOfClass44;
  int operandIndex;
  int fieldsLeft;
  int trackedRegisterTest;
  int needsNoNode;
  int isEntryOrExit;
  bool hasLoopIndexSource;
  bool needsRegisterHash;
  undefined *nodeVtableBase;
  int *instAfterNext;
  int *nextInst;
  undefined *nodeVtableTemp;
  int schedulerReorderEnabled;
  uint edgeVectorCount;
  uint elementCount;
  undefined4 *succAppendSlot;
  undefined4 *predEdgeSlot;
  int latestSlot10Node;
  uint uVar13;
  int *inst;
  undefined4 *nodeAlloc;
  int sourceOperandCount;
  int iVar17;
  int listNextNode;
  uint dotProductLimit;
  uint nodeIndex;
  uint predEdgeCount;
  int curNode;
  int latestSlot11Node;
  undefined4 *schedNode;
  uint *lastWriterSet;
  undefined4 uVar26;
  uint *nodeVector;
  /* issue #64 live-repro (crash #11, past the 0x275c dropped-arg fix): auStack_78 is declared
   * as only 8 bytes, but DListNode__init(auStack_78) - a sentinel-node doubly-linked-list
   * initializer - writes through it as `undefined4*` up to index 5 (`scheduler[4] = scheduler;
   * scheduler[5] = 0;`), i.e. 24 bytes: the same undersized-local defect class already fixed for
   * local_c08c/local_2c/local_98. The overrun silently landed on whatever gcc placed next on
   * this rebuild's stack instead of the intended sentinel-node fields, so the list's "head"
   * self-pointer (meant to make the sentinel point to itself when empty, per
   * DList__insertBefore/DList__pushBack's insert logic) never actually got set. Live-verified on real
   * hardware: the very next list-insert call (DList__pushBack(auStack_78,schedNode), a few lines
   * below) crashed dereferencing that missing self-pointer as a wild address. `local_70`,
   * declared right after, is independently used later in this function (part_044.c:10810-
   * 10858) and must keep its own storage - so auStack_78 gets its own full-sized buffer here
   * rather than being merged with its neighbors. */
  undefined1 auStack_78 [24];
  int local_70;
  uint lastNodeIndex;
  int visitedCount;

  schedulerReorderEnabled = Compiler__isOptionEnabled(*scheduler,0x24);
  dotProductLimit = 0x7fffffff;
  if (schedulerReorderEnabled == 0) {
    dotProductLimit = 0;
  }
  scheduler[4] = block;
  SchedModel__resetCounters(scheduler[2]);
  DListNode__init(auStack_78);
  instAfterNext = (int *)(*(int **)(scheduler[4] + 0x98))[2];
  if (instAfterNext != (int *)0x0) {
    nodeIndex = 0;
    needsRegisterHash = false;
    inst = *(int **)(scheduler[4] + 0x98);
    do {
      nextInst = instAfterNext;
      if ((inst[5] & 1U) != 0) {
        inst[5] = inst[5] & 0xffffefff;
        inst[0x54] = 0;
        isEntryOrExit = (**(code **)(*inst + 0x34))(inst);
        if ((isEntryOrExit == 0) && (isEntryOrExit = (**(code **)(*inst + 0x38))(inst), isEntryOrExit == 0)) {
          needsNoNode = ((int (*)())IRInst__needsNoSchedulerNode)(inst);
          if (needsNoNode == 0) {
            trackedRegisterTest = ((int (*)())IRInst__writesTrackedRegister)(inst);
            if (((trackedRegisterTest != 0) ||
                (trackedRegisterTest = (**(code **)(*(int *)scheduler[3] + 0x2c))((int *)scheduler[3],inst),
                trackedRegisterTest != 0)) ||
               (trackedRegisterTest = (**(code **)(*(int *)scheduler[3] + 0x28))((int *)scheduler[3],inst),
               trackedRegisterTest != 0)) {
              needsRegisterHash = true;
            }
            inst[0x54] = nodeIndex;
            arena = *(undefined4 *)(*scheduler + 0x378);
            nodeAlloc = (undefined4 *)Arena__alloc(arena,0x74);
            nodeVtableBase = PTR_DAT_001e9138;
            schedNode = nodeAlloc + 1;
            nodeVtableTemp = PTR_DAT_001e8b48 + 8;
            *nodeAlloc = arena;
            nodeAlloc[1] = nodeVtableTemp;
            nodeAlloc[0xc] = 0xffffffff;
            nodeAlloc[1] = nodeVtableBase + 8;
            nodeAlloc[0x11] = 0;
            nodeAlloc[0x1c] = 0;
            fieldsLeft = 4;
            nodeAlloc[2] = 0;
            nodeAlloc[3] = 0;
            nodeAlloc[0xd] = 0;
            nodeAlloc[0xe] = 0;
            nodeAlloc[0xf] = inst;
            nodeAlloc[0x10] = nodeIndex;
            nodeAlloc[0x12] = 0;
            nodeAlloc[0x17] = 0;
            nodeAlloc[0x18] = 0;
            nodeAlloc[0x19] = 0;
            nodeAlloc[0x1a] = 0;
            nodeAlloc[0x1b] = 0;
            zeroCursor = schedNode;
            do {
              zeroCursor[0x12] = 0;
              zeroCursor = zeroCursor + 1;
              fieldsLeft = fieldsLeft + -1;
            } while (fieldsLeft != 0);
            nodeAlloc[4] = 0;
            nodeAlloc[7] = 1;
            nodeAlloc[5] = 0;
            nodeAlloc[6] = 1;
            nodeAlloc[8] = 0;
            nodeAlloc[9] = 0;
            nodeAlloc[10] = 0;
            nodeAlloc[0xb] = 0;
            arena = *(undefined4 *)(*scheduler + 0x378);
            predVectorAlloc = (undefined4 *)Arena__alloc(arena,0x14);
            *predVectorAlloc = arena;
            predVectorAlloc[1] = 2;
            predVectorAlloc[4] = arena;
            predVectorAlloc[2] = 0;
            vectorData = Arena__alloc(arena,8);
            predVectorAlloc[3] = vectorData;
            nodeAlloc[0x12] = predVectorAlloc + 1;
            arena = *(undefined4 *)(*scheduler + 0x378);
            succVectorAlloc = (undefined4 *)Arena__alloc(arena,0x14);
            *succVectorAlloc = arena;
            succVectorAlloc[1] = 2;
            succVectorAlloc[2] = 0;
            succVectorAlloc[4] = arena;
            vectorData = Arena__alloc(arena,8);
            succVectorAlloc[3] = vectorData;
            nodeAlloc[0x11] = succVectorAlloc + 1;
            if (0 < inst[0x21]) {
              operandIndex = 1;
              hasLoopIndexSource = false;
              do {
                ((int (*)())Scheduler__addOperandDependencyEdges)(scheduler,schedNode,inst,operandIndex,0);
                sourceDef = (int *)IRInst__getOperandSource(inst,operandIndex);
                isPresub = (**(code **)(*sourceDef + 0x5c))(sourceDef);
                if (isPresub == 0) {
                  sourceDef = (int *)IRInst__getOperandSource(inst,operandIndex);
                  isMix = (**(code **)(*sourceDef + 0x60))(sourceDef);
                  if (isMix != 0) goto LAB_0016a958;
                  uVar26 = IRInst__getOperandSource(inst,operandIndex);
                  isProjectionOfClass26or3a = IRInst__isProjectionOfClass26or3a(uVar26);
                  if ((isProjectionOfClass26or3a != 0) &&
                     (targetSlot53Result = (**(code **)(**(int **)(*scheduler + 0x30c) + 0xd4))
                                         (*(int **)(*scheduler + 0x30c)), targetSlot53Result != 0))
                  goto LAB_0016a958;
                }
                else {
LAB_0016a958:
                  sourceDef = (int *)IRInst__getOperandSource(inst,operandIndex);
                  isMix = (**(code **)(*sourceDef + 0x60))(sourceDef);
                  if (isMix != 0) {
                    presubSource = (int *)IRInst__getOperandSource(sourceDef,1);
                    isPresub = (**(code **)(*presubSource + 0x5c))(presubSource);
                    if (isPresub != 0) {
                      sourceDef = (int *)IRInst__getOperandSource(sourceDef,1);
                    }
                  }
                  for (sourceOperandIndex = 1; sourceOperandCount = (**(code **)(*sourceDef + 0x14))(sourceDef), sourceOperandIndex <= sourceOperandCount;
                      sourceOperandIndex = sourceOperandIndex + 1) {
                    ((int (*)())Scheduler__addOperandDependencyEdges)(scheduler,schedNode,sourceDef,operandIndex,sourceOperandIndex);
                  }
                }
                uVar26 = IRInst__getOperandSource(inst,operandIndex);
                sourceIsLoopIndexLoad = IRInst__isProjectionOfClass44(uVar26);
                if (sourceIsLoopIndexLoad != 0) {
                  hasLoopIndexSource = true;
                }
                operandIndex = operandIndex + 1;
              } while (operandIndex <= inst[0x21]);
              if (hasLoopIndexSource) {
                nodePredEdges = (uint *)nodeAlloc[0x12];
                predEdgeIndex = 0;
                predEdgeCount = nodePredEdges[1];
                if (0 < (int)predEdgeCount) {
                  while( true ) {
                    if (predEdgeIndex < *nodePredEdges) {
                      elementCount = nodePredEdges[1];
                      if (elementCount <= predEdgeIndex) {
                        _memset(elementCount * 4 + nodePredEdges[2],0,(predEdgeIndex - elementCount) * 4 + 4);
                        nodePredEdges[1] = predEdgeIndex + 1;
                      }
                      predEdgeSlot = (undefined4 *)(predEdgeIndex * 4 + nodePredEdges[2]);
                    }
                    else {
                      predEdgeSlot = (undefined4 *)Vector__elementRefGrow(nodePredEdges,predEdgeIndex);
                    }
                    operandProducer = *(int *)*predEdgeSlot;
                    isProjectionOfClass44 = IRInst__isProjectionOfClass44(*(undefined4 *)(operandProducer + 0x38));
                    if (isProjectionOfClass44 == 0) {
                      innerEdgeIndex = 0;
                      do {
                        nodePredEdges = (uint *)nodeAlloc[0x12];
                        if (innerEdgeIndex < *nodePredEdges) {
                          edgeVectorCount = nodePredEdges[1];
                          if (edgeVectorCount <= innerEdgeIndex) {
                            _memset(edgeVectorCount * 4 + nodePredEdges[2],0,(innerEdgeIndex - edgeVectorCount) * 4 + 4);
                            nodePredEdges[1] = innerEdgeIndex + 1;
                          }
                          predEdgeSlot = (undefined4 *)(innerEdgeIndex * 4 + nodePredEdges[2]);
                        }
                        else {
                          predEdgeSlot = (undefined4 *)Vector__elementRefGrow(nodePredEdges,innerEdgeIndex);
                        }
                        loopIndexProducer = *(int *)*predEdgeSlot;
                        isProjectionOfClass44 = IRInst__isProjectionOfClass44(*(undefined4 *)(loopIndexProducer + 0x38));
                        if ((isProjectionOfClass44 != 0) && (*(int *)(operandProducer + 0x3c) < *(int *)(loopIndexProducer + 0x3c))) {
                          arena = *(undefined4 *)(*scheduler + 0x378);
                          edgeAlloc = (undefined4 *)Arena__alloc(arena,0x24);
                          *edgeAlloc = arena;
                          edgeAlloc[4] = 1;
                          edgeAlloc[1] = operandProducer;
                          edgeAlloc[7] = 0x1010101;
                          edgeAlloc[3] = 5;
                          edgeAlloc[5] = 0;
                          edgeAlloc[6] = 0;
                          edgeAlloc[8] = 0;
                          edgeAlloc[2] = loopIndexProducer;
                          uVar26 = ((int (*)())Scheduler__getDependencyLatency)(scheduler,*(undefined4 *)(operandProducer + 0x38),
                                                *(undefined4 *)(loopIndexProducer + 0x38),0,0,5);
                          edgeAlloc[4] = uVar26;
                          producerSuccEdges = *(uint **)(operandProducer + 0x40);
                          edgeVectorCount = producerSuccEdges[1];
                          if (edgeVectorCount < *producerSuccEdges) {
                            _memset(edgeVectorCount * 4 + producerSuccEdges[2],0,4);
                            appendSlot = (int *)(edgeVectorCount * 4 + producerSuccEdges[2]);
                            producerSuccEdges[1] = edgeVectorCount + 1;
                          }
                          else {
                            appendSlot = (int *)Vector__elementRefGrow(producerSuccEdges,edgeVectorCount);
                          }
                          *appendSlot = (int)(edgeAlloc + 1);
                          loopIndexPredEdges = *(uint **)(loopIndexProducer + 0x44);
                          edgeVectorCount = loopIndexPredEdges[1];
                          if (edgeVectorCount < *loopIndexPredEdges) {
                            _memset(edgeVectorCount * 4 + loopIndexPredEdges[2],0,4);
                            appendSlot = (int *)(edgeVectorCount * 4 + loopIndexPredEdges[2]);
                            loopIndexPredEdges[1] = edgeVectorCount + 1;
                          }
                          else {
                            appendSlot = (int *)Vector__elementRefGrow(loopIndexPredEdges,edgeVectorCount);
                          }
                          *appendSlot = (int)(edgeAlloc + 1);
                        }
                        innerEdgeIndex = innerEdgeIndex + 1;
                      } while (predEdgeCount != innerEdgeIndex);
                    }
                    predEdgeIndex = predEdgeIndex + 1;
                    if (predEdgeCount == predEdgeIndex) break;
                    nodePredEdges = (uint *)nodeAlloc[0x12];
                  }
                }
              }
            }
            if (*(int *)(inst[0x22] + 4) == 1) {
              DList__pushBack(auStack_78,schedNode);
            }
            if (dotProductLimit == nodeIndex) {
              chainIndex = nodeIndex - 1;
              if (-1 < (int)chainIndex) {
                nodeByteOffset = chainIndex * 4;
                chainStep = 0;
                do {
                  allNodes = (uint *)scheduler[6];
                  if (chainIndex < *allNodes) {
                    elementCount = allNodes[1];
                    if (elementCount <= chainIndex) {
                      _memset(elementCount * 4 + allNodes[2],0,(chainIndex - elementCount) * 4 + 4);
                      allNodes[1] = chainIndex + 1;
                    }
                    nodeSlot = (int *)(nodeByteOffset + allNodes[2]);
                  }
                  else {
                    nodeSlot = (int *)Vector__elementRefGrow(allNodes,chainIndex);
                  }
                  chainNode = *nodeSlot;
                  chainNodeInst = *(int *)(chainNode + 0x38);
                  if (((*(uint *)(chainNodeInst + 0x14) & 2) == 0) &&
                     (*(int *)(*(int *)(chainNodeInst + 0x88) + 4) != 1)) {
                    arena = *(undefined4 *)(*scheduler + 0x378);
                    edgeAlloc = (undefined4 *)Arena__alloc(arena,0x24);
                    *edgeAlloc = arena;
                    edgeAlloc[1] = chainNode;
                    edgeAlloc[7] = 0x1010101;
                    edgeAlloc[8] = 0;
                    edgeAlloc[4] = 1;
                    edgeAlloc[5] = 0;
                    edgeAlloc[6] = 0;
                    edgeAlloc[2] = schedNode;
                    edgeAlloc[3] = 1;
                    uVar26 = ((int (*)())Scheduler__getDependencyLatency)(scheduler,chainNodeInst,inst,0,0,1);
                    edgeAlloc[4] = uVar26;
                    chainNodeSuccEdges = *(uint **)(chainNode + 0x40);
                    elementCount = chainNodeSuccEdges[1];
                    if (elementCount < *chainNodeSuccEdges) {
                      _memset(elementCount * 4 + chainNodeSuccEdges[2],0,4);
                      succAppendSlot = (undefined4 *)(elementCount * 4 + chainNodeSuccEdges[2]);
                      chainNodeSuccEdges[1] = elementCount + 1;
                    }
                    else {
                      succAppendSlot = (undefined4 *)Vector__elementRefGrow(chainNodeSuccEdges,elementCount);
                    }
                    *succAppendSlot = edgeAlloc + 1;
                    nodePredEdges = (uint *)nodeAlloc[0x12];
                    elementCount = nodePredEdges[1];
                    if (elementCount < *nodePredEdges) {
                      _memset(elementCount * 4 + nodePredEdges[2],0,4);
                      succAppendSlot = (undefined4 *)(elementCount * 4 + nodePredEdges[2]);
                      nodePredEdges[1] = elementCount + 1;
                    }
                    else {
                      succAppendSlot = (undefined4 *)Vector__elementRefGrow(nodePredEdges,elementCount);
                    }
                    *succAppendSlot = edgeAlloc + 1;
                  }
                  chainStep = chainStep + 1;
                  chainIndex = chainIndex - 1;
                  nodeByteOffset = nodeByteOffset + -4;
                } while (chainStep != nodeIndex);
              }
            }
            else if ((int)dotProductLimit < (int)nodeIndex) {
              allNodes = (uint *)scheduler[6];
              prevNodeIndex = nodeIndex - 1;
              if (prevNodeIndex < *allNodes) {
                lengthWord = allNodes[1];
                if (lengthWord <= prevNodeIndex) {
                  _memset(lengthWord * 4 + allNodes[2],0,(prevNodeIndex - lengthWord) * 4 + 4);
                  allNodes[1] = nodeIndex;
                }
                nodeSlot = (int *)(prevNodeIndex * 4 + allNodes[2]);
              }
              else {
                nodeSlot = (int *)Vector__elementRefGrow(allNodes,prevNodeIndex);
              }
              prevNode = *nodeSlot;
              prevNodeInst = *(int *)(prevNode + 0x38);
              if (*(int *)(*(int *)(prevNodeInst + 0x88) + 4) != 1) {
                arena = *(undefined4 *)(*scheduler + 0x378);
                edgeAlloc = (undefined4 *)Arena__alloc(arena,0x24);
                *edgeAlloc = arena;
                edgeAlloc[1] = prevNode;
                edgeAlloc[7] = 0x1010101;
                edgeAlloc[8] = 0;
                edgeAlloc[3] = 1;
                edgeAlloc[4] = 1;
                edgeAlloc[5] = 0;
                edgeAlloc[6] = 0;
                edgeAlloc[2] = schedNode;
                uVar26 = ((int (*)())Scheduler__getDependencyLatency)(scheduler,prevNodeInst,inst,0,0,1);
                edgeAlloc[4] = uVar26;
                prevNodeSuccEdges = *(uint **)(prevNode + 0x40);
                countWord = prevNodeSuccEdges[1];
                if (countWord < *prevNodeSuccEdges) {
                  _memset(countWord * 4 + prevNodeSuccEdges[2],0,4);
                  appendSlot = (int *)(countWord * 4 + prevNodeSuccEdges[2]);
                  prevNodeSuccEdges[1] = countWord + 1;
                }
                else {
                  appendSlot = (int *)Vector__elementRefGrow(prevNodeSuccEdges,countWord);
                }
                *appendSlot = (int)(edgeAlloc + 1);
                nodePredEdges = (uint *)nodeAlloc[0x12];
                countWord = nodePredEdges[1];
                if (countWord < *nodePredEdges) {
                  _memset(countWord * 4 + nodePredEdges[2],0,4);
                  appendSlot = (int *)(countWord * 4 + nodePredEdges[2]);
                  nodePredEdges[1] = countWord + 1;
                }
                else {
                  appendSlot = (int *)Vector__elementRefGrow(nodePredEdges,countWord);
                }
                *appendSlot = (int)(edgeAlloc + 1);
              }
            }
            allNodes = (uint *)scheduler[6];
            countWord = allNodes[1];
            if (countWord < *allNodes) {
              _memset(countWord * 4 + allNodes[2],0,4);
              nodeSlot = (int *)(countWord * 4 + allNodes[2]);
              allNodes[1] = countWord + 1;
            }
            else {
              nodeSlot = (int *)Vector__elementRefGrow(allNodes,countWord);
            }
            *nodeSlot = (int)schedNode;
            nodeIndex = nodeIndex + 1;
            nextInst = (int *)inst[2];
          }
          else {
            if (((((inst[0x20] == 0) || (flagBit0Result = RegKind__flagBit0(inst[0x26]), flagBit0Result == 0)) ||
                 ((inst[5] & 2U) != 0)) ||
                ((isUndefined = (**(code **)(*inst + 0x50))(inst), isUndefined != 0 ||
                 ((inst[5] & 0x40U) != 0)))) ||
               (((inst[5] & 0x20U) == 0 && (schedulerAllocRegEnabled = Compiler__isOptionEnabled(*scheduler,0x25), schedulerAllocRegEnabled != 0))))
            goto LAB_0016b038;
            newVirtualReg = *(int *)(*scheduler + 0x3c4) + 1;
            *(int *)(*scheduler + 0x3c4) = newVirtualReg;
            nextInst = (int *)inst[2];
            inst[0x25] = newVirtualReg;
          }
        }
        else {
LAB_0016b038:
          if ((inst[0x20] != 0) &&
             (flagBit0Result = RegKind__flagBit0(inst[0x26]), flagBit0Result != 0) &&
             ((inst[5] & 2U) == 0) &&
             (isUndefined = (**(code **)(*inst + 0x50))(inst), isUndefined == 0) &&
             ((inst[5] & 0x40U) == 0) &&
             (((inst[5] & 0x20U) != 0) ||
              (schedulerAllocRegEnabled = Compiler__isOptionEnabled(*scheduler,0x25), schedulerAllocRegEnabled == 0))) {
            newVirtualReg = *(int *)(*scheduler + 0x3c4) + 1;
            *(int *)(*scheduler + 0x3c4) = newVirtualReg;
            inst[0x25] = newVirtualReg;
          }
          nextInst = (int *)inst[2];
        }
      }
      instAfterNext = (int *)nextInst[2];
      inst = nextInst;
    } while ((int *)nextInst[2] != (int *)0x0);
    if (needsRegisterHash) {
      arena = *(undefined4 *)(*scheduler + 0x378);
      hashAlloc = (undefined4 *)Arena__alloc(arena,0x1c);
      lastWriterSet = hashAlloc + 1;
      *hashAlloc = arena;
      dotProductLimit = 1;
      hashAlloc[4] = VRegKey__equals;
      hashAlloc[1] = 1;
      hashAlloc[5] = VRegKey__hash;
      sizeAttemptsLeft = 0x20;
      hashAlloc[6] = arena;
      do {
        dotProductLimit = dotProductLimit << 1;
        if (0xf < dotProductLimit) break;
        sizeAttemptsLeft = sizeAttemptsLeft + -1;
      } while (sizeAttemptsLeft != 0);
      *lastWriterSet = dotProductLimit;
      hashAlloc[2] = 0;
      vectorData = Arena__alloc(arena,*lastWriterSet << 2);
      hashAlloc[3] = vectorData;
      _memset(vectorData,0,*lastWriterSet << 2);
      nodeIndex = nodeIndex - 1;
      if (-1 < (int)nodeIndex) {
        nodeByteOffset = nodeIndex * 4;
        visitedCount = 0;
        carriedSlot10Node = 0;
        carriedSlot11Node = 0;
        lastNodeIndex = nodeIndex;
        do {
          nodeVector = (uint *)scheduler[6];
          if (nodeIndex < *nodeVector) {
            dotProductLimit = nodeVector[1];
            if (dotProductLimit <= nodeIndex) {
              _memset(dotProductLimit * 4 + nodeVector[2],0,(nodeIndex - dotProductLimit) * 4 + 4);
              nodeVector[1] = nodeIndex + 1;
            }
            nodeSlot = (int *)(nodeByteOffset + nodeVector[2]);
          }
          else {
            nodeSlot = (int *)Vector__elementRefGrow(nodeVector,nodeIndex);
          }
          curNode = *nodeSlot;
          /* issue #76: curNode is read back from scheduler[6]'s array at whatever index this
           * iteration's format was recorded under - but that recording can legitimately still
           * be an empty (never-populated) slot: a *different*, unrelated code path
           * (Scheduler__addOperandDependencyEdges, cross-referencing a format's own sub-component via that
           * component's OWN persistent [0x54] "registry index") can grow this SAME array ahead
           * of the official sequential writer, using an index that has nothing to do with how
           * many formats this loop has appended so far. Verified live on real hardware: the
           * component's [0x54] value was stable and pre-existing (set before this whole
           * CGLCreateContext call chain even began, not corrupted by anything traced this
           * session), and every instruction from this read through the IRInst__writesTrackedRegister call below
           * is a byte-for-byte accurate decompilation of the stock binary (checked against the
           * real disassembly) - so this is a real, stock-shared gap between two independent
           * writers of the same growable array, not a decompilation defect. The rest of this
           * loop iteration exists purely to detect and register cross-format rendering quirks
           * (building "nodeAlloc[7]=0x1010101"-tagged quirk records) for a real, populated
           * format pair - with nothing here to compare against, there is no quirk to register,
           * so skip straight to this iteration's own bookkeeping instead of dereferencing a
           * format that was never actually stored. */
          if (curNode == 0) {
            latestSlot10Node = 0;
            latestSlot11Node = 0;
            goto LAB_issue76_skip_pair;
          }
          curInst = *(int **)(curNode + 0x38);
          writesTrackedRegister = ((int (*)())IRInst__writesTrackedRegister)(curInst);
          if (writesTrackedRegister != 0) {
            laterWriterInst = HashTable__find(lastWriterSet,curInst);
            if (laterWriterInst != 0) {
              nodeVector = (uint *)scheduler[6];
              laterWriterIndex = *(uint *)(laterWriterInst + 0x150);
              if (laterWriterIndex < *nodeVector) {
                countWord = nodeVector[1];
                if (countWord <= laterWriterIndex) {
                  _memset(countWord * 4 + nodeVector[2],0,(laterWriterIndex - countWord) * 4 + 4);
                  nodeVector[1] = laterWriterIndex + 1;
                }
                laterWriterNodeSlot = (int *)(laterWriterIndex * 4 + nodeVector[2]);
              }
              else {
                laterWriterNodeSlot = (int *)Vector__elementRefGrow(nodeVector,laterWriterIndex);
              }
              laterWriterNode = *laterWriterNodeSlot;
              arena = *(undefined4 *)(*scheduler + 0x378);
              nodeAlloc = (undefined4 *)Arena__alloc(arena,0x24);
              *nodeAlloc = arena;
              nodeAlloc[1] = curNode;
              nodeAlloc[7] = 0x1010101;
              nodeAlloc[4] = 1;
              nodeAlloc[5] = 0;
              nodeAlloc[6] = 0;
              nodeAlloc[8] = 0;
              nodeAlloc[2] = laterWriterNode;
              nodeAlloc[3] = 1;
              uVar26 = ((int (*)())Scheduler__getDependencyLatency)(scheduler,curInst,laterWriterInst,0,0,1);
              nodeAlloc[4] = uVar26;
              curSuccEdges = *(uint **)(curNode + 0x40);
              vectorCount = curSuccEdges[1];
              if (vectorCount < *curSuccEdges) {
                _memset(vectorCount * 4 + curSuccEdges[2],0,4);
                edgeAppendSlot = (int *)(vectorCount * 4 + curSuccEdges[2]);
                curSuccEdges[1] = vectorCount + 1;
              }
              else {
                edgeAppendSlot = (int *)Vector__elementRefGrow(curSuccEdges,vectorCount);
              }
              *edgeAppendSlot = (int)(nodeAlloc + 1);
              laterWriterPredEdges = *(uint **)(laterWriterNode + 0x44);
              vectorCount = laterWriterPredEdges[1];
              if (vectorCount < *laterWriterPredEdges) {
                _memset(vectorCount * 4 + laterWriterPredEdges[2],0,4);
                edgeAppendSlot = (int *)(vectorCount * 4 + laterWriterPredEdges[2]);
                laterWriterPredEdges[1] = vectorCount + 1;
              }
              else {
                edgeAppendSlot = (int *)Vector__elementRefGrow(laterWriterPredEdges,vectorCount);
              }
              *edgeAppendSlot = (int)(nodeAlloc + 1);
              FUN_00194720(lastWriterSet,laterWriterInst);
            }
            HashTable__insert(lastWriterSet,curInst);
          }
          threadSlot10Result = (**(code **)(*(int *)scheduler[3] + 0x28))((int *)scheduler[3],curInst);
          latestSlot10Node = carriedSlot10Node;
          if ((threadSlot10Result != 0) && (latestSlot10Node = curNode, carriedSlot10Node != 0)) {
            arena = *(undefined4 *)(*scheduler + 0x378);
            nodeAlloc = (undefined4 *)Arena__alloc(arena,0x24);
            *nodeAlloc = arena;
            nodeAlloc[7] = 0x1010101;
            nodeAlloc[1] = curNode;
            nodeAlloc[4] = 1;
            nodeAlloc[5] = 0;
            nodeAlloc[6] = 0;
            nodeAlloc[8] = 0;
            nodeAlloc[2] = carriedSlot10Node;
            nodeAlloc[3] = 4;
            uVar26 = ((int (*)())Scheduler__getDependencyLatency)(scheduler,curInst,*(undefined4 *)(carriedSlot10Node + 0x38),0,0,4);
            nodeAlloc[4] = uVar26;
            curSuccEdges = *(uint **)(curNode + 0x40);
            vectorCount = curSuccEdges[1];
            if (vectorCount < *curSuccEdges) {
              _memset(vectorCount * 4 + curSuccEdges[2],0,4);
              edgeAppendSlot = (int *)(vectorCount * 4 + curSuccEdges[2]);
              curSuccEdges[1] = vectorCount + 1;
            }
            else {
              edgeAppendSlot = (int *)Vector__elementRefGrow(curSuccEdges,vectorCount);
            }
            *edgeAppendSlot = (int)(nodeAlloc + 1);
            carriedSlot10PredEdges = *(uint **)(carriedSlot10Node + 0x44);
            vectorCount = carriedSlot10PredEdges[1];
            if (vectorCount < *carriedSlot10PredEdges) {
              _memset(vectorCount * 4 + carriedSlot10PredEdges[2],0,4);
              edgeAppendSlot = (int *)(vectorCount * 4 + carriedSlot10PredEdges[2]);
              carriedSlot10PredEdges[1] = vectorCount + 1;
            }
            else {
              edgeAppendSlot = (int *)Vector__elementRefGrow(carriedSlot10PredEdges,vectorCount);
            }
            *edgeAppendSlot = (int)(nodeAlloc + 1);
          }
          threadSlot11Result = (**(code **)(*(int *)scheduler[3] + 0x2c))((int *)scheduler[3],curInst);
          latestSlot11Node = carriedSlot11Node;
          if ((threadSlot11Result != 0) && (latestSlot11Node = curNode, carriedSlot11Node != 0)) {
            arena = *(undefined4 *)(*scheduler + 0x378);
            nodeAlloc = (undefined4 *)Arena__alloc(arena,0x24);
            *nodeAlloc = arena;
            nodeAlloc[7] = 0x1010101;
            nodeAlloc[1] = curNode;
            nodeAlloc[4] = 1;
            nodeAlloc[5] = 0;
            nodeAlloc[6] = 0;
            nodeAlloc[8] = 0;
            nodeAlloc[2] = carriedSlot11Node;
            nodeAlloc[3] = 4;
            uVar26 = ((int (*)())Scheduler__getDependencyLatency)(scheduler,curInst,*(undefined4 *)(carriedSlot11Node + 0x38),0,0,4);
            nodeAlloc[4] = uVar26;
            curSuccEdges = *(uint **)(curNode + 0x40);
            vectorCount = curSuccEdges[1];
            if (vectorCount < *curSuccEdges) {
              _memset(vectorCount * 4 + curSuccEdges[2],0,4);
              edgeAppendSlot = (int *)(vectorCount * 4 + curSuccEdges[2]);
              curSuccEdges[1] = vectorCount + 1;
            }
            else {
              edgeAppendSlot = (int *)Vector__elementRefGrow(curSuccEdges,vectorCount);
            }
            *edgeAppendSlot = (int)(nodeAlloc + 1);
            carriedSlot11PredEdges = *(uint **)(carriedSlot11Node + 0x44);
            vectorCount = carriedSlot11PredEdges[1];
            if (vectorCount < *carriedSlot11PredEdges) {
              _memset(vectorCount * 4 + carriedSlot11PredEdges[2],0,4);
              edgeAppendSlot = (int *)(vectorCount * 4 + carriedSlot11PredEdges[2]);
              carriedSlot11PredEdges[1] = vectorCount + 1;
            }
            else {
              edgeAppendSlot = (int *)Vector__elementRefGrow(carriedSlot11PredEdges,vectorCount);
            }
            *edgeAppendSlot = (int)(nodeAlloc + 1);
          }
          if (0 < curInst[0x21]) {
            sourceNumber = 1;
            do {
              uVar26 = IRInst__getOperandSource(curInst,sourceNumber);
              sourceWritesTracked = ((int (*)())IRInst__writesTrackedRegister)(uVar26);
              if (sourceWritesTracked != 0) {
                uVar26 = IRInst__getOperandSource(curInst,sourceNumber);
                readerWriterInst = (int *)HashTable__find(lastWriterSet,uVar26);
                if ((readerWriterInst != (int *)0x0) && (curInst != readerWriterInst)) {
                  nodeVector = (uint *)scheduler[6];
                  readerWriterIndex = readerWriterInst[0x54];
                  if (readerWriterIndex < *nodeVector) {
                    uVar13 = nodeVector[1];
                    if (uVar13 <= readerWriterIndex) {
                      _memset(uVar13 * 4 + nodeVector[2],0,(readerWriterIndex - uVar13) * 4 + 4);
                      nodeVector[1] = readerWriterIndex + 1;
                    }
                    writerNodeSlot = (int *)(readerWriterIndex * 4 + nodeVector[2]);
                  }
                  else {
                    writerNodeSlot = (int *)Vector__elementRefGrow(nodeVector,readerWriterIndex);
                  }
                  readerWriterNode = *writerNodeSlot;
                  arena = *(undefined4 *)(*scheduler + 0x378);
                  nodeAlloc = (undefined4 *)Arena__alloc(arena,0x24);
                  *nodeAlloc = arena;
                  nodeAlloc[7] = 0x1010101;
                  nodeAlloc[1] = curNode;
                  nodeAlloc[3] = 2;
                  nodeAlloc[4] = 1;
                  nodeAlloc[5] = 0;
                  nodeAlloc[6] = 0;
                  nodeAlloc[8] = 0;
                  nodeAlloc[2] = readerWriterNode;
                  uVar26 = ((int (*)())Scheduler__getDependencyLatency)(scheduler,curInst,readerWriterInst,sourceNumber,0,2);
                  nodeAlloc[4] = uVar26;
                  curSuccEdges = *(uint **)(curNode + 0x40);
                  vectorCount = curSuccEdges[1];
                  if (vectorCount < *curSuccEdges) {
                    _memset(vectorCount * 4 + curSuccEdges[2],0,4);
                    edgeAppendSlot = (int *)(vectorCount * 4 + curSuccEdges[2]);
                    curSuccEdges[1] = vectorCount + 1;
                  }
                  else {
                    edgeAppendSlot = (int *)Vector__elementRefGrow(curSuccEdges,vectorCount);
                  }
                  *edgeAppendSlot = (int)(nodeAlloc + 1);
                  readerWriterPredEdges = *(uint **)(readerWriterNode + 0x44);
                  vectorCount = readerWriterPredEdges[1];
                  if (vectorCount < *readerWriterPredEdges) {
                    _memset(vectorCount * 4 + readerWriterPredEdges[2],0,4);
                    edgeAppendSlot = (int *)(vectorCount * 4 + readerWriterPredEdges[2]);
                    readerWriterPredEdges[1] = vectorCount + 1;
                  }
                  else {
                    edgeAppendSlot = (int *)Vector__elementRefGrow(readerWriterPredEdges,vectorCount);
                  }
                  *edgeAppendSlot = (int)(nodeAlloc + 1);
                }
              }
              sourceNumber = sourceNumber + 1;
            } while (sourceNumber <= curInst[0x21]);
          }
          isFetch = (**(code **)(*curInst + 0x28))(curInst);
          if ((isFetch != 0) && (latestSlot11Node != 0)) {
            arena = *(undefined4 *)(*scheduler + 0x378);
            nodeAlloc = (undefined4 *)Arena__alloc(arena,0x24);
            *nodeAlloc = arena;
            nodeAlloc[7] = 0x1010101;
            nodeAlloc[1] = curNode;
            nodeAlloc[4] = 1;
            nodeAlloc[5] = 0;
            nodeAlloc[6] = 0;
            nodeAlloc[8] = 0;
            nodeAlloc[2] = latestSlot11Node;
            nodeAlloc[3] = 4;
            uVar26 = ((int (*)())Scheduler__getDependencyLatency)(scheduler,curInst,*(undefined4 *)(latestSlot11Node + 0x38),0,0,4);
            nodeAlloc[4] = uVar26;
            curSuccEdges = *(uint **)(curNode + 0x40);
            vectorCount = curSuccEdges[1];
            if (vectorCount < *curSuccEdges) {
              _memset(vectorCount * 4 + curSuccEdges[2],0,4);
              edgeAppendSlot = (int *)(vectorCount * 4 + curSuccEdges[2]);
              curSuccEdges[1] = vectorCount + 1;
            }
            else {
              edgeAppendSlot = (int *)Vector__elementRefGrow(curSuccEdges,vectorCount);
            }
            *edgeAppendSlot = (int)(nodeAlloc + 1);
            slot11PredEdges = *(uint **)(latestSlot11Node + 0x44);
            vectorCount = slot11PredEdges[1];
            if (vectorCount < *slot11PredEdges) {
              _memset(vectorCount * 4 + slot11PredEdges[2],0,4);
              edgeAppendSlot = (int *)(vectorCount * 4 + slot11PredEdges[2]);
              slot11PredEdges[1] = vectorCount + 1;
            }
            else {
              edgeAppendSlot = (int *)Vector__elementRefGrow(slot11PredEdges,vectorCount);
            }
            *edgeAppendSlot = (int)(nodeAlloc + 1);
          }
          isAlu = (**(code **)(*curInst + 0x24))(curInst);
          if (((isAlu != 0) && ((curInst[5] & 2U) == 0)) && (latestSlot10Node != 0)) {
            arena = *(undefined4 *)(*scheduler + 0x378);
            nodeAlloc = (undefined4 *)Arena__alloc(arena,0x24);
            *nodeAlloc = arena;
            nodeAlloc[7] = 0x1010101;
            nodeAlloc[1] = curNode;
            nodeAlloc[8] = 0;
            nodeAlloc[4] = 1;
            nodeAlloc[5] = 0;
            nodeAlloc[6] = 0;
            nodeAlloc[2] = latestSlot10Node;
            nodeAlloc[3] = 4;
            uVar26 = ((int (*)())Scheduler__getDependencyLatency)(scheduler,curInst,*(undefined4 *)(latestSlot10Node + 0x38),0,0,4);
            nodeAlloc[4] = uVar26;
            curSuccEdges = *(uint **)(curNode + 0x40);
            vectorCount = curSuccEdges[1];
            if (vectorCount < *curSuccEdges) {
              _memset(vectorCount * 4 + curSuccEdges[2],0,4);
              edgeAppendSlot = (int *)(vectorCount * 4 + curSuccEdges[2]);
              curSuccEdges[1] = vectorCount + 1;
            }
            else {
              edgeAppendSlot = (int *)Vector__elementRefGrow(curSuccEdges,vectorCount);
            }
            *edgeAppendSlot = (int)(nodeAlloc + 1);
            slot10PredEdges = *(uint **)(latestSlot10Node + 0x44);
            vectorCount = slot10PredEdges[1];
            if (vectorCount < *slot10PredEdges) {
              _memset(vectorCount * 4 + slot10PredEdges[2],0,4);
              edgeAppendSlot = (int *)(vectorCount * 4 + slot10PredEdges[2]);
              slot10PredEdges[1] = vectorCount + 1;
            }
            else {
              edgeAppendSlot = (int *)Vector__elementRefGrow(slot10PredEdges,vectorCount);
            }
            *edgeAppendSlot = (int)(nodeAlloc + 1);
          }
          threadIsFetchClass = (**(code **)(*(int *)scheduler[3] + 0x20))((int *)scheduler[3],curInst);
          if ((threadIsFetchClass != 0) && (threadIsFetchClass = DList__isEmpty(auStack_78), threadIsFetchClass == 0)) {
            listNext = *(int *)(local_70 + 8);
            listNode = local_70;
            while (listNext != 0) {
              arena = *(undefined4 *)(*scheduler + 0x378);
              nodeAlloc = (undefined4 *)Arena__alloc(arena,0x24);
              *nodeAlloc = arena;
              nodeAlloc[7] = 0x1010101;
              nodeAlloc[1] = curNode;
              nodeAlloc[4] = 1;
              nodeAlloc[5] = 0;
              nodeAlloc[6] = 0;
              nodeAlloc[8] = 0;
              nodeAlloc[2] = listNode;
              nodeAlloc[3] = 4;
              uVar26 = ((int (*)())Scheduler__getDependencyLatency)(scheduler,curInst,*(undefined4 *)(listNode + 0x38),0,0,4);
              nodeAlloc[4] = uVar26;
              curSuccEdges = *(uint **)(curNode + 0x40);
              vectorCount = curSuccEdges[1];
              if (vectorCount < *curSuccEdges) {
                _memset(vectorCount * 4 + curSuccEdges[2],0,4);
                edgeAppendSlot = (int *)(vectorCount * 4 + curSuccEdges[2]);
                curSuccEdges[1] = vectorCount + 1;
              }
              else {
                edgeAppendSlot = (int *)Vector__elementRefGrow(curSuccEdges,vectorCount);
              }
              *edgeAppendSlot = (int)(nodeAlloc + 1);
              listNodePredEdges = *(uint **)(listNode + 0x44);
              vectorCount = listNodePredEdges[1];
              if (vectorCount < *listNodePredEdges) {
                _memset(vectorCount * 4 + listNodePredEdges[2],0,4);
                edgeAppendSlot = (int *)(vectorCount * 4 + listNodePredEdges[2]);
                listNodePredEdges[1] = vectorCount + 1;
              }
              else {
                edgeAppendSlot = (int *)Vector__elementRefGrow(listNodePredEdges,vectorCount);
              }
              *edgeAppendSlot = (int)(nodeAlloc + 1);
              listNode = *(int *)(listNode + 8);
              listNext = *(int *)(listNode + 8);
            }
          }
          if (((*(int *)(scheduler[1] + 0x33c) != 0) &&
              (*(int *)(*(int *)(*scheduler + 0x30c) + 0x20) <
               *(int *)(*(int *)(scheduler[1] + 0x33c) + 300))) &&
             (resourceSlot10Result = (**(code **)(*(int *)scheduler[2] + 0x28))((int *)scheduler[2],curInst),
             resourceSlot10Result != 0)) {
            listNext = *(int *)(local_70 + 8);
            listNode = local_70;
            while (listNextNode = listNext, listNextNode != 0) {
              if (*(int *)(listNode + 0x38) == *(int *)(scheduler[1] + 0x33c)) {
                arena = *(undefined4 *)(*scheduler + 0x378);
                nodeAlloc = (undefined4 *)Arena__alloc(arena,0x24);
                *nodeAlloc = arena;
                nodeAlloc[7] = 0x1010101;
                nodeAlloc[1] = curNode;
                nodeAlloc[3] = 2;
                nodeAlloc[4] = 1;
                nodeAlloc[5] = 0;
                nodeAlloc[6] = 0;
                nodeAlloc[8] = 0;
                nodeAlloc[2] = listNode;
                uVar26 = ((int (*)())Scheduler__getDependencyLatency)(scheduler,curInst,*(undefined4 *)(listNode + 0x38),0,0,2);
                nodeAlloc[4] = uVar26;
                curSuccEdges = *(uint **)(curNode + 0x40);
                vectorCount = curSuccEdges[1];
                if (vectorCount < *curSuccEdges) {
                  _memset(vectorCount * 4 + curSuccEdges[2],0,4);
                  edgeAppendSlot = (int *)(vectorCount * 4 + curSuccEdges[2]);
                  curSuccEdges[1] = vectorCount + 1;
                }
                else {
                  edgeAppendSlot = (int *)Vector__elementRefGrow(curSuccEdges,vectorCount);
                }
                *edgeAppendSlot = (int)(nodeAlloc + 1);
                listNodePredEdges = *(uint **)(listNode + 0x44);
                vectorCount = listNodePredEdges[1];
                if (vectorCount < *listNodePredEdges) {
                  _memset(vectorCount * 4 + listNodePredEdges[2],0,4);
                  edgeAppendSlot = (int *)(vectorCount * 4 + listNodePredEdges[2]);
                  listNodePredEdges[1] = vectorCount + 1;
                }
                else {
                  edgeAppendSlot = (int *)Vector__elementRefGrow(listNodePredEdges,vectorCount);
                }
                *edgeAppendSlot = (int)(nodeAlloc + 1);
                listNextNode = *(int *)(listNode + 8);
              }
              listNode = listNextNode;
              listNext = *(int *)(listNextNode + 8);
            }
          }
LAB_issue76_skip_pair:
          nodeIndex = nodeIndex - 1;
          nodeByteOffset = nodeByteOffset + -4;
          visitedCount = visitedCount + 1;
          carriedSlot10Node = latestSlot10Node;
          carriedSlot11Node = latestSlot11Node;
        } while (visitedCount != lastNodeIndex + 1);
      }
      if (lastWriterSet != (uint *)0x0) {
        dotProductLimit = *lastWriterSet;
        if (dotProductLimit == 0) {
          hashBuckets = hashAlloc[3];
        }
        else {
          hashBuckets = hashAlloc[3];
          nodeIndex = 0;
          do {
            iVar17 = *(int *)(nodeIndex * 4 + hashBuckets);
            if (iVar17 != 0) {
              Arena__free(hashAlloc[6],iVar17);
              dotProductLimit = *lastWriterSet;
              hashBuckets = hashAlloc[3];
            }
            nodeIndex = nodeIndex + 1;
          } while (nodeIndex < dotProductLimit);
        }
        Arena__free(hashAlloc[6],hashBuckets);
        Arena__free(*hashAlloc,hashAlloc);
      }
    }
  }
  return;
}

/* Scheduler__buildCoScheduleGroups @ 0x16bd70 (1140 bytes) */
int Scheduler__buildCoScheduleGroups(scheduler)
  int *scheduler;
{
  undefined4 *allocation;
  uint stackCountBeforeSibling;
  int *siblingEdge;
  uint consumerPredCount;
  uint *consumerPredEdges;
  int *succEdgeSlot;
  uint *succEdges;
  int *topSlot;
  uint topIndex;
  int *pushSlot;
  uint stackCountBefore;
  uint *zeroCursor;
  uint defaultMaskWord;
  uint vectorCount;
  int pushByteOffset;
  undefined4 defaultSelectWord;
  uint uVar3;
  int *nodeSlot;
  int iVar5;
  undefined4 *puVar6;
  uint succEdgeCount;
  uint vectorCount2;
  int siblingNode;
  uint *groupRecord;
  uint nodeCount;
  int consumerNode;
  int node;
  uint loopIndex;
  uint loopIndex2;
  int succEdge;
  uint *allNodes;
  undefined4 arena;
  uint loopIndex3;
  /* NOTE (issue #64): local_68/local_64/local_60 are passed by address (&local_68) to Arena__alloc/
   * Vector__removeAt/Vector__elementRefGrow as one contiguous 3-word vector struct (capacity, count, data-ptr).
   * Ghidra split it into 3 separate scalar locals, which -O0 does NOT lay out contiguously (confirmed
   * live: real stack deltas were 0x44/0x4 bytes, not 4/4) - forced into one array so the compiler
   * can't reorder/pad between them. */
  undefined4 local_68vec_16bd70[3];
#define local_68_vec local_68vec_16bd70[0]
#define local_64_vec local_68vec_16bd70[1]
#define local_60_vec local_68vec_16bd70[2]
  undefined4 compilerArena;
  
  compilerArena = *(undefined4 *)(*scheduler + 0x378);
  nodeCount = *(uint *)(scheduler[6] + 4);
  local_64_vec = 0;
  local_68_vec = 2;
  local_60_vec = Arena__alloc(compilerArena,8);
  if (0 < (int)nodeCount) {
    loopIndex = 0;
    groupRecord = (uint *)0x0;
    do {
      allNodes = (uint *)scheduler[6];
      if (loopIndex < *allNodes) {
        vectorCount = allNodes[1];
        if (vectorCount <= loopIndex) {
          _memset(vectorCount * 4 + allNodes[2],0,(loopIndex - vectorCount) * 4 + 4);
          allNodes[1] = loopIndex + 1;
        }
        nodeSlot = (int *)(loopIndex * 4 + allNodes[2]);
      }
      else {
        nodeSlot = (int *)Vector__elementRefGrow(allNodes,loopIndex);
      }
      node = *nodeSlot;
      /* issue #76: same shared-array gap as Scheduler__buildDependencyGraph - scheduler[6] can have never-populated
       * slots left behind by an unrelated code path (Scheduler__addOperandDependencyEdges) that grows this same array
       * via a format's own persistent, pre-existing registry index, independent of how many
       * slots this function's own sequential scan has walked. Skip an empty slot instead of
       * dereferencing it. */
      if (node == 0) goto LAB_issue76_skip_16bd70;
      if (((((*(int *)(node + 0x60) == 0) &&
            (nodeSlot = *(int **)(node + 0x38), nodeSlot[0x20] != 0)) &&
           (iVar5 = RegKind__flagBit0(nodeSlot[0x26]), iVar5 != 0)) &&
          (((nodeSlot[5] & 2U) == 0 && (iVar5 = (**(code **)(*nodeSlot + 0x50))(nodeSlot), iVar5 == 0))))
         && ((*(uint *)(*(int *)(node + 0x38) + 0x14) & 0x20) == 0)) {
        if (groupRecord == (uint *)0x0) {
          arena = *(undefined4 *)(*scheduler + 0x378);
          allocation = (undefined4 *)Arena__alloc(arena,0x2c);
          defaultMaskWord = DAT_001b01a8;
          defaultSelectWord = DAT_001b0198;
          groupRecord = allocation + 1;
          *allocation = arena;
          allocation[1] = defaultMaskWord;
          allocation[6] = 0x7fffffff;
          allocation[2] = 0xffffffff;
          iVar5 = 4;
          allocation[4] = defaultSelectWord;
          allocation[5] = 0;
          allocation[3] = 0;
          zeroCursor = groupRecord;
          do {
            zeroCursor[6] = 0;
            zeroCursor = zeroCursor + 1;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        stackCountBefore = local_64_vec;
        *(uint **)(node + 0x60) = groupRecord;
        groupRecord[4] = 1;
        *groupRecord = *(uint *)(*(int *)(node + 0x38) + 0xc);
        if (local_64_vec < local_68_vec) {
          iVar5 = local_64_vec * 4;
          _memset(iVar5 + local_60_vec,0,4);
          local_64_vec = stackCountBefore + 1;
          pushSlot = (int *)(iVar5 + local_60_vec);
        }
        else {
          pushSlot = (int *)Vector__elementRefGrow(&local_68_vec,local_64_vec);
        }
        *pushSlot = node;
        while (uVar3 = DAT_001b01a8, local_64_vec != 0) {
          topIndex = local_64_vec - 1;
          topSlot = (int *)0x0;
          if (topIndex < local_64_vec) {
            topSlot = (int *)(topIndex * 4 + local_60_vec);
          }
          iVar5 = *topSlot;
          Vector__removeAt(&local_68_vec,topIndex);
          succEdges = *(uint **)(iVar5 + 0x40);
          loopIndex2 = 0;
          vectorCount = succEdges[1];
          if (0 < (int)vectorCount) {
            while( true ) {
              if (loopIndex2 < *succEdges) {
                succEdgeCount = succEdges[1];
                if (succEdgeCount <= loopIndex2) {
                  _memset(succEdgeCount * 4 + succEdges[2],0,(loopIndex2 - succEdgeCount) * 4 + 4);
                  succEdges[1] = loopIndex2 + 1;
                }
                succEdgeSlot = (int *)(loopIndex2 * 4 + succEdges[2]);
              }
              else {
                succEdgeSlot = (int *)Vector__elementRefGrow(succEdges,loopIndex2);
              }
              succEdge = *succEdgeSlot;
              if (*(int *)(succEdge + 8) == 0) {
                consumerNode = *(int *)(succEdge + 4);
                loopIndex3 = 0;
                consumerPredEdges = *(uint **)(consumerNode + 0x44);
                consumerPredCount = consumerPredEdges[1];
                if (0 < (int)consumerPredCount) {
                  while( true ) {
                    if (loopIndex3 < *consumerPredEdges) {
                      vectorCount2 = consumerPredEdges[1];
                      if (vectorCount2 <= loopIndex3) {
                        _memset(vectorCount2 * 4 + consumerPredEdges[2],0,(loopIndex3 - vectorCount2) * 4 + 4);
                        consumerPredEdges[1] = loopIndex3 + 1;
                      }
                      puVar6 = (undefined4 *)(loopIndex3 * 4 + consumerPredEdges[2]);
                    }
                    else {
                      puVar6 = (undefined4 *)Vector__elementRefGrow(consumerPredEdges,loopIndex3);
                    }
                    stackCountBeforeSibling = local_64_vec;
                    siblingEdge = (int *)*puVar6;
                    if (((siblingEdge[2] == 0) && (siblingEdge[4] == *(int *)(succEdge + 0x10))) &&
                       ((siblingEdge[5] == *(int *)(succEdge + 0x14) && (*(int *)(*siblingEdge + 0x60) == 0))))
                    {
                      *(uint **)(*siblingEdge + 0x60) = groupRecord;
                      groupRecord[4] = groupRecord[4] + 1;
                      *groupRecord = *groupRecord | *(uint *)(*(int *)(*siblingEdge + 0x38) + 0xc);
                      siblingNode = *siblingEdge;
                      if (local_64_vec < local_68_vec) {
                        pushByteOffset = local_64_vec * 4;
                        _memset(pushByteOffset + local_60_vec,0,4);
                        local_64_vec = stackCountBeforeSibling + 1;
                        pushSlot = (int *)(pushByteOffset + local_60_vec);
                      }
                      else {
                        pushSlot = (int *)Vector__elementRefGrow(&local_68_vec,local_64_vec);
                      }
                      *pushSlot = siblingNode;
                    }
                    loopIndex3 = loopIndex3 + 1;
                    if (consumerPredCount == loopIndex3) break;
                    consumerPredEdges = *(uint **)(consumerNode + 0x44);
                  }
                }
              }
              loopIndex2 = loopIndex2 + 1;
              if (vectorCount == loopIndex2) break;
              succEdges = *(uint **)(iVar5 + 0x40);
            }
          }
        }
        if (groupRecord[4] == 1) {
          *(undefined4 *)(node + 0x60) = 0;
          *groupRecord = uVar3;
          groupRecord[4] = 0;
        }
        else {
          groupRecord = (uint *)0x0;
        }
      }
LAB_issue76_skip_16bd70:
      loopIndex = loopIndex + 1;
    } while (nodeCount != loopIndex);
    if (groupRecord != (uint *)0x0) {
      Arena__free(groupRecord[-1],groupRecord + -1);
    }
  }
  return Arena__free(compilerArena,local_60_vec);
}

/* FUN_0016c1fc @ 0x16c1fc (1092 bytes) */
int FUN_0016c1fc(compiler)
  int *compiler;
{
  int *inst2;
  int allocation;
  int schedulerAllocRegEnabled2;
  int schedulerAllocRegEnabled;
  int operandRecord2;
  int operandRecord;
  int loopIndex;
  int *piVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *inst;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  inst = (int *)compiler[0xc];
  iVar4 = *inst;
  if (iVar4 == 0) {
    iVar4 = inst[1];
    if (iVar4 == 0) goto LAB_0016c27c;
  }
  else if (inst[1] != 0) goto LAB_0016c27c;
  if (((*(int *)(iVar4 + 100) == 0) && (*(int *)(iVar4 + 0x60) == 0)) &&
     (*(int *)(*(int *)(iVar4 + 0x38) + 0x98) == 1)) {
    *(undefined4 *)(*(int *)(iVar4 + 0x38) + 0x98) = 0;
    inst = (int *)compiler[0xc];
  }
LAB_0016c27c:
  iVar4 = 0;
  while( true ) {
    iVar12 = inst[iVar4];
    if ((((iVar12 != 0) && (inst = *(int **)(iVar12 + 0x38), inst[0x20] != 0)) &&
        ((iVar5 = RegKind__flagBit0(inst[0x26]), iVar5 != 0 &&
         (((inst[5] & 2U) == 0 && (iVar5 = (**(code **)(*inst + 0x50))(inst), iVar5 == 0))))))
       && ((inst[5] & 0x40U) != 0)) {
      iVar5 = inst[0x25];
      iVar10 = 0;
      piVar9 = compiler;
      do {
        operandRecord = IRInst__getOperandRecord(inst,0);
        if (*(char *)(iVar10 + operandRecord + 0x10) != '\x01') {
          *(int *)(piVar9[0x4d] + iVar5 * 4) = iVar12;
        }
        bVar2 = iVar10 != 3;
        piVar9 = piVar9 + 1;
        iVar10 = iVar10 + 1;
      } while (bVar2);
    }
    if (4 < iVar4 + 1) break;
    inst = (int *)compiler[0xc];
    iVar4 = iVar4 + 1;
  }
  iVar4 = compiler[0xc];
  loopIndex = 0;
  do {
    iVar5 = loopIndex * 4;
    loopIndex = loopIndex + 1;
    iVar4 = *(int *)(iVar5 + iVar4);
    if (iVar4 != 0) {
      inst2 = *(int **)(iVar4 + 0x38);
      schedulerAllocRegEnabled2 = Compiler__isOptionEnabled(*compiler,0x25);
      if (schedulerAllocRegEnabled2 == 0) {
LAB_0016c3e0:
        iVar5 = inst2[0x20];
      }
      else {
        iVar5 = 0;
        if (inst2[0x20] != 0) {
          iVar5 = RegKind__flagBit0(inst2[0x26]);
          if ((((iVar5 != 0) && ((inst2[5] & 2U) == 0)) &&
              (iVar5 = (**(code **)(*inst2 + 0x50))(inst2), iVar5 == 0)) &&
             (((inst2[5] & 0x40U) == 0 && ((inst2[5] & 0x20U) == 0)))) {
            if ((*(int *)(iVar4 + 0x60) == 0) ||
               (iVar5 = *(int *)(*(int *)(iVar4 + 0x60) + 4), iVar5 < 0)) {
              iVar10 = (**(code **)(**(int **)(*compiler + 0x30c) + 0x7c))
                                 (*(int **)(*compiler + 0x30c),inst2);
              iVar5 = DAT_001b0194;
              if (iVar10 != 0) {
                if (*(int **)(iVar4 + 0x60) == (int *)0x0) {
                  iVar5 = inst2[3];
                }
                else {
                  iVar5 = **(int **)(iVar4 + 0x60);
                }
              }
              iVar5 = ((int (*)())Scheduler__findFreeTempRegister)(compiler,inst2[0x26],iVar5);
              if (iVar5 < 0) {
                iVar5 = compiler[0x52];
                iVar10 = compiler[0x53];
                compiler[0x52] = iVar5 + 1;
                if (iVar10 < iVar5 + 1) {
                  piVar9 = compiler;
                  do {
                    iVar11 = piVar9[0x4d];
                    allocation = Arena__alloc(*(undefined4 *)(*compiler + 0x378),iVar10 << 3);
                    iVar7 = compiler[0x53];
                    piVar9[0x4d] = allocation;
                    piVar9 = piVar9 + 1;
                    _memcpy(allocation,iVar11,iVar7 << 2);
                    Arena__free(*(undefined4 *)(*compiler + 0x378),iVar11);
                  } while (piVar9 != compiler + 4);
                  compiler[0x53] = iVar10 << 1;
                }
                iVar10 = iVar5 * 4;
                iVar6 = 4;
                piVar9 = compiler;
                do {
                  piVar1 = piVar9 + 0x4d;
                  piVar9 = piVar9 + 1;
                  *(undefined4 *)(iVar10 + *piVar1) = 0;
                  iVar6 = iVar6 + -1;
                } while (iVar6 != 0);
              }
              else {
                iVar10 = iVar5 << 2;
              }
              iVar6 = 0;
              piVar9 = compiler;
              do {
                operandRecord2 = IRInst__getOperandRecord(inst2,0);
                if (*(char *)(iVar6 + operandRecord2 + 0x10) != '\x01') {
                  *(int *)(piVar9[0x4d] + iVar10) = iVar4;
                }
                bVar2 = iVar6 != 3;
                piVar9 = piVar9 + 1;
                iVar6 = iVar6 + 1;
              } while (bVar2);
              if (*(int *)(iVar4 + 0x60) != 0) {
                *(int *)(*(int *)(iVar4 + 0x60) + 4) = iVar5;
              }
            }
            else {
              iVar10 = 0;
              piVar9 = compiler;
              do {
                operandRecord = IRInst__getOperandRecord(inst2,0);
                if (*(char *)(iVar10 + operandRecord + 0x10) != '\x01') {
                  *(int *)(piVar9[0x4d] + iVar5 * 4) = iVar4;
                }
                bVar2 = iVar10 != 3;
                piVar9 = piVar9 + 1;
                iVar10 = iVar10 + 1;
              } while (bVar2);
            }
            inst2[0x25] = iVar5;
            inst2[5] = inst2[5] | 0x40;
            goto LAB_0016c620;
          }
          goto LAB_0016c3e0;
        }
      }
      if (((iVar5 != 0) && (iVar4 = RegKind__flagBit0(inst2[0x26]), iVar4 != 0)) &&
         (((inst2[5] & 2U) == 0 && (iVar4 = (**(code **)(*inst2 + 0x50))(inst2), iVar4 == 0)))) {
        uVar3 = inst2[5];
        if ((uVar3 & 0x20) == 0) {
          schedulerAllocRegEnabled = Compiler__isOptionEnabled(*compiler,0x25);
          if (schedulerAllocRegEnabled != 0) goto LAB_0016c620;
          uVar3 = inst2[5];
        }
        if ((uVar3 & 0x40) == 0) {
          iVar4 = *(int *)(*compiler + 0x3c4) + 1;
          *(int *)(*compiler + 0x3c4) = iVar4;
          inst2[0x25] = iVar4;
        }
      }
    }
LAB_0016c620:
    if (4 < loopIndex) {
      return;
    }
    iVar4 = compiler[0xc];
  } while( true );
}

/* Scheduler__commitBundle @ 0x16c640 (816 bytes) */
int Scheduler__commitBundle(scheduler)
  undefined4 *scheduler;
{
  int listNodeInst;
  int listNode;
  bool moreSlots;
  uint vectorCount;
  undefined4 *predEdgeSlot;
  int bundleRecord;
  int insertAfter;
  int slotIndex;
  uint predEdgeCount;
  int slotNode;
  uint loopIndex;
  int lastCommitted;
  uint *predEdges;
  int *predEdge;
  
  slotIndex = 0;
  ((int (*)())FUN_0016c1fc)(scheduler);
  bundleRecord = scheduler[0xc];
  lastCommitted = 0;
  insertAfter = *(int *)(*(int *)(scheduler[4] + 0xcc) + 4);
  do {
    slotNode = *(int *)(slotIndex * 4 + bundleRecord);
    if (slotNode != 0) {
      lastCommitted = *(int *)(slotNode + 0x38);
      loopIndex = 0;
      Block__appendInst(scheduler[4],lastCommitted);
      ((int (*)())FUN_00165788)(lastCommitted,*scheduler);
      *(uint *)(lastCommitted + 0x14) = *(uint *)(lastCommitted + 0x14) | 4;
      predEdges = *(uint **)(slotNode + 0x44);
      predEdgeCount = predEdges[1];
      if (0 < (int)predEdgeCount) {
        while( true ) {
          if (loopIndex < *predEdges) {
            vectorCount = predEdges[1];
            if (vectorCount <= loopIndex) {
              _memset(vectorCount * 4 + predEdges[2],0,(loopIndex - vectorCount) * 4 + 4);
              predEdges[1] = loopIndex + 1;
            }
            predEdgeSlot = (undefined4 *)(loopIndex * 4 + predEdges[2]);
          }
          else {
            predEdgeSlot = (undefined4 *)Vector__elementRefGrow(predEdges,loopIndex);
          }
          loopIndex = loopIndex + 1;
          predEdge = (int *)*predEdgeSlot;
          if (((predEdge[2] == 0) &&
              (bundleRecord = (**(code **)(**(int **)(*predEdge + 0x38) + 0x5c))(*(int **)(*predEdge + 0x38))
              , bundleRecord != 0)) && (*(int *)(*(int *)(*predEdge + 0x38) + 0x158) == 0)) {
            Block__insertInstAfter(scheduler[4],insertAfter,*(int *)(*predEdge + 0x38));
            *(uint *)(*(int *)(*predEdge + 0x38) + 0x14) =
                 *(uint *)(*(int *)(*predEdge + 0x38) + 0x14) | 4;
            insertAfter = *(int *)(*predEdge + 0x38);
          }
          if (predEdgeCount == loopIndex) break;
          predEdges = *(uint **)(slotNode + 0x44);
        }
      }
      bundleRecord = scheduler[0xc];
    }
    moreSlots = slotIndex != 4;
    slotIndex = slotIndex + 1;
  } while (moreSlots);
  listNode = *(int *)(bundleRecord + 0x1c);
  for (bundleRecord = *(int *)(*(int *)(bundleRecord + 0x1c) + 8); bundleRecord != 0; bundleRecord = *(int *)(bundleRecord + 8)) {
    listNodeInst = *(int *)(listNode + 0x38);
    if ((*(int *)(listNodeInst + 0x98) == 0x45) || (*(int *)(listNodeInst + 0x98) == 0x44)) {
      Block__insertInstAfter(scheduler[4],insertAfter,listNodeInst);
      *(uint *)(listNodeInst + 0x14) = *(uint *)(listNodeInst + 0x14) | 4;
      insertAfter = listNodeInst;
      if (lastCommitted == 0) {
        lastCommitted = listNodeInst;
      }
    }
    else {
      loopIndex = 0;
      Block__appendInst(scheduler[4],listNodeInst);
      ((int (*)())FUN_00165788)(listNodeInst,*scheduler);
      *(uint *)(listNodeInst + 0x14) = *(uint *)(listNodeInst + 0x14) | 4;
      predEdges = *(uint **)(listNode + 0x44);
      predEdgeCount = predEdges[1];
      lastCommitted = listNodeInst;
      if (0 < (int)predEdgeCount) {
        while( true ) {
          if (loopIndex < *predEdges) {
            vectorCount = predEdges[1];
            if (vectorCount <= loopIndex) {
              _memset(vectorCount * 4 + predEdges[2],0,(loopIndex - vectorCount) * 4 + 4);
              predEdges[1] = loopIndex + 1;
            }
            predEdgeSlot = (undefined4 *)(loopIndex * 4 + predEdges[2]);
          }
          else {
            predEdgeSlot = (undefined4 *)Vector__elementRefGrow(predEdges,loopIndex);
          }
          loopIndex = loopIndex + 1;
          predEdge = (int *)*predEdgeSlot;
          if (((predEdge[2] == 0) &&
              (lastCommitted = (**(code **)(**(int **)(*predEdge + 0x38) + 0x5c))
                                  (*(int **)(*predEdge + 0x38)), lastCommitted != 0)) &&
             (*(int *)(*(int *)(*predEdge + 0x38) + 0x158) == 0)) {
            Block__insertInstAfter(scheduler[4],insertAfter,*(int *)(*predEdge + 0x38));
            *(uint *)(*(int *)(*predEdge + 0x38) + 0x14) =
                 *(uint *)(*(int *)(*predEdge + 0x38) + 0x14) | 4;
            insertAfter = *(int *)(*predEdge + 0x38);
          }
          lastCommitted = listNodeInst;
          if (predEdgeCount == loopIndex) break;
          predEdges = *(uint **)(listNode + 0x44);
        }
      }
    }
    listNode = bundleRecord;
  }
  if (lastCommitted != 0) {
    *(uint *)(lastCommitted + 0x14) = *(uint *)(lastCommitted + 0x14) & 0xfffffffb;
  }
  return lastCommitted;
}

