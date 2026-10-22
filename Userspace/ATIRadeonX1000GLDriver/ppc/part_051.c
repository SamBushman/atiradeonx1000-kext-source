#include "decls.h"

/* lanesToRgbMask @ 0x195424 (56 bytes) */
int lanesToRgbMask(laneWord)
  uint laneWord;
{
  return ((laneWord >> 8 & 0xff) == 0) << 2 |
         ((laneWord >> 0x10 & 0xff) == 0) << 1 | laneWord >> 0x18 == 0;
}

/* packSourceModifier @ 0x19545c (20 bytes) */
int packSourceModifier(modifierBit0, modifierBit1)
  uint modifierBit0;
  int modifierBit1;
{
  return modifierBit0 | (uint)(modifierBit1 != 0) * 2;
}

/* R300MachineAssembler__vslot12_assembleNodeAndMarkChildren @ 0x195474 (256 bytes) */
int R300MachineAssembler__vslot12_assembleNodeAndMarkChildren(this, node)
  int *this;
  int *node;
{
  int child;
  int iVar2;
  uint loopIndex;
  int childByteOffset;
  
  iVar2 = (**(code **)(*node + 0x14))(node,node);
  if (iVar2 != 0) {
    this[6] = 1;
  }
  iVar2 = this[0x18];
  (**(code **)(*node + 0x44))(node,this[4]);
  this[6] = 0;
  if (node[0x37] != 0) {
    if (iVar2 == this[0x18]) {
      iVar2 = node[0x34];
      childByteOffset = 0;
      for (loopIndex = 1; loopIndex <= *(uint *)(iVar2 + 4); loopIndex = loopIndex + 1) {
        child = *(int *)(*(int *)(iVar2 + 8) + childByteOffset);
        if (child != 0) {
          *(undefined4 *)(child + 0xdc) = 1;
        }
        childByteOffset = childByteOffset + 4;
      }
    }
    if (this[0x23] == 1) {
      (**(code **)(*this + 0x148))(this);
    }
  }
  return;
}

/* R300MachineAssembler__vslot6_noOp @ 0x195574 (4 bytes) */
int R300MachineAssembler__vslot6_noOp()
{
  return;
}

/* R300MachineAssembler__vslot8_returnsTrue @ 0x195578 (8 bytes) */
int R300MachineAssembler__vslot8_returnsTrue()
{
  return 1;
}

/* R300MachineAssembler__vslot3_noOp @ 0x195580 (4 bytes) */
int R300MachineAssembler__vslot3_noOp()
{
  return;
}

/* R300MachineAssembler__vslot9_getRecordBufferWords @ 0x195584 (12 bytes) */
int R300MachineAssembler__vslot9_getRecordBufferWords(this, resultOut)
  undefined4 this;
  undefined4 *resultOut;
{
  *resultOut = 0x258f;
  return;
}

/* psnLiteralAddressFromRegisterWord @ 0x195590 (48 bytes) */
int psnLiteralAddressFromRegisterWord(this, registerWord)
  undefined4 this;
  int registerWord;
{
  uint descriptor;
  uint biasedExponent;
  
  descriptor = *(uint *)(registerWord + 4);
  biasedExponent = descriptor >> 0x17 & 0xff;
  if (biasedExponent == 0) {
    return 0;
  }
  return descriptor >> 7 & 0xffff | descriptor >> 8 & 0x800000 | (biasedExponent - 0x40) * 0x10000;
}

/* R300MachineAssembler__callSlot65 @ 0x1955c0 (16 bytes) */
int R300MachineAssembler__callSlot65(this, node, compiler)
  int *this;
  uint node;
  uint compiler;
{
                    
                    
  (**(code **)(*this + 0x104))(this,node,compiler);
  return;
}

/* R300MachineAssembler__declareNodeRegistersThunk @ 0x1955d0 (12 bytes) */
int R300MachineAssembler__declareNodeRegistersThunk(node, unused1, unused2, compiler, this)
  undefined4 node;
  undefined4 unused1;
  undefined4 unused2;
  undefined4 compiler;
  undefined4 this;
{
  return FUN_000e2c78(node,this,compiler);
}

/* R300MachineAssembler__vslot65_declareNodeRegisters @ 0x1955dc (28 bytes) */
int R300MachineAssembler__vslot65_declareNodeRegisters(this, node, compiler)
  undefined4 this;
  undefined4 node;
  undefined4 compiler;
{
  return FUN_000e2c78(node,this,compiler);
}

/* R300MachineAssembler__vslot2_exceedsInstructionLimit @ 0x1955f8 (36 bytes) */
int R300MachineAssembler__vslot2_exceedsInstructionLimit(param_1)
  int param_1;
{
  return *(int *)(*(int *)(*(int *)(param_1 + 0xc) + 0x30c) + 0x40) + 1 < *(int *)(param_1 + 0x60);
}

/* R300MachineAssembler__vslot38_returnsFalse @ 0x19561c (8 bytes) */
int R300MachineAssembler__vslot38_returnsFalse()
{
  return 0;
}

/* R300MachineAssembler__vslot36_noOp @ 0x195624 (4 bytes) */
int R300MachineAssembler__vslot36_noOp()
{
  return;
}

/* R300MachineAssembler__vslot39_noOp @ 0x195628 (4 bytes) */
int R300MachineAssembler__vslot39_noOp()
{
  return;
}

/* R300MachineAssembler__vslot40_noOp @ 0x19562c (4 bytes) */
int R300MachineAssembler__vslot40_noOp()
{
  return;
}

/* R300MachineAssembler__vslot41_noOp @ 0x195630 (4 bytes) */
int R300MachineAssembler__vslot41_noOp()
{
  return;
}

/* R300MachineAssembler__vslot42_noOp @ 0x195634 (4 bytes) */
int R300MachineAssembler__vslot42_noOp()
{
  return;
}

/* R300MachineAssembler__vslot29_noOp @ 0x195638 (4 bytes) */
int R300MachineAssembler__vslot29_noOp()
{
  return;
}

/* R300MachineAssembler__vslot43_noOp @ 0x19563c (4 bytes) */
int R300MachineAssembler__vslot43_noOp()
{
  return;
}

/* R300MachineAssembler__vslot44_noOp @ 0x195640 (4 bytes) */
int R300MachineAssembler__vslot44_noOp()
{
  return;
}

/* opcodeInfoRgbHwOpcode @ 0x195650 (76 bytes) */
int opcodeInfoRgbHwOpcode(unusedThis, irOpcode)
  undefined4 unusedThis;
  int irOpcode;
{
  int entryByteOffset;
  
  entryByteOffset = irOpcode * 0x38;
  if ((*(uint *)(PTR_DAT_001e913c + entryByteOffset) & 2) != 0) {
    return *(undefined4 *)(PTR_DAT_001e913c + entryByteOffset + 0xc);
  }
  if (*(int *)(PTR_DAT_001e913c + entryByteOffset + 4) == 0) {
    return *(undefined4 *)(PTR_DAT_001e913c + entryByteOffset + 0xc);
  }
  return *(undefined4 *)(PTR_DAT_001e913c + *(int *)(PTR_DAT_001e913c + entryByteOffset + 4) * 0x38 + 0xc);
}

/* opcodeInfoAlphaHwOpcode @ 0x19569c (76 bytes) */
int opcodeInfoAlphaHwOpcode(unusedThis, irOpcode)
  undefined4 unusedThis;
  int irOpcode;
{
  int entryByteOffset;
  
  entryByteOffset = irOpcode * 0x38;
  if ((*(uint *)(PTR_DAT_001e913c + entryByteOffset) & 2) == 0) {
    return *(undefined4 *)(PTR_DAT_001e913c + entryByteOffset + 0xc);
  }
  if (*(int *)(PTR_DAT_001e913c + entryByteOffset + 4) == 0) {
    return *(undefined4 *)(PTR_DAT_001e913c + entryByteOffset + 0xc);
  }
  return *(undefined4 *)(PTR_DAT_001e913c + *(int *)(PTR_DAT_001e913c + entryByteOffset + 4) * 0x38 + 0xc);
}

/* R300MachineAssembler__callSlot14 @ 0x1956e8 (16 bytes) */
int R300MachineAssembler__callSlot14(this)
  int *this;
{
                    
                    
  (**(code **)(*this + 0x38))();
  return;
}

/* R300MachineAssembler__vslot16_noOp @ 0x1956f8 (4 bytes) */
int R300MachineAssembler__vslot16_noOp()
{
  return;
}

/* R300MachineAssembler__vslot19_noOp @ 0x1956fc (4 bytes) */
int R300MachineAssembler__vslot19_noOp()
{
  return;
}

/* R300MachineAssembler__vslot20_noOp @ 0x195700 (4 bytes) */
int R300MachineAssembler__vslot20_noOp()
{
  return;
}

