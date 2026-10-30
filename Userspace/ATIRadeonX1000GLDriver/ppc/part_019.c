#include "decls.h"

/* scDumpPixelProgramPsn @ 0xd4e08 (92 bytes) */
int scDumpPixelProgramPsn(sinkRecord, shaderState, optionsArg, argR6, argR7, argR8, unusedArg7, argR10)
  undefined4 *sinkRecord;
  int shaderState;
  undefined4 optionsArg;
  undefined4 argR6;
  undefined4 argR7;
  undefined4 argR8;
  undefined4 unusedArg7;
  undefined4 argR10;
{
  DAT_001fa61c = *sinkRecord;
  DAT_001fa618 = sinkRecord[1];
  FUN_000d183c(shaderState + 0x64c,"SC Generated Shader",0,argR6,argR7,argR8,DAT_001fa618,argR10)
  ;
  return 1;
}

/* scDumpPixelProgramToStringStub @ 0xd4e64 (40 bytes) */
int scDumpPixelProgramToStringStub()
{
  undefined1 auStack_28 [40];
  
  psnClearSinkRecord2(auStack_28);
  return 0;
}

/* scDumpPixelProgram @ 0xd4e8c (60 bytes) */
int scDumpPixelProgram(sinkContext, shaderState, optionsArg, sinkFn, argR7, argR8, param_7)
  undefined4 sinkContext;
  undefined4 shaderState;
  undefined4 optionsArg;
  undefined4 sinkFn;
  undefined4 argR7;
  undefined4 argR8;
  undefined4 param_7;
{
  undefined4 sinkFnCopy;
  undefined4 staleArgR10;
  undefined4 sinkFnField;
  undefined4 sinkContextField;
  
  sinkFnCopy = sinkFn;
  psnClearSinkRecord2(&sinkFnField);
  sinkFnField = sinkFn;
  sinkContextField = sinkContext;
  ((int (*)())scDumpPixelProgramPsn)(&sinkFnField,shaderState,optionsArg,sinkFnCopy,argR7,argR8,param_7,staleArgR10);
  return 0;
}

/* ffpsBuildRgbSourceOperand @ 0xd4ef0 (628 bytes) */
int ffpsBuildRgbSourceOperand(ctx, srcEnum, operandEnum, outSrcToken, outSwizzleWord, unit, baseFormat, isFirstUnit, previousUnit)
  int ctx;
  undefined *srcEnum;
  uint operandEnum;
  uint *outSrcToken;
  uint *outSwizzleWord;
  undefined *unit;
  undefined4 baseFormat;
  int isFirstUnit;
  undefined4 previousUnit;
{
  undefined *texUnitIndex;
  
  texUnitIndex = srcEnum + -0x84c0;
  if ((undefined *)0xf < texUnitIndex) {
    if (srcEnum < (undefined *)0x2) {
      if (srcEnum == (undefined *)0x0) {
        *outSrcToken = *outSrcToken & 0xffc0ffff | 0x120000;
        *(undefined2 *)((int)outSrcToken + 2) = 0;
        *outSrcToken = *outSrcToken | 0x400000;
        if (operandEnum != 0x301) {
          if (operandEnum < 0x302) {
            if (operandEnum != 0x300) {
              return;
            }
          }
          else if (operandEnum != 0x302) {
            if (operandEnum != 0x303) {
              return;
            }
            goto LAB_000d5160;
          }
LAB_000d517c:
          *outSwizzleWord = *outSwizzleWord & 0xfffff888 | 0x444;
          return;
        }
      }
      else {
        if (srcEnum != (undefined *)0x1) {
          return;
        }
        *outSrcToken = *outSrcToken & 0xffc0ffff | 0x120000;
        *(undefined2 *)((int)outSrcToken + 2) = 0;
        *outSrcToken = *outSrcToken | 0x400000;
        if (operandEnum == 0x301) goto LAB_000d517c;
        if (operandEnum < 0x302) {
          if (operandEnum != 0x300) {
            return;
          }
        }
        else if (operandEnum != 0x302) {
          if (operandEnum != 0x303) {
            return;
          }
          goto LAB_000d517c;
        }
      }
LAB_000d5160:
      *outSwizzleWord = *outSwizzleWord & 0xfffff888 | 0x555;
      return;
    }
    if (srcEnum == (undefined *)0x8576) {
      *outSrcToken = *outSrcToken & 0xffc0ffff | 0x10000;
      *(short *)((int)outSrcToken + 2) = (short)unit;
      goto LAB_000d4fe0;
    }
    if ((undefined *)0x8576 < srcEnum) {
      if (srcEnum != (undefined *)0x8577) {
        if (srcEnum != (undefined *)0x8578) goto LAB_000d4fe0;
        if (isFirstUnit == 0) {
          *outSrcToken = *outSrcToken & 0xffc0ffff | 0x40000;
          *(ushort *)((int)outSrcToken + 2) = (*(unsigned short *)((unsigned char *)&(previousUnit) + 2)) + (ushort)(byte)((unsigned char *)0x000013b2)[ctx];
          goto LAB_000d4fe0;
        }
      }
      *outSrcToken = *outSrcToken & 0xffc0ffff | 0x120000;
      goto LAB_000d4fe0;
    }
    texUnitIndex = unit;
    if (srcEnum != ((unsigned char *)0x00001702)) goto LAB_000d4fe0;
  }
  *outSrcToken = *outSrcToken & 0xffc0ffff | 0x40000;
  *(short *)((int)outSrcToken + 2) = (short)texUnitIndex;
LAB_000d4fe0:
  if (operandEnum == 0x302) {
    *outSrcToken = *outSrcToken | 0x400000;
    *outSwizzleWord = *outSwizzleWord & 0xfffff888 | 0x333;
    return;
  }
  if (operandEnum == 0x303) {
    *outSrcToken = *outSrcToken | 0x400000;
    *outSwizzleWord = *outSwizzleWord & 0xfffff888 | 0x10333;
    return;
  }
  if (operandEnum == 0x301) {
    *outSrcToken = *outSrcToken | 0x400000;
    *outSwizzleWord = *outSwizzleWord & 0xfffff888 | 0x10210;
    return;
  }
  return;
}

/* ffpsBuildAlphaSourceOperand @ 0xd51a0 (460 bytes) */
int ffpsBuildAlphaSourceOperand(ctx, srcEnum, operandEnum, outSrcToken, outSwizzleWord, unit, baseFormat, isFirstUnit, previousUnit)
  int ctx;
  undefined *srcEnum;
  int operandEnum;
  uint *outSrcToken;
  uint *outSwizzleWord;
  undefined *unit;
  undefined4 baseFormat;
  int isFirstUnit;
  undefined4 previousUnit;
{
  undefined *texUnitIndex;
  
  texUnitIndex = srcEnum + -0x84c0;
  if ((undefined *)0xf < texUnitIndex) {
    if (srcEnum < (undefined *)0x2) {
      if (srcEnum == (undefined *)0x0) {
        *outSrcToken = *outSrcToken & 0xffc0ffff | 0x120000;
        *(undefined2 *)((int)outSrcToken + 2) = 0;
        *outSrcToken = *outSrcToken | 0x400000;
        if (operandEnum != 0x302) {
          if (operandEnum != 0x303) {
            return;
          }
          goto LAB_000d535c;
        }
      }
      else {
        if (srcEnum != (undefined *)0x1) {
          return;
        }
        *outSrcToken = *outSrcToken & 0xffc0ffff | 0x120000;
        *(undefined2 *)((int)outSrcToken + 2) = 0;
        *outSrcToken = *outSrcToken | 0x400000;
        if (operandEnum == 0x302) {
LAB_000d535c:
          *outSwizzleWord = *outSwizzleWord & 0xffff8fff | 0x5000;
          return;
        }
        if (operandEnum != 0x303) {
          return;
        }
      }
      *outSwizzleWord = *outSwizzleWord & 0xffff8fff | 0x4000;
      return;
    }
    if (srcEnum == (undefined *)0x8576) {
      *outSrcToken = *outSrcToken & 0xffc0ffff | 0x10000;
      *(short *)((int)outSrcToken + 2) = (short)unit;
      goto LAB_000d52a0;
    }
    if ((undefined *)0x8576 < srcEnum) {
      if (srcEnum != (undefined *)0x8577) {
        if (srcEnum != (undefined *)0x8578) goto LAB_000d52a0;
        if (isFirstUnit == 0) {
          *outSrcToken = *outSrcToken & 0xffc0ffff | 0x40000;
          *(ushort *)((int)outSrcToken + 2) = (*(unsigned short *)((unsigned char *)&(previousUnit) + 2)) + (ushort)(byte)((unsigned char *)0x000013b2)[ctx];
          goto LAB_000d52a0;
        }
      }
      *outSrcToken = *outSrcToken & 0xffc0ffff | 0x120000;
      *(undefined2 *)((int)outSrcToken + 2) = 0;
      goto LAB_000d52a0;
    }
    texUnitIndex = unit;
    if (srcEnum != ((unsigned char *)0x00001702)) goto LAB_000d52a0;
  }
  *outSrcToken = *outSrcToken & 0xffc0ffff | 0x40000;
  *(short *)((int)outSrcToken + 2) = (short)texUnitIndex;
LAB_000d52a0:
  if (operandEnum == 0x303) {
    *outSrcToken = *outSrcToken | 0x400000;
    *outSwizzleWord = *outSwizzleWord & 0xffff8fff | 0x13000;
    return;
  }
  return;
}

/* ffpsEmitColorOutputMovs @ 0xd5390 (548 bytes) */
int ffpsEmitColorOutputMovs(ctx, ilBuilder, isFirstUnit, previousUnit, componentMask)
  int ctx;
  uint *ilBuilder;
  int isFirstUnit;
  int previousUnit;
  uint componentMask;
{
  uint newTokenBuffer;
  bool notLastComponent;
  uint tokenIndex;
  uint componentToken;
  uint sourceToken;
  uint loopCounter;
  
  componentToken = 0x170000;
  if (isFirstUnit == 0) {
    sourceToken = previousUnit + (uint)(byte)((unsigned char *)0x000013b2)[ctx] & 0xffff | 0x40000;
  }
  else {
    sourceToken = 0x120000;
  }
  loopCounter = 0;
  do {
    if ((1 << (loopCounter & 0x3f) & componentMask) != 0) {
      tokenIndex = *ilBuilder;
      componentToken = loopCounter & 0xffff | componentToken & 0xffff0000;
      if (ilBuilder[1] <= tokenIndex) {
        newTokenBuffer = (**(code **)(ctx + 0xc))(ilBuilder[1] * 4 + 0x200);
        if (ilBuilder[2] != 0) {
          _memcpy(newTokenBuffer,ilBuilder[2],*ilBuilder << 2);
          (**(code **)(ctx + 0x18))(ilBuilder[2]);
        }
        ilBuilder[2] = newTokenBuffer;
        tokenIndex = *ilBuilder;
        ilBuilder[1] = ilBuilder[1] + 0x80;
      }
      *(undefined4 *)(tokenIndex * 4 + ilBuilder[2]) = 0xe;
      tokenIndex = *ilBuilder + 1;
      *ilBuilder = tokenIndex;
      if (ilBuilder[1] <= tokenIndex) {
        newTokenBuffer = (**(code **)(ctx + 0xc))(ilBuilder[1] * 4 + 0x200);
        if (ilBuilder[2] != 0) {
          _memcpy(newTokenBuffer,ilBuilder[2],*ilBuilder << 2);
          (**(code **)(ctx + 0x18))(ilBuilder[2]);
        }
        ilBuilder[2] = newTokenBuffer;
        tokenIndex = *ilBuilder;
        ilBuilder[1] = ilBuilder[1] + 0x80;
      }
      *(uint *)(tokenIndex * 4 + ilBuilder[2]) = componentToken;
      tokenIndex = *ilBuilder + 1;
      *ilBuilder = tokenIndex;
      if (ilBuilder[1] <= tokenIndex) {
        newTokenBuffer = (**(code **)(ctx + 0xc))(ilBuilder[1] * 4 + 0x200);
        if (ilBuilder[2] != 0) {
          _memcpy(newTokenBuffer,ilBuilder[2],*ilBuilder << 2);
          (**(code **)(ctx + 0x18))(ilBuilder[2]);
        }
        ilBuilder[2] = newTokenBuffer;
        tokenIndex = *ilBuilder;
        ilBuilder[1] = ilBuilder[1] + 0x80;
      }
      *(uint *)(tokenIndex * 4 + ilBuilder[2]) = sourceToken;
      *ilBuilder = *ilBuilder + 1;
    }
    notLastComponent = loopCounter != 3;
    loopCounter = loopCounter + 1;
  } while (notLastComponent);
  return;
}

/* FUN_000d55c0 @ 0xd55c0 (832 bytes) */
int FUN_000d55c0(ctx, ilBuilder, isFirstUnit, previousUnit)
  int ctx;
  uint *ilBuilder;
  int isFirstUnit;
  undefined4 previousUnit;
{
  uint newTokenBuffer;
  byte textureUnitCount;
  uint tokenIndex;
  uint sourceToken;
  
  tokenIndex = *ilBuilder;
  if (ilBuilder[1] <= tokenIndex) {
    newTokenBuffer = (**(code **)(ctx + 0xc))(ilBuilder[1] * 4 + 0x200);
    if (ilBuilder[2] != 0) {
      _memcpy(newTokenBuffer,ilBuilder[2],*ilBuilder << 2);
      (**(code **)(ctx + 0x18))(ilBuilder[2]);
    }
    ilBuilder[2] = newTokenBuffer;
    tokenIndex = *ilBuilder;
    ilBuilder[1] = ilBuilder[1] + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + ilBuilder[2]) = 3;
  tokenIndex = *ilBuilder + 1;
  *ilBuilder = tokenIndex;
  textureUnitCount = ((unsigned char *)0x000013b2)[ctx];
  if (ilBuilder[1] <= tokenIndex) {
    newTokenBuffer = (**(code **)(ctx + 0xc))(ilBuilder[1] * 4 + 0x200);
    if (ilBuilder[2] != 0) {
      _memcpy(newTokenBuffer,ilBuilder[2],*ilBuilder << 2);
      (**(code **)(ctx + 0x18))(ilBuilder[2]);
    }
    ilBuilder[2] = newTokenBuffer;
    tokenIndex = *ilBuilder;
    ilBuilder[1] = ilBuilder[1] + 0x80;
  }
  *(uint *)(tokenIndex * 4 + ilBuilder[2]) = (int)(*(unsigned short *)((unsigned char *)&(previousUnit) + 2)) + (uint)textureUnitCount & 0xffff | 0x40000;
  tokenIndex = *ilBuilder + 1;
  *ilBuilder = tokenIndex;
  if (isFirstUnit == 0) {
    sourceToken = (int)(*(unsigned short *)((unsigned char *)&(previousUnit) + 2)) + (uint)(byte)((unsigned char *)0x000013b2)[ctx] & 0xffff | 0x40000;
  }
  else {
    sourceToken = 0x120000;
  }
  if (ilBuilder[1] <= tokenIndex) {
    newTokenBuffer = (**(code **)(ctx + 0xc))(ilBuilder[1] * 4 + 0x200);
    if (ilBuilder[2] != 0) {
      _memcpy(newTokenBuffer,ilBuilder[2],*ilBuilder << 2);
      (**(code **)(ctx + 0x18))(ilBuilder[2]);
    }
    ilBuilder[2] = newTokenBuffer;
    tokenIndex = *ilBuilder;
    ilBuilder[1] = ilBuilder[1] + 0x80;
  }
  *(uint *)(tokenIndex * 4 + ilBuilder[2]) = sourceToken;
  tokenIndex = *ilBuilder + 1;
  *ilBuilder = tokenIndex;
  if (ilBuilder[1] <= tokenIndex) {
    newTokenBuffer = (**(code **)(ctx + 0xc))(ilBuilder[1] * 4 + 0x200);
    if (ilBuilder[2] != 0) {
      _memcpy(newTokenBuffer,ilBuilder[2],*ilBuilder << 2);
      (**(code **)(ctx + 0x18))(ilBuilder[2]);
    }
    ilBuilder[2] = newTokenBuffer;
    tokenIndex = *ilBuilder;
    ilBuilder[1] = ilBuilder[1] + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + ilBuilder[2]) = 0x530000;
  tokenIndex = *ilBuilder + 1;
  *ilBuilder = tokenIndex;
  if (ilBuilder[1] <= tokenIndex) {
    newTokenBuffer = (**(code **)(ctx + 0xc))(ilBuilder[1] * 4 + 0x200);
    if (ilBuilder[2] != 0) {
      _memcpy(newTokenBuffer,ilBuilder[2],*ilBuilder << 2);
      (**(code **)(ctx + 0x18))(ilBuilder[2]);
    }
    ilBuilder[2] = newTokenBuffer;
    tokenIndex = *ilBuilder;
    ilBuilder[1] = ilBuilder[1] + 0x80;
  }
  *(undefined **)(tokenIndex * 4 + ilBuilder[2]) = ((unsigned char *)0x00004210);
  *ilBuilder = *ilBuilder + 1;
  return;
}

