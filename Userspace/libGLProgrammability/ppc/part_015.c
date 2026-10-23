#include "decls.h"

/* _PPCRuntimeCompilerGetBaseIndexInRegister @ 0x97bda06c (16 bytes) */
int _PPCRuntimeCompilerGetBaseIndexInRegister(param_1, param_2)
  int param_1;
  int param_2;
{
  return *(undefined2 *)(param_2 * 0x38 + param_1 + 0x18);
}

/* _PPCRuntimeCompilerGetOffsetInRegister @ 0x97bda07c (88 bytes) */
int _PPCRuntimeCompilerGetOffsetInRegister(param_1, param_2)
  int param_1;
  int param_2;
{
  int iVar1;
  int local_40 [2];
  byte abStack_38 [40];
  
  iVar1 = param_2 * 0x38 + param_1;
  _memcpy(local_40,iVar1 + 8,0x24);
  return *(undefined4 *)(local_40[0] + (uint)abStack_38[*(int *)(iVar1 + 4)] * 4);
}

/* _PPCRuntimeCompilerBuildTransferSwizzle @ 0x97bda0d4 (104 bytes) */
int _PPCRuntimeCompilerBuildTransferSwizzle(compiler, param_2, param_3)
  undefined1 *compiler;
  int param_2;
  char *param_3;
{
  char cVar1;
  uint loopIndex;
  undefined1 *puVar3;
  
  *compiler = 0;
  compiler[1] = 1;
  compiler[2] = 2;
  compiler[3] = 3;
  puVar3 = compiler + 3;
  do {
    cVar1 = *param_3;
    loopIndex = 0;
    param_3 = param_3 + 1;
    do {
      if (*(char *)(param_2 + loopIndex) == cVar1) {
        *compiler = (char)loopIndex;
        break;
      }
      loopIndex = loopIndex + 1;
    } while (loopIndex < 4);
    compiler = compiler + 1;
    if (puVar3 < compiler) {
      return;
    }
  } while( true );
}

/* _PPCRuntimeCompilerSwizzleRegisterAV @ 0x97bda13c (2444 bytes) */
int _PPCRuntimeCompilerSwizzleRegisterAV(compiler, vectorReg, swizzle)
  int compiler;
  int vectorReg;
  uint *swizzle;
{
  uint vectorInstWord8;
  uint vectorInstWord7;
  uint vectorInstWord5;
  uint vectorInstWord4;
  int srcRegB;
  int srcRegA;
  uint *codeCursor2;
  uint *codeCursor;
  int iVar1;
  uint uVar2;
  uint vectorInstWord6;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint *codeWritePtr;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  uint *emitPtr2;
  
  vectorInstWord5 = *swizzle;
  iVar4 = 1;
  iVar5 = 1;
  vectorInstWord6 = (vectorInstWord5 & 0x3000000) << 4 | (vectorInstWord5 & 0x30000) << 8 | (vectorInstWord5 & 0x300) << 0xc |
          (vectorInstWord5 & 3) << 0x10;
  vectorInstWord7 = 0;
  vectorInstWord6 = vectorInstWord6 | vectorInstWord6 >> 0x10;
  do {
    if (((vectorInstWord6 >> (vectorInstWord7 * -4 + 0x1c & 0x3f)) + 1 & 3) == (vectorInstWord6 >> (vectorInstWord7 * -4 + 0x18 & 0x3f) & 3)
       ) {
      iVar1 = vectorInstWord7 * 4 + 8;
      iVar4 = 2;
      uVar10 = 0x20 - iVar1;
      uVar7 = 0x1c - iVar1;
      goto LAB_97bda1ac;
    }
    vectorInstWord7 = vectorInstWord7 + 1;
  } while ((int)vectorInstWord7 < 4);
  goto LAB_97bda240;
  while( true ) {
    iVar5 = iVar5 + 1;
    uVar11 = uVar11 - 4;
    uVar10 = uVar10 - 4;
    if (3 < iVar5) break;
LAB_97bda278:
    if ((vectorInstWord6 >> (uVar11 & 0x3f) & 3) != (vectorInstWord6 >> (uVar10 & 0x3f) & 3)) break;
  }
  if ((vectorInstWord8 == 0) && (iVar5 < 4)) {
    uVar11 = 0x10;
    uVar10 = 0xc;
    do {
      if ((vectorInstWord6 >> (uVar11 & 0x3f) & 3) != (vectorInstWord6 >> (uVar10 & 0x3f) & 3)) break;
      iVar5 = iVar5 + 1;
      vectorInstWord8 = vectorInstWord8 - 1 & 3;
      uVar11 = uVar11 + 4;
      uVar10 = uVar10 + 4;
    } while (iVar5 < 4);
  }
  goto LAB_97bda304;
  while( true ) {
    iVar4 = iVar4 + 1;
    uVar10 = uVar10 - 4;
    uVar7 = uVar7 - 4;
    if (3 < iVar4) break;
LAB_97bda1ac:
    if (((vectorInstWord6 >> (uVar10 & 0x3f)) + 1 & 3) != (vectorInstWord6 >> (uVar7 & 0x3f) & 3)) break;
  }
  if ((vectorInstWord7 == 0) && (iVar4 < 4)) {
    uVar10 = 0x10;
    uVar7 = 0xc;
    do {
      if (((vectorInstWord6 >> (uVar10 & 0x3f)) + 1 & 3) != (vectorInstWord6 >> (uVar7 & 0x3f) & 3)) break;
      iVar4 = iVar4 + 1;
      vectorInstWord7 = vectorInstWord7 - 1 & 3;
      uVar10 = uVar10 + 4;
      uVar7 = uVar7 + 4;
    } while (iVar4 < 4);
  }
LAB_97bda240:
  vectorInstWord8 = 0;
  do {
    if ((vectorInstWord6 >> (vectorInstWord8 * -4 + 0x1c & 0x3f) & 3) == (vectorInstWord6 >> (vectorInstWord8 * -4 + 0x18 & 0x3f) & 3)) {
      iVar1 = vectorInstWord8 * 4 + 8;
      iVar5 = 2;
      uVar11 = 0x20 - iVar1;
      uVar10 = 0x1c - iVar1;
      goto LAB_97bda278;
    }
    vectorInstWord8 = vectorInstWord8 + 1;
  } while ((int)vectorInstWord8 < 4);
LAB_97bda304:
  if (iVar5 == 4) {
    codeCursor = *(uint **)(compiler + 0xe30);
    *codeCursor = vectorReg << 0x15 | (vectorInstWord6 >> (vectorInstWord8 * -4 + 0x1c & 0x3f) & 0xf) << 0x10 | vectorReg << 0xb
              | 0x1000028c;
    *(uint **)(compiler + 0xe30) = codeCursor + 1;
    return;
  }
  if (iVar4 == 4) {
    vectorInstWord7 = (vectorInstWord5 & 0x3000000) >> 0x18;
    if (vectorInstWord7 == 0) {
      return;
    }
    vectorInstWord5 = vectorReg << 0x15 | vectorReg << 0x10 | vectorReg << 0xb;
    vectorInstWord7 = vectorInstWord7 << 8;
LAB_97bda710:
    codeWritePtr = *(uint **)(compiler + 0xe30);
    vectorInstWord7 = vectorInstWord5 | vectorInstWord7 & 0x300 | 0x1000002c;
LAB_97bdaabc:
    *codeWritePtr = vectorInstWord7;
  }
  else {
    if (iVar5 == 3) {
      vectorInstWord5 = vectorReg << 0xb;
      vectorInstWord7 = vectorInstWord6 >> (vectorInstWord8 * -4 + 0x10 & 0x3f);
      codeCursor = *(uint **)(compiler + 0xe30);
      *codeCursor = (vectorInstWord6 >> (vectorInstWord8 * -4 + 0x1c & 0x3f) & 0xf) << 0x10 | 0x600000 | vectorInstWord5 | 0x1000028c;
      *(uint **)(compiler + 0xe30) = codeCursor + 1;
      srcRegA = vectorReg;
      if ((vectorInstWord7 & 0xf) != 0) {
        srcRegA = 4;
        codeCursor[1] = vectorReg << 0x10 | 0x800000U | vectorInstWord5 | (vectorInstWord7 & 3) << 8 | 0x1000002c;
        *(uint **)(compiler + 0xe30) = codeCursor + 2;
      }
      codeCursor = *(uint **)(compiler + 0xe30);
      *codeCursor = vectorReg << 0x15 | 0x30000U | srcRegA << 0xb | 0x1000012c;
      codeWritePtr = codeCursor + 1;
      *(uint **)(compiler + 0xe30) = codeWritePtr;
      if (vectorInstWord8 == 0) {
        return;
      }
      vectorInstWord5 = vectorReg << 0x15 | vectorReg << 0x10 | vectorInstWord5;
      vectorInstWord7 = vectorInstWord8;
    }
    else {
      if (iVar4 != 3) {
        if (iVar5 == 2) {
          vectorInstWord5 = vectorReg << 0xb;
          vectorInstWord4 = vectorInstWord6 >> (vectorInstWord8 * -4 + 0x14 & 0x3f);
          vectorInstWord7 = vectorInstWord4 & 0xf;
          uVar10 = vectorInstWord6 >> (vectorInstWord8 * -4 + 0x10 & 0x3f) & 0xf;
          codeCursor = *(uint **)(compiler + 0xe30);
          *codeCursor = (vectorInstWord6 >> (vectorInstWord8 * -4 + 0x1c & 0x3f) & 0xf) << 0x10 | 0x600000 | vectorInstWord5 |
                    0x1000028c;
          emitPtr2 = codeCursor + 1;
          *(uint **)(compiler + 0xe30) = emitPtr2;
          if (uVar10 == (vectorInstWord7 + 1 & 3)) {
            srcRegA = vectorReg;
            if (vectorInstWord7 != 0) {
              srcRegA = 4;
              *emitPtr2 = vectorReg << 0x10 | 0x800000U | vectorInstWord5 | (vectorInstWord4 & 3) << 8 | 0x1000002c;
              *(uint **)(compiler + 0xe30) = codeCursor + 2;
            }
            codeCursor2 = *(uint **)(compiler + 0xe30);
            vectorInstWord7 = vectorReg << 0x15 | 0x30000U | srcRegA << 0xb | 0x1000022c;
LAB_97bda6e8:
            *codeCursor2 = vectorInstWord7;
            puVar9 = codeCursor2 + 1;
          }
          else {
            if (uVar10 != vectorInstWord7) {
              srcRegA = vectorReg;
              if (vectorInstWord7 != 0) {
                srcRegA = 4;
                *emitPtr2 = vectorReg << 0x10 | 0x800000U | vectorInstWord5 | (vectorInstWord4 & 3) << 8 | 0x1000002c;
                *(uint **)(compiler + 0xe30) = codeCursor + 2;
              }
              vectorInstWord6 = vectorInstWord6 >> (vectorInstWord8 * -4 + 0x10 & 0x3f);
              codeCursor = *(uint **)(compiler + 0xe30);
              *codeCursor = srcRegA << 0xb | 0x1063012c;
              *(uint **)(compiler + 0xe30) = codeCursor + 1;
              srcRegA = vectorReg;
              if ((vectorInstWord6 & 0xf) != 0) {
                srcRegA = 4;
                codeCursor[1] = vectorReg << 0x10 | 0x800000U | vectorInstWord5 | (vectorInstWord6 & 3) << 8 | 0x1000002c;
                *(uint **)(compiler + 0xe30) = codeCursor + 2;
              }
              codeCursor2 = *(uint **)(compiler + 0xe30);
              vectorInstWord7 = vectorReg << 0x15 | 0x30000U | srcRegA << 0xb | 0x1000012c;
              goto LAB_97bda6e8;
            }
            puVar9 = codeCursor + 3;
            codeCursor[2] = vectorReg << 0x15 | 0x1003222c;
            *emitPtr2 = vectorInstWord7 << 0x10 | 0x800000 | vectorInstWord5 | 0x1000028c;
          }
          *(uint **)(compiler + 0xe30) = puVar9;
          if (vectorInstWord8 == 0) {
            return;
          }
          vectorInstWord5 = vectorReg << 0x15 | vectorReg << 0x10 | vectorInstWord5;
          vectorInstWord7 = vectorInstWord8;
LAB_97bda70c:
          vectorInstWord7 = (4 - vectorInstWord7) * 0x100;
          goto LAB_97bda710;
        }
        if (iVar4 == 2) {
          uVar2 = vectorInstWord6 >> (vectorInstWord7 * -4 + 0x1c & 0x3f) & 0xf;
          srcRegA = vectorReg;
          if (uVar2 != 2) {
            codeCursor = *(uint **)(compiler + 0xe30);
            srcRegA = 3;
            *codeCursor = vectorReg << 0x10 | 0x600000U | vectorReg << 0xb | (uVar2 * 4 + 8) * 0x40 & 0x300
                      | 0x1000002c;
            *(uint **)(compiler + 0xe30) = codeCursor + 1;
          }
          uVar10 = vectorInstWord6 >> (vectorInstWord7 * -4 + 0x14 & 0x3f);
          vectorInstWord5 = uVar10 & 0xf;
          uVar7 = vectorInstWord6 >> (vectorInstWord7 * -4 + 0x10 & 0x3f) & 0xf;
          if (uVar7 == (vectorInstWord5 + 1 & 3)) {
            srcRegB = vectorReg;
            if (vectorInstWord5 != 0) {
              codeCursor = *(uint **)(compiler + 0xe30);
              srcRegB = 4;
              *codeCursor = vectorReg << 0x10 | 0x800000U | vectorReg << 0xb | (uVar10 & 3) << 8 |
                        0x1000002c;
              *(uint **)(compiler + 0xe30) = codeCursor + 1;
            }
            codeWritePtr = *(uint **)(compiler + 0xe30);
            *codeWritePtr = vectorReg << 0x15 | srcRegA << 0x10 | srcRegB << 0xb | 0x1000022c;
LAB_97bda854:
            *(uint **)(compiler + 0xe30) = codeWritePtr + 1;
          }
          else {
            if (uVar7 == vectorInstWord5) {
              codeCursor = *(uint **)(compiler + 0xe30);
              *codeCursor = vectorInstWord5 << 0x10 | 0x800000 | vectorReg << 0xb | 0x1000028c;
              codeWritePtr = codeCursor + 1;
              *codeWritePtr = vectorReg << 0x15 | srcRegA << 0x10 | 0x1000222c;
              goto LAB_97bda854;
            }
            srcRegB = vectorReg;
            if (vectorInstWord5 != 0) {
              codeCursor = *(uint **)(compiler + 0xe30);
              srcRegB = 4;
              *codeCursor = vectorReg << 0x10 | 0x800000U | vectorReg << 0xb | (uVar10 & 3) << 8 |
                        0x1000002c;
              *(uint **)(compiler + 0xe30) = codeCursor + 1;
            }
            vectorInstWord6 = vectorInstWord6 >> (vectorInstWord7 * -4 + 0x10 & 0x3f);
            codeCursor = *(uint **)(compiler + 0xe30);
            *codeCursor = srcRegA << 0x10 | srcRegB << 0xb | 0x1060012c;
            *(uint **)(compiler + 0xe30) = codeCursor + 1;
            srcRegA = vectorReg;
            if ((vectorInstWord6 & 0xf) != 0) {
              srcRegA = 4;
              codeCursor[1] = vectorReg << 0x10 | 0x800000U | vectorReg << 0xb | (vectorInstWord6 & 3) << 8 |
                          0x1000002c;
              *(uint **)(compiler + 0xe30) = codeCursor + 2;
            }
            codeCursor = *(uint **)(compiler + 0xe30);
            *codeCursor = vectorReg << 0x15 | 0x30000U | srcRegA << 0xb | 0x1000012c;
            *(uint **)(compiler + 0xe30) = codeCursor + 1;
          }
          if (vectorInstWord7 == 0) {
            return;
          }
          vectorInstWord5 = vectorReg << 0x15 | vectorReg << 0x10 | vectorReg << 0xb;
          goto LAB_97bda70c;
        }
        uVar6 = (vectorInstWord5 & 0x3000000) >> 0x18;
        srcRegA = vectorReg;
        if (uVar6 != 3) {
          codeCursor = *(uint **)(compiler + 0xe30);
          srcRegA = 3;
          *codeCursor = vectorReg << 0x10 | 0x600000U | vectorReg << 0xb | (uVar6 * 4 + 4) * 0x40 & 0x300 |
                    0x1000002c;
          *(uint **)(compiler + 0xe30) = codeCursor + 1;
        }
        srcRegB = vectorReg;
        if ((vectorInstWord5 & 0x30000) != 0) {
          codeCursor = *(uint **)(compiler + 0xe30);
          srcRegB = 4;
          *codeCursor = vectorReg << 0x10 | 0x800000U | vectorReg << 0xb | ((vectorInstWord5 & 0x30000) >> 0x10) << 8
                    | 0x1000002c;
          *(uint **)(compiler + 0xe30) = codeCursor + 1;
        }
        codeCursor = *(uint **)(compiler + 0xe30);
        *codeCursor = srcRegA << 0x10 | srcRegB << 0xb | 0x1060012c;
        *(uint **)(compiler + 0xe30) = codeCursor + 1;
        srcRegA = vectorReg;
        if ((vectorInstWord5 & 0x300) != 0) {
          srcRegA = 4;
          codeCursor[1] = vectorReg << 0x10 | 0x800000U | vectorReg << 0xb | vectorInstWord5 & 0x300 | 0x1000002c;
          *(uint **)(compiler + 0xe30) = codeCursor + 2;
        }
        codeCursor = *(uint **)(compiler + 0xe30);
        *codeCursor = srcRegA << 0xb | 0x1063012c;
        *(uint **)(compiler + 0xe30) = codeCursor + 1;
        srcRegA = vectorReg;
        if ((vectorInstWord5 & 3) != 0) {
          srcRegA = 4;
          codeCursor[1] = vectorReg << 0x10 | 0x800000U | vectorReg << 0xb | (vectorInstWord5 & 3) << 8 | 0x1000002c;
          *(uint **)(compiler + 0xe30) = codeCursor + 2;
        }
        codeWritePtr = *(uint **)(compiler + 0xe30);
        vectorInstWord7 = vectorReg << 0x15 | 0x30000U | srcRegA << 0xb | 0x1000012c;
        goto LAB_97bdaabc;
      }
      uVar2 = vectorInstWord6 >> (vectorInstWord7 * -4 + 0x1c & 0x3f) & 0xf;
      srcRegA = vectorReg;
      if (uVar2 != 1) {
        codeCursor = *(uint **)(compiler + 0xe30);
        srcRegA = 3;
        *codeCursor = vectorReg << 0x10 | 0x600000U | vectorReg << 0xb | (uVar2 * 4 + 0xc) * 0x40 & 0x300 |
                  0x1000002c;
        *(uint **)(compiler + 0xe30) = codeCursor + 1;
      }
      vectorInstWord6 = vectorInstWord6 >> (vectorInstWord7 * -4 + 0x10 & 0x3f);
      srcRegB = vectorReg;
      if ((vectorInstWord6 & 0xf) != 0) {
        codeCursor = *(uint **)(compiler + 0xe30);
        srcRegB = 4;
        *codeCursor = vectorReg << 0x10 | 0x800000U | vectorReg << 0xb | (vectorInstWord6 & 3) << 8 | 0x1000002c;
        *(uint **)(compiler + 0xe30) = codeCursor + 1;
      }
      codeCursor = *(uint **)(compiler + 0xe30);
      *codeCursor = vectorReg << 0x15 | srcRegA << 0x10 | srcRegB << 0xb | 0x1000012c;
      codeWritePtr = codeCursor + 1;
      *(uint **)(compiler + 0xe30) = codeWritePtr;
      if (vectorInstWord7 == 0) {
        return;
      }
      vectorInstWord5 = vectorReg << 0x15 | vectorReg << 0x10 | vectorReg << 0xb;
    }
    *codeWritePtr = vectorInstWord5 | (4 - vectorInstWord7) * 0x100 & 0x300 | 0x1000002c;
  }
  *(uint **)(compiler + 0xe30) = codeWritePtr + 1;
  return;
}

/* _PPCRuntimeCompilerFindVariableInfo @ 0x97bdaac8 (88 bytes) */
int _PPCRuntimeCompilerFindVariableInfo(compiler, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int compiler;
  int param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  int *piVar1;
  uint loopIndex;
  
  loopIndex = 0;
  piVar1 = *(int **)(compiler + 0xe00);
  if (*(uint *)(compiler + 0xe04) != 0) {
    do {
      if (param_2 == *piVar1) {
        return piVar1;
      }
      loopIndex = loopIndex + 1;
      piVar1 = piVar1 + 2;
    } while (loopIndex < *(uint *)(compiler + 0xe04));
  }
  return (int *)0x0;
}

/* _PPCRuntimeCompilerLoadSourceNO @ 0x97bdab20 (348 bytes) */
int _PPCRuntimeCompilerLoadSourceNO(compiler, opOffsets, opBank, opSwizzle, opIndexInfo, opStorage, opFlags5, opType, opWord7, opWord8, element, sourceSlot)
  int compiler;
  undefined4 opOffsets;
  undefined4 opBank;
  undefined4 opSwizzle;
  undefined4 opIndexInfo;
  undefined4 opStorage;
  undefined4 opFlags5;
  undefined4 opType;
  undefined4 opWord7;
  undefined4 opWord8;
  undefined4 element;
  int sourceSlot;
{
  int chunkIndex;
  uint loopIndex;
  int iVar1;
  undefined *puVar2;
  undefined4 codeCursor;
  int iVar4;
  uint loopIndex2;
  uint uVar6;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  iVar1 = sourceSlot * 4;
  uStack0000001c = opOffsets;
  uStack00000020 = opBank;
  uStack00000024 = opSwizzle;
  uStack00000028 = opIndexInfo;
  uStack0000002c = opStorage;
  uStack00000030 = opFlags5;
  uStack00000034 = opType;
  if ((*(uint *)(compiler + 0xe50) & 4) != 0) {
    loopIndex = 0;
    do {
      iVar4 = iVar1 + loopIndex;
      _PPCRuntimeCompilerBackupRegister(compiler,iVar4);
      loopIndex = loopIndex + 1;
      _PPCRuntimeCompilerDirtyRegister(compiler,iVar4);
    } while (loopIndex < 4);
  }
  loopIndex2 = 0;
  do {
    uVar6 = loopIndex2 + 1;
    _PPCRuntimeCompilerLoadRegister
              (compiler,iVar1 + loopIndex2,uStack0000001c,uStack00000020,uStack00000024,uStack00000028,
               uStack0000002c,uStack00000030,uStack00000034,opWord7,opWord8,loopIndex2);
    loopIndex2 = uVar6;
  } while (uVar6 < 4);
  if ((*(unsigned char *)((unsigned char *)&(uStack0000002c) + 2)) == '\0') {
    return;
  }
  if (sourceSlot == 0) {
    codeCursor = *(undefined4 *)(compiler + 0xe30);
    puVar2 = &_glpNegateSourceARTC;
  }
  else if (sourceSlot == 1) {
    codeCursor = *(undefined4 *)(compiler + 0xe30);
    puVar2 = &_glpNegateSourceBRTC;
  }
  else {
    if (sourceSlot != 2) goto LAB_97bdac4c;
    codeCursor = *(undefined4 *)(compiler + 0xe30);
    puVar2 = &_glpNegateSourceCRTC;
  }
  chunkIndex = _glpRTCAddAChunk_97bd7cbc(puVar2,codeCursor);
  *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + chunkIndex * 4;
LAB_97bdac4c:
  loopIndex = 0;
  do {
    iVar4 = iVar1 + loopIndex;
    loopIndex = loopIndex + 1;
    _PPCRuntimeCompilerDirtyRegister(compiler,iVar4);
  } while (loopIndex < 4);
  return;
}

/* _PPCRuntimeCompilerLoadSourceAV @ 0x97bdac7c (268 bytes) */
int _PPCRuntimeCompilerLoadSourceAV(compiler, opOffsets, opBank, opSwizzle, opIndexInfo, opStorage, opFlags5, opType, opWord7, opWord8, element, sourceSlot)
  int compiler;
  int opOffsets;
  undefined4 opBank;
  undefined4 opSwizzle;
  undefined4 opIndexInfo;
  undefined4 opStorage;
  undefined4 opFlags5;
  undefined4 opType;
  undefined4 opWord7;
  undefined4 opWord8;
  int element;
  int sourceSlot;
{
  uint *codeCursor;
  int iStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  iStack0000001c = opOffsets;
  uStack00000020 = opBank;
  uStack00000024 = opSwizzle;
  uStack00000028 = opIndexInfo;
  uStack0000002c = opStorage;
  uStack00000030 = opFlags5;
  uStack00000034 = opType;
  if ((*(uint *)(compiler + 0xe50) & 4) != 0) {
    _PPCRuntimeCompilerBackupRegister(compiler,sourceSlot);
    _PPCRuntimeCompilerDirtyRegister(compiler,sourceSlot);
  }
  iStack0000001c = iStack0000001c + element * 0x10;
  _PPCRuntimeCompilerLoadRegister
            (compiler,sourceSlot,iStack0000001c,uStack00000020,uStack00000024,uStack00000028,
             uStack0000002c,uStack00000030,uStack00000034,opWord7,opWord8,0);
  if ((*(unsigned char *)((unsigned char *)&(uStack0000002c) + 2)) != '\0') {
    codeCursor = *(uint **)(compiler + 0xe30);
    *codeCursor = sourceSlot << 0x15 | sourceSlot << 0x10 | 0x10003cc4;
    *(uint **)(compiler + 0xe30) = codeCursor + 1;
    _PPCRuntimeCompilerDirtyRegister(compiler,sourceSlot);
    return;
  }
  return;
}

/* _PPCRuntimeCompilerWriteDestinationNO @ 0x97bdad88 (368 bytes) */
int _PPCRuntimeCompilerWriteDestinationNO(compiler, param_2)
  int compiler;
  int param_2;
{
  uint *codeCursor;
  uint uVar2;
  uint loopIndex;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  
  _memcpy(&local_50,*(int *)(compiler + 0xe28) + 0xc,0x24);
  uVar2 = 0x2000000;
  _PPCRuntimeCompilerDirtyRegister(compiler,0x10);
  _PPCRuntimeCompilerDirtyRegister(compiler,0x11);
  _PPCRuntimeCompilerDirtyRegister(compiler,0x12);
  _PPCRuntimeCompilerDirtyRegister(compiler,0x13);
  loopIndex = 0;
  do {
    if (((*(unsigned char *)((unsigned char *)&(local_34) + 0)) >> (loopIndex & 0x3f) & 1) != 0) {
      if (((*(unsigned short *)((unsigned char *)&(local_40) + 0)) == 1) || ((*(uint *)(compiler + 0xe50) & 4) == 0)) {
        codeCursor = *(uint **)(compiler + 0xe30);
        *codeCursor = uVar2 | (uint)(ushort)((*(unsigned short *)((unsigned char *)&(local_40) + 0)) + 5) << 0x10 |
                  *(uint *)(loopIndex * 4 + local_50 + param_2 * 0x10) & 0xffff | 0xd0000000;
        *(uint **)(compiler + 0xe30) = codeCursor + 1;
      }
      else {
        _PPCRuntimeCompilerDirtyRegistersWithData
                  (compiler,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38,local_34,
                   local_30,loopIndex);
        _PPCRuntimeCompilerSetRegister
                  (compiler,loopIndex + 0x10,local_50,local_4c,local_48,local_44,local_40,local_3c,
                   local_38,local_34,local_30,0,loopIndex);
      }
    }
    loopIndex = loopIndex + 1;
    uVar2 = uVar2 + 0x200000;
  } while (loopIndex < 4);
  return;
}

/* _PPCRuntimeCompilerWriteDestinationAV @ 0x97bdaef8 (748 bytes) */
int _PPCRuntimeCompilerWriteDestinationAV(compiler, param_2)
  int compiler;
  int param_2;
{
  undefined4 *codeWritePtr;
  undefined4 *codeCursor;
  int instruction;
  undefined4 vectorInstWord2;
  undefined4 extraout_r4;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 *puVar2;
  undefined4 in_r10;
  int codeCursor2;
  int vectorInstWord;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  undefined4 local_30;
  
  instruction = *(int *)(compiler + 0xe28);
  _memcpy(&local_50,instruction + 0xc,0x24);
  local_50 = local_50 + param_2 * 0x10;
  _PPCRuntimeCompilerDirtyRegister(compiler,2);
  puVar2 = &local_48;
  ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(compiler,2,puVar2);
  _PPEmulatorVariableSwizzleFromMask(&local_50,extraout_r4,puVar2,in_r6,in_r7,in_r8,in_r9,in_r10);
  if (*(char *)(instruction + 6) != '\0') {
    vectorInstWord = _glpRTCAddAChunk_97bd7cbc
                      (&_glpOpBuildConditionCodeAVRTC,*(undefined4 *)(compiler + 0xe30));
    codeCursor2 = *(int *)(compiler + 0xe30);
    vectorInstWord = vectorInstWord * 4;
    codeWritePtr = (undefined4 *)(codeCursor2 + vectorInstWord);
    *(undefined4 **)(compiler + 0xe30) = codeWritePtr;
    if ((*(unsigned char *)((unsigned char *)&(local_34) + 0)) == '\x0f') {
      *(undefined4 *)(codeCursor2 + vectorInstWord) = 0x12852c84;
    }
    else {
      *(undefined4 *)(codeCursor2 + vectorInstWord) = 0x10836a8c;
      *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 2;
      vectorInstWord2 = 0x1063212c;
      if ((local_34 & 0x1000000) == 0) {
        vectorInstWord2 = 0x1063492c;
      }
      codeWritePtr[1] = vectorInstWord2;
      codeCursor = *(undefined4 **)(compiler + 0xe30);
      vectorInstWord2 = 0x1063212c;
      *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
      if ((local_34 & 0x2000000) == 0) {
        vectorInstWord2 = 0x1063492c;
      }
      *codeCursor = vectorInstWord2;
      codeCursor = *(undefined4 **)(compiler + 0xe30);
      vectorInstWord2 = 0x1063212c;
      *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
      if ((local_34 & 0x4000000) == 0) {
        vectorInstWord2 = 0x1063492c;
      }
      *codeCursor = vectorInstWord2;
      codeCursor = *(undefined4 **)(compiler + 0xe30);
      vectorInstWord2 = 0x1063212c;
      *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
      if ((local_34 & 0x8000000) == 0) {
        vectorInstWord2 = 0x1063492c;
      }
      *codeCursor = vectorInstWord2;
      codeWritePtr = *(undefined4 **)(compiler + 0xe30);
      *codeWritePtr = 0x129428ea;
    }
    *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 1;
  }
  if ((char)local_40 != '\0') {
    _PPCRuntimeCompilerSaveAllTemporariesToMemory(compiler);
  }
  if (((((*(unsigned short *)((unsigned char *)&(local_40) + 0)) == 1) || ((*(unsigned short *)((unsigned char *)&(local_40) + 0)) == 9)) || ((*(uint *)(compiler + 0xe50) & 4) == 0))
     || ((local_40 & 0xff) != 0)) {
    _PPCRuntimeCompilerSetRegister
              (compiler,2,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38,local_34,
               local_30,0,0);
    _PPCRuntimeCompilerSaveRegisterToMemory(compiler,2);
    _PPCRuntimeCompilerDirtyRegistersWithData
              (compiler,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38,local_34,
               local_30,0);
  }
  else {
    _PPCRuntimeCompilerDirtyRegistersWithData
              (compiler,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38,local_34,
               local_30,0);
    _PPCRuntimeCompilerSetRegister
              (compiler,2,local_50,local_4c,local_48,local_44,local_40,local_3c,local_38,local_34,
               local_30,0,0);
  }
  return;
}

/* _PPCRuntimeCompilerTestConditionRegisterAV @ 0x97bdb1e4 (576 bytes) */
int _PPCRuntimeCompilerTestConditionRegisterAV(compiler, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9)
  int compiler;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  uint param_9;
{
  uint *codeCursor2;
  uint vectorInstWord;
  undefined4 *codeCursor;
  uint *codeWritePtr;
  undefined4 uStack0000001c;
  undefined4 uStack00000020;
  undefined4 uStack00000024;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  
  uStack0000001c = param_2;
  uStack00000020 = param_3;
  uStack00000024 = param_4;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  switch(param_9 >> 0x10 & 0xff) {
  case 0:
    codeWritePtr = *(uint **)(compiler + 0xe30);
    vectorInstWord = 0x10636a8c;
    goto LAB_97bdb424;
  case 1:
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x10b4a484;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(compiler,5,(int)&param_9 + 2);
    codeCursor2 = *(uint **)(compiler + 0xe30);
    vectorInstWord = 0x10600000;
    break;
  case 2:
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x10b4a484;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(compiler,5,(int)&param_9 + 2);
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    vectorInstWord = 0x10810000;
    goto LAB_97bdb338;
  case 3:
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x10b4a484;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(compiler,5,(int)&param_9 + 2);
    codeCursor2 = *(uint **)(compiler + 0xe30);
    vectorInstWord = 0x10610000;
    break;
  case 4:
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x10b4a484;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(compiler,5,(int)&param_9 + 2);
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    vectorInstWord = 0x10820000;
LAB_97bdb338:
    *codeCursor = 0x1060038c;
    codeCursor[1] = vectorInstWord | 0x38c;
    codeCursor[2] = 0x10651886;
    codeCursor[3] = 0x10852086;
    codeCursor[4] = 0x10632484;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 5;
    return;
  case 5:
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x10b4a484;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(compiler,5,(int)&param_9 + 2);
    codeCursor2 = *(uint **)(compiler + 0xe30);
    vectorInstWord = 0x10620000;
    break;
  case 6:
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x10b4a484;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
    ((int (*)())_PPCRuntimeCompilerSwizzleRegisterAV)(compiler,5,(int)&param_9 + 2);
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x1060038c;
    codeCursor[1] = 0x10651886;
    codeWritePtr = codeCursor + 3;
    codeCursor[2] = 0x10631d04;
    goto LAB_97bdb42c;
  case 7:
    codeWritePtr = *(uint **)(compiler + 0xe30);
    vectorInstWord = 0x10694c84;
LAB_97bdb424:
    *codeWritePtr = vectorInstWord;
    goto LAB_97bdb428;
  default:
    goto switchD_97bdb240_default;
  }
  *codeCursor2 = vectorInstWord | 0x38c;
  codeWritePtr = codeCursor2 + 1;
  *codeWritePtr = 0x10651886;
LAB_97bdb428:
  codeWritePtr = codeWritePtr + 1;
LAB_97bdb42c:
  *(uint **)(compiler + 0xe30) = codeWritePtr;
switchD_97bdb240_default:
  return;
}