/* R300MachineAssembler__vslot21_noOp @ 0x195704 (4 bytes) */
int R300MachineAssembler__vslot21_noOp()
{
  return;
}

/* R300MachineAssembler__vslot22_noOp @ 0x195708 (4 bytes) */
int R300MachineAssembler__vslot22_noOp()
{
  return;
}

/* R300MachineAssembler__initNopAluRecord @ 0x19570c (136 bytes) */
int R300MachineAssembler__initNopAluRecord(this)
  int this;
{
  int record;
  
  *(undefined4 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58)) = 3;
  record = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58);
  *(undefined2 *)(record + 0x12) = 0x8000;
  *(undefined2 *)(record + 0xe) = 0x8000;
  *(undefined2 *)(record + 0x10) = 0x8000;
  *(undefined1 *)(record + 0x2c) = 0x14;
  *(undefined1 *)(record + 0x31) = 0;
  *(undefined1 *)(record + 0x2a) = 0x14;
  *(undefined1 *)(record + 0x2b) = 0x14;
  *(undefined2 *)(record + 0x1e) = 0x8000;
  *(undefined2 *)(record + 0x1a) = 0x8000;
  *(undefined2 *)(record + 0x1c) = 0x8000;
  *(undefined1 *)(record + 0x40) = 0;
  *(undefined1 *)(record + 0x3b) = 0x10;
  *(undefined1 *)(record + 0x39) = 0x10;
  *(undefined1 *)(record + 0x3a) = 0x10;
  return;
}

/* R300MachineAssembler__setRsColorFields @ 0x195794 (68 bytes) */
int R300MachineAssembler__setRsColorFields(this, recordIndex, colorIndex, colorSource, destRegisterWord, biased)
  int this;
  int recordIndex;
  undefined4 colorIndex;
  undefined4 colorSource;
  undefined4 destRegisterWord;
  undefined4 biased;
{
  int recordOffset;
  
  recordOffset = recordIndex * 0x48;
  *(undefined4 *)(*(int *)(this + 0x58) + recordOffset) = 1;
  *(undefined1 *)(recordOffset + *(int *)(this + 0x58) + 10) = (undefined1)colorIndex;
  *(undefined1 *)(recordOffset + *(int *)(this + 0x58) + 0xb) = (undefined1)colorSource;
  *(undefined2 *)(recordOffset + *(int *)(this + 0x58) + 6) = (*(unsigned short *)((unsigned char *)&(destRegisterWord) + 2));
  *(undefined1 *)(recordOffset + *(int *)(this + 0x58) + 0xd) = (undefined1)biased;
  return;
}

/* R300MachineAssembler__setRsTexCoordFields @ 0x1957d8 (68 bytes) */
int R300MachineAssembler__setRsTexCoordFields(this, recordIndex, texCoordIndex, texCoordPresent, destRegisterWord, adjusted)
  int this;
  int recordIndex;
  undefined4 texCoordIndex;
  undefined4 texCoordPresent;
  undefined4 destRegisterWord;
  undefined4 adjusted;
{
  int recordOffset;
  
  recordOffset = recordIndex * 0x48;
  *(undefined4 *)(*(int *)(this + 0x58) + recordOffset) = 1;
  *(undefined1 *)(recordOffset + *(int *)(this + 0x58) + 8) = (undefined1)texCoordIndex;
  *(undefined1 *)(recordOffset + *(int *)(this + 0x58) + 9) = (undefined1)texCoordPresent;
  *(undefined2 *)(recordOffset + *(int *)(this + 0x58) + 4) = (*(unsigned short *)((unsigned char *)&(destRegisterWord) + 2));
  *(undefined1 *)(recordOffset + *(int *)(this + 0x58) + 0xc) = (undefined1)adjusted;
  return;
}

/* R300MachineAssembler__rgbSelectForSrcpSwizzle @ 0x19581c (260 bytes) */
int R300MachineAssembler__rgbSelectForSrcpSwizzle(this, sourceIndex, selectOut, unused, swizzle)
  undefined4 this;
  int sourceIndex;
  int selectOut;
  undefined4 unused;
  uint swizzle;
{
  int callResult;
  uint swizzleLanes;
  
  swizzleLanes = swizzle & 0xffffff00 | 4;
  callResult = FUN_000f2d18(swizzleLanes,DAT_001b2ac0);
  if (callResult == 0) {
    callResult = FUN_000f2d18(swizzleLanes,DAT_001b2abc);
    if (callResult == 0) {
      callResult = FUN_000f2d18(swizzleLanes,DAT_001b2ab8);
      if (callResult == 0) {
        callResult = FUN_000f2d18(swizzleLanes,DAT_001b2ab4);
        if (callResult == 0) {
          callResult = FUN_000f2d18(swizzleLanes,DAT_001b2ac4);
          if (callResult != 0) {
            *(undefined4 *)(sourceIndex * 4 + selectOut) = 0x13;
          }
        }
        else {
          *(undefined4 *)(sourceIndex * 4 + selectOut) = 0x12;
        }
      }
      else {
        *(undefined4 *)(sourceIndex * 4 + selectOut) = 0x11;
      }
    }
    else {
      *(undefined4 *)(sourceIndex * 4 + selectOut) = 0x10;
    }
  }
  else {
    *(undefined4 *)(sourceIndex * 4 + selectOut) = 0xf;
  }
  return;
}

/* R300MachineAssembler__alphaSelectForSrcpComponent @ 0x195920 (108 bytes) */
int R300MachineAssembler__alphaSelectForSrcpComponent(this, sourceIndex, selectOut, unused, componentIndex)
  undefined4 this;
  int sourceIndex;
  int selectOut;
  undefined4 unused;
  undefined4 componentIndex;
{
  if ((char)componentIndex == '\0') {
    *(undefined4 *)(sourceIndex * 4 + selectOut) = 0xc;
    return;
  }
  if ((char)componentIndex == '\x01') {
    *(undefined4 *)(sourceIndex * 4 + selectOut) = 0xd;
    return;
  }
  if ((char)componentIndex == '\x02') {
    *(undefined4 *)(sourceIndex * 4 + selectOut) = 0xe;
    return;
  }
  if (((char)componentIndex != '\x03') && ((char)componentIndex != '\x04')) {
    return;
  }
  *(undefined4 *)(sourceIndex * 4 + selectOut) = 0xf;
  return;
}

/* R300MachineAssembler__rgbSelectForAlphaSource @ 0x19598c (112 bytes) */
int R300MachineAssembler__rgbSelectForAlphaSource(this, sourceIndex, selectOut, unused, sourceNumber, swizzle)
  undefined4 this;
  int sourceIndex;
  int selectOut;
  undefined4 unused;
  int sourceNumber;
  uint swizzle;
{
  int callResult;
  
  callResult = FUN_000f2d18(swizzle & 0xffffff00 | 4,DAT_001b2ac4);
  if (callResult == 0) {
    *(int *)(sourceIndex * 4 + selectOut) = sourceNumber + 0x1d;
  }
  else {
    *(int *)(sourceIndex * 4 + selectOut) = sourceNumber + 0xc;
  }
  return;
}

/* R300MachineAssembler__rgbSelectForSourceSwizzle @ 0x1959fc (336 bytes) */
int R300MachineAssembler__rgbSelectForSourceSwizzle(this, sourceIndex, selectOut, unused, sourceNumber, swizzle)
  undefined4 this;
  int sourceIndex;
  int selectOut;
  undefined4 unused;
  int sourceNumber;
  uint swizzle;
{
  int callResult;
  uint swizzleOrLane;
  
  swizzleOrLane = swizzle & 0xffffff00 | 4;
  callResult = FUN_000f2d18(swizzleOrLane,DAT_001b2ac0);
  if (callResult != 0) {
    *(int *)(sourceIndex * 4 + selectOut) = sourceNumber << 2;
    return;
  }
  callResult = FUN_000f2d18(swizzleOrLane,DAT_001b2abc);
  if (callResult != 0) {
    *(int *)(selectOut + sourceIndex * 4) = sourceNumber * 4 + 1;
    return;
  }
  callResult = FUN_000f2d18(swizzleOrLane,DAT_001b2ab8);
  if (callResult != 0) {
    *(int *)(selectOut + sourceIndex * 4) = sourceNumber * 4 + 2;
    return;
  }
  callResult = FUN_000f2d18(swizzleOrLane,DAT_001b2ab4);
  if (callResult != 0) {
    *(int *)(selectOut + sourceIndex * 4) = sourceNumber * 4 + 3;
    return;
  }
  swizzleOrLane = swizzle >> 0x18;
  if (swizzleOrLane == 1) {
LAB_00195b1c:
    *(int *)(sourceIndex * 4 + selectOut) = sourceNumber + 0x17;
  }
  else {
    if (swizzleOrLane != 3) {
      if ((swizzleOrLane == 2) || ((swizzle >> 0x10 & 0xff) == 0)) {
        *(int *)(sourceIndex * 4 + selectOut) = sourceNumber + 0x1a;
        return;
      }
      if ((swizzle >> 8 & 0xff) == 0) goto LAB_00195b1c;
    }
    *(int *)(sourceIndex * 4 + selectOut) = sourceNumber + 0x1d;
  }
  return;
}