/* ffpsEmitDeclarations @ 0xd5900 (2612 bytes) */
int ffpsEmitDeclarations(ctx, ilBuilder)
  int ctx;
  int ilBuilder;
{
  bool hasUnitWithoutCompare;
  undefined4 newTokenBuffer;
  uint tokenIndex;
  uint textureUnitCount;
  uint loopCounter;
  int iVar6;
  uint loopIndex;
  uint *countPtr;
  
  countPtr = (uint *)(ilBuilder + 4);
  iVar6 = *(int *)(*(int *)(ctx + 4) + 0x10);
  if (*(uint *)(ilBuilder + 8) <= *(uint *)(ilBuilder + 4)) {
    newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
    if (*(int *)(ilBuilder + 0xc) != 0) {
      _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*(int *)(ilBuilder + 4) << 2);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
    }
    *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
    *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
  }
  *(undefined4 *)(*countPtr * 4 + *(int *)(ilBuilder + 0xc)) = 0x1ff0016;
  tokenIndex = *countPtr + 1;
  *countPtr = tokenIndex;
  if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
    newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
    if (*(int *)(ilBuilder + 0xc) != 0) {
      _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
    }
    *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
    tokenIndex = *countPtr;
    *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x120000;
  tokenIndex = *countPtr + 1;
  *countPtr = tokenIndex;
  if (((*(uint *)(ctx + 0x44) & 0xa00000) != 0) ||
     (((int)*(uint *)(ctx + 0x44) < 0 && (*(short *)(((unsigned char *)0x00002d48) + iVar6) == -0x7e06)))) {
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x1ff0016;
    tokenIndex = *countPtr + 1;
    *countPtr = tokenIndex;
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x130000;
    tokenIndex = *countPtr + 1;
    *countPtr = tokenIndex;
  }
  textureUnitCount = (uint)(byte)((unsigned char *)0x000013b2)[ctx];
  hasUnitWithoutCompare = false;
  if (textureUnitCount != 0) {
    loopIndex = 0;
    loopCounter = 0x80000;
    iVar6 = ctx;
    do {
      if (((*(uint *)(ctx + 0x44) & 0x100000) != 0) &&
         (*(char *)(loopIndex + *(int *)(((unsigned char *)0x00001168) + ctx) + 0x71) == '\0')) {
        hasUnitWithoutCompare = true;
      }
      if (*(int *)(((unsigned char *)0x000013f8) + iVar6) != 0) {
        if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
          newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
          if (*(int *)(ilBuilder + 0xc) != 0) {
            _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
          }
          *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
          tokenIndex = *countPtr;
          *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
        }
        *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x1ff0016;
        tokenIndex = *countPtr + 1;
        *countPtr = tokenIndex;
        if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
          newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
          if (*(int *)(ilBuilder + 0xc) != 0) {
            _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
          }
          *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
          tokenIndex = *countPtr;
          *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
        }
        *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = loopIndex & 0xffff | 0x110000;
        tokenIndex = *countPtr + 1;
        *countPtr = tokenIndex;
        if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
          newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
          if (*(int *)(ilBuilder + 0xc) != 0) {
            _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
          }
          *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
          tokenIndex = *countPtr;
          *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
        }
        *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = loopIndex << 0x10 | 0x19;
        tokenIndex = *countPtr + 1;
        *countPtr = tokenIndex;
        if (((int)(uint)*(byte *)(ctx + 0x20) >> (loopIndex & 0x3f) & 1U) == 0) {
          textureUnitCount = (uint)(byte)((unsigned char *)0x000013b2)[ctx];
        }
        else {
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = loopCounter | 0x19;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          textureUnitCount = (uint)(byte)((unsigned char *)0x000013b2)[ctx];
        }
      }
      loopIndex = loopIndex + 1;
      loopCounter = loopCounter + 0x10000;
      iVar6 = iVar6 + 4;
    } while ((int)loopIndex < (int)textureUnitCount);
  }
  if (*(char *)(ctx + 0x121) != '\0') {
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x1ff0016;
    tokenIndex = *countPtr + 1;
    *countPtr = tokenIndex;
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x100000;
    tokenIndex = *countPtr + 1;
    *countPtr = tokenIndex;
  }
  if (hasUnitWithoutCompare) {
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x1c;
    tokenIndex = *countPtr + 1;
    *countPtr = tokenIndex;
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x10011;
    tokenIndex = *countPtr + 1;
    *countPtr = tokenIndex;
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0;
    tokenIndex = *countPtr + 1;
    *countPtr = tokenIndex;
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0;
    tokenIndex = *countPtr + 1;
    *countPtr = tokenIndex;
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0;
    tokenIndex = *countPtr + 1;
    *countPtr = tokenIndex;
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x3f800000;
    *countPtr = *countPtr + 1;
  }
  return;
}

