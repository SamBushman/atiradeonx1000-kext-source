#include "decls.h"

/* ParseOperand__GetSwizzle @ 0x97bbbfc0 (12 bytes) */
int ParseOperand__GetSwizzle(this, param_2)
  unsigned char * this;
  uint param_2;
{
  return *(undefined1 *)(param_2 + *(int *)(this + 0x10));
}

/* ParseOperand__ClearSwizzles @ 0x97bbbfcc (68 bytes) */
int ParseOperand__ClearSwizzles(this)
  unsigned char * this;
{
  if (*(int *)(this + 0x10) != 0) {
    _free(*(int *)(this + 0x10));
  }
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  return;
}

/* ParseOperand__GetString @ 0x97bbc010 (584 bytes) */
int ParseOperand__GetString(this)
  unsigned char * this;
{
  int elemOffset;
  char *allocation2;
  int length;
  short glTypeSigned;
  ushort glType;
  int symbolPtr;
  char *formatString;
  char *allocation;
  int length2;
  int length3;
  uint baseSize;
  undefined4 r4Out0;
  char *valueArg;
  uint component;
  double unusedFpArg3;
  double unusedFpArg4;
  double unusedFpArg5;
  double unusedFpArg6;
  double unusedFpArg7;
  double unusedFpArg8;
  double unusedStackArg0;
  double unusedStackArg1;
  double unusedStackArg2;
  double unusedStackArg3;
  double unusedStackArg4;
  
  if (*(int *)this != 0) {
    length = _strlen(*(undefined4 *)(*(int *)this + 0x14));
    allocation2 = (char *)_malloc(length + 1);
    _sprintf(allocation2,DAT_a7b7bbdc,*(undefined4 *)(*(int *)this + 0x14));
    return allocation2;
  }
  if (*(int *)(this + 4) == 0) {
    allocation = (char *)_malloc(10);
    formatString = DAT_a7b7bbf0;
LAB_97bbc23c:
    _sprintf(allocation,formatString);
  }
  else {
    allocation = (char *)_malloc(0xa0);
    *allocation = '\0';
    symbolPtr = *(int *)this;
    if (symbolPtr == 0) {
      glTypeSigned = *(short *)(this + 0x18);
    }
    else {
      glTypeSigned = *(short *)(symbolPtr + 0x2c);
    }
    if (glTypeSigned != 0x1406) {
      if (symbolPtr == 0) {
        glTypeSigned = *(short *)(this + 0x18);
      }
      else {
        glTypeSigned = *(short *)(symbolPtr + 0x2c);
      }
      if (glTypeSigned != 0x1404) {
        if (symbolPtr == 0) {
          glTypeSigned = *(short *)(this + 0x18);
        }
        else {
          glTypeSigned = *(short *)(symbolPtr + 0x2c);
        }
        formatString = DAT_a7b7bbec;
        if (glTypeSigned != -0x74aa) goto LAB_97bbc23c;
      }
    }
    for (component = 0; baseSize = ParseOperand__GetBaseSize(this), component < baseSize; component = component + 1) {
      if (component != 0) {
        _sprintf(allocation,DAT_a7b7bbe0,allocation);
      }
      if (*(int *)this == 0) {
        glType = *(ushort *)(this + 0x18);
      }
      else {
        glType = *(ushort *)(*(int *)this + 0x2c);
      }
      if (glType == 0x1406) {
        _sprintf(allocation,"%s ",allocation);
        length2 = _strlen(allocation);
        length3 = _strlen(allocation);
        elemOffset = component * 4;
        ((char * (*)())_glp_dtostr)(length3,r4Out0,allocation + length2,0x9f - length3,
                    (double)*(float *)(elemOffset + *(int *)(this + 4)),1e-07,unusedFpArg3,unusedFpArg4,unusedFpArg5,unusedFpArg6,
                    unusedFpArg7,unusedFpArg8,unusedStackArg0,unusedStackArg1,unusedStackArg2,
                    unusedStackArg3,unusedStackArg4);
LAB_97bbc1b0:
        valueArg = *(char **)(elemOffset + *(int *)(this + 4));
        formatString = DAT_a7b7bbe8;
LAB_97bbc1ec:
        _sprintf(allocation,formatString,allocation,valueArg);
      }
      else if (glType < 0x1407) {
        if (glType == 0x1404) {
          elemOffset = component << 2;
          goto LAB_97bbc1b0;
        }
      }
      else if (glType == 0x8b56) {
        formatString = DAT_a7b7bbc4;
        if (*(int *)(component * 4 + *(int *)(this + 4)) == 0) {
          valueArg = "false";
        }
        else {
          valueArg = "true";
        }
        goto LAB_97bbc1ec;
      }
    }
  }
  return allocation;
}

/* __ZN16ParseSymbolTableC2Ej @ 0x97bbc258 (4 bytes) */
int __ZN16ParseSymbolTableC2Ej(this, param_2)
  void *this;
  uint param_2;
{
  int iVar1;
  void *allocation;
  uint loopIndex;
  
  *(uint *)((int)this + 0x10) = param_2;
  allocation = operator_new__(param_2 << 2);
  loopIndex = 0;
  *(void **)((int)this + 8) = allocation;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  if (*(int *)((int)this + 0x10) != 0) {
    do {
      iVar1 = loopIndex * 4;
      loopIndex = loopIndex + 1;
      *(undefined4 *)(iVar1 + *(int *)((int)this + 8)) = 0;
    } while (loopIndex < *(uint *)((int)this + 0x10));
  }
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  return;
}

/* __ZN16ParseSymbolTableC1Ej @ 0x97bbc25c (4 bytes) */
int __ZN16ParseSymbolTableC1Ej(this, param_2)
  void *this;
  uint param_2;
{
  int iVar1;
  void *allocation;
  uint loopIndex;
  
  *(uint *)((int)this + 0x10) = param_2;
  allocation = operator_new__(param_2 << 2);
  loopIndex = 0;
  *(void **)((int)this + 8) = allocation;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  if (*(int *)((int)this + 0x10) != 0) {
    do {
      iVar1 = loopIndex * 4;
      loopIndex = loopIndex + 1;
      *(undefined4 *)(iVar1 + *(int *)((int)this + 8)) = 0;
    } while (loopIndex < *(uint *)((int)this + 0x10));
  }
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  return;
}

/* __ZN16ParseSymbolTableC4Ej @ 0x97bbc260 (184 bytes) */
int __ZN16ParseSymbolTableC4Ej(this, param_2)
  void *this;
  uint param_2;
{
  int iVar1;
  void *allocation;
  uint loopIndex;
  
  *(uint *)((int)this + 0x10) = param_2;
  allocation = operator_new__(param_2 << 2);
  loopIndex = 0;
  *(void **)((int)this + 8) = allocation;
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  if (*(int *)((int)this + 0x10) != 0) {
    do {
      iVar1 = loopIndex * 4;
      loopIndex = loopIndex + 1;
      *(undefined4 *)(iVar1 + *(int *)((int)this + 8)) = 0;
    } while (loopIndex < *(uint *)((int)this + 0x10));
  }
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  *(undefined4 *)((int)this + 0x48) = 0;
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  return;
}

/* __ZN16ParseSymbolTableD2Ev @ 0x97bbc318 (8 bytes) */
int __ZN16ParseSymbolTableD2Ev(this)
  void *this;
{
  return ((int (*)())__ZN16ParseSymbolTableD4Ev)(this);
}

/* __ZN16ParseSymbolTableD1Ev @ 0x97bbc320 (8 bytes) */
int __ZN16ParseSymbolTableD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN16ParseSymbolTableD4Ev)(this);
}

/* __ZN16ParseSymbolTableD4Ev @ 0x97bbc328 (92 bytes) */
int __ZN16ParseSymbolTableD4Ev(this)
  void *this;
{
  void *this_00;
  void *pvVar1;
  
  this_00 = *(void **)this;
  while (this_00 != (void *)0x0) {
    pvVar1 = *(void **)((int)this_00 + 8);
    __ZN11ParseSymbolD1Ev(this_00);
    __ZdlPv(this_00);
    this_00 = pvVar1;
  }
  return __ZdlPv(*(void **)((int)this + 8));
}

/* ParseSymbolTable__processOperand @ 0x97bbc384 (252 bytes) */
int ParseSymbolTable__processOperand(this, parseOperand)
  unsigned char * this;
  unsigned char * parseOperand;
{
  bool bVar1;
  unsigned char * pPVar2;
  int iVar3;
  unsigned char * this_00;
  
  if (((parseOperand != (unsigned char *)0x0) &&
      (this_00 = *(unsigned char **)parseOperand, this_00 != (unsigned char *)0x0)) &&
     (*(int *)(this_00 + 0x50) == 0)) {
    if (*(int *)(this_00 + 0x48) == 0) {
      *(undefined2 *)(this_00 + 0x30) = 0;
    }
    else {
      ParseSymbol__SetArrayPositionFromLastIndex(this_00);
    }
    pPVar2 = (unsigned char *)((int (*)())ParseSymbolTable__FindSymbol)(this,this_00);
    if (pPVar2 == (unsigned char *)0x0) {
      pPVar2 = (unsigned char *)((int (*)())ParseSymbolTable__InsertSymbol)(this,this_00);
      bVar1 = pPVar2 == (unsigned char *)0x0;
    }
    else {
      __ZN11ParseSymbolD1Ev(this_00);
      __ZdlPv(this_00);
      bVar1 = false;
    }
    if (((!bVar1) && (*(unsigned char **)parseOperand = pPVar2, *(int *)(pPVar2 + 0x34) != 0)) &&
       (iVar3 = GetBuiltInInitialSwizzle(pPVar2), iVar3 != 0)) {
      ParseOperand__AddSwizzle(parseOperand,(uchar)iVar3);
      return;
    }
  }
  return;
}

