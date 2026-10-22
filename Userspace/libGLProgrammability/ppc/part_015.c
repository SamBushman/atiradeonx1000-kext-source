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
int _PPCRuntimeCompilerSwizzleRegisterAV(compiler, param_2, param_3)
  int compiler;
  int param_2;
  uint *param_3;
{
  uint vectorInstWord8;
  uint vectorInstWord7;
  uint vectorInstWord5;
  uint vectorInstWord4;
  int vectorInstWord2;
  int vectorInstWord;
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
  uint *vectorInstWord3;
  
  vectorInstWord5 = *param_3;
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
    *codeCursor = param_2 << 0x15 | (vectorInstWord6 >> (vectorInstWord8 * -4 + 0x1c & 0x3f) & 0xf) << 0x10 | param_2 << 0xb
              | 0x1000028c;
    *(uint **)(compiler + 0xe30) = codeCursor + 1;
    return;
  }
  if (iVar4 == 4) {
    vectorInstWord7 = (vectorInstWord5 & 0x3000000) >> 0x18;
    if (vectorInstWord7 == 0) {
      return;
    }
    vectorInstWord5 = param_2 << 0x15 | param_2 << 0x10 | param_2 << 0xb;
    vectorInstWord7 = vectorInstWord7 << 8;
LAB_97bda710:
    codeWritePtr = *(uint **)(compiler + 0xe30);
    vectorInstWord7 = vectorInstWord5 | vectorInstWord7 & 0x300 | 0x1000002c;
LAB_97bdaabc:
    *codeWritePtr = vectorInstWord7;
  }
  else {
    if (iVar5 == 3) {
      vectorInstWord5 = param_2 << 0xb;
      vectorInstWord7 = vectorInstWord6 >> (vectorInstWord8 * -4 + 0x10 & 0x3f);
      codeCursor = *(uint **)(compiler + 0xe30);
      *codeCursor = (vectorInstWord6 >> (vectorInstWord8 * -4 + 0x1c & 0x3f) & 0xf) << 0x10 | 0x600000 | vectorInstWord5 | 0x1000028c;
      *(uint **)(compiler + 0xe30) = codeCursor + 1;
      vectorInstWord = param_2;
      if ((vectorInstWord7 & 0xf) != 0) {
        vectorInstWord = 4;
        codeCursor[1] = param_2 << 0x10 | 0x800000U | vectorInstWord5 | (vectorInstWord7 & 3) << 8 | 0x1000002c;
        *(uint **)(compiler + 0xe30) = codeCursor + 2;
      }
      codeCursor = *(uint **)(compiler + 0xe30);
      *codeCursor = param_2 << 0x15 | 0x30000U | vectorInstWord << 0xb | 0x1000012c;
      codeWritePtr = codeCursor + 1;
      *(uint **)(compiler + 0xe30) = codeWritePtr;
      if (vectorInstWord8 == 0) {
        return;
      }
      vectorInstWord5 = param_2 << 0x15 | param_2 << 0x10 | vectorInstWord5;
      vectorInstWord7 = vectorInstWord8;
    }
    else {
      if (iVar4 != 3) {
        if (iVar5 == 2) {
          vectorInstWord5 = param_2 << 0xb;
          vectorInstWord4 = vectorInstWord6 >> (vectorInstWord8 * -4 + 0x14 & 0x3f);
          vectorInstWord7 = vectorInstWord4 & 0xf;
          uVar10 = vectorInstWord6 >> (vectorInstWord8 * -4 + 0x10 & 0x3f) & 0xf;
          codeCursor = *(uint **)(compiler + 0xe30);
          *codeCursor = (vectorInstWord6 >> (vectorInstWord8 * -4 + 0x1c & 0x3f) & 0xf) << 0x10 | 0x600000 | vectorInstWord5 |
                    0x1000028c;
          vectorInstWord3 = codeCursor + 1;
          *(uint **)(compiler + 0xe30) = vectorInstWord3;
          if (uVar10 == (vectorInstWord7 + 1 & 3)) {
            vectorInstWord = param_2;
            if (vectorInstWord7 != 0) {
              vectorInstWord = 4;
              *vectorInstWord3 = param_2 << 0x10 | 0x800000U | vectorInstWord5 | (vectorInstWord4 & 3) << 8 | 0x1000002c;
              *(uint **)(compiler + 0xe30) = codeCursor + 2;
            }
            codeCursor2 = *(uint **)(compiler + 0xe30);
            vectorInstWord7 = param_2 << 0x15 | 0x30000U | vectorInstWord << 0xb | 0x1000022c;
LAB_97bda6e8:
            *codeCursor2 = vectorInstWord7;
            puVar9 = codeCursor2 + 1;
          }
          else {
            if (uVar10 != vectorInstWord7) {
              vectorInstWord = param_2;
              if (vectorInstWord7 != 0) {
                vectorInstWord = 4;
                *vectorInstWord3 = param_2 << 0x10 | 0x800000U | vectorInstWord5 | (vectorInstWord4 & 3) << 8 | 0x1000002c;
                *(uint **)(compiler + 0xe30) = codeCursor + 2;
              }
              vectorInstWord6 = vectorInstWord6 >> (vectorInstWord8 * -4 + 0x10 & 0x3f);
              codeCursor = *(uint **)(compiler + 0xe30);
              *codeCursor = vectorInstWord << 0xb | 0x1063012c;
              *(uint **)(compiler + 0xe30) = codeCursor + 1;
              vectorInstWord = param_2;
              if ((vectorInstWord6 & 0xf) != 0) {
                vectorInstWord = 4;
                codeCursor[1] = param_2 << 0x10 | 0x800000U | vectorInstWord5 | (vectorInstWord6 & 3) << 8 | 0x1000002c;
                *(uint **)(compiler + 0xe30) = codeCursor + 2;
              }
              codeCursor2 = *(uint **)(compiler + 0xe30);
              vectorInstWord7 = param_2 << 0x15 | 0x30000U | vectorInstWord << 0xb | 0x1000012c;
              goto LAB_97bda6e8;
            }
            puVar9 = codeCursor + 3;
            codeCursor[2] = param_2 << 0x15 | 0x1003222c;
            *vectorInstWord3 = vectorInstWord7 << 0x10 | 0x800000 | vectorInstWord5 | 0x1000028c;
          }
          *(uint **)(compiler + 0xe30) = puVar9;
          if (vectorInstWord8 == 0) {
            return;
          }
          vectorInstWord5 = param_2 << 0x15 | param_2 << 0x10 | vectorInstWord5;
          vectorInstWord7 = vectorInstWord8;
LAB_97bda70c:
          vectorInstWord7 = (4 - vectorInstWord7) * 0x100;
          goto LAB_97bda710;
        }
        if (iVar4 == 2) {
          uVar2 = vectorInstWord6 >> (vectorInstWord7 * -4 + 0x1c & 0x3f) & 0xf;
          vectorInstWord = param_2;
          if (uVar2 != 2) {
            codeCursor = *(uint **)(compiler + 0xe30);
            vectorInstWord = 3;
            *codeCursor = param_2 << 0x10 | 0x600000U | param_2 << 0xb | (uVar2 * 4 + 8) * 0x40 & 0x300
                      | 0x1000002c;
            *(uint **)(compiler + 0xe30) = codeCursor + 1;
          }
          uVar10 = vectorInstWord6 >> (vectorInstWord7 * -4 + 0x14 & 0x3f);
          vectorInstWord5 = uVar10 & 0xf;
          uVar7 = vectorInstWord6 >> (vectorInstWord7 * -4 + 0x10 & 0x3f) & 0xf;
          if (uVar7 == (vectorInstWord5 + 1 & 3)) {
            vectorInstWord2 = param_2;
            if (vectorInstWord5 != 0) {
              codeCursor = *(uint **)(compiler + 0xe30);
              vectorInstWord2 = 4;
              *codeCursor = param_2 << 0x10 | 0x800000U | param_2 << 0xb | (uVar10 & 3) << 8 |
                        0x1000002c;
              *(uint **)(compiler + 0xe30) = codeCursor + 1;
            }
            codeWritePtr = *(uint **)(compiler + 0xe30);
            *codeWritePtr = param_2 << 0x15 | vectorInstWord << 0x10 | vectorInstWord2 << 0xb | 0x1000022c;
LAB_97bda854:
            *(uint **)(compiler + 0xe30) = codeWritePtr + 1;
          }
          else {
            if (uVar7 == vectorInstWord5) {
              codeCursor = *(uint **)(compiler + 0xe30);
              *codeCursor = vectorInstWord5 << 0x10 | 0x800000 | param_2 << 0xb | 0x1000028c;
              codeWritePtr = codeCursor + 1;
              *codeWritePtr = param_2 << 0x15 | vectorInstWord << 0x10 | 0x1000222c;
              goto LAB_97bda854;
            }
            vectorInstWord2 = param_2;
            if (vectorInstWord5 != 0) {
              codeCursor = *(uint **)(compiler + 0xe30);
              vectorInstWord2 = 4;
              *codeCursor = param_2 << 0x10 | 0x800000U | param_2 << 0xb | (uVar10 & 3) << 8 |
                        0x1000002c;
              *(uint **)(compiler + 0xe30) = codeCursor + 1;
            }
            vectorInstWord6 = vectorInstWord6 >> (vectorInstWord7 * -4 + 0x10 & 0x3f);
            codeCursor = *(uint **)(compiler + 0xe30);
            *codeCursor = vectorInstWord << 0x10 | vectorInstWord2 << 0xb | 0x1060012c;
            *(uint **)(compiler + 0xe30) = codeCursor + 1;
            vectorInstWord = param_2;
            if ((vectorInstWord6 & 0xf) != 0) {
              vectorInstWord = 4;
              codeCursor[1] = param_2 << 0x10 | 0x800000U | param_2 << 0xb | (vectorInstWord6 & 3) << 8 |
                          0x1000002c;
              *(uint **)(compiler + 0xe30) = codeCursor + 2;
            }
            codeCursor = *(uint **)(compiler + 0xe30);
            *codeCursor = param_2 << 0x15 | 0x30000U | vectorInstWord << 0xb | 0x1000012c;
            *(uint **)(compiler + 0xe30) = codeCursor + 1;
          }
          if (vectorInstWord7 == 0) {
            return;
          }
          vectorInstWord5 = param_2 << 0x15 | param_2 << 0x10 | param_2 << 0xb;
          goto LAB_97bda70c;
        }
        uVar6 = (vectorInstWord5 & 0x3000000) >> 0x18;
        vectorInstWord = param_2;
        if (uVar6 != 3) {
          codeCursor = *(uint **)(compiler + 0xe30);
          vectorInstWord = 3;
          *codeCursor = param_2 << 0x10 | 0x600000U | param_2 << 0xb | (uVar6 * 4 + 4) * 0x40 & 0x300 |
                    0x1000002c;
          *(uint **)(compiler + 0xe30) = codeCursor + 1;
        }
        vectorInstWord2 = param_2;
        if ((vectorInstWord5 & 0x30000) != 0) {
          codeCursor = *(uint **)(compiler + 0xe30);
          vectorInstWord2 = 4;
          *codeCursor = param_2 << 0x10 | 0x800000U | param_2 << 0xb | ((vectorInstWord5 & 0x30000) >> 0x10) << 8
                    | 0x1000002c;
          *(uint **)(compiler + 0xe30) = codeCursor + 1;
        }
        codeCursor = *(uint **)(compiler + 0xe30);
        *codeCursor = vectorInstWord << 0x10 | vectorInstWord2 << 0xb | 0x1060012c;
        *(uint **)(compiler + 0xe30) = codeCursor + 1;
        vectorInstWord = param_2;
        if ((vectorInstWord5 & 0x300) != 0) {
          vectorInstWord = 4;
          codeCursor[1] = param_2 << 0x10 | 0x800000U | param_2 << 0xb | vectorInstWord5 & 0x300 | 0x1000002c;
          *(uint **)(compiler + 0xe30) = codeCursor + 2;
        }
        codeCursor = *(uint **)(compiler + 0xe30);
        *codeCursor = vectorInstWord << 0xb | 0x1063012c;
        *(uint **)(compiler + 0xe30) = codeCursor + 1;
        vectorInstWord = param_2;
        if ((vectorInstWord5 & 3) != 0) {
          vectorInstWord = 4;
          codeCursor[1] = param_2 << 0x10 | 0x800000U | param_2 << 0xb | (vectorInstWord5 & 3) << 8 | 0x1000002c;
          *(uint **)(compiler + 0xe30) = codeCursor + 2;
        }
        codeWritePtr = *(uint **)(compiler + 0xe30);
        vectorInstWord7 = param_2 << 0x15 | 0x30000U | vectorInstWord << 0xb | 0x1000012c;
        goto LAB_97bdaabc;
      }
      uVar2 = vectorInstWord6 >> (vectorInstWord7 * -4 + 0x1c & 0x3f) & 0xf;
      vectorInstWord = param_2;
      if (uVar2 != 1) {
        codeCursor = *(uint **)(compiler + 0xe30);
        vectorInstWord = 3;
        *codeCursor = param_2 << 0x10 | 0x600000U | param_2 << 0xb | (uVar2 * 4 + 0xc) * 0x40 & 0x300 |
                  0x1000002c;
        *(uint **)(compiler + 0xe30) = codeCursor + 1;
      }
      vectorInstWord6 = vectorInstWord6 >> (vectorInstWord7 * -4 + 0x10 & 0x3f);
      vectorInstWord2 = param_2;
      if ((vectorInstWord6 & 0xf) != 0) {
        codeCursor = *(uint **)(compiler + 0xe30);
        vectorInstWord2 = 4;
        *codeCursor = param_2 << 0x10 | 0x800000U | param_2 << 0xb | (vectorInstWord6 & 3) << 8 | 0x1000002c;
        *(uint **)(compiler + 0xe30) = codeCursor + 1;
      }
      codeCursor = *(uint **)(compiler + 0xe30);
      *codeCursor = param_2 << 0x15 | vectorInstWord << 0x10 | vectorInstWord2 << 0xb | 0x1000012c;
      codeWritePtr = codeCursor + 1;
      *(uint **)(compiler + 0xe30) = codeWritePtr;
      if (vectorInstWord7 == 0) {
        return;
      }
      vectorInstWord5 = param_2 << 0x15 | param_2 << 0x10 | param_2 << 0xb;
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
int _PPCTextureSamplerSampleTexel2DRTCNO(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  short sVar1;
  short sVar2;
  uint ppcInstWord2;
  int *piVar4;
  undefined *puVar5;
  int chunkIndex;
  int iVar7;
  uint *ppcInstWord;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar4 = *(int **)(param_2 * 4 + *param_1);
  if (piVar4 != (int *)0x0) {
    param_1[1] = (int)piVar4;
    sVar1 = *(short *)(*piVar4 + 0x10);
    sVar2 = *(short *)(*piVar4 + 0x12);
    if ((sVar1 == -0x7ed3) || (sVar2 == -0x7ed3)) {
      iVar7 = 0x812d;
    }
    else if ((sVar1 == 0x2900) || (iVar7 = 0, sVar2 == 0x2900)) {
      iVar7 = 0x2900;
    }
    if (((param_1[5] != param_2) || (param_1[6] != 3)) || (param_1[7] != iVar7)) {
      *param_3 = param_2 * 4 & 0xfffc | 0x82220000;
      ppcInstWord = param_3 + 1;
      if (sVar1 == 0x2901) {
        *ppcInstWord = 0x82910160;
        ppcInstWord = param_3 + 2;
      }
      if (sVar2 == 0x2901) {
        *ppcInstWord = 0x82b10164;
        ppcInstWord = ppcInstWord + 1;
      }
      if (iVar7 == 0x812d) {
        *ppcInstWord = 0x82510190;
        ppcInstWord[1] = 0xc1d10170;
        ppcInstWord[2] = 0xc1f10174;
        ppcInstWord2 = 0x823101c4;
      }
      else if (iVar7 == 0x2900) {
        *ppcInstWord = 0x82510190;
        ppcInstWord[1] = 0xc1d10170;
        ppcInstWord[2] = 0xc1f10174;
        ppcInstWord2 = 0x823101c8;
      }
      else {
        *ppcInstWord = 0x82510140;
        ppcInstWord[1] = 0xc1d10120;
        ppcInstWord[2] = 0xc1f10124;
        ppcInstWord2 = 0x823101c0;
      }
      ppcInstWord[3] = ppcInstWord2;
      param_3 = ppcInstWord + 4;
      param_1[7] = iVar7;
      param_1[5] = param_2;
      param_1[6] = 3;
    }
    if (sVar1 == 0x2901) {
      if (sVar2 == 0x2901) {
        puVar5 = &_glpOpTexPrepareCoords2RRRTC;
      }
      else {
        puVar5 = &_glpOpTexPrepareCoords2RCRTC;
      }
    }
    else if (sVar2 == 0x2901) {
      puVar5 = &_glpOpTexPrepareCoords2CRRTC;
    }
    else {
      puVar5 = &_glpOpTexPrepareCoords2CCRTC;
    }
    iVar7 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(puVar5,param_3);
    chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSampleRTC,param_3 + iVar7);
    param_3 = param_3 + iVar7 + chunkIndex;
  }
  return param_3;
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
int _PPCTextureSamplerSampleTexelRECTRTCNO(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  short sVar1;
  short sVar2;
  uint ppcInstWord2;
  int *piVar4;
  int chunkIndex;
  int iVar6;
  uint *ppcInstWord;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar4 = *(int **)(param_2 * 4 + *param_1);
  if (piVar4 != (int *)0x0) {
    param_1[1] = (int)piVar4;
    sVar1 = *(short *)(*piVar4 + 0x10);
    sVar2 = *(short *)(*piVar4 + 0x12);
    if ((sVar1 == -0x7ed3) || (sVar2 == -0x7ed3)) {
      iVar6 = 0x812d;
    }
    else if ((sVar1 == 0x2900) || (iVar6 = 0, sVar2 == 0x2900)) {
      iVar6 = 0x2900;
    }
    if ((param_1[5] != param_2) || (param_1[6] != 2)) {
      *param_3 = param_2 * 4 & 0xfffc | 0x82220000;
      ppcInstWord = param_3 + 1;
      if (sVar1 == 0x2901) {
        *ppcInstWord = 0x82910160;
        ppcInstWord = param_3 + 2;
      }
      if (sVar2 == 0x2901) {
        *ppcInstWord = 0x82b10164;
        ppcInstWord = ppcInstWord + 1;
      }
      if (iVar6 == 0x812d) {
        *ppcInstWord = 0x82510190;
        ppcInstWord[1] = 0xc1d10170;
        ppcInstWord[2] = 0xc1f10174;
        ppcInstWord2 = 0x823101c4;
      }
      else if (iVar6 == 0x2900) {
        *ppcInstWord = 0x82510190;
        ppcInstWord[1] = 0xc1d10170;
        ppcInstWord[2] = 0xc1f10174;
        ppcInstWord2 = 0x823101c8;
      }
      else {
        *ppcInstWord = 0x82510140;
        ppcInstWord[1] = 0xc1d10120;
        ppcInstWord[2] = 0xc1f10124;
        ppcInstWord2 = 0x823101c0;
      }
      ppcInstWord[3] = ppcInstWord2;
      param_3 = ppcInstWord + 4;
      param_1[7] = iVar6;
      param_1[5] = param_2;
      param_1[6] = 2;
    }
    iVar6 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexPrepareCoords4CCRTC,param_3);
    chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSampleRTC,param_3 + iVar6);
    param_3 = param_3 + iVar6 + chunkIndex;
  }
  return param_3;
}

