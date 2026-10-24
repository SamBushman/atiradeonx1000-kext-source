#include "decls.h"

/* _PPStreamRemoveOperation @ 0x97bf2714 (192 bytes) */
int _PPStreamRemoveOperation(stream, opChunk)
  int stream;
  int opChunk;
{
  uint removedFlagBits;
  uint nextWord0;
  uint oldTargetIndex;
  uint newTargetIndex;
  int nextChunk;
  
  nextChunk = *(int *)(opChunk + 8);
  if (nextChunk != 0) {
    nextWord0 = *(uint *)(nextChunk + 0xc);
    removedFlagBits = (*(uint *)(opChunk + 0xc) >> 0x1a & 7) << 0x1a;
    *(uint *)(nextChunk + 0xc) = removedFlagBits | nextWord0 & 0xe3ffffff;
    oldTargetIndex = *(uint *)(opChunk + 0xc) & 0x3ffff;
    if (oldTargetIndex == 0) {
      newTargetIndex = 0;
      oldTargetIndex = *(uint *)(*(int *)(opChunk + 8) + 0xc);
      *(uint *)(nextChunk + 0xc) = removedFlagBits | nextWord0 & 0xe3fc0000;
      oldTargetIndex = oldTargetIndex & 0x3ffff;
    }
    else {
      newTargetIndex = nextWord0 & 0x3ffff;
    }
    _renumberLabels(**(undefined4 **)(stream + 0x24),oldTargetIndex,newTargetIndex,0);
    _renumberTargets(**(undefined4 **)(stream + 0x20),oldTargetIndex,newTargetIndex,0);
  }
  _PPStreamChunkListRemoveChunk(*(undefined4 *)(stream + 0x20),opChunk);
  return nextChunk;
}

/* _adjustAllocation_97bf27d4 @ 0x97bf27d4 (124 bytes) */
int _adjustAllocation_97bf27d4(capacityPtr, bufferPtr, cursorPtr)
  int *capacityPtr;
  int *bufferPtr;
  int *cursorPtr;
{
  int allocation;
  int oldBuffer;
  int newCapacity;
  int oldCursor;
  
  oldBuffer = *bufferPtr;
  oldCursor = *cursorPtr;
  if (*capacityPtr - (oldCursor - oldBuffer) < 0x800) {
    newCapacity = *capacityPtr + 0x1000;
    *capacityPtr = newCapacity;
    allocation = _realloc(*bufferPtr,newCapacity);
    *cursorPtr = allocation;
    if (allocation == 0) {
      return 0;
    }
    *bufferPtr = allocation;
    *cursorPtr = allocation + (oldCursor - oldBuffer);
  }
  return 1;
}

/* _ncpy_97bf2850 @ 0x97bf2850 (144 bytes) */
int _ncpy_97bf2850(out, value)
  char *out;
  int value;
{
  int leadingValue;
  char *writeCursor [4];
  
  writeCursor[0] = out;
  if (value < 0) {
    writeCursor[0] = out + 1;
    *out = '-';
    value = -value;
  }
  leadingValue = value / 10;
  if (leadingValue != 0) {
    ((int (*)())_handleDigit_97c05b70)(writeCursor,leadingValue);
  }
  *writeCursor[0] = (char)value + (char)leadingValue * -10 + '0';
  return writeCursor[0] + (1 - (int)out);
}

