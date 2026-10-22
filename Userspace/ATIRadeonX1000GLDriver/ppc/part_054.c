#include "decls.h"

/* R520MachineAssembler__terminateOpenBranches @ 0x1a1398 (312 bytes) */
int R520MachineAssembler__terminateOpenBranches(this)
  int *this;
{
  int *piVar1;
  int stackVector;
  uint uVar3;
  short previousTarget;
  int branchRecord;
  
  do {
    stackVector = *(int *)(this[4] + 0x28);
    uVar3 = *(uint *)(stackVector + 4);
    if (uVar3 == 0) {
      previousTarget = -1;
LAB_001a1430:
      *(undefined4 *)(this[0x18] * 0x48 + this[0x2a]) = 5;
      *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x12) = 0xff;
      *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x10) = 1;
      *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0xe) = 2;
      *(short *)(this[0x18] * 0x48 + this[0x2a] + 0xc) = previousTarget - (short)this[0x1d];
                    
                    
      (**(code **)(*this + 0x15c))(this);
      return;
    }
    piVar1 = (int *)0x0;
    if (uVar3 - 1 < uVar3) {
      piVar1 = (int *)((uVar3 - 1) * 4 + *(int *)(stackVector + 8));
    }
    branchRecord = *piVar1;
    Vector__removeAt(stackVector,uVar3 - 1);
    if ((*(char *)(branchRecord + 0xe) == '\x03') || (*(char *)(branchRecord + 0xe) == '\x01')) {
      previousTarget = *(short *)(branchRecord + 0xc);
      *(short *)(branchRecord + 0xc) = (short)this[0x18] - (short)this[0x1d];
      goto LAB_001a1430;
    }
    *(short *)(branchRecord + 0xc) = (short)this[0x18] - (short)this[0x1d];
  } while( true );
}

/* R520MachineAssembler__vslot30_assembleThenTerminate @ 0x1a14d0 (188 bytes) */
int R520MachineAssembler__vslot30_assembleThenTerminate(this, node, block)
  int *this;
  int node;
  undefined4 block;
{
  bool emittedNothing;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int recordIndexBefore;
  
  recordIndexBefore = this[0x18];
  (**(code **)(*this + 0x34))
            (this,block,*(undefined4 *)(node + 0xdc),in_r6,in_r7,in_r8,
             *(code **)(*this + 0x34));
  if ((*(int *)(node + 0xdc) == 0) || (emittedNothing = true, recordIndexBefore != this[0x18])) {
    emittedNothing = false;
  }
  ((int (*)())R520MachineAssembler__terminateOpenBranches)(this);
  if (*(int *)(*(int *)(node + 300) + 0x134) != 0) {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + -0x3a) = 4;
  }
  if (emittedNothing) {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + -0x44) = 1;
  }
  return;
}

/* R520MachineAssembler__vslot28_endLoop @ 0x1a158c (704 bytes) */
int R520MachineAssembler__vslot28_endLoop(this, node, block, compiler)
  int *this;
  int node;
  undefined4 block;
  undefined4 compiler;
{
  byte bVar1;
  int *loopIndex;
  int iVar3;
  int iVar4;
  uint loopIndex2;
  int a4;
  int iVar6;
  int iVar7;
  int loopRemaining;
  int loopStartRecord;
  undefined8 uVar10;
  
  iVar4 = *(int *)(this[4] + 0x24);
  loopIndex = (int *)0x0;
  loopIndex2 = *(uint *)(iVar4 + 4);
  if (loopIndex2 - 1 < loopIndex2) {
    loopIndex = (int *)((loopIndex2 - 1) * 4 + *(int *)(iVar4 + 8));
  }
  loopStartRecord = *loopIndex;
  Vector__removeAt(iVar4,loopIndex2 - 1);
  iVar4 = this[0x18];
  uVar10 = Compiler__isOptionEnabled(compiler,0x4b);
  if ((int)((ulonglong)uVar10 >> 0x20) == 0) {
    iVar4 = this[0x2a];
  }
  else {
    iVar3 = (iVar4 + -1) * 0x48;
    iVar4 = this[0x2a];
    iVar7 = iVar4 + iVar3;
    if ((((*(int *)(iVar4 + iVar3) == 5) && (*(char *)(iVar7 + 0xe) == '\0')) &&
        ((*(uint *)(iVar7 + 0x10) & 0xff00ff00) == 0x1000000)) &&
       (*(char *)(iVar4 + loopStartRecord * 0x48 + 0xf) == '\0')) {
      bVar1 = *(byte *)(iVar7 + 0x13);
      this[0x18] = this[0x18] + -1;
      this[0x2f] = this[0x2f] + 1;
      iVar3 = bVar1 + 1;
      *(int *)(this[4] + 0x1c) = *(int *)(this[4] + 0x1c) + 1;
      iVar4 = this[0x2a];
      goto LAB_001a168c;
    }
  }
  iVar3 = 1;
  this[0x2f] = 0;
LAB_001a168c:
  a4 = loopStartRecord * 0x48;
  *(short *)(iVar4 + a4 + 0xc) = (short)this[0x18] - (short)this[0x1d];
  loopRemaining = this[0x2f];
  iVar6 = this[0x2e];
  iVar7 = iVar6 * 4;
  this[iVar6 + 0x30] = loopStartRecord;
  if (0 < loopRemaining) {
    iVar4 = this[0x2a];
    loopIndex = this + iVar6 + 0x30;
    loopIndex2 = (uint)*(byte *)(iVar4 + a4 + 0x13);
    while( true ) {
      if (*(char *)(*loopIndex * 0x48 + iVar4 + 0xf) == '\0') {
        loopIndex2 = loopIndex2 + 1;
      }
      loopStartRecord = loopIndex[1];
      iVar6 = iVar4 + loopStartRecord * 0x48;
      if (*(char *)(iVar6 + 0xf) == '\x01') {
        loopIndex2 = loopIndex2 + 1;
      }
      *(char *)(iVar6 + 0x13) = (char)loopIndex2;
      if (loopIndex2 != 0) {
        *(undefined1 *)(loopStartRecord * 0x48 + this[0x2a] + 0x15) = 1;
      }
      loopIndex = loopIndex + 1;
      loopRemaining = loopRemaining + -1;
      if (loopRemaining == 0) break;
      iVar4 = this[0x2a];
    }
    iVar6 = this[0x2e];
  }
  this[0x2e] = iVar6 + -1;
  *(undefined4 *)(this[0x18] * 0x48 + this[0x2a]) = 5;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0xe) = 0;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x12) = 0;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x10) = 1;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x14) = 1;
  *(char *)(this[0x18] * 0x48 + this[0x2a] + 0x13) = (char)iVar3;
  (**(code **)(*this + 0x15c))
            (this,(int)uVar10,iVar3,iVar7,a4,iVar4,*(code **)(*this + 0x15c),0);
  if (*(int *)(node + 0xdc) != 0) {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + -0x44) = 1;
  }
                    
                    
  (**(code **)(*this + 0x34))(this,block,0);
  return;
}