/* _PPCTextureSamplerWrapCoordinates1DRTCAV @ 0x97be2084 (144 bytes) */
int _PPCTextureSamplerWrapCoordinates1DRTCAV(param_1, param_2)
  int param_1;
  int param_2;
{
  short sVar1;
  short sVar2;
  undefined *puVar3;
  int chunkIndex;
  
  sVar1 = *(short *)(**(int **)(param_1 + 4) + 0x16);
  sVar2 = *(short *)(**(int **)(param_1 + 4) + 0x10);
  if (((sVar1 == 0x2600) || (sVar1 == 0x2700)) && (sVar2 == 0x2900)) {
    sVar2 = -0x7ed1;
  }
  if (sVar2 == 0x2901) {
    puVar3 = &_glpOpTexWrapCoordsRRRAVRTC;
  }
  else {
    puVar3 = &_glpOpTexWrapCoordsCCCAVRTC;
  }
  chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(puVar3,param_2);
  return param_2 + chunkIndex * 4;
}

/* _PPCTextureSamplerWrapCoordinates2DRTCAV @ 0x97be2114 (212 bytes) */
int _PPCTextureSamplerWrapCoordinates2DRTCAV(param_1, param_2)
  int param_1;
  int param_2;
{
  int chunkIndex;
  short sVar1;
  undefined *puVar2;
  int iVar3;
  short sVar4;
  
  iVar3 = **(int **)(param_1 + 4);
  sVar1 = *(short *)(iVar3 + 0x10);
  sVar4 = *(short *)(iVar3 + 0x12);
  if ((*(short *)(iVar3 + 0x16) == 0x2600) || (*(short *)(iVar3 + 0x16) == 0x2700)) {
    if (sVar1 == 0x2900) {
      sVar1 = -0x7ed1;
    }
    if (sVar4 == 0x2900) {
      sVar4 = -0x7ed1;
    }
  }
  if (sVar1 == 0x2901) {
    if (sVar4 == 0x2901) {
      puVar2 = &_glpOpTexWrapCoordsRRRAVRTC;
    }
    else {
      puVar2 = &_glpOpTexWrapCoordsRCCAVRTC;
    }
  }
  else if (sVar4 == 0x2901) {
    puVar2 = &_glpOpTexWrapCoordsCRRAVRTC;
  }
  else {
    puVar2 = &_glpOpTexWrapCoordsCCCAVRTC;
  }
  chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(puVar2,param_2);
  return param_2 + chunkIndex * 4;
}

/* _PPCTextureSamplerWrapCoordinates3DRTCAV @ 0x97be21e8 (328 bytes) */
int _PPCTextureSamplerWrapCoordinates3DRTCAV(param_1, param_2)
  int param_1;
  int param_2;
{
  int chunkIndex;
  short sVar1;
  undefined *puVar2;
  int iVar3;
  short sVar4;
  short sVar5;
  
  iVar3 = **(int **)(param_1 + 4);
  sVar1 = *(short *)(iVar3 + 0x10);
  sVar5 = *(short *)(iVar3 + 0x12);
  sVar4 = *(short *)(iVar3 + 0x14);
  if ((*(short *)(iVar3 + 0x16) == 0x2600) || (*(short *)(iVar3 + 0x16) == 0x2700)) {
    if (sVar1 == 0x2900) {
      sVar1 = -0x7ed1;
    }
    if (sVar5 == 0x2900) {
      sVar5 = -0x7ed1;
    }
    if (sVar4 == 0x2900) {
      sVar4 = -0x7ed1;
    }
  }
  if (sVar1 == 0x2901) {
    if (sVar5 == 0x2901) {
      if (sVar4 == 0x2901) {
        puVar2 = &_glpOpTexWrapCoordsRRRAVRTC;
      }
      else {
        puVar2 = &_glpOpTexWrapCoordsRRCAVRTC;
      }
    }
    else if (sVar4 == 0x2901) {
      puVar2 = &_glpOpTexWrapCoordsRCRAVRTC;
    }
    else {
      puVar2 = &_glpOpTexWrapCoordsRCCAVRTC;
    }
  }
  else if (sVar5 == 0x2901) {
    if (sVar4 == 0x2901) {
      puVar2 = &_glpOpTexWrapCoordsCRRAVRTC;
    }
    else {
      puVar2 = &_glpOpTexWrapCoordsCRCAVRTC;
    }
  }
  else if (sVar4 == 0x2901) {
    puVar2 = &_glpOpTexWrapCoordsCCRAVRTC;
  }
  else {
    puVar2 = &_glpOpTexWrapCoordsCCCAVRTC;
  }
  chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(puVar2,param_2);
  return param_2 + chunkIndex * 4;
}

