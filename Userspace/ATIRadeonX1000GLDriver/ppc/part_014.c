#include "decls.h"

/* FUN_000934f0 @ 0x934f0 (20 bytes) */
int FUN_000934f0(allocState)
  int allocState;
{
  undefined4 uVar1;
  int allocStatus;
  int emitTable;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 selectRowA0;
  undefined4 selectRowA1;
  undefined4 selectRowA2;
  undefined4 selectRowA3;
  undefined4 selectRowC0;
  undefined4 selectRowC1;
  undefined4 selectRowC2;
  undefined4 selectRowC3;
  undefined4 selectRowB0;
  undefined4 selectRowB1;
  undefined4 selectRowB2;
  undefined4 selectRowB3;
  undefined1 tempA [4];
  undefined4 tempAReg;
  undefined1 tempAMask [16];
  undefined4 tempASelect0;
  undefined4 tempASelect1;
  undefined4 tempASelect2;
  undefined1 tempB [4];
  undefined4 tempBReg;
  undefined1 tempBMask [16];
  undefined4 tempBSelect0;
  undefined4 tempBSelect1;
  undefined4 tempBSelect3;
  
  if (allocState == 0) {
    return 1;
  }
  uVar1 = 0;
  emitTable = *(int *)(allocState + 0x3d4);
  if (*(int *)(allocState + 0x4e8) == -1) {
    if ((*(int *)(allocState + 0x4c0) == -1) &&
       (ffvpEmitReflectionVector(allocState), *(int *)(allocState + 0x4c0) == -1)) {
      return 2;
    }
    allocStatus = ffvpAllocTempRegister(allocState,1,allocState + 0x4e4);
    if (allocStatus == 0) {
      uVar1 = *(undefined4 *)(allocState + 0x4e8);
      allocStatus = ffvpAllocTempRegister(allocState,2,tempA);
      if (allocStatus == 0) {
        allocStatus = ffvpAllocTempRegister(allocState,2,tempB);
        if (allocStatus == 0) {
          uVar5 = **(undefined4 **)(allocState + 0x3ec);
          uVar4 = **(undefined4 **)(allocState + 0x3f0);
          (**(code **)(((unsigned char *)0x000012f0) + emitTable))
                    (allocState,uVar4,tempAReg,tempAMask,uVar5,tempAReg,&DAT_001dbdb4,&DAT_001fa5e8,uVar5,tempAReg,&DAT_001dbdb4,&DAT_001fa5e8)
          ;
          selectRowA0 = 4;
          selectRowA1 = 4;
          selectRowA3 = 4;
          selectRowA2 = tempASelect2;
          (**(code **)(((unsigned char *)0x000012f4) + emitTable))
                    (allocState,uVar4,uVar1,&DAT_001dbd84,uVar5,tempAReg,&tempASelect0,&DAT_001fa5e8,uVar5,(*(int *)((int)allocState + 1216)),(&DAT_001dbd74),&DAT_001fa5e8,uVar5,tempAReg,(&selectRowA0),&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + emitTable))
                    (allocState,uVar4,tempAReg,tempAMask,uVar5,uVar1,&DAT_001dbd74,&DAT_001fa5e8,uVar5,uVar1,&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x00001318) + emitTable))
                    (allocState,uVar4,tempAReg,tempAMask,uVar5,tempAReg,&tempASelect0,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x0000131c) + emitTable))
                    (allocState,uVar4,tempBReg,tempBMask,uVar5,tempBReg,&DAT_001dbdb4,&DAT_001dbd94)
          ;
          selectRowC0 = *(undefined4 *)(allocState + 0x4d4);
          selectRowC1 = *(undefined4 *)(allocState + 0x4d8);
          selectRowB2 = 4;
          selectRowA2 = 4;
          selectRowA3 = 4;
          selectRowA0 = tempASelect0;
          selectRowA1 = tempASelect1;
          selectRowC2 = 4;
          selectRowC3 = 4;
          selectRowB0 = tempBSelect0;
          selectRowB1 = tempBSelect1;
          selectRowB3 = tempBSelect3;
          (**(code **)(((unsigned char *)0x000012f4) + emitTable))
                    (allocState,uVar4,uVar1,&DAT_001dbd84,uVar5,tempAReg,&selectRowA0,&DAT_001fa5e8,uVar5,(*(int *)((int)allocState + 1216)),(&selectRowC0),&DAT_001fa5e8,uVar5,tempBReg,(&selectRowB0),&DAT_001fa5e8);
          ffvpFreeTempRegister(allocState,tempA);
          ffvpFreeTempRegister(allocState,tempB);
          return 0;
        }
      }
    }
    uVar1 = 7;
  }
  return uVar1;
}

/* ffvpEmitBlendedEyeNormal @ 0x93510 (1220 bytes) */
int ffvpEmitBlendedEyeNormal(programBuilder, matrixSelectors, matrixCount, implicitLastWeight)
  int programBuilder;
  int matrixSelectors;
  uint matrixCount;
  int implicitLastWeight;
{
  undefined4 eyeNormalReg;
  undefined4 *dstMask;
  int glCtx;
  int sourceNormalRegB;
  int selectorB;
  int invModelviewReg;
  int allocStatus;
  int sourceNormalReg;
  uint loopIndex;
  int selector;
  int checkIndex;
  int builderCursor;
  undefined4 dstTempFile;
  int *invModelviewRegCursor;
  undefined4 constFile;
  undefined4 *fileTable;
  undefined4 srcTempFile;
  uint remaining;
  undefined1 tempX [4];
  undefined4 tempXReg;
  undefined1 tempY [4];
  undefined4 tempYReg;
  undefined1 tempZ [4];
  undefined4 tempZReg;
  undefined *maskBaseX;
  undefined *maskBaseY;
  undefined *maskBaseZ;
  undefined1 *tempYOperand;
  int *invModelviewRegs;
  undefined1 *tempZOperand;
  int emit1Src1Index;
  int emit2Src1File;
  
  if (programBuilder == 0) {
    return 1;
  }
  if (4 < matrixCount) {
    return 4;
  }
  if (matrixCount != 0) {
    checkIndex = 0;
    builderCursor = programBuilder;
    remaining = matrixCount;
    do {
      selector = *(int *)(matrixSelectors + checkIndex * 4);
      if (selector == 0) {
        sourceNormalReg = *(int *)(programBuilder + 4);
      }
      else {
        if (selector != 1) {
          return 3;
        }
        sourceNormalReg = *(int *)(programBuilder + 100);
      }
      if (sourceNormalReg == -1) {
        return 2;
      }
      if (*(int *)(builderCursor + 0xc4) == -1) {
        return 2;
      }
      checkIndex = checkIndex + 1;
      builderCursor = builderCursor + 4;
      remaining = remaining - 1;
    } while (remaining != 0);
  }
  if ((matrixCount < 4) && (implicitLastWeight != 0)) {
    selectorB = *(int *)(matrixSelectors + matrixCount * 4);
    if (selectorB == 0) {
      sourceNormalRegB = *(int *)(programBuilder + 4);
    }
    else {
      if (selectorB != 1) {
        return 3;
      }
      sourceNormalRegB = *(int *)(programBuilder + 100);
    }
    if (sourceNormalRegB == -1) {
      return 2;
    }
    if (*(int *)(matrixCount * 4 + programBuilder + 0xc4) == -1) {
      return 2;
    }
  }
  glCtx = *(int *)(programBuilder + 0x3d4);
  if (*(int *)(programBuilder + 0x448) != -1) {
    return 0;
  }
  if ((*(int *)(programBuilder + 0x560) == -1) &&
     (ffvpEmitBlendWeights(programBuilder,matrixCount,implicitLastWeight), *(int *)(programBuilder + 0x560) == -1)) {
    return 2;
  }
  if ((matrixCount < 4) && (implicitLastWeight != 0)) {
    matrixCount = matrixCount + 1;
  }
  allocStatus = ffvpAllocTempRegister(programBuilder,1,programBuilder + 0x444);
  if ((allocStatus == 0) && (allocStatus = ffvpAllocTempRegister(programBuilder,0,tempX), allocStatus == 0)) {
    tempYOperand = tempY;
    allocStatus = ffvpAllocTempRegister(programBuilder,0,tempYOperand);
    if (allocStatus == 0) {
      tempZOperand = tempZ;
      allocStatus = ffvpAllocTempRegister(programBuilder,0,tempZOperand);
      if (allocStatus == 0) {
        fileTable = *(undefined4 **)(programBuilder + 0x3ec);
        constFile = fileTable[2];
        dstTempFile = **(undefined4 **)(programBuilder + 0x3f0);
        if (matrixCount == 0) {
          maskBaseX = &DAT_001e3520;
          maskBaseY = &DAT_001e3520;
          maskBaseZ = &DAT_001e3520;
LAB_0009388c:
          srcTempFile = *fileTable;
          eyeNormalReg = *(undefined4 *)(programBuilder + 0x448);
          emit1Src1Index = *(int *)((int)programBuilder + 1376);
          (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                    (programBuilder,dstTempFile,eyeNormalReg,maskBaseX + -0x781c,srcTempFile,tempXReg,&DAT_001dbd14,
                     &DAT_001fa5e8,srcTempFile,emit1Src1Index,&DAT_001dbd14,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                    (programBuilder,dstTempFile,eyeNormalReg,maskBaseY + -0x77bc,srcTempFile,tempYReg,&DAT_001dbd14,
                     &DAT_001fa5e8,srcTempFile,emit1Src1Index,&DAT_001dbd14,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                    (programBuilder,dstTempFile,eyeNormalReg,maskBaseZ + -0x77cc,srcTempFile,tempZReg,&DAT_001dbd14,
                     &DAT_001fa5e8,srcTempFile,emit1Src1Index,&DAT_001dbd14,&DAT_001fa5e8);
          ffvpFreeTempRegister(programBuilder,tempX);
          ffvpFreeTempRegister(programBuilder,tempYOperand);
          ffvpFreeTempRegister(programBuilder,tempZOperand);
          return 0;
        }
        invModelviewRegs = (int *)(programBuilder + 0xc4);
        maskBaseX = &DAT_001e3520;
        maskBaseY = &DAT_001e3520;
        maskBaseZ = &DAT_001e3520;
LAB_00093754:
        loopIndex = 0;
        dstMask = (undefined4 *)(maskBaseX + -0x781c);
        invModelviewRegCursor = invModelviewRegs;
        do {
          invModelviewReg = *invModelviewRegCursor;
          loopIndex = loopIndex + 1;
          emit2Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
          (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                    (programBuilder,dstTempFile,tempXReg,dstMask,constFile,invModelviewReg,&DAT_001dbd74,&DAT_001fa5e8,emit2Src1File,(*(int *)(matrixSelectors + (loopIndex - 1) * 4) == 0 ? *(int *)(programBuilder + 4) : (*(int *)(matrixSelectors + (loopIndex - 1) * 4) == 1 ? *(int *)(programBuilder + 100) : 0)),&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                    (programBuilder,dstTempFile,tempYReg,dstMask,constFile,invModelviewReg + 1,&DAT_001dbd74,&DAT_001fa5e8,emit2Src1File,(*(int *)(matrixSelectors + (loopIndex - 1) * 4) == 0 ? *(int *)(programBuilder + 4) : (*(int *)(matrixSelectors + (loopIndex - 1) * 4) == 1 ? *(int *)(programBuilder + 100) : 0)),&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                    (programBuilder,dstTempFile,tempZReg,dstMask,constFile,invModelviewReg + 2,&DAT_001dbd74,&DAT_001fa5e8,emit2Src1File,(*(int *)(matrixSelectors + (loopIndex - 1) * 4) == 0 ? *(int *)(programBuilder + 4) : (*(int *)(matrixSelectors + (loopIndex - 1) * 4) == 1 ? *(int *)(programBuilder + 100) : 0)),&DAT_001dbd74,&DAT_001fa5e8);
          if (matrixCount <= loopIndex) {
            fileTable = *(undefined4 **)(programBuilder + 0x3ec);
            goto LAB_0009388c;
          }
          if (loopIndex == 1) {
            dstMask = (undefined4 *)(maskBaseY + -0x77bc);
          }
          else {
            if (loopIndex == 0) goto LAB_00093754;
            if (loopIndex == 2) {
              dstMask = (undefined4 *)(maskBaseZ + -0x77cc);
            }
            else {
              dstMask = (undefined4 *)0x0;
              if (loopIndex == 3) {
                dstMask = &DAT_001dbd44;
              }
            }
          }
          invModelviewRegCursor = invModelviewRegCursor + 1;
        } while( true );
      }
    }
  }
  return 7;
}

/* ffvpPrepareRescaledNormal @ 0x939e0 (52 bytes) */
int ffvpPrepareRescaledNormal(programBuilder)
  int programBuilder;
{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (programBuilder != 0) {
    if ((*(int *)(programBuilder + 4) != -1) && (*(int *)(programBuilder + 0x344) != -1)) {
      uVar1 = ffvpEmitRescaledNormal(programBuilder);
      return uVar1;
    }
    uVar1 = 2;
  }
  return uVar1;
}

/* ffvpPrepareNormalizedNormal @ 0x93a20 (24 bytes) */
int ffvpPrepareNormalizedNormal(programBuilder)
  int programBuilder;
{
  undefined4 uVar1;
  
  if (*(int *)(programBuilder + 4) != -1) {
    uVar1 = ffvpEmitNormalizedNormal(programBuilder);
    return uVar1;
  }
  return 2;
}

/* ffvpEmitBlendedClipPosition @ 0x93a40 (3576 bytes) */
int ffvpEmitBlendedClipPosition(programBuilder, matrixSelectors, matrixCount, implicitLastWeight, writeToTemp, clipCopyIndex)
  int *programBuilder;
  int matrixSelectors;
  uint matrixCount;
  int implicitLastWeight;
  int writeToTemp;
  uint clipCopyIndex;
{
  uint matrixIndex;
  undefined4 srcTempFileB;
  undefined4 dstTempFileB;
  undefined4 copyDstFile;
  undefined4 constFile;
  undefined4 dstFile;
  undefined *maskConstPtr;
  undefined4 *tempRegCursor;
  undefined4 *dstFileTable;
  int *mvpRegCursor2;
  int *mvpRegCursor;
  int glCtx;
  int sourceInputRegB;
  int selectorB;
  int mvpReg;
  int dstReg;
  int allocStatus;
  int sourceInputReg;
  bool writeDirect;
  int selector;
  undefined4 *maskPtr;
  int checkIndex;
  undefined4 *srcFileTable;
  int *checkCursor;
  undefined4 srcTempFile;
  undefined4 dstTempFile;
  int copySrcReg;
  undefined *negateConstPtr;
  undefined *selectConstPtr;
  undefined *negateConstPtr2;
  undefined4 constFileB;
  undefined4 tempDstFile;
  uint remaining;
  uint uStack0000002c;
  undefined1 blendTemp1 [4];
  int blendTemp1Reg;
  undefined1 blendTemp0 [4];
  undefined4 blendTemp0Reg;
  undefined1 outTemp [4];
  int outTempReg;
  undefined1 blendTemp2 [4];
  undefined4 blendTemp2Reg;
  undefined1 blendTemp3 [4];
  undefined4 blendTemp3Reg [9];
  undefined1 blendTemp4 [4];
  undefined4 blendTemp4Reg;
  undefined1 blendTemp5 [4];
  undefined4 blendTemp5Reg;
  undefined1 blendTemp6 [4];
  undefined4 blendTemp6Reg;
  undefined *constBase88;
  undefined1 *blendTemp2Ptr;
  undefined *constBase80;
  undefined1 *blendTemp3Ptr;
  undefined1 *blendTemp4Ptr;
  undefined *constBase74;
  undefined1 *blendTemp5Ptr;
  undefined1 *blendTemp6Ptr;
  undefined1 *blendTemp0Ptr;
  undefined *constBase64;
  undefined *constBase60;
  undefined *constBase5c;
  undefined *constBase58;
  undefined *constBase54;
  int src1Index;
  int emit4Src1Index;
  int emit5Src1Index;
  int src1File;
  int deadSrc1File;
  int deadEmitFn12ec;
  int iVarS7;
  int deadEmitFn12f4;
  int deadEmitFn12f4B;
  int iVarS10;
  int deadEmitFn12f4C;
  int emit17Src1Index;
  int emit17Src1Select;
  int src1FileB;
  int emit14Src1Select;
  int emit15Src1Select;
  int emit16Src1Select;
  int emit20Src1Index;
  int emit20Src1Select;
  int emit20Src2Index;
  int emit13Src1File;
  int emit13Src1Select;
  int src1IndexB;
  int emit18Src1Select;
  int emit19Src1Select;
  int emit21Src1Index;
  int emit21Src1Select;
  
  if (programBuilder == (int *)0x0) {
    return 1;
  }
  if (4 < matrixCount) {
    return 4;
  }
  if (matrixCount != 0) {
    checkIndex = 0;
    checkCursor = programBuilder;
    remaining = matrixCount;
    do {
      selector = *(int *)(matrixSelectors + checkIndex * 4);
      if (selector == 0) {
        sourceInputReg = *programBuilder;
      }
      else {
        if (selector != 1) {
          return 3;
        }
        sourceInputReg = programBuilder[0x18];
      }
      if (sourceInputReg == -1) {
        return 2;
      }
      if (checkCursor[0x29] == -1) {
        return 2;
      }
      checkIndex = checkIndex + 1;
      checkCursor = checkCursor + 1;
      remaining = remaining - 1;
    } while (remaining != 0);
  }
  if ((matrixCount < 4) && (implicitLastWeight != 0)) {
    selectorB = *(int *)(matrixSelectors + matrixCount * 4);
    if (selectorB == 0) {
      sourceInputRegB = *programBuilder;
    }
    else {
      if (selectorB != 1) {
        return 3;
      }
      sourceInputRegB = programBuilder[0x18];
    }
    if (sourceInputRegB == -1) {
      return 2;
    }
    if (programBuilder[matrixCount + 0x29] == -1) {
      return 2;
    }
  }
  if (programBuilder[0x1a] != -1) {
    writeDirect = writeToTemp == 0;
    if (!writeDirect) {
      if (7 < clipCopyIndex) {
        return 3;
      }
      if (programBuilder[clipCopyIndex + 0x21] == -1) {
        return 2;
      }
    }
    glCtx = programBuilder[0xf5];
    uStack0000002c = clipCopyIndex;
    if ((*(uint *)(((unsigned char *)0x000013c0) + glCtx) & 4) == 0) {
      if ((programBuilder[0x158] != -1) || (ffvpEmitBlendWeights(programBuilder,matrixCount,implicitLastWeight), programBuilder[0x158] != -1)) {
        if ((matrixCount < 4) && (implicitLastWeight != 0)) {
          matrixCount = matrixCount + 1;
        }
        blendTemp0Ptr = blendTemp0;
        allocStatus = ffvpAllocTempRegister(programBuilder,0,blendTemp0Ptr);
        if ((allocStatus == 0) && (allocStatus = ffvpAllocTempRegister(programBuilder,0,blendTemp1), allocStatus == 0)) {
          blendTemp2Ptr = blendTemp2;
          allocStatus = ffvpAllocTempRegister(programBuilder,0,blendTemp2Ptr);
          if (allocStatus == 0) {
            blendTemp3Ptr = blendTemp3;
            allocStatus = ffvpAllocTempRegister(programBuilder,0,blendTemp3Ptr);
            if (allocStatus == 0) {
              dstTempFile = *(undefined4 *)programBuilder[0xfc];
              srcTempFile = *(undefined4 *)programBuilder[0xfb];
              constFileB = ((undefined4 *)programBuilder[0xfb])[2];
              if (matrixCount == 0) {
LAB_000944c4:
                if (writeDirect) {
                  dstFile = *(undefined4 *)(programBuilder[0xfc] + 8);
                  dstReg = programBuilder[0x1a];
                }
                else {
                  allocStatus = ffvpAllocTempRegister(programBuilder,0,outTemp);
                  if (allocStatus != 0) {
                    return 7;
                  }
                  dstFile = *(undefined4 *)programBuilder[0xfc];
                  dstReg = outTempReg;
                }
                constBase88 = &DAT_001e3a54;
                constBase80 = &DAT_001f3a54;
                src1Index = *(int *)((int)programBuilder + 1376);
                (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                          (programBuilder,dstFile,dstReg,&DAT_001dbd04,srcTempFile,blendTemp0Reg,&DAT_001dbd14,
                           &DAT_001fa5e8,srcTempFile,src1Index,&DAT_001dbd14,&DAT_001fa5e8);
                (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                          (programBuilder,dstFile,dstReg,&DAT_001dbd64,srcTempFile,blendTemp1Reg,&DAT_001dbd14,
                           &DAT_001fa5e8,srcTempFile,src1Index,&DAT_001dbd14,&DAT_001fa5e8);
                (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                          (programBuilder,dstFile,dstReg,&DAT_001dbd54,srcTempFile,blendTemp2Reg,&DAT_001dbd14,
                           &DAT_001fa5e8,srcTempFile,src1Index,&DAT_001dbd14,&DAT_001fa5e8);
                if ((*(char *)(programBuilder + 0x1d1) == '\0') || (programBuilder[0x1a8] != -1)) {
                  emit4Src1Index = *(int *)((int)programBuilder + 1376);
                  (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                            (programBuilder,dstFile,dstReg,&DAT_001dbd44,srcTempFile,blendTemp3Reg[0],&DAT_001dbd14,
                             &DAT_001fa5e8,srcTempFile,emit4Src1Index,&DAT_001dbd14,&DAT_001fa5e8);
                  ffvpFreeTempRegister(programBuilder,blendTemp0Ptr);
                  ffvpFreeTempRegister(programBuilder,blendTemp1);
                  ffvpFreeTempRegister(programBuilder,blendTemp2Ptr);
                  ffvpFreeTempRegister(programBuilder,blendTemp3Ptr);
                }
                else {
                  emit5Src1Index = *(int *)((int)programBuilder + 1376);
                  (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                            (programBuilder,*(undefined4 *)programBuilder[0xfc],blendTemp0Reg,&DAT_001dbd44,srcTempFile,
                             blendTemp3Reg[0],&DAT_001dbd14,&DAT_001fa5e8,srcTempFile,emit5Src1Index,&DAT_001dbd14,&DAT_001fa5e8);
                  (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                            (programBuilder,dstFile,dstReg,&DAT_001dbd44,srcTempFile,blendTemp0Reg,&DAT_001dbcd4,
                             &DAT_001fa5e8);
                  ffvpEmitInverseW(programBuilder,srcTempFile,blendTemp0Reg);
                  ffvpFreeTempRegister(programBuilder,blendTemp0Ptr);
                  ffvpFreeTempRegister(programBuilder,blendTemp1);
                  ffvpFreeTempRegister(programBuilder,blendTemp2Ptr);
                  ffvpFreeTempRegister(programBuilder,blendTemp3Ptr);
                  if (programBuilder[0x1a8] == -1) {
                    ffvpFreeTempRegister(programBuilder,outTemp);
                    return 2;
                  }
                }
                if (!writeDirect) {
                  selectConstPtr = constBase88 + -0x7d40;
                  negateConstPtr = constBase80 + 0x6b94;
                  (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                            (programBuilder,*(undefined4 *)(programBuilder[0xfc] + 8),programBuilder[0x1a],&DAT_001dbd24,
                             srcTempFile,outTempReg,selectConstPtr,negateConstPtr);
                  (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                            (programBuilder,*(undefined4 *)(programBuilder[0xfc] + 0x14),
                             programBuilder[uStack0000002c + 0x21],&DAT_001dbd24,srcTempFile,outTempReg,selectConstPtr,
                             negateConstPtr);
                  ffvpFreeTempRegister(programBuilder,outTemp);
                }
                return 0;
              }
              constBase88 = &DAT_001e3a54;
              constBase80 = &DAT_001f3a54;
              constBase74 = &DAT_001e3a54;
LAB_00094348:
              matrixIndex = 0;
              maskPtr = (undefined4 *)(constBase74 + -0x7d50);
              mvpRegCursor = programBuilder + 0x29;
              do {
                mvpReg = *mvpRegCursor;
                matrixIndex = matrixIndex + 1;
                selectConstPtr = constBase88 + -0x7d40;
                negateConstPtr = constBase80 + 0x6b94;
                src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
                (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                          (programBuilder,dstTempFile,blendTemp0Reg,maskPtr,constFileB,mvpReg,selectConstPtr,negateConstPtr,src1File,glCtx,selectConstPtr,negateConstPtr);
                (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                          (programBuilder,dstTempFile,blendTemp1Reg,maskPtr,constFileB,mvpReg + 1,selectConstPtr,negateConstPtr,src1File,glCtx,selectConstPtr,negateConstPtr);
                (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                          (programBuilder,dstTempFile,blendTemp2Reg,maskPtr,constFileB,mvpReg + 2,selectConstPtr,negateConstPtr,src1File,glCtx,selectConstPtr,negateConstPtr);
                (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                          (programBuilder,dstTempFile,blendTemp3Reg[0],maskPtr,constFileB,mvpReg + 3,selectConstPtr,negateConstPtr,src1File,glCtx,selectConstPtr,negateConstPtr);
                if (matrixCount <= matrixIndex) goto LAB_000944c4;
                if (matrixIndex == 1) {
                  maskPtr = &DAT_001dbd64;
                }
                else {
                  if (matrixIndex == 0) goto LAB_00094348;
                  if (matrixIndex == 2) {
                    maskPtr = &DAT_001dbd54;
                  }
                  else {
                    maskPtr = (undefined4 *)0x0;
                    if (matrixIndex == 3) {
                      maskPtr = &DAT_001dbd44;
                    }
                  }
                }
                mvpRegCursor = mvpRegCursor + 1;
              } while( true );
            }
          }
        }
        return 7;
      }
    }
    else if ((programBuilder[0x158] != -1) || (ffvpEmitBlendWeights(programBuilder,matrixCount,implicitLastWeight), programBuilder[0x158] != -1)
            ) {
      if ((matrixCount < 4) && (implicitLastWeight != 0)) {
        matrixCount = matrixCount + 1;
      }
      blendTemp3Ptr = blendTemp3;
      allocStatus = ffvpAllocTempRegister(programBuilder,0,blendTemp3Ptr);
      if (allocStatus != 0) {
        return 7;
      }
      blendTemp4Ptr = blendTemp4;
      allocStatus = ffvpAllocTempRegister(programBuilder,0,blendTemp4Ptr);
      if (allocStatus != 0) {
        return 7;
      }
      blendTemp5Ptr = blendTemp5;
      allocStatus = ffvpAllocTempRegister(programBuilder,0,blendTemp5Ptr);
      if (allocStatus != 0) {
        return 7;
      }
      blendTemp6Ptr = blendTemp6;
      allocStatus = ffvpAllocTempRegister(programBuilder,0,blendTemp6Ptr);
      if (allocStatus != 0) {
        return 7;
      }
      allocStatus = ffvpAllocTempRegister(programBuilder,0,blendTemp1);
      if (allocStatus != 0) {
        return 7;
      }
      srcFileTable = (undefined4 *)programBuilder[0xfb];
      dstFileTable = (undefined4 *)programBuilder[0xfc];
      srcTempFile = *srcFileTable;
      dstTempFileB = *dstFileTable;
      constFile = srcFileTable[2];
      if (matrixCount == 0) {
        constBase54 = &DAT_001e3a54;
        constBase88 = &DAT_001e3a54;
        constBase80 = &DAT_001f3a54;
        constBase64 = &DAT_001e3a54;
        constBase58 = &DAT_001e3a54;
        constBase5c = &DAT_001e3a54;
        constBase60 = &DAT_001f3a54;
      }
      else {
        constBase54 = &DAT_001e3a54;
        constBase88 = &DAT_001e3a54;
        constBase80 = &DAT_001f3a54;
        constBase64 = &DAT_001e3a54;
        constBase5c = &DAT_001e3a54;
        constBase58 = &DAT_001e3a54;
        matrixIndex = 0;
        constBase60 = &DAT_001f3a54;
        tempRegCursor = blendTemp3Reg;
        mvpRegCursor2 = programBuilder;
        do {
          mvpReg = mvpRegCursor2[0x29];
          tempDstFile = *tempRegCursor;
          matrixIndex = matrixIndex + 1;
          mvpRegCursor2 = mvpRegCursor2 + 1;
          tempRegCursor = tempRegCursor + 10;
          deadSrc1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
          deadEmitFn12ec = *(int *)((int)*(int *)((int)programBuilder + 980) + 4844);
          emit13Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
          emit13Src1Select = (int)constBase64 + -32128;
          (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                    (programBuilder,dstTempFileB,tempDstFile,&DAT_001dbd24,constFile,mvpReg + 3,&DAT_001dbd14,&DAT_001fa5e8,emit13Src1File,glCtx,emit13Src1Select,&DAT_001fa5e8);
          src1FileB = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
          emit14Src1Select = (int)constBase58 + -32096;
          (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                    (programBuilder,dstTempFileB,tempDstFile,&DAT_001dbd24,constFile,mvpReg + 2,&DAT_001dbd14,&DAT_001fa5e8
                    ,src1FileB,glCtx,emit14Src1Select,&DAT_001fa5e8,dstTempFileB,tempDstFile,&DAT_001dbd14,&DAT_001fa5e8);
          emit15Src1Select = (int)constBase5c + -32112;
          (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                    (programBuilder,dstTempFileB,tempDstFile,&DAT_001dbd24,constFile,mvpReg + 1,&DAT_001dbd14,&DAT_001fa5e8
                    ,src1FileB,glCtx,emit15Src1Select,&DAT_001fa5e8,dstTempFileB,tempDstFile,&DAT_001dbd14,&DAT_001fa5e8);
          emit16Src1Select = (int)constBase60 + 27556;
          (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                    (programBuilder,dstTempFileB,tempDstFile,&DAT_001dbd24,constFile,mvpReg,&DAT_001dbd14,&DAT_001fa5e8,src1FileB,glCtx,emit16Src1Select,&DAT_001fa5e8,dstTempFileB,tempDstFile,&DAT_001dbd14,&DAT_001fa5e8);
        } while (matrixCount != matrixIndex);
        dstFileTable = (undefined4 *)programBuilder[0xfc];
        srcFileTable = (undefined4 *)programBuilder[0xfb];
      }
      dstReg = blendTemp1Reg;
      if (writeDirect) {
        copyDstFile = dstFileTable[2];
        copySrcReg = programBuilder[0x1a];
      }
      else {
        copyDstFile = *dstFileTable;
        copySrcReg = blendTemp1Reg;
      }
      srcTempFileB = *srcFileTable;
      negateConstPtr2 = constBase80 + 0x6b94;
      selectConstPtr = constBase88 + -0x7d40;
      negateConstPtr = constBase54 + -0x7d30;
      emit17Src1Index = *(int *)((int)programBuilder + 1376);
      emit17Src1Select = (int)constBase64 + -32128;
      (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                (programBuilder,srcTempFileB,blendTemp1Reg,negateConstPtr,srcTempFile,blendTemp6Reg,selectConstPtr,negateConstPtr2,srcTempFileB,emit17Src1Index,emit17Src1Select,negateConstPtr2);
      iVarS7 = *(int *)((int)programBuilder + 1376);
      deadEmitFn12f4 = *(int *)((int)*(int *)((int)programBuilder + 980) + 4852);
      src1IndexB = *(int *)((int)programBuilder + 1376);
      emit18Src1Select = (int)constBase58 + -32096;
      (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                (programBuilder,srcTempFileB,dstReg,negateConstPtr,srcTempFile,blendTemp5Reg,selectConstPtr,negateConstPtr2,srcTempFileB,src1IndexB,emit18Src1Select,negateConstPtr2,srcTempFileB,dstReg,selectConstPtr,negateConstPtr2);
      deadEmitFn12f4B = *(int *)((int)*(int *)((int)programBuilder + 980) + 4852);
      emit19Src1Select = (int)constBase5c + -32112;
      (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                (programBuilder,srcTempFileB,dstReg,negateConstPtr,srcTempFile,blendTemp4Reg,selectConstPtr,negateConstPtr2,srcTempFileB,src1IndexB,emit19Src1Select,negateConstPtr2,srcTempFileB,dstReg,selectConstPtr,negateConstPtr2);
      if ((*(char *)(programBuilder + 0x1d1) == '\0') || (programBuilder[0x1a8] != -1)) {
        emit20Src1Index = *(int *)((int)programBuilder + 1376);
        emit20Src1Select = (int)constBase60 + 27556;
        emit20Src2Index = blendTemp1Reg;
        (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                  (programBuilder,copyDstFile,copySrcReg,negateConstPtr,srcTempFile,blendTemp3Reg[0],selectConstPtr,negateConstPtr2,srcTempFile,emit20Src1Index,emit20Src1Select,negateConstPtr2,srcTempFile,emit20Src2Index,selectConstPtr,negateConstPtr2);
      }
      else {
        iVarS10 = *(int *)((int)programBuilder + 1376);
        deadEmitFn12f4C = *(int *)((int)*(int *)((int)programBuilder + 980) + 4852);
        emit21Src1Index = *(int *)((int)programBuilder + 1376);
        emit21Src1Select = (int)constBase60 + 27556;
        (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                  (programBuilder,srcTempFileB,dstReg,negateConstPtr,srcTempFile,blendTemp3Reg[0],selectConstPtr,negateConstPtr2,srcTempFileB,emit21Src1Index,emit21Src1Select,negateConstPtr2,srcTempFileB,dstReg,selectConstPtr,negateConstPtr2);
        if (writeDirect) {
          (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                    (programBuilder,*(undefined4 *)(programBuilder[0xfc] + 8),programBuilder[0x1a],negateConstPtr,srcTempFile,
                     blendTemp1Reg,selectConstPtr,negateConstPtr2);
        }
        ffvpEmitInverseW(programBuilder,srcTempFile,blendTemp1Reg);
        if (programBuilder[0x1a8] == -1) {
          ffvpFreeTempRegister(programBuilder,blendTemp3Ptr);
          ffvpFreeTempRegister(programBuilder,blendTemp4Ptr);
          ffvpFreeTempRegister(programBuilder,blendTemp5Ptr);
          ffvpFreeTempRegister(programBuilder,blendTemp6Ptr);
          ffvpFreeTempRegister(programBuilder,blendTemp1);
          return 2;
        }
      }
      if (!writeDirect) {
        maskConstPtr = constBase54 + -0x7d30;
        selectConstPtr = constBase88 + -0x7d40;
        negateConstPtr = constBase80 + 0x6b94;
        (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                  (programBuilder,*(undefined4 *)(programBuilder[0xfc] + 8),programBuilder[0x1a],maskConstPtr,srcTempFile,blendTemp1Reg,
                   selectConstPtr,negateConstPtr);
        (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                  (programBuilder,*(undefined4 *)(programBuilder[0xfc] + 0x14),programBuilder[uStack0000002c + 0x21],
                   maskConstPtr,srcTempFile,blendTemp1Reg,selectConstPtr,negateConstPtr);
      }
      ffvpFreeTempRegister(programBuilder,blendTemp3Ptr);
      ffvpFreeTempRegister(programBuilder,blendTemp4Ptr);
      ffvpFreeTempRegister(programBuilder,blendTemp5Ptr);
      ffvpFreeTempRegister(programBuilder,blendTemp6Ptr);
      ffvpFreeTempRegister(programBuilder,blendTemp1);
      return 0;
    }
  }
  return 2;
}

/* ffvpEmitBlendedEyePosition @ 0x94840 (3400 bytes) */
int ffvpEmitBlendedEyePosition(programBuilder, matrixSelectors, matrixCount, implicitLastWeight, twoMatrixBlend)
  int *programBuilder;
  int matrixSelectors;
  uint matrixCount;
  int implicitLastWeight;
  int twoMatrixBlend;
{
  uint matrixIndex;
  undefined4 dstTempFileB;
  undefined4 srcTempFileB;
  undefined4 srcTempFile;
  undefined4 *tempReg3Cursor;
  int eyePositionRegB;
  int modelviewRegB;
  int glCtx;
  int sourceInputRegB;
  int selectorB;
  int allocStatus;
  int eyePositionReg;
  int modelviewReg;
  int blendWeightsReg;
  int sourceInputReg;
  int selector;
  int checkIndex;
  int allocStatusB;
  int *modelviewRegCursor;
  undefined4 dstTempFile;
  undefined4 constFile;
  code *selectConstPtr;
  undefined4 *fileTable;
  code *selectConstPtr2;
  undefined4 tempRegSel;
  undefined4 tempRegCursorValue;
  undefined **negateConstPtr;
  uint remaining;
  undefined1 blendTemp0 [4];
  undefined4 blendTemp0Reg;
  undefined1 blendTemp1 [4];
  undefined4 blendTemp1Reg;
  undefined1 blendTemp2 [4];
  undefined4 blendTemp2Reg;
  undefined1 blendTemp3 [4];
  undefined4 blendTemp3Reg [9];
  undefined1 blendTemp4 [4];
  undefined4 blendTemp4Reg;
  undefined1 blendTemp5 [4];
  undefined4 blendTemp5Reg;
  undefined1 blendTemp6 [4];
  undefined4 blendTemp6Reg;
  undefined1 *blendTemp3Ptr;
  undefined1 *blendTemp4Ptr;
  undefined1 *blendTemp5Ptr;
  undefined **constBase8c;
  code *constBase88;
  undefined1 *blendTemp6Ptr;
  code *constBase80;
  undefined **constBase7c;
  code *constBase78;
  code *constBase74;
  code *constBase70;
  code *constBase6c;
  code *constBase68;
  code *constBase64;
  undefined1 *blendTemp2Ptr;
  code *constBase5c;
  int src1File;
  int src1FileB;
  int src1Index;
  int emit5Src1Index;
  int emit5Src1Select;
  int emit15Src1File;
  int emit15Src1Select;
  int emit19Src1Index;
  int emit19Src1Select;
  int emit6Src1Index;
  int selectConstArg;
  int src1FileC;
  int emit16Src1Select;
  int emit17Src1Select;
  int emit18Src1Select;
  int src1IndexB;
  int emit20Src1Select;
  int emit21Src1Select;
  int emit22Src1Select;
  
  if (programBuilder == (int *)0x0) {
    return 1;
  }
  if (4 < matrixCount) {
    return 4;
  }
  if (matrixCount != 0) {
    checkIndex = 0;
    modelviewRegCursor = programBuilder;
    remaining = matrixCount;
    do {
      selector = *(int *)(matrixSelectors + checkIndex * 4);
      if (selector == 0) {
        sourceInputReg = *programBuilder;
      }
      else {
        if (selector != 1) {
          return 3;
        }
        sourceInputReg = programBuilder[0x18];
      }
      if (sourceInputReg == -1) {
        return 2;
      }
      if (modelviewRegCursor[0x2d] == -1) {
        return 2;
      }
      checkIndex = checkIndex + 1;
      modelviewRegCursor = modelviewRegCursor + 1;
      remaining = remaining - 1;
    } while (remaining != 0);
  }
  if ((matrixCount < 4) && (implicitLastWeight != 0)) {
    selectorB = *(int *)(matrixSelectors + matrixCount * 4);
    if (selectorB == 0) {
      sourceInputRegB = *programBuilder;
    }
    else {
      if (selectorB != 1) {
        return 3;
      }
      sourceInputRegB = programBuilder[0x18];
    }
    if (sourceInputRegB == -1) {
      return 2;
    }
    if (programBuilder[matrixCount + 0x2d] == -1) {
      return 2;
    }
  }
  glCtx = programBuilder[0xf5];
  if ((*(uint *)(((unsigned char *)0x000013c0) + glCtx) & 4) == 0) {
    if (programBuilder[0xfe] != -1) {
      return 0;
    }
    blendWeightsReg = programBuilder[0x158];
    if (blendWeightsReg == -1) {
      ffvpEmitBlendWeights(programBuilder,matrixCount,implicitLastWeight);
      blendWeightsReg = programBuilder[0x158];
      if (blendWeightsReg == -1) {
        return 2;
      }
    }
    if ((matrixCount < 4) && (implicitLastWeight != 0)) {
      matrixCount = matrixCount + 1;
    }
    allocStatusB = ffvpAllocTempRegister(programBuilder,0,programBuilder + 0xfd);
    if ((allocStatusB == 0) && (allocStatusB = ffvpAllocTempRegister(programBuilder,0,blendTemp0), allocStatusB == 0)) {
      allocStatusB = ffvpAllocTempRegister(programBuilder,0,blendTemp1);
      if (allocStatusB == 0) {
        blendTemp2Ptr = blendTemp2;
        allocStatusB = ffvpAllocTempRegister(programBuilder,0,blendTemp2Ptr);
        if (allocStatusB == 0) {
          blendTemp3Ptr = blendTemp3;
          allocStatusB = ffvpAllocTempRegister(programBuilder,0,blendTemp3Ptr);
          if (allocStatusB == 0) {
            fileTable = (undefined4 *)programBuilder[0xfb];
            constFile = fileTable[2];
            dstTempFile = *(undefined4 *)programBuilder[0xfc];
            if ((matrixCount < 3) && (twoMatrixBlend != 0)) {
              if (matrixCount != 0) {
                constBase88 = IrFetchTextureMapBias__dtor;
                constBase8c = &PTR_DAT_001f4850;
                constBase6c = IrFetchTextureMapBias__dtor;
                constBase68 = IrFetchTextureMapBias__dtor;
                constBase64 = IrFetchTextureMapBias__dtor;
                constBase70 = IrFetchTextureMapBias__dtor;
                do {
                  matrixIndex = 0;
                  tempRegSel = blendTemp0Reg;
                  modelviewRegCursor = programBuilder + 0x2d;
                  while( true ) {
                    modelviewRegB = *modelviewRegCursor;
                    matrixIndex = matrixIndex + 1;
                    selectConstPtr = constBase88 + 0x74c4;
                    negateConstPtr = constBase8c + 0x1766;
                    src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
                    (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                              (programBuilder,dstTempFile,tempRegSel,constBase6c + 0x74b4,constFile,modelviewRegB,selectConstPtr,negateConstPtr,src1File,glCtx,selectConstPtr,negateConstPtr);
                    (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                              (programBuilder,dstTempFile,tempRegSel,constBase68 + 0x7514,constFile,modelviewRegB + 1,selectConstPtr,
                               negateConstPtr,src1File,glCtx,selectConstPtr,negateConstPtr);
                    (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                              (programBuilder,dstTempFile,tempRegSel,constBase64 + 0x7504,constFile,modelviewRegB + 2,selectConstPtr,
                               negateConstPtr,src1File,glCtx,selectConstPtr,negateConstPtr);
                    (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                              (programBuilder,dstTempFile,tempRegSel,constBase70 + 0x74f4,constFile,modelviewRegB + 3,selectConstPtr,
                               negateConstPtr,src1File,glCtx,selectConstPtr,negateConstPtr);
                    if (matrixCount <= matrixIndex) {
                      fileTable = (undefined4 *)programBuilder[0xfb];
                      goto LAB_0009510c;
                    }
                    if (matrixIndex == 0) break;
                    tempRegSel = 0;
                    if (matrixIndex == 1) {
                      tempRegSel = blendTemp1Reg;
                    }
                    modelviewRegCursor = modelviewRegCursor + 1;
                  }
                } while( true );
              }
              constBase88 = IrFetchTextureMapBias__dtor;
              constBase8c = &PTR_DAT_001f4850;
LAB_0009510c:
              srcTempFileB = *fileTable;
              eyePositionRegB = programBuilder[0xfe];
              negateConstPtr = constBase8c + 0x1766;
              emit5Src1Index = blendTemp0Reg;
              emit5Src1Select = (int)constBase88 + 29892;
              (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                        (programBuilder,dstTempFile,eyePositionRegB,&DAT_001dbd24,srcTempFileB,blendWeightsReg,&DAT_001fa5f8,negateConstPtr,srcTempFileB,emit5Src1Index,emit5Src1Select,negateConstPtr);
              emit6Src1Index = blendTemp1Reg;
              selectConstArg = (int)constBase88 + 29892;
              (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                        (programBuilder,dstTempFile,eyePositionRegB,&DAT_001dbd24,srcTempFileB,blendWeightsReg,&DAT_001dbce4,negateConstPtr,srcTempFileB,emit6Src1Index,selectConstArg,negateConstPtr,srcTempFileB,eyePositionRegB,selectConstArg,negateConstPtr);
            }
            else {
              if (matrixCount != 0) {
                constBase88 = IrFetchTextureMapBias__dtor;
                constBase8c = &PTR_DAT_001f4850;
                constBase6c = IrFetchTextureMapBias__dtor;
                constBase68 = IrFetchTextureMapBias__dtor;
                constBase64 = IrFetchTextureMapBias__dtor;
                constBase70 = IrFetchTextureMapBias__dtor;
LAB_00095234:
                matrixIndex = 0;
                selectConstPtr = constBase6c + 0x74b4;
                modelviewRegCursor = programBuilder + 0x2d;
                do {
                  modelviewReg = *modelviewRegCursor;
                  matrixIndex = matrixIndex + 1;
                  selectConstPtr2 = constBase88 + 0x74c4;
                  negateConstPtr = constBase8c + 0x1766;
                  src1FileB = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
                  (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                            (programBuilder,dstTempFile,blendTemp0Reg,selectConstPtr,constFile,modelviewReg,selectConstPtr2,negateConstPtr,src1FileB,glCtx,selectConstPtr2,negateConstPtr);
                  (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                            (programBuilder,dstTempFile,blendTemp1Reg,selectConstPtr,constFile,modelviewReg + 1,selectConstPtr2,negateConstPtr,src1FileB,glCtx,selectConstPtr2,negateConstPtr);
                  (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                            (programBuilder,dstTempFile,blendTemp2Reg,selectConstPtr,constFile,modelviewReg + 2,selectConstPtr2,negateConstPtr,src1FileB,glCtx,selectConstPtr2,negateConstPtr);
                  (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                            (programBuilder,dstTempFile,blendTemp3Reg[0],selectConstPtr,constFile,modelviewReg + 3,selectConstPtr2,negateConstPtr,src1FileB,glCtx,selectConstPtr2,negateConstPtr);
                  if (matrixCount <= matrixIndex) {
                    fileTable = (undefined4 *)programBuilder[0xfb];
                    goto LAB_000953b4;
                  }
                  if (matrixIndex == 1) {
                    selectConstPtr = constBase68 + 0x7514;
                  }
                  else {
                    if (matrixIndex == 0) goto LAB_00095234;
                    if (matrixIndex == 2) {
                      selectConstPtr = constBase64 + 0x7504;
                    }
                    else {
                      selectConstPtr = (code *)0x0;
                      if (matrixIndex == 3) {
                        selectConstPtr = constBase70 + 0x74f4;
                      }
                    }
                  }
                  modelviewRegCursor = modelviewRegCursor + 1;
                } while( true );
              }
              constBase88 = IrFetchTextureMapBias__dtor;
              constBase8c = &PTR_DAT_001f4850;
              constBase6c = IrFetchTextureMapBias__dtor;
              constBase68 = IrFetchTextureMapBias__dtor;
              constBase64 = IrFetchTextureMapBias__dtor;
              constBase70 = IrFetchTextureMapBias__dtor;
LAB_000953b4:
              srcTempFileB = *fileTable;
              eyePositionReg = programBuilder[0xfe];
              selectConstPtr = constBase88 + 0x74c4;
              negateConstPtr = constBase8c + 0x1766;
              src1Index = *(int *)((int)programBuilder + 1376);
              (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                        (programBuilder,dstTempFile,eyePositionReg,constBase6c + 0x74b4,srcTempFileB,blendTemp0Reg,selectConstPtr,negateConstPtr,srcTempFileB,src1Index,selectConstPtr,negateConstPtr);
              (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                        (programBuilder,dstTempFile,eyePositionReg,constBase68 + 0x7514,srcTempFileB,blendTemp1Reg,selectConstPtr,negateConstPtr,srcTempFileB,src1Index,selectConstPtr,negateConstPtr);
              (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                        (programBuilder,dstTempFile,eyePositionReg,constBase64 + 0x7504,srcTempFileB,blendTemp2Reg,selectConstPtr,negateConstPtr,srcTempFileB,src1Index,selectConstPtr,negateConstPtr);
              (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                        (programBuilder,dstTempFile,eyePositionReg,constBase70 + 0x74f4,srcTempFileB,blendTemp3Reg[0],selectConstPtr,negateConstPtr,srcTempFileB,src1Index,selectConstPtr,negateConstPtr);
            }
            ffvpFreeTempRegister(programBuilder,blendTemp0);
            ffvpFreeTempRegister(programBuilder,blendTemp1);
            ffvpFreeTempRegister(programBuilder,blendTemp2Ptr);
            ffvpFreeTempRegister(programBuilder,blendTemp3Ptr);
            return 0;
          }
        }
      }
    }
  }
  else {
    if (programBuilder[0xfe] != -1) {
      return 0;
    }
    if ((programBuilder[0x158] == -1) && (ffvpEmitBlendWeights(programBuilder,matrixCount,implicitLastWeight), programBuilder[0x158] == -1)) {
      return 2;
    }
    if ((matrixCount < 4) && (implicitLastWeight != 0)) {
      matrixCount = matrixCount + 1;
    }
    allocStatus = ffvpAllocTempRegister(programBuilder,0,programBuilder + 0xfd);
    if (allocStatus == 0) {
      blendTemp3Ptr = blendTemp3;
      allocStatus = ffvpAllocTempRegister(programBuilder,0,blendTemp3Ptr);
      if (allocStatus == 0) {
        blendTemp4Ptr = blendTemp4;
        allocStatus = ffvpAllocTempRegister(programBuilder,0,blendTemp4Ptr);
        if (allocStatus == 0) {
          blendTemp5Ptr = blendTemp5;
          allocStatus = ffvpAllocTempRegister(programBuilder,0,blendTemp5Ptr);
          if (allocStatus == 0) {
            blendTemp6Ptr = blendTemp6;
            allocStatus = ffvpAllocTempRegister(programBuilder,0,blendTemp6Ptr);
            if (allocStatus == 0) {
              fileTable = (undefined4 *)programBuilder[0xfb];
              srcTempFile = *fileTable;
              dstTempFileB = *(undefined4 *)programBuilder[0xfc];
              constFile = fileTable[2];
              if (matrixCount == 0) {
                constBase5c = IrFetchTextureMapBias__dtor;
                constBase88 = IrFetchTextureMapBias__dtor;
                constBase8c = &PTR_DAT_001f4850;
                constBase80 = IrFetchTextureMapBias__dtor;
                constBase74 = IrFetchTextureMapBias__dtor;
                constBase78 = IrFetchTextureMapBias__dtor;
                constBase7c = &PTR_DAT_001f4850;
              }
              else {
                constBase5c = IrFetchTextureMapBias__dtor;
                constBase88 = IrFetchTextureMapBias__dtor;
                constBase8c = &PTR_DAT_001f4850;
                constBase80 = IrFetchTextureMapBias__dtor;
                constBase78 = IrFetchTextureMapBias__dtor;
                constBase74 = IrFetchTextureMapBias__dtor;
                matrixIndex = 0;
                constBase7c = &PTR_DAT_001f4850;
                tempReg3Cursor = blendTemp3Reg;
                modelviewRegCursor = programBuilder;
                do {
                  modelviewReg = modelviewRegCursor[0x2d];
                  tempRegCursorValue = *tempReg3Cursor;
                  matrixIndex = matrixIndex + 1;
                  modelviewRegCursor = modelviewRegCursor + 1;
                  tempReg3Cursor = tempReg3Cursor + 10;
                  emit15Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
                  emit15Src1Select = (int)constBase80 + 29828;
                  (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                            (programBuilder,dstTempFileB,tempRegCursorValue,&DAT_001dbd24,constFile,modelviewReg + 3,&DAT_001dbd14,
                             &DAT_001fa5e8,emit15Src1File,glCtx,emit15Src1Select,&DAT_001fa5e8);
                  src1FileC = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
                  emit16Src1Select = (int)constBase74 + 29860;
                  (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                            (programBuilder,dstTempFileB,tempRegCursorValue,&DAT_001dbd24,constFile,modelviewReg + 2,&DAT_001dbd14,
                             &DAT_001fa5e8,src1FileC,glCtx,emit16Src1Select,&DAT_001fa5e8,dstTempFileB,tempRegCursorValue,&DAT_001dbd14,&DAT_001fa5e8);
                  emit17Src1Select = (int)constBase78 + 29844;
                  (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                            (programBuilder,dstTempFileB,tempRegCursorValue,&DAT_001dbd24,constFile,modelviewReg + 1,&DAT_001dbd14,
                             &DAT_001fa5e8,src1FileC,glCtx,emit17Src1Select,&DAT_001fa5e8,dstTempFileB,tempRegCursorValue,&DAT_001dbd14,&DAT_001fa5e8);
                  emit18Src1Select = (int)constBase7c + 23976;
                  (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                            (programBuilder,dstTempFileB,tempRegCursorValue,&DAT_001dbd24,constFile,modelviewReg,&DAT_001dbd14,
                             &DAT_001fa5e8,src1FileC,glCtx,emit18Src1Select,&DAT_001fa5e8,dstTempFileB,tempRegCursorValue,&DAT_001dbd14,&DAT_001fa5e8);
                } while (matrixCount != matrixIndex);
                fileTable = (undefined4 *)programBuilder[0xfb];
              }
              eyePositionReg = programBuilder[0xfe];
              srcTempFileB = *fileTable;
              negateConstPtr = constBase8c + 0x1766;
              selectConstPtr = constBase5c + 0x74d4;
              selectConstPtr2 = constBase88 + 0x74c4;
              emit19Src1Index = *(int *)((int)programBuilder + 1376);
              emit19Src1Select = (int)constBase80 + 29828;
              (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                        (programBuilder,srcTempFileB,eyePositionReg,selectConstPtr,srcTempFile,blendTemp6Reg,selectConstPtr2,negateConstPtr,srcTempFileB,emit19Src1Index,emit19Src1Select,negateConstPtr);
              src1IndexB = *(int *)((int)programBuilder + 1376);
              emit20Src1Select = (int)constBase74 + 29860;
              (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                        (programBuilder,srcTempFileB,eyePositionReg,selectConstPtr,srcTempFile,blendTemp5Reg,selectConstPtr2,negateConstPtr,srcTempFileB,src1IndexB,emit20Src1Select,negateConstPtr,srcTempFileB,eyePositionReg,selectConstPtr2,negateConstPtr);
              emit21Src1Select = (int)constBase78 + 29844;
              (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                        (programBuilder,srcTempFileB,eyePositionReg,selectConstPtr,srcTempFile,blendTemp4Reg,selectConstPtr2,negateConstPtr,srcTempFileB,src1IndexB,emit21Src1Select,negateConstPtr,srcTempFileB,eyePositionReg,selectConstPtr2,negateConstPtr);
              emit22Src1Select = (int)constBase7c + 23976;
              (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                        (programBuilder,srcTempFileB,eyePositionReg,selectConstPtr,srcTempFile,blendTemp3Reg[0],selectConstPtr2,negateConstPtr,srcTempFileB,src1IndexB,emit22Src1Select,negateConstPtr,srcTempFileB,eyePositionReg,selectConstPtr2,negateConstPtr);
              ffvpFreeTempRegister(programBuilder,blendTemp3Ptr);
              ffvpFreeTempRegister(programBuilder,blendTemp4Ptr);
              ffvpFreeTempRegister(programBuilder,blendTemp5Ptr);
              ffvpFreeTempRegister(programBuilder,blendTemp6Ptr);
              return 0;
            }
          }
        }
      }
    }
  }
  return 7;
}

/* ffvpEmitInverseEyeDistance_955a0 @ 0x955a0 (20 bytes) */
int ffvpEmitInverseEyeDistance_955a0(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 0) {
    return 1;
  }
  uVar1 = 0;
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x538) == -1) {
    iVar4 = *(int *)(param_1 + 0x510);
    if (iVar4 == -1) {
      ffvpEmitEyeDistanceSquared(param_1);
      iVar4 = *(int *)(param_1 + 0x510);
      if (iVar4 == -1) {
        return 2;
      }
    }
    iVar2 = ffvpAllocTempRegister(param_1,2,param_1 + 0x534);
    uVar1 = 7;
    if (iVar2 == 0) {
      (**(code **)(((unsigned char *)0x00001318) + iVar3))
                (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x538),
                 param_1 + 0x53c,**(undefined4 **)(param_1 + 0x3ec),iVar4,param_1 + 0x524,
                 &DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ffvpEmitEyeVector_955c0 @ 0x955c0 (20 bytes) */
int ffvpEmitEyeVector_955c0(param_1)
  int param_1;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == 0) {
    return 1;
  }
  iVar3 = *(int *)(param_1 + 0x3d4);
  if (*(int *)(param_1 + 0x420) != -1) {
    return 0;
  }
  iVar4 = *(int *)(param_1 + 0x538);
  if (iVar4 == -1) {
    ffvpEmitInverseEyeDistance(param_1);
    iVar4 = *(int *)(param_1 + 0x538);
    if (iVar4 != -1) goto LAB_0009226c;
LAB_00092320:
    uVar1 = 2;
  }
  else {
LAB_0009226c:
    if (*(int *)(param_1 + 0x3f8) == -1) {
      if ((*(uint *)(((unsigned char *)0x000013c0) + iVar3) & 4) == 0) {
        ffvpEmitEyePositionDp4(param_1);
      }
      else {
        ffvpEmitEyePositionMad(param_1);
      }
      if (*(int *)(param_1 + 0x3f8) == -1) goto LAB_00092320;
    }
    iVar2 = ffvpAllocTempRegister(param_1,1,param_1 + 0x41c);
    uVar1 = 7;
    if (iVar2 == 0) {
      (**(code **)(((unsigned char *)0x000012ec) + iVar3))
                (param_1,**(undefined4 **)(param_1 + 0x3f0),*(undefined4 *)(param_1 + 0x420),
                 &DAT_001dbd84,**(undefined4 **)(param_1 + 0x3ec),iVar4,param_1 + 0x54c,&DAT_001fa5e8,
                 **(undefined4 **)(param_1 + 0x3ec),*(int *)((int)param_1 + 1016),&DAT_001dbd74,&DAT_001fa5e8);
      uVar1 = 0;
    }
  }
  return uVar1;
}

/* ffvpPrepareBlendWeights @ 0x955e0 (40 bytes) */
int ffvpPrepareBlendWeights(programBuilder, weightCount, implicitLastWeight)
  int programBuilder;
  undefined4 weightCount;
  undefined4 implicitLastWeight;
{
  undefined4 uVar1;
  
  uVar1 = 1;
  if ((programBuilder != 0) && (uVar1 = 2, *(int *)(programBuilder + 0x5c) != -1)) {
    uVar1 = ffvpEmitBlendWeights(programBuilder,weightCount,implicitLastWeight);
    return uVar1;
  }
  return uVar1;
}

/* ffvpEmitProjectedPosition @ 0x95610 (1840 bytes) */
int ffvpEmitProjectedPosition(programBuilder, copyEnabled, copyOutIndex)
  int programBuilder;
  int copyEnabled;
  uint copyOutIndex;
{
  bool noCopy;
  int projectionConstReg;
  int allocStatus;
  undefined4 srcTempFile;
  undefined4 dstReg;
  undefined4 dstFile;
  int glCtx;
  undefined4 constFile;
  undefined4 dstTempFile;
  undefined4 constFile2;
  undefined1 projTemp [4];
  undefined4 projTempReg;
  undefined1 wTemp [4];
  undefined4 wTempReg;
  int src1File;
  int src1Index;
  int emit4Src1File;
  int emit4Src1Index;
  int emit5Src1File;
  int emit9Src1Index;
  int emit9Src1Select;
  int emit10Src1Index;
  int emit10Src1Select;
  int deadEmitFn12f4;
  int deadSrcTempFile;
  int iVarS12;
  int deadSelectConst;
  int deadSrcTempFileB;
  int deadEmitFn12f4B;
  int emit13Src1Index;
  int emit13Src1Select;
  int emit11Src1Index;
  int emit11Src1Select;
  int emit12Src1File;
  int emit12Src1Index;
  int emit12Src1Select;
  int emit12Src2File;
  int emit12Src2Index;
  
  if (programBuilder == 0) {
    return 1;
  }
  if ((*(int *)(programBuilder + 0x68) == -1) || (*(int *)(programBuilder + 0xd4) == -1)) {
LAB_00095d30:
    dstReg = 2;
  }
  else {
    noCopy = copyEnabled == 0;
    if (!noCopy) {
      if (7 < copyOutIndex) {
        return 3;
      }
      if (*(int *)(copyOutIndex * 4 + programBuilder + 0x84) == -1) goto LAB_00095d30;
    }
    glCtx = *(int *)(programBuilder + 0x3d4);
    if ((*(uint *)(((unsigned char *)0x000013c0) + glCtx) & 4) == 0) {
      if ((*(int *)(programBuilder + 0x3f8) == -1) &&
         (ffvpEmitEyePositionDp4(programBuilder), *(int *)(programBuilder + 0x3f8) == -1)) goto LAB_00095d30;
      if (noCopy) {
        dstFile = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 8);
        dstReg = *(undefined4 *)(programBuilder + 0x68);
      }
      else {
        projectionConstReg = ffvpAllocTempRegister(programBuilder,0,projTemp);
        if (projectionConstReg != 0) {
          return 7;
        }
        dstFile = **(undefined4 **)(programBuilder + 0x3f0);
        dstReg = projTempReg;
      }
      projectionConstReg = *(int *)(programBuilder + 0xd4);
      srcTempFile = **(undefined4 **)(programBuilder + 0x3ec);
      constFile = (*(undefined4 **)(programBuilder + 0x3ec))[2];
      src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
      src1Index = *(int *)((int)programBuilder + 1016);
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                (programBuilder,dstFile,dstReg,&DAT_001dbd04,constFile,projectionConstReg,&DAT_001dbd14,&DAT_001fa5e8,src1File,src1Index,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                (programBuilder,dstFile,dstReg,&DAT_001dbd64,constFile,projectionConstReg + 1,&DAT_001dbd14,&DAT_001fa5e8,src1File,src1Index,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                (programBuilder,dstFile,dstReg,&DAT_001dbd54,constFile,projectionConstReg + 2,&DAT_001dbd14,&DAT_001fa5e8,src1File,src1Index,&DAT_001dbd14,&DAT_001fa5e8);
      if ((*(char *)(programBuilder + 0x744) == '\0') || (*(int *)(programBuilder + 0x6a0) != -1)) {
        emit4Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
        emit4Src1Index = *(int *)((int)programBuilder + 1016);
        (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                  (programBuilder,dstFile,dstReg,&DAT_001dbd44,constFile,projectionConstReg + 3,&DAT_001dbd14,&DAT_001fa5e8,emit4Src1File,emit4Src1Index,&DAT_001dbd14,&DAT_001fa5e8);
      }
      else {
        dstTempFile = **(undefined4 **)(programBuilder + 0x3f0);
        allocStatus = ffvpAllocTempRegister(programBuilder,0,wTemp);
        if (allocStatus != 0) {
          return 7;
        }
        emit5Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
        (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                  (programBuilder,dstTempFile,wTempReg,&DAT_001dbd44,constFile,projectionConstReg + 3,&DAT_001dbd14,&DAT_001fa5e8,emit5Src1File,src1Index,&DAT_001dbd14,&DAT_001fa5e8)
        ;
        (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                  (programBuilder,dstFile,dstReg,&DAT_001dbd44,srcTempFile,wTempReg,&DAT_001dbcd4,&DAT_001fa5e8);
        ffvpEmitInverseW(programBuilder,srcTempFile,wTempReg);
        ffvpFreeTempRegister(programBuilder,wTemp);
        if (*(int *)(programBuilder + 0x6a0) == -1) goto LAB_00095d30;
      }
      if (!noCopy) {
        dstReg = **(undefined4 **)(programBuilder + 0x3ec);
        (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                  (programBuilder,*(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 8),
                   *(undefined4 *)(programBuilder + 0x68),&DAT_001dbd24,dstReg,projTempReg,&DAT_001dbd14,
                   &DAT_001fa5e8);
        (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                  (programBuilder,*(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0x14),
                   *(undefined4 *)(copyOutIndex * 4 + programBuilder + 0x84),&DAT_001dbd24,dstReg,projTempReg,
                   &DAT_001dbd14,&DAT_001fa5e8);
        goto LAB_00095d10;
      }
    }
    else {
      dstReg = **(undefined4 **)(programBuilder + 0x3ec);
      if ((*(int *)(programBuilder + 0x3f8) == -1) &&
         (ffvpEmitEyePositionMad(programBuilder), *(int *)(programBuilder + 0x3f8) == -1)) goto LAB_00095d30;
      projectionConstReg = ffvpAllocTempRegister(programBuilder,0,projTemp);
      dstFile = projTempReg;
      if (projectionConstReg != 0) {
        return 7;
      }
      if (noCopy) {
        srcTempFile = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 8);
        constFile = *(undefined4 *)(programBuilder + 0x68);
      }
      else {
        srcTempFile = **(undefined4 **)(programBuilder + 0x3f0);
        constFile = projTempReg;
      }
      projectionConstReg = *(int *)(programBuilder + 0xd4);
      dstTempFile = **(undefined4 **)(programBuilder + 0x3ec);
      constFile2 = (*(undefined4 **)(programBuilder + 0x3ec))[2];
      emit9Src1Index = *(int *)((int)programBuilder + 1016);
      emit9Src1Select = &DAT_001dbcd4;
      (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                (programBuilder,dstTempFile,projTempReg,&DAT_001dbd24,constFile2,projectionConstReg + 3,&DAT_001dbd14,&DAT_001fa5e8,dstTempFile,emit9Src1Index,emit9Src1Select,&DAT_001fa5e8);
      emit10Src1Index = *(int *)((int)programBuilder + 1016);
      emit10Src1Select = &DAT_001dbcf4;
      (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                (programBuilder,dstTempFile,dstFile,&DAT_001dbd24,constFile2,projectionConstReg + 2,&DAT_001dbd14,&DAT_001fa5e8,dstTempFile,emit10Src1Index,emit10Src1Select,&DAT_001fa5e8,dstTempFile,dstFile,&DAT_001dbd14,&DAT_001fa5e8);
      deadEmitFn12f4 = *(int *)((int)*(int *)((int)programBuilder + 980) + 4852);
      emit11Src1Index = *(int *)((int)programBuilder + 1016);
      emit11Src1Select = &DAT_001dbce4;
      (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                (programBuilder,dstTempFile,dstFile,&DAT_001dbd24,constFile2,projectionConstReg + 1,&DAT_001dbd14,&DAT_001fa5e8,dstTempFile,emit11Src1Index,emit11Src1Select,&DAT_001fa5e8,dstTempFile,dstFile,&DAT_001dbd14,&DAT_001fa5e8);
      if ((*(char *)(programBuilder + 0x744) == '\0') || (*(int *)(programBuilder + 0x6a0) != -1)) {
        deadSrcTempFile = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
        iVarS12 = *(int *)((int)programBuilder + 1016);
        deadSelectConst = &DAT_001fa5f8;
        deadSrcTempFileB = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
        deadEmitFn12f4B = *(int *)((int)*(int *)((int)programBuilder + 980) + 4852);
        emit12Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
        emit12Src1Index = *(int *)((int)programBuilder + 1016);
        emit12Src1Select = &DAT_001fa5f8;
        emit12Src2File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
        emit12Src2Index = projTempReg;
        (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                  (programBuilder,srcTempFile,constFile,&DAT_001dbd24,constFile2,projectionConstReg,&DAT_001dbd14,&DAT_001fa5e8,emit12Src1File,emit12Src1Index,emit12Src1Select,&DAT_001fa5e8,emit12Src2File,emit12Src2Index,&DAT_001dbd14,&DAT_001fa5e8);
      }
      else {
        emit13Src1Index = *(int *)((int)programBuilder + 1016);
        emit13Src1Select = &DAT_001fa5f8;
        (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                  (programBuilder,**(undefined4 **)(programBuilder + 0x3ec),projTempReg,&DAT_001dbd24,constFile2,projectionConstReg,
                   &DAT_001dbd14,&DAT_001fa5e8,**(undefined4 **)(programBuilder + 0x3ec),emit13Src1Index,emit13Src1Select,&DAT_001fa5e8,**(undefined4 **)(programBuilder + 0x3ec),projTempReg,&DAT_001dbd14,&DAT_001fa5e8);
        if (noCopy) {
          (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                    (programBuilder,*(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 8),
                     *(undefined4 *)(programBuilder + 0x68),&DAT_001dbd24,dstReg,projTempReg,&DAT_001dbd14,
                     &DAT_001fa5e8);
        }
        ffvpEmitInverseW(programBuilder,dstReg,projTempReg);
        if (*(int *)(programBuilder + 0x6a0) == -1) {
          ffvpFreeTempRegister(programBuilder,projTemp);
          return 2;
        }
      }
      if (!noCopy) {
        dstReg = **(undefined4 **)(programBuilder + 0x3ec);
        (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                  (programBuilder,*(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 8),
                   *(undefined4 *)(programBuilder + 0x68),&DAT_001dbd24,dstReg,projTempReg,&DAT_001dbd14,
                   &DAT_001fa5e8);
        (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                  (programBuilder,*(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0x14),
                   *(undefined4 *)(copyOutIndex * 4 + programBuilder + 0x84),&DAT_001dbd24,dstReg,projTempReg,
                   &DAT_001dbd14,&DAT_001fa5e8);
      }
LAB_00095d10:
      ffvpFreeTempRegister(programBuilder,projTemp);
    }
    dstReg = 0;
  }
  return dstReg;
}

/* ffvpEmitEyePosition @ 0x95d70 (72 bytes) */
int ffvpEmitEyePosition(programBuilder)
  int *programBuilder;
{
  int src0IndexBase;
  undefined4 src0File;
  undefined4 status;
  int allocStatus;
  int glCtx;
  undefined4 dstFile;
  int tempRegIndex;
  
  status = 1;
  if (programBuilder != (int *)0x0) {
    if ((programBuilder[0x2d] != -1) && (*programBuilder != -1)) {
      if ((*(uint *)(((unsigned char *)0x000013c0) + programBuilder[0xf5]) & 4) != 0) {
        status = 0;
        glCtx = programBuilder[0xf5];
        if (programBuilder[0xfe] == -1) {
          allocStatus = ffvpAllocTempRegister(programBuilder,0,programBuilder + 0xfd);
          status = 7;
          if (allocStatus == 0) {
            dstFile = *(undefined4 *)programBuilder[0xfc];
            src0File = *(undefined4 *)(programBuilder[0xfb] + 8);
            tempRegIndex = programBuilder[0xfe];
            src0IndexBase = programBuilder[0x2d];
            (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                      (programBuilder,dstFile,tempRegIndex,&DAT_001dbd24,src0File,src0IndexBase + 3,&DAT_001dbd14,&DAT_001fa5e8,
                       ((int *)programBuilder[0xfb])[1],programBuilder[0],&DAT_001dbcd4,&DAT_001fa5e8);
            (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                      (programBuilder,dstFile,tempRegIndex,&DAT_001dbd24,src0File,src0IndexBase + 2,&DAT_001dbd14,&DAT_001fa5e8,
                       ((int *)programBuilder[0xfb])[1],programBuilder[0],&DAT_001dbcf4,&DAT_001fa5e8,dstFile,tempRegIndex,&DAT_001dbd14,&DAT_001fa5e8);
            (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                      (programBuilder,dstFile,tempRegIndex,&DAT_001dbd24,src0File,src0IndexBase + 1,&DAT_001dbd14,&DAT_001fa5e8,
                       ((int *)programBuilder[0xfb])[1],programBuilder[0],&DAT_001dbce4,&DAT_001fa5e8,dstFile,tempRegIndex,&DAT_001dbd14,&DAT_001fa5e8);
            (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                      (programBuilder,dstFile,tempRegIndex,&DAT_001dbd24,src0File,src0IndexBase,&DAT_001dbd14,&DAT_001fa5e8,
                       ((int *)programBuilder[0xfb])[1],programBuilder[0],&DAT_001fa5f8,&DAT_001fa5e8,dstFile,tempRegIndex,&DAT_001dbd14,&DAT_001fa5e8);
            status = 0;
          }
        }
        return status;
      }
      status = 0;
      glCtx = programBuilder[0xf5];
      if (programBuilder[0xfe] == -1) {
        allocStatus = ffvpAllocTempRegister(programBuilder,0,programBuilder + 0xfd);
        status = 7;
        if (allocStatus == 0) {
          src0File = *(undefined4 *)(programBuilder[0xfb] + 8);
          dstFile = *(undefined4 *)programBuilder[0xfc];
          tempRegIndex = programBuilder[0xfe];
          src0IndexBase = programBuilder[0x2d];
          (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                    (programBuilder,dstFile,tempRegIndex,&DAT_001dbd04,src0File,src0IndexBase,&DAT_001dbd14,&DAT_001fa5e8,((int *)programBuilder[0xfb])[1],programBuilder[0],&DAT_001dbd14,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                    (programBuilder,dstFile,tempRegIndex,&DAT_001dbd64,src0File,src0IndexBase + 1,&DAT_001dbd14,&DAT_001fa5e8,((int *)programBuilder[0xfb])[1],programBuilder[0],&DAT_001dbd14,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                    (programBuilder,dstFile,tempRegIndex,&DAT_001dbd54,src0File,src0IndexBase + 2,&DAT_001dbd14,&DAT_001fa5e8,((int *)programBuilder[0xfb])[1],programBuilder[0],&DAT_001dbd14,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                    (programBuilder,dstFile,tempRegIndex,&DAT_001dbd44,src0File,src0IndexBase + 3,&DAT_001dbd14,&DAT_001fa5e8,((int *)programBuilder[0xfb])[1],programBuilder[0],&DAT_001dbd14,&DAT_001fa5e8);
          status = 0;
        }
      }
      return status;
    }
    status = 2;
  }
  return status;
}

/* ffvpEmitClipPosition @ 0x95dd0 (1792 bytes) */
int ffvpEmitClipPosition(programBuilder, copyDisabled, clipCopyIndex)
  int *programBuilder;
  int copyDisabled;
  uint clipCopyIndex;
{
  undefined4 srcTempFileC;
  undefined4 constFileB;
  undefined4 srcTempFile;
  undefined4 outDstFile;
  int clipTempReg;
  int allocStatusC;
  int mvpConstRegCopy;
  int allocStatus;
  bool noClipCopy;
  int dstReg;
  undefined4 constFile;
  undefined4 dstFile;
  int glCtx;
  int allocStatusB;
  undefined4 srcTempFileB;
  int mvpConstReg;
  undefined4 dstTempFile;
  undefined1 clipTemp [4];
  int clipTempRegB;
  undefined1 wTemp [4];
  undefined4 wTempReg;
  int emit9Src1File;
  int emit9Src1Index;
  int emit9Src1Select;
  int emit10Src1File;
  int emit10Src1Index;
  int emit10Src1Select;
  int deadEmitFn12f4;
  int deadSrc1File;
  int deadInputReg;
  int deadSelectConst;
  int deadSrcTempFile;
  int deadEmitFn12f4B;
  int emit13Src1File;
  int emit13Src1Index;
  int emit13Src1Select;
  int emit4Src1File;
  int emit4Src1Index;
  int emit4Src1FileB;
  int emit4Src1IndexB;
  int emit5Src1File;
  int emit5Src1Index;
  int emit11Src1File;
  int emit11Src1Index;
  int emit11Src1Select;
  int emit12Src1File;
  int emit12Src1Index;
  int emit12Src1Select;
  int emit12Src2File;
  int emit12Src2Index;
  
  if (programBuilder == (int *)0x0) {
    return 1;
  }
  if (((programBuilder[0x1a] == -1) || (mvpConstReg = programBuilder[0x29], mvpConstReg == -1)) || (*programBuilder == -1)) {
    return 2;
  }
  noClipCopy = copyDisabled == 0;
  if (!noClipCopy) {
    if (7 < clipCopyIndex) {
      return 3;
    }
    if (programBuilder[clipCopyIndex + 0x21] == -1) {
      return 2;
    }
  }
  glCtx = programBuilder[0xf5];
  if ((*(uint *)(((unsigned char *)0x000013c0) + glCtx) & 4) == 0) {
    if (noClipCopy) {
      dstFile = *(undefined4 *)(programBuilder[0xfc] + 8);
      dstReg = programBuilder[0x1a];
    }
    else {
      allocStatusC = ffvpAllocTempRegister(programBuilder,0,clipTemp);
      if (allocStatusC != 0) {
        return 7;
      }
      mvpConstReg = programBuilder[0x29];
      dstFile = *(undefined4 *)programBuilder[0xfc];
      dstReg = clipTempRegB;
    }
    constFile = *(undefined4 *)(programBuilder[0xfb] + 8);
    /* issue #64 live-repro (crash #9, past the local_98-cluster fix): this indirect dispatch
     * (through the per-instance function-pointer table at 0x12e4+glCtx) reaches arbEmitRecord2Src_op01
     * on real hardware, whose real signature takes 12 parameters - but every call at this
     * shared call shape only supplies 8, matching the project's known dropped-call-args
     * defect class (Tools/userspace/indirect_args.py, detect_dropped_args.py). Since the call
     * is an untyped raw function-pointer invocation, the missing param_9-12 are simply never
     * pushed; arbEmitRecord2Src_op01 reads whatever stale stack memory happens to be there instead.
     * Live-verified on real hardware: it crashed dereferencing param_11 as a null pointer.
     * arbEmitRecord2Src_op01's own body applies the IDENTICAL bit-packing pattern to (param_5,param_6,
     * param_7,param_8) as it does to (param_9,param_10,param_11,param_12) - one group at
     * iVar15+4, the other at iVar15+8 - matching OpenGL's separate front/back stencil-state
     * encoding; when front and back use the same function (the common, non-"Separate" case
     * exercised here), both groups are the same values. Fixed by supplying constFile/mvpConstReg+N/
     * &DAT_001dbd14/&DAT_001fa5e8 again as param_9-12 at every call site reaching this same
     * dispatch slot in this function.
     * CORRECTION (#81, from the stock's outgoing stack stores at 0x96220-0x96234 etc.): the real
     * words are NOT copies of param_5-8 - param_9 is rec[1] (`*(programBuilder[0xfb] + 4)`), param_10 is
     * *programBuilder, and param_11/12 are the PIC constants - so the calls now pass those. */
    emit4Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
    emit4Src1Index = *(int *)((int)programBuilder + 0);
    (**(code **)(((unsigned char *)0x000012e4) + glCtx))
              (programBuilder,dstFile,dstReg,&DAT_001dbd04,constFile,mvpConstReg,&DAT_001dbd14,&DAT_001fa5e8,emit4Src1File,emit4Src1Index,&DAT_001dbd14,&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e4) + glCtx))
              (programBuilder,dstFile,dstReg,&DAT_001dbd64,constFile,mvpConstReg + 1,&DAT_001dbd14,&DAT_001fa5e8,emit4Src1File,emit4Src1Index,&DAT_001dbd14,&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e4) + glCtx))
              (programBuilder,dstFile,dstReg,&DAT_001dbd54,constFile,mvpConstReg + 2,&DAT_001dbd14,&DAT_001fa5e8,emit4Src1File,emit4Src1Index,&DAT_001dbd14,&DAT_001fa5e8);
    if ((*(char *)(programBuilder + 0x1d1) == '\0') || (programBuilder[0x1a8] != -1)) {
      emit4Src1FileB = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
      emit4Src1IndexB = *(int *)((int)programBuilder + 0);
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                (programBuilder,dstFile,dstReg,&DAT_001dbd44,constFile,mvpConstReg + 3,&DAT_001dbd14,&DAT_001fa5e8,emit4Src1FileB,emit4Src1IndexB,&DAT_001dbd14,&DAT_001fa5e8);
    }
    else {
      dstTempFile = *(undefined4 *)programBuilder[0xfc];
      srcTempFileB = *(undefined4 *)programBuilder[0xfb];
      allocStatusB = ffvpAllocTempRegister(programBuilder,0,wTemp);
      if (allocStatusB != 0) {
        return 7;
      }
      emit5Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
      emit5Src1Index = *(int *)((int)programBuilder + 0);
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                (programBuilder,dstTempFile,wTempReg,&DAT_001dbd44,constFile,mvpConstReg + 3,&DAT_001dbd14,&DAT_001fa5e8,emit5Src1File,emit5Src1Index,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                (programBuilder,dstFile,dstReg,&DAT_001dbd44,srcTempFileB,wTempReg,&DAT_001dbcd4,&DAT_001fa5e8);
      ffvpEmitInverseW(programBuilder,srcTempFileB,wTempReg);
      ffvpFreeTempRegister(programBuilder,wTemp);
      if (programBuilder[0x1a8] == -1) {
        return 2;
      }
    }
    if (noClipCopy) {
      return 0;
    }
    srcTempFile = *(undefined4 *)programBuilder[0xfb];
    (**(code **)(((unsigned char *)0x000012e8) + glCtx))
              (programBuilder,*(undefined4 *)(programBuilder[0xfc] + 8),programBuilder[0x1a],&DAT_001dbd24,srcTempFile,clipTempRegB
               ,&DAT_001dbd14,&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e8) + glCtx))
              (programBuilder,*(undefined4 *)(programBuilder[0xfc] + 0x14),programBuilder[clipCopyIndex + 0x21],&DAT_001dbd24,
               srcTempFile,clipTempRegB,&DAT_001dbd14,&DAT_001fa5e8);
  }
  else {
    srcTempFile = *(undefined4 *)programBuilder[0xfb];
    allocStatus = ffvpAllocTempRegister(programBuilder,0,clipTemp);
    clipTempReg = clipTempRegB;
    if (allocStatus != 0) {
      return 7;
    }
    if (noClipCopy) {
      outDstFile = *(undefined4 *)(programBuilder[0xfc] + 8);
      dstReg = programBuilder[0x1a];
    }
    else {
      outDstFile = *(undefined4 *)programBuilder[0xfc];
      dstReg = clipTempRegB;
    }
    mvpConstRegCopy = programBuilder[0x29];
    srcTempFileC = *(undefined4 *)programBuilder[0xfb];
    constFileB = ((undefined4 *)programBuilder[0xfb])[2];
    emit9Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
    emit9Src1Index = *(int *)((int)programBuilder + 0);
    emit9Src1Select = &DAT_001dbcd4;
    (**(code **)(((unsigned char *)0x000012ec) + glCtx))
              (programBuilder,srcTempFileC,clipTempRegB,&DAT_001dbd24,constFileB,mvpConstRegCopy + 3,&DAT_001dbd14,&DAT_001fa5e8,emit9Src1File,emit9Src1Index,emit9Src1Select,&DAT_001fa5e8);
    emit10Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
    emit10Src1Index = *(int *)((int)programBuilder + 0);
    emit10Src1Select = &DAT_001dbcf4;
    (**(code **)(((unsigned char *)0x000012f4) + glCtx))
              (programBuilder,srcTempFileC,clipTempReg,&DAT_001dbd24,constFileB,mvpConstRegCopy + 2,&DAT_001dbd14,&DAT_001fa5e8,emit10Src1File,emit10Src1Index,emit10Src1Select,&DAT_001fa5e8,srcTempFileC,clipTempReg,&DAT_001dbd14,&DAT_001fa5e8);
    deadEmitFn12f4 = *(int *)((int)*(int *)((int)programBuilder + 980) + 4852);
    emit11Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
    emit11Src1Index = *(int *)((int)programBuilder + 0);
    emit11Src1Select = &DAT_001dbce4;
    (**(code **)(((unsigned char *)0x000012f4) + glCtx))
              (programBuilder,srcTempFileC,clipTempReg,&DAT_001dbd24,constFileB,mvpConstRegCopy + 1,&DAT_001dbd14,&DAT_001fa5e8,emit11Src1File,emit11Src1Index,emit11Src1Select,&DAT_001fa5e8,srcTempFileC,clipTempReg,&DAT_001dbd14,&DAT_001fa5e8);
    if ((*(char *)(programBuilder + 0x1d1) == '\0') || (programBuilder[0x1a8] != -1)) {
      deadSrc1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
      deadInputReg = *(int *)((int)programBuilder + 0);
      deadSelectConst = &DAT_001fa5f8;
      deadSrcTempFile = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
      deadEmitFn12f4B = *(int *)((int)*(int *)((int)programBuilder + 980) + 4852);
      emit12Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
      emit12Src1Index = *(int *)((int)programBuilder + 0);
      emit12Src1Select = &DAT_001fa5f8;
      emit12Src2File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
      emit12Src2Index = clipTempRegB;
      (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                (programBuilder,outDstFile,dstReg,&DAT_001dbd24,constFileB,mvpConstRegCopy,&DAT_001dbd14,&DAT_001fa5e8,emit12Src1File,emit12Src1Index,emit12Src1Select,&DAT_001fa5e8,emit12Src2File,emit12Src2Index,&DAT_001dbd14,&DAT_001fa5e8);
    }
    else {
      emit13Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 4);
      emit13Src1Index = *(int *)((int)programBuilder + 0);
      emit13Src1Select = &DAT_001fa5f8;
      (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                (programBuilder,*(undefined4 *)programBuilder[0xfb],clipTempRegB,&DAT_001dbd24,constFileB,mvpConstRegCopy,
                 &DAT_001dbd14,&DAT_001fa5e8,emit13Src1File,emit13Src1Index,emit13Src1Select,&DAT_001fa5e8,*(undefined4 *)programBuilder[0xfb],clipTempRegB,&DAT_001dbd14,&DAT_001fa5e8);
      if (noClipCopy) {
        (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                  (programBuilder,*(undefined4 *)(programBuilder[0xfc] + 8),programBuilder[0x1a],&DAT_001dbd24,srcTempFile,
                   clipTempRegB,&DAT_001dbd14,&DAT_001fa5e8);
      }
      ffvpEmitInverseW(programBuilder,srcTempFile,clipTempRegB);
      if (programBuilder[0x1a8] == -1) {
        ffvpFreeTempRegister(programBuilder,clipTemp);
        return 2;
      }
    }
    if (!noClipCopy) {
      srcTempFile = *(undefined4 *)programBuilder[0xfb];
      (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                (programBuilder,*(undefined4 *)(programBuilder[0xfc] + 8),programBuilder[0x1a],&DAT_001dbd24,srcTempFile,
                 clipTempRegB,&DAT_001dbd14,&DAT_001fa5e8);
      (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                (programBuilder,*(undefined4 *)(programBuilder[0xfc] + 0x14),programBuilder[clipCopyIndex + 0x21],&DAT_001dbd24
                 ,srcTempFile,clipTempRegB,&DAT_001dbd14,&DAT_001fa5e8);
    }
  }
  ffvpFreeTempRegister(programBuilder,clipTemp);
  return 0;
}

/* ffvpPrepareEyeNormal @ 0x96500 (52 bytes) */
int ffvpPrepareEyeNormal(programBuilder)
  int programBuilder;
{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (programBuilder != 0) {
    if ((*(int *)(programBuilder + 0xc4) != -1) && (*(int *)(programBuilder + 4) != -1)) {
      uVar1 = ffvpEmitEyeNormal(programBuilder);
      return uVar1;
    }
    uVar1 = 2;
  }
  return uVar1;
}

/* ffvpPrepareFogExp2 @ 0x96540 (172 bytes) */
int ffvpPrepareFogExp2(programBuilder)
  int programBuilder;
{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(int *)(programBuilder + 0x330) == -1) || (iVar2 = *(int *)(programBuilder + 0x70), iVar2 == -1)) {
    return 2;
  }
  if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(*(int *)(programBuilder + 0x3d4) + 4) + 0x10)) ==
      -0x7baf) {
    if (*(int *)(programBuilder + 0x50) == -1) {
      return 2;
    }
    if (3 < *(uint *)(programBuilder + 0x54)) {
      return 3;
    }
  }
  if ((((*(int *)(programBuilder + 0x3d8) == 0) && (iVar2 != *(int *)(programBuilder + 0x74))) &&
      (iVar2 != *(int *)(programBuilder + 0x78))) &&
     ((iVar2 != *(int *)(programBuilder + 0x7c) && (iVar2 != *(int *)(programBuilder + 0x80))))) {
    return 3;
  }
  *(undefined1 *)(*(int *)(programBuilder + 0x3d4) + 0x12e) = 0;
  uVar1 = ffvpEmitFogExp2(programBuilder);
  return uVar1;
}

/* ffvpEmitTexCoordGen @ 0x96600 (1872 bytes) */
int ffvpEmitTexCoordGen(programBuilder, texUnit, useXyz1Select, texUnitAlias, texMatrixEnabled, texMatrixUnit, texGenModes)
  int programBuilder;
  uint texUnit;
  undefined4 useXyz1Select;
  uint texUnitAlias;
  int texMatrixEnabled;
  uint texMatrixUnit;
  uint texGenModes;
{
  undefined4 constFileB;
  undefined4 genSrcFile;
  undefined4 matrixDstReg;
  undefined4 *planeRegCursor;
  int texMatrixReg;
  int glCtx;
  bool noTexGen;
  bool needsInvW;
  bool noTexMatrix;
  int unitOffset;
  uint genMode;
  char wantsInvWTemp;
  undefined4 status;
  int allocStatus;
  int iVarSa;
  int iVarSb;
  undefined4 *dstFileTable;
  undefined4 *srcFileTable;
  int texgenSrcReg;
  int glCtxB;
  undefined4 genDstFile;
  undefined4 planeReg;
  undefined4 constFile;
  undefined4 matrixDstFile;
  uint componentShift;
  undefined4 genDstReg;
  undefined *maskCursor;
  undefined4 uStack00000020;
  undefined1 texTempA [4];
  undefined4 texTempAReg;
  undefined1 texTempB [4];
  undefined4 texTempBReg;
  undefined4 wMulSrcFile;
  undefined4 wMulSrcReg;
  int ownsTempB;
  int ownsTempA;
  int emit8Src1File;
  int emit8Src1Select;
  
  noTexMatrix = texMatrixEnabled == 0;
  uStack00000020 = useXyz1Select;
  if ((noTexMatrix) && (texGenModes == 0)) {
    status = ffvpEmitTexCoordPassThrough(programBuilder,texUnit,useXyz1Select,texUnitAlias,0,texMatrixUnit,0);
    return status;
  }
  if (programBuilder == 0) {
    return 1;
  }
  if (((7 < texUnit) || (7 < texUnitAlias)) || (7 < texMatrixUnit)) {
    return 3;
  }
  unitOffset = texUnit * 4;
  if (((*(int *)(unitOffset + programBuilder + 0x84) == -1) || (*(int *)(unitOffset + programBuilder + 0x2c) == -1)) ||
     ((needsInvW = *(char *)(programBuilder + 0x744) != '\0', needsInvW && (*(int *)(programBuilder + 0xa4) == -1)))) {
    return 2;
  }
  glCtxB = *(int *)(programBuilder + 0x3d4);
  if ((needsInvW) || ((texGenModes != 0 && (!noTexMatrix)))) {
    allocStatus = ffvpAllocTempRegister(programBuilder,0,texTempA);
    if (allocStatus != 0) {
      return 7;
    }
    wantsInvWTemp = *(char *)(programBuilder + 0x744);
    ownsTempA = 1;
  }
  else {
    ownsTempA = 0;
    wantsInvWTemp = '\0';
  }
  noTexGen = texGenModes == 0;
  if (wantsInvWTemp == '\0') {
    if (noTexGen) {
      dstFileTable = *(undefined4 **)(programBuilder + 0x3f0);
      genDstFile = 0;
      texTempAReg = 0;
    }
    else if (noTexMatrix) {
      dstFileTable = *(undefined4 **)(programBuilder + 0x3f0);
      texTempAReg = *(undefined4 *)(unitOffset + programBuilder + 0x84);
      genDstFile = dstFileTable[5];
    }
    else {
      dstFileTable = *(undefined4 **)(programBuilder + 0x3f0);
      genDstFile = *dstFileTable;
    }
    matrixDstFile = dstFileTable[5];
    matrixDstReg = *(undefined4 *)(unitOffset + programBuilder + 0x84);
    if (noTexGen) {
      ownsTempB = 0;
      wMulSrcFile = 0;
      wMulSrcReg = 0;
      goto LAB_00096b24;
    }
    ownsTempB = 0;
    wMulSrcFile = 0;
    wMulSrcReg = 0;
    genDstReg = texTempAReg;
  }
  else {
    if (noTexGen) {
      wMulSrcReg = texTempAReg;
      matrixDstFile = **(undefined4 **)(programBuilder + 0x3f0);
      ownsTempB = 0;
      matrixDstReg = texTempAReg;
      wMulSrcFile = matrixDstFile;
      goto LAB_00096b24;
    }
    genDstFile = **(undefined4 **)(programBuilder + 0x3f0);
    genDstReg = texTempAReg;
    if (noTexMatrix) {
      wMulSrcReg = texTempAReg;
      matrixDstFile = 0;
      ownsTempB = 0;
      matrixDstReg = 0;
      wMulSrcFile = genDstFile;
    }
    else {
      if (*(int *)(programBuilder + 0x6a0) == -1) {
        if (ownsTempA == 0) {
          return 2;
        }
        ffvpFreeTempRegister(programBuilder,texTempA);
        return 2;
      }
      allocStatus = ffvpAllocTempRegister(programBuilder,0,texTempB);
      if (allocStatus != 0) {
        if (ownsTempA == 0) {
          return 7;
        }
        ffvpFreeTempRegister(programBuilder,texTempA);
        return 7;
      }
      wMulSrcReg = texTempBReg;
      matrixDstFile = **(undefined4 **)(programBuilder + 0x3f0);
      ownsTempB = 1;
      matrixDstReg = texTempBReg;
      wMulSrcFile = matrixDstFile;
    }
  }
  if (((((texGenModes & 7) == 0) || ((texGenModes & 0x38) == 0)) || ((texGenModes & 0x1c0) == 0)) ||
     ((texGenModes & 0xe00) == 0)) {
    (**(code **)(((unsigned char *)0x000012e8) + glCtxB))
              (programBuilder,genDstFile,genDstReg,&DAT_001dbd24,*(undefined4 *)(*(int *)(programBuilder + 0x3ec) + 4),
               *(undefined4 *)(unitOffset + programBuilder + 0x2c),&DAT_001dbd14,&DAT_001fa5e8);
  }
  componentShift = 0;
  maskCursor = &DAT_001dbdfc;
  planeRegCursor = (undefined4 *)(texUnit * 0x10 + programBuilder + 0x348);
  do {
    genMode = texGenModes >> (componentShift & 0x3f) & 7;
    if (genMode == 0) goto switchD_0009696c_default;
    srcFileTable = *(undefined4 **)(programBuilder + 0x3ec);
    glCtx = *(int *)(programBuilder + 0x3d4);
    planeReg = *planeRegCursor;
    constFile = srcFileTable[2];
    switch(genMode) {
    case 1:
      if (*(int *)(programBuilder + 0x3f8) == -1) {
        if ((*(uint *)(((unsigned char *)0x000013c0) + glCtx) & 4) == 0) {
          ffvpEmitEyePositionDp4(programBuilder);
        }
        else {
          ffvpEmitEyePositionMad(programBuilder);
        }
      }
      /* #70 stack words: case 1 (stock 0x969a8) passes (rec[0], *(programBuilder + 0x3f8)) as the 9th / 10th arguments below, case 2
       * (0x96988) passes (rec[4], *programBuilder); the 11th / 12th are the PIC constants on both paths */
      iVarSa = *srcFileTable;
      iVarSb = *(int *)(programBuilder + 0x3f8);
      goto LAB_000969f0;
    case 2:
      iVarSa = srcFileTable[1];
      iVarSb = *(int *)programBuilder;
LAB_000969f0:
      /* issue #79 class: the stock sets r9 / r10 (`addi r9,r11,0x5700`, `addi r10,r10,0x3fd4` from the PIC base 0x96614 =
       * &DAT_001dbd14 / &DAT_001fa5e8) for the `bctrl` at 0x96a20 - the same 7th / 8th arguments every sibling call through
       * this slot passes - and stores them again as stack words, which is why the same-block count stopped at r8 */
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))(programBuilder,genDstFile,genDstReg,maskCursor,constFile,planeReg,&DAT_001dbd14,&DAT_001fa5e8,iVarSa,iVarSb,&DAT_001dbd14,&DAT_001fa5e8);
      goto switchD_0009696c_default;
    case 3:
      texgenSrcReg = *(int *)(programBuilder + 0x4e8);
      genSrcFile = *srcFileTable;
      if (texgenSrcReg == -1) {
        ffvpEmitSphereMapCoord(programBuilder);
        texgenSrcReg = *(int *)(programBuilder + 0x4e8);
      }
      break;
    case 4:
      genSrcFile = *srcFileTable;
      if (*(char *)(glCtx + 0x128) == '\0') {
        if (*(char *)(glCtx + 300) == '\0') {
          texgenSrcReg = *(int *)(programBuilder + 0x448);
          if (texgenSrcReg == -1) {
            ffvpEmitEyeNormal(programBuilder);
            texgenSrcReg = *(int *)(programBuilder + 0x448);
          }
        }
        else {
          texgenSrcReg = *(int *)(programBuilder + 0x470);
          if (texgenSrcReg == -1) {
            ffvpEmitRescaledNormal(programBuilder);
            texgenSrcReg = *(int *)(programBuilder + 0x470);
          }
        }
      }
      else {
        texgenSrcReg = *(int *)(programBuilder + 0x498);
        if (texgenSrcReg == -1) {
          ffvpEmitNormalizedNormal(programBuilder);
          texgenSrcReg = *(int *)(programBuilder + 0x498);
        }
      }
      break;
    case 5:
      texgenSrcReg = *(int *)(programBuilder + 0x4c0);
      genSrcFile = *srcFileTable;
      if (texgenSrcReg == -1) {
        ffvpEmitReflectionVector(programBuilder);
        texgenSrcReg = *(int *)(programBuilder + 0x4c0);
      }
      break;
    default:
      goto switchD_0009696c_default;
    }
    (**(code **)(((unsigned char *)0x000012e8) + glCtx))
              (programBuilder,genDstFile,genDstReg,maskCursor,genSrcFile,texgenSrcReg,&DAT_001dbd14,&DAT_001fa5e8);
switchD_0009696c_default:
    noTexGen = componentShift != 9;
    maskCursor = maskCursor + 0x10;
    planeRegCursor = planeRegCursor + 1;
    componentShift = componentShift + 3;
  } while (noTexGen);
LAB_00096b24:
  if (!noTexMatrix) {
    texMatrixReg = *(int *)(texMatrixUnit * 4 + programBuilder + 0xd8);
    constFileB = *(undefined4 *)(*(int *)(programBuilder + 0x3ec) + 8);
    (**(code **)(((unsigned char *)0x000012e4) + glCtxB))
              (programBuilder,matrixDstFile,matrixDstReg,&DAT_001dbd04,constFileB,texMatrixReg,&DAT_001dbd14,&DAT_001fa5e8,(noTexGen ? (*(int **)(programBuilder + 0x3ec))[1] : noTexMatrix ? 0 : **(int **)(programBuilder + 0x3ec)),(noTexGen ? *(int *)(unitOffset + programBuilder + 0x2c) : noTexMatrix ? 0 : texTempAReg),(useXyz1Select != 0 ? ((unsigned char *)&DAT_001dbdc0 + 4) : &DAT_001dbd14),&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e4) + glCtxB))
              (programBuilder,matrixDstFile,matrixDstReg,&DAT_001dbd64,constFileB,texMatrixReg + 1,&DAT_001dbd14,&DAT_001fa5e8,(noTexGen ? (*(int **)(programBuilder + 0x3ec))[1] : noTexMatrix ? 0 : **(int **)(programBuilder + 0x3ec)),(noTexGen ? *(int *)(unitOffset + programBuilder + 0x2c) : noTexMatrix ? 0 : texTempAReg),(useXyz1Select != 0 ? ((unsigned char *)&DAT_001dbdc0 + 4) : &DAT_001dbd14),&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e4) + glCtxB))
              (programBuilder,matrixDstFile,matrixDstReg,&DAT_001dbd54,constFileB,texMatrixReg + 2,&DAT_001dbd14,&DAT_001fa5e8,(noTexGen ? (*(int **)(programBuilder + 0x3ec))[1] : noTexMatrix ? 0 : **(int **)(programBuilder + 0x3ec)),(noTexGen ? *(int *)(unitOffset + programBuilder + 0x2c) : noTexMatrix ? 0 : texTempAReg),(useXyz1Select != 0 ? ((unsigned char *)&DAT_001dbdc0 + 4) : &DAT_001dbd14),&DAT_001fa5e8);
    (**(code **)(((unsigned char *)0x000012e4) + glCtxB))
              (programBuilder,matrixDstFile,matrixDstReg,&DAT_001dbd44,constFileB,texMatrixReg + 3,&DAT_001dbd14,&DAT_001fa5e8,(noTexGen ? (*(int **)(programBuilder + 0x3ec))[1] : noTexMatrix ? 0 : **(int **)(programBuilder + 0x3ec)),(noTexGen ? *(int *)(unitOffset + programBuilder + 0x2c) : noTexMatrix ? 0 : texTempAReg),(useXyz1Select != 0 ? ((unsigned char *)&DAT_001dbdc0 + 4) : &DAT_001dbd14),&DAT_001fa5e8);
  }
  if (*(char *)(programBuilder + 0x744) != '\0') {
    emit8Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
    emit8Src1Select = (int)programBuilder + 1716;
    (**(code **)(((unsigned char *)0x000012ec) + glCtxB))
              (programBuilder,*(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0x14),
               *(undefined4 *)(unitOffset + programBuilder + 0x84),&DAT_001dbd24,wMulSrcFile,wMulSrcReg,&DAT_001dbd14
               ,&DAT_001fa5e8,emit8Src1File,*(int *)(programBuilder + 0x6a0),emit8Src1Select,&DAT_001fa5e8);
  }
  if (ownsTempA != 0) {
    ffvpFreeTempRegister(programBuilder,texTempA);
  }
  if (ownsTempB != 0) {
    ffvpFreeTempRegister(programBuilder,texTempB);
  }
  return 0;
}

/* ffvpEmitSceneColor @ 0x96d80 (1700 bytes) */
int ffvpEmitSceneColor(programBuilder)
  int programBuilder;
{
  undefined4 dstReg;
  undefined4 *ambientRegPtr;
  int stateBlockB;
  int constFile;
  int alphaTableBase;
  int ambientSrcReg;
  int ctxWordCursorB;
  int sideWordOffset;
  int builderSideCursor;
  int ctxWordCursor;
  bool sidesDiffer;
  undefined *maskPtrA;
  undefined *maskPtrB;
  undefined *maskPtrC;
  int status;
  int fetchStatus;
  int allocStatus;
  undefined4 src0Reg;
  undefined4 src1Reg;
  int colorSlotOffset;
  undefined4 *sourcePtr;
  undefined4 dstTempFile;
  undefined4 srcTempFile;
  int sideWordOffsetB;
  int stateBlock;
  int glCtx;
  undefined4 primaryReg;
  uint loopIndex;
  int sideBuilderCursor;
  int builderSideCursorB;
  undefined4 fetchedReg;
  undefined1 fetchedFileB [4];
  int fetchedFile;
  undefined1 fetchedFileA [4];
  int materialRegs [4];
  undefined4 sideColorRegs [4];
  int alphaTableBaseB;
  int *fetchFileOutPtr;
  int primaryColorBase;
  int *ambientRegs;
  int alphaTableBaseA;
  int iVarS1;
  int iVarS2;
  int iVarS3;
  int iVarS4;
  int iVarS5;
  int iVarS6;
  int iVarS7;
  int iVarS8;
  int iVarS9;
  int iVarS10;
  int iVarS11;
  int emit7Src1File;
  int emit7Src1Index;
  int emit7Src1Select;
  int emit7Src1Negate;
  int emit3Src1File;
  int emit3Src1Index;
  int emit3Src1Select;
  int emit3Src1Negate;
  int emit3Src2File;
  int emit3Src2Index;
  
  status = 1;
  if (programBuilder != 0) {
    glCtx = *(int *)(programBuilder + 0x3d4);
    loopIndex = 0;
    stateBlock = *(int *)(*(int *)(glCtx + 4) + 0x10);
    ctxWordCursor = glCtx;
    builderSideCursorB = programBuilder;
    do {
      fetchStatus = ffvpResolveMaterialSource(programBuilder,*(undefined4 *)(ctxWordCursor + 0x270),0,fetchedFileA,fetchedFileB);
      if (fetchStatus != 0) {
        return fetchStatus;
      }
      fetchStatus = ffvpResolveMaterialSource(programBuilder,*(undefined4 *)(ctxWordCursor + 0x278),1,fetchedFileA,fetchedFileB);
      if (fetchStatus != 0) {
        return fetchStatus;
      }
      if ((*(int *)(glCtx + 0x13c) == 1) && (*(int *)(builderSideCursorB + 0x2f8) == -1)) goto LAB_00097408;
      loopIndex = loopIndex + 1;
      ctxWordCursor = ctxWordCursor + 4;
      builderSideCursorB = builderSideCursorB + 0x24;
    } while (loopIndex <= (byte)((unsigned char *)0x00002d48)[stateBlock + 4]);
    if (*(int *)(programBuilder + 0x328) == -1) {
LAB_00097408:
      status = 2;
    }
    else {
      glCtx = *(int *)(programBuilder + 0x3d4);
      loopIndex = 0;
      sideWordOffset = 0;
      constFile = (*(undefined4 **)(programBuilder + 0x3ec))[2];
      srcTempFile = **(undefined4 **)(programBuilder + 0x3ec);
      ambientRegs = materialRegs + 2;
      dstTempFile = **(undefined4 **)(programBuilder + 0x3f0);
      stateBlockB = *(int *)(*(int *)(glCtx + 4) + 0x10);
      ctxWordCursor = glCtx;
      do {
        sourcePtr = (undefined4 *)(ctxWordCursor + 0x278);
        loopIndex = loopIndex + 1;
        ctxWordCursor = ctxWordCursor + 4;
        ffvpResolveMaterialSource(programBuilder,*sourcePtr,1,(int)materialRegs + sideWordOffset,sideWordOffset + (int)ambientRegs);
        sideWordOffset = sideWordOffset + 4;
      } while (loopIndex <= (byte)((unsigned char *)0x00002d48)[stateBlockB + 4]);
      if ((((byte)((unsigned char *)0x00002d48)[stateBlockB + 4] == 0) || (materialRegs[0] != materialRegs[1])) ||
         (sidesDiffer = true, materialRegs[2] != materialRegs[3])) {
        sidesDiffer = false;
      }
      sidesDiffer = !sidesDiffer;
      fetchFileOutPtr = &fetchedFile;
      primaryColorBase = programBuilder + 0x5ac;
      alphaTableBaseA = 0x1d6d90;
      alphaTableBaseB = 0x1d6d90;
      loopIndex = 0;
      sideWordOffsetB = 0;
      colorSlotOffset = 0;
      builderSideCursor = programBuilder;
      ctxWordCursorB = glCtx;
      sideBuilderCursor = programBuilder;
      do {
        allocStatus = ffvpAllocTempRegister(programBuilder,0,primaryColorBase + colorSlotOffset);
        if (allocStatus != 0) {
          return 7;
        }
        ambientSrcReg = *(int *)((int)materialRegs + sideWordOffsetB);
        primaryReg = *(undefined4 *)(sideBuilderCursor + 0x5b0);
        *(undefined4 *)((int)sideColorRegs + sideWordOffsetB) = primaryReg;
        if (constFile == ambientSrcReg) {
          allocStatus = ffvpAllocTempRegister(programBuilder,1,programBuilder + 0x64c + colorSlotOffset);
          if (allocStatus != 0) {
            return 7;
          }
          *(undefined4 *)(sideBuilderCursor + 0x64c) = srcTempFile;
          maskPtrC = PTR_DAT_001e9778;
          maskPtrB = PTR_DAT_001e9774;
          maskPtrA = PTR_DAT_001e9770;
          (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                    (programBuilder,dstTempFile,*(undefined4 *)(sideBuilderCursor + 0x650),PTR_DAT_001e9770,constFile,
                     *(undefined4 *)(sideWordOffsetB + (int)ambientRegs),PTR_DAT_001e9774,PTR_DAT_001e9778);
          ffvpResolveMaterialSource(programBuilder,*(undefined4 *)(ctxWordCursorB + 0x270),0,&fetchedFile,&fetchedReg);
          if (constFile == fetchedFile) {
            fetchedReg = *(undefined4 *)(builderSideCursor + 0x2f8);
            (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                      (programBuilder,dstTempFile,primaryReg,maskPtrA,constFile,fetchedReg,maskPtrB,maskPtrC);
          }
          else {
            emit3Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
            emit3Src1Index = *(int *)((int)programBuilder + 808);
            emit3Src1Select = &DAT_001dbd14;
            emit3Src1Negate = &DAT_001fa5e8;
            emit3Src2File = fetchedFile;
            emit3Src2Index = fetchedReg;
            (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                      (programBuilder,dstTempFile,primaryReg,PTR_DAT_001e9770,srcTempFile,*(undefined4 *)(sideBuilderCursor + 0x650)
                       ,PTR_DAT_001e9774,PTR_DAT_001e9778,emit3Src1File,emit3Src1Index,emit3Src1Select,emit3Src1Negate,emit3Src2File,emit3Src2Index,emit3Src1Select,emit3Src1Negate);
          }
          if (*(int *)(programBuilder + 0x32c) != -1) {
            src0Reg = *(undefined4 *)(sideBuilderCursor + 0x650);
            src1Reg = srcTempFile;
            alphaTableBase = alphaTableBaseA;
LAB_00097360:
            (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                      (programBuilder,dstTempFile,primaryReg,((unsigned char *)0x00004ff4) + alphaTableBase,src1Reg,src0Reg,PTR_DAT_001e9774,
                       PTR_DAT_001e9778,(*(int *)((int)*(int *)((int)programBuilder + 1004) + 8)),*(int *)(programBuilder + 0x32c),&DAT_001dbd14,&DAT_001fa5e8,srcTempFile,primaryReg,&DAT_001dbd14,&DAT_001fa5e8);
          }
        }
        else {
          *(int *)(sideBuilderCursor + 0x64c) = ambientSrcReg;
          src1Reg = *(undefined4 *)(sideWordOffsetB + (int)ambientRegs);
          ambientRegPtr = (undefined4 *)(sideWordOffsetB + (int)ambientRegs);
          *(undefined4 *)(sideBuilderCursor + 0x650) = src1Reg;
          if (((sidesDiffer) || (loopIndex == 0)) &&
             ((**(code **)(((unsigned char *)0x000012ec) + glCtx))
                        (programBuilder,dstTempFile,primaryReg,PTR_DAT_001e9770,ambientSrcReg,src1Reg,PTR_DAT_001e9774,
                         PTR_DAT_001e9778,(*(int *)((int)*(int *)((int)programBuilder + 1004) + 8)),(*(int *)((int)programBuilder + 808)),PTR_DAT_001e9774,PTR_DAT_001e9778), sidesDiffer)) {
            ffvpResolveMaterialSource(programBuilder,*(undefined4 *)(ctxWordCursorB + 0x270),0,&fetchedFile,&fetchedReg);
            dstReg = primaryReg;
LAB_000972c8:
            (**(code **)(((unsigned char *)0x000012f0) + glCtx))
                      (programBuilder,dstTempFile,dstReg,PTR_DAT_001e9770,srcTempFile,dstReg,PTR_DAT_001e9774,
                       PTR_DAT_001e9778,fetchedFile,fetchedReg,&DAT_001dbd14,&DAT_001fa5e8);
          }
          else if (loopIndex == 1) {
            ffvpResolveMaterialSource(programBuilder,*(undefined4 *)(glCtx + 0x274),0,fetchFileOutPtr,&fetchedReg);
            dstReg = sideColorRegs[0];
            emit7Src1File = fetchedFile;
            emit7Src1Index = fetchedReg;
            emit7Src1Select = &DAT_001dbd14;
            emit7Src1Negate = &DAT_001fa5e8;
            (**(code **)(((unsigned char *)0x000012f0) + glCtx))
                      (programBuilder,dstTempFile,sideColorRegs[1],PTR_DAT_001e9770,srcTempFile,sideColorRegs[0],
                       PTR_DAT_001e9774,PTR_DAT_001e9778,emit7Src1File,emit7Src1Index,emit7Src1Select,emit7Src1Negate);
            ffvpResolveMaterialSource(programBuilder,*(undefined4 *)(glCtx + 0x270),0,fetchFileOutPtr,&fetchedReg);
            goto LAB_000972c8;
          }
          if ((*(int *)(programBuilder + 0x32c) != -1) && ((sidesDiffer || (loopIndex == 0)))) {
            src1Reg = *(undefined4 *)((int)materialRegs + sideWordOffsetB);
            src0Reg = *ambientRegPtr;
            alphaTableBase = alphaTableBaseB;
            goto LAB_00097360;
          }
        }
        if (*(char *)(glCtx + 0x12d) != '\0') {
          if (*(short *)(((unsigned char *)0x00002d48) + stateBlockB) == -0x7e06) {
            allocStatus = ffvpAllocTempRegister(programBuilder,1,programBuilder + 0x5fc + colorSlotOffset);
            if (allocStatus != 0) {
              return 7;
            }
          }
          else {
            _memcpy(sideBuilderCursor + 0x5fc,sideBuilderCursor + 0x5ac,0x28);
          }
        }
        loopIndex = loopIndex + 1;
        colorSlotOffset = colorSlotOffset + 0x28;
        sideBuilderCursor = sideBuilderCursor + 0x28;
        sideWordOffsetB = sideWordOffsetB + 4;
        builderSideCursor = builderSideCursor + 0x24;
        ctxWordCursorB = ctxWordCursorB + 4;
      } while (loopIndex <= (byte)((unsigned char *)0x00002d48)[stateBlockB + 4]);
      status = 0;
    }
  }
  return status;
}

/* ffvpEmitDirectionalLight @ 0x97440 (4212 bytes) */
int ffvpEmitDirectionalLight(programBuilder, lightIndex, isFirstLight, isLastLight, ambientCode, diffuseCode, specularCode)
  int programBuilder;
  int lightIndex;
  int isFirstLight;
  int isLastLight;
  int ambientCode;
  int diffuseCode;
  int specularCode;
{
  undefined4 *selectPtr;
  undefined *constPtrC;
  undefined4 lightSrcReg;
  undefined4 lightSrcFile;
  undefined4 outputFileD;
  int allocStatusC;
  int ctxSideCursor;
  int sideOffset;
  int allocStatusB;
  int srcInputReg;
  int allocStatusA;
  int normalReg;
  int resolveStatus;
  int lightRecWalk;
  int srcFileInput;
  int stateBlockB;
  int lightRecScan;
  int lightCountSentinel;
  int glCtx;
  undefined4 outputFileC;
  undefined4 outputRegC;
  undefined *selectConstPtr;
  undefined4 *lightRecCursorE;
  int builderCursor;
  int stateBlock;
  int glCtxB;
  int iVar8;
  int srcReg;
  int srcFile;
  int sideCount;
  bool noSpecular;
  bool notFirstLight;
  undefined4 colorDstReg;
  undefined *src0Select;
  undefined4 *tempRegCursor;
  int builderColorCursor;
  int lightRecCursorB;
  undefined4 dstTempFile;
  int lightRecord;
  int builderSideCursor;
  uint sideIndex;
  undefined1 *tempBPtr;
  int iStack00000020;
  int iStack00000024;
  int iStack0000002c;
  int iStack00000030;
  int src1File;
  int materialFile;
  int materialReg;
  undefined1 fixedFile [4];
  undefined1 fixedReg [4];
  undefined4 materialSelect0;
  undefined4 materialSelect1;
  undefined4 materialSelect2;
  undefined4 materialSelect3;
  undefined1 fixedSelect [16];
  undefined1 tempD [4];
  undefined4 tempDReg;
  undefined1 tempDMask [16];
  undefined1 tempDSelect0 [16];
  undefined1 tempA [4];
  undefined4 tempAReg;
  undefined1 tempAMask [16];
  undefined1 tempASelect0 [16];
  undefined1 tempE [4];
  undefined4 tempEReg;
  undefined1 tempC [4];
  undefined4 tempCReg;
  undefined1 tempCMask [16];
  undefined1 tempCSelect0 [16];
  undefined1 tempB [4];
  undefined4 tempBReg;
  undefined1 tempBMask [16];
  undefined1 tempBSelect0 [56];
  uint sideCounter;
  uint glSeparateSpecular;
  int constBase90;
  int constBase8c;
  int constBase88;
  int constBase84;
  int constBase80;
  int constBase7c;
  undefined1 *tempCPtr;
  undefined1 *tempBPtrCopy;
  undefined4 *tempBRegBase;
  int *materialRegPtr;
  undefined1 *tempDPtr;
  undefined1 *tempAPtr;
  undefined1 *tempASelectPtr;
  undefined1 *tempEPtr;
  int iVarS10;
  int iVarS11;
  int deadSrcTempFile;
  int iVarS13;
  int iVarS14;
  int iVarS15;
  int deadSelectConst;
  int iVarS17;
  int iVarS18;
  int iVarS19;
  int iVarS20;
  int iVarS21;
  int iVarS22;
  int emit7Src1Select;
  int emit8Src1File;
  int emit8Src1Index;
  int emit8Src1Select;
  int emit10Src1File;
  int emit10Src1Index;
  int emit10Src1Select;
  int emit11Src1File;
  int emit11Src1Index;
  int emit11Src1Select;
  int src2Index;
  int iVarS34;
  int iVarS35;
  int emit15Src1File;
  int emit15Src1Index;
  int emit15Src1Select;
  int emit15Src1Negate;
  int emit17Src1File;
  int emit17Src1Index;
  int emit17Src1Select;
  int emit17Src1Negate;
  int emit23Src1Select;
  int emit3Src1File;
  int emit3Src1Index;
  int emit3Src2File;
  int iVarS48;
  int iVarS49;
  int iVarS50;
  int iVarS51;
  int srcTempFileArg;
  int emit9Src1Index;
  int emit9Src1Select;
  int emit9Src2Select;
  int emit21Src1Select;
  int emit19Src1File;
  int emit19Src1Index;
  int emit19Src1Negate;
  int emit6Src1Index;
  int emit6Src1Select;
  int emit6Src2File;
  int emit6Src2Index;
  int emit6Src2Select;
  int emit6Src2Negate;
  int iVarS66;
  int iVarS67;
  int srcTempFileArgB;
  int emit12Src1Index;
  int iVarS70;
  int iVarS71;
  
  lightRecord = programBuilder + 0xf8 + lightIndex * 0x3c;
  glCtxB = *(int *)(programBuilder + 0x3d4);
  stateBlock = *(int *)(*(int *)(glCtxB + 4) + 0x10);
  if ((*(int *)(lightRecord + 0x24) == -1) || ((ambientCode == 2 && (*(int *)(lightRecord + 4) == -1)))) {
LAB_000984b0:
    lightCountSentinel = 2;
  }
  else {
    if (diffuseCode == 2) {
      sideCount = (byte)((unsigned char *)0x00002d48)[stateBlock + 4] + 1;
      lightRecWalk = lightRecord;
      do {
        if ((*(int *)(lightRecWalk + 0xc) == -1) && (*(int *)(lightRecord + 8) == -1)) goto LAB_000984b0;
        lightRecWalk = lightRecWalk + 4;
        sideCount = sideCount + -1;
      } while (sideCount != 0);
    }
    noSpecular = specularCode == 0;
    iStack00000020 = isFirstLight;
    iStack00000024 = isLastLight;
    iStack0000002c = diffuseCode;
    iStack00000030 = specularCode;
    if (!noSpecular) {
      sideIndex = 0;
      do {
        resolveStatus = ffvpResolveFixedSource(programBuilder,*(undefined4 *)(glCtxB + 0x290),fixedFile,fixedReg,
                             fixedSelect);
        if (resolveStatus != 0) {
          return resolveStatus;
        }
        sideIndex = sideIndex + 1;
        glCtxB = glCtxB + 4;
      } while (sideIndex <= (byte)((unsigned char *)0x00002d48)[stateBlock + 4]);
      if ((((unsigned char *)0x00002d48)[stateBlock + 5] == '\0') && (*(int *)(lightRecord + 0x28) == -1))
      goto LAB_000984b0;
    }
    if (iStack00000030 == 2) {
      stateBlock = (byte)((unsigned char *)0x00002d48)[stateBlock + 4] + 1;
      lightRecScan = lightRecord;
      do {
        if ((*(int *)(lightRecScan + 0x18) == -1) && (*(int *)(lightRecord + 0x14) == -1)) goto LAB_000984b0;
        lightRecScan = lightRecScan + 4;
        stateBlock = stateBlock + -1;
      } while (stateBlock != 0);
    }
    glCtx = *(int *)(programBuilder + 0x3d4);
    stateBlockB = *(int *)(*(int *)(glCtx + 4) + 0x10);
    /* #70 stack words (stackargs_overrides.json): the stock's r16, the 9th argument of the ctx+0x12e4 calls below, is rec[0]
     * on three arms and rec[4] (`lwz r16,0x4(r2)` at 0x97638) on the arm that takes iVar8 = *(programBuilder + 4); Ghidra dropped
     * the dead loads */
    src1File = **(int **)(programBuilder + 0x3ec);
    if (*(char *)(glCtx + 0x128) == '\0') {
      if (*(char *)(glCtx + 300) == '\0') {
        if (*(char *)(glCtx + 0x12a) == '\0') {
          normalReg = *(int *)(programBuilder + 4);
          src1File = (*(int **)(programBuilder + 0x3ec))[1];
        }
        else {
          if (*(int *)(programBuilder + 0x448) != -1) goto LAB_00097650;
          ffvpEmitEyeNormal(programBuilder);
          normalReg = *(int *)(programBuilder + 0x448);
        }
      }
      else {
        if (*(int *)(programBuilder + 0x470) != -1) goto LAB_00097650;
        ffvpEmitRescaledNormal(programBuilder);
        normalReg = *(int *)(programBuilder + 0x470);
      }
LAB_0009763c:
      if (normalReg == -1) goto LAB_000984b0;
    }
    else if (*(int *)(programBuilder + 0x498) == -1) {
      ffvpEmitNormalizedNormal(programBuilder);
      normalReg = *(int *)(programBuilder + 0x498);
      goto LAB_0009763c;
    }
LAB_00097650:
    tempAPtr = tempA;
    allocStatusA = ffvpAllocTempRegister(programBuilder,2,tempAPtr);
    if (allocStatusA == 0) {
      dstTempFile = **(undefined4 **)(programBuilder + 0x3f0);
      srcInputReg = (*(int **)(programBuilder + 0x3ec))[2];
      srcFileInput = **(int **)(programBuilder + 0x3ec);
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                (programBuilder,dstTempFile,tempAReg,tempAMask,srcInputReg,*(undefined4 *)(lightRecord + 0x24),&DAT_001dbd74
                 ,&DAT_001fa5e8,src1File,(*(char *)(glCtx + 0x128) == '\0' ? (*(char *)(glCtx + 300) == '\0' ? (*(char *)(glCtx + 0x12a) == '\0' ? *(int *)(programBuilder + 4) : *(int *)(programBuilder + 0x448)) : *(int *)(programBuilder + 0x470)) : *(int *)(programBuilder + 0x498)),&DAT_001dbd74,&DAT_001fa5e8);
      if ((ambientCode != 0) && (ambientCode != 3)) {
        sideIndex = 0;
        builderCursor = programBuilder;
        do {
          colorDstReg = *(undefined4 *)(builderCursor + 0x5b0);
          if (ambientCode == 1) {
            (**(code **)(((unsigned char *)0x000012f0) + glCtx))
                      (programBuilder,dstTempFile,colorDstReg,&DAT_001dbd84,srcFileInput,colorDstReg,&DAT_001dbd14,&DAT_001fa5e8,*(int *)(builderCursor + 0x64c),*(int *)(builderCursor + 0x650),&DAT_001dbd14,&DAT_001fa5e8);
          }
          else {
            emit3Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
            emit3Src1Index = *(int *)((int)lightRecord + 4);
            emit3Src2File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
            (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                      (programBuilder,dstTempFile,colorDstReg,&DAT_001dbd84,*(undefined4 *)(builderCursor + 0x64c),
                       *(undefined4 *)(builderCursor + 0x650),&DAT_001dbd14,&DAT_001fa5e8,emit3Src1File,emit3Src1Index,&DAT_001dbd14,&DAT_001fa5e8,emit3Src2File,colorDstReg,&DAT_001dbd14,&DAT_001fa5e8);
          }
          sideIndex = sideIndex + 1;
          builderCursor = builderCursor + 0x28;
        } while (sideIndex <= (byte)((unsigned char *)0x00002d48)[stateBlockB + 4]);
      }
      tempBPtr = tempB;
      sideIndex = 0;
      tempBPtrCopy = tempBPtr;
      do {
        allocStatusB = ffvpAllocTempRegister(programBuilder,1,tempBPtr);
        if (allocStatusB != 0) goto LAB_000984a0;
        sideIndex = sideIndex + 1;
        tempBPtr = tempBPtr + 0x28;
      } while (sideIndex <= (byte)((unsigned char *)0x00002d48)[stateBlockB + 4]);
      if (noSpecular) {
        tempBRegBase = &tempBReg;
        tempASelectPtr = tempASelect0;
        do {
          sideIndex = 0;
          tempRegCursor = tempBRegBase;
          do {
            sideOffset = sideIndex * 0x28;
            sideIndex = sideIndex + 1;
            /* stack words, stock 0x97b88-0x97b9c: the 4th (0x44) is the r2 of the first pass (r18 + 0x3194) or of the later ones (0x14_0000 + 0x4940) */
            (**(code **)(((unsigned char *)0x0000132c) + glCtx))
                      (programBuilder,dstTempFile,*tempRegCursor,tempBPtrCopy + sideOffset + 8,srcFileInput,tempAReg,&DAT_001dbd34,
                       &DAT_001fa5e8,srcFileInput,tempAReg,tempASelectPtr,(sideIndex == 1 ? &DAT_001fa5e8 : &DAT_001dbd94),srcFileInput,tempAReg,&DAT_001dbdb4,&DAT_001fa5e8);
            if ((byte)((unsigned char *)0x00002d48)[stateBlockB + 4] < sideIndex) goto LAB_00097bd4;
            tempRegCursor = tempRegCursor + 10;
          } while (sideIndex != 0);
        } while( true );
      }
      tempCPtr = tempC;
      allocStatusB = ffvpAllocTempRegister(programBuilder,2,tempCPtr);
      if (allocStatusB == 0) {
        tempDPtr = tempD;
        allocStatusB = ffvpAllocTempRegister(programBuilder,2,tempDPtr);
        if (allocStatusB == 0) {
          if (((unsigned char *)0x00002d48)[stateBlockB + 5] == '\0') {
            tempBRegBase = &tempBReg;
            materialRegPtr = &materialReg;
            tempASelectPtr = tempASelect0;
            (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                      (programBuilder,dstTempFile,tempCReg,tempCMask,srcInputReg,*(undefined4 *)(lightRecord + 0x28),
                       &DAT_001dbd74,&DAT_001fa5e8,src1File,(*(char *)(glCtx + 0x128) == '\0' ? (*(char *)(glCtx + 300) == '\0' ? (*(char *)(glCtx + 0x12a) == '\0' ? *(int *)(programBuilder + 4) : *(int *)(programBuilder + 0x448)) : *(int *)(programBuilder + 0x470)) : *(int *)(programBuilder + 0x498)),&DAT_001dbd74,&DAT_001fa5e8);
LAB_00097a58:
            lightRecCursorE = (undefined4 *)(glCtx + 0x290);
            selectConstPtr = &DAT_001fa5e8;
            sideIndex = 0;
            tempRegCursor = tempBRegBase;
LAB_00097a68:
            ffvpResolveFixedSource(programBuilder,*lightRecCursorE,&materialFile,materialRegPtr,&materialSelect0);
            sideOffset = sideIndex * 0x28;
            sideIndex = sideIndex + 1;
            iVarS15 = *(int *)((int)*(int *)((int)programBuilder + 980) + 4908);
            deadSelectConst = &DAT_001dbdb4;
            emit6Src1Index = tempAReg;
            emit6Src1Select = tempASelectPtr;
            emit6Src2File = materialFile;
            emit6Src2Index = materialReg;
            emit6Src2Select = &materialSelect0;
            emit6Src2Negate = &DAT_001fa5e8;
            (**(code **)(((unsigned char *)0x0000132c) + glCtx))
                      (programBuilder,dstTempFile,*tempRegCursor,tempBPtrCopy + sideOffset + 8,srcFileInput,tempCReg,tempCSelect0,selectConstPtr,srcFileInput,emit6Src1Index,emit6Src1Select,selectConstPtr,emit6Src2File,emit6Src2Index,emit6Src2Select,emit6Src2Negate)
            ;
            if (sideIndex <= (byte)((unsigned char *)0x00002d48)[stateBlockB + 4]) goto LAB_00097a40;
            ffvpFreeTempRegister(programBuilder,tempCPtr);
            ffvpFreeTempRegister(programBuilder,tempDPtr);
LAB_00097bd4:
            constBase90 = 0x1d7454;
            constBase8c = 0x1d7454;
            constBase80 = 0x1d7454;
            notFirstLight = iStack00000020 == 0;
            constBase88 = 0x1d7454;
            glSeparateSpecular = 0x81fa;
            sideCounter = 0;
            constBase84 = 0x1d7454;
            constBase7c = 0x1d7454;
            tempRegCursor = tempBRegBase;
            ctxSideCursor = glCtx;
            builderColorCursor = programBuilder;
            lightRecCursorB = lightRecord;
            builderSideCursor = programBuilder;
            while (noSpecular) {
              if (((!notFirstLight) && (*(char *)(glCtx + 0x12d) != '\0')) &&
                 (*(ushort *)(((unsigned char *)0x00002d48) + stateBlockB) == glSeparateSpecular)) {
                emit7Src1Select = &DAT_001dbd34;
                (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                          (programBuilder,dstTempFile,*(undefined4 *)(builderSideCursor + 0x600),((unsigned char *)0x00004930) + constBase90,srcFileInput
                           ,*(undefined4 *)(builderSideCursor + 0x600),((unsigned char *)0x000048c0) + constBase8c,&DAT_001fa5e8,srcFileInput,*(undefined4 *)(builderSideCursor + 0x600),emit7Src1Select,&DAT_001fa5e8);
              }
LAB_000980d0:
              if (iStack0000002c == 0) {
                if (iStack00000024 != 0) {
                  outputFileC = *(undefined4 *)(builderColorCursor + 0x74);
                  colorDstReg = *(undefined4 *)(builderSideCursor + 0x5b0);
                  outputRegC = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0xc);
                  ffvpResolveMaterialSource(programBuilder,*(undefined4 *)(ctxSideCursor + 0x280),2,&materialFile,&materialReg);
                  materialSelect3 = 3;
                  materialSelect2 = 5;
                  materialSelect0 = 5;
                  materialSelect1 = 5;
                  emit8Src1File = materialFile;
                  emit8Src1Index = materialReg;
                  emit8Src1Select = &materialSelect0;
                  (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                            (programBuilder,outputRegC,outputFileC,((unsigned char *)0x000048d0) + constBase84,srcFileInput,colorDstReg,
                             ((unsigned char *)0x00004970) + constBase7c,&DAT_001fa5e8,emit8Src1File,emit8Src1Index,emit8Src1Select,&DAT_001fa5e8);
                }
              }
              else {
                colorDstReg = *(undefined4 *)(builderSideCursor + 0x5b0);
                src2Index = colorDstReg; /* stock r29, the 6th stack word of the 12f4 call below (0x981a4) */
                if (iStack00000024 == 0) {
                  outputFileD = **(undefined4 **)(programBuilder + 0x3f0);
                  constPtrC = ((unsigned char *)0x00004930) + constBase90;
                }
                else {
                  colorDstReg = *(undefined4 *)(builderColorCursor + 0x74);
                  outputFileD = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0xc);
                  constPtrC = ((unsigned char *)0x000048d0) + constBase84;
                }
                if (*(int *)(lightRecCursorB + 0xc) == -1) {
                  ffvpResolveMaterialSource(programBuilder,*(undefined4 *)(ctxSideCursor + 0x280),2,&materialFile,&materialReg);
                }
                srcFile = materialFile;
                srcReg = materialReg;
                if ((iStack0000002c == 1) ||
                   (srcFile = srcInputReg, srcReg = *(int *)(lightRecCursorB + 0xc), *(int *)(lightRecCursorB + 0xc) != -1)) {
                  srcTempFileArg = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
                  emit9Src1Index = *(int *)((int)tempRegCursor + 0);
                  emit9Src1Select = ((unsigned char *)&DAT_001dbdc0 + 44);
                  emit9Src2Select = &DAT_001dbd74;
                  (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                            (programBuilder,outputFileD,colorDstReg,constPtrC,srcFile,srcReg,((unsigned char *)0x000048c0) + constBase8c,
                             &DAT_001fa5e8,srcTempFileArg,emit9Src1Index,emit9Src1Select,&DAT_001fa5e8,srcTempFileArg,src2Index,emit9Src2Select,&DAT_001fa5e8);
                }
                else {
                  tempEPtr = tempE;
                  allocStatusC = ffvpAllocTempRegister(programBuilder,0,tempEPtr);
                  if (allocStatusC != 0) goto LAB_000984a0;
                  if (srcInputReg == materialFile) {
                    emit10Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
                    emit10Src1Index = *(int *)((int)tempRegCursor + 0);
                    emit10Src1Select = ((unsigned char *)&DAT_001dbdc0 + 44);
                    (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                              (programBuilder,dstTempFile,tempEReg,constPtrC,srcInputReg,materialReg,&DAT_001dbd14,
                               &DAT_001fa5e8,emit10Src1File,emit10Src1Index,emit10Src1Select,&DAT_001fa5e8);
                    src0Select = ((unsigned char *)0x00004970) + constBase7c;
                    lightSrcReg = *(undefined4 *)(lightRecord + 8);
                    srcFile = srcInputReg;
                  }
                  else {
                    emit11Src1File = materialFile;
                    emit11Src1Index = materialReg;
                    emit11Src1Select = &DAT_001dbd14;
                    (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                              (programBuilder,dstTempFile,tempEReg,constPtrC,srcInputReg,*(undefined4 *)(lightRecord + 8),
                               ((unsigned char *)0x00004970) + constBase7c,&DAT_001fa5e8,emit11Src1File,emit11Src1Index,emit11Src1Select,&DAT_001fa5e8);
                    lightSrcReg = *tempRegCursor;
                    src0Select = ((unsigned char *)0x00004998) + constBase80;
                    srcFile = srcFileInput;
                  }
                  srcTempFileArgB = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
                  emit12Src1Index = tempEReg;
                  (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                            (programBuilder,outputFileD,colorDstReg,constPtrC,srcFile,lightSrcReg,src0Select,&DAT_001fa5e8,srcTempFileArgB,emit12Src1Index,&DAT_001dbd14,&DAT_001fa5e8,srcTempFileArgB,src2Index,&DAT_001dbd74,&DAT_001fa5e8);
                  ffvpFreeTempRegister(programBuilder,tempEPtr);
                }
              }
              tempBPtr = tempBPtrCopy;
              tempRegCursor = tempRegCursor + 10;
              builderColorCursor = builderColorCursor + 4;
              builderSideCursor = builderSideCursor + 0x28;
              ctxSideCursor = ctxSideCursor + 4;
              lightRecCursorB = lightRecCursorB + 4;
              sideCounter = sideCounter + 1;
              if ((byte)((unsigned char *)0x00002d48)[stateBlockB + 4] < sideCounter) {
                sideIndex = 0;
                ffvpFreeTempRegister(programBuilder,tempAPtr);
                do {
                  sideIndex = sideIndex + 1;
                  ffvpFreeTempRegister(programBuilder,tempBPtr);
                  tempBPtr = tempBPtr + 0x28;
                } while (sideIndex <= (byte)((unsigned char *)0x00002d48)[stateBlockB + 4]);
                return 0;
              }
            }
            colorDstReg = *(undefined4 *)(builderSideCursor + 0x600);
            if (*(int *)(lightRecCursorB + 0x18) == -1) {
              ffvpResolveMaterialSource(programBuilder,*(undefined4 *)(ctxSideCursor + 0x288),3,&materialFile,&materialReg);
            }
            if (iStack00000030 == 1) {
              srcFile = materialFile;
              srcReg = materialReg;
              if ((!notFirstLight) && (*(ushort *)(((unsigned char *)0x00002d48) + stateBlockB) == glSeparateSpecular))
              goto LAB_00097d1c;
LAB_00097d70:
              (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                        (programBuilder,dstTempFile,colorDstReg,((unsigned char *)0x00004930) + constBase90,srcFile,srcReg,&DAT_001dbd14,
                         &DAT_001fa5e8,(*(int *)((int)*(int *)((int)programBuilder + 1004) + 0)),(*(int *)((int)tempRegCursor + 0)),(&DAT_001dbcf4),&DAT_001fa5e8,(*(int *)((int)*(int *)((int)programBuilder + 1004) + 0)),colorDstReg,(&DAT_001dbd14),&DAT_001fa5e8);
              goto LAB_000980d0;
            }
            srcReg = *(int *)(lightRecCursorB + 0x18);
            if (srcReg != -1) {
              srcFile = srcInputReg;
              if ((notFirstLight) || (*(ushort *)(((unsigned char *)0x00002d48) + stateBlockB) != glSeparateSpecular))
              goto LAB_00097d70;
LAB_00097d1c:
              (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                        (programBuilder,dstTempFile,colorDstReg,((unsigned char *)0x00004930) + constBase90,srcFile,srcReg,
                         ((unsigned char *)0x000048c0) + constBase8c,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)programBuilder + 1004) + 0)),(*(int *)((int)tempRegCursor + 0)),(&DAT_001dbcf4),&DAT_001fa5e8);
              goto LAB_000980d0;
            }
            tempEPtr = tempE;
            allocStatusC = ffvpAllocTempRegister(programBuilder,1,tempEPtr);
            if (allocStatusC == 0) {
              if (srcInputReg == materialFile) {
                emit15Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
                emit15Src1Index = *(int *)((int)tempRegCursor + 0);
                emit15Src1Select = &DAT_001dbcf4;
                emit15Src1Negate = &DAT_001fa5e8;
                (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                          (programBuilder,dstTempFile,tempEReg,&DAT_001dbd84,srcInputReg,materialReg,&DAT_001dbd14,
                           &DAT_001fa5e8,emit15Src1File,emit15Src1Index,emit15Src1Select,emit15Src1Negate);
                if ((!notFirstLight) && (*(ushort *)(((unsigned char *)0x00002d48) + stateBlockB) == glSeparateSpecular)) {
                  selectPtr = &DAT_001dbd14;
                  lightSrcFile = *(undefined4 *)(lightRecord + 0x14);
                  srcFile = srcInputReg;
                  goto LAB_00097fd4;
                }
                selectPtr = &DAT_001dbd14;
                lightSrcFile = *(undefined4 *)(lightRecord + 0x14);
                srcFile = srcInputReg;
LAB_00098038:
                (**(code **)(((unsigned char *)0x000012f4) + glCtx))
                          (programBuilder,dstTempFile,colorDstReg,&DAT_001dbd84,srcFile,lightSrcFile,selectPtr,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)programBuilder + 1004) + 0)),(tempEReg),&DAT_001dbd14,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)programBuilder + 1004) + 0)),colorDstReg,&DAT_001dbd14,&DAT_001fa5e8);
              }
              else {
                emit17Src1File = materialFile;
                emit17Src1Index = materialReg;
                emit17Src1Select = &DAT_001dbd14;
                emit17Src1Negate = &DAT_001fa5e8;
                (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                          (programBuilder,dstTempFile,tempEReg,&DAT_001dbd84,srcInputReg,*(undefined4 *)(lightRecord + 0x14),
                           &DAT_001dbd14,&DAT_001fa5e8,emit17Src1File,emit17Src1Index,emit17Src1Select,emit17Src1Negate);
                if ((notFirstLight) || (*(ushort *)(((unsigned char *)0x00002d48) + stateBlockB) != glSeparateSpecular)) {
                  lightSrcFile = *tempRegCursor;
                  selectPtr = (undefined4 *)(((unsigned char *)0x000048a0) + constBase88);
                  srcFile = srcFileInput;
                  goto LAB_00098038;
                }
                lightSrcFile = *tempRegCursor;
                selectPtr = (undefined4 *)(((unsigned char *)0x000048a0) + constBase88);
                srcFile = srcFileInput;
LAB_00097fd4:
                (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                          (programBuilder,dstTempFile,colorDstReg,&DAT_001dbd84,srcFile,lightSrcFile,selectPtr,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)programBuilder + 1004) + 0)),(tempEReg),&DAT_001dbd14,&DAT_001fa5e8);
              }
              ffvpFreeTempRegister(programBuilder,tempEPtr);
              goto LAB_000980d0;
            }
            goto LAB_000984a0;
          }
          if ((*(int *)(programBuilder + 0x420) != -1) ||
             (ffvpEmitEyeVector(programBuilder), *(int *)(programBuilder + 0x420) != -1)) {
            materialRegPtr = &materialReg;
            tempBRegBase = &tempBReg;
            deadSrcTempFile = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
            iVarS13 = *(int *)((int)*(int *)((int)programBuilder + 980) + 4848);
            iVarS14 = &tempBReg;
            emit19Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
            emit19Src1Index = *(int *)((int)programBuilder + 1056);
            emit19Src1Negate = &DAT_001dbd94;
            (**(code **)(((unsigned char *)0x000012f0) + glCtx))
                      (programBuilder,dstTempFile,tempBReg,tempBMask,srcInputReg,*(undefined4 *)(lightRecord + 0x24),&DAT_001dbd14,&DAT_001fa5e8,emit19Src1File,emit19Src1Index,&DAT_001dbd14,emit19Src1Negate);
            tempASelectPtr = tempASelect0;
            (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                      (programBuilder,dstTempFile,tempCReg,tempCMask,srcFileInput,tempBReg,tempBSelect0,&DAT_001fa5e8,srcFileInput,tempBReg,tempBSelect0,&DAT_001fa5e8);
            iVarS10 = *(int *)((int)*(int *)((int)programBuilder + 980) + 4836);
            emit21Src1Select = &DAT_001dbd74;
            (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                      (programBuilder,dstTempFile,tempDReg,tempDMask,srcFileInput,tempBReg,tempBSelect0,&DAT_001fa5e8,src1File,(*(char *)(glCtx + 0x128) == '\0' ? (*(char *)(glCtx + 300) == '\0' ? (*(char *)(glCtx + 0x12a) == '\0' ? *(int *)(programBuilder + 4) : *(int *)(programBuilder + 0x448)) : *(int *)(programBuilder + 0x470)) : *(int *)(programBuilder + 0x498)),emit21Src1Select,&DAT_001fa5e8);
            (**(code **)(((unsigned char *)0x00001318) + glCtx))
                      (programBuilder,dstTempFile,tempCReg,tempCMask,srcFileInput,tempCReg,tempCSelect0,&DAT_001fa5e8);
            emit23Src1Select = &tempCSelect0;
            (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                      (programBuilder,dstTempFile,tempCReg,tempCMask,srcFileInput,tempDReg,tempDSelect0,&DAT_001fa5e8,srcFileInput,tempCReg,emit23Src1Select,&DAT_001fa5e8);
            goto LAB_00097a58;
          }
          goto LAB_000984b0;
        }
      }
    }
LAB_000984a0:
    lightCountSentinel = 7;
  }
  return lightCountSentinel;
LAB_00097a40:
  lightRecCursorE = lightRecCursorE + 1;
  tempRegCursor = tempRegCursor + 10;
  selectConstPtr = &DAT_001dbd94;
  if (sideIndex == 0) goto LAB_00097a58;
  goto LAB_00097a68;
}

/* ffvpEmitLight @ 0x98500 (6432 bytes) */
int ffvpEmitLight(programBuilder, lightIndex, isFirstLight, isLastLight, needsSpecularB, localViewer, lightFlag23, ambientCode, diffuseCode, specularCode)
  int programBuilder;
  int lightIndex;
  int isFirstLight;
  int isLastLight;
  int needsSpecularB;
  int localViewer;
  int lightFlag23;
  int ambientCode;
  int diffuseCode;
  int specularCode;
{
  bool hasSpecularTempB;
  bool noSpecularTemp;
  undefined4 *lightRecCursorE;
  undefined4 lightSrcReg;
  undefined4 outputRegC;
  undefined4 outputFileD;
  undefined4 outputFileC;
  undefined4 lightSrcFile;
  int allocStatusB;
  int srcInputReg;
  int normalReg;
  int lightRecCursorD;
  int sideOffset;
  int builderCursor;
  int eyePositionReg;
  int allocStatus;
  int lightRecCursor;
  int ctxCursor;
  undefined4 colorSrcFile;
  undefined4 colorSrcReg;
  undefined4 *tempRegCursor;
  int stateBlock;
  int srcReg;
  int srcFile;
  int sideCount;
  int specularRegField;
  bool needsSpecular;
  int emit20Src1File;
  int emit20Src1Index;
  int emit20Src1Select;
  bool noSpecularSource;
  bool notFirstLight;
  int lightRecCursorC;
  undefined4 *selectPtr;
  undefined *src0SelectPtr;
  int builderColorCursor;
  int builderSideCursorB;
  int lightRecCursorCB;
  undefined4 dstTempFile;
  int lightRecord;
  int srcTempFile;
  undefined4 colorReg;
  undefined *dstMaskPtr;
  uint sideIndex;
  code *selectConstPtr;
  undefined1 *tempOperandCursor;
  undefined1 *tempOperandCursorB;
  int iStack00000020;
  int iStack00000024;
  int sourceFile;
  undefined1 fixedSelect [4];
  undefined1 fixedReg [4];
  int sourceReg;
  undefined1 fixedFile [16];
  undefined4 sourceSelect0;
  undefined4 sourceSelect1;
  undefined4 sourceSelect2;
  undefined4 sourceSelect3;
  int swizzleSelect0;
  undefined4 swizzleSelect1;
  undefined4 swizzleSelect2;
  undefined4 swizzleSelect3;
  undefined1 tempA [4];
  undefined4 tempAReg;
  undefined1 tempAMask [32];
  undefined1 tempE [4];
  undefined4 tempEReg;
  undefined1 tempEMask [16];
  undefined1 tempESelect0 [16];
  undefined1 tempB [4];
  undefined4 tempBReg;
  undefined1 tempBMask [16];
  undefined1 tempBSelect0 [16];
  undefined1 tempF [4];
  undefined4 tempFReg;
  undefined1 tempFMask [16];
  undefined1 tempFSelect0 [16];
  undefined1 tempC [4];
  undefined4 tempCReg;
  undefined1 tempCMask [32];
  undefined1 tempD [4];
  undefined4 tempDReg;
  undefined1 tempDMask [16];
  undefined1 tempDSelect0 [16];
  undefined1 tempG [4];
  undefined4 tempGReg;
  undefined1 tempGMask [16];
  undefined1 tempGSelect0 [56];
  uint sideCounter;
  int hasSpecularTemp;
  undefined1 *specTempOperand;
  uint glSeparateSpecular;
  code *constBase98;
  code *constBase94;
  code *constBase90;
  code *constBase8c;
  code *constBase88;
  undefined1 *tempAPtr;
  code *constBase80;
  undefined1 *tempBPtr;
  undefined1 *tempOperandPtrB;
  code *constBase74;
  undefined1 *tempCPtr;
  undefined1 *tempOperandMaskPtr;
  undefined1 *tempOperandBase;
  undefined *constBase64;
  code *constBase60;
  int deadSrcTempFile;
  int iVarS2;
  int iVarS3;
  int deadSrcTempFileB;
  int iVarS5;
  int iVarS6;
  int emit19Src1File;
  int iVarS8;
  int emit25Src1Index;
  int emit25Src1Negate;
  int emit1Src1File;
  int emit1Src1Index;
  int emit1Src1Select;
  int emit6Src1Select;
  int emit7Src1Select;
  int emit14Src1Index;
  int emit14Src1Select;
  int emit16Src1Index;
  int emit16Src1Select;
  int emit17Src1File;
  int emit17Src1Index;
  int emit17Src1Select;
  int emit21Src1File;
  int emit21Src1Index;
  int emit29Src1Select;
  int emit31Src1Select;
  int emit32Src1File;
  int emit32Src1Index;
  int emit32Src1Select;
  int emit34Src1File;
  int emit34Src1Index;
  int emit34Src1Select;
  int emit34Src1Negate;
  int emit36Src1File;
  int emit36Src1Index;
  int emit36Src1Select;
  int emit36Src1Negate;
  int iVarS38;
  int emit39Src1File;
  int emit39Src1Index;
  int emit39Src1Select;
  int emit41Src1File;
  int emit41Src1Index;
  int emit41Src1Select;
  int emit42Src1File;
  int emit42Src1Index;
  int emit42Src1Select;
  int srcTempFileArg;
  int emit2Src1Index;
  int identitySelectArg;
  int noNegateArg;
  int emit3Src1File;
  int emit3Src1Index;
  int identitySelectArgB;
  int emit3Src2Negate;
  int emit22Src1Index;
  int emit22Src1Select;
  int iVarS58;
  int iVarS59;
  int iVarS60;
  int iVarS61;
  int emit12Src1File;
  int emit12Src1Index;
  int emit12Src1Select;
  int emit13Src1File;
  int emit13Src1Index;
  int emit13Src1Select;
  int emit15Src1File;
  int emit15Src1Index;
  int emit15Src1Select;
  int emit30Src1Index;
  int emit30Src1Select;
  int emit30Src2File;
  int emit30Src2Index;
  int emit30Src2Select;
  int emit30Src2Negate;
  int iVarS77;
  int iVarS78;
  int srcTempFileArgB;
  int emit40Src1Index;
  int emit40Src1Select;
  int emit40Src2Index;
  int emit40Src2Select;
  int srcTempFileArgC;
  int emit43Src1Index;
  int emit43Src2Index;
  int emit23Src1Select;
  int emit23Src2Select;
  int emit8Src1File;
  int emit8Src1Index;
  int emit8Src1Select;
  int emit11Src1File;
  int emit11Src1Index;
  int emit27Src1Select;
  int emit24Src1Select;
  int iVarS96;
  int iVarS97;
  
  if (programBuilder == 0) {
    return 1;
  }
  lightRecord = programBuilder + 0xf8 + lightIndex * 0x3c;
  if (*(int *)(lightRecord + 0x24) == -1) {
    return 2;
  }
  needsSpecular = needsSpecularB != 0;
  if (needsSpecular) {
    if (localViewer == 0) {
      specularRegField = *(int *)(lightRecord + 0x2c);
    }
    else {
      specularRegField = *(int *)(lightRecord + 0x34);
    }
    if (specularRegField == -1) {
      return 2;
    }
  }
  ctxCursor = *(int *)(programBuilder + 0x3d4);
  stateBlock = *(int *)(*(int *)(ctxCursor + 4) + 0x10);
  if (((unsigned char *)0x0000150c)[lightIndex * 0x6c + ctxCursor] != '\0') {
    if (*(int *)(lightRecord + 0x28) == -1) {
      return 2;
    }
    if (*(int *)(lightRecord + 0x30) == -1) {
      return 2;
    }
    if ((*(float *)(lightIndex * 0x80 + stateBlock + 0x251c) != 0.0) && (*(int *)(lightRecord + 0x38) == -1)) {
      return 2;
    }
  }
  if ((ambientCode == 2) && (*(int *)(lightRecord + 4) == -1)) {
    return 2;
  }
  if (diffuseCode == 2) {
    sideCount = (byte)((unsigned char *)0x00002d48)[stateBlock + 4] + 1;
    lightRecCursorC = lightRecord;
    do {
      if ((*(int *)(lightRecCursorC + 0xc) == -1) && (*(int *)(lightRecord + 8) == -1)) {
        return 2;
      }
      lightRecCursorC = lightRecCursorC + 4;
      sideCount = sideCount + -1;
    } while (sideCount != 0);
  }
  noSpecularSource = specularCode == 0;
  iStack00000020 = isFirstLight;
  iStack00000024 = isLastLight;
  if (!noSpecularSource) {
    sideIndex = 0;
    do {
      lightRecCursorC = ffvpResolveFixedSource(programBuilder,*(undefined4 *)(ctxCursor + 0x290),fixedSelect,fixedReg,
                           fixedFile);
      if (lightRecCursorC != 0) {
        return lightRecCursorC;
      }
      sideIndex = sideIndex + 1;
      ctxCursor = ctxCursor + 4;
    } while (sideIndex <= (byte)((unsigned char *)0x00002d48)[stateBlock + 4]);
  }
  if (specularCode == 2) {
    stateBlock = (byte)((unsigned char *)0x00002d48)[stateBlock + 4] + 1;
    lightRecCursor = lightRecord;
    do {
      if ((*(int *)(lightRecCursor + 0x18) == -1) && (*(int *)(lightRecord + 0x14) == -1)) {
        return 2;
      }
      lightRecCursor = lightRecCursor + 4;
      stateBlock = stateBlock + -1;
    } while (stateBlock != 0);
  }
  tempAPtr = tempA;
  lightRecCursorC = *(int *)(programBuilder + 0x3d4);
  stateBlock = *(int *)(*(int *)(lightRecCursorC + 4) + 0x10);
  allocStatus = ffvpAllocTempRegister(programBuilder,1,tempAPtr);
  if (allocStatus != 0) {
    return 7;
  }
  tempBPtr = tempB;
  allocStatus = ffvpAllocTempRegister(programBuilder,1,tempBPtr);
  if (allocStatus != 0) {
    return 7;
  }
  tempCPtr = tempC;
  allocStatus = ffvpAllocTempRegister(programBuilder,2,tempCPtr);
  if (allocStatus != 0) {
    return 7;
  }
  allocStatus = ffvpAllocTempRegister(programBuilder,2,tempD);
  if (allocStatus != 0) {
    return 7;
  }
  eyePositionReg = *(int *)(programBuilder + 0x3f8);
  if (eyePositionReg == -1) {
    if ((*(uint *)(((unsigned char *)0x000013c0) + lightRecCursorC) & 4) == 0) {
      ffvpEmitEyePositionDp4(programBuilder);
    }
    else {
      ffvpEmitEyePositionMad(programBuilder);
    }
    eyePositionReg = *(int *)(programBuilder + 0x3f8);
    if (eyePositionReg == -1) {
      return 2;
    }
  }
  if (*(char *)(lightRecCursorC + 0x128) == '\0') {
    if (*(char *)(lightRecCursorC + 300) == '\0') {
      if (*(int *)(programBuilder + 0x448) != -1) goto LAB_00098818;
      ffvpEmitEyeNormal(programBuilder);
      normalReg = *(int *)(programBuilder + 0x448);
    }
    else {
      if (*(int *)(programBuilder + 0x470) != -1) goto LAB_00098818;
      ffvpEmitRescaledNormal(programBuilder);
      normalReg = *(int *)(programBuilder + 0x470);
    }
  }
  else {
    if (*(int *)(programBuilder + 0x498) != -1) goto LAB_00098818;
    ffvpEmitNormalizedNormal(programBuilder);
    normalReg = *(int *)(programBuilder + 0x498);
  }
  if (normalReg == -1) {
    return 2;
  }
LAB_00098818:
  srcInputReg = (*(int **)(programBuilder + 0x3ec))[2];
  dstTempFile = **(undefined4 **)(programBuilder + 0x3f0);
  srcTempFile = **(int **)(programBuilder + 0x3ec);
  if (lightFlag23 == 0) {
    constBase64 = &DAT_001f8514;
    constBase60 = KhanVs__deleting_dtor_1d8514;
    constBase80 = KhanVs__deleting_dtor_1d8514;
    emit1Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
    emit1Src1Index = *(int *)((int)lightRecord + 36);
    emit1Src1Select = &DAT_001dbd14;
    (**(code **)(((unsigned char *)0x000012ec) + lightRecCursorC))
              (programBuilder,dstTempFile,tempAReg,tempAMask,srcTempFile,eyePositionReg,&DAT_001dbcd4,&DAT_001fa5e8,emit1Src1File,emit1Src1Index,emit1Src1Select,&DAT_001fa5e8);
    srcTempFileArg = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
    emit2Src1Index = *(int *)((int)programBuilder + 1016);
    identitySelectArg = &DAT_001dbd14;
    noNegateArg = &DAT_001fa5e8;
    (**(code **)(((unsigned char *)0x000012f4) + lightRecCursorC))
              (programBuilder,dstTempFile,tempAReg,tempAMask,srcInputReg,*(undefined4 *)(lightRecord + 0x24),&DAT_001dbcd4,
               ((unsigned char *)0x00003880) + (int)constBase80,srcTempFileArg,emit2Src1Index,identitySelectArg,noNegateArg,srcTempFileArg,tempAReg,identitySelectArg,noNegateArg);
  }
  else {
    constBase64 = &DAT_001f8514;
    constBase60 = KhanVs__deleting_dtor_1d8514;
    constBase80 = KhanVs__deleting_dtor_1d8514;
    emit3Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
    emit3Src1Index = *(int *)((int)lightRecord + 36);
    identitySelectArgB = &DAT_001dbd14;
    emit3Src2Negate = &DAT_001dbd94;
    (**(code **)(((unsigned char *)0x000012f4) + lightRecCursorC))
              (programBuilder,dstTempFile,tempAReg,tempAMask,srcTempFile,eyePositionReg,&DAT_001dbcd4,&DAT_001fa5e8,emit3Src1File,emit3Src1Index,identitySelectArgB,&DAT_001fa5e8,srcTempFile,eyePositionReg,identitySelectArgB,emit3Src2Negate);
  }
  tempOperandMaskPtr = tempDSelect0;
  constBase74 = KhanVs__deleting_dtor_1d8514;
  selectConstPtr = 0x000020d4 + (int)constBase64;
  (**(code **)(((unsigned char *)0x000012e4) + lightRecCursorC))
            (programBuilder,dstTempFile,tempBReg,&DAT_001dbd04,srcTempFile,tempAReg,&DAT_001dbd74,selectConstPtr,srcTempFile,tempAReg,&DAT_001dbd74,selectConstPtr);
  (**(code **)(((unsigned char *)0x00001318) + lightRecCursorC))
            (programBuilder,dstTempFile,tempDReg,tempDMask,srcTempFile,tempBReg,&DAT_001fa5f8,selectConstPtr);
  emit6Src1Select = (int)constBase60 + 14336;
  (**(code **)(((unsigned char *)0x000012ec) + lightRecCursorC))
            (programBuilder,dstTempFile,tempAReg,tempAMask,srcTempFile,tempDReg,tempOperandMaskPtr,selectConstPtr,srcTempFile,tempAReg,emit6Src1Select,selectConstPtr);
  if ((needsSpecular) && (localViewer == 0)) {
    emit7Src1Select = &DAT_001fa5f8;
    (**(code **)(((unsigned char *)0x000012ec) + lightRecCursorC))
              (programBuilder,dstTempFile,tempBReg,&DAT_001dbd64,srcTempFile,tempDReg,tempOperandMaskPtr,selectConstPtr,srcTempFile,tempBReg,emit7Src1Select,selectConstPtr);
    swizzleSelect1 = 1;
    swizzleSelect2 = 5;
    swizzleSelect3 = 4;
    swizzleSelect0 = localViewer;
    deadSrcTempFile = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
    iVarS2 = *(int *)((int)*(int *)((int)programBuilder + 980) + 4836);
    iVarS3 = &swizzleSelect0;
    emit8Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
    emit8Src1Index = tempBReg;
    emit8Src1Select = &swizzleSelect0;
    (**(code **)(((unsigned char *)0x000012e4) + lightRecCursorC))
              (programBuilder,dstTempFile,tempDReg,tempDMask,srcInputReg,*(undefined4 *)(lightRecord + 0x2c),&DAT_001dbd74,selectConstPtr,emit8Src1File,emit8Src1Index,emit8Src1Select,selectConstPtr);
    (**(code **)(((unsigned char *)0x00001314) + lightRecCursorC))
              (programBuilder,dstTempFile,tempDReg,tempDMask,srcTempFile,tempDReg,tempOperandMaskPtr,selectConstPtr);
  }
  if (((unsigned char *)0x0000150c)[lightIndex * 0x6c + lightRecCursorC] == '\0') {
    specTempOperand = tempD;
    if (needsSpecular) {
      if (localViewer == 0) {
        hasSpecularTemp = 1;
      }
      else {
        hasSpecularTemp = 1;
        (**(code **)(((unsigned char *)0x000012e8) + lightRecCursorC))
                  (programBuilder,dstTempFile,tempDReg,tempDMask,srcInputReg,*(undefined4 *)(lightRecord + 0x34),
                   constBase60 + 0x3800,0x000020d4 + (int)constBase64);
      }
    }
    else {
      hasSpecularTemp = 0;
    }
  }
  else {
    allocStatus = ffvpAllocTempRegister(programBuilder,2,tempE);
    if (allocStatus != 0) {
      return 7;
    }
    selectConstPtr = 0x000020d4 + (int)constBase64;
    deadSrcTempFileB = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
    iVarS5 = *(int *)((int)*(int *)((int)programBuilder + 980) + 4836);
    emit11Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
    emit11Src1Index = tempAReg;
    (**(code **)(((unsigned char *)0x000012e4) + lightRecCursorC))
              (programBuilder,dstTempFile,tempEReg,tempEMask,srcInputReg,*(undefined4 *)(lightRecord + 0x28),((unsigned char *)0x00003860) + (int)constBase74,selectConstPtr,emit11Src1File,emit11Src1Index,((unsigned char *)0x00003860) + (int)constBase74,selectConstPtr);
    if (*(float *)(lightIndex * 0x80 + stateBlock + 0x251c) == 0.0) {
      emit12Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
      emit12Src1Index = *(int *)((int)lightRecord + 48);
      emit12Src1Select = (int)constBase60 + 14336;
      (**(code **)(((unsigned char *)0x0000130c) + lightRecCursorC))
                (programBuilder,dstTempFile,tempEReg,tempEMask,srcTempFile,tempEReg,tempESelect0,selectConstPtr,emit12Src1File,emit12Src1Index,emit12Src1Select,selectConstPtr);
    }
    else {
      allocStatus = ffvpAllocTempRegister(programBuilder,2,tempF);
      if (allocStatus != 0) {
        return 7;
      }
      emit13Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
      emit13Src1Index = *(int *)((int)lightRecord + 48);
      emit13Src1Select = (int)constBase60 + 14336;
      (**(code **)(((unsigned char *)0x0000130c) + lightRecCursorC))
                (programBuilder,dstTempFile,tempFReg,tempFMask,srcTempFile,tempEReg,tempESelect0,selectConstPtr,emit13Src1File,emit13Src1Index,emit13Src1Select,selectConstPtr);
      emit14Src1Index = tempFReg;
      emit14Src1Select = &tempFSelect0;
      (**(code **)(((unsigned char *)0x000012ec) + lightRecCursorC))
                (programBuilder,dstTempFile,tempEReg,tempEMask,srcTempFile,tempEReg,tempESelect0,selectConstPtr,srcTempFile,emit14Src1Index,emit14Src1Select,selectConstPtr);
      emit15Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
      emit15Src1Index = *(int *)((int)lightRecord + 56);
      emit15Src1Select = (int)constBase60 + 14336;
      (**(code **)(((unsigned char *)0x00001324) + lightRecCursorC))
                (programBuilder,dstTempFile,tempEReg,tempEMask,srcTempFile,tempEReg,tempESelect0,selectConstPtr,emit15Src1File,emit15Src1Index,emit15Src1Select,selectConstPtr);
      ffvpFreeTempRegister(programBuilder,tempF);
    }
    if (needsSpecular) {
      if (localViewer == 0) {
        emit16Src1Index = tempDReg;
        emit16Src1Select = tempOperandMaskPtr;
        (**(code **)(((unsigned char *)0x000012ec) + lightRecCursorC))
                  (programBuilder,dstTempFile,tempEReg,tempEMask,srcTempFile,tempEReg,tempESelect0,
                   0x000020d4 + (int)constBase64,srcTempFile,emit16Src1Index,emit16Src1Select,0x000020d4 + (int)constBase64);
      }
      else {
        emit17Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
        emit17Src1Index = *(int *)((int)lightRecord + 52);
        emit17Src1Select = (int)constBase60 + 14336;
        (**(code **)(((unsigned char *)0x000012ec) + lightRecCursorC))
                  (programBuilder,dstTempFile,tempEReg,tempEMask,srcTempFile,tempEReg,tempESelect0,
                   0x000020d4 + (int)constBase64,emit17Src1File,emit17Src1Index,emit17Src1Select,0x000020d4 + (int)constBase64);
      }
    }
    specTempOperand = tempE;
    ffvpFreeTempRegister(programBuilder,tempD);
    hasSpecularTemp = 1;
  }
  selectConstPtr = 0x000020d4 + (int)constBase64;
  (**(code **)(((unsigned char *)0x000012e4) + lightRecCursorC))
            (programBuilder,dstTempFile,tempCReg,tempCMask,srcTempFile,tempAReg,((unsigned char *)0x00003860) + (int)constBase74,selectConstPtr,srcTempFile,(*(char *)(lightRecCursorC + 0x128) == '\0' ? (*(char *)(lightRecCursorC + 300) == '\0' ? *(int *)(programBuilder + 0x448) : *(int *)(programBuilder + 0x470)) : *(int *)(programBuilder + 0x498)),((unsigned char *)0x00003860) + (int)constBase74,selectConstPtr);
  ffvpFreeTempRegister(programBuilder,tempBPtr);
  if ((ambientCode != 0) && (ambientCode != 3)) {
    sideIndex = 0;
    noSpecularTemp = hasSpecularTemp == 0;
    builderCursor = programBuilder;
    do {
      colorReg = *(undefined4 *)(builderCursor + 0x5b0);
      colorSrcFile = *(undefined4 *)(builderCursor + 0x64c);
      if (ambientCode == 1) {
        if (noSpecularTemp) {
          emit19Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
          (**(code **)(((unsigned char *)0x000012f0) + lightRecCursorC))
                    (programBuilder,dstTempFile,colorReg,&DAT_001dbd84,colorSrcFile,*(undefined4 *)(builderCursor + 0x650),
                     &DAT_001dbd14,selectConstPtr,emit19Src1File,colorReg,&DAT_001dbd14,selectConstPtr);
        }
        else {
          /* stack words 9-11 of the shared call below: arm A = stock 0x98f18 (words from specTempOperand), arm B = stock 0x99058 (goto below) */
          emit20Src1File = srcTempFile;
          emit20Src1Index = *(int *)((int)specTempOperand + 4);
          emit20Src1Select = (int)specTempOperand + 24;
          colorSrcReg = *(undefined4 *)(builderCursor + 0x650);
LAB_00099084:
          (**(code **)(((unsigned char *)0x000012f4) + lightRecCursorC))
                    (programBuilder,dstTempFile,colorReg,&DAT_001dbd84,colorSrcFile,colorSrcReg,&DAT_001dbd14,selectConstPtr,emit20Src1File,emit20Src1Index,emit20Src1Select,selectConstPtr,srcTempFile,colorReg,&DAT_001dbd14,selectConstPtr);
        }
      }
      else {
        if (noSpecularTemp) {
          emit20Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
          emit20Src1Index = *(int *)((int)lightRecord + 4);
          emit20Src1Select = &DAT_001dbd14;
          colorSrcReg = *(undefined4 *)(builderCursor + 0x650);
          goto LAB_00099084;
        }
        builderColorCursor = ffvpAllocTempRegister(programBuilder,0,tempBPtr);
        if (builderColorCursor != 0) {
          return 7;
        }
        emit21Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
        emit21Src1Index = *(int *)((int)lightRecord + 4);
        (**(code **)(((unsigned char *)0x000012ec) + lightRecCursorC))
                  (programBuilder,dstTempFile,tempBReg,&DAT_001dbd24,colorSrcFile,*(undefined4 *)(builderCursor + 0x650),
                   &DAT_001dbd14,selectConstPtr,emit21Src1File,emit21Src1Index,&DAT_001dbd14,selectConstPtr);
        emit22Src1Index = *(int *)((int)specTempOperand + 4);
        emit22Src1Select = (int)specTempOperand + 24;
        (**(code **)(((unsigned char *)0x000012f4) + lightRecCursorC))
                  (programBuilder,dstTempFile,colorReg,&DAT_001dbd84,srcTempFile,tempBReg,&DAT_001dbd14,selectConstPtr,srcTempFile,emit22Src1Index,emit22Src1Select,selectConstPtr,srcTempFile,colorReg,&DAT_001dbd14,selectConstPtr);
        ffvpFreeTempRegister(programBuilder,tempBPtr);
      }
      sideIndex = sideIndex + 1;
      builderCursor = builderCursor + 0x28;
    } while (sideIndex <= (byte)((unsigned char *)0x00002d48)[stateBlock + 4]);
  }
  tempOperandCursor = tempG;
  sideIndex = 0;
  tempOperandBase = tempOperandCursor;
  do {
    allocStatus = ffvpAllocTempRegister(programBuilder,1,tempOperandCursor);
    if (allocStatus != 0) {
      return 7;
    }
    sideIndex = sideIndex + 1;
    tempOperandCursor = tempOperandCursor + 0x28;
  } while (sideIndex <= (byte)((unsigned char *)0x00002d48)[stateBlock + 4]);
  if (noSpecularSource) {
    do {
      sideIndex = 0;
      tempRegCursor = &tempGReg;
      do {
        sideOffset = sideIndex * 0x28;
        sideIndex = sideIndex + 1;
        emit23Src1Select = ((unsigned char *)tempCMask + 16);
        emit23Src2Select = &DAT_001dbdb4;
        (**(code **)(((unsigned char *)0x0000132c) + lightRecCursorC))
                  (programBuilder,dstTempFile,*tempRegCursor,tempOperandBase + sideOffset + 8,srcTempFile,tempCReg,&DAT_001dbd34,
                   0x000020d4 + (int)constBase64,srcTempFile,tempCReg,emit23Src1Select,(sideIndex == 1 ? (0x000020d4 + (int)constBase64) : ((int)constBase80 + 14464)),srcTempFile,tempCReg,emit23Src2Select,0x000020d4 + (int)constBase64);
        if ((byte)((unsigned char *)0x00002d48)[stateBlock + 4] < sideIndex) goto LAB_000994dc;
        tempRegCursor = tempRegCursor + 10;
      } while (sideIndex != 0);
    } while( true );
  }
  allocStatus = ffvpAllocTempRegister(programBuilder,2,tempBPtr);
  if (allocStatus == 0) {
    tempOperandPtrB = tempF;
    allocStatus = ffvpAllocTempRegister(programBuilder,2,tempOperandPtrB);
    if (allocStatus == 0) {
      if (((unsigned char *)0x00002d48)[stateBlock + 5] == '\0') {
        swizzleSelect0 = 4;
        swizzleSelect1 = 4;
        swizzleSelect3 = 4;
        swizzleSelect2 = 5;
        iVarS8 = *(int *)((int)*(int *)((int)programBuilder + 980) + 4848);
        emit24Src1Select = &swizzleSelect0;
        (**(code **)(((unsigned char *)0x000012f0) + lightRecCursorC))
                  (programBuilder,dstTempFile,tempGReg,tempGMask,srcTempFile,tempAReg,constBase60 + 0x3800,0x000020d4 + (int)constBase64,srcTempFile,tempAReg,emit24Src1Select,0x000020d4 + (int)constBase64);
      }
      else {
        if ((*(int *)(programBuilder + 0x420) == -1) &&
           (ffvpEmitEyeVector(programBuilder), *(int *)(programBuilder + 0x420) == -1)) {
          return 2;
        }
        emit25Src1Index = *(int *)((int)programBuilder + 1056);
        emit25Src1Negate = (int)constBase80 + 14464;
        (**(code **)(((unsigned char *)0x000012f0) + lightRecCursorC))
                  (programBuilder,dstTempFile,tempGReg,tempGMask,srcTempFile,tempAReg,constBase60 + 0x3800,
                   0x000020d4 + (int)constBase64,srcTempFile,emit25Src1Index,constBase60 + 0x3800,emit25Src1Negate);
      }
      selectConstPtr = 0x000020d4 + (int)constBase64;
      (**(code **)(((unsigned char *)0x000012e4) + lightRecCursorC))
                (programBuilder,dstTempFile,tempBReg,tempBMask,srcTempFile,tempGReg,tempGSelect0,selectConstPtr,srcTempFile,tempGReg,tempGSelect0,selectConstPtr);
      iVarS6 = *(int *)((int)*(int *)((int)programBuilder + 980) + 4836);
      emit27Src1Select = (int)constBase74 + 14432;
      (**(code **)(((unsigned char *)0x000012e4) + lightRecCursorC))
                (programBuilder,dstTempFile,tempFReg,tempFMask,srcTempFile,tempGReg,tempGSelect0,selectConstPtr,srcTempFile,(*(char *)(lightRecCursorC + 0x128) == '\0' ? (*(char *)(lightRecCursorC + 300) == '\0' ? *(int *)(programBuilder + 0x448) : *(int *)(programBuilder + 0x470)) : *(int *)(programBuilder + 0x498)),emit27Src1Select,selectConstPtr);
      (**(code **)(((unsigned char *)0x00001318) + lightRecCursorC))
                (programBuilder,dstTempFile,tempBReg,tempBMask,srcTempFile,tempBReg,tempBSelect0,selectConstPtr);
      emit29Src1Select = &tempBSelect0;
      (**(code **)(((unsigned char *)0x000012ec) + lightRecCursorC))
                (programBuilder,dstTempFile,tempBReg,tempBMask,srcTempFile,tempFReg,tempFSelect0,selectConstPtr,srcTempFile,tempBReg,emit29Src1Select,selectConstPtr);
      do {
        sideIndex = 0;
        selectConstPtr = 0x000020d4 + (int)constBase64;
        lightRecCursorE = (undefined4 *)(lightRecCursorC + 0x290);
        selectPtr = &tempGReg;
        do {
          ffvpResolveFixedSource(programBuilder,*lightRecCursorE,&sourceFile,&sourceReg,&sourceSelect0);
          sideOffset = sideIndex * 0x28;
          sideIndex = sideIndex + 1;
          emit30Src1Index = tempCReg;
          emit30Src1Select = ((unsigned char *)tempCMask + 16);
          emit30Src2File = sourceFile;
          emit30Src2Index = sourceReg;
          emit30Src2Select = &sourceSelect0;
          emit30Src2Negate = (int)constBase64 + 8404;
          (**(code **)(((unsigned char *)0x0000132c) + lightRecCursorC))
                    (programBuilder,dstTempFile,*selectPtr,tempOperandBase + sideOffset + 8,srcTempFile,tempBReg,tempBSelect0,selectConstPtr,srcTempFile,emit30Src1Index,emit30Src1Select,selectConstPtr,emit30Src2File,emit30Src2Index,emit30Src2Select,emit30Src2Negate);
          if ((byte)((unsigned char *)0x00002d48)[stateBlock + 4] < sideIndex) {
            ffvpFreeTempRegister(programBuilder,tempBPtr);
            ffvpFreeTempRegister(programBuilder,tempOperandPtrB);
LAB_000994dc:
            lightRecCursorE = &tempGReg;
            constBase98 = KhanVs__deleting_dtor_1d8514;
            constBase94 = KhanVs__deleting_dtor_1d8514;
            hasSpecularTempB = hasSpecularTemp != 0;
            constBase8c = KhanVs__deleting_dtor_1d8514;
            notFirstLight = iStack00000020 == 0;
            glSeparateSpecular = 0x81fa;
            sideCounter = 0;
            constBase90 = KhanVs__deleting_dtor_1d8514;
            tempOperandCursor = tempOperandBase + 8;
            constBase88 = KhanVs__deleting_dtor_1d8514;
            lightRecCursorD = lightRecCursorC;
            builderColorCursor = programBuilder;
            builderSideCursorB = programBuilder;
            lightRecCursorCB = lightRecord;
            do {
              if (hasSpecularTempB) {
                emit31Src1Select = &DAT_001dbd14;
                (**(code **)(((unsigned char *)0x000012ec) + lightRecCursorC))
                          (programBuilder,dstTempFile,*lightRecCursorE,tempOperandCursor,srcTempFile,*(undefined4 *)(specTempOperand + 4),
                           specTempOperand + 0x18,&DAT_001fa5e8,srcTempFile,*lightRecCursorE,emit31Src1Select,&DAT_001fa5e8);
              }
              if (noSpecularSource) {
                if (((!notFirstLight) && (*(char *)(lightRecCursorC + 0x12d) != '\0')) &&
                   (*(ushort *)(((unsigned char *)0x00002d48) + stateBlock) == glSeparateSpecular)) {
                  emit32Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
                  emit32Src1Index = *(int *)((int)lightRecCursorE + 0);
                  emit32Src1Select = &DAT_001dbcf4;
                  (**(code **)(((unsigned char *)0x000012ec) + lightRecCursorC))
                            (programBuilder,dstTempFile,*(undefined4 *)(builderSideCursorB + 0x600),
                             ((unsigned char *)0x00003870) + (int)constBase98,srcTempFile,*(undefined4 *)(builderSideCursorB + 0x600),
                             constBase60 + 0x3800,&DAT_001fa5e8,emit32Src1File,emit32Src1Index,emit32Src1Select,&DAT_001fa5e8);
                }
              }
              else {
                colorReg = *(undefined4 *)(builderSideCursorB + 0x600);
                if (*(int *)(lightRecCursorCB + 0x18) == -1) {
                  ffvpResolveMaterialSource(programBuilder,*(undefined4 *)(lightRecCursorD + 0x288),3,&sourceFile,&sourceReg);
                }
                if (specularCode == 1) {
                  srcFile = sourceFile;
                  srcReg = sourceReg;
                  if ((!notFirstLight) && (*(ushort *)(((unsigned char *)0x00002d48) + stateBlock) == glSeparateSpecular))
                  goto LAB_0009966c;
LAB_000996c0:
                  (**(code **)(((unsigned char *)0x000012f4) + lightRecCursorC))
                            (programBuilder,dstTempFile,colorReg,((unsigned char *)0x00003870) + (int)constBase98,srcFile,srcReg,
                             &DAT_001dbd14,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)programBuilder + 1004) + 0)),(*(int *)((int)lightRecCursorE + 0)),(&DAT_001dbcf4),&DAT_001fa5e8,(*(int *)((int)*(int *)((int)programBuilder + 1004) + 0)),colorReg,(&DAT_001dbd14),&DAT_001fa5e8);
                }
                else {
                  srcReg = *(int *)(lightRecCursorCB + 0x18);
                  if (srcReg == -1) {
                    allocStatusB = ffvpAllocTempRegister(programBuilder,1,tempBPtr);
                    if (allocStatusB != 0) {
                      return 7;
                    }
                    if (srcInputReg == sourceFile) {
                      emit34Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
                      emit34Src1Index = *(int *)((int)lightRecCursorE + 0);
                      emit34Src1Select = &DAT_001dbcf4;
                      emit34Src1Negate = &DAT_001fa5e8;
                      (**(code **)(((unsigned char *)0x000012ec) + lightRecCursorC))
                                (programBuilder,dstTempFile,tempBReg,&DAT_001dbd84,srcInputReg,sourceReg,&DAT_001dbd14,
                                 &DAT_001fa5e8,emit34Src1File,emit34Src1Index,emit34Src1Select,emit34Src1Negate);
                      if ((notFirstLight) || (*(ushort *)(((unsigned char *)0x00002d48) + stateBlock) != glSeparateSpecular)) {
                        lightSrcFile = *(undefined4 *)(lightRecord + 0x14);
                        selectPtr = &DAT_001dbd14;
                        srcFile = srcInputReg;
                        goto LAB_00099980;
                      }
                      lightSrcFile = *(undefined4 *)(lightRecord + 0x14);
                      selectPtr = &DAT_001dbd14;
                      srcFile = srcInputReg;
LAB_0009991c:
                      (**(code **)(((unsigned char *)0x000012ec) + lightRecCursorC))
                                (programBuilder,dstTempFile,colorReg,&DAT_001dbd84,srcFile,lightSrcFile,selectPtr,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)programBuilder + 1004) + 0)),(tempBReg),&DAT_001dbd14,&DAT_001fa5e8)
                      ;
                    }
                    else {
                      emit36Src1File = sourceFile;
                      emit36Src1Index = sourceReg;
                      emit36Src1Select = &DAT_001dbd14;
                      emit36Src1Negate = &DAT_001fa5e8;
                      (**(code **)(((unsigned char *)0x000012ec) + lightRecCursorC))
                                (programBuilder,dstTempFile,tempBReg,&DAT_001dbd84,srcInputReg,
                                 *(undefined4 *)(lightRecord + 0x14),&DAT_001dbd14,&DAT_001fa5e8,emit36Src1File,emit36Src1Index,emit36Src1Select,emit36Src1Negate);
                      if ((!notFirstLight) && (*(ushort *)(((unsigned char *)0x00002d48) + stateBlock) == glSeparateSpecular)) {
                        lightSrcFile = *lightRecCursorE;
                        selectPtr = (undefined4 *)(((unsigned char *)0x000037e0) + (int)constBase94);
                        srcFile = srcTempFile;
                        goto LAB_0009991c;
                      }
                      lightSrcFile = *lightRecCursorE;
                      selectPtr = (undefined4 *)(((unsigned char *)0x000037e0) + (int)constBase94);
                      srcFile = srcTempFile;
LAB_00099980:
                      (**(code **)(((unsigned char *)0x000012f4) + lightRecCursorC))
                                (programBuilder,dstTempFile,colorReg,&DAT_001dbd84,srcFile,lightSrcFile,selectPtr,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)programBuilder + 1004) + 0)),(tempBReg),&DAT_001dbd14,&DAT_001fa5e8,(*(int *)((int)*(int *)((int)programBuilder + 1004) + 0)),colorReg,&DAT_001dbd14,&DAT_001fa5e8)
                      ;
                    }
                    ffvpFreeTempRegister(programBuilder,tempBPtr);
                  }
                  else {
                    srcFile = srcInputReg;
                    if ((notFirstLight) || (*(ushort *)(((unsigned char *)0x00002d48) + stateBlock) != glSeparateSpecular))
                    goto LAB_000996c0;
LAB_0009966c:
                    (**(code **)(((unsigned char *)0x000012ec) + lightRecCursorC))
                              (programBuilder,dstTempFile,colorReg,((unsigned char *)0x00003870) + (int)constBase98,srcFile,srcReg,
                               constBase60 + 0x3800,&DAT_001fa5e8,srcFile,colorReg,(&DAT_001dbd34),&DAT_001fa5e8);
                  }
                }
              }
              if (diffuseCode == 0) {
                if (iStack00000024 != 0) {
                  outputFileC = *(undefined4 *)(builderColorCursor + 0x74);
                  colorReg = *(undefined4 *)(builderSideCursorB + 0x5b0);
                  outputRegC = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0xc);
                  ffvpResolveMaterialSource(programBuilder,*(undefined4 *)(lightRecCursorD + 0x280),2,&sourceFile,&sourceReg);
                  sourceSelect3 = 3;
                  sourceSelect2 = 5;
                  sourceSelect0 = 5;
                  sourceSelect1 = 5;
                  emit39Src1File = sourceFile;
                  emit39Src1Index = sourceReg;
                  emit39Src1Select = &sourceSelect0;
                  (**(code **)(((unsigned char *)0x000012ec) + lightRecCursorC))
                            (programBuilder,outputRegC,outputFileC,((unsigned char *)0x00003810) + (int)constBase90,srcTempFile,colorReg,
                             ((unsigned char *)0x000038b0) + (int)constBase88,&DAT_001fa5e8,emit39Src1File,emit39Src1Index,emit39Src1Select,&DAT_001fa5e8);
                }
              }
              else {
                colorReg = *(undefined4 *)(builderSideCursorB + 0x5b0);
                if (iStack00000024 == 0) {
                  outputFileD = **(undefined4 **)(programBuilder + 0x3f0);
                  dstMaskPtr = ((unsigned char *)0x00003870) + (int)constBase98;
                }
                else {
                  colorReg = *(undefined4 *)(builderColorCursor + 0x74);
                  outputFileD = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0xc);
                  dstMaskPtr = ((unsigned char *)0x00003810) + (int)constBase90;
                }
                if (*(int *)(lightRecCursorCB + 0xc) == -1) {
                  ffvpResolveMaterialSource(programBuilder,*(undefined4 *)(lightRecCursorD + 0x280),2,&sourceFile,&sourceReg);
                }
                srcFile = sourceFile;
                srcReg = sourceReg;
                if ((diffuseCode == 1) ||
                   (srcFile = srcInputReg, srcReg = *(int *)(lightRecCursorCB + 0xc), *(int *)(lightRecCursorCB + 0xc) != -1)) {
                  srcTempFileArgB = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
                  emit40Src1Index = *(int *)((int)lightRecCursorE + 0);
                  emit40Src1Select = ((unsigned char *)&DAT_001dbdc0 + 44);
                  emit40Src2Index = *(int *)((int)builderSideCursorB + 1456);
                  emit40Src2Select = &DAT_001dbd74;
                  (**(code **)(((unsigned char *)0x000012f4) + lightRecCursorC))
                            (programBuilder,outputFileD,colorReg,dstMaskPtr,srcFile,srcReg,constBase60 + 0x3800,
                             &DAT_001fa5e8,srcTempFileArgB,emit40Src1Index,emit40Src1Select,&DAT_001fa5e8,srcTempFileArgB,emit40Src2Index,emit40Src2Select,&DAT_001fa5e8);
                }
                else {
                  allocStatusB = ffvpAllocTempRegister(programBuilder,0,tempBPtr);
                  if (allocStatusB != 0) {
                    return 7;
                  }
                  if (srcInputReg == sourceFile) {
                    emit41Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
                    emit41Src1Index = *(int *)((int)lightRecCursorE + 0);
                    emit41Src1Select = ((unsigned char *)&DAT_001dbdc0 + 44);
                    (**(code **)(((unsigned char *)0x000012ec) + lightRecCursorC))
                              (programBuilder,dstTempFile,tempBReg,dstMaskPtr,srcInputReg,sourceReg,&DAT_001dbd14,
                               &DAT_001fa5e8,emit41Src1File,emit41Src1Index,emit41Src1Select,&DAT_001fa5e8);
                    lightSrcReg = *(undefined4 *)(lightRecord + 8);
                    src0SelectPtr = ((unsigned char *)0x000038b0) + (int)constBase88;
                    srcFile = srcInputReg;
                  }
                  else {
                    emit42Src1File = sourceFile;
                    emit42Src1Index = sourceReg;
                    emit42Src1Select = &DAT_001dbd14;
                    (**(code **)(((unsigned char *)0x000012ec) + lightRecCursorC))
                              (programBuilder,dstTempFile,tempBReg,dstMaskPtr,srcInputReg,*(undefined4 *)(lightRecord + 8),
                               ((unsigned char *)0x000038b0) + (int)constBase88,&DAT_001fa5e8,emit42Src1File,emit42Src1Index,emit42Src1Select,&DAT_001fa5e8);
                    lightSrcReg = *lightRecCursorE;
                    src0SelectPtr = ((unsigned char *)0x000038d8) + (int)constBase8c;
                    srcFile = srcTempFile;
                  }
                  srcTempFileArgC = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
                  emit43Src1Index = tempBReg;
                  emit43Src2Index = *(int *)((int)builderSideCursorB + 1456);
                  (**(code **)(((unsigned char *)0x000012f4) + lightRecCursorC))
                            (programBuilder,outputFileD,colorReg,dstMaskPtr,srcFile,lightSrcReg,src0SelectPtr,&DAT_001fa5e8,srcTempFileArgC,emit43Src1Index,&DAT_001dbd14,&DAT_001fa5e8,srcTempFileArgC,emit43Src2Index,&DAT_001dbd74,&DAT_001fa5e8);
                  ffvpFreeTempRegister(programBuilder,tempBPtr);
                }
              }
              tempOperandCursorB = tempOperandBase;
              tempOperandCursor = tempOperandCursor + 0x28;
              lightRecCursorE = lightRecCursorE + 10;
              builderColorCursor = builderColorCursor + 4;
              builderSideCursorB = builderSideCursorB + 0x28;
              lightRecCursorD = lightRecCursorD + 4;
              lightRecCursorCB = lightRecCursorCB + 4;
              sideCounter = sideCounter + 1;
              if ((byte)((unsigned char *)0x00002d48)[stateBlock + 4] < sideCounter) {
                sideIndex = 0;
                ffvpFreeTempRegister(programBuilder,tempAPtr);
                ffvpFreeTempRegister(programBuilder,tempCPtr);
                ffvpFreeTempRegister(programBuilder,specTempOperand);
                do {
                  sideIndex = sideIndex + 1;
                  ffvpFreeTempRegister(programBuilder,tempOperandCursorB);
                  tempOperandCursorB = tempOperandCursorB + 0x28;
                } while (sideIndex <= (byte)((unsigned char *)0x00002d48)[stateBlock + 4]);
                return 0;
              }
            } while( true );
          }
          lightRecCursorE = lightRecCursorE + 1;
          selectPtr = selectPtr + 10;
          selectConstPtr = (code *)(((unsigned char *)0x00003880) + (int)constBase80);
        } while (sideIndex != 0);
      } while( true );
    }
  }
  return 7;
}

/* ffvpEmitPointSizeAttenuation @ 0x99e50 (1796 bytes) */
int ffvpEmitPointSizeAttenuation(programBuilder, sizeSource, useDistanceSquared)
  int programBuilder;
  uint sizeSource;
  int useDistanceSquared;
{
  undefined4 attenParamReg;
  undefined4 srcTempFile;
  int invEyeDistReg;
  int allocStatus;
  bool usesEyeDistance;
  bool clampMinMax;
  int attenParamRegCheck;
  undefined4 *fileTable;
  undefined4 status;
  undefined4 sizeParamReg;
  undefined4 dstTempFile;
  undefined4 constFile;
  undefined4 a4_00;
  int glCtx;
  undefined4 sizeSrcReg;
  undefined4 selectArrA0;
  undefined4 selectArrA1;
  undefined4 selectArrA2;
  undefined4 selectArrA3;
  undefined4 selectArrB0;
  int selectArrB1;
  undefined4 selectArrB2;
  undefined4 selectArrB3;
  undefined4 selectArrC0;
  undefined4 selectArrC1;
  int selectArrC2;
  int selectArrC3;
  undefined4 selectArrD0;
  undefined4 selectArrD1;
  undefined4 selectArrD2;
  undefined4 selectArrD3;
  undefined4 selectArrE0;
  undefined4 selectArrE1;
  undefined4 selectArrE2;
  undefined4 selectArrE3;
  undefined1 tempB [4];
  undefined4 tempBReg;
  undefined1 tempBMask [32];
  undefined1 tempA [4];
  undefined4 tempAReg;
  undefined1 tempAMask [16];
  undefined4 tempASelect0;
  undefined4 tempASelect1;
  undefined4 tempASelect2;
  undefined4 tempASelect3;
  undefined4 pointSizeOutFile;
  int deadSrcTempFile;
  int deadEmitFnSlot;
  int deadSrcTempFileB;
  int deadEmitFnSlotB;
  int deadSelectPtr;
  int iVarS6;
  int deadEmitFn12ec;
  int deadSelectConst;
  int deadSelectPtrB;
  int iVarS10;
  int iVarS11;
  int iVarS12;
  int iVarS13;
  int iVarS14;
  int emit1Src1File;
  int emit1Src1Index;
  int emit1Src1Select;
  int emit2Src1Index;
  int emit2Src1Select;
  int emit3Src1File;
  int emit3Src1Index;
  int emit3Src1Select;
  int emit4Src1File;
  int emit4Src1Index;
  int emit4Src1Select;
  
  if (programBuilder == 0) {
    return 1;
  }
  status = 4;
  switch(sizeSource) {
  case 0:
    if (*(int *)(programBuilder + 0x4c) == -1) {
      return 2;
    }
  case 2:
    attenParamRegCheck = *(int *)(programBuilder + 0x334);
    break;
  case 1:
    attenParamRegCheck = *(int *)(programBuilder + 0x4c);
    break;
  case 3:
    if (*(int *)(programBuilder + 0x4c) == -1) {
      return 2;
    }
  case 4:
    attenParamRegCheck = *(int *)(programBuilder + 0x334);
    goto joined_r0x00099f10;
  default:
    goto switchD_00099ea8_default;
  }
  if (attenParamRegCheck == -1) {
    return 2;
  }
  attenParamRegCheck = *(int *)(programBuilder + 0x338);
joined_r0x00099f10:
  if (attenParamRegCheck == -1) {
    return 2;
  }
  if (*(int *)(programBuilder + 0x340) == -1) {
    return 2;
  }
  if (*(int *)(programBuilder + 0x6c) == -1) {
    return 2;
  }
  glCtx = *(int *)(programBuilder + 0x3d4);
  allocStatus = ffvpAllocTempRegister(programBuilder,2,tempA);
  usesEyeDistance = sizeSource < 3;
  if (allocStatus != 0) {
    return 7;
  }
  if ((usesEyeDistance) && (allocStatus = ffvpAllocTempRegister(programBuilder,1,tempB), allocStatus != 0)) {
    return 7;
  }
  fileTable = *(undefined4 **)(programBuilder + 0x3ec);
  pointSizeOutFile = (*(undefined4 **)(programBuilder + 0x3f0))[7];
  constFile = fileTable[2];
  dstTempFile = **(undefined4 **)(programBuilder + 0x3f0);
  srcTempFile = *fileTable;
  a4_00 = fileTable[1];
  if (sizeSource == 0) {
    iVarS6 = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
    deadEmitFn12ec = *(int *)((int)*(int *)((int)programBuilder + 980) + 4844);
    deadSelectConst = &DAT_001dbcf4;
    emit1Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 8);
    emit1Src1Index = *(int *)((int)programBuilder + 820);
    emit1Src1Select = &DAT_001dbcf4;
    (**(code **)(((unsigned char *)0x000012ec) + glCtx))
              (programBuilder,dstTempFile,tempBReg,&DAT_001dbd54,a4_00,*(undefined4 *)(programBuilder + 0x4c),&DAT_001fa5f8,&DAT_001fa5e8,emit1Src1File,emit1Src1Index,emit1Src1Select,&DAT_001fa5e8);
  }
  if (usesEyeDistance) {
    if ((*(int *)(programBuilder + 0x510) == -1) &&
       (ffvpEmitEyeDistanceSquared(programBuilder), *(int *)(programBuilder + 0x510) == -1)) {
      return 2;
    }
    sizeParamReg = *(undefined4 *)(programBuilder + 0x338);
    if (useDistanceSquared == 0) {
      invEyeDistReg = *(int *)(programBuilder + 0x538);
      if (invEyeDistReg == -1) {
        ffvpEmitInverseEyeDistance(programBuilder);
        invEyeDistReg = *(int *)(programBuilder + 0x538);
        if (invEyeDistReg == -1) {
          return 2;
        }
      }
      selectArrC0 = 1;
      selectArrC1 = 1;
      selectArrB2 = 4;
      selectArrB3 = 4;
      selectArrB1 = 5;
      selectArrB0 = *(undefined4 *)(programBuilder + 0x54c);
      selectArrC2 = useDistanceSquared;
      selectArrC3 = useDistanceSquared;
      deadSelectPtrB = &tempAMask;
      iVarS10 = (int)programBuilder + 1316;
      emit2Src1Index = *(int *)((int)programBuilder + 1296);
      emit2Src1Select = (int)programBuilder + 1316;
      (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                (programBuilder,dstTempFile,tempBReg,&selectArrC0,srcTempFile,invEyeDistReg,&selectArrB0,&DAT_001fa5e8,srcTempFile,emit2Src1Index,emit2Src1Select,&DAT_001fa5e8);
      selectArrB0 = 1;
      selectArrB2 = 5;
      selectArrB3 = 4;
      selectArrB1 = useDistanceSquared;
      deadSrcTempFile = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
      deadEmitFnSlot = *(int *)((int)*(int *)((int)programBuilder + 980) + 4836);
      emit3Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
      emit3Src1Index = tempBReg;
      emit3Src1Select = &selectArrB0;
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                (programBuilder,dstTempFile,tempAReg,tempAMask,constFile,sizeParamReg,&DAT_001dbd74,&DAT_001fa5e8,emit3Src1File,emit3Src1Index,emit3Src1Select,&DAT_001fa5e8);
    }
    else {
      selectArrB0 = *(undefined4 *)(programBuilder + 0x524);
      selectArrB2 = 5;
      selectArrB3 = 4;
      selectArrB1 = 4;
      deadSrcTempFileB = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
      deadEmitFnSlotB = *(int *)((int)*(int *)((int)programBuilder + 980) + 4836);
      deadSelectPtr = &selectArrB0;
      emit4Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
      emit4Src1Index = *(int *)((int)programBuilder + 1296);
      emit4Src1Select = &selectArrB0;
      (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                (programBuilder,dstTempFile,tempAReg,tempAMask,constFile,sizeParamReg,&DAT_001dbd74,&DAT_001fa5e8,emit4Src1File,emit4Src1Index,emit4Src1Select,&DAT_001fa5e8);
    }
    (**(code **)(((unsigned char *)0x00001318) + glCtx))
              (programBuilder,dstTempFile,tempAReg,tempAMask,srcTempFile,tempAReg,&tempASelect0,&DAT_001fa5e8);
  }
  attenParamReg = tempAReg;
  switch(sizeSource) {
  case 0:
    clampMinMax = false;
    selectArrD0 = DAT_001dbcf4;
    selectArrD1 = DAT_001dbcf8;
    selectArrA1 = tempASelect1;
    selectArrD2 = DAT_001dbcfc;
    selectArrD3 = DAT_001dbd00;
    selectArrA0 = tempASelect0;
    selectArrA3 = tempASelect3;
    selectArrA2 = tempASelect2;
    a4_00 = srcTempFile;
    sizeSrcReg = tempBReg;
    break;
  case 1:
    sizeSrcReg = *(undefined4 *)(programBuilder + 0x4c);
    clampMinMax = false;
    selectArrD0 = DAT_001fa5f8;
    selectArrD1 = DAT_001fa5fc;
    selectArrA1 = tempASelect1;
    selectArrD2 = DAT_001fa600;
    selectArrD3 = DAT_001fa604;
    selectArrA0 = tempASelect0;
    selectArrA3 = tempASelect3;
    selectArrA2 = tempASelect2;
    break;
  case 2:
    selectArrD1 = tempASelect1;
    selectArrD0 = tempASelect0;
    selectArrD3 = tempASelect3;
    selectArrD2 = tempASelect2;
    goto LAB_0009a3bc;
  case 3:
    tempAReg = *(undefined4 *)(programBuilder + 0x4c);
    selectArrD0 = DAT_001fa5f8;
    selectArrD3 = DAT_001fa604;
    selectArrD1 = DAT_001fa5fc;
    selectArrD2 = DAT_001fa600;
    srcTempFile = a4_00;
    goto LAB_0009a3bc;
  case 4:
    tempAReg = *(undefined4 *)(programBuilder + 0x340);
    selectArrD0 = DAT_001dbdb4;
    selectArrD3 = DAT_001dbdc0;
    selectArrD1 = DAT_001dbdb8;
    selectArrD2 = DAT_001dbdbc;
    srcTempFile = constFile;
LAB_0009a3bc:
    clampMinMax = true;
    selectArrA0 = DAT_001dbcf4;
    selectArrA1 = DAT_001dbcf8;
    selectArrA2 = DAT_001dbcfc;
    selectArrA3 = DAT_001dbd00;
    a4_00 = srcTempFile;
    sizeSrcReg = tempAReg;
    srcTempFile = constFile;
    attenParamReg = *(undefined4 *)(programBuilder + 0x334);
    break;
  default:
    clampMinMax = false;
    a4_00 = 0;
    sizeSrcReg = 0;
    srcTempFile = 0;
    attenParamReg = 0;
  }
  if (usesEyeDistance) {
    ffvpFreeTempRegister(programBuilder,tempB);
  }
  selectArrE0 = 0;
  selectArrE2 = 4;
  selectArrE1 = 4;
  selectArrE3 = 1;
  if (clampMinMax) {
    allocStatus = ffvpAllocTempRegister(programBuilder,2,tempB);
    if (allocStatus != 0) {
      return 7;
    }
    (**(code **)(((unsigned char *)0x000012e8) + glCtx))
              (programBuilder,dstTempFile,tempBReg,tempBMask,srcTempFile,attenParamReg,&selectArrA0,&DAT_001fa5e8);
    /* stack words, stock 0x9a468-0x9a4a8: r20 = rec[0], tempBReg, &local_90 (= tempBMask + 16), &DAT_001fa5e8, r17 = rec[2] (constFile), *(programBuilder + 0x340), &selectArrE0, &DAT_001fa5e8 */
    (**(code **)(((unsigned char *)0x000012fc) + glCtx))
              (programBuilder,pointSizeOutFile,*(undefined4 *)(programBuilder + 0x6c),&DAT_001dbd24,a4_00,sizeSrcReg,&selectArrD0,
               &DAT_001fa5e8,**(int **)(programBuilder + 0x3ec),tempBReg,tempBMask + 16,&DAT_001fa5e8,constFile,*(int *)(programBuilder + 0x340),&selectArrE0,&DAT_001fa5e8);
    ffvpFreeTempRegister(programBuilder,tempB);
  }
  else {
    /* stack words, stock 0x9a4d8-0x9a520: uVar5, uVar6 (the stock's r27/r28), &selectArrA0, &DAT_001fa5e8, r17 = rec[2] (constFile), *(programBuilder + 0x340), &selectArrE0, &DAT_001fa5e8 */
    (**(code **)(((unsigned char *)0x000012fc) + glCtx))
              (programBuilder,pointSizeOutFile,*(undefined4 *)(programBuilder + 0x6c),&DAT_001dbd24,a4_00,sizeSrcReg,&selectArrD0,
               &DAT_001fa5e8,srcTempFile,attenParamReg,&selectArrA0,&DAT_001fa5e8,constFile,*(int *)(programBuilder + 0x340),&selectArrE0,&DAT_001fa5e8);
  }
  ffvpFreeTempRegister(programBuilder,tempA);
  status = 0;
switchD_00099ea8_default:
  return status;
}

/* ffvpEmitFogDistance @ 0x9a590 (848 bytes) */
int ffvpEmitFogDistance(programBuilder)
  int programBuilder;
{
  int allocStatus;
  uint fogCoordComponents;
  undefined4 *src0Select;
  int stateBlock;
  undefined4 dstTempFile;
  undefined4 srcTempFile;
  undefined4 outputFile;
  int fogOutReg;
  int glCtx;
  int eyePositionReg;
  undefined1 tempA [4];
  undefined4 tempAReg;
  int emit5Src1Select;
  int emit1Src1Negate;
  
  if (programBuilder == 0) {
    return 1;
  }
  fogOutReg = *(int *)(programBuilder + 0x70);
  if (fogOutReg != -1) {
    glCtx = *(int *)(programBuilder + 0x3d4);
    outputFile = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0x18);
    if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(glCtx + 4) + 0x10)) == -0x7bae) {
      eyePositionReg = *(int *)(programBuilder + 0x3f8);
      if (eyePositionReg == -1) {
        if ((*(uint *)(((unsigned char *)0x000013c0) + glCtx) & 4) == 0) {
          ffvpEmitEyePositionDp4(programBuilder);
        }
        else {
          ffvpEmitEyePositionMad(programBuilder);
        }
        eyePositionReg = *(int *)(programBuilder + 0x3f8);
        if (eyePositionReg == -1) {
          return 2;
        }
        glCtx = *(int *)(programBuilder + 0x3d4);
      }
      stateBlock = *(int *)(*(int *)(glCtx + 4) + 0x10);
      srcTempFile = **(undefined4 **)(programBuilder + 0x3ec);
      if ((*(short *)(((unsigned char *)0x00002e06) + stateBlock) != -0x7bae) ||
         (*(short *)(((unsigned char *)0x00002e08) + stateBlock) == -0x7aa4)) {
        emit1Src1Negate = &DAT_001dbd94;
        (**(code **)(((unsigned char *)0x00001304) + glCtx))
                  (programBuilder,outputFile,fogOutReg,&DAT_001dbd04,srcTempFile,eyePositionReg,&DAT_001dbcf4,&DAT_001fa5e8,srcTempFile,eyePositionReg,&DAT_001dbcf4,emit1Src1Negate);
        return 0;
      }
      if (*(short *)(((unsigned char *)0x00002e08) + stateBlock) != -0x7aa5) {
        (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                  (programBuilder,outputFile,fogOutReg,&DAT_001dbd04,srcTempFile,eyePositionReg,&DAT_001dbcf4,&DAT_001dbd94);
        return 0;
      }
      dstTempFile = **(undefined4 **)(programBuilder + 0x3f0);
      allocStatus = ffvpAllocTempRegister(programBuilder,1,tempA);
      if (allocStatus == 0) {
        (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                  (programBuilder,dstTempFile,tempAReg,&DAT_001dbd04,srcTempFile,eyePositionReg,&DAT_001dbd74,&DAT_001fa5e8,srcTempFile,eyePositionReg,&DAT_001dbd74,&DAT_001fa5e8);
        (**(code **)(((unsigned char *)0x00001318) + glCtx))
                  (programBuilder,dstTempFile,tempAReg,&DAT_001dbd64,srcTempFile,tempAReg,&DAT_001fa5f8,&DAT_001fa5e8);
        emit5Src1Select = ((unsigned char *)&DAT_001dbdc0 + 244);
        (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                  (programBuilder,outputFile,fogOutReg,&DAT_001dbd04,srcTempFile,tempAReg,&DAT_001dbec4,&DAT_001fa5e8,srcTempFile,tempAReg,emit5Src1Select,&DAT_001fa5e8);
        ffvpFreeTempRegister(programBuilder,tempA);
        return 0;
      }
      return 7;
    }
    if (*(int *)(programBuilder + 0x50) != -1) {
      fogCoordComponents = *(uint *)(programBuilder + 0x54);
      if (fogCoordComponents < 4) {
        if (fogCoordComponents == 2) {
          src0Select = &DAT_001dbcf4;
        }
        else if (fogCoordComponents == 3) {
          src0Select = &DAT_001dbcd4;
        }
        else if (fogCoordComponents == 1) {
          src0Select = &DAT_001dbce4;
        }
        else {
          src0Select = &DAT_001fa5f8;
        }
        (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                  (programBuilder,outputFile,fogOutReg,&DAT_001dbd04,*(undefined4 *)(*(int *)(programBuilder + 0x3ec) + 4),
                   *(int *)(programBuilder + 0x50),src0Select,&DAT_001fa5e8);
        return 0;
      }
      return 3;
    }
  }
  return 2;
}

/* ffvpFinishProgram @ 0x9a910 (120 bytes) */
int ffvpFinishProgram(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  if (*(code **)(((unsigned char *)0x000012d8) + *(int *)(param_1 + 0x3d4)) != (code *)0x0) {
    (**(code **)(((unsigned char *)0x000012d8) + *(int *)(param_1 + 0x3d4)))(*(int *)(param_1 + 0x3d4),param_1);
  }
  if ((*(int *)(param_1 + 0x3d8) != 0) ||
     (uVar1 = 6, *(uint *)(param_1 + 0x3cc) <= *(uint *)(param_1 + 0x3e4))) {
    uVar1 = 0;
  }
  return uVar1;
}

/* fpVariantProgramFree @ 0x9a990 (104 bytes) */
int fpVariantProgramFree(ctx, program)
  int ctx;
  int program;
{
  undefined4 status;
  
  status = 1;
  if (program != 0) {
    if (*(int *)(program + 0x3c8) != 0) {
      (**(code **)(ctx + 0x18))(*(int *)(program + 0x3c8));
    }
    (**(code **)(ctx + 0x18))(program);
    status = 0;
  }
  return status;
}

/* ffvpEmitFogLinear @ 0x9aa00 (1232 bytes) */
int ffvpEmitFogLinear(programBuilder)
  int programBuilder;
{
  undefined4 fogDstReg;
  undefined4 *fogMask;
  undefined4 *fogCoordSelect;
  int stateBlock;
  int allocStatus;
  int fogCoordComponents;
  undefined4 *fileTable;
  int fogCoordReg;
  undefined4 fogParamConstReg;
  undefined4 constFile;
  undefined4 dstTempFile;
  undefined4 srcTempFile;
  undefined4 dstFile;
  undefined4 fogFactorReg;
  int glCtx;
  int glCtxB;
  undefined4 fogCoordFile;
  undefined4 selectArrA0;
  undefined4 selectArrA1;
  undefined4 selectArrA2;
  undefined4 selectArrA3;
  undefined4 selectArrB0;
  undefined4 selectArrB1;
  undefined4 selectArrB2;
  undefined4 selectArrB3;
  undefined1 tempA [4];
  undefined4 tempAReg;
  undefined1 tempAMask [24];
  undefined4 tempASelect2;
  undefined1 tempB [4];
  undefined4 tempBReg;
  int emit3Src1Select;
  int deadSrcTempFile;
  int deadEmitFnSlot;
  int deadSelectPtr;
  int deadSrcTempFileB;
  int deadEmitFnSlotB;
  int deadSelectPtrB;
  int emit5Src1Negate;
  int emit8Src1Select;
  int emit6Src1File;
  int emit6Src1Index;
  int emit6Src1Select;
  int emit7Src1File;
  int emit7Src1Index;
  int emit7Src1Select;
  
  glCtxB = *(int *)(programBuilder + 0x3d4);
  if (*(int *)(programBuilder + 0x588) != -1) {
    return 0;
  }
  fileTable = *(undefined4 **)(programBuilder + 0x3ec);
  fogParamConstReg = *(undefined4 *)(programBuilder + 0x330);
  dstFile = **(undefined4 **)(programBuilder + 0x3f0);
  constFile = fileTable[2];
  if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(glCtxB + 4) + 0x10)) == -0x7bae) {
    fogCoordReg = *(int *)(programBuilder + 0x3f8);
    if (fogCoordReg == -1) {
      if ((*(uint *)(((unsigned char *)0x000013c0) + glCtxB) & 4) == 0) {
        ffvpEmitEyePositionDp4(programBuilder);
      }
      else {
        ffvpEmitEyePositionMad(programBuilder);
      }
      fogCoordReg = *(int *)(programBuilder + 0x3f8);
      if (fogCoordReg == -1) {
        return 2;
      }
      fileTable = *(undefined4 **)(programBuilder + 0x3ec);
    }
    fogCoordFile = *fileTable;
    fogCoordSelect = &DAT_001dbcf4;
  }
  else {
    fogCoordComponents = *(int *)(programBuilder + 0x54);
    fogCoordFile = fileTable[1];
    fogCoordReg = *(int *)(programBuilder + 0x50);
    if (fogCoordComponents == 1) {
      fogCoordSelect = &DAT_001dbce4;
    }
    else if (fogCoordComponents == 0) {
      fogCoordSelect = &DAT_001fa5f8;
    }
    else if (fogCoordComponents == 2) {
      fogCoordSelect = &DAT_001dbcf4;
    }
    else if (fogCoordComponents == 3) {
      fogCoordSelect = &DAT_001dbcd4;
    }
    else {
      fogCoordSelect = &DAT_001dbd14;
    }
  }
  allocStatus = ffvpAllocTempRegister(programBuilder,2,programBuilder + 0x584);
  if (allocStatus == 0) {
    fogFactorReg = *(undefined4 *)(programBuilder + 0x588);
    allocStatus = ffvpAllocTempRegister(programBuilder,2,tempA);
    if (allocStatus == 0) {
      glCtx = *(int *)(programBuilder + 0x3d4);
      stateBlock = *(int *)(*(int *)(glCtx + 4) + 0x10);
      if ((*(short *)(((unsigned char *)0x00002e06) + stateBlock) == -0x7bae) &&
         (*(short *)(((unsigned char *)0x00002e08) + stateBlock) != -0x7aa4)) {
        if (*(short *)(((unsigned char *)0x00002e08) + stateBlock) == -0x7aa5) {
          dstTempFile = **(undefined4 **)(programBuilder + 0x3f0);
          srcTempFile = **(undefined4 **)(programBuilder + 0x3ec);
          allocStatus = ffvpAllocTempRegister(programBuilder,1,tempB);
          if (allocStatus != 0) {
            return 7;
          }
          (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                    (programBuilder,dstTempFile,tempBReg,&DAT_001dbd04,fogCoordFile,fogCoordReg,&DAT_001dbd74,&DAT_001fa5e8,fogCoordFile,fogCoordReg,&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x00001318) + glCtx))
                    (programBuilder,dstTempFile,tempBReg,&DAT_001dbd64,srcTempFile,tempBReg,&DAT_001fa5f8,&DAT_001fa5e8
                    );
          emit3Src1Select = ((unsigned char *)&DAT_001dbdc0 + 244);
          (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                    (programBuilder,dstFile,tempAReg,tempAMask,srcTempFile,tempBReg,&DAT_001dbec4,&DAT_001fa5e8,srcTempFile,tempBReg,emit3Src1Select,&DAT_001fa5e8);
          ffvpFreeTempRegister(programBuilder,tempB);
        }
        else {
          (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                    (programBuilder,dstFile,tempAReg,tempAMask,fogCoordFile,fogCoordReg,fogCoordSelect,&DAT_001dbd94);
        }
      }
      else {
        emit5Src1Negate = &DAT_001dbd94;
        (**(code **)(((unsigned char *)0x00001304) + glCtx))
                  (programBuilder,dstFile,tempAReg,tempAMask,fogCoordFile,fogCoordReg,fogCoordSelect,&DAT_001fa5e8,fogCoordFile,fogCoordReg,fogCoordSelect,emit5Src1Negate);
      }
      fogCoordFile = **(undefined4 **)(programBuilder + 0x3ec);
      selectArrB3 = 4;
      selectArrA0 = 4;
      selectArrA2 = 2;
      selectArrA1 = 1;
      selectArrA3 = 4;
      selectArrB0 = 4;
      selectArrB1 = 5;
      selectArrB2 = tempASelect2;
      if (*(int *)(programBuilder + 0x3d8) != 0) {
        deadSrcTempFile = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
        deadEmitFnSlot = *(int *)((int)*(int *)((int)programBuilder + 980) + 4836);
        deadSelectPtr = &selectArrB0;
        emit6Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
        emit6Src1Index = tempAReg;
        emit6Src1Select = &selectArrB0;
        (**(code **)(((unsigned char *)0x000012e4) + glCtxB))
                  (programBuilder,*(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0x18),*(undefined4 *)(programBuilder + 0x70),&DAT_001dbd04,constFile,fogParamConstReg,&selectArrA0,&DAT_001fa5e8,emit6Src1File,emit6Src1Index,emit6Src1Select,&DAT_001fa5e8);
        ffvpFreeTempRegister(programBuilder,tempA);
        return 0;
      }
      fogMask = (undefined4 *)(programBuilder + 0x58c);
      deadSrcTempFileB = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
      deadEmitFnSlotB = *(int *)((int)*(int *)((int)programBuilder + 980) + 4836);
      deadSelectPtrB = &selectArrB0;
      emit7Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
      emit7Src1Index = tempAReg;
      emit7Src1Select = &selectArrB0;
      (**(code **)(((unsigned char *)0x000012e4) + glCtxB))(programBuilder,dstFile,fogFactorReg,fogMask,constFile,fogParamConstReg,&selectArrA0,&DAT_001fa5e8,emit7Src1File,emit7Src1Index,emit7Src1Select,&DAT_001fa5e8);
      ffvpFreeTempRegister(programBuilder,tempA);
      fogDstReg = fogFactorReg;
      if (-1 < *(int *)(glCtxB + 0x44)) {
        fogDstReg = *(undefined4 *)(programBuilder + 0x70);
        fogMask = &DAT_001dbd44;
        dstFile = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0x18);
      }
      emit8Src1Select = &DAT_001dbdb4;
      (**(code **)(((unsigned char *)0x00001328) + glCtxB))
                (programBuilder,dstFile,fogDstReg,fogMask,fogCoordFile,fogFactorReg,programBuilder + 0x59c,&DAT_001fa5e8,fogCoordFile,fogFactorReg,emit8Src1Select,&DAT_001fa5e8);
      return 0;
    }
  }
  return 7;
}

/* ffvpPrepareFogLinear @ 0x9af00 (172 bytes) */
int ffvpPrepareFogLinear(programBuilder)
  int programBuilder;
{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(int *)(programBuilder + 0x330) == -1) || (iVar2 = *(int *)(programBuilder + 0x70), iVar2 == -1)) {
    return 2;
  }
  if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(*(int *)(programBuilder + 0x3d4) + 4) + 0x10)) ==
      -0x7baf) {
    if (*(int *)(programBuilder + 0x50) == -1) {
      return 2;
    }
    if (3 < *(uint *)(programBuilder + 0x54)) {
      return 3;
    }
  }
  if ((((*(int *)(programBuilder + 0x3d8) == 0) && (iVar2 != *(int *)(programBuilder + 0x74))) &&
      (iVar2 != *(int *)(programBuilder + 0x78))) &&
     ((iVar2 != *(int *)(programBuilder + 0x7c) && (iVar2 != *(int *)(programBuilder + 0x80))))) {
    return 3;
  }
  *(undefined1 *)(*(int *)(programBuilder + 0x3d4) + 0x12e) = 0;
  uVar1 = ((int (*)())ffvpEmitFogLinear)(programBuilder);
  return uVar1;
}

/* ffvpEmitFogExp @ 0x9afc0 (1084 bytes) */
int ffvpEmitFogExp(programBuilder)
  int programBuilder;
{
  undefined4 *fogMask;
  undefined4 *fogCoordSelect;
  int stateBlock;
  int allocStatus;
  undefined4 fogTempRegCopy;
  int fogCoordComponents;
  undefined4 *fileTable;
  int fogCoordReg;
  undefined4 constFile;
  undefined4 fogParamConstReg;
  undefined4 dstTempFile;
  undefined4 srcTempFile;
  undefined4 fogDstReg;
  int glCtx;
  undefined4 dstFile;
  undefined4 fogCoordFile;
  int glCtxB;
  undefined1 tempA [4];
  undefined4 tempAReg;
  undefined1 tempAMask [16];
  undefined1 tempASelect0 [16];
  undefined1 tempB [4];
  undefined4 tempBReg;
  int emit3Src1Select;
  int emit6Src1File;
  int emit6Src1Select;
  int emit5Src1Negate;
  
  glCtxB = *(int *)(programBuilder + 0x3d4);
  if (*(int *)(programBuilder + 0x588) != -1) {
    return 0;
  }
  fileTable = *(undefined4 **)(programBuilder + 0x3ec);
  fogParamConstReg = *(undefined4 *)(programBuilder + 0x330);
  dstFile = **(undefined4 **)(programBuilder + 0x3f0);
  constFile = fileTable[2];
  if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(glCtxB + 4) + 0x10)) == -0x7bae) {
    fogCoordReg = *(int *)(programBuilder + 0x3f8);
    if (fogCoordReg == -1) {
      if ((*(uint *)(((unsigned char *)0x000013c0) + glCtxB) & 4) == 0) {
        ffvpEmitEyePositionDp4(programBuilder);
      }
      else {
        ffvpEmitEyePositionMad(programBuilder);
      }
      fogCoordReg = *(int *)(programBuilder + 0x3f8);
      if (fogCoordReg == -1) {
        return 2;
      }
      fileTable = *(undefined4 **)(programBuilder + 0x3ec);
    }
    fogCoordFile = *fileTable;
    fogCoordSelect = &DAT_001dbcf4;
  }
  else {
    fogCoordComponents = *(int *)(programBuilder + 0x54);
    fogCoordFile = fileTable[1];
    fogCoordReg = *(int *)(programBuilder + 0x50);
    if (fogCoordComponents == 1) {
      fogCoordSelect = &DAT_001dbce4;
    }
    else if (fogCoordComponents == 0) {
      fogCoordSelect = &DAT_001fa5f8;
    }
    else if (fogCoordComponents == 2) {
      fogCoordSelect = &DAT_001dbcf4;
    }
    else if (fogCoordComponents == 3) {
      fogCoordSelect = &DAT_001dbcd4;
    }
    else {
      fogCoordSelect = &DAT_001dbd14;
    }
  }
  allocStatus = ffvpAllocTempRegister(programBuilder,2,programBuilder + 0x584);
  if (allocStatus == 0) {
    fogDstReg = *(undefined4 *)(programBuilder + 0x588);
    allocStatus = ffvpAllocTempRegister(programBuilder,2,tempA);
    fogTempRegCopy = tempAReg;
    if (allocStatus == 0) {
      glCtx = *(int *)(programBuilder + 0x3d4);
      stateBlock = *(int *)(*(int *)(glCtx + 4) + 0x10);
      if ((*(short *)(((unsigned char *)0x00002e06) + stateBlock) == -0x7bae) &&
         (*(short *)(((unsigned char *)0x00002e08) + stateBlock) != -0x7aa4)) {
        if (*(short *)(((unsigned char *)0x00002e08) + stateBlock) == -0x7aa5) {
          dstTempFile = **(undefined4 **)(programBuilder + 0x3f0);
          srcTempFile = **(undefined4 **)(programBuilder + 0x3ec);
          allocStatus = ffvpAllocTempRegister(programBuilder,1,tempB);
          if (allocStatus != 0) {
            return 7;
          }
          (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                    (programBuilder,dstTempFile,tempBReg,&DAT_001dbd04,fogCoordFile,fogCoordReg,&DAT_001dbd74,&DAT_001fa5e8,fogCoordFile,fogCoordReg,&DAT_001dbd74,&DAT_001fa5e8);
          (**(code **)(((unsigned char *)0x00001318) + glCtx))
                    (programBuilder,dstTempFile,tempBReg,&DAT_001dbd64,srcTempFile,tempBReg,&DAT_001fa5f8,&DAT_001fa5e8
                    );
          emit3Src1Select = ((unsigned char *)&DAT_001dbdc0 + 244);
          (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                    (programBuilder,dstFile,fogTempRegCopy,tempAMask,srcTempFile,tempBReg,&DAT_001dbec4,&DAT_001fa5e8,srcTempFile,tempBReg,emit3Src1Select,&DAT_001fa5e8);
          ffvpFreeTempRegister(programBuilder,tempB);
        }
        else {
          (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                    (programBuilder,dstFile,tempAReg,tempAMask,fogCoordFile,fogCoordReg,fogCoordSelect,&DAT_001dbd94);
        }
      }
      else {
        emit5Src1Negate = &DAT_001dbd94;
        (**(code **)(((unsigned char *)0x00001304) + glCtx))
                  (programBuilder,dstFile,tempAReg,tempAMask,fogCoordFile,fogCoordReg,fogCoordSelect,&DAT_001fa5e8,fogCoordFile,fogCoordReg,fogCoordSelect,emit5Src1Negate);
      }
      fogCoordFile = **(undefined4 **)(programBuilder + 0x3ec);
      emit6Src1File = *(int *)((int)*(int *)((int)programBuilder + 1004) + 0);
      emit6Src1Select = &tempASelect0;
      (**(code **)(((unsigned char *)0x000012ec) + glCtxB))
                (programBuilder,dstFile,tempAReg,tempAMask,constFile,fogParamConstReg,&DAT_001dbcf4,&DAT_001fa5e8,emit6Src1File,tempAReg,emit6Src1Select,&DAT_001fa5e8);
      if (*(int *)(programBuilder + 0x3d8) == 0) {
        fogMask = (undefined4 *)(programBuilder + 0x58c);
        if (-1 < *(int *)(glCtxB + 0x44)) {
          fogDstReg = *(undefined4 *)(programBuilder + 0x70);
          fogMask = &DAT_001dbd44;
          dstFile = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0x18);
        }
      }
      else {
        fogDstReg = *(undefined4 *)(programBuilder + 0x70);
        fogMask = &DAT_001dbd04;
        dstFile = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0x18);
      }
      (**(code **)(((unsigned char *)0x00001320) + glCtxB))
                (programBuilder,dstFile,fogDstReg,fogMask,fogCoordFile,tempAReg,tempASelect0,&DAT_001fa5e8);
      ffvpFreeTempRegister(programBuilder,tempA);
      return 0;
    }
  }
  return 7;
}

/* ffvpEmitColorOutputs @ 0x9b430 (848 bytes) */
int ffvpEmitColorOutputs(programBuilder, noLights)
  int programBuilder;
  int noLights;
{
  undefined4 secondarySrcFile;
  undefined4 secondaryOutFile;
  undefined4 srcTempFile;
  short fogMode;
  int fogFactorReg;
  undefined4 status;
  int secondaryOutReg;
  uint loopIndex;
  int stateBlock;
  undefined4 secondaryColorReg;
  int builderRegCursor;
  int ctxWordCursor;
  int colorSlotCursor;
  int glCtx;
  undefined4 primaryColorReg;
  undefined *selectPtr;
  undefined4 primaryOutReg;
  undefined4 materialFile;
  undefined4 materialReg;
  undefined4 materialSelect0;
  undefined4 materialSelect1;
  undefined4 materialSelect2;
  int materialSelect3;
  undefined *constBase68;
  undefined *constBase64;
  undefined4 *materialSelectPtr;
  undefined *constBase5c;
  int emit1Src1File;
  int emit1Src1Index;
  int emit1Src1Select;
  int emit2Src1File;
  int emit2Src1Index;
  
  status = 1;
  if (programBuilder != 0) {
    glCtx = *(int *)(programBuilder + 0x3d4);
    materialSelectPtr = &materialSelect0;
    loopIndex = 0;
    srcTempFile = **(undefined4 **)(programBuilder + 0x3ec);
    stateBlock = *(int *)(*(int *)(glCtx + 4) + 0x10);
    constBase68 = &DAT_001db440;
    constBase64 = &DAT_001db440;
    constBase5c = &DAT_001db440;
    builderRegCursor = programBuilder;
    ctxWordCursor = glCtx;
    colorSlotCursor = programBuilder;
    do {
      primaryColorReg = *(undefined4 *)(colorSlotCursor + 0x5b0);
      secondaryColorReg = *(undefined4 *)(colorSlotCursor + 0x600);
      primaryOutReg = *(undefined4 *)(builderRegCursor + 0x74);
      ffvpResolveMaterialSource(programBuilder,*(undefined4 *)(ctxWordCursor + 0x280),2,&materialFile,&materialReg);
      materialSelect0 = 5;
      materialSelect1 = 5;
      materialSelect2 = 5;
      materialSelect3 = 3;
      if (noLights == 0) {
        emit1Src1File = materialFile;
        emit1Src1Index = materialReg;
        emit1Src1Select = materialSelectPtr;
        (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                  (programBuilder,*(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0xc),primaryOutReg,constBase68 + 0x8e4,
                   srcTempFile,primaryColorReg,constBase64 + 0x984,&DAT_001fa5e8,emit1Src1File,emit1Src1Index,emit1Src1Select,&DAT_001fa5e8);
      }
      if ((((*(short *)(((unsigned char *)0x00002d48) + stateBlock) == -0x7e06) && (*(char *)(glCtx + 0x12d) != '\0')
           ) || (((*(uint *)(glCtx + 0x44) & 0x1000000) != 0 && (*(char *)(glCtx + 0x121) == '\0')
                 ))) || ((*(uint *)(glCtx + 0x44) & 0xa10000) != 0)) {
        secondaryOutReg = *(int *)(builderRegCursor + 0x7c);
        secondaryOutFile = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0x10);
        ffvpResolveMaterialSource(programBuilder,*(undefined4 *)(ctxWordCursor + 0x288),3,&materialFile,&materialReg);
        if (((*(short *)(((unsigned char *)0x00002d48) + stateBlock) != -0x7e06) ||
            (*(char *)(glCtx + 0x12d) == '\0')) || (noLights == 0)) {
          selectPtr = constBase5c + 0x964;
          secondaryColorReg = materialReg;
          secondarySrcFile = materialFile;
        }
        else {
          selectPtr = constBase64 + 0x984;
          secondarySrcFile = srcTempFile;
        }
        /* stack words 9/10 of the last call: the stock (0x9b6fc/0x9b708) passes (materialFile, materialReg) unless the two arms below replace them */
        emit2Src1File = materialFile;
        emit2Src1Index = materialReg;
        if ((((*(uint *)(glCtx + 0x44) & 0x1000000) != 0) && (*(char *)(glCtx + 0x121) == '\0'))
           && ((*(int *)(programBuilder + 0x3d8) == 0 && (secondaryOutReg == *(int *)(programBuilder + 0x70))))) {
          if (*(char *)(glCtx + 0x12e) == '\0') {
            if (*(int *)(programBuilder + 0x588) == -1) {
              fogMode = *(short *)(((unsigned char *)0x00002e04) + stateBlock);
              if (fogMode == 0x801) {
                ffvpEmitFogExp2(programBuilder);
                fogFactorReg = *(int *)(programBuilder + 0x588);
              }
              else if (fogMode == 0x2601) {
                ((int (*)())ffvpEmitFogLinear)(programBuilder);
                fogFactorReg = *(int *)(programBuilder + 0x588);
              }
              else {
                if (fogMode != 0x800) {
                  return 2;
                }
                ((int (*)())ffvpEmitFogExp)(programBuilder);
                fogFactorReg = *(int *)(programBuilder + 0x588);
              }
              if (fogFactorReg == -1) {
                return 2;
              }
            }
            materialSelect3 = *(int *)(programBuilder + 0x5a8);
            emit2Src1File = srcTempFile;
            emit2Src1Index = *(int *)(programBuilder + 0x588);
          }
          else {
            emit2Src1File = (*(int **)(programBuilder + 0x3ec))[1];
            emit2Src1Index = *(int *)(programBuilder + 0x50);
            materialSelect3 = *(int *)(programBuilder + 0x54);
            if (materialSelect3 != 1) {
              if (materialSelect3 == 0) {
                materialSelect3 = 0;
              }
              else if ((materialSelect3 != 2) && (materialSelect3 != 3)) {
                materialSelect3 = 3;
              }
            }
          }
        }
        (**(code **)(((unsigned char *)0x000012ec) + glCtx))
                  (programBuilder,secondaryOutFile,secondaryOutReg,constBase68 + 0x8e4,secondarySrcFile,secondaryColorReg,selectPtr,&DAT_001fa5e8,emit2Src1File,emit2Src1Index,materialSelectPtr,&DAT_001fa5e8);
      }
      loopIndex = loopIndex + 1;
      colorSlotCursor = colorSlotCursor + 0x28;
      builderRegCursor = builderRegCursor + 4;
      ctxWordCursor = ctxWordCursor + 4;
    } while (loopIndex <= (byte)((unsigned char *)0x00002d48)[stateBlock + 4]);
    status = 0;
  }
  return status;
}

/* ffvpPrepareFogExp @ 0x9b790 (172 bytes) */
int ffvpPrepareFogExp(programBuilder)
  int programBuilder;
{
  undefined4 uVar1;
  int iVar2;
  
  if ((*(int *)(programBuilder + 0x330) == -1) || (iVar2 = *(int *)(programBuilder + 0x70), iVar2 == -1)) {
    return 2;
  }
  if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(*(int *)(programBuilder + 0x3d4) + 4) + 0x10)) ==
      -0x7baf) {
    if (*(int *)(programBuilder + 0x50) == -1) {
      return 2;
    }
    if (3 < *(uint *)(programBuilder + 0x54)) {
      return 3;
    }
  }
  if ((((*(int *)(programBuilder + 0x3d8) == 0) && (iVar2 != *(int *)(programBuilder + 0x74))) &&
      (iVar2 != *(int *)(programBuilder + 0x78))) &&
     ((iVar2 != *(int *)(programBuilder + 0x7c) && (iVar2 != *(int *)(programBuilder + 0x80))))) {
    return 3;
  }
  *(undefined1 *)(*(int *)(programBuilder + 0x3d4) + 0x12e) = 0;
  uVar1 = ((int (*)())ffvpEmitFogExp)(programBuilder);
  return uVar1;
}

/* ffvpEmitFogTexCoord @ 0x9b850 (892 bytes) */
int ffvpEmitFogTexCoord(programBuilder, texUnit)
  int programBuilder;
  uint texUnit;
{
  int stateBlock;
  undefined4 dstTempFile;
  undefined4 srcTempFile;
  undefined4 srcTempFileB;
  int eyePositionReg;
  undefined4 texOutFile;
  int texOutReg;
  int glCtx;
  uint local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 tempA [4];
  undefined4 tempAReg;
  int emit4Src1Select;
  int emit1Src1Negate;
  
  if (programBuilder == 0) {
    return 1;
  }
  if (texUnit < 8) {
    texOutReg = *(int *)(texUnit * 4 + programBuilder + 0x84);
    if (texOutReg != -1) {
      glCtx = *(int *)(programBuilder + 0x3d4);
      texOutFile = *(undefined4 *)(*(int *)(programBuilder + 0x3f0) + 0x14);
      local_74 = DAT_001dbda8;
      local_78 = DAT_001dbda4;
      local_70 = DAT_001dbdac;
      local_6c = DAT_001dbdb0;
      if (*(short *)(((unsigned char *)0x00002e06) + *(int *)(*(int *)(glCtx + 4) + 0x10)) == -0x7bae) {
        eyePositionReg = *(int *)(programBuilder + 0x3f8);
        if (eyePositionReg != -1) {
LAB_0009b914:
          srcTempFileB = **(undefined4 **)(programBuilder + 0x3ec);
          local_78 = 2;
          stateBlock = *(int *)(*(int *)(glCtx + 4) + 0x10);
          if (*(short *)(((unsigned char *)0x00002e06) + stateBlock) != -0x7bae) {
            emit1Src1Negate = &DAT_001dbd94;
            (**(code **)(((unsigned char *)0x00001304) + glCtx))
                      (programBuilder,texOutFile,texOutReg,&DAT_001dbd24,srcTempFileB,eyePositionReg,&local_78,&DAT_001fa5e8,srcTempFileB,eyePositionReg,&local_78,emit1Src1Negate);
            return 0;
          }
          if (*(short *)(((unsigned char *)0x00002e08) + stateBlock) == -0x7aa5) {
            srcTempFile = **(undefined4 **)(programBuilder + 0x3ec);
            dstTempFile = **(undefined4 **)(programBuilder + 0x3f0);
            stateBlock = ffvpAllocTempRegister(programBuilder,1,tempA);
            if (stateBlock != 0) {
              return 7;
            }
            (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                      (programBuilder,dstTempFile,tempAReg,&DAT_001dbd04,srcTempFileB,eyePositionReg,&DAT_001dbd74,&DAT_001fa5e8,srcTempFileB,eyePositionReg,&DAT_001dbd74,&DAT_001fa5e8)
            ;
            (**(code **)(((unsigned char *)0x00001318) + glCtx))
                      (programBuilder,dstTempFile,tempAReg,&DAT_001dbd64,srcTempFile,tempAReg,&DAT_001fa5f8,
                       &DAT_001fa5e8);
            emit4Src1Select = ((unsigned char *)&DAT_001dbdc0 + 244);
            (**(code **)(((unsigned char *)0x000012e4) + glCtx))
                      (programBuilder,texOutFile,texOutReg,&DAT_001dbd24,srcTempFile,tempAReg,&DAT_001dbec4,&DAT_001fa5e8,srcTempFile,tempAReg,emit4Src1Select,&DAT_001fa5e8)
            ;
            ffvpFreeTempRegister(programBuilder,tempA);
            return 0;
          }
          (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                    (programBuilder,texOutFile,texOutReg,&DAT_001dbd24,srcTempFileB,eyePositionReg,&local_78,&DAT_001dbd94);
          return 0;
        }
        if ((*(uint *)(((unsigned char *)0x000013c0) + glCtx) & 4) == 0) {
          ffvpEmitEyePositionDp4(programBuilder);
        }
        else {
          ffvpEmitEyePositionMad(programBuilder);
        }
        eyePositionReg = *(int *)(programBuilder + 0x3f8);
        if (eyePositionReg != -1) {
          glCtx = *(int *)(programBuilder + 0x3d4);
          goto LAB_0009b914;
        }
      }
      else if (*(int *)(programBuilder + 0x50) != -1) {
        local_78 = *(uint *)(programBuilder + 0x54);
        if (local_78 < 4) {
          if (local_78 != 1) {
            if (local_78 == 0) {
              local_78 = 0;
            }
            else if ((local_78 != 2) && (local_78 != 3)) {
              local_78 = 4;
            }
          }
          (**(code **)(((unsigned char *)0x000012e8) + glCtx))
                    (programBuilder,texOutFile,texOutReg,&DAT_001dbd24,
                     *(undefined4 *)(*(int *)(programBuilder + 0x3ec) + 4),*(int *)(programBuilder + 0x50),
                     &local_78,&DAT_001fa5e8);
          return 0;
        }
        goto LAB_0009bbb0;
      }
    }
    texOutFile = 2;
  }
  else {
LAB_0009bbb0:
    texOutFile = 3;
  }
  return texOutFile;
}

/* vec4StoreAtIndex @ 0x9bbf0 (28 bytes) */
int vec4StoreAtIndex(param_1, param_2, param_3)
  int param_1;
  undefined8 *param_2;
  int param_3;
{
  undefined8 uVar1;
  
  uVar1 = param_2[1];
  *(undefined8 *)(param_3 * 0x10 + param_1) = *param_2;
  *(undefined8 *)(param_3 * 0x10 + param_1 + 8) = uVar1;
  return;
}

/* mat4StoreAtIndex @ 0x9bc10 (228 bytes) */
int mat4StoreAtIndex(keepOrder, table, srcMatrix, tableIndex)
  int keepOrder;
  int table;
  undefined4 *srcMatrix;
  int tableIndex;
{
  int slotOffset;
  int slot;
  undefined4 elem5;
  undefined4 elem14;
  undefined4 elem1;
  undefined4 elem12;
  undefined4 elem4;
  undefined4 elem8;
  undefined4 elem15;
  undefined4 elem9;
  undefined4 elem11;
  undefined4 elem7;
  undefined4 elem3;
  undefined4 elem10;
  undefined4 elem6;
  undefined4 elem2;
  undefined4 elem13;
  
  slotOffset = tableIndex * 0x10;
  elem15 = srcMatrix[0xf];
  elem1 = srcMatrix[1];
  elem2 = srcMatrix[2];
  slot = slotOffset + table;
  elem3 = srcMatrix[3];
  elem4 = srcMatrix[4];
  elem5 = srcMatrix[5];
  elem6 = srcMatrix[6];
  elem7 = srcMatrix[7];
  elem8 = srcMatrix[8];
  elem9 = srcMatrix[9];
  elem10 = srcMatrix[10];
  elem11 = srcMatrix[0xb];
  elem12 = srcMatrix[0xc];
  elem13 = srcMatrix[0xd];
  elem14 = srcMatrix[0xe];
  if (keepOrder == 0) {
    *(undefined4 *)(slotOffset + table) = *srcMatrix;
    *(undefined4 *)(slot + 0x3c) = elem15;
    *(undefined4 *)(slot + 4) = elem4;
    *(undefined4 *)(slot + 8) = elem8;
    *(undefined4 *)(slot + 0xc) = elem12;
    *(undefined4 *)(slot + 0x10) = elem1;
    *(undefined4 *)(slot + 0x14) = elem5;
    *(undefined4 *)(slot + 0x18) = elem9;
    *(undefined4 *)(slot + 0x1c) = elem13;
    *(undefined4 *)(slot + 0x20) = elem2;
    *(undefined4 *)(slot + 0x24) = elem6;
    *(undefined4 *)(slot + 0x28) = elem10;
    *(undefined4 *)(slot + 0x2c) = elem14;
    *(undefined4 *)(slot + 0x30) = elem3;
    *(undefined4 *)(slot + 0x34) = elem7;
    *(undefined4 *)(slot + 0x38) = elem11;
  }
  else {
    *(undefined4 *)(slotOffset + table) = *srcMatrix;
    *(undefined4 *)(slot + 0x3c) = elem15;
    *(undefined4 *)(slot + 4) = elem1;
    *(undefined4 *)(slot + 8) = elem2;
    *(undefined4 *)(slot + 0xc) = elem3;
    *(undefined4 *)(slot + 0x10) = elem4;
    *(undefined4 *)(slot + 0x14) = elem5;
    *(undefined4 *)(slot + 0x18) = elem6;
    *(undefined4 *)(slot + 0x1c) = elem7;
    *(undefined4 *)(slot + 0x20) = elem8;
    *(undefined4 *)(slot + 0x24) = elem9;
    *(undefined4 *)(slot + 0x28) = elem10;
    *(undefined4 *)(slot + 0x2c) = elem11;
    *(undefined4 *)(slot + 0x30) = elem12;
    *(undefined4 *)(slot + 0x34) = elem13;
    *(undefined4 *)(slot + 0x38) = elem14;
  }
  return;
}

/* paramListCreate @ 0x9bd00 (96 bytes) */
int paramListCreate(ctx)
  int ctx;
{
  ushort slotCount;
  int *vector;
  
  slotCount = *(ushort *)(((unsigned char *)0x000013be) + ctx);
  vector = (int *)(**(code **)(ctx + 0xc))((uint)slotCount * 8 + 0xc);
  vector[2] = 0;
  *vector = (int)(vector + 3);
  vector[1] = (int)(vector + 3 + slotCount);
  return vector;
}

/* ffvpInitContextState @ 0x9bd60 (160 bytes) */
int ffvpInitContextState(ctx, flag131)
  int ctx;
  undefined4 flag131;
{
  int cursor;
  int countdown;
  
  *(undefined1 *)(ctx + 0x131) = (undefined1)flag131;
  *(undefined1 *)(ctx + 0x12f) = 0;
  *(undefined4 *)(ctx + 0x14c) = 0;
  *(undefined1 *)(ctx + 0x125) = 0;
  *(undefined1 *)(ctx + 0x124) = 0;
  *(undefined4 *)(ctx + 0x13c) = 0;
  *(undefined4 *)(ctx + 0x148) = 0;
  *(undefined1 *)(ctx + 0x12d) = 0;
  *(code **)(((unsigned char *)0x000012cc) + ctx) = vec4StoreAtIndex;
  *(code **)(((unsigned char *)0x000012c8) + ctx) = mat4StoreAtIndex;
  countdown = 8;
  cursor = ctx;
  do {
    *(undefined4 *)(cursor + 0x150) = 0;
    cursor = cursor + 4;
    countdown = countdown + -1;
  } while (countdown != 0);
  cursor = ctx + 0x3a0;
  countdown = 8;
  do {
    *(uint *)(cursor + 8) = *(uint *)(cursor + 8) & 0xffffff;
    cursor = cursor + 4;
    countdown = countdown + -1;
  } while (countdown != 0);
  *(undefined1 *)(ctx + 299) = 0;
  *(undefined1 *)(ctx + 0x126) = 0;
  return;
}

/* ffvpAnalyzeLightState @ 0x9be00 (2216 bytes) */
int ffvpAnalyzeLightState(ctx)
  int ctx;
{
  uint lightMaskCursor;
  uint lightMaskShifting;
  undefined4 copyWord0;
  uint *lightControlCursor;
  int lightStateOffset;
  int lightDirtyCursor;
  int wordOffset;
  float normalXTemp;
  char newColorSumFlag;
  char oldColorSumFlag;
  char stateFlag24ae;
  char stateFlag2d4d;
  float normalYTemp;
  float lightAmbientX;
  bool needsLightModelSum;
  float oneConst;
  undefined4 colorMaterialLookup;
  char stateFlag24ad;
  undefined1 newFlag12c;
  int controlWordOffset;
  byte dirtyBits;
  int lightState;
  undefined4 *lightCache;
  int dirtyCursor;
  int ctxBase124;
  uint *lightFlagCursor;
  undefined4 copyWord1;
  int lightCopyCursor;
  undefined4 copyWord2;
  uint dirtyCount;
  uint *ctxFlags1874Ptr;
  uint secondaryColorBits;
  bool secondaryColorNeeded;
  int lightCacheOffset;
  byte *lightDirtyPtr;
  int lightIndex;
  int stateBlock;
  
  ctxBase124 = ctx + 0x124;
  oldColorSumFlag = *(char *)(ctx + 0x12f);
  stateBlock = *(int *)(*(int *)(ctx + 4) + 0x10);
  stateFlag24ad = *(char *)(stateBlock + 0x24ad);
  stateFlag24ae = *(char *)(stateBlock + 0x24ae);
  if (-1 < *(int *)(ctx + 0x44)) {
    if ((*(uint *)(ctx + 0x8c) & 0xc000000) != 0) {
      *(char *)(ctx + 300) = stateFlag24ae;
      return;
    }
    *(undefined1 *)(ctx + 300) = 0;
    return;
  }
  ctxFlags1874Ptr = (uint *)(ctx + 0x1874);
  stateFlag2d4d = ((unsigned char *)0x00002d48)[stateBlock + 5];
  secondaryColorNeeded = *(short *)(((unsigned char *)0x00002d48) + stateBlock) == -0x7e06;
  secondaryColorBits = (uint)secondaryColorNeeded;
  colorMaterialLookup = *(undefined4 *)
           (&DAT_001dbed4 +
           (uint)(byte)((unsigned char *)0x00002d48)[stateBlock + 3] *
           ((*(ushort *)(((unsigned char *)0x00002d44) + stateBlock) & 1 | *(ushort *)(((unsigned char *)0x00002d44) + stateBlock) >> 2 & 2)
           + ((*(ushort *)(((unsigned char *)0x00002d46) + stateBlock) >> 8 & 4) +
             (*(ushort *)(((unsigned char *)0x00002d46) + stateBlock) & 0xf)) * 3 + 1) * 4);
  *(undefined4 *)(ctx + 0x26c) = colorMaterialLookup;
  if (*(int *)(ctx + 0x13c) != 1) {
    colorMaterialLookup = 0;
  }
  *(undefined4 *)(ctx + 0x1890) = colorMaterialLookup;
  *(undefined1 *)(ctx + 0x12f) = 0;
  if ((stateFlag2d4d != '\0') && (stateFlag24ae == '\0')) {
    *(undefined1 *)(ctx + 300) = 0;
    if ((*(uint *)(ctx + 0x40) & 0x10000) != 0) {
      dirtyCount = (uint)(byte)((unsigned char *)0x000013b5)[ctx];
      if (dirtyCount != 0) {
        dirtyCursor = ctx;
        if ((dirtyCount == 0) || (dirtyCount == 0x80000000)) {
          dirtyCount = 1;
        }
        do {
          *(byte *)(dirtyCursor + 0x1814) = *(byte *)(dirtyCursor + 0x1814) | 0x18;
          dirtyCursor = dirtyCursor + 1;
          dirtyCount = dirtyCount - 1;
        } while (dirtyCount != 0);
      }
    }
    goto LAB_0009bfa0;
  }
  if (((*(uint *)(ctx + 0x8c) >> 0x1a & 1) != 0 || (*(uint *)(ctx + 0x8c) >> 0x1b & 1) != 0)
     && ((*(uint *)(ctx + 0x40) & 0x10000) != 0)) {
    dirtyCount = (uint)(byte)((unsigned char *)0x000013b5)[ctx];
    if (dirtyCount != 0) {
      dirtyCursor = ctx;
      if ((dirtyCount == 0) || (dirtyCount == 0x80000000)) {
        dirtyCount = 1;
      }
      do {
        *(byte *)(dirtyCursor + 0x1814) = *(byte *)(dirtyCursor + 0x1814) | 0x18;
        dirtyCursor = dirtyCursor + 1;
        dirtyCount = dirtyCount - 1;
      } while (dirtyCount != 0);
    }
  }
  if ((stateFlag24ae == '\0') || (stateFlag24ad != '\0')) {
    newColorSumFlag = *(char *)(ctx + 0x12f);
LAB_0009bf34:
    newFlag12c = 0;
  }
  else {
    newColorSumFlag = *(char *)(ctx + 0x12f);
    newFlag12c = 1;
    if (newColorSumFlag != '\0') goto LAB_0009bf34;
  }
  *(undefined1 *)(ctx + 300) = newFlag12c;
  if (oldColorSumFlag != newColorSumFlag) {
    dirtyCount = (uint)(byte)((unsigned char *)0x000013b5)[ctx];
    if (dirtyCount != 0) {
      dirtyCursor = ctx;
      if ((dirtyCount == 0) || (dirtyCount == 0x80000000)) {
        dirtyCount = 1;
      }
      do {
        *(byte *)(dirtyCursor + 0x1814) = *(byte *)(dirtyCursor + 0x1814) | 0x18;
        dirtyCursor = dirtyCursor + 1;
        dirtyCount = dirtyCount - 1;
      } while (dirtyCount != 0);
    }
  }
LAB_0009bfa0:
  if ((*(uint *)(ctx + 0x180c) & 1) != 0) {
    *(uint *)(ctx + 0x180c) = *(uint *)(ctx + 0x180c) & 0xfffffffe;
  }
  oneConst = FLOAT_001aa0e8;
  lightMaskShifting = *(uint *)(ctx + 0x88);
  if (lightMaskShifting != 0) {
    lightIndex = 0;
    needsLightModelSum = false;
    lightCacheOffset = 0;
    lightDirtyCursor = ctx;
    lightFlagCursor = ctxFlags1874Ptr;
    lightCopyCursor = ctxBase124;
    do {
      if ((lightMaskShifting & 1) != 0) {
        lightDirtyPtr = (byte *)(lightDirtyCursor + 0x1814);
        lightState = lightIndex * 0x80 + stateBlock + 0x24c0;
        lightCache = (undefined4 *)(((unsigned char *)0x000014a4) + lightCacheOffset + ctx);
        if (*(byte *)(lightDirtyCursor + 0x1814) != 0) {
          if ((*(byte *)(lightDirtyCursor + 0x1814) & 1) != 0) {
            lightAmbientX = *(float *)(lightIndex * 0x80 + stateBlock + 0x24c0);
            if (((lightAmbientX == FLOAT_001aa0d4) && (*(float *)(lightState + 4) == FLOAT_001aa0d4)) &&
               (*(float *)(lightState + 8) == FLOAT_001aa0d4)) {
              controlWordOffset = lightIndex * 4 + ctxBase124;
              *(uint *)(controlWordOffset + 0x284) = *(uint *)(controlWordOffset + 0x284) & 0x3fffffff;
              *(ushort *)(lightFlagCursor + 8) = *(ushort *)(lightFlagCursor + 8) & 0x9fff;
            }
            else if (((lightAmbientX == FLOAT_001aa0e8) && (*(float *)(lightState + 4) == FLOAT_001aa0e8)) &&
                    (*(float *)(lightState + 8) == FLOAT_001aa0e8)) {
              controlWordOffset = lightIndex * 4 + ctxBase124;
              *(uint *)(controlWordOffset + 0x284) = *(uint *)(controlWordOffset + 0x284) & 0x3fffffff | 0x40000000;
              *(ushort *)(lightFlagCursor + 8) = *(ushort *)(lightFlagCursor + 8) & 0x9fff | 0x2000;
            }
            else if (((*(float *)(lightState + 0x50) == oneConst) &&
                     (*(float *)(lightState + 0x54) == FLOAT_001aa0d4)) &&
                    ((*(float *)(lightState + 0x58) == FLOAT_001aa0d4 &&
                     (*(char *)(lightCache + 0x1a) == '\0')))) {
              needsLightModelSum = true;
              controlWordOffset = lightIndex * 4 + ctxBase124;
              *(uint *)(controlWordOffset + 0x284) = *(uint *)(controlWordOffset + 0x284) & 0x3fffffff | 0xc0000000;
              *(ushort *)(lightFlagCursor + 8) = *(ushort *)(lightFlagCursor + 8) | 0x6000;
            }
            else {
              controlWordOffset = lightIndex * 4 + ctxBase124;
              *(uint *)(controlWordOffset + 0x284) = *(uint *)(controlWordOffset + 0x284) & 0x3fffffff | 0x80000000;
              *(ushort *)(lightFlagCursor + 8) = *(ushort *)(lightFlagCursor + 8) & 0x9fff | 0x4000;
            }
          }
          wordOffset = lightIndex * 4;
          dirtyBits = *lightDirtyPtr;
          if ((dirtyBits & 2) != 0) {
            if (((*(float *)(lightState + 0x10) == FLOAT_001aa0d4) &&
                (*(float *)(lightState + 0x14) == FLOAT_001aa0d4)) &&
               (*(float *)(lightState + 0x18) == FLOAT_001aa0d4)) {
              *(uint *)(wordOffset + ctxBase124 + 0x284) = *(uint *)(wordOffset + ctxBase124 + 0x284) & 0xcfffffff;
              *(ushort *)(lightFlagCursor + 8) = *(ushort *)(lightFlagCursor + 8) & 0xe7ff;
              dirtyBits = *lightDirtyPtr;
            }
            else if (((*(float *)(lightState + 0x10) == FLOAT_001aa0e8) &&
                     (*(float *)(lightState + 0x14) == FLOAT_001aa0e8)) &&
                    (*(float *)(lightState + 0x18) == FLOAT_001aa0e8)) {
              *(uint *)(wordOffset + ctxBase124 + 0x284) =
                   *(uint *)(wordOffset + ctxBase124 + 0x284) & 0xcfffffff | 0x10000000;
              *(ushort *)(lightFlagCursor + 8) = *(ushort *)(lightFlagCursor + 8) & 0xe7ff | 0x800;
              dirtyBits = *lightDirtyPtr;
            }
            else {
              *(uint *)(wordOffset + ctxBase124 + 0x284) =
                   *(uint *)(wordOffset + ctxBase124 + 0x284) & 0xcfffffff | 0x20000000;
              *(ushort *)(lightFlagCursor + 8) = *(ushort *)(lightFlagCursor + 8) & 0xe7ff | 0x1000;
              dirtyBits = *lightDirtyPtr;
            }
          }
          if ((dirtyBits & 4) != 0) {
            if (((*(float *)(lightState + 0x20) == FLOAT_001aa0d4) &&
                (*(float *)(lightState + 0x24) == FLOAT_001aa0d4)) &&
               (*(float *)(lightState + 0x28) == FLOAT_001aa0d4)) {
              *(uint *)(wordOffset + ctxBase124 + 0x284) = *(uint *)(wordOffset + ctxBase124 + 0x284) & 0xf3ffffff;
              *(ushort *)(lightFlagCursor + 8) = *(ushort *)(lightFlagCursor + 8) & 63999;
              dirtyBits = *lightDirtyPtr;
            }
            else if (((*(float *)(lightState + 0x20) == FLOAT_001aa0e8) &&
                     (*(float *)(lightState + 0x24) == FLOAT_001aa0e8)) &&
                    (*(float *)(lightState + 0x28) == FLOAT_001aa0e8)) {
              *(uint *)(wordOffset + ctxBase124 + 0x284) =
                   *(uint *)(wordOffset + ctxBase124 + 0x284) & 0xf3ffffff | 0x4000000;
              *(ushort *)(lightFlagCursor + 8) = *(ushort *)(lightFlagCursor + 8) & 63999 | 0x200;
              dirtyBits = *lightDirtyPtr;
            }
            else {
              *(uint *)(wordOffset + ctxBase124 + 0x284) =
                   *(uint *)(wordOffset + ctxBase124 + 0x284) & 0xf3ffffff | 0x8000000;
              *(ushort *)(lightFlagCursor + 8) = *(ushort *)(lightFlagCursor + 8) & 63999 | 0x400;
              dirtyBits = *lightDirtyPtr;
            }
          }
          if ((dirtyBits & 0x20) != 0) {
            if ((*(float *)(lightState + 0x54) == FLOAT_001aa0d4) &&
               (*(float *)(lightState + 0x58) == FLOAT_001aa0d4)) {
              if ((*(float *)(lightState + 0x50) == oneConst) ||
                 (*(float *)(lightState + 0x50) == FLOAT_001aa0d4)) {
                *(uint *)(wordOffset + ctxBase124 + 0x284) = *(uint *)(wordOffset + ctxBase124 + 0x284) & 0xfcffffff
                ;
                *(ushort *)(lightFlagCursor + 8) = *(ushort *)(lightFlagCursor + 8) & 0xffe7;
              }
              else {
                *(uint *)(wordOffset + ctxBase124 + 0x284) = *(uint *)(wordOffset + ctxBase124 + 0x284) | 0x3000000;
                *(ushort *)(lightFlagCursor + 8) = *(ushort *)(lightFlagCursor + 8) | 0x18;
                *(byte *)(lightDirtyCursor + 0x181c) = *(byte *)(lightDirtyCursor + 0x181c) | 4;
              }
            }
            else {
              *(uint *)(wordOffset + ctxBase124 + 0x284) =
                   *(uint *)(wordOffset + ctxBase124 + 0x284) & 0xfeffffff | 0x2000000;
              *(ushort *)(lightFlagCursor + 8) = *(ushort *)(lightFlagCursor + 8) & 0xfff7 | 0x10;
            }
          }
          if (*(float *)(lightState + 0x3c) == FLOAT_001aa0d4) {
            if (*(char *)(ctx + 0x12f) == '\0') {
              copyWord0 = lightCache[0x15];
              copyWord1 = lightCache[0x16];
              copyWord2 = lightCache[0x17];
              *(undefined4 *)(lightCopyCursor + 0x174) = lightCache[0x14];
              *(undefined4 *)(lightCopyCursor + 0x178) = copyWord0;
              *(undefined4 *)(lightCopyCursor + 0x17c) = copyWord1;
              *(undefined4 *)(lightCopyCursor + 0x180) = copyWord2;
              copyWord0 = lightCache[0x10];
              copyWord1 = lightCache[0x11];
              copyWord2 = lightCache[0x12];
              *(undefined4 *)(lightCopyCursor + 0x200) = lightCache[0x13];
              *(undefined4 *)(lightCopyCursor + 500) = copyWord0;
              *(undefined4 *)(lightCopyCursor + 0x1f8) = copyWord1;
              *(undefined4 *)(lightCopyCursor + 0x1fc) = copyWord2;
            }
            else {
              copyWord0 = lightCache[0xd];
              copyWord1 = lightCache[0xe];
              copyWord2 = lightCache[0xf];
              *(undefined4 *)(lightCopyCursor + 0x174) = lightCache[0xc];
              *(undefined4 *)(lightCopyCursor + 0x178) = copyWord0;
              *(undefined4 *)(lightCopyCursor + 0x17c) = copyWord1;
              *(undefined4 *)(lightCopyCursor + 0x180) = copyWord2;
              copyWord0 = lightCache[8];
              copyWord1 = lightCache[9];
              copyWord2 = lightCache[10];
              *(undefined4 *)(lightCopyCursor + 0x200) = lightCache[0xb];
              *(undefined4 *)(lightCopyCursor + 500) = copyWord0;
              *(undefined4 *)(lightCopyCursor + 0x1f8) = copyWord1;
              *(undefined4 *)(lightCopyCursor + 0x1fc) = copyWord2;
            }
          }
          else {
            copyWord0 = *lightCache;
            copyWord1 = lightCache[2];
            copyWord2 = lightCache[3];
            *(undefined4 *)(lightCopyCursor + 0x178) = lightCache[1];
            *(undefined4 *)(lightCopyCursor + 0x174) = copyWord0;
            *(undefined4 *)(lightCopyCursor + 0x17c) = copyWord1;
            *(undefined4 *)(lightCopyCursor + 0x180) = copyWord2;
            normalXTemp = GH_U2F((unsigned int)(lightCache[4]));
            normalYTemp = GH_U2F((unsigned int)(lightCache[5]));
            *(float *)(lightCopyCursor + 0x1fc) = -GH_U2F((unsigned int)(lightCache[6]));
            *(float *)(lightCopyCursor + 500) = -normalXTemp;
            *(float *)(lightCopyCursor + 0x1f8) = -normalYTemp;
            *(uint *)(wordOffset + ctxBase124 + 0x284) =
                 (uint)(*(float *)(lightState + 0x3c) == oneConst) << 0x17 |
                 *(uint *)(wordOffset + ctxBase124 + 0x284) & 0xff7fffff;
          }
          *lightDirtyPtr = 0;
        }
        if (*(char *)(lightDirtyCursor + 0x181c) != '\0') {
          *(undefined1 *)(lightDirtyCursor + 0x181c) = 0;
        }
        secondaryColorBits = secondaryColorBits | -(uint)(*(uint *)(lightIndex * 4 + ctxBase124 + 0x284) >> 0x1a & 3) >> 0x1f;
      }
      secondaryColorNeeded = SUB41(secondaryColorBits,0);
      lightMaskShifting = lightMaskShifting >> 1;
      lightIndex = lightIndex + 1;
      lightCacheOffset = lightCacheOffset + 0x6c;
      lightFlagCursor = (uint *)((int)lightFlagCursor + 2);
      lightDirtyCursor = lightDirtyCursor + 1;
      lightCopyCursor = lightCopyCursor + 0x10;
    } while (lightMaskShifting != 0);
    if (needsLightModelSum) {
      *(undefined4 *)(ctx + 0x3a0) = 0;
      *(undefined4 *)(ctx + 0x398) = 0;
      *(undefined4 *)(ctx + 0x39c) = 0;
      *ctxFlags1874Ptr = *ctxFlags1874Ptr | 4;
      lightMaskCursor = *(uint *)(ctx + 0x88);
      if (lightMaskCursor != 0) {
        lightStateOffset = 0x24c0;
        lightControlCursor = (uint *)(ctx + 0x3a8);
        do {
          if (((lightMaskCursor & 1) != 0) && (*lightControlCursor >> 0x1e == 3)) {
            *(float *)(ctx + 0x398) = *(float *)(ctx + 0x398) + *(float *)(stateBlock + lightStateOffset);
            *(float *)(ctx + 0x39c) =
                 *(float *)(ctx + 0x39c) + *(float *)(stateBlock + lightStateOffset + 4);
            *(float *)(ctx + 0x3a0) =
                 *(float *)(ctx + 0x3a0) + *(float *)(stateBlock + lightStateOffset + 8);
          }
          lightMaskCursor = lightMaskCursor >> 1;
          lightControlCursor = lightControlCursor + 1;
          lightStateOffset = lightStateOffset + 0x80;
        } while (lightMaskCursor != 0);
      }
    }
  }
  *(bool *)(ctx + 0x12d) = secondaryColorNeeded;
  return;
}

/* fpVariantCacheFlush @ 0x9c700 (248 bytes) */
int fpVariantCacheFlush(ctx)
  int ctx;
{
  int bucketOffset;
  int bucketTable;
  undefined4 a1;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  uint loopIndex;
  int a0;
  
  loopIndex = 0;
  if (*(int *)(((unsigned char *)0x0000111c) + ctx) != 0) {
    do {
      bucketTable = *(int *)(((unsigned char *)0x00001118) + ctx);
      bucketOffset = loopIndex * 4;
      a0 = *(int *)(bucketOffset + bucketTable);
      while (a0 != 0) {
        *(undefined4 *)(bucketOffset + bucketTable) = *(undefined4 *)(a0 + 0x5c);
        ((int (*)())fpVariantProgramFree)(ctx,*(undefined4 *)(a0 + 0x54));
        if (*(int *)(a0 + 0x4c) != 0) {
          (**(code **)(ctx + 0x18))(*(int *)(a0 + 0x4c));
        }
        (**(code **)(ctx + 0x18))(*(undefined4 *)(a0 + 0x50));
        (**(code **)(ctx + 0x18))(a0,a1,in_r5,in_r6,in_r7,in_r8,*(code **)(ctx + 0x18));
        bucketTable = *(int *)(((unsigned char *)0x00001118) + ctx);
        a0 = *(int *)(bucketOffset + bucketTable);
      }
      loopIndex = loopIndex + 1;
      *(undefined4 *)(bucketOffset + bucketTable) = 0;
    } while (loopIndex < *(uint *)(((unsigned char *)0x0000111c) + ctx));
  }
  *(undefined4 *)(((unsigned char *)0x0000148c) + ctx) = 0;
  *(undefined4 *)(ctx + 0x3c8) = 0;
  *(undefined4 *)(ctx + 0x14c) = 0;
  return;
}

/* fpVariantCacheInsert @ 0x9c800 (744 bytes) */
int fpVariantCacheInsert(ctx, key, program, dependencyA, dependencyB, constRegCount, paramList, flag)
  int ctx;
  uint *key;
  int program;
  undefined4 dependencyA;
  undefined4 dependencyB;
  int constRegCount;
  undefined4 *paramList;
  undefined4 flag;
{
  undefined4 constBytes;
  uint rotate;
  uint *keyCursor;
  undefined4 programInstrCount;
  uint hash;
  uint rotateCounter;
  int entry;
  int newParamList;
  uint entrySerial;
  uint *keyEnd;
  uint *keyTail;
  int bucketIndex;
  
  entry = (**(code **)(ctx + 0xc))(0x60,key,program,dependencyA,dependencyB,constRegCount,paramList,flag)
  ;
  entrySerial = *(uint *)(ctx + 0x3c8);
  if (1000000 < entrySerial) {
    ((int (*)())fpVariantCacheFlush)(ctx);
    entrySerial = *(uint *)(ctx + 0x3c8);
  }
  if (((unsigned char *)0x00001120)[ctx] == '\0') {
    keyEnd = key + 0xc;
    hash = 0;
    keyCursor = key;
    while (keyCursor + 0xb <= keyEnd) {
      hash = hash ^ *keyCursor ^ (keyCursor[1] << 3 | keyCursor[1] >> 0x1d) ^
              (keyCursor[2] << 6 | keyCursor[2] >> 0x1a) ^ (keyCursor[3] << 9 | keyCursor[3] >> 0x17) ^
              (keyCursor[4] << 0xc | keyCursor[4] >> 0x14) ^ (keyCursor[5] << 0xf | keyCursor[5] >> 0x11) ^
              (keyCursor[6] << 0x12 | keyCursor[6] >> 0xe) ^ (keyCursor[7] << 0x15 | keyCursor[7] >> 0xb) ^
              (keyCursor[8] << 0x18 | keyCursor[8] >> 8) ^ (keyCursor[9] << 0x1b | keyCursor[9] >> 5) ^
              (keyCursor[10] << 0x1e | keyCursor[10] >> 2);
      keyCursor = keyCursor + 0xb;
    }
    keyTail = keyCursor + 5;
    if (keyEnd < keyTail) {
      rotateCounter = 0;
      keyTail = keyCursor;
    }
    else {
      rotateCounter = 0xf;
      hash = hash ^ *keyCursor ^ (keyCursor[1] << 3 | keyCursor[1] >> 0x1d) ^
              (keyCursor[2] << 6 | keyCursor[2] >> 0x1a) ^ (keyCursor[3] << 9 | keyCursor[3] >> 0x17) ^
              (keyCursor[4] << 0xc | keyCursor[4] >> 0x14);
    }
    for (; keyTail < keyEnd; keyTail = keyTail + 1) {
      rotate = rotateCounter & 0x1f;
      rotateCounter = rotateCounter + 3;
      hash = hash ^ (*keyTail << rotate | *keyTail >> 0x20 - rotate);
    }
    bucketIndex = hash - (hash / *(uint *)(((unsigned char *)0x0000111c) + ctx)) *
                     *(uint *)(((unsigned char *)0x0000111c) + ctx);
  }
  else {
    hash = *key + key[2] + key[3];
    bucketIndex = hash - (hash / *(uint *)(((unsigned char *)0x0000111c) + ctx)) *
                     *(uint *)(((unsigned char *)0x0000111c) + ctx);
  }
  *(uint *)(entry + 0x30) = entrySerial;
  *(int *)(ctx + 0x3c8) = *(int *)(ctx + 0x3c8) + 1;
  _memcpy(entry,key,0x30);
  *(undefined4 *)(entry + 0x3c) = dependencyA;
  *(undefined4 *)(entry + 0x40) = dependencyB;
  *(int *)(entry + 0x54) = program;
  programInstrCount = *(undefined4 *)(program + 0x3d0);
  *(int *)(entry + 0x48) = constRegCount;
  *(undefined4 *)(entry + 0x44) = programInstrCount;
  if (paramList == (undefined4 *)0x0) {
    newParamList = ((int (*)())paramListCreate)(ctx);
    *(int *)(entry + 0x50) = newParamList;
    *(undefined4 *)(newParamList + 8) = 0;
    *(undefined4 *)(entry + 0x4c) = 0;
    *(undefined1 *)(entry + 0x58) = 0;
  }
  else {
    *(undefined4 **)(entry + 0x50) = paramList;
    if (((paramList[2] == 1) && (*(int *)*paramList == 0)) && (*(int *)paramList[1] == 0)) {
      *(undefined1 *)(entry + 0x58) = 1;
      *(undefined4 *)(entry + 0x4c) = 0;
    }
    else {
      *(undefined1 *)(entry + 0x58) = 0;
      constBytes = (**(code **)(ctx + 0xc))(constRegCount << 4);
      *(undefined4 *)(entry + 0x4c) = constBytes;
    }
  }
  *(char *)(entry + 0x59) = (char)flag;
  *(undefined4 *)(entry + 0x5c) = *(undefined4 *)(*(int *)(((unsigned char *)0x00001118) + ctx) + bucketIndex * 4);
  *(int *)(bucketIndex * 4 + *(int *)(((unsigned char *)0x00001118) + ctx)) = entry;
  return entry;
}

/* fpVariantEntryRecomputeDependencies @ 0x9cb10 (280 bytes) */
int fpVariantEntryRecomputeDependencies(ctx, entry, depRecord, instrBytes)
  int ctx;
  int entry;
  int depRecord;
  int instrBytes;
{
  undefined4 scratchCopy;
  int depStatus;
  undefined4 instrCount;
  int program;
  int newInstrCount;
  undefined4 outDepA;
  undefined4 outDepB;
  undefined4 outDepC [4];
  
  program = *(int *)(entry + 0x54);
  scratchCopy = (**(code **)(ctx + 0xc))(instrBytes * *(int *)(program + 0x3cc),entry,depRecord,instrBytes);
  *(undefined4 *)(depRecord + 4) = *(undefined4 *)(program + 0x3c8);
  instrCount = *(undefined4 *)(program + 0x3cc);
  *(int **)(depRecord + 0x1c) = &newInstrCount;
  *(undefined4 **)(depRecord + 0x28) = &outDepA;
  *(undefined4 *)(depRecord + 0x18) = scratchCopy;
  *(undefined4 **)(depRecord + 0x2c) = &outDepB;
  *(undefined4 *)(depRecord + 8) = instrCount;
  *(undefined4 **)(depRecord + 0x30) = outDepC;
  depStatus = recordProgramBuildDependencies(depRecord);
  if (depStatus == 0) {
    _memcpy(*(undefined4 *)(program + 0x3c8),scratchCopy,instrBytes * newInstrCount);
    *(int *)(program + 0x3cc) = newInstrCount;
    *(undefined4 *)(entry + 0x38) = outDepB;
    *(undefined4 *)(entry + 0x44) = outDepC[0];
    *(undefined4 *)(entry + 0x34) = outDepA;
  }
  else {
    _memcpy(*(undefined4 *)(program + 0x3c8),scratchCopy,instrBytes * *(int *)(program + 0x3cc));
  }
  (**(code **)(ctx + 0x18))(scratchCopy);
  return depStatus == 0;
}

/* ffvpBuildLightKey @ 0x9cc30 (712 bytes) */
int ffvpBuildLightKey(ctx)
  int ctx;
{
  uint keyBit24;
  uint lightMaskCursorB;
  uint lightMaskCursor;
  uint keyBit10;
  int lightCountdown;
  int lightControlBase;
  int lightsKeyBit;
  ushort oldLightKey;
  uint keyBit29;
  uint keyBit26;
  bool anyDirectionalLight;
  ushort lightKeyBit8;
  ushort lightKeyBit7;
  ushort lightKeyBit5;
  ushort lightKeyBits13to14;
  ushort lightKeyBits11to12;
  ushort lightKeyBits9to10;
  ushort lightKeyBit6;
  ushort lightKeyBit4;
  float zeroConst;
  float oneConst;
  uint oldKey;
  uint keyPartial;
  int lightWordOffset;
  uint ctxFlags44;
  int lightStateCursor;
  bool anyPositionalLight;
  uint colorMaterialLights;
  ushort *lightKeyCursor;
  int stateBlock;
  bool lightIsDirectional;
  int lightCountdownB;
  
  stateBlock = *(int *)(*(int *)(ctx + 4) + 0x10);
  if (*(char *)(stateBlock + 0x24ad) == '\0') {
    ctxFlags44 = *(uint *)(ctx + 0x44);
    anyPositionalLight = false;
    anyDirectionalLight = false;
    colorMaterialLights = 0;
  }
  else {
    ctxFlags44 = *(uint *)(ctx + 0x44);
    if (((int)ctxFlags44 < 0) && (lightMaskCursorB = *(uint *)(ctx + 0x88), lightMaskCursorB != 0)) {
      anyPositionalLight = false;
      anyDirectionalLight = false;
      lightStateCursor = stateBlock;
      do {
        if ((lightMaskCursorB & 1) != 0) {
          lightIsDirectional = *(float *)(lightStateCursor + 0x24fc) == FLOAT_001aa0d4;
          anyDirectionalLight = (bool)(lightIsDirectional | anyDirectionalLight);
          anyPositionalLight = (bool)(!lightIsDirectional | anyPositionalLight);
        }
        lightMaskCursorB = lightMaskCursorB >> 1;
        lightStateCursor = lightStateCursor + 0x80;
      } while (lightMaskCursorB != 0);
    }
    else {
      anyPositionalLight = false;
      anyDirectionalLight = false;
    }
    colorMaterialLights = -(uint)(*(uint *)(ctx + 0x8c) & 0xc000000) >> 0x1f;
  }
  oldKey = *(uint *)(ctx + 0x1874);
  keyBit29 = ((byte)((unsigned char *)0x00002d48)[stateBlock + 5] & 1) << 0x1d;
  keyBit26 = (*(byte *)(ctx + 300) & 1) << 0x1a;
  *(uint *)(ctx + 0x1874) = keyBit26 | keyBit29 | oldKey & 0xdbffffff;
  if (((colorMaterialLights != 0) || (anyPositionalLight)) || (lightsKeyBit = 0, anyDirectionalLight)) {
    lightsKeyBit = 1;
  }
  keyBit24 = lightsKeyBit << 0x18;
  keyPartial = keyBit24 | keyBit26 | keyBit29 | oldKey & 0xdaffffff;
  *(uint *)(ctx + 0x1874) = keyPartial;
  if ((int)ctxFlags44 < 0) {
    lightMaskCursor = *(uint *)(ctx + 0x88);
    lightCountdownB = 8;
    *(uint *)(ctx + 0x1874) = keyPartial | 0x800;
    oneConst = FLOAT_001aa0e8;
    zeroConst = FLOAT_001aa0d4;
    lightKeyCursor = (ushort *)(ctx + 0x1894);
    lightWordOffset = 0;
    lightControlBase = ctx + 0x3a8;
    keyBit10 = (uint)(*(short *)(((unsigned char *)0x00002d48) + stateBlock) == -0x7e06) << 10;
    *(uint *)(ctx + 0x1874) = keyBit10 | keyBit24 | keyBit26 | keyBit29 | oldKey & 0xdafffbff | 0x800;
    *(uint *)(ctx + 0x1874) =
         (*(byte *)(ctx + 0x12d) & 1) << 8 |
         ((byte)((unsigned char *)0x00002d48)[stateBlock + 4] & 1) << 9 |
         keyBit10 | keyBit24 | keyBit26 | keyBit29 | oldKey & 0xdafff8ff | 0x800;
    do {
      if ((lightMaskCursor & 1) == 0) {
        *lightKeyCursor = 0;
      }
      else {
        oldLightKey = *lightKeyCursor;
        *lightKeyCursor = oldLightKey | 0x8000;
        lightKeyBits13to14 = (ushort)((uint)*(undefined4 *)(lightControlBase + lightWordOffset) >> 0x11) & 0x6000;
        *lightKeyCursor = lightKeyBits13to14 | oldLightKey & 0x9fff | 0x8000;
        lightKeyBits11to12 = (*(byte *)(lightControlBase + lightWordOffset) & 0x30) << 7;
        *lightKeyCursor = lightKeyBits13to14 | oldLightKey & 0x87ff | 0x8000 | lightKeyBits11to12;
        lightKeyBits9to10 = (*(byte *)(lightControlBase + lightWordOffset) & 0xc) << 7;
        *lightKeyCursor = lightKeyBits13to14 | oldLightKey & 0x81ff | 0x8000 | lightKeyBits11to12 | lightKeyBits9to10;
        lightKeyBit8 = (ushort)(*(float *)(stateBlock + 0x24fc) != zeroConst) << 8;
        *lightKeyCursor = lightKeyBits13to14 | oldLightKey & 0x80ff | 0x8000 | lightKeyBits11to12 | lightKeyBits9to10 | lightKeyBit8;
        lightKeyBit7 = (ushort)(*(float *)(stateBlock + 0x24fc) == oneConst) << 7;
        *lightKeyCursor = lightKeyBits13to14 | oldLightKey & 0x807f | 0x8000 | lightKeyBits11to12 | lightKeyBits9to10 | lightKeyBit8 | lightKeyBit7;
        lightKeyBit6 = ((byte)((unsigned char *)0x0000150c)[ctx] & 1) << 6;
        *lightKeyCursor = lightKeyBits13to14 | oldLightKey & 0x803f | 0x8000 | lightKeyBits11to12 | lightKeyBits9to10 | lightKeyBit8 | lightKeyBit7 | lightKeyBit6;
        lightKeyBit5 = (ushort)(*(float *)(stateBlock + 0x251c) != zeroConst) << 5;
        *lightKeyCursor = lightKeyBits13to14 | oldLightKey & 0x801f | 0x8000 | lightKeyBits11to12 | lightKeyBits9to10 | lightKeyBit8 | lightKeyBit7 | lightKeyBit6 | lightKeyBit5
        ;
        lightKeyBit4 = (ushort)((uint)*(undefined4 *)(lightControlBase + lightWordOffset) >> 0x15) & 0x10;
        *lightKeyCursor = lightKeyBit4 | lightKeyBits13to14 | oldLightKey & 0x800f | 0x8000 | lightKeyBits11to12 | lightKeyBits9to10 | lightKeyBit8 | lightKeyBit7 |
                            lightKeyBit6 | lightKeyBit5;
        *lightKeyCursor = lightKeyBit4 | lightKeyBits13to14 | oldLightKey & 0x8007 | 0x8000 | lightKeyBits11to12 | lightKeyBits9to10 | lightKeyBit8 | lightKeyBit7 |
                            lightKeyBit6 | lightKeyBit5 | (*(byte *)(lightControlBase + lightWordOffset) & 1) << 3;
      }
      lightMaskCursor = lightMaskCursor >> 1;
      lightKeyCursor = lightKeyCursor + 1;
      lightWordOffset = lightWordOffset + 4;
      stateBlock = stateBlock + 0x80;
      ctx = ctx + 0x6c;
      lightCountdownB = lightCountdownB + -1;
    } while (lightCountdownB != 0);
  }
  else {
    lightCountdown = 8;
    *(uint *)(ctx + 0x1874) =
         -(ctxFlags44 & 0xa10000) >> 0x18 & 0x80 | keyBit24 | keyBit26 | keyBit29 | oldKey & 0xdafff07f;
    do {
      *(undefined2 *)(ctx + 0x1894) = 0;
      ctx = ctx + 2;
      lightCountdown = lightCountdown + -1;
    } while (lightCountdown != 0);
  }
  return;
}

/* ffvpBuildFogKey @ 0x9cf10 (224 bytes) */
int ffvpBuildFogKey(ctx, unusedArg2, unusedArg3, unusedArg4, unusedArg5, unusedArg6)
  int ctx;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
{
  short fogDistanceMode;
  short fogMode;
  int stateBlock;
  uint fogCode;
  
  stateBlock = *(int *)(*(int *)(ctx + 4) + 0x10);
  if (((*(uint *)(ctx + 0x44) & 0x1000000) != 0) && (*(char *)(ctx + 0x121) == '\0')) {
    fogMode = *(short *)(((unsigned char *)0x00002e04) + stateBlock);
    fogCode = 2;
    if ((fogMode != 0x801) && (fogCode = 3, fogMode != 0x2601)) {
      fogCode = (uint)(fogMode == 0x800);
    }
    *(uint *)(ctx + 0x1874) =
         (uint)(*(short *)(((unsigned char *)0x00002e06) + stateBlock) == -0x7baf) << 4 |
         fogCode << 5 | *(uint *)(ctx + 0x1874) & 0xffffff8f;
    fogDistanceMode = *(short *)(((unsigned char *)0x00002e08) + stateBlock);
    if (fogDistanceMode == -0x7aa5) {
      fogCode = 2;
    }
    else if (fogDistanceMode == -0x7aa4) {
      fogCode = 0;
    }
    else if (fogDistanceMode == 0x2502) {
      fogCode = 1;
    }
    *(uint *)(ctx + 0x1878) = fogCode << 0x12 | *(uint *)(ctx + 0x1878) & 0xfff3ffff;
    return;
  }
  *(uint *)(ctx + 0x1874) = *(uint *)(ctx + 0x1874) & 0xffffff8f;
  *(uint *)(ctx + 0x1878) = *(uint *)(ctx + 0x1878) & 0xfff3ffff;
  return;
}

/* ffvpBuildBlendKey @ 0x9cff0 (132 bytes) */
int ffvpBuildBlendKey(ctx)
  int ctx;
{
  byte blendFlag13a9;
  byte blendFlag13aa;
  uint oldKey;
  int stateBlock;
  
  stateBlock = *(int *)(*(int *)(ctx + 4) + 0x10);
  if ((((unsigned char *)0x00004301)[stateBlock] != '\0') && (*(byte *)(ctx + 0x91) != 0)) {
    oldKey = *(uint *)(ctx + 0x1874);
    blendFlag13a9 = ((unsigned char *)0x000013a9)[ctx];
    blendFlag13aa = ((unsigned char *)0x000013aa)[ctx];
    *(uint *)(ctx + 0x1874) = oldKey | 0x8000000;
    *(uint *)(ctx + 0x1874) =
         (blendFlag13aa & 1) << 0xf |
         (blendFlag13a9 & 1) << 0x10 |
         (*(byte *)(ctx + 0x91) & 7) << 0x11 |
         (uint)(*(char *)(ctx + 0x90) == '\x02') << 0x14 |
         (*(uint *)(ctx + 0x8c) & 0x80000) << 2 |
         ((byte)((unsigned char *)0x00004302)[stateBlock] & 1) << 0x16 | oldKey & 0xff807fff | 0x8000000;
    return;
  }
  *(uint *)(ctx + 0x1874) = *(uint *)(ctx + 0x1874) & 0xf7807fff;
  return;
}

/* ffvpUpdateLightModelFlags @ 0x9d080 (596 bytes) */
int ffvpUpdateLightModelFlags(ctx, unusedArg2, unusedArg3, unusedArg4, unusedArg5, unusedArg6)
  int ctx;
  undefined4 unusedArg2;
  undefined4 unusedArg3;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
{
  uint texGenNeedsNormal;
  uint lightMaskShifting;
  byte secondaryColorFlag;
  bool anyDirectionalLight;
  bool anyPositionalLight;
  float zeroConst;
  uint packedMaterialSources;
  undefined1 normalizeFlag;
  int stateBlock;
  byte separateSpecularLight;
  int lightStateCursor;
  uint *lightControlCursor;
  bool lightIsDirectional;
  
  stateBlock = *(int *)(*(int *)(ctx + 4) + 0x10);
  *(undefined1 *)(ctx + 0x128) = 0;
  *(undefined1 *)(ctx + 0x129) = 0;
  *(undefined1 *)(ctx + 0x130) = 0;
  *(undefined1 *)(ctx + 0x12a) = 0;
  if (*(int *)(ctx + 0x44) < 0) {
    if (*(int *)(ctx + 0x13c) == 1) {
      packedMaterialSources = *(uint *)(ctx + 0x26c);
      *(undefined4 *)(ctx + 0x290) = 2;
      *(uint *)(ctx + 0x278) = packedMaterialSources >> 4 & 0xf;
      *(uint *)(ctx + 0x270) = packedMaterialSources & 0xf;
      *(uint *)(ctx + 0x280) = packedMaterialSources >> 8 & 0xf;
      *(uint *)(ctx + 0x28c) = packedMaterialSources >> 0x1c;
      *(uint *)(ctx + 0x288) = packedMaterialSources >> 0xc & 0xf;
      *(uint *)(ctx + 0x274) = packedMaterialSources >> 0x10 & 0xf;
      *(uint *)(ctx + 0x27c) = packedMaterialSources >> 0x14 & 0xf;
      *(undefined4 *)(ctx + 0x294) = 3;
      *(uint *)(ctx + 0x284) = packedMaterialSources >> 0x18 & 0xf;
    }
    else {
      *(undefined4 *)(ctx + 0x280) = 2;
      *(undefined4 *)(ctx + 0x288) = 3;
      *(undefined4 *)(ctx + 0x290) = 0;
      *(undefined4 *)(ctx + 0x294) = 1;
      *(undefined4 *)(ctx + 0x274) = 4;
      *(undefined4 *)(ctx + 0x27c) = 5;
      *(undefined4 *)(ctx + 0x270) = 0;
      *(undefined4 *)(ctx + 0x278) = 1;
      *(undefined4 *)(ctx + 0x284) = 6;
      *(undefined4 *)(ctx + 0x28c) = 7;
    }
    zeroConst = FLOAT_001aa0d4;
    lightMaskShifting = *(uint *)(ctx + 0x88);
    if (lightMaskShifting != 0) {
      anyDirectionalLight = false;
      anyPositionalLight = false;
      lightControlCursor = (uint *)(ctx + 0x3a8);
      lightStateCursor = stateBlock;
      do {
        if ((lightMaskShifting & 1) != 0) {
          if ((((*lightControlCursor & 0xc000000) == 0) || (*(short *)(((unsigned char *)0x00002d48) + stateBlock) != -0x7e06)) ||
             (separateSpecularLight = 1, ((unsigned char *)0x00002d48)[stateBlock + 5] == '\0')) {
            separateSpecularLight = 0;
          }
          *(byte *)(ctx + 0x130) = separateSpecularLight | *(byte *)(ctx + 0x130);
          lightIsDirectional = *(float *)(lightStateCursor + 0x24fc) == zeroConst;
          anyDirectionalLight = (bool)(lightIsDirectional | anyDirectionalLight);
          anyPositionalLight = (bool)(!lightIsDirectional | anyPositionalLight);
        }
        lightMaskShifting = lightMaskShifting >> 1;
        lightControlCursor = lightControlCursor + 1;
        lightStateCursor = lightStateCursor + 0x80;
      } while (lightMaskShifting != 0);
      goto LAB_0009d228;
    }
  }
  anyDirectionalLight = false;
  anyPositionalLight = false;
LAB_0009d228:
  texGenNeedsNormal = *(uint *)(ctx + 0x8c) >> 0x1b & 1 | *(uint *)(ctx + 0x8c) >> 0x1a & 1;
  if ((texGenNeedsNormal == 0) || (separateSpecularLight = 1, ((unsigned char *)0x00002d48)[stateBlock + 5] == '\0')) {
    separateSpecularLight = 0;
  }
  separateSpecularLight = *(byte *)(ctx + 0x130) | separateSpecularLight;
  *(byte *)(ctx + 0x130) = separateSpecularLight;
  *(byte *)(ctx + 0x129) = anyPositionalLight | separateSpecularLight;
  if ((((texGenNeedsNormal == 0) && (!anyPositionalLight)) && (!anyDirectionalLight)) || (normalizeFlag = 1, *(char *)(stateBlock + 0x24ad) == '\0')) {
    normalizeFlag = 0;
  }
  *(undefined1 *)(ctx + 0x128) = normalizeFlag;
  if ((*(char *)(ctx + 0x12f) != '\0') || (secondaryColorFlag = 1, -1 < *(int *)(ctx + 0x44))) {
    secondaryColorFlag = 0;
  }
  *(byte *)(ctx + 0x12a) = secondaryColorFlag | (byte)texGenNeedsNormal;
  return;
}

/* ffvpRunStateHook @ 0x9d2e0 (184 bytes) */
int ffvpRunStateHook(ctx)
  int ctx;
{
  code *UNRECOVERED_JUMPTABLE;
  int hookArg;
  
  if (*(char *)(ctx + 0x3d4) != '\0') {
    return;
  }
  if (*(char *)(ctx + 0x124) == '\0') {
    if ((*(uint *)(ctx + 0x44) & 0x100000) != 0) {
      return;
    }
    hookArg = *(int *)(ctx + 0x14c);
    if (hookArg == 0) {
      return;
    }
    (**(code **)(((unsigned char *)0x000012d0) + ctx))(ctx,hookArg);
    UNRECOVERED_JUMPTABLE = *(code **)(((unsigned char *)0x000012c4) + ctx);
  }
  else {
    hookArg = *(int *)(ctx + 0x14c);
    if (hookArg == 0) {
      return;
    }
    UNRECOVERED_JUMPTABLE = *(code **)(((unsigned char *)0x000012d0) + ctx);
  }
                    
                    
  (*UNRECOVERED_JUMPTABLE)(ctx,hookArg);
  return;
}

/* gldValidateVertexProgramState @ 0x9d3b0 (64 bytes) */
int gldValidateVertexProgramState(ctx, arg2, param_3, param_4, param_5, param_6, param_7)
  int ctx;
  undefined4 arg2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  if (ctx == 0) {
    return;
  }
  *(undefined1 *)(ctx + 0x3d4) = 0;
  if ((*(uint *)(ctx + 0x44) & 0x100000) != 0) {
    if (*(char *)(ctx + 0x1868) != '\0') {
                    
                    
      (**(code **)((int)((unsigned char *)0x000011cc) + ctx))();
      return;
    }
    extvsValidateProgramState(ctx,arg2);
    return;
  }
  ((int (*)())ffvpRunStateHook)(ctx);
  return;
}

/* ffvpBuildProgram @ 0x9d410 (5944 bytes) */
int ffvpBuildProgram(ctx, passThroughArg2, passThroughArg3, constRegCountOut, paramList, unusedArg6, unusedArg7, unusedArg8)
  int ctx;
  undefined4 passThroughArg2;
  undefined4 passThroughArg3;
  int *constRegCountOut;
  int *paramList;
  undefined4 unusedArg6;
  undefined4 unusedArg7;
  undefined4 unusedArg8;
{
  int lightIndex;
  int ctxUnitCursor;
  int activeLightCount;
  int texUnitCtxCursor;
  int genIndex;
  int lastParamReg;
  int programTypeResult;
  int emittedLightIndex;
  int regPlus1;
  int paramCountSnapshot;
  int regCursor;
  int ctxCursor;
  int matrixLoopCount;
  int lightStateCursor;
  int texUnitStateCursor;
  float zeroConst;
  undefined4 paramKind;
  uint lightControlWord;
  int lastActiveLight;
  int texUnitEnableCursor;
  uint lightMaskLoop;
  uint texUnitIndex;
  uint ctxByte11d2;
  uint lightMaskCopy;
  uint texUnitCount;
  uint texUnitLimit;
  uint tableCount;
  uint lightMaskShifting;
  uint ctxFlags44;
  uint unitMask;
  uint matrixIndex;
  byte lightEnableByte;
  byte matrixCountByte;
  short fogMode;
  bool needsLightModelParam;
  uint ctxFlags8c;
  uint texGenFlags;
  uint ctxFlags44B;
  int programRecord;
  int nextConstReg;
  uint texUnitIndexMap;
  undefined4 programFlag;
  int *mapCursorA;
  float matrixCursor;
  int *mapCursorB;
  int regAfterLightPair;
  int regAfterFour;
  int regPlus4;
  int paramKinds;
  int unaff_r17;
  int unaff_r18;
  float unaff_r19;
  undefined4 ctxFlag400Active;
  int stateBlock;
  int stateBlockCopy;
  int *paramMapCursor;
  uint *lightControlPtr;
  int unitKindIndex;
  ushort *texCoordMapPtr;
  int unitCountdown;
  float local_78;
  uint local_74 [4];
  float local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  float local_50;
  int local_4c;
  int local_48;
  
  stateBlock = *(int *)(*(int *)(ctx + 4) + 0x10);
  if ((*(uint *)(ctx + 0x1874) & 0xc0000000) != 0x40000000) {
    ctxFlags44B = *(uint *)(ctx + 0x44);
    goto LAB_0009d494;
  }
  if ((*(uint *)(ctx + 0x8c) & 0x800000) != 0) {
    ctxFlags44B = *(uint *)(ctx + 0x44);
    goto LAB_0009d4b8;
  }
  ctxFlags44B = *(uint *)(ctx + 0x44);
  if ((ctxFlags44B & 0x20000) == 0) {
LAB_0009d494:
    programFlag = 0;
  }
  else {
    if ((ctxFlags44B & 0x2000) == 0) {
      if (((unsigned char *)0x00001135)[ctx] != '\0') goto LAB_0009d4b8;
      goto LAB_0009d494;
    }
    if (((unsigned char *)0x000011d3)[ctx] == '\0') goto LAB_0009d494;
LAB_0009d4b8:
    programFlag = 1;
    if ((*(uint *)(((unsigned char *)0x000013c0) + ctx) & 1) == 0) goto LAB_0009d494;
  }
  if (((ctxFlags44B & 0x400) == 0) || (ctxFlag400Active = 1, (*(uint *)(((unsigned char *)0x000013c0) + ctx) & 2) == 0)) {
    ctxFlag400Active = 0;
  }
  ctxByte11d2 = (uint)(byte)((unsigned char *)0x000011d2)[ctx];
  programRecord = ffvpCreateBuilder(ctx,passThroughArg2,programFlag);
  (**(code **)(((unsigned char *)0x000012c0) + ctx))(ctx,programRecord,&local_78,passThroughArg3);
  if (*(int *)(ctx + 0x13c) == 1) {
    _memcpy(programRecord,ctx + 0x19c,0x68);
  }
  else {
    _memcpy(programRecord,ctx + 0x204,0x68);
  }
  paramMapCursor = (int *)(programRecord + 0xa4);
  stateBlockCopy = *(int *)(*(int *)(ctx + 4) + 0x10);
  _memset(paramMapCursor,0xffffffff,0x324);
  paramList[2] = 0;
  if (((unsigned char *)0x00004301)[stateBlockCopy] == '\0') {
    local_78 = GH_U2F((unsigned int)((stateBlockCopy + 0x2460)));
    nextConstReg = 0;
    if ((((((local_74[0] != 0 || local_74[1] != 0) || local_74[2] != 0) ||
          FLOAT_001aa0e8 != local_78) ||
         (((local_74[3] != 0 || local_60 != 0) || local_5c != 0) || FLOAT_001aa0e8 != local_64)) ||
        (((local_58 != 0 || local_54 != 0) || local_4c != 0) || FLOAT_001aa0e8 != local_50)) ||
        (((local_48 != 0 || unaff_r17 != 0) || unaff_r18 != 0) || FLOAT_001aa0e8 != unaff_r19)) {
      *(undefined4 *)(programRecord + 0xa4) = 0;
      nextConstReg = 4;
      *(undefined4 *)(paramList[2] * 4 + *paramList) = 0;
      *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
      paramList[2] = paramList[2] + 1;
    }
    ctxFlags8c = *(uint *)(ctx + 0x8c);
    if ((ctxFlags8c & 0x80000) != 0) {
      *(int *)(programRecord + 0xb4) = nextConstReg;
      regPlus4 = nextConstReg + 4;
      nextConstReg = nextConstReg + 8;
      *(undefined4 *)(paramList[2] * 4 + *paramList) = 1;
      *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
      paramList[2] = paramList[2] + 1;
      *(int *)(programRecord + 0xc4) = regPlus4;
      *(undefined4 *)(paramList[2] * 4 + *paramList) = 2;
      *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
      paramList[2] = paramList[2] + 1;
      ctxFlags8c = *(uint *)(ctx + 0x8c);
    }
  }
  else {
    matrixCountByte = ((unsigned char *)0x00004300)[stateBlockCopy];
    nextConstReg = 0;
    matrixLoopCount = 4;
    matrixIndex = 0;
    matrixCursor = GH_U2F((unsigned int)((stateBlockCopy + 0x1960)));
    mapCursorA = paramMapCursor;
    do {
      if (((1 << (matrixCountByte & 0x3f)) - 1U & 1 << (matrixIndex & 0x3f)) != 0) {
        if ((((((local_74[0] != 0 || local_74[1] != 0) || local_74[2] != 0) ||
              FLOAT_001aa0e8 != matrixCursor) ||
             (((local_74[3] != 0 || local_60 != 0) || local_5c != 0) || FLOAT_001aa0e8 != local_64))
            || (((local_58 != 0 || local_54 != 0) || local_4c != 0) || FLOAT_001aa0e8 != local_50))
            || (((local_48 != 0 || unaff_r17 != 0) || unaff_r18 != 0) || FLOAT_001aa0e8 != unaff_r19
               )) {
          *mapCursorA = nextConstReg;
          nextConstReg = nextConstReg + 4;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0;
          *(uint *)(paramList[2] * 4 + paramList[1]) = matrixIndex;
          paramList[2] = paramList[2] + 1;
        }
        local_78 = matrixCursor;
        if ((*(uint *)(ctx + 0x8c) & 0x80000) != 0) {
          mapCursorA[4] = nextConstReg;
          regAfterFour = nextConstReg + 4;
          nextConstReg = nextConstReg + 8;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 1;
          *(uint *)(paramList[2] * 4 + paramList[1]) = matrixIndex;
          paramList[2] = paramList[2] + 1;
          mapCursorA[8] = regAfterFour;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 2;
          *(uint *)(paramList[2] * 4 + paramList[1]) = matrixIndex;
          paramList[2] = paramList[2] + 1;
        }
      }
      matrixIndex = matrixIndex + 1;
      matrixCursor = GH_U2F((unsigned int)(((int)GH_F2U(matrixCursor) + 0x40)));
      mapCursorA = mapCursorA + 1;
      matrixLoopCount = matrixLoopCount + -1;
    } while (matrixLoopCount != 0);
    *(int *)(programRecord + 0xd4) = nextConstReg;
    nextConstReg = nextConstReg + 4;
    *(undefined4 *)(paramList[2] * 4 + *paramList) = 3;
    *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
    paramList[2] = paramList[2] + 1;
    ctxFlags8c = *(uint *)(ctx + 0x8c);
  }
  if ((ctxFlags8c & 0x800000) != 0) {
    unitMask = 0xff;
    if ((*(uint *)(ctx + 0x44) & 0x20000) != 0) {
      if ((*(uint *)(ctx + 0x44) & 0x2000) == 0) {
        unitMask = (uint)(byte)((unsigned char *)0x00001135)[ctx];
      }
      else {
        unitMask = (uint)(byte)((unsigned char *)0x000011d3)[ctx];
      }
    }
    unitCountdown = 8;
    texUnitIndexMap = 0;
    unitKindIndex = 0;
    texUnitStateCursor = ctx + 0x450;
    mapCursorA = paramMapCursor;
    mapCursorB = paramMapCursor;
    ctxCursor = ctx;
    do {
      if ((unitMask & 1 << (texUnitIndexMap & 0x3f)) != 0) {
        texGenFlags = *(uint *)(ctxCursor + 0x48);
        if (((texGenFlags & 0x20) != 0) && ((ushort)(*(short *)(texUnitStateCursor + 0x3c) + 0xdc00U) < 2)) {
          mapCursorA[0xa9] = nextConstReg;
          nextConstReg = nextConstReg + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x1a;
          *(int *)(paramList[2] * 4 + paramList[1]) = unitKindIndex;
          paramList[2] = paramList[2] + 1;
        }
        if (((texGenFlags & 0x40) != 0) && ((ushort)(*(short *)(texUnitStateCursor + 0x60) + 0xdc00U) < 2)) {
          mapCursorA[0xaa] = nextConstReg;
          nextConstReg = nextConstReg + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x1a;
          *(int *)(paramList[2] * 4 + paramList[1]) = unitKindIndex + 1;
          paramList[2] = paramList[2] + 1;
        }
        if (((texGenFlags & 0x80) != 0) && ((ushort)(*(short *)(texUnitStateCursor + 0x84) + 0xdc00U) < 2)) {
          mapCursorA[0xab] = nextConstReg;
          nextConstReg = nextConstReg + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x1a;
          *(int *)(paramList[2] * 4 + paramList[1]) = unitKindIndex + 2;
          paramList[2] = paramList[2] + 1;
        }
        if (((texGenFlags & 0x100) != 0) && ((ushort)(*(short *)(texUnitStateCursor + 0xa8) + 0xdc00U) < 2)) {
          mapCursorA[0xac] = nextConstReg;
          nextConstReg = nextConstReg + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x1a;
          *(int *)(paramList[2] * 4 + paramList[1]) = unitKindIndex + 3;
          paramList[2] = paramList[2] + 1;
        }
        if (*(int *)(ctxCursor + 0x150) != 0) {
          mapCursorB[0xd] = nextConstReg;
          nextConstReg = nextConstReg + 4;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 4;
          *(uint *)(paramList[2] * 4 + paramList[1]) = texUnitIndexMap;
          paramList[2] = paramList[2] + 1;
        }
      }
      texUnitIndexMap = texUnitIndexMap + 1;
      texUnitStateCursor = texUnitStateCursor + 0xcc;
      unitKindIndex = unitKindIndex + 4;
      mapCursorB = mapCursorB + 1;
      ctxCursor = ctxCursor + 4;
      mapCursorA = mapCursorA + 4;
      unitCountdown = unitCountdown + -1;
    } while (unitCountdown != 0);
  }
  zeroConst = FLOAT_001aa0d4;
  ctxFlags44 = *(uint *)(ctx + 0x44);
  if ((int)ctxFlags44 < 0) {
    lightMaskShifting = *(uint *)(ctx + 0x88);
    if (lightMaskShifting == 0) {
      needsLightModelParam = false;
      regCursor = nextConstReg;
    }
    else {
      lightIndex = 0;
      needsLightModelParam = false;
      lightStateCursor = stateBlockCopy;
      ctxUnitCursor = ctx;
      do {
        lightControlPtr = (uint *)(lightIndex * 4 + ctx + 0x3a8);
        regCursor = nextConstReg;
        if (((lightMaskShifting & 1) != 0) &&
           (lightControlWord = *(uint *)(ctx + 0x3a8 + lightIndex * 4), (lightControlWord & 0xfc000000) != 0)) {
          lightControlWord = lightControlWord & 0xc0000000;
          if (lightControlWord == 0x80000000) {
            paramMapCursor[0x16] = nextConstReg;
            nextConstReg = nextConstReg + 1;
            *(undefined4 *)(paramList[2] * 4 + *paramList) = 5;
            *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex;
            paramList[2] = paramList[2] + 1;
          }
          else if (lightControlWord == 0xc0000000) {
            needsLightModelParam = true;
          }
          lightControlWord = *lightControlPtr;
          if ((lightControlWord & 0x30000000) == 0x20000000) {
            if (*(int *)(ctx + 0x13c) == 1) {
              if (7 < *(uint *)(ctx + 0x280)) {
                paramMapCursor[0x18] = nextConstReg;
                nextConstReg = nextConstReg + 1;
                *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x1c;
                *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex << 1;
                paramList[2] = paramList[2] + 1;
              }
              if ((((unsigned char *)0x00002d48)[stateBlockCopy + 4] != '\0') && (7 < *(uint *)(ctx + 0x284))) {
                paramMapCursor[0x19] = nextConstReg;
                nextConstReg = nextConstReg + 1;
                *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x1c;
                *(uint *)(paramList[2] * 4 + paramList[1]) = lightIndex << 1 | 1;
                paramList[2] = paramList[2] + 1;
              }
            }
            if ((paramMapCursor[0x18] == -1) ||
               ((((unsigned char *)0x00002d48)[stateBlockCopy + 4] != '\0' && (paramMapCursor[0x19] == -1)))) {
              paramMapCursor[0x17] = nextConstReg;
              nextConstReg = nextConstReg + 1;
              *(undefined4 *)(paramList[2] * 4 + *paramList) = 6;
              *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex;
              paramList[2] = paramList[2] + 1;
              lightControlWord = *lightControlPtr;
            }
            else {
              lightControlWord = *lightControlPtr;
            }
          }
          if ((lightControlWord & 0xc000000) == 0x8000000) {
            if (*(int *)(ctx + 0x13c) == 1) {
              if (7 < *(uint *)(ctx + 0x288)) {
                paramMapCursor[0x1b] = nextConstReg;
                nextConstReg = nextConstReg + 1;
                *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x1d;
                *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex << 1;
                paramList[2] = paramList[2] + 1;
              }
              if ((((unsigned char *)0x00002d48)[stateBlockCopy + 4] != '\0') && (7 < *(uint *)(ctx + 0x28c))) {
                paramMapCursor[0x1c] = nextConstReg;
                nextConstReg = nextConstReg + 1;
                *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x1d;
                *(uint *)(paramList[2] * 4 + paramList[1]) = lightIndex << 1 | 1;
                paramList[2] = paramList[2] + 1;
              }
            }
            if ((paramMapCursor[0x1b] == -1) ||
               ((((unsigned char *)0x00002d48)[stateBlockCopy + 4] != '\0' && (paramMapCursor[0x1c] == -1)))) {
              paramMapCursor[0x1a] = nextConstReg;
              nextConstReg = nextConstReg + 1;
              *(undefined4 *)(paramList[2] * 4 + *paramList) = 7;
              *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex;
              paramList[2] = paramList[2] + 1;
            }
          }
          paramMapCursor[0x1e] = nextConstReg;
          regAfterLightPair = nextConstReg + 2;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 8;
          *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex;
          paramList[2] = paramList[2] + 1;
          paramMapCursor[0x1f] = nextConstReg + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 9;
          *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex;
          paramList[2] = paramList[2] + 1;
          regCursor = regAfterLightPair;
          if (*(float *)(lightStateCursor + 0x24fc) != zeroConst) {
            if ((*lightControlPtr & 0x2000000) != 0) {
              if ((*lightControlPtr & 0x1000000) == 0) {
                paramMapCursor[0x20] = regAfterLightPair;
                paramKind = 10;
                paramCountSnapshot = paramList[2];
                paramKinds = *paramList;
              }
              else {
                paramMapCursor[0x22] = regAfterLightPair;
                paramKind = 0xc;
                paramCountSnapshot = paramList[2];
                paramKinds = *paramList;
              }
              regAfterLightPair = nextConstReg + 3;
              *(undefined4 *)(paramCountSnapshot * 4 + paramKinds) = paramKind;
              *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex;
              paramList[2] = paramList[2] + 1;
            }
            regCursor = regAfterLightPair;
            if (((unsigned char *)0x0000150c)[ctxUnitCursor] != '\0') {
              paramMapCursor[0x21] = regAfterLightPair;
              regCursor = regAfterLightPair + 1;
              *(undefined4 *)(paramList[2] * 4 + *paramList) = 0xb;
              *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex;
              paramList[2] = paramList[2] + 1;
              if (*(float *)(lightStateCursor + 0x251c) != zeroConst) {
                paramMapCursor[0x23] = regCursor;
                regCursor = regAfterLightPair + 2;
                *(undefined4 *)(paramList[2] * 4 + *paramList) = 0xd;
                *(int *)(paramList[2] * 4 + paramList[1]) = lightIndex;
                paramList[2] = paramList[2] + 1;
              }
            }
          }
        }
        lightMaskShifting = lightMaskShifting >> 1;
        lightIndex = lightIndex + 1;
        paramMapCursor = paramMapCursor + 0xf;
        lightStateCursor = lightStateCursor + 0x80;
        ctxUnitCursor = ctxUnitCursor + 0x6c;
        nextConstReg = regCursor;
      } while (lightMaskShifting != 0);
    }
    if (*(int *)(ctx + 0x13c) == 1) {
      if (7 < *(uint *)(ctx + 0x270)) {
        *(int *)(programRecord + 0x2d8) = regCursor;
        regCursor = regCursor + 1;
        *(undefined4 *)(paramList[2] * 4 + *paramList) = 0xe;
        *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
        paramList[2] = paramList[2] + 1;
      }
      if (7 < *(uint *)(ctx + 0x278)) {
        *(int *)(programRecord + 0x2dc) = regCursor;
        regCursor = regCursor + 1;
        *(undefined4 *)(paramList[2] * 4 + *paramList) = 0xf;
        *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
        paramList[2] = paramList[2] + 1;
      }
      if (7 < *(uint *)(ctx + 0x280)) {
        *(int *)(programRecord + 0x2e0) = regCursor;
        regCursor = regCursor + 1;
        *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x10;
        *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
        paramList[2] = paramList[2] + 1;
      }
      if (7 < *(uint *)(ctx + 0x288)) {
        *(int *)(programRecord + 0x2ec) = regCursor;
        regCursor = regCursor + 1;
        *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x11;
        *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
        paramList[2] = paramList[2] + 1;
      }
      if ((7 < *(uint *)(ctx + 0x270)) || (7 < *(uint *)(ctx + 0x278))) {
        *(int *)(programRecord + 0x2f8) = regCursor;
        regCursor = regCursor + 1;
        *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x12;
        *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
        paramList[2] = paramList[2] + 1;
      }
      if (1 < *(uint *)(ctx + 0x290)) {
        *(int *)(programRecord + 800) = regCursor;
        regCursor = regCursor + 1;
        *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x13;
        *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
        paramList[2] = paramList[2] + 1;
      }
      if (((unsigned char *)0x00002d48)[stateBlockCopy + 4] != '\0') {
        if (7 < *(uint *)(ctx + 0x274)) {
          *(int *)(programRecord + 0x2fc) = regCursor;
          regCursor = regCursor + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0xe;
          *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 1;
          paramList[2] = paramList[2] + 1;
        }
        if (7 < *(uint *)(ctx + 0x27c)) {
          *(int *)(programRecord + 0x300) = regCursor;
          regCursor = regCursor + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0xf;
          *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 1;
          paramList[2] = paramList[2] + 1;
        }
        if (7 < *(uint *)(ctx + 0x284)) {
          *(int *)(programRecord + 0x304) = regCursor;
          regCursor = regCursor + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x10;
          *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 1;
          paramList[2] = paramList[2] + 1;
        }
        if (7 < *(uint *)(ctx + 0x28c)) {
          *(int *)(programRecord + 0x310) = regCursor;
          regCursor = regCursor + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x11;
          *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 1;
          paramList[2] = paramList[2] + 1;
        }
        if ((7 < *(uint *)(ctx + 0x274)) || (7 < *(uint *)(ctx + 0x27c))) {
          *(int *)(programRecord + 0x31c) = regCursor;
          regCursor = regCursor + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x12;
          *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 1;
          paramList[2] = paramList[2] + 1;
        }
        if (1 < *(uint *)(ctx + 0x294)) {
          *(int *)(programRecord + 0x324) = regCursor;
          regCursor = regCursor + 1;
          *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x13;
          *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 1;
          paramList[2] = paramList[2] + 1;
        }
      }
    }
    *(int *)(programRecord + 0x328) = regCursor;
    nextConstReg = regCursor + 1;
    *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x14;
    *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
    paramList[2] = paramList[2] + 1;
    if (needsLightModelParam) {
      *(int *)(programRecord + 0x32c) = nextConstReg;
      nextConstReg = regCursor + 2;
      *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x1b;
      *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
      paramList[2] = paramList[2] + 1;
      ctxFlags44 = *(uint *)(ctx + 0x44);
    }
    else {
      ctxFlags44 = *(uint *)(ctx + 0x44);
    }
  }
  if (((ctxFlags44 & 0x1000000) != 0) && (*(char *)(ctx + 0x121) == '\0')) {
    *(int *)(programRecord + 0x330) = nextConstReg;
    nextConstReg = nextConstReg + 1;
    *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x15;
    *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
    paramList[2] = paramList[2] + 1;
  }
  if ((*(uint *)(ctx + 0x1874) & 0xc0000000) == 0x80000000) {
    *(int *)(programRecord + 0x334) = nextConstReg;
    regPlus1 = nextConstReg + 1;
    lastParamReg = nextConstReg + 2;
    nextConstReg = nextConstReg + 3;
    *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x16;
    *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
    paramList[2] = paramList[2] + 1;
    *(int *)(programRecord + 0x338) = regPlus1;
    *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x17;
    *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
    paramList[2] = paramList[2] + 1;
    *(int *)(programRecord + 0x340) = lastParamReg;
    *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x18;
    *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
    paramList[2] = paramList[2] + 1;
  }
  if (*(char *)(ctx + 300) != '\0') {
    *(int *)(programRecord + 0x344) = nextConstReg;
    nextConstReg = nextConstReg + 1;
    *(undefined4 *)(paramList[2] * 4 + *paramList) = 0x19;
    *(undefined4 *)(paramList[2] * 4 + paramList[1]) = 0;
    paramList[2] = paramList[2] + 1;
  }
  *constRegCountOut = nextConstReg;
  if (((unsigned char *)0x00004301)[stateBlock] == '\0') {
    local_78 = GH_U2F((unsigned int)((stateBlock + 0x1960)));
    if ((((((local_74[0] == 0 && local_74[1] == 0) && local_74[2] == 0) &&
          FLOAT_001aa0e8 == local_78) &&
         (((local_74[3] == 0 && local_60 == 0) && local_5c == 0) && FLOAT_001aa0e8 == local_64)) &&
        (((local_58 == 0 && local_54 == 0) && local_4c == 0) && FLOAT_001aa0e8 == local_50)) &&
        (((local_48 == 0 && unaff_r17 == 0) && unaff_r18 == 0) && FLOAT_001aa0e8 == unaff_r19)) {
      ffvpEmitPositionPassThrough(programRecord,ctxFlag400Active,ctxByte11d2);
    }
    else {
      ((int (*)())ffvpEmitClipPosition)(programRecord,ctxFlag400Active,ctxByte11d2);
    }
    if (*(char *)(ctx + 0x12a) != '\0') {
      ((int (*)())ffvpPrepareEyeNormal)(programRecord);
    }
  }
  else {
    tableCount = (uint)*(byte *)(ctx + 0x90);
    if (tableCount != 0) {
      genIndex = 0;
      texUnitEnableCursor = ctx;
      if (tableCount == 0) {
        tableCount = 1;
      }
      do {
        local_74[genIndex] = (uint)(byte)((unsigned char *)0x000013a9)[texUnitEnableCursor];
        tableCount = tableCount - 1;
        genIndex = genIndex + 1;
        texUnitEnableCursor = texUnitEnableCursor + 1;
      } while (tableCount != 0);
    }
    ((int (*)())ffvpPrepareBlendWeights)(programRecord,(uint)*(byte *)(ctx + 0x91),(uint)(byte)((unsigned char *)0x00004302)[stateBlock]);
    if (*(char *)(ctx + 0x129) == '\0') {
      ((int (*)())ffvpEmitBlendedClipPosition)(programRecord,local_74,(uint)*(byte *)(ctx + 0x91),
                   (uint)(byte)((unsigned char *)0x00004302)[stateBlock],ctxFlag400Active,ctxByte11d2);
    }
    else {
      ((int (*)())ffvpEmitBlendedEyePosition)(programRecord,local_74,(uint)*(byte *)(ctx + 0x91),
                   (uint)(byte)((unsigned char *)0x00004302)[stateBlock],(uint)(*(char *)(ctx + 0x90) == '\x02'));
      ((int (*)())ffvpEmitProjectedPosition)(programRecord,ctxFlag400Active,ctxByte11d2);
    }
    if (*(char *)(ctx + 0x12a) != '\0') {
      ((int (*)())ffvpEmitBlendedEyeNormal)(programRecord,local_74,(uint)*(byte *)(ctx + 0x91),
                   (uint)(byte)((unsigned char *)0x00004302)[stateBlock]);
    }
  }
  if (*(char *)(ctx + 0x128) == '\0') {
    if (*(char *)(ctx + 300) != '\0') {
      ((int (*)())ffvpPrepareRescaledNormal)(programRecord);
    }
  }
  else {
    ((int (*)())ffvpPrepareNormalizedNormal)(programRecord);
  }
  ctxFlags44B = *(uint *)(ctx + 0x44);
  if ((((ctxFlags44B & 0x1000000) != 0) && (*(char *)(ctx + 0x121) == '\0')) &&
     ((*(int *)(programRecord + 0x3d8) == 0 || ((ctxFlags44B & 0x2000) == 0)))) {
    fogMode = *(short *)(((unsigned char *)0x00002e04) + stateBlock);
    if (fogMode == 0x801) {
      ((int (*)())ffvpPrepareFogExp2)(programRecord);
      ctxFlags44B = *(uint *)(ctx + 0x44);
    }
    else if (fogMode == 0x2601) {
      ((int (*)())ffvpPrepareFogLinear)(programRecord);
      ctxFlags44B = *(uint *)(ctx + 0x44);
    }
    else if (fogMode == 0x800) {
      ((int (*)())ffvpPrepareFogExp)(programRecord);
      ctxFlags44B = *(uint *)(ctx + 0x44);
    }
  }
  if ((ctxFlags44B & 0x20000) == 0) {
    if ((*(uint *)(ctx + 0x8c) & 0x800000) == 0) goto LAB_0009e8dc;
    texUnitLimit = (uint)*(byte *)(ctx + 0x2b);
    if ((uint)(byte)((unsigned char *)0x000013b0)[ctx] < (uint)*(byte *)(ctx + 0x2b)) {
      texUnitLimit = (uint)(byte)((unsigned char *)0x000013b0)[ctx];
    }
    if (texUnitLimit == 0) goto LAB_0009e8dc;
    texUnitIndex = 0;
    texCoordMapPtr = (ushort *)(ctx + 0x187c);
    texUnitCtxCursor = ctx;
    texUnitEnableCursor = ctx;
    do {
      if (((unsigned char *)0x00001438)[texUnitEnableCursor] != '\0') {
        ((int (*)())ffvpEmitTexCoordGen)(programRecord,texUnitIndex,0,texUnitIndex,(uint)*(byte *)(texUnitCtxCursor + 0x153),texUnitIndex,*texCoordMapPtr >> 2 & 0xfff
                    );
      }
      texUnitIndex = texUnitIndex + 1;
      texCoordMapPtr = texCoordMapPtr + 1;
      texUnitEnableCursor = texUnitEnableCursor + 1;
      texUnitCtxCursor = texUnitCtxCursor + 4;
    } while (texUnitLimit != texUnitIndex);
  }
  else {
    if ((ctxFlags44B & 0x2000) == 0) {
      lightEnableByte = ((unsigned char *)0x00001135)[ctx];
    }
    else {
      lightEnableByte = ((unsigned char *)0x000011d3)[ctx];
    }
    texUnitCount = (uint)(byte)((unsigned char *)0x000013b0)[ctx];
    if (texUnitCount == 0) goto LAB_0009e8dc;
    texUnitIndex = 0;
    texCoordMapPtr = (ushort *)(ctx + 0x187c);
    texUnitCtxCursor = ctx;
    do {
      if (((uint)lightEnableByte & 1 << (texUnitIndex & 0x3f)) != 0) {
        ((int (*)())ffvpEmitTexCoordGen)(programRecord,texUnitIndex,0,texUnitIndex,(uint)*(byte *)(texUnitCtxCursor + 0x153),texUnitIndex,*texCoordMapPtr >> 2 & 0xfff
                    );
        texUnitCount = (uint)(byte)((unsigned char *)0x000013b0)[ctx];
      }
      texUnitIndex = texUnitIndex + 1;
      texCoordMapPtr = texCoordMapPtr + 1;
      texUnitCtxCursor = texUnitCtxCursor + 4;
    } while ((int)texUnitIndex < (int)texUnitCount);
  }
  ctxFlags44B = *(uint *)(ctx + 0x44);
LAB_0009e8dc:
  if ((int)ctxFlags44B < 0) {
    activeLightCount = 0;
    ((int (*)())ffvpEmitSceneColor)(programRecord);
    zeroConst = FLOAT_001aa0d4;
    lightMaskLoop = *(uint *)(ctx + 0x88);
    if (lightMaskLoop != 0) {
      activeLightCount = 0;
      lastActiveLight = 0;
      lightControlPtr = (uint *)(ctx + 0x3a8);
      lightMaskCopy = lightMaskLoop;
      do {
        if (((lightMaskCopy & 1) != 0) && ((*lightControlPtr & 0xfc000000) != 0)) {
          lastActiveLight = activeLightCount;
        }
        lightMaskCopy = lightMaskCopy >> 1;
        activeLightCount = activeLightCount + 1;
        lightControlPtr = lightControlPtr + 1;
      } while (lightMaskCopy != 0);
      activeLightCount = 0;
      emittedLightIndex = 0;
      lightControlPtr = (uint *)(ctx + 0x3a8);
      do {
        if (((lightMaskLoop & 1) != 0) && (lightMaskCopy = *lightControlPtr, (lightMaskCopy & 0xfc000000) != 0)) {
          if (*(float *)(stateBlock + 0x24fc) == zeroConst) {
            ((int (*)())ffvpEmitDirectionalLight)(programRecord,emittedLightIndex,(uint)(activeLightCount == 0),(uint)(emittedLightIndex == lastActiveLight),lightMaskCopy >> 0x1e,
                         lightMaskCopy >> 0x1c & 3,lightMaskCopy >> 0x1a & 3);
          }
          else {
            ((int (*)())ffvpEmitLight)(programRecord,emittedLightIndex,(uint)(activeLightCount == 0),(uint)(emittedLightIndex == lastActiveLight),lightMaskCopy >> 0x19 & 1,
                         lightMaskCopy >> 0x18 & 1,lightMaskCopy >> 0x17 & 1,lightMaskCopy >> 0x1e,lightMaskCopy >> 0x1c & 3,
                         lightMaskCopy >> 0x1a & 3);
          }
          activeLightCount = activeLightCount + 1;
        }
        lightMaskLoop = lightMaskLoop >> 1;
        emittedLightIndex = emittedLightIndex + 1;
        lightControlPtr = lightControlPtr + 1;
        stateBlock = stateBlock + 0x80;
      } while (lightMaskLoop != 0);
    }
    ((int (*)())ffvpEmitColorOutputs)(programRecord,activeLightCount);
  }
  else {
    ffvpEmitColorPassThrough(programRecord,3,0,0);
    if ((*(uint *)(ctx + 0x44) & 0xa10000) != 0) {
      ffvpEmitColorPassThrough(programRecord,4,1,0);
    }
  }
  if ((*(uint *)(ctx + 0x1874) & 0xc0000000) == 0x80000000) {
    ((int (*)())ffvpEmitPointSizeAttenuation)(programRecord,2,(uint)(*(float *)(ctx + 0x114) == FLOAT_001aa0d4));
  }
  if ((*(uint *)(ctx + 0x44) & 0x800) == 0) {
    if (*(char *)(ctx + 0x121) != '\0') {
      ((int (*)())ffvpEmitFogTexCoord)(programRecord,(uint)*(byte *)(ctx + 0x120));
    }
  }
  else if (*(int *)(programRecord + 0x3d8) == 0) {
    ((int (*)())ffvpEmitFogTexCoord)(programRecord,(uint)(byte)((unsigned char *)0x000011d1)[ctx]);
  }
  else {
    ((int (*)())ffvpEmitFogDistance)(programRecord);
  }
  programTypeResult = ((int (*)())ffvpFinishProgram)(programRecord);
  if (programTypeResult == 6) {
    *(undefined1 *)(ctx + 0x126) = 1;
  }
  return programRecord;
}

/* fpVariantCacheGrow @ 0x9eb90 (560 bytes) */
int fpVariantCacheGrow(ctx, growBy)
  int ctx;
  int growBy;
{
  uint *nextEntry;
  uint *keyTail;
  int newBucketIndex;
  uint rotate;
  uint rotateCounter;
  int newBuckets;
  int oldBuckets;
  uint *entry;
  uint *keyCursor;
  uint hash;
  uint *keyCursorB;
  uint *keyBlockEnd;
  uint *keyEnd;
  int oldBucketCount;
  int loopIndex;
  
  oldBucketCount = *(int *)(((unsigned char *)0x0000111c) + ctx);
  if (oldBucketCount != 0xfb2f) {
    *(int *)(((unsigned char *)0x0000111c) + ctx) = oldBucketCount + growBy;
    if (0xfb2f < (uint)(oldBucketCount + growBy)) {
      *(undefined4 *)(((unsigned char *)0x0000111c) + ctx) = 0xfb2f;
    }
    newBuckets = (**(code **)(ctx + 0x10))(1,*(int *)(((unsigned char *)0x0000111c) + ctx) << 2);
    if (oldBucketCount == 0) {
      oldBuckets = *(int *)(((unsigned char *)0x00001118) + ctx);
    }
    else {
      oldBuckets = *(int *)(((unsigned char *)0x00001118) + ctx);
      loopIndex = 0;
      do {
        entry = *(uint **)(loopIndex * 4 + oldBuckets);
        if (entry != (uint *)0x0) {
          do {
            keyEnd = entry + 0xc;
            if (keyEnd < entry + 0xb) {
              hash = 0;
              keyCursor = entry;
            }
            else {
              hash = 0;
              keyBlockEnd = entry + 0xb;
              keyCursorB = entry;
              do {
                keyCursor = keyBlockEnd;
                hash = hash ^ *keyCursorB ^ (keyCursorB[1] << 3 | keyCursorB[1] >> 0x1d) ^
                        (keyCursorB[2] << 6 | keyCursorB[2] >> 0x1a) ^ (keyCursorB[3] << 9 | keyCursorB[3] >> 0x17)
                        ^ (keyCursorB[4] << 0xc | keyCursorB[4] >> 0x14) ^
                        (keyCursorB[5] << 0xf | keyCursorB[5] >> 0x11) ^
                        (keyCursorB[6] << 0x12 | keyCursorB[6] >> 0xe) ^
                        (keyCursorB[7] << 0x15 | keyCursorB[7] >> 0xb) ^
                        (keyCursorB[8] << 0x18 | keyCursorB[8] >> 8) ^ (keyCursorB[9] << 0x1b | keyCursorB[9] >> 5)
                        ^ (keyCursorB[10] << 0x1e | keyCursorB[10] >> 2);
                keyBlockEnd = keyCursor + 0xb;
                keyCursorB = keyCursor;
              } while (keyCursor + 0xb <= keyEnd);
            }
            keyTail = keyCursor + 5;
            if (keyEnd < keyTail) {
              rotateCounter = 0;
              keyTail = keyCursor;
            }
            else {
              rotateCounter = 0xf;
              hash = hash ^ *keyCursor ^ (keyCursor[1] << 3 | keyCursor[1] >> 0x1d) ^
                      (keyCursor[2] << 6 | keyCursor[2] >> 0x1a) ^ (keyCursor[3] << 9 | keyCursor[3] >> 0x17) ^
                      (keyCursor[4] << 0xc | keyCursor[4] >> 0x14);
            }
            for (; keyTail < keyEnd; keyTail = keyTail + 1) {
              rotate = rotateCounter & 0x1f;
              rotateCounter = rotateCounter + 3;
              hash = hash ^ (*keyTail << rotate | *keyTail >> 0x20 - rotate);
            }
            nextEntry = (uint *)entry[0x17];
            newBucketIndex = (hash - (hash / *(uint *)(((unsigned char *)0x0000111c) + ctx)) *
                             *(uint *)(((unsigned char *)0x0000111c) + ctx)) * 4;
            entry[0x17] = *(uint *)(newBuckets + newBucketIndex);
            *(uint **)(newBuckets + newBucketIndex) = entry;
            entry = nextEntry;
          } while (nextEntry != (uint *)0x0);
          oldBuckets = *(int *)(((unsigned char *)0x00001118) + ctx);
        }
        loopIndex = loopIndex + 1;
      } while (oldBucketCount != loopIndex);
    }
    (**(code **)(ctx + 0x18))(oldBuckets);
    *(int *)(((unsigned char *)0x00001118) + ctx) = newBuckets;
  }
  return;
}

/* fpVariantCacheLookup @ 0x9edd0 (708 bytes) */
int fpVariantCacheLookup(ctx, key)
  int ctx;
  uint *key;
{
  bool hashFullKey;
  uint rotateAmount;
  uint *keyCursor;
  uint hash;
  int bucketEntry;
  uint rotateCounter;
  int compareResult;
  uint *keyEnd;
  uint *keyTail;
  uint bucketCount;
  int loopIndex;
  
  hashFullKey = ((unsigned char *)0x00001120)[ctx] == '\0';
  if (hashFullKey) {
    keyEnd = key + 0xc;
    bucketCount = *(uint *)(((unsigned char *)0x0000111c) + ctx);
    hash = 0;
    keyCursor = key;
    while (keyCursor + 0xb <= keyEnd) {
      hash = hash ^ *keyCursor ^ (keyCursor[1] << 3 | keyCursor[1] >> 0x1d) ^
              (keyCursor[2] << 6 | keyCursor[2] >> 0x1a) ^ (keyCursor[3] << 9 | keyCursor[3] >> 0x17) ^
              (keyCursor[4] << 0xc | keyCursor[4] >> 0x14) ^ (keyCursor[5] << 0xf | keyCursor[5] >> 0x11) ^
              (keyCursor[6] << 0x12 | keyCursor[6] >> 0xe) ^ (keyCursor[7] << 0x15 | keyCursor[7] >> 0xb) ^
              (keyCursor[8] << 0x18 | keyCursor[8] >> 8) ^ (keyCursor[9] << 0x1b | keyCursor[9] >> 5) ^
              (keyCursor[10] << 0x1e | keyCursor[10] >> 2);
      keyCursor = keyCursor + 0xb;
    }
    keyTail = keyCursor + 5;
    if (keyEnd < keyTail) {
      rotateCounter = 0;
      keyTail = keyCursor;
    }
    else {
      rotateCounter = 0xf;
      hash = hash ^ *keyCursor ^ (keyCursor[1] << 3 | keyCursor[1] >> 0x1d) ^
              (keyCursor[2] << 6 | keyCursor[2] >> 0x1a) ^ (keyCursor[3] << 9 | keyCursor[3] >> 0x17) ^
              (keyCursor[4] << 0xc | keyCursor[4] >> 0x14);
    }
    for (; keyTail < keyEnd; keyTail = keyTail + 1) {
      rotateAmount = rotateCounter & 0x1f;
      rotateCounter = rotateCounter + 3;
      hash = hash ^ (*keyTail << rotateAmount | *keyTail >> 0x20 - rotateAmount);
    }
    bucketEntry = hash - (hash / bucketCount) * bucketCount;
  }
  else {
    bucketCount = *(uint *)(((unsigned char *)0x0000111c) + ctx);
    hash = *key + key[2] + key[3];
    bucketEntry = hash - (hash / bucketCount) * bucketCount;
  }
  bucketEntry = *(int *)(bucketEntry * 4 + *(int *)(((unsigned char *)0x00001118) + ctx));
  if (*(char *)(ctx + 0x2f) == '\0') {
    loopIndex = 0;
    if (bucketEntry != 0) {
      do {
        compareResult = _memcmp(bucketEntry,key,0x30);
        if (compareResult == 0) {
          return bucketEntry;
        }
        bucketEntry = *(int *)(bucketEntry + 0x5c);
        loopIndex = loopIndex + 1;
      } while (bucketEntry != 0);
      goto LAB_0009f014;
    }
  }
  else {
    loopIndex = 0;
    if (bucketEntry != 0) {
      do {
        compareResult = _memcmp(bucketEntry,key,0x18);
        if (compareResult == 0) {
          return bucketEntry;
        }
        bucketEntry = *(int *)(bucketEntry + 0x5c);
        loopIndex = loopIndex + 1;
      } while (bucketEntry != 0);
      goto LAB_0009f014;
    }
  }
  loopIndex = 0;
LAB_0009f014:
  if ((hashFullKey) || (loopIndex < 5)) {
    if ((loopIndex < 8) || (0xfb2e < bucketCount)) {
      return 0;
    }
    if (hashFullKey) {
      ((int (*)())fpVariantCacheGrow)(ctx,0x859);
      return 0;
    }
  }
  ((int (*)())fpVariantCacheGrow)(ctx,0);
  ((unsigned char *)0x00001120)[ctx] = 0;
  return 0;
}

/* programFillStateConstants @ 0x9f0b0 (4444 bytes) */
void programFillStateConstants(int ctx,int program,undefined4 unusedArg3,undefined4 unusedArg4,undefined4 unusedArg5,undefined4 unusedArg6,undefined4 unusedArg7,undefined4 unusedArg8,double scratchProduct,double unusedFloatArg2,double unusedFloatArg3,double unusedFloatArg4,double unusedFloatArg5,double unusedFloatArg6,double unusedFloatArg7,double unusedFloatArg8,double unusedFloatArg9,double unusedFloatArg10,double unusedFloatArg11,double unusedFloatArg12,double unusedFloatArg13)
{
  undefined4 slotAlt01;
  undefined4 mvpCopy31;
  undefined4 slotAlt12;
  undefined4 mvpCopy12;
  undefined4 slotAlt23;
  undefined4 mvpCopy02;
  undefined4 slotAlt02;
  undefined4 mvpCopy22;
  undefined4 slotAlt13;
  undefined4 mvpCopy03;
  undefined4 slotAlt03;
  undefined4 mvpCopy23;
  undefined4 slotAlt33;
  undefined4 mvpCopy13;
  undefined4 slotAlt20;
  undefined4 mvpCopy10;
  uint texUnit;
  undefined4 slotAlt31;
  undefined4 mvpCopy20;
  undefined4 slotAlt10;
  undefined4 mvpCopy30;
  undefined4 slotAlt21;
  undefined4 mvpCopy01;
  undefined4 slotAlt32;
  undefined4 mvpCopy21;
  undefined4 slotAlt11;
  undefined4 mvpCopy11;
  undefined4 slotAlt22;
  undefined4 mvpCopy32;
  undefined4 slotAlt30;
  undefined4 mvpCopy33;
  int materialState;
  int lightState2;
  int ctxUnitState;
  int slotMatrixAlt;
  int texUnitState;
  int constDest;
  int ctxVec4Entry;
  int lightState;
  int constIndex;
  int constOffset;
  float stateF24a4;
  float minor2;
  float invSrc10;
  float invSrc30;
  float invSrc20;
  float invSrc31;
  float mulSlot32;
  float mulSlot22;
  float mulSlot12;
  float invSrc21;
  float invSrc11;
  float invDeterminant;
  float invSrc01;
  float invSrc00;
  float mulSlot33;
  float mulSlot23;
  float mulSlot13;
  float minor6;
  float mulSlot31;
  float mulSlot21;
  float mulSlot11;
  float minor5;
  float minor4;
  float minor3;
  double minor13;
  double mulSlot30;
  double mulSlot20;
  double mulSlot10;
  double invSrc23;
  double minor8;
  double minor7;
  double invSrc13;
  float mvp11;
  float mvp12;
  float mvp13;
  float mulSlot01;
  float mvp32;
  float mulSlot03;
  float mvp20;
  float mvp21;
  float mvp22;
  float mvp23;
  float mulSlot02;
  float mvp33;
  float mvp30;
  float mvp31;
  float mvp10;
  uint texGenComponent;
  undefined4 copySlot32;
  int paramMap;
  undefined4 copySlot11;
  undefined4 copySlot21;
  undefined4 copySlot01;
  undefined4 copySlot30;
  undefined4 copySlot20;
  undefined4 copySlot33;
  int slotMatrix;
  undefined8 *texGenPlane;
  uint paramCount;
  int slotMatrixCopy;
  undefined4 copySlot10;
  int constAddr;
  int ctxState;
  uint paramIndex;
  int paramMapEntries;
  int paramOffset;
  int stateBlock;
  int constantBuffer;
  undefined4 copySlot13;
  undefined4 copySlot23;
  undefined4 copySlot03;
  undefined4 copySlot22;
  undefined4 copySlot02;
  undefined4 copySlot12;
  undefined4 copySlot31;
  uint elementIndex;
  int *paramList;
  undefined8 valueXY;
  double mvp03;
  double mvp02;
  double mvp01;
  double mvp00;
  double minor11;
  double mulSlot00;
  double minor10;
  double minor12;
  double minor9;
  undefined8 valueZW;
  double invSrc33;
  double invSrc32;
  double invSrc03;
  double invSrc12;
  double invSrc02;
  double invSrc22;
  float stateVecX;
  float stateVecY;
  float stateVecZ;
  undefined4 stateVecW;
  float result00;
  float result10;
  float result20;
  float result30;
  float result01;
  float result11;
  float result21;
  float result31;
  float result02;
  float result12;
  float result22;
  float result32;
  float result03;
  float result13;
  float result23;
  float result33;
  undefined4 intToDoubleHiA;
  uint intToDoubleLoA;
  undefined4 intToDoubleHiB;
  uint intToDoubleLoB;
  float minor1;
  float cofactor30;
  float cofactor20;
  float cofactor10;
  float cofactor00;
  float determinant;
  float minorProduct;
  
  paramList = *(int **)(program + 0x50);
  ctxState = *(int *)(ctx + 4);
  paramMap = *(int *)(program + 0x54);
  constantBuffer = *(int *)(program + 0x4c);
  paramCount = paramList[2];
  stateBlock = *(int *)(ctxState + 0x10);
  paramMapEntries = paramMap + 0xa4;
  if (paramCount != 0) {
    paramIndex = 0;
    paramOffset = 0;
    do {
      elementIndex = *(uint *)(paramList[1] + paramOffset);
      switch(*(undefined4 *)(*paramList + paramOffset)) {
      case 0:
        mvp00 = (double)*(float *)(stateBlock + 0x1920);
        slotMatrix = stateBlock + 0x1860 + elementIndex * 0x40;
        mvp10 = *(float *)(stateBlock + 0x1930);
        mvp11 = *(float *)(stateBlock + 0x1934);
        mvp12 = *(float *)(stateBlock + 0x1938);
        mvp13 = *(float *)(stateBlock + 0x193c);
        mulSlot00 = (double)*(float *)(slotMatrix + 0x100);
        mvp01 = (double)*(float *)(stateBlock + 0x1924);
        mulSlot01 = *(float *)(slotMatrix + 0x104);
        mvp02 = (double)*(float *)(stateBlock + 0x1928);
        mvp03 = (double)*(float *)(stateBlock + 0x192c);
        mvp20 = *(float *)(stateBlock + 0x1940);
        mvp21 = *(float *)(stateBlock + 0x1944);
        mvp22 = *(float *)(stateBlock + 0x1948);
        mvp23 = *(float *)(stateBlock + 0x194c);
        mulSlot02 = *(float *)(slotMatrix + 0x108);
        mvp33 = *(float *)(stateBlock + 0x195c);
        mvp30 = *(float *)(stateBlock + 0x1950);
        mvp31 = *(float *)(stateBlock + 0x1954);
        mvp32 = *(float *)(stateBlock + 0x1958);
        mulSlot03 = *(float *)(slotMatrix + 0x10c);
        result30 = mvp33 * mulSlot03 +
                    mvp23 * mulSlot02 + (float)(mvp03 * mulSlot00 + (double)(mvp13 * mulSlot01));
        result00 = mvp30 * mulSlot03 +
                    mvp20 * mulSlot02 + (float)(mvp00 * mulSlot00 + (double)(mvp10 * mulSlot01));
        result10 = mvp31 * mulSlot03 +
                    mvp21 * mulSlot02 + (float)(mvp01 * mulSlot00 + (double)(mvp11 * mulSlot01));
        result20 = mvp32 * mulSlot03 +
                    mvp22 * mulSlot02 + (float)(mvp02 * mulSlot00 + (double)(mvp12 * mulSlot01));
        mulSlot11 = *(float *)(slotMatrix + 0x114);
        mulSlot10 = (double)*(float *)(slotMatrix + 0x110);
        mulSlot12 = *(float *)(slotMatrix + 0x118);
        mulSlot13 = *(float *)(slotMatrix + 0x11c);
        result31 = mvp33 * mulSlot13 +
                    mvp23 * mulSlot12 + (float)(mvp03 * mulSlot10 + (double)(mvp13 * mulSlot11));
        result01 = mvp30 * mulSlot13 +
                    mvp20 * mulSlot12 + (float)(mvp00 * mulSlot10 + (double)(mvp10 * mulSlot11));
        result11 = mvp31 * mulSlot13 +
                    mvp21 * mulSlot12 + (float)(mvp01 * mulSlot10 + (double)(mvp11 * mulSlot11));
        result21 = mvp32 * mulSlot13 +
                    mvp22 * mulSlot12 + (float)(mvp02 * mulSlot10 + (double)(mvp12 * mulSlot11));
        mulSlot21 = *(float *)(slotMatrix + 0x124);
        mulSlot20 = (double)*(float *)(slotMatrix + 0x120);
        mulSlot22 = *(float *)(slotMatrix + 0x128);
        mulSlot23 = *(float *)(slotMatrix + 300);
        result32 = mvp33 * mulSlot23 +
                    mvp23 * mulSlot22 + (float)(mvp03 * mulSlot20 + (double)(mvp13 * mulSlot21));
        result02 = mvp30 * mulSlot23 +
                    mvp20 * mulSlot22 + (float)(mvp00 * mulSlot20 + (double)(mvp10 * mulSlot21));
        result12 = mvp31 * mulSlot23 +
                    mvp21 * mulSlot22 + (float)(mvp01 * mulSlot20 + (double)(mvp11 * mulSlot21));
        result22 = mvp32 * mulSlot23 +
                    mvp22 * mulSlot22 + (float)(mvp02 * mulSlot20 + (double)(mvp12 * mulSlot21));
        mulSlot31 = *(float *)(slotMatrix + 0x134);
        mulSlot30 = (double)*(float *)(slotMatrix + 0x130);
        mulSlot32 = *(float *)(slotMatrix + 0x138);
        mulSlot33 = *(float *)(slotMatrix + 0x13c);
        scratchProduct = (double)(mvp11 * mulSlot31);
        result33 = mvp33 * mulSlot33 +
                    mvp23 * mulSlot32 + (float)(mvp03 * mulSlot30 + (double)(mvp13 * mulSlot31));
        result03 = mvp30 * mulSlot33 +
                    mvp20 * mulSlot32 + (float)(mvp00 * mulSlot30 + (double)(mvp10 * mulSlot31));
        result13 = mvp31 * mulSlot33 + mvp21 * mulSlot32 + (float)(mvp01 * mulSlot30 + scratchProduct);
        result23 = mvp32 * mulSlot33 +
                    mvp22 * mulSlot32 + (float)(mvp02 * mulSlot30 + (double)(mvp12 * mulSlot31));
        constOffset = *(int *)(elementIndex * 4 + paramMapEntries) * 0x10;
        constAddr = constantBuffer + constOffset;
        if ((*(uint *)(((unsigned char *)0x000013c0) + ctx) & 4) == 0) {
          *(float *)(constantBuffer + constOffset) = result00;
          *(float *)(constAddr + 0x3c) = result33;
          *(float *)(constAddr + 4) = result01;
          *(float *)(constAddr + 8) = result02;
          *(float *)(constAddr + 0xc) = result03;
          *(float *)(constAddr + 0x10) = result10;
          *(float *)(constAddr + 0x14) = result11;
          *(float *)(constAddr + 0x18) = result12;
          *(float *)(constAddr + 0x1c) = result13;
          *(float *)(constAddr + 0x20) = result20;
          *(float *)(constAddr + 0x24) = result21;
          *(float *)(constAddr + 0x28) = result22;
          *(float *)(constAddr + 0x2c) = result23;
          *(float *)(constAddr + 0x30) = result30;
          *(float *)(constAddr + 0x34) = result31;
          *(float *)(constAddr + 0x38) = result32;
          paramCount = paramList[2];
        }
        else {
          *(float *)(constantBuffer + constOffset) = result00;
          *(float *)(constAddr + 0x3c) = result33;
          *(float *)(constAddr + 4) = result10;
          *(float *)(constAddr + 8) = result20;
          *(float *)(constAddr + 0xc) = result30;
          *(float *)(constAddr + 0x10) = result01;
          *(float *)(constAddr + 0x14) = result11;
          *(float *)(constAddr + 0x18) = result21;
          *(float *)(constAddr + 0x1c) = result31;
          *(float *)(constAddr + 0x20) = result02;
          *(float *)(constAddr + 0x24) = result12;
          *(float *)(constAddr + 0x28) = result22;
          *(float *)(constAddr + 0x2c) = result32;
          *(float *)(constAddr + 0x30) = result03;
          *(float *)(constAddr + 0x34) = result13;
          *(float *)(constAddr + 0x38) = result23;
          paramCount = paramList[2];
        }
        break;
      case 1:
        slotMatrixCopy = stateBlock + 0x1860 + elementIndex * 0x40;
        constOffset = *(int *)(elementIndex * 4 + paramMapEntries + 0x10) * 0x10;
        copySlot01 = *(undefined4 *)(slotMatrixCopy + 0x104);
        copySlot33 = *(undefined4 *)(slotMatrixCopy + 0x13c);
        constAddr = constantBuffer + constOffset;
        copySlot02 = *(undefined4 *)(slotMatrixCopy + 0x108);
        copySlot03 = *(undefined4 *)(slotMatrixCopy + 0x10c);
        copySlot10 = *(undefined4 *)(slotMatrixCopy + 0x110);
        copySlot11 = *(undefined4 *)(slotMatrixCopy + 0x114);
        copySlot12 = *(undefined4 *)(slotMatrixCopy + 0x118);
        copySlot13 = *(undefined4 *)(slotMatrixCopy + 0x11c);
        copySlot20 = *(undefined4 *)(slotMatrixCopy + 0x120);
        copySlot21 = *(undefined4 *)(slotMatrixCopy + 0x124);
        copySlot22 = *(undefined4 *)(slotMatrixCopy + 0x128);
        copySlot23 = *(undefined4 *)(slotMatrixCopy + 300);
        copySlot30 = *(undefined4 *)(slotMatrixCopy + 0x130);
        copySlot31 = *(undefined4 *)(slotMatrixCopy + 0x134);
        copySlot32 = *(undefined4 *)(slotMatrixCopy + 0x138);
        if ((*(uint *)(((unsigned char *)0x000013c0) + ctx) & 4) == 0) {
          *(undefined4 *)(constantBuffer + constOffset) = *(undefined4 *)(slotMatrixCopy + 0x100);
          *(undefined4 *)(constAddr + 0x3c) = copySlot33;
          *(undefined4 *)(constAddr + 4) = copySlot10;
          *(undefined4 *)(constAddr + 8) = copySlot20;
          *(undefined4 *)(constAddr + 0xc) = copySlot30;
          *(undefined4 *)(constAddr + 0x10) = copySlot01;
          *(undefined4 *)(constAddr + 0x14) = copySlot11;
          *(undefined4 *)(constAddr + 0x18) = copySlot21;
          *(undefined4 *)(constAddr + 0x1c) = copySlot31;
          *(undefined4 *)(constAddr + 0x20) = copySlot02;
          *(undefined4 *)(constAddr + 0x24) = copySlot12;
          *(undefined4 *)(constAddr + 0x28) = copySlot22;
          *(undefined4 *)(constAddr + 0x2c) = copySlot32;
          *(undefined4 *)(constAddr + 0x30) = copySlot03;
          *(undefined4 *)(constAddr + 0x34) = copySlot13;
          *(undefined4 *)(constAddr + 0x38) = copySlot23;
          paramCount = paramList[2];
        }
        else {
          *(undefined4 *)(constantBuffer + constOffset) = *(undefined4 *)(slotMatrixCopy + 0x100);
          *(undefined4 *)(constAddr + 0x3c) = copySlot33;
          *(undefined4 *)(constAddr + 4) = copySlot01;
          *(undefined4 *)(constAddr + 8) = copySlot02;
          *(undefined4 *)(constAddr + 0xc) = copySlot03;
          *(undefined4 *)(constAddr + 0x10) = copySlot10;
          *(undefined4 *)(constAddr + 0x14) = copySlot11;
          *(undefined4 *)(constAddr + 0x18) = copySlot12;
          *(undefined4 *)(constAddr + 0x1c) = copySlot13;
          *(undefined4 *)(constAddr + 0x20) = copySlot20;
          *(undefined4 *)(constAddr + 0x24) = copySlot21;
          *(undefined4 *)(constAddr + 0x28) = copySlot22;
          *(undefined4 *)(constAddr + 0x2c) = copySlot23;
          *(undefined4 *)(constAddr + 0x30) = copySlot30;
          *(undefined4 *)(constAddr + 0x34) = copySlot31;
          *(undefined4 *)(constAddr + 0x38) = copySlot32;
          paramCount = paramList[2];
        }
        break;
      case 2:
        slotMatrix = stateBlock + 0x1860 + elementIndex * 0x40;
        invSrc00 = *(float *)(slotMatrix + 0x100);
        invSrc32 = (double)*(float *)(slotMatrix + 0x138);
        invSrc13 = (double)*(float *)(slotMatrix + 0x11c);
        invSrc12 = (double)*(float *)(slotMatrix + 0x118);
        invSrc33 = (double)*(float *)(slotMatrix + 0x13c);
        invSrc03 = (double)*(float *)(slotMatrix + 0x10c);
        invSrc02 = (double)*(float *)(slotMatrix + 0x108);
        invSrc22 = (double)*(float *)(slotMatrix + 0x128);
        invSrc01 = *(float *)(slotMatrix + 0x104);
        invSrc11 = *(float *)(slotMatrix + 0x114);
        invSrc21 = *(float *)(slotMatrix + 0x124);
        minor1 = (float)(invSrc12 * invSrc33 - (double)(float)(invSrc13 * invSrc32));
        minor2 = (float)(invSrc02 * invSrc33 - (double)(float)(invSrc03 * invSrc32));
        minor3 = (float)(invSrc02 * invSrc13 - (double)(float)(invSrc03 * invSrc12));
        invSrc23 = (double)*(float *)(slotMatrix + 300);
        invSrc31 = *(float *)(slotMatrix + 0x134);
        invSrc20 = *(float *)(slotMatrix + 0x120);
        minor4 = (float)(invSrc02 * invSrc23 - (double)(float)(invSrc03 * invSrc22));
        minor5 = (float)(invSrc12 * invSrc23 - (double)(float)(invSrc13 * invSrc22));
        cofactor20 = invSrc31 * minor3 + (invSrc01 * minor1 - invSrc11 * minor2);
        minor6 = (float)(invSrc22 * invSrc33 - (double)(float)(invSrc23 * invSrc32));
        minor7 = (double)(invSrc00 * invSrc21 - invSrc01 * invSrc20);
        cofactor30 = -(invSrc01 * minor5 - (invSrc11 * minor4 - invSrc21 * minor3));
        cofactor10 = -(invSrc01 * minor6 - (invSrc21 * minor2 - invSrc31 * minor4));
        cofactor00 = invSrc31 * minor5 + (invSrc11 * minor6 - invSrc21 * minor1);
        invSrc30 = *(float *)(slotMatrix + 0x130);
        invSrc10 = *(float *)(slotMatrix + 0x110);
        minor8 = (double)(invSrc10 * invSrc21 - invSrc11 * invSrc20);
        minor9 = (double)(invSrc00 * invSrc31 - invSrc01 * invSrc30);
        minor10 = (double)(invSrc00 * invSrc11 - invSrc01 * invSrc10);
        minor11 = (double)(invSrc10 * invSrc31 - invSrc11 * invSrc30);
        minor12 = (double)(invSrc20 * invSrc31 - invSrc21 * invSrc30);
        determinant = invSrc00 * cofactor00 + invSrc10 * cofactor10 + invSrc30 * cofactor30 + invSrc20 * cofactor20;
        minorProduct = (float)(minor11 * invSrc23);
        scratchProduct = (double)(float)(minor7 * invSrc13 - (double)(float)(minor10 * invSrc23));
        minor13 = minor8 * invSrc03 - scratchProduct;
        if (determinant != FLOAT_001aa0d4) {
          invDeterminant = FLOAT_001aa0e8 / determinant;
          result00 = cofactor00 * invDeterminant;
          result02 = cofactor20 * invDeterminant;
          result01 = cofactor10 * invDeterminant;
          result30 = -(float)(minor12 * invSrc12 -
                              (double)(float)(minor11 * invSrc22 - (double)(float)(minor8 * invSrc32))) *
                      invDeterminant;
          result33 = (float)(minor10 * invSrc22 +
                             (double)(float)(minor8 * invSrc02 - (double)(float)(minor7 * invSrc12))) *
                      invDeterminant;
          result10 = invDeterminant * -(invSrc10 * minor6 - (invSrc20 * minor1 - invSrc30 * minor5));
          result20 = (float)(minor8 * invSrc33 + (double)(float)(minor12 * invSrc13 - (double)minorProduct))
                      * invDeterminant;
          result11 = invDeterminant * (invSrc30 * minor4 + (invSrc00 * minor6 - invSrc20 * minor2));
          result21 = -(float)(minor12 * invSrc03 -
                              (double)(float)(minor9 * invSrc23 - (double)(float)(minor7 * invSrc33))) *
                      invDeterminant;
          result12 = invDeterminant * -(invSrc00 * minor1 - (invSrc10 * minor2 - invSrc30 * minor3));
          result31 = (float)(minor7 * invSrc32 +
                             (double)(float)(minor12 * invSrc02 - (double)(float)(minor9 * invSrc22))) *
                      invDeterminant;
          result13 = invDeterminant * (invSrc20 * minor3 + (invSrc00 * minor5 - invSrc10 * minor4));
          result03 = cofactor30 * invDeterminant;
          result32 = -(float)(minor11 * invSrc02 -
                              (double)(float)(minor9 * invSrc12 - (double)(float)(minor10 * invSrc32))) *
                      invDeterminant;
          result22 = (float)(minor10 * invSrc33 +
                             (double)(float)(minor11 * invSrc03 - (double)(float)(minor9 * invSrc13))) *
                      invDeterminant;
          scratchProduct = (double)result22;
          result23 = -(float)minor13 * invDeterminant;
        }
        constOffset = *(int *)(elementIndex * 4 + paramMapEntries + 0x20) * 0x10;
        constAddr = constantBuffer + constOffset;
        *(float *)(constantBuffer + constOffset) = result00;
        *(float *)(constAddr + 0x3c) = result33;
        *(float *)(constAddr + 4) = result01;
        *(float *)(constAddr + 8) = result02;
        *(float *)(constAddr + 0xc) = result03;
        *(float *)(constAddr + 0x10) = result10;
        *(float *)(constAddr + 0x14) = result11;
        *(float *)(constAddr + 0x18) = result12;
        *(float *)(constAddr + 0x1c) = result13;
        *(float *)(constAddr + 0x20) = result20;
        *(float *)(constAddr + 0x24) = result21;
        *(float *)(constAddr + 0x28) = result22;
        *(float *)(constAddr + 0x2c) = result23;
        *(float *)(constAddr + 0x30) = result30;
        *(float *)(constAddr + 0x34) = result31;
        *(float *)(constAddr + 0x38) = result32;
        paramCount = paramList[2];
        break;
      case 3:
        mvpCopy01 = *(undefined4 *)(stateBlock + 0x1924);
        mvpCopy02 = *(undefined4 *)(stateBlock + 0x1928);
        mvpCopy03 = *(undefined4 *)(stateBlock + 0x192c);
        mvpCopy11 = *(undefined4 *)(stateBlock + 0x1934);
        constOffset = *(int *)(paramMap + 0xd4) * 0x10;
        mvpCopy33 = *(undefined4 *)(stateBlock + 0x195c);
        mvpCopy10 = *(undefined4 *)(stateBlock + 0x1930);
        mvpCopy12 = *(undefined4 *)(stateBlock + 0x1938);
        mvpCopy13 = *(undefined4 *)(stateBlock + 0x193c);
        mvpCopy20 = *(undefined4 *)(stateBlock + 0x1940);
        constAddr = constantBuffer + constOffset;
        mvpCopy21 = *(undefined4 *)(stateBlock + 0x1944);
        mvpCopy22 = *(undefined4 *)(stateBlock + 0x1948);
        mvpCopy23 = *(undefined4 *)(stateBlock + 0x194c);
        mvpCopy30 = *(undefined4 *)(stateBlock + 0x1950);
        mvpCopy31 = *(undefined4 *)(stateBlock + 0x1954);
        mvpCopy32 = *(undefined4 *)(stateBlock + 0x1958);
        if ((*(uint *)(((unsigned char *)0x000013c0) + ctx) & 4) == 0) {
          *(undefined4 *)(constantBuffer + constOffset) = *(undefined4 *)(stateBlock + 0x1920);
          *(undefined4 *)(constAddr + 0x3c) = mvpCopy33;
          *(undefined4 *)(constAddr + 4) = mvpCopy10;
          *(undefined4 *)(constAddr + 8) = mvpCopy20;
          *(undefined4 *)(constAddr + 0xc) = mvpCopy30;
          *(undefined4 *)(constAddr + 0x10) = mvpCopy01;
          *(undefined4 *)(constAddr + 0x14) = mvpCopy11;
          *(undefined4 *)(constAddr + 0x18) = mvpCopy21;
          *(undefined4 *)(constAddr + 0x1c) = mvpCopy31;
          *(undefined4 *)(constAddr + 0x20) = mvpCopy02;
          *(undefined4 *)(constAddr + 0x24) = mvpCopy12;
          *(undefined4 *)(constAddr + 0x28) = mvpCopy22;
          *(undefined4 *)(constAddr + 0x2c) = mvpCopy32;
          *(undefined4 *)(constAddr + 0x30) = mvpCopy03;
          *(undefined4 *)(constAddr + 0x34) = mvpCopy13;
          *(undefined4 *)(constAddr + 0x38) = mvpCopy23;
          paramCount = paramList[2];
        }
        else {
          *(undefined4 *)(constantBuffer + constOffset) = *(undefined4 *)(stateBlock + 0x1920);
          *(undefined4 *)(constAddr + 0x3c) = mvpCopy33;
          *(undefined4 *)(constAddr + 4) = mvpCopy01;
          *(undefined4 *)(constAddr + 8) = mvpCopy02;
          *(undefined4 *)(constAddr + 0xc) = mvpCopy03;
          *(undefined4 *)(constAddr + 0x10) = mvpCopy10;
          *(undefined4 *)(constAddr + 0x14) = mvpCopy11;
          *(undefined4 *)(constAddr + 0x18) = mvpCopy12;
          *(undefined4 *)(constAddr + 0x1c) = mvpCopy13;
          *(undefined4 *)(constAddr + 0x20) = mvpCopy20;
          *(undefined4 *)(constAddr + 0x24) = mvpCopy21;
          *(undefined4 *)(constAddr + 0x28) = mvpCopy22;
          *(undefined4 *)(constAddr + 0x2c) = mvpCopy23;
          *(undefined4 *)(constAddr + 0x30) = mvpCopy30;
          *(undefined4 *)(constAddr + 0x34) = mvpCopy31;
          *(undefined4 *)(constAddr + 0x38) = mvpCopy32;
          paramCount = paramList[2];
        }
        break;
      case 4:
        slotMatrixAlt = *(int *)(ctxState + 0x10) + 0x1860 + elementIndex * 0x40;
        constOffset = *(int *)(elementIndex * 4 + paramMapEntries + 0x34) * 0x10;
        slotAlt20 = *(undefined4 *)(slotMatrixAlt + 0x420);
        slotAlt33 = *(undefined4 *)(slotMatrixAlt + 0x43c);
        constAddr = constantBuffer + constOffset;
        slotAlt01 = *(undefined4 *)(slotMatrixAlt + 0x404);
        slotAlt02 = *(undefined4 *)(slotMatrixAlt + 0x408);
        slotAlt03 = *(undefined4 *)(slotMatrixAlt + 0x40c);
        slotAlt10 = *(undefined4 *)(slotMatrixAlt + 0x410);
        slotAlt11 = *(undefined4 *)(slotMatrixAlt + 0x414);
        slotAlt12 = *(undefined4 *)(slotMatrixAlt + 0x418);
        slotAlt13 = *(undefined4 *)(slotMatrixAlt + 0x41c);
        slotAlt21 = *(undefined4 *)(slotMatrixAlt + 0x424);
        slotAlt22 = *(undefined4 *)(slotMatrixAlt + 0x428);
        slotAlt23 = *(undefined4 *)(slotMatrixAlt + 0x42c);
        slotAlt30 = *(undefined4 *)(slotMatrixAlt + 0x430);
        slotAlt31 = *(undefined4 *)(slotMatrixAlt + 0x434);
        slotAlt32 = *(undefined4 *)(slotMatrixAlt + 0x438);
        *(undefined4 *)(constantBuffer + constOffset) = *(undefined4 *)(slotMatrixAlt + 0x400);
        *(undefined4 *)(constAddr + 8) = slotAlt20;
        *(undefined4 *)(constAddr + 4) = slotAlt10;
        *(undefined4 *)(constAddr + 0x10) = slotAlt01;
        *(undefined4 *)(constAddr + 0x14) = slotAlt11;
        *(undefined4 *)(constAddr + 0xc) = slotAlt30;
        *(undefined4 *)(constAddr + 0x18) = slotAlt21;
        *(undefined4 *)(constAddr + 0x1c) = slotAlt31;
        *(undefined4 *)(constAddr + 0x20) = slotAlt02;
        *(undefined4 *)(constAddr + 0x24) = slotAlt12;
        *(undefined4 *)(constAddr + 0x28) = slotAlt22;
        *(undefined4 *)(constAddr + 0x2c) = slotAlt32;
        *(undefined4 *)(constAddr + 0x30) = slotAlt03;
        *(undefined4 *)(constAddr + 0x34) = slotAlt13;
        *(undefined4 *)(constAddr + 0x38) = slotAlt23;
        *(undefined4 *)(constAddr + 0x3c) = slotAlt33;
        paramCount = paramList[2];
        break;
      case 5:
        valueXY = *(undefined8 *)(stateBlock + 0x24c0 + elementIndex * 0x80);
        valueZW = *(undefined8 *)(stateBlock + 0x24c0 + elementIndex * 0x80 + 8);
        constIndex = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x58);
        goto LAB_0009fa50;
      case 6:
        lightState = stateBlock + 0x24c0 + elementIndex * 0x80;
        valueXY = *(undefined8 *)(lightState + 0x10);
        valueZW = *(undefined8 *)(lightState + 0x18);
        constIndex = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x5c);
        goto LAB_0009fa50;
      case 7:
        lightState = stateBlock + 0x24c0 + elementIndex * 0x80;
        valueXY = *(undefined8 *)(lightState + 0x20);
        valueZW = *(undefined8 *)(lightState + 0x28);
        constIndex = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x68);
        goto LAB_0009fa50;
      case 8:
        if ((*(char *)(ctx + 0x12f) != '\0') && ((*(uint *)(stateBlock + 0x24ac) & 0xffff00) != 0))
        {
          if (*(char *)(stateBlock + 0x24ad) == '\0') {
            if (*(char *)(stateBlock + 0x24ae) != '\0') {
              stateF24a4 = *(float *)(stateBlock + 0x24a4);
              ctxVec4Entry = elementIndex * 0x10 + ctx;
              stateVecZ = stateF24a4 * *(float *)(ctxVec4Entry + 0x2a0);
              stateVecX = stateF24a4 * *(float *)(ctxVec4Entry + 0x298);
              stateVecY = stateF24a4 * *(float *)(ctxVec4Entry + 0x29c);
            }
          }
          else {
            scratchProduct = (double)(**(code **)(((unsigned char *)0x00001348) + ctx))
                                         (&stateVecX,elementIndex * 0x10 + ctx + 0x298);
          }
          stateVecW = 0x3f800000;
          constIndex = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x78);
          goto LAB_0009fb60;
        }
        ctxVec4Entry = ctx + elementIndex * 0x10 + 0x290;
        valueXY = *(undefined8 *)(ctxVec4Entry + 8);
        valueZW = *(undefined8 *)(ctxVec4Entry + 0x10);
        constIndex = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x78);
        goto LAB_0009fa50;
      case 9:
        if ((*(char *)(ctx + 0x12f) != '\0') && ((*(uint *)(stateBlock + 0x24ac) & 0xffff00) != 0))
        {
          if (*(char *)(stateBlock + 0x24ad) == '\0') {
            if (*(char *)(stateBlock + 0x24ae) != '\0') {
              stateF24a4 = *(float *)(stateBlock + 0x24a4);
              ctxVec4Entry = elementIndex * 0x10 + ctx;
              stateVecZ = stateF24a4 * *(float *)(ctxVec4Entry + 800);
              stateVecX = stateF24a4 * *(float *)(ctxVec4Entry + 0x318);
              stateVecY = stateF24a4 * *(float *)(ctxVec4Entry + 0x31c);
            }
          }
          else {
            scratchProduct = (double)(**(code **)(((unsigned char *)0x00001348) + ctx))
                                         (scratchProduct,&stateVecX,elementIndex * 0x10 + ctx + 0x318);
          }
          stateVecW = 0x3f800000;
          constIndex = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x7c);
          goto LAB_0009fb60;
        }
        ctxVec4Entry = ctx + elementIndex * 0x10 + 0x310;
        valueXY = *(undefined8 *)(ctxVec4Entry + 8);
        valueZW = *(undefined8 *)(ctxVec4Entry + 0x10);
        constIndex = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x7c);
        goto LAB_0009fa50;
      case 10:
        lightState = stateBlock + 0x24c0 + elementIndex * 0x80;
        stateVecX = *(float *)(lightState + 0x58);
        stateVecY = *(float *)(lightState + 0x54);
        stateVecZ = *(float *)(lightState + 0x50);
        stateVecW = 0;
        constIndex = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x80);
        goto LAB_0009fb60;
      case 0xb:
        ctxUnitState = ctx + elementIndex * 0x6c;
        constDest = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x84) * 0x10;
        *(undefined4 *)(constantBuffer + constDest) = *(undefined4 *)(((unsigned char *)0x00001500) + ctxUnitState + 4);
        constDest = constantBuffer + constDest;
        *(undefined4 *)(constDest + 4) = *(undefined4 *)(((unsigned char *)0x00001500) + ctxUnitState + 4);
        *(undefined4 *)(constDest + 8) = *(undefined4 *)(((unsigned char *)0x00001500) + ctxUnitState + 4);
        *(undefined4 *)(constDest + 0xc) = *(undefined4 *)(((unsigned char *)0x00001500) + ctxUnitState + 4);
        paramCount = paramList[2];
        break;
      case 0xc:
        ctxUnitState = ctx + elementIndex * 0x6c;
        constDest = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x88) * 0x10;
        *(undefined4 *)(constantBuffer + constDest) = *(undefined4 *)(((unsigned char *)0x00001500) + ctxUnitState + 8);
        constDest = constantBuffer + constDest;
        *(undefined4 *)(constDest + 4) = *(undefined4 *)(((unsigned char *)0x00001500) + ctxUnitState + 8);
        *(undefined4 *)(constDest + 8) = *(undefined4 *)(((unsigned char *)0x00001500) + ctxUnitState + 8);
        *(undefined4 *)(constDest + 0xc) = *(undefined4 *)(((unsigned char *)0x00001500) + ctxUnitState + 8);
        paramCount = paramList[2];
        break;
      case 0xd:
        lightState2 = stateBlock + 0x24c0 + elementIndex * 0x80;
        constDest = *(int *)(elementIndex * 0x3c + paramMapEntries + 0x8c) * 0x10;
        *(undefined4 *)(constantBuffer + constDest) = *(undefined4 *)(lightState2 + 0x5c);
        constDest = constantBuffer + constDest;
        *(undefined4 *)(constDest + 4) = *(undefined4 *)(lightState2 + 0x5c);
        *(undefined4 *)(constDest + 8) = *(undefined4 *)(lightState2 + 0x5c);
        *(undefined4 *)(constDest + 0xc) = *(undefined4 *)(lightState2 + 0x5c);
        paramCount = paramList[2];
        break;
      case 0xe:
        if (elementIndex == 0) {
          valueZW = *(undefined8 *)(stateBlock + 0x28f8);
          valueXY = *(undefined8 *)(stateBlock + 0x28f0);
          constIndex = *(int *)(paramMap + 0x2d8);
        }
        else {
          valueZW = *(undefined8 *)(((unsigned char *)0x00002b38) + stateBlock);
          valueXY = *(undefined8 *)(stateBlock + 0x2b30);
          constIndex = *(int *)(elementIndex * 0x24 + paramMapEntries + 0x234);
        }
        goto LAB_0009fa50;
      case 0xf:
        if (elementIndex == 0) {
          valueZW = *(undefined8 *)(stateBlock + 0x28c8);
          valueXY = *(undefined8 *)(stateBlock + 0x28c0);
          constIndex = *(int *)(paramMap + 0x2dc);
        }
        else {
          valueZW = *(undefined8 *)(stateBlock + 0x2b08);
          valueXY = *(undefined8 *)(stateBlock + 0x2b00);
          constIndex = *(int *)(elementIndex * 0x24 + paramMapEntries + 0x238);
        }
        goto LAB_0009fa50;
      case 0x10:
        if (elementIndex == 0) {
          valueZW = *(undefined8 *)(stateBlock + 0x28d8);
          valueXY = *(undefined8 *)(stateBlock + 0x28d0);
          constIndex = *(int *)(paramMap + 0x2e0);
        }
        else {
          valueZW = *(undefined8 *)(stateBlock + 0x2b18);
          valueXY = *(undefined8 *)(stateBlock + 0x2b10);
          constIndex = *(int *)(elementIndex * 0x24 + paramMapEntries + 0x23c);
        }
        goto LAB_0009fa50;
      case 0x11:
        if (elementIndex == 0) {
          valueZW = *(undefined8 *)(stateBlock + 0x28e8);
          valueXY = *(undefined8 *)(stateBlock + 0x28e0);
          constIndex = *(int *)(paramMap + 0x2ec);
        }
        else {
          valueZW = *(undefined8 *)(stateBlock + 0x2b28);
          valueXY = *(undefined8 *)(stateBlock + 0x2b20);
          constIndex = *(int *)(elementIndex * 0x24 + paramMapEntries + 0x248);
        }
        goto LAB_0009fa50;
      case 0x12:
        if (elementIndex == 0) {
          stateVecX = *(float *)(stateBlock + 0x28c0) * *(float *)(stateBlock + 0x24b0) +
                      *(float *)(stateBlock + 0x28f0);
          stateVecY = *(float *)(stateBlock + 0x28c4) * *(float *)(stateBlock + 0x24b4) +
                       *(float *)(stateBlock + 0x28f4);
          stateVecZ = *(float *)(stateBlock + 0x28c8) * *(float *)(stateBlock + 0x24b8) +
                      *(float *)(stateBlock + 0x28f8);
        }
        else {
          stateVecX = *(float *)(stateBlock + 0x2b00) * *(float *)(stateBlock + 0x24b0) +
                      *(float *)(stateBlock + 0x2b30);
          stateVecY = *(float *)(stateBlock + 0x2b04) * *(float *)(stateBlock + 0x24b4) +
                       *(float *)(stateBlock + 0x2b34);
          stateVecZ = *(float *)(stateBlock + 0x2b08) * *(float *)(stateBlock + 0x24b8) +
                      *(float *)(((unsigned char *)0x00002b38) + stateBlock);
        }
        constOffset = *(int *)(elementIndex * 0x24 + paramMapEntries + 0x254) * 0x10;
        *(ulonglong *)(constantBuffer + constOffset) = CONCAT44(stateVecX,stateVecY);
        *(ulonglong *)(constantBuffer + constOffset + 8) = CONCAT44(stateVecZ,stateVecW);
        paramCount = paramList[2];
        break;
      case 0x13:
        if (elementIndex == 0) {
          constDest = *(int *)(paramMap + 800) * 0x10;
          *(undefined4 *)(constantBuffer + constDest) = *(undefined4 *)(stateBlock + 0x2900);
          constDest = constantBuffer + constDest;
          *(undefined4 *)(constDest + 4) = *(undefined4 *)(stateBlock + 0x2900);
          *(undefined4 *)(constDest + 8) = *(undefined4 *)(stateBlock + 0x2900);
          *(undefined4 *)(constDest + 0xc) = *(undefined4 *)(stateBlock + 0x2900);
          paramCount = paramList[2];
        }
        else {
          constDest = *(int *)(elementIndex * 4 + paramMapEntries + 0x27c) * 0x10;
          *(undefined4 *)(constantBuffer + constDest) = *(undefined4 *)(((unsigned char *)0x00002b40) + stateBlock);
          constDest = constantBuffer + constDest;
          *(undefined4 *)(constDest + 4) = *(undefined4 *)(((unsigned char *)0x00002b40) + stateBlock);
          *(undefined4 *)(constDest + 8) = *(undefined4 *)(((unsigned char *)0x00002b40) + stateBlock);
          *(undefined4 *)(constDest + 0xc) = *(undefined4 *)(((unsigned char *)0x00002b40) + stateBlock);
          paramCount = paramList[2];
        }
        break;
      case 0x14:
        valueZW = *(undefined8 *)(stateBlock + 0x24b8);
        valueXY = *(undefined8 *)(stateBlock + 0x24b0);
        constIndex = *(int *)(paramMap + 0x328);
        goto LAB_0009fa50;
      case 0x15:
        stateVecY = *(float *)(ctx + 0x134);
        stateVecZ = *(float *)(ctx + 0x138);
        stateVecW = 0;
        stateVecX = 0.0;
        constIndex = *(int *)(paramMap + 0x330);
        goto LAB_0009fb60;
      case 0x16:
        stateVecX = *(float *)(ctx + 400);
        stateVecY = *(float *)(ctx + 0x194);
        stateVecZ = *(float *)(ctx + 0xf0);
        stateVecW = *(undefined4 *)(ctx + 0x198);
        constIndex = *(int *)(paramMap + 0x334);
        goto LAB_0009fb60;
      case 0x17:
        stateVecX = *(float *)(ctx + 0x118);
        stateVecY = *(float *)(ctx + 0x114);
        stateVecZ = *(float *)(ctx + 0x110);
        stateVecW = 0;
        constOffset = *(int *)(paramMap + 0x338) * 0x10;
        *(ulonglong *)(constantBuffer + constOffset) = CONCAT44(stateVecX,stateVecY);
        *(ulonglong *)(constantBuffer + constOffset + 8) = (ulonglong)(uint)GH_F2U(stateVecZ) << 0x20;
        paramCount = paramList[2];
        break;
      case 0x18:
        if ((*(uint *)(ctx + 0x44) & 0x40000000) == 0) {
          intToDoubleHiB = 0x43300000;
          intToDoubleHiA = 0x43300000;
          intToDoubleLoA = *(uint *)(ctx + 0x108) ^ 0x80000000;
          intToDoubleLoB = *(uint *)(ctx + 0x10c) ^ 0x80000000;
          stateVecX = (float)((double)CONCAT44(0x43300000,intToDoubleLoA) - DOUBLE_001aa1e0);
          stateVecY = (float)((double)CONCAT44(0x43300000,intToDoubleLoB) - DOUBLE_001aa1e0);
        }
        else {
          stateVecX = *(float *)(ctx + 0x100);
          stateVecY = *(float *)(ctx + 0x104);
        }
        stateVecW = 0;
        stateVecZ = 0.0;
        constIndex = *(int *)(paramMap + 0x340);
        goto LAB_0009fb60;
      case 0x19:
        constDest = *(int *)(paramMap + 0x344) * 0x10;
        *(undefined4 *)(constantBuffer + constDest) = *(undefined4 *)(stateBlock + 0x24a4);
        constDest = constantBuffer + constDest;
        *(undefined4 *)(constDest + 4) = *(undefined4 *)(stateBlock + 0x24a4);
        *(undefined4 *)(constDest + 8) = *(undefined4 *)(stateBlock + 0x24a4);
        *(undefined4 *)(constDest + 0xc) = *(undefined4 *)(stateBlock + 0x24a4);
        paramCount = paramList[2];
        break;
      case 0x1a:
        texGenComponent = elementIndex & 3;
        texUnit = elementIndex >> 2;
        if (texGenComponent == 1) {
          texUnitState = texUnit * 0xcc + ctx;
          if (*(short *)(texUnitState + 0x4b0) == 0x2401) {
            texGenPlane = (undefined8 *)(texUnitState + 0x4c4);
          }
          else {
            texGenPlane = (undefined8 *)(texUnit * 0xcc + ctx + 0x4b4);
          }
        }
        else if (texGenComponent == 0) {
          texUnitState = texUnit * 0xcc + ctx;
          if (*(short *)(texUnitState + 0x48c) == 0x2401) {
            texGenPlane = (undefined8 *)(texUnitState + 0x4a0);
          }
          else {
            texGenPlane = (undefined8 *)(texUnit * 0xcc + ctx + 0x490);
          }
        }
        else if (texGenComponent == 2) {
          texUnitState = texUnit * 0xcc + ctx;
          if (*(short *)(texUnitState + 0x4d4) == 0x2401) {
            texGenPlane = (undefined8 *)(texUnitState + 0x4e8);
          }
          else {
            texGenPlane = (undefined8 *)(texUnit * 0xcc + ctx + 0x4d8);
          }
        }
        else {
          texGenPlane = (undefined8 *)0x0;
          if (texGenComponent == 3) {
            texUnitState = texUnit * 0xcc + ctx;
            if (*(short *)(texUnitState + 0x4f8) == 0x2401) {
              texGenPlane = (undefined8 *)(texUnitState + 0x50c);
            }
            else {
              texGenPlane = (undefined8 *)(texUnit * 0xcc + ctx + 0x4fc);
            }
          }
        }
        valueXY = texGenPlane[1];
        constOffset = *(int *)(elementIndex * 4 + paramMapEntries + 0x2a4) * 0x10;
        *(undefined8 *)(constantBuffer + constOffset) = *texGenPlane;
        *(undefined8 *)(constantBuffer + constOffset + 8) = valueXY;
        paramCount = paramList[2];
        break;
      case 0x1b:
        valueZW = *(undefined8 *)(ctx + 0x3a0);
        valueXY = *(undefined8 *)(ctx + 0x398);
        constIndex = *(int *)(paramMap + 0x32c);
LAB_0009fa50:
        *(undefined8 *)(constantBuffer + constIndex * 0x10) = valueXY;
        *(undefined8 *)(constantBuffer + constIndex * 0x10 + 8) = valueZW;
        paramCount = paramList[2];
        break;
      case 0x1c:
        lightState = stateBlock + 0x24c0 + (elementIndex >> 1) * 0x80;
        materialState = (elementIndex & 1) * 0x240 + stateBlock;
        stateVecX = *(float *)(lightState + 0x10) * *(float *)(materialState + 0x28d0);
        stateVecY = *(float *)(lightState + 0x14) * *(float *)(materialState + 0x28d4);
        stateVecZ = *(float *)(lightState + 0x18) * *(float *)(materialState + 0x28d8);
        stateVecW = *(undefined4 *)(materialState + 0x28dc);
        constIndex = *(int *)(((elementIndex >> 1) * 0xf + (elementIndex & 1)) * 4 + paramMapEntries + 0x60);
        goto LAB_0009fb60;
      case 0x1d:
        lightState = stateBlock + 0x24c0 + (elementIndex >> 1) * 0x80;
        materialState = (elementIndex & 1) * 0x240 + stateBlock;
        stateVecX = *(float *)(lightState + 0x20) * *(float *)(materialState + 0x28e0);
        stateVecY = *(float *)(lightState + 0x24) * *(float *)(materialState + 0x28e4);
        stateVecW = 0x3f800000;
        stateVecZ = *(float *)(lightState + 0x28) * *(float *)(materialState + 0x28e8);
        constIndex = *(int *)(((elementIndex >> 1) * 0xf + (elementIndex & 1)) * 4 + paramMapEntries + 0x6c);
LAB_0009fb60:
        *(ulonglong *)(constantBuffer + constIndex * 0x10) = CONCAT44(stateVecX,stateVecY);
        *(ulonglong *)(constantBuffer + constIndex * 0x10 + 8) = CONCAT44(stateVecZ,stateVecW);
        paramCount = paramList[2];
      }
      paramIndex = paramIndex + 1;
      paramOffset = paramOffset + 4;
    } while (paramIndex < paramCount);
  }
  _restf14();
  return;
}

/* arbProgramFindIndex @ 0xa0290 (96 bytes) */
int arbProgramFindIndex(ctx, programTable, programId)
  undefined4 ctx;
  int programTable;
  int programId;
{
  bool searching;
  uint entryIndex;
  int idOffset;
  
  if (programId != 0) {
    entryIndex = 3;
    idOffset = 0x48;
    searching = true;
    while (entryIndex < *(uint *)(programTable + 4)) {
      if (!searching) {
        return entryIndex;
      }
      if (programId == *(int *)(idOffset + *(int *)(programTable + 8))) {
        searching = false;
      }
      else {
        entryIndex = entryIndex + 1;
        idOffset = idOffset + 0x18;
      }
    }
    if (!searching) {
      return entryIndex;
    }
  }
  return 0;
}

/* glProgramStringARB_impl @ 0xa0300 (80 bytes) */
int glProgramStringARB_impl(ctx, target, format, length, text, param_6, param_7, param_8)
  int ctx;
  int target;
  int format;
  int length;
  undefined4 text;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  *(undefined4 *)(((unsigned char *)0x00001124) + ctx) = 0xffffffff;
  **(undefined1 **)(((unsigned char *)0x00001128) + ctx) = 0;
  if (length < 1) {
    return;
  }
  if (format != 0x8875) {
    return;
  }
  if (target != 0x8804) {
    return;
  }
  return arbfpProgramString(ctx,0x8875,length,text);
}

/* arbProgramEntryInit @ 0xa0350 (36 bytes) */
int arbProgramEntryInit(param_1, param_2)
  undefined4 param_1;
  undefined4 *param_2;
{
  param_2[5] = 0;
  param_2[3] = 0xffffffff;
  *param_2 = 0;
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[4] = 0;
  return;
}

/* glBindProgramARB_impl @ 0xa0380 (476 bytes) */
int glBindProgramARB_impl(ctx, target, programId, unusedArg4, unusedArg5, unusedArg6, entries)
  int ctx;
  int target;
  int programId;
  undefined4 unusedArg4;
  undefined4 unusedArg5;
  undefined4 unusedArg6;
  int entries;
{
  int entriesBase;
  int newEntries;
  uint programCount;
  int programIndex;
  undefined4 programObject;
  undefined4 a1;
  int a2;
  undefined4 in_r10;
  int entryPtr;
  int programTable;
  
  if ((target == 0x8620) || (target == 0x8804)) {
    programTable = *(int *)(((unsigned char *)0x0000112c) + ctx);
    a2 = programId;
    programIndex = ((int (*)())arbProgramFindIndex)(ctx,programTable,programId);
    if (programIndex == 0) {
      if (programId != 0) {
        programCount = *(uint *)(programTable + 4);
        if ((programCount & 7) == 0) {
          newEntries = (**(code **)(ctx + 0xc))(programCount * 0x18 + 0xc0);
          if (newEntries == 0) {
            return;
          }
          a2 = *(int *)(programTable + 4) * 0x18;
          (**(code **)(((unsigned char *)0x00001344) + ctx))(newEntries,*(undefined4 *)(programTable + 8),a2);
          (**(code **)(ctx + 0x18))(*(undefined4 *)(programTable + 8));
          *(int *)(programTable + 8) = newEntries;
          programCount = *(uint *)(programTable + 4);
        }
        ((int (*)())arbProgramEntryInit)(ctx,programCount * 0x18 + *(int *)(programTable + 8));
        *(int *)(*(int *)(programTable + 4) * 0x18 + *(int *)(programTable + 8) + 4) = target;
        *(int *)(*(int *)(programTable + 4) * 0x18 + *(int *)(programTable + 8)) = programId;
        if (target == 0x8804) {
          entriesBase = *(int *)(programTable + 8);
          entryPtr = *(int *)(programTable + 4) * 0x18 + entriesBase;
          programObject = (**(code **)(ctx + 0xc))(0x78,a1,a2,unusedArg4,unusedArg5,unusedArg6,entriesBase);
          *(undefined4 *)(entryPtr + 0x14) = programObject;
          arbfpProgramObjectInit(ctx,*(undefined4 *)
                                (*(int *)(programTable + 4) * 0x18 + *(int *)(programTable + 8) + 0x14));
          arbfpBindProgram(ctx,*(undefined4 *)(programTable + 4),a2,unusedArg4,unusedArg5,unusedArg6,entriesBase,in_r10);
        }
        *(int *)(programTable + 4) = *(int *)(programTable + 4) + 1;
        return;
      }
    }
    else {
      entries = *(int *)(programTable + 8);
      if (target != *(int *)(programIndex * 0x18 + entries + 4)) {
        return;
      }
    }
    if (target == 0x8804) {
      if (programIndex == 0) {
        programIndex = *(int *)(((unsigned char *)0x0000126c) + ctx);
      }
      arbfpBindProgram(ctx,programIndex,a2,unusedArg4,unusedArg5,unusedArg6,entries,in_r10);
      return;
    }
  }
  return;
}

/* glGenProgramsARB_impl @ 0xa0570 (124 bytes) */
int glGenProgramsARB_impl(ctx, count, ids)
  int ctx;
  int count;
  int ids;
{
  int iVar1;
  int loopIndex;
  int *piVar3;
  int iVar4;
  
  if (0 < count) {
    piVar3 = *(int **)(((unsigned char *)0x0000112c) + ctx);
    loopIndex = 0;
    iVar4 = *piVar3;
    do {
      while (iVar1 = ((int (*)())arbProgramFindIndex)(ctx,piVar3,iVar4), iVar1 != 0) {
        iVar4 = iVar4 + 1;
      }
      iVar1 = loopIndex * 4;
      loopIndex = loopIndex + 1;
      *(int *)(ids + iVar1) = iVar4;
      iVar4 = iVar4 + 1;
    } while (count != loopIndex);
    *piVar3 = iVar4;
  }
  return;
}

/* glGetProgramivARB_impl @ 0xa05f0 (704 bytes) */
int glGetProgramivARB_impl(ctx, target, pname, params)
  int ctx;
  int target;
  int pname;
  uint *params;
{
  int iVar1;
  int iVar2;
  
  if (target == 0x8620) {
    iVar2 = *(int *)(((unsigned char *)0x000014a0) + ctx);
  }
  else {
    if (target != 0x8804) {
      return;
    }
    iVar2 = *(int *)(((unsigned char *)0x00001270) + ctx);
  }
  iVar1 = *(int *)(((unsigned char *)0x0000112c) + ctx);
  if (pname == 0x8627) {
    *params = *(uint *)(iVar2 * 0x18 + *(int *)(iVar1 + 8) + 0xc);
    return;
  }
  if (pname == 0x8876) {
    *params = *(uint *)(iVar2 * 0x18 + *(int *)(iVar1 + 8) + 8);
    return;
  }
  if (pname != 0x8677) {
    if (target == 0x8804) {
      iVar2 = *(int *)(iVar2 * 0x18 + *(int *)(iVar1 + 8) + 0x14);
      switch(pname) {
      case 0x8805:
        *params = *(uint *)(*(int *)(iVar2 + 0x74) + 0x6c);
        return;
      case 0x8806:
        *params = *(uint *)(*(int *)(iVar2 + 0x74) + 0x70);
        return;
      case 0x8807:
        *params = *(uint *)(*(int *)(iVar2 + 0x74) + 0x74);
        return;
      case 0x8808:
        *params = *(uint *)(iVar2 + 0x54);
        return;
      case 0x8809:
        *params = *(uint *)(iVar2 + 0x58);
        return;
      case 0x880a:
        *params = *(uint *)(iVar2 + 0x5c);
switchD_000a0718_caseD_8811:
        return;
      case 0x880b:
        *params = *(uint *)(((unsigned char *)0x00001204) + ctx);
        return;
      case 0x880c:
        *params = *(uint *)(((unsigned char *)0x00001208) + ctx);
        return;
      case 0x880d:
        *params = *(uint *)(((unsigned char *)0x0000120cU) + ctx);
        return;
      case 0x880e:
        *params = *(uint *)(((unsigned char *)0x00001210) + ctx);
        return;
      case 0x880f:
        *params = *(uint *)(((unsigned char *)0x00001214) + ctx);
        return;
      case 0x8810:
        *params = *(uint *)(((unsigned char *)0x00001218) + ctx);
        return;
      case 0x8811:
      case 0x8812:
      case 0x8813:
      case 0x8814:
      case 0x8815:
      case 0x8816:
      case 0x8817:
      case 0x8818:
      case 0x8819:
      case 0x881a:
      case 0x881b:
      case 0x881c:
      case 0x881d:
      case 0x881e:
      case 0x881f:
      case 0x8820:
      case 0x8821:
      case 0x8822:
      case 0x8823:
      case 0x8824:
      case 0x8825:
      case 0x8826:
      case 0x8827:
      case 0x8828:
      case 0x8829:
      case 0x882a:
      case 0x882b:
      case 0x882c:
      case 0x882d:
      case 0x882e:
      case 0x882f:
      case 0x8830:
      case 0x8831:
      case 0x8832:
      case 0x8833:
      case 0x8834:
      case 0x8835:
      case 0x8836:
      case 0x8837:
      case 0x8838:
      case 0x8839:
      case 0x883a:
      case 0x883b:
      case 0x883c:
      case 0x883d:
      case 0x883e:
      case 0x883f:
      case 0x8840:
      case 0x8841:
      case 0x8842:
      case 0x8843:
      case 0x8844:
      case 0x8845:
      case 0x8846:
      case 0x8847:
      case 0x8848:
      case 0x8849:
      case 0x884a:
      case 0x884b:
      case 0x884c:
      case 0x884d:
      case 0x884e:
      case 0x884f:
      case 0x8850:
      case 0x8851:
      case 0x8852:
      case 0x8853:
      case 0x8854:
      case 0x8855:
      case 0x8856:
      case 0x8857:
      case 0x8858:
      case 0x8859:
      case 0x885a:
      case 0x885b:
      case 0x885c:
      case 0x885d:
      case 0x885e:
      case 0x885f:
      case 0x8860:
      case 0x8861:
      case 0x8862:
      case 0x8863:
      case 0x8864:
      case 0x8865:
      case 0x8866:
      case 0x8867:
      case 0x8868:
      case 0x8869:
      case 0x886a:
      case 0x886b:
      case 0x886c:
      case 0x886d:
      case 0x886e:
      case 0x886f:
      case 0x8870:
      case 0x8871:
      case 0x8872:
      case 0x8873:
      case 0x8874:
      case 0x8875:
      case 0x8876:
      case 0x8877:
      case 0x8878:
      case 0x8879:
      case 0x887a:
      case 0x887b:
      case 0x887c:
      case 0x887d:
      case 0x887e:
      case 0x887f:
      case 0x8880:
      case 0x8881:
      case 0x8882:
      case 0x8883:
      case 0x8884:
      case 0x8885:
      case 0x8886:
      case 0x8887:
      case 0x8888:
      case 0x8889:
      case 0x888a:
      case 0x888b:
      case 0x888c:
      case 0x888d:
      case 0x888e:
      case 0x888f:
      case 0x8890:
      case 0x8891:
      case 0x8892:
      case 0x8893:
      case 0x8894:
      case 0x8895:
      case 0x8896:
      case 0x8897:
      case 0x8898:
      case 0x8899:
      case 0x889a:
      case 0x889b:
      case 0x889c:
      case 0x889d:
      case 0x889e:
      case 0x889f:
        goto switchD_000a0718_caseD_8811;
      case 0x88a0:
        *params = *(uint *)(*(int *)(iVar2 + 0x74) + 0x68);
        return;
      case 0x88a1:
        *params = *(uint *)(((unsigned char *)0x000011d4) + ctx);
        return;
      case 0x88a2:
        *params = *(uint *)(iVar2 + 0x50);
        return;
      case 0x88a3:
        *params = *(uint *)(((unsigned char *)0x000011d8) + ctx);
        return;
      case 0x88a4:
        *params = *(uint *)(*(int *)(iVar2 + 0x74) + 0x88);
        return;
      case 0x88a5:
        *params = *(uint *)(((unsigned char *)0x000011dc) + ctx);
        return;
      case 0x88a6:
        *params = *(uint *)(iVar2 + 0x68);
        return;
      case 0x88a7:
        *params = *(uint *)(((unsigned char *)0x000011e0) + ctx);
        return;
      case 0x88a8:
        *params = *(uint *)(*(int *)(iVar2 + 0x74) + 0x84);
        return;
      case 0x88a9:
        *params = *(uint *)(((unsigned char *)0x000011e4) + ctx);
        return;
      case 0x88aa:
        *params = *(uint *)(iVar2 + 100);
        return;
      case 0x88ab:
        *params = *(uint *)(((unsigned char *)0x000011e8) + ctx);
        return;
      case 0x88ac:
        *params = *(uint *)(*(int *)(iVar2 + 0x74) + 0x7c);
        return;
      case 0x88ad:
        *params = *(uint *)(((unsigned char *)0x000011ec) + ctx);
        return;
      case 0x88ae:
        *params = *(uint *)(iVar2 + 0x60);
        return;
      case 0x88af:
        *params = *(uint *)(((unsigned char *)0x000011f0) + ctx);
        return;
      case 0x88b0:
      case 0x88b2:
        *params = 0;
        return;
      case 0x88b1:
        *params = *(uint *)(((unsigned char *)0x000011f4) + ctx);
        return;
      case 0x88b3:
        *params = *(uint *)(((unsigned char *)0x000011f8) + ctx);
        return;
      case 0x88b4:
        *params = *(uint *)(((unsigned char *)0x000011fc) + ctx);
        return;
      case 0x88b5:
        *params = *(uint *)(((unsigned char *)0x00001200) + ctx);
        return;
      case 0x88b6:
        *params = (uint)*(byte *)(iVar2 + 0x6c);
        return;
      default:
        return;
      }
    }
    return;
  }
  *params = *(uint *)(iVar2 * 0x18 + *(int *)(iVar1 + 8));
  return;
}

/* arbProgramEntryFree @ 0xa0ba0 (188 bytes) */
int arbProgramEntryFree(context, param_2)
  int context;
  undefined4 *param_2;
{
  int iVar1;
  
  iVar1 = param_2[5];
  if (iVar1 != 0) {
    if (param_2[1] == 0x8804) {
      arbfpProgramObjectFree(context,iVar1);
      iVar1 = param_2[5];
    }
    (**(code **)(context + 0x18))(iVar1);
    param_2[5] = 0;
  }
  if (param_2[4] != 0) {
    (**(code **)(context + 0x18))(param_2[4]);
    param_2[4] = 0;
  }
  param_2[2] = 0;
  param_2[3] = 0xffffffff;
  *param_2 = 0;
  param_2[1] = 0;
  return;
}

/* arbProgramTableRelease @ 0xa0c60 (260 bytes) */
int arbProgramTableRelease(ctx)
  int ctx;
{
  int entry;
  uint loopIndex;
  int entryOffset;
  int programTable;
  
  gldCallHook1278(ctx);
  if (*(int *)(((unsigned char *)0x00001128) + ctx) != 0) {
    (**(code **)(ctx + 0x18))(*(int *)(((unsigned char *)0x00001128) + ctx));
    *(undefined4 *)(((unsigned char *)0x00001128) + ctx) = 0;
  }
  *(int *)(*(int *)(((unsigned char *)0x0000112c) + ctx) + 0xc) =
       *(int *)(*(int *)(((unsigned char *)0x0000112c) + ctx) + 0xc) + -1;
  if (*(int *)(*(int *)(((unsigned char *)0x0000112c) + ctx) + 0xc) == 0) {
    programTable = *(int *)(((unsigned char *)0x0000112c) + ctx);
    if (*(int *)(programTable + 4) != 0) {
      loopIndex = 0;
      entryOffset = 0;
      do {
        loopIndex = loopIndex + 1;
        entry = entryOffset + *(int *)(programTable + 8);
        entryOffset = entryOffset + 0x18;
        ((int (*)())arbProgramEntryFree)(ctx,entry);
      } while (loopIndex < *(uint *)(programTable + 4));
    }
    *(undefined4 *)(programTable + 4) = 0;
    if (*(int *)(programTable + 8) != 0) {
      (**(code **)(ctx + 0x18))(*(int *)(programTable + 8));
      *(undefined4 *)(programTable + 8) = 0;
    }
    (**(code **)(ctx + 0x18))(programTable);
    *(undefined4 *)(((unsigned char *)0x0000112c) + ctx) = 0;
  }
  return;
}

/* glDeleteProgramsARB_impl @ 0xa0d70 (372 bytes) */
int glDeleteProgramsARB_impl(ctx, count, ids)
  int ctx;
  int count;
  int *ids;
{
  uint entryIndex;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar2;
  int loopIndex;
  int entryOffset;
  int programTable;
  
  if (0 < count) {
    programTable = *(int *)(((unsigned char *)0x0000112c) + ctx);
    loopIndex = 0;
    do {
      entryIndex = ((int (*)())arbProgramFindIndex)(ctx,programTable,*ids);
      if (entryIndex != 0) {
        iVar2 = *(int *)(programTable + 8);
        entryOffset = entryIndex * 0x18;
        if ((*(int *)(iVar2 + entryOffset + 4) == 0x8804) &&
           (*(int *)(*(int *)(((unsigned char *)0x00001270) + ctx) * 0x18 + iVar2) == *ids)) {
          ((int (*)())glBindProgramARB_impl)(ctx,0x8804,0,in_r6,in_r7,in_r8,*ids);
          iVar2 = *(int *)(programTable + 8);
        }
        ((int (*)())arbProgramEntryFree)(ctx,entryOffset + iVar2);
        entryOffset = entryOffset + *(int *)(programTable + 8);
        _memmove(entryOffset,entryOffset + 0x18,(*(int *)(programTable + 4) - entryIndex) * 0x18 + -0x18);
        entryOffset = *(int *)(programTable + 4) + -1;
        *(int *)(programTable + 4) = entryOffset;
        *(undefined4 *)(entryOffset * 0x18 + *(int *)(programTable + 8) + 8) = 0;
        *(undefined4 *)(*(int *)(programTable + 4) * 0x18 + *(int *)(programTable + 8)) = 0;
        *(undefined4 *)(*(int *)(programTable + 4) * 0x18 + *(int *)(programTable + 8) + 0xc) = 0xffffffff;
        *(undefined4 *)(*(int *)(programTable + 4) * 0x18 + *(int *)(programTable + 8) + 0x10) = 0;
        *(undefined4 *)(*(int *)(programTable + 4) * 0x18 + *(int *)(programTable + 8) + 4) = 0;
        *(undefined4 *)(*(int *)(programTable + 4) * 0x18 + *(int *)(programTable + 8) + 0x14) = 0;
        if (entryIndex < *(uint *)(((unsigned char *)0x00001270) + ctx)) {
          *(uint *)(((unsigned char *)0x00001270) + ctx) = *(uint *)(((unsigned char *)0x00001270) + ctx) - 1;
        }
      }
      loopIndex = loopIndex + 1;
      ids = ids + 1;
    } while (count != loopIndex);
  }
  return;
}

/* arbProgramTableInit @ 0xa0ef0 (144 bytes) */
int arbProgramTableInit(context)
  int context;
{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(((unsigned char *)0x0000112c) + context);
  puVar3[3] = 1;
  *puVar3 = 1;
  puVar3[4] = 1;
  puVar3[1] = 3;
  uVar1 = (**(code **)(context + 0xc))(0xc0);
  puVar3[2] = uVar1;
  *(undefined4 *)(((unsigned char *)0x00001124) + context) = 0xffffffff;
  puVar2 = (undefined1 *)(**(code **)(context + 0xc))(1);
  *(undefined1 **)(((unsigned char *)0x00001128) + context) = puVar2;
  *puVar2 = 0;
  *(undefined4 *)(((unsigned char *)0x00001130) + context) = 0;
  return arbfpInitProgramState(context);
}

/* noop_a0f80 @ 0xa0f80 (4 bytes) */
int noop_a0f80()
{
  return;
}

/* atifsInit @ 0xa0f90 (152 bytes) */
int atifsInit(ctx)
  int ctx;
{
  uint uVar1;
  undefined *puVar2;
  int iVar3;
  uint loopCounter;
  uint uVar5;
  int remaining;
  
  puVar2 = PTR_FUN_001e89f0;
  *(code **)(((unsigned char *)0x00001160) + ctx) = noop_a0f80;
  *(code **)(((unsigned char *)0x0000115c) + ctx) = noop_a0f80;
  *(undefined **)(((unsigned char *)0x00001164) + ctx) = puVar2;
  atifsResetState(ctx);
  uVar5 = *(uint *)(ctx + 0x27bc);
  loopCounter = 0;
  remaining = 0x10;
  iVar3 = ctx;
  do {
    uVar1 = loopCounter & 0x3f;
    *(undefined4 *)(iVar3 + 0x27c0) = 0xff;
    loopCounter = loopCounter + 1;
    iVar3 = iVar3 + 4;
    uVar5 = 1 << uVar1 | uVar5;
    remaining = remaining + -1;
  } while (remaining != 0);
  *(uint *)(ctx + 0x27bc) = uVar5;
  return 1;
}

/* FUN_000a1040 @ 0xa1040 (20 bytes) */
int FUN_000a1040(param_1, param_2)
  undefined4 param_1;
  int param_2;
{
  if (param_2 != 0) {
    return 0x125;
  }
  return 2;
}

/* arbProgramIsValid @ 0xa1060 (44 bytes) */
int arbProgramIsValid(param_1)
  int param_1;
{
  if (((param_1 != -0x1134) && (*(int *)(((unsigned char *)0x00001144) + param_1) != 0)) &&
     (*(char *)(*(int *)(((unsigned char *)0x00001144) + param_1) + 0x74) != '\0')) {
    return 1;
  }
  return 0;
}