/* R520MachineAssembler__vslot72_setTempDestination @ 0x1a184c (208 bytes) */
int R520MachineAssembler__vslot72_setTempDestination(this, writeRgb, writeAlpha, inst, destRegister)
  int this;
  int writeRgb;
  int writeAlpha;
  undefined4 inst;
  undefined4 destRegister;
{
  int recordBase;
  int operandRecord;
  undefined1 writeMask;
  int recordIndex;
  
  if (writeRgb != 0) {
    *(undefined2 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0xc) =
         (*(unsigned short *)((unsigned char *)&(destRegister) + 2));
    recordIndex = *(int *)(this + 0x60);
    recordBase = *(int *)(this + 0xa8);
    operandRecord = IRInst__getOperandRecord(inst,0);
    writeMask = lanesToRgbMask(*(undefined4 *)(operandRecord + 0x10));
    *(undefined1 *)(recordIndex * 0x48 + recordBase + 0x14) = writeMask;
  }
  if (writeAlpha != 0) {
    *(undefined2 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x18) =
         (*(unsigned short *)((unsigned char *)&(destRegister) + 2));
    recordIndex = *(int *)(this + 0x60);
    recordBase = *(int *)(this + 0xa8);
    operandRecord = IRInst__getOperandRecord(inst,0);
    *(bool *)(recordIndex * 0x48 + recordBase + 0x20) = *(char *)(operandRecord + 0x13) == '\0';
  }
  return;
}

/* R520MachineAssembler__vslot74_setPredicateSetDestination @ 0x1a191c (560 bytes) */
int R520MachineAssembler__vslot74_setPredicateSetDestination(this, writeRgb, writeAlpha, inst)
  int this;
  int writeRgb;
  int writeAlpha;
  int inst;
{
  int iVar1;
  byte invertBit;
  undefined1 uVar4;
  int operandRecord;
  undefined1 compareCode;
  int iVar6;
  int iVar7;
  
  switch(*(undefined4 *)(inst + 300)) {
  default:
    iVar6 = 2;
    compareCode = 0;
    break;
  case 1:
    iVar6 = 2;
    compareCode = 3;
    break;
  case 2:
    iVar6 = 1;
    compareCode = 1;
    break;
  case 3:
    iVar6 = 2;
    compareCode = 2;
    break;
  case 4:
    iVar6 = 2;
    compareCode = 1;
    break;
  case 5:
    iVar6 = 1;
    compareCode = 2;
  }
  invertBit = packSourceModifier(1,0);
  *(undefined4 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8)) = 4;
  if (writeRgb != 0) {
    iVar7 = *(int *)(this + 0x60);
    iVar1 = *(int *)(this + 0xa8);
    operandRecord = IRInst__getOperandRecord(inst,0);
    uVar4 = lanesToRgbMask(*(undefined4 *)(operandRecord + 0x10));
    *(undefined1 *)(iVar7 * 0x48 + iVar1 + 0x15) = uVar4;
    if (iVar6 == 1) {
      iVar1 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
      *(byte *)(iVar1 + 0x2d) = invertBit ^ *(byte *)(iVar1 + 0x2d);
    }
    else {
      iVar1 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
      *(byte *)(iVar1 + 0x2e) = invertBit ^ *(byte *)(iVar1 + 0x2e);
    }
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x16) = compareCode;
  }
  if (writeAlpha != 0) {
    iVar7 = *(int *)(this + 0x60);
    iVar1 = *(int *)(this + 0xa8);
    operandRecord = IRInst__getOperandRecord(inst,0);
    *(bool *)(iVar7 * 0x48 + iVar1 + 0x21) = *(char *)(operandRecord + 0x13) == '\0';
  }
  if (iVar6 == 1) {
    iVar6 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(byte *)(iVar6 + 0x3c) = invertBit ^ *(byte *)(iVar6 + 0x3c);
  }
  else {
    iVar6 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8);
    *(byte *)(iVar6 + 0x3d) = invertBit ^ *(byte *)(iVar6 + 0x3d);
  }
  *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x22) = compareCode;
  return;
}

/* R520MachineAssembler__vslot73_setOutputDestination @ 0x1a1b64 (448 bytes) */
int R520MachineAssembler__vslot73_setOutputDestination(this, writeRgb, writeAlpha, inst)
  int this;
  int writeRgb;
  int writeAlpha;
  int inst;
{
  int iVar1;
  byte outputFlags;
  undefined1 uVar3;
  int iVar4;
  int destinationIndex;
  undefined1 uVar6;
  int destinationClass;
  
  destinationClass = *(int *)(inst + 0x98);
  destinationIndex = *(int *)(inst + 0x94);
  if (destinationClass == 0x2c) {
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x15) = 7;
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x21) = 1;
    *(undefined4 *)(*(int *)(this + 0xac) + 0x9374) = 1;
    outputFlags = (*(int *)(inst + 300) == 0) << 1;
    if ((*(uint *)(inst + 0x14) & 0x1000) != 0) {
      outputFlags = outputFlags | 1;
    }
    *(byte *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x16) = outputFlags;
    *(byte *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x22) = outputFlags;
  }
  else {
    if (destinationClass == 9) {
      iVar1 = destinationIndex + 1;
      iVar4 = *(int *)(*(int *)(this + 0xac) + 0x9374);
      if (iVar1 <= iVar4) {
        iVar1 = iVar4;
      }
      *(int *)(*(int *)(this + 0xac) + 0x9374) = iVar1;
    }
    uVar6 = (undefined1)destinationIndex;
    if ((writeRgb != 0) && (destinationClass != 8)) {
      *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x16) = uVar6;
      iVar4 = *(int *)(this + 0x60);
      destinationIndex = *(int *)(this + 0xa8);
      iVar1 = IRInst__getOperandRecord(inst,0);
      uVar3 = lanesToRgbMask(*(undefined4 *)(iVar1 + 0x10));
      *(undefined1 *)(iVar4 * 0x48 + destinationIndex + 0x15) = uVar3;
    }
    if (writeAlpha != 0) {
      *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x22) = uVar6;
      if (destinationClass == 8) {
        *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + 0x23) = 1;
      }
      else {
        iVar1 = *(int *)(this + 0x60);
        destinationIndex = *(int *)(this + 0xa8);
        destinationClass = IRInst__getOperandRecord(inst,0);
        *(bool *)(iVar1 * 0x48 + destinationIndex + 0x21) = *(char *)(destinationClass + 0x13) == '\0';
      }
    }
  }
  return;
}