/* _PPCTextureSamplerSampleTexel1DRTCAV @ 0x97be2330 (780 bytes) */
int _PPCTextureSamplerSampleTexel1DRTCAV(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  uint *param_3;
{
  undefined4 *ppcTextureSamplerSampleTexel1DFromLevelRTCAVResult;
  uint *puVar1;
  int chunkIndex;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  
  piVar5 = *(int **)(param_2 * 4 + *param_1);
  if ((uint)(*(ushort *)(*piVar5 + 0x16) - 0x2700) < 4) {
    param_1[10] = 1;
    if (param_1[9] != 0) {
      *param_3 = 0x39e00200;
      param_3[1] = 0x7c4379ce;
      param_3 = param_3 + 2;
    }
    uVar4 = param_2 * 4 & 0xfffcU | 0x82220000;
    *param_3 = uVar4;
    param_3[1] = 0x39e00120;
    param_3[2] = 0x7df178ce;
    param_3[3] = 0x39e00040;
    param_3[4] = 0x7c2c78ce;
    param_3[5] = 0x39ef00c0;
    param_3[6] = 0x7c4c78ce;
    chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexCalculateLambda1DAVRTC,param_3 + 7);
    puVar1 = param_3 + 7 + chunkIndex;
    *puVar1 = 0x39e00040;
    puVar1[1] = 0x7c9178ce;
    puVar1[2] = 0x1063200a;
    puVar6 = puVar1 + 3;
    if (param_1[9] != 0) {
      *puVar6 = 0x39e00200;
      puVar1[4] = 0x7c4378ce;
      puVar1[5] = 0x1063100a;
      puVar6 = puVar1 + 6;
    }
    *puVar6 = 0x39e00030;
    puVar6[1] = 0x7c3178ce;
    puVar6[2] = 0x39e00020;
    puVar6[3] = 0x7c5178ce;
    puVar6[4] = 0x1063144a;
    puVar6[5] = 0x10630c0a;
    puVar6[6] = 0x10601a8c;
    puVar6[7] = 0x10801b8a;
    puVar6[8] = 0x39e00200;
    puVar6[9] = 0x7c8379ce;
    puVar6[10] = 0x7f03782e;
    if ((uint)(*(ushort *)(*piVar5 + 0x16) - 0x2700) < 2) {
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(param_1,param_2,puVar6 + 0xb);
    }
    else {
      puVar6[0xb] = 0x10801aca;
      puVar6[0xc] = 0x1083204a;
      puVar6[0xd] = 0x39e00210;
      puVar6[0xe] = 0x7c8379ce;
      puVar6[0xf] = 0x39e00230;
      puVar6[0x10] = 0x7c0379ce;
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(param_1,param_2,puVar6 + 0x11);
      *puVar3 = 0x39e00220;
      puVar3[1] = 0x7c4379ce;
      puVar3[2] = 0x3b180001;
      puVar3[3] = 0x39e00230;
      puVar3[4] = 0x7c0378ce;
      puVar3[5] = uVar4;
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(param_1,param_2,puVar3 + 6);
      *puVar3 = 0x39e00220;
      puVar3[1] = 0x7c2378ce;
      puVar3[2] = 0x39e00210;
      puVar3[3] = 0x7c0378ce;
      puVar3[4] = 0x1000028c;
      puVar3[5] = 0x1068004a;
      puVar3[6] = 0x1063386e;
      puVar3[7] = 0x104018ae;
      puVar3 = puVar3 + 8;
    }
    return puVar3;
  }
  param_1[10] = 0;
  ppcTextureSamplerSampleTexel1DFromLevelRTCAVResult = (undefined4 *)((int (*)())_PPCTextureSamplerSampleTexel1DFromLevelRTCAV)(param_1,param_2,param_3);
  return ppcTextureSamplerSampleTexel1DFromLevelRTCAVResult;
}

/* _PPCTextureSamplerSampleTexel2DRTCAV @ 0x97be263c (780 bytes) */
int _PPCTextureSamplerSampleTexel2DRTCAV(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  uint *param_3;
{
  undefined4 *ppcTextureSamplerSampleTexel2DFromLevelRTCAVResult;
  uint *puVar1;
  int chunkIndex;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  
  piVar5 = *(int **)(param_2 * 4 + *param_1);
  if ((uint)(*(ushort *)(*piVar5 + 0x16) - 0x2700) < 4) {
    param_1[10] = 1;
    if (param_1[9] != 0) {
      *param_3 = 0x39e00200;
      param_3[1] = 0x7c4379ce;
      param_3 = param_3 + 2;
    }
    uVar4 = param_2 * 4 & 0xfffcU | 0x82220000;
    *param_3 = uVar4;
    param_3[1] = 0x39e00120;
    param_3[2] = 0x7df178ce;
    param_3[3] = 0x39e00040;
    param_3[4] = 0x7c2c78ce;
    param_3[5] = 0x39ef00c0;
    param_3[6] = 0x7c4c78ce;
    chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexCalculateLambda2DAVRTC,param_3 + 7);
    puVar1 = param_3 + 7 + chunkIndex;
    *puVar1 = 0x39e00040;
    puVar1[1] = 0x7c9178ce;
    puVar1[2] = 0x1063200a;
    puVar6 = puVar1 + 3;
    if (param_1[9] != 0) {
      *puVar6 = 0x39e00200;
      puVar1[4] = 0x7c4378ce;
      puVar1[5] = 0x1063100a;
      puVar6 = puVar1 + 6;
    }
    *puVar6 = 0x39e00030;
    puVar6[1] = 0x7c3178ce;
    puVar6[2] = 0x39e00020;
    puVar6[3] = 0x7c5178ce;
    puVar6[4] = 0x1063144a;
    puVar6[5] = 0x10630c0a;
    puVar6[6] = 0x10601a8c;
    puVar6[7] = 0x10801b8a;
    puVar6[8] = 0x39e00200;
    puVar6[9] = 0x7c8379ce;
    puVar6[10] = 0x7f03782e;
    if ((uint)(*(ushort *)(*piVar5 + 0x16) - 0x2700) < 2) {
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(param_1,param_2,puVar6 + 0xb);
    }
    else {
      puVar6[0xb] = 0x10801aca;
      puVar6[0xc] = 0x1083204a;
      puVar6[0xd] = 0x39e00210;
      puVar6[0xe] = 0x7c8379ce;
      puVar6[0xf] = 0x39e00230;
      puVar6[0x10] = 0x7c0379ce;
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(param_1,param_2,puVar6 + 0x11);
      *puVar3 = 0x39e00220;
      puVar3[1] = 0x7c4379ce;
      puVar3[2] = 0x3b180001;
      puVar3[3] = 0x39e00230;
      puVar3[4] = 0x7c0378ce;
      puVar3[5] = uVar4;
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(param_1,param_2,puVar3 + 6);
      *puVar3 = 0x39e00220;
      puVar3[1] = 0x7c2378ce;
      puVar3[2] = 0x39e00210;
      puVar3[3] = 0x7c0378ce;
      puVar3[4] = 0x1000028c;
      puVar3[5] = 0x1068004a;
      puVar3[6] = 0x1063386e;
      puVar3[7] = 0x104018ae;
      puVar3 = puVar3 + 8;
    }
    return puVar3;
  }
  param_1[10] = 0;
  ppcTextureSamplerSampleTexel2DFromLevelRTCAVResult = (undefined4 *)((int (*)())_PPCTextureSamplerSampleTexel2DFromLevelRTCAV)(param_1,param_2,param_3);
  return ppcTextureSamplerSampleTexel2DFromLevelRTCAVResult;
}

