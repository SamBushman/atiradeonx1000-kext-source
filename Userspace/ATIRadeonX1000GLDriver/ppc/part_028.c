#include "decls.h"

/* IRInst__deleteIfUnused @ 0x10564c (584 bytes) */
int IRInst__deleteIfUnused(inst, compiler, sourcesReleased)
  int *inst;
  int compiler;
  int sourcesReleased;
{
  int countValue;
  int isDeletable;
  int sourceDef;
  int useCount;
  int loopIndex;
  int operandCount;
  undefined4 result;
  int *sourceInst;
  int operandIndex;
  int *grandSourceInst;
  int operandVReg;
  int childOperandIndex;
  
  useCount = IRInst__useCount(inst,*(undefined4 *)(compiler + 0x6c4));
  result = 0;
  if (useCount == 0) {
    if (sourcesReleased == 0) {
      operandCount = inst[0x21];
      operandIndex = 1;
      if (0 < operandCount) {
        do {
          sourceDef = IRInst__getOperandSource(inst,operandIndex);
          operandCount = inst[0x21];
          operandIndex = operandIndex + 1;
          *(int *)(sourceDef + 0x160) = *(int *)(sourceDef + 0x160) + -1;
        } while (operandIndex <= operandCount);
      }
    }
    else {
      operandCount = inst[0x21];
    }
    if (0 < operandCount) {
      loopIndex = 1;
      do {
        sourceInst = (int *)IRInst__getOperandSource(inst,loopIndex);
        isDeletable = (**(code **)(*sourceInst + 0x5c))(sourceInst);
        if ((isDeletable != 0) || (isDeletable = (**(code **)(*sourceInst + 0x60))(sourceInst), isDeletable != 0)) {
          childOperandIndex = 1;
          countValue = IRInst__useCount(sourceInst,*(undefined4 *)(compiler + 0x6c4));
          if (countValue == 0) {
            for (; countValue = (**(code **)(*sourceInst + 0x14))(sourceInst), childOperandIndex <= countValue; childOperandIndex = childOperandIndex + 1) {
              grandSourceInst = (int *)IRInst__getOperandSource(sourceInst,childOperandIndex);
              grandSourceInst[0x58] = grandSourceInst[0x58] + -1;
              countValue = (**(code **)(*grandSourceInst + 0x5c))(grandSourceInst);
              if ((countValue != 0) &&
                 (countValue = IRInst__useCount(grandSourceInst,*(undefined4 *)(compiler + 0x6c4)), countValue == 0)) {
                (**(code **)(*sourceInst + 0x60))(sourceInst);
                for (countValue = 1; operandVReg = (**(code **)(*grandSourceInst + 0x14))(grandSourceInst), countValue <= operandVReg;
                    countValue = countValue + 1) {
                  operandVReg = IRInst__getOperandSource(grandSourceInst,countValue);
                  *(int *)(operandVReg + 0x160) = *(int *)(operandVReg + 0x160) + -1;
                }
                (**(code **)(*grandSourceInst + 0xc))(grandSourceInst,sourcesReleased,compiler);
              }
            }
            (**(code **)(*sourceInst + 0xc))(sourceInst,sourcesReleased,compiler);
          }
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex <= inst[0x21]);
    }
    (**(code **)(*inst + 0xc))(inst,sourcesReleased,compiler);
    result = 1;
  }
  return result;
}

/* IRInst__dropCounterAndDeleteIfUnused @ 0x105894 (20 bytes) */
int IRInst__dropCounterAndDeleteIfUnused(inst, arg)
  int inst;
  undefined4 arg;
{
  undefined4 uVar1;
  
  *(int *)(inst + 0x160) = *(int *)(inst + 0x160) + -1;
  uVar1 = ((int (*)())IRInst__deleteIfUnused)(inst,arg,0);
  return uVar1;
}

/* IRInst__decrementSourceUseCounts @ 0x1058a8 (136 bytes) */
int IRInst__decrementSourceUseCounts(inst, program)
  int inst;
  int program;
{
  int operandVReg;
  int operandIndex;
  
  if (((*(uint *)(program + 0x30) & 0x80) != 0) && (operandIndex = 1, 0 < *(int *)(inst + 0x84))) {
    do {
      operandVReg = IRInst__getOperandSource(inst,operandIndex);
      if (operandVReg != 0) {
        operandVReg = IRInst__getOperandSource(inst,operandIndex);
        *(int *)(operandVReg + 0x160) = *(int *)(operandVReg + 0x160) + -1;
      }
      operandIndex = operandIndex + 1;
    } while (operandIndex <= *(int *)(inst + 0x84));
  }
  return;
}

/* IRInst__removeFromSourceUserLists @ 0x105930 (276 bytes) */
int IRInst__removeFromSourceUserLists(inst, program)
  int inst;
  int program;
{
  int operandVReg;
  uint userCount;
  int *elementRef;
  int operandIndex;
  uint loopIndex;
  uint *userVector;
  
  if (((*(uint *)(program + 0x30) & 0x80) != 0) && (operandIndex = 1, 0 < *(int *)(inst + 0x84))) {
    do {
      operandVReg = IRInst__getOperandSource(inst,operandIndex);
      if (operandVReg != 0) {
        operandVReg = IRInst__getOperandSource(inst,operandIndex);
        userVector = *(uint **)(operandVReg + 0x10);
        userCount = userVector[1];
        if (0 < (int)userCount) {
          loopIndex = 0;
          do {
            if (loopIndex < *userVector) {
              if (userCount <= loopIndex) {
                _memset(userCount * 4 + userVector[2],0,(loopIndex - userCount) * 4 + 4);
                userVector[1] = loopIndex + 1;
              }
              elementRef = (int *)(loopIndex * 4 + userVector[2]);
            }
            else {
              elementRef = (int *)Vector__elementRefGrow(userVector,loopIndex);
            }
            if (inst == *elementRef) {
              Vector__removeAt(userVector,loopIndex);
              break;
            }
            userCount = userVector[1];
            loopIndex = loopIndex + 1;
          } while ((int)loopIndex < (int)userCount);
        }
      }
      operandIndex = operandIndex + 1;
    } while (operandIndex <= *(int *)(inst + 0x84));
  }
  return;
}

/* IRInst__removeFromList @ 0x105a44 (224 bytes) */
int IRInst__removeFromList(this, compiler)
  int *this;
  int compiler;
{
  int vslot40Result;
  uint flags;
  int vslot34Result;
  int nextInst;
  
  vslot34Result = (**(code **)(*this + 0x34))(this,compiler);
  if (vslot34Result == 0) {
    (**(code **)(*this + 0x38))(this);
  }
  ((int (*)())IRInst__removeFromSourceUserLists)(this,*(undefined4 *)(compiler + COMP_currentProgram));
  nextInst = this[1];
  vslot40Result = (**(code **)(*this + 0x40))(this);
  if ((vslot40Result != 0) &&
     (vslot40Result = *(int *)(*(int *)(compiler + COMP_currentProgram) + 0x3a0), this == *(int **)(vslot40Result + 300))) {
    *(int *)(vslot40Result + 300) = nextInst;
  }
  flags = this[5];
  if ((((flags & 4) == 0) && (nextInst != 0)) && ((*(uint *)(nextInst + 0x14) & 4) != 0)) {
    *(uint *)(nextInst + 0x14) = *(uint *)(nextInst + 0x14) & 0xfffffffb;
    flags = this[5];
  }
  this[5] = flags & 0xfffffffe;
  return DList__unlink(this);
}

/* IRInst__detachWhenTracking @ 0x105b24 (88 bytes) */
int IRInst__detachWhenTracking(inst, program)
  undefined4 inst;
  int program;
{
  if ((*(uint *)(program + 0x30) & 0x80) != 0) {
    ((int (*)())IRInst__removeFromSourceUserLists)(inst,program);
    ((int (*)())IRInst__decrementSourceUseCounts)(inst,program);
    return;
  }
  return;
}

/* IRInst__removeFromListEx @ 0x105b7c (224 bytes) */
int IRInst__removeFromListEx(this, sourcesReleased, compiler)
  int *this;
  undefined4 sourcesReleased;
  int compiler;
{
  int vslot40Result;
  uint flags;
  int vslot34Result;
  int nextInst;
  
  vslot34Result = (**(code **)(*this + 0x34))(this,sourcesReleased,compiler);
  if (vslot34Result == 0) {
    (**(code **)(*this + 0x38))(this);
  }
  ((int (*)())IRInst__detachWhenTracking)(this,*(undefined4 *)(compiler + COMP_currentProgram));
  nextInst = this[1];
  vslot40Result = (**(code **)(*this + 0x40))(this);
  if ((vslot40Result != 0) &&
     (vslot40Result = *(int *)(*(int *)(compiler + COMP_currentProgram) + 0x3a0), this == *(int **)(vslot40Result + 300))) {
    *(int *)(vslot40Result + 300) = nextInst;
  }
  flags = this[5];
  if ((((flags & 4) == 0) && (nextInst != 0)) && ((*(uint *)(nextInst + 0x14) & 4) != 0)) {
    *(uint *)(nextInst + 0x14) = *(uint *)(nextInst + 0x14) & 0xfffffffb;
    flags = this[5];
  }
  this[5] = flags & 0xfffffffe;
  return DList__unlink(this);
}

/* IRInst__getDefiningField128 @ 0x105c5c (168 bytes) */
int IRInst__getDefiningField128(inst, operandIndex)
  int inst;
  int operandIndex;
{
  int operandVReg;
  undefined4 destKind;
  int *operandRef;
  
  while( true ) {
    if (operandIndex == 0) {
      return *(undefined4 *)(inst + 0x128);
    }
    operandVReg = IRInst__getOperandSource(inst,operandIndex);
    if (operandVReg == 0) break;
    inst = IRInst__getOperandSource(inst,operandIndex);
    operandIndex = 0;
  }
  operandRef = *(int **)(operandIndex * 0x18 + inst + 0x8c);
  if (operandRef == (int *)0x0) {
    return 0;
  }
                    
                    
  destKind = (**(code **)(*operandRef + 0x24))(operandRef);
  return destKind;
}

/* IRInst__firstLiteralSourceValue @ 0x105d04 (184 bytes) */
int IRInst__firstLiteralSourceValue(outValue, inst)
  undefined4 *outValue;
  int *inst;
{
  int operandIndex;
  int operandRecord;
  int lastOperand;
  
  if ((inst[5] & 0x200U) == 0) {
    lastOperand = inst[0x21];
  }
  else {
    lastOperand = inst[0x21] + -1;
  }
  operandIndex = (**(code **)(*inst + 0x14))(inst);
  do {
    operandIndex = operandIndex + 1;
    if (lastOperand < operandIndex) {
      *outValue = DAT_001af9bc;
      return outValue;
    }
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
  } while ((*(uint *)(*(int *)(operandRecord + 4) + 0x14) & 0x80000) == 0);
  *outValue = *(undefined4 *)(operandRecord + 0x10);
  return outValue;
}

/* IRInst__operandKindClass @ 0x105dbc (152 bytes) */
int IRInst__operandKindClass(inst, operandIndex)
  undefined4 inst;
  int operandIndex;
{
  int regKind;
  int sourceDef;
  int operandRecord;
  undefined1 result;
  int sourceInst;
  
  if ((operandIndex < 1) || (sourceInst = IRInst__getOperandSource(inst,operandIndex), sourceInst == 0)) {
    operandRecord = IRInst__getOperandRecord(inst,operandIndex);
    regKind = *(int *)(operandRecord + 0xc);
  }
  else {
    sourceDef = IRInst__getOperandSource(inst,operandIndex);
    regKind = *(int *)(sourceDef + 0x98);
  }
  result = 2;
  if (PTR_PTR_001e8c60[regKind * 0x10 + 9] != '\x01') {
    result = PTR_PTR_001e8c60[regKind * 0x10 + 9] == '\x02';
  }
  return result;
}

/* IRInst__copyOperandFrom @ 0x105e54 (72 bytes) */
int IRInst__copyOperandFrom(dstInst, dstIndex, inst, srcIndex)
  int dstInst;
  int dstIndex;
  undefined4 inst;
  undefined4 srcIndex;
{
  undefined4 operandRecord;
  
  operandRecord = IRInst__getOperandRecord(inst,srcIndex);
  return IROperand__copyFrom(dstIndex * 0x18 + dstInst + 0x8c,operandRecord);
}

/* IRInst__appendOperandRef @ 0x105e9c (104 bytes) */
int IRInst__appendOperandRef(inst, operandRef)
  int inst;
  undefined4 operandRef;
{
  int newIndex;
  int oldCount;
  
  oldCount = *(int *)(inst + 0x84);
  newIndex = oldCount + 1;
  *(int *)(inst + 0x84) = newIndex;
  if ((*(uint *)(inst + 0x14) & 0x200) != 0) {
    ((int (*)())IRInst__copyOperandFrom)(inst,newIndex,inst,oldCount);
    newIndex = *(int *)(inst + 0x84) + -1;
  }
  return IRInst__setOperandRef(inst,newIndex,operandRef);
}

/* IRInst__addToUseLists @ 0x105f04 (256 bytes) */
int IRInst__addToUseLists(inst, program)
  int inst;
  int program;
{
  int operandVReg;
  int *elementRef;
  int operandIndex;
  uint count;
  uint *vectorHeader;
  
  if (((*(uint *)(program + PROG_flags) & 0x80) != 0) && (operandIndex = 1, 0 < *(int *)(inst + 0x84))) {
    do {
      operandVReg = IRInst__getOperandSource(inst,operandIndex);
      if (operandVReg != 0) {
        operandVReg = IRInst__getOperandSource(inst,operandIndex);
        vectorHeader = *(uint **)(operandVReg + 0x10);
        count = vectorHeader[1];
        if (count < *vectorHeader) {
          _memset(count * 4 + vectorHeader[2],0,4);
          elementRef = (int *)(count * 4 + vectorHeader[2]);
          vectorHeader[1] = count + 1;
        }
        else {
          elementRef = (int *)Vector__elementRefGrow(vectorHeader,count);
        }
        *elementRef = inst;
        operandVReg = IRInst__getOperandSource(inst,operandIndex);
        if (*(int *)(program + PROG_useEpoch) < *(int *)(operandVReg + 0x160)) {
          *(int *)(operandVReg + 0x160) = *(int *)(operandVReg + 0x160) + 1;
        }
        else {
          *(int *)(operandVReg + 0x160) = *(int *)(program + PROG_useEpoch) + 1;
        }
      }
      operandIndex = operandIndex + 1;
    } while (operandIndex <= *(int *)(inst + 0x84));
  }
  return;
}

/* IRInst__setOperandSource @ 0x106004 (428 bytes) */
int IRInst__setOperandSource(inst, operandIndex, newSource, trackUses, compilerCtx)
  int inst;
  undefined4 operandIndex;
  int newSource;
  int trackUses;
  int compilerCtx;
{
  int operandVReg;
  uint count;
  int *elementRef;
  int options;
  uint loopIndex;
  uint *vectorHeader;
  
  options = *(int *)(compilerCtx + 0x6c4);
  if ((trackUses != 0) && (operandVReg = IRInst__getOperandSource(inst,operandIndex), operandVReg != 0)) {
    operandVReg = IRInst__getOperandSource(inst,operandIndex);
    vectorHeader = *(uint **)(operandVReg + 0x10);
    count = vectorHeader[1];
    if (0 < (int)count) {
      loopIndex = 0;
      do {
        if (loopIndex < *vectorHeader) {
          if (count <= loopIndex) {
            _memset(count * 4 + vectorHeader[2],0,(loopIndex - count) * 4 + 4);
            vectorHeader[1] = loopIndex + 1;
          }
          elementRef = (int *)(loopIndex * 4 + vectorHeader[2]);
        }
        else {
          elementRef = (int *)Vector__elementRefGrow(vectorHeader,loopIndex);
        }
        if (inst == *elementRef) {
          Vector__removeAt(vectorHeader,loopIndex);
          operandVReg = IRInst__getOperandSource(inst,operandIndex);
          *(int *)(operandVReg + 0x160) = *(int *)(operandVReg + 0x160) + -1;
          break;
        }
        count = vectorHeader[1];
        loopIndex = loopIndex + 1;
      } while ((int)loopIndex < (int)count);
    }
  }
  IRInst__setOperandSourceRaw(inst,operandIndex,newSource,compilerCtx);
  if ((trackUses != 0) && (newSource != 0)) {
    vectorHeader = *(uint **)(newSource + 0x10);
    count = vectorHeader[1];
    if (count < *vectorHeader) {
      _memset(count * 4 + vectorHeader[2],0,4);
      elementRef = (int *)(count * 4 + vectorHeader[2]);
      vectorHeader[1] = count + 1;
    }
    else {
      elementRef = (int *)Vector__elementRefGrow(vectorHeader,count);
    }
    *elementRef = inst;
    options = *(int *)(options + 0x478);
    if (options < *(int *)(newSource + 0x160)) {
      *(int *)(newSource + 0x160) = *(int *)(newSource + 0x160) + 1;
    }
    else {
      *(int *)(newSource + 0x160) = options + 1;
    }
  }
  return;
}

/* IRInst__replaceOperandsReferencing @ 0x1061b0 (128 bytes) */
int IRInst__replaceOperandsReferencing(inst, refInst, compiler)
  int inst;
  int refInst;
  undefined4 compiler;
{
  int operandCount;
  int refWord;
  int loopIndex;
  int recordCursor;
  
  operandCount = *(int *)(inst + 0x84);
  refWord = *(int *)(refInst + 0x8c);
  if (0 < operandCount) {
    loopIndex = 1;
    recordCursor = inst;
    do {
      if (refWord == *(int *)(recordCursor + 0xa4)) {
        ((int (*)())IRInst__setOperandSource)(inst,loopIndex,refInst,0,compiler);
        operandCount = *(int *)(inst + 0x84);
      }
      loopIndex = loopIndex + 1;
      recordCursor = recordCursor + 0x18;
    } while (loopIndex <= operandCount);
  }
  return;
}

/* IRInst__setOperandSourceIfLegal @ 0x106230 (144 bytes) */
int IRInst__setOperandSourceIfLegal(inst, operandIndex, source, legalityArg4, legalityArg5, compiler)
  undefined4 inst;
  undefined4 operandIndex;
  undefined4 source;
  undefined4 legalityArg4;
  undefined4 legalityArg5;
  int compiler;
{
  int isLegal;
  
  isLegal = (**(code **)(**(int **)(compiler + 0x30c) + 0x11c))
                    (*(int **)(compiler + 0x30c),inst,operandIndex,source,legalityArg4,legalityArg5,compiler);
  if (isLegal != 0) {
    ((int (*)())IRInst__setOperandSource)(inst,operandIndex,source,0,compiler);
  }
  return isLegal != 0;
}

/* IRInst__getOrCreateOperandRecord @ 0x1062c0 (156 bytes) */
int IRInst__getOrCreateOperandRecord(inst, operandIndex, srcRecord, compiler)
  int inst;
  int operandIndex;
  undefined4 *srcRecord;
  int compiler;
{
  uint extraIndex;
  undefined4 arena;
  undefined4 *allocation;
  int *newSlot;
  uint oldCount;
  undefined4 recWord1;
  undefined4 recWord3;
  undefined4 recWord2;
  uint pushIndex;
  uint *extraVector;
  
  if (operandIndex < 5) {
    allocation = (undefined4 *)(operandIndex * 0x18 + inst + 0x8c);
  }
  else {
    extraVector = *(uint **)(inst + 0x118);
    if (extraVector == (uint *)0x0) {
      arena = *(undefined4 *)(compiler + COMP_arenaA);
      allocation = (undefined4 *)Arena__alloc(arena,0x14);
      extraVector = allocation + 1;
      *allocation = arena;
      allocation[1] = 2;
      allocation[2] = 0;
      allocation[4] = arena;
      arena = Arena__alloc(arena,8);
      allocation[3] = arena;
      *(uint **)(inst + 0x118) = extraVector;
    }
    if ((int)extraVector[1] < (int)(operandIndex - 4U)) {
      arena = *(undefined4 *)(compiler + COMP_arenaA);
      allocation = (undefined4 *)Arena__alloc(arena,0x1c);
      *allocation = arena;
      allocation[1] = 0;
      allocation[2] = 0;
      allocation[6] = 0;
      extraVector = *(uint **)(inst + 0x118);
      pushIndex = extraVector[1];
      if (pushIndex < *extraVector) {
        _memset((void *)(pushIndex * 4 + extraVector[2]),0,4);
        newSlot = (int *)(pushIndex * 4 + extraVector[2]);
        extraVector[1] = pushIndex + 1;
      }
      else {
        newSlot = (int *)Vector__elementRefGrow(extraVector,pushIndex);
      }
      *newSlot = (int)(allocation + 1);
      setSelectedConstantWord(allocation + 1,operandIndex);
      extraVector = *(uint **)(inst + 0x118);
    }
    extraIndex = operandIndex - 5;
    if (extraIndex < *extraVector) {
      oldCount = extraVector[1];
      if (oldCount <= extraIndex) {
        _memset((void *)(oldCount * 4 + extraVector[2]),0,(extraIndex - oldCount) * 4 + 4);
        extraVector[1] = operandIndex - 4U;
      }
      allocation = (undefined4 *)(extraIndex * 4 + extraVector[2]);
    }
    else {
      allocation = (undefined4 *)Vector__elementRefGrow(extraVector,extraIndex);
    }
    allocation = (undefined4 *)*allocation;
  }
  IROperand__setModifierBits(allocation,1,srcRecord[5] & 1);
  IROperand__setModifierBits(allocation,2,(uint)srcRecord[5] >> 1 & 1);
  arena = *srcRecord;
  recWord1 = srcRecord[1];
  recWord2 = srcRecord[2];
  recWord3 = srcRecord[3];
  allocation[4] = srcRecord[4];
  *allocation = arena;
  allocation[1] = recWord1;
  allocation[2] = recWord2;
  allocation[3] = recWord3;
  return;
}

/* IRInst__validate @ 0x10647c (620 bytes) */
int IRInst__validate(inst, compiler)
  int *inst;
  int compiler;
{
  int srcInst;
  int srcRecord;
  int laneIndex;
  int srcLoopIndex;
  int slotResult2;
  int lanesLeft;
  int destRecord;
  int loopIndex;
  bool moreLanes;
  uint readComponent;
  int slotResult;
  int operandRecord;
  int program;
  int laneIndex2;
  undefined4 destSelectWord;
  undefined4 srcSelectWord;
  undefined4 srcDestSelectWord [4];
  
  if (0 < inst[0x20]) {
    loopIndex = 0;
    do {
      slotResult = (**(code **)(*inst + 0x24))(inst);
      if (slotResult != 0) {
        IRInst__getOperandRecord(inst,loopIndex);
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < inst[0x20]);
  }
  program = *(int *)(compiler + COMP_currentProgram);
  if (((*(uint *)(program + 0x30) & 8) == 0) && (*(int *)(inst[0x22] + 8) != 0x8e)) {
    destRecord = IRInst__getOperandRecord(inst,0);
    laneIndex = 0;
    destSelectWord = *(undefined4 *)(destRecord + 0x10);
    lanesLeft = 4;
    do {
      if (*(char *)((int)&destSelectWord + laneIndex) == '\0') {
        loopIndex = 1;
        if (0 < inst[0x21]) {
          do {
            slotResult2 = (**(code **)(*inst + 0x24))(inst);
            if ((slotResult2 != 0) || (slotResult2 = (**(code **)(*inst + 0x28))(inst), slotResult2 != 0)) {
              IRInst__getOperandRecord(inst,loopIndex);
            }
            loopIndex = loopIndex + 1;
          } while (loopIndex <= inst[0x21]);
        }
        goto LAB_0010663c;
      }
      laneIndex = laneIndex + 1;
      lanesLeft = lanesLeft + -1;
    } while (lanesLeft != 0);
    program = *(int *)(compiler + COMP_currentProgram);
    if (((*(uint *)(program + 0x30) & 0x20000) != 0) && (srcLoopIndex = 1, 0 < inst[0x21])) {
      do {
        srcRecord = IRInst__getOperandRecord(inst,srcLoopIndex);
        srcSelectWord = *(undefined4 *)(srcRecord + 0x10);
        srcInst = IRInst__getOperandSource(inst,srcLoopIndex);
        if (srcInst != 0) {
          operandRecord = IRInst__getOperandRecord(srcInst,0);
          laneIndex2 = 0;
          srcDestSelectWord[0] = *(undefined4 *)(operandRecord + 0x10);
          do {
            readComponent = (uint)*(byte *)((int)srcDestSelectWord + laneIndex2 + -4);
            if (((readComponent != 4) && (*(char *)((int)srcDestSelectWord + readComponent) != '\0')) &&
               ((*(uint *)(srcInst + 0x14) & 0x200) != 0)) {
              IRInst__getOperandRecord(srcInst,*(undefined4 *)(srcInst + 0x84));
            }
            moreLanes = laneIndex2 != 3;
            laneIndex2 = laneIndex2 + 1;
          } while (moreLanes);
        }
        srcLoopIndex = srcLoopIndex + 1;
      } while (srcLoopIndex <= inst[0x21]);
LAB_0010663c:
      program = *(int *)(compiler + COMP_currentProgram);
    }
  }
  if ((*(uint *)(program + 0x30) & 0x800) == 0) {
    (**(code **)(*inst + 0x68))(inst);
  }
  if (((inst[5] & 0x200U) != 0) && ((*(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) & 8) != 0)) {
    IRInst__getOperandSource(inst,inst[0x21]);
  }
  (**(code **)(*inst + 100))(inst);
  return 1;
}

/* IRProjection__validate @ 0x1066e8 (84 bytes) */
int IRProjection__validate(inst, compiler)
  undefined4 inst;
  undefined4 compiler;
{
  int selectRecord;
  int isProjection;
  
  isProjection = IRInst__isProjectionOfClass26or3a(inst);
  if (isProjection != 0) {
    selectRecord = IRInst__getOperandRecord(inst,1);
    SelectWord__isSplat(*(undefined4 *)(selectRecord + 0x10));
  }
  return ((int (*)())IRInst__validate)(inst,compiler);
}

/* IRPresub2__validate @ 0x10673c (68 bytes) */
int IRPresub2__validate(this, compiler)
  int *this;
  undefined4 compiler;
{
  (**(code **)(*this + 0x14))(this,compiler);
  return ((int (*)())IRInst__validate)(this,compiler);
}

/* IRPhiNode__validate @ 0x106780 (128 bytes) */
int IRPhiNode__validate(inst, compiler)
  int inst;
  undefined4 compiler;
{
  int srcRecord;
  int loopIndex;
  int operandCount;
  int checkIndex;
  
  operandCount = *(int *)(inst + 0x84);
  if (0 < operandCount) {
    loopIndex = 1;
    do {
      srcRecord = IRInst__getOperandRecord(inst,loopIndex);
      loopIndex = loopIndex + 1;
      SelectWord__isIdentity(*(undefined4 *)(srcRecord + 0x10));
      operandCount = *(int *)(inst + 0x84);
    } while (loopIndex <= operandCount);
  }
  if (1 < operandCount) {
    checkIndex = 2;
    do {
      checkIndex = checkIndex + 1;
    } while (checkIndex <= operandCount);
  }
  return ((int (*)())IRInst__validate)(inst,compiler);
}

/* IRInst__setExtraOperandSource @ 0x106804 (484 bytes) */
int IRInst__setExtraOperandSource(inst, newSource, trackUses, compilerCtx)
  int inst;
  int newSource;
  int trackUses;
  int compilerCtx;
{
  undefined4 extraOperandSwizzle;
  uint flagsOrCount;
  int oldSource;
  int *elementRef;
  int options;
  uint loopIndex;
  uint *vectorHeader;
  
  options = *(int *)(compilerCtx + 0x6c4);
  if (trackUses != 0) {
    flagsOrCount = *(uint *)(inst + 0x14);
    if ((flagsOrCount & 0x200) == 0) goto LAB_00106908;
    oldSource = IRInst__getOperandSource(inst,*(undefined4 *)(inst + 0x84));
    if (oldSource != 0) {
      vectorHeader = *(uint **)(oldSource + 0x10);
      flagsOrCount = vectorHeader[1];
      if (0 < (int)flagsOrCount) {
        loopIndex = 0;
        do {
          if (loopIndex < *vectorHeader) {
            if (flagsOrCount <= loopIndex) {
              _memset(flagsOrCount * 4 + vectorHeader[2],0,(loopIndex - flagsOrCount) * 4 + 4);
              vectorHeader[1] = loopIndex + 1;
            }
            elementRef = (int *)(loopIndex * 4 + vectorHeader[2]);
          }
          else {
            elementRef = (int *)Vector__elementRefGrow(vectorHeader,loopIndex);
          }
          if (inst == *elementRef) {
            Vector__removeAt(vectorHeader,loopIndex);
            flagsOrCount = *(uint *)(inst + 0x14);
            *(int *)(oldSource + 0x160) = *(int *)(oldSource + 0x160) + -1;
            goto LAB_00106908;
          }
          flagsOrCount = vectorHeader[1];
          loopIndex = loopIndex + 1;
        } while ((int)loopIndex < (int)flagsOrCount);
      }
    }
  }
  flagsOrCount = *(uint *)(inst + 0x14);
LAB_00106908:
  if ((flagsOrCount & 0x200) == 0) {
    *(uint *)(inst + 0x14) = flagsOrCount | 0x200;
    extraOperandSwizzle = DAT_001af9c4;
    oldSource = *(int *)(inst + 0x84) + 1;
    *(int *)(inst + 0x84) = oldSource;
    oldSource = IRInst__getOperandRecord(inst,oldSource);
    *(undefined4 *)(oldSource + 0x10) = extraOperandSwizzle;
  }
  IRInst__setOperandSourceRaw(inst,*(undefined4 *)(inst + 0x84),newSource,compilerCtx);
  if ((trackUses != 0) && (newSource != 0)) {
    vectorHeader = *(uint **)(newSource + 0x10);
    flagsOrCount = vectorHeader[1];
    if (flagsOrCount < *vectorHeader) {
      _memset(flagsOrCount * 4 + vectorHeader[2],0,4);
      elementRef = (int *)(flagsOrCount * 4 + vectorHeader[2]);
      vectorHeader[1] = flagsOrCount + 1;
    }
    else {
      elementRef = (int *)Vector__elementRefGrow(vectorHeader,flagsOrCount);
    }
    *elementRef = inst;
    options = *(int *)(options + 0x478);
    if (options < *(int *)(newSource + 0x160)) {
      *(int *)(newSource + 0x160) = *(int *)(newSource + 0x160) + 1;
    }
    else {
      *(int *)(newSource + 0x160) = options + 1;
    }
  }
  return;
}

/* IRInst__insertSourceBeforeLast @ 0x1069e8 (352 bytes) */
int IRInst__insertSourceBeforeLast(inst, newSource, compiler)
  int inst;
  undefined4 newSource;
  int compiler;
{
  undefined4 defaultSelect2;
  undefined4 lastSelect;
  undefined4 lastSource2;
  undefined4 lastSource;
  undefined4 defaultSelect;
  int oldCount;
  int newCount;
  int lastIndex;
  
  oldCount = *(int *)(inst + 0x84);
  newCount = oldCount + 1;
  *(int *)(inst + 0x84) = newCount;
  if ((*(uint *)(inst + 0x14) & 0x200) == 0) {
    ((int (*)())IRInst__setOperandSource)(inst,newCount,newSource,0,compiler);
    defaultSelect = DAT_001af9bc;
    if (newCount == 0) {
      *(undefined4 *)(inst + 0x9c) = DAT_001af9bc;
    }
    else {
      oldCount = IRInst__getOperandRecord(inst,newCount);
      *(undefined4 *)(oldCount + 0x10) = defaultSelect;
    }
  }
  else {
    if ((*(uint *)(*(int *)(compiler + 0x6c4) + 0x30) & 8) == 0) {
      lastSource = IRInst__getOperandSource(inst,oldCount);
      ((int (*)())IRInst__setOperandSource)(inst,newCount,lastSource,0,compiler);
    }
    else {
      lastSource2 = IRInst__getOperandSource(inst,oldCount);
      ((int (*)())IRInst__setExtraOperandSource)(inst,lastSource2,0,compiler);
    }
    lastIndex = *(int *)(inst + 0x84);
    newCount = IRInst__getOperandRecord(inst,oldCount);
    lastSelect = *(undefined4 *)(newCount + 0x10);
    if (lastIndex == 0) {
      *(undefined4 *)(inst + 0x9c) = lastSelect;
    }
    else {
      newCount = IRInst__getOperandRecord(inst,lastIndex);
      *(undefined4 *)(newCount + 0x10) = lastSelect;
    }
    ((int (*)())IRInst__setOperandSource)(inst,oldCount,newSource,0,compiler);
    defaultSelect2 = DAT_001af9bc;
    if (oldCount == 0) {
      *(undefined4 *)(inst + 0x9c) = DAT_001af9bc;
      newCount = 0;
    }
    else {
      newCount = IRInst__getOperandRecord(inst,oldCount);
      *(undefined4 *)(newCount + 0x10) = defaultSelect2;
      newCount = oldCount;
    }
  }
  return newCount;
}

/* IRInst__setLastOperandFromRecord @ 0x106b48 (88 bytes) */
int IRInst__setLastOperandFromRecord(inst, srcRecord, trackUses, compiler)
  int inst;
  int srcRecord;
  undefined4 trackUses;
  undefined4 compiler;
{
  int operandRecord;
  undefined4 selectWord;
  
  ((int (*)())IRInst__setExtraOperandSource)(inst,*(undefined4 *)(srcRecord + 4),trackUses,compiler);
  selectWord = *(undefined4 *)(srcRecord + 0x10);
  if (*(int *)(inst + 0x84) == 0) {
    *(undefined4 *)(inst + 0x9c) = selectWord;
  }
  else {
    operandRecord = IRInst__getOperandRecord(inst,*(int *)(inst + 0x84));
    *(undefined4 *)(operandRecord + 0x10) = selectWord;
  }
  return;
}

/* IRMix__validate @ 0x106ba0 (276 bytes) */
int IRMix__validate(inst, compiler, unusedArg3, forwardedArg4, forwardedArg5, forwardedArg6, forwardedArg7)
  int *inst;
  int compiler;
  undefined4 unusedArg3;
  undefined4 forwardedArg4;
  undefined4 forwardedArg5;
  undefined4 forwardedArg6;
  undefined4 forwardedArg7;
{
  int loopIndex2;
  bool moreChannels;
  int channel;
  undefined4 operandVReg;
  int operandRecord;
  int *sourceInst;
  int loopIndex;
  
  if (0 < inst[0x21]) {
    loopIndex2 = 1;
    do {
      loopIndex2 = loopIndex2 + 1;
    } while (loopIndex2 <= inst[0x21]);
  }
  channel = 0;
  do {
    IRInst__getOperandRecord(inst,0);
    if (0 < inst[0x21]) {
      loopIndex = 1;
      do {
        IRInst__getOperandRecord(inst,loopIndex);
        if ((*(uint *)(*(int *)(compiler + COMP_currentProgram) + 0x30) & 8) != 0) {
          if (loopIndex != 1) {
            operandVReg = IRInst__getOperandSource(inst,loopIndex);
            operandRecord = IRInst__getOperandRecord(inst,loopIndex);
            IRInst__allSelectsAreHwConstants(operandVReg,compiler,*(undefined4 *)(operandRecord + 0x10),forwardedArg4,forwardedArg5,forwardedArg6,forwardedArg7
                        );
          }
          sourceInst = (int *)IRInst__getOperandSource(inst,loopIndex);
          (**(code **)(*sourceInst + 0x60))(sourceInst);
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex <= inst[0x21]);
    }
    moreChannels = channel != 3;
    channel = channel + 1;
  } while (moreChannels);
  (**(code **)(*inst + 0x14))(inst);
  return ((int (*)())IRInst__validate)(inst,compiler);
}

/* IRPresub1__validate @ 0x106cb4 (68 bytes) */
int IRPresub1__validate(this, compiler)
  int *this;
  undefined4 compiler;
{
  (**(code **)(*this + 0x14))(this,compiler);
  return ((int (*)())IRInst__validate)(this,compiler);
}

/* IRInst__isCoalescableMov @ 0x106cf8 (772 bytes) */
int IRInst__isCoalescableMov(inst, colorGraph)
  int *inst;
  undefined4 colorGraph;
{
  int operandKindClass;
  int byteCountdown;
  int operandIndex;
  int isMovLike;
  int sourceReg;
  int flagBit0Result;
  int *operandVReg;
  int *flagBytePtr;
  int vslot50Result;
  int instReg;
  undefined4 operandVReg2;
  
  if ((inst[5] & 0x200U) != 0) {
    operandVReg = (int *)IRInst__getOperandSource(inst,inst[0x21]);
    vslot50Result = (**(code **)(*operandVReg + 0x50))(operandVReg);
    if (vslot50Result == 0) {
      if (operandVReg[0x20] == 0) {
        return 0;
      }
      flagBit0Result = RegKind__flagBit0(operandVReg[0x26]);
      if (flagBit0Result == 0) {
        return 0;
      }
      if ((operandVReg[5] & 2U) != 0) {
        return 0;
      }
      vslot50Result = (**(code **)(*operandVReg + 0x50))(operandVReg);
      if (vslot50Result != 0) {
        return 0;
      }
      sourceReg = thunk_FUN_00134de8(colorGraph,operandVReg);
      instReg = thunk_FUN_00134de8(colorGraph,inst);
      if (sourceReg != instReg) {
        return 0;
      }
    }
  }
  isMovLike = (**(code **)(*inst + 100))(inst);
  if (isMovLike != 0) {
    for (operandIndex = 1; instReg = (**(code **)(*inst + 0x14))(inst), operandIndex <= instReg;
        operandIndex = operandIndex + 1) {
      if ((inst[operandIndex * 6 + 0x28] & 1U) != 0) {
        return 0;
      }
      if ((inst[operandIndex * 6 + 0x28] & 2U) != 0) {
        return 0;
      }
      instReg = IRInst__isSourceSelectIdentity(inst,operandIndex);
      if (instReg == 0) {
        return 0;
      }
    }
    if ((inst[0x48] == 0) && (inst[0x49] == 0)) {
      if ((inst[0x20] != 0) &&
         (((operandIndex = RegKind__flagBit0(inst[0x26]), operandIndex != 0 && ((inst[5] & 2U) == 0)) &&
          (operandIndex = (**(code **)(*inst + 0x50))(inst), operandIndex == 0)))) {
        byteCountdown = 4;
        flagBytePtr = inst;
        do {
          if ((uint)(*(byte *)(flagBytePtr + 0x27) - 2) < 2) {
            return 0;
          }
          flagBytePtr = (int *)((int)flagBytePtr + 1);
          byteCountdown = byteCountdown + -1;
        } while (byteCountdown != 0);
      }
      IRInst__getOperandRecord(inst,0);
      operandKindClass = ((int (*)())IRInst__operandKindClass)(inst,0);
      if ((((operandKindClass == 0) && ((inst[5] & 2U) == 0)) &&
          ((inst[0x20] != 0 &&
           ((operandKindClass = RegKind__flagBit0(inst[0x26]), operandKindClass != 0 && ((inst[5] & 2U) == 0)))))) &&
         (operandKindClass = (**(code **)(*inst + 0x50))(inst), operandKindClass == 0)) {
        operandVReg = (int *)IRInst__getOperandSource(inst,1);
        vslot50Result = (**(code **)(*operandVReg + 0x50))(operandVReg);
        if (vslot50Result != 0) {
          return 1;
        }
        operandVReg = (int *)IRInst__getOperandSource(inst,1);
        if ((((operandVReg[0x20] != 0) && (vslot50Result = RegKind__flagBit0(operandVReg[0x26]), vslot50Result != 0)) &&
            ((operandVReg[5] & 2U) == 0)) && (vslot50Result = (**(code **)(*operandVReg + 0x50))(operandVReg), vslot50Result == 0))
        {
          operandVReg2 = IRInst__getOperandSource(inst,1);
          sourceReg = thunk_FUN_00134de8(colorGraph,operandVReg2);
          instReg = thunk_FUN_00134de8(colorGraph,inst);
          if (sourceReg == instReg) {
            return 1;
          }
        }
      }
    }
  }
  return 0;
}

/* IRFetch__ctor_106ffc @ 0x106ffc (80 bytes) */
int IRFetch__ctor_106ffc(inst, opcode, compiler)
  undefined4 *inst;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRInst__ctor_1051b0(inst,opcode,compiler);
  vtable = PTR_DAT_001e8c64;
  inst[0x20] = 1;
  inst[0x21] = 1;
  *inst = vtable + 8;
  return;
}

/* IRFetch__ctor_10704c @ 0x10704c (80 bytes) */
int IRFetch__ctor_10704c(inst, opcode, compiler)
  undefined4 *inst;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRInst__ctor_1051b0(inst,opcode,compiler);
  vtable = PTR_DAT_001e8c64;
  inst[0x20] = 1;
  inst[0x21] = 1;
  *inst = vtable + 8;
  return;
}

/* IRPseudo__ctor_10709c @ 0x10709c (92 bytes) */
int IRPseudo__ctor_10709c(inst, opcode, compiler)
  undefined4 *inst;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRInst__ctor_1051b0(inst,opcode,compiler);
  vtable = PTR_DAT_001e8b50;
  inst[5] = inst[5] | 0x18000;
  *inst = vtable + 8;
  inst[0x20] = 0;
  return;
}