/* R520MachineAssembler__vslot23_emitTexRecord @ 0x1a1d24 (2180 bytes) */
int R520MachineAssembler__vslot23_emitTexRecord(this, inst, blockArg, compiler)
  int *this;
  int inst;
  undefined4 blockArg;
  int compiler;
{
  bool bVar1;
  undefined1 uVar2;
  int *a0;
  int iVar3;
  int *piVar4;
  undefined2 uVar7;
  int iVar5;
  byte bVar8;
  undefined4 uVar6;
  byte bVar10;
  uint uVar9;
  undefined4 unaff_r21;
  undefined4 unaff_r22;
  int *piVar11;
  int loopRemaining;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  uint local_78 [4];
  uint local_68 [4];
  undefined4 local_58 [4];
  undefined4 local_48;
  undefined4 local_44;
  uint local_40;
  uint local_3c [3];
  
  a0 = (int *)IRInst__getOperandSource(inst,1);
  iVar3 = (**(code **)(*a0 + 0x60))(a0);
  if (iVar3 != 0) {
    loopRemaining = IRInst__getOperandRecord(a0,1);
    uVar6 = *(undefined4 *)(loopRemaining + 0x10);
    loopRemaining = IRInst__getOperandRecord(inst,1);
    unaff_r22 = *(undefined4 *)(loopRemaining + 0x10);
    FUN_000f2bdc(&local_48,uVar6,unaff_r22);
    piVar4 = (int *)IRInst__getOperandSource(a0,1);
    IRInst__setOperandSource(inst,1,piVar4,0,compiler);
    loopRemaining = IRInst__getOperandRecord(a0,1);
    uVar6 = *(undefined4 *)(loopRemaining + 0x10);
    loopRemaining = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(loopRemaining + 0x10) = uVar6;
    unaff_r21 = local_48;
    piVar11 = a0;
  }
  else {
    piVar11 = (int *)0x0;
    piVar4 = a0;
  }
  uVar7 = (**(code **)(*this + 0x158))(this,inst,1,compiler);
  *(undefined4 *)(this[0x18] * 0x48 + this[0x2a]) = 2;
  *(undefined2 *)(this[0x18] * 0x48 + this[0x2a] + 0xe) = uVar7;
  iVar13 = *(int *)(inst + 0x134);
  loopRemaining = *(int *)(*(int *)(inst + 0x88) + 8);
  if (loopRemaining != 0x77) {
    *(char *)(this[0x18] * 0x48 + this[0x2a] + 0x19) = (char)iVar13;
    iVar15 = this[0x18];
    iVar5 = this[0x2a];
    uVar7 = thunk_FUN_00134de8(*(undefined4 *)(compiler + 0x6c4),inst);
    *(undefined2 *)(iVar15 * 0x48 + iVar5 + 0xc) = uVar7;
  }
  else {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x19) = 0;
    *(undefined2 *)(this[0x18] * 0x48 + this[0x2a] + 0xc) = 0;
    *(undefined4 *)(this[0x2b] + 0x9370) = 1;
  }
  iVar5 = (**(code **)(*piVar4 + 0x80))(piVar4);
  if (iVar5 == 0) {
    *(undefined4 *)(iVar13 * 4 + this[0x2b] + 0x9378) = 1;
  }
  if (*(int *)(PTR_DAT_001e913c + loopRemaining * 0x38 + 0xc) != -1) {
    *(char *)(this[0x18] * 0x48 + this[0x2a] + 0x1a) =
         (char)*(int *)(PTR_DAT_001e913c + loopRemaining * 0x38 + 0xc);
  }
  bVar10 = 0xc;
  iVar13 = *(int *)(iVar13 * 0xc + *(int *)(*(int *)(compiler + 0x6c4) + 0x78) + 4);
  if (iVar13 != 2) {
    if (iVar13 < 3) {
      bVar10 = 0xe;
      if (iVar13 != 1) {
LAB_001a1f84:
        bVar10 = 0;
      }
    }
    else {
      bVar10 = 8;
      if (4 < iVar13) goto LAB_001a1f84;
    }
  }
  bVar1 = *(int *)(inst + 0x138) == 1;
  if (loopRemaining == 0x77) {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x1f) = 0;
    iVar13 = IRInst__getOperandRecord(inst,1);
    FUN_000f32cc(&local_44,*(undefined4 *)(iVar13 + 0x10));
    *(undefined4 *)(inst + 0x9c) = local_44;
    iVar13 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(iVar13 + 0x10) = 0x10203;
    goto LAB_001a20d4;
  }
  if ((loopRemaining - 0x75U < 2) || (loopRemaining == 0xae)) {
    *(byte *)(this[0x18] * 0x48 + this[0x2a] + 0x1f) = bVar10 & 7;
    *(bool *)(this[0x18] * 0x48 + this[0x2a] + 0x18) = bVar1;
    iVar13 = this[0x18] * 0x48 + this[0x2a];
    if ((*(uint *)(inst + 0x14) & 0x2000) == 0) goto LAB_001a20b4;
LAB_001a20cc:
    uVar2 = 0;
  }
  else {
    *(byte *)(this[0x18] * 0x48 + this[0x2a] + 0x1f) = bVar10;
    *(bool *)(this[0x18] * 0x48 + this[0x2a] + 0x18) = bVar1;
    iVar13 = this[0x18] * 0x48 + this[0x2a];
    if ((*(uint *)(inst + 0x14) & 0x2000) != 0) goto LAB_001a20cc;
LAB_001a20b4:
    iVar5 = Compiler__isOptionEnabled(compiler,0x22);
    uVar2 = 1;
    if (iVar5 == 0) goto LAB_001a20cc;
  }
  *(undefined1 *)(iVar13 + 0x1c) = uVar2;