/* R300MachineAssembler__alphaSelectForAlphaSource @ 0x195b4c (16 bytes) */
int R300MachineAssembler__alphaSelectForAlphaSource(this, sourceIndex, selectOut, unused, sourceNumber)
  undefined4 this;
  int sourceIndex;
  int selectOut;
  undefined4 unused;
  int sourceNumber;
{
  *(int *)(sourceIndex * 4 + selectOut) = sourceNumber + 9;
  return;
}

/* R300MachineAssembler__alphaSelectForColorComponent @ 0x195b5c (84 bytes) */
int R300MachineAssembler__alphaSelectForColorComponent(this, sourceIndex, selectOut, unused, sourceNumber, componentIndex)
  undefined4 this;
  int sourceIndex;
  int selectOut;
  undefined4 unused;
  int sourceNumber;
  undefined4 componentIndex;
{
  if ((char)componentIndex == '\0') {
    *(int *)(selectOut + sourceIndex * 4) = sourceNumber * 3;
    return;
  }
  if ((char)componentIndex == '\x01') {
    *(int *)(selectOut + sourceIndex * 4) = sourceNumber * 3 + 1;
    return;
  }
  if ((char)componentIndex != '\x02') {
    return;
  }
  *(int *)(selectOut + sourceIndex * 4) = sourceNumber * 3 + 2;
  return;
}

/* R300MachineAssembler__setAluSourceAddresses @ 0x195bb0 (316 bytes) */
int R300MachineAssembler__setAluSourceAddresses(this, rgbSourceMask, rgbSourceAddress, alphaSourceMask, alphaSourceAddress)
  int this;
  int rgbSourceMask;
  int rgbSourceAddress;
  int alphaSourceMask;
  int alphaSourceAddress;
{
  bool notLastSource;
  int addressCursor;
  uint loopIndex;
  
  loopIndex = 1;
  addressCursor = rgbSourceAddress;
  do {
    if (((rgbSourceMask >> (loopIndex & 0x3f) & 1U) != 0) && (-1 < *(int *)(addressCursor + 4))) {
      if (loopIndex == 1) {
        *(short *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0xe) =
             (short)*(undefined4 *)(rgbSourceAddress + 4);
      }
      else if (loopIndex == 2) {
        *(short *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x10) =
             (short)*(undefined4 *)(rgbSourceAddress + 8);
      }
      else if (loopIndex == 3) {
        *(short *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x12) =
             (short)*(undefined4 *)(rgbSourceAddress + 0xc);
      }
    }
    notLastSource = loopIndex != 3;
    addressCursor = addressCursor + 4;
    loopIndex = loopIndex + 1;
  } while (notLastSource);
  loopIndex = 1;
  addressCursor = alphaSourceAddress;
  do {
    if (((alphaSourceMask >> (loopIndex & 0x3f) & 1U) != 0) && (-1 < *(int *)(addressCursor + 4))) {
      if (loopIndex == 1) {
        *(short *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x1a) =
             (short)*(undefined4 *)(alphaSourceAddress + 4);
      }
      else if (loopIndex == 2) {
        *(short *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x1c) =
             (short)*(undefined4 *)(alphaSourceAddress + 8);
      }
      else if (loopIndex == 3) {
        *(short *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x1e) =
             (short)*(undefined4 *)(alphaSourceAddress + 0xc);
      }
    }
    notLastSource = loopIndex != 3;
    addressCursor = addressCursor + 4;
    loopIndex = loopIndex + 1;
  } while (notLastSource);
  return;
}

/* R300MachineAssembler__setAlphaOpcode @ 0x195cec (644 bytes) */
int R300MachineAssembler__setAlphaOpcode(this, hardwareOpcode, irOpcode, irInst)
  int this;
  int hardwareOpcode;
  int irOpcode;
  int irInst;
{
  undefined1 savedModifier;
  int iVar2;
  undefined1 alphaOpcode;
  int iVar4;
  
  alphaOpcode = (undefined1)hardwareOpcode;
  *(undefined4 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58)) = 3;
  if (hardwareOpcode != -1) goto LAB_00195f08;
  if (irOpcode == 0x31) {
LAB_00195e0c:
    alphaOpcode = 0;
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x3a) = 0x11;
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x3b) = 0x10;
    goto LAB_00195f08;
  }
  if (irOpcode < 0x32) {
    if (irOpcode != 0x13) {
      if (irOpcode == 0x25) {
LAB_00195e48:
        iVar2 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58);
        alphaOpcode = *(undefined1 *)(iVar2 + 0x39);
        *(undefined1 *)(iVar2 + 0x39) = *(undefined1 *)(iVar2 + 0x3a);
        iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58);
        savedModifier = *(undefined1 *)(iVar2 + 0x3c);
        *(undefined1 *)(iVar4 + 0x3c) = *(undefined1 *)(iVar4 + 0x3d);
        iVar2 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58);
        *(undefined1 *)(iVar2 + 0x3a) = *(undefined1 *)(iVar2 + 0x3b);
        iVar2 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58);
        *(undefined1 *)(iVar2 + 0x3d) = *(undefined1 *)(iVar2 + 0x3e);
        *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x3b) = alphaOpcode;
        *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x3e) = savedModifier;
        if (irOpcode == 0x9d) {
          alphaOpcode = 5;
        }
        else {
          alphaOpcode = 6;
        }
        goto LAB_00195f08;
      }
      if (irOpcode != 0x12) goto LAB_00195d6c;
LAB_00195d94:
      alphaOpcode = 0;
      iVar2 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58);
      *(undefined1 *)(iVar2 + 0x3b) = *(undefined1 *)(iVar2 + 0x3a);
      iVar2 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58);
      *(undefined1 *)(iVar2 + 0x3e) = *(undefined1 *)(iVar2 + 0x3d);
      *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x3a) = 0x11;
      *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x3d) = 0;
      goto LAB_00195f08;
    }
  }
  else if (irOpcode != 0x36) {
    if (irOpcode < 0x37) {
      if (irOpcode == 0x34) goto LAB_00195d94;
    }
    else {
      if (irOpcode == 0x66) goto LAB_00195e0c;
      if (irOpcode == 0x9d) goto LAB_00195e48;
    }
LAB_00195d6c:
    alphaOpcode = 0xff;
    goto LAB_00195f08;
  }
  alphaOpcode = 0;
  *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x3b) = 0x10;
LAB_00195f08:
  *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x40) = alphaOpcode;
  if (*(int *)(irInst + 0x120) != 0) {
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x42) = 1;
  }
  iVar4 = *(int *)(this + 0x60);
  iVar2 = *(int *)(this + 0x58);
  alphaOpcode = psnOutputScaleCode(*(undefined4 *)(irInst + 0x124));
  *(undefined1 *)(iVar4 * 0x48 + iVar2 + 0x41) = alphaOpcode;
  return;
}

/* R300MachineAssembler__setAlphaTempWriteEnable @ 0x195f70 (28 bytes) */
int R300MachineAssembler__setAlphaTempWriteEnable(this)
  int this;
{
  *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x20) = 1;
  return;
}

/* R300MachineAssembler__closeTextureIndirectionLevel @ 0x195f8c (76 bytes) */
int R300MachineAssembler__closeTextureIndirectionLevel(this)
  int this;
{
  int texCountNow;
  
  *(int *)(this + 0x88) = *(int *)(this + 0x88) + 1;
  if (*(int *)(this + 100) == *(int *)(this + 0x6c)) {
    texCountNow = *(int *)(this + 0x68);
    if (texCountNow != *(int *)(this + 0x70)) {
      *(int *)(this + 0x7c) = *(int *)(this + 0x7c) + 1;
    }
  }
  else {
    texCountNow = *(int *)(this + 0x68);
  }
  *(int *)(this + 0x70) = texCountNow;
  *(int *)(this + 0x6c) = *(int *)(this + 100);
  return;
}