/* _PPCRuntimeCompilerWriteFinalFragmentToBuffer @ 0x97bdb444 (568 bytes) */
int _PPCRuntimeCompilerWriteFinalFragmentToBuffer(compiler, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int compiler;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  undefined4 ppcRasterOpMachine_BufferMaskRTCAVResult;
  undefined4 ppcRasterOpMachine_LogicOpRTCAVResult;
  undefined4 ppcRasterOpMachine_BlendingRTCAVResult;
  undefined4 ppcRasterOpMachine_DepthAndStencilTestRTCAVResult;
  undefined4 *codeWritePtr2;
  int codeWritePtr;
  undefined4 *codeCursor;
  int chunkIndex;
  bool bVar1;
  bool bVar2;
  undefined4 ppcRasterOpMachine_AlphaTestRTCAVResult;
  uint framebufferFormat;
  undefined4 *puVar5;
  int iVar6;
  
  iVar6 = *(int *)(compiler + 0xe20);
  bVar1 = false;
  if (((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 0x40) != 0) &&
     ((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x70) & 0x1e0000) != 0x1e0000)) {
    bVar1 = true;
  }
  bVar2 = false;
  if (((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 0x20) != 0) &&
     (3 < (*(uint *)(*(int *)(iVar6 + 0xd80) + 0x68) & 0xf))) {
    bVar2 = true;
  }
  if ((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 1) != 0) {
    ppcRasterOpMachine_AlphaTestRTCAVResult = ((int (*)())_PPCRasterOpMachine_AlphaTestRTCAV)(compiler + 0xe14,*(undefined4 *)(compiler + 0xe30));
    iVar6 = *(int *)(compiler + 0xe20);
    *(undefined4 *)(compiler + 0xe30) = ppcRasterOpMachine_AlphaTestRTCAVResult;
  }
  if ((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 6) != 0) {
    ppcRasterOpMachine_DepthAndStencilTestRTCAVResult = ((int (*)())_PPCRasterOpMachine_DepthAndStencilTestRTCAV)(compiler + 0xe14,*(undefined4 *)(compiler + 0xe30));
    iVar6 = *(int *)(compiler + 0xe20);
    *(undefined4 *)(compiler + 0xe30) = ppcRasterOpMachine_DepthAndStencilTestRTCAVResult;
  }
  if ((((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 8) != 0) || (bVar2)) || (bVar1)) {
    framebufferFormat = _PPEmulatorFramebufferFormat(iVar6);
    if ((framebufferFormat & 0x8000) == 0) {
      framebufferFormat = _PPEmulatorFramebufferFormat(*(undefined4 *)(compiler + 0xe20));
      if ((framebufferFormat & 0x8000000) != 0) {
        codeCursor = *(undefined4 **)(compiler + 0xe30);
        *codeCursor = 0x7c4030ce;
        *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
      }
    }
    else {
      codeWritePtr = _glpRTCAddAChunk_97bd7cbc
                        (&_glpOpConvertARGB8888ToRGBAFFFF,*(undefined4 *)(compiler + 0xe30));
      *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + codeWritePtr * 4;
    }
    iVar6 = *(int *)(compiler + 0xe20);
  }
  if ((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 8) != 0) {
    ppcRasterOpMachine_BlendingRTCAVResult = ((int (*)())_PPCRasterOpMachine_BlendingRTCAV)(compiler + 0xe14,*(undefined4 *)(compiler + 0xe30));
    iVar6 = *(int *)(compiler + 0xe20);
    *(undefined4 *)(compiler + 0xe30) = ppcRasterOpMachine_BlendingRTCAVResult;
  }
  if ((*(uint *)(*(int *)(iVar6 + 0xd80) + 0x3c) & 0x20) != 0) {
    ppcRasterOpMachine_LogicOpRTCAVResult = ((int (*)())_PPCRasterOpMachine_LogicOpRTCAV)(compiler + 0xe14,*(undefined4 *)(compiler + 0xe30));
    *(undefined4 *)(compiler + 0xe30) = ppcRasterOpMachine_LogicOpRTCAVResult;
  }
  if (bVar1) {
    ppcRasterOpMachine_BufferMaskRTCAVResult = ((int (*)())_PPCRasterOpMachine_BufferMaskRTCAV)(compiler + 0xe14,*(undefined4 *)(compiler + 0xe30));
    *(undefined4 *)(compiler + 0xe30) = ppcRasterOpMachine_BufferMaskRTCAVResult;
  }
  framebufferFormat = _PPEmulatorFramebufferFormat(*(undefined4 *)(compiler + 0xe20));
  if ((framebufferFormat & 0x8000) == 0) {
    framebufferFormat = _PPEmulatorFramebufferFormat(*(undefined4 *)(compiler + 0xe20));
    if ((framebufferFormat & 0x8000000) == 0) {
      return;
    }
    codeWritePtr2 = *(undefined4 **)(compiler + 0xe30);
    *codeWritePtr2 = 0x7e6031ce;
  }
  else {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x10739c84;
    puVar5 = codeCursor + 1;
    *(undefined4 **)(compiler + 0xe30) = puVar5;
    chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpConvertRGBAFFFFToARGB8888,puVar5);
    codeWritePtr2 = (undefined4 *)(*(int *)(compiler + 0xe30) + chunkIndex * 4);
    *(undefined4 *)(*(int *)(compiler + 0xe30) + chunkIndex * 4) = 0x7c60318e;
  }
  *(undefined4 **)(compiler + 0xe30) = codeWritePtr2 + 1;
  return;
}

/* _PPCRuntimeCompilerWritePrologNO @ 0x97bdb67c (828 bytes) */
int _PPCRuntimeCompilerWritePrologNO(compiler)
  int compiler;
{
  int ppcInstWord;
  int fieldInstWord;
  int codeCursor3;
  int chunkIndex;
  uint *codeCursor2;
  undefined4 *codeCursor;
  uint fieldInstWord2;
  int *piVar4;
  int iVar5;
  uint fieldInstWord3;
  int iVar7;
  
  iVar7 = 0x13;
  fieldInstWord = 0xd;
  fieldInstWord2 = 0x284;
  do {
    if ((fieldInstWord != 0x10) || ((*(uint *)(*(int *)(compiler + 0xe24) + 0x34) & 0x200) != 0)) {
      codeCursor2 = *(uint **)(compiler + 0xe30);
      *codeCursor2 = fieldInstWord << 0x15 | fieldInstWord2 & 0xffff | 0x90030000;
      *(uint **)(compiler + 0xe30) = codeCursor2 + 1;
    }
    fieldInstWord = fieldInstWord + 1;
    fieldInstWord2 = fieldInstWord2 + 4;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  fieldInstWord3 = 0xe;
  iVar5 = 0x12;
  fieldInstWord2 = 0x308;
  piVar4 = (int *)(compiler + 0x33c);
  do {
    if ((fieldInstWord3 < 0x14) || (*piVar4 != 0)) {
      codeCursor2 = *(uint **)(compiler + 0xe30);
      *codeCursor2 = fieldInstWord3 << 0x15 | fieldInstWord2 & 0xffff | 0xd0030000;
      *(uint **)(compiler + 0xe30) = codeCursor2 + 1;
    }
    fieldInstWord3 = fieldInstWord3 + 1;
    piVar4 = piVar4 + 0xe;
    fieldInstWord2 = fieldInstWord2 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if ((*(uint *)(*(int *)(compiler + 0xe24) + 0x34) & 0x400) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0xfd00048e;
    codeCursor[1] = 0xd1030350;
    codeCursor[2] = 0xffc0004c;
    codeCursor[3] = 0xffe0004c;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 4;
  }
  codeCursor = *(undefined4 **)(compiler + 0xe30);
  *codeCursor = 0x80430d9c;
  iVar5 = *(int *)(compiler + 0xe24);
  *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  if ((*(uint *)(iVar5 + 0x34) & 1) != 0) {
    codeCursor[1] = 0x80a30d84;
    iVar5 = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
  }
  if ((*(uint *)(iVar5 + 0x34) & 2) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x80c30d88;
    iVar5 = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  if ((*(uint *)(iVar5 + 0x34) & 4) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x80e30d8c;
    iVar5 = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  if ((*(uint *)(iVar5 + 0x34) & 8) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x81030d90;
    iVar5 = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  if ((*(uint *)(iVar5 + 0x34) & 0x10) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x81230d94;
    iVar5 = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  if ((*(uint *)(iVar5 + 0x34) & 0x20) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x81430d98;
    iVar5 = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  if (((*(int *)(iVar5 + 0x38) == 0x8804) || (*(int *)(iVar5 + 0x38) == 0x8b30)) &&
     ((*(uint *)(iVar5 + 0x34) & 0x1004) != 0)) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x81830da4;
    codeCursor[1] = 0x81a30da0;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
  }
  chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpLoadOneAndZeroRTC,*(undefined4 *)(compiler + 0xe30));
  codeCursor3 = *(int *)(compiler + 0xe30);
  *(undefined4 *)(codeCursor3 + chunkIndex * 4) = 0x7c8903a6;
  ppcInstWord = codeCursor3 + chunkIndex * 4;
  iVar7 = *(int *)(compiler + 0xe24);
  *(int *)(compiler + 0xe30) = ppcInstWord + 4;
  if ((*(int *)(iVar7 + 0x38) != 0x8804) && (*(int *)(iVar7 + 0x38) != 0x8b30)) {
    *(undefined4 *)(ppcInstWord + 4) = 0x3a2000ff;
    *(undefined4 *)(ppcInstWord + 8) = 0x3a400000;
    iVar7 = *(int *)(compiler + 0xe24);
    *(int *)(compiler + 0xe30) = ppcInstWord + 0xc;
  }
  if ((*(int *)(iVar7 + 0x38) == 0x8804) || (*(int *)(iVar7 + 0x38) == 0x8b30)) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0xfd805890;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  return;
}

/* _PPCRuntimeCompilerWriteEpilogNO @ 0x97bdb9b8 (352 bytes) */
int _PPCRuntimeCompilerWriteEpilogNO(compiler)
  int compiler;
{
  int fieldInstWord;
  undefined4 *codeCursor;
  int iVar2;
  uint *codeCursor2;
  uint fieldInstWord2;
  int *piVar5;
  uint fieldInstWord3;
  int iVar7;
  
  iVar2 = *(int *)(compiler + 0xe24);
  if ((*(int *)(iVar2 + 0x38) != 0x8804) && (*(int *)(iVar2 + 0x38) != 0x8b30)) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x39e00008;
    codeCursor[1] = 0x7e317830;
    codeCursor[2] = 0x7e259378;
    iVar2 = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 3;
  }
  if ((*(uint *)(iVar2 + 0x34) & 0x400) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0xc1030350;
    codeCursor[1] = 0xfdfe458e;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
  }
  fieldInstWord = 0xd;
  iVar7 = 0x13;
  fieldInstWord2 = 0x284;
  do {
    if ((fieldInstWord != 0x10) || ((*(uint *)(*(int *)(compiler + 0xe24) + 0x34) & 0x200) != 0)) {
      codeCursor2 = *(uint **)(compiler + 0xe30);
      *codeCursor2 = fieldInstWord << 0x15 | fieldInstWord2 & 0xffff | 0x80030000;
      *(uint **)(compiler + 0xe30) = codeCursor2 + 1;
    }
    fieldInstWord = fieldInstWord + 1;
    fieldInstWord2 = fieldInstWord2 + 4;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  fieldInstWord3 = 0xe;
  iVar2 = 0x12;
  fieldInstWord2 = 0x308;
  piVar5 = (int *)(compiler + 0x33c);
  do {
    if ((fieldInstWord3 < 0x14) || (*piVar5 != 0)) {
      codeCursor2 = *(uint **)(compiler + 0xe30);
      *codeCursor2 = fieldInstWord3 << 0x15 | fieldInstWord2 & 0xffff | 0xc0030000;
      *(uint **)(compiler + 0xe30) = codeCursor2 + 1;
    }
    fieldInstWord3 = fieldInstWord3 + 1;
    piVar5 = piVar5 + 0xe;
    fieldInstWord2 = fieldInstWord2 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  codeCursor = *(undefined4 **)(compiler + 0xe30);
  *codeCursor = 0x7ca32b78;
  codeCursor[1] = 0x4e800020;
  *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
  return;
}

/* _PPCRuntimeCompilerWritePrologAV @ 0x97bdbb18 (1132 bytes) */
int _PPCRuntimeCompilerWritePrologAV(compiler)
  int compiler;
{
  int fieldInstWord;
  undefined4 *codeCursor;
  uint framebufferFormat;
  int chunkIndex;
  undefined4 *puVar1;
  uint *codeCursor2;
  undefined4 *vectorInstWord;
  uint fieldInstWord2;
  int codeCursor3;
  int ppcInstWord;
  int iVar7;
  int iVar8;
  
  codeCursor = *(undefined4 **)(compiler + 0xe30);
  *codeCursor = 0x7c0042a6;
  iVar7 = 0x20;
  *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  do {
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  codeCursor = *(undefined4 **)(compiler + 0xe30);
  *codeCursor = 0x6405ffff;
  codeCursor[1] = 0x60a5ffff;
  codeCursor[2] = 0x7ca043a6;
  codeCursor[3] = 0x10ff038c;
  iVar8 = 0x13;
  codeCursor[4] = 0x10e73984;
  fieldInstWord = 0xd;
  *(undefined4 **)(compiler + 0xe30) = codeCursor + 5;
  fieldInstWord2 = 0x284;
  do {
    if ((fieldInstWord != 0x10) || ((*(uint *)(*(int *)(compiler + 0xe24) + 0x34) & 0x200) != 0)) {
      codeCursor2 = *(uint **)(compiler + 0xe30);
      *codeCursor2 = fieldInstWord << 0x15 | fieldInstWord2 & 0xffff | 0x90030000;
      *(uint **)(compiler + 0xe30) = codeCursor2 + 1;
    }
    fieldInstWord = fieldInstWord + 1;
    fieldInstWord2 = fieldInstWord2 + 4;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
  codeCursor = *(undefined4 **)(compiler + 0xe30);
  *codeCursor = 0x80430d9c;
  iVar7 = *(int *)(compiler + 0xe24);
  *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  if ((*(uint *)(iVar7 + 0x34) & 1) != 0) {
    codeCursor[1] = 0x80a30d84;
    iVar7 = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
  }
  if ((*(uint *)(iVar7 + 0x34) & 2) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x80c30d88;
    iVar7 = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  if ((*(uint *)(iVar7 + 0x34) & 4) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x80e30d8c;
    iVar7 = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  if ((*(uint *)(iVar7 + 0x34) & 8) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x81030d90;
    iVar7 = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  if ((*(uint *)(iVar7 + 0x34) & 0x10) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x81230d94;
    iVar7 = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  if ((*(uint *)(iVar7 + 0x34) & 0x20) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x81430d98;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
  }
  chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpLoadOneAndZeroAVRTC,*(undefined4 *)(compiler + 0xe30));
  codeCursor3 = *(int *)(compiler + 0xe30);
  iVar8 = *(int *)(compiler + 0xe24);
  ppcInstWord = codeCursor3 + chunkIndex * 4;
  *(int *)(compiler + 0xe30) = ppcInstWord;
  if (((*(int *)(iVar8 + 0x38) == 0x8804) || (*(int *)(iVar8 + 0x38) == 0x8b30)) &&
     ((*(uint *)(iVar8 + 0x34) & 0x1004) != 0)) {
    *(undefined4 *)(codeCursor3 + chunkIndex * 4) = 0x81830da4;
    *(undefined4 *)(ppcInstWord + 4) = 0x81a30da0;
    iVar8 = *(int *)(compiler + 0xe24);
    *(int *)(compiler + 0xe30) = ppcInstWord + 8;
  }
  if ((*(int *)(iVar8 + 0x38) != 0x8804) && (*(int *)(iVar8 + 0x38) != 0x8b30)) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x39e01b70;
    codeCursor[1] = 0x7dcf10ce;
    codeCursor[2] = 0x39e01b80;
    codeCursor[3] = 0x7def10ce;
    codeCursor[4] = 0x39e00000;
    codeCursor[5] = 0x7e4f18ce;
    codeCursor[6] = 0x121f038c;
    codeCursor[7] = 0x12294c84;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 8;
  }
  codeCursor = *(undefined4 **)(compiler + 0xe30);
  *codeCursor = 0x7c8903a6;
  puVar1 = codeCursor + 1;
  *(undefined4 **)(compiler + 0xe30) = puVar1;
  chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpLoadOneAndZeroRTC,puVar1);
  iVar8 = *(int *)(compiler + 0xe24);
  *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + chunkIndex * 4;
  if ((*(int *)(iVar8 + 0x38) == 0x8804) || (*(int *)(iVar8 + 0x38) == 0x8b30)) {
    framebufferFormat = _PPEmulatorFramebufferFormat(*(undefined4 *)(compiler + 0xe20));
    if ((framebufferFormat & 0x8000) != 0) {
      codeCursor = *(undefined4 **)(compiler + 0xe30);
      *codeCursor = 0x39e00040;
      codeCursor[1] = 0x7e4378ce;
      *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
    }
    iVar8 = *(int *)(compiler + 0xe24);
  }
  if ((*(int *)(iVar8 + 0x38) == 0x8804) || (*(int *)(iVar8 + 0x38) == 0x8b30)) {
    if ((*(uint *)(iVar8 + 0x34) & 4) != 0) {
      codeCursor = *(undefined4 **)(compiler + 0xe30);
      *codeCursor = 0x7c6068ce;
      vectorInstWord = codeCursor + 1;
      *(undefined4 **)(compiler + 0xe30) = vectorInstWord;
      if ((*(uint *)(compiler + 0xe50) & 8) == 0) {
        *vectorInstWord = 0x11c9436a;
        iVar8 = *(int *)(compiler + 0xe24);
        *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
      }
      else {
        *vectorInstWord = 0x1080190a;
        codeCursor[2] = 0x11c9236a;
        iVar8 = *(int *)(compiler + 0xe24);
        *(undefined4 **)(compiler + 0xe30) = codeCursor + 3;
      }
    }
    if ((*(uint *)(iVar8 + 0x34) & 0x1000) != 0) {
      codeCursor = *(undefined4 **)(compiler + 0xe30);
      *codeCursor = 0xfd805890;
      codeCursor[1] = 0xc1ad0008;
      *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
    }
  }
  return;
}

/* _PPCRuntimeCompilerWriteEpilogAV @ 0x97bdbf84 (304 bytes) */
int _PPCRuntimeCompilerWriteEpilogAV(compiler)
  int compiler;
{
  int fieldInstWord;
  undefined4 *codeCursor;
  int chunkIndex;
  int iVar1;
  uint *codeCursor2;
  uint fieldInstWord2;
  undefined4 *puVar4;
  int iVar5;
  
  iVar1 = *(int *)(*(int *)(compiler + 0xe24) + 0x38);
  if ((iVar1 != 0x8804) && (iVar1 != 0x8b30)) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x1210486c;
    codeCursor[1] = 0x39e0020e;
    codeCursor[2] = 0x10718484;
    codeCursor[3] = 0x7c6f194e;
    codeCursor[4] = 0x7caf1a2e;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 5;
  }
  fieldInstWord = 0xd;
  iVar5 = 0x13;
  fieldInstWord2 = 0x284;
  do {
    if ((fieldInstWord != 0x10) || ((*(uint *)(*(int *)(compiler + 0xe24) + 0x34) & 0x200) != 0)) {
      codeCursor2 = *(uint **)(compiler + 0xe30);
      *codeCursor2 = fieldInstWord << 0x15 | fieldInstWord2 & 0xffff | 0x80030000;
      *(uint **)(compiler + 0xe30) = codeCursor2 + 1;
    }
    fieldInstWord = fieldInstWord + 1;
    fieldInstWord2 = fieldInstWord2 + 4;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  codeCursor = *(undefined4 **)(compiler + 0xe30);
  *codeCursor = 0x7ca32b78;
  puVar4 = codeCursor + 1;
  *(undefined4 **)(compiler + 0xe30) = puVar4;
  chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpEpilogAVRTC,puVar4);
  *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + chunkIndex * 4;
  return;
}

/* _PPCRuntimeCompilerStride @ 0x97bdc0b4 (548 bytes) */
int _PPCRuntimeCompilerStride(compiler)
  int compiler;
{
  undefined4 *codeCursor;
  ushort uVar1;
  uint *codeCursor2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = *(int *)(compiler + 0xe24);
  if ((*(int *)(iVar3 + 0x38) == 0x8804) || (*(int *)(iVar3 + 0x38) == 0x8b30)) {
    if (*(int *)(compiler + 0xe4c) == 0) {
      codeCursor = *(undefined4 **)(compiler + 0xe30);
      *codeCursor = 0xed8c502a;
      puVar4 = codeCursor + 1;
    }
    else {
      if ((*(uint *)(iVar3 + 0x34) & 4) != 0) {
        codeCursor = *(undefined4 **)(compiler + 0xe30);
        *codeCursor = 0x10684b2c;
        codeCursor[1] = 0x11ce180a;
        *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
        if ((*(uint *)(compiler + 0xe50) & 8) != 0) {
          codeCursor[2] = 0x7c6068ce;
          codeCursor[3] = 0x7c8060ce;
          codeCursor[4] = 0x10a0728c;
          codeCursor[5] = 0x10a4196e;
          codeCursor[6] = 0x10c0290a;
          codeCursor[7] = 0x11ce336a;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 8;
        }
        iVar3 = *(int *)(compiler + 0xe24);
      }
      if ((*(uint *)(iVar3 + 0x34) & 0x1000) == 0) goto LAB_97bdc214;
      codeCursor = *(undefined4 **)(compiler + 0xe30);
      *codeCursor = 0xed8c502a;
      codeCursor[1] = 0xc10d0008;
      codeCursor[2] = 0xc12c0008;
      codeCursor[3] = 0xeda9433a;
      puVar4 = codeCursor + 4;
    }
    *(undefined4 **)(compiler + 0xe30) = puVar4;
    iVar3 = *(int *)(compiler + 0xe24);
  }
  else {
    codeCursor2 = *(uint **)(compiler + 0xe30);
    *codeCursor2 = *(ushort *)(iVar3 + 0xbe) | 0x38e70000;
    iVar3 = *(int *)(compiler + 0xe24);
    *(uint **)(compiler + 0xe30) = codeCursor2 + 1;
  }
LAB_97bdc214:
  if ((*(uint *)(iVar3 + 0x34) & 2) != 0) {
    codeCursor2 = *(uint **)(compiler + 0xe30);
    *codeCursor2 = *(ushort *)(iVar3 + 0xba) | 0x38c60000;
    iVar3 = *(int *)(compiler + 0xe24);
    *(uint **)(compiler + 0xe30) = codeCursor2 + 1;
  }
  if ((*(uint *)(iVar3 + 0x34) & 0x1000) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x81e30da8;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
    uVar1 = *(ushort *)(*(int *)(compiler + 0xe24) + 0xda);
    codeCursor[2] = 0x91e30da8;
    codeCursor[1] = uVar1 | 0x39ef0000;
    iVar3 = *(int *)(compiler + 0xe24);
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 3;
  }
  if ((*(uint *)(iVar3 + 0x34) & 0x4000) != 0) {
    codeCursor = *(undefined4 **)(compiler + 0xe30);
    *codeCursor = 0x81e30dac;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
    uVar1 = *(ushort *)(*(int *)(compiler + 0xe24) + 0xde);
    codeCursor[2] = 0x91e30dac;
    codeCursor[1] = uVar1 | 0x39ef0000;
    *(undefined4 **)(compiler + 0xe30) = codeCursor + 3;
  }
  return;
}

/* _PPCRuntimeCompilerLoop @ 0x97bdc2d8 (92 bytes) */
int _PPCRuntimeCompilerLoop(compiler)
  int compiler;
{
  uint uVar1;
  uint *codeCursor;
  
  codeCursor = *(uint **)(compiler + 0xe30);
  uVar1 = (uint)((int)codeCursor - *(int *)(compiler + 0xe38)) >> 2;
  if (uVar1 < 0x1fff) {
    *codeCursor = uVar1 * -4 & 0xfffc | 0x42000000;
    *(uint **)(compiler + 0xe30) = codeCursor + 1;
    return;
  }
  *codeCursor = 0x42400008;
  codeCursor[1] = (~uVar1 & 0xffffff) << 2 | 0x48000000;
  *(uint **)(compiler + 0xe30) = codeCursor + 2;
  return;
}

/* _PPCRuntimeCompilerCompileNO @ 0x97bdc334 (5348 bytes) */
int _PPCRuntimeCompilerCompileNO(compiler)
  int compiler;
{
  undefined4 glpDCBReallocResult;
  int glpDCBReallocResult2;
  uint loopIndex;
  uint ppcInstWord4;
  undefined4 ppcInstWord3;
  undefined4 codeWritePtr6;
  undefined4 *codeWritePtr5;
  int ppcInstWord;
  int codeWritePtr2;
  int codeWritePtr;
  undefined4 *codeCursor2;
  int codeCursor3;
  int instruction;
  int chunkIndex;
  int chunkIndex2;
  char cVar1;
  byte bVar2;
  ushort uVar3;
  bool bVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  uint loopIndex2;
  int iVar9;
  undefined4 uVar10;
  undefined *puVar11;
  undefined4 uVar12;
  undefined4 codeWritePtr4;
  undefined4 in_r6;
  undefined4 in_r7;
  int in_r8;
  undefined4 *ppcInstWord2;
  undefined4 uVar13;
  undefined4 uVar14;
  int codeCursor;
  int *codeWritePtr3;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int *piVar19;
  uint uVar20;
  uint *puVar21;
  
  _PPCRuntimeCompilerInitialise(compiler,0);
  uVar10 = _glpDCBAlloc(0x2000);
  iVar16 = 0x2000;
  *(undefined4 *)(compiler + 0xe30) = uVar10;
  *(undefined4 *)(compiler + 0xe2c) = uVar10;
  ((int (*)())_PPCRuntimeCompilerWritePrologNO)(compiler);
  *(undefined4 *)(compiler + 0xe48) = 0;
  do {
    iVar6 = *(int *)(compiler + 0xe48);
    if ((iVar6 != 1) && (iVar6 != 3)) {
      codeWritePtr2 = *(int *)(compiler + 0xe24);
      puVar5 = *(undefined4 **)(codeWritePtr2 + 0x120);
      *(undefined4 **)(compiler + 0xe28) = puVar5;
      while (puVar5 != (undefined4 *)0x0) {
        puVar21 = *(uint **)(compiler + 0xe28);
        uVar17 = 1;
        bVar4 = true;
        uVar7 = puVar21[0xc];
        uVar18 = *puVar21;
        cVar1 = *(char *)(puVar21 + 1);
        if (uVar7 != 0) {
          codeWritePtr2 = 0;
          do {
            if ((*(char *)((int)puVar21 + codeWritePtr2 + 0x48) != '\0') &&
               (loopIndex2 = (uint)*(byte *)((int)puVar21 + codeWritePtr2 + 0x49), uVar17 < loopIndex2)) {
              uVar17 = loopIndex2;
            }
            codeWritePtr2 = codeWritePtr2 + 0x24;
            uVar7 = uVar7 - 1;
          } while (uVar7 != 0);
        }
        if (uVar18 == 0x22) {
          if ((*(int *)(compiler + 0x380) == 0) &&
             (((uVar3 = *(ushort *)(puVar21 + 7),
               uVar7 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(compiler,0x10), uVar3 != uVar7 ||
               (piVar19 = (int *)puVar21[3],
               codeWritePtr2 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(compiler,0x10), *piVar19 != codeWritePtr2)) ||
              (puVar21 = *(uint **)(compiler + 0xe28), (puVar21[10] & 0x1000000) == 0)))) {
            _PPCRuntimeCompilerBackupRegister(compiler,0x10);
            puVar21 = *(uint **)(compiler + 0xe28);
          }
          if ((*(int *)(compiler + 0x3b8) == 0) &&
             (((uVar3 = *(ushort *)(puVar21 + 7),
               uVar7 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(compiler,0x11), uVar3 != uVar7 ||
               (uVar7 = puVar21[3], codeWritePtr2 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(compiler,0x11),
               *(int *)(uVar7 + 4) != codeWritePtr2)) ||
              (puVar21 = *(uint **)(compiler + 0xe28), (puVar21[10] & 0x2000000) == 0)))) {
            _PPCRuntimeCompilerBackupRegister(compiler,0x11);
            puVar21 = *(uint **)(compiler + 0xe28);
          }
          if ((*(int *)(compiler + 0x3f0) == 0) &&
             (((uVar3 = *(ushort *)(puVar21 + 7),
               uVar7 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(compiler,0x12), uVar3 != uVar7 ||
               (uVar7 = puVar21[3], codeWritePtr2 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(compiler,0x12),
               *(int *)(uVar7 + 8) != codeWritePtr2)) ||
              (puVar21 = *(uint **)(compiler + 0xe28), (puVar21[10] & 0x4000000) == 0)))) {
            _PPCRuntimeCompilerBackupRegister(compiler,0x12);
            puVar21 = *(uint **)(compiler + 0xe28);
          }
          if ((*(int *)(compiler + 0x428) == 0) &&
             (((uVar3 = *(ushort *)(puVar21 + 7),
               uVar7 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(compiler,0x13), uVar3 != uVar7 ||
               (uVar7 = puVar21[3], codeWritePtr2 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(compiler,0x13),
               *(int *)(uVar7 + 0xc) != codeWritePtr2)) ||
              (puVar21 = *(uint **)(compiler + 0xe28), (puVar21[10] & 0x8000000) == 0)))) {
            _PPCRuntimeCompilerBackupRegister(compiler,0x13);
            puVar21 = *(uint **)(compiler + 0xe28);
          }
          if ((*(char *)(puVar21 + 0x12) == '\0') && (*(char *)(puVar21 + 0x1b) == '\0')) {
            ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,puVar21[0xd],puVar21[0xe],puVar21[0xf],puVar21[0x10],puVar21[0x11],
                       puVar21[0x12],puVar21[0x13],puVar21[0x14],puVar21[0x15],0,0);
            iVar6 = *(int *)(compiler + 0xe28);
            codeWritePtr3 = *(int **)(iVar6 + 0x70);
            codeWritePtr4 = *(undefined4 *)(iVar6 + 0x5c);
            in_r6 = *(undefined4 *)(iVar6 + 0x60);
            in_r7 = *(undefined4 *)(iVar6 + 100);
            in_r8 = *(int *)(iVar6 + 0x68);
            ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,*(undefined4 *)(iVar6 + 0x58),codeWritePtr4,in_r6,in_r7,in_r8,
                       *(undefined4 *)(iVar6 + 0x6c),codeWritePtr3,*(undefined4 *)(iVar6 + 0x74),
                       *(undefined4 *)(iVar6 + 0x78),0,1);
            codeWritePtr2 = _glpRTCAddAChunk_97bd7cbc(&_glpOpMultRTC,*(undefined4 *)(compiler + 0xe30));
            *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + codeWritePtr2 * 4;
          }
          else if ((*(char *)(puVar21 + 0x12) == '\0') ||
                  (*(char *)((int)puVar21 + 0x49) != *(char *)((int)puVar21 + 0x6d))) {
            iVar6 = 0;
            if (*(char *)(puVar21 + 0x12) == '\0') {
              if (*(char *)(puVar21 + 0x1b) != '\0') {
                ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,puVar21[0x16],puVar21[0x17],puVar21[0x18],puVar21[0x19],
                           puVar21[0x1a],puVar21[0x1b],puVar21[0x1c],puVar21[0x1d],puVar21[0x1e],0,1
                          );
                instruction = *(int *)(compiler + 0xe28);
                iVar6 = 1;
                uVar13 = *(undefined4 *)(instruction + 0x54);
                uVar10 = *(undefined4 *)(instruction + 0x50);
                codeWritePtr3 = *(int **)(instruction + 0x4c);
                uVar12 = *(undefined4 *)(instruction + 0x34);
                codeWritePtr4 = *(undefined4 *)(instruction + 0x38);
                in_r6 = *(undefined4 *)(instruction + 0x3c);
                in_r7 = *(undefined4 *)(instruction + 0x40);
                in_r8 = *(int *)(instruction + 0x44);
                uVar14 = *(undefined4 *)(instruction + 0x48);
                goto LAB_97bdc778;
              }
            }
            else {
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,puVar21[0xd],puVar21[0xe],puVar21[0xf],puVar21[0x10],puVar21[0x11],
                         puVar21[0x12],puVar21[0x13],puVar21[0x14],puVar21[0x15],0,1);
              instruction = *(int *)(compiler + 0xe28);
              uVar13 = *(undefined4 *)(instruction + 0x78);
              uVar10 = *(undefined4 *)(instruction + 0x74);
              codeWritePtr3 = *(int **)(instruction + 0x70);
              uVar12 = *(undefined4 *)(instruction + 0x58);
              codeWritePtr4 = *(undefined4 *)(instruction + 0x5c);
              in_r6 = *(undefined4 *)(instruction + 0x60);
              in_r7 = *(undefined4 *)(instruction + 100);
              in_r8 = *(int *)(instruction + 0x68);
              uVar14 = *(undefined4 *)(instruction + 0x6c);
LAB_97bdc778:
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,uVar12,codeWritePtr4,in_r6,in_r7,in_r8,uVar14,codeWritePtr3,uVar10,uVar13,0,0);
            }
            if (uVar17 == 2) {
              chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(compiler + 0xe30));
              codeCursor = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursor + chunkIndex * 4) = 0xfd008090;
              iVar6 = iVar6 * 0x24 + *(int *)(compiler + 0xe28);
              *(int *)(compiler + 0xe30) = codeCursor + chunkIndex * 4 + 4;
              codeWritePtr4 = *(undefined4 *)(iVar6 + 0x38);
              in_r6 = *(undefined4 *)(iVar6 + 0x3c);
              in_r7 = *(undefined4 *)(iVar6 + 0x40);
              in_r8 = *(int *)(iVar6 + 0x44);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,*(undefined4 *)(iVar6 + 0x34),codeWritePtr4,in_r6,in_r7,in_r8,
                         *(undefined4 *)(iVar6 + 0x48),*(undefined4 *)(iVar6 + 0x4c),
                         *(undefined4 *)(iVar6 + 0x50),*(undefined4 *)(iVar6 + 0x54),1,1);
              ppcInstWord = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(compiler + 0xe30));
              codeWritePtr3 = *(int **)(compiler + 0xe30);
              ppcInstWord = ppcInstWord << 2;
              ppcInstWord4 = 0xfe200000;
            }
            else if (uVar17 == 3) {
              chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(compiler + 0xe30));
              codeCursor = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursor + chunkIndex * 4) = 0xfd008090;
              *(int *)(compiler + 0xe30) = codeCursor + chunkIndex * 4 + 4;
              iVar9 = iVar6 * 0x24 + *(int *)(compiler + 0xe28);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                         *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                         *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                         *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                         *(undefined4 *)(iVar9 + 0x54),1,1);
              chunkIndex2 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(compiler + 0xe30));
              codeCursor3 = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursor3 + chunkIndex2 * 4) = 0xfe208090;
              *(int *)(compiler + 0xe30) = codeCursor3 + chunkIndex2 * 4 + 4;
              iVar6 = iVar6 * 0x24 + *(int *)(compiler + 0xe28);
              codeWritePtr4 = *(undefined4 *)(iVar6 + 0x38);
              in_r6 = *(undefined4 *)(iVar6 + 0x3c);
              in_r7 = *(undefined4 *)(iVar6 + 0x40);
              in_r8 = *(int *)(iVar6 + 0x44);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,*(undefined4 *)(iVar6 + 0x34),codeWritePtr4,in_r6,in_r7,in_r8,
                         *(undefined4 *)(iVar6 + 0x48),*(undefined4 *)(iVar6 + 0x4c),
                         *(undefined4 *)(iVar6 + 0x50),*(undefined4 *)(iVar6 + 0x54),2,1);
              ppcInstWord = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(compiler + 0xe30));
              codeWritePtr3 = *(int **)(compiler + 0xe30);
              ppcInstWord = ppcInstWord << 2;
              ppcInstWord4 = 0xfe400000;
            }
            else {
              if (uVar17 != 4) goto LAB_97bdcb04;
              iVar6 = iVar6 * 0x24;
              chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(compiler + 0xe30));
              codeCursor = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursor + chunkIndex * 4) = 0xfd008090;
              *(int *)(compiler + 0xe30) = codeCursor + chunkIndex * 4 + 4;
              iVar9 = iVar6 + *(int *)(compiler + 0xe28);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                         *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                         *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                         *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                         *(undefined4 *)(iVar9 + 0x54),1,1);
              chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(compiler + 0xe30));
              codeCursor = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursor + chunkIndex * 4) = 0xfe208090;
              *(int *)(compiler + 0xe30) = codeCursor + chunkIndex * 4 + 4;
              iVar9 = iVar6 + *(int *)(compiler + 0xe28);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,*(undefined4 *)(iVar9 + 0x34),*(undefined4 *)(iVar9 + 0x38),
                         *(undefined4 *)(iVar9 + 0x3c),*(undefined4 *)(iVar9 + 0x40),
                         *(undefined4 *)(iVar9 + 0x44),*(undefined4 *)(iVar9 + 0x48),
                         *(undefined4 *)(iVar9 + 0x4c),*(undefined4 *)(iVar9 + 0x50),
                         *(undefined4 *)(iVar9 + 0x54),2,1);
              chunkIndex2 = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(compiler + 0xe30));
              codeCursor3 = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursor3 + chunkIndex2 * 4) = 0xfe408090;
              *(int *)(compiler + 0xe30) = codeCursor3 + chunkIndex2 * 4 + 4;
              iVar6 = iVar6 + *(int *)(compiler + 0xe28);
              codeWritePtr4 = *(undefined4 *)(iVar6 + 0x38);
              in_r6 = *(undefined4 *)(iVar6 + 0x3c);
              in_r7 = *(undefined4 *)(iVar6 + 0x40);
              in_r8 = *(int *)(iVar6 + 0x44);
              ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,*(undefined4 *)(iVar6 + 0x34),codeWritePtr4,in_r6,in_r7,in_r8,
                         *(undefined4 *)(iVar6 + 0x48),*(undefined4 *)(iVar6 + 0x4c),
                         *(undefined4 *)(iVar6 + 0x50),*(undefined4 *)(iVar6 + 0x54),3,1);
              ppcInstWord = _glpRTCAddAChunk_97bd7cbc(&_glpOpDot4RTC,*(undefined4 *)(compiler + 0xe30));
              codeWritePtr3 = *(int **)(compiler + 0xe30);
              ppcInstWord = ppcInstWord << 2;
              ppcInstWord4 = 0xfe600000;
            }
            *(uint *)((int)codeWritePtr3 + ppcInstWord) = ppcInstWord4 | 0x8090;
            *(undefined4 *)((int)codeWritePtr3 + ppcInstWord + 4) = 0xfe004090;
            *(int *)(compiler + 0xe30) = (int)codeWritePtr3 + ppcInstWord + 8;
          }