LAB_001a20d4:
  iVar13 = IRInst__getOperandRecord(inst,1);
  FUN_000f3470(&local_40,*(undefined4 *)(iVar13 + 0x10));
  iVar13 = this[0x18] * 0x48 + this[0x2a];
  *(uint *)(iVar13 + 0x14) = local_40 >> 2 & 0xc00000 | *(uint *)(iVar13 + 0x14) & 0xff3fffff;
  iVar13 = this[0x18] * 0x48 + this[0x2a];
  *(uint *)(iVar13 + 0x14) = (local_40 & 0x30000) << 4 | *(uint *)(iVar13 + 0x14) & 0xffcfffff;
  iVar13 = this[0x18] * 0x48 + this[0x2a];
  *(uint *)(iVar13 + 0x14) = (local_40 & 0x300) << 10 | *(uint *)(iVar13 + 0x14) & 0xfff3ffff;
  iVar13 = this[0x18] * 0x48 + this[0x2a];
  *(uint *)(iVar13 + 0x14) = (local_40 & 3) << 0x10 | *(uint *)(iVar13 + 0x14) & 0xfffcffff;
  FUN_000f3470(local_3c,*(undefined4 *)(inst + 0x140));
  iVar13 = this[0x18] * 0x48 + this[0x2a];
  *(uint *)(iVar13 + 0x14) = (local_3c[0] & 0x3000000) << 6 | *(uint *)(iVar13 + 0x14) & 0x3fffffff;
  iVar13 = this[0x18] * 0x48 + this[0x2a];
  *(uint *)(iVar13 + 0x14) = (local_3c[0] & 0x30000) << 0xc | *(uint *)(iVar13 + 0x14) & 0xcfffffff;
  iVar13 = this[0x18] * 0x48 + this[0x2a];
  *(uint *)(iVar13 + 0x14) = (local_3c[0] & 0x300) << 0x12 | *(uint *)(iVar13 + 0x14) & 0xf3ffffff;
  iVar13 = this[0x18] * 0x48 + this[0x2a];
  *(uint *)(iVar13 + 0x14) = (local_3c[0] & 3) << 0x18 | *(uint *)(iVar13 + 0x14) & 0xfcffffff;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x1d) = 0;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x1e) = 0;
  iVar5 = this[0x18] * 0x48 + this[0x2a];
  bVar10 = *(byte *)(iVar5 + 0x1d);
  iVar13 = IRInst__getOperandRecord(inst,0);
  bVar8 = lanesToRgbMask(*(undefined4 *)(iVar13 + 0x10));
  *(byte *)(iVar5 + 0x1d) = bVar10 | bVar8;
  iVar5 = this[0x18] * 0x48 + this[0x2a];
  bVar10 = *(byte *)(iVar5 + 0x1e);
  iVar13 = IRInst__getOperandRecord(inst,0);
  *(byte *)(iVar5 + 0x1e) = bVar10 | *(char *)(iVar13 + 0x13) == '\0';
  *(undefined2 *)(this[0x18] * 0x48 + this[0x2a] + 0x10) = 0;
  *(undefined2 *)(this[0x18] * 0x48 + this[0x2a] + 0x12) = 0;
  this[0x2c] = this[0x18];
  if (loopRemaining == 0x78) {
    loopRemaining = IRInst__getOperandRecord(inst,2);
    uVar9 = *(uint *)(loopRemaining + 0x10);
    loopRemaining = this[0x18] * 0x48 + this[0x2a];
    *(uint *)(loopRemaining + 0x14) = uVar9 >> 10 & 0xc000 | *(uint *)(loopRemaining + 0x14) & 0xffff3fff;
    loopRemaining = this[0x18] * 0x48 + this[0x2a];
    *(uint *)(loopRemaining + 0x14) = uVar9 >> 4 & 0x3000 | *(uint *)(loopRemaining + 0x14) & 0xffffcfff;
    loopRemaining = this[0x18] * 0x48 + this[0x2a];
    *(uint *)(loopRemaining + 0x14) = (uVar9 & 0x300) << 2 | *(uint *)(loopRemaining + 0x14) & 0xfffff3ff;
    loopRemaining = this[0x18] * 0x48 + this[0x2a];
    *(uint *)(loopRemaining + 0x14) = (uVar9 & 3) << 8 | *(uint *)(loopRemaining + 0x14) & 0xfffffcff;
    iVar13 = this[0x18];
    loopRemaining = this[0x2a];
    uVar14 = *(undefined4 *)(compiler + 0x6c4);
    uVar6 = IRInst__getOperandSource(inst,2);
    uVar7 = thunk_FUN_00134de8(uVar14,uVar6);
    *(undefined2 *)(iVar13 * 0x48 + loopRemaining + 0x10) = uVar7;
    loopRemaining = IRInst__getOperandRecord(inst,3);
    uVar9 = *(uint *)(loopRemaining + 0x10);
    loopRemaining = this[0x18] * 0x48 + this[0x2a];
    *(uint *)(loopRemaining + 0x14) = uVar9 >> 0x12 & 0xc0 | *(uint *)(loopRemaining + 0x14) & 0xffffff3f;
    loopRemaining = this[0x18] * 0x48 + this[0x2a];
    *(uint *)(loopRemaining + 0x14) = uVar9 >> 0xc & 0x30 | *(uint *)(loopRemaining + 0x14) & 0xffffffcf;
    loopRemaining = this[0x18] * 0x48 + this[0x2a];
    *(uint *)(loopRemaining + 0x14) = uVar9 >> 6 & 0xc | *(uint *)(loopRemaining + 0x14) & 0xfffffff3;
    loopRemaining = this[0x18] * 0x48 + this[0x2a];
    *(uint *)(loopRemaining + 0x14) = uVar9 & 3 | *(uint *)(loopRemaining + 0x14) & 0xfffffffc;
    iVar13 = this[0x18];
    loopRemaining = this[0x2a];
    uVar14 = *(undefined4 *)(compiler + 0x6c4);
    uVar6 = IRInst__getOperandSource(inst,3);
    uVar7 = thunk_FUN_00134de8(uVar14,uVar6);
    *(undefined2 *)(iVar13 * 0x48 + loopRemaining + 0x12) = uVar7;
  }
  if (iVar3 != 0) {
    iVar3 = 0;
    loopRemaining = 4;
    do {
      *(undefined4 *)(iVar3 + (int)local_78) = 0;
      *(undefined4 *)(iVar3 + (int)local_58) = 0;
      *(undefined4 *)(iVar3 + (int)local_68) = 0;
      iVar3 = iVar3 + 4;
      loopRemaining = loopRemaining + -1;
    } while (loopRemaining != 0);
    (**(code **)(*this + 0xf8))(this,1,local_58,local_78,0,unaff_r21);
    (**(code **)(*this + 0x108))(this,1,local_78,piVar11,unaff_r22);
    (**(code **)(*this + 0x10c))(this,1,local_68,piVar11,unaff_r22);
    IRInst__setOperandSource(inst,1,piVar11,0,compiler);
    iVar3 = IRInst__getOperandRecord(inst,1);
    *(undefined4 *)(iVar3 + 0x10) = unaff_r22;
    iVar3 = this[0x18] * 0x48 + this[0x2a];
    *(uint *)(iVar3 + 0x14) = (local_78[1] & 3) << 0x16 | *(uint *)(iVar3 + 0x14) & 0xff3fffff;
    iVar3 = this[0x18] * 0x48 + this[0x2a];
    *(uint *)(iVar3 + 0x14) = (local_78[1] & 0x18) << 0x11 | *(uint *)(iVar3 + 0x14) & 0xffcfffff;
    iVar3 = this[0x18] * 0x48 + this[0x2a];
    *(uint *)(iVar3 + 0x14) = (local_78[1] & 0xc0) << 0xc | *(uint *)(iVar3 + 0x14) & 0xfff3ffff;
    iVar3 = this[0x18] * 0x48 + this[0x2a];
    *(uint *)(iVar3 + 0x14) = (local_68[1] & 0x600) << 7 | *(uint *)(iVar3 + 0x14) & 0xfffcffff;
  }
  return;
}

/* R520MachineAssembler__emitCompareToPredicate @ 0x1a25a8 (692 bytes) */
int R520MachineAssembler__emitCompareToPredicate(this, inst, blockArg, flag)
  int *this;
  int inst;
  undefined4 blockArg;
  uint flag;
{
  int inst2;
  undefined4 uVar2;
  int iVar3;
  int operandRecord;
  uint uVar5;
  undefined4 a3;
  int iVar6;
  undefined1 compareCode;
  undefined1 auStack_48 [40];
  
  inst2 = IRInst__create(0x12,this[3]);
  uVar2 = IRInst__getOperandSource(inst,1);
  IRInst__setOperandSource(inst2,1,uVar2,0,this[3]);
  iVar6 = inst2 + 0xa4;
  iVar3 = IRInst__getOperandRecord(inst,1);
  uVar2 = *(undefined4 *)(iVar3 + 0x10);
  iVar3 = IRInst__getOperandRecord(inst2,1);
  uVar5 = *(uint *)(inst + 0xb8);
  *(undefined4 *)(iVar3 + 0x10) = uVar2;
  IROperand__setModifierBits(iVar6,2,uVar5 >> 1 & 1);
  iVar3 = inst2 + 0xbc;
  IROperand__setModifierBits(iVar6,1,*(uint *)(inst + 0xb8) & 1);
  uVar2 = IRInst__getOperandSource(inst,2);
  a3 = 0;
  IRInst__setOperandSource(inst2,2,uVar2,0,this[3]);
  operandRecord = IRInst__getOperandRecord(inst,2);
  uVar2 = *(undefined4 *)(operandRecord + 0x10);
  operandRecord = IRInst__getOperandRecord(inst2,2);
  uVar5 = *(uint *)(inst + 0xd0);
  *(undefined4 *)(operandRecord + 0x10) = uVar2;
  IROperand__setModifierBits(iVar3,2,uVar5 >> 1 & 1);
  compareCode = 2;
  IROperand__setModifierBits(iVar3,1,*(uint *)(inst + 0xd0) & 1);
  *(undefined4 *)(inst2 + 0x9c) = 0x10101;
  operandRecord = IRInst__getOperandRecord(inst2,0);
  *(undefined4 *)(operandRecord + 0xc) = 0;
  *(undefined4 *)(operandRecord + 8) = 0;
  switch(*(undefined4 *)(inst + 300)) {
  case 0:
    compareCode = 0;
    IROperand__setModifierBits(iVar3,1,*(uint *)(inst + 0xd0) & 1 ^ 1);
    break;
  case 1:
    compareCode = 3;
    IROperand__setModifierBits(iVar3,1,*(uint *)(inst + 0xd0) & 1 ^ 1);
    break;
  case 2:
    uVar5 = *(uint *)(inst + 0xb8);
    goto LAB_001a2784;
  case 3:
    uVar5 = *(uint *)(inst + 0xd0);
    goto LAB_001a27a4;
  case 4:
    uVar5 = *(uint *)(inst + 0xd0);
    iVar6 = iVar3;
LAB_001a2784:
    compareCode = 1;
    IROperand__setModifierBits(iVar6,1,uVar5 & 1 ^ 1);
    break;
  case 5:
    uVar5 = *(uint *)(inst + 0xb8);
    iVar3 = iVar6;
LAB_001a27a4:
    compareCode = 2;
    IROperand__setModifierBits(iVar3,1,uVar5 & 1 ^ 1);
  }
  FUN_001940a8(auStack_48);
  DList__pushBack(auStack_48,inst2);
  (**(code **)(*this + 0x34))(this,auStack_48,blockArg,a3);
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + -5) = 0;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + -4) = compareCode;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + -0x34) = 0;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + -0x33) = 0;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + -3) = 1;
  return;
}