/* IRPseudo__ctor @ 0x1070f8 (92 bytes) */
int IRPseudo__ctor(inst, opcode, compiler)
  undefined4 *inst;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRInst__ctor_1051b0(inst,opcode,compiler);
  vtable = PTR_DAT_001e8b50;
  inst[5] = inst[5] | 0x18000;
  *inst = vtable + 8;
  inst[0x20] = 0;
  return;
}

/* IRAlu__ctor_107154 @ 0x107154 (84 bytes) */
int IRAlu__ctor_107154(inst, opcode, compiler)
  undefined4 *inst;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRInst__ctor_1051b0(inst,opcode,compiler);
  vtable = PTR_DAT_001e8c58;
  inst[0x4b] = 0;
  inst[0x20] = 1;
  *inst = vtable + 8;
  return;
}

/* IRAlu__ctor_1071a8 @ 0x1071a8 (84 bytes) */
int IRAlu__ctor_1071a8(inst, opcode, compiler)
  undefined4 *inst;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  IRInst__ctor_1051b0(inst,opcode,compiler);
  vtable = PTR_DAT_001e8c58;
  inst[0x4b] = 0;
  inst[0x20] = 1;
  *inst = vtable + 8;
  return;
}

/* IRMemStore__ctor_1071fc @ 0x1071fc (84 bytes) */
int IRMemStore__ctor_1071fc(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRFetch__ctor_10704c)(this,opcode,compiler);
  vtable = PTR_DAT_001e8c10;
  this[0x4b] = 0;
  this[0x21] = 2;
  *this = vtable + 8;
  return;
}