LAB_97bdcb04:
          ((int (*)())_PPCRuntimeCompilerWriteDestinationNO)(compiler,0);
        }
        else {
          loopIndex = 0;
          if (uVar17 != 0) {
            do {
              if ((*(int *)(compiler + 0x380) == 0) &&
                 (((uVar3 = *(ushort *)(puVar21 + 7),
                   loopIndex2 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(compiler,0x10), uVar3 != loopIndex2
                   || (piVar19 = (int *)puVar21[3],
                      codeWritePtr2 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(compiler,0x10),
                      *piVar19 != codeWritePtr2)) ||
                  (puVar21 = *(uint **)(compiler + 0xe28), (puVar21[10] & 0x1000000) == 0)))) {
                _PPCRuntimeCompilerBackupRegister(compiler,0x10);
                puVar21 = *(uint **)(compiler + 0xe28);
              }
              if ((*(int *)(compiler + 0x3b8) == 0) &&
                 (((uVar3 = *(ushort *)(puVar21 + 7),
                   loopIndex2 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(compiler,0x11), uVar3 != loopIndex2
                   || (loopIndex2 = puVar21[3],
                      codeWritePtr2 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(compiler,0x11),
                      *(int *)(loopIndex2 + 4) != codeWritePtr2)) ||
                  (puVar21 = *(uint **)(compiler + 0xe28), (puVar21[10] & 0x2000000) == 0)))) {
                _PPCRuntimeCompilerBackupRegister(compiler,0x11);
                puVar21 = *(uint **)(compiler + 0xe28);
              }
              if ((*(int *)(compiler + 0x3f0) == 0) &&
                 (((uVar3 = *(ushort *)(puVar21 + 7),
                   loopIndex2 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(compiler,0x12), uVar3 != loopIndex2
                   || (loopIndex2 = puVar21[3],
                      codeWritePtr2 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(compiler,0x12),
                      *(int *)(loopIndex2 + 8) != codeWritePtr2)) ||
                  (puVar21 = *(uint **)(compiler + 0xe28), (puVar21[10] & 0x4000000) == 0)))) {
                _PPCRuntimeCompilerBackupRegister(compiler,0x12);
                puVar21 = *(uint **)(compiler + 0xe28);
              }
              if ((*(int *)(compiler + 0x428) == 0) &&
                 (((uVar3 = *(ushort *)(puVar21 + 7),
                   loopIndex2 = ((int (*)())_PPCRuntimeCompilerGetBaseIndexInRegister)(compiler,0x13), uVar3 != loopIndex2
                   || (loopIndex2 = puVar21[3],
                      codeWritePtr2 = ((int (*)())_PPCRuntimeCompilerGetOffsetInRegister)(compiler,0x13),
                      *(int *)(loopIndex2 + 0xc) != codeWritePtr2)) ||
                  (puVar21 = *(uint **)(compiler + 0xe28), (puVar21[10] & 0x8000000) == 0)))) {
                _PPCRuntimeCompilerBackupRegister(compiler,0x13);
                puVar21 = *(uint **)(compiler + 0xe28);
              }
              if (puVar21[0xc] != 0) {
                codeWritePtr2 = 0;
                loopIndex2 = 0;
                do {
                  uVar20 = loopIndex2 + 1;
                  codeWritePtr3 = *(int **)((int)puVar21 + codeWritePtr2 + 0x4c);
                  codeWritePtr4 = *(undefined4 *)((int)puVar21 + codeWritePtr2 + 0x38);
                  in_r6 = *(undefined4 *)((int)puVar21 + codeWritePtr2 + 0x3c);
                  in_r7 = *(undefined4 *)((int)puVar21 + codeWritePtr2 + 0x40);
                  in_r8 = *(int *)((int)puVar21 + codeWritePtr2 + 0x44);
                  ((int (*)())_PPCRuntimeCompilerLoadSourceNO)(compiler,*(undefined4 *)((int)puVar21 + codeWritePtr2 + 0x34),codeWritePtr4,in_r6,in_r7,
                             in_r8,*(undefined4 *)((int)puVar21 + codeWritePtr2 + 0x48),codeWritePtr3,
                             *(undefined4 *)((int)puVar21 + codeWritePtr2 + 0x50),
                             *(undefined4 *)((int)puVar21 + codeWritePtr2 + 0x54),loopIndex,loopIndex2);
                  puVar21 = *(uint **)(compiler + 0xe28);
                  codeWritePtr2 = codeWritePtr2 + 0x24;
                  loopIndex2 = uVar20;
                } while (uVar20 < puVar21[0xc]);
              }
              if (uVar18 < 0x15) {
                if (((0x12 < uVar18) || (uVar18 == 1)) || ((uVar18 != 0 && (uVar18 - 0x10 < 2)))) {
LAB_97bdcd64:
                  _PPCRuntimeCompilerDirtyRegister(compiler,0);
                  _PPCRuntimeCompilerDirtyRegister(compiler,1);
                  _PPCRuntimeCompilerDirtyRegister(compiler,2);
                  _PPCRuntimeCompilerDirtyRegister(compiler,3);
                  _PPCRuntimeCompilerDirtyRegister(compiler,4);
                  _PPCRuntimeCompilerDirtyRegister(compiler,5);
                  _PPCRuntimeCompilerDirtyRegister(compiler,6);
                  _PPCRuntimeCompilerDirtyRegister(compiler,7);
                }
              }
              else {
                if (uVar18 == 0x38) goto LAB_97bdcd64;
                if (uVar18 == 0x48) {
                  _PPCRuntimeCompilerDirtyRegister(compiler,0);
                  _PPCRuntimeCompilerDirtyRegistersWithIndirectData(compiler);
                }
              }
              switch(uVar18) {
              case 0:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpMovRTC;
                break;
              case 1:
                codeWritePtr2 = _glpRTCAddAChunk_97bd7cbc
                                  (&_glpOpShuffleSrcRTC,*(undefined4 *)(compiler + 0xe30));
                codeWritePtr2 = *(int *)(compiler + 0xe30) + codeWritePtr2 * 4;
                *(int *)(compiler + 0xe30) = codeWritePtr2;
                codeWritePtr2 = _glpRTCAddAChunk_97bd7cbc(&_glpOpLogRTC,codeWritePtr2);
                codeWritePtr2 = *(int *)(compiler + 0xe30) + codeWritePtr2 * 4;
                *(int *)(compiler + 0xe30) = codeWritePtr2;
                codeWritePtr2 = _glpRTCAddAChunk_97bd7cbc(&_glpOpRestoreSrcBRTC,codeWritePtr2);
                codeWritePtr2 = *(int *)(compiler + 0xe30) + codeWritePtr2 * 4;
                *(int *)(compiler + 0xe30) = codeWritePtr2;
                codeWritePtr2 = _glpRTCAddAChunk_97bd7cbc(&_glpOpExpRTC,codeWritePtr2);
                codeWritePtr2 = *(int *)(compiler + 0xe30) + codeWritePtr2 * 4;
                *(int *)(compiler + 0xe30) = codeWritePtr2;
                puVar11 = &_glpOpShuffleDstRTC;
                break;
              case 2:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpAbsRTC;
                break;
              default:
                goto switchD_97bdcdfc_caseD_3;
              case 4:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpFrcRTC;
                break;
              case 5:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpFlrRTC;
                break;
              case 0xd:
                codeWritePtr6 = *(undefined4 *)(compiler + 0xe30);
                puVar11 = &_glpOpRsqRTC;
                goto LAB_97bdcf9c;
              case 0xe:
                codeWritePtr6 = *(undefined4 *)(compiler + 0xe30);
                puVar11 = &_glpOpRcpRTC;
                goto LAB_97bdcf9c;
              case 0x10:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                goto LAB_97bdd288;
              case 0x11:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpExpRTC;
                break;
              case 0x13:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpLogRTC;
                goto LAB_97bdcfe4;
              case 0x14:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpLogRTC;
                break;
              case 0x1f:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpAddRTC;
                break;
              case 0x20:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpSubRTC;
                break;
              case 0x22:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpMultRTC;
                break;
              case 0x27:
                bVar2 = *(byte *)(*(int *)(compiler + 0xe28) + 5);
                if (bVar2 == 2) {
                  codeWritePtr6 = *(undefined4 *)(compiler + 0xe30);
                  puVar11 = &_glpOpDot2RTC;
LAB_97bdd170:
                  codeWritePtr2 = _glpRTCAddAChunk_97bd7cbc(puVar11,codeWritePtr6);
                  *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + codeWritePtr2 * 4;
                }
                else {
                  if (2 < bVar2) {
                    if (bVar2 == 3) {
                      codeWritePtr6 = *(undefined4 *)(compiler + 0xe30);
                      puVar11 = &_glpOpDot3RTC;
                    }
                    else {
                      if (bVar2 != 4) goto LAB_97bdd184;
                      codeWritePtr6 = *(undefined4 *)(compiler + 0xe30);
                      puVar11 = &_glpOpDot4RTC;
                    }
                    goto LAB_97bdd170;
                  }
                  if (bVar2 == 1) {
                    codeWritePtr6 = *(undefined4 *)(compiler + 0xe30);
                    puVar11 = &_glpOpDot1RTC;
                    goto LAB_97bdd170;
                  }
                }
LAB_97bdd184:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                goto LAB_97bdcfb4;
              case 0x28:
                codeWritePtr6 = *(undefined4 *)(compiler + 0xe30);
                puVar11 = &_glpOpDot3RTC;
                goto LAB_97bdcf9c;
              case 0x29:
                codeWritePtr6 = *(undefined4 *)(compiler + 0xe30);
                puVar11 = &_glpOpDot4RTC;
                goto LAB_97bdcf9c;
              case 0x2a:
                codeWritePtr6 = *(undefined4 *)(compiler + 0xe30);
                puVar11 = &_glpOpDphRTC;
LAB_97bdcf9c:
                codeWritePtr2 = _glpRTCAddAChunk_97bd7cbc(puVar11,codeWritePtr6);
                codeWritePtr2 = *(int *)(compiler + 0xe30) + codeWritePtr2 * 4;
                *(int *)(compiler + 0xe30) = codeWritePtr2;
LAB_97bdcfb4:
                puVar11 = &_glpOpSplatC0RTC;
                break;
              case 0x2b:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpDistRTC;
                break;
              case 0x2c:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpMinRTC;
                break;
              case 0x2d:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpMaxRTC;
                break;
              case 0x2e:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpXpdRTC;
                break;
              case 0x32:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpSetGERTC;
                break;
              case 0x35:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpSetLTRTC;
                break;
              case 0x38:
                codeWritePtr2 = _glpRTCAddAChunk_97bd7cbc
                                  (&_glpOpSaveSrcBRTC,*(undefined4 *)(compiler + 0xe30));
                codeWritePtr2 = *(int *)(compiler + 0xe30) + codeWritePtr2 * 4;
                *(int *)(compiler + 0xe30) = codeWritePtr2;
                codeWritePtr2 = _glpRTCAddAChunk_97bd7cbc(&_glpOpLogRTC,codeWritePtr2);
                codeWritePtr2 = *(int *)(compiler + 0xe30) + codeWritePtr2 * 4;
                *(int *)(compiler + 0xe30) = codeWritePtr2;
                codeWritePtr2 = _glpRTCAddAChunk_97bd7cbc(&_glpOpRestoreSrcBRTC,codeWritePtr2);
                codeWritePtr2 = *(int *)(compiler + 0xe30) + codeWritePtr2 * 4;
                *(int *)(compiler + 0xe30) = codeWritePtr2;
LAB_97bdd288:
                puVar11 = &_glpOpExpRTC;
LAB_97bdcfe4:
                codeWritePtr2 = _glpRTCAddAChunk_97bd7cbc(puVar11,codeWritePtr2);
                codeWritePtr2 = *(int *)(compiler + 0xe30) + codeWritePtr2 * 4;
                *(int *)(compiler + 0xe30) = codeWritePtr2;
                puVar11 = &_glpOpSplatC2RTC;
                break;
              case 0x3c:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpLerpRTC;
                break;
              case 0x3e:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpCmpRTC;
                break;
              case 0x3f:
                codeWritePtr2 = *(int *)(compiler + 0xe30);
                puVar11 = &_glpOpMultAddRTC;
                break;
              case 0x41:
                codeWritePtr2 = *(int *)(compiler + 0xe28);
                switch(*(undefined1 *)(codeWritePtr2 + 0x60)) {
                case 0:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe000090;
                  break;
                case 1:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe000890;
                  break;
                case 2:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe001090;
                  break;
                case 3:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe001890;
                  break;
                case 4:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe000050;
                  break;
                case 5:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe000850;
                  break;
                case 6:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe001050;
                  break;
                case 7:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe001850;
                  break;
                case 8:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe005090;
                  break;
                case 9:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe005890;
                  break;
                case 10:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  *codeWritePtr5 = 0xfe005050;
                  codeWritePtr2 = *(int *)(compiler + 0xe28);
                  *(undefined4 **)(compiler + 0xe30) = codeWritePtr5 + 1;
                default:
                  goto switchD_97bdd2fc_default;
                }
                *codeWritePtr5 = ppcInstWord3;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr5 + 1;
                codeWritePtr2 = *(int *)(compiler + 0xe28);
switchD_97bdd2fc_default:
                switch(*(undefined1 *)(codeWritePtr2 + 0x61)) {
                case 0:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe200090;
                  break;
                case 1:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe200890;
                  break;
                case 2:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe201090;
                  break;
                case 3:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe201890;
                  break;
                case 4:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe200050;
                  break;
                case 5:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe200850;
                  break;
                case 6:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe201050;
                  break;
                case 7:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe201850;
                  break;
                case 8:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe205090;
                  break;
                case 9:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe205890;
                  break;
                case 10:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  *codeWritePtr5 = 0xfe205050;
                  codeWritePtr2 = *(int *)(compiler + 0xe28);
                  *(undefined4 **)(compiler + 0xe30) = codeWritePtr5 + 1;
                default:
                  goto switchD_97bdd41c_default;
                }
                *codeWritePtr5 = ppcInstWord3;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr5 + 1;
                codeWritePtr2 = *(int *)(compiler + 0xe28);
switchD_97bdd41c_default:
                switch(*(undefined1 *)(codeWritePtr2 + 0x62)) {
                case 0:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe400090;
                  break;
                case 1:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe400890;
                  break;
                case 2:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe401090;
                  break;
                case 3:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe401890;
                  break;
                case 4:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe400050;
                  break;
                case 5:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe400850;
                  break;
                case 6:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe401050;
                  break;
                case 7:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe401850;
                  break;
                case 8:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe405090;
                  break;
                case 9:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe405890;
                  break;
                case 10:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  *codeWritePtr5 = 0xfe405050;
                  codeWritePtr2 = *(int *)(compiler + 0xe28);
                  *(undefined4 **)(compiler + 0xe30) = codeWritePtr5 + 1;
                default:
                  goto switchD_97bdd53c_default;
                }
                *codeWritePtr5 = ppcInstWord3;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr5 + 1;
                codeWritePtr2 = *(int *)(compiler + 0xe28);
switchD_97bdd53c_default:
                switch(*(undefined1 *)(codeWritePtr2 + 99)) {
                case 0:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe600090;
                  break;
                case 1:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe600890;
                  break;
                case 2:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe601090;
                  break;
                case 3:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe601890;
                  break;
                case 4:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe600050;
                  break;
                case 5:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe600850;
                  break;
                case 6:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe601050;
                  break;
                case 7:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe601850;
                  break;
                case 8:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe605090;
                  break;
                case 9:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe605890;
                  break;
                case 10:
                  codeWritePtr5 = *(undefined4 **)(compiler + 0xe30);
                  ppcInstWord3 = 0xfe605050;
                  break;
                default:
                  goto switchD_97bdcdfc_caseD_3;
                }
                *codeWritePtr5 = ppcInstWord3;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr5 + 1;
                goto switchD_97bdcdfc_caseD_3;
              case 0x42:
                in_r8 = *(int *)(compiler + 0xe20);
                if (*(int *)(*(int *)(in_r8 + 0xd80) + 0x38) - 0x8b30U < 2) {
                  codeWritePtr3 = *(int **)(*(int *)(compiler + 0xe28) + 0x58);
                  uVar10 = *(undefined4 *)
                            (*(int *)((uint)*(ushort *)(*(int *)(compiler + 0xe28) + 0x68) * 4 +
                                      in_r8 + 0xd84) + *codeWritePtr3);
                }
                else {
                  uVar10 = *(undefined4 *)(*(int *)(compiler + 0xe28) + 0x10c);
                }
                ((int (*)())_PPCTextureSamplerAttachGLDContext)(*(undefined4 *)(compiler + 0xe1c),*(undefined4 *)(in_r8 + 0xd9c));
                codeWritePtr2 = *(int *)(*(int *)(compiler + 0xe28) + 0x110);
                if (codeWritePtr2 == 2) {
                  codeWritePtr4 = *(undefined4 *)(compiler + 0xe30);
                  uVar10 = ((int (*)())_PPCTextureSamplerSampleTexelRECTRTCNO)(*(undefined4 *)(compiler + 0xe1c),uVar10,codeWritePtr4);
                }
                else {
                  if (codeWritePtr2 != 3) goto switchD_97bdcdfc_caseD_3;
                  codeWritePtr4 = *(undefined4 *)(compiler + 0xe30);
                  uVar10 = ((int (*)())_PPCTextureSamplerSampleTexel2DRTCNO)(*(undefined4 *)(compiler + 0xe1c),uVar10,codeWritePtr4);
                }
                *(undefined4 *)(compiler + 0xe30) = uVar10;
                goto switchD_97bdcdfc_caseD_3;
              case 0x48:
                if ((*(byte *)(*(int *)(compiler + 0xe28) + 0x28) & 1) != 0) {
                  codeWritePtr2 = _glpRTCAddAChunk_97bd7cbc(&_glpOpArlRTC,*(undefined4 *)(compiler + 0xe30));
                  *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + codeWritePtr2 * 4;
                }
              case 0x49:
              case 0x4a:
              case 0x4b:
              case 0x4c:
              case 0x4d:
              case 0x4f:
              case 0x55:
              case 0x56:
              case 0x57:
              case 0x58:
              case 0x59:
              case 0x5a:
                bVar4 = false;
                goto LAB_97bdd85c;
              case 0x5b:
                bVar4 = false;
                goto switchD_97bdcdfc_caseD_3;
              }
              codeWritePtr2 = _glpRTCAddAChunk_97bd7cbc(puVar11,codeWritePtr2);
              *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + codeWritePtr2 * 4;
switchD_97bdcdfc_caseD_3:
              if (bVar4) {
                if (cVar1 != '\0') {
                  codeWritePtr2 = _glpRTCAddAChunk_97bd7cbc
                                    (&_glpOpSaturateRTC,*(undefined4 *)(compiler + 0xe30));
                  *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + codeWritePtr2 * 4;
                }
                ((int (*)())_PPCRuntimeCompilerWriteDestinationNO)(compiler,loopIndex);
              }
LAB_97bdd85c:
              loopIndex = loopIndex + 1;
              if (uVar17 <= loopIndex) break;
              puVar21 = *(uint **)(compiler + 0xe28);
            } while( true );
          }
          codeWritePtr2 = *(int *)(compiler + 0xe2c);
          if (iVar16 - 2000U < (uint)(*(int *)(compiler + 0xe30) - codeWritePtr2)) {
            iVar16 = iVar16 + 0x2000;
            glpDCBReallocResult2 = _glpDCBRealloc(codeWritePtr2,iVar16);
            *(int *)(compiler + 0xe2c) = glpDCBReallocResult2;
            codeWritePtr2 = glpDCBReallocResult2 - codeWritePtr2 >> 2;
            if (codeWritePtr2 != 0) {
              codeWritePtr2 = codeWritePtr2 * 4;
              codeWritePtr3 = (int *)(*(int *)(compiler + 0xe3c) + codeWritePtr2);
              *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + codeWritePtr2;
              in_r8 = *(int *)(compiler + 0xe40) + codeWritePtr2;
              *(int *)(compiler + 0xe34) = *(int *)(compiler + 0xe34) + codeWritePtr2;
              *(int *)(compiler + 0xe38) = *(int *)(compiler + 0xe38) + codeWritePtr2;
              *(int **)(compiler + 0xe3c) = codeWritePtr3;
              *(int *)(compiler + 0xe40) = in_r8;
            }
          }
        }
        codeWritePtr2 = *(int *)(compiler + 0xe24);
        ppcInstWord2 = (undefined4 *)(*(int *)(compiler + 0xe28) + 0x11c);
        if (*(int *)(compiler + 0xe28) == *(int *)(codeWritePtr2 + 4)) {
          ppcInstWord2 = (undefined4 *)0x0;
        }
        *(undefined4 **)(compiler + 0xe28) = ppcInstWord2;
        puVar5 = ppcInstWord2;
      }
      if ((*(int *)(codeWritePtr2 + 0x38) != 0x8804) && (*(int *)(codeWritePtr2 + 0x38) != 0x8b30)) {
        codeCursor2 = *(undefined4 **)(compiler + 0xe30);
        *codeCursor2 = 0xc0060010;
        ppcInstWord2 = codeCursor2 + 1;
        *ppcInstWord2 = 0xc0260014;
        codeCursor2[2] = 0xc0460018;
        codeCursor2[3] = 0xc066001c;
        *(undefined4 **)(compiler + 0xe30) = codeCursor2 + 4;
        codeWritePtr2 = _glpRTCAddAChunk_97bd7cbc(&_glpOpClippingRTC,codeCursor2 + 4);
        *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + codeWritePtr2 * 4;
      }
      iVar6 = *(int *)(compiler + 0xe48);
      if (iVar6 == 0) {
        _PPCRuntimeCompilerDirtyRegistersContainingAttributes(compiler);
        _PPCRuntimeCompilerDirtyRegistersContainingTemps(compiler);
        _PPCRuntimeCompilerDirtyRegistersContainingParams(compiler);
        iVar6 = *(int *)(compiler + 0xe48);
        *(undefined4 *)(compiler + 0xe38) = *(undefined4 *)(compiler + 0xe30);
      }
      else if (iVar6 == 2) {
        ((int (*)())_PPCRuntimeCompilerStride)(compiler);
        ((int (*)())_PPCRuntimeCompilerLoop)(compiler);
        iVar6 = *(int *)(compiler + 0xe48);
      }
    }
    *(uint *)(compiler + 0xe48) = iVar6 + 1U;
    if (3 < iVar6 + 1U) {
      ((int (*)())_PPCRuntimeCompilerWriteEpilogNO)(compiler);
      codeWritePtr = *(int *)(compiler + 0xe30) - *(int *)(compiler + 0xe2c) >> 2;
      glpDCBReallocResult = _glpDCBRealloc(*(int *)(compiler + 0xe2c),codeWritePtr << 2);
      *(undefined4 *)(compiler + 0xe2c) = glpDCBReallocResult;
                    
                    
      (*_glpPushInstructions)(codeWritePtr,glpDCBReallocResult,codeWritePtr4,in_r6,in_r7,in_r8,ppcInstWord2,codeWritePtr3);
      return;
    }
  } while( true );
}

/* _PPCRuntimeCompilerCompileAV @ 0x97bdda38 (15728 bytes) */
int _PPCRuntimeCompilerCompileAV(compiler)
  int compiler;
{
  undefined4 *vectorInstWord6;
  int codeWritePtr4;
  int ppcInstWord;
  int codeWordCount;
  char dimensionByte;
  int codeCursorAfter;
  uint sourceComponent2;
  uint vectorInstWord4;
  undefined4 vectorInstWord3;
  uint ppcWord;
  uint vectorInstWord2;
  undefined4 grownCodeBuffer;
  undefined4 projectionEnabled;
  undefined4 destComponent;
  undefined4 passThroughR4;
  int passIndex;
  int codeBufferBase;
  int sourceOffset21;
  uint vectorInstWord;
  uint operandSelector;
  uint componentLoopIndex;
  undefined4 *codeWritePtr;
  int sourceOffset;
  int codeCursorAddr;
  int emittedWord;
  int chunkWordCount;
  int curInst;
  int sourceCount;
  int programInfo;
  undefined4 *codeCursor;
  undefined4 *codeCursor4;
  uint *codeCursor3;
  int *instruction2;
  int instruction;
  int codeCursor2;
  undefined8 chunkIndex2;
  int chunkIndex;
  uint loopIndex;
  bool bVar1;
  char saturateFlag;
  byte dimension;
  bool bVar4;
  undefined4 *instructionListHead;
  uint sourceComponent;
  uint uVar7;
  undefined4 uVar8;
  int vectorInstWord5;
  int *codeWordPtr;
  int iVar11;
  uint operandWidth;
  uint *codeWritePtr2;
  uint *codeWritePtr3;
  undefined4 codeBuffer;
  undefined *opTemplate;
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
  undefined4 extraout_r4_11;
  undefined4 extraout_r4_12;
  undefined4 extraout_r4_13;
  undefined4 srcBankWord;
  undefined4 srcSwizzleWord;
  int srcIndexWord;
  int *srcStorageWord;
  undefined4 *inst;
  int operandOffset;
  undefined4 *puVar18;
  int *srcTypeWord;
  int codeBufferCapacity;
  uint elementCount;
  int opcode;
  uint uVar22;
  undefined8 emitResult64;
  
  _PPCRuntimeCompilerInitialise(compiler,1);
  codeBuffer = _glpDCBAlloc(0x2000);
  codeBufferCapacity = 0x2000;
  *(undefined4 *)(compiler + 0xe30) = codeBuffer;
  *(undefined4 *)(compiler + 0xe2c) = codeBuffer;
  ((int (*)())_PPCRuntimeCompilerWritePrologAV)(compiler);
  *(undefined4 *)(compiler + 0xe34) = *(undefined4 *)(compiler + 0xe30);
  *(undefined4 *)(compiler + 0xe48) = 0;
  passThroughR4 = extraout_r4;
  do {
    if (((1 < *(uint *)(compiler + 0xe48)) &&
        (programInfo = *(int *)(*(int *)(compiler + 0xe20) + 0xd80), (*(uint *)(programInfo + 0x3c) & 6) == 4))
       && ((*(uint *)(programInfo + 0x34) & 0xa000) == 0)) {
      emitResult64 = ((int (*)())_PPCRasterOpMachine_DepthTestRTCAV)(compiler + 0xe14,*(undefined4 *)(compiler + 0xe30));
      passThroughR4 = (undefined4)emitResult64;
      *(int *)(compiler + 0xe30) = (int)((ulonglong)emitResult64 >> 0x20);
    }
    programInfo = *(int *)(compiler + 0xe24);
    instructionListHead = *(undefined4 **)(programInfo + 0x120);
    *(undefined4 **)(compiler + 0xe28) = instructionListHead;
    while (instructionListHead != (undefined4 *)0x0) {
      elementCount = 1;
      bVar4 = true;
      instruction2 = *(int **)(compiler + 0xe28);
      instruction2[0x46] = *(int *)(compiler + 0xe30) - *(int *)(compiler + 0xe2c);
      opcode = *instruction2;
      sourceCount = *(int *)(*(int *)(compiler + 0xe28) + 0x30);
      saturateFlag = *(char *)(instruction2 + 1);
      if (sourceCount != 0) {
        operandOffset = 0;
        do {
          iVar11 = operandOffset + *(int *)(compiler + 0xe28);
          if ((*(char *)(iVar11 + 0x48) != '\0') &&
             (operandWidth = (uint)*(byte *)(iVar11 + 0x49), elementCount < operandWidth)) {
            elementCount = operandWidth;
          }
          operandOffset = operandOffset + 0x24;
          sourceCount = sourceCount + -1;
        } while (sourceCount != 0);
      }
      if (opcode == 0x22) {
        _PPCRuntimeCompilerBackupRegister(compiler,2);
        _PPCRuntimeCompilerDirtyRegister(compiler,2);
        inst = *(undefined4 **)(compiler + 0xe28);
        if ((*(char *)(inst + 0x12) == '\0') && (*(char *)(inst + 0x1b) == '\0')) {
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],inst[0x12],
                     inst[0x13],inst[0x14],inst[0x15],0,0);
          curInst = *(int *)(compiler + 0xe28);
          srcTypeWord = *(int **)(curInst + 0x70);
          srcBankWord = *(undefined4 *)(curInst + 0x5c);
          srcSwizzleWord = *(undefined4 *)(curInst + 0x60);
          srcIndexWord = *(int *)(curInst + 100);
          srcStorageWord = *(int **)(curInst + 0x68);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                     *(undefined4 *)(curInst + 0x6c),srcTypeWord,*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),0,1);
          chunkWordCount = _glpRTCAddAChunk_97bd7cbc(&_glpOpMulAVRTC,*(undefined4 *)(compiler + 0xe30));
          chunkWordCount = *(int *)(compiler + 0xe30) + chunkWordCount * 4;
          *(int *)(compiler + 0xe30) = chunkWordCount;
          if (saturateFlag != '\0') {
            chunkWordCount = _glpRTCAddAChunk_97bd7cbc(&_glpOpSaturateAVRTC,chunkWordCount);
            *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + chunkWordCount * 4;
          }
LAB_97bdde9c:
          destComponent = 0;
LAB_97bddea4:
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,destComponent);
          passThroughR4 = extraout_r4_01;
          goto LAB_97be18e4;
        }
        if (((*(char *)(inst + 0x12) == '\0') || (*(char *)(inst + 0x1b) == '\0')) ||
           (*(char *)((int)inst + 0x49) != *(char *)((int)inst + 0x6d))) {
          if ((*(char *)(inst + 0x12) != '\0') && (1 < *(byte *)((int)inst + 0x6d))) {
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],inst[0x12],
                       inst[0x13],inst[0x14],inst[0x15],0,1);
            curInst = *(int *)(compiler + 0xe28);
            srcTypeWord = *(int **)(curInst + 0x70);
            srcBankWord = *(undefined4 *)(curInst + 0x5c);
            srcSwizzleWord = *(undefined4 *)(curInst + 0x60);
            srcIndexWord = *(int *)(curInst + 100);
            srcStorageWord = *(int **)(curInst + 0x68);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                       *(undefined4 *)(curInst + 0x6c),srcTypeWord,*(undefined4 *)(curInst + 0x74),
                       *(undefined4 *)(curInst + 0x78),0,0);
            if (elementCount == 2) {
              codeCursor = *(undefined4 **)(compiler + 0xe30);
              *codeCursor = 0x10a0028c;
              codeCursor[1] = 0x1045386e;
              curInst = *(int *)(compiler + 0xe28);
              *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
              srcTypeWord = *(int **)(curInst + 0x4c);
              srcBankWord = *(undefined4 *)(curInst + 0x38);
              srcSwizzleWord = *(undefined4 *)(curInst + 0x3c);
              srcIndexWord = *(int *)(curInst + 0x40);
              srcStorageWord = *(int **)(curInst + 0x44);
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                         *(undefined4 *)(curInst + 0x48),srcTypeWord,*(undefined4 *)(curInst + 0x50),
                         *(undefined4 *)(curInst + 0x54),1,1);
              codeCursor = *(undefined4 **)(compiler + 0xe30);
              *codeCursor = 0x10a1028c;
              codeWritePtr2 = codeCursor + 1;
              *codeWritePtr2 = 0x1045106e;
            }
            else {
              if (elementCount == 3) {
                codeCursor = *(undefined4 **)(compiler + 0xe30);
                *codeCursor = 0x10a0028c;
                codeCursor[1] = 0x1045386e;
                curInst = *(int *)(compiler + 0xe28);
                *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                           *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                           *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                           *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                           *(undefined4 *)(curInst + 0x54),1,1);
                codeCursor = *(undefined4 **)(compiler + 0xe30);
                *codeCursor = 0x10a1028c;
                codeCursor[1] = 0x1045106e;
                curInst = *(int *)(compiler + 0xe28);
                *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
                srcTypeWord = *(int **)(curInst + 0x4c);
                srcBankWord = *(undefined4 *)(curInst + 0x38);
                srcSwizzleWord = *(undefined4 *)(curInst + 0x3c);
                srcIndexWord = *(int *)(curInst + 0x40);
                srcStorageWord = *(int **)(curInst + 0x44);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                           *(undefined4 *)(curInst + 0x48),srcTypeWord,*(undefined4 *)(curInst + 0x50),
                           *(undefined4 *)(curInst + 0x54),2,1);
                codeCursor3 = *(uint **)(compiler + 0xe30);
                vectorInstWord2 = 0x10a20000;
              }
              else {
                if (elementCount != 4) goto LAB_97bdde9c;
                codeCursor = *(undefined4 **)(compiler + 0xe30);
                *codeCursor = 0x10a0028c;
                codeCursor[1] = 0x1045386e;
                curInst = *(int *)(compiler + 0xe28);
                *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                           *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                           *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                           *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                           *(undefined4 *)(curInst + 0x54),1,1);
                codeCursor = *(undefined4 **)(compiler + 0xe30);
                *codeCursor = 0x10a1028c;
                codeCursor[1] = 0x1045106e;
                curInst = *(int *)(compiler + 0xe28);
                *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                           *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                           *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                           *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                           *(undefined4 *)(curInst + 0x54),2,1);
                codeCursor = *(undefined4 **)(compiler + 0xe30);
                *codeCursor = 0x10a2028c;
                codeCursor[1] = 0x1045106e;
                curInst = *(int *)(compiler + 0xe28);
                *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
                srcTypeWord = *(int **)(curInst + 0x4c);
                srcBankWord = *(undefined4 *)(curInst + 0x38);
                srcSwizzleWord = *(undefined4 *)(curInst + 0x3c);
                srcIndexWord = *(int *)(curInst + 0x40);
                srcStorageWord = *(int **)(curInst + 0x44);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                           *(undefined4 *)(curInst + 0x48),srcTypeWord,*(undefined4 *)(curInst + 0x50),
                           *(undefined4 *)(curInst + 0x54),3,1);
                codeCursor3 = *(uint **)(compiler + 0xe30);
                vectorInstWord2 = 0x10a30000;
              }
              *codeCursor3 = vectorInstWord2 | 0x28c;
              codeWritePtr2 = codeCursor3 + 1;
              *codeWritePtr2 = 0x1045106e;
            }
            goto LAB_97bdde94;
          }
          if ((*(char *)(inst + 0x1b) != '\0') && (1 < *(byte *)((int)inst + 0x49))) {
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                       inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],0,1);
            curInst = *(int *)(compiler + 0xe28);
            srcTypeWord = *(int **)(curInst + 0x4c);
            srcBankWord = *(undefined4 *)(curInst + 0x38);
            srcSwizzleWord = *(undefined4 *)(curInst + 0x3c);
            srcIndexWord = *(int *)(curInst + 0x40);
            srcStorageWord = *(int **)(curInst + 0x44);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                       *(undefined4 *)(curInst + 0x48),srcTypeWord,*(undefined4 *)(curInst + 0x50),
                       *(undefined4 *)(curInst + 0x54),0,0);
            if (elementCount == 2) {
              chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp2AVRTC,*(undefined4 *)(compiler + 0xe30));
              codeCursor2 = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursor2 + chunkIndex * 4) = 0x10a5112c;
              curInst = *(int *)(compiler + 0xe28);
              *(int *)(compiler + 0xe30) = codeCursor2 + chunkIndex * 4 + 4;
              srcBankWord = *(undefined4 *)(curInst + 0x5c);
              srcSwizzleWord = *(undefined4 *)(curInst + 0x60);
              srcIndexWord = *(int *)(curInst + 100);
              srcStorageWord = *(int **)(curInst + 0x68);
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                         *(undefined4 *)(curInst + 0x6c),*(undefined4 *)(curInst + 0x70),
                         *(undefined4 *)(curInst + 0x74),*(undefined4 *)(curInst + 0x78),1,1);
              chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp2AVRTC,*(undefined4 *)(compiler + 0xe30));
              srcTypeWord = *(int **)(compiler + 0xe30);
              codeWordPtr = srcTypeWord + chunkIndex;
              emittedWord = 0x10a5132c;