/* R520MachineAssembler__vslot39_appendLoopStartRecord @ 0x1a2878 (284 bytes) */
int R520MachineAssembler__vslot39_appendLoopStartRecord(this, loopCount)
  int *this;
  undefined4 loopCount;
{
  int iVar1;
  int *piVar2;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  *(undefined4 *)(this[0x18] * 0x48 + this[0x2a]) = 5;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x12) = 0;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0xe) = 1;
  *(char *)(this[0x18] * 0x48 + this[0x2a] + 0x18) = (char)loopCount;
  (**(code **)(*this + 0x15c))(this,loopCount,in_r5,in_r6,in_r7,in_r8,*this);
  *(short *)(this[0x18] * 0x48 + this[0x2a] + -0x3c) = (short)this[0x18] + -1;
  iVar1 = this[0x18];
  puVar5 = *(uint **)(this[4] + 0x28);
  iVar3 = this[0x2a];
  uVar4 = puVar5[1];
  if (uVar4 < *puVar5) {
    _memset(uVar4 * 4 + puVar5[2],0,4);
    piVar2 = (int *)(uVar4 * 4 + puVar5[2]);
    puVar5[1] = uVar4 + 1;
  }
  else {
    piVar2 = (int *)Vector__elementRefGrow(puVar5,uVar4);
  }
  *piVar2 = iVar1 * 0x48 + iVar3 + -0x48;
  return;
}

/* R520MachineAssembler__appendBranchEndRecord @ 0x1a2994 (380 bytes) */
int R520MachineAssembler__appendBranchEndRecord(this, count, variant)
  int *this;
  int count;
  int variant;
{
  int recordIndex;
  int *piVar2;
  int recordsBase;
  uint uVar4;
  uint *puVar5;
  
  *(undefined4 *)(this[0x18] * 0x48 + this[0x2a]) = 5;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x12) = 0xff;
  if (variant == 0) {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0xe) = 5;
  }
  else {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0xe) = 6;
  }
  if (count < 1) {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x15) = 0;
  }
  else {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x15) = 1;
  }
  *(char *)(this[0x18] * 0x48 + this[0x2a] + 0x13) = (char)count;
  (**(code **)(*this + 0x15c))(this);
  *(short *)(this[0x18] * 0x48 + this[0x2a] + -0x3c) = (short)this[0x18] + -1;
  recordIndex = this[0x18];
  puVar5 = *(uint **)(this[4] + 0x28);
  recordsBase = this[0x2a];
  uVar4 = puVar5[1];
  if (uVar4 < *puVar5) {
    _memset(uVar4 * 4 + puVar5[2],0,4);
    piVar2 = (int *)(uVar4 * 4 + puVar5[2]);
    puVar5[1] = uVar4 + 1;
  }
  else {
    piVar2 = (int *)Vector__elementRefGrow(puVar5,uVar4);
  }
  *piVar2 = recordIndex * 0x48 + recordsBase + -0x48;
  return;
}

/* R520MachineAssembler__emitConditionalBranch @ 0x1a2b10 (248 bytes) */
int R520MachineAssembler__emitConditionalBranch(this, branchCount, inst, variant, blockFlag, parentNode)
  int this;
  int branchCount;
  undefined4 inst;
  undefined4 variant;
  int blockFlag;
  undefined4 parentNode;
{
  int callResult;
  uint uVar2;
  int local_38 [7];
  
  local_38[0] = 0;
  callResult = evaluateConstantComparison(inst,local_38);
  if (local_38[0] == 0) {
    uVar2 = Block__getPredecessor(parentNode,0);
    ((int (*)())R520MachineAssembler__emitCompareToPredicate)(this,inst,blockFlag,uVar2);
    ((int (*)())R520MachineAssembler__appendBranchEndRecord)(this,branchCount + -1,variant);
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + -0x36) = 0xf0;
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + -0x3d) = 1;
  }
  else if ((callResult != 0) && (((int (*)())R520MachineAssembler__appendBranchEndRecord)(this,branchCount + -1,variant), blockFlag != 0)) {
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0xa8) + -0x44) = 1;
  }
  return;
}

/* R520MachineAssembler__vslot27_assembleIf @ 0x1a2c08 (264 bytes) */
int R520MachineAssembler__vslot27_assembleIf(this, node, block, extra1, extra2, extra3, extra4)
  int *this;
  int node;
  undefined4 block;
  undefined4 extra1;
  undefined4 extra2;
  undefined4 extra3;
  undefined4 extra4;
{
  int iVar1;
  int *a0;
  int *piVar2;
  undefined4 emittedAny;
  int recordIndexBefore;
  
  a0 = (int *)Block__getBranchInst(node,node,block,extra1,extra2,extra3,extra4);
  (**(code **)(*a0 + 0x14))(a0);
  DList__unlink(a0);
  *(undefined4 *)(node + 0x130) = 0;
  recordIndexBefore = this[0x18];
  (**(code **)(*this + 0x34))(this,block,*(undefined4 *)(node + 0xdc));
  piVar2 = (int *)0x0;
  iVar1 = *(int *)(*(int *)(node + 0x134) + 0xd0);
  if (*(int *)(iVar1 + 4) != 0) {
    piVar2 = *(int **)(iVar1 + 8);
  }
  iVar1 = *piVar2;
  (**(code **)(*this + 0x34))
            (this,iVar1 + 0x90,*(undefined4 *)(iVar1 + 0xdc),extra1,extra2,extra3,
             *(code **)(*this + 0x34));
  if (((*(int *)(node + 0xdc) == 0) && (*(int *)(iVar1 + 0xdc) == 0)) ||
     (emittedAny = 1, recordIndexBefore != this[0x18])) {
    emittedAny = 0;
  }
  return ((int (*)())R520MachineAssembler__emitConditionalBranch)(this,*(undefined4 *)(iVar1 + 0x130),a0,
               *(undefined4 *)(*(int *)(iVar1 + 300) + 0x134),emittedAny,node);
}

/* R520MachineAssembler__vslot32_assembleBranchEnd @ 0x1a2d10 (160 bytes) */
int R520MachineAssembler__vslot32_assembleBranchEnd(this, node, block)
  int *this;
  int node;
  undefined4 block;
{
  bool emittedNothing;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int recordIndexBefore;
  
  recordIndexBefore = this[0x18];
  (**(code **)(*this + 0x34))
            (this,block,*(undefined4 *)(node + 0xdc),in_r6,in_r7,in_r8,
             *(code **)(*this + 0x34));
  if ((*(int *)(node + 0xdc) == 0) || (emittedNothing = true, recordIndexBefore != this[0x18])) {
    emittedNothing = false;
  }
  ((int (*)())R520MachineAssembler__appendBranchEndRecord)(this,*(undefined4 *)(node + 0x130),
               *(undefined4 *)(*(int *)(node + 300) + 0x134));
  if (emittedNothing) {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + -0x44) = 1;
  }
  return;
}

