#include "decls.h"

/* scDumpPixelProgramPsn @ 0xd4e08 (92 bytes) */
int scDumpPixelProgramPsn(sinkRecord, shaderState, optionsArg, argR6, argR7, argR8, param_7, argR10)
  undefined4 *sinkRecord;
  int shaderState;
  undefined4 optionsArg;
  undefined4 argR6;
  undefined4 argR7;
  undefined4 argR8;
  undefined4 param_7;
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
  undefined4 in_r10;
  undefined4 sinkFnField;
  undefined4 sinkContextField;
  
  sinkFnCopy = sinkFn;
  psnClearSinkRecord2(&sinkFnField);
  sinkFnField = sinkFn;
  sinkContextField = sinkContext;
  ((int (*)())scDumpPixelProgramPsn)(&sinkFnField,shaderState,optionsArg,sinkFnCopy,argR7,argR8,param_7,in_r10);
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

/* FUN_000d5390 @ 0xd5390 (548 bytes) */
int FUN_000d5390(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  uint *param_2;
  int param_3;
  int param_4;
  uint param_5;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint loopCounter;
  
  uVar3 = 0x170000;
  if (param_3 == 0) {
    uVar4 = param_4 + (uint)(byte)((unsigned char *)0x000013b2)[param_1] & 0xffff | 0x40000;
  }
  else {
    uVar4 = 0x120000;
  }
  loopCounter = 0;
  do {
    if ((1 << (loopCounter & 0x3f) & param_5) != 0) {
      uVar2 = *param_2;
      uVar3 = loopCounter & 0xffff | uVar3 & 0xffff0000;
      if (param_2[1] <= uVar2) {
        uVar2 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if (param_2[2] != 0) {
          _memcpy(uVar2,param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = uVar2;
        uVar2 = *param_2;
        param_2[1] = param_2[1] + 0x80;
      }
      *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0xe;
      uVar2 = *param_2 + 1;
      *param_2 = uVar2;
      if (param_2[1] <= uVar2) {
        uVar2 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if (param_2[2] != 0) {
          _memcpy(uVar2,param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = uVar2;
        uVar2 = *param_2;
        param_2[1] = param_2[1] + 0x80;
      }
      *(uint *)(uVar2 * 4 + param_2[2]) = uVar3;
      uVar2 = *param_2 + 1;
      *param_2 = uVar2;
      if (param_2[1] <= uVar2) {
        uVar2 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
        if (param_2[2] != 0) {
          _memcpy(uVar2,param_2[2],*param_2 << 2);
          (**(code **)(param_1 + 0x18))(param_2[2]);
        }
        param_2[2] = uVar2;
        uVar2 = *param_2;
        param_2[1] = param_2[1] + 0x80;
      }
      *(uint *)(uVar2 * 4 + param_2[2]) = uVar4;
      *param_2 = *param_2 + 1;
    }
    bVar1 = loopCounter != 3;
    loopCounter = loopCounter + 1;
  } while (bVar1);
  return;
}

/* FUN_000d55c0 @ 0xd55c0 (832 bytes) */
int FUN_000d55c0(param_1, param_2, param_3, param_4)
  int param_1;
  uint *param_2;
  int param_3;
  undefined4 param_4;
{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_2;
  if (param_2[1] <= uVar2) {
    uVar2 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if (param_2[2] != 0) {
      _memcpy(uVar2,param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = uVar2;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 3;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  bVar1 = ((unsigned char *)0x000013b2)[param_1];
  if (param_2[1] <= uVar2) {
    uVar2 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if (param_2[2] != 0) {
      _memcpy(uVar2,param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = uVar2;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar2 * 4 + param_2[2]) = (int)(*(unsigned short *)((unsigned char *)&(param_4) + 2)) + (uint)bVar1 & 0xffff | 0x40000;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_3 == 0) {
    uVar3 = (int)(*(unsigned short *)((unsigned char *)&(param_4) + 2)) + (uint)(byte)((unsigned char *)0x000013b2)[param_1] & 0xffff | 0x40000;
  }
  else {
    uVar3 = 0x120000;
  }
  if (param_2[1] <= uVar2) {
    uVar2 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if (param_2[2] != 0) {
      _memcpy(uVar2,param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = uVar2;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(uint *)(uVar2 * 4 + param_2[2]) = uVar3;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    uVar2 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if (param_2[2] != 0) {
      _memcpy(uVar2,param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = uVar2;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined4 *)(uVar2 * 4 + param_2[2]) = 0x530000;
  uVar2 = *param_2 + 1;
  *param_2 = uVar2;
  if (param_2[1] <= uVar2) {
    uVar2 = (**(code **)(param_1 + 0xc))(param_2[1] * 4 + 0x200);
    if (param_2[2] != 0) {
      _memcpy(uVar2,param_2[2],*param_2 << 2);
      (**(code **)(param_1 + 0x18))(param_2[2]);
    }
    param_2[2] = uVar2;
    uVar2 = *param_2;
    param_2[1] = param_2[1] + 0x80;
  }
  *(undefined **)(uVar2 * 4 + param_2[2]) = ((unsigned char *)0x00004210);
  *param_2 = *param_2 + 1;
  return;
}

/* ffpsEmitDeclarations @ 0xd5900 (2612 bytes) */
int ffpsEmitDeclarations(ctx, ilBuilder)
  int ctx;
  int ilBuilder;
{
  bool bVar1;
  undefined4 newTokenBuffer;
  uint tokenIndex;
  uint uVar4;
  uint loopCounter;
  int iVar6;
  uint loopIndex;
  uint *puVar8;
  
  puVar8 = (uint *)(ilBuilder + 4);
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
  *(undefined4 *)(*puVar8 * 4 + *(int *)(ilBuilder + 0xc)) = 0x1ff0016;
  tokenIndex = *puVar8 + 1;
  *puVar8 = tokenIndex;
  if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
    newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
    if (*(int *)(ilBuilder + 0xc) != 0) {
      _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*puVar8 << 2);
      (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
    }
    *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
    tokenIndex = *puVar8;
    *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
  }
  *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x120000;
  tokenIndex = *puVar8 + 1;
  *puVar8 = tokenIndex;
  if (((*(uint *)(ctx + 0x44) & 0xa00000) != 0) ||
     (((int)*(uint *)(ctx + 0x44) < 0 && (*(short *)(((unsigned char *)0x00002d48) + iVar6) == -0x7e06)))) {
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*puVar8 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *puVar8;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x1ff0016;
    tokenIndex = *puVar8 + 1;
    *puVar8 = tokenIndex;
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*puVar8 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *puVar8;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x130000;
    tokenIndex = *puVar8 + 1;
    *puVar8 = tokenIndex;
  }
  uVar4 = (uint)(byte)((unsigned char *)0x000013b2)[ctx];
  bVar1 = false;
  if (uVar4 != 0) {
    loopIndex = 0;
    loopCounter = 0x80000;
    iVar6 = ctx;
    do {
      if (((*(uint *)(ctx + 0x44) & 0x100000) != 0) &&
         (*(char *)(loopIndex + *(int *)(((unsigned char *)0x00001168) + ctx) + 0x71) == '\0')) {
        bVar1 = true;
      }
      if (*(int *)(((unsigned char *)0x000013f8) + iVar6) != 0) {
        if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
          newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
          if (*(int *)(ilBuilder + 0xc) != 0) {
            _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*puVar8 << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
          }
          *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
          tokenIndex = *puVar8;
          *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
        }
        *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x1ff0016;
        tokenIndex = *puVar8 + 1;
        *puVar8 = tokenIndex;
        if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
          newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
          if (*(int *)(ilBuilder + 0xc) != 0) {
            _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*puVar8 << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
          }
          *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
          tokenIndex = *puVar8;
          *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
        }
        *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = loopIndex & 0xffff | 0x110000;
        tokenIndex = *puVar8 + 1;
        *puVar8 = tokenIndex;
        if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
          newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
          if (*(int *)(ilBuilder + 0xc) != 0) {
            _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*puVar8 << 2);
            (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
          }
          *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
          tokenIndex = *puVar8;
          *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
        }
        *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = loopIndex << 0x10 | 0x19;
        tokenIndex = *puVar8 + 1;
        *puVar8 = tokenIndex;
        if (((int)(uint)*(byte *)(ctx + 0x20) >> (loopIndex & 0x3f) & 1U) == 0) {
          uVar4 = (uint)(byte)((unsigned char *)0x000013b2)[ctx];
        }
        else {
          if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
            newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
            if (*(int *)(ilBuilder + 0xc) != 0) {
              _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*puVar8 << 2);
              (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
            }
            *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
            tokenIndex = *puVar8;
            *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
          }
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = loopCounter | 0x19;
          tokenIndex = *puVar8 + 1;
          *puVar8 = tokenIndex;
          uVar4 = (uint)(byte)((unsigned char *)0x000013b2)[ctx];
        }
      }
      loopIndex = loopIndex + 1;
      loopCounter = loopCounter + 0x10000;
      iVar6 = iVar6 + 4;
    } while ((int)loopIndex < (int)uVar4);
  }
  if (*(char *)(ctx + 0x121) != '\0') {
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*puVar8 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *puVar8;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x1ff0016;
    tokenIndex = *puVar8 + 1;
    *puVar8 = tokenIndex;
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*puVar8 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *puVar8;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x100000;
    tokenIndex = *puVar8 + 1;
    *puVar8 = tokenIndex;
  }
  if (bVar1) {
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*puVar8 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *puVar8;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x1c;
    tokenIndex = *puVar8 + 1;
    *puVar8 = tokenIndex;
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*puVar8 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *puVar8;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x10011;
    tokenIndex = *puVar8 + 1;
    *puVar8 = tokenIndex;
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*puVar8 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *puVar8;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0;
    tokenIndex = *puVar8 + 1;
    *puVar8 = tokenIndex;
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*puVar8 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *puVar8;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0;
    tokenIndex = *puVar8 + 1;
    *puVar8 = tokenIndex;
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*puVar8 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *puVar8;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0;
    tokenIndex = *puVar8 + 1;
    *puVar8 = tokenIndex;
    if (*(uint *)(ilBuilder + 8) <= tokenIndex) {
      newTokenBuffer = (**(code **)(ctx + 0xc))(*(uint *)(ilBuilder + 8) * 4 + 0x200);
      if (*(int *)(ilBuilder + 0xc) != 0) {
        _memcpy(newTokenBuffer,*(int *)(ilBuilder + 0xc),*puVar8 << 2);
        (**(code **)(ctx + 0x18))(*(undefined4 *)(ilBuilder + 0xc));
      }
      *(undefined4 *)(ilBuilder + 0xc) = newTokenBuffer;
      tokenIndex = *puVar8;
      *(int *)(ilBuilder + 8) = *(int *)(ilBuilder + 8) + 0x80;
    }
    *(undefined4 *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = 0x3f800000;
    *puVar8 = *puVar8 + 1;
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
  int loopCounter;
  uint tokenIndex;
  bool bVar1;
  byte textureUnitCount;
  float rgbScale;
  ushort uVar4;
  int iVar5;
  int unitState;
  undefined4 newTokenBuffer;
  uint uVar8;
  int iVar9;
  int argCount;
  undefined4 ilOpcode;
  int *piVar12;
  undefined4 dstWriteWord;
  uint uVar14;
  uint *countPtr;
  uint srcTokens [2];
  undefined1 srcToken2 [4];
  uint srcSwizzles [2];
  undefined1 srcSwizzle2 [4];
  uint local_80 [2];
  undefined1 auStack_78 [4];
  uint local_74;
  uint local_70;
  undefined1 auStack_6c [4];
  int argOrder [4];
  uint *local_58;
  
  unitState = 0;
  local_58 = &local_74;
  do {
    *(undefined4 *)(unitState + (int)srcTokens) = 0;
    *(undefined4 *)(unitState + (int)srcSwizzles) = 0;
    bVar1 = unitState != 8;
    *(undefined4 *)(unitState + (int)local_80) = 0;
    *(undefined4 *)(unitState + (int)local_58) = 0;
    unitState = unitState + 4;
  } while (bVar1);
  unitState = unit * 0xcc + ctx;
  countPtr = (uint *)(ilBuilder + 4);
  ilOpcode = 0;
  ((int (*)())ffpsBuildRgbSourceOperand)(ctx,(uint)*(ushort *)(unitState + 0x456),(uint)*(ushort *)(unitState + 0x462),srcTokens,
               srcSwizzles,unit,baseFormat,isFirstUnit,previousUnit);
  ((int (*)())ffpsBuildRgbSourceOperand)(ctx,(uint)*(ushort *)(unitState + 0x458),(uint)*(ushort *)(unitState + 0x464),
               srcTokens + 1,srcSwizzles + 1,unit,baseFormat,isFirstUnit,previousUnit);
  ((int (*)())ffpsBuildRgbSourceOperand)(ctx,(uint)*(ushort *)(unitState + 0x45a),(uint)*(ushort *)(unitState + 0x466),srcToken2,
               srcSwizzle2,unit,baseFormat,isFirstUnit,previousUnit);
  uVar8 = (uint)*(ushort *)(unitState + 0x454);
  rgbScale = *(float *)(unitState + 0x474);
  if (uVar8 < 0x86b0) {
    if (uVar8 < 0x86ae) {
      if (uVar8 == 0x2100) {
        ilOpcode = 0x49;
LAB_000d6560:
        argCount = 2;
        argOrder[0] = 0;
        iVar9 = uVar8 - 0x10000;
        argOrder[1] = 1;
      }
      else if (uVar8 < 0x2101) {
        if (uVar8 == 0x104) {
          ilOpcode = 3;
          goto LAB_000d6560;
        }
        if (uVar8 != 0x1e01) goto LAB_000d6534;
        argCount = 1;
        argOrder[0] = 0;
        iVar9 = -0xe1ff;
        ilOpcode = 0x47;
      }
      else if (uVar8 == 0x8574) {
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
      else if (uVar8 == 0x8575) {
        argOrder[1] = 0;
        argCount = 3;
        ilOpcode = 0x3f;
        iVar9 = -0x7a8b;
        argOrder[2] = 1;
        argOrder[0] = 2;
      }
      else {
        if (uVar8 != 0x84e7) goto LAB_000d6534;
        argCount = 2;
        argOrder[0] = 0;
        iVar9 = -0x7b19;
        ilOpcode = 0x5b;
        argOrder[1] = 1;
      }
    }
    else {
LAB_000d64e8:
      iVar9 = uVar8 - 0x10000;
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
  else if (uVar8 == 0x8744) {
    argOrder[0] = 0;
    argCount = 3;
    ilOpcode = 0x40;
    iVar9 = -0x78bc;
    argOrder[2] = 1;
    argOrder[1] = 2;
  }
  else if (uVar8 < 0x8745) {
    if (uVar8 - 0x8740 < 2) goto LAB_000d64e8;
LAB_000d6534:
    iVar9 = uVar8 - 0x10000;
    argCount = 0;
  }
  else if (uVar8 == 0x8745) {
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
    if (uVar8 != 0x8746) goto LAB_000d6534;
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
    if (((rgbScale == FLOAT_001aa104) || (uVar8 == 0x8740)) || (uVar8 == 0x8741)) goto LAB_000d6840;
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
    piVar12 = argOrder;
    do {
      iVar5 = *piVar12;
      piVar12 = piVar12 + 1;
      uVar14 = srcTokens[iVar5];
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
      *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = uVar14;
      tokenIndex = *countPtr + 1;
      *countPtr = tokenIndex;
      if ((srcTokens[iVar5] & 0x400000) != 0) {
        uVar14 = srcSwizzles[iVar5];
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
        *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = uVar14;
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
  ((int (*)())ffpsBuildAlphaSourceOperand)(ctx,(uint)*(ushort *)(unitState + 0x45c),(uint)*(ushort *)(unitState + 0x468),local_80,
               local_58,unit,baseFormat,isFirstUnit,previousUnit);
  ((int (*)())ffpsBuildAlphaSourceOperand)(ctx,(uint)*(ushort *)(unitState + 0x45e),(uint)*(ushort *)(unitState + 0x46a),
               local_80 + 1,&local_70,unit,baseFormat,isFirstUnit,previousUnit);
  ((int (*)())ffpsBuildAlphaSourceOperand)(ctx,(uint)*(ushort *)(unitState + 0x460),(uint)*(ushort *)(unitState + 0x46c),auStack_78,
               auStack_6c,unit,baseFormat,isFirstUnit,previousUnit);
  uVar4 = *(ushort *)(unitState + 0x452);
  rgbScale = *(float *)(unitState + 0x478);
  if (uVar4 == 0x8574) {
    argOrder[0] = 0;
    ilOpcode = 3;
    argOrder[1] = 1;
    if ((local_80[1] & 0x400000) == 0) {
      local_80[1] = local_80[1] | 0x400000;
      local_70 = local_70 & 0xffff8fff | 0x3000;
    }
    unitState = 2;
    local_70 = local_70 | 0x20000;
  }
  else if (uVar4 < 0x8575) {
    if (uVar4 == 0x1e01) {
      unitState = 1;
      argOrder[0] = 0;
      ilOpcode = 0x47;
    }
    else {
      if (uVar4 < 0x1e02) {
        if (uVar4 != 0x104) {
LAB_000d6fbc:
          unitState = 0;
          goto LAB_000d7144;
        }
        ilOpcode = 3;
      }
      else if (uVar4 == 0x2100) {
        ilOpcode = 0x49;
      }
      else {
        if (uVar4 != 0x84e7) goto LAB_000d6fbc;
        ilOpcode = 0x5b;
      }
      unitState = 2;
      argOrder[0] = 0;
      argOrder[1] = 1;
    }
  }
  else if (uVar4 == 0x8744) {
    argOrder[0] = 0;
    unitState = 3;
    ilOpcode = 0x40;
    argOrder[2] = 1;
    argOrder[1] = 2;
  }
  else if (uVar4 < 0x8745) {
    if (uVar4 != 0x8575) goto LAB_000d6fbc;
    argOrder[1] = 0;
    unitState = 3;
    ilOpcode = 0x3f;
    argOrder[2] = 1;
    argOrder[0] = 2;
  }
  else if (uVar4 == 0x8745) {
    argOrder[0] = 0;
    ilOpcode = 0x40;
    argOrder[2] = 1;
    argOrder[1] = 2;
    if ((local_80[1] & 0x400000) == 0) {
      local_80[1] = local_80[1] | 0x400000;
      local_70 = local_70 & 0xffff8fff | 0x3000;
    }
    unitState = 3;
    local_70 = local_70 | 0x20000;
  }
  else {
    if (uVar4 != 0x8746) goto LAB_000d6fbc;
    argOrder[0] = 0;
    argOrder[1] = 2;
    ilOpcode = 0x40;
    argOrder[2] = 1;
    if ((local_80[1] & 0x400000) == 0) {
      local_80[1] = local_80[1] | 0x400000;
      local_70 = local_70 & 0xffff8fff | 0x3000;
    }
    unitState = 3;
    local_70 = local_70 | 0x8000;
  }
LAB_000d7144:
  textureUnitCount = ((unsigned char *)0x000013b2)[ctx];
  dstWriteWord = 0x140;
  if (uVar4 == 0x86af) {
    if (rgbScale != FLOAT_001aa0e8) {
      if (rgbScale == FLOAT_001aa108) {
        dstWriteWord = 0x740;
      }
      else {
        dstWriteWord = 0x740;
        local_74 = local_74 | 0x40000;
      }
      goto LAB_000d7214;
    }
  }
  else if ((rgbScale != FLOAT_001aa104) && (uVar4 != 0x8741)) {
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
    piVar12 = argOrder;
    do {
      argCount = *piVar12;
      piVar12 = piVar12 + 1;
      uVar14 = local_80[argCount];
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
      *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = uVar14;
      tokenIndex = *countPtr + 1;
      *countPtr = tokenIndex;
      if ((local_80[argCount] & 0x400000) != 0) {
        uVar14 = local_58[argCount];
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
        *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = uVar14;
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
  uint uVar6;
  undefined4 uVar7;
  undefined *puVar8;
  undefined *puVar9;
  uint uVar10;
  undefined4 ilOpcode;
  uint unitDestToken;
  uint uVar13;
  uint colorSourceToken;
  uint uVar15;
  uint *countPtr;
  
  countPtr = (uint *)(ilBuilder + 4);
  colorSourceToken = 0;
  uVar13 = 0;
  uVar10 = 0;
  puVar9 = (undefined *)0x0;
  puVar8 = (undefined *)0x0;
  uVar6 = 0;
  uVar7 = 0;
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
          uVar15 = 2;
          uVar13 = unitNumber | 0x440000;
          puVar8 = ((unsigned char *)0x00003444);
          puVar9 = ((unsigned char *)0x00004210);
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
        uVar15 = 2;
        uVar13 = unitNumber | 0x440000;
        puVar9 = ((unsigned char *)0x00003444);
        puVar8 = ((unsigned char *)0x00004210);
        goto LAB_000d75e8;
      }
      if (baseFormat != 0x190a) {
        if (baseFormat < 0x190a) goto LAB_000d7d84;
        if (baseFormat != 0x8049) goto LAB_000d75e0;
      }
    }
    tokenIndex = *countPtr;
    uVar15 = 1;
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
      uVar13 = unitNumber | 0x440000;
      uVar10 = unitNumber | 0x440000;
      if (baseFormat < 0x190b) {
        if (0x1906 < baseFormat) {
LAB_000d7ee4:
          puVar8 = (undefined *)0x555;
          uVar6 = 0x210;
          goto LAB_000d7f0c;
        }
        if (baseFormat != 0x1906) goto LAB_000d7f0c;
        uVar6 = 0x444;
        puVar8 = (undefined *)0x555;
      }
      else {
        if (baseFormat == 0x8049) goto LAB_000d7ee4;
LAB_000d7f0c:
        if (baseFormat == 0x8049) {
          tokenIndex = *countPtr;
          uVar15 = 3;
          puVar8 = (undefined *)((uint)puVar8 | 0x5000);
          uVar6 = uVar6 | 0x3000;
          goto LAB_000d75e8;
        }
      }
      tokenIndex = *countPtr;
      uVar15 = 3;
      puVar8 = (undefined *)((uint)puVar8 | 0x3000);
      uVar6 = uVar6 | 0x4000;
      goto LAB_000d75e8;
    }
    if ((texEnvMode == 0xbe2) && (0x1905 < baseFormat)) {
      if (baseFormat < 0x190b) {
        if (isFirstUnit == 0) {
          uVar10 = textureUnitCount + previousUnit & 0xffff | 0x40000;
        }
        else {
          uVar10 = 0x120000;
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
        *(uint *)(tokenIndex3 * 4 + *(int *)(ilBuilder + 0xc)) = uVar10;
        colorSourceToken = unitNumber | 0x40000;
        tokenIndex = *countPtr + 1;
        *countPtr = tokenIndex;
        if (isFirstUnit == 0) {
          uVar13 = previousUnit + (uint)(byte)((unsigned char *)0x000013b2)[ctx] & 0xffff | 0x40000;
        }
        else {
          uVar13 = 0x120000;
        }
        uVar15 = 2;
        unitDestToken = unitTempRegister | 0x440000;
        uVar7 = 0x40;
        goto LAB_000d75e8;
      }
      if (baseFormat == 0x8049) {
        ilOpcode = 0x3f;
        colorSourceToken = unitNumber | 0x40000;
        uVar13 = unitNumber | 0x10000;
        if (isFirstUnit == 0) {
          tokenIndex = *countPtr;
          uVar15 = 0;
          uVar10 = textureUnitCount + previousUnit & 0xffff | 0x40000;
        }
        else {
          tokenIndex = *countPtr;
          uVar15 = 0;
          uVar10 = 0x120000;
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
          uVar13 = textureUnitCount + previousUnit & 0xffff | 0x40000;
        }
        else {
          uVar13 = 0x120000;
        }
        tokenIndex = *countPtr;
        colorSourceToken = unitNumber | 0x440000;
        uVar15 = 2;
        puVar9 = ((unsigned char *)0x00003555);
      }
      else if (baseFormat == 0x1907) {
        ilOpcode = 0x49;
        if (isFirstUnit == 0) {
          uVar13 = textureUnitCount + previousUnit & 0xffff | 0x40000;
        }
        else {
          uVar13 = 0x120000;
        }
        tokenIndex = *countPtr;
        colorSourceToken = unitNumber | 0x440000;
        uVar15 = 2;
        puVar9 = ((unsigned char *)0x00005210);
      }
      else {
        ilOpcode = 0x49;
        colorSourceToken = unitNumber | 0x40000;
        if (isFirstUnit == 0) {
          tokenIndex = *countPtr;
          uVar15 = 2;
          uVar13 = textureUnitCount + previousUnit & 0xffff | 0x40000;
        }
        else {
          tokenIndex = *countPtr;
          uVar15 = 2;
          uVar13 = 0x120000;
        }
      }
      goto LAB_000d75e8;
    }
    if (texEnvMode == 0x2101) {
      if (baseFormat == 0x1907) {
        ilOpcode = 3;
        if (isFirstUnit == 0) {
          uVar13 = textureUnitCount + previousUnit & 0xffff | 0x40000;
        }
        else {
          uVar13 = 0x120000;
        }
        tokenIndex = *countPtr;
        colorSourceToken = unitNumber | 0x440000;
        uVar13 = uVar13 | 0x400000;
        uVar15 = 2;
        puVar9 = ((unsigned char *)0x00004210);
        puVar8 = ((unsigned char *)0x00003444);
        goto LAB_000d75e8;
      }
      if (baseFormat == 0x1908) {
        ilOpcode = 0x3f;
        if (isFirstUnit == 0) {
          uVar10 = textureUnitCount + previousUnit & 0xffff | 0x40000;
        }
        else {
          uVar10 = 0x120000;
        }
        tokenIndex = *countPtr;
        colorSourceToken = unitNumber | 0x440000;
        uVar13 = unitNumber | 0x440000;
        uVar15 = 3;
        puVar9 = ((unsigned char *)0x00004333);
        puVar8 = ((unsigned char *)0x00004210);
        goto LAB_000d75e8;
      }
    }
  }
LAB_000d75e0:
  tokenIndex = *countPtr;
  uVar15 = 0;
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
    *(undefined4 *)(tokenIndex2 * 4 + *(int *)(ilBuilder + 0xc)) = uVar7;
    tokenIndex2 = *countPtr + 1;
    *countPtr = tokenIndex2;
  }
  if (uVar15 != 0) {
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
      *(undefined **)(tokenIndex2 * 4 + *(int *)(ilBuilder + 0xc)) = puVar9;
      tokenIndex2 = *countPtr + 1;
      *countPtr = tokenIndex2;
    }
  }
  if (1 < uVar15) {
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
    *(uint *)(tokenIndex2 * 4 + *(int *)(ilBuilder + 0xc)) = uVar13;
    tokenIndex2 = *countPtr + 1;
    *countPtr = tokenIndex2;
    if ((uVar13 & 0x400000) != 0) {
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
      *(undefined **)(tokenIndex2 * 4 + *(int *)(ilBuilder + 0xc)) = puVar8;
      tokenIndex2 = *countPtr + 1;
      *countPtr = tokenIndex2;
    }
  }
  if (2 < uVar15) {
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
    *(uint *)(tokenIndex2 * 4 + *(int *)(ilBuilder + 0xc)) = uVar10;
    tokenIndex3 = *countPtr + 1;
    *countPtr = tokenIndex3;
    if ((uVar10 & 0x400000) != 0) {
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
      *(uint *)(tokenIndex3 * 4 + *(int *)(ilBuilder + 0xc)) = uVar6;
      *countPtr = *countPtr + 1;
    }
  }
  return;
}

/* FUN_000d8450 @ 0xd8450 (5856 bytes) */
int FUN_000d8450(ctx, ilBuilder, param_3)
  int ctx;
  int ilBuilder;
  int param_3;
{
  uint tokenIndex;
  bool bVar1;
  uint uVar2;
  undefined4 newTokenBuffer;
  uint textureUnitCount;
  int texEnvRecord;
  int unitByteCursor;
  int unitPtrCursor;
  int unitRecordCursor;
  char *unitFlagPtr;
  uint unit;
  uint uVar11;
  uint ilOpcode;
  undefined *puVar13;
  uint *countPtr;
  int iStack00000020;
  char acStack_68 [28];
  
  countPtr = (uint *)(ilBuilder + 4);
  textureUnitCount = (uint)(byte)((unsigned char *)0x000013b2)[ctx];
  if (textureUnitCount != 0) {
    unit = 0;
    texEnvRecord = ctx + 0x450;
    unitByteCursor = ctx;
    unitPtrCursor = ctx;
    unitRecordCursor = ctx;
    iStack00000020 = param_3;
    do {
      if (*(int *)(((unsigned char *)0x000013f8) + unitPtrCursor) != 0) {
        bVar1 = false;
        if ((*(uint *)(ctx + 0x44) & 0x100000) != 0) {
          bVar1 = *(char *)(unit + *(int *)(((unsigned char *)0x00001168) + ctx) + 0x71) == '\0';
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
            if ((iStack00000020 == 0) || (acStack_68[unit] == '\0')) {
              if ((bVar1) &&
                 (((*(uint *)(ctx + 0x44) & 0x20000000) == 0 ||
                  ((1 << (unit & 0x3f) & *(uint *)(ctx + 0xec)) == 0)))) {
                uVar11 = 0x10011;
              }
              else {
                uVar11 = unit & 0xffff | 0x110000;
              }
            }
            else {
              uVar11 = unit + (uint)(byte)((unsigned char *)0x000013b2)[ctx] * 2 & 0xffff | 0x40000;
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
            *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = uVar11 | 0x400000;
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
          uVar11 = unit & 0xffff;
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
          uVar2 = uVar11 + 0x14 & 0xffff;
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = uVar11 | 0x110000;
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
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = uVar2 | 0x410000;
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
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = uVar11 | 0x110000;
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
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = uVar2 | 0x410000;
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
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = uVar2 | 0x410000;
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
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = uVar11 | 0x510000;
          tokenIndex = *countPtr + 1;
          *countPtr = tokenIndex;
          if (*unitFlagPtr == '\x01') {
            puVar13 = (undefined *)0x0;
          }
          else {
            puVar13 = ((unsigned char *)0x00001111);
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
          *(undefined **)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = puVar13;
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
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = uVar2 | 0x410000;
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
          *(uint *)(tokenIndex * 4 + *(int *)(ilBuilder + 0xc)) = uVar11 | 0x40000;
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

/* FUN_000d9b58 @ 0xd9b58 (84 bytes) */
int FUN_000d9b58(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  undefined4 param_1;
  uint *param_2;
  int param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  bool bVar1;
  uint uVar2;
  int loopCounter;
  int loopCounterB;
  
  loopCounter = 0;
  do {
    uVar2 = *param_2;
    if (uVar2 != 0) {
      loopCounterB = 0;
      do {
        if ((uVar2 & 1) != 0) {
          if (param_3 == 0) {
            return loopCounterB + loopCounter;
          }
          param_3 = param_3 + -1;
        }
        uVar2 = uVar2 >> 1;
        loopCounterB = loopCounterB + 1;
      } while (uVar2 != 0);
    }
    bVar1 = loopCounter != 0xe0;
    param_2 = param_2 + 1;
    loopCounter = loopCounter + 0x20;
  } while (bVar1);
  return -1;
}

/* scStoreConstantComponent @ 0xd9bac (228 bytes) */
undefined4 scStoreConstantComponent(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6,double fparam_1)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  
  if (param_6 == 0) {
    piVar4 = *(int **)(param_5 + 0x84);
    if (piVar4 != (int *)0x0) {
      uVar2 = *(uint *)(param_5 + 0x78);
      if (uVar2 == 0) {
LAB_000d9c0c:
        if (*(uint *)(param_5 + 0x6c) <= uVar2) {
          return 0;
        }
        iVar3 = uVar2 * 0x14;
        *(uint *)(param_5 + 0x78) = uVar2 + 1;
      }
      else if (*piVar4 == param_2) {
        iVar3 = 0;
      }
      else {
        iVar1 = 0x14;
        uVar6 = uVar2;
        piVar5 = piVar4;
        do {
          iVar3 = iVar1;
          piVar5 = piVar5 + 5;
          uVar6 = uVar6 - 1;
          if (uVar6 == 0) goto LAB_000d9c0c;
          iVar1 = iVar3 + 0x14;
        } while (*piVar5 != param_2);
      }
      *(int *)(iVar3 + (int)piVar4) = param_2;
      *(float *)((int)piVar4 + param_4 * 4 + iVar3 + 4) = (float)fparam_1;
      return 1;
    }
  }
  else {
    uVar2 = *(uint *)(param_5 + 0x54);
    if (uVar2 < *(uint *)(param_5 + 0x48)) {
      *(uint *)(param_5 + 0x54) = uVar2 + 1;
      iVar3 = uVar2 * 0x24 + *(int *)(param_5 + 0x60);
      *(int *)(uVar2 * 0x24 + *(int *)(param_5 + 0x60)) = param_2;
      *(float *)(iVar3 + 0x14) = (float)fparam_1;
      *(int *)(iVar3 + 4) = param_4;
      *(undefined4 *)(iVar3 + 8) = 1;
      return 1;
    }
  }
  return 0;
}

/* FUN_000d9c90 @ 0xd9c90 (228 bytes) */
int FUN_000d9c90(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  
  if (param_6 == 0) {
    piVar4 = *(int **)(param_5 + 0x88);
    if (piVar4 != (int *)0x0) {
      uVar2 = *(uint *)(param_5 + 0x7c);
      if (uVar2 == 0) {
LAB_000d9cf0:
        if (*(uint *)(param_5 + 0x70) <= uVar2) {
          return 0;
        }
        iVar3 = uVar2 * 0x14;
        *(uint *)(param_5 + 0x7c) = uVar2 + 1;
      }
      else if (*piVar4 == param_2) {
        iVar3 = 0;
      }
      else {
        iVar1 = 0x14;
        uVar6 = uVar2;
        piVar5 = piVar4;
        do {
          iVar3 = iVar1;
          piVar5 = piVar5 + 5;
          uVar6 = uVar6 - 1;
          if (uVar6 == 0) goto LAB_000d9cf0;
          iVar1 = iVar3 + 0x14;
        } while (*piVar5 != param_2);
      }
      *(int *)(iVar3 + (int)piVar4) = param_2;
      *(undefined4 *)((int)piVar4 + param_4 * 4 + iVar3 + 4) = param_3;
      return 1;
    }
  }
  else {
    uVar2 = *(uint *)(param_5 + 0x58);
    if (uVar2 < *(uint *)(param_5 + 0x4c)) {
      *(uint *)(param_5 + 0x58) = uVar2 + 1;
      iVar3 = uVar2 * 0x24 + *(int *)(param_5 + 100);
      *(int *)(uVar2 * 0x24 + *(int *)(param_5 + 100)) = param_2;
      *(undefined4 *)(iVar3 + 0x14) = param_3;
      *(int *)(iVar3 + 4) = param_4;
      *(undefined4 *)(iVar3 + 8) = 0;
      return 1;
    }
  }
  return 0;
}

/* FUN_000d9d74 @ 0xd9d74 (228 bytes) */
int FUN_000d9d74(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  undefined4 param_3;
  int param_4;
  int param_5;
  int param_6;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  
  if (param_6 == 0) {
    piVar4 = *(int **)(param_5 + 0x8c);
    if (piVar4 != (int *)0x0) {
      uVar2 = *(uint *)(param_5 + 0x80);
      if (uVar2 == 0) {
LAB_000d9dd4:
        if (*(uint *)(param_5 + 0x74) <= uVar2) {
          return 0;
        }
        iVar3 = uVar2 * 0x14;
        *(uint *)(param_5 + 0x80) = uVar2 + 1;
      }
      else if (*piVar4 == param_2) {
        iVar3 = 0;
      }
      else {
        iVar1 = 0x14;
        uVar6 = uVar2;
        piVar5 = piVar4;
        do {
          iVar3 = iVar1;
          piVar5 = piVar5 + 5;
          uVar6 = uVar6 - 1;
          if (uVar6 == 0) goto LAB_000d9dd4;
          iVar1 = iVar3 + 0x14;
        } while (*piVar5 != param_2);
      }
      *(int *)(iVar3 + (int)piVar4) = param_2;
      *(undefined4 *)((int)piVar4 + param_4 * 4 + iVar3 + 4) = param_3;
      return 1;
    }
  }
  else {
    uVar2 = *(uint *)(param_5 + 0x5c);
    if (uVar2 < *(uint *)(param_5 + 0x50)) {
      *(uint *)(param_5 + 0x5c) = uVar2 + 1;
      iVar3 = uVar2 * 0x24 + *(int *)(param_5 + 0x68);
      *(int *)(uVar2 * 0x24 + *(int *)(param_5 + 0x68)) = param_2;
      *(undefined4 *)(iVar3 + 0x14) = param_3;
      *(int *)(iVar3 + 4) = param_4;
      *(undefined4 *)(iVar3 + 8) = 2;
      return 1;
    }
  }
  return 0;
}

/* FUN_000d9e58 @ 0xd9e58 (64 bytes) */
int FUN_000d9e58(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  int param_6;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_6 + 0x54);
  if (*(uint *)(param_6 + 0x48) <= uVar1) {
    return 0;
  }
  iVar2 = uVar1 * 0x24 + *(int *)(param_6 + 0x60);
  *(uint *)(param_6 + 0x54) = uVar1 + 1;
  *(undefined4 *)(uVar1 * 0x24 + *(int *)(param_6 + 0x60)) = param_2;
  *(undefined4 *)(iVar2 + 0x10) = param_4;
  *(undefined4 *)(iVar2 + 4) = param_5;
  *(undefined4 *)(iVar2 + 8) = param_3;
  return 1;
}

/* FUN_000d9e98 @ 0xd9e98 (156 bytes) */
int FUN_000d9e98(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  int param_7;
  int param_8;
  undefined4 param_9;
  int param_10;
{
  uint uVar1;
  int iVar2;
  
  uVar1 = *(uint *)(param_10 + 0x58);
  if (*(uint *)(param_10 + 0x4c) <= uVar1) {
    return 0;
  }
  *(uint *)(param_10 + 0x58) = uVar1 + 1;
  iVar2 = uVar1 * 0x24 + *(int *)(param_10 + 100);
  *(undefined4 *)(uVar1 * 0x24 + *(int *)(param_10 + 100)) = param_2;
  *(undefined4 *)(iVar2 + 4) = 0;
  if (param_8 == -1) {
    if (param_7 == 0xff) {
      *(undefined4 *)(iVar2 + 8) = 0x15;
    }
    else {
      *(undefined4 *)(iVar2 + 8) = 0x16;
    }
  }
  else if (param_7 == 0xff) {
    *(undefined4 *)(iVar2 + 8) = 0x17;
  }
  else {
    *(undefined4 *)(iVar2 + 8) = 0x18;
  }
  *(int *)(iVar2 + 0x1c) = param_8;
  *(undefined4 *)(iVar2 + 0x10) = param_5;
  *(undefined4 *)(iVar2 + 0xc) = param_6;
  *(undefined4 *)(iVar2 + 0x20) = param_9;
  return 1;
}

/* FUN_000d9f3c @ 0xd9f3c (60 bytes) */
int FUN_000d9f3c(param_1, param_2)
  int param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = *(int *)(param_1 + 0x2c);
  }
  else {
    iVar2 = *(int *)(param_1 + 0x30);
  }
  bVar1 = true;
  if (*(uint **)(iVar2 + 0x48) != (uint *)0x0) {
    bVar1 = (**(uint **)(iVar2 + 0x48) & 0x200000) == 0;
  }
  return bVar1;
}

/* FUN_000d9f80 @ 0xd9f80 (32 bytes) */
int FUN_000d9f80(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x3c);
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x40);
}

/* FUN_000d9fa0 @ 0xd9fa0 (32 bytes) */
int FUN_000d9fa0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x30) + 0xc);
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x10);
}

/* FUN_000d9fc0 @ 0xd9fc0 (32 bytes) */
int FUN_000d9fc0(param_1, param_2)
  int param_1;
  int param_2;
{
  if (param_2 != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x24);
  }
  return *(undefined4 *)(*(int *)(param_1 + 0x2c) + 0x28);
}

/* FUN_000d9fe0 @ 0xd9fe0 (72 bytes) */
int FUN_000d9fe0(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 *param_5;
{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x2c) + 0x34);
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0x30) + 0x30);
  }
  iVar1 = iVar2 + param_3 * 0x10;
  *param_5 = *(undefined4 *)(iVar2 + param_3 * 0x10);
  param_5[1] = *(undefined4 *)(iVar1 + 4);
  param_5[2] = *(undefined4 *)(iVar1 + 8);
  param_5[3] = *(undefined4 *)(iVar1 + 0xc);
  return;
}

/* FUN_000da028 @ 0xda028 (72 bytes) */
int FUN_000da028(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 *param_5;
{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x2c) + 4);
  }
  else {
    iVar1 = **(int **)(param_1 + 0x30);
  }
  iVar2 = iVar1 + param_3 * 0x10;
  *param_5 = *(undefined4 *)(iVar1 + param_3 * 0x10);
  param_5[1] = *(undefined4 *)(iVar2 + 4);
  param_5[2] = *(undefined4 *)(iVar2 + 8);
  param_5[3] = *(undefined4 *)(iVar2 + 0xc);
  return;
}

/* FUN_000da070 @ 0xda070 (44 bytes) */
int FUN_000da070(param_1, param_2, param_3, param_4, param_5)
  int param_1;
  int param_2;
  int param_3;
  undefined4 param_4;
  undefined4 *param_5;
{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x2c) + 0x1c);
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 0x30) + 0x18);
  }
  *param_5 = *(undefined4 *)(iVar1 + param_3 * 4);
  return;
}

