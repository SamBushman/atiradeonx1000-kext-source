#include "decls.h"

/* IROperand__setModifierBits @ 0x103d50 (40 bytes) */
int IROperand__setModifierBits(operandRecord, mask, set)
  int operandRecord;
  uint mask;
  int set;
{
  if (set != 0) {
    *(uint *)(operandRecord + 0x14) = mask | *(uint *)(operandRecord + 0x14);
    return;
  }
  *(uint *)(operandRecord + 0x14) = *(uint *)(operandRecord + 0x14) & ~mask;
  return;
}

/* floatToFixedSaturate @ 0x103d78 (220 bytes) */
int floatToFixedSaturate(undefined4 unusedArg1,int integerBits,uint fractionBits,double value)
{
  float distanceAboveMin;
  double clampedValue;
  float distanceToMax;
  uint halfRange;
  double maxLimit;
  double cappedAtMax;
  double minLimit;
  
  halfRange = 1 << (integerBits - 1U & 0x3f);
  minLimit = (double)(float)((double)CONCAT44(0x43300000,-halfRange ^ 0x80000000) - DOUBLE_001aa1e0);
  maxLimit = (double)((float)((double)CONCAT44(0x43300000,halfRange ^ 0x80000000) - DOUBLE_001aa1e0) +
                  FLOAT_001aa114 /
                  (float)((double)CONCAT44(0x43300000,1 << (fractionBits - 1 & 0x3f) ^ 0x80000000) -
                         DOUBLE_001aa1e0));
  distanceToMax = (float)(maxLimit - value);
  cappedAtMax = value;
  if (distanceToMax < 0.0) {
    cappedAtMax = maxLimit;
  }
  if (-distanceToMax < 0.0) {
    cappedAtMax = value;
  }
  distanceAboveMin = (float)(cappedAtMax - minLimit);
  clampedValue = cappedAtMax;
  if (distanceAboveMin < 0.0) {
    clampedValue = minLimit;
  }
  if (-distanceAboveMin < 0.0) {
    clampedValue = cappedAtMax;
  }
  return (int)(clampedValue * (double)(float)((double)CONCAT44(0x43300000,
                                                        1 << (fractionBits & 0x3f) ^ 0x80000000) -
                                      DOUBLE_001aa1e0));
}

/* constantZeroFloat @ 0x103e54 (28 bytes) */
double constantZeroFloat( void)
{
  return (double)FLOAT_001aa0d4;
}

/* isLessThan2 @ 0x103e70 (16 bytes) */
int isLessThan2(param_1)
  uint param_1;
{
  return param_1 < 2;
}

/* setSelectedConstantWord @ 0x103e84 (56 bytes) */
int setSelectedConstantWord(record, flag)
  int record;
  int flag;
{
  if (flag == 0) {
    *(undefined4 *)(record + 0x10) = DAT_001af9c0;
    return;
  }
  *(undefined4 *)(record + 0x10) = DAT_001af9bc;
  return;
}

/* IRInst__cloneInto @ 0x103ebc (92 bytes) */
int IRInst__cloneInto(srcInst, dstInst, compiler, keepId)
  undefined4 srcInst;
  int dstInst;
  int compiler;
  int keepId;
{
  int newId;
  
  _memcpy(dstInst,srcInst,0x164);
  if (keepId == 0) {
    newId = *(int *)(compiler + 0x324);
    *(int *)(dstInst + 0x14c) = newId;
    *(int *)(compiler + 0x324) = newId + 1;
  }
  return dstInst;
}

/* IRInst__saveCounters @ 0x103f18 (44 bytes) */
int IRInst__saveCounters(inst, snapshot, mask)
  int inst;
  uint *snapshot;
  uint mask;
{
  *snapshot = mask;
  if ((mask & 1) != 0) {
    snapshot[1] = *(uint *)(inst + 0x160);
  }
  if ((*snapshot & 2) == 0) {
    return;
  }
  snapshot[2] = *(uint *)(inst + 0x14c);
  return;
}

/* IRInst__restoreCounters @ 0x103f44 (64 bytes) */
int IRInst__restoreCounters(inst, snapshot)
  int inst;
  uint *snapshot;
{
  uint mask;
  
  mask = *snapshot;
  if ((mask & 1) != 0) {
    *(uint *)(inst + 0x160) = snapshot[1];
    mask = *snapshot;
    snapshot[1] = 0;
  }
  if ((mask & 2) != 0) {
    *(uint *)(inst + 0x14c) = snapshot[2];
  }
  *snapshot = 0;
  snapshot[2] = 0;
  return;
}

/* IRInst__copyBodyFrom @ 0x103f84 (100 bytes) */
int IRInst__copyBodyFrom(dstInst, srcInst)
  undefined4 dstInst;
  undefined4 srcInst;
{
  undefined4 counterSnapshot;
  undefined4 counterSnapshotUseCount;
  undefined4 counterSnapshotInstId;
  
  counterSnapshotInstId = 0;
  counterSnapshot = 0;
  counterSnapshotUseCount = 0;
  ((int (*)())IRInst__saveCounters)(dstInst,&counterSnapshot,0xffffffff);
  _memcpy(dstInst,srcInst,0x164);
  return ((int (*)())IRInst__restoreCounters)(dstInst,&counterSnapshot);
}

/* operandsHaveSameConstant @ 0x103fe8 (52 bytes) */
int operandsHaveSameConstant(instA, instB, operandIndex)
  int instA;
  int instB;
  int operandIndex;
{
  int operandRecordB;
  
  operandRecordB = operandIndex * 0x18 + instB;
  if ((*(int *)(instA + 0x94) == *(int *)(operandRecordB + 0x94)) &&
     (*(int *)(instA + 0x98) == *(int *)(operandRecordB + 0x98))) {
    return 1;
  }
  return 0;
}