/* _PPCTextureSamplerSampleTexel3DRTCAV @ 0x97be2948 (780 bytes) */
int _PPCTextureSamplerSampleTexel3DRTCAV(param_1, param_2, param_3)
  int *param_1;
  int param_2;
  uint *param_3;
{
  undefined4 *ppcTextureSamplerSampleTexel3DFromLevelRTCAVResult;
  uint *puVar1;
  int chunkIndex;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  
  piVar5 = *(int **)(param_2 * 4 + *param_1);
  if ((uint)(*(ushort *)(*piVar5 + 0x16) - 0x2700) < 4) {
    param_1[10] = 1;
    if (param_1[9] != 0) {
      *param_3 = 0x39e00200;
      param_3[1] = 0x7c4379ce;
      param_3 = param_3 + 2;
    }
    uVar4 = param_2 * 4 & 0xfffcU | 0x82220000;
    *param_3 = uVar4;
    param_3[1] = 0x39e00120;
    param_3[2] = 0x7df178ce;
    param_3[3] = 0x39e00040;
    param_3[4] = 0x7c2c78ce;
    param_3[5] = 0x39ef00c0;
    param_3[6] = 0x7c4c78ce;
    chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexCalculateLambda3DAVRTC,param_3 + 7);
    puVar1 = param_3 + 7 + chunkIndex;
    *puVar1 = 0x39e00040;
    puVar1[1] = 0x7c9178ce;
    puVar1[2] = 0x1063200a;
    puVar6 = puVar1 + 3;
    if (param_1[9] != 0) {
      *puVar6 = 0x39e00200;
      puVar1[4] = 0x7c4378ce;
      puVar1[5] = 0x1063100a;
      puVar6 = puVar1 + 6;
    }
    *puVar6 = 0x39e00030;
    puVar6[1] = 0x7c3178ce;
    puVar6[2] = 0x39e00020;
    puVar6[3] = 0x7c5178ce;
    puVar6[4] = 0x1063144a;
    puVar6[5] = 0x10630c0a;
    puVar6[6] = 0x10601a8c;
    puVar6[7] = 0x10801b8a;
    puVar6[8] = 0x39e00200;
    puVar6[9] = 0x7c8379ce;
    puVar6[10] = 0x7f03782e;
    if ((uint)(*(ushort *)(*piVar5 + 0x16) - 0x2700) < 2) {
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(param_1,param_2,puVar6 + 0xb);
    }
    else {
      puVar6[0xb] = 0x10801aca;
      puVar6[0xc] = 0x1083204a;
      puVar6[0xd] = 0x39e00210;
      puVar6[0xe] = 0x7c8379ce;
      puVar6[0xf] = 0x39e00230;
      puVar6[0x10] = 0x7c0379ce;
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(param_1,param_2,puVar6 + 0x11);
      *puVar3 = 0x39e00220;
      puVar3[1] = 0x7c4379ce;
      puVar3[2] = 0x3b180001;
      puVar3[3] = 0x39e00230;
      puVar3[4] = 0x7c0378ce;
      puVar3[5] = uVar4;
      puVar3 = (undefined4 *)
               ((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(param_1,param_2,puVar3 + 6);
      *puVar3 = 0x39e00220;
      puVar3[1] = 0x7c2378ce;
      puVar3[2] = 0x39e00210;
      puVar3[3] = 0x7c0378ce;
      puVar3[4] = 0x1000028c;
      puVar3[5] = 0x1068004a;
      puVar3[6] = 0x1063386e;
      puVar3[7] = 0x104018ae;
      puVar3 = puVar3 + 8;
    }
    return puVar3;
  }
  param_1[10] = 0;
  ppcTextureSamplerSampleTexel3DFromLevelRTCAVResult = (undefined4 *)((int (*)())_PPCTextureSamplerSampleTexel3DFromLevelRTCAV)(param_1,param_2,param_3);
  return ppcTextureSamplerSampleTexel3DFromLevelRTCAVResult;
}

/* _PPCTextureSamplerSampleTexel1DFromLevelRTCAV @ 0x97be2c58 (960 bytes) */
int _PPCTextureSamplerSampleTexel1DFromLevelRTCAV(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  int ppcTextureSamplerWrapCoordinates1DRTCAVResult;
  int chunkIndex;
  bool bVar1;
  short sVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  uint ppcInstWord2;
  int iVar7;
  int *piVar8;
  uint *ppcInstWord;
  undefined4 *vectorInstWord;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar8 = *(int **)(param_2 * 4 + *param_1);
  if (piVar8 == (int *)0x0) {
    return param_3;
  }
  param_1[1] = (int)piVar8;
  iVar5 = *piVar8;
  iVar7 = 0x812d;
  sVar2 = *(short *)(iVar5 + 0x10);
  if ((sVar2 != -0x7ed3) &&
     (((sVar2 != 0x2900 || (*(short *)(iVar5 + 0x16) == 0x2600)) ||
      (iVar7 = 0x2900, *(short *)(iVar5 + 0x16) == 0x2700)))) {
    iVar7 = 0;
  }
  if (((param_1[5] == param_2) && (param_1[6] == 4)) && (param_1[7] == iVar7)) {
    iVar4 = param_1[10];
    if (iVar4 != 0) goto LAB_97be2d14;
  }
  else {
    iVar4 = param_1[10];
LAB_97be2d14:
    if (iVar4 == 0) {
      ppcInstWord2 = 0x3a310120;
      *param_3 = param_2 * 4 & 0xfffc | 0x82220000;
    }
    else {
      *param_3 = 0x1ef800d0;
      ppcInstWord2 = 0x7e31ba14;
      param_3 = param_3 + 1;
      *param_3 = 0x3a310120;
    }
    param_3[1] = ppcInstWord2;
    ppcInstWord = param_3 + 2;
    if (sVar2 == 0x2901) {
      *ppcInstWord = 0x39e00040;
      param_3[3] = 0x7e3178ce;
      ppcInstWord = param_3 + 4;
    }
    if (iVar7 == 0x812d) {
      *ppcInstWord = 0x82510070;
      ppcInstWord[1] = 0x39e00050;
      ppcInstWord[2] = 0x7df178ce;
      ppcInstWord[3] = 0x39e00080;
      ppcInstWord[4] = 0x7e1178ce;
      ppcInstWord2 = 0x823100a4;
    }
    else if (iVar7 == 0x2900) {
      *ppcInstWord = 0x82510070;
      ppcInstWord[1] = 0x39e00050;
      ppcInstWord[2] = 0x7df178ce;
      ppcInstWord[3] = 0x39e00080;
      ppcInstWord[4] = 0x7e1178ce;
      ppcInstWord2 = 0x823100a8;
    }
    else {
      *ppcInstWord = 0x82510020;
      ppcInstWord[1] = 0x39e00000;
      ppcInstWord[2] = 0x7df178ce;
      ppcInstWord[3] = 0x39e00030;
      ppcInstWord[4] = 0x7e1178ce;
      ppcInstWord2 = 0x823100a0;
    }
    ppcInstWord[5] = ppcInstWord2;
    param_1[5] = param_2;
    param_3 = ppcInstWord + 6;
    param_1[6] = 4;
    param_1[7] = iVar7;
    iVar5 = *piVar8;
  }
  uVar3 = *(ushort *)(iVar5 + 0x16);
  if (uVar3 == 0x2700) {
LAB_97be2ebc:
    if (param_1[8] != 0) {
      chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,param_3);
      param_3 = param_3 + chunkIndex;
    }
    chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedAVRTC,param_3);
    ppcTextureSamplerWrapCoordinates1DRTCAVResult = ((int (*)())_PPCTextureSamplerWrapCoordinates1DRTCAV)(param_1,param_3 + chunkIndex);
    iVar7 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample1DAVRTC,ppcTextureSamplerWrapCoordinates1DRTCAVResult);
    vectorInstWord = (undefined4 *)(ppcTextureSamplerWrapCoordinates1DRTCAVResult + iVar7 * 4);
    *vectorInstWord = 0x10431c84;
  }
  else {
    if (uVar3 < 0x2701) {
      if (uVar3 == 0x2600) goto LAB_97be2ebc;
      bVar1 = uVar3 == 0x2601;
LAB_97be2eb4:
      if (!bVar1) {
        return param_3;
      }
    }
    else {
      if (uVar3 == 0x2702) goto LAB_97be2ebc;
      if (0x2701 < uVar3) {
        bVar1 = uVar3 == 0x2703;
        goto LAB_97be2eb4;
      }
    }
    if (param_1[8] != 0) {
      chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,param_3);
      param_3 = param_3 + chunkIndex;
    }
    chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedWithLERPValuesAVRTC,param_3);
    param_3[chunkIndex] = 0x10c00484;
    ppcTextureSamplerWrapCoordinates1DRTCAVResult = ((int (*)())_PPCTextureSamplerWrapCoordinates1DRTCAV)(param_1,param_3 + chunkIndex + 1);
    iVar7 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample1DAVRTC,ppcTextureSamplerWrapCoordinates1DRTCAVResult);
    vectorInstWord = (undefined4 *)(ppcTextureSamplerWrapCoordinates1DRTCAVResult + iVar7 * 4);
    *vectorInstWord = 0x1020228c;
    vectorInstWord[1] = 0x104138ee;
    vectorInstWord[2] = 0x100a4b2c;
    vectorInstWord[3] = 0x10060780;
    ppcTextureSamplerWrapCoordinates1DRTCAVResult = ((int (*)())_PPCTextureSamplerWrapCoordinates1DRTCAV)(param_1,vectorInstWord + 4);
    iVar7 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample1DAVRTC,ppcTextureSamplerWrapCoordinates1DRTCAVResult);
    vectorInstWord = (undefined4 *)(ppcTextureSamplerWrapCoordinates1DRTCAVResult + iVar7 * 4);
    *vectorInstWord = 0x10202a8c;
    vectorInstWord = vectorInstWord + 1;
    *vectorInstWord = 0x104110ee;
  }
  return vectorInstWord + 1;
}

/* _PPCTextureSamplerSampleTexel2DFromLevelRTCAV @ 0x97be3018 (1172 bytes) */
int _PPCTextureSamplerSampleTexel2DFromLevelRTCAV(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  int ppcTextureSamplerWrapCoordinates2DRTCAVResult;
  int chunkIndex;
  bool bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  uint ppcInstWord2;
  int iVar8;
  int *piVar9;
  uint *ppcInstWord;
  undefined4 *vectorInstWord;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar9 = *(int **)(param_2 * 4 + *param_1);
  if (piVar9 == (int *)0x0) {
    return param_3;
  }
  param_1[1] = (int)piVar9;
  iVar6 = *piVar9;
  sVar2 = *(short *)(iVar6 + 0x10);
  sVar3 = *(short *)(iVar6 + 0x12);
  if ((sVar2 == -0x7ed3) || (sVar3 == -0x7ed3)) {
    iVar8 = 0x812d;
  }
  else if ((((sVar2 != 0x2900) && (sVar3 != 0x2900)) || (*(short *)(iVar6 + 0x16) == 0x2600)) ||
          (iVar8 = 0x2900, *(short *)(iVar6 + 0x16) == 0x2700)) {
    iVar8 = 0;
  }
  if (((param_1[5] == param_2) && (param_1[6] == 3)) && (param_1[7] == iVar8)) {
    iVar5 = param_1[10];
    if (iVar5 != 0) goto LAB_97be30f0;
  }
  else {
    iVar5 = param_1[10];
LAB_97be30f0:
    if (iVar5 == 0) {
      ppcInstWord2 = 0x3a310120;
      *param_3 = param_2 * 4 & 0xfffc | 0x82220000;
    }
    else {
      *param_3 = 0x1ef800d0;
      ppcInstWord2 = 0x7e31ba14;
      param_3 = param_3 + 1;
      *param_3 = 0x3a310120;
    }
    param_3[1] = ppcInstWord2;
    ppcInstWord = param_3 + 2;
    if ((sVar2 == 0x2901) || (sVar3 == 0x2901)) {
      *ppcInstWord = 0x39e00040;
      param_3[3] = 0x7e3178ce;
      ppcInstWord = param_3 + 4;
    }
    if (iVar8 == 0x812d) {
      *ppcInstWord = 0x82510070;
      ppcInstWord[1] = 0x39e00050;
      ppcInstWord[2] = 0x7df178ce;
      ppcInstWord[3] = 0x39e00080;
      ppcInstWord[4] = 0x7e1178ce;
      ppcInstWord2 = 0x823100a4;
    }
    else if (iVar8 == 0x2900) {
      *ppcInstWord = 0x82510070;
      ppcInstWord[1] = 0x39e00050;
      ppcInstWord[2] = 0x7df178ce;
      ppcInstWord[3] = 0x39e00080;
      ppcInstWord[4] = 0x7e1178ce;
      ppcInstWord2 = 0x823100a8;
    }
    else {
      *ppcInstWord = 0x82510020;
      ppcInstWord[1] = 0x39e00000;
      ppcInstWord[2] = 0x7df178ce;
      ppcInstWord[3] = 0x39e00030;
      ppcInstWord[4] = 0x7e1178ce;
      ppcInstWord2 = 0x823100a0;
    }
    ppcInstWord[5] = ppcInstWord2;
    param_1[5] = param_2;
    param_3 = ppcInstWord + 6;
    param_1[6] = 3;
    param_1[7] = iVar8;
    iVar6 = *piVar9;
  }
  uVar4 = *(ushort *)(iVar6 + 0x16);
  if (uVar4 == 0x2700) {
LAB_97be32a0:
    if (param_1[8] != 0) {
      chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,param_3);
      param_3 = param_3 + chunkIndex;
    }
    chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedAVRTC,param_3);
    ppcTextureSamplerWrapCoordinates2DRTCAVResult = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(param_1,param_3 + chunkIndex);
    iVar8 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,ppcTextureSamplerWrapCoordinates2DRTCAVResult);
    vectorInstWord = (undefined4 *)(ppcTextureSamplerWrapCoordinates2DRTCAVResult + iVar8 * 4);
    *vectorInstWord = 0x10431c84;
  }
  else {
    if (uVar4 < 0x2701) {
      if (uVar4 == 0x2600) goto LAB_97be32a0;
      bVar1 = uVar4 == 0x2601;
LAB_97be3298:
      if (!bVar1) {
        return param_3;
      }
    }
    else {
      if (uVar4 == 0x2702) goto LAB_97be32a0;
      if (0x2701 < uVar4) {
        bVar1 = uVar4 == 0x2703;
        goto LAB_97be3298;
      }
    }
    if (param_1[8] != 0) {
      chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,param_3);
      param_3 = param_3 + chunkIndex;
    }
    chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedWithLERPValuesAVRTC,param_3);
    param_3[chunkIndex] = 0x10c00484;
    ppcTextureSamplerWrapCoordinates2DRTCAVResult = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(param_1,param_3 + chunkIndex + 1);
    iVar8 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,ppcTextureSamplerWrapCoordinates2DRTCAVResult);
    vectorInstWord = (undefined4 *)(ppcTextureSamplerWrapCoordinates2DRTCAVResult + iVar8 * 4);
    *vectorInstWord = 0x1024492c;
    vectorInstWord[1] = 0x1021392e;
    vectorInstWord[2] = 0x10200a8c;
    vectorInstWord[3] = 0x104138ee;
    vectorInstWord[4] = 0x100a4a2c;
    vectorInstWord[5] = 0x10060780;
    ppcTextureSamplerWrapCoordinates2DRTCAVResult = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(param_1,vectorInstWord + 6);
    iVar8 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,ppcTextureSamplerWrapCoordinates2DRTCAVResult);
    vectorInstWord = (undefined4 *)(ppcTextureSamplerWrapCoordinates2DRTCAVResult + iVar8 * 4);
    *vectorInstWord = 0x1025492c;
    vectorInstWord[1] = 0x1021392e;
    vectorInstWord[2] = 0x10200a8c;
    vectorInstWord[3] = 0x104110ee;
    vectorInstWord[4] = 0x100a4b2c;
    vectorInstWord[5] = 0x10060780;
    ppcTextureSamplerWrapCoordinates2DRTCAVResult = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(param_1,vectorInstWord + 6);
    iVar8 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,ppcTextureSamplerWrapCoordinates2DRTCAVResult);
    vectorInstWord = (undefined4 *)(ppcTextureSamplerWrapCoordinates2DRTCAVResult + iVar8 * 4);
    *vectorInstWord = 0x1024492c;
    vectorInstWord[1] = 0x1021396e;
    vectorInstWord[2] = 0x10200a8c;
    vectorInstWord[3] = 0x104110ee;
    vectorInstWord[4] = 0x1003528c;
    vectorInstWord[5] = 0x10060780;
    ppcTextureSamplerWrapCoordinates2DRTCAVResult = ((int (*)())_PPCTextureSamplerWrapCoordinates2DRTCAV)(param_1,vectorInstWord + 6);
    iVar8 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,ppcTextureSamplerWrapCoordinates2DRTCAVResult);
    vectorInstWord = (undefined4 *)(ppcTextureSamplerWrapCoordinates2DRTCAVResult + iVar8 * 4);
    *vectorInstWord = 0x1025492c;
    vectorInstWord[1] = 0x1021396e;
    vectorInstWord[2] = 0x10200a8c;
    vectorInstWord = vectorInstWord + 3;
    *vectorInstWord = 0x104110ee;
  }
  return vectorInstWord + 1;
}