/* ParseSymbolTable__AddSymbol @ 0x97bbc480 (140 bytes) */
int ParseSymbolTable__AddSymbol(this, parseSymbol)
  unsigned char * this;
  unsigned char * parseSymbol;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(this + 4) == 0) {
    *(unsigned char **)this = parseSymbol;
    iVar3 = *(int *)(this + 8);
    iVar1 = (*(uint *)(parseSymbol + 0x1c) -
            (*(uint *)(parseSymbol + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4;
  }
  else {
    *(unsigned char **)(*(int *)(this + 4) + 8) = parseSymbol;
    iVar3 = *(int *)(this + 8);
    iVar1 = (*(uint *)(parseSymbol + 0x1c) -
            (*(uint *)(parseSymbol + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4;
    iVar2 = *(int *)(iVar1 + iVar3);
    if (*(int *)(iVar1 + iVar3) != 0) {
      do {
        iVar1 = iVar2;
        iVar2 = *(int *)(iVar1 + 4);
      } while (iVar2 != 0);
      *(unsigned char **)(iVar1 + 4) = parseSymbol;
      goto LAB_97bbc4f8;
    }
  }
  *(unsigned char **)(iVar1 + iVar3) = parseSymbol;
LAB_97bbc4f8:
  *(unsigned char **)(this + 4) = parseSymbol;
  *(int *)(this + 0x14) = *(int *)(this + 0x14) + 1;
  return;
}

/* ParseSymbolTable__InsertSingleSymbol @ 0x97bbc50c (1504 bytes) */
int ParseSymbolTable__InsertSingleSymbol(this, parseSymbol)
  unsigned char * this;
  unsigned char * parseSymbol;
{
  uint arraySizeLimit;
  uint registerClassBits;
  int firstChunk;
  int arrayTrackingMode;
  int scalerWidth;
  int chunkList;
  bool isExtraVec4;
  byte chunkKind;
  int nextIndex;
  short counterLow;
  unsigned char * symbolChunk;
  int *r3In0;
  int typeKind;
  int *r3In1;
  uint vec4Count;
  undefined4 r4In0;
  undefined4 strayR5;
  undefined4 strayR6;
  undefined4 strayR7;
  undefined4 strayR8;
  uint registerSlot;
  undefined4 needsRegisters;
  uint vec4Index;
  byte *curChunk;
  uint usageEntry [6];
  
  symbolChunk = (unsigned char *)GetChunkForSymbol(parseSymbol,*(int *)(this + 0x3c));
  *(undefined4 *)(parseSymbol + 4) = 0;
  *(undefined4 *)(parseSymbol + 8) = 0;
  ((int (*)())ParseSymbolTable__AddSymbol)(this,parseSymbol);
  *(undefined4 *)(parseSymbol + 0x50) = 1;
  if (*(int *)(parseSymbol + 0x38) == 0) {
    needsRegisters = 0;
    if ((*(int *)(parseSymbol + 0x58) == 0) && (*(int *)(parseSymbol + 0x3c) == 0)) {
      r3In0 = *(int **)(parseSymbol + 0xc);
      r3In1 = (int *)0x0;
      if (r3In0 != (int *)0x0) {
        typeKind = (**(code **)(*r3In0 + 0x24))(r3In0);
        if ((((typeKind != 0) &&
             (typeKind = (**(code **)(**(int **)(parseSymbol + 0xc) + 0x24))(*(int **)(parseSymbol + 0xc)),
             typeKind != 9)) &&
            (typeKind = (**(code **)(**(int **)(parseSymbol + 0xc) + 0x24))(*(int **)(parseSymbol + 0xc)),
            typeKind != 10)) &&
           ((typeKind = (**(code **)(**(int **)(parseSymbol + 0xc) + 0x24))(*(int **)(parseSymbol + 0xc)),
            typeKind != 0xb &&
            (typeKind = (**(code **)(**(int **)(parseSymbol + 0xc) + 0x24))(*(int **)(parseSymbol + 0xc)),
            typeKind != 0xc)))) {
          needsRegisters = 1;
        }
        goto LAB_97bbc61c;
      }
    }
    else {
LAB_97bbc61c:
      r3In1 = *(int **)(parseSymbol + 0xc);
    }
    *(undefined4 *)(parseSymbol + 0x38) = needsRegisters;
  }
  else {
    r3In1 = *(int **)(parseSymbol + 0xc);
  }
  typeKind = (**(code **)(*r3In1 + 0x24))(r3In1);
  *(uint *)(parseSymbol + 0x60) = (uint)(typeKind == 4);
  typeKind = **(int **)(parseSymbol + 0xc);
  typeKind = (**(code **)(typeKind + 0x24))(*(int **)(parseSymbol + 0xc),r4In0,strayR5,strayR6,strayR7,strayR8,typeKind);
  *(uint *)(parseSymbol + 0x5c) = (uint)(typeKind == 5);
  *(undefined4 *)(parseSymbol + 0x54) = *(undefined4 *)(this + 0x50);
  vec4Count = GetVec4sForType((uint)*(ushort *)(parseSymbol + 0x2c));
  ParseSymbol__SetChunk(parseSymbol,symbolChunk);
  curChunk = *(byte **)parseSymbol;
  *(undefined4 *)(parseSymbol + 0x44) = 0;
  if (curChunk == (byte *)0x0) {
    return parseSymbol;
  }
  chunkKind = *curChunk;
  if (chunkKind == 2) {
    chunkList = *(int *)(*(int *)(this + 0xc) + 0x18);
    goto LAB_97bbc70c;
  }
  if (chunkKind < 3) {
    if (chunkKind == 0) {
      chunkList = *(int *)(*(int *)(this + 0xc) + 4);
      goto LAB_97bbc70c;
    }
  }
  else {
    if (chunkKind == 3) {
      chunkList = *(int *)(*(int *)(this + 0xc) + 0x10);
      goto LAB_97bbc70c;
    }
    if (chunkKind == 4) {
      chunkList = *(int *)(*(int *)(this + 0xc) + 0x1c);
      goto LAB_97bbc70c;
    }
  }
  chunkList = 0;
LAB_97bbc70c:
  vec4Index = 0;
  if ((vec4Count != 0) && (chunkList != 0)) {
    do {
      isExtraVec4 = vec4Index != 0;
      if (isExtraVec4) {
        curChunk = (byte *)_PPStreamChunkCreateFromChunk(curChunk);
      }
      chunkKind = *curChunk;
      if (chunkKind == 2) {
        nextIndex = *(int *)(this + 0x18);
        *(short *)(curChunk + 0x12) = (short)nextIndex;
        *(int *)(this + 0x18) = nextIndex + 1;
        if ((*(uint *)(curChunk + 0xc) & 0xf0000) == 0x90000) {
          registerSlot = *(uint *)(this + 0x1c);
          *(uint *)(curChunk + 0xc) = registerSlot & 0x1f | *(uint *)(curChunk + 0xc) & 0xffffffe0;
          *(uint *)(this + 0x1c) = registerSlot + 1;
          scalerWidth = GetScalerWidthForType((uint)*(ushort *)(parseSymbol + 0x2c));
          *(int *)(this + 0x20) = *(int *)(this + 0x20) + scalerWidth;
        }
      }
      else if (chunkKind < 3) {
        if (chunkKind == 0) {
          nextIndex = *(int *)(this + 0x38);
          *(short *)(curChunk + 0x12) = (short)nextIndex;
          *(int *)(this + 0x38) = nextIndex + 1;
          if (*(int *)(parseSymbol + 0x60) == 0) {
            if (*(int *)(parseSymbol + 0x5c) != 0) {
              registerSlot = *(uint *)(this + 0x34);
              *(uint *)(curChunk + 0xc) = registerSlot & 0x1f | *(uint *)(curChunk + 0xc) & 0xffffffe0;
              *(uint *)(this + 0x34) = registerSlot + 1;
            }
          }
          else {
            registerSlot = *(uint *)(this + 0x1c);
            *(uint *)(curChunk + 0xc) = registerSlot & 0x1f | *(uint *)(curChunk + 0xc) & 0xffffffe0;
            *(uint *)(this + 0x1c) = registerSlot + 1;
            scalerWidth = GetScalerWidthForType((uint)*(ushort *)(parseSymbol + 0x2c));
            *(int *)(this + 0x20) = *(int *)(this + 0x20) + scalerWidth;
          }
          if (*(int *)(this + 0x50) != 0) {
            curChunk[0x14] = 0;
            curChunk[0x15] = 0;
            curChunk[0x16] = 0;
            curChunk[0x17] = 1;
          }
        }
      }
      else if (chunkKind == 3) {
        nextIndex = *(int *)(this + 0x24);
        *(short *)(curChunk + 0x12) = (short)nextIndex;
        *(int *)(this + 0x24) = nextIndex + 1;
        if (*(int *)(this + 0x50) != 0) {
          curChunk[0x14] = 0;
          curChunk[0x15] = 0;
          curChunk[0x16] = 0;
          curChunk[0x17] = 1;
        }
        registerClassBits = *(uint *)(curChunk + 0xc) & 0x1f0000;
        if (registerClassBits == 0x20000) {
          nextIndex = *(int *)(this + 0x2c);
          *(short *)(curChunk + 0xe) = (short)nextIndex;
          *(int *)(this + 0x2c) = nextIndex + 1;
        }
        else if (registerClassBits == 0x10000) {
          nextIndex = *(int *)(this + 0x28);
          *(short *)(curChunk + 0xe) = (short)nextIndex;
          *(int *)(this + 0x28) = nextIndex + 1;
        }
        else if (registerClassBits == 0x100000) {
          *(uint *)(curChunk + 0xc) = (vec4Index & 3) << 0xc | *(uint *)(curChunk + 0xc) & 0xffffcfff;
        }
      }
      else if (chunkKind == 4) {
        nextIndex = *(int *)(this + 0x30);
        *(short *)(curChunk + 0x12) = (short)nextIndex;
        *(int *)(this + 0x30) = nextIndex + 1;
      }
      _PPStreamChunkListAddChunk(chunkList,curChunk);
      arrayTrackingMode = *(int *)(this + 0x50);
      if (arrayTrackingMode == 0) {
LAB_97bbc990:
        if (1 < vec4Count) {
          if (((isExtraVec4) || (arrayTrackingMode == 0)) || (*(int *)(this + 0x40) != 0)) {
            if (((vec4Index == vec4Count - 1) && (arrayTrackingMode != 0)) && (*(int *)(this + 0x40) == 0)) {
              chunkKind = **(byte **)(this + 0x48);
              if (chunkKind != 2) {
                if (chunkKind < 3) {
                  if ((chunkKind == 0) &&
                     (firstChunk = *(int *)(*(int *)(*(int *)(this + 0xc) + 8) + 4),
                     *(short *)(firstChunk + 0x12) == 0)) {
                    counterLow = *(short *)(this + 0x3a);
LAB_97bbcab0:
                    *(short *)(firstChunk + 0x12) = counterLow + -1;
                  }
                }
                else if ((chunkKind == 3) &&
                        (firstChunk = *(int *)(*(int *)(*(int *)(this + 0xc) + 0x14) + 4),
                        *(short *)(firstChunk + 0x12) == 0)) {
                  counterLow = *(short *)(this + 0x26);
                  goto LAB_97bbcab0;
                }
              }
            }
          }
          else {
            chunkKind = *curChunk;
            if (chunkKind != 2) {
              if (chunkKind < 3) {
                if (chunkKind == 0) {
                  usageEntry[1] = 0;
                  usageEntry[0] = (uint)(ushort)(*(short *)(this + 0x3a) - 1);
                  _PPStreamAddTempUsageArray(*(undefined4 *)(this + 0xc),usageEntry);
                }
              }
              else if (chunkKind == 3) {
                usageEntry[1] = 0;
                usageEntry[0] = (uint)(ushort)(*(short *)(this + 0x26) - 1);
                _PPStreamAddParamBindingArray(*(undefined4 *)(this + 0xc),usageEntry);
              }
            }
          }
        }
      }
      else {
        arraySizeLimit = *(uint *)(this + 0x40);
        if (((arraySizeLimit <= *(uint *)(this + 0x44)) || (*(uint *)(this + 0x44) != 0)) || (isExtraVec4))
        goto LAB_97bbc990;
        chunkKind = *curChunk;
        if (chunkKind != 2) {
          if (chunkKind < 3) {
            if (chunkKind == 0) {
              usageEntry[1] = 0;
              usageEntry[0] = (uint)(ushort)(*(short *)(this + 0x3a) - 1);
              _PPStreamAddTempUsageArray(*(undefined4 *)(this + 0xc),usageEntry);
LAB_97bbc984:
              arraySizeLimit = *(uint *)(this + 0x40);
            }
          }
          else if (chunkKind == 3) {
            usageEntry[1] = 0;
            usageEntry[0] = (uint)(ushort)(*(short *)(this + 0x26) - 1);
            _PPStreamAddParamBindingArray(*(undefined4 *)(this + 0xc),usageEntry);
            goto LAB_97bbc984;
          }
        }
        *(uint *)(this + 0x44) = arraySizeLimit;
      }
      vec4Index = vec4Index + 1;
      *(byte **)(this + 0x48) = curChunk;
    } while (vec4Index < vec4Count);
  }
  return parseSymbol;
}

/* ParseSymbolTable__FinishArrayAddition @ 0x97bbcaec (216 bytes) */
int ParseSymbolTable__FinishArrayAddition(this)
  unsigned char * this;
{
  byte bVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(this + 0x50);
  if (((iVar3 == 0) || (*(int *)(this + 0x40) != 0)) || (*(int *)(this + 0x44) == 0)) {
    if (iVar3 != 0) {
      return;
    }
    if (*(int *)(this + 0x44) == 0) {
      return;
    }
  }
  bVar1 = **(byte **)(this + 0x48);
  if (bVar1 != 2) {
    if (bVar1 < 3) {
      if ((bVar1 != 0) ||
         (iVar4 = *(int *)(*(int *)(*(int *)(this + 0xc) + 8) + 4), *(short *)(iVar4 + 0x12) != 0))
      goto LAB_97bbcba4;
      sVar2 = *(short *)(this + 0x3a);
    }
    else {
      if ((bVar1 != 3) ||
         (iVar4 = *(int *)(*(int *)(*(int *)(this + 0xc) + 0x14) + 4), *(short *)(iVar4 + 0x12) != 0
         )) goto LAB_97bbcba4;
      sVar2 = *(short *)(this + 0x26);
    }
    *(short *)(iVar4 + 0x12) = sVar2 + -1;
    iVar3 = *(int *)(this + 0x50);
  }
LAB_97bbcba4:
  if (iVar3 == 0) {
    *(undefined4 *)(this + 0x44) = 0;
    *(undefined4 *)(this + 0x40) = 0;
    return;
  }
  *(undefined4 *)(this + 0x44) = *(undefined4 *)(this + 0x40);
  return;
}

/* ParseSymbolTable__AddTempFromOutput @ 0x97bbcbc4 (324 bytes) */
int ParseSymbolTable__AddTempFromOutput(this, parseSymbol)
  unsigned char * this;
  unsigned char * parseSymbol;
{
  ushort uVar1;
  int iVar2;
  unsigned char * this_00;
  unsigned char * p_Var3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  this_00 = operator_new(100);
  __ZN11ParseSymbolC1Ev(this_00);
  p_Var3 = (unsigned char *)_PPStreamChunkCreateWithType(0,0);
  ParseSymbol__operator_(this_00,parseSymbol);
  *(undefined4 *)(this_00 + 8) = 0;
  *(undefined4 *)(this_00 + 4) = 0;
  ((int (*)())ParseSymbolTable__AddSymbol)(this,this_00);
  uVar1 = *(ushort *)(this_00 + 0x2c);
  *(undefined4 *)(this_00 + 0x50) = 1;
  uVar4 = GetVec4sForType((uint)uVar1);
  *(undefined4 *)(this_00 + 0x28) = 0xffffffff;
  *(undefined4 *)(this_00 + 0x38) = 1;
  uVar5 = GetPPStreamTypeForGLType((uint)uVar1);
  uVar9 = *(uint *)(p_Var3 + 0xc);
  uVar5 = (uVar5 & 7) << 0x1a;
  uVar8 = 0;
  *(uint *)(p_Var3 + 0xc) = uVar5 | uVar9 & 0xe3ffffff;
  iVar6 = GetScalerWidthForType((uint)*(ushort *)(this_00 + 0x2c));
  *(uint *)(p_Var3 + 0xc) = (iVar6 + -1) * 0x1000000 & 0x3000000U | uVar5 | uVar9 & 0xffffff;
  ParseSymbol__SetChunk(this_00,p_Var3);
  *(undefined4 *)(this_00 + 0x44) = 0;
  iVar6 = *(int *)this_00;
  iVar7 = *(int *)(*(int *)(this + 0xc) + 4);
  if ((uVar4 != 0) && (iVar7 != 0)) {
    do {
      if (uVar8 != 0) {
        iVar6 = _PPStreamChunkCreateFromChunk(iVar6);
      }
      iVar2 = *(int *)(this + 0x38);
      uVar8 = uVar8 + 1;
      *(short *)(iVar6 + 0x12) = (short)iVar2;
      *(int *)(this + 0x38) = iVar2 + 1;
      _PPStreamChunkListAddChunk(iVar7,iVar6);
    } while (uVar8 < uVar4);
  }
  return this_00;
}

/* ParseSymbolTable__AddFromExternalSymbol @ 0x97bbcd08 (1028 bytes) */
int ParseSymbolTable__AddFromExternalSymbol(this, parseSymbol, addFirstUsage, patchPrevIndex)
  unsigned char * this;
  unsigned char * parseSymbol;
  int addFirstUsage;
  int patchPrevIndex;
{
  uint registerClassBits;
  int firstChunk;
  int scalerWidth;
  int nextIndex;
  byte chunkKind;
  int nextSrcChunk;
  uint registerSlot;
  short counterLow;
  unsigned char * newSymbol;
  unsigned char * symbolChunk;
  uint vec4Count;
  int srcChunk;
  int chunkList;
  uint vec4Index;
  byte *curChunk;
  uint usageEntry [7];
  
  newSymbol = operator_new(100);
  __ZN11ParseSymbolC1Ev(newSymbol);
  srcChunk = *(int *)parseSymbol;
  chunkList = 0;
  symbolChunk = (unsigned char *)_PPStreamChunkCreateFromChunk(srcChunk);
  ParseSymbol__operator_(newSymbol,parseSymbol);
  *(undefined4 *)(newSymbol + 8) = 0;
  *(undefined4 *)(newSymbol + 4) = 0;
  ((int (*)())ParseSymbolTable__AddSymbol)(this,newSymbol);
  *(undefined4 *)(newSymbol + 0x50) = 1;
  vec4Count = GetVec4sForType((uint)*(ushort *)(newSymbol + 0x2c));
  ParseSymbol__SetChunk(newSymbol,symbolChunk);
  curChunk = *(byte **)newSymbol;
  *(undefined4 *)(newSymbol + 0x44) = 0;
  if (curChunk != (byte *)0x0) {
    chunkKind = *curChunk;
    if (chunkKind == 2) {
      chunkList = *(int *)(*(int *)(this + 0xc) + 0x18);
    }
    else if (chunkKind < 3) {
      if (chunkKind == 0) {
        chunkList = *(int *)(*(int *)(this + 0xc) + 4);
      }
    }
    else if (chunkKind == 3) {
      chunkList = *(int *)(*(int *)(this + 0xc) + 0x10);
    }
    else if (chunkKind == 4) {
      chunkList = *(int *)(*(int *)(this + 0xc) + 0x1c);
    }
    vec4Index = 0;
    if ((vec4Count != 0) && (chunkList != 0)) {
      do {
        if ((vec4Index != 0) && (nextSrcChunk = *(int *)(srcChunk + 8), nextSrcChunk != 0)) {
          curChunk = (byte *)_PPStreamChunkCreateFromChunk(nextSrcChunk);
          srcChunk = nextSrcChunk;
        }
        chunkKind = *curChunk;
        if (chunkKind == 2) {
          nextIndex = *(int *)(this + 0x18);
          *(short *)(curChunk + 0x12) = (short)nextIndex;
          *(int *)(this + 0x18) = nextIndex + 1;
          if ((*(uint *)(curChunk + 0xc) & 0xf0000) == 0x90000) {
            registerSlot = *(uint *)(this + 0x1c);
            *(uint *)(curChunk + 0xc) = registerSlot & 0x1f | *(uint *)(curChunk + 0xc) & 0xffffffe0;
            *(uint *)(this + 0x1c) = registerSlot + 1;
            scalerWidth = GetScalerWidthForType((uint)*(ushort *)(newSymbol + 0x2c));
            *(int *)(this + 0x20) = *(int *)(this + 0x20) + scalerWidth;
          }
        }
        else if (chunkKind < 3) {
          if (chunkKind == 0) {
            nextIndex = *(int *)(this + 0x38);
            *(short *)(curChunk + 0x12) = (short)nextIndex;
            *(int *)(this + 0x38) = nextIndex + 1;
            if (*(int *)(newSymbol + 0x60) == 0) {
              if (*(int *)(newSymbol + 0x5c) != 0) {
                registerSlot = *(uint *)(this + 0x34);
                *(uint *)(curChunk + 0xc) = registerSlot & 0x1f | *(uint *)(curChunk + 0xc) & 0xffffffe0;
                *(uint *)(this + 0x34) = registerSlot + 1;
              }
            }
            else {
              registerSlot = *(uint *)(this + 0x1c);
              *(uint *)(curChunk + 0xc) = registerSlot & 0x1f | *(uint *)(curChunk + 0xc) & 0xffffffe0;
              *(uint *)(this + 0x1c) = registerSlot + 1;
              scalerWidth = GetScalerWidthForType((uint)*(ushort *)(newSymbol + 0x2c));
              *(int *)(this + 0x20) = *(int *)(this + 0x20) + scalerWidth;
            }
            if (*(int *)(this + 0x50) != 0) {
              curChunk[0x14] = 0;
              curChunk[0x15] = 0;
              curChunk[0x16] = 0;
              curChunk[0x17] = 1;
            }
          }
        }
        else if (chunkKind == 3) {
          nextIndex = *(int *)(this + 0x24);
          *(short *)(curChunk + 0x12) = (short)nextIndex;
          *(int *)(this + 0x24) = nextIndex + 1;
          registerClassBits = *(uint *)(curChunk + 0xc) & 0x1f0000;
          if (registerClassBits == 0x20000) {
            nextIndex = *(int *)(this + 0x2c);
            *(short *)(curChunk + 0xe) = (short)nextIndex;
            *(int *)(this + 0x2c) = nextIndex + 1;
          }
          else if (registerClassBits == 0x10000) {
            nextIndex = *(int *)(this + 0x28);
            *(short *)(curChunk + 0xe) = (short)nextIndex;
            *(int *)(this + 0x28) = nextIndex + 1;
          }
          else if (registerClassBits == 0x100000) {
            *(uint *)(curChunk + 0xc) = (vec4Index & 3) << 0xc | *(uint *)(curChunk + 0xc) & 0xffffcfff;
          }
        }
        else if (chunkKind == 4) {
          nextIndex = *(int *)(this + 0x30);
          *(short *)(curChunk + 0x12) = (short)nextIndex;
          *(int *)(this + 0x30) = nextIndex + 1;
        }
        _PPStreamChunkListAddChunk(chunkList,curChunk);
        if ((vec4Index == 0) && (addFirstUsage != 0)) {
          chunkKind = *curChunk;
          if (chunkKind != 2) {
            if (chunkKind < 3) {
              if (chunkKind == 0) {
                usageEntry[1] = 0;
                usageEntry[0] = (uint)(ushort)(*(short *)(this + 0x3a) - 1);
                _PPStreamAddTempUsageArray(*(undefined4 *)(this + 0xc),usageEntry);
              }
            }
            else if (chunkKind == 3) {
              usageEntry[1] = 0;
              usageEntry[0] = (uint)(ushort)(*(short *)(this + 0x26) - 1);
              _PPStreamAddParamBindingArray(*(undefined4 *)(this + 0xc),usageEntry);
            }
          }
        }
        if ((vec4Index == vec4Count - 1) && (patchPrevIndex != 0)) {
          chunkKind = *curChunk;
          if (chunkKind != 2) {
            if (chunkKind < 3) {
              if ((chunkKind == 0) &&
                 (firstChunk = *(int *)(*(int *)(*(int *)(this + 0xc) + 8) + 4),
                 *(short *)(firstChunk + 0x12) == 0)) {
                counterLow = *(short *)(this + 0x3a);
LAB_97bbd0d4:
                *(short *)(firstChunk + 0x12) = counterLow + -1;
              }
            }
            else if ((chunkKind == 3) &&
                    (firstChunk = *(int *)(*(int *)(*(int *)(this + 0xc) + 0x14) + 4),
                    *(short *)(firstChunk + 0x12) == 0)) {
              counterLow = *(short *)(this + 0x26);
              goto LAB_97bbd0d4;
            }
          }
        }
        vec4Index = vec4Index + 1;
      } while (vec4Index < vec4Count);
    }
  }
  return newSymbol;
}

/* ParseSymbolTable__InsertSymbol @ 0x97bbd10c (952 bytes) */
int ParseSymbolTable__InsertSymbol(this, parseSymbol)
  unsigned char * this;
  unsigned char * parseSymbol;
{
  bool bVar1;
  undefined1 *puVar2;
  int iVar3;
  short sVar5;
  undefined4 uVar4;
  unsigned char * pPVar6;
  unsigned char * pPVar7;
  int *r3In0;
  int iVar8;
  undefined4 uVar9;
  uint uVar10;
  uint uVar11;
  char acStack_40 [20];
  
  puVar2 = DAT_a7b7bcfc;
  uVar9 = 0;
  if (parseSymbol == (unsigned char *)0x0) {
    return 0;
  }
  if ((*(int *)(this + 0x4c) != 0) || (*(int *)(parseSymbol + 0x24) == 0)) {
    sVar5 = *(short *)(parseSymbol + 0x2c);
LAB_97bbd254:
    if (sVar5 == 0x7ffe) {
      iVar3 = *(int *)(*(int *)(parseSymbol + 0xc) + 8);
      if (iVar3 != 0) {
        uVar11 = 0;
        uVar10 = *(int *)(iVar3 + 8) - *(int *)(iVar3 + 4) >> 3;
        if (uVar10 != 0) {
          do {
            pPVar6 = operator_new(100);
            __ZN11ParseSymbolC1ERKS_(pPVar6,parseSymbol);
            ParseSymbol__CatName(pPVar6,".");
            r3In0 = *(int **)(*(int *)(iVar3 + 4) + uVar11 * 8);
            iVar8 = (**(code **)(*r3In0 + 0x1c))(r3In0);
            *(undefined1 *)(*(int *)(iVar8 + 4) + *(int *)(*(int *)(iVar8 + 4) + -0xc)) = *puVar2;
            ParseSymbol__CatName(pPVar6,*(char **)(iVar8 + 4));
            ParseSymbol__SetParseTreeType(pPVar6,*(unsigned char **)(*(int *)(iVar3 + 4) + uVar11 * 8));
            *(undefined4 *)(pPVar6 + 0x48) = 0;
            ParseSymbol__ResolveOpenGLType(pPVar6);
            uVar4 = 0;
            if ((*(int *)(parseSymbol + 0x3c) != 0) || (*(int *)(parseSymbol + 0x40) != 0)) {
              uVar4 = 1;
            }
            *(undefined4 *)(pPVar6 + 0x40) = uVar4;
            *(undefined4 *)(pPVar6 + 0x3c) = 0;
            uVar11 = uVar11 + 1;
            pPVar7 = operator_new(0x38);
            __ZN12ParseOperandC1Ev(pPVar7);
            *(unsigned char **)pPVar7 = pPVar6;
            ((int (*)())ParseSymbolTable__processOperand)(this,pPVar7);
            __ZN12ParseOperandD1Ev(pPVar7);
            __ZdlPv(pPVar7);
          } while (uVar11 < uVar10);
        }
      }
    }
    else if (sVar5 == 0x7fff) {
      uVar10 = 0;
      if (0 < *(int *)(*(int *)(parseSymbol + 0xc) + 4)) {
        do {
          pPVar6 = operator_new(100);
          __ZN11ParseSymbolC1ERKS_(pPVar6,parseSymbol);
          ParseSymbol__AddDirectIndex(pPVar6,uVar10);
          _sprintf(acStack_40,"[%d]",uVar10);
          ParseSymbol__CatName(pPVar6,acStack_40);
          *(undefined4 *)(pPVar6 + 0x48) = 1;
          ParseSymbol__ResolveOpenGLType(pPVar6);
          uVar4 = 0;
          if ((*(int *)(parseSymbol + 0x3c) != 0) || (*(int *)(parseSymbol + 0x40) != 0)) {
            uVar4 = 1;
          }
          *(undefined4 *)(pPVar6 + 0x40) = uVar4;
          *(undefined4 *)(pPVar6 + 0x3c) = 0;
          pPVar7 = operator_new(0x38);
          __ZN12ParseOperandC1Ev(pPVar7);
          *(unsigned char **)pPVar7 = pPVar6;
          if (uVar10 == 0) {
            *(int *)(this + 0x40) = *(int *)(this + 0x40) + 1;
          }
          ((int (*)())ParseSymbolTable__processOperand)(this,pPVar7);
          if (uVar10 == *(int *)(*(int *)(parseSymbol + 0xc) + 4) - 1U) {
            *(int *)(this + 0x40) = *(int *)(this + 0x40) + -1;
            ((int (*)())ParseSymbolTable__FinishArrayAddition)(this);
          }
          if (pPVar7 != (unsigned char *)0x0) {
            __ZN12ParseOperandD1Ev(pPVar7);
            __ZdlPv(pPVar7);
          }
          uVar10 = uVar10 + 1;
        } while ((int)uVar10 < *(int *)(*(int *)(parseSymbol + 0xc) + 4));
      }
    }
    else {
      uVar9 = ((int (*)())ParseSymbolTable__InsertSingleSymbol)(this,parseSymbol);
    }
    return uVar9;
  }
  sVar5 = *(short *)(parseSymbol + 0x2c);
  if (((sVar5 != 0x7fff) || (*(int *)(parseSymbol + 0x3c) != 0)) || (*(int *)(parseSymbol + 0x40) != 0))
  goto LAB_97bbd254;
  bVar1 = false;
  if (-1 < *(int *)(parseSymbol + 0x28)) {
    for (iVar3 = *(int *)this; iVar3 != 0; iVar3 = *(int *)(iVar3 + 8)) {
      if (*(int *)(parseSymbol + 0x28) == *(int *)(iVar3 + 0x28)) {
        bVar1 = true;
        break;
      }
    }
    if (bVar1) goto LAB_97bbd244;
  }
  *(undefined4 *)(this + 0x4c) = 1;
  pPVar6 = operator_new(100);
  __ZN11ParseSymbolC1ERKS_(pPVar6,parseSymbol);
  ParseSymbol__TrimNameToBase(pPVar6);
  ParseSymbol__SetParseTreeType(pPVar6,*(unsigned char **)(parseSymbol + 0x10));
  uVar9 = 0;
  if ((*(int *)(parseSymbol + 0x3c) != 0) || (*(int *)(parseSymbol + 0x40) != 0)) {
    uVar9 = 1;
  }
  *(undefined4 *)(pPVar6 + 0x40) = uVar9;
  *(undefined4 *)(pPVar6 + 0x3c) = 0;
  pPVar7 = operator_new(0x38);
  __ZN12ParseOperandC1Ev(pPVar7);
  *(unsigned char **)pPVar7 = pPVar6;
  ((int (*)())ParseSymbolTable__processOperand)(this,pPVar7);
  __ZN12ParseOperandD1Ev(pPVar7);
  __ZdlPv(pPVar7);
LAB_97bbd244:
  *(undefined4 *)(this + 0x4c) = 0;
  return 0;
}

/* ParseSymbolTable__FindFirstElement @ 0x97bbd4c4 (624 bytes) */
int ParseSymbolTable__FindFirstElement(this, parseSymbol)
  unsigned char * this;
  unsigned char * parseSymbol;
{
  unsigned char * pPVar1;
  int iVar2;
  char *pcVar3;
  undefined4 r4In0;
  unsigned char * pTVar4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  uint uVar11;
  char acStack_30 [16];
  
  uVar10 = 0;
  if (parseSymbol != (unsigned char *)0x0) {
    if (*(short *)(parseSymbol + 0x2c) == 0x7ffe) {
      iVar9 = *(int *)(*(int *)(parseSymbol + 0xc) + 8);
      if (iVar9 != 0) {
        pPVar1 = operator_new(100);
        __ZN11ParseSymbolC1Ev(pPVar1);
        iVar5 = *(int *)**(undefined4 **)(iVar9 + 4);
        iVar5 = (**(code **)(iVar5 + 0x1c))
                          ((int *)**(undefined4 **)(iVar9 + 4),r4In0,in_r5,in_r6,in_r7,in_r8,iVar5);
        *(undefined1 *)(*(int *)(iVar5 + 4) + *(int *)(*(int *)(iVar5 + 4) + -0xc)) = *DAT_a7b7bcfc;
        uVar10 = *(undefined4 *)(iVar5 + 4);
        iVar5 = _strlen(uVar10);
        iVar5 = iVar5 + 1;
        if (*(int *)(parseSymbol + 0x14) != 0) {
          iVar2 = _strlen(*(int *)(parseSymbol + 0x14));
          iVar5 = iVar5 + iVar2 + 1;
        }
        pcVar3 = (char *)_malloc(iVar5);
        if (*(int *)(parseSymbol + 0x14) == 0) {
          _strcpy(pcVar3,uVar10);
        }
        else {
          _sprintf(pcVar3,DAT_a7b7bbf4,*(int *)(parseSymbol + 0x14),uVar10);
        }
        ParseSymbol__SetName(pPVar1,pcVar3);
        iVar5 = *(int *)(parseSymbol + 0x3c);
        *(undefined4 *)(pPVar1 + 0x28) = *(undefined4 *)(parseSymbol + 0x28);
        uVar10 = 0;
        if ((iVar5 != 0) || (*(int *)(parseSymbol + 0x40) != 0)) {
          uVar10 = 1;
        }
        *(undefined4 *)(pPVar1 + 0x40) = uVar10;
        ParseSymbol__SetParseTreeType(pPVar1,(unsigned char *)**(undefined4 **)(iVar9 + 4));
        uVar10 = ((int (*)())ParseSymbolTable__FindFirstElement)(this,pPVar1);
        if (pPVar1 != (unsigned char *)0x0) {
          __ZN11ParseSymbolD1Ev(pPVar1);
          __ZdlPv(pPVar1);
        }
        _free(pcVar3);
      }
    }
    else if (*(short *)(parseSymbol + 0x2c) == 0x7fff) {
      uVar11 = 0;
      if (0 < *(int *)(*(int *)(parseSymbol + 0xc) + 4)) {
        do {
          pPVar1 = operator_new(100);
          __ZN11ParseSymbolC1Ev(pPVar1);
          ParseSymbol__SetName(pPVar1,*(char **)(parseSymbol + 0x14));
          ParseSymbol__AddDirectIndex(pPVar1,uVar11);
          _sprintf(acStack_30,DAT_a7b7bbf8,uVar11);
          ParseSymbol__CatName(pPVar1,acStack_30);
          uVar10 = *(undefined4 *)(parseSymbol + 0x40);
          uVar6 = *(undefined4 *)(parseSymbol + 0x3c);
          uVar8 = *(undefined4 *)(parseSymbol + 0x60);
          uVar7 = *(undefined4 *)(parseSymbol + 0x5c);
          pTVar4 = *(unsigned char **)(parseSymbol + 0xc);
          *(undefined4 *)(pPVar1 + 0x28) = *(undefined4 *)(parseSymbol + 0x28);
          *(undefined4 *)(pPVar1 + 0x40) = uVar10;
          *(undefined4 *)(pPVar1 + 0x3c) = uVar6;
          *(undefined4 *)(pPVar1 + 0x60) = uVar8;
          *(undefined4 *)(pPVar1 + 0x5c) = uVar7;
          ParseSymbol__SetParseTreeType(pPVar1,pTVar4);
          *(undefined4 *)(pPVar1 + 0x48) = 1;
          ParseSymbol__ResolveOpenGLType(pPVar1);
          uVar10 = ((int (*)())ParseSymbolTable__FindFirstElement)(this,pPVar1);
          if (pPVar1 != (unsigned char *)0x0) {
            __ZN11ParseSymbolD1Ev(pPVar1);
            __ZdlPv(pPVar1);
          }
          uVar11 = uVar11 + 1;
        } while ((int)uVar11 < *(int *)(*(int *)(parseSymbol + 0xc) + 4));
      }
    }
    else {
      uVar10 = ((int (*)())ParseSymbolTable__FindSymbol)(this,parseSymbol);
    }
  }
  return uVar10;
}

/* ParseSymbolTable__FindSymbol @ 0x97bbd734 (120 bytes) */
int ParseSymbolTable__FindSymbol(this, parseSymbol)
  unsigned char * this;
  unsigned char * parseSymbol;
{
  int iVar1;
  unsigned char * pPVar2;
  
  pPVar2 = *(unsigned char **)
            ((*(uint *)(parseSymbol + 0x1c) -
             (*(uint *)(parseSymbol + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4 +
            *(int *)(this + 8));
  while( true ) {
    if (pPVar2 == (unsigned char *)0x0) {
      return (unsigned char *)0x0;
    }
    iVar1 = __ZeqRK11ParseSymbolS1_(pPVar2,parseSymbol);
    if (iVar1 != 0) break;
    pPVar2 = *(unsigned char **)(pPVar2 + 4);
  }
  return pPVar2;
}

/* ParseSymbolTable__NextSymbol @ 0x97bbd7ac (24 bytes) */
int ParseSymbolTable__NextSymbol(this, parseSymbol)
  unsigned char * this;
  unsigned char * parseSymbol;
{
  if (parseSymbol != (unsigned char *)0x0) {
    return *(undefined4 *)(parseSymbol + 8);
  }
  return *(undefined4 *)this;
}

/* ParseSymbolTable__NextSymbolInHash @ 0x97bbd7c4 (20 bytes) */
int ParseSymbolTable__NextSymbolInHash(this, parseSymbol)
  unsigned char * this;
  unsigned char * parseSymbol;
{
  if (parseSymbol == (unsigned char *)0x0) {
    return 0;
  }
  return *(undefined4 *)(parseSymbol + 4);
}

/* ParseSymbolTable__FirstSymbolInHash @ 0x97bbd7d8 (32 bytes) */
int ParseSymbolTable__FirstSymbolInHash(this, param_2)
  unsigned char * this;
  uint param_2;
{
  return *(undefined4 *)
          ((param_2 - (param_2 / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4 +
          *(int *)(this + 8));
}

/* ParseSymbolTable__FindGlobalSymbolByName @ 0x97bbd7f8 (244 bytes) */
int ParseSymbolTable__FindGlobalSymbolByName(this, str)
  unsigned char * this;
  char *str;
{
  unsigned char * this_00;
  int iVar1;
  unsigned char * pPVar2;
  
  if (str != (char *)0x0) {
    this_00 = operator_new(100);
    __ZN11ParseSymbolC1Ev(this_00);
    if (this_00 != (unsigned char *)0x0) {
      ParseSymbol__SetName(this_00,str);
      for (pPVar2 = *(unsigned char **)
                     ((*(uint *)(this_00 + 0x1c) -
                      (*(uint *)(this_00 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10))
                      * 4 + *(int *)(this + 8)); pPVar2 != (unsigned char *)0x0;
          pPVar2 = *(unsigned char **)(pPVar2 + 4)) {
        if ((*(int *)(pPVar2 + 0x38) != 0) &&
           (iVar1 = __ZeqRK11ParseSymbolS1_(pPVar2,this_00), iVar1 != 0)) {
          __ZN11ParseSymbolD1Ev(this_00);
          __ZdlPv(this_00);
          return pPVar2;
        }
      }
      __ZN11ParseSymbolD1Ev(this_00);
      __ZdlPv(this_00);
    }
  }
  return (unsigned char *)0x0;
}

/* ParseSymbolTable__FindSymbolByName @ 0x97bbd8ec (232 bytes) */
int ParseSymbolTable__FindSymbolByName(this, str)
  unsigned char * this;
  char *str;
{
  unsigned char * this_00;
  int iVar1;
  unsigned char * pPVar2;
  
  if (str != (char *)0x0) {
    this_00 = operator_new(100);
    __ZN11ParseSymbolC1Ev(this_00);
    if (this_00 != (unsigned char *)0x0) {
      ParseSymbol__SetName(this_00,str);
      for (pPVar2 = *(unsigned char **)
                     ((*(uint *)(this_00 + 0x1c) -
                      (*(uint *)(this_00 + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10))
                      * 4 + *(int *)(this + 8)); pPVar2 != (unsigned char *)0x0;
          pPVar2 = *(unsigned char **)(pPVar2 + 4)) {
        iVar1 = __ZeqRK11ParseSymbolS1_(pPVar2,this_00);
        if (iVar1 != 0) {
          __ZN11ParseSymbolD1Ev(this_00);
          __ZdlPv(this_00);
          return pPVar2;
        }
      }
      __ZN11ParseSymbolD1Ev(this_00);
      __ZdlPv(this_00);
    }
  }
  return (unsigned char *)0x0;
}

/* ParseSymbolTable__FindNextParamSymbolByName @ 0x97bbd9d4 (192 bytes) */
int ParseSymbolTable__FindNextParamSymbolByName(this, parseSymbol, str)
  unsigned char * this;
  unsigned char * parseSymbol;
  char *str;
{
  int length;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = 0;
  if (str != (char *)0x0) {
    length = _strlen(str);
    if (parseSymbol == (unsigned char *)0x0) {
      iVar4 = *(int *)this;
    }
    else {
      iVar4 = *(int *)(parseSymbol + 8);
    }
    while ((iVar2 = 0, iVar4 != 0 &&
           (((iVar3 = *(int *)(iVar4 + 0x14), iVar3 == 0 ||
             (iVar2 = _strncmp(str,iVar3,length), iVar2 != 0)) ||
            ((iVar2 = iVar4, *(int *)(iVar4 + 0x20) != length &&
             ((*(char *)(iVar3 + length) != '.' && (*(char *)(iVar3 + length) != '['))))))))) {
      iVar4 = *(int *)(iVar4 + 8);
    }
  }
  return iVar2;
}

/* ParseSymbolTable__RemoveSymbol @ 0x97bbda94 (600 bytes) */
int ParseSymbolTable__RemoveSymbol(this, parseSymbol)
  unsigned char * this;
  unsigned char * parseSymbol;
{
  byte bVar1;
  unsigned char * pPVar2;
  unsigned char * pPVar3;
  unsigned char * pPVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  
  uVar7 = 0;
  uVar5 = GetVec4sForType((uint)*(ushort *)(parseSymbol + 0x2c));
  pbVar8 = *(byte **)parseSymbol;
  if (uVar5 != 0) {
    do {
      bVar1 = *pbVar8;
      if (bVar1 == 2) {
LAB_97bbdb58:
        *(int *)(this + 0x18) = *(int *)(this + 0x18) + -1;
        if ((*(uint *)(pbVar8 + 0xc) & 0xf0000) == 0x90000) {
          *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
          iVar6 = GetScalerWidthForType((uint)*(ushort *)(parseSymbol + 0x2c));
          *(int *)(this + 0x20) = *(int *)(this + 0x20) - iVar6;
        }
      }
      else if (bVar1 < 3) {
        if (bVar1 == 0) {
          if (*(int *)(parseSymbol + 0x60) == 0) {
            if (*(int *)(parseSymbol + 0x5c) != 0) {
              *(int *)(this + 0x34) = *(int *)(this + 0x34) + -1;
            }
          }
          else {
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
            iVar6 = GetScalerWidthForType((uint)*(ushort *)(parseSymbol + 0x2c));
            *(int *)(this + 0x20) = *(int *)(this + 0x20) - iVar6;
          }
          *(int *)(this + 0x38) = *(int *)(this + 0x38) + -1;
          goto LAB_97bbdb58;
        }
      }
      else if (bVar1 == 3) {
        *(int *)(this + 0x24) = *(int *)(this + 0x24) + -1;
        if ((*(uint *)(pbVar8 + 0xc) & 0x1f0000) == 0x20000) {
          *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + -1;
        }
        else if ((*(uint *)(pbVar8 + 0xc) & 0x1f0000) == 0x10000) {
          *(int *)(this + 0x28) = *(int *)(this + 0x28) + -1;
        }
      }
      else if (bVar1 == 4) {
        *(int *)(this + 0x30) = *(int *)(this + 0x30) + -1;
      }
      uVar7 = uVar7 + 1;
    } while (uVar7 < uVar5);
  }
  *(int *)(this + 0x14) = *(int *)(this + 0x14) + -1;
  pPVar2 = (unsigned char *)0x0;
  for (pPVar3 = *(unsigned char **)
                 ((*(uint *)(parseSymbol + 0x1c) -
                  (*(uint *)(parseSymbol + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4
                 + *(int *)(this + 8)); pPVar3 != (unsigned char *)0x0;
      pPVar3 = *(unsigned char **)(pPVar3 + 4)) {
    if (pPVar3 == parseSymbol) {
      if (pPVar2 == (unsigned char *)0x0) {
        *(undefined4 *)
         ((*(uint *)(parseSymbol + 0x1c) -
          (*(uint *)(parseSymbol + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4 +
         *(int *)(this + 8)) = *(undefined4 *)(parseSymbol + 4);
      }
      else {
        *(undefined4 *)(pPVar2 + 4) = *(undefined4 *)(parseSymbol + 4);
      }
    }
    pPVar2 = pPVar3;
  }
  pPVar3 = *(unsigned char **)this;
  pPVar2 = (unsigned char *)0x0;
  do {
    pPVar4 = pPVar3;
    if (pPVar4 == (unsigned char *)0x0) {
LAB_97bbdcd0:
      *(undefined4 *)(parseSymbol + 0x50) = 0;
      return;
    }
    if (pPVar4 == parseSymbol) {
      if (pPVar2 == (unsigned char *)0x0) {
        *(undefined4 *)this = *(undefined4 *)(parseSymbol + 8);
      }
      else {
        *(undefined4 *)(pPVar2 + 8) = *(undefined4 *)(parseSymbol + 8);
      }
      if (*(unsigned char **)(this + 4) == pPVar4) {
        *(unsigned char **)(this + 4) = pPVar2;
      }
      goto LAB_97bbdcd0;
    }
    pPVar3 = *(unsigned char **)(pPVar4 + 8);
    pPVar2 = pPVar4;
  } while( true );
}

/* ParseSymbolTable__RemoveEndSymbol @ 0x97bbdcec (704 bytes) */
int ParseSymbolTable__RemoveEndSymbol(this, parseSymbol)
  unsigned char * this;
  unsigned char * parseSymbol;
{
  unsigned char * listNext;
  unsigned char * listPrev;
  int isMatch;
  int tempCounter;
  byte chunkKind;
  unsigned char * hashPrev;
  unsigned char * hashNode;
  unsigned char * listNode;
  uint vec4Count;
  int scalarWidth2;
  int scalarWidth;
  int removedOk;
  uint vec4Idx;
  byte *chunk;
  
  removedOk = 1;
  vec4Idx = 0;
  vec4Count = GetVec4sForType((uint)*(ushort *)(parseSymbol + 0x2c));
  chunk = *(byte **)parseSymbol;
  if (vec4Count != 0) {
    do {
      chunkKind = *chunk;
      if (chunkKind == 2) {
        if (*(int *)(this + 0x18) - 1U != (uint)*(ushort *)(chunk + 0x12)) goto LAB_97bbde78;
        *(uint *)(this + 0x18) = *(int *)(this + 0x18) - 1U;
        if ((*(uint *)(chunk + 0xc) & 0xf0000) == 0x90000) {
          *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
          scalarWidth = GetScalerWidthForType((uint)*(ushort *)(parseSymbol + 0x2c));
          *(int *)(this + 0x20) = *(int *)(this + 0x20) - scalarWidth;
        }
      }
      else if (chunkKind < 3) {
        if (chunkKind == 0) {
          tempCounter = *(int *)(this + 0x38);
          if (tempCounter - 1U != (uint)*(ushort *)(chunk + 0x12)) goto LAB_97bbde78;
          if (*(int *)(parseSymbol + 0x60) == 0) {
            if (*(int *)(parseSymbol + 0x5c) != 0) {
              *(int *)(this + 0x34) = *(int *)(this + 0x34) + -1;
            }
          }
          else {
            *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + -1;
            scalarWidth2 = GetScalerWidthForType((uint)*(ushort *)(parseSymbol + 0x2c));
            *(int *)(this + 0x20) = *(int *)(this + 0x20) - scalarWidth2;
          }
          *(int *)(this + 0x38) = tempCounter + -1;
        }
      }
      else if (chunkKind == 3) {
        if (*(int *)(this + 0x24) - 1U == (uint)*(ushort *)(chunk + 0x12)) {
          *(uint *)(this + 0x24) = *(int *)(this + 0x24) - 1U;
          if ((*(uint *)(chunk + 0xc) & 0x1f0000) == 0x20000) {
            *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + -1;
          }
          else if ((*(uint *)(chunk + 0xc) & 0x1f0000) == 0x10000) {
            *(int *)(this + 0x28) = *(int *)(this + 0x28) + -1;
          }
        }
        else {
LAB_97bbde78:
          removedOk = 0;
        }
      }
      else if (chunkKind == 4) {
        if (*(int *)(this + 0x30) - 1U != (uint)*(ushort *)(chunk + 0x12)) goto LAB_97bbde78;
        *(uint *)(this + 0x30) = *(int *)(this + 0x30) - 1U;
      }
      vec4Idx = vec4Idx + 1;
    } while (vec4Idx < vec4Count);
    if (removedOk == 0) {
      return 0;
    }
  }
  *(int *)(this + 0x14) = *(int *)(this + 0x14) + -1;
  hashPrev = (unsigned char *)0x0;
  for (hashNode = *(unsigned char **)
                 ((*(uint *)(parseSymbol + 0x1c) -
                  (*(uint *)(parseSymbol + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4
                 + *(int *)(this + 8)); hashNode != (unsigned char *)0x0;
      hashNode = *(unsigned char **)(hashNode + 4)) {
    isMatch = __ZeqRK11ParseSymbolS1_(hashNode,parseSymbol);
    if (isMatch != 0) {
      if (hashPrev == (unsigned char *)0x0) {
        *(undefined4 *)
         ((*(uint *)(parseSymbol + 0x1c) -
          (*(uint *)(parseSymbol + 0x1c) / *(uint *)(this + 0x10)) * *(uint *)(this + 0x10)) * 4 +
         *(int *)(this + 8)) = *(undefined4 *)(hashNode + 4);
      }
      else {
        *(undefined4 *)(hashPrev + 4) = *(undefined4 *)(hashNode + 4);
      }
    }
    hashPrev = hashNode;
  }
  listNext = *(unsigned char **)this;
  listPrev = (unsigned char *)0x0;
  do {
    listNode = listNext;
    if (listNode == (unsigned char *)0x0) {
LAB_97bbdf8c:
      *(undefined4 *)(parseSymbol + 0x50) = 0;
      return removedOk;
    }
    isMatch = __ZeqRK11ParseSymbolS1_(listNode,parseSymbol);
    if (isMatch != 0) {
      if (listPrev == (unsigned char *)0x0) {
        *(undefined4 *)this = *(undefined4 *)(listNode + 8);
      }
      else {
        *(undefined4 *)(listPrev + 8) = *(undefined4 *)(listNode + 8);
      }
      if (*(unsigned char **)(this + 4) == listNode) {
        *(unsigned char **)(this + 4) = listPrev;
      }
      goto LAB_97bbdf8c;
    }
    listNext = *(unsigned char **)(listNode + 8);
    listPrev = listNode;
  } while( true );
}

/* ParseSymbolTable__CopySymbolTable @ 0x97bbdfac (228 bytes) */
int ParseSymbolTable__CopySymbolTable(this)
  unsigned char * this;
{
  undefined4 uVar1;
  unsigned char * this_00;
  unsigned char * this_01;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  unsigned char * pPVar10;
  
  this_00 = operator_new(0x54);
  ((int (*)())__ZN16ParseSymbolTableC1Ej)(this_00,0x80);
  for (pPVar10 = *(unsigned char **)this; pPVar10 != (unsigned char *)0x0;
      pPVar10 = *(unsigned char **)(pPVar10 + 8)) {
    this_01 = operator_new(100);
    __ZN11ParseSymbolC1Ev(this_01);
    ParseSymbol__operator_(this_01,pPVar10);
    ParseSymbol__SetChunk(this_01,*(unsigned char **)pPVar10);
    *(undefined4 *)(this_01 + 0x44) = 0;
    ((int (*)())ParseSymbolTable__AddSymbol)(this_00,this_01);
  }
  uVar2 = *(undefined4 *)(this + 0x3c);
  uVar1 = *(undefined4 *)(this + 0x1c);
  uVar7 = *(undefined4 *)(this + 0x20);
  uVar9 = *(undefined4 *)(this + 0x24);
  uVar8 = *(undefined4 *)(this + 0x28);
  uVar6 = *(undefined4 *)(this + 0x2c);
  uVar5 = *(undefined4 *)(this + 0x30);
  uVar4 = *(undefined4 *)(this + 0x34);
  uVar3 = *(undefined4 *)(this + 0x38);
  *(undefined4 *)(this_00 + 0x18) = *(undefined4 *)(this + 0x18);
  *(undefined4 *)(this_00 + 0x1c) = uVar1;
  *(undefined4 *)(this_00 + 0x20) = uVar7;
  *(undefined4 *)(this_00 + 0x24) = uVar9;
  *(undefined4 *)(this_00 + 0x28) = uVar8;
  *(undefined4 *)(this_00 + 0x2c) = uVar6;
  *(undefined4 *)(this_00 + 0x30) = uVar5;
  *(undefined4 *)(this_00 + 0x34) = uVar4;
  *(undefined4 *)(this_00 + 0x38) = uVar3;
  *(undefined4 *)(this_00 + 0x3c) = uVar2;
  return this_00;
}

/* ParseSymbolTable__ChangeChunk @ 0x97bbe090 (128 bytes) */
int ParseSymbolTable__ChangeChunk(this, _PPStreamChunk1, _PPStreamChunk2, param_4)
  unsigned char * this;
  unsigned char * _PPStreamChunk1;
  unsigned char * _PPStreamChunk2;
  int param_4;
{
  unsigned char * this_00;
  
  this_00 = *(unsigned char **)this;
  if (this_00 != (unsigned char *)0x0) {
    do {
      if (*(unsigned char **)this_00 == _PPStreamChunk1) {
        ParseSymbol__SetChunk(this_00,_PPStreamChunk2);
        if (param_4 != 0) {
          *(undefined4 *)(this_00 + 0x44) = 0;
        }
        return 1;
      }
      this_00 = *(unsigned char **)(this_00 + 8);
    } while (this_00 != (unsigned char *)0x0);
  }
  return 0;
}

/* ParseSymbolTable__ClearCompilerTempData @ 0x97bbe110 (40 bytes) */
int ParseSymbolTable__ClearCompilerTempData(this)
  unsigned char * this;
{
  int iVar1;
  
  iVar1 = *(int *)this;
  if (iVar1 != 0) {
    do {
      *(undefined4 *)(iVar1 + 0xc) = 0;
      *(undefined4 *)(iVar1 + 0x10) = 0;
      iVar1 = *(int *)(iVar1 + 8);
    } while (iVar1 != 0);
    return;
  }
  return;
}

/* ParseSymbolTable__Dump @ 0x97bbe138 (84 bytes) */
int ParseSymbolTable__Dump(this)
  unsigned char * this;
{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = PTR_DAT_a7b7c0bc;
  for (iVar2 = *(int *)this; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
    _fflush(puVar1 + 0x58);
  }
  return;
}

/* ParseSymbolTable__GetString @ 0x97bbe18c (992 bytes) */
int ParseSymbolTable__GetString(this, mode)
  unsigned char * this;
  int mode;
{
  uint needed2;
  uint bucketIdx;
  uint needed;
  unsigned char * symbol;
  char *buffer;
  int symbolText;
  int newLen;
  char *result;
  undefined4 sectionHeader;
  uint capacity;
  char kindFilter;
  int usedLen;
  uint hashSize;
  
  symbol = (unsigned char *)((int (*)())ParseSymbolTable__NextSymbol)(this,(unsigned char *)0x0);
  buffer = (char *)_malloc(0x800);
  capacity = 0x800;
  usedLen = 0;
  kindFilter = '\x02';
  result = (char *)0x0;
  if (buffer != (char *)0x0) {
    *buffer = '\0';
    result = buffer;
    if (mode == 1) {
      hashSize = *(uint *)(this + 0x10);
      bucketIdx = 0;
      if (hashSize != 0) {
        do {
          symbol = (unsigned char *)((int (*)())ParseSymbolTable__FirstSymbolInHash)(this,bucketIdx);
          if (symbol != (unsigned char *)0x0) {
            _sprintf(result,DAT_a7b7bc08,result,bucketIdx);
            usedLen = _strlen(result);
            buffer = result;
            do {
              symbolText = ParseSymbol__GetString(symbol,1);
              result = buffer;
              if (symbolText != 0) {
                newLen = _strlen(symbolText);
                newLen = newLen + usedLen;
                needed2 = newLen + 1;
                if (capacity < needed2) {
                  capacity = 0x800;
                  if (0x800 < needed2 >> 2) {
                    capacity = needed2 >> 2;
                  }
                  capacity = needed2 + capacity;
                  result = (char *)_malloc(capacity);
                  if (result == (char *)0x0) goto LAB_97bbe3d4;
                  _memmove(result,buffer,usedLen + 1);
                  _free(buffer);
                }
                usedLen = newLen + 1;
                _strcat(result,symbolText);
                result[newLen] = '\n';
                result[usedLen] = '\0';
                _free(symbolText);
              }
              symbol = (unsigned char *)((int (*)())ParseSymbolTable__NextSymbolInHash)(this,symbol);
              buffer = result;
            } while (symbol != (unsigned char *)0x0);
            _strcat(result,DAT_a7b7bc0c);
            hashSize = *(uint *)(this + 0x10);
          }
          bucketIdx = bucketIdx + 1;
        } while (bucketIdx < hashSize);
      }
    }
    else if (mode < 2) {
      if (mode == 0) {
        while (result = buffer, symbol != (unsigned char *)0x0) {
          symbolText = ParseSymbol__GetString(symbol,1);
          if (symbolText != 0) {
            newLen = _strlen(symbolText);
            newLen = newLen + usedLen;
            needed = newLen + 1;
            if (capacity < needed) {
              capacity = 0x800;
              if (0x800 < needed >> 2) {
                capacity = needed >> 2;
              }
              capacity = needed + capacity;
              result = (char *)_malloc(capacity);
              if (result == (char *)0x0) {
LAB_97bbe3d4:
                _free(buffer);
                _free(symbolText);
                return (char *)0x0;
              }
              _memmove(result,buffer,usedLen + 1);
              _free(buffer);
            }
            usedLen = newLen + 1;
            _strcat(result,symbolText);
            result[newLen] = '\n';
            result[usedLen] = '\0';
            _free(symbolText);
          }
          symbol = (unsigned char *)((int (*)())ParseSymbolTable__NextSymbol)(this,symbol);
          buffer = result;
        }
      }
    }
    else if (mode == 2) {
      _sprintf(buffer,DAT_a7b7bc10);
      usedLen = _strlen(buffer);
      do {
        while( true ) {
          symbol = (unsigned char *)((int (*)())ParseSymbolTable__NextSymbol)(this,(unsigned char *)0x0);
          while (symbol != (unsigned char *)0x0) {
            result = buffer;
            if ((**(char **)symbol == kindFilter) &&
               (symbolText = ParseSymbol__GetString(symbol,0), symbolText != 0)) {
              newLen = _strlen(symbolText);
              newLen = newLen + usedLen;
              needed = newLen + 2;
              if (capacity < needed) {
                capacity = 0x800;
                if (0x800 < needed >> 2) {
                  capacity = needed >> 2;
                }
                capacity = needed + capacity;
                result = (char *)_malloc(capacity);
                if (result == (char *)0x0) goto LAB_97bbe3d4;
                _memmove(result,buffer,usedLen + 1);
                _free(buffer);
              }
              usedLen = newLen + 1;
              _strcat(result,symbolText);
              result[newLen] = '\n';
              result[usedLen] = '\0';
              _free(symbolText);
            }
            symbol = (unsigned char *)((int (*)())ParseSymbolTable__NextSymbol)(this,symbol);
            buffer = result;
          }
          if (kindFilter != '\x02') break;
          kindFilter = '\x03';
          _strcat(buffer,DAT_a7b7bc14);
          sectionHeader = DAT_a7b7bc14;
LAB_97bbe53c:
          symbolText = _strlen(sectionHeader);
          usedLen = usedLen + symbolText;
        }
        if (kindFilter == '\x03') {
          kindFilter = '\x04';
          _strcat(buffer,DAT_a7b7bc18);
          sectionHeader = DAT_a7b7bc18;
          goto LAB_97bbe53c;
        }
        if (kindFilter == '\x04') {
          kindFilter = '\0';
          _strcat(buffer,DAT_a7b7bc1c);
          sectionHeader = DAT_a7b7bc1c;
          goto LAB_97bbe53c;
        }
        result = buffer;
      } while (kindFilter != '\0');
    }
  }
  return result;
}

/* TIntermSymbol__compileNode @ 0x97bbe56c (304 bytes) */
int TIntermSymbol__compileNode(this, pPStreamCompiler, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * pPStreamCompiler;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 typePointer;
  undefined4 id;
  undefined1 *puVar1;
  int symbol;
  undefined4 uVar3;
  unsigned char * this_00;
  unsigned char * pTVar4;
  undefined4 r4In0;
  int r9In0;
  undefined4 *this_01;
  
  this_01 = (undefined4 *)0x0;
  symbol = (**(code **)(*(int *)this + 0x60))(this,pPStreamCompiler,param_3,param_4,param_5,param_6);
  puVar1 = DAT_a7b7bd04;
  r9In0 = *(int *)(symbol + 4);
  *(undefined1 *)(r9In0 + *(int *)(r9In0 + -0xc)) = *DAT_a7b7bd04;
  if (*(int *)(symbol + 4) != 0) {
    uVar3 = (*(code *)**(undefined4 **)this)(this,r4In0,param_3,param_4,param_5,param_6,r9In0);
    *(undefined4 *)(pPStreamCompiler + 0x90) = uVar3;
    this_00 = operator_new(100);
    __ZN11ParseSymbolC1Ev(this_00);
    symbol = (**(code **)(*(int *)this + 0x60))(this);
    *(undefined1 *)(*(int *)(symbol + 4) + *(int *)(*(int *)(symbol + 4) + -0xc)) = *puVar1;
    ParseSymbol__SetName(this_00,*(char **)(symbol + 4));
    id = (**(code **)(*(int *)this + 0x5c))(this);
    *(undefined4 *)(this_00 + 0x28) = id;
    pTVar4 = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
    ParseSymbol__SetParseTreeType(this_00,pTVar4);
    typePointer = (**(code **)(*(int *)this + 0x3c))(this);
    *(undefined4 *)(this_00 + 0x10) = typePointer;
    this_01 = operator_new(0x38);
    __ZN12ParseOperandC1Ev(this_01);
    *this_01 = this_00;
  }
  return this_01;
}

/* TIntermConstantUnion__compileNode @ 0x97bbe69c (340 bytes) */
int TIntermConstantUnion__compileNode(this, pPStreamCompiler, param_3, param_4, param_5, param_6, param_7, param_8)
  unsigned char * this;
  unsigned char * pPStreamCompiler;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  void *this_00;
  undefined4 uVar4;
  undefined **local_50 [9];
  uint local_2c;
  
  this_00 = operator_new(0x38);
  __ZN12ParseOperandC1Ev(this_00);
  uVar4 = (*(code *)**(undefined4 **)this)(this);
  *(undefined4 *)(pPStreamCompiler + 0x90) = uVar4;
  (**(code **)(*(int *)this + 0x38))(local_50,this);
  if ((local_2c & 0x400) == 0) {
    iVar1 = (int)(local_2c << 0xd | local_2c >> 0x13) >> 0x18;
  }
  else {
    iVar1 = (int)(local_2c << 0xd | local_2c >> 0x13) >> 0x18;
    iVar1 = iVar1 * iVar1;
  }
  *(int *)((int)this_00 + 0x24) = iVar1;
  local_50[0] = &PTR___ZN5TTypeD1Ev_a7b7d730;
  *(undefined4 *)((int)this_00 + 4) = *(undefined4 *)(this + 0x30);
  (**(code **)(*(int *)this + 0x38))(local_50,this);
  local_50[0] = &PTR___ZN5TTypeD1Ev_a7b7d730;
  uVar2 = local_2c >> 0x13 & 0x3f;
  if (uVar2 == 2) {
    uVar3 = 0x1404;
LAB_97bbe7a0:
    *(undefined2 *)((int)this_00 + 0x18) = uVar3;
  }
  else {
    if (uVar2 < 3) {
      if (uVar2 == 1) {
        uVar3 = 0x1406;
        goto LAB_97bbe7a0;
      }
    }
    else {
      if (uVar2 == 3) {
        uVar3 = 0x8b56;
        goto LAB_97bbe7a0;
      }
      if (uVar2 == 0xe) {
        TPPStreamCompiler__error
                  (pPStreamCompiler,(char *)0x1,(char *)0x0,
                   "TIntermConstantUnion::compileNode: EbtStruct constant union type, investigate",
                   param_5,param_6,param_7,param_8);
      }
    }
    TPPStreamCompiler__error
              (pPStreamCompiler,(char *)0x1,(char *)0x0,
               "TIntermConstantUnion::compileNode: Unexpected constant union type",param_5,param_6,
               param_7,param_8);
  }
  return this_00;
}

/* TIntermBinary__compileNode @ 0x97bbe7f0 (3444 bytes) */
int TIntermBinary__compileNode(this, compiler, unusedArg3, unusedArg4, unusedArg5, unusedArg6)
  unsigned char * this;
  unsigned char * compiler;
  undefined4 unusedArg3;
  char *unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
{
  unsigned char * leftOperandToDelete;
  unsigned char * rightOperandToDelete;
  unsigned char * operandWorkPtr;
  unsigned char * addrTempArg;
  undefined4 *swizzleIter;
  int operatorTokenOffset;
  int fieldNameString;
  int logicalSize;
  int resultQualifier;
  int binaryOp;
  int swizzleMap;
  int fieldTypeVtable;
  int leftIsMatrix;
  uint isMatrixFlag;
  uint swizzleIndex;
  uint glTypeArg;
  uint ppStreamType;
  unsigned char * thisType;
  undefined4 callArgOne;
  undefined4 symbolIsArray;
  int *resultParseType;
  int *swizzleChildTyped;
  int *rightAggregateNode;
  int *fieldType;
  int swizzleSequence;
  int swizzleCount;
  int *right;
  int *left;
  int isArrayResult;
  ushort glType;
  unsigned char * leftOperandToFree;
  int op;
  undefined4 currentLine;
  int *leftType;
  int leftIsArray;
  unsigned char * leftNodeType;
  unsigned char * newLeftOperand;
  unsigned char * leftSymbol;
  undefined1 swizzleComponent;
  int rightAggregate;
  int swizzleConstant;
  void *operandCopy;
  undefined4 r4In0;
  undefined4 r4In1;
  undefined4 r4In2;
  undefined4 r4In3;
  uchar newSwizzleComponent;
  undefined4 r4Out0;
  undefined4 r4Out1;
  unsigned char ** operandSlotPtr;
  undefined4 *thisVtable;
  uint *rightConstData;
  undefined4 zeroCallArg;
  uint indexValue;
  int fieldIndex;
  undefined8 operandPairResult;
  uint opHeader;
  uint opFlags;
  uint opDest0;
  undefined4 opDest1;
  uint opSrc0A;
  undefined4 opSrc0B;
  uint opSrc1A;
  undefined4 opSrc1B;
  uint opSrc2A;
  undefined4 opSrc2B;
  undefined4 opAuxA;
  undefined4 opAuxB;
  undefined4 opLine;
  undefined4 opWord13;
  uint operandDescOrSprintfBuffer;
  undefined4 operandDescB;
  undefined **structType [2];
  int structTypeFields;
  int arrayStride;
  unsigned char * addrTempOperand;
  unsigned char * leftOperand;
  unsigned char * rightOperand;
  unsigned char * resultOperand [6];
  
  zeroCallArg = 0;
  opAuxA = 0;
  opAuxB = 0;
  opHeader = 0;
  opFlags = 0;
  opDest0 = 0;
  opDest1 = 0;
  opSrc0A = 0;
  opSrc0B = 0;
  opSrc1A = 0;
  opSrc1B = 0;
  opSrc2A = 0;
  opSrc2B = 0;
  opWord13 = 0;
  resultOperand[0] = (unsigned char *)0x0;
  leftOperand = (unsigned char *)0x0;
  rightOperand = (unsigned char *)0x0;
  opLine = 0;
  opLine = (*(code *)**(undefined4 **)this)(this,compiler,unusedArg3,unusedArg4,unusedArg5,unusedArg6);
  thisVtable = *(undefined4 **)this;
  opHeader = opHeader & 0x1fffffff | 0x40000000;
  currentLine = (*(code *)*thisVtable)(this,r4In0,unusedArg3,unusedArg4,unusedArg5,unusedArg6,thisVtable);
  *(undefined4 *)(compiler + 0x90) = currentLine;
  left = *(int **)(this + 0x34);
  if (left != (int *)0x0) {
    leftOperand = (unsigned char *)(**(code **)(*left + 0xc))(left,compiler);
    op = *(int *)(this + 0x30);
    if (((op != 0x2d) && (op != 0x2e)) && (op != 0x2f)) {
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(compiler + 0x68),leftOperand);
    }
  }
  right = *(int **)(this + 0x38);
  if (right != (int *)0x0) {
    rightOperand = (unsigned char *)(**(code **)(*right + 0xc))(right,compiler);
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(compiler + 0x68),rightOperand);
  }
  op = *(int *)(this + 0x30);
  if (op == 0x2d) {
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(compiler + 0x68),rightOperand);
    rightConstData = *(uint **)(rightOperand + 4);
    indexValue = *rightConstData;
    leftType = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))
                              (*(int **)(this + 0x34),r4In1,unusedArg3,unusedArg4,op,unusedArg6,rightConstData);
    leftIsArray = (**(code **)(*leftType + 0x38))(leftType);
    if (leftIsArray == 0) {
      ParseOperand__AddDirectIndex(leftOperand,indexValue);
    }
    else {
      ParseSymbol__AddDirectIndex(*(unsigned char **)leftOperand,indexValue);
      _sprintf((char *)&operandDescOrSprintfBuffer,"[%d]",indexValue);
      ParseSymbol__CatName(*(unsigned char **)leftOperand,(char *)&operandDescOrSprintfBuffer);
      isArrayResult = (**(code **)(*(int *)this + 0x54))(this);
      if (isArrayResult == 0) {
        symbolIsArray = 1;
LAB_97bbf03c:
        leftSymbol = *(unsigned char **)leftOperand;
        *(undefined4 *)(leftSymbol + 0x48) = symbolIsArray;
        ParseSymbol__ResolveOpenGLType(leftSymbol);
      }
      else {
        TPPStreamCompiler__error
                  (compiler,(char *)0x1,(char *)0x0,
                   "TIntermBinary::compileNode: Array index results in another array, this is not handled"
                   ,op,unusedArg6,rightConstData,zeroCallArg);
      }
    }
LAB_97bbf04c:
    resultOperand[0] = leftOperand;
    goto LAB_97bbf4fc;
  }
  if (op == 0x2e) {
    if (*(int *)leftOperand == 0) {
      leftNodeType = (unsigned char *)(**(code **)(**(int **)(this + 0x34) + 0x3c))(*(int **)(this + 0x34));
      newLeftOperand = (unsigned char *)
               TPPStreamCompiler__newIndirectOperandFromConstant(compiler,leftOperand,leftNodeType);
      leftOperandToFree = leftOperand;
      if (leftOperand != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(leftOperand);
        __ZdlPv(leftOperandToFree);
      }
    }
    else {
      leftType = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))(*(int **)(this + 0x34));
      leftIsArray = (**(code **)(*leftType + 0x38))(leftType);
      newLeftOperand = leftOperand;
      if (leftIsArray != 0) {
        _sprintf((char *)&operandDescOrSprintfBuffer,"[%d]",0);
        ParseSymbol__CatName(*(unsigned char **)leftOperand,(char *)&operandDescOrSprintfBuffer);
        isArrayResult = (**(code **)(*(int *)this + 0x54))(this);
        if (isArrayResult == 0) {
          leftSymbol = *(unsigned char **)leftOperand;
          *(undefined4 *)(leftSymbol + 0x48) = 1;
          ParseSymbol__ResolveOpenGLType(leftSymbol);
          newLeftOperand = leftOperand;
        }
        else {
          unusedArg4 = 
          "TIntermBinary::compileNode: Array index results in another array, this is not handled";
          TPPStreamCompiler__error
                    (compiler,(char *)0x1,(char *)0x0,
                     "TIntermBinary::compileNode: Array index results in another array, this is not handled"
                     ,op,unusedArg6,thisVtable,zeroCallArg);
          newLeftOperand = leftOperand;
        }
      }
    }
    leftOperand = newLeftOperand;
    leftType = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))(*(int **)(this + 0x34));
    leftIsArray = (**(code **)(*leftType + 0x38))(leftType);
    if (leftIsArray == 0) {
      ParseOperand__AddDirectIndex(leftOperand,0);
    }
    else {
      ParseSymbol__AddDirectIndex(*(unsigned char **)leftOperand,0);
    }
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(compiler + 0x68),leftOperand);
    leftType = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))(*(int **)(this + 0x34));
    leftIsArray = (**(code **)(*leftType + 0x38))(leftType);
    if (leftIsArray == 0) {
      leftType = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))(*(int **)(this + 0x34));
      leftIsMatrix = (**(code **)(*leftType + 0x34))(leftType);
      if (leftIsMatrix == 0) {
        *(unsigned char **)(leftOperand + 0xc) = rightOperand;
        rightOperand = (unsigned char *)0x0;
        goto LAB_97bbf04c;
      }
    }
    leftType = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))(*(int **)(this + 0x34));
    leftIsArray = (**(code **)(*leftType + 0x38))(leftType);
    if (leftIsArray == 0) {
      arrayStride = 1;
    }
    else {
      arrayStride = TPPStreamCompiler__getArrayOffset(compiler,leftOperand);
    }
    resultOperand[0] = leftOperand;
    addrTempOperand = *(unsigned char **)(leftOperand + 8);
    if (addrTempOperand == (unsigned char *)0x0) {
      addrTempOperand = (unsigned char *)TPPStreamCompiler__newAddressTemp(compiler);
      if (arrayStride < 2) {
        opHeader = opHeader & 0x3c03ffff | 0x20000000;
        TPPStreamCompiler__getOperandAsDestVar
                  ((unsigned char *)&operandDescOrSprintfBuffer,compiler,addrTempOperand,unusedArg4,op,unusedArg6);
        opDest0 = operandDescOrSprintfBuffer;
        opDest1 = operandDescB;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&operandDescOrSprintfBuffer,compiler,rightOperand,unusedArg4,op,unusedArg6,thisVtable,zeroCallArg);
        opFlags = (opDest0 >> 0xc & 1) << 0x1c | opFlags & 0xefffffff;
        opSrc0A = operandDescOrSprintfBuffer;
        opSrc0B = operandDescB;
      }
      else {
        opHeader = opHeader & 0xfc03ffff | 0x880000;
        TPPStreamCompiler__getOperandAsDestVar
                  ((unsigned char *)&operandDescOrSprintfBuffer,compiler,addrTempOperand,unusedArg4,op,unusedArg6);
        opDest0 = operandDescOrSprintfBuffer;
        opDest1 = operandDescB;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&operandDescOrSprintfBuffer,compiler,rightOperand,unusedArg4,op,unusedArg6,thisVtable,zeroCallArg);
        opSrc0A = operandDescOrSprintfBuffer;
        opSrc0B = operandDescB;
        if (*(int *)addrTempOperand == 0) {
          glType = *(ushort *)(addrTempOperand + 0x18);
        }
        else {
          glType = *(ushort *)(*(int *)addrTempOperand + 0x2c);
        }
        TPPStreamCompiler__getConstantAsSourceVar
                  ((unsigned char *)&operandDescOrSprintfBuffer,(uint)compiler,&arrayStride,1,(uint)glType);
        opFlags = (opDest0 >> 0xc & 1) << 0x1c | opFlags & 0xefffffff;
        opSrc1A = operandDescOrSprintfBuffer;
        opSrc1B = operandDescB;
      }
      if (*(int *)addrTempOperand == 0) {
        glType = *(ushort *)(addrTempOperand + 0x18);
      }
      else {
        glType = *(ushort *)(*(int *)addrTempOperand + 0x2c);
      }
      ppStreamType = GetPPStreamTypeForGLType((uint)glType);
      opFlags = (ppStreamType & 7) << 0x17 | opFlags & 0xfc7fffff;
      logicalSize = ParseOperand__GetLogicalSize(addrTempOperand);
      opFlags = (logicalSize + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3ffffff;
      TPPStreamCompiler__AddOperation
                (compiler,&addrTempOperand,(unsigned char *)&opHeader,(char *)0x0,0);
      *(unsigned char **)(resultOperand[0] + 8) = addrTempOperand;
      goto LAB_97bbf4fc;
    }
    if (arrayStride < 2) {
      opHeader = opHeader & 0xfc03ffff | 0x7c0000;
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&operandDescOrSprintfBuffer,compiler,addrTempOperand,unusedArg4,op,unusedArg6);
      opDest0 = operandDescOrSprintfBuffer;
      opDest1 = operandDescB;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&operandDescOrSprintfBuffer,compiler,rightOperand,unusedArg4,op,unusedArg6,thisVtable,zeroCallArg);
      opSrc0A = operandDescOrSprintfBuffer;
      opSrc0B = operandDescB;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&operandDescOrSprintfBuffer,compiler,addrTempOperand,unusedArg4,op,unusedArg6,thisVtable,zeroCallArg);
      opFlags = (opDest0 >> 0xc & 1) << 0x1c | opFlags & 0xefffffff;
      opSrc1A = operandDescOrSprintfBuffer;
      opSrc1B = operandDescB;
    }
    else {
      opHeader = opHeader & 0x7c03ffff | 0x60fc0000;
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&operandDescOrSprintfBuffer,compiler,addrTempOperand,unusedArg4,op,unusedArg6);
      opDest0 = operandDescOrSprintfBuffer;
      opDest1 = operandDescB;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&operandDescOrSprintfBuffer,compiler,rightOperand,unusedArg4,op,unusedArg6,thisVtable,zeroCallArg);
      opSrc0A = operandDescOrSprintfBuffer;
      opSrc0B = operandDescB;
      if (*(int *)addrTempOperand == 0) {
        glType = *(ushort *)(addrTempOperand + 0x18);
      }
      else {
        glType = *(ushort *)(*(int *)addrTempOperand + 0x2c);
      }
      glTypeArg = (uint)glType;
      callArgOne = 1;
      addrTempArg = addrTempOperand;
      TPPStreamCompiler__getConstantAsSourceVar
                ((unsigned char *)&operandDescOrSprintfBuffer,(uint)compiler,&arrayStride,1,glTypeArg);
      opSrc1A = operandDescOrSprintfBuffer;
      opSrc1B = operandDescB;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&operandDescOrSprintfBuffer,compiler,addrTempOperand,callArgOne,glTypeArg,unusedArg6,addrTempArg,zeroCallArg);
      opFlags = (opDest0 >> 0xc & 1) << 0x1c | opFlags & 0xefffffff;
      opSrc2A = operandDescOrSprintfBuffer;
      opSrc2B = operandDescB;
    }
    if (*(int *)addrTempOperand == 0) {
      glType = *(ushort *)(addrTempOperand + 0x18);
    }
    else {
      glType = *(ushort *)(*(int *)addrTempOperand + 0x2c);
    }
    ppStreamType = GetPPStreamTypeForGLType((uint)glType);
    opFlags = (ppStreamType & 7) << 0x17 | opFlags & 0xfc7fffff;
    logicalSize = ParseOperand__GetLogicalSize(addrTempOperand);
    opFlags = (logicalSize + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3ffffff;
    operandSlotPtr = &addrTempOperand;
  }
  else {
    if (op == 0x2f) {
      leftSymbol = *(unsigned char **)leftOperand;
      (**(code **)(**(int **)(this + 0x34) + 0x38))(structType,*(int **)(this + 0x34));
      structType[0] = &PTR___ZN5TTypeD1Ev_a7b7d730;
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(compiler + 0x68),rightOperand);
      fieldIndex = **(int **)(rightOperand + 4);
      ParseSymbol__CatName(leftSymbol,".");
      fieldType = *(int **)(*(int *)(structTypeFields + 4) + fieldIndex * 8);
      fieldTypeVtable = *fieldType;
      fieldNameString = (**(code **)(fieldTypeVtable + 0x1c))(fieldType,r4In2,unusedArg3,unusedArg4,op,unusedArg6,fieldTypeVtable);
      *(undefined1 *)(*(int *)(fieldNameString + 4) + *(int *)(*(int *)(fieldNameString + 4) + -0xc)) = *DAT_a7b7bd04;
      ParseSymbol__CatName(leftSymbol,*(char **)(fieldNameString + 4));
      ParseSymbol__SetParseTreeType(leftSymbol,*(unsigned char **)(*(int *)(structTypeFields + 4) + fieldIndex * 8));
      symbolIsArray = 0;
      goto LAB_97bbf03c;
    }
    if (op == 0x30) {
      swizzleMap = 0;
      resultOperand[0] = leftOperand;
      swizzleCount = *(int *)(leftOperand + 0x14);
      if (swizzleCount != 0) {
        swizzleIndex = 0;
        swizzleMap = _malloc(swizzleCount);
        if (0 < swizzleCount) {
          do {
            swizzleComponent = ((int (*)())ParseOperand__GetSwizzle)(resultOperand[0],swizzleIndex);
            *(undefined1 *)(swizzleMap + swizzleIndex) = swizzleComponent;
            swizzleIndex = swizzleIndex + 1;
          } while ((int)swizzleIndex < swizzleCount);
        }
        ((int (*)())ParseOperand__ClearSwizzles)(resultOperand[0]);
      }
      rightAggregate = (**(code **)(**(int **)(this + 0x38) + 0x1c))(*(int **)(this + 0x38));
      if (rightAggregate == 0) {
        TPPStreamCompiler__error
                  (compiler,(char *)0x1,*(char **)(*(int *)leftOperand + 0x14),
                   "Right hand child of vector swizzle is not an aggregate node.",op,unusedArg6,
                   *(int *)leftOperand,zeroCallArg);
      }
      else {
        rightAggregateNode = (int *)(**(code **)(**(int **)(this + 0x38) + 0x1c))(*(int **)(this + 0x38));
        swizzleSequence = (**(code **)(*rightAggregateNode + 100))(rightAggregateNode);
        for (swizzleIter = *(undefined4 **)(swizzleSequence + 4); swizzleIter != *(undefined4 **)(swizzleSequence + 8);
            swizzleIter = swizzleIter + 1) {
          swizzleChildTyped = (int *)(**(code **)(*(int *)*swizzleIter + 0x14))((int *)*swizzleIter);
          swizzleConstant = (**(code **)(*swizzleChildTyped + 0x18))(swizzleChildTyped);
          if (swizzleConstant == 0) {
            TPPStreamCompiler__error
                      (compiler,(char *)0x1,*(char **)(*(int *)leftOperand + 0x14),
                       "Unexpected non-constant in vector swizzle.",op,unusedArg6,*(int *)leftOperand,
                       zeroCallArg);
          }
          else {
            if (swizzleCount == 0) {
              swizzleChildTyped = (int *)(**(code **)(*(int *)*swizzleIter + 0x14))((int *)*swizzleIter,r4In3);
              swizzleConstant = (**(code **)(*swizzleChildTyped + 0x18))(swizzleChildTyped);
              newSwizzleComponent = *(uchar *)(*(int *)(swizzleConstant + 0x30) + 3);
            }
            else {
              swizzleChildTyped = (int *)(**(code **)(*(int *)*swizzleIter + 0x14))((int *)*swizzleIter);
              swizzleConstant = (**(code **)(*swizzleChildTyped + 0x18))(swizzleChildTyped);
              newSwizzleComponent = *(uchar *)(swizzleMap + **(int **)(swizzleConstant + 0x30));
            }
            ParseOperand__AddSwizzle(resultOperand[0],newSwizzleComponent);
          }
        }
      }
      goto LAB_97bbf4fc;
    }
    if (op < 0x31) {
      if (op - 0x1dU < 2) {
        thisType = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
        operandWorkPtr = (unsigned char *)&leftOperand;
        operandSlotPtr = &rightOperand;
        operandPairResult = TPPStreamCompiler__equalOperands
                           (compiler,thisType,(unsigned char **)operandWorkPtr,operandSlotPtr,(uint)(op == 0x1d));
      }
      else {
LAB_97bbf334:
        thisType = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
        resultOperand[0] = (unsigned char *)TPPStreamCompiler__newTemporary(compiler,thisType);
        operandSlotPtr = &rightOperand;
        __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_
                  (compiler,resultOperand,&leftOperand,operandSlotPtr);
LAB_97bbf370:
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&operandDescOrSprintfBuffer,compiler,leftOperand,operandSlotPtr,op,unusedArg6,thisVtable,zeroCallArg)
        ;
        opSrc0A = operandDescOrSprintfBuffer;
        opSrc0B = operandDescB;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&operandDescOrSprintfBuffer,compiler,rightOperand,operandSlotPtr,op,unusedArg6,thisVtable,zeroCallArg)
        ;
        opSrc1A = operandDescOrSprintfBuffer;
        opSrc1B = operandDescB;
        operandWorkPtr = resultOperand[0];
        TPPStreamCompiler__getOperandAsDestVar
                  ((unsigned char *)&operandDescOrSprintfBuffer,compiler,resultOperand[0],operandSlotPtr,op,unusedArg6);
        operandPairResult = CONCAT44(resultOperand[0],r4Out1);
        opDest0 = operandDescOrSprintfBuffer;
        opDest1 = operandDescB;
      }
    }
    else {
      if (op != 0x76) {
        if ((op < 0x76) || (0x7e < op)) goto LAB_97bbf334;
        if ((*(int *)(leftOperand + 0xc) == 0) && (*(int *)(leftOperand + 8) == 0)) {
          resultOperand[0] = leftOperand;
        }
        else {
          operandWorkPtr = operator_new(0x38);
          __ZN12ParseOperandC1ERKS_(operandWorkPtr,leftOperand);
          resultOperand[0] = operandWorkPtr;
          if (*(int *)(leftOperand + 0xc) != 0) {
            operandCopy = operator_new(0x38);
            __ZN12ParseOperandC1ERKS_(operandCopy,*(unsigned char **)(leftOperand + 0xc));
            *(void **)(operandWorkPtr + 0xc) = operandCopy;
          }
          operandWorkPtr = resultOperand[0];
          if (*(int *)(leftOperand + 8) != 0) {
            operandCopy = operator_new(0x38);
            __ZN12ParseOperandC1ERKS_(operandCopy,*(unsigned char **)(leftOperand + 8));
            *(void **)(operandWorkPtr + 8) = operandCopy;
          }
        }
        operandSlotPtr = &rightOperand;
        __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_S2_
                  (compiler,resultOperand,&leftOperand,operandSlotPtr);
        goto LAB_97bbf370;
      }
      operandWorkPtr = (unsigned char *)&rightOperand;
      operandSlotPtr = (unsigned char **)0x1;
      resultOperand[0] = leftOperand;
      TPPStreamCompiler__assignOperands(compiler,&leftOperand,(unsigned char **)operandWorkPtr,1);
      operandPairResult = CONCAT44(resultOperand[0],r4Out0);
    }
    resultOperand[0] = (unsigned char *)((ulonglong)operandPairResult >> 0x20);
    binaryOp = *(int *)(this + 0x30);
    operatorTokenOffset = binaryOp * 4;
    opHeader = (*(uint *)(&_operatorToken + operatorTokenOffset) & 0xff) << 0x12 | opHeader & 0xfc03ffff;
    resultParseType = *(int **)(*(int *)resultOperand[0] + 0xc);
    if (resultParseType != (int *)0x0) {
      resultQualifier = (**(code **)(*resultParseType + 0x24))(resultParseType,(int)operandPairResult,operandWorkPtr,operandSlotPtr,binaryOp,unusedArg6,operatorTokenOffset);
      if (resultQualifier == 0xd) {
        *(undefined4 *)(compiler + 0xa4) = 1;
      }
      binaryOp = *(int *)(this + 0x30);
    }
    if (binaryOp < 0x31) {
      if (0x2c < binaryOp) goto LAB_97bbf4fc;
      if (0x16 < binaryOp) {
        if (binaryOp < 0x1d) goto LAB_97bbf46c;
        if (binaryOp < 0x1f) goto LAB_97bbf4fc;
      }
    }
    else {
      if (binaryOp == 0x76) goto LAB_97bbf4fc;
      if ((0x75 < binaryOp) && (binaryOp - 0x7fU < 6)) {
LAB_97bbf46c:
        TPPStreamCompiler__error
                  (compiler,(char *)0x1,(char *)0x0,
                   "TIntermBinary::compileNode: Unsupported operation (TOperator: %d)",binaryOp,unusedArg6
                   ,operatorTokenOffset,zeroCallArg);
        goto LAB_97bbf4fc;
      }
    }
    isMatrixFlag = ParseOperand__IsMatrix(resultOperand[0]);
    opFlags = (isMatrixFlag & 1) << 0x1c | opFlags & 0xefffffff;
    if (*(int *)resultOperand[0] == 0) {
      glType = *(ushort *)(resultOperand[0] + 0x18);
    }
    else {
      glType = *(ushort *)(*(int *)resultOperand[0] + 0x2c);
    }
    ppStreamType = GetPPStreamTypeForGLType((uint)glType);
    opFlags = (ppStreamType & 7) << 0x17 | opFlags & 0xfc7fffff;
    logicalSize = ParseOperand__GetLogicalSize(resultOperand[0]);
    opFlags = (logicalSize + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3ffffff;
    operandSlotPtr = resultOperand;
  }
  TPPStreamCompiler__AddOperation(compiler,operandSlotPtr,(unsigned char *)&opHeader,(char *)0x0,0);