/* IRVertexFetch__ctor_107250 @ 0x107250 (128 bytes) */
int IRVertexFetch__ctor_107250(this, opcode, compiler, vertexArg4, vertexArg5)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
  undefined4 vertexArg4;
  undefined4 vertexArg5;
{
  undefined4 defaultWord;
  undefined *vtable;
  
  ((int (*)())IRFetch__ctor_10704c)(this,opcode,compiler);
  defaultWord = DAT_001af9bc;
  vtable = PTR_DAT_001e8c08 + 8;
  this[0x4b] = vertexArg5;
  *this = vtable;
  this[0x4f] = 0;
  this[0x50] = defaultWord;
  this[0x4c] = vertexArg4;
  this[0x4d] = 0;
  this[0x4e] = 0;
  return IRVertexFetch__initSemantics(this);
}

/* IRVertexFetch__ctor_1072d0 @ 0x1072d0 (128 bytes) */
int IRVertexFetch__ctor_1072d0(this, opcode, compiler, vertexArg4, vertexArg5)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
  undefined4 vertexArg4;
  undefined4 vertexArg5;
{
  undefined4 defaultWord;
  undefined *vtable;
  
  ((int (*)())IRFetch__ctor_10704c)(this,opcode,compiler);
  defaultWord = DAT_001af9bc;
  vtable = PTR_DAT_001e8c08 + 8;
  this[0x4b] = vertexArg5;
  *this = vtable;
  this[0x4f] = 0;
  this[0x50] = defaultWord;
  this[0x4c] = vertexArg4;
  this[0x4d] = 0;
  this[0x4e] = 0;
  return IRVertexFetch__initSemantics(this);
}