/* FUN_000da09c @ 0xda09c (36 bytes) */
int FUN_000da09c(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(param_1 + 0x38);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x3c);
  }
  *(int *)(iVar1 + 0x100) = *(int *)(iVar1 + 0x100) + 1;
  return;
}

/* FUN_000da0c0 @ 0xda0c0 (192 bytes) */
int FUN_000da0c0(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puStack00000018;
  undefined4 *puStack0000001c;
  
  puStack00000018 = param_1;
  puStack0000001c = param_2;
  iVar1 = (*(code *)param_2[0xc])(param_2[0xb],0x6c8);
  uVar3 = puStack0000001c[0xd];
  *puStack00000018 = uVar3;
  uVar2 = puStack0000001c[0xb];
  puStack00000018[1] = uVar2;
  puStack00000018[3] = *puStack0000001c;
  puStack00000018[5] = puStack0000001c[1];
  puStack00000018[4] = puStack0000001c[0x14];
  if (iVar1 == 0) {
    puStack00000018[2] = 0;
    return;
  }
  FUN_000e1a48(iVar1,uVar2,puStack0000001c[0xc],uVar3,0,0,puStack0000001c[0xf],puStack0000001c[0x10]
               ,puStack0000001c[0x11],puStack0000001c[0x12],puStack0000001c[0x13],
               puStack0000001c[0xe]);
  puStack00000018[2] = iVar1;
  if (*(int *)(iVar1 + 0x314) != 0) {
    return;
  }
  iVar1 = _setjmp(*(int **)(iVar1 + 4));
  if (iVar1 != 0) {
    return;
  }
  if (puStack00000018[3] == -1) {
    puStack00000018[10] = puStack0000001c[2];
  }
  else {
    uVar2 = FUN_000cd290(puStack00000018[3]);
    puStack00000018[10] = uVar2;
  }
  iVar1 = puStack00000018[10];
  iVar4 = puStack0000001c[3];
  iVar5 = puStack0000001c[4];
  if (iVar1 == 2) {
    Compiler__setHardwareFamily(puStack00000018[2],2);
    if (iVar5 - 1U < 0x20c) {
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = iVar5;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = 0x20c;
    }
    if (iVar4 - 1U < 0x100) goto code_r0x000da340;
  }
  else {
    if (iVar1 == 3) {
      Compiler__setHardwareFamily(puStack00000018[2],4);
      if (iVar5 - 1U < 0x200) {
        *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = iVar5;
      }
      else {
        *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = 0x200;
      }
      if (0x3ff < iVar4 - 1U) {
        *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = 0x400;
        return;
      }
code_r0x000da340:
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = iVar4;
      return;
    }
    if (iVar1 != 1) {
      *(undefined4 *)(puStack00000018[2] + 0x314) = 0xe;
      Compiler__setHardwareFamily(puStack00000018[2],1);
      return;
    }
    Compiler__setHardwareFamily(puStack00000018[2],1);
    if (iVar5 - 1U < 0x60) {
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = iVar5;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = 0x60;
    }
    if (iVar4 - 1U < 0x100) {
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = iVar5;
      return;
    }
  }
  *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = 0x100;
  return;
}