LAB_97bbf4fc:
  rightOperandToDelete = rightOperand;
  if (rightOperand != (unsigned char *)0x0) {
    __ZN12ParseOperandD1Ev(rightOperand);
    __ZdlPv(rightOperandToDelete);
  }
  leftOperandToDelete = leftOperand;
  if ((leftOperand != (unsigned char *)0x0) && (resultOperand[0] != leftOperand)) {
    __ZN12ParseOperandD1Ev(leftOperand);
    __ZdlPv(leftOperandToDelete);
  }
  return resultOperand[0];
}

/* TIntermUnary__compileNode @ 0x97bbf564 (1824 bytes) */
int TIntermUnary__compileNode(this, compiler, unusedArg3, scratchArg4, scratchArg5, scratchArg6)
  unsigned char * this;
  unsigned char * compiler;
  undefined4 unusedArg3;
  undefined4 scratchArg4;
  undefined4 scratchArg5;
  uint scratchArg6;
{
  int resultQualifier;
  int opReload;
  unsigned char * operandToFree;
  unsigned char * sizeOperand;
  undefined4 callArgScratch;
  ushort glType;
  bool emitFinalOp;
  undefined4 currentLine;
  uint streamType;
  unsigned char * thisType;
  int *resultParseType;
  undefined4 r4In0;
  undefined4 r4In1;
  undefined4 r4In2;
  unsigned char * recordPtrArg;
  unsigned char * callArgOperand;
  undefined4 constGlType;
  unsigned char * scratchPtr7;
  uint opOrFormatWord;
  int logicalSize;
  uint op1Header;
  uint op1Flags;
  uint op1Dest0;
  undefined4 op1Dest1;
  uint op1Src0A;
  undefined4 op1Src0B;
  uint op1Src1A;
  undefined4 op1Src1B;
  undefined4 op1Src2A;
  undefined4 op1Src2B;
  undefined4 op1AuxA;
  undefined4 op1AuxB;
  undefined4 op1Line;
  undefined4 op1Word13;
  uint operandDesc;
  undefined4 operandDescB;
  uint op2Header;
  uint op2Flags;
  uint op2Dest0;
  undefined4 op2Dest1;
  uint op2Src0A;
  undefined4 op2Src0B;
  uint op2Src1A;
  undefined4 op2Src1B;
  undefined4 op2Src2A;
  undefined4 op2Src2B;
  undefined4 op2AuxA;
  undefined4 op2AuxB;
  undefined4 op2Line;
  undefined4 op2Word13;
  unsigned char * resultOperand;
  unsigned char * operand;
  undefined4 constValue [2];
  
  scratchPtr7 = (unsigned char *)0x0;
  op1AuxA = 0;
  op1AuxB = 0;
  op1Header = 0;
  op1Flags = 0;
  op1Dest0 = 0;
  op1Dest1 = 0;
  emitFinalOp = true;
  op1Src0A = 0;
  op1Src0B = 0;
  op1Src1A = 0;
  op1Src1B = 0;
  op1Src2A = 0;
  op1Src2B = 0;
  op1Word13 = 0;
  resultOperand = (unsigned char *)0x0;
  op1Line = 0;
  op1Line = (*(code *)**(undefined4 **)this)(this,compiler,unusedArg3,scratchArg4,scratchArg5,scratchArg6);
  op1Header = op1Header & 0x1fffffff | 0x20000000;
  currentLine = (*(code *)**(undefined4 **)this)(this);
  *(undefined4 *)(compiler + 0x90) = currentLine;
  operand = (unsigned char *)
             (**(code **)(**(int **)(this + 0x34) + 0xc))(*(int **)(this + 0x34),compiler);
  ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(compiler + 0x68),operand);
  opOrFormatWord = *(uint *)(this + 0x30);
  if (opOrFormatWord - 5 < 8) {
    scratchPtr7 = (unsigned char *)((opOrFormatWord - 5) * 4);
    switch(opOrFormatWord) {
    default:
      emitFinalOp = false;
      goto LAB_97bbfa5c;
    case 6:
    case 7:
      goto switchD_97bbf664_caseD_6;
    case 9:
    case 10:
      thisType = (unsigned char *)(**(code **)(*(int *)this + 0x3c))
                                  (this,r4In0,unusedArg3,scratchArg4,scratchArg5,scratchArg6,scratchPtr7,opOrFormatWord);
      resultOperand = (unsigned char *)TPPStreamCompiler__newTemporary(compiler,thisType);
      __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_
                (compiler,&resultOperand,&operand);
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&operandDesc,compiler,operand,scratchArg4,scratchArg5,scratchArg6,scratchPtr7,opOrFormatWord);
      op1Src0A = operandDesc;
      op1Src0B = operandDescB;
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&operandDesc,compiler,resultOperand,scratchArg4,scratchArg5,scratchArg6);
      op1Flags = (operandDesc >> 0xc & 1) << 0x1c | op1Flags & 0xefffffff;
      op1Header = op1Header & 0xfc03ffff;
      op1Dest1 = operandDescB;
      op1Dest0 = operandDesc;
      if (*(int *)resultOperand == 0) {
        glType = *(ushort *)(resultOperand + 0x18);
      }
      else {
        glType = *(ushort *)(*(int *)resultOperand + 0x2c);
      }
      scratchPtr7 = resultOperand;
      opOrFormatWord = GetPPStreamTypeForGLType((uint)glType);
      op1Flags = (opOrFormatWord & 7) << 0x17 | op1Flags & 0xfc7fffff;
      logicalSize = ParseOperand__GetLogicalSize(resultOperand);
      op1Flags = (logicalSize + -1) * 0x4000000 & 0xc000000U | op1Flags & 0xf3ffffff;
      recordPtrArg = (unsigned char *)&op1Header;
      callArgScratch = 0;
      constGlType = 0;
      TPPStreamCompiler__AddOperation(compiler,&resultOperand,recordPtrArg,(char *)0x0,0);
      op2AuxA = 0;
      op2AuxB = 0;
      op2Header = 0;
      op2Flags = 0;
      op2Dest0 = 0;
      op2Dest1 = 0;
      op2Src0A = 0;
      op2Src0B = 0;
      op2Src1A = 0;
      op2Src1B = 0;
      op2Src2A = 0;
      op2Src2B = 0;
      op2Word13 = 0;
      op2Line = 0;
      op2Line = (*(code *)**(undefined4 **)this)
                           (this,r4In1,recordPtrArg,callArgScratch,constGlType,scratchArg6,*(undefined4 **)this);
      op2Header = op2Header & 0x1fffffff | 0x40000000;
      if (*(int *)operand == 0) {
        glType = *(ushort *)(operand + 0x18);
      }
      else {
        glType = *(ushort *)(*(int *)operand + 0x2c);
      }
      callArgOperand = operand;
      opOrFormatWord = GetPPStreamTypeForGLType((uint)glType);
      if (opOrFormatWord == 3) {
        constGlType = 0x1404;
LAB_97bbf88c:
        constValue[0] = 1;
LAB_97bbf894:
        callArgScratch = 1;
        TPPStreamCompiler__getConstantAsSourceVar
                  ((unsigned char *)&operandDesc,(uint)compiler,constValue,1,constGlType);
        op2Src1A = operandDesc;
        op2Src1B = operandDescB;
      }
      else if (opOrFormatWord < 4) {
        if (opOrFormatWord == 1) {
          constGlType = 0x1406;
          constValue[0] = 0x3f800000;
          goto LAB_97bbf894;
        }
      }
      else if (opOrFormatWord == 4) {
        constGlType = 0x8b56;
        goto LAB_97bbf88c;
      }
      __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_
                (compiler,&operand,&operand);
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&operandDesc,compiler,operand,callArgScratch,constGlType,scratchArg6,callArgOperand,scratchPtr7);
      op2Src0A = operandDesc;
      op2Src0B = operandDescB;
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&operandDesc,compiler,operand,callArgScratch,constGlType,scratchArg6);
      scratchArg6 = *(uint *)(&_operatorToken + *(int *)(this + 0x30) * 4);
      opOrFormatWord = (scratchArg6 & 0xff) << 0x12 | op2Header & 0xfc03ffff;
      op2Flags = (op1Dest0 >> 0xc & 1) << 0x1c | op2Flags & 0xefffffff;
      op2Dest0 = operandDesc;
      op2Dest1 = operandDescB;
      if (*(int *)operand == 0) {
        glType = *(ushort *)(operand + 0x18);
      }
      else {
        glType = *(ushort *)(*(int *)operand + 0x2c);
      }
      scratchPtr7 = operand;
      op2Header = opOrFormatWord;
      streamType = GetPPStreamTypeForGLType((uint)glType);
      op2Flags = (streamType & 7) << 0x17 | op2Flags & 0xfc7fffff;
      emitFinalOp = false;
      logicalSize = ParseOperand__GetLogicalSize(operand);
      op2Flags = (logicalSize + -1) * 0x4000000 & 0xc000000U | op2Flags & 0xf3ffffff;
      scratchArg4 = 0;
      scratchArg5 = 0;
      TPPStreamCompiler__AddOperation
                (compiler,&operand,(unsigned char *)&op2Header,(char *)0x0,0);
      break;
    case 0xb:
    case 0xc:
      op1Header = op1Header & 0x1fffffff | 0x40000000;
      if (*(int *)operand == 0) {
        glType = *(ushort *)(operand + 0x18);
      }
      else {
        glType = *(ushort *)(*(int *)operand + 0x2c);
      }
      streamType = GetPPStreamTypeForGLType((uint)glType);
      if (streamType == 3) {
        scratchArg5 = 0x1404;
LAB_97bbfa3c:
        constValue[0] = 1;
LAB_97bbfa44:
        scratchArg4 = 1;
        TPPStreamCompiler__getConstantAsSourceVar
                  ((unsigned char *)&operandDesc,(uint)compiler,constValue,1,scratchArg5);
        op1Src1A = operandDesc;
        op1Src1B = operandDescB;
      }
      else if (streamType < 4) {
        if (streamType == 1) {
          scratchArg5 = 0x1406;
          constValue[0] = 0x3f800000;
          goto LAB_97bbfa44;
        }
      }
      else if (streamType == 4) {
        scratchArg5 = 0x8b56;
        goto LAB_97bbfa3c;
      }