/* IRInst__unlinkAndClearFlag0 @ 0x10401c (56 bytes) */
int IRInst__unlinkAndClearFlag0(inst)
  int inst;
{
  DList__unlink(inst);
  *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) & 0xfffffffe;
  return;
}

/* IRInst__useCount @ 0x104054 (24 bytes) */
int IRInst__useCount(obj, program)
  int obj;
  int program;
{
  int count;
  
  count = *(int *)(obj + 0x160) - *(int *)(program + PROG_useEpoch);
  if (-1 < count) {
    return count;
  }
  return 0;
}

/* RegKind__vectorWidthKind @ 0x10406c (68 bytes) */
int RegKind__vectorWidthKind(regKind)
  int regKind;
{
  if ((*(uint *)(PTR_PTR_001e8c60 + regKind * 0x10 + 4) & 0x400) != 0) {
    return 0x16;
  }
  if ((*(uint *)(PTR_PTR_001e8c60 + regKind * 0x10 + 4) & 0x800) == 0) {
    return regKind;
  }
  return 0x15;
}

/* RegKind__laneCount @ 0x1040b0 (84 bytes) */
int RegKind__laneCount(regKind)
  int regKind;
{
  if ((*(uint *)(PTR_PTR_001e8c60 + regKind * 0x10 + 4) & 0x400) != 0) {
    return '\x04';
  }
  if ((*(uint *)(PTR_PTR_001e8c60 + regKind * 0x10 + 4) & 0x800) != 0) {
    return '\x03';
  }
  return (regKind == 7) + '\x01';
}

/* IRLoadInterp__setLaneKindAndIndex @ 0x104104 (124 bytes) */
int IRLoadInterp__setLaneKindAndIndex(inst, lane, kind, indexValue)
  int inst;
  int lane;
  uint kind;
  uint indexValue;
{
  if (lane == 1) {
    *(uint *)(inst + 0x130) = (kind & 0xff) << 0x10 | indexValue & 0xffff;
    return;
  }
  if (lane < 2) {
    if (lane != 0) {
      return;
    }
    *(uint *)(inst + 300) = (kind & 0xff) << 0x10 | indexValue & 0xffff;
    return;
  }
  if (lane == 2) {
    *(uint *)(inst + 0x134) = (kind & 0xff) << 0x10 | indexValue & 0xffff;
    return;
  }
  if (lane != 3) {
    return;
  }
  *(uint *)(inst + 0x138) = (kind & 0xff) << 0x10 | indexValue & 0xffff;
  return;
}

/* IRLoadInterp__laneIndex_104180 @ 0x104180 (80 bytes) */
int IRLoadInterp__laneIndex_104180(inst, lane)
  int inst;
  int lane;
{
  if (lane == 1) {
    return *(undefined2 *)(inst + 0x132);
  }
  if (lane < 2) {
    if (lane == 0) {
      return *(undefined2 *)(inst + 0x12e);
    }
  }
  else {
    if (lane == 2) {
      return *(undefined2 *)(inst + 0x136);
    }
    if (lane == 3) {
      return *(undefined2 *)(inst + 0x13a);
    }
  }
  return 0;
}

/* IRLoadInterp__setLane @ 0x1041d0 (156 bytes) */
int IRLoadInterp__setLane(inst, lane, used, kind, indexValue)
  int inst;
  int lane;
  int used;
  uint kind;
  uint indexValue;
{
  if (lane == 1) {
    *(uint *)(inst + 0x130) = used << 0x18 | (kind & 0xff) << 0x10 | indexValue & 0xffff;
    return;
  }
  if (lane < 2) {
    if (lane != 0) {
      return;
    }
    *(uint *)(inst + 300) = used << 0x18 | (kind & 0xff) << 0x10 | indexValue & 0xffff;
    return;
  }
  if (lane == 2) {
    *(uint *)(inst + 0x134) = used << 0x18 | (kind & 0xff) << 0x10 | indexValue & 0xffff;
    return;
  }
  if (lane != 3) {
    return;
  }
  *(uint *)(inst + 0x138) = used << 0x18 | (kind & 0xff) << 0x10 | indexValue & 0xffff;
  return;
}

/* IRLoadInterp__laneIndex @ 0x10426c (80 bytes) */
int IRLoadInterp__laneIndex(inst, lane)
  int inst;
  int lane;
{
  if (lane == 1) {
    return *(undefined2 *)(inst + 0x132);
  }
  if (lane < 2) {
    if (lane == 0) {
      return *(undefined2 *)(inst + 0x12e);
    }
  }
  else {
    if (lane == 2) {
      return *(undefined2 *)(inst + 0x136);
    }
    if (lane == 3) {
      return *(undefined2 *)(inst + 0x13a);
    }
  }
  return 0;
}

/* IRInst__firstOperandWithSelectNot4 @ 0x1042bc (116 bytes) */
int IRInst__firstOperandWithSelectNot4(inst, componentSlot)
  int *inst;
  int componentSlot;
{
  char selectValue;
  int operandCount;
  int loopIndex;
  char *selectBytePtr;
  
  selectBytePtr = (char *)((int)inst + componentSlot + 0xb4);
  loopIndex = 1;
  while( true ) {
    operandCount = (**(code **)(*inst + 0x14))(inst);
    if (operandCount < loopIndex) {
      return -1;
    }
    selectValue = *selectBytePtr;
    selectBytePtr = selectBytePtr + 0x18;
    if (selectValue != '\x04') break;
    loopIndex = loopIndex + 1;
  }
  return loopIndex;
}