/* _PPCTextureSamplerSampleTexel3DFromLevelRTCAV @ 0x97be34ac (1612 bytes) */
int _PPCTextureSamplerSampleTexel3DFromLevelRTCAV(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  int ppcTextureSamplerWrapCoordinates3DRTCAVResult;
  int chunkIndex;
  bool bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  int iVar6;
  uint ppcInstWord2;
  int *piVar8;
  int iVar9;
  uint *ppcInstWord;
  undefined4 *vectorInstWord;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar8 = *(int **)(param_2 * 4 + *param_1);
  if (piVar8 == (int *)0x0) {
    return param_3;
  }
  param_1[1] = (int)piVar8;
  iVar6 = *piVar8;
  sVar2 = *(short *)(iVar6 + 0x10);
  sVar3 = *(short *)(iVar6 + 0x12);
  if (((sVar2 == -0x7ed3) || (sVar3 == -0x7ed3)) || (*(short *)(iVar6 + 0x14) == -0x7ed3)) {
    iVar9 = 0x812d;
  }
  else if ((((sVar2 != 0x2900) && (sVar3 != 0x2900)) && (*(short *)(iVar6 + 0x14) != 0x2900)) ||
          ((*(short *)(iVar6 + 0x16) == 0x2600 ||
           (iVar9 = 0x2900, *(short *)(iVar6 + 0x16) == 0x2700)))) {
    iVar9 = 0;
  }
  if (((param_1[5] == param_2) && (param_1[6] == 1)) && (param_1[7] == iVar9)) {
    iVar5 = param_1[10];
    if (iVar5 != 0) goto LAB_97be359c;
  }
  else {
    iVar5 = param_1[10];
LAB_97be359c:
    if (iVar5 == 0) {
      ppcInstWord2 = 0x3a310120;
      *param_3 = param_2 * 4 & 0xfffc | 0x82220000;
    }
    else {
      *param_3 = 0x1ef800d0;
      ppcInstWord2 = 0x7e31ba14;
      param_3 = param_3 + 1;
      *param_3 = 0x3a310120;
    }
    param_3[1] = ppcInstWord2;
    ppcInstWord = param_3 + 2;
    if ((sVar2 == 0x2901) || (sVar3 == 0x2901)) {
      *ppcInstWord = 0x39e00040;
      param_3[3] = 0x7e3178ce;
      ppcInstWord = param_3 + 4;
    }
    if (iVar9 == 0x812d) {
      *ppcInstWord = 0x82510070;
      ppcInstWord[1] = 0x82710074;
      ppcInstWord[2] = 0x39e00050;
      ppcInstWord[3] = 0x7df178ce;
      ppcInstWord[4] = 0x39e00080;
      ppcInstWord[5] = 0x7e1178ce;
      ppcInstWord2 = 0x823100a4;
    }
    else if (iVar9 == 0x2900) {
      *ppcInstWord = 0x82510070;
      ppcInstWord[1] = 0x82710074;
      ppcInstWord[2] = 0x39e00050;
      ppcInstWord[3] = 0x7df178ce;
      ppcInstWord[4] = 0x39e00080;
      ppcInstWord[5] = 0x7e1178ce;
      ppcInstWord2 = 0x823100a8;
    }
    else {
      *ppcInstWord = 0x82510020;
      ppcInstWord[1] = 0x82710024;
      ppcInstWord[2] = 0x39e00000;
      ppcInstWord[3] = 0x7df178ce;
      ppcInstWord[4] = 0x39e00030;
      ppcInstWord[5] = 0x7e1178ce;
      ppcInstWord2 = 0x823100a0;
    }
    ppcInstWord[6] = ppcInstWord2;
    param_1[5] = param_2;
    param_3 = ppcInstWord + 7;
    param_1[6] = 1;
    param_1[7] = iVar9;
    iVar6 = *piVar8;
  }
  uVar4 = *(ushort *)(iVar6 + 0x16);
  if (uVar4 == 0x2700) {
LAB_97be376c:
    if (param_1[8] != 0) {
      chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,param_3);
      param_3 = param_3 + chunkIndex;
    }
    chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedAVRTC,param_3);
    ppcTextureSamplerWrapCoordinates3DRTCAVResult = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,param_3 + chunkIndex);
    iVar9 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,ppcTextureSamplerWrapCoordinates3DRTCAVResult);
    vectorInstWord = (undefined4 *)(ppcTextureSamplerWrapCoordinates3DRTCAVResult + iVar9 * 4);
    *vectorInstWord = 0x10431c84;
  }
  else {
    if (uVar4 < 0x2701) {
      if (uVar4 == 0x2600) goto LAB_97be376c;
      bVar1 = uVar4 == 0x2601;
LAB_97be3764:
      if (!bVar1) {
        return param_3;
      }
    }
    else {
      if (uVar4 == 0x2702) goto LAB_97be376c;
      if (0x2701 < uVar4) {
        bVar1 = uVar4 == 0x2703;
        goto LAB_97be3764;
      }
    }
    if (param_1[8] != 0) {
      chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexProjectCoordinatesAVRTC,param_3);
      param_3 = param_3 + chunkIndex;
    }
    chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntNormalisedWithLERPValuesAVRTC,param_3);
    param_3[chunkIndex] = 0x10c00484;
    ppcTextureSamplerWrapCoordinates3DRTCAVResult = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,param_3 + chunkIndex + 1);
    iVar9 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,ppcTextureSamplerWrapCoordinates3DRTCAVResult);
    vectorInstWord = (undefined4 *)(ppcTextureSamplerWrapCoordinates3DRTCAVResult + iVar9 * 4);
    *vectorInstWord = 0x1024492c;
    vectorInstWord[1] = 0x1021392e;
    vectorInstWord[2] = 0x10044a2c;
    vectorInstWord[3] = 0x1021382e;
    vectorInstWord[4] = 0x10200a8c;
    vectorInstWord[5] = 0x104138ee;
    vectorInstWord[6] = 0x100a4a2c;
    vectorInstWord[7] = 0x10060780;
    ppcTextureSamplerWrapCoordinates3DRTCAVResult = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,vectorInstWord + 8);
    iVar9 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,ppcTextureSamplerWrapCoordinates3DRTCAVResult);
    vectorInstWord = (undefined4 *)(ppcTextureSamplerWrapCoordinates3DRTCAVResult + iVar9 * 4);
    *vectorInstWord = 0x1025492c;
    vectorInstWord[1] = 0x1021392e;
    vectorInstWord[2] = 0x10044a2c;
    vectorInstWord[3] = 0x1021382e;
    vectorInstWord[4] = 0x10200a8c;
    vectorInstWord[5] = 0x104110ee;
    vectorInstWord[6] = 0x100a4b2c;
    vectorInstWord[7] = 0x10060780;
    ppcTextureSamplerWrapCoordinates3DRTCAVResult = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,vectorInstWord + 8);
    iVar9 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,ppcTextureSamplerWrapCoordinates3DRTCAVResult);
    vectorInstWord = (undefined4 *)(ppcTextureSamplerWrapCoordinates3DRTCAVResult + iVar9 * 4);
    *vectorInstWord = 0x1024492c;
    vectorInstWord[1] = 0x1021396e;
    vectorInstWord[2] = 0x10044a2c;
    vectorInstWord[3] = 0x1021382e;
    vectorInstWord[4] = 0x10200a8c;
    vectorInstWord[5] = 0x104110ee;
    vectorInstWord[6] = 0x1003528c;
    vectorInstWord[7] = 0x10004a2c;
    vectorInstWord[8] = 0x10060780;
    ppcTextureSamplerWrapCoordinates3DRTCAVResult = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,vectorInstWord + 9);
    iVar9 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,ppcTextureSamplerWrapCoordinates3DRTCAVResult);
    vectorInstWord = (undefined4 *)(ppcTextureSamplerWrapCoordinates3DRTCAVResult + iVar9 * 4);
    *vectorInstWord = 0x1025492c;
    vectorInstWord[1] = 0x1021396e;
    vectorInstWord[2] = 0x10044a2c;
    vectorInstWord[3] = 0x1021382e;
    vectorInstWord[4] = 0x10200a8c;
    vectorInstWord[5] = 0x104110ee;
    vectorInstWord[6] = 0x100a492c;
    vectorInstWord[7] = 0x10060780;
    ppcTextureSamplerWrapCoordinates3DRTCAVResult = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,vectorInstWord + 8);
    iVar9 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,ppcTextureSamplerWrapCoordinates3DRTCAVResult);
    vectorInstWord = (undefined4 *)(ppcTextureSamplerWrapCoordinates3DRTCAVResult + iVar9 * 4);
    *vectorInstWord = 0x1024492c;
    vectorInstWord[1] = 0x1021392e;
    vectorInstWord[2] = 0x10054a2c;
    vectorInstWord[3] = 0x1021382e;
    vectorInstWord[4] = 0x10200a8c;
    vectorInstWord[5] = 0x104110ee;
    vectorInstWord[6] = 0x1003528c;
    vectorInstWord[7] = 0x1009032c;
    vectorInstWord[8] = 0x10060780;
    ppcTextureSamplerWrapCoordinates3DRTCAVResult = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,vectorInstWord + 9);
    iVar9 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,ppcTextureSamplerWrapCoordinates3DRTCAVResult);
    vectorInstWord = (undefined4 *)(ppcTextureSamplerWrapCoordinates3DRTCAVResult + iVar9 * 4);
    *vectorInstWord = 0x1025492c;
    vectorInstWord[1] = 0x1021392e;
    vectorInstWord[2] = 0x10054a2c;
    vectorInstWord[3] = 0x1021382e;
    vectorInstWord[4] = 0x10200a8c;
    vectorInstWord[5] = 0x104110ee;
    vectorInstWord[6] = 0x1003528c;
    vectorInstWord[7] = 0x1000492c;
    vectorInstWord[8] = 0x1000022c;
    vectorInstWord[9] = 0x10060780;
    ppcTextureSamplerWrapCoordinates3DRTCAVResult = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,vectorInstWord + 10);
    iVar9 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,ppcTextureSamplerWrapCoordinates3DRTCAVResult);
    vectorInstWord = (undefined4 *)(ppcTextureSamplerWrapCoordinates3DRTCAVResult + iVar9 * 4);
    *vectorInstWord = 0x1024492c;
    vectorInstWord[1] = 0x1021396e;
    vectorInstWord[2] = 0x10054a2c;
    vectorInstWord[3] = 0x1021382e;
    vectorInstWord[4] = 0x10200a8c;
    vectorInstWord[5] = 0x104110ee;
    vectorInstWord[6] = 0x1003528c;
    vectorInstWord[7] = 0x10060780;
    ppcTextureSamplerWrapCoordinates3DRTCAVResult = ((int (*)())_PPCTextureSamplerWrapCoordinates3DRTCAV)(param_1,vectorInstWord + 8);
    iVar9 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample3DAVRTC,ppcTextureSamplerWrapCoordinates3DRTCAVResult);
    vectorInstWord = (undefined4 *)(ppcTextureSamplerWrapCoordinates3DRTCAVResult + iVar9 * 4);
    *vectorInstWord = 0x1025492c;
    vectorInstWord[1] = 0x1021396e;
    vectorInstWord[2] = 0x10054a2c;
    vectorInstWord[3] = 0x1021382e;
    vectorInstWord[4] = 0x10200a8c;
    vectorInstWord = vectorInstWord + 5;
    *vectorInstWord = 0x104110ee;
  }
  return vectorInstWord + 1;
}