LAB_97bbfa5c:
      resultOperand = operand;
    }
  }
  else {
switchD_97bbf664_caseD_6:
    thisType = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
    resultOperand = (unsigned char *)TPPStreamCompiler__newTemporary(compiler,thisType);
  }
  if (emitFinalOp) {
    __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_(compiler,&resultOperand,&operand)
    ;
    TPPStreamCompiler__getOperandAsSourceVar
              ((unsigned char *)&operandDesc,compiler,operand,scratchArg4,scratchArg5,scratchArg6,scratchPtr7,opOrFormatWord);
    op1Src0A = operandDesc;
    op1Src0B = operandDescB;
    callArgOperand = resultOperand;
    TPPStreamCompiler__getOperandAsDestVar
              ((unsigned char *)&operandDesc,compiler,resultOperand,scratchArg4,scratchArg5,scratchArg6);
    opReload = *(int *)(this + 0x30);
    op1Header = (*(uint *)(&_operatorToken + opReload * 4) & 0xff) << 0x12 | op1Header & 0xfc03ffff;
    op1Dest1 = operandDescB;
    op1Dest0 = operandDesc;
    scratchPtr7 = *(unsigned char **)resultOperand;
    resultParseType = *(int **)(scratchPtr7 + 0xc);
    if (resultParseType == (int *)0x0) goto LAB_97bbfb3c;
    resultQualifier = (**(code **)(*resultParseType + 0x24))(resultParseType,r4In2,callArgOperand,scratchArg4,scratchArg5,scratchArg6,scratchPtr7,opReload);
    if (resultQualifier == 0xd) {
      *(undefined4 *)(compiler + 0xa4) = 1;
    }
  }
  opReload = *(int *)(this + 0x30);
LAB_97bbfb3c:
  if (opReload == 5) {
    *(uint *)(operand + 0x28) = (uint)(*(int *)(operand + 0x28) != 1);
  }
  else if (opReload == 8) {
    TPPStreamCompiler__error
              (compiler,(char *)0x1,(char *)0x0,
               "SecondPassProcessAggregateOp: EOpBitwiseNot not supported",scratchArg5,scratchArg6,scratchPtr7,8)
    ;
  }
  if (emitFinalOp) {
    opReload = *(int *)(this + 0x30);
    if (((opReload == 0x4b) || (opReload == 0x57)) || (opReload == 0x58)) {
      op1Flags = (op1Src0A >> 0xe & 1) << 0x1c | op1Flags & 0xefffffff;
      if (*(int *)operand == 0) {
        glType = *(ushort *)(operand + 0x18);
      }
      else {
        glType = *(ushort *)(*(int *)operand + 0x2c);
      }
      opOrFormatWord = GetPPStreamTypeForGLType((uint)glType);
      sizeOperand = operand;
    }
    else {
      op1Flags = (op1Dest0 >> 0xc & 1) << 0x1c | op1Flags & 0xefffffff;
      if (*(int *)resultOperand == 0) {
        glType = *(ushort *)(resultOperand + 0x18);
      }
      else {
        glType = *(ushort *)(*(int *)resultOperand + 0x2c);
      }
      opOrFormatWord = GetPPStreamTypeForGLType((uint)glType);
      sizeOperand = resultOperand;
    }
    op1Flags = (opOrFormatWord & 7) << 0x17 | op1Flags & 0xfc7fffff;
    logicalSize = ParseOperand__GetLogicalSize(sizeOperand);
    op1Flags = (logicalSize + -1) * 0x4000000 & 0xc000000U | op1Flags & 0xf3ffffff;
    TPPStreamCompiler__AddOperation(compiler,&resultOperand,(unsigned char *)&op1Header,(char *)0x0,0)
    ;
  }
  operandToFree = operand;
  if ((resultOperand != operand) && (operand != (unsigned char *)0x0)) {
    __ZN12ParseOperandD1Ev(operand);
    __ZdlPv(operandToFree);
  }
  return resultOperand;
}