LAB_97bdeef0:
              srcTypeWord[chunkIndex] = emittedWord;
              codeWordPtr[1] = 0x10452c84;
            }
            else {
              if (elementCount == 3) {
                chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp3AVRTC,*(undefined4 *)(compiler + 0xe30))
                ;
                codeCursor2 = *(int *)(compiler + 0xe30);
                *(undefined4 *)(codeCursor2 + chunkIndex * 4) = 0x10a5112c;
                curInst = *(int *)(compiler + 0xe28);
                *(int *)(compiler + 0xe30) = codeCursor2 + chunkIndex * 4 + 4;
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                           *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                           *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                           *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                           *(undefined4 *)(curInst + 0x78),1,1);
                chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp3AVRTC,*(undefined4 *)(compiler + 0xe30))
                ;
                codeCursorAddr = *(int *)(compiler + 0xe30);
                *(undefined4 *)(codeCursorAddr + chunkIndex * 4) = 0x10a5112c;
                instruction = *(int *)(compiler + 0xe28);
                *(int *)(compiler + 0xe30) = codeCursorAddr + chunkIndex * 4 + 4;
                srcBankWord = *(undefined4 *)(instruction + 0x5c);
                srcSwizzleWord = *(undefined4 *)(instruction + 0x60);
                srcIndexWord = *(int *)(instruction + 100);
                srcStorageWord = *(int **)(instruction + 0x68);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(instruction + 0x58),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                           *(undefined4 *)(instruction + 0x6c),*(undefined4 *)(instruction + 0x70),
                           *(undefined4 *)(instruction + 0x74),*(undefined4 *)(instruction + 0x78),2,1);
                chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp3AVRTC,*(undefined4 *)(compiler + 0xe30))
                ;
                srcTypeWord = *(int **)(compiler + 0xe30);
                codeWordPtr = srcTypeWord + chunkIndex;
                emittedWord = 0x10a5122c;
                goto LAB_97bdeef0;
              }
              if (elementCount != 4) goto LAB_97bdde9c;
              chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp4AVRTC,*(undefined4 *)(compiler + 0xe30));
              codeCursor2 = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursor2 + chunkIndex * 4) = 0x10a5112c;
              curInst = *(int *)(compiler + 0xe28);
              *(int *)(compiler + 0xe30) = codeCursor2 + chunkIndex * 4 + 4;
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                         *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                         *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                         *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                         *(undefined4 *)(curInst + 0x78),1,1);
              chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp4AVRTC,*(undefined4 *)(compiler + 0xe30));
              codeCursorAddr = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursorAddr + chunkIndex * 4) = 0x10a5112c;
              instruction = *(int *)(compiler + 0xe28);
              *(int *)(compiler + 0xe30) = codeCursorAddr + chunkIndex * 4 + 4;
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(instruction + 0x58),*(undefined4 *)(instruction + 0x5c),
                         *(undefined4 *)(instruction + 0x60),*(undefined4 *)(instruction + 100),
                         *(undefined4 *)(instruction + 0x68),*(undefined4 *)(instruction + 0x6c),
                         *(undefined4 *)(instruction + 0x70),*(undefined4 *)(instruction + 0x74),
                         *(undefined4 *)(instruction + 0x78),2,1);
              chunkIndex = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp4AVRTC,*(undefined4 *)(compiler + 0xe30));
              codeCursorAddr = *(int *)(compiler + 0xe30);
              *(undefined4 *)(codeCursorAddr + chunkIndex * 4) = 0x10a5112c;
              instruction = *(int *)(compiler + 0xe28);
              *(int *)(compiler + 0xe30) = codeCursorAddr + chunkIndex * 4 + 4;
              srcTypeWord = *(int **)(instruction + 0x70);
              srcBankWord = *(undefined4 *)(instruction + 0x5c);
              srcSwizzleWord = *(undefined4 *)(instruction + 0x60);
              srcIndexWord = *(int *)(instruction + 100);
              srcStorageWord = *(int **)(instruction + 0x68);
              ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(instruction + 0x58),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                         *(undefined4 *)(instruction + 0x6c),srcTypeWord,*(undefined4 *)(instruction + 0x74),
                         *(undefined4 *)(instruction + 0x78),3,1);
              chunkWordCount = _glpRTCAddAChunk_97bd7cbc(&_glpOpDp4AVRTC,*(undefined4 *)(compiler + 0xe30));
              codeWordPtr = (int *)(*(int *)(compiler + 0xe30) + chunkWordCount * 4);
              *(undefined4 *)(*(int *)(compiler + 0xe30) + chunkWordCount * 4) = 0x10a5112c;
              codeWordPtr[1] = 0x10452c84;
            }
            *(int **)(compiler + 0xe30) = codeWordPtr + 2;
            goto LAB_97bdde9c;
          }
          if ((*(char *)(inst + 0x12) == '\0') == 0) {
            sourceOffset = 0x54;
          }
          else {
            sourceOffset = 0x30;
          }
          sourceOffset21 = (uint)(*(char *)(inst + 0x12) == '\0') * 0x24;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)((int)inst + sourceOffset + 4),
                     *(undefined4 *)((int)inst + sourceOffset + 8),
                     *(undefined4 *)((int)inst + sourceOffset + 0xc),
                     *(undefined4 *)((int)inst + sourceOffset + 0x10),
                     *(undefined4 *)((int)inst + sourceOffset + 0x14),
                     *(undefined4 *)((int)inst + sourceOffset + 0x18),
                     *(undefined4 *)((int)inst + sourceOffset + 0x1c),
                     *(undefined4 *)((int)inst + sourceOffset + 0x20),
                     *(undefined4 *)((int)inst + sourceOffset + 0x24),0,0);
          curInst = sourceOffset21 + *(int *)(compiler + 0xe28);
          srcTypeWord = *(int **)(curInst + 0x4c);
          srcBankWord = *(undefined4 *)(curInst + 0x38);
          srcSwizzleWord = *(undefined4 *)(curInst + 0x3c);
          srcIndexWord = *(int *)(curInst + 0x40);
          srcStorageWord = *(int **)(curInst + 0x44);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                     *(undefined4 *)(curInst + 0x48),srcTypeWord,*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),0,1);
          if (elementCount == 2) {
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            *codeCursor = 0x1040386e;
            *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,0);
            _PPCRuntimeCompilerBackupRegister(compiler,2);
            _PPCRuntimeCompilerDirtyRegister(compiler,2);
            sourceOffset21 = sourceOffset21 + *(int *)(compiler + 0xe28);
            srcTypeWord = *(int **)(sourceOffset21 + 0x4c);
            srcBankWord = *(undefined4 *)(sourceOffset21 + 0x38);
            srcSwizzleWord = *(undefined4 *)(sourceOffset21 + 0x3c);
            srcIndexWord = *(int *)(sourceOffset21 + 0x40);
            srcStorageWord = *(int **)(sourceOffset21 + 0x44);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(sourceOffset21 + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                       *(undefined4 *)(sourceOffset21 + 0x48),srcTypeWord,*(undefined4 *)(sourceOffset21 + 0x50),
                       *(undefined4 *)(sourceOffset21 + 0x54),1,1);
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            destComponent = 1;
          }
          else if (elementCount == 3) {
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            *codeCursor = 0x1040386e;
            *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,0);
            _PPCRuntimeCompilerBackupRegister(compiler,2);
            _PPCRuntimeCompilerDirtyRegister(compiler,2);
            curInst = sourceOffset21 + *(int *)(compiler + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                       *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                       *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                       *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                       *(undefined4 *)(curInst + 0x54),1,1);
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            *codeCursor = 0x1040386e;
            *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,1);
            _PPCRuntimeCompilerBackupRegister(compiler,2);
            _PPCRuntimeCompilerDirtyRegister(compiler,2);
            sourceOffset21 = sourceOffset21 + *(int *)(compiler + 0xe28);
            srcTypeWord = *(int **)(sourceOffset21 + 0x4c);
            srcBankWord = *(undefined4 *)(sourceOffset21 + 0x38);
            srcSwizzleWord = *(undefined4 *)(sourceOffset21 + 0x3c);
            srcIndexWord = *(int *)(sourceOffset21 + 0x40);
            srcStorageWord = *(int **)(sourceOffset21 + 0x44);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(sourceOffset21 + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                       *(undefined4 *)(sourceOffset21 + 0x48),srcTypeWord,*(undefined4 *)(sourceOffset21 + 0x50),
                       *(undefined4 *)(sourceOffset21 + 0x54),2,1);
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            destComponent = 2;
          }
          else {
            passThroughR4 = extraout_r4_02;
            if (elementCount != 4) goto LAB_97be18e4;
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            *codeCursor = 0x1040386e;
            *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,0);
            _PPCRuntimeCompilerBackupRegister(compiler,2);
            _PPCRuntimeCompilerDirtyRegister(compiler,2);
            curInst = sourceOffset21 + *(int *)(compiler + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                       *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                       *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                       *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                       *(undefined4 *)(curInst + 0x54),1,1);
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            *codeCursor = 0x1040386e;
            *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,1);
            _PPCRuntimeCompilerBackupRegister(compiler,2);
            _PPCRuntimeCompilerDirtyRegister(compiler,2);
            curInst = sourceOffset21 + *(int *)(compiler + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                       *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                       *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                       *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                       *(undefined4 *)(curInst + 0x54),2,1);
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            *codeCursor = 0x1040386e;
            *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
            ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,2);
            _PPCRuntimeCompilerBackupRegister(compiler,2);
            _PPCRuntimeCompilerDirtyRegister(compiler,2);
            sourceOffset21 = sourceOffset21 + *(int *)(compiler + 0xe28);
            srcTypeWord = *(int **)(sourceOffset21 + 0x4c);
            srcBankWord = *(undefined4 *)(sourceOffset21 + 0x38);
            srcSwizzleWord = *(undefined4 *)(sourceOffset21 + 0x3c);
            srcIndexWord = *(int *)(sourceOffset21 + 0x40);
            srcStorageWord = *(int **)(sourceOffset21 + 0x44);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(sourceOffset21 + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                       *(undefined4 *)(sourceOffset21 + 0x48),srcTypeWord,*(undefined4 *)(sourceOffset21 + 0x50),
                       *(undefined4 *)(sourceOffset21 + 0x54),3,1);
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            destComponent = 3;
          }
          *codeCursor = 0x1040386e;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
          goto LAB_97bddea4;
        }
        if (elementCount == 2) {
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],inst[0x12],
                     inst[0x13],inst[0x14],inst[0x15],0,0);
          curInst = *(int *)(compiler + 0xe28);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                     *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                     *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                     *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),0,1);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c00a8c;
          codeCursor[1] = 0x104039ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),1,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c10a8c;
          codeCursor[1] = 0x104011ae;
          codeCursor[2] = 0x3b000210;
          codeCursor[3] = 0x7c43c1ce;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                     *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                     *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                     *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),1,1);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c10a8c;
          codeCursor[1] = 0x104039ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          srcTypeWord = *(int **)(curInst + 0x4c);
          srcBankWord = *(undefined4 *)(curInst + 0x38);
          srcSwizzleWord = *(undefined4 *)(curInst + 0x3c);
          srcIndexWord = *(int *)(curInst + 0x40);
          srcStorageWord = *(int **)(curInst + 0x44);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                     *(undefined4 *)(curInst + 0x48),srcTypeWord,*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),0,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c00a8c;
          codeWritePtr = codeCursor + 1;
          *codeWritePtr = 0x104011ae;
LAB_97bdde5c:
          *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 1;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,1);
          _PPCRuntimeCompilerBackupRegister(compiler,2);
          _PPCRuntimeCompilerDirtyRegister(compiler,2);
          codeWritePtr2 = *(uint **)(compiler + 0xe30);
          ppcWord = 0x7c43c0ce;
          goto LAB_97bdde90;
        }
        if (elementCount == 3) {
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],inst[0x12],
                     inst[0x13],inst[0x14],inst[0x15],0,0);
          curInst = *(int *)(compiler + 0xe28);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                     *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                     *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                     *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),0,1);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c00a8c;
          codeCursor[1] = 0x104039ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),1,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c10a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),2,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c20a8c;
          codeCursor[1] = 0x104011ae;
          codeCursor[2] = 0x3b000210;
          codeCursor[3] = 0x7c43c1ce;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                     *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                     *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                     *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),1,1);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c20a8c;
          codeCursor[1] = 0x104039ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),1,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c10a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),0,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c00a8c;
          codeCursor[1] = 0x104011ae;
          codeCursor[2] = 0x3b200220;
          codeCursor[3] = 0x7c43c9ce;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                     *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                     *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                     *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),2,1);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c00a8c;
          codeCursor[1] = 0x104039ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),1,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c10a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          srcTypeWord = *(int **)(curInst + 0x4c);
          srcBankWord = *(undefined4 *)(curInst + 0x38);
          srcSwizzleWord = *(undefined4 *)(curInst + 0x3c);
          srcIndexWord = *(int *)(curInst + 0x40);
          srcStorageWord = *(int **)(curInst + 0x44);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                     *(undefined4 *)(curInst + 0x48),srcTypeWord,*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),2,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c20a8c;
          codeCursor[1] = 0x104011ae;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,2);
          _PPCRuntimeCompilerBackupRegister(compiler,2);
          _PPCRuntimeCompilerDirtyRegister(compiler,2);
          codeWritePtr = *(undefined4 **)(compiler + 0xe30);
          *codeWritePtr = 0x7c43c8ce;
          goto LAB_97bdde5c;
        }
        passThroughR4 = extraout_r4_00;
        if (elementCount == 4) {
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],inst[0x12],
                     inst[0x13],inst[0x14],inst[0x15],0,0);
          curInst = *(int *)(compiler + 0xe28);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                     *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                     *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                     *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),0,1);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c00a8c;
          codeCursor[1] = 0x104039ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),1,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c10a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),2,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c20a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),3,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c30a8c;
          codeCursor[1] = 0x104011ae;
          codeCursor[2] = 0x3ae00210;
          codeCursor[3] = 0x7c43b9ce;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                     *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                     *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                     *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),1,1);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c30a8c;
          codeCursor[1] = 0x104039ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),2,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c20a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),1,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c10a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),0,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c00a8c;
          codeCursor[1] = 0x104011ae;
          codeCursor[2] = 0x3b000220;
          codeCursor[3] = 0x7c43c1ce;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                     *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                     *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                     *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),2,1);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c00a8c;
          codeCursor[1] = 0x104039ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),1,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c10a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),2,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c20a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),3,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c30a8c;
          codeCursor[1] = 0x104011ae;
          codeCursor[2] = 0x3b200230;
          codeCursor[3] = 0x7c43c9ce;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 4;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),*(undefined4 *)(curInst + 0x5c),
                     *(undefined4 *)(curInst + 0x60),*(undefined4 *)(curInst + 100),
                     *(undefined4 *)(curInst + 0x68),*(undefined4 *)(curInst + 0x6c),
                     *(undefined4 *)(curInst + 0x70),*(undefined4 *)(curInst + 0x74),
                     *(undefined4 *)(curInst + 0x78),3,1);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c30a8c;
          codeCursor[1] = 0x104039ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),2,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c20a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                     *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                     *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                     *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),1,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c10a8c;
          codeCursor[1] = 0x104011ae;
          curInst = *(int *)(compiler + 0xe28);
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          srcTypeWord = *(int **)(curInst + 0x4c);
          srcBankWord = *(undefined4 *)(curInst + 0x38);
          srcSwizzleWord = *(undefined4 *)(curInst + 0x3c);
          srcIndexWord = *(int *)(curInst + 0x40);
          srcStorageWord = *(int **)(curInst + 0x44);
          ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                     *(undefined4 *)(curInst + 0x48),srcTypeWord,*(undefined4 *)(curInst + 0x50),
                     *(undefined4 *)(curInst + 0x54),0,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x10c00a8c;
          codeCursor[1] = 0x104011ae;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,3);
          _PPCRuntimeCompilerBackupRegister(compiler,2);
          _PPCRuntimeCompilerDirtyRegister(compiler,2);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x7c43c8ce;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,2);
          _PPCRuntimeCompilerBackupRegister(compiler,2);
          _PPCRuntimeCompilerDirtyRegister(compiler,2);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x7c43c0ce;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
          ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,1);
          _PPCRuntimeCompilerBackupRegister(compiler,2);
          _PPCRuntimeCompilerDirtyRegister(compiler,2);
          codeWritePtr2 = *(uint **)(compiler + 0xe30);
          ppcWord = 0x7c43b8ce;
          goto LAB_97bdde90;
        }
      }
      else {
        if ((opcode == 0x31) || (opcode == 0x36)) {
          _PPCRuntimeCompilerBackupRegister(compiler,2);
          _PPCRuntimeCompilerDirtyRegister(compiler,2);
          if (elementCount < 2) {
            curInst = *(int *)(compiler + 0xe28);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                       *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                       *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                       *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                       *(undefined4 *)(curInst + 0x54),0,0);
            curInst = *(int *)(compiler + 0xe28);
            srcTypeWord = *(int **)(curInst + 0x70);
            srcBankWord = *(undefined4 *)(curInst + 0x5c);
            srcSwizzleWord = *(undefined4 *)(curInst + 0x60);
            srcIndexWord = *(int *)(curInst + 100);
            srcStorageWord = *(int **)(curInst + 0x68);
            ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                       *(undefined4 *)(curInst + 0x6c),srcTypeWord,*(undefined4 *)(curInst + 0x74),
                       *(undefined4 *)(curInst + 0x78),0,1);
            if (*(char *)(*(int *)(compiler + 0xe28) + 0x21) == '\x01') {
              dimensionByte = *(char *)(*(int *)(compiler + 0xe28) + 5);
              if (dimensionByte == '\x01') {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpSetAllEqualTo1AVRTC;
              }
              else if (dimensionByte == '\x02') {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpSetAllEqualTo2AVRTC;
              }
              else if (dimensionByte == '\x03') {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpSetAllEqualTo3AVRTC;
              }
              else {
                if (dimensionByte != '\x04') goto LAB_97bdf944;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpSetAllEqualTo4AVRTC;
              }
            }
            else {
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSetEqualToAVRTC;
            }
LAB_97bdf930:
            chunkWordCount = _glpRTCAddAChunk_97bd7cbc(opTemplate,codeWritePtr);
            *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + chunkWordCount * 4;
          }
          else {
            codeCursor = *(undefined4 **)(compiler + 0xe30);
            *codeCursor = 0x10a84484;
            *(undefined4 **)(compiler + 0xe30) = codeCursor + 1;
            if (elementCount == 3) {
              loopIndex = 0;
              do {
                curInst = *(int *)(compiler + 0xe28);
                sourceComponent2 = loopIndex;
                if (*(char *)(curInst + 0x48) == '\0') {
                  sourceComponent2 = 0;
                }
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                           *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                           *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                           *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                           *(undefined4 *)(curInst + 0x54),sourceComponent2,0);
                curInst = *(int *)(compiler + 0xe28);
                operandWidth = loopIndex;
                if (*(char *)(curInst + 0x6c) == '\0') {
                  operandWidth = 0;
                }
                loopIndex = loopIndex + 1;
                srcTypeWord = *(int **)(curInst + 0x70);
                srcBankWord = *(undefined4 *)(curInst + 0x5c);
                srcSwizzleWord = *(undefined4 *)(curInst + 0x60);
                srcIndexWord = *(int *)(curInst + 100);
                srcStorageWord = *(int **)(curInst + 0x68);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                           *(undefined4 *)(curInst + 0x6c),srcTypeWord,*(undefined4 *)(curInst + 0x74),
                           *(undefined4 *)(curInst + 0x78),operandWidth,1);
                chunkWordCount = _glpRTCAddAChunk_97bd7cbc
                                  (&_glpOpSetAllEqualTo3AVRTC,*(undefined4 *)(compiler + 0xe30));
                codeCursor2 = *(int *)(compiler + 0xe30);
                *(undefined4 *)(codeCursor2 + chunkWordCount * 4) = 0x10a5112c;
                *(int *)(compiler + 0xe30) = codeCursor2 + chunkWordCount * 4 + 4;
              } while (loopIndex < 3);
LAB_97bdf7ec:
              _PPCRuntimeCompilerBackupRegister(compiler,0);
              _PPCRuntimeCompilerDirtyRegister(compiler,0);
              codeCursor = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpAllAVRTC;
              *codeCursor = 0x10052c84;
              codeWritePtr = codeCursor + 1;
              *(undefined4 **)(compiler + 0xe30) = codeWritePtr;
              goto LAB_97bdf930;
            }
            if (elementCount < 4) {
              if (elementCount == 2) {
                loopIndex = 0;
                do {
                  curInst = *(int *)(compiler + 0xe28);
                  sourceComponent2 = loopIndex;
                  if (*(char *)(curInst + 0x48) == '\0') {
                    sourceComponent2 = 0;
                  }
                  ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                             *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                             *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                             *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                             *(undefined4 *)(curInst + 0x54),sourceComponent2,0);
                  curInst = *(int *)(compiler + 0xe28);
                  operandWidth = loopIndex;
                  if (*(char *)(curInst + 0x6c) == '\0') {
                    operandWidth = 0;
                  }
                  loopIndex = loopIndex + 1;
                  srcTypeWord = *(int **)(curInst + 0x70);
                  srcBankWord = *(undefined4 *)(curInst + 0x5c);
                  srcSwizzleWord = *(undefined4 *)(curInst + 0x60);
                  srcIndexWord = *(int *)(curInst + 100);
                  srcStorageWord = *(int **)(curInst + 0x68);
                  ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                             *(undefined4 *)(curInst + 0x6c),srcTypeWord,*(undefined4 *)(curInst + 0x74),
                             *(undefined4 *)(curInst + 0x78),operandWidth,1);
                  chunkWordCount = _glpRTCAddAChunk_97bd7cbc
                                    (&_glpOpSetAllEqualTo2AVRTC,*(undefined4 *)(compiler + 0xe30));
                  codeCursor2 = *(int *)(compiler + 0xe30);
                  *(undefined4 *)(codeCursor2 + chunkWordCount * 4) = 0x10a5112c;
                  *(int *)(compiler + 0xe30) = codeCursor2 + chunkWordCount * 4 + 4;
                } while (loopIndex < 2);
                goto LAB_97bdf7ec;
              }
            }
            else if (elementCount == 4) {
              loopIndex = 0;
              do {
                curInst = *(int *)(compiler + 0xe28);
                sourceComponent2 = loopIndex;
                if (*(char *)(curInst + 0x48) == '\0') {
                  sourceComponent2 = 0;
                }
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x34),*(undefined4 *)(curInst + 0x38),
                           *(undefined4 *)(curInst + 0x3c),*(undefined4 *)(curInst + 0x40),
                           *(undefined4 *)(curInst + 0x44),*(undefined4 *)(curInst + 0x48),
                           *(undefined4 *)(curInst + 0x4c),*(undefined4 *)(curInst + 0x50),
                           *(undefined4 *)(curInst + 0x54),sourceComponent2,0);
                curInst = *(int *)(compiler + 0xe28);
                operandWidth = loopIndex;
                if (*(char *)(curInst + 0x6c) == '\0') {
                  operandWidth = 0;
                }
                loopIndex = loopIndex + 1;
                srcTypeWord = *(int **)(curInst + 0x70);
                srcBankWord = *(undefined4 *)(curInst + 0x5c);
                srcSwizzleWord = *(undefined4 *)(curInst + 0x60);
                srcIndexWord = *(int *)(curInst + 100);
                srcStorageWord = *(int **)(curInst + 0x68);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(curInst + 0x58),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                           *(undefined4 *)(curInst + 0x6c),srcTypeWord,*(undefined4 *)(curInst + 0x74),
                           *(undefined4 *)(curInst + 0x78),operandWidth,1);
                chunkWordCount = _glpRTCAddAChunk_97bd7cbc
                                  (&_glpOpSetAllEqualTo4AVRTC,*(undefined4 *)(compiler + 0xe30));
                codeCursor2 = *(int *)(compiler + 0xe30);
                *(undefined4 *)(codeCursor2 + chunkWordCount * 4) = 0x10a5112c;
                *(int *)(compiler + 0xe30) = codeCursor2 + chunkWordCount * 4 + 4;
              } while (loopIndex < 4);
              goto LAB_97bdf7ec;
            }
          }