/* _PPCTextureSamplerSampleTexelRECTFromLevelRTCAV @ 0x97be3af8 (1084 bytes) */
int _PPCTextureSamplerSampleTexelRECTFromLevelRTCAV(param_1, param_2, param_3)
  int *param_1;
  uint param_2;
  uint *param_3;
{
  uint *vectorInstWord;
  int chunkIndex;
  bool bVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  uint ppcInstWord2;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint *ppcInstWord;
  
  if (7 < param_2) {
    param_2 = 7;
  }
  piVar8 = *(int **)(param_2 * 4 + *param_1);
  if (piVar8 == (int *)0x0) {
    return param_3;
  }
  param_1[1] = (int)piVar8;
  iVar6 = *piVar8;
  sVar2 = *(short *)(iVar6 + 0x10);
  sVar3 = *(short *)(iVar6 + 0x12);
  if ((sVar2 == -0x7ed3) || (sVar3 == -0x7ed3)) {
    iVar7 = 0x812d;
  }
  else if ((((sVar2 != 0x2900) && (sVar3 != 0x2900)) || (*(short *)(iVar6 + 0x16) == 0x2600)) ||
          (iVar7 = 0x2900, *(short *)(iVar6 + 0x16) == 0x2700)) {
    iVar7 = 0;
  }
  if (((param_1[5] != param_2) || (param_1[6] != 2)) || (param_1[7] != iVar7)) {
    *param_3 = param_2 * 4 & 0xfffc | 0x82220000;
    ppcInstWord = param_3 + 1;
    if ((sVar2 == 0x2901) || (sVar3 == 0x2901)) {
      *ppcInstWord = 0x39e00160;
      param_3[2] = 0x7e3178ce;
      ppcInstWord = param_3 + 3;
    }
    if (iVar7 == 0x812d) {
      *ppcInstWord = 0x82510190;
      ppcInstWord[1] = 0x39e00170;
      ppcInstWord[2] = 0x7df178ce;
      ppcInstWord[3] = 0x39e001a0;
      ppcInstWord[4] = 0x7e1178ce;
      ppcInstWord2 = 0x823101c4;
    }
    else if (iVar7 == 0x2900) {
      *ppcInstWord = 0x82510190;
      ppcInstWord[1] = 0x39e00170;
      ppcInstWord[2] = 0x7df178ce;
      ppcInstWord[3] = 0x39e001a0;
      ppcInstWord[4] = 0x7e1178ce;
      ppcInstWord2 = 0x823101c8;
    }
    else {
      *ppcInstWord = 0x82510140;
      ppcInstWord[1] = 0x39e00120;
      ppcInstWord[2] = 0x7df178ce;
      ppcInstWord[3] = 0x39e00150;
      ppcInstWord[4] = 0x7e1178ce;
      ppcInstWord2 = 0x823101c0;
    }
    ppcInstWord[5] = ppcInstWord2;
    param_1[7] = iVar7;
    param_3 = ppcInstWord + 6;
    param_1[5] = param_2;
    param_1[6] = 2;
    iVar6 = *piVar8;
  }
  uVar4 = *(ushort *)(iVar6 + 0x16);
  if (uVar4 == 0x2700) {
LAB_97be3d34:
    chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntDenormalisedAVRTC,param_3);
    vectorInstWord = param_3 + chunkIndex;
    chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,vectorInstWord);
    iVar7 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,vectorInstWord + chunkIndex);
    vectorInstWord = vectorInstWord + chunkIndex + iVar7;
    *vectorInstWord = 0x10431c84;
  }
  else {
    if (uVar4 < 0x2701) {
      if (uVar4 == 0x2600) goto LAB_97be3d34;
      bVar1 = uVar4 == 0x2601;
LAB_97be3d2c:
      if (!bVar1) {
        return param_3;
      }
    }
    else {
      if (uVar4 == 0x2702) goto LAB_97be3d34;
      if (0x2701 < uVar4) {
        bVar1 = uVar4 == 0x2703;
        goto LAB_97be3d2c;
      }
    }
    chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexFloatToIntDenormalisedWithLERPValuesAVRTC,param_3);
    vectorInstWord = param_3 + chunkIndex;
    *vectorInstWord = 0x10c00484;
    vectorInstWord = vectorInstWord + 1;
    chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,vectorInstWord);
    iVar7 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,vectorInstWord + chunkIndex);
    vectorInstWord = vectorInstWord + chunkIndex + iVar7;
    *vectorInstWord = 0x1024492c;
    vectorInstWord[1] = 0x1021392e;
    vectorInstWord[2] = 0x10200a8c;
    vectorInstWord[3] = 0x104138ee;
    vectorInstWord[4] = 0x100a4a2c;
    vectorInstWord[5] = 0x10060780;
    vectorInstWord = vectorInstWord + 6;
    chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,vectorInstWord);
    iVar7 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,vectorInstWord + chunkIndex);
    vectorInstWord = vectorInstWord + chunkIndex + iVar7;
    *vectorInstWord = 0x1025492c;
    vectorInstWord[1] = 0x1021392e;
    vectorInstWord[2] = 0x10200a8c;
    vectorInstWord[3] = 0x104110ee;
    vectorInstWord[4] = 0x100a4b2c;
    vectorInstWord[5] = 0x10060780;
    vectorInstWord = vectorInstWord + 6;
    chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,vectorInstWord);
    iVar7 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,vectorInstWord + chunkIndex);
    vectorInstWord = vectorInstWord + chunkIndex + iVar7;
    *vectorInstWord = 0x1024492c;
    vectorInstWord[1] = 0x1021396e;
    vectorInstWord[2] = 0x10200a8c;
    vectorInstWord[3] = 0x104110ee;
    vectorInstWord[4] = 0x1003528c;
    vectorInstWord[5] = 0x10060780;
    vectorInstWord = vectorInstWord + 6;
    chunkIndex = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexWrapCoordsCCCAVRTC,vectorInstWord);
    iVar7 = ((int (*)())_glpRTCAddAChunk_97be1c2c)(&_glpOpTexSample2DAVRTC,vectorInstWord + chunkIndex);
    vectorInstWord = vectorInstWord + chunkIndex + iVar7;
    *vectorInstWord = 0x1025492c;
    vectorInstWord[1] = 0x1021396e;
    vectorInstWord[2] = 0x10200a8c;
    vectorInstWord = vectorInstWord + 3;
    *vectorInstWord = 0x104110ee;
  }
  return vectorInstWord + 1;
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
int _PPCRasterOpMachine_DepthTestRTCAV(param_1, param_2)
  int *param_1;
  uint *param_2;
{
  uint ppcInstWord;
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = param_1[1];
  uVar2 = *(uint *)(*(int *)(*param_1 + 0xd80) + 0x50);
  uVar1 = uVar2 & 7;
  if ((uVar1 != 0) && (uVar1 != 7)) {
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    param_2[2] = 0xfc0d4000;
    param_2 = param_2 + 3;
  }
  uVar1 = (uint)(*(int *)(iVar3 + 0xe3c) - (int)param_2) >> 2;
  switch(uVar2 & 7) {
  case 0:
    *param_2 = (uVar1 & 0xffffff) << 2 | 0x48000000;
    goto LAB_97be44f0;
  case 1:
    ppcInstWord = 0x41800000;
    break;
  case 2:
    ppcInstWord = 0x41820000;
    break;
  case 3:
    ppcInstWord = 0x40810000;
    break;
  case 4:
    ppcInstWord = 0x41810000;
    break;
  case 5:
    ppcInstWord = 0x40820000;
    break;
  case 6:
    ppcInstWord = 0x40800000;
    break;
  default:
    goto switchD_97be4464_caseD_7;
  }
  *param_2 = ppcInstWord | 8;
  param_2 = param_2 + 1;
  *param_2 = (uVar1 - 1) * 4 & 0x3fffffc | 0x48000000;
LAB_97be44f0:
  param_2 = param_2 + 1;
switchD_97be4464_caseD_7:
  return param_2;
}