/* IRVertexFetch__new @ 0x107350 (84 bytes) */
int IRVertexFetch__new(opcode, compiler, vertexArg4, vertexArg5)
  undefined4 opcode;
  int compiler;
  undefined4 vertexArg4;
  undefined4 vertexArg5;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRVertexFetch__ctor_1072d0)(allocation + 1,opcode,compiler,vertexArg4,vertexArg5);
  return allocation + 1;
}

/* IRVertexFetch__ctor_1073dc @ 0x1073dc (68 bytes) */
int IRVertexFetch__ctor_1073dc(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  ((int (*)())IRFetch__ctor_10704c)(this,opcode,compiler);
  *this = PTR_DAT_001e8c08 + 8;
  return;
}

/* IRVertexFetch__ctor_107420 @ 0x107420 (68 bytes) */
int IRVertexFetch__ctor_107420(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  ((int (*)())IRFetch__ctor_10704c)(this,opcode,compiler);
  *this = PTR_DAT_001e8c08 + 8;
  return;
}

/* IRLoadConst__vslot75 @ 0x107464 (68 bytes) */
int IRLoadConst__vslot75(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRVertexFetch__ctor_107420)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* IRTextureFetch__ctor_1074e0 @ 0x1074e0 (232 bytes) */
int IRTextureFetch__ctor_1074e0(this, opcode, compiler)
  undefined4 *this;
  int opcode;
  int compiler;
{
  undefined4 defaultWord;
  undefined *vtable;
  undefined2 *fetchStateBlock;
  
  ((int (*)())IRFetch__ctor_10704c)(this,opcode,compiler);
  vtable = PTR_DAT_001e8c0c;
  this[0x4c] = 0;
  this[0x4d] = 0xffffffff;
  *this = vtable + 8;
  this[0x26] = 0;
  this[0x2c] = 0;
  this[0x42] = 0;
  this[0x41] = 0;
  fetchStateBlock = (undefined2 *)Arena__alloc(*(undefined4 *)(compiler + COMP_arenaA),0x24);
  _memset(fetchStateBlock,0,0x24);
  defaultWord = DAT_001af9bc;
  fetchStateBlock[4] = 7;
  fetchStateBlock[6] = 3;
  fetchStateBlock[9] = 1;
  fetchStateBlock[10] = 0;
  *fetchStateBlock = 3;
  fetchStateBlock[1] = 3;
  fetchStateBlock[2] = 3;
  fetchStateBlock[3] = 7;
  fetchStateBlock[5] = 3;
  fetchStateBlock[7] = 1;
  fetchStateBlock[8] = 0;
  fetchStateBlock[0xb] = 0;
  fetchStateBlock[0xc] = 0;
  fetchStateBlock[0xd] = 0;
  fetchStateBlock[0xe] = 0;
  this[0x4f] = fetchStateBlock;
  this[0x4e] = 0xffffffff;
  this[0x50] = defaultWord;
  if (opcode == 0x77) {
    this[5] = this[5] | 8;
  }
  return;
}