/* ffpsEmitTexEnvCombine @ 0xd6340 (4540 bytes) */
int ffpsEmitTexEnvCombine(ctx, ilBuilder, baseFormat, unit, textureObject, isFirstUnit, previousUnit)
  int ctx;
  int ilBuilder;
  undefined4 baseFormat;
  uint unit;
  undefined4 textureObject;
  undefined4 isFirstUnit;
  undefined4 previousUnit;
{
  uint alphaSourceSwizzle;
  uint alphaSourceToken;
  uint rgbSourceSwizzle;
  int loopCounter;
  uint tokenIndex;
  bool notLastWord;
  byte textureUnitCount;
  float rgbScale;
  ushort combineAlphaMode;
  int argSlot;
  int unitState;
  undefined4 newTokenBuffer;
  uint combineRgbMode;
  int iVar9;
  int argCount;
  undefined4 ilOpcode;
  int *argOrderCursor;
  undefined4 dstWriteWord;
  uint rgbSourceToken;
  uint *countPtr;
  uint srcTokens [2];
  undefined1 srcToken2 [4];
  uint srcSwizzles [2];
  undefined1 srcSwizzle2 [4];
  uint alphaSrcTokens [2];
  undefined1 alphaSrcToken2 [4];
  uint alphaSwizzle0;
  uint alphaSwizzle1;
  undefined1 alphaSwizzle2 [4];
  int argOrder [4];
  uint *alphaSwizzlesPtr;
  
  unitState = 0;
  alphaSwizzlesPtr = &alphaSwizzle0;
  do {
    *(undefined4 *)(unitState + (int)srcTokens) = 0;
    *(undefined4 *)(unitState + (int)srcSwizzles) = 0;
    notLastWord = unitState != 8;
    *(undefined4 *)(unitState + (int)alphaSrcTokens) = 0;
    *(undefined4 *)(unitState + (int)alphaSwizzlesPtr) = 0;
    unitState = unitState + 4;
  } while (notLastWord);
  unitState = unit * 0xcc + ctx;
  countPtr = (uint *)(ilBuilder + 4);
  ilOpcode = 0;
  ((int (*)())ffpsBuildRgbSourceOperand)(ctx,(uint)*(ushort *)(unitState + 0x456),(uint)*(ushort *)(unitState + 0x462),srcTokens,
               srcSwizzles,unit,baseFormat,isFirstUnit,previousUnit);
  ((int (*)())ffpsBuildRgbSourceOperand)(ctx,(uint)*(ushort *)(unitState + 0x458),(uint)*(ushort *)(unitState + 0x464),
               srcTokens + 1,srcSwizzles + 1,unit,baseFormat,isFirstUnit,previousUnit);
  ((int (*)())ffpsBuildRgbSourceOperand)(ctx,(uint)*(ushort *)(unitState + 0x45a),(uint)*(ushort *)(unitState + 0x466),srcToken2,
               srcSwizzle2,unit,baseFormat,isFirstUnit,previousUnit);
  combineRgbMode = (uint)*(ushort *)(unitState + 0x454);
  rgbScale = *(float *)(unitState + 0x474);
  if (combineRgbMode < 0x86b0) {
    if (combineRgbMode < 0x86ae) {
      if (combineRgbMode == 0x2100) {
        ilOpcode = 0x49;
LAB_000d6560:
        argCount = 2;
        argOrder[0] = 0;
        iVar9 = combineRgbMode - 0x10000;
        argOrder[1] = 1;
      }
      else if (combineRgbMode < 0x2101) {
        if (combineRgbMode == 0x104) {
          ilOpcode = 3;
          goto LAB_000d6560;
        }
        if (combineRgbMode != 0x1e01) goto LAB_000d6534;
        argCount = 1;
        argOrder[0] = 0;
        iVar9 = -0xe1ff;
        ilOpcode = 0x47;
      }
      else if (combineRgbMode == 0x8574) {
        argOrder[0] = 0;
        ilOpcode = 3;
        argOrder[1] = 1;
        if ((srcTokens[1] & 0x400000) == 0) {
          srcTokens[1] = srcTokens[1] | 0x400000;
          srcSwizzles[1] = srcSwizzles[1] & 0xfffff888 | 0x210;
        }
        argCount = 2;
        iVar9 = -0x7a8c;
        srcSwizzles[1] = srcSwizzles[1] | 0x20000;
      }
      else if (combineRgbMode == 0x8575) {
        argOrder[1] = 0;
        argCount = 3;
        ilOpcode = 0x3f;
        iVar9 = -0x7a8b;
        argOrder[2] = 1;
        argOrder[0] = 2;
      }
      else {
        if (combineRgbMode != 0x84e7) goto LAB_000d6534;
        argCount = 2;
        argOrder[0] = 0;
        iVar9 = -0x7b19;
        ilOpcode = 0x5b;
        argOrder[1] = 1;
      }
    }
    else {
LAB_000d64e8:
      iVar9 = combineRgbMode - 0x10000;
      argOrder[0] = 0;
      ilOpcode = 0x22;
      argOrder[1] = 1;
      if ((srcTokens[0] & 0x400000) == 0) {
        srcTokens[0] = srcTokens[0] | 0x400000;
        srcSwizzles[0] = srcSwizzles[0] & 0xfffff888 | 0x210;
      }
      if ((srcTokens[1] & 0x400000) == 0) {
        srcTokens[1] = srcTokens[1] | 0x400000;
        srcSwizzles[1] = srcSwizzles[1] & 0xfffff888 | 0x210;
      }
      argCount = 2;
      srcSwizzles[0] = srcSwizzles[0] | 0x20000;
      srcSwizzles[1] = srcSwizzles[1] | 0x20000;
    }
  }
  else if (combineRgbMode == 0x8744) {
    argOrder[0] = 0;
    argCount = 3;
    ilOpcode = 0x40;
    iVar9 = -0x78bc;
    argOrder[2] = 1;
    argOrder[1] = 2;
  }
  else if (combineRgbMode < 0x8745) {
    if (combineRgbMode - 0x8740 < 2) goto LAB_000d64e8;
LAB_000d6534:
    iVar9 = combineRgbMode - 0x10000;
    argCount = 0;
  }
  else if (combineRgbMode == 0x8745) {
    argOrder[0] = 0;
    argOrder[1] = 2;
    argOrder[2] = 1;
    ilOpcode = 0x40;
    if ((srcTokens[1] & 0x400000) == 0) {
      srcTokens[1] = srcTokens[1] | 0x400000;
      srcSwizzles[1] = srcSwizzles[1] & 0xfffff888 | 0x210;
    }
    argCount = 3;
    iVar9 = -0x78bb;
    srcSwizzles[1] = srcSwizzles[1] | 0x20000;
  }
  else {
    if (combineRgbMode != 0x8746) goto LAB_000d6534;
    argOrder[0] = 0;
    argOrder[1] = 2;
    argOrder[2] = 1;
    ilOpcode = 0x40;
    if ((srcTokens[1] & 0x400000) == 0) {
      srcTokens[1] = srcTokens[1] | 0x400000;
      srcSwizzles[1] = srcSwizzles[1] & 0xfffff888 | 0x210;
    }
    argCount = 3;
    iVar9 = -0x78ba;
    srcSwizzles[1] = srcSwizzles[1] | 0x888;
  }
  textureUnitCount = ((unsigned char *)0x000013b2)[ctx];
  dstWriteWord = 0x115;
  if (iVar9 + 0x7952U < 2) {
    if (rgbScale == FLOAT_001aa0e8) {
LAB_000d6840:
      dstWriteWord = 0x515;
    }
    else if (rgbScale == FLOAT_001aa108) {
      dstWriteWord = 0x715;
    }
    else {
      dstWriteWord = 0x715;
      srcSwizzles[0] = srcSwizzles[0] | 0x40000;
    }
  }
  else {
    if (((rgbScale == FLOAT_001aa104) || (combineRgbMode == 0x8740)) || (combineRgbMode == 0x8741)) goto LAB_000d6840;
    if (rgbScale == FLOAT_001aa108) {
      dstWriteWord = 0x315;
    }
  }
  tokenIndex = *countPtr;
  if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
    newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
    if (*(int *)(ilBuilder + 0xc) != 0) {
      _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
    }
    *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
    tokenIndex = *countPtr;
    *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = ilOpcode;
  tokenIndex = *countPtr + 1;
  *countPtr = tokenIndex;
  if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
    ilOpcode = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
    if (*(int *)(ilBuilder + 0xc) != 0) {
      _memcpy(ilOpcode,*(int *)(ilBuilder + 0xc),*countPtr << 2);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
    }
    *(undefined4 *)(ilBuilder + 0xc) = ilOpcode;
    tokenIndex = *countPtr;
    *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) =
       (int)(short)unit + (uint)textureUnitCount & 0xffff | 0x440000;
  tokenIndex = *countPtr + 1;
  *countPtr = tokenIndex;
  if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
    ilOpcode = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
    if (*(int *)(ilBuilder + 0xc) != 0) {
      _memcpy(ilOpcode,*(int *)(ilBuilder + 0xc),*countPtr << 2);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
    }
    *(undefined4 *)(ilBuilder + 0xc) = ilOpcode;
    tokenIndex = *countPtr;
    *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = dstWriteWord;
  tokenIndex = *countPtr + 1;
  *countPtr = tokenIndex;
  if (argCount != 0) {
    loopCounter = 0;
    argOrderCursor = argOrder;
    do {
      argSlot = *argOrderCursor;
      argOrderCursor = argOrderCursor + 1;
      rgbSourceToken = srcTokens[argSlot];
      if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
        ilOpcode = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
        if (*(int *)(ilBuilder + 0xc) != 0) {
          _memcpy(ilOpcode,*(int *)(ilBuilder + 0xc),*countPtr << 2);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
        }
        *(undefined4 *)(ilBuilder + 0xc) = ilOpcode;
        tokenIndex = *countPtr;
        *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
      }
      *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = rgbSourceToken;
      tokenIndex = *countPtr + 1;
      *countPtr = tokenIndex;
      if ((srcTokens[argSlot] & 0x400000) != 0) {
        rgbSourceSwizzle = srcSwizzles[argSlot];
        if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
          ilOpcode = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
          if (*(int *)(ilBuilder + 0xc) != 0) {
            _memcpy(ilOpcode,*(int *)(ilBuilder + 0xc),*countPtr << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
          }
          *(undefined4 *)(ilBuilder + 0xc) = ilOpcode;
          tokenIndex = *countPtr;
          *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
        }
        *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = rgbSourceSwizzle;
        tokenIndex = *countPtr + 1;
        *countPtr = tokenIndex;
      }
      loopCounter = loopCounter + 1;
    } while (argCount != loopCounter);
  }
  if ((*(short *)(unitState + 0x454) == -0x78bf) || (*(short *)(unitState + 0x454) == -0x7951)) {
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      ilOpcode = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(ilOpcode,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = ilOpcode;
      tokenIndex = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x47;
    tokenIndex = *countPtr + 1;
    *countPtr = tokenIndex;
    textureUnitCount = ((unsigned char *)0x000013b2)[ctx];
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      ilOpcode = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(ilOpcode,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = ilOpcode;
      tokenIndex = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) =
         (unit & 0xffff) + (uint)textureUnitCount & 0xffff | 0x440000;
    tokenIndex = *countPtr + 1;
    *countPtr = tokenIndex;
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      ilOpcode = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(ilOpcode,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = ilOpcode;
      tokenIndex = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x40;
    tokenIndex = *countPtr + 1;
    *countPtr = tokenIndex;
    textureUnitCount = ((unsigned char *)0x000013b2)[ctx];
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      ilOpcode = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(ilOpcode,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = ilOpcode;
      tokenIndex = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) =
         (unit & 0xffff) + (uint)textureUnitCount & 0xffff | 0x440000;
    tokenIndex = *countPtr + 1;
    *countPtr = tokenIndex;
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      ilOpcode = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(ilOpcode,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = ilOpcode;
      tokenIndex = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0;
    *countPtr = *countPtr + 1;
    return;
  }
  ilOpcode = 0;
  ((int (*)())ffpsBuildAlphaSourceOperand)(ctx,(uint)*(ushort *)(unitState + 0x45c),(uint)*(ushort *)(unitState + 0x468),alphaSrcTokens,
               alphaSwizzlesPtr,unit,baseFormat,isFirstUnit,previousUnit);
  ((int (*)())ffpsBuildAlphaSourceOperand)(ctx,(uint)*(ushort *)(unitState + 0x45e),(uint)*(ushort *)(unitState + 0x46a),
               alphaSrcTokens + 1,&alphaSwizzle1,unit,baseFormat,isFirstUnit,previousUnit);
  ((int (*)())ffpsBuildAlphaSourceOperand)(ctx,(uint)*(ushort *)(unitState + 0x460),(uint)*(ushort *)(unitState + 0x46c),alphaSrcToken2,
               alphaSwizzle2,unit,baseFormat,isFirstUnit,previousUnit);
  combineAlphaMode = *(ushort *)(unitState + 0x452);
  rgbScale = *(float *)(unitState + 0x478);
  if (combineAlphaMode == 0x8574) {
    argOrder[0] = 0;
    ilOpcode = 3;
    argOrder[1] = 1;
    if ((alphaSrcTokens[1] & 0x400000) == 0) {
      alphaSrcTokens[1] = alphaSrcTokens[1] | 0x400000;
      alphaSwizzle1 = alphaSwizzle1 & 0xffff8fff | 0x3000;
    }
    unitState = 2;
    alphaSwizzle1 = alphaSwizzle1 | 0x20000;
  }
  else if (combineAlphaMode < 0x8575) {
    if (combineAlphaMode == 0x1e01) {
      unitState = 1;
      argOrder[0] = 0;
      ilOpcode = 0x47;
    }
    else {
      if (combineAlphaMode < 0x1e02) {
        if (combineAlphaMode != 0x104) {
LAB_000d6fbc:
          unitState = 0;
          goto LAB_000d7144;
        }
        ilOpcode = 3;
      }
      else if (combineAlphaMode == 0x2100) {
        ilOpcode = 0x49;
      }
      else {
        if (combineAlphaMode != 0x84e7) goto LAB_000d6fbc;
        ilOpcode = 0x5b;
      }
      unitState = 2;
      argOrder[0] = 0;
      argOrder[1] = 1;
    }
  }
  else if (combineAlphaMode == 0x8744) {
    argOrder[0] = 0;
    unitState = 3;
    ilOpcode = 0x40;
    argOrder[2] = 1;
    argOrder[1] = 2;
  }
  else if (combineAlphaMode < 0x8745) {
    if (combineAlphaMode != 0x8575) goto LAB_000d6fbc;
    argOrder[1] = 0;
    unitState = 3;
    ilOpcode = 0x3f;
    argOrder[2] = 1;
    argOrder[0] = 2;
  }
  else if (combineAlphaMode == 0x8745) {
    argOrder[0] = 0;
    ilOpcode = 0x40;
    argOrder[2] = 1;
    argOrder[1] = 2;
    if ((alphaSrcTokens[1] & 0x400000) == 0) {
      alphaSrcTokens[1] = alphaSrcTokens[1] | 0x400000;
      alphaSwizzle1 = alphaSwizzle1 & 0xffff8fff | 0x3000;
    }
    unitState = 3;
    alphaSwizzle1 = alphaSwizzle1 | 0x20000;
  }
  else {
    if (combineAlphaMode != 0x8746) goto LAB_000d6fbc;
    argOrder[0] = 0;
    argOrder[1] = 2;
    ilOpcode = 0x40;
    argOrder[2] = 1;
    if ((alphaSrcTokens[1] & 0x400000) == 0) {
      alphaSrcTokens[1] = alphaSrcTokens[1] | 0x400000;
      alphaSwizzle1 = alphaSwizzle1 & 0xffff8fff | 0x3000;
    }
    unitState = 3;
    alphaSwizzle1 = alphaSwizzle1 | 0x8000;
  }
LAB_000d7144:
  textureUnitCount = ((unsigned char *)0x000013b2)[ctx];
  dstWriteWord = 0x140;
  if (combineAlphaMode == 0x86af) {
    if (rgbScale != FLOAT_001aa0e8) {
      if (rgbScale == FLOAT_001aa108) {
        dstWriteWord = 0x740;
      }
      else {
        dstWriteWord = 0x740;
        alphaSwizzle0 = alphaSwizzle0 | 0x40000;
      }
      goto LAB_000d7214;
    }
  }
  else if ((rgbScale != FLOAT_001aa104) && (combineAlphaMode != 0x8741)) {
    if (rgbScale == FLOAT_001aa108) {
      dstWriteWord = 0x340;
    }
    goto LAB_000d7214;
  }
  dstWriteWord = 0x540;
LAB_000d7214:
  tokenIndex = *countPtr;
  if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
    newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
    if (*(int *)(ilBuilder + 0xc) != 0) {
      _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
    }
    *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
    tokenIndex = *countPtr;
    *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = ilOpcode;
  tokenIndex = *countPtr + 1;
  *countPtr = tokenIndex;
  if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
    ilOpcode = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
    if (*(int *)(ilBuilder + 0xc) != 0) {
      _memcpy(ilOpcode,*(int *)(ilBuilder + 0xc),*countPtr << 2);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
    }
    *(undefined4 *)(ilBuilder + 0xc) = ilOpcode;
    tokenIndex = *countPtr;
    *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
  }
  *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) =
       (int)(short)unit + (uint)textureUnitCount & 0xffff | 0x440000;
  tokenIndex = *countPtr + 1;
  *countPtr = tokenIndex;
  if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
    ilOpcode = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
    if (*(int *)(ilBuilder + 0xc) != 0) {
      _memcpy(ilOpcode,*(int *)(ilBuilder + 0xc),*countPtr << 2);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
    }
    *(undefined4 *)(ilBuilder + 0xc) = ilOpcode;
    tokenIndex = *countPtr;
    *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = dstWriteWord;
  tokenIndex = *countPtr + 1;
  *countPtr = tokenIndex;
  if (unitState != 0) {
    loopCounter = 0;
    argOrderCursor = argOrder;
    do {
      argCount = *argOrderCursor;
      argOrderCursor = argOrderCursor + 1;
      alphaSourceToken = alphaSrcTokens[argCount];
      if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
        ilOpcode = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
        if (*(int *)(ilBuilder + 0xc) != 0) {
          _memcpy(ilOpcode,*(int *)(ilBuilder + 0xc),*countPtr << 2);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
        }
        *(undefined4 *)(ilBuilder + 0xc) = ilOpcode;
        tokenIndex = *countPtr;
        *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
      }
      *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = alphaSourceToken;
      tokenIndex = *countPtr + 1;
      *countPtr = tokenIndex;
      if ((alphaSrcTokens[argCount] & 0x400000) != 0) {
        alphaSourceSwizzle = alphaSwizzlesPtr[argCount];
        if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
          ilOpcode = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
          if (*(int *)(ilBuilder + 0xc) != 0) {
            _memcpy(ilOpcode,*(int *)(ilBuilder + 0xc),*countPtr << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
          }
          *(undefined4 *)(ilBuilder + 0xc) = ilOpcode;
          tokenIndex = *countPtr;
          *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
        }
        *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = alphaSourceSwizzle;
        tokenIndex = *countPtr + 1;
        *countPtr = tokenIndex;
      }
      loopCounter = loopCounter + 1;
    } while (unitState != loopCounter);
  }
  return;
}

