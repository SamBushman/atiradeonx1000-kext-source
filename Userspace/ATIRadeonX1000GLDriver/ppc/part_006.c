#include "decls.h"

/* atifsReplayTextureOps @ 0x3e4d0 (276 bytes) */
int atifsReplayTextureOps(ctx, unusedArg2, opCount, opStream)
  undefined4 ctx;
  undefined4 unusedArg2;
  int opCount;
  uint *opStream;
{
  uint srcIndex;
  uint swizzleBits;
  int dstReg;
  int coordSrc;
  undefined4 swizzle;
  uint opWord;
  int loopIndex;
  
  if (opCount != 0) {
    loopIndex = 0;
    do {
      opWord = *opStream;
      opStream = opStream + 1;
      swizzle = 0x8977;
      swizzleBits = opWord & 0x300;
      dstReg = (opWord >> 0xc & 0xff) + 0x8921;
      if (swizzleBits != 0x100) {
        if (swizzleBits < 0x101) {
          swizzle = 0x8976;
          if (swizzleBits != 0) {
loopSetSwizzle:
            swizzle = 0;
          }
        }
        else {
          swizzle = 0x8978;
          if (swizzleBits != 0x200) {
            if (swizzleBits != 0x300) goto loopSetSwizzle;
            swizzle = 0x8979;
          }
        }
      }
      srcIndex = opWord >> 0x14 & 0xff;
      if ((opWord & 7) == 1) {
        coordSrc = srcIndex + 0x8921;
      }
      else {
        coordSrc = 0;
        if ((opWord & 7) == 5) {
          coordSrc = srcIndex + 0x84c0;
        }
      }
      if ((opWord & 0xf0) == 0) {
        glPassTexCoordATI_impl(ctx,dstReg,coordSrc,swizzle);
      }
      else {
        glSampleMapATI_impl(ctx,dstReg,coordSrc,swizzle);
      }
      loopIndex = loopIndex + 1;
    } while (opCount != loopIndex);
  }
  return;
}

/* atifsReplayColorAlphaOps @ 0x3e600 (1352 bytes) */
int atifsReplayColorAlphaOps(ctx, unusedArg2, opCount, opStream)
  undefined4 ctx;
  undefined4 unusedArg2;
  int opCount;
  uint *opStream;
{
  uint argRep;
  uint dstMask;
  uint argModMask;
  uint argRepBits;
  uint argKind;
  undefined *dstModBits;
  uint opBits;
  uint argReg;
  uint argWord;
  uint opHeader;
  uint *recordPtr;
  int loopIndex;
  int dstReg;
  int argCount;
  undefined4 glOp;
  uint dstMod;
  int argsLeft;
  undefined4 arg1;
  undefined4 arg1Rep;
  uint arg1Mod;
  undefined4 arg2;
  undefined4 arg2Rep;
  undefined4 arg2Mod;
  undefined4 arg3;
  undefined4 arg3Rep;
  undefined4 arg3Mod;
  
  if (opCount != 0) {
    argCount = 0;
    loopIndex = 0;
    do {
      opHeader = *opStream;
      opStream = opStream + 1;
      opBits = opHeader & 0xf00;
      if (opBits == 0x500) {
        glOp = 0x8967;
      }
      else if (opBits < 0x501) {
        if (opBits == 0x200) {
          glOp = 0x8964;
        }
        else if (opBits < 0x201) {
          if (opBits == 0) {
            glOp = 0x8961;
          }
          else {
            glOp = 0x8963;
            if (opBits != 0x100) {
loopSetGlOp:
              glOp = 0;
            }
          }
        }
        else if (opBits == 0x300) {
          glOp = 0x8965;
        }
        else {
          if (opBits != 0x400) goto loopSetGlOp;
          glOp = 0x8966;
        }
      }
      else if (opBits == 0x800) {
        glOp = 0x896a;
      }
      else if (opBits < 0x801) {
        if (opBits == 0x600) {
          glOp = 0x8968;
        }
        else {
          if (opBits != 0x700) goto loopSetGlOp;
          glOp = 0x8969;
        }
      }
      else if (opBits == 0x900) {
        glOp = 0x896b;
      }
      else {
        if (opBits != 0xa00) goto loopSetGlOp;
        glOp = 0x896c;
      }
      dstMod = 0;
      dstReg = (opHeader >> 0x14 & 0xff) + 0x8921;
      if ((opHeader & 0xf000) != 0) {
        dstModBits = (undefined *)(opHeader & 0x7000);
        dstMod = 4;
        if (dstModBits != (undefined *)0x3000) {
          if (dstModBits < (undefined *)0x3001) {
            dstMod = 1;
            if ((dstModBits != (undefined *)0x1000) && (dstMod = 2, dstModBits != (undefined *)0x2000)) {
loopSetDstMod:
              dstMod = 0;
            }
          }
          else {
            dstMod = 0x10;
            if ((dstModBits != ((unsigned char *)0x00005000)) && (dstMod = 0x20, dstModBits != (undefined *)0x6000)) {
              if (dstModBits != (undefined *)0x4000) goto loopSetDstMod;
              dstMod = 8;
            }
          }
        }
        if ((opHeader & 0x8000) != 0) {
          dstMod = dstMod | 0x40;
        }
      }
      if (opBits == 0) {
        argCount = 1;
loopSetRecordPtr:
        recordPtr = &arg1Mod;
        argsLeft = argCount;
        do {
          argWord = *opStream;
          opStream = opStream + 1;
          argKind = argWord & 7;
          argReg = argWord >> 0x14 & 0xff;
          if (argKind == 2) {
            argReg = argReg + 0x8941;
          }
          else if (argKind < 3) {
            if (argKind != 1) goto setArgReg;
            argReg = argReg + 0x8921;
          }
          else if (argKind != 3) {
            if (argKind == 4) {
              if (argReg == 0) {
                argReg = 0x8577;
              }
              else {
                if (argReg != 1) goto setArgReg;
                argReg = 0x896d;
              }
            }
            else {
setArgReg:
              argReg = 0;
            }
          }
          argRepBits = argWord & 0x7000;
          recordPtr[-2] = argReg;
          if (argRepBits == 0x2000) {
            argRep = 0x1904;
          }
          else if (argRepBits < 0x2001) {
            argRep = 0x1903;
            if (argRepBits != 0x1000) {
loopSetArgRep:
              argRep = 0;
            }
          }
          else {
            argRep = 0x1905;
            if ((argRepBits != 0x3000) && (argRep = 0x1906, argRepBits != 0x4000)) goto loopSetArgRep;
          }
          recordPtr[-1] = argRep;
          argModMask = 0;
          if ((argWord & 0xf00) != 0) {
            argModMask = argWord >> 6 & 4;
            if ((argWord & 0x200) != 0) {
              argModMask = argModMask | 1;
            }
            if ((argWord & 0x400) != 0) {
              argModMask = argModMask | 8;
            }
            if ((argWord & 0x800) != 0) {
              argModMask = argModMask | 2;
            }
          }
          *recordPtr = argModMask;
          recordPtr = recordPtr + 3;
          argsLeft = argsLeft + -1;
        } while (argsLeft != 0);
      }
      else {
        if (opBits < 0x501) {
          argCount = 2;
          goto loopSetRecordPtr;
        }
        if (opBits < 0xa01) {
          argCount = 3;
          goto loopSetRecordPtr;
        }
        if (argCount != 0) goto loopSetRecordPtr;
      }
      if ((opHeader & 0x70000) == 0) {
        dstMask = 0;
        if ((opHeader & 0xf0000) == 0) goto checkArgCount;
      }
      else {
        dstMask = (opHeader & 0x70000) >> 0x10 & 1;
        if ((opHeader & 0x20000) != 0) {
          dstMask = dstMask | 2;
        }
        if ((opHeader & 0x40000) != 0) {
          dstMask = dstMask | 4;
        }
checkArgCount:
        if (argCount == 2) {
          glColorFragmentOp2ATI_impl(ctx,glOp,dstReg,dstMask,dstMod,arg1,arg1Rep,arg1Mod,arg2,
                       arg2Rep,arg2Mod);
        }
        else if (argCount == 3) {
          glColorFragmentOp3ATI_impl(ctx,glOp,dstReg,dstMask,dstMod,arg1,arg1Rep,arg1Mod,arg2,
                       arg2Rep,arg2Mod,arg3,arg3Rep,arg3Mod);
        }
        else if (argCount == 1) {
          glColorFragmentOp1ATI_impl(ctx,glOp,dstReg,dstMask,dstMod,arg1,arg1Rep,arg1Mod);
        }
      }
      if (((opHeader & 0x80000) != 0) || ((opHeader & 0xf0000) == 0)) {
        if (argCount == 2) {
          glAlphaFragmentOp2ATI_impl(ctx,glOp,dstReg,dstMod,arg1,arg1Rep,arg1Mod,arg2,arg2Rep,
                       arg2Mod);
        }
        else if (argCount == 3) {
          glAlphaFragmentOp3ATI_impl(ctx,glOp,dstReg,dstMod,arg1,arg1Rep,arg1Mod,arg2,arg2Rep,
                       arg2Mod,arg3,arg3Rep,arg3Mod);
        }
        else if (argCount == 1) {
          glAlphaFragmentOp1ATI_impl(ctx,glOp,dstReg,dstMod,arg1,arg1Rep,arg1Mod);
        }
      }
      loopIndex = loopIndex + 1;
    } while (opCount != loopIndex);
  }
  return;
}

/* atifsReplayProgram @ 0x3eb70 (296 bytes) */
int atifsReplayProgram(ctx, shader, unusedArg3)
  int ctx;
  uint *shader;
  undefined4 unusedArg3;
{
  ushort constDataBaseWords;
  uint constWord;
  undefined4 compiledProgram;
  uint constCount;
  uint loopIndex;
  uint *constCursor;
  
  *(undefined2 *)(ctx + 0x2800) = 0;
  glBeginFragmentShaderATI_impl(ctx);
  constDataBaseWords = *(ushort *)((int)shader + 0x16);
  constCount = *shader >> 0x10 & 0xff;
  constCursor = shader + (*shader & 0xffff);
  if (constCount != 0) {
    loopIndex = 0;
    do {
      constWord = *constCursor;
      constCursor = constCursor + 1;
      if ((constWord & 3) == 1) {
        glSetFragmentShaderConstantATI_impl(ctx,(constWord >> 0x14 & 0xff) + 0x8941,
                     (int)shader + (constWord >> 8 & 0xff0) + (uint)constDataBaseWords * 4);
      }
      loopIndex = loopIndex + 1;
    } while (constCount != loopIndex);
  }
  ((int (*)())atifsReplayTextureOps)(ctx,unusedArg3,shader[1] >> 0x10 & 0xff,shader + (shader[1] & 0xffff));
  ((int (*)())atifsReplayColorAlphaOps)(ctx,unusedArg3,shader[2] >> 0x10 & 0xff,shader + (shader[2] & 0xffff));
  ((int (*)())atifsReplayTextureOps)(ctx,unusedArg3,shader[3] >> 0x10 & 0xff,shader + (shader[3] & 0xffff));
  ((int (*)())atifsReplayColorAlphaOps)(ctx,unusedArg3,shader[4] >> 0x10 & 0xff,shader + (shader[4] & 0xffff));
  glEndFragmentShaderATI_impl(ctx);
  compiledProgram = gld_getFragmentShaderKind(ctx);
  *(undefined4 *)(ctx + 0x27b8) = compiledProgram;
  return 1;
}

/* fpilEmitAngleConstants @ 0x3eca0 (164 bytes) */
int fpilEmitAngleConstants(emitter, opRecordOffset, entryHeader, srcRegWord1, unusedArg5, unusedArg6, unusedArg7)
  int *emitter;
  undefined4 opRecordOffset;
  undefined4 entryHeader;
  undefined4 srcRegWord1;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  float angleConst0;
  float angleConst1;
  float angleConst2;
  float angleConst3;
  uint translatorFlags;
  uint constRegisterBase;
  int constTokenPos;
  int tokenData;
  
  translatorFlags = *(uint *)(emitter[0xd] + 0x20);
  if ((translatorFlags & 0x4000000) == 0) {
    *(uint *)(emitter[0xd] + 0x20) = translatorFlags | 0x4000000;
    angleConst3 = FLOAT_001aa13c;
    angleConst2 = FLOAT_001aa138;
    angleConst1 = FLOAT_001aa134;
    angleConst0 = FLOAT_001aa130;
    constTokenPos = emitter[6];
    tokenData = emitter[10];
    *(undefined4 *)(constTokenPos * 4 + tokenData) = 0x1c;
    tokenData = constTokenPos * 4 + tokenData;
    constRegisterBase = *(uint *)(*emitter + 0x28);
    *(float *)(tokenData + 8) = angleConst0;
    *(uint *)(tokenData + 4) = constRegisterBase & 0xffff | 0x10000;
    *(float *)(tokenData + 0x14) = angleConst3;
    *(float *)(tokenData + 0xc) = angleConst1;
    *(float *)(tokenData + 0x10) = angleConst2;
    emitter[6] = emitter[6] + 6;
  }
  return emitter[9];
}

/* fpilClassifyDestination @ 0x3ed50 (60 bytes) */
int fpilClassifyDestination(translator, irDest)
  int *translator;
  int irDest;
{
  uint destEntryWord;
  
  destEntryWord = *(uint *)(((uint)*(ushort *)(irDest + 6) + *(int *)(*translator + 0x14)) * 8 + *translator) >>
          0x1a & 7;
  if (destEntryWord == 3) {
    return 1;
  }
  return (uint)(destEntryWord == 4) << 1;
}

/* fpilBuildDestinationToken @ 0x3ed90 (160 bytes) */
int fpilBuildDestinationToken(translator, irDest, outToken, outMask, saturate)
  int *translator;
  uint *irDest;
  uint *outToken;
  uint *outMask;
  int saturate;
{
  ushort irIndex;
  uint regIndex;
  uint modifier;
  int programTempBase;
  uint irWord;
  
  irWord = *irDest;
  modifier = 0;
  if ((irWord & 0xe0000) == 0x20000) {
    regIndex = (uint)*(ushort *)((int)irDest + 6);
  }
  else {
    irIndex = *(ushort *)((int)irDest + 6);
    programTempBase = *(int *)(*translator + 0x10);
    translator[4] = 1 << (irIndex & 0x3f) | translator[4];
    regIndex = (uint)irIndex + programTempBase + 1;
    irWord = *irDest;
  }
  if (saturate != 0) {
    modifier = 0x100;
  }
  *outToken = regIndex & 0xffff | 0x440000;
  *outMask = (irWord >> 0x10 & 1) << 6 |
             (irWord >> 0xf & 1) << 4 | (irWord >> 0xe & 1) << 2 | irWord >> 0xd & 1 | modifier;
  return 0;
}

/* fpilSetComponentSelect @ 0x3ee30 (88 bytes) */
int fpilSetComponentSelect(selectValue, componentIdx, swizzleWord)
  uint selectValue;
  int componentIdx;
  uint *swizzleWord;
{
  if (componentIdx == 0) {
    *swizzleWord = selectValue & 7 | *swizzleWord & 0xfffffff8;
    return;
  }
  if (componentIdx == 1) {
    *swizzleWord = (selectValue & 7) << 4 | *swizzleWord & 0xffffff8f;
    return;
  }
  if (componentIdx == 2) {
    *swizzleWord = (selectValue & 7) << 8 | *swizzleWord & 0xfffff8ff;
    return;
  }
  *swizzleWord = (selectValue & 7) << 0xc | *swizzleWord & 0xffff8fff;
  return;
}

/* fpilEmitScalarConstant @ 0x3eea0 (168 bytes) */
int fpilEmitScalarConstant(translator, constValue, outRegister)
  int translator;
  undefined4 constValue;
  uint *outRegister;
{
  int tokenData;
  uint translatorFlags;
  int constTokenOffsetOrAddr;
  
  if ((*(uint *)(translator + 0x14) >> 0x15 & 0x3f) < 0x20) {
    tokenData = *(int *)(translator + 0x28);
    constTokenOffsetOrAddr = *(int *)(translator + 0x18) * 4;
    *(undefined4 *)(constTokenOffsetOrAddr + tokenData) = 0x1c;
    constTokenOffsetOrAddr = constTokenOffsetOrAddr + tokenData;
    translatorFlags = *(uint *)(translator + 0x14);
    *(undefined4 *)(constTokenOffsetOrAddr + 0x14) = 0;
    *(undefined4 *)(constTokenOffsetOrAddr + 0xc) = 0;
    *(undefined4 *)(constTokenOffsetOrAddr + 0x10) = 0;
    *(undefined4 *)(constTokenOffsetOrAddr + 8) = constValue;
    *(uint *)(constTokenOffsetOrAddr + 4) = translatorFlags >> 0x15 & 0x3f | 0x20000;
    *(int *)(translator + 0x18) = *(int *)(translator + 0x18) + 6;
    *outRegister = *(uint *)(translator + 0x14) >> 0x15 & 0x3f;
    *(uint *)(translator + 0x14) =
         ((*(uint *)(translator + 0x14) >> 0x15 & 0x3f) + 1) * 0x200000 & 0x7e00000 |
         *(uint *)(translator + 0x14) & 0xf81fffff;
    return *(int *)(translator + 0x24);
  }
  if (*(int *)(translator + 0x24) != 0) {
    return *(int *)(translator + 0x24);
  }
  *(undefined4 *)(translator + 0x24) = 4;
  return 4;
}

/* fpilReserveTokens @ 0x3ef50 (240 bytes) */
int fpilReserveTokens(translator, nWords, outPtr)
  int translator;
  int nWords;
  int *outPtr;
{
  int allocation;
  uint tokenCapacity;
  int tokenCount;
  int *tokenDataPtrAddr;
  
  tokenDataPtrAddr = (int *)(translator + 0x28);
  tokenCount = *(int *)(translator + 0x2c);
  tokenCapacity = *(uint *)(translator + 0x30);
  if (tokenCapacity < (uint)(nWords + tokenCount)) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < (uint)(nWords + tokenCount); tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
      if (*(int *)(translator + 0x24) != 0) {
        return *(int *)(translator + 0x24);
      }
      *(undefined4 *)(translator + 0x24) = 1;
      return 1;
    }
    *tokenDataPtrAddr = allocation;
    *(uint *)(translator + 0x30) = tokenCapacity;
    tokenCount = *(int *)(translator + 0x2c);
  }
  *(int *)(translator + 0x2c) = nWords + tokenCount;
  *outPtr = tokenCount * 4 + *tokenDataPtrAddr;
  return 0;
}

/* fpilMapConstantRegister @ 0x3f050 (336 bytes) */
int fpilMapConstantRegister(translator, instIndex, outRegister)
  int *translator;
  int instIndex;
  undefined4 *outRegister;
{
  int constEntryOffset;
  int constEntry;
  uint cachedPairCount;
  int loopIndex;
  byte *nextPairByte;
  ushort wantedIndex;
  int instRecord;
  byte *pairCache;
  int program;
  byte *scanPtr;
  uint entryWord;
  uint pairsLeft;
  
  program = *translator;
  instRecord = program + *(int *)(program + 0x54) * 8 + instIndex * 8;
  if ((*(uint *)(instRecord + 0x18) & 0x3800000) == 0x1000000) {
    constEntryOffset = ((uint)*(ushort *)(instRecord + 0x1e) + *(int *)(program + 0x2c)) * 8;
    entryWord = *(uint *)(program + constEntryOffset);
    constEntry = program + constEntryOffset;
    if (((entryWord & 0x1f0000) == 0x10000) && ((entryWord & 0x1c000000) == 0xc000000)) {
      *outRegister = *(undefined4 *)((uint)*(ushort *)(constEntry + 2) * 0x10 + translator[3]);
      pairCache = (byte *)translator[0xd];
      cachedPairCount = *(uint *)(pairCache + 0x20) >> 0x1b;
      if (cachedPairCount == 0) {
        wantedIndex = *(ushort *)(constEntry + 2);
loopStorePairCache:
        pairCache[cachedPairCount * 2] = (byte)wantedIndex;
        *(char *)(cachedPairCount * 2 + translator[0xd] + 1) = (char)*outRegister;
        *(int *)(translator[0xd] + 0x20) = *(int *)(translator[0xd] + 0x20) + 0x8000000;
        return 0;
      }
      wantedIndex = *(ushort *)(constEntry + 2);
      if (*pairCache != wantedIndex) {
        loopIndex = 0;
        scanPtr = pairCache;
        pairsLeft = cachedPairCount;
        do {
          loopIndex = loopIndex + 1;
          pairsLeft = pairsLeft - 1;
          if (pairsLeft == 0) {
            if (0xf < loopIndex) {
              if (translator[9] != 0) {
                return translator[9];
              }
              translator[9] = 4;
              return 4;
            }
            goto loopStorePairCache;
          }
          nextPairByte = scanPtr + 2;
          scanPtr = scanPtr + 2;
        } while (*nextPairByte != wantedIndex);
      }
      return 0;
    }
  }
  if (translator[9] != 0) {
    return translator[9];
  }
  translator[9] = 2;
  return 2;
}

/* fpilTranslateSource @ 0x3f1c0 (700 bytes) */
int fpilTranslateSource(translator, irSource, outToken, outSwizzle)
  int *translator;
  uint *irSource;
  uint *outToken;
  uint *outSwizzle;
{
  uint select2;
  uint ilSwizzle;
  uint componentCount;
  uint select3;
  int paramEntryOffset;
  bool remapSwizzle;
  uint srcNegate;
  uint negate0;
  uint srcKindBits;
  uint select0;
  uint srcWord;
  int program;
  uint comp0Bits;
  undefined *ilSourceToken;
  
  srcWord = *irSource;
  srcKindBits = srcWord & 0x3800000;
  if (srcKindBits == 0) {
    program = *translator;
    paramEntryOffset = ((uint)*(ushort *)((int)irSource + 6) + *(int *)(program + 0x24)) * 8;
    switch(*(ushort *)(program + paramEntryOffset) & 0xf) {
    default:
programCase0:
      if (translator[9] != 0) {
        return translator[9];
      }
      translator[9] = 3;
      return 3;
    case 1:
      remapSwizzle = false;
      ilSourceToken = ((unsigned char *)0x00160000);
      break;
    case 2:
      remapSwizzle = false;
      ilSourceToken = (undefined *)0x120000;
      break;
    case 3:
      remapSwizzle = false;
      ilSourceToken = (undefined *)0x130000;
      break;
    case 5:
      remapSwizzle = true;
      ilSourceToken = (undefined *)0x100000;
      break;
    case 7:
      remapSwizzle = false;
      ilSourceToken = (undefined *)(*(uint *)(program + paramEntryOffset) & 0x1f | 0x110000);
    }
  }
  else if (srcKindBits == 0x1000000) {
    remapSwizzle = false;
    ilSourceToken = (undefined *)(*(ushort *)((int)irSource + 6) | 0x10000);
  }
  else if (srcKindBits == 0x800000) {
    remapSwizzle = false;
    ilSourceToken = (undefined *)(*(ushort *)((int)irSource + 6) | 0x40000);
  }
  else {
    if (srcKindBits != 0x1800000) goto programCase0;
    remapSwizzle = false;
    ilSourceToken = (undefined *)
              ((uint)*(ushort *)((int)irSource + 6) + *(int *)(*translator + 0x10) + 1 & 0xffff |
              0x40000);
  }
  if ((translator[5] & 0x20000000U) == 0) {
    componentCount = 4;
  }
  else {
    componentCount = (srcWord >> 0xc & 3) + 1;
  }
  srcNegate = srcWord >> 0x1b & 1;
  select0 = 4;
  if (componentCount != 0) {
    select0 = *(uint *)(&fpilSourceInfoTable_001dac08 + (srcWord >> 0x13 & 0xc)) >> 0x19 & 7;
  }
  negate0 = srcNegate ^ *(uint *)(&fpilSourceInfoTable_001dac08 + (srcWord >> 0x13 & 0xc)) >> 0x18 & 1;
  comp0Bits = negate0 << 3 | select0;
  if (componentCount < 2) {
    ilSwizzle = negate0 << 0xf |
            select0 << 0xc | negate0 << 0xb | select0 << 8 | negate0 << 7 | select0 << 4 | comp0Bits;
  }
  else {
    select2 = 4;
    if (2 < componentCount) {
      select2 = *(uint *)(&fpilSourceInfoTable_001dac08 + (srcWord >> 0xf & 0xc)) >> 0x19 & 7;
    }
    select3 = 4;
    if (3 < componentCount) {
      select3 = *(uint *)(&fpilSourceInfoTable_001dac08 + (srcWord >> 0xd & 0xc)) >> 0x19 & 7;
    }
    ilSwizzle = (srcNegate ^ *(uint *)(&fpilSourceInfoTable_001dac08 + (srcWord >> 0xd & 0xc)) >> 0x18 & 1) << 0xf |
            select3 << 0xc |
            (srcNegate ^ *(uint *)(&fpilSourceInfoTable_001dac08 + (srcWord >> 0xf & 0xc)) >> 0x18 & 1) << 0xb |
            select2 << 8 |
            (srcNegate ^ *(uint *)(&fpilSourceInfoTable_001dac08 + (srcWord >> 0x11 & 0xc)) >> 0x18 & 1) << 7 |
            *(uint *)(&fpilSourceInfoTable_001dac08 + (srcWord >> 0x11 & 0xc)) >> 0x15 & 0x70 | comp0Bits;
  }
  if (remapSwizzle) {
    ilSwizzle = ((byte)(fpilSwizzleComponentTable_001dac00)[ilSwizzle >> 0xc & 7] & 7) << 0xc |
            ((byte)(fpilSwizzleComponentTable_001dac00)[ilSwizzle >> 8 & 7] & 7) << 8 |
            ((byte)(fpilSwizzleComponentTable_001dac00)[ilSwizzle >> 4 & 7] & 7) << 4 |
            (byte)(fpilSwizzleComponentTable_001dac00)[ilSwizzle & 7] & 7 | ilSwizzle & 0xffff8888;
  }
  *outToken = (uint)ilSourceToken | 0x400000;
  *outSwizzle = ilSwizzle;
  return 0;
}

/* fpilTranslateSourceWithSwizzle @ 0x3f4e0 (232 bytes) */
int fpilTranslateSourceWithSwizzle(translator, irSource, outToken, outSwizzle, selectWordPtr)
  int translator;
  uint *irSource;
  undefined4 *outToken;
  uint *outSwizzle;
  uint *selectWordPtr;
{
  uint compEntry0;
  uint compEntry3;
  int srcResult;
  undefined4 result;
  uint compEntry2;
  uint compEntry1;
  uint selectWord;
  uint srcNegate;
  undefined4 ilToken;
  uint ilSwizzleWords [7];
  
  srcResult = ((int (*)())fpilTranslateSource)(translator,irSource,&ilToken,ilSwizzleWords);
  if (srcResult == 0) {
    selectWord = *selectWordPtr;
    result = 0;
    srcNegate = *irSource >> 0x1b & 1;
    compEntry3 = *(uint *)(&fpilSourceInfoTable_001dac08 + (selectWord >> 10 & 0x3c));
    compEntry1 = *(uint *)(&fpilSourceInfoTable_001dac08 + (selectWord >> 6 & 0x3c));
    compEntry2 = *(uint *)(&fpilSourceInfoTable_001dac08 + (selectWord >> 2 & 0x3c));
    compEntry0 = *(uint *)(&fpilSourceInfoTable_001dac08 + (selectWord & 0xf) * 4);
    *outToken = ilToken;
    *outSwizzle = (srcNegate ^ compEntry0 >> 0x18 & 1) << 0xf |
               compEntry0 >> 0xd & 0x7000 |
               (srcNegate ^ compEntry2 >> 0x18 & 1) << 0xb |
               compEntry2 >> 0x11 & 0x700 |
               (srcNegate ^ compEntry1 >> 0x18 & 1) << 7 |
               compEntry1 >> 0x15 & 0x70 |
               (srcNegate ^ compEntry3 >> 0x18 & 1) << 3 | compEntry3 >> 0x19 & 7 | ilSwizzleWords[0] & 0xffff0000;
  }
  else {
    result = *(undefined4 *)(translator + 0x24);
  }
  return result;
}

/* freeIfNonNull @ 0x3f5d0 (12 bytes) */
int freeIfNonNull(pointer)
  int pointer;
{
  if (pointer == 0) {
    return;
  }
  return _free(pointer);
}

/* fpilDestroyTranslator @ 0x3f5e0 (112 bytes) */
int fpilDestroyTranslator(translator)
  int translator;
{
  if (*(int *)(translator + 0x34) != 0) {
    ((int (*)())freeIfNonNull)(*(int *)(translator + 0x34));
  }
  if (*(int *)(translator + 0x28) != 0) {
    _free(*(int *)(translator + 0x28));
  }
  if (translator != 0) {
    _free(translator);
    return;
  }
  return;
}

/* fpilCreateTranslator @ 0x3f660 (220 bytes) */
int fpilCreateTranslator()
{
  int bufferOrZero;
  int allocation;
  int allocation2;
  
  allocation = _malloc(0x38);
  if (allocation != 0) {
    _memset(allocation,0,0x38);
    *(undefined4 *)(allocation + 0x24) = 0;
    *(undefined4 *)(allocation + 0x28) = 0;
    *(undefined4 *)(allocation + 0x30) = 0;
    *(undefined4 *)(allocation + 0x2c) = 0;
    *(undefined4 *)(allocation + 4) = 0xffffffff;
    *(undefined4 *)(allocation + 8) = 0xffffffff;
    allocation2 = _malloc(0x24);
    bufferOrZero = 0;
    if (allocation2 != 0) {
      _memset(allocation2,0,0x24);
      bufferOrZero = allocation2;
    }
    *(int *)(allocation + 0x34) = bufferOrZero;
    if (*(int *)(allocation + 0x34) != 0) {
      return allocation;
    }
    if (allocation != 0) {
      _free(allocation);
      return 0;
    }
  }
  return 0;
}

/* fpilTranslateDestination @ 0x3f750 (232 bytes) */
int fpilTranslateDestination(translator, irDest, outToken, outMask, flag)
  int *translator;
  uint *irDest;
  uint *outToken;
  uint *outMask;
  undefined4 flag;
{
  undefined4 tempBase;
  undefined4 buildResult;
  uint destWord;
  
  if (((translator[5] & 0x20000000U) != 0) &&
     (((((destWord = *irDest, (destWord & 0x2000) != 0 && ((destWord & 0x300) != 0)) ||
        (((destWord & 0x4000) != 0 && ((destWord & 0xc0) != 0x40)))) ||
       (((destWord & 0x8000) != 0 && ((destWord & 0x30) != 0x20)))) ||
      (((destWord & 0x10000) != 0 && ((destWord & 0xc) != 0xc)))))) {
    tempBase = *(undefined4 *)(*translator + 0x10);
    *outToken = 0;
    *outMask = 0;
    *outToken = *outToken & 0xffc0ffff | 0x40000;
    *(short *)((int)outToken + 2) = (short)tempBase;
    *outToken = *outToken | 0x400000;
    *outMask = *outMask & 0xffffff00 | 0x55;
    return 0;
  }
  buildResult = ((int (*)())fpilBuildDestinationToken)(translator,irDest,outToken,outMask,flag);
  return buildResult;
}

/* fpilEmitEmptyProgram @ 0x3f850 (396 bytes) */
int fpilEmitEmptyProgram(translator)
  int translator;
{
  int translatorError;
  int allocation;
  uint tokenCapacity;
  int tokenCount;
  dword *tokenWord4Ptr;
  dword *tokenWord5Ptr;
  dword *tokenWord6Ptr;
  undefined4 *tokenWritePtr;
  dword *tokenWord1Ptr;
  int *tokenDataPtrAddr;
  dword *tokenWord2Ptr;
  dword *tokenWord3Ptr;
  
  tokenDataPtrAddr = (int *)(translator + 0x28);
  *(undefined4 *)(translator + 0x2c) = 0;
  *(undefined4 *)(translator + 0x24) = 0;
  tokenCount = *(int *)(translator + 0x2c);
  tokenCapacity = *(uint *)(translator + 0x30);
  if (tokenCapacity < tokenCount + 7U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
      translatorError = *(int *)(translator + 0x24);
      if (translatorError == 0) {
        translatorError = 1;
        *(undefined4 *)(translator + 0x24) = 1;
      }
      if (translatorError != 0) {
        return translatorError;
      }
      tokenWritePtr = (undefined4 *)0x0;
      tokenWord1Ptr = ((unsigned char *)0x4);
      tokenWord2Ptr = ((unsigned char *)0x8);
      tokenWord3Ptr = ((unsigned char *)0xc);
      tokenWord4Ptr = ((unsigned char *)0x10);
      tokenWord5Ptr = ((unsigned char *)0x14);
      tokenWord6Ptr = ((unsigned char *)0x18);
      goto storeTokenWritePtr;
    }
    *tokenDataPtrAddr = allocation;
    *(uint *)(translator + 0x30) = tokenCapacity;
    tokenCount = *(int *)(translator + 0x2c);
  }
  *(int *)(translator + 0x2c) = tokenCount + 7;
  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
  tokenWord1Ptr = tokenWritePtr + 1;
  tokenWord2Ptr = tokenWritePtr + 2;
  tokenWord3Ptr = tokenWritePtr + 3;
  tokenWord4Ptr = tokenWritePtr + 4;
  tokenWord5Ptr = tokenWritePtr + 5;
  tokenWord6Ptr = tokenWritePtr + 6;
storeTokenWritePtr:
  *tokenWritePtr = 1;
  *tokenWord1Ptr = 0x10200;
  *tokenWord2Ptr = 0x47;
  *tokenWord3Ptr = 0x170000;
  *tokenWord4Ptr = 0x440000;
  *tokenWord5Ptr = (dword)((unsigned char *)0x00004444);
  *tokenWord6Ptr = 0x28;
  return 0;
}

/* fpilEmitMoveFromTemp @ 0x3f9f0 (472 bytes) */
int fpilEmitMoveFromTemp(translator, irDest, destFlag)
  int *translator;
  uint *irDest;
  undefined4 destFlag;
{
  uint tempBase;
  int translatorError;
  int tokenCount;
  int allocation;
  undefined4 *tokenWritePtr;
  int buildResult;
  uint tokenCapacity;
  uint compEntry1;
  uint compEntry2;
  dword *tokenWord1Ptr;
  dword *tokenWord4Ptr;
  uint compEntry3;
  uint compEntry0;
  dword *tokenWord2Ptr;
  uint destWord;
  dword *tokenWord3Ptr;
  int *tokenDataPtrAddr;
  dword destToken;
  dword destMaskWords [6];
  
  destToken = 0;
  destMaskWords[0] = 0;
  buildResult = ((int (*)())fpilBuildDestinationToken)(translator,irDest,&destToken,destMaskWords,destFlag);
  if (buildResult != 0) {
    return translator[9];
  }
  destWord = *irDest;
  tokenDataPtrAddr = translator + 10;
  tokenCount = translator[0xb];
  tokenCapacity = translator[0xc];
  compEntry3 = *(uint *)(&fpilSourceInfoTable_001dac08 + (destWord >> 6 & 0xc));
  compEntry2 = *(uint *)(&fpilSourceInfoTable_001dac08 + (destWord >> 4 & 0xc));
  compEntry1 = *(uint *)(&fpilSourceInfoTable_001dac08 + (destWord >> 2 & 0xc));
  compEntry0 = *(uint *)(&fpilSourceInfoTable_001dac08 + (destWord & 0xc));
  tempBase = *(uint *)(*translator + 0x10);
  if (tokenCapacity < tokenCount + 5U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
      translatorError = translator[9];
      if (translatorError == 0) {
        translatorError = 1;
        translator[9] = 1;
      }
      if (translatorError != 0) {
        return translatorError;
      }
      tokenWritePtr = (undefined4 *)0x0;
      tokenWord1Ptr = ((unsigned char *)0x4);
      tokenWord2Ptr = ((unsigned char *)0x8);
      tokenWord3Ptr = ((unsigned char *)0xc);
      tokenWord4Ptr = ((unsigned char *)0x10);
      goto storeTokenWritePtr;
    }
    *tokenDataPtrAddr = allocation;
    translator[0xc] = tokenCapacity;
    tokenCount = translator[0xb];
  }
  translator[0xb] = tokenCount + 5;
  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
  tokenWord1Ptr = tokenWritePtr + 1;
  tokenWord2Ptr = tokenWritePtr + 2;
  tokenWord3Ptr = tokenWritePtr + 3;
  tokenWord4Ptr = tokenWritePtr + 4;
storeTokenWritePtr:
  *tokenWritePtr = 0x47;
  *tokenWord1Ptr = destToken;
  *tokenWord2Ptr = destMaskWords[0];
  *tokenWord3Ptr = tempBase & 0xffff | 0x440000;
  *tokenWord4Ptr = compEntry0 >> 9 & 0x8000 |
            compEntry0 >> 0xd & 0x7000 |
            compEntry1 >> 0xd & 0x800 |
            compEntry1 >> 0x11 & 0x700 |
            compEntry2 >> 0x11 & 0x80 | compEntry2 >> 0x15 & 0x70 | compEntry3 >> 0x15 & 8 | compEntry3 >> 0x19 & 7;
  return 0;
}

/* fpilEmitInstruction @ 0x3fbf0 (392 bytes) */
int fpilEmitInstruction(translator, ilInstr, nDst, nSrc)
  int translator;
  undefined4 *ilInstr;
  int nDst;
  int nSrc;
{
  int headerWords;
  int errorCode;
  int allocation;
  undefined4 *srcAuxWordPtr;
  uint capacityWords;
  uint requiredWords;
  undefined4 *recordPtr;
  undefined4 *sourceOutPtr;
  int usedWords;
  int recordWords;
  int *dataPtrAddr;
  
  if (*(int *)(translator + 0x24) != 0) {
    return *(int *)(translator + 0x24);
  }
  dataPtrAddr = (int *)(translator + 0x28);
  usedWords = *(int *)(translator + 0x2c);
  capacityWords = *(uint *)(translator + 0x30);
  recordWords = (nDst + nSrc) * 2 + 1;
  requiredWords = recordWords + usedWords;
  if (capacityWords < requiredWords) {
    if (capacityWords == 0) {
      capacityWords = 0x10;
    }
    else {
      capacityWords = capacityWords << 1;
    }
    for (; capacityWords < requiredWords; capacityWords = capacityWords << 1) {
    }
    if (*dataPtrAddr == 0) {
      allocation = _malloc(capacityWords << 2);
    }
    else {
      allocation = _realloc(*dataPtrAddr,capacityWords << 2);
    }
    if (allocation == 0) {
      errorCode = *(int *)(translator + 0x24);
      if (errorCode == 0) {
        errorCode = 1;
        *(undefined4 *)(translator + 0x24) = 1;
      }
      recordPtr = (undefined4 *)0x0;
      if (errorCode != 0) {
        return errorCode;
      }
      goto storeRecordPtr;
    }
    *dataPtrAddr = allocation;
    *(uint *)(translator + 0x30) = capacityWords;
    usedWords = *(int *)(translator + 0x2c);
  }
  *(int *)(translator + 0x2c) = recordWords + usedWords;
  recordPtr = (undefined4 *)(usedWords * 4 + *dataPtrAddr);
storeRecordPtr:
  *recordPtr = *ilInstr;
  if (nDst == 0) {
    headerWords = 1;
  }
  else {
    headerWords = 3;
    recordPtr[1] = ilInstr[1];
    recordPtr[2] = ilInstr[2];
  }
  if (0 < nSrc) {
    recordPtr = recordPtr + headerWords;
    sourceOutPtr = recordPtr;
    do {
      *sourceOutPtr = ilInstr[3];
      sourceOutPtr = sourceOutPtr + 2;
      srcAuxWordPtr = ilInstr + 6;
      ilInstr = ilInstr + 1;
      recordPtr[1] = *srcAuxWordPtr;
      recordPtr = recordPtr + 2;
      nSrc = nSrc + -1;
    } while (nSrc != 0);
  }
  return 0;
}

/* fragmentTranslateSimpleOp @ 0x3fd80 (440 bytes) */
int fragmentTranslateSimpleOp(translator, slot, ilInstr)
  int *translator;
  int slot;
  undefined4 *ilInstr;
{
  uint hasDestination;
  int translatorError;
  int tokenCount;
  int allocation;
  undefined4 *srcWordPtr;
  uint tokenCapacity;
  uint requiredTokenWords;
  undefined4 *tokenWritePtr;
  undefined4 *srcPairCursor;
  uint opWord;
  int headerWords;
  int instrWords;
  int *tokenDataPtrAddr;
  uint srcCount;
  
  opWord = *(uint *)(*translator + *(int *)(*translator + 0x54) * 8 + slot * 8);
  srcCount = opWord >> 0x1d;
  hasDestination = (*(uint *)(&fragmentOpcodeInfoTable_word3_001dac40 + (opWord >> 0xe & 0xff0)) ^ 0x20000000) >> 0x1d & 1;
  if (translator[9] != 0) {
    return translator[9];
  }
  tokenDataPtrAddr = translator + 10;
  tokenCount = translator[0xb];
  tokenCapacity = translator[0xc];
  instrWords = (hasDestination + srcCount) * 2 + 1;
  requiredTokenWords = instrWords + tokenCount;
  if (tokenCapacity < requiredTokenWords) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < requiredTokenWords; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
      translatorError = translator[9];
      if (translatorError == 0) {
        translatorError = 1;
        translator[9] = 1;
      }
      tokenWritePtr = (undefined4 *)0x0;
      if (translatorError != 0) {
        return translatorError;
      }
      goto storeTokenWritePtr;
    }
    *tokenDataPtrAddr = allocation;
    translator[0xc] = tokenCapacity;
    tokenCount = translator[0xb];
  }
  translator[0xb] = instrWords + tokenCount;
  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
storeTokenWritePtr:
  *tokenWritePtr = *ilInstr;
  if (hasDestination == 0) {
    headerWords = 1;
  }
  else {
    headerWords = 3;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
  }
  if (srcCount != 0) {
    tokenWritePtr = tokenWritePtr + headerWords;
    srcPairCursor = tokenWritePtr;
    do {
      *srcPairCursor = ilInstr[3];
      srcPairCursor = srcPairCursor + 2;
      srcWordPtr = ilInstr + 6;
      ilInstr = ilInstr + 1;
      tokenWritePtr[1] = *srcWordPtr;
      tokenWritePtr = tokenWritePtr + 2;
      srcCount = srcCount - 1;
    } while (srcCount != 0);
  }
  return 0;
}

/* fragmentTranslateRep @ 0x3ff40 (592 bytes) */
int fragmentTranslateRep(translator, slot, ilInstr)
  int *translator;
  undefined4 slot;
  undefined4 *ilInstr;
{
  uint tokenCapacity;
  int translatorError;
  int tokenCount;
  int allocation;
  int paramTableBase;
  int srcEntryOffset;
  undefined4 *tokenWritePtr;
  uint srcEntryWord;
  int program;
  dword *tokenWord2Ptr;
  dword *tokenWord1Ptr;
  int *tokenDataPtrAddr;
  int scalarOperand [4];
  longlong constAsInt64;
  float constValue;
  
  if ((ilInstr[3] & 0x3f0000) != 0x10000) {
    if (translator[9] != 0) {
      return translator[9];
    }
    translator[9] = 2;
    return 2;
  }
  program = *translator;
  srcEntryOffset = (uint)*(ushort *)((int)ilInstr + 0xe) * 8;
  paramTableBase = program + *(int *)(program + 0x2c) * 8;
  srcEntryWord = *(uint *)(paramTableBase + srcEntryOffset);
  if ((((srcEntryWord & 0x1f0000) == 0x110000) && ((srcEntryWord >> 0x1a & 7) < 2)) && ((ilInstr[6] & 7) < 4)) {
    scalarOperand[0] = translator[9];
    constValue = *(float *)(program + *(int *)(program + 0x6c) * 8 +
                          ((uint)*(ushort *)(paramTableBase + srcEntryOffset + 2) * 4 + (ilInstr[6] & 7)) * 4);
  }
  else {
    scalarOperand[0] = translator[9];
    if (scalarOperand[0] == 0) {
      scalarOperand[0] = 2;
      translator[9] = 2;
    }
    constValue = 0.0;
  }
  if (scalarOperand[0] != 0) {
    return scalarOperand[0];
  }
  constAsInt64 = (longlong)(int)constValue;
  ((int (*)())fpilEmitScalarConstant)(translator,(int)constValue,scalarOperand);
  ilInstr[3] = ilInstr[3] & 0xffc0ffff | 0x20000;
  *(short *)((int)ilInstr + 0xe) = (short)scalarOperand[0];
  if (translator[9] != 0) {
    return translator[9];
  }
  tokenDataPtrAddr = translator + 10;
  tokenCount = translator[0xb];
  tokenCapacity = translator[0xc];
  if (tokenCapacity < tokenCount + 3U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 3U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
      translatorError = translator[9];
      if (translatorError == 0) {
        translatorError = 1;
        translator[9] = 1;
      }
      if (translatorError != 0) {
        return translatorError;
      }
      tokenWritePtr = (undefined4 *)0x0;
      tokenWord1Ptr = ((unsigned char *)0x4);
      tokenWord2Ptr = ((unsigned char *)0x8);
      goto storeTokenWritePtr;
    }
    *tokenDataPtrAddr = allocation;
    translator[0xc] = tokenCapacity;
    tokenCount = translator[0xb];
  }
  translator[0xb] = tokenCount + 3;
  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
  tokenWord1Ptr = tokenWritePtr + 1;
  tokenWord2Ptr = tokenWritePtr + 2;
storeTokenWritePtr:
  *tokenWritePtr = *ilInstr;
  *tokenWord1Ptr = ilInstr[3];
  *tokenWord2Ptr = ilInstr[6];
  return 0;
}

/* fragmentTranslateDdy @ 0x401b0 (420 bytes) */
int fragmentTranslateDdy(translator, slot, ilInstr)
  int translator;
  undefined4 slot;
  undefined4 *ilInstr;
{
  uint tokenCapacity;
  int translatorError;
  int allocation;
  uint srcSwizzleWord;
  int tokenCount;
  dword *tokenWord1Ptr;
  dword *tokenWord2Ptr;
  undefined4 *tokenWritePtr;
  dword *tokenWord3Ptr;
  dword *tokenWord4Ptr;
  int *tokenDataPtrAddr;
  
  *(uint *)(*(int *)(translator + 0x34) + 0x20) =
       *(uint *)(*(int *)(translator + 0x34) + 0x20) | 0x1000000;
  if ((*(uint *)(*(int *)(translator + 0x34) + 0x20) & 0x800000) != 0) {
    srcSwizzleWord = ilInstr[6];
    ilInstr[6] = (srcSwizzleWord & 0xfffff777 ^ 0x8000) & 0x8000 |
                 (srcSwizzleWord & 0xffffff77 ^ 0x800) & 0x800 |
                 (srcSwizzleWord & 0xfffffff7 ^ 0x80) & 0x80 | (srcSwizzleWord ^ 8) & 8 | srcSwizzleWord & 0xffff7777;
  }
  if (*(int *)(translator + 0x24) != 0) {
    return *(int *)(translator + 0x24);
  }
  tokenDataPtrAddr = (int *)(translator + 0x28);
  tokenCount = *(int *)(translator + 0x2c);
  tokenCapacity = *(uint *)(translator + 0x30);
  if (tokenCapacity < tokenCount + 5U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
      translatorError = *(int *)(translator + 0x24);
      if (translatorError == 0) {
        translatorError = 1;
        *(undefined4 *)(translator + 0x24) = 1;
      }
      if (translatorError != 0) {
        return translatorError;
      }
      tokenWritePtr = (undefined4 *)0x0;
      tokenWord1Ptr = ((unsigned char *)0x4);
      tokenWord2Ptr = ((unsigned char *)0x8);
      tokenWord3Ptr = ((unsigned char *)0xc);
      tokenWord4Ptr = ((unsigned char *)0x10);
      goto storeTokenWritePtr;
    }
    *tokenDataPtrAddr = allocation;
    *(uint *)(translator + 0x30) = tokenCapacity;
    tokenCount = *(int *)(translator + 0x2c);
  }
  *(int *)(translator + 0x2c) = tokenCount + 5;
  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
  tokenWord1Ptr = tokenWritePtr + 1;
  tokenWord2Ptr = tokenWritePtr + 2;
  tokenWord3Ptr = tokenWritePtr + 3;
  tokenWord4Ptr = tokenWritePtr + 4;
storeTokenWritePtr:
  *tokenWritePtr = *ilInstr;
  *tokenWord1Ptr = ilInstr[1];
  *tokenWord2Ptr = ilInstr[2];
  *tokenWord3Ptr = ilInstr[3];
  *tokenWord4Ptr = ilInstr[6];
  return 0;
}

/* fragmentTranslateScalarMath @ 0x40370 (4 bytes) */
int fragmentTranslateScalarMath(translator, slot, ilInstr)
  int *translator;
  int slot;
  undefined4 *ilInstr;
{
  uint negate3;
  uint negate2;
  uint select2;
  uint select1;
  uint select3;
  uint tokenCapacity2;
  uint tokenCapacity;
  int translatorError;
  int tokenCount;
  undefined4 *tokenWritePtr;
  void *allocation;
  uint negate0;
  int tempRegister;
  uint negate1;
  undefined4 unaff_r21;
  undefined4 unaff_r22;
  uint componentCount;
  uint *dstMaskPtr;
  uint *swizzlePtr;
  uint srcSwizzleWord;
  int *tokenDataPtrAddr;
  
  componentCount = 1;
  if ((translator[5] & 0x20000000U) != 0) {
    componentCount = (*(uint *)(slot * 8 + *translator + *(int *)(*translator + 0x54) * 8 + 4) >> 0x1a & 3) + 1;
  }
  srcSwizzleWord = ilInstr[6];
  if (1 < componentCount) {
    tempRegister = translator[8];
    unaff_r22 = ilInstr[1];
    unaff_r21 = ilInstr[2];
    ilInstr[1] = 0x40000;
    *(short *)((int)ilInstr + 6) = (short)tempRegister;
    ilInstr[2] = 0x55;
    ilInstr[1] = ilInstr[1] | 0x400000;
  }
  negate0 = srcSwizzleWord >> 3 & 1;
  swizzlePtr = ilInstr + 6;
  ilInstr[6] = negate0 << 0xf |
               (srcSwizzleWord & 7) << 0xc |
               negate0 << 0xb |
               (srcSwizzleWord & 7) << 8 | negate0 << 7 | (srcSwizzleWord & 7) << 4 | negate0 << 3 | srcSwizzleWord & 0xffff0007;
  if (translator[9] == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 5U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
      }
      if ((void *)*tokenDataPtrAddr == (void *)0x0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc((void *)*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == (void *)0x0) {
        if (translator[9] == 0) {
          translator[9] = 1;
        }
        goto checkComponentCount;
      }
      *tokenDataPtrAddr = (int)allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    translator[0xb] = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    tokenWritePtr[3] = ilInstr[3];
    tokenWritePtr[4] = ilInstr[6];
  }
checkComponentCount:
  if (1 >= componentCount) {
    return translator[9];
  }
  select1 = srcSwizzleWord >> 4 & 7;
  negate1 = srcSwizzleWord >> 7 & 1;
  dstMaskPtr = ilInstr + 2;
  ilInstr[2] = ilInstr[2] & 0xfffffffc;
  *swizzlePtr = negate1 << 0xf |
            select1 << 0xc |
            negate1 << 0xb |
            select1 << 8 | negate1 << 7 | select1 << 4 | negate1 << 3 | select1 | *swizzlePtr & 0xffff0000;
  if (translator[9] == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 5U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
      }
      if ((void *)*tokenDataPtrAddr == (void *)0x0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc((void *)*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == (void *)0x0) {
        if (translator[9] == 0) {
          translator[9] = 1;
        }
        goto checkComponentCount2;
      }
      *tokenDataPtrAddr = (int)allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    translator[0xb] = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    tokenWritePtr[3] = ilInstr[3];
    tokenWritePtr[4] = ilInstr[6];
  }
checkComponentCount2:
  if (componentCount < 3) goto setTempRegister;
  select2 = srcSwizzleWord >> 8 & 7;
  negate2 = srcSwizzleWord >> 0xb & 1;
  *dstMaskPtr = *dstMaskPtr & 0xfffffff3;
  *swizzlePtr = negate2 << 0xf |
            select2 << 0xc |
            negate2 << 0xb |
            select2 << 8 | negate2 << 7 | select2 << 4 | negate2 << 3 | select2 | *swizzlePtr & 0xffff0000;
  if (translator[9] == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 5U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
      }
      if ((void *)*tokenDataPtrAddr == (void *)0x0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc((void *)*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == (void *)0x0) {
        if (translator[9] == 0) {
          translator[9] = 1;
        }
        goto checkComponentCount3;
      }
      *tokenDataPtrAddr = (int)allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    translator[0xb] = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    tokenWritePtr[3] = ilInstr[3];
    tokenWritePtr[4] = ilInstr[6];
  }
checkComponentCount3:
  if (componentCount == 4) {
    select3 = srcSwizzleWord >> 0xc & 7;
    negate3 = srcSwizzleWord >> 0xf & 1;
    *dstMaskPtr = *dstMaskPtr & 0xffffffcf;
    *swizzlePtr = negate3 << 0xf |
              select3 << 0xc |
              negate3 << 0xb |
              select3 << 8 | negate3 << 7 | select3 << 4 | negate3 << 3 | select3 | *swizzlePtr & 0xffff0000;
    if (translator[9] == 0) {
      tokenDataPtrAddr = translator + 10;
      tokenCount = translator[0xb];
      tokenCapacity2 = translator[0xc];
      if (tokenCapacity2 < tokenCount + 5U) {
        if (tokenCapacity2 == 0) {
          tokenCapacity2 = 0x10;
        }
        else {
          tokenCapacity2 = tokenCapacity2 << 1;
        }
        for (; tokenCapacity2 < tokenCount + 5U; tokenCapacity2 = tokenCapacity2 << 1) {
        }
        if ((void *)*tokenDataPtrAddr == (void *)0x0) {
          allocation = _malloc(tokenCapacity2 << 2);
        }
        else {
          allocation = _realloc((void *)*tokenDataPtrAddr,tokenCapacity2 << 2);
        }
        if (allocation == (void *)0x0) {
          if (translator[9] == 0) {
            translator[9] = 1;
          }
          goto setTempRegister;
        }
        *tokenDataPtrAddr = (int)allocation;
        translator[0xc] = tokenCapacity2;
        tokenCount = translator[0xb];
      }
      translator[0xb] = tokenCount + 5;
      tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
      *tokenWritePtr = *ilInstr;
      tokenWritePtr[1] = ilInstr[1];
      tokenWritePtr[2] = ilInstr[2];
      tokenWritePtr[3] = ilInstr[3];
      tokenWritePtr[4] = ilInstr[6];
    }
  }
setTempRegister:
  tempRegister = translator[8];
  ilInstr[3] = 0;
  *swizzlePtr = 0;
  ilInstr[3] = ilInstr[3] & 0xffc0ffff | 0x40000;
  *(short *)((int)ilInstr + 0xe) = (short)tempRegister;
  ilInstr[3] = ilInstr[3] | 0x400000;
  *swizzlePtr = *swizzlePtr & 0xffff0000 | 0x3210;
  *ilInstr = 0;
  ilInstr[1] = unaff_r22;
  ilInstr[2] = unaff_r21;
  *(undefined2 *)((int)ilInstr + 2) = 0x47;
  translatorError = translator[9];
  if (translatorError == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity2 = translator[0xc];
    if (tokenCapacity2 < tokenCount + 5U) {
      if (tokenCapacity2 == 0) {
        tokenCapacity2 = 0x10;
      }
      else {
        tokenCapacity2 = tokenCapacity2 << 1;
      }
      for (; tokenCapacity2 < tokenCount + 5U; tokenCapacity2 = tokenCapacity2 << 1) {
      }
      if ((void *)*tokenDataPtrAddr == (void *)0x0) {
        allocation = _malloc(tokenCapacity2 << 2);
      }
      else {
        allocation = _realloc((void *)*tokenDataPtrAddr,tokenCapacity2 << 2);
      }
      if (allocation == (void *)0x0) {
        if (translator[9] != 0) {
          return translator[9];
        }
        translator[9] = 1;
        return 1;
      }
      *tokenDataPtrAddr = (int)allocation;
      translator[0xc] = tokenCapacity2;
      tokenCount = translator[0xb];
    }
    translator[0xb] = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    tokenWritePtr[3] = ilInstr[3];
    tokenWritePtr[4] = ilInstr[6];
    translatorError = translator[9];
  }
  return translatorError;
}

/* fragmentTranslateScalarMathBody @ 0x40374 (1800 bytes) */
int fragmentTranslateScalarMathBody(translator, slot, ilInstr, unusedArg4, unusedArg5, unusedArg6, unusedArg7, unusedArg8)
  int *translator;
  int slot;
  undefined4 *ilInstr;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
{
  uint negate3;
  uint negate2;
  uint select2;
  uint select1;
  uint select3;
  uint tokenCapacity2;
  uint tokenCapacity;
  int translatorError;
  int tokenCount;
  int allocation;
  undefined4 *tokenWritePtr;
  uint negate0;
  int tempRegister;
  uint negate1;
  undefined4 unaff_r21;
  undefined4 unaff_r22;
  uint componentCount;
  uint *dstMaskPtr;
  uint *swizzlePtr;
  uint srcSwizzleWord;
  int *tokenDataPtrAddr;
  
  componentCount = 1;
  if ((translator[5] & 0x20000000U) != 0) {
    componentCount = (*(uint *)(slot * 8 + *translator + *(int *)(*translator + 0x54) * 8 + 4) >> 0x1a & 3) + 1;
  }
  srcSwizzleWord = ilInstr[6];
  if (1 < componentCount) {
    tempRegister = translator[8];
    unaff_r22 = ilInstr[1];
    unaff_r21 = ilInstr[2];
    ilInstr[1] = 0x40000;
    *(short *)((int)ilInstr + 6) = (short)tempRegister;
    ilInstr[2] = 0x55;
    ilInstr[1] = ilInstr[1] | 0x400000;
  }
  negate0 = srcSwizzleWord >> 3 & 1;
  swizzlePtr = ilInstr + 6;
  ilInstr[6] = negate0 << 0xf |
               (srcSwizzleWord & 7) << 0xc |
               negate0 << 0xb |
               (srcSwizzleWord & 7) << 8 | negate0 << 7 | (srcSwizzleWord & 7) << 4 | negate0 << 3 | srcSwizzleWord & 0xffff0007;
  if (translator[9] == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 5U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (translator[9] == 0) {
          translator[9] = 1;
        }
        goto checkComponentCount;
      }
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    translator[0xb] = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    tokenWritePtr[3] = ilInstr[3];
    tokenWritePtr[4] = ilInstr[6];
  }
checkComponentCount:
  if (1 >= componentCount) {
    return translator[9];
  }
  select1 = srcSwizzleWord >> 4 & 7;
  negate1 = srcSwizzleWord >> 7 & 1;
  dstMaskPtr = ilInstr + 2;
  ilInstr[2] = ilInstr[2] & 0xfffffffc;
  *swizzlePtr = negate1 << 0xf |
            select1 << 0xc |
            negate1 << 0xb |
            select1 << 8 | negate1 << 7 | select1 << 4 | negate1 << 3 | select1 | *swizzlePtr & 0xffff0000;
  if (translator[9] == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 5U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (translator[9] == 0) {
          translator[9] = 1;
        }
        goto checkComponentCount2;
      }
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    translator[0xb] = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    tokenWritePtr[3] = ilInstr[3];
    tokenWritePtr[4] = ilInstr[6];
  }
checkComponentCount2:
  if (componentCount < 3) goto setTempRegister;
  select2 = srcSwizzleWord >> 8 & 7;
  negate2 = srcSwizzleWord >> 0xb & 1;
  *dstMaskPtr = *dstMaskPtr & 0xfffffff3;
  *swizzlePtr = negate2 << 0xf |
            select2 << 0xc |
            negate2 << 0xb |
            select2 << 8 | negate2 << 7 | select2 << 4 | negate2 << 3 | select2 | *swizzlePtr & 0xffff0000;
  if (translator[9] == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 5U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (translator[9] == 0) {
          translator[9] = 1;
        }
        goto checkComponentCount3;
      }
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    translator[0xb] = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    tokenWritePtr[3] = ilInstr[3];
    tokenWritePtr[4] = ilInstr[6];
  }
checkComponentCount3:
  if (componentCount == 4) {
    select3 = srcSwizzleWord >> 0xc & 7;
    negate3 = srcSwizzleWord >> 0xf & 1;
    *dstMaskPtr = *dstMaskPtr & 0xffffffcf;
    *swizzlePtr = negate3 << 0xf |
              select3 << 0xc |
              negate3 << 0xb |
              select3 << 8 | negate3 << 7 | select3 << 4 | negate3 << 3 | select3 | *swizzlePtr & 0xffff0000;
    if (translator[9] == 0) {
      tokenDataPtrAddr = translator + 10;
      tokenCount = translator[0xb];
      tokenCapacity2 = translator[0xc];
      if (tokenCapacity2 < tokenCount + 5U) {
        if (tokenCapacity2 == 0) {
          tokenCapacity2 = 0x10;
        }
        else {
          tokenCapacity2 = tokenCapacity2 << 1;
        }
        for (; tokenCapacity2 < tokenCount + 5U; tokenCapacity2 = tokenCapacity2 << 1) {
        }
        if (*tokenDataPtrAddr == 0) {
          allocation = _malloc(tokenCapacity2 << 2);
        }
        else {
          allocation = _realloc(*tokenDataPtrAddr,tokenCapacity2 << 2);
        }
        if (allocation == 0) {
          if (translator[9] == 0) {
            translator[9] = 1;
          }
          goto setTempRegister;
        }
        *tokenDataPtrAddr = allocation;
        translator[0xc] = tokenCapacity2;
        tokenCount = translator[0xb];
      }
      translator[0xb] = tokenCount + 5;
      tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
      *tokenWritePtr = *ilInstr;
      tokenWritePtr[1] = ilInstr[1];
      tokenWritePtr[2] = ilInstr[2];
      tokenWritePtr[3] = ilInstr[3];
      tokenWritePtr[4] = ilInstr[6];
    }
  }
setTempRegister:
  tempRegister = translator[8];
  ilInstr[3] = 0;
  *swizzlePtr = 0;
  ilInstr[3] = ilInstr[3] & 0xffc0ffff | 0x40000;
  *(short *)((int)ilInstr + 0xe) = (short)tempRegister;
  ilInstr[3] = ilInstr[3] | 0x400000;
  *swizzlePtr = *swizzlePtr & 0xffff0000 | 0x3210;
  *ilInstr = 0;
  ilInstr[1] = unaff_r22;
  ilInstr[2] = unaff_r21;
  *(undefined2 *)((int)ilInstr + 2) = 0x47;
  translatorError = translator[9];
  if (translatorError == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity2 = translator[0xc];
    if (tokenCapacity2 < tokenCount + 5U) {
      if (tokenCapacity2 == 0) {
        tokenCapacity2 = 0x10;
      }
      else {
        tokenCapacity2 = tokenCapacity2 << 1;
      }
      for (; tokenCapacity2 < tokenCount + 5U; tokenCapacity2 = tokenCapacity2 << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity2 << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity2 << 2);
      }
      if (allocation == 0) {
        if (translator[9] != 0) {
          return translator[9];
        }
        translator[9] = 1;
        return 1;
      }
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity2;
      tokenCount = translator[0xb];
    }
    translator[0xb] = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    tokenWritePtr[3] = ilInstr[3];
    tokenWritePtr[4] = ilInstr[6];
    translatorError = translator[9];
  }
  return translatorError;
}

/* fragmentTranslateScalarMath2Src @ 0x40ac4 (2096 bytes) */
int fragmentTranslateScalarMath2Src(translator, slot, ilInstr, unusedArg4, unusedArg5, unusedArg6, unusedArg7, unusedArg8)
  int *translator;
  int slot;
  undefined4 *ilInstr;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
{
  uint src1SelectComp3;
  uint src1NegateComp3;
  uint src0NegateComp2;
  uint src1SelectComp2;
  uint src0NegateComp3;
  uint src0SelectComp2;
  uint src0SelectComp1;
  uint src0SelectComp3;
  uint src1NegateComp2;
  uint src1NegateComp1;
  uint tokenCapacity2;
  uint tokenCapacity;
  int translatorError;
  int tokenCount;
  int allocation;
  undefined4 *recordSwzNext;
  bool moreSources;
  int srcIndex;
  uint src0NegateComp0;
  uint src1SelectComp1;
  undefined4 *recordPtr;
  int tempRegister;
  uint src1NegateComp0;
  uint src0NegateComp1;
  undefined4 *tokenWritePtr;
  undefined4 unaff_r19;
  undefined4 unaff_r20;
  uint repeatCount;
  uint *dstMaskPtr;
  uint *srcSwizzle1Ptr;
  uint *srcSwizzle0Ptr;
  uint srcSwizzle1;
  uint srcSwizzle0;
  int *tokenDataPtrAddr;
  
  repeatCount = 1;
  if ((translator[5] & 0x20000000U) != 0) {
    repeatCount = (*(uint *)(slot * 8 + *translator + *(int *)(*translator + 0x54) * 8 + 4) >> 0x1a & 3) + 1
    ;
  }
  srcSwizzle0 = ilInstr[6];
  srcSwizzle1 = ilInstr[7];
  if (repeatCount >= 2) {
    tempRegister = translator[8];
    unaff_r20 = ilInstr[1];
    unaff_r19 = ilInstr[2];
    ilInstr[1] = 0x40000;
    *(short *)((int)ilInstr + 6) = (short)tempRegister;
    ilInstr[2] = 0x55;
    ilInstr[1] = ilInstr[1] | 0x400000;
  }
  src0NegateComp0 = srcSwizzle0 >> 3 & 1;
  src1NegateComp0 = srcSwizzle1 >> 3 & 1;
  srcSwizzle0Ptr = ilInstr + 6;
  srcSwizzle1Ptr = ilInstr + 7;
  ilInstr[6] = src0NegateComp0 << 0xf |
               (srcSwizzle0 & 7) << 0xc |
               src0NegateComp0 << 0xb |
               (srcSwizzle0 & 7) << 8 | src0NegateComp0 << 7 | (srcSwizzle0 & 7) << 4 | src0NegateComp0 << 3 | srcSwizzle0 & 0xffff0007
  ;
  ilInstr[7] = src1NegateComp0 << 0xf |
               (srcSwizzle1 & 7) << 0xc |
               src1NegateComp0 << 0xb |
               (srcSwizzle1 & 7) << 8 | src1NegateComp0 << 7 | (srcSwizzle1 & 7) << 4 | src1NegateComp0 << 3 | srcSwizzle1 & 0xffff0007
  ;
  if (translator[9] == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (translator[9] == 0) {
          translator[9] = 1;
        }
        goto checkRepeatCount;
      }
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    srcIndex = 0;
    translator[0xb] = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    recordPtr = ilInstr;
    do {
      moreSources = srcIndex != 1;
      srcIndex = srcIndex + 1;
      tokenWritePtr[3] = recordPtr[3];
      recordSwzNext = recordPtr + 6;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordSwzNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (moreSources);
  }
checkRepeatCount:
  if (repeatCount < 2) {
    return translator[9];
  }
  src0SelectComp1 = srcSwizzle0 >> 4 & 7;
  src0NegateComp1 = srcSwizzle0 >> 7 & 1;
  src1SelectComp1 = srcSwizzle1 >> 4 & 7;
  src1NegateComp1 = srcSwizzle1 >> 7 & 1;
  dstMaskPtr = ilInstr + 2;
  ilInstr[2] = ilInstr[2] & 0xfffffffc;
  *srcSwizzle0Ptr = src0NegateComp1 << 0xf |
             src0SelectComp1 << 0xc |
             src0NegateComp1 << 0xb |
             src0SelectComp1 << 8 | src0NegateComp1 << 7 | src0SelectComp1 << 4 | src0NegateComp1 << 3 | src0SelectComp1 | *srcSwizzle0Ptr & 0xffff0000;
  *srcSwizzle1Ptr = src1NegateComp1 << 0xf |
             src1SelectComp1 << 0xc |
             src1NegateComp1 << 0xb |
             src1SelectComp1 << 8 | src1NegateComp1 << 7 | src1SelectComp1 << 4 | src1NegateComp1 << 3 | src1SelectComp1 | *srcSwizzle1Ptr & 0xffff0000;
  if (translator[9] == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (translator[9] == 0) {
          translator[9] = 1;
        }
        goto checkRepeatCount2;
      }
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    srcIndex = 0;
    translator[0xb] = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    recordPtr = ilInstr;
    do {
      moreSources = srcIndex != 1;
      srcIndex = srcIndex + 1;
      tokenWritePtr[3] = recordPtr[3];
      recordSwzNext = recordPtr + 6;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordSwzNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (moreSources);
  }
checkRepeatCount2:
  if (repeatCount < 3) goto setTempRegister;
  src0SelectComp2 = srcSwizzle0 >> 8 & 7;
  src0NegateComp2 = srcSwizzle0 >> 0xb & 1;
  src1SelectComp2 = srcSwizzle1 >> 8 & 7;
  src1NegateComp2 = srcSwizzle1 >> 0xb & 1;
  *dstMaskPtr = *dstMaskPtr & 0xfffffff3;
  *srcSwizzle0Ptr = src0NegateComp2 << 0xf |
             src0SelectComp2 << 0xc |
             src0NegateComp2 << 0xb |
             src0SelectComp2 << 8 | src0NegateComp2 << 7 | src0SelectComp2 << 4 | src0NegateComp2 << 3 | src0SelectComp2 | *srcSwizzle0Ptr & 0xffff0000;
  *srcSwizzle1Ptr = src1NegateComp2 << 0xf |
             src1SelectComp2 << 0xc |
             src1NegateComp2 << 0xb |
             src1SelectComp2 << 8 | src1NegateComp2 << 7 | src1SelectComp2 << 4 | src1NegateComp2 << 3 | src1SelectComp2 | *srcSwizzle1Ptr & 0xffff0000;
  if (translator[9] == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (translator[9] == 0) {
          translator[9] = 1;
        }
        goto checkRepeatCount3;
      }
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    srcIndex = 0;
    translator[0xb] = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    recordPtr = ilInstr;
    do {
      moreSources = srcIndex != 1;
      srcIndex = srcIndex + 1;
      tokenWritePtr[3] = recordPtr[3];
      recordSwzNext = recordPtr + 6;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordSwzNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (moreSources);
  }
checkRepeatCount3:
  if (repeatCount == 4) {
    src0SelectComp3 = srcSwizzle0 >> 0xc & 7;
    src0NegateComp3 = srcSwizzle0 >> 0xf & 1;
    src1SelectComp3 = srcSwizzle1 >> 0xc & 7;
    src1NegateComp3 = srcSwizzle1 >> 0xf & 1;
    *dstMaskPtr = *dstMaskPtr & 0xffffffcf;
    *srcSwizzle0Ptr = src0NegateComp3 << 0xf |
               src0SelectComp3 << 0xc |
               src0NegateComp3 << 0xb |
               src0SelectComp3 << 8 | src0NegateComp3 << 7 | src0SelectComp3 << 4 | src0NegateComp3 << 3 | src0SelectComp3 | *srcSwizzle0Ptr & 0xffff0000;
    *srcSwizzle1Ptr = src1NegateComp3 << 0xf |
               src1SelectComp3 << 0xc |
               src1NegateComp3 << 0xb |
               src1SelectComp3 << 8 |
               src1NegateComp3 << 7 | src1SelectComp3 << 4 | src1NegateComp3 << 3 | src1SelectComp3 | *srcSwizzle1Ptr & 0xffff0000;
    if (translator[9] == 0) {
      tokenDataPtrAddr = translator + 10;
      tokenCount = translator[0xb];
      tokenCapacity2 = translator[0xc];
      if (tokenCapacity2 < tokenCount + 7U) {
        if (tokenCapacity2 == 0) {
          tokenCapacity2 = 0x10;
        }
        else {
          tokenCapacity2 = tokenCapacity2 << 1;
        }
        for (; tokenCapacity2 < tokenCount + 7U; tokenCapacity2 = tokenCapacity2 << 1) {
        }
        if (*tokenDataPtrAddr == 0) {
          allocation = _malloc(tokenCapacity2 << 2);
        }
        else {
          allocation = _realloc(*tokenDataPtrAddr,tokenCapacity2 << 2);
        }
        if (allocation == 0) {
          if (translator[9] == 0) {
            translator[9] = 1;
          }
          goto setTempRegister;
        }
        *tokenDataPtrAddr = allocation;
        translator[0xc] = tokenCapacity2;
        tokenCount = translator[0xb];
      }
      srcIndex = 0;
      translator[0xb] = tokenCount + 7;
      tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
      *tokenWritePtr = *ilInstr;
      tokenWritePtr[1] = ilInstr[1];
      tokenWritePtr[2] = ilInstr[2];
      recordPtr = ilInstr;
      do {
        moreSources = srcIndex != 1;
        srcIndex = srcIndex + 1;
        tokenWritePtr[3] = recordPtr[3];
        recordSwzNext = recordPtr + 6;
        recordPtr = recordPtr + 1;
        tokenWritePtr[4] = *recordSwzNext;
        tokenWritePtr = tokenWritePtr + 2;
      } while (moreSources);
    }
  }
setTempRegister:
  tempRegister = translator[8];
  ilInstr[3] = 0;
  *srcSwizzle0Ptr = 0;
  ilInstr[3] = ilInstr[3] & 0xffc0ffff | 0x40000;
  *(short *)((int)ilInstr + 0xe) = (short)tempRegister;
  ilInstr[3] = ilInstr[3] | 0x400000;
  *srcSwizzle0Ptr = *srcSwizzle0Ptr & 0xffff0000 | 0x3210;
  *ilInstr = 0;
  ilInstr[1] = unaff_r20;
  ilInstr[2] = unaff_r19;
  *(undefined2 *)((int)ilInstr + 2) = 0x47;
  translatorError = translator[9];
  if (translatorError == 0) {
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity2 = translator[0xc];
    if (tokenCapacity2 < tokenCount + 5U) {
      if (tokenCapacity2 == 0) {
        tokenCapacity2 = 0x10;
      }
      else {
        tokenCapacity2 = tokenCapacity2 << 1;
      }
      for (; tokenCapacity2 < tokenCount + 5U; tokenCapacity2 = tokenCapacity2 << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity2 << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity2 << 2);
      }
      if (allocation == 0) {
        if (translator[9] != 0) {
          return translator[9];
        }
        translator[9] = 1;
        return 1;
      }
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity2;
      tokenCount = translator[0xb];
    }
    translator[0xb] = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    tokenWritePtr[3] = ilInstr[3];
    tokenWritePtr[4] = ilInstr[6];
    translatorError = translator[9];
  }
  return translatorError;
}

/* fragmentTranslateTrig @ 0x41310 (488 bytes) */
int fragmentTranslateTrig(translator, slot, ilInstr)
  int translator;
  undefined4 slot;
  int ilInstr;
{
  int allocation;
  undefined4 *tokenWritePtr;
  undefined2 tempRegisterHalf;
  uint tokenCapacity;
  int tokenCount;
  undefined4 tempRegister;
  int *tokenDataPtrAddr;
  undefined4 ilInstOpcode;
  undefined4 ilInstDst;
  undefined4 ilInstDstMask;
  undefined4 ilInstSrc0;
  undefined4 ilInstSwz0;
  
  _memcpy(&ilInstOpcode,ilInstr,0x24);
  tempRegister = *(undefined4 *)(translator + 0x20);
  *(undefined4 *)(ilInstr + 0x18) = 0;
  tempRegisterHalf = (undefined2)tempRegister;
  *(undefined4 *)(ilInstr + 0xc) = 0x40000;
  *(undefined2 *)(ilInstr + 0xe) = tempRegisterHalf;
  ilInstDstMask = 0x55;
  ilInstDst = CONCAT22(4,tempRegisterHalf);
  ilInstOpcode = 0x4d;
  *(uint *)(ilInstr + 0x18) = *(uint *)(ilInstr + 0x18) & 0xffff0000 | 0x3210;
  *(uint *)(ilInstr + 0xc) = *(uint *)(ilInstr + 0xc) | 0x400000;
  ilInstDst = ilInstDst | 0x400000;
  if (*(int *)(translator + 0x24) == 0) {
    tokenDataPtrAddr = (int *)(translator + 0x28);
    tokenCount = *(int *)(translator + 0x2c);
    tokenCapacity = *(uint *)(translator + 0x30);
    if (tokenCapacity < tokenCount + 5U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (*(int *)(translator + 0x24) == 0) {
          *(undefined4 *)(translator + 0x24) = 1;
        }
        goto storeTranslator;
      }
      *tokenDataPtrAddr = allocation;
      *(uint *)(translator + 0x30) = tokenCapacity;
      tokenCount = *(int *)(translator + 0x2c);
    }
    *(int *)(translator + 0x2c) = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = ilInstOpcode;
    tokenWritePtr[1] = ilInstDst;
    tokenWritePtr[2] = ilInstDstMask;
    tokenWritePtr[3] = ilInstSrc0;
    tokenWritePtr[4] = ilInstSwz0;
  }
storeTranslator:
  *(int *)(translator + 0x20) = *(int *)(translator + 0x20) + 1;
  ((int (*)())fragmentTranslateScalarMath)(translator,slot,ilInstr);
  *(int *)(translator + 0x20) = *(int *)(translator + 0x20) + -1;
  return *(undefined4 *)(translator + 0x24);
}

/* fragmentTranslateAngleConvert @ 0x41510 (548 bytes) */
int fragmentTranslateAngleConvert(emitter, slot, entryHeader, srcRegWord1, unusedArg5, unusedArg6, unusedArg7)
  int *emitter;
  int slot;
  undefined4 *entryHeader;
  undefined4 srcRegWord1;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  uint tokenCapacity;
  int translatorError;
  int tokenCount;
  int allocation;
  undefined4 *srcSwizzlePtr;
  bool morePairs;
  int opRecordOffset;
  int srcPairIndex;
  undefined4 *tokenWritePtr;
  dword *tokenWord1Ptr;
  dword *tokenWord2Ptr;
  undefined4 tempRegister;
  int *tokenDataPtrAddr;
  uint opWord;
  
  opRecordOffset = (slot + *(int *)(*emitter + 0x54)) * 8;
  opWord = *(uint *)(opRecordOffset + *emitter);
  ((int (*)())fpilEmitAngleConstants)(emitter,opRecordOffset,entryHeader,srcRegWord1,unusedArg5,unusedArg6,unusedArg7);
  tempRegister = *(undefined4 *)(*emitter + 0x28);
  entryHeader[7] = 0;
  entryHeader[4] = 0x10000;
  *(short *)((int)entryHeader + 0x12) = (short)tempRegister;
  opWord = *(uint *)(&UNK_001aa574 + (2 - ((int)-(opWord & 0x3fc0000 ^ 0x580000) >> 0x1f)) * 4);
  entryHeader[4] = entryHeader[4] | 0x400000;
  entryHeader[7] = (opWord & 7) << 0xc |
               (opWord & 7) << 8 | (opWord & 7) << 4 | opWord & 7 | entryHeader[7] & 0xffff0000;
  if (emitter[9] != 0) {
    return emitter[9];
  }
  tokenDataPtrAddr = emitter + 10;
  tokenCount = emitter[0xb];
  tokenCapacity = emitter[0xc];
  if (tokenCapacity < tokenCount + 7U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
      translatorError = emitter[9];
      if (translatorError == 0) {
        translatorError = 1;
        emitter[9] = 1;
      }
      if (translatorError != 0) {
        return translatorError;
      }
      tokenWritePtr = (undefined4 *)0x0;
      tokenWord1Ptr = ((unsigned char *)0x4);
      tokenWord2Ptr = ((unsigned char *)0x8);
      goto setSrcPairIndex;
    }
    *tokenDataPtrAddr = allocation;
    emitter[0xc] = tokenCapacity;
    tokenCount = emitter[0xb];
  }
  emitter[0xb] = tokenCount + 7;
  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
  tokenWord1Ptr = tokenWritePtr + 1;
  tokenWord2Ptr = tokenWritePtr + 2;
setSrcPairIndex:
  srcPairIndex = 0;
  *tokenWritePtr = *entryHeader;
  *tokenWord1Ptr = entryHeader[1];
  *tokenWord2Ptr = entryHeader[2];
  do {
    morePairs = srcPairIndex != 1;
    srcPairIndex = srcPairIndex + 1;
    tokenWritePtr[3] = entryHeader[3];
    srcSwizzlePtr = entryHeader + 6;
    entryHeader = entryHeader + 1;
    tokenWritePtr[4] = *srcSwizzlePtr;
    tokenWritePtr = tokenWritePtr + 2;
  } while (morePairs);
  return 0;
}

/* fragmentTranslateMod @ 0x41750 (1160 bytes) */
int fragmentTranslateMod(translator, slot, ilInstr)
  int translator;
  undefined4 slot;
  int ilInstr;
{
  uint tokenCapacity;
  int allocation;
  int tokenCount;
  undefined4 *tokenWritePtr;
  undefined4 *recordWordNext;
  undefined **recordWordNext2;
  uint srcSwizzleWord;
  undefined4 *tokenWritePtrB;
  undefined2 tempRegisterHalf;
  dword *tokenWord1Ptr;
  int translatorError;
  undefined4 *recordPtr;
  dword *tokenWord2Ptr;
  undefined **recordPtr2;
  int *tokenDataPtrAddr;
  undefined4 ilInstAOpcode;
  undefined4 ilInstADst;
  dword ilInstADstMask;
  undefined4 ilInstASrc0;
  undefined4 ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *ilInstASwz0;
  uint ilInstASwz1;
  undefined4 ilInstASwz2;
  
  _memset(&ilInstAOpcode,0,0x24);
  translatorError = *(int *)(translator + 0x24);
  tempRegisterHalf = (undefined2)*(undefined4 *)(translator + 0x20);
  ilInstADst = CONCAT22(4,tempRegisterHalf);
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x20);
  ilInstADstMask = 0x55;
  ilInstASrc0 = *(undefined **)(ilInstr + 0xc);
  ilInstASwz0 = *(undefined **)(ilInstr + 0x18);
  ilInstASrc1 = *(undefined4 *)(ilInstr + 0x10);
  ilInstASwz1 = *(undefined4 *)(ilInstr + 0x1c);
  ilInstADst = ilInstADst | 0x400000;
  if (translatorError == 0) {
    tokenDataPtrAddr = (int *)(translator + 0x28);
    tokenCount = *(int *)(translator + 0x2c);
    tokenCapacity = *(uint *)(translator + 0x30);
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        translatorError = *(int *)(translator + 0x24);
        if (translatorError == 0) {
          translatorError = 1;
          *(undefined4 *)(translator + 0x24) = 1;
        }
        tempRegisterHalf = (undefined2)*(undefined4 *)(translator + 0x20);
        goto setIlInstASrc0;
      }
      *tokenDataPtrAddr = allocation;
      *(uint *)(translator + 0x30) = tokenCapacity;
      tokenCount = *(int *)(translator + 0x2c);
    }
    recordPtr = &ilInstASrc0;
    *(int *)(translator + 0x2c) = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = ilInstAOpcode;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr;
      recordWordNext = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordWordNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (&ilInstASrc2 != recordPtr);
    tempRegisterHalf = (undefined2)*(undefined4 *)(translator + 0x20);
    translatorError = *(int *)(translator + 0x24);
  }
setIlInstASrc0:
  ilInstASrc0 = (undefined *)CONCAT22(4,tempRegisterHalf);
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x30);
  ilInstASwz0 = ((unsigned char *)0x00003210);
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  if (translatorError == 0) {
    tokenDataPtrAddr = (int *)(translator + 0x28);
    tokenCount = *(int *)(translator + 0x2c);
    tokenCapacity = *(uint *)(translator + 0x30);
    if (tokenCapacity < tokenCount + 5U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        translatorError = *(int *)(translator + 0x24);
        if (translatorError == 0) {
          translatorError = 1;
          *(undefined4 *)(translator + 0x24) = 1;
        }
        goto setSrcSwizzleWord;
      }
      *tokenDataPtrAddr = allocation;
      *(uint *)(translator + 0x30) = tokenCapacity;
      tokenCount = *(int *)(translator + 0x2c);
    }
    *(int *)(translator + 0x2c) = tokenCount + 5;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = ilInstAOpcode;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    tokenWritePtr[3] = ilInstASrc0;
    tokenWritePtr[4] = ilInstASwz0;
    translatorError = *(int *)(translator + 0x24);
  }
setSrcSwizzleWord:
  srcSwizzleWord = *(uint *)(ilInstr + 0x1c);
  ilInstADstMask = *(dword *)(ilInstr + 8);
  ilInstADst = *(dword *)(ilInstr + 4);
  ilInstASrc1 = *(undefined4 *)(ilInstr + 0x10);
  ilInstASrc2 = *(undefined4 *)(ilInstr + 0xc);
  ilInstASwz2 = *(undefined4 *)(ilInstr + 0x18);
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x40);
  ilInstASwz1 = (srcSwizzleWord & 0xfffff777 ^ 0x8000) & 0x8000 |
              (srcSwizzleWord & 0xffffff77 ^ 0x800) & 0x800 |
              (srcSwizzleWord & 0xfffffff7 ^ 0x80) & 0x80 | (srcSwizzleWord ^ 8) & 8 | srcSwizzleWord & 0xffff7777;
  if (translatorError != 0) {
    return translatorError;
  }
  tokenDataPtrAddr = (int *)(translator + 0x28);
  tokenCount = *(int *)(translator + 0x2c);
  tokenCapacity = *(uint *)(translator + 0x30);
  if (tokenCapacity < tokenCount + 9U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 9U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
      translatorError = *(int *)(translator + 0x24);
      if (translatorError == 0) {
        translatorError = 1;
        *(undefined4 *)(translator + 0x24) = 1;
      }
      if (translatorError != 0) {
        return translatorError;
      }
      tokenWritePtrB = (undefined4 *)0x0;
      tokenWord1Ptr = ((unsigned char *)0x4);
      tokenWord2Ptr = ((unsigned char *)0x8);
      goto setRecordPtr2;
    }
    *tokenDataPtrAddr = allocation;
    *(uint *)(translator + 0x30) = tokenCapacity;
    tokenCount = *(int *)(translator + 0x2c);
  }
  *(int *)(translator + 0x2c) = tokenCount + 9;
  tokenWritePtrB = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
  tokenWord1Ptr = tokenWritePtrB + 1;
  tokenWord2Ptr = tokenWritePtrB + 2;
setRecordPtr2:
  recordPtr2 = (undefined **)&ilInstASrc0;
  *tokenWritePtrB = ilInstAOpcode;
  *tokenWord1Ptr = ilInstADst;
  *tokenWord2Ptr = ilInstADstMask;
  do {
    tokenWritePtrB[3] = *recordPtr2;
    recordWordNext2 = recordPtr2 + 3;
    recordPtr2 = recordPtr2 + 1;
    tokenWritePtrB[4] = *recordWordNext2;
    tokenWritePtrB = tokenWritePtrB + 2;
  } while (&ilInstASwz0 != recordPtr2);
  return 0;
}

/* fragmentTranslateAtn @ 0x41c00 (4544 bytes) */
int fragmentTranslateAtn(emitter, slot, instr)
  int *emitter;
  int slot;
  int instr;
{
  uint tokenCapacity;
  uint *tokenWritePtr;
  uint *recordPtr4;
  undefined **recordPtr3;
  undefined **recordPtr;
  undefined4 *recordWordNext;
  uint *recordWordNext2;
  undefined **recordWordNext3;
  undefined *swz0Saved;
  uint capacity;
  int bufferCount;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 staleArgR4;
  uint srcRegWord1;
  undefined *ilInstASrc0OrStaleR7;
  char *srcCursorOrStaleR8;
  undefined **swzCursorOrStaleR8;
  undefined4 dstMaskOrStaleR9;
  uint *tokenCountOrWritePtr;
  short tempRegisterHalf;
  undefined4 *recordPtr2;
  undefined **recordWordNext4;
  uint *srcCopyCursor;
  undefined4 *tokenWritePtr2;
  int tempRegister;
  int *bufferDataPtr;
  undefined4 entryHeader;
  undefined4 ilInstADst;
  uint ilInstADstMask;
  undefined4 ilInstASrc0;
  undefined4 ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *ilInstASwzArray [11];
  
  if ((*(uint *)((slot + *(int *)(*emitter + 0x54)) * 8 + *emitter) & 0xe0000000) == 0x20000000)
  {
    *(undefined4 *)(instr + 0x10) = 0x40000;
    *(undefined2 *)(instr + 0x12) = 0;
    *(undefined **)(instr + 0x1c) = ((unsigned char *)0x00005555);
    *(uint *)(instr + 0x10) = *(uint *)(instr + 0x10) | 0x400000;
  }
  _memset(&entryHeader,0,0x24);
  tempRegister = emitter[8];
  bufferCount = emitter[9];
  ilInstADst = CONCAT22(4,(short)tempRegister);
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x5b);
  srcRegWord1 = *(uint *)(instr + 0x10);
  ilInstADstMask = 0x55;
  ilInstASwzArray[0] = (undefined *)(*(uint *)(instr + 0x18) & 0xffff7777 | 0x100000);
  ilInstASwzArray[1] = (undefined *)(*(uint *)(instr + 0x1c) & 0xffff7777 | 0x100000);
  ilInstASrc0 = *(undefined **)(instr + 0xc);
  ilInstASrc1 = (undefined *)srcRegWord1;
  ilInstADst = ilInstADst | 0x400000;
  if (bufferCount == 0) {
    bufferDataPtr = emitter + 10;
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 7U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = emitter[9];
        if (bufferCount == 0) {
          bufferCount = 1;
          emitter[9] = 1;
        }
        tempRegister = emitter[8];
        goto setSwz0Saved;
      }
      *bufferDataPtr = bufferCount;
      emitter[0xc] = capacity;
      bufferCount = emitter[0xb];
    }
    recordPtr2 = &ilInstASrc0;
    emitter[0xb] = bufferCount + 7;
    tokenWritePtr2 = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr2 = entryHeader;
    tokenWritePtr2[1] = ilInstADst;
    tokenWritePtr2[2] = ilInstADstMask;
    do {
      tokenWritePtr2[3] = *recordPtr2;
      recordWordNext = recordPtr2 + 3;
      recordPtr2 = recordPtr2 + 1;
      tokenWritePtr2[4] = *recordWordNext;
      tokenWritePtr2 = tokenWritePtr2 + 2;
    } while (&ilInstASrc2 != recordPtr2);
    tempRegister = emitter[8];
    bufferCount = emitter[9];
  }
setSwz0Saved:
  swz0Saved = ilInstASwzArray[0];
  ilInstASrc2 = (uint *)ilInstASrc1;
  ilInstASrc0OrStaleR7 = ilInstASrc0;
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0xd);
  ilInstADst = CONCAT22(4,(short)tempRegister + 1);
  ilInstASrc0 = (undefined *)CONCAT22(4,(short)tempRegister);
  ilInstASrc1 = ilInstASrc0OrStaleR7;
  ilInstADstMask = 0x55;
  ilInstASwzArray[2] = ilInstASwzArray[1];
  ilInstASwzArray[0] = ((unsigned char *)0x00003210);
  ilInstASwzArray[1] = swz0Saved;
  entryHeader = entryHeader & 0xc000ffff | 0x30000;
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  if (bufferCount == 0) {
    bufferDataPtr = emitter + 10;
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = emitter[9];
        if (bufferCount == 0) {
          bufferCount = 1;
          emitter[9] = 1;
        }
        tempRegister = emitter[8];
        goto setIlInstASrc0;
      }
      *bufferDataPtr = bufferCount;
      emitter[0xc] = capacity;
      bufferCount = emitter[0xb];
    }
    recordPtr = (undefined **)&ilInstASrc0;
    emitter[0xb] = bufferCount + 9;
    tokenWritePtr = (uint *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = (uint)*recordPtr;
      recordWordNext4 = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = (uint)*recordWordNext4;
      tokenWritePtr = tokenWritePtr + 2;
    } while (ilInstASwzArray != recordPtr);
    tempRegister = emitter[8];
    bufferCount = emitter[9];
  }
setIlInstASrc0:
  ilInstASrc0 = (undefined *)CONCAT22(4,(short)tempRegister);
  ilInstADst = CONCAT22(4,(short)tempRegister + 2);
  entryHeader = entryHeader & 0xc000ffff | 0x40000;
  ilInstADstMask = 0x55;
  ilInstASwzArray[0] = ((unsigned char *)0x00003210);
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  if (bufferCount == 0) {
    bufferDataPtr = emitter + 10;
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = emitter[9];
        if (bufferCount == 0) {
          bufferCount = 1;
          emitter[9] = 1;
        }
        tempRegister = emitter[8];
        goto setTempRegisterHalf;
      }
      *bufferDataPtr = bufferCount;
      emitter[0xc] = capacity;
      bufferCount = emitter[0xb];
    }
    recordPtr = (undefined **)&ilInstASrc0;
    emitter[0xb] = bufferCount + 9;
    tokenWritePtr = (uint *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = (uint)*recordPtr;
      recordWordNext4 = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = (uint)*recordWordNext4;
      tokenWritePtr = tokenWritePtr + 2;
    } while (ilInstASwzArray != recordPtr);
    tempRegister = emitter[8];
    bufferCount = emitter[9];
  }
setTempRegisterHalf:
  tempRegisterHalf = (short)tempRegister + 1;
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x20);
  ilInstASrc0 = (undefined *)CONCAT22(4,(short)tempRegister + 2);
  ilInstADst = CONCAT22(4,tempRegisterHalf);
  ilInstASrc1 = (undefined *)CONCAT22(4,tempRegisterHalf);
  srcCursorOrStaleR8 = (*(GhidraMachOSection *)0x00000054).sectname + 1;
  ilInstADstMask = 0x55;
  ilInstASwzArray[0] = ((unsigned char *)0x00003210);
  ilInstASwzArray[1] = ((unsigned char *)0x00003210);
  entryHeader = entryHeader & 0xc000ffff;
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  ilInstASrc1 = (undefined *)((uint)ilInstASrc1 | 0x400000);
  if (bufferCount == 0) {
    bufferDataPtr = emitter + 10;
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 7U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount != 0) {
        *bufferDataPtr = bufferCount;
        emitter[0xc] = capacity;
        bufferCount = emitter[0xb];
        goto setRecordPtr4;
      }
      if (emitter[9] == 0) {
        emitter[9] = 1;
      }
    }
    else {
setRecordPtr4:
      recordPtr4 = &ilInstASrc0;
      srcCursorOrStaleR8 = (char *)&ilInstASrc2;
      emitter[0xb] = bufferCount + 7;
      tokenWritePtr = (uint *)(bufferCount * 4 + *bufferDataPtr);
      *tokenWritePtr = entryHeader;
      tokenWritePtr[1] = ilInstADst;
      tokenWritePtr[2] = ilInstADstMask;
      do {
        tokenWritePtr[3] = *recordPtr4;
        recordWordNext2 = recordPtr4 + 3;
        recordPtr4 = recordPtr4 + 1;
        tokenWritePtr[4] = *recordWordNext2;
        tokenWritePtr = tokenWritePtr + 2;
      } while ((uint *)srcCursorOrStaleR8 != recordPtr4);
    }
    tempRegister = emitter[8];
  }
  ilInstASrc0 = (undefined *)CONCAT22(4,(short)tempRegister + 1);
  emitter[8] = tempRegister + 3;
  (*(unsigned short *)((unsigned char *)&(entryHeader) + 2)) = 5;
  dstMaskOrStaleR9 = 0xffff7777;
  ilInstASwzArray[0] = ((unsigned char *)0x00003210);
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  ((int (*)())fragmentTranslateScalarMath)(emitter,slot,&entryHeader);
  staleArgR4 = 0x24;
  emitter[8] = emitter[8] + -3;
  _memset(&entryHeader,0,0x24);
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x5b);
  ((int (*)())fpilEmitAngleConstants)(emitter,extraout_r4,staleArgR4,srcRegWord1,ilInstASrc0OrStaleR7,srcCursorOrStaleR8,dstMaskOrStaleR9);
  tempRegisterHalf = (short)emitter[8];
  ilInstASrc1 = (undefined *)CONCAT22(4,tempRegisterHalf + 1);
  ilInstADst = CONCAT22(4,tempRegisterHalf + 2);
  ilInstASrc0 = (undefined *)CONCAT22(1,(short)*(undefined4 *)(*emitter + 0x28));
  bufferCount = emitter[9];
  ilInstASwzArray[1] = ((unsigned char *)0x00003210);
  ilInstADstMask = 0x55;
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc1 = (undefined *)((uint)ilInstASrc1 | 0x400000);
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  ilInstASwzArray[0] = ((unsigned char *)0x00001111);
  staleArgR4 = extraout_r4_00;
  if (bufferCount == 0) {
    bufferDataPtr = emitter + 10;
    bufferCount = emitter[0xb];
    tokenCapacity = emitter[0xc];
    if (tokenCapacity < bufferCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < bufferCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(tokenCapacity << 2);
        staleArgR4 = extraout_r4_01;
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,tokenCapacity << 2);
        staleArgR4 = extraout_r4_02;
      }
      if (bufferCount == 0) {
        bufferCount = emitter[9];
        if (bufferCount == 0) {
          bufferCount = 1;
          emitter[9] = 1;
        }
        tempRegisterHalf = (short)emitter[8];
        goto setEntryHeader;
      }
      *bufferDataPtr = bufferCount;
      emitter[0xc] = tokenCapacity;
      bufferCount = emitter[0xb];
    }
    recordPtr2 = &ilInstASrc0;
    emitter[0xb] = bufferCount + 7;
    tokenWritePtr2 = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr2 = entryHeader;
    tokenWritePtr2[1] = ilInstADst;
    tokenWritePtr2[2] = ilInstADstMask;
    do {
      tokenWritePtr2[3] = *recordPtr2;
      recordWordNext = recordPtr2 + 3;
      recordPtr2 = recordPtr2 + 1;
      tokenWritePtr2[4] = *recordWordNext;
      tokenWritePtr2 = tokenWritePtr2 + 2;
    } while (&ilInstASrc2 != recordPtr2);
    tempRegisterHalf = (short)emitter[8];
    bufferCount = emitter[9];
  }
setEntryHeader:
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0xd);
  ilInstASrc0 = (undefined *)CONCAT22(4,tempRegisterHalf);
  ilInstASrc1 = (undefined *)CONCAT22(4,tempRegisterHalf + 2);
  ilInstADst = CONCAT22(4,tempRegisterHalf + 1);
  ilInstASrc2 = (uint *)CONCAT22(4,tempRegisterHalf + 1);
  dstMaskOrStaleR9 = 0x55;
  ilInstASrc0OrStaleR7 = ((unsigned char *)0x00003210);
  swzCursorOrStaleR8 = (undefined **)((unsigned char *)0x00003210);
  ilInstADstMask = 0x55;
  ilInstASwzArray[2] = ((unsigned char *)0x00003210);
  ilInstASwzArray[1] = ((unsigned char *)0x00003210);
  ilInstASwzArray[0] = ((unsigned char *)0x00003210);
  entryHeader = entryHeader & 0xc000ffff | 0x30000;
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  ilInstASrc1 = (undefined *)((uint)ilInstASrc1 | 0x400000);
  tokenCountOrWritePtr = (uint *)((uint)ilInstASrc2 | 0x400000);
  ilInstASrc2 = tokenCountOrWritePtr;
  if (bufferCount == 0) {
    bufferDataPtr = emitter + 10;
    tokenCountOrWritePtr = (uint *)emitter[0xb];
    tokenCapacity = emitter[0xc];
    if (tokenCapacity < (int)tokenCountOrWritePtr + 9U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < (int)tokenCountOrWritePtr + 9U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(tokenCapacity << 2);
        staleArgR4 = extraout_r4_03;
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,tokenCapacity << 2);
        staleArgR4 = extraout_r4_04;
      }
      if (bufferCount == 0) {
        if (emitter[9] == 0) {
          emitter[9] = 1;
        }
        goto setEntryHeader2;
      }
      *bufferDataPtr = bufferCount;
      emitter[0xc] = tokenCapacity;
      tokenCountOrWritePtr = (uint *)emitter[0xb];
    }
    recordPtr3 = (undefined **)&ilInstASrc0;
    swzCursorOrStaleR8 = ilInstASwzArray;
    emitter[0xb] = (int)tokenCountOrWritePtr + 9;
    tokenCountOrWritePtr = (uint *)((int)tokenCountOrWritePtr * 4 + *bufferDataPtr);
    *tokenCountOrWritePtr = entryHeader;
    tokenCountOrWritePtr[1] = ilInstADst;
    tokenCountOrWritePtr[2] = ilInstADstMask;
    srcCopyCursor = tokenCountOrWritePtr;
    do {
      srcCopyCursor[3] = (uint)*recordPtr3;
      recordWordNext3 = recordPtr3 + 3;
      recordPtr3 = recordPtr3 + 1;
      srcCopyCursor[4] = (uint)*recordWordNext3;
      srcCopyCursor = srcCopyCursor + 2;
    } while (swzCursorOrStaleR8 != recordPtr3);
  }
setEntryHeader2:
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x5b);
  entryHeader = entryHeader & 0xc000ffff;
  ((int (*)())fpilEmitAngleConstants)(emitter,staleArgR4,entryHeader,dstMaskOrStaleR9,ilInstASrc0OrStaleR7,swzCursorOrStaleR8,tokenCountOrWritePtr);
  tempRegisterHalf = (short)emitter[8];
  ilInstASrc0 = (undefined *)CONCAT22(1,(short)*(undefined4 *)(*emitter + 0x28));
  ilInstADst = CONCAT22(4,tempRegisterHalf + 2);
  ilInstASrc1 = (undefined *)CONCAT22(4,tempRegisterHalf + 1);
  bufferCount = emitter[9];
  ilInstASwzArray[0] = (undefined *)0x0;
  ilInstASwzArray[1] = ((unsigned char *)0x00003210);
  ilInstADstMask = 0x55;
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc1 = (undefined *)((uint)ilInstASrc1 | 0x400000);
  if (bufferCount == 0) {
    bufferDataPtr = emitter + 10;
    bufferCount = emitter[0xb];
    tokenCapacity = emitter[0xc];
    if (tokenCapacity < bufferCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < bufferCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(tokenCapacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,tokenCapacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = emitter[9];
        if (bufferCount == 0) {
          bufferCount = 1;
          emitter[9] = 1;
        }
        tempRegisterHalf = (short)emitter[8];
        goto setEntryHeader3;
      }
      *bufferDataPtr = bufferCount;
      emitter[0xc] = tokenCapacity;
      bufferCount = emitter[0xb];
    }
    recordPtr4 = &ilInstASrc0;
    emitter[0xb] = bufferCount + 7;
    tokenWritePtr = (uint *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr4;
      recordWordNext2 = recordPtr4 + 3;
      recordPtr4 = recordPtr4 + 1;
      tokenWritePtr[4] = *recordWordNext2;
      tokenWritePtr = tokenWritePtr + 2;
    } while (recordPtr4 != &ilInstASrc2);
    tempRegisterHalf = (short)emitter[8];
    bufferCount = emitter[9];
  }
setEntryHeader3:
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0xd);
  ilInstASrc1 = (undefined *)CONCAT22(4,tempRegisterHalf + 2);
  ilInstASrc2 = (uint *)CONCAT22(4,tempRegisterHalf + 1);
  ilInstADst = CONCAT22(4,tempRegisterHalf + 1);
  entryHeader = entryHeader & 0xc000ffff | 0x50000;
  ilInstADstMask = 0x55;
  ilInstASwzArray[1] = ((unsigned char *)0x00003210);
  ilInstASwzArray[2] = ((unsigned char *)0x00003210);
  ilInstASrc0 = *(undefined **)(instr + 0x10);
  ilInstASwzArray[0] = *(undefined **)(instr + 0x1c);
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc1 = (undefined *)((uint)ilInstASrc1 | 0x400000);
  ilInstASrc2 = (uint *)((uint)ilInstASrc2 | 0x400000);
  if (bufferCount == 0) {
    bufferDataPtr = emitter + 10;
    bufferCount = emitter[0xb];
    tokenCapacity = emitter[0xc];
    if (tokenCapacity < bufferCount + 9U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < bufferCount + 9U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(tokenCapacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,tokenCapacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = emitter[9];
        if (bufferCount == 0) {
          bufferCount = 1;
          emitter[9] = 1;
        }
        tempRegisterHalf = (short)emitter[8];
        goto setEntryHeader4;
      }
      *bufferDataPtr = bufferCount;
      emitter[0xc] = tokenCapacity;
      bufferCount = emitter[0xb];
    }
    recordPtr = (undefined **)&ilInstASrc0;
    emitter[0xb] = bufferCount + 9;
    tokenWritePtr = (uint *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = (uint)*recordPtr;
      recordWordNext4 = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = (uint)*recordWordNext4;
      tokenWritePtr = tokenWritePtr + 2;
    } while (ilInstASwzArray != recordPtr);
    tempRegisterHalf = (short)emitter[8];
    bufferCount = emitter[9];
  }
setEntryHeader4:
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0xd);
  ilInstASrc2 = (uint *)CONCAT22(4,tempRegisterHalf + 1);
  ilInstASrc1 = (undefined *)CONCAT22(4,tempRegisterHalf + 1);
  entryHeader = entryHeader & 0xc000ffff | 0x50000;
  ilInstADstMask = *(uint *)(instr + 8);
  ilInstADst = *(uint *)(instr + 4);
  ilInstASwzArray[2] = ((unsigned char *)0x00003210);
  ilInstASrc0 = *(undefined **)(instr + 0xc);
  ilInstASwzArray[0] = *(undefined **)(instr + 0x18);
  ilInstASrc1 = (undefined *)((uint)ilInstASrc1 | 0x400000);
  ilInstASrc2 = (uint *)((uint)ilInstASrc2 | 0x400000);
  ilInstASwzArray[1] = (undefined *)0xba98;
  if (bufferCount == 0) {
    bufferDataPtr = emitter + 10;
    bufferCount = emitter[0xb];
    tokenCapacity = emitter[0xc];
    if (tokenCapacity < bufferCount + 9U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < bufferCount + 9U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(tokenCapacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,tokenCapacity << 2);
      }
      if (bufferCount == 0) {
        if (emitter[9] != 0) {
          return emitter[9];
        }
        emitter[9] = 1;
        return 1;
      }
      *bufferDataPtr = bufferCount;
      emitter[0xc] = tokenCapacity;
      bufferCount = emitter[0xb];
    }
    recordPtr = (undefined **)&ilInstASrc0;
    emitter[0xb] = bufferCount + 9;
    tokenWritePtr = (uint *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = (uint)*recordPtr;
      recordWordNext4 = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = (uint)*recordWordNext4;
      tokenWritePtr = tokenWritePtr + 2;
    } while (ilInstASwzArray != recordPtr);
    bufferCount = emitter[9];
  }
  return bufferCount;
}

/* fragmentTranslateRfr @ 0x42e00 (4024 bytes) */
int fragmentTranslateRfr(emitter, slot, instr)
  int emitter;
  undefined4 slot;
  int instr;
{
  undefined4 *recordWordNext;
  undefined **recordWordNext2;
  uint capacity;
  int bufferCount;
  undefined4 *recordPtr;
  undefined **recordPtr2;
  undefined4 *tokenWritePtr;
  uint *tokenWritePtr2;
  int *bufferDataPtr;
  short tempRegister;
  undefined4 entryHeader;
  undefined4 ilInstADst;
  uint ilInstADstMask;
  undefined4 ilInstASrc0;
  undefined4 ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *ilInstASwzArray [11];
  
  _memset(&entryHeader,0,0x24);
  bufferCount = *(int *)(emitter + 0x24);
  tempRegister = (short)*(undefined4 *)(emitter + 0x20);
  ilInstADst = CONCAT22(4,tempRegister);
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x23);
  ilInstADstMask = 0x55;
  ilInstASrc0 = *(undefined **)(instr + 0xc);
  ilInstASwzArray[0] = *(undefined **)(instr + 0x18);
  ilInstASrc1 = (undefined *)*(undefined4 *)(instr + 0x10);
  ilInstASwzArray[1] = (undefined *)*(undefined4 *)(instr + 0x1c);
  ilInstADst = ilInstADst | 0x400000;
  if (bufferCount == 0) {
    bufferDataPtr = (int *)(emitter + 0x28);
    bufferCount = *(int *)(emitter + 0x2c);
    capacity = *(uint *)(emitter + 0x30);
    if (capacity < bufferCount + 7U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = *(int *)(emitter + 0x24);
        if (bufferCount == 0) {
          bufferCount = 1;
          *(undefined4 *)(emitter + 0x24) = 1;
        }
        tempRegister = (short)*(undefined4 *)(emitter + 0x20);
        goto setIlInstADst;
      }
      *bufferDataPtr = bufferCount;
      *(uint *)(emitter + 0x30) = capacity;
      bufferCount = *(int *)(emitter + 0x2c);
    }
    recordPtr = &ilInstASrc0;
    *(int *)(emitter + 0x2c) = bufferCount + 7;
    tokenWritePtr = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr;
      recordWordNext = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordWordNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (&ilInstASrc2 != recordPtr);
    tempRegister = (short)*(undefined4 *)(emitter + 0x20);
    bufferCount = *(int *)(emitter + 0x24);
  }
setIlInstADst:
  ilInstADst = CONCAT22(4,tempRegister + 1);
  ilInstASrc0 = (undefined *)CONCAT22(4,tempRegister);
  ilInstASrc1 = (undefined *)CONCAT22(4,tempRegister);
  ilInstADstMask = 0x55;
  ilInstASwzArray[0] = ((unsigned char *)0x00003210);
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x40);
  ilInstASwzArray[1] = ((unsigned char *)0x00003210);
  ilInstASwzArray[2] = (undefined *)0xdddd;
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  ilInstASrc2 = 0x440000;
  ilInstASrc1 = (undefined *)((uint)ilInstASrc1 | 0x400000);
  if (bufferCount == 0) {
    bufferDataPtr = (int *)(emitter + 0x28);
    bufferCount = *(int *)(emitter + 0x2c);
    capacity = *(uint *)(emitter + 0x30);
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = *(int *)(emitter + 0x24);
        if (bufferCount == 0) {
          bufferCount = 1;
          *(undefined4 *)(emitter + 0x24) = 1;
        }
        tempRegister = (short)*(undefined4 *)(emitter + 0x20);
        goto setIlInstADst2;
      }
      *bufferDataPtr = bufferCount;
      *(uint *)(emitter + 0x30) = capacity;
      bufferCount = *(int *)(emitter + 0x2c);
    }
    recordPtr2 = (undefined **)&ilInstASrc0;
    *(int *)(emitter + 0x2c) = bufferCount + 9;
    tokenWritePtr = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr2;
      recordWordNext2 = recordPtr2 + 3;
      recordPtr2 = recordPtr2 + 1;
      tokenWritePtr[4] = *recordWordNext2;
      tokenWritePtr = tokenWritePtr + 2;
    } while (ilInstASwzArray != recordPtr2);
    tempRegister = (short)*(undefined4 *)(emitter + 0x20);
    bufferCount = *(int *)(emitter + 0x24);
  }
setIlInstADst2:
  ilInstADst = CONCAT22(4,tempRegister + 2);
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x49);
  ilInstADstMask = 0x55;
  ilInstASrc1 = *(undefined **)(instr + 0x14);
  ilInstASwzArray[1] = *(undefined **)(instr + 0x20);
  ilInstASrc0 = *(undefined **)(instr + 0x14);
  ilInstASwzArray[0] = *(undefined **)(instr + 0x20);
  ilInstADst = ilInstADst | 0x400000;
  if (bufferCount == 0) {
    bufferDataPtr = (int *)(emitter + 0x28);
    bufferCount = *(int *)(emitter + 0x2c);
    capacity = *(uint *)(emitter + 0x30);
    if (capacity < bufferCount + 7U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = *(int *)(emitter + 0x24);
        if (bufferCount == 0) {
          bufferCount = 1;
          *(undefined4 *)(emitter + 0x24) = 1;
        }
        tempRegister = (short)*(undefined4 *)(emitter + 0x20);
        goto setIlInstADst3;
      }
      *bufferDataPtr = bufferCount;
      *(uint *)(emitter + 0x30) = capacity;
      bufferCount = *(int *)(emitter + 0x2c);
    }
    recordPtr = &ilInstASrc0;
    *(int *)(emitter + 0x2c) = bufferCount + 7;
    tokenWritePtr = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr;
      recordWordNext = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordWordNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (&ilInstASrc2 != recordPtr);
    tempRegister = (short)*(undefined4 *)(emitter + 0x20);
    bufferCount = *(int *)(emitter + 0x24);
  }
setIlInstADst3:
  ilInstADst = CONCAT22(4,tempRegister + 1);
  ilInstASrc0 = (undefined *)CONCAT22(4,tempRegister + 2);
  ilInstASrc1 = (undefined *)CONCAT22(4,tempRegister + 1);
  ilInstADstMask = 0x55;
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x40);
  ilInstASwzArray[1] = ((unsigned char *)0x00003210);
  ilInstASwzArray[0] = ((unsigned char *)0x00003210);
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  ilInstASrc1 = (undefined *)((uint)ilInstASrc1 | 0x400000);
  ilInstASwzArray[2] = ((unsigned char *)0x00005555U);
  ilInstASrc2 = 0x440000;
  if (bufferCount == 0) {
    bufferDataPtr = (int *)(emitter + 0x28);
    bufferCount = *(int *)(emitter + 0x2c);
    capacity = *(uint *)(emitter + 0x30);
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = *(int *)(emitter + 0x24);
        if (bufferCount == 0) {
          bufferCount = 1;
          *(undefined4 *)(emitter + 0x24) = 1;
        }
        tempRegister = (short)*(undefined4 *)(emitter + 0x20);
        goto setIlInstADst4;
      }
      *bufferDataPtr = bufferCount;
      *(uint *)(emitter + 0x30) = capacity;
      bufferCount = *(int *)(emitter + 0x2c);
    }
    recordPtr2 = (undefined **)&ilInstASrc0;
    *(int *)(emitter + 0x2c) = bufferCount + 9;
    tokenWritePtr = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr2;
      recordWordNext2 = recordPtr2 + 3;
      recordPtr2 = recordPtr2 + 1;
      tokenWritePtr[4] = *recordWordNext2;
      tokenWritePtr = tokenWritePtr + 2;
    } while (ilInstASwzArray != recordPtr2);
    tempRegister = (short)*(undefined4 *)(emitter + 0x20);
    bufferCount = *(int *)(emitter + 0x24);
  }
setIlInstADst4:
  ilInstADst = CONCAT22(4,tempRegister + 2);
  ilInstASrc0 = (undefined *)CONCAT22(4,tempRegister + 1);
  ilInstADstMask = 0x55;
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x5a);
  ilInstASwzArray[0] = ((unsigned char *)0x00003210);
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  if (bufferCount == 0) {
    bufferDataPtr = (int *)(emitter + 0x28);
    bufferCount = *(int *)(emitter + 0x2c);
    capacity = *(uint *)(emitter + 0x30);
    if (capacity < bufferCount + 5U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 5U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = *(int *)(emitter + 0x24);
        if (bufferCount == 0) {
          bufferCount = 1;
          *(undefined4 *)(emitter + 0x24) = 1;
        }
        tempRegister = (short)*(undefined4 *)(emitter + 0x20);
        goto setIlInstADst5;
      }
      *bufferDataPtr = bufferCount;
      *(uint *)(emitter + 0x30) = capacity;
      bufferCount = *(int *)(emitter + 0x2c);
    }
    *(int *)(emitter + 0x2c) = bufferCount + 5;
    tokenWritePtr = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    tokenWritePtr[3] = ilInstASrc0;
    tokenWritePtr[4] = ilInstASwzArray[0];
    tempRegister = (short)*(undefined4 *)(emitter + 0x20);
    bufferCount = *(int *)(emitter + 0x24);
  }
setIlInstADst5:
  ilInstADst = CONCAT22(4,tempRegister + 2);
  ilInstASrc2 = CONCAT22(4,tempRegister + 2);
  ilInstASrc1 = (undefined *)CONCAT22(4,tempRegister);
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x40);
  ilInstADst = ilInstADst | 0x400000;
  ilInstADstMask = 0x55;
  ilInstASwzArray[1] = ((unsigned char *)0x00003210);
  ilInstASwzArray[2] = ((unsigned char *)0x00003210);
  ilInstASrc0 = *(undefined **)(instr + 0x14);
  ilInstASwzArray[0] = *(undefined **)(instr + 0x20);
  ilInstASrc2 = ilInstASrc2 | 0x400000;
  ilInstASrc1 = (undefined *)((uint)ilInstASrc1 | 0x400000);
  if (bufferCount == 0) {
    bufferDataPtr = (int *)(emitter + 0x28);
    bufferCount = *(int *)(emitter + 0x2c);
    capacity = *(uint *)(emitter + 0x30);
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = *(int *)(emitter + 0x24);
        if (bufferCount == 0) {
          bufferCount = 1;
          *(undefined4 *)(emitter + 0x24) = 1;
        }
        tempRegister = (short)*(undefined4 *)(emitter + 0x20);
        goto setIlInstADst6;
      }
      *bufferDataPtr = bufferCount;
      *(uint *)(emitter + 0x30) = capacity;
      bufferCount = *(int *)(emitter + 0x2c);
    }
    recordPtr2 = (undefined **)&ilInstASrc0;
    *(int *)(emitter + 0x2c) = bufferCount + 9;
    tokenWritePtr = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr2;
      recordWordNext2 = recordPtr2 + 3;
      recordPtr2 = recordPtr2 + 1;
      tokenWritePtr[4] = *recordWordNext2;
      tokenWritePtr = tokenWritePtr + 2;
    } while (ilInstASwzArray != recordPtr2);
    tempRegister = (short)*(undefined4 *)(emitter + 0x20);
    bufferCount = *(int *)(emitter + 0x24);
  }
setIlInstADst6:
  ilInstADst = CONCAT22(4,tempRegister + 2);
  ilInstASrc0 = (undefined *)CONCAT22(4,tempRegister + 2);
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x49);
  ilInstASwzArray[0] = ((unsigned char *)0x00003210);
  ilInstADstMask = 0x55;
  ilInstADst = ilInstADst | 0x400000;
  ilInstASrc1 = (undefined *)*(undefined4 *)(instr + 0x10);
  ilInstASwzArray[1] = (undefined *)*(undefined4 *)(instr + 0x1c);
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  if (bufferCount == 0) {
    bufferDataPtr = (int *)(emitter + 0x28);
    bufferCount = *(int *)(emitter + 0x2c);
    capacity = *(uint *)(emitter + 0x30);
    if (capacity < bufferCount + 7U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = *(int *)(emitter + 0x24);
        if (bufferCount == 0) {
          bufferCount = 1;
          *(undefined4 *)(emitter + 0x24) = 1;
        }
        tempRegister = (short)*(undefined4 *)(emitter + 0x20);
        goto setIlInstADst7;
      }
      *bufferDataPtr = bufferCount;
      *(uint *)(emitter + 0x30) = capacity;
      bufferCount = *(int *)(emitter + 0x2c);
    }
    recordPtr = &ilInstASrc0;
    *(int *)(emitter + 0x2c) = bufferCount + 7;
    tokenWritePtr = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr;
      recordWordNext = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordWordNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (recordPtr != &ilInstASrc2);
    tempRegister = (short)*(undefined4 *)(emitter + 0x20);
    bufferCount = *(int *)(emitter + 0x24);
  }
setIlInstADst7:
  ilInstADst = CONCAT22(4,tempRegister + 2);
  ilInstASrc2 = CONCAT22(4,tempRegister + 2);
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0x40);
  ilInstADstMask = 0x55;
  ilInstADst = ilInstADst | 0x400000;
  ilInstASwzArray[2] = (undefined *)0xba98;
  ilInstASrc0 = *(undefined **)(instr + 0x14);
  ilInstASwzArray[0] = *(undefined **)(instr + 0x20);
  ilInstASrc1 = (undefined *)*(undefined4 *)(instr + 0xc);
  ilInstASwzArray[1] = (undefined *)*(undefined4 *)(instr + 0x18);
  ilInstASrc2 = ilInstASrc2 | 0x400000;
  if (bufferCount == 0) {
    bufferDataPtr = (int *)(emitter + 0x28);
    bufferCount = *(int *)(emitter + 0x2c);
    capacity = *(uint *)(emitter + 0x30);
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        bufferCount = *(int *)(emitter + 0x24);
        if (bufferCount == 0) {
          bufferCount = 1;
          *(undefined4 *)(emitter + 0x24) = 1;
        }
        tempRegister = (short)*(undefined4 *)(emitter + 0x20);
        goto setEntryHeader;
      }
      *bufferDataPtr = bufferCount;
      *(uint *)(emitter + 0x30) = capacity;
      bufferCount = *(int *)(emitter + 0x2c);
    }
    recordPtr2 = (undefined **)&ilInstASrc0;
    *(int *)(emitter + 0x2c) = bufferCount + 9;
    tokenWritePtr = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = entryHeader;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr2;
      recordWordNext2 = recordPtr2 + 3;
      recordPtr2 = recordPtr2 + 1;
      tokenWritePtr[4] = *recordWordNext2;
      tokenWritePtr = tokenWritePtr + 2;
    } while (ilInstASwzArray != recordPtr2);
    tempRegister = (short)*(undefined4 *)(emitter + 0x20);
    bufferCount = *(int *)(emitter + 0x24);
  }
setEntryHeader:
  entryHeader = CONCAT22((*(unsigned short *)((unsigned char *)&(entryHeader) + 0)),0xd);
  ilInstASrc0 = (undefined *)CONCAT22(4,tempRegister + 1);
  ilInstASrc2 = CONCAT22(4,tempRegister + 2);
  entryHeader = entryHeader & 0xc000ffff | 0x50000;
  ilInstADstMask = *(uint *)(instr + 8);
  ilInstADst = *(uint *)(instr + 4);
  ilInstASwzArray[1] = ((unsigned char *)0x00004444);
  ilInstASwzArray[0] = ((unsigned char *)0x00003210);
  ilInstASwzArray[2] = ((unsigned char *)0x00003210);
  ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
  ilInstASrc1 = (undefined *)0x440000;
  ilInstASrc2 = ilInstASrc2 | 0x400000;
  if (bufferCount == 0) {
    bufferDataPtr = (int *)(emitter + 0x28);
    bufferCount = *(int *)(emitter + 0x2c);
    capacity = *(uint *)(emitter + 0x30);
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
        if (*(int *)(emitter + 0x24) != 0) {
          return *(int *)(emitter + 0x24);
        }
        *(undefined4 *)(emitter + 0x24) = 1;
        return 1;
      }
      *bufferDataPtr = bufferCount;
      *(uint *)(emitter + 0x30) = capacity;
      bufferCount = *(int *)(emitter + 0x2c);
    }
    recordPtr2 = (undefined **)&ilInstASrc0;
    *(int *)(emitter + 0x2c) = bufferCount + 9;
    tokenWritePtr2 = (uint *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr2 = entryHeader;
    tokenWritePtr2[1] = ilInstADst;
    tokenWritePtr2[2] = ilInstADstMask;
    do {
      tokenWritePtr2[3] = (uint)*recordPtr2;
      recordWordNext2 = recordPtr2 + 3;
      recordPtr2 = recordPtr2 + 1;
      tokenWritePtr2[4] = (uint)*recordWordNext2;
      tokenWritePtr2 = tokenWritePtr2 + 2;
    } while (ilInstASwzArray != recordPtr2);
    bufferCount = *(int *)(emitter + 0x24);
  }
  return bufferCount;
}

/* fragmentTranslateFfw @ 0x43df0 (352 bytes) */
int fragmentTranslateFfw(translator, slot, ilInstr)
  int translator;
  undefined4 slot;
  undefined4 *ilInstr;
{
  int tokenCount;
  int allocation;
  undefined4 *srcSwizzlePtr;
  bool morePairs;
  uint tokenCapacity;
  int translatorError;
  int srcPairIndex;
  undefined4 src2Operand;
  undefined4 src2Swizzle;
  undefined4 *tokenWritePtr;
  int *tokenDataPtrAddr;
  
  src2Operand = ilInstr[5];
  src2Swizzle = ilInstr[8];
  ilInstr[5] = ilInstr[3];
  ilInstr[8] = ilInstr[6];
  ilInstr[3] = src2Operand;
  ilInstr[6] = src2Swizzle;
  translatorError = *(int *)(translator + 0x24);
  if (translatorError == 0) {
    tokenDataPtrAddr = (int *)(translator + 0x28);
    tokenCount = *(int *)(translator + 0x2c);
    tokenCapacity = *(uint *)(translator + 0x30);
    if (tokenCapacity < tokenCount + 9U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 9U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (*(int *)(translator + 0x24) != 0) {
          return *(int *)(translator + 0x24);
        }
        *(undefined4 *)(translator + 0x24) = 1;
        return 1;
      }
      *tokenDataPtrAddr = allocation;
      *(uint *)(translator + 0x30) = tokenCapacity;
      tokenCount = *(int *)(translator + 0x2c);
    }
    srcPairIndex = 0;
    *(int *)(translator + 0x2c) = tokenCount + 9;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    do {
      morePairs = srcPairIndex != 2;
      srcPairIndex = srcPairIndex + 1;
      tokenWritePtr[3] = ilInstr[3];
      srcSwizzlePtr = ilInstr + 6;
      ilInstr = ilInstr + 1;
      tokenWritePtr[4] = *srcSwizzlePtr;
      tokenWritePtr = tokenWritePtr + 2;
    } while (morePairs);
    translatorError = *(int *)(translator + 0x24);
  }
  return translatorError;
}

/* fragmentTranslateDst @ 0x43f60 (996 bytes) */
int fragmentTranslateDst(translator, slot, ilInstr)
  int translator;
  undefined4 slot;
  undefined4 *ilInstr;
{
  undefined4 *srcCursor;
  int allocation;
  undefined4 *srcSwizzlePtr;
  bool morePairs;
  uint tokenCapacity;
  int tokenCount;
  int srcPairIndex;
  undefined4 *srcSwizzlePtrFirst;
  undefined4 tempRegister;
  undefined4 *tokenWritePtr;
  undefined4 savedDstMask;
  undefined4 savedDst;
  int *tokenDataPtrAddr;
  
  if ((*(uint *)(translator + 0x14) & 0x20000000) == 0) {
    *(undefined2 *)((int)ilInstr + 2) = 0x24;
    if (*(int *)(translator + 0x24) != 0) {
      return *(int *)(translator + 0x24);
    }
    tokenDataPtrAddr = (int *)(translator + 0x28);
    tokenCount = *(int *)(translator + 0x2c);
    tokenCapacity = *(uint *)(translator + 0x30);
    if (tokenCount + 7U <= tokenCapacity) {
loopSetSrcPairIndex:
      srcPairIndex = 0;
      *(int *)(translator + 0x2c) = tokenCount + 7;
      tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
      *tokenWritePtr = *ilInstr;
      tokenWritePtr[1] = ilInstr[1];
      tokenWritePtr[2] = ilInstr[2];
      do {
        morePairs = srcPairIndex != 1;
        srcPairIndex = srcPairIndex + 1;
        tokenWritePtr[3] = ilInstr[3];
        srcSwizzlePtrFirst = ilInstr + 6;
        ilInstr = ilInstr + 1;
        tokenWritePtr[4] = *srcSwizzlePtrFirst;
        tokenWritePtr = tokenWritePtr + 2;
      } while (morePairs);
      return *(int *)(translator + 0x24);
    }
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation != 0) {
      *tokenDataPtrAddr = allocation;
      *(uint *)(translator + 0x30) = tokenCapacity;
      tokenCount = *(int *)(translator + 0x2c);
      goto loopSetSrcPairIndex;
    }
    goto checkTranslator;
  }
  tempRegister = *(undefined4 *)(translator + 0x20);
  savedDst = ilInstr[1];
  savedDstMask = ilInstr[2];
  ilInstr[1] = 0x40000;
  *(short *)((int)ilInstr + 6) = (short)tempRegister;
  ilInstr[2] = 0x55;
  ilInstr[1] = ilInstr[1] | 0x400000;
  if (*(int *)(translator + 0x24) == 0) {
    tokenDataPtrAddr = (int *)(translator + 0x28);
    tokenCount = *(int *)(translator + 0x2c);
    tokenCapacity = *(uint *)(translator + 0x30);
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (*(int *)(translator + 0x24) == 0) {
          *(undefined4 *)(translator + 0x24) = 1;
        }
        goto storeIlInstr;
      }
      *tokenDataPtrAddr = allocation;
      *(uint *)(translator + 0x30) = tokenCapacity;
      tokenCount = *(int *)(translator + 0x2c);
    }
    srcPairIndex = 0;
    *(int *)(translator + 0x2c) = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = *ilInstr;
    tokenWritePtr[1] = ilInstr[1];
    tokenWritePtr[2] = ilInstr[2];
    srcCursor = ilInstr;
    do {
      morePairs = srcPairIndex != 1;
      srcPairIndex = srcPairIndex + 1;
      tokenWritePtr[3] = srcCursor[3];
      srcSwizzlePtr = srcCursor + 6;
      srcCursor = srcCursor + 1;
      tokenWritePtr[4] = *srcSwizzlePtr;
      tokenWritePtr = tokenWritePtr + 2;
    } while (morePairs);
  }
storeIlInstr:
  ilInstr[1] = savedDst;
  ilInstr[2] = savedDstMask;
  *ilInstr = 0;
  *(undefined2 *)((int)ilInstr + 2) = 0x38;
  tempRegister = *(undefined4 *)(translator + 0x20);
  ilInstr[3] = 0x40000;
  *(short *)((int)ilInstr + 0xe) = (short)tempRegister;
  ilInstr[6] = ((unsigned char *)0x00003210);
  ilInstr[3] = ilInstr[3] | 0x400000;
  if (*(int *)(translator + 0x24) != 0) {
    return *(int *)(translator + 0x24);
  }
  tokenDataPtrAddr = (int *)(translator + 0x28);
  tokenCount = *(int *)(translator + 0x2c);
  tokenCapacity = *(uint *)(translator + 0x30);
  if (tokenCapacity < tokenCount + 5U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
checkTranslator:
      if (*(int *)(translator + 0x24) == 0) {
        *(undefined4 *)(translator + 0x24) = 1;
        return 1;
      }
      return *(int *)(translator + 0x24);
    }
    *tokenDataPtrAddr = allocation;
    *(uint *)(translator + 0x30) = tokenCapacity;
    tokenCount = *(int *)(translator + 0x2c);
  }
  *(int *)(translator + 0x2c) = tokenCount + 5;
  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
  *tokenWritePtr = *ilInstr;
  tokenWritePtr[1] = ilInstr[1];
  tokenWritePtr[2] = ilInstr[2];
  tokenWritePtr[3] = ilInstr[3];
  tokenWritePtr[4] = ilInstr[6];
  return *(int *)(translator + 0x24);
}

/* fragmentTranslateIf @ 0x44360 (388 bytes) */
int fragmentTranslateIf(translator, slot, ilInstr)
  int translator;
  undefined4 slot;
  undefined4 *ilInstr;
{
  int translatorError;
  int tokenCount;
  int allocation;
  undefined4 *srcSwizzlePtr;
  bool morePairs;
  uint tokenCapacity;
  int srcPairIndex;
  undefined4 *tokenWritePtr;
  int *tokenDataPtrAddr;
  
  ilInstr[4] = 0x40000;
  *(undefined2 *)((int)ilInstr + 0x12) = 0;
  ilInstr[7] = ((unsigned char *)0x00004444);
  ilInstr[4] = ilInstr[4] | 0x400000;
  if (*(int *)(translator + 0x24) != 0) {
    return *(int *)(translator + 0x24);
  }
  tokenDataPtrAddr = (int *)(translator + 0x28);
  tokenCount = *(int *)(translator + 0x2c);
  tokenCapacity = *(uint *)(translator + 0x30);
  if (tokenCapacity < tokenCount + 5U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 5U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
      translatorError = *(int *)(translator + 0x24);
      if (translatorError == 0) {
        translatorError = 1;
        *(undefined4 *)(translator + 0x24) = 1;
      }
      tokenWritePtr = (undefined4 *)0x0;
      if (translatorError != 0) {
        return translatorError;
      }
      goto setSrcPairIndex;
    }
    *tokenDataPtrAddr = allocation;
    *(uint *)(translator + 0x30) = tokenCapacity;
    tokenCount = *(int *)(translator + 0x2c);
  }
  *(int *)(translator + 0x2c) = tokenCount + 5;
  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
setSrcPairIndex:
  srcPairIndex = 0;
  *tokenWritePtr = *ilInstr;
  do {
    morePairs = srcPairIndex != 1;
    srcPairIndex = srcPairIndex + 1;
    tokenWritePtr[1] = ilInstr[3];
    srcSwizzlePtr = ilInstr + 6;
    ilInstr = ilInstr + 1;
    tokenWritePtr[2] = *srcSwizzlePtr;
    tokenWritePtr = tokenWritePtr + 2;
  } while (morePairs);
  return 0;
}

/* fragmentTranslateRfl @ 0x44500 (1432 bytes) */
int fragmentTranslateRfl(translator, slot, ilInstr)
  int translator;
  undefined4 slot;
  int ilInstr;
{
  int tokenCount;
  int allocation;
  undefined4 *recordWordNext;
  uint tokenCapacity;
  int translatorError;
  undefined2 tempRegister;
  undefined4 *recordPtr;
  undefined4 *tokenWritePtr;
  int *tokenDataPtrAddr;
  undefined4 ilInstAOpcode;
  undefined4 ilInstADst;
  undefined4 ilInstADstMask;
  undefined4 ilInstASrc0;
  undefined4 ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *ilInstASwz0;
  undefined *ilInstASwz1;
  
  _memset(&ilInstAOpcode,0,0x24);
  translatorError = *(int *)(translator + 0x24);
  tempRegister = (undefined2)*(undefined4 *)(translator + 0x20);
  ilInstADst = CONCAT22(4,tempRegister);
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x23);
  ilInstADstMask = 0x55;
  ilInstASrc0 = *(undefined4 *)(ilInstr + 0xc);
  ilInstASwz0 = (undefined *)*(undefined4 *)(ilInstr + 0x18);
  ilInstASrc1 = *(undefined4 *)(ilInstr + 0x10);
  ilInstASwz1 = (undefined *)*(undefined4 *)(ilInstr + 0x1c);
  ilInstADst = ilInstADst | 0x400000;
  if (translatorError == 0) {
    tokenDataPtrAddr = (int *)(translator + 0x28);
    tokenCount = *(int *)(translator + 0x2c);
    tokenCapacity = *(uint *)(translator + 0x30);
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        translatorError = *(int *)(translator + 0x24);
        if (translatorError == 0) {
          translatorError = 1;
          *(undefined4 *)(translator + 0x24) = 1;
        }
        tempRegister = (undefined2)*(undefined4 *)(translator + 0x20);
        goto setIlInstASrc0;
      }
      *tokenDataPtrAddr = allocation;
      *(uint *)(translator + 0x30) = tokenCapacity;
      tokenCount = *(int *)(translator + 0x2c);
    }
    recordPtr = &ilInstASrc0;
    *(int *)(translator + 0x2c) = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = ilInstAOpcode;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr;
      recordWordNext = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordWordNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (&ilInstASrc2 != recordPtr);
    tempRegister = (undefined2)*(undefined4 *)(translator + 0x20);
    translatorError = *(int *)(translator + 0x24);
  }
setIlInstASrc0:
  ilInstASrc0 = CONCAT22(4,tempRegister);
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x49);
  ilInstASwz0 = ((unsigned char *)0x00003210);
  ilInstASrc0 = ilInstASrc0 | 0x400000;
  if (translatorError == 0) {
    tokenDataPtrAddr = (int *)(translator + 0x28);
    tokenCount = *(int *)(translator + 0x2c);
    tokenCapacity = *(uint *)(translator + 0x30);
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        translatorError = *(int *)(translator + 0x24);
        if (translatorError == 0) {
          translatorError = 1;
          *(undefined4 *)(translator + 0x24) = 1;
        }
        tempRegister = (undefined2)*(undefined4 *)(translator + 0x20);
        goto setIlInstASrc1;
      }
      *tokenDataPtrAddr = allocation;
      *(uint *)(translator + 0x30) = tokenCapacity;
      tokenCount = *(int *)(translator + 0x2c);
    }
    recordPtr = &ilInstASrc0;
    *(int *)(translator + 0x2c) = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = ilInstAOpcode;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr;
      recordWordNext = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordWordNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (&ilInstASrc2 != recordPtr);
    tempRegister = (undefined2)*(undefined4 *)(translator + 0x20);
    translatorError = *(int *)(translator + 0x24);
  }
setIlInstASrc1:
  ilInstASrc1 = CONCAT22(4,tempRegister);
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),3);
  ilInstASwz1 = ((unsigned char *)0x00003210);
  ilInstASrc1 = ilInstASrc1 | 0x400000;
  if (translatorError == 0) {
    tokenDataPtrAddr = (int *)(translator + 0x28);
    tokenCount = *(int *)(translator + 0x2c);
    tokenCapacity = *(uint *)(translator + 0x30);
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        translatorError = *(int *)(translator + 0x24);
        if (translatorError == 0) {
          translatorError = 1;
          *(undefined4 *)(translator + 0x24) = 1;
        }
        goto setIlInstADst;
      }
      *tokenDataPtrAddr = allocation;
      *(uint *)(translator + 0x30) = tokenCapacity;
      tokenCount = *(int *)(translator + 0x2c);
    }
    recordPtr = &ilInstASrc0;
    *(int *)(translator + 0x2c) = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = ilInstAOpcode;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr;
      recordWordNext = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordWordNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (recordPtr != &ilInstASrc2);
    translatorError = *(int *)(translator + 0x24);
  }
setIlInstADst:
  ilInstADst = *(undefined4 *)(ilInstr + 4);
  ilInstADstMask = *(undefined4 *)(ilInstr + 8);
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x5b);
  ilInstASwz0 = (undefined *)*(undefined4 *)(ilInstr + 0x18);
  ilInstASrc0 = *(undefined4 *)(ilInstr + 0xc);
  if (translatorError == 0) {
    tokenDataPtrAddr = (int *)(translator + 0x28);
    tokenCount = *(int *)(translator + 0x2c);
    tokenCapacity = *(uint *)(translator + 0x30);
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
        if (*(int *)(translator + 0x24) != 0) {
          return *(int *)(translator + 0x24);
        }
        *(undefined4 *)(translator + 0x24) = 1;
        return 1;
      }
      *tokenDataPtrAddr = allocation;
      *(uint *)(translator + 0x30) = tokenCapacity;
      tokenCount = *(int *)(translator + 0x2c);
    }
    recordPtr = &ilInstASrc0;
    *(int *)(translator + 0x2c) = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = ilInstAOpcode;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr;
      recordWordNext = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr[4] = *recordWordNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (recordPtr != &ilInstASrc2);
    translatorError = *(int *)(translator + 0x24);
  }
  return translatorError;
}

/* fragmentTranslateWhile @ 0x44ac0 (440 bytes) */
int fragmentTranslateWhile(translator, slot, ilInstr)
  int translator;
  undefined4 slot;
  undefined4 *ilInstr;
{
  uint tokenCapacity;
  int translatorError;
  int allocation;
  uint translatorFlags;
  int tokenCount;
  undefined4 *tokenWritePtr;
  dword *tokenWord2Ptr;
  dword *tokenWord1Ptr;
  int *tokenDataPtrAddr;
  uint scalarConstOperand [9];
  
  translatorFlags = *(uint *)(translator + 0x14);
  if ((translatorFlags & 0x100000) == 0) {
    scalarConstOperand[0] = translatorFlags & 0x100000;
    ((int (*)())fpilEmitScalarConstant)(translator,0xff,scalarConstOperand);
    translatorFlags = (scalarConstOperand[0] & 0x1f) << 0xf | *(uint *)(translator + 0x14) & 0xfff07fff | 0x100000;
    *(uint *)(translator + 0x14) = translatorFlags;
  }
  ilInstr[3] = 0x40000;
  *(ushort *)((int)ilInstr + 0xe) = (ushort)(translatorFlags >> 0xf) & 0x1f;
  ilInstr[6] = ((unsigned char *)0x00003210);
  ilInstr[3] = ilInstr[3] & 0xffc0ffff | 0x420000;
  if (*(int *)(translator + 0x24) != 0) {
    return *(int *)(translator + 0x24);
  }
  tokenDataPtrAddr = (int *)(translator + 0x28);
  tokenCount = *(int *)(translator + 0x2c);
  tokenCapacity = *(uint *)(translator + 0x30);
  if (tokenCapacity < tokenCount + 3U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 3U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation == 0) {
      translatorError = *(int *)(translator + 0x24);
      if (translatorError == 0) {
        translatorError = 1;
        *(undefined4 *)(translator + 0x24) = 1;
      }
      if (translatorError != 0) {
        return translatorError;
      }
      tokenWritePtr = (undefined4 *)0x0;
      tokenWord1Ptr = ((unsigned char *)0x4);
      tokenWord2Ptr = ((unsigned char *)0x8);
      goto storeTokenWritePtr;
    }
    *tokenDataPtrAddr = allocation;
    *(uint *)(translator + 0x30) = tokenCapacity;
    tokenCount = *(int *)(translator + 0x2c);
  }
  *(int *)(translator + 0x2c) = tokenCount + 3;
  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
  tokenWord1Ptr = tokenWritePtr + 1;
  tokenWord2Ptr = tokenWritePtr + 2;
storeTokenWritePtr:
  *tokenWritePtr = *ilInstr;
  *tokenWord1Ptr = ilInstr[3];
  *tokenWord2Ptr = ilInstr[6];
  return 0;
}

/* fragmentTranslateDsl @ 0x44c90 (2856 bytes) */
int fragmentTranslateDsl(emitter, recordIndex)
  int *emitter;
  int recordIndex;
{
  undefined4 *tokenWritePtr;
  undefined **recordPtr3;
  undefined **recordPtr2;
  undefined **recordWordNext4;
  undefined4 *recordWordNext3;
  undefined4 *recordWordNext;
  undefined **recordWordNext2;
  int bufferCount;
  uint capacity;
  undefined4 *recordPtr;
  undefined4 *srcCursor;
  undefined **swizzleCursor;
  undefined **recordWordNext5;
  undefined4 *tokenWritePtr2;
  uint *tokenWritePtr3;
  int opRecord;
  int *bufferDataPtr;
  undefined1 dstTokenHeader [2];
  ushort dstRegister;
  undefined1 dstMask [4];
  undefined *composedSwizzle;
  undefined4 ilInstAOpcode;
  undefined4 ilInstADst;
  undefined4 ilInstADstMask;
  undefined4 ilInstASrc0;
  undefined4 ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *ilInstASwz0;
  undefined *ilInstASwz1;
  undefined4 ilInstBOpcode;
  undefined4 ilInstBDst;
  uint ilInstBDstMask;
  undefined4 ilInstBSrc0;
  undefined4 ilInstBSrc1;
  undefined4 ilInstBSrc2;
  undefined *swizzleSlots [3];
  undefined4 ilInstCOpcode;
  undefined4 ilInstCDst;
  undefined4 ilInstCDstMask;
  undefined4 ilInstCSrc0;
  undefined1 srcToken [4];
  uint ilInstCSrc2;
  undefined *ilInstCSwz0;
  undefined1 srcSwizzle [4];
  undefined *ilInstCSwz2;
  
  opRecord = *emitter;
  recordPtr = &ilInstASrc0;
  bufferCount = *(int *)(opRecord + 0x54);
  _memset(&ilInstAOpcode,0,0x24);
  opRecord = opRecord + bufferCount * 8 + recordIndex * 8;
  _memset(&ilInstBOpcode,0,0x24);
  ilInstADst = CONCAT22(4,(short)emitter[8]);
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x5b);
  ilInstADstMask = 0x55;
  ilInstADst = ilInstADst | 0x400000;
  bufferCount = ((int (*)())fpilTranslateSource)(emitter,opRecord + 0x18,recordPtr,&ilInstASwz0);
  if (bufferCount == 0) {
    ilInstASwz1 = ((unsigned char *)0x00005555U);
    ilInstASrc1 = 0x440000;
    if (emitter[9] != 0) {
      return emitter[9];
    }
    bufferDataPtr = emitter + 10;
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 7U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) goto checkEmitter;
      *bufferDataPtr = bufferCount;
      emitter[0xc] = capacity;
      bufferCount = emitter[0xb];
    }
    emitter[0xb] = bufferCount + 7;
    tokenWritePtr2 = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr2 = ilInstAOpcode;
    tokenWritePtr2[1] = ilInstADst;
    tokenWritePtr2[2] = ilInstADstMask;
    srcCursor = recordPtr;
    do {
      tokenWritePtr2[3] = *srcCursor;
      recordWordNext = srcCursor + 3;
      srcCursor = srcCursor + 1;
      tokenWritePtr2[4] = *recordWordNext;
      tokenWritePtr2 = tokenWritePtr2 + 2;
    } while (&ilInstASrc2 != srcCursor);
    ilInstBOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBOpcode) + 0)),0xd);
    ilInstBDst = CONCAT22(4,(short)emitter[8] + 1);
    ilInstBSrc0 = (undefined *)CONCAT22(4,(short)emitter[8]);
    ilInstBOpcode = ilInstBOpcode & 0xc000ffff | 0x20000;
    ilInstBDst = ilInstBDst | 0x400000;
    ilInstBDstMask = 0x55;
    swizzleSlots[0] = ((unsigned char *)0x00003210);
    swizzleSlots[1] = ((unsigned char *)0x00004454);
    swizzleSlots[2] = ((unsigned char *)0x00004445);
    ilInstBSrc0 = (undefined *)((uint)ilInstBSrc0 | 0x400000);
    ilInstBSrc1 = 0x440000;
    ilInstBSrc2 = 0x440000;
    if (emitter[9] != 0) {
      return emitter[9];
    }
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) goto checkEmitter;
      *bufferDataPtr = bufferCount;
      emitter[0xc] = capacity;
      bufferCount = emitter[0xb];
    }
    recordPtr3 = (undefined **)&ilInstBSrc0;
    emitter[0xb] = bufferCount + 9;
    tokenWritePtr3 = (uint *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr3 = ilInstBOpcode;
    tokenWritePtr3[1] = ilInstBDst;
    tokenWritePtr3[2] = ilInstBDstMask;
    swizzleCursor = recordPtr3;
    do {
      tokenWritePtr3[3] = (uint)*swizzleCursor;
      recordWordNext2 = swizzleCursor + 3;
      swizzleCursor = swizzleCursor + 1;
      tokenWritePtr3[4] = (uint)*recordWordNext2;
      tokenWritePtr3 = tokenWritePtr3 + 2;
    } while (swizzleSlots != swizzleCursor);
    if (1 < (*(uint *)(opRecord + 4) >> 0x1a & 3)) {
      ilInstASrc0 = CONCAT22(4,(short)emitter[8]);
      ilInstASwz0 = ((unsigned char *)0x00003210);
      ilInstASrc0 = ilInstASrc0 | 0x400000;
      if (emitter[9] != 0) {
        return emitter[9];
      }
      bufferCount = emitter[0xb];
      capacity = emitter[0xc];
      if (capacity < bufferCount + 7U) {
        if (capacity == 0) {
          capacity = 0x10;
        }
        else {
          capacity = capacity << 1;
        }
        for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
        }
        if (*bufferDataPtr == 0) {
          bufferCount = _malloc(capacity << 2);
        }
        else {
          bufferCount = _realloc(*bufferDataPtr,capacity << 2);
        }
        if (bufferCount == 0) goto checkEmitter;
        *bufferDataPtr = bufferCount;
        emitter[0xc] = capacity;
        bufferCount = emitter[0xb];
      }
      emitter[0xb] = bufferCount + 7;
      tokenWritePtr2 = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
      *tokenWritePtr2 = ilInstAOpcode;
      tokenWritePtr2[1] = ilInstADst;
      tokenWritePtr2[2] = ilInstADstMask;
      srcCursor = recordPtr;
      do {
        tokenWritePtr2[3] = *srcCursor;
        recordWordNext = srcCursor + 3;
        srcCursor = srcCursor + 1;
        tokenWritePtr2[4] = *recordWordNext;
        tokenWritePtr2 = tokenWritePtr2 + 2;
      } while (&ilInstASrc2 != srcCursor);
      ilInstBSrc2 = CONCAT22(4,(short)emitter[8] + 1);
      swizzleSlots[1] = (undefined *)((uint)swizzleSlots[1] & 0xfffff88f | 0x540);
      swizzleSlots[2] = ((unsigned char *)0x00003210);
      ilInstBSrc2 = ilInstBSrc2 | 0x400000;
      if (emitter[9] != 0) {
        return emitter[9];
      }
      bufferCount = emitter[0xb];
      capacity = emitter[0xc];
      if (capacity < bufferCount + 9U) {
        if (capacity == 0) {
          capacity = 0x10;
        }
        else {
          capacity = capacity << 1;
        }
        for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
        }
        if (*bufferDataPtr == 0) {
          bufferCount = _malloc(capacity << 2);
        }
        else {
          bufferCount = _realloc(*bufferDataPtr,capacity << 2);
        }
        if (bufferCount == 0) goto checkEmitter;
        *bufferDataPtr = bufferCount;
        emitter[0xc] = capacity;
        bufferCount = emitter[0xb];
      }
      emitter[0xb] = bufferCount + 9;
      tokenWritePtr3 = (uint *)(bufferCount * 4 + *bufferDataPtr);
      *tokenWritePtr3 = ilInstBOpcode;
      tokenWritePtr3[1] = ilInstBDst;
      tokenWritePtr3[2] = ilInstBDstMask;
      swizzleCursor = recordPtr3;
      do {
        tokenWritePtr3[3] = (uint)*swizzleCursor;
        recordWordNext2 = swizzleCursor + 3;
        swizzleCursor = swizzleCursor + 1;
        tokenWritePtr3[4] = (uint)*recordWordNext2;
        tokenWritePtr3 = tokenWritePtr3 + 2;
      } while (swizzleSlots != swizzleCursor);
      if ((*(uint *)(opRecord + 4) & 0xc000000) == 0xc000000) {
        if (emitter[9] != 0) {
          return emitter[9];
        }
        bufferCount = emitter[0xb];
        capacity = emitter[0xc];
        if (capacity < bufferCount + 7U) {
          if (capacity == 0) {
            capacity = 0x10;
          }
          else {
            capacity = capacity << 1;
          }
          for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
          }
          if (*bufferDataPtr == 0) {
            bufferCount = _malloc(capacity << 2);
          }
          else {
            bufferCount = _realloc(*bufferDataPtr,capacity << 2);
          }
          if (bufferCount == 0) goto checkEmitter;
          *bufferDataPtr = bufferCount;
          emitter[0xc] = capacity;
          bufferCount = emitter[0xb];
        }
        emitter[0xb] = bufferCount + 7;
        tokenWritePtr2 = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
        *tokenWritePtr2 = ilInstAOpcode;
        tokenWritePtr2[1] = ilInstADst;
        tokenWritePtr2[2] = ilInstADstMask;
        do {
          tokenWritePtr2[3] = *recordPtr;
          recordWordNext3 = recordPtr + 3;
          recordPtr = recordPtr + 1;
          tokenWritePtr2[4] = *recordWordNext3;
          tokenWritePtr2 = tokenWritePtr2 + 2;
        } while (&ilInstASrc2 != recordPtr);
        swizzleSlots[1] = (undefined *)((uint)swizzleSlots[1] & 0xffff88ff | 0x5400);
        if (emitter[9] != 0) {
          return emitter[9];
        }
        bufferCount = emitter[0xb];
        capacity = emitter[0xc];
        if (capacity < bufferCount + 9U) {
          if (capacity == 0) {
            capacity = 0x10;
          }
          else {
            capacity = capacity << 1;
          }
          for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
          }
          if (*bufferDataPtr == 0) {
            bufferCount = _malloc(capacity << 2);
          }
          else {
            bufferCount = _realloc(*bufferDataPtr,capacity << 2);
          }
          if (bufferCount == 0) goto checkEmitter;
          *bufferDataPtr = bufferCount;
          emitter[0xc] = capacity;
          bufferCount = emitter[0xb];
        }
        emitter[0xb] = bufferCount + 9;
        tokenWritePtr3 = (uint *)(bufferCount * 4 + *bufferDataPtr);
        *tokenWritePtr3 = ilInstBOpcode;
        tokenWritePtr3[1] = ilInstBDst;
        tokenWritePtr3[2] = ilInstBDstMask;
        do {
          tokenWritePtr3[3] = (uint)*recordPtr3;
          recordWordNext4 = recordPtr3 + 3;
          recordPtr3 = recordPtr3 + 1;
          tokenWritePtr3[4] = (uint)*recordWordNext4;
          tokenWritePtr3 = tokenWritePtr3 + 2;
        } while (swizzleSlots != recordPtr3);
      }
    }
    _memset(&ilInstCOpcode,0,0x24);
    ilInstCOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstCOpcode) + 0)),0xd);
    ilInstBOpcode = ilInstBOpcode & 0xc000ffff | 0x30000;
    bufferCount = ((int (*)())fpilTranslateDestination)(emitter,opRecord + 8,&ilInstCDst,&ilInstCDstMask,*(uint *)(opRecord + 4) >> 0x14 & 1);
    if (bufferCount == 0) {
      ilInstCSrc0 = (undefined *)CONCAT22(4,(short)emitter[8] + 1);
      ilInstCSwz0 = ((unsigned char *)0x00003210);
      ilInstCSrc0 = (undefined *)((uint)ilInstCSrc0 | 0x400000);
      bufferCount = ((int (*)())fpilTranslateSource)(emitter,opRecord + 0x10,srcToken,srcSwizzle);
      if (bufferCount == 0) {
        bufferCount = ((int (*)())fpilBuildDestinationToken)(emitter,opRecord + 8,dstTokenHeader,dstMask,0);
        if (bufferCount == 0) {
          composedSwizzle = ((unsigned char *)0x00003210);
          capacity = *(uint *)(opRecord + 8);
          if ((capacity & 0x2000) != 0) {
            ((int (*)())fpilSetComponentSelect)(0,capacity >> 8 & 3,&composedSwizzle);
            capacity = *(uint *)(opRecord + 8);
          }
          if ((capacity & 0x4000) != 0) {
            ((int (*)())fpilSetComponentSelect)(1,capacity >> 6 & 3,&composedSwizzle);
            capacity = *(uint *)(opRecord + 8);
          }
          if ((capacity & 0x8000) != 0) {
            ((int (*)())fpilSetComponentSelect)(2,capacity >> 4 & 3,&composedSwizzle);
            capacity = *(uint *)(opRecord + 8);
          }
          if ((capacity & 0x10000) != 0) {
            ((int (*)())fpilSetComponentSelect)(3,capacity >> 2 & 3,&composedSwizzle);
          }
          bufferCount = emitter[9];
          ilInstCSrc2 = dstRegister | 0x440000;
          ilInstCSwz2 = composedSwizzle;
        }
        else {
          bufferCount = emitter[9];
        }
        if (bufferCount != 0) {
          return bufferCount;
        }
        bufferCount = emitter[0xb];
        capacity = emitter[0xc];
        if (capacity < bufferCount + 9U) {
          if (capacity == 0) {
            capacity = 0x10;
          }
          else {
            capacity = capacity << 1;
          }
          for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
          }
          if (*bufferDataPtr == 0) {
            bufferCount = _malloc(capacity << 2);
          }
          else {
            bufferCount = _realloc(*bufferDataPtr,capacity << 2);
          }
          if (bufferCount == 0) {
checkEmitter:
            if (emitter[9] != 0) {
              return emitter[9];
            }
            emitter[9] = 1;
            return 1;
          }
          *bufferDataPtr = bufferCount;
          emitter[0xc] = capacity;
          bufferCount = emitter[0xb];
        }
        recordPtr2 = (undefined **)&ilInstCSrc0;
        emitter[0xb] = bufferCount + 9;
        tokenWritePtr = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
        *tokenWritePtr = ilInstCOpcode;
        tokenWritePtr[1] = ilInstCDst;
        tokenWritePtr[2] = ilInstCDstMask;
        do {
          tokenWritePtr[3] = *recordPtr2;
          recordWordNext5 = recordPtr2 + 3;
          recordPtr2 = recordPtr2 + 1;
          tokenWritePtr[4] = *recordWordNext5;
          tokenWritePtr = tokenWritePtr + 2;
        } while (&ilInstCSwz0 != recordPtr2);
        return 0;
      }
    }
  }
  return emitter[9];
}

/* fragmentTranslateSel @ 0x457f0 (2412 bytes) */
int fragmentTranslateSel(emitter, recordIndex)
  int *emitter;
  int recordIndex;
{
  uint *tokenWritePtr3;
  undefined **recordWordNext4;
  undefined4 *recordWordNext3;
  undefined4 *recordWordNext;
  undefined **recordWordNext2;
  int bufferCount;
  uint capacity;
  short tempRegister;
  undefined4 *recordPtr;
  uint negate1;
  uint select3;
  uint negate2;
  uint select1;
  undefined4 *srcCursor;
  undefined **swizzleCursor;
  undefined **recordPtr2;
  uint *tokenWritePtr;
  undefined4 *tokenWritePtr2;
  uint *srcRecordPtr;
  int *bufferDataPtr;
  int opRecord;
  uint translatedDst;
  uint translatedDstMask;
  undefined4 translatedSrcToken;
  uint translatedSrcSwizzle;
  undefined4 ilInstAOpcode;
  undefined4 ilInstADst;
  undefined4 ilInstADstMask;
  undefined4 ilInstASrc0;
  undefined4 ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *ilInstASwz0;
  undefined *ilInstASwz1;
  undefined4 ilInstBOpcode;
  undefined4 ilInstBDst;
  uint ilInstBDstMask;
  undefined4 ilInstBSrc0;
  undefined4 ilInstBSrc1;
  undefined4 ilInstBSrc2;
  undefined *ilInstBSwz0;
  uint ilInstBSwz1;
  undefined *ilInstBSwz2;
  
  opRecord = *emitter;
  bufferCount = *(int *)(opRecord + 0x54);
  _memset(&ilInstAOpcode,0,0x24);
  opRecord = opRecord + bufferCount * 8 + recordIndex * 8;
  _memset(&ilInstBOpcode,0,0x24);
  bufferCount = ((int (*)())fpilTranslateDestination)(emitter,opRecord + 8,&translatedDst,&translatedDstMask,*(uint *)(opRecord + 4) >> 0x14 & 1);
  if (bufferCount != 0) {
loopReturnEmitter:
    return emitter[9];
  }
  srcRecordPtr = (uint *)(opRecord + 0x10);
  bufferCount = ((int (*)())fpilTranslateSource)(emitter,srcRecordPtr,&translatedSrcToken,&translatedSrcSwizzle);
  if (bufferCount != 0) goto loopReturnEmitter;
  recordPtr = &ilInstASrc0;
  ilInstADst = CONCAT22(4,(short)emitter[8]);
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x5b);
  ilInstADstMask = 0x55;
  ilInstADst = ilInstADst | 0x400000;
  bufferCount = ((int (*)())fpilTranslateSource)(emitter,opRecord + 0x18,recordPtr,&ilInstASwz0);
  if (bufferCount != 0) goto loopReturnEmitter;
  ilInstASwz1 = ((unsigned char *)0x00005555U);
  ilInstASrc1 = 0x440000;
  if (emitter[9] != 0) {
    return emitter[9];
  }
  bufferDataPtr = emitter + 10;
  bufferCount = emitter[0xb];
  capacity = emitter[0xc];
  if (capacity < bufferCount + 7U) {
    if (capacity == 0) {
      capacity = 0x10;
    }
    else {
      capacity = capacity << 1;
    }
    for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
    }
    if (*bufferDataPtr == 0) {
      bufferCount = _malloc(capacity << 2);
    }
    else {
      bufferCount = _realloc(*bufferDataPtr,capacity << 2);
    }
    if (bufferCount == 0) goto checkEmitter;
    *bufferDataPtr = bufferCount;
    emitter[0xc] = capacity;
    bufferCount = emitter[0xb];
  }
  emitter[0xb] = bufferCount + 7;
  tokenWritePtr2 = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
  *tokenWritePtr2 = ilInstAOpcode;
  tokenWritePtr2[1] = ilInstADst;
  tokenWritePtr2[2] = ilInstADstMask;
  srcCursor = recordPtr;
  do {
    tokenWritePtr2[3] = *srcCursor;
    recordWordNext = srcCursor + 3;
    srcCursor = srcCursor + 1;
    tokenWritePtr2[4] = *recordWordNext;
    tokenWritePtr2 = tokenWritePtr2 + 2;
  } while (&ilInstASrc2 != srcCursor);
  ilInstBOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBOpcode) + 0)),0xd);
  ilInstBOpcode = ilInstBOpcode & 0xc000ffff | 0x20000;
  if ((*srcRecordPtr & 0x3000) == 0x1000) {
    tempRegister = (short)emitter[8];
    ilInstBDst = translatedDst;
    ilInstBDstMask = translatedDstMask;
  }
  else {
    tempRegister = (short)emitter[8];
    ilInstBDst = CONCAT22(4,tempRegister + 1);
    ilInstBDstMask = 0x55;
    ilInstBDst = ilInstBDst | 0x400000;
  }
  select1 = translatedSrcSwizzle >> 4 & 7;
  negate1 = translatedSrcSwizzle >> 7 & 1;
  ilInstBSrc0 = (undefined *)CONCAT22(4,tempRegister);
  capacity = translatedSrcSwizzle >> 3 & 1;
  ilInstBSwz0 = ((unsigned char *)0x00003210);
  ilInstBSrc2 = translatedSrcToken;
  ilInstBSwz2 = (undefined *)
             (capacity << 0xf |
             (translatedSrcSwizzle & 7) << 0xc |
             capacity << 0xb |
             (translatedSrcSwizzle & 7) << 8 | capacity << 7 | (translatedSrcSwizzle & 7) << 4 | translatedSrcSwizzle & 0xffff000f);
  ilInstBSrc1 = translatedSrcToken;
  ilInstBSrc0 = (undefined *)((uint)ilInstBSrc0 | 0x400000);
  ilInstBSwz1 = negate1 << 0xf |
             select1 << 0xc |
             negate1 << 0xb |
             select1 << 8 | negate1 << 7 | select1 << 4 | negate1 << 3 | translatedSrcSwizzle & 0xffff0000 | select1;
  if (emitter[9] != 0) {
    return emitter[9];
  }
  bufferCount = emitter[0xb];
  capacity = emitter[0xc];
  if (capacity < bufferCount + 9U) {
    if (capacity == 0) {
      capacity = 0x10;
    }
    else {
      capacity = capacity << 1;
    }
    for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
    }
    if (*bufferDataPtr == 0) {
      bufferCount = _malloc(capacity << 2);
    }
    else {
      bufferCount = _realloc(*bufferDataPtr,capacity << 2);
    }
    if (bufferCount == 0) goto checkEmitter;
    *bufferDataPtr = bufferCount;
    emitter[0xc] = capacity;
    bufferCount = emitter[0xb];
  }
  recordPtr2 = (undefined **)&ilInstBSrc0;
  emitter[0xb] = bufferCount + 9;
  tokenWritePtr = (uint *)(bufferCount * 4 + *bufferDataPtr);
  *tokenWritePtr = ilInstBOpcode;
  tokenWritePtr[1] = ilInstBDst;
  tokenWritePtr[2] = ilInstBDstMask;
  swizzleCursor = recordPtr2;
  do {
    tokenWritePtr[3] = (uint)*swizzleCursor;
    recordWordNext2 = swizzleCursor + 3;
    swizzleCursor = swizzleCursor + 1;
    tokenWritePtr[4] = (uint)*recordWordNext2;
    tokenWritePtr = tokenWritePtr + 2;
  } while (&ilInstBSwz0 != swizzleCursor);
  if (1 < (*srcRecordPtr >> 0xc & 3)) {
    ilInstASrc0 = CONCAT22(4,(short)emitter[8]);
    ilInstASwz0 = ((unsigned char *)0x00003210);
    ilInstASrc0 = ilInstASrc0 | 0x400000;
    if (emitter[9] != 0) {
      return emitter[9];
    }
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 7U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) goto checkEmitter;
      *bufferDataPtr = bufferCount;
      emitter[0xc] = capacity;
      bufferCount = emitter[0xb];
    }
    emitter[0xb] = bufferCount + 7;
    tokenWritePtr2 = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr2 = ilInstAOpcode;
    tokenWritePtr2[1] = ilInstADst;
    tokenWritePtr2[2] = ilInstADstMask;
    srcCursor = recordPtr;
    do {
      tokenWritePtr2[3] = *srcCursor;
      recordWordNext = srcCursor + 3;
      srcCursor = srcCursor + 1;
      tokenWritePtr2[4] = *recordWordNext;
      tokenWritePtr2 = tokenWritePtr2 + 2;
    } while (&ilInstASrc2 != srcCursor);
    if ((*srcRecordPtr & 0x3000) == 0x2000) {
      ilInstBDst = translatedDst;
      ilInstBDstMask = translatedDstMask;
    }
    capacity = translatedSrcSwizzle >> 8 & 7;
    negate2 = translatedSrcSwizzle >> 0xb & 1;
    ilInstBSrc2 = CONCAT22(4,(short)emitter[8] + 1);
    ilInstBSwz2 = ((unsigned char *)0x00003210);
    ilInstBSrc2 = ilInstBSrc2 | 0x400000;
    ilInstBSwz1 = negate2 << 0xf |
               capacity << 0xc |
               negate2 << 0xb |
               capacity << 8 | negate2 << 7 | capacity << 4 | negate2 << 3 | capacity | ilInstBSwz1 & 0xffff0000;
    if (emitter[9] != 0) {
      return emitter[9];
    }
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) goto checkEmitter;
      *bufferDataPtr = bufferCount;
      emitter[0xc] = capacity;
      bufferCount = emitter[0xb];
    }
    emitter[0xb] = bufferCount + 9;
    tokenWritePtr = (uint *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr = ilInstBOpcode;
    tokenWritePtr[1] = ilInstBDst;
    tokenWritePtr[2] = ilInstBDstMask;
    swizzleCursor = recordPtr2;
    do {
      tokenWritePtr[3] = (uint)*swizzleCursor;
      recordWordNext2 = swizzleCursor + 3;
      swizzleCursor = swizzleCursor + 1;
      tokenWritePtr[4] = (uint)*recordWordNext2;
      tokenWritePtr = tokenWritePtr + 2;
    } while (&ilInstBSwz0 != swizzleCursor);
    if ((*srcRecordPtr & 0x3000) != 0x3000) {
      return 0;
    }
    if (emitter[9] != 0) {
      return emitter[9];
    }
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 7U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 7U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) goto checkEmitter;
      *bufferDataPtr = bufferCount;
      emitter[0xc] = capacity;
      bufferCount = emitter[0xb];
    }
    emitter[0xb] = bufferCount + 7;
    tokenWritePtr2 = (undefined4 *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr2 = ilInstAOpcode;
    tokenWritePtr2[1] = ilInstADst;
    tokenWritePtr2[2] = ilInstADstMask;
    do {
      tokenWritePtr2[3] = *recordPtr;
      recordWordNext3 = recordPtr + 3;
      recordPtr = recordPtr + 1;
      tokenWritePtr2[4] = *recordWordNext3;
      tokenWritePtr2 = tokenWritePtr2 + 2;
    } while (&ilInstASrc2 != recordPtr);
    select3 = translatedSrcSwizzle >> 0xc & 7;
    capacity = translatedSrcSwizzle >> 0xf & 1;
    ilInstBDst = translatedDst;
    ilInstBDstMask = translatedDstMask;
    ilInstBSwz1 = capacity << 0xf |
               select3 << 0xc |
               capacity << 0xb |
               select3 << 8 | capacity << 7 | select3 << 4 | capacity << 3 | select3 | ilInstBSwz1 & 0xffff0000;
    if (emitter[9] != 0) {
      return emitter[9];
    }
    bufferCount = emitter[0xb];
    capacity = emitter[0xc];
    if (capacity < bufferCount + 9U) {
      if (capacity == 0) {
        capacity = 0x10;
      }
      else {
        capacity = capacity << 1;
      }
      for (; capacity < bufferCount + 9U; capacity = capacity << 1) {
      }
      if (*bufferDataPtr == 0) {
        bufferCount = _malloc(capacity << 2);
      }
      else {
        bufferCount = _realloc(*bufferDataPtr,capacity << 2);
      }
      if (bufferCount == 0) {
checkEmitter:
        if (emitter[9] == 0) {
          emitter[9] = 1;
          return 1;
        }
        return emitter[9];
      }
      *bufferDataPtr = bufferCount;
      emitter[0xc] = capacity;
      bufferCount = emitter[0xb];
    }
    emitter[0xb] = bufferCount + 9;
    tokenWritePtr3 = (uint *)(bufferCount * 4 + *bufferDataPtr);
    *tokenWritePtr3 = ilInstBOpcode;
    tokenWritePtr3[1] = ilInstBDst;
    tokenWritePtr3[2] = ilInstBDstMask;
    do {
      tokenWritePtr3[3] = (uint)*recordPtr2;
      recordWordNext4 = recordPtr2 + 3;
      recordPtr2 = recordPtr2 + 1;
      tokenWritePtr3[4] = (uint)*recordWordNext4;
      tokenWritePtr3 = tokenWritePtr3 + 2;
    } while (recordPtr2 != &ilInstBSwz0);
  }
  return 0;
}

/* fragmentTranslateAll @ 0x46180 (1528 bytes) */
int fragmentTranslateAll(translator, slot, componentCount)
  int *translator;
  int slot;
  int componentCount;
{
  uint swizzleNeg1;
  int srcResult;
  int instrWords;
  uint tokenCapacity;
  int tokenCount2;
  int tokenCount;
  undefined4 *recordPtr2;
  undefined4 *recordPtr;
  undefined4 *recordWordNext2;
  int allocation;
  int allocation2;
  undefined4 *recordWordNext;
  bool countFromSlot;
  uint swizzleSel1;
  uint requiredTokenWords;
  int destResult;
  undefined4 *tokenWritePtr;
  undefined4 *srcCursor;
  undefined4 *recordWordNext3;
  int opRecord;
  int *tokenDataPtrAddr;
  undefined4 ilInstAOpcode;
  uint ilInstADst;
  uint ilInstADstMask;
  undefined4 ilInstASrc0;
  uint ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *ilInstASwz0;
  uint ilInstASwz1;
  
  countFromSlot = componentCount == 0;
  opRecord = *translator + *(int *)(*translator + 0x54) * 8;
  _memset(&ilInstAOpcode,0,0x24);
  if (countFromSlot) {
    componentCount = (*(uint *)(slot * 8 + opRecord + 4) >> 0x1a & 3) + 1;
  }
  if (componentCount < 3) {
    if (componentCount == 1) {
      (*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 2)) = 0x47;
    }
    else {
      (*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 2)) = 0x49;
    }
    opRecord = opRecord + slot * 8;
    destResult = ((int (*)())fpilTranslateDestination)(translator,opRecord + 8,&ilInstADst,&ilInstADstMask,1);
    if (destResult != 0) {
loopReturnTranslator:
      return translator[9];
    }
    if (countFromSlot) {
      opRecord = ((int (*)())fpilTranslateSource)(translator,opRecord + 0x10,&ilInstASrc0,&ilInstASwz0);
      if (opRecord != 0) goto loopReturnTranslator;
    }
    else {
      ilInstASrc0 = CONCAT22(4,(short)translator[8]);
      ilInstASwz0 = ((unsigned char *)0x00003210);
      ilInstASrc0 = ilInstASrc0 | 0x400000;
    }
    if (componentCount == 2) {
      ilInstASrc1 = ilInstASrc0;
      ilInstASwz1 = (uint)ilInstASwz0 >> 4 & 8 | (uint)ilInstASwz0 >> 4 & 7 | (uint)ilInstASwz0 & 0xfffffff0;
    }
    if (translator[9] != 0) {
      return translator[9];
    }
    tokenDataPtrAddr = translator + 10;
    tokenCount2 = translator[0xb];
    instrWords = componentCount * 2 + 3;
    tokenCapacity = translator[0xc];
    requiredTokenWords = instrWords + tokenCount2;
    if (tokenCapacity < requiredTokenWords) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < requiredTokenWords; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) goto checkTranslator;
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity;
      tokenCount2 = translator[0xb];
    }
    translator[0xb] = instrWords + tokenCount2;
    tokenWritePtr = (undefined4 *)(tokenCount2 * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = ilInstAOpcode;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    if (0 < componentCount) {
      recordPtr = &ilInstASrc0;
      do {
        tokenWritePtr[3] = *recordPtr;
        recordWordNext3 = recordPtr + 3;
        recordPtr = recordPtr + 1;
        tokenWritePtr[4] = *recordWordNext3;
        tokenWritePtr = tokenWritePtr + 2;
        componentCount = componentCount + -1;
      } while (componentCount != 0);
    }
  }
  else {
    ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x49);
    ilInstADstMask = ilInstADstMask & 0xffffff00 | 0x111;
    ilInstADst = CONCAT22((short)(ilInstADst >> 0x10),(short)translator[8]) & 0xffc0ffff | 0x440000;
    if (countFromSlot) {
      srcResult = ((int (*)())fpilTranslateSource)(translator,opRecord + slot * 8 + 0x10,&ilInstASrc0,&ilInstASwz0);
      if (srcResult != 0) goto loopReturnTranslator;
    }
    else {
      ilInstASrc0 = CONCAT22(4,(short)translator[8]);
      ilInstASwz0 = ((unsigned char *)0x00003210);
      ilInstASrc0 = ilInstASrc0 | 0x400000;
    }
    ilInstASrc1 = ilInstASrc0;
    swizzleSel1 = (uint)ilInstASwz0 >> 4 & 7;
    swizzleNeg1 = (uint)ilInstASwz0 >> 4 & 8;
    if (componentCount == 3) {
      ilInstASwz1 = swizzleNeg1 | swizzleSel1 | (uint)ilInstASwz0 & 0xfffff0f0 | 0x500;
    }
    else {
      ilInstASwz1 = ((uint)ilInstASwz0 & 0xfffff8f0) >> 4 & 0x800 |
                 (uint)ilInstASwz0 >> 4 & 0x700 | swizzleNeg1 | swizzleSel1 | (uint)ilInstASwz0 & 0xfffff0f0;
    }
    if (translator[9] != 0) {
      return translator[9];
    }
    tokenDataPtrAddr = translator + 10;
    tokenCount = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation2 = _malloc(tokenCapacity << 2);
      }
      else {
        allocation2 = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation2 == 0) goto checkTranslator;
      *tokenDataPtrAddr = allocation2;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
    }
    recordPtr2 = &ilInstASrc0;
    translator[0xb] = tokenCount + 7;
    tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = ilInstAOpcode;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    srcCursor = recordPtr2;
    do {
      tokenWritePtr[3] = *srcCursor;
      recordWordNext = srcCursor + 3;
      srcCursor = srcCursor + 1;
      tokenWritePtr[4] = *recordWordNext;
      tokenWritePtr = tokenWritePtr + 2;
    } while (&ilInstASrc2 != srcCursor);
    opRecord = ((int (*)())fpilTranslateDestination)(translator,opRecord + slot * 8 + 8,&ilInstADst,&ilInstADstMask,1);
    if (opRecord != 0) goto loopReturnTranslator;
    ilInstASrc0 = CONCAT22(4,(short)translator[8]);
    ilInstASwz0 = (undefined *)0x0;
    ilInstASwz1 = ilInstASwz1 & 0xfffffff8 | 2;
    ilInstASrc1 = ilInstASrc0 | 0x400000;
    ilInstASrc0 = ilInstASrc0 | 0x400000;
    if (translator[9] != 0) {
      return translator[9];
    }
    tokenCount2 = translator[0xb];
    tokenCapacity = translator[0xc];
    if (tokenCapacity < tokenCount2 + 7U) {
      if (tokenCapacity == 0) {
        tokenCapacity = 0x10;
      }
      else {
        tokenCapacity = tokenCapacity << 1;
      }
      for (; tokenCapacity < tokenCount2 + 7U; tokenCapacity = tokenCapacity << 1) {
      }
      if (*tokenDataPtrAddr == 0) {
        allocation = _malloc(tokenCapacity << 2);
      }
      else {
        allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      }
      if (allocation == 0) {
checkTranslator:
        if (translator[9] != 0) {
          return translator[9];
        }
        translator[9] = 1;
        return 1;
      }
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity;
      tokenCount2 = translator[0xb];
    }
    translator[0xb] = tokenCount2 + 7;
    tokenWritePtr = (undefined4 *)(tokenCount2 * 4 + *tokenDataPtrAddr);
    *tokenWritePtr = ilInstAOpcode;
    tokenWritePtr[1] = ilInstADst;
    tokenWritePtr[2] = ilInstADstMask;
    do {
      tokenWritePtr[3] = *recordPtr2;
      recordWordNext2 = recordPtr2 + 3;
      recordPtr2 = recordPtr2 + 1;
      tokenWritePtr[4] = *recordWordNext2;
      tokenWritePtr = tokenWritePtr + 2;
    } while (recordPtr2 != &ilInstASrc2);
  }
  return 0;
}

/* fragmentTranslateAny @ 0x467a0 (632 bytes) */
int fragmentTranslateAny(translator, slot, useTempSource)
  int *translator;
  int slot;
  int useTempSource;
{
  int srcResult;
  int destResult;
  int tokenCount;
  int translatorError;
  int allocation;
  undefined4 *recordWordNext;
  int opTableOffset;
  uint tokenCapacity;
  undefined2 tempRegister;
  undefined4 *recordPtr;
  undefined4 *tokenWritePtr;
  int *tokenDataPtrAddr;
  int opRecord;
  undefined4 ilInstAOpcode;
  undefined4 ilInstADst;
  undefined4 ilInstADstMask;
  undefined4 ilInstASrc0;
  uint ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *ilInstASwz0;
  uint ilInstASwz1;
  
  opRecord = *translator;
  opTableOffset = *(int *)(opRecord + 0x54);
  _memset(&ilInstAOpcode,0,0x24);
  opRecord = opRecord + opTableOffset * 8 + slot * 8;
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x23);
  destResult = ((int (*)())fpilTranslateDestination)(translator,opRecord + 8,&ilInstADst,&ilInstADstMask,1);
  if (destResult == 0) {
    if (useTempSource == 0) {
      srcResult = ((int (*)())fpilTranslateSource)(translator,opRecord + 0x10,&ilInstASrc0,&ilInstASwz0);
      if (srcResult != 0) goto setTranslatorError;
      tempRegister = (undefined2)translator[8];
    }
    else {
      tempRegister = (undefined2)translator[8];
      ilInstASrc0 = CONCAT22(4,tempRegister);
      ilInstASwz0 = ((unsigned char *)0x00003210);
      ilInstASrc0 = ilInstASrc0 | 0x400000;
    }
    translatorError = translator[9];
    ilInstASwz1 = ilInstASwz1 & 0xffff0000 | 0x5555;
    ilInstASrc1 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc1) + 0)),tempRegister) & 0xffc0ffff | 0x440000;
    if (translatorError == 0) {
      tokenDataPtrAddr = translator + 10;
      tokenCount = translator[0xb];
      tokenCapacity = translator[0xc];
      if (tokenCapacity < tokenCount + 7U) {
        if (tokenCapacity == 0) {
          tokenCapacity = 0x10;
        }
        else {
          tokenCapacity = tokenCapacity << 1;
        }
        for (; tokenCapacity < tokenCount + 7U; tokenCapacity = tokenCapacity << 1) {
        }
        if (*tokenDataPtrAddr == 0) {
          allocation = _malloc(tokenCapacity << 2);
        }
        else {
          allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
        }
        if (allocation == 0) {
          if (translator[9] != 0) {
            return translator[9];
          }
          translator[9] = 1;
          return 1;
        }
        *tokenDataPtrAddr = allocation;
        translator[0xc] = tokenCapacity;
        tokenCount = translator[0xb];
      }
      recordPtr = &ilInstASrc0;
      translator[0xb] = tokenCount + 7;
      tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
      *tokenWritePtr = ilInstAOpcode;
      tokenWritePtr[1] = ilInstADst;
      tokenWritePtr[2] = ilInstADstMask;
      do {
        tokenWritePtr[3] = *recordPtr;
        recordWordNext = recordPtr + 3;
        recordPtr = recordPtr + 1;
        tokenWritePtr[4] = *recordWordNext;
        tokenWritePtr = tokenWritePtr + 2;
      } while (&ilInstASrc2 != recordPtr);
      translatorError = 0;
    }
  }
  else {
setTranslatorError:
    translatorError = translator[9];
  }
  return translatorError;
}

/* fragmentTranslateArithmetic @ 0x46a30 (1080 bytes) */
int fragmentTranslateArithmetic(translator, slot)
  int *translator;
  int slot;
{
  int copyCount;
  int srcResult;
  int destResult;
  int opcodeTableOffset;
  int allocationB;
  uint tokenCapacity2;
  uint tokenCapacity;
  int tokenCount2;
  int allocation;
  uint *recordWordNext;
  int tokenCount;
  uint *recordPtr;
  uint *tokenWritePtr;
  uint src0Flag;
  uint src1Flag;
  uint replicateFlag;
  int copyIndex;
  uint opcodeIndex;
  uint extraCopies;
  int opTableBase;
  int opRecord;
  int *tokenDataPtrAddr;
  undefined4 ilInstAOpcode;
  undefined4 ilInstADst;
  uint ilInstADstMask;
  undefined4 ilInstASrc0;
  undefined1 ilInstASrc1 [2];
  short ilInstASrc1Hi;
  uint ilInstASrc2;
  uint ilInstASwz0;
  undefined1 ilInstASwz1 [32];
  
  opTableBase = *translator + *(int *)(*translator + 0x54) * 8;
  _memset(&ilInstAOpcode,0,0x24);
  opRecord = opTableBase + slot * 8;
  opcodeIndex = *(uint *)(opTableBase + slot * 8) >> 0x12 & 0xff;
  if ((translator[5] & 0x20000000U) == 0) {
    replicateFlag = 0;
    src0Flag = 0;
    src1Flag = 0;
    extraCopies = 3;
  }
  else {
    replicateFlag = *(uint *)(opRecord + 4) >> 0x1c & 1;
    src0Flag = *(uint *)(opRecord + 0x10) >> 0xe & 1;
    src1Flag = *(uint *)(opRecord + 0x18) >> 0xe & 1;
    extraCopies = *(uint *)(opRecord + 4) >> 0x1a & 3;
  }
  opcodeTableOffset = opcodeIndex * 0x10;
  ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),(short)(*(uint *)(&fragmentOpcodeInfoTable_001dac34 + opcodeTableOffset) >> 1));
  ilInstAOpcode = (*(uint *)(&fragmentOpcodeInfoTable_word1_001dac38 + opcodeTableOffset) >> 0x13) << 0x10 | ilInstAOpcode & 0xc000ffff;
  destResult = ((int (*)())fpilTranslateDestination)(translator,opRecord + 8,&ilInstADst,&ilInstADstMask,*(uint *)(opRecord + 4) >> 0x14 & 1);
  if (destResult == 0) {
    srcResult = ((int (*)())fpilTranslateSource)(translator,opRecord + 0x10,&ilInstASrc0,&ilInstASwz0);
    if ((srcResult == 0) &&
       (srcResult = ((int (*)())fpilTranslateSource)(translator,opRecord + 0x18,ilInstASrc1,ilInstASwz1), srcResult == 0)) {
      if (replicateFlag == 0) {
        copyCount = 1;
      }
      else {
        copyCount = extraCopies + 1;
        if (copyCount == 0) {
loopCheckTranslator:
          if ((((translator[5] & 0x20000000U) == 0) || (opcodeIndex != 0x3a)) ||
             (copyCount = ((int (*)())fpilClassifyDestination)(translator,opRecord + 8), copyCount != 1)) {
            return 0;
          }
          ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),99);
          ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstADst) + 2)));
          ilInstASwz0 = ilInstASwz0 & 0xffff0000 | 0x3210;
          ilInstASrc0 = (ilInstADst >> 0x10 & 0x3f) << 0x10 | ilInstASrc0 & 0xffc0ffff;
          ilInstAOpcode = ilInstAOpcode & 0xc000ffff;
          if (translator[9] != 0) {
            return translator[9];
          }
          tokenDataPtrAddr = translator + 10;
          tokenCount2 = translator[0xb];
          tokenCapacity = translator[0xc];
          if (tokenCapacity < tokenCount2 + 5U) {
            if (tokenCapacity == 0) {
              tokenCapacity = 0x10;
            }
            else {
              tokenCapacity = tokenCapacity << 1;
            }
            for (; tokenCapacity < tokenCount2 + 5U; tokenCapacity = tokenCapacity << 1) {
            }
            if (*tokenDataPtrAddr == 0) {
              allocationB = _malloc(tokenCapacity << 2);
            }
            else {
              allocationB = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
            }
            if (allocationB == 0) {
loopCheckTranslator2:
              if (translator[9] != 0) {
                return translator[9];
              }
              translator[9] = 1;
              return 1;
            }
            *tokenDataPtrAddr = allocationB;
            translator[0xc] = tokenCapacity;
            tokenCount2 = translator[0xb];
          }
          translator[0xb] = tokenCount2 + 5;
          tokenWritePtr = (uint *)(tokenCount2 * 4 + *tokenDataPtrAddr);
          *tokenWritePtr = ilInstAOpcode;
          tokenWritePtr[1] = ilInstADst;
          tokenWritePtr[2] = ilInstADstMask;
          tokenWritePtr[3] = ilInstASrc0;
          tokenWritePtr[4] = ilInstASwz0;
          return 0;
        }
      }
      if (translator[9] != 0) {
        return translator[9];
      }
      copyIndex = 0;
      tokenDataPtrAddr = translator + 10;
      do {
        tokenCount = translator[0xb];
        tokenCapacity2 = translator[0xc];
        if (tokenCapacity2 < tokenCount + 7U) {
          if (tokenCapacity2 == 0) {
            tokenCapacity2 = 0x10;
          }
          else {
            tokenCapacity2 = tokenCapacity2 << 1;
          }
          for (; tokenCapacity2 < tokenCount + 7U; tokenCapacity2 = tokenCapacity2 << 1) {
          }
          if (*tokenDataPtrAddr == 0) {
            allocation = _malloc(tokenCapacity2 << 2);
          }
          else {
            allocation = _realloc(*tokenDataPtrAddr,tokenCapacity2 << 2);
          }
          if (allocation == 0) goto loopCheckTranslator2;
          *tokenDataPtrAddr = allocation;
          translator[0xc] = tokenCapacity2;
          tokenCount = translator[0xb];
        }
        translator[0xb] = tokenCount + 7;
        tokenWritePtr = (uint *)(tokenCount * 4 + *tokenDataPtrAddr);
        *tokenWritePtr = ilInstAOpcode;
        tokenWritePtr[1] = ilInstADst;
        tokenWritePtr[2] = ilInstADstMask;
        recordPtr = &ilInstASrc0;
        do {
          tokenWritePtr[3] = *recordPtr;
          recordWordNext = recordPtr + 3;
          recordPtr = recordPtr + 1;
          tokenWritePtr[4] = *recordWordNext;
          tokenWritePtr = tokenWritePtr + 2;
        } while (recordPtr != &ilInstASrc2);
        if (replicateFlag != 0) {
          ilInstADst = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstADst) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstADst) + 2)) + 1);
        }
        if (src0Flag != 0) {
          ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 2)) + 1);
        }
        if (src1Flag != 0) {
          ilInstASrc1Hi = ilInstASrc1Hi + 1;
        }
        copyIndex = copyIndex + 1;
        if (copyCount == copyIndex) goto loopCheckTranslator;
        if (translator[9] != 0) {
          return translator[9];
        }
      } while( true );
    }
  }
  return translator[9];
}

/* fragmentInstructionToIL @ 0x46e90 (7800 bytes) */
int fragmentInstructionToIL(translator, unusedArg2, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7, unusedArg8)
  int *translator;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
{
  int maxRegSpan;
  int regSpan;
  int programPtr;
  int instructionBlock2;
  int instBlockOffset;
  int newTempBase;
  int arraySourceCount;
  int tempRegBase;
  int srcWordOffset;
  int srcSwizzleStatus;
  int tokenWordCount;
  int instructionBlock;
  int instructionBlock4;
  bool advanceSrc0;
  bool moreTemps;
  bool moreSources;
  short tempRegisterBase;
  undefined2 ilSelectOpcode;
  undefined4 emittedSourceCount;
  uint *src1OperandPtr;
  uint *src0OperandPtr;
  uint *dstOutPair;
  uint opcodeInfoWord1;
  int srcStatus3;
  int emitStatus3;
  int srcStatus2;
  int emitStatus2;
  int emitStatus;
  int reserveStatus;
  int callStatus;
  int srcStatus;
  int dstStatus;
  int constStatus;
  uint opcode;
  int opcodeInfoOffset;
  int instructionBlockOffset;
  int recordByteOffset;
  uint operandCount;
  bool isScalarForm;
  bool maskBitSet;
  bool advanceSrc1;
  short tempRegisterIndex;
  uint dstMaskHigh;
  int program;
  int componentCount;
  int componentIndex;
  int destClass;
  int callStatus2;
  uint opcodeInfoWord0;
  int returnCode;
  undefined4 saturate;
  undefined2 tempRegisterHalf;
  uint swizzleNegate;
  uint dstMaskLow2;
  uint select2;
  uint select1;
  undefined *adjustedSwizzle;
  uint opClass;
  uint negateBit;
  uint savedDstToken2;
  uint savedOpcodeWord;
  uint savedDstWord;
  uint recordWord1;
  uint srcIndex;
  uint dstFlagWord;
  uint srcModeBits;
  uint opcode2;
  int tempRegister;
  int recordSpan;
  int instructionCount;
  int instructionIndex;
  int recordIndex;
  uint *currentRecord;
  uint *instructionRecords;
  uint *sourceRecordCursor;
  uint savedOpcodeWord2;
  uint select3;
  uint componentCode;
  uint savedDstMask2;
  int opRecordOrSrcStatus;
  int tempWordOffset;
  int componentLoopIndex;
  int opRecordCopy;
  int hasSecondSource;
  int destPtrOrDestStatus;
  int opRecord2;
  int tempIndex;
  int opRecord;
  undefined4 *srcOutCursor;
  uint *src0Operand;
  uint dstToken;
  uint dstMask;
  uint srcToken;
  uint srcSwizzle;
  uint dstToken2;
  uint dstMask2;
  uint *reservedTokens;
  undefined4 tempWord0;
  uint tempWord1;
  uint tempWord2;
  uint tempWord3;
  uint tempWord4;
  uint tempWord5;
  undefined4 ilInstBOpcode;
  undefined4 ilInstBDst;
  uint ilInstBDstMask;
  undefined4 ilInstBSrc0;
  undefined4 ilInstBSrc1;
  undefined *ilInstBSwz0;
  undefined *ilInstBSwz12 [2];
  undefined4 ilInstAOpcode;
  undefined4 ilInstADst;
  uint ilInstADstMask;
  undefined4 ilInstASrc0;
  undefined4 ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *ilInstASwz0;
  undefined *ilInstASwz1;
  undefined *ilInstASwz2;
  int src1RegSpan;
  int src0RegSpan;
  int dstRegSpan;
  uint src1Advances;
  uint src0Advances;
  uint *instHeader;
  uint savedDstCopy;
  uint savedWord1Copy;
  uint savedDstToken;
  uint savedDstMask;
  undefined4 *ilInstBPtr;
  undefined4 *ilInstAPtr;
  
  program = *translator;
  instructionCount = *(int *)(program + 0x50);
  instructionBlockOffset = *(int *)(program + 0x54) * 8;
  instructionRecords = (uint *)(program + instructionBlockOffset);
  if (instructionCount < 1) {
loopReturnCode:
    returnCode = 0;
  }
  else {
    opcode = *(uint *)(program + instructionBlockOffset) >> 0x12 & 0xff;
    opcodeInfoOffset = opcode * 0x10;
    opClass = *(uint *)(&fragmentOpcodeInfoTable_001dac34 + opcodeInfoOffset) >> 0x11 & 0xf;
    if ((opClass != 0) && ((*(uint *)(&fragmentOpcodeInfoTable_word3_001dac40 + opcodeInfoOffset) >> 0x1c & DAT_001db344) == 0)) {
      instructionIndex = 0;
      recordIndex = 0;
      recordByteOffset = 0;
      currentRecord = instructionRecords;
      do {
        operandCount = *currentRecord >> 0x1d;
        recordSpan = operandCount + 2;
        if (opClass == 2) {
          instructionBlock = *translator + *(int *)(*translator + 0x54) * 8;
          opcode2 = *(uint *)(recordByteOffset + instructionBlock) >> 0x12 & 0xff;
          if ((opcode2 - 0x44 < 2) || (hasSecondSource = 0, opcode2 == 0x47)) {
            hasSecondSource = 1;
          }
          if (((opcode2 == 0x43) || (opcode2 == 0x45)) || (isScalarForm = false, opcode2 == 0x47)) {
            isScalarForm = true;
          }
          ilInstAPtr = &ilInstAOpcode;
          opRecord = instructionBlock + recordByteOffset;
          _memset(ilInstAPtr,0,0x24);
          ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),(short)(*(uint *)(&fragmentOpcodeInfoTable_001dac34 + opcode2 * 0x10) >> 1))
          ;
          ((int (*)())fpilTranslateDestination)(translator,opRecord + 8,&ilInstADst,&ilInstADstMask,
                       *(uint *)(recordByteOffset + instructionBlock + 4) >> 0x14 & 1);
          ((int (*)())fpilTranslateSource)(translator,opRecord + 0x10,&ilInstASrc0,&ilInstASwz0);
          if ((translator[5] & 0x20000000U) == 0) {
            ilInstAOpcode = (*(uint *)(opRecord + 0x18) & 0x1f) << 0x10 | ilInstAOpcode & 0xc000ffff;
            srcModeBits = *(uint *)(opRecord + 0x18) >> 5 & 7;
            if (hasSecondSource != 0) {
              ilInstASrc1 = ilInstASrc0;
              ilInstASwz1 = ilInstASwz0;
            }
          }
          else {
            reservedTokens = (uint *)0x0;
            constStatus = ((int (*)())fpilMapConstantRegister)(translator,recordIndex,&reservedTokens);
            if (constStatus != 0) goto checkTranslator;
            ilInstAOpcode = ((uint)reservedTokens & 0x3fff) << 0x10 | ilInstAOpcode & 0xc000ffff;
            srcModeBits = *(uint *)(opRecord + 0x20) >> 5 & 7;
            if (hasSecondSource != 0) {
              ((int (*)())fpilTranslateSource)(translator,opRecord + 0x28,&ilInstASrc1,&ilInstASwz1);
              swizzleNegate = (uint)ilInstASwz1 >> 3 & 1;
              ilInstASwz1 = (undefined *)
                         (swizzleNegate << 0xf |
                         ((uint)ilInstASwz1 & 7) << 0xc |
                         swizzleNegate << 0xb |
                         ((uint)ilInstASwz1 & 7) << 8 |
                         swizzleNegate << 7 | ((uint)ilInstASwz1 & 7) << 4 | (uint)ilInstASwz1 & 0xffff000f);
            }
          }
          if (srcModeBits - 5 < 3) {
            ilInstAOpcode = ilInstAOpcode & 0xf3ffffff | 0x4000000;
          }
          adjustedSwizzle = ilInstASwz0;
          if ((isScalarForm) &&
             (adjustedSwizzle = (undefined *)((uint)ilInstASwz0 & 0xff1fffff | 0x600000),
             ((uint)ilInstASwz0 & 0x8000) != 0)) {
            adjustedSwizzle = (undefined *)
                      (((uint)ilInstASwz0 & 0xff1ff777 ^ 0x8000) & 0x8000 |
                      ((uint)ilInstASwz0 & 0xff1fff77 ^ 0x800) & 0x800 |
                      ((uint)ilInstASwz0 & 0xff1ffff7 ^ 0x80) & 0x80 |
                      ((uint)adjustedSwizzle ^ 8) & 8 | (uint)ilInstASwz0 & 0xff1f7777 | 0x600000);
          }
          ilInstASwz0 = adjustedSwizzle;
          ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,hasSecondSource + 1);
loopCheckOpcode:
          if (opcode != 0x4d) {
loopCheckOpcodeInfoOffset:
            if ((((*(uint *)(&fragmentOpcodeInfoTable_001dac34 + opcodeInfoOffset) >> 0x11 & 0xf) != 3) &&
                ((translator[5] & 0x20000000U) != 0)) &&
               (((((dstFlagWord = *(uint *)((int)instructionRecords + recordByteOffset + 8), (dstFlagWord & 0x2000) != 0 &&
                   ((dstFlagWord & 0x300) != 0)) ||
                  (((dstFlagWord & 0x4000) != 0 && ((dstFlagWord & 0xc0) != 0x40)))) ||
                 (((dstFlagWord & 0x8000) != 0 && ((dstFlagWord & 0x30) != 0x20)))) ||
                (((dstFlagWord & 0x10000) != 0 && ((dstFlagWord & 0xc) != 0xc)))))) {
              ((int (*)())fpilEmitMoveFromTemp)(translator,(int)instructionRecords + recordByteOffset + 8,currentRecord[1] >> 0x14 & 1);
            }
          }
        }
        else {
          if (opClass != 7) {
            if (opClass == 5) {
              ilInstBPtr = &ilInstBOpcode;
              _memset(ilInstBPtr,0,0x24);
              ilInstBOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBOpcode) + 0)),(short)(*(uint *)(&fragmentOpcodeInfoTable_001dac34 + opcodeInfoOffset) >> 1));
              ilInstBOpcode = (*(uint *)(&fragmentOpcodeInfoTable_word1_001dac38 + opcodeInfoOffset) >> 0x13) << 0x10 | ilInstBOpcode & 0xc000ffff;
              if ((*(uint *)(&fragmentOpcodeInfoTable_word3_001dac40 + opcodeInfoOffset) >> 0x1c & 2) == 0) {
                if (((currentRecord[1] & 0x100000) != 0) ||
                   (saturate = 0, (*(uint *)(&fragmentOpcodeInfoTable_word3_001dac40 + opcodeInfoOffset) >> 0x1c & 1) != 0)) {
                  saturate = 1;
                }
                ((int (*)())fpilTranslateDestination)(translator,(int)instructionRecords + recordByteOffset + 8,&ilInstBDst,&ilInstBDstMask,saturate);
              }
              if (operandCount != 0) {
                srcIndex = 0;
                srcOutCursor = &ilInstBSrc0;
                sourceRecordCursor = instructionRecords + recordIndex * 2 + 4;
                do {
                  srcIndex = srcIndex + 1;
                  ((int (*)())fpilTranslateSource)(translator,sourceRecordCursor,srcOutCursor,srcOutCursor + 3);
                  srcOutCursor = srcOutCursor + 1;
                  sourceRecordCursor = sourceRecordCursor + 2;
                } while (operandCount != srcIndex);
              }
              (**(code **)(&fragmentOpcodeInfoTable_handler_001dac3c + opcodeInfoOffset))(translator,recordIndex,ilInstBPtr);
checkTranslator:
              if (translator[9] != 0) {
                return translator[9];
              }
            }
            else {
              opcodeInfoWord0 = *(uint *)(&fragmentOpcodeInfoTable_001dac34 + opcodeInfoOffset);
              opcodeInfoWord1 = *(uint *)(&fragmentOpcodeInfoTable_word1_001dac38 + opcodeInfoOffset);
              if (opClass == 4) {
                operandCount = operandCount - 1;
              }
              tokenWordCount = operandCount * 2 + 1;
              if (opClass != 3) {
                tokenWordCount = operandCount * 2 + 3;
              }
              tokenWordCount = ((int (*)())fpilReserveTokens)(translator,tokenWordCount,&reservedTokens);
              if (tokenWordCount != 0) goto loopReturnTranslator;
              *reservedTokens = (opcodeInfoWord1 >> 0x13) << 0x10 | opcodeInfoWord0 >> 1 & 0xffff;
              if ((*(uint *)(&fragmentOpcodeInfoTable_001dac34 + opcodeInfoOffset) >> 0x11 & 0xf) != 3) {
                if (((currentRecord[1] & 0x100000) != 0) ||
                   (saturate = 0, (*(uint *)(&fragmentOpcodeInfoTable_word3_001dac40 + opcodeInfoOffset) & 0x10000000) != 0)) {
                  saturate = 1;
                }
                dstStatus = ((int (*)())fpilTranslateDestination)(translator,(int)instructionRecords + recordByteOffset + 8,&dstToken,&dstMask,saturate);
                if (dstStatus != 0) goto loopReturnTranslator;
                reservedTokens[1] = dstToken;
                reservedTokens[2] = dstMask;
              }
              if ((*(uint *)(&fragmentOpcodeInfoTable_001dac34 + opcodeInfoOffset) >> 0x11 & 0xf) == 4) {
                srcSwizzleStatus = ((int (*)())fpilTranslateSourceWithSwizzle)(translator,(int)instructionRecords + recordByteOffset + 0x10,&srcToken,&srcSwizzle,
                                     (int)instructionRecords + recordByteOffset + 0x18);
              }
              else {
                srcSwizzleStatus = ((int (*)())fpilTranslateSource)(translator,(int)instructionRecords + recordByteOffset + 0x10,&srcToken,&srcSwizzle);
              }
              if (srcSwizzleStatus != 0) goto loopReturnTranslator;
              opClass = *(uint *)(&fragmentOpcodeInfoTable_001dac34 + opcodeInfoOffset) >> 0x11 & 0xf;
              if (opClass == 6) {
                srcSwizzle = srcSwizzle & 0xffff0fff | 0x5000;
              }
              if (opClass == 3) {
                reservedTokens[1] = srcToken;
                reservedTokens[2] = srcSwizzle;
              }
              else {
                reservedTokens[3] = srcToken;
                reservedTokens[4] = srcSwizzle;
              }
              if (1 < (int)operandCount) {
                srcStatus = ((int (*)())fpilTranslateSource)(translator,(int)instructionRecords + recordByteOffset + 0x18,&srcToken,&srcSwizzle);
                if (srcStatus != 0) goto loopReturnTranslator;
                reservedTokens[5] = srcToken;
                reservedTokens[6] = srcSwizzle;
                if (2 < (int)operandCount) {
                  srcStatus = ((int (*)())fpilTranslateSource)(translator,(int)instructionRecords + recordByteOffset + 0x20,&srcToken,&srcSwizzle);
                  if (srcStatus != 0) goto loopReturnTranslator;
                  reservedTokens[7] = srcToken;
                  reservedTokens[8] = srcSwizzle;
                }
              }
            }
            goto loopCheckOpcode;
          }
          if (opcode == 0) {
            ilInstAPtr = &ilInstAOpcode;
            opRecord = *translator + *(int *)(*translator + 0x54) * 8;
            _memset(ilInstAPtr,0,0x24);
            opRecordCopy = recordByteOffset + opRecord;
            opRecord = opRecord + recordByteOffset;
            ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x47);
            callStatus = ((int (*)())fpilTranslateDestination)(translator,opRecord + 8,&ilInstADst,&ilInstADstMask,
                                 *(uint *)(opRecordCopy + 4) >> 0x14 & 1);
            if ((callStatus == 0) &&
               (callStatus = ((int (*)())fpilTranslateSource)(translator,opRecord + 0x10,&ilInstASrc0,&ilInstASwz0), callStatus == 0)) {
              if (((translator[5] & 0x20000000U) == 0) ||
                 (recordWord1 = *(uint *)(opRecordCopy + 4), (recordWord1 & 0x10000000) == 0)) {
                componentCount = 1;
              }
              else {
                componentCount = (recordWord1 >> 0x1a & 3) + 1;
                if (componentCount == 0) goto loopCheckOpcodeInfoOffset;
              }
              componentLoopIndex = 0;
              do {
                emitStatus3 = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,1);
                if (emitStatus3 != 0) goto loopCheckTranslator;
                componentLoopIndex = componentLoopIndex + 1;
                ilInstADst = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstADst) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstADst) + 2)) + 1);
                ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 2)) + 1);
              } while (componentCount != componentLoopIndex);
              goto loopCheckOpcodeInfoOffset;
            }
loopCheckTranslator:
            if (translator[9] != 0) {
              return translator[9];
            }
            goto loopCheckOpcodeInfoOffset;
          }
          if (opcode == 0x40) {
            instructionBlock2 = *translator + *(int *)(*translator + 0x54) * 8;
            dstStatus = ((int (*)())fpilTranslateDestination)(translator,instructionBlock2 + recordByteOffset + 8,&dstToken2,&dstMask2,
                                 *(uint *)(recordByteOffset + instructionBlock2 + 4) >> 0x14 & 1);
            if (dstStatus == 0) {
              ilInstAPtr = &ilInstAOpcode;
              srcWordOffset = 0;
              instructionBlock2 = recordIndex * 8 + instructionBlock2 + 0x10;
              do {
                srcStatus3 = ((int (*)())fpilTranslateSource)(translator,instructionBlock2,srcWordOffset + (int)ilInstAPtr,(int)&tempWord3 + srcWordOffset);
                if (srcStatus3 != 0) goto loopCheckTranslator;
                moreSources = srcWordOffset != 8;
                instructionBlock2 = instructionBlock2 + 8;
                srcWordOffset = srcWordOffset + 4;
              } while (moreSources);
              tempRegBase = translator[8];
              tempIndex = 0;
              tempWordOffset = 0;
              ilInstBPtr = &ilInstBOpcode;
              dstOutPair = &dstToken;
              do {
                tempRegisterIndex = (short)tempRegBase + (short)tempIndex;
                moreTemps = tempIndex != 2;
                tempIndex = tempIndex + 1;
                *(undefined4 *)(tempWordOffset + (int)ilInstBPtr) = 0;
                dstOutPair[0xd] = dstOutPair[0xd] & 0xffc0ffff | 0x40000;
                *(short *)((int)dstOutPair + 0x36) = tempRegisterIndex;
                *(undefined4 *)((int)&tempWord0 + tempWordOffset) = 0;
                tempWordOffset = tempWordOffset + 4;
                dstOutPair[7] = dstOutPair[7] & 0xffc0ffff | 0x40000;
                *(short *)((int)dstOutPair + 0x1e) = tempRegisterIndex;
                dstOutPair[7] = dstOutPair[7] | 0x400000;
                dstOutPair = dstOutPair + 1;
              } while (moreTemps);
              reserveStatus = ((int (*)())fpilReserveTokens)(translator,7,&reservedTokens);
              savedDstWord = tempWord0;
              if (reserveStatus == 0) {
                *reservedTokens = 0x5b;
                reservedTokens[1] = tempWord0;
                reservedTokens[2] = dstMask2;
                reservedTokens[3] = ilInstADstMask;
                reservedTokens[4] = tempWord5;
                reservedTokens[5] = ilInstAOpcode;
                reservedTokens[6] = tempWord3;
                reserveStatus = ((int (*)())fpilReserveTokens)(translator,7,&reservedTokens);
                if (reserveStatus == 0) {
                  *reservedTokens = 0x5b;
                  savedWord1Copy = tempWord1;
                  reservedTokens[1] = tempWord1;
                  reservedTokens[2] = dstMask2;
                  reservedTokens[3] = ilInstADst;
                  reservedTokens[4] = tempWord4;
                  reservedTokens[5] = ilInstAOpcode;
                  reservedTokens[6] = tempWord3;
                  dstMask2 = dstMask2 | 0x100;
                  reserveStatus = ((int (*)())fpilReserveTokens)(translator,5,&reservedTokens);
                  savedOpcodeWord2 = ilInstBOpcode;
                  if (reserveStatus == 0) {
                    *reservedTokens = 0x20;
                    reservedTokens[1] = savedDstWord;
                    reservedTokens[2] = dstMask2;
                    reservedTokens[3] = ilInstBOpcode;
                    savedDstCopy = ilInstBDst;
                    reservedTokens[4] = ilInstBDst;
                    dstMask2 = dstMask2 & 0xfffffeff;
                    reserveStatus = ((int (*)())fpilReserveTokens)(translator,5,&reservedTokens);
                    if (reserveStatus == 0) {
                      *reservedTokens = 3;
                      reservedTokens[1] = savedWord1Copy;
                      reservedTokens[2] = dstMask2;
                      reservedTokens[3] = savedOpcodeWord2;
                      reservedTokens[4] = savedOpcodeWord2;
                      reserveStatus = ((int (*)())fpilReserveTokens)(translator,5,&reservedTokens);
                      if (reserveStatus == 0) {
                        *reservedTokens = 0x49;
                        reservedTokens[1] = savedDstWord;
                        reservedTokens[2] = dstMask2;
                        reservedTokens[3] = savedOpcodeWord2;
                        reservedTokens[4] = savedOpcodeWord2;
                        reserveStatus = ((int (*)())fpilReserveTokens)(translator,5,&reservedTokens);
                        savedOpcodeWord = ilInstBOpcode;
                        if (reserveStatus == 0) {
                          *reservedTokens = 0x49;
                          reservedTokens[1] = savedWord1Copy;
                          reservedTokens[2] = dstMask2;
                          reservedTokens[3] = savedOpcodeWord2;
                          reservedTokens[4] = savedDstCopy;
                          reserveStatus = ((int (*)())fpilReserveTokens)(translator,7,&reservedTokens);
                          if (reserveStatus == 0) {
                            *reservedTokens = 0x23;
                            reservedTokens[1] = tempWord2;
                            reservedTokens[2] = dstMask2;
                            reservedTokens[3] = savedOpcodeWord | 0x400000;
                            reservedTokens[4] = (uint)((unsigned char *)0x00004555);
                            reservedTokens[5] = savedOpcodeWord | 0x400000;
                            reservedTokens[6] = (uint)((unsigned char *)0x00004555);
                            ilInstBDst = ilInstBDst | 0x400000;
                            reserveStatus = ((int (*)())fpilReserveTokens)(translator,7,&reservedTokens);
                            if (reserveStatus == 0) {
                              *reservedTokens = 0x40;
                              reservedTokens[1] = dstToken2;
                              reservedTokens[2] = dstMask2;
                              reservedTokens[3] = ilInstBOpcode;
                              reservedTokens[4] = ilInstBDstMask;
                              reservedTokens[5] = ilInstBDst;
                              reservedTokens[6] = 0xba98;
                              goto loopCheckOpcodeInfoOffset;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            goto loopCheckTranslator;
          }
          if (opcode == 0x22) {
            instructionBlock2 = *translator + *(int *)(*translator + 0x54) * 8;
            opRecord2 = instructionBlock2 + recordByteOffset;
            src0OperandPtr = (uint *)(opRecord2 + 0x10);
            arraySourceCount = (*(uint *)(opRecord2 + 0x10) >> 0xe & 1) + (*(uint *)(opRecord2 + 0x18) >> 0xe & 1);
            if ((arraySourceCount == 1) &&
               (((*(uint *)(opRecord2 + 0x10) & 0x3000) == 0 ||
                ((*(uint *)(opRecord2 + 0x18) & 0x3000) == 0)))) {
              callStatus2 = ((int (*)())fragmentTranslateArithmetic)(translator,recordIndex);
              goto joined_r0x00048448;
            }
            ilInstBPtr = &ilInstBOpcode;
            _memset(ilInstBPtr,0,0x24);
            ilInstBOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBOpcode) + 0)),0x49);
            instructionBlock2 = ((int (*)())fpilTranslateDestination)(translator,opRecord2 + 8,&ilInstBDst,&ilInstBDstMask,
                                  *(uint *)(recordByteOffset + instructionBlock2 + 4) >> 0x14 & 1);
            if (((instructionBlock2 != 0) ||
                (instructionBlock2 = ((int (*)())fpilTranslateSource)(translator,src0OperandPtr,&ilInstBSrc0,&ilInstBSwz0), instructionBlock2 != 0)) ||
               (instructionBlock2 = ((int (*)())fpilTranslateSource)(translator,(uint *)(opRecord2 + 0x18),&ilInstBSrc1,ilInstBSwz12),
               savedDstMask2 = ilInstBDstMask, savedDstToken2 = ilInstBDst, instructionBlock2 != 0)) {
loopSetCallStatus2:
              callStatus2 = translator[9];
              goto joined_r0x00048448;
            }
            if (arraySourceCount == 0) {
              emitStatus = ((int (*)())fpilEmitInstruction)(translator,ilInstBPtr,1,2);
joined_r0x000479e8:
              if (emitStatus != 0) goto loopSetCallStatus2;
            }
            else if (arraySourceCount != 1) {
              tempRegisterHalf = (undefined2)translator[8];
              ilInstBDst = CONCAT22(4,tempRegisterHalf);
              savedDstToken = savedDstToken2;
              regSpan = (*src0OperandPtr >> 0xc & 3) + 1;
              newTempBase = regSpan + translator[8];
              savedDstMask = ilInstBDstMask;
              translator[8] = newTempBase;
              ilInstBDstMask = 0x55;
              ilInstBDst = ilInstBDst | 0x400000;
              if (regSpan != 0) {
                ilInstAPtr = &ilInstAOpcode;
                componentIndex = 0;
                do {
                  componentCode = *src0OperandPtr >> 0xc & 3;
                  _memcpy(ilInstAPtr,ilInstBPtr,0x24);
                  tempRegister = translator[8];
                  negateBit = (uint)ilInstBSwz12[0] >> 3 & 1;
                  ilInstADst = CONCAT22(4,(short)tempRegister);
                  ilInstADstMask = 0x55;
                  ilInstASwz1 = (undefined *)
                             (negateBit << 0xf |
                             ((uint)ilInstBSwz12[0] & 7) << 0xc |
                             negateBit << 0xb |
                             ((uint)ilInstBSwz12[0] & 7) << 8 |
                             negateBit << 7 |
                             ((uint)ilInstBSwz12[0] & 7) << 4 |
                             negateBit << 3 | (uint)ilInstBSwz12[0] & 7 | (uint)ilInstASwz1 & 0xffff0000);
                  ilInstADst = ilInstADst | 0x400000;
                  emitStatus3 = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,2);
                  if (emitStatus3 == 0) {
                    ilInstASrc2 = CONCAT22(4,(short)tempRegister);
                    ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 2)) + 1);
                    ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x40);
                    ilInstASwz2 = ((unsigned char *)0x00003210);
                    ilInstASrc2 = ilInstASrc2 | 0x400000;
                    if (componentCode == 1) {
                      ilInstADst = ilInstBDst;
                      ilInstADstMask = ilInstBDstMask;
                    }
                    select1 = (uint)ilInstBSwz12[0] >> 4 & 7;
                    negateBit = (uint)ilInstBSwz12[0] >> 7 & 1;
                    ilInstASwz1 = (undefined *)
                               (negateBit << 0xf |
                               select1 << 0xc |
                               negateBit << 0xb |
                               select1 << 8 |
                               negateBit << 7 |
                               select1 << 4 | negateBit << 3 | select1 | (uint)ilInstASwz1 & 0xffff0000);
                    emitStatus3 = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,3);
                    if ((emitStatus3 == 0) && (1 < componentCode)) {
                      ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 2)) + 1);
                      if (componentCode == 2) {
                        ilInstADst = ilInstBDst;
                        ilInstADstMask = ilInstBDstMask;
                      }
                      select2 = (uint)ilInstBSwz12[0] >> 8 & 7;
                      negateBit = (uint)ilInstBSwz12[0] >> 0xb & 1;
                      ilInstASwz1 = (undefined *)
                                 (negateBit << 0xf |
                                 select2 << 0xc |
                                 negateBit << 0xb |
                                 select2 << 8 |
                                 negateBit << 7 |
                                 select2 << 4 | negateBit << 3 | select2 | (uint)ilInstASwz1 & 0xffff0000);
                      emitStatus3 = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,3);
                      if ((emitStatus3 == 0) && (componentCode == 3)) {
                        select3 = (uint)ilInstBSwz12[0] >> 0xc & 7;
                        negateBit = (uint)ilInstBSwz12[0] >> 0xf & 1;
                        ilInstADst = ilInstBDst;
                        ilInstADstMask = ilInstBDstMask;
                        ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 2)) + 1);
                        ilInstASwz1 = (undefined *)
                                   (negateBit << 0xf |
                                   select3 << 0xc |
                                   negateBit << 0xb |
                                   select3 << 8 |
                                   negateBit << 7 |
                                   select3 << 4 | negateBit << 3 | select3 | (uint)ilInstASwz1 & 0xffff0000)
                        ;
                        ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,3);
                      }
                    }
                  }
                  componentIndex = componentIndex + 1;
                  ilInstBDst = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBDst) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstBDst) + 2)) + 1);
                  ilInstBSrc1 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBSrc1) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstBSrc1) + 2)) + 1);
                } while (regSpan != componentIndex);
                newTempBase = translator[8];
              }
              ilInstBSrc0 = CONCAT22(4,tempRegisterHalf);
              translator[8] = newTempBase - regSpan;
              ilInstBOpcode = 0x47;
              ilInstBSwz0 = ((unsigned char *)0x00003210);
              ilInstBDst = savedDstToken;
              ilInstBDstMask = savedDstMask;
              ilInstBSrc0 = ilInstBSrc0 | 0x400000;
              if (regSpan != 0) {
                componentIndex = 0;
                do {
                  componentIndex = componentIndex + 1;
                  ((int (*)())fpilEmitInstruction)(translator,ilInstBPtr,1,1);
                  ilInstBDst = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBDst) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstBDst) + 2)) + 1);
                  ilInstBSrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBSrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstBSrc0) + 2)) + 1);
                } while (regSpan != componentIndex);
              }
            }
            else {
              if ((*src0OperandPtr & 0x4000) == 0) {
                dstMaskLow2 = ilInstBDstMask & 3;
                ilInstBDst = CONCAT22(4,(short)translator[8]);
                ilInstBDstMask = 0;
                ilInstBOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBOpcode) + 0)),0x23);
                ilInstBDst = ilInstBDst | 0x400000;
                do {
                  componentIndex = 0;
                  maskBitSet = dstMaskLow2 == 1;
                  while( true ) {
                    if (maskBitSet) {
                      dstMaskHigh = ilInstBDstMask & 0xffffff00;
                      if (componentIndex == 0) {
                        ilInstBDstMask = dstMaskHigh | 1;
                      }
                      else if (componentIndex == 1) {
                        ilInstBDstMask = dstMaskHigh | 4;
                      }
                      else if (componentIndex == 2) {
                        ilInstBDstMask = dstMaskHigh | 0x10;
                      }
                      else {
                        ilInstBDstMask = ilInstBDstMask & 0xffffff00 | 0x40;
                      }
                      emitStatus2 = ((int (*)())fpilEmitInstruction)(translator,ilInstBPtr,1,2);
                      if (emitStatus2 != 0) goto loopSetCallStatus2;
                    }
                    componentIndex = componentIndex + 1;
                    ilInstBSrc1 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBSrc1) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstBSrc1) + 2)) + 1);
                    if ((int)(*(uint *)(opRecord2 + 0x18) >> 0xc & 3) < componentIndex) {
                      ilInstBSrc0 = CONCAT22(4,(short)translator[8]);
                      ilInstBOpcode = 0x47;
                      ilInstBSwz0 = ((unsigned char *)0x00003210);
                      ilInstBSrc0 = ilInstBSrc0 | 0x400000;
                      ilInstBDst = savedDstToken2;
                      ilInstBDstMask = savedDstMask2;
                      emitStatus = ((int (*)())fpilEmitInstruction)(translator,ilInstBPtr,1,1);
                      goto joined_r0x000479e8;
                    }
                    if (componentIndex == 0) break;
                    if (componentIndex == 1) {
                      maskBitSet = (savedDstMask2 & 0xc) == 4;
                    }
                    else if (componentIndex == 2) {
                      maskBitSet = (savedDstMask2 & 0x30) == 0x10;
                    }
                    else {
                      maskBitSet = (savedDstMask2 & 0xc0) == 0x40;
                    }
                  }
                } while( true );
              }
              ilInstAPtr = &ilInstAOpcode;
              componentCode = *src0OperandPtr >> 0xc & 3;
              _memcpy(ilInstAPtr,ilInstBPtr,0x24);
              tempRegBase = translator[8];
              negateBit = (uint)ilInstBSwz12[0] >> 3 & 1;
              ilInstADst = CONCAT22(4,(short)tempRegBase);
              ilInstADstMask = 0x55;
              ilInstASwz1 = (undefined *)
                         (negateBit << 0xf |
                         ((uint)ilInstBSwz12[0] & 7) << 0xc |
                         negateBit << 0xb |
                         ((uint)ilInstBSwz12[0] & 7) << 8 |
                         negateBit << 7 |
                         ((uint)ilInstBSwz12[0] & 7) << 4 |
                         negateBit << 3 | (uint)ilInstBSwz12[0] & 7 | (uint)ilInstASwz1 & 0xffff0000);
              ilInstADst = ilInstADst | 0x400000;
              emitStatus2 = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,2);
              if (emitStatus2 == 0) {
                ilInstASrc2 = CONCAT22(4,(short)tempRegBase);
                ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 2)) + 1);
                ilInstASwz2 = ((unsigned char *)0x00003210);
                ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x40);
                ilInstASrc2 = ilInstASrc2 | 0x400000;
                if (componentCode == 1) {
                  ilInstADst = ilInstBDst;
                  ilInstADstMask = ilInstBDstMask;
                }
                select1 = (uint)ilInstBSwz12[0] >> 4 & 7;
                negateBit = (uint)ilInstBSwz12[0] >> 7 & 1;
                ilInstASwz1 = (undefined *)
                           (negateBit << 0xf |
                           select1 << 0xc |
                           negateBit << 0xb |
                           select1 << 8 |
                           negateBit << 7 |
                           select1 << 4 | negateBit << 3 | select1 | (uint)ilInstASwz1 & 0xffff0000);
                emitStatus = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,3);
                if ((emitStatus == 0) && (1 < componentCode)) {
                  ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 2)) + 1);
                  if (componentCode == 2) {
                    ilInstADst = ilInstBDst;
                    ilInstADstMask = ilInstBDstMask;
                  }
                  select2 = (uint)ilInstBSwz12[0] >> 8 & 7;
                  negateBit = (uint)ilInstBSwz12[0] >> 0xb & 1;
                  ilInstASwz1 = (undefined *)
                             (negateBit << 0xf |
                             select2 << 0xc |
                             negateBit << 0xb |
                             select2 << 8 |
                             negateBit << 7 |
                             select2 << 4 | negateBit << 3 | select2 | (uint)ilInstASwz1 & 0xffff0000);
                  emitStatus = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,3);
                  if ((emitStatus == 0) && (componentCode == 3)) {
                    select3 = (uint)ilInstBSwz12[0] >> 0xc & 7;
                    negateBit = (uint)ilInstBSwz12[0] >> 0xf & 1;
                    ilInstADst = ilInstBDst;
                    ilInstADstMask = ilInstBDstMask;
                    ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 2)) + 1);
                    ilInstASwz1 = (undefined *)
                               (negateBit << 0xf |
                               select3 << 0xc |
                               negateBit << 0xb |
                               select3 << 8 |
                               negateBit << 7 |
                               select3 << 4 | negateBit << 3 | select3 | (uint)ilInstASwz1 & 0xffff0000);
                    ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,3);
                  }
                }
              }
            }
            goto loopCheckOpcodeInfoOffset;
          }
          if (((opcode - 0x1f < 2) || (opcode == 0x23)) || (opcode == 0x3a)) {
            callStatus2 = ((int (*)())fragmentTranslateArithmetic)(translator,recordIndex);
            goto joined_r0x0004802c;
          }
          if (opcode == 0x6c) {
            ilInstAPtr = &ilInstAOpcode;
            instructionBlock4 = *translator + *(int *)(*translator + 0x54) * 8;
            _memset(ilInstAPtr,0,0x24);
            opRecordOrSrcStatus = instructionBlock4 + recordByteOffset;
            destPtrOrDestStatus = opRecordOrSrcStatus + 8;
            destClass = ((int (*)())fpilClassifyDestination)(translator,destPtrOrDestStatus);
            if (destClass == 1) {
              ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),99);
            }
            else if (destClass == 2) {
              ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x56);
              ilInstAOpcode = ilInstAOpcode & 0xc000ffff;
            }
            else {
              ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x47);
            }
            destPtrOrDestStatus = ((int (*)())fpilTranslateDestination)(translator,destPtrOrDestStatus,&ilInstADst,&ilInstADstMask,
                                  *(uint *)(recordByteOffset + instructionBlock4 + 4) >> 0x14 & 1);
            if ((destPtrOrDestStatus == 0) &&
               (opRecordOrSrcStatus = ((int (*)())fpilTranslateSource)(translator,opRecordOrSrcStatus + 0x10,&ilInstASrc0,&ilInstASwz0), opRecordOrSrcStatus == 0)) {
              emittedSourceCount = 1;
              if (destClass == 2) {
                emittedSourceCount = 2;
                ilInstASwz1 = (undefined *)((uint)ilInstASwz1 & 0xffff0000 | 0x4444);
                ilInstASrc1 = CONCAT22((short)(ilInstASrc1 >> 0x10),(short)translator[8]) & 0xffc0ffff |
                           0x440000;
              }
              emitStatus = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,emittedSourceCount);
              goto joined_r0x00048414;
            }
            goto loopCheckTranslator;
          }
          if (opcode == 8) {
            callStatus2 = ((int (*)())fragmentTranslateAny)(translator,recordIndex,0);
joined_r0x00048448:
            if (callStatus2 != 0) {
loopReturnTranslator:
              return translator[9];
            }
            goto loopCheckOpcodeInfoOffset;
          }
          if (opcode == 9) {
            callStatus2 = ((int (*)())fragmentTranslateAll)(translator,recordIndex,0);
            goto joined_r0x00048448;
          }
          if (opcode == 10) {
            ilInstAPtr = &ilInstAOpcode;
            programPtr = *translator;
            instBlockOffset = *(int *)(programPtr + 0x54);
            _memset(ilInstAPtr,0,0x24);
            programPtr = programPtr + instBlockOffset * 8 + recordByteOffset;
            ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x5b);
            dstStatus = ((int (*)())fpilTranslateDestination)(translator,programPtr + 8,&ilInstADst,&ilInstADstMask,1);
            if (dstStatus == 0) {
              ilInstASwz0 = (undefined *)((uint)ilInstASwz0 & 0xffff0000 | 0x5555);
              ilInstASrc0 = CONCAT22((short)(ilInstASrc0 >> 0x10),(short)translator[8]) & 0xffc0ffff |
                         0x440000;
              srcStatus = ((int (*)())fpilTranslateSource)(translator,programPtr + 0x10,&ilInstASrc1,&ilInstASwz1);
              if (srcStatus == 0) {
                emitStatus = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,2);
joined_r0x00048414:
                if (emitStatus == 0) goto loopCheckOpcodeInfoOffset;
              }
            }
            goto loopCheckTranslator;
          }
          if (opcode == 0x26) {
            ilInstAPtr = &ilInstAOpcode;
            programPtr = *translator;
            instBlockOffset = *(int *)(programPtr + 0x54);
            _memset(ilInstAPtr,0,0x24);
            programPtr = programPtr + instBlockOffset * 8 + recordByteOffset;
            ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x5b);
            ilInstADstMask = ilInstADstMask & 0xffffff00 | 0x55;
            ilInstADst = CONCAT22((short)(ilInstADst >> 0x10),(short)translator[8]) & 0xffc0ffff | 0x440000
            ;
            callStatus = ((int (*)())fpilTranslateSource)(translator,programPtr + 0x10,&ilInstASrc0,&ilInstASwz0);
            if (((callStatus == 0) &&
                (callStatus = ((int (*)())fpilTranslateSource)(translator,programPtr + 0x18,&ilInstASrc1,&ilInstASwz1), callStatus == 0)) &&
               (callStatus = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,2), callStatus == 0)) {
              ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),1);
              dstStatus = ((int (*)())fpilTranslateDestination)(translator,programPtr + 8,&ilInstADst,&ilInstADstMask,1);
              if (dstStatus == 0) {
                ilInstASrc0 = CONCAT22(4,(short)translator[8]);
                ilInstASwz0 = ((unsigned char *)0x00003210);
                ilInstASrc0 = ilInstASrc0 | 0x400000;
                emitStatus = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,1);
                goto joined_r0x00048414;
              }
            }
            goto loopCheckTranslator;
          }
          if (opcode == 0x39) {
            callStatus2 = ((int (*)())fragmentTranslateSel)(translator,recordIndex);
            goto joined_r0x00048448;
          }
          if (opcode == 0x6d) {
            callStatus2 = ((int (*)())fragmentTranslateDsl)(translator,recordIndex);
            goto joined_r0x00048448;
          }
          if ((opcode == 0x31) || (opcode == 0x36)) {
            instructionBlock = *translator + *(int *)(*translator + 0x54) * 8;
            if ((translator[5] & 0x20000000U) == 0) {
              src1Advances = 0;
              src0Advances = 0;
            }
            else {
              src0Advances = *(uint *)(instructionBlock + recordByteOffset + 0x10) >> 0xe & 1;
              src1Advances = *(uint *)(instructionBlock + recordByteOffset + 0x18) >> 0xe & 1;
            }
            src0Operand = (uint *)(recordByteOffset + instructionBlock + 0x10);
            src1OperandPtr = (uint *)(recordByteOffset + instructionBlock + 0x18);
            instHeader = (uint *)(recordByteOffset + instructionBlock);
            ilInstAPtr = &ilInstAOpcode;
            dstRegSpan = (instHeader[1] >> 0x1a & 3) + 1;
            src0RegSpan = (*src0Operand >> 0xc & 3) + 1;
            src1RegSpan = (*src1OperandPtr >> 0xc & 3) + 1;
            _memset(ilInstAPtr,0,0x24);
            ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x56);
            ilInstAOpcode = (uint)((*(uint *)(recordByteOffset + instructionBlock) & 0x3fc0000) == 0xc40000) << 0x10 |
                       ilInstAOpcode & 0xc000ffff;
            srcStatus2 = ((int (*)())fpilTranslateSource)(translator,src0Operand,&ilInstASrc0,&ilInstASwz0);
            if ((srcStatus2 == 0) &&
               (srcStatus2 = ((int (*)())fpilTranslateSource)(translator,src1OperandPtr,&ilInstASrc1,&ilInstASwz1), srcStatus2 == 0)) {
              if (dstRegSpan < 2) {
                ilInstADst = CONCAT22(4,(short)translator[8]);
                ilInstADstMask = 0x55;
                ilInstADst = ilInstADst | 0x400000;
                emitStatus2 = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,2);
                if (emitStatus2 == 0) {
                  maxRegSpan = src0RegSpan;
                  if (src0RegSpan < src1RegSpan) {
                    maxRegSpan = src1RegSpan;
                  }
                  advanceSrc0 = src0Advances != 0;
                  if (((advanceSrc0) || (src1Advances != 0)) && (1 < maxRegSpan)) {
                    ilInstBPtr = &ilInstBOpcode;
                    ilInstADst = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstADst) + 0)),(short)translator[8] + 1);
                    _memset(ilInstBPtr,0,0x24);
                    ilSelectOpcode = 0x49;
                    if ((*(uint *)(recordByteOffset + instructionBlock) & 0x3fc0000) != 0xc40000) {
                      ilSelectOpcode = 3;
                    }
                    ilInstBOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBOpcode) + 0)),ilSelectOpcode);
                    tempRegisterBase = (short)translator[8];
                    ilInstBDst = CONCAT22(4,tempRegisterBase);
                    componentIndex = 1;
                    ilInstBSrc1 = CONCAT22(4,tempRegisterBase + 1);
                    ilInstBSrc0 = CONCAT22(4,tempRegisterBase);
                    ilInstBDstMask = 0x55;
                    advanceSrc1 = src1Advances != 0;
                    ilInstBSwz12[0] = ((unsigned char *)0x00003210);
                    ilInstBSwz0 = ((unsigned char *)0x00003210);
                    ilInstBDst = ilInstBDst | 0x400000;
                    ilInstBSrc1 = ilInstBSrc1 | 0x400000;
                    ilInstBSrc0 = ilInstBSrc0 | 0x400000;
                    do {
                      if (advanceSrc0) {
                        ilInstASrc0 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc0) + 2)) + 1);
                      }
                      if (advanceSrc1) {
                        ilInstASrc1 = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstASrc1) + 0)),(*(unsigned short *)((unsigned char *)&(ilInstASrc1) + 2)) + 1);
                      }
                      emitStatus3 = ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,2);
                      if ((emitStatus3 != 0) ||
                         (emitStatus3 = ((int (*)())fpilEmitInstruction)(translator,ilInstBPtr,1,2), emitStatus3 != 0))
                      goto setCallStatus2;
                      componentIndex = componentIndex + 1;
                    } while (maxRegSpan != componentIndex);
                  }
                  if ((*instHeader & 0x3fc0000) == 0xc40000) {
                    callStatus2 = ((int (*)())fragmentTranslateAll)(translator,recordIndex,maxRegSpan);
                    goto joined_r0x0004802c;
                  }
                  ilInstBPtr = &ilInstBOpcode;
                  programPtr = *translator;
                  instBlockOffset = *(int *)(programPtr + 0x54);
                  _memset(ilInstBPtr,0,0x24);
                  ilInstBOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstBOpcode) + 0)),0x23);
                  instBlockOffset = ((int (*)())fpilTranslateDestination)(translator,programPtr + instBlockOffset * 8 + recordByteOffset + 8,&ilInstBDst,&ilInstBDstMask,1)
                  ;
                  if (instBlockOffset == 0) {
                    ilInstBSrc0 = CONCAT22(4,(short)translator[8]);
                    ilInstBSwz0 = ((unsigned char *)0x00003210);
                    ilInstBSwz12[0] = (undefined *)((uint)ilInstBSwz12[0] & 0xffff0000 | 0x5555);
                    ilInstBSrc0 = ilInstBSrc0 | 0x400000;
                    ilInstBSrc1 = CONCAT22((short)(ilInstBSrc1 >> 0x10),(short)translator[8]) & 0xffc0ffff |
                               0x440000;
                    emitStatus = ((int (*)())fpilEmitInstruction)(translator,ilInstBPtr,1,2);
                    if (emitStatus == 0) goto loopCheckOpcode;
                  }
                }
                goto setCallStatus2;
              }
              ((int (*)())fpilTranslateDestination)(translator,recordByteOffset + instructionBlock + 8,&ilInstADst,&ilInstADstMask,0);
              ((int (*)())fpilEmitInstruction)(translator,ilInstAPtr,1,2);
              callStatus2 = translator[9];
            }
            else {
setCallStatus2:
              callStatus2 = translator[9];
            }
joined_r0x0004802c:
            if (callStatus2 != 0) goto loopReturnTranslator;
            goto loopCheckOpcode;
          }
          if (opcode != 0x4d) break;
        }
        instructionIndex = instructionIndex + 1;
        recordIndex = recordIndex + recordSpan;
        if (instructionCount == instructionIndex) goto loopReturnCode;
        recordByteOffset = recordIndex * 8;
        currentRecord = instructionRecords + recordIndex * 2;
        opcode = instructionRecords[recordIndex * 2] >> 0x12 & 0xff;
        opcodeInfoOffset = opcode * 0x10;
        opClass = *(uint *)(&fragmentOpcodeInfoTable_001dac34 + opcodeInfoOffset) >> 0x11 & 0xf;
        if ((opClass == 0) || ((*(uint *)(&fragmentOpcodeInfoTable_word3_001dac40 + opcodeInfoOffset) >> 0x1c & DAT_001db344) != 0))
        break;
      } while( true );
    }
    returnCode = translator[9];
    if (returnCode == 0) {
      returnCode = 3;
      translator[9] = 3;
    }
  }
  return returnCode;
}

/* fragmentProgramToIL @ 0x48da0 (6552 bytes) */
int fragmentProgramToIL(translator)
  int *translator;
{
  bool moreChannels;
  uint channelIndex;
  uint translatorFlags;
  uint fogMode;
  uint outputIndex;
  uint *outputEntry;
  uint outputCount;
  uint constantIndex;
  uint paramTypeBits;
  uint paramIndex;
  uint *paramEntry;
  uint paramCount;
  uint requiredTokenWords;
  uint *attribEntry;
  int attribRemaining;
  int outputRemaining;
  int optionEntry;
  int optionCount;
  int allocation2;
  int allocation;
  uint tokenCapacity4;
  uint tokenCapacity3;
  uint tokenCapacity;
  undefined4 *tokenWritePtr2;
  int *tokenDataPtrAddr;
  int tokenCount3;
  int translatorError3;
  int translatorError2;
  int tokenCount2;
  int translatorError;
  int tokenCount;
  undefined **ilCopyNext;
  undefined4 *ilCopyNext2;
  bool fogRequired;
  ushort attribBinding;
  short fogTempPlus1;
  short outputIndexShort;
  undefined2 tempRegisterHalf;
  short fogTempRegister;
  double intToDoubleBias;
  uint texTargetsHigh;
  uint *outputScanEntry;
  uint tokenCapacity2;
  int programKind;
  int reservedTokenPos;
  int translatorInfo;
  int programObj2;
  int ilWordIndex;
  int ilWordCount;
  int constRecordPtr;
  int tokensLeft;
  uint texTargetsLow;
  undefined4 in_r4;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  undefined4 extraout_r4_08;
  undefined4 extraout_r4_09;
  undefined4 extraout_r4_10;
  int in_r5;
  undefined4 in_r6;
  undefined4 *tokenWritePtr;
  dword *tokenWord1Ptr;
  int wordOffset;
  uint paramKind;
  undefined4 *ilCopyCursor2;
  undefined **ilCopyCursor;
  int *program;
  undefined *attribSourceToken;
  undefined *swizzleXYZW;
  uint nibbleCarry;
  uint outputDstToken;
  undefined4 dstMaskToken;
  uint outputSrcToken;
  undefined4 *tokenWritePtr3;
  int programObj;
  int removedWords;
  int fogTokenPtr;
  int programObj4;
  int placeholderOffset;
  int constBlockBase;
  int programObj3;
  int tokenCopyOffset;
  int unitsLeft;
  undefined4 ilInstAOpcode;
  undefined4 ilInstADst;
  uint ilInstADstMask;
  undefined4 ilInstASrc0;
  undefined4 ilInstASrc1;
  undefined4 ilInstASrc2;
  undefined *ilInstASwzWords [10];
  undefined4 intToDoubleHiA;
  uint intToDoubleLoA;
  undefined4 intToDoubleHiB;
  uint intToDoubleLoB;
  undefined4 intToDoubleHiC;
  uint intToDoubleLoC;
  undefined4 intToDoubleHiD;
  uint intToDoubleLoD;
  
  program = (int *)*translator;
  if (program == (int *)0x0) {
    if (translator[9] != 0) {
      return translator[9];
    }
    translator[9] = 2;
    return 2;
  }
  translator[8] = program[4] + program[0xc] + 1;
  programKind = *program;
  if ((programKind != 0x8804) && (programKind != 0x8b30)) {
returnTranslatorStatus:
    if (translator[9] != 0) {
      return translator[9];
    }
loopStoreTranslator:
    translator[9] = 3;
    return 3;
  }
  tokenDataPtrAddr = translator + 10;
  translator[5] = (uint)(programKind - 0x8b30U < 2) << 0x1d | translator[5] & 0xdfffffffU;
  tokenCount = translator[0xb];
  tokenCapacity = translator[0xc];
  if (tokenCapacity < tokenCount + 2U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 2U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
      in_r4 = extraout_r4;
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      in_r4 = extraout_r4_00;
    }
    if (allocation != 0) {
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
      goto storeTranslator;
    }
    translatorError = translator[9];
    if (translatorError == 0) {
      translatorError = 1;
      translator[9] = 1;
    }
    if (translatorError != 0) {
      return translatorError;
    }
    tokenWritePtr3 = (undefined4 *)0x0;
    tokenWord1Ptr = ((unsigned char *)0x4);
  }
  else {
storeTranslator:
    translator[0xb] = tokenCount + 2;
    tokenWritePtr3 = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
    tokenWord1Ptr = tokenWritePtr3 + 1;
  }
  *tokenWritePtr3 = 1;
  *tokenWord1Ptr = 0x10200;
  programObj = *translator;
  outputRemaining = *(int *)(programObj + 0x30);
  outputScanEntry = (uint *)(programObj + *(int *)(programObj + 0x34) * 8);
  if (0 < outputRemaining) {
    do {
      if (((*outputScanEntry >> 0x10 & 0xf) == 4) && ((*outputScanEntry & 0xe) != 0)) {
        *(uint *)(translator[0xd] + 0x20) = *(uint *)(translator[0xd] + 0x20) | 0x400000;
        programObj = *translator;
        break;
      }
      outputScanEntry = outputScanEntry + 2;
      outputRemaining = outputRemaining + -1;
    } while (outputRemaining != 0);
  }
  optionCount = *(int *)(programObj + 0x48);
  optionEntry = programObj + *(int *)(programObj + 0x4c) * 8;
  if (0 < optionCount) {
    do {
      switch(*(undefined1 *)(optionEntry + 3)) {
      case 0:
      case 8:
      case 10:
        translatorError = translator[9];
        if (translatorError == 0) goto loopStoreTranslator;
        if (translatorError != 0) {
          return translatorError;
        }
        goto setAttribRemaining;
      case 1:
        translator[5] = translator[5] & 0xe7ffffffU | 0x10000000;
        break;
      case 2:
        translator[5] = translator[5] & 0xe7ffffffU | 0x18000000;
        break;
      case 3:
        translator[5] = translator[5] & 0xe7ffffffU | 0x8000000;
      }
      optionCount = optionCount + -1;
      optionEntry = optionEntry + 8;
    } while (optionCount != 0);
  }
setAttribRemaining:
  attribRemaining = *(int *)(programObj + 0x20);
  tokenCount2 = translator[0xb];
  tokenCapacity = translator[0xc];
  requiredTokenWords = attribRemaining * 2 + tokenCount2;
  attribEntry = (uint *)(programObj + *(int *)(programObj + 0x24) * 8);
  if (tokenCapacity < requiredTokenWords) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < requiredTokenWords; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation2 = _malloc(tokenCapacity << 2);
      in_r4 = extraout_r4_01;
    }
    else {
      allocation2 = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      in_r4 = extraout_r4_02;
    }
    if (allocation2 == 0) goto loopCheckTranslator2;
    *tokenDataPtrAddr = allocation2;
    translator[0xc] = tokenCapacity;
    tokenCount2 = translator[0xb];
  }
  translator[0xb] = attribRemaining * 2 + tokenCount2;
  tokenWritePtr = (undefined4 *)(tokenCount2 * 4 + *tokenDataPtrAddr);
  if (attribRemaining < 1) {
loopCheckTranslator:
    if ((translator[5] & 0x18000000U) != 0) {
      tokenCount = translator[0xb];
      tokenCapacity = translator[0xc];
      if (tokenCapacity < tokenCount + 2U) {
        if (tokenCapacity == 0) {
          tokenCapacity = 0x10;
        }
        else {
          tokenCapacity = tokenCapacity << 1;
        }
        for (; tokenCapacity < tokenCount + 2U; tokenCapacity = tokenCapacity << 1) {
        }
        if (*tokenDataPtrAddr == 0) {
          allocation = _malloc(tokenCapacity << 2);
          in_r4 = extraout_r4_03;
        }
        else {
          allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
          in_r4 = extraout_r4_04;
        }
        if (allocation == 0) goto loopCheckTranslator2;
        *tokenDataPtrAddr = allocation;
        translator[0xc] = tokenCapacity;
        tokenCount = translator[0xb];
      }
      translator[0xb] = tokenCount + 2;
      tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
      *tokenWritePtr = 0x1ff0016;
      tokenWritePtr[1] = 0x100000;
    }
  }
  else {
    in_r5 = 0;
    do {
      attribBinding = *(ushort *)attribEntry;
      if ((attribBinding & 0xf) == 1) {
        *tokenWritePtr = 0x3ff0016;
setAttribSourceToken:
        attribSourceToken = ((unsigned char *)0x00160000);
      }
      else {
        *tokenWritePtr = 0x1ff0016;
        switch(attribBinding & 0xf) {
        default:
          goto returnTranslatorStatus;
        case 1:
          goto setAttribSourceToken;
        case 2:
          attribSourceToken = (undefined *)0x120000;
          break;
        case 3:
          attribSourceToken = (undefined *)0x130000;
          break;
        case 5:
          in_r5 = 1;
          attribSourceToken = (undefined *)0x100000;
          break;
        case 7:
          attribSourceToken = (undefined *)(*attribEntry & 0x1f | 0x110000);
        }
      }
      attribRemaining = attribRemaining + -1;
      tokenWritePtr[1] = attribSourceToken;
      tokenWritePtr = tokenWritePtr + 2;
      attribEntry = attribEntry + 2;
    } while (attribRemaining != 0);
    in_r6 = 0;
    if (in_r5 == 0) goto loopCheckTranslator;
  }
  texTargetsHigh = translator[1];
  texTargetsLow = translator[2];
  tokenWritePtr2 = (undefined4 *)0x0;
  unitsLeft = 0x10;
  ilWordIndex = 0;
  do {
    ilWordCount = ilWordIndex;
    switch(texTargetsLow & 0xf) {
    case 0:
      tokenWritePtr = &ilInstAOpcode;
      ilWordCount = ilWordIndex + 1;
      tokenWritePtr[ilWordIndex] = (int)tokenWritePtr2 << 0x10 | 0xc000019;
      break;
    case 1:
      tokenWritePtr = &ilInstAOpcode;
      ilWordCount = ilWordIndex + 1;
      tokenWritePtr[ilWordIndex] = (int)tokenWritePtr2 << 0x10 | 0xb000019;
      break;
    case 2:
      tokenWritePtr = &ilInstAOpcode;
      ilWordCount = ilWordIndex + 1;
      tokenWritePtr[ilWordIndex] = (int)tokenWritePtr2 << 0x10 | 0x12000019;
      break;
    case 3:
      tokenWritePtr = &ilInstAOpcode;
      ilWordCount = ilWordIndex + 1;
      tokenWritePtr[ilWordIndex] = (int)tokenWritePtr2 << 0x10 | 0xa000019;
      break;
    case 4:
      tokenWritePtr = &ilInstAOpcode;
      ilWordCount = ilWordIndex + 1;
      tokenWritePtr[ilWordIndex] = (int)tokenWritePtr2 << 0x10 | 0x9000019;
    }
    unitsLeft = unitsLeft + -1;
    nibbleCarry = texTargetsHigh << 0x1c;
    texTargetsHigh = texTargetsHigh >> 4;
    tokenWritePtr2 = (undefined4 *)((int)tokenWritePtr2 + 1);
    texTargetsLow = nibbleCarry | texTargetsLow >> 4;
    ilWordIndex = ilWordCount;
  } while (unitsLeft != 0);
  tokenCount = translator[0xb];
  tokenCapacity = translator[0xc];
  if (tokenCapacity < (uint)(ilWordCount + tokenCount)) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < (uint)(ilWordCount + tokenCount); tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation2 = _malloc(tokenCapacity << 2);
      in_r4 = extraout_r4_05;
    }
    else {
      allocation2 = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      in_r4 = extraout_r4_06;
    }
    if (allocation2 != 0) {
      *tokenDataPtrAddr = allocation2;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
      goto setTokenCopyOffset;
    }
    translatorError2 = translator[9];
    if (translatorError2 == 0) {
      translatorError2 = 1;
      translator[9] = 1;
    }
    tokenCopyOffset = 0;
    if (translatorError2 != 0) {
      return translatorError2;
    }
  }
  else {
setTokenCopyOffset:
    tokenCopyOffset = tokenCount * 4;
    tokenCount = ilWordCount + tokenCount;
    translator[0xb] = tokenCount;
    tokenCopyOffset = tokenCopyOffset + *tokenDataPtrAddr;
  }
  if (0 < ilWordCount) {
    wordOffset = 0;
    tokenWritePtr = &ilInstAOpcode;
    do {
      *(undefined4 *)(wordOffset + tokenCopyOffset) = *(undefined4 *)(wordOffset + (int)tokenWritePtr);
      wordOffset = wordOffset + 4;
      ilWordCount = ilWordCount + -1;
    } while (ilWordCount != 0);
  }
  intToDoubleBias = DOUBLE_001aa1e0;
  programObj3 = *translator;
  paramCount = *(uint *)(programObj3 + 0x28);
  paramEntry = (uint *)(programObj3 + *(int *)(programObj3 + 0x2c) * 8);
  constBlockBase = programObj3 + *(int *)(programObj3 + 0x6c) * 8;
  if (0 < (int)paramCount) {
    paramIndex = 0;
    do {
      paramTypeBits = *paramEntry & 0x1c000000;
      paramKind = *paramEntry >> 0x10 & 0x1f;
      if ((((paramTypeBits != 0xc000000) && (paramTypeBits != 0x4000000)) && (paramTypeBits != 0x10000000)) &&
         (paramTypeBits != 0)) {
        translatorError3 = translator[9];
        if (translatorError3 == 0) goto loopStoreTranslator;
        goto checkTranslatorError3;
      }
      if (paramKind == 0x11) {
        tokenCount2 = translator[0xb];
        tokenCapacity4 = translator[0xc];
        if (tokenCapacity4 < tokenCount2 + 6U) {
          if (tokenCapacity4 == 0) {
            tokenCapacity4 = 0x10;
          }
          else {
            tokenCapacity4 = tokenCapacity4 << 1;
          }
          for (; tokenCapacity4 < tokenCount2 + 6U; tokenCapacity4 = tokenCapacity4 << 1) {
          }
          if (*tokenDataPtrAddr == 0) {
            allocation = _malloc(tokenCapacity4 << 2);
            in_r4 = extraout_r4_07;
          }
          else {
            allocation = _realloc(*tokenDataPtrAddr,tokenCapacity4 << 2);
            in_r4 = extraout_r4_08;
          }
          if (allocation == 0) goto loopCheckTranslator2;
          *tokenDataPtrAddr = allocation;
          translator[0xc] = tokenCapacity4;
          tokenCount2 = translator[0xb];
        }
        tokenCount = tokenCount2 + 6;
        translator[0xb] = tokenCount;
        tokenWritePtr2 = (undefined4 *)(tokenCount2 * 4 + *tokenDataPtrAddr);
        *tokenWritePtr2 = 0x1c;
        tokenWritePtr2[1] = paramIndex & 0xffff | 0x10000;
        constantIndex = (uint)(ushort)*paramEntry;
        if ((*paramEntry & 0x1c000000) == 0xc000000) {
          intToDoubleHiA = 0x43300000;
          constRecordPtr = constBlockBase + constantIndex * 0x10;
          intToDoubleLoA = *(uint *)(constantIndex * 0x10 + constBlockBase) ^ 0x80000000;
          tokenWritePtr2[2] = (float)((double)CONCAT44(0x43300000,intToDoubleLoA) - intToDoubleBias);
          intToDoubleHiB = 0x43300000;
          intToDoubleLoB = *(uint *)(constRecordPtr + 4) ^ 0x80000000;
          tokenWritePtr2[3] = (float)((double)CONCAT44(0x43300000,intToDoubleLoB) - intToDoubleBias);
          intToDoubleHiC = 0x43300000;
          intToDoubleLoC = *(uint *)(constRecordPtr + 8) ^ 0x80000000;
          tokenWritePtr2[4] = (float)((double)CONCAT44(0x43300000,intToDoubleLoC) - intToDoubleBias);
          intToDoubleHiD = 0x43300000;
          intToDoubleLoD = *(uint *)(constRecordPtr + 0xc) ^ 0x80000000;
          tokenWritePtr2[5] = (float)((double)CONCAT44(0x43300000,intToDoubleLoD) - intToDoubleBias);
        }
        else if ((*paramEntry & 0x1c000000) == 0x10000000) {
          constRecordPtr = constBlockBase + constantIndex * 0x10;
          tokenWritePtr2[2] = (uint)(*(int *)(constBlockBase + constantIndex * 0x10) != 0);
          tokenWritePtr2[3] = (uint)(*(int *)(constRecordPtr + 4) != 0);
          tokenWritePtr2[4] = (uint)(*(int *)(constRecordPtr + 8) != 0);
          tokenWritePtr2[5] = (uint)(*(int *)(constRecordPtr + 0xc) != 0);
        }
        else {
          constRecordPtr = constBlockBase + constantIndex * 0x10;
          tokenWritePtr2[2] = *(undefined4 *)(constBlockBase + constantIndex * 0x10);
          tokenWritePtr2[3] = *(undefined4 *)(constRecordPtr + 4);
          tokenWritePtr2[4] = *(undefined4 *)(constRecordPtr + 8);
          tokenWritePtr2[5] = *(undefined4 *)(constRecordPtr + 0xc);
        }
      }
      paramIndex = paramIndex + 1;
      paramEntry = paramEntry + 2;
    } while (paramCount != paramIndex);
  }
  translator[6] = translator[0xb];
  tokenCount3 = translator[0xb];
  tokenCapacity = translator[0xc];
  if (tokenCapacity < tokenCount3 + 0xc6U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount3 + 0xc6U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
      in_r4 = extraout_r4_09;
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
      in_r4 = extraout_r4_10;
    }
    if (allocation == 0) {
loopCheckTranslator2:
      if (translator[9] != 0) {
        return translator[9];
      }
      translator[9] = 1;
      return 1;
    }
    *tokenDataPtrAddr = allocation;
    translator[0xc] = tokenCapacity;
    tokenCount3 = translator[0xb];
  }
  tokenCount = tokenCount3 + 0xc6;
  translator[0xb] = tokenCount;
  paramKind = tokenCount3 * 4 + *tokenDataPtrAddr;
  placeholderOffset = 0;
  tokensLeft = 0xc6;
  do {
    *(undefined4 *)(placeholderOffset + paramKind) = 0x4b;
    placeholderOffset = placeholderOffset + 4;
    tokensLeft = tokensLeft + -1;
  } while (tokensLeft != 0);
  translatorError3 = translator[9];
  translator[7] = translator[0xb];
checkTranslatorError3:
  if (translatorError3 != 0) {
    return translatorError3;
  }
  tokenCount = ((int (*)())fragmentInstructionToIL)(translator,in_r4,in_r5,in_r6,tokenWritePtr,tokenCount,paramKind,tokenWritePtr2);
  if (tokenCount != 0) goto returnTranslator;
  programObj2 = *translator;
  outputCount = *(uint *)(programObj2 + 0x30);
  outputEntry = (uint *)(programObj2 + *(int *)(programObj2 + 0x34) * 8);
  if (0 < (int)outputCount) {
    outputIndex = 0;
    do {
      if ((1 << (outputIndex & 0x3f) & translator[4]) != 0) {
        dstMaskToken = 0x55;
        swizzleXYZW = ((unsigned char *)0x00003210);
        outputDstToken = outputIndex + *(int *)(*translator + 0x10) + 1 & 0xffff | 0x440000;
        if ((*(ushort *)outputEntry & 0xf) == 4) {
          translatorInfo = translator[0xd];
          if (((*(uint *)(translatorInfo + 0x20) & 0x400000) != 0) ||
             (fogRequired = true, (*(uint *)(translatorInfo + 0x20) >> 0x12 & 0xf) < 2)) {
            fogRequired = false;
          }
          translatorFlags = translator[5];
          translator[5] = translatorFlags | 0x80000000;
          outputSrcToken = *outputEntry >> 1 & 7 | 0x570000;
          if ((translatorFlags & 0x18000000) != 0) {
            *(uint *)(translatorInfo + 0x20) = *(uint *)(translatorInfo + 0x20) | 0x2000000;
            tempRegisterHalf = (undefined2)translator[8];
            fogTempRegister = ((ushort)((uint)*(undefined4 *)(translator[0xd] + 0x20) >> 0x1a) & 1) +
                    (short)*(undefined4 *)(*translator + 0x28);
            _memset(&ilInstAOpcode,0,0x24);
            fogTempPlus1 = fogTempRegister + 1;
            fogMode = (uint)translator[5] >> 0x1b & 3;
            ilInstADst = CONCAT22(4,tempRegisterHalf);
            ilInstADstMask = 0x55;
            ilInstASwzWords[0] = (undefined *)((uint)ilInstASwzWords[0] & 0xffff0000);
            ilInstASrc0 = (undefined *)((uint)ilInstASrc0 & 0xffc0ffff | 0x500000);
            ilInstADst = ilInstADst | 0x400000;
            if (fogMode == 1) {
              translatorError = translator[9];
              ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x40);
              ilInstADstMask = 0x155;
              ilInstASwzWords[1] = (undefined *)0x0;
              ilInstASrc1 = CONCAT22(1,fogTempPlus1) | 0x400000;
              ilInstASwzWords[2] = ((unsigned char *)0x00001111);
              ilInstASrc2 = CONCAT22(1,fogTempPlus1) | 0x400000;
              if (translatorError == 0) {
                tokenCount = translator[0xb];
                tokenCapacity3 = translator[0xc];
                if (tokenCapacity3 < tokenCount + 9U) {
                  if (tokenCapacity3 == 0) {
                    tokenCapacity3 = 0x10;
                  }
                  else {
                    tokenCapacity3 = tokenCapacity3 << 1;
                  }
                  for (; tokenCapacity3 < tokenCount + 9U; tokenCapacity3 = tokenCapacity3 << 1) {
                  }
                  if (*tokenDataPtrAddr == 0) {
                    allocation = _malloc(tokenCapacity3 << 2);
                  }
                  else {
                    allocation = _realloc(*tokenDataPtrAddr,tokenCapacity3 << 2);
                  }
                  if (allocation == 0) {
loopSetTranslatorError:
                    translatorError = translator[9];
                    if (translatorError == 0) {
                      translatorError = 1;
                      translator[9] = 1;
                    }
                    goto setProgramObj4;
                  }
                  *tokenDataPtrAddr = allocation;
                  translator[0xc] = tokenCapacity3;
                  tokenCount = translator[0xb];
                }
                ilCopyCursor = (undefined **)&ilInstASrc0;
                translator[0xb] = tokenCount + 9;
                tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
                *tokenWritePtr = ilInstAOpcode;
                tokenWritePtr[1] = ilInstADst;
                tokenWritePtr[2] = ilInstADstMask;
                do {
                  tokenWritePtr[3] = *ilCopyCursor;
                  ilCopyNext = ilCopyCursor + 3;
                  ilCopyCursor = ilCopyCursor + 1;
                  tokenWritePtr[4] = *ilCopyNext;
                  tokenWritePtr = tokenWritePtr + 2;
                } while (ilInstASwzWords != ilCopyCursor);
                goto setTranslatorError;
              }
            }
            else {
              if ((fogMode == 0) || (3 < fogMode)) goto setChannelIndex;
              ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x49);
              if ((translator[5] & 0x18000000U) == 0x10000000) {
                ilInstASrc1 = CONCAT22(1,fogTempPlus1);
                translatorError = translator[9];
                ilInstASwzWords[1] = (undefined *)0x2222;
                ilInstASrc1 = ilInstASrc1 | 0x400000;
                if (translatorError == 0) {
                  tokenCount = translator[0xb];
                  tokenCapacity3 = translator[0xc];
                  if (tokenCapacity3 < tokenCount + 7U) {
                    if (tokenCapacity3 == 0) {
                      tokenCapacity3 = 0x10;
                    }
                    else {
                      tokenCapacity3 = tokenCapacity3 << 1;
                    }
                    for (; tokenCapacity3 < tokenCount + 7U; tokenCapacity3 = tokenCapacity3 << 1) {
                    }
                    if (*tokenDataPtrAddr == 0) {
                      allocation = _malloc(tokenCapacity3 << 2);
                    }
                    else {
                      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity3 << 2);
                    }
                    if (allocation == 0) {
loopSetTranslatorError2:
                      translatorError = translator[9];
                      if (translatorError == 0) {
                        translatorError = 1;
                        translator[9] = 1;
                      }
                      goto setIlInstASrc02;
                    }
                    *tokenDataPtrAddr = allocation;
                    translator[0xc] = tokenCapacity3;
                    tokenCount = translator[0xb];
                  }
                  ilCopyCursor2 = &ilInstASrc0;
                  translator[0xb] = tokenCount + 7;
                  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
                  *tokenWritePtr = ilInstAOpcode;
                  tokenWritePtr[1] = ilInstADst;
                  tokenWritePtr[2] = ilInstADstMask;
                  do {
                    tokenWritePtr[3] = *ilCopyCursor2;
                    ilCopyNext2 = ilCopyCursor2 + 3;
                    ilCopyCursor2 = ilCopyCursor2 + 1;
                    tokenWritePtr[4] = *ilCopyNext2;
                    tokenWritePtr = tokenWritePtr + 2;
                  } while (&ilInstASrc2 != ilCopyCursor2);
loopSetTranslatorError3:
                  translatorError = translator[9];
                }
              }
              else {
                ilInstASrc1 = CONCAT22(1,fogTempPlus1);
                translatorError = translator[9];
                ilInstASrc1 = ilInstASrc1 | 0x400000;
                ilInstASwzWords[1] = ((unsigned char *)0x00003333);
                if (translatorError == 0) {
                  tokenCount = translator[0xb];
                  tokenCapacity3 = translator[0xc];
                  if (tokenCapacity3 < tokenCount + 7U) {
                    if (tokenCapacity3 == 0) {
                      tokenCapacity3 = 0x10;
                    }
                    else {
                      tokenCapacity3 = tokenCapacity3 << 1;
                    }
                    for (; tokenCapacity3 < tokenCount + 7U; tokenCapacity3 = tokenCapacity3 << 1) {
                    }
                    if (*tokenDataPtrAddr == 0) {
                      allocation = _malloc(tokenCapacity3 << 2);
                    }
                    else {
                      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity3 << 2);
                    }
                    if (allocation == 0) {
                      translatorError = translator[9];
                      if (translatorError == 0) {
                        translatorError = 1;
                        translator[9] = 1;
                      }
                      goto setIlInstASrc0;
                    }
                    *tokenDataPtrAddr = allocation;
                    translator[0xc] = tokenCapacity3;
                    tokenCount = translator[0xb];
                  }
                  ilCopyCursor2 = &ilInstASrc0;
                  translator[0xb] = tokenCount + 7;
                  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
                  *tokenWritePtr = ilInstAOpcode;
                  tokenWritePtr[1] = ilInstADst;
                  tokenWritePtr[2] = ilInstADstMask;
                  do {
                    tokenWritePtr[3] = *ilCopyCursor2;
                    ilCopyNext2 = ilCopyCursor2 + 3;
                    ilCopyCursor2 = ilCopyCursor2 + 1;
                    tokenWritePtr[4] = *ilCopyNext2;
                    tokenWritePtr = tokenWritePtr + 2;
                  } while (&ilInstASrc2 != ilCopyCursor2);
                  translatorError = translator[9];
                }
setIlInstASrc0:
                ilInstASrc0 = (undefined *)CONCAT22(4,tempRegisterHalf);
                ilInstASrc1 = CONCAT22(4,tempRegisterHalf);
                ilInstASwzWords[0] = ((unsigned char *)0x00003210);
                ilInstASwzWords[1] = ((unsigned char *)0x00003210);
                ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x49);
                ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
                ilInstASrc1 = ilInstASrc1 | 0x400000;
                if (translatorError == 0) {
                  tokenCount = translator[0xb];
                  tokenCapacity3 = translator[0xc];
                  if (tokenCapacity3 < tokenCount + 7U) {
                    if (tokenCapacity3 == 0) {
                      tokenCapacity3 = 0x10;
                    }
                    else {
                      tokenCapacity3 = tokenCapacity3 << 1;
                    }
                    for (; tokenCapacity3 < tokenCount + 7U; tokenCapacity3 = tokenCapacity3 << 1) {
                    }
                    if (*tokenDataPtrAddr == 0) {
                      allocation = _malloc(tokenCapacity3 << 2);
                    }
                    else {
                      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity3 << 2);
                    }
                    if (allocation == 0) goto loopSetTranslatorError2;
                    *tokenDataPtrAddr = allocation;
                    translator[0xc] = tokenCapacity3;
                    tokenCount = translator[0xb];
                  }
                  ilCopyCursor2 = &ilInstASrc0;
                  translator[0xb] = tokenCount + 7;
                  tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
                  *tokenWritePtr = ilInstAOpcode;
                  tokenWritePtr[1] = ilInstADst;
                  tokenWritePtr[2] = ilInstADstMask;
                  do {
                    tokenWritePtr[3] = *ilCopyCursor2;
                    ilCopyNext2 = ilCopyCursor2 + 3;
                    ilCopyCursor2 = ilCopyCursor2 + 1;
                    tokenWritePtr[4] = *ilCopyNext2;
                    tokenWritePtr = tokenWritePtr + 2;
                  } while (&ilInstASrc2 != ilCopyCursor2);
                  goto loopSetTranslatorError3;
                }
              }
setIlInstASrc02:
              ilInstASrc0 = (undefined *)CONCAT22(4,tempRegisterHalf);
              ilInstADstMask = ilInstADstMask | 0x100;
              ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x2d);
              ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
              ilInstASwzWords[0] = (undefined *)0xba98;
              if (translatorError != 0) goto setProgramObj4;
              tokenCount = translator[0xb];
              tokenCapacity3 = translator[0xc];
              if (tokenCapacity3 < tokenCount + 5U) {
                if (tokenCapacity3 == 0) {
                  tokenCapacity3 = 0x10;
                }
                else {
                  tokenCapacity3 = tokenCapacity3 << 1;
                }
                for (; tokenCapacity3 < tokenCount + 5U; tokenCapacity3 = tokenCapacity3 << 1) {
                }
                if (*tokenDataPtrAddr == 0) {
                  allocation = _malloc(tokenCapacity3 << 2);
                }
                else {
                  allocation = _realloc(*tokenDataPtrAddr,tokenCapacity3 << 2);
                }
                if (allocation == 0) goto loopSetTranslatorError;
                *tokenDataPtrAddr = allocation;
                translator[0xc] = tokenCapacity3;
                tokenCount = translator[0xb];
              }
              translator[0xb] = tokenCount + 5;
              tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
              *tokenWritePtr = ilInstAOpcode;
              tokenWritePtr[1] = ilInstADst;
              tokenWritePtr[2] = ilInstADstMask;
              tokenWritePtr[3] = ilInstASrc0;
              tokenWritePtr[4] = ilInstASwzWords[0];
setTranslatorError:
              translatorError = translator[9];
            }
setProgramObj4:
            programObj4 = *translator;
            ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x47);
            ilInstADstMask = 0x155;
            outputIndexShort = (short)outputIndex;
            ilInstADst = CONCAT22(4,outputIndexShort + (short)*(undefined4 *)(programObj4 + 0x10) + 1);
            ilInstADst = ilInstADst | 0x400000;
            ilInstASwzWords[0] = ((unsigned char *)0x00003210);
            ilInstASrc0 = (undefined *)CONCAT22(4,outputIndexShort + (short)*(undefined4 *)(programObj4 + 0x10) + 1);
            ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
            if (translatorError == 0) {
              tokenCount = translator[0xb];
              tokenCapacity3 = translator[0xc];
              if (tokenCapacity3 < tokenCount + 5U) {
                if (tokenCapacity3 == 0) {
                  tokenCapacity3 = 0x10;
                }
                else {
                  tokenCapacity3 = tokenCapacity3 << 1;
                }
                for (; tokenCapacity3 < tokenCount + 5U; tokenCapacity3 = tokenCapacity3 << 1) {
                }
                if (*tokenDataPtrAddr == 0) {
                  allocation = _malloc(tokenCapacity3 << 2);
                }
                else {
                  allocation = _realloc(*tokenDataPtrAddr,tokenCapacity3 << 2);
                }
                if (allocation == 0) {
                  translatorError = translator[9];
                  if (translatorError == 0) {
                    translatorError = 1;
                    translator[9] = 1;
                  }
                  programObj4 = *translator;
                  goto setIlInstAOpcode;
                }
                *tokenDataPtrAddr = allocation;
                translator[0xc] = tokenCapacity3;
                tokenCount = translator[0xb];
              }
              translator[0xb] = tokenCount + 5;
              tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
              *tokenWritePtr = ilInstAOpcode;
              tokenWritePtr[1] = ilInstADst;
              tokenWritePtr[2] = ilInstADstMask;
              tokenWritePtr[3] = ilInstASrc0;
              tokenWritePtr[4] = ilInstASwzWords[0];
              programObj4 = *translator;
              translatorError = translator[9];
            }
setIlInstAOpcode:
            ilInstAOpcode = CONCAT22((*(unsigned short *)((unsigned char *)&(ilInstAOpcode) + 0)),0x3f);
            ilInstASrc0 = (undefined *)CONCAT22(4,tempRegisterHalf);
            ilInstADstMask = 0x15;
            ilInstASwzWords[0] = ((unsigned char *)0x00003210);
            ilInstADst = CONCAT22(4,outputIndexShort + (short)*(undefined4 *)(programObj4 + 0x10) + 1);
            ilInstASrc0 = (undefined *)((uint)ilInstASrc0 | 0x400000);
            ilInstADst = ilInstADst | 0x400000;
            ilInstASrc2 = CONCAT22(1,fogTempRegister);
            ilInstASwzWords[1] = ((unsigned char *)0x00003210);
            ilInstASwzWords[2] = ((unsigned char *)0x00003210);
            ilInstASrc1 = CONCAT22(4,outputIndexShort + (short)*(undefined4 *)(programObj4 + 0x10) + 1);
            ilInstASrc2 = ilInstASrc2 | 0x400000;
            ilInstASrc1 = ilInstASrc1 | 0x400000;
            if (translatorError == 0) {
              tokenCount = translator[0xb];
              tokenCapacity3 = translator[0xc];
              if (tokenCapacity3 < tokenCount + 9U) {
                if (tokenCapacity3 == 0) {
                  tokenCapacity3 = 0x10;
                }
                else {
                  tokenCapacity3 = tokenCapacity3 << 1;
                }
                for (; tokenCapacity3 < tokenCount + 9U; tokenCapacity3 = tokenCapacity3 << 1) {
                }
                if (*tokenDataPtrAddr == 0) {
                  allocation = _malloc(tokenCapacity3 << 2);
                }
                else {
                  allocation = _realloc(*tokenDataPtrAddr,tokenCapacity3 << 2);
                }
                if (allocation == 0) {
                  if (translator[9] == 0) {
                    translator[9] = 1;
                  }
                  goto setChannelIndex;
                }
                *tokenDataPtrAddr = allocation;
                translator[0xc] = tokenCapacity3;
                tokenCount = translator[0xb];
              }
              ilCopyCursor = (undefined **)&ilInstASrc0;
              translator[0xb] = tokenCount + 9;
              tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
              *tokenWritePtr = ilInstAOpcode;
              tokenWritePtr[1] = ilInstADst;
              tokenWritePtr[2] = ilInstADstMask;
              do {
                tokenWritePtr[3] = *ilCopyCursor;
                ilCopyNext = ilCopyCursor + 3;
                ilCopyCursor = ilCopyCursor + 1;
                tokenWritePtr[4] = *ilCopyNext;
                tokenWritePtr = tokenWritePtr + 2;
              } while (ilInstASwzWords != ilCopyCursor);
            }
          }
setChannelIndex:
          channelIndex = 0;
          if (fogRequired) {
            do {
              if (((int)(*(uint *)(translator[0xd] + 0x20) >> 0x12 & 0xf) >> (channelIndex & 0x3f) & 1U) != 0
                 ) {
                tokenCount = translator[0xb];
                tokenCapacity2 = translator[0xc];
                if (tokenCapacity2 < tokenCount + 5U) {
                  if (tokenCapacity2 == 0) {
                    tokenCapacity2 = 0x10;
                  }
                  else {
                    tokenCapacity2 = tokenCapacity2 << 1;
                  }
                  for (; tokenCapacity2 < tokenCount + 5U; tokenCapacity2 = tokenCapacity2 << 1) {
                  }
                  if (*tokenDataPtrAddr == 0) {
                    allocation = _malloc(tokenCapacity2 << 2);
                  }
                  else {
                    allocation = _realloc(*tokenDataPtrAddr,tokenCapacity2 << 2);
                  }
                  if (allocation == 0) goto loopCheckTranslator2;
                  *tokenDataPtrAddr = allocation;
                  translator[0xc] = tokenCapacity2;
                  tokenCount = translator[0xb];
                }
                outputSrcToken = channelIndex & 0xffff | outputSrcToken & 0xffff0000;
                translator[0xb] = tokenCount + 5;
                fogTokenPtr = tokenCount * 4 + *tokenDataPtrAddr;
                *(undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr) = 0x47;
                *(undefined **)(fogTokenPtr + 0x10) = ((unsigned char *)0x00003210);
                *(uint *)(fogTokenPtr + 4) = outputSrcToken;
                *(undefined4 *)(fogTokenPtr + 8) = 0x55;
                *(uint *)(fogTokenPtr + 0xc) = outputDstToken;
              }
              moreChannels = channelIndex != 3;
              channelIndex = channelIndex + 1;
            } while (moreChannels);
            goto setOutputIndex;
          }
        }
        else {
          if ((*(ushort *)outputEntry & 0xf) != 7) goto returnTranslatorStatus;
          translatorFlags = translator[5];
          dstMaskToken = 0x155;
          translator[5] = translatorFlags | 0x40000000;
          outputSrcToken = 0x580000;
          if ((translatorFlags & 0x20000000) == 0) {
            swizzleXYZW = ((unsigned char *)0x00003212);
          }
        }
        tokenCount = translator[0xb];
        tokenCapacity3 = translator[0xc];
        if (tokenCapacity3 < tokenCount + 5U) {
          if (tokenCapacity3 == 0) {
            tokenCapacity3 = 0x10;
          }
          else {
            tokenCapacity3 = tokenCapacity3 << 1;
          }
          for (; tokenCapacity3 < tokenCount + 5U; tokenCapacity3 = tokenCapacity3 << 1) {
          }
          if (*tokenDataPtrAddr == 0) {
            allocation = _malloc(tokenCapacity3 << 2);
          }
          else {
            allocation = _realloc(*tokenDataPtrAddr,tokenCapacity3 << 2);
          }
          if (allocation == 0) goto loopCheckTranslator2;
          *tokenDataPtrAddr = allocation;
          translator[0xc] = tokenCapacity3;
          tokenCount = translator[0xb];
        }
        translator[0xb] = tokenCount + 5;
        tokenWritePtr = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
        *tokenWritePtr = 0x47;
        tokenWritePtr[4] = swizzleXYZW;
        tokenWritePtr[1] = outputSrcToken;
        tokenWritePtr[2] = dstMaskToken;
        tokenWritePtr[3] = outputDstToken;
      }
setOutputIndex:
      outputIndex = outputIndex + 1;
      outputEntry = outputEntry + 2;
    } while (outputCount != outputIndex);
  }
  tokenCount = translator[0xb];
  tokenCapacity = translator[0xc];
  if (tokenCapacity < tokenCount + 1U) {
    if (tokenCapacity == 0) {
      tokenCapacity = 0x10;
    }
    else {
      tokenCapacity = tokenCapacity << 1;
    }
    for (; tokenCapacity < tokenCount + 1U; tokenCapacity = tokenCapacity << 1) {
    }
    if (*tokenDataPtrAddr == 0) {
      allocation = _malloc(tokenCapacity << 2);
    }
    else {
      allocation = _realloc(*tokenDataPtrAddr,tokenCapacity << 2);
    }
    if (allocation != 0) {
      *tokenDataPtrAddr = allocation;
      translator[0xc] = tokenCapacity;
      tokenCount = translator[0xb];
      goto storeTranslator2;
    }
    translatorError = translator[9];
    if (translatorError == 0) {
      translatorError = 1;
      translator[9] = 1;
    }
    if (translatorError != 0) {
      return translatorError;
    }
  }
  else {
storeTranslator2:
    translator[0xb] = tokenCount + 1;
    tokenWritePtr3 = (undefined4 *)(tokenCount * 4 + *tokenDataPtrAddr);
  }
  *tokenWritePtr3 = 0x28;
  reservedTokenPos = translator[7];
  removedWords = reservedTokenPos - translator[6];
  if (removedWords != 0) {
    _memmove(translator[10] + translator[6] * 4,translator[10] + reservedTokenPos * 4,(translator[0xb] - reservedTokenPos) * 4);
    translator[7] = translator[6];
    translator[0xb] = translator[0xb] - removedWords;
  }
  if ((translator[5] & 0xc0000000U) == 0) {
    ((int (*)())fpilEmitEmptyProgram)(translator);
  }
returnTranslator:
  return translator[9];
}

/* floatToFp24 @ 0x4a7d0 (80 bytes) */
uint floatToFp24(double value)
{
  float floatValue;
  uint exponentBits;
  uint signBit;
  
  floatValue = (float)value;
  exponentBits = (uint)GH_F2U(floatValue) >> 0x17 & 0xff;
  signBit = (uint)GH_F2U(floatValue) >> 8 & 0x800000;
  if (exponentBits < 0x41) {
    return 0;
  }
  if (0xbf < exponentBits) {
    return signBit | 0x7fffff;
  }
  return (uint)GH_F2U(floatValue) >> 7 & 0xffff | signBit | (exponentBits - 0x40) * 0x10000;
}

/* fp24ToFloat @ 0x4a830 (40 bytes) */
double fp24ToFloat(uint fp24Bits)
{
  return (double)GH_U2F((unsigned int)(((fp24Bits & 0x800000) << 8 | ((fp24Bits >> 0x10 & 0x7f) + 0x40) * 0x800000 |
                        (fp24Bits & 0xffff) << 7)));
}

/* gldReselectProgramStream @ 0x4a860 (112 bytes) */
int gldReselectProgramStream(glContext, unusedArg2, unusedArg3, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  int glContext;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  char selectedByteFlag;
  
  if (((*(uint *)(glContext + 0x44) & 0x20000) != 0) && (*(int *)(glContext + 0x1e70) != 0)) {
    if ((*(uint *)(glContext + 0x44) & 0x2000) == 0) {
      selectedByteFlag = ((unsigned char *)0x00001136)[glContext];
    }
    else {
      selectedByteFlag = ((unsigned char *)0x000011d0)[glContext];
    }
    if (selectedByteFlag == '\0') {
                    
                    
      (**(code **)(glContext + 0x294c))(glContext);
      return;
    }
  }
                    
                    
  (**(code **)(glContext + 0x294c))(glContext,*(undefined4 *)(glContext + 0x1e5c));
  return;
}

/* gldRebindCurrentProgram @ 0x4a8f0 (140 bytes) */
void gldRebindCurrentProgram(int glContext,undefined4 unusedArg2,undefined4 unusedArgR5,undefined4 unused,double fprF1)
{
  if ((*(uint *)(glContext + 0x44) & 0x20000) == 0) {
    ffpsBuildProgram(glContext,0);
                    
                    
    (**(code **)(glContext + 0x294c))(glContext,*(undefined4 *)(glContext + 0x1e5c));
    return;
  }
  if ((*(uint *)(glContext + 0x44) & 0x2000) != 0) {
    ((undefined4 (*)())gld_compileFragmentProgram)(glContext,0,unusedArgR5,unused,fprF1);
    return;
  }
  atifsCompileCurrentShader(glContext);
  return;
}

/* gldResetProgramEntry @ 0x4a990 (100 bytes) */
int gldResetProgramEntry(glContext, unusedArg2)
  int glContext;
  undefined4 *unusedArg2;
{
  /* issue #74: this called freeAndNullField(unusedArg2+8) twice in a row with the identical argument.
   * freeAndNullField is a plain free-and-null helper, so the second call was always a guaranteed
   * no-op once the first succeeded (or, before the malloc_size() guard above, a second harmless
   * skip once the first left a bad value in place) - a redundant duplicate, not a real second
   * resource being freed. Removed; no other call site in this corpus uses a different offset
   * here to compare against, so there is no evidence a second, distinct field was ever meant
   * to be freed. */
  freeAndNullField(unusedArg2 + 8);
  *unusedArg2 = 0;
  unusedArg2[7] = 0;
  if ((glContext != 0) && (unusedArg2 == *(undefined4 **)(glContext + 0x1e68))) {
    *(undefined4 *)(glContext + 0x1e68) = 0;
  }
  return;
}

/* arbfpRebindIfOverLimit @ 0x4aa00 (136 bytes) */
int arbfpRebindIfOverLimit(ctx, unusedArg2)
  int ctx;
  int unusedArg2;
{
  undefined4 flagValue;
  undefined1 *flagBytePtr;
  
  flagBytePtr = *(undefined1 **)(((unsigned char *)0x00001488) + ctx);
  if ((flagBytePtr == (undefined1 *)0x0) ||
     ((*(int *)(flagBytePtr + 0x37cc) < 0x41 && (*(int *)(flagBytePtr + 0x37d0) < 0x41)))) {
    flagValue = 0;
  }
  else {
    if (unusedArg2 != 0) {
      *(undefined4 *)(ctx + 0x1e68) = 0;
      *flagBytePtr = 0;
      *(undefined4 *)(((unsigned char *)0x00001488) + ctx) = 0;
    }
    arbfpBindFragmentProgram(ctx,flagBytePtr);
    flagValue = 1;
  }
  return flagValue;
}

/* gldResetProgramEntryDefaults @ 0x4aa90 (196 bytes) */
int gldResetProgramEntryDefaults(glContext, programEntry)
  int glContext;
  uint *programEntry;
{
  uint *nextUnit;
  uint *unitCursor;
  int loopIndex;
  
  if (((unsigned char *)0x000013b2)[glContext] != '\0') {
    loopIndex = 0;
    unitCursor = programEntry;
    do {
      nextUnit = unitCursor + 1;
      loopIndex = loopIndex + 1;
      unitCursor[0x22] = unitCursor[0x22] & 0xfe001fc0 | 0xd10000;
      unitCursor = unitCursor + 1;
      *unitCursor = *nextUnit & 0xfffcffef;
    } while (loopIndex < (int)(uint)(byte)((unsigned char *)0x000013b2)[glContext]);
  }
  programEntry[0x87] = 0;
  programEntry[0x83] = 1;
  programEntry[0x84] = 0;
  programEntry[0x86] = 0;
  *programEntry = *programEntry & 0xfffffff0;
  programEntry[1] = programEntry[1] & 0xfffc0fff | 0x10000;
  programEntry[0x22] = programEntry[0x22] & 0xffffe03f;
  programEntry[0x82] = programEntry[0x82] & 0xfffff800 | 0x80;
  return;
}

/* gldInitProgramCacheEntry @ 0x4ab60 (304 bytes) */
int gldInitProgramCacheEntry(glContext)
  int glContext;
{
  int loopIndex;
  int clearByteOffset;
  int listByteOffset;
  int wordsLeft;
  
  gld_buildUnitSetupCmdList(glContext,(*(uint *)(PTR_DAT_001e88c8 + (uint)*(byte *)(glContext + 0x293f) * 0x24 + 0x20
                                 ) ^ 0x800000) >> 0x17 & 1,1);
  *(uint *)(((unsigned char *)0x00001544) + *(int *)(glContext + 0x1e60)) =
       *(uint *)(((unsigned char *)0x00001544) + *(int *)(glContext + 0x1e60)) & 0xffc0003f | 0x40;
  *(undefined4 *)(((unsigned char *)0x00001098) + *(int *)(glContext + 0x1e60)) = 1;
  ((int (*)())gldResetProgramEntryDefaults)(glContext,((unsigned char *)0x000010ec) + *(int *)(glContext + 0x1e60));
  *(undefined4 *)(glContext + 0x1e84) = 0;
  *(undefined4 *)(glContext + 0x277c) = 0xffffffff;
  *(undefined4 *)(glContext + 0x1e64) = 0;
  *(undefined4 *)(glContext + 0x1e80) = 0;
  if (0 < *(int *)(glContext + 0x1e74)) {
    loopIndex = 0;
    do {
      listByteOffset = loopIndex * 4;
      loopIndex = loopIndex + 1;
      ((unsigned char *)0x000010e9)[*(int *)(listByteOffset + *(int *)(glContext + 0x1e7c))] = 0;
      ((unsigned char *)0x000010ea)[*(int *)(listByteOffset + *(int *)(glContext + 0x1e7c))] = 0;
    } while (loopIndex < *(int *)(glContext + 0x1e74));
  }
  *(undefined4 *)(glContext + 0x1e74) = 0;
  if (*(int *)(glContext + 0x1e5c) == 0) {
    *(undefined4 *)(glContext + 0x1e5c) = *(undefined4 *)(glContext + 0x1e60);
  }
  *(undefined4 *)(glContext + 0x1e84) = 0;
  *(undefined4 *)(glContext + 0x1e80) = 0;
  wordsLeft = 8;
  clearByteOffset = 0;
  do {
    *(undefined4 *)(glContext + 0x1e88 + clearByteOffset) = 0;
    clearByteOffset = clearByteOffset + 4;
    wordsLeft = wordsLeft + -1;
  } while (wordsLeft != 0);
  return;
}

/* gldUploadProgramState @ 0x4ac90 (1272 bytes) */
int gldUploadProgramState(glContext)
  int glContext;
{
  int copyCountdown;
  int uploadDwordCount;
  int unitIndex;
  int glStateBlock;
  uint uploadWord28;
  uint uploadWord25;
  uint uploadWord0;
  uint bankBase;
  uint unitMask;
  int *bankSrcBase;
  int *maskWordPtr;
  int contextWordCursor;
  int programFlagArg;
  int unitScaleCursor;
  int depthGroup;
  uint uploadWord26;
  uint uploadWord23;
  uint registerIndex;
  bool moreBanks;
  uint uploadWord27;
  uint uploadWord24;
  uint loopIndex;
  bool depthScaleSeen;
  uint dirtyWordOffset;
  int texObj;
  code *bankDstBase;
  int *uploadSizePtr;
  int *bankCursor;
  int *regSrcCursor;
  code *regDstCursor;
  int *glContextWord1e5c;
  uint constDirtyMask;
  uint unitLimit;
  int texBindingCursor;
  uint *stateBlock;
  int fp24Value;
  double depthCompareValue;
  undefined4 fogColorR;
  undefined4 fogColorG;
  undefined4 fogColorB;
  undefined4 fogColorPad;
  float fogLinearScale;
  float fogLinearEndScaled;
  float fogExpScale;
  float fogExp2Scale;
  
  glContextWord1e5c = *(int **)(glContext + 0x1e5c);
  glContextWord1e5c[0x42e] = glContextWord1e5c[0x42e] & 0xffff00ff;
  unitLimit = (uint)*(byte *)(glContext + 0x2b);
  if ((uint)(byte)((unsigned char *)0x000013b2)[glContext] < (uint)*(byte *)(glContext + 0x2b)) {
    unitLimit = (uint)(byte)((unsigned char *)0x000013b2)[glContext];
  }
  depthScaleSeen = false;
  if (unitLimit != 0) {
    loopIndex = 0;
    texBindingCursor = glContext;
    do {
      texObj = *(int *)(((unsigned char *)0x000013f8) + texBindingCursor);
      if (((texObj != 0) && (*(short *)(texObj + 0x38) == 0x1902)) &&
         (depthCompareValue = (double)*(float *)(texObj + 0x50), depthCompareValue != 0.0)) {
        depthGroup = ((int)loopIndex >> 2) + (uint)((int)loopIndex < 0 && (loopIndex & 3) != 0);
        if (depthGroup == 1) {
          fp24Value = ((uint (*)())floatToFp24)(depthCompareValue);
          glContextWord1e5c[0x68] = fp24Value;
        }
        else if (depthGroup < 2) {
          if (depthGroup == 0) {
            fp24Value = ((uint (*)())floatToFp24)(depthCompareValue);
            glContextWord1e5c[99] = fp24Value;
          }
        }
        else if (depthGroup == 2) {
          fp24Value = ((uint (*)())floatToFp24)(depthCompareValue);
          glContextWord1e5c[0x6d] = fp24Value;
        }
        else if (depthGroup == 3) {
          fp24Value = ((uint (*)())floatToFp24)(depthCompareValue);
          glContextWord1e5c[0x72] = fp24Value;
        }
        dirtyWordOffset = depthGroup + 0x10U >> 3 & 0x1ffffffc;
        depthScaleSeen = true;
        *(uint *)((int)glContextWord1e5c + (int)(((unsigned char *)0x000010b8) + dirtyWordOffset)) =
             1 << (depthGroup + 0x10U & 0x1f) | *(uint *)((int)glContextWord1e5c + (int)(((unsigned char *)0x000010b8) + dirtyWordOffset));
      }
      loopIndex = loopIndex + 1;
      texBindingCursor = texBindingCursor + 4;
    } while (unitLimit != loopIndex);
  }
  if (*(char *)(glContext + 0x121) != '\0') {
    glStateBlock = *(int *)(*(int *)(glContext + 4) + 0x10);
    fogColorR = *(undefined4 *)(((unsigned char *)0x00002de0) + glStateBlock);
    fogColorG = *(undefined4 *)(((unsigned char *)0x00002de4) + glStateBlock);
    fogColorB = *(undefined4 *)(((unsigned char *)0x00002de8) + glStateBlock);
    fogColorPad = 0;
    fogLinearScale = -1.0 / (*(float *)(((unsigned char *)0x00002df8) + glStateBlock) - *(float *)(((unsigned char *)0x00002df4) + glStateBlock));
    fogLinearEndScaled = *(float *)(((unsigned char *)0x00002df8) + glStateBlock) * *(float *)(((unsigned char *)0x00002dfc) + glStateBlock);
    fogExpScale = *(float *)(((unsigned char *)0x00002df0) + glStateBlock) / 0.6931472;
    fogExp2Scale = *(float *)(((unsigned char *)0x00002df0) + glStateBlock) / 0.83255464;
    (**(code **)(((unsigned char *)0x00001280) + glContext))
              (glContext,0,
               *(undefined4 *)(((unsigned char *)0x00003878) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(glContext + 0x1e5c)))
               ,*(undefined4 *)
                 (((unsigned char *)0x00003878) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(glContext + 0x1e5c))),&fogColorR,1,
               1,*(code **)(((unsigned char *)0x00001280) + glContext));
    (**(code **)(((unsigned char *)0x00001280) + glContext))
              (glContext,0,
               *(undefined4 *)(((unsigned char *)0x0000387c) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(glContext + 0x1e5c)))
               ,*(undefined4 *)
                 (((unsigned char *)0x0000387c) + *(int *)(((unsigned char *)0x000036c0) + *(int *)(glContext + 0x1e5c))),&fogLinearScale,1,
               1);
  }
  noop_b5190(glContext,*(int *)(glContext + 0x1e5c) + 0x1784,
               ((unsigned char *)0x00001660) + *(int *)(glContext + 0x1e5c));
  unitMask = (uint)*(byte *)(glContext + 0x20);
  if (unitMask != 0) {
    unitIndex = 0;
    unitScaleCursor = glContext + 0x28b4;
    do {
      if ((unitMask & 1) != 0) {
        (**(code **)(((unsigned char *)0x00001280) + glContext))(glContext,0,unitIndex + 0x14,unitIndex + 0x14,unitScaleCursor,1,1);
      }
      unitMask = unitMask >> 1;
      unitIndex = unitIndex + 1;
      unitScaleCursor = unitScaleCursor + 0x10;
    } while (unitMask != 0);
  }
  if ((depthScaleSeen) && (*(undefined1 *)((int)glContextWord1e5c + 0x10eb) = 0, glContextWord1e5c == *(int **)(glContext + 0x1e64)))
  {
    if (*(int *)(glContext + 0x23e0) == 0) {
      uploadDwordCount = glContextWord1e5c[0xdac];
      stateBlock = (uint *)(glContextWord1e5c + 0x43b);
      uploadSizePtr = glContextWord1e5c + 0x423;
      bankCursor = glContextWord1e5c;
    }
    else {
      uploadDwordCount = glContextWord1e5c[0xdaf];
      stateBlock = (uint *)(glContextWord1e5c + 0x4c6);
      uploadSizePtr = glContextWord1e5c + 0x424;
      bankCursor = glContextWord1e5c + 7;
    }
    *(int **)(glContext + 0x1e64) = glContextWord1e5c;
    if (*bankCursor == 0) {
      programFlagArg = bankCursor[1];
      *(undefined4 *)(0x00002348 + glContext + 4) = 1;
      *(int *)(glContext + 0x2350) = programFlagArg;
      *(int *)(glContext + 0x2338) = *uploadSizePtr;
      *bankCursor = 1;
      *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x100000;
    }
    if (*(char *)((int)glContextWord1e5c + 0x10eb) == '\0') {
      copyCountdown = 8;
      contextWordCursor = glContext;
      bankCursor = glContextWord1e5c;
      do {
        maskWordPtr = bankCursor + 0x42e;
        bankCursor = bankCursor + 1;
        *(int *)(contextWordCursor + 0x1e88) = *maskWordPtr;
        contextWordCursor = contextWordCursor + 4;
        copyCountdown = copyCountdown + -1;
      } while (copyCountdown != 0);
      bankBase = 0;
      bankDstBase = 0x00001f30 + glContext;
      bankSrcBase = glContextWord1e5c + 0x20;
      bankCursor = glContextWord1e5c;
      do {
        constDirtyMask = bankCursor[0x42e];
        if (constDirtyMask != 0) {
          regSrcCursor = bankSrcBase + 3;
          regDstCursor = bankDstBase + 8;
          registerIndex = bankBase;
          do {
            if (((constDirtyMask & 1) != 0) && ((1 << (registerIndex & 0x3f) & glContextWord1e5c[0x436]) == 0)) {
              *(int *)regDstCursor = *regSrcCursor;
              *(int *)(regDstCursor + 4) = regSrcCursor[1];
              *(int *)(regDstCursor + 8) = regSrcCursor[2];
              *(int *)(regDstCursor + 0xc) = regSrcCursor[3];
            }
            constDirtyMask = constDirtyMask >> 1;
            registerIndex = registerIndex + 1;
            regSrcCursor = regSrcCursor + 4;
            regDstCursor = regDstCursor + 0x10;
          } while (constDirtyMask != 0);
        }
        moreBanks = bankBase != 0xe0;
        bankCursor = bankCursor + 1;
        bankSrcBase = bankSrcBase + 0x80;
        bankDstBase = bankDstBase + 0x200;
        bankBase = bankBase + 0x20;
      } while (moreBanks);
      *(undefined1 *)((int)glContextWord1e5c + 0x10eb) = 1;
      *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x40000000;
    }
    if (stateBlock[0x85] == 0) {
      *(uint *)(glContext + 0x1f2c) = stateBlock[0x82];
      uploadWord0 = *stateBlock;
      *(int *)(glContext + 0x1f34) = uploadDwordCount;
      *(uint *)(0x00001f30 + glContext) = uploadWord0 & 0xffffff1f;
      _memcpy(glContext + 0x1ea8,stateBlock + 1,uploadDwordCount << 2);
      uploadWord23 = stateBlock[0x23];
      uploadWord24 = stateBlock[0x24];
      uploadWord25 = stateBlock[0x25];
      *(uint *)(glContext + 0x1ee8) = stateBlock[0x22];
      *(uint *)(glContext + 0x1eec) = uploadWord23;
      *(uint *)(glContext + 0x1ef0) = uploadWord24;
      *(uint *)(glContext + 0x1ef4) = uploadWord25;
      uploadWord26 = stateBlock[0x26];
      uploadWord27 = stateBlock[0x27];
      uploadWord28 = stateBlock[0x28];
      *(uint *)(glContext + 0x1f04) = stateBlock[0x29];
      *(uint *)(glContext + 0x1ef8) = uploadWord26;
      *(uint *)(glContext + 0x1efc) = uploadWord27;
      *(uint *)(glContext + 0x1f00) = uploadWord28;
      stateBlock[0x85] = 1;
      *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) | 0x80000000;
    }
  }
  return;
}

/* gldSetProgramStreamMode @ 0x4b190 (700 bytes) */
int gldSetProgramStreamMode(glContext, mode)
  int glContext;
  int mode;
{
  char needsUpdate;
  undefined4 registerDirty;
  int glContextWord1e5c;
  bool modeIsZero;
  bool useSecondary;
  char selectedByteFlag;
  code *dirtyCallback;
  undefined1 *programStatePtr;
  uint streamComponents;
  int specialStream;
  undefined4 programFlag;
  int programEntry;
  
  specialStream = *(int *)(glContext + 0x276c);
  if (((*(uint *)(glContext + 0x44) & 0x20000) == 0) || (*(int *)(glContext + 0x1e70) == 0)) {
loopSetProgramFlag:
    programFlag = 1;
    programEntry = *(int *)(glContext + 0x1e5c);
    useSecondary = false;
  }
  else {
    if ((*(uint *)(glContext + 0x44) & 0x2000) == 0) {
      selectedByteFlag = ((unsigned char *)0x00001136)[glContext];
    }
    else {
      selectedByteFlag = ((unsigned char *)0x000011d0)[glContext];
    }
    if (selectedByteFlag != '\0') goto loopSetProgramFlag;
    programFlag = 0;
    programEntry = *(int *)(glContext + 0x1e70);
    useSecondary = true;
  }
  modeIsZero = mode == 0;
  if (modeIsZero) {
    *(undefined4 *)(glContext + 0x23e0) = 0;
  }
  else {
    *(undefined4 *)(glContext + 0x23e0) = 1;
  }
  programStatePtr = *(undefined1 **)(((unsigned char *)0x000036c0) + programEntry);
  if (programStatePtr == (undefined1 *)0x0) {
    return;
  }
  if (mode == *(int *)(((unsigned char *)0x000010e4) + programEntry)) {
    if (((unsigned char *)0x000036c4)[programEntry] == '\0') {
      if (!modeIsZero) {
        needsUpdate = '\0';
        goto checkNeedsUpdate;
      }
      needsUpdate = ((unsigned char *)0x000010e9)[programEntry];
    }
    else {
      if (modeIsZero) goto storeX000010e4;
      needsUpdate = ((unsigned char *)0x000010ea)[programEntry];
    }
    if (needsUpdate != '\0') {
      return;
    }
    if (useSecondary) {
      *programStatePtr = (char)programFlag;
      ((unsigned char *)0x000010e9)[programEntry] = 0;
      ((unsigned char *)0x000010ea)[programEntry] = 0;
loopCallArbfpBindFragmentProgram:
      arbfpBindFragmentProgram(glContext,*(undefined4 *)(((unsigned char *)0x000036c0) + programEntry));
      return;
    }
    glContextWord1e5c = *(int *)(glContext + 0x1e5c);
    ((unsigned char *)0x000010e9)[glContextWord1e5c] = 0;
    ((unsigned char *)0x000010ea)[glContextWord1e5c] = 0;
    (**(code **)(glContext + 0x294c))(glContext,glContextWord1e5c);
    dirtyCallback = *(code **)(((unsigned char *)0x00001330) + glContext);
    registerDirty = *(undefined4 *)(glContext + 0x1930);
  }
  else {
    if (!modeIsZero) {
      needsUpdate = ((unsigned char *)0x000036c4)[programEntry];
checkNeedsUpdate:
      if (needsUpdate == '\0') {
        if (useSecondary) {
          arbfpCompileFragmentProgram(glContext,0,programStatePtr,programStatePtr + 4);
        }
        else {
          ffpsBuildProgram(glContext,1);
        }
        ((unsigned char *)0x000036c4)[programEntry] = 1;
      }
    }
storeX000010e4:
    *(int *)(((unsigned char *)0x000010e4) + programEntry) = mode;
    *(int *)(((unsigned char *)0x00001528) + programEntry) = mode;
    *(int *)(((unsigned char *)0x000012fc) + programEntry) = mode;
    if (mode == 2) {
      specialStream = specialStream << 2;
      streamComponents = 4;
    }
    else {
      specialStream = specialStream * 4;
      streamComponents = (*(uint *)(((unsigned char *)0x000013e0) + specialStream + programEntry) >> 6 & 0x3f) + 1 & 0x3f;
    }
    *(uint *)(((unsigned char *)0x000013e0) + specialStream + programEntry) =
         streamComponents << 0xc | *(uint *)(((unsigned char *)0x000013e0) + specialStream + programEntry) & 0xff000fff | 0xfc0000;
    if (useSecondary) {
      **(undefined1 **)(((unsigned char *)0x000036c0) + programEntry) = (char)programFlag;
      ((unsigned char *)0x000010e9)[programEntry] = 0;
      ((unsigned char *)0x000010ea)[programEntry] = 0;
      *(undefined4 *)(glContext + 0x1e68) = programFlag;
      goto loopCallArbfpBindFragmentProgram;
    }
    glContextWord1e5c = *(int *)(glContext + 0x1e5c);
    ((unsigned char *)0x000010e9)[glContextWord1e5c] = 0;
    ((unsigned char *)0x000010ea)[glContextWord1e5c] = 0;
    *(undefined4 *)(glContext + 0x1e68) = 0;
    (**(code **)(((unsigned char *)0x00001334) + glContext))(glContext,1);
    (**(code **)(glContext + 0x294c))(glContext,glContextWord1e5c);
    dirtyCallback = *(code **)(((unsigned char *)0x00001330) + glContext);
    registerDirty = *(undefined4 *)(glContext + 0x1930);
  }
  (*dirtyCallback)(glContext,registerDirty);
  *(uint *)(glContext + 0x1930) = *(uint *)(glContext + 0x1930) & 0x3fefffff;
  return;
}

/* gldClearBoundSlot @ 0x4b480 (148 bytes) */
int gldClearBoundSlot(glContext, slotIndex)
  int glContext;
  int slotIndex;
{
  int slotAddr;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  code *a6;
  undefined4 registerDirty;
  
  slotAddr = slotIndex * 4 + glContext;
  if (*(int *)(((unsigned char *)0x00001448) + slotAddr) != 0) {
    registerDirty = *(undefined4 *)(glContext + 0x1930);
    *(undefined4 *)(glContext + 0x23e0) = 0;
    **(undefined1 **)(((unsigned char *)0x00001448) + slotAddr) = 0;
    (**(code **)(((unsigned char *)0x00001290) + glContext))
              (glContext,*(undefined4 *)(((unsigned char *)0x00001448) + slotAddr),in_r5,in_r6,in_r7,in_r8,0);
    a6 = *(code **)(((unsigned char *)0x00001330) + glContext);
    *(uint *)(glContext + 0x1f2c) = *(uint *)(glContext + 0x1f2c) & 0xfffff800 | 0x80;
    (*a6)(glContext,0xc0100000,in_r5,in_r6,in_r7,in_r8,a6);
    *(undefined4 *)(glContext + 0x1930) = registerDirty;
  }
  return;
}

/* gldRemoveProgramFromList @ 0x4b520 (160 bytes) */
int gldRemoveProgramFromList(glContext, programEntry)
  int glContext;
  int programEntry;
{
  int *glContextWord1e7c;
  int loopIndex;
  int listCount;
  int searchCountdown;
  int shiftByteOffset;
  
  listCount = *(int *)(glContext + 0x1e74);
  while( true ) {
    if (listCount < 1) {
      return;
    }
    glContextWord1e7c = *(int **)(glContext + 0x1e7c);
    loopIndex = 0;
    if (programEntry != *glContextWord1e7c) {
      loopIndex = 0;
      searchCountdown = listCount;
      do {
        loopIndex = loopIndex + 1;
        searchCountdown = searchCountdown + -1;
        if (searchCountdown == 0) {
          return;
        }
      } while (programEntry != glContextWord1e7c[loopIndex]);
    }
    listCount = listCount + -1;
    *(int *)(glContext + 0x1e74) = listCount;
    if (listCount == loopIndex) break;
    if (loopIndex < listCount) {
      shiftByteOffset = loopIndex << 2;
      while( true ) {
        loopIndex = loopIndex + 1;
        *(undefined4 *)(shiftByteOffset + (int)glContextWord1e7c) = *(undefined4 *)((int)glContextWord1e7c + shiftByteOffset + 4);
        shiftByteOffset = shiftByteOffset + 4;
        listCount = *(int *)(glContext + 0x1e74);
        if (listCount <= loopIndex) break;
        glContextWord1e7c = *(int **)(glContext + 0x1e7c);
      }
    }
  }
  return;
}

/* gldReleaseProgramEntry @ 0x4b5d0 (296 bytes) */
int gldReleaseProgramEntry(glContext, programEntry)
  int glContext;
  int programEntry;
{
  int *glContextWord1e7c;
  int loopIndex;
  int listCount;
  int searchCountdown;
  int shiftByteOffset;
  int stateBlock;
  
  ((int (*)())gldResetProgramEntry)(glContext,programEntry);
  if ((glContext != 0) && (stateBlock = *(int *)(((unsigned char *)0x000036c0) + programEntry), stateBlock != 0)) {
    (**(code **)(glContext + 0x18))(*(undefined4 *)(stateBlock + 0xc));
    *(undefined4 *)(stateBlock + 0xc) = 0;
    stateBlock = *(int *)(((unsigned char *)0x000036c0) + programEntry);
    listCount = *(int *)(glContext + 0x1e74);
    while (0 < listCount) {
      glContextWord1e7c = *(int **)(glContext + 0x1e7c);
      loopIndex = 0;
      if (programEntry != *glContextWord1e7c) {
        loopIndex = 0;
        searchCountdown = listCount;
        do {
          loopIndex = loopIndex + 1;
          searchCountdown = searchCountdown + -1;
          if (searchCountdown == 0) goto callProgramEntryReleaseCallback;
        } while (glContextWord1e7c[loopIndex] != programEntry);
      }
      listCount = listCount + -1;
      *(int *)(glContext + 0x1e74) = listCount;
      if (listCount == loopIndex) break;
      if (loopIndex < listCount) {
        shiftByteOffset = loopIndex << 2;
        while( true ) {
          loopIndex = loopIndex + 1;
          *(undefined4 *)(shiftByteOffset + (int)glContextWord1e7c) = *(undefined4 *)((int)glContextWord1e7c + shiftByteOffset + 4);
          shiftByteOffset = shiftByteOffset + 4;
          listCount = *(int *)(glContext + 0x1e74);
          if (listCount <= loopIndex) break;
          glContextWord1e7c = *(int **)(glContext + 0x1e7c);
        }
      }
    }
callProgramEntryReleaseCallback:
    (**(code **)(glContext + 0x18))(*(undefined4 *)(((unsigned char *)0x000036c0) + programEntry));
    if (programEntry != stateBlock + 0x124) {
      *(undefined4 *)(((unsigned char *)0x000036c0) + programEntry) = 0;
    }
  }
  return;
}

/* gldFlushProgramCache @ 0x4b710 (188 bytes) */
int gldFlushProgramCache(glContext)
  int glContext;
{
  undefined *programEntry;
  int loopIndex;
  undefined *entryByteOffset;
  
  if (*(short *)(glContext + 0x1e6c) != 0) {
    loopIndex = 0;
    entryByteOffset = (undefined *)0x0;
    do {
      loopIndex = loopIndex + 1;
      programEntry = entryByteOffset + *(int *)(glContext + 0x1e60);
      entryByteOffset = ((unsigned char *)0x00003754U) + (int)entryByteOffset;
      *(undefined4 *)(programEntry + 0x1780) = 0;
      ((int (*)())gldReleaseProgramEntry)(glContext,programEntry);
    } while (loopIndex < (int)(uint)*(ushort *)(glContext + 0x1e6c));
  }
  _free(*(undefined4 *)(glContext + 0x1e60));
  _memset(*(undefined4 *)(((unsigned char *)0x00001114) + glContext),0xff,
          (uint)*(ushort *)(((unsigned char *)0x00001110) + glContext) << 1);
  *(undefined2 *)(glContext + 0x1e6c) = 0;
  *(undefined4 *)(glContext + 0x1e5c) = 0;
  *(undefined4 *)(glContext + 0x1e80) = 0;
  *(undefined4 *)(glContext + 0x1e84) = 0;
  *(undefined4 *)(glContext + 0x1e60) = 0;
  return;
}

/* gldMarkAllProgramsDirty @ 0x4b7d0 (392 bytes) */
int gldMarkAllProgramsDirty(glContext)
  int glContext;
{
  uint shaderCount;
  int shaderOffset;
  int shaderEntry;
  int programEntries;
  int entriesLeft;
  undefined4 allocation;
  int programTable;
  uint programCount;
  uint loopIndex2;
  int loopIndex;
  int shaderList;
  
  shaderList = *(int *)(((unsigned char *)0x0000112c) + glContext);
  ((int (*)())gldFlushProgramCache)(glContext);
  *(undefined2 *)(glContext + 0x1e6c) = 1;
  allocation = _malloc(((unsigned char *)0x00003754U));
  *(undefined4 *)(glContext + 0x1e60) = allocation;
  _memset(allocation,0,((unsigned char *)0x00003754U));
  *(undefined4 *)(glContext + 0x1e5c) = 0;
  ((int (*)())gldInitProgramCacheEntry)(glContext);
  *(undefined2 *)(((unsigned char *)0x000015c8) + *(int *)(glContext + 0x1e60)) = 0xffff;
  gld_destroyUnitCmdLists(glContext);
  programTable = *(int *)(((unsigned char *)0x00001154) + glContext);
  programEntries = *(int *)(programTable + 0x88);
  if (programEntries != 0) {
    programCount = *(uint *)(programTable + 4);
    loopIndex = 0;
    if (programCount != 0) {
      do {
        programEntries = *(int *)(*(int *)(((unsigned char *)0x0000113c) + glContext) * 4 +
                        *(int *)(loopIndex * 0x78 + programEntries + 0x70));
        if (programEntries != 0) {
          *(undefined1 *)(programEntries + 0x119) = 1;
          programCount = *(uint *)(programTable + 4);
        }
        entriesLeft = programCount - loopIndex;
        if ((programCount < loopIndex + 1U) || (programCount == 0)) {
          entriesLeft = 1;
        }
        do {
          loopIndex = loopIndex + 1;
          entriesLeft = entriesLeft + -1;
          if (entriesLeft == 0) goto setShaderCount;
          programEntries = *(int *)(programTable + 0x88);
        } while (programEntries == 0);
      } while( true );
    }
  }
setShaderCount:
  shaderCount = *(uint *)(shaderList + 4);
  if (shaderCount != 0) {
    loopIndex2 = 0;
    shaderOffset = 0;
    do {
      shaderEntry = shaderOffset + *(int *)(shaderList + 8);
      if (((*(int *)(shaderEntry + 4) == 0x8804) &&
          (shaderEntry = *(int *)(*(int *)(shaderEntry + 0x14) + 0x70), shaderEntry != 0)) &&
         (shaderEntry = *(int *)(*(int *)(((unsigned char *)0x00001130) + glContext) * 4 + shaderEntry), shaderEntry != 0)) {
        *(undefined1 *)(shaderEntry + 0x119) = 1;
        shaderCount = *(uint *)(shaderList + 4);
      }
      loopIndex2 = loopIndex2 + 1;
      shaderOffset = shaderOffset + 0x18;
    } while (loopIndex2 < shaderCount);
  }
  return;
}

/* gldGrowProgramHashTable @ 0x4b980 (616 bytes) */
int gldGrowProgramHashTable(glContext, growBy)
  int glContext;
  int growBy;
{
  uint *hashTailCursor;
  int entryPtr;
  ushort nextEntryIndex;
  int newBucketByteOffset;
  uint rotateShift;
  uint rotateAmount;
  int newTable;
  int oldTable;
  uint *keyEnd;
  uint hashValue;
  uint *hashBlockBase;
  uint *hashBlockCursor;
  uint *hashBlockLimit;
  uint entryIndex;
  uint oldBucketCount;
  uint loopIndex;
  int programEntries;
  
  oldBucketCount = (uint)*(ushort *)(((unsigned char *)0x00001110) + glContext);
  programEntries = *(int *)(glContext + 0x1e60);
  if (oldBucketCount != 0x2811) {
    *(short *)(((unsigned char *)0x00001110) + glContext) = (short)(oldBucketCount + growBy);
    if (0x2811 < (oldBucketCount + growBy & 0xffff)) {
      *(undefined2 *)(((unsigned char *)0x00001110) + glContext) = 0x2811;
    }
    newTable = (**(code **)(glContext + 0xc))((uint)*(ushort *)(((unsigned char *)0x00001110) + glContext) << 1);
    _memset(newTable,0xff,(uint)*(ushort *)(((unsigned char *)0x00001110) + glContext) << 1);
    if (oldBucketCount == 0) {
      oldTable = *(int *)(((unsigned char *)0x00001114) + glContext);
    }
    else {
      oldTable = *(int *)(((unsigned char *)0x00001114) + glContext);
      loopIndex = 0;
      do {
        entryIndex = (uint)*(ushort *)(loopIndex * 2 + oldTable);
        if (entryIndex != 0xffff) {
          do {
            entryPtr = programEntries + entryIndex * 0x3754;
            keyEnd = (uint *)(((unsigned char *)0x000015c8) + entryPtr);
            hashBlockBase = (uint *)(((unsigned char *)0x00001544) + entryPtr);
            if (keyEnd < ((unsigned char *)0x00001570) + entryPtr) {
              hashValue = 0;
            }
            else {
              hashValue = 0;
              hashBlockLimit = (uint *)(((unsigned char *)0x00001570) + entryPtr);
              hashBlockCursor = hashBlockBase;
              do {
                hashBlockBase = hashBlockLimit;
                hashValue = hashValue ^ *hashBlockCursor ^ (hashBlockCursor[1] << 3 | hashBlockCursor[1] >> 0x1d) ^
                        (hashBlockCursor[2] << 6 | hashBlockCursor[2] >> 0x1a) ^
                        (hashBlockCursor[3] << 9 | hashBlockCursor[3] >> 0x17) ^
                        (hashBlockCursor[4] << 0xc | hashBlockCursor[4] >> 0x14) ^
                        (hashBlockCursor[5] << 0xf | hashBlockCursor[5] >> 0x11) ^
                        (hashBlockCursor[6] << 0x12 | hashBlockCursor[6] >> 0xe) ^
                        (hashBlockCursor[7] << 0x15 | hashBlockCursor[7] >> 0xb) ^
                        (hashBlockCursor[8] << 0x18 | hashBlockCursor[8] >> 8) ^
                        (hashBlockCursor[9] << 0x1b | hashBlockCursor[9] >> 5) ^
                        (hashBlockCursor[10] << 0x1e | hashBlockCursor[10] >> 2);
                hashBlockLimit = hashBlockBase + 0xb;
                hashBlockCursor = hashBlockBase;
              } while (hashBlockBase + 0xb <= keyEnd);
            }
            hashTailCursor = hashBlockBase + 5;
            if (keyEnd < hashTailCursor) {
              rotateAmount = 0;
              hashTailCursor = hashBlockBase;
            }
            else {
              rotateAmount = 0xf;
              hashValue = hashValue ^ *hashBlockBase ^ (hashBlockBase[1] << 3 | hashBlockBase[1] >> 0x1d) ^
                      (hashBlockBase[2] << 6 | hashBlockBase[2] >> 0x1a) ^ (hashBlockBase[3] << 9 | hashBlockBase[3] >> 0x17) ^
                      (hashBlockBase[4] << 0xc | hashBlockBase[4] >> 0x14);
            }
            for (; hashTailCursor < keyEnd; hashTailCursor = hashTailCursor + 1) {
              rotateShift = rotateAmount & 0x1f;
              rotateAmount = rotateAmount + 3;
              hashValue = hashValue ^ (*hashTailCursor << rotateShift | *hashTailCursor >> 0x20 - rotateShift);
            }
            nextEntryIndex = *(ushort *)(((unsigned char *)0x000015c8) + entryPtr);
            newBucketByteOffset = (hashValue - (hashValue / *(ushort *)(((unsigned char *)0x00001110) + glContext)) *
                             (uint)*(ushort *)(((unsigned char *)0x00001110) + glContext)) * 2;
            *(undefined2 *)(((unsigned char *)0x000015c8) + entryPtr) = *(undefined2 *)(newTable + newBucketByteOffset);
            *(short *)(newTable + newBucketByteOffset) = (short)entryIndex;
            entryIndex = (uint)nextEntryIndex;
          } while (nextEntryIndex != 0xffff);
          oldTable = *(int *)(((unsigned char *)0x00001114) + glContext);
        }
        loopIndex = loopIndex + 1;
      } while (loopIndex < oldBucketCount);
    }
    (**(code **)(glContext + 0x18))(oldTable);
    *(int *)(((unsigned char *)0x00001114) + glContext) = newTable;
  }
  return;
}

/* gldLookupProgramVariant @ 0x4bbf0 (1244 bytes) */
int gldLookupProgramVariant(glContext)
  int glContext;
{
  uint *keyPtrB;
  uint *hashTailCursor;
  uint *entryKeyPtrA;
  uint *entryKeyPtrB;
  uint *keyPairCursor;
  uint keyWordIndex;
  uint nextEntryIndex;
  uint entryIndex;
  int hashTableForSlot;
  int glContextWord1e60;
  ushort glContextWord1e6c;
  undefined4 allocation2;
  int allocation;
  int loopIndex;
  uint *entryKeyWordPtr;
  char useSimpleHash;
  uint rotateShift;
  int bucketByteOffset;
  uint hashValue;
  int hashTable;
  ushort hashBucketCount;
  uint *stateKey;
  undefined4 lookupResult;
  uint rotateAmount;
  uint *keyEnd;
  uint *hashBlockBase;
  uint *hashBlockCursor;
  uint *hashBlockLimit;
  int listByteOffset;
  undefined *entryKeyCursor;
  uint keyWordLimit;
  
  keyWordLimit = 0x11;
  stateKey = (uint *)(glContext + 0x18a4);
  if (*(byte *)(glContext + 0x2b) < 9) {
    keyWordLimit = (uint)*(byte *)(glContext + 0x2b) * 2 + 1;
  }
  useSimpleHash = ((unsigned char *)0x00001112)[glContext];
  if (useSimpleHash == '\0') {
    keyEnd = (uint *)(glContext + 0x18e8);
    hashBucketCount = *(ushort *)(((unsigned char *)0x00001110) + glContext);
    if (keyEnd < (uint *)(glContext + 0x18d0)) {
      hashValue = 0;
      hashBlockBase = stateKey;
    }
    else {
      hashValue = 0;
      hashBlockLimit = (uint *)(glContext + 0x18d0);
      hashBlockCursor = stateKey;
      do {
        hashBlockBase = hashBlockLimit;
        hashValue = hashValue ^ *hashBlockCursor ^ (hashBlockCursor[1] << 3 | hashBlockCursor[1] >> 0x1d) ^
                (hashBlockCursor[2] << 6 | hashBlockCursor[2] >> 0x1a) ^ (hashBlockCursor[3] << 9 | hashBlockCursor[3] >> 0x17) ^
                (hashBlockCursor[4] << 0xc | hashBlockCursor[4] >> 0x14) ^ (hashBlockCursor[5] << 0xf | hashBlockCursor[5] >> 0x11)
                ^ (hashBlockCursor[6] << 0x12 | hashBlockCursor[6] >> 0xe) ^
                (hashBlockCursor[7] << 0x15 | hashBlockCursor[7] >> 0xb) ^ (hashBlockCursor[8] << 0x18 | hashBlockCursor[8] >> 8) ^
                (hashBlockCursor[9] << 0x1b | hashBlockCursor[9] >> 5) ^ (hashBlockCursor[10] << 0x1e | hashBlockCursor[10] >> 2);
        hashBlockLimit = hashBlockBase + 0xb;
        hashBlockCursor = hashBlockBase;
      } while (hashBlockBase + 0xb <= keyEnd);
    }
    hashTailCursor = hashBlockBase + 5;
    if (keyEnd < hashTailCursor) {
      rotateAmount = 0;
      hashTailCursor = hashBlockBase;
    }
    else {
      rotateAmount = 0xf;
      hashValue = hashValue ^ *hashBlockBase ^ (hashBlockBase[1] << 3 | hashBlockBase[1] >> 0x1d) ^
              (hashBlockBase[2] << 6 | hashBlockBase[2] >> 0x1a) ^ (hashBlockBase[3] << 9 | hashBlockBase[3] >> 0x17) ^
              (hashBlockBase[4] << 0xc | hashBlockBase[4] >> 0x14);
    }
    for (; hashTailCursor < keyEnd; hashTailCursor = hashTailCursor + 1) {
      rotateShift = rotateAmount & 0x1f;
      rotateAmount = rotateAmount + 3;
      hashValue = hashValue ^ (*hashTailCursor << rotateShift | *hashTailCursor >> 0x20 - rotateShift);
    }
    hashValue = hashValue - (hashValue / hashBucketCount) * (uint)hashBucketCount;
  }
  else {
    hashBucketCount = *(ushort *)(((unsigned char *)0x00001110) + glContext);
    hashValue = *(int *)(glContext + 0x18a8) + *(int *)(glContext + 0x18b0) + *(int *)(glContext + 0x18b8) +
            *(int *)(glContext + 0x18c0);
    hashValue = hashValue - (hashValue / hashBucketCount) * (uint)hashBucketCount;
  }
  hashTable = *(int *)(((unsigned char *)0x00001114) + glContext);
  bucketByteOffset = (hashValue & 0xffff) * 2;
  *(undefined4 *)(glContext + 0x277c) = 0xffffffff;
  entryIndex = (uint)*(ushort *)(hashTable + bucketByteOffset);
  if (entryIndex == 0xffff) {
    loopIndex = 0;
  }
  else {
    loopIndex = 0;
    nextEntryIndex = entryIndex;
    do {
      entryIndex = nextEntryIndex;
      loopIndex = loopIndex + 1;
      glContextWord1e60 = *(int *)(glContext + 0x1e60) + entryIndex * 0x3754;
      entryKeyCursor = ((unsigned char *)0x00001544) + glContextWord1e60;
      if ((*stateKey == *(uint *)(((unsigned char *)0x00001544) + glContextWord1e60) &&
          *(int *)(glContext + 0x18a8) == *(int *)(((unsigned char *)0x00001548) + glContextWord1e60)) &&
          *(int *)(glContext + 0x18ac) == *(int *)(((unsigned char *)0x0000154c) + glContextWord1e60)) {
        if (keyWordLimit < 4) {
loopStoreGlContext:
          *(int *)(glContext + 0x1e5c) = glContextWord1e60;
          return 1;
        }
        if (*(int *)(((unsigned char *)0x00001550) + glContextWord1e60) == *(int *)(glContext + 0x18b0) &&
            *(int *)(((unsigned char *)0x00001554) + glContextWord1e60) == *(int *)(glContext + 0x18b4)) {
          keyWordIndex = 3;
          keyPairCursor = stateKey;
          do {
            keyWordIndex = keyWordIndex + 2;
            if (keyWordLimit <= keyWordIndex) goto loopStoreGlContext;
            entryKeyPtrB = (uint *)(entryKeyCursor + 0x18);
            keyPtrB = keyPairCursor + 6;
            entryKeyPtrA = (uint *)(entryKeyCursor + 0x14);
            entryKeyWordPtr = keyPairCursor + 5;
            entryKeyCursor = entryKeyCursor + 8;
            keyPairCursor = keyPairCursor + 2;
          } while (*entryKeyPtrA == *entryKeyWordPtr && *keyPtrB == *entryKeyPtrB);
        }
      }
      nextEntryIndex = (uint)*(ushort *)(((unsigned char *)0x000015c8) + glContextWord1e60);
    } while (*(ushort *)(((unsigned char *)0x000015c8) + glContextWord1e60) != 0xffff);
  }
  if ((useSimpleHash == '\0') || (loopIndex < 7)) {
    if ((loopIndex < 8) || (0x2810 < hashBucketCount)) {
      glContextWord1e6c = *(ushort *)(glContext + 0x1e6c);
      if (0x400 < glContextWord1e6c) {
        entryIndex = 0;
        ((int (*)())gldFlushProgramCache)(glContext);
        *(undefined2 *)(glContext + 0x1e6c) = 1;
        allocation2 = _malloc(((unsigned char *)0x00003754U));
        *(undefined4 *)(glContext + 0x1e60) = allocation2;
        _memset(allocation2,0,((unsigned char *)0x00003754U));
        ((int (*)())gldInitProgramCacheEntry)(glContext);
        *(undefined2 *)(((unsigned char *)0x000015c8) + *(int *)(glContext + 0x1e60)) = 0xffff;
        glContextWord1e6c = *(ushort *)(glContext + 0x1e6c);
      }
      *(ushort *)(glContext + 0x1e6c) = glContextWord1e6c + 1;
      if (*(int *)(glContext + 0x1e68) != 0) {
        ((unsigned char *)0x000010e9)[*(int *)(glContext + 0x1e68)] = 0;
        ((unsigned char *)0x000010ea)[*(int *)(glContext + 0x1e68)] = 0;
        ((unsigned char *)0x000010eb)[*(int *)(glContext + 0x1e68)] = 0;
        *(undefined4 *)(glContext + 0x1e68) = 0;
      }
      if (0 < *(int *)(glContext + 0x1e74)) {
        loopIndex = 0;
        do {
          listByteOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          ((unsigned char *)0x000010e9)[*(int *)(*(int *)(glContext + 0x1e7c) + listByteOffset)] = 0;
          ((unsigned char *)0x000010ea)[*(int *)(*(int *)(glContext + 0x1e7c) + listByteOffset)] = 0;
        } while (loopIndex < *(int *)(glContext + 0x1e74));
      }
      *(undefined4 *)(glContext + 0x1e74) = 0;
      allocation = _realloc(*(undefined4 *)(glContext + 0x1e60),
                       (uint)*(ushort *)(glContext + 0x1e6c) * 0x3754);
      *(int *)(glContext + 0x1e60) = allocation;
      if (allocation == 0) {
        return 0;
      }
      glContextWord1e6c = *(ushort *)(glContext + 0x1e6c);
      hashTableForSlot = *(int *)(((unsigned char *)0x00001114) + glContext);
      *(uint *)(glContext + 0x1e5c) = allocation + (uint)glContextWord1e6c * 0x3754 + -0x3754;
      if (*(short *)(bucketByteOffset + hashTableForSlot) == -1) {
        *(ushort *)(bucketByteOffset + hashTableForSlot) = glContextWord1e6c - 1;
      }
      else {
        *(ushort *)(((unsigned char *)0x000015c8) + entryIndex * 0x3754 + allocation) = glContextWord1e6c - 1;
      }
      _memset(*(undefined4 *)(glContext + 0x1e5c),0,((unsigned char *)0x00003754U));
      *(undefined2 *)(((unsigned char *)0x000015c8) + *(int *)(glContext + 0x1e5c)) = 0xffff;
      _memcpy(((unsigned char *)0x00001544) + *(int *)(glContext + 0x1e5c),glContext + 0x18a4,0x84);
      return 0;
    }
    if (useSimpleHash == '\0') {
      ((int (*)())gldGrowProgramHashTable)(glContext,0x313);
      goto setLookupResult;
    }
  }
  ((int (*)())gldGrowProgramHashTable)(glContext,0);
  ((unsigned char *)0x00001112)[glContext] = 0;
setLookupResult:
  lookupResult = ((int (*)())gldLookupProgramVariant)(glContext);
  return lookupResult;
}

/* gldCopyProgramStreamState @ 0x4c100 (336 bytes) */
int gldCopyProgramStreamState(dstState, glContext)
  int dstState;
  int glContext;
{
  undefined *stateBlockBase;
  int programEntry;
  undefined4 streamWord2;
  uint streamCount;
  undefined4 *streamState;
  
  programEntry = *(int *)(glContext + 0x1e64);
  if (programEntry != 0) {
    if (*(int *)(glContext + 0x23e0) == 0) {
      streamCount = *(uint *)(((unsigned char *)0x000036a8) + programEntry);
      streamState = (undefined4 *)(programEntry + 4);
      stateBlockBase = ((unsigned char *)0x000010ec);
    }
    else {
      streamCount = *(uint *)(((unsigned char *)0x000036b4) + programEntry);
      streamState = (undefined4 *)(programEntry + 0x20);
      stateBlockBase = ((unsigned char *)0x00001318);
    }
    *(undefined4 *)(dstState + 0x250) = *(undefined4 *)(stateBlockBase + programEntry + 0x44);
    *(undefined4 *)(dstState + 600) = *(undefined4 *)(stateBlockBase + programEntry + 0x48);
    streamWord2 = streamState[2];
    *(undefined4 *)(dstState + 0x218) = 0;
    *(undefined4 *)(dstState + 0x220) = streamWord2;
    *(undefined4 *)(dstState + 0x210) = streamState[3];
    *(undefined4 *)(dstState + 0x208) = *streamState;
    *(undefined4 *)(dstState + 0x200) = streamState[1];
    if (streamCount != 0) {
      *(undefined4 *)(dstState + 0x108) = *(undefined4 *)streamState[4];
      *(undefined4 *)(dstState + 0x110) = *(undefined4 *)(streamState[4] + 4);
      *(undefined4 *)(dstState + 0x118) = *(undefined4 *)(streamState[4] + 8);
      *(undefined4 *)(dstState + 0x120) = *(undefined4 *)(streamState[4] + 0xc);
      *(undefined4 *)(dstState + 0x128) = *(undefined4 *)(streamState[4] + 0x10);
      *(undefined4 *)(dstState + 0x130) = *(undefined4 *)(streamState[4] + 0x14);
      if (1 < streamCount) {
        *(undefined4 *)(dstState + 0x138) = *(undefined4 *)(streamState[4] + 0x18);
        *(undefined4 *)(dstState + 0x140) = *(undefined4 *)(streamState[4] + 0x1c);
        *(undefined4 *)(dstState + 0x148) = *(undefined4 *)(streamState[4] + 0x20);
        *(undefined4 *)(dstState + 0x150) = *(undefined4 *)(streamState[4] + 0x24);
        *(undefined4 *)(dstState + 0x158) = *(undefined4 *)(streamState[4] + 0x28);
        *(undefined4 *)(dstState + 0x160) = *(undefined4 *)(streamState[4] + 0x2c);
        return;
      }
      goto storeDstState;
    }
  }
  *(undefined4 *)(dstState + 0x1fc) = 0xc0001000;
  *(undefined4 *)(dstState + 0x104) = 0xc00a1000;
  *(undefined4 *)(dstState + 0x24c) = 0xc0001000;
  *(undefined4 *)(dstState + 0x254) = 0xc0001000;
  *(undefined4 *)(dstState + 0x21c) = 0xc0001000;
  *(undefined4 *)(dstState + 0x214) = 0xc0001000;
  *(undefined4 *)(dstState + 0x20c) = 0xc0001000;
  *(undefined4 *)(dstState + 0x204) = 0xc0001000;
storeDstState:
  *(undefined4 *)(dstState + 0x134) = 0xc00a1000;
  return;
}


/* issue: auto-generated aliases bridging data.s/code.s references (written
 * without a leading underscore, matching the raw stock-binary symbol name)
 * against the real compiled C symbols (gcc adds one underscore automatically).
 * Needed because ld64 (required for this PPC binary's size - stock ld breaks on
 * large PPC links) does not silently reconcile this the way stock ld did. */
asm(".globl fragmentTranslateSimpleOp");
asm(".set fragmentTranslateSimpleOp, _fragmentTranslateSimpleOp");
asm(".globl fragmentTranslateRep");
asm(".set fragmentTranslateRep, _fragmentTranslateRep");
asm(".globl fragmentTranslateDdy");
asm(".set fragmentTranslateDdy, _fragmentTranslateDdy");
asm(".globl fragmentTranslateScalarMath");
asm(".set fragmentTranslateScalarMath, _fragmentTranslateScalarMath");
asm(".globl fragmentTranslateTrig");
asm(".set fragmentTranslateTrig, _fragmentTranslateTrig");
asm(".globl fragmentTranslateAngleConvert");
asm(".set fragmentTranslateAngleConvert, _fragmentTranslateAngleConvert");
asm(".globl fragmentTranslateMod");
asm(".set fragmentTranslateMod, _fragmentTranslateMod");
asm(".globl fragmentTranslateAtn");
asm(".set fragmentTranslateAtn, _fragmentTranslateAtn");
asm(".globl fragmentTranslateRfr");
asm(".set fragmentTranslateRfr, _fragmentTranslateRfr");
asm(".globl fragmentTranslateFfw");
asm(".set fragmentTranslateFfw, _fragmentTranslateFfw");
asm(".globl fragmentTranslateDst");
asm(".set fragmentTranslateDst, _fragmentTranslateDst");
asm(".globl fragmentTranslateIf");
asm(".set fragmentTranslateIf, _fragmentTranslateIf");
asm(".globl fragmentTranslateRfl");
asm(".set fragmentTranslateRfl, _fragmentTranslateRfl");
asm(".globl fragmentTranslateWhile");
asm(".set fragmentTranslateWhile, _fragmentTranslateWhile");