/* R300MachineAssembler__writeHeaderRecord @ 0x195fd8 (152 bytes) */
int R300MachineAssembler__writeHeaderRecord(this, highestConstant, pixelSize)
  int this;
  undefined4 highestConstant;
  undefined4 pixelSize;
{
  undefined4 rsCount;
  int aluSlotExtra;
  int header;
  
  *(undefined2 *)(*(int *)(this + 0x58) + 0x24) = (*(unsigned short *)((unsigned char *)&(highestConstant) + 2));
  header = *(int *)(this + 0x58);
  *(int *)(header + 8) = *(int *)(this + 0x60) + -1;
  *(undefined2 *)(header + 0x14) = 1;
  if ((*(int *)(this + 100) == *(int *)(this + 0x6c)) &&
     (*(int *)(this + 0x68) != *(int *)(this + 0x70))) {
    aluSlotExtra = *(int *)(this + 0x7c) + 1;
    *(int *)(this + 0x7c) = aluSlotExtra;
  }
  else {
    aluSlotExtra = *(int *)(this + 0x7c);
  }
  *(short *)(header + 0x1e) = (short)*(int *)(this + 100) + (short)aluSlotExtra;
  *(undefined1 *)(header + 0xd) = 6;
  *(undefined1 *)(header + 0xc) = 0;
  *(short *)(header + 0x1c) = (short)*(undefined4 *)(this + 100);
  *(short *)(header + 0x1a) = (short)*(undefined4 *)(this + 0x68);
  *(short *)(header + 0x16) = (short)*(undefined4 *)(this + 0x88) + 1;
  rsCount = *(undefined4 *)(this + 0x74);
  *(undefined2 *)(header + 0x22) = (*(unsigned short *)((unsigned char *)&(pixelSize) + 2));
  *(short *)(header + 0x18) = (short)rsCount;
  return;
}

/* R300MachineAssembler__beginNextRecord @ 0x196070 (320 bytes) */
int R300MachineAssembler__beginNextRecord(this)
  int *this;
{
  int recordPtr;
  
  if (this[0x1d] == 0) {
    recordPtr = this[0x16] + this[0x18] * 0x48;
    _memcpy(recordPtr + 0x48,recordPtr,0x48);
    _memset(this[0x18] * 0x48 + this[0x16],0,0x48);
    this[0x18] = 2;
    this[0x1d] = 1;
    (**(code **)(*this + 0xc4))(this,1,0,0,0,0);
    (**(code **)(*this + 200))(this,1,0,0,0,0);
    (**(code **)(*this + 0xcc))(this,1,0xf);
    (**(code **)(*this + 0xd0))(this,1,0xf);
  }
  this[0x21] = 1;
  this[0x20] = 1;
  this[0x18] = this[0x18] + 1;
  return;
}

/* R300MachineAssembler__vslot4_finishProgram @ 0x1961c8 (296 bytes) */
int R300MachineAssembler__vslot4_finishProgram(param_1)
  int *param_1;
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  *(int *)(param_1[0x17] + 0x93b8) = param_1[0x24];
  *(int *)(param_1[0x17] + 0x9364) = *(int *)(*(int *)(param_1[3] + 0x6c4) + 0x7c) + 1;
  iVar2 = *(int *)(*(int *)(param_1[3] + 0x6c4) + 0x80);
  *(undefined4 *)(param_1[0x17] + 0x9368) = *(undefined4 *)(*(int *)(param_1[3] + 0x6c4) + 0x84);
  uVar3 = iVar2 + 1;
  uVar1 = *(uint *)(param_1[0x17] + 0x9364);
  if (uVar3 < uVar1) {
    uVar3 = uVar1;
  }
  *(uint *)(param_1[0x17] + 0x9364) = uVar3;
  iVar4 = 0;
  iVar2 = FUN_0013061c(*(undefined4 *)(param_1[3] + 0x6c4),0);
  if (iVar2 != 0) {
    iVar4 = iVar2 + -1;
  }
  if (param_1[0x18] == param_1[0x1d] + 1) {
    (**(code **)(*param_1 + 0xbc))(param_1);
    (**(code **)(*param_1 + 0xc0))(param_1);
    (**(code **)(*param_1 + 0x15c))(param_1);
  }
                    
                    
  (**(code **)(*param_1 + 0x144))(param_1,param_1[0x1e],iVar4);
  return;
}

/* R300MachineAssembler__assembleAsOpcodeInfo31 @ 0x1962f0 (128 bytes) */
int R300MachineAssembler__assembleAsOpcodeInfo31(this, node, compiler, extraArg)
  int *this;
  int node;
  undefined4 compiler;
  undefined4 extraArg;
{
  undefined4 opcodeInfo;
  
  opcodeInfo = Opcode__getInfo(0x31);
  *(undefined4 *)(node + 0x88) = opcodeInfo;
  if (*(int *)(node + 0x98) != 0x2c) {
                    
                    
    (**(code **)(*this + 0x38))(this,node,compiler,extraArg);
    return;
  }
  return;
}

/* R300MachineAssembler__trackMaxLevelAndAssemble @ 0x196370 (64 bytes) */
int R300MachineAssembler__trackMaxLevelAndAssemble(this, registerIndex, node)
  int *this;
  int registerIndex;
  int node;
{
  int newMax;
  
  if ((*(int *)(node + 0x98) == 2) || (*(int *)(node + 0x98) == 0xc)) {
    newMax = this[0x1e];
    if (this[0x1e] < registerIndex) {
      newMax = registerIndex;
    }
    this[0x1e] = newMax;
  }
                    
                    
  (**(code **)(*this + 0x88))(this,node);
  return;
}

/* R300MachineAssembler__vslot5_beginProgram @ 0x1963b0 (236 bytes) */
int R300MachineAssembler__vslot5_beginProgram(param_1, param_2, param_3, param_4)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  int param_4;
{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_4 + 0x30c);
  uVar1 = FUN_000e14e4(param_4,0x963c,param_3);
  *(undefined4 *)(param_1 + 0x5c) = uVar1;
  _memset(uVar1,0,0x963c);
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x54) = 3;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  *(undefined4 *)(param_1 + 0x60) = 1;
  *(undefined4 *)(param_1 + 100) = 0;
  *(undefined4 *)(param_1 + 0x68) = 0;
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0x88) = 0;
  *(undefined4 *)(param_1 + 0x78) = 0;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  *(undefined4 *)(param_1 + 0x80) = 1;
  *(undefined4 *)(param_1 + 0x84) = 1;
  *(int *)(param_1 + 0xc) = param_4;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  *(undefined4 *)(param_1 + 0x14) = param_3;
  **(undefined4 **)(param_1 + 0x58) = 0;
  *(int *)(*(int *)(param_1 + 0x58) + 4) = *(int *)(*(int *)(param_4 + 0x30c) + 0x40) + 1;
  *(undefined4 *)(param_1 + 0x98) = 1;
  *(undefined4 *)(param_1 + 0x94) = 1;
  return;
}

/* R300MachineAssembler__noteFetchTextureUnit @ 0x19649c (128 bytes) */
int R300MachineAssembler__noteFetchTextureUnit(this, sourceIndex, inst)
  int this;
  undefined4 sourceIndex;
  undefined4 inst;
{
  int *a0;
  int registerRecord;
  
  a0 = (int *)IRInst__getOperandSource(inst,sourceIndex);
  registerRecord = (**(code **)(*a0 + 0x80))(a0);
  if (*(int *)(registerRecord + 0xb4) == 0x10303) {
    *(uint *)(*(int *)(this + 0x5c) + 0x936c) =
         1 << (*(uint *)(registerRecord + 0x148) & 0x3f) | *(uint *)(*(int *)(this + 0x5c) + 0x936c);
  }
  return;
}