/* ffpsEmitTexEnvLegacy @ 0xd7520 (3832 bytes) */
int ffpsEmitTexEnvLegacy(ctx, ilBuilder, baseFormat, texEnvMode, unit, textureObject, isFirstUnit, previousUnit)
  int ctx;
  int ilBuilder;
  uint baseFormat;
  uint texEnvMode;
  uint unit;
  int textureObject;
  int isFirstUnit;
  int previousUnit;
{
  uint tokenIndex3;
  undefined4 newTokenBuffer2;
  undefined4 newTokenBuffer;
  uint tokenIndex2;
  uint unitTempRegister;
  uint textureUnitCount;
  undefined4 grownTokenBuffer;
  uint tokenIndex;
  uint unitNumber;
  uint source2Swizzle;
  undefined4 destModifierWord;
  undefined *source1Swizzle;
  undefined *source0Swizzle;
  uint source2Token;
  undefined4 ilOpcode;
  uint unitDestToken;
  uint source1Token;
  uint colorSourceToken;
  uint argCount;
  uint *countPtr;
  
  countPtr = (uint *)(ilBuilder + 4);
  colorSourceToken = 0;
  source1Token = 0;
  source2Token = 0;
  source0Swizzle = (undefined *)0x0;
  source1Swizzle = (undefined *)0x0;
  source2Swizzle = 0;
  destModifierWord = 0;
  if ((((baseFormat == 0x1902) || (baseFormat == 0x81a5)) || (baseFormat == 0x81a7)) || (baseFormat == 0x81a6))
  {
    baseFormat = (uint)*(ushort *)(textureObject + 0x58);
  }
  textureUnitCount = (uint)(byte)((unsigned char *)0x000013b2)[ctx];
  unitNumber = unit & 0xffff;
  ilOpcode = 0;
  unitTempRegister = unitNumber + textureUnitCount & 0xffff;
  unitDestToken = unitTempRegister | 0x40000;
  if (texEnvMode == 0x1e01) {
    if (baseFormat != 0x1908) {
      if (baseFormat < 0x1909) {
        if (baseFormat == 0x1906) {
          ilOpcode = 3;
          if (isFirstUnit == 0) {
            colorSourceToken = textureUnitCount + previousUnit & 0xffff | 0x40000;
          }
          else {
            colorSourceToken = 0x120000;
          }
          tokenIndex = *countPtr;
          colorSourceToken = colorSourceToken | 0x400000;
          argCount = 2;
          source1Token = unitNumber | 0x440000;
          source1Swizzle = ((unsigned char *)0x00003444);
          source0Swizzle = ((unsigned char *)0x00004210);
          goto LAB_000d75e8;
        }
        if (baseFormat != 0x1907) goto LAB_000d75e0;
LAB_000d7d84:
        ilOpcode = 3;
        if (isFirstUnit == 0) {
          colorSourceToken = textureUnitCount + previousUnit & 0xffff | 0x40000;
        }
        else {
          colorSourceToken = 0x120000;
        }
        tokenIndex = *countPtr;
        colorSourceToken = colorSourceToken | 0x400000;
        argCount = 2;
        source1Token = unitNumber | 0x440000;
        source0Swizzle = ((unsigned char *)0x00003444);
        source1Swizzle = ((unsigned char *)0x00004210);
        goto LAB_000d75e8;
      }
      if (baseFormat != 0x190a) {
        if (baseFormat < 0x190a) goto LAB_000d7d84;
        if (baseFormat != 0x8049) goto LAB_000d75e0;
      }
    }
    tokenIndex = *countPtr;
    argCount = 1;
    ilOpcode = 0x47;
    colorSourceToken = unitNumber | 0x40000;
    goto LAB_000d75e8;
  }
  if (texEnvMode < 0x1e02) {
    if (texEnvMode == 0x104) {
      ilOpcode = 0x40;
      if (isFirstUnit == 0) {
        colorSourceToken = textureUnitCount + previousUnit & 0xffff | 0x40000;
      }
      else {
        colorSourceToken = 0x120000;
      }
      source1Token = unitNumber | 0x440000;
      source2Token = unitNumber | 0x440000;
      if (baseFormat < 0x190b) {
        if (0x1906 < baseFormat) {
LAB_000d7ee4:
          source1Swizzle = (undefined *)0x555;
          source2Swizzle = 0x210;
          goto LAB_000d7f0c;
        }
        if (baseFormat != 0x1906) goto LAB_000d7f0c;
        source2Swizzle = 0x444;
        source1Swizzle = (undefined *)0x555;
      }
      else {
        if (baseFormat == 0x8049) goto LAB_000d7ee4;
LAB_000d7f0c:
        if (baseFormat == 0x8049) {
          tokenIndex = *countPtr;
          argCount = 3;
          source1Swizzle = (undefined *)((uint)source1Swizzle | 0x5000);
          source2Swizzle = source2Swizzle | 0x3000;
          goto LAB_000d75e8;
        }
      }
      tokenIndex = *countPtr;
      argCount = 3;
      source1Swizzle = (undefined *)((uint)source1Swizzle | 0x3000);
      source2Swizzle = source2Swizzle | 0x4000;
      goto LAB_000d75e8;
    }
    if ((texEnvMode == 0xbe2) && (0x1905 < baseFormat)) {
      if (baseFormat < 0x190b) {
        if (isFirstUnit == 0) {
          source2Token = textureUnitCount + previousUnit & 0xffff | 0x40000;
        }
        else {
          source2Token = 0x120000;
        }
        tokenIndex3 = *countPtr;
        if (*(uint *)(ilBuilder + 8) <= tokenIndex3) {
          newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
          if (*(int *)(ilBuilder + 0xc) != 0) {
            _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
          }
          *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
          tokenIndex3 = *countPtr;
          *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
        }
        *(undefined4 *)(tokenIndex3 * 4 + *(int *)(ilBuilder + 0xc)) = 0x3f;
        tokenIndex3 = *countPtr + 1;
        *countPtr = tokenIndex3;
        if (*(uint *)(ilBuilder + 8) <= tokenIndex3) {
          newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
          if (*(int *)(ilBuilder + 0xc) != 0) {
            _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
          }
          *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
          tokenIndex3 = *countPtr;
          *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
        }
        *(uint *)(tokenIndex3 * 4 + *(int *)(ilBuilder + 0xc)) = unitTempRegister | 0x440000;
        tokenIndex3 = *countPtr + 1;
        *countPtr = tokenIndex3;
        if (*(uint *)(ilBuilder + 8) <= tokenIndex3) {
          newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
          if (*(int *)(ilBuilder + 0xc) != 0) {
            _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
          }
          *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
          tokenIndex3 = *countPtr;
          *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
        }
        *(undefined4 *)(tokenIndex3 * 4 + *(int *)(ilBuilder + 0xc)) = 0x15;
        tokenIndex3 = *countPtr + 1;
        *countPtr = tokenIndex3;
        if (*(uint *)(ilBuilder + 8) <= tokenIndex3) {
          newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
          if (*(int *)(ilBuilder + 0xc) != 0) {
            _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
          }
          *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
          tokenIndex3 = *countPtr;
          *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
        }
        *(uint *)(tokenIndex3 * 4 + *(int *)(ilBuilder + 0xc)) = unitNumber | 0x40000;
        tokenIndex3 = *countPtr + 1;
        *countPtr = tokenIndex3;
        if (*(uint *)(ilBuilder + 8) <= tokenIndex3) {
          newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
          if (*(int *)(ilBuilder + 0xc) != 0) {
            _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
          }
          *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
          tokenIndex3 = *countPtr;
          *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
        }
        *(uint *)(tokenIndex3 * 4 + *(int *)(ilBuilder + 0xc)) = unitNumber | 0x10000;
        tokenIndex3 = *countPtr + 1;
        *countPtr = tokenIndex3;
        if (*(uint *)(ilBuilder + 8) <= tokenIndex3) {
          newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
          if (*(int *)(ilBuilder + 0xc) != 0) {
            _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
          }
          *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
          tokenIndex3 = *countPtr;
          *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
        }
        ilOpcode = 0x49;
        *(uint *)(tokenIndex3 * 4 + *(int *)(ilBuilder + 0xc)) = source2Token;
        colorSourceToken = unitNumber | 0x40000;
        tokenIndex = *countPtr + 1;
        *countPtr = tokenIndex;
        if (isFirstUnit == 0) {
          source1Token = previousUnit + (uint)(byte)((unsigned char *)0x000013b2)[ctx] & 0xffff | 0x40000;
        }
        else {
          source1Token = 0x120000;
        }
        argCount = 2;
        unitDestToken = unitTempRegister | 0x440000;
        destModifierWord = 0x40;
        goto LAB_000d75e8;
      }
      if (baseFormat == 0x8049) {
        ilOpcode = 0x3f;
        colorSourceToken = unitNumber | 0x40000;
        source1Token = unitNumber | 0x10000;
        if (isFirstUnit == 0) {
          tokenIndex = *countPtr;
          argCount = 0;
          source2Token = textureUnitCount + previousUnit & 0xffff | 0x40000;
        }
        else {
          tokenIndex = *countPtr;
          argCount = 0;
          source2Token = 0x120000;
        }
        goto LAB_000d75e8;
      }
    }
  }
  else {
    if (texEnvMode == 0x2100) {
      if (baseFormat == 0x1906) {
        ilOpcode = 0x49;
        if (isFirstUnit == 0) {
          source1Token = textureUnitCount + previousUnit & 0xffff | 0x40000;
        }
        else {
          source1Token = 0x120000;
        }
        tokenIndex = *countPtr;
        colorSourceToken = unitNumber | 0x440000;
        argCount = 2;
        source0Swizzle = ((unsigned char *)0x00003555);
      }
      else if (baseFormat == 0x1907) {
        ilOpcode = 0x49;
        if (isFirstUnit == 0) {
          source1Token = textureUnitCount + previousUnit & 0xffff | 0x40000;
        }
        else {
          source1Token = 0x120000;
        }
        tokenIndex = *countPtr;
        colorSourceToken = unitNumber | 0x440000;
        argCount = 2;
        source0Swizzle = ((unsigned char *)0x00005210);
      }
      else {
        ilOpcode = 0x49;
        colorSourceToken = unitNumber | 0x40000;
        if (isFirstUnit == 0) {
          tokenIndex = *countPtr;
          argCount = 2;
          source1Token = textureUnitCount + previousUnit & 0xffff | 0x40000;
        }
        else {
          tokenIndex = *countPtr;
          argCount = 2;
          source1Token = 0x120000;
        }
      }
      goto LAB_000d75e8;
    }
    if (texEnvMode == 0x2101) {
      if (baseFormat == 0x1907) {
        ilOpcode = 3;
        if (isFirstUnit == 0) {
          source1Token = textureUnitCount + previousUnit & 0xffff | 0x40000;
        }
        else {
          source1Token = 0x120000;
        }
        tokenIndex = *countPtr;
        colorSourceToken = unitNumber | 0x440000;
        source1Token = source1Token | 0x400000;
        argCount = 2;
        source0Swizzle = ((unsigned char *)0x00004210);
        source1Swizzle = ((unsigned char *)0x00003444);
        goto LAB_000d75e8;
      }
      if (baseFormat == 0x1908) {
        ilOpcode = 0x3f;
        if (isFirstUnit == 0) {
          source2Token = textureUnitCount + previousUnit & 0xffff | 0x40000;
        }
        else {
          source2Token = 0x120000;
        }
        tokenIndex = *countPtr;
        colorSourceToken = unitNumber | 0x440000;
        source1Token = unitNumber | 0x440000;
        argCount = 3;
        source0Swizzle = ((unsigned char *)0x00004333);
        source1Swizzle = ((unsigned char *)0x00004210);
        goto LAB_000d75e8;
      }
    }
  }
LAB_000d75e0:
  tokenIndex = *countPtr;
  argCount = 0;
LAB_000d75e8:
  if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
    grownTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
    if (*(int *)(ilBuilder + 0xc) != 0) {
      _memcpy(grownTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
    }
    *(undefined4 *)(ilBuilder + 0xc) = grownTokenBuffer;
    tokenIndex = *countPtr;
    *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = ilOpcode;
  tokenIndex2 = *countPtr + 1;
  *countPtr = tokenIndex2;
  if (*(uint *)(ilBuilder + 8) <= tokenIndex2) {
    newTokenBuffer2 = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
    if (*(int *)(ilBuilder + 0xc) != 0) {
      _memcpy(newTokenBuffer2,*(int *)(ilBuilder + 0xc),*countPtr << 2);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
    }
    *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer2;
    tokenIndex2 = *countPtr;
    *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
  }
  *(uint *)(tokenIndex2 * 4 + *(int *)(ilBuilder + 0xc)) = unitDestToken;
  tokenIndex2 = *countPtr + 1;
  *countPtr = tokenIndex2;
  if ((unitDestToken & 0x400000) != 0) {
    if (*(uint *)(ilBuilder + 8) <= tokenIndex2) {
      newTokenBuffer2 = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer2,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer2;
      tokenIndex2 = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex2 * 4 + *(int *)(ilBuilder + 0xc)) = destModifierWord;
    tokenIndex2 = *countPtr + 1;
    *countPtr = tokenIndex2;
  }
  if (argCount != 0) {
    if (*(uint *)(ilBuilder + 8) <= tokenIndex2) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex2 = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(uint *)(tokenIndex2 * 4 + *(int *)(ilBuilder + 0xc)) = colorSourceToken;
    tokenIndex2 = *countPtr + 1;
    *countPtr = tokenIndex2;
    if ((colorSourceToken & 0x400000) != 0) {
      if (*(uint *)(ilBuilder + 8) <= tokenIndex2) {
        newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
        if (*(int *)(ilBuilder + 0xc) != 0) {
          _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
        }
        *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
        tokenIndex2 = *countPtr;
        *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
      }
      *(undefined **)(tokenIndex2 * 4 + *(int *)(ilBuilder + 0xc)) = source0Swizzle;
      tokenIndex2 = *countPtr + 1;
      *countPtr = tokenIndex2;
    }
  }
  if (1 < argCount) {
    if (*(uint *)(ilBuilder + 8) <= tokenIndex2) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex2 = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(uint *)(tokenIndex2 * 4 + *(int *)(ilBuilder + 0xc)) = source1Token;
    tokenIndex2 = *countPtr + 1;
    *countPtr = tokenIndex2;
    if ((source1Token & 0x400000) != 0) {
      if (*(uint *)(ilBuilder + 8) <= tokenIndex2) {
        newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
        if (*(int *)(ilBuilder + 0xc) != 0) {
          _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
        }
        *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
        tokenIndex2 = *countPtr;
        *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
      }
      *(undefined **)(tokenIndex2 * 4 + *(int *)(ilBuilder + 0xc)) = source1Swizzle;
      tokenIndex2 = *countPtr + 1;
      *countPtr = tokenIndex2;
    }
  }
  if (2 < argCount) {
    if (*(uint *)(ilBuilder + 8) <= tokenIndex2) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex2 = *countPtr;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(uint *)(tokenIndex2 * 4 + *(int *)(ilBuilder + 0xc)) = source2Token;
    tokenIndex3 = *countPtr + 1;
    *countPtr = tokenIndex3;
    if ((source2Token & 0x400000) != 0) {
      if (*(uint *)(ilBuilder + 8) <= tokenIndex3) {
        newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
        if (*(int *)(ilBuilder + 0xc) != 0) {
          _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
        }
        *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
        tokenIndex3 = *countPtr;
        *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
      }
      *(uint *)(tokenIndex3 * 4 + *(int *)(ilBuilder + 0xc)) = source2Swizzle;
      *countPtr = *countPtr + 1;
    }
  }
  return;
}

/* FUN_000d8450 @ 0xd8450 (5856 bytes) */
int FUN_000d8450(ctx, ilBuilder, useUnitFlags)
  int ctx;
  int ilBuilder;
  int useUnitFlags;
{
  uint unitIndex;
  uint tokenIndex;
  bool hasNoCompareMode;
  uint coordRegisterIndex;
  undefined4 newTokenBuffer;
  uint textureUnitCount;
  int texEnvRecord;
  int unitByteCursor;
  int unitPtrCursor;
  int unitRecordCursor;
  char *unitFlagPtr;
  uint unit;
  uint sourceRegisterToken;
  uint ilOpcode;
  undefined *swizzleToken;
  uint *countPtr;
  int iStack00000020;
  char unitFlags [28];
  
  countPtr = (uint *)(ilBuilder + 4);
  textureUnitCount = (uint)(byte)((unsigned char *)0x000013b2)[ctx];
  if (textureUnitCount != 0) {
    unit = 0;
    texEnvRecord = ctx + 0x450;
    unitByteCursor = ctx;
    unitPtrCursor = ctx;
    unitRecordCursor = ctx;
    iStack00000020 = useUnitFlags;
    do {
      if (*(int *)(((unsigned char *)0x000013f8) + unitPtrCursor) != 0) {
        hasNoCompareMode = false;
        if ((*(uint *)(ctx + 0x44) & 0x100000) != 0) {
          hasNoCompareMode = *(char *)(unit + *(int *)(((unsigned char *)0x00001168) + ctx) + 0x71) == '\0';
        }
        if (((int)(uint)*(byte *)(ctx + 0x20) >> (unit & 0x3f) & 1U) == 0) {
          if ((*(short *)(unitRecordCursor + 0x450) != -0x7a90) || (*(short *)(texEnvRecord + 4) != -0x7885)) {
            tokenIndex = *countPtr;
            if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
              newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
              if (*(int *)(ilBuilder + 0xc) != 0) {
                _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
                (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
              }
              *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
              tokenIndex = *countPtr;
              *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
            }
            *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = (unit & 0xff) << 0x10 | 0x800005d;
            tokenIndex = *countPtr + 1;
            *countPtr = tokenIndex;
            if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
              newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
              if (*(int *)(ilBuilder + 0xc) != 0) {
                _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
                (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
              }
              *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
              tokenIndex = *countPtr;
              *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
            }
            *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = unit & 0xffff | 0x40000;
            tokenIndex = *countPtr + 1;
            *countPtr = tokenIndex;
            if ((iStack00000020 == 0) || (unitFlags[unit] == '\0')) {
              if ((hasNoCompareMode) &&
                 (((*(uint *)(ctx + 0x44) & 0x20000000) == 0 ||
                  ((1 << (unit & 0x3f) & *(uint *)(ctx + 0xec)) == 0)))) {
                sourceRegisterToken = 0x10011;
              }
              else {
                sourceRegisterToken = unit & 0xffff | 0x110000;
              }
            }
            else {
              sourceRegisterToken = unit + (uint)(byte)((unsigned char *)0x000013b2)[ctx] * 2 & 0xffff | 0x40000;
            }
            if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
              newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
              if (*(int *)(ilBuilder + 0xc) != 0) {
                _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
                (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
              }
              *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
              tokenIndex = *countPtr;
              *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
            }
            *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = sourceRegisterToken | 0x400000;
            tokenIndex = *countPtr + 1;
            *countPtr = tokenIndex;
            if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
              newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
              if (*(int *)(ilBuilder + 0xc) != 0) {
                _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
                (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
              }
              *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
              tokenIndex = *countPtr;
              *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
            }
            *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x603210;
            *countPtr = *countPtr + 1;
            textureUnitCount = (uint)(byte)((unsigned char *)0x000013b2)[ctx];
          }
        }
        else {
          tokenIndex = *countPtr;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x49;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          unitIndex = unit & 0xffff;
          *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x40020;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          coordRegisterIndex = unitIndex + 0x14 & 0xffff;
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = unitIndex | 0x110000;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          unitFlagPtr = (char *)(unitByteCursor + 0x21);
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = coordRegisterIndex | 0x410000;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(char *)(unitByteCursor + 0x21) == '\x01') {
            ilOpcode = 0x50;
          }
          else {
            ilOpcode = 5;
          }
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = ilOpcode | 0x5500;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = (unit & 0xff) << 0x10 | 0x800005d;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x40020;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x440020;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x603210;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x40;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x40021;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = unitIndex | 0x110000;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = coordRegisterIndex | 0x410000;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*unitFlagPtr == '\x01') {
            ilOpcode = 0x51;
          }
          else {
            ilOpcode = 0x15;
          }
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = ilOpcode | 0x5500;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = coordRegisterIndex | 0x410000;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*unitFlagPtr == '\x01') {
            ilOpcode = 0x42;
          }
          else {
            ilOpcode = 0x24;
          }
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = ilOpcode | 0x4400;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) =
               ((unit & 0xff) + 8) * 0x10000 & 0xff0000 | 0x800005d;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x40021;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x440021;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x603210;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x5b;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x40022;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = unitIndex | 0x510000;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*unitFlagPtr == '\x01') {
            swizzleToken = (undefined *)0x0;
          }
          else {
            swizzleToken = ((unsigned char *)0x00001111);
          }
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(undefined **)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = swizzleToken;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = coordRegisterIndex | 0x410000;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(undefined **)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = ((unsigned char *)0x00003333);
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x3000d;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = unitIndex | 0x40000;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x40022;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x40021;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*countPtr << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *countPtr;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x40020;
          *countPtr = *countPtr + 1;
          textureUnitCount = (uint)(byte)((unsigned char *)0x000013b2)[ctx];
        }
      }
      unit = unit + 1;
      texEnvRecord = texEnvRecord + 0xcc;
      unitPtrCursor = unitPtrCursor + 4;
      unitRecordCursor = unitRecordCursor + 0xcc;
      unitByteCursor = unitByteCursor + 1;
    } while ((int)unit < (int)textureUnitCount);
  }
  return;
}