/* _PPCRasterOpMachine_DepthAndStencilTestRTCAV @ 0x97be44fc (1172 bytes) */
int _PPCRasterOpMachine_DepthAndStencilTestRTCAV(param_1, param_2)
  int *param_1;
  uint *param_2;
{
  uint *ppcRasterOpMachineUpdateStencilBufferRTCAVResult;
  uint *ppcRasterOpMachineUpdateStencilBufferRTCAVResult2;
  uint ppcInstWord4;
  uint ppcInstWord3;
  uint *ppcInstWord;
  bool bVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint *ppcInstWord2;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint *puVar15;
  
  iVar11 = *param_1;
  puVar15 = (uint *)0x0;
  iVar13 = param_1[1];
  iVar4 = *(int *)(iVar11 + 0xd80);
  uVar5 = *(uint *)(iVar4 + 0x48);
  uVar10 = *(uint *)(iVar4 + 0x3c);
  uVar2 = *(uint *)(iVar4 + 0x4c) >> 0x18;
  bVar1 = (uVar10 >> 6 & 1) == 0;
  uVar8 = *(uint *)(*(int *)(iVar11 + 0xd80) + 0x50);
  uVar9 = *(uint *)(*(int *)(iVar11 + 0xd80) + 0x70);
  if (bVar1) {
    uVar14 = 0xff;
  }
  else {
    uVar14 = uVar9 >> 8 & 0xff;
  }
  bVar3 = (uVar10 & 2) != 0;
  uVar12 = *(uint *)(iVar4 + 0x4c) >> 8 & 0xff;
  if (!bVar3) goto LAB_97be4754;
  *param_2 = 0x83430dac;
  param_2[1] = 0x8b3a0000;
  ppcInstWord2 = param_2 + 2;
  puVar6 = ppcInstWord2;
  switch(uVar5 >> 0xc & 7) {
  case 0:
    uVar5 = uVar5 >> 0xf;
    param_2 = ppcInstWord2;
    goto LAB_97be47b8;
  case 1:
    *ppcInstWord2 = uVar2 & uVar12 | 0x3ba00000;
    param_2[3] = uVar12 | 0x733e0000;
    ppcInstWord3 = 0x41800000;
    break;
  case 2:
    *ppcInstWord2 = uVar2 & uVar12 | 0x3ba00000;
    param_2[3] = uVar12 | 0x733e0000;
    ppcInstWord3 = 0x41820000;
    break;
  case 3:
    *ppcInstWord2 = uVar2 & uVar12 | 0x3ba00000;
    param_2[3] = uVar12 | 0x733e0000;
    ppcInstWord3 = 0x40810000;
    break;
  case 4:
    *ppcInstWord2 = uVar2 & uVar12 | 0x3ba00000;
    param_2[3] = uVar12 | 0x733e0000;
    ppcInstWord3 = 0x41810000;
    break;
  case 5:
    *ppcInstWord2 = uVar2 & uVar12 | 0x3ba00000;
    param_2[3] = uVar12 | 0x733e0000;
    ppcInstWord3 = 0x40820000;
    break;
  case 6:
    *ppcInstWord2 = uVar2 & uVar12 | 0x3ba00000;
    param_2[3] = uVar12 | 0x733e0000;
    ppcInstWord3 = 0x40800000;
    break;
  case 7:
    *ppcInstWord2 = 0x48000000;
    puVar6 = param_2 + 3;
    puVar15 = ppcInstWord2;
  default:
    goto switchD_97be45d8_default;
  }
  param_2[4] = 0x7c1df000;
  puVar15 = param_2 + 5;
  *puVar15 = ppcInstWord3;
  puVar6 = param_2 + 6;
switchD_97be45d8_default:
  ppcRasterOpMachineUpdateStencilBufferRTCAVResult = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(uVar5 >> 0xf & 7,0x1a,0x19,uVar2,uVar14,puVar6);
  param_2 = ppcRasterOpMachineUpdateStencilBufferRTCAVResult + 1;
  *ppcRasterOpMachineUpdateStencilBufferRTCAVResult = *(int *)(iVar13 + 0xe3c) - (int)ppcRasterOpMachineUpdateStencilBufferRTCAVResult & 0x3fffffcU | 0x48000000;
  *puVar15 = *puVar15 | (int)param_2 - (int)puVar15 & 0xfffcU;
LAB_97be4754:
  if ((uVar10 & 4) == 0) {
    if (!bVar3) {
      return param_2;
    }
    ppcRasterOpMachineUpdateStencilBufferRTCAVResult2 = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(uVar5 >> 0x15 & 7,0x1a,0x19,uVar2,uVar14,param_2);
    return ppcRasterOpMachineUpdateStencilBufferRTCAVResult2;
  }
  switch(uVar8 & 7) {
  case 0:
    if (bVar3) {
      uVar5 = uVar5 >> 0x12;
LAB_97be47b8:
      param_2 = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(uVar5 & 7,0x1a,0x19,uVar2,uVar14,param_2);
    }
    *param_2 = *(int *)(iVar13 + 0xe3c) - (int)param_2 & 0x3fffffcU | 0x48000000;
    return param_2 + 1;
  case 1:
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    ppcInstWord4 = 0x41800000;
    break;
  case 2:
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    ppcInstWord4 = 0x41820000;
    break;
  case 3:
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    ppcInstWord4 = 0x40810000;
    break;
  case 4:
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    ppcInstWord4 = 0x41810000;
    break;
  case 5:
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    ppcInstWord4 = 0x40820000;
    break;
  case 6:
    *param_2 = 0x81e30da8;
    param_2[1] = 0xc10f0000;
    ppcInstWord4 = 0x40800000;
    break;
  case 7:
    *param_2 = 0x81e30da8;
    ppcInstWord4 = 0x48000000;
    goto LAB_97be48e0;
  default:
    goto switchD_97be4784_default;
  }
  param_2 = param_2 + 2;
  *param_2 = 0xfc0d4000;
LAB_97be48e0:
  puVar15 = param_2 + 1;
  *puVar15 = ppcInstWord4;
  param_2 = param_2 + 2;
switchD_97be4784_default:
  if (bVar3) {
    param_2 = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(uVar5 >> 0x12 & 7,0x1a,0x19,uVar2,uVar14,param_2);
  }
  *param_2 = *(int *)(iVar13 + 0xe3c) - (int)param_2 & 0x3fffffcU | 0x48000000;
  ppcInstWord = param_2 + 1;
  *puVar15 = *puVar15 | (int)ppcInstWord - (int)puVar15 & 0xfffcU;
  if (bVar3) {
    ppcInstWord = (uint *)((int (*)())_PPCRasterOpMachineUpdateStencilBufferRTCAV)(uVar5 >> 0x15 & 7,0x1a,0x19,uVar2,uVar14,ppcInstWord);
  }
  if ((bVar1) || ((uVar9 & 0x10000) != 0)) {
    *ppcInstWord = 0xd1af0000;
    ppcInstWord = ppcInstWord + 1;
  }
  return ppcInstWord;
}

/* _PPCRasterOpMachine_AlphaTestRTCAV @ 0x97be49d0 (616 bytes) */
int _PPCRasterOpMachine_AlphaTestRTCAV(param_1, param_2)
  int *param_1;
  uint *param_2;
{
  uint ppcInstWord;
  uint framebufferFormat;
  float fVar1;
  uint uVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  double dVar7;
  
  uVar6 = 0;
  iVar4 = *(int *)(*param_1 + 0xd80);
  uVar5 = *(uint *)(iVar4 + 0x40);
  fVar3 = *(float *)(iVar4 + 0x44);
  uVar2 = uVar5 & 7;
  if ((uVar2 != 7) && (uVar2 != 0)) {
    framebufferFormat = _PPEmulatorFramebufferFormat(*param_1);
    if ((framebufferFormat & 0x1c000) == 0) {
      *param_2 = 0x3b000210;
      param_2[1] = 0x7e63c1ce;
      param_2[2] = 0xc123021c;
      param_2[3] = (uint)(int)fVar3 >> 0x10 | 0x3de00000;
      param_2[4] = (uint)(int)fVar3 & 0xffff | 0x61ef0000;
      param_2[5] = 0x91e30210;
      param_2[6] = 0xc1030210;
      ppcInstWord = 0xfc094000;
    }
    else {
      fVar1 = TAllocation__guardBlockSize;
      if ((fVar3 < TAllocation__guardBlockSize) || (fVar1 = FLOAT_97c3acd8, FLOAT_97c3acd8 < fVar3))
      {
        fVar3 = fVar1;
      }
      fVar3 = fVar3 * FLOAT_97c3acbc + FLOAT_97c3acc0;
      dVar7 = (double)fVar3;
      if (DOUBLE_97c30a78 <= dVar7) {
        ppcInstWord = (uint)(int)(dVar7 - DOUBLE_97c30a78);
      }
      else {
        ppcInstWord = (uint)(int)fVar3;
      }
      *param_2 = 0x10734c0a;
      param_2[1] = 0x1063444a;
      param_2[2] = 0x10635b2e;
      param_2[3] = 0x10601b8a;
      param_2[4] = 0x3b000210;
      param_2[5] = 0x7c63c1ce;
      ppcInstWord = ppcInstWord & 0xffff | 0x2c170000;
      param_2[6] = 0x82e3021c;
    }
    param_2[7] = ppcInstWord;
    param_2 = param_2 + 8;
    uVar6 = (uint)(*(int *)(param_1[1] + 0xe3c) - (int)param_2) >> 2;
  }
  switch(uVar5 & 7) {
  case 0:
    uVar6 = *(int *)(param_1[1] + 0xe3c) - (int)param_2 & 0x3fffffcU | 0x48000000;
    break;
  case 1:
    uVar6 = (uVar6 & 0x3fff) << 2 | 0x40800000;
    break;
  case 2:
    uVar6 = (uVar6 & 0x3fff) << 2 | 0x40820000;
    break;
  case 3:
    uVar6 = (uVar6 & 0x3fff) << 2 | 0x41810000;
    break;
  case 4:
    uVar6 = (uVar6 & 0x3fff) << 2 | 0x40810000;
    break;
  case 5:
    uVar6 = (uVar6 & 0x3fff) << 2 | 0x41820000;
    break;
  case 6:
    uVar6 = (uVar6 & 0x3fff) << 2 | 0x41800000;
    break;
  default:
    goto switchD_97be4bb8_caseD_7;
  }
  *param_2 = uVar6;
  param_2 = param_2 + 1;
switchD_97be4bb8_caseD_7:
  return param_2;
}