/* IRTextureFetchGradients__ctor_107600 @ 0x107600 (76 bytes) */
int IRTextureFetchGradients__ctor_107600(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRTextureFetch__ctor_1074e0)(this,opcode,compiler);
  vtable = PTR_DAT_001e8c48;
  this[0x21] = 3;
  *this = vtable + 8;
  return;
}

/* IRTextureFetch__ctor_10764c @ 0x10764c (232 bytes) */
int IRTextureFetch__ctor_10764c(this, opcode, compiler)
  undefined4 *this;
  int opcode;
  int compiler;
{
  undefined4 defaultWord;
  undefined *vtable;
  undefined2 *fetchStateBlock;
  
  ((int (*)())IRFetch__ctor_10704c)(this,opcode,compiler);
  vtable = PTR_DAT_001e8c0c;
  this[0x4c] = 0;
  this[0x4d] = 0xffffffff;
  *this = vtable + 8;
  this[0x26] = 0;
  this[0x2c] = 0;
  this[0x42] = 0;
  this[0x41] = 0;
  fetchStateBlock = (undefined2 *)Arena__alloc(*(undefined4 *)(compiler + COMP_arenaA),0x24);
  _memset(fetchStateBlock,0,0x24);
  defaultWord = DAT_001af9bc;
  fetchStateBlock[4] = 7;
  fetchStateBlock[6] = 3;
  fetchStateBlock[9] = 1;
  fetchStateBlock[10] = 0;
  *fetchStateBlock = 3;
  fetchStateBlock[1] = 3;
  fetchStateBlock[2] = 3;
  fetchStateBlock[3] = 7;
  fetchStateBlock[5] = 3;
  fetchStateBlock[7] = 1;
  fetchStateBlock[8] = 0;
  fetchStateBlock[0xb] = 0;
  fetchStateBlock[0xc] = 0;
  fetchStateBlock[0xd] = 0;
  fetchStateBlock[0xe] = 0;
  this[0x4f] = fetchStateBlock;
  this[0x4e] = 0xffffffff;
  this[0x50] = defaultWord;
  if (opcode == 0x77) {
    this[5] = this[5] | 8;
  }
  return;
}