/* BitSet256__findNthSetBit @ 0xd9b58 (84 bytes) */
int BitSet256__findNthSetBit(unusedArg1, bitWords, nthSetBit, unusedArg4, unusedArg5, unusedArg6, unusedArg7)
  undefined4 unusedArg1;
  uint *bitWords;
  int nthSetBit;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
{
  bool notLastWord;
  uint wordBits;
  int loopCounter;
  int loopCounterB;
  
  loopCounter = 0;
  do {
    wordBits = *bitWords;
    if (wordBits != 0) {
      loopCounterB = 0;
      do {
        if ((wordBits & 1) != 0) {
          if (nthSetBit == 0) {
            return loopCounterB + loopCounter;
          }
          nthSetBit = nthSetBit + -1;
        }
        wordBits = wordBits >> 1;
        loopCounterB = loopCounterB + 1;
      } while (wordBits != 0);
    }
    notLastWord = loopCounter != 0xe0;
    bitWords = bitWords + 1;
    loopCounter = loopCounter + 0x20;
  } while (notLastWord);
  return -1;
}

/* scStoreConstantComponent @ 0xd9bac (228 bytes) */
undefined4 scStoreConstantComponent(undefined4 unusedArg1,int constRegister,undefined4 unusedArg3,int lane,int constBlock,int useLiteralTable,double laneValue)
{
  int nextEntryOffset;
  uint entryCount;
  int entryOffset;
  int *tableBase;
  int *entryCursor;
  uint entriesLeft;
  
  if (useLiteralTable == 0) {
    tableBase = *(int **)(constBlock + 0x84);
    if (tableBase != (int *)0x0) {
      entryCount = *(uint *)(constBlock + 0x78);
      if (entryCount == 0) {
LAB_000d9c0c:
        if (*(uint *)(constBlock + 0x6c) <= entryCount) {
          return 0;
        }
        entryOffset = entryCount * 0x14;
        *(uint *)(constBlock + 0x78) = entryCount + 1;
      }
      else if (*tableBase == constRegister) {
        entryOffset = 0;
      }
      else {
        nextEntryOffset = 0x14;
        entriesLeft = entryCount;
        entryCursor = tableBase;
        do {
          entryOffset = nextEntryOffset;
          entryCursor = entryCursor + 5;
          entriesLeft = entriesLeft - 1;
          if (entriesLeft == 0) goto LAB_000d9c0c;
          nextEntryOffset = entryOffset + 0x14;
        } while (*entryCursor != constRegister);
      }
      *(int *)(entryOffset + (int)tableBase) = constRegister;
      *(float *)((int)tableBase + lane * 4 + entryOffset + 4) = (float)laneValue;
      return 1;
    }
  }
  else {
    entryCount = *(uint *)(constBlock + 0x54);
    if (entryCount < *(uint *)(constBlock + 0x48)) {
      *(uint *)(constBlock + 0x54) = entryCount + 1;
      entryOffset = entryCount * 0x24 + *(int *)(constBlock + 0x60);
      *(int *)(entryCount * 0x24 + *(int *)(constBlock + 0x60)) = constRegister;
      *(float *)(entryOffset + 0x14) = (float)laneValue;
      *(int *)(entryOffset + 4) = lane;
      *(undefined4 *)(entryOffset + 8) = 1;
      return 1;
    }
  }
  return 0;
}

/* ConstBank__storeIntLane @ 0xd9c90 (228 bytes) */
int ConstBank__storeIntLane(unusedArg1, registerKey, laneValue, lane, bank, useGlobalList)
  undefined4 unusedArg1;
  int registerKey;
  undefined4 laneValue;
  int lane;
  int bank;
  int useGlobalList;
{
  uint literalRecordCount;
  uint entryCount;
  int nextEntryOffset;
  int entryOffset;
  int *entryTable;
  int *entryCursor;
  uint entriesLeft;
  
  if (useGlobalList == 0) {
    entryTable = *(int **)(bank + 0x88);
    if (entryTable != (int *)0x0) {
      entryCount = *(uint *)(bank + 0x7c);
      if (entryCount == 0) {
LAB_000d9cf0:
        if (*(uint *)(bank + 0x70) <= entryCount) {
          return 0;
        }
        entryOffset = entryCount * 0x14;
        *(uint *)(bank + 0x7c) = entryCount + 1;
      }
      else if (*entryTable == registerKey) {
        entryOffset = 0;
      }
      else {
        nextEntryOffset = 0x14;
        entriesLeft = entryCount;
        entryCursor = entryTable;
        do {
          entryOffset = nextEntryOffset;
          entryCursor = entryCursor + 5;
          entriesLeft = entriesLeft - 1;
          if (entriesLeft == 0) goto LAB_000d9cf0;
          nextEntryOffset = entryOffset + 0x14;
        } while (*entryCursor != registerKey);
      }
      *(int *)(entryOffset + (int)entryTable) = registerKey;
      *(undefined4 *)((int)entryTable + lane * 4 + entryOffset + 4) = laneValue;
      return 1;
    }
  }
  else {
    literalRecordCount = *(uint *)(bank + 0x58);
    if (literalRecordCount < *(uint *)(bank + 0x4c)) {
      *(uint *)(bank + 0x58) = literalRecordCount + 1;
      entryOffset = literalRecordCount * 0x24 + *(int *)(bank + 100);
      *(int *)(literalRecordCount * 0x24 + *(int *)(bank + 100)) = registerKey;
      *(undefined4 *)(entryOffset + 0x14) = laneValue;
      *(int *)(entryOffset + 4) = lane;
      *(undefined4 *)(entryOffset + 8) = 0;
      return 1;
    }
  }
  return 0;
}

/* ConstBank__storeBoolLane @ 0xd9d74 (228 bytes) */
int ConstBank__storeBoolLane(unusedArg1, registerKey, laneValue, lane, bank, useGlobalList)
  undefined4 unusedArg1;
  int registerKey;
  undefined4 laneValue;
  int lane;
  int bank;
  int useGlobalList;
{
  uint literalRecordCount;
  uint entryCount;
  int nextEntryOffset;
  int entryOffset;
  int *entryTable;
  int *entryCursor;
  uint entriesLeft;
  
  if (useGlobalList == 0) {
    entryTable = *(int **)(bank + 0x8c);
    if (entryTable != (int *)0x0) {
      entryCount = *(uint *)(bank + 0x80);
      if (entryCount == 0) {
LAB_000d9dd4:
        if (*(uint *)(bank + 0x74) <= entryCount) {
          return 0;
        }
        entryOffset = entryCount * 0x14;
        *(uint *)(bank + 0x80) = entryCount + 1;
      }
      else if (*entryTable == registerKey) {
        entryOffset = 0;
      }
      else {
        nextEntryOffset = 0x14;
        entriesLeft = entryCount;
        entryCursor = entryTable;
        do {
          entryOffset = nextEntryOffset;
          entryCursor = entryCursor + 5;
          entriesLeft = entriesLeft - 1;
          if (entriesLeft == 0) goto LAB_000d9dd4;
          nextEntryOffset = entryOffset + 0x14;
        } while (*entryCursor != registerKey);
      }
      *(int *)(entryOffset + (int)entryTable) = registerKey;
      *(undefined4 *)((int)entryTable + lane * 4 + entryOffset + 4) = laneValue;
      return 1;
    }
  }
  else {
    literalRecordCount = *(uint *)(bank + 0x5c);
    if (literalRecordCount < *(uint *)(bank + 0x50)) {
      *(uint *)(bank + 0x5c) = literalRecordCount + 1;
      entryOffset = literalRecordCount * 0x24 + *(int *)(bank + 0x68);
      *(int *)(literalRecordCount * 0x24 + *(int *)(bank + 0x68)) = registerKey;
      *(undefined4 *)(entryOffset + 0x14) = laneValue;
      *(int *)(entryOffset + 4) = lane;
      *(undefined4 *)(entryOffset + 8) = 2;
      return 1;
    }
  }
  return 0;
}

/* scStoreIntConstantComponent @ 0xd9e58 (64 bytes) */
int scStoreIntConstantComponent(unusedArg1, constRegister, valueHighHalf, valueLowHalf, lane, constBlock)
  undefined4 unusedArg1;
  undefined4 constRegister;
  undefined4 valueHighHalf;
  undefined4 valueLowHalf;
  undefined4 lane;
  int constBlock;
{
  uint recordIndex;
  int recordAddr;
  
  recordIndex = *(uint *)(constBlock + 0x54);
  if (*(uint *)(constBlock + 0x48) <= recordIndex) {
    return 0;
  }
  recordAddr = recordIndex * 0x24 + *(int *)(constBlock + 0x60);
  *(uint *)(constBlock + 0x54) = recordIndex + 1;
  *(undefined4 *)(recordIndex * 0x24 + *(int *)(constBlock + 0x60)) = constRegister;
  *(undefined4 *)(recordAddr + 0x10) = valueLowHalf;
  *(undefined4 *)(recordAddr + 4) = lane;
  *(undefined4 *)(recordAddr + 8) = valueHighHalf;
  return 1;
}

/* ConstBank__addMappedEntry @ 0xd9e98 (156 bytes) */
int ConstBank__addMappedEntry(unusedArg1, registerKey, unusedArg3, unusedArg4, valueLo, valueHi, maskByte, sourceRegister, extraWord, bank)
  undefined4 unusedArg1;
  undefined4 registerKey;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 valueLo;
  undefined4 valueHi;
  int maskByte;
  int sourceRegister;
  undefined4 extraWord;
  int bank;
{
  uint entryIndex;
  int entry;
  
  entryIndex = *(uint *)(bank + 0x58);
  if (*(uint *)(bank + 0x4c) <= entryIndex) {
    return 0;
  }
  *(uint *)(bank + 0x58) = entryIndex + 1;
  entry = entryIndex * 0x24 + *(int *)(bank + 100);
  *(undefined4 *)(entryIndex * 0x24 + *(int *)(bank + 100)) = registerKey;
  *(undefined4 *)(entry + 4) = 0;
  if (sourceRegister == -1) {
    if (maskByte == 0xff) {
      *(undefined4 *)(entry + 8) = 0x15;
    }
    else {
      *(undefined4 *)(entry + 8) = 0x16;
    }
  }
  else if (maskByte == 0xff) {
    *(undefined4 *)(entry + 8) = 0x17;
  }
  else {
    *(undefined4 *)(entry + 8) = 0x18;
  }
  *(int *)(entry + 0x1c) = sourceRegister;
  *(undefined4 *)(entry + 0x10) = valueLo;
  *(undefined4 *)(entry + 0xc) = valueHi;
  *(undefined4 *)(entry + 0x20) = extraWord;
  return 1;
}

/* CompileInput__lacksFlag0x200000 @ 0xd9f3c (60 bytes) */
int CompileInput__lacksFlag0x200000(compileInput, sideSelector)
  int compileInput;
  int sideSelector;
{
  bool result;
  int sideObject;
  
  if (sideSelector == 0) {
    sideObject = *(int *)(compileInput + 0x2c);
  }
  else {
    sideObject = *(int *)(compileInput + 0x30);
  }
  result = true;
  if (*(uint **)(sideObject + 0x48) != (uint *)0x0) {
    result = (**(uint **)(sideObject + 0x48) & 0x200000) == 0;
  }
  return result;
}

/* CompileInput__getFloatConstCount @ 0xd9f80 (32 bytes) */
int CompileInput__getFloatConstCount(compileInput, sideSelector)
  int compileInput;
  int sideSelector;
{
  if (sideSelector != 0) {
    return *(undefined4 *)(*(int *)(compileInput + 0x30) + 0x3c);
  }
  return *(undefined4 *)(*(int *)(compileInput + 0x2c) + 0x40);
}

/* CompileInput__getIntConstCount @ 0xd9fa0 (32 bytes) */
int CompileInput__getIntConstCount(compileInput, sideSelector)
  int compileInput;
  int sideSelector;
{
  if (sideSelector != 0) {
    return *(undefined4 *)(*(int *)(compileInput + 0x30) + 0xc);
  }
  return *(undefined4 *)(*(int *)(compileInput + 0x2c) + 0x10);
}

/* CompileInput__getBoolConstCount @ 0xd9fc0 (32 bytes) */
int CompileInput__getBoolConstCount(compileInput, sideSelector)
  int compileInput;
  int sideSelector;
{
  if (sideSelector != 0) {
    return *(undefined4 *)(*(int *)(compileInput + 0x30) + 0x24);
  }
  return *(undefined4 *)(*(int *)(compileInput + 0x2c) + 0x28);
}