LAB_97bdf944:
          if (opcode == 0x36) {
            codeWritePtr2 = *(uint **)(compiler + 0xe30);
            ppcWord = 0x1048104a;
LAB_97bdde90:
            *codeWritePtr2 = ppcWord;
LAB_97bdde94:
            *(uint **)(compiler + 0xe30) = codeWritePtr2 + 1;
          }
          goto LAB_97bdde9c;
        }
        operandWidth = 0;
        if (elementCount != 0) {
          do {
            _PPCRuntimeCompilerBackupRegister(compiler,2);
            _PPCRuntimeCompilerDirtyRegister(compiler,2);
            programInfo = *(int *)(compiler + 0xe28);
            passThroughR4 = extraout_r4_03;
            if (*(int *)(programInfo + 0x30) != 0) {
              operandOffset = 0;
              componentLoopIndex = 0;
              do {
                programInfo = operandOffset + programInfo;
                sourceComponent = operandWidth;
                if (*(char *)(programInfo + 0x48) == '\0') {
                  sourceComponent = 0;
                }
                uVar22 = componentLoopIndex + 1;
                operandOffset = operandOffset + 0x24;
                srcTypeWord = *(int **)(programInfo + 0x4c);
                srcBankWord = *(undefined4 *)(programInfo + 0x38);
                srcSwizzleWord = *(undefined4 *)(programInfo + 0x3c);
                srcIndexWord = *(int *)(programInfo + 0x40);
                srcStorageWord = *(int **)(programInfo + 0x44);
                ((int (*)())_PPCRuntimeCompilerLoadSourceAV)(compiler,*(undefined4 *)(programInfo + 0x34),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                           *(undefined4 *)(programInfo + 0x48),srcTypeWord,*(undefined4 *)(programInfo + 0x50),
                           *(undefined4 *)(programInfo + 0x54),sourceComponent,componentLoopIndex);
                programInfo = *(int *)(compiler + 0xe28);
                passThroughR4 = extraout_r4_04;
                componentLoopIndex = uVar22;
              } while (uVar22 < *(uint *)(programInfo + 0x30));
            }
            switch(opcode) {
            case 1:
            case 0xb:
            case 0x10:
            case 0x11:
            case 0x13:
            case 0x14:
            case 0x18:
            case 0x2e:
            case 0x38:
            case 0x42:
            case 0x43:
            case 0x44:
            case 0x45:
            case 0x6f:
            case 0x70:
              _PPCRuntimeCompilerDirtyRegister(compiler,0);
              _PPCRuntimeCompilerDirtyRegister(compiler,1);
              passThroughR4 = extraout_r4_05;
              break;
            case 0x48:
              _PPCRuntimeCompilerDirtyRegistersWithIndirectData(compiler);
              passThroughR4 = extraout_r4_06;
            }
            switch(opcode) {
            case 0:
switchD_97bdfc38_caseD_0:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpMovAVRTC;
              break;
            case 1:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpLitAVRTC;
              break;
            case 2:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpAbsAVRTC;
              break;
            case 3:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpCeilAVRTC;
              break;
            case 4:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpFrcAVRTC;
              break;
            case 5:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpFlrAVRTC;
              break;
            default:
              goto switchD_97bdfc38_caseD_6;
            case 7:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSetSignAVRTC;
              break;
            case 8:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpAnyAVRTC;
              break;
            case 9:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpAllAVRTC;
              break;
            case 10:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpNotAVRTC;
              break;
            case 0xb:
              dimension = *(byte *)(*(int *)(compiler + 0xe28) + 5);
              if (dimension == 2) {
                emitResult64 = ((int (*)())_PPCNoiseGeneratorCalculate2DAVRTC)(*(int *)(compiler + 0xe20) + 0x360,
                                    *(undefined4 *)(compiler + 0xe30));
              }
              else if (dimension < 3) {
                if (dimension != 1) goto switchD_97bdfc38_caseD_6;
                emitResult64 = ((int (*)())_PPCNoiseGeneratorCalculate1DAVRTC)(*(int *)(compiler + 0xe20) + 0x360,
                                    *(undefined4 *)(compiler + 0xe30));
              }
              else if (dimension == 3) {
                emitResult64 = ((int (*)())_PPCNoiseGeneratorCalculate3DAVRTC)(*(int *)(compiler + 0xe20) + 0x360,
                                    *(undefined4 *)(compiler + 0xe30));
              }
              else {
                if (dimension != 4) goto switchD_97bdfc38_caseD_6;
                emitResult64 = ((int (*)())_PPCNoiseGeneratorCalculate4DAVRTC)(*(int *)(compiler + 0xe20) + 0x360,
                                    *(undefined4 *)(compiler + 0xe30));
              }
              goto LAB_97be1634;
            case 0xc:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSqrtAVRTC;
              break;
            case 0xd:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpRsqAVRTC;
              break;
            case 0xe:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpRcpAVRTC;
              break;
            case 0x10:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              goto LAB_97be04f0;
            case 0x11:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpExpAVRTC;
              break;
            case 0x12:
              dimension = *(byte *)(*(int *)(compiler + 0xe28) + 5);
              if (dimension == 2) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpLength2AVRTC;
              }
              else if (dimension < 3) {
                if (dimension != 1) goto switchD_97bdfc38_caseD_6;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpLength1AVRTC;
              }
              else if (dimension == 3) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpLength3AVRTC;
              }
              else {
                if (dimension != 4) goto switchD_97bdfc38_caseD_6;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpLength4AVRTC;
              }
              break;
            case 0x13:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpLg2AVRTC;
              break;
            case 0x14:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpLogAVRTC;
              break;
            case 0x15:
              dimension = *(byte *)(*(int *)(compiler + 0xe28) + 5);
              if (dimension == 2) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpNormalise2AVRTC;
              }
              else if (dimension < 3) {
                if (dimension != 1) goto switchD_97bdfc38_caseD_6;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpNormalise1AVRTC;
              }
              else if (dimension == 3) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpNormalise3AVRTC;
              }
              else {
                if (dimension != 4) goto switchD_97bdfc38_caseD_6;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpNormalise4AVRTC;
              }
              break;
            case 0x16:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpDegreesToRadiansAVRTC;
              break;
            case 0x17:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpRadiansToDegreesAVRTC;
              break;
            case 0x18:
              codeCursor = *(undefined4 **)(compiler + 0xe30);
              *codeCursor = 0x1003028c;
              codeWritePtr = codeCursor + 1;
              *(undefined4 **)(compiler + 0xe30) = codeWritePtr;
              chunkWordCount = _glpRTCAddAChunk_97bd7cbc(&_glpOpCosAVRTC,codeWritePtr);
              codeCursorAfter = *(int *)(compiler + 0xe30) + chunkWordCount * 4 + 4;
              *(undefined4 *)(*(int *)(compiler + 0xe30) + chunkWordCount * 4) = 0x10221484;
              *(int *)(compiler + 0xe30) = codeCursorAfter;
              chunkIndex2 = _glpRTCAddAChunk_97bd7cbc(&_glpOpSinAVRTC,codeCursorAfter);
              passThroughR4 = (undefined4)chunkIndex2;
              vectorInstWord5 = (int)((ulonglong)chunkIndex2 >> 0x20) * 4;
              codeWritePtr3 = (uint *)(*(int *)(compiler + 0xe30) + vectorInstWord5 + 4);
              *(undefined4 *)(*(int *)(compiler + 0xe30) + vectorInstWord5) = 0x1041132c;
              goto LAB_97be1820;
            case 0x19:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSinAVRTC;
              break;
            case 0x1a:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpCosAVRTC;
              break;
            case 0x1f:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpAddAVRTC;
              break;
            case 0x20:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSubAVRTC;
              break;
            case 0x21:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpModAVRTC;
              break;
            case 0x23:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpMulAVRTC;
              break;
            case 0x24:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpLogicalAndAVRTC;
              break;
            case 0x25:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpLogicalOrAVRTC;
              break;
            case 0x26:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpLogicalXorAVRTC;
              break;
            case 0x27:
              dimension = *(byte *)(*(int *)(compiler + 0xe28) + 5);
              if (dimension == 2) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpDp2AVRTC;
                break;
              }
              if (dimension < 3) {
                if (dimension == 1) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  opTemplate = &_glpOpDp1AVRTC;
                  break;
                }
              }
              else {
                if (dimension == 3) goto switchD_97bdfc38_caseD_28;
                if (dimension == 4) goto switchD_97bdfc38_caseD_29;
              }
              goto switchD_97bdfc38_caseD_6;
            case 0x28:
switchD_97bdfc38_caseD_28:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpDp3AVRTC;
              break;
            case 0x29:
switchD_97bdfc38_caseD_29:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpDp4AVRTC;
              break;
            case 0x2a:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpDphAVRTC;
              break;
            case 0x2b:
              if (*(int *)(*(int *)(compiler + 0xe24) + 0x38) - 0x8b30U < 2) {
                dimension = *(byte *)(*(int *)(compiler + 0xe28) + 5);
                if (dimension == 2) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  opTemplate = &_glpOpDistance2GLSLAVRTC;
                }
                else if (dimension < 3) {
                  if (dimension != 1) goto switchD_97bdfc38_caseD_6;
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  opTemplate = &_glpOpDistance1GLSLAVRTC;
                }
                else if (dimension == 3) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  opTemplate = &_glpOpDistance3GLSLAVRTC;
                }
                else {
                  if (dimension != 4) goto switchD_97bdfc38_caseD_6;
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  opTemplate = &_glpOpDistance4GLSLAVRTC;
                }
              }
              else {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpDistanceARBVPFPAVRTC;
              }
              break;
            case 0x2c:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpMinAVRTC;
              break;
            case 0x2d:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpMaxAVRTC;
              break;
            case 0x2e:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpXpdAVRTC;
              break;
            case 0x2f:
              dimension = *(byte *)(*(int *)(compiler + 0xe28) + 5);
              if (dimension == 2) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpReflect2AVRTC;
              }
              else if (dimension < 3) {
                if (dimension != 1) goto switchD_97bdfc38_caseD_6;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpReflect1AVRTC;
              }
              else if (dimension == 3) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpReflect3AVRTC;
              }
              else {
                if (dimension != 4) goto switchD_97bdfc38_caseD_6;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpReflect4AVRTC;
              }
              break;
            case 0x30:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpStrAVRTC;
              break;
            case 0x32:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSgeAVRTC;
              break;
            case 0x33:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSgtAVRTC;
              break;
            case 0x34:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSleAVRTC;
              break;
            case 0x35:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSltAVRTC;
              break;
            case 0x37:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSflAVRTC;
              break;
            case 0x38:
              chunkWordCount = _glpRTCAddAChunk_97bd7cbc(&_glpOpLg2AVRTC,*(undefined4 *)(compiler + 0xe30));
              chunkWordCount = *(int *)(compiler + 0xe30) + chunkWordCount * 4;
              *(int *)(compiler + 0xe30) = chunkWordCount;
              chunkWordCount = _glpRTCAddAChunk_97bd7cbc(&_glpOpMulForPowAVRTC,chunkWordCount);
              codeWritePtr = (undefined4 *)(*(int *)(compiler + 0xe30) + chunkWordCount * 4);
              *(undefined4 **)(compiler + 0xe30) = codeWritePtr;
LAB_97be04f0:
              opTemplate = &_glpOpEx2AVRTC;
              break;
            case 0x39:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpScalarSelectAVRTC;
              break;
            case 0x3a:
              curInst = *(int *)(*(int *)(compiler + 0xe28) + 0x24);
              if (curInst == 1) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpDivideAVRTC;
              }
              else {
                if (curInst != 3) goto switchD_97bdfc38_caseD_6;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpIntegerDivideAVRTC;
              }
              break;
            case 0x3b:
              dimension = *(byte *)(*(int *)(compiler + 0xe28) + 5);
              if (dimension == 2) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpFaceForward2AVRTC;
              }
              else if (dimension < 3) {
                if (dimension != 1) goto switchD_97bdfc38_caseD_6;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpFaceForward1AVRTC;
              }
              else if (dimension == 3) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpFaceForward3AVRTC;
              }
              else {
                if (dimension != 4) goto switchD_97bdfc38_caseD_6;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpFaceForward4AVRTC;
              }
              break;
            case 0x3c:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpLerpAVRTC;
              break;
            case 0x3d:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpClampAVRTC;
              break;
            case 0x3e:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpCmpAVRTC;
              break;
            case 0x3f:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpMadAVRTC;
              break;
            case 0x40:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpSmoothStepAVRTC;
              break;
            case 0x41:
              curInst = *(int *)(compiler + 0xe28);
              srcStorageWord = (int *)(uint)*(byte *)(curInst + 99);
              operandSelector = (uint)*(byte *)(curInst + 0x61);
              srcTypeWord = (int *)(uint)*(byte *)(curInst + 0x62);
              switch(*(undefined1 *)(curInst + 0x60)) {
              case 0:
                if (operandSelector == 0) {
                  operandSelector = 0xffffffff;
                  if ((srcTypeWord == (int *)0x0) && (srcTypeWord = (int *)0xffffffff, srcStorageWord == (int *)0x0)) {
                    srcStorageWord = (int *)0xffffffff;
                  }
LAB_97be06cc:
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord4 = 0x10400000;
LAB_97be07d8:
                  vectorInstWord4 = vectorInstWord4 | 0x28c;
LAB_97be0ad4:
                  *codeWritePtr2 = vectorInstWord4;
LAB_97be0ad8:
                  *(uint **)(compiler + 0xe30) = codeWritePtr2 + 1;
                  break;
                }
                if (operandSelector != 1) goto LAB_97be06cc;
                if (srcTypeWord != (int *)0x2) {
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x1040022c;
                  goto LAB_97be0794;
                }
                if (srcStorageWord != (int *)0x3) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x1040032c;
                  goto LAB_97be077c;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x10400484;
                goto LAB_97be1470;
              case 1:
                if (operandSelector == 1) {
                  operandSelector = 0xffffffff;
                  if ((srcTypeWord == (int *)0x1) && (srcTypeWord = (int *)0xffffffff, srcStorageWord == (int *)0x1)) {
                    srcStorageWord = (int *)0xffffffff;
                  }
LAB_97be0748:
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord4 = 0x10410000;
                  goto LAB_97be07d8;
                }
                if (operandSelector != 2) goto LAB_97be0748;
                if (srcTypeWord != (int *)0x3) {
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x1040032c;
                  goto LAB_97be0794;
                }
                if (srcStorageWord != (int *)0x0) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10400484;
                  goto LAB_97be077c;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x10400000;
                goto LAB_97be13a0;
              case 2:
                if (operandSelector == 2) {
                  operandSelector = 0xffffffff;
                  if ((srcTypeWord == (int *)0x2) && (srcTypeWord = (int *)0xffffffff, srcStorageWord == (int *)0x2)) {
                    srcStorageWord = (int *)0xffffffff;
                  }
LAB_97be07d0:
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord4 = 0x10420000;
                  goto LAB_97be07d8;
                }
                if (operandSelector != 3) goto LAB_97be07d0;
                if (srcTypeWord != (int *)0x0) {
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10400484;
                  goto LAB_97be0794;
                }
                if (srcStorageWord != (int *)0x1) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10400000;
                  goto LAB_97be1050;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x10400000;
                goto LAB_97be1040;
              case 3:
                if (operandSelector == 0) {
                  if (srcTypeWord != (int *)0x1) {
                    codeWritePtr2 = *(uint **)(compiler + 0xe30);
                    vectorInstWord = 0x10400000;
                    goto LAB_97be0c28;
                  }
                  if (srcStorageWord != (int *)0x2) {
                    codeWritePtr3 = *(uint **)(compiler + 0xe30);
                    vectorInstWord = 0x10400000;
                    goto LAB_97be0c18;
                  }
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10400000;
                  goto LAB_97be0c08;
                }
                if (operandSelector != 3) {
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord4 = 0x10400484;
                  goto LAB_97be0ad4;
                }
                if ((srcTypeWord == (int *)0x3) && (srcTypeWord = (int *)0xffffffff, srcStorageWord == (int *)0x3)) {
                  srcStorageWord = (int *)0xffffffff;
                }
                codeWritePtr2 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1043028c;
                goto LAB_97be0794;
              case 4:
                if (operandSelector == 4) {
                  operandSelector = 0xffffffff;
                  if ((srcTypeWord == (int *)0x4) && (srcTypeWord = (int *)0xffffffff, srcStorageWord == (int *)0x4)) {
                    srcStorageWord = (int *)0xffffffff;
                  }
LAB_97be08c4:
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord4 = 0x10400000;
LAB_97be0960:
                  *codeWritePtr = 0x10603cc4;
                  codeWritePtr2 = codeWritePtr + 1;
                  *codeWritePtr2 = vectorInstWord4 | 0x1a8c;
                  goto LAB_97be0ad8;
                }
                if (operandSelector != 5) goto LAB_97be08c4;
                if (srcTypeWord != (int *)0x6) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord3 = 0x10603cc4;
                  vectorInstWord = 0x10431a2c;
                  goto LAB_97be0e64;
                }
                if (srcStorageWord == (int *)0x7) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10403cc4;
                  goto LAB_97be1470;
                }
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                vectorInstWord3 = 0x10603cc4;
                vectorInstWord = 0x10431b2c;
                goto LAB_97be1248;
              case 5:
                if (operandSelector == 5) {
                  operandSelector = 0xffffffff;
                  if ((srcTypeWord == (int *)0x5) && (srcTypeWord = (int *)0xffffffff, srcStorageWord == (int *)0x5)) {
                    srcStorageWord = (int *)0xffffffff;
                  }
LAB_97be0954:
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord4 = 0x10410000;
                  goto LAB_97be0960;
                }
                if (operandSelector != 6) goto LAB_97be0954;
                if (srcTypeWord != (int *)0x7) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord3 = 0x10603cc4;
                  vectorInstWord = 0x10431b2c;
                  goto LAB_97be0e64;
                }
                if (srcStorageWord != (int *)0x4) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10403cc4;
                  goto LAB_97be077c;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x10600000;
                vectorInstWord4 = 0x10430000;
                goto LAB_97be1484;
              case 6:
                if (operandSelector == 6) {
                  operandSelector = 0xffffffff;
                  if ((srcTypeWord == (int *)0x6) && (srcTypeWord = (int *)0xffffffff, srcStorageWord == (int *)0x6)) {
                    srcStorageWord = (int *)0xffffffff;
                  }
LAB_97be09ec:
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord4 = 0x10420000;
                  goto LAB_97be0960;
                }
                if (operandSelector != 7) goto LAB_97be09ec;
                if (srcTypeWord != (int *)0x4) {
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10403cc4;
                  goto LAB_97be0794;
                }
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcStorageWord != (int *)0x5) {
                  vectorInstWord = 0x10430000;
                  goto LAB_97be1338;
                }
                vectorInstWord = 0x10430000;
                goto LAB_97be132c;
              case 7:
                if (operandSelector != 4) {
                  if (operandSelector != 7) {
                    codeWritePtr2 = *(uint **)(compiler + 0xe30);
                    vectorInstWord4 = 0x10403cc4;
                    goto LAB_97be0ad4;
                  }
                  if ((srcTypeWord == (int *)0x7) && (srcTypeWord = (int *)0xffffffff, srcStorageWord == (int *)0x7)) {
                    srcStorageWord = (int *)0xffffffff;
                  }
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord3 = 0x10603cc4;
                  vectorInstWord = 0x10431a8c;
                  goto LAB_97be0e64;
                }
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcTypeWord != (int *)0x5) {
                  vectorInstWord = 0x10430000;
                  goto LAB_97be0fb8;
                }
                vectorInstWord = 0x10430000;
                if (srcStorageWord != (int *)0x6) goto LAB_97be0fac;
                vectorInstWord = 0x10430000;
                goto LAB_97be0ab4;
              case 8:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10484484;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 1;
                if (operandSelector != 8) break;
                if (srcTypeWord != (int *)0x8) goto switchD_97be0ba4_default;
                bVar1 = srcStorageWord == (int *)0x8;
LAB_97be0b40:
                if (bVar1) goto switchD_97bdfc38_caseD_6;
                goto switchD_97be0fe8_default;
              case 9:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x1040038c;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 1;
                if (operandSelector != 9) break;
                if (srcTypeWord == (int *)0x9) {
                  bVar1 = srcStorageWord == (int *)0x9;
                  goto LAB_97be0b40;
                }
                goto switchD_97be0ba4_default;
              case 10:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10483cc4;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 1;
                if (operandSelector == 10) {
                  operandSelector = 0xffffffff;
                  if (srcTypeWord != (int *)0xa) goto switchD_97be0ba4_default;
                  srcTypeWord = (int *)0xffffffff;
                  if (srcStorageWord != (int *)0xa) goto switchD_97be0fe8_default;
                  srcStorageWord = (int *)0xffffffff;
                }
              }
              switch(operandSelector) {
              case 0:
                if (srcTypeWord == (int *)0x0) {
                  bVar1 = srcStorageWord == (int *)0x0;
                  codeCursor3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10600000;
LAB_97be0c50:
                  vectorInstWord = vectorInstWord | 0x28c;
                  goto LAB_97be0c54;
                }
                if (srcTypeWord != (int *)0x1) {
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10420000;
LAB_97be0c28:
                  vectorInstWord = vectorInstWord | 300;
                  goto LAB_97be0794;
                }
                if (srcStorageWord != (int *)0x2) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10420000;
LAB_97be0c18:
                  vectorInstWord = vectorInstWord | 0x22c;
                  goto LAB_97be077c;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x10420000;
LAB_97be0c08:
                vectorInstWord = vectorInstWord | 0x32c;
                goto LAB_97be1470;
              case 1:
                if (srcTypeWord == (int *)0x1) {
                  bVar1 = srcStorageWord == (int *)0x1;
                  codeCursor3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10610000;
                  goto LAB_97be0c50;
                }
                if (srcTypeWord != (int *)0x2) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord3 = 0x1060012c;
                  goto LAB_97be0e60;
                }
                bVar1 = srcStorageWord == (int *)0x3;
                codeCursor3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1060012c;
                goto LAB_97be0c54;
              case 2:
                if (srcTypeWord == (int *)0x2) {
                  bVar1 = srcStorageWord == (int *)0x2;
                  codeCursor3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10620000;
                  goto LAB_97be0c50;
                }
                if (srcTypeWord != (int *)0x3) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord3 = 0x1060022c;
                  goto LAB_97be0e60;
                }
                bVar1 = srcStorageWord == (int *)0x0;
                codeCursor3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1060022c;
                goto LAB_97be0c54;
              case 3:
                if (srcTypeWord != (int *)0x0) {
                  if (srcTypeWord != (int *)0x3) {
                    codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                    vectorInstWord3 = 0x1060032c;
                    goto LAB_97be0e60;
                  }
                  bVar1 = srcStorageWord == (int *)0x3;
                  codeCursor3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10630000;
                  goto LAB_97be0c50;
                }
                bVar1 = srcStorageWord == (int *)0x1;
                codeCursor3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1060032c;
LAB_97be0c54:
                *codeCursor3 = vectorInstWord;
                codeWritePtr2 = codeCursor3 + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
LAB_97be0f9c:
                if (!bVar1) {
                  vectorInstWord = 0x10420000;
LAB_97be0fac:
                  vectorInstWord = vectorInstWord | 0x1a2c;
                  goto LAB_97be133c;
                }
                vectorInstWord = 0x10420000;
LAB_97be0ab4:
                vectorInstWord = vectorInstWord | 0x1b2c;
                goto LAB_97be181c;
              case 4:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcTypeWord == (int *)0x4) {
                  bVar1 = srcStorageWord == (int *)0x4;
                  vectorInstWord = 0x10600000;
LAB_97be0da4:
                  *codeWritePtr2 = vectorInstWord | 0x1a8c;
                  goto LAB_97be0e24;
                }
                if (srcTypeWord == (int *)0x5) {
                  bVar1 = srcStorageWord == (int *)0x6;
                  goto LAB_97be0f9c;
                }
                codeWritePtr2 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1042192c;
LAB_97be0794:
                *codeWritePtr2 = vectorInstWord;
                break;
              case 5:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcTypeWord == (int *)0x5) {
                  bVar1 = srcStorageWord == (int *)0x5;
                  vectorInstWord = 0x10610000;
                  goto LAB_97be0da4;
                }
                if (srcTypeWord != (int *)0x6) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord3 = 0x1063192c;
                  goto LAB_97be0e60;
                }
                bVar1 = srcStorageWord == (int *)0x7;
                vectorInstWord = 0x1063192c;
LAB_97be0e1c:
                *codeWritePtr2 = vectorInstWord;
LAB_97be0e24:
                *(uint **)(compiler + 0xe30) = codeWritePtr2 + 1;
                if (!bVar1) {
                  codeWritePtr3 = codeWritePtr2 + 2;
                  codeWritePtr2[1] = 0x10421a2c;
                  goto LAB_97be1344;
                }
                vectorInstWord = 0x10421b2c;
                goto LAB_97be1418;
              case 6:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcTypeWord == (int *)0x6) {
                  bVar1 = srcStorageWord == (int *)0x6;
                  vectorInstWord = 0x10620000;
                  goto LAB_97be0da4;
                }
                if (srcTypeWord == (int *)0x7) {
                  bVar1 = srcStorageWord == (int *)0x4;
                  vectorInstWord = 0x10631a2c;
                  goto LAB_97be0e1c;
                }
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                vectorInstWord3 = 0x10631a2c;
LAB_97be0e60:
                vectorInstWord = 0x1042192c;
LAB_97be0e64:
                *codeWritePtr = vectorInstWord3;
                codeWritePtr2 = codeWritePtr + 1;
                *codeWritePtr2 = vectorInstWord;
                break;
              case 7:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                vectorInstWord6 = codeWritePtr + 1;
                *(undefined4 **)(compiler + 0xe30) = vectorInstWord6;
                if (srcTypeWord == (int *)0x4) {
                  bVar1 = srcStorageWord == (int *)0x5;
                  vectorInstWord3 = 0x10631b2c;
                }
                else {
                  if (srcTypeWord != (int *)0x7) {
                    *vectorInstWord6 = 0x10631b2c;
                    codeWritePtr[2] = 0x1042192c;
                    *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 3;
                    goto switchD_97be0ba4_default;
                  }
                  bVar1 = srcStorageWord == (int *)0x7;
                  vectorInstWord3 = 0x10631a8c;
                }
                *vectorInstWord6 = vectorInstWord3;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 2;
                if (bVar1) {
                  codeWritePtr3 = codeWritePtr + 3;
                  codeWritePtr[2] = 0x10421b2c;
                  goto LAB_97be1820;
                }
                codeWritePtr3 = codeWritePtr + 3;
                codeWritePtr[2] = 0x10421a2c;
                goto LAB_97be1344;
              case 8:
                if (srcTypeWord != (int *)0x8) {
                  codeWritePtr2 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x1042412c;
                  goto LAB_97be0794;
                }
                if (srcStorageWord == (int *)0x8) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x1042432c;
                  goto LAB_97be1470;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1042422c;
                goto LAB_97be077c;
              case 9:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x1060038c;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcTypeWord == (int *)0x9) {
                  bVar1 = srcStorageWord == (int *)0x9;
                  goto LAB_97be0f9c;
                }
LAB_97be0fb4:
                vectorInstWord = 0x10420000;
LAB_97be0fb8:
                *codeWritePtr2 = vectorInstWord | 0x192c;
                break;
              case 10:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10683cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcTypeWord != (int *)0xa) goto LAB_97be0fb4;
                bVar1 = srcStorageWord == (int *)0xa;
                goto LAB_97be0f9c;
              default:
                goto switchD_97be0ba4_default;
              }
              *(uint **)(compiler + 0xe30) = codeWritePtr2 + 1;
switchD_97be0ba4_default:
              switch((int)srcTypeWord) {
              case 0x0:
                if (srcStorageWord == (int *)0x0) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10600000;
LAB_97be1074:
                  vectorInstWord = vectorInstWord | 0x28c;
                  goto LAB_97be107c;
                }
                if (srcStorageWord != (int *)0x1) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10420000;
LAB_97be1050:
                  vectorInstWord = vectorInstWord | 300;
                  goto LAB_97be077c;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x10420000;
LAB_97be1040:
                vectorInstWord = vectorInstWord | 0x22c;
                goto LAB_97be1470;
              case 0x1:
                if (srcStorageWord == (int *)0x1) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10610000;
                  goto LAB_97be1074;
                }
                if (srcStorageWord == (int *)0x2) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x1060012c;
                  goto LAB_97be107c;
                }
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                vectorInstWord3 = 0x1060012c;
LAB_97be1244:
                vectorInstWord = 0x1042192c;
LAB_97be1248:
                *codeWritePtr = vectorInstWord3;
                codeWritePtr3 = codeWritePtr + 1;
                *codeWritePtr3 = vectorInstWord;
                goto LAB_97be0780;
              case 0x2:
                if (srcStorageWord == (int *)0x2) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10620000;
                  goto LAB_97be1074;
                }
                if (srcStorageWord != (int *)0x3) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord3 = 0x1060022c;
                  goto LAB_97be1244;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1060022c;
                goto LAB_97be107c;
              case 0x3:
                if (srcStorageWord != (int *)0x0) {
                  if (srcStorageWord != (int *)0x3) {
                    codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                    vectorInstWord3 = 0x1060032c;
                    goto LAB_97be1244;
                  }
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x10630000;
                  goto LAB_97be1074;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1060032c;
LAB_97be107c:
                vectorInstWord4 = 0x10421a2c;
                goto LAB_97be148c;
              case 0x4:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcStorageWord == (int *)0x4) {
                  vectorInstWord = 0x10600000;
LAB_97be11c0:
                  vectorInstWord = vectorInstWord | 0x1a8c;
                  goto LAB_97be1290;
                }
                if (srcStorageWord != (int *)0x5) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x1042192c;
                  goto LAB_97be077c;
                }
                codeWritePtr3 = codeWritePtr + 2;
                *codeWritePtr2 = 0x10421a2c;
                goto LAB_97be1820;
              case 0x5:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcStorageWord == (int *)0x5) {
                  vectorInstWord = 0x10610000;
                  goto LAB_97be11c0;
                }
                if (srcStorageWord != (int *)0x6) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord3 = 0x1063192c;
                  goto LAB_97be1244;
                }
                vectorInstWord = 0x1063192c;
                goto LAB_97be1290;
              case 0x6:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcStorageWord == (int *)0x6) {
                  vectorInstWord = 0x10620000;
                  goto LAB_97be11c0;
                }
                if (srcStorageWord != (int *)0x7) {
                  codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                  vectorInstWord3 = 0x10631a2c;
                  goto LAB_97be1244;
                }
                vectorInstWord = 0x10631a2c;
LAB_97be1290:
                *codeWritePtr2 = vectorInstWord;
                codeWritePtr2[1] = 0x10421a2c;
                *(uint **)(compiler + 0xe30) = codeWritePtr2 + 2;
                goto switchD_97bdfc38_caseD_6;
              case 0x7:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (srcStorageWord == (int *)0x4) {
                  vectorInstWord = 0x10631b2c;
                  goto LAB_97be1290;
                }
                vectorInstWord = 0x10630000;
                if (srcStorageWord == (int *)0x7) goto LAB_97be11c0;
                *codeWritePtr2 = 0x10631b2c;
                codeWritePtr[2] = 0x1042192c;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 3;
                break;
              case 0x8:
                if (srcStorageWord == (int *)0x8) {
                  codeWritePtr3 = *(uint **)(compiler + 0xe30);
                  vectorInstWord = 0x1042422c;
                  goto LAB_97be1470;
                }
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1042412c;
LAB_97be077c:
                *codeWritePtr3 = vectorInstWord;
LAB_97be0780:
                codeWritePtr3 = codeWritePtr3 + 1;
LAB_97be1344:
                *(uint **)(compiler + 0xe30) = codeWritePtr3;
                break;
              case 0x9:
                bVar1 = srcStorageWord == (int *)0x9;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                vectorInstWord3 = 0x1060038c;
                goto LAB_97be1318;
              case 0xa:
                bVar1 = srcStorageWord == (int *)0xa;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                vectorInstWord3 = 0x10683cc4;
LAB_97be1318:
                *codeWritePtr = vectorInstWord3;
                codeWritePtr2 = codeWritePtr + 1;
                *(uint **)(compiler + 0xe30) = codeWritePtr2;
                if (!bVar1) {
                  vectorInstWord = 0x10420000;
LAB_97be1338:
                  vectorInstWord = vectorInstWord | 0x192c;
LAB_97be133c:
                  codeWritePtr3 = codeWritePtr2 + 1;
                  *codeWritePtr2 = vectorInstWord;
                  goto LAB_97be1344;
                }
                vectorInstWord = 0x10420000;
LAB_97be132c:
                vectorInstWord = vectorInstWord | 0x1a2c;
LAB_97be181c:
                codeWritePtr3 = codeWritePtr2 + 1;
                *codeWritePtr2 = vectorInstWord;
                goto LAB_97be1820;
              }
switchD_97be0fe8_default:
              switch((int)srcStorageWord) {
              case 0x0:
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x10420000;
LAB_97be13a0:
                vectorInstWord = vectorInstWord | 300;
                goto LAB_97be1470;
              case 0x1:
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord4 = 0x10420000;
                vectorInstWord = 0x1060012c;
                break;
              case 0x2:
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord4 = 0x10420000;
                vectorInstWord = 0x1060022c;
                break;
              case 0x3:
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord4 = 0x10420000;
                vectorInstWord = 0x1060032c;
                break;
              case 0x4:
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x10600000;
                goto LAB_97be1480;
              case 0x5:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                vectorInstWord = 0x1063192c;
                goto LAB_97be1404;
              case 0x6:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                vectorInstWord = 0x10631a2c;
                goto LAB_97be1404;
              case 0x7:
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                vectorInstWord = 0x10631b2c;
LAB_97be1404:
                *codeWritePtr = 0x10603cc4;
                codeWritePtr2 = codeWritePtr + 1;
                *codeWritePtr2 = vectorInstWord;
                vectorInstWord = 0x1042192c;
LAB_97be1418:
                codeWritePtr3 = codeWritePtr2 + 2;
                codeWritePtr2[1] = vectorInstWord;
                goto LAB_97be1820;
              case 0x8:
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x1042412c;
LAB_97be1470:
                *codeWritePtr3 = vectorInstWord;
                goto LAB_97be1494;
              case 0x9:
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord4 = 0x10420000;
                vectorInstWord = 0x1060038c;
                break;
              case 0xa:
                codeWritePtr3 = *(uint **)(compiler + 0xe30);
                vectorInstWord = 0x10680000;
LAB_97be1480:
                vectorInstWord4 = 0x10420000;
LAB_97be1484:
                vectorInstWord = vectorInstWord | 0x3cc4;
                break;
              default:
                goto switchD_97bdfc38_caseD_6;
              }
              vectorInstWord4 = vectorInstWord4 | 0x192c;
LAB_97be148c:
              *codeWritePtr3 = vectorInstWord;
              codeWritePtr3 = codeWritePtr3 + 1;
              *codeWritePtr3 = vectorInstWord4;
LAB_97be1494:
              codeWritePtr3 = codeWritePtr3 + 1;
LAB_97be1820:
              *(uint **)(compiler + 0xe30) = codeWritePtr3;
              goto switchD_97bdfc38_caseD_6;
            case 0x42:
            case 0x43:
            case 0x44:
            case 0x45:
              srcStorageWord = *(int **)(compiler + 0xe20);
              if (*(int *)(srcStorageWord[0x360] + 0x38) - 0x8b30U < 2) {
                srcTypeWord = *(int **)(*(int *)(compiler + 0xe28) + 0x58);
                uVar8 = *(undefined4 *)
                         (srcStorageWord[*(ushort *)(*(int *)(compiler + 0xe28) + 0x68) + 0x361] + *srcTypeWord);
              }
              else {
                uVar8 = *(undefined4 *)(*(int *)(compiler + 0xe28) + 0x10c);
              }
              ((int (*)())_PPCTextureSamplerAttachGLDContext)(*(undefined4 *)(compiler + 0xe1c),srcStorageWord[0x367]);
              projectionEnabled = 0;
              if ((opcode == 0x43) || (opcode == 0x45)) {
                projectionEnabled = 1;
              }
              ((int (*)())_PPCTextureSamplerSetProjectionEnabled)(*(undefined4 *)(compiler + 0xe1c),projectionEnabled);
              ((int (*)())_PPCTextureSamplerSetLodBiasEnabled)(*(undefined4 *)(compiler + 0xe1c),(uint)(opcode - 0x44U < 2));
              if (((opcode == 0x44) &&
                  (programInfo = *(int *)(*(int *)(*(int *)(compiler + 0xe20) + 0xd80) + 0x38),
                  programInfo != 0x8b30)) && (programInfo != 0x8b31)) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                *codeWritePtr = 0x1043028c;
                codeWritePtr[1] = 0x1000436a;
                *(undefined4 **)(compiler + 0xe30) = codeWritePtr + 2;
              }
              uVar7 = *(uint *)(*(int *)(compiler + 0xe28) + 0x110);
              if (uVar7 == 2) {
                srcBankWord = *(undefined4 *)(compiler + 0xe30);
                emitResult64 = ((int (*)())_PPCTextureSamplerSampleTexelRECTRTCAV)(*(undefined4 *)(compiler + 0xe1c),uVar8,srcBankWord);
              }
              else {
                passThroughR4 = extraout_r4_07;
                if (uVar7 < 3) {
                  if (uVar7 != 1) goto switchD_97bdfc38_caseD_6;
                  srcBankWord = *(undefined4 *)(compiler + 0xe30);
                  emitResult64 = ((int (*)())_PPCTextureSamplerSampleTexel3DRTCAV)(*(undefined4 *)(compiler + 0xe1c),uVar8,srcBankWord);
                }
                else if (uVar7 == 3) {
                  srcBankWord = *(undefined4 *)(compiler + 0xe30);
                  emitResult64 = ((int (*)())_PPCTextureSamplerSampleTexel2DRTCAV)(*(undefined4 *)(compiler + 0xe1c),uVar8,srcBankWord);
                }
                else {
                  if (uVar7 != 4) goto switchD_97bdfc38_caseD_6;
                  srcBankWord = *(undefined4 *)(compiler + 0xe30);
                  emitResult64 = ((int (*)())_PPCTextureSamplerSampleTexel1DRTCAV)(*(undefined4 *)(compiler + 0xe1c),uVar8,srcBankWord);
                }
              }