/* R520MachineAssembler__appendLoopRecord @ 0x1a2db0 (308 bytes) */
int R520MachineAssembler__appendLoopRecord(this, hasSecondCondition)
  int *this;
  int hasSecondCondition;
{
  int *piVar1;
  int recordIndex;
  uint stackCount;
  uint *stackVector;
  
  *(undefined4 *)(this[0x18] * 0x48 + this[0x2a]) = 5;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x12) = 0xf;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0xe) = 0;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x14) = 2;
  if (hasSecondCondition != 0) {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x15) = 2;
  }
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0xb) = 1;
  recordIndex = this[0x18];
  stackVector = *(uint **)(this[4] + 0x24);
  stackCount = stackVector[1];
  if (stackCount < *stackVector) {
    _memset(stackCount * 4 + stackVector[2],0,4);
    piVar1 = (int *)(stackCount * 4 + stackVector[2]);
    stackVector[1] = stackCount + 1;
  }
  else {
    piVar1 = (int *)Vector__elementRefGrow(stackVector,stackCount);
  }
  *piVar1 = recordIndex;
  (**(code **)(*this + 0x15c))(this);
  this[0x2e] = this[0x2e] + 1;
  return;
}

/* R520MachineAssembler__vslot25_assembleLoop @ 0x1a2ee4 (284 bytes) */
int R520MachineAssembler__vslot25_assembleLoop(this, node, block, extra1, extra2, extra3, extra4)
  int *this;
  int node;
  undefined4 block;
  undefined4 extra1;
  undefined4 extra2;
  undefined4 extra3;
  undefined4 extra4;
{
  int *conditionNode;
  uint uVar2;
  undefined4 hasCondition;
  int recordIndexBefore;
  int iVar5;
  
  conditionNode = (int *)Block__getBranchInst(node,node,block,extra1,extra2,extra3,extra4);
  (**(code **)(*conditionNode + 0x14))(conditionNode);
  DList__unlink(conditionNode);
  *(undefined4 *)(node + 0x130) = 0;
  recordIndexBefore = this[0x18];
  (**(code **)(*this + 0x34))
            (this,block,*(undefined4 *)(node + 0xdc),extra1,extra2,extra3,
             *(code **)(*this + 0x34));
  if ((*(int *)(node + 0xdc) == 0) || (hasCondition = 1, recordIndexBefore != this[0x18])) {
    hasCondition = 0;
  }
  uVar2 = Block__getPredecessor(node,0);
  ((int (*)())R520MachineAssembler__emitCompareToPredicate)(this,conditionNode,hasCondition,uVar2);
  iVar5 = *(int *)(node + 0x138);
  recordIndexBefore = DList__count(iVar5 + 0x90);
  if ((recordIndexBefore < 3) && (recordIndexBefore = FUN_000e79e8(iVar5), recordIndexBefore != 0)) {
    conditionNode = (int *)0x0;
    if (*(int *)(*(int *)(iVar5 + 0xd0) + 4) != 0) {
      conditionNode = *(int **)(*(int *)(iVar5 + 0xd0) + 8);
    }
    hasCondition = 0;
    if (*conditionNode == *(int *)(node + 0x13c)) goto LAB_001a2fe8;
  }
  hasCondition = 1;
LAB_001a2fe8:
  return ((int (*)())R520MachineAssembler__appendLoopRecord)(this,hasCondition);
}

/* R520MachineAssembler__vslot37_closeBranch @ 0x1a3000 (556 bytes) */
int R520MachineAssembler__vslot37_closeBranch(this, node)
  int *this;
  int *node;
{
  int *piVar1;
  undefined4 a1;
  uint uVar2;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int pendingRecord;
  int stackVector;
  uint *puVar5;
  longlong callResult;
  undefined8 uVar7;
  
  stackVector = node[0x4e];
  callResult = DList__count(stackVector + 0x90);
  a1 = (undefined4)callResult;
  if ((callResult < 0x300000000) &&
     (uVar7 = FUN_000e79e8(stackVector), a1 = (undefined4)uVar7, (int)((ulonglong)uVar7 >> 0x20) != 0)) {
    piVar1 = (int *)0x0;
    if (*(int *)(*(int *)(stackVector + 0xd0) + 4) != 0) {
      piVar1 = *(int **)(*(int *)(stackVector + 0xd0) + 8);
    }
    if (*piVar1 == node[0x4f]) {
      return;
    }
  }
  *(undefined4 *)(this[0x18] * 0x48 + this[0x2a]) = 5;
  *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0xe) = 0;
  stackVector = (**(code **)(*node + 0x40))(node,a1,in_r5,in_r6,in_r7,in_r8,*node);
  if (stackVector == 0) {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x12) = 0;
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x15) = 1;
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x13) = 1;
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0xf) = 1;
  }
  else {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 0x12) = 0xff;
  }
  piVar1 = (int *)0x0;
  stackVector = *(int *)(this[4] + 0x24);
  uVar2 = *(uint *)(stackVector + 4);
  if (uVar2 - 1 < uVar2) {
    piVar1 = (int *)((uVar2 - 1) * 4 + *(int *)(stackVector + 8));
  }
  pendingRecord = *piVar1;
  Vector__removeAt(stackVector,uVar2 - 1);
  *(short *)(pendingRecord * 0x48 + this[0x2a] + 0xc) = (short)this[0x18] - (short)this[0x1d];
  stackVector = this[0x18];
  puVar5 = *(uint **)(this[4] + 0x24);
  uVar2 = puVar5[1];
  if (uVar2 < *puVar5) {
    _memset(uVar2 * 4 + puVar5[2],0,4);
    piVar1 = (int *)(uVar2 * 4 + puVar5[2]);
    puVar5[1] = uVar2 + 1;
  }
  else {
    piVar1 = (int *)Vector__elementRefGrow(puVar5,uVar2);
  }
  *piVar1 = stackVector;
  if (*(int *)(node[0x4f] + 0xdc) != 0) {
    *(undefined1 *)(this[0x18] * 0x48 + this[0x2a] + 4) = 1;
  }
                    
                    
  (**(code **)(*this + 0x15c))(this);
  return;
}

/* FUN_001a322c @ 0x1a322c (32 bytes) */
int FUN_001a322c()
{
  return;
}

/* FUN_001a324c @ 0x1a324c (8 bytes) */
int FUN_001a324c()
{
  return;
}

/* FUN_001a3254 @ 0x1a3254 (4 bytes) */
int FUN_001a3254()
{
  return;
}

/* FUN_001a3258 @ 0x1a3258 (4 bytes) */
int FUN_001a3258()
{
  return;
}

/* FUN_001a325c @ 0x1a325c (4 bytes) */
int FUN_001a325c()
{
  return;
}

/* FUN_001a3260 @ 0x1a3260 (4 bytes) */
int FUN_001a3260()
{
  return;
}

/* FUN_001a3264 @ 0x1a3264 (24 bytes) */
int FUN_001a3264()
{
  return;
}

/* FUN_001a327c @ 0x1a327c (84 bytes) */
int FUN_001a327c()
{
  return;
}

/* FUN_001a32d0 @ 0x1a32d0 (172 bytes) */
int FUN_001a32d0(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 uVar1;
  
  if (DAT_001fc1d4 == (code *)0x0) {
    DAT_001fc1d4 = (code *)((int (*)())FUN_001a3580)("sprintf");
  }
                    
                    
  uVar1 = (*DAT_001fc1d4)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return uVar1;
}