/* CompileInput__readFloatConst @ 0xd9fe0 (72 bytes) */
int CompileInput__readFloatConst(compileInput, sideSelector, constIndex, unusedArg4, outValue)
  int compileInput;
  int sideSelector;
  int constIndex;
  undefined4 unusedArg4;
  undefined4 *outValue;
{
  int recordAddr;
  int tableBase;
  
  if (sideSelector == 0) {
    tableBase = *(int *)(*(int *)(compileInput + 0x2c) + 0x34);
  }
  else {
    tableBase = *(int *)(*(int *)(compileInput + 0x30) + 0x30);
  }
  recordAddr = tableBase + constIndex * 0x10;
  *outValue = *(undefined4 *)(tableBase + constIndex * 0x10);
  outValue[1] = *(undefined4 *)(recordAddr + 4);
  outValue[2] = *(undefined4 *)(recordAddr + 8);
  outValue[3] = *(undefined4 *)(recordAddr + 0xc);
  return;
}

/* CompileInput__readIntConst @ 0xda028 (72 bytes) */
int CompileInput__readIntConst(compileInput, sideSelector, constIndex, unusedArg4, outValue)
  int compileInput;
  int sideSelector;
  int constIndex;
  undefined4 unusedArg4;
  undefined4 *outValue;
{
  int tableBase;
  int recordAddr;
  
  if (sideSelector == 0) {
    tableBase = *(int *)(*(int *)(compileInput + 0x2c) + 4);
  }
  else {
    tableBase = **(int **)(compileInput + 0x30);
  }
  recordAddr = tableBase + constIndex * 0x10;
  *outValue = *(undefined4 *)(tableBase + constIndex * 0x10);
  outValue[1] = *(undefined4 *)(recordAddr + 4);
  outValue[2] = *(undefined4 *)(recordAddr + 8);
  outValue[3] = *(undefined4 *)(recordAddr + 0xc);
  return;
}

/* CompileInput__readBoolConst @ 0xda070 (44 bytes) */
int CompileInput__readBoolConst(compileInput, sideSelector, constIndex, unusedArg4, outValue)
  int compileInput;
  int sideSelector;
  int constIndex;
  undefined4 unusedArg4;
  undefined4 *outValue;
{
  int iVar1;
  
  if (sideSelector == 0) {
    iVar1 = *(int *)(*(int *)(compileInput + 0x2c) + 0x1c);
  }
  else {
    iVar1 = *(int *)(*(int *)(compileInput + 0x30) + 0x18);
  }
  *outValue = *(undefined4 *)(iVar1 + constIndex * 4);
  return;
}

/* Compiler__bumpStatsCounter100 @ 0xda09c (36 bytes) */
int Compiler__bumpStatsCounter100(compiler, selector)
  int compiler;
  int selector;
{
  int statsObject;
  
  if (selector == 0) {
    statsObject = *(int *)(compiler + 0x38);
  }
  else {
    statsObject = *(int *)(compiler + 0x3c);
  }
  *(int *)(statsObject + 0x100) = *(int *)(statsObject + 0x100) + 1;
  return;
}

/* Compiler__createFromRequest_da0c0 @ 0xda0c0 (192 bytes) */
int Compiler__createFromRequest_da0c0(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int hardwareKind;
  int setjmpResult;
  int compilerObj;
  undefined4 requestOwner;
  undefined4 requestArena;
  int limitForObject4;
  int limitForObject8;
  undefined4 *stateOutHome;
  undefined4 *requestHome;
  
  stateOutHome = param_1;
  requestHome = param_2;
  compilerObj = (*(code *)param_2[0xc])(param_2[0xb],0x6c8);
  requestArena = requestHome[0xd];
  *stateOutHome = requestArena;
  requestOwner = requestHome[0xb];
  stateOutHome[1] = requestOwner;
  stateOutHome[3] = *requestHome;
  stateOutHome[5] = requestHome[1];
  stateOutHome[4] = requestHome[0x14];
  if (compilerObj == 0) {
    stateOutHome[2] = 0;
    return;
  }
  Compiler__init_e1a48(compilerObj,requestOwner,requestHome[0xc],requestArena,0,0,requestHome[0xf],requestHome[0x10]
               ,requestHome[0x11],requestHome[0x12],requestHome[0x13],
               requestHome[0xe]);
  stateOutHome[2] = compilerObj;
  if (*(int *)(compilerObj + 0x314) != 0) {
    return;
  }
  setjmpResult = _setjmp(*(int **)(compilerObj + 4));
  if (setjmpResult != 0) {
    return;
  }
  if (stateOutHome[3] == -1) {
    stateOutHome[10] = requestHome[2];
  }
  else {
    requestOwner = FUN_000cd290(stateOutHome[3]);
    stateOutHome[10] = requestOwner;
  }
  hardwareKind = stateOutHome[10];
  limitForObject4 = requestHome[3];
  limitForObject8 = requestHome[4];
  if (hardwareKind == 2) {
    Compiler__setHardwareFamily(stateOutHome[2],2);
    if (limitForObject8 - 1U < 0x20c) {
      *(int *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 8) + 0x40) = limitForObject8;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 8) + 0x40) = 0x20c;
    }
    if (limitForObject4 - 1U < 0x100) goto code_r0x000da340;
  }
  else {
    if (hardwareKind == 3) {
      Compiler__setHardwareFamily(stateOutHome[2],4);
      if (limitForObject8 - 1U < 0x200) {
        *(int *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 8) + 0x40) = limitForObject8;
      }
      else {
        *(undefined4 *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 8) + 0x40) = 0x200;
      }
      if (0x3ff < limitForObject4 - 1U) {
        *(undefined4 *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 4) + 0x40) = 0x400;
        return;
      }
code_r0x000da340:
      *(int *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 4) + 0x40) = limitForObject4;
      return;
    }
    if (hardwareKind != 1) {
      *(undefined4 *)(stateOutHome[2] + 0x314) = 0xe;
      Compiler__setHardwareFamily(stateOutHome[2],1);
      return;
    }
    Compiler__setHardwareFamily(stateOutHome[2],1);
    if (limitForObject8 - 1U < 0x60) {
      *(int *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 8) + 0x40) = limitForObject8;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 8) + 0x40) = 0x60;
    }
    if (limitForObject4 - 1U < 0x100) {
      *(int *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 4) + 0x40) = limitForObject8;
      return;
    }
  }
  *(undefined4 *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 4) + 0x40) = 0x100;
  return;
}

/* scSetCallbackTables @ 0xda394 (68 bytes) */
int scSetCallbackTables(compileInput, request, resultObject)
  int compileInput;
  int request;
  undefined4 resultObject;
{
  undefined4 status;
  
  *(undefined4 *)(compileInput + 0x38) = resultObject;
  *(undefined4 *)(compileInput + 0x3c) = resultObject;
  *(undefined4 *)(compileInput + 0x40) = resultObject;
  *(int *)(compileInput + 0x2c) = request;
  *(int *)(compileInput + 0x30) = request;
  *(int *)(compileInput + 0x34) = request;
  if (*(int *)(compileInput + 8) != 0) {
    status = Compiler__compileWithRetry(*(int *)(compileInput + 8),resultObject,*(undefined4 *)(request + 0x4c),
                         *(undefined4 *)(request + 0x54),compileInput);
    return status;
  }
  return 2;
}

/* FUN_000da420 @ 0xda420 (24 bytes) */
int FUN_000da420(param_1)
  int param_1;
{
  if (*(int *)(param_1 + 8) == 0) {
    return 2;
  }
  return *(undefined4 *)(*(int *)(param_1 + 8) + 0x314);
}

/* FUN_000da438 @ 0xda438 (32 bytes) */
int FUN_000da438(targetObject, param_2)
  int targetObject;
  undefined4 *param_2;
{
  undefined4 secondWord;
  undefined4 thirdWord;
  
  thirdWord = param_2[2];
  secondWord = param_2[1];
  *(undefined4 *)(targetObject + 0x18) = *param_2;
  *(undefined4 *)(targetObject + 0x20) = thirdWord;
  *(undefined4 *)(targetObject + 0x1c) = secondWord;
  return;
}

/* scDestroyCompilerObject @ 0xda458 (96 bytes) */
int scDestroyCompilerObject(state, releaseChip)
  undefined4 *state;
  undefined4 releaseChip;
{
  if (state[2] != 0) {
    Compiler__releaseChipAndPools(state[2],releaseChip);
                    
                    
    (*(code *)*state)(state[1],state[2]);
    return;
  }
  return;
}

/* Compiler__createFromRequest @ 0xda4b8 (192 bytes) */
int Compiler__createFromRequest(state, request)
  undefined4 *state;
  undefined4 *request;
{
  int hardwareKind;
  int setjmpResult;
  int compilerObj;
  undefined4 requestOwner;
  undefined4 requestArena;
  int limitForObject4;
  int limitForObject8;
  undefined4 *stateOutHome;
  undefined4 *requestHome;
  
  stateOutHome = state;
  requestHome = request;
  compilerObj = (*(code *)request[0xc])(request[0xb],0x6c8);
  requestArena = requestHome[0xd];
  *stateOutHome = requestArena;
  requestOwner = requestHome[0xb];
  stateOutHome[1] = requestOwner;
  stateOutHome[3] = *requestHome;
  stateOutHome[5] = requestHome[1];
  stateOutHome[4] = requestHome[0x14];
  if (compilerObj == 0) {
    stateOutHome[2] = 0;
    return;
  }
  Compiler__init_e1a48(compilerObj,requestOwner,requestHome[0xc],requestArena,0,0,requestHome[0xf],requestHome[0x10]
               ,requestHome[0x11],requestHome[0x12],requestHome[0x13],
               requestHome[0xe]);
  stateOutHome[2] = compilerObj;
  if (*(int *)(compilerObj + 0x314) != 0) {
    return;
  }
  setjmpResult = _setjmp(*(int **)(compilerObj + 4));
  if (setjmpResult != 0) {
    return;
  }
  if (stateOutHome[3] == -1) {
    stateOutHome[10] = requestHome[2];
  }
  else {
    requestOwner = FUN_000cd290(stateOutHome[3]);
    stateOutHome[10] = requestOwner;
  }
  hardwareKind = stateOutHome[10];
  limitForObject4 = requestHome[3];
  limitForObject8 = requestHome[4];
  if (hardwareKind == 2) {
    Compiler__setHardwareFamily(stateOutHome[2],2);
    if (limitForObject8 - 1U < 0x20c) {
      *(int *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 8) + 0x40) = limitForObject8;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 8) + 0x40) = 0x20c;
    }
    if (limitForObject4 - 1U < 0x100) goto code_r0x000da738;
  }
  else {
    if (hardwareKind == 3) {
      Compiler__setHardwareFamily(stateOutHome[2],4);
      if (limitForObject8 - 1U < 0x200) {
        *(int *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 8) + 0x40) = limitForObject8;
      }
      else {
        *(undefined4 *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 8) + 0x40) = 0x200;
      }
      if (0x3ff < limitForObject4 - 1U) {
        *(undefined4 *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 4) + 0x40) = 0x400;
        return;
      }
code_r0x000da738:
      *(int *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 4) + 0x40) = limitForObject4;
      return;
    }
    if (hardwareKind != 1) {
      *(undefined4 *)(stateOutHome[2] + 0x314) = 0xe;
      Compiler__setHardwareFamily(stateOutHome[2],1);
      return;
    }
    Compiler__setHardwareFamily(stateOutHome[2],1);
    if (limitForObject8 - 1U < 0x60) {
      *(int *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 8) + 0x40) = limitForObject8;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 8) + 0x40) = 0x60;
    }
    if (limitForObject4 - 1U < 0x100) {
      *(int *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 4) + 0x40) = limitForObject8;
      return;
    }
  }
  *(undefined4 *)(*(int *)(*(int *)(stateOutHome[2] + 0x310) + 4) + 0x40) = 0x100;
  return;
}

/* MiniFloat__decode @ 0xda78c (244 bytes) */
double MiniFloat__decode(uint encoded,double unusedFprArg)
{
  uint mantissaBits;
  uint exponentBits;
  double decoded;
  double scale;
  
  decoded = DOUBLE_001aa250;
  mantissaBits = encoded & 7;
  exponentBits = encoded >> 3 & 0xf;
  if (exponentBits == 0) {
    if (mantissaBits == 0) {
      decoded = (double)FLOAT_001aa1c0;
    }
    else {
      decoded = (double)((float)((double)CONCAT44(0x43300000,mantissaBits) - DOUBLE_001aa250) *
                       FLOAT_001aa170 * FLOAT_001aa1c4);
    }
  }
  else {
    scale = _pow(DOUBLE_001aa2a0,
                 (double)(float)((double)CONCAT44(0x43300000,exponentBits) - DOUBLE_001aa250) -
                 DOUBLE_001aa2a8[0]);
    decoded = (double)((float)((double)CONCAT44(0x43300000,mantissaBits) - decoded) * FLOAT_001aa170 *
                     (float)scale + (float)scale);
  }
  return decoded;
}

/* ildisInitContext @ 0xda8a8 (40 bytes) */
int ildisInitContext(disassembler)
  undefined4 *disassembler;
{
  disassembler[0x87] = 0;
  *disassembler = 0;
  disassembler[0x84] = 0;
  disassembler[0x85] = 0;
  disassembler[0x86] = 0;
  return _memset(disassembler + 4,0,0x200);
}

/* ildisSkipToken @ 0xda8d0 (16 bytes) */
int ildisSkipToken(disassembler)
  int disassembler;
{
  *(int *)(disassembler + 8) = *(int *)(disassembler + 8) + 4;
  return;
}

/* ildisSetIndent @ 0xda8e0 (20 bytes) */
int ildisSetIndent(disassembler, indent)
  int disassembler;
  int indent;
{
  if (indent < 0) {
    indent = 0;
  }
  *(int *)(disassembler + 0x21c) = indent;
  return;
}

/* returnZero_da8f4 @ 0xda8f4 (8 bytes) */
int returnZero_da8f4()
{
  return 0;
}

/* returnZero_da8fc @ 0xda8fc (8 bytes) */
int returnZero_da8fc()
{
  return 0;
}

/* ildisAppendf @ 0xda904 (128 bytes) */
int ildisAppendf(disassembler, format, fmtArgR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int disassembler;
  undefined4 format;
  undefined4 fmtArgR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  unsigned int ghidra_home[8] = { disassembler, format, fmtArgR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  uint currentLength;
  undefined1 auStack_224 [536];
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 8)) = fmtArgR5;
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = fmtArgR6;
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = fmtArgR7;
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = fmtArgR8;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = fmtArgR9;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = fmtArgR10;
  printf_LDBLStub_1a3428(auStack_224,0x200,format,&(*(unsigned int *)((unsigned char *)ghidra_home + 8)),fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  currentLength = _strlen(disassembler + 0x10);
  if (currentLength <= 0x1ff - currentLength) {
    _strcat(disassembler + 0x10,auStack_224);
  }
  return;
}