LAB_97be1634:
              passThroughR4 = (undefined4)emitResult64;
              *(int *)(compiler + 0xe30) = (int)((ulonglong)emitResult64 >> 0x20);
              goto switchD_97bdfc38_caseD_6;
            case 0x48:
              if ((*(byte *)(*(int *)(compiler + 0xe28) + 0x28) & 1) != 0) {
                chunkIndex2 = _glpRTCAddAChunk_97bd7cbc(&_glpOpArlAVRTC,*(undefined4 *)(compiler + 0xe30))
                ;
                passThroughR4 = (undefined4)chunkIndex2;
                *(int *)(compiler + 0xe30) =
                     *(int *)(compiler + 0xe30) + (int)((ulonglong)chunkIndex2 >> 0x20) * 4;
              }
            case 0x49:
            case 0x4a:
            case 0x4c:
            case 0x4f:
            case 0x56:
            case 0x57:
            case 0x59:
            case 0x5a:
            case 0x5b:
            case 0x6a:
              goto switchD_97bdfc38_caseD_49;
            case 0x4b:
              curInst = *(int *)(compiler + 0xe28);
              srcBankWord = *(undefined4 *)(curInst + 0x10);
              srcSwizzleWord = *(undefined4 *)(curInst + 0x14);
              srcIndexWord = *(int *)(curInst + 0x18);
              srcStorageWord = *(int **)(curInst + 0x1c);
              ((int (*)())_PPCRuntimeCompilerTestConditionRegisterAV)(compiler,*(undefined4 *)(curInst + 0xc),srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,
                         *(undefined4 *)(curInst + 0x20),*(undefined4 *)(curInst + 0x24),
                         *(undefined4 *)(curInst + 0x28));
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              *codeWritePtr = 0x10634e86;
              codeWritePtr[1] = 0x4098000c;
              codeWritePtr[2] = 0x419a0008;
              srcTypeWord = codeWritePtr + 3;
              passThroughR4 = extraout_r4_08;
              goto LAB_97be16ec;
            case 0x4d:
              codeWritePtr2 = *(uint **)(compiler + 0xe30);
              *codeWritePtr2 = *(int *)(compiler + 0xe40) - (int)codeWritePtr2 & 0x3fffffcU | 0x48000000;
              *(uint **)(compiler + 0xe30) = codeWritePtr2 + 1;
              goto switchD_97bdfc38_caseD_49;
            case 0x54:
            case 0x58:
              codeWordPtr = *(int **)(*(int *)(compiler + 0xe20) + 0xd80);
              curInst = *codeWordPtr + *(int *)(*(int *)(compiler + 0xe28) + 8) * 0x11c;
              if ((uint)codeWordPtr[1] < curInst - 0x11cU) {
                codeWritePtr2 = *(uint **)(compiler + 0xe30);
                uVar7 = *(int *)(compiler + 0xe40) - (int)codeWritePtr2;
              }
              else {
                codeWritePtr2 = *(uint **)(compiler + 0xe30);
                uVar7 = *(int *)(curInst + -4) - ((int)codeWritePtr2 - *(int *)(compiler + 0xe2c));
              }
              *codeWritePtr2 = uVar7 & 0x3fffffc | 0x48000000;
              goto LAB_97be17b0;
            case 0x55:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              codeWritePtr[1] = 0x40980008;
              srcTypeWord = codeWritePtr + 2;
              *codeWritePtr = 0x10604cc6;
LAB_97be16ec:
              *(int **)(compiler + 0xe30) = srcTypeWord;
              codeWordPtr = *(int **)(*(int *)(compiler + 0xe20) + 0xd80);
              curInst = *codeWordPtr + *(int *)(*(int *)(compiler + 0xe28) + 8) * 0x11c;
              if ((uint)codeWordPtr[1] < curInst - 0x11cU) {
                uVar7 = *(int *)(compiler + 0xe40) - (int)srcTypeWord;
              }
              else {
                uVar7 = *(int *)(curInst + -4) - ((int)srcTypeWord - *(int *)(compiler + 0xe2c));
              }
              codeWritePtr2 = *(uint **)(compiler + 0xe30);
              *codeWritePtr2 = uVar7 & 0x3fffffc | 0x48000000;
LAB_97be17b0:
              *(uint **)(compiler + 0xe30) = codeWritePtr2 + 1;
switchD_97bdfc38_caseD_49:
              bVar4 = false;
              goto LAB_97be1860;
            case 0x68:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpRefractAVRTC;
              break;
            case 0x6b:
              codeWordPtr = *(int **)(*(int *)(compiler + 0xe20) + 0xd80);
              curInst = *codeWordPtr + *(int *)(*(int *)(compiler + 0xe28) + 8) * 0x11c;
              if ((uint)codeWordPtr[1] < curInst - 0x11cU) {
                codeWritePtr2 = *(uint **)(compiler + 0xe30);
                vectorInstWord = *(int *)(compiler + 0xe40) - (int)codeWritePtr2;
              }
              else {
                codeWritePtr2 = *(uint **)(compiler + 0xe30);
                vectorInstWord = *(int *)(curInst + -4) - ((int)codeWritePtr2 - *(int *)(compiler + 0xe2c));
              }
              vectorInstWord = vectorInstWord & 0x3fffffc | 0x48000000;
              bVar4 = false;
              goto LAB_97be181c;
            case 0x6c:
              curInst = *(int *)(compiler + 0xe28);
              if ((*(int *)(curInst + 0x24) == 3) && (*(int *)(curInst + 0x4c) == 1)) {
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpTruncateAVRTC;
              }
              else {
                if ((*(int *)(curInst + 0x24) != 4) ||
                   ((*(int *)(curInst + 0x4c) != 1 && (*(int *)(curInst + 0x4c) != 3))))
                goto switchD_97bdfc38_caseD_0;
                codeWritePtr = *(undefined4 **)(compiler + 0xe30);
                opTemplate = &_glpOpSetNotEqualToZeroAVRTC;
              }
              break;
            case 0x6d:
              codeWritePtr = *(undefined4 **)(compiler + 0xe30);
              opTemplate = &_glpOpDestinationScalarSelectAVRTC;
              break;
            case 0x6f:
              codeCursor4 = *(undefined4 **)(compiler + 0xe30);
              *codeCursor4 = 0x39e001b0;
              codeCursor4[1] = 0x7c6378ce;
              codeWritePtr = codeCursor4 + 3;
              codeCursor4[2] = 0x100038ee;
              opTemplate = &_glpOpEx2AVRTC;
              *(undefined4 **)(compiler + 0xe30) = codeWritePtr;
              break;
            case 0x70:
              chunkIndex2 = _glpRTCAddAChunk_97bd7cbc(&_glpOpLg2AVRTC,*(undefined4 *)(compiler + 0xe30));
              passThroughR4 = (undefined4)chunkIndex2;
              srcIndexWord = *(int *)(compiler + 0xe30);
              ppcInstWord = (int)((ulonglong)chunkIndex2 >> 0x20) * 4;
              srcTypeWord = (int *)(srcIndexWord + ppcInstWord);
              srcStorageWord = srcTypeWord + 1;
              *(undefined4 *)(srcIndexWord + ppcInstWord) = 0x39e001c0;
              srcTypeWord[1] = 0x7c6378ce;
              srcTypeWord[2] = 0x104238ee;
              *(int **)(compiler + 0xe30) = srcTypeWord + 3;
              goto switchD_97bdfc38_caseD_6;
            }
            chunkIndex2 = _glpRTCAddAChunk_97bd7cbc(opTemplate,codeWritePtr);
            passThroughR4 = (undefined4)chunkIndex2;
            *(int *)(compiler + 0xe30) =
                 *(int *)(compiler + 0xe30) + (int)((ulonglong)chunkIndex2 >> 0x20) * 4;
switchD_97bdfc38_caseD_6:
            if (bVar4) {
              if (saturateFlag != '\0') {
                chunkWordCount = _glpRTCAddAChunk_97bd7cbc
                                  (&_glpOpSaturateAVRTC,*(undefined4 *)(compiler + 0xe30));
                *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + chunkWordCount * 4;
              }
              ((int (*)())_PPCRuntimeCompilerWriteDestinationAV)(compiler,operandWidth);
              passThroughR4 = extraout_r4_09;
            }
LAB_97be1860:
            operandWidth = operandWidth + 1;
          } while (operandWidth < elementCount);
        }
        codeWritePtr4 = *(int *)(compiler + 0xe2c);
        if (codeBufferCapacity - 3000U < (uint)(*(int *)(compiler + 0xe30) - codeWritePtr4)) {
          codeBufferCapacity = codeBufferCapacity + 0x2000;
          emitResult64 = _glpDCBRealloc(codeWritePtr4,codeBufferCapacity);
          codeBufferBase = (int)((ulonglong)emitResult64 >> 0x20);
          passThroughR4 = (undefined4)emitResult64;
          *(int *)(compiler + 0xe2c) = codeBufferBase;
          codeWritePtr4 = codeBufferBase - codeWritePtr4 >> 2;
          if (codeWritePtr4 != 0) {
            codeWritePtr4 = codeWritePtr4 * 4;
            srcTypeWord = (int *)(*(int *)(compiler + 0xe3c) + codeWritePtr4);
            *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + codeWritePtr4;
            srcStorageWord = (int *)(*(int *)(compiler + 0xe40) + codeWritePtr4);
            *(int *)(compiler + 0xe34) = *(int *)(compiler + 0xe34) + codeWritePtr4;
            *(int *)(compiler + 0xe38) = *(int *)(compiler + 0xe38) + codeWritePtr4;
            *(int **)(compiler + 0xe3c) = srcTypeWord;
            *(int **)(compiler + 0xe40) = srcStorageWord;
          }
        }
LAB_97be18e4:
        inst = *(undefined4 **)(compiler + 0xe28);
      }
      programInfo = *(int *)(compiler + 0xe24);
      instructionListHead = inst + 0x47;
      if (inst == *(undefined4 **)(programInfo + 4)) {
        instructionListHead = (undefined4 *)0x0;
      }
      *(undefined4 **)(compiler + 0xe28) = instructionListHead;
    }
    passIndex = *(int *)(compiler + 0xe48);
    if (passIndex == 0) {
      *(undefined4 **)(compiler + 0xe40) = *(undefined4 **)(compiler + 0xe30);
      inst = *(undefined4 **)(compiler + 0xe30);
      while (((uint)inst & 0xf) != 0) {
        *inst = 0x60000000;
        *(undefined4 **)(compiler + 0xe30) = inst + 1;
        inst = inst + 1;
      }
      _PPCRuntimeCompilerInitialise(compiler,1);
      uVar8 = *(undefined4 *)(compiler + 0xe34);
      passThroughR4 = extraout_r4_10;
LAB_97be1ac8:
      passIndex = *(int *)(compiler + 0xe48);
      *(undefined4 *)(compiler + 0xe30) = uVar8;
    }
    else if (passIndex == 1) {
      _PPCRuntimeCompilerBackupRegister(compiler,0);
      _PPCRuntimeCompilerBackupRegister(compiler,1);
      _PPCRuntimeCompilerBackupRegister(compiler,2);
      _PPCRuntimeCompilerDirtyRegistersContainingAttributes(compiler);
      _PPCRuntimeCompilerDirtyRegistersContainingTemps(compiler);
      _PPCRuntimeCompilerDirtyRegistersContainingParams(compiler);
      if (((uint)*(undefined4 **)(compiler + 0xe30) & 0xf) != 0) {
        inst = (undefined4 *)0x60000000;
        codeWritePtr = *(undefined4 **)(compiler + 0xe30);
        do {
          puVar18 = codeWritePtr + 1;
          *codeWritePtr = 0x60000000;
          *(undefined4 **)(compiler + 0xe30) = puVar18;
          codeWritePtr = puVar18;
        } while (((uint)puVar18 & 0xf) != 0);
      }
      _PPCRuntimeCompilerInitialiseVariableInfo(compiler);
      passIndex = *(int *)(compiler + 0xe48);
      *(undefined4 *)(compiler + 0xe38) = *(undefined4 *)(compiler + 0xe30);
      passThroughR4 = extraout_r4_11;
    }
    else {
      if (passIndex == 2) {
        inst = *(undefined4 **)(compiler + 0xe30);
        *(undefined4 **)(compiler + 0xe40) = inst;
        if ((*(int *)(programInfo + 0x38) == 0x8804) || (*(int *)(programInfo + 0x38) == 0x8b30)) {
          if ((*(uint *)(programInfo + 0x34) & 2) != 0) {
            ((int (*)())_PPCRuntimeCompilerWriteFinalFragmentToBuffer)(compiler,passThroughR4,srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,inst,srcTypeWord);
            inst = *(undefined4 **)(compiler + 0xe30);
          }
        }
        else {
          _PPCRuntimeCompilerBackupRegister(compiler,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x39e00010;
          codeCursor[1] = 0x7c0678ce;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          programInfo = _glpRTCAddAChunk_97bd7cbc(&_glpOpClippingAVRTC,codeCursor + 2);
          inst = (undefined4 *)(*(int *)(compiler + 0xe30) + programInfo * 4);
          *(undefined4 **)(compiler + 0xe30) = inst;
        }
        *(undefined4 **)(compiler + 0xe3c) = inst;
        _PPCRuntimeCompilerBackupRegister(compiler,0);
        _PPCRuntimeCompilerBackupRegister(compiler,1);
        _PPCRuntimeCompilerBackupRegister(compiler,2);
        _PPCRuntimeCompilerDirtyRegistersContainingAttributes(compiler);
        _PPCRuntimeCompilerDirtyRegistersContainingTemps(compiler);
        _PPCRuntimeCompilerDirtyRegistersContainingParams(compiler);
        _PPCRuntimeCompilerInitialiseVariableInfo(compiler);
        uVar8 = *(undefined4 *)(compiler + 0xe38);
        passThroughR4 = extraout_r4_12;
        goto LAB_97be1ac8;
      }
      if (passIndex == 3) {
        if ((*(int *)(programInfo + 0x38) == 0x8804) || (*(int *)(programInfo + 0x38) == 0x8b30)) {
          if ((*(uint *)(programInfo + 0x34) & 2) != 0) {
            ((int (*)())_PPCRuntimeCompilerWriteFinalFragmentToBuffer)(compiler,passThroughR4,srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,inst,srcTypeWord);
          }
        }
        else {
          _PPCRuntimeCompilerBackupRegister(compiler,0);
          codeCursor = *(undefined4 **)(compiler + 0xe30);
          *codeCursor = 0x39e00010;
          codeCursor[1] = 0x7c0678ce;
          *(undefined4 **)(compiler + 0xe30) = codeCursor + 2;
          programInfo = _glpRTCAddAChunk_97bd7cbc(&_glpOpClippingAVRTC,codeCursor + 2);
          *(int *)(compiler + 0xe30) = *(int *)(compiler + 0xe30) + programInfo * 4;
        }
        ((int (*)())_PPCRuntimeCompilerStride)(compiler);
        ((int (*)())_PPCRuntimeCompilerLoop)(compiler);
        passIndex = *(int *)(compiler + 0xe48);
        passThroughR4 = extraout_r4_13;
      }
    }
    *(uint *)(compiler + 0xe48) = passIndex + 1U;
    if (3 < passIndex + 1U) {
      ((int (*)())_PPCRuntimeCompilerWriteEpilogAV)(compiler);
      codeWordCount = *(int *)(compiler + 0xe30) - *(int *)(compiler + 0xe2c) >> 2;
      grownCodeBuffer = _glpDCBRealloc(*(int *)(compiler + 0xe2c),codeWordCount << 2);
      *(undefined4 *)(compiler + 0xe2c) = grownCodeBuffer;
                    
                    
      (*_glpPushInstructions)(codeWordCount,grownCodeBuffer,srcBankWord,srcSwizzleWord,srcIndexWord,srcStorageWord,inst,srcTypeWord);
      return;
    }
  } while( true );
}

/* _PPCRuntimeCompilerGetCompiledResult @ 0x97be1be0 (8 bytes) */
int _PPCRuntimeCompilerGetCompiledResult(param_1)
  int param_1;
{
  return *(undefined4 *)(param_1 + 0xe2c);
}

/* _PPCTextureSamplerCreate @ 0x97be1be8 (12 bytes) */
int _PPCTextureSamplerCreate()
{
  undefined4 allocation;
  
  allocation = _calloc(0x2c,1);
  return allocation;
}

/* _PPCTextureSamplerInitialise @ 0x97be1bf4 (16 bytes) */
int _PPCTextureSamplerInitialise(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
  return;
}

/* _PPCTextureSamplerAttachGLDContext @ 0x97be1c08 (8 bytes) */
int _PPCTextureSamplerAttachGLDContext(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  return;
}

/* _PPCTextureSamplerSetProjectionEnabled @ 0x97be1c10 (8 bytes) */
int _PPCTextureSamplerSetProjectionEnabled(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return;
}

/* _PPCTextureSamplerSetLodBiasEnabled @ 0x97be1c18 (8 bytes) */
int _PPCTextureSamplerSetLodBiasEnabled(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x24) = param_2;
  return;
}

/* _PPCTextureSamplerAttachDerivatives @ 0x97be1c20 (12 bytes) */
void _PPCTextureSamplerAttachDerivatives(int param_1,undefined4 param_2,double fparam_1)
{
  *(float *)(param_1 + 0x10) = (float)fparam_1;
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}

/* _glpRTCAddAChunk_97be1c2c @ 0x97be1c2c (48 bytes) */
int _glpRTCAddAChunk_97be1c2c(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = *param_1;
  while (iVar1 != 0) {
    *param_2 = iVar1;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    iVar1 = *param_1;
  }
  return iVar2;
}

/* _PPCTextureSamplerSampleTexel1DRTCNO @ 0x97be1c5c (8 bytes) */
int _PPCTextureSamplerSampleTexel1DRTCNO(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  return param_3;
}

/* _PPCTextureSamplerSampleTexel2DRTCNO @ 0x97be1c64 (560 bytes) */
int _PPCTextureSamplerSampleTexel2DRTCNO(sampler, textureUnit, codeCursor)
  int *sampler;
  uint textureUnit;
  uint *codeCursor;
{
  int coordChunkWordCount;
  short wrapModeS;
  short wrapModeT;
  uint emittedWord;
  int *textureObject;
  undefined *coordChunk;
  int sampleWordCount;
  int borderMode;
  uint *emitPtr;
  
  if (7 < textureUnit) {
    textureUnit = 7;
  }
  textureObject = *(int **)(textureUnit * 4 + *sampler);
  if (textureObject != (int *)0x0) {
    sampler[1] = (int)textureObject;
    wrapModeS = *(short *)(*textureObject + 0x10);
    wrapModeT = *(short *)(*textureObject + 0x12);
    if ((wrapModeS == -0x7ed3) || (wrapModeT == -0x7ed3)) {
      borderMode = 0x812d;
    }
    else if ((wrapModeS == 0x2900) || (borderMode = 0, wrapModeT == 0x2900)) {
      borderMode = 0x2900;
    }
    if (((sampler[5] != textureUnit) || (sampler[6] != 3)) || (sampler[7] != borderMode)) {
      *codeCursor = textureUnit * 4 & 0xfffc | 0x82220000;
      emitPtr = codeCursor + 1;
      if (wrapModeS == 0x2901) {
        *emitPtr = 0x82910160;
        emitPtr = codeCursor + 2;
      }
      if (wrapModeT == 0x2901) {
        *emitPtr = 0x82b10164;
        emitPtr = emitPtr + 1;
      }
      if (borderMode == 0x812d) {
        *emitPtr = 0x82510190;
        emitPtr[1] = 0xc1d10170;
        emitPtr[2] = 0xc1f10174;
        emittedWord = 0x823101c4;
      }
      else if (borderMode == 0x2900) {
        *emitPtr = 0x82510190;
        emitPtr[1] = 0xc1d10170;
        emitPtr[2] = 0xc1f10174;
        emittedWord = 0x823101c8;
      }
      else {
        *emitPtr = 0x82510140;
        emitPtr[1] = 0xc1d10120;
        emitPtr[2] = 0xc1f10124;
        emittedWord = 0x823101c0;
      }
      emitPtr[3] = emittedWord;
      codeCursor = emitPtr + 4;
      sampler[7] = borderMode;
      sampler[5] = textureUnit;
      sampler[6] = 3;
    }
    if (wrapModeS == 0x2901) {
      if (wrapModeT == 0x2901) {
        coordChunk = &_glpOpTexPrepareCoords2RRRTC;
      }
      else {
        coordChunk = &_glpOpTexPrepareCoords2RCRTC;
      }
    }
    else if (wrapModeT == 0x2901) {
      coordChunk = &_glpOpTexPrepareCoords2CRRTC;
    }
    else {
      coordChunk = &_glpOpTexPrepareCoords2CCRTC;
    }
    coordChunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(coordChunk,codeCursor);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSampleRTC,codeCursor + coordChunkWordCount);
    codeCursor = codeCursor + coordChunkWordCount + sampleWordCount;
  }
  return codeCursor;
}

/* _PPCTextureSamplerSampleTexel3DRTCNO @ 0x97be1e94 (8 bytes) */
int _PPCTextureSamplerSampleTexel3DRTCNO(param_1, param_2, param_3)
  undefined4 param_1;
  undefined4 param_2;
  undefined4 param_3;
{
  return param_3;
}

/* _PPCTextureSamplerSampleTexelRECTRTCNO @ 0x97be1e9c (488 bytes) */
int _PPCTextureSamplerSampleTexelRECTRTCNO(sampler, textureUnit, codeCursor)
  int *sampler;
  uint textureUnit;
  uint *codeCursor;
{
  int coordChunkWordCount;
  short wrapModeS;
  short wrapModeT;
  uint emittedWord;
  int *textureObject;
  int sampleWordCount;
  int borderMode;
  uint *emitPtr;
  
  if (7 < textureUnit) {
    textureUnit = 7;
  }
  textureObject = *(int **)(textureUnit * 4 + *sampler);
  if (textureObject != (int *)0x0) {
    sampler[1] = (int)textureObject;
    wrapModeS = *(short *)(*textureObject + 0x10);
    wrapModeT = *(short *)(*textureObject + 0x12);
    if ((wrapModeS == -0x7ed3) || (wrapModeT == -0x7ed3)) {
      borderMode = 0x812d;
    }
    else if ((wrapModeS == 0x2900) || (borderMode = 0, wrapModeT == 0x2900)) {
      borderMode = 0x2900;
    }
    if ((sampler[5] != textureUnit) || (sampler[6] != 2)) {
      *codeCursor = textureUnit * 4 & 0xfffc | 0x82220000;
      emitPtr = codeCursor + 1;
      if (wrapModeS == 0x2901) {
        *emitPtr = 0x82910160;
        emitPtr = codeCursor + 2;
      }
      if (wrapModeT == 0x2901) {
        *emitPtr = 0x82b10164;
        emitPtr = emitPtr + 1;
      }
      if (borderMode == 0x812d) {
        *emitPtr = 0x82510190;
        emitPtr[1] = 0xc1d10170;
        emitPtr[2] = 0xc1f10174;
        emittedWord = 0x823101c4;
      }
      else if (borderMode == 0x2900) {
        *emitPtr = 0x82510190;
        emitPtr[1] = 0xc1d10170;
        emitPtr[2] = 0xc1f10174;
        emittedWord = 0x823101c8;
      }
      else {
        *emitPtr = 0x82510140;
        emitPtr[1] = 0xc1d10120;
        emitPtr[2] = 0xc1f10124;
        emittedWord = 0x823101c0;
      }
      emitPtr[3] = emittedWord;
      codeCursor = emitPtr + 4;
      sampler[7] = borderMode;
      sampler[5] = textureUnit;
      sampler[6] = 2;
    }
    coordChunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexPrepareCoords4CCRTC,codeCursor);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSampleRTC,codeCursor + coordChunkWordCount);
    codeCursor = codeCursor + coordChunkWordCount + sampleWordCount;
  }
  return codeCursor;
}

/* _PPCTextureSamplerWrapCoordinates1DRTCAV @ 0x97be2084 (144 bytes) */
int _PPCTextureSamplerWrapCoordinates1DRTCAV(sampler, codeCursor)
  int sampler;
  int codeCursor;
{
  short minFilter;
  short wrapModeS;
  undefined *coordChunk;
  int chunkWordCount;
  
  minFilter = *(short *)(**(int **)(sampler + 4) + 0x16);
  wrapModeS = *(short *)(**(int **)(sampler + 4) + 0x10);
  if (((minFilter == 0x2600) || (minFilter == 0x2700)) && (wrapModeS == 0x2900)) {
    wrapModeS = -0x7ed1;
  }
  if (wrapModeS == 0x2901) {
    coordChunk = &_glpOpTexWrapCoordsRRRAVRTC;
  }
  else {
    coordChunk = &_glpOpTexWrapCoordsCCCAVRTC;
  }
  chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(coordChunk,codeCursor);
  return codeCursor + chunkWordCount * 4;
}

/* _PPCTextureSamplerWrapCoordinates2DRTCAV @ 0x97be2114 (212 bytes) */
int _PPCTextureSamplerWrapCoordinates2DRTCAV(sampler, codeCursor)
  int sampler;
  int codeCursor;
{
  int chunkWordCount;
  short wrapModeS;
  undefined *coordChunk;
  int textureState;
  short wrapModeT;
  
  textureState = **(int **)(sampler + 4);
  wrapModeS = *(short *)(textureState + 0x10);
  wrapModeT = *(short *)(textureState + 0x12);
  if ((*(short *)(textureState + 0x16) == 0x2600) || (*(short *)(textureState + 0x16) == 0x2700)) {
    if (wrapModeS == 0x2900) {
      wrapModeS = -0x7ed1;
    }
    if (wrapModeT == 0x2900) {
      wrapModeT = -0x7ed1;
    }
  }
  if (wrapModeS == 0x2901) {
    if (wrapModeT == 0x2901) {
      coordChunk = &_glpOpTexWrapCoordsRRRAVRTC;
    }
    else {
      coordChunk = &_glpOpTexWrapCoordsRCCAVRTC;
    }
  }
  else if (wrapModeT == 0x2901) {
    coordChunk = &_glpOpTexWrapCoordsCRRAVRTC;
  }
  else {
    coordChunk = &_glpOpTexWrapCoordsCCCAVRTC;
  }
  chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(coordChunk,codeCursor);
  return codeCursor + chunkWordCount * 4;
}

/* _PPCTextureSamplerWrapCoordinates3DRTCAV @ 0x97be21e8 (328 bytes) */
int _PPCTextureSamplerWrapCoordinates3DRTCAV(sampler, codeCursor)
  int sampler;
  int codeCursor;
{
  int chunkWordCount;
  short wrapModeS;
  undefined *coordChunk;
  int textureState;
  short wrapModeR;
  short wrapModeT;
  
  textureState = **(int **)(sampler + 4);
  wrapModeS = *(short *)(textureState + 0x10);
  wrapModeT = *(short *)(textureState + 0x12);
  wrapModeR = *(short *)(textureState + 0x14);
  if ((*(short *)(textureState + 0x16) == 0x2600) || (*(short *)(textureState + 0x16) == 0x2700)) {
    if (wrapModeS == 0x2900) {
      wrapModeS = -0x7ed1;
    }
    if (wrapModeT == 0x2900) {
      wrapModeT = -0x7ed1;
    }
    if (wrapModeR == 0x2900) {
      wrapModeR = -0x7ed1;
    }
  }
  if (wrapModeS == 0x2901) {
    if (wrapModeT == 0x2901) {
      if (wrapModeR == 0x2901) {
        coordChunk = &_glpOpTexWrapCoordsRRRAVRTC;
      }
      else {
        coordChunk = &_glpOpTexWrapCoordsRRCAVRTC;
      }
    }
    else if (wrapModeR == 0x2901) {
      coordChunk = &_glpOpTexWrapCoordsRCRAVRTC;
    }
    else {
      coordChunk = &_glpOpTexWrapCoordsRCCAVRTC;
    }
  }
  else if (wrapModeT == 0x2901) {
    if (wrapModeR == 0x2901) {
      coordChunk = &_glpOpTexWrapCoordsCRRAVRTC;
    }
    else {
      coordChunk = &_glpOpTexWrapCoordsCRCAVRTC;
    }
  }
  else if (wrapModeR == 0x2901) {
    coordChunk = &_glpOpTexWrapCoordsCCRAVRTC;
  }
  else {
    coordChunk = &_glpOpTexWrapCoordsCCCAVRTC;
  }
  chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(coordChunk,codeCursor);
  return codeCursor + chunkWordCount * 4;
}