/* IRTextureFetch__new @ 0x10776c (68 bytes) */
int IRTextureFetch__new(opcode, compiler)
  undefined4 opcode;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRTextureFetch__ctor_10764c)(allocation + 1,opcode,compiler);
  return allocation + 1;
}

/* IRLoadConst__vslot59 @ 0x1077e8 (68 bytes) */
int IRLoadConst__vslot59(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRTextureFetch__ctor_10764c)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* IRTextureFetchGradients__ctor_107864 @ 0x107864 (76 bytes) */
int IRTextureFetchGradients__ctor_107864(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRTextureFetch__ctor_1074e0)(this,opcode,compiler);
  vtable = PTR_DAT_001e8c48;
  this[0x21] = 3;
  *this = vtable + 8;
  return;
}

/* IRLoadConst__vslot71 @ 0x1078b0 (68 bytes) */
int IRLoadConst__vslot71(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRTextureFetchGradients__ctor_107864)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* IRMemLoad__ctor_10792c @ 0x10792c (84 bytes) */
int IRMemLoad__ctor_10792c(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRFetch__ctor_10704c)(this,opcode,compiler);
  vtable = PTR_DAT_001e8c50;
  this[0x4b] = 0;
  this[0x21] = 2;
  *this = vtable + 8;
  return;
}