/* scSetCallbackTables @ 0xda394 (68 bytes) */
int scSetCallbackTables(param_1, param_2, param_3)
  int param_1;
  int param_2;
  undefined4 param_3;
{
  undefined4 uVar1;
  
  *(undefined4 *)(param_1 + 0x38) = param_3;
  *(undefined4 *)(param_1 + 0x3c) = param_3;
  *(undefined4 *)(param_1 + 0x40) = param_3;
  *(int *)(param_1 + 0x2c) = param_2;
  *(int *)(param_1 + 0x30) = param_2;
  *(int *)(param_1 + 0x34) = param_2;
  if (*(int *)(param_1 + 8) != 0) {
    uVar1 = FUN_000e2524(*(int *)(param_1 + 8),param_3,*(undefined4 *)(param_2 + 0x4c),
                         *(undefined4 *)(param_2 + 0x54),param_1);
    return uVar1;
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
int FUN_000da438(param_1, param_2)
  int param_1;
  undefined4 *param_2;
{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = param_2[2];
  uVar1 = param_2[1];
  *(undefined4 *)(param_1 + 0x18) = *param_2;
  *(undefined4 *)(param_1 + 0x20) = uVar2;
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  return;
}

/* scDestroyCompilerObject @ 0xda458 (96 bytes) */
int scDestroyCompilerObject(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  if (param_1[2] != 0) {
    Compiler__releaseChipAndPools(param_1[2],param_2);
                    
                    
    (*(code *)*param_1)(param_1[1],param_1[2]);
    return;
  }
  return;
}

/* FUN_000da4b8 @ 0xda4b8 (192 bytes) */
int FUN_000da4b8(param_1, param_2)
  undefined4 *param_1;
  undefined4 *param_2;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 *puStack00000018;
  undefined4 *puStack0000001c;
  
  puStack00000018 = param_1;
  puStack0000001c = param_2;
  iVar1 = (*(code *)param_2[0xc])(param_2[0xb],0x6c8);
  uVar3 = puStack0000001c[0xd];
  *puStack00000018 = uVar3;
  uVar2 = puStack0000001c[0xb];
  puStack00000018[1] = uVar2;
  puStack00000018[3] = *puStack0000001c;
  puStack00000018[5] = puStack0000001c[1];
  puStack00000018[4] = puStack0000001c[0x14];
  if (iVar1 == 0) {
    puStack00000018[2] = 0;
    return;
  }
  FUN_000e1a48(iVar1,uVar2,puStack0000001c[0xc],uVar3,0,0,puStack0000001c[0xf],puStack0000001c[0x10]
               ,puStack0000001c[0x11],puStack0000001c[0x12],puStack0000001c[0x13],
               puStack0000001c[0xe]);
  puStack00000018[2] = iVar1;
  if (*(int *)(iVar1 + 0x314) != 0) {
    return;
  }
  iVar1 = _setjmp(*(int **)(iVar1 + 4));
  if (iVar1 != 0) {
    return;
  }
  if (puStack00000018[3] == -1) {
    puStack00000018[10] = puStack0000001c[2];
  }
  else {
    uVar2 = FUN_000cd290(puStack00000018[3]);
    puStack00000018[10] = uVar2;
  }
  iVar1 = puStack00000018[10];
  iVar4 = puStack0000001c[3];
  iVar5 = puStack0000001c[4];
  if (iVar1 == 2) {
    Compiler__setHardwareFamily(puStack00000018[2],2);
    if (iVar5 - 1U < 0x20c) {
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = iVar5;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = 0x20c;
    }
    if (iVar4 - 1U < 0x100) goto code_r0x000da738;
  }
  else {
    if (iVar1 == 3) {
      Compiler__setHardwareFamily(puStack00000018[2],4);
      if (iVar5 - 1U < 0x200) {
        *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = iVar5;
      }
      else {
        *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = 0x200;
      }
      if (0x3ff < iVar4 - 1U) {
        *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = 0x400;
        return;
      }
code_r0x000da738:
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = iVar4;
      return;
    }
    if (iVar1 != 1) {
      *(undefined4 *)(puStack00000018[2] + 0x314) = 0xe;
      Compiler__setHardwareFamily(puStack00000018[2],1);
      return;
    }
    Compiler__setHardwareFamily(puStack00000018[2],1);
    if (iVar5 - 1U < 0x60) {
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = iVar5;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 8) + 0x40) = 0x60;
    }
    if (iVar4 - 1U < 0x100) {
      *(int *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = iVar5;
      return;
    }
  }
  *(undefined4 *)(*(int *)(*(int *)(puStack00000018[2] + 0x310) + 4) + 0x40) = 0x100;
  return;
}