/* _PPCTextureSamplerSampleTexel1DRTCAV @ 0x97be2330 (780 bytes) */
int _PPCTextureSamplerSampleTexel1DRTCAV(sampler, textureUnit, codeCursor)
  int *sampler;
  int textureUnit;
  uint *codeCursor;
{
  undefined4 *resultCursor;
  undefined4 *emitCursor;
  uint *afterLambdaPtr;
  int lambdaWordCount;
  uint unitLoadWord;
  int *textureObject;
  uint *stateEmitPtr;
  
  textureObject = *(int **)(textureUnit * 4 + *sampler);
  if ((uint)(*(ushort *)(*textureObject + 0x16) - 0x2700) < 4) {
    sampler[10] = 1;
    if (sampler[9] != 0) {
      *codeCursor = 0x39e00200;
      codeCursor[1] = 0x7c4379ce;
      codeCursor = codeCursor + 2;
    }
    unitLoadWord = textureUnit * 4 & 0xfffcU | 0x82220000;
    *codeCursor = unitLoadWord;
    codeCursor[1] = 0x39e00120;
    codeCursor[2] = 0x7df178ce;
    codeCursor[3] = 0x39e00040;
    codeCursor[4] = 0x7c2c78ce;
    codeCursor[5] = 0x39ef00c0;
    codeCursor[6] = 0x7c4c78ce;
    lambdaWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexCalculateLambda1DAVRTC,codeCursor + 7);
    afterLambdaPtr = codeCursor + 7 + lambdaWordCount;
    *afterLambdaPtr = 0x39e00040;
    afterLambdaPtr[1] = 0x7c9178ce;
    afterLambdaPtr[2] = 0x1063200a;
    stateEmitPtr = afterLambdaPtr + 3;
    if (sampler[9] != 0) {
      *stateEmitPtr = 0x39e00200;
      afterLambdaPtr[4] = 0x7c4378ce;
      afterLambdaPtr[5] = 0x1063100a;
      stateEmitPtr = afterLambdaPtr + 6;
    }
    *stateEmitPtr = 0x39e00030;
    stateEmitPtr[1] = 0x7c3178ce;
    stateEmitPtr[2] = 0x39e00020;
    stateEmitPtr[3] = 0x7c5178ce;
    stateEmitPtr[4] = 0x1063144a;
    stateEmitPtr[5] = 0x10630c0a;
    stateEmitPtr[6] = 0x10601a8c;
    stateEmitPtr[7] = 0x10801b8a;
    stateEmitPtr[8] = 0x39e00200;
    stateEmitPtr[9] = 0x7c8379ce;
    stateEmitPtr[10] = 0x7f03782e;
    if ((uint)(*(ushort *)(*textureObject + 0x16) - 0x2700) < 2) {
      emitCursor = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(sampler,textureUnit,stateEmitPtr + 0xb);
    }
    else {
      stateEmitPtr[0xb] = 0x10801aca;
      stateEmitPtr[0xc] = 0x1083204a;
      stateEmitPtr[0xd] = 0x39e00210;
      stateEmitPtr[0xe] = 0x7c8379ce;
      stateEmitPtr[0xf] = 0x39e00230;
      stateEmitPtr[0x10] = 0x7c0379ce;
      emitCursor = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(sampler,textureUnit,stateEmitPtr + 0x11);
      *emitCursor = 0x39e00220;
      emitCursor[1] = 0x7c4379ce;
      emitCursor[2] = 0x3b180001;
      emitCursor[3] = 0x39e00230;
      emitCursor[4] = 0x7c0378ce;
      emitCursor[5] = unitLoadWord;
      emitCursor = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(sampler,textureUnit,emitCursor + 6);
      *emitCursor = 0x39e00220;
      emitCursor[1] = 0x7c2378ce;
      emitCursor[2] = 0x39e00210;
      emitCursor[3] = 0x7c0378ce;
      emitCursor[4] = 0x1000028c;
      emitCursor[5] = 0x1068004a;
      emitCursor[6] = 0x1063386e;
      emitCursor[7] = 0x104018ae;
      emitCursor = emitCursor + 8;
    }
    return emitCursor;
  }
  sampler[10] = 0;
  resultCursor = (undefined4 *)((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(sampler,textureUnit,codeCursor);
  return resultCursor;
}

/* _PPCTextureSamplerSampleTexel2DRTCAV @ 0x97be263c (780 bytes) */
int _PPCTextureSamplerSampleTexel2DRTCAV(sampler, textureUnit, codeCursor)
  int *sampler;
  int textureUnit;
  uint *codeCursor;
{
  undefined4 *resultCursor;
  undefined4 *emitCursor;
  uint *afterLambdaPtr;
  int lambdaWordCount;
  uint unitLoadWord;
  int *textureObject;
  uint *stateEmitPtr;
  
  textureObject = *(int **)(textureUnit * 4 + *sampler);
  if ((uint)(*(ushort *)(*textureObject + 0x16) - 0x2700) < 4) {
    sampler[10] = 1;
    if (sampler[9] != 0) {
      *codeCursor = 0x39e00200;
      codeCursor[1] = 0x7c4379ce;
      codeCursor = codeCursor + 2;
    }
    unitLoadWord = textureUnit * 4 & 0xfffcU | 0x82220000;
    *codeCursor = unitLoadWord;
    codeCursor[1] = 0x39e00120;
    codeCursor[2] = 0x7df178ce;
    codeCursor[3] = 0x39e00040;
    codeCursor[4] = 0x7c2c78ce;
    codeCursor[5] = 0x39ef00c0;
    codeCursor[6] = 0x7c4c78ce;
    lambdaWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexCalculateLambda2DAVRTC,codeCursor + 7);
    afterLambdaPtr = codeCursor + 7 + lambdaWordCount;
    *afterLambdaPtr = 0x39e00040;
    afterLambdaPtr[1] = 0x7c9178ce;
    afterLambdaPtr[2] = 0x1063200a;
    stateEmitPtr = afterLambdaPtr + 3;
    if (sampler[9] != 0) {
      *stateEmitPtr = 0x39e00200;
      afterLambdaPtr[4] = 0x7c4378ce;
      afterLambdaPtr[5] = 0x1063100a;
      stateEmitPtr = afterLambdaPtr + 6;
    }
    *stateEmitPtr = 0x39e00030;
    stateEmitPtr[1] = 0x7c3178ce;
    stateEmitPtr[2] = 0x39e00020;
    stateEmitPtr[3] = 0x7c5178ce;
    stateEmitPtr[4] = 0x1063144a;
    stateEmitPtr[5] = 0x10630c0a;
    stateEmitPtr[6] = 0x10601a8c;
    stateEmitPtr[7] = 0x10801b8a;
    stateEmitPtr[8] = 0x39e00200;
    stateEmitPtr[9] = 0x7c8379ce;
    stateEmitPtr[10] = 0x7f03782e;
    if ((uint)(*(ushort *)(*textureObject + 0x16) - 0x2700) < 2) {
      emitCursor = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(sampler,textureUnit,stateEmitPtr + 0xb);
    }
    else {
      stateEmitPtr[0xb] = 0x10801aca;
      stateEmitPtr[0xc] = 0x1083204a;
      stateEmitPtr[0xd] = 0x39e00210;
      stateEmitPtr[0xe] = 0x7c8379ce;
      stateEmitPtr[0xf] = 0x39e00230;
      stateEmitPtr[0x10] = 0x7c0379ce;
      emitCursor = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(sampler,textureUnit,stateEmitPtr + 0x11);
      *emitCursor = 0x39e00220;
      emitCursor[1] = 0x7c4379ce;
      emitCursor[2] = 0x3b180001;
      emitCursor[3] = 0x39e00230;
      emitCursor[4] = 0x7c0378ce;
      emitCursor[5] = unitLoadWord;
      emitCursor = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(sampler,textureUnit,emitCursor + 6);
      *emitCursor = 0x39e00220;
      emitCursor[1] = 0x7c2378ce;
      emitCursor[2] = 0x39e00210;
      emitCursor[3] = 0x7c0378ce;
      emitCursor[4] = 0x1000028c;
      emitCursor[5] = 0x1068004a;
      emitCursor[6] = 0x1063386e;
      emitCursor[7] = 0x104018ae;
      emitCursor = emitCursor + 8;
    }
    return emitCursor;
  }
  sampler[10] = 0;
  resultCursor = (undefined4 *)((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(sampler,textureUnit,codeCursor);
  return resultCursor;
}

/* _PPCTextureSamplerSampleTexel3DRTCAV @ 0x97be2948 (780 bytes) */
int _PPCTextureSamplerSampleTexel3DRTCAV(sampler, textureUnit, codeCursor)
  int *sampler;
  int textureUnit;
  uint *codeCursor;
{
  undefined4 *resultCursor;
  undefined4 *emitCursor;
  uint *afterLambdaPtr;
  int lambdaWordCount;
  uint unitLoadWord;
  int *textureObject;
  uint *stateEmitPtr;
  
  textureObject = *(int **)(textureUnit * 4 + *sampler);
  if ((uint)(*(ushort *)(*textureObject + 0x16) - 0x2700) < 4) {
    sampler[10] = 1;
    if (sampler[9] != 0) {
      *codeCursor = 0x39e00200;
      codeCursor[1] = 0x7c4379ce;
      codeCursor = codeCursor + 2;
    }
    unitLoadWord = textureUnit * 4 & 0xfffcU | 0x82220000;
    *codeCursor = unitLoadWord;
    codeCursor[1] = 0x39e00120;
    codeCursor[2] = 0x7df178ce;
    codeCursor[3] = 0x39e00040;
    codeCursor[4] = 0x7c2c78ce;
    codeCursor[5] = 0x39ef00c0;
    codeCursor[6] = 0x7c4c78ce;
    lambdaWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexCalculateLambda3DAVRTC,codeCursor + 7);
    afterLambdaPtr = codeCursor + 7 + lambdaWordCount;
    *afterLambdaPtr = 0x39e00040;
    afterLambdaPtr[1] = 0x7c9178ce;
    afterLambdaPtr[2] = 0x1063200a;
    stateEmitPtr = afterLambdaPtr + 3;
    if (sampler[9] != 0) {
      *stateEmitPtr = 0x39e00200;
      afterLambdaPtr[4] = 0x7c4378ce;
      afterLambdaPtr[5] = 0x1063100a;
      stateEmitPtr = afterLambdaPtr + 6;
    }
    *stateEmitPtr = 0x39e00030;
    stateEmitPtr[1] = 0x7c3178ce;
    stateEmitPtr[2] = 0x39e00020;
    stateEmitPtr[3] = 0x7c5178ce;
    stateEmitPtr[4] = 0x1063144a;
    stateEmitPtr[5] = 0x10630c0a;
    stateEmitPtr[6] = 0x10601a8c;
    stateEmitPtr[7] = 0x10801b8a;
    stateEmitPtr[8] = 0x39e00200;
    stateEmitPtr[9] = 0x7c8379ce;
    stateEmitPtr[10] = 0x7f03782e;
    if ((uint)(*(ushort *)(*textureObject + 0x16) - 0x2700) < 2) {
      emitCursor = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(sampler,textureUnit,stateEmitPtr + 0xb);
    }
    else {
      stateEmitPtr[0xb] = 0x10801aca;
      stateEmitPtr[0xc] = 0x1083204a;
      stateEmitPtr[0xd] = 0x39e00210;
      stateEmitPtr[0xe] = 0x7c8379ce;
      stateEmitPtr[0xf] = 0x39e00230;
      stateEmitPtr[0x10] = 0x7c0379ce;
      emitCursor = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(sampler,textureUnit,stateEmitPtr + 0x11);
      *emitCursor = 0x39e00220;
      emitCursor[1] = 0x7c4379ce;
      emitCursor[2] = 0x3b180001;
      emitCursor[3] = 0x39e00230;
      emitCursor[4] = 0x7c0378ce;
      emitCursor[5] = unitLoadWord;
      emitCursor = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(sampler,textureUnit,emitCursor + 6);
      *emitCursor = 0x39e00220;
      emitCursor[1] = 0x7c2378ce;
      emitCursor[2] = 0x39e00210;
      emitCursor[3] = 0x7c0378ce;
      emitCursor[4] = 0x1000028c;
      emitCursor[5] = 0x1068004a;
      emitCursor[6] = 0x1063386e;
      emitCursor[7] = 0x104018ae;
      emitCursor = emitCursor + 8;
    }
    return emitCursor;
  }
  sampler[10] = 0;
  resultCursor = (undefined4 *)((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(sampler,textureUnit,codeCursor);
  return resultCursor;
}

/* _PPCTextureSamplerSampleTexel1DFromLevelRTCAV @ 0x97be2c58 (960 bytes) */
int _PPCTextureSamplerSampleTexel1DFromLevelRTCAV(sampler, textureUnit, codeCursor)
  int *sampler;
  uint textureUnit;
  uint *codeCursor;
{
  int sampleWordCount;
  int wrapEndAddr;
  int chunkWordCount;
  bool isLinearFilter;
  short wrapModeS;
  ushort minFilter;
  int lambdaComputed;
  int textureState;
  uint emittedWord;
  int borderMode;
  int *textureObject;
  uint *stateEmitPtr;
  undefined4 *emitPtr;
  
  if (7 < textureUnit) {
    textureUnit = 7;
  }
  textureObject = *(int **)(textureUnit * 4 + *sampler);
  if (textureObject == (int *)0x0) {
    return codeCursor;
  }
  sampler[1] = (int)textureObject;
  textureState = *textureObject;
  borderMode = 0x812d;
  wrapModeS = *(short *)(textureState + 0x10);
  if ((wrapModeS != -0x7ed3) &&
     (((wrapModeS != 0x2900 || (*(short *)(textureState + 0x16) == 0x2600)) ||
      (borderMode = 0x2900, *(short *)(textureState + 0x16) == 0x2700)))) {
    borderMode = 0;
  }
  if (((sampler[5] == textureUnit) && (sampler[6] == 4)) && (sampler[7] == borderMode)) {
    lambdaComputed = sampler[10];
    if (lambdaComputed != 0) goto LAB_97be2d14;
  }
  else {
    lambdaComputed = sampler[10];
LAB_97be2d14:
    if (lambdaComputed == 0) {
      emittedWord = 0x3a310120;
      *codeCursor = textureUnit * 4 & 0xfffc | 0x82220000;
    }
    else {
      *codeCursor = 0x1ef800d0;
      emittedWord = 0x7e31ba14;
      codeCursor = codeCursor + 1;
      *codeCursor = 0x3a310120;
    }
    codeCursor[1] = emittedWord;
    stateEmitPtr = codeCursor + 2;
    if (wrapModeS == 0x2901) {
      *stateEmitPtr = 0x39e00040;
      codeCursor[3] = 0x7e3178ce;
      stateEmitPtr = codeCursor + 4;
    }
    if (borderMode == 0x812d) {
      *stateEmitPtr = 0x82510070;
      stateEmitPtr[1] = 0x39e00050;
      stateEmitPtr[2] = 0x7df178ce;
      stateEmitPtr[3] = 0x39e00080;
      stateEmitPtr[4] = 0x7e1178ce;
      emittedWord = 0x823100a4;
    }
    else if (borderMode == 0x2900) {
      *stateEmitPtr = 0x82510070;
      stateEmitPtr[1] = 0x39e00050;
      stateEmitPtr[2] = 0x7df178ce;
      stateEmitPtr[3] = 0x39e00080;
      stateEmitPtr[4] = 0x7e1178ce;
      emittedWord = 0x823100a8;
    }
    else {
      *stateEmitPtr = 0x82510020;
      stateEmitPtr[1] = 0x39e00000;
      stateEmitPtr[2] = 0x7df178ce;
      stateEmitPtr[3] = 0x39e00030;
      stateEmitPtr[4] = 0x7e1178ce;
      emittedWord = 0x823100a0;
    }
    stateEmitPtr[5] = emittedWord;
    sampler[5] = textureUnit;
    codeCursor = stateEmitPtr + 6;
    sampler[6] = 4;
    sampler[7] = borderMode;
    textureState = *textureObject;
  }
  minFilter = *(ushort *)(textureState + 0x16);
  if (minFilter == 0x2700) {
LAB_97be2ebc:
    if (sampler[8] != 0) {
      chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,codeCursor);
      codeCursor = codeCursor + chunkWordCount;
    }
    chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedAVRTC,codeCursor);
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates1DRTCAV)(sampler,codeCursor + chunkWordCount);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample1DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x10431c84;
  }
  else {
    if (minFilter < 0x2701) {
      if (minFilter == 0x2600) goto LAB_97be2ebc;
      isLinearFilter = minFilter == 0x2601;
LAB_97be2eb4:
      if (!isLinearFilter) {
        return codeCursor;
      }
    }
    else {
      if (minFilter == 0x2702) goto LAB_97be2ebc;
      if (0x2701 < minFilter) {
        isLinearFilter = minFilter == 0x2703;
        goto LAB_97be2eb4;
      }
    }
    if (sampler[8] != 0) {
      chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,codeCursor);
      codeCursor = codeCursor + chunkWordCount;
    }
    chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedWithLERPValuesAVRTC,codeCursor);
    codeCursor[chunkWordCount] = 0x10c00484;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates1DRTCAV)(sampler,codeCursor + chunkWordCount + 1);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample1DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1020228c;
    emitPtr[1] = 0x104138ee;
    emitPtr[2] = 0x100a4b2c;
    emitPtr[3] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates1DRTCAV)(sampler,emitPtr + 4);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample1DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x10202a8c;
    emitPtr = emitPtr + 1;
    *emitPtr = 0x104110ee;
  }
  return emitPtr + 1;
}

/* _PPCTextureSamplerSampleTexel2DFromLevelRTCAV @ 0x97be3018 (1172 bytes) */
int _PPCTextureSamplerSampleTexel2DFromLevelRTCAV(sampler, textureUnit, codeCursor)
  int *sampler;
  uint textureUnit;
  uint *codeCursor;
{
  int sampleWordCount;
  int wrapEndAddr;
  int chunkWordCount;
  bool isLinearFilter;
  short wrapModeS;
  short wrapModeT;
  ushort minFilter;
  int lambdaComputed;
  int textureState;
  uint emittedWord;
  int borderMode;
  int *textureObject;
  uint *stateEmitPtr;
  undefined4 *emitPtr;
  
  if (7 < textureUnit) {
    textureUnit = 7;
  }
  textureObject = *(int **)(textureUnit * 4 + *sampler);
  if (textureObject == (int *)0x0) {
    return codeCursor;
  }
  sampler[1] = (int)textureObject;
  textureState = *textureObject;
  wrapModeS = *(short *)(textureState + 0x10);
  wrapModeT = *(short *)(textureState + 0x12);
  if ((wrapModeS == -0x7ed3) || (wrapModeT == -0x7ed3)) {
    borderMode = 0x812d;
  }
  else if ((((wrapModeS != 0x2900) && (wrapModeT != 0x2900)) || (*(short *)(textureState + 0x16) == 0x2600)) ||
          (borderMode = 0x2900, *(short *)(textureState + 0x16) == 0x2700)) {
    borderMode = 0;
  }
  if (((sampler[5] == textureUnit) && (sampler[6] == 3)) && (sampler[7] == borderMode)) {
    lambdaComputed = sampler[10];
    if (lambdaComputed != 0) goto LAB_97be30f0;
  }
  else {
    lambdaComputed = sampler[10];
LAB_97be30f0:
    if (lambdaComputed == 0) {
      emittedWord = 0x3a310120;
      *codeCursor = textureUnit * 4 & 0xfffc | 0x82220000;
    }
    else {
      *codeCursor = 0x1ef800d0;
      emittedWord = 0x7e31ba14;
      codeCursor = codeCursor + 1;
      *codeCursor = 0x3a310120;
    }
    codeCursor[1] = emittedWord;
    stateEmitPtr = codeCursor + 2;
    if ((wrapModeS == 0x2901) || (wrapModeT == 0x2901)) {
      *stateEmitPtr = 0x39e00040;
      codeCursor[3] = 0x7e3178ce;
      stateEmitPtr = codeCursor + 4;
    }
    if (borderMode == 0x812d) {
      *stateEmitPtr = 0x82510070;
      stateEmitPtr[1] = 0x39e00050;
      stateEmitPtr[2] = 0x7df178ce;
      stateEmitPtr[3] = 0x39e00080;
      stateEmitPtr[4] = 0x7e1178ce;
      emittedWord = 0x823100a4;
    }
    else if (borderMode == 0x2900) {
      *stateEmitPtr = 0x82510070;
      stateEmitPtr[1] = 0x39e00050;
      stateEmitPtr[2] = 0x7df178ce;
      stateEmitPtr[3] = 0x39e00080;
      stateEmitPtr[4] = 0x7e1178ce;
      emittedWord = 0x823100a8;
    }
    else {
      *stateEmitPtr = 0x82510020;
      stateEmitPtr[1] = 0x39e00000;
      stateEmitPtr[2] = 0x7df178ce;
      stateEmitPtr[3] = 0x39e00030;
      stateEmitPtr[4] = 0x7e1178ce;
      emittedWord = 0x823100a0;
    }
    stateEmitPtr[5] = emittedWord;
    sampler[5] = textureUnit;
    codeCursor = stateEmitPtr + 6;
    sampler[6] = 3;
    sampler[7] = borderMode;
    textureState = *textureObject;
  }
  minFilter = *(ushort *)(textureState + 0x16);
  if (minFilter == 0x2700) {
LAB_97be32a0:
    if (sampler[8] != 0) {
      chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,codeCursor);
      codeCursor = codeCursor + chunkWordCount;
    }
    chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedAVRTC,codeCursor);
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(sampler,codeCursor + chunkWordCount);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x10431c84;
  }
  else {
    if (minFilter < 0x2701) {
      if (minFilter == 0x2600) goto LAB_97be32a0;
      isLinearFilter = minFilter == 0x2601;
LAB_97be3298:
      if (!isLinearFilter) {
        return codeCursor;
      }
    }
    else {
      if (minFilter == 0x2702) goto LAB_97be32a0;
      if (0x2701 < minFilter) {
        isLinearFilter = minFilter == 0x2703;
        goto LAB_97be3298;
      }
    }
    if (sampler[8] != 0) {
      chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,codeCursor);
      codeCursor = codeCursor + chunkWordCount;
    }
    chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedWithLERPValuesAVRTC,codeCursor);
    codeCursor[chunkWordCount] = 0x10c00484;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(sampler,codeCursor + chunkWordCount + 1);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1024492c;
    emitPtr[1] = 0x1021392e;
    emitPtr[2] = 0x10200a8c;
    emitPtr[3] = 0x104138ee;
    emitPtr[4] = 0x100a4a2c;
    emitPtr[5] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(sampler,emitPtr + 6);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1025492c;
    emitPtr[1] = 0x1021392e;
    emitPtr[2] = 0x10200a8c;
    emitPtr[3] = 0x104110ee;
    emitPtr[4] = 0x100a4b2c;
    emitPtr[5] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(sampler,emitPtr + 6);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1024492c;
    emitPtr[1] = 0x1021396e;
    emitPtr[2] = 0x10200a8c;
    emitPtr[3] = 0x104110ee;
    emitPtr[4] = 0x1003528c;
    emitPtr[5] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(sampler,emitPtr + 6);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1025492c;
    emitPtr[1] = 0x1021396e;
    emitPtr[2] = 0x10200a8c;
    emitPtr = emitPtr + 3;
    *emitPtr = 0x104110ee;
  }
  return emitPtr + 1;
}

/* _PPCTextureSamplerSampleTexel3DFromLevelRTCAV @ 0x97be34ac (1612 bytes) */
int _PPCTextureSamplerSampleTexel3DFromLevelRTCAV(sampler, textureUnit, codeCursor)
  int *sampler;
  uint textureUnit;
  uint *codeCursor;
{
  int sampleWordCount;
  int wrapEndAddr;
  int chunkWordCount;
  bool isLinearFilter;
  short wrapModeS;
  short wrapModeT;
  ushort minFilter;
  int lambdaComputed;
  int textureState;
  uint emittedWord;
  int *textureObject;
  int borderMode;
  uint *stateEmitPtr;
  undefined4 *emitPtr;
  
  if (7 < textureUnit) {
    textureUnit = 7;
  }
  textureObject = *(int **)(textureUnit * 4 + *sampler);
  if (textureObject == (int *)0x0) {
    return codeCursor;
  }
  sampler[1] = (int)textureObject;
  textureState = *textureObject;
  wrapModeS = *(short *)(textureState + 0x10);
  wrapModeT = *(short *)(textureState + 0x12);
  if (((wrapModeS == -0x7ed3) || (wrapModeT == -0x7ed3)) || (*(short *)(textureState + 0x14) == -0x7ed3)) {
    borderMode = 0x812d;
  }
  else if ((((wrapModeS != 0x2900) && (wrapModeT != 0x2900)) && (*(short *)(textureState + 0x14) != 0x2900)) ||
          ((*(short *)(textureState + 0x16) == 0x2600 ||
           (borderMode = 0x2900, *(short *)(textureState + 0x16) == 0x2700)))) {
    borderMode = 0;
  }
  if (((sampler[5] == textureUnit) && (sampler[6] == 1)) && (sampler[7] == borderMode)) {
    lambdaComputed = sampler[10];
    if (lambdaComputed != 0) goto LAB_97be359c;
  }
  else {
    lambdaComputed = sampler[10];
LAB_97be359c:
    if (lambdaComputed == 0) {
      emittedWord = 0x3a310120;
      *codeCursor = textureUnit * 4 & 0xfffc | 0x82220000;
    }
    else {
      *codeCursor = 0x1ef800d0;
      emittedWord = 0x7e31ba14;
      codeCursor = codeCursor + 1;
      *codeCursor = 0x3a310120;
    }
    codeCursor[1] = emittedWord;
    stateEmitPtr = codeCursor + 2;
    if ((wrapModeS == 0x2901) || (wrapModeT == 0x2901)) {
      *stateEmitPtr = 0x39e00040;
      codeCursor[3] = 0x7e3178ce;
      stateEmitPtr = codeCursor + 4;
    }
    if (borderMode == 0x812d) {
      *stateEmitPtr = 0x82510070;
      stateEmitPtr[1] = 0x82710074;
      stateEmitPtr[2] = 0x39e00050;
      stateEmitPtr[3] = 0x7df178ce;
      stateEmitPtr[4] = 0x39e00080;
      stateEmitPtr[5] = 0x7e1178ce;
      emittedWord = 0x823100a4;
    }
    else if (borderMode == 0x2900) {
      *stateEmitPtr = 0x82510070;
      stateEmitPtr[1] = 0x82710074;
      stateEmitPtr[2] = 0x39e00050;
      stateEmitPtr[3] = 0x7df178ce;
      stateEmitPtr[4] = 0x39e00080;
      stateEmitPtr[5] = 0x7e1178ce;
      emittedWord = 0x823100a8;
    }
    else {
      *stateEmitPtr = 0x82510020;
      stateEmitPtr[1] = 0x82710024;
      stateEmitPtr[2] = 0x39e00000;
      stateEmitPtr[3] = 0x7df178ce;
      stateEmitPtr[4] = 0x39e00030;
      stateEmitPtr[5] = 0x7e1178ce;
      emittedWord = 0x823100a0;
    }
    stateEmitPtr[6] = emittedWord;
    sampler[5] = textureUnit;
    codeCursor = stateEmitPtr + 7;
    sampler[6] = 1;
    sampler[7] = borderMode;
    textureState = *textureObject;
  }
  minFilter = *(ushort *)(textureState + 0x16);
  if (minFilter == 0x2700) {
LAB_97be376c:
    if (sampler[8] != 0) {
      chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,codeCursor);
      codeCursor = codeCursor + chunkWordCount;
    }
    chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedAVRTC,codeCursor);
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(sampler,codeCursor + chunkWordCount);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x10431c84;
  }
  else {
    if (minFilter < 0x2701) {
      if (minFilter == 0x2600) goto LAB_97be376c;
      isLinearFilter = minFilter == 0x2601;
LAB_97be3764:
      if (!isLinearFilter) {
        return codeCursor;
      }
    }
    else {
      if (minFilter == 0x2702) goto LAB_97be376c;
      if (0x2701 < minFilter) {
        isLinearFilter = minFilter == 0x2703;
        goto LAB_97be3764;
      }
    }
    if (sampler[8] != 0) {
      chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,codeCursor);
      codeCursor = codeCursor + chunkWordCount;
    }
    chunkWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedWithLERPValuesAVRTC,codeCursor);
    codeCursor[chunkWordCount] = 0x10c00484;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(sampler,codeCursor + chunkWordCount + 1);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1024492c;
    emitPtr[1] = 0x1021392e;
    emitPtr[2] = 0x10044a2c;
    emitPtr[3] = 0x1021382e;
    emitPtr[4] = 0x10200a8c;
    emitPtr[5] = 0x104138ee;
    emitPtr[6] = 0x100a4a2c;
    emitPtr[7] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(sampler,emitPtr + 8);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1025492c;
    emitPtr[1] = 0x1021392e;
    emitPtr[2] = 0x10044a2c;
    emitPtr[3] = 0x1021382e;
    emitPtr[4] = 0x10200a8c;
    emitPtr[5] = 0x104110ee;
    emitPtr[6] = 0x100a4b2c;
    emitPtr[7] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(sampler,emitPtr + 8);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1024492c;
    emitPtr[1] = 0x1021396e;
    emitPtr[2] = 0x10044a2c;
    emitPtr[3] = 0x1021382e;
    emitPtr[4] = 0x10200a8c;
    emitPtr[5] = 0x104110ee;
    emitPtr[6] = 0x1003528c;
    emitPtr[7] = 0x10004a2c;
    emitPtr[8] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(sampler,emitPtr + 9);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1025492c;
    emitPtr[1] = 0x1021396e;
    emitPtr[2] = 0x10044a2c;
    emitPtr[3] = 0x1021382e;
    emitPtr[4] = 0x10200a8c;
    emitPtr[5] = 0x104110ee;
    emitPtr[6] = 0x100a492c;
    emitPtr[7] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(sampler,emitPtr + 8);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1024492c;
    emitPtr[1] = 0x1021392e;
    emitPtr[2] = 0x10054a2c;
    emitPtr[3] = 0x1021382e;
    emitPtr[4] = 0x10200a8c;
    emitPtr[5] = 0x104110ee;
    emitPtr[6] = 0x1003528c;
    emitPtr[7] = 0x1009032c;
    emitPtr[8] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(sampler,emitPtr + 9);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1025492c;
    emitPtr[1] = 0x1021392e;
    emitPtr[2] = 0x10054a2c;
    emitPtr[3] = 0x1021382e;
    emitPtr[4] = 0x10200a8c;
    emitPtr[5] = 0x104110ee;
    emitPtr[6] = 0x1003528c;
    emitPtr[7] = 0x1000492c;
    emitPtr[8] = 0x1000022c;
    emitPtr[9] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(sampler,emitPtr + 10);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1024492c;
    emitPtr[1] = 0x1021396e;
    emitPtr[2] = 0x10054a2c;
    emitPtr[3] = 0x1021382e;
    emitPtr[4] = 0x10200a8c;
    emitPtr[5] = 0x104110ee;
    emitPtr[6] = 0x1003528c;
    emitPtr[7] = 0x10060780;
    wrapEndAddr = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(sampler,emitPtr + 8);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,wrapEndAddr);
    emitPtr = (undefined4 *)(wrapEndAddr + sampleWordCount * 4);
    *emitPtr = 0x1025492c;
    emitPtr[1] = 0x1021396e;
    emitPtr[2] = 0x10054a2c;
    emitPtr[3] = 0x1021382e;
    emitPtr[4] = 0x10200a8c;
    emitPtr = emitPtr + 5;
    *emitPtr = 0x104110ee;
  }
  return emitPtr + 1;
}

/* _PPCTextureSamplerSampleTexelRECTFromLevelRTCAV @ 0x97be3af8 (1084 bytes) */
int _PPCTextureSamplerSampleTexelRECTFromLevelRTCAV(sampler, textureUnit, codeCursor)
  int *sampler;
  uint textureUnit;
  uint *codeCursor;
{
  int sampleWordCount;
  int chunkWordsThenEnd;
  int floatToIntWordCount;
  uint *emitPtr;
  uint *stateEmitPtr;
  int textureState;
  bool isLinearFilter;
  short wrapModeS;
  short wrapModeT;
  ushort minFilter;
  uint emittedWord;
  int borderMode;
  int *textureObject;
  
  if (7 < textureUnit) {
    textureUnit = 7;
  }
  textureObject = *(int **)(textureUnit * 4 + *sampler);
  if (textureObject == (int *)0x0) {
    return codeCursor;
  }
  sampler[1] = (int)textureObject;
  textureState = *textureObject;
  wrapModeS = *(short *)(textureState + 0x10);
  wrapModeT = *(short *)(textureState + 0x12);
  if ((wrapModeS == -0x7ed3) || (wrapModeT == -0x7ed3)) {
    borderMode = 0x812d;
  }
  else if ((((wrapModeS != 0x2900) && (wrapModeT != 0x2900)) || (*(short *)(textureState + 0x16) == 0x2600)) ||
          (borderMode = 0x2900, *(short *)(textureState + 0x16) == 0x2700)) {
    borderMode = 0;
  }
  if (((sampler[5] != textureUnit) || (sampler[6] != 2)) || (sampler[7] != borderMode)) {
    *codeCursor = textureUnit * 4 & 0xfffc | 0x82220000;
    stateEmitPtr = codeCursor + 1;
    if ((wrapModeS == 0x2901) || (wrapModeT == 0x2901)) {
      *stateEmitPtr = 0x39e00160;
      codeCursor[2] = 0x7e3178ce;
      stateEmitPtr = codeCursor + 3;
    }
    if (borderMode == 0x812d) {
      *stateEmitPtr = 0x82510190;
      stateEmitPtr[1] = 0x39e00170;
      stateEmitPtr[2] = 0x7df178ce;
      stateEmitPtr[3] = 0x39e001a0;
      stateEmitPtr[4] = 0x7e1178ce;
      emittedWord = 0x823101c4;
    }
    else if (borderMode == 0x2900) {
      *stateEmitPtr = 0x82510190;
      stateEmitPtr[1] = 0x39e00170;
      stateEmitPtr[2] = 0x7df178ce;
      stateEmitPtr[3] = 0x39e001a0;
      stateEmitPtr[4] = 0x7e1178ce;
      emittedWord = 0x823101c8;
    }
    else {
      *stateEmitPtr = 0x82510140;
      stateEmitPtr[1] = 0x39e00120;
      stateEmitPtr[2] = 0x7df178ce;
      stateEmitPtr[3] = 0x39e00150;
      stateEmitPtr[4] = 0x7e1178ce;
      emittedWord = 0x823101c0;
    }
    stateEmitPtr[5] = emittedWord;
    sampler[7] = borderMode;
    codeCursor = stateEmitPtr + 6;
    sampler[5] = textureUnit;
    sampler[6] = 2;
    textureState = *textureObject;
  }
  minFilter = *(ushort *)(textureState + 0x16);
  if (minFilter == 0x2700) {
LAB_97be3d34:
    floatToIntWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntDenormalisedAVRTC,codeCursor);
    emitPtr = codeCursor + floatToIntWordCount;
    chunkWordsThenEnd = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,emitPtr);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,emitPtr + chunkWordsThenEnd);
    emitPtr = emitPtr + chunkWordsThenEnd + sampleWordCount;
    *emitPtr = 0x10431c84;
  }
  else {
    if (minFilter < 0x2701) {
      if (minFilter == 0x2600) goto LAB_97be3d34;
      isLinearFilter = minFilter == 0x2601;
LAB_97be3d2c:
      if (!isLinearFilter) {
        return codeCursor;
      }
    }
    else {
      if (minFilter == 0x2702) goto LAB_97be3d34;
      if (0x2701 < minFilter) {
        isLinearFilter = minFilter == 0x2703;
        goto LAB_97be3d2c;
      }
    }
    floatToIntWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntDenormalisedWithLERPValuesAVRTC,codeCursor);
    emitPtr = codeCursor + floatToIntWordCount;
    *emitPtr = 0x10c00484;
    emitPtr = emitPtr + 1;
    chunkWordsThenEnd = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,emitPtr);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,emitPtr + chunkWordsThenEnd);
    emitPtr = emitPtr + chunkWordsThenEnd + sampleWordCount;
    *emitPtr = 0x1024492c;
    emitPtr[1] = 0x1021392e;
    emitPtr[2] = 0x10200a8c;
    emitPtr[3] = 0x104138ee;
    emitPtr[4] = 0x100a4a2c;
    emitPtr[5] = 0x10060780;
    emitPtr = emitPtr + 6;
    chunkWordsThenEnd = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,emitPtr);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,emitPtr + chunkWordsThenEnd);
    emitPtr = emitPtr + chunkWordsThenEnd + sampleWordCount;
    *emitPtr = 0x1025492c;
    emitPtr[1] = 0x1021392e;
    emitPtr[2] = 0x10200a8c;
    emitPtr[3] = 0x104110ee;
    emitPtr[4] = 0x100a4b2c;
    emitPtr[5] = 0x10060780;
    emitPtr = emitPtr + 6;
    chunkWordsThenEnd = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,emitPtr);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,emitPtr + chunkWordsThenEnd);
    emitPtr = emitPtr + chunkWordsThenEnd + sampleWordCount;
    *emitPtr = 0x1024492c;
    emitPtr[1] = 0x1021396e;
    emitPtr[2] = 0x10200a8c;
    emitPtr[3] = 0x104110ee;
    emitPtr[4] = 0x1003528c;
    emitPtr[5] = 0x10060780;
    emitPtr = emitPtr + 6;
    chunkWordsThenEnd = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,emitPtr);
    sampleWordCount = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,emitPtr + chunkWordsThenEnd);
    emitPtr = emitPtr + chunkWordsThenEnd + sampleWordCount;
    *emitPtr = 0x1025492c;
    emitPtr[1] = 0x1021396e;
    emitPtr[2] = 0x10200a8c;
    emitPtr = emitPtr + 3;
    *emitPtr = 0x104110ee;
  }
  return emitPtr + 1;
}

/* _PPCNoiseGeneratorCreate @ 0x97be3f34 (56 bytes) */
int _PPCNoiseGeneratorCreate()
{
  undefined4 allocation;
  
  allocation = _malloc(0xa20);
  ((int (*)())_PPCNoiseGeneratorInitialise)(allocation);
  return allocation;
}