/* FUN_001a337c @ 0x1a337c (172 bytes) */
int FUN_001a337c(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  if (DAT_001fc1d8 == (code *)0x0) {
    DAT_001fc1d8 = (code *)((int (*)())FUN_001a3580)("printf");
  }
                    
                    
  (*DAT_001fc1d8)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_001a3428 @ 0x1a3428 (172 bytes) */
int FUN_001a3428(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  if (DAT_001fc1dc == (code *)0x0) {
    DAT_001fc1dc = (code *)((int (*)())FUN_001a3580)("vsnprintf");
  }
                    
                    
  (*DAT_001fc1dc)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_001a34d4 @ 0x1a34d4 (172 bytes) */
int FUN_001a34d4(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  if (DAT_001fc1e0 == (code *)0x0) {
    DAT_001fc1e0 = (code *)((int (*)())FUN_001a3580)("vsprintf");
  }
                    
                    
  (*DAT_001fc1e0)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}

/* FUN_001a3580 @ 0x1a3580 (164 bytes) */
int FUN_001a3580(param_1)
  undefined4 param_1;
{
  int length;
  int iVar1;
  int callResult;
  undefined4 callResult2;
  /* issue #76 (same defect class as issue #64's stack-split fixes elsewhere in this corpus):
   * local_58/acStack_54/acStack_50 are three separate locals at consecutive stock frame offsets
   * (-0x58, -0x54, -0x50 - no gaps), meant to be ONE 72-byte buffer: code builds a symbol name
   * by strcpy'ing into local_58+1 (needing far more than local_58's own declared 4 bytes) and
   * then appends a literal string constant across all three via raw word-sized stores
   * (`*(undefined4*)(local_58+iVar1)`, `acStack_50[iVar1]`, `*(undefined4*)(acStack_54+iVar1)`).
   * -O0 doesn't lay separately-declared locals out contiguously, so this crashed writing/reading
   * through whatever unrelated stack content followed the undersized local_58 on its own.
   * Merged into one real buffer with offset-preserving aliases, per the established pattern. */
  char acStack_58_combined[72];
#define local_58 (acStack_58_combined + 0)
#define acStack_54 (acStack_58_combined + 4)
#define acStack_50 (acStack_58_combined + 8)

  local_58[0] = '_';
  _strcpy(local_58 + 1,param_1);
  length = _strlen(local_58);
  *(undefined4 *)(local_58 + length) = (*(unsigned int *)((unsigned char *)&(s__LDBL128_001aa0b4) + 0));
  acStack_50[length] = s__LDBL128_001aa0b4[8];
  *(undefined4 *)(acStack_54 + length) = (*(unsigned int *)((unsigned char *)&(s__LDBL128_001aa0b4) + 4));
  callResult = _NSIsSymbolNameDefinedWithHint(local_58,"libSystem.");
  if (callResult == 0) {
    local_58[length] = '\0';
  }
  callResult2 = _NSLookupAndBindSymbolWithHint(local_58,"libSystem.");
  callResult2 = _NSAddressOfSymbol(callResult2);
  return callResult2;
}

/* FUN_001cd7bc @ 0x1cd7bc (28 bytes) */
int FUN_001cd7bc()
{
  return "pseudo";
}

/* MachineAssembler__dtor_1cd7ec @ 0x1cd7ec (36 bytes) */
int MachineAssembler__dtor_1cd7ec(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001e9a40;
  return;
}

/* DListNode__dtor @ 0x1cd810 (36 bytes) */
int DListNode__dtor(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e8b48 + 8;
  return;
}

/* DListNode__deleting_dtor @ 0x1cd834 (56 bytes) */
int DListNode__deleting_dtor(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e8b48 + 8;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(param_1[-1],param_1 + -1);
}

/* IRPseudo__dtor @ 0x1cd86c (68 bytes) */
int IRPseudo__dtor(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e8b4c;
  *param_1 = PTR_DAT_001e8b50 + 8;
  puVar1 = PTR_DAT_001e8b48;
  *param_1 = puVar2 + 8;
  *param_1 = puVar1 + 8;
  return;
}

/* IRPseudo__deleting_dtor @ 0x1cd8b0 (88 bytes) */
int IRPseudo__deleting_dtor(param_1)
  undefined4 *param_1;
{
  undefined *puVar1;
  undefined *puVar2;
  
  puVar2 = PTR_DAT_001e8b4c;
  *param_1 = PTR_DAT_001e8b50 + 8;
  puVar1 = PTR_DAT_001e8b48;
  *param_1 = puVar2 + 8;
  *param_1 = puVar1 + 8;
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(param_1[-1],param_1 + -1);
}

/* IRInst__dtor_1cd908 @ 0x1cd908 (104 bytes) */
int IRInst__dtor_1cd908(this)
  undefined4 *this;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *this = &PTR_FUN_001e9998;
  *this = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *this = PTR_DAT_001e8b4c + 8;
  *this = puVar1;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* IRInst__dtor_1cd970 @ 0x1cd970 (84 bytes) */
int IRInst__dtor_1cd970(this)
  undefined4 *this;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *this = &PTR_FUN_001e97a0;
  *this = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *this = PTR_DAT_001e8b4c + 8;
  *this = puVar1;
  return;
}

/* IRInst__dtor_1cd9c4 @ 0x1cd9c4 (104 bytes) */
int IRInst__dtor_1cd9c4(this)
  undefined4 *this;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *this = &PTR_FUN_001e97a0;
  *this = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *this = PTR_DAT_001e8b4c + 8;
  *this = puVar1;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* IRInst__dtor_1cda2c @ 0x1cda2c (84 bytes) */
int IRInst__dtor_1cda2c(this)
  undefined4 *this;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *this = &PTR_FUN_001e9848;
  *this = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *this = PTR_DAT_001e8b4c + 8;
  *this = puVar1;
  return;
}

/* IRInst__dtor_1cda80 @ 0x1cda80 (104 bytes) */
int IRInst__dtor_1cda80(this)
  undefined4 *this;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *this = &PTR_FUN_001e9848;
  *this = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *this = PTR_DAT_001e8b4c + 8;
  *this = puVar1;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* IRInst__dtor_1cdae8 @ 0x1cdae8 (84 bytes) */
int IRInst__dtor_1cdae8(this)
  undefined4 *this;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *this = &PTR_FUN_001e98f0;
  *this = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *this = PTR_DAT_001e8b4c + 8;
  *this = puVar1;
  return;
}

/* IRInst__dtor_1cdb3c @ 0x1cdb3c (104 bytes) */
int IRInst__dtor_1cdb3c(this)
  undefined4 *this;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *this = &PTR_FUN_001e98f0;
  *this = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *this = PTR_DAT_001e8b4c + 8;
  *this = puVar1;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* IRInst__dtor_1cdba4 @ 0x1cdba4 (84 bytes) */
int IRInst__dtor_1cdba4(this)
  undefined4 *this;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e8b50 + 8;
  *this = &PTR_FUN_001e9998;
  *this = puVar1;
  puVar1 = PTR_DAT_001e8b48 + 8;
  *this = PTR_DAT_001e8b4c + 8;
  *this = puVar1;
  return;
}

/* FUN_001cdc64 @ 0x1cdc64 (28 bytes) */
int FUN_001cdc64()
{
  return "SIMPLE";
}

/* FUN_001cdc88 @ 0x1cdc88 (28 bytes) */
int FUN_001cdc88()
{
  return "ENTRY";
}

/* FUN_001cdcac @ 0x1cdcac (28 bytes) */
int FUN_001cdcac()
{
  return "ANY";
}

/* FUN_001cdcd0 @ 0x1cdcd0 (28 bytes) */
int FUN_001cdcd0()
{
  return "EXIT";
}

/* FUN_001cdcfc @ 0x1cdcfc (28 bytes) */
int FUN_001cdcfc()
{
  return "LOOP_FOOTER";
}