/* IRMemLoad__ctor_107980 @ 0x107980 (84 bytes) */
int IRMemLoad__ctor_107980(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRFetch__ctor_10704c)(this,opcode,compiler);
  vtable = PTR_DAT_001e8c50;
  this[0x4b] = 0;
  this[0x21] = 2;
  *this = vtable + 8;
  return;
}

/* IRMemStore__ctor_1079d4 @ 0x1079d4 (84 bytes) */
int IRMemStore__ctor_1079d4(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRFetch__ctor_10704c)(this,opcode,compiler);
  vtable = PTR_DAT_001e8c10;
  this[0x4b] = 0;
  this[0x21] = 2;
  *this = vtable + 8;
  return;
}

/* IRZeroary__ctor_107a28 @ 0x107a28 (76 bytes) */
int IRZeroary__ctor_107a28(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRAlu__ctor_1071a8)(this,opcode,compiler);
  vtable = PTR_DAT_001e8c2c;
  this[0x21] = 0;
  *this = vtable + 8;
  return;
}

/* IRNop__ctor_107a74 @ 0x107a74 (92 bytes) */
int IRNop__ctor_107a74(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined4 defaultWord;
  undefined *vtable;
  
  ((int (*)())IRZeroary__ctor_107a28)(this,opcode,compiler);
  defaultWord = DAT_001af9c8;
  vtable = PTR_DAT_001e8be8 + 8;
  this[0x20] = 0;
  *this = vtable;
  this[0x27] = defaultWord;
  this[0x21] = 0;
  return;
}