/* ildisFlushLine @ 0xda984 (120 bytes) */
int ildisFlushLine(disassembler, passThroughR4, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int disassembler;
  undefined4 passThroughR4;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  if (*(int *)(disassembler + 0x210) != 0) {
    ((int (*)())ildisAppendf)(disassembler,"\r\n",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    (*(code *)**(undefined4 **)(disassembler + 0x210))
              (*(undefined4 *)(disassembler + 0x214),"",disassembler + 0x10,0);
  }
  *(undefined1 *)(disassembler + 0x10) = 0;
  return;
}

/* ildisAppendIndentedf @ 0xda9fc (180 bytes) */
int ildisAppendIndentedf(disassembler, indentLevel, format, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int disassembler;
  int indentLevel;
  undefined4 format;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  unsigned int ghidra_home[8] = { disassembler, indentLevel, format, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  uint bufferLength;
  undefined4 unusedFormatCopy;
  int loopCounter;
  undefined1 lineBuffer [540];
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = fmtArgR6;
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = fmtArgR7;
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = fmtArgR8;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = fmtArgR9;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = fmtArgR10;
  if (0 < indentLevel) {
    loopCounter = 0;
    unusedFormatCopy = format;
    do {
      loopCounter = loopCounter + 1;
      ((int (*)())ildisAppendf)(disassembler,"    ",unusedFormatCopy,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    } while (indentLevel != loopCounter);
  }
  printf_LDBLStub_1a3428(lineBuffer,0x200,format,&(*(unsigned int *)((unsigned char *)ghidra_home + 12)),fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  bufferLength = _strlen(disassembler + 0x10);
  if (bufferLength <= 0x1ff - bufferLength) {
    _strcat(disassembler + 0x10,lineBuffer);
  }
  return;
}

/* ildisPrintNegateComponents @ 0xdaab0 (412 bytes) */
int ildisPrintNegateComponents(disassembler, negateWord, useRgbaLetters, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  undefined4 disassembler;
  uint negateWord;
  int useRgbaLetters;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  bool negateX;
  uint negateZ;
  uint negateY;
  uint negateW;
  char *componentText;
  int useRgbaLettersCopy;
  
  negateX = (negateWord >> 3 & 1) != 0;
  negateY = negateWord >> 7 & 1;
  negateZ = negateWord >> 0xb & 1;
  negateW = negateWord >> 0xf & 1;
  if ((((!negateX) && (negateY == 0)) && (negateZ == 0)) && (negateW == 0)) {
    return;
  }
  useRgbaLettersCopy = useRgbaLetters;
  ((int (*)())ildisAppendf)(disassembler,"_neg(",useRgbaLetters,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  if (negateX) {
    if (useRgbaLetters == 0) {
      componentText = "x";
    }
    else {
      componentText = "r";
    }
    ((int (*)())ildisAppendf)(disassembler,componentText,useRgbaLettersCopy,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  if (negateY != 0) {
    if (useRgbaLetters == 0) {
      componentText = "y";
    }
    else {
      componentText = "g";
    }
    ((int (*)())ildisAppendf)(disassembler,componentText,useRgbaLettersCopy,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  if (negateZ != 0) {
    if (useRgbaLetters == 0) {
      componentText = "z";
    }
    else {
      componentText = "b";
    }
    ((int (*)())ildisAppendf)(disassembler,componentText,useRgbaLettersCopy,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  if (negateW != 0) {
    if (useRgbaLetters == 0) {
      componentText = "w";
    }
    else {
      componentText = "a";
    }
    ((int (*)())ildisAppendf)(disassembler,componentText,useRgbaLettersCopy,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  ((int (*)())ildisAppendf)(disassembler,")",useRgbaLettersCopy,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return;
}

/* ildisComponentSelectChar @ 0xdac4c (204 bytes) */
int ildisComponentSelectChar(disassembler, componentSelect, useRgbaLetters, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int *disassembler;
  undefined4 componentSelect;
  int useRgbaLetters;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  undefined4 componentChar;
  
  switch(componentSelect) {
  case 0:
    componentChar = 0x78;
    if (useRgbaLetters != 0) {
      componentChar = 0x72;
    }
    break;
  case 1:
    componentChar = 0x79;
    if (useRgbaLetters != 0) {
      componentChar = 0x67;
    }
    break;
  case 2:
    componentChar = 0x7a;
    if (useRgbaLetters != 0) {
      componentChar = 0x62;
    }
    break;
  case 3:
    componentChar = 0x77;
    if (useRgbaLetters != 0) {
      componentChar = 0x61;
    }
    break;
  case 4:
    componentChar = 0x30;
    break;
  case 5:
    componentChar = 0x31;
    break;
  default:
    *disassembler = *disassembler + 1;
    ((int (*)())ildisAppendf)(disassembler,"!!!invalidCompSel!!!",useRgbaLetters,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    componentChar = 0;
  }
  return componentChar;
}

/* ildisPrintSwizzle @ 0xdad30 (300 bytes) */
int ildisPrintSwizzle(disassembler, swizzleWord, useRgbaLetters, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  undefined4 disassembler;
  uint swizzleWord;
  undefined4 useRgbaLetters;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  int swizzleChar3Value;
  int compareResult;
  char swizzleChar0;
  char swizzleChar1;
  char swizzleChar2;
  undefined1 swizzleChar3;
  undefined1 swizzleTerminator;
  
  swizzleChar0 = ((int (*)())ildisComponentSelectChar)(disassembler,swizzleWord & 7,useRgbaLetters,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  swizzleChar1 = ((int (*)())ildisComponentSelectChar)(disassembler,swizzleWord >> 4 & 7,useRgbaLetters,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  swizzleChar2 = ((int (*)())ildisComponentSelectChar)(disassembler,swizzleWord >> 8 & 7,useRgbaLetters,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  swizzleChar3Value = ((int (*)())ildisComponentSelectChar)(disassembler,swizzleWord >> 0xc & 7,useRgbaLetters,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  swizzleChar3 = (undefined1)swizzleChar3Value;
  swizzleTerminator = 0;
  compareResult = _strcmp(&swizzleChar0,"rgba");
  if ((compareResult != 0) && (compareResult = _strcmp(&swizzleChar0,"xyzw"), compareResult != 0)) {
    if ((((int)swizzleChar1 == (int)swizzleChar0) &&
        (((int)swizzleChar2 == (int)swizzleChar1 && (swizzleChar3Value == swizzleChar2)))) &&
       (((swizzleChar3Value - 0x61U & 0xff) < 0x1a || ((swizzleChar3Value - 0x41U & 0xff) < 0x1a)))) {
      swizzleChar1 = '\0';
    }
    ((int (*)())ildisAppendf)(disassembler,".",useRgbaLetters,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ((int (*)())ildisAppendf)(disassembler,&swizzleChar0,useRgbaLetters,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  return;
}

/* ildisPrintResultModifiers @ 0xdae5c (260 bytes) */
int ildisPrintResultModifiers(disassembler, resultModifierWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int *disassembler;
  uint resultModifierWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  int fmtArgR9;
  undefined4 fmtArgR10;
{
  uint shiftCode;
  char *suffixText;
  
  if ((resultModifierWord & 0x100) != 0) {
    ((int (*)())ildisAppendf)(disassembler,"_sat",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  if ((resultModifierWord & 0x1e00) == 0) {
    return;
  }
  shiftCode = resultModifierWord >> 9 & 0xf;
  if (shiftCode < 7) {
    fmtArgR9 = 0;
    switch(shiftCode) {
    case 0:
      goto switchD_000daebc_caseD_0;
    case 1:
      suffixText = "_x2";
      break;
    case 2:
      suffixText = "_x4";
      break;
    case 3:
      suffixText = "_x8";
      break;
    case 4:
      suffixText = "_d2";
      break;
    case 5:
      suffixText = "_d4";
      break;
    case 6:
      suffixText = "_d8";
    }
  }
  else {
switchD_000daebc_caseD_0:
    suffixText = "!!!invalidShift!!!";
    *disassembler = *disassembler + 1;
  }
  ((int (*)())ildisAppendf)(disassembler,suffixText,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return;
}

/* ildisPrintElementFormat @ 0xdaf7c (172 bytes) */
int ildisPrintElementFormat(disassembler, elementFormat, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9)
  int *disassembler;
  uint elementFormat;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
{
  int passThroughR9Zero;
  
  if (elementFormat < 8) {
    passThroughR9Zero = 0;
    switch(elementFormat) {
    case 0:
      ((int (*)())ildisAppendf)(disassembler,"unknown",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,passThroughR9Zero,0xdaf88);
      return;
    case 1:
      ((int (*)())ildisAppendf)(disassembler,"snorm",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,passThroughR9Zero,0xdaf88);
      return;
    case 2:
      ((int (*)())ildisAppendf)(disassembler,"unorm",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,passThroughR9Zero,0xdaf88);
      return;
    case 3:
      ((int (*)())ildisAppendf)(disassembler,"sint",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,passThroughR9Zero,0xdaf88);
      return;
    case 4:
      ((int (*)())ildisAppendf)(disassembler,"uint",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,passThroughR9Zero,0xdaf88);
      return;
    case 5:
      ((int (*)())ildisAppendf)(disassembler,"float",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,passThroughR9Zero,0xdaf88);
      return;
    case 6:
      ((int (*)())ildisAppendf)(disassembler,"srgb",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,passThroughR9Zero,0xdaf88);
      return;
    case 7:
      ((int (*)())ildisAppendf)(disassembler,"mixed",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,passThroughR9Zero,0xdaf88);
      return;
    }
  }
  *disassembler = *disassembler + 1;
  ((int (*)())ildisAppendf)(disassembler,"!!!invalidElemFormat!!!",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdaf88);
  return;
}

/* ildisPrintFormatXyzw @ 0xdb048 (224 bytes) */
int ildisPrintFormatXyzw(disassembler, passThroughR4, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int disassembler;
  undefined4 passThroughR4;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  uint formatWord;
  
  formatWord = **(uint **)(disassembler + 8);
  *(uint **)(disassembler + 8) = *(uint **)(disassembler + 8) + 1;
  ((int (*)())ildisAppendf)(disassembler,"_fmtx(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintElementFormat)(disassembler,formatWord >> 0x14 & 7,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ((int (*)())ildisAppendf)(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisAppendf)(disassembler,"_fmty(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintElementFormat)(disassembler,formatWord >> 0x17 & 7,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ((int (*)())ildisAppendf)(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisAppendf)(disassembler,"_fmtz(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintElementFormat)(disassembler,formatWord >> 0x1a & 7,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ((int (*)())ildisAppendf)(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisAppendf)(disassembler,"_fmtw(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintElementFormat)(disassembler,formatWord >> 0x1d,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ((int (*)())ildisAppendf)(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return;
}

/* ildisModComponentChar @ 0xdb128 (156 bytes) */
int ildisModComponentChar(disassembler, modComponentSelect, defaultComponentText, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int *disassembler;
  int modComponentSelect;
  char *defaultComponentText;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  int resultChar;
  
  resultChar = 0;
  if (defaultComponentText != (char *)0x0) {
    if (modComponentSelect == 1) {
      resultChar = (int)*defaultComponentText;
    }
    else {
      if (modComponentSelect < 2) {
        if (modComponentSelect == 0) {
          return 0x5f;
        }
      }
      else {
        if (modComponentSelect == 2) {
          return 0x30;
        }
        if (modComponentSelect == 3) {
          return 0x31;
        }
      }
      *disassembler = *disassembler + 1;
      ((int (*)())ildisAppendf)(disassembler,"!!!invalidModComp!!!",defaultComponentText,fmtArgR6,fmtArgR7,fmtArgR8,disassembler,fmtArgR10);
      resultChar = 0x20;
    }
  }
  return resultChar;
}

/* ildisPrintDestinationWriteMask @ 0xdb1c4 (304 bytes) */
int ildisPrintDestinationWriteMask(disassembler, modifierWord, useRgbaLetters, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  undefined4 disassembler;
  uint modifierWord;
  int useRgbaLetters;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  bool useRgbaLettersFlag;
  char *defaultComponentText;
  int charIndex;
  char modifierChars [36];
  
  if ((modifierWord & 0xff) != 0x55) {
    useRgbaLettersFlag = useRgbaLetters != 0;
    if (useRgbaLettersFlag) {
      defaultComponentText = "r";
    }
    else {
      defaultComponentText = "x";
    }
    modifierChars[0] = ((int (*)())ildisModComponentChar)(disassembler,modifierWord & 3,defaultComponentText,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    if (useRgbaLettersFlag) {
      defaultComponentText = "g";
    }
    else {
      defaultComponentText = "y";
    }
    modifierChars[1] = ((int (*)())ildisModComponentChar)(disassembler,modifierWord >> 2 & 3,defaultComponentText,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,
                               fmtArgR10);
    if (useRgbaLettersFlag) {
      defaultComponentText = "b";
    }
    else {
      defaultComponentText = "z";
    }
    modifierChars[2] = ((int (*)())ildisModComponentChar)(disassembler,modifierWord >> 4 & 3,defaultComponentText,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,
                               fmtArgR10);
    if (useRgbaLettersFlag) {
      defaultComponentText = "a";
    }
    else {
      defaultComponentText = "w";
    }
    modifierChars[3] = ((int (*)())ildisModComponentChar)(disassembler,modifierWord >> 6 & 3,defaultComponentText,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,
                               fmtArgR10);
    ((int (*)())ildisAppendf)(disassembler,".",defaultComponentText,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    charIndex = 0;
    do {
      ((int (*)())ildisAppendf)(disassembler,"%c",(int)modifierChars[charIndex],fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      useRgbaLettersFlag = charIndex != 3;
      charIndex = charIndex + 1;
    } while (useRgbaLettersFlag);
  }
  return;
}

/* ildisPrintUnsigned @ 0xdb2f4 (92 bytes) */
int ildisPrintUnsigned(disassembler, passThroughR4, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int disassembler;
  undefined4 passThroughR4;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  undefined4 value;
  undefined1 textBuffer [76];
  
  value = **(undefined4 **)(disassembler + 8);
  *(undefined4 **)(disassembler + 8) = *(undefined4 **)(disassembler + 8) + 1;
  printf_LDBLStub_1a32d0(textBuffer,"%lu",value,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return ((int (*)())ildisAppendf)(disassembler,textBuffer,value,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
}

/* ildisPrintCmpVal @ 0xdb350 (244 bytes) */
int ildisPrintCmpVal(disassembler, cmpValWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int *disassembler;
  uint cmpValWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  int fmtArgR9;
  undefined4 fmtArgR10;
{
  uint cmpValCode;
  
  ((int (*)())ildisAppendf)(disassembler,"_cmpval(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  cmpValCode = cmpValWord >> 0x16 & 7;
  if (cmpValCode < 5) {
    fmtArgR9 = 0;
    switch(cmpValCode) {
    case 0:
      ((int (*)())ildisAppendf)(disassembler,"0.0",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 1:
      ((int (*)())ildisAppendf)(disassembler,"0.5",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 2:
      ((int (*)())ildisAppendf)(disassembler,"1.0",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 3:
      ((int (*)())ildisAppendf)(disassembler,"-0.5",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 4:
      ((int (*)())ildisAppendf)(disassembler,"-1.0",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    }
  }
  else {
    *disassembler = *disassembler + 1;
    ((int (*)())ildisAppendf)(disassembler,"!!!invalidCmpVal!!!",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  ((int (*)())ildisAppendf)(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return;
}

/* ildisPrintUsage @ 0xdb458 (260 bytes) */
int ildisPrintUsage(disassembler, usageCode, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int *disassembler;
  uint usageCode;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  int fmtArgR9;
  undefined4 fmtArgR10;
{
  ((int (*)())ildisAppendf)(disassembler,"_usage(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  if (usageCode < 6) {
    fmtArgR9 = 0;
    switch(usageCode) {
    case 0:
      ((int (*)())ildisAppendf)(disassembler,"pos",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 1:
      ((int (*)())ildisAppendf)(disassembler,"pointsize",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 2:
      ((int (*)())ildisAppendf)(disassembler,"color",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 3:
      ((int (*)())ildisAppendf)(disassembler,"backcolor",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 4:
      ((int (*)())ildisAppendf)(disassembler,"fog",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 5:
      ((int (*)())ildisAppendf)(disassembler,"generic",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    }
  }
  else {
    *disassembler = *disassembler + 1;
    ((int (*)())ildisAppendf)(disassembler,"!!!invalid!!!",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  ((int (*)())ildisAppendf)(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return;
}

/* ildisPrintFixedPoint @ 0xdb574 (352 bytes) */
void ildisPrintFixedPoint(undefined4 disassembler,uint fieldBits,uint integerBits,uint fractionBits,double staleFprArg1,double staleFprArg2,double staleFprArg3,double staleFprArg4,double staleFprArg5,double staleFprArg6,double staleFprArg7,double staleFprArg8,double staleFprArg9,double staleFprArg10,double staleFprArg11,double staleFprArg12)
{
  uint loopCounterB;
  float integerPart;
  uint fractionBitIndex;
  int integerBitsLeft;
  uint loopCounter;
  undefined1 *textBufferPtr;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  uint uVar6;
  undefined4 staleArgR10;
  uint bitIndex;
  undefined1 textBuffer [256];
  undefined4 intToDoubleHi;
  int fractionScale;
  undefined4 intToDoubleHi2;
  uint integerField;
  undefined4 intToDoubleHi3;
  uint fractionField;
  
  fractionScale = 1 << (fractionBits & 0x3f);
  intToDoubleHi = 0x43300000;
  integerField = 0;
  if (1 < integerBits) {
    integerBitsLeft = integerBits - 1;
    integerField = 0;
    if (integerBitsLeft != 0) {
      loopCounterB = 0;
      integerField = 0;
      do {
        bitIndex = loopCounterB & 0x3f;
        loopCounterB = loopCounterB + 1;
        integerField = integerField | 1 << bitIndex;
        integerBitsLeft = integerBitsLeft + -1;
      } while (integerBitsLeft != 0);
      integerField = integerField << (fractionBits & 0x3f);
    }
    integerField = fieldBits & integerField;
  }
  intToDoubleHi2 = 0x43300000;
  integerField = integerField >> (fractionBits & 0x3f);
  integerPart = (float)((double)CONCAT44(0x43300000,integerField) - DOUBLE_001aa250);
  if ((fieldBits & 1 << ((fractionBits + integerBits) - 1 & 0x3f)) != 0) {
    integerPart = FLOAT_001aa114 - integerPart;
  }
  fractionField = 0;
  uVar6 = integerField;
  if (fractionBits != 0) {
    loopCounter = 0;
    uVar6 = 0;
    bitIndex = fractionBits;
    do {
      fractionBitIndex = loopCounter & 0x3f;
      loopCounter = loopCounter + 1;
      uVar6 = uVar6 | 1 << fractionBitIndex;
      bitIndex = bitIndex - 1;
    } while (bitIndex != 0);
    fractionField = uVar6 & fieldBits;
  }
  intToDoubleHi3 = 0x43300000;
  textBufferPtr = textBuffer;
  ((char * (*)())FUN_000cdc3c)(disassembler,10,textBufferPtr,
               (double)((float)(DOUBLE_001aa200 /
                               ((double)CONCAT44(0x43300000,fractionScale) - DOUBLE_001aa250)) *
                        (float)((double)CONCAT44(0x43300000,fractionField) - DOUBLE_001aa250) + integerPart));
  ((int (*)())ildisAppendf)(disassembler,textBuffer,textBufferPtr,fractionBits,staleArgR7,staleArgR8,uVar6,staleArgR10);
  return;
}

/* ildisPrintTexelOffsets @ 0xdb6d4 (196 bytes) */
int ildisPrintTexelOffsets(disassembler, offsetsWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  undefined4 disassembler;
  uint offsetsWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  undefined4 integerBitsArg;
  undefined4 fractionBitsArg;
  double printResult;
  double staleFpr2;
  double staleFpr3;
  double staleFpr4;
  double staleFpr5;
  double staleFpr6;
  double staleFpr7;
  double staleFpr8;
  double staleStackArg_ffffffa8;
  double staleStackArg_ffffffb0;
  double staleStackArg_ffffffb8;
  double staleStackArg_ffffffc0;
  
  printResult = (double)((int (*)())ildisAppendf)(disassembler,"_xoffset(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  integerBitsArg = 7;
  fractionBitsArg = 1;
  ((void (*)())ildisPrintFixedPoint)(disassembler,offsetsWord & 0xff,7,1,printResult,staleFpr2,staleFpr3,staleFpr4,staleFpr5,staleFpr6,staleFpr7,staleFpr8,
               staleStackArg_ffffffa8,staleStackArg_ffffffb0,staleStackArg_ffffffb8,staleStackArg_ffffffc0);
  ((int (*)())ildisAppendf)(disassembler,")",integerBitsArg,fractionBitsArg,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  printResult = (double)((int (*)())ildisAppendf)(disassembler,"_yoffset(",integerBitsArg,fractionBitsArg,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  integerBitsArg = 7;
  fractionBitsArg = 1;
  ((void (*)())ildisPrintFixedPoint)(disassembler,offsetsWord >> 8 & 0xff,7,1,printResult,staleFpr2,staleFpr3,staleFpr4,staleFpr5,staleFpr6,staleFpr7,staleFpr8,
               staleStackArg_ffffffa8,staleStackArg_ffffffb0,staleStackArg_ffffffb8,staleStackArg_ffffffc0);
  ((int (*)())ildisAppendf)(disassembler,")",integerBitsArg,fractionBitsArg,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  printResult = (double)((int (*)())ildisAppendf)(disassembler,"_zoffset(",integerBitsArg,fractionBitsArg,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  integerBitsArg = 7;
  fractionBitsArg = 1;
  ((void (*)())ildisPrintFixedPoint)(disassembler,offsetsWord >> 0x10 & 0xff,7,1,printResult,staleFpr2,staleFpr3,staleFpr4,staleFpr5,staleFpr6,staleFpr7,staleFpr8,
               staleStackArg_ffffffa8,staleStackArg_ffffffb0,staleStackArg_ffffffb8,staleStackArg_ffffffc0);
  ((int (*)())ildisAppendf)(disassembler,")",integerBitsArg,fractionBitsArg,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return;
}

/* ildisPrintSignedField @ 0xdb798 (132 bytes) */
int ildisPrintSignedField(disassembler, fieldValue, fieldWidth, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  undefined4 disassembler;
  uint fieldValue;
  uint fieldWidth;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  uint fieldMask;
  uint signBit;
  uint magnitude;
  undefined1 textBuffer [268];
  
  fieldMask = (1 << (fieldWidth & 0x3f)) - 1;
  magnitude = fieldMask & fieldValue;
  signBit = magnitude & 1 << (fieldWidth - 1 & 0x3f);
  if (signBit != 0) {
    magnitude = (fieldMask & ~magnitude) + 1;
    ((int (*)())ildisAppendf)(disassembler,"-",fieldWidth - 1,fmtArgR6,fmtArgR7,fmtArgR8,signBit,fmtArgR10);
  }
  printf_LDBLStub_1a32d0(textBuffer,"%lu",magnitude,fmtArgR6,fmtArgR7,fmtArgR8,signBit,fmtArgR10);
  return ((int (*)())ildisAppendf)(disassembler,textBuffer,magnitude,fmtArgR6,fmtArgR7,fmtArgR8,signBit,fmtArgR10);
}

/* ildisPrintAddressOffsetImmediate @ 0xdb81c (196 bytes) */
int ildisPrintAddressOffsetImmediate(disassembler, controlWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int disassembler;
  uint controlWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  undefined4 fieldWidthArg;
  uint offsetsWord;
  
  if ((controlWord & 0x20000000) != 0) {
    ((int (*)())ildisAppendf)(disassembler,"_aoffimmi(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    fieldWidthArg = 4;
    offsetsWord = **(uint **)(disassembler + 8);
    *(uint **)(disassembler + 8) = *(uint **)(disassembler + 8) + 1;
    ((int (*)())ildisPrintSignedField)(disassembler,offsetsWord & 0xf,4,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ((int (*)())ildisAppendf)(disassembler,",",fieldWidthArg,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    fieldWidthArg = 4;
    ((int (*)())ildisPrintSignedField)(disassembler,offsetsWord >> 4 & 0xf,4,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ((int (*)())ildisAppendf)(disassembler,",",fieldWidthArg,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    fieldWidthArg = 4;
    ((int (*)())ildisPrintSignedField)(disassembler,offsetsWord >> 8 & 0xf,4,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    ((int (*)())ildisAppendf)(disassembler,")",fieldWidthArg,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    return;
  }
  return;
}

/* ildisPrintResourceSampler @ 0xdb8e0 (88 bytes) */
int ildisPrintResourceSampler(disassembler, resourceSamplerWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  undefined4 disassembler;
  uint resourceSamplerWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  uint resourceIndex;
  uint samplerIndex;
  undefined1 textBuffer [268];
  
  samplerIndex = resourceSamplerWord >> 0x18 & 0x1f;
  resourceIndex = resourceSamplerWord >> 0x10 & 0xff;
  printf_LDBLStub_1a32d0(textBuffer,"_resource(%d)_sampler(%d)",resourceIndex,samplerIndex,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return ((int (*)())ildisAppendf)(disassembler,textBuffer,resourceIndex,samplerIndex,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
}

/* ildisPrintAnisoMode @ 0xdb938 (280 bytes) */
int ildisPrintAnisoMode(disassembler, anisoCode, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int *disassembler;
  uint anisoCode;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  int fmtArgR9;
  undefined4 fmtArgR10;
{
  ((int (*)())ildisAppendf)(disassembler,"_aniso(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  if (anisoCode < 7) {
    fmtArgR9 = 0;
    switch(anisoCode) {
    case 0:
      ((int (*)())ildisAppendf)(disassembler,"unknown",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 1:
      ((int (*)())ildisAppendf)(disassembler,"disabled",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 2:
      ((int (*)())ildisAppendf)(disassembler,"1",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 3:
      ((int (*)())ildisAppendf)(disassembler,"2",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 4:
      ((int (*)())ildisAppendf)(disassembler,"4",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 5:
      ((int (*)())ildisAppendf)(disassembler,"8",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
      break;
    case 6:
      ((int (*)())ildisAppendf)(disassembler,"16",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    }
  }
  else {
    *disassembler = *disassembler + 1;
    ((int (*)())ildisAppendf)(disassembler,"!!invalid!!",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  ((int (*)())ildisAppendf)(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return;
}

/* ildisPrintMipFilter @ 0xdba6c (216 bytes) */
int ildisPrintMipFilter(disassembler, mipFilterCode, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  int *disassembler;
  int mipFilterCode;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  ((int (*)())ildisAppendf)(disassembler,"_mip(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  if (mipFilterCode == 1) {
    ((int (*)())ildisAppendf)(disassembler,"point",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  else if (mipFilterCode == 0) {
    ((int (*)())ildisAppendf)(disassembler,"unknown",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  else if (mipFilterCode == 2) {
    ((int (*)())ildisAppendf)(disassembler,"linear",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  else if (mipFilterCode == 3) {
    ((int (*)())ildisAppendf)(disassembler,"base",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  else {
    *disassembler = *disassembler + 1;
    ((int (*)())ildisAppendf)(disassembler,"!!invalid!!",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  }
  ((int (*)())ildisAppendf)(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return;
}

/* ildisPrintFilterName @ 0xdbb44 (124 bytes) */
int ildisPrintFilterName(disassembler, filterCode, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9)
  int *disassembler;
  int filterCode;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
{
  if (filterCode == 1) {
    ((int (*)())ildisAppendf)(disassembler,"point",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdbb50);
    return;
  }
  if (filterCode == 0) {
    ((int (*)())ildisAppendf)(disassembler,"unknown",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdbb50);
    return;
  }
  if (filterCode == 2) {
    ((int (*)())ildisAppendf)(disassembler,"linear",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdbb50);
    return;
  }
  if (filterCode == 3) {
    ((int (*)())ildisAppendf)(disassembler,"aniso",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdbb50);
    return;
  }
  *disassembler = *disassembler + 1;
  return ((int (*)())ildisAppendf)(disassembler,"!!invalid!!",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,0xdbb50);
}

/* ildisPrintFilterModes @ 0xdbbc0 (284 bytes) */
int ildisPrintFilterModes(disassembler, filterWord, passThroughR5, fmtArgR6, fmtArgR7, fmtArgR8, fmtArgR9, fmtArgR10)
  undefined4 disassembler;
  uint filterWord;
  undefined4 passThroughR5;
  undefined4 fmtArgR6;
  undefined4 fmtArgR7;
  undefined4 fmtArgR8;
  undefined4 fmtArgR9;
  undefined4 fmtArgR10;
{
  undefined4 integerBitsArg;
  undefined4 fractionBitsArg;
  double staleFprArg1;
  double staleFpr2;
  double staleFpr3;
  double staleFpr4;
  double staleFpr5;
  double staleFpr6;
  double staleFpr7;
  double staleFpr8;
  double staleStackArg_ffffffa8;
  double staleStackArg_ffffffb0;
  double staleStackArg_ffffffb8;
  double staleStackArg_ffffffc0;
  
  ((int (*)())ildisAppendf)(disassembler,"_mag(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintFilterName)(disassembler,filterWord & 7,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ((int (*)())ildisAppendf)(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisAppendf)(disassembler,"_min(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintFilterName)(disassembler,filterWord >> 3 & 7,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ((int (*)())ildisAppendf)(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisAppendf)(disassembler,"_volmag(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintFilterName)(disassembler,filterWord >> 6 & 7,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ((int (*)())ildisAppendf)(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisAppendf)(disassembler,"_volmin(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintFilterName)(disassembler,filterWord >> 9 & 7,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9);
  ((int (*)())ildisAppendf)(disassembler,")",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintMipFilter)(disassembler,filterWord >> 0xc & 7,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  ((int (*)())ildisPrintAnisoMode)(disassembler,filterWord >> 0xf & 7,passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  staleFprArg1 = (double)((int (*)())ildisAppendf)(disassembler,"_lodbias(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,
                                  fmtArgR10);
  integerBitsArg = 3;
  fractionBitsArg = 4;
  ((void (*)())ildisPrintFixedPoint)(disassembler,filterWord >> 0x12 & 0x7f,3,4,staleFprArg1,staleFpr2,staleFpr3,staleFpr4,staleFpr5,staleFpr6,staleFpr7,staleFpr8
               ,staleStackArg_ffffffa8,staleStackArg_ffffffb0,staleStackArg_ffffffb8,staleStackArg_ffffffc0);
  ((int (*)())ildisAppendf)(disassembler,")",integerBitsArg,fractionBitsArg,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return;
}