/* FUN_0019651c @ 0x19651c (640 bytes) */
int FUN_0019651c(param_1, inst, param_3)
  int *param_1;
  int inst;
  uint param_3;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 a4;
  undefined4 a3;
  uint a2;
  code *pcVar4;
  int a1;
  uint loopIndex;
  
  a2 = 0;
  loopIndex = 0;
  do {
    iVar2 = IRInst__getOperandRecord(inst,0);
    if (*(char *)(loopIndex + iVar2 + 0x10) == '\x01') {
      a2 = a2 | 1 << (loopIndex & 0x3f);
    }
    bVar1 = loopIndex != 3;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  iVar2 = *(int *)(inst + 0x144);
  if ((iVar2 == 0x16) || (iVar2 == 0x17)) {
    pcVar4 = *(code **)(*param_1 + 0xc4);
    a1 = param_1[0x25];
    uVar3 = FUN_0010e40c(iVar2,*(undefined4 *)(inst + 0x148));
    a4 = thunk_FUN_00134de8(*(undefined4 *)(param_1[3] + 0x6c4),inst);
    a3 = 1;
  }
  else if (iVar2 == 0x1b) {
    a3 = 1;
    pcVar4 = *(code **)(*param_1 + 0xc4);
    a1 = param_1[0x25];
    uVar3 = *(undefined4 *)(inst + 0x148);
    iVar2 = FUN_000d9f3c(*(undefined4 *)(param_1[3] + 0x398),0);
    if (iVar2 == 0) {
      a3 = 3;
    }
    a4 = thunk_FUN_00134de8(*(undefined4 *)(param_1[3] + 0x6c4),inst);
  }
  else {
    if (iVar2 != 0x23) {
      pcVar4 = *(code **)(*param_1 + 200);
      loopIndex = *(uint *)(inst + 0x148);
      iVar2 = param_1[0x26];
      uVar3 = thunk_FUN_00134de8(*(undefined4 *)(param_1[3] + 0x6c4),inst);
      (*pcVar4)(param_1,iVar2,loopIndex,1,uVar3,(*(uint *)(inst + 0x13c) ^ 1) & 1);
      (**(code **)(*param_1 + 0xcc))(param_1,param_1[0x26],a2);
      iVar2 = param_1[3];
      param_1[0x26] = param_1[0x26] + 1;
      if (*(int *)(*(int *)(iVar2 + 0x6c4) + 0x80) < (int)loopIndex) {
        *(uint *)(*(int *)(iVar2 + 0x6c4) + 0x80) = loopIndex;
        iVar2 = param_1[3];
      }
      *(uint *)(*(int *)(iVar2 + 0x6c4) + 0x88) =
           1 << (loopIndex & 0x3f) | *(uint *)(*(int *)(iVar2 + 0x6c4) + 0x88);
      iVar2 = param_1[0x25];
      goto LAB_0019675c;
    }
    pcVar4 = *(code **)(*param_1 + 0xc4);
    a1 = param_1[0x25];
    uVar3 = *(undefined4 *)(inst + 0x148);
    a4 = thunk_FUN_00134de8(*(undefined4 *)(param_1[3] + 0x6c4),inst);
    a3 = 2;
  }
  (*pcVar4)(param_1,a1,uVar3,a3,a4,0);
  (**(code **)(*param_1 + 0xd0))(param_1,param_1[0x25],a2);
  iVar2 = param_1[0x25] + 1;
  param_1[0x25] = iVar2;
LAB_0019675c:
  if (iVar2 <= param_1[0x26]) {
    iVar2 = param_1[0x26];
  }
  param_1[0x1d] = iVar2 + -1;
  param_1[0x18] = iVar2;
  return;
}

/* R300MachineAssembler__resolveSourceRegister @ 0x19679c (188 bytes) */
int R300MachineAssembler__resolveSourceRegister(this, inst, sourceIndex, compiler)
  undefined4 this;
  undefined4 inst;
  undefined4 sourceIndex;
  int compiler;
{
  int *operandVReg;
  int callResult;
  
  operandVReg = (int *)IRInst__getOperandSource(inst,sourceIndex);
  if (((((operandVReg[0x20] == 0) || (callResult = FUN_00126760(operandVReg[0x26]), callResult == 0)) ||
       ((operandVReg[5] & 2U) != 0)) || (callResult = (**(code **)(*operandVReg + 0x50))(operandVReg), callResult != 0)) &&
     (callResult = (**(code **)(*operandVReg + 0x50))(operandVReg), callResult == 0)) {
    return;
  }
  thunk_FUN_00134de8(*(undefined4 *)(compiler + 0x6c4),operandVReg);
  return;
}

/* R300MachineAssembler__setAluSourceSelectsAndModifiers @ 0x196858 (640 bytes) */
int R300MachineAssembler__setAluSourceSelectsAndModifiers(this, irInst, writeRgb, rgbSelects, unused1, writeAlpha, alphaSelects, unused2, singleSource)
  int this;
  int *irInst;
  int writeRgb;
  int rgbSelects;
  undefined4 unused1;
  int writeAlpha;
  int alphaSelects;
  undefined4 unused2;
  int singleSource;
{
  bool hasThirdSource;
  bool notFirstSource;
  undefined1 modifierBits;
  int callResult;
  uint *sourceFlags;
  int loopIndex;
  
  loopIndex = 1;
  hasThirdSource = singleSource == 0;
  sourceFlags = (uint *)(irInst + 0x2e);
  do {
    callResult = (**(code **)(*irInst + 0x14))(irInst);
    if (callResult < loopIndex) {
      return;
    }
    notFirstSource = loopIndex != 1;
    if (notFirstSource) {
      if (loopIndex == 2) {
        if (writeRgb != 0) {
          *(char *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x2b) =
               (char)*(undefined4 *)(rgbSelects + 8);
        }
        if (writeAlpha != 0) {
          *(char *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x3a) =
               (char)*(undefined4 *)(alphaSelects + 8);
        }
      }
      else if ((loopIndex == 3) && (hasThirdSource)) {
        if (writeRgb != 0) {
          *(char *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x2c) =
               (char)*(undefined4 *)(rgbSelects + 0xc);
        }
        if (writeAlpha != 0) {
          *(char *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x3b) =
               (char)*(undefined4 *)(alphaSelects + 0xc);
        }
      }
    }
    else {
      if (writeRgb != 0) {
        *(char *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x2a) =
             (char)*(undefined4 *)(rgbSelects + 4);
      }
      if (writeAlpha != 0) {
        *(char *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x39) =
             (char)*(undefined4 *)(alphaSelects + 4);
      }
    }
    modifierBits = ((int (*)())packSourceModifier)(*sourceFlags & 1,*sourceFlags >> 1 & 1);
    if (writeAlpha != 0) {
      if (hasThirdSource) {
        if (!notFirstSource) goto LAB_001969d4;
        if (loopIndex == 2) {
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x3d) = modifierBits
          ;
        }
        else if (loopIndex == 3) {
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x3e) = modifierBits
          ;
        }
      }
      else if (loopIndex == 3) {
LAB_001969d4:
        *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x3c) = modifierBits;
      }
    }
    if (writeRgb != 0) {
      if (notFirstSource) {
        if (loopIndex == 2) {
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x2e) = modifierBits
          ;
        }
        else if ((loopIndex == 3) && (hasThirdSource)) {
          *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x2f) = modifierBits
          ;
        }
      }
      else {
        *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x2d) = modifierBits;
      }
    }
    loopIndex = loopIndex + 1;
    sourceFlags = sourceFlags + 6;
  } while( true );
}

/* R300MachineAssembler__setRgbOpcode @ 0x196ad8 (644 bytes) */
int R300MachineAssembler__setRgbOpcode(this, hardwareOpcode, irOpcode, irInst)
  int this;
  int hardwareOpcode;
  int irOpcode;
  int irInst;
{
  undefined1 savedModifier;
  int iVar2;
  undefined1 rgbOpcode;
  int iVar4;
  
  rgbOpcode = (undefined1)hardwareOpcode;
  *(undefined4 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58)) = 3;
  if (hardwareOpcode != -1) goto LAB_00196cf4;
  if (irOpcode == 0x31) {
LAB_00196bf8:
    rgbOpcode = 0;
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x2b) = 0x15;
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x2c) = 0x14;
    goto LAB_00196cf4;
  }
  if (irOpcode < 0x32) {
    if (irOpcode != 0x13) {
      if (irOpcode == 0x25) {
LAB_00196c34:
        iVar2 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58);
        rgbOpcode = *(undefined1 *)(iVar2 + 0x2a);
        *(undefined1 *)(iVar2 + 0x2a) = *(undefined1 *)(iVar2 + 0x2b);
        iVar4 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58);
        savedModifier = *(undefined1 *)(iVar2 + 0x2d);
        *(undefined1 *)(iVar4 + 0x2d) = *(undefined1 *)(iVar4 + 0x2e);
        iVar2 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58);
        *(undefined1 *)(iVar2 + 0x2b) = *(undefined1 *)(iVar2 + 0x2c);
        iVar2 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58);
        *(undefined1 *)(iVar2 + 0x2e) = *(undefined1 *)(iVar2 + 0x2f);
        *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x2c) = rgbOpcode;
        *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x2f) = savedModifier;
        if (irOpcode == 0x9d) {
          rgbOpcode = 7;
        }
        else {
          rgbOpcode = 8;
        }
        goto LAB_00196cf4;
      }
      if (irOpcode != 0x12) goto LAB_00196b58;
LAB_00196b80:
      rgbOpcode = 0;
      iVar2 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58);
      *(undefined1 *)(iVar2 + 0x2c) = *(undefined1 *)(iVar2 + 0x2b);
      iVar2 = *(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58);
      *(undefined1 *)(iVar2 + 0x2f) = *(undefined1 *)(iVar2 + 0x2e);
      *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x2b) = 0x15;
      *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x2e) = 0;
      goto LAB_00196cf4;
    }
  }
  else if (irOpcode != 0x36) {
    if (irOpcode < 0x37) {
      if (irOpcode == 0x34) goto LAB_00196b80;
    }
    else {
      if (irOpcode == 0x66) goto LAB_00196bf8;
      if (irOpcode == 0x9d) goto LAB_00196c34;
    }
LAB_00196b58:
    rgbOpcode = 0xff;
    goto LAB_00196cf4;
  }
  rgbOpcode = 0;
  *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x2c) = 0x14;