/* _glpSourceSign @ 0x97bf28e0 (180 bytes) */
int _glpSourceSign(operands, out, operandIndex, invert)
  int operands;
  int out;
  int operandIndex;
  uint invert;
{
  char ch;
  int copyIndex;
  
  if ((invert & 1) == 0) {
    if ((*(uint *)(operands + operandIndex * 8) & 0x8000000) == 0) {
      return out;
    }
    copyIndex = 0;
    ch = s___97c2a2d4[0];
    while (ch != '\0') {
      *(char *)(out + copyIndex) = ch;
      ch = "-"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
  }
  else {
    if ((*(uint *)(operands + operandIndex * 8) & 0x8000000) != 0) {
      return out;
    }
    copyIndex = 0;
    ch = s___97c2a2d4[0];
    while (ch != '\0') {
      *(char *)(out + copyIndex) = ch;
      ch = "-"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
  }
  return out + copyIndex;
}

/* _glpSourceType @ 0x97bf2994 (1080 bytes) */
int _glpSourceType(operands, out, paramNumberMap, paramArrayMap, operandIndex, rowOffset, printFlags)
  int operands;
  int out;
  int paramNumberMap;
  int paramArrayMap;
  int operandIndex;
  uint rowOffset;
  uint printFlags;
{
  uint addressComponent;
  int copyIndex2;
  int copyEnd2;
  int copyEnd;
  int copyEnd3;
  char ch;
  uint registerFile;
  int textCursor;
  int bracketCursor;
  int copyIndex;
  int operandByteOffset;
  
  if ((printFlags & 0x10) != 0) {
    if (rowOffset == 1) {
      rowOffset = *(uint *)(operands + 8) >> 6 & 3;
    }
    else if ((int)rowOffset < 2) {
      if (rowOffset == 0) {
        rowOffset = *(uint *)(operands + 8) >> 8 & 3;
      }
    }
    else if (rowOffset == 2) {
      rowOffset = *(uint *)(operands + 8) >> 4 & 3;
    }
    else if (rowOffset == 3) {
      rowOffset = *(uint *)(operands + 8) >> 2 & 3;
    }
  }
  operandByteOffset = operandIndex * 8;
  registerFile = *(uint *)(operandByteOffset + operands) >> 0x17 & 7;
  if (registerFile == 1) {
    copyIndex = 0;
    ch = s_tmp_97c2d76c[0];
    while (ch != '\0') {
      *(char *)(out + copyIndex) = ch;
      ch = "tmp"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
LAB_97bf2d98:
    copyEnd2 = ((int (*)())_ncpy_97bf2850)(out + copyIndex,*(ushort *)(operandByteOffset + operands + 6) + rowOffset);
    return out + copyIndex + copyEnd2;
  }
  if (registerFile < 2) {
    if (registerFile != 0) {
      return out;
    }
    copyIndex = 0;
    ch = s_att_97c2d7e4[0];
    while (ch != '\0') {
      *(char *)(out + copyIndex) = ch;
      ch = "att"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    goto LAB_97bf2d98;
  }
  if (registerFile != 2) {
    if (registerFile != 3) {
      return out;
    }
    copyIndex = 0;
    ch = s_res_97c2d774[0];
    while (ch != '\0') {
      *(char *)(out + copyIndex) = ch;
      ch = "res"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    goto LAB_97bf2d98;
  }
  copyIndex = 0;
  ch = s_prm_97c2d7e8[0];
  while (ch != '\0') {
    *(char *)(out + copyIndex) = ch;
    ch = "prm"[copyIndex + 1];
    copyIndex = copyIndex + 1;
  }
  copyEnd3 = ((int (*)())_ncpy_97bf2850)(out + copyIndex,
                         *(int *)(paramNumberMap + (uint)*(ushort *)(operandByteOffset + operands + 6) * 4) + rowOffset);
  textCursor = out + copyIndex + copyEnd3;
  if (-1 < *(int *)(operandByteOffset + operands)) {
    if (*(int *)(paramArrayMap + (uint)*(ushort *)(operandByteOffset + operands + 6) * 4) == -1) {
      return textCursor;
    }
    copyIndex = 0;
    ch = s___97c29860[0];
    while (ch != '\0') {
      *(char *)(textCursor + copyIndex) = ch;
      ch = "["[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyEnd = ((int (*)())_ncpy_97bf2850)(textCursor + copyIndex,
                           *(undefined4 *)(paramArrayMap + (uint)*(ushort *)(operandByteOffset + operands + 6) * 4));
    bracketCursor = textCursor + copyIndex + copyEnd;
    copyIndex2 = 0;
    ch = s___97c2d770[0];
    while (ch != '\0') {
      *(char *)(bracketCursor + copyIndex2) = ch;
      ch = "]"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    goto LAB_97bf2d5c;
  }
  copyIndex = 0;
  ch = s__adr_97c2d778[0];
  while (ch != '\0') {
    *(char *)(textCursor + copyIndex) = ch;
    ch = "[adr"[copyIndex + 1];
    copyIndex = copyIndex + 1;
  }
  copyEnd = ((int (*)())_ncpy_97bf2850)(textCursor + copyIndex,*(uint *)(operandByteOffset + operands) >> 0x1e & 1);
  bracketCursor = textCursor + copyIndex + copyEnd;
  addressComponent = *(uint *)(operandByteOffset + operands) >> 0x1c & 3;
  if (addressComponent == 1) {
    copyIndex2 = 0;
    ch = s__y_97c2d784[0];
    while (ch != '\0') {
      *(char *)(bracketCursor + copyIndex2) = ch;
      ch = ".y"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
LAB_97bf2c84:
    bracketCursor = bracketCursor + copyIndex2;
  }
  else {
    if (1 < addressComponent) {
      if (addressComponent == 2) {
        copyIndex2 = 0;
        ch = s__z_97c2d788[0];
        while (ch != '\0') {
          *(char *)(bracketCursor + copyIndex2) = ch;
          ch = ".z"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
      }
      else {
        if (addressComponent != 3) goto LAB_97bf2c88;
        copyIndex2 = 0;
        ch = s__w_97c2d78c[0];
        while (ch != '\0') {
          *(char *)(bracketCursor + copyIndex2) = ch;
          ch = ".w"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
      }
      goto LAB_97bf2c84;
    }
    if (addressComponent == 0) {
      copyIndex2 = 0;
      ch = s__x_97c2d780[0];
      while (ch != '\0') {
        *(char *)(bracketCursor + copyIndex2) = ch;
        ch = ".x"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      goto LAB_97bf2c84;
    }
  }
LAB_97bf2c88:
  copyIndex2 = 0;
  ch = s___97c2d770[0];
  while (ch != '\0') {
    *(char *)(bracketCursor + copyIndex2) = ch;
    ch = "]"[copyIndex2 + 1];
    copyIndex2 = copyIndex2 + 1;
  }
LAB_97bf2d5c:
  return bracketCursor + copyIndex2;
}

/* _glpSourceComponents @ 0x97bf2dcc (504 bytes) */
int _glpSourceComponents(inst, out, operandIndex, destSelector, printFlags)
  int inst;
  char *out;
  int operandIndex;
  uint destSelector;
  uint printFlags;
{
  int componentCount;
  int copyIndex;
  char ch;
  uint bitShift;
  int copyIndex2;
  uint destSwizzle;
  uint shiftAmount;
  char *textCursor;
  uint sourceSwizzle;
  uint finalSwizzle;
  uint nibbleShift;
  int componentsLeft;
  
  sourceSwizzle = 0x3210;
  if ((printFlags & 0x40) == 0) {
    sourceSwizzle = *(uint *)(inst + operandIndex * 8);
    sourceSwizzle = sourceSwizzle >> 3 & 0x3000 | sourceSwizzle >> 9 & 0x300 | sourceSwizzle >> 0xf & 0x30 | sourceSwizzle >> 0x15 & 3;
  }
  finalSwizzle = sourceSwizzle;
  if ((printFlags & 0xc) != 0) {
    destSwizzle = destSelector;
    if ((printFlags & 4) == 0) {
      destSwizzle = *(uint *)(inst + 8);
      destSwizzle = (destSwizzle & 0xc) << 10 | (destSwizzle & 0x30) << 4 | destSwizzle >> 2 & 0x30 | destSwizzle >> 8 & 3;
    }
    if (destSwizzle != 0x3210) {
      componentsLeft = 4;
      nibbleShift = 0;
      finalSwizzle = 0;
      do {
        bitShift = nibbleShift & 0x3f;
        shiftAmount = (destSwizzle & 3) * 4 - nibbleShift;
        if ((int)shiftAmount < 1) {
          shiftAmount = sourceSwizzle << (-shiftAmount & 0x3f);
        }
        else {
          shiftAmount = (int)sourceSwizzle >> (shiftAmount & 0x3f);
        }
        nibbleShift = nibbleShift + 4;
        finalSwizzle = finalSwizzle | shiftAmount & 3 << bitShift;
        destSwizzle = (int)destSwizzle >> 4;
        componentsLeft = componentsLeft + -1;
      } while (componentsLeft != 0);
    }
  }
  if ((printFlags & 2) == 0) {
    componentCount = 4;
    if ((*(uint *)(inst + operandIndex * 8) & 0x3000) == 0) {
      componentCount = 1;
    }
    if (finalSwizzle != 0x3210) {
      copyIndex2 = 0;
      ch = s___97c2a130[0];
      while (ch != '\0') {
        out[copyIndex2] = ch;
        ch = "."[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      out = out + copyIndex2;
      for (; componentCount != 0; componentCount = componentCount + -1) {
        ch = (char)finalSwizzle;
        finalSwizzle = (int)finalSwizzle >> 4;
        *out = (ch + 1U & 3) + 0x77;
        out = out + 1;
      }
    }
  }
  else {
    copyIndex = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      out[copyIndex] = ch;
      ch = "."[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    textCursor = out + copyIndex;
    if (destSelector == 1) {
      finalSwizzle = (int)finalSwizzle >> 4;
    }
    else if ((int)destSelector < 2) {
      if (destSelector != 0) {
        return textCursor;
      }
    }
    else if (destSelector == 2) {
      finalSwizzle = (int)finalSwizzle >> 8;
    }
    else {
      if (destSelector != 3) {
        return textCursor;
      }
      finalSwizzle = (int)finalSwizzle >> 0xc;
    }
    out[copyIndex] = ((char)finalSwizzle + 1U & 3) + 0x77;
    out = textCursor + 1;
  }
  return out;
}

/* _glpWriteComponentsWithDestinationSwizzle @ 0x97bf2fc4 (244 bytes) */
int _glpWriteComponentsWithDestinationSwizzle(inst, out)
  int inst;
  char *out;
{
  int copyIndex;
  int loopIndex;
  char ch;
  uint bitShift;
  uint shiftAmount;
  char *textCursor;
  uint nibbleShift;
  uint resultSwizzle;
  uint destSwizzle;
  int componentsLeft;
  
  destSwizzle = *(uint *)(inst + 8);
  destSwizzle = (destSwizzle & 0xc) << 10 | (destSwizzle & 0x30) << 4 | destSwizzle >> 2 & 0x30 | destSwizzle >> 8 & 3;
  if (destSwizzle == 0x3210) {
    return out;
  }
  componentsLeft = 4;
  resultSwizzle = 0;
  nibbleShift = 0;
  do {
    bitShift = nibbleShift & 0x3f;
    shiftAmount = (destSwizzle & 3) * 4 - nibbleShift;
    if ((int)shiftAmount < 1) {
      shiftAmount = 0x3210 << (-shiftAmount & 0x3f);
    }
    else {
      shiftAmount = 0x3210 >> (shiftAmount & 0x3f);
    }
    nibbleShift = nibbleShift + 4;
    resultSwizzle = resultSwizzle | shiftAmount & 3 << bitShift;
    destSwizzle = (int)destSwizzle >> 4;
    componentsLeft = componentsLeft + -1;
  } while (componentsLeft != 0);
  if (resultSwizzle != 0x3210) {
    copyIndex = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      out[copyIndex] = ch;
      ch = "."[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    textCursor = out + copyIndex;
    loopIndex = 0;
    do {
      loopIndex = loopIndex + 1;
      ch = (char)resultSwizzle;
      resultSwizzle = (int)resultSwizzle >> 4;
      *textCursor = (ch + 1U & 3) + 0x77;
      textCursor = textCursor + 1;
    } while (loopIndex < 4);
    return textCursor;
  }
  return out;
}

/* _glpWriteSourceOperand_97bf30b8 @ 0x97bf30b8 (128 bytes) */
int _glpWriteSourceOperand_97bf30b8(inst, out, paramNumberMap, paramArrayMap, operandIndex, rowOffset, destSelector, printFlags)
  undefined4 inst;
  undefined4 out;
  undefined4 paramNumberMap;
  undefined4 paramArrayMap;
  undefined4 operandIndex;
  undefined4 rowOffset;
  undefined4 destSelector;
  undefined4 printFlags;
{
  undefined4 glpSourceComponentsResult;
  undefined4 glpSourceTypeResult;
  undefined4 glpSourceSignResult;
  
  glpSourceSignResult = ((int (*)())_glpSourceSign)(inst,out,operandIndex,printFlags);
  glpSourceTypeResult = ((int (*)())_glpSourceType)(inst,glpSourceSignResult,paramNumberMap,paramArrayMap,operandIndex,rowOffset,printFlags);
  glpSourceComponentsResult = ((int (*)())_glpSourceComponents)(inst,glpSourceTypeResult,operandIndex,destSelector,printFlags);
  return glpSourceComponentsResult;
}

/* _glpWriteDestinationMask @ 0x97bf3138 (1312 bytes) */
int _glpWriteDestinationMask(inst, out, maskStyle, printFlags)
  int inst;
  int out;
  int maskStyle;
  uint printFlags;
{
  int copyIndex2;
  int copyIndex;
  uint maskWord;
  char ch;
  int copyLength;
  int copyIndex3;
  int writeCursor;
  
  if ((printFlags & 2) == 0) {
    maskWord = *(uint *)(inst + 8);
    if ((maskWord & 0x1e000) == 0x1e000) {
      return out;
    }
    writeCursor = 0;
    copyIndex3 = writeCursor;
    ch = s___97c2a130[0];
    if (s___97c2a130[0] != '\0') {
      do {
        *(char *)(out + copyIndex3) = ch;
        writeCursor = copyIndex3 + 1;
        ch = "."[copyIndex3 + 1];
        copyIndex3 = writeCursor;
      } while (ch != '\0');
      maskWord = *(uint *)(inst + 8);
    }
    writeCursor = out + writeCursor;
    if ((maskWord & 0x2000) != 0) {
      copyLength = 0;
      copyIndex3 = copyLength;
      ch = s_x_97c2d790[0];
      if (s_x_97c2d790[0] != '\0') {
        do {
          *(char *)(writeCursor + copyIndex3) = ch;
          copyLength = copyIndex3 + 1;
          ch = "x"[copyIndex3 + 1];
          copyIndex3 = copyLength;
        } while (ch != '\0');
        maskWord = *(uint *)(inst + 8);
      }
      writeCursor = writeCursor + copyLength;
    }
    if ((maskWord & 0x4000) != 0) {
      copyLength = 0;
      copyIndex3 = copyLength;
      ch = s_y_97c2d794[0];
      if (s_y_97c2d794[0] != '\0') {
        do {
          *(char *)(writeCursor + copyIndex3) = ch;
          copyLength = copyIndex3 + 1;
          ch = "y"[copyIndex3 + 1];
          copyIndex3 = copyLength;
        } while (ch != '\0');
        maskWord = *(uint *)(inst + 8);
      }
      writeCursor = writeCursor + copyLength;
    }
    if ((maskWord & 0x8000) != 0) {
      copyLength = 0;
      copyIndex3 = copyLength;
      ch = s_z_97c2d798[0];
      if (s_z_97c2d798[0] != '\0') {
        do {
          *(char *)(writeCursor + copyIndex3) = ch;
          copyLength = copyIndex3 + 1;
          ch = "z"[copyIndex3 + 1];
          copyIndex3 = copyLength;
        } while (ch != '\0');
        maskWord = *(uint *)(inst + 8);
      }
      writeCursor = writeCursor + copyLength;
    }
    if ((maskWord & 0x10000) == 0) {
      return writeCursor;
    }
    copyIndex = 0;
    ch = s_w_97c2d79c[0];
    while (ch != '\0') {
      *(char *)(writeCursor + copyIndex) = ch;
      ch = "w"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
  }
  else if (maskStyle == 1) {
    copyIndex2 = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      *(char *)(out + copyIndex2) = ch;
      ch = "."[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    maskWord = *(uint *)(inst + 8);
    writeCursor = out + copyIndex2;
    if ((maskWord & 0x4000) == 0) {
      if ((maskWord & 0x8000) == 0) {
        if ((maskWord & 0x10000) == 0) {
          return writeCursor;
        }
        copyIndex = 0;
        ch = s_w_97c2d79c[0];
        while (ch != '\0') {
          *(char *)(writeCursor + copyIndex) = ch;
          ch = "w"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else {
        copyIndex = 0;
        ch = s_z_97c2d798[0];
        while (ch != '\0') {
          *(char *)(writeCursor + copyIndex) = ch;
          ch = "z"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
    }
    else {
      copyIndex = 0;
      ch = s_y_97c2d794[0];
      while (ch != '\0') {
        *(char *)(writeCursor + copyIndex) = ch;
        ch = "y"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
  }
  else if (maskStyle < 2) {
    if (maskStyle != 0) {
      return out;
    }
    copyIndex2 = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      *(char *)(out + copyIndex2) = ch;
      ch = "."[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    maskWord = *(uint *)(inst + 8);
    writeCursor = out + copyIndex2;
    if ((maskWord & 0x2000) == 0) {
      if ((maskWord & 0x4000) == 0) {
        if ((maskWord & 0x8000) == 0) {
          if ((maskWord & 0x10000) == 0) {
            return writeCursor;
          }
          copyIndex = 0;
          ch = s_w_97c2d79c[0];
          while (ch != '\0') {
            *(char *)(writeCursor + copyIndex) = ch;
            ch = "w"[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
        }
        else {
          copyIndex = 0;
          ch = s_z_97c2d798[0];
          while (ch != '\0') {
            *(char *)(writeCursor + copyIndex) = ch;
            ch = "z"[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
        }
      }
      else {
        copyIndex = 0;
        ch = s_y_97c2d794[0];
        while (ch != '\0') {
          *(char *)(writeCursor + copyIndex) = ch;
          ch = "y"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
    }
    else {
      copyIndex = 0;
      ch = s_x_97c2d790[0];
      while (ch != '\0') {
        *(char *)(writeCursor + copyIndex) = ch;
        ch = "x"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
  }
  else if (maskStyle == 2) {
    copyIndex2 = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      *(char *)(out + copyIndex2) = ch;
      ch = "."[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    writeCursor = out + copyIndex2;
    if ((*(uint *)(inst + 8) & 0x8000) == 0) {
      if ((*(uint *)(inst + 8) & 0x10000) == 0) {
        return writeCursor;
      }
      copyIndex = 0;
      ch = s_w_97c2d79c[0];
      while (ch != '\0') {
        *(char *)(writeCursor + copyIndex) = ch;
        ch = "w"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    else {
      copyIndex = 0;
      ch = s_z_97c2d798[0];
      while (ch != '\0') {
        *(char *)(writeCursor + copyIndex) = ch;
        ch = "z"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
  }
  else {
    if (maskStyle != 3) {
      return out;
    }
    copyIndex2 = 0;
    ch = s___97c2a130[0];
    while (ch != '\0') {
      *(char *)(out + copyIndex2) = ch;
      ch = "."[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    writeCursor = out + copyIndex2;
    if ((*(uint *)(inst + 8) & 0x10000) == 0) {
      return writeCursor;
    }
    copyIndex = 0;
    ch = s_w_97c2d79c[0];
    while (ch != '\0') {
      *(char *)(writeCursor + copyIndex) = ch;
      ch = "w"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
  }
  return writeCursor + copyIndex;
}

/* _glpWriteDestinationOperand_97bf3658 @ 0x97bf3658 (348 bytes) */
int _glpWriteDestinationOperand_97bf3658(inst, out, registerOffset, maskArg, printFlags)
  int inst;
  int out;
  int registerOffset;
  undefined4 maskArg;
  uint printFlags;
{
  int copyEnd;
  char ch;
  uint registerFile;
  int copyIndex;
  undefined4 suffixEnd;
  
  registerFile = *(uint *)(inst + 8) >> 0x11 & 7;
  if (registerFile == 3) {
    copyIndex = 0;
    ch = s_res_97c2d774[0];
    while (ch != '\0') {
      *(char *)(out + copyIndex) = ch;
      ch = "res"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
  }
  else if (registerFile < 4) {
    if (registerFile != 1) goto LAB_97bf3754;
    copyIndex = 0;
    ch = s_tmp_97c2d76c[0];
    while (ch != '\0') {
      *(char *)(out + copyIndex) = ch;
      ch = "tmp"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
  }
  else {
    if (registerFile != 4) goto LAB_97bf3754;
    copyIndex = 0;
    ch = s_adr_97c2d7e0[0];
    while (ch != '\0') {
      *(char *)(out + copyIndex) = ch;
      ch = "adr"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
  }
  out = out + copyIndex;
LAB_97bf3754:
  copyEnd = ((int (*)())_ncpy_97bf2850)(out,(uint)*(ushort *)(inst + 0xe) + registerOffset);
  if ((printFlags & 0x40) == 0) {
    suffixEnd = ((int (*)())_glpWriteDestinationMask)(inst,out + copyEnd,maskArg,printFlags);
  }
  else {
    suffixEnd = ((int (*)())_glpSourceComponents)(inst,out + copyEnd,1,maskArg,printFlags);
  }
  return suffixEnd;
}

/* _glpWriteTextureOperand_97bf37b4 @ 0x97bf37b4 (760 bytes) */
int _glpWriteTextureOperand_97bf37b4(operands, out, operandIndex, unitNumberTable)
  int operands;
  int out;
  int operandIndex;
  int unitNumberTable;
{
  int copyIndex3;
  int copyIndex2;
  int copyIndex;
  char ch;
  int unitTextLength;
  int operandByteOffset;
  int unitCursor;
  int targetCursor;
  
  copyIndex = 0;
  ch = s_texture__97c2d814[0];
  while (ch != '\0') {
    *(char *)(out + copyIndex) = ch;
    ch = "texture["[copyIndex + 1];
    copyIndex = copyIndex + 1;
  }
  unitCursor = out + copyIndex;
  if (unitNumberTable == 0) {
    unitTextLength = 0;
    ch = s_0_97c2d800[0];
    while (ch != '\0') {
      *(char *)(unitCursor + unitTextLength) = ch;
      ch = "0"[unitTextLength + 1];
      unitTextLength = unitTextLength + 1;
    }
    operandByteOffset = operandIndex << 3;
  }
  else {
    operandByteOffset = operandIndex * 8;
    unitTextLength = ((int (*)())_ncpy_97bf2850)(unitCursor,*(undefined4 *)
                                  (unitNumberTable + (uint)*(ushort *)(operandByteOffset + operands + 6) * 0x10));
  }
  copyIndex2 = 0;
  ch = s____97c2d820[0];
  while (ch != '\0') {
    *(char *)(unitCursor + unitTextLength + copyIndex2) = ch;
    ch = "], "[copyIndex2 + 1];
    copyIndex2 = copyIndex2 + 1;
  }
  targetCursor = unitCursor + unitTextLength + copyIndex2;
  switch(*(uint *)(operandByteOffset + operands) >> 5 & 7) {
  case 0:
    copyIndex3 = 0;
    ch = s_CUBE_97c2d830[0];
    while (ch != '\0') {
      *(char *)(targetCursor + copyIndex3) = ch;
      ch = "CUBE"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    break;
  case 1:
    copyIndex3 = 0;
    ch = s_3D_97c2d82c[0];
    while (ch != '\0') {
      *(char *)(targetCursor + copyIndex3) = ch;
      ch = "3D"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    break;
  case 2:
    copyIndex3 = 0;
    ch = s_RECT_97c2d838[0];
    while (ch != '\0') {
      *(char *)(targetCursor + copyIndex3) = ch;
      ch = "RECT"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    break;
  case 3:
    copyIndex3 = 0;
    ch = s_2D_97c2d828[0];
    while (ch != '\0') {
      *(char *)(targetCursor + copyIndex3) = ch;
      ch = "2D"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    break;
  case 4:
    copyIndex3 = 0;
    ch = s_1D_97c2d824[0];
    while (ch != '\0') {
      *(char *)(targetCursor + copyIndex3) = ch;
      ch = "1D"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    break;
  case 5:
    copyIndex3 = 0;
    ch = s_SHADOWRECT_97c2d840[0];
    while (ch != '\0') {
      *(char *)(targetCursor + copyIndex3) = ch;
      ch = "SHADOWRECT"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    break;
  case 6:
    copyIndex3 = 0;
    ch = s_SHADOW2D_97c2d84c[0];
    while (ch != '\0') {
      *(char *)(targetCursor + copyIndex3) = ch;
      ch = "SHADOW2D"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    break;
  case 7:
    copyIndex3 = 0;
    ch = s_SHADOW1D_97c2d858[0];
    while (ch != '\0') {
      *(char *)(targetCursor + copyIndex3) = ch;
      ch = "SHADOW1D"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    break;
  default:
    goto switchD_97bf38d0_default;
  }
  targetCursor = targetCursor + copyIndex3;
switchD_97bf38d0_default:
  return targetCursor;
}

/* _glpDisassemble2Op @ 0x97bf3acc (56112 bytes) */
int _glpDisassemble2Op(inst, outText, outWordCount, outTextLength, paramNumbers, paramArrayPos, reserved7, outFlagWord, stateFlags, shaderType, optionFlags)
  uint *inst;
  int outText;
  int *outWordCount;
  int *outTextLength;
  undefined4 paramNumbers;
  undefined4 paramArrayPos;
  undefined4 reserved7;
  undefined4 outFlagWord;
  uint *stateFlags;
  int shaderType;
  undefined4 optionFlags;
{
  int copyIndex12;
  uint valueType;
  uint stateFlags1;
  uint src3SizeMinusOne;
  bool isFirstRow;
  int swizzleSelect;
  int nextComponent;
  int outLen;
  int outBase;
  int componentCount;
  int typeTextLength;
  uint writeMaskBits2;
  uint instWord2b;
  uint sourceMode2;
  uint flagWord2;
  uint opcode;
  uint flagWord;
  uint sizeMinusOne;
  uint writeMaskBits;
  uint sourceMode;
  uint instWord0;
  char *outPtr;
  int outPos;
  int opOffsetOrTailLength;
  int copyIndex9;
  int copyIndex10;
  int copyIndex11;
  int copyEnd;
  int outCursor6;
  int copyEnd2;
  int outCursor7;
  int loopIndex2;
  int loopIndex3;
  int loopIndex4;
  int loopIndex;
  int copyIndex6;
  int outCursor;
  int copyIndex3;
  int outCursor2;
  int copyIndex2;
  int outCursor4;
  int copyIndex4;
  int outCursor5;
  int copyIndex5;
  int outCursor3;
  int copyIndex;
  bool destOverlapsSource;
  undefined *opStringTable;
  char ch;
  char *mnemonic;
  int outLen2;
  int outStart;
  int swizzleSelect2;
  uint src1Word0;
  uint rowIndex;
  uint writeMaskBits3;
  int componentIndex;
  int nextComponent2;
  int swizzleSelect3;
  
  opStringTable = PTR__ppstreamOpString_a7b7c108;
  instWord0 = *inst;
  opcode = instWord0 >> 0x12 & 0xff;
  if ((int)inst[3] < 0) {
    return 0xffffffff;
  }
  if (((((instWord0 >> 0x1d != 0) && ((int)inst[4] < 0)) &&
       (((inst[4] >> 0x17 & 7) != 2 || (shaderType == 0x8b30)))) ||
      (((1 < instWord0 >> 0x1d && ((int)inst[6] < 0)) &&
       (((inst[6] >> 0x17 & 7) != 2 || (shaderType == 0x8b30)))))) ||
     ((((2 < instWord0 >> 0x1d && ((int)inst[8] < 0)) &&
       (((inst[8] >> 0x17 & 7) != 2 || (shaderType == 0x8b30)))) || (0x70 < opcode)))) {
LAB_97c017a4:
    return 0xffffffff;
  }
  opOffsetOrTailLength = opcode * 4;
  outStart = outText;
  switch(opcode) {
  case 0:
    componentCount = 1;
    if ((inst[2] & 0x1000) != 0) {
      componentCount = (inst[2] >> 10 & 3) + 1;
    }
    loopIndex3 = 0;
    if (componentCount == 0) goto LAB_97c0178c;
    do {
      copyIndex4 = 0;
      ch = s_MOV_97c2e430[0];
      while (ch != '\0') {
        *(char *)(outStart + copyIndex4) = ch;
        ch = "MOV "[copyIndex4 + 1];
        copyIndex4 = copyIndex4 + 1;
      }
      outCursor4 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outStart + copyIndex4,loopIndex3,0,0);
      copyIndex3 = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor4 + copyIndex3) = ch;
        ch = ", "[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor4 + copyIndex3,paramNumbers,paramArrayPos,2,loopIndex3,0,8);
      copyIndex4 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex4) = ch;
        ch = ";\n"[copyIndex4 + 1];
        copyIndex4 = copyIndex4 + 1;
      }
      loopIndex3 = loopIndex3 + 1;
      outStart = outCursor + copyIndex4;
    } while (loopIndex3 < componentCount);
    goto LAB_97c01788;
  default:
    goto LAB_97c017a4;
  case 2:
  case 4:
  case 5:
    copyIndex9 = 0;
    mnemonic = *(char **)(PTR__ppstreamOpString_a7b7c108 + opOffsetOrTailLength);
    ch = *mnemonic;
    while (ch != '\0') {
      *(char *)(outText + copyIndex9) = ch;
      copyIndex9 = copyIndex9 + 1;
      ch = mnemonic[copyIndex9];
    }
    copyIndex = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex9 + copyIndex) = ch;
      ch = " "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex9 + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 3:
    *stateFlags = *stateFlags | 1;
    copyIndex = 0;
    ch = s_FLR_scratch__97c2e420[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "FLR scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,9);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_MOV_97c2e430[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "MOV "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s____scratch__97c2e438[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ", -scratch;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 6:
    if ((stateFlags[1] & 0x400000) == 0) {
      return 0xffffffff;
    }
    if (shaderType != 0x8b30) {
      return 0xffffffff;
    }
    *stateFlags = *stateFlags | 0x400003;
    copyIndex = 0;
    ch = s_DDX_scratch__97c2f7fc[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "DDX scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_ABS_scratch__scratch__97c2e8c0[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "ABS scratch, scratch;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_DDY_scratch1__97c2f80c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "DDY scratch1, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_ABS_scratch1__scratch1__97c2e880[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "ABS scratch1, scratch1;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_ADD_97c2e6d4[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "ADD "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch__scratch1__97c2e4f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ", scratch, scratch1;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 7:
    if (((stateFlags[1] & 0x100000) == 0) || (shaderType != 0x8b31)) {
      *stateFlags = *stateFlags | 0x1003;
      copyIndex = 0;
      ch = s_SLT_scratch__97c2e474[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "SLT scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
      copyIndex = 0;
      ch = s___kZERO__97c2e484[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_SLT_scratch1__97c2e490[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "SLT scratch1, "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex + copyIndex2,paramNumbers,paramArrayPos,2,0,0,9);
      copyIndex = 0;
      ch = s___kZERO__97c2e484[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_SUB_97c2e934[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "SUB "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___scratch1__scratch__97c2e93c[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ", scratch1, scratch;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      *stateFlags = *stateFlags | 0x100000;
      copyIndex = 0;
      ch = s_SSG_97c2e92c[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "SSG "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
      opOffsetOrTailLength = 0;
      ch = s_____end_97c2e910[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ";\n# end\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 8:
    flagWord2 = *stateFlags;
    *stateFlags = flagWord2 | 0x2000;
    sourceMode = inst[4] >> 0xc & 3;
    if (sourceMode == 2) {
      *stateFlags = flagWord2 | 0x3001;
      copyIndex = 0;
      ch = s_DP3_scratch_x__97c2e734[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "DP3 scratch.x, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
      copyIndex = 0;
      ch = s___kONE__97c2e9b0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kONE;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
LAB_97bfb2c8:
      outBase = outCursor + copyIndex;
    }
    else {
      outBase = outText;
      if (sourceMode < 3) {
        if (sourceMode == 1) {
          *stateFlags = flagWord2 | 0x2001;
          copyIndex = 0;
          ch = s_ADD_scratch_x__97c2e960[0];
          while (ch != '\0') {
            *(char *)(outText + copyIndex) = ch;
            ch = "ADD scratch.x, "[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,2);
          copyIndex = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex) = ch;
            ch = ", "[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,2);
          copyIndex = 0;
          ch = s___97c2d8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex) = ch;
            ch = ";\n"[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          goto LAB_97bfb2c8;
        }
      }
      else if (sourceMode == 3) {
        *stateFlags = flagWord2 | 0x3001;
        copyIndex = 0;
        ch = s_DP4_scratch_x__97c2e744[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "DP4 scratch.x, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
        copyIndex = 0;
        ch = s___kONE__97c2e9b0[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", kONE;\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        goto LAB_97bfb2c8;
      }
    }
    copyIndex3 = 0;
    ch = s_SGE_97c2e91c[0];
    while (ch != '\0') {
      *(char *)(outBase + copyIndex3) = ch;
      ch = "SGE "[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outBase + copyIndex3,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch_x__kHALF__97c2e970[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ", scratch.x, kHALF;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 9:
    sourceMode2 = inst[4] >> 0xc & 3;
    if (sourceMode2 == 2) {
      *stateFlags = *stateFlags | 1;
      copyIndex = 0;
      ch = s_MUL_scratch_x__97c2e6fc[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "MUL scratch.x, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,2);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,1,2);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_MUL_97c2e4f0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "MUL "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
      copyIndex = 0;
      ch = s___scratch_x__97c2e9a0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", scratch.x, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,2,2);
      opOffsetOrTailLength = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ";\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else if (sourceMode2 < 3) {
      if (sourceMode2 != 1) goto LAB_97c0178c;
      copyIndex = 0;
      ch = s_MUL_97c2e4f0[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "MUL "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,2);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,1,2);
      opOffsetOrTailLength = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ";\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      if (sourceMode2 != 3) goto LAB_97c0178c;
      *stateFlags = *stateFlags | 1;
      copyIndex = 0;
      ch = s_MUL_scratch_xy__97c2e510[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "MUL scratch.xy, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0x3210,4)
      ;
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor6 + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor6 + copyIndex,paramNumbers,paramArrayPos,2,0,0x3232,4);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_MUL_97c2e4f0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "MUL "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___scratch_x__scratch_y__97c2e524[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ", scratch.x, scratch.y;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 10:
    *stateFlags = *stateFlags | 0x1000;
    copyIndex = 0;
    ch = s_SUB_97c2e934[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "SUB "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___kONE__97c2e954[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", kONE, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0xc:
    writeMaskBits = inst[2];
    *stateFlags = *stateFlags | 1;
    instWord2b = inst[2];
    writeMaskBits = writeMaskBits >> 0xd & 0xf;
    loopIndex = 0;
    do {
      if ((writeMaskBits & 1) != 0) {
        copyIndex2 = 0;
        ch = s_RSQ_scratch_x__97c2e57c[0];
        while (ch != '\0') {
          *(char *)(outStart + copyIndex2) = ch;
          ch = "RSQ scratch.x, "[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor7 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outStart + copyIndex2,paramNumbers,paramArrayPos,2,0,loopIndex,10)
        ;
        copyIndex3 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor7 + copyIndex3) = ch;
          ch = ";\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        copyIndex4 = 0;
        ch = s_RCP_97c2e58c[0];
        while (ch != '\0') {
          *(char *)(outCursor7 + copyIndex3 + copyIndex4) = ch;
          ch = "RCP "[copyIndex4 + 1];
          copyIndex4 = copyIndex4 + 1;
        }
        outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor7 + copyIndex3 + copyIndex4,0,loopIndex,2);
        copyIndex2 = 0;
        ch = s___scratch_x__97c2e594[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex2) = ch;
          ch = ", scratch.x;\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        instWord2b = inst[2];
        outStart = outCursor + copyIndex2;
      }
      loopIndex = loopIndex + 1;
      writeMaskBits = (int)writeMaskBits >> 1;
    } while (loopIndex <= (int)(instWord2b >> 10 & 3));
    goto LAB_97c01788;
  case 0xd:
  case 0x10:
  case 0x13:
    writeMaskBits = inst[2];
    writeMaskBits2 = writeMaskBits >> 0xd & 0xf;
    loopIndex3 = 0;
    do {
      if ((writeMaskBits2 & 1) != 0) {
        mnemonic = *(char **)(opStringTable + opOffsetOrTailLength);
        copyIndex10 = 0;
        ch = *mnemonic;
        while (ch != '\0') {
          *(char *)(outStart + copyIndex10) = ch;
          copyIndex10 = copyIndex10 + 1;
          ch = mnemonic[copyIndex10];
        }
        copyIndex5 = 0;
        ch = s__97c291c0[0];
        while (ch != '\0') {
          *(char *)(outStart + copyIndex10 + copyIndex5) = ch;
          ch = " "[copyIndex5 + 1];
          copyIndex5 = copyIndex5 + 1;
        }
        outCursor4 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outStart + copyIndex10 + copyIndex5,0,loopIndex3,2);
        copyIndex3 = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor4 + copyIndex3) = ch;
          ch = ", "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor4 + copyIndex3,paramNumbers,paramArrayPos,2,0,loopIndex3,10)
        ;
        copyIndex4 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor6 + copyIndex4) = ch;
          ch = ";\n"[copyIndex4 + 1];
          copyIndex4 = copyIndex4 + 1;
        }
        writeMaskBits = inst[2];
        outStart = outCursor6 + copyIndex4;
      }
      loopIndex3 = loopIndex3 + 1;
      writeMaskBits2 = (int)writeMaskBits2 >> 1;
    } while (loopIndex3 <= (int)(writeMaskBits >> 10 & 3));
    goto LAB_97c01788;
  case 0x12:
    *stateFlags = *stateFlags | 1;
    sourceMode = inst[4] >> 0xc & 3;
    if (sourceMode == 1) {
      copyIndex = 0;
      ch = s_SWZ_scratch__97c2e79c[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "SWZ scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      typeTextLength = ((int (*)())_glpSourceType)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0);
      copyIndex = 0;
      ch = s___x__y__0__0__97c2e7ac[0];
      while (ch != '\0') {
        *(char *)(typeTextLength + copyIndex) = ch;
        ch = ", x, y, 0, 0;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = typeTextLength + copyIndex;
      copyIndex = 0;
      ch = s_DP3_scratch_x__scratch__scratch__97c2e7bc[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "DP3 scratch.x, scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    else {
      if (sourceMode == 0) {
        copyIndex = 0;
        ch = s_MUL_scratch_x__97c2e6fc[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "MUL scratch.x, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else if (sourceMode == 2) {
        copyIndex = 0;
        ch = s_DP3_scratch_x__97c2e734[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "DP3 scratch.x, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else {
        copyIndex = 0;
        ch = s_DP4_scratch_x__97c2e744[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "DP4 scratch.x, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    copyIndex2 = 0;
    ch = s_RSQ_scratch_x__scratch_x__97c2e754[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "RSQ scratch.x, scratch.x;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_RCP_97c2e58c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "RCP "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch_x__97c2e594[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ", scratch.x;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x15:
    if ((((inst[4] >> 0xc & 3) == 3) || ((stateFlags[1] & 0x800000) == 0)) || (shaderType != 0x8b30))
    {
      *stateFlags = *stateFlags | 1;
      sizeMinusOne = inst[2] >> 10 & 3;
      if (sizeMinusOne == 0) {
        copyIndex = 0;
        ch = s_MUL_scratch_x__97c2e6fc[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "MUL scratch.x, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
        copyIndex = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ";\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else if (sizeMinusOne == 1) {
        copyIndex = 0;
        ch = s_MUL_scratch_xy__97c2e510[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "MUL scratch.xy, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
        copyIndex = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ";\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = outCursor + copyIndex;
        copyIndex = 0;
        ch = s_MUL_scratch_x__scratch_x__scratc_97c2e70c[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = "MUL scratch.x, scratch.x, scratch.y;\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else {
        if (sizeMinusOne == 2) {
          copyIndex = 0;
          ch = s_DP3_scratch_x__97c2e734[0];
          while (ch != '\0') {
            *(char *)(outText + copyIndex) = ch;
            ch = "DP3 scratch.x, "[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
        }
        else {
          copyIndex = 0;
          ch = s_DP4_scratch_x__97c2e744[0];
          while (ch != '\0') {
            *(char *)(outText + copyIndex) = ch;
            ch = "DP4 scratch.x, "[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
        copyIndex = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ";\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      copyIndex2 = 0;
      ch = s_RSQ_scratch_x__scratch_x__97c2e754[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "RSQ scratch.x, scratch.x;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_MUL_97c2e4f0[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
      opOffsetOrTailLength = 0;
      ch = s___scratch_x__97c2e594[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ", scratch.x;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      flagWord = *stateFlags;
      *stateFlags = flagWord | 0x800000;
      if ((inst[4] >> 0xc & 3) == 2) {
        copyIndex = 0;
        ch = s_NRM_97c2e6dc[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "NRM "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outBase = outText + copyIndex;
        if ((inst[2] & 0x3fc) == 0x6c) {
          outCursor3 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outBase,0,0,0);
        }
        else {
          copyIndex3 = 0;
          ch = s_scratch_97c2e63c[0];
          while (ch != '\0') {
            *(char *)(outBase + copyIndex3) = ch;
            ch = "scratch"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor3 = outBase + copyIndex3;
        }
        copyIndex3 = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor3 + copyIndex3) = ch;
          ch = ", "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor3 + copyIndex3,paramNumbers,paramArrayPos,2,0,0,0);
        copyIndex = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ";\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else {
        *stateFlags = flagWord | 0x800001;
        copyIndex = 0;
        ch = s_MUL_scratch__97c2e62c[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "MUL scratch, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor3 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
        if ((inst[4] & 0x3000) == 0) {
          *stateFlags = *stateFlags | 0x1000;
          copyIndex2 = 0;
          ch = s___kFLOAT__97c2e6e4[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex2) = ch;
            ch = ", kFLOAT;\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        else {
          *stateFlags = *stateFlags | 0x1000;
          copyIndex2 = 0;
          ch = s___kVEC2__97c2e6f0[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex2) = ch;
            ch = ", kVEC2;\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        copyIndex3 = 0;
        ch = s_NRM_97c2e6dc[0];
        while (ch != '\0') {
          *(char *)(outCursor3 + copyIndex2 + copyIndex3) = ch;
          ch = "NRM "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor = outCursor3 + copyIndex2 + copyIndex3;
        if ((inst[2] & 0x3fc) == 0x6c) {
          outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor,0,0,0);
        }
        else {
          copyIndex = 0;
          ch = s_scratch_97c2e63c[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex) = ch;
            ch = "scratch"[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          outCursor = outCursor + copyIndex;
        }
        copyIndex = 0;
        ch = s___scratch__97c2e620[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", scratch;\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      outStart = outCursor + copyIndex;
      if ((inst[2] & 0x3fc) == 0x6c) goto LAB_97c01788;
      copyIndex = 0;
      ch = s_MOV_97c2e430[0];
      while (ch != '\0') {
        *(char *)(outStart + copyIndex) = ch;
        ch = "MOV "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outStart + copyIndex,0,0,0);
      copyIndex = 0;
      ch = s___scratch_97c2e65c[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", scratch"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = ((int (*)())_glpWriteComponentsWithDestinationSwizzle)(inst,outCursor + copyIndex);
      opOffsetOrTailLength = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ";\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x16:
    copyIndex = 0;
    ch = s_MUL_97c2e4f0[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "MUL "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___0_0174532925199__97c2e9d0[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ", 0.0174532925199;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x17:
    copyIndex = 0;
    ch = s_MUL_97c2e4f0[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "MUL "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___57_295779513082__97c2e9bc[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ", 57.295779513082;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x19:
    if (shaderType == 0x8b30) {
      loopIndex = 0;
      do {
        copyIndex2 = 0;
        ch = s_SIN_97c2eb80[0];
        while (ch != '\0') {
          *(char *)(outStart + copyIndex2) = ch;
          ch = "SIN "[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outStart + copyIndex2,0,loopIndex,2);
        copyIndex3 = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor2 + copyIndex3) = ch;
          ch = ", "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,2,0,loopIndex,10)
        ;
        copyIndex2 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor6 + copyIndex2) = ch;
          ch = ";\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        loopIndex = loopIndex + 1;
        outStart = outCursor6 + copyIndex2;
      } while (loopIndex <= (int)(inst[2] >> 10 & 3));
      opOffsetOrTailLength = 0;
      ch = s___end_97c2eb88[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = "# end\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      if (((stateFlags[1] & 0x100000) != 0) && (shaderType == 0x8b31)) {
        *stateFlags = *stateFlags | 0x100000;
        copyIndex3 = 0;
        ch = s___sine__SIN__using_NV_vertex_pro_97c2eb90[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex3) = ch;
          ch = "# sine (SIN) using NV_vertex_program2_option\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outStart = outText + copyIndex3;
        loopIndex = 0;
        do {
          copyIndex2 = 0;
          ch = s_SIN_97c2eb80[0];
          while (ch != '\0') {
            *(char *)(outStart + copyIndex2) = ch;
            ch = "SIN "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outStart + copyIndex2,0,loopIndex,2);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,2,0,loopIndex,10);
          copyIndex2 = 0;
          ch = s___97c2d8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex2) = ch;
            ch = ";\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          loopIndex = loopIndex + 1;
          outStart = outCursor + copyIndex2;
        } while (loopIndex <= (int)(inst[2] >> 10 & 3));
        goto LAB_97c01788;
      }
      *stateFlags = *stateFlags | 0x7007;
      copyIndex = 0;
      ch = s_MAD_scratch__97c2e64c[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "MAD scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
      copyIndex = 0;
      ch = s___k2PI_RCP__kHALF__97c2ebc0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", k2PI_RCP, kHALF;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_FRC_scratch__scratch__97c2ebd4[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "FRC scratch, scratch;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_MAD_scratch__scratch__k2PI___kPI_97c2ebec[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MAD scratch, scratch, k2PI, -kPI;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_SLT_scratch1__scratch__kZERO__97c2ec10[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SLT scratch1, scratch, kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_ABS_scratch__scratch__97c2e8c0[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "ABS scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_SUB_scratch__scratch__kHALFPI__97c2ec30[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SUB scratch, scratch, kHALFPI;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_ABS_scratch__scratch__97c2e8c0[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "ABS scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_scratch__scratch__kHALFPI_RC_97c2ec50[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL scratch, scratch, kHALFPI_RCP;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_SUB_scratch2__kTHREE__scratch__97c2ec74[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SUB scratch2, kTHREE, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_scratch2__scratch2__scratch__97c2ec94[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL scratch2, scratch2, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_scratch2__scratch2__scratch__97c2ec94[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL scratch2, scratch2, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MAD_scratch2__scratch2___kHALF__k_97c2ecb8[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MAD scratch2, scratch2, -kHALF, kONE;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MAD_scratch1__scratch1___kTWO__k_97c2ece0[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MAD scratch1, scratch1, -kTWO, kONE;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_97c2e4f0[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___scratch2__scratch1__97c2ed08[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ", scratch2, scratch1;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x1a:
    if (shaderType == 0x8b30) {
      copyIndex3 = 0;
      ch = s___cosine__COS__97c2ed20[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex3) = ch;
        ch = "# cosine (COS)\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outStart = outText + copyIndex3;
      loopIndex = 0;
      do {
        copyIndex2 = 0;
        ch = s_COS_97c2ed30[0];
        while (ch != '\0') {
          *(char *)(outStart + copyIndex2) = ch;
          ch = "COS "[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outStart + copyIndex2,0,loopIndex,2);
        copyIndex3 = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor2 + copyIndex3) = ch;
          ch = ", "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,2,0,loopIndex,10)
        ;
        copyIndex2 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor6 + copyIndex2) = ch;
          ch = ";\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        loopIndex = loopIndex + 1;
        outStart = outCursor6 + copyIndex2;
      } while (loopIndex <= (int)(inst[2] >> 10 & 3));
      opOffsetOrTailLength = 0;
      ch = s___end_97c2eb88[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = "# end\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      if (((stateFlags[1] & 0x100000) != 0) && (shaderType == 0x8b31)) {
        *stateFlags = *stateFlags | 0x100000;
        copyIndex3 = 0;
        ch = s___cosine__COS__using_NV_vertex_p_97c2ed38[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex3) = ch;
          ch = "# cosine (COS) using NV_vertex_program2_option\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outStart = outText + copyIndex3;
        loopIndex = 0;
        do {
          copyIndex2 = 0;
          ch = s_COS_97c2ed30[0];
          while (ch != '\0') {
            *(char *)(outStart + copyIndex2) = ch;
            ch = "COS "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outStart + copyIndex2,0,loopIndex,2);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,2,0,loopIndex,10);
          copyIndex2 = 0;
          ch = s___97c2d8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex2) = ch;
            ch = ";\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          loopIndex = loopIndex + 1;
          outStart = outCursor + copyIndex2;
        } while (loopIndex <= (int)(inst[2] >> 10 & 3));
        goto LAB_97c01788;
      }
      *stateFlags = *stateFlags | 0x7003;
      copyIndex = 0;
      ch = s_MAD_scratch__97c2e64c[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "MAD scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
      copyIndex = 0;
      ch = s___k2PI_RCP__kHALF__97c2ebc0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", k2PI_RCP, kHALF;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_FRC_scratch__scratch__97c2ebd4[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "FRC scratch, scratch;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_MAD_scratch__scratch__k2PI___kPI_97c2ebec[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MAD scratch, scratch, k2PI, -kPI;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_ABS_scratch__scratch__97c2e8c0[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "ABS scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_scratch__scratch__kHALFPI_RC_97c2ec50[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL scratch, scratch, kHALFPI_RCP;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_SUB_scratch1__kTHREE__scratch__97c2ed68[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SUB scratch1, kTHREE, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_scratch1__scratch1__scratch__97c2ed88[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL scratch1, scratch1, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_scratch1__scratch1__scratch__97c2ed88[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL scratch1, scratch1, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MAD_97c2e644[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MAD "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___scratch1___kHALF__kONE__97c2edac[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ", scratch1, -kHALF, kONE;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x1b:
    *stateFlags = *stateFlags | 0x2f00f;
    copyIndex = 0;
    ch = s_MAD_scratch__97c2e64c[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "MAD scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s___kPI_RCP__kHALF__97c2edc8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", kPI_RCP, kHALF;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_FRC_scratch__scratch__97c2ebd4[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "FRC scratch, scratch;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_MAD_scratch__scratch__kPI___kHAL_97c2eddc[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MAD scratch, scratch, kPI, -kHALFPI;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MUL_scratch1__scratch__scratch__97c2ee04[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MUL scratch1, scratch, scratch;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MUL_scratch2__scratch1__scratch__97c2ee28[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MUL scratch2, scratch1, scratch;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MUL_scratch3__scratch1__scratch1_97c2ee4c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MUL scratch3, scratch1, scratch1;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MAD_scratch__kTAN_K1__scratch2__s_97c2ee70[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MAD scratch, kTAN_K1, scratch2, scratch;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MAD_scratch2__kTAN_K2__scratch1__97c2ee9c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MAD scratch2, kTAN_K2, scratch1, kONE;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MAD_scratch1__kTAN_K3__scratch3__97c2eec4[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MAD scratch1, kTAN_K3, scratch3, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outPtr = (char *)(outCursor2 + copyIndex);
    if ((inst[2] & 0x3000) == 0) {
      copyIndex = 0;
      ch = s_RCP_scratch1_x__scratch1_x__97c2eef0[0];
      while (ch != '\0') {
        outPtr[copyIndex] = ch;
        ch = "RCP scratch1.x, scratch1.x;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outPtr = outPtr + copyIndex;
    }
    else {
      loopIndex = 0;
      do {
        copyIndex3 = 0;
        ch = s_RCP_scratch1__97c2ea98[0];
        while (ch != '\0') {
          outPtr[copyIndex3] = ch;
          ch = "RCP scratch1."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        loopIndex = loopIndex + 1;
        outPtr = outPtr + copyIndex3;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___scratch1__97c2ef10[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ", scratch1."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ";\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
      } while (loopIndex <= (int)(inst[2] >> 10 & 3));
    }
    copyIndex = 0;
    ch = s_MUL_97c2e4f0[0];
    while (ch != '\0') {
      outPtr[copyIndex] = ch;
      ch = "MUL "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outPtr + copyIndex,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch__scratch1__97c2e4f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ", scratch, scratch1;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x1c:
    *stateFlags = *stateFlags | 0x1307f;
    copyIndex = 0;
    ch = s_SLT_scratch__97c2e474[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "SLT scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s___kZERO__97c2e484[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", kZERO;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_MUL_scratch1__97c2ef1c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "MUL scratch1, "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex + copyIndex2,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_SUB_scratch1__kONE__scratch1__97c2ef2c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "SUB scratch1, kONE, scratch1;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_SGE_scratch5__kZERO__scratch1__97c2ef4c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "SGE scratch5, kZERO, scratch1;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outPtr = (char *)(outCursor2 + copyIndex);
    loopIndex = 0;
    do {
      copyIndex3 = 0;
      ch = s_RSQ_scratch1__97c2ef6c[0];
      while (ch != '\0') {
        outPtr[copyIndex3] = ch;
        ch = "RSQ scratch1."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      loopIndex = loopIndex + 1;
      outPtr = outPtr + copyIndex3;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___scratch1__97c2ef10[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ", scratch1."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
    } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
    copyIndex = 0;
    ch = s_MUL_scratch2__97c2ef7c[0];
    while (ch != '\0') {
      outPtr[copyIndex] = ch;
      ch = "MUL scratch2, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outPtr + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s___scratch1__97c2e684[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", scratch1;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_ABS_scratch2__scratch2__97c2ef8c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "ABS scratch2, scratch2;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_SLT_scratch6__kONE__scratch2__97c2efa8[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "SLT scratch6, kONE, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outPtr = (char *)(outCursor2 + copyIndex);
    loopIndex = 0;
    do {
      copyIndex3 = 0;
      ch = s_RCP_scratch3__97c2efc8[0];
      while (ch != '\0') {
        outPtr[copyIndex3] = ch;
        ch = "RCP scratch3."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      loopIndex = loopIndex + 1;
      outPtr = outPtr + copyIndex3;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___scratch2__97c2efd8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ", scratch2."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
    } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
    copyIndex = 0;
    ch = s_SUB_scratch3__scratch3__scratch2_97c2efe4[0];
    while (ch != '\0') {
      outPtr[copyIndex] = ch;
      ch = "SUB scratch3, scratch3, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex3 = 0;
    ch = s_MAD_scratch2__scratch6__scratch3_97c2f008[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + copyIndex] = ch;
      ch = "MAD scratch2, scratch6, scratch3, scratch2;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    copyIndex2 = 0;
    ch = s_MUL_scratch1__scratch2__scratch2_97c2f038[0];
    while (ch != '\0') {
      outPtr[copyIndex2 + copyIndex3 + copyIndex] = ch;
      ch = "MUL scratch1, scratch2, scratch2;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outLen2 = copyIndex2 + copyIndex3 + copyIndex;
    copyIndex = 0;
    ch = s_MUL_scratch3__scratch1__scratch2_97c2f05c[0];
    while (ch != '\0') {
      outPtr[copyIndex + outLen2] = ch;
      ch = "MUL scratch3, scratch1, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outLen = copyIndex + outLen2;
    copyIndex3 = 0;
    ch = s_MUL_scratch4__scratch1__scratch1_97c2f080[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + outLen] = ch;
      ch = "MUL scratch4, scratch1, scratch1;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outPos = copyIndex3 + outLen;
    copyIndex = 0;
    ch = s_MUL_scratch2__kATAN_K1__scratch2_97c2f0a4[0];
    while (ch != '\0') {
      outPtr[copyIndex + outPos] = ch;
      ch = "MUL scratch2, kATAN_K1, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outLen = copyIndex + outPos;
    copyIndex3 = 0;
    ch = s_MAD_scratch2__kATAN_K3__scratch3_97c2f0c8[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + outLen] = ch;
      ch = "MAD scratch2, kATAN_K3, scratch3, scratch2;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outPos = copyIndex3 + outLen;
    copyIndex = 0;
    ch = s_MAD_scratch1__kATAN_K2__scratch1_97c2f0f8[0];
    while (ch != '\0') {
      outPtr[copyIndex + outPos] = ch;
      ch = "MAD scratch1, kATAN_K2, scratch1, kONE;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outLen = copyIndex + outPos;
    copyIndex3 = 0;
    ch = s_MAD_scratch1__kATAN_K4__scratch4_97c2f124[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + outLen] = ch;
      ch = "MAD scratch1, kATAN_K4, scratch4, scratch1;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outPtr = outPtr + copyIndex3 + outLen;
    loopIndex = 0;
    do {
      copyIndex3 = 0;
      ch = s_RCP_scratch1__97c2ea98[0];
      while (ch != '\0') {
        outPtr[copyIndex3] = ch;
        ch = "RCP scratch1."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      loopIndex = loopIndex + 1;
      outPtr = outPtr + copyIndex3;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___scratch1__97c2ef10[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ", scratch1."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
    } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
    copyIndex = 0;
    ch = s_MUL_scratch2__scratch2__scratch1_97c2f154[0];
    while (ch != '\0') {
      outPtr[copyIndex] = ch;
      ch = "MUL scratch2, scratch2, scratch1;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex3 = 0;
    ch = s_MAD_scratch1__kTWO___scratch2__k_97c2f178[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + copyIndex] = ch;
      ch = "MAD scratch1, kTWO, -scratch2, kHALFPI;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    copyIndex2 = 0;
    ch = s_MAD_scratch2__scratch6__scratch1_97c2f1a4[0];
    while (ch != '\0') {
      outPtr[copyIndex2 + copyIndex3 + copyIndex] = ch;
      ch = "MAD scratch2, scratch6, scratch1, scratch2;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outLen2 = copyIndex2 + copyIndex3 + copyIndex;
    copyIndex = 0;
    ch = s_SUB_scratch1__kHALFPI__scratch2__97c2f1d4[0];
    while (ch != '\0') {
      outPtr[copyIndex + outLen2] = ch;
      ch = "SUB scratch1, kHALFPI, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outLen = copyIndex + outLen2;
    copyIndex3 = 0;
    ch = s_MAD_scratch2__scratch5__scratch1_97c2f1f8[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + outLen] = ch;
      ch = "MAD scratch2, scratch5, scratch1, scratch2;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outPos = copyIndex3 + outLen;
    copyIndex = 0;
    ch = s_MAD_scratch__scratch___kTWO__kON_97c2f228[0];
    while (ch != '\0') {
      outPtr[copyIndex + outPos] = ch;
      ch = "MAD scratch, scratch, -kTWO, kONE;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outLen = copyIndex + outPos;
    copyIndex3 = 0;
    ch = s_MUL_97c2e4f0[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + outLen] = ch;
      ch = "MUL "[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outPtr + copyIndex3 + outLen,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch2__scratch__97c2f24c[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ", scratch2, scratch;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x1d:
    *stateFlags = *stateFlags | 0x3307f;
    copyIndex = 0;
    ch = s_SLT_scratch__97c2e474[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "SLT scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s___kZERO__97c2e484[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", kZERO;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_MUL_scratch1__97c2ef1c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "MUL scratch1, "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex + copyIndex2,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_SUB_scratch1__kONE__scratch1__97c2ef2c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "SUB scratch1, kONE, scratch1;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_SGE_scratch5__kZERO__scratch1__97c2ef4c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "SGE scratch5, kZERO, scratch1;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outPtr = (char *)(outCursor2 + copyIndex);
    loopIndex = 0;
    do {
      copyIndex3 = 0;
      ch = s_RSQ_scratch1__97c2ef6c[0];
      while (ch != '\0') {
        outPtr[copyIndex3] = ch;
        ch = "RSQ scratch1."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      loopIndex = loopIndex + 1;
      outPtr = outPtr + copyIndex3;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___scratch1__97c2ef10[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ", scratch1."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
    } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
    copyIndex = 0;
    ch = s_MUL_scratch2__97c2ef7c[0];
    while (ch != '\0') {
      outPtr[copyIndex] = ch;
      ch = "MUL scratch2, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outPtr + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s___scratch1__97c2e684[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", scratch1;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_ABS_scratch2__scratch2__97c2ef8c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "ABS scratch2, scratch2;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_ADD_scratch2__scratch2__kOFFSET__97c2f5c0[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "ADD scratch2, scratch2, kOFFSET;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_SLT_scratch6__kONE__scratch2__97c2efa8[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "SLT scratch6, kONE, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outPtr = (char *)(outCursor2 + copyIndex);
    loopIndex = 0;
    do {
      copyIndex3 = 0;
      ch = s_RCP_scratch3__97c2efc8[0];
      while (ch != '\0') {
        outPtr[copyIndex3] = ch;
        ch = "RCP scratch3."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      loopIndex = loopIndex + 1;
      outPtr = outPtr + copyIndex3;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___scratch2__97c2efd8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ", scratch2."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
    } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
    copyIndex = 0;
    ch = s_SUB_scratch3__scratch3__scratch2_97c2efe4[0];
    while (ch != '\0') {
      outPtr[copyIndex] = ch;
      ch = "SUB scratch3, scratch3, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex3 = 0;
    ch = s_MAD_scratch2__scratch6__scratch3_97c2f008[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + copyIndex] = ch;
      ch = "MAD scratch2, scratch6, scratch3, scratch2;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    copyIndex2 = 0;
    ch = s_MUL_scratch1__scratch2__scratch2_97c2f038[0];
    while (ch != '\0') {
      outPtr[copyIndex2 + copyIndex3 + copyIndex] = ch;
      ch = "MUL scratch1, scratch2, scratch2;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outLen2 = copyIndex2 + copyIndex3 + copyIndex;
    copyIndex = 0;
    ch = s_MUL_scratch3__scratch1__scratch2_97c2f05c[0];
    while (ch != '\0') {
      outPtr[copyIndex + outLen2] = ch;
      ch = "MUL scratch3, scratch1, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outLen = copyIndex + outLen2;
    copyIndex3 = 0;
    ch = s_MUL_scratch4__scratch1__scratch1_97c2f080[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + outLen] = ch;
      ch = "MUL scratch4, scratch1, scratch1;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outPos = copyIndex3 + outLen;
    copyIndex = 0;
    ch = s_MUL_scratch2__kATAN_K1__scratch2_97c2f0a4[0];
    while (ch != '\0') {
      outPtr[copyIndex + outPos] = ch;
      ch = "MUL scratch2, kATAN_K1, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outLen = copyIndex + outPos;
    copyIndex3 = 0;
    ch = s_MAD_scratch2__kATAN_K3__scratch3_97c2f0c8[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + outLen] = ch;
      ch = "MAD scratch2, kATAN_K3, scratch3, scratch2;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outPos = copyIndex3 + outLen;
    copyIndex = 0;
    ch = s_MAD_scratch1__kATAN_K2__scratch1_97c2f0f8[0];
    while (ch != '\0') {
      outPtr[copyIndex + outPos] = ch;
      ch = "MAD scratch1, kATAN_K2, scratch1, kONE;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outLen = copyIndex + outPos;
    copyIndex3 = 0;
    ch = s_MAD_scratch1__kATAN_K4__scratch4_97c2f124[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + outLen] = ch;
      ch = "MAD scratch1, kATAN_K4, scratch4, scratch1;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outPtr = outPtr + copyIndex3 + outLen;
    loopIndex = 0;
    do {
      copyIndex3 = 0;
      ch = s_RCP_scratch1__97c2ea98[0];
      while (ch != '\0') {
        outPtr[copyIndex3] = ch;
        ch = "RCP scratch1."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      loopIndex = loopIndex + 1;
      outPtr = outPtr + copyIndex3;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___scratch1__97c2ef10[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ", scratch1."[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
      *outPtr = ((byte)loopIndex & 3) + 0x77;
      copyIndex3 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + 1] = ch;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + 1;
    } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
    copyIndex = 0;
    ch = s_MUL_scratch2__scratch2__scratch1_97c2f154[0];
    while (ch != '\0') {
      outPtr[copyIndex] = ch;
      ch = "MUL scratch2, scratch2, scratch1;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex3 = 0;
    ch = s_MAD_scratch1__kTWO___scratch2__k_97c2f178[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + copyIndex] = ch;
      ch = "MAD scratch1, kTWO, -scratch2, kHALFPI;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    copyIndex2 = 0;
    ch = s_MAD_scratch2__scratch6__scratch1_97c2f1a4[0];
    while (ch != '\0') {
      outPtr[copyIndex2 + copyIndex3 + copyIndex] = ch;
      ch = "MAD scratch2, scratch6, scratch1, scratch2;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outLen2 = copyIndex2 + copyIndex3 + copyIndex;
    copyIndex = 0;
    ch = s_SUB_scratch1__kHALFPI__scratch2__97c2f1d4[0];
    while (ch != '\0') {
      outPtr[copyIndex + outLen2] = ch;
      ch = "SUB scratch1, kHALFPI, scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outLen = copyIndex + outLen2;
    copyIndex3 = 0;
    ch = s_MAD_scratch2__scratch5__scratch1_97c2f1f8[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + outLen] = ch;
      ch = "MAD scratch2, scratch5, scratch1, scratch2;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outPos = copyIndex3 + outLen;
    copyIndex = 0;
    ch = s_MAD_scratch__scratch___kTWO__kON_97c2f228[0];
    while (ch != '\0') {
      outPtr[copyIndex + outPos] = ch;
      ch = "MAD scratch, scratch, -kTWO, kONE;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outLen = copyIndex + outPos;
    copyIndex3 = 0;
    ch = s_MUL_scratch__scratch2__scratch__97c2f5e4[0];
    while (ch != '\0') {
      outPtr[copyIndex3 + outLen] = ch;
      ch = "MUL scratch, scratch2, scratch;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outPos = copyIndex3 + outLen;
    copyIndex = 0;
    ch = s_SUB_97c2e934[0];
    while (ch != '\0') {
      outPtr[copyIndex + outPos] = ch;
      ch = "SUB "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outPtr + copyIndex + outPos,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___kHALFPI__scratch__97c2f608[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ", kHALFPI, scratch;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x1e:
    *stateFlags = *stateFlags | 0x331ff;
    if (*inst >> 0x1d == 2) {
      copyIndex = 0;
      ch = s_SGE_scratch__97c2f264[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "SGE scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
      copyIndex = 0;
      ch = s___kZERO__97c2e484[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_MAD_scratch__scratch__k2PI___kPI_97c2ebec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "MAD scratch, scratch, k2PI, -kPI;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_SLT_scratch1__97c2e490[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SLT scratch1, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,paramNumbers,paramArrayPos,3,0,0,8);
      copyIndex = 0;
      ch = s___kZERO__97c2e484[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_MUL_scratch4__scratch__scratch1__97c2f274[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "MUL scratch4, scratch, scratch1;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_ABS_scratch__97c2e448[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "ABS scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,paramNumbers,paramArrayPos,3,0,0,8);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_SGE_scratch5___scratch__kZERO__97c2f298[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "SGE scratch5, -scratch, kZERO;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_SLT_scratch__97c2e474[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SLT scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
      copyIndex = 0;
      ch = s___kZERO__97c2e484[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_MAD_scratch6__scratch___kPI__kHA_97c2f2b8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "MAD scratch6, scratch, -kPI, kHALFPI;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_MAD_scratch1__scratch5__kOFFSET__97c2f2e0[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MAD scratch1, scratch5, kOFFSET, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,paramNumbers,paramArrayPos,3,0,0,8);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outPtr = (char *)(outCursor + copyIndex);
      loopIndex = 0;
      do {
        copyIndex3 = 0;
        ch = s_RCP_scratch__97c2e5f0[0];
        while (ch != '\0') {
          outPtr[copyIndex3] = ch;
          ch = "RCP scratch."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        loopIndex = loopIndex + 1;
        outPtr = outPtr + copyIndex3;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___scratch1__97c2ef10[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ", scratch1."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ";\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
      } while (loopIndex <= (int)(inst[6] >> 0xc & 3));
      copyIndex = 0;
      ch = s_MUL_scratch__97c2e62c[0];
      while (ch != '\0') {
        outPtr[copyIndex] = ch;
        ch = "MUL scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outPtr + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
      copyIndex = 0;
      ch = s___scratch__97c2e620[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_SLT_scratch7__scratch__kZERO__97c2f304[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "SLT scratch7, scratch, kZERO;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_ABS_scratch__scratch__97c2e8c0[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "ABS scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_SLT_scratch8__kONE__scratch__97c2f324[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SLT scratch8, kONE, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_SGE_scratch1___scratch__kZERO__97c2f344[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SGE scratch1, -scratch, kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MAD_scratch__scratch1__kOFFSET__s_97c2f364[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MAD scratch, scratch1, kOFFSET, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outPtr = (char *)(outCursor2 + copyIndex);
      loopIndex = 0;
      do {
        copyIndex3 = 0;
        ch = s_RCP_scratch1__97c2ea98[0];
        while (ch != '\0') {
          outPtr[copyIndex3] = ch;
          ch = "RCP scratch1."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        loopIndex = loopIndex + 1;
        outPtr = outPtr + copyIndex3;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___scratch__97c2eaa8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ", scratch."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ";\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
      } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
      copyIndex = 0;
      ch = s_SUB_scratch1__scratch1__scratch__97c2f390[0];
      while (ch != '\0') {
        outPtr[copyIndex] = ch;
        ch = "SUB scratch1, scratch1, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex3 = 0;
      ch = s_MAD_scratch__scratch8__scratch1__97c2f3b4[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + copyIndex] = ch;
        ch = "MAD scratch, scratch8, scratch1, scratch;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      copyIndex2 = 0;
      ch = s_MUL_scratch1__scratch__scratch__97c2ee04[0];
      while (ch != '\0') {
        outPtr[copyIndex2 + copyIndex3 + copyIndex] = ch;
        ch = "MUL scratch1, scratch, scratch;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outLen2 = copyIndex2 + copyIndex3 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_scratch2__scratch1__scratch__97c2ee28[0];
      while (ch != '\0') {
        outPtr[copyIndex + outLen2] = ch;
        ch = "MUL scratch2, scratch1, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outLen = copyIndex + outLen2;
      copyIndex3 = 0;
      ch = s_MUL_scratch3__scratch1__scratch1_97c2ee4c[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + outLen] = ch;
        ch = "MUL scratch3, scratch1, scratch1;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPos = copyIndex3 + outLen;
      copyIndex = 0;
      ch = s_MUL_scratch__kATAN_K1__scratch__97c2f3e0[0];
      while (ch != '\0') {
        outPtr[copyIndex + outPos] = ch;
        ch = "MUL scratch, kATAN_K1, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outLen = copyIndex + outPos;
      copyIndex3 = 0;
      ch = s_MAD_scratch2__kATAN_K3__scratch2_97c2f404[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + outLen] = ch;
        ch = "MAD scratch2, kATAN_K3, scratch2, scratch;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPos = copyIndex3 + outLen;
      copyIndex = 0;
      ch = s_MAD_scratch__kATAN_K2__scratch1__97c2f430[0];
      while (ch != '\0') {
        outPtr[copyIndex + outPos] = ch;
        ch = "MAD scratch, kATAN_K2, scratch1, kONE;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outLen = copyIndex + outPos;
      copyIndex3 = 0;
      ch = s_MAD_scratch__kATAN_K4__scratch3__97c2f458[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + outLen] = ch;
        ch = "MAD scratch, kATAN_K4, scratch3, scratch;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + outLen;
      loopIndex = 0;
      do {
        copyIndex3 = 0;
        ch = s_RCP_scratch__97c2e5f0[0];
        while (ch != '\0') {
          outPtr[copyIndex3] = ch;
          ch = "RCP scratch."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        loopIndex = loopIndex + 1;
        outPtr = outPtr + copyIndex3;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___scratch__97c2eaa8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ", scratch."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ";\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
      } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
      copyIndex = 0;
      ch = s_MUL_scratch1__scratch2__scratch__97c2f484[0];
      while (ch != '\0') {
        outPtr[copyIndex] = ch;
        ch = "MUL scratch1, scratch2, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex3 = 0;
      ch = s_MAD_scratch__kTWO___scratch1__kH_97c2f4a8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + copyIndex] = ch;
        ch = "MAD scratch, kTWO, -scratch1, kHALFPI;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      copyIndex2 = 0;
      ch = s_MAD_scratch__scratch8__scratch__s_97c2f4d0[0];
      while (ch != '\0') {
        outPtr[copyIndex2 + copyIndex3 + copyIndex] = ch;
        ch = "MAD scratch, scratch8, scratch, scratch1;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outLen2 = copyIndex2 + copyIndex3 + copyIndex;
      copyIndex = 0;
      ch = s_MAD_scratch2__scratch7___kTWO__k_97c2f4fc[0];
      while (ch != '\0') {
        outPtr[copyIndex + outLen2] = ch;
        ch = "MAD scratch2, scratch7, -kTWO, kONE;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outLen = copyIndex + outLen2;
      copyIndex3 = 0;
      ch = s_MUL_scratch__scratch__scratch2__97c2f524[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + outLen] = ch;
        ch = "MUL scratch, scratch, scratch2;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPos = copyIndex3 + outLen;
      copyIndex = 0;
      ch = s_ADD_scratch__scratch__scratch4__97c2f548[0];
      while (ch != '\0') {
        outPtr[copyIndex + outPos] = ch;
        ch = "ADD scratch, scratch, scratch4;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outLen = copyIndex + outPos;
      copyIndex3 = 0;
      ch = s_SUB_scratch1__scratch6__scratch__97c2f56c[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + outLen] = ch;
        ch = "SUB scratch1, scratch6, scratch;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPos = copyIndex3 + outLen;
      copyIndex = 0;
      ch = s_MAD_97c2e644[0];
      while (ch != '\0') {
        outPtr[copyIndex + outPos] = ch;
        ch = "MAD "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outPtr + copyIndex + outPos,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___scratch5__scratch1__scratch__97c2f590[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ", scratch5, scratch1, scratch;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      copyIndex = 0;
      ch = s_SLT_scratch__97c2e474[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "SLT scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
      copyIndex = 0;
      ch = s___kZERO__97c2e484[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_ABS_scratch2__97c2f5b0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "ABS scratch2, "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex + copyIndex2,paramNumbers,paramArrayPos,2,0,0,8);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_SLT_scratch6__kONE__scratch2__97c2efa8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "SLT scratch6, kONE, scratch2;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outPtr = (char *)(outCursor + copyIndex + copyIndex2);
      loopIndex = 0;
      do {
        copyIndex3 = 0;
        ch = s_RCP_scratch3__97c2efc8[0];
        while (ch != '\0') {
          outPtr[copyIndex3] = ch;
          ch = "RCP scratch3."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        loopIndex = loopIndex + 1;
        outPtr = outPtr + copyIndex3;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___scratch2__97c2efd8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ", scratch2."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ";\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
      } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
      copyIndex = 0;
      ch = s_SUB_scratch3__scratch3__scratch2_97c2efe4[0];
      while (ch != '\0') {
        outPtr[copyIndex] = ch;
        ch = "SUB scratch3, scratch3, scratch2;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex3 = 0;
      ch = s_MAD_scratch2__scratch6__scratch3_97c2f008[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + copyIndex] = ch;
        ch = "MAD scratch2, scratch6, scratch3, scratch2;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      copyIndex2 = 0;
      ch = s_MUL_scratch1__scratch2__scratch2_97c2f038[0];
      while (ch != '\0') {
        outPtr[copyIndex2 + copyIndex3 + copyIndex] = ch;
        ch = "MUL scratch1, scratch2, scratch2;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outLen2 = copyIndex2 + copyIndex3 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_scratch3__scratch1__scratch2_97c2f05c[0];
      while (ch != '\0') {
        outPtr[copyIndex + outLen2] = ch;
        ch = "MUL scratch3, scratch1, scratch2;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outLen = copyIndex + outLen2;
      copyIndex3 = 0;
      ch = s_MUL_scratch4__scratch1__scratch1_97c2f080[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + outLen] = ch;
        ch = "MUL scratch4, scratch1, scratch1;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPos = copyIndex3 + outLen;
      copyIndex = 0;
      ch = s_MUL_scratch2__kATAN_K1__scratch2_97c2f0a4[0];
      while (ch != '\0') {
        outPtr[copyIndex + outPos] = ch;
        ch = "MUL scratch2, kATAN_K1, scratch2;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outLen = copyIndex + outPos;
      copyIndex3 = 0;
      ch = s_MAD_scratch2__kATAN_K3__scratch3_97c2f0c8[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + outLen] = ch;
        ch = "MAD scratch2, kATAN_K3, scratch3, scratch2;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPos = copyIndex3 + outLen;
      copyIndex = 0;
      ch = s_MAD_scratch1__kATAN_K2__scratch1_97c2f0f8[0];
      while (ch != '\0') {
        outPtr[copyIndex + outPos] = ch;
        ch = "MAD scratch1, kATAN_K2, scratch1, kONE;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outLen = copyIndex + outPos;
      copyIndex3 = 0;
      ch = s_MAD_scratch1__kATAN_K4__scratch4_97c2f124[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + outLen] = ch;
        ch = "MAD scratch1, kATAN_K4, scratch4, scratch1;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outPtr = outPtr + copyIndex3 + outLen;
      loopIndex = 0;
      do {
        copyIndex3 = 0;
        ch = s_RCP_scratch1__97c2ea98[0];
        while (ch != '\0') {
          outPtr[copyIndex3] = ch;
          ch = "RCP scratch1."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        loopIndex = loopIndex + 1;
        outPtr = outPtr + copyIndex3;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___scratch1__97c2ef10[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ", scratch1."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ";\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
      } while (loopIndex <= (int)(inst[4] >> 0xc & 3));
      copyIndex = 0;
      ch = s_MUL_scratch2__scratch2__scratch1_97c2f154[0];
      while (ch != '\0') {
        outPtr[copyIndex] = ch;
        ch = "MUL scratch2, scratch2, scratch1;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex3 = 0;
      ch = s_MAD_scratch1__kTWO___scratch2__k_97c2f178[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + copyIndex] = ch;
        ch = "MAD scratch1, kTWO, -scratch2, kHALFPI;\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      copyIndex2 = 0;
      ch = s_MAD_scratch2__scratch6__scratch1_97c2f1a4[0];
      while (ch != '\0') {
        outPtr[copyIndex2 + copyIndex3 + copyIndex] = ch;
        ch = "MAD scratch2, scratch6, scratch1, scratch2;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outLen2 = copyIndex2 + copyIndex3 + copyIndex;
      copyIndex = 0;
      ch = s_MAD_scratch__scratch___kTWO__kON_97c2f228[0];
      while (ch != '\0') {
        outPtr[copyIndex + outLen2] = ch;
        ch = "MAD scratch, scratch, -kTWO, kONE;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outLen = copyIndex + outLen2;
      copyIndex3 = 0;
      ch = s_MUL_97c2e4f0[0];
      while (ch != '\0') {
        outPtr[copyIndex3 + outLen] = ch;
        ch = "MUL "[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outPtr + copyIndex3 + outLen,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___scratch2__scratch__97c2f24c[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ", scratch2, scratch;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x1f:
  case 0x20:
    outLen2 = 1;
    if ((inst[2] & 0x1000) != 0) {
      outLen2 = (inst[2] >> 10 & 3) + 1;
    }
    loopIndex4 = 0;
    if (outLen2 == 0) goto LAB_97c0178c;
    do {
      copyIndex11 = 0;
      mnemonic = *(char **)(PTR__ppstreamOpString_a7b7c108 + opOffsetOrTailLength);
      ch = *mnemonic;
      while (ch != '\0') {
        *(char *)(outStart + copyIndex11) = ch;
        copyIndex11 = copyIndex11 + 1;
        ch = mnemonic[copyIndex11];
      }
      copyIndex6 = 0;
      ch = s__97c291c0[0];
      while (ch != '\0') {
        *(char *)(outStart + copyIndex11 + copyIndex6) = ch;
        ch = " "[copyIndex6 + 1];
        copyIndex6 = copyIndex6 + 1;
      }
      outCursor5 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outStart + copyIndex11 + copyIndex6,loopIndex4,0,0);
      copyIndex3 = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor5 + copyIndex3) = ch;
        ch = ", "[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      swizzleSelect2 = loopIndex4;
      if ((inst[4] & 0x4000) == 0) {
        swizzleSelect2 = 0;
      }
      outCursor5 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor5 + copyIndex3,paramNumbers,paramArrayPos,2,swizzleSelect2,0,8);
      copyIndex3 = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor5 + copyIndex3) = ch;
        ch = ", "[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      swizzleSelect2 = loopIndex4;
      if ((inst[6] & 0x4000) == 0) {
        swizzleSelect2 = 0;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor5 + copyIndex3,paramNumbers,paramArrayPos,3,swizzleSelect2,0,8);
      copyIndex5 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex5) = ch;
        ch = ";\n"[copyIndex5 + 1];
        copyIndex5 = copyIndex5 + 1;
      }
      loopIndex4 = loopIndex4 + 1;
      outStart = outCursor + copyIndex5;
    } while (loopIndex4 < outLen2);
    goto LAB_97c01788;
  case 0x21:
    *stateFlags = *stateFlags | 1;
    if ((inst[6] >> 0xc & 3) == 0) {
      copyIndex = 0;
      ch = s_RCP_scratch__97c2e600[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "RCP scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,3,0,0,0);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = outCursor + copyIndex;
    }
    else {
      componentIndex = 0;
      do {
        copyIndex2 = 0;
        ch = s_RCP_scratch__97c2e5f0[0];
        while (ch != '\0') {
          *(char *)(outStart + copyIndex2) = ch;
          ch = "RCP scratch."[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        nextComponent = componentIndex + 1;
        outPtr = (char *)(outStart + copyIndex2);
        *outPtr = ((byte)nextComponent & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ", "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outPtr + copyIndex3 + 1,paramNumbers,paramArrayPos,3,0,componentIndex,10);
        copyIndex = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ";\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outStart = outCursor + copyIndex;
        componentIndex = nextComponent;
      } while (nextComponent <= (int)(inst[6] >> 0xc & 3));
    }
    copyIndex = 0;
    ch = s_MUL_scratch__scratch__97c2e9ec[0];
    while (ch != '\0') {
      *(char *)(outStart + copyIndex) = ch;
      ch = "MUL scratch, scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outStart + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_FLR_scratch__scratch__97c2ea04[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "FLR scratch, scratch;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_MAD_97c2e644[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MAD "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___scratch__97c2e570[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,9);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x22:
  case 0x4e:
    destOverlapsSource = false;
    if ((*(short *)((int)inst + 0xe) == *(short *)((int)inst + 0x16)) ||
       (*(short *)((int)inst + 0xe) == *(short *)((int)inst + 0x1e))) {
      destOverlapsSource = true;
    }
    src1Word0 = inst[4];
    if (((src1Word0 & 0x4000) == 0) || ((inst[6] & 0x4000) == 0)) {
      if (((src1Word0 & 0x4000) == 0) && ((inst[6] & 0x4000) == 0)) {
        copyIndex = 0;
        ch = s_MUL_97c2e4f0[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "MUL "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,8);
        opOffsetOrTailLength = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outStart + opOffsetOrTailLength) = ch;
          ch = ";\n"[opOffsetOrTailLength + 1];
          opOffsetOrTailLength = opOffsetOrTailLength + 1;
        }
        break;
      }
      if (((src1Word0 & 0x3000) == 0) || (opcode = inst[6] >> 0xc & 3, opcode == 0)) {
        loopIndex = 0;
        do {
          copyIndex2 = 0;
          ch = s_MUL_97c2e4f0[0];
          while (ch != '\0') {
            *(char *)(outStart + copyIndex2) = ch;
            ch = "MUL "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outStart + copyIndex2,loopIndex,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          swizzleSelect = loopIndex;
          if ((inst[4] & 0x4000) == 0) {
            swizzleSelect = 0;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,2,swizzleSelect,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          swizzleSelect = loopIndex;
          if ((inst[6] & 0x4000) == 0) {
            swizzleSelect = 0;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,3,swizzleSelect,0,0);
          copyIndex2 = 0;
          ch = s___97c2d8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex2) = ch;
            ch = ";\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          loopIndex = loopIndex + 1;
          outStart = outCursor + copyIndex2;
        } while (loopIndex <= (int)(inst[2] >> 10 & 3));
      }
      else if ((src1Word0 & 0x4000) == 0) {
        if (destOverlapsSource) {
          if ((opcode != 1) || (((stateFlags[1] & 0x800000) != 0 && (shaderType == 0x8b30)))) {
            *stateFlags = *stateFlags | 1;
            writeMaskBits = inst[2];
            writeMaskBits3 = writeMaskBits >> 0xd & 0xf;
            loopIndex2 = 0;
            outBase = outText;
            do {
              if ((writeMaskBits3 & 1) != 0) {
                if (opcode != 1) {
                  if (opcode == 2) {
                    copyIndex2 = 0;
                    ch = s_DP3_scratch_97c2e6bc[0];
                    while (ch != '\0') {
                      *(char *)(outBase + copyIndex2) = ch;
                      ch = "DP3 scratch"[copyIndex2 + 1];
                      copyIndex2 = copyIndex2 + 1;
                    }
                  }
                  else {
                    copyIndex2 = 0;
                    ch = s_DP4_scratch_97c2e6c8[0];
                    while (ch != '\0') {
                      *(char *)(outBase + copyIndex2) = ch;
                      ch = "DP4 scratch"[copyIndex2 + 1];
                      copyIndex2 = copyIndex2 + 1;
                    }
                  }
                }
                else {
                  *stateFlags = *stateFlags | 0x800000;
                  copyIndex2 = 0;
                  ch = s___NV_fragment_program2_DP2_97c2e694[0];
                  while (ch != '\0') {
                    *(char *)(outBase + copyIndex2) = ch;
                    ch = "# NV_fragment_program2:DP2\n"[copyIndex2 + 1];
                    copyIndex2 = copyIndex2 + 1;
                  }
                  outBase = outBase + copyIndex2;
                  copyIndex2 = 0;
                  ch = s_DP2_scratch_97c2e6b0[0];
                  while (ch != '\0') {
                    *(char *)(outBase + copyIndex2) = ch;
                    ch = "DP2 scratch"[copyIndex2 + 1];
                    copyIndex2 = copyIndex2 + 1;
                  }
                }
                outCursor2 = ((int (*)())_glpWriteDestinationMask)(inst,outBase + copyIndex2,loopIndex2,2);
                copyIndex = 0;
                ch = s___97c2d7ec[0];
                while (ch != '\0') {
                  *(char *)(outCursor2 + copyIndex) = ch;
                  ch = ", "[copyIndex + 1];
                  copyIndex = copyIndex + 1;
                }
                outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
                copyIndex = 0;
                ch = s___97c2d7ec[0];
                while (ch != '\0') {
                  *(char *)(outCursor2 + copyIndex) = ch;
                  ch = ", "[copyIndex + 1];
                  copyIndex = copyIndex + 1;
                }
                outCursor3 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,paramNumbers,paramArrayPos,3,loopIndex2,0,0x10);
                copyIndex2 = 0;
                ch = s___97c2d8f8[0];
                while (ch != '\0') {
                  *(char *)(outCursor3 + copyIndex2) = ch;
                  ch = ";\n"[copyIndex2 + 1];
                  copyIndex2 = copyIndex2 + 1;
                }
                writeMaskBits = inst[2];
                outBase = outCursor3 + copyIndex2;
              }
              loopIndex2 = loopIndex2 + 1;
              writeMaskBits3 = (int)writeMaskBits3 >> 1;
            } while (loopIndex2 <= (int)(writeMaskBits >> 10 & 3));
            copyIndex3 = 0;
            ch = s_MOV_97c2e430[0];
            while (ch != '\0') {
              *(char *)(outBase + copyIndex3) = ch;
              ch = "MOV "[copyIndex3 + 1];
              copyIndex3 = copyIndex3 + 1;
            }
            outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outBase + copyIndex3,0,0,0);
            opOffsetOrTailLength = 0;
            ch = s___scratch__97c2e620[0];
            while (ch != '\0') {
              *(char *)(outStart + opOffsetOrTailLength) = ch;
              ch = ", scratch;\n"[opOffsetOrTailLength + 1];
              opOffsetOrTailLength = opOffsetOrTailLength + 1;
            }
          }
          else {
            *stateFlags = *stateFlags | 3;
            writeMaskBits = inst[2];
            writeMaskBits2 = writeMaskBits >> 0xd & 0xf;
            loopIndex2 = 0;
            outBase = outText;
            do {
              if ((writeMaskBits2 & 1) != 0) {
                copyIndex2 = 0;
                ch = s_MUL_scratch__97c2e62c[0];
                while (ch != '\0') {
                  *(char *)(outBase + copyIndex2) = ch;
                  ch = "MUL scratch, "[copyIndex2 + 1];
                  copyIndex2 = copyIndex2 + 1;
                }
                outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outBase + copyIndex2,paramNumbers,paramArrayPos,2,0,0,0);
                copyIndex = 0;
                ch = s___97c2d7ec[0];
                while (ch != '\0') {
                  *(char *)(outCursor2 + copyIndex) = ch;
                  ch = ", "[copyIndex + 1];
                  copyIndex = copyIndex + 1;
                }
                outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,paramNumbers,paramArrayPos,3,loopIndex2,0,0x10);
                copyIndex = 0;
                ch = s___97c2d8f8[0];
                while (ch != '\0') {
                  *(char *)(outCursor2 + copyIndex) = ch;
                  ch = ";\n"[copyIndex + 1];
                  copyIndex = copyIndex + 1;
                }
                copyIndex4 = 0;
                ch = s_ADD_scratch1_97c2e674[0];
                while (ch != '\0') {
                  *(char *)(outCursor2 + copyIndex + copyIndex4) = ch;
                  ch = "ADD scratch1"[copyIndex4 + 1];
                  copyIndex4 = copyIndex4 + 1;
                }
                outCursor3 = ((int (*)())_glpWriteDestinationMask)(inst,outCursor2 + copyIndex + copyIndex4,loopIndex2,2);
                copyIndex2 = 0;
                ch = s___scratch_x__scratch_y__97c2e524[0];
                while (ch != '\0') {
                  *(char *)(outCursor3 + copyIndex2) = ch;
                  ch = ", scratch.x, scratch.y;\n"[copyIndex2 + 1];
                  copyIndex2 = copyIndex2 + 1;
                }
                writeMaskBits = inst[2];
                outBase = outCursor3 + copyIndex2;
              }
              loopIndex2 = loopIndex2 + 1;
              writeMaskBits2 = (int)writeMaskBits2 >> 1;
            } while (loopIndex2 <= (int)(writeMaskBits >> 10 & 3));
            copyIndex3 = 0;
            ch = s_MOV_97c2e430[0];
            while (ch != '\0') {
              *(char *)(outBase + copyIndex3) = ch;
              ch = "MOV "[copyIndex3 + 1];
              copyIndex3 = copyIndex3 + 1;
            }
            outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outBase + copyIndex3,0,0,0);
            opOffsetOrTailLength = 0;
            ch = s___scratch1__97c2e684[0];
            while (ch != '\0') {
              *(char *)(outStart + opOffsetOrTailLength) = ch;
              ch = ", scratch1;\n"[opOffsetOrTailLength + 1];
              opOffsetOrTailLength = opOffsetOrTailLength + 1;
            }
          }
          break;
        }
        if ((opcode != 1) || (((stateFlags[1] & 0x800000) != 0 && (shaderType == 0x8b30)))) {
          writeMaskBits = inst[2];
          writeMaskBits3 = writeMaskBits >> 0xd & 0xf;
          loopIndex = 0;
          do {
            if ((writeMaskBits3 & 1) != 0) {
              if (opcode != 1) {
                if (opcode == 2) {
                  copyIndex2 = 0;
                  ch = s_DP3_97c2e548[0];
                  while (ch != '\0') {
                    *(char *)(outStart + copyIndex2) = ch;
                    ch = "DP3 "[copyIndex2 + 1];
                    copyIndex2 = copyIndex2 + 1;
                  }
                }
                else {
                  copyIndex2 = 0;
                  ch = s_DP4_97c2e550[0];
                  while (ch != '\0') {
                    *(char *)(outStart + copyIndex2) = ch;
                    ch = "DP4 "[copyIndex2 + 1];
                    copyIndex2 = copyIndex2 + 1;
                  }
                }
              }
              else {
                *stateFlags = *stateFlags | 0x800000;
                copyIndex2 = 0;
                ch = s___NV_fragment_program2_DP2_97c2e694[0];
                while (ch != '\0') {
                  *(char *)(outStart + copyIndex2) = ch;
                  ch = "# NV_fragment_program2:DP2\n"[copyIndex2 + 1];
                  copyIndex2 = copyIndex2 + 1;
                }
                outStart = outStart + copyIndex2;
                copyIndex2 = 0;
                ch = s_DP2_97c2e540[0];
                while (ch != '\0') {
                  *(char *)(outStart + copyIndex2) = ch;
                  ch = "DP2 "[copyIndex2 + 1];
                  copyIndex2 = copyIndex2 + 1;
                }
              }
              outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outStart + copyIndex2,0,loopIndex,2);
              copyIndex3 = 0;
              ch = s___97c2d7ec[0];
              while (ch != '\0') {
                *(char *)(outCursor2 + copyIndex3) = ch;
                ch = ", "[copyIndex3 + 1];
                copyIndex3 = copyIndex3 + 1;
              }
              outCursor7 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,2,0,0,0)
              ;
              copyIndex3 = 0;
              ch = s___97c2d7ec[0];
              while (ch != '\0') {
                *(char *)(outCursor7 + copyIndex3) = ch;
                ch = ", "[copyIndex3 + 1];
                copyIndex3 = copyIndex3 + 1;
              }
              outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor7 + copyIndex3,paramNumbers,paramArrayPos,3,loopIndex,0,0x10);
              copyIndex2 = 0;
              ch = s___97c2d8f8[0];
              while (ch != '\0') {
                *(char *)(outCursor + copyIndex2) = ch;
                ch = ";\n"[copyIndex2 + 1];
                copyIndex2 = copyIndex2 + 1;
              }
              writeMaskBits = inst[2];
              outStart = outCursor + copyIndex2;
            }
            loopIndex = loopIndex + 1;
            writeMaskBits3 = (int)writeMaskBits3 >> 1;
          } while (loopIndex <= (int)(writeMaskBits >> 10 & 3));
        }
        else {
          *stateFlags = *stateFlags | 1;
          writeMaskBits = inst[2];
          writeMaskBits2 = writeMaskBits >> 0xd & 0xf;
          loopIndex = 0;
          do {
            if ((writeMaskBits2 & 1) != 0) {
              copyIndex2 = 0;
              ch = s_MUL_scratch__97c2e62c[0];
              while (ch != '\0') {
                *(char *)(outStart + copyIndex2) = ch;
                ch = "MUL scratch, "[copyIndex2 + 1];
                copyIndex2 = copyIndex2 + 1;
              }
              outCursor7 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outStart + copyIndex2,paramNumbers,paramArrayPos,2,0,0,0)
              ;
              copyIndex3 = 0;
              ch = s___97c2d7ec[0];
              while (ch != '\0') {
                *(char *)(outCursor7 + copyIndex3) = ch;
                ch = ", "[copyIndex3 + 1];
                copyIndex3 = copyIndex3 + 1;
              }
              outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor7 + copyIndex3,paramNumbers,paramArrayPos,3,loopIndex,0,0x10);
              copyIndex3 = 0;
              ch = s___97c2d8f8[0];
              while (ch != '\0') {
                *(char *)(outCursor2 + copyIndex3) = ch;
                ch = ";\n"[copyIndex3 + 1];
                copyIndex3 = copyIndex3 + 1;
              }
              copyIndex4 = 0;
              ch = s_ADD_97c2e6d4[0];
              while (ch != '\0') {
                *(char *)(outCursor2 + copyIndex3 + copyIndex4) = ch;
                ch = "ADD "[copyIndex4 + 1];
                copyIndex4 = copyIndex4 + 1;
              }
              outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex3 + copyIndex4,0,loopIndex,2);
              copyIndex2 = 0;
              ch = s___scratch_x__scratch_y__97c2e524[0];
              while (ch != '\0') {
                *(char *)(outCursor + copyIndex2) = ch;
                ch = ", scratch.x, scratch.y;\n"[copyIndex2 + 1];
                copyIndex2 = copyIndex2 + 1;
              }
              writeMaskBits = inst[2];
              outStart = outCursor + copyIndex2;
            }
            loopIndex = loopIndex + 1;
            writeMaskBits2 = (int)writeMaskBits2 >> 1;
          } while (loopIndex <= (int)(writeMaskBits >> 10 & 3));
        }
      }
      else {
        *stateFlags = *stateFlags | 1;
        src1Word0 = inst[4];
        rowIndex = 0;
        do {
          if (rowIndex == 0) {
            outLen2 = 0;
            copyIndex12 = outLen2;
            ch = s_MUL_97c2e4f0[0];
            if (s_MUL_97c2e4f0[0] != '\0') {
              do {
                *(char *)(outStart + copyIndex12) = ch;
                outLen2 = copyIndex12 + 1;
                ch = "MUL "[copyIndex12 + 1];
                copyIndex12 = outLen2;
              } while (ch != '\0');
              goto LAB_97bf6dac;
            }
          }
          else {
            outLen2 = 0;
            copyIndex12 = outLen2;
            ch = s_MAD_97c2e644[0];
            if (s_MAD_97c2e644[0] != '\0') {
              do {
                *(char *)(outStart + copyIndex12) = ch;
                outLen2 = copyIndex12 + 1;
                ch = "MAD "[copyIndex12 + 1];
                copyIndex12 = outLen2;
              } while (ch != '\0');
LAB_97bf6dac:
              src1Word0 = inst[4];
            }
          }
          outCursor = outStart + outLen2;
          if (rowIndex == (src1Word0 >> 0xc & 3)) {
            outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor,0,0,0);
            copyIndex = 0;
            ch = s___97c2d7ec[0];
            while (ch != '\0') {
              *(char *)(outCursor + copyIndex) = ch;
              ch = ", "[copyIndex + 1];
              copyIndex = copyIndex + 1;
            }
          }
          else {
            copyIndex = 0;
            ch = s_scratch__97c2e668[0];
            while (ch != '\0') {
              *(char *)(outCursor + copyIndex) = ch;
              ch = "scratch, "[copyIndex + 1];
              copyIndex = copyIndex + 1;
            }
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,rowIndex,0,8);
          copyIndex = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex) = ch;
            ch = ", "[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,rowIndex,2);
          if (rowIndex == 0) {
            copyIndex = 0;
            ch = s___97c2d8f8[0];
            while (ch != '\0') {
              *(char *)(outCursor + copyIndex) = ch;
              ch = ";\n"[copyIndex + 1];
              copyIndex = copyIndex + 1;
            }
          }
          else {
            copyIndex = 0;
            ch = s___scratch__97c2e620[0];
            while (ch != '\0') {
              *(char *)(outCursor + copyIndex) = ch;
              ch = ", scratch;\n"[copyIndex + 1];
              copyIndex = copyIndex + 1;
            }
          }
          src1Word0 = inst[4];
          outStart = outCursor + copyIndex;
          rowIndex = rowIndex + 1;
        } while ((int)rowIndex <= (int)(src1Word0 >> 0xc & 3));
      }
    }
    else {
      *stateFlags = *stateFlags | 1;
      sizeMinusOne = inst[2] >> 10 & 3;
      if (sizeMinusOne == 1) {
        componentIndex = 0;
        do {
          copyIndex2 = 0;
          ch = s_MUL_scratch__97c2e62c[0];
          while (ch != '\0') {
            *(char *)(outStart + copyIndex2) = ch;
            ch = "MUL scratch, "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outStart + copyIndex2,paramNumbers,paramArrayPos,2,0,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,3,0,componentIndex,2);
          copyIndex3 = 0;
          ch = s___97c2d8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ";\n"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          copyIndex4 = 0;
          ch = s_MAD_97c2e644[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3 + copyIndex4) = ch;
            ch = "MAD "[copyIndex4 + 1];
            copyIndex4 = copyIndex4 + 1;
          }
          outCursor4 = outCursor2 + copyIndex3 + copyIndex4;
          if (!destOverlapsSource) {
            outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor4,componentIndex,0,0);
          }
          else {
            copyIndex2 = 0;
            ch = s_scratch_97c2e63c[0];
            while (ch != '\0') {
              *(char *)(outCursor4 + copyIndex2) = ch;
              ch = "scratch"[copyIndex2 + 1];
              copyIndex2 = copyIndex2 + 1;
            }
            copyEnd = ((int (*)())_ncpy_97bf2850)(outCursor4 + copyIndex2,componentIndex + 1);
            outCursor = outCursor4 + copyIndex2 + copyEnd;
          }
          nextComponent = componentIndex + 1;
          copyIndex2 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex2) = ch;
            ch = ", "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex2,paramNumbers,paramArrayPos,2,1,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,3,1,componentIndex,2);
          copyIndex = 0;
          ch = s___scratch__97c2e620[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex) = ch;
            ch = ", scratch;\n"[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          outStart = outCursor + copyIndex;
          componentIndex = nextComponent;
        } while (nextComponent <= (int)(inst[2] >> 10 & 3));
        if (destOverlapsSource) {
          flagWord = *stateFlags | 6;
LAB_97bf68e0:
          *stateFlags = flagWord;
LAB_97bf68e4:
          if (destOverlapsSource) {
            loopIndex = 0;
            do {
              copyIndex2 = 0;
              ch = s_MOV_97c2e430[0];
              while (ch != '\0') {
                *(char *)(outStart + copyIndex2) = ch;
                ch = "MOV "[copyIndex2 + 1];
                copyIndex2 = copyIndex2 + 1;
              }
              outCursor4 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outStart + copyIndex2,loopIndex,0,0);
              copyIndex2 = 0;
              ch = s___scratch_97c2e65c[0];
              while (ch != '\0') {
                *(char *)(outCursor4 + copyIndex2) = ch;
                ch = ", scratch"[copyIndex2 + 1];
                copyIndex2 = copyIndex2 + 1;
              }
              loopIndex = loopIndex + 1;
              copyEnd = ((int (*)())_ncpy_97bf2850)(outCursor4 + copyIndex2,loopIndex);
              outCursor = outCursor4 + copyIndex2 + copyEnd;
              copyIndex2 = 0;
              ch = s___97c2d8f8[0];
              while (ch != '\0') {
                *(char *)(outCursor + copyIndex2) = ch;
                ch = ";\n"[copyIndex2 + 1];
                copyIndex2 = copyIndex2 + 1;
              }
              outStart = outCursor + copyIndex2;
            } while (loopIndex <= (int)(inst[2] >> 10 & 3));
          }
        }
      }
      else if (sizeMinusOne == 2) {
        componentIndex = 0;
        do {
          copyIndex2 = 0;
          ch = s_MUL_scratch__97c2e62c[0];
          while (ch != '\0') {
            *(char *)(outStart + copyIndex2) = ch;
            ch = "MUL scratch, "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outStart + copyIndex2,paramNumbers,paramArrayPos,2,0,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,3,0,componentIndex,2);
          copyIndex3 = 0;
          ch = s___97c2d8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ";\n"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          copyIndex4 = 0;
          ch = s_MAD_scratch__97c2e64c[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3 + copyIndex4) = ch;
            ch = "MAD scratch, "[copyIndex4 + 1];
            copyIndex4 = copyIndex4 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3 + copyIndex4,paramNumbers,paramArrayPos,2,1,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,3,1,componentIndex,2);
          copyIndex3 = 0;
          ch = s___scratch__97c2e620[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", scratch;\n"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          copyIndex4 = 0;
          ch = s_MAD_97c2e644[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3 + copyIndex4) = ch;
            ch = "MAD "[copyIndex4 + 1];
            copyIndex4 = copyIndex4 + 1;
          }
          outCursor4 = outCursor2 + copyIndex3 + copyIndex4;
          if (!destOverlapsSource) {
            outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor4,componentIndex,0,0);
          }
          else {
            copyIndex2 = 0;
            ch = s_scratch_97c2e63c[0];
            while (ch != '\0') {
              *(char *)(outCursor4 + copyIndex2) = ch;
              ch = "scratch"[copyIndex2 + 1];
              copyIndex2 = copyIndex2 + 1;
            }
            copyEnd = ((int (*)())_ncpy_97bf2850)(outCursor4 + copyIndex2,componentIndex + 1);
            outCursor = outCursor4 + copyIndex2 + copyEnd;
          }
          nextComponent = componentIndex + 1;
          copyIndex2 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex2) = ch;
            ch = ", "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex2,paramNumbers,paramArrayPos,2,2,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,3,2,componentIndex,2);
          copyIndex = 0;
          ch = s___scratch__97c2e620[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex) = ch;
            ch = ", scratch;\n"[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          outStart = outCursor + copyIndex;
          componentIndex = nextComponent;
        } while (nextComponent <= (int)(inst[2] >> 10 & 3));
        if (destOverlapsSource) {
          flagWord = *stateFlags | 0xe;
          goto LAB_97bf68e0;
        }
      }
      else {
        if (sizeMinusOne != 3) goto LAB_97bf68e4;
        componentIndex = 0;
        do {
          copyIndex2 = 0;
          ch = s_MUL_scratch__97c2e62c[0];
          while (ch != '\0') {
            *(char *)(outStart + copyIndex2) = ch;
            ch = "MUL scratch, "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outStart + copyIndex2,paramNumbers,paramArrayPos,2,0,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,3,0,componentIndex,2);
          copyIndex3 = 0;
          ch = s___97c2d8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ";\n"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          copyIndex4 = 0;
          ch = s_MAD_scratch__97c2e64c[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3 + copyIndex4) = ch;
            ch = "MAD scratch, "[copyIndex4 + 1];
            copyIndex4 = copyIndex4 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3 + copyIndex4,paramNumbers,paramArrayPos,2,1,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,3,1,componentIndex,2);
          copyIndex3 = 0;
          ch = s___scratch__97c2e620[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", scratch;\n"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          copyIndex4 = 0;
          ch = s_MAD_scratch__97c2e64c[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3 + copyIndex4) = ch;
            ch = "MAD scratch, "[copyIndex4 + 1];
            copyIndex4 = copyIndex4 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3 + copyIndex4,paramNumbers,paramArrayPos,2,2,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,3,2,componentIndex,2);
          copyIndex3 = 0;
          ch = s___scratch__97c2e620[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", scratch;\n"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          copyIndex4 = 0;
          ch = s_MAD_97c2e644[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3 + copyIndex4) = ch;
            ch = "MAD "[copyIndex4 + 1];
            copyIndex4 = copyIndex4 + 1;
          }
          outCursor4 = outCursor2 + copyIndex3 + copyIndex4;
          if (!destOverlapsSource) {
            outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor4,componentIndex,0,0);
          }
          else {
            copyIndex2 = 0;
            ch = s_scratch_97c2e63c[0];
            while (ch != '\0') {
              *(char *)(outCursor4 + copyIndex2) = ch;
              ch = "scratch"[copyIndex2 + 1];
              copyIndex2 = copyIndex2 + 1;
            }
            copyEnd = ((int (*)())_ncpy_97bf2850)(outCursor4 + copyIndex2,componentIndex + 1);
            outCursor = outCursor4 + copyIndex2 + copyEnd;
          }
          nextComponent = componentIndex + 1;
          copyIndex2 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex2) = ch;
            ch = ", "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex2,paramNumbers,paramArrayPos,2,3,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,3,3,componentIndex,2);
          copyIndex = 0;
          ch = s___scratch__97c2e620[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex) = ch;
            ch = ", scratch;\n"[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          outStart = outCursor + copyIndex;
          componentIndex = nextComponent;
        } while (nextComponent <= (int)(inst[2] >> 10 & 3));
        if (destOverlapsSource) {
          flagWord = *stateFlags | 0x1e;
          goto LAB_97bf68e0;
        }
      }
    }
    goto LAB_97c01788;
  case 0x23:
    destOverlapsSource = false;
    if ((*(short *)((int)inst + 0xe) == *(short *)((int)inst + 0x16)) ||
       (*(short *)((int)inst + 0xe) == *(short *)((int)inst + 0x1e))) {
      destOverlapsSource = true;
    }
    loopIndex = 0;
    do {
      copyIndex2 = 0;
      ch = s_MUL_97c2e4f0[0];
      while (ch != '\0') {
        *(char *)(outStart + copyIndex2) = ch;
        ch = "MUL "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor = outStart + copyIndex2;
      if (!destOverlapsSource) {
        outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor,loopIndex,0,0);
      }
      else {
        copyIndex2 = 0;
        ch = s_scratch_97c2e63c[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex2) = ch;
          ch = "scratch"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor = outCursor + copyIndex2;
        if (loopIndex != 0) {
          copyEnd2 = ((int (*)())_ncpy_97bf2850)(outCursor,loopIndex);
          outCursor = outCursor + copyEnd2;
        }
      }
      copyIndex2 = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex2) = ch;
        ch = ", "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex2,paramNumbers,paramArrayPos,2,loopIndex,0,0);
      copyIndex3 = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex3) = ch;
        ch = ", "[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,3,loopIndex,0,0);
      copyIndex2 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex2) = ch;
        ch = ";\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      loopIndex = loopIndex + 1;
      outStart = outCursor + copyIndex2;
      sizeMinusOne = inst[2] >> 10 & 3;
    } while (loopIndex <= (int)sizeMinusOne);
    if (destOverlapsSource) {
      if (sizeMinusOne == 1) {
        flagWord = *stateFlags | 3;
LAB_97bf7aec:
        *stateFlags = flagWord;
      }
      else {
        if (sizeMinusOne == 2) {
          flagWord = *stateFlags | 7;
          goto LAB_97bf7aec;
        }
        if (sizeMinusOne == 3) {
          flagWord = *stateFlags | 0xf;
          goto LAB_97bf7aec;
        }
      }
      loopIndex = 0;
      do {
        copyIndex2 = 0;
        ch = s_MOV_97c2e430[0];
        while (ch != '\0') {
          *(char *)(outStart + copyIndex2) = ch;
          ch = "MOV "[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outStart + copyIndex2,loopIndex,0,0);
        copyIndex2 = 0;
        ch = s___scratch_97c2e65c[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex2) = ch;
          ch = ", scratch"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor = outCursor + copyIndex2;
        if (loopIndex != 0) {
          copyEnd2 = ((int (*)())_ncpy_97bf2850)(outCursor,loopIndex);
          outCursor = outCursor + copyEnd2;
        }
        copyIndex2 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex2) = ch;
          ch = ";\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        loopIndex = loopIndex + 1;
        outStart = outCursor + copyIndex2;
      } while (loopIndex <= (int)(inst[2] >> 10 & 3));
    }
    goto LAB_97c01788;
  case 0x24:
    copyIndex = 0;
    ch = s_MUL_97c2e4f0[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "MUL "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x25:
    *stateFlags = *stateFlags | 0x2001;
    copyIndex = 0;
    ch = s_ADD_scratch_x__97c2e960[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "ADD scratch.x, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,0);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_SGE_97c2e91c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "SGE "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch_x__kHALF__97c2e970[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ", scratch.x, kHALF;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x26:
    *stateFlags = *stateFlags | 1;
    copyIndex = 0;
    ch = s_SUB_scratch_x__97c2e988[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "SUB scratch.x, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,0);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_ABS_97c2e998[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "ABS "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch_x__97c2e594[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ", scratch.x;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x27:
    src1Word0 = inst[4];
    if (((src1Word0 >> 0xc & 3) == 1) && (((stateFlags[1] & 0x800000) == 0 || (shaderType != 0x8b30)))) {
      copyIndex = 0;
      ch = s_MUL_scratch_xy__97c2e510[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "MUL scratch.xy, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,0);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_MUL_97c2e4f0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "MUL "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___scratch_x__scratch_y__97c2e524[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ", scratch.x, scratch.y;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      if ((src1Word0 >> 0xc & 3) == 1) {
        *stateFlags = *stateFlags | 0x800000;
        src1Word0 = inst[4];
      }
      src1Word0 = src1Word0 >> 0xc & 3;
      if (src1Word0 == 0) {
        copyIndex = 0;
        ch = s_MUL_97c2e4f0[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "MUL "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else if (src1Word0 == 1) {
        copyIndex = 0;
        ch = s_DP2_97c2e540[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "DP2 "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else if (src1Word0 == 2) {
        copyIndex = 0;
        ch = s_DP3_97c2e548[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "DP3 "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else {
        copyIndex = 0;
        ch = s_DP4_97c2e550[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "DP4 "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ";\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x2b:
    *stateFlags = *stateFlags | 1;
    copyIndex = 0;
    ch = s_ADD_scratch__97c2e7e0[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "ADD scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,1);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = outCursor + copyIndex;
    sourceMode = inst[4] >> 0xc & 3;
    if (sourceMode == 1) {
      copyIndex = 0;
      ch = s_SWZ_scratch__scratch__x__y__0__0_97c2e7f0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "SWZ scratch, scratch, x, y, 0, 0;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = outCursor + copyIndex;
      copyIndex = 0;
      ch = s_DP3_scratch_x__scratch__scratch__97c2e7bc[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "DP3 scratch.x, scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    else if (sourceMode == 0) {
      copyIndex = 0;
      ch = s_MUL_scratch_x__scratch_x__scratc_97c2e814[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "MUL scratch.x, scratch.x, scratch.x;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    else if (sourceMode == 2) {
      copyIndex = 0;
      ch = s_DP3_scratch_x__scratch__scratch__97c2e7bc[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "DP3 scratch.x, scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    else {
      copyIndex = 0;
      ch = s_DP4_scratch_x__scratch__scratch__97c2e83c[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "DP4 scratch.x, scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    copyIndex2 = 0;
    ch = s_RSQ_scratch_x__scratch_x__97c2e754[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "RSQ scratch.x, scratch.x;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_RCP_97c2e58c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "RCP "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch_x__97c2e594[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ", scratch.x;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x2c:
  case 0x2d:
    copyIndex9 = 0;
    mnemonic = *(char **)(PTR__ppstreamOpString_a7b7c108 + opOffsetOrTailLength);
    ch = *mnemonic;
    while (ch != '\0') {
      *(char *)(outText + copyIndex9) = ch;
      copyIndex9 = copyIndex9 + 1;
      ch = mnemonic[copyIndex9];
    }
    copyIndex = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex9 + copyIndex) = ch;
      ch = " "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex9 + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x2e:
  case 0x32:
  case 0x35:
    copyIndex9 = 0;
    mnemonic = *(char **)(PTR__ppstreamOpString_a7b7c108 + opOffsetOrTailLength);
    ch = *mnemonic;
    while (ch != '\0') {
      *(char *)(outText + copyIndex9) = ch;
      copyIndex9 = copyIndex9 + 1;
      ch = mnemonic[copyIndex9];
    }
    copyIndex = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex9 + copyIndex) = ch;
      ch = " "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex9 + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x2f:
    *stateFlags = *stateFlags | 1;
    if ((inst[2] >> 10 & 3) == 2) {
      copyIndex = 0;
      ch = s_DP3_scratch_x__97c2e734[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "DP3 scratch.x, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    else {
      copyIndex = 0;
      ch = s_DP4_scratch_x__97c2e744[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "DP4 scratch.x, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,0);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_MUL_scratch__97c2e62c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "MUL scratch, "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex + copyIndex2,paramNumbers,paramArrayPos,3,0,0,0);
    copyIndex = 0;
    ch = s___scratch_x__97c2e594[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", scratch.x;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_ADD_scratch__scratch__scratch__97c2e770[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "ADD scratch, scratch, scratch;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_ADD_97c2e6d4[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "ADD "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s____scratch_97c2e790[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", -scratch"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteComponentsWithDestinationSwizzle)(inst,outCursor + copyIndex);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x31:
    if (((inst[4] & 0x4000) == 0) && ((inst[6] & 0x4000) == 0)) {
      if ((((stateFlags[1] & 0x100000) == 0) || (shaderType != 0x8b31)) &&
         (((stateFlags[1] & 0x400000) == 0 || (shaderType != 0x8b30)))) {
        *stateFlags = *stateFlags | 0x1001;
        copyIndex = 0;
        ch = s_SUB_scratch__97c2e870[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "SUB scratch, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,8);
        copyIndex = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ";\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        copyIndex2 = 0;
        ch = s_ABS_scratch__scratch__97c2e8c0[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex + copyIndex2) = ch;
          ch = "ABS scratch, scratch;\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor2 = outCursor + copyIndex + copyIndex2;
        copyIndex = 0;
        ch = s_SGE_97c2e91c[0];
        while (ch != '\0') {
          *(char *)(outCursor2 + copyIndex) = ch;
          ch = "SGE "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
        opOffsetOrTailLength = 0;
        ch = s____scratch__kZERO__97c2e460[0];
        while (ch != '\0') {
          *(char *)(outStart + opOffsetOrTailLength) = ch;
          ch = ", -scratch, kZERO;\n"[opOffsetOrTailLength + 1];
          opOffsetOrTailLength = opOffsetOrTailLength + 1;
        }
      }
      else {
        if (shaderType == 0x8b31) {
          flagWord = *stateFlags | 0x100000;
        }
        else {
          flagWord = *stateFlags | 0x400000;
        }
        *stateFlags = flagWord;
        copyIndex = 0;
        ch = s_SEQ_97c2e924[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "SEQ "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,8);
        opOffsetOrTailLength = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outStart + opOffsetOrTailLength) = ch;
          ch = ";\n"[opOffsetOrTailLength + 1];
          opOffsetOrTailLength = opOffsetOrTailLength + 1;
        }
      }
    }
    else {
      *stateFlags = *stateFlags | 3;
      src1Word0 = inst[4];
      if ((src1Word0 & 0x4000) == 0) {
        src1Word0 = inst[6];
      }
      src1Word0 = src1Word0 >> 0xc & 3;
      loopIndex2 = 0;
      outBase = outText;
      do {
        isFirstRow = loopIndex2 == 0;
        if (isFirstRow) {
          copyIndex2 = 0;
          ch = s_SUB_scratch__97c2e870[0];
          while (ch != '\0') {
            *(char *)(outBase + copyIndex2) = ch;
            ch = "SUB scratch, "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        else {
          copyIndex2 = 0;
          ch = s_SUB_scratch1__97c2e860[0];
          while (ch != '\0') {
            *(char *)(outBase + copyIndex2) = ch;
            ch = "SUB scratch1, "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        swizzleSelect3 = loopIndex2;
        if ((inst[4] & 0x4000) == 0) {
          swizzleSelect3 = 0;
        }
        outCursor7 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outBase + copyIndex2,paramNumbers,paramArrayPos,2,swizzleSelect3,0,0)
        ;
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor7 + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        swizzleSelect3 = loopIndex2;
        if ((inst[6] & 0x4000) == 0) {
          swizzleSelect3 = 0;
        }
        outCursor3 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor7 + copyIndex,paramNumbers,paramArrayPos,3,swizzleSelect3,0,0);
        copyIndex2 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor3 + copyIndex2) = ch;
          ch = ";\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor3 = outCursor3 + copyIndex2;
        if (isFirstRow) {
          copyIndex2 = 0;
          ch = s_ABS_scratch__scratch__97c2e8c0[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex2) = ch;
            ch = "ABS scratch, scratch;\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        else {
          copyIndex2 = 0;
          ch = s_ABS_scratch1__scratch1__97c2e880[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex2) = ch;
            ch = "ABS scratch1, scratch1;\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        outBase = outCursor3 + copyIndex2;
        if (!isFirstRow) {
          copyIndex2 = 0;
          ch = s_ADD_scratch__scratch__scratch1__97c2e89c[0];
          while (ch != '\0') {
            *(char *)(outBase + copyIndex2) = ch;
            ch = "ADD scratch, scratch, scratch1;\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outBase = outBase + copyIndex2;
        }
        loopIndex2 = loopIndex2 + 1;
      } while (loopIndex2 <= (int)src1Word0);
      copyIndex3 = 0;
      ch = s_DP4_scratch__scratch__97c2e8d8[0];
      while (ch != '\0') {
        *(char *)(outBase + copyIndex3) = ch;
        ch = "DP4 scratch, scratch, "[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outCursor3 = outBase + copyIndex3;
      if (src1Word0 == 1) {
        *stateFlags = *stateFlags | 0x1000;
        copyIndex3 = 0;
        ch = s_kVEC2_97c2e8f0[0];
        while (ch != '\0') {
          *(char *)(outCursor3 + copyIndex3) = ch;
          ch = "kVEC2"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
LAB_97bf9b6c:
        outCursor3 = outCursor3 + copyIndex3;
      }
      else {
        if (src1Word0 == 2) {
          *stateFlags = *stateFlags | 0x1000;
          copyIndex3 = 0;
          ch = s_kVEC3_97c2e8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex3) = ch;
            ch = "kVEC3"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          goto LAB_97bf9b6c;
        }
        if (src1Word0 == 3) {
          *stateFlags = *stateFlags | 0x1000;
          copyIndex3 = 0;
          ch = s_kVEC4_97c2e900[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex3) = ch;
            ch = "kVEC4"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          goto LAB_97bf9b6c;
        }
      }
      copyIndex3 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor3 + copyIndex3) = ch;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      copyIndex2 = 0;
      ch = s_ABS_scratch__scratch__97c2e8c0[0];
      while (ch != '\0') {
        *(char *)(outCursor3 + copyIndex3 + copyIndex2) = ch;
        ch = "ABS scratch, scratch;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor3 + copyIndex3 + copyIndex2;
      copyIndex = 0;
      ch = s_SGE_97c2e91c[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SGE "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s____scratch__kZERO__97c2e460[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ", -scratch, kZERO;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x33:
    copyIndex = 0;
    ch = s_SLT_97c2e458[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "SLT "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,1);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,1);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x34:
    copyIndex = 0;
    ch = s_SGE_97c2e91c[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "SGE "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,1);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,1);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x36:
    if (((inst[4] & 0x4000) == 0) && ((inst[6] & 0x4000) == 0)) {
      if ((((stateFlags[1] & 0x100000) == 0) || (shaderType != 0x8b31)) &&
         (((stateFlags[1] & 0x400000) == 0 || (shaderType != 0x8b30)))) {
        *stateFlags = *stateFlags | 0x1001;
        copyIndex = 0;
        ch = s_SUB_scratch__97c2e870[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "SUB scratch, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,0);
        copyIndex = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ";\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        copyIndex2 = 0;
        ch = s_ABS_scratch__scratch__97c2e8c0[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex + copyIndex2) = ch;
          ch = "ABS scratch, scratch;\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor2 = outCursor + copyIndex + copyIndex2;
        copyIndex = 0;
        ch = s_SLT_97c2e458[0];
        while (ch != '\0') {
          *(char *)(outCursor2 + copyIndex) = ch;
          ch = "SLT "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
        opOffsetOrTailLength = 0;
        ch = s____scratch__kZERO__97c2e460[0];
        while (ch != '\0') {
          *(char *)(outStart + opOffsetOrTailLength) = ch;
          ch = ", -scratch, kZERO;\n"[opOffsetOrTailLength + 1];
          opOffsetOrTailLength = opOffsetOrTailLength + 1;
        }
      }
      else {
        if (shaderType == 0x8b31) {
          flagWord = *stateFlags | 0x100000;
        }
        else {
          flagWord = *stateFlags | 0x400000;
        }
        *stateFlags = flagWord;
        copyIndex = 0;
        ch = s_SNE_97c2e908[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "SNE "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,8);
        opOffsetOrTailLength = 0;
        ch = s_____end_97c2e910[0];
        while (ch != '\0') {
          *(char *)(outStart + opOffsetOrTailLength) = ch;
          ch = ";\n# end\n"[opOffsetOrTailLength + 1];
          opOffsetOrTailLength = opOffsetOrTailLength + 1;
        }
      }
    }
    else {
      *stateFlags = *stateFlags | 3;
      src1Word0 = inst[4];
      if ((src1Word0 & 0x4000) == 0) {
        src1Word0 = inst[6];
      }
      src1Word0 = src1Word0 >> 0xc & 3;
      loopIndex2 = 0;
      outBase = outText;
      do {
        isFirstRow = loopIndex2 == 0;
        if (isFirstRow) {
          copyIndex2 = 0;
          ch = s_SUB_scratch__97c2e870[0];
          while (ch != '\0') {
            *(char *)(outBase + copyIndex2) = ch;
            ch = "SUB scratch, "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        else {
          copyIndex2 = 0;
          ch = s_SUB_scratch1__97c2e860[0];
          while (ch != '\0') {
            *(char *)(outBase + copyIndex2) = ch;
            ch = "SUB scratch1, "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        swizzleSelect3 = loopIndex2;
        if ((inst[4] & 0x4000) == 0) {
          swizzleSelect3 = 0;
        }
        outCursor7 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outBase + copyIndex2,paramNumbers,paramArrayPos,2,swizzleSelect3,0,0)
        ;
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor7 + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        swizzleSelect3 = loopIndex2;
        if ((inst[6] & 0x4000) == 0) {
          swizzleSelect3 = 0;
        }
        outCursor3 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor7 + copyIndex,paramNumbers,paramArrayPos,3,swizzleSelect3,0,0);
        copyIndex2 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor3 + copyIndex2) = ch;
          ch = ";\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor3 = outCursor3 + copyIndex2;
        if (isFirstRow) {
          copyIndex2 = 0;
          ch = s_ABS_scratch__scratch__97c2e8c0[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex2) = ch;
            ch = "ABS scratch, scratch;\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        else {
          copyIndex2 = 0;
          ch = s_ABS_scratch1__scratch1__97c2e880[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex2) = ch;
            ch = "ABS scratch1, scratch1;\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
        }
        outBase = outCursor3 + copyIndex2;
        if (!isFirstRow) {
          copyIndex2 = 0;
          ch = s_ADD_scratch__scratch__scratch1__97c2e89c[0];
          while (ch != '\0') {
            *(char *)(outBase + copyIndex2) = ch;
            ch = "ADD scratch, scratch, scratch1;\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outBase = outBase + copyIndex2;
        }
        loopIndex2 = loopIndex2 + 1;
      } while (loopIndex2 <= (int)src1Word0);
      copyIndex3 = 0;
      ch = s_DP4_scratch__scratch__97c2e8d8[0];
      while (ch != '\0') {
        *(char *)(outBase + copyIndex3) = ch;
        ch = "DP4 scratch, scratch, "[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      outCursor3 = outBase + copyIndex3;
      if (src1Word0 == 1) {
        *stateFlags = *stateFlags | 0x1000;
        copyIndex3 = 0;
        ch = s_kVEC2_97c2e8f0[0];
        while (ch != '\0') {
          *(char *)(outCursor3 + copyIndex3) = ch;
          ch = "kVEC2"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
LAB_97bf9370:
        outCursor3 = outCursor3 + copyIndex3;
      }
      else {
        if (src1Word0 == 2) {
          *stateFlags = *stateFlags | 0x1000;
          copyIndex3 = 0;
          ch = s_kVEC3_97c2e8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex3) = ch;
            ch = "kVEC3"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          goto LAB_97bf9370;
        }
        if (src1Word0 == 3) {
          *stateFlags = *stateFlags | 0x1000;
          copyIndex3 = 0;
          ch = s_kVEC4_97c2e900[0];
          while (ch != '\0') {
            *(char *)(outCursor3 + copyIndex3) = ch;
            ch = "kVEC4"[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          goto LAB_97bf9370;
        }
      }
      copyIndex3 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor3 + copyIndex3) = ch;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      copyIndex2 = 0;
      ch = s_ABS_scratch__scratch__97c2e8c0[0];
      while (ch != '\0') {
        *(char *)(outCursor3 + copyIndex3 + copyIndex2) = ch;
        ch = "ABS scratch, scratch;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor3 + copyIndex3 + copyIndex2;
      copyIndex = 0;
      ch = s_SLT_97c2e458[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SLT "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s____scratch__kZERO__97c2e460[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ", -scratch, kZERO;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x38:
    writeMaskBits = inst[2];
    writeMaskBits2 = writeMaskBits >> 0xd & 0xf;
    loopIndex3 = 0;
    do {
      if ((writeMaskBits2 & 1) != 0) {
        mnemonic = *(char **)(opStringTable + opOffsetOrTailLength);
        copyIndex10 = 0;
        ch = *mnemonic;
        while (ch != '\0') {
          *(char *)(outStart + copyIndex10) = ch;
          copyIndex10 = copyIndex10 + 1;
          ch = mnemonic[copyIndex10];
        }
        copyIndex5 = 0;
        ch = s__97c291c0[0];
        while (ch != '\0') {
          *(char *)(outStart + copyIndex10 + copyIndex5) = ch;
          ch = " "[copyIndex5 + 1];
          copyIndex5 = copyIndex5 + 1;
        }
        outCursor4 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outStart + copyIndex10 + copyIndex5,0,loopIndex3,2);
        copyIndex3 = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor4 + copyIndex3) = ch;
          ch = ", "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor4 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor4 + copyIndex3,paramNumbers,paramArrayPos,2,0,loopIndex3,10);
        copyIndex3 = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor4 + copyIndex3) = ch;
          ch = ", "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor4 + copyIndex3,paramNumbers,paramArrayPos,3,0,loopIndex3,10)
        ;
        copyIndex4 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor6 + copyIndex4) = ch;
          ch = ";\n"[copyIndex4 + 1];
          copyIndex4 = copyIndex4 + 1;
        }
        writeMaskBits = inst[2];
        outStart = outCursor6 + copyIndex4;
      }
      loopIndex3 = loopIndex3 + 1;
      writeMaskBits2 = (int)writeMaskBits2 >> 1;
    } while (loopIndex3 <= (int)(writeMaskBits >> 10 & 3));
    goto LAB_97c01788;
  case 0x39:
    *stateFlags = *stateFlags | 0x1001;
    copyIndex = 0;
    ch = s_SUB_scratch__kSEL__97c2f620[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "SUB scratch, kSEL, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,3,0,0,0);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_ABS_scratch__scratch__97c2e8c0[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "ABS scratch, scratch;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_SGE_scratch___scratch__kZERO__97c2f634[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "SGE scratch, -scratch, kZERO;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_DP4_97c2e550[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "DP4 "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___scratch__97c2e570[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x3a:
    *stateFlags = *stateFlags | 1;
    if (((inst[4] & 0x4000) == 0) || ((inst[6] & 0x4000) == 0)) {
      if ((inst[4] & 0x4000) == 0) {
        if ((inst[6] & 0x4000) == 0) {
          if ((inst[6] & 0x3000) == 0) {
            copyIndex = 0;
            ch = s_RCP_scratch__97c2e600[0];
            while (ch != '\0') {
              *(char *)(outText + copyIndex) = ch;
              ch = "RCP scratch, "[copyIndex + 1];
              copyIndex = copyIndex + 1;
            }
            outCursor3 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,3,0,0,0);
            copyIndex3 = 0;
            ch = s___97c2d8f8[0];
            while (ch != '\0') {
              *(char *)(outCursor3 + copyIndex3) = ch;
              ch = ";\n"[copyIndex3 + 1];
              copyIndex3 = copyIndex3 + 1;
            }
            outBase = outCursor3 + copyIndex3;
          }
          else {
            writeMaskBits = inst[2];
            writeMaskBits2 = writeMaskBits >> 0xd & 0xf;
            loopIndex2 = 0;
            outBase = outText;
            do {
              if ((writeMaskBits2 & 1) != 0) {
                copyIndex2 = 0;
                ch = s_RCP_scratch__97c2e5f0[0];
                while (ch != '\0') {
                  *(char *)(outBase + copyIndex2) = ch;
                  ch = "RCP scratch."[copyIndex2 + 1];
                  copyIndex2 = copyIndex2 + 1;
                }
                outPtr = (char *)(outBase + copyIndex2);
                *outPtr = ((char)loopIndex2 + 1U & 3) + 0x77;
                copyIndex = 0;
                ch = s___97c2d7ec[0];
                while (ch != '\0') {
                  outPtr[copyIndex + 1] = ch;
                  ch = ", "[copyIndex + 1];
                  copyIndex = copyIndex + 1;
                }
                outCursor3 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outPtr + copyIndex + 1,paramNumbers,paramArrayPos,3,0,loopIndex2,10);
                copyIndex2 = 0;
                ch = s___97c2d8f8[0];
                while (ch != '\0') {
                  *(char *)(outCursor3 + copyIndex2) = ch;
                  ch = ";\n"[copyIndex2 + 1];
                  copyIndex2 = copyIndex2 + 1;
                }
                writeMaskBits = inst[2];
                outBase = outCursor3 + copyIndex2;
              }
              loopIndex2 = loopIndex2 + 1;
              writeMaskBits2 = (int)writeMaskBits2 >> 1;
            } while (loopIndex2 <= (int)(writeMaskBits >> 10 & 3));
          }
          copyIndex3 = 0;
          ch = s_MUL_97c2e4f0[0];
          while (ch != '\0') {
            *(char *)(outBase + copyIndex3) = ch;
            ch = "MUL "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outBase + copyIndex3,0,0,0);
          copyIndex = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex) = ch;
            ch = ", "[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
          opOffsetOrTailLength = 0;
          ch = s___scratch__97c2e620[0];
          while (ch != '\0') {
            *(char *)(outStart + opOffsetOrTailLength) = ch;
            ch = ", scratch;\n"[opOffsetOrTailLength + 1];
            opOffsetOrTailLength = opOffsetOrTailLength + 1;
          }
          break;
        }
        loopIndex = 0;
        do {
          outLen2 = 0;
          do {
            copyIndex4 = 0;
            ch = s_RCP_scratch__97c2e5f0[0];
            while (ch != '\0') {
              *(char *)(outStart + copyIndex4) = ch;
              ch = "RCP scratch."[copyIndex4 + 1];
              copyIndex4 = copyIndex4 + 1;
            }
            nextComponent2 = outLen2 + 1;
            outPtr = (char *)(outStart + copyIndex4);
            *outPtr = ((byte)nextComponent2 & 3) + 0x77;
            copyIndex3 = 0;
            ch = s___97c2d7ec[0];
            while (ch != '\0') {
              outPtr[copyIndex3 + 1] = ch;
              ch = ", "[copyIndex3 + 1];
              copyIndex3 = copyIndex3 + 1;
            }
            outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outPtr + copyIndex3 + 1,paramNumbers,paramArrayPos,3,loopIndex,outLen2,2);
            copyIndex2 = 0;
            ch = s___97c2d8f8[0];
            while (ch != '\0') {
              *(char *)(outCursor + copyIndex2) = ch;
              ch = ";\n"[copyIndex2 + 1];
              copyIndex2 = copyIndex2 + 1;
            }
            outStart = outCursor + copyIndex2;
            outLen2 = nextComponent2;
          } while (nextComponent2 <= (int)(inst[6] >> 0xc & 3));
          copyIndex2 = 0;
          ch = s_MUL_97c2e4f0[0];
          while (ch != '\0') {
            *(char *)(outStart + copyIndex2) = ch;
            ch = "MUL "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outStart + copyIndex2,loopIndex,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,2,0,0,0);
          copyIndex2 = 0;
          ch = s___scratch__97c2e5e0[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex2) = ch;
            ch = ", scratch; \n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          loopIndex = loopIndex + 1;
          outStart = outCursor + copyIndex2;
        } while (loopIndex <= (int)(inst[6] >> 0xc & 3));
      }
      else {
        copyIndex = 0;
        ch = s_RCP_scratch__97c2e600[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "RCP scratch, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,3,0,0,0);
        copyIndex = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ";\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outStart = outCursor + copyIndex;
        loopIndex = 0;
        do {
          copyIndex2 = 0;
          ch = s_MUL_97c2e4f0[0];
          while (ch != '\0') {
            *(char *)(outStart + copyIndex2) = ch;
            ch = "MUL "[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outStart + copyIndex2,loopIndex,0,0);
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            *(char *)(outCursor2 + copyIndex3) = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,2,loopIndex,0,0);
          copyIndex2 = 0;
          ch = s___scratch_x__97c2e610[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex2) = ch;
            ch = ", scratch.x; \n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          loopIndex = loopIndex + 1;
          outStart = outCursor + copyIndex2;
        } while (loopIndex <= (int)(inst[2] >> 10 & 3));
      }
    }
    else {
      loopIndex = 0;
      do {
        outLen2 = 0;
        do {
          copyIndex4 = 0;
          ch = s_RCP_scratch__97c2e5f0[0];
          while (ch != '\0') {
            *(char *)(outStart + copyIndex4) = ch;
            ch = "RCP scratch."[copyIndex4 + 1];
            copyIndex4 = copyIndex4 + 1;
          }
          nextComponent2 = outLen2 + 1;
          outPtr = (char *)(outStart + copyIndex4);
          *outPtr = ((byte)nextComponent2 & 3) + 0x77;
          copyIndex3 = 0;
          ch = s___97c2d7ec[0];
          while (ch != '\0') {
            outPtr[copyIndex3 + 1] = ch;
            ch = ", "[copyIndex3 + 1];
            copyIndex3 = copyIndex3 + 1;
          }
          outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outPtr + copyIndex3 + 1,paramNumbers,paramArrayPos,3,loopIndex,outLen2,2);
          copyIndex2 = 0;
          ch = s___97c2d8f8[0];
          while (ch != '\0') {
            *(char *)(outCursor + copyIndex2) = ch;
            ch = ";\n"[copyIndex2 + 1];
            copyIndex2 = copyIndex2 + 1;
          }
          outStart = outCursor + copyIndex2;
          outLen2 = nextComponent2;
        } while (nextComponent2 <= (int)(inst[6] >> 0xc & 3));
        copyIndex2 = 0;
        ch = s_MUL_97c2e4f0[0];
        while (ch != '\0') {
          *(char *)(outStart + copyIndex2) = ch;
          ch = "MUL "[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outStart + copyIndex2,loopIndex,0,0);
        copyIndex3 = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor2 + copyIndex3) = ch;
          ch = ", "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,2,loopIndex,0,0);
        copyIndex2 = 0;
        ch = s___scratch__97c2e5e0[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex2) = ch;
          ch = ", scratch; \n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        loopIndex = loopIndex + 1;
        outStart = outCursor + copyIndex2;
      } while (loopIndex <= (int)(inst[6] >> 0xc & 3));
    }
    goto LAB_97c01788;
  case 0x3b:
    *stateFlags = *stateFlags | 0x1001;
    src3SizeMinusOne = inst[8] >> 0xc & 3;
    if (src3SizeMinusOne == 1) {
      copyIndex = 0;
      ch = s_SWZ_scratch__97c2e79c[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "SWZ scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      typeTextLength = ((int (*)())_glpSourceType)(inst,outText + copyIndex,paramNumbers,paramArrayPos,4,0,0);
      copyIndex = 0;
      ch = s___x__y__0__0__97c2e7ac[0];
      while (ch != '\0') {
        *(char *)(typeTextLength + copyIndex) = ch;
        ch = ", x, y, 0, 0;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_DP3_scratch_x__scratch__97c2ea1c[0];
      while (ch != '\0') {
        *(char *)(typeTextLength + copyIndex + copyIndex2) = ch;
        ch = "DP3 scratch.x, scratch, "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,typeTextLength + copyIndex + copyIndex2,paramNumbers,paramArrayPos,3,0,0,0);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    else {
      if (src3SizeMinusOne == 0) {
        copyIndex = 0;
        ch = s_MUL_scratch_x__97c2e6fc[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "MUL scratch.x, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else if (src3SizeMinusOne == 2) {
        copyIndex = 0;
        ch = s_DP3_scratch_x__97c2e734[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "DP3 scratch.x, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      else {
        copyIndex = 0;
        ch = s_DP4_scratch_x__97c2e744[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "DP4 scratch.x, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,4,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,0);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
    }
    copyIndex2 = 0;
    ch = s_SLT_scratch__scratch_x__kZERO__97c2ea38[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "SLT scratch, scratch.x, kZERO;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_MAD_scratch__scratch__kTWO___kON_97c2ea58[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MAD scratch, scratch, kTWO, -kONE;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MUL_97c2e4f0[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MUL "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___scratch__97c2e570[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x3c:
    if (shaderType == 0x8b30) {
      copyIndex = 0;
      ch = s_LRP_97c2e9e4[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "LRP "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,8);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,4,0,0,8);
      opOffsetOrTailLength = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ";\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      *stateFlags = *stateFlags | 1;
      copyIndex = 0;
      ch = s_MAD_scratch__97c2e64c[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "MAD scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,4,0,0,8);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,9);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,4,0,0,8);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_MAD_97c2e644[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "MAD "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,8);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
      opOffsetOrTailLength = 0;
      ch = s___scratch__97c2e620[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ", scratch;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x3d:
    *stateFlags = *stateFlags | 1;
    copyIndex = 0;
    ch = s_MAX_scratch__97c2e558[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "MAX scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,8);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_MIN_97c2e568[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "MIN "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
    copyIndex = 0;
    ch = s___scratch__97c2e570[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,4,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x3e:
    if (shaderType == 0x8b30) {
      copyIndex = 0;
      ch = s_CMP_97c2f81c[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "CMP "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,4,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ";\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      *stateFlags = *stateFlags | 0x1001;
      copyIndex = 0;
      ch = s_SLT_scratch__97c2e474[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "SLT scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
      copyIndex = 0;
      ch = s___kZERO__97c2e484[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = outCursor + copyIndex;
      if (shaderType == 0x8b30) {
        copyIndex = 0;
        ch = s_LRP_97c2e9e4[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = "LRP "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex,0,0,0);
        copyIndex = 0;
        ch = s___scratch__97c2e570[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", scratch, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,0);
        copyIndex = 0;
        ch = s___97c2d7ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,4,0,0,0);
        opOffsetOrTailLength = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outStart + opOffsetOrTailLength) = ch;
          ch = ";\n"[opOffsetOrTailLength + 1];
          opOffsetOrTailLength = opOffsetOrTailLength + 1;
        }
      }
      else {
        *stateFlags = *stateFlags | 0x1002;
        copyIndex = 0;
        ch = s_SUB_scratch1__kONE__scratch__97c2f668[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = "SUB scratch1, kONE, scratch;\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        copyIndex2 = 0;
        ch = s_MUL_scratch__scratch__97c2e9ec[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex + copyIndex2) = ch;
          ch = "MUL scratch, scratch, "[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex + copyIndex2,paramNumbers,paramArrayPos,3,0,0,0);
        copyIndex = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ";\n"[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        copyIndex2 = 0;
        ch = s_MAD_97c2e644[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex + copyIndex2) = ch;
          ch = "MAD "[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
        copyIndex = 0;
        ch = s___scratch1__97c2f688[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex) = ch;
          ch = ", scratch1, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
        outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,4,0,0,0);
        opOffsetOrTailLength = 0;
        ch = s___scratch__97c2e620[0];
        while (ch != '\0') {
          *(char *)(outStart + opOffsetOrTailLength) = ch;
          ch = ", scratch;\n"[opOffsetOrTailLength + 1];
          opOffsetOrTailLength = opOffsetOrTailLength + 1;
        }
      }
    }
    break;
  case 0x40:
    *stateFlags = *stateFlags | 0x1003;
    copyIndex = 0;
    ch = s_SUB_scratch__97c2e870[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "SUB scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,3,0,0,8);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outPtr = (char *)(outCursor + copyIndex);
    if ((inst[8] >> 0xc & 3) == 0) {
      copyIndex = 0;
      ch = s_RCP_scratch1_x__scratch_x__97c2ea7c[0];
      while (ch != '\0') {
        outPtr[copyIndex] = ch;
        ch = "RCP scratch1.x, scratch.x;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outPtr = outPtr + copyIndex;
    }
    else {
      loopIndex = 0;
      do {
        copyIndex3 = 0;
        ch = s_RCP_scratch1__97c2ea98[0];
        while (ch != '\0') {
          outPtr[copyIndex3] = ch;
          ch = "RCP scratch1."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        loopIndex = loopIndex + 1;
        outPtr = outPtr + copyIndex3;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___scratch__97c2eaa8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ", scratch."[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
        *outPtr = ((byte)loopIndex & 3) + 0x77;
        copyIndex3 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          outPtr[copyIndex3 + 1] = ch;
          ch = ";\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outPtr = outPtr + copyIndex3 + 1;
      } while (loopIndex <= (int)(inst[8] >> 0xc & 3));
    }
    copyIndex = 0;
    ch = s_SUB_scratch__97c2e870[0];
    while (ch != '\0') {
      outPtr[copyIndex] = ch;
      ch = "SUB scratch, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outPtr + copyIndex,paramNumbers,paramArrayPos,4,0,0,8);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_MUL_scratch__scratch__scratch1__97c2eab4[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "MUL scratch, scratch, scratch1;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_MAX_scratch__scratch__kZERO__97c2ead8[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MAX scratch, scratch, kZERO;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MIN_scratch__scratch__kONE__97c2eaf8[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MIN scratch, scratch, kONE;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_ADD_scratch1__scratch__scratch__97c2eb18[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "ADD scratch1, scratch, scratch;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_SUB_scratch1__kTHREE__scratch1__97c2eb3c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "SUB scratch1, kTHREE, scratch1;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MUL_scratch__scratch__scratch__97c2eb60[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MUL scratch, scratch, scratch;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MUL_97c2e4f0[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MUL "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch__scratch1__97c2e4f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ", scratch, scratch1;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x42:
  case 0x43:
  case 0x44:
    if (shaderType == 0x8b30) {
      stateFlags1 = stateFlags[1];
    }
    else {
      stateFlags1 = stateFlags[1];
      if ((stateFlags1 & 0x200000) == 0) {
        return 0xffffffff;
      }
      if (shaderType != 0x8b31) {
        return 0xffffffff;
      }
    }
    if (((stateFlags1 & 0x400000) == 0) || (shaderType != 0x8b30)) {
      if ((inst[8] >> 5 & 7) - 5 < 3) {
        return 0xffffffff;
      }
    }
    else {
      *stateFlags = *stateFlags | 0x1000000;
    }
    if (shaderType == 0x8b31) {
      *stateFlags = *stateFlags | 0x200000;
    }
    copyIndex9 = 0;
    mnemonic = *(char **)(PTR__ppstreamOpString_a7b7c108 + opOffsetOrTailLength);
    ch = *mnemonic;
    while (ch != '\0') {
      *(char *)(outText + copyIndex9) = ch;
      copyIndex9 = copyIndex9 + 1;
      ch = mnemonic[copyIndex9];
    }
    copyIndex = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex9 + copyIndex) = ch;
      ch = " "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex9 + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteTextureOperand_97bf37b4)(inst,outCursor + copyIndex,4,optionFlags);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x48:
    if (shaderType != 0x8b31) {
      return 0xffffffff;
    }
    copyIndex = 0;
    ch = s_ARL_97c2f7e4[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "ARL "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x4d:
    outStart = 0;
    copyIndex12 = outStart;
    ch = s__97c26c38[0];
    if (s__97c26c38[0] != '\0') {
      do {
        *(char *)(outText + copyIndex12) = ch;
        outStart = copyIndex12 + 1;
        ch = "\n"[copyIndex12 + 1];
        copyIndex12 = outStart;
      } while (ch != '\0');
      instWord0 = *inst;
    }
    outStart = outText + outStart;
    goto LAB_97c0178c;
  case 0x4f:
    copyIndex9 = 0;
    mnemonic = *(char **)(PTR__ppstreamOpString_a7b7c108 + opOffsetOrTailLength);
    ch = *mnemonic;
    while (ch != '\0') {
      *(char *)(outText + copyIndex9) = ch;
      copyIndex9 = copyIndex9 + 1;
      ch = mnemonic[copyIndex9];
    }
    copyIndex = 0;
    ch = s__97c291c0[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex9 + copyIndex) = ch;
      ch = " "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex9 + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x50:
    if ((stateFlags[1] & 0x400000) == 0) {
      return 0xffffffff;
    }
    if (shaderType != 0x8b30) {
      return 0xffffffff;
    }
    *stateFlags = *stateFlags | 0x400000;
    copyIndex = 0;
    ch = s_DDX_97c2f7ec[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "DDX "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x51:
    if ((stateFlags[1] & 0x400000) == 0) {
      return 0xffffffff;
    }
    if (shaderType != 0x8b30) {
      return 0xffffffff;
    }
    *stateFlags = *stateFlags | 0x400000;
    copyIndex = 0;
    ch = s_DDY_97c2f7f4[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "DDY "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x57:
    if ((stateFlags[1] & 0x800000) == 0) {
      return 0xffffffff;
    }
    if (shaderType != 0x8b30) {
      return 0xffffffff;
    }
    *stateFlags = *stateFlags | 0x800000;
    copyIndex = 0;
    ch = s_REP_97c2f824[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "REP "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ";\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x5b:
    if ((stateFlags[1] & 0x800000) == 0) {
      return 0xffffffff;
    }
    if (shaderType != 0x8b30) {
      return 0xffffffff;
    }
    *stateFlags = *stateFlags | 0x800000;
    copyIndex3 = 0;
    ch = s_ENDREP__97c2f82c[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex3) = ch;
      ch = "ENDREP;\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    outStart = outText + copyIndex3;
    goto LAB_97c01788;
  case 0x68:
    *stateFlags = *stateFlags | 0x1007;
    sizeMinusOne = inst[2] >> 10 & 3;
    if (sizeMinusOne == 1) {
      copyIndex = 0;
      ch = s_MUL_scratch_xy__97c2e510[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "MUL scratch.xy, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,0);
      copyIndex3 = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex3) = ch;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyIndex3 + 1;
      }
      copyIndex = 0;
      ch = s_MUL_scratch__scratch_x__scratch__97c2f6b4[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex3 + copyIndex) = ch;
        ch = "MUL scratch, scratch.x, scratch.y;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor3 = outCursor2 + copyIndex3 + copyIndex;
    }
    else {
      if (sizeMinusOne == 0) {
        copyIndex = 0;
        ch = s_MUL_scratch__97c2e62c[0];
        while (ch != '\0') {
          *(char *)(outText + copyIndex) = ch;
          ch = "MUL scratch, "[copyIndex + 1];
          copyIndex = copyIndex + 1;
        }
LAB_97c00620:
        outBase = outText + copyIndex;
      }
      else {
        if (sizeMinusOne == 2) {
          copyIndex = 0;
          ch = s_DP3_scratch__97c2f6d8[0];
          while (ch != '\0') {
            *(char *)(outText + copyIndex) = ch;
            ch = "DP3 scratch, "[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          goto LAB_97c00620;
        }
        outBase = outText;
        if (sizeMinusOne == 3) {
          copyIndex = 0;
          ch = s_DP4_scratch__97c2f6e8[0];
          while (ch != '\0') {
            *(char *)(outText + copyIndex) = ch;
            ch = "DP4 scratch, "[copyIndex + 1];
            copyIndex = copyIndex + 1;
          }
          goto LAB_97c00620;
        }
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outBase,paramNumbers,paramArrayPos,2,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor3 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,0);
    }
    copyIndex3 = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor3 + copyIndex3) = ch;
      ch = ";\n"[copyIndex3 + 1];
      copyIndex3 = copyIndex3 + 1;
    }
    copyIndex2 = 0;
    ch = s_MAD_scratch1__scratch___scratch__97c2f6f8[0];
    while (ch != '\0') {
      *(char *)(outCursor3 + copyIndex3 + copyIndex2) = ch;
      ch = "MAD scratch1, scratch, -scratch, kONE;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor3 + copyIndex3 + copyIndex2;
    copyIndex = 0;
    ch = s_MUL_scratch2__97c2ef7c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MUL scratch2, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,paramNumbers,paramArrayPos,4,0,0,0);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,4,0,0,0);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_MAD_scratch1__scratch2___scratch_97c2f720[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "MAD scratch1, scratch2, -scratch1, kONE;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_RSQ_scratch2__scratch1_x__97c2f74c[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "RSQ scratch2, scratch1.x;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_RCP_scratch2__scratch2_x__97c2f768[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "RCP scratch2, scratch2.x;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor2 = outCursor2 + copyIndex;
    copyIndex = 0;
    ch = s_MAD_scratch2__scratch_x__97c2f784[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MAD scratch2, scratch.x, "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,paramNumbers,paramArrayPos,4,0,0,8);
    copyIndex = 0;
    ch = s___scratch2_x__97c2f7a0[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", scratch2.x;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_MUL_scratch2__97c2ef7c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "MUL scratch2, "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex + copyIndex2,paramNumbers,paramArrayPos,3,0,0,8);
    copyIndex = 0;
    ch = s___scratch2_x__97c2f7a0[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", scratch2.x;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_MAD_scratch__97c2e64c[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "MAD scratch, "[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex + copyIndex2,paramNumbers,paramArrayPos,2,0,0,8);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,4,0,0,8);
    copyIndex = 0;
    ch = s____scratch2__97c2f7b0[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", -scratch2;\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    copyIndex2 = 0;
    ch = s_SGE_scratch1__scratch1_x__kZERO__97c2f7c0[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex + copyIndex2) = ch;
      ch = "SGE scratch1, scratch1.x, kZERO;\n"[copyIndex2 + 1];
      copyIndex2 = copyIndex2 + 1;
    }
    outCursor2 = outCursor + copyIndex + copyIndex2;
    copyIndex = 0;
    ch = s_MUL_97c2e4f0[0];
    while (ch != '\0') {
      *(char *)(outCursor2 + copyIndex) = ch;
      ch = "MUL "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
    opOffsetOrTailLength = 0;
    ch = s___scratch__scratch1__97c2e4f8[0];
    while (ch != '\0') {
      *(char *)(outStart + opOffsetOrTailLength) = ch;
      ch = ", scratch, scratch1;\n"[opOffsetOrTailLength + 1];
      opOffsetOrTailLength = opOffsetOrTailLength + 1;
    }
    break;
  case 0x6c:
    valueType = inst[1] >> 0x17 & 7;
    if (valueType == 4) {
      *stateFlags = *stateFlags | 0x1001;
      copyIndex = 0;
      ch = s_ABS_scratch__97c2e448[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "ABS scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_SLT_97c2e458[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "SLT "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s____scratch__kZERO__97c2e460[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ", -scratch, kZERO;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else if (valueType == 3) {
      *stateFlags = *stateFlags | 0x1003;
      copyIndex = 0;
      ch = s_SLT_scratch__97c2e474[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "SLT scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outText + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
      copyIndex = 0;
      ch = s___kZERO__97c2e484[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_SLT_scratch1__97c2e490[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "SLT scratch1, "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex + copyIndex2,paramNumbers,paramArrayPos,2,0,0,9);
      copyIndex = 0;
      ch = s___kZERO__97c2e484[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", kZERO;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_ADD_scratch___scratch__scratch1__97c2e4a0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "ADD scratch, -scratch, scratch1;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_ABS_scratch1__97c2e4c4[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "ABS scratch1, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_FLR_scratch1__scratch1__97c2e4d4[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "FLR scratch1, scratch1;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_MUL_97c2e4f0[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor2 + copyIndex,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___scratch__scratch1__97c2e4f8[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ", scratch, scratch1;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      if (valueType != 1) goto LAB_97c0178c;
      copyIndex = 0;
      ch = s_MOV_97c2e430[0];
      while (ch != '\0') {
        *(char *)(outText + copyIndex) = ch;
        ch = "MOV "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outText + copyIndex,0,0,0);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,8);
      opOffsetOrTailLength = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ";\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x6d:
    if ((inst[2] >> 0x11 & 7) != 1) {
      return 0xffffffff;
    }
    *stateFlags = *stateFlags | 0x1001;
    copyIndex = 0;
    ch = s_SUB_scratch__kSEL_97c2f654[0];
    while (ch != '\0') {
      *(char *)(outText + copyIndex) = ch;
      ch = "SUB scratch, kSEL"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteComponentsWithDestinationSwizzle)(inst,outText + copyIndex);
    copyIndex = 0;
    ch = s___97c2d7ec[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ", "[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,3,0,0,0);
    copyIndex = 0;
    ch = s___97c2d8f8[0];
    while (ch != '\0') {
      *(char *)(outCursor + copyIndex) = ch;
      ch = ";\n"[copyIndex + 1];
      copyIndex = copyIndex + 1;
    }
    outCursor = outCursor + copyIndex;
    if (shaderType == 0x8b31) {
      *stateFlags = *stateFlags | 0x1002;
      copyIndex = 0;
      ch = s_ABS_scratch__scratch__97c2e8c0[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "ABS scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_SGE_scratch___scratch__kZERO__97c2f634[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "SGE scratch, -scratch, kZERO;\n"[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor2 = outCursor + copyIndex + copyIndex2;
      copyIndex = 0;
      ch = s_SUB_scratch1__kONE__scratch__97c2f668[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "SUB scratch1, kONE, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor2 = outCursor2 + copyIndex;
      copyIndex = 0;
      ch = s_MUL_scratch__scratch__97c2e9ec[0];
      while (ch != '\0') {
        *(char *)(outCursor2 + copyIndex) = ch;
        ch = "MUL scratch, scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
      copyIndex = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ";\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_MAD_97c2e644[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "MAD "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
      copyIndex = 0;
      ch = s___scratch1__97c2f688[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", scratch1, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex,0,0,0x40);
      opOffsetOrTailLength = 0;
      ch = s___scratch__97c2e620[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ", scratch;\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    else {
      copyIndex = 0;
      ch = s_ABS_SAT_scratch__scratch__97c2f698[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = "ABS_SAT scratch, scratch;\n"[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      copyIndex2 = 0;
      ch = s_LRP_97c2e9e4[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex + copyIndex2) = ch;
        ch = "LRP "[copyIndex2 + 1];
        copyIndex2 = copyIndex2 + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex + copyIndex2,0,0,0);
      copyIndex = 0;
      ch = s___scratch__97c2e570[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", scratch, "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor + copyIndex,0,0,0x40);
      copyIndex = 0;
      ch = s___97c2d7ec[0];
      while (ch != '\0') {
        *(char *)(outCursor + copyIndex) = ch;
        ch = ", "[copyIndex + 1];
        copyIndex = copyIndex + 1;
      }
      outStart = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor + copyIndex,paramNumbers,paramArrayPos,2,0,0,0);
      opOffsetOrTailLength = 0;
      ch = s___97c2d8f8[0];
      while (ch != '\0') {
        *(char *)(outStart + opOffsetOrTailLength) = ch;
        ch = ";\n"[opOffsetOrTailLength + 1];
        opOffsetOrTailLength = opOffsetOrTailLength + 1;
      }
    }
    break;
  case 0x6f:
    *stateFlags = *stateFlags | 0x20000;
    writeMaskBits = inst[2];
    loopIndex = 0;
    writeMaskBits2 = writeMaskBits >> 0xd & 0xf;
    do {
      if ((writeMaskBits2 & 1) != 0) {
        copyIndex2 = 0;
        ch = s_POW_97c2e5a4[0];
        while (ch != '\0') {
          *(char *)(outStart + copyIndex2) = ch;
          ch = "POW "[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor2 = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outStart + copyIndex2,0,loopIndex,2);
        copyIndex3 = 0;
        ch = s___kE__97c2e5ac[0];
        while (ch != '\0') {
          *(char *)(outCursor2 + copyIndex3) = ch;
          ch = ", kE, "[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        outCursor6 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outCursor2 + copyIndex3,paramNumbers,paramArrayPos,2,0,loopIndex,10)
        ;
        copyIndex2 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor6 + copyIndex2) = ch;
          ch = ";\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        writeMaskBits = inst[2];
        outStart = outCursor6 + copyIndex2;
      }
      loopIndex = loopIndex + 1;
      writeMaskBits2 = (int)writeMaskBits2 >> 1;
    } while (loopIndex <= (int)(writeMaskBits >> 10 & 3));
    goto LAB_97c01788;
  case 0x70:
    *stateFlags = *stateFlags | 0x20001;
    writeMaskBits = inst[2];
    loopIndex = 0;
    writeMaskBits2 = writeMaskBits >> 0xd & 0xf;
    do {
      if ((writeMaskBits2 & 1) != 0) {
        copyIndex2 = 0;
        ch = s_LG2_scratch__97c2e5b4[0];
        while (ch != '\0') {
          *(char *)(outStart + copyIndex2) = ch;
          ch = "LG2 scratch, "[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        outCursor7 = ((int (*)())_glpWriteSourceOperand_97bf30b8)(inst,outStart + copyIndex2,paramNumbers,paramArrayPos,2,0,loopIndex,10)
        ;
        copyIndex3 = 0;
        ch = s___97c2d8f8[0];
        while (ch != '\0') {
          *(char *)(outCursor7 + copyIndex3) = ch;
          ch = ";\n"[copyIndex3 + 1];
          copyIndex3 = copyIndex3 + 1;
        }
        copyIndex4 = 0;
        ch = s_MUL_97c2e4f0[0];
        while (ch != '\0') {
          *(char *)(outCursor7 + copyIndex3 + copyIndex4) = ch;
          ch = "MUL "[copyIndex4 + 1];
          copyIndex4 = copyIndex4 + 1;
        }
        outCursor = ((int (*)())_glpWriteDestinationOperand_97bf3658)(inst,outCursor7 + copyIndex3 + copyIndex4,0,loopIndex,2);
        copyIndex2 = 0;
        ch = s___scratch__k1_OVER_LOG2_E__97c2e5c4[0];
        while (ch != '\0') {
          *(char *)(outCursor + copyIndex2) = ch;
          ch = ", scratch, k1_OVER_LOG2_E;\n"[copyIndex2 + 1];
          copyIndex2 = copyIndex2 + 1;
        }
        writeMaskBits = inst[2];
        outStart = outCursor + copyIndex2;
      }
      loopIndex = loopIndex + 1;
      writeMaskBits2 = (int)writeMaskBits2 >> 1;
    } while (loopIndex <= (int)(writeMaskBits >> 10 & 3));
    goto LAB_97c01788;
  }
  outStart = outStart + opOffsetOrTailLength;
LAB_97c01788:
  instWord0 = *inst;
LAB_97c0178c:
  *outWordCount = (instWord0 >> 0x1d) + 1;
  *outTextLength = outStart - outText;
  return 0;
}

/* _isParamArrayStart_97c017c0 @ 0x97c017c0 (96 bytes) */
int _isParamArrayStart_97c017c0(program, startRegister, arraySize)
  int program;
  uint startRegister;
  uint *arraySize;
{
  int arrayTable;
  int entryIndex;
  int arrayCount;
  
  arrayCount = *(int *)(program + 0x38);
  arrayTable = program + *(int *)(program + 0x3c) * 8;
  if ((arrayCount != 0) && (entryIndex = 0, 0 < arrayCount)) {
    do {
      if ((*(uint *)(arrayTable + entryIndex * 8) & 0xffff) == startRegister) {
        *arraySize = (uint)*(ushort *)(entryIndex * 8 + arrayTable + 6);
        return 1;
      }
      entryIndex = entryIndex + 1;
    } while (entryIndex < arrayCount);
  }
  return 0;
}

/* _glpPPShaderToProgramString @ 0x97c01820 (15972 bytes) */
int _glpPPShaderToProgramString(shader, printOptions, printFlags)
  int *shader;
  undefined4 printOptions;
  uint printFlags;
{
  uint outputKind;
  uint matrixModifier;
  uint texgenCoordinate;
  uint lightProductTerm;
  uint isBackFace;
  uint paramKind;
  uint paramArrayStartRegister;
  uint highestParamRegister;
  int *arraySizeOut;
  int copyEnd7;
  int arrayPos;
  uint pendingUsageFlags;
  uint paramRegister;
  int instructionOffset;
  int outputOffset;
  int copyIndex11;
  int nextIndex5;
  undefined8 glp_dtostrResult;
  undefined8 adjustAllocationResult;
  int adjustAllocationResult3;
  int glpDisassemble2OpResult;
  int adjustAllocationResult2;
  int nextIndex4;
  int nextIndex3;
  int loopIndex7;
  int allocation4;
  int nextIndex2;
  int loopIndex6;
  int nextIndex;
  int loopIndex5;
  int instructionCount;
  int outputCount;
  int paramOffset;
  int attribOffset;
  int tempCount;
  int paramCount;
  int attribCount;
  int copyIndex10;
  int copyIndex9;
  int copyEnd;
  int copyEnd3;
  int copyEnd4;
  int copyEnd6;
  int copyEnd5;
  uint loopIndex4;
  int loopIndex;
  int loopIndex3;
  int loopIndex2;
  int allocation2;
  int copyLength8;
  int copyIndex;
  int copyLength;
  int copyIndex6;
  int copyLength3;
  int copyIndex3;
  int copyLength5;
  int copyIndex4;
  int copyLength10;
  int copyLength7;
  int copyIndex8;
  int copyLength9;
  int copyIndex5;
  int copyLength4;
  int copyIndex2;
  int copyLength2;
  int copyIndex7;
  char ch;
  uint registerWord1;
  int entriesLeft;
  int copyEnd8;
  int entryByteOffset;
  uint *paramWord1Cursor;
  int numberEnd;
  int copyEnd2;
  char *allocation8;
  char *allocation;
  undefined4 r4AfterOutBufferMalloc;
  undefined4 r4AfterParamArrayPosMalloc;
  undefined4 callResultLow;
  undefined4 r4AfterArraySizesMalloc;
  int copyLength6;
  int nextIndex6;
  int *allocation9;
  int *allocation10;
  int allocation3;
  int shaderTarget;
  int *tempWord1Cursor;
  int addressRegCount;
  char *allocation6;
  int adrIndex;
  char *allocation7;
  uint attributeKind;
  float *constantData;
  double leftoverFpr3;
  double leftoverFpr4;
  double leftoverFpr5;
  double leftoverFpr6;
  double leftoverFpr7;
  double leftoverFpr8;
  undefined8 callResultPair;
  double leftoverStackArg1;
  double leftoverStackArg2;
  double leftoverStackArg3;
  double leftoverStackArg4;
  double leftoverStackArg5;
  uint usageFlags;
  uint requestedFlags;
  int outCapacity;
  char *outBuffer;
  char *outCursor;
  uint arrayEnd;
  int wordsConsumed;
  int charsWritten;
  undefined4 outFlagWord;
  char *bodyStart;
  char *bodyCursor [2];
  
  outCapacity = 0x1000;
  outFlagWord = 1;
  usageFlags = 0;
  requestedFlags = 0;
  outBuffer = (char *)_malloc(0x1000);
  loopIndex5 = 0;
  allocation3 = 0;
  allocation10 = (int *)0x0;
  allocation9 = (int *)0x0;
  if (outBuffer == (char *)0x0) {
    return 0;
  }
  shaderTarget = *shader;
  if ((printFlags & 2) == 0) {
    if ((printFlags & 1) != 0) {
      requestedFlags = requestedFlags | 0x100000;
    }
  }
  else {
    requestedFlags = requestedFlags | 0x300000;
  }
  if ((printFlags & 8) == 0) {
    if ((printFlags & 4) != 0) {
      requestedFlags = requestedFlags | 0x400000;
    }
  }
  else {
    requestedFlags = requestedFlags | 0xc00000;
  }
  addressRegCount = shader[6];
  callResultLow = r4AfterOutBufferMalloc;
  outCursor = outBuffer;
  if (addressRegCount != 0) {
    ch = 'A';
    copyIndex8 = 0;
    do {
      outBuffer[copyIndex8] = ch;
      copyLength10 = copyIndex8 + 1;
      ch = "ADDRESS adr0"[copyIndex8 + 1];
      copyIndex8 = copyLength10;
    } while (ch != '\0');
    adrIndex = 1;
    outCursor = outBuffer + copyLength10;
    if (1 < addressRegCount) {
      do {
        ch = ',';
        copyIndex4 = 0;
        do {
          outCursor[copyIndex4] = ch;
          copyLength5 = copyIndex4 + 1;
          ch = ", adr"[copyIndex4 + 1];
          copyIndex4 = copyLength5;
        } while (ch != '\0');
        outCursor = outCursor + copyLength5;
        nextIndex2 = adrIndex + 1;
        copyEnd6 = ((int (*)())_ncpy_97bf2850)(outCursor,adrIndex);
        outCursor = outCursor + copyEnd6;
        adrIndex = nextIndex2;
      } while (nextIndex2 < addressRegCount);
    }
    ch = ';';
    copyIndex5 = 0;
    do {
      outCursor[copyIndex5] = ch;
      copyLength7 = copyIndex5 + 1;
      ch = ";\n"[copyIndex5 + 1];
      copyIndex5 = copyLength7;
    } while (ch != '\0');
    outCursor = outCursor + copyLength7;
    adjustAllocationResult = ((int (*)())_adjustAllocation_97bf27d4)(&outCapacity,&outBuffer,&outCursor);
    callResultLow = (undefined4)adjustAllocationResult;
    allocation8 = outBuffer;
    if ((int)((ulonglong)adjustAllocationResult >> 0x20) == 0) goto LAB_97c04d50;
    ch = '\n';
    copyIndex5 = 0;
    do {
      outCursor[copyIndex5] = ch;
      copyLength7 = copyIndex5 + 1;
      ch = "\n"[copyIndex5 + 1];
      copyIndex5 = copyLength7;
    } while (ch != '\0');
    outCursor = outCursor + copyLength7;
  }
  tempCount = shader[4];
  loopIndex2 = 0;
  if (0 < tempCount) {
    tempWord1Cursor = shader + shader[5] * 2 + 1;
    do {
      ch = 'T';
      copyIndex4 = 0;
      do {
        outCursor[copyIndex4] = ch;
        copyLength5 = copyIndex4 + 1;
        ch = "TEMP "[copyIndex4 + 1];
        copyIndex4 = copyLength5;
      } while (ch != '\0');
      ch = 't';
      copyIndex4 = 0;
      do {
        outCursor[copyIndex4 + copyLength5] = ch;
        copyLength3 = copyIndex4 + 1;
        ch = "tmp"[copyIndex4 + 1];
        copyIndex4 = copyLength3;
      } while (ch != '\0');
      outCursor = outCursor + copyLength3 + copyLength5;
      copyEnd3 = ((int (*)())_ncpy_97bf2850)(outCursor,(uint)(ushort)*tempWord1Cursor);
      ch = ';';
      copyIndex4 = 0;
      do {
        outCursor[copyIndex4 + copyEnd3] = ch;
        copyLength3 = copyIndex4 + 1;
        ch = ";\n"[copyIndex4 + 1];
        copyIndex4 = copyLength3;
      } while (ch != '\0');
      outCursor = outCursor + copyLength3 + copyEnd3;
      adjustAllocationResult = ((int (*)())_adjustAllocation_97bf27d4)(&outCapacity,&outBuffer,&outCursor);
      callResultLow = (undefined4)adjustAllocationResult;
      allocation8 = outBuffer;
      if ((int)((ulonglong)adjustAllocationResult >> 0x20) == 0) goto LAB_97c04d50;
      loopIndex2 = loopIndex2 + 1;
      tempWord1Cursor = tempWord1Cursor + 2;
    } while (loopIndex2 < tempCount);
  }
  if (tempCount != 0) {
    ch = '\n';
    copyIndex5 = 0;
    do {
      outCursor[copyIndex5] = ch;
      copyLength7 = copyIndex5 + 1;
      ch = "\n"[copyIndex5 + 1];
      copyIndex5 = copyLength7;
    } while (ch != '\0');
    outCursor = outCursor + copyLength7;
  }
  attribCount = shader[8];
  loopIndex3 = 0;
  attribOffset = shader[9];
  if (0 < attribCount) {
    do {
      attributeKind = (uint)shader[attribOffset * 2 + loopIndex3 * 2] >> 0x10 & 0xf;
      if (attributeKind == 0) goto LAB_97c0239c;
      ch = 'A';
      copyIndex3 = 0;
      do {
        outCursor[copyIndex3] = ch;
        copyLength3 = copyIndex3 + 1;
        ch = "ATTRIB att"[copyIndex3 + 1];
        copyIndex3 = copyLength3;
      } while (ch != '\0');
      outCursor = outCursor + copyLength3;
      copyEnd3 = ((int (*)())_ncpy_97bf2850)(outCursor,(uint)*(ushort *)((int)shader + loopIndex3 * 8 + attribOffset * 8 + 6));
      outCursor = outCursor + copyEnd3;
      if (shaderTarget == 0x8b30) {
        ch = ' ';
        copyIndex3 = 0;
        do {
          outCursor[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = " = fragment."[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
LAB_97c01cf4:
        outCursor = outCursor + copyLength3;
      }
      else if (shaderTarget == 0x8b31) {
        ch = ' ';
        copyIndex3 = 0;
        do {
          outCursor[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = " = vertex."[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        goto LAB_97c01cf4;
      }
      switch(attributeKind) {
      default:
        goto switchD_97c01d20_caseD_0;
      case 1:
        ch = 'p';
        copyIndex3 = 0;
        do {
          outCursor[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "position"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        break;
      case 2:
        ch = 'c';
        copyIndex3 = 0;
        do {
          outCursor[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "color.primary"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        break;
      case 3:
        ch = 'c';
        copyIndex3 = 0;
        do {
          outCursor[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "color.secondary"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        break;
      case 4:
        ch = 'n';
        copyIndex3 = 0;
        do {
          outCursor[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "normal"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        break;
      case 5:
        ch = 'f';
        copyIndex3 = 0;
        do {
          outCursor[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "fogcoord"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        break;
      case 6:
        ch = 'w';
        copyIndex3 = 0;
        do {
          outCursor[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "weight["[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        outCursor = outCursor + copyLength3;
        copyEnd3 = ((int (*)())_ncpy_97bf2850)(outCursor,shader[attribOffset * 2 + loopIndex3 * 2] & 0x1f);
        ch = ']';
        outCursor = outCursor + copyEnd3;
        copyIndex3 = 0;
        do {
          outCursor[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "]"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        goto LAB_97c02100;
      case 7:
        ch = 't';
        copyIndex3 = 0;
        do {
          outCursor[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "texcoord["[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        outCursor = outCursor + copyLength3;
        copyEnd3 = ((int (*)())_ncpy_97bf2850)(outCursor,shader[attribOffset * 2 + loopIndex3 * 2] & 0x1f);
        ch = ']';
        outCursor = outCursor + copyEnd3;
        copyIndex3 = 0;
        do {
          outCursor[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "]"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        goto LAB_97c02100;
      case 8:
        ch = 'm';
        copyIndex3 = 0;
        do {
          outCursor[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "matrixindex["[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        outCursor = outCursor + copyLength3;
        copyEnd3 = ((int (*)())_ncpy_97bf2850)(outCursor,shader[attribOffset * 2 + loopIndex3 * 2] & 0x1f);
        ch = ']';
        outCursor = outCursor + copyEnd3;
        copyIndex3 = 0;
        do {
          outCursor[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "]"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        goto LAB_97c02100;
      case 9:
        ch = 'a';
        copyIndex3 = 0;
        do {
          outCursor[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "attrib["[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        outCursor = outCursor + copyLength3;
        copyEnd3 = ((int (*)())_ncpy_97bf2850)(outCursor,shader[attribOffset * 2 + loopIndex3 * 2] & 0x1f);
        ch = ']';
        outCursor = outCursor + copyEnd3;
        copyIndex3 = 0;
        do {
          outCursor[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "]"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
LAB_97c02100:
        outCursor = outCursor + copyLength3;
        goto switchD_97c01d20_caseD_0;
      case 10:
        ch = 'm';
        copyIndex3 = 0;
        do {
          outCursor[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "material."[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
        outCursor = outCursor + copyLength3;
        if ((shader[attribOffset * 2 + loopIndex3 * 2] & 1U) == 0) {
          ch = 'f';
          copyIndex3 = 0;
          do {
            outCursor[copyIndex3] = ch;
            copyLength3 = copyIndex3 + 1;
            ch = "front."[copyIndex3 + 1];
            copyIndex3 = copyLength3;
          } while (ch != '\0');
LAB_97c021d8:
          outCursor = outCursor + copyLength3;
        }
        else if ((shader[attribOffset * 2 + loopIndex3 * 2] & 1U) == 1) {
          ch = 'b';
          copyIndex3 = 0;
          do {
            outCursor[copyIndex3] = ch;
            copyLength3 = copyIndex3 + 1;
            ch = "back."[copyIndex3 + 1];
            copyIndex3 = copyLength3;
          } while (ch != '\0');
          goto LAB_97c021d8;
        }
        switch((uint)shader[attribOffset * 2 + loopIndex3 * 2] >> 0xc & 0xf) {
        case 0:
          ch = 'a';
          copyIndex3 = 0;
          do {
            outCursor[copyIndex3] = ch;
            copyLength3 = copyIndex3 + 1;
            ch = "ambient"[copyIndex3 + 1];
            copyIndex3 = copyLength3;
          } while (ch != '\0');
          break;
        case 1:
          ch = 'd';
          copyIndex3 = 0;
          do {
            outCursor[copyIndex3] = ch;
            copyLength3 = copyIndex3 + 1;
            ch = "diffuse"[copyIndex3 + 1];
            copyIndex3 = copyLength3;
          } while (ch != '\0');
          break;
        case 2:
          ch = 's';
          copyIndex3 = 0;
          do {
            outCursor[copyIndex3] = ch;
            copyLength3 = copyIndex3 + 1;
            ch = "specular"[copyIndex3 + 1];
            copyIndex3 = copyLength3;
          } while (ch != '\0');
          break;
        case 3:
          ch = 'e';
          copyIndex3 = 0;
          do {
            outCursor[copyIndex3] = ch;
            copyLength3 = copyIndex3 + 1;
            ch = "emission"[copyIndex3 + 1];
            copyIndex3 = copyLength3;
          } while (ch != '\0');
          break;
        case 4:
          ch = 's';
          copyIndex3 = 0;
          do {
            outCursor[copyIndex3] = ch;
            copyLength3 = copyIndex3 + 1;
            ch = "shininess"[copyIndex3 + 1];
            copyIndex3 = copyLength3;
          } while (ch != '\0');
          break;
        default:
          goto switchD_97c01d20_caseD_0;
        }
        break;
      case 0xb:
        ch = 'f';
        copyIndex3 = 0;
        do {
          outCursor[copyIndex3] = ch;
          copyLength3 = copyIndex3 + 1;
          ch = "frontfacing"[copyIndex3 + 1];
          copyIndex3 = copyLength3;
        } while (ch != '\0');
      }
      outCursor = outCursor + copyLength3;
switchD_97c01d20_caseD_0:
      ch = ';';
      copyIndex3 = 0;
      do {
        outCursor[copyIndex3] = ch;
        copyLength3 = copyIndex3 + 1;
        ch = ";\n"[copyIndex3 + 1];
        copyIndex3 = copyLength3;
      } while (ch != '\0');
      outCursor = outCursor + copyLength3;
      adjustAllocationResult = ((int (*)())_adjustAllocation_97bf27d4)(&outCapacity,&outBuffer,&outCursor);
      callResultLow = (undefined4)adjustAllocationResult;
      allocation8 = outBuffer;
      if ((int)((ulonglong)adjustAllocationResult >> 0x20) == 0) goto LAB_97c04d50;
LAB_97c0239c:
      loopIndex3 = loopIndex3 + 1;
    } while (loopIndex3 < attribCount);
  }
  if (attribCount != 0) {
    ch = '\n';
    copyIndex5 = 0;
    do {
      outCursor[copyIndex5] = ch;
      copyLength7 = copyIndex5 + 1;
      ch = "\n"[copyIndex5 + 1];
      copyIndex5 = copyLength7;
    } while (ch != '\0');
    outCursor = outCursor + copyLength7;
  }
  paramCount = shader[10];
  paramOffset = shader[0xb];
  if (paramCount != 0) {
    highestParamRegister = 0xffffffff;
    if (0 < paramCount) {
      paramWord1Cursor = (uint *)(shader + paramOffset * 2 + 1);
      entriesLeft = paramCount;
      do {
        registerWord1 = *paramWord1Cursor;
        paramWord1Cursor = paramWord1Cursor + 2;
        if ((int)highestParamRegister < (int)(registerWord1 & 0xffff)) {
          highestParamRegister = registerWord1 & 0xffff;
        }
        entriesLeft = entriesLeft + -1;
      } while (entriesLeft != 0);
      if (highestParamRegister != 0xffffffff) {
        allocation4 = highestParamRegister * 4 + 4;
        allocation3 = _malloc(allocation4);
        allocation10 = (int *)_malloc(allocation4);
        if ((allocation3 == 0) || (callResultLow = r4AfterParamArrayPosMalloc, allocation10 == (int *)0x0)) {
          allocation9 = allocation10;
          allocation8 = outBuffer;
          if (allocation3 != 0) {
            _free(allocation3);
            allocation8 = outBuffer;
          }
joined_r0x97c02488:
          outBuffer = allocation8;
          if (allocation9 != (int *)0x0) {
            _free(allocation9);
            allocation8 = outBuffer;
          }
          goto LAB_97c04d50;
        }
      }
    }
    if (shader[0xe] != 0) {
      allocation9 = (int *)_malloc(shader[0xe] << 2);
      callResultLow = r4AfterArraySizesMalloc;
    }
    callResultPair = CONCAT44(allocation9,callResultLow);
    loopIndex3 = 0;
    arrayPos = -1;
    arrayEnd = 0xffffffff;
    paramArrayStartRegister = 0xffffffff;
    arraySizeOut = allocation9;
    if (0 < paramCount) {
      do {
        entryByteOffset = loopIndex3 * 8 + paramOffset * 8;
        if ((shader[paramOffset * 2 + loopIndex3 * 2] & 0x1f0000U) != 0) {
          if (paramArrayStartRegister == 0xffffffff) {
            paramRegister = (uint)*(ushort *)((int)shader + entryByteOffset + 6);
            *(uint *)(paramRegister * 4 + allocation3) = paramRegister;
            callResultPair = ((int (*)())_isParamArrayStart_97c017c0)(shader,(uint)*(ushort *)((int)shader + entryByteOffset + 6),&arrayEnd);
            if ((int)((ulonglong)callResultPair >> 0x20) == 0) {
              allocation10[*(ushort *)((int)shader + entryByteOffset + 6)] = arrayPos;
            }
            else {
              paramArrayStartRegister = (uint)*(ushort *)((int)shader + entryByteOffset + 6);
              allocation10[paramArrayStartRegister] = 0;
              arrayPos = 1;
            }
          }
          else {
            paramRegister = (uint)*(ushort *)((int)shader + entryByteOffset + 6);
            if ((int)paramRegister <= (int)arrayEnd) {
              *(uint *)(paramRegister * 4 + allocation3) = paramArrayStartRegister;
              allocation10[*(ushort *)((int)shader + entryByteOffset + 6)] = arrayPos;
              arrayPos = arrayPos + 1;
              if (*(ushort *)((int)shader + entryByteOffset + 6) == arrayEnd) {
                paramArrayStartRegister = 0xffffffff;
                arrayEnd = 0xffffffff;
                *arraySizeOut = arrayPos;
                arraySizeOut = arraySizeOut + 1;
                arrayPos = -1;
              }
            }
          }
        }
        loopIndex3 = loopIndex3 + 1;
      } while (loopIndex3 < paramCount);
    }
    loopIndex = 0;
    loopIndex7 = 0;
    if (0 < paramCount) {
      do {
        entryByteOffset = loopIndex * 8;
        paramKind = (uint)shader[paramOffset * 2 + loopIndex * 2] >> 0x10 & 0x1f;
        if (paramKind == 0) goto LAB_97c04238;
        if (allocation10[*(ushort *)((int)shader + entryByteOffset + paramOffset * 8 + 6)] == -1) {
          ch = 'P';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "PARAM prm"[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = outCursor + copyLength;
          callResultPair = ((int (*)())_ncpy_97bf2850)(outCursor,*(undefined4 *)
                                            (allocation3 + (uint)*(ushort *)
                                                             ((int)shader + entryByteOffset + paramOffset * 8 + 6)
                                                      * 4));
          ch = ' ';
          copyIndex = 0;
          do {
            (outCursor + (int)((ulonglong)callResultPair >> 0x20))[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = " = "[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = outCursor + (int)((ulonglong)callResultPair >> 0x20) + copyLength;
        }
        else {
          if (allocation10[*(ushort *)((int)shader + entryByteOffset + paramOffset * 8 + 6)] == 0) {
            loopIndex5 = 0;
            ch = 'P';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "PARAM prm"[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            outCursor = outCursor + copyLength;
            copyEnd = ((int (*)())_ncpy_97bf2850)(outCursor,*(undefined4 *)
                                             (allocation3 + (uint)*(ushort *)
                                                              ((int)shader + entryByteOffset + paramOffset * 8 + 6
                                                              ) * 4));
            ch = '[';
            copyIndex = 0;
            do {
              outCursor[copyIndex + copyEnd] = ch;
              copyLength6 = copyIndex + 1;
              ch = "["[copyIndex + 1];
              copyIndex = copyLength6;
            } while (ch != '\0');
            outCursor = outCursor + copyLength6 + copyEnd;
            callResultPair = ((int (*)())_ncpy_97bf2850)(outCursor,allocation9[loopIndex7]);
            ch = ']';
            copyIndex = 0;
            do {
              (outCursor + (int)((ulonglong)callResultPair >> 0x20))[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "]"[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            outCursor = outCursor + (int)((ulonglong)callResultPair >> 0x20) + copyLength;
            ch = ' ';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = " = {\n    "[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
          }
          else {
            loopIndex5 = loopIndex5 + 1;
            ch = ' ';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "    "[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
          }
          outCursor = outCursor + copyLength;
        }
        if (paramKind == 0) {
LAB_97c028a4:
          ch = 's';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            nextIndex4 = copyIndex + 1;
            ch = "state."[copyIndex + 1];
            copyIndex = nextIndex4;
          } while (ch != '\0');
        }
        else if (paramKind < 3) {
          ch = 'p';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            nextIndex4 = copyIndex + 1;
            ch = "program."[copyIndex + 1];
            copyIndex = nextIndex4;
          } while (ch != '\0');
        }
        else {
          if (paramKind != 0x11) goto LAB_97c028a4;
          nextIndex4 = 0;
        }
        outCursor = outCursor + nextIndex4;
        switch(paramKind) {
        default:
          goto switchD_97c02904_caseD_0;
        case 1:
          ch = 'l';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "local["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = outCursor + copyLength;
          copyEnd2 = ((int (*)())_ncpy_97bf2850)(outCursor,shader[paramOffset * 2 + loopIndex * 2] & 0xffff);
          ch = ']';
          outCursor = outCursor + copyEnd2;
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "]"[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          goto LAB_97c040c4;
        case 2:
          ch = 'e';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "env["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = outCursor + copyLength;
          copyEnd2 = ((int (*)())_ncpy_97bf2850)(outCursor,shader[paramOffset * 2 + loopIndex * 2] & 0xffff);
          ch = ']';
          outCursor = outCursor + copyEnd2;
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "]"[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          goto LAB_97c040c4;
        case 3:
          ch = 'l';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "light["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = outCursor + copyLength;
          copyEnd7 = ((int (*)())_ncpy_97bf2850)(outCursor,shader[paramOffset * 2 + loopIndex * 2] & 0xff);
          ch = ']';
          copyIndex = 0;
          do {
            outCursor[copyIndex + copyEnd7] = ch;
            copyLength6 = copyIndex + 1;
            ch = "]."[copyIndex + 1];
            copyIndex = copyLength6;
          } while (ch != '\0');
          outCursor = outCursor + copyLength6 + copyEnd7;
          switch((uint)shader[paramOffset * 2 + loopIndex * 2] >> 8 & 0xf) {
          case 0:
            ch = 'a';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "ambient"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            break;
          case 1:
            ch = 'd';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "diffuse"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            break;
          case 2:
            ch = 's';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "specular"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            break;
          case 3:
            ch = 'p';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "position"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            break;
          case 4:
            ch = 's';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "spot.direction"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            break;
          case 5:
            ch = 'a';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "attenuation"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            break;
          case 6:
            ch = 'h';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "half"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            break;
          case 7:
            ch = 's';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "spotcutoff"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            break;
          default:
            goto switchD_97c02904_caseD_0;
          }
          break;
        case 4:
          ch = 'l';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "lightprod["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = outCursor + copyLength;
          copyEnd = ((int (*)())_ncpy_97bf2850)(outCursor,shader[paramOffset * 2 + loopIndex * 2] & 0xff);
          ch = ']';
          copyIndex = 0;
          do {
            outCursor[copyIndex + copyEnd] = ch;
            copyLength6 = copyIndex + 1;
            ch = "]."[copyIndex + 1];
            copyIndex = copyLength6;
          } while (ch != '\0');
          outCursor = outCursor + copyLength6 + copyEnd;
          isBackFace = (uint)shader[paramOffset * 2 + loopIndex * 2] >> 8 & 1;
          if (isBackFace == 0) {
            ch = 'f';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "front."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
LAB_97c02e60:
            outCursor = outCursor + copyLength;
          }
          else if (isBackFace == 1) {
            ch = 'b';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "back."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            goto LAB_97c02e60;
          }
          lightProductTerm = (uint)shader[paramOffset * 2 + loopIndex * 2] >> 9 & 3;
          if (lightProductTerm == 1) {
            ch = 'd';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "diffuse"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            break;
          }
          if (lightProductTerm < 2) {
            if (lightProductTerm == 0) {
              ch = 'a';
              copyIndex = 0;
              do {
                outCursor[copyIndex] = ch;
                nextIndex4 = copyIndex + 1;
                ch = "ambient"[copyIndex + 1];
                copyIndex = nextIndex4;
              } while (ch != '\0');
              break;
            }
          }
          else if (lightProductTerm == 2) {
            ch = 's';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "specular"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            break;
          }
          goto switchD_97c02904_caseD_0;
        case 5:
          if (((uint)shader[paramOffset * 2 + loopIndex * 2] >> 1 & 7) == 5) {
            ch = 'l';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "lightmodel."[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
          }
          else {
            ch = 'm';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "material."[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
          }
          outCursor = outCursor + nextIndex4;
          if ((shader[paramOffset * 2 + loopIndex * 2] & 1U) == 0) {
            ch = 'f';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "front."[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
LAB_97c03088:
            outCursor = outCursor + nextIndex4;
          }
          else if ((shader[paramOffset * 2 + loopIndex * 2] & 1U) == 1) {
            ch = 'b';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "back."[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            goto LAB_97c03088;
          }
          switch((uint)shader[paramOffset * 2 + loopIndex * 2] >> 1 & 7) {
          case 0:
            ch = 'a';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "ambient"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            break;
          case 1:
            ch = 'd';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "diffuse"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            break;
          case 2:
            ch = 's';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "specular"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            break;
          case 3:
            ch = 'e';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "emission"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            break;
          case 4:
            ch = 's';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "shininess"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            break;
          case 5:
            ch = 's';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "scenecolor"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            break;
          default:
            goto switchD_97c02904_caseD_0;
          }
          break;
        case 6:
          ch = 'l';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            nextIndex4 = copyIndex + 1;
            ch = "lightmodel.ambient"[copyIndex + 1];
            copyIndex = nextIndex4;
          } while (ch != '\0');
          break;
        case 7:
          ch = 't';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "texgen["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = outCursor + copyLength;
          copyEnd = ((int (*)())_ncpy_97bf2850)(outCursor,shader[paramOffset * 2 + loopIndex * 2] & 0x1f);
          ch = ']';
          copyIndex = 0;
          do {
            outCursor[copyIndex + copyEnd] = ch;
            copyLength6 = copyIndex + 1;
            ch = "].eye."[copyIndex + 1];
            copyIndex = copyLength6;
          } while (ch != '\0');
          outCursor = outCursor + copyLength6 + copyEnd;
          texgenCoordinate = (uint)shader[paramOffset * 2 + loopIndex * 2] >> 5 & 7;
          if (texgenCoordinate == 1) {
            ch = 't';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "t"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
          }
          else if (texgenCoordinate < 2) {
            if (texgenCoordinate != 0) goto switchD_97c02904_caseD_0;
            ch = 's';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "s"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
          }
          else if (texgenCoordinate == 2) {
            ch = 'r';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "r"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
          }
          else {
            if (texgenCoordinate != 3) goto switchD_97c02904_caseD_0;
            ch = 'q';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "q"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
          }
          break;
        case 8:
          ch = 't';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "texgen["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = outCursor + copyLength;
          copyEnd = ((int (*)())_ncpy_97bf2850)(outCursor,shader[paramOffset * 2 + loopIndex * 2] & 0x1f);
          ch = ']';
          copyIndex = 0;
          do {
            outCursor[copyIndex + copyEnd] = ch;
            copyLength6 = copyIndex + 1;
            ch = "].object."[copyIndex + 1];
            copyIndex = copyLength6;
          } while (ch != '\0');
          outCursor = outCursor + copyLength6 + copyEnd;
          texgenCoordinate = (uint)shader[paramOffset * 2 + loopIndex * 2] >> 5 & 7;
          if (texgenCoordinate == 1) {
            ch = 't';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "t"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
          }
          else if (texgenCoordinate < 2) {
            if (texgenCoordinate != 0) goto switchD_97c02904_caseD_0;
            ch = 's';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "s"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
          }
          else if (texgenCoordinate == 2) {
            ch = 'r';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "r"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
          }
          else {
            if (texgenCoordinate != 3) goto switchD_97c02904_caseD_0;
            ch = 'q';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "q"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
          }
          break;
        case 9:
          ch = 't';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "texenv["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = outCursor + copyLength;
          copyEnd2 = ((int (*)())_ncpy_97bf2850)(outCursor,shader[paramOffset * 2 + loopIndex * 2] & 0x1f);
          ch = ']';
          outCursor = outCursor + copyEnd2;
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "].color"[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          goto LAB_97c040c4;
        case 10:
          ch = 'c';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "clip["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = outCursor + copyLength;
          copyEnd2 = ((int (*)())_ncpy_97bf2850)(outCursor,shader[paramOffset * 2 + loopIndex * 2] & 0xff);
          ch = ']';
          outCursor = outCursor + copyEnd2;
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "].plane"[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          goto LAB_97c040c4;
        case 0xb:
          ch = 'f';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            nextIndex4 = copyIndex + 1;
            ch = "fog.color"[copyIndex + 1];
            copyIndex = nextIndex4;
          } while (ch != '\0');
          break;
        case 0xc:
          ch = 'f';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            nextIndex4 = copyIndex + 1;
            ch = "fog.params"[copyIndex + 1];
            copyIndex = nextIndex4;
          } while (ch != '\0');
          break;
        case 0xd:
          ch = 'p';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            nextIndex4 = copyIndex + 1;
            ch = "point.size"[copyIndex + 1];
            copyIndex = nextIndex4;
          } while (ch != '\0');
          break;
        case 0xe:
          ch = 'p';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            nextIndex4 = copyIndex + 1;
            ch = "point.attenuation"[copyIndex + 1];
            copyIndex = nextIndex4;
          } while (ch != '\0');
          break;
        case 0xf:
          ch = 'd';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            nextIndex4 = copyIndex + 1;
            ch = "depth.range"[copyIndex + 1];
            copyIndex = nextIndex4;
          } while (ch != '\0');
          break;
        case 0x10:
          ch = 'm';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "matrix."[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = outCursor + copyLength;
          switch((uint)shader[paramOffset * 2 + loopIndex * 2] >> 8 & 7) {
          case 0:
            ch = 'm';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "mvp."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            goto LAB_97c038d4;
          case 1:
            ch = 'p';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "projection."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
LAB_97c038d4:
            outCursor = outCursor + copyLength;
            goto switchD_97c0384c_default;
          case 2:
            ch = 'c';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "color["[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            outCursor = outCursor + copyLength;
            copyEnd2 = ((int (*)())_ncpy_97bf2850)(outCursor,shader[paramOffset * 2 + loopIndex * 2] & 0xff);
            ch = ']';
            outCursor = outCursor + copyEnd2;
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "]."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            break;
          case 3:
            ch = 'm';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "modelview["[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            outCursor = outCursor + copyLength;
            copyEnd2 = ((int (*)())_ncpy_97bf2850)(outCursor,shader[paramOffset * 2 + loopIndex * 2] & 0xff);
            ch = ']';
            outCursor = outCursor + copyEnd2;
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "]."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            break;
          case 4:
            ch = 't';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "texture["[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            outCursor = outCursor + copyLength;
            copyEnd2 = ((int (*)())_ncpy_97bf2850)(outCursor,shader[paramOffset * 2 + loopIndex * 2] & 0xff);
            ch = ']';
            outCursor = outCursor + copyEnd2;
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "]."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            break;
          case 5:
            ch = 'p';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "program["[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            outCursor = outCursor + copyLength;
            copyEnd2 = ((int (*)())_ncpy_97bf2850)(outCursor,shader[paramOffset * 2 + loopIndex * 2] & 0xff);
            ch = ']';
            outCursor = outCursor + copyEnd2;
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "]."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            break;
          default:
            goto switchD_97c0384c_default;
          }
          outCursor = outCursor + copyLength;
switchD_97c0384c_default:
          matrixModifier = (uint)shader[paramOffset * 2 + loopIndex * 2] >> 0xe & 3;
          if (matrixModifier == 1) {
            ch = 't';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "transpose."[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
LAB_97c03c14:
            outCursor = outCursor + copyLength;
          }
          else if (1 < matrixModifier) {
            if (matrixModifier == 2) {
              ch = 'i';
              copyIndex = 0;
              do {
                outCursor[copyIndex] = ch;
                copyLength = copyIndex + 1;
                ch = "inverse."[copyIndex + 1];
                copyIndex = copyLength;
              } while (ch != '\0');
            }
            else {
              if (matrixModifier != 3) goto LAB_97c03c20;
              ch = 'i';
              copyIndex = 0;
              do {
                outCursor[copyIndex] = ch;
                copyLength = copyIndex + 1;
                ch = "invtrans."[copyIndex + 1];
                copyIndex = copyLength;
              } while (ch != '\0');
            }
            goto LAB_97c03c14;
          }
LAB_97c03c20:
          ch = 'r';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "row["[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
          outCursor = outCursor + copyLength;
          copyEnd2 = ((int (*)())_ncpy_97bf2850)(outCursor,(uint)shader[paramOffset * 2 + loopIndex * 2] >> 0xc & 3);
          ch = ']';
          outCursor = outCursor + copyEnd2;
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            copyLength = copyIndex + 1;
            ch = "]"[copyIndex + 1];
            copyIndex = copyLength;
          } while (ch != '\0');
LAB_97c040c4:
          outCursor = outCursor + copyLength;
          goto switchD_97c02904_caseD_0;
        case 0x11:
          constantData = (float *)(shader +
                             shader[0x1b] * 2 + (shader[paramOffset * 2 + loopIndex * 2] & 0xffffU) * 4);
          switch((uint)shader[paramOffset * 2 + loopIndex * 2] >> 0x1a & 7) {
          case 0:
          case 1:
            ch = '{';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "{"[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            outCursor = outCursor + copyLength;
            glp_dtostrResult = ((char * (*)())_glp_dtostr)((int)((ulonglong)callResultPair >> 0x20),(int)callResultPair,outCursor,
                                 outBuffer + (outCapacity - (int)outCursor),(double)*constantData,1e-07,leftoverFpr3,
                                 leftoverFpr4,leftoverFpr5,leftoverFpr6,leftoverFpr7,leftoverFpr8,leftoverStackArg1,leftoverStackArg2,
                                 leftoverStackArg3,leftoverStackArg4,leftoverStackArg5);
            numberEnd = (int)((ulonglong)glp_dtostrResult >> 0x20);
            ch = ',';
            copyIndex = 0;
            do {
              *(char *)(numberEnd + copyIndex) = ch;
              copyLength6 = copyIndex + 1;
              ch = ", "[copyIndex + 1];
              copyIndex = copyLength6;
            } while (ch != '\0');
            outCursor = (char *)(numberEnd + copyLength6);
            glp_dtostrResult = ((char * (*)())_glp_dtostr)(numberEnd,(int)glp_dtostrResult,outCursor,outBuffer + (outCapacity - (int)outCursor),
                                 (double)constantData[1],1e-07,leftoverFpr3,leftoverFpr4,leftoverFpr5,leftoverFpr6,leftoverFpr7,leftoverFpr8,
                                 leftoverStackArg1,leftoverStackArg2,leftoverStackArg3,
                                 leftoverStackArg4,leftoverStackArg5);
            numberEnd = (int)((ulonglong)glp_dtostrResult >> 0x20);
            ch = ',';
            copyIndex = 0;
            do {
              *(char *)(numberEnd + copyIndex) = ch;
              copyLength6 = copyIndex + 1;
              ch = ", "[copyIndex + 1];
              copyIndex = copyLength6;
            } while (ch != '\0');
            outCursor = (char *)(numberEnd + copyLength6);
            glp_dtostrResult = ((char * (*)())_glp_dtostr)(numberEnd,(int)glp_dtostrResult,outCursor,outBuffer + (outCapacity - (int)outCursor),
                                 (double)constantData[2],1e-07,leftoverFpr3,leftoverFpr4,leftoverFpr5,leftoverFpr6,leftoverFpr7,leftoverFpr8,
                                 leftoverStackArg1,leftoverStackArg2,leftoverStackArg3,
                                 leftoverStackArg4,leftoverStackArg5);
            numberEnd = (int)((ulonglong)glp_dtostrResult >> 0x20);
            ch = ',';
            copyIndex = 0;
            do {
              *(char *)(numberEnd + copyIndex) = ch;
              copyLength6 = copyIndex + 1;
              ch = ", "[copyIndex + 1];
              copyIndex = copyLength6;
            } while (ch != '\0');
            outCursor = (char *)(numberEnd + copyLength6);
            outCursor = (char *)((char * (*)())_glp_dtostr)(numberEnd,(int)glp_dtostrResult,outCursor,
                                           outBuffer + (outCapacity - (int)outCursor),(double)constantData[3],
                                           1e-07,leftoverFpr3,leftoverFpr4,leftoverFpr5,leftoverFpr6,leftoverFpr7,leftoverFpr8,
                                           leftoverStackArg1,leftoverStackArg2,leftoverStackArg3,
                                           leftoverStackArg4,leftoverStackArg5);
            ch = '}';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "}"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            break;
          case 2:
            ch = '{';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              nextIndex4 = copyIndex + 1;
              ch = "{-- Fixed constant data not currently supported --}"[copyIndex + 1];
              copyIndex = nextIndex4;
            } while (ch != '\0');
            break;
          case 3:
          case 4:
            ch = '{';
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "{"[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            outCursor = outCursor + copyLength;
            copyEnd = ((int (*)())_ncpy_97bf2850)(outCursor, *(unsigned int *)constantData);
            ch = ',';
            copyIndex = 0;
            do {
              outCursor[copyIndex + copyEnd] = ch;
              copyLength6 = copyIndex + 1;
              ch = ", "[copyIndex + 1];
              copyIndex = copyLength6;
            } while (ch != '\0');
            outCursor = outCursor + copyLength6 + copyEnd;
            copyEnd = ((int (*)())_ncpy_97bf2850)(outCursor, ((unsigned int *)constantData)[1]);
            ch = ',';
            copyIndex = 0;
            do {
              outCursor[copyIndex + copyEnd] = ch;
              copyLength6 = copyIndex + 1;
              ch = ", "[copyIndex + 1];
              copyIndex = copyLength6;
            } while (ch != '\0');
            outCursor = outCursor + copyLength6 + copyEnd;
            copyEnd = ((int (*)())_ncpy_97bf2850)(outCursor, ((unsigned int *)constantData)[2]);
            ch = ',';
            copyIndex = 0;
            do {
              outCursor[copyIndex + copyEnd] = ch;
              copyLength6 = copyIndex + 1;
              ch = ", "[copyIndex + 1];
              copyIndex = copyLength6;
            } while (ch != '\0');
            outCursor = outCursor + copyLength6 + copyEnd;
            copyEnd2 = ((int (*)())_ncpy_97bf2850)(outCursor, ((unsigned int *)constantData)[3]);
            ch = '}';
            outCursor = outCursor + copyEnd2;
            copyIndex = 0;
            do {
              outCursor[copyIndex] = ch;
              copyLength = copyIndex + 1;
              ch = "}"[copyIndex + 1];
              copyIndex = copyLength;
            } while (ch != '\0');
            goto LAB_97c040c4;
          default:
            goto switchD_97c02904_caseD_0;
          }
          break;
        case 0x12:
          ch = 'n';
          copyIndex = 0;
          do {
            outCursor[copyIndex] = ch;
            nextIndex4 = copyIndex + 1;
            ch = "normalscale"[copyIndex + 1];
            copyIndex = nextIndex4;
          } while (ch != '\0');
        }
        outCursor = outCursor + nextIndex4;
switchD_97c02904_caseD_0:
        if (allocation10[*(ushort *)((int)shader + entryByteOffset + paramOffset * 8 + 6)] == -1) {
          ch = ';';
          copyIndex6 = 0;
          do {
            outCursor[copyIndex6] = ch;
            copyLength8 = copyIndex6 + 1;
            ch = ";\n"[copyIndex6 + 1];
            copyIndex6 = copyLength8;
          } while (ch != '\0');
        }
        else if (loopIndex5 + 1 == allocation9[loopIndex7]) {
          loopIndex7 = loopIndex7 + 1;
          ch = '\n';
          copyIndex6 = 0;
          do {
            outCursor[copyIndex6] = ch;
            copyLength8 = copyIndex6 + 1;
            ch = "\n};\n"[copyIndex6 + 1];
            copyIndex6 = copyLength8;
          } while (ch != '\0');
        }
        else {
          ch = ',';
          copyIndex6 = 0;
          do {
            outCursor[copyIndex6] = ch;
            copyLength8 = copyIndex6 + 1;
            ch = ",\n"[copyIndex6 + 1];
            copyIndex6 = copyLength8;
          } while (ch != '\0');
        }
        outCursor = outCursor + copyLength8;
        callResultPair = ((int (*)())_adjustAllocation_97bf27d4)(&outCapacity,&outBuffer,&outCursor);
        if ((int)((ulonglong)callResultPair >> 0x20) == 0) {
          if (allocation3 != 0) {
            _free(allocation3);
          }
          allocation8 = outBuffer;
          if (allocation10 != (int *)0x0) {
            _free(allocation10);
            allocation8 = outBuffer;
          }
          goto joined_r0x97c02488;
        }
LAB_97c04238:
        loopIndex = loopIndex + 1;
      } while (loopIndex < paramCount);
    }
    if (allocation9 != (int *)0x0) {
      _free(allocation9);
    }
  }
  outputCount = shader[0xc];
  loopIndex2 = 0;
  outputOffset = shader[0xd];
  if (0 < outputCount) {
    do {
      outputKind = (uint)shader[outputOffset * 2 + loopIndex2 * 2] >> 0x10 & 0xf;
      if (outputKind == 0) goto LAB_97c04904;
      ch = 'O';
      copyIndex4 = 0;
      do {
        outCursor[copyIndex4] = ch;
        copyLength5 = copyIndex4 + 1;
        ch = "OUTPUT res"[copyIndex4 + 1];
        copyIndex4 = copyLength5;
      } while (ch != '\0');
      outCursor = outCursor + copyLength5;
      copyEnd8 = ((int (*)())_ncpy_97bf2850)(outCursor,(uint)*(ushort *)((int)shader + loopIndex2 * 8 + outputOffset * 8 + 6))
      ;
      ch = ' ';
      copyIndex4 = 0;
      do {
        outCursor[copyIndex4 + copyEnd8] = ch;
        copyLength3 = copyIndex4 + 1;
        ch = " = "[copyIndex4 + 1];
        copyIndex4 = copyLength3;
      } while (ch != '\0');
      outCursor = outCursor + copyLength3 + copyEnd8;
      switch(outputKind) {
      default:
        goto switchD_97c04350_caseD_0;
      case 1:
        ch = 'r';
        copyIndex4 = 0;
        do {
          outCursor[copyIndex4] = ch;
          nextIndex3 = copyIndex4 + 1;
          ch = "result.position"[copyIndex4 + 1];
          copyIndex4 = nextIndex3;
        } while (ch != '\0');
        break;
      case 2:
        ch = 'r';
        copyIndex4 = 0;
        do {
          outCursor[copyIndex4] = ch;
          nextIndex3 = copyIndex4 + 1;
          ch = "result.fogcoord"[copyIndex4 + 1];
          copyIndex4 = nextIndex3;
        } while (ch != '\0');
        break;
      case 3:
        ch = 'r';
        copyIndex4 = 0;
        do {
          outCursor[copyIndex4] = ch;
          nextIndex3 = copyIndex4 + 1;
          ch = "result.pointsize"[copyIndex4 + 1];
          copyIndex4 = nextIndex3;
        } while (ch != '\0');
        break;
      case 4:
        ch = 'r';
        copyIndex4 = 0;
        do {
          outCursor[copyIndex4] = ch;
          copyLength5 = copyIndex4 + 1;
          ch = "result.color"[copyIndex4 + 1];
          copyIndex4 = copyLength5;
        } while (ch != '\0');
        outCursor = outCursor + copyLength5;
        if (shaderTarget == 0x8b31) {
          if ((shader[outputOffset * 2 + loopIndex2 * 2] & 1U) == 0) {
            ch = '.';
            copyIndex4 = 0;
            do {
              outCursor[copyIndex4] = ch;
              nextIndex3 = copyIndex4 + 1;
              ch = ".front.primary"[copyIndex4 + 1];
              copyIndex4 = nextIndex3;
            } while (ch != '\0');
          }
          else {
            if ((shader[outputOffset * 2 + loopIndex2 * 2] & 1U) != 1) goto switchD_97c04350_caseD_0;
            ch = '.';
            copyIndex4 = 0;
            do {
              outCursor[copyIndex4] = ch;
              nextIndex3 = copyIndex4 + 1;
              ch = ".back.primary"[copyIndex4 + 1];
              copyIndex4 = nextIndex3;
            } while (ch != '\0');
          }
          break;
        }
        if ((shaderTarget == 0x8b30) && (1 < ((uint)shader[outputOffset * 2 + loopIndex2 * 2] >> 1 & 7))) {
          ch = '[';
          copyIndex4 = 0;
          do {
            outCursor[copyIndex4] = ch;
            copyLength5 = copyIndex4 + 1;
            ch = "["[copyIndex4 + 1];
            copyIndex4 = copyLength5;
          } while (ch != '\0');
          outCursor = outCursor + copyLength5;
          copyEnd4 = ((int (*)())_ncpy_97bf2850)(outCursor,(uint)shader[outputOffset * 2 + loopIndex2 * 2] >> 1 & 7);
          ch = ']';
          outCursor = outCursor + copyEnd4;
          copyIndex4 = 0;
          do {
            outCursor[copyIndex4] = ch;
            copyLength5 = copyIndex4 + 1;
            ch = "]"[copyIndex4 + 1];
            copyIndex4 = copyLength5;
          } while (ch != '\0');
          goto LAB_97c04804;
        }
        goto switchD_97c04350_caseD_0;
      case 5:
        ch = 'r';
        copyIndex4 = 0;
        do {
          outCursor[copyIndex4] = ch;
          copyLength5 = copyIndex4 + 1;
          ch = "result.color"[copyIndex4 + 1];
          copyIndex4 = copyLength5;
        } while (ch != '\0');
        outCursor = outCursor + copyLength5;
        if (shaderTarget == 0x8b31) {
          if ((shader[outputOffset * 2 + loopIndex2 * 2] & 1U) == 0) {
            ch = '.';
            copyIndex4 = 0;
            do {
              outCursor[copyIndex4] = ch;
              nextIndex3 = copyIndex4 + 1;
              ch = ".front.secondary"[copyIndex4 + 1];
              copyIndex4 = nextIndex3;
            } while (ch != '\0');
          }
          else {
            if ((shader[outputOffset * 2 + loopIndex2 * 2] & 1U) != 1) goto switchD_97c04350_caseD_0;
            ch = '.';
            copyIndex4 = 0;
            do {
              outCursor[copyIndex4] = ch;
              nextIndex3 = copyIndex4 + 1;
              ch = ".back.secondary"[copyIndex4 + 1];
              copyIndex4 = nextIndex3;
            } while (ch != '\0');
          }
          break;
        }
        goto switchD_97c04350_caseD_0;
      case 6:
        ch = 'r';
        copyIndex4 = 0;
        do {
          outCursor[copyIndex4] = ch;
          copyLength5 = copyIndex4 + 1;
          ch = "result.texcoord["[copyIndex4 + 1];
          copyIndex4 = copyLength5;
        } while (ch != '\0');
        outCursor = outCursor + copyLength5;
        copyEnd4 = ((int (*)())_ncpy_97bf2850)(outCursor,shader[outputOffset * 2 + loopIndex2 * 2] & 0x1f);
        ch = ']';
        outCursor = outCursor + copyEnd4;
        copyIndex4 = 0;
        do {
          outCursor[copyIndex4] = ch;
          copyLength5 = copyIndex4 + 1;
          ch = "]"[copyIndex4 + 1];
          copyIndex4 = copyLength5;
        } while (ch != '\0');
        goto LAB_97c04804;
      case 7:
        ch = 'r';
        copyIndex4 = 0;
        do {
          outCursor[copyIndex4] = ch;
          nextIndex3 = copyIndex4 + 1;
          ch = "result.depth"[copyIndex4 + 1];
          copyIndex4 = nextIndex3;
        } while (ch != '\0');
        break;
      case 8:
        ch = 'r';
        copyIndex4 = 0;
        do {
          outCursor[copyIndex4] = ch;
          nextIndex3 = copyIndex4 + 1;
          ch = "result.eyePosition"[copyIndex4 + 1];
          copyIndex4 = nextIndex3;
        } while (ch != '\0');
        break;
      case 9:
        ch = 'r';
        copyIndex4 = 0;
        do {
          outCursor[copyIndex4] = ch;
          nextIndex3 = copyIndex4 + 1;
          ch = "result.clipVertex"[copyIndex4 + 1];
          copyIndex4 = nextIndex3;
        } while (ch != '\0');
        break;
      case 10:
        ch = 'r';
        copyIndex4 = 0;
        do {
          outCursor[copyIndex4] = ch;
          copyLength5 = copyIndex4 + 1;
          ch = "result.attrib["[copyIndex4 + 1];
          copyIndex4 = copyLength5;
        } while (ch != '\0');
        outCursor = outCursor + copyLength5;
        copyEnd4 = ((int (*)())_ncpy_97bf2850)(outCursor,shader[outputOffset * 2 + loopIndex2 * 2] & 0x1f);
        ch = ']';
        outCursor = outCursor + copyEnd4;
        copyIndex4 = 0;
        do {
          outCursor[copyIndex4] = ch;
          copyLength5 = copyIndex4 + 1;
          ch = "]"[copyIndex4 + 1];
          copyIndex4 = copyLength5;
        } while (ch != '\0');
LAB_97c04804:
        outCursor = outCursor + copyLength5;
        goto switchD_97c04350_caseD_0;
      }
      outCursor = outCursor + nextIndex3;
switchD_97c04350_caseD_0:
      ch = ';';
      copyIndex4 = 0;
      do {
        outCursor[copyIndex4] = ch;
        copyLength5 = copyIndex4 + 1;
        ch = ";\n"[copyIndex4 + 1];
        copyIndex4 = copyLength5;
      } while (ch != '\0');
      outCursor = outCursor + copyLength5;
      adjustAllocationResult2 = ((int (*)())_adjustAllocation_97bf27d4)(&outCapacity,&outBuffer,&outCursor);
      if (adjustAllocationResult2 == 0) {
        allocation9 = allocation10;
        allocation8 = outBuffer;
        if (allocation3 != 0) {
          _free(allocation3);
          allocation8 = outBuffer;
        }
        goto joined_r0x97c02488;
      }
LAB_97c04904:
      loopIndex2 = loopIndex2 + 1;
    } while (loopIndex2 < outputCount);
  }
  ch = '\n';
  copyIndex7 = 0;
  do {
    outCursor[copyIndex7] = ch;
    copyLength9 = copyIndex7 + 1;
    ch = "\n"[copyIndex7 + 1];
    copyIndex7 = copyLength9;
  } while (ch != '\0');
  outCursor = outCursor + copyLength9;
  bodyCursor[0] = (char *)_malloc(outCapacity);
  allocation8 = outBuffer;
  if (bodyCursor[0] == (char *)0x0) goto LAB_97c04d50;
  instructionCount = shader[0x14];
  loopIndex2 = 0;
  instructionOffset = shader[0x15];
  loopIndex7 = 0;
  bodyStart = bodyCursor[0];
  if (0 < instructionCount) {
    do {
      glpDisassemble2OpResult = ((int (*)())_glpDisassemble2Op)(shader + instructionOffset * 2 + loopIndex7 * 2,bodyCursor[0],&wordsConsumed,&charsWritten,
                                 allocation3,allocation10,0,&outFlagWord,&usageFlags,shaderTarget,printOptions);
      if (glpDisassemble2OpResult == -1) {
LAB_97c04a0c:
        if (allocation3 != 0) {
          _free(allocation3);
        }
        if (allocation10 != (int *)0x0) {
          _free(allocation10);
        }
        goto LAB_97c04ab8;
      }
      bodyCursor[0] = bodyCursor[0] + charsWritten;
      loopIndex7 = loopIndex7 + wordsConsumed;
      adjustAllocationResult3 = ((int (*)())_adjustAllocation_97bf27d4)(&outCapacity,&bodyStart,bodyCursor);
      if (adjustAllocationResult3 == 0) goto LAB_97c04a0c;
      loopIndex2 = loopIndex2 + 1;
      loopIndex7 = loopIndex7 + 1;
    } while (loopIndex2 < instructionCount);
  }
  if (allocation3 != 0) {
    _free(allocation3);
  }
  if (allocation10 != (int *)0x0) {
    _free(allocation10);
  }
  ch = 'E';
  copyIndex2 = 0;
  do {
    bodyCursor[0][copyIndex2] = ch;
    copyLength2 = copyIndex2 + 1;
    ch = "END\n"[copyIndex2 + 1];
    copyIndex2 = copyLength2;
  } while (ch != '\0');
  bodyCursor[0] = bodyCursor[0] + copyLength2;
  allocation8 = (char *)_malloc(outCapacity);
  if (allocation8 == (char *)0x0) {
LAB_97c04ab8:
    _free(outBuffer);
    allocation8 = bodyStart;
    goto LAB_97c04d50;
  }
  if (*shader == 0x8b30) {
    ch = '!';
    copyIndex2 = 0;
    do {
      allocation8[copyIndex2] = ch;
      copyLength2 = copyIndex2 + 1;
      ch = "!!ARBfp1.0\n\n"[copyIndex2 + 1];
      copyIndex2 = copyLength2;
    } while (ch != '\0');
  }
  else if (*shader == 0x8b31) {
    ch = '!';
    copyIndex2 = 0;
    do {
      allocation8[copyIndex2] = ch;
      copyLength2 = copyIndex2 + 1;
      ch = "!!ARBvp1.0\n\n"[copyIndex2 + 1];
      copyIndex2 = copyLength2;
    } while (ch != '\0');
  }
  else {
    ch = 'U';
    copyIndex2 = 0;
    do {
      allocation8[copyIndex2] = ch;
      copyLength2 = copyIndex2 + 1;
      ch = "Unknown Target (error)\n\n"[copyIndex2 + 1];
      copyIndex2 = copyLength2;
    } while (ch != '\0');
  }
  allocation6 = allocation8 + copyLength2;
  if ((usageFlags & 0x200000) == 0) {
    if ((usageFlags & 0x100000) != 0) {
      ch = 'O';
      copyIndex2 = 0;
      do {
        allocation6[copyIndex2] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "OPTION NV_vertex_program2;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      goto LAB_97c04c18;
    }
  }
  else {
    ch = 'O';
    copyIndex2 = 0;
    do {
      allocation6[copyIndex2] = ch;
      copyLength2 = copyIndex2 + 1;
      ch = "OPTION NV_vertex_program3;\n"[copyIndex2 + 1];
      copyIndex2 = copyLength2;
    } while (ch != '\0');
LAB_97c04c18:
    allocation6 = allocation6 + copyLength2;
  }
  if ((usageFlags & 0x800000) == 0) {
    if ((usageFlags & 0x400000) != 0) {
      ch = 'O';
      copyIndex2 = 0;
      do {
        allocation6[copyIndex2] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "OPTION NV_fragment_program;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      goto LAB_97c04c9c;
    }
  }
  else {
    ch = 'O';
    copyIndex2 = 0;
    do {
      allocation6[copyIndex2] = ch;
      copyLength2 = copyIndex2 + 1;
      ch = "OPTION NV_fragment_program2;\n"[copyIndex2 + 1];
      copyIndex2 = copyLength2;
    } while (ch != '\0');
LAB_97c04c9c:
    allocation6 = allocation6 + copyLength2;
  }
  if ((usageFlags & 0x1000000) != 0) {
    ch = 'O';
    copyIndex2 = 0;
    do {
      allocation6[copyIndex2] = ch;
      copyLength2 = copyIndex2 + 1;
      ch = "OPTION ARB_fragment_program_shadow;\n"[copyIndex2 + 1];
      copyIndex2 = copyLength2;
    } while (ch != '\0');
    allocation6 = allocation6 + copyLength2;
  }
  if ((usageFlags & 0xf00000) != 0) {
    ch = '\n';
    copyIndex2 = 0;
    do {
      allocation6[copyIndex2] = ch;
      copyLength2 = copyIndex2 + 1;
      ch = "\n"[copyIndex2 + 1];
      copyIndex2 = copyLength2;
    } while (ch != '\0');
    allocation6 = allocation6 + copyLength2;
  }
  allocation = (char *)_malloc(outCapacity);
  if (allocation != (char *)0x0) {
    allocation7 = allocation;
    if ((usageFlags & 0x1000) != 0) {
      ch = 'P';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "PARAM kARRAY1 = { 0.0, 1.0, 2.0, 3.0 };\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2 + copyLength2] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kZERO       = kARRAY1.xxxx;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      nextIndex5 = copyLength4 + copyLength2;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2 + nextIndex5] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kONE        = kARRAY1.yyyy;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      nextIndex6 = copyLength2 + nextIndex5;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2 + nextIndex6] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kTWO        = kARRAY1.zzzz;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      nextIndex5 = copyLength4 + nextIndex6;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2 + nextIndex5] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kTHREE      = kARRAY1.wwww;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      nextIndex6 = copyLength2 + nextIndex5;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2 + nextIndex6] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kSEL        = kARRAY1;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      nextIndex5 = copyLength4 + nextIndex6;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2 + nextIndex5] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kFLOAT      = kARRAY1.yxxx;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      nextIndex6 = copyLength2 + nextIndex5;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2 + nextIndex6] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kVEC2       = kARRAY1.yyxx;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      nextIndex5 = copyLength4 + nextIndex6;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2 + nextIndex5] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kVEC3       = kARRAY1.yyyx;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      nextIndex6 = copyLength2 + nextIndex5;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation[copyIndex2 + nextIndex6] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kVEC4       = kARRAY1.yyyy;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      allocation7 = allocation + copyLength4 + nextIndex6;
    }
    if ((usageFlags & 0x2000) != 0) {
      ch = 'P';
      loopIndex6 = 0;
      do {
        allocation7[loopIndex6] = ch;
        nextIndex = loopIndex6 + 1;
        ch = "PARAM kARRAY2 = { 0.5, 3.141592653589793, 6.283185307179586, 1.570796326794897 };\n"
                [loopIndex6 + 1];
        loopIndex6 = nextIndex;
      } while (ch != '\0');
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + nextIndex] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kHALF       = kARRAY2.xxxx;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      nextIndex5 = copyLength4 + nextIndex;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + nextIndex5] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kPI         = kARRAY2.yyyy;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      nextIndex6 = copyLength2 + nextIndex5;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + nextIndex6] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS k2PI        = kARRAY2.zzzz;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      nextIndex5 = copyLength4 + nextIndex6;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + nextIndex5] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kHALFPI     = kARRAY2.wwww;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      allocation7 = allocation7 + copyLength2 + nextIndex5;
    }
    if ((usageFlags & 0x4000) != 0) {
      ch = 'P';
      loopIndex6 = 0;
      do {
        allocation7[loopIndex6] = ch;
        nextIndex = loopIndex6 + 1;
        ch = "PARAM kARRAY3 = { 0.636619772367581, 0.31830988618379067, 0.159154943091895, -0.0962243 };\n"
                [loopIndex6 + 1];
        loopIndex6 = nextIndex;
      } while (ch != '\0');
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + nextIndex] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kHALFPI_RCP = kARRAY3.xxxx;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      nextIndex5 = copyLength4 + nextIndex;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + nextIndex5] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kPI_RCP     = kARRAY3.yyyy;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      nextIndex6 = copyLength2 + nextIndex5;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + nextIndex6] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS k2PI_RCP    = kARRAY3.zzzz;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      nextIndex5 = copyLength4 + nextIndex6;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + nextIndex5] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kTAN_K1     = kARRAY3.wwww;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      allocation7 = allocation7 + copyLength2 + nextIndex5;
    }
    if ((usageFlags & 0x8000) != 0) {
      ch = 'P';
      loopIndex6 = 0;
      do {
        allocation7[loopIndex6] = ch;
        nextIndex = loopIndex6 + 1;
        ch = "PARAM kARRAY4 = { -0.429562, 0.00986998, 57.295779513082, 0.0174532925199 };\n"
                [loopIndex6 + 1];
        loopIndex6 = nextIndex;
      } while (ch != '\0');
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + nextIndex] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kTAN_K2     = kARRAY4.xxxx;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      nextIndex5 = copyLength4 + nextIndex;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + nextIndex5] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kTAN_K3     = kARRAY4.yyyy;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      nextIndex6 = copyLength2 + nextIndex5;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + nextIndex6] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kDEGREES    = kARRAY4.zzzz;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      nextIndex5 = copyLength4 + nextIndex6;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + nextIndex5] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kRADIANS    = kARRAY4.wwww;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      allocation7 = allocation7 + copyLength2 + nextIndex5;
    }
    if ((usageFlags & 0x10000) != 0) {
      ch = 'P';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "PARAM kARRAY5 = { 0.999918, 0.746304, 0.414164, 0.054165 };\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + copyLength2] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kATAN_K1    = kARRAY5.xxxx;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      nextIndex5 = copyLength4 + copyLength2;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + nextIndex5] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kATAN_K2    = kARRAY5.yyyy;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      nextIndex6 = copyLength2 + nextIndex5;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + nextIndex6] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kATAN_K3    = kARRAY5.zzzz;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      nextIndex5 = copyLength4 + nextIndex6;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + nextIndex5] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kATAN_K4    = kARRAY5.wwww;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      allocation7 = allocation7 + copyLength2 + nextIndex5;
    }
    if ((usageFlags & 0x20000) != 0) {
      ch = 'P';
      loopIndex6 = 0;
      do {
        allocation7[loopIndex6] = ch;
        nextIndex = loopIndex6 + 1;
        ch = "PARAM kARRAY6 = { 0.671088e-17, 2.718281828459045, 0.69314718056, 0.0 };\n"
                [loopIndex6 + 1];
        loopIndex6 = nextIndex;
      } while (ch != '\0');
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + nextIndex] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS kOFFSET     = kARRAY6.xxxx;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      nextIndex5 = copyLength4 + nextIndex;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + nextIndex5] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "ALIAS kE          = kARRAY6.y;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      nextIndex6 = copyLength2 + nextIndex5;
      ch = 'A';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2 + nextIndex6] = ch;
        copyLength4 = copyIndex2 + 1;
        ch = "ALIAS k1_OVER_LOG2_E = kARRAY6.zzzz;\n"[copyIndex2 + 1];
        copyIndex2 = copyLength4;
      } while (ch != '\0');
      allocation7 = allocation7 + copyLength4 + nextIndex6;
    }
    if ((usageFlags & 0xff000) != 0) {
      ch = '\n';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      allocation7 = allocation7 + copyLength2;
    }
    loopIndex4 = 0;
    pendingUsageFlags = usageFlags;
    while ((pendingUsageFlags & 1) != 0) {
      ch = 'T';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "TEMP scratch"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      allocation7 = allocation7 + copyLength2;
      if (loopIndex4 != 0) {
        copyEnd5 = ((int (*)())_ncpy_97bf2850)(allocation7,loopIndex4);
        allocation7 = allocation7 + copyEnd5;
      }
      ch = ';';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = ";\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      loopIndex4 = loopIndex4 + 1;
      allocation7 = allocation7 + copyLength2;
      pendingUsageFlags = (int)usageFlags >> (loopIndex4 & 0x3f);
    }
    if ((usageFlags & 0xfff) != 0) {
      ch = '\n';
      copyIndex2 = 0;
      do {
        allocation7[copyIndex2] = ch;
        copyLength2 = copyIndex2 + 1;
        ch = "\n"[copyIndex2 + 1];
        copyIndex2 = copyLength2;
      } while (ch != '\0');
      allocation7 = allocation7 + copyLength2;
    }
    allocation2 = _malloc(allocation7 + (int)(allocation6 +
                                    (int)(outCursor +
                                         (int)(bodyCursor[0] +
                                              (((-(int)outBuffer - (int)allocation8) - (int)allocation) -
                                              (int)bodyStart) + 1))));
    *allocation6 = '\0';
    copyIndex9 = 0;
    *outCursor = '\0';
    *allocation7 = '\0';
    *bodyCursor[0] = '\0';
    ch = *allocation8;
    while (ch != '\0') {
      *(char *)(allocation2 + copyIndex9) = ch;
      copyIndex9 = copyIndex9 + 1;
      ch = allocation8[copyIndex9];
    }
    copyIndex10 = 0;
    ch = *outBuffer;
    while (ch != '\0') {
      *(char *)(allocation2 + copyIndex9 + copyIndex10) = ch;
      copyIndex10 = copyIndex10 + 1;
      ch = outBuffer[copyIndex10];
    }
    copyIndex11 = allocation2 + copyIndex9 + copyIndex10;
    copyIndex9 = 0;
    ch = *allocation;
    while (ch != '\0') {
      *(char *)(copyIndex11 + copyIndex9) = ch;
      copyIndex9 = copyIndex9 + 1;
      ch = allocation[copyIndex9];
    }
    copyIndex11 = copyIndex11 + copyIndex9;
    copyIndex9 = 0;
    ch = *bodyStart;
    while (ch != '\0') {
      *(char *)(copyIndex11 + copyIndex9) = ch;
      copyIndex9 = copyIndex9 + 1;
      ch = bodyStart[copyIndex9];
    }
    *(undefined1 *)(copyIndex11 + copyIndex9) = 0;
    _free(allocation8);
    _free(outBuffer);
    _free(allocation);
    _free(bodyStart);
    return allocation2;
  }
  _free(outBuffer);
  _free(bodyStart);
LAB_97c04d50:
  _free(allocation8);
  return 0;
}

/* _glpPPShaderToProgram @ 0x97c057a4 (472 bytes) */
int _glpPPShaderToProgram(shader, printOptions, printFlags)
  int *shader;
  undefined4 printOptions;
  undefined4 printFlags;
{
  int glpPPShaderToProgramStringResult;
  undefined4 allocation2;
  undefined4 ppStreamCreateResult;
  int ppParserParseResult;
  int parser;
  undefined4 limitAt450;
  undefined4 limitAt454;
  undefined4 limitAt458;
  undefined4 limitAt45c;
  undefined4 limitAt460;
  undefined4 limitAt464;
  undefined4 limitAt468;
  undefined4 limitAt46c;
  undefined4 limitAt470;
  undefined4 limitAt474;
  undefined4 limitAt478;
  undefined4 limitAt47c;
  undefined4 limitAt480;
  undefined4 limitAt484;
  undefined4 limitAt488;
  undefined4 streamInfo [5];
  
  _memset(&limitAt450,0,0x3c);
  glpPPShaderToProgramStringResult = ((int (*)())_glpPPShaderToProgramString)(shader,printOptions,printFlags);
  parser = 0;
  allocation2 = 0;
  if (glpPPShaderToProgramStringResult != 0) {
    if (*shader == 0x8b30) {
      parser = _PPParserCreate(2);
      limitAt460 = 0x100;
      limitAt45c = 0x8000;
      limitAt464 = 0x80;
      limitAt468 = 0x40;
      limitAt46c = 0;
      limitAt450 = 0x80;
      limitAt454 = 0x80;
      limitAt488 = 0;
    }
    else if (*shader == 0x8b31) {
      parser = _PPParserCreate(0);
      limitAt488 = 0x10;
      limitAt45c = 0x8000;
      limitAt464 = 0x100;
      limitAt468 = 0x20;
      limitAt46c = 2;
      limitAt450 = 0x100;
      limitAt454 = 0x100;
      limitAt460 = 0x100;
    }
    ppStreamCreateResult = _PPStreamCreate();
    _PPParserAttachStream(parser,ppStreamCreateResult);
    limitAt474 = 0x10;
    limitAt478 = 4;
    limitAt47c = 1;
    limitAt480 = 6;
    limitAt484 = 8;
    limitAt458 = 8;
    limitAt470 = 8;
    _memcpy(parser + 0x450,&limitAt450,0x3c);
    _PPParserAttachString(parser,glpPPShaderToProgramStringResult,1);
    ppParserParseResult = _PPParserParse(parser);
    allocation2 = 0;
    if (ppParserParseResult == 0) {
      _PPStreamGetStream(ppStreamCreateResult,0,streamInfo);
      allocation2 = _calloc(streamInfo[0],8);
      _PPStreamGetStream(ppStreamCreateResult,allocation2,streamInfo);
      _PPStreamFree(ppStreamCreateResult);
      _PPParserFree(parser);
      _free(glpPPShaderToProgramStringResult);
    }
  }
  return allocation2;
}

/* _glpFreePPShaderToProgram @ 0x97c0597c (12 bytes) */
int _glpFreePPShaderToProgram(program)
  int program;
{
  if (program == 0) {
    return;
  }
  return _free(program);
}

/* _glpUniformToFloat @ 0x97c05988 (344 bytes) */
int _glpUniformToFloat(shader, registerNumber, uniformValue, floatOut)
  int shader;
  uint registerNumber;
  float *uniformValue;
  float *floatOut;
{
  float component0;
  float component1;
  float component2;
  bool found;
  bool isIntegerUniform;
  double intToDoubleBias;
  int paramTable;
  uint entryWord0;
  int paramCount;
  int loopIndex;
  
  intToDoubleBias = DOUBLE_97c30a58;
  if (shader != 0) {
    paramCount = *(int *)(shader + 0x28);
    found = false;
    isIntegerUniform = false;
    paramTable = shader + *(int *)(shader + 0x2c) * 8;
    if (paramCount != 0) {
      loopIndex = 0;
      if (0 < paramCount) {
        do {
          entryWord0 = *(uint *)(paramTable + loopIndex * 8);
          if (((entryWord0 >> 0x10 & 0x1f) == 1) && ((entryWord0 & 0xffff) == registerNumber)) {
            found = true;
            if ((-1 < *(int *)(loopIndex * 8 + paramTable + 4)) && ((entryWord0 >> 0x1a & 7) != 1)) {
              isIntegerUniform = true;
            }
            break;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex < paramCount);
      }
      if (found) {
        if (isIntegerUniform) {
          *floatOut = (float)((double)CONCAT44(0x43300000,-*uniformValue) - DOUBLE_97c30a58);
          floatOut[1] = (float)((double)CONCAT44(0x43300000,-uniformValue[1]) - intToDoubleBias);
          floatOut[2] = (float)((double)CONCAT44(0x43300000,-uniformValue[2]) - intToDoubleBias);
          floatOut[3] = (float)((double)CONCAT44(0x43300000,-uniformValue[3]) - intToDoubleBias);
        }
        else {
          component0 = *uniformValue;
          component1 = uniformValue[1];
          component2 = uniformValue[2];
          floatOut[3] = uniformValue[3];
          *floatOut = component0;
          floatOut[1] = component1;
          floatOut[2] = component2;
        }
      }
    }
  }
  return;
}

/* _glpUniformsToFloats @ 0x97c05ae0 (144 bytes) */
int _glpUniformsToFloats(shader, uniformValues, floatsOut)
  int shader;
  int uniformValues;
  int floatsOut;
{
  int registerByteOffset;
  int paramOffset;
  uint entryWord0;
  int paramCount;
  int entryIndex;
  
  if (shader != 0) {
    paramCount = *(int *)(shader + 0x28);
    paramOffset = *(int *)(shader + 0x2c);
    if ((paramCount != 0) && (entryIndex = 0, 0 < paramCount)) {
      do {
        entryWord0 = *(uint *)(shader + paramOffset * 8 + entryIndex * 8);
        if ((entryWord0 >> 0x10 & 0x1f) == 1) {
          entryWord0 = entryWord0 & 0xffff;
          registerByteOffset = entryWord0 * 0x10;
          ((int (*)())_glpUniformToFloat)(shader,entryWord0,uniformValues + registerByteOffset,floatsOut + registerByteOffset);
        }
        entryIndex = entryIndex + 1;
      } while (entryIndex < paramCount);
    }
  }
  return;
}

/* _handleDigit_97c05b70 @ 0x97c05b70 (112 bytes) */
int _handleDigit_97c05b70(writeCursorPtr, value)
  int *writeCursorPtr;
  int value;
{
  int leadingValue;
  
  leadingValue = value / 10;
  if (leadingValue != 0) {
    ((int (*)())_handleDigit_97c05b70)(writeCursorPtr,leadingValue);
  }
  *(char *)*writeCursorPtr = (char)value + (char)leadingValue * -10 + '0';
  *writeCursorPtr = *writeCursorPtr + 1;
  return;
}

/* _clearFuncInfoList @ 0x97c05be0 (68 bytes) */
int _clearFuncInfoList(funcInfos, count)
  int funcInfos;
  int count;
{
  int recordOffset;
  int record;
  int recordIndex;
  
  recordIndex = 0;
  if (count != 0) {
    do {
      recordOffset = recordIndex * 0x20;
      recordIndex = recordIndex + 1;
      record = recordOffset + funcInfos;
      *(undefined4 *)(funcInfos + recordOffset) = 0xffffffff;
      *(undefined4 *)(record + 0x14) = 0;
      *(undefined4 *)(record + 4) = 0xffffffff;
      *(undefined4 *)(record + 8) = 0;
      *(undefined4 *)(record + 0xc) = 0;
      *(undefined4 *)(record + 0x10) = 0;
      count = count + -1;
    } while (count != 0);
    return;
  }
  return;
}

/* _UpdateFunctionIndex @ 0x97c05c24 (60 bytes) */
int _UpdateFunctionIndex(notFoundIndex, key, funcInfos, count)
  uint notFoundIndex;
  int key;
  int funcInfos;
  uint count;
{
  uint recordIndex;
  
  recordIndex = 0;
  if (count != 0) {
    do {
      if (key == *(int *)(funcInfos + recordIndex * 0x20)) break;
      recordIndex = recordIndex + 1;
    } while (recordIndex < count);
  }
  if (recordIndex == count) {
    recordIndex = notFoundIndex;
  }
  return recordIndex;
}

/* _RecordFunctionCall @ 0x97c05c60 (188 bytes) */
int _RecordFunctionCall(key, funcInfosPtr, count)
  int key;
  int *funcInfosPtr;
  uint count;
{
  int allocation;
  uint loopIndex;
  
  loopIndex = 0;
  if (count != 0) {
    do {
      if (key == *(int *)(loopIndex * 0x20 + *funcInfosPtr)) break;
      loopIndex = loopIndex + 1;
    } while (loopIndex < count);
  }
  if (loopIndex == count) {
    if ((count & 0x7f) == 0) {
      allocation = _malloc(count * 0x20 + 0x1000);
      ((int (*)())_clearFuncInfoList)(allocation,count + 0x80);
      _memcpy(allocation,*funcInfosPtr,count * 0x20);
      if (*funcInfosPtr != 0) {
        _free(*funcInfosPtr);
      }
      *funcInfosPtr = allocation;
    }
    count = count + 1;
    *(int *)(loopIndex * 0x20 + *funcInfosPtr) = key;
  }
  return count;
}

/* _RecordFunctionEdge @ 0x97c05d1c (72 bytes) */
int _RecordFunctionEdge(currentIndex, key, edgeValue, funcInfos, count)
  uint currentIndex;
  int key;
  undefined4 edgeValue;
  int funcInfos;
  uint count;
{
  uint loopIndex;
  
  loopIndex = 0;
  if (count == 0) {
    return currentIndex;
  }
  do {
    if (key == *(int *)(funcInfos + loopIndex * 0x20)) {
      if (-1 < (int)currentIndex) {
        *(undefined4 *)(currentIndex * 0x20 + funcInfos + 4) = edgeValue;
      }
      return loopIndex;
    }
    loopIndex = loopIndex + 1;
  } while (loopIndex < count);
  return currentIndex;
}

/* _ClearJumpTable @ 0x97c05d64 (92 bytes) */
int _ClearJumpTable(jumpTable)
  int jumpTable;
{
  if (*(int *)(jumpTable + 0xc) != 0) {
    _free(*(undefined4 *)(jumpTable + 0x10));
    _free(*(undefined4 *)(jumpTable + 0x14));
    *(undefined4 *)(jumpTable + 0xc) = 0;
    *(undefined4 *)(jumpTable + 0x10) = 0;
    *(undefined4 *)(jumpTable + 0x14) = 0;
  }
  *(undefined4 *)(jumpTable + 8) = 0;
  return;
}

/* _AddOpToJumpTable @ 0x97c05dc0 (396 bytes) */
int _AddOpToJumpTable(inst, jumpTable)
  uint *inst;
  int jumpTable;
{
  int targetByteOffset;
  uint branchCountCopy;
  uint loopIndex;
  uint loopIndex2;
  int sourceByteOffset;
  uint branchCount;
  int allocation;
  uint instWord0;
  
  *(int *)(jumpTable + 8) = *(int *)(jumpTable + 8) + 1;
  instWord0 = *inst;
  switch(instWord0 >> 0x12 & 0xff) {
  case 0x4b:
  case 0x4c:
  case 0x54:
  case 0x55:
  case 0x56:
  case 0x57:
  case 0x58:
  case 0x5a:
  case 0x5b:
  case 0x69:
  case 0x6a:
  case 0x6b:
    branchCount = *(uint *)(jumpTable + 0xc);
    if ((branchCount & 0x7f) == 0) {
      allocation = _malloc(branchCount * 4 + 0x200);
      _memset(allocation,0,*(int *)(jumpTable + 0xc) * 4 + 0x200);
      loopIndex2 = 0;
      branchCountCopy = 0;
      if (*(int *)(jumpTable + 0xc) != 0) {
        do {
          sourceByteOffset = loopIndex2 * 4;
          loopIndex2 = loopIndex2 + 1;
          *(undefined4 *)(sourceByteOffset + allocation) = *(undefined4 *)(sourceByteOffset + *(int *)(jumpTable + 0x10));
          branchCountCopy = *(uint *)(jumpTable + 0xc);
        } while (loopIndex2 < branchCountCopy);
      }
      if (*(int *)(jumpTable + 0x10) != 0) {
        _free(*(int *)(jumpTable + 0x10));
        branchCountCopy = *(uint *)(jumpTable + 0xc);
      }
      *(int *)(jumpTable + 0x10) = allocation;
      allocation = _malloc(branchCountCopy * 4 + 0x200);
      _memset(allocation,0,*(int *)(jumpTable + 0xc) * 4 + 0x200);
      loopIndex = 0;
      branchCount = 0;
      if (*(int *)(jumpTable + 0xc) != 0) {
        do {
          targetByteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *(undefined4 *)(targetByteOffset + allocation) = *(undefined4 *)(targetByteOffset + *(int *)(jumpTable + 0x14));
          branchCount = *(uint *)(jumpTable + 0xc);
        } while (loopIndex < branchCount);
      }
      if (*(int *)(jumpTable + 0x14) != 0) {
        _free(*(int *)(jumpTable + 0x14));
        branchCount = *(uint *)(jumpTable + 0xc);
      }
      *(int *)(jumpTable + 0x14) = allocation;
      instWord0 = *inst;
    }
    *(uint *)(branchCount * 4 + *(int *)(jumpTable + 0x10)) = instWord0 & 0x3ffff;
    *(uint *)(*(int *)(jumpTable + 0xc) * 4 + *(int *)(jumpTable + 0x14)) = inst[1] & 0x3ffff;
    *(int *)(jumpTable + 0xc) = *(int *)(jumpTable + 0xc) + 1;
  }
  return;
}

/* _UpdateFunctionTable @ 0x97c05fd0 (68 bytes) */
int _UpdateFunctionTable(oldKey, newKey0, newKey1, funcInfos, count)
  int oldKey;
  undefined4 newKey0;
  undefined4 newKey1;
  int funcInfos;
  int count;
{
  int recordOffset;
  int recordIndex;
  
  recordIndex = 0;
  if (count != 0) {
    do {
      recordOffset = recordIndex * 0x20;
      if (oldKey == *(int *)(recordOffset + funcInfos)) {
        *(undefined4 *)(recordOffset + funcInfos) = newKey0;
      }
      if (oldKey == *(int *)(recordOffset + funcInfos + 4)) {
        *(undefined4 *)(recordOffset + funcInfos + 4) = newKey1;
      }
      recordIndex = recordIndex + 1;
      count = count + -1;
    } while (count != 0);
    return;
  }
  return;
}

/* _FindFunctionIndex @ 0x97c06014 (48 bytes) */
int _FindFunctionIndex(key, funcInfos, count)
  int key;
  int funcInfos;
  uint count;
{
  uint loopIndex;
  
  loopIndex = 0;
  if (count != 0) {
    do {
      if (key == *(int *)(funcInfos + loopIndex * 0x20)) {
        return loopIndex;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < count);
  }
  return loopIndex;
}

/* _InlineFunctionsBranch @ 0x97c06044 (1488 bytes) */
int _InlineFunctionsBranch(stream)
  int stream;
{
  bool inDeadFunction;
  bool copyingCallee;
  int endChunk;
  undefined4 keepIndexFlag;
  uint recordKey;
  uint continuationIndex;
  uint insertedWord1;
  uint funcInfoIndex;
  uint funcSearchIndex;
  uint funcScanWord0;
  uint callOpIndex;
  uint opIndex;
  uint inlinedStartIndex;
  uint previousOpIndex;
  int funcRecordByteOffset;
  int continuationChunk;
  int calleeChunk;
  int funcRecordOffset;
  int nextChunk;
  int findFunctionIndexResult;
  bool beforeCalleeEnd;
  uint calleeWord0;
  int *opList;
  int scanChunk;
  undefined4 lastResult;
  int calleeRecordOffset;
  int insertedChunk;
  undefined4 r3AfterFreeFuncInfos;
  uint opWord0;
  int opsScanned;
  uint returnWord0;
  uint scanWord0;
  int loopIndex;
  uint funcCount;
  int currentFuncIndex;
  int opChunk;
  bool noOps;
  int callPredecessor;
  uint opHeader;
  uint opFlags;
  int funcInfos [6];
  
  opList = *(int **)(stream + 0x20);
  funcInfos[0] = 0;
  opIndex = 0;
  opChunk = *opList;
  funcCount = 0;
  currentFuncIndex = -1;
  if (opChunk != 0) {
    do {
      opWord0 = *(uint *)(opChunk + 0xc);
      opIndex = opWord0 & 0x3ffff;
      if (opIndex == 0) {
        funcCount = ((int (*)())_RecordFunctionCall)(0,funcInfos,funcCount);
        opWord0 = *(uint *)(opChunk + 0xc);
      }
      if ((opWord0 >> 0x12 & 0xff) == 0x4c) {
        funcCount = ((int (*)())_RecordFunctionCall)(*(uint *)(opChunk + 0x10) & 0x3ffff,funcInfos,funcCount);
      }
      opChunk = *(int *)(opChunk + 8);
    } while (opChunk != 0);
    opList = *(int **)(stream + 0x20);
  }
  previousOpIndex = 0;
  for (opChunk = *opList; opChunk != 0; opChunk = *(int *)(opChunk + 8)) {
    opIndex = *(uint *)(opChunk + 0xc) & 0x3ffff;
    currentFuncIndex = ((int (*)())_RecordFunctionEdge)(currentFuncIndex,opIndex,previousOpIndex,funcInfos[0],funcCount);
    ((int (*)())_AddOpToJumpTable)(opChunk + 0xc,funcInfos[0] + currentFuncIndex * 0x20);
    previousOpIndex = opIndex;
  }
  lastResult = ((int (*)())_RecordFunctionEdge)(currentFuncIndex,0,opIndex,funcInfos[0],funcCount);
  if (1 < funcCount) {
    opList = *(int **)(stream + 0x20);
    opChunk = *opList;
    noOps = opChunk == 0;
    if (!noOps) {
      do {
        currentFuncIndex = ((int (*)())_UpdateFunctionIndex)(currentFuncIndex,*(uint *)(opChunk + 0xc) & 0x3ffff,funcInfos[0],funcCount);
        callPredecessor = opChunk;
        if ((*(uint *)(opChunk + 0xc) >> 0x12 & 0xff) == 0x4c) {
          inlinedStartIndex = 0xffffffff;
          loopIndex = 0;
          findFunctionIndexResult = ((int (*)())_FindFunctionIndex)(*(uint *)(opChunk + 0x10) & 0x3ffff,funcInfos[0],funcCount);
          returnWord0 = *(uint *)(*(int *)(opChunk + 8) + 0xc);
          callOpIndex = *(uint *)(opChunk + 0xc) & 0x3ffff;
          callPredecessor = *(int *)(opChunk + 4);
          calleeRecordOffset = findFunctionIndexResult * 0x20;
          _PPStreamChunkListRemoveChunk(*(undefined4 *)(stream + 0x20),opChunk);
          calleeChunk = **(int **)(stream + 0x20);
          calleeWord0 = *(uint *)(calleeChunk + 0xc);
          while (*(uint *)(calleeRecordOffset + funcInfos[0]) != (calleeWord0 & 0x3ffff)) {
            calleeChunk = *(int *)(calleeChunk + 8);
            calleeWord0 = *(uint *)(calleeChunk + 0xc);
          }
          copyingCallee = true;
          insertedChunk = callPredecessor;
          do {
            _memcpy(&opHeader,calleeChunk + 0xc,0x38);
            if (((opHeader >> 0x12 & 0xff) == 0x4d) &&
               ((opHeader & 0x3ffff) != *(uint *)(calleeRecordOffset + funcInfos[0] + 4))) {
              opFlags = returnWord0 & 0x3ffff | opFlags & 0xfffc0000;
              opHeader = opHeader & 0xfc03ffff | 0x12c0000;
            }
            else if ((opHeader >> 0x12 & 0xff) == 0x4d) {
              opHeader = opHeader & 0xfc03ffff | 0x1b80000;
            }
            keepIndexFlag = 0;
            if ((callOpIndex == 0) && (inlinedStartIndex == 0xffffffff)) {
              keepIndexFlag = 1;
            }
            insertedChunk = _PPStreamInsertOperationAfterChunk(stream,&opHeader,calleeChunk + 0x44,keepIndexFlag,insertedChunk);
            insertedWord1 = *(uint *)(insertedChunk + 0x10);
            if ((insertedWord1 & 0x3ffff) != 0) {
              opsScanned = 0;
              scanChunk = **(int **)(stream + 0x20);
              scanWord0 = *(uint *)(scanChunk + 0xc);
              while (*(uint *)(calleeRecordOffset + funcInfos[0]) != (scanWord0 & 0x3ffff)) {
                scanChunk = *(int *)(scanChunk + 8);
                scanWord0 = *(uint *)(scanChunk + 0xc);
              }
              beforeCalleeEnd = true;
              while ((scanWord0 & 0x3ffff) != (insertedWord1 & 0x3ffff)) {
                if ((scanWord0 & 0x3ffff) == *(uint *)(calleeRecordOffset + funcInfos[0] + 4)) {
                  beforeCalleeEnd = false;
                }
                scanChunk = *(int *)(scanChunk + 8);
                opsScanned = opsScanned + 1;
                if (!beforeCalleeEnd) goto LAB_97c0638c;
                scanWord0 = *(uint *)(scanChunk + 0xc);
              }
              *(uint *)(insertedChunk + 0x10) =
                   ((*(uint *)(insertedChunk + 0xc) & 0x3ffff) - loopIndex) + opsScanned & 0x3ffff |
                   insertedWord1 & 0xfffc0000;
            }
LAB_97c0638c:
            if (inlinedStartIndex == 0xffffffff) {
              inlinedStartIndex = *(uint *)(insertedChunk + 0xc) & 0x3ffff;
            }
            if ((*(uint *)(calleeChunk + 0xc) & 0x3ffff) == *(uint *)(calleeRecordOffset + funcInfos[0] + 4)) {
              copyingCallee = false;
            }
            calleeChunk = *(int *)(calleeChunk + 8);
            loopIndex = loopIndex + 1;
          } while (copyingCallee);
          if (loopIndex < 1) {
            continuationChunk = *(int *)(insertedChunk + 8);
            if (callOpIndex == 0) {
              *(uint *)(continuationChunk + 0xc) = *(uint *)(continuationChunk + 0xc) & 0xfffc0000;
            }
            inlinedStartIndex = *(uint *)(continuationChunk + 0xc) & 0x3ffff;
            continuationIndex = inlinedStartIndex;
          }
          else {
            continuationIndex = *(uint *)(insertedChunk + 0xc) & 0x3ffff;
          }
          noOps = callPredecessor == 0;
          _PPStreamChangeBranchTargets(stream,callOpIndex,inlinedStartIndex);
          ((int (*)())_UpdateFunctionTable)(callOpIndex,inlinedStartIndex,continuationIndex,funcInfos[0],funcCount);
        }
        funcRecordByteOffset = currentFuncIndex * 0x20;
        endChunk = **(int **)(stream + 0x20);
        ((int (*)())_ClearJumpTable)(funcInfos[0] + funcRecordByteOffset);
        funcScanWord0 = *(uint *)(endChunk + 0xc);
        while (*(uint *)(funcRecordByteOffset + funcInfos[0]) != (funcScanWord0 & 0x3ffff)) {
          endChunk = *(int *)(endChunk + 8);
          funcScanWord0 = *(uint *)(endChunk + 0xc);
        }
        if (*(uint *)(funcRecordByteOffset + funcInfos[0] + 4) != (funcScanWord0 & 0x3ffff)) {
          do {
            ((int (*)())_AddOpToJumpTable)(endChunk + 0xc,funcInfos[0] + funcRecordByteOffset);
            endChunk = *(int *)(endChunk + 8);
          } while (*(uint *)(funcRecordByteOffset + funcInfos[0] + 4) != (*(uint *)(endChunk + 0xc) & 0x3ffff));
        }
        lastResult = ((int (*)())_AddOpToJumpTable)(endChunk + 0xc,funcInfos[0] + funcRecordByteOffset);
        if (noOps) {
          opChunk = **(int **)(stream + 0x20);
        }
        else {
          opChunk = *(int *)(callPredecessor + 8);
        }
        noOps = opChunk == 0;
      } while (!noOps);
      opList = *(int **)(stream + 0x20);
    }
    funcSearchIndex = 0;
    inDeadFunction = false;
    nextChunk = *opList;
    while (opChunk = nextChunk, opChunk != 0) {
      nextChunk = *(int *)(opChunk + 8);
      if ((inDeadFunction) || (funcSearchIndex = 0, funcCount == 0)) {
        opWord0 = *(uint *)(opChunk + 0xc);
      }
      else {
        opWord0 = *(uint *)(opChunk + 0xc);
        do {
          recordKey = *(uint *)(funcSearchIndex * 0x20 + funcInfos[0]);
          if ((recordKey != 0) && (recordKey == (opWord0 & 0x3ffff))) {
            inDeadFunction = true;
            break;
          }
          funcSearchIndex = funcSearchIndex + 1;
        } while (funcSearchIndex < funcCount);
      }
      if (inDeadFunction) {
        if (*(uint *)(funcSearchIndex * 0x20 + funcInfos[0] + 4) == (opWord0 & 0x3ffff)) {
          inDeadFunction = false;
        }
        _PPStreamRemoveLabelsAtOperationIndex(stream,opWord0 & 0x3ffff);
        lastResult = _PPStreamChunkListRemoveChunk(*(undefined4 *)(stream + 0x20),opChunk);
      }
      else if ((opWord0 >> 0x12 & 0xff) == 0x6e) {
        lastResult = ((int (*)())_PPStreamRemoveOperation)(stream,opChunk);
      }
    }
  }
  if (funcInfos[0] != 0) {
    funcInfoIndex = 0;
    if (funcCount != 0) {
      do {
        funcRecordOffset = funcInfoIndex * 0x20;
        funcInfoIndex = funcInfoIndex + 1;
        ((int (*)())_ClearJumpTable)(funcInfos[0] + funcRecordOffset);
      } while (funcInfoIndex < funcCount);
    }
    _free(funcInfos[0]);
    lastResult = r3AfterFreeFuncInfos;
  }
  return lastResult;
}

/* _IsParamSampler @ 0x97c06614 (84 bytes) */
int _IsParamSampler(arrayKind, paramIndex, stream)
  int arrayKind;
  undefined4 paramIndex;
  int stream;
{
  int paramChunk;
  uint isSampler;
  
  isSampler = 0;
  if ((arrayKind == 2) &&
     (paramChunk = _PPStreamChunkListChunkAtIndex(*(undefined4 *)(stream + 0x10),paramIndex),
     (*(uint *)(paramChunk + 0xc) >> 0x10 & 0x1f) == 1)) {
    isSampler = *(uint *)(paramChunk + 0x10) >> 0x1f;
  }
  return isSampler;
}

/* _GetStreamArray_97c06668 @ 0x97c06668 (152 bytes) */
int _GetStreamArray_97c06668(arrayKind, registerIndex, stream)
  int arrayKind;
  uint registerIndex;
  int stream;
{
  int arrayChunk;
  int arrayNumber;
  
  arrayNumber = 0;
  if (arrayKind == 1) {
    for (arrayChunk = **(int **)(stream + 8); arrayChunk != 0; arrayChunk = *(int *)(arrayChunk + 8)) {
      if ((*(ushort *)(arrayChunk + 0xe) <= registerIndex) && (registerIndex <= *(ushort *)(arrayChunk + 0x12))) {
        return arrayNumber;
      }
      arrayNumber = arrayNumber + 1;
    }
  }
  else if (arrayKind == 2) {
    for (arrayChunk = **(int **)(stream + 0x14); arrayChunk != 0; arrayChunk = *(int *)(arrayChunk + 8)) {
      if ((*(ushort *)(arrayChunk + 0xe) <= registerIndex) && (registerIndex <= *(ushort *)(arrayChunk + 0x12))) {
        return arrayNumber;
      }
      arrayNumber = arrayNumber + 1;
    }
  }
  return -1;
}

/* _FindMatchingAvailableCopy @ 0x97c06700 (164 bytes) */
int _FindMatchingAvailableCopy(copy, copyTable)
  int copy;
  uint *copyTable;
{
  int candidate;
  int recordOffset;
  uint loopIndex;
  
  loopIndex = 0;
  if (*copyTable != 0) {
    recordOffset = 0;
    do {
      candidate = recordOffset + copyTable[1];
      if ((((*(int *)(recordOffset + copyTable[1]) != 0) && (*(int *)(candidate + 4) == *(int *)(copy + 4)))
          && (*(int *)(candidate + 8) == *(int *)(copy + 8))) &&
         (((*(int *)(candidate + 0xc) == *(int *)(copy + 0xc) &&
           (*(int *)(candidate + 0x10) == *(int *)(copy + 0x10))) &&
          ((*(int *)(candidate + 0x38) == *(int *)(copy + 0x38) &&
           (*(int *)(candidate + 0x3c) == *(int *)(copy + 0x3c))))))) {
        return candidate;
      }
      loopIndex = loopIndex + 1;
      recordOffset = recordOffset + 0x48;
    } while (loopIndex < *copyTable);
  }
  return 0;
}

/* _UpdateACUsingAvailableCopyTable @ 0x97c067a4 (444 bytes) */
int _UpdateACUsingAvailableCopyTable(operand, copyTable, stream)
  int operand;
  uint *copyTable;
  undefined4 stream;
{
  int componentIndex;
  int negateValue;
  int loopIndex2;
  bool allComponentsCopied;
  uint usedCount;
  undefined4 streamArray_97c06668;
  int entryOffset;
  int componentsLeft;
  int *copyEntry;
  uint loopIndex;
  int componentOperand;
  int componentSlot;
  uint componentLimit;
  
  loopIndex = 0;
  if (*copyTable != 0) {
    copyEntry = (int *)copyTable[1];
    entryOffset = 0;
    do {
      if (((*copyEntry != 0) && (copyEntry[1] == *(int *)(operand + 0xc))) &&
         (copyEntry[2] == *(int *)(operand + 0x10))) {
        componentLimit = *(uint *)(operand + 0x14);
        allComponentsCopied = true;
        loopIndex2 = 0;
        usedCount = 0;
        componentOperand = operand;
        do {
          if (((usedCount <= componentLimit) && (*(int *)(componentOperand + 0x28) != 0)) &&
             (usedCount = usedCount + 1, copyEntry[*(int *)(componentOperand + 0x18) + 10] != 1)) {
            allComponentsCopied = false;
          }
          loopIndex2 = loopIndex2 + 1;
          componentOperand = componentOperand + 4;
          if (3 < loopIndex2) {
            if (allComponentsCopied) {
              *(int *)(operand + 0xc) = copyEntry[3];
              *(undefined4 *)(operand + 0x10) = *(undefined4 *)(entryOffset + copyTable[1] + 0x10);
              if (*(int *)(operand + 0x38) == 0) {
                negateValue = *(int *)(entryOffset + copyTable[1] + 0x38);
              }
              else {
                negateValue = 1 - *(int *)(entryOffset + copyTable[1] + 0x38);
              }
              *(int *)(operand + 0x38) = negateValue;
              componentsLeft = 4;
              componentIndex = 0;
              loopIndex = 0;
              do {
                if ((componentLimit < loopIndex) || (componentSlot = componentIndex * 4 + operand, *(int *)(componentSlot + 0x28) == 0))
                {
                  *(int *)(componentIndex * 4 + operand + 0x18) = componentIndex;
                }
                else {
                  loopIndex = loopIndex + 1;
                  *(undefined4 *)(componentSlot + 0x18) =
                       *(undefined4 *)(*(int *)(componentSlot + 0x18) * 4 + entryOffset + copyTable[1] + 0x18);
                }
                componentIndex = componentIndex + 1;
                componentsLeft = componentsLeft + -1;
              } while (componentsLeft != 0);
              streamArray_97c06668 = ((int (*)())_GetStreamArray_97c06668)(*(undefined4 *)(operand + 0xc),*(undefined4 *)(operand + 0x10),
                                 stream);
              *(undefined4 *)(operand + 0x44) = streamArray_97c06668;
              return 1;
            }
            break;
          }
        } while (allComponentsCopied);
      }
      loopIndex = loopIndex + 1;
      entryOffset = entryOffset + 0x48;
      copyEntry = copyEntry + 0x12;
    } while (loopIndex < *copyTable);
  }
  return 0;
}

/* _AddToAvailableCopyTable @ 0x97c06960 (1196 bytes) */
int _AddToAvailableCopyTable(movInst, copyTable, stream)
  uint *movInst;
  uint *copyTable;
  undefined4 stream;
{
  int slotsLeft;
  int flagSlot;
  int newEntryAddr;
  uint entryCount;
  uint validSoFar;
  uint grownTable;
  int entryOffset;
  uint oldEntryIndex;
  uint destComponentSelect;
  int updateACUsingAvailableCopyTableResult;
  int findMatchingAvailableCopyResult;
  int loopIndex;
  uint instWord1;
  undefined4 swizzleValue;
  undefined4 *componentCursor;
  int *clearCursor;
  int newValidCount;
  uint destWord0;
  int unusedSlotsLeft;
  uint srcWord0;
  uint destWord1;
  uint destComponentWritten;
  int elementCount;
  int loopIndex2;
  int componentsLeft;
  int oldEntryAddr;
  undefined4 entryInUse;
  uint destFile;
  int destRegister;
  uint srcFile;
  int srcRegister;
  uint componentCountMinusOne;
  uint swizzle [4];
  uint componentValid [4];
  uint entryTail [8];
  
  elementCount = 1;
  if (((((*movInst >> 0x12 & 0xff) == 0) && (destWord1 = movInst[3], -1 < (int)destWord1)) &&
      (srcWord0 = movInst[4], -1 < (int)srcWord0)) &&
     ((destWord0 = movInst[2], (destWord0 >> 0x11 & 7) != (srcWord0 >> 0x17 & 7) ||
      (*(short *)((int)movInst + 0xe) != *(short *)((int)movInst + 0x16))))) {
    instWord1 = movInst[1];
    if ((instWord1 & 0x10000000) != 0) {
      elementCount = (instWord1 >> 0x1a & 3) + 1;
    }
    loopIndex2 = 0;
    if (elementCount != 0) {
      do {
        destRegister = (destWord1 & 0xffff) + loopIndex2;
        componentCountMinusOne = instWord1 >> 0x1a & 3;
        srcRegister = (uint)*(ushort *)((int)movInst + 0x16) + loopIndex2;
        srcFile = srcWord0 >> 0x17 & 7;
        destFile = destWord0 >> 0x11 & 7;
        entryTail[0] = srcWord0 >> 0x1b & 1;
        componentsLeft = 4;
        entryInUse = 1;
        loopIndex = 0;
        validSoFar = 0;
        componentCursor = &entryInUse;
        do {
          destComponentWritten = 0;
          destComponentSelect = 0;
          if (validSoFar <= componentCountMinusOne) {
            if (loopIndex == 1) {
              destComponentWritten = destWord0 >> 0xe & 1;
              destComponentSelect = destWord0 >> 6 & 3;
            }
            else if (loopIndex < 2) {
              if (loopIndex == 0) {
                destComponentWritten = destWord0 >> 0xd & 1;
                destComponentSelect = destWord0 >> 8 & 3;
              }
            }
            else if (loopIndex == 2) {
              destComponentWritten = destWord0 >> 0xf & 1;
              destComponentSelect = destWord0 >> 4 & 3;
            }
            else if (loopIndex == 3) {
              destComponentWritten = destWord0 >> 0x10 & 1;
              destComponentSelect = destWord0 >> 2 & 3;
            }
          }
          validSoFar = validSoFar + destComponentWritten;
          componentCursor[10] = destComponentWritten;
          if (destComponentSelect == 1) {
            componentCursor[6] = srcWord0 >> 0x13 & 3;
          }
          else if (destComponentSelect == 0) {
            componentCursor[6] = srcWord0 >> 0x15 & 3;
          }
          else if (destComponentSelect == 2) {
            componentCursor[6] = srcWord0 >> 0x11 & 3;
          }
          else if (destComponentSelect == 3) {
            componentCursor[6] = srcWord0 >> 0xf & 3;
          }
          loopIndex = loopIndex + 1;
          componentCursor = componentCursor + 1;
          componentsLeft = componentsLeft + -1;
        } while (componentsLeft != 0);
        if (loopIndex < 4) {
          clearCursor = &srcRegister;
          unusedSlotsLeft = 0;
          do {
            clearCursor[10] = 0;
            clearCursor[6] = 0;
            clearCursor = clearCursor + 1;
            unusedSlotsLeft = unusedSlotsLeft + -1;
          } while (unusedSlotsLeft != 0);
        }
        entryTail[2] = ((int (*)())_GetStreamArray_97c06668)(destFile,destRegister,stream);
        entryTail[3] = ((int (*)())_GetStreamArray_97c06668)(srcFile,srcRegister,stream);
        if (((movInst[1] & 0x10000000) != 0) && (loopIndex2 == 0)) {
          entryTail[1] = 1;
          findMatchingAvailableCopyResult = ((int (*)())_FindMatchingAvailableCopy)(&entryInUse,copyTable);
          if (findMatchingAvailableCopyResult == 0) {
            entryCount = *copyTable;
            if ((entryCount & 7) == 0) {
              oldEntryIndex = 0;
              grownTable = _malloc(entryCount * 0x48 + 0x240);
              _memset(grownTable,0,*copyTable * 0x48 + 0x240);
              entryCount = 0;
              if (*copyTable != 0) {
                entryOffset = 0;
                do {
                  newEntryAddr = entryOffset + grownTable;
                  oldEntryAddr = entryOffset + copyTable[1];
                  entryOffset = entryOffset + 0x48;
                  _memcpy(newEntryAddr,oldEntryAddr,0x48);
                  entryCount = *copyTable;
                  oldEntryIndex = oldEntryIndex + 1;
                } while (oldEntryIndex < entryCount);
              }
              if (copyTable[1] != 0) {
                _free(copyTable[1]);
                entryCount = *copyTable;
              }
              copyTable[1] = grownTable;
            }
            _memcpy(entryCount * 0x48 + copyTable[1],&entryInUse,0x48);
            *copyTable = *copyTable + 1;
          }
          else {
            slotsLeft = 4;
            componentCursor = &entryInUse;
            flagSlot = findMatchingAvailableCopyResult;
            do {
              if ((componentCursor[10] == 1) && (*(int *)(flagSlot + 0x28) == 0)) {
                newValidCount = *(int *)(findMatchingAvailableCopyResult + 0x14);
                swizzleValue = componentCursor[6];
                *(undefined4 *)(flagSlot + 0x28) = 1;
                *(int *)(findMatchingAvailableCopyResult + 0x14) = newValidCount + 1;
LAB_97c06bf0:
                *(undefined4 *)(flagSlot + 0x18) = swizzleValue;
              }
              else if (componentCursor[10] == 1) {
                swizzleValue = componentCursor[6];
                goto LAB_97c06bf0;
              }
              flagSlot = flagSlot + 4;
              componentCursor = componentCursor + 1;
              slotsLeft = slotsLeft + -1;
            } while (slotsLeft != 0);
          }
        }
        entryTail[1] = 0;
        do {
          updateACUsingAvailableCopyTableResult = ((int (*)())_UpdateACUsingAvailableCopyTable)(&entryInUse,copyTable,stream);
        } while (updateACUsingAvailableCopyTableResult != 0);
        findMatchingAvailableCopyResult = ((int (*)())_FindMatchingAvailableCopy)(&entryInUse,copyTable);
        if (findMatchingAvailableCopyResult == 0) {
          entryCount = *copyTable;
          if ((entryCount & 7) == 0) {
            oldEntryIndex = 0;
            grownTable = _malloc(entryCount * 0x48 + 0x240);
            _memset(grownTable,0,*copyTable * 0x48 + 0x240);
            entryCount = 0;
            if (*copyTable != 0) {
              entryOffset = 0;
              do {
                oldEntryIndex = oldEntryIndex + 1;
                _memcpy(entryOffset + grownTable,entryOffset + copyTable[1],0x48);
                entryCount = *copyTable;
                entryOffset = entryOffset + 0x48;
              } while (oldEntryIndex < entryCount);
            }
            if (copyTable[1] != 0) {
              _free(copyTable[1]);
              entryCount = *copyTable;
            }
            copyTable[1] = grownTable;
          }
          _memcpy(entryCount * 0x48 + copyTable[1],&entryInUse,0x48);
          *copyTable = *copyTable + 1;
        }
        else {
          slotsLeft = 4;
          componentCursor = &entryInUse;
          flagSlot = findMatchingAvailableCopyResult;
          do {
            if ((componentCursor[10] == 1) && (*(int *)(flagSlot + 0x28) == 0)) {
              newValidCount = *(int *)(findMatchingAvailableCopyResult + 0x14);
              swizzleValue = componentCursor[6];
              *(undefined4 *)(flagSlot + 0x28) = 1;
              *(int *)(findMatchingAvailableCopyResult + 0x14) = newValidCount + 1;
LAB_97c06d30:
              *(undefined4 *)(flagSlot + 0x18) = swizzleValue;
            }
            else if (componentCursor[10] == 1) {
              swizzleValue = componentCursor[6];
              goto LAB_97c06d30;
            }
            flagSlot = flagSlot + 4;
            componentCursor = componentCursor + 1;
            slotsLeft = slotsLeft + -1;
          } while (slotsLeft != 0);
        }
        loopIndex2 = loopIndex2 + 1;
        if (elementCount <= loopIndex2) {
          return;
        }
        destWord1 = movInst[3];
        srcWord0 = movInst[4];
        destWord0 = movInst[2];
        instWord1 = movInst[1];
      } while( true );
    }
  }
  return;
}

/* _FindInAvailableCopyTableSource @ 0x97c06e0c (304 bytes) */
int _FindInAvailableCopyTableSource(operandWord0, operandWord1, copyTable)
  uint operandWord0;
  uint operandWord1;
  uint *copyTable;
{
  bool matched;
  uint componentCount;
  int *copyEntry;
  uint loopIndex;
  
  matched = false;
  loopIndex = 0;
  if (*copyTable != 0) {
    copyEntry = (int *)copyTable[1];
    do {
      if (((((*copyEntry != 0) && (copyEntry[1] == (operandWord0 >> 0x17 & 7))) &&
           (copyEntry[2] == (operandWord1 & 0xffff))) &&
          ((copyEntry[0xf] == (operandWord0 >> 0xe & 1) &&
           (componentCount = operandWord0 >> 0xc & 3, componentCount <= (uint)copyEntry[5])))) && (-1 < (int)operandWord0)) {
        matched = true;
        if (componentCount == 1) {
LAB_97c06ed8:
          if (*(int *)((int)copyEntry + (operandWord0 >> 0x11 & 0xc) + 0x28) == 1) {
LAB_97c06eec:
            if (*(int *)((int)copyEntry + (operandWord0 >> 0x13 & 0xc) + 0x28) == 1) goto LAB_97c06f04;
          }
        }
        else {
          if (componentCount < 2) {
            if (componentCount != 0) goto LAB_97c06f04;
            goto LAB_97c06eec;
          }
          if (componentCount == 2) {
LAB_97c06ec4:
            if (*(int *)((int)copyEntry + (operandWord0 >> 0xf & 0xc) + 0x28) == 1) goto LAB_97c06ed8;
          }
          else {
            if (componentCount != 3) goto LAB_97c06f04;
            if (*(int *)((int)copyEntry + (operandWord0 >> 0xd & 0xc) + 0x28) == 1) goto LAB_97c06ec4;
          }
        }
        matched = false;
      }
LAB_97c06f04:
      loopIndex = loopIndex + 1;
      copyEntry = copyEntry + 0x12;
    } while ((loopIndex < *copyTable) && (!matched));
  }
  if (matched) {
    return copyTable[1] + (loopIndex - 1) * 0x48;
  }
  return 0;
}

/* _CheckRemoveAvailableCopyTable @ 0x97c06f3c (756 bytes) */
int _CheckRemoveAvailableCopyTable(destWord0, destWord1, registerOffset, relativeFlag, copyTable, stream)
  uint destWord0;
  uint destWord1;
  int registerOffset;
  int relativeFlag;
  uint *copyTable;
  undefined4 stream;
{
  bool overlaps;
  int flagSlot;
  uint writeMaskBit;
  uint writtenRegister;
  int loopIndex3;
  int loopIndex;
  bool overlapsSource;
  int componentSwizzle;
  int *flagCursor;
  int destArrayIndex;
  uint loopIndex2;
  uint entryCount;
  int entryAddr;
  int componentFlag;
  int entryOffset;
  uint tableBase;
  uint destWord0Copy;
  uint destWord1Copy;
  
  destArrayIndex = -1;
  destWord0Copy = destWord0;
  destWord1Copy = destWord1;
  if ((int)destWord1 < 0) {
    destArrayIndex = ((int (*)())_GetStreamArray_97c06668)(destWord0 >> 0x11 & 7,(destWord1 & 0xffff) + registerOffset,stream);
  }
  entryCount = *copyTable;
  loopIndex2 = 0;
  if (entryCount != 0) {
    entryOffset = 0;
    do {
      tableBase = copyTable[1];
      if (*(int *)(entryOffset + tableBase) != 0) {
        overlaps = false;
        if ((destArrayIndex < 0) || (destArrayIndex != *(int *)(entryOffset + tableBase + 0x40))) {
          entryAddr = entryOffset + tableBase;
          if ((*(int *)(entryAddr + 0x3c) != 0) &&
             (*(uint *)(entryAddr + 4) == (destWord0Copy >> 0x11 & 7))) {
            writtenRegister = (destWord1Copy & 0xffff) + registerOffset;
            if ((*(uint *)(entryAddr + 8) <= writtenRegister) &&
               (writtenRegister <= *(uint *)(entryAddr + 8) + *(int *)(entryAddr + 0x14))) goto LAB_97c070dc;
          }
          flagSlot = entryOffset + tableBase;
          if ((*(uint *)(flagSlot + 4) == (destWord0Copy >> 0x11 & 7)) &&
             ((*(int *)(flagSlot + 8) == (destWord1Copy & 0xffff) + registerOffset &&
              (*(int *)(flagSlot + 0x3c) == relativeFlag)))) {
            flagCursor = (int *)(flagSlot + 0x28);
            loopIndex = 0;
            do {
              componentFlag = *flagCursor;
              flagCursor = flagCursor + 1;
              if (componentFlag == 1) {
                if (loopIndex == 1) {
                  writeMaskBit = destWord0Copy >> 0xe & 1;
                }
                else if (loopIndex < 2) {
                  writeMaskBit = destWord0Copy >> 0xd & 1;
                  if (loopIndex != 0) goto LAB_97c070c8;
                }
                else if (loopIndex == 2) {
                  writeMaskBit = destWord0Copy >> 0xf & 1;
                }
                else {
                  if (loopIndex != 3) goto LAB_97c070c8;
                  writeMaskBit = destWord0Copy >> 0x10 & 1;
                }
                if (writeMaskBit == 1) {
                  overlaps = true;
                  break;
                }
              }
LAB_97c070c8:
              loopIndex = loopIndex + 1;
            } while (loopIndex <= (int)(destWord0Copy >> 10 & 3));
            if (overlaps) goto LAB_97c070dc;
          }
        }
        else {
LAB_97c070dc:
          *(undefined4 *)(entryOffset + tableBase) = 0;
          tableBase = copyTable[1];
        }
        overlapsSource = false;
        if ((destArrayIndex < 0) || (destArrayIndex != *(int *)(entryOffset + tableBase + 0x44))) {
          entryAddr = entryOffset + tableBase;
          if ((*(int *)(entryAddr + 0x3c) != 0) &&
             (*(uint *)(entryAddr + 0xc) == (destWord0Copy >> 0x11 & 7))) {
            writtenRegister = (destWord1Copy & 0xffff) + registerOffset;
            if ((*(uint *)(entryAddr + 0x10) <= writtenRegister) &&
               (writtenRegister <= *(uint *)(entryAddr + 0x10) + *(int *)(entryAddr + 0x14))) goto LAB_97c07204;
          }
          flagSlot = entryOffset + tableBase;
          if ((*(uint *)(flagSlot + 0xc) == (destWord0Copy >> 0x11 & 7)) &&
             ((*(int *)(flagSlot + 0x10) == (destWord1Copy & 0xffff) + registerOffset &&
              (*(int *)(flagSlot + 0x3c) == relativeFlag)))) {
            loopIndex3 = 0;
            do {
              if (*(int *)(flagSlot + 0x28) == 1) {
                componentSwizzle = *(int *)(flagSlot + 0x18);
                if (componentSwizzle == 1) {
                  writeMaskBit = destWord0Copy >> 0xe & 1;
                }
                else {
                  writeMaskBit = destWord0Copy >> 0xd & 1;
                  if (componentSwizzle != 0) {
                    if (componentSwizzle == 2) {
                      writeMaskBit = destWord0Copy >> 0xf & 1;
                    }
                    else {
                      if (componentSwizzle != 3) goto LAB_97c071ec;
                      writeMaskBit = destWord0Copy >> 0x10 & 1;
                    }
                  }
                }
                if (writeMaskBit == 1) {
                  overlapsSource = true;
                  break;
                }
              }
LAB_97c071ec:
              loopIndex3 = loopIndex3 + 1;
              flagSlot = flagSlot + 4;
            } while (loopIndex3 <= (int)(destWord0Copy >> 10 & 3));
          }
          if (overlapsSource) goto LAB_97c07204;
        }
        else {
LAB_97c07204:
          *(undefined4 *)(entryOffset + tableBase) = 0;
        }
        entryCount = *copyTable;
      }
      loopIndex2 = loopIndex2 + 1;
      entryOffset = entryOffset + 0x48;
    } while (loopIndex2 < entryCount);
  }
  return;
}

/* _ReplaceUsingAvailableCopyTable @ 0x97c07230 (580 bytes) */
int _ReplaceUsingAvailableCopyTable(inst, copyTable)
  uint *inst;
  undefined4 copyTable;
{
  uint swizzleSelect0;
  uint componentCount;
  uint swizzleSelect3;
  uint swizzleSelect2;
  uint swizzleSelect1;
  uint operandWord0;
  uint newFileBits;
  uint *copyEntry;
  uint oldOperandWord0;
  int loopIndex;
  uint *srcOperand;
  
  loopIndex = 0;
  copyEntry = inst;
  srcOperand = inst;
  if (*inst >> 0x1d != 0) {
    do {
      copyEntry = (uint *)((int (*)())_FindInAvailableCopyTableSource)(srcOperand[4],srcOperand[5],copyTable);
      if (copyEntry != (uint *)0x0) {
        oldOperandWord0 = srcOperand[4];
        newFileBits = (copyEntry[3] & 7) << 0x17;
        srcOperand[4] = newFileBits | oldOperandWord0 & 0xfc7fffff;
        *(undefined2 *)((int)srcOperand + 0x16) = *(undefined2 *)((int)copyEntry + 0x12);
        if ((oldOperandWord0 & 0x8000000) == 0) {
          srcOperand[4] = (copyEntry[0xe] & 1) << 0x1b | newFileBits | oldOperandWord0 & 0xf47fffff;
        }
        else {
          srcOperand[4] = (1 - copyEntry[0xe]) * 0x8000000 & 0x8000000 | newFileBits | oldOperandWord0 & 0xf47fffff;
        }
        operandWord0 = srcOperand[4];
        componentCount = operandWord0 >> 0xc & 3;
        if (componentCount == 1) goto LAB_97c07398;
        if (componentCount < 2) {
          if (componentCount != 0) goto LAB_97c07448;
        }
        else {
          if (componentCount == 2) goto LAB_97c07340;
          if (componentCount != 3) goto LAB_97c07448;
          swizzleSelect0 = operandWord0 >> 0xf & 3;
          if (swizzleSelect0 == 1) {
            swizzleSelect0 = copyEntry[7];
LAB_97c07338:
            srcOperand[4] = (swizzleSelect0 & 3) << 0xf | operandWord0 & 0xfffe7fff;
          }
          else {
            if (1 < swizzleSelect0) {
              if (swizzleSelect0 == 2) {
                swizzleSelect0 = copyEntry[8];
              }
              else {
                if (swizzleSelect0 != 3) goto LAB_97c07340;
                swizzleSelect0 = copyEntry[9];
              }
              goto LAB_97c07338;
            }
            if (swizzleSelect0 == 0) {
              swizzleSelect0 = copyEntry[6];
              goto LAB_97c07338;
            }
          }
LAB_97c07340:
          swizzleSelect1 = srcOperand[4] >> 0x11 & 3;
          if (swizzleSelect1 == 1) {
            swizzleSelect1 = copyEntry[7];
LAB_97c07390:
            srcOperand[4] = (swizzleSelect1 & 3) << 0x11 | srcOperand[4] & 0xfff9ffff;
          }
          else {
            if (1 < swizzleSelect1) {
              if (swizzleSelect1 == 2) {
                swizzleSelect1 = copyEntry[8];
              }
              else {
                if (swizzleSelect1 != 3) goto LAB_97c07398;
                swizzleSelect1 = copyEntry[9];
              }
              goto LAB_97c07390;
            }
            if (swizzleSelect1 == 0) {
              swizzleSelect1 = copyEntry[6];
              goto LAB_97c07390;
            }
          }
LAB_97c07398:
          swizzleSelect2 = srcOperand[4] >> 0x13 & 3;
          if (swizzleSelect2 == 1) {
            swizzleSelect2 = copyEntry[7];
          }
          else if (swizzleSelect2 < 2) {
            if (swizzleSelect2 != 0) goto LAB_97c073f0;
            swizzleSelect2 = copyEntry[6];
          }
          else if (swizzleSelect2 == 2) {
            swizzleSelect2 = copyEntry[8];
          }
          else {
            if (swizzleSelect2 != 3) goto LAB_97c073f0;
            swizzleSelect2 = copyEntry[9];
          }
          srcOperand[4] = (swizzleSelect2 & 3) << 0x13 | srcOperand[4] & 0xffe7ffff;
        }
LAB_97c073f0:
        swizzleSelect3 = srcOperand[4] >> 0x15 & 3;
        if (swizzleSelect3 == 1) {
          swizzleSelect3 = copyEntry[7];
        }
        else if (swizzleSelect3 < 2) {
          if (swizzleSelect3 != 0) goto LAB_97c07448;
          swizzleSelect3 = copyEntry[6];
        }
        else if (swizzleSelect3 == 2) {
          swizzleSelect3 = copyEntry[8];
        }
        else {
          if (swizzleSelect3 != 3) goto LAB_97c07448;
          swizzleSelect3 = copyEntry[9];
        }
        srcOperand[4] = (swizzleSelect3 & 3) << 0x15 | srcOperand[4] & 0xff9fffff;
      }
LAB_97c07448:
      loopIndex = loopIndex + 1;
      srcOperand = srcOperand + 2;
    } while (loopIndex < (int)(*inst >> 0x1d));
  }
  return copyEntry;
}

/* _RemoveFromAvailableCopyTable @ 0x97c07474 (152 bytes) */
int _RemoveFromAvailableCopyTable(op, copyTable, stream)
  int op;
  undefined4 copyTable;
  undefined4 stream;
{
  uint destWord0;
  int elementCount;
  int element;
  int nextElement;
  
  destWord0 = *(uint *)(op + 8);
  elementCount = 1;
  if ((destWord0 & 0x1000) != 0) {
    elementCount = (destWord0 >> 10 & 3) + 1;
    ((int (*)())_CheckRemoveAvailableCopyTable)(destWord0,*(undefined4 *)(op + 0xc),0,1,copyTable,stream);
  }
  element = 0;
  if (elementCount != 0) {
    do {
      nextElement = element + 1;
      ((int (*)())_CheckRemoveAvailableCopyTable)(*(undefined4 *)(op + 8),*(undefined4 *)(op + 0xc),element,0,copyTable,stream
                );
      element = nextElement;
    } while (nextElement < elementCount);
  }
  return;
}

/* _CopyPropagateOperation @ 0x97c0750c (80 bytes) */
int _CopyPropagateOperation(op, copyTable, stream)
  undefined4 op;
  undefined4 copyTable;
  undefined4 stream;
{
  ((int (*)())_ReplaceUsingAvailableCopyTable)(op,copyTable);
  ((int (*)())_RemoveFromAvailableCopyTable)(op,copyTable,stream);
  return ((int (*)())_AddToAvailableCopyTable)(op,copyTable,stream);
}

/* _EndLocalAvailableCopyList @ 0x97c0755c (132 bytes) */
int _EndLocalAvailableCopyList(op)
  uint *op;
{
  uint opcode;
  
  opcode = *op >> 0x12 & 0xff;
  if (((((opcode != 0x4c) && (opcode != 0x55)) && (opcode != 0x58)) &&
      ((((opcode != 0x6a && (opcode != 0x6b)) &&
        ((opcode != 0x59 && ((opcode != 0x69 && (opcode != 0x54)))))) && (opcode != 0x4d)))) &&
     ((((opcode != 0x4b && (opcode != 0x57)) && (opcode != 0x5b)) &&
      ((opcode != 0x56 && (opcode != 0x5a)))))) {
    return 0;
  }
  return 1;
}

/* _LocalCopyPropagator @ 0x97c075e0 (236 bytes) */
int _LocalCopyPropagator(stream)
  int stream;
{
  int endLocalAvailableCopyListResult;
  uint *allocation;
  int entryOffset;
  int isParamSampler;
  int opChunk;
  uint entryIndex;
  
  opChunk = **(int **)(stream + 0x20);
  allocation = (uint *)_malloc(8);
  allocation[1] = 0;
  *allocation = 0;
  for (; opChunk != 0; opChunk = *(int *)(opChunk + 8)) {
    endLocalAvailableCopyListResult = ((int (*)())_EndLocalAvailableCopyList)(opChunk + 0xc);
    if ((endLocalAvailableCopyListResult != 0) && (entryIndex = 0, *allocation != 0)) {
      entryOffset = 0;
      do {
        isParamSampler = ((int (*)())_IsParamSampler)(*(undefined4 *)(entryOffset + allocation[1] + 0xc),
                                *(undefined4 *)(entryOffset + allocation[1] + 0x10),stream);
        if (isParamSampler == 0) {
          *(undefined4 *)(entryOffset + allocation[1]) = 0;
        }
        entryIndex = entryIndex + 1;
        entryOffset = entryOffset + 0x48;
      } while (entryIndex < *allocation);
    }
    ((int (*)())_CopyPropagateOperation)(opChunk + 0xc,allocation,stream);
  }
  if (allocation[1] != 0) {
    _free(allocation[1]);
  }
  return _free(allocation);
}

/* _EmbedSamplerParamIndices @ 0x97c076cc (144 bytes) */
int _EmbedSamplerParamIndices(stream)
  int stream;
{
  bool paramListEmpty;
  short paramIndex;
  uint opcode;
  int paramChunk;
  int opChunk;
  
  opChunk = **(int **)(stream + 0x20);
  if (opChunk == 0) {
    return;
  }
  do {
    opcode = *(uint *)(opChunk + 0xc) >> 0x12 & 0xff;
    if ((0x41 < opcode) && ((opcode < 0x48 || (opcode == 0x62)))) {
      paramChunk = **(int **)(stream + 0x10);
      paramListEmpty = paramChunk == 0;
      if (!paramListEmpty) {
        paramIndex = *(short *)(paramChunk + 0x12);
        while (*(short *)(opChunk + 0x2a) != paramIndex) {
          paramChunk = *(int *)(paramChunk + 8);
          if (paramChunk == 0) goto LAB_97c0774c;
          paramListEmpty = false;
          paramIndex = *(short *)(paramChunk + 0x12);
        }
        if ((!paramListEmpty) && ((*(uint *)(paramChunk + 0xc) >> 0x10 & 0x1f) == 1)) {
          *(short *)(opChunk + 0x32) = (short)*(uint *)(paramChunk + 0xc);
        }
      }
    }
LAB_97c0774c:
    opChunk = *(int *)(opChunk + 8);
    if (opChunk == 0) {
      return;
    }
  } while( true );
}

/* _LinearizeFixOutputReads @ 0x97c0775c (916 bytes) */
int _LinearizeFixOutputReads(stream)
  int stream;
{
  uint tempSizeMinusOne;
  int movChunk;
  int opChunk;
  uint loopIndex2;
  uint loopIndex;
  ushort outputIndex;
  bool readsOutput;
  int sourceOperand;
  int *opList;
  undefined4 maxIndex;
  uint opWord0;
  uint sourceCount;
  int sourceOperandRewrite;
  int outputChunk;
  uint tempDeclWord0;
  undefined4 tempDeclWord1OrScanChunk;
  int tempDeclWord2;
  int tempDeclWord3;
  undefined4 movHeader;
  uint movFlags;
  uint movDest0;
  uint movDest1;
  uint movSrc0A;
  uint movSrc0B;
  undefined4 movSrc1A;
  undefined4 movSrc1B;
  undefined4 movSrc2A;
  undefined4 movSrc2B;
  undefined4 movAuxA;
  undefined4 movAuxB;
  undefined4 movLine;
  undefined4 movWord13;
  
  outputChunk = **(int **)(stream + 0x1c);
  do {
    if (outputChunk == 0) {
      return;
    }
    readsOutput = false;
    outputIndex = *(ushort *)(outputChunk + 0x12);
    tempDeclWord1OrScanChunk = **(int **)(stream + 0x20);
    if (tempDeclWord1OrScanChunk != 0) {
      do {
        loopIndex = 0;
        sourceCount = *(uint *)(tempDeclWord1OrScanChunk + 0xc) >> 0x1d;
        if (sourceCount != 0) {
          sourceOperand = tempDeclWord1OrScanChunk + 0x10;
          do {
            if ((((*(uint *)(sourceOperand + 0xc) >> 0x17 & 7) == 3) && (*(ushort *)(sourceOperand + 0x12) == outputIndex)
                ) || (((*(uint *)(tempDeclWord1OrScanChunk + 0xc) >> 0x12 & 0xff) == 0x6d &&
                      (((*(uint *)(tempDeclWord1OrScanChunk + 0x14) >> 0x11 & 7) == 3 &&
                       (*(ushort *)(tempDeclWord1OrScanChunk + 0x1a) == outputIndex)))))) {
              readsOutput = true;
              break;
            }
            if (readsOutput) break;
            loopIndex = loopIndex + 1;
            sourceOperand = sourceOperand + 8;
          } while (loopIndex < sourceCount);
        }
        tempDeclWord1OrScanChunk = *(int *)(tempDeclWord1OrScanChunk + 8);
      } while (tempDeclWord1OrScanChunk != 0);
      if (readsOutput) {
        tempDeclWord0 = 0;
        tempDeclWord2 = tempDeclWord1OrScanChunk;
        tempDeclWord3 = tempDeclWord1OrScanChunk;
        maxIndex = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(stream + 4));
        tempDeclWord1OrScanChunk = CONCAT22((*(unsigned short *)((unsigned char *)&(tempDeclWord1OrScanChunk) + 0)),(short)maxIndex + 1);
        tempDeclWord0 = (*(uint *)(outputChunk + 0xc) >> 0x18 & 3) << 0x18 |
                   (*(uint *)(outputChunk + 0xc) >> 0x1a & 7) << 0x1a |
                   *(uint *)(outputChunk + 0xc) & 0xe0000000 | tempDeclWord0 & 0xffffff;
        _PPStreamAddTempUsage(stream,&tempDeclWord0);
        opList = *(int **)(stream + 0x20);
        opChunk = *opList;
        if (opChunk != 0) {
          do {
            if (((*(uint *)(opChunk + 0x14) >> 0x11 & 7) == 3) && (*(ushort *)(opChunk + 0x1a) == outputIndex)
               ) {
              *(uint *)(opChunk + 0x14) = *(uint *)(opChunk + 0x14) & 0xfff1ffff | 0x20000;
              *(undefined2 *)(opChunk + 0x1a) = (*(unsigned short *)((unsigned char *)&(tempDeclWord1OrScanChunk) + 2));
            }
            opWord0 = *(uint *)(opChunk + 0xc);
            loopIndex2 = 0;
            if (opWord0 >> 0x1d != 0) {
              sourceOperandRewrite = opChunk + 0x10;
              do {
                if (((*(uint *)(sourceOperandRewrite + 0xc) >> 0x17 & 7) == 3) &&
                   (*(ushort *)(sourceOperandRewrite + 0x12) == outputIndex)) {
                  *(uint *)(sourceOperandRewrite + 0xc) = *(uint *)(sourceOperandRewrite + 0xc) & 0xfc7fffff | 0x800000;
                  *(undefined2 *)(sourceOperandRewrite + 0x12) = (*(unsigned short *)((unsigned char *)&(tempDeclWord1OrScanChunk) + 2));
                  opWord0 = *(uint *)(opChunk + 0xc);
                }
                loopIndex2 = loopIndex2 + 1;
                sourceOperandRewrite = sourceOperandRewrite + 8;
              } while (loopIndex2 < opWord0 >> 0x1d);
            }
            opChunk = *(int *)(opChunk + 8);
          } while (opChunk != 0);
          opList = *(int **)(stream + 0x20);
        }
        for (opChunk = *opList; opChunk != 0; opChunk = *(int *)(opChunk + 8)) {
          if ((*(uint *)(opChunk + 0xc) >> 0x12 & 0xff) == 0x4d) {
            tempSizeMinusOne = tempDeclWord0 >> 0x18 & 3;
            movDest0 = tempSizeMinusOne << 10 | 0x6c;
            movSrc1A = 0;
            movSrc1B = 0;
            movSrc2A = 0;
            movSrc2B = 0;
            movAuxA = 0;
            movAuxB = 0;
            movLine = *(undefined4 *)(opChunk + 0x3c);
            movHeader = 0x20000000;
            movWord13 = 0;
            if (tempSizeMinusOne == 1) {
LAB_97c07a24:
              movDest0 = movDest0 | 0x4000;
LAB_97c07a2c:
              movDest0 = movDest0 | 0x2000;
            }
            else {
              if (1 < tempSizeMinusOne) {
                if (tempSizeMinusOne != 2) {
                  if (tempSizeMinusOne != 3) goto LAB_97c07a34;
                  movDest0 = 0x10c6c;
                }
                movDest0 = movDest0 | 0x8000;
                goto LAB_97c07a24;
              }
              if (tempSizeMinusOne == 0) goto LAB_97c07a2c;
            }
LAB_97c07a34:
            tempSizeMinusOne = tempDeclWord0 >> 0x18 & 3;
            movFlags = (tempDeclWord0 >> 0x1d & 3) << 0x12 |
                       tempSizeMinusOne << 0x1a | (tempDeclWord0 >> 0x1a & 7) << 0x17;
            movDest0 = movDest0 | 0x60000;
            movSrc0A = tempSizeMinusOne << 0xc | 0x8d8000;
            movSrc0B = tempDeclWord1OrScanChunk & 0xffff;
            movDest1 = (uint)outputIndex;
            movChunk = _PPStreamInsertOperationAfterChunk
                              (stream,&movHeader,0,0,*(undefined4 *)(opChunk + 4));
            _PPStreamChangeBranchTargets
                      (stream,*(uint *)(opChunk + 0xc) & 0x3ffff,*(uint *)(movChunk + 0xc) & 0x3ffff);
          }
        }
      }
    }
    outputChunk = *(int *)(outputChunk + 8);
  } while( true );
}

/* _glpPPShaderLinearizeStreamMgr @ 0x97c07af0 (320 bytes) */
int _glpPPShaderLinearizeStreamMgr(stream, passFlags)
  undefined4 stream;
  uint passFlags;
{
  undefined4 program;
  
  if ((passFlags & 1) != 0) {
    ((int (*)())_InlineFunctionsBranch)(stream);
  }
  if ((passFlags & 0x102) != 0) {
    _DetectConstantLoopsSimple(stream);
    _UnrollConstantLoopsSimple(stream,passFlags & 0x100);
  }
  if ((passFlags & 4) != 0) {
    _PPStreamPackIndices(stream);
    _FlattenIfs(stream);
  }
  if ((passFlags & 0x106) != 0) {
    ((int (*)())_LinearizeFixOutputReads)(stream);
  }
  if ((passFlags & 0x80) != 0) {
    _ConstantPropagateFold(stream);
  }
  if ((passFlags & 8) != 0) {
    ((int (*)())_LocalCopyPropagator)(stream);
  }
  if ((passFlags & 0x10) != 0) {
    ((int (*)())_EmbedSamplerParamIndices)(stream);
  }
  program = 0;
  if (passFlags != 0) {
    _PPStreamPackIndices(stream);
    program = _ProgramNew(stream);
    _Registerify(program);
    _Blockify(program);
  }
  if ((passFlags & 0x60) != 0) {
    _BuildGenKill(program);
    _BuildLiveOut(program);
  }
  if ((passFlags & 0x40) != 0) {
    _DeadCodeEliminationSimple(program);
  }
  if ((passFlags & 0x20) != 0) {
    _BuildInterferenceSets(program);
    _RegistersMerge(program);
  }
  if (passFlags != 0) {
    _RegistersCleanup(program);
    _ProgramFree(program);
  }
  return _PPStreamPackIndices(stream);
}

/* _glpPPShaderLinearize @ 0x97c07c30 (156 bytes) */
int _glpPPShaderLinearize(program, passFlags)
  undefined4 program;
  undefined4 passFlags;
{
  undefined4 ppStreamCreateResult;
  undefined4 linearizedProgram;
  int streamInfo [7];
  
  linearizedProgram = 0;
  streamInfo[0] = 0;
  ppStreamCreateResult = _PPStreamCreate();
  _PPStreamAttachStream(ppStreamCreateResult,program);
  ((int (*)())_glpPPShaderLinearizeStreamMgr)(ppStreamCreateResult,passFlags);
  _PPStreamGetStream(ppStreamCreateResult,0,streamInfo);
  if (streamInfo[0] != 0) {
    linearizedProgram = _malloc(streamInfo[0] * 8 + 0xfU & 0xfffffff0);
    _PPStreamGetStream(ppStreamCreateResult,linearizedProgram,streamInfo);
  }
  _PPStreamFree(ppStreamCreateResult);
  return linearizedProgram;
}

/* _glpFreePPShaderLinearize @ 0x97c07ccc (12 bytes) */
int _glpFreePPShaderLinearize(program)
  int program;
{
  if (program == 0) {
    return;
  }
  return _free(program);
}

/* _BitSetNew @ 0x97c07cd8 (104 bytes) */
int _BitSetNew(bitCount)
  uint bitCount;
{
  uint allocation2;
  uint *allocation;
  uint byteSize;
  
  byteSize = (bitCount >> 3 & 0x1ffffffc) + 4;
  allocation = (uint *)_malloc(0xc);
  *allocation = bitCount;
  allocation[1] = byteSize;
  allocation2 = _malloc(byteSize);
  allocation[2] = allocation2;
  ((int (*)())_BitSetSetRangeEqualsInternal)(allocation,0,bitCount,0);
  return allocation;
}

/* _BitSetClone @ 0x97c07d40 (64 bytes) */
int _BitSetClone(bitSet)
  undefined4 *bitSet;
{
  undefined4 bitSetNewResult;
  
  bitSetNewResult = ((int (*)())_BitSetNew)(*bitSet);
  _BitSetCopyEquals(bitSetNewResult,bitSet);
  return bitSetNewResult;
}

/* _BitSetFree @ 0x97c07d80 (52 bytes) */
int _BitSetFree(bitSet)
  int bitSet;
{
  undefined4 r3AfterFreeBitSet;
  
  _free(*(undefined4 *)(bitSet + 8));
  _free(bitSet);
  return r3AfterFreeBitSet;
}

/* _BitSetGetSizeInBits @ 0x97c07db4 (8 bytes) */
int _BitSetGetSizeInBits(bitSet)
  undefined4 *bitSet;
{
  return *bitSet;
}

/* _BitSetGetEquals @ 0x97c07dbc (88 bytes) */
int _BitSetGetEquals(bitSet, bitIndex)
  int bitSet;
  uint bitIndex;
{
  ((int (*)())_BitSetExpandEquals)(bitSet,bitIndex + 1);
  return (*(uint *)((bitIndex >> 3 & 0x1ffffffc) + *(int *)(bitSet + 8)) & 1 << (bitIndex & 0x1f)) !=
         0;
}

/* _BitSetSetEquals @ 0x97c07e14 (88 bytes) */
int _BitSetSetEquals(bitSet, bitIndex)
  int bitSet;
  uint bitIndex;
{
  uint wordByteOffset;
  
  ((int (*)())_BitSetExpandEquals)(bitSet,bitIndex + 1);
  wordByteOffset = bitIndex >> 3 & 0x1ffffffc;
  *(uint *)(wordByteOffset + *(int *)(bitSet + 8)) =
       *(uint *)(wordByteOffset + *(int *)(bitSet + 8)) | 1 << (bitIndex & 0x1f);
  return bitSet;
}

/* _BitSetClearEquals @ 0x97c07e6c (88 bytes) */
int _BitSetClearEquals(bitSet, bitIndex)
  int bitSet;
  uint bitIndex;
{
  uint wordByteOffset;
  
  ((int (*)())_BitSetExpandEquals)(bitSet,bitIndex + 1);
  wordByteOffset = bitIndex >> 3 & 0x1ffffffc;
  *(uint *)(wordByteOffset + *(int *)(bitSet + 8)) =
       *(uint *)(wordByteOffset + *(int *)(bitSet + 8)) &
       (-2 << (bitIndex & 0x1f) | 0xfffffffeU >> 0x20 - (bitIndex & 0x1f));
  return bitSet;
}

/* _BitSetSetRangeEquals @ 0x97c07ec4 (84 bytes) */
int _BitSetSetRangeEquals(bitSet, firstBit, endBit, value)
  undefined4 bitSet;
  undefined4 firstBit;
  undefined4 endBit;
  undefined4 value;
{
  ((int (*)())_BitSetExpandEquals)(bitSet,endBit);
  ((int (*)())_BitSetSetRangeEqualsInternal)(bitSet,firstBit,endBit,value);
  return bitSet;
}

/* _BitSetSetRangeEqualsInternal @ 0x97c07f18 (100 bytes) */
int _BitSetSetRangeEqualsInternal(bitSet, firstBit, endBit, value)
  int bitSet;
  uint firstBit;
  uint endBit;
  int value;
{
  int bitsLeft;
  uint wordByteOffset;
  
  if (endBit <= firstBit) {
    return;
  }
  bitsLeft = endBit - firstBit;
  do {
    if (value == 0) {
      wordByteOffset = firstBit >> 3 & 0x1ffffffc;
      *(uint *)(wordByteOffset + *(int *)(bitSet + 8)) =
           *(uint *)(wordByteOffset + *(int *)(bitSet + 8)) & ~(1 << (firstBit & 0x1f));
    }
    else {
      wordByteOffset = firstBit >> 3 & 0x1ffffffc;
      *(uint *)(wordByteOffset + *(int *)(bitSet + 8)) =
           *(uint *)(wordByteOffset + *(int *)(bitSet + 8)) | 1 << (firstBit & 0x1f);
    }
    firstBit = firstBit + 1;
    bitsLeft = bitsLeft + -1;
  } while (bitsLeft != 0);
  return;
}

/* _BitSetExpandEquals @ 0x97c07f7c (60 bytes) */
int _BitSetExpandEquals(bitSet, minBitCount)
  uint *bitSet;
  uint minBitCount;
{
  if (*bitSet < minBitCount) {
    ((int (*)())_BitSetSetSizeEquals)(bitSet,minBitCount);
  }
  return bitSet;
}

/* _BitSetSetSizeEquals @ 0x97c07fb8 (112 bytes) */
int _BitSetSetSizeEquals(bitSet, newBitCount)
  uint *bitSet;
  uint newBitCount;
{
  uint allocation;
  uint newByteSize;
  
  if (*bitSet != newBitCount) {
    newByteSize = (newBitCount >> 3 & 0x1ffffffc) + 4;
    allocation = _realloc(bitSet[2],newByteSize);
    bitSet[2] = allocation;
    ((int (*)())_BitSetSetRangeEqualsInternal)(bitSet,*bitSet,newBitCount,0);
    *bitSet = newBitCount;
    bitSet[1] = newByteSize;
  }
  return bitSet;
}

/* _BitSetNextSetBit @ 0x97c08030 (136 bytes) */
int _BitSetNextSetBit(bitSet, afterBit)
  uint *bitSet;
  int afterBit;
{
  uint word;
  uint foundBit;
  uint bitInWord;
  uint wordIndex;
  
  wordIndex = afterBit + 1U >> 5;
  bitInWord = afterBit + 1U & 0x1f;
  if (wordIndex < bitSet[1] >> 2) {
    do {
      word = *(uint *)(wordIndex * 4 + bitSet[2]);
      if ((word != 0) && (bitInWord < 0x20)) {
        do {
          if (((word & 1 << (bitInWord & 0x3f)) != 0) &&
             (foundBit = wordIndex * 0x20 + bitInWord, foundBit < *bitSet)) {
            return foundBit;
          }
          bitInWord = bitInWord + 1;
        } while (bitInWord < 0x20);
      }
      wordIndex = wordIndex + 1;
      bitInWord = 0;
    } while ((int)wordIndex < (int)(bitSet[1] >> 2));
  }
  return 0xffffffff;
}

/* _BitSetAndEquals @ 0x97c080b8 (128 bytes) */
int _BitSetAndEquals(bitSet, otherSet)
  undefined4 *bitSet;
  undefined4 *otherSet;
{
  int wordByteOffset;
  int wordIndex;
  uint wordsLeft;
  
  ((int (*)())_BitSetExpandEquals)(bitSet,*otherSet);
  ((int (*)())_BitSetExpandEquals)(otherSet,*bitSet);
  wordIndex = 0;
  for (wordsLeft = (uint)bitSet[1] >> 2; wordsLeft != 0; wordsLeft = wordsLeft - 1) {
    wordByteOffset = wordIndex * 4;
    wordIndex = wordIndex + 1;
    *(uint *)(wordByteOffset + bitSet[2]) = *(uint *)(wordByteOffset + bitSet[2]) & *(uint *)(wordByteOffset + otherSet[2]);
  }
  return bitSet;
}

/* _BitSetAndNotEquals @ 0x97c08138 (128 bytes) */
int _BitSetAndNotEquals(bitSet, otherSet)
  undefined4 *bitSet;
  undefined4 *otherSet;
{
  int wordByteOffset;
  int wordIndex;
  uint wordsLeft;
  
  ((int (*)())_BitSetExpandEquals)(bitSet,*otherSet);
  ((int (*)())_BitSetExpandEquals)(otherSet,*bitSet);
  wordIndex = 0;
  for (wordsLeft = (uint)bitSet[1] >> 2; wordsLeft != 0; wordsLeft = wordsLeft - 1) {
    wordByteOffset = wordIndex * 4;
    wordIndex = wordIndex + 1;
    *(uint *)(wordByteOffset + bitSet[2]) = *(uint *)(wordByteOffset + bitSet[2]) & ~*(uint *)(wordByteOffset + otherSet[2]);
  }
  return bitSet;
}

/* _BitSetOrEquals @ 0x97c081b8 (128 bytes) */
int _BitSetOrEquals(bitSet, otherSet)
  undefined4 *bitSet;
  undefined4 *otherSet;
{
  int wordByteOffset;
  int wordIndex;
  uint wordsLeft;
  
  ((int (*)())_BitSetExpandEquals)(bitSet,*otherSet);
  ((int (*)())_BitSetExpandEquals)(otherSet,*bitSet);
  wordIndex = 0;
  for (wordsLeft = (uint)bitSet[1] >> 2; wordsLeft != 0; wordsLeft = wordsLeft - 1) {
    wordByteOffset = wordIndex * 4;
    wordIndex = wordIndex + 1;
    *(uint *)(wordByteOffset + bitSet[2]) = *(uint *)(wordByteOffset + bitSet[2]) | *(uint *)(wordByteOffset + otherSet[2]);
  }
  return bitSet;
}