/* TIntermAggregate__compileNode @ 0x97bbfca4 (4308 bytes) */
int TIntermAggregate__compileNode(this, compiler, parseOperand2, strayArg4, strayArg5, strayArg6)
  unsigned char * this;
  unsigned char * compiler;
  unsigned char ** parseOperand2;
  int strayArg4;
  undefined4 strayArg5;
  undefined4 strayArg6;
{
  unsigned char *constructedType;
  unsigned char *paramType;
  char *functionNameData;
  char *nodeType;
  undefined4 functionIsEmpty;
  undefined4 newParamOperand;
  undefined4 labelLength;
  undefined4 sourceLine;
  int *childTypeObj;
  int *operandTypeObj;
  int *queuedNode;
  int lastOpIndexNow;
  int callArgTypeKind;
  int callArgTypeVtable;
  int lastParamOpIndex;
  int functionFirstOp;
  int copyBackIndex;
  int paramByteOffset;
  int lastOpBefore;
  int pendingQueueSize;
  int mainNameCompare;
  int operandsLeft;
  int argTypeKind;
  int argTypeVtable;
  int curLastOpIndex;
  int paramScanIndex;
  int returnNameData;
  int isWriteableFlag;
  int paramSetupIndex;
  int lastOperation;
  int ppStream;
  uint operatorOffset;
  uint ppStreamType;
  uint srcOperandOffset;
  uint lastOpIndexAtEnd;
  uint opHeaderWord;
  int logicalSize;
  int firstChildTypeInfo;
  int src2SelectCode;
  int headerOpcode;
  int lastOpIndex;
  int paramIndex;
  int paramOperandArray;
  int operatorTimes4;
  int typeKindCode;
  int callNestingDepth;
  int functionIndex;
  int *refCountPtr;
  int oldRefCount;
  int newRefCount;
  int name2;
  int name;
  int name3;
  int name4;
  bool hasChildren;
  byte terminalChar;
  ushort operandGLType;
  byte *terminalCharPtr;
  undefined **stackTypeVtable;
  int aggregateOp;
  undefined4 carriedR4;
  int calleeNameObj;
  unsigned char *resultType;
  unsigned char ** childOperandCopies;
  unsigned char * functionTable;
  unsigned char * operandCopy;
  undefined4 r4Out0;
  undefined4 r4In0;
  undefined4 r4In1;
  undefined4 r4Out1;
  undefined4 r4Out2;
  undefined4 r4Out3;
  undefined4 r4Out4;
  undefined4 r4Out5;
  undefined4 r4In2;
  undefined4 r4Out6;
  undefined4 r4Out7;
  undefined4 r4Out8;
  undefined4 r4In3;
  undefined4 r4In4;
  undefined4 r4Out9;
  undefined4 r4Out10;
  undefined4 r4Out11;
  undefined4 r4Out12;
  undefined4 r4In5;
  undefined4 r4Out13;
  undefined4 r4In6;
  undefined4 r4In7;
  unsigned char ** operandArraySel;
  unsigned char ** paramSlotPtr;
  unsigned char * opHeaderOrParamSlotPtr;
  uint returnTypeBits;
  int defReturnNameData;
  uint operatorCode;
  uint r10In0;
  int childCount;
  unsigned char ** childOperands;
  int labelNameObj;
  undefined4 *paramListCursor;
  unsigned char * functionStack;
  undefined4 returnValueName;
  uint *srcSlotCursor;
  unsigned char * childOperand;
  undefined4 *childCursor;
  void *operandTemp;
  char reservation;
  byte cr0Reg;
  undefined8 resultAndR4Pair;
  uint opHeaderAndFlags [2];
  undefined **opDest0;
  uint opDest1;
  undefined **opSrc0A;
  uint opSrc0B;
  undefined **opSrc1A;
  uint opSrc1B;
  uint opSrc2A;
  undefined4 opSrc2B;
  undefined **opAuxA;
  uint opAuxB;
  undefined4 opLine;
  undefined4 opLabelLength;
  undefined **stackType;
  uint stackTypeArraySize;
  uint stackTypeBits;
  undefined **destroyAllocatorArg [4];
  unsigned char * paramTempOperand;
  unsigned char * argTempOperand;
  unsigned char * resultOperand [3];
  
  childOperands = (unsigned char **)0x0;
  opAuxA = (undefined **)0x0;
  opAuxB = 0;
  opHeaderAndFlags[0] = 0;
  opHeaderAndFlags[1] = 0;
  opDest0 = (undefined **)0x0;
  opDest1 = 0;
  opSrc0A = (undefined **)0x0;
  opSrc0B = 0;
  opSrc1A = (undefined **)0x0;
  opSrc1B = 0;
  opSrc2A = 0;
  opSrc2B = 0;
  resultOperand[0] = (unsigned char *)0x0;
  opLine = 0;
  opLabelLength = 0;
  ppStream = *(int *)(compiler + 0x70);
  childCount = *(int *)(this + 0x3c) - *(int *)(this + 0x38) >> 2;
  opLine = (*(code *)**(undefined4 **)this)
                       (this,compiler,parseOperand2,strayArg4,strayArg5,strayArg6,*(int *)(this + 0x38));
  sourceLine = (*(code *)**(undefined4 **)this)(this);
  *(undefined4 *)(compiler + 0x90) = sourceLine;
  aggregateOp = *(int *)(this + 0x30);
  if (aggregateOp == 3) {
    name = (**(code **)(*(int *)this + 0x6c))(this);
    terminalCharPtr = DAT_a7b7bd04;
    *(byte *)(*(int *)(name + 4) + *(int *)(*(int *)(name + 4) + -0xc)) = *DAT_a7b7bd04;
    labelLength = _strlen(*(undefined4 *)(name + 4));
    name = (**(code **)(*(int *)this + 0x6c))(this);
    *(byte *)(*(int *)(name + 4) + *(int *)(*(int *)(name + 4) + -0xc)) = *terminalCharPtr;
    _PPStreamAddLabel(ppStream,*(undefined4 *)(name + 4),labelLength);
    name = (**(code **)(*(int *)this + 0x6c))(this);
    *(byte *)(*(int *)(name + 4) + *(int *)(*(int *)(name + 4) + -0xc)) = *terminalCharPtr;
    functionIndex = FunctionTable__addFunction(*(unsigned char **)(compiler + 0x6c),*(char **)(name + 4));
    name2 = (**(code **)(*(int *)this + 0x6c))(this);
    *(byte *)(*(int *)(name2 + 4) + *(int *)(*(int *)(name2 + 4) + -0xc)) = *terminalCharPtr;
    ParseFunctionStack__push((unsigned char *)(compiler + 0x58),*(char **)(name2 + 4));
    name2 = (**(code **)(*(int *)this + 0x6c))(this);
    *(byte *)(*(int *)(name2 + 4) + *(int *)(*(int *)(name2 + 4) + -0xc)) = *terminalCharPtr;
    mainNameCompare = _memcmp(*(undefined4 *)(name2 + 4),"main(",5);
    if (mainNameCompare == 0) {
      parseOperand2 = (unsigned char **)0x0;
      FunctionTable__setFirstOp(*(unsigned char **)(compiler + 0x6c),functionIndex,0);
      *(undefined4 *)(compiler + 0xac) = 1;
      while (pendingQueueSize = ((int (*)())size)((unsigned char *)(compiler + 0x4c)), pendingQueueSize != 0) {
        queuedNode = (int *)fetch((unsigned char *)(compiler + 0x4c));
        (**(code **)(*queuedNode + 0xc))(queuedNode,compiler);
      }
    }
    else {
      lastOpBefore = TPPStreamCompiler__LastOperationIndex(compiler);
      parseOperand2 = (unsigned char **)0x1;
      if (lastOpBefore != -1) {
        parseOperand2 = (unsigned char **)(lastOpBefore + 1);
      }
      FunctionTable__setFirstOp(*(unsigned char **)(compiler + 0x6c),functionIndex,(uint)parseOperand2);
    }
    (**(code **)(*(int *)this + 0x38))(&stackType,this);
    returnTypeBits = stackTypeBits & 0x1f80000;
    cr0Reg = (returnTypeBits == 0) << 1;
    stackType = &PTR___ZN5TTypeD1Ev_a7b7d730;
    carriedR4 = r4In0;
    if (returnTypeBits != 0) {
      name2 = (**(code **)(*(int *)this + 0x6c))(this,r4In0,parseOperand2,strayArg4,strayArg5,strayArg6,returnTypeBits);
      defReturnNameData = *(int *)(name2 + 4);
      *(byte *)(defReturnNameData + *(int *)(defReturnNameData + -0xc)) = *DAT_a7b7bd04;
      carriedR4 = *(undefined4 *)(name2 + 4);
      nodeType = (char *)(**(code **)(*(int *)this + 0x3c))
                                 (this,r4In1,parseOperand2,strayArg4,strayArg5,strayArg6,defReturnNameData,name2);
      resultOperand[0] = (unsigned char *)TPPStreamCompiler__newReturnValue((unsigned char *)compiler,nodeType,carriedR4)
      ;
      parseOperand2 = (unsigned char **)0x1;
      FunctionTable__setReturnVal(*(unsigned char **)(compiler + 0x6c),functionIndex,1);
      carriedR4 = r4Out1;
    }
  }
  else {
    carriedR4 = r4Out0;
    if ((aggregateOp != 2) && (aggregateOp == 1)) {
      callNestingDepth = *(int *)(compiler + 0x98);
      if (0 < callNestingDepth) {
        resultAndR4Pair = ParseFunctionStack__empty((unsigned char *)(compiler + 0x58));
        carriedR4 = (undefined4)resultAndR4Pair;
        if ((int)((ulonglong)resultAndR4Pair >> 0x20) != 0) {
          ((int (*)())store)((unsigned char *)(compiler + 0x4c),this);
          return (unsigned char *)0x0;
        }
        callNestingDepth = *(int *)(compiler + 0x98);
      }
      *(int *)(compiler + 0x98) = callNestingDepth + 1;
    }
  }
  hasChildren = childCount != 0;
  if (hasChildren) {
    childOperands = (unsigned char **)_malloc(childCount << 2);
    carriedR4 = r4Out2;
    childOperandCopies = childOperands;
    for (childCursor = *(undefined4 **)(this + 0x38); childCursor != *(undefined4 **)(this + 0x3c);
        childCursor = childCursor + 1) {
      childOperand = (unsigned char *)(**(code **)(*(int *)*childCursor + 0xc))((int *)*childCursor,compiler);
      *childOperandCopies = childOperand;
      childOperandCopies = childOperandCopies + 1;
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(compiler + 0x68),childOperand);
      carriedR4 = r4Out3;
    }
  }
  resultAndR4Pair = CONCAT44(resultOperand[0],carriedR4);
  operatorCode = *(uint *)(this + 0x30);
  r10In0 = (*(uint *)(&_operatorToken + operatorCode * 4) & 0xff) << 0x12 |
       childCount << 0x1d | opHeaderAndFlags[0] & 0x1c03ffff;
  opHeaderWord = r10In0;
  switch(operatorCode) {
  case 0x15:
    opHeaderWord = childCount << 0x1d | opHeaderAndFlags[0] & 0x1c03ffff | 0x8c0000;
  case 0x17:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x38:
  case 0x39:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x48:
  case 0x49:
  case 0x4a:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x50:
  case 0x51:
  case 0x52:
  case 0x85:
  case 0x8a:
  case 0x8b:
  case 0x8c:
  case 0x8d:
  case 0x8e:
  case 0x8f:
  case 0x90:
  case 0x91:
  case 0x92:
  case 0x93:
  case 0x94:
  case 0x95:
  case 0x96:
  case 0x97:
  case 0x98:
  case 0x99:
  case 0x9a:
  case 0x9b:
  case 0x9c:
  case 0x9d:
  case 0x9e:
  case 0x9f:
  case 0xa0:
  case 0xa1:
  case 0xa2:
  case 0xa3:
    opHeaderAndFlags[0] = opHeaderWord;
    resultType = (unsigned char *)(**(code **)(*(int *)this + 0x3c))
                                 (this,carriedR4,parseOperand2,strayArg4,strayArg5,operatorCode,operatorCode * 4,r10In0);
    resultAndR4Pair = TPPStreamCompiler__newTemporary(compiler,resultType);
    operatorCode = *(uint *)(this + 0x30);
    opHeaderWord = opHeaderAndFlags[0];
    break;
  case 0x25:
    resultAndR4Pair = CONCAT44(childOperands[childCount + -1],carriedR4);
  }
  opHeaderAndFlags[0] = opHeaderWord;
  resultOperand[0] = (unsigned char *)((ulonglong)resultAndR4Pair >> 0x20);
  if ((((resultOperand[0] != (unsigned char *)0x0) && (operatorCode != 3)) && (*(int *)resultOperand[0] != 0)) &&
     (operandTypeObj = *(int **)(*(int *)resultOperand[0] + 0xc), operandTypeObj != (int *)0x0)) {
    typeKindCode = (**(code **)(*operandTypeObj + 0x24))(operandTypeObj,(int)resultAndR4Pair,parseOperand2,strayArg4,strayArg5,operatorCode);
    resultAndR4Pair = CONCAT44(resultOperand[0],r4Out4);
    if (typeKindCode == 0xd) {
      *(undefined4 *)(compiler + 0xa4) = 1;
    }
    operatorCode = *(uint *)(this + 0x30);
  }
  resultOperand[0] = (unsigned char *)((ulonglong)resultAndR4Pair >> 0x20);
  if (0xa3 < operatorCode) {
switchD_97bc03dc_caseD_0:
    TType__getCompleteString(&stackType,this + 8);
    terminalChar = *DAT_a7b7bd04;
    *(byte *)(stackTypeArraySize + *(int *)(stackTypeArraySize - 0xc)) = terminalChar;
    TPPStreamCompiler__error
              (compiler,(char *)0x1,(char *)0x0,
               "TIntermAggregate::compileNode- unhandle operation %s at %d\n",stackTypeArraySize,
               *(undefined4 *)(this + 4),(uint)terminalChar,r10In0);
    refCountPtr = (int *)(stackTypeArraySize - 4);
    destroyAllocatorArg[0] = stackType;
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        newRefCount = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = newRefCount;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(stackTypeArraySize - 0xc),destroyAllocatorArg);
    }
    goto switchD_97bc03dc_caseD_25;
  }
  operatorTimes4 = operatorCode * 4;
  switch(operatorCode) {
  default:
    goto switchD_97bc03dc_caseD_0;
  case 1:
    *(int *)(compiler + 0x98) = *(int *)(compiler + 0x98) + -1;
    break;
  case 2:
    paramOperandArray = 0;
    childOperandCopies = (unsigned char **)0x0;
    if (hasChildren) {
      paramOperandArray = _malloc(childCount << 2);
      childOperandCopies = (unsigned char **)_malloc(childCount << 2);
      resultAndR4Pair = CONCAT44(resultOperand[0],r4Out12);
    }
    terminalCharPtr = DAT_a7b7bd04;
    resultOperand[0] = (unsigned char *)((ulonglong)resultAndR4Pair >> 0x20);
    paramSetupIndex = 0;
    childCursor = *(undefined4 **)(this + 0x38);
    if (0 < childCount) {
      do {
        paramByteOffset = paramSetupIndex * 4;
        name4 = (**(code **)(*(int *)this + 0x6c))(this);
        terminalChar = *terminalCharPtr;
        *(byte *)(*(int *)(name4 + 4) + *(int *)(*(int *)(name4 + 4) + -0xc)) = terminalChar;
        functionNameData = *(char **)(name4 + 4);
        childTypeObj = (int *)(**(code **)(*(int *)*childCursor + 0x14))
                                   ((int *)*childCursor,r4In5,parseOperand2,strayArg4,strayArg5,operatorCode,(uint)terminalChar);
        paramType = (unsigned char *)(**(code **)(*childTypeObj + 0x3c))(childTypeObj);
        newParamOperand = TPPStreamCompiler__newParam(compiler,paramType,functionNameData,paramSetupIndex);
        *(undefined4 *)(paramByteOffset + paramOperandArray) = newParamOperand;
        if ((*(int *)(childOperands[paramSetupIndex] + 0xc) == 0) && (*(int *)(childOperands[paramSetupIndex] + 8) == 0)) {
          childOperandCopies[paramSetupIndex] = (unsigned char *)0x0;
        }
        else {
          operandCopy = operator_new(0x38);
          __ZN12ParseOperandC1ERKS_(operandCopy,childOperands[paramSetupIndex]);
          childOperandCopies[paramSetupIndex] = operandCopy;
          childOperand = childOperands[paramSetupIndex];
          if (*(int *)(childOperand + 0xc) != 0) {
            operandTemp = operator_new(0x38);
            __ZN12ParseOperandC1ERKS_(operandTemp,*(unsigned char **)(childOperands[paramSetupIndex] + 0xc));
            *(void **)(operandCopy + 0xc) = operandTemp;
            childOperand = childOperands[paramSetupIndex];
          }
          if (*(int *)(childOperand + 8) != 0) {
            childOperand = childOperandCopies[paramSetupIndex];
            operandTemp = operator_new(0x38);
            __ZN12ParseOperandC1ERKS_(operandTemp,*(unsigned char **)(childOperands[paramSetupIndex] + 8));
            *(void **)(childOperand + 8) = operandTemp;
          }
        }
        parseOperand2 = childOperands + paramSetupIndex;
        paramSetupIndex = paramSetupIndex + 1;
        strayArg4 = 0;
        TPPStreamCompiler__assignOperands(compiler,(unsigned char **)(paramOperandArray + paramByteOffset),parseOperand2,0);
        resultAndR4Pair = CONCAT44(resultOperand[0],r4Out13);
        childCursor = childCursor + 1;
      } while (paramSetupIndex < childCount);
    }
    resultOperand[0] = (unsigned char *)((ulonglong)resultAndR4Pair >> 0x20);
    opHeaderAndFlags[0] = opHeaderAndFlags[0] & 0x1c03ffff | 0x1300000;
    copyBackIndex = 0;
    labelNameObj = (**(code **)(*(int *)this + 0x6c))
                       (this,(int)resultAndR4Pair,parseOperand2,strayArg4,strayArg5,operatorCode,*(int *)this);
    terminalCharPtr = DAT_a7b7bd04;
    *(byte *)(*(int *)(labelNameObj + 4) + *(int *)(*(int *)(labelNameObj + 4) + -0xc)) = *DAT_a7b7bd04;
    opLabelLength = _strlen(*(undefined4 *)(labelNameObj + 4));
    name3 = (**(code **)(*(int *)this + 0x6c))(this);
    opHeaderOrParamSlotPtr = (unsigned char *)opHeaderAndFlags;
    carriedR4 = 0;
    *(byte *)(*(int *)(name3 + 4) + *(int *)(*(int *)(name3 + 4) + -0xc)) = *terminalCharPtr;
    functionNameData = *(char **)(name3 + 4);
    TPPStreamCompiler__AddOperation(compiler,(unsigned char **)0x0,opHeaderOrParamSlotPtr,functionNameData,0);
    if (0 < childCount) {
      do {
        isWriteableFlag = ParseOperand__isWriteable(childOperands[copyBackIndex]);
        if (isWriteableFlag != 0) {
          operandArraySel = childOperandCopies;
          if (childOperandCopies[copyBackIndex] == (unsigned char *)0x0) {
            operandArraySel = childOperands;
          }
          opHeaderOrParamSlotPtr = (unsigned char *)(paramOperandArray + copyBackIndex * 4);
          functionNameData = (char *)0x0;
          TPPStreamCompiler__assignOperands(compiler,operandArraySel + copyBackIndex,(unsigned char **)opHeaderOrParamSlotPtr,0);
        }
        operandTemp = *(void **)(copyBackIndex * 4 + paramOperandArray);
        if (operandTemp != (void *)0x0) {
          __ZN12ParseOperandD1Ev(operandTemp);
          __ZdlPv(operandTemp);
        }
        childOperand = childOperandCopies[copyBackIndex];
        if (childOperand != (unsigned char *)0x0) {
          __ZN12ParseOperandD1Ev(childOperand);
          __ZdlPv(childOperand);
        }
        copyBackIndex = copyBackIndex + 1;
      } while (copyBackIndex < childCount);
    }
    if (paramOperandArray != 0) {
      _free(paramOperandArray);
    }
    if (childOperandCopies != (unsigned char **)0x0) {
      _free(childOperandCopies);
    }
    (**(code **)(*(int *)this + 0x38))(&stackType,this);
    stackType = &PTR___ZN5TTypeD1Ev_a7b7d730;
    if ((stackTypeBits & 0x1f80000) != 0) {
      name = (**(code **)(*(int *)this + 0x6c))(this,r4In6,opHeaderOrParamSlotPtr,functionNameData,carriedR4,operatorCode,stackTypeBits & 0x1f80000)
      ;
      returnNameData = *(int *)(name + 4);
      *(byte *)(returnNameData + *(int *)(returnNameData + -0xc)) = *DAT_a7b7bd04;
      returnValueName = *(undefined4 *)(name + 4);
      nodeType = (char *)(**(code **)(*(int *)this + 0x3c))
                                 (this,r4In7,opHeaderOrParamSlotPtr,functionNameData,carriedR4,operatorCode,returnNameData,name);
      resultOperand[0] = (unsigned char *)
                    TPPStreamCompiler__newReturnValue((unsigned char *)compiler,nodeType,returnValueName);
    }
    break;
  case 3:
    functionStack = (unsigned char *)(compiler + 0x58);
    childCursor = (undefined4 *)ParseFunctionStack__getCurrentParamList(functionStack);
    childOperandCopies = (unsigned char **)ParseFunctionStack__getCurrentNumParams(functionStack);
    functionNameData = (char *)ParseFunctionStack__current(functionStack);
    functionIndex = FunctionTable__findFunction
                      (*(unsigned char **)(compiler + 0x6c),functionNameData,parseOperand2,strayArg4,strayArg5,operatorCode);
    functionFirstOp = FunctionTable__getFirstOp(*(unsigned char **)(compiler + 0x6c),functionIndex);
    if (functionFirstOp == 0) {
LAB_97bc06f4:
      functionTable = *(unsigned char **)(compiler + 0x6c);
      functionIsEmpty = 0;
    }
    else {
      lastParamOpIndex = ParseFunctionStack__getLastParamOpIndex(functionStack);
      lastOpIndexNow = TPPStreamCompiler__LastOperationIndex(compiler);
      if (lastParamOpIndex != lastOpIndexNow) goto LAB_97bc06f4;
      functionTable = *(unsigned char **)(compiler + 0x6c);
      functionIsEmpty = 1;
    }
    FunctionTable__setEmpty(functionTable,functionIndex,functionIsEmpty);
    operandArraySel = childOperandCopies;
    FunctionTable__setNumParams(*(unsigned char **)(compiler + 0x6c),functionIndex,(int)childOperandCopies);
    calleeNameObj = (**(code **)(*(int *)this + 0x6c))(this);
    *(byte *)(*(int *)(calleeNameObj + 4) + *(int *)(*(int *)(calleeNameObj + 4) + -0xc)) = *DAT_a7b7bd04;
    functionNameData = *(char **)(calleeNameObj + 4);
    lastOperation = *(int *)(*(int *)(ppStream + 0x20) + 4);
    carriedR4 = r4Out5;
    if ((lastOperation == 0) || ((*(uint *)(lastOperation + 0xc) & 0x3fc0000) != 0x1340000)) {
LAB_97bc0788:
      paramScanIndex = 0;
      if (0 < (int)childOperandCopies) {
        do {
          paramSlotPtr = (unsigned char **)(childCursor + paramScanIndex);
          if (((int *)childCursor[paramScanIndex] != (int *)0x0) &&
             ((operandTypeObj = *(int **)(*(int *)childCursor[paramScanIndex] + 0xc), callArgTypeVtable = *operandTypeObj,
              callArgTypeKind = (**(code **)(callArgTypeVtable + 0x24))(operandTypeObj,carriedR4,operandArraySel,strayArg4,strayArg5,operatorCode,callArgTypeVtable),
              callArgTypeKind == 10 ||
              (operandTypeObj = *(int **)(*(int *)childCursor[paramScanIndex] + 0xc),
              callArgTypeKind = (**(code **)(*operandTypeObj + 0x24))
                                (operandTypeObj,r4In2,operandArraySel,strayArg4,strayArg5,operatorCode,*(int *)childCursor[paramScanIndex]),
              carriedR4 = r4Out6, callArgTypeKind == 0xb)))) {
            paramTempOperand = (unsigned char *)
                       TPPStreamCompiler__newParam
                                 (compiler,*(unsigned char **)(*(int *)childCursor[paramScanIndex] + 0xc),functionNameData,paramScanIndex);
            strayArg4 = 0;
            TPPStreamCompiler__assignOperands(compiler,&paramTempOperand,paramSlotPtr,0);
            childOperand = paramTempOperand;
            carriedR4 = r4Out7;
            operandArraySel = paramSlotPtr;
            if (paramTempOperand != (unsigned char *)0x0) {
              __ZN12ParseOperandD1Ev(paramTempOperand);
              __ZdlPv(childOperand);
              carriedR4 = r4Out8;
              operandArraySel = paramSlotPtr;
            }
          }
          paramScanIndex = paramScanIndex + 1;
        } while (paramScanIndex < (int)childOperandCopies);
      }
      opHeaderAndFlags[1] = 0;
      opAuxA = (undefined **)0x0;
      opAuxB = 0;
      opDest0 = (undefined **)0x0;
      opDest1 = 0;
      opSrc0A = (undefined **)0x0;
      opSrc0B = 0;
      opSrc1A = (undefined **)0x0;
      opSrc1B = 0;
      opSrc2A = 0;
      opSrc2B = 0;
      opLabelLength = 0;
      opHeaderAndFlags[0] = 0x1340000;
      opLine = 0;
      opLine = (*(code *)**(undefined4 **)this)(this,carriedR4,operandArraySel,strayArg4,strayArg5,operatorCode,0x1340000);
      TPPStreamCompiler__AddOperation
                (compiler,(unsigned char **)0x0,(unsigned char *)opHeaderAndFlags,(char *)0x0,0);
    }
    else {
      curLastOpIndex = TPPStreamCompiler__LastOperationIndex(compiler);
      resultAndR4Pair = FunctionTable__getFirstOp(*(unsigned char **)(compiler + 0x6c),functionIndex);
      carriedR4 = (undefined4)resultAndR4Pair;
      if (curLastOpIndex < (int)((ulonglong)resultAndR4Pair >> 0x20)) goto LAB_97bc0788;
    }
    if (childCursor != (undefined4 *)0x0) {
      paramListCursor = childCursor;
      if (0 < (int)childOperandCopies) {
        do {
          operandTemp = (void *)*paramListCursor;
          if (operandTemp != (void *)0x0) {
            __ZN12ParseOperandD1Ev(operandTemp);
            __ZdlPv(operandTemp);
          }
          childOperandCopies = (unsigned char **)((int)childOperandCopies + -1);
          paramListCursor = paramListCursor + 1;
        } while (childOperandCopies != (unsigned char **)0x0);
      }
      _free(childCursor);
    }
    ParseFunctionStack__pop(functionStack);
    lastOpIndexAtEnd = TPPStreamCompiler__LastOperationIndex(compiler);
    FunctionTable__setLastOp(*(unsigned char **)(compiler + 0x6c),functionIndex,lastOpIndexAtEnd);
    break;
  case 4:
    functionStack = (unsigned char *)(compiler + 0x58);
    paramIndex = 0;
    resultAndR4Pair = ParseFunctionStack__current(functionStack);
    carriedR4 = (undefined4)resultAndR4Pair;
    if (0 < childCount) {
      do {
        if ((childOperands[paramIndex] != (unsigned char *)0x0) &&
           (((operandTypeObj = *(int **)(*(int *)childOperands[paramIndex] + 0xc), argTypeVtable = *operandTypeObj,
             argTypeKind = (**(code **)(argTypeVtable + 0x24))(operandTypeObj,carriedR4,parseOperand2,strayArg4,strayArg5,operatorCode,argTypeVtable),
             argTypeKind == 9 ||
             (operandTypeObj = *(int **)(*(int *)childOperands[paramIndex] + 0xc),
             argTypeKind = (**(code **)(*operandTypeObj + 0x24))
                                (operandTypeObj,r4In3,parseOperand2,strayArg4,strayArg5,operatorCode,*(int *)childOperands[paramIndex]),
             argTypeKind == 0xb)) ||
            (operandTypeObj = *(int **)(*(int *)childOperands[paramIndex] + 0xc),
            argTypeKind = (**(code **)(*operandTypeObj + 0x24))
                               (operandTypeObj,r4In4,parseOperand2,strayArg4,strayArg5,operatorCode,*(int *)childOperands[paramIndex]),
            carriedR4 = r4Out9, argTypeKind == 0xc)))) {
          argTempOperand = (unsigned char *)
                     TPPStreamCompiler__newParam
                               (compiler,*(unsigned char **)(*(int *)childOperands[paramIndex] + 0xc),
                                (char *)((ulonglong)resultAndR4Pair >> 0x20),paramIndex);
          parseOperand2 = &argTempOperand;
          strayArg4 = 0;
          TPPStreamCompiler__assignOperands(compiler,childOperands + paramIndex,parseOperand2,0);
          childOperand = argTempOperand;
          carriedR4 = r4Out10;
          if (argTempOperand != (unsigned char *)0x0) {
            __ZN12ParseOperandD1Ev(argTempOperand);
            __ZdlPv(childOperand);
            carriedR4 = r4Out11;
          }
        }
        paramIndex = paramIndex + 1;
      } while (paramIndex < childCount);
    }
    lastOpIndex = TPPStreamCompiler__LastOperationIndex(compiler);
    ParseFunctionStack__setLastParamOpIndex(functionStack,lastOpIndex);
    ParseFunctionStack__setCurrentParamList(functionStack,childOperands);
    ParseFunctionStack__setCurrentNumParams(functionStack,childCount);
    break;
  case 0x15:
  case 0x17:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x39:
  case 0x45:
  case 0x46:
  case 0x47:
  case 0x4a:
  case 0x4c:
  case 0x4d:
  case 0x4e:
  case 0x50:
  case 0x51:
  case 0x52:
    strayArg4 = childCount;
    __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_i
              (compiler,resultOperand,childOperands,childCount);
    if (0 < childCount) {
      srcSlotCursor = opHeaderAndFlags;
      operandsLeft = childCount;
      childOperandCopies = childOperands;
      do {
        childOperand = *childOperandCopies;
        childOperandCopies = childOperandCopies + 1;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&stackType,compiler,childOperand,strayArg4,strayArg5,operatorCode,operatorTimes4,r10In0);
        stackTypeVtable = stackType;
        operandsLeft = operandsLeft + -1;
        srcSlotCursor[5] = stackTypeArraySize;
        srcSlotCursor[4] = (uint)stackTypeVtable;
        srcSlotCursor = srcSlotCursor + 2;
      } while (operandsLeft != 0);
    }
    goto LAB_97bc11d8;
  case 0x25:
    break;
  case 0x38:
    strayArg4 = childCount;
    __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_i
              (compiler,resultOperand,childOperands,childCount);
    if (0 < childCount) {
      srcSlotCursor = opHeaderAndFlags;
      operandsLeft = childCount;
      childOperandCopies = childOperands;
      do {
        childOperand = *childOperandCopies;
        childOperandCopies = childOperandCopies + 1;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&stackType,compiler,childOperand,strayArg4,strayArg5,operatorCode,operatorTimes4,r10In0);
        stackTypeVtable = stackType;
        operandsLeft = operandsLeft + -1;
        srcSlotCursor[5] = stackTypeArraySize;
        srcSlotCursor[4] = (uint)stackTypeVtable;
        srcSlotCursor = srcSlotCursor + 2;
      } while (operandsLeft != 0);
    }
    goto LAB_97bc11d8;
  case 0x48:
  case 0x49:
    strayArg4 = childCount;
    __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_i
              (compiler,resultOperand,childOperands,childCount);
    if (0 < childCount) {
      srcSlotCursor = opHeaderAndFlags + childCount * 2;
      operandsLeft = childCount;
      childOperandCopies = childOperands;
      do {
        childOperand = *childOperandCopies;
        childOperandCopies = childOperandCopies + 1;
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&stackType,compiler,childOperand,strayArg4,strayArg5,operatorCode,operatorTimes4,r10In0);
        stackTypeVtable = stackType;
        operandsLeft = operandsLeft + -1;
        srcSlotCursor[3] = stackTypeArraySize;
        srcSlotCursor[2] = (uint)stackTypeVtable;
        srcSlotCursor = srcSlotCursor + -2;
      } while (operandsLeft != 0);
    }
    goto LAB_97bc11d8;
  case 0x66:
  case 0x67:
  case 0x68:
  case 0x69:
  case 0x6a:
  case 0x6b:
  case 0x6c:
  case 0x6d:
  case 0x6e:
  case 0x6f:
  case 0x70:
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
  case 0x75:
    constructedType = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
    resultOperand[0] = (unsigned char *)TPPStreamCompiler__construct(compiler,constructedType,childOperands,childCount);
    break;
  case 0x85:
    childCount = 2;
    opHeaderAndFlags[0] = opHeaderAndFlags[0] & 0x1fffffff | 0x40000000;
    childOperands = (unsigned char **)_malloc(8);
    childOperand = (unsigned char *)TPPStreamCompiler__getVertex(compiler);
    childOperands[1] = childOperand;
    childOperand = (unsigned char *)TPPStreamCompiler__getMVP(compiler);
    *childOperands = childOperand;
    TPPStreamCompiler__getOperandAsSourceVar
              ((unsigned char *)&stackType,compiler,childOperand,strayArg4,strayArg5,operatorCode,operatorTimes4,r10In0);
    opSrc0A = stackType;
    opSrc0B = stackTypeArraySize;
    TPPStreamCompiler__getOperandAsSourceVar
              ((unsigned char *)&stackType,compiler,childOperands[1],strayArg4,strayArg5,operatorCode,operatorTimes4,r10In0);
    opSrc1A = stackType;
    opSrc1B = stackTypeArraySize;
    goto LAB_97bc11d8;
  case 0x8a:
  case 0x8b:
  case 0x8e:
  case 0x8f:
  case 0x92:
  case 0x93:
  case 0x96:
  case 0x98:
  case 0x99:
  case 0x9a:
  case 0x9b:
    if (childCount == 3) {
      switch(operatorCode) {
      case 0x8a:
      case 0x8e:
      case 0x92:
      case 0x96:
      case 0x98:
      case 0x99:
        headerOpcode = 0x44;
        break;
      case 0x8b:
      case 0x8f:
      case 0x93:
      case 0x9a:
      case 0x9b:
        headerOpcode = 0x45;
        break;
      default:
        goto switchD_97bc03dc_caseD_8c;
      }
      opHeaderAndFlags[0] = headerOpcode << 0x12 | opHeaderAndFlags[0] & 0xfc03ffff;
    }
  case 0x8c:
  case 0x8d:
  case 0x90:
  case 0x91:
  case 0x94:
  case 0x95:
  case 0x97:
  case 0x9c:
  case 0x9d:
  case 0x9e:
  case 0x9f:
  case 0xa0:
  case 0xa1:
  case 0xa2:
  case 0xa3:
switchD_97bc03dc_caseD_8c:
    operatorOffset = operatorCode - 0x8a;
    src2SelectCode = 4;
    srcOperandOffset = operatorOffset;
    if (operatorOffset < 0x1a) {
      srcOperandOffset = operatorOffset * 4;
      switch(operatorOffset) {
      default:
        src2SelectCode = 4;
        break;
      case 4:
      case 5:
      case 6:
      case 7:
        src2SelectCode = 3;
        break;
      case 8:
      case 9:
      case 10:
      case 0xb:
        src2SelectCode = 1;
        break;
      case 0xc:
      case 0xd:
        src2SelectCode = 0;
        break;
      case 0xe:
      case 0x10:
      case 0x12:
      case 0x14:
        src2SelectCode = 7;
        break;
      case 0xf:
      case 0x11:
      case 0x13:
      case 0x15:
        src2SelectCode = 6;
        break;
      case 0x16:
      case 0x17:
        src2SelectCode = 2;
        break;
      case 0x18:
      case 0x19:
        src2SelectCode = 5;
      }
    }
    strayArg4 = childCount;
    __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_i
              (compiler,resultOperand,childOperands,childCount);
    if (hasChildren) {
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&stackType,compiler,childOperands[1],strayArg4,strayArg5,operatorCode,srcOperandOffset,r10In0);
      opSrc0A = stackType;
      opSrc0B = stackTypeArraySize;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&stackType,compiler,*childOperands,strayArg4,strayArg5,operatorCode,srcOperandOffset,r10In0);
      opSrc2A = src2SelectCode << 5 | opSrc2A & 0xffffff1f;
      opSrc1A = stackType;
      opSrc1B = stackTypeArraySize;
      if (childCount == 3) {
        TPPStreamCompiler__getOperandAsSourceVar
                  ((unsigned char *)&stackType,compiler,childOperands[2],strayArg4,strayArg5,operatorCode,opSrc2A,r10In0);
        opAuxA = stackType;
        opAuxB = stackTypeArraySize;
      }
    }
    opHeaderAndFlags[0] = (childCount + 1) * 0x20000000 | opHeaderAndFlags[0] & 0x1fffffff;
LAB_97bc11d8:
    TPPStreamCompiler__getOperandAsDestVar
              ((unsigned char *)&stackType,compiler,resultOperand[0],strayArg4,strayArg5,operatorCode);
    opDest0 = stackType;
    opDest1 = stackTypeArraySize;
    if ((*(int *)(this + 0x30) == 0x4c) || (*(int *)(this + 0x30) == 0x4d)) {
      opHeaderAndFlags[1] = ((uint)opSrc0A >> 0xe & 1) << 0x1c | opHeaderAndFlags[1] & 0xefffffff;
      firstChildTypeInfo = *(int *)*childOperands;
      if (firstChildTypeInfo == 0) {
        operandGLType = *(ushort *)(*childOperands + 0x18);
      }
      else {
        operandGLType = *(ushort *)(firstChildTypeInfo + 0x2c);
      }
      ppStreamType = GetPPStreamTypeForGLType((uint)operandGLType);
      opHeaderAndFlags[1] = (ppStreamType & 7) << 0x17 | opHeaderAndFlags[1] & 0xfc7fffff;
      childOperand = *childOperands;
    }
    else {
      opHeaderAndFlags[1] = ((uint)stackType >> 0xc & 1) << 0x1c | opHeaderAndFlags[1] & 0xefffffff;
      if (*(int *)resultOperand[0] == 0) {
        operandGLType = *(ushort *)(resultOperand[0] + 0x18);
      }
      else {
        operandGLType = *(ushort *)(*(int *)resultOperand[0] + 0x2c);
      }
      ppStreamType = GetPPStreamTypeForGLType((uint)operandGLType);
      opHeaderAndFlags[1] = (ppStreamType & 7) << 0x17 | opHeaderAndFlags[1] & 0xfc7fffff;
      childOperand = resultOperand[0];
    }
    logicalSize = ParseOperand__GetLogicalSize(childOperand);
    opHeaderAndFlags[1] = (logicalSize + -1) * 0x4000000 & 0xc000000U | opHeaderAndFlags[1] & 0xf3ffffff;
    TPPStreamCompiler__AddOperation(compiler,resultOperand,(unsigned char *)opHeaderAndFlags,(char *)0x0,0);
  }
switchD_97bc03dc_caseD_25:
  if (*(int *)(this + 0x30) != 4) {
    childOperandCopies = childOperands;
    if (0 < childCount) {
      do {
        childOperand = *childOperandCopies;
        if ((childOperand != (unsigned char *)0x0) && (childOperand != resultOperand[0])) {
          __ZN12ParseOperandD1Ev(childOperand);
          __ZdlPv(childOperand);
        }
        childCount = childCount + -1;
        childOperandCopies = childOperandCopies + 1;
      } while (childCount != 0);
    }
    if (childOperands != (unsigned char **)0x0) {
      _free(childOperands);
    }
  }
  return resultOperand[0];
}

/* TIntermSelection__compileNode @ 0x97bc1348 (2232 bytes) */
int TIntermSelection__compileNode(this, compiler, strayArg3, strayArg4, strayArg5, strayArg6, strayArg7, strayArg8)
  unsigned char * this;
  unsigned char * compiler;
  undefined4 strayArg3;
  undefined4 strayArg4;
  undefined4 strayArg5;
  undefined4 *strayArg6;
  undefined4 strayArg7;
  undefined4 strayArg8;
{
  undefined4 ifElseLabelLength;
  undefined4 strayZero11;
  int logicalSize;
  int *falseBlock;
  bool conditionNotConstant;
  ushort glTypeCode;
  bool foldedToDiscard;
  int *conditionConstantPtr;
  unsigned char *nodeType;
  unsigned char * conditionOperand;
  uint ppStreamType;
  int carriedR4;
  int operationCountBefore;
  undefined4 r4In0;
  int r4In1;
  int r4Out0;
  int r4Out1;
  undefined4 r4In2;
  int r4Out2;
  int r4Out3;
  int r4Out4;
  int r4Out5;
  int r4In3;
  int r4Out6;
  int r4Out7;
  char *labelId;
  undefined4 *r9In0;
  undefined4 opcodeValue;
  int ppStream;
  int conditionConstant;
  char *r5In0;
  uint conditionIsConstant;
  undefined8 lastOpIndexPair;
  char ifElseLabel [32];
  char ifEndLabel [32];
  uint opHeader;
  uint opFlags;
  undefined **opDest0;
  undefined4 opDest1;
  undefined **opSrc0A;
  undefined4 opSrc0B;
  undefined4 opSrc1A;
  undefined4 opSrc1B;
  undefined4 opSrc2A;
  undefined4 opSrc2B;
  undefined4 opAuxA;
  undefined4 opAuxB;
  uint opLine;
  uint opLabelLength;
  undefined **stackType;
  undefined4 stackTypeArraySize;
  uint stackTypeBits;
  unsigned char * resultOperand;
  unsigned char * trueOperand;
  unsigned char * falseOperand [3];
  
  labelId = *(char **)(compiler + 0x8c);
  r5In0 = "gl__IfEnd_";
  *(char **)(compiler + 0x8c) = labelId + 1;
  falseOperand[0] = (unsigned char *)0x0;
  resultOperand = (unsigned char *)0x0;
  trueOperand = (unsigned char *)0x0;
  ppStream = *(int *)(compiler + 0x70);
  _sprintf(ifElseLabel,"%s%d","gl__IfElse_",labelId);
  _sprintf(ifEndLabel,"%s%d",(int)"gl__IfEnd_",(int)labelId);
  foldedToDiscard = false;
  conditionConstant = 1;
  (**(code **)(*(int *)this + 0x38))((unsigned char *)&stackType,this);
  stackType = &PTR___ZN5TTypeD1Ev_a7b7d730;
  if ((stackTypeBits & 0x1f80000) != 0) {
    nodeType = (unsigned char *)(**(code **)(*(int *)this + 0x3c))
                                (this,r4In0,r5In0,labelId,strayArg5,strayArg6,stackTypeBits & 0x1f80000);
    resultOperand = (unsigned char *)TPPStreamCompiler__newTemporary(compiler,nodeType);
  }
  conditionOperand = (unsigned char *)
           (**(code **)(**(int **)(this + 0x30) + 0xc))(*(int **)(this + 0x30),compiler);
  ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(compiler + 0x68),conditionOperand);
  conditionConstantPtr = *(int **)(conditionOperand + 4);
  if (conditionConstantPtr != (int *)0x0) {
    conditionConstant = *conditionConstantPtr;
  }
  conditionIsConstant = (uint)(conditionConstantPtr != (int *)0x0);
  conditionNotConstant = conditionIsConstant == 0;
  carriedR4 = r4In1;
  if (conditionNotConstant) {
    opFlags = 0;
    r9In0 = *(undefined4 **)this;
    opAuxA = 0;
    opAuxB = 0;
    opDest0 = (undefined **)0x0;
    opDest1 = 0;
    opSrc0A = (undefined **)0x0;
    opSrc0B = 0;
    opSrc1A = 0;
    opSrc1B = 0;
    opSrc2A = 0;
    opSrc2B = 0;
    opHeader = 0x21540000;
    opLine = conditionIsConstant;
    opLabelLength = conditionIsConstant;
    opLine = (*(code *)*r9In0)(this,r4In1,r5In0,labelId,strayArg5,strayArg6,r9In0);
    TPPStreamCompiler__getOperandAsSourceVar
              ((unsigned char *)&stackType,compiler,conditionOperand,labelId,strayArg5,strayArg6,r9In0,strayArg8);
    opFlags = ((uint)stackType >> 0xe & 1) << 0x1c | opFlags & 0xefffffff;
    opSrc0B = stackTypeArraySize;
    opSrc0A = stackType;
    if (*(int *)conditionOperand == 0) {
      glTypeCode = *(ushort *)(conditionOperand + 0x18);
    }
    else {
      glTypeCode = *(ushort *)(*(int *)conditionOperand + 0x2c);
    }
    ppStreamType = GetPPStreamTypeForGLType((uint)glTypeCode);
    opFlags = (ppStreamType & 7) << 0x17 | opFlags & 0xfc7fffff;
    logicalSize = ParseOperand__GetLogicalSize(conditionOperand);
    opFlags = (logicalSize + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3ffffff;
    opLabelLength = _strlen(ifElseLabel);
    r5In0 = (char *)&opHeader;
    labelId = ifElseLabel;
    strayArg5 = 0;
    TPPStreamCompiler__AddOperation(compiler,(unsigned char **)0x0,(unsigned char *)r5In0,labelId,0)
    ;
    carriedR4 = r4Out0;
  }
  if ((*(int *)(this + 0x34) != 0) && ((conditionIsConstant != 1 || (conditionConstant != 0)))) {
    operationCountBefore = TPPStreamCompiler__LastOperationIndex(compiler);
    trueOperand = (unsigned char *)
               (**(code **)(**(int **)(this + 0x34) + 0xc))(*(int **)(this + 0x34),compiler);
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(compiler + 0x68),trueOperand);
    carriedR4 = r4Out1;
    if (conditionNotConstant) {
      lastOpIndexPair = TPPStreamCompiler__LastOperationIndex(compiler);
      carriedR4 = (int)lastOpIndexPair;
      if ((((int)((ulonglong)lastOpIndexPair >> 0x20) - operationCountBefore == 1) && (resultOperand == (unsigned char *)0x0)) &&
         (*(int *)(this + 0x38) == 0)) {
        carriedR4 = *(int *)(*(int *)(ppStream + 0x20) + 4);
        if ((*(uint *)(carriedR4 + 0xc) & 0x3fc0000) == 0x13c0000) {
          _PPStreamChunkListRemoveChunk(*(int *)(ppStream + 0x20),carriedR4);
          _PPStreamChunkListRemoveChunk
                    (*(int *)(ppStream + 0x20),*(undefined4 *)(*(int *)(ppStream + 0x20) + 4));
          opcodeValue = 0x4f;
          opFlags = 0;
          opAuxA = 0;
          opAuxB = 0;
          opDest0 = (undefined **)0x0;
          opDest1 = 0;
          opSrc0A = (undefined **)0x0;
          opSrc0B = 0;
          opSrc1A = 0;
          opSrc1B = 0;
          opSrc2A = 0;
          opSrc2B = 0;
          opHeader = 0x13c0000;
          opLine = conditionIsConstant;
          opLabelLength = conditionIsConstant;
          opLine = (*(code *)**(undefined4 **)this)(this,r4In2,r5In0,labelId,strayArg5,strayArg6,0x4f);
          opHeader = opHeader & 0x1fffffff | 0x20000000;
          *(undefined4 *)(conditionOperand + 0x28) = 1;
          TPPStreamCompiler__getOperandAsSourceVar
                    ((unsigned char *)&stackType,compiler,conditionOperand,labelId,strayArg5,strayArg6,opcodeValue,strayArg8
                    );
          opFlags = ((uint)stackType >> 0xe & 1) << 0x1c | opFlags & 0xefffffff;
          opSrc0B = stackTypeArraySize;
          opSrc0A = stackType;
          if (*(int *)conditionOperand == 0) {
            glTypeCode = *(ushort *)(conditionOperand + 0x18);
          }
          else {
            glTypeCode = *(ushort *)(*(int *)conditionOperand + 0x2c);
          }
          ppStreamType = GetPPStreamTypeForGLType((uint)glTypeCode);
          opFlags = (ppStreamType & 7) << 0x17 | opFlags & 0xfc7fffff;
          logicalSize = ParseOperand__GetLogicalSize(conditionOperand);
          opFlags = (logicalSize + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3ffffff;
          r5In0 = (char *)&opHeader;
          labelId = (char *)0x0;
          strayArg5 = 0;
          TPPStreamCompiler__AddOperation
                    (compiler,(unsigned char **)0x0,(unsigned char *)r5In0,(char *)0x0,0);
          foldedToDiscard = true;
          __ZN12ParseOperandD1Ev(conditionOperand);
          __ZdlPv(conditionOperand);
          carriedR4 = r4Out2;
          conditionOperand = trueOperand;
          goto LAB_97bc18ac;
        }
      }
    }
    if (conditionOperand != (unsigned char *)0x0) {
      __ZN12ParseOperandD1Ev(conditionOperand);
      __ZdlPv(conditionOperand);
      carriedR4 = r4Out3;
    }
    conditionOperand = trueOperand;
    if (resultOperand != (unsigned char *)0x0) {
      strayZero11 = 0;
      strayArg8 = 0;
      opFlags = 0;
      strayArg6 = *(undefined4 **)this;
      opAuxA = 0;
      opAuxB = 0;
      opLabelLength = 0;
      opDest0 = (undefined **)0x0;
      opDest1 = 0;
      opSrc0A = (undefined **)0x0;
      opSrc0B = 0;
      opSrc1A = 0;
      opSrc1B = 0;
      opSrc2A = 0;
      opSrc2B = 0;
      opLine = 0;
      opHeader = 0x20000000;
      opLine = (*(code *)*strayArg6)(this,carriedR4,r5In0,labelId,strayArg5,strayArg6,0,0);
      __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_
                (compiler,&resultOperand,&trueOperand);
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&stackType,compiler,resultOperand,labelId,strayArg5,strayArg6);
      opDest0 = stackType;
      opDest1 = stackTypeArraySize;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&stackType,compiler,trueOperand,labelId,strayArg5,strayArg6,strayZero11,strayArg8);
      opFlags = ((uint)opDest0 >> 0xc & 1) << 0x1c | opFlags & 0xefffffff;
      opSrc0A = stackType;
      opSrc0B = stackTypeArraySize;
      if (*(int *)resultOperand == 0) {
        glTypeCode = *(ushort *)(resultOperand + 0x18);
      }
      else {
        glTypeCode = *(ushort *)(*(int *)resultOperand + 0x2c);
      }
      ppStreamType = GetPPStreamTypeForGLType((uint)glTypeCode);
      opFlags = (ppStreamType & 7) << 0x17 | opFlags & 0xfc7fffff;
      logicalSize = ParseOperand__GetLogicalSize(resultOperand);
      opFlags = (logicalSize + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3ffffff;
      r5In0 = (char *)&opHeader;
      labelId = (char *)0x0;
      strayArg5 = 0;
      TPPStreamCompiler__AddOperation(compiler,&resultOperand,(unsigned char *)r5In0,(char *)0x0,0);
      carriedR4 = r4Out4;
      conditionOperand = trueOperand;
    }
  }
LAB_97bc18ac:
  if (conditionOperand != (unsigned char *)0x0) {
    __ZN12ParseOperandD1Ev(conditionOperand);
    __ZdlPv(conditionOperand);
    carriedR4 = r4Out5;
  }
  falseBlock = *(int **)(this + 0x38);
  if ((falseBlock != (int *)0x0) && ((conditionIsConstant != 1 || (conditionConstant != 1)))) {
    if (conditionNotConstant) {
      opFlags = 0;
      opAuxA = 0;
      opAuxB = 0;
      opDest0 = (undefined **)0x0;
      opDest1 = 0;
      opSrc0A = (undefined **)0x0;
      opSrc0B = 0;
      opSrc1A = 0;
      opSrc1B = 0;
      opSrc2A = 0;
      opSrc2B = 0;
      opHeader = 0x1600000;
      opLine = conditionIsConstant;
      opLabelLength = conditionIsConstant;
      opLine = (*(code *)**(undefined4 **)this)(this,carriedR4,r5In0,labelId,strayArg5,strayArg6,0x58);
      opLabelLength = _strlen(ifEndLabel);
      strayArg5 = 0;
      labelId = ifEndLabel;
      TPPStreamCompiler__AddOperation
                (compiler,(unsigned char **)0x0,(unsigned char *)&opHeader,ifEndLabel,0);
      r5In0 = (char *)_strlen(ifElseLabel);
      _PPStreamAddLabel(ppStream,ifElseLabel,r5In0);
      falseBlock = *(int **)(this + 0x38);
    }
    falseOperand[0] = (unsigned char *)(**(code **)(*falseBlock + 0xc))(falseBlock,compiler);
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(compiler + 0x68),falseOperand[0]);
    carriedR4 = r4In3;
    if (resultOperand != (unsigned char *)0x0) {
      opFlags = 0;
      strayZero11 = 0;
      opLine = 0;
      opLabelLength = 0;
      opAuxA = 0;
      opAuxB = 0;
      opDest0 = (undefined **)0x0;
      opDest1 = 0;
      opSrc0A = (undefined **)0x0;
      opSrc0B = 0;
      opSrc1A = 0;
      opSrc1B = 0;
      opSrc2A = 0;
      opSrc2B = 0;
      opHeader = 0;
      opLine = (*(code *)**(undefined4 **)this)(this,r4In3,r5In0,labelId,strayArg5,strayArg6,0);
      opHeader = opHeader & 0x1fffffff | 0x20000000;
      __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_
                (compiler,&resultOperand,falseOperand);
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&stackType,compiler,resultOperand,labelId,strayArg5,strayArg6);
      opDest0 = stackType;
      opDest1 = stackTypeArraySize;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&stackType,compiler,falseOperand[0],labelId,strayArg5,strayArg6,strayZero11,
                 strayArg8);
      opFlags = ((uint)opDest0 >> 0xc & 1) << 0x1c | opFlags & 0xefffffff;
      opSrc0A = stackType;
      opSrc0B = stackTypeArraySize;
      if (*(int *)resultOperand == 0) {
        glTypeCode = *(ushort *)(resultOperand + 0x18);
      }
      else {
        glTypeCode = *(ushort *)(*(int *)resultOperand + 0x2c);
      }
      ppStreamType = GetPPStreamTypeForGLType((uint)glTypeCode);
      opFlags = (ppStreamType & 7) << 0x17 | opFlags & 0xfc7fffff;
      conditionConstant = ParseOperand__GetLogicalSize(resultOperand);
      opFlags = (conditionConstant + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3ffffff;
      r5In0 = (char *)&opHeader;
      labelId = (char *)0x0;
      strayArg5 = 0;
      TPPStreamCompiler__AddOperation(compiler,&resultOperand,(unsigned char *)r5In0,(char *)0x0,0);
      carriedR4 = r4Out6;
    }
    conditionOperand = falseOperand[0];
    if (falseOperand[0] != (unsigned char *)0x0) {
      __ZN12ParseOperandD1Ev(falseOperand[0]);
      __ZdlPv(conditionOperand);
      carriedR4 = r4Out7;
    }
  }
  if ((!foldedToDiscard) && (conditionNotConstant)) {
    opFlags = 0;
    opAuxA = 0;
    opAuxB = 0;
    opDest0 = (undefined **)0x0;
    opDest1 = 0;
    opSrc0A = (undefined **)0x0;
    opSrc0B = 0;
    opSrc1A = 0;
    opSrc1B = 0;
    opSrc2A = 0;
    opSrc2B = 0;
    opHeader = 0x1640000;
    opLine = conditionIsConstant;
    opLabelLength = conditionIsConstant;
    opLine = (*(code *)**(undefined4 **)this)(this,carriedR4,r5In0,labelId,strayArg5,strayArg6,0x1640000);
    TPPStreamCompiler__AddOperation
              (compiler,(unsigned char **)0x0,(unsigned char *)&opHeader,(char *)0x0,0);
    labelId = ifElseLabel;
    if (*(int *)(this + 0x38) != 0) {
      labelId = ifEndLabel;
    }
    ifElseLabelLength = _strlen(labelId);
    labelId = ifElseLabel;
    if (*(int *)(this + 0x38) != 0) {
      labelId = ifEndLabel;
    }
    _PPStreamAddLabel(ppStream,labelId,ifElseLabelLength);
  }
  return resultOperand;
}