LAB_00196cf4:
  *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x31) = rgbOpcode;
  if (*(int *)(irInst + 0x120) != 0) {
    *(undefined1 *)(*(int *)(this + 0x60) * 0x48 + *(int *)(this + 0x58) + 0x33) = 1;
  }
  iVar4 = *(int *)(this + 0x60);
  iVar2 = *(int *)(this + 0x58);
  rgbOpcode = psnOutputScaleCode(*(undefined4 *)(irInst + 0x124));
  *(undefined1 *)(iVar4 * 0x48 + iVar2 + 0x32) = rgbOpcode;
  return;
}

/* R300MachineAssembler__create @ 0x196d5c (96 bytes) */
int R300MachineAssembler__create(unusedThis, compiler)
  undefined4 unusedThis;
  int compiler;
{
  undefined4 *allocation;
  undefined4 arena;
  
  arena = *(undefined4 *)(compiler + 0x378);
  allocation = (undefined4 *)Arena__alloc(arena,0xac);
  *allocation = arena;
  allocation[1] = &PTR_FUN_001eb6a0;
  allocation[7] = 0;
  return allocation + 1;
}

/* R300MachineAssembler__dtor_196dbc @ 0x196dbc (64 bytes) */
int R300MachineAssembler__dtor_196dbc(this)
  undefined4 *this;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e914c;
  this[0x16] = 0;
  *this = &PTR_FUN_001eb6a0;
  this[0x17] = 0;
  *this = puVar1 + 8;
  return;
}

/* R300MachineAssembler__dtor @ 0x196dfc (64 bytes) */
int R300MachineAssembler__dtor(this)
  undefined4 *this;
{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_001e914c;
  this[0x16] = 0;
  *this = &PTR_FUN_001eb6a0;
  this[0x17] = 0;
  *this = puVar1 + 8;
  return;
}

/* MachineAssembler__dtor_196e3c @ 0x196e3c (84 bytes) */
int MachineAssembler__dtor_196e3c(this)
  undefined4 *this;
{
  this[0x16] = 0;
  this[0x17] = 0;
  *this = &PTR_FUN_001eb6a0;
  *this = PTR_DAT_001e914c + 8;
  if (this == (undefined4 *)0x0) {
    return;
  }
  return Arena__free(this[-1],this + -1);
}