/* _PPCRasterOpMachine_BlendingRTCAV @ 0x97be4c58 (888 bytes) */
int _PPCRasterOpMachine_BlendingRTCAV(param_1, param_2)
  int *param_1;
  uint *param_2;
{
  uint vectorInstWord4;
  undefined4 *vectorInstWord2;
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *vectorInstWord3;
  uint uVar5;
  int vectorInstWord;
  
  vectorInstWord = 0x13;
  uVar5 = *(uint *)(*(int *)(*param_1 + 0xd80) + 0x58);
  uVar2 = _PPEmulatorFramebufferFormat(*param_1);
  if ((uVar2 & 0x8000000) == 0) {
    *param_2 = 0x1273444a;
    param_2[1] = 0x12734c0a;
    param_2 = param_2 + 2;
  }
  if ((1 < (uVar5 >> 0x10 & 7) - 3) || (1 < (uVar5 >> 0x13 & 7) - 3)) {
    if (((((uVar5 & 0xf) - 8 < 4) ||
         (((uVar2 = uVar5 >> 4 & 0xf, uVar2 == 8 || (uVar2 == 9)) || (uVar2 == 10)))) ||
        ((((uVar2 == 0xb || (uVar2 = uVar5 >> 8 & 0xf, uVar2 == 8)) || (uVar2 == 9)) ||
         ((uVar2 == 10 || (uVar2 == 0xb)))))) ||
       ((uVar2 = uVar5 >> 0xc & 0xf, uVar2 == 8 ||
        (((uVar2 == 9 || (uVar2 == 10)) || (uVar2 == 0xb)))))) {
      *param_2 = 0x81e30d9c;
      param_2[1] = 0x81ef00d8;
      param_2[2] = 0x39c02d70;
      param_2[3] = 0x7ccf70ce;
      param_2 = param_2 + 4;
    }
    puVar3 = (undefined4 *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(param_2,0,uVar5 & 0xf);
    uVar2 = uVar5 >> 4 & 0xf;
    if ((uVar5 & 0xf) != uVar2) {
      vectorInstWord3 = (undefined4 *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(puVar3,3,uVar2);
      puVar3 = vectorInstWord3 + 1;
      *vectorInstWord3 = 0x10001b6a;
    }
    param_2 = (uint *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(puVar3,1,uVar5 >> 8 & 0xf);
    uVar2 = uVar5 >> 0xc & 0xf;
    if ((uVar5 >> 8 & 0xf) != uVar2) {
      vectorInstWord2 = (undefined4 *)((int (*)())_PPCRasterOpMachineCalculateBlendingFactorsRTCAV)(param_2,3,uVar2);
      param_2 = vectorInstWord2 + 1;
      *vectorInstWord2 = 0x10211b6a;
    }
  }
  uVar2 = uVar5 >> 0x10 & 7;
  bVar1 = uVar2 == (uVar5 >> 0x13 & 7);
  if (!bVar1) {
    vectorInstWord = 3;
  }
  switch(uVar2) {
  case 0:
    *param_2 = 0x1093482e;
    param_2 = param_2 + 1;
    *param_2 = vectorInstWord << 0x15 | 0x1002206e;
    goto LAB_97be4f04;
  case 1:
    *param_2 = 0x1093482e;
    vectorInstWord4 = vectorInstWord << 0x15 | 0x1004284a;
    break;
  case 2:
    *param_2 = 0x1093482e;
    vectorInstWord4 = vectorInstWord << 0x15 | 0x1005204a;
    break;
  case 3:
    vectorInstWord4 = vectorInstWord << 0x15 | 0x1013144a;
    goto LAB_97be4f00;
  case 4:
    vectorInstWord4 = vectorInstWord << 0x15 | 0x1013140a;
LAB_97be4f00:
    *param_2 = vectorInstWord4;
    goto LAB_97be4f04;
  default:
    goto switchD_97be4e5c_default;
  }
  param_2[1] = 0x10a2486e;
  param_2 = param_2 + 2;
  *param_2 = vectorInstWord4;
LAB_97be4f04:
  param_2 = param_2 + 1;
switchD_97be4e5c_default:
  if (bVar1) {
    return param_2;
  }
  switch(uVar5 >> 0x13 & 7) {
  case 0:
    vectorInstWord4 = 0x1262206e;
    *param_2 = 0x1093482e;
    goto LAB_97be4f88;
  case 1:
    *param_2 = 0x1093482e;
    vectorInstWord4 = 0x1264284a;
    break;
  case 2:
    *param_2 = 0x1093482e;
    vectorInstWord4 = 0x1265204a;
    break;
  case 3:
    vectorInstWord4 = 0x1273144a;
    goto LAB_97be4fc4;
  case 4:
    vectorInstWord4 = 0x1273140a;
LAB_97be4fc4:
    *param_2 = vectorInstWord4;
    goto LAB_97be4fc8;
  default:
    goto switchD_97be4f38_default;
  }
  param_2 = param_2 + 1;
  *param_2 = 0x10a2486e;
LAB_97be4f88:
  param_2 = param_2 + 1;
  *param_2 = vectorInstWord4;
LAB_97be4fc8:
  param_2 = param_2 + 1;
switchD_97be4f38_default:
  *param_2 = vectorInstWord << 0x10 | 0x12609b6a;
  return param_2 + 1;
}

/* _PPCRasterOpMachine_LogicOpRTCAV @ 0x97be4ff8 (520 bytes) */
int _PPCRasterOpMachine_LogicOpRTCAV(param_1, param_2)
  int *param_1;
  uint *param_2;
{
  uint vectorInstWord2;
  uint vectorInstWord;
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*(int *)(*param_1 + 0xd80) + 0x68);
  uVar1 = uVar2 & 0xf;
  if ((uVar1 < 3) || (uVar1 == 4)) {
    if (uVar1 == 1) {
      vectorInstWord = 0x12684484;
    }
    else if (uVar1 < 2) {
      if (uVar1 != 0) {
        return param_2;
      }
      vectorInstWord = 0x12694c84;
    }
    else {
      if (uVar1 == 2) {
        return param_2;
      }
      if (uVar1 != 4) {
        return param_2;
      }
      vectorInstWord = 0x12621484;
    }
    *param_2 = vectorInstWord;
    goto LAB_97be507c;
  }
  if (uVar1 != 5) {
    *param_2 = 0x10734b2e;
    param_2[1] = 0x10601b8a;
    param_2 = param_2 + 2;
  }
  uVar2 = uVar2 & 0xf;
  if (uVar2 != 3) {
    *param_2 = 0x10824b2e;
    param_2[1] = 0x1080238a;
    param_2 = param_2 + 2;
  }
  switch(uVar2) {
  case 3:
    vectorInstWord = 0x10c30000;
    goto LAB_97be5148;
  default:
    goto switchD_97be5104_caseD_4;
  case 5:
    vectorInstWord = 0x10c40000;
LAB_97be5148:
    vectorInstWord = vectorInstWord | 0x4d04;
    break;
  case 6:
    vectorInstWord = 0x10c32404;
    break;
  case 7:
    vectorInstWord = 0x10c32404;
    goto LAB_97be51a0;
  case 8:
    vectorInstWord = 0x10c32484;
    break;
  case 9:
    vectorInstWord = 0x10c32504;
    break;
  case 10:
    vectorInstWord = 0x10c324c4;
    break;
  case 0xb:
    vectorInstWord = 0x10c324c4;
LAB_97be51a0:
    vectorInstWord2 = 0x10c64d04;
LAB_97be51d8:
    *param_2 = vectorInstWord;
    param_2 = param_2 + 1;
    *param_2 = vectorInstWord2;
    goto LAB_97be51e0;
  case 0xc:
    vectorInstWord = 0x10c32444;
    break;
  case 0xd:
    vectorInstWord = 0x10c41c44;
    break;
  case 0xe:
    vectorInstWord = 0x10840000;
    goto LAB_97be51cc;
  case 0xf:
    vectorInstWord = 0x10630000;
LAB_97be51cc:
    vectorInstWord = vectorInstWord | 0x4d04;
    vectorInstWord2 = 0x10c32484;
    goto LAB_97be51d8;
  }
  *param_2 = vectorInstWord;
LAB_97be51e0:
  param_2 = param_2 + 1;
switchD_97be5104_caseD_4:
  *param_2 = 0x39e00020;
  param_2[1] = 0x7c6378ce;
  param_2[2] = 0x10c61c04;
  param_2[3] = 0x10c0330a;
  param_2[4] = 0x39e00070;
  param_2[5] = 0x7c6378ce;
  param_2 = param_2 + 6;
  *param_2 = 0x126648ee;
LAB_97be507c:
  return param_2 + 1;
}

/* _PPCRasterOpMachine_BufferMaskRTCAV @ 0x97be5234 (208 bytes) */
int _PPCRasterOpMachine_BufferMaskRTCAV(param_1, param_2)
  int *param_1;
  undefined4 *param_2;
{
  uint uVar1;
  undefined4 vectorInstWord;
  
  vectorInstWord = 0x1063492c;
  uVar1 = *(uint *)(*(int *)(*param_1 + 0xd80) + 0x70);
  *param_2 = 0x10836a8c;
  if ((uVar1 & 0x20000) == 0) {
    vectorInstWord = 0x1063212c;
  }
  param_2[1] = vectorInstWord;
  vectorInstWord = 0x1063492c;
  if ((uVar1 & 0x40000) == 0) {
    vectorInstWord = 0x1063212c;
  }
  param_2[2] = vectorInstWord;
  vectorInstWord = 0x1063492c;
  if ((uVar1 & 0x80000) == 0) {
    vectorInstWord = 0x1063212c;
  }
  param_2[3] = vectorInstWord;
  vectorInstWord = 0x1063492c;
  if ((uVar1 & 0x100000) == 0) {
    vectorInstWord = 0x1063212c;
  }
  param_2[4] = vectorInstWord;
  param_2[5] = 0x127310ea;
  return param_2 + 6;
}

/* _PPCRasterOpMachineCalculateBlendingFactorsRTCAV @ 0x97be5304 (400 bytes) */
int _PPCRasterOpMachineCalculateBlendingFactorsRTCAV(param_1, param_2, param_3)
  uint *param_1;
  int param_2;
  undefined4 param_3;
{
  uint vectorInstWord;
  uint vectorInstWord2;
  
  switch(param_3) {
  case 0:
    vectorInstWord = param_2 << 0x15 | 0x10094c84;
    break;
  case 1:
    vectorInstWord = param_2 << 0x15 | 0x10084484;
    break;
  case 2:
    vectorInstWord = param_2 << 0x15 | 0x10139c84;
    break;
  case 3:
    vectorInstWord = param_2 << 0x15 | 0x1008984a;
    break;
  case 4:
    vectorInstWord = param_2 << 0x15 | 0x10039a8c;
    break;
  case 5:
    vectorInstWord = param_2 << 0x15 | param_2 << 0xb | 0x10080000;
    vectorInstWord2 = param_2 << 0x15 | 0x10039a8c;
    goto LAB_97be545c;
  case 6:
    vectorInstWord = param_2 << 0x15 | 0x1003128c;
    break;
  case 7:
    vectorInstWord = param_2 << 0x15 | param_2 << 0xb | 0x10080000;
    vectorInstWord2 = param_2 << 0x15 | 0x1003128c;
    goto LAB_97be545c;
  case 8:
    vectorInstWord = param_2 << 0x15 | 0x10063484;
    break;
  case 9:
    vectorInstWord = param_2 << 0x15 | 0x1008304a;
    break;
  case 10:
    vectorInstWord = param_2 << 0x15 | 0x1003328c;
    break;
  case 0xb:
    vectorInstWord = param_2 << 0x15 | param_2 << 0xb | 0x10080000;
    vectorInstWord2 = param_2 << 0x15 | 0x1003328c;
LAB_97be545c:
    *param_1 = vectorInstWord2;
    param_1 = param_1 + 1;
    *param_1 = vectorInstWord | 0x4a;
    goto LAB_97be5394;
  case 0xc:
    vectorInstWord = param_2 << 0x15 | 0x10021484;
    break;
  case 0xd:
    vectorInstWord = param_2 << 0x15 | 0x1008104a;
    break;
  case 0xe:
    vectorInstWord = param_2 << 0x15;
    vectorInstWord2 = vectorInstWord | param_2 << 0x10;
    *param_1 = vectorInstWord | 0x1008104a;
    param_1[1] = vectorInstWord2 | 0x10009c4a;
    param_1[2] = vectorInstWord | param_2 << 0xb | 0x1003028c;
    param_1 = param_1 + 3;
    *param_1 = vectorInstWord2 | 0x1000436a;
    goto LAB_97be5394;
  default:
    return param_1;
  }
  *param_1 = vectorInstWord;
LAB_97be5394:
  return param_1 + 1;
}

/* _PPCRasterOpMachineUpdateStencilBufferRTCAV @ 0x97be54d0 (468 bytes) */
int _PPCRasterOpMachineUpdateStencilBufferRTCAV(param_1, param_2, param_3, param_4, param_5, param_6)
  undefined4 param_1;
  int param_2;
  uint param_3;
  uint param_4;
  uint param_5;
  uint *param_6;
{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  
  switch(param_1) {
  case 0:
    *param_6 = param_5 ^ 0xffff | param_3 << 0x15 | 0x701e0000;
    puVar3 = param_6 + 1;
    *puVar3 = param_2 << 0x10 | 0x9bc00000;
    goto LAB_97be5588;
  case 1:
    return param_6;
  case 2:
    *param_6 = param_5 ^ 0xffff | param_3 << 0x15 | 0x701e0000;
    param_6[1] = param_4 & param_5 | 0x3be00000;
    puVar3 = param_6 + 2;
    *puVar3 = 0x7fdefb78;
    goto LAB_97be5580;
  case 3:
    *param_6 = (param_3 & 0x1f) << 0x10 | 0x2c0000ff;
    param_6[1] = param_3 << 0x10 | 0x3be00000;
    param_6[2] = 0x40800008;
    uVar1 = param_5 ^ 0xffff | param_3 << 0x15;
    uVar2 = param_3 << 0x10 | 0x3be00001;
    break;
  case 4:
    *param_6 = (param_3 & 0x1f) << 0x10 | 0x2c000000;
    param_6[1] = param_3 << 0x10 | 0x3be00000;
    param_6[2] = 0x40810008;
    uVar1 = param_5 ^ 0xffff | param_3 << 0x15;
    uVar2 = param_3 << 0x10 | 0x3be0ffff;
    break;
  case 5:
    *param_6 = param_5 ^ 0xffff | param_3 << 0x15 | 0x701e0000;
    param_6[1] = param_3 << 0x15 | param_3 << 0xb | 0x7c1f00f8;
    param_6[2] = param_5 | 0x73ff0000;
    param_6[3] = 0x7fdefb78;
    param_6[4] = param_2 << 0x10 | 0x9bc00000;
    return param_6 + 5;
  case 6:
    uVar1 = param_5 ^ 0xffff | param_3 << 0x15;
    uVar2 = param_3 << 0x10 | 0x3be00001;
    goto LAB_97be55e8;
  case 7:
    uVar1 = param_5 ^ 0xffff | param_3 << 0x15;
    uVar2 = param_3 << 0x10 | 0x3be0ffff;
LAB_97be55e8:
    *param_6 = uVar2;
    puVar3 = param_6 + 1;
    *puVar3 = 0x73ff00ff;
    goto LAB_97be55f4;
  default:
    return param_6;
  }
  puVar3 = param_6 + 3;
  *puVar3 = uVar2;
LAB_97be55f4:
  puVar3[1] = uVar1 | 0x701e0000;
  puVar3[2] = param_5 | 0x73ff0000;
  puVar3 = puVar3 + 3;
  *puVar3 = 0x7fdefb78;
LAB_97be5580:
  puVar3 = puVar3 + 1;
  *puVar3 = param_2 << 0x10 | 0x9bc00000;
LAB_97be5588:
  return puVar3 + 1;
}