/* _PPCNoiseGeneratorInitialise @ 0x97be3f6c (280 bytes) */
int _PPCNoiseGeneratorInitialise(param_1)
  undefined1 *param_1;
{
  uint loopIndex;
  undefined1 uVar1;
  undefined4 uVar2;
  uint randomResult;
  int iVar4;
  float *pfVar5;
  uint randomResult2;
  undefined1 *puVar7;
  
  _memset(param_1,0,0xa20);
  loopIndex = 0;
  pfVar5 = (float *)(param_1 + 0x210);
  do {
    param_1[loopIndex] = (char)loopIndex;
    randomResult = _random();
    loopIndex = loopIndex + 1;
    *pfVar5 = (float)(((double)CONCAT44(0x43300000,
                                        (randomResult + (((int)randomResult >> 9) +
                                                 (uint)((int)randomResult < 0 && (randomResult & 0x1ff) != 0)) *
                                                 -0x200) - 0x100 ^ 0x80000000) - 4503601774854144.0)
                     * 0.00390625);
    pfVar5 = pfVar5 + 1;
  } while (loopIndex < 0x100);
  puVar7 = param_1 + 0xff;
  do {
    uVar1 = *puVar7;
    randomResult2 = _random();
    iVar4 = randomResult2 + (((int)randomResult2 >> 8) + (uint)((int)randomResult2 < 0 && (randomResult2 & 0xff) != 0)) * -0x100;
    *puVar7 = param_1[iVar4];
    puVar7 = puVar7 + -1;
    param_1[iVar4] = uVar1;
  } while (puVar7 != param_1);
  iVar4 = 0x102;
  puVar7 = param_1;
  do {
    uVar2 = *(undefined4 *)(puVar7 + 0x210);
    param_1[0x100] = *param_1;
    param_1 = param_1 + 1;
    *(undefined4 *)(puVar7 + 0x610) = uVar2;
    puVar7 = puVar7 + 4;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return puVar7;
}

/* _glpRTCAddAChunk_97be4088 @ 0x97be4088 (48 bytes) */
int _glpRTCAddAChunk_97be4088(param_1, param_2)
  int *param_1;
  int *param_2;
{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = *param_1;
  while (iVar1 != 0) {
    *param_2 = iVar1;
    iVar2 = iVar2 + 1;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    iVar1 = *param_1;
  }
  return iVar2;
}

/* _PPCNoiseGeneratorCalculate1DAVRTC @ 0x97be40b8 (228 bytes) */
int _PPCNoiseGeneratorCalculate1DAVRTC(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *vectorInstWord;
  int glpRTCAddAChunkResult;
  int glpRTCAddAChunkResult2;
  uint loopIndex;
  undefined4 *vectorInstWord2;
  
  *param_2 = 0x11a8400a;
  param_2[1] = 0x102b5c84;
  vectorInstWord2 = param_2 + 2;
  loopIndex = 0;
  do {
    loopIndex = loopIndex + 1;
    glpRTCAddAChunkResult = ((int (*)())_glpRTCAddAChunk_97be4088)(&_glpOpFirstStageAVRTC,vectorInstWord2);
    glpRTCAddAChunkResult2 = ((int (*)())_glpRTCAddAChunk_97be4088)(&_glpOpSecondStage1DAVRTC,vectorInstWord2 + glpRTCAddAChunkResult);
    vectorInstWord = vectorInstWord2 + glpRTCAddAChunkResult + glpRTCAddAChunkResult2;
    *vectorInstWord = 0x1122486e;
    vectorInstWord[1] = 0x10003b6e;
    vectorInstWord[2] = 0x10213aee;
    vectorInstWord2 = vectorInstWord + 3;
  } while (loopIndex < 6);
  *vectorInstWord2 = 0x10494c84;
  vectorInstWord[4] = 0x1120038c;
  vectorInstWord[5] = 0x39c00030;
  vectorInstWord[6] = 0x7dae18ce;
  return vectorInstWord + 7;
}

/* _PPCNoiseGeneratorCalculate2DAVRTC @ 0x97be419c (228 bytes) */
int _PPCNoiseGeneratorCalculate2DAVRTC(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *vectorInstWord;
  int glpRTCAddAChunkResult;
  int glpRTCAddAChunkResult2;
  uint loopIndex;
  undefined4 *vectorInstWord2;
  
  *param_2 = 0x11a8400a;
  param_2[1] = 0x102b5c84;
  vectorInstWord2 = param_2 + 2;
  loopIndex = 0;
  do {
    loopIndex = loopIndex + 1;
    glpRTCAddAChunkResult = ((int (*)())_glpRTCAddAChunk_97be4088)(&_glpOpFirstStageAVRTC,vectorInstWord2);
    glpRTCAddAChunkResult2 = ((int (*)())_glpRTCAddAChunk_97be4088)(&_glpOpSecondStage2DAVRTC,vectorInstWord2 + glpRTCAddAChunkResult);
    vectorInstWord = vectorInstWord2 + glpRTCAddAChunkResult + glpRTCAddAChunkResult2;
    *vectorInstWord = 0x1122486e;
    vectorInstWord[1] = 0x10003b6e;
    vectorInstWord[2] = 0x10213aee;
    vectorInstWord2 = vectorInstWord + 3;
  } while (loopIndex < 6);
  *vectorInstWord2 = 0x10494c84;
  vectorInstWord[4] = 0x1120038c;
  vectorInstWord[5] = 0x39c00030;
  vectorInstWord[6] = 0x7dae18ce;
  return vectorInstWord + 7;
}

/* _PPCNoiseGeneratorCalculate3DAVRTC @ 0x97be4280 (228 bytes) */
int _PPCNoiseGeneratorCalculate3DAVRTC(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  undefined4 *vectorInstWord;
  int glpRTCAddAChunkResult;
  int glpRTCAddAChunkResult2;
  uint loopIndex;
  undefined4 *vectorInstWord2;
  
  *param_2 = 0x11a8400a;
  param_2[1] = 0x102b5c84;
  vectorInstWord2 = param_2 + 2;
  loopIndex = 0;
  do {
    loopIndex = loopIndex + 1;
    glpRTCAddAChunkResult = ((int (*)())_glpRTCAddAChunk_97be4088)(&_glpOpFirstStageAVRTC,vectorInstWord2);
    glpRTCAddAChunkResult2 = ((int (*)())_glpRTCAddAChunk_97be4088)(&_glpOpSecondStage3DAVRTC,vectorInstWord2 + glpRTCAddAChunkResult);
    vectorInstWord = vectorInstWord2 + glpRTCAddAChunkResult + glpRTCAddAChunkResult2;
    *vectorInstWord = 0x1122486e;
    vectorInstWord[1] = 0x10003b6e;
    vectorInstWord[2] = 0x10213aee;
    vectorInstWord2 = vectorInstWord + 3;
  } while (loopIndex < 6);
  *vectorInstWord2 = 0x10494c84;
  vectorInstWord[4] = 0x1120038c;
  vectorInstWord[5] = 0x39c00030;
  vectorInstWord[6] = 0x7dae18ce;
  return vectorInstWord + 7;
}

/* _PPCNoiseGeneratorCalculate4DAVRTC @ 0x97be4364 (8 bytes) */
int _PPCNoiseGeneratorCalculate4DAVRTC(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  return param_2;
}

/* _PPCRasterOpMachineCreate @ 0x97be436c (60 bytes) */
int _PPCRasterOpMachineCreate()
{
  undefined4 allocation;
  
  allocation = _calloc(8,1);
  ((int (*)())_PPCRasterOpMachineInitialise)(allocation);
  return allocation;
}

/* _PPCRasterOpMachineInitialise @ 0x97be43a8 (16 bytes) */
int _PPCRasterOpMachineInitialise(param_1)
  undefined4 *param_1;
{
  param_1[1] = 0;
  *param_1 = 0;
  return;
}

/* _PPCRasterOpMachineAttachEmulatorContext @ 0x97be43bc (8 bytes) */
int _PPCRasterOpMachineAttachEmulatorContext(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  return;
}

/* _PPCRasterOpMachineAttachRuntimeCompiler @ 0x97be43c4 (8 bytes) */
int _PPCRasterOpMachineAttachRuntimeCompiler(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}

/* _PPCRasterOpMachine_DepthTestRTCAV @ 0x97be43cc (272 bytes) */
int _PPCRasterOpMachine_DepthTestRTCAV(machine, codeCursor)
  int *machine;
  uint *codeCursor;
{
  uint skipWords;
  uint branchWord;
  uint depthFunc;
  uint depthState;
  int compiler;
  
  compiler = machine[1];
  depthState = *(uint *)(*(int *)(*machine + 0xd80) + 0x50);
  depthFunc = depthState & 7;
  if ((depthFunc != 0) && (depthFunc != 7)) {
    *codeCursor = 0x81e30da8;
    codeCursor[1] = 0xc10f0000;
    codeCursor[2] = 0xfc0d4000;
    codeCursor = codeCursor + 3;
  }
  skipWords = (uint)(*(int *)(compiler + 0xe3c) - (int)codeCursor) >> 2;
  switch(depthState & 7) {
  case 0:
    *codeCursor = (skipWords & 0xffffff) << 2 | 0x48000000;
    goto LAB_97be44f0;
  case 1:
    branchWord = 0x41800000;
    break;
  case 2:
    branchWord = 0x41820000;
    break;
  case 3:
    branchWord = 0x40810000;
    break;
  case 4:
    branchWord = 0x41810000;
    break;
  case 5:
    branchWord = 0x40820000;
    break;
  case 6:
    branchWord = 0x40800000;
    break;
  default:
    goto switchD_97be4464_caseD_7;
  }
  *codeCursor = branchWord | 8;
  codeCursor = codeCursor + 1;
  *codeCursor = (skipWords - 1) * 4 & 0x3fffffc | 0x48000000;
LAB_97be44f0:
  codeCursor = codeCursor + 1;
switchD_97be4464_caseD_7:
  return codeCursor;
}

/* _PPCRasterOpMachine_DepthAndStencilTestRTCAV @ 0x97be44fc (1172 bytes) */
int _PPCRasterOpMachine_DepthAndStencilTestRTCAV(machine, codeCursor)
  int *machine;
  uint *codeCursor;
{
  uint *stencilUpdateCursor;
  uint *finalUpdateCursor;
  uint depthBranchWord;
  uint stencilBranchWord;
  uint *tailEmitPtr;
  bool bufferMaskDisabled;
  uint stencilRef;
  bool stencilEnabled;
  int rasterState;
  uint stencilState;
  uint *emitPtr;
  uint *stencilTestEnd;
  uint depthFunc;
  uint writeMasks;
  uint stageFlags;
  int emulator;
  uint stencilValueMask;
  int compiler;
  uint stencilWriteMask;
  uint *branchFixupPtr;
  
  emulator = *machine;
  branchFixupPtr = (uint *)0x0;
  compiler = machine[1];
  rasterState = *(int *)(emulator + 0xd80);
  stencilState = *(uint *)(rasterState + 0x48);
  stageFlags = *(uint *)(rasterState + 0x3c);
  stencilRef = *(uint *)(rasterState + 0x4c) >> 0x18;
  bufferMaskDisabled = (stageFlags >> 6 & 1) == 0;
  depthFunc = *(uint *)(*(int *)(emulator + 0xd80) + 0x50);
  writeMasks = *(uint *)(*(int *)(emulator + 0xd80) + 0x70);
  if (bufferMaskDisabled) {
    stencilWriteMask = 0xff;
  }
  else {
    stencilWriteMask = writeMasks >> 8 & 0xff;
  }
  stencilEnabled = (stageFlags & 2) != 0;
  stencilValueMask = *(uint *)(rasterState + 0x4c) >> 8 & 0xff;
  if (!stencilEnabled) goto LAB_97be4754;
  *codeCursor = 0x83430dac;
  codeCursor[1] = 0x8b3a0000;
  stencilTestEnd = codeCursor + 2;
  emitPtr = stencilTestEnd;
  switch(stencilState >> 0xc & 7) {
  case 0:
    stencilState = stencilState >> 0xf;
    codeCursor = stencilTestEnd;
    goto LAB_97be47b8;
  case 1:
    *stencilTestEnd = stencilRef & stencilValueMask | 0x3ba00000;
    codeCursor[3] = stencilValueMask | 0x733e0000;
    stencilBranchWord = 0x41800000;
    break;
  case 2:
    *stencilTestEnd = stencilRef & stencilValueMask | 0x3ba00000;
    codeCursor[3] = stencilValueMask | 0x733e0000;
    stencilBranchWord = 0x41820000;
    break;
  case 3:
    *stencilTestEnd = stencilRef & stencilValueMask | 0x3ba00000;
    codeCursor[3] = stencilValueMask | 0x733e0000;
    stencilBranchWord = 0x40810000;
    break;
  case 4:
    *stencilTestEnd = stencilRef & stencilValueMask | 0x3ba00000;
    codeCursor[3] = stencilValueMask | 0x733e0000;
    stencilBranchWord = 0x41810000;
    break;
  case 5:
    *stencilTestEnd = stencilRef & stencilValueMask | 0x3ba00000;
    codeCursor[3] = stencilValueMask | 0x733e0000;
    stencilBranchWord = 0x40820000;
    break;
  case 6:
    *stencilTestEnd = stencilRef & stencilValueMask | 0x3ba00000;
    codeCursor[3] = stencilValueMask | 0x733e0000;
    stencilBranchWord = 0x40800000;
    break;
  case 7:
    *stencilTestEnd = 0x48000000;
    emitPtr = codeCursor + 3;
    branchFixupPtr = stencilTestEnd;
  default:
    goto switchD_97be45d8_default;
  }
  codeCursor[4] = 0x7c1df000;
  branchFixupPtr = codeCursor + 5;
  *branchFixupPtr = stencilBranchWord;
  emitPtr = codeCursor + 6;
switchD_97be45d8_default:
  stencilUpdateCursor = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(stencilState >> 0xf & 7,0x1a,0x19,stencilRef,stencilWriteMask,emitPtr);
  codeCursor = stencilUpdateCursor + 1;
  *stencilUpdateCursor = *(int *)(compiler + 0xe3c) - (int)stencilUpdateCursor & 0x3fffffcU | 0x48000000;
  *branchFixupPtr = *branchFixupPtr | (int)codeCursor - (int)branchFixupPtr & 0xfffcU;
LAB_97be4754:
  if ((stageFlags & 4) == 0) {
    if (!stencilEnabled) {
      return codeCursor;
    }
    finalUpdateCursor = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(stencilState >> 0x15 & 7,0x1a,0x19,stencilRef,stencilWriteMask,codeCursor);
    return finalUpdateCursor;
  }
  switch(depthFunc & 7) {
  case 0:
    if (stencilEnabled) {
      stencilState = stencilState >> 0x12;
LAB_97be47b8:
      codeCursor = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(stencilState & 7,0x1a,0x19,stencilRef,stencilWriteMask,codeCursor);
    }
    *codeCursor = *(int *)(compiler + 0xe3c) - (int)codeCursor & 0x3fffffcU | 0x48000000;
    return codeCursor + 1;
  case 1:
    *codeCursor = 0x81e30da8;
    codeCursor[1] = 0xc10f0000;
    depthBranchWord = 0x41800000;
    break;
  case 2:
    *codeCursor = 0x81e30da8;
    codeCursor[1] = 0xc10f0000;
    depthBranchWord = 0x41820000;
    break;
  case 3:
    *codeCursor = 0x81e30da8;
    codeCursor[1] = 0xc10f0000;
    depthBranchWord = 0x40810000;
    break;
  case 4:
    *codeCursor = 0x81e30da8;
    codeCursor[1] = 0xc10f0000;
    depthBranchWord = 0x41810000;
    break;
  case 5:
    *codeCursor = 0x81e30da8;
    codeCursor[1] = 0xc10f0000;
    depthBranchWord = 0x40820000;
    break;
  case 6:
    *codeCursor = 0x81e30da8;
    codeCursor[1] = 0xc10f0000;
    depthBranchWord = 0x40800000;
    break;
  case 7:
    *codeCursor = 0x81e30da8;
    depthBranchWord = 0x48000000;
    goto LAB_97be48e0;
  default:
    goto switchD_97be4784_default;
  }
  codeCursor = codeCursor + 2;
  *codeCursor = 0xfc0d4000;
LAB_97be48e0:
  branchFixupPtr = codeCursor + 1;
  *branchFixupPtr = depthBranchWord;
  codeCursor = codeCursor + 2;
switchD_97be4784_default:
  if (stencilEnabled) {
    codeCursor = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(stencilState >> 0x12 & 7,0x1a,0x19,stencilRef,stencilWriteMask,codeCursor);
  }
  *codeCursor = *(int *)(compiler + 0xe3c) - (int)codeCursor & 0x3fffffcU | 0x48000000;
  tailEmitPtr = codeCursor + 1;
  *branchFixupPtr = *branchFixupPtr | (int)tailEmitPtr - (int)branchFixupPtr & 0xfffcU;
  if (stencilEnabled) {
    tailEmitPtr = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(stencilState >> 0x15 & 7,0x1a,0x19,stencilRef,stencilWriteMask,tailEmitPtr);
  }
  if ((bufferMaskDisabled) || ((writeMasks & 0x10000) != 0)) {
    *tailEmitPtr = 0xd1af0000;
    tailEmitPtr = tailEmitPtr + 1;
  }
  return tailEmitPtr;
}

/* _PPCRasterOpMachine_AlphaTestRTCAV @ 0x97be49d0 (616 bytes) */
int _PPCRasterOpMachine_AlphaTestRTCAV(machine, codeCursor)
  int *machine;
  uint *codeCursor;
{
  uint compareWord;
  uint framebufferFormat;
  float clampBound;
  uint alphaFunc;
  float alphaRef;
  int rasterState;
  uint alphaState;
  uint branchField;
  double alphaRefScaled;
  
  branchField = 0;
  rasterState = *(int *)(*machine + 0xd80);
  alphaState = *(uint *)(rasterState + 0x40);
  alphaRef = *(float *)(rasterState + 0x44);
  alphaFunc = alphaState & 7;
  if ((alphaFunc != 7) && (alphaFunc != 0)) {
    framebufferFormat = _PPEmulatorFramebufferFormat(*machine);
    if ((framebufferFormat & 0x1c000) == 0) {
      *codeCursor = 0x3b000210;
      codeCursor[1] = 0x7e63c1ce;
      codeCursor[2] = 0xc123021c;
      codeCursor[3] = (uint)(int)alphaRef >> 0x10 | 0x3de00000;
      codeCursor[4] = (uint)(int)alphaRef & 0xffff | 0x61ef0000;
      codeCursor[5] = 0x91e30210;
      codeCursor[6] = 0xc1030210;
      compareWord = 0xfc094000;
    }
    else {
      clampBound = TAllocation__guardBlockSize;
      if ((alphaRef < TAllocation__guardBlockSize) || (clampBound = FLOAT_97c3acd8, FLOAT_97c3acd8 < alphaRef))
      {
        alphaRef = clampBound;
      }
      alphaRef = alphaRef * FLOAT_97c3acbc + FLOAT_97c3acc0;
      alphaRefScaled = (double)alphaRef;
      if (DOUBLE_97c30a78 <= alphaRefScaled) {
        compareWord = (uint)(int)(alphaRefScaled - DOUBLE_97c30a78);
      }
      else {
        compareWord = (uint)(int)alphaRef;
      }
      *codeCursor = 0x10734c0a;
      codeCursor[1] = 0x1063444a;
      codeCursor[2] = 0x10635b2e;
      codeCursor[3] = 0x10601b8a;
      codeCursor[4] = 0x3b000210;
      codeCursor[5] = 0x7c63c1ce;
      compareWord = compareWord & 0xffff | 0x2c170000;
      codeCursor[6] = 0x82e3021c;
    }
    codeCursor[7] = compareWord;
    codeCursor = codeCursor + 8;
    branchField = (uint)(*(int *)(machine[1] + 0xe3c) - (int)codeCursor) >> 2;
  }
  switch(alphaState & 7) {
  case 0:
    branchField = *(int *)(machine[1] + 0xe3c) - (int)codeCursor & 0x3fffffcU | 0x48000000;
    break;
  case 1:
    branchField = (branchField & 0x3fff) << 2 | 0x40800000;
    break;
  case 2:
    branchField = (branchField & 0x3fff) << 2 | 0x40820000;
    break;
  case 3:
    branchField = (branchField & 0x3fff) << 2 | 0x41810000;
    break;
  case 4:
    branchField = (branchField & 0x3fff) << 2 | 0x40810000;
    break;
  case 5:
    branchField = (branchField & 0x3fff) << 2 | 0x41820000;
    break;
  case 6:
    branchField = (branchField & 0x3fff) << 2 | 0x41800000;
    break;
  default:
    goto switchD_97be4bb8_caseD_7;
  }
  *codeCursor = branchField;
  codeCursor = codeCursor + 1;
switchD_97be4bb8_caseD_7:
  return codeCursor;
}

/* _PPCRasterOpMachine_BlendingRTCAV @ 0x97be4c58 (888 bytes) */
int _PPCRasterOpMachine_BlendingRTCAV(machine, codeCursor)
  int *machine;
  uint *codeCursor;
{
  undefined4 *emitPtrAlpha;
  uint alphaEquationWord;
  uint rgbEquationWord;
  uint blendField;
  undefined4 *emitPtr;
  bool equationsEqual;
  undefined4 *factorEnd;
  uint blendState;
  int vectorRegSel;
  
  vectorRegSel = 0x13;
  blendState = *(uint *)(*(int *)(*machine + 0xd80) + 0x58);
  blendField = _PPEmulatorFramebufferFormat(*machine);
  if ((blendField & 0x8000000) == 0) {
    *codeCursor = 0x1273444a;
    codeCursor[1] = 0x12734c0a;
    codeCursor = codeCursor + 2;
  }
  if ((1 < (blendState >> 0x10 & 7) - 3) || (1 < (blendState >> 0x13 & 7) - 3)) {
    if (((((blendState & 0xf) - 8 < 4) ||
         (((blendField = blendState >> 4 & 0xf, blendField == 8 || (blendField == 9)) || (blendField == 10)))) ||
        ((((blendField == 0xb || (blendField = blendState >> 8 & 0xf, blendField == 8)) || (blendField == 9)) ||
         ((blendField == 10 || (blendField == 0xb)))))) ||
       ((blendField = blendState >> 0xc & 0xf, blendField == 8 ||
        (((blendField == 9 || (blendField == 10)) || (blendField == 0xb)))))) {
      *codeCursor = 0x81e30d9c;
      codeCursor[1] = 0x81ef00d8;
      codeCursor[2] = 0x39c02d70;
      codeCursor[3] = 0x7ccf70ce;
      codeCursor = codeCursor + 4;
    }
    emitPtr = (undefined4 *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(codeCursor,0,blendState & 0xf);
    blendField = blendState >> 4 & 0xf;
    if ((blendState & 0xf) != blendField) {
      factorEnd = (undefined4 *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(emitPtr,3,blendField);
      emitPtr = factorEnd + 1;
      *factorEnd = 0x10001b6a;
    }
    codeCursor = (uint *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(emitPtr,1,blendState >> 8 & 0xf);
    blendField = blendState >> 0xc & 0xf;
    if ((blendState >> 8 & 0xf) != blendField) {
      emitPtrAlpha = (undefined4 *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(codeCursor,3,blendField);
      codeCursor = emitPtrAlpha + 1;
      *emitPtrAlpha = 0x10211b6a;
    }
  }
  blendField = blendState >> 0x10 & 7;
  equationsEqual = blendField == (blendState >> 0x13 & 7);
  if (!equationsEqual) {
    vectorRegSel = 3;
  }
  switch(blendField) {
  case 0:
    *codeCursor = 0x1093482e;
    codeCursor = codeCursor + 1;
    *codeCursor = vectorRegSel << 0x15 | 0x1002206e;
    goto LAB_97be4f04;
  case 1:
    *codeCursor = 0x1093482e;
    rgbEquationWord = vectorRegSel << 0x15 | 0x1004284a;
    break;
  case 2:
    *codeCursor = 0x1093482e;
    rgbEquationWord = vectorRegSel << 0x15 | 0x1005204a;
    break;
  case 3:
    rgbEquationWord = vectorRegSel << 0x15 | 0x1013144a;
    goto LAB_97be4f00;
  case 4:
    rgbEquationWord = vectorRegSel << 0x15 | 0x1013140a;
LAB_97be4f00:
    *codeCursor = rgbEquationWord;
    goto LAB_97be4f04;
  default:
    goto switchD_97be4e5c_default;
  }
  codeCursor[1] = 0x10a2486e;
  codeCursor = codeCursor + 2;
  *codeCursor = rgbEquationWord;
LAB_97be4f04:
  codeCursor = codeCursor + 1;
switchD_97be4e5c_default:
  if (equationsEqual) {
    return codeCursor;
  }
  switch(blendState >> 0x13 & 7) {
  case 0:
    alphaEquationWord = 0x1262206e;
    *codeCursor = 0x1093482e;
    goto LAB_97be4f88;
  case 1:
    *codeCursor = 0x1093482e;
    alphaEquationWord = 0x1264284a;
    break;
  case 2:
    *codeCursor = 0x1093482e;
    alphaEquationWord = 0x1265204a;
    break;
  case 3:
    alphaEquationWord = 0x1273144a;
    goto LAB_97be4fc4;
  case 4:
    alphaEquationWord = 0x1273140a;
LAB_97be4fc4:
    *codeCursor = alphaEquationWord;
    goto LAB_97be4fc8;
  default:
    goto switchD_97be4f38_default;
  }
  codeCursor = codeCursor + 1;
  *codeCursor = 0x10a2486e;
LAB_97be4f88:
  codeCursor = codeCursor + 1;
  *codeCursor = alphaEquationWord;
LAB_97be4fc8:
  codeCursor = codeCursor + 1;
switchD_97be4f38_default:
  *codeCursor = vectorRegSel << 0x10 | 0x12609b6a;
  return codeCursor + 1;
}

/* _PPCRasterOpMachine_LogicOpRTCAV @ 0x97be4ff8 (520 bytes) */
int _PPCRasterOpMachine_LogicOpRTCAV(machine, codeCursor)
  int *machine;
  uint *codeCursor;
{
  uint opWord2;
  uint opWord;
  uint logicOp;
  uint logicOpState;
  
  logicOpState = *(uint *)(*(int *)(*machine + 0xd80) + 0x68);
  logicOp = logicOpState & 0xf;
  if ((logicOp < 3) || (logicOp == 4)) {
    if (logicOp == 1) {
      opWord = 0x12684484;
    }
    else if (logicOp < 2) {
      if (logicOp != 0) {
        return codeCursor;
      }
      opWord = 0x12694c84;
    }
    else {
      if (logicOp == 2) {
        return codeCursor;
      }
      if (logicOp != 4) {
        return codeCursor;
      }
      opWord = 0x12621484;
    }
    *codeCursor = opWord;
    goto LAB_97be507c;
  }
  if (logicOp != 5) {
    *codeCursor = 0x10734b2e;
    codeCursor[1] = 0x10601b8a;
    codeCursor = codeCursor + 2;
  }
  logicOpState = logicOpState & 0xf;
  if (logicOpState != 3) {
    *codeCursor = 0x10824b2e;
    codeCursor[1] = 0x1080238a;
    codeCursor = codeCursor + 2;
  }
  switch(logicOpState) {
  case 3:
    opWord = 0x10c30000;
    goto LAB_97be5148;
  default:
    goto switchD_97be5104_caseD_4;
  case 5:
    opWord = 0x10c40000;
LAB_97be5148:
    opWord = opWord | 0x4d04;
    break;
  case 6:
    opWord = 0x10c32404;
    break;
  case 7:
    opWord = 0x10c32404;
    goto LAB_97be51a0;
  case 8:
    opWord = 0x10c32484;
    break;
  case 9:
    opWord = 0x10c32504;
    break;
  case 10:
    opWord = 0x10c324c4;
    break;
  case 0xb:
    opWord = 0x10c324c4;
LAB_97be51a0:
    opWord2 = 0x10c64d04;
LAB_97be51d8:
    *codeCursor = opWord;
    codeCursor = codeCursor + 1;
    *codeCursor = opWord2;
    goto LAB_97be51e0;
  case 0xc:
    opWord = 0x10c32444;
    break;
  case 0xd:
    opWord = 0x10c41c44;
    break;
  case 0xe:
    opWord = 0x10840000;
    goto LAB_97be51cc;
  case 0xf:
    opWord = 0x10630000;
LAB_97be51cc:
    opWord = opWord | 0x4d04;
    opWord2 = 0x10c32484;
    goto LAB_97be51d8;
  }
  *codeCursor = opWord;
LAB_97be51e0:
  codeCursor = codeCursor + 1;
switchD_97be5104_caseD_4:
  *codeCursor = 0x39e00020;
  codeCursor[1] = 0x7c6378ce;
  codeCursor[2] = 0x10c61c04;
  codeCursor[3] = 0x10c0330a;
  codeCursor[4] = 0x39e00070;
  codeCursor[5] = 0x7c6378ce;
  codeCursor = codeCursor + 6;
  *codeCursor = 0x126648ee;
LAB_97be507c:
  return codeCursor + 1;
}

/* _PPCRasterOpMachine_BufferMaskRTCAV @ 0x97be5234 (208 bytes) */
int _PPCRasterOpMachine_BufferMaskRTCAV(machine, codeCursor)
  int *machine;
  undefined4 *codeCursor;
{
  uint writeMasks;
  undefined4 colorMaskWord;
  
  colorMaskWord = 0x1063492c;
  writeMasks = *(uint *)(*(int *)(*machine + 0xd80) + 0x70);
  *codeCursor = 0x10836a8c;
  if ((writeMasks & 0x20000) == 0) {
    colorMaskWord = 0x1063212c;
  }
  codeCursor[1] = colorMaskWord;
  colorMaskWord = 0x1063492c;
  if ((writeMasks & 0x40000) == 0) {
    colorMaskWord = 0x1063212c;
  }
  codeCursor[2] = colorMaskWord;
  colorMaskWord = 0x1063492c;
  if ((writeMasks & 0x80000) == 0) {
    colorMaskWord = 0x1063212c;
  }
  codeCursor[3] = colorMaskWord;
  colorMaskWord = 0x1063492c;
  if ((writeMasks & 0x100000) == 0) {
    colorMaskWord = 0x1063212c;
  }
  codeCursor[4] = colorMaskWord;
  codeCursor[5] = 0x127310ea;
  return codeCursor + 6;
}

/* _PPCRasterOpMachineCalculateBlendingFactorsRTCAV @ 0x97be5304 (400 bytes) */
int _PPCRasterOpMachineCalculateBlendingFactorsRTCAV(codeCursor, vectorReg, blendFactor)
  uint *codeCursor;
  int vectorReg;
  undefined4 blendFactor;
{
  uint factorWord;
  uint factorWord2;
  
  switch(blendFactor) {
  case 0:
    factorWord = vectorReg << 0x15 | 0x10094c84;
    break;
  case 1:
    factorWord = vectorReg << 0x15 | 0x10084484;
    break;
  case 2:
    factorWord = vectorReg << 0x15 | 0x10139c84;
    break;
  case 3:
    factorWord = vectorReg << 0x15 | 0x1008984a;
    break;
  case 4:
    factorWord = vectorReg << 0x15 | 0x10039a8c;
    break;
  case 5:
    factorWord = vectorReg << 0x15 | vectorReg << 0xb | 0x10080000;
    factorWord2 = vectorReg << 0x15 | 0x10039a8c;
    goto LAB_97be545c;
  case 6:
    factorWord = vectorReg << 0x15 | 0x1003128c;
    break;
  case 7:
    factorWord = vectorReg << 0x15 | vectorReg << 0xb | 0x10080000;
    factorWord2 = vectorReg << 0x15 | 0x1003128c;
    goto LAB_97be545c;
  case 8:
    factorWord = vectorReg << 0x15 | 0x10063484;
    break;
  case 9:
    factorWord = vectorReg << 0x15 | 0x1008304a;
    break;
  case 10:
    factorWord = vectorReg << 0x15 | 0x1003328c;
    break;
  case 0xb:
    factorWord = vectorReg << 0x15 | vectorReg << 0xb | 0x10080000;
    factorWord2 = vectorReg << 0x15 | 0x1003328c;
LAB_97be545c:
    *codeCursor = factorWord2;
    codeCursor = codeCursor + 1;
    *codeCursor = factorWord | 0x4a;
    goto LAB_97be5394;
  case 0xc:
    factorWord = vectorReg << 0x15 | 0x10021484;
    break;
  case 0xd:
    factorWord = vectorReg << 0x15 | 0x1008104a;
    break;
  case 0xe:
    factorWord = vectorReg << 0x15;
    factorWord2 = factorWord | vectorReg << 0x10;
    *codeCursor = factorWord | 0x1008104a;
    codeCursor[1] = factorWord2 | 0x10009c4a;
    codeCursor[2] = factorWord | vectorReg << 0xb | 0x1003028c;
    codeCursor = codeCursor + 3;
    *codeCursor = factorWord2 | 0x1000436a;
    goto LAB_97be5394;
  default:
    return codeCursor;
  }
  *codeCursor = factorWord;
LAB_97be5394:
  return codeCursor + 1;
}

/* _PPCRasterOpMachineUpdateStencilBufferRTCAV @ 0x97be54d0 (468 bytes) */
int _PPCRasterOpMachineUpdateStencilBufferRTCAV(stencilOp, stencilPtrReg, valueReg, stencilRef, writeMask, codeCursor)
  undefined4 stencilOp;
  int stencilPtrReg;
  uint valueReg;
  uint stencilRef;
  uint writeMask;
  uint *codeCursor;
{
  uint clearBitsWord;
  uint deltaLoadWord;
  uint *emitPtr;
  
  switch(stencilOp) {
  case 0:
    *codeCursor = writeMask ^ 0xffff | valueReg << 0x15 | 0x701e0000;
    emitPtr = codeCursor + 1;
    *emitPtr = stencilPtrReg << 0x10 | 0x9bc00000;
    goto LAB_97be5588;
  case 1:
    return codeCursor;
  case 2:
    *codeCursor = writeMask ^ 0xffff | valueReg << 0x15 | 0x701e0000;
    codeCursor[1] = stencilRef & writeMask | 0x3be00000;
    emitPtr = codeCursor + 2;
    *emitPtr = 0x7fdefb78;
    goto LAB_97be5580;
  case 3:
    *codeCursor = (valueReg & 0x1f) << 0x10 | 0x2c0000ff;
    codeCursor[1] = valueReg << 0x10 | 0x3be00000;
    codeCursor[2] = 0x40800008;
    clearBitsWord = writeMask ^ 0xffff | valueReg << 0x15;
    deltaLoadWord = valueReg << 0x10 | 0x3be00001;
    break;
  case 4:
    *codeCursor = (valueReg & 0x1f) << 0x10 | 0x2c000000;
    codeCursor[1] = valueReg << 0x10 | 0x3be00000;
    codeCursor[2] = 0x40810008;
    clearBitsWord = writeMask ^ 0xffff | valueReg << 0x15;
    deltaLoadWord = valueReg << 0x10 | 0x3be0ffff;
    break;
  case 5:
    *codeCursor = writeMask ^ 0xffff | valueReg << 0x15 | 0x701e0000;
    codeCursor[1] = valueReg << 0x15 | valueReg << 0xb | 0x7c1f00f8;
    codeCursor[2] = writeMask | 0x73ff0000;
    codeCursor[3] = 0x7fdefb78;
    codeCursor[4] = stencilPtrReg << 0x10 | 0x9bc00000;
    return codeCursor + 5;
  case 6:
    clearBitsWord = writeMask ^ 0xffff | valueReg << 0x15;
    deltaLoadWord = valueReg << 0x10 | 0x3be00001;
    goto LAB_97be55e8;
  case 7:
    clearBitsWord = writeMask ^ 0xffff | valueReg << 0x15;
    deltaLoadWord = valueReg << 0x10 | 0x3be0ffff;
LAB_97be55e8:
    *codeCursor = deltaLoadWord;
    emitPtr = codeCursor + 1;
    *emitPtr = 0x73ff00ff;
    goto LAB_97be55f4;
  default:
    return codeCursor;
  }
  emitPtr = codeCursor + 3;
  *emitPtr = deltaLoadWord;
LAB_97be55f4:
  emitPtr[1] = clearBitsWord | 0x701e0000;
  emitPtr[2] = writeMask | 0x73ff0000;
  emitPtr = emitPtr + 3;
  *emitPtr = 0x7fdefb78;
LAB_97be5580:
  emitPtr = emitPtr + 1;
  *emitPtr = stencilPtrReg << 0x10 | 0x9bc00000;
LAB_97be5588:
  return emitPtr + 1;
}