/* FUN_000da78c @ 0xda78c (244 bytes) */
double FUN_000da78c(uint param_1,double fparam_1)
{
  uint uVar1;
  uint uVar2;
  double dVar3;
  double dVar4;
  
  dVar3 = DOUBLE_001aa250;
  uVar1 = param_1 & 7;
  uVar2 = param_1 >> 3 & 0xf;
  if (uVar2 == 0) {
    if (uVar1 == 0) {
      dVar3 = (double)FLOAT_001aa1c0;
    }
    else {
      dVar3 = (double)((float)((double)CONCAT44(0x43300000,uVar1) - DOUBLE_001aa250) *
                       FLOAT_001aa170 * FLOAT_001aa1c4);
    }
  }
  else {
    dVar4 = _pow(DOUBLE_001aa2a0,
                 (double)(float)((double)CONCAT44(0x43300000,uVar2) - DOUBLE_001aa250) -
                 DOUBLE_001aa2a8[0]);
    dVar3 = (double)((float)((double)CONCAT44(0x43300000,uVar1) - dVar3) * FLOAT_001aa170 *
                     (float)dVar4 + (float)dVar4);
  }
  return dVar3;
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
  uint uVar1;
  undefined4 uVar2;
  int loopCounter;
  undefined1 auStack_234 [540];
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 12)) = fmtArgR6;
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = fmtArgR7;
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = fmtArgR8;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = fmtArgR9;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = fmtArgR10;
  if (0 < indentLevel) {
    loopCounter = 0;
    uVar2 = format;
    do {
      loopCounter = loopCounter + 1;
      ((int (*)())ildisAppendf)(disassembler,"    ",uVar2,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
    } while (indentLevel != loopCounter);
  }
  printf_LDBLStub_1a3428(auStack_234,0x200,format,&(*(unsigned int *)((unsigned char *)ghidra_home + 12)),fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  uVar1 = _strlen(disassembler + 0x10);
  if (uVar1 <= 0x1ff - uVar1) {
    _strcat(disassembler + 0x10,auStack_234);
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
void ildisPrintFixedPoint(undefined4 disassembler,uint fieldBits,uint integerBits,uint fractionBits,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12)
{
  uint loopCounterB;
  float integerPart;
  uint uVar2;
  int iVar3;
  uint loopCounter;
  undefined1 *textBufferPtr;
  undefined4 in_r7;
  undefined4 in_r8;
  uint uVar6;
  undefined4 in_r10;
  uint uVar7;
  undefined1 textBuffer [256];
  undefined4 local_28;
  int fractionScale;
  undefined4 local_20;
  uint integerField;
  undefined4 local_18;
  uint fractionField;
  
  fractionScale = 1 << (fractionBits & 0x3f);
  local_28 = 0x43300000;
  integerField = 0;
  if (1 < integerBits) {
    iVar3 = integerBits - 1;
    integerField = 0;
    if (iVar3 != 0) {
      loopCounterB = 0;
      integerField = 0;
      do {
        uVar7 = loopCounterB & 0x3f;
        loopCounterB = loopCounterB + 1;
        integerField = integerField | 1 << uVar7;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      integerField = integerField << (fractionBits & 0x3f);
    }
    integerField = fieldBits & integerField;
  }
  local_20 = 0x43300000;
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
    uVar7 = fractionBits;
    do {
      uVar2 = loopCounter & 0x3f;
      loopCounter = loopCounter + 1;
      uVar6 = uVar6 | 1 << uVar2;
      uVar7 = uVar7 - 1;
    } while (uVar7 != 0);
    fractionField = uVar6 & fieldBits;
  }
  local_18 = 0x43300000;
  textBufferPtr = textBuffer;
  ((char * (*)())FUN_000cdc3c)(disassembler,10,textBufferPtr,
               (double)((float)(DOUBLE_001aa200 /
                               ((double)CONCAT44(0x43300000,fractionScale) - DOUBLE_001aa250)) *
                        (float)((double)CONCAT44(0x43300000,fractionField) - DOUBLE_001aa250) + integerPart));
  ((int (*)())ildisAppendf)(disassembler,textBuffer,textBufferPtr,fractionBits,in_r7,in_r8,uVar6,in_r10);
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
  double dVar3;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  
  dVar3 = (double)((int (*)())ildisAppendf)(disassembler,"_xoffset(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  integerBitsArg = 7;
  fractionBitsArg = 1;
  ((void (*)())ildisPrintFixedPoint)(disassembler,offsetsWord & 0xff,7,1,dVar3,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
               in_stack_ffffffa8,in_stack_ffffffb0,in_stack_ffffffb8,in_stack_ffffffc0);
  ((int (*)())ildisAppendf)(disassembler,")",integerBitsArg,fractionBitsArg,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  dVar3 = (double)((int (*)())ildisAppendf)(disassembler,"_yoffset(",integerBitsArg,fractionBitsArg,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  integerBitsArg = 7;
  fractionBitsArg = 1;
  ((void (*)())ildisPrintFixedPoint)(disassembler,offsetsWord >> 8 & 0xff,7,1,dVar3,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
               in_stack_ffffffa8,in_stack_ffffffb0,in_stack_ffffffb8,in_stack_ffffffc0);
  ((int (*)())ildisAppendf)(disassembler,")",integerBitsArg,fractionBitsArg,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  dVar3 = (double)((int (*)())ildisAppendf)(disassembler,"_zoffset(",integerBitsArg,fractionBitsArg,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  integerBitsArg = 7;
  fractionBitsArg = 1;
  ((void (*)())ildisPrintFixedPoint)(disassembler,offsetsWord >> 0x10 & 0xff,7,1,dVar3,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8,
               in_stack_ffffffa8,in_stack_ffffffb0,in_stack_ffffffb8,in_stack_ffffffc0);
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
  double fparam_1;
  double in_f2;
  double in_f3;
  double in_f4;
  double in_f5;
  double in_f6;
  double in_f7;
  double in_f8;
  double in_stack_ffffffa8;
  double in_stack_ffffffb0;
  double in_stack_ffffffb8;
  double in_stack_ffffffc0;
  
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
  fparam_1 = (double)((int (*)())ildisAppendf)(disassembler,"_lodbias(",passThroughR5,fmtArgR6,fmtArgR7,fmtArgR8,fmtArgR9,
                                  fmtArgR10);
  integerBitsArg = 3;
  fractionBitsArg = 4;
  ((void (*)())ildisPrintFixedPoint)(disassembler,filterWord >> 0x12 & 0x7f,3,4,fparam_1,in_f2,in_f3,in_f4,in_f5,in_f6,in_f7,in_f8
               ,in_stack_ffffffa8,in_stack_ffffffb0,in_stack_ffffffb8,in_stack_ffffffc0);
  ((int (*)())ildisAppendf)(disassembler,")",integerBitsArg,fractionBitsArg,fmtArgR7,fmtArgR8,fmtArgR9,fmtArgR10);
  return;
}