/* R300MachineAssembler__placeInstructionConstants @ 0x196e90 (872 bytes) */
int R300MachineAssembler__placeInstructionConstants(this, inst, constantAllocator)
  undefined4 this;
  int *inst;
  undefined4 constantAllocator;
{
  uint sourceLaneWord;
  int iVar2;
  int *piVar3;
  undefined4 operandVReg;
  int *a0;
  int callResult;
  int *operandVReg2;
  undefined4 operandVReg3;
  int iVar8;
  uint local_28 [3];
  
  iVar2 = *(int *)(inst[0x22] + 8);
  if ((((iVar2 == 0x9e) || (iVar2 == 0xa0)) || (iVar2 == 0x9f)) || (iVar8 = 1, iVar2 == 0xa1)) {
    iVar2 = IRInst__getOperandRecord(inst,0);
    if (((*(char *)(iVar2 + 0x10) == '\0') ||
        (iVar2 = IRInst__getOperandRecord(inst,0), *(char *)(iVar2 + 0x11) == '\0')) ||
       (iVar2 = IRInst__getOperandRecord(inst,0), *(char *)(iVar2 + 0x12) == '\0')) {
      operandVReg = IRInst__getOperandSource(inst,1);
      iVar2 = FUN_0018d388(constantAllocator,operandVReg,0);
      if (iVar2 == 0) {
        return 0;
      }
    }
    iVar2 = IRInst__getOperandRecord(inst,0);
    if (*(char *)(iVar2 + 0x13) == '\0') {
      operandVReg = IRInst__getOperandSource(inst,1);
      iVar2 = FUN_0018d388(constantAllocator,operandVReg,1);
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  else {
    for (; iVar2 = (**(code **)(*inst + 0x14))(inst), iVar8 <= iVar2; iVar8 = iVar8 + 1) {
      a0 = (int *)IRInst__getOperandSource(inst,iVar8);
      callResult = (**(code **)(*a0 + 0x60))(a0);
      piVar3 = inst;
      iVar2 = iVar8;
      if (callResult != 0) {
        operandVReg2 = (int *)IRInst__getOperandSource(a0,1);
        piVar3 = a0;
        iVar2 = 1;
        a0 = operandVReg2;
      }
      iVar2 = IRInst__getOperandRecord(piVar3,iVar2);
      FUN_000f3398(local_28,*(undefined4 *)(iVar2 + 0x10));
      sourceLaneWord = local_28[0];
      iVar2 = (**(code **)(*a0 + 0x5c))(a0);
      if (iVar2 == 0) {
        if ((a0[0x26] != 0x33) || (a0[0x4b] == 3)) {
          if ((sourceLaneWord & 0xffffff00) == 0) {
            if ((sourceLaneWord & 0xff) == 0) goto LAB_001971a8;
            iVar2 = FUN_0018c7f4(constantAllocator,a0,1);
          }
          else if ((sourceLaneWord & 0xff) == 0) {
            iVar2 = FUN_0018c7f4(constantAllocator,a0,0);
          }
          else {
            iVar2 = FUN_0018c980(constantAllocator,a0,a0);
          }
joined_r0x00197160:
          if (iVar2 == 0) {
            return 0;
          }
        }
      }
      else {
        if ((sourceLaneWord & 0xffffff00) != 0) {
          iVar2 = (**(code **)(*a0 + 0x14))(a0);
          if (iVar2 == 1) {
            operandVReg = IRInst__getOperandSource(a0,1);
            iVar2 = FUN_0018d388(constantAllocator,operandVReg,0);
          }
          else {
            operandVReg = IRInst__getOperandSource(a0,1);
            operandVReg3 = IRInst__getOperandSource(a0,2);
            iVar2 = FUN_0018cdd8(constantAllocator,operandVReg,operandVReg3,0);
          }
          if (iVar2 == 0) {
            return 0;
          }
        }
        if ((sourceLaneWord & 0xff) != 0) {
          iVar2 = (**(code **)(*a0 + 0x14))(a0);
          if (iVar2 == 1) {
            operandVReg = IRInst__getOperandSource(a0,1);
            iVar2 = FUN_0018d388(constantAllocator,operandVReg,1);
          }
          else {
            operandVReg = IRInst__getOperandSource(a0,1);
            operandVReg3 = IRInst__getOperandSource(a0,2);
            iVar2 = FUN_0018cdd8(constantAllocator,operandVReg,operandVReg3,1);
          }
          goto joined_r0x00197160;
        }
      }
LAB_001971a8: ;
    }
  }
  return 1;
}

/* R300MachineAssembler__assembleBlock @ 0x1971f8 (1652 bytes) */
int R300MachineAssembler__assembleBlock(this, block, startOfShaderFlag)
  int *this;
  int block;
  int startOfShaderFlag;
{
  uint *puVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  uint uVar9;
  int *piVar10;
  int iVar11;
  int *piVar12;
  int *a0;
  int *piVar13;
  code *pcVar14;
  int local_88;
  undefined1 auStack_84 [60];
  undefined4 local_48 [2];
  
  piVar13 = *(int **)(block + 8);
  bVar3 = false;
  if (piVar13[2] == 0) {
    return;
  }
  do {
    iVar11 = (**(code **)(*this + 8))(this);
    if (iVar11 != 0) {
      Compiler__fail(this[3],5);
    }
    iVar11 = this[3];
    if (**(int **)(iVar11 + 0x6c4) == 0) {
      piVar12 = (int *)FUN_000e3b88(this[4],block,piVar13,&local_88);
      if ((piVar12 == (int *)0x0) || (local_88 == 0)) {
        iVar11 = this[3];
      }
      else {
        iVar11 = this[3];
        piVar13 = piVar12;
      }
    }
    iVar11 = FUN_00106cf8(piVar13,*(undefined4 *)(iVar11 + 0x6c4));
    piVar12 = piVar13;
    if ((((iVar11 == 0) || (uVar9 = piVar13[5], (uVar9 & 4) != 0)) || ((int)uVar9 < 0)) ||
       ((uVar9 & 0x1000) != 0)) {
      PackState__reset(auStack_84);
      if (piVar13 == (int *)0x0) {
        bVar5 = false;
      }
      else {
        bVar5 = false;
        piVar10 = piVar13;
        do {
          uVar9 = piVar10[5];
          if ((uVar9 & 1) != 0) {
            if ((uVar9 & 0x80) != 0) {
              bVar5 = true;
            }
            if ((uVar9 & 0x10000) == 0) {
              ((int (*)())R300MachineAssembler__placeInstructionConstants)(this,piVar10,auStack_84);
              uVar9 = piVar10[5];
            }
          }
          piVar10 = (int *)piVar10[2];
        } while ((piVar10 != (int *)0x0) && ((uVar9 & 4) != 0));
      }
      FUN_0018c1c8(auStack_84,this + 7);
      if (piVar13 == (int *)0x0) {
LAB_00197808:
        piVar10 = (int *)piVar13[2];
      }
      else {
        bVar2 = false;
        bVar8 = false;
        bVar6 = false;
        bVar7 = false;
        piVar10 = piVar13;
        do {
          uVar9 = piVar10[5];
          if ((uVar9 & 1) != 0) {
            iVar11 = piVar10[0x47];
            pcVar14 = *(code **)(*this + 0x13c);
            FUN_00105d04(local_48,piVar10);
            (*pcVar14)(this,iVar11,local_48[0]);
            if ((piVar10[5] & 0x10000U) == 0) {
              if ((piVar10[5] & 2U) != 0) {
                a0 = (int *)IRInst__getOperandSource(piVar10,1);
                iVar11 = (**(code **)(*a0 + 0x50))(a0);
                if ((iVar11 != 0) &&
                   (iVar11 = IRInst__getOperandRecord(piVar10,0), *(int *)(iVar11 + 0x10) == 0x1010100))
                goto LAB_00197784;
              }
              iVar11 = (**(code **)(*piVar10 + 0x28))(piVar10);
              if (iVar11 == 0) {
                if (!bVar2) {
                  bVar2 = true;
                  (**(code **)(*this + 0xc0))(this);
                }
                if (this[0x23] == 0) {
                  *(undefined4 *)(*(int *)(this[3] + 0x6c4) + 0x3cc) = 1;
                  this[0x23] = 2;
                }
                else if (this[0x23] == 1) {
                  this[0x23] = 2;
                  (**(code **)(*this + 0x148))(this);
                }
                bVar4 = !bVar3;
                if (bVar4) {
                  bVar6 = true;
                  goto LAB_00197624;
                }
                bVar6 = true;
              }
              else {
                iVar11 = this[0x23];
                if (iVar11 == 0) {
                  this[0x23] = 1;
                  (**(code **)(*this + 0x134))(this);
                }
                else {
                  if (iVar11 != 2) {
                    if ((iVar11 != 1) || ((piVar10[5] & 0x1000U) == 0)) goto LAB_0019752c;
                    (**(code **)(*this + 0x148))(this);
                  }
                  this[0x23] = 1;
                  (**(code **)(*this + 0x134))(this);
                  (**(code **)(*this + 0x138))(this);
                }
LAB_0019752c:
                bVar3 = false;
                bVar7 = true;
                bVar4 = true;
LAB_00197624:
                if (*(int *)(piVar10[0x22] + 8) == 0xb4) {
                  piVar10[5] = piVar10[5] | 0x1000;
                }
              }
              (**(code **)(*piVar10 + 0x1c))(piVar10,this,0,this[3]);
              if (bVar4) {
                if ((((piVar10[5] & 0x1000U) != 0) || (startOfShaderFlag != 0)) || ((piVar10[5] & 2U) != 0)) {
                  (**(code **)(*this + 0x14c))(this);
                  iVar11 = (**(code **)(*piVar10 + 0x28))(piVar10);
                  if (iVar11 == 0) {
                    bVar3 = true;
                    startOfShaderFlag = 0;
                    goto LAB_001976d0;
                  }
                }
                bVar3 = false;
                startOfShaderFlag = 0;
              }
LAB_001976d0:
              if (bVar5) {
                (**(code **)(*this + 0x114))(this);
              }
              if (this[6] != 0) {
                (**(code **)(*this + 0x140))(this);
              }
              (**(code **)(*piVar10 + 0x20))(piVar10,this,0,this[3]);
              iVar11 = (**(code **)(*piVar10 + 0x28))(piVar10);
              if (iVar11 != 0) {
                this[0x1a] = this[0x1a] + 1;
                (**(code **)(*this + 0x15c))(this);
                uVar9 = piVar10[5];
                goto LAB_00197788;
              }
            }
            else {
              iVar11 = (**(code **)(*piVar10 + 0x5c))(piVar10);
              if (iVar11 != 0) {
                bVar8 = true;
              }
              iVar11 = (**(code **)(*piVar10 + 0x48))(piVar10);
              if (iVar11 != 0) {
                ((int (*)())R300MachineAssembler__callSlot65)(this,(uint)piVar10,this[3]);
              }
              iVar11 = (**(code **)(*piVar10 + 0x4c))(piVar10);
              if (iVar11 != 0) {
                ((int (*)())FUN_0019651c)(this,piVar10,this[3]);
              }
              iVar11 = (**(code **)(*piVar10 + 0x38))(piVar10);
              if ((iVar11 != 0) && (this[0x23] == 1)) {
                (**(code **)(*this + 0x148))(this);
                uVar9 = piVar10[5];
                goto LAB_00197788;
              }
            }
LAB_00197784:
            uVar9 = piVar10[5];
          }
LAB_00197788:
          piVar10 = (int *)piVar10[2];
        } while ((piVar10 != (int *)0x0) && ((uVar9 & 4) != 0));
        if (bVar6) {
          (**(code **)(*this + 0x15c))(this);
          this[0x19] = this[0x19] + 1;
          piVar10 = (int *)piVar13[2];
        }
        else {
          if ((bVar7) || (!bVar8)) goto LAB_00197808;
          (**(code **)(*this + 0x110))(this);
          piVar10 = (int *)piVar13[2];
        }
      }
    }
    else {
      *(int *)(this[4] + 0xc) = *(int *)(this[4] + 0xc) + 1;
      piVar10 = (int *)piVar13[2];
    }
    do {
      piVar13 = piVar10;
      puVar1 = (uint *)(piVar12 + 5);
      if ((int *)piVar13[2] == (int *)0x0) {
        return;
      }
      piVar10 = (int *)piVar13[2];
      piVar12 = piVar13;
    } while ((*puVar1 & 4) != 0);
  } while( true );
}

/* R300MachineAssembler__classifyAluOperation @ 0x19786c (672 bytes) */
int R300MachineAssembler__classifyAluOperation(this, rgbLaneBytes, alphaLaneBytes, irInst, rgbHardwareOpcodeOut, alphaHardwareOpcodeOut)
  int *this;
  undefined4 *rgbLaneBytes;
  undefined4 *alphaLaneBytes;
  int irInst;
  undefined4 *rgbHardwareOpcodeOut;
  undefined4 *alphaHardwareOpcodeOut;
{
  char laneW;
  char laneY;
  undefined4 uVar3;
  uint classFlags;
  undefined1 laneEnableByte;
  char laneZ;
  undefined4 opcodeClass;
  int irOpcode;
  
  *alphaLaneBytes = 0;
  alphaLaneBytes[1] = 0;
  *rgbLaneBytes = 0;
  rgbLaneBytes[1] = 0;
  irOpcode = *(int *)(*(int *)(irInst + 0x88) + 8);
  if (irOpcode == 0x35) {
    IROperand__setModifierBits(irInst + 0xbc,1,*(uint *)(irInst + 0xd0) & 1 ^ 1);
    uVar3 = Opcode__getInfo(0x34);
    irOpcode = 0x34;
    *(undefined4 *)(irInst + 0x88) = uVar3;
  }
  opcodeClass = *(undefined4 *)(PTR_DAT_001e913c + irOpcode * 0x38 + 0x34);
  uVar3 = ((int (*)())opcodeInfoRgbHwOpcode)(this[0x29],irOpcode);
  *rgbHardwareOpcodeOut = uVar3;
  uVar3 = ((int (*)())opcodeInfoAlphaHwOpcode)(this[0x29],irOpcode);
  *alphaHardwareOpcodeOut = uVar3;
  irOpcode = IRInst__getOperandRecord(irInst,0);
  this[0x28] = *(int *)(irOpcode + 0x10);
  switch(opcodeClass) {
  case 0:
    if (*(char *)(this + 0x28) == '\0') {
      laneY = *(char *)((int)this + 0xa1);
      laneZ = *(char *)((int)this + 0xa2);
LAB_001979d4:
      classFlags = 1;
    }
    else {
      laneY = *(char *)((int)this + 0xa1);
      if (laneY == '\0') {
        laneZ = *(char *)((int)this + 0xa2);
        goto LAB_001979d4;
      }
      laneZ = *(char *)((int)this + 0xa2);
      classFlags = 0;
      if (laneZ == '\0') goto LAB_001979d4;
    }
    laneW = *(char *)((int)this + 0xa3);
    if (laneW == '\0') {
      classFlags = classFlags | 2;
    }
    if (*(char *)(this + 0x28) == '\0') {
      laneEnableByte = 0xff;
    }
    else {
      laneEnableByte = 0;
    }
    *(undefined1 *)rgbLaneBytes = laneEnableByte;
    laneEnableByte = 0xff;
    if (laneY != '\0') {
      laneEnableByte = 0;
    }
    *(undefined1 *)((int)rgbLaneBytes + 1) = laneEnableByte;
    laneEnableByte = 0xff;
    if (laneZ != '\0') {
      laneEnableByte = 0;
    }
    *(undefined1 *)((int)rgbLaneBytes + 2) = laneEnableByte;
    laneEnableByte = 0xff;
    if (laneW != '\0') {
      laneEnableByte = 0;
    }
    goto LAB_00197b18;
  case 1:
    classFlags = 5;
    if (*(char *)((int)this + 0xa3) == '\0') {
      classFlags = 7;
      *alphaHardwareOpcodeOut = 1;
    }
    *(undefined1 *)((int)rgbLaneBytes + 6) = 0xff;
    *(undefined1 *)((int)rgbLaneBytes + 1) = 0xff;
    *(undefined1 *)rgbLaneBytes = 0xff;
    break;
  case 2:
    classFlags = 1;
    if (*(char *)((int)this + 0xa3) == '\0') {
      classFlags = 3;
      *alphaHardwareOpcodeOut = 1;
    }
    *(undefined1 *)((int)rgbLaneBytes + 2) = 0xff;
    *(undefined1 *)rgbLaneBytes = 0xff;
    *(undefined1 *)((int)rgbLaneBytes + 1) = 0xff;
    break;
  case 3:
    classFlags = 3;
    goto LAB_00197aa4;
  default:
    classFlags = 0;
    break;
  case 5:
    if (((*(char *)(this + 0x28) == '\0') || (*(char *)((int)this + 0xa1) == '\0')) ||
       (classFlags = 2, *(char *)((int)this + 0xa2) == '\0')) {
      *rgbHardwareOpcodeOut = 10;
      (**(code **)(*this + 0x150))(this,10);
      classFlags = 0xb;
    }
    laneEnableByte = 0xff;
LAB_00197b18:
    *(undefined1 *)((int)alphaLaneBytes + 3) = laneEnableByte;
    break;
  case 8:
    classFlags = 0x13;
LAB_00197aa4:
    *alphaHardwareOpcodeOut = 1;
    *(undefined1 *)((int)alphaLaneBytes + 3) = 0xff;
    *(undefined1 *)((int)rgbLaneBytes + 2) = 0xff;
    *(undefined1 *)rgbLaneBytes = 0xff;
    *(undefined1 *)((int)rgbLaneBytes + 1) = 0xff;
  }
  return classFlags;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl FUN_00195474");
asm(".set FUN_00195474, _R300MachineAssembler__vslot12_assembleNodeAndMarkChildren");
asm(".globl FUN_00195574");
asm(".set FUN_00195574, _R300MachineAssembler__vslot6_noOp");
asm(".globl FUN_00195578");
asm(".set FUN_00195578, _R300MachineAssembler__vslot8_returnsTrue");
asm(".globl FUN_00195580");
asm(".set FUN_00195580, _R300MachineAssembler__vslot3_noOp");
asm(".globl FUN_00195584");
asm(".set FUN_00195584, _R300MachineAssembler__vslot9_getRecordBufferWords");
asm(".globl FUN_00195590");
asm(".set FUN_00195590, _psnLiteralAddressFromRegisterWord");
asm(".globl FUN_001955dc");
asm(".set FUN_001955dc, _R300MachineAssembler__vslot65_declareNodeRegisters");
asm(".globl FUN_001955f8");
asm(".set FUN_001955f8, _R300MachineAssembler__vslot2_exceedsInstructionLimit");
asm(".globl FUN_0019561c");
asm(".set FUN_0019561c, _R300MachineAssembler__vslot38_returnsFalse");
asm(".globl FUN_00195624");
asm(".set FUN_00195624, _R300MachineAssembler__vslot36_noOp");
asm(".globl FUN_00195628");
asm(".set FUN_00195628, _R300MachineAssembler__vslot39_noOp");
asm(".globl FUN_0019562c");
asm(".set FUN_0019562c, _R300MachineAssembler__vslot40_noOp");
asm(".globl FUN_00195630");
asm(".set FUN_00195630, _R300MachineAssembler__vslot41_noOp");
asm(".globl FUN_00195634");
asm(".set FUN_00195634, _R300MachineAssembler__vslot42_noOp");
asm(".globl FUN_00195638");
asm(".set FUN_00195638, _R300MachineAssembler__vslot29_noOp");
asm(".globl FUN_0019563c");
asm(".set FUN_0019563c, _R300MachineAssembler__vslot43_noOp");
asm(".globl FUN_00195640");
asm(".set FUN_00195640, _R300MachineAssembler__vslot44_noOp");
asm(".globl FUN_001956e8");
asm(".set FUN_001956e8, _R300MachineAssembler__callSlot14");
asm(".globl FUN_001956f8");
asm(".set FUN_001956f8, _R300MachineAssembler__vslot16_noOp");
asm(".globl FUN_001956fc");
asm(".set FUN_001956fc, _R300MachineAssembler__vslot19_noOp");
asm(".globl FUN_00195700");
asm(".set FUN_00195700, _R300MachineAssembler__vslot20_noOp");
asm(".globl FUN_00195704");
asm(".set FUN_00195704, _R300MachineAssembler__vslot21_noOp");
asm(".globl FUN_00195708");
asm(".set FUN_00195708, _R300MachineAssembler__vslot22_noOp");
asm(".globl FUN_0019570c");
asm(".set FUN_0019570c, _R300MachineAssembler__initNopAluRecord");
asm(".globl FUN_00195794");
asm(".set FUN_00195794, _R300MachineAssembler__setRsColorFields");
asm(".globl FUN_001957d8");
asm(".set FUN_001957d8, _R300MachineAssembler__setRsTexCoordFields");
asm(".globl FUN_0019581c");
asm(".set FUN_0019581c, _R300MachineAssembler__rgbSelectForSrcpSwizzle");
asm(".globl FUN_00195920");
asm(".set FUN_00195920, _R300MachineAssembler__alphaSelectForSrcpComponent");
asm(".globl FUN_0019598c");
asm(".set FUN_0019598c, _R300MachineAssembler__rgbSelectForAlphaSource");
asm(".globl FUN_001959fc");
asm(".set FUN_001959fc, _R300MachineAssembler__rgbSelectForSourceSwizzle");
asm(".globl FUN_00195b4c");
asm(".set FUN_00195b4c, _R300MachineAssembler__alphaSelectForAlphaSource");
asm(".globl FUN_00195b5c");
asm(".set FUN_00195b5c, _R300MachineAssembler__alphaSelectForColorComponent");
asm(".globl FUN_00195bb0");
asm(".set FUN_00195bb0, _R300MachineAssembler__setAluSourceAddresses");
asm(".globl FUN_00195cec");
asm(".set FUN_00195cec, _R300MachineAssembler__setAlphaOpcode");
asm(".globl FUN_00195f70");
asm(".set FUN_00195f70, _R300MachineAssembler__setAlphaTempWriteEnable");
asm(".globl FUN_00195f8c");
asm(".set FUN_00195f8c, _R300MachineAssembler__closeTextureIndirectionLevel");
asm(".globl FUN_00195fd8");
asm(".set FUN_00195fd8, _R300MachineAssembler__writeHeaderRecord");
asm(".globl FUN_00196070");
asm(".set FUN_00196070, _R300MachineAssembler__beginNextRecord");
asm(".globl FUN_001961c8");
asm(".set FUN_001961c8, _R300MachineAssembler__vslot4_finishProgram");
asm(".globl FUN_001962f0");
asm(".set FUN_001962f0, _R300MachineAssembler__assembleAsOpcodeInfo31");
asm(".globl FUN_001963b0");
asm(".set FUN_001963b0, _R300MachineAssembler__vslot5_beginProgram");
asm(".globl FUN_0019649c");
asm(".set FUN_0019649c, _R300MachineAssembler__noteFetchTextureUnit");
asm(".globl FUN_0019679c");
asm(".set FUN_0019679c, _R300MachineAssembler__resolveSourceRegister");
asm(".globl FUN_00196858");
asm(".set FUN_00196858, _R300MachineAssembler__setAluSourceSelectsAndModifiers");
asm(".globl FUN_00196ad8");
asm(".set FUN_00196ad8, _R300MachineAssembler__setRgbOpcode");
asm(".globl FUN_00196d5c");
asm(".set FUN_00196d5c, _R300MachineAssembler__create");
asm(".globl FUN_00196dfc");
asm(".set FUN_00196dfc, _R300MachineAssembler__dtor");
asm(".globl FUN_00196e3c");
asm(".set FUN_00196e3c, _MachineAssembler__dtor_196e3c");
asm(".globl FUN_001971f8");
asm(".set FUN_001971f8, _R300MachineAssembler__assembleBlock");