/* TIntermLoop__compileNode @ 0x97bc1c00 (3000 bytes) */
int TIntermLoop__compileNode(this, compiler, strayArg3, strayArg4, strayArg5, strayArg6)
  unsigned char * this;
  unsigned char * compiler;
  undefined4 strayArg3;
  undefined4 strayArg4;
  undefined4 strayArg5;
  undefined4 strayArg6;
{
  int *testNode;
  undefined4 strayZero12;
  undefined4 endLabelLength;
  char *endIfLabelArg;
  int *terminalNode;
  undefined4 strayZero4;
  undefined4 bodyLabelLength;
  undefined4 endIfLabelLength;
  int labelCursor;
  int opListTailAfter;
  int testFirst;
  int logicalSize;
  int lastLabelChunk;
  int opListTailBefore;
  ushort glTypeCode;
  int scanCursor;
  unsigned char *operandToFree;
  undefined4 startLabelLength;
  int *bodyNode;
  unsigned char *testType;
  uint ppStreamType;
  int opCursor;
  void *discardedResult;
  undefined4 r4In0;
  undefined4 r4In1;
  undefined4 r4Out0;
  undefined4 r4Out1;
  undefined4 r4In2;
  undefined4 r4In3;
  undefined4 r4Out2;
  undefined4 r4Out3;
  undefined4 r4In4;
  undefined4 r4In5;
  unsigned char * opRecordPtr;
  char *endLabelArg;
  undefined4 carriedR4;
  char *labelPrefixArg;
  undefined4 strayZero13;
  undefined4 strayZero14;
  int *operationChunkList;
  int ppStream;
  int loopId;
  undefined8 tempPair;
  char whileBodyLabel [32];
  char whileEndLabel [32];
  char whileStartLabel [32];
  char whileEndIfLabel [32];
  undefined4 opHeader;
  uint opFlags;
  uint opDest0;
  undefined4 opDest1;
  uint opSrc0A;
  undefined4 opSrc0B;
  undefined4 opSrc1A;
  undefined4 opSrc1B;
  undefined4 opSrc2A;
  undefined4 opSrc2B;
  undefined4 opAuxA;
  undefined4 opAuxB;
  int opLine;
  int opLabelLength;
  uint operandDesc;
  undefined4 operandDescB;
  unsigned char * conditionTemp;
  unsigned char * conditionOperand [6];
  
  loopId = *(int *)(compiler + 0x8c);
  labelPrefixArg = "gl__WhileEndIf_";
  ppStream = *(int *)(compiler + 0x70);
  *(int *)(compiler + 0x8c) = loopId + 1;
  conditionTemp = (unsigned char *)0x0;
  conditionOperand[0] = (unsigned char *)0x0;
  operationChunkList = *(int **)(ppStream + 0x20);
  if ((((*(int *)(compiler + 0xc4) < 2) || (*(int *)(this + 0xc) != 0)) || (*(int *)(this + 8) != 0))
     || (*(int *)(this + 0x10) != 0)) {
    _sprintf(whileBodyLabel,"%s%d","gl__WhileBody_",loopId);
    _sprintf(whileEndLabel,"%s%d","gl__WhileEnd_",loopId);
    _sprintf(whileStartLabel,"%s%d","gl__WhileStart_",loopId);
    _sprintf(whileEndIfLabel,"%s%d",(int)"gl__WhileEndIf_",loopId);
    endLabelArg = whileEndLabel;
    ParseWhileLoopStack__push((unsigned char *)(compiler + 0x5c),whileBodyLabel,whileEndLabel);
    opFlags = 0;
    opAuxA = 0;
    opAuxB = 0;
    opDest0 = 0;
    opDest1 = 0;
    opSrc0A = 0;
    opSrc0B = 0;
    opSrc1A = 0;
    opSrc1B = 0;
    opSrc2A = 0;
    opSrc2B = 0;
    opLabelLength = 0;
    opHeader = 0x1a80000;
    opLine = 0;
    opLine = (*(code *)**(undefined4 **)this)(this,r4In0,endLabelArg,loopId,strayArg5,labelPrefixArg,0x1a80000);
    opLabelLength = _strlen(whileEndLabel);
    strayZero12 = 0;
    endLabelArg = whileEndLabel;
    TPPStreamCompiler__AddOperation
              (compiler,(unsigned char **)0x0,(unsigned char *)&opHeader,whileEndLabel,0);
    opListTailBefore = 0;
    for (opCursor = *operationChunkList; opCursor != 0; opCursor = *(int *)(opCursor + 8)) {
      opListTailBefore = opCursor;
    }
    startLabelLength = _strlen(whileStartLabel);
    _PPStreamAddLabel(ppStream,whileStartLabel,startLabelLength);
    if ((*(int *)(this + 0x14) != 0) && (testNode = *(int **)(this + 0xc), testNode != (int *)0x0)) {
      conditionOperand[0] = (unsigned char *)(**(code **)(*testNode + 0xc))(testNode,compiler);
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(compiler + 0x68),conditionOperand[0]);
      testType = (unsigned char *)(**(code **)(**(int **)(this + 0xc) + 0x3c))(*(int **)(this + 0xc));
      tempPair = TPPStreamCompiler__newTemporary(compiler,testType);
      conditionTemp = (unsigned char *)((ulonglong)tempPair >> 0x20);
      strayZero13 = 0;
      strayZero14 = 0;
      opFlags = 0;
      opAuxA = 0;
      opAuxB = 0;
      opDest0 = 0;
      opDest1 = 0;
      opSrc0A = 0;
      opSrc0B = 0;
      opSrc1A = 0;
      opSrc1B = 0;
      opSrc2A = 0;
      opSrc2B = 0;
      opLabelLength = 0;
      opHeader = 0x20280000;
      opLine = 0;
      opLine = (*(code *)**(undefined4 **)this)(this,(int)tempPair,startLabelLength,endLabelArg,strayZero12,labelPrefixArg,0,0);
      __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_
                (compiler,&conditionTemp,conditionOperand);
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&operandDesc,compiler,conditionTemp,endLabelArg,strayZero12,labelPrefixArg);
      opDest0 = operandDesc;
      opDest1 = operandDescB;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&operandDesc,compiler,conditionOperand[0],endLabelArg,strayZero12,labelPrefixArg,strayZero13,strayZero14);
      opFlags = (opDest0 >> 0xc & 1) << 0x1c | opFlags & 0xefffffff;
      opSrc0A = operandDesc;
      opSrc0B = operandDescB;
      if (*(int *)conditionTemp == 0) {
        glTypeCode = *(ushort *)(conditionTemp + 0x18);
      }
      else {
        glTypeCode = *(ushort *)(*(int *)conditionTemp + 0x2c);
      }
      ppStreamType = GetPPStreamTypeForGLType((uint)glTypeCode);
      opFlags = (ppStreamType & 7) << 0x17 | opFlags & 0xfc7fffff;
      logicalSize = ParseOperand__GetLogicalSize(conditionTemp);
      opFlags = (logicalSize + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3ffffff;
      strayZero12 = 0;
      strayZero4 = 0;
      opRecordPtr = (unsigned char *)&opHeader;
      TPPStreamCompiler__AddOperation
                (compiler,&conditionTemp,(unsigned char *)&opHeader,(char *)0x0,0);
      strayZero13 = 0;
      strayZero14 = 0;
      opFlags = 0;
      opAuxA = 0;
      opAuxB = 0;
      opLabelLength = 0;
      opHeader = 0x21540000;
      opDest0 = 0;
      opDest1 = 0;
      opSrc0A = 0;
      opSrc0B = 0;
      opSrc1A = 0;
      opSrc1B = 0;
      opSrc2A = 0;
      opSrc2B = 0;
      opLine = 0;
      opLine = (*(code *)**(undefined4 **)this)(this,r4In1,opRecordPtr,strayZero12,strayZero4,labelPrefixArg,0,0);
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&operandDesc,compiler,conditionTemp,strayZero12,strayZero4,labelPrefixArg,strayZero13,strayZero14);
      opFlags = (operandDesc >> 0xe & 1) << 0x1c | opFlags & 0xefffffff;
      opSrc0B = operandDescB;
      opSrc0A = operandDesc;
      if (*(int *)conditionTemp == 0) {
        glTypeCode = *(ushort *)(conditionTemp + 0x18);
      }
      else {
        glTypeCode = *(ushort *)(*(int *)conditionTemp + 0x2c);
      }
      ppStreamType = GetPPStreamTypeForGLType((uint)glTypeCode);
      opFlags = (ppStreamType & 7) << 0x17 | opFlags & 0xfc7fffff;
      logicalSize = ParseOperand__GetLogicalSize(conditionTemp);
      opFlags = (logicalSize + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3ffffff;
      opLabelLength = _strlen(whileEndIfLabel);
      strayZero4 = 0;
      opRecordPtr = (unsigned char *)&opHeader;
      endIfLabelArg = whileEndIfLabel;
      TPPStreamCompiler__AddOperation
                (compiler,(unsigned char **)0x0,(unsigned char *)&opHeader,whileEndIfLabel,0);
      operandToFree = conditionTemp;
      carriedR4 = r4Out0;
      if (conditionTemp != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(conditionTemp);
        __ZdlPv(operandToFree);
        carriedR4 = r4Out1;
      }
      opFlags = 0;
      opHeader = 0x1500000;
      opDest0 = 0;
      opDest1 = 0;
      opSrc0A = 0;
      opSrc0B = 0;
      opSrc1A = 0;
      opSrc1B = 0;
      opSrc2A = 0;
      opSrc2B = 0;
      opAuxA = 0;
      opAuxB = 0;
      opLine = 0;
      opLabelLength = 0;
      opLine = (*(code *)**(undefined4 **)this)
                           (this,carriedR4,opRecordPtr,endIfLabelArg,strayZero4,labelPrefixArg,*(undefined4 **)this);
      opLabelLength = _strlen(whileEndLabel);
      strayZero12 = 0;
      opRecordPtr = (unsigned char *)&opHeader;
      endLabelArg = whileEndLabel;
      TPPStreamCompiler__AddOperation
                (compiler,(unsigned char **)0x0,(unsigned char *)&opHeader,whileEndLabel,0);
      opFlags = 0;
      opHeader = 0x1640000;
      opAuxA = 0;
      opAuxB = 0;
      opDest0 = 0;
      opDest1 = 0;
      opSrc0A = 0;
      opSrc0B = 0;
      opSrc1A = 0;
      opSrc1B = 0;
      opSrc2A = 0;
      opSrc2B = 0;
      opLabelLength = 0;
      opLine = 0;
      opLine = (*(code *)**(undefined4 **)this)
                           (this,r4In2,opRecordPtr,endLabelArg,strayZero12,labelPrefixArg,*(undefined4 **)this);
      endLabelArg = (char *)0x0;
      strayZero12 = 0;
      TPPStreamCompiler__AddOperation
                (compiler,(unsigned char **)0x0,(unsigned char *)&opHeader,(char *)0x0,0);
      endIfLabelLength = _strlen(whileEndIfLabel);
      _PPStreamAddLabel(ppStream,whileEndIfLabel,endIfLabelLength);
      operandToFree = conditionOperand[0];
      if (conditionOperand[0] != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(conditionOperand[0]);
        __ZdlPv(operandToFree);
      }
    }
    bodyNode = *(int **)(this + 8);
    if ((bodyNode != (int *)0x0) &&
       (discardedResult = (void *)(**(code **)(*bodyNode + 0xc))(bodyNode,compiler), discardedResult != (void *)0x0)) {
      __ZN12ParseOperandD1Ev(discardedResult);
      __ZdlPv(discardedResult);
    }
    bodyLabelLength = _strlen(whileBodyLabel);
    _PPStreamAddLabel(ppStream,whileBodyLabel,bodyLabelLength);
    terminalNode = *(int **)(this + 0x10);
    if ((terminalNode != (int *)0x0) &&
       (discardedResult = (void *)(**(code **)(*terminalNode + 0xc))(terminalNode,compiler), discardedResult != (void *)0x0)) {
      __ZN12ParseOperandD1Ev(discardedResult);
      __ZdlPv(discardedResult);
    }
    testFirst = *(int *)(this + 0x14);
    if ((testFirst == 0) && (testNode = *(int **)(this + 0xc), testNode != (int *)0x0)) {
      conditionOperand[0] = (unsigned char *)(**(code **)(*testNode + 0xc))(testNode,compiler);
      ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(compiler + 0x68),conditionOperand[0]);
      testType = (unsigned char *)(**(code **)(**(int **)(this + 0xc) + 0x3c))(*(int **)(this + 0xc));
      tempPair = TPPStreamCompiler__newTemporary(compiler,testType);
      conditionTemp = (unsigned char *)((ulonglong)tempPair >> 0x20);
      strayZero13 = 0;
      strayZero14 = 0;
      opFlags = 0;
      opAuxA = 0;
      opAuxB = 0;
      opDest0 = 0;
      opDest1 = 0;
      opSrc0A = 0;
      opSrc0B = 0;
      opSrc1A = 0;
      opSrc1B = 0;
      opSrc2A = 0;
      opSrc2B = 0;
      opHeader = 0x20280000;
      opLine = testFirst;
      opLabelLength = testFirst;
      opLine = (*(code *)**(undefined4 **)this)(this,(int)tempPair,bodyLabelLength,endLabelArg,strayZero12,labelPrefixArg,0,0);
      __ZN17TPPStreamCompiler22IndirectAddressHandlerEPP12ParseOperandS2_
                (compiler,&conditionTemp,conditionOperand);
      TPPStreamCompiler__getOperandAsDestVar
                ((unsigned char *)&operandDesc,compiler,conditionTemp,endLabelArg,strayZero12,labelPrefixArg);
      opDest0 = operandDesc;
      opDest1 = operandDescB;
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&operandDesc,compiler,conditionOperand[0],endLabelArg,strayZero12,labelPrefixArg,strayZero13,strayZero14);
      opFlags = (opDest0 >> 0xc & 1) << 0x1c | opFlags & 0xefffffff;
      opSrc0A = operandDesc;
      opSrc0B = operandDescB;
      if (*(int *)conditionTemp == 0) {
        glTypeCode = *(ushort *)(conditionTemp + 0x18);
      }
      else {
        glTypeCode = *(ushort *)(*(int *)conditionTemp + 0x2c);
      }
      ppStreamType = GetPPStreamTypeForGLType((uint)glTypeCode);
      opFlags = (ppStreamType & 7) << 0x17 | opFlags & 0xfc7fffff;
      logicalSize = ParseOperand__GetLogicalSize(conditionTemp);
      opFlags = (logicalSize + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3ffffff;
      strayZero12 = 0;
      strayZero4 = 0;
      opRecordPtr = (unsigned char *)&opHeader;
      TPPStreamCompiler__AddOperation
                (compiler,&conditionTemp,(unsigned char *)&opHeader,(char *)0x0,0);
      strayZero13 = 0;
      strayZero14 = 0;
      opFlags = 0;
      opAuxA = 0;
      opAuxB = 0;
      opLabelLength = 0;
      opHeader = 0x21540000;
      opDest0 = 0;
      opDest1 = 0;
      opSrc0A = 0;
      opSrc0B = 0;
      opSrc1A = 0;
      opSrc1B = 0;
      opSrc2A = 0;
      opSrc2B = 0;
      opLine = 0;
      opLine = (*(code *)**(undefined4 **)this)(this,r4In3,opRecordPtr,strayZero12,strayZero4,labelPrefixArg,0,0);
      TPPStreamCompiler__getOperandAsSourceVar
                ((unsigned char *)&operandDesc,compiler,conditionTemp,strayZero12,strayZero4,labelPrefixArg,strayZero13,strayZero14);
      opFlags = (operandDesc >> 0xe & 1) << 0x1c | opFlags & 0xefffffff;
      opSrc0B = operandDescB;
      opSrc0A = operandDesc;
      if (*(int *)conditionTemp == 0) {
        glTypeCode = *(ushort *)(conditionTemp + 0x18);
      }
      else {
        glTypeCode = *(ushort *)(*(int *)conditionTemp + 0x2c);
      }
      ppStreamType = GetPPStreamTypeForGLType((uint)glTypeCode);
      opFlags = (ppStreamType & 7) << 0x17 | opFlags & 0xfc7fffff;
      logicalSize = ParseOperand__GetLogicalSize(conditionTemp);
      opFlags = (logicalSize + -1) * 0x4000000 & 0xc000000U | opFlags & 0xf3ffffff;
      opLabelLength = _strlen(whileEndIfLabel);
      strayZero4 = 0;
      opRecordPtr = (unsigned char *)&opHeader;
      endIfLabelArg = whileEndIfLabel;
      TPPStreamCompiler__AddOperation
                (compiler,(unsigned char **)0x0,(unsigned char *)&opHeader,whileEndIfLabel,0);
      operandToFree = conditionTemp;
      carriedR4 = r4Out2;
      if (conditionTemp != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(conditionTemp);
        __ZdlPv(operandToFree);
        carriedR4 = r4Out3;
      }
      opFlags = 0;
      opHeader = 0x1500000;
      opDest0 = 0;
      opDest1 = 0;
      opSrc0A = 0;
      opSrc0B = 0;
      opSrc1A = 0;
      opSrc1B = 0;
      opSrc2A = 0;
      opSrc2B = 0;
      opAuxA = 0;
      opAuxB = 0;
      opLine = 0;
      opLabelLength = 0;
      opLine = (*(code *)**(undefined4 **)this)
                           (this,carriedR4,opRecordPtr,endIfLabelArg,strayZero4,labelPrefixArg,*(undefined4 **)this);
      opLabelLength = _strlen(whileEndLabel);
      strayZero12 = 0;
      opRecordPtr = (unsigned char *)&opHeader;
      endLabelArg = whileEndLabel;
      TPPStreamCompiler__AddOperation
                (compiler,(unsigned char **)0x0,(unsigned char *)&opHeader,whileEndLabel,0);
      opFlags = 0;
      opHeader = 0x1640000;
      opAuxA = 0;
      opAuxB = 0;
      opDest0 = 0;
      opDest1 = 0;
      opSrc0A = 0;
      opSrc0B = 0;
      opSrc1A = 0;
      opSrc1B = 0;
      opSrc2A = 0;
      opSrc2B = 0;
      opLabelLength = 0;
      opLine = 0;
      opLine = (*(code *)**(undefined4 **)this)
                           (this,r4In4,opRecordPtr,endLabelArg,strayZero12,labelPrefixArg,*(undefined4 **)this);
      endLabelArg = (char *)0x0;
      strayZero12 = 0;
      TPPStreamCompiler__AddOperation
                (compiler,(unsigned char **)0x0,(unsigned char *)&opHeader,(char *)0x0,0);
      bodyLabelLength = _strlen(whileEndIfLabel);
      _PPStreamAddLabel(ppStream,whileEndIfLabel,bodyLabelLength);
      operandToFree = conditionOperand[0];
      if (conditionOperand[0] != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(conditionOperand[0]);
        __ZdlPv(operandToFree);
      }
    }
    ParseWhileLoopStack__pop((unsigned char *)(compiler + 0x5c));
    opListTailAfter = 0;
    for (scanCursor = opListTailBefore; scanCursor != 0; scanCursor = *(int *)(scanCursor + 8)) {
      opListTailAfter = scanCursor;
    }
    if ((*(int *)(compiler + 0xc4) < 2) || (opListTailAfter != opListTailBefore)) {
      opFlags = 0;
      opAuxA = 0;
      opAuxB = 0;
      opDest0 = 0;
      opDest1 = 0;
      opSrc0A = 0;
      opSrc0B = 0;
      opSrc1A = 0;
      opSrc1B = 0;
      opSrc2A = 0;
      opSrc2B = 0;
      opLabelLength = 0;
      opHeader = 0x1ac0000;
      opLine = 0;
      opLine = (*(code *)**(undefined4 **)this)
                           (this,r4In5,bodyLabelLength,endLabelArg,strayZero12,labelPrefixArg,0x1ac0000,*(undefined4 **)this);
      opLabelLength = _strlen(whileStartLabel);
      TPPStreamCompiler__AddOperation
                (compiler,(unsigned char **)0x0,(unsigned char *)&opHeader,whileStartLabel,0);
      endLabelLength = _strlen(whileEndLabel);
      _PPStreamAddLabel(ppStream,whileEndLabel,endLabelLength);
    }
    else {
      _PPStreamChunkListRemoveChunk(operationChunkList,opListTailAfter);
      lastLabelChunk = 0;
      for (labelCursor = **(int **)(ppStream + 0x24); labelCursor != 0; labelCursor = *(int *)(labelCursor + 8)) {
        lastLabelChunk = labelCursor;
      }
      _PPStreamChunkListRemoveChunk(*(int **)(ppStream + 0x24),lastLabelChunk);
    }
  }
  return 0;
}

/* TIntermBranch__compileNode @ 0x97bc27b8 (1420 bytes) */
int TIntermBranch__compileNode(this, compiler, strayArg3, strayArg4, strayArg5, strayArg6)
  unsigned char * this;
  unsigned char * compiler;
  unsigned char ** strayArg3;
  undefined4 strayArg4;
  undefined4 strayArg5;
  undefined4 strayArg6;
{
  int *paramTypeObj;
  undefined4 continueLabel;
  undefined4 breakLabel;
  int paramTypeVtable;
  ushort returnGLType;
  int paramByteOffset;
  unsigned char *operandToFree;
  int branchKind;
  undefined4 carriedR4;
  int paramList;
  undefined4 r4Out0;
  undefined4 r4Out1;
  undefined4 r4In0;
  undefined4 r4Out2;
  undefined4 r4Out3;
  undefined4 r4Out4;
  char *labelText;
  int *returnExprNode;
  int paramTypeKind;
  int paramIndex;
  unsigned char ** paramSlot;
  unsigned char * functionStack;
  undefined8 paramListPair;
  uint opHeader;
  uint opFlags;
  undefined4 opDest0;
  undefined4 opDest1;
  undefined4 opSrc0A;
  undefined4 opSrc0B;
  undefined4 opSrc1A;
  undefined4 opSrc1B;
  undefined4 opSrc2A;
  undefined4 opSrc2B;
  undefined4 opAuxA;
  undefined4 opAuxB;
  undefined4 opLine;
  undefined4 opLabelLength;
  undefined4 operandDesc;
  undefined4 operandDescB;
  undefined **stackType;
  undefined4 stackTypeArraySize;
  undefined4 stackTypeStructure;
  undefined4 stackTypeFieldName;
  undefined4 stackTypeTypeName;
  undefined4 stackTypeWord14;
  undefined4 stackTypeStructureSize;
  undefined4 stackTypeWord1c;
  undefined4 stackTypeWord20;
  uint stackTypeBits;
  undefined4 minusOne;
  unsigned char * paramOperand;
  unsigned char * returnSlot;
  unsigned char * returnValueOperand;
  
  returnValueOperand = (unsigned char *)0x0;
  opHeader = 0;
  opFlags = 0;
  opDest0 = 0;
  opDest1 = 0;
  opSrc0A = 0;
  opSrc0B = 0;
  opSrc1A = 0;
  opSrc1B = 0;
  opSrc2A = 0;
  opSrc2B = 0;
  opAuxA = 0;
  opAuxB = 0;
  opLine = 0;
  opLabelLength = 0;
  opLine = (*(code *)**(undefined4 **)this)(this,compiler,strayArg3,strayArg4,strayArg5,strayArg6);
  returnExprNode = *(int **)(this + 0xc);
  opHeader = opHeader & 0x1fffffff;
  carriedR4 = r4Out0;
  if (returnExprNode != (int *)0x0) {
    returnValueOperand = (unsigned char *)
               (**(code **)(*returnExprNode + 0xc))(returnExprNode,compiler,strayArg3,strayArg4,strayArg5,strayArg6,returnExprNode);
    ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(compiler + 0x68),returnValueOperand);
    carriedR4 = r4Out1;
  }
  branchKind = *(int *)(this + 8);
  if (branchKind == 99) {
    functionStack = (unsigned char *)(compiler + 0x58);
    paramIndex = 0;
    labelText = (char *)ParseFunctionStack__current(functionStack);
    branchKind = ParseFunctionStack__getCurrentNumParams(functionStack);
    paramListPair = ParseFunctionStack__getCurrentParamList(functionStack);
    paramList = (int)((ulonglong)paramListPair >> 0x20);
    carriedR4 = (undefined4)paramListPair;
    opHeader = opHeader & 0xfc03ffff;
    if (0 < branchKind) {
      do {
        paramByteOffset = paramIndex * 4;
        paramSlot = (unsigned char **)(paramByteOffset + paramList);
        if ((*(int **)(paramByteOffset + paramList) != (int *)0x0) &&
           ((paramTypeObj = *(int **)(**(int **)(paramByteOffset + paramList) + 0xc), paramTypeVtable = *paramTypeObj,
            paramTypeKind = (**(code **)(paramTypeVtable + 0x24))(paramTypeObj,carriedR4,strayArg3,strayArg4,strayArg5,strayArg6,paramTypeVtable),
            paramTypeKind == 10 ||
            (paramTypeObj = *(int **)(**(int **)(paramByteOffset + paramList) + 0xc),
            paramTypeKind = (**(code **)(*paramTypeObj + 0x24))
                              (paramTypeObj,r4In0,strayArg3,strayArg4,strayArg5,strayArg6,**(int **)(paramByteOffset + paramList)),
            carriedR4 = r4Out2, paramTypeKind == 0xb)))) {
          paramOperand = (unsigned char *)
                     TPPStreamCompiler__newParam
                               (compiler,*(unsigned char **)(**(int **)(paramByteOffset + paramList) + 0xc),labelText,paramIndex);
          strayArg4 = 0;
          TPPStreamCompiler__assignOperands(compiler,&paramOperand,paramSlot,0);
          operandToFree = paramOperand;
          carriedR4 = r4Out3;
          strayArg3 = paramSlot;
          if (paramOperand != (unsigned char *)0x0) {
            __ZN12ParseOperandD1Ev(paramOperand);
            __ZdlPv(operandToFree);
            carriedR4 = r4Out4;
            strayArg3 = paramSlot;
          }
        }
        paramIndex = paramIndex + 1;
      } while (paramIndex < branchKind);
    }
    if (returnValueOperand != (unsigned char *)0x0) {
      if (*(int *)(returnValueOperand + 4) == 0) {
        returnSlot = (unsigned char *)
                   TPPStreamCompiler__newReturnValue
                             ((unsigned char *)compiler,*(char **)(*(int *)returnValueOperand + 0xc),labelText);
      }
      else {
        branchKind = 0;
        if (*(int *)returnValueOperand == 0) {
          returnGLType = *(ushort *)(returnValueOperand + 0x18);
        }
        else {
          returnGLType = *(ushort *)(*(int *)returnValueOperand + 0x2c);
        }
        if (returnGLType == 0x1406) {
          branchKind = 1;
        }
        else if (returnGLType < 0x1407) {
          if (returnGLType == 0x1404) {
            branchKind = 2;
          }
        }
        else if (returnGLType == 0x8b56) {
          branchKind = 3;
        }
        stackTypeBits = branchKind << 0x13 | stackTypeBits & 0x9ff | 0x800;
        stackType = &PTR___ZN5TTypeD1Ev_a7b7d730;
        stackTypeArraySize = 0;
        stackTypeStructure = 0;
        stackTypeFieldName = 0;
        stackTypeTypeName = 0;
        stackTypeWord14 = 0;
        stackTypeStructureSize = 0;
        stackTypeWord1c = 0;
        stackTypeWord20 = 0;
        returnSlot = (unsigned char *)
                   TPPStreamCompiler__newReturnValue((unsigned char *)compiler,(char *)&stackType,labelText);
        stackType = &PTR___ZN5TTypeD1Ev_a7b7d730;
      }
      TPPStreamCompiler__assignOperands(compiler,&returnSlot,&returnValueOperand,0);
      operandToFree = returnValueOperand;
      if (returnValueOperand != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(returnValueOperand);
        __ZdlPv(operandToFree);
      }
      operandToFree = returnSlot;
      if (returnSlot != (unsigned char *)0x0) {
        __ZN12ParseOperandD1Ev(returnSlot);
        __ZdlPv(operandToFree);
      }
    }
    opFlags = 0;
    labelText = (char *)0x0;
    opAuxA = 0;
    opAuxB = 0;
    opLabelLength = 0;
    opHeader = 0x1340000;
    opDest0 = 0;
    opDest1 = 0;
    opSrc0A = 0;
    opSrc0B = 0;
    opSrc1A = 0;
    opSrc1B = 0;
    opSrc2A = 0;
    opSrc2B = 0;
    opLine = 0;
  }
  else if (branchKind < 100) {
    if (branchKind != 0x62) {
      return 0;
    }
    opFlags = 0;
    opAuxA = 0;
    opAuxB = 0;
    opHeader = 0x13c0000;
    opDest0 = 0;
    opDest1 = 0;
    opSrc0A = 0;
    opSrc0B = 0;
    opSrc1A = 0;
    opSrc1B = 0;
    opSrc2A = 0;
    opSrc2B = 0;
    opLabelLength = 0;
    opLine = 0;
    opLine = (*(code *)**(undefined4 **)this)
                         (this,carriedR4,strayArg3,strayArg4,strayArg5,strayArg6,*(undefined4 **)this);
    opHeader = opHeader & 0x1fffffff | 0x20000000;
    minusOne = 0xbf800000;
    TPPStreamCompiler__getConstantAsSourceVar
              ((unsigned char *)&operandDesc,(uint)compiler,&minusOne,1,0x1406);
    opFlags = opFlags & 0xfc7fffff | 0x800000;
    labelText = (char *)0x0;
    opSrc0A = operandDesc;
    opSrc0B = operandDescB;
  }
  else if (branchKind == 100) {
    opFlags = 0;
    opHeader = 0x1500000;
    opAuxA = 0;
    opAuxB = 0;
    opDest0 = 0;
    opDest1 = 0;
    opSrc0A = 0;
    opSrc0B = 0;
    opSrc1A = 0;
    opSrc1B = 0;
    opSrc2A = 0;
    opSrc2B = 0;
    opLabelLength = 0;
    opLine = 0;
    opLine = (*(code *)**(undefined4 **)this)
                         (this,carriedR4,strayArg3,strayArg4,strayArg5,strayArg6,*(undefined4 **)this);
    breakLabel = ParseWhileLoopStack__breakLabel((unsigned char *)(compiler + 0x5c));
    opLabelLength = _strlen(breakLabel);
    labelText = (char *)ParseWhileLoopStack__breakLabel((unsigned char *)(compiler + 0x5c));
  }
  else {
    if (branchKind != 0x65) {
      return 0;
    }
    opFlags = 0;
    opHeader = 0x1a40000;
    opAuxA = 0;
    opAuxB = 0;
    opDest0 = 0;
    opDest1 = 0;
    opSrc0A = 0;
    opSrc0B = 0;
    opSrc1A = 0;
    opSrc1B = 0;
    opSrc2A = 0;
    opSrc2B = 0;
    opLabelLength = 0;
    opLine = 0;
    opLine = (*(code *)**(undefined4 **)this)
                         (this,carriedR4,strayArg3,strayArg4,strayArg5,strayArg6,*(undefined4 **)this);
    continueLabel = ParseWhileLoopStack__continueLabel((unsigned char *)(compiler + 0x5c));
    opLabelLength = _strlen(continueLabel);
    labelText = (char *)ParseWhileLoopStack__continueLabel((unsigned char *)(compiler + 0x5c));
  }
  TPPStreamCompiler__AddOperation
            (compiler,(unsigned char **)0x0,(unsigned char *)&opHeader,labelText,0);
  return 0;
}