/* IRLoadConst__vslot41 @ 0x107ad0 (68 bytes) */
int IRLoadConst__vslot41(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRNop__ctor_107a74)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* IRNop__ctor_107b4c @ 0x107b4c (92 bytes) */
int IRNop__ctor_107b4c(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined4 defaultWord;
  undefined *vtable;
  
  ((int (*)())IRZeroary__ctor_107a28)(this,opcode,compiler);
  defaultWord = DAT_001af9c8;
  vtable = PTR_DAT_001e8be8 + 8;
  this[0x20] = 0;
  *this = vtable;
  this[0x27] = defaultWord;
  this[0x21] = 0;
  return;
}

/* IRZeroary__ctor_107ba8 @ 0x107ba8 (76 bytes) */
int IRZeroary__ctor_107ba8(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRAlu__ctor_1071a8)(this,opcode,compiler);
  vtable = PTR_DAT_001e8c2c;
  this[0x21] = 0;
  *this = vtable + 8;
  return;
}

/* IRZeroary__new @ 0x107bf4 (68 bytes) */
int IRZeroary__new(opcode, compiler)
  undefined4 opcode;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRZeroary__ctor_107ba8)(allocation + 1,opcode,compiler);
  return allocation + 1;
}

/* IRLoadConst__vslot51 @ 0x107c70 (68 bytes) */
int IRLoadConst__vslot51(this, compiler)
  undefined4 this;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + COMP_arenaA);
  allocation = (undefined4 *)Arena__alloc(arena,0x168);
  *allocation = arena;
  ((int (*)())IRZeroary__ctor_107ba8)(allocation + 1,this,compiler);
  return allocation + 1;
}

/* IRUnary__ctor_107cec @ 0x107cec (76 bytes) */
int IRUnary__ctor_107cec(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRAlu__ctor_1071a8)(this,opcode,compiler);
  vtable = PTR_DAT_001e8c68;
  this[0x21] = 1;
  *this = vtable + 8;
  return;
}

/* IRMov__ctor_107d38 @ 0x107d38 (112 bytes) */
int IRMov__ctor_107d38(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  bool moreOperands;
  undefined *vtable;
  int loopIndex;
  
  ((int (*)())IRUnary__ctor_107cec)(this,opcode,compiler);
  vtable = PTR_DAT_001e8bf0;
  this[0x20] = 1;
  *this = vtable + 8;
  loopIndex = 0;
  do {
    moreOperands = loopIndex != 1;
    this[0x25] = 0xffffffff;
    this[0x26] = 0;
    loopIndex = loopIndex + 1;
    this = this + 6;
  } while (moreOperands);
  return;
}

/* IRInst__reinitAsUnary @ 0x107da8 (76 bytes) */
int IRInst__reinitAsUnary(this, opcode, compiler)
  undefined4 *this;
  undefined4 opcode;
  undefined4 compiler;
{
  undefined *vtable;
  
  ((int (*)())IRAlu__ctor_1071a8)(this,opcode,compiler);
  vtable = PTR_DAT_001e8c68;
  this[0x21] = 1;
  *this = vtable + 8;
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_00105a44");
asm(".set FUN_00105a44, _IRInst__removeFromList");
asm(".globl FUN_00105b7c");
asm(".set FUN_00105b7c, _IRInst__removeFromListEx");
asm(".globl FUN_00105e9c");
asm(".set FUN_00105e9c, _IRInst__appendOperandRef");
asm(".globl FUN_0010647c");
asm(".set FUN_0010647c, _IRInst__validate");
asm(".globl FUN_001066e8");
asm(".set FUN_001066e8, _IRProjection__validate");
asm(".globl FUN_0010673c");
asm(".set FUN_0010673c, _IRPresub2__validate");
asm(".globl FUN_00106780");
asm(".set FUN_00106780, _IRPhiNode__validate");
asm(".globl FUN_001069e8");
asm(".set FUN_001069e8, _IRInst__insertSourceBeforeLast");
asm(".globl FUN_00106ba0");
asm(".set FUN_00106ba0, _IRMix__validate");
asm(".globl FUN_00106cb4");
asm(".set FUN_00106cb4, _IRPresub1__validate");
asm(".globl FUN_00107464");
asm(".set FUN_00107464, _IRLoadConst__vslot75");
asm(".globl FUN_0010776c");
asm(".set FUN_0010776c, _IRTextureFetch__new");
asm(".globl FUN_001077e8");
asm(".set FUN_001077e8, _IRLoadConst__vslot59");
asm(".globl FUN_001078b0");
asm(".set FUN_001078b0, _IRLoadConst__vslot71");
asm(".globl FUN_00107ad0");
asm(".set FUN_00107ad0, _IRLoadConst__vslot41");
asm(".globl FUN_00107c70");
asm(".set FUN_00107c70, _IRLoadConst__vslot51");