/* IRVertexFetch__initSemantics @ 0x104330 (52 bytes) */
int IRVertexFetch__initSemantics(inst)
  int inst;
{
  *(undefined4 *)(inst + 0xac) = 0;
  *(undefined4 *)(inst + 0x98) = 0;
  *(undefined4 *)(inst + 0xb0) = 0x1f;
  *(undefined4 *)(inst + 0x9c) = DAT_001af9c0;
  return;
}

/* Vslot__outDefaults_0_0_4 @ 0x104364 (24 bytes) */
int Vslot__outDefaults_0_0_4(unusedArg1, outFirst, outSecond, outThird)
  undefined4 unusedArg1;
  undefined4 *outFirst;
  undefined4 *outSecond;
  undefined4 *outThird;
{
  *outFirst = 0;
  *outSecond = 0;
  *outThird = 4;
  return;
}

/* IRInst__vslot28_hasFlag0x4000AndClass0x24 @ 0x10437c (36 bytes) */
int IRInst__vslot28_hasFlag0x4000AndClass0x24(this, program)
  int this;
  int program;
{
  if (((*(uint *)(program + 0x30) & 0x4000) != 0) && (*(int *)(this + 0x98) == 0x24)) {
    return 1;
  }
  return 0;
}

/* instClassTableIsIdentity @ 0x1043a0 (80 bytes) */
int instClassTableIsIdentity()
{
  int storedIndex;
  int *entry;
  int loopIndex;
  int remaining;
  
  loopIndex = 0;
  remaining = 0x15;
  entry = &DAT_001ea500;
  do {
    storedIndex = *entry;
    entry = entry + 2;
    if (storedIndex != loopIndex) {
      return 0;
    }
    loopIndex = loopIndex + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  return 1;
}

/* IRInst__create @ 0x1043f0 (108 bytes) */
int IRInst__create(opcode, compiler)
  undefined4 opcode;
  undefined4 compiler;
{
  int inst;
  undefined4 opcodeInfo;
  
  inst = OpcodeTraits__getInstClass(opcode,compiler);
  inst = (**(code **)(&DAT_001ea4fc + inst * 8))(opcode,compiler);
  opcodeInfo = Opcode__getInfo(opcode);
  *(undefined4 *)(inst + 0x88) = opcodeInfo;
  return inst;
}

/* IRInst__clone @ 0x10445c (132 bytes) */
int IRInst__clone(srcInst, compiler, keepId)
  undefined4 srcInst;
  int compiler;
  int keepId;
{
  int newId;
  undefined4 *newBlock;
  
  newBlock = (undefined4 *)Arena__alloc(*(undefined4 *)(compiler + COMP_arenaA),0x168);
  *newBlock = *(undefined4 *)(compiler + COMP_arenaA);
  _memcpy(newBlock + 1,srcInst,0x164);
  if (keepId == 0) {
    newId = *(int *)(compiler + COMP_nextInstId);
    newBlock[0x54] = newId;
    *(int *)(compiler + COMP_nextInstId) = newId + 1;
  }
  newBlock[0x57] = 0;
  newBlock[3] = 0;
  newBlock[2] = 0;
  return newBlock + 1;
}

/* IRInst__replaceExtraData @ 0x1044e0 (60 bytes) */
int IRInst__replaceExtraData(param_1, newData, compiler)
  int param_1;
  undefined4 newData;
  int compiler;
{
  Arena__free(*(undefined4 *)(compiler + COMP_arenaA),*(undefined4 *)(param_1 + 0x13c));
  *(undefined4 *)(param_1 + 0x13c) = newData;
  return;
}

/* IRInst__allSelectsAreHwConstants @ 0x10453c (168 bytes) */
int IRInst__allSelectsAreHwConstants(inst, compiler, selectBytes, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  int inst;
  int compiler;
  undefined4 selectBytes;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  unsigned int ghidra_home[8] = { inst, compiler, selectBytes, unusedArg4, unusedArg5, unusedArg6, unusedArg7, 0 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  uint selectValue;
  int isHwConstant;
  undefined4 result;
  byte *selectPtr;
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = selectBytes;
  if (*(int *)(inst + 0x98) == 0x33) {
    selectPtr = (byte *)&(*(unsigned int *)((unsigned char *)ghidra_home + 8));
    do {
      selectValue = (uint)*selectPtr;
      if ((selectValue != 4) &&
         ((((int)*(char *)(inst + 0x15c) >> (selectValue & 0x3f) & 1U) == 0 ||
          (isHwConstant = (**(code **)(**(int **)(compiler + 0x30c) + 0xf0))
                             ((double)*(float *)(selectValue * 0x18 + inst + 0x20)), isHwConstant == 0))))
      goto LAB_001045cc;
      selectPtr = selectPtr + 1;
    } while (selectPtr != &(*(unsigned int *)((unsigned char *)ghidra_home + 12)));
    result = 1;
  }
  else {
LAB_001045cc:
    result = 0;
  }
  return result;
}

/* IRInst__isProjectionOfClass26or3a @ 0x1045e4 (96 bytes) */
int IRInst__isProjectionOfClass26or3a(this)
  int *this;
{
  int isProjection;
  undefined4 result;
  
  isProjection = (**(code **)(*this + 0x54))(this);
  result = 0;
  if ((isProjection != 0) && ((this[0x26] == 0x26 || (this[0x26] == 0x3a)))) {
    result = 1;
  }
  return result;
}

/* IRInst__isProjectionOfClass44 @ 0x104644 (88 bytes) */
int IRInst__isProjectionOfClass44(this)
  int *this;
{
  int isProjection;
  undefined4 result;
  
  isProjection = (**(code **)(*this + 0x54))(this);
  if ((isProjection == 0) || (result = 1, this[0x26] != 0x44)) {
    result = 0;
  }
  return result;
}

/* IRInst__setHardwareRegisterAndAdd @ 0x10469c (44 bytes) */
int IRInst__setHardwareRegisterAndAdd(inst, program, regKind, regNumber)
  int inst;
  undefined4 program;
  undefined4 regKind;
  undefined4 regNumber;
{
  *(undefined4 *)(inst + 0x94) = regNumber;
  *(undefined4 *)(inst + 0x98) = regKind;
  *(uint *)(inst + 0x14) = *(uint *)(inst + 0x14) | 0x42;
  *(undefined4 *)(inst + 0x80) = 0;
  return Program__addInst(program,inst);
}

/* IRInst__setOperandRef @ 0x1046c8 (104 bytes) */
int IRInst__setOperandRef(inst, operandIndex, operandRef)
  int inst;
  int operandIndex;
  int *operandRef;
{
  int refWord2;
  int record;
  undefined4 destKind;
  
  record = operandIndex * 0x18 + inst;
  *(int *)(record + 0x98) = operandRef[1];
  refWord2 = operandRef[2];
  *(int **)(record + 0x8c) = operandRef;
  *(int *)(record + 0x94) = refWord2;
  if (operandIndex == 0) {
    destKind = (**(code **)(*operandRef + 0x24))(operandRef);
    *(undefined4 *)(inst + 0x128) = destKind;
  }
  return;
}

/* IROperand__copyFrom @ 0x104730 (120 bytes) */
int IROperand__copyFrom(dstOperand, srcOperand)
  undefined4 *dstOperand;
  undefined4 *srcOperand;
{
  undefined4 word0;
  undefined4 word1;
  undefined4 word3;
  undefined4 word2;
  
  ((int (*)())IROperand__setModifierBits)(dstOperand,1,srcOperand[5] & 1);
  ((int (*)())IROperand__setModifierBits)(dstOperand,2,(uint)srcOperand[5] >> 1 & 1);
  word0 = *srcOperand;
  word1 = srcOperand[1];
  word2 = srcOperand[2];
  word3 = srcOperand[3];
  dstOperand[4] = srcOperand[4];
  *dstOperand = word0;
  dstOperand[1] = word1;
  dstOperand[2] = word2;
  dstOperand[3] = word3;
  return;
}

/* IROperand__copyModifiersAndSelect @ 0x1047a8 (88 bytes) */
int IROperand__copyModifiersAndSelect(dstOperand, srcOperand)
  int dstOperand;
  int srcOperand;
{
  ((int (*)())IROperand__setModifierBits)(dstOperand,1,*(uint *)(srcOperand + 0x14) & 1);
  ((int (*)())IROperand__setModifierBits)(dstOperand,2,*(uint *)(srcOperand + 0x14) >> 1 & 1);
  *(undefined4 *)(dstOperand + 0x10) = *(undefined4 *)(srcOperand + 0x10);
  return;
}

/* Inst__isBeforeOrSame @ 0x104800 (92 bytes) */
int Inst__isBeforeOrSame(instA, instB)
  int instA;
  int instB;
{
  int cursor;
  undefined4 blockOrder;
  
  if (*(int *)(instA + 0x158) != *(int *)(instB + 0x158)) {
    blockOrder = Block__isAncestorOf(*(int *)(instA + 0x158),*(int *)(instB + 0x158));
    return blockOrder;
  }
  if (instA != instB) {
    cursor = *(int *)(instB + 4);
    while( true ) {
      if (cursor == 0) {
        return 0;
      }
      if (instA == cursor) break;
      cursor = *(int *)(cursor + 4);
    }
  }
  return 1;
}

/* Inst__nearestCommonAncestorBlock @ 0x10485c (120 bytes) */
int Inst__nearestCommonAncestorBlock(instA, instB)
  int instA;
  int instB;
{
  int isBefore;
  undefined4 commonBlock;
  int result;
  
  isBefore = ((int (*)())Inst__isBeforeOrSame)(instA,instB);
  result = instA;
  if ((isBefore == 0) && (isBefore = ((int (*)())Inst__isBeforeOrSame)(instB,instA), result = instB, isBefore == 0)) {
    commonBlock = Block__nearestCommonAncestor(*(undefined4 *)(instA + 0x158),*(undefined4 *)(instB + 0x158));
    result = Block__resolveRedirect(commonBlock);
    return result;
  }
  return result;
}

/* IRInst__setExtraFixed3_4_1048d4 @ 0x1048d4 (56 bytes) */
void IRInst__setExtraFixed3_4_1048d4(int inst,double value)
{
  undefined2 fixedValue;
  int extraData;
  
  extraData = *(int *)(inst + 0x13c);
  fixedValue = ((int (*)())floatToFixedSaturate)(inst,3,4,value);
  *(undefined2 *)(extraData + 0x18) = fixedValue;
  return;
}

/* IRInst__setExtraFixed3_4_10490c @ 0x10490c (56 bytes) */
void IRInst__setExtraFixed3_4_10490c(int inst,double value)
{
  undefined2 fixedValue;
  int extraData;
  
  extraData = *(int *)(inst + 0x13c);
  fixedValue = ((int (*)())floatToFixedSaturate)(inst,3,4,value);
  *(undefined2 *)(extraData + 0x18) = fixedValue;
  return;
}

/* IRInst__setExtraFixed3_4_104944 @ 0x104944 (56 bytes) */
void IRInst__setExtraFixed3_4_104944(int inst,double value)
{
  undefined2 fixedValue;
  int extraData;
  
  extraData = *(int *)(inst + 0x13c);
  fixedValue = ((int (*)())floatToFixedSaturate)(inst,3,4,value);
  *(undefined2 *)(extraData + 0x18) = fixedValue;
  return;
}

/* IRInst__hasSingleUse @ 0x10497c (36 bytes) */
int IRInst__hasSingleUse(obj, program)
  int obj;
  int program;
{
  int useCount;
  
  useCount = *(int *)(obj + 0x160) - *(int *)(program + PROG_useEpoch);
  if (useCount < 0) {
    useCount = 0;
  }
  return useCount == 1;
}

/* IRInst__hasTwoUses @ 0x1049a0 (36 bytes) */
int IRInst__hasTwoUses(inst, program)
  int inst;
  int program;
{
  int useCount;
  
  useCount = *(int *)(inst + 0x160) - *(int *)(program + 0x478);
  if (useCount < 0) {
    useCount = 0;
  }
  return useCount == 2;
}

/* IRInst__hasNoUses @ 0x1049c4 (36 bytes) */
int IRInst__hasNoUses(inst, program, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  int inst;
  int program;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  return *(int *)(inst + 0x160) - *(int *)(program + 0x478) < 0 ||
         *(int *)(inst + 0x160) == *(int *)(program + 0x478);
}

/* IRInst__appendSource @ 0x1049e8 (172 bytes) */
int IRInst__appendSource(inst, operandRef)
  int *inst;
  int operandRef;
{
  int flagsAddr;
  int oldCount;
  int newCount;
  int virtualCallResult;
  
  oldCount = inst[0x21];
  ((int (*)())IRInst__setOperandRef)(inst,oldCount + 1,operandRef);
  newCount = inst[0x21];
  inst[0x21] = newCount + 1;
  if (((0 < inst[0x20]) && (operandRef == inst[0x23])) &&
     (virtualCallResult = (**(code **)(*inst + 0x14))(inst), flagsAddr = DAT_001af9bc, virtualCallResult < newCount + 1)) {
    inst[5] = inst[5] | 0x200;
    inst[(oldCount + 1) * 6 + 0x27] = flagsAddr;
  }
  return;
}

/* IRLoadInterp__laneUsed @ 0x104a94 (80 bytes) */
int IRLoadInterp__laneUsed(inst, lane)
  int inst;
  int lane;
{
  if (lane == 1) {
    return *(undefined1 *)(inst + 0x130);
  }
  if (lane < 2) {
    if (lane == 0) {
      return *(undefined1 *)(inst + 300);
    }
  }
  else {
    if (lane == 2) {
      return *(undefined1 *)(inst + 0x134);
    }
    if (lane == 3) {
      return *(undefined1 *)(inst + 0x138);
    }
  }
  return 0;
}

/* IRLoadInterp__laneSelects @ 0x104ae4 (136 bytes) */
int IRLoadInterp__laneSelects(outSelects, inst)
  undefined1 *outSelects;
  undefined4 inst;
{
  bool moreLanes;
  int used;
  int lane;
  undefined1 *outCursor;
  
  lane = 0;
  outCursor = outSelects;
  do {
    used = ((int (*)())IRLoadInterp__laneUsed)(inst,lane);
    if (used == 1) {
      *outCursor = 5;
    }
    else if (used == 2) {
      *outCursor = 6;
    }
    else {
      *outCursor = 4;
    }
    moreLanes = lane != 3;
    outCursor = outCursor + 1;
    lane = lane + 1;
  } while (moreLanes);
  return outSelects;
}

/* IRLoadInterp__laneKind @ 0x104b6c (80 bytes) */
int IRLoadInterp__laneKind(inst, lane)
  int inst;
  int lane;
{
  if (lane == 1) {
    return *(undefined1 *)(inst + 0x131);
  }
  if (lane < 2) {
    if (lane == 0) {
      return *(undefined1 *)(inst + 0x12d);
    }
  }
  else {
    if (lane == 2) {
      return *(undefined1 *)(inst + 0x135);
    }
    if (lane == 3) {
      return *(undefined1 *)(inst + 0x139);
    }
  }
  return 0;
}

/* IROperand__init @ 0x104bbc (44 bytes) */
int IROperand__init(operand)
  undefined4 *operand;
{
  operand[3] = 0x46;
  operand[5] = operand[5] & 0xfffffffc;
  operand[1] = 0;
  operand[2] = 0xffffffff;
  *operand = 0;
  return;
}

/* IRInst__initOperandRecord @ 0x104be8 (16 bytes) */
int IRInst__initOperandRecord(inst, operandIndex)
  int inst;
  int operandIndex;
{
  return ((int (*)())IROperand__init)(operandIndex * 0x18 + inst + 0x8c);
}

/* IRInst__resetFields @ 0x104bf8 (324 bytes) */
int IRInst__resetFields(inst, compiler)
  int inst;
  undefined4 compiler;
{
  int loopIndex;
  bool moreOperands;
  uint laneBit;
  undefined4 defaultRecordWord;
  int instFlagBit2Result;
  undefined4 *defaultWordPtr;
  uint lane;
  int remainingLanes;
  int recordCursor;
  
  *(undefined4 *)(inst + 0x11c) = 0;
  *(undefined4 *)(inst + 0x80) = 0;
  *(undefined4 *)(inst + 0x84) = 0;
  *(undefined4 *)(inst + 0x10) = 0;
  ((int (*)())IRInst__initOperandRecord)(inst,0);
  defaultRecordWord = DAT_001af9bc;
  *(undefined4 *)(inst + 0x9c) = DAT_001af9c0;
  *(undefined4 *)(inst + 0x154) = defaultRecordWord;
  *(undefined4 *)(inst + 0xc) = 0;
  loopIndex = 1;
  recordCursor = inst;
  do {
    ((int (*)())IRInst__initOperandRecord)(inst,loopIndex);
    *(undefined4 *)(recordCursor + 0xb4) = DAT_001af9bc;
    instFlagBit2Result = OpcodeTraits__instFlagBit2(compiler,inst);
    if (instFlagBit2Result != 0) {
      if (loopIndex == 1) {
        defaultWordPtr = &DAT_001af9d0;
      }
      else {
        defaultWordPtr = &DAT_001af9cc;
      }
      *(undefined4 *)(recordCursor + 0xb4) = *defaultWordPtr;
    }
    moreOperands = loopIndex != 4;
    recordCursor = recordCursor + 0x18;
    loopIndex = loopIndex + 1;
  } while (moreOperands);
  *(undefined4 *)(inst + 0x124) = 0;
  lane = 0;
  *(undefined4 *)(inst + 0x120) = 0;
  remainingLanes = 4;
  recordCursor = inst;
  do {
    *(undefined4 *)(recordCursor + 0x1c) = 0;
    laneBit = lane & 0x3f;
    *(undefined4 *)(recordCursor + 0x20) = 0;
    lane = lane + 1;
    recordCursor = recordCursor + 0x18;
    *(byte *)(inst + 0x15c) = *(byte *)(inst + 0x15c) & ~(byte)(1 << laneBit);
    remainingLanes = remainingLanes + -1;
  } while (remainingLanes != 0);
  *(undefined4 *)(inst + 300) = 0;
  *(undefined4 *)(inst + 0x148) = 0;
  *(undefined4 *)(inst + 0x130) = 0;
  *(undefined4 *)(inst + 0x134) = 0;
  *(undefined4 *)(inst + 0x138) = 0;
  *(undefined4 *)(inst + 0x13c) = 0;
  *(undefined4 *)(inst + 0x140) = 0;
  *(undefined4 *)(inst + 0x144) = 0;
  return;
}

/* IRInst__readLastOperand @ 0x104d3c (44 bytes) */
int IRInst__readLastOperand(inst, out)
  int inst;
  int out;
{
  *(undefined4 *)(out + 4) = *(undefined4 *)(*(int *)(inst + 0x84) * 0x18 + inst + 0x90);
  *(undefined4 *)(out + 0x10) =
       *(undefined4 *)(*(int *)(inst + 0x84) * 0x18 + inst + 0x9c);
  return;
}

/* IRInst__applyChannelMask @ 0x104d68 (184 bytes) */
int IRInst__applyChannelMask(inst, channelBytes)
  int *inst;
  char *channelBytes;
{
  bool moreChannels;
  int operandCount;
  int *channelFlagPtr;
  int loopIndex;
  int operandIndex;
  
  loopIndex = 0;
  channelFlagPtr = inst + 0x27;
  do {
    if (*channelBytes == '\0') {
      *(undefined1 *)channelFlagPtr = 1;
      for (operandIndex = 1; operandCount = (**(code **)(*inst + 0x14))(inst), operandIndex <= operandCount;
          operandIndex = operandIndex + 1) {
        (**(code **)(*inst + 0x88))(inst,operandIndex,loopIndex,4);
      }
    }
    else {
      *(undefined1 *)channelFlagPtr = 0;
    }
    moreChannels = loopIndex != 3;
    channelFlagPtr = (int *)((int)channelFlagPtr + 1);
    channelBytes = channelBytes + 1;
    loopIndex = loopIndex + 1;
  } while (moreChannels);
  return;
}

/* IRLoadConst__removeFromListEx @ 0x104e20 (196 bytes) */
int IRLoadConst__removeFromListEx(this, unusedArg2, compiler)
  int this;
  undefined4 unusedArg2;
  int compiler;
{
  int instKind;
  uint flags;
  int nextInst;
  
  instKind = *(int *)(this + 0x98);
  if (instKind == 0xc) {
    ConstRecord__findInTable(*(undefined4 *)(*(int *)(compiler + COMP_currentProgram) + 0x3ac),this);
    instKind = *(int *)(this + 0x98);
  }
  if ((instKind != 2) && (instKind != 0x33)) {
    nextInst = *(int *)(this + 4);
    instKind = *(int *)(*(int *)(compiler + COMP_currentProgram) + 0x3a0);
    if (this == *(int *)(instKind + 300)) {
      *(int *)(instKind + 300) = nextInst;
    }
    flags = *(uint *)(this + 0x14);
    if ((((flags & 4) == 0) && (nextInst != 0)) && ((*(uint *)(nextInst + 0x14) & 4) != 0)) {
      *(uint *)(nextInst + 0x14) = *(uint *)(nextInst + 0x14) & 0xfffffffb;
      flags = *(uint *)(this + 0x14);
    }
    *(uint *)(this + 0x14) = flags & 0xfffffffe;
    DList__unlink(this);
    return;
  }
  return;
}

/* IRLoadInterp__laneKind_104ee4 @ 0x104ee4 (80 bytes) */
int IRLoadInterp__laneKind_104ee4(inst, lane)
  int inst;
  int lane;
{
  if (lane == 1) {
    return *(undefined1 *)(inst + 0x131);
  }
  if (lane < 2) {
    if (lane == 0) {
      return *(undefined1 *)(inst + 0x12d);
    }
  }
  else {
    if (lane == 2) {
      return *(undefined1 *)(inst + 0x135);
    }
    if (lane == 3) {
      return *(undefined1 *)(inst + 0x139);
    }
  }
  return 0;
}

/* IRInst__switchOpcodeVariant @ 0x104f34 (156 bytes) */
int IRInst__switchOpcodeVariant(inst, flag)
  int inst;
  int flag;
{
  int opcode;
  undefined4 opcodeInfo;
  
  if (flag == 0) {
    opcode = *(int *)(*(int *)(inst + 0x88) + 8);
    if (opcode == 0x2b) {
      opcodeInfo = Opcode__getInfo(0xa6);
      *(undefined4 *)(inst + 0x88) = opcodeInfo;
    }
    else if (opcode == 99) {
      opcodeInfo = Opcode__getInfo(100);
      *(undefined4 *)(inst + 0x88) = opcodeInfo;
    }
  }
  else {
    opcode = *(int *)(*(int *)(inst + 0x88) + 8);
    if (opcode == 0xa6) {
      opcodeInfo = Opcode__getInfo(0x2b);
      *(undefined4 *)(inst + 0x88) = opcodeInfo;
    }
    else if (opcode == 100) {
      opcodeInfo = Opcode__getInfo(99);
      *(undefined4 *)(inst + 0x88) = opcodeInfo;
    }
  }
  return;
}

/* IRInst__opcodeIsInSet @ 0x104fd0 (92 bytes) */
int IRInst__opcodeIsInSet(inst)
  int inst;
{
  int opcode;
  
  opcode = *(int *)(*(int *)(inst + 0x88) + 8);
  if (opcode < 0xae) {
    if ((0xaa < opcode) || ((0x23 < opcode && ((opcode < 0x27 || (opcode == 0x9d)))))) {
      return 1;
    }
  }
  else if (0xeb < opcode) {
    if (opcode < 0xef) {
      return 1;
    }
    if (opcode - 0xf2U < 3) {
      return 1;
    }
  }
  return 0;
}

/* IRInst__ctor_10502c @ 0x10502c (312 bytes) */
int IRInst__ctor_10502c(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  int compiler;
{
  int flagWordIndex;
  int instructionId;
  undefined4 *flagWordCursor;
  undefined4 *allocation;
  undefined4 vectorData;
  undefined4 arena;
  bool moreFlagWords;
  undefined4 opcodeInfo;
  undefined4 *operandRecordCursor;
  int operandCountdown;
  
  this[0x1f] = 0;
  this[1] = 0;
  this[2] = 0;
  *this = &PTR_FUN_001e9fc8;
  operandCountdown = 5;
  operandRecordCursor = this + 0x23;
  do {
    *operandRecordCursor = 0;
    operandRecordCursor[1] = 0;
    operandRecordCursor[5] = 0;
    operandRecordCursor = operandRecordCursor + 6;
    operandCountdown = operandCountdown + -1;
  } while (operandCountdown != 0);
  instructionId = *(int *)(compiler + COMP_nextInstId);
  this[0x53] = instructionId;
  *(int *)(compiler + COMP_nextInstId) = instructionId + 1;
  this[0x58] = 0;
  flagWordIndex = 0;
  this[0x54] = 0;
  this[0x56] = 0;
  *(undefined1 *)(this + 0x57) = 0;
  flagWordCursor = this;
  do {
    moreFlagWords = flagWordIndex != 1;
    flagWordCursor[5] = 0;
    flagWordIndex = flagWordIndex + 1;
    flagWordCursor = flagWordCursor + 1;
  } while (moreFlagWords);
  opcodeInfo = Opcode__getInfo(opcode);
  this[0x22] = opcodeInfo;
  this[5] = this[5] | 1;
  ((int (*)())IRInst__resetFields)(this,compiler);
  (*(code *)**(undefined4 **)this[0x22])((undefined4 *)this[0x22],this,compiler);
  if ((*(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) & 0x80) != 0) {
    arena = *(undefined4 *)(compiler + COMP_arenaB);
    allocation = (undefined4 *)Arena__alloc(arena,0x14);
    *allocation = arena;
    allocation[1] = 2;
    allocation[2] = 0;
    allocation[4] = arena;
    vectorData = Arena__alloc(arena,8);
    allocation[3] = vectorData;
    this[4] = allocation + 1;
  }
  return;
}

/* IRInst__ctor_1051b0 @ 0x1051b0 (312 bytes) */
int IRInst__ctor_1051b0(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  int compiler;
{
  int flagWordIndex;
  int instructionId;
  undefined4 *flagWordCursor;
  undefined4 *allocation;
  undefined4 vectorData;
  undefined4 arena;
  bool moreFlagWords;
  undefined4 opcodeInfo;
  undefined4 *operandRecordCursor;
  int operandCountdown;
  
  this[0x1f] = 0;
  this[1] = 0;
  this[2] = 0;
  *this = &PTR_FUN_001e9fc8;
  operandCountdown = 5;
  operandRecordCursor = this + 0x23;
  do {
    *operandRecordCursor = 0;
    operandRecordCursor[1] = 0;
    operandRecordCursor[5] = 0;
    operandRecordCursor = operandRecordCursor + 6;
    operandCountdown = operandCountdown + -1;
  } while (operandCountdown != 0);
  instructionId = *(int *)(compiler + COMP_nextInstId);
  this[0x53] = instructionId;
  *(int *)(compiler + COMP_nextInstId) = instructionId + 1;
  this[0x58] = 0;
  flagWordIndex = 0;
  this[0x54] = 0;
  this[0x56] = 0;
  *(undefined1 *)(this + 0x57) = 0;
  flagWordCursor = this;
  do {
    moreFlagWords = flagWordIndex != 1;
    flagWordCursor[5] = 0;
    flagWordIndex = flagWordIndex + 1;
    flagWordCursor = flagWordCursor + 1;
  } while (moreFlagWords);
  opcodeInfo = Opcode__getInfo(opcode);
  this[0x22] = opcodeInfo;
  this[5] = this[5] | 1;
  ((int (*)())IRInst__resetFields)(this,compiler);
  (*(code *)**(undefined4 **)this[0x22])((undefined4 *)this[0x22],this,compiler);
  if ((*(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) & 0x80) != 0) {
    arena = *(undefined4 *)(compiler + COMP_arenaB);
    allocation = (undefined4 *)Arena__alloc(arena,0x14);
    *allocation = arena;
    allocation[1] = 2;
    allocation[2] = 0;
    allocation[4] = arena;
    vectorData = Arena__alloc(arena,8);
    allocation[3] = vectorData;
    this[4] = allocation + 1;
  }
  return;
}

/* IRInst__setOperandSourceRaw @ 0x105334 (152 bytes) */
int IRInst__setOperandSourceRaw(inst, operandIndex, source, compiler)
  int inst;
  int operandIndex;
  undefined4 source;
  int compiler;
{
  int *extraSlotRef;
  uint instVectorAt118Count;
  uint *instVectorAt118;
  undefined4 *allocation;
  int *newExtraSlotRef;
  uint extraVectorCount;
  undefined4 arena;
  uint extraSlotIndex;
  uint *extraOperandVector;
  
  if (operandIndex < 5) {
    *(undefined4 *)(operandIndex * 0x18 + inst + 0x90) = source;
  }
  else {
    extraOperandVector = *(uint **)(inst + 0x118);
    if (extraOperandVector == (uint *)0x0) {
      arena = *(undefined4 *)(compiler + COMP_arenaA);
      allocation = (undefined4 *)Arena__alloc(arena,0x14);
      extraOperandVector = allocation + 1;
      *allocation = arena;
      allocation[1] = 2;
      allocation[2] = 0;
      allocation[4] = arena;
      arena = Arena__alloc(arena,8);
      allocation[3] = arena;
      *(uint **)(inst + 0x118) = extraOperandVector;
    }
    if ((int)extraOperandVector[1] < (int)(operandIndex - 4U)) {
      arena = *(undefined4 *)(compiler + COMP_arenaA);
      allocation = (undefined4 *)Arena__alloc(arena,0x1c);
      *allocation = arena;
      allocation[1] = 0;
      allocation[2] = 0;
      allocation[6] = 0;
      instVectorAt118 = *(uint **)(inst + 0x118);
      instVectorAt118Count = instVectorAt118[1];
      if (instVectorAt118Count < *instVectorAt118) {
        _memset((void *)(instVectorAt118Count * 4 + instVectorAt118[2]),0,4);
        newExtraSlotRef = (int *)(instVectorAt118Count * 4 + instVectorAt118[2]);
        instVectorAt118[1] = instVectorAt118Count + 1;
      }
      else {
        newExtraSlotRef = (int *)Vector__elementRefGrow(instVectorAt118,instVectorAt118Count);
      }
      *newExtraSlotRef = (int)(allocation + 1);
      ((int (*)())setSelectedConstantWord)(allocation + 1,operandIndex);
      extraOperandVector = *(uint **)(inst + 0x118);
    }
    extraSlotIndex = operandIndex - 5;
    if (extraSlotIndex < *extraOperandVector) {
      extraVectorCount = extraOperandVector[1];
      if (extraVectorCount <= extraSlotIndex) {
        _memset((void *)(extraVectorCount * 4 + extraOperandVector[2]),0,(extraSlotIndex - extraVectorCount) * 4 + 4);
        extraOperandVector[1] = operandIndex - 4U;
      }
      extraSlotRef = (int *)(extraSlotIndex * 4 + extraOperandVector[2]);
    }
    else {
      extraSlotRef = (int *)Vector__elementRefGrow(extraOperandVector,extraSlotIndex);
    }
    *(undefined4 *)(*extraSlotRef + 4) = source;
  }
  return;
}

/* IRInst__getOperandRecord @ 0x1054ec (168 bytes) */
int IRInst__getOperandRecord(inst, operandIndex)
  int inst;
  int operandIndex;
{
  int record;
  uint count;
  int *elementRef;
  uint extraIndex;
  uint *vectorHeader;
  
  if (operandIndex < 5) {
    record = operandIndex * 0x18 + inst + 0x8c;
  }
  else {
    vectorHeader = *(uint **)(inst + 0x118);
    extraIndex = operandIndex - 5;
    if (extraIndex < *vectorHeader) {
      count = vectorHeader[1];
      if (count <= extraIndex) {
        _memset(count * 4 + vectorHeader[2],0,(extraIndex - count) * 4 + 4);
        vectorHeader[1] = operandIndex - 4;
      }
      elementRef = (int *)(extraIndex * 4 + vectorHeader[2]);
    }
    else {
      elementRef = (int *)Vector__elementRefGrow(vectorHeader,extraIndex);
    }
    record = *elementRef;
  }
  return record;
}

/* IRInst__getOperandSource @ 0x105594 (56 bytes) */
int IRInst__getOperandSource(inst, operandIndex)
  undefined4 inst;
  undefined4 operandIndex;
{
  int record;
  
  record = ((int (*)())IRInst__getOperandRecord)(inst,operandIndex);
  if ((record == 0) || (record = *(int *)(record + 4), record == 0)) {
    record = 0;
  }
  return record;
}

/* IRInst__isProjectionOfOpcode2a @ 0x1055cc (128 bytes) */
int IRInst__isProjectionOfOpcode2a(this)
  int *this;
{
  int operandSource;
  int isProjection;
  bool result;
  
  isProjection = (**(code **)(*this + 0x54))(this);
  result = false;
  if (isProjection != 0) {
    operandSource = ((int (*)())IRInst__getOperandSource)(this,1);
    if (operandSource == 0) {
      result = this[0x2c] == 0x2a;
    }
    else {
      result = *(int *)(operandSource + 0x98) == 0x2a;
    }
  }
  return result;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_0010437c");
asm(".set FUN_0010437c, _IRInst__vslot28_hasFlag0x4000AndClass0x24");
asm(".globl FUN_00104e20");
asm(".set FUN_00104e20, _IRLoadConst__removeFromListEx");