/* TIntermSymbol__indirectNode @ 0x97bc2d44 (312 bytes) */
int TIntermSymbol__indirectNode(this, pPStreamCompiler, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * pPStreamCompiler;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 typePointer;
  undefined4 id;
  undefined1 *puVar1;
  int symbol;
  undefined4 uVar3;
  unsigned char * this_00;
  unsigned char * pTVar4;
  undefined4 r4In0;
  int r9In0;
  undefined4 *this_01;
  
  this_01 = (undefined4 *)0x0;
  symbol = (**(code **)(*(int *)this + 0x60))(this,pPStreamCompiler,param_3,param_4,param_5,param_6);
  puVar1 = DAT_a7b7bd0c;
  r9In0 = *(int *)(symbol + 4);
  *(undefined1 *)(r9In0 + *(int *)(r9In0 + -0xc)) = *DAT_a7b7bd0c;
  if (**(char **)(symbol + 4) != '\0') {
    uVar3 = (*(code *)**(undefined4 **)this)(this,r4In0,param_3,param_4,param_5,param_6,r9In0);
    *(undefined4 *)(pPStreamCompiler + 0x90) = uVar3;
    this_00 = operator_new(100);
    __ZN11ParseSymbolC1Ev(this_00);
    symbol = (**(code **)(*(int *)this + 0x60))(this);
    *(undefined1 *)(*(int *)(symbol + 4) + *(int *)(*(int *)(symbol + 4) + -0xc)) = *puVar1;
    ParseSymbol__SetName(this_00,*(char **)(symbol + 4));
    id = (**(code **)(*(int *)this + 0x5c))(this);
    *(undefined4 *)(this_00 + 0x28) = id;
    pTVar4 = (unsigned char *)(**(code **)(*(int *)this + 0x3c))(this);
    ParseSymbol__SetParseTreeType(this_00,pTVar4);
    typePointer = (**(code **)(*(int *)this + 0x3c))(this);
    *(undefined4 *)(this_00 + 0x10) = typePointer;
    this_01 = operator_new(0x38);
    __ZN12ParseOperandC1Ev(this_01);
    *this_01 = this_00;
  }
  return this_01;
}

/* TIntermConstantUnion__indirectNode @ 0x97bc2e7c (340 bytes) */
int TIntermConstantUnion__indirectNode(this, pPStreamCompiler, param_3, param_4, param_5, param_6, param_7, param_8)
  unsigned char * this;
  unsigned char * pPStreamCompiler;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int iVar1;
  uint uVar2;
  undefined2 uVar3;
  void *this_00;
  undefined4 uVar4;
  undefined **local_50 [9];
  uint local_2c;
  
  this_00 = operator_new(0x38);
  __ZN12ParseOperandC1Ev(this_00);
  uVar4 = (*(code *)**(undefined4 **)this)(this);
  *(undefined4 *)(pPStreamCompiler + 0x90) = uVar4;
  (**(code **)(*(int *)this + 0x38))(local_50,this);
  if ((local_2c & 0x400) == 0) {
    iVar1 = (int)(local_2c << 0xd | local_2c >> 0x13) >> 0x18;
  }
  else {
    iVar1 = (int)(local_2c << 0xd | local_2c >> 0x13) >> 0x18;
    iVar1 = iVar1 * iVar1;
  }
  *(int *)((int)this_00 + 0x24) = iVar1;
  local_50[0] = &PTR___ZN5TTypeD1Ev_a7b7d778;
  *(undefined4 *)((int)this_00 + 4) = *(undefined4 *)(this + 0x30);
  (**(code **)(*(int *)this + 0x38))(local_50,this);
  local_50[0] = &PTR___ZN5TTypeD1Ev_a7b7d778;
  uVar2 = local_2c >> 0x13 & 0x3f;
  if (uVar2 == 2) {
    uVar3 = 0x1404;
LAB_97bc2f80:
    *(undefined2 *)((int)this_00 + 0x18) = uVar3;
  }
  else {
    if (uVar2 < 3) {
      if (uVar2 == 1) {
        uVar3 = 0x1406;
        goto LAB_97bc2f80;
      }
    }
    else {
      if (uVar2 == 3) {
        uVar3 = 0x8b56;
        goto LAB_97bc2f80;
      }
      if (uVar2 == 0xe) {
        TPPStreamCompiler__error
                  (pPStreamCompiler,(char *)0x1,(char *)0x0,
                   "TIntermConstantUnion::indirectNode: EbtStruct constant union type, investigate",
                   param_5,param_6,param_7,param_8);
      }
    }
    TPPStreamCompiler__error
              (pPStreamCompiler,(char *)0x1,(char *)0x0,
               "TIntermConstantUnion::indirectNode: Unexpected constant union type",param_5,param_6,
               param_7,param_8);
  }
  return this_00;
}

/* TIntermBinary__indirectNode @ 0x97bc2fd0 (1000 bytes) */
int TIntermBinary__indirectNode(this, pPStreamCompiler, strayArg3, strayArg4, strayArg5, strayArg6, strayArg7, strayArg8)
  unsigned char * this;
  unsigned char * pPStreamCompiler;
  undefined4 strayArg3;
  undefined4 strayArg4;
  undefined4 strayArg5;
  undefined4 strayArg6;
  undefined4 strayArg7;
  undefined4 strayArg8;
{
  uint fieldIndex;
  int fieldByteOffset;
  int typeQueryResult;
  int *fieldType;
  int *right;
  int *left;
  int isArrayResult;
  bool leftIsNull;
  int binaryOp;
  undefined4 sourceLine;
  int *leftChildType;
  unsigned char *leftSymbol;
  unsigned char *leftNodeType;
  unsigned char *resultOperand;
  unsigned char *symbolTable;
  int fieldName;
  uint *rightConstData;
  void *rightOperand;
  unsigned char *leftOperand;
  uint constIndex;
  undefined **typeOrIndexBuf [2];
  int typeStructFields;
  undefined **stackType;
  uint stackTypeArraySize;
  
  leftOperand = (unsigned char *)0x0;
  rightOperand = (void *)0x0;
  sourceLine = (*(code *)**(undefined4 **)this)(this);
  *(undefined4 *)(pPStreamCompiler + 0x90) = sourceLine;
  left = *(int **)(this + 0x34);
  if (left != (int *)0x0) {
    leftOperand = (unsigned char *)(**(code **)(*left + 0x10))(left,pPStreamCompiler);
  }
  right = *(int **)(this + 0x38);
  if (right != (int *)0x0) {
    rightOperand = (void *)(**(code **)(*right + 0x10))(right,pPStreamCompiler);
  }
  leftIsNull = leftOperand == (unsigned char *)0x0;
  resultOperand = (unsigned char *)0x0;
  if (leftIsNull) goto LAB_97bc3364;
  binaryOp = *(int *)(this + 0x30);
  if (binaryOp == 0x2d) {
    constIndex = **(uint **)((int)rightOperand + 4);
    resultOperand = leftOperand;
    if (*(int *)(*(unsigned char **)leftOperand + 0x4c) == 0) goto LAB_97bc3364;
    ParseSymbol__AddDirectIndex(*(unsigned char **)leftOperand,constIndex);
    _sprintf((char *)typeOrIndexBuf,"[%d]",constIndex);
    ParseSymbol__CatName(*(unsigned char **)leftOperand,(char *)typeOrIndexBuf);
    isArrayResult = (**(code **)(*(int *)this + 0x54))(this);
    if (isArrayResult != 0) {
      TPPStreamCompiler__error
                (pPStreamCompiler,(char *)0x1,(char *)0x0,
                 "TIntermBinary::: Array index results in another array, this is not handled",
                 strayArg5,strayArg6,strayArg7,strayArg8);
      goto LAB_97bc3364;
    }
    leftSymbol = *(unsigned char **)leftOperand;
    *(undefined4 *)(leftSymbol + 0x48) = 1;
  }
  else {
    if (binaryOp == 0x2e) {
      if (*(int *)leftOperand == 0) {
        leftNodeType = (unsigned char *)(**(code **)(**(int **)(this + 0x34) + 0x3c))(*(int **)(this + 0x34));
        resultOperand = (unsigned char *)
                 TPPStreamCompiler__newIndirectOperandFromConstant(pPStreamCompiler,leftOperand,leftNodeType);
        __ZN12ParseOperandD1Ev(leftOperand);
        __ZdlPv(leftOperand);
        leftIsNull = resultOperand == (unsigned char *)0x0;
        leftOperand = resultOperand;
      }
      else {
        if (*(int *)(*(int *)leftOperand + 0x4c) == 0) {
          leftChildType = (int *)(**(code **)(**(int **)(this + 0x34) + 0x3c))(*(int **)(this + 0x34));
          typeQueryResult = (**(code **)(*leftChildType + 0x34))(leftChildType);
          resultOperand = leftOperand;
          if (typeQueryResult == 0) goto LAB_97bc3364;
          symbolTable = *(unsigned char **)(pPStreamCompiler + 0x68);
          *(undefined4 *)(pPStreamCompiler + 0xa8) = 1;
        }
        else {
          (**(code **)(**(int **)(this + 0x34) + 0x38))(&stackType,*(int **)(this + 0x34));
          *(undefined4 *)(pPStreamCompiler + 0xa8) = 1;
          stackType = &PTR___ZN5TTypeD1Ev_a7b7d778;
          ((int (*)())ParseSymbolTable__processOperand)(*(unsigned char **)(pPStreamCompiler + 0x68),leftOperand);
          ParseSymbol__AddDirectIndex(*(unsigned char **)leftOperand,stackTypeArraySize);
          _sprintf((char *)typeOrIndexBuf,"[%d]",0);
          ParseSymbol__CatName(*(unsigned char **)leftOperand,(char *)typeOrIndexBuf);
          isArrayResult = (**(code **)(*(int *)this + 0x54))(this);
          if (isArrayResult == 0) {
            leftSymbol = *(unsigned char **)leftOperand;
            *(undefined4 *)(leftSymbol + 0x48) = 1;
            ParseSymbol__ResolveOpenGLType(leftSymbol);
          }
          symbolTable = *(unsigned char **)(pPStreamCompiler + 0x68);
        }
        ((int (*)())ParseSymbolTable__processOperand)(symbolTable,leftOperand);
        resultOperand = leftOperand;
      }
      goto LAB_97bc3364;
    }
    if (binaryOp != 0x2f) goto LAB_97bc3364;
    leftSymbol = *(unsigned char **)leftOperand;
    (**(code **)(**(int **)(this + 0x34) + 0x38))(typeOrIndexBuf,*(int **)(this + 0x34));
    typeOrIndexBuf[0] = &PTR___ZN5TTypeD1Ev_a7b7d778;
    rightConstData = *(uint **)((int)rightOperand + 4);
    fieldIndex = *rightConstData;
    if (leftSymbol == (unsigned char *)0x0) {
      TPPStreamCompiler__error
                (pPStreamCompiler,(char *)0x1,(char *)0x0,
                 "TIntermBinary::indirectNode: Structure symbol, parse error.",strayArg5,strayArg6,
                 rightConstData,strayArg8);
    }
    if (typeStructFields == 0) {
      TPPStreamCompiler__error
                (pPStreamCompiler,(char *)0x1,(char *)0x0,
                 "TIntermBinary::indirectNode: No structure fields, parse error.",strayArg5,strayArg6,
                 rightConstData,strayArg8);
    }
    if ((uint)(*(int *)(typeStructFields + 8) - *(int *)(typeStructFields + 4) >> 3) <= fieldIndex) {
      TPPStreamCompiler__error
                (pPStreamCompiler,(char *)0x1,(char *)0x0,
                 "TIntermBinary::indirectNode: Structure index too big for field size, parse error",
                 strayArg5,strayArg6,rightConstData,strayArg8);
    }
    fieldByteOffset = fieldIndex * 8;
    ParseSymbol__CatName(leftSymbol,".");
    fieldType = *(int **)(*(int *)(typeStructFields + 4) + fieldByteOffset);
    fieldName = (**(code **)(*fieldType + 0x1c))(fieldType);
    *(undefined1 *)(*(int *)(fieldName + 4) + *(int *)(*(int *)(fieldName + 4) + -0xc)) = *DAT_a7b7bd0c;
    ParseSymbol__CatName(leftSymbol,*(char **)(fieldName + 4));
    ParseSymbol__SetParseTreeType(leftSymbol,*(unsigned char **)(*(int *)(typeStructFields + 4) + fieldByteOffset));
    leftSymbol = *(unsigned char **)leftOperand;
    *(undefined4 *)(leftSymbol + 0x48) = 0;
  }
  ParseSymbol__ResolveOpenGLType(leftSymbol);
  resultOperand = leftOperand;
LAB_97bc3364:
  if (rightOperand != (void *)0x0) {
    __ZN12ParseOperandD1Ev(rightOperand);
    __ZdlPv(rightOperand);
  }
  if ((!leftIsNull) && (resultOperand != leftOperand)) {
    __ZN12ParseOperandD1Ev(leftOperand);
    __ZdlPv(leftOperand);
  }
  return resultOperand;
}

/* TIntermUnary__indirectNode @ 0x97bc33b8 (112 bytes) */
int TIntermUnary__indirectNode(this, pPStreamCompiler, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * pPStreamCompiler;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 uVar1;
  void *this_00;
  
  uVar1 = (*(code *)**(undefined4 **)this)(this,pPStreamCompiler,param_3,param_4,param_5,param_6);
  *(undefined4 *)(pPStreamCompiler + 0x90) = uVar1;
  this_00 = (void *)(**(code **)(**(int **)(this + 0x34) + 0x10))(*(int **)(this + 0x34),pPStreamCompiler);
  if (this_00 != (void *)0x0) {
    __ZN12ParseOperandD1Ev(this_00);
    __ZdlPv(this_00);
  }
  return 0;
}

/* TIntermAggregate__indirectNode @ 0x97bc3428 (232 bytes) */
int TIntermAggregate__indirectNode(this, pPStreamCompiler, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * pPStreamCompiler;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  undefined4 uVar1;
  undefined4 *allocation;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  void *this_00;
  
  iVar3 = *(int *)(this + 0x3c) - *(int *)(this + 0x38) >> 2;
  uVar1 = (*(code *)**(undefined4 **)this)(this,pPStreamCompiler,param_3,param_4,param_5,param_6,this + 0x34)
  ;
  *(undefined4 *)(pPStreamCompiler + 0x90) = uVar1;
  allocation = (undefined4 *)_malloc(iVar3 << 2);
  puVar4 = allocation;
  for (puVar5 = *(undefined4 **)(this + 0x38); puVar5 != *(undefined4 **)(this + 0x3c);
      puVar5 = puVar5 + 1) {
    uVar1 = (**(code **)(*(int *)*puVar5 + 0x10))((int *)*puVar5,pPStreamCompiler);
    *puVar4 = uVar1;
    puVar4 = puVar4 + 1;
  }
  puVar4 = allocation;
  if (0 < iVar3) {
    do {
      this_00 = (void *)*puVar4;
      if (this_00 != (void *)0x0) {
        __ZN12ParseOperandD1Ev(this_00);
        __ZdlPv(this_00);
      }
      iVar3 = iVar3 + -1;
      puVar4 = puVar4 + 1;
    } while (iVar3 != 0);
  }
  if (allocation != (undefined4 *)0x0) {
    _free(allocation);
  }
  return 0;
}

/* TIntermSelection__indirectNode @ 0x97bc3510 (204 bytes) */
int TIntermSelection__indirectNode(this, pPStreamCompiler)
  unsigned char * this;
  unsigned char * pPStreamCompiler;
{
  int *falseBlock;
  void *pvVar1;
  int *piVar2;
  
  piVar2 = (int *)0x0;
  if (*(int *)(this + 0x34) != 0) {
    pvVar1 = (void *)(**(code **)(**(int **)(this + 0x30) + 0x10))(*(int **)(this + 0x30));
    if (pvVar1 != (void *)0x0) {
      __ZN12ParseOperandD1Ev(pvVar1);
      __ZdlPv(pvVar1);
    }
    piVar2 = *(int **)(this + 0x34);
  }
  if (piVar2 != (int *)0x0) {
    pvVar1 = (void *)(**(code **)(*piVar2 + 0x10))(piVar2,pPStreamCompiler);
    if (pvVar1 != (void *)0x0) {
      __ZN12ParseOperandD1Ev(pvVar1);
      __ZdlPv(pvVar1);
    }
  }
  falseBlock = *(int **)(this + 0x38);
  if ((falseBlock != (int *)0x0) &&
     (pvVar1 = (void *)(**(code **)(*falseBlock + 0x10))(falseBlock,pPStreamCompiler), pvVar1 != (void *)0x0)) {
    __ZN12ParseOperandD1Ev(pvVar1);
    __ZdlPv(pvVar1);
  }
  return 0;
}

/* TIntermLoop__indirectNode @ 0x97bc35dc (200 bytes) */
int TIntermLoop__indirectNode(this, pPStreamCompiler)
  unsigned char * this;
  unsigned char * pPStreamCompiler;
{
  int *piVar1;
  void *pvVar2;
  
  piVar1 = *(int **)(this + 0xc);
  if (piVar1 != (int *)0x0) {
    pvVar2 = (void *)(**(code **)(*piVar1 + 0x10))(piVar1);
    if (pvVar2 != (void *)0x0) {
      __ZN12ParseOperandD1Ev(pvVar2);
      __ZdlPv(pvVar2);
    }
  }
  piVar1 = *(int **)(this + 8);
  if (piVar1 != (int *)0x0) {
    pvVar2 = (void *)(**(code **)(*piVar1 + 0x10))(piVar1,pPStreamCompiler);
    if (pvVar2 != (void *)0x0) {
      __ZN12ParseOperandD1Ev(pvVar2);
      __ZdlPv(pvVar2);
    }
  }
  piVar1 = *(int **)(this + 0x10);
  if ((piVar1 != (int *)0x0) &&
     (pvVar2 = (void *)(**(code **)(*piVar1 + 0x10))(piVar1,pPStreamCompiler), pvVar2 != (void *)0x0)) {
    __ZN12ParseOperandD1Ev(pvVar2);
    __ZdlPv(pvVar2);
  }
  return 0;
}

/* TIntermBranch__indirectNode @ 0x97bc36a4 (88 bytes) */
int TIntermBranch__indirectNode(param_1)
  unsigned char * param_1;
{
  int *r3In0;
  void *this;
  
  r3In0 = *(int **)(param_1 + 0xc);
  if ((r3In0 != (int *)0x0) && (this = (void *)(**(code **)(*r3In0 + 0x10))(r3In0), this != (void *)0x0)) {
    __ZN12ParseOperandD1Ev(this);
    __ZdlPv(this);
  }
  return 0;
}

/* __ZN22ConstantAllocationListC2Ev @ 0x97bc36fc (4 bytes) */
int __ZN22ConstantAllocationListC2Ev(this)
  void *this;
{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* __ZN22ConstantAllocationListC1Ev @ 0x97bc3700 (4 bytes) */
int __ZN22ConstantAllocationListC1Ev(this)
  void *this;
{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* __ZN22ConstantAllocationListC4Ev @ 0x97bc3704 (16 bytes) */
int __ZN22ConstantAllocationListC4Ev(this)
  void *this;
{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* __ZN22ConstantAllocationListD2Ev @ 0x97bc3714 (8 bytes) */
int __ZN22ConstantAllocationListD2Ev(this)
  void *this;
{
  return ((int (*)())__ZN22ConstantAllocationListD4Ev)(this);
}

/* __ZN22ConstantAllocationListD1Ev @ 0x97bc371c (8 bytes) */
int __ZN22ConstantAllocationListD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN22ConstantAllocationListD4Ev)(this);
}

/* __ZN22ConstantAllocationListD4Ev @ 0x97bc3724 (16 bytes) */
int __ZN22ConstantAllocationListD4Ev(this)
  void *this;
{
  if (*(int *)this == 0) {
    return;
  }
  return _free(*(int *)this);
}

/* ConstantAllocationList__clear @ 0x97bc3734 (68 bytes) */
int ConstantAllocationList__clear(this)
  unsigned char * this;
{
  if (*(int *)this != 0) {
    _free(*(int *)this);
  }
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* ConstantAllocationList__addConstant @ 0x97bc3778 (320 bytes) */
int ConstantAllocationList__addConstant(this, constantId, values, glType)
  unsigned char * this;
  int constantId;
  bool *values;
  int glType;
{
  int valueDst;
  int loopIndex;
  int newEntries;
  bool *valueSrc;
  int newEntry;
  int valueByteOffset;
  int oldEntries;
  int wordsLeft;
  int entryOffset;
  undefined4 entryWord3;
  undefined4 entryWord1;
  undefined4 entryWord2;
  int oldEntry;
  uint count;
  
  count = *(uint *)(this + 4);
  if ((count & 0xf) == 0) {
    newEntries = _malloc(count * 0x18 + 0x180);
    _memset(newEntries,0,*(int *)(this + 4) * 0x18 + 0x180);
    count = *(uint *)(this + 4);
    loopIndex = 0;
    if ((int)count < 1) {
      oldEntries = *(int *)this;
    }
    else {
      oldEntries = *(int *)this;
      entryOffset = 0;
      do {
        oldEntry = entryOffset + oldEntries;
        entryWord1 = *(undefined4 *)(oldEntry + 4);
        loopIndex = loopIndex + 1;
        entryWord2 = *(undefined4 *)(oldEntry + 8);
        newEntry = entryOffset + newEntries;
        entryWord3 = *(undefined4 *)(oldEntry + 0xc);
        *(undefined4 *)(entryOffset + newEntries) = *(undefined4 *)(entryOffset + oldEntries);
        entryOffset = entryOffset + 0x18;
        *(undefined4 *)(newEntry + 4) = entryWord1;
        *(undefined4 *)(newEntry + 8) = entryWord2;
        *(undefined4 *)(newEntry + 0xc) = entryWord3;
        entryWord3 = *(undefined4 *)(oldEntry + 0x10);
        *(undefined4 *)(newEntry + 0x14) = *(undefined4 *)(oldEntry + 0x14);
        *(undefined4 *)(newEntry + 0x10) = entryWord3;
      } while (loopIndex < (int)count);
    }
    if (oldEntries != 0) {
      _free(oldEntries);
      count = *(uint *)(this + 4);
    }
    *(int *)this = newEntries;
  }
  valueByteOffset = 0;
  *(int *)(count * 0x18 + *(int *)this) = constantId;
  wordsLeft = 4;
  *(ushort *)(*(int *)(this + 4) * 0x18 + *(int *)this + 0x14) = glType;
  do {
    valueSrc = values + valueByteOffset;
    valueDst = valueByteOffset + *(int *)(this + 4) * 0x18 + *(int *)this;
    valueByteOffset = valueByteOffset + 4;
    *(undefined4 *)(valueDst + 4) = *(undefined4 *)valueSrc;
    wordsLeft = wordsLeft + -1;
  } while (wordsLeft != 0);
  *(int *)(this + 4) = *(int *)(this + 4) + 1;
  return;
}

/* ConstantAllocationList__updateConstant @ 0x97bc38b8 (128 bytes) */
int ConstantAllocationList__updateConstant(this, param_2, param_3, param_4)
  unsigned char * this;
  int param_2;
  bool *param_3;
  uint param_4;
{
  int loopIndex2;
  int iVar1;
  int iVar2;
  int loopIndex;
  int *piVar4;
  int iVar5;
  
  iVar5 = *(int *)(this + 4);
  loopIndex = 0;
  if (0 < iVar5) {
    piVar4 = *(int **)this;
    do {
      iVar2 = *piVar4;
      piVar4 = piVar4 + 6;
      if (param_2 == iVar2) break;
      loopIndex = loopIndex + 1;
    } while (loopIndex < iVar5);
  }
  if (iVar5 <= loopIndex) {
    return;
  }
  iVar5 = *(int *)this;
  loopIndex2 = 0;
  if (*(ushort *)(loopIndex * 0x18 + iVar5 + 0x14) == param_4) {
    while( true ) {
      iVar1 = loopIndex2 * 4;
      loopIndex2 = loopIndex2 + 1;
      *(undefined4 *)(iVar1 + loopIndex * 0x18 + iVar5 + 4) = *(undefined4 *)(param_3 + iVar1);
      if (3 < loopIndex2) break;
      iVar5 = *(int *)this;
    }
    return;
  }
  return;
}

/* ConstantAllocationList__getConstantUsage @ 0x97bc3938 (132 bytes) */
int ConstantAllocationList__getConstantUsage(this, param_2, param_3, param_4)
  unsigned char * this;
  int param_2;
  bool *param_3;
  ushort *param_4;
{
  int iVar1;
  int loopIndex;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = *(int *)(this + 4);
  loopIndex = 0;
  if (0 < iVar5) {
    piVar3 = *(int **)this;
    do {
      iVar1 = *piVar3;
      piVar3 = piVar3 + 6;
      if (param_2 == iVar1) break;
      loopIndex = loopIndex + 1;
    } while (loopIndex < iVar5);
  }
  uVar4 = 0;
  if (loopIndex < iVar5) {
    iVar5 = 0;
    iVar1 = 4;
    *param_4 = *(ushort *)(loopIndex * 0x18 + *(int *)this + 0x14);
    do {
      uVar4 = 1;
      *(undefined4 *)(param_3 + iVar5) = *(undefined4 *)(iVar5 + loopIndex * 0x18 + *(int *)this + 4);
      iVar5 = iVar5 + 4;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return uVar4;
}

/* newQueue @ 0x97bc39bc (20 bytes) */
int newQueue(q)
  unsigned char * q;
{
  *(undefined4 *)(q + 8) = 0;
  *(undefined4 *)q = 0;
  *(undefined4 *)(q + 4) = 0;
  return;
}

/* size @ 0x97bc39d0 (8 bytes) */
int size(q)
  unsigned char * q;
{
  return *(undefined4 *)(q + 8);
}

/* store @ 0x97bc39d8 (108 bytes) */
int store(q, param_2)
  unsigned char * q;
  void *param_2;
{
  int iVar1;
  undefined4 *allocation;
  
  allocation = (undefined4 *)_malloc(8);
  iVar1 = *(int *)(q + 8);
  *allocation = param_2;
  allocation[1] = 0;
  if (iVar1 == 0) {
    *(undefined4 **)q = allocation;
    iVar1 = 0;
  }
  else {
    *(undefined4 **)(*(int *)(q + 4) + 4) = allocation;
    iVar1 = *(int *)(q + 8);
  }
  *(undefined4 **)(q + 4) = allocation;
  *(int *)(q + 8) = iVar1 + 1;
  return;
}