/* FUN_001cdd20 @ 0x1cdd20 (28 bytes) */
int FUN_001cdd20()
{
  return "POST_LOOP_FOOTER";
}

/* FUN_001cdd44 @ 0x1cdd44 (28 bytes) */
int FUN_001cdd44()
{
  return "IF_HEADER";
}

/* FUN_001cdd60 @ 0x1cdd60 (28 bytes) */
int FUN_001cdd60()
{
  return "IF_HEADER_S";
}

/* FUN_001cdd84 @ 0x1cdd84 (28 bytes) */
int FUN_001cdd84()
{
  return "IF_FOOTER";
}

/* FUN_001cdda8 @ 0x1cdda8 (28 bytes) */
int FUN_001cdda8()
{
  return "IF_FOOTER_S";
}

/* FUN_001cddcc @ 0x1cddcc (28 bytes) */
int FUN_001cddcc()
{
  return "BREAK";
}

/* FUN_001cddf0 @ 0x1cddf0 (28 bytes) */
int FUN_001cddf0()
{
  return "CONTINUE";
}

/* FUN_001cde18 @ 0x1cde18 (28 bytes) */
int FUN_001cde18()
{
  return "FUNC_END";
}

/* EntryBlock__deleting_dtor @ 0x1cde34 (104 bytes) */
int EntryBlock__deleting_dtor(this)
  undefined4 *this;
{
  *this = &PTR_FUN_001e9f28;
  Block__dtor_ea270(this);
  if (this != (undefined4 *)0x0) {
    Arena__free(this[-1],this + -1);
    return;
  }
  return;
}

/* AnyBlock__dtor @ 0x1cde9c (36 bytes) */
int AnyBlock__dtor(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e8b58 + 8;
  return Block__dtor_ea270(param_1);
}

/* AnyBlock__deleting_dtor @ 0x1cdec0 (104 bytes) */
int AnyBlock__deleting_dtor(param_1)
  undefined4 *param_1;
{
  *param_1 = PTR_DAT_001e8b58 + 8;
  Block__dtor_ea270(param_1);
  if (param_1 != (undefined4 *)0x0) {
    Arena__free(param_1[-1],param_1 + -1);
    return;
  }
  return;
}

/* FuncEndBlock__dtor @ 0x1cdf28 (36 bytes) */
int FuncEndBlock__dtor(this2)
  undefined4 *this2;
{
  *this2 = &PTR_FUN_001e9b60;
  return Block__dtor_ea270(this2);
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_001a14d0");
asm(".set FUN_001a14d0, _R520MachineAssembler__vslot30_assembleThenTerminate");
asm(".globl FUN_001a158c");
asm(".set FUN_001a158c, _R520MachineAssembler__vslot28_endLoop");
asm(".globl FUN_001a184c");
asm(".set FUN_001a184c, _R520MachineAssembler__vslot72_setTempDestination");
asm(".globl FUN_001a191c");
asm(".set FUN_001a191c, _R520MachineAssembler__vslot74_setPredicateSetDestination");
asm(".globl FUN_001a1b64");
asm(".set FUN_001a1b64, _R520MachineAssembler__vslot73_setOutputDestination");
asm(".globl FUN_001a1d24");
asm(".set FUN_001a1d24, _R520MachineAssembler__vslot23_emitTexRecord");
asm(".globl FUN_001a2878");
asm(".set FUN_001a2878, _R520MachineAssembler__vslot39_appendLoopStartRecord");
asm(".globl FUN_001a2c08");
asm(".set FUN_001a2c08, _R520MachineAssembler__vslot27_assembleIf");
asm(".globl FUN_001a2d10");
asm(".set FUN_001a2d10, _R520MachineAssembler__vslot32_assembleBranchEnd");
asm(".globl FUN_001a2ee4");
asm(".set FUN_001a2ee4, _R520MachineAssembler__vslot25_assembleLoop");
asm(".globl FUN_001a3000");
asm(".set FUN_001a3000, _R520MachineAssembler__vslot37_closeBranch");
asm(".globl FUN_001cd7bc");
asm(".set FUN_001cd7bc, _FUN_001cd7bc");
asm(".globl FUN_001cd7ec");
asm(".set FUN_001cd7ec, _MachineAssembler__dtor_1cd7ec");
asm(".globl FUN_001cd810");
asm(".set FUN_001cd810, _DListNode__dtor");
asm(".globl FUN_001cd834");
asm(".set FUN_001cd834, _DListNode__deleting_dtor");
asm(".globl FUN_001cd86c");
asm(".set FUN_001cd86c, _IRPseudo__dtor");
asm(".globl FUN_001cd8b0");
asm(".set FUN_001cd8b0, _IRPseudo__deleting_dtor");
asm(".globl FUN_001cd908");
asm(".set FUN_001cd908, _IRInst__dtor_1cd908");
asm(".globl FUN_001cd970");
asm(".set FUN_001cd970, _IRInst__dtor_1cd970");
asm(".globl FUN_001cd9c4");
asm(".set FUN_001cd9c4, _IRInst__dtor_1cd9c4");
asm(".globl FUN_001cda2c");
asm(".set FUN_001cda2c, _IRInst__dtor_1cda2c");
asm(".globl FUN_001cda80");
asm(".set FUN_001cda80, _IRInst__dtor_1cda80");
asm(".globl FUN_001cdae8");
asm(".set FUN_001cdae8, _IRInst__dtor_1cdae8");
asm(".globl FUN_001cdb3c");
asm(".set FUN_001cdb3c, _IRInst__dtor_1cdb3c");
asm(".globl FUN_001cdba4");
asm(".set FUN_001cdba4, _IRInst__dtor_1cdba4");
asm(".globl FUN_001cdc64");
asm(".set FUN_001cdc64, _FUN_001cdc64");
asm(".globl FUN_001cdc88");
asm(".set FUN_001cdc88, _FUN_001cdc88");
asm(".globl FUN_001cdcac");
asm(".set FUN_001cdcac, _FUN_001cdcac");
asm(".globl FUN_001cdcd0");
asm(".set FUN_001cdcd0, _FUN_001cdcd0");
asm(".globl FUN_001cdcfc");
asm(".set FUN_001cdcfc, _FUN_001cdcfc");
asm(".globl FUN_001cdd20");
asm(".set FUN_001cdd20, _FUN_001cdd20");
asm(".globl FUN_001cdd44");
asm(".set FUN_001cdd44, _FUN_001cdd44");
asm(".globl FUN_001cdd60");
asm(".set FUN_001cdd60, _FUN_001cdd60");
asm(".globl FUN_001cdd84");
asm(".set FUN_001cdd84, _FUN_001cdd84");
asm(".globl FUN_001cdda8");
asm(".set FUN_001cdda8, _FUN_001cdda8");
asm(".globl FUN_001cddcc");
asm(".set FUN_001cddcc, _FUN_001cddcc");
asm(".globl FUN_001cddf0");
asm(".set FUN_001cddf0, _FUN_001cddf0");
asm(".globl FUN_001cde18");
asm(".set FUN_001cde18, _FUN_001cde18");
asm(".globl FUN_001cde34");
asm(".set FUN_001cde34, _EntryBlock__deleting_dtor");
asm(".globl FUN_001cde9c");
asm(".set FUN_001cde9c, _AnyBlock__dtor");
asm(".globl FUN_001cdec0");
asm(".set FUN_001cdec0, _AnyBlock__deleting_dtor");
asm(".globl FUN_001cdf28");
asm(".set FUN_001cdf28, _FuncEndBlock__dtor");
