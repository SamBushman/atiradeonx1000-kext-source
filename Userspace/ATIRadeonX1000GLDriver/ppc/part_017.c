#include "decls.h"

/* extvsOptimizeProgram @ 0xb9f10 (11376 bytes) */
int extvsOptimizeProgram(ctx, shader)
  int ctx;
  int shader;
{
  undefined4 addInstWord50Mapped;
  undefined4 addInstWord48Mapped;
  undefined4 addInstWord34Mapped;
  undefined4 addInstWord4cMapped;
  undefined4 addInstWord30Mapped;
  undefined4 addInstWord28Mapped;
  undefined4 addInstWord50_3;
  undefined4 addInstWord10;
  undefined4 addInstWord50_2;
  undefined4 addInstWord34_2;
  undefined4 addInstWord44_3;
  undefined4 addInstWord44_2;
  undefined4 addInstWord1c;
  undefined4 addInstWordc;
  undefined4 addInstWord2c;
  undefined4 addInstWord44;
  undefined4 addInstWord30;
  undefined4 addInstWord48_2;
  undefined4 addInstWord14;
  undefined4 addInstWord8;
  undefined4 addInstWord28;
  undefined4 addInstWord40;
  undefined4 addInstWord4c;
  undefined4 partnerOffsetWordc;
  undefined4 partnerOffsetWord18;
  undefined4 partnerOffsetWord10;
  undefined4 partnerOffsetWord14;
  undefined4 partnerOffsetWord8;
  uint mulScanStart;
  uint shiftIndex;
  uint afterAddIndex;
  int *laterSrc1Slot;
  int *laterSrcSlot;
  int shiftDstPtr;
  int matMulInst;
  int mulOffset;
  int laterOffset;
  int remaining;
  int shiftCursorOffset;
  int partnerOffset;
  int followerCount;
  int matrixSymbol;
  int addInstOffset;
  int shiftSrc;
  int shiftOffset;
  int shiftDst;
  int addSrcIndex;
  int instArray;
  uint fusedPartnerIndex;
  uint followerIndex;
  uint addSearchIndex;
  uint matMulSearchIndex;
  uint mulSearchIndex;
  bool destXUnused;
  bool canContinue;
  char destEnableY;
  char destEnableZ;
  char destEnableW;
  bool fusable;
  bool notFused;
  int remainingLater;
  char *laterFlagCursor;
  uint instCount;
  int laterInstPtr;
  byte laterReadFlagD;
  byte laterReadFlagC;
  byte laterReadFlagA;
  int instEnd;
  byte laterReadFlagB;
  undefined4 *operandRecordPtr;
  uint instCountAtEntry;
  undefined4 *srcRecordPtr;
  int instKind;
  undefined4 addInstWord48;
  int *laterDestSlot;
  undefined4 operandWord;
  int shaderWord20;
  undefined4 addInstWord50;
  undefined4 addInstWord38;
  undefined4 addInstWord2cMapped;
  int laterSrcKind;
  undefined4 addInstWord4c_2;
  undefined4 addInstWord34;
  undefined4 addInstWord30_2;
  undefined4 addInstWord54;
  int symbolTable;
  uint sweepStep;
  uint scanIndex;
  int wantedKind;
  int instEndOffset;
  uint remainingInsts;
  undefined4 *addInst;
  undefined4 *mulInst;
  int iStack00000018;
  char readsX;
  char readsY;
  char readsZ;
  char readsW [25];
  
  symbolTable = shader + 0x1c;
  instCountAtEntry = *(uint *)(shader + 0x14);
  instCount = instCountAtEntry;
  iStack00000018 = ctx;
  if (instCountAtEntry != 0) {
    instEndOffset = instCountAtEntry * 0x74;
    sweepStep = 0;
    do {
      laterInstPtr = *(int *)(shader + 0x18);
      remainingInsts = instCountAtEntry - sweepStep;
      instEnd = instEndOffset + laterInstPtr;
      destEnableY = *(char *)(instEnd + -0x61);
      destEnableZ = *(char *)(instEnd + -0x5d);
      destEnableW = *(char *)(instEnd + -0x59);
      destXUnused = *(char *)(instEnd + -0x65) == '\0';
      if ((((destXUnused) && (destEnableY == '\0')) && (destEnableZ == '\0')) && (destEnableW == '\0')) {
LAB_000ba610:
        shiftCursorOffset = instEndOffset;
        if (remainingInsts < instCount) {
          do {
            remainingInsts = remainingInsts + 1;
            shiftSrc = shiftCursorOffset + *(int *)(shader + 0x18);
            _memcpy(shiftSrc + -0x74,shiftSrc,0x74);
            instCount = *(uint *)(shader + 0x14);
            shiftCursorOffset = shiftCursorOffset + 0x74;
          } while (remainingInsts < instCount);
        }
        instCount = instCount - 1;
        *(uint *)(shader + 0x14) = instCount;
      }
      else {
        instKind = *(int *)(instEnd + -0x70);
        if (instKind == 1) {
          if (remainingInsts < instCount) {
            remaining = instCount - remainingInsts;
            laterDestSlot = (int *)(instEnd + 4);
            laterReadFlagA = 0;
            laterReadFlagB = 0;
            laterReadFlagC = 0;
            laterReadFlagD = 0;
            do {
              if ((*laterDestSlot == 1) && (laterDestSlot[1] == *(int *)(instEnd + -0x6c))) {
                laterReadFlagB = laterReadFlagB | *(byte *)((int)laterDestSlot + 0xb);
                laterReadFlagA = laterReadFlagA | *(byte *)((int)laterDestSlot + 0xf);
                laterReadFlagC = laterReadFlagC | *(byte *)((int)laterDestSlot + 0x13);
                laterReadFlagD = laterReadFlagD | *(byte *)((int)laterDestSlot + 0x17);
              }
              laterDestSlot = laterDestSlot + 0x1d;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          else {
            laterReadFlagB = 0;
            laterReadFlagA = 0;
            laterReadFlagC = 0;
            laterReadFlagD = 0;
          }
          if ((((destXUnused) || (laterReadFlagB != 0)) && ((destEnableY == '\0' || (laterReadFlagA != 0)))) &&
             (((destEnableZ == '\0' || (laterReadFlagC != 0)) && ((destEnableW == '\0' || (laterReadFlagD != 0))))))
          goto LAB_000ba610;
        }
        else {
          if (*(int *)(instEnd + -0x74) == 0x87a2) {
            if (remainingInsts < instCount) {
              remaining = instCount - remainingInsts;
              laterFlagCursor = (char *)(instEnd + 0x38);
              fusable = true;
              laterReadFlagA = 0;
              laterReadFlagC = 0;
              laterReadFlagD = 0;
              laterReadFlagB = 0;
              do {
                if (((*laterFlagCursor != '\0') || (laterFlagCursor[0x1c] != '\0')) || (laterFlagCursor[0x38] != '\0')) {
                  fusable = false;
                }
                if ((*(int *)(laterFlagCursor + -0x34) == 2) &&
                   (*(int *)(laterFlagCursor + -0x30) == *(int *)(instEnd + -0x6c))) {
                  laterReadFlagA = laterReadFlagA | laterFlagCursor[-0x29];
                  laterReadFlagC = laterReadFlagC | laterFlagCursor[-0x25];
                  laterReadFlagD = laterReadFlagD | laterFlagCursor[-0x21];
                  laterReadFlagB = laterReadFlagB | laterFlagCursor[-0x1d];
                }
                laterFlagCursor = laterFlagCursor + 0x74;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            else {
              fusable = true;
              laterReadFlagA = 0;
              laterReadFlagC = 0;
              laterReadFlagD = 0;
              laterReadFlagB = 0;
            }
            if (((((((destXUnused) || (laterReadFlagA != 0)) && ((destEnableY == '\0' || (laterReadFlagC != 0)))) &&
                  ((destEnableZ == '\0' || (laterReadFlagD != 0)))) && ((destEnableW == '\0' || (laterReadFlagB != 0)))) &&
                (fusable)) || (instCount <= remainingInsts)) goto LAB_000ba610;
            remaining = instCount - remainingInsts;
            laterFlagCursor = (char *)(instEnd + 0x38);
            fusable = true;
            do {
              if (((*laterFlagCursor != '\0') || (laterFlagCursor[0x1c] != '\0')) || (laterFlagCursor[0x38] != '\0')) {
                fusable = false;
              }
              laterFlagCursor = laterFlagCursor + 0x74;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          else {
            if (*(char *)(shader + 0x7b) == '\0') {
              if (instKind == 2) {
                instKind = *(int *)(instEnd + -0x6c);
                shaderWord20 = *(int *)(shader + 0x20);
                goto LAB_000ba1a0;
              }
            }
            else if (instKind == 2) {
              instKind = *(int *)(instEnd + -0x6c);
              shaderWord20 = *(int *)(shader + 0x20);
              if (*(int *)(instKind * 0x54 + shaderWord20 + 0x28) == 0x87c4) goto LAB_000ba664;
LAB_000ba1a0:
              if (*(int *)(instKind * 0x54 + shaderWord20 + 0x24) == 0x87c0) goto LAB_000ba664;
            }
            if (remainingInsts < instCount) {
              laterReadFlagD = 0;
              laterReadFlagC = 0;
              laterReadFlagA = 0;
              laterReadFlagB = 0;
              fusable = true;
              instKind = instEndOffset;
              scanIndex = remainingInsts;
              while( true ) {
                laterInstPtr = instKind + laterInstPtr;
                if ((((*(int *)(laterInstPtr + 0x20) == 2) &&
                     (shaderWord20 = *(int *)(instEnd + -0x6c), *(int *)(laterInstPtr + 0x24) == shaderWord20)) ||
                    ((*(int *)(laterInstPtr + 0x3c) == 2 &&
                     (shaderWord20 = *(int *)(instEnd + -0x6c), *(int *)(laterInstPtr + 0x40) == shaderWord20)))) ||
                   ((*(int *)(laterInstPtr + 0x58) == 2 &&
                    (shaderWord20 = *(int *)(instEnd + -0x6c), *(int *)(laterInstPtr + 0x5c) == shaderWord20)))) {
                  extvsInstReadsTempComponents(symbolTable,laterInstPtr,shaderWord20,&readsX,&readsY,&readsZ,readsW);
                  if (((((destXUnused) || ((readsX == '\0' || (laterReadFlagB != 0)))) &&
                       ((destEnableY == '\0' || ((readsY == '\0' || (laterReadFlagA != 0)))))) &&
                      ((destEnableZ == '\0' || ((readsZ == '\0' || (laterReadFlagC != 0)))))) &&
                     ((destEnableW == '\0' || ((readsW[0] == '\0' || (laterReadFlagD != 0)))))) {
                    instCount = *(uint *)(shader + 0x14);
                  }
                  else {
                    instCount = *(uint *)(shader + 0x14);
                    fusable = false;
                  }
                }
                if ((*(int *)(laterInstPtr + 4) == 2) && (*(int *)(laterInstPtr + 8) == *(int *)(instEnd + -0x6c)))
                {
                  laterReadFlagD = laterReadFlagD | *(byte *)(laterInstPtr + 0x1b);
                  laterReadFlagB = laterReadFlagB | *(byte *)(laterInstPtr + 0xf);
                  laterReadFlagA = laterReadFlagA | *(byte *)(laterInstPtr + 0x13);
                  laterReadFlagC = laterReadFlagC | *(byte *)(laterInstPtr + 0x17);
                }
                scanIndex = scanIndex + 1;
                instKind = instKind + 0x74;
                if (instCount <= scanIndex) break;
                laterInstPtr = *(int *)(shader + 0x18);
              }
            }
            else {
              fusable = true;
              laterReadFlagB = 0;
              laterReadFlagA = 0;
              laterReadFlagC = 0;
              laterReadFlagD = 0;
            }
            if (((((destXUnused) || (laterReadFlagB != 0)) && ((destEnableY == '\0' || (laterReadFlagA != 0)))) &&
                ((((destEnableZ == '\0' || (laterReadFlagC != 0)) && ((destEnableW == '\0' || (laterReadFlagD != 0)))) &&
                 (fusable)))) || (instCount <= remainingInsts)) goto LAB_000ba610;
            fusable = true;
            laterReadFlagC = 0;
            laterReadFlagA = 0;
            laterReadFlagB = 0;
            laterReadFlagD = 0;
            laterOffset = instEndOffset;
            scanIndex = remainingInsts;
            do {
              instKind = laterOffset + *(int *)(shader + 0x18);
              if ((((*(int *)(instKind + 0x20) == 2) &&
                   (shaderWord20 = *(int *)(instEnd + -0x6c), *(int *)(instKind + 0x24) == shaderWord20)) ||
                  ((*(int *)(instKind + 0x3c) == 2 &&
                   (shaderWord20 = *(int *)(instEnd + -0x6c), *(int *)(instKind + 0x40) == shaderWord20)))) ||
                 ((*(int *)(instKind + 0x58) == 2 &&
                  (shaderWord20 = *(int *)(instEnd + -0x6c), *(int *)(instKind + 0x5c) == shaderWord20)))) {
                extvsInstReadsTempComponents(symbolTable,instKind,shaderWord20,&readsX,&readsY,&readsZ,readsW);
                if ((((destXUnused) || ((readsX == '\0' || (laterReadFlagC != 0)))) &&
                    (((destEnableY == '\0' || ((readsY == '\0' || (laterReadFlagA != 0)))) &&
                     ((destEnableZ == '\0' || ((readsZ == '\0' || (laterReadFlagB != 0)))))))) &&
                   ((destEnableW == '\0' || ((readsW[0] == '\0' || (laterReadFlagD != 0)))))) {
                  instCount = *(uint *)(shader + 0x14);
                }
                else {
                  instCount = *(uint *)(shader + 0x14);
                  fusable = false;
                }
              }
              if ((*(int *)(instKind + 4) == 2) && (*(int *)(instKind + 8) == *(int *)(instEnd + -0x6c)))
              {
                laterReadFlagD = laterReadFlagD | *(byte *)(instKind + 0x1b);
                laterReadFlagC = laterReadFlagC | *(byte *)(instKind + 0xf);
                laterReadFlagA = laterReadFlagA | *(byte *)(instKind + 0x13);
                laterReadFlagB = laterReadFlagB | *(byte *)(instKind + 0x17);
              }
              scanIndex = scanIndex + 1;
              laterOffset = laterOffset + 0x74;
            } while (scanIndex < instCount);
          }
          if (fusable) goto LAB_000ba610;
        }
      }
LAB_000ba664:
      sweepStep = sweepStep + 1;
      instEndOffset = instEndOffset + -0x74;
    } while (instCountAtEntry != sweepStep);
  }
  if (instCount != 0) {
    mulSearchIndex = 0;
    do {
      mulOffset = mulSearchIndex * 0x74;
      instArray = *(int *)(shader + 0x18);
      mulInst = (undefined4 *)(mulOffset + instArray);
      if ((((*(int *)(mulOffset + instArray) == 0x8786) && (mulInst[1] == 2)) &&
          ((mulInst[3] != 0 && ((mulInst[4] != 0 && (mulInst[5] != 0)))))) &&
         ((mulInst[6] != 0 && (remainingInsts = mulSearchIndex + 1, addSearchIndex = remainingInsts, remainingInsts < instCount)))) {
        do {
          addInstOffset = addSearchIndex * 0x74;
          addInst = (undefined4 *)(instArray + addInstOffset);
          if (*(int *)(instArray + addInstOffset) == 0x8787) {
            instKind = addInst[8];
            if ((instKind != 2) || (shaderWord20 = mulInst[2], addInst[9] != shaderWord20)) {
              if ((addInst[0xf] != 2) || (shaderWord20 = mulInst[2], addInst[0x10] != shaderWord20))
              goto LAB_000ba7ec;
              wantedKind = 2;
              if (instKind == 2) goto LAB_000ba7dc;
            }
            else {
              wantedKind = addInst[0xf];
              if (wantedKind == 2) {
LAB_000ba7dc:
                if (addInst[9] == addInst[0x10]) goto LAB_000ba7ec;
              }
            }
            canContinue = true;
            if (remainingInsts < addSearchIndex) {
              remainingLater = addSearchIndex - remainingInsts;
              laterSrcSlot = (int *)(instArray + remainingInsts * 0x74 + 0x20);
              do {
                if ((((*laterSrcSlot == 2) && (laterSrcSlot[1] == shaderWord20)) ||
                    ((laterSrcSlot[7] == 2 && (laterSrcSlot[8] == shaderWord20)))) ||
                   ((((laterSrcSlot[0xe] == 2 && (laterSrcSlot[0xf] == shaderWord20)) ||
                     ((laterSrcKind = laterSrcSlot[-7], laterSrcKind == 2 && (laterSrcSlot[-6] == shaderWord20)))) ||
                    (((laterSrcKind == mulInst[8] && (laterSrcSlot[-6] == mulInst[9])) ||
                     ((laterSrcKind == mulInst[0xf] && (laterSrcSlot[-6] == mulInst[0x10])))))))) {
                  canContinue = false;
                }
                laterSrcSlot = laterSrcSlot + 0x1d;
                remainingLater = remainingLater + -1;
              } while (remainingLater != 0);
              if (canContinue) goto LAB_000ba8a8;
LAB_000ba754:
              canContinue = true;
              remainingLater = addSearchIndex - remainingInsts;
              laterSrcSlot = (int *)(remainingInsts * 0x74 + instArray + 0x20);
              if ((addSearchIndex < mulSearchIndex + 2) || (addSearchIndex == 0)) {
                remainingLater = 1;
              }
              do {
                if ((((((*laterSrcSlot == 2) && (laterSrcSlot[1] == shaderWord20)) ||
                      ((laterSrcSlot[7] == 2 && (laterSrcSlot[8] == shaderWord20)))) ||
                     ((laterSrcSlot[0xe] == 2 && (laterSrcSlot[0xf] == shaderWord20)))) ||
                    (((*laterSrcSlot == 2 && (laterSrcSlot[1] == addInst[2])) ||
                     ((((laterSrcSlot[7] == 2 && (laterSrcSlot[8] == addInst[2])) ||
                       ((laterSrcSlot[0xe] == 2 && (laterSrcSlot[0xf] == addInst[2])))) ||
                      ((laterSrcKind = laterSrcSlot[-7], instKind == laterSrcKind && (laterSrcSlot[-6] == addInst[9]))))))))
                   || (((laterSrcKind == wantedKind && (laterSrcSlot[-6] == addInst[0x10])) ||
                       ((laterSrcKind == addInst[1] && (laterSrcSlot[-6] == addInst[2])))))) {
                  canContinue = false;
                }
                laterSrcSlot = laterSrcSlot + 0x1d;
                remainingLater = remainingLater + -1;
              } while (remainingLater != 0);
              if (canContinue) {
LAB_000bc018:
                canContinue = true;
                afterAddIndex = addSearchIndex + 1;
                if (afterAddIndex < instCount) {
                  remainingLater = instCount - afterAddIndex;
                  laterSrcSlot = (int *)(instArray + afterAddIndex * 0x74 + 0x20);
                  do {
                    if ((((*laterSrcSlot == 2) && (laterSrcSlot[1] == shaderWord20)) ||
                        ((laterSrcSlot[7] == 2 && (laterSrcSlot[8] == shaderWord20)))) ||
                       ((laterSrcSlot[0xe] == 2 && (laterSrcSlot[0xf] == shaderWord20)))) {
                      canContinue = false;
                    }
                    laterSrcSlot = laterSrcSlot + 0x1d;
                    remainingLater = remainingLater + -1;
                  } while (remainingLater != 0);
                  if (!canContinue) goto LAB_000bd6dc;
                }
                addSrcIndex = addInst[9];
                *mulInst = 0x8788;
                if (addSrcIndex == shaderWord20) {
                  addInstWord40 = addInst[0x10];
                  addInstWord44 = addInst[0x11];
                  addInstWord48 = addInst[0x12];
                  addInstWord4c_2 = addInst[0x13];
                  addInstWord50 = addInst[0x14];
                  addInstWord54 = addInst[0x15];
                  mulInst[0x16] = wantedKind;
                  mulInst[0x17] = addInstWord40;
                  mulInst[0x18] = addInstWord44;
                  mulInst[0x19] = addInstWord48;
                  mulInst[0x1a] = addInstWord4c_2;
                  mulInst[0x1b] = addInstWord50;
                  mulInst[0x1c] = addInstWord54;
                }
                else {
                  addInstWord28 = addInst[10];
                  addInstWord2c = addInst[0xb];
                  addInstWord30_2 = addInst[0xc];
                  addInstWord34 = addInst[0xd];
                  addInstWord38 = addInst[0xe];
                  addInstWord44_2 = addInst[0x11];
                  addInstWord48_2 = addInst[0x12];
                  addInstWord4c = addInst[0x13];
                  addInstWord50_2 = addInst[0x14];
                  mulInst[0x16] = instKind;
                  mulInst[0x17] = addSrcIndex;
                  mulInst[0x18] = addInstWord28;
                  mulInst[0x19] = addInstWord2c;
                  mulInst[0x1a] = addInstWord30_2;
                  mulInst[0x1b] = addInstWord34;
                  mulInst[0x1c] = addInstWord38;
                  addInst[10] = addInstWord44_2;
                  addInst[0xb] = addInstWord48_2;
                  addInst[0xc] = addInstWord4c;
                  addInst[0xd] = addInstWord50_2;
                }
                addInstWord8 = addInst[2];
                operandRecordPtr = addInst + 0x11;
                addInstWordc = addInst[3];
                addInstWord10 = addInst[4];
                mulInst[1] = addInst[1];
                mulInst[2] = addInstWord8;
                mulInst[3] = addInstWordc;
                mulInst[4] = addInstWord10;
                addInstWord1c = addInst[7];
                addInstWord14 = addInst[5];
                mulInst[6] = addInst[6];
                mulInst[7] = addInstWord1c;
                mulInst[5] = addInstWord14;
                addInstWord28Mapped = addInst[10];
                switch(addInstWord28Mapped) {
                case 0x87d9:
                  addInstWord28Mapped = 0x87d5;
                  break;
                case 0x87da:
                  addInstWord28Mapped = 0x87d6;
                  break;
                case 0x87db:
                  addInstWord28Mapped = 0x87d7;
                  break;
                case 0x87dc:
                  addInstWord28Mapped = 0x87d8;
                  break;
                case 0x87df:
                  addInstWord28Mapped = 0x87de;
                }
                addInstWord2cMapped = addInst[0xb];
                *operandRecordPtr = addInstWord28Mapped;
                switch(addInstWord2cMapped) {
                case 0x87d9:
                  addInstWord2cMapped = 0x87d5;
                  break;
                case 0x87da:
                  addInstWord2cMapped = 0x87d6;
                  break;
                case 0x87db:
                  addInstWord2cMapped = 0x87d7;
                  break;
                case 0x87dc:
                  addInstWord2cMapped = 0x87d8;
                  break;
                case 0x87df:
                  addInstWord2cMapped = 0x87de;
                }
                addInstWord30Mapped = addInst[0xc];
                addInst[0x12] = addInstWord2cMapped;
                switch(addInstWord30Mapped) {
                case 0x87d9:
                  addInstWord30Mapped = 0x87d5;
                  break;
                case 0x87da:
                  addInstWord30Mapped = 0x87d6;
                  break;
                case 0x87db:
                  addInstWord30Mapped = 0x87d7;
                  break;
                case 0x87dc:
                  addInstWord30Mapped = 0x87d8;
                  break;
                case 0x87df:
                  addInstWord30Mapped = 0x87de;
                }
                addInstWord34Mapped = addInst[0xd];
                addInst[0x13] = addInstWord30Mapped;
                switch(addInstWord34Mapped) {
                case 0x87d9:
                  addInstWord34Mapped = 0x87d5;
                  break;
                case 0x87da:
                  addInstWord34Mapped = 0x87d6;
                  break;
                case 0x87db:
                  addInstWord34Mapped = 0x87d7;
                  break;
                case 0x87dc:
                  addInstWord34Mapped = 0x87d8;
                  break;
                case 0x87df:
                  addInstWord34Mapped = 0x87de;
                }
                addInstWord28Mapped = addInst[10];
                addInst[0x14] = addInstWord34Mapped;
                srcRecordPtr = mulInst + 10;
                switch(addInstWord28Mapped) {
                case 0x87d5:
                  addInstWord28Mapped = *srcRecordPtr;
                  break;
                case 0x87d6:
                  addInstWord28Mapped = mulInst[0xb];
                  break;
                case 0x87d7:
                  addInstWord28Mapped = mulInst[0xc];
                  break;
                case 0x87d8:
                  addInstWord28Mapped = mulInst[0xd];
                  break;
                case 0x87d9:
                  addInstWord28Mapped = *srcRecordPtr;
                  switch(addInstWord28Mapped) {
                  case 0x87d5:
switchD_000bc544_caseD_87d5:
                    addInstWord28Mapped = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bc544_caseD_87d6:
                    addInstWord28Mapped = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bc544_caseD_87d7:
                    addInstWord28Mapped = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bc544_caseD_87d8:
                    addInstWord28Mapped = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bc544_caseD_87d9:
                    addInstWord28Mapped = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bc544_caseD_87da:
                    addInstWord28Mapped = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bc544_caseD_87db:
                    addInstWord28Mapped = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bc544_caseD_87dc:
                    addInstWord28Mapped = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bc544_caseD_87de:
                    addInstWord28Mapped = 0x87df;
                    break;
                  case 0x87df:
switchD_000bc544_caseD_87df:
                    addInstWord28Mapped = 0x87de;
                  }
                  break;
                case 0x87da:
                  addInstWord28Mapped = mulInst[0xb];
                  switch(addInstWord28Mapped) {
                  case 0x87d5:
                    goto switchD_000bc544_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc544_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc544_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc544_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc544_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc544_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc544_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc544_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc544_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc544_caseD_87df;
                  }
                  break;
                case 0x87db:
                  addInstWord28Mapped = mulInst[0xc];
                  switch(addInstWord28Mapped) {
                  case 0x87d5:
                    goto switchD_000bc544_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc544_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc544_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc544_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc544_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc544_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc544_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc544_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc544_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc544_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  addInstWord28Mapped = mulInst[0xd];
                  switch(addInstWord28Mapped) {
                  case 0x87d5:
                    goto switchD_000bc544_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc544_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc544_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc544_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc544_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc544_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc544_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc544_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc544_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc544_caseD_87df;
                  }
                }
                addInstWord2cMapped = addInst[0xb];
                addInst[10] = addInstWord28Mapped;
                switch(addInstWord2cMapped) {
                case 0x87d5:
                  addInstWord2cMapped = *srcRecordPtr;
                  break;
                case 0x87d6:
                  addInstWord2cMapped = mulInst[0xb];
                  break;
                case 0x87d7:
                  addInstWord2cMapped = mulInst[0xc];
                  break;
                case 0x87d8:
                  addInstWord2cMapped = mulInst[0xd];
                  break;
                case 0x87d9:
                  addInstWord2cMapped = *srcRecordPtr;
                  switch(addInstWord2cMapped) {
                  case 0x87d5:
switchD_000bc79c_caseD_87d5:
                    addInstWord2cMapped = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bc79c_caseD_87d6:
                    addInstWord2cMapped = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bc79c_caseD_87d7:
                    addInstWord2cMapped = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bc79c_caseD_87d8:
                    addInstWord2cMapped = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bc79c_caseD_87d9:
                    addInstWord2cMapped = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bc79c_caseD_87da:
                    addInstWord2cMapped = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bc79c_caseD_87db:
                    addInstWord2cMapped = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bc79c_caseD_87dc:
                    addInstWord2cMapped = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bc79c_caseD_87de:
                    addInstWord2cMapped = 0x87df;
                    break;
                  case 0x87df:
switchD_000bc79c_caseD_87df:
                    addInstWord2cMapped = 0x87de;
                  }
                  break;
                case 0x87da:
                  addInstWord2cMapped = mulInst[0xb];
                  switch(addInstWord2cMapped) {
                  case 0x87d5:
                    goto switchD_000bc79c_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc79c_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc79c_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc79c_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc79c_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc79c_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc79c_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc79c_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc79c_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc79c_caseD_87df;
                  }
                  break;
                case 0x87db:
                  addInstWord2cMapped = mulInst[0xc];
                  switch(addInstWord2cMapped) {
                  case 0x87d5:
                    goto switchD_000bc79c_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc79c_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc79c_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc79c_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc79c_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc79c_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc79c_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc79c_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc79c_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc79c_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  addInstWord2cMapped = mulInst[0xd];
                  switch(addInstWord2cMapped) {
                  case 0x87d5:
                    goto switchD_000bc79c_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc79c_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc79c_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc79c_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc79c_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc79c_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc79c_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc79c_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc79c_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc79c_caseD_87df;
                  }
                }
                addInstWord30Mapped = addInst[0xc];
                addInst[0xb] = addInstWord2cMapped;
                switch(addInstWord30Mapped) {
                case 0x87d5:
                  addInstWord30Mapped = *srcRecordPtr;
                  break;
                case 0x87d6:
                  addInstWord30Mapped = mulInst[0xb];
                  break;
                case 0x87d7:
                  addInstWord30Mapped = mulInst[0xc];
                  break;
                case 0x87d8:
                  addInstWord30Mapped = mulInst[0xd];
                  break;
                case 0x87d9:
                  addInstWord30Mapped = *srcRecordPtr;
                  switch(addInstWord30Mapped) {
                  case 0x87d5:
switchD_000bc9f4_caseD_87d5:
                    addInstWord30Mapped = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bc9f4_caseD_87d6:
                    addInstWord30Mapped = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bc9f4_caseD_87d7:
                    addInstWord30Mapped = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bc9f4_caseD_87d8:
                    addInstWord30Mapped = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bc9f4_caseD_87d9:
                    addInstWord30Mapped = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bc9f4_caseD_87da:
                    addInstWord30Mapped = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bc9f4_caseD_87db:
                    addInstWord30Mapped = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bc9f4_caseD_87dc:
                    addInstWord30Mapped = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bc9f4_caseD_87de:
                    addInstWord30Mapped = 0x87df;
                    break;
                  case 0x87df:
switchD_000bc9f4_caseD_87df:
                    addInstWord30Mapped = 0x87de;
                  }
                  break;
                case 0x87da:
                  addInstWord30Mapped = mulInst[0xb];
                  switch(addInstWord30Mapped) {
                  case 0x87d5:
                    goto switchD_000bc9f4_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc9f4_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc9f4_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc9f4_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc9f4_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc9f4_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc9f4_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc9f4_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc9f4_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc9f4_caseD_87df;
                  }
                  break;
                case 0x87db:
                  addInstWord30Mapped = mulInst[0xc];
                  switch(addInstWord30Mapped) {
                  case 0x87d5:
                    goto switchD_000bc9f4_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc9f4_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc9f4_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc9f4_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc9f4_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc9f4_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc9f4_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc9f4_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc9f4_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc9f4_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  addInstWord30Mapped = mulInst[0xd];
                  switch(addInstWord30Mapped) {
                  case 0x87d5:
                    goto switchD_000bc9f4_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bc9f4_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bc9f4_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bc9f4_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bc9f4_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bc9f4_caseD_87da;
                  case 0x87db:
                    goto switchD_000bc9f4_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bc9f4_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bc9f4_caseD_87de;
                  case 0x87df:
                    goto switchD_000bc9f4_caseD_87df;
                  }
                }
                addInstWord34Mapped = addInst[0xd];
                addInst[0xc] = addInstWord30Mapped;
                switch(addInstWord34Mapped) {
                case 0x87d5:
                  addInstWord34Mapped = *srcRecordPtr;
                  break;
                case 0x87d6:
                  addInstWord34Mapped = mulInst[0xb];
                  break;
                case 0x87d7:
                  addInstWord34Mapped = mulInst[0xc];
                  break;
                case 0x87d8:
                  addInstWord34Mapped = mulInst[0xd];
                  break;
                case 0x87d9:
                  addInstWord34Mapped = *srcRecordPtr;
                  switch(addInstWord34Mapped) {
                  case 0x87d5:
switchD_000bcc4c_caseD_87d5:
                    addInstWord34Mapped = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bcc4c_caseD_87d6:
                    addInstWord34Mapped = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bcc4c_caseD_87d7:
                    addInstWord34Mapped = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bcc4c_caseD_87d8:
                    addInstWord34Mapped = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bcc4c_caseD_87d9:
                    addInstWord34Mapped = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bcc4c_caseD_87da:
                    addInstWord34Mapped = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bcc4c_caseD_87db:
                    addInstWord34Mapped = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bcc4c_caseD_87dc:
                    addInstWord34Mapped = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bcc4c_caseD_87de:
                    addInstWord34Mapped = 0x87df;
                    break;
                  case 0x87df:
switchD_000bcc4c_caseD_87df:
                    addInstWord34Mapped = 0x87de;
                  }
                  break;
                case 0x87da:
                  addInstWord34Mapped = mulInst[0xb];
                  switch(addInstWord34Mapped) {
                  case 0x87d5:
                    goto switchD_000bcc4c_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bcc4c_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bcc4c_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bcc4c_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bcc4c_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bcc4c_caseD_87da;
                  case 0x87db:
                    goto switchD_000bcc4c_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bcc4c_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bcc4c_caseD_87de;
                  case 0x87df:
                    goto switchD_000bcc4c_caseD_87df;
                  }
                  break;
                case 0x87db:
                  addInstWord34Mapped = mulInst[0xc];
                  switch(addInstWord34Mapped) {
                  case 0x87d5:
                    goto switchD_000bcc4c_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bcc4c_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bcc4c_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bcc4c_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bcc4c_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bcc4c_caseD_87da;
                  case 0x87db:
                    goto switchD_000bcc4c_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bcc4c_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bcc4c_caseD_87de;
                  case 0x87df:
                    goto switchD_000bcc4c_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  addInstWord34Mapped = mulInst[0xd];
                  switch(addInstWord34Mapped) {
                  case 0x87d5:
                    goto switchD_000bcc4c_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bcc4c_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bcc4c_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bcc4c_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bcc4c_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bcc4c_caseD_87da;
                  case 0x87db:
                    goto switchD_000bcc4c_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bcc4c_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bcc4c_caseD_87de;
                  case 0x87df:
                    goto switchD_000bcc4c_caseD_87df;
                  }
                }
                operandWord = *operandRecordPtr;
                addInst[0xd] = addInstWord34Mapped;
                srcRecordPtr = mulInst + 0x11;
                switch(operandWord) {
                case 0x87d5:
                  operandWord = *srcRecordPtr;
                  break;
                case 0x87d6:
                  operandWord = mulInst[0x12];
                  break;
                case 0x87d7:
                  operandWord = mulInst[0x13];
                  break;
                case 0x87d8:
                  operandWord = mulInst[0x14];
                  break;
                case 0x87d9:
                  operandWord = *srcRecordPtr;
                  switch(operandWord) {
                  case 0x87d5:
switchD_000bcea8_caseD_87d5:
                    operandWord = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bcea8_caseD_87d6:
                    operandWord = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bcea8_caseD_87d7:
                    operandWord = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bcea8_caseD_87d8:
                    operandWord = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bcea8_caseD_87d9:
                    operandWord = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bcea8_caseD_87da:
                    operandWord = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bcea8_caseD_87db:
                    operandWord = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bcea8_caseD_87dc:
                    operandWord = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bcea8_caseD_87de:
                    operandWord = 0x87df;
                    break;
                  case 0x87df:
switchD_000bcea8_caseD_87df:
                    operandWord = 0x87de;
                  }
                  break;
                case 0x87da:
                  operandWord = mulInst[0x12];
                  switch(operandWord) {
                  case 0x87d5:
                    goto switchD_000bcea8_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bcea8_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bcea8_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bcea8_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bcea8_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bcea8_caseD_87da;
                  case 0x87db:
                    goto switchD_000bcea8_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bcea8_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bcea8_caseD_87de;
                  case 0x87df:
                    goto switchD_000bcea8_caseD_87df;
                  }
                  break;
                case 0x87db:
                  operandWord = mulInst[0x13];
                  switch(operandWord) {
                  case 0x87d5:
                    goto switchD_000bcea8_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bcea8_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bcea8_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bcea8_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bcea8_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bcea8_caseD_87da;
                  case 0x87db:
                    goto switchD_000bcea8_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bcea8_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bcea8_caseD_87de;
                  case 0x87df:
                    goto switchD_000bcea8_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  operandWord = mulInst[0x14];
                  switch(operandWord) {
                  case 0x87d5:
                    goto switchD_000bcea8_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bcea8_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bcea8_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bcea8_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bcea8_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bcea8_caseD_87da;
                  case 0x87db:
                    goto switchD_000bcea8_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bcea8_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bcea8_caseD_87de;
                  case 0x87df:
                    goto switchD_000bcea8_caseD_87df;
                  }
                }
                addInstWord48Mapped = addInst[0x12];
                *operandRecordPtr = operandWord;
                switch(addInstWord48Mapped) {
                case 0x87d5:
                  addInstWord48Mapped = *srcRecordPtr;
                  break;
                case 0x87d6:
                  addInstWord48Mapped = mulInst[0x12];
                  break;
                case 0x87d7:
                  addInstWord48Mapped = mulInst[0x13];
                  break;
                case 0x87d8:
                  addInstWord48Mapped = mulInst[0x14];
                  break;
                case 0x87d9:
                  addInstWord48Mapped = *srcRecordPtr;
                  switch(addInstWord48Mapped) {
                  case 0x87d5:
switchD_000bd100_caseD_87d5:
                    addInstWord48Mapped = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bd100_caseD_87d6:
                    addInstWord48Mapped = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bd100_caseD_87d7:
                    addInstWord48Mapped = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bd100_caseD_87d8:
                    addInstWord48Mapped = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bd100_caseD_87d9:
                    addInstWord48Mapped = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bd100_caseD_87da:
                    addInstWord48Mapped = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bd100_caseD_87db:
                    addInstWord48Mapped = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bd100_caseD_87dc:
                    addInstWord48Mapped = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bd100_caseD_87de:
                    addInstWord48Mapped = 0x87df;
                    break;
                  case 0x87df:
switchD_000bd100_caseD_87df:
                    addInstWord48Mapped = 0x87de;
                  }
                  break;
                case 0x87da:
                  addInstWord48Mapped = mulInst[0x12];
                  switch(addInstWord48Mapped) {
                  case 0x87d5:
                    goto switchD_000bd100_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd100_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd100_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd100_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd100_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd100_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd100_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd100_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd100_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd100_caseD_87df;
                  }
                  break;
                case 0x87db:
                  addInstWord48Mapped = mulInst[0x13];
                  switch(addInstWord48Mapped) {
                  case 0x87d5:
                    goto switchD_000bd100_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd100_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd100_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd100_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd100_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd100_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd100_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd100_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd100_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd100_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  addInstWord48Mapped = mulInst[0x14];
                  switch(addInstWord48Mapped) {
                  case 0x87d5:
                    goto switchD_000bd100_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd100_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd100_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd100_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd100_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd100_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd100_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd100_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd100_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd100_caseD_87df;
                  }
                }
                addInstWord4cMapped = addInst[0x13];
                addInst[0x12] = addInstWord48Mapped;
                switch(addInstWord4cMapped) {
                case 0x87d5:
                  addInstWord4cMapped = *srcRecordPtr;
                  break;
                case 0x87d6:
                  addInstWord4cMapped = mulInst[0x12];
                  break;
                case 0x87d7:
                  addInstWord4cMapped = mulInst[0x13];
                  break;
                case 0x87d8:
                  addInstWord4cMapped = mulInst[0x14];
                  break;
                case 0x87d9:
                  addInstWord4cMapped = *srcRecordPtr;
                  switch(addInstWord4cMapped) {
                  case 0x87d5:
switchD_000bd358_caseD_87d5:
                    addInstWord4cMapped = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bd358_caseD_87d6:
                    addInstWord4cMapped = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bd358_caseD_87d7:
                    addInstWord4cMapped = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bd358_caseD_87d8:
                    addInstWord4cMapped = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bd358_caseD_87d9:
                    addInstWord4cMapped = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bd358_caseD_87da:
                    addInstWord4cMapped = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bd358_caseD_87db:
                    addInstWord4cMapped = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bd358_caseD_87dc:
                    addInstWord4cMapped = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bd358_caseD_87de:
                    addInstWord4cMapped = 0x87df;
                    break;
                  case 0x87df:
switchD_000bd358_caseD_87df:
                    addInstWord4cMapped = 0x87de;
                  }
                  break;
                case 0x87da:
                  addInstWord4cMapped = mulInst[0x12];
                  switch(addInstWord4cMapped) {
                  case 0x87d5:
                    goto switchD_000bd358_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd358_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd358_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd358_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd358_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd358_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd358_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd358_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd358_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd358_caseD_87df;
                  }
                  break;
                case 0x87db:
                  addInstWord4cMapped = mulInst[0x13];
                  switch(addInstWord4cMapped) {
                  case 0x87d5:
                    goto switchD_000bd358_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd358_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd358_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd358_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd358_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd358_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd358_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd358_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd358_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd358_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  addInstWord4cMapped = mulInst[0x14];
                  switch(addInstWord4cMapped) {
                  case 0x87d5:
                    goto switchD_000bd358_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd358_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd358_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd358_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd358_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd358_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd358_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd358_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd358_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd358_caseD_87df;
                  }
                }
                addInstWord50Mapped = addInst[0x14];
                addInst[0x13] = addInstWord4cMapped;
                switch(addInstWord50Mapped) {
                case 0x87d5:
                  addInstWord50Mapped = *srcRecordPtr;
                  break;
                case 0x87d6:
                  addInstWord50Mapped = mulInst[0x12];
                  break;
                case 0x87d7:
                  addInstWord50Mapped = mulInst[0x13];
                  break;
                case 0x87d8:
                  addInstWord50Mapped = mulInst[0x14];
                  break;
                case 0x87d9:
                  addInstWord50Mapped = *srcRecordPtr;
                  switch(addInstWord50Mapped) {
                  case 0x87d5:
switchD_000bd5b0_caseD_87d5:
                    addInstWord50Mapped = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bd5b0_caseD_87d6:
                    addInstWord50Mapped = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bd5b0_caseD_87d7:
                    addInstWord50Mapped = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bd5b0_caseD_87d8:
                    addInstWord50Mapped = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bd5b0_caseD_87d9:
                    addInstWord50Mapped = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bd5b0_caseD_87da:
                    addInstWord50Mapped = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bd5b0_caseD_87db:
                    addInstWord50Mapped = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bd5b0_caseD_87dc:
                    addInstWord50Mapped = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bd5b0_caseD_87de:
                    addInstWord50Mapped = 0x87df;
                    break;
                  case 0x87df:
switchD_000bd5b0_caseD_87df:
                    addInstWord50Mapped = 0x87de;
                  }
                  break;
                case 0x87da:
                  addInstWord50Mapped = mulInst[0x12];
                  switch(addInstWord50Mapped) {
                  case 0x87d5:
                    goto switchD_000bd5b0_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd5b0_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd5b0_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd5b0_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd5b0_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd5b0_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd5b0_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd5b0_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd5b0_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd5b0_caseD_87df;
                  }
                  break;
                case 0x87db:
                  addInstWord50Mapped = mulInst[0x13];
                  switch(addInstWord50Mapped) {
                  case 0x87d5:
                    goto switchD_000bd5b0_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd5b0_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd5b0_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd5b0_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd5b0_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd5b0_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd5b0_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd5b0_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd5b0_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd5b0_caseD_87df;
                  }
                  break;
                case 0x87dc:
                  addInstWord50Mapped = mulInst[0x14];
                  switch(addInstWord50Mapped) {
                  case 0x87d5:
                    goto switchD_000bd5b0_caseD_87d5;
                  case 0x87d6:
                    goto switchD_000bd5b0_caseD_87d6;
                  case 0x87d7:
                    goto switchD_000bd5b0_caseD_87d7;
                  case 0x87d8:
                    goto switchD_000bd5b0_caseD_87d8;
                  case 0x87d9:
                    goto switchD_000bd5b0_caseD_87d9;
                  case 0x87da:
                    goto switchD_000bd5b0_caseD_87da;
                  case 0x87db:
                    goto switchD_000bd5b0_caseD_87db;
                  case 0x87dc:
                    goto switchD_000bd5b0_caseD_87dc;
                  case 0x87de:
                    goto switchD_000bd5b0_caseD_87de;
                  case 0x87df:
                    goto switchD_000bd5b0_caseD_87df;
                  }
                }
                addInst[0x14] = addInstWord50Mapped;
                addInstWord50_3 = addInst[0x14];
                addInstWord28 = addInst[10];
                addInstWord2c = addInst[0xb];
                addInstWord30 = addInst[0xc];
                addInstWord34_2 = addInst[0xd];
                addInstWord44_3 = addInst[0x11];
                addInstWord4c = addInst[0x13];
                mulInst[0x12] = addInst[0x12];
                mulInst[0x14] = addInstWord50_3;
                mulInst[10] = addInstWord28;
                mulInst[0xb] = addInstWord2c;
                mulInst[0xc] = addInstWord30;
                mulInst[0xd] = addInstWord34_2;
                mulInst[0x11] = addInstWord44_3;
                mulInst[0x13] = addInstWord4c;
                instCount = *(int *)(shader + 0x14) - 1;
                *(uint *)(shader + 0x14) = instCount;
                shiftIndex = addSearchIndex;
                if (addSearchIndex < instCount) {
                  do {
                    shiftIndex = shiftIndex + 1;
                    shiftDst = addInstOffset + *(int *)(shader + 0x18);
                    addInstOffset = addInstOffset + 0x74;
                    _memcpy(shiftDst,shiftDst + 0x74,0x74);
                    instCount = *(uint *)(shader + 0x14);
                  } while (shiftIndex < instCount);
                }
              }
LAB_000bd6dc:
              addSearchIndex = addSearchIndex + 1;
              canContinue = true;
            }
            else {
LAB_000ba8a8:
              canContinue = true;
              afterAddIndex = addSearchIndex + 1;
              if (afterAddIndex < instCount) {
                remainingLater = instCount - afterAddIndex;
                laterSrcSlot = (int *)(instArray + afterAddIndex * 0x74 + 0x20);
                do {
                  if (((*laterSrcSlot == 2) && (laterSrcSlot[1] == shaderWord20)) ||
                     (((laterSrcSlot[7] == 2 && (laterSrcSlot[8] == shaderWord20)) ||
                      ((laterSrcSlot[0xe] == 2 && (laterSrcSlot[0xf] == shaderWord20)))))) {
                    canContinue = false;
                  }
                  laterSrcSlot = laterSrcSlot + 0x1d;
                  remainingLater = remainingLater + -1;
                } while (remainingLater != 0);
                if (!canContinue) {
                  if (remainingInsts < addSearchIndex) goto LAB_000ba754;
                  goto LAB_000bc018;
                }
              }
              *addInst = 0x8788;
              if (addInst[9] == shaderWord20) {
                addInstWord28Mapped = addInst[10];
                addInst[0x16] = wantedKind;
                addInst[0x17] = addInst[0x10];
                addInst[0x18] = addInst[0x11];
                addInst[0x19] = addInst[0x12];
                addInst[0x1a] = addInst[0x13];
                addInst[0x1b] = addInst[0x14];
                addInst[0x1c] = addInst[0x15];
              }
              else {
                addInst[0x18] = addInst[10];
                addInstWord28Mapped = addInst[0x11];
                addInst[0x16] = instKind;
                addInst[0x17] = addInst[9];
                addInst[0x19] = addInst[0xb];
                addInst[0x1a] = addInst[0xc];
                addInst[0x1b] = addInst[0xd];
                addInst[0x1c] = addInst[0xe];
                addInst[0xb] = addInst[0x12];
                addInst[0xc] = addInst[0x13];
                addInst[0xd] = addInst[0x14];
                addInst[10] = addInstWord28Mapped;
              }
              operandRecordPtr = addInst + 0x11;
              switch(addInstWord28Mapped) {
              case 0x87d9:
                addInstWord28Mapped = 0x87d5;
                break;
              case 0x87da:
                addInstWord28Mapped = 0x87d6;
                break;
              case 0x87db:
                addInstWord28Mapped = 0x87d7;
                break;
              case 0x87dc:
                addInstWord28Mapped = 0x87d8;
                break;
              case 0x87df:
                addInstWord28Mapped = 0x87de;
              }
              addInstWord2cMapped = addInst[0xb];
              *operandRecordPtr = addInstWord28Mapped;
              switch(addInstWord2cMapped) {
              case 0x87d9:
                addInstWord2cMapped = 0x87d5;
                break;
              case 0x87da:
                addInstWord2cMapped = 0x87d6;
                break;
              case 0x87db:
                addInstWord2cMapped = 0x87d7;
                break;
              case 0x87dc:
                addInstWord2cMapped = 0x87d8;
                break;
              case 0x87df:
                addInstWord2cMapped = 0x87de;
              }
              addInstWord30Mapped = addInst[0xc];
              addInst[0x12] = addInstWord2cMapped;
              switch(addInstWord30Mapped) {
              case 0x87d9:
                addInstWord30Mapped = 0x87d5;
                break;
              case 0x87da:
                addInstWord30Mapped = 0x87d6;
                break;
              case 0x87db:
                addInstWord30Mapped = 0x87d7;
                break;
              case 0x87dc:
                addInstWord30Mapped = 0x87d8;
                break;
              case 0x87df:
                addInstWord30Mapped = 0x87de;
              }
              addInstWord34Mapped = addInst[0xd];
              addInst[0x13] = addInstWord30Mapped;
              switch(addInstWord34Mapped) {
              case 0x87d9:
                addInstWord34Mapped = 0x87d5;
                break;
              case 0x87da:
                addInstWord34Mapped = 0x87d6;
                break;
              case 0x87db:
                addInstWord34Mapped = 0x87d7;
                break;
              case 0x87dc:
                addInstWord34Mapped = 0x87d8;
                break;
              case 0x87df:
                addInstWord34Mapped = 0x87de;
              }
              addInst[0x14] = addInstWord34Mapped;
              srcRecordPtr = mulInst + 10;
              addInst[9] = mulInst[9];
              addInstWord28Mapped = addInst[10];
              switch(addInstWord28Mapped) {
              case 0x87d5:
                addInstWord28Mapped = *srcRecordPtr;
                break;
              case 0x87d6:
                addInstWord28Mapped = mulInst[0xb];
                break;
              case 0x87d7:
                addInstWord28Mapped = mulInst[0xc];
                break;
              case 0x87d8:
                addInstWord28Mapped = mulInst[0xd];
                break;
              case 0x87d9:
                addInstWord28Mapped = *srcRecordPtr;
                switch(addInstWord28Mapped) {
                case 0x87d5:
switchD_000badac_caseD_87d5:
                  addInstWord28Mapped = 0x87d9;
                  break;
                case 0x87d6:
switchD_000badac_caseD_87d6:
                  addInstWord28Mapped = 0x87da;
                  break;
                case 0x87d7:
switchD_000badac_caseD_87d7:
                  addInstWord28Mapped = 0x87db;
                  break;
                case 0x87d8:
switchD_000badac_caseD_87d8:
                  addInstWord28Mapped = 0x87dc;
                  break;
                case 0x87d9:
switchD_000badac_caseD_87d9:
                  addInstWord28Mapped = 0x87d5;
                  break;
                case 0x87da:
switchD_000badac_caseD_87da:
                  addInstWord28Mapped = 0x87d6;
                  break;
                case 0x87db:
switchD_000badac_caseD_87db:
                  addInstWord28Mapped = 0x87d7;
                  break;
                case 0x87dc:
switchD_000badac_caseD_87dc:
                  addInstWord28Mapped = 0x87d8;
                  break;
                case 0x87de:
switchD_000badac_caseD_87de:
                  addInstWord28Mapped = 0x87df;
                  break;
                case 0x87df:
switchD_000badac_caseD_87df:
                  addInstWord28Mapped = 0x87de;
                }
                break;
              case 0x87da:
                addInstWord28Mapped = mulInst[0xb];
                switch(addInstWord28Mapped) {
                case 0x87d5:
                  goto switchD_000badac_caseD_87d5;
                case 0x87d6:
                  goto switchD_000badac_caseD_87d6;
                case 0x87d7:
                  goto switchD_000badac_caseD_87d7;
                case 0x87d8:
                  goto switchD_000badac_caseD_87d8;
                case 0x87d9:
                  goto switchD_000badac_caseD_87d9;
                case 0x87da:
                  goto switchD_000badac_caseD_87da;
                case 0x87db:
                  goto switchD_000badac_caseD_87db;
                case 0x87dc:
                  goto switchD_000badac_caseD_87dc;
                case 0x87de:
                  goto switchD_000badac_caseD_87de;
                case 0x87df:
                  goto switchD_000badac_caseD_87df;
                }
                break;
              case 0x87db:
                addInstWord28Mapped = mulInst[0xc];
                switch(addInstWord28Mapped) {
                case 0x87d5:
                  goto switchD_000badac_caseD_87d5;
                case 0x87d6:
                  goto switchD_000badac_caseD_87d6;
                case 0x87d7:
                  goto switchD_000badac_caseD_87d7;
                case 0x87d8:
                  goto switchD_000badac_caseD_87d8;
                case 0x87d9:
                  goto switchD_000badac_caseD_87d9;
                case 0x87da:
                  goto switchD_000badac_caseD_87da;
                case 0x87db:
                  goto switchD_000badac_caseD_87db;
                case 0x87dc:
                  goto switchD_000badac_caseD_87dc;
                case 0x87de:
                  goto switchD_000badac_caseD_87de;
                case 0x87df:
                  goto switchD_000badac_caseD_87df;
                }
                break;
              case 0x87dc:
                addInstWord28Mapped = mulInst[0xd];
                switch(addInstWord28Mapped) {
                case 0x87d5:
                  goto switchD_000badac_caseD_87d5;
                case 0x87d6:
                  goto switchD_000badac_caseD_87d6;
                case 0x87d7:
                  goto switchD_000badac_caseD_87d7;
                case 0x87d8:
                  goto switchD_000badac_caseD_87d8;
                case 0x87d9:
                  goto switchD_000badac_caseD_87d9;
                case 0x87da:
                  goto switchD_000badac_caseD_87da;
                case 0x87db:
                  goto switchD_000badac_caseD_87db;
                case 0x87dc:
                  goto switchD_000badac_caseD_87dc;
                case 0x87de:
                  goto switchD_000badac_caseD_87de;
                case 0x87df:
                  goto switchD_000badac_caseD_87df;
                }
              }
              addInstWord2cMapped = addInst[0xb];
              addInst[10] = addInstWord28Mapped;
              switch(addInstWord2cMapped) {
              case 0x87d5:
                addInstWord2cMapped = *srcRecordPtr;
                break;
              case 0x87d6:
                addInstWord2cMapped = mulInst[0xb];
                break;
              case 0x87d7:
                addInstWord2cMapped = mulInst[0xc];
                break;
              case 0x87d8:
                addInstWord2cMapped = mulInst[0xd];
                break;
              case 0x87d9:
                addInstWord2cMapped = *srcRecordPtr;
                switch(addInstWord2cMapped) {
                case 0x87d5:
switchD_000bb004_caseD_87d5:
                  addInstWord2cMapped = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bb004_caseD_87d6:
                  addInstWord2cMapped = 0x87da;
                  break;
                case 0x87d7:
switchD_000bb004_caseD_87d7:
                  addInstWord2cMapped = 0x87db;
                  break;
                case 0x87d8:
switchD_000bb004_caseD_87d8:
                  addInstWord2cMapped = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bb004_caseD_87d9:
                  addInstWord2cMapped = 0x87d5;
                  break;
                case 0x87da:
switchD_000bb004_caseD_87da:
                  addInstWord2cMapped = 0x87d6;
                  break;
                case 0x87db:
switchD_000bb004_caseD_87db:
                  addInstWord2cMapped = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bb004_caseD_87dc:
                  addInstWord2cMapped = 0x87d8;
                  break;
                case 0x87de:
switchD_000bb004_caseD_87de:
                  addInstWord2cMapped = 0x87df;
                  break;
                case 0x87df:
switchD_000bb004_caseD_87df:
                  addInstWord2cMapped = 0x87de;
                }
                break;
              case 0x87da:
                addInstWord2cMapped = mulInst[0xb];
                switch(addInstWord2cMapped) {
                case 0x87d5:
                  goto switchD_000bb004_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb004_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb004_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb004_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb004_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb004_caseD_87da;
                case 0x87db:
                  goto switchD_000bb004_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb004_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb004_caseD_87de;
                case 0x87df:
                  goto switchD_000bb004_caseD_87df;
                }
                break;
              case 0x87db:
                addInstWord2cMapped = mulInst[0xc];
                switch(addInstWord2cMapped) {
                case 0x87d5:
                  goto switchD_000bb004_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb004_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb004_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb004_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb004_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb004_caseD_87da;
                case 0x87db:
                  goto switchD_000bb004_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb004_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb004_caseD_87de;
                case 0x87df:
                  goto switchD_000bb004_caseD_87df;
                }
                break;
              case 0x87dc:
                addInstWord2cMapped = mulInst[0xd];
                switch(addInstWord2cMapped) {
                case 0x87d5:
                  goto switchD_000bb004_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb004_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb004_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb004_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb004_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb004_caseD_87da;
                case 0x87db:
                  goto switchD_000bb004_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb004_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb004_caseD_87de;
                case 0x87df:
                  goto switchD_000bb004_caseD_87df;
                }
              }
              addInstWord30Mapped = addInst[0xc];
              addInst[0xb] = addInstWord2cMapped;
              switch(addInstWord30Mapped) {
              case 0x87d5:
                addInstWord30Mapped = *srcRecordPtr;
                break;
              case 0x87d6:
                addInstWord30Mapped = mulInst[0xb];
                break;
              case 0x87d7:
                addInstWord30Mapped = mulInst[0xc];
                break;
              case 0x87d8:
                addInstWord30Mapped = mulInst[0xd];
                break;
              case 0x87d9:
                addInstWord30Mapped = *srcRecordPtr;
                switch(addInstWord30Mapped) {
                case 0x87d5:
switchD_000bb25c_caseD_87d5:
                  addInstWord30Mapped = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bb25c_caseD_87d6:
                  addInstWord30Mapped = 0x87da;
                  break;
                case 0x87d7:
switchD_000bb25c_caseD_87d7:
                  addInstWord30Mapped = 0x87db;
                  break;
                case 0x87d8:
switchD_000bb25c_caseD_87d8:
                  addInstWord30Mapped = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bb25c_caseD_87d9:
                  addInstWord30Mapped = 0x87d5;
                  break;
                case 0x87da:
switchD_000bb25c_caseD_87da:
                  addInstWord30Mapped = 0x87d6;
                  break;
                case 0x87db:
switchD_000bb25c_caseD_87db:
                  addInstWord30Mapped = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bb25c_caseD_87dc:
                  addInstWord30Mapped = 0x87d8;
                  break;
                case 0x87de:
switchD_000bb25c_caseD_87de:
                  addInstWord30Mapped = 0x87df;
                  break;
                case 0x87df:
switchD_000bb25c_caseD_87df:
                  addInstWord30Mapped = 0x87de;
                }
                break;
              case 0x87da:
                addInstWord30Mapped = mulInst[0xb];
                switch(addInstWord30Mapped) {
                case 0x87d5:
                  goto switchD_000bb25c_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb25c_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb25c_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb25c_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb25c_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb25c_caseD_87da;
                case 0x87db:
                  goto switchD_000bb25c_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb25c_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb25c_caseD_87de;
                case 0x87df:
                  goto switchD_000bb25c_caseD_87df;
                }
                break;
              case 0x87db:
                addInstWord30Mapped = mulInst[0xc];
                switch(addInstWord30Mapped) {
                case 0x87d5:
                  goto switchD_000bb25c_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb25c_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb25c_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb25c_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb25c_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb25c_caseD_87da;
                case 0x87db:
                  goto switchD_000bb25c_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb25c_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb25c_caseD_87de;
                case 0x87df:
                  goto switchD_000bb25c_caseD_87df;
                }
                break;
              case 0x87dc:
                addInstWord30Mapped = mulInst[0xd];
                switch(addInstWord30Mapped) {
                case 0x87d5:
                  goto switchD_000bb25c_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb25c_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb25c_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb25c_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb25c_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb25c_caseD_87da;
                case 0x87db:
                  goto switchD_000bb25c_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb25c_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb25c_caseD_87de;
                case 0x87df:
                  goto switchD_000bb25c_caseD_87df;
                }
              }
              addInstWord34Mapped = addInst[0xd];
              addInst[0xc] = addInstWord30Mapped;
              switch(addInstWord34Mapped) {
              case 0x87d5:
                addInstWord34Mapped = *srcRecordPtr;
                break;
              case 0x87d6:
                addInstWord34Mapped = mulInst[0xb];
                break;
              case 0x87d7:
                addInstWord34Mapped = mulInst[0xc];
                break;
              case 0x87d8:
                addInstWord34Mapped = mulInst[0xd];
                break;
              case 0x87d9:
                addInstWord34Mapped = *srcRecordPtr;
                switch(addInstWord34Mapped) {
                case 0x87d5:
switchD_000bb4b4_caseD_87d5:
                  addInstWord34Mapped = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bb4b4_caseD_87d6:
                  addInstWord34Mapped = 0x87da;
                  break;
                case 0x87d7:
switchD_000bb4b4_caseD_87d7:
                  addInstWord34Mapped = 0x87db;
                  break;
                case 0x87d8:
switchD_000bb4b4_caseD_87d8:
                  addInstWord34Mapped = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bb4b4_caseD_87d9:
                  addInstWord34Mapped = 0x87d5;
                  break;
                case 0x87da:
switchD_000bb4b4_caseD_87da:
                  addInstWord34Mapped = 0x87d6;
                  break;
                case 0x87db:
switchD_000bb4b4_caseD_87db:
                  addInstWord34Mapped = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bb4b4_caseD_87dc:
                  addInstWord34Mapped = 0x87d8;
                  break;
                case 0x87de:
switchD_000bb4b4_caseD_87de:
                  addInstWord34Mapped = 0x87df;
                  break;
                case 0x87df:
switchD_000bb4b4_caseD_87df:
                  addInstWord34Mapped = 0x87de;
                }
                break;
              case 0x87da:
                addInstWord34Mapped = mulInst[0xb];
                switch(addInstWord34Mapped) {
                case 0x87d5:
                  goto switchD_000bb4b4_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb4b4_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb4b4_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb4b4_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb4b4_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb4b4_caseD_87da;
                case 0x87db:
                  goto switchD_000bb4b4_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb4b4_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb4b4_caseD_87de;
                case 0x87df:
                  goto switchD_000bb4b4_caseD_87df;
                }
                break;
              case 0x87db:
                addInstWord34Mapped = mulInst[0xc];
                switch(addInstWord34Mapped) {
                case 0x87d5:
                  goto switchD_000bb4b4_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb4b4_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb4b4_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb4b4_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb4b4_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb4b4_caseD_87da;
                case 0x87db:
                  goto switchD_000bb4b4_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb4b4_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb4b4_caseD_87de;
                case 0x87df:
                  goto switchD_000bb4b4_caseD_87df;
                }
                break;
              case 0x87dc:
                addInstWord34Mapped = mulInst[0xd];
                switch(addInstWord34Mapped) {
                case 0x87d5:
                  goto switchD_000bb4b4_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb4b4_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb4b4_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb4b4_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb4b4_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb4b4_caseD_87da;
                case 0x87db:
                  goto switchD_000bb4b4_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb4b4_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb4b4_caseD_87de;
                case 0x87df:
                  goto switchD_000bb4b4_caseD_87df;
                }
              }
              addInst[0xd] = addInstWord34Mapped;
              srcRecordPtr = mulInst + 0x11;
              addInst[0x10] = mulInst[0x10];
              operandWord = *operandRecordPtr;
              switch(operandWord) {
              case 0x87d5:
                operandWord = *srcRecordPtr;
                break;
              case 0x87d6:
                operandWord = mulInst[0x12];
                break;
              case 0x87d7:
                operandWord = mulInst[0x13];
                break;
              case 0x87d8:
                operandWord = mulInst[0x14];
                break;
              case 0x87d9:
                operandWord = *srcRecordPtr;
                switch(operandWord) {
                case 0x87d5:
switchD_000bb718_caseD_87d5:
                  operandWord = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bb718_caseD_87d6:
                  operandWord = 0x87da;
                  break;
                case 0x87d7:
switchD_000bb718_caseD_87d7:
                  operandWord = 0x87db;
                  break;
                case 0x87d8:
switchD_000bb718_caseD_87d8:
                  operandWord = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bb718_caseD_87d9:
                  operandWord = 0x87d5;
                  break;
                case 0x87da:
switchD_000bb718_caseD_87da:
                  operandWord = 0x87d6;
                  break;
                case 0x87db:
switchD_000bb718_caseD_87db:
                  operandWord = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bb718_caseD_87dc:
                  operandWord = 0x87d8;
                  break;
                case 0x87de:
switchD_000bb718_caseD_87de:
                  operandWord = 0x87df;
                  break;
                case 0x87df:
switchD_000bb718_caseD_87df:
                  operandWord = 0x87de;
                }
                break;
              case 0x87da:
                operandWord = mulInst[0x12];
                switch(operandWord) {
                case 0x87d5:
                  goto switchD_000bb718_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb718_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb718_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb718_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb718_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb718_caseD_87da;
                case 0x87db:
                  goto switchD_000bb718_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb718_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb718_caseD_87de;
                case 0x87df:
                  goto switchD_000bb718_caseD_87df;
                }
                break;
              case 0x87db:
                operandWord = mulInst[0x13];
                switch(operandWord) {
                case 0x87d5:
                  goto switchD_000bb718_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb718_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb718_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb718_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb718_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb718_caseD_87da;
                case 0x87db:
                  goto switchD_000bb718_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb718_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb718_caseD_87de;
                case 0x87df:
                  goto switchD_000bb718_caseD_87df;
                }
                break;
              case 0x87dc:
                operandWord = mulInst[0x14];
                switch(operandWord) {
                case 0x87d5:
                  goto switchD_000bb718_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb718_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb718_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb718_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb718_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb718_caseD_87da;
                case 0x87db:
                  goto switchD_000bb718_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb718_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb718_caseD_87de;
                case 0x87df:
                  goto switchD_000bb718_caseD_87df;
                }
              }
              addInstWord48Mapped = addInst[0x12];
              *operandRecordPtr = operandWord;
              switch(addInstWord48Mapped) {
              case 0x87d5:
                addInstWord48Mapped = *srcRecordPtr;
                break;
              case 0x87d6:
                addInstWord48Mapped = mulInst[0x12];
                break;
              case 0x87d7:
                addInstWord48Mapped = mulInst[0x13];
                break;
              case 0x87d8:
                addInstWord48Mapped = mulInst[0x14];
                break;
              case 0x87d9:
                addInstWord48Mapped = *srcRecordPtr;
                switch(addInstWord48Mapped) {
                case 0x87d5:
switchD_000bb970_caseD_87d5:
                  addInstWord48Mapped = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bb970_caseD_87d6:
                  addInstWord48Mapped = 0x87da;
                  break;
                case 0x87d7:
switchD_000bb970_caseD_87d7:
                  addInstWord48Mapped = 0x87db;
                  break;
                case 0x87d8:
switchD_000bb970_caseD_87d8:
                  addInstWord48Mapped = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bb970_caseD_87d9:
                  addInstWord48Mapped = 0x87d5;
                  break;
                case 0x87da:
switchD_000bb970_caseD_87da:
                  addInstWord48Mapped = 0x87d6;
                  break;
                case 0x87db:
switchD_000bb970_caseD_87db:
                  addInstWord48Mapped = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bb970_caseD_87dc:
                  addInstWord48Mapped = 0x87d8;
                  break;
                case 0x87de:
switchD_000bb970_caseD_87de:
                  addInstWord48Mapped = 0x87df;
                  break;
                case 0x87df:
switchD_000bb970_caseD_87df:
                  addInstWord48Mapped = 0x87de;
                }
                break;
              case 0x87da:
                addInstWord48Mapped = mulInst[0x12];
                switch(addInstWord48Mapped) {
                case 0x87d5:
                  goto switchD_000bb970_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb970_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb970_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb970_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb970_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb970_caseD_87da;
                case 0x87db:
                  goto switchD_000bb970_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb970_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb970_caseD_87de;
                case 0x87df:
                  goto switchD_000bb970_caseD_87df;
                }
                break;
              case 0x87db:
                addInstWord48Mapped = mulInst[0x13];
                switch(addInstWord48Mapped) {
                case 0x87d5:
                  goto switchD_000bb970_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb970_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb970_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb970_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb970_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb970_caseD_87da;
                case 0x87db:
                  goto switchD_000bb970_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb970_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb970_caseD_87de;
                case 0x87df:
                  goto switchD_000bb970_caseD_87df;
                }
                break;
              case 0x87dc:
                addInstWord48Mapped = mulInst[0x14];
                switch(addInstWord48Mapped) {
                case 0x87d5:
                  goto switchD_000bb970_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bb970_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bb970_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bb970_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bb970_caseD_87d9;
                case 0x87da:
                  goto switchD_000bb970_caseD_87da;
                case 0x87db:
                  goto switchD_000bb970_caseD_87db;
                case 0x87dc:
                  goto switchD_000bb970_caseD_87dc;
                case 0x87de:
                  goto switchD_000bb970_caseD_87de;
                case 0x87df:
                  goto switchD_000bb970_caseD_87df;
                }
              }
              addInstWord4cMapped = addInst[0x13];
              addInst[0x12] = addInstWord48Mapped;
              switch(addInstWord4cMapped) {
              case 0x87d5:
                addInstWord4cMapped = *srcRecordPtr;
                break;
              case 0x87d6:
                addInstWord4cMapped = mulInst[0x12];
                break;
              case 0x87d7:
                addInstWord4cMapped = mulInst[0x13];
                break;
              case 0x87d8:
                addInstWord4cMapped = mulInst[0x14];
                break;
              case 0x87d9:
                addInstWord4cMapped = *srcRecordPtr;
                switch(addInstWord4cMapped) {
                case 0x87d5:
switchD_000bbbc8_caseD_87d5:
                  addInstWord4cMapped = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bbbc8_caseD_87d6:
                  addInstWord4cMapped = 0x87da;
                  break;
                case 0x87d7:
switchD_000bbbc8_caseD_87d7:
                  addInstWord4cMapped = 0x87db;
                  break;
                case 0x87d8:
switchD_000bbbc8_caseD_87d8:
                  addInstWord4cMapped = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bbbc8_caseD_87d9:
                  addInstWord4cMapped = 0x87d5;
                  break;
                case 0x87da:
switchD_000bbbc8_caseD_87da:
                  addInstWord4cMapped = 0x87d6;
                  break;
                case 0x87db:
switchD_000bbbc8_caseD_87db:
                  addInstWord4cMapped = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bbbc8_caseD_87dc:
                  addInstWord4cMapped = 0x87d8;
                  break;
                case 0x87de:
switchD_000bbbc8_caseD_87de:
                  addInstWord4cMapped = 0x87df;
                  break;
                case 0x87df:
switchD_000bbbc8_caseD_87df:
                  addInstWord4cMapped = 0x87de;
                }
                break;
              case 0x87da:
                addInstWord4cMapped = mulInst[0x12];
                switch(addInstWord4cMapped) {
                case 0x87d5:
                  goto switchD_000bbbc8_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bbbc8_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bbbc8_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bbbc8_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bbbc8_caseD_87d9;
                case 0x87da:
                  goto switchD_000bbbc8_caseD_87da;
                case 0x87db:
                  goto switchD_000bbbc8_caseD_87db;
                case 0x87dc:
                  goto switchD_000bbbc8_caseD_87dc;
                case 0x87de:
                  goto switchD_000bbbc8_caseD_87de;
                case 0x87df:
                  goto switchD_000bbbc8_caseD_87df;
                }
                break;
              case 0x87db:
                addInstWord4cMapped = mulInst[0x13];
                switch(addInstWord4cMapped) {
                case 0x87d5:
                  goto switchD_000bbbc8_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bbbc8_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bbbc8_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bbbc8_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bbbc8_caseD_87d9;
                case 0x87da:
                  goto switchD_000bbbc8_caseD_87da;
                case 0x87db:
                  goto switchD_000bbbc8_caseD_87db;
                case 0x87dc:
                  goto switchD_000bbbc8_caseD_87dc;
                case 0x87de:
                  goto switchD_000bbbc8_caseD_87de;
                case 0x87df:
                  goto switchD_000bbbc8_caseD_87df;
                }
                break;
              case 0x87dc:
                addInstWord4cMapped = mulInst[0x14];
                switch(addInstWord4cMapped) {
                case 0x87d5:
                  goto switchD_000bbbc8_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bbbc8_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bbbc8_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bbbc8_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bbbc8_caseD_87d9;
                case 0x87da:
                  goto switchD_000bbbc8_caseD_87da;
                case 0x87db:
                  goto switchD_000bbbc8_caseD_87db;
                case 0x87dc:
                  goto switchD_000bbbc8_caseD_87dc;
                case 0x87de:
                  goto switchD_000bbbc8_caseD_87de;
                case 0x87df:
                  goto switchD_000bbbc8_caseD_87df;
                }
              }
              addInstWord50Mapped = addInst[0x14];
              addInst[0x13] = addInstWord4cMapped;
              switch(addInstWord50Mapped) {
              case 0x87d5:
                addInstWord50Mapped = *srcRecordPtr;
                break;
              case 0x87d6:
                addInstWord50Mapped = mulInst[0x12];
                break;
              case 0x87d7:
                addInstWord50Mapped = mulInst[0x13];
                break;
              case 0x87d8:
                addInstWord50Mapped = mulInst[0x14];
                break;
              case 0x87d9:
                addInstWord50Mapped = *srcRecordPtr;
                switch(addInstWord50Mapped) {
                case 0x87d5:
switchD_000bbe20_caseD_87d5:
                  addInstWord50Mapped = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bbe20_caseD_87d6:
                  addInstWord50Mapped = 0x87da;
                  break;
                case 0x87d7:
switchD_000bbe20_caseD_87d7:
                  addInstWord50Mapped = 0x87db;
                  break;
                case 0x87d8:
switchD_000bbe20_caseD_87d8:
                  addInstWord50Mapped = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bbe20_caseD_87d9:
                  addInstWord50Mapped = 0x87d5;
                  break;
                case 0x87da:
switchD_000bbe20_caseD_87da:
                  addInstWord50Mapped = 0x87d6;
                  break;
                case 0x87db:
switchD_000bbe20_caseD_87db:
                  addInstWord50Mapped = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bbe20_caseD_87dc:
                  addInstWord50Mapped = 0x87d8;
                  break;
                case 0x87de:
switchD_000bbe20_caseD_87de:
                  addInstWord50Mapped = 0x87df;
                  break;
                case 0x87df:
switchD_000bbe20_caseD_87df:
                  addInstWord50Mapped = 0x87de;
                }
                break;
              case 0x87da:
                addInstWord50Mapped = mulInst[0x12];
                switch(addInstWord50Mapped) {
                case 0x87d5:
                  goto switchD_000bbe20_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bbe20_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bbe20_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bbe20_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bbe20_caseD_87d9;
                case 0x87da:
                  goto switchD_000bbe20_caseD_87da;
                case 0x87db:
                  goto switchD_000bbe20_caseD_87db;
                case 0x87dc:
                  goto switchD_000bbe20_caseD_87dc;
                case 0x87de:
                  goto switchD_000bbe20_caseD_87de;
                case 0x87df:
                  goto switchD_000bbe20_caseD_87df;
                }
                break;
              case 0x87db:
                addInstWord50Mapped = mulInst[0x13];
                switch(addInstWord50Mapped) {
                case 0x87d5:
                  goto switchD_000bbe20_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bbe20_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bbe20_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bbe20_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bbe20_caseD_87d9;
                case 0x87da:
                  goto switchD_000bbe20_caseD_87da;
                case 0x87db:
                  goto switchD_000bbe20_caseD_87db;
                case 0x87dc:
                  goto switchD_000bbe20_caseD_87dc;
                case 0x87de:
                  goto switchD_000bbe20_caseD_87de;
                case 0x87df:
                  goto switchD_000bbe20_caseD_87df;
                }
                break;
              case 0x87dc:
                addInstWord50Mapped = mulInst[0x14];
                switch(addInstWord50Mapped) {
                case 0x87d5:
                  goto switchD_000bbe20_caseD_87d5;
                case 0x87d6:
                  goto switchD_000bbe20_caseD_87d6;
                case 0x87d7:
                  goto switchD_000bbe20_caseD_87d7;
                case 0x87d8:
                  goto switchD_000bbe20_caseD_87d8;
                case 0x87d9:
                  goto switchD_000bbe20_caseD_87d9;
                case 0x87da:
                  goto switchD_000bbe20_caseD_87da;
                case 0x87db:
                  goto switchD_000bbe20_caseD_87db;
                case 0x87dc:
                  goto switchD_000bbe20_caseD_87dc;
                case 0x87de:
                  goto switchD_000bbe20_caseD_87de;
                case 0x87df:
                  goto switchD_000bbe20_caseD_87df;
                }
              }
              addInst[0x14] = addInstWord50Mapped;
              instCount = *(int *)(shader + 0x14) - 1;
              *(uint *)(shader + 0x14) = instCount;
              shiftOffset = mulOffset;
              mulScanStart = mulSearchIndex;
              if (mulSearchIndex < instCount) {
                do {
                  addSearchIndex = mulScanStart;
                  mulScanStart = addSearchIndex + 1;
                  shiftSrc = shiftOffset + *(int *)(shader + 0x18);
                  _memcpy(shiftSrc,shiftSrc + 0x74,0x74);
                  instCount = *(uint *)(shader + 0x14);
                  shiftOffset = shiftOffset + 0x74;
                } while (mulScanStart < instCount);
                addSearchIndex = addSearchIndex + 2;
                canContinue = true;
              }
              else {
                canContinue = true;
                addSearchIndex = remainingInsts;
              }
            }
          }
          else {
LAB_000ba7ec:
            canContinue = false;
            addSearchIndex = addSearchIndex + 1;
          }
          if ((instCount <= addSearchIndex) || (canContinue)) break;
          instArray = *(int *)(shader + 0x18);
        } while( true );
      }
      mulSearchIndex = mulSearchIndex + 1;
    } while (mulSearchIndex < instCount);
    if (instCount != 0) {
      matMulSearchIndex = 0;
      do {
        instArray = *(int *)(shader + 0x18);
        matMulInst = instArray + matMulSearchIndex * 0x74;
        if (((*(int *)(instArray + matMulSearchIndex * 0x74) == 0x8798) && (*(int *)(matMulInst + 4) == 2)) &&
           (*(int *)(matMulInst + 0x20) == 2)) {
          matrixSymbol = *(int *)(shader + 0x20) + *(int *)(matMulInst + 0x24) * 0x54;
          if ((*(char *)(matrixSymbol + 0x44) != '\0') && (*(int *)(matrixSymbol + 0x48) == 0xba6)) {
            followerIndex = matMulSearchIndex + 1;
            if (followerIndex < instCount) {
              followerCount = instCount - followerIndex;
              canContinue = true;
              fusedPartnerIndex = 0;
              laterSrc1Slot = (int *)(followerIndex * 0x74 + instArray + 0x3c);
              do {
                if ((*laterSrc1Slot == 2) && (laterSrc1Slot[1] == *(int *)(matMulInst + 8))) {
                  if ((((laterSrc1Slot[-0xf] == 0x8798) && (laterSrc1Slot[-7] == 2)) &&
                      (instKind = *(int *)(shader + 0x20) + laterSrc1Slot[-6] * 0x54,
                      *(char *)(instKind + 0x44) != '\0')) &&
                     ((*(int *)(instKind + 0x48) == 0xba7 && (fusedPartnerIndex == 0)))) {
                    notFused = false;
                    fusedPartnerIndex = followerIndex;
                  }
                  else {
LAB_000bd88c:
                    canContinue = false;
                    notFused = true;
                  }
                }
                else {
                  if (((laterSrc1Slot[-7] == 2) && (laterSrc1Slot[-6] == *(int *)(matMulInst + 8))) ||
                     ((laterSrc1Slot[7] == 2 && (laterSrc1Slot[8] == *(int *)(matMulInst + 8))))) goto LAB_000bd88c;
                  if ((laterSrc1Slot[-0xe] != 2) || (notFused = true, laterSrc1Slot[-0xd] != *(int *)(matMulInst + 8)))
                  {
                    notFused = false;
                  }
                }
                followerIndex = followerIndex + 1;
                followerCount = followerCount + -1;
              } while ((followerCount != 0) && (laterSrc1Slot = laterSrc1Slot + 0x1d, !notFused));
              if (!canContinue) goto LAB_000bd970;
              partnerOffset = fusedPartnerIndex * 0x74;
            }
            else {
              fusedPartnerIndex = 0;
              partnerOffset = 0;
            }
            instKind = *(int *)(shader + 0x2c);
            if (instKind == 0) {
              instKind = extvsAppendSymbol(iStack00000018,symbolTable,
                                    *(undefined4 *)(*(int *)(((unsigned char *)0x0000116c) + iStack00000018) + 0x18)
                                   );
              instArray = *(int *)(shader + 0x18);
              *(int *)(shader + 0x2c) = instKind;
            }
            partnerOffset = partnerOffset + instArray;
            *(int *)(matMulInst + 0x24) = instKind;
            partnerOffsetWord8 = *(undefined4 *)(partnerOffset + 8);
            partnerOffsetWordc = *(undefined4 *)(partnerOffset + 0xc);
            partnerOffsetWord10 = *(undefined4 *)(partnerOffset + 0x10);
            *(undefined4 *)(matMulInst + 4) = *(undefined4 *)(partnerOffset + 4);
            *(undefined4 *)(matMulInst + 8) = partnerOffsetWord8;
            *(undefined4 *)(matMulInst + 0xc) = partnerOffsetWordc;
            *(undefined4 *)(matMulInst + 0x10) = partnerOffsetWord10;
            partnerOffsetWord14 = *(undefined4 *)(partnerOffset + 0x14);
            partnerOffsetWord18 = *(undefined4 *)(partnerOffset + 0x18);
            *(undefined4 *)(matMulInst + 0x1c) = *(undefined4 *)(partnerOffset + 0x1c);
            *(undefined4 *)(matMulInst + 0x14) = partnerOffsetWord14;
            *(undefined4 *)(matMulInst + 0x18) = partnerOffsetWord18;
            instCount = *(int *)(shader + 0x14) - 1;
            *(uint *)(shader + 0x14) = instCount;
            if (fusedPartnerIndex < instCount) {
              shiftOffset = fusedPartnerIndex * 0x74;
              do {
                fusedPartnerIndex = fusedPartnerIndex + 1;
                shiftDstPtr = shiftOffset + *(int *)(shader + 0x18);
                shiftOffset = shiftOffset + 0x74;
                _memcpy(shiftDstPtr,shiftDstPtr + 0x74,0x74);
                instCount = *(uint *)(shader + 0x14);
              } while (fusedPartnerIndex < instCount);
            }
          }
        }
LAB_000bd970:
        matMulSearchIndex = matMulSearchIndex + 1;
      } while (matMulSearchIndex < instCount);
    }
  }
  return;
}

/* gld_emitLightingStatePacket @ 0xbd9a0 (160 bytes) */
void gld_emitLightingStatePacket(int glContext,undefined4 passArgR4,undefined4 passArgR5,undefined4 passArgR6,double fpPassThrough1)
{
  code *glContextPtr275c;
  int packetPtr;
  undefined4 *packetStart;
  undefined4 r4AfterCall;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  int a6;
  
  if ((*(uint *)(glContext + 0x44) & 0x100000) == 0) {
    packetStart = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
    *(undefined4 **)(0x00002748 + glContext + 4) = packetStart;
    *packetStart = 0x860;
    a6 = *(int *)(0x00002748 + glContext + 4);
    *(undefined4 *)(a6 + 4) = *(undefined4 *)(glContext + 0x1b78);
    packetPtr = *(int *)(0x00002748 + glContext + 4);
    glContextPtr275c = *(code **)(glContext + 0x275c);
    *(int *)(0x00002748 + glContext + 4) = packetPtr + 8;
    (*glContextPtr275c)(glContext,packetPtr + 8,passArgR5,passArgR6,staleArgR7,staleArgR8,a6);
    ffvpAnalyzeLightState(glContext);
    fpPassThrough1 = (double)ffvpBuildLightKey(glContext);
    passArgR4 = r4AfterCall;
  }
  ((void (*)())FUN_0004d620)(glContext,passArgR4,passArgR5,passArgR6,fpPassThrough1);
  return;
}

/* gld_updateTexCombinerState @ 0xbda40 (1016 bytes) */
int gld_updateTexCombinerState(glContext, unusedArgR4, dirtyBitsArg, scratchR6, dirtyWord3, dirtyWord1, unusedArgR9, dirtyWord4)
  int glContext;
  undefined4 unusedArgR4;
  undefined4 dirtyBitsArg;
  undefined4 scratchR6;
  undefined4 dirtyWord3;
  undefined4 dirtyWord1;
  undefined4 unusedArgR9;
  undefined4 dirtyWord4;
{
  uint combineBits26;
  int unitFlagsAddrInactive;
  int activeListOffset;
  uint texCombineStateWord;
  uint glContextWord44;
  byte glContextByte13b0;
  byte enabledUnitMask;
  ushort oldUnitFlags;
  short envSlot1Code;
  uint slotUses2402;
  bool unitDisabledByte;
  uint slotEnableBits;
  ushort disabledBit14;
  int ctxUnitCursor;
  uint loopIndex2;
  int unitEnvBlock;
  uint glContextWord8c;
  uint slotCodeBits;
  uint slotUsesSpecial;
  uint unitEnableBits;
  int unitFlagsAddr;
  int unitWordCursor;
  uint slotUsesSpecialSrc;
  int loopIndex;
  uint slot2Enabled;
  uint slot1Enabled;
  uint enabledUnitBits;
  int envBlockCursor;
  int unitByteCursor;
  uint unitsToScan;
  
  glContextWord44 = *(uint *)(glContext + 0x44);
  if (((((glContextWord44 & 0x2000) == 0) || ((*(byte *)(glContext + 0x2e) & 1) != 0)) ||
      ((*(uint *)(glContext + 0x38) & 0x8000) != 0)) || (*(short *)(glContext + 0x42) != 0)) {
    glContextByte13b0 = ((unsigned char *)0x000013b0)[glContext];
    unitWordCursor = glContext + 0x44;
    *(uint *)(glContext + 0x8c) = *(uint *)(glContext + 0x8c) & 0xf07fffff;
    *(uint *)(glContext + 0x1874) = *(uint *)(glContext + 0x1874) & 0xfdffffff;
    unitsToScan = (uint)*(byte *)(glContext + 0x2b);
    if ((uint)glContextByte13b0 < (uint)*(byte *)(glContext + 0x2b)) {
      unitsToScan = (uint)glContextByte13b0;
    }
    if ((glContextWord44 & 0x20000) == 0) {
      *(undefined1 *)(glContext + 0x1878) = 0;
      enabledUnitBits = 0;
    }
    else {
      if ((glContextWord44 & 0x2000) == 0) {
        enabledUnitMask = ((unsigned char *)0x00001135)[glContext];
      }
      else {
        enabledUnitMask = ((unsigned char *)0x000011d3)[glContext];
      }
      enabledUnitBits = (uint)enabledUnitMask;
      *(byte *)(glContext + 0x1878) = enabledUnitMask;
    }
    loopIndex = 0;
    if (unitsToScan != 0) {
      loopIndex2 = 0;
      ctxUnitCursor = glContext;
      envBlockCursor = glContext;
      unitByteCursor = glContext;
      while( true ) {
        slotEnableBits = *(uint *)(unitWordCursor + 4) & 0x1e0;
        if ((glContextWord44 & 0x20000) == 0) {
          unitEnableBits = *(uint *)(unitWordCursor + 4) & 0x1f;
        }
        else {
          unitEnableBits = enabledUnitBits & 1 << (loopIndex2 & 0x3f);
        }
        unitEnvBlock = glContext + 0x450 + loopIndex2 * 0xcc;
        if ((int)-unitEnableBits < 0) {
          unitFlagsAddr = loopIndex2 * 2 + glContext;
          unitDisabledByte = *(char *)(unitByteCursor + 0x2784) == '\0';
          *(uint *)(ctxUnitCursor + 0x150) = (uint)unitDisabledByte;
          disabledBit14 = (ushort)unitDisabledByte << 0xe;
          oldUnitFlags = *(ushort *)(unitFlagsAddr + 0x187c);
          *(ushort *)(unitFlagsAddr + 0x187c) = oldUnitFlags & 0xbfff | disabledBit14;
          if (slotEnableBits == 0) {
            *(ushort *)(unitFlagsAddr + 0x187c) = oldUnitFlags & 0x8003 | disabledBit14;
            texCombineStateWord = *(uint *)(glContext + 0x8c);
          }
          else {
            slot2Enabled = slotEnableBits >> 7 & 1;
            envSlot1Code = *(short *)(unitEnvBlock + 0x60);
            texCombineStateWord = slotEnableBits >> 5 & 1;
            slot1Enabled = slotEnableBits >> 6 & 1;
            if ((slot2Enabled == 0) || (slotUsesSpecialSrc = 1, 1 < (ushort)(*(short *)(unitEnvBlock + 0x84) + 0x7aefU))) {
              slotUsesSpecialSrc = 0;
            }
            slotCodeBits = 0;
            if (texCombineStateWord != 0) {
              slotCodeBits = *(uint *)(&DAT_001dbf70 +
                                (*(ushort *)(envBlockCursor + 0x48c) >> 2 & 4 |
                                *(ushort *)(envBlockCursor + 0x48c) & 3) * 4);
            }
            if (slot1Enabled != 0) {
              slotCodeBits = slotCodeBits | *(int *)(&DAT_001dbf70 +
                                        (*(ushort *)(envBlockCursor + 0x4b0) >> 2 & 4 |
                                        *(ushort *)(envBlockCursor + 0x4b0) & 3) * 4) << 3;
            }
            if (slot2Enabled != 0) {
              slotCodeBits = slotCodeBits | *(int *)(&DAT_001dbf70 +
                                        (*(ushort *)(envBlockCursor + 0x4d4) >> 2 & 4 |
                                        *(ushort *)(envBlockCursor + 0x4d4) & 3) * 4) << 6;
            }
            if (slotEnableBits >> 8 != 0) {
              slotCodeBits = slotCodeBits | *(int *)(&DAT_001dbf70 +
                                        (*(ushort *)(envBlockCursor + 0x4f8) >> 2 & 4 |
                                        *(ushort *)(envBlockCursor + 0x4f8) & 3) * 4) << 9;
            }
            unitFlagsAddr = loopIndex2 * 2 + glContext;
            slotUsesSpecialSrc = (((ushort)(*(short *)(unitEnvBlock + 0x3c) + 0x7aefU) < 2 || envSlot1Code == -0x7aee) ||
                     envSlot1Code == -0x7aef) | slotUsesSpecialSrc;
            slotUses2402 = (uint)(*(short *)(unitEnvBlock + 0x3c) == 0x2402 || envSlot1Code == 0x2402);
            slotUsesSpecial = slotUsesSpecialSrc | slotUses2402;
            *(ushort *)(unitFlagsAddr + 0x187c) =
                 *(ushort *)(unitFlagsAddr + 0x187c) & 0xc003 | (ushort)(slotCodeBits << 2) & 0x3ffc;
            glContextWord8c = *(uint *)(glContext + 0x8c);
            slotUsesSpecialSrc = (slotUsesSpecialSrc | glContextWord8c >> 0x1b & 1) << 0x1b;
            *(uint *)(glContext + 0x1874) =
                 (slotUsesSpecial | *(uint *)(glContext + 0x1874) >> 0x19 & 1) << 0x19 |
                 *(uint *)(glContext + 0x1874) & 0xfdffffff;
            combineBits26 = (slotUses2402 | (glContextWord8c & 0xf7ffffff) >> 0x1a & 1) << 0x1a;
            *(uint *)(glContext + 0x8c) = combineBits26 | slotUsesSpecialSrc | glContextWord8c & 0xf3ffffff;
            texCombineStateWord = ((glContextWord8c & 0x2000000) >> 0x19 |
                     slotUsesSpecial | *(short *)(unitEnvBlock + 0x3c) == 0x2400 & texCombineStateWord |
                              *(short *)(unitEnvBlock + 0x60) == 0x2400 & slot1Enabled |
                              *(short *)(unitEnvBlock + 0x84) == 0x2400 & slot2Enabled |
                              (uint)(*(short *)(unitEnvBlock + 0xa8) == 0x2400) & slotEnableBits >> 8) << 0x19 |
                     combineBits26 | slotUsesSpecialSrc | glContextWord8c & 0xf1ffffff;
            *(uint *)(glContext + 0x8c) = texCombineStateWord;
          }
          *(uint *)(glContext + 0x8c) = texCombineStateWord | 0x800000;
          activeListOffset = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *(uint *)(glContext + 0x8c) =
               (uint)(0 < (int)loopIndex2) << 0x18 | texCombineStateWord & 0xfeffffff | 0x800000;
          *(uint *)(activeListOffset + glContext + 0x98) = loopIndex2;
        }
        else {
          *(undefined4 *)(ctxUnitCursor + 0x150) = 0;
          unitFlagsAddrInactive = loopIndex2 * 2 + glContext;
          *(ushort *)(unitFlagsAddrInactive + 0x187c) = *(ushort *)(unitFlagsAddrInactive + 0x187c) & 0x8003;
        }
        loopIndex2 = loopIndex2 + 1;
        unitWordCursor = unitWordCursor + 4;
        ctxUnitCursor = ctxUnitCursor + 4;
        envBlockCursor = envBlockCursor + 0xcc;
        unitByteCursor = unitByteCursor + 1;
        unitsToScan = unitsToScan - 1;
        if (unitsToScan == 0) break;
        glContextWord44 = *(uint *)(glContext + 0x44);
      }
    }
    *(int *)(glContext + 0x94) = loopIndex;
  }
  return;
}

/* psnDecDecodeFragmentProgram @ 0xbde70 (1504 bytes) */
int psnDecDecodeFragmentProgram(rsWords, programImage, outProgram, scCallbacks)
  uint *rsWords;
  uint *programImage;
  undefined4 *outProgram;
  undefined4 *scCallbacks;
{
  int aluByteOffset;
  int texByteOffset;
  uint aluEnd;
  uint texCountFlag;
  uint rsIndex;
  bool moreAluPhases;
  uint alphaAddrWord2;
  uint alphaAddrWord1;
  uint alphaAddrWord0;
  uint aluAddrWord2;
  uint aluAddrWord1;
  uint aluAddrWord0;
  uint aluStart;
  uint cursor4Word0;
  uint cursor5Word0;
  uint *cursor5;
  int *cursor3;
  int *cursor2;
  uint *texWordPtr;
  undefined4 *aluWordPtr;
  bool isFirstTexInst;
  uint lastRsIndex;
  uint texWord;
  uint phaseScan;
  ushort signedRegIndex;
  undefined4 status;
  int recordIndex;
  uint texStart;
  uint texIndex;
  int *cursor;
  uint phaseCursor;
  int phaseBias;
  uint *cursor4;
  int *program;
  uint recordCount;
  uint phaseIndex;
  
  if (((scCallbacks == (undefined4 *)0x0) || (scCallbacks[0xd] != -0x54520ff3)) ||
     (outProgram == (undefined4 *)0x0)) {
    status = 0x80000005;
  }
  else {
    phaseBias = -(*programImage & 7);
    phaseIndex = phaseBias + 3;
    recordCount = (*rsWords & 0xf) + 1;
    if (phaseIndex < 4) {
      phaseCursor = phaseIndex;
      phaseScan = phaseIndex;
      if ((*programImage >> 3 & 1) != 0) goto LAB_000bdeec;
      while( true ) {
        recordCount = recordCount + (programImage[phaseScan + 2] >> 6 & 0x3f) + 1;
        phaseCursor = phaseScan + 1;
        if (3 < phaseScan + 1) break;
LAB_000bdeec:
        recordCount = recordCount + (programImage[phaseCursor + 2] >> 0x11 & 0x1f) + 1;
        phaseScan = phaseCursor;
      }
    }
    program = (int *)*outProgram;
    if (program == (int *)0x0) {
      program = (int *)(*(code *)*scCallbacks)(recordCount * 0x48 + 0x48);
      *program = 0;
      program[1] = recordCount + 1;
      *outProgram = program;
    }
    else if ((*program != 0) || ((uint)program[1] <= recordCount)) {
      return 0x80000006;
    }
    *(undefined2 *)(program + 5) = 0;
    program[2] = 0;
    *(byte *)((int)program + 0xd) = (byte)(*rsWords >> 5) & 7;
    rsIndex = 0;
    cursor4 = rsWords;
    cursor = program;
    do {
      lastRsIndex = rsIndex;
      cursor[0x12] = 1;
      rsIndex = lastRsIndex + 1;
      *(byte *)(cursor + 0x14) = (byte)cursor4[1] & 0xf;
      *(byte *)((int)cursor + 0x51) = (byte)(cursor4[1] >> 4) & 1;
      *(byte *)((int)cursor + 0x52) = (byte)(cursor4[1] >> 0xc) & 0xf;
      *(byte *)((int)cursor + 0x53) = (byte)*(undefined2 *)(cursor4 + 1) & 3;
      *(byte *)(cursor + 0x15) = (byte)(cursor4[1] >> 0x19) & 1;
      *(byte *)((int)cursor + 0x55) = (byte)(cursor4[1] >> 0x1b);
      *(ushort *)((int)cursor + 0x4e) = (ushort)(cursor4[1] >> 0x12) & 0x7f;
      cursor4 = cursor4 + 1;
      cursor4Word0 = *cursor4;
      *(undefined1 *)((int)cursor + 0x57) = 0;
      *(undefined1 *)((int)cursor + 0x56) = 0;
      *(ushort *)(cursor + 0x13) = (ushort)(cursor4Word0 >> 5) & 0x7f;
      cursor = cursor + 0x12;
    } while (rsIndex <= (*rsWords & 0xf));
    recordIndex = lastRsIndex + 2;
    texCountFlag = *programImage >> 3 & 1;
    if (phaseIndex < 4) {
      cursor5 = programImage + phaseBias + 5;
      do {
        cursor5Word0 = *cursor5;
        cursor5 = cursor5 + 1;
        aluStart = cursor5Word0 & 0x3f;
        texStart = cursor5Word0 >> 0xc & 0x1f;
        if ((texCountFlag != 0) && (texCountFlag = texStart + (cursor5Word0 >> 0x11 & 0x1f), texStart <= texCountFlag)) {
          texByteOffset = texStart << 2;
          cursor2 = program + recordIndex * 0x12;
          texIndex = texStart;
          do {
            *cursor2 = 2;
            isFirstTexInst = texIndex == texStart;
            texIndex = texIndex + 1;
            recordIndex = recordIndex + 1;
            *(byte *)((int)cursor2 + 0x19) = (byte)(*(uint *)(texByteOffset + programImage[7]) >> 0xb) & 0xf;
            texWord = *(uint *)(texByteOffset + programImage[7]);
            *(bool *)(cursor2 + 8) = isFirstTexInst;
            *(undefined1 *)((int)cursor2 + 0x1f) = 0;
            *(byte *)((int)cursor2 + 0x1a) = (byte)(texWord >> 0xf) & 7;
            *(ushort *)((int)cursor2 + 0xe) = (ushort)*(undefined4 *)(texByteOffset + programImage[7]) & 0x1f;
            texWordPtr = (uint *)(texByteOffset + programImage[7]);
            texByteOffset = texByteOffset + 4;
            *(ushort *)(cursor2 + 3) = (ushort)(*texWordPtr >> 6) & 0x1f;
            cursor2 = cursor2 + 0x12;
          } while (texIndex <= texCountFlag);
        }
        aluEnd = aluStart + (cursor5Word0 >> 6 & 0x3f);
        if (aluStart <= aluEnd) {
          aluByteOffset = aluStart << 2;
          cursor3 = program + recordIndex * 0x12;
          do {
            *cursor3 = 3;
            *(byte *)(cursor3 + 5) = (byte)(*(uint *)(programImage[8] + aluByteOffset) >> 0x17) & 7;
            *(byte *)((int)cursor3 + 0x15) =
                 (byte)((uint)*(undefined4 *)(programImage[8] + aluByteOffset) >> 0x1a) & 7;
            *(byte *)((int)cursor3 + 0x16) =
                 (byte)((uint)*(undefined4 *)(programImage[8] + aluByteOffset) >> 0x1d) & 3;
            aluAddrWord0 = *(uint *)(programImage[8] + aluByteOffset) & 0x3f;
            signedRegIndex = (ushort)aluAddrWord0;
            if (0x1f < aluAddrWord0) {
              signedRegIndex = signedRegIndex - 0x20 | 0x8000;
            }
            *(ushort *)((int)cursor3 + 0xe) = signedRegIndex;
            aluAddrWord1 = *(uint *)(programImage[8] + aluByteOffset) >> 6 & 0x3f;
            signedRegIndex = (ushort)aluAddrWord1;
            if (0x1f < aluAddrWord1) {
              signedRegIndex = signedRegIndex - 0x20 | 0x8000;
            }
            *(ushort *)(cursor3 + 4) = signedRegIndex;
            aluAddrWord2 = *(uint *)(programImage[8] + aluByteOffset) >> 0xc & 0x3f;
            signedRegIndex = (ushort)aluAddrWord2;
            if (0x1f < aluAddrWord2) {
              signedRegIndex = signedRegIndex - 0x20 | 0x8000;
            }
            *(ushort *)((int)cursor3 + 0x12) = signedRegIndex;
            *(ushort *)(cursor3 + 3) =
                 (ushort)((uint)*(undefined4 *)(programImage[8] + aluByteOffset) >> 0x12) & 0x1f;
            *(byte *)(cursor3 + 8) = (byte)(*(uint *)(programImage[9] + aluByteOffset) >> 0x17) & 1;
            *(byte *)((int)cursor3 + 0x21) = *(byte *)(programImage[9] + aluByteOffset) & 1;
            *(byte *)((int)cursor3 + 0x22) =
                 (byte)((uint)*(undefined4 *)(programImage[9] + aluByteOffset) >> 0x19) & 3;
            *(byte *)((int)cursor3 + 0x23) =
                 (byte)((uint)*(undefined4 *)(programImage[9] + aluByteOffset) >> 0x1b) & 1;
            alphaAddrWord0 = *(uint *)(programImage[9] + aluByteOffset) & 0x3f;
            signedRegIndex = (ushort)alphaAddrWord0;
            if (0x1f < alphaAddrWord0) {
              signedRegIndex = signedRegIndex - 0x20 | 0x8000;
            }
            *(ushort *)((int)cursor3 + 0x1a) = signedRegIndex;
            alphaAddrWord1 = *(uint *)(programImage[9] + aluByteOffset) >> 6 & 0x3f;
            signedRegIndex = (ushort)alphaAddrWord1;
            if (0x1f < alphaAddrWord1) {
              signedRegIndex = signedRegIndex - 0x20 | 0x8000;
            }
            *(ushort *)(cursor3 + 7) = signedRegIndex;
            alphaAddrWord2 = *(uint *)(programImage[9] + aluByteOffset) >> 0xc & 0x3f;
            signedRegIndex = (ushort)alphaAddrWord2;
            if (0x1f < alphaAddrWord2) {
              signedRegIndex = signedRegIndex - 0x20 | 0x8000;
            }
            *(ushort *)((int)cursor3 + 0x1e) = signedRegIndex;
            aluStart = aluStart + 1;
            recordIndex = recordIndex + 1;
            *(ushort *)(cursor3 + 6) =
                 (ushort)((uint)*(undefined4 *)(programImage[9] + aluByteOffset) >> 0x12) & 0x1f;
            *(byte *)((int)cursor3 + 0x2a) = (byte)*(undefined4 *)(programImage[0xb] + aluByteOffset) & 0x1f;
            *(byte *)((int)cursor3 + 0x2d) = (byte)(*(uint *)(programImage[0xb] + aluByteOffset) >> 5) & 3;
            *(byte *)((int)cursor3 + 0x2b) = (byte)(*(uint *)(programImage[0xb] + aluByteOffset) >> 7) & 0x1f;
            *(byte *)((int)cursor3 + 0x2e) = (byte)(*(uint *)(programImage[0xb] + aluByteOffset) >> 0xc) & 3;
            *(byte *)(cursor3 + 0xb) = (byte)(*(uint *)(programImage[0xb] + aluByteOffset) >> 0xe) & 0x1f;
            *(byte *)((int)cursor3 + 0x2f) = (byte)(*(uint *)(programImage[0xb] + aluByteOffset) >> 0x13) & 3;
            *(byte *)(cursor3 + 0xc) = (byte)(*(uint *)(programImage[0xb] + aluByteOffset) >> 0x15) & 3;
            *(byte *)((int)cursor3 + 0x31) = (byte)(*(uint *)(programImage[0xb] + aluByteOffset) >> 0x17) & 0xf;
            *(byte *)((int)cursor3 + 0x32) =
                 (byte)((uint)*(undefined4 *)(programImage[0xb] + aluByteOffset) >> 0x1b) & 7;
            *(byte *)((int)cursor3 + 0x33) =
                 (byte)((uint)*(undefined4 *)(programImage[0xb] + aluByteOffset) >> 0x1e) & 1;
            *(byte *)(cursor3 + 0xd) = (byte)((uint)*(undefined4 *)(programImage[0xb] + aluByteOffset) >> 0x1f);
            *(byte *)((int)cursor3 + 0x39) = (byte)*(undefined4 *)(aluByteOffset + programImage[0xc]) & 0x1f;
            *(byte *)(cursor3 + 0xf) = (byte)(*(uint *)(aluByteOffset + programImage[0xc]) >> 5) & 3;
            *(byte *)((int)cursor3 + 0x3a) = (byte)(*(uint *)(aluByteOffset + programImage[0xc]) >> 7) & 0x1f;
            *(byte *)((int)cursor3 + 0x3d) = (byte)(*(uint *)(aluByteOffset + programImage[0xc]) >> 0xc) & 3;
            *(byte *)((int)cursor3 + 0x3b) = (byte)(*(uint *)(aluByteOffset + programImage[0xc]) >> 0xe) & 0x1f;
            *(byte *)((int)cursor3 + 0x3e) = (byte)(*(uint *)(aluByteOffset + programImage[0xc]) >> 0x13) & 3;
            *(byte *)((int)cursor3 + 0x3f) = (byte)(*(uint *)(aluByteOffset + programImage[0xc]) >> 0x15) & 3;
            *(byte *)(cursor3 + 0x10) = (byte)(*(uint *)(aluByteOffset + programImage[0xc]) >> 0x17) & 0xf;
            *(byte *)((int)cursor3 + 0x41) =
                 (byte)((uint)*(undefined4 *)(aluByteOffset + programImage[0xc]) >> 0x1b) & 7;
            aluWordPtr = (undefined4 *)(aluByteOffset + programImage[0xc]);
            aluByteOffset = aluByteOffset + 4;
            *(byte *)((int)cursor3 + 0x42) = (byte)((uint)*aluWordPtr >> 0x1e) & 1;
            cursor3 = cursor3 + 0x12;
          } while (aluStart <= aluEnd);
        }
        moreAluPhases = phaseIndex != 3;
        texCountFlag = 1;
        phaseIndex = phaseIndex + 1;
      } while (moreAluPhases);
    }
    status = 0;
    program[2] = recordCount;
  }
  return status;
}

/* psnEncodeHwProgramPhased @ 0xbe460 (2472 bytes) */
int psnEncodeHwProgramPhased(psnProgram, rsWords, programImage, unusedArgR6, unusedArgR7, unusedArgR8, unusedArgR9)
  int psnProgram;
  uint *rsWords;
  uint *programImage;
  undefined4 unusedArgR6;
  undefined4 unusedArgR7;
  undefined4 unusedArgR8;
  undefined4 unusedArgR9;
{
  ushort psnProgramShort16;
  uint loopIndex;
  ushort regWord;
  ushort psnProgramShort22;
  int texByteOffset;
  int aluByteOffset;
  bool aluPending;
  bool texSeen;
  int *rsScanNextCopy;
  uint rsWordPartial;
  uint aluBaseIndex;
  uint recordKind;
  uint phaseTexCount;
  uint aluRegField;
  uint rsOutIndex;
  uint rsCountMasked;
  uint *instRecord;
  int *rsScanCur;
  uint loopIndex2;
  int aluHwIndex;
  uint phaseAluCount;
  int *rsScanAhead;
  int *rsScanPrev;
  uint rsOutIndexNext;
  uint texBaseIndex;
  uint *cursor;
  byte rsFlagsByte;
  byte usedFlagsAccum;
  byte depthWriteAccum;
  uint psnProgramWord8;
  uint loopIndex3;
  uint phaseTexCountMinus1;
  int phaseSlot;
  
  psnProgramShort16 = *(ushort *)(psnProgram + 0x16);
  psnProgramShort22 = *(ushort *)(psnProgram + 0x22);
  psnProgramWord8 = *(uint *)(psnProgram + 8);
  phaseSlot = 4 - (uint)psnProgramShort16;
  if ((*(int *)(psnProgram + 0x48) == 1) && (psnProgramWord8 != 0)) {
    rsScanAhead = (int *)(psnProgram + 0x90);
    loopIndex2 = 1;
    rsScanNextCopy = rsScanAhead;
    rsScanPrev = (int *)(psnProgram + 0x48);
    rsOutIndex = 0;
    do {
      rsScanCur = rsScanNextCopy;
      rsOutIndexNext = rsOutIndex;
      if ((rsScanPrev[2] & 0xff00ffU) != 0) {
        rsOutIndexNext = rsOutIndex + 1;
        rsWords[rsOutIndex + 1] = 0;
        rsFlagsByte = *(byte *)(rsScanPrev + 2);
        rsWords[rsOutIndex + 1] = rsFlagsByte & 0xf;
        rsWordPartial = (*(byte *)((int)rsScanPrev + 9) & 1) << 4 | rsFlagsByte & 0xf;
        rsWords[rsOutIndex + 1] = rsWordPartial;
        rsWordPartial = (*(byte *)((int)rsScanPrev + 10) & 0xf) << 0xc | rsWordPartial;
        rsWords[rsOutIndex + 1] = rsWordPartial;
        rsWordPartial = (*(byte *)((int)rsScanPrev + 0xb) & 3) << 0x10 | rsWordPartial;
        rsWords[rsOutIndex + 1] = rsWordPartial;
        rsWordPartial = (*(byte *)(rsScanPrev + 3) & 1) << 0x19 | rsWordPartial;
        rsWords[rsOutIndex + 1] = rsWordPartial;
        rsWordPartial = (uint)*(byte *)((int)rsScanPrev + 0xd) << 0x1b | rsWordPartial;
        rsWords[rsOutIndex + 1] = rsWordPartial;
        rsWordPartial = (*(ushort *)(rsScanPrev + 1) & 0x7f) << 5 | rsWordPartial;
        rsWords[rsOutIndex + 1] = rsWordPartial;
        rsWords[rsOutIndex + 1] = (*(ushort *)((int)rsScanPrev + 6) & 0x7f) << 0x12 | rsWordPartial;
      }
      loopIndex2 = loopIndex2 + 1;
      if (*rsScanAhead != 1) break;
      rsScanAhead = rsScanAhead + 0x12;
      rsScanNextCopy = rsScanCur + 0x12;
      rsScanPrev = rsScanCur;
      rsOutIndex = rsOutIndexNext;
    } while (loopIndex2 <= psnProgramWord8);
    rsCountMasked = rsOutIndexNext & 0xff;
    if (rsOutIndexNext != 0) goto LAB_000be580;
  }
  else {
    loopIndex2 = 1;
  }
  rsCountMasked = 1;
  rsWords[1] = 0;
LAB_000be580:
  rsCountMasked = rsCountMasked - 1 & 0xf;
  *rsWords = rsCountMasked;
  *rsWords = (*(byte *)(psnProgram + 0xd) & 7) << 5 | rsCountMasked;
  programImage[1] = psnProgramShort22 & 0x7f;
  *programImage = psnProgramShort16 - 1 & 7;
  programImage[0xd] = 0;
  programImage[2] = 0;
  programImage[3] = 0;
  programImage[4] = 0;
  programImage[5] = 0;
  programImage[6] = 0;
  if (loopIndex2 <= psnProgramWord8) {
    aluPending = false;
    aluBaseIndex = 0;
    texBaseIndex = 0;
    loopIndex = 0;
    loopIndex3 = 0;
    instRecord = (uint *)(psnProgram + loopIndex2 * 0x48);
    depthWriteAccum = 0;
    usedFlagsAccum = 0;
    texSeen = false;
    cursor = instRecord + 0x1a;
    do {
      recordKind = *instRecord;
      aluHwIndex = aluBaseIndex + loopIndex;
      if (recordKind == 2) {
        if (*(char *)((int)instRecord + 0x1a) != '\0') {
          texByteOffset = (texBaseIndex + loopIndex3) * 4;
          *(undefined4 *)(programImage[7] + texByteOffset) = 0;
          *(uint *)(texByteOffset + programImage[7]) =
               *(byte *)((int)instRecord + 0xf) & 0x1f | *(uint *)(texByteOffset + programImage[7]) & 0xffffffe0;
          *(uint *)(texByteOffset + programImage[7]) =
               (*(byte *)((int)instRecord + 0xd) & 0x1f) << 6 |
               *(uint *)(texByteOffset + programImage[7]) & 0xfffff83f;
          *(uint *)(texByteOffset + programImage[7]) =
               (*(byte *)((int)instRecord + 0x19) & 0xf) << 0xb |
               *(uint *)(texByteOffset + programImage[7]) & 0xffff87ff;
          *(uint *)(texByteOffset + programImage[7]) =
               (*(byte *)((int)instRecord + 0x1a) & 7) << 0xf |
               *(uint *)(texByteOffset + programImage[7]) & 0xfffc7fff;
          *(uint *)(texByteOffset + programImage[7]) =
               (*(ushort *)((int)instRecord + 0xe) & 0x20) << 0xe |
               *(uint *)(texByteOffset + programImage[7]) & 0xfff7ffff;
          *(uint *)(texByteOffset + programImage[7]) =
               (*(ushort *)(instRecord + 3) & 0x20) << 0xf | *(uint *)(texByteOffset + programImage[7]) & 0xffefffff
          ;
          if (!texSeen) {
            texSeen = true;
            *programImage = *programImage | 8;
          }
          loopIndex3 = loopIndex3 + 1;
          aluPending = false;
        }
      }
      else if ((1 < recordKind) && (recordKind < 5)) {
        aluByteOffset = aluHwIndex * 4;
        *(undefined4 *)(programImage[8] + aluByteOffset) = 0;
        regWord = *(ushort *)((int)instRecord + 0xe);
        aluRegField = regWord & 0x1f;
        if ((regWord & 0x8000) != 0) {
          aluRegField = (regWord & 0x1f) + 0x20;
        }
        *(uint *)(aluByteOffset + programImage[8]) = aluRegField | *(uint *)(aluByteOffset + programImage[8]) & 0xffffffc0;
        aluRegField = *(ushort *)(instRecord + 4) & 0x1f;
        if ((*(ushort *)(instRecord + 4) & 0x8000) != 0) {
          aluRegField = aluRegField + 0x20;
        }
        *(uint *)(aluByteOffset + programImage[8]) = aluRegField << 6 | *(uint *)(aluByteOffset + programImage[8]) & 0xfffff03f;
        aluRegField = *(ushort *)((int)instRecord + 0x12) & 0x1f;
        if ((*(ushort *)((int)instRecord + 0x12) & 0x8000) != 0) {
          aluRegField = aluRegField + 0x20;
        }
        *(uint *)(aluByteOffset + programImage[8]) = aluRegField << 0xc | *(uint *)(aluByteOffset + programImage[8]) & 0xfffc0fff;
        *(uint *)(aluByteOffset + programImage[8]) =
             (*(byte *)((int)instRecord + 0xd) & 0x1f) << 0x12 |
             *(uint *)(aluByteOffset + programImage[8]) & 0xff83ffff;
        *(uint *)(aluByteOffset + programImage[8]) =
             (*(byte *)(instRecord + 5) & 7) << 0x17 | *(uint *)(aluByteOffset + programImage[8]) & 0xfc7fffff;
        *(uint *)(aluByteOffset + programImage[8]) =
             (*(byte *)((int)instRecord + 0x15) & 7) << 0x1a |
             *(uint *)(aluByteOffset + programImage[8]) & 0xe3ffffff;
        *(uint *)(aluByteOffset + programImage[8]) =
             (*(byte *)((int)instRecord + 0x16) & 3) << 0x1d |
             *(uint *)(aluByteOffset + programImage[8]) & 0x9fffffff;
        *(undefined4 *)(programImage[9] + aluByteOffset) = 0;
        aluRegField = *(ushort *)((int)instRecord + 0x1a) & 0x1f;
        if ((*(ushort *)((int)instRecord + 0x1a) & 0x8000) != 0) {
          aluRegField = aluRegField + 0x20;
        }
        *(uint *)(aluByteOffset + programImage[9]) = aluRegField | *(uint *)(aluByteOffset + programImage[9]) & 0xffffffc0;
        aluRegField = *(ushort *)(instRecord + 7) & 0x1f;
        if ((*(ushort *)(instRecord + 7) & 0x8000) != 0) {
          aluRegField = aluRegField + 0x20;
        }
        *(uint *)(aluByteOffset + programImage[9]) = aluRegField << 6 | *(uint *)(aluByteOffset + programImage[9]) & 0xfffff03f;
        aluRegField = *(ushort *)((int)instRecord + 0x1e) & 0x1f;
        if ((*(ushort *)((int)instRecord + 0x1e) & 0x8000) != 0) {
          aluRegField = aluRegField + 0x20;
        }
        *(uint *)(aluByteOffset + programImage[9]) = aluRegField << 0xc | *(uint *)(aluByteOffset + programImage[9]) & 0xfffc0fff;
        *(uint *)(aluByteOffset + programImage[9]) =
             (*(byte *)((int)instRecord + 0x19) & 0x1f) << 0x12 |
             *(uint *)(aluByteOffset + programImage[9]) & 0xff83ffff;
        *(uint *)(aluByteOffset + programImage[9]) =
             (*(byte *)(instRecord + 8) & 1) << 0x17 | *(uint *)(aluByteOffset + programImage[9]) & 0xff7fffff;
        *(uint *)(aluByteOffset + programImage[9]) =
             (*(byte *)((int)instRecord + 0x21) & 1) << 0x18 |
             *(uint *)(aluByteOffset + programImage[9]) & 0xfeffffff;
        *(uint *)(aluByteOffset + programImage[9]) =
             (*(byte *)((int)instRecord + 0x22) & 3) << 0x19 |
             *(uint *)(aluByteOffset + programImage[9]) & 0xf9ffffff;
        *(uint *)(aluByteOffset + programImage[9]) =
             (*(byte *)((int)instRecord + 0x23) & 1) << 0x1b |
             *(uint *)(aluByteOffset + programImage[9]) & 0xf7ffffff;
        if (programImage[10] != 0) {
          *(undefined4 *)(programImage[10] + aluByteOffset) = 0;
          *(uint *)(aluByteOffset + programImage[10]) =
               *(ushort *)((int)instRecord + 0xe) >> 5 & 1 |
               *(uint *)(aluByteOffset + programImage[10]) & 0xfffffffe;
          *(uint *)(aluByteOffset + programImage[10]) =
               *(ushort *)(instRecord + 4) >> 4 & 2 | *(uint *)(aluByteOffset + programImage[10]) & 0xfffffffd;
          *(uint *)(aluByteOffset + programImage[10]) =
               *(ushort *)((int)instRecord + 0x12) >> 3 & 4 |
               *(uint *)(aluByteOffset + programImage[10]) & 0xfffffffb;
          *(uint *)(aluByteOffset + programImage[10]) =
               *(ushort *)(instRecord + 3) >> 2 & 8 | *(uint *)(aluByteOffset + programImage[10]) & 0xfffffff7;
          *(uint *)(aluByteOffset + programImage[10]) =
               *(ushort *)((int)instRecord + 0x1a) >> 1 & 0x10 |
               *(uint *)(aluByteOffset + programImage[10]) & 0xffffffef;
          *(uint *)(aluByteOffset + programImage[10]) =
               *(ushort *)(instRecord + 7) & 0x20 | *(uint *)(aluByteOffset + programImage[10]) & 0xffffffdf;
          *(uint *)(aluByteOffset + programImage[10]) =
               (*(ushort *)((int)instRecord + 0x1e) & 0x20) << 1 |
               *(uint *)(aluByteOffset + programImage[10]) & 0xffffffbf;
          *(uint *)(aluByteOffset + programImage[10]) =
               (*(ushort *)(instRecord + 6) & 0x20) << 2 | *(uint *)(aluByteOffset + programImage[10]) & 0xffffff7f;
        }
        loopIndex = loopIndex + 1;
        aluPending = true;
        *(undefined4 *)(programImage[0xb] + aluByteOffset) = 0;
        *(uint *)(aluByteOffset + programImage[0xb]) =
             *(byte *)((int)instRecord + 0x2a) & 0x1f | *(uint *)(aluByteOffset + programImage[0xb]) & 0xffffffe0;
        *(uint *)(aluByteOffset + programImage[0xb]) =
             (*(byte *)((int)instRecord + 0x2d) & 3) << 5 |
             *(uint *)(aluByteOffset + programImage[0xb]) & 0xffffff9f;
        *(uint *)(aluByteOffset + programImage[0xb]) =
             (*(byte *)((int)instRecord + 0x2b) & 0x1f) << 7 |
             *(uint *)(aluByteOffset + programImage[0xb]) & 0xfffff07f;
        *(uint *)(aluByteOffset + programImage[0xb]) =
             (*(byte *)((int)instRecord + 0x2e) & 3) << 0xc |
             *(uint *)(aluByteOffset + programImage[0xb]) & 0xffffcfff;
        *(uint *)(aluByteOffset + programImage[0xb]) =
             (*(byte *)(instRecord + 0xb) & 0x1f) << 0xe | *(uint *)(aluByteOffset + programImage[0xb]) & 0xfff83fff
        ;
        *(uint *)(aluByteOffset + programImage[0xb]) =
             (*(byte *)((int)instRecord + 0x2f) & 3) << 0x13 |
             *(uint *)(aluByteOffset + programImage[0xb]) & 0xffe7ffff;
        *(uint *)(aluByteOffset + programImage[0xb]) =
             (*(byte *)(instRecord + 0xc) & 3) << 0x15 | *(uint *)(aluByteOffset + programImage[0xb]) & 0xff9fffff;
        *(uint *)(aluByteOffset + programImage[0xb]) =
             (*(byte *)((int)instRecord + 0x31) & 0xf) << 0x17 |
             *(uint *)(aluByteOffset + programImage[0xb]) & 0xf87fffff;
        *(uint *)(aluByteOffset + programImage[0xb]) =
             (*(byte *)((int)instRecord + 0x32) & 7) << 0x1b |
             *(uint *)(aluByteOffset + programImage[0xb]) & 0xc7ffffff;
        *(uint *)(aluByteOffset + programImage[0xb]) =
             (*(byte *)((int)instRecord + 0x33) & 1) << 0x1e |
             *(uint *)(aluByteOffset + programImage[0xb]) & 0xbfffffff;
        *(uint *)(aluByteOffset + programImage[0xb]) =
             (uint)*(byte *)(instRecord + 0xd) << 0x1f | *(uint *)(aluByteOffset + programImage[0xb]) & 0x7fffffff;
        *(undefined4 *)(programImage[0xc] + aluByteOffset) = 0;
        *(uint *)(aluByteOffset + programImage[0xc]) =
             *(byte *)((int)instRecord + 0x39) & 0x1f | *(uint *)(aluByteOffset + programImage[0xc]) & 0xffffffe0;
        *(uint *)(aluByteOffset + programImage[0xc]) =
             (*(byte *)(instRecord + 0xf) & 3) << 5 | *(uint *)(aluByteOffset + programImage[0xc]) & 0xffffff9f;
        *(uint *)(aluByteOffset + programImage[0xc]) =
             (*(byte *)((int)instRecord + 0x3a) & 0x1f) << 7 |
             *(uint *)(aluByteOffset + programImage[0xc]) & 0xfffff07f;
        *(uint *)(aluByteOffset + programImage[0xc]) =
             (*(byte *)((int)instRecord + 0x3d) & 3) << 0xc |
             *(uint *)(aluByteOffset + programImage[0xc]) & 0xffffcfff;
        *(uint *)(aluByteOffset + programImage[0xc]) =
             (*(byte *)((int)instRecord + 0x3b) & 0x1f) << 0xe |
             *(uint *)(aluByteOffset + programImage[0xc]) & 0xfff83fff;
        *(uint *)(aluByteOffset + programImage[0xc]) =
             (*(byte *)((int)instRecord + 0x3e) & 3) << 0x13 |
             *(uint *)(aluByteOffset + programImage[0xc]) & 0xffe7ffff;
        *(uint *)(aluByteOffset + programImage[0xc]) =
             (*(byte *)((int)instRecord + 0x3f) & 3) << 0x15 |
             *(uint *)(aluByteOffset + programImage[0xc]) & 0xff9fffff;
        *(uint *)(aluByteOffset + programImage[0xc]) =
             (*(byte *)(instRecord + 0x10) & 0xf) << 0x17 |
             *(uint *)(aluByteOffset + programImage[0xc]) & 0xf87fffff;
        *(uint *)(aluByteOffset + programImage[0xc]) =
             (*(byte *)((int)instRecord + 0x41) & 7) << 0x1b |
             *(uint *)(aluByteOffset + programImage[0xc]) & 0xc7ffffff;
        *(uint *)(aluByteOffset + programImage[0xc]) =
             (*(byte *)((int)instRecord + 0x42) & 1) << 0x1e |
             *(uint *)(aluByteOffset + programImage[0xc]) & 0xbfffffff;
        depthWriteAccum = depthWriteAccum | *(byte *)((int)instRecord + 0x23);
        usedFlagsAccum = usedFlagsAccum | *(byte *)((int)instRecord + 0x15) | *(byte *)((int)instRecord + 0x21);
      }
      if ((loopIndex2 == psnProgramWord8) || ((cursor[-8] == 2 && ((aluPending || (*(char *)cursor != '\0')))))) {
        if (loopIndex3 == 0) {
          loopIndex3 = 1;
          phaseTexCount = 1;
          phaseTexCountMinus1 = 0;
        }
        else {
          phaseTexCount = loopIndex3 & 0xff;
          phaseTexCountMinus1 = loopIndex3 - 1;
        }
        phaseAluCount = loopIndex & 0xff;
        if (loopIndex == 0) {
          aluHwIndex = aluHwIndex * 4;
          *(undefined4 *)(programImage[8] + aluHwIndex) = 0;
          *(undefined4 *)(programImage[9] + aluHwIndex) = 0;
          if (programImage[10] != 0) {
            *(undefined4 *)(programImage[10] + aluHwIndex) = 0;
          }
          phaseAluCount = 1;
          *(undefined4 *)(programImage[0xb] + aluHwIndex) = 0;
          *(undefined4 *)(programImage[0xc] + aluHwIndex) = 0;
          loopIndex = 1;
        }
        programImage[phaseSlot + 2] =
             (phaseTexCountMinus1 & 0x1e0) << 0x17 |
             (texBaseIndex & 0x1e0) << 0x13 |
             (phaseAluCount - 1) * 0x40 & 0xfc0 |
             (phaseTexCount - 1) * 0x20000 & 0x3e0000 |
             aluBaseIndex & 0x3f | (texBaseIndex & 0x1f) << 0xc | programImage[phaseSlot + 2] & 0xc00000;
        if (phaseSlot == 1) {
          programImage[6] = (loopIndex - 1) * 0x200 & 0x38000 |
                       (aluBaseIndex & 0x1c0) << 6 | programImage[6] & 0xfffc0fff;
        }
        else if (phaseSlot == 0) {
          programImage[6] = (loopIndex - 1) * 8 & 0xe00 | aluBaseIndex & 0x1c0 | programImage[6] & 0xfffff03f;
        }
        else if (phaseSlot == 2) {
          programImage[6] = (loopIndex - 1) * 0x8000 & 0xe00000 |
                       (aluBaseIndex & 0x1c0) << 0xc | programImage[6] & 0xff03ffff;
        }
        else if (phaseSlot == 3) {
          programImage[6] = (loopIndex - 1) * 0x200000 & 0x38000000 |
                       (aluBaseIndex & 0x1c0) << 0x12 | programImage[6] & 0xc0ffffff;
        }
        if (usedFlagsAccum != 0) {
          programImage[phaseSlot + 2] = programImage[phaseSlot + 2] | 0x400000;
        }
        if (depthWriteAccum != 0) {
          programImage[phaseSlot + 2] = programImage[phaseSlot + 2] | 0x800000;
          programImage[0xd] = programImage[0xd] | 1;
        }
        if (texSeen) {
          texBaseIndex = texBaseIndex + loopIndex3;
        }
        aluBaseIndex = aluBaseIndex + loopIndex;
        phaseSlot = phaseSlot + 1;
        loopIndex = 0;
        loopIndex3 = 0;
        depthWriteAccum = 0;
        usedFlagsAccum = 0;
        texSeen = true;
      }
      loopIndex2 = loopIndex2 + 1;
      instRecord = instRecord + 0x12;
      cursor = cursor + 0x12;
    } while (loopIndex2 <= psnProgramWord8);
  }
  return;
}

/* psnCheckLimitsAndGenerate @ 0xbee40 (244 bytes) */
int psnCheckLimitsAndGenerate(psnProgram, passThroughR4, passThroughR5, unusedArgR6, passThroughR7, passThroughR8, passThroughR9)
  int psnProgram;
  undefined4 passThroughR4;
  undefined4 passThroughR5;
  undefined4 unusedArgR6;
  undefined4 passThroughR7;
  undefined4 passThroughR8;
  undefined4 passThroughR9;
{
  undefined4 limitStatus;
  
  ((int (*)())psnAnalyzeProgram)(psnProgram);
  if (*(ushort *)(psnProgram + 0x16) < 5) {
    if (*(ushort *)(psnProgram + 0x18) < 0x11) {
      if (*(ushort *)(psnProgram + 0x1a) < 0x21) {
        if (*(ushort *)(psnProgram + 0x1e) < 0x41) {
          if (*(short *)(psnProgram + 0x20) == 0) {
            if (*(ushort *)(psnProgram + 0x22) < 0x20) {
              if (*(ushort *)(psnProgram + 0x24) < 0x20) {
                ((int (*)())psnEncodeHwProgramPhased)(psnProgram,passThroughR4,passThroughR5,0,passThroughR7,passThroughR8,passThroughR9);
                limitStatus = 0;
              }
              else {
                limitStatus = 0x80000013;
              }
            }
            else {
              limitStatus = 0x80000012;
            }
          }
          else {
            limitStatus = 0x80000017;
          }
        }
        else {
          limitStatus = 0x80000016;
        }
      }
      else {
        limitStatus = 0x80000015;
      }
    }
    else {
      limitStatus = 0x80000014;
    }
  }
  else {
    limitStatus = 0x80000011;
  }
  return limitStatus;
}

/* psnRemapTempRegisters @ 0xbef40 (1192 bytes) */
int psnRemapTempRegisters(psnProgram, passThroughR4, passThroughR5, unusedArgR6, recordFieldCursor)
  int psnProgram;
  undefined4 passThroughR4;
  undefined4 passThroughR5;
  undefined4 unusedArgR6;
  dword *recordFieldCursor;
{
  bool bankFlag;
  byte operandKindByte;
  ushort regIndexField;
  dword nextRecordKind;
  int tableValueNext;
  uint recordKind;
  int remapIndex;
  int *slotScanCursor;
  undefined4 limitStatus;
  char *enableFlag20Ptr;
  ushort *regField12Ptr;
  ushort *regField10Ptr;
  dword *nextRecordPtr;
  dword *recordPtr;
  int *highTableCursor;
  dword *scanRecordPtr;
  char *enableFlag14Ptr;
  uint loopIndex;
  dword *scanNextPtr;
  dword *regField0eCursor;
  ushort *regField18Ptr;
  uint psnProgramWord8;
  ushort *regField1ePtr;
  ushort *regField06Ptr;
  char *enableFlag0bPtr;
  ushort *regField04Ptr;
  char *enableFlag09Ptr;
  dword *scanNextPtr2;
  dword *regField0cCursor;
  ushort *kindField1aPtr;
  ushort *regField1cPtr;
  ushort *regField1aPtr;
  int countdownIndex;
  int regRemapTable [32];
  int regRemapTableHigh [35];
  
  ((int (*)())psnAnalyzeProgram)(psnProgram);
  if (*(ushort *)(psnProgram + 0x16) < 5) {
    if (*(ushort *)(psnProgram + 0x18) < 0x11) {
      if (*(ushort *)(psnProgram + 0x1a) < 0x201) {
        if (*(ushort *)(psnProgram + 0x1e) < 0x201) {
          if (*(short *)(psnProgram + 0x20) == 0) {
            if (*(ushort *)(psnProgram + 0x22) < 0x40) {
              if (*(ushort *)(psnProgram + 0x24) < 0x40) {
                scanRecordPtr = &(*(GhidraMachOCommand *)0x0000001c).filesize;
                psnProgramWord8 = *(uint *)(psnProgram + 8);
                remapIndex = 0;
                countdownIndex = 0x40;
                do {
                  *(undefined4 *)(remapIndex + (int)regRemapTable) = 0xffffffff;
                  remapIndex = remapIndex + 4;
                  countdownIndex = countdownIndex + -1;
                } while (countdownIndex != 0);
                if ((psnProgramWord8 != 0) &&
                   (recordPtr = (dword *)(psnProgram + 0x48), recordFieldCursor = recordPtr,
                   *(int *)(psnProgram + 0x48) == 1)) {
                  scanNextPtr = (dword *)(psnProgram + 0x90);
                  loopIndex = 1;
                  bankFlag = false;
                  scanNextPtr2 = scanNextPtr;
                  scanRecordPtr = recordPtr;
                  do {
                    nextRecordPtr = scanNextPtr2;
                    if ((*(char *)((int)scanRecordPtr + 9) != '\0') &&
                       (regIndexField = *(ushort *)(scanRecordPtr + 1), regRemapTable[regIndexField] = 0,
                       (regIndexField & 0x20) != 0)) {
                      bankFlag = true;
                    }
                    if ((*(char *)((int)scanRecordPtr + 0xb) != '\0') &&
                       (regIndexField = *(ushort *)((int)scanRecordPtr + 6), regRemapTable[regIndexField] = 0,
                       (regIndexField & 0x20) != 0)) {
                      bankFlag = true;
                    }
                    loopIndex = loopIndex + 1;
                    if (psnProgramWord8 < loopIndex) break;
                    nextRecordKind = *scanNextPtr;
                    scanNextPtr = scanNextPtr + 0x12;
                    scanNextPtr2 = nextRecordPtr + 0x12;
                    scanRecordPtr = nextRecordPtr;
                  } while (nextRecordKind == 1);
                  if (bankFlag) {
                    remapIndex = 0x20;
                    countdownIndex = 0;
                    highTableCursor = regRemapTableHigh;
                    do {
                      if (*highTableCursor == 0) {
                        if (regRemapTable[countdownIndex] != -1) {
                          slotScanCursor = regRemapTable + countdownIndex + 1;
                          do {
                            tableValueNext = *slotScanCursor;
                            countdownIndex = countdownIndex + 1;
                            slotScanCursor = slotScanCursor + 1;
                          } while (tableValueNext != -1);
                        }
                        *highTableCursor = countdownIndex;
                        regRemapTable[countdownIndex] = remapIndex;
                      }
                      bankFlag = remapIndex != 0x3f;
                      highTableCursor = highTableCursor + 1;
                      remapIndex = remapIndex + 1;
                    } while (bankFlag);
                    regField0eCursor = (dword *)(psnProgram + 0x56);
                    kindField1aPtr = (ushort *)(psnProgram + 0x62);
                    recordFieldCursor = (dword *)(psnProgram + 0x54);
                    regField1ePtr = (ushort *)(psnProgram + 0x66);
                    regField06Ptr = (ushort *)(psnProgram + 0x4e);
                    enableFlag0bPtr = (char *)(psnProgram + 0x53);
                    regField04Ptr = (ushort *)(psnProgram + 0x4c);
                    enableFlag09Ptr = (char *)(psnProgram + 0x51);
                    regField1cPtr = (ushort *)(psnProgram + 100);
                    regField18Ptr = (ushort *)(psnProgram + 0x60);
                    enableFlag20Ptr = (char *)(psnProgram + 0x68);
                    regField12Ptr = (ushort *)(psnProgram + 0x5a);
                    regField10Ptr = (ushort *)(psnProgram + 0x58);
                    loopIndex = 1;
                    enableFlag14Ptr = (char *)(psnProgram + 0x5c);
                    scanRecordPtr = regField0eCursor;
                    regField0cCursor = recordFieldCursor;
                    regField1aPtr = kindField1aPtr;
                    do {
                      recordKind = *recordPtr;
                      if (recordKind != 2) {
                        if (recordKind < 3) {
                          if (recordKind == 1) {
                            if ((*enableFlag09Ptr != '\0') && (remapIndex = regRemapTable[*regField04Ptr], remapIndex != -1))
                            {
                              *regField04Ptr = (ushort)remapIndex;
                            }
                            if ((*enableFlag0bPtr != '\0') && (remapIndex = regRemapTable[*regField06Ptr], remapIndex != -1))
                            {
                              *regField06Ptr = (ushort)remapIndex;
                            }
                          }
                        }
                        else if (recordKind < 5) {
                          if ((*enableFlag14Ptr != '\0') &&
                             (remapIndex = regRemapTable[*(ushort *)recordFieldCursor], remapIndex != -1)) {
                            *(ushort *)recordFieldCursor = (ushort)remapIndex;
                          }
                          if (((*(ushort *)regField0eCursor & 0x8000) == 0) &&
                             (remapIndex = regRemapTable[*(ushort *)regField0eCursor], remapIndex != -1)) {
                            *(ushort *)regField0eCursor = (ushort)remapIndex;
                          }
                          if (((*regField10Ptr & 0x8000) == 0) &&
                             (remapIndex = regRemapTable[*regField10Ptr], remapIndex != -1)) {
                            *regField10Ptr = (ushort)remapIndex;
                          }
                          if (((*regField12Ptr & 0x8000) == 0) &&
                             (remapIndex = regRemapTable[*regField12Ptr], remapIndex != -1)) {
                            *regField12Ptr = (ushort)remapIndex;
                          }
                          if ((*enableFlag20Ptr != '\0') && (remapIndex = regRemapTable[*regField18Ptr], remapIndex != -1)) {
                            *regField18Ptr = (ushort)remapIndex;
                          }
                          if (((*regField1aPtr & 0x8000) == 0) &&
                             (remapIndex = regRemapTable[*regField1aPtr], remapIndex != -1)) {
                            *regField1aPtr = (ushort)remapIndex;
                          }
                          if (((*regField1cPtr & 0x8000) == 0) &&
                             (remapIndex = regRemapTable[*regField1cPtr], remapIndex != -1)) {
                            *regField1cPtr = (ushort)remapIndex;
                          }
                          if (((*regField1ePtr & 0x8000) == 0) &&
                             (remapIndex = regRemapTable[*regField1ePtr], remapIndex != -1)) {
                            *regField1ePtr = (ushort)remapIndex;
                          }
                        }
                        goto LAB_000bf33c;
                      }
                      operandKindByte = *(byte *)kindField1aPtr;
                      if (operandKindByte == 2) {
LAB_000bf224:
                        remapIndex = regRemapTable[*(ushort *)scanRecordPtr];
                        if (remapIndex != -1) {
                          *(ushort *)scanRecordPtr = (ushort)remapIndex;
                        }
                      }
                      else if (operandKindByte < 3) {
                        if (operandKindByte == 1) {
LAB_000bf20c:
                          remapIndex = regRemapTable[*(ushort *)regField0cCursor];
                          if (remapIndex != -1) {
                            *(ushort *)regField0cCursor = (ushort)remapIndex;
                          }
                          goto LAB_000bf224;
                        }
                      }
                      else if (operandKindByte < 5) goto LAB_000bf20c;
LAB_000bf33c:
                      loopIndex = loopIndex + 1;
                      recordPtr = recordPtr + 0x12;
                      scanRecordPtr = scanRecordPtr + 0x12;
                      regField1ePtr = regField1ePtr + 0x24;
                      regField06Ptr = regField06Ptr + 0x24;
                      enableFlag0bPtr = enableFlag0bPtr + 0x48;
                      regField04Ptr = regField04Ptr + 0x24;
                      enableFlag09Ptr = enableFlag09Ptr + 0x48;
                      regField0cCursor = regField0cCursor + 0x12;
                      kindField1aPtr = kindField1aPtr + 0x24;
                      regField1cPtr = regField1cPtr + 0x24;
                      regField1aPtr = regField1aPtr + 0x24;
                      regField18Ptr = regField18Ptr + 0x24;
                      enableFlag20Ptr = enableFlag20Ptr + 0x48;
                      regField12Ptr = regField12Ptr + 0x24;
                      regField10Ptr = regField10Ptr + 0x24;
                      regField0eCursor = regField0eCursor + 0x12;
                      recordFieldCursor = recordFieldCursor + 0x12;
                      enableFlag14Ptr = enableFlag14Ptr + 0x48;
                    } while (loopIndex <= psnProgramWord8);
                  }
                }
                ((int (*)())psnEncodeHwProgramPhased)(psnProgram,passThroughR4,passThroughR5,1,recordFieldCursor,regRemapTable,scanRecordPtr);
                limitStatus = 0;
              }
              else {
                limitStatus = 0x80000013;
              }
            }
            else {
              limitStatus = 0x80000012;
            }
          }
          else {
            limitStatus = 0x80000017;
          }
        }
        else {
          limitStatus = 0x80000016;
        }
      }
      else {
        limitStatus = 0x80000015;
      }
    }
    else {
      limitStatus = 0x80000014;
    }
  }
  else {
    limitStatus = 0x80000011;
  }
  return limitStatus;
}

/* psnPlanPhases @ 0xbf400 (1260 bytes) */
int psnPlanPhases(psnProgram, wantedPhaseCount, unusedArgR5, unusedArgR6, unusedArgR7, unusedArgR8, unusedArgR9)
  int psnProgram;
  uint wantedPhaseCount;
  undefined4 unusedArgR5;
  undefined4 unusedArgR6;
  undefined4 unusedArgR7;
  undefined4 unusedArgR8;
  undefined4 unusedArgR9;
{
  uint loopIndex3;
  uint loopIndex2;
  bool needSplit;
  bool anyFlagsSet;
  byte channelMaskByte;
  bool splittable;
  uint recordKind;
  uint nextPendingRecord;
  uint selectBits;
  char texDimModeA;
  char texDimModeB;
  char texDimModeC;
  uint recordKind2;
  int pendingRecordPtr;
  int *rsScanPtr;
  uint loopIndex;
  uint recordCount;
  uint recordNumber2;
  uint *recordPtr;
  uint recordNumber;
  uint pendingRecord;
  undefined1 *flagPtr;
  uint texRegCount;
  uint hasHighAddress;
  byte usedFlags;
  
  if (wantedPhaseCount <= (*(byte *)(psnProgram + 0xf) & 0xf)) {
    return;
  }
  recordCount = *(uint *)(psnProgram + 8);
  if ((*(int *)(psnProgram + 0x48) == 1) && (recordCount != 0)) {
    rsScanPtr = (int *)(psnProgram + 0x90);
    loopIndex = 1;
    do {
      loopIndex = loopIndex + 1;
      if (*rsScanPtr != 1) goto LAB_000bf474;
      rsScanPtr = rsScanPtr + 0x12;
    } while (loopIndex <= recordCount);
LAB_000bf44c:
    usedFlags = 0;
    hasHighAddress = 0;
    splittable = true;
  }
  else {
    loopIndex = 1;
LAB_000bf474:
    if (recordCount < loopIndex) goto LAB_000bf44c;
    usedFlags = 0;
    splittable = true;
    recordPtr = (uint *)(psnProgram + loopIndex * 0x48);
    texRegCount = 0;
    loopIndex3 = 0;
    needSplit = false;
    hasHighAddress = 0;
    recordNumber = loopIndex;
    do {
      recordKind = *recordPtr;
      if (recordKind < 5) {
        if (recordKind < 3) {
          if ((recordKind == 2) &&
             (usedFlags = usedFlags | *(byte *)(recordPtr + 1) | *(byte *)((int)recordPtr + 0x1b),
             *(char *)((int)recordPtr + 0x1a) != '\0')) {
            hasHighAddress = hasHighAddress | -(uint)(recordPtr[7] & 0xffff00) >> 0x1f;
          }
        }
        else {
          usedFlags = usedFlags | *(byte *)(recordPtr + 1);
        }
      }
      else if ((recordKind == 5) && (usedFlags = usedFlags | *(byte *)(recordPtr + 1), splittable)) {
        if ((*(char *)((int)recordPtr + 0xe) != '\0') || (*(char *)((int)recordPtr + 0x11) != '\0')) {
          needSplit = true;
        }
        selectBits = recordPtr[4] & 0xff00ff00;
        if ((selectBits != 0) &&
           ((*(ushort *)(recordPtr + 3) < loopIndex3 || (*(char *)((int)recordPtr + 0x19) != '\0')))) {
          needSplit = true;
        }
        texDimModeA = *(char *)(recordPtr + 5);
        texDimModeB = *(char *)((int)recordPtr + 0x15);
        texDimModeC = texDimModeA;
        if ((selectBits != 0) && (texDimModeC = texDimModeB, selectBits == 0x100ff00)) {
          texDimModeA = texDimModeB;
        }
        texDimModeB = texDimModeC;
        if ((texDimModeA == '\x01') || (texDimModeB = texDimModeA, texDimModeA != '\0')) {
          if (texDimModeB == '\x02') goto LAB_000bf5b4;
          if (texDimModeB == '\x01') {
            texRegCount = texRegCount - *(byte *)((int)recordPtr + 0x13);
          }
        }
        else if (texDimModeC == '\x02') {
LAB_000bf5b4:
          texRegCount = texRegCount + 1;
        }
        splittable = !needSplit;
        if (4 < texRegCount) {
          needSplit = true;
          splittable = false;
        }
      }
      recordNumber = recordNumber + 1;
      loopIndex3 = loopIndex3 + 1;
      recordPtr = recordPtr + 0x12;
    } while (recordNumber <= recordCount);
    if (loopIndex3 != 0) goto LAB_000bf45c;
  }
  loopIndex3 = 1;
LAB_000bf45c:
  if ((*(short *)(psnProgram + 0x20) == 0) && (*(short *)(psnProgram + 0x12) == 0)) {
    *(short *)(psnProgram + 0x12) = (short)loopIndex3 + -1;
  }
  if (!splittable) {
    *(undefined2 *)(psnProgram + 0x28) = 1;
  }
  if ((*(short *)(psnProgram + 0x28) != 0) && (*(short *)(psnProgram + 0x22) == 0)) {
    *(undefined2 *)(psnProgram + 0x22) = 1;
  }
  if (loopIndex <= recordCount) {
    anyFlagsSet = usedFlags != 0;
    recordPtr = (uint *)(psnProgram + loopIndex * 0x48);
    loopIndex2 = 0;
    flagPtr = (undefined1 *)((int)recordPtr + -3);
    pendingRecord = 100000;
    recordNumber2 = loopIndex;
    do {
      recordKind2 = *recordPtr;
      nextPendingRecord = pendingRecord;
      if (recordKind2 < 5) {
        if (recordKind2 < 3) {
          if (recordKind2 == 2) {
            if (hasHighAddress == 0) {
              *(undefined1 *)((int)recordPtr + 0x1d) = 7;
              *(undefined1 *)((int)recordPtr + 0x1e) = 1;
              recordPtr[5] = recordPtr[5] & 0xffff | 0x1b1b0000;
            }
            channelMaskByte = *(byte *)((int)recordPtr + 0x1f);
            if (channelMaskByte != 0) {
              if ((channelMaskByte & 2) != 0) {
                recordPtr[5] = recordPtr[5] >> 2 & 0x300000 | recordPtr[5] & 0xffcfffff;
              }
              if ((channelMaskByte & 4) != 0) {
                recordPtr[5] = recordPtr[5] >> 4 & 0xc0000 | recordPtr[5] & 0xfff3ffff;
              }
              if ((channelMaskByte & 8) != 0) {
                recordPtr[5] = recordPtr[5] >> 6 & 0x30000 | recordPtr[5] & 0xfffcffff;
              }
            }
            nextPendingRecord = recordNumber2;
            if (((!anyFlagsSet) && (*(char *)(recordPtr + 8) != '\0')) && (pendingRecord != 100000)) {
              pendingRecordPtr = psnProgram + pendingRecord * 0x48;
              *(undefined1 *)(pendingRecordPtr + 4) = 1;
              *(undefined1 *)(pendingRecordPtr + 0x1b) = 1;
              *(undefined1 *)(recordPtr + 1) = 1;
            }
          }
        }
        else {
          if (((*(char *)((int)recordPtr + 0x15) == '\0') && ((recordPtr[8] & 0xff00ff) == 0)) &&
             (loopIndex2 != *(ushort *)(psnProgram + 0x12))) {
            *recordPtr = 4;
          }
          if ((anyFlagsSet) || (pendingRecord == 100000)) {
LAB_000bf860:
            nextPendingRecord = 100000;
          }
          else {
            pendingRecordPtr = psnProgram + pendingRecord * 0x48;
            *(undefined1 *)(pendingRecordPtr + 4) = 1;
            *(undefined1 *)(pendingRecordPtr + 0x1b) = 1;
            *(undefined1 *)(recordPtr + 1) = 1;
            nextPendingRecord = 100000;
          }
        }
      }
      else if (recordKind2 == 5) {
        if ((!anyFlagsSet) && (pendingRecord != 100000)) {
          pendingRecordPtr = psnProgram + pendingRecord * 0x48;
          *(undefined1 *)(pendingRecordPtr + 4) = 1;
          *(undefined1 *)(pendingRecordPtr + 0x1b) = 1;
          *(undefined1 *)(recordPtr + 1) = 1;
        }
        if ((((byte)(*(byte *)((int)recordPtr + 0x12) & 0xf0) ==
              (byte)(*(byte *)((int)recordPtr + 0x12) << 4)) || (loopIndex2 == 0)) ||
           (1 < *(int *)(flagPtr + -0x45) - 3U)) goto LAB_000bf860;
        *flagPtr = 1;
        nextPendingRecord = 100000;
      }
      recordNumber2 = recordNumber2 + 1;
      loopIndex2 = loopIndex2 + 1;
      recordPtr = recordPtr + 0x12;
      flagPtr = flagPtr + 0x48;
      pendingRecord = nextPendingRecord;
    } while (recordNumber2 <= recordCount);
    if (((loopIndex2 != 0) &&
        (pendingRecordPtr = (*(ushort *)(psnProgram + 0x12) + loopIndex) * 0x48, *(int *)(psnProgram + pendingRecordPtr) == 3)) &&
       (usedFlags == 0)) {
      *(undefined1 *)(psnProgram + pendingRecordPtr + 4) = 1;
    }
  }
  if (((hasHighAddress != 0) || (usedFlags != 0)) || (*(short *)(psnProgram + 0x20) != 0)) {
    wantedPhaseCount = wantedPhaseCount | wantedPhaseCount << 4;
  }
  *(char *)(psnProgram + 0xf) = (char)wantedPhaseCount;
  return;
}

/* ilRemapSwizzleTriple @ 0xbf910 (796 bytes) */
int ilRemapSwizzleTriple(swizzleCode, selectX, selectY, selectZ)
  uint *swizzleCode;
  undefined4 *selectX;
  undefined4 *selectY;
  undefined4 *selectZ;
{
  uint swizzleCodeWord0;
  undefined4 selectValue;
  
  swizzleCodeWord0 = *swizzleCode;
  if ((swizzleCodeWord0 & 0x80) != 0) {
    *swizzleCode = swizzleCodeWord0 & 0xffffff7f;
    return;
  }
  switch(swizzleCodeWord0) {
  case 0:
    *swizzleCode = 0;
    *selectX = 0;
    *selectY = 1;
    *selectZ = 2;
    return;
  case 1:
    *swizzleCode = 0;
    *selectX = 0;
    *selectY = 0;
    *selectZ = 0;
    return;
  case 2:
    selectValue = 1;
    break;
  case 3:
    selectValue = 2;
    break;
  case 4:
    *swizzleCode = 1;
    *selectX = 0;
    *selectY = 1;
    *selectZ = 2;
    return;
  case 5:
    selectValue = 0;
    goto LAB_000bfac8;
  case 6:
    *swizzleCode = 1;
    *selectX = 1;
    *selectY = 1;
    *selectZ = 1;
    return;
  case 7:
    selectValue = 2;
    goto LAB_000bfac8;
  case 8:
    *swizzleCode = 2;
    *selectX = 0;
    *selectY = 1;
    *selectZ = 2;
    return;
  case 9:
    selectValue = 0;
    goto LAB_000bfae4;
  case 10:
    selectValue = 1;
    goto LAB_000bfae4;
  case 0xb:
    *swizzleCode = 2;
    *selectX = 2;
    *selectY = 2;
    *selectZ = 2;
    return;
  case 0xc:
    selectValue = 3;
    break;
  case 0xd:
    selectValue = 3;
LAB_000bfac8:
    *swizzleCode = 1;
    *selectX = selectValue;
    *selectY = selectValue;
    *selectZ = selectValue;
    return;
  case 0xe:
    selectValue = 3;
LAB_000bfae4:
    *swizzleCode = 2;
    *selectX = selectValue;
    *selectY = selectValue;
    *selectZ = selectValue;
    return;
  case 0xf:
    *swizzleCode = 3;
    *selectX = 0;
    *selectY = 1;
    *selectZ = 2;
    return;
  case 0x10:
    selectValue = 0;
    goto LAB_000bfb34;
  case 0x11:
    selectValue = 1;
    goto LAB_000bfb34;
  case 0x12:
    selectValue = 2;
LAB_000bfb34:
    *swizzleCode = 3;
    *selectX = selectValue;
    *selectY = selectValue;
    *selectZ = selectValue;
    return;
  case 0x13:
    *swizzleCode = 3;
    *selectX = 3;
    *selectY = 3;
    *selectZ = 3;
    return;
  case 0x14:
    selectValue = 4;
    break;
  case 0x15:
    selectValue = 6;
    break;
  case 0x16:
    selectValue = 5;
    break;
  case 0x17:
    *swizzleCode = 0;
    *selectX = 1;
    *selectY = 2;
    *selectZ = 0;
    return;
  case 0x18:
    *swizzleCode = 1;
    *selectX = 1;
    *selectY = 2;
    *selectZ = 0;
    return;
  case 0x19:
    *swizzleCode = 2;
    *selectX = 1;
    *selectY = 2;
    *selectZ = 0;
    return;
  case 0x1a:
    *swizzleCode = 0;
    *selectX = 2;
    *selectY = 0;
    *selectZ = 1;
    return;
  case 0x1b:
    *swizzleCode = 1;
    *selectX = 2;
    *selectY = 0;
    *selectZ = 1;
    return;
  case 0x1c:
    *swizzleCode = 2;
    *selectX = 2;
    *selectY = 0;
    *selectZ = 1;
    return;
  case 0x1d:
    *swizzleCode = 0;
    *selectX = 3;
    *selectY = 2;
    *selectZ = 1;
    return;
  case 0x1e:
    *swizzleCode = 1;
    *selectX = 3;
    *selectY = 2;
    *selectZ = 1;
    return;
  case 0x1f:
    *swizzleCode = 2;
    *selectX = 3;
    *selectY = 2;
    *selectZ = 1;
    return;
  default:
    return;
  }
  *swizzleCode = 0;
  *selectX = selectValue;
  *selectY = selectValue;
  *selectZ = selectValue;
  return;
}

/* ilRemapSwizzleSingle @ 0xbfcc0 (440 bytes) */
int ilRemapSwizzleSingle(swizzleCode, channelSelect)
  uint *swizzleCode;
  undefined4 *channelSelect;
{
  uint swizzleWord;
  
  swizzleWord = *swizzleCode;
  if ((swizzleWord & 0x80) == 0) {
    switch(swizzleWord) {
    case 0:
      *swizzleCode = 0;
      *channelSelect = 0;
      return;
    case 1:
      *swizzleCode = 0;
      *channelSelect = 1;
      return;
    case 2:
      *swizzleCode = 0;
      *channelSelect = 2;
      return;
    case 3:
      *swizzleCode = 1;
      *channelSelect = 0;
      return;
    case 4:
      *swizzleCode = 1;
      *channelSelect = 1;
      return;
    case 5:
      *swizzleCode = 1;
      *channelSelect = 2;
      return;
    case 6:
      *swizzleCode = 2;
      *channelSelect = 0;
      return;
    case 7:
      *swizzleCode = 2;
      *channelSelect = 1;
      return;
    case 8:
      *swizzleCode = 2;
      *channelSelect = 2;
      return;
    case 9:
      *swizzleCode = 0;
      *channelSelect = 3;
      return;
    case 10:
      *swizzleCode = 1;
      *channelSelect = 3;
      return;
    case 0xb:
      *swizzleCode = 2;
      *channelSelect = 3;
      return;
    case 0xc:
      *swizzleCode = 3;
      *channelSelect = 0;
      return;
    case 0xd:
      *swizzleCode = 3;
      *channelSelect = 1;
      return;
    case 0xe:
      *swizzleCode = 3;
      *channelSelect = 2;
      return;
    case 0xf:
      *swizzleCode = 3;
      *channelSelect = 3;
      return;
    case 0x10:
      *swizzleCode = 0;
      *channelSelect = 4;
      return;
    case 0x11:
      *swizzleCode = 0;
      *channelSelect = 6;
      return;
    case 0x12:
      *swizzleCode = 0;
      *channelSelect = 5;
      return;
    default:
      return;
    }
  }
  *swizzleCode = swizzleWord & 0xffffff7f;
  return;
}

/* psnEncodeHwProgram @ 0xbfed0 (2464 bytes) */
int psnEncodeHwProgram(psnProgram, rsWords, programImage)
  int psnProgram;
  uint *rsWords;
  uint *programImage;
{
  uint hwRecordHeader;
  uint signMask10;
  uint rsOutCount;
  uint signMaskE;
  ushort recShort1a;
  byte recByte15;
  byte recByte19;
  byte recByte17;
  byte recBytebB;
  byte recByte6B;
  byte recByte3d;
  byte recByte45;
  byte recByte13;
  byte recByte16;
  byte recByte12;
  byte recByte32;
  byte recByte11;
  byte recByte2e;
  byte recBytef;
  byte recByte3f;
  byte recBytee;
  uint instWord24_2;
  uint instWord14;
  uint instWord0;
  uint instWord28;
  uint instWord24;
  ushort instShort3_3;
  ushort instShort4_2;
  ushort instShort4;
  byte instBytef;
  byte instByte1_2;
  byte instByte1;
  byte prevScanInstByte2;
  byte instByte4;
  byte instByte2;
  byte instByte6;
  byte instByte5;
  byte instByte10;
  byte instBytec;
  uint *inst;
  int loopIndex;
  uint psnProgramWord8;
  ushort psnProgramShort22;
  ushort psnProgramShort28;
  ushort psnProgramShort12;
  byte recByte6;
  byte recByte7;
  byte recByte2d;
  byte recByte9;
  byte recByteb;
  byte recByte1d;
  byte recByte1e;
  byte recByte5;
  byte recByte5B;
  byte recByte41;
  byte recByte22;
  byte recByte23;
  byte recByte16B;
  byte recByte31;
  byte recByte2f;
  byte recByte3e;
  ushort instShort3;
  ushort recShort12;
  ushort recShort12B;
  ushort instShort7;
  ushort recShort1e;
  ushort instShort3_2;
  ushort instShort6;
  ushort recShorte;
  bool needEndRecord;
  uint hwWordC_f2;
  uint hwWordC_f5;
  uint hwWordC_f8;
  uint hwWordC_f15;
  uint hwWordC_f18;
  uint hwWordC_f21;
  uint hwWord10_f12;
  uint hwWord10_f14;
  uint hwWord10_f19;
  uint hwWord10_f21;
  uint hwWord14_f14;
  uint hwWord14_f17;
  uint hwWord14_f20;
  int *nextScanInst;
  uint rsWordPartial;
  uint hwWordC_f0;
  uint hwWord14_f12;
  uint rsOutIndex;
  uint hwWordC_f13;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  int *rsScanCur;
  undefined4 staleArgR8;
  int *scanInst;
  uint signMask12;
  uint rsOutIndexNext;
  int hwRecordCountEnd;
  uint signMask1a;
  uint signMask1e;
  int *prevScanInst;
  int endRecordOffset;
  uint signMask1c;
  uint firstAddrWord;
  int hwRecordIndex;
  int prevHwRecordIndex;
  byte depthWriteAccum;
  uint loopIndex2;
  uint *outCursor;
  uint fieldTemp0;
  uint fieldTemp1;
  uint fieldTemp2;
  uint fieldTemp3;
  uint *fieldTemp3Ptr;
  uint *fieldTemp1Ptr;
  uint *fieldTemp2Ptr;
  
  outCursor = programImage;
  ((int (*)())psnAnalyzeProgram)(psnProgram);
  if (0x10 < *(ushort *)(psnProgram + 0x18)) {
    return 0x80000014;
  }
  if (0x200 < (uint)*(ushort *)(psnProgram + 0x1a) + (uint)*(ushort *)(psnProgram + 0x1c) +
              (uint)*(ushort *)(psnProgram + 0x20)) {
    return 0x80000018;
  }
  if (0x7f < *(ushort *)(psnProgram + 0x22)) {
    return 0x80000012;
  }
  if (0xff < *(ushort *)(psnProgram + 0x24)) {
    return 0x80000013;
  }
  ((int (*)())psnPlanPhases)(psnProgram,1,outCursor,staleArgR6,staleArgR7,staleArgR8,(uint)*(ushort *)(psnProgram + 0x20));
  psnProgramWord8 = *(uint *)(psnProgram + 8);
  if ((*(int *)(psnProgram + 0x48) == 1) && (psnProgramWord8 != 0)) {
    scanInst = (int *)(psnProgram + 0x90);
    loopIndex2 = 1;
    nextScanInst = scanInst;
    rsOutIndex = 0;
    prevScanInst = (int *)(psnProgram + 0x48);
    do {
      rsScanCur = nextScanInst;
      rsOutIndexNext = rsOutIndex;
      if ((prevScanInst[2] & 0xff00ffU) != 0) {
        rsOutIndexNext = rsOutIndex + 1;
        rsWords[rsOutIndex + 1] = 0;
        prevScanInstByte2 = *(byte *)(prevScanInst + 2);
        rsWords[rsOutIndex + 1] = prevScanInstByte2 & 0xf;
        rsWordPartial = (*(byte *)((int)prevScanInst + 9) & 1) << 4 | prevScanInstByte2 & 0xf;
        rsWords[rsOutIndex + 1] = rsWordPartial;
        rsWordPartial = (*(byte *)((int)prevScanInst + 10) & 0xf) << 0xc | rsWordPartial;
        rsWords[rsOutIndex + 1] = rsWordPartial;
        rsWordPartial = (*(byte *)((int)prevScanInst + 0xb) & 3) << 0x10 | rsWordPartial;
        rsWords[rsOutIndex + 1] = rsWordPartial;
        rsWordPartial = (*(byte *)(prevScanInst + 3) & 1) << 0x19 | rsWordPartial;
        rsWords[rsOutIndex + 1] = rsWordPartial;
        rsWordPartial = (*(ushort *)(prevScanInst + 1) & 0x7f) << 5 | rsWordPartial;
        rsWords[rsOutIndex + 1] = rsWordPartial;
        rsWords[rsOutIndex + 1] = (*(ushort *)((int)prevScanInst + 6) & 0x7f) << 0x12 | rsWordPartial;
      }
      loopIndex2 = loopIndex2 + 1;
      if (*scanInst != 1) break;
      scanInst = scanInst + 0x12;
      nextScanInst = rsScanCur + 0x12;
      rsOutIndex = rsOutIndexNext;
      prevScanInst = rsScanCur;
    } while (loopIndex2 <= psnProgramWord8);
    rsOutCount = rsOutIndexNext & 0xff;
    if (rsOutIndexNext == 0) goto LAB_000c004c;
  }
  else {
    loopIndex2 = 1;
LAB_000c004c:
    rsOutCount = 1;
    rsWords[1] = 0;
  }
  rsOutCount = rsOutCount - 1 & 0xf;
  *rsWords = rsOutCount;
  *rsWords = (*(byte *)(psnProgram + 0xd) & 7) << 5 | rsOutCount;
  if (psnProgramWord8 < loopIndex2) {
    hwRecordIndex = 0;
    depthWriteAccum = 0;
    endRecordOffset = 0;
    hwRecordCountEnd = 1;
  }
  else {
    fieldTemp3Ptr = &fieldTemp3;
    fieldTemp2Ptr = &fieldTemp2;
    depthWriteAccum = 0;
    inst = (uint *)(loopIndex2 * 0x48 + psnProgram);
    fieldTemp1Ptr = &fieldTemp1;
    needEndRecord = true;
    loopIndex = 0;
    hwRecordIndex = 0;
    do {
      prevHwRecordIndex = hwRecordIndex;
      instWord0 = *inst;
      hwRecordHeader = 0;
      if (instWord0 < 5) {
        if (instWord0 < 3) {
          if (instWord0 == 2) {
            recShorte = *(ushort *)((int)inst + 0xe);
            instShort3 = *(ushort *)(inst + 3);
            needEndRecord = true;
            instWord14 = inst[5];
            recByte6 = *(byte *)((int)inst + 6);
            recByte7 = *(byte *)((int)inst + 7);
            instByte2 = *(byte *)(inst + 2);
            recByte9 = *(byte *)((int)inst + 9);
            recByteb = *(byte *)((int)inst + 0xb);
            recByte1d = *(byte *)((int)inst + 0x1d);
            recByte1e = *(byte *)((int)inst + 0x1e);
            instShort4_2 = *(ushort *)(inst + 4);
            recShort12B = *(ushort *)((int)inst + 0x12);
            instByte1_2 = *(byte *)(inst + 1);
            recByte5B = *(byte *)((int)inst + 5);
            *(uint *)(loopIndex + programImage[4] + 4) =
                 (*(byte *)((int)inst + 0x1b) & 1) << 0x19 |
                 (*(byte *)(inst + 7) & 1) << 0x1a |
                 (*(byte *)(inst + 6) & 1) << 0x1b |
                 (*(byte *)((int)inst + 0x1a) & 7) << 0x16 |
                 (*(byte *)((int)inst + 0x19) & 0xf) << 0x10;
            *(uint *)(loopIndex + programImage[4] + 8) =
                 (instWord14 & 0x3000000) << 6 |
                 (instWord14 & 0xc000000) << 2 |
                 instWord14 >> 2 & 0xc000000 |
                 instWord14 >> 6 & 0x3000000 |
                 instWord14 >> 2 & 0xc000 |
                 instWord14 >> 6 & 0x3000 |
                 instWord14 >> 10 & 0xc00 |
                 instWord14 >> 0xe & 0x300 |
                 (instShort3 & 0x4000) << 9 |
                 (instShort3 & 0x7f) << 0x10 | recShorte >> 7 & 0x80 | recShorte & 0x7f;
            hwRecordHeader = (recByte1e & 1) << 0xe |
                     (recByte1d & 7) << 0xb |
                     (recByteb & 1) << 10 |
                     (recByte9 & 1) << 7 |
                     (instByte2 & 1) << 0x16 |
                     (recByte7 & 7) << 0x19 |
                     (recByte6 & 1) << 6 | (recByte5B & 7) << 3 | (instByte1_2 & 1) << 2 | 3;
            *(uint *)(loopIndex + programImage[4] + 0xc) =
                 instWord14 << 0x1e |
                 (instWord14 & 0xc) << 0x1a |
                 (instWord14 & 0x30) << 0x16 |
                 (instWord14 & 0xc0) << 0x12 |
                 (instWord14 & 0x300) << 6 |
                 (instWord14 & 0xc00) << 2 |
                 instWord14 >> 2 & 0xc00 |
                 instWord14 >> 6 & 0x300 |
                 (recShort12B & 0x4000) << 9 |
                 (recShort12B & 0x7f) << 0x10 | instShort4_2 >> 7 & 0x80 | instShort4_2 & 0x7f;
            *(undefined4 *)(loopIndex + programImage[4] + 0x10) = 0;
            *(undefined4 *)(loopIndex + programImage[4] + 0x14) = 0;
          }
        }
        else {
          recShorte = *(ushort *)((int)inst + 0xe);
          signMaskE = 0xffffff80;
          hwRecordHeader = (*(byte *)(inst + 0x11) & 3) << 0x17 |
                   (*(byte *)((int)inst + 0x43) & 1) << 0x15 |
                   (*(byte *)(inst + 0xd) & 1) << 9 |
                   (*(byte *)((int)inst + 0x42) & 1) << 0x14 |
                   (*(byte *)((int)inst + 0x33) & 1) << 0x13 |
                   (*(byte *)((int)inst + 0x21) & 1) << 0x12 |
                   (*(byte *)((int)inst + 0x15) & 7) << 0xf |
                   (*(byte *)(inst + 8) & 1) << 0xe |
                   (*(byte *)(inst + 5) & 7) << 0xb |
                   (*(byte *)((int)inst + 10) & 1) << 8 |
                   (*(byte *)((int)inst + 9) & 1) << 7 |
                   (*(byte *)(inst + 2) & 1) << 0x16 |
                   (*(byte *)((int)inst + 7) & 7) << 0x19 |
                   (*(byte *)((int)inst + 6) & 1) << 6 |
                   (*(byte *)((int)inst + 5) & 7) << 3 |
                   (*(byte *)(inst + 1) & 1) << 2 | (uint)(instWord0 == 3);
          if ((recShorte & 0x2000) == 0) {
            signMaskE = 0;
          }
          instShort4 = *(ushort *)(inst + 4);
          signMask10 = 0xffffff80;
          if ((instShort4 & 0x2000) == 0) {
            signMask10 = 0;
          }
          recShort12 = *(ushort *)((int)inst + 0x12);
          signMask12 = 0xffffff80;
          if ((recShort12 & 0x2000) == 0) {
            signMask12 = 0;
          }
          recShort1a = *(ushort *)((int)inst + 0x1a);
          instBytec = *(byte *)(inst + 0xc);
          signMask1a = 0xffffff80;
          if ((recShort1a & 0x2000) == 0) {
            signMask1a = 0;
          }
          instShort7 = *(ushort *)(inst + 7);
          signMask1c = 0xffffff80;
          if ((instShort7 & 0x2000) == 0) {
            signMask1c = 0;
          }
          recShort1e = *(ushort *)((int)inst + 0x1e);
          signMask1e = 0xffffff80;
          if ((recShort1e & 0x2000) == 0) {
            signMask1e = 0;
          }
          fieldTemp3 = (uint)*(byte *)((int)inst + 0x2a);
          recByte3f = *(byte *)((int)inst + 0x3f);
          instWord24 = inst[9];
          fieldTemp2 = instWord24 >> 0x17 & 7;
          fieldTemp0 = instWord24 >> 0x1d;
          fieldTemp1 = instWord24 >> 0x1a & 7;
          ((int (*)())ilRemapSwizzleTriple)(fieldTemp3Ptr,&fieldTemp0,fieldTemp1Ptr,fieldTemp2Ptr);
          hwWordC_f0 = fieldTemp3 & 3;
          hwWordC_f2 = fieldTemp0 & 7;
          hwWordC_f5 = fieldTemp1 & 7;
          instWord24_2 = inst[9];
          hwWordC_f8 = fieldTemp2 & 7;
          fieldTemp3 = instWord24_2 >> 7 & 7;
          fieldTemp1 = instWord24_2 >> 0xd & 7;
          fieldTemp0 = instWord24_2 >> 10 & 7;
          fieldTemp2 = (uint)*(byte *)((int)inst + 0x2b);
          ((int (*)())ilRemapSwizzleTriple)(fieldTemp2Ptr,fieldTemp1Ptr,&fieldTemp0,fieldTemp3Ptr);
          recByte2d = *(byte *)((int)inst + 0x2d);
          recByte2e = *(byte *)((int)inst + 0x2e);
          recByte32 = *(byte *)((int)inst + 0x32);
          recByte16 = *(byte *)((int)inst + 0x16);
          recByte45 = *(byte *)((int)inst + 0x45);
          hwWordC_f13 = fieldTemp2 & 3;
          hwWordC_f15 = fieldTemp1 & 7;
          hwWordC_f18 = fieldTemp0 & 7;
          hwWordC_f21 = fieldTemp3 & 7;
          fieldTemp0 = (uint)*(byte *)((int)inst + 0x36);
          fieldTemp3 = (uint)*(byte *)((int)inst + 0x39);
          ((int (*)())ilRemapSwizzleSingle)(fieldTemp3Ptr,&fieldTemp0);
          hwWord10_f12 = fieldTemp3 & 3;
          hwWord10_f14 = fieldTemp0 & 7;
          fieldTemp3 = (uint)*(byte *)((int)inst + 0x37);
          fieldTemp0 = (uint)*(byte *)((int)inst + 0x3a);
          ((int (*)())ilRemapSwizzleSingle)(&fieldTemp0,fieldTemp3Ptr);
          instBytef = *(byte *)(inst + 0xf);
          recByte3d = *(byte *)((int)inst + 0x3d);
          instShort3_2 = *(ushort *)(inst + 3);
          recByte41 = *(byte *)((int)inst + 0x41);
          recByte22 = *(byte *)((int)inst + 0x22);
          instShort6 = *(ushort *)(inst + 6);
          hwWord10_f19 = fieldTemp0 & 3;
          recByte23 = *(byte *)((int)inst + 0x23);
          instByte10 = *(byte *)(inst + 0x10);
          hwWord10_f21 = fieldTemp3 & 7;
          recByte31 = *(byte *)((int)inst + 0x31);
          instWord28 = inst[10];
          fieldTemp0 = instWord28 >> 0x1d;
          fieldTemp2 = instWord28 >> 0x17 & 7;
          fieldTemp1 = instWord28 >> 0x1a & 7;
          fieldTemp3 = (uint)*(byte *)(inst + 0xb);
          ((int (*)())ilRemapSwizzleTriple)(fieldTemp3Ptr,&fieldTemp0,fieldTemp1Ptr,fieldTemp2Ptr);
          hwWord14_f12 = fieldTemp3 & 3;
          hwWord14_f14 = fieldTemp0 & 7;
          hwWord14_f17 = fieldTemp1 & 7;
          fieldTemp0 = (uint)*(byte *)(inst + 0xe);
          hwWord14_f20 = fieldTemp2 & 7;
          fieldTemp2 = (uint)*(byte *)((int)inst + 0x3b);
          ((int (*)())ilRemapSwizzleSingle)(fieldTemp2Ptr,&fieldTemp0);
          needEndRecord = false;
          recByte2f = *(byte *)((int)inst + 0x2f);
          recByte3e = *(byte *)((int)inst + 0x3e);
          *(uint *)(loopIndex + programImage[4] + 4) =
               (uint)instBytec << 0x1e |
               (recShort12 & 0x4000) << 0xf |
               (recShort12 & 0x8000) << 0xd |
               (signMask12 & 0xff | recShort12 & 0x7f) << 0x14 |
               (instShort4 & 0x4000) << 5 |
               (instShort4 & 0x8000) << 3 |
               (signMask10 & 0xff | instShort4 & 0x7f) << 10 |
               recShorte >> 5 & 0x200 | recShorte >> 7 & 0x100 | signMaskE & 0xff | recShorte & 0x7f;
          *(uint *)(loopIndex + programImage[4] + 8) =
               (uint)recByte3f << 0x1e |
               (recShort1e & 0x4000) << 0xf |
               (recShort1e & 0x8000) << 0xd |
               (signMask1e & 0xff | recShort1e & 0x7f) << 0x14 |
               (instShort7 & 0x4000) << 5 |
               (instShort7 & 0x8000) << 3 |
               (signMask1c & 0xff | instShort7 & 0x7f) << 10 |
               recShort1a >> 5 & 0x200 | recShort1a >> 7 & 0x100 | signMask1a & 0xff | recShort1a & 0x7f;
          *(uint *)(loopIndex + programImage[4] + 0xc) =
               (uint)recByte45 << 0x1f |
               (recByte16 & 3) << 0x1d |
               (recByte32 & 7) << 0x1a |
               (recByte2e & 3) << 0x18 |
               (recByte2d & 3) << 0xb |
               hwWordC_f21 << 0x15 |
               hwWordC_f18 << 0x12 |
               hwWordC_f15 << 0xf | hwWordC_f13 << 0xd | hwWordC_f8 << 8 | hwWordC_f5 << 5 | hwWordC_f2 << 2 | hwWordC_f0;
          *(uint *)(loopIndex + programImage[4] + 0x10) =
               instShort6 >> 3 & 0x800 |
               (instShort6 & 0x7f) << 4 |
               instByte10 & 0xf |
               (uint)recByte23 << 0x1f |
               (recByte22 & 3) << 0x1d |
               (recByte41 & 7) << 0x1a |
               (recByte3d & 3) << 0x18 |
               (instBytef & 3) << 0x11 | hwWord10_f21 << 0x15 | hwWord10_f19 << 0x13 | hwWord10_f14 << 0xe | hwWord10_f12 << 0xc
          ;
          *(uint *)(loopIndex + programImage[4] + 0x14) =
               (uint)recByte3e << 0x1e |
               (recByte2f & 3) << 0x17 |
               (fieldTemp0 & 7) << 0x1b |
               (fieldTemp2 & 3) << 0x19 |
               hwWord14_f20 << 0x14 |
               hwWord14_f17 << 0x11 |
               hwWord14_f14 << 0xe |
               hwWord14_f12 << 0xc | instShort3_2 >> 3 & 0x800 | (instShort3_2 & 0x7f) << 4 | recByte31 & 0xf;
          if (*inst == 3) {
            depthWriteAccum = depthWriteAccum | *(byte *)((int)inst + 0x23);
          }
        }
      }
      else if (instWord0 == 5) {
        recBytee = *(byte *)((int)inst + 0xe);
        recBytef = *(byte *)((int)inst + 0xf);
        needEndRecord = false;
        instByte4 = *(byte *)(inst + 4);
        recByte11 = *(byte *)((int)inst + 0x11);
        recByte12 = *(byte *)((int)inst + 0x12);
        recByte13 = *(byte *)((int)inst + 0x13);
        instByte1 = *(byte *)(inst + 1);
        recByte5 = *(byte *)((int)inst + 5);
        recByte6B = *(byte *)((int)inst + 6);
        recBytebB = *(byte *)((int)inst + 0xb);
        recByte17 = *(byte *)((int)inst + 0x17);
        instShort3_3 = *(ushort *)(inst + 3);
        recByte19 = *(byte *)((int)inst + 0x19);
        recByte16B = *(byte *)((int)inst + 0x16);
        instByte5 = *(byte *)(inst + 5);
        instByte6 = *(byte *)(inst + 6);
        recByte15 = *(byte *)((int)inst + 0x15);
        *(undefined4 *)(programImage[4] + loopIndex + 4) = 0;
        hwRecordHeader = (recBytebB & 1) << 10 | (recByte6B & 1) << 6 | (recByte5 & 7) << 3 | (instByte1 & 1) << 2 | 2;
        *(uint *)(programImage[4] + loopIndex + 8) =
             (recByte16B & 1) << 0x1c |
             (recByte15 & 3) << 0x1a |
             (instByte5 & 3) << 0x18 |
             (recByte13 & 0x1f) << 0x10 |
             (uint)recByte12 << 8 | (recByte11 & 3) << 6 | (instByte4 & 1) << 5 | (recBytef & 1) << 4 | recBytee & 7;
        *(uint *)(programImage[4] + loopIndex + 0xc) =
             (uint)recByte19 << 0x1f | (instShort3_3 & 0x1ff) << 0x10 | (instByte6 & 0x1f) << 8 | recByte17 & 0x1f;
        *(undefined4 *)(programImage[4] + loopIndex + 0x10) = 0;
        *(undefined4 *)(programImage[4] + loopIndex + 0x14) = 0;
      }
      loopIndex2 = loopIndex2 + 1;
      hwRecordIndex = prevHwRecordIndex + 1;
      inst = inst + 0x12;
      *(uint *)(programImage[4] + loopIndex) = hwRecordHeader;
      loopIndex = loopIndex + 0x18;
    } while (loopIndex2 <= psnProgramWord8);
    hwRecordCountEnd = hwRecordIndex;
    if (!needEndRecord) goto LAB_000c07dc;
    endRecordOffset = hwRecordIndex * 0x18;
    hwRecordCountEnd = prevHwRecordIndex + 2;
  }
  *(undefined4 *)(programImage[4] + endRecordOffset) = 0;
  *(undefined4 *)(endRecordOffset + programImage[4] + 4) = 0;
  *(undefined4 *)(endRecordOffset + programImage[4] + 8) = 0;
  *(undefined4 *)(endRecordOffset + programImage[4] + 0xc) = 0;
  *(undefined4 *)(endRecordOffset + programImage[4] + 0x10) = 0;
  *(undefined4 *)(endRecordOffset + programImage[4] + 0x14) = 0;
  *(uint *)(endRecordOffset + programImage[4]) = *(uint *)(endRecordOffset + programImage[4]) & 0xfffffffc | 1;
  *(uint *)(endRecordOffset + programImage[4]) = *(uint *)(endRecordOffset + programImage[4]) | 4;
  if ((hwRecordIndex != 0) && ((uint)*(ushort *)(psnProgram + 0x12) == hwRecordIndex - 1U)) {
    *(short *)(psnProgram + 0x12) = (short)hwRecordIndex;
  }
LAB_000c07dc:
  programImage[2] = 0;
  programImage[3] = (hwRecordCountEnd + -1) * 0x10000 & 0x1ff0000;
  firstAddrWord = *(ushort *)(psnProgram + 0x10) & 0x1ff;
  programImage[2] = firstAddrWord;
  psnProgramShort12 = *(ushort *)(psnProgram + 0x12);
  programImage[1] = 0;
  programImage[2] = (psnProgramShort12 & 0x1ff) << 0x10 | firstAddrWord;
  psnProgramShort28 = *(ushort *)(psnProgram + 0x28);
  *programImage = 0;
  programImage[1] = (uint)psnProgramShort28 << 0x1f;
  psnProgramShort22 = *(ushort *)(psnProgram + 0x22);
  programImage[5] = (uint)(depthWriteAccum != 0);
  *programImage = psnProgramShort22 & 0x7f;
  return 0;
}

/* psnDecRecomputeSourceUsage @ 0xc0880 (1832 bytes) */
int psnDecRecomputeSourceUsage(entry)
  int entry;
{
  int propagateReadMaskPtr;
  int slotByteOffset;
  uint readSlot;
  ushort previousReadMask;
  bool loopContinue2;
  bool loopContinue;
  ushort maskWord;
  ushort alphaReadComponentBits;
  ushort readComponentBits;
  ushort writeAndOutputMask;
  int halfCursor;
  uint sourceIndex;
  uint halfFlags;
  bool opcodeInSet1f1;
  bool componentModeIs300;
  bool slotIsNotSrcp;
  ushort opcode;
  ushort referencedSrcpOp;
  ushort sourceSelect;
  uint writeAndOutputMaskWide;
  undefined4 defaultScaleBits;
  uint uVar9;
  int referencedHalfIndex;
  uint replicatedMask;
  int sourceFlagsBase;
  uint componentSelect;
  int half;
  uint readComponents;
  ushort sourceSwizzle;
  int readMaskPtr;
  uint slotComponentMask;
  ushort *sourceFlagsPtr;
  int srcpReadMaskPtr;
  undefined4 *usageCursor;
  ushort componentMode;
  uint addressSlot;
  int halfIndex;
  int copyHalfNumber;
  int nextHalfIndex;
  uint srcpSelectsUsed;
  int propagateHalf;
  
  propagateHalf = 0;
  copyHalfNumber = 0;
  srcpSelectsUsed = 0;
  halfIndex = 0;
  do {
    half = entry + halfIndex * 0x40;
    opcode = *(ushort *)(half + 0x28);
    *(undefined4 *)(half + 0x14) = 0;
    *(undefined4 *)(half + 0x20) = 0;
    *(undefined4 *)(half + 0x1c) = 0;
    *(undefined4 *)(half + 0x24) = 0;
    *(undefined4 *)(half + 0x18) = 0;
    halfFlags = *(uint *)(half + 0x30) & 0xffffff89;
    *(uint *)(half + 0x30) = halfFlags;
    if (opcode == 2) {
      *(uint *)(half + 0x30) = halfFlags | 0x52;
      propagateHalf = half;
    }
    nextHalfIndex = halfIndex + 1;
    if (opcode == 0xd) {
      copyHalfNumber = nextHalfIndex;
    }
    opcodeInSet1f1 = (1 << ((int)(short)opcode & 0x3fU) & 0x1f1U) != 0;
    sourceIndex = 0;
    sourceFlagsBase = half;
    do {
      sourceSelect = *(ushort *)(half + 8 + sourceIndex * 4);
      sourceSwizzle = *(ushort *)(half + 8 + sourceIndex * 4 + 2);
      addressSlot = sourceSelect & 3;
      componentMode = sourceSwizzle & 0x300;
      componentSelect = sourceSwizzle & 0x1f;
      componentModeIs300 = componentMode == 0x300;
      if (componentModeIs300) {
        *(uint *)(half + 0x30) = *(uint *)(half + 0x30) | 0x10;
      }
      if ((opcode == 3) && ((componentSelect | 0xfffffff9) == 0xffffffff)) {
        slotComponentMask = (1 < sourceIndex) + 3;
        if (componentMode == 0x200) {
          slotComponentMask = slotComponentMask * 4 & 4 | slotComponentMask >> 1;
        }
        else if (componentModeIs300) {
          slotComponentMask = slotComponentMask * 8 & 8 | slotComponentMask * 2 & 4 | slotComponentMask >> 1 & 2;
        }
        else if (componentMode == 0x100) {
          slotComponentMask = slotComponentMask * 2 & 6 | slotComponentMask >> 2;
        }
        componentSelect = slotComponentMask & componentSelect;
      }
      *(undefined2 *)(sourceFlagsBase + 0x34) = 0;
      sourceFlagsPtr = (ushort *)(sourceFlagsBase + 0x34);
      if (((componentSelect & 0x10) == 0) &&
         (((sourceSwizzle & 0x300) != 0 ||
          (((*(ushort *)(half + 6) | *(ushort *)(half + 2)) & 0xffef & ~componentSelect) != 0)))) {
        *(undefined2 *)(sourceFlagsBase + 0x34) = 8;
      }
      slotIsNotSrcp = addressSlot != 3;
      if (slotIsNotSrcp) {
        readSlot = addressSlot;
        if (componentSelect == 0x11) {
          *sourceFlagsPtr = *sourceFlagsPtr | 4;
        }
        else if (componentSelect == 0x12) {
          *sourceFlagsPtr = *sourceFlagsPtr | 2;
        }
        else if (componentSelect == 0x10) {
          *sourceFlagsPtr = *sourceFlagsPtr | 1;
        }
      }
      else {
        srcpSelectsUsed = sourceSelect & 0x300 | srcpSelectsUsed;
        referencedHalfIndex = ((sourceSelect & 0x300) >> 8) - 1;
        referencedSrcpOp = *(ushort *)(referencedHalfIndex * 0x40 + entry + 0x2a);
        if (halfIndex != referencedHalfIndex) {
          *(uint *)(half + 0x30) = *(uint *)(half + 0x30) | 0x20;
        }
        addressSlot = (uint)(referencedSrcpOp - 1 < 2);
        *sourceFlagsPtr = *sourceFlagsPtr | 0x10;
        readSlot = 0;
      }
      if ((sourceSwizzle & 0x1000) != 0) {
        *sourceFlagsPtr = *sourceFlagsPtr | 0x20;
      }
      if ((sourceSwizzle & 0x2000) != 0) {
        *sourceFlagsPtr = *sourceFlagsPtr | 0x40;
      }
      if ((halfIndex == 1) && (sourceIndex == 2)) {
        propagateHalf = 0;
      }
      if ((sourceSelect & 0x100) != 0) {
        readComponents = componentSelect & 7;
        if ((readComponents | 0xfffffff9) == 0xffffffff) {
          writeAndOutputMask = *(ushort *)(half + 6) | *(ushort *)(half + 2);
          writeAndOutputMaskWide = (uint)writeAndOutputMask;
          replicatedMask = writeAndOutputMaskWide & 0xffef;
          if (componentMode == 0x200) {
            replicatedMask = (writeAndOutputMaskWide & 1) << 2 | writeAndOutputMask >> 1 & 3;
          }
          else if (componentModeIs300) {
            replicatedMask = (writeAndOutputMaskWide & 2) << 1 | writeAndOutputMask >> 1 & 2;
          }
          else if (componentMode == 0x100) {
            replicatedMask = (writeAndOutputMaskWide & 3) << 1 | writeAndOutputMask >> 2 & 1;
          }
          if ((opcode < 9) && (opcodeInSet1f1)) {
            readComponents = readComponents & replicatedMask;
          }
        }
        slotByteOffset = readSlot * 2;
        readMaskPtr = slotByteOffset + half;
        readComponentBits = (ushort)readComponents;
        *(ushort *)(readMaskPtr + 0x14) = readComponentBits | *(ushort *)(readMaskPtr + 0x14);
        if (propagateHalf != 0) {
          *(ushort *)(slotByteOffset + propagateHalf + 0x14) = readComponentBits | *(ushort *)(slotByteOffset + propagateHalf + 0x14);
        }
        if (!slotIsNotSrcp) {
          srcpReadMaskPtr = addressSlot * 2 + half;
          *(ushort *)(readMaskPtr + 0x20) = readComponentBits | *(ushort *)(readMaskPtr + 0x20);
          *(ushort *)(srcpReadMaskPtr + 0x14) = readComponentBits | *(ushort *)(srcpReadMaskPtr + 0x14);
          *(ushort *)(srcpReadMaskPtr + 0x20) = readComponentBits | *(ushort *)(srcpReadMaskPtr + 0x20);
          if (propagateHalf != 0) {
            propagateReadMaskPtr = addressSlot * 2 + propagateHalf;
            maskWord = *(ushort *)(propagateReadMaskPtr + 0x14);
            *(ushort *)(slotByteOffset + propagateHalf + 0x20) = readComponentBits | *(ushort *)(slotByteOffset + propagateHalf + 0x20);
            *(ushort *)(propagateReadMaskPtr + 0x14) = readComponentBits | maskWord;
            *(ushort *)(propagateReadMaskPtr + 0x20) = readComponentBits | *(ushort *)(propagateReadMaskPtr + 0x20);
          }
        }
      }
      if ((sourceSelect & 0x200) != 0) {
        alphaReadComponentBits = (ushort)componentSelect & 8;
        if ((((componentModeIs300) && (opcode < 9)) && (opcodeInSet1f1)) &&
           ((~(*(ushort *)(half + 6) | *(ushort *)(half + 2)) & 1) != 0)) {
          alphaReadComponentBits = 0;
        }
        slotByteOffset = readSlot * 2;
        readMaskPtr = slotByteOffset + half;
        *(ushort *)(readMaskPtr + 0x1a) = alphaReadComponentBits | *(ushort *)(readMaskPtr + 0x1a);
        if (propagateHalf != 0) {
          *(ushort *)(slotByteOffset + propagateHalf + 0x1a) = alphaReadComponentBits | *(ushort *)(slotByteOffset + propagateHalf + 0x1a);
        }
        if (!slotIsNotSrcp) {
          srcpReadMaskPtr = addressSlot * 2 + half;
          *(ushort *)(readMaskPtr + 0x24) = alphaReadComponentBits | *(ushort *)(readMaskPtr + 0x24);
          *(ushort *)(srcpReadMaskPtr + 0x1a) = alphaReadComponentBits | *(ushort *)(srcpReadMaskPtr + 0x1a);
          *(ushort *)(srcpReadMaskPtr + 0x24) = alphaReadComponentBits | *(ushort *)(srcpReadMaskPtr + 0x24);
          if (propagateHalf != 0) {
            propagateReadMaskPtr = addressSlot * 2 + propagateHalf;
            previousReadMask = *(ushort *)(propagateReadMaskPtr + 0x1a);
            *(ushort *)(slotByteOffset + propagateHalf + 0x24) = alphaReadComponentBits | *(ushort *)(slotByteOffset + propagateHalf + 0x24);
            *(ushort *)(propagateReadMaskPtr + 0x1a) = alphaReadComponentBits | previousReadMask;
            *(ushort *)(propagateReadMaskPtr + 0x24) = alphaReadComponentBits | *(ushort *)(propagateReadMaskPtr + 0x24);
          }
        }
      }
      loopContinue2 = sourceIndex != 2;
      sourceFlagsBase = sourceFlagsBase + 2;
      sourceIndex = sourceIndex + 1;
    } while (loopContinue2);
    halfIndex = nextHalfIndex;
  } while (nextHalfIndex != 2);
  if (copyHalfNumber == 1) {
    *(undefined4 *)(entry + 0x14) = *(undefined4 *)(entry + 0x54);
    *(undefined4 *)(entry + 0x20) = *(undefined4 *)(entry + 0x60);
    *(undefined4 *)(entry + 0x24) = *(undefined4 *)(entry + 100);
    *(undefined4 *)(entry + 0x1c) = *(undefined4 *)(entry + 0x5c);
    *(undefined4 *)(entry + 0x18) = *(undefined4 *)(entry + 0x58);
    *(uint *)(entry + 0x30) = *(uint *)(entry + 0x30) | 4;
  }
  else if (copyHalfNumber == 2) {
    *(undefined4 *)(entry + 0x54) = *(undefined4 *)(entry + 0x14);
    *(undefined4 *)(entry + 0x60) = *(undefined4 *)(entry + 0x20);
    *(undefined4 *)(entry + 100) = *(undefined4 *)(entry + 0x24);
    *(undefined4 *)(entry + 0x5c) = *(undefined4 *)(entry + 0x1c);
    *(undefined4 *)(entry + 0x58) = *(undefined4 *)(entry + 0x18);
    *(uint *)(entry + 0x70) = *(uint *)(entry + 0x70) | 4;
  }
  halfIndex = 0;
  halfCursor = entry;
  do {
    if ((*(short *)(halfCursor + 2) == 0 && *(short *)(halfCursor + 6) == 0) &&
       ((*(uint *)(halfCursor + 0x30) & 1) == 0)) {
      *(uint *)(halfCursor + 0x30) = *(uint *)(halfCursor + 0x30) & 0xfffffffb;
    }
    loopContinue = halfIndex != 1;
    halfCursor = halfCursor + 0x40;
    halfIndex = halfIndex + 1;
  } while (loopContinue);
  halfIndex = 0;
  usageCursor = (undefined4 *)(entry + 0x14);
  halfCursor = entry;
  do {
    halfIndex = halfIndex + 1;
    if ((srcpSelectsUsed & halfIndex * 0x100) == 0) {
      *(undefined2 *)((int)usageCursor + 0x16) = 0;
    }
    if ((*(short *)((int)usageCursor + -0x12) == 0 && *(short *)((int)usageCursor + -0xe) == 0) &&
       (uVar9 = usageCursor[7], (uVar9 & 1) == 0)) {
      usageCursor[4] = 0;
      *usageCursor = 0;
      usageCursor[1] = 0;
      usageCursor[2] = 0;
      usageCursor[7] = uVar9 & 0xfffffff7;
      usageCursor[3] = 0;
      usageCursor[6] = 0x3f800000;
      if ((*(uint *)(halfCursor + 0x70) & 6) == 0) {
        *(undefined2 *)(usageCursor + 9) = 1;
        *(undefined2 *)((int)usageCursor + 0x22) = 1;
        *(undefined2 *)(usageCursor + 8) = 1;
        usageCursor[7] = uVar9 & 0xffffffe5;
        defaultScaleBits = (*(unsigned int *)&DAT_001dbf94);
        *(undefined2 *)(usageCursor + 5) = 0;
        usageCursor[-3] = defaultScaleBits;
        usageCursor[-1] = defaultScaleBits;
        usageCursor[-2] = defaultScaleBits;
      }
    }
    usageCursor = usageCursor + 0x10;
    halfCursor = halfCursor + -0x40;
  } while (halfIndex != 2);
  halfIndex = 0;
  halfCursor = entry;
  do {
    if (((*(short *)(halfCursor + 2) != 0 || *(short *)(halfCursor + 6) != 0) ||
        ((*(uint *)(halfCursor + 0x30) & 1) != 0)) &&
       ((*(short *)(entry + 0x1a) != 0 || *(short *)(entry + 0x1c) != 0) ||
        *(short *)(entry + 0x1e) != 0)) {
      *(uint *)(halfCursor + 0x30) = *(uint *)(halfCursor + 0x30) | 2;
    }
    loopContinue = halfIndex != 1;
    halfCursor = halfCursor + 0x40;
    entry = entry + 0x3a;
    halfIndex = halfIndex + 1;
  } while (loopContinue);
  return;
}

/* psnDecCanonicalizeEntry @ 0xc0fd0 (1936 bytes) */
int psnDecCanonicalizeEntry(entry, unusedArgR4, unusedArgR5, unusedArgR6, oldAddressOffset, unusedArgR8, sourceSwizzlePtr, unusedArgR10)
  int entry;
  undefined4 unusedArgR4;
  undefined4 unusedArgR5;
  undefined4 unusedArgR6;
  undefined4 oldAddressOffset;
  undefined4 unusedArgR8;
  undefined4 sourceSwizzlePtr;
  undefined4 unusedArgR10;
{
  ushort maskWord;
  ushort componentMode;
  undefined4 defaultScaleBits;
  uint readSlot;
  uint slotComponentMask;
  uint addressSlot;
  ushort alphaReadComponentBits;
  ushort readComponentBits;
  ushort writeAndOutputMask;
  ushort sourceSwizzle;
  uint srcpSelectsUsed;
  uint componentSelect;
  ushort previousReadMask;
  ushort sourceSelect;
  int slotByteOffset;
  int halfCursor;
  int copyHalfNumber;
  int halfIndex;
  int half;
  int propagateReadMaskPtr;
  int propagateHalf;
  bool opcodeInSet1f1;
  bool componentModeIs300;
  ushort source2FlagsB;
  undefined4 defaultOperandWord2;
  undefined4 swappedSourceWord;
  uint maskWithoutBit4;
  uint writeAndOutputMaskInt;
  uint halfFlags;
  uint rewriteSelectKey;
  ushort swizzleSelect;
  ushort sourceSwizzleOfSlot;
  ushort source0Flags;
  uint lastRestrictMask;
  ushort swizzleWordAtSlot;
  ushort writeAndOutputMaskBits;
  ushort source1Flags;
  int halfOffsetCursor;
  int groupIndex;
  int peepholeHalf;
  int groupUsagePtr;
  int sourceByteOffset;
  int source0Word;
  int sourceSlotCursor;
  int sourceSlots;
  int source2Word;
  int slotIndex;
  bool entryChanged;
  bool loopContinue;
  bool slotIsNotSrcp;
  bool loopContinue2;
  bool selectsRewritten;
  float outputScale;
  ushort referencedSrcpOp;
  short thirdSlotAddress;
  uint writeAndOutputMaskWide;
  int referencedHalfIndex;
  uint replicatedMask;
  int sourceSlotPtr;
  int sourceFlagsBase;
  ushort source2Flags;
  uint uVar13;
  ushort opcode;
  uint readComponents;
  ushort source1FlagsOld;
  uint groupNumber;
  int readMaskPtr;
  uint uVar19;
  uint oldHalfFlags;
  uint swizzleMode;
  ushort *sourceFlagsPtr;
  int srcpReadMaskPtr;
  undefined4 *usageCursor;
  int sourceCounter;
  short *usageWordPtr;
  ushort source0FlagsNew;
  int halfByteOffset;
  undefined4 defaultOperandWord;
  int groupSlots;
  int nextHalfIndex;
  
  selectsRewritten = false;
  groupNumber = 1;
  groupSlots = entry;
  do {
    if ((*(short *)(groupSlots + 0x82) != -1) &&
       (*(short *)(groupSlots + 0x80) == *(short *)(groupSlots + 0x82))) {
      halfByteOffset = 0;
      rewriteSelectKey = (groupNumber & 0xff) << 8 | 1;
      do {
        sourceSlotPtr = entry + halfByteOffset;
        sourceCounter = 0;
        do {
          if (*(ushort *)(sourceSlotPtr + 8) == rewriteSelectKey) {
            *(ushort *)(sourceSlotPtr + 8) = (ushort)rewriteSelectKey ^ 1;
            selectsRewritten = true;
          }
          loopContinue2 = sourceCounter != 2;
          sourceSlotPtr = sourceSlotPtr + 4;
          sourceCounter = sourceCounter + 1;
        } while (loopContinue2);
        loopContinue2 = halfByteOffset != 0x40;
        halfByteOffset = halfByteOffset + 0x40;
      } while (loopContinue2);
    }
    thirdSlotAddress = *(short *)(groupSlots + 0x84);
    if (thirdSlotAddress != -1) {
      if (*(short *)(groupSlots + 0x80) == thirdSlotAddress) {
        halfByteOffset = 0;
        rewriteSelectKey = (groupNumber & 0xff) << 8 | 2;
        do {
          sourceSlotPtr = entry + halfByteOffset;
          sourceCounter = 0;
          do {
            if (*(ushort *)(sourceSlotPtr + 8) == rewriteSelectKey) {
              *(ushort *)(sourceSlotPtr + 8) = (ushort)rewriteSelectKey ^ 2;
              selectsRewritten = true;
            }
            loopContinue2 = sourceCounter != 2;
            sourceSlotPtr = sourceSlotPtr + 4;
            sourceCounter = sourceCounter + 1;
          } while (loopContinue2);
          loopContinue2 = halfByteOffset != 0x40;
          halfByteOffset = halfByteOffset + 0x40;
        } while (loopContinue2);
      }
      else if (*(short *)(groupSlots + 0x82) == thirdSlotAddress) {
        halfByteOffset = 0;
        rewriteSelectKey = (groupNumber & 0xff) << 8 | 2;
        do {
          sourceSlotPtr = entry + halfByteOffset;
          sourceCounter = 0;
          do {
            if (*(ushort *)(sourceSlotPtr + 8) == rewriteSelectKey) {
              *(ushort *)(sourceSlotPtr + 8) = (ushort)rewriteSelectKey ^ 3;
              selectsRewritten = true;
            }
            loopContinue2 = sourceCounter != 2;
            sourceSlotPtr = sourceSlotPtr + 4;
            sourceCounter = sourceCounter + 1;
          } while (loopContinue2);
          loopContinue2 = halfByteOffset != 0x40;
          halfByteOffset = halfByteOffset + 0x40;
        } while (loopContinue2);
      }
    }
    loopContinue2 = groupNumber != 2;
    groupSlots = groupSlots + 6;
    groupNumber = groupNumber + 1;
  } while (loopContinue2);
  if (selectsRewritten) {
    ((int (*)())psnDecRecomputeSourceUsage)(entry);
    groupIndex = 0;
    groupUsagePtr = entry + 0x10;
    do {
      usageWordPtr = (short *)(groupUsagePtr + 4);
      slotIndex = 0;
      do {
        if (*usageWordPtr == 0 && usageWordPtr[0x20] == 0) {
          usageWordPtr[0x36] = -1;
        }
        loopContinue = slotIndex != 2;
        usageWordPtr = usageWordPtr + 1;
        slotIndex = slotIndex + 1;
      } while (loopContinue);
      loopContinue = groupIndex != 1;
      groupUsagePtr = groupUsagePtr + 6;
      groupIndex = groupIndex + 1;
    } while (loopContinue);
  }
  entryChanged = false;
  lastRestrictMask = 0;
  halfOffsetCursor = 0;
  do {
    peepholeHalf = halfOffsetCursor + entry;
    oldHalfFlags = *(uint *)(peepholeHalf + 0x30);
    halfFlags = oldHalfFlags & 0xffff00ff;
    *(uint *)(peepholeHalf + 0x30) = halfFlags;
    if ((*(ushort *)(peepholeHalf + 2) != 0 || *(ushort *)(peepholeHalf + 6) != 0) || ((oldHalfFlags & 1) != 0)) {
      opcode = *(ushort *)(peepholeHalf + 0x28);
      if ((opcode == 5) &&
         ((*(short *)(peepholeHalf + 8) == *(short *)(peepholeHalf + 0xc) &&
          ((*(ushort *)(peepholeHalf + 10) ^ *(ushort *)(peepholeHalf + 0xe)) == 0x1000)))) {
        opcode = 0;
        *(undefined2 *)(peepholeHalf + 0x28) = 0;
        entryChanged = true;
        *(undefined2 *)(peepholeHalf + 0x36) = 2;
        *(ushort *)(peepholeHalf + 10) = *(ushort *)(peepholeHalf + 10) & 0xefff | 0x2000;
        *(ushort *)(peepholeHalf + 0x34) = *(ushort *)(peepholeHalf + 0x34) & 0xffdf | 0x40;
        defaultOperandWord = (*(unsigned int *)&DAT_001dbf90);
        *(undefined2 *)(peepholeHalf + 0x38) = 1;
        *(undefined4 *)(peepholeHalf + 0xc) = defaultOperandWord;
        *(undefined4 *)(peepholeHalf + 0x10) = (*(unsigned int *)&DAT_001dbf94);
      }
      if ((((opcode == 7) && (*(short *)(peepholeHalf + 8) == *(short *)(peepholeHalf + 0xc))) &&
          (*(int *)(peepholeHalf + 8) == *(int *)(peepholeHalf + 0x10))) &&
         ((*(ushort *)(peepholeHalf + 10) ^ *(ushort *)(peepholeHalf + 0xe)) == 0x1000)) {
        opcode = 0;
        *(undefined2 *)(peepholeHalf + 0x28) = 0;
        entryChanged = true;
        *(undefined2 *)(peepholeHalf + 0x36) = 2;
        *(ushort *)(peepholeHalf + 10) = *(ushort *)(peepholeHalf + 10) & 0xefff | 0x2000;
        *(ushort *)(peepholeHalf + 0x34) = *(ushort *)(peepholeHalf + 0x34) & 0xffdf | 0x40;
        defaultOperandWord = (*(unsigned int *)&DAT_001dbf90);
        *(undefined2 *)(peepholeHalf + 0x38) = 1;
        *(undefined4 *)(peepholeHalf + 0xc) = defaultOperandWord;
        *(undefined4 *)(peepholeHalf + 0x10) = (*(unsigned int *)&DAT_001dbf94);
      }
      if (opcode == 0) {
        source1FlagsOld = *(ushort *)(peepholeHalf + 0x36);
        if (((*(ushort *)(peepholeHalf + 0x34) | source1FlagsOld) & 1) == 0) {
          source2Flags = *(ushort *)(peepholeHalf + 0x38);
        }
        else {
          source1FlagsOld = 2;
          entryChanged = true;
          *(undefined2 *)(peepholeHalf + 0x36) = 2;
          *(undefined2 *)(peepholeHalf + 0x34) = *(undefined2 *)(peepholeHalf + 0x38);
          *(undefined4 *)(peepholeHalf + 8) = *(undefined4 *)(peepholeHalf + 0x10);
          defaultOperandWord = (*(unsigned int *)&DAT_001dbf90);
          source2Flags = 1;
          *(undefined2 *)(peepholeHalf + 0x38) = 1;
          *(undefined4 *)(peepholeHalf + 0xc) = defaultOperandWord;
          *(undefined4 *)(peepholeHalf + 0x10) = (*(unsigned int *)&DAT_001dbf94);
        }
        source0FlagsNew = source1FlagsOld;
        if (((*(ushort *)(peepholeHalf + 8) & 0x300) == 0) && ((source1FlagsOld & 2) == 0)) {
          source0FlagsNew = *(ushort *)(peepholeHalf + 0x34);
          swappedSourceWord = *(undefined4 *)(peepholeHalf + 0xc);
          *(ushort *)(peepholeHalf + 0x34) = source1FlagsOld;
          *(ushort *)(peepholeHalf + 0x36) = source0FlagsNew;
          *(undefined4 *)(peepholeHalf + 0xc) = *(undefined4 *)(peepholeHalf + 8);
          *(undefined4 *)(peepholeHalf + 8) = swappedSourceWord;
        }
        if ((source0FlagsNew & 0x20) != 0) {
          *(ushort *)(peepholeHalf + 0x36) = source0FlagsNew ^ 0x20;
          *(ushort *)(peepholeHalf + 0x34) = *(ushort *)(peepholeHalf + 0x34) ^ 0x20;
          *(ushort *)(peepholeHalf + 10) = *(ushort *)(peepholeHalf + 10) ^ 0x1000;
          *(ushort *)(peepholeHalf + 0xe) = *(ushort *)(peepholeHalf + 0xe) ^ 0x1000;
        }
        if ((source2Flags & 1) == 0) {
          if (((*(ushort *)(peepholeHalf + 0x36) & 2) == 0) || ((*(ushort *)(peepholeHalf + 8) & 0x300) != 0)) {
            source0Word = *(int *)(peepholeHalf + 8);
            source2Word = *(int *)(peepholeHalf + 0x10);
          }
          else {
            source0Flags = *(ushort *)(peepholeHalf + 0x34);
            source0Word = *(int *)(peepholeHalf + 0x10);
            source2Word = *(int *)(peepholeHalf + 8);
            *(ushort *)(peepholeHalf + 0x34) = source2Flags;
            *(ushort *)(peepholeHalf + 0x38) = source0Flags;
            *(int *)(peepholeHalf + 0x10) = source2Word;
            *(int *)(peepholeHalf + 8) = source0Word;
            if ((source0Flags & 1) != 0) goto LAB_000c14b0;
          }
          if (((source0Word == source2Word) && ((*(ushort *)(peepholeHalf + 0x36) & 2) != 0)) &&
             (outputScale = *(float *)(peepholeHalf + 0x2c), outputScale < FLOAT_001aa100)) {
            entryChanged = true;
            *(undefined2 *)(peepholeHalf + 0x38) = 1;
            defaultOperandWord2 = (*(unsigned int *)&DAT_001dbf94);
            *(float *)(peepholeHalf + 0x2c) = outputScale + outputScale;
            *(undefined4 *)(peepholeHalf + 0x10) = defaultOperandWord2;
          }
        }
LAB_000c14b0:
        if (((oldHalfFlags & 8) == 0) && (*(float *)(peepholeHalf + 0x2c) == FLOAT_001aa0e8)) {
          source0Flags = *(ushort *)(peepholeHalf + 0x34);
          source1Flags = *(ushort *)(peepholeHalf + 0x36);
          if (((source0Flags | source1Flags) & 0x18) == 0) {
            source2FlagsB = *(ushort *)(peepholeHalf + 0x38);
            if (((source2FlagsB & 1) != 0) &&
               ((((source0Flags ^ source1Flags) & 0x40) == 0 || ((*(ushort *)(peepholeHalf + 0xc) & 0x300) == 0)))) {
              *(uint *)(peepholeHalf + 0x30) = halfFlags | 0x100;
              if ((source0Flags & 0x40) != 0) {
                *(uint *)(peepholeHalf + 0x30) = halfFlags | 0x1100;
              }
              if ((source0Flags & 0x20) == 0) {
                halfFlags = *(uint *)(peepholeHalf + 0x30);
              }
              else {
                halfFlags = *(uint *)(peepholeHalf + 0x30) | 0x800;
                *(uint *)(peepholeHalf + 0x30) = halfFlags;
              }
            }
          }
          else {
            source2FlagsB = *(ushort *)(peepholeHalf + 0x38);
          }
          if ((((source0Flags | source2FlagsB) & 0x18) == 0) && ((source1Flags & 2) != 0)) {
            halfFlags = halfFlags | 0x200;
            *(uint *)(peepholeHalf + 0x30) = halfFlags;
          }
          if ((halfFlags | 0xfffffcff) == 0xffffffff) {
            *(uint *)(peepholeHalf + 0x30) = halfFlags | 0x400;
          }
        }
      }
      if ((opcode < 9) && ((1 << ((int)(short)opcode & 0x3fU) & 0x1f1U) != 0)) {
        writeAndOutputMaskBits = *(ushort *)(peepholeHalf + 6) | *(ushort *)(peepholeHalf + 2);
        writeAndOutputMaskInt = (uint)writeAndOutputMaskBits;
        maskWithoutBit4 = writeAndOutputMaskInt & 0xffef;
        if (((maskWithoutBit4 - 1 & 0xffff) < 2) || (maskWithoutBit4 == 4)) {
          sourceSlots = peepholeHalf + 8;
          sourceByteOffset = 0;
          uVar13 = lastRestrictMask;
          do {
            sourceSwizzleOfSlot = *(ushort *)(sourceByteOffset + sourceSlots + 2);
            lastRestrictMask = uVar13;
            if ((sourceSwizzleOfSlot | 0xfffffff9) == 0xffffffff) {
              swizzleMode = sourceSwizzleOfSlot & 0x300;
              lastRestrictMask = (writeAndOutputMaskInt & 3) << 1 | (int)(writeAndOutputMaskInt & 4) >> 2;
              if (swizzleMode != 0x100) {
                if (swizzleMode < 0x101) {
                  lastRestrictMask = maskWithoutBit4;
                  if ((sourceSwizzleOfSlot & 0x300) != 0) {
                    lastRestrictMask = uVar13;
                  }
                }
                else if (swizzleMode == 0x200) {
                  lastRestrictMask = (writeAndOutputMaskInt & 1) << 2 | writeAndOutputMaskBits >> 1 & 3;
                }
                else {
                  lastRestrictMask = uVar13;
                  if (swizzleMode == 0x300) {
                    lastRestrictMask = (writeAndOutputMaskInt & 2) << 1 | (int)(writeAndOutputMaskInt & 4) >> 1 | (writeAndOutputMaskInt & 1) << 3;
                    if ((writeAndOutputMaskBits & 1) == 0) {
                      *(ushort *)(sourceByteOffset + sourceSlots) = *(ushort *)(sourceByteOffset + sourceSlots) & 0xfdff;
                    }
                    else {
                      *(ushort *)(sourceByteOffset + sourceSlots) = *(ushort *)(sourceByteOffset + sourceSlots) & 0xfeff;
                    }
                  }
                }
              }
              entryChanged = true;
              *(ushort *)(sourceByteOffset + sourceSlots + 2) = sourceSwizzleOfSlot & ~((ushort)lastRestrictMask ^ 0xf | 0x300);
            }
            loopContinue2 = sourceByteOffset != 8;
            sourceByteOffset = sourceByteOffset + 4;
            uVar13 = lastRestrictMask;
          } while (loopContinue2);
        }
      }
      sourceCounter = 0;
      sourceSlotCursor = peepholeHalf;
      do {
        swizzleWordAtSlot = *(ushort *)(sourceSlotCursor + 10);
        swizzleSelect = swizzleWordAtSlot & 0x1f;
        if (swizzleSelect == 0x10) {
          *(ushort *)(sourceSlotCursor + 10) = swizzleWordAtSlot & 0xcfff;
          *(ushort *)(peepholeHalf + 0x34) = *(ushort *)(peepholeHalf + 0x34) & 0xff9f;
        }
        else if ((0xf < swizzleSelect) && (swizzleSelect < 0x13)) {
          *(ushort *)(sourceSlotCursor + 10) = swizzleWordAtSlot & 0xdfff;
          *(ushort *)(peepholeHalf + 0x34) = *(ushort *)(peepholeHalf + 0x34) & 0xffbf;
        }
        loopContinue2 = sourceCounter != 2;
        sourceSlotCursor = sourceSlotCursor + 4;
        peepholeHalf = peepholeHalf + 2;
        sourceCounter = sourceCounter + 1;
      } while (loopContinue2);
    }
    loopContinue2 = halfOffsetCursor == 0x40;
    halfOffsetCursor = halfOffsetCursor + 0x40;
    if (loopContinue2) {
      if (entryChanged) {
        propagateHalf = 0;
        copyHalfNumber = 0;
        srcpSelectsUsed = 0;
        halfIndex = 0;
        do {
          half = entry + halfIndex * 0x40;
          opcode = *(ushort *)(half + 0x28);
          *(undefined4 *)(half + 0x14) = 0;
          *(undefined4 *)(half + 0x20) = 0;
          *(undefined4 *)(half + 0x1c) = 0;
          *(undefined4 *)(half + 0x24) = 0;
          *(undefined4 *)(half + 0x18) = 0;
          halfFlags = *(uint *)(half + 0x30) & 0xffffff89;
          *(uint *)(half + 0x30) = halfFlags;
          if (opcode == 2) {
            *(uint *)(half + 0x30) = halfFlags | 0x52;
            propagateHalf = half;
          }
          nextHalfIndex = halfIndex + 1;
          if (opcode == 0xd) {
            copyHalfNumber = nextHalfIndex;
          }
          opcodeInSet1f1 = (1 << ((int)(short)opcode & 0x3fU) & 0x1f1U) != 0;
          uVar19 = 0;
          sourceFlagsBase = half;
          do {
            sourceSelect = *(ushort *)(half + 8 + uVar19 * 4);
            sourceSwizzle = *(ushort *)(half + 8 + uVar19 * 4 + 2);
            addressSlot = sourceSelect & 3;
            componentMode = sourceSwizzle & 0x300;
            componentSelect = sourceSwizzle & 0x1f;
            componentModeIs300 = componentMode == 0x300;
            if (componentModeIs300) {
              *(uint *)(half + 0x30) = *(uint *)(half + 0x30) | 0x10;
            }
            if ((opcode == 3) && ((componentSelect | 0xfffffff9) == 0xffffffff)) {
              slotComponentMask = (1 < uVar19) + 3;
              if (componentMode == 0x200) {
                slotComponentMask = slotComponentMask * 4 & 4 | slotComponentMask >> 1;
              }
              else if (componentModeIs300) {
                slotComponentMask = slotComponentMask * 8 & 8 | slotComponentMask * 2 & 4 | slotComponentMask >> 1 & 2;
              }
              else if (componentMode == 0x100) {
                slotComponentMask = slotComponentMask * 2 & 6 | slotComponentMask >> 2;
              }
              componentSelect = slotComponentMask & componentSelect;
            }
            *(undefined2 *)(sourceFlagsBase + 0x34) = 0;
            sourceFlagsPtr = (ushort *)(sourceFlagsBase + 0x34);
            if (((componentSelect & 0x10) == 0) &&
               (((sourceSwizzle & 0x300) != 0 ||
                (((*(ushort *)(half + 6) | *(ushort *)(half + 2)) & 0xffef & ~componentSelect) != 0)))) {
              *(undefined2 *)(sourceFlagsBase + 0x34) = 8;
            }
            slotIsNotSrcp = addressSlot != 3;
            if (slotIsNotSrcp) {
              readSlot = addressSlot;
              if (componentSelect == 0x11) {
                *sourceFlagsPtr = *sourceFlagsPtr | 4;
              }
              else if (componentSelect == 0x12) {
                *sourceFlagsPtr = *sourceFlagsPtr | 2;
              }
              else if (componentSelect == 0x10) {
                *sourceFlagsPtr = *sourceFlagsPtr | 1;
              }
            }
            else {
              srcpSelectsUsed = sourceSelect & 0x300 | srcpSelectsUsed;
              referencedHalfIndex = ((sourceSelect & 0x300) >> 8) - 1;
              referencedSrcpOp = *(ushort *)(referencedHalfIndex * 0x40 + entry + 0x2a);
              if (halfIndex != referencedHalfIndex) {
                *(uint *)(half + 0x30) = *(uint *)(half + 0x30) | 0x20;
              }
              addressSlot = (uint)(referencedSrcpOp - 1 < 2);
              *sourceFlagsPtr = *sourceFlagsPtr | 0x10;
              readSlot = 0;
            }
            if ((sourceSwizzle & 0x1000) != 0) {
              *sourceFlagsPtr = *sourceFlagsPtr | 0x20;
            }
            if ((sourceSwizzle & 0x2000) != 0) {
              *sourceFlagsPtr = *sourceFlagsPtr | 0x40;
            }
            if ((halfIndex == 1) && (uVar19 == 2)) {
              propagateHalf = 0;
            }
            if ((sourceSelect & 0x100) != 0) {
              readComponents = componentSelect & 7;
              if ((readComponents | 0xfffffff9) == 0xffffffff) {
                writeAndOutputMask = *(ushort *)(half + 6) | *(ushort *)(half + 2);
                writeAndOutputMaskWide = (uint)writeAndOutputMask;
                replicatedMask = writeAndOutputMaskWide & 0xffef;
                if (componentMode == 0x200) {
                  replicatedMask = (writeAndOutputMaskWide & 1) << 2 | writeAndOutputMask >> 1 & 3;
                }
                else if (componentModeIs300) {
                  replicatedMask = (writeAndOutputMaskWide & 2) << 1 | writeAndOutputMask >> 1 & 2;
                }
                else if (componentMode == 0x100) {
                  replicatedMask = (writeAndOutputMaskWide & 3) << 1 | writeAndOutputMask >> 2 & 1;
                }
                if ((opcode < 9) && (opcodeInSet1f1)) {
                  readComponents = readComponents & replicatedMask;
                }
              }
              slotByteOffset = readSlot * 2;
              readMaskPtr = slotByteOffset + half;
              readComponentBits = (ushort)readComponents;
              *(ushort *)(readMaskPtr + 0x14) = readComponentBits | *(ushort *)(readMaskPtr + 0x14);
              if (propagateHalf != 0) {
                *(ushort *)(slotByteOffset + propagateHalf + 0x14) = readComponentBits | *(ushort *)(slotByteOffset + propagateHalf + 0x14);
              }
              if (!slotIsNotSrcp) {
                srcpReadMaskPtr = addressSlot * 2 + half;
                *(ushort *)(readMaskPtr + 0x20) = readComponentBits | *(ushort *)(readMaskPtr + 0x20);
                *(ushort *)(srcpReadMaskPtr + 0x14) = readComponentBits | *(ushort *)(srcpReadMaskPtr + 0x14);
                *(ushort *)(srcpReadMaskPtr + 0x20) = readComponentBits | *(ushort *)(srcpReadMaskPtr + 0x20);
                if (propagateHalf != 0) {
                  propagateReadMaskPtr = addressSlot * 2 + propagateHalf;
                  maskWord = *(ushort *)(propagateReadMaskPtr + 0x14);
                  *(ushort *)(slotByteOffset + propagateHalf + 0x20) = readComponentBits | *(ushort *)(slotByteOffset + propagateHalf + 0x20);
                  *(ushort *)(propagateReadMaskPtr + 0x14) = readComponentBits | maskWord;
                  *(ushort *)(propagateReadMaskPtr + 0x20) = readComponentBits | *(ushort *)(propagateReadMaskPtr + 0x20);
                }
              }
            }
            if ((sourceSelect & 0x200) != 0) {
              alphaReadComponentBits = (ushort)componentSelect & 8;
              if ((((componentModeIs300) && (opcode < 9)) && (opcodeInSet1f1)) &&
                 ((~(*(ushort *)(half + 6) | *(ushort *)(half + 2)) & 1) != 0)) {
                alphaReadComponentBits = 0;
              }
              slotByteOffset = readSlot * 2;
              readMaskPtr = slotByteOffset + half;
              *(ushort *)(readMaskPtr + 0x1a) = alphaReadComponentBits | *(ushort *)(readMaskPtr + 0x1a);
              if (propagateHalf != 0) {
                *(ushort *)(slotByteOffset + propagateHalf + 0x1a) = alphaReadComponentBits | *(ushort *)(slotByteOffset + propagateHalf + 0x1a);
              }
              if (!slotIsNotSrcp) {
                srcpReadMaskPtr = addressSlot * 2 + half;
                *(ushort *)(readMaskPtr + 0x24) = alphaReadComponentBits | *(ushort *)(readMaskPtr + 0x24);
                *(ushort *)(srcpReadMaskPtr + 0x1a) = alphaReadComponentBits | *(ushort *)(srcpReadMaskPtr + 0x1a);
                *(ushort *)(srcpReadMaskPtr + 0x24) = alphaReadComponentBits | *(ushort *)(srcpReadMaskPtr + 0x24);
                if (propagateHalf != 0) {
                  propagateReadMaskPtr = addressSlot * 2 + propagateHalf;
                  previousReadMask = *(ushort *)(propagateReadMaskPtr + 0x1a);
                  *(ushort *)(slotByteOffset + propagateHalf + 0x24) = alphaReadComponentBits | *(ushort *)(slotByteOffset + propagateHalf + 0x24);
                  *(ushort *)(propagateReadMaskPtr + 0x1a) = alphaReadComponentBits | previousReadMask;
                  *(ushort *)(propagateReadMaskPtr + 0x24) = alphaReadComponentBits | *(ushort *)(propagateReadMaskPtr + 0x24);
                }
              }
            }
            loopContinue2 = uVar19 != 2;
            sourceFlagsBase = sourceFlagsBase + 2;
            uVar19 = uVar19 + 1;
          } while (loopContinue2);
          halfIndex = nextHalfIndex;
        } while (nextHalfIndex != 2);
        if (copyHalfNumber == 1) {
          *(undefined4 *)(entry + 0x14) = *(undefined4 *)(entry + 0x54);
          *(undefined4 *)(entry + 0x20) = *(undefined4 *)(entry + 0x60);
          *(undefined4 *)(entry + 0x24) = *(undefined4 *)(entry + 100);
          *(undefined4 *)(entry + 0x1c) = *(undefined4 *)(entry + 0x5c);
          *(undefined4 *)(entry + 0x18) = *(undefined4 *)(entry + 0x58);
          *(uint *)(entry + 0x30) = *(uint *)(entry + 0x30) | 4;
        }
        else if (copyHalfNumber == 2) {
          *(undefined4 *)(entry + 0x54) = *(undefined4 *)(entry + 0x14);
          *(undefined4 *)(entry + 0x60) = *(undefined4 *)(entry + 0x20);
          *(undefined4 *)(entry + 100) = *(undefined4 *)(entry + 0x24);
          *(undefined4 *)(entry + 0x5c) = *(undefined4 *)(entry + 0x1c);
          *(undefined4 *)(entry + 0x58) = *(undefined4 *)(entry + 0x18);
          *(uint *)(entry + 0x70) = *(uint *)(entry + 0x70) | 4;
        }
        halfIndex = 0;
        halfCursor = entry;
        do {
          if ((*(short *)(halfCursor + 2) == 0 && *(short *)(halfCursor + 6) == 0) &&
             ((*(uint *)(halfCursor + 0x30) & 1) == 0)) {
            *(uint *)(halfCursor + 0x30) = *(uint *)(halfCursor + 0x30) & 0xfffffffb;
          }
          loopContinue = halfIndex != 1;
          halfCursor = halfCursor + 0x40;
          halfIndex = halfIndex + 1;
        } while (loopContinue);
        halfIndex = 0;
        usageCursor = (undefined4 *)(entry + 0x14);
        halfCursor = entry;
        do {
          halfIndex = halfIndex + 1;
          if ((srcpSelectsUsed & halfIndex * 0x100) == 0) {
            *(undefined2 *)((int)usageCursor + 0x16) = 0;
          }
          if ((*(short *)((int)usageCursor + -0x12) == 0 && *(short *)((int)usageCursor + -0xe) == 0) &&
             (uVar19 = usageCursor[7], (uVar19 & 1) == 0)) {
            usageCursor[4] = 0;
            *usageCursor = 0;
            usageCursor[1] = 0;
            usageCursor[2] = 0;
            usageCursor[7] = uVar19 & 0xfffffff7;
            usageCursor[3] = 0;
            usageCursor[6] = 0x3f800000;
            if ((*(uint *)(halfCursor + 0x70) & 6) == 0) {
              *(undefined2 *)(usageCursor + 9) = 1;
              *(undefined2 *)((int)usageCursor + 0x22) = 1;
              *(undefined2 *)(usageCursor + 8) = 1;
              usageCursor[7] = uVar19 & 0xffffffe5;
              defaultScaleBits = (*(unsigned int *)&DAT_001dbf94);
              *(undefined2 *)(usageCursor + 5) = 0;
              usageCursor[-3] = defaultScaleBits;
              usageCursor[-1] = defaultScaleBits;
              usageCursor[-2] = defaultScaleBits;
            }
          }
          usageCursor = usageCursor + 0x10;
          halfCursor = halfCursor + -0x40;
        } while (halfIndex != 2);
        halfIndex = 0;
        halfCursor = entry;
        do {
          if (((*(short *)(halfCursor + 2) != 0 || *(short *)(halfCursor + 6) != 0) ||
              ((*(uint *)(halfCursor + 0x30) & 1) != 0)) &&
             ((*(short *)(entry + 0x1a) != 0 || *(short *)(entry + 0x1c) != 0) ||
              *(short *)(entry + 0x1e) != 0)) {
            *(uint *)(halfCursor + 0x30) = *(uint *)(halfCursor + 0x30) | 2;
          }
          loopContinue = halfIndex != 1;
          halfCursor = halfCursor + 0x40;
          entry = entry + 0x3a;
          halfIndex = halfIndex + 1;
        } while (loopContinue);
        return;
      }
      return;
    }
  } while( true );
}

/* psnDecDecodeHwInstruction @ 0xc1780 (1416 bytes) */
int psnDecDecodeHwInstruction(decoded, wordsMode0, wordsMode2)
  ushort *decoded;
  int wordsMode0;
  int wordsMode2;
{
  uint texWord;
  uint texFieldCode;
  uint groupNumber;
  uint rsWord;
  int referencedHalfIndex;
  ushort alphaReadComponentBits;
  ushort readComponentBits;
  uint alphaOpTableOffset;
  uint alphaSourceSelectCode;
  uint restrictMaskCopy;
  ushort thirdSlotAddress;
  ushort alphaAddrHigh;
  ushort rgbAddrHigh;
  uint alphaSourceModifier;
  uint rewriteSelectKey;
  ushort previousReadMask;
  uint alphaSourcesLeft;
  uint readSlot;
  int halfCounter2;
  int halfIndexB;
  int halfCounter;
  int halfByteOffset;
  int sourceIndex;
  int groupSetupCounter;
  int addressSlotOffset;
  int slotIndex;
  int sourceSlotPtr;
  int programWordPtr;
  int groupCounter;
  int entryMode;
  uint rgbInstWord;
  uint alphaAddrWord;
  uint rgbAddrWord;
  uint srcpSelectsUsed;
  uint writeAndOutputMaskWide;
  uint readComponents;
  uint replicatedMask;
  uint slotComponentMask;
  uint swizzleMode;
  ushort componentMode;
  ushort source2FlagsB;
  ushort source0FlagsNew;
  undefined4 defaultOperandWord2;
  undefined4 swappedSourceWord;
  undefined4 defaultOperandWord;
  ushort writeAndOutputMask;
  ushort swizzleSelect;
  ushort sourceSwizzleOfSlot;
  ushort source0Flags;
  ushort source1FlagsOld;
  uint componentSelect;
  ushort swizzleWordAtSlot;
  ushort writeAndOutputMaskBits;
  ushort opcode;
  uint writeAndOutputMaskInt;
  uint halfFlags;
  ushort sourceSelect;
  ushort source2Flags;
  int copyHalfNumber;
  int halfOffsetCursor;
  int groupIndex;
  int nextHalfIndex;
  int sourceSlotCursor;
  int sourceSlots;
  int source2Word;
  int sourceCounter;
  int halfIndex;
  int peepholeHalf;
  int sourceByteOffset;
  int source0Word;
  bool opcodeInSet1f1;
  bool entryChanged;
  bool loopContinue;
  bool selectsRewritten;
  bool componentModeIs300;
  bool slotIsNotSrcp;
  bool loopContinue2;
  float outputScale;
  ushort referencedSrcpOp;
  int hwImage;
  uint sourceModifierCopy;
  uint alphaWordValue;
  ushort *propagateHalf;
  ushort source1Flags;
  uint hwWordValue;
  uint fieldAccum;
  ushort slotSelect;
  uint addressSlot;
  ushort sourceSwizzleWord;
  uint rgbOpTableOffset;
  ushort *sourceFlagsPtr;
  ushort *recordPtr;
  int halfCounter3;
  ushort *slotWordPtr;
  ushort previousReadMaskB;
  undefined4 outputScaleWord;
  int rsWordPtr;
  int slotCounter;
  uint sourceModifier;
  uint rgbSourcesLeft;
  uint sourceSelectCode;
  
  _memset(decoded,0,0x80);
  entryMode = *(int *)(decoded + 0x46);
  decoded[0x40] = 0;
  decoded[0x41] = 0;
  decoded[0x44] = 0;
  decoded[0x45] = 0;
  decoded[0x42] = 0;
  decoded[0x43] = 0;
  hwImage = *(int *)(decoded + 0x48);
  if (entryMode != 1) {
    if (entryMode == 0) {
      rsWordPtr = hwImage * 4 + wordsMode0;
      decoded[2] = (ushort)((uint)*(undefined4 *)(rsWordPtr + 4) >> 0x12) & 0x7f;
      decoded[0x40] = *(byte *)(rsWordPtr + 6) >> 4 | 0xc000;
      if ((*(ushort *)(rsWordPtr + 4) & 3) != 0) {
        decoded[10] = 0xf;
        decoded[3] = 0xf;
        slotSelect = *(ushort *)(rsWordPtr + 4) & 3;
        if ((slotSelect == 2) || (slotSelect == 3)) {
          decoded[0x1d] = slotSelect;
        }
      }
      hwImage = hwImage * 4 + wordsMode0;
      *(undefined4 *)(decoded + 0x16) =
           *(undefined4 *)((*(uint *)(hwImage + 4) >> 0x19 & 0x7c) + 0x1dc198);
      decoded[0x22] = (ushort)(*(uint *)(hwImage + 4) >> 5) & 0x7f;
      decoded[0x43] = (ushort)*(undefined4 *)(hwImage + 4) & 0xf | 0xa000;
      rsWord = *(uint *)(hwImage + 4);
      if ((rsWord & 0x10) != 0) {
        decoded[0x2d] = 0xf;
        decoded[0x23] = 0xf;
        rsWord = *(uint *)(hwImage + 4);
      }
      *(undefined4 *)(decoded + 0x36) = *(undefined4 *)((rsWord >> 0x17 & 4) + 0x1dc198);
      return;
    }
    if (entryMode != 2) {
      return;
    }
    groupCounter = 0;
    hwImage = hwImage * 4 + wordsMode2;
    alphaAddrWord = *(uint *)(hwImage + 0x198);
    rgbAddrWord = *(uint *)(hwImage + 0x98);
    alphaWordValue = *(uint *)(hwImage + 0x398);
    rgbInstWord = *(uint *)(hwImage + 0x298);
    decoded[0x40] = (ushort)rgbAddrWord & 0x3f;
    decoded[0x43] = (ushort)alphaAddrWord & 0x3f;
    decoded[0x41] = (ushort)(rgbAddrWord >> 6) & 0x3f;
    decoded[0x42] = (ushort)(rgbAddrWord >> 0xc) & 0x3f;
    decoded[0x44] = (ushort)(alphaAddrWord >> 6) & 0x3f;
    decoded[0x45] = (ushort)(alphaAddrWord >> 0xc) & 0x3f;
    addressSlotOffset = 0x80;
    do {
      slotWordPtr = (ushort *)((int)decoded + addressSlotOffset);
      slotCounter = 0;
      do {
        if (0x1f < *slotWordPtr) {
          *slotWordPtr = *slotWordPtr - 0x20 | 0x8000;
        }
        loopContinue = slotCounter != 2;
        slotWordPtr = slotWordPtr + 1;
        slotCounter = slotCounter + 1;
      } while (loopContinue);
      loopContinue = groupCounter != 1;
      addressSlotOffset = addressSlotOffset + 6;
      groupCounter = groupCounter + 1;
    } while (loopContinue);
    groupSetupCounter = 0;
    slotWordPtr = decoded;
    recordPtr = decoded;
    do {
      recordPtr[0x3a] = 1;
      recordPtr[0x1a] = 1;
      defaultOperandWord2 = (*(unsigned int *)&DAT_001dbf94);
      loopContinue = groupSetupCounter != 2;
      recordPtr = recordPtr + 1;
      groupSetupCounter = groupSetupCounter + 1;
      *(undefined4 *)(slotWordPtr + 4) = (*(unsigned int *)&DAT_001dbf94);
      *(undefined4 *)(slotWordPtr + 0x24) = defaultOperandWord2;
      slotWordPtr = slotWordPtr + 2;
    } while (loopContinue);
    rgbAddrHigh = (ushort)(rgbAddrWord >> 0x10);
    decoded[3] = rgbAddrHigh >> 7 & 7;
    decoded[2] = rgbAddrHigh >> 2 & 0x1f;
    rgbOpTableOffset = rgbInstWord >> 0x15 & 0x3c;
    *decoded = rgbAddrHigh >> 0xd & 3;
    decoded[1] = rgbAddrHigh >> 10 & 7;
    decoded[0x14] = *(ushort *)(rgbOpTableOffset + 0x1dc158);
    rgbOpTableOffset = (uint)*(ushort *)(rgbOpTableOffset + 0x1dc15a);
    if (rgbOpTableOffset != 0) {
      sourceModifier = rgbInstWord >> 5 & 3;
LAB_000c1ab0:
      sourceIndex = 0;
      sourceSelectCode = rgbInstWord & 0x1f;
      sourceModifierCopy = sourceModifier;
      slotWordPtr = decoded + 4;
      rgbSourcesLeft = rgbOpTableOffset;
      if (rgbOpTableOffset == 0) {
        rgbSourcesLeft = 1;
      }
      do {
        sourceIndex = sourceIndex + 1;
        *(undefined4 *)slotWordPtr = *(undefined4 *)(sourceSelectCode * 4 + 0x1dc0d8);
        slotWordPtr[1] = (ushort)(sourceModifierCopy << 0xc) | slotWordPtr[1];
        rgbSourcesLeft = rgbSourcesLeft - 1;
        if (rgbSourcesLeft == 0) break;
        sourceSelectCode = rgbInstWord >> 7 & 0x1f;
        sourceModifierCopy = rgbInstWord >> 0xc & 3;
        if (sourceIndex != 1) {
          if (sourceIndex == 0) goto LAB_000c1ab0;
          sourceSelectCode = rgbInstWord >> 0xe & 0x1f;
          sourceModifierCopy = rgbInstWord >> 0x13 & 3;
          if (sourceIndex != 2) {
            sourceSelectCode = 0;
            sourceModifierCopy = 0;
          }
        }
        slotWordPtr = slotWordPtr + 2;
      } while( true );
    }
    decoded[0x15] = (ushort)(rgbInstWord >> 0x15) & 3;
    if ((rgbInstWord & 0x40000000) != 0) {
      *(uint *)(decoded + 0x18) = *(uint *)(decoded + 0x18) | 8;
    }
    alphaAddrHigh = (ushort)(alphaAddrWord >> 0x10);
    outputScaleWord = *(undefined4 *)((rgbInstWord >> 0x19 & 0x1c) + 0x1dc198);
    decoded[0x22] = alphaAddrHigh >> 2 & 0x1f;
    *(undefined4 *)(decoded + 0x16) = outputScaleWord;
    if ((alphaAddrWord & 0x800000) != 0) {
      decoded[0x23] = 8;
    }
    decoded[0x20] = alphaAddrHigh >> 9 & 3;
    if ((alphaAddrWord & 0x1000000) != 0) {
      decoded[0x21] = 8;
    }
    if ((alphaAddrWord & 0x8000000) != 0) {
      decoded[0x21] = decoded[0x21] | 0x10;
    }
    alphaOpTableOffset = alphaWordValue >> 0x15 & 0x3c;
    decoded[0x34] = *(ushort *)(alphaOpTableOffset + 0x1dc098);
    alphaOpTableOffset = (uint)*(ushort *)(alphaOpTableOffset + 0x1dc09a);
    if ((rgbInstWord & 0x7800000) == 0x1000000) {
      if (alphaOpTableOffset < 2) {
        alphaOpTableOffset = 2;
      }
    }
    else if (alphaOpTableOffset == 0) {
LAB_000c1cec:
      decoded[0x35] = (ushort)(alphaWordValue >> 0x15) & 3;
      if ((alphaWordValue & 0x40000000) != 0) {
        *(uint *)(decoded + 0x38) = *(uint *)(decoded + 0x38) | 8;
      }
      *(undefined4 *)(decoded + 0x36) = *(undefined4 *)((alphaWordValue >> 0x19 & 0x1c) + 0x1dc198);
      ((int (*)())psnDecRecomputeSourceUsage)(decoded);
      selectsRewritten = false;
      groupNumber = 1;
      slotWordPtr = decoded;
      do {
        if ((slotWordPtr[0x41] != 0xffff) && (slotWordPtr[0x40] == slotWordPtr[0x41])) {
          halfByteOffset = 0;
          rewriteSelectKey = (groupNumber & 0xff) << 8 | 1;
          do {
            sourceSlotPtr = (int)decoded + halfByteOffset;
            sourceCounter = 0;
            do {
              if (*(ushort *)(sourceSlotPtr + 8) == rewriteSelectKey) {
                *(ushort *)(sourceSlotPtr + 8) = (ushort)rewriteSelectKey ^ 1;
                selectsRewritten = true;
              }
              loopContinue2 = sourceCounter != 2;
              sourceSlotPtr = sourceSlotPtr + 4;
              sourceCounter = sourceCounter + 1;
            } while (loopContinue2);
            loopContinue2 = halfByteOffset != 0x40;
            halfByteOffset = halfByteOffset + 0x40;
          } while (loopContinue2);
        }
        thirdSlotAddress = slotWordPtr[0x42];
        if (thirdSlotAddress != 0xffff) {
          if (slotWordPtr[0x40] == thirdSlotAddress) {
            halfByteOffset = 0;
            rewriteSelectKey = (groupNumber & 0xff) << 8 | 2;
            do {
              sourceSlotPtr = (int)decoded + halfByteOffset;
              sourceCounter = 0;
              do {
                if (*(ushort *)(sourceSlotPtr + 8) == rewriteSelectKey) {
                  *(ushort *)(sourceSlotPtr + 8) = (ushort)rewriteSelectKey ^ 2;
                  selectsRewritten = true;
                }
                loopContinue2 = sourceCounter != 2;
                sourceSlotPtr = sourceSlotPtr + 4;
                sourceCounter = sourceCounter + 1;
              } while (loopContinue2);
              loopContinue2 = halfByteOffset != 0x40;
              halfByteOffset = halfByteOffset + 0x40;
            } while (loopContinue2);
          }
          else if (slotWordPtr[0x41] == thirdSlotAddress) {
            halfByteOffset = 0;
            rewriteSelectKey = (groupNumber & 0xff) << 8 | 2;
            do {
              sourceSlotPtr = (int)decoded + halfByteOffset;
              sourceCounter = 0;
              do {
                if (*(ushort *)(sourceSlotPtr + 8) == rewriteSelectKey) {
                  *(ushort *)(sourceSlotPtr + 8) = (ushort)rewriteSelectKey ^ 3;
                  selectsRewritten = true;
                }
                loopContinue2 = sourceCounter != 2;
                sourceSlotPtr = sourceSlotPtr + 4;
                sourceCounter = sourceCounter + 1;
              } while (loopContinue2);
              loopContinue2 = halfByteOffset != 0x40;
              halfByteOffset = halfByteOffset + 0x40;
            } while (loopContinue2);
          }
        }
        loopContinue2 = groupNumber != 2;
        slotWordPtr = slotWordPtr + 3;
        groupNumber = groupNumber + 1;
      } while (loopContinue2);
      if (selectsRewritten) {
        ((int (*)())psnDecRecomputeSourceUsage)(decoded);
        groupIndex = 0;
        slotWordPtr = decoded + 8;
        do {
          recordPtr = slotWordPtr + 2;
          slotIndex = 0;
          do {
            if (*recordPtr == 0 && recordPtr[0x20] == 0) {
              recordPtr[0x36] = 0xffff;
            }
            loopContinue = slotIndex != 2;
            recordPtr = recordPtr + 1;
            slotIndex = slotIndex + 1;
          } while (loopContinue);
          loopContinue = groupIndex != 1;
          slotWordPtr = slotWordPtr + 3;
          groupIndex = groupIndex + 1;
        } while (loopContinue);
      }
      entryChanged = false;
      alphaWordValue = 0;
      halfOffsetCursor = 0;
      do {
        peepholeHalf = halfOffsetCursor + (int)decoded;
        alphaOpTableOffset = *(uint *)(peepholeHalf + 0x30);
        halfFlags = alphaOpTableOffset & 0xffff00ff;
        *(uint *)(peepholeHalf + 0x30) = halfFlags;
        if ((*(ushort *)(peepholeHalf + 2) != 0 || *(ushort *)(peepholeHalf + 6) != 0) || ((alphaOpTableOffset & 1) != 0)) {
          opcode = *(ushort *)(peepholeHalf + 0x28);
          if ((opcode == 5) &&
             ((*(short *)(peepholeHalf + 8) == *(short *)(peepholeHalf + 0xc) &&
              ((*(ushort *)(peepholeHalf + 10) ^ *(ushort *)(peepholeHalf + 0xe)) == 0x1000)))) {
            opcode = 0;
            *(undefined2 *)(peepholeHalf + 0x28) = 0;
            entryChanged = true;
            *(undefined2 *)(peepholeHalf + 0x36) = 2;
            *(ushort *)(peepholeHalf + 10) = *(ushort *)(peepholeHalf + 10) & 0xefff | 0x2000;
            *(ushort *)(peepholeHalf + 0x34) = *(ushort *)(peepholeHalf + 0x34) & 0xffdf | 0x40;
            defaultOperandWord = (*(unsigned int *)&DAT_001dbf90);
            *(undefined2 *)(peepholeHalf + 0x38) = 1;
            *(undefined4 *)(peepholeHalf + 0xc) = defaultOperandWord;
            *(undefined4 *)(peepholeHalf + 0x10) = (*(unsigned int *)&DAT_001dbf94);
          }
          if ((((opcode == 7) && (*(short *)(peepholeHalf + 8) == *(short *)(peepholeHalf + 0xc))) &&
              (*(int *)(peepholeHalf + 8) == *(int *)(peepholeHalf + 0x10))) &&
             ((*(ushort *)(peepholeHalf + 10) ^ *(ushort *)(peepholeHalf + 0xe)) == 0x1000)) {
            opcode = 0;
            *(undefined2 *)(peepholeHalf + 0x28) = 0;
            entryChanged = true;
            *(undefined2 *)(peepholeHalf + 0x36) = 2;
            *(ushort *)(peepholeHalf + 10) = *(ushort *)(peepholeHalf + 10) & 0xefff | 0x2000;
            *(ushort *)(peepholeHalf + 0x34) = *(ushort *)(peepholeHalf + 0x34) & 0xffdf | 0x40;
            defaultOperandWord = (*(unsigned int *)&DAT_001dbf90);
            *(undefined2 *)(peepholeHalf + 0x38) = 1;
            *(undefined4 *)(peepholeHalf + 0xc) = defaultOperandWord;
            *(undefined4 *)(peepholeHalf + 0x10) = (*(unsigned int *)&DAT_001dbf94);
          }
          if (opcode == 0) {
            source1FlagsOld = *(ushort *)(peepholeHalf + 0x36);
            if (((*(ushort *)(peepholeHalf + 0x34) | source1FlagsOld) & 1) == 0) {
              source2Flags = *(ushort *)(peepholeHalf + 0x38);
            }
            else {
              source1FlagsOld = 2;
              entryChanged = true;
              *(undefined2 *)(peepholeHalf + 0x36) = 2;
              *(undefined2 *)(peepholeHalf + 0x34) = *(undefined2 *)(peepholeHalf + 0x38);
              *(undefined4 *)(peepholeHalf + 8) = *(undefined4 *)(peepholeHalf + 0x10);
              defaultOperandWord = (*(unsigned int *)&DAT_001dbf90);
              source2Flags = 1;
              *(undefined2 *)(peepholeHalf + 0x38) = 1;
              *(undefined4 *)(peepholeHalf + 0xc) = defaultOperandWord;
              *(undefined4 *)(peepholeHalf + 0x10) = (*(unsigned int *)&DAT_001dbf94);
            }
            source0FlagsNew = source1FlagsOld;
            if (((*(ushort *)(peepholeHalf + 8) & 0x300) == 0) && ((source1FlagsOld & 2) == 0)) {
              source0FlagsNew = *(ushort *)(peepholeHalf + 0x34);
              swappedSourceWord = *(undefined4 *)(peepholeHalf + 0xc);
              *(ushort *)(peepholeHalf + 0x34) = source1FlagsOld;
              *(ushort *)(peepholeHalf + 0x36) = source0FlagsNew;
              *(undefined4 *)(peepholeHalf + 0xc) = *(undefined4 *)(peepholeHalf + 8);
              *(undefined4 *)(peepholeHalf + 8) = swappedSourceWord;
            }
            if ((source0FlagsNew & 0x20) != 0) {
              *(ushort *)(peepholeHalf + 0x36) = source0FlagsNew ^ 0x20;
              *(ushort *)(peepholeHalf + 0x34) = *(ushort *)(peepholeHalf + 0x34) ^ 0x20;
              *(ushort *)(peepholeHalf + 10) = *(ushort *)(peepholeHalf + 10) ^ 0x1000;
              *(ushort *)(peepholeHalf + 0xe) = *(ushort *)(peepholeHalf + 0xe) ^ 0x1000;
            }
            if ((source2Flags & 1) == 0) {
              if (((*(ushort *)(peepholeHalf + 0x36) & 2) == 0) ||
                 ((*(ushort *)(peepholeHalf + 8) & 0x300) != 0)) {
                source0Word = *(int *)(peepholeHalf + 8);
                source2Word = *(int *)(peepholeHalf + 0x10);
              }
              else {
                source0Flags = *(ushort *)(peepholeHalf + 0x34);
                source0Word = *(int *)(peepholeHalf + 0x10);
                source2Word = *(int *)(peepholeHalf + 8);
                *(ushort *)(peepholeHalf + 0x34) = source2Flags;
                *(ushort *)(peepholeHalf + 0x38) = source0Flags;
                *(int *)(peepholeHalf + 0x10) = source2Word;
                *(int *)(peepholeHalf + 8) = source0Word;
                if ((source0Flags & 1) != 0) goto LAB_000c14b0;
              }
              if (((source0Word == source2Word) && ((*(ushort *)(peepholeHalf + 0x36) & 2) != 0)) &&
                 (outputScale = *(float *)(peepholeHalf + 0x2c), outputScale < FLOAT_001aa100)) {
                entryChanged = true;
                *(undefined2 *)(peepholeHalf + 0x38) = 1;
                defaultOperandWord2 = (*(unsigned int *)&DAT_001dbf94);
                *(float *)(peepholeHalf + 0x2c) = outputScale + outputScale;
                *(undefined4 *)(peepholeHalf + 0x10) = defaultOperandWord2;
              }
            }
LAB_000c14b0:
            if (((alphaOpTableOffset & 8) == 0) && (*(float *)(peepholeHalf + 0x2c) == FLOAT_001aa0e8)) {
              source0Flags = *(ushort *)(peepholeHalf + 0x34);
              source1Flags = *(ushort *)(peepholeHalf + 0x36);
              if (((source0Flags | source1Flags) & 0x18) == 0) {
                source2FlagsB = *(ushort *)(peepholeHalf + 0x38);
                if (((source2FlagsB & 1) != 0) &&
                   ((((source0Flags ^ source1Flags) & 0x40) == 0 || ((*(ushort *)(peepholeHalf + 0xc) & 0x300) == 0)))
                   ) {
                  *(uint *)(peepholeHalf + 0x30) = halfFlags | 0x100;
                  if ((source0Flags & 0x40) != 0) {
                    *(uint *)(peepholeHalf + 0x30) = halfFlags | 0x1100;
                  }
                  if ((source0Flags & 0x20) == 0) {
                    halfFlags = *(uint *)(peepholeHalf + 0x30);
                  }
                  else {
                    halfFlags = *(uint *)(peepholeHalf + 0x30) | 0x800;
                    *(uint *)(peepholeHalf + 0x30) = halfFlags;
                  }
                }
              }
              else {
                source2FlagsB = *(ushort *)(peepholeHalf + 0x38);
              }
              if ((((source0Flags | source2FlagsB) & 0x18) == 0) && ((source1Flags & 2) != 0)) {
                halfFlags = halfFlags | 0x200;
                *(uint *)(peepholeHalf + 0x30) = halfFlags;
              }
              if ((halfFlags | 0xfffffcff) == 0xffffffff) {
                *(uint *)(peepholeHalf + 0x30) = halfFlags | 0x400;
              }
            }
          }
          if ((opcode < 9) && ((1 << ((int)(short)opcode & 0x3fU) & 0x1f1U) != 0)) {
            writeAndOutputMaskBits = *(ushort *)(peepholeHalf + 6) | *(ushort *)(peepholeHalf + 2);
            writeAndOutputMaskInt = (uint)writeAndOutputMaskBits;
            alphaOpTableOffset = writeAndOutputMaskInt & 0xffef;
            if (((alphaOpTableOffset - 1 & 0xffff) < 2) || (alphaOpTableOffset == 4)) {
              sourceSlots = peepholeHalf + 8;
              sourceByteOffset = 0;
              restrictMaskCopy = alphaWordValue;
              do {
                sourceSwizzleOfSlot = *(ushort *)(sourceByteOffset + sourceSlots + 2);
                alphaWordValue = restrictMaskCopy;
                if ((sourceSwizzleOfSlot | 0xfffffff9) == 0xffffffff) {
                  swizzleMode = sourceSwizzleOfSlot & 0x300;
                  alphaWordValue = (writeAndOutputMaskInt & 3) << 1 | (int)(writeAndOutputMaskInt & 4) >> 2;
                  if (swizzleMode != 0x100) {
                    if (swizzleMode < 0x101) {
                      alphaWordValue = alphaOpTableOffset;
                      if ((sourceSwizzleOfSlot & 0x300) != 0) {
                        alphaWordValue = restrictMaskCopy;
                      }
                    }
                    else if (swizzleMode == 0x200) {
                      alphaWordValue = (writeAndOutputMaskInt & 1) << 2 | writeAndOutputMaskBits >> 1 & 3;
                    }
                    else {
                      alphaWordValue = restrictMaskCopy;
                      if (swizzleMode == 0x300) {
                        alphaWordValue = (writeAndOutputMaskInt & 2) << 1 | (int)(writeAndOutputMaskInt & 4) >> 1 | (writeAndOutputMaskInt & 1) << 3;
                        if ((writeAndOutputMaskBits & 1) == 0) {
                          *(ushort *)(sourceByteOffset + sourceSlots) = *(ushort *)(sourceByteOffset + sourceSlots) & 0xfdff;
                        }
                        else {
                          *(ushort *)(sourceByteOffset + sourceSlots) = *(ushort *)(sourceByteOffset + sourceSlots) & 0xfeff;
                        }
                      }
                    }
                  }
                  entryChanged = true;
                  *(ushort *)(sourceByteOffset + sourceSlots + 2) = sourceSwizzleOfSlot & ~((ushort)alphaWordValue ^ 0xf | 0x300);
                }
                loopContinue2 = sourceByteOffset != 8;
                sourceByteOffset = sourceByteOffset + 4;
                restrictMaskCopy = alphaWordValue;
              } while (loopContinue2);
            }
          }
          halfCounter3 = 0;
          sourceSlotCursor = peepholeHalf;
          do {
            swizzleWordAtSlot = *(ushort *)(sourceSlotCursor + 10);
            swizzleSelect = swizzleWordAtSlot & 0x1f;
            if (swizzleSelect == 0x10) {
              *(ushort *)(sourceSlotCursor + 10) = swizzleWordAtSlot & 0xcfff;
              *(ushort *)(peepholeHalf + 0x34) = *(ushort *)(peepholeHalf + 0x34) & 0xff9f;
            }
            else if ((0xf < swizzleSelect) && (swizzleSelect < 0x13)) {
              *(ushort *)(sourceSlotCursor + 10) = swizzleWordAtSlot & 0xdfff;
              *(ushort *)(peepholeHalf + 0x34) = *(ushort *)(peepholeHalf + 0x34) & 0xffbf;
            }
            loopContinue2 = halfCounter3 != 2;
            sourceSlotCursor = sourceSlotCursor + 4;
            peepholeHalf = peepholeHalf + 2;
            halfCounter3 = halfCounter3 + 1;
          } while (loopContinue2);
        }
        loopContinue2 = halfOffsetCursor == 0x40;
        halfOffsetCursor = halfOffsetCursor + 0x40;
        if (loopContinue2) {
          if (!entryChanged) {
            return;
          }
          slotWordPtr = (ushort *)0x0;
          copyHalfNumber = 0;
          srcpSelectsUsed = 0;
          halfIndex = 0;
          do {
            recordPtr = decoded + halfIndex * 0x20;
            opcode = recordPtr[0x14];
            hwWordValue = *(uint *)(recordPtr + 0x18);
            recordPtr[10] = 0;
            recordPtr[0xb] = 0;
            recordPtr[0x10] = 0;
            recordPtr[0x11] = 0;
            recordPtr[0xe] = 0;
            recordPtr[0xf] = 0;
            recordPtr[0x12] = 0;
            recordPtr[0x13] = 0;
            recordPtr[0xc] = 0;
            recordPtr[0xd] = 0;
            *(uint *)(recordPtr + 0x18) = hwWordValue & 0xffffff89;
            if (opcode == 2) {
              *(uint *)(recordPtr + 0x18) = hwWordValue & 0xffffff89 | 0x52;
              slotWordPtr = recordPtr;
            }
            nextHalfIndex = halfIndex + 1;
            if (opcode == 0xd) {
              copyHalfNumber = nextHalfIndex;
            }
            opcodeInSet1f1 = (1 << ((int)(short)opcode & 0x3fU) & 0x1f1U) != 0;
            fieldAccum = 0;
            propagateHalf = recordPtr;
            do {
              sourceSelect = recordPtr[fieldAccum * 2 + 4];
              sourceSwizzleWord = recordPtr[fieldAccum * 2 + 5];
              addressSlot = sourceSelect & 3;
              componentMode = sourceSwizzleWord & 0x300;
              componentSelect = sourceSwizzleWord & 0x1f;
              componentModeIs300 = componentMode == 0x300;
              if (componentModeIs300) {
                *(uint *)(recordPtr + 0x18) = *(uint *)(recordPtr + 0x18) | 0x10;
              }
              if ((opcode == 3) && ((componentSelect | 0xfffffff9) == 0xffffffff)) {
                slotComponentMask = (1 < fieldAccum) + 3;
                if (componentMode == 0x200) {
                  slotComponentMask = slotComponentMask * 4 & 4 | slotComponentMask >> 1;
                }
                else if (componentModeIs300) {
                  slotComponentMask = slotComponentMask * 8 & 8 | slotComponentMask * 2 & 4 | slotComponentMask >> 1 & 2;
                }
                else if (componentMode == 0x100) {
                  slotComponentMask = slotComponentMask * 2 & 6 | slotComponentMask >> 2;
                }
                componentSelect = slotComponentMask & componentSelect;
              }
              propagateHalf[0x1a] = 0;
              sourceFlagsPtr = propagateHalf + 0x1a;
              if (((componentSelect & 0x10) == 0) &&
                 (((sourceSwizzleWord & 0x300) != 0 || (((recordPtr[3] | recordPtr[1]) & 0xffef & ~componentSelect) != 0))))
              {
                propagateHalf[0x1a] = 8;
              }
              slotIsNotSrcp = addressSlot != 3;
              if (slotIsNotSrcp) {
                readSlot = addressSlot;
                if (componentSelect == 0x11) {
                  *sourceFlagsPtr = *sourceFlagsPtr | 4;
                }
                else if (componentSelect == 0x12) {
                  *sourceFlagsPtr = *sourceFlagsPtr | 2;
                }
                else if (componentSelect == 0x10) {
                  *sourceFlagsPtr = *sourceFlagsPtr | 1;
                }
              }
              else {
                srcpSelectsUsed = sourceSelect & 0x300 | srcpSelectsUsed;
                referencedHalfIndex = ((sourceSelect & 0x300) >> 8) - 1;
                referencedSrcpOp = decoded[referencedHalfIndex * 0x20 + 0x15];
                if (halfIndex != referencedHalfIndex) {
                  *(uint *)(recordPtr + 0x18) = *(uint *)(recordPtr + 0x18) | 0x20;
                }
                addressSlot = (uint)(referencedSrcpOp - 1 < 2);
                *sourceFlagsPtr = *sourceFlagsPtr | 0x10;
                readSlot = 0;
              }
              if ((sourceSwizzleWord & 0x1000) != 0) {
                *sourceFlagsPtr = *sourceFlagsPtr | 0x20;
              }
              if ((sourceSwizzleWord & 0x2000) != 0) {
                *sourceFlagsPtr = *sourceFlagsPtr | 0x40;
              }
              if ((halfIndex == 1) && (fieldAccum == 2)) {
                slotWordPtr = (ushort *)0x0;
              }
              if ((sourceSelect & 0x100) != 0) {
                readComponents = componentSelect & 7;
                if ((readComponents | 0xfffffff9) == 0xffffffff) {
                  writeAndOutputMask = recordPtr[3] | recordPtr[1];
                  writeAndOutputMaskWide = (uint)writeAndOutputMask;
                  replicatedMask = writeAndOutputMaskWide & 0xffef;
                  if (componentMode == 0x200) {
                    replicatedMask = (writeAndOutputMaskWide & 1) << 2 | writeAndOutputMask >> 1 & 3;
                  }
                  else if (componentModeIs300) {
                    replicatedMask = (writeAndOutputMaskWide & 2) << 1 | writeAndOutputMask >> 1 & 2;
                  }
                  else if (componentMode == 0x100) {
                    replicatedMask = (writeAndOutputMaskWide & 3) << 1 | writeAndOutputMask >> 2 & 1;
                  }
                  if ((opcode < 9) && (opcodeInSet1f1)) {
                    readComponents = readComponents & replicatedMask;
                  }
                }
                readComponentBits = (ushort)readComponents;
                recordPtr[readSlot + 10] = readComponentBits | recordPtr[readSlot + 10];
                if (slotWordPtr != (ushort *)0x0) {
                  slotWordPtr[readSlot + 10] = readComponentBits | slotWordPtr[readSlot + 10];
                }
                if (!slotIsNotSrcp) {
                  recordPtr[readSlot + 0x10] = readComponentBits | recordPtr[readSlot + 0x10];
                  recordPtr[addressSlot + 10] = readComponentBits | recordPtr[addressSlot + 10];
                  recordPtr[addressSlot + 0x10] = readComponentBits | recordPtr[addressSlot + 0x10];
                  if (slotWordPtr != (ushort *)0x0) {
                    previousReadMaskB = slotWordPtr[addressSlot + 10];
                    slotWordPtr[readSlot + 0x10] = readComponentBits | slotWordPtr[readSlot + 0x10];
                    slotWordPtr[addressSlot + 10] = readComponentBits | previousReadMaskB;
                    slotWordPtr[addressSlot + 0x10] = readComponentBits | slotWordPtr[addressSlot + 0x10];
                  }
                }
              }
              if ((sourceSelect & 0x200) != 0) {
                alphaReadComponentBits = (ushort)componentSelect & 8;
                if ((((componentModeIs300) && (opcode < 9)) && (opcodeInSet1f1)) &&
                   ((~(recordPtr[3] | recordPtr[1]) & 1) != 0)) {
                  alphaReadComponentBits = 0;
                }
                recordPtr[readSlot + 0xd] = alphaReadComponentBits | recordPtr[readSlot + 0xd];
                if (slotWordPtr != (ushort *)0x0) {
                  slotWordPtr[readSlot + 0xd] = alphaReadComponentBits | slotWordPtr[readSlot + 0xd];
                }
                if (!slotIsNotSrcp) {
                  recordPtr[readSlot + 0x12] = alphaReadComponentBits | recordPtr[readSlot + 0x12];
                  recordPtr[addressSlot + 0xd] = alphaReadComponentBits | recordPtr[addressSlot + 0xd];
                  recordPtr[addressSlot + 0x12] = alphaReadComponentBits | recordPtr[addressSlot + 0x12];
                  if (slotWordPtr != (ushort *)0x0) {
                    previousReadMask = slotWordPtr[addressSlot + 0xd];
                    slotWordPtr[readSlot + 0x12] = alphaReadComponentBits | slotWordPtr[readSlot + 0x12];
                    slotWordPtr[addressSlot + 0xd] = alphaReadComponentBits | previousReadMask;
                    slotWordPtr[addressSlot + 0x12] = alphaReadComponentBits | slotWordPtr[addressSlot + 0x12];
                  }
                }
              }
              loopContinue2 = fieldAccum != 2;
              propagateHalf = propagateHalf + 1;
              fieldAccum = fieldAccum + 1;
            } while (loopContinue2);
            halfIndex = nextHalfIndex;
          } while (nextHalfIndex != 2);
          if (copyHalfNumber == 1) {
            *(undefined4 *)(decoded + 10) = *(undefined4 *)(decoded + 0x2a);
            *(undefined4 *)(decoded + 0x10) = *(undefined4 *)(decoded + 0x30);
            *(undefined4 *)(decoded + 0x12) = *(undefined4 *)(decoded + 0x32);
            *(undefined4 *)(decoded + 0xe) = *(undefined4 *)(decoded + 0x2e);
            *(undefined4 *)(decoded + 0xc) = *(undefined4 *)(decoded + 0x2c);
            *(uint *)(decoded + 0x18) = *(uint *)(decoded + 0x18) | 4;
          }
          else if (copyHalfNumber == 2) {
            *(undefined4 *)(decoded + 0x2a) = *(undefined4 *)(decoded + 10);
            *(undefined4 *)(decoded + 0x30) = *(undefined4 *)(decoded + 0x10);
            *(undefined4 *)(decoded + 0x32) = *(undefined4 *)(decoded + 0x12);
            *(undefined4 *)(decoded + 0x2e) = *(undefined4 *)(decoded + 0xe);
            *(undefined4 *)(decoded + 0x2c) = *(undefined4 *)(decoded + 0xc);
            *(uint *)(decoded + 0x38) = *(uint *)(decoded + 0x38) | 4;
          }
          halfCounter = 0;
          slotWordPtr = decoded;
          do {
            if ((slotWordPtr[1] == 0 && slotWordPtr[3] == 0) && ((*(uint *)(slotWordPtr + 0x18) & 1) == 0)) {
              *(uint *)(slotWordPtr + 0x18) = *(uint *)(slotWordPtr + 0x18) & 0xfffffffb;
            }
            loopContinue = halfCounter != 1;
            slotWordPtr = slotWordPtr + 0x20;
            halfCounter = halfCounter + 1;
          } while (loopContinue);
          halfIndexB = 0;
          recordPtr = decoded + 10;
          slotWordPtr = decoded;
          do {
            halfIndexB = halfIndexB + 1;
            if ((srcpSelectsUsed & halfIndexB * 0x100) == 0) {
              recordPtr[0xb] = 0;
            }
            if ((recordPtr[-9] == 0 && recordPtr[-7] == 0) &&
               (fieldAccum = *(uint *)(recordPtr + 0xe), (fieldAccum & 1) == 0)) {
              recordPtr[8] = 0;
              recordPtr[9] = 0;
              recordPtr[0] = 0;
              recordPtr[1] = 0;
              recordPtr[2] = 0;
              recordPtr[3] = 0;
              recordPtr[4] = 0;
              recordPtr[5] = 0;
              *(uint *)(recordPtr + 0xe) = fieldAccum & 0xfffffff7;
              recordPtr[6] = 0;
              recordPtr[7] = 0;
              recordPtr[0xc] = 0x3f80;
              recordPtr[0xd] = 0;
              if ((*(uint *)(slotWordPtr + 0x38) & 6) == 0) {
                recordPtr[0x12] = 1;
                recordPtr[0x11] = 1;
                recordPtr[0x10] = 1;
                *(uint *)(recordPtr + 0xe) = fieldAccum & 0xffffffe5;
                defaultOperandWord2 = (*(unsigned int *)&DAT_001dbf94);
                recordPtr[10] = 0;
                *(undefined4 *)(recordPtr + -6) = defaultOperandWord2;
                *(undefined4 *)(recordPtr + -2) = defaultOperandWord2;
                *(undefined4 *)(recordPtr + -4) = defaultOperandWord2;
              }
            }
            recordPtr = recordPtr + 0x20;
            slotWordPtr = slotWordPtr + -0x20;
          } while (halfIndexB != 2);
          halfCounter2 = 0;
          slotWordPtr = decoded;
          do {
            if (((slotWordPtr[1] != 0 || slotWordPtr[3] != 0) || ((*(uint *)(slotWordPtr + 0x18) & 1) != 0)) &&
               ((decoded[0xd] != 0 || decoded[0xe] != 0) || decoded[0xf] != 0)) {
              *(uint *)(slotWordPtr + 0x18) = *(uint *)(slotWordPtr + 0x18) | 2;
            }
            loopContinue = halfCounter2 != 1;
            slotWordPtr = slotWordPtr + 0x20;
            decoded = decoded + 0x1d;
            halfCounter2 = halfCounter2 + 1;
          } while (loopContinue);
          return;
        }
      } while( true );
    }
    alphaSourceModifier = alphaWordValue >> 5 & 3;
LAB_000c1c40:
    hwImage = 0;
    alphaSourceSelectCode = alphaWordValue & 0x1f;
    sourceModifier = alphaSourceModifier;
    slotWordPtr = decoded + 0x24;
    alphaSourcesLeft = alphaOpTableOffset;
    if (alphaOpTableOffset == 0) {
      alphaSourcesLeft = 1;
    }
    do {
      hwImage = hwImage + 1;
      *(undefined4 *)slotWordPtr = *(undefined4 *)(alphaSourceSelectCode * 4 + 0x1dc04c);
      slotWordPtr[1] = (ushort)(sourceModifier << 0xc) | slotWordPtr[1];
      alphaSourcesLeft = alphaSourcesLeft - 1;
      if (alphaSourcesLeft == 0) goto LAB_000c1cec;
      alphaSourceSelectCode = alphaWordValue >> 7 & 0x1f;
      sourceModifier = alphaWordValue >> 0xc & 3;
      if (hwImage != 1) {
        if (hwImage == 0) goto LAB_000c1c40;
        alphaSourceSelectCode = alphaWordValue >> 0xe & 0x1f;
        sourceModifier = alphaWordValue >> 0x13 & 3;
        if (hwImage != 2) {
          alphaSourceSelectCode = 0;
          sourceModifier = 0;
        }
      }
      slotWordPtr = slotWordPtr + 2;
    } while( true );
  }
  programWordPtr = hwImage * 4 + wordsMode2;
  decoded[2] = (ushort)(*(uint *)(programWordPtr + 0x18) >> 6) & 0x1f;
  decoded[0x40] = (ushort)*(undefined4 *)(programWordPtr + 0x18) & 0x1f;
  texFieldCode = *(uint *)(programWordPtr + 0x18) >> 0xf & 7;
  if (texFieldCode == 2) {
    decoded[0x1d] = 1;
    decoded[0x18] = 0;
    decoded[0x19] = 1;
    decoded[10] = 0xf;
  }
  else {
    if (texFieldCode < 3) {
      if (texFieldCode != 1) goto LAB_000c1950;
    }
    else if (4 < texFieldCode) goto LAB_000c1950;
    decoded[10] = 0xf;
    decoded[3] = 0xf;
  }
LAB_000c1950:
  texWord = *(uint *)(hwImage * 4 + wordsMode2 + 0x18);
  decoded[0x16] = 0x3f80;
  decoded[0x17] = 0;
  decoded[0x14] = (ushort)(texWord >> 3) & 0xf00 | (ushort)(texWord >> 0xf) & 7;
  return;
}

/* psnDecTrySwapAddressSlots @ 0xc1d60 (276 bytes) */
int psnDecTrySwapAddressSlots(entry, group, slotA, slotB)
  int entry;
  int group;
  uint slotA;
  uint slotB;
{
  int halfCursor;
  int slotAAddressPtr;
  int loopIndex;
  bool loopContinue;
  undefined2 savedAddress;
  ushort selectGroupBitsShort;
  uint selectSlot;
  int slotMaskBase;
  uint selectGroupBits;
  int slotBAddressPtr;
  int halfByteOffset;
  
  if (((*(uint *)(entry + 0x30) | *(uint *)(entry + 0x70)) & 0x10) != 0) {
    return 0;
  }
  if (slotA == 0) {
    slotMaskBase = group * 4 + entry;
    if (*(short *)(slotMaskBase + 0x20) != 0 || *(short *)(slotMaskBase + 0x60) != 0) {
      return 0;
    }
LAB_000c1da8:
    if (slotB != 1) goto LAB_000c1dd0;
  }
  else if (slotA != 1) goto LAB_000c1da8;
  slotMaskBase = group * 4 + entry;
  if (*(short *)(slotMaskBase + 0x22) != 0 || *(short *)(slotMaskBase + 0x62) != 0) {
    return 0;
  }
LAB_000c1dd0:
  halfByteOffset = 0;
  slotBAddressPtr = (group * 3 + slotB) * 2 + entry;
  slotAAddressPtr = (group * 3 + slotA) * 2 + entry;
  savedAddress = *(undefined2 *)(slotAAddressPtr + 0x80);
  *(undefined2 *)(slotAAddressPtr + 0x80) = *(undefined2 *)(slotBAddressPtr + 0x80);
  *(undefined2 *)(slotBAddressPtr + 0x80) = savedAddress;
  do {
    halfCursor = entry + halfByteOffset;
    loopIndex = 0;
    do {
      selectGroupBits = *(ushort *)(halfCursor + 8) & 0x300;
      selectSlot = *(ushort *)(halfCursor + 8) & 3;
      if (selectGroupBits == (group + 1) * 0x100) {
        selectGroupBitsShort = (ushort)selectGroupBits;
        if (slotA == selectSlot) {
          *(ushort *)(halfCursor + 8) = (ushort)slotB | selectGroupBitsShort;
        }
        else if (slotB == selectSlot) {
          *(ushort *)(halfCursor + 8) = (ushort)slotA | selectGroupBitsShort;
        }
      }
      loopContinue = loopIndex != 2;
      halfCursor = halfCursor + 4;
      loopIndex = loopIndex + 1;
    } while (loopContinue);
    loopContinue = halfByteOffset != 0x40;
    halfByteOffset = halfByteOffset + 0x40;
  } while (loopContinue);
  return 1;
}

/* psnDecSortAddressSlots @ 0xc1e90 (232 bytes) */
int psnDecSortAddressSlots(entry, group)
  int entry;
  int group;
{
  ushort slotTwoAddress;
  int groupSlots;
  uint swapResult;
  uint anySwapped;
  
  anySwapped = 0;
  groupSlots = group * 6 + entry;
  if (*(ushort *)(groupSlots + 0x84) < *(ushort *)(groupSlots + 0x82)) {
    anySwapped = ((int (*)())psnDecTrySwapAddressSlots)(entry,group,1,2);
  }
  groupSlots = group * 6 + entry;
  slotTwoAddress = *(ushort *)(groupSlots + 0x82);
  if (slotTwoAddress < *(ushort *)(groupSlots + 0x80)) {
    swapResult = ((int (*)())psnDecTrySwapAddressSlots)(entry,group,0,1);
    slotTwoAddress = *(ushort *)(groupSlots + 0x82);
    anySwapped = anySwapped | swapResult;
  }
  if (*(ushort *)(groupSlots + 0x84) < slotTwoAddress) {
    swapResult = ((int (*)())psnDecTrySwapAddressSlots)(entry,group,1,2);
    anySwapped = anySwapped | swapResult;
  }
  if (anySwapped != 0) {
    ((int (*)())psnDecRecomputeSourceUsage)(entry);
  }
  return anySwapped;
}

/* psnDecEncodeHwWords @ 0xc1f80 (1824 bytes) */
int psnDecEncodeHwWords(decodedProgram, rsWords, programImage)
  uint *decodedProgram;
  int rsWords;
  int programImage;
{
  uint decodedProgramWord0;
  uint decodedProgramWord8;
  int loopIndex2;
  int loopIndex;
  bool moreLoops;
  ushort alphaDestReg;
  ushort sourceSlotWord;
  ushort rgbRegField;
  ushort interpModeField;
  ushort alphaRegField;
  float oneF;
  int entryMode;
  int halfCursorSwizzle;
  int halfCursorScale;
  int aluWordBaseA;
  int slotCursor;
  int alphaWritten;
  int texWordPtrB;
  int texWordPtr;
  int recordIndexBytes;
  uint oldWordValue;
  uint alphaSelectAccum;
  uint alphaRegValue;
  uint newFieldBitsB;
  int entry;
  uint newFieldBits;
  uint swizzleByte;
  uint scaleCode;
  uint rgbSelectAccum;
  uint rgbRegValue;
  uint regLowBits;
  int rsWordPtr;
  int aluWordPtr;
  uint swizzleSel;
  uint destRegField;
  uint rgbSourceSelect;
  uint oldWordValueB;
  int aluWordBase;
  int sourceSlotBase;
  uint loopIndex3;
  uint oldWordValueC;
  uint alphaSourceSelect;
  double scaleValue;
  
  decodedProgramWord0 = *decodedProgram;
  if (decodedProgramWord0 != 0) {
    loopIndex3 = 0;
    do {
      decodedProgramWord8 = decodedProgram[2];
      entry = loopIndex3 * 0xa0 + decodedProgramWord8;
      entryMode = *(int *)(entry + 0x8c);
      recordIndexBytes = *(int *)(entry + 0x90);
      destRegField = (uint)*(ushort *)(entry + 4);
      alphaDestReg = *(ushort *)(entry + 0x44);
      if (entryMode == 1) {
        texWordPtr = recordIndexBytes * 4 + programImage;
        oldWordValue = *(uint *)(texWordPtr + 0x18);
        newFieldBits = (destRegField & 0x1f) << 6;
        *(uint *)(texWordPtr + 0x18) = newFieldBits | oldWordValue & 0xfffff83f;
        if ((*(short *)(entry + 2) == 0 && *(short *)(entry + 6) == 0) &&
           ((*(uint *)(entry + 0x30) & 1) == 0)) {
          *(uint *)(texWordPtr + 0x18) = newFieldBits | oldWordValue & 0xfffc783f;
        }
        recordIndexBytes = recordIndexBytes * 4 + programImage;
        oldWordValueB = *(uint *)(recordIndexBytes + 0x18);
        regLowBits = *(ushort *)(entry + 0x80) & 0x1f;
        *(uint *)(recordIndexBytes + 0x18) = regLowBits | oldWordValueB & 0xffffffe0;
        newFieldBitsB = (*(byte *)(entry + 0x29) & 7) << 0xf;
        *(uint *)(recordIndexBytes + 0x18) = newFieldBitsB | regLowBits | oldWordValueB & 0xfffc7fe0;
        *(uint *)(recordIndexBytes + 0x18) =
             (*(ushort *)(entry + 0x28) & 0xf00) << 3 | newFieldBitsB | regLowBits | oldWordValueB & 0xfff807e0;
        decodedProgramWord0 = *decodedProgram;
      }
      else if (entryMode == 0) {
        recordIndexBytes = recordIndexBytes * 4;
        texWordPtrB = recordIndexBytes + rsWords;
        oldWordValueC = *(uint *)(texWordPtrB + 4);
        newFieldBits = (destRegField & 0x7f) << 0x12;
        newFieldBitsB = (alphaDestReg & 0x7f) << 5;
        *(uint *)(texWordPtrB + 4) = newFieldBitsB | newFieldBits | oldWordValueC & 0xfe03f01f;
        if ((*(short *)(entry + 2) == 0 && *(short *)(entry + 6) == 0) &&
           ((*(uint *)(entry + 0x30) & 1) == 0)) {
          *(uint *)(texWordPtrB + 4) = newFieldBitsB | newFieldBits | oldWordValueC & 0xfe00f01f;
        }
        else {
          interpModeField = *(ushort *)(entry + 0x3a);
          if ((interpModeField == 2) || (interpModeField == 3)) {
            *(uint *)(recordIndexBytes + rsWords + 4) =
                 (interpModeField & 3) << 0x10 | *(uint *)(recordIndexBytes + rsWords + 4) & 0xfffcffff;
          }
          else if (interpModeField == 0) {
            *(uint *)(recordIndexBytes + rsWords + 4) = *(uint *)(recordIndexBytes + rsWords + 4) & 0xfffcffff | 0x10000;
          }
        }
        if ((*(short *)(entry + 0x42) != 0 || *(short *)(entry + 0x46) != 0) ||
           (alphaWritten = 0, (*(uint *)(entry + 0x70) & 1) != 0)) {
          alphaWritten = 1;
        }
        rsWordPtr = recordIndexBytes + rsWords;
        oldWordValue = *(uint *)(rsWordPtr + 4);
        newFieldBits = alphaWritten << 4;
        *(uint *)(rsWordPtr + 4) = newFieldBits | oldWordValue & 0xffffffef;
        if (*(ushort *)(entry + 0x80) == 0xffff) {
          *(uint *)(rsWordPtr + 4) = newFieldBits | oldWordValue & 0xffff0fef;
        }
        else {
          *(uint *)(rsWordPtr + 4) =
               (*(ushort *)(entry + 0x80) & 0xf) << 0xc | newFieldBits | oldWordValue & 0xffff0fef;
        }
        if (*(ushort *)(entry + 0x86) == 0xffff) {
          *(uint *)(recordIndexBytes + rsWords + 4) = *(uint *)(recordIndexBytes + rsWords + 4) & 0xfffffff0;
        }
        else {
          *(uint *)(recordIndexBytes + rsWords + 4) =
               *(ushort *)(entry + 0x86) & 0xf | *(uint *)(recordIndexBytes + rsWords + 4) & 0xfffffff0;
        }
        oneF = FLOAT_001aa0e8;
        recordIndexBytes = recordIndexBytes + rsWords;
        oldWordValue = *(uint *)(recordIndexBytes + 4);
        newFieldBits = (uint)(*(float *)(entry + 0x2c) != FLOAT_001aa0e8) << 0x1b;
        *(uint *)(recordIndexBytes + 4) = newFieldBits | oldWordValue & 0x7ffffff;
        *(uint *)(recordIndexBytes + 4) =
             (uint)(*(float *)(entry + 0x6c) != oneF) << 0x19 | newFieldBits | oldWordValue & 0x5ffffff;
        decodedProgramWord0 = *decodedProgram;
      }
      else if (entryMode == 2) {
        recordIndexBytes = recordIndexBytes * 4;
        aluWordPtr = recordIndexBytes + programImage;
        loopIndex2 = 0;
        *(uint *)(aluWordPtr + 0x98) = (destRegField & 0x1f) << 0x12 | *(uint *)(aluWordPtr + 0x98) & 0xff83ffff;
        *(uint *)(aluWordPtr + 0x198) = (alphaDestReg & 0x1f) << 0x12 | *(uint *)(aluWordPtr + 0x198) & 0xff83ffff;
        oldWordValueB = *(uint *)(aluWordPtr + 0x98);
        newFieldBits = (*(ushort *)(entry + 2) & 7) << 0x1a;
        *(uint *)(aluWordPtr + 0x98) = newFieldBits | oldWordValueB & 0xe3ffffff;
        *(uint *)(aluWordPtr + 0x98) =
             (*(ushort *)(loopIndex3 * 0xa0 + decodedProgramWord8) & 3) << 0x1d | newFieldBits | oldWordValueB & 0x83ffffff;
        oldWordValueB = *(uint *)(aluWordPtr + 0x198);
        newFieldBits = (*(ushort *)(entry + 0x42) & 8) << 0x15;
        *(uint *)(aluWordPtr + 0x198) = newFieldBits | oldWordValueB & 0xfeffffff;
        newFieldBitsB = (*(ushort *)(entry + 0x42) & 0x10) << 0x17;
        *(uint *)(aluWordPtr + 0x198) = newFieldBitsB | newFieldBits | oldWordValueB & 0xf6ffffff;
        *(uint *)(aluWordPtr + 0x198) =
             (*(ushort *)(entry + 0x40) & 3) << 0x19 | newFieldBitsB | newFieldBits | oldWordValueB & 0xf0ffffff;
        *(uint *)(aluWordPtr + 0x98) =
             (*(ushort *)(entry + 6) & 7) << 0x17 | *(uint *)(aluWordPtr + 0x98) & 0xfc7fffff;
        *(uint *)(aluWordPtr + 0x198) =
             (*(ushort *)(entry + 0x46) & 8) << 0x14 | *(uint *)(aluWordPtr + 0x198) & 0xff7fffff;
        slotCursor = entry;
        do {
          rgbRegField = *(ushort *)(slotCursor + 0x80);
          rgbRegValue = (uint)rgbRegField;
          alphaRegField = *(ushort *)(slotCursor + 0x86);
          alphaRegValue = (uint)alphaRegField;
          if (rgbRegValue == 0xffff) {
            rgbRegValue = 0x20;
          }
          else if ((short)rgbRegField < 0) {
            rgbRegValue = ((int)(short)rgbRegField & 0x7fffU) + 0x20;
          }
          if (alphaRegValue == 0xffff) {
            alphaRegValue = 0x20;
          }
          else if ((short)alphaRegField < 0) {
            alphaRegValue = ((int)(short)alphaRegField & 0x7fffU) + 0x20;
          }
          if (loopIndex2 == 1) {
            *(uint *)(aluWordPtr + 0x98) = (rgbRegValue & 0x3f) << 6 | *(uint *)(aluWordPtr + 0x98) & 0xfffff03f;
            *(uint *)(aluWordPtr + 0x198) = (alphaRegValue & 0x3f) << 6 | *(uint *)(aluWordPtr + 0x198) & 0xfffff03f
            ;
          }
          else if (loopIndex2 == 0) {
            *(uint *)(aluWordPtr + 0x98) = rgbRegValue & 0x3f | *(uint *)(aluWordPtr + 0x98) & 0xffffffc0;
            *(uint *)(aluWordPtr + 0x198) = alphaRegValue & 0x3f | *(uint *)(aluWordPtr + 0x198) & 0xffffffc0;
          }
          else if (loopIndex2 == 2) {
            *(uint *)(aluWordPtr + 0x98) = (rgbRegValue & 0x3f) << 0xc | *(uint *)(aluWordPtr + 0x98) & 0xfffc0fff
            ;
            *(uint *)(aluWordPtr + 0x198) =
                 (alphaRegValue & 0x3f) << 0xc | *(uint *)(aluWordPtr + 0x198) & 0xfffc0fff;
          }
          moreLoops = loopIndex2 != 2;
          slotCursor = slotCursor + 2;
          loopIndex2 = loopIndex2 + 1;
        } while (moreLoops);
        aluWordBaseA = recordIndexBytes + programImage;
        loopIndex = 0;
        do {
          rgbSourceSelect = 0;
          rgbSelectAccum = 0;
          alphaSourceSelect = 0;
          alphaSelectAccum = 0;
          loopIndex2 = 0;
          sourceSlotBase = entry + 8;
          do {
            sourceSlotWord = *(ushort *)(loopIndex * 4 + sourceSlotBase + 2);
            swizzleSel = *(ushort *)(loopIndex * 4 + sourceSlotBase) & 3;
            if (loopIndex2 == 0) {
              rgbSourceSelect = 6;
              if (((sourceSlotWord & 0x300) != 0x100) && (rgbSourceSelect = 5, (sourceSlotWord & 0x300) != 0x200)) {
                rgbSourceSelect = sourceSlotWord & 0x1f;
              }
              rgbSelectAccum = (sourceSlotWord & 0x3000) >> 0xc;
              rgbSourceSelect = (uint)*(byte *)(rgbSourceSelect * 4 + 0x1dc000 + swizzleSel);
            }
            else if (loopIndex2 == 1) {
              alphaSelectAccum = (sourceSlotWord & 0x3000) >> 0xc;
              alphaSourceSelect = (uint)*(byte *)((sourceSlotWord & 0x1f) * 4 + 0x1dbfb4 + swizzleSel);
            }
            moreLoops = loopIndex2 != 1;
            sourceSlotBase = sourceSlotBase + 0x40;
            loopIndex2 = loopIndex2 + 1;
          } while (moreLoops);
          if (loopIndex == 1) {
            *(uint *)(aluWordBaseA + 0x298) =
                 rgbSelectAccum << 0xc | (rgbSourceSelect & 0x1f) << 7 | *(uint *)(aluWordBaseA + 0x298) & 0xffffc07f;
            *(uint *)(aluWordBaseA + 0x398) =
                 alphaSelectAccum << 0xc | (alphaSourceSelect & 0x1f) << 7 | *(uint *)(aluWordBaseA + 0x398) & 0xffffc07f;
          }
          else if (loopIndex == 0) {
            *(uint *)(aluWordBaseA + 0x298) =
                 rgbSelectAccum << 5 | rgbSourceSelect & 0x1f | *(uint *)(aluWordBaseA + 0x298) & 0xffffff80;
            *(uint *)(aluWordBaseA + 0x398) =
                 alphaSelectAccum << 5 | alphaSourceSelect & 0x1f | *(uint *)(aluWordBaseA + 0x398) & 0xffffff80;
          }
          else if (loopIndex == 2) {
            *(uint *)(aluWordBaseA + 0x298) =
                 rgbSelectAccum << 0x13 | (rgbSourceSelect & 0x1f) << 0xe | *(uint *)(aluWordBaseA + 0x298) & 0xffe03fff;
            *(uint *)(aluWordBaseA + 0x398) =
                 alphaSelectAccum << 0x13 | (alphaSourceSelect & 0x1f) << 0xe | *(uint *)(aluWordBaseA + 0x398) & 0xffe03fff;
          }
          moreLoops = loopIndex != 2;
          loopIndex = loopIndex + 1;
        } while (moreLoops);
        loopIndex = 0;
        halfCursorScale = entry;
        do {
          scaleValue = (double)*(float *)(halfCursorScale + 0x2c) * DOUBLE_001aa290;
          if (DOUBLE_001aa1e8 <= scaleValue) {
            scaleCode = (int)(scaleValue - DOUBLE_001aa1e8) + 0x80000000;
          }
          else {
            scaleCode = (uint)(int)scaleValue;
          }
          switch(scaleCode) {
          case 1:
            scaleCode = 6;
            break;
          case 2:
            scaleCode = 5;
            break;
          case 4:
            scaleCode = 4;
            break;
          case 8:
            scaleCode = 0;
            break;
          case 0x10:
            scaleCode = 1;
            break;
          case 0x20:
            scaleCode = 2;
            break;
          case 0x40:
            scaleCode = 3;
          }
          if (loopIndex == 0) {
            aluWordBase = recordIndexBytes + programImage;
            oldWordValue = *(uint *)(aluWordBase + 0x298);
            scaleCode = (scaleCode & 7) << 0x1b;
            *(uint *)(aluWordBase + 0x298) = scaleCode | oldWordValue & 0xc7ffffff;
            *(uint *)(aluWordBase + 0x298) =
                 (*(uint *)(entry + 0x30) & 8) << 0x1b | scaleCode | oldWordValue & 0x87ffffff;
          }
          else if (loopIndex == 1) {
            aluWordBase = recordIndexBytes + programImage;
            oldWordValue = *(uint *)(aluWordBase + 0x398);
            scaleCode = (scaleCode & 7) << 0x1b;
            *(uint *)(aluWordBase + 0x398) = scaleCode | oldWordValue & 0xc7ffffff;
            *(uint *)(aluWordBase + 0x398) =
                 (*(uint *)(entry + 0x70) & 8) << 0x1b | scaleCode | oldWordValue & 0x87ffffff;
          }
          moreLoops = loopIndex != 1;
          halfCursorScale = halfCursorScale + 0x40;
          loopIndex = loopIndex + 1;
        } while (moreLoops);
        recordIndexBytes = recordIndexBytes + programImage;
        loopIndex = 0;
        halfCursorSwizzle = entry;
        do {
          swizzleByte = (uint)*(byte *)((uint)*(ushort *)(halfCursorSwizzle + 0x28) * 2 + 0x1dbf98 + loopIndex);
          if (loopIndex == 0) {
            oldWordValue = *(uint *)(recordIndexBytes + 0x298);
            swizzleByte = (swizzleByte & 0xf) << 0x17;
            *(uint *)(recordIndexBytes + 0x298) = swizzleByte | oldWordValue & 0xf87fffff;
            *(uint *)(recordIndexBytes + 0x298) =
                 (*(ushort *)(entry + 0x2a) & 3) << 0x15 | swizzleByte | oldWordValue & 0xf81fffff;
          }
          else if (loopIndex == 1) {
            oldWordValue = *(uint *)(recordIndexBytes + 0x398);
            swizzleByte = (swizzleByte & 0xf) << 0x17;
            *(uint *)(recordIndexBytes + 0x398) = swizzleByte | oldWordValue & 0xf87fffff;
            *(uint *)(recordIndexBytes + 0x398) =
                 (*(ushort *)(entry + 0x6a) & 3) << 0x15 | swizzleByte | oldWordValue & 0xf81fffff;
          }
          moreLoops = loopIndex != 1;
          halfCursorSwizzle = halfCursorSwizzle + 0x40;
          loopIndex = loopIndex + 1;
        } while (moreLoops);
        decodedProgramWord0 = *decodedProgram;
      }
      loopIndex3 = loopIndex3 + 1;
    } while (loopIndex3 < decodedProgramWord0);
  }
  return;
}

/* psnDecAllocateTempsAndCompact @ 0xc2834 (1536 bytes) */
int psnDecAllocateTempsAndCompact(psnState, decodedProgram, rsWords, programImage)
  int psnState;
  uint *decodedProgram;
  int rsWords;
  undefined4 programImage;
{
  short *usageWordCursor;
  undefined4 returnStatus;
  uint stackTop;
  ushort readMask;
  ushort writeMaskLive;
  ushort newTempRegister;
  ushort liveMaskBefore;
  ushort destLiveMask;
  uint entryCountAfterLoop;
  uint entryCount;
  ushort *addressSlotPtr;
  int scanEntry;
  int entryOffset;
  int freeListIndex;
  int groupUsageCursor;
  int addressSlotOffset;
  int halfByteOffset2;
  int groupCounter;
  int groupCursor;
  int halfByteOffset;
  int halfCursor;
  bool outputHasDepthBit;
  uint loopIndex2;
  uint loopIndex;
  bool loopContinue;
  int entryMode;
  uint freeEntryNext;
  undefined4 r4AfterCall;
  int slotCounter;
  int groupUsageBase;
  int slotOffset;
  undefined4 staleArgR7;
  int halfCounter;
  undefined2 *destMapEntry;
  int halfCounter2;
  uint tempRegisterCount;
  short targetIndex;
  ushort outputMask;
  ushort renderTarget;
  short *targetInitCursor;
  ushort *sourceMapEntry;
  uint freeEntryValue;
  ushort *halfWords;
  ushort *readMaskPtr;
  uint *freeTempStack;
  short *targetLiveTable;
  undefined2 mappedAlphaDest;
  undefined2 mappedRgbDest;
  uint regMapTable;
  int entry;
  int initCounter;
  uint uStack_68;
  uint maxTempIndex;
  short *freeTempList;
  undefined4 constOneBits;
  
  tempRegisterCount = *(uint *)(psnState + 0x30);
  regMapTable = decodedProgram[3];
  targetLiveTable = (short *)(regMapTable + tempRegisterCount * 4);
  freeTempList = targetLiveTable + 8;
  if (rsWords == 0) {
    freeTempStack = (uint *)0x0;
  }
  else {
    freeTempStack = &uStack_68;
    tempRegisterCount = 0x80;
  }
  targetIndex = 0;
  initCounter = 4;
  targetInitCursor = targetLiveTable;
  do {
    *targetInitCursor = targetIndex;
    targetInitCursor[1] = 0xf;
    targetIndex = targetIndex + 1;
    targetInitCursor = targetInitCursor + 2;
    initCounter = initCounter + -1;
  } while (initCounter != 0);
  targetLiveTable[1] = targetLiveTable[1] | 0x10;
  _memset(regMapTable,0,*(int *)(psnState + 0x30) << 2);
  uStack_68 = 0;
  if (tempRegisterCount != 0) {
    uStack_68 = tempRegisterCount & 0xffff;
    freeListIndex = 0;
    freeEntryValue = uStack_68;
    do {
      freeEntryNext = freeEntryValue - 1;
      freeEntryValue = freeEntryNext & 0xffff;
      freeTempList[freeListIndex] = (short)freeEntryNext;
      tempRegisterCount = tempRegisterCount - 1;
      freeListIndex = freeListIndex + 1;
    } while (tempRegisterCount != 0);
  }
  loopIndex = 0;
  maxTempIndex = 0;
  entryCount = *decodedProgram;
  entryOffset = (entryCount - 1) * 0xa0;
  do {
    entry = entryOffset + decodedProgram[2];
    entryMode = *(int *)(entry + 0x8c);
    if (entryMode == 2) {
      halfCounter = 0;
      slotOffset = 0;
      halfCursor = entry;
      do {
        if (((((*(ushort *)(halfCursor + 6) != 0) && ((*(uint *)(halfCursor + 0x30) & 0x400) != 0)) &&
             ((*(uint *)(halfCursor + 0x30) & 0x1800) == 0)) &&
            ((constOneBits = 0x3f800000, *(float *)(halfCursor + 0x2c) == 1.0 &&
             ((*(ushort *)(halfCursor + 10) & 0x10) == 0)))) &&
           ((*(short *)((slotOffset + (*(ushort *)(halfCursor + 8) & 3)) * 2 + entry + 0x80) ==
             *(short *)(halfCursor + 4) &&
            ((*(ushort *)(halfCursor + 6) & ~(*(ushort *)(halfCursor + 10) & 0xf)) == 0)))) {
          *(undefined2 *)(halfCursor + 6) = 0;
        }
        loopContinue = halfCounter != 1;
        halfCursor = halfCursor + 0x40;
        slotOffset = slotOffset + 3;
        halfCounter = halfCounter + 1;
      } while (loopContinue);
      entryMode = *(int *)(entry + 0x8c);
    }
    if (entryMode == 2) {
      halfByteOffset = 0;
      do {
        halfWords = (ushort *)(halfByteOffset + entry);
        outputMask = halfWords[1];
        outputHasDepthBit = (outputMask >> 4 & 1) != 0;
        if ((outputHasDepthBit) && ((targetLiveTable[1] & 0x10U) == 0)) {
          outputMask = outputMask & 0xffef;
          halfWords[1] = outputMask;
        }
        renderTarget = *halfWords;
        outputMask = (targetLiveTable[(uint)renderTarget * 2 + 1] | 0x10U) & outputMask;
        halfWords[1] = outputMask;
        targetLiveTable[(uint)renderTarget * 2 + 1] = targetLiveTable[(uint)renderTarget * 2 + 1] & ~outputMask;
        if (outputHasDepthBit) {
          targetLiveTable[1] = targetLiveTable[1] & 0xffef;
        }
        loopContinue = halfByteOffset != 0x40;
        halfByteOffset = halfByteOffset + 0x40;
      } while (loopContinue);
    }
    halfByteOffset2 = 0;
    mappedRgbDest = *(undefined2 *)(regMapTable + (uint)*(ushort *)(entry + 4) * 4);
    mappedAlphaDest = *(undefined2 *)((uint)*(ushort *)(entry + 0x44) * 4 + regMapTable);
    halfCursor = entry;
    do {
      destMapEntry = (undefined2 *)(regMapTable + (uint)*(ushort *)(halfCursor + 4) * 4);
      destLiveMask = destMapEntry[1];
      writeMaskLive = destLiveMask & *(ushort *)(halfCursor + 6);
      *(ushort *)(halfCursor + 6) = writeMaskLive;
      if ((*(int *)(entry + 0x8c) != 2) && (writeMaskLive != 0)) {
        writeMaskLive = 0xf;
        *(undefined2 *)(halfCursor + 6) = 0xf;
      }
      destMapEntry[1] = destMapEntry[1] & ~writeMaskLive;
      if ((*(short *)(halfCursor + 2) == 0 && *(short *)(halfCursor + 6) == 0) &&
         ((*(uint *)(halfCursor + 0x30) & 1) == 0)) {
        *(undefined4 *)(halfCursor + 0x24) = 0;
        *(undefined4 *)(halfCursor + 0x14) = 0;
        *(undefined4 *)(halfCursor + 0x18) = 0;
        *(undefined4 *)(halfCursor + 0x1c) = 0;
        *(undefined4 *)(halfCursor + 0x20) = 0;
      }
      if (((freeTempStack != (uint *)0x0) && (destLiveMask != 0)) && (destMapEntry[1] == 0)) {
        stackTop = *freeTempStack;
        *(undefined2 *)(stackTop * 2 + freeTempStack[2]) = *destMapEntry;
        *freeTempStack = stackTop + 1;
        *destMapEntry = 0;
      }
      loopContinue = halfByteOffset2 != 0x40;
      halfCursor = halfCursor + 0x40;
      halfByteOffset2 = halfByteOffset2 + 0x40;
    } while (loopContinue);
    halfCounter = 0;
    addressSlotOffset = 0x80;
    groupCursor = entry;
    do {
      addressSlotPtr = (ushort *)(entry + addressSlotOffset);
      slotCounter = 0;
      groupUsageBase = groupCursor + 0x10;
      do {
        if ((*addressSlotPtr & 0x8000) == 0) {
          readMaskPtr = (ushort *)(groupUsageBase + 4);
          halfCounter2 = 0;
          sourceMapEntry = (ushort *)(regMapTable + (uint)*addressSlotPtr * 4);
          do {
            liveMaskBefore = sourceMapEntry[1];
            readMask = *readMaskPtr;
            sourceMapEntry[1] = readMask | liveMaskBefore;
            if ((liveMaskBefore == 0) && (readMask != 0)) {
              uStack_68 = uStack_68 - 1;
              newTempRegister = freeTempList[uStack_68];
              if (maxTempIndex < newTempRegister) {
                maxTempIndex = (uint)newTempRegister;
              }
              *sourceMapEntry = newTempRegister;
            }
            loopContinue = halfCounter2 != 1;
            readMaskPtr = readMaskPtr + 0x20;
            halfCounter2 = halfCounter2 + 1;
          } while (loopContinue);
        }
        loopContinue = slotCounter != 2;
        groupUsageBase = groupUsageBase + 2;
        addressSlotPtr = addressSlotPtr + 1;
        slotCounter = slotCounter + 1;
      } while (loopContinue);
      loopContinue = halfCounter != 1;
      groupCursor = groupCursor + 6;
      addressSlotOffset = addressSlotOffset + 6;
      halfCounter = halfCounter + 1;
    } while (loopContinue);
    if (*(short *)(entry + 6) == 0) {
      mappedRgbDest = 0;
    }
    *(undefined2 *)(entry + 4) = mappedRgbDest;
    if (*(short *)(entry + 0x46) == 0) {
      mappedAlphaDest = 0;
    }
    *(undefined2 *)(entry + 0x44) = mappedAlphaDest;
    groupCounter = 0;
    staleArgR7 = 0xffffffff;
    groupUsageCursor = entry + 0x10;
    do {
      usageWordCursor = (short *)(groupUsageCursor + 4);
      halfCounter = 0;
      do {
        if (*usageWordCursor == 0 && usageWordCursor[0x20] == 0) {
          usageWordCursor[0x36] = -1;
        }
        else if ((usageWordCursor[0x36] & 0x8000U) == 0) {
          usageWordCursor[0x36] = *(short *)(regMapTable + (uint)(ushort)usageWordCursor[0x36] * 4);
        }
        loopContinue = halfCounter != 2;
        usageWordCursor = usageWordCursor + 1;
        halfCounter = halfCounter + 1;
      } while (loopContinue);
      loopContinue = groupCounter != 1;
      groupUsageCursor = groupUsageCursor + 6;
      groupCounter = groupCounter + 1;
    } while (loopContinue);
    if (*(int *)(entry + 0x8c) == 2) {
      ((int (*)())psnDecRecomputeSourceUsage)(entry);
      ((int (*)())psnDecSortAddressSlots)(entry,0);
      ((int (*)())psnDecSortAddressSlots)(entry,1);
      ((int (*)())psnDecCanonicalizeEntry)(entry,r4AfterCall,slotCounter,groupUsageBase,staleArgR7,groupCounter,usageWordCursor,groupUsageCursor);
    }
    loopIndex = loopIndex + 1;
    entryOffset = entryOffset + -0xa0;
  } while (entryCount != loopIndex);
  entryCountAfterLoop = *decodedProgram;
  if (entryCountAfterLoop == 0) {
    loopIndex = 0;
  }
  else {
    loopIndex2 = 0;
    loopIndex = 0;
    do {
      scanEntry = decodedProgram[2] + loopIndex2 * 0xa0;
      if (((*(short *)(scanEntry + 2) != 0 || *(short *)(scanEntry + 6) != 0) ||
          ((*(uint *)(scanEntry + 0x30) & 1) != 0)) ||
         ((*(short *)(scanEntry + 0x42) != 0 || *(short *)(scanEntry + 0x46) != 0 ||
          ((*(uint *)(scanEntry + 0x70) & 1) != 0)))) {
        if (loopIndex < loopIndex2) {
          _memcpy(loopIndex * 0xa0 + decodedProgram[2],scanEntry,0xa0);
          entryCountAfterLoop = *decodedProgram;
        }
        loopIndex = loopIndex + 1;
      }
      loopIndex2 = loopIndex2 + 1;
    } while (loopIndex2 < entryCountAfterLoop);
  }
  *decodedProgram = loopIndex;
  decodedProgram[1] = maxTempIndex + 1;
  if (loopIndex == 0) {
    returnStatus = 0x80000004;
  }
  else {
    if (rsWords != 0) {
      ((int (*)())psnDecEncodeHwWords)(decodedProgram,rsWords,programImage);
    }
    returnStatus = 0;
  }
  return returnStatus;
}

/* psnMaskIsSingleComponent @ 0xc2e40 (48 bytes) */
int psnMaskIsSingleComponent(writeMask)
  undefined4 writeMask;
{
  ushort maskBits;
  
  maskBits = (*(unsigned short *)((unsigned char *)&(writeMask) + 2)) & 0xf;
  if (((1 < (ushort)(maskBits - 1)) && (maskBits != 4)) && (maskBits != 8)) {
    return 0;
  }
  return 1;
}

/* psnDecAlphaDestIs @ 0xc2e70 (36 bytes) */
int psnDecAlphaDestIs(entry, registerNumber)
  int entry;
  uint registerNumber;
{
  if (((*(ushort *)(entry + 0x46) & 8) != 0) && (*(ushort *)(entry + 0x44) == registerNumber)) {
    return 1;
  }
  return 0;
}

/* psnDecAlphaComponentReadsReg @ 0xc2ea0 (120 bytes) */
int psnDecAlphaComponentReadsReg(entry, registerNumber, passThroughR5, passThroughR6)
  int entry;
  uint registerNumber;
  undefined4 passThroughR5;
  undefined4 passThroughR6;
{
  bool loopContinue;
  ushort *halfOneMaskPtr;
  int halfZeroMaskBase;
  int groupIndex;
  int loopIndex;
  int halfOneBase;
  int halfOneBaseRef;
  
  halfOneBase = entry + 0x50;
  halfOneBaseRef = entry + 0x54;
  groupIndex = 0;
  halfZeroMaskBase = entry + 0x14;
  do {
    halfOneMaskPtr = (ushort *)(halfOneBase + 4);
    loopIndex = 0;
    do {
      if (halfOneMaskPtr[0x16] == registerNumber) {
        if (((*(ushort *)((halfZeroMaskBase - halfOneBaseRef) + (int)halfOneMaskPtr) & 8) != 0) || ((*halfOneMaskPtr & 8) != 0)) {
          return 1;
        }
      }
      loopContinue = loopIndex != 2;
      halfOneMaskPtr = halfOneMaskPtr + 1;
      loopIndex = loopIndex + 1;
    } while (loopContinue);
    loopContinue = groupIndex == 1;
    halfOneBase = halfOneBase + 6;
    halfZeroMaskBase = halfZeroMaskBase + 6;
    halfOneBaseRef = halfOneBaseRef + 6;
    groupIndex = groupIndex + 1;
    if (loopContinue) {
      return 0;
    }
  } while( true );
}

/* psnDecAnySourceIsReg @ 0xc2f20 (140 bytes) */
int psnDecAnySourceIsReg(entry, usageMask, address)
  int entry;
  undefined4 usageMask;
  uint address;
{
  bool loopContinue;
  int halfUsageBase;
  int halfIndex;
  int loopIndex;
  int addressGroupOffset;
  ushort *readMaskPtr;
  int loopIndex2;
  ushort *addressSlotPtr;
  
  halfIndex = 0;
  do {
    loopIndex = 0;
    addressGroupOffset = 0;
    halfUsageBase = halfIndex * 0x40 + entry + 0x10;
    do {
      readMaskPtr = (ushort *)(halfUsageBase + 4);
      loopIndex2 = 0;
      addressSlotPtr = (ushort *)(entry + addressGroupOffset + 0x80);
      do {
        if ((((*(unsigned short *)((unsigned char *)&(usageMask) + 2)) & *readMaskPtr) != 0) && (*addressSlotPtr == address)) {
          return 1;
        }
        loopContinue = loopIndex2 != 2;
        readMaskPtr = readMaskPtr + 1;
        addressSlotPtr = addressSlotPtr + 1;
        loopIndex2 = loopIndex2 + 1;
      } while (loopContinue);
      loopContinue = loopIndex != 1;
      addressGroupOffset = addressGroupOffset + 6;
      halfUsageBase = halfUsageBase + 6;
      loopIndex = loopIndex + 1;
    } while (loopContinue);
    loopContinue = halfIndex == 1;
    halfIndex = halfIndex + 1;
    if (loopContinue) {
      return 0;
    }
  } while( true );
}

/* psnDecAnyPartialSourceIsReg @ 0xc2fb0 (148 bytes) */
int psnDecAnyPartialSourceIsReg(entry, usageMask, address)
  int entry;
  uint usageMask;
  uint address;
{
  bool loopContinue;
  int halfUsageBase;
  int halfIndex;
  int loopIndex;
  int addressGroupOffset;
  ushort *readMaskPtr;
  int loopIndex2;
  ushort *addressSlotPtr;
  
  halfIndex = 0;
  do {
    loopIndex = 0;
    addressGroupOffset = 0;
    halfUsageBase = halfIndex * 0x40 + entry + 0x10;
    do {
      readMaskPtr = (ushort *)(halfUsageBase + 4);
      loopIndex2 = 0;
      addressSlotPtr = (ushort *)(entry + addressGroupOffset + 0x80);
      do {
        if ((((*readMaskPtr & usageMask) != 0) && (*readMaskPtr != usageMask)) && (*addressSlotPtr == address)) {
          return 1;
        }
        loopContinue = loopIndex2 != 2;
        readMaskPtr = readMaskPtr + 1;
        addressSlotPtr = addressSlotPtr + 1;
        loopIndex2 = loopIndex2 + 1;
      } while (loopContinue);
      loopContinue = loopIndex != 1;
      addressGroupOffset = addressGroupOffset + 6;
      halfUsageBase = halfUsageBase + 6;
      loopIndex = loopIndex + 1;
    } while (loopContinue);
    loopContinue = halfIndex == 1;
    halfIndex = halfIndex + 1;
    if (loopContinue) {
      return 0;
    }
  } while( true );
}

/* psnDecMaskCoveredByDests @ 0xc3050 (64 bytes) */
int psnDecMaskCoveredByDests(entry, componentMask, registerNumber)
  int entry;
  uint componentMask;
  uint registerNumber;
{
  if (*(ushort *)(entry + 4) == registerNumber) {
    componentMask = componentMask & ~(uint)*(ushort *)(entry + 6);
  }
  if (registerNumber == *(ushort *)(entry + 0x44)) {
    componentMask = componentMask & ~(uint)*(ushort *)(entry + 0x46);
  }
  return componentMask == 0;
}

/* psnDecFirstFreeAddressSlot @ 0xc3090 (52 bytes) */
int psnDecFirstFreeAddressSlot(entry)
  int entry;
{
  bool bVar1;
  int loopIndex;
  
  loopIndex = 0;
  do {
    if (*(short *)(entry + 0x86) == -1) {
      return loopIndex;
    }
    bVar1 = loopIndex != 2;
    entry = entry + 2;
    loopIndex = loopIndex + 1;
  } while (bVar1);
  return -1;
}

/* psnDecHasFreeAddressSlot @ 0xc30d0 (40 bytes) */
int psnDecHasFreeAddressSlot(entry)
  undefined4 entry;
{
  uint uVar1;
  
  uVar1 = ((int (*)())psnDecFirstFreeAddressSlot)(entry);
  return ~uVar1 >> 0x1f;
}

/* psnDecRetargetSourceReg @ 0xc3100 (312 bytes) */
int psnDecRetargetSourceReg(entry, oldComponentSelect, newComponentSelect, newSlot, address)
  int entry;
  uint oldComponentSelect;
  uint newComponentSelect;
  int newSlot;
  uint address;
{
  bool loopContinue;
  ushort sourceSwizzle;
  uint scratchBits;
  int halfCursor;
  undefined4 r4AfterCall;
  uint newSlotCode;
  int newSlotAddressPtr;
  int oldAddressOffset;
  int sourceCounter;
  ushort *sourceSwizzlePtr;
  int halfCounter;
  
  scratchBits = newComponentSelect >> 3 & 1;
  if ((newComponentSelect & 7) != 0) {
    scratchBits = 0;
  }
  newSlotCode = 2;
  if ((newSlot != 2) && (newSlotCode = 3, newSlot != 3)) {
    newSlotCode = (uint)(newSlot == 1);
  }
  halfCounter = 0;
  oldAddressOffset = (uint)(oldComponentSelect == 8) * 3;
  newSlotAddressPtr = (scratchBits * 3 + newSlot) * 2 + entry;
  halfCursor = entry;
  do {
    sourceSwizzlePtr = (ushort *)(halfCursor + 10);
    sourceCounter = 0;
    do {
      sourceSwizzle = *sourceSwizzlePtr;
      scratchBits = (uint)sourceSwizzle;
      if (((sourceSwizzle & 0x1f) == oldComponentSelect) &&
         (*(ushort *)((oldAddressOffset + (sourceSwizzlePtr[-1] & 3)) * 2 + entry + 0x80) == address)) {
        *sourceSwizzlePtr = sourceSwizzle & 0xffe0 | (ushort)newComponentSelect;
        sourceSwizzlePtr[-1] = sourceSwizzlePtr[-1] & 0xfcfc | 0x200 | (ushort)newSlotCode;
        *(short *)(newSlotAddressPtr + 0x80) = (short)address;
      }
      loopContinue = sourceCounter != 2;
      sourceSwizzlePtr = sourceSwizzlePtr + 2;
      sourceCounter = sourceCounter + 1;
    } while (loopContinue);
    loopContinue = halfCounter != 1;
    halfCursor = halfCursor + 0x40;
    halfCounter = halfCounter + 1;
  } while (loopContinue);
  if (*(int *)(entry + 0x8c) == 2) {
    ((int (*)())psnDecRecomputeSourceUsage)(entry);
    ((int (*)())psnDecCanonicalizeEntry)(entry,r4AfterCall,newSlotCode,newSlotAddressPtr,oldAddressOffset,sourceCounter,sourceSwizzlePtr,scratchBits);
  }
  return 1;
}

/* psnDecReplaceSourceAddress @ 0xc3240 (916 bytes) */
int psnDecReplaceSourceAddress(entry, oldAddrWord, newAddrWord, halfSelect, oldAddressOffset, sourceReg, sourceSwizzlePtr, freeSlotIndex)
  int entry;
  uint oldAddrWord;
  uint newAddrWord;
  int halfSelect;
  uint oldAddressOffset;
  uint sourceReg;
  undefined4 sourceSwizzlePtr;
  int freeSlotIndex;
{
  bool replaceAlpha;
  int addrSlotScanCursor;
  int loopIndex9;
  int loopIndex8;
  int loopIndex7;
  int loopIndex5;
  int loopIndex4;
  int loopIndex3;
  bool slotLoopContinue;
  bool replaceRgb;
  bool loopContinue;
  ushort sourceSelectWord;
  ushort newOffsetShort;
  ushort *sourceSlotPtr;
  undefined4 *usageClearCursor;
  uint slotAddrSel;
  int *usageFlagCursor;
  uint sourceAddrSel;
  undefined4 r4AfterCall;
  uint halfIndex;
  int scanHalfCursorB;
  uint loopIndex2;
  uint sourceIndex;
  int selectBankOffset;
  int loopIndex6;
  undefined2 *addrSlotClearPtr;
  int scanHalfCursor;
  ushort *scanSlotPtr;
  uint replaceSelectBits;
  uint loopIndex;
  int addressUsageFlags [11];
  
  replaceSelectBits = (oldAddressOffset & 8) << 6;
  if ((oldAddressOffset & 7) == 0) {
    if ((oldAddressOffset & 8) == 0) {
      return 0;
    }
  }
  else {
    replaceSelectBits = replaceSelectBits | 0x100;
  }
  halfIndex = (uint)(halfSelect == 8);
  newOffsetShort = (ushort)oldAddressOffset;
  if ((oldAddressOffset == 0x10) || (oldAddressOffset == 0x12)) {
    oldAddressOffset = oldAddressOffset & 0xffff;
    loopIndex5 = 0;
    sourceSlotPtr = (ushort *)(entry + halfIndex * 0x40 + 8);
    do {
      slotLoopContinue = loopIndex5 != 2;
      sourceSlotPtr[1] = newOffsetShort;
      loopIndex5 = loopIndex5 + 1;
      *sourceSlotPtr = *sourceSlotPtr & 0xfcff;
      sourceSlotPtr = sourceSlotPtr + 2;
    } while (slotLoopContinue);
    sourceSwizzlePtr = 3;
    sourceIndex = sourceReg;
  }
  else {
    sourceIndex = 0;
    replaceRgb = (replaceSelectBits >> 8 & 1) != 0;
    replaceAlpha = replaceSelectBits >> 9 != 0;
    sourceSlotPtr = (ushort *)(entry + halfIndex * 0x40 + 8);
    do {
      sourceAddrSel = *sourceSlotPtr & 3;
      if (((sourceAddrSel < 3) && ((sourceSlotPtr[1] & 0x1f) == sourceReg)) &&
         (selectBankOffset = ((*sourceSlotPtr & 0x300) == 0x100 ^ 1) * 3,
         *(ushort *)((selectBankOffset + sourceAddrSel) * 2 + entry + 0x80) == oldAddrWord)) {
        loopIndex3 = 0;
        loopIndex8 = 0;
        do {
          usageClearCursor = (undefined4 *)((int)addressUsageFlags + loopIndex8);
          loopIndex6 = 0;
          do {
            loopContinue = loopIndex6 != 2;
            *usageClearCursor = 0;
            loopIndex6 = loopIndex6 + 1;
            usageClearCursor = usageClearCursor + 1;
          } while (loopContinue);
          loopContinue = loopIndex3 != 1;
          loopIndex8 = loopIndex8 + 0xc;
          loopIndex3 = loopIndex3 + 1;
        } while (loopContinue);
        loopIndex = 0;
        scanHalfCursorB = entry;
        scanHalfCursor = entry;
        do {
          scanSlotPtr = (ushort *)(scanHalfCursor + 8);
          loopIndex2 = 0;
          do {
            if ((halfIndex != loopIndex) || (sourceIndex != loopIndex2)) {
              sourceSelectWord = *scanSlotPtr;
              slotAddrSel = sourceSelectWord & 3;
              if (slotAddrSel == 3) {
                if (((sourceSelectWord & 0x100) != 0) &&
                   (addressUsageFlags[0] = 1, (ushort)(*(short *)(scanHalfCursorB + 0x2a) - 1U) < 2)) {
                  addressUsageFlags[1] = 1;
                }
                if (((sourceSelectWord & 0x200) != 0) &&
                   (addressUsageFlags[3] = 1, (ushort)(*(short *)(scanHalfCursorB + 0x2a) - 1U) < 2)) {
                  addressUsageFlags[4] = 1;
                }
              }
              else {
                if ((sourceSelectWord & 0x100) != 0) {
                  addressUsageFlags[slotAddrSel] = 1;
                }
                if ((sourceSelectWord & 0x200) != 0) {
                  addressUsageFlags[slotAddrSel + 3] = 1;
                }
              }
            }
            loopContinue = loopIndex2 != 2;
            scanSlotPtr = scanSlotPtr + 2;
            loopIndex2 = loopIndex2 + 1;
          } while (loopContinue);
          loopContinue = loopIndex != 1;
          scanHalfCursor = scanHalfCursor + 0x40;
          scanHalfCursorB = scanHalfCursorB + 0x40;
          loopIndex = loopIndex + 1;
        } while (loopContinue);
        loopIndex9 = 0;
        loopIndex4 = 0x80;
        halfSelect = 0;
        do {
          usageFlagCursor = (int *)((int)addressUsageFlags + halfSelect);
          addrSlotClearPtr = (undefined2 *)(entry + loopIndex4);
          loopIndex7 = 0;
          do {
            if (*usageFlagCursor == 0) {
              *addrSlotClearPtr = 0xffff;
            }
            loopContinue = loopIndex7 != 2;
            usageFlagCursor = usageFlagCursor + 1;
            addrSlotClearPtr = addrSlotClearPtr + 1;
            loopIndex7 = loopIndex7 + 1;
          } while (loopContinue);
          loopContinue = loopIndex9 != 1;
          halfSelect = halfSelect + 0xc;
          loopIndex4 = loopIndex4 + 6;
          loopIndex9 = loopIndex9 + 1;
        } while (loopContinue);
        freeSlotIndex = 0;
        sourceSwizzlePtr = 0xffff;
        addrSlotScanCursor = entry;
        while ((((replaceRgb && (*(ushort *)(addrSlotScanCursor + 0x80) != 0xffff)) &&
                (newAddrWord != *(ushort *)(addrSlotScanCursor + 0x80))) ||
               (((replaceAlpha && (*(ushort *)(addrSlotScanCursor + 0x86) != 0xffff)) &&
                (newAddrWord != *(ushort *)(addrSlotScanCursor + 0x86)))))) {
          loopContinue = freeSlotIndex == 2;
          addrSlotScanCursor = addrSlotScanCursor + 2;
          freeSlotIndex = freeSlotIndex + 1;
          if (loopContinue) {
            *(short *)((selectBankOffset + sourceAddrSel) * 2 + entry + 0x80) = (short)oldAddrWord;
            return 0;
          }
        }
        if (replaceRgb) {
          *(short *)(freeSlotIndex * 2 + entry + 0x80) = (short)newAddrWord;
        }
        if (replaceAlpha) {
          *(short *)(freeSlotIndex * 2 + entry + 0x86) = (short)newAddrWord;
        }
        sourceSlotPtr[1] = sourceSlotPtr[1] & 0xffe0 | newOffsetShort;
        *sourceSlotPtr = (*sourceSlotPtr & 0xfffc | (ushort)freeSlotIndex) & 0xfcff | (ushort)replaceSelectBits;
      }
      loopContinue = sourceIndex != 2;
      sourceSlotPtr = sourceSlotPtr + 2;
      sourceIndex = sourceIndex + 1;
    } while (loopContinue);
  }
  if (*(int *)(entry + 0x8c) == 2) {
    ((int (*)())psnDecRecomputeSourceUsage)(entry);
    ((int (*)())psnDecCanonicalizeEntry)(entry,r4AfterCall,halfIndex,halfSelect,oldAddressOffset,sourceIndex,sourceSwizzlePtr,freeSlotIndex);
  }
  return 0;
}

/* psnDecReadsRegMask @ 0xc3600 (120 bytes) */
int psnDecReadsRegMask(entry, registerNumber, componentMask, passThroughR6)
  int entry;
  uint registerNumber;
  undefined4 componentMask;
  undefined4 passThroughR6;
{
  bool loopContinue;
  ushort *halfOneMaskPtr;
  int halfZeroMaskBase;
  int slotIndex;
  int loopIndex;
  int halfOneBase;
  int halfOneBaseRef;
  
  halfOneBase = entry + 0x50;
  halfOneBaseRef = entry + 0x54;
  slotIndex = 0;
  halfZeroMaskBase = entry + 0x14;
  do {
    halfOneMaskPtr = (ushort *)(halfOneBase + 4);
    loopIndex = 0;
    do {
      if (halfOneMaskPtr[0x16] == registerNumber) {
        if (((*(ushort *)((halfZeroMaskBase - halfOneBaseRef) + (int)halfOneMaskPtr) & (*(unsigned short *)((unsigned char *)&(componentMask) + 2))) != 0) ||
           (((*(unsigned short *)((unsigned char *)&(componentMask) + 2)) & *halfOneMaskPtr) != 0)) {
          return 1;
        }
      }
      loopContinue = loopIndex != 1;
      halfOneMaskPtr = halfOneMaskPtr + 3;
      loopIndex = loopIndex + 1;
    } while (loopContinue);
    loopContinue = slotIndex == 2;
    halfOneBase = halfOneBase + 2;
    halfZeroMaskBase = halfZeroMaskBase + 2;
    halfOneBaseRef = halfOneBaseRef + 2;
    slotIndex = slotIndex + 1;
    if (loopContinue) {
      return 0;
    }
  } while( true );
}

/* psnDecSourceHasPartialMask @ 0xc3680 (100 bytes) */
int psnDecSourceHasPartialMask(entry, address, componentMask, passThroughR6, passThroughR7, passThroughR8)
  int entry;
  uint address;
  undefined4 componentMask;
  undefined4 passThroughR6;
  undefined4 passThroughR7;
  undefined4 passThroughR8;
{
  bool loopContinue;
  ushort *readMaskPtr;
  int slotMaskBase;
  int loopIndex;
  int slotIndex;
  
  slotMaskBase = entry + 0x10;
  slotIndex = 0;
  do {
    readMaskPtr = (ushort *)(slotMaskBase + 4);
    loopIndex = 0;
    do {
      if (readMaskPtr[0x36] == address) {
        if (((*readMaskPtr & (*(unsigned short *)((unsigned char *)&(componentMask) + 2))) != 0) && ((*readMaskPtr & ~(*(unsigned short *)((unsigned char *)&(componentMask) + 2))) != 0)) {
          return 1;
        }
      }
      loopContinue = loopIndex != 1;
      readMaskPtr = readMaskPtr + 3;
      loopIndex = loopIndex + 1;
    } while (loopContinue);
    loopContinue = slotIndex == 2;
    slotMaskBase = slotMaskBase + 2;
    slotIndex = slotIndex + 1;
    if (loopContinue) {
      return 0;
    }
  } while( true );
}

/* psnDecDestMatchesRegMask @ 0xc36f0 (60 bytes) */
int psnDecDestMatchesRegMask(entry, registerNumber, componentMask, passThroughR6, passThroughR7, passThroughR8, passThroughR9)
  int entry;
  uint registerNumber;
  undefined4 componentMask;
  undefined4 passThroughR6;
  undefined4 passThroughR7;
  undefined4 passThroughR8;
  undefined4 passThroughR9;
{
  bool bVar1;
  int loopIndex;
  
  loopIndex = 0;
  while ((*(ushort *)(entry + 4) != registerNumber || ((*(ushort *)(entry + 6) & (*(unsigned short *)((unsigned char *)&(componentMask) + 2))) == 0)))
  {
    bVar1 = loopIndex == 1;
    entry = entry + 0x40;
    loopIndex = loopIndex + 1;
    if (bVar1) {
      return 0;
    }
  }
  return 1;
}

/* psnDecCanFoldIntoSlot @ 0xc3740 (120 bytes) */
int psnDecCanFoldIntoSlot(entry, halfSelector, slotCount)
  int entry;
  int halfSelector;
  int slotCount;
{
  bool loopContinue;
  ushort *sourceSelectPtr;
  int loopIndex;
  
  loopIndex = 0;
  sourceSelectPtr = (ushort *)(entry + (uint)(halfSelector == 8) * 0x40 + 8);
  do {
    if ((*sourceSelectPtr & 3) == 3) {
      return 0;
    }
    loopContinue = loopIndex != 2;
    sourceSelectPtr = sourceSelectPtr + 2;
    loopIndex = loopIndex + 1;
  } while (loopContinue);
  if (((*(uint *)((1 - (uint)(halfSelector == 8)) * 0x40 + entry + 0x30) & 0x20) == 0) &&
     (1 < slotCount - 1U)) {
    return 1;
  }
  return 0;
}

/* psnDecSwapAddressSlotsInSources @ 0xc37c0 (216 bytes) */
int psnDecSwapAddressSlotsInSources(entry, slotA, slotB, group, passThroughR7, passThroughR8, passThroughR9)
  int entry;
  uint slotA;
  uint slotB;
  int group;
  undefined4 passThroughR7;
  undefined4 passThroughR8;
  undefined4 passThroughR9;
{
  int slotAAddressPtr;
  int loopIndex;
  bool loopContinue;
  ushort sourceSelect;
  undefined2 savedAddress;
  ushort groupSelectBits;
  int halfCursor;
  int loopIndex2;
  ushort *sourceSelectPtr;
  int slotBAddressPtr;
  
  if (group == 0) {
    groupSelectBits = 0x100;
  }
  else {
    groupSelectBits = 0x200;
  }
  loopIndex = 0;
  halfCursor = entry;
  do {
    sourceSelectPtr = (ushort *)(halfCursor + 8);
    loopIndex2 = 0;
    do {
      sourceSelect = *sourceSelectPtr;
      if (((sourceSelect & 0x300) != 0) && ((groupSelectBits & sourceSelect & 0x300) != 0)) {
        if ((sourceSelect & 3) == slotA) {
          *sourceSelectPtr = (ushort)slotB | sourceSelect & 0xfffc;
        }
        if ((sourceSelect & 3) == slotB) {
          *sourceSelectPtr = (ushort)slotA | *sourceSelectPtr & 0xfffc;
        }
      }
      loopContinue = loopIndex2 != 2;
      sourceSelectPtr = sourceSelectPtr + 2;
      loopIndex2 = loopIndex2 + 1;
    } while (loopContinue);
    loopContinue = loopIndex != 1;
    halfCursor = halfCursor + 0x40;
    loopIndex = loopIndex + 1;
  } while (loopContinue);
  slotBAddressPtr = (group * 3 + slotB) * 2 + entry;
  slotAAddressPtr = (group * 3 + slotA) * 2 + entry;
  savedAddress = *(undefined2 *)(slotAAddressPtr + 0x80);
  *(undefined2 *)(slotAAddressPtr + 0x80) = *(undefined2 *)(slotBAddressPtr + 0x80);
  *(undefined2 *)(slotBAddressPtr + 0x80) = savedAddress;
  return;
}

/* psnDecTryRebindAddressWithRollback @ 0xc38a0 (1208 bytes) */
int psnDecTryRebindAddressWithRollback(entry, oldAddressValue, newAddressValue, opcode, excludeMask, rebindFlags)
  int entry;
  uint oldAddressValue;
  undefined4 newAddressValue;
  int opcode;
  uint excludeMask;
  uint rebindFlags;
{
  uint loopIndex;
  bool moreInit;
  bool rgbAffected;
  bool alphaNotAffected;
  bool moreScan;
  ushort sourceSelectWord;
  ushort sourceUsageMask;
  bool slot1Free;
  bool changed;
  bool moreSlots;
  undefined4 slotMaskHigh;
  short *usageCursor;
  int halfBase;
  uint excludeMaskCopy;
  uint freeSlotIndex;
  uint usageWordValue;
  int slotRowBase;
  int sourceIndex;
  undefined4 r4AfterCall;
  undefined4 slotMaskLow;
  undefined4 staleArgR9;
  undefined4 slotMaskLowB;
  int scanIndex;
  int halfIndex;
  int scanCounter;
  int addrSlotByteOffset;
  int usageGroupBase;
  ushort *slotRef;
  int halfScan;
  int bankSelect;
  ushort *usageMaskCursor;
  int usageClearCursor;
  int entryCursor;
  ushort *sourceSlotCursor;
  ushort *addrSlotCursor;
  ushort *sourceSlotPtr;
  int halfLoop;
  undefined4 slotMaskTable [2];
  undefined1 entryBackup [180];
  
  excludeMaskCopy = excludeMask;
  _memcpy(entryBackup,entry,0xa0);
  halfScan = 0;
  slotMaskLow = 0xffffffff;
  usageClearCursor = entry + 0x10;
  do {
    usageCursor = (short *)(usageClearCursor + 4);
    scanCounter = 0;
    do {
      if ((*usageCursor == 0) && (usageCursor[0x20] == 0)) {
        usageCursor[0x36] = -1;
      }
      moreInit = scanCounter != 2;
      usageCursor = usageCursor + 1;
      scanCounter = scanCounter + 1;
    } while (moreInit);
    moreInit = halfScan != 1;
    usageClearCursor = usageClearCursor + 6;
    halfScan = halfScan + 1;
  } while (moreInit);
  rgbAffected = (rebindFlags & 7) != 0;
  if ((rgbAffected) && (*(ushort *)(entry + 0x80) != oldAddressValue)) {
    if ((*(ushort *)(entry + 0x82) == 0xffff) || (oldAddressValue == *(ushort *)(entry + 0x82))) {
      ((int (*)())psnDecSwapAddressSlotsInSources)(entry,0,1,0,excludeMaskCopy,0xffffffff,3);
    }
    else if ((*(ushort *)(entry + 0x84) == 0xffff) || (oldAddressValue == *(ushort *)(entry + 0x84))) {
      ((int (*)())psnDecSwapAddressSlotsInSources)(entry,0,2,0,excludeMaskCopy,0xffffffff,3);
    }
  }
  alphaNotAffected = (rebindFlags >> 3 & 1) == 0;
  if (alphaNotAffected) {
    bankSelect = 0;
    goto LAB_000c3a40;
  }
  if (*(ushort *)(entry + 0x86) != oldAddressValue) {
    if ((*(ushort *)(entry + 0x88) == 0xffff) || (oldAddressValue == *(ushort *)(entry + 0x88))) {
      bankSelect = 1;
      ((int (*)())psnDecSwapAddressSlotsInSources)(entry,0,1,1,excludeMaskCopy,slotMaskLow,scanCounter);
      goto LAB_000c3a40;
    }
    if ((*(ushort *)(entry + 0x8a) == 0xffff) || (oldAddressValue == *(ushort *)(entry + 0x8a))) {
      bankSelect = 1;
      ((int (*)())psnDecSwapAddressSlotsInSources)(entry,0,2,1,excludeMaskCopy,slotMaskLow,scanCounter);
      goto LAB_000c3a40;
    }
  }
  bankSelect = 1;
LAB_000c3a40:
  halfLoop = 0;
  usageGroupBase = entry + 0x10;
  entryCursor = entry;
  do {
    sourceSlotCursor = (ushort *)(entryCursor + 10);
    usageMaskCursor = (ushort *)(usageGroupBase + 4);
    scanIndex = 0;
    do {
      sourceSelectWord = sourceSlotCursor[-1];
      slotRef = (ushort *)(sourceSelectWord & 0x100);
      if ((sourceSelectWord & 0x100) == 0) {
        if ((sourceSelectWord & 0x200) != 0) {
          sourceUsageMask = usageMaskCursor[3];
          slotRef = (ushort *)((int)((unsigned char *)0x0) + 1);
          goto LAB_000c3ab0;
        }
      }
      else {
        sourceUsageMask = *usageMaskCursor;
        slotRef = (ushort *)0x0;
LAB_000c3ab0:
        if ((((sourceSelectWord & 3) < 3) &&
            (slotRowBase = (int)slotRef * 3,
            *(ushort *)((slotRowBase + (sourceSelectWord & 3)) * 2 + entry + 0x80) == oldAddressValue)) &&
           ((*sourceSlotCursor & 0x1f & (uint)sourceUsageMask & ~excludeMask) != 0)) {
          halfBase = (int)slotRef * 6 + entry;
          slot1Free = *(short *)(halfBase + 0x82) == -1;
          freeSlotIndex = (uint)slot1Free;
          slotRef = (ushort *)(int)(short)(ushort)slot1Free;
          if (*(short *)(halfBase + 0x84) == -1) {
            freeSlotIndex = 2;
            slotRef = (ushort *)((int)((unsigned char *)0x0) + 2);
          }
          *(short *)((slotRowBase + freeSlotIndex) * 2 + entry + 0x80) = (short)oldAddressValue;
          sourceSlotCursor[-1] = (ushort)slotRef | sourceSlotCursor[-1] & 0xfffc;
        }
      }
      moreSlots = scanIndex != 2;
      sourceSlotCursor = sourceSlotCursor + 2;
      usageMaskCursor = usageMaskCursor + 1;
      scanIndex = scanIndex + 1;
    } while (moreSlots);
    moreSlots = halfLoop == 1;
    entryCursor = entryCursor + 0x40;
    usageGroupBase = usageGroupBase + 0x40;
    halfLoop = halfLoop + 1;
    if (moreSlots) {
      changed = false;
      halfLoop = 0;
      addrSlotByteOffset = 0x80;
      do {
        addrSlotCursor = (ushort *)(entry + addrSlotByteOffset);
        loopIndex = 0;
        do {
          slotMaskHigh = _UNK_001aa7f8;
          slotMaskLowB = _UNK_001aa7f4;
          if (*addrSlotCursor == oldAddressValue) {
            halfIndex = 0;
            entryCursor = entry;
            do {
              sourceSlotPtr = (ushort *)(entryCursor + 8);
              sourceIndex = 0;
              do {
                sourceSelectWord = *sourceSlotPtr;
                usageMaskCursor = (ushort *)(uint)sourceSelectWord;
                slotMaskTable[0] = slotMaskLowB;
                slotMaskTable[1] = slotMaskHigh;
                slotRef = (ushort *)slotMaskTable[halfLoop];
                if ((sourceSelectWord & 3) == loopIndex) {
                  if (((uint)slotRef & sourceSelectWord & 0x300) != 0) {
                    sourceUsageMask = sourceSlotPtr[1];
                    usageWordValue = (uint)sourceUsageMask;
                    slotRef = sourceSlotPtr + 1;
                    if ((sourceUsageMask & excludeMask) != 0) {
                      if ((sourceUsageMask & 0x2000) == 0) {
                        usageWordValue = sourceUsageMask ^ 0x1000;
                        sourceSlotPtr[1] = (ushort)usageWordValue;
                      }
                      usageMaskCursor = (ushort *)(sourceSelectWord & 0xfffffffc | 3);
                      *sourceSlotPtr = (ushort)usageMaskCursor;
                      if ((opcode != 7) || ((1 < (usageWordValue & 0x1f) - 1 && ((usageWordValue & 0x1f) != 4)))) {
                        sourceSlotPtr[1] = (ushort)usageWordValue | (ushort)rebindFlags;
                      }
                      if ((rebindFlags & 1) == 0) {
                        *slotRef = *slotRef & 0xfffe;
                      }
                      if ((rebindFlags & 2) == 0) {
                        *slotRef = *slotRef & 0xfffd;
                      }
                      if ((rebindFlags & 4) == 0) {
                        *slotRef = *slotRef & 0xfffb;
                      }
                      if (alphaNotAffected) {
                        *slotRef = *slotRef & 0xfff7;
                      }
                      changed = true;
                      *sourceSlotPtr = sourceSelectWord & 0xfcfc | 3 | (ushort)slotMaskTable[bankSelect];
                    }
                  }
                }
                moreScan = sourceIndex != 2;
                sourceSlotPtr = sourceSlotPtr + 2;
                sourceIndex = sourceIndex + 1;
              } while (moreScan);
              moreScan = halfIndex != 1;
              entryCursor = entryCursor + 0x40;
              halfIndex = halfIndex + 1;
            } while (moreScan);
          }
          staleArgR9 = 3;
          moreScan = loopIndex != 2;
          addrSlotCursor = addrSlotCursor + 1;
          loopIndex = loopIndex + 1;
        } while (moreScan);
        moreScan = halfLoop != 1;
        addrSlotByteOffset = addrSlotByteOffset + 6;
        halfLoop = halfLoop + 1;
      } while (moreScan);
      if (changed) {
        if (rgbAffected) {
          *(undefined2 *)(entry + 0x80) = (*(unsigned short *)((unsigned char *)&(newAddressValue) + 2));
        }
        if (!alphaNotAffected) {
          *(undefined2 *)(entry + 0x86) = (*(unsigned short *)((unsigned char *)&(newAddressValue) + 2));
        }
        ((int (*)())psnDecRecomputeSourceUsage)(entry);
        ((int (*)())psnDecCanonicalizeEntry)(entry,r4AfterCall,entryCursor,loopIndex,addrSlotCursor,staleArgR9,slotRef,usageMaskCursor);
      }
      else {
        _memcpy(entry,entryBackup,0xa0);
      }
      return 1;
    }
  } while( true );
}

/* psnConstantComponentsAreOne @ 0xc3d60 (232 bytes) */
int psnConstantComponentsAreOne(constants, maskHigh, maskLow, constantIndex, componentMask)
  int constants;
  uint maskHigh;
  uint maskLow;
  uint constantIndex;
  uint componentMask;
{
  uint constantUsable;
  
  if ((int)(constantIndex - 0x20) < 0) {
    constantUsable = (maskHigh << 1) << (0x1f - constantIndex & 0x3f) | maskLow >> (constantIndex & 0x3f);
  }
  else {
    constantUsable = maskHigh >> (constantIndex - 0x20 & 0x3f);
  }
  if ((constantUsable & 1) != 0) {
    if (((componentMask & 1) == 0) || (*(float *)(constants + constantIndex * 0x10) == FLOAT_001aa108)) {
      if (((componentMask & 2) == 0) || (*(float *)(constantIndex * 0x10 + constants + 4) == FLOAT_001aa108)) {
        if (((componentMask & 4) == 0) || (*(float *)(constantIndex * 0x10 + constants + 8) == FLOAT_001aa108)) {
          if (((componentMask & 8) == 0) || (*(float *)(constantIndex * 0x10 + constants + 0xc) == FLOAT_001aa108)
             ) {
            if ((componentMask & 0xfffffff0) == 0) {
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

/* psnDecRangeHasConflict @ 0xc3e50 (376 bytes) */
int psnDecRangeHasConflict(decodedProgram, firstEntry, lastEntry, half, passThroughR7, passThroughR8, passThroughR9)
  int decodedProgram;
  int firstEntry;
  int lastEntry;
  int half;
  undefined4 passThroughR7;
  undefined4 passThroughR8;
  uint passThroughR9;
{
  int loopIndex;
  bool loopContinue;
  ushort rgbDestReg;
  ushort rgbWriteMask;
  ushort alphaDestReg;
  ushort alphaWriteMask;
  ushort sourceSelect;
  int halfByteOffset;
  uint addressSlot;
  int decodedProgramWord8;
  int conflictFlag;
  int slotConflict;
  undefined4 conflictResult;
  int scanOffset;
  int scanIndex;
  int entry;
  ushort *sourceSelectPtr;
  
  scanIndex = lastEntry + -1;
  decodedProgramWord8 = *(int *)(decodedProgram + 8);
  entry = lastEntry * 0xa0 + decodedProgramWord8;
  rgbDestReg = *(ushort *)(entry + 4);
  rgbWriteMask = *(ushort *)(entry + 6);
  alphaDestReg = *(ushort *)(entry + 0x44);
  alphaWriteMask = *(ushort *)(entry + 0x46);
  if (scanIndex < firstEntry) {
LAB_000c3fb0:
    conflictResult = 0;
  }
  else {
    halfByteOffset = half * 0x40;
    scanOffset = scanIndex * 0xa0;
    while( true ) {
      decodedProgramWord8 = scanOffset + decodedProgramWord8;
      conflictFlag = ((int (*)())psnDecReadsRegMask)(decodedProgramWord8,(uint)rgbDestReg,(uint)rgbWriteMask,half);
      if ((((conflictFlag != 0) ||
           (conflictFlag = ((int (*)())psnDecReadsRegMask)(decodedProgramWord8,(uint)alphaDestReg,(uint)alphaWriteMask,half), conflictFlag != 0)) ||
          (conflictFlag = ((int (*)())psnDecDestMatchesRegMask)(decodedProgramWord8,(uint)rgbDestReg,(uint)rgbWriteMask,half,passThroughR7,passThroughR8,passThroughR9),
          conflictFlag != 0)) ||
         (conflictFlag = ((int (*)())psnDecDestMatchesRegMask)(decodedProgramWord8,(uint)alphaDestReg,(uint)alphaWriteMask,half,passThroughR7,passThroughR8,passThroughR9),
         conflictFlag != 0)) break;
      sourceSelectPtr = (ushort *)(entry + halfByteOffset + 8);
      loopIndex = 0;
      do {
        sourceSelect = *sourceSelectPtr;
        addressSlot = sourceSelect & 3;
        if (addressSlot == 3) goto LAB_000c3fa8;
        passThroughR9 = sourceSelect & 0x100;
        if ((sourceSelect & 0x100) != 0) {
          slotConflict = ((int (*)())psnDecDestMatchesRegMask)(decodedProgramWord8,(uint)*(ushort *)(addressSlot * 2 + entry + 0x80),7,half,passThroughR7
                                ,passThroughR8,passThroughR9);
          if (slotConflict != 0) goto LAB_000c3fa8;
          sourceSelect = *sourceSelectPtr;
        }
        if (((sourceSelect & 0x200) != 0) &&
           (slotConflict = ((int (*)())psnDecDestMatchesRegMask)(decodedProgramWord8,(uint)*(ushort *)(addressSlot * 2 + entry + 0x86),8,half,
                                  passThroughR7,passThroughR8,passThroughR9), slotConflict != 0)) goto LAB_000c3fa8;
        loopContinue = loopIndex != 2;
        sourceSelectPtr = sourceSelectPtr + 2;
        loopIndex = loopIndex + 1;
      } while (loopContinue);
      scanIndex = scanIndex + -1;
      scanOffset = scanOffset + -0xa0;
      if (scanIndex < firstEntry) goto LAB_000c3fb0;
      decodedProgramWord8 = *(int *)(decodedProgram + 8);
    }
LAB_000c3fa8:
    conflictResult = 1;
  }
  return conflictResult;
}

/* psnDecTryMergeAddressSlots @ 0xc3fd0 (784 bytes) */
int psnDecTryMergeAddressSlots(entry, otherEntry, reverseRoles, staleArgR6, unusedArgR7)
  int entry;
  int otherEntry;
  int reverseRoles;
  undefined4 staleArgR6;
  undefined4 unusedArgR7;
{
  int clearCounter;
  int destHalf;
  int slotIndexInit;
  int sourceSlotsB;
  int halfByteOffset;
  int groupIndex;
  bool lastSourceReached;
  bool lastSlotReached;
  int loopIndex;
  int loopIndex2;
  bool loopContinue;
  ushort destSelectWord;
  undefined2 savedSrcpOp;
  int sourceSlotsA;
  short *usageWordPtr;
  uint otherSelect;
  undefined2 *clearSlotPtr;
  undefined4 r4AfterCall;
  undefined4 r4AfterCall2;
  undefined4 halfSize;
  uint slotFound;
  int sourceIndex;
  uint slotSearchIndex;
  int staleArgR9;
  int usageHalfBase;
  undefined2 *usageSlotPtr;
  int sourceCounter;
  ushort *otherSelectPtr;
  
  if ((*(int *)(entry + 0x8c) == 2) && (*(int *)(otherEntry + 0x8c) == 2)) {
    sourceSlotsA = entry;
    sourceSlotsB = otherEntry;
    if (reverseRoles != 0) {
      sourceSlotsA = otherEntry;
      sourceSlotsB = entry;
    }
    loopIndex = 0;
    loopIndex2 = 0;
    sourceCounter = 0;
    do {
      if ((*(ushort *)(sourceSlotsB + 8) & 0x200) != 0) {
        loopIndex = loopIndex + 1;
      }
      if ((*(ushort *)(sourceSlotsB + 8) & 0x100) != 0) {
        loopIndex2 = loopIndex2 + 1;
      }
      destSelectWord = *(ushort *)(sourceSlotsA + 0x48);
      if ((destSelectWord & 0x200) != 0) {
        loopIndex = loopIndex + 1;
      }
      slotFound = destSelectWord & 0x100;
      if ((destSelectWord & 0x100) != 0) {
        loopIndex2 = loopIndex2 + 1;
      }
      loopContinue = sourceCounter != 2;
      sourceSlotsB = sourceSlotsB + 4;
      sourceSlotsA = sourceSlotsA + 4;
      sourceCounter = sourceCounter + 1;
    } while (loopContinue);
    if ((loopIndex < 4) && (loopIndex2 < 4)) {
      groupIndex = 0;
      usageSlotPtr = (undefined2 *)(entry + 0x10);
      do {
        usageWordPtr = usageSlotPtr + 2;
        slotIndexInit = 0;
        do {
          if ((*usageWordPtr == 0) && (usageWordPtr[0x20] == 0)) {
            usageWordPtr[0x36] = -1;
          }
          loopContinue = slotIndexInit != 2;
          usageWordPtr = usageWordPtr + 1;
          slotIndexInit = slotIndexInit + 1;
        } while (loopContinue);
        loopContinue = groupIndex != 1;
        usageSlotPtr = usageSlotPtr + 3;
        groupIndex = groupIndex + 1;
      } while (loopContinue);
      halfByteOffset = (uint)(reverseRoles != 0) * 0x40;
      sourceIndex = 0;
      staleArgR9 = halfByteOffset + 0x16;
      otherSelectPtr = (ushort *)(otherEntry + halfByteOffset + 8);
      usageHalfBase = entry + staleArgR9;
      slotSearchIndex = 2;
      do {
        otherSelect = (uint)*otherSelectPtr;
        if ((*otherSelectPtr & 0x100) != 0) {
          usageSlotPtr = (undefined2 *)(entry + halfByteOffset + 0x14);
          slotSearchIndex = 0;
          staleArgR6 = 0xffff;
          staleArgR9 = entry;
          do {
            slotFound = 0;
            if (*(short *)(staleArgR9 + 0x80) == -1) {
              if ((otherSelect & 3) == 3) {
                return 0;
              }
              slotFound = 1;
              *(undefined2 *)(staleArgR9 + 0x80) = *(undefined2 *)((otherSelect & 3) * 2 + otherEntry + 0x80);
              *usageSlotPtr = 7;
              otherSelect = *otherSelectPtr & 0xfffc | slotSearchIndex;
              *otherSelectPtr = (ushort)otherSelect;
            }
            lastSlotReached = slotSearchIndex == 2;
            slotSearchIndex = slotSearchIndex + 1;
            if (lastSlotReached) {
              if (slotFound == 0) {
                return 0;
              }
              break;
            }
            staleArgR9 = staleArgR9 + 2;
            usageSlotPtr = usageSlotPtr + 1;
          } while (slotFound == 0);
        }
        if ((otherSelect & 0x200) != 0) {
          usageSlotPtr = (undefined2 *)(usageHalfBase + 4);
          slotSearchIndex = 0;
          staleArgR6 = 0xffff;
          staleArgR9 = entry;
          do {
            slotFound = 0;
            if (*(short *)(staleArgR9 + 0x86) == -1) {
              if ((otherSelect & 3) == 3) {
                return 0;
              }
              slotFound = 1;
              *(undefined2 *)(staleArgR9 + 0x86) = *(undefined2 *)((otherSelect & 3) * 2 + otherEntry + 0x86);
              *usageSlotPtr = 8;
              otherSelect = *otherSelectPtr & 0xfffc | slotSearchIndex;
              *otherSelectPtr = (ushort)otherSelect;
            }
            lastSlotReached = slotSearchIndex == 2;
            slotSearchIndex = slotSearchIndex + 1;
            if (lastSlotReached) {
              if (slotFound == 0) {
                return 0;
              }
              break;
            }
            staleArgR9 = staleArgR9 + 2;
            usageSlotPtr = usageSlotPtr + 1;
          } while (slotFound == 0);
        }
        lastSourceReached = sourceIndex == 2;
        otherSelectPtr = otherSelectPtr + 2;
        sourceIndex = sourceIndex + 1;
        if (lastSourceReached) {
          destHalf = halfByteOffset + entry;
          halfByteOffset = halfByteOffset + otherEntry;
          halfSize = 0x40;
          savedSrcpOp = *(undefined2 *)(destHalf + 0x2a);
          _memcpy(destHalf,halfByteOffset,0x40);
          clearSlotPtr = (undefined2 *)(halfByteOffset + 8);
          clearCounter = 0;
          *(undefined2 *)(halfByteOffset + 6) = 0;
          *(undefined2 *)(halfByteOffset + 2) = 0;
          *(undefined2 *)(destHalf + 0x2a) = savedSrcpOp;
          do {
            loopContinue = clearCounter != 2;
            *clearSlotPtr = 0;
            clearSlotPtr[1] = 0;
            clearCounter = clearCounter + 1;
            clearSlotPtr = clearSlotPtr + 2;
          } while (loopContinue);
          ((int (*)())psnDecRecomputeSourceUsage)(entry);
          ((int (*)())psnDecCanonicalizeEntry)(entry,r4AfterCall,halfSize,staleArgR6,slotFound,slotSearchIndex,staleArgR9,usageSlotPtr);
          ((int (*)())psnDecRecomputeSourceUsage)(otherEntry);
          ((int (*)())psnDecCanonicalizeEntry)(otherEntry,r4AfterCall2,halfSize,staleArgR6,slotFound,slotSearchIndex,staleArgR9,usageSlotPtr);
          return 1;
        }
      } while( true );
    }
  }
  return 0;
}

/* psnProgramToDecoded @ 0xc42f0 (2444 bytes) */
int psnProgramToDecoded(decodedProgram, recordCursor)
  uint *decodedProgram;
  uint *recordCursor;
{
  byte controlByte;
  byte selectByte;
  ushort sourceRegWord3;
  ushort sourceRegWord2;
  ushort sourceRegWord1;
  ushort sourceModifier;
  uint alphaSourceCount;
  uint rgbSourceCount;
  uint alphaSourcesLeft;
  ushort *alphaSourceSlotPtr;
  ushort *alphaHalf;
  ushort *rgbSourceSlotPtr;
  bool loopContinue;
  byte opKindByte;
  undefined4 defaultOperandWord2;
  uint recordKind;
  uint sourceSelectCode;
  ushort sourceSelectWord;
  undefined4 r4AfterCall;
  uint *staleArgR5;
  byte *staleArgR6;
  ushort *recField0e;
  char *staleArgR7;
  ushort *defaultSlotPtr;
  byte *staleArgR9;
  int slotCounter;
  ushort *defaultSlotPtr2;
  uint *recField1c;
  uint *recField0c;
  ushort *recField1e;
  byte *recField2b;
  byte *recField3a;
  uint *recField40;
  byte *recField2e;
  byte *recField3d;
  ushort *recField1a;
  byte *recField39;
  uint *recField3c;
  byte *recField2a;
  byte *recField2d;
  byte *recField31;
  ushort *entry;
  uint rgbSourcesLeft;
  uint *puStack00000018;
  byte *recField1f;
  byte *recField3e;
  byte *recField3b;
  byte *recField2f;
  uint *recField2c;
  ushort *recField1aCopyd4;
  ushort *recField12;
  uint *recField10;
  ushort *recField0eCopyc8;
  byte *recField15;
  byte *recField16;
  uint *recField14;
  uint *recField0cCopyb8;
  char *recField33;
  uint *recField30;
  uint *recField20;
  uint *recField18;
  byte *recField32;
  char *recField21;
  byte *recField22;
  char *recField23;
  char *recField42;
  byte *recField3f;
  byte *recField0b;
  byte *recField0d;
  byte *recField0a;
  ushort *recField06;
  char *recField09;
  uint *recField0cCopy78;
  uint *recField08;
  uint *recField04;
  byte *recField41;
  byte *recField19;
  uint recordNumber;
  int entryByteOffset;
  
  *(undefined1 *)(decodedProgram + 4) = *(undefined1 *)(recordCursor + 3);
  *(undefined1 *)((int)decodedProgram + 0x11) = *(undefined1 *)((int)recordCursor + 0xd);
  if (*decodedProgram != 0) {
    recField0c = recordCursor + 0x15;
    recField0e = (ushort *)((int)recordCursor + 0x56);
    recField1f = (byte *)((int)recordCursor + 0x67);
    recField19 = (byte *)((int)recordCursor + 0x61);
    recField41 = (byte *)((int)recordCursor + 0x89);
    recField04 = recordCursor + 0x13;
    recField08 = recordCursor + 0x14;
    recField09 = (char *)((int)recordCursor + 0x51);
    recField06 = (ushort *)((int)recordCursor + 0x4e);
    recField0a = (byte *)((int)recordCursor + 0x52);
    recField0d = (byte *)((int)recordCursor + 0x55);
    recField0b = (byte *)((int)recordCursor + 0x53);
    recField3f = (byte *)((int)recordCursor + 0x87);
    recField42 = (char *)((int)recordCursor + 0x8a);
    recField23 = (char *)((int)recordCursor + 0x6b);
    recField22 = (byte *)((int)recordCursor + 0x6a);
    recField21 = (char *)((int)recordCursor + 0x69);
    recField32 = (byte *)((int)recordCursor + 0x7a);
    recField18 = recordCursor + 0x18;
    recField20 = recordCursor + 0x1a;
    recField30 = recordCursor + 0x1e;
    recField33 = (char *)((int)recordCursor + 0x7b);
    recField14 = recordCursor + 0x17;
    recField16 = (byte *)((int)recordCursor + 0x5e);
    recField15 = (byte *)((int)recordCursor + 0x5d);
    recField10 = recordCursor + 0x16;
    recField12 = (ushort *)((int)recordCursor + 0x5a);
    recField1a = (ushort *)((int)recordCursor + 0x62);
    recField2c = recordCursor + 0x1d;
    recField2f = (byte *)((int)recordCursor + 0x77);
    recField3b = (byte *)((int)recordCursor + 0x83);
    recField40 = recordCursor + 0x22;
    recField31 = (byte *)((int)recordCursor + 0x79);
    recField1c = recordCursor + 0x19;
    recField1e = (ushort *)((int)recordCursor + 0x66);
    recField2a = (byte *)((int)recordCursor + 0x72);
    recField2d = (byte *)((int)recordCursor + 0x75);
    recField2b = (byte *)((int)recordCursor + 0x73);
    recField2e = (byte *)((int)recordCursor + 0x76);
    recField39 = (byte *)((int)recordCursor + 0x81);
    recField3c = recordCursor + 0x21;
    recField3a = (byte *)((int)recordCursor + 0x82);
    recField3d = (byte *)((int)recordCursor + 0x85);
    recField3e = (byte *)((int)recordCursor + 0x86);
    recordNumber = 0;
    entryByteOffset = 0;
    puStack00000018 = decodedProgram;
    recField1aCopyd4 = recField1a;
    recField0eCopyc8 = recField0e;
    recField0cCopyb8 = recField0c;
    recField0cCopy78 = recField0c;
    do {
      recordCursor = recordCursor + 0x12;
      entry = (ushort *)(entryByteOffset + puStack00000018[2]);
      _memset(entry,0,0x80);
      entry[0x40] = 0;
      entry[0x41] = 0;
      entry[0x44] = 0;
      entry[0x45] = 0;
      entry[0x42] = 0;
      entry[0x43] = 0;
      recordKind = *recordCursor;
      if (recordKind == 2) {
        entry[0x48] = 0;
        entry[0x49] = 0;
        entry[0x4a] = 0;
        entry[0x4b] = 0;
        entry[0x46] = 0;
        entry[0x47] = 1;
        opKindByte = *(byte *)recField1a;
        sourceSelectWord = (ushort)opKindByte;
        if (opKindByte == 2) {
          entry[10] = 0xf;
          sourceRegWord1 = *recField0e;
          entry[0x1d] = 1;
          entry[0x18] = 0;
          entry[0x19] = 1;
          entry[0x40] = sourceRegWord1;
          sourceSelectWord = (ushort)*(byte *)recField1a;
        }
        else if (opKindByte < 3) {
          if (opKindByte == 1) {
LAB_000c46e8:
            entry[3] = 0xf;
            entry[2] = *(ushort *)recField0c;
            entry[10] = ~(ushort)*recField1f & 0xf;
            entry[0x40] = *recField0e;
            sourceSelectWord = (ushort)*(byte *)recField1a;
          }
        }
        else if (opKindByte < 5) goto LAB_000c46e8;
        selectByte = *recField19;
        entry[0x16] = 0x3f80;
        entry[0x17] = 0;
        entry[0x14] = (ushort)selectByte << 8 | sourceSelectWord;
      }
      else if (recordKind < 3) {
        if (recordKind == 1) {
          entry[0x46] = 0;
          entry[0x47] = 0;
          entry[0x48] = 0;
          entry[0x49] = 0;
          entry[0x4a] = 0;
          entry[0x4b] = 0;
          if (*recField0b == 0) {
            entry[0x16] = 0x3f80;
            entry[0x17] = 0;
          }
          else {
            entry[3] = 0xf;
            sourceRegWord2 = *recField06;
            entry[10] = 0xf;
            entry[2] = sourceRegWord2;
            entry[0x40] = *recField0a | 0xc000;
            *(undefined4 *)(entry + 0x16) = *(undefined4 *)((uint)*recField0d * 4 + 0x1dc198);
            controlByte = *recField0b;
            if ((controlByte == 2) || (controlByte == 3)) {
              entry[0x1d] = (ushort)controlByte;
            }
          }
          if (*recField09 == '\0') {
            entry[0x36] = 0x3f80;
            entry[0x37] = 0;
          }
          else {
            entry[0x23] = 0xf;
            sourceRegWord3 = *(ushort *)recField04;
            entry[0x2d] = 0xf;
            entry[0x22] = sourceRegWord3;
            entry[0x43] = *(byte *)recField08 | 0xa000;
            *(undefined4 *)(entry + 0x36) =
                 *(undefined4 *)((uint)*(byte *)recField0cCopy78 * 4 + 0x1dc198);
          }
        }
      }
      else if (recordKind < 5) {
        entry[0x48] = 0;
        entry[0x49] = 0;
        entry[0x4a] = 0;
        entry[0x4b] = 0;
        entry[0x46] = 0;
        entry[0x47] = 2;
        slotCounter = 0;
        entry[0x40] = *recField0eCopyc8;
        entry[0x41] = *(ushort *)recField10;
        entry[0x42] = *recField12;
        entry[0x43] = *recField1aCopyd4;
        entry[0x44] = *(ushort *)recField1c;
        entry[0x45] = *recField1e;
        defaultSlotPtr = entry;
        defaultSlotPtr2 = entry;
        do {
          defaultSlotPtr2[0x3a] = 1;
          defaultSlotPtr2[0x1a] = 1;
          defaultOperandWord2 = (*(unsigned int *)&DAT_001dbf94);
          loopContinue = slotCounter != 2;
          defaultSlotPtr2 = defaultSlotPtr2 + 1;
          slotCounter = slotCounter + 1;
          *(undefined4 *)(defaultSlotPtr + 4) = (*(unsigned int *)&DAT_001dbf94);
          *(undefined4 *)(defaultSlotPtr + 0x24) = defaultOperandWord2;
          defaultSlotPtr = defaultSlotPtr + 2;
        } while (loopContinue);
        entry[2] = *(ushort *)recField0cCopyb8;
        entry[3] = (ushort)*(byte *)recField14;
        *entry = (ushort)*recField16;
        entry[1] = (ushort)*recField15;
        entry[0x14] = *(ushort *)((uint)*recField31 * 4 + 0x1dc158);
        rgbSourceCount = (uint)*(ushort *)((uint)*recField31 * 4 + 0x1dc15a);
        if (rgbSourceCount != 0) {
LAB_000c4830:
          sourceSelectCode = (uint)*recField2a;
          sourceModifier = (ushort)*recField2d;
          slotCounter = 0;
          rgbSourceSlotPtr = entry + 4;
          rgbSourcesLeft = rgbSourceCount;
          if (rgbSourceCount == 0) {
            rgbSourcesLeft = 1;
          }
          do {
            slotCounter = slotCounter + 1;
            *(undefined4 *)rgbSourceSlotPtr = *(undefined4 *)(sourceSelectCode * 4 + 0x1dc0d8);
            rgbSourceSlotPtr[1] = sourceModifier << 0xc | rgbSourceSlotPtr[1];
            rgbSourcesLeft = rgbSourcesLeft - 1;
            if (rgbSourcesLeft == 0) goto LAB_000c48b4;
            if (slotCounter == 1) {
              sourceSelectCode = (uint)*recField2b;
              sourceModifier = (ushort)*recField2e;
            }
            else {
              if (slotCounter == 0) goto LAB_000c4830;
              if (slotCounter == 2) {
                sourceSelectCode = (uint)*(byte *)recField2c;
                sourceModifier = (ushort)*recField2f;
              }
              else {
                sourceSelectCode = 0;
                sourceModifier = 0;
              }
            }
            rgbSourceSlotPtr = rgbSourceSlotPtr + 2;
          } while( true );
        }
        slotCounter = 3;
LAB_000c48b4:
        entry[0x15] = (ushort)*(byte *)recField30;
        if (*recField33 == '\x01') {
          *(uint *)(entry + 0x18) = *(uint *)(entry + 0x18) | 8;
        }
        alphaHalf = entry + 0x20;
        *(undefined4 *)(entry + 0x16) = *(undefined4 *)((uint)*recField32 * 4 + 0x1dc198);
        entry[0x22] = *(ushort *)recField18;
        if (*(char *)recField20 != '\0') {
          entry[0x23] = 8;
        }
        entry[0x20] = (ushort)*recField22;
        if (*recField21 != '\0') {
          entry[0x21] = 8;
        }
        if (*recField23 != '\0') {
          entry[0x21] = entry[0x21] | 0x10;
        }
        entry[0x34] = *(ushort *)((uint)*(byte *)recField40 * 4 + 0x1dc098);
        alphaSourceCount = (uint)*(ushort *)((uint)*(byte *)recField40 * 4 + 0x1dc09a);
        if (*recField31 == 2) {
          if (alphaSourceCount < 2) {
            alphaSourceCount = 2;
          }
LAB_000c49a8:
LAB_000c49b0:
          sourceSelectCode = (uint)*recField39;
          sourceModifier = (ushort)*(byte *)recField3c;
          slotCounter = 0;
          alphaSourceSlotPtr = entry + 0x24;
          alphaSourcesLeft = alphaSourceCount;
          if (alphaSourceCount == 0) {
            alphaSourcesLeft = 1;
          }
          do {
            slotCounter = slotCounter + 1;
            *(undefined4 *)alphaSourceSlotPtr = *(undefined4 *)(sourceSelectCode * 4 + 0x1dc04c);
            alphaSourceSlotPtr[1] = sourceModifier << 0xc | alphaSourceSlotPtr[1];
            alphaSourcesLeft = alphaSourcesLeft - 1;
            staleArgR5 = (uint *)0x1dc04c;
            if (alphaSourcesLeft == 0) goto LAB_000c4a74;
            if (slotCounter == 1) {
              sourceSelectCode = (uint)*recField3a;
              sourceModifier = (ushort)*recField3d;
            }
            else {
              if (slotCounter == 0) goto LAB_000c49b0;
              if (slotCounter == 2) {
                sourceSelectCode = (uint)*recField3b;
                sourceModifier = (ushort)*recField3e;
              }
              else {
                sourceSelectCode = 0;
                sourceModifier = 0;
              }
            }
            alphaSourceSlotPtr = alphaSourceSlotPtr + 2;
          } while( true );
        }
        staleArgR5 = recField20;
        if (alphaSourceCount != 0) goto LAB_000c49a8;
LAB_000c4a74:
        entry[0x35] = (ushort)*recField3f;
        if (*recField42 == '\x01') {
          *(uint *)(entry + 0x38) = *(uint *)(entry + 0x38) | 8;
        }
        *(undefined4 *)(entry + 0x36) = *(undefined4 *)((uint)*recField41 * 4 + 0x1dc198);
        staleArgR6 = recField3f;
        staleArgR7 = recField42;
        staleArgR9 = recField41;
        ((int (*)())psnDecRecomputeSourceUsage)(entry);
        ((int (*)())psnDecCanonicalizeEntry)(entry,r4AfterCall,staleArgR5,staleArgR6,staleArgR7,alphaHalf,staleArgR9,slotCounter);
      }
      recField1a = recField1a + 0x24;
      recField40 = recField40 + 0x12;
      recField31 = recField31 + 0x48;
      recField1c = recField1c + 0x12;
      recField1e = recField1e + 0x24;
      recField2a = recField2a + 0x48;
      recField2d = recField2d + 0x48;
      recordNumber = recordNumber + 1;
      recField2b = recField2b + 0x48;
      entryByteOffset = entryByteOffset + 0xa0;
      recField19 = recField19 + 0x48;
      recField41 = recField41 + 0x48;
      recField04 = recField04 + 0x12;
      recField2e = recField2e + 0x48;
      recField08 = recField08 + 0x12;
      recField39 = recField39 + 0x48;
      recField3c = recField3c + 0x12;
      recField09 = recField09 + 0x48;
      recField06 = recField06 + 0x24;
      recField0a = recField0a + 0x48;
      recField0cCopy78 = recField0cCopy78 + 0x12;
      recField0d = recField0d + 0x48;
      recField0b = recField0b + 0x48;
      recField42 = recField42 + 0x48;
      recField3a = recField3a + 0x48;
      recField3d = recField3d + 0x48;
      recField23 = recField23 + 0x48;
      recField3f = recField3f + 0x48;
      recField22 = recField22 + 0x48;
      recField0c = recField0c + 0x12;
      recField0e = recField0e + 0x24;
      recField21 = recField21 + 0x48;
      recField32 = recField32 + 0x48;
      recField18 = recField18 + 0x12;
      recField20 = recField20 + 0x12;
      recField30 = recField30 + 0x12;
      recField33 = recField33 + 0x48;
      recField0cCopyb8 = recField0cCopyb8 + 0x12;
      recField14 = recField14 + 0x12;
      recField16 = recField16 + 0x48;
      recField15 = recField15 + 0x48;
      recField0eCopyc8 = recField0eCopyc8 + 0x24;
      recField10 = recField10 + 0x12;
      recField12 = recField12 + 0x24;
      recField1aCopyd4 = recField1aCopyd4 + 0x24;
      recField2c = recField2c + 0x12;
      recField2f = recField2f + 0x48;
      recField3b = recField3b + 0x48;
      recField3e = recField3e + 0x48;
      recField1f = recField1f + 0x48;
    } while (recordNumber < *puStack00000018);
  }
  return;
}

/* psnDecodedToProgram @ 0xc4ce0 (1484 bytes) */
int psnDecodedToProgram(decodedProgram, previousRecord, outStatus)
  uint *decodedProgram;
  undefined4 *previousRecord;
  uint *outStatus;
{
  undefined1 alphaSourceSelect;
  ushort sourceSlotWord;
  uint outputScaleBits;
  undefined1 alphaSwizzleByte;
  short entryShort3a;
  undefined1 isFirstTexRecord;
  int entryAlias;
  uint entryArray;
  int loopIndex2;
  bool loopContinue;
  byte entryByte15;
  float entryFloat6c;
  undefined2 rgbDestReg;
  undefined2 alphaDestReg;
  ushort flagsBit4;
  float oneF;
  int entryMode;
  short rgbRegField;
  undefined1 alphaWriteFlag;
  short alphaRegField;
  uint sourceTableIndex;
  uint rgbSourceModifier;
  uint channelSwizzle;
  int loopIndex;
  int sourceSlotCursor;
  int entry;
  uint alphaSourceModifier;
  undefined1 alphaSourceModifierByte;
  undefined4 headerWord1;
  uint loopIndex3;
  undefined1 rgbSourceSelect;
  undefined1 rgbSourceModifierByte;
  undefined4 *outRecord;
  undefined1 outputScaleCode;
  
  headerWord1 = previousRecord[1];
  _memset(previousRecord,0,0x48);
  previousRecord[1] = headerWord1;
  previousRecord[2] = *decodedProgram;
  *(undefined1 *)(previousRecord + 3) = *(undefined1 *)(decodedProgram + 4);
  *(undefined1 *)((int)previousRecord + 0xd) = *(undefined1 *)((int)decodedProgram + 0x11);
  *outStatus = 0;
  if (*decodedProgram != 0) {
    isFirstTexRecord = 1;
    loopIndex3 = 0;
    do {
      outRecord = previousRecord + 0x12;
      _memset(outRecord,0,0x48);
      entryArray = decodedProgram[2];
      entry = loopIndex3 * 0xa0 + entryArray;
      entryMode = *(int *)(entry + 0x8c);
      rgbDestReg = *(undefined2 *)(entry + 4);
      alphaDestReg = *(undefined2 *)(entry + 0x44);
      if (entryMode == 1) {
        *(undefined2 *)(previousRecord + 0x15) = rgbDestReg;
        *outRecord = 2;
        *(undefined2 *)((int)previousRecord + 0x56) = *(undefined2 *)(entry + 0x80);
        if ((*(short *)(entry + 2) == 0 && *(short *)(entry + 6) == 0) &&
           ((*(uint *)(entry + 0x30) & 1) == 0)) {
          *(undefined1 *)((int)previousRecord + 0x61) = 0;
          *(undefined1 *)((int)previousRecord + 0x62) = 0;
        }
        else {
          *(char *)((int)previousRecord + 0x62) = (char)*(undefined2 *)(entry + 0x28);
          *(char *)((int)previousRecord + 0x61) = (char)((ushort)*(undefined2 *)(entry + 0x28) >> 8);
        }
        entryByte15 = *(byte *)(entry + 0x15);
        *(undefined1 *)(previousRecord + 0x1a) = isFirstTexRecord;
        isFirstTexRecord = 0;
        *(byte *)((int)previousRecord + 0x67) = entryByte15 ^ 0xf;
      }
      else if (entryMode == 0) {
        *(undefined2 *)((int)previousRecord + 0x4e) = rgbDestReg;
        *(undefined2 *)(previousRecord + 0x13) = alphaDestReg;
        *outRecord = 1;
        if ((*(short *)(entry + 2) == 0 && *(short *)(entry + 6) == 0) &&
           ((*(uint *)(entry + 0x30) & 1) == 0)) {
          *(undefined1 *)((int)previousRecord + 0x53) = 0;
        }
        else {
          entryShort3a = *(short *)(entry + 0x3a);
          if ((entryShort3a == 2) || (entryShort3a == 3)) {
            *(char *)((int)previousRecord + 0x53) = (char)entryShort3a;
          }
          else if (entryShort3a == 0) {
            *(undefined1 *)((int)previousRecord + 0x53) = 1;
          }
        }
        if ((*(short *)(entry + 0x42) != 0 || *(short *)(entry + 0x46) != 0) ||
           (alphaWriteFlag = 0, (*(uint *)(entry + 0x70) & 1) != 0)) {
          alphaWriteFlag = 1;
        }
        *(undefined1 *)((int)previousRecord + 0x51) = alphaWriteFlag;
        if (*(short *)(entry + 0x80) == -1) {
          *(undefined1 *)((int)previousRecord + 0x52) = 0;
        }
        else {
          *(char *)((int)previousRecord + 0x52) = (char)*(short *)(entry + 0x80);
        }
        if (*(short *)(entry + 0x86) == -1) {
          *(undefined1 *)(previousRecord + 0x14) = 0;
        }
        else {
          *(char *)(previousRecord + 0x14) = (char)*(short *)(entry + 0x86);
        }
        oneF = FLOAT_001aa0e8;
        *(bool *)((int)previousRecord + 0x55) = *(float *)(entry + 0x2c) != FLOAT_001aa0e8;
        entryFloat6c = *(float *)(entry + 0x6c);
        *(undefined1 *)((int)previousRecord + 0x57) = 0;
        *(undefined1 *)((int)previousRecord + 0x56) = 0;
        *(bool *)(previousRecord + 0x15) = entryFloat6c != oneF;
      }
      else if (entryMode == 2) {
        *(undefined2 *)(previousRecord + 0x15) = rgbDestReg;
        *(undefined2 *)(previousRecord + 0x18) = alphaDestReg;
        *outRecord = 3;
        *(char *)((int)previousRecord + 0x5d) = (char)*(undefined2 *)(entry + 2);
        *(char *)((int)previousRecord + 0x5e) = (char)*(undefined2 *)(loopIndex3 * 0xa0 + entryArray);
        *(byte *)((int)previousRecord + 0x69) = (byte)(*(ushort *)(entry + 0x42) >> 3) & 1;
        flagsBit4 = *(ushort *)(entry + 0x42) >> 4 & 1;
        *(char *)((int)previousRecord + 0x6b) = (char)flagsBit4;
        if (flagsBit4 != 0) {
          *outStatus = *outStatus | 1;
        }
        loopIndex = 0;
        *(char *)((int)previousRecord + 0x6a) = (char)*(undefined2 *)(entry + 0x40);
        *(char *)(previousRecord + 0x17) = (char)*(undefined2 *)(entry + 6);
        *(byte *)(previousRecord + 0x1a) = (byte)(*(ushort *)(entry + 0x46) >> 3) & 1;
        entryAlias = entry;
        do {
          rgbRegField = *(short *)(entryAlias + 0x80);
          alphaRegField = *(short *)(entryAlias + 0x86);
          if (rgbRegField == -1) {
            rgbRegField = -0x8000;
          }
          if (alphaRegField == -1) {
            alphaRegField = -0x8000;
          }
          if (loopIndex == 1) {
            *(short *)(previousRecord + 0x16) = rgbRegField;
            *(short *)(previousRecord + 0x19) = alphaRegField;
          }
          else if (loopIndex == 0) {
            *(short *)((int)previousRecord + 0x56) = rgbRegField;
            *(short *)((int)previousRecord + 0x62) = alphaRegField;
          }
          else if (loopIndex == 2) {
            *(short *)((int)previousRecord + 0x5a) = rgbRegField;
            *(short *)((int)previousRecord + 0x66) = alphaRegField;
          }
          loopContinue = loopIndex != 2;
          entryAlias = entryAlias + 2;
          loopIndex = loopIndex + 1;
        } while (loopContinue);
        loopIndex2 = 0;
        do {
          rgbSourceSelect = 0;
          rgbSourceModifier = 0;
          alphaSourceSelect = 0;
          alphaSourceModifier = 0;
          loopIndex = 0;
          sourceSlotCursor = entry + 8;
          do {
            sourceSlotWord = *(ushort *)(loopIndex2 * 4 + sourceSlotCursor + 2);
            channelSwizzle = *(ushort *)(loopIndex2 * 4 + sourceSlotCursor) & 3;
            if (loopIndex == 0) {
              sourceTableIndex = 6;
              if (((sourceSlotWord & 0x300) != 0x100) && (sourceTableIndex = 5, (sourceSlotWord & 0x300) != 0x200)) {
                sourceTableIndex = sourceSlotWord & 0x1f;
              }
              rgbSourceModifier = (sourceSlotWord & 0x3000) >> 0xc;
              rgbSourceSelect = *(undefined1 *)(sourceTableIndex * 4 + 0x1dc000 + channelSwizzle);
            }
            else if (loopIndex == 1) {
              alphaSourceModifier = (sourceSlotWord & 0x3000) >> 0xc;
              alphaSourceSelect = *(undefined1 *)((sourceSlotWord & 0x1f) * 4 + 0x1dbfb4 + channelSwizzle);
            }
            loopContinue = loopIndex != 1;
            sourceSlotCursor = sourceSlotCursor + 0x40;
            loopIndex = loopIndex + 1;
          } while (loopContinue);
          rgbSourceModifierByte = (undefined1)rgbSourceModifier;
          alphaSourceModifierByte = (undefined1)alphaSourceModifier;
          if (loopIndex2 == 1) {
            *(undefined1 *)((int)previousRecord + 0x73) = rgbSourceSelect;
            *(undefined1 *)((int)previousRecord + 0x76) = rgbSourceModifierByte;
            *(undefined1 *)((int)previousRecord + 0x82) = alphaSourceSelect;
            *(undefined1 *)((int)previousRecord + 0x85) = alphaSourceModifierByte;
          }
          else if (loopIndex2 == 0) {
            *(undefined1 *)((int)previousRecord + 0x72) = rgbSourceSelect;
            *(undefined1 *)((int)previousRecord + 0x75) = rgbSourceModifierByte;
            *(undefined1 *)((int)previousRecord + 0x81) = alphaSourceSelect;
            *(undefined1 *)(previousRecord + 0x21) = alphaSourceModifierByte;
          }
          else if (loopIndex2 == 2) {
            *(undefined1 *)(previousRecord + 0x1d) = rgbSourceSelect;
            *(undefined1 *)((int)previousRecord + 0x77) = rgbSourceModifierByte;
            *(undefined1 *)((int)previousRecord + 0x83) = alphaSourceSelect;
            *(undefined1 *)((int)previousRecord + 0x86) = alphaSourceModifierByte;
          }
          loopContinue = loopIndex2 != 2;
          loopIndex2 = loopIndex2 + 1;
        } while (loopContinue);
        loopIndex = 0;
        entryAlias = entry;
        do {
          outputScaleBits = (uint)(int)((double)*(float *)(entryAlias + 0x2c) * DOUBLE_001aa290);
          outputScaleCode = (undefined1)outputScaleBits;
          switch(outputScaleBits & 0xff) {
          case 1:
            outputScaleCode = 6;
            break;
          case 2:
            outputScaleCode = 5;
            break;
          case 4:
            outputScaleCode = 4;
            break;
          case 8:
            outputScaleCode = 0;
            break;
          case 0x10:
            outputScaleCode = 1;
            break;
          case 0x20:
            outputScaleCode = 2;
            break;
          case 0x40:
            outputScaleCode = 3;
          }
          if (loopIndex == 0) {
            *(undefined1 *)((int)previousRecord + 0x7a) = outputScaleCode;
            *(byte *)((int)previousRecord + 0x7b) = (byte)(*(uint *)(entry + 0x30) >> 3) & 1;
          }
          else if (loopIndex == 1) {
            *(undefined1 *)((int)previousRecord + 0x89) = outputScaleCode;
            *(byte *)((int)previousRecord + 0x8a) = (byte)(*(uint *)(entry + 0x70) >> 3) & 1;
          }
          loopContinue = loopIndex != 1;
          entryAlias = entryAlias + 0x40;
          loopIndex = loopIndex + 1;
        } while (loopContinue);
        loopIndex = 0;
        entryAlias = entry;
        do {
          alphaSwizzleByte = *(undefined1 *)((uint)*(ushort *)(entryAlias + 0x28) * 2 + 0x1dbf98 + loopIndex);
          if (loopIndex == 0) {
            *(undefined1 *)((int)previousRecord + 0x79) = alphaSwizzleByte;
            *(char *)(previousRecord + 0x1e) = (char)*(undefined2 *)(entry + 0x2a);
          }
          else if (loopIndex == 1) {
            *(undefined1 *)(previousRecord + 0x22) = alphaSwizzleByte;
            *(char *)((int)previousRecord + 0x87) = (char)*(undefined2 *)(entry + 0x6a);
          }
          loopContinue = loopIndex != 1;
          entryAlias = entryAlias + 0x40;
          loopIndex = loopIndex + 1;
        } while (loopContinue);
        isFirstTexRecord = 1;
        *(undefined1 *)(previousRecord + 0x1f) = 0;
      }
      loopIndex3 = loopIndex3 + 1;
      previousRecord = outRecord;
    } while (loopIndex3 < *decodedProgram);
  }
  return;
}

/* psnAccumulateRgbSelectRead @ 0xc5460 (72 bytes) */
int psnAccumulateRgbSelectRead(selectCode, writeMask, passThroughR5, passThroughR6, sourceUsage, passThroughR8)
  undefined4 selectCode;
  uint writeMask;
  int passThroughR5;
  int passThroughR6;
  int sourceUsage;
  int passThroughR8;
{
  ushort currentUsageBits;
  int sourceUsageEntry;
  int secondUsageEntry;
  ushort componentBits;
  
  componentBits = (ushort)(writeMask & 7);
  if ((writeMask & 7) == 0) {
    return;
  }
  switch(selectCode) {
  case 0:
  case 4:
  case 8:
  case 0xf:
    break;
  case 1:
  case 5:
  case 9:
  case 0x10:
    componentBits = 1;
    break;
  case 2:
  case 6:
  case 10:
  case 0x11:
    componentBits = 2;
    break;
  case 3:
  case 7:
  case 0xb:
  case 0x12:
    componentBits = 4;
    break;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0x13:
    componentBits = 8;
    break;
  default:
    componentBits = 0;
    break;
  case 0x17:
  case 0x18:
  case 0x19:
    componentBits = (ushort)((writeMask & 3) << 1) | (ushort)(writeMask >> 2) & 1;
    break;
  case 0x1a:
  case 0x1b:
  case 0x1c:
    componentBits = (ushort)((writeMask & 1) << 2) | (ushort)(writeMask >> 1) & 3;
    break;
  case 0x1d:
  case 0x1e:
  case 0x1f:
    componentBits = (ushort)((writeMask & 1) << 3) | (ushort)((writeMask & 2) << 1) | (ushort)(writeMask >> 1) & 2
    ;
  }
  switch(selectCode) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 0x17:
  case 0x1a:
    *(ushort *)(sourceUsage + 2) = componentBits | *(ushort *)(sourceUsage + 2);
    break;
  case 4:
  case 5:
  case 6:
  case 7:
  case 0x18:
  case 0x1b:
    *(ushort *)(sourceUsage + 6) = componentBits | *(ushort *)(sourceUsage + 6);
    break;
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0x19:
  case 0x1c:
    *(ushort *)(sourceUsage + 10) = componentBits | *(ushort *)(sourceUsage + 10);
    break;
  case 0xc:
    *(ushort *)(sourceUsage + 0xe) = componentBits | *(ushort *)(sourceUsage + 0xe);
    break;
  case 0xd:
    *(ushort *)(sourceUsage + 0x12) = componentBits | *(ushort *)(sourceUsage + 0x12);
    break;
  case 0xe:
    *(ushort *)(sourceUsage + 0x16) = componentBits | *(ushort *)(sourceUsage + 0x16);
    break;
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
    *(ushort *)(sourceUsage + 2) = componentBits | *(ushort *)(sourceUsage + 2);
    *(ushort *)(passThroughR8 + 2) = componentBits | *(ushort *)(passThroughR8 + 2);
    if (1 < passThroughR5 - 1U) {
      return;
    }
    sourceUsageEntry = sourceUsage + 4;
    secondUsageEntry = passThroughR8 + 4;
    goto code_r0x000c5714;
  case 0x13:
    *(ushort *)(sourceUsage + 0xe) = componentBits | *(ushort *)(sourceUsage + 0xe);
    *(ushort *)(passThroughR8 + 10) = componentBits | *(ushort *)(passThroughR8 + 10);
    if (1 < passThroughR6 - 1U) {
      return;
    }
    sourceUsageEntry = sourceUsage + 0x10;
    secondUsageEntry = passThroughR8 + 0xc;
code_r0x000c5714:
    *(ushort *)(sourceUsageEntry + 2) = componentBits | *(ushort *)(sourceUsageEntry + 2);
    *(ushort *)(secondUsageEntry + 2) = componentBits | *(ushort *)(secondUsageEntry + 2);
    break;
  case 0x1d:
    *(ushort *)(sourceUsage + 2) = componentBits & 7 | *(ushort *)(sourceUsage + 2);
    *(ushort *)(sourceUsage + 0xe) = componentBits & 8 | *(ushort *)(sourceUsage + 0xe);
    break;
  case 0x1e:
    sourceUsageEntry = sourceUsage + 4;
    secondUsageEntry = sourceUsage + 0x10;
    currentUsageBits = *(ushort *)(sourceUsage + 6);
    goto code_r0x000c5788;
  case 0x1f:
    sourceUsageEntry = sourceUsage + 8;
    secondUsageEntry = sourceUsage + 0x14;
    currentUsageBits = *(ushort *)(sourceUsage + 10);
code_r0x000c5788:
    *(ushort *)(sourceUsageEntry + 2) = componentBits & 7 | currentUsageBits;
    *(ushort *)(secondUsageEntry + 2) = componentBits & 8 | *(ushort *)(secondUsageEntry + 2);
  }
  return;
}

/* psnAccumulateAlphaSelectRead @ 0xc57b0 (104 bytes) */
int psnAccumulateAlphaSelectRead(selectCode, writeMask, passThroughR5, passThroughR6, sourceUsage, passThroughR8)
  undefined4 selectCode;
  uint writeMask;
  undefined4 passThroughR5;
  undefined4 passThroughR6;
  int sourceUsage;
  int passThroughR8;
{
  int sourceUsageEntry;
  ushort componentBits;
  int secondUsageEntry;
  
  if ((writeMask & 8) == 0) {
    return;
  }
  componentBits = 0;
  switch(selectCode) {
  case 0:
  case 3:
  case 6:
  case 0xc:
    componentBits = 1;
    break;
  case 1:
  case 4:
  case 7:
  case 0xd:
    componentBits = 2;
    break;
  case 2:
  case 5:
  case 8:
  case 0xe:
    componentBits = 4;
    break;
  case 9:
  case 10:
  case 0xb:
  case 0xf:
    componentBits = 8;
  }
  switch(selectCode) {
  case 0:
  case 1:
  case 2:
    *(ushort *)(sourceUsage + 2) = componentBits | *(ushort *)(sourceUsage + 2);
    break;
  case 3:
  case 4:
  case 5:
    *(ushort *)(sourceUsage + 6) = componentBits | *(ushort *)(sourceUsage + 6);
    break;
  case 6:
  case 7:
  case 8:
    *(ushort *)(sourceUsage + 10) = componentBits | *(ushort *)(sourceUsage + 10);
    break;
  case 9:
    *(ushort *)(sourceUsage + 0xe) = componentBits | *(ushort *)(sourceUsage + 0xe);
    break;
  case 10:
    *(ushort *)(sourceUsage + 0x12) = componentBits | *(ushort *)(sourceUsage + 0x12);
    break;
  case 0xb:
    *(ushort *)(sourceUsage + 0x16) = componentBits | *(ushort *)(sourceUsage + 0x16);
    break;
  case 0xc:
  case 0xd:
  case 0xe:
    *(ushort *)(sourceUsage + 2) = componentBits | *(ushort *)(sourceUsage + 2);
    *(ushort *)(passThroughR8 + 2) = componentBits | *(ushort *)(passThroughR8 + 2);
    if (1 < (ushort)((*(unsigned short *)((unsigned char *)&(passThroughR5) + 2)) - 1U)) {
      return;
    }
    sourceUsageEntry = sourceUsage + 4;
    secondUsageEntry = passThroughR8 + 4;
    goto code_r0x000c5994;
  case 0xf:
    *(ushort *)(sourceUsage + 0xe) = componentBits | *(ushort *)(sourceUsage + 0xe);
    *(ushort *)(passThroughR8 + 10) = componentBits | *(ushort *)(passThroughR8 + 10);
    if (1 < (ushort)((*(unsigned short *)((unsigned char *)&(passThroughR6) + 2)) - 1U)) {
      return;
    }
    sourceUsageEntry = sourceUsage + 0x10;
    secondUsageEntry = passThroughR8 + 0xc;
code_r0x000c5994:
    *(ushort *)(sourceUsageEntry + 2) = componentBits | *(ushort *)(sourceUsageEntry + 2);
    *(ushort *)(secondUsageEntry + 2) = componentBits | *(ushort *)(secondUsageEntry + 2);
  }
  return;
}

/* psnRaReleaseUse @ 0xc59c0 (580 bytes) */
int psnRaReleaseUse(operand, tempTable, freeList)
  ushort *operand;
  int *tempTable;
  int *freeList;
{
  int prevEntryOffset;
  int freeListBase;
  int scanIndex;
  int freeListBaseEnd;
  int insertByteOffset;
  ushort neighbourReg;
  ushort freeCount;
  ushort releasedReg;
  ushort tempAltReg;
  uint freeCountU;
  uint insertPos;
  uint tempIndex;
  ushort usedMask;
  ushort remainingMask;
  int shiftCount;
  ushort *scanCursor;
  int bankBase;
  ushort bankMaskBits;
  int shiftOffset;
  uint freeCountOld;
  short expectedPrevReg;
  int tempEntry;
  uint scanCounter;
  
  usedMask = operand[1];
  if (usedMask == 0) {
    *operand = 0;
    return;
  }
  tempIndex = (uint)*operand;
  if (tempIndex < *(ushort *)(tempTable + 2)) {
    bankBase = tempTable[1];
    bankMaskBits = (usedMask == 8) + 7;
  }
  else {
    bankBase = *tempTable;
    bankMaskBits = 0xf;
    tempIndex = tempIndex - *(ushort *)(tempTable + 2) & 0xffff;
  }
  tempEntry = bankBase + tempIndex * 8;
  usedMask = usedMask & *(ushort *)(tempEntry + 4);
  operand[1] = usedMask;
  if (usedMask == 0) {
    *operand = 0;
    return;
  }
  if (bankMaskBits == 8) {
    tempAltReg = *(ushort *)(tempEntry + 2);
  }
  else {
    tempAltReg = *(ushort *)(bankBase + tempIndex * 8);
  }
  *operand = tempAltReg;
  remainingMask = *(ushort *)(tempEntry + 4) & ~operand[1];
  *(ushort *)(tempEntry + 4) = remainingMask;
  freeCountOld = (uint)*(ushort *)(freeList + 1);
  releasedReg = *operand;
  insertPos = freeCountOld - 1;
  if ((bankMaskBits & remainingMask) != 0) {
    return;
  }
  if (insertPos == 0) {
    freeListBase = *freeList;
    insertByteOffset = 0;
    insertPos = 0;
  }
  else {
    freeListBase = *freeList;
    insertByteOffset = insertPos * 4;
    if (releasedReg <= *(ushort *)(insertByteOffset + freeListBase + -4)) {
      scanCursor = (ushort *)(insertByteOffset + freeListBase + -8);
      scanCounter = insertPos;
      do {
        insertByteOffset = insertByteOffset + -4;
        insertPos = insertPos - 1;
        scanCounter = scanCounter - 1;
        if (scanCounter == 0) {
          insertByteOffset = insertPos * 4;
          break;
        }
        neighbourReg = *scanCursor;
        scanCursor = scanCursor + -2;
      } while (releasedReg <= neighbourReg);
    }
  }
  if (*(ushort *)(insertByteOffset + freeListBase) == releasedReg) {
    *(ushort *)(insertByteOffset + freeListBase + 2) = bankMaskBits | *(ushort *)(insertByteOffset + freeListBase + 2);
    freeCount = *(ushort *)(freeList + 1);
  }
  else {
    if (insertPos < freeCountOld) {
      shiftCount = freeCountOld - insertPos;
      shiftOffset = freeCountOld << 2;
      if (freeCountOld - 1 < insertPos) {
        shiftCount = 1;
      }
      while( true ) {
        *(undefined4 *)(shiftOffset + freeListBase) = *(undefined4 *)(shiftOffset + freeListBase + -4);
        shiftOffset = shiftOffset + -4;
        shiftCount = shiftCount + -1;
        if (shiftCount == 0) break;
        freeListBase = *freeList;
      }
      freeListBase = *freeList;
    }
    *(ushort *)(insertByteOffset + freeListBase) = releasedReg;
    *(ushort *)(insertByteOffset + *freeList + 2) = bankMaskBits;
    freeCount = *(short *)(freeList + 1) + 1;
    *(ushort *)(freeList + 1) = freeCount;
  }
  freeCountU = (uint)freeCount;
  freeListBaseEnd = *freeList;
  if (freeCountU - 1 == 0) {
    return;
  }
  prevEntryOffset = (freeCountU - 2) * 4;
  expectedPrevReg = *(short *)((freeCountU - 1) * 4 + freeListBaseEnd) + -1;
  if (*(short *)(freeListBaseEnd + prevEntryOffset) != expectedPrevReg) {
    return;
  }
  if (*(short *)(freeListBaseEnd + prevEntryOffset + 2) == 0xf) {
    scanIndex = freeCountU - 1;
    while( true ) {
      prevEntryOffset = prevEntryOffset + -4;
      freeCount = freeCount - 1;
      *(ushort *)(freeList + 1) = freeCount;
      scanIndex = scanIndex + -1;
      if (scanIndex == 0) {
        return;
      }
      expectedPrevReg = expectedPrevReg + -1;
      if (*(short *)(prevEntryOffset + freeListBaseEnd) != expectedPrevReg) break;
      if (*(short *)(prevEntryOffset + freeListBaseEnd + 2) != 0xf) {
        return;
      }
    }
    return;
  }
  return;
}

/* psnRaAssignDefinition @ 0xc5c50 (476 bytes) */
int psnRaAssignDefinition(operand, tempTable, freeList, unusedArgR6, unusedArgR7, unusedArgR8, unusedArgR9, unusedArgR10)
  ushort *operand;
  int *tempTable;
  int *freeList;
  undefined4 unusedArgR6;
  undefined4 unusedArgR7;
  undefined4 unusedArgR8;
  undefined4 unusedArgR9;
  undefined4 unusedArgR10;
{
  ushort scanFreeMask;
  ushort entryFreeMask;
  ushort entryUsedMask;
  int freeShiftOffset;
  int freeByteOffset;
  uint freePos;
  ushort bankMaskBits;
  ushort allocatedReg;
  ushort resultReg;
  uint tempIndex;
  ushort *cursor;
  int bankBase;
  uint freeEntryCount;
  ushort *tempEntry;
  ushort requestedMask;
  int freeListBase;
  ushort *freeEntry;
  
  tempIndex = (uint)*operand;
  if ((*operand & 0x8000) == 0) {
    requestedMask = operand[1];
    resultReg = 0;
    if (requestedMask != 0) {
      if (tempIndex < *(ushort *)(tempTable + 2)) {
        bankBase = tempTable[1];
        bankMaskBits = 8;
        if (requestedMask != 8) {
          bankMaskBits = 7;
          operand[1] = requestedMask & 0xfff7;
        }
      }
      else {
        bankBase = *tempTable;
        bankMaskBits = 0xf;
        tempIndex = tempIndex - *(ushort *)(tempTable + 2) & 0xffff;
      }
      tempEntry = (ushort *)(bankBase + tempIndex * 8);
      entryUsedMask = tempEntry[2];
      if (entryUsedMask == 0) {
        *(undefined2 *)(bankBase + tempIndex * 8) = 0xffff;
        tempEntry[1] = 0xffff;
      }
      tempEntry[2] = entryUsedMask | operand[1];
      if ((bankMaskBits & entryUsedMask) == 0) {
        freeEntry = (ushort *)*freeList;
        entryFreeMask = freeEntry[1];
        if ((bankMaskBits & ~entryFreeMask) == 0) {
          freePos = 0;
          freeByteOffset = 0;
          freeEntryCount = 1;
        }
        else {
          cursor = freeEntry + 3;
          freePos = 0;
          do {
            freeEntryCount = freePos;
            scanFreeMask = *cursor;
            freePos = freeEntryCount + 1;
            cursor = cursor + 2;
          } while ((bankMaskBits & ~scanFreeMask) != 0);
          freeByteOffset = freePos * 4;
          freeEntryCount = freeEntryCount + 2;
          freeEntry = freeEntry + freePos * 2;
          entryFreeMask = freeEntry[1];
        }
        allocatedReg = *freeEntry;
        freeEntry[1] = entryFreeMask & ~bankMaskBits;
        if (*(ushort *)(freeList + 1) == freeEntryCount) {
          if (*(short *)(freeByteOffset + *freeList + 2) != 0) {
            *(short *)(freeList + 1) = (short)freeEntryCount + 1;
            freePos = freeEntryCount;
          }
          *(ushort *)(*freeList + freePos * 4) = allocatedReg + 1;
          *(undefined2 *)(freePos * 4 + *freeList + 2) = 0xf;
        }
        else {
          freeListBase = *freeList;
          if ((*(short *)(freeListBase + freeByteOffset + 2) == 0) &&
             (freeEntryCount = *(ushort *)(freeList + 1) - 1, *(short *)(freeList + 1) = (short)freeEntryCount,
             freePos < (freeEntryCount & 0xffff))) {
            freeShiftOffset = freePos << 2;
            while( true ) {
              freePos = freePos + 1;
              *(undefined4 *)(freeShiftOffset + freeListBase) = *(undefined4 *)(freeShiftOffset + freeListBase + 4);
              freeShiftOffset = freeShiftOffset + 4;
              if (*(ushort *)(freeList + 1) <= freePos) break;
              freeListBase = *freeList;
            }
          }
        }
        if ((bankMaskBits & 7) != 0) {
          *tempEntry = allocatedReg;
        }
        if ((bankMaskBits & 8) != 0) {
          tempEntry[1] = allocatedReg;
        }
      }
      if (bankMaskBits == 8) {
        resultReg = tempEntry[1];
      }
      else {
        resultReg = *tempEntry;
      }
    }
    *operand = resultReg;
    return;
  }
  return;
}

/* psnAnalyzeProgram @ 0xc5e60 (1524 bytes) */
int psnAnalyzeProgram(psnProgram)
  undefined4 *psnProgram;
{
  undefined4 *cursor7;
  int loopIndex2;
  uint loopIndex;
  uint usedBit;
  ushort regFieldValue;
  undefined4 *returnCursor;
  ushort *recFieldShortPtr10;
  ushort *recFieldShortPtre;
  ushort *recFieldShortPtr6;
  char *recFieldBytePtr9;
  int iVar8;
  int wordIndex;
  char *recFieldBytePtrb;
  ushort *recFieldShortPtr4;
  ushort maxRegister;
  uint fileUseSum;
  ushort *recFieldShortPtr18;
  byte *recFieldBytePtr19;
  ushort *recFieldShortPtrc;
  char *recFieldBytePtr34;
  ushort *recFieldShortPtr1e;
  ushort *recFieldShortPtr1c;
  ushort *cursor2;
  ushort *cursor3;
  ushort *recFieldShortPtr1a;
  ushort *cursor4;
  char *recFieldBytePtr20;
  ushort *recFieldShortPtr12;
  ushort *cursor5;
  ushort *cursor6;
  char *recFieldBytePtr14;
  char *cursor;
  uint kind1Count;
  int remaining;
  /* issue #64 live-repro (crash #8, past the ilRewriteForTextureState fixes): local_98/local_94/local_90/
   * local_8c/local_88/local_84/local_80/local_7c were 8 separately-declared 4-byte locals,
   * each initialized to the same value below, that a later loop (`*(short*)((int)&local_98 +
   * iVar8) = ...`, iVar8 running 0..30) treats as one contiguous 32-byte/16-ushort array -
   * the same Ghidra local-splitting defect class already fixed in FUN_000fd5c8,
   * ffpsBuildProgram's local_68 cluster, and this session's own ConstRecord__findInTable local_2c cluster.
   * Only local_98's OWN 4 bytes are real storage; the walk past it (needed to reach what
   * should be local_94/local_90/.../local_7c) ran off local_98's real bounds into whatever
   * gcc actually placed next on the stack. Live-verified on real hardware via a hardware
   * watchpoint on the calling function's saved r30/r31 stack slot: this loop's clamping
   * store (`*(undefined2*)((int)&local_98+iVar8) = 0xff;`) was confirmed to be the exact
   * write corrupting that slot, which is what caused gld_compileILProgram's r30 to read back as
   * 0xff00ff and crash on its next stack-relative access. Fixed by giving the cluster real,
   * guaranteed-contiguous storage as an array (local_7c is kept as its own separate variable
   * too, since it is independently used above for the early-return check; fileUseCounts[7] is
   * initialized to the same value alongside it so the walk's last slot still gets it). */
  uint fileUseCounts[8];
  uint local_7c;
  uint alreadyAnalysed;
  uint fileCount4;
  uint fileCount3;
  int noKind2Yet;
  uint fileCount2;
  uint local_68;
  uint fileCount1;
  uint kind2Count;
  undefined4 maxFlaggedRegister;
  uint fileCount0;
  uint instructionCount;
  
  alreadyAnalysed = (uint)*(ushort *)(psnProgram + 5);
  if (alreadyAnalysed != 0) {
    return;
  }
  instructionCount = psnProgram[2];
  fileUseCounts[0] = alreadyAnalysed;
  fileUseCounts[1] = alreadyAnalysed;
  fileUseCounts[2] = alreadyAnalysed;
  fileUseCounts[3] = alreadyAnalysed;
  fileUseCounts[4] = alreadyAnalysed;
  fileUseCounts[5] = alreadyAnalysed;
  fileUseCounts[6] = alreadyAnalysed;
  fileUseCounts[7] = alreadyAnalysed;
  if (instructionCount == 0) {
    fileCount0 = instructionCount;
    fileCount3 = instructionCount;
    fileCount2 = instructionCount;
    fileCount4 = instructionCount;
    noKind2Yet = 1;
    maxFlaggedRegister = 0;
    fileCount1 = instructionCount;
    kind2Count = instructionCount;
    maxRegister = 0;
  }
  else {
    recFieldShortPtr1a = (ushort *)((int)psnProgram + 0x62);
    kind1Count = 0;
    kind2Count = 0;
    noKind2Yet = 1;
    fileCount1 = 0;
    fileCount4 = 0;
    fileCount2 = 0;
    fileCount0 = 0;
    fileCount3 = 0;
    maxFlaggedRegister = 0;
    recFieldBytePtr20 = (char *)(psnProgram + 0x1a);
    recFieldShortPtr12 = (ushort *)((int)psnProgram + 0x5a);
    recFieldShortPtr10 = (ushort *)(psnProgram + 0x16);
    recFieldShortPtre = (ushort *)((int)psnProgram + 0x56);
    recFieldShortPtrc = (ushort *)(psnProgram + 0x15);
    recFieldBytePtr34 = (char *)(psnProgram + 0x1f);
    recFieldShortPtr1e = (ushort *)((int)psnProgram + 0x66);
    recFieldShortPtr1c = (ushort *)(psnProgram + 0x19);
    recFieldShortPtr18 = (ushort *)(psnProgram + 0x18);
    recFieldBytePtr14 = (char *)(psnProgram + 0x17);
    recFieldBytePtr19 = (byte *)((int)psnProgram + 0x61);
    recFieldShortPtr4 = (ushort *)(psnProgram + 0x13);
    recFieldBytePtr9 = (char *)((int)psnProgram + 0x51);
    recFieldShortPtr6 = (ushort *)((int)psnProgram + 0x4e);
    recFieldBytePtrb = (char *)((int)psnProgram + 0x53);
    loopIndex = 1;
    maxRegister = 0;
    cursor2 = recFieldShortPtre;
    cursor3 = recFieldShortPtr10;
    cursor4 = recFieldShortPtr1a;
    cursor5 = recFieldShortPtr12;
    cursor6 = recFieldShortPtrc;
    cursor = recFieldBytePtr20;
    cursor7 = psnProgram;
    do {
      cursor7 = cursor7 + 0x12;
      switch(*cursor7) {
      case 1:
        if ((*recFieldBytePtrb != '\0') && (maxRegister < *recFieldShortPtr6)) {
          maxRegister = *recFieldShortPtr6;
        }
        if ((*recFieldBytePtr9 != '\0') && (maxRegister < *recFieldShortPtr4)) {
          maxRegister = *recFieldShortPtr4;
        }
        kind1Count = kind1Count + 1 & 0xffff;
        break;
      case 2:
        if (noKind2Yet == 0) {
          if (*cursor != '\0') {
            fileCount0 = fileCount0 + 1 & 0xffff;
            fileCount4 = fileCount4 + 1 & 0xffff;
          }
        }
        else {
          fileCount0 = fileCount0 + 1 & 0xffff;
        }
        if (*(byte *)recFieldShortPtr1a < 8) {
          usedBit = 1 << ((int)(char)*(byte *)recFieldShortPtr1a & 0x3fU);
          if ((usedBit & 0xba) == 0) {
            if ((usedBit & 4) == 0) {
              if ((usedBit & 0x40) != 0) {
                regFieldValue = *cursor3;
                if (*cursor3 <= maxRegister) {
                  regFieldValue = maxRegister;
                }
                maxRegister = *recFieldShortPtr12;
                if (*recFieldShortPtr12 <= regFieldValue) {
                  maxRegister = regFieldValue;
                }
                goto LAB_000c60a8;
              }
            }
            else if (maxRegister < *cursor2) {
              maxRegister = *cursor2;
            }
          }
          else {
LAB_000c60a8:
            if (maxRegister < *cursor2) {
              maxRegister = *cursor2;
            }
            if (maxRegister < *recFieldShortPtrc) {
              maxRegister = *recFieldShortPtrc;
            }
            if (*recFieldBytePtr19 < 0x10) {
              wordIndex = (uint)*recFieldBytePtr19 * 2;
              *(short *)((int)fileUseCounts + wordIndex) = *(short *)((int)fileUseCounts + wordIndex) + 1;
            }
          }
        }
        noKind2Yet = 0;
        kind2Count = kind2Count + 1 & 0xffff;
        break;
      case 3:
      case 4:
        if (fileCount0 == 0) {
          fileCount0 = 1;
        }
        if ((*recFieldBytePtr14 != '\0') && (maxRegister < *cursor6)) {
          maxRegister = *cursor6;
        }
        regFieldValue = *recFieldShortPtre;
        if ((regFieldValue & 0x8000) == 0) {
          if (maxRegister < regFieldValue) {
            maxRegister = regFieldValue;
          }
        }
        else if (maxFlaggedRegister < (regFieldValue & 0x7fff)) {
          maxFlaggedRegister = regFieldValue & 0x7fff;
        }
        regFieldValue = *recFieldShortPtr10;
        if ((regFieldValue & 0x8000) == 0) {
          if (maxRegister < regFieldValue) {
            maxRegister = regFieldValue;
          }
        }
        else if (maxFlaggedRegister < (regFieldValue & 0x7fff)) {
          maxFlaggedRegister = regFieldValue & 0x7fff;
        }
        regFieldValue = *cursor5;
        if ((regFieldValue & 0x8000) == 0) {
          if (maxRegister < regFieldValue) {
            maxRegister = regFieldValue;
          }
        }
        else if (maxFlaggedRegister < (regFieldValue & 0x7fff)) {
          maxFlaggedRegister = regFieldValue & 0x7fff;
        }
        if ((*recFieldBytePtr20 != '\0') && (maxRegister < *recFieldShortPtr18)) {
          maxRegister = *recFieldShortPtr18;
        }
        regFieldValue = *cursor4;
        if ((regFieldValue & 0x8000) == 0) {
          if (maxRegister < regFieldValue) {
            maxRegister = regFieldValue;
          }
        }
        else if (maxFlaggedRegister < (regFieldValue & 0x7fff)) {
          maxFlaggedRegister = regFieldValue & 0x7fff;
        }
        regFieldValue = *recFieldShortPtr1c;
        if ((regFieldValue & 0x8000) == 0) {
          if (maxRegister < regFieldValue) {
            maxRegister = regFieldValue;
          }
        }
        else if (maxFlaggedRegister < (regFieldValue & 0x7fff)) {
          maxFlaggedRegister = regFieldValue & 0x7fff;
        }
        regFieldValue = *recFieldShortPtr1e;
        if ((regFieldValue & 0x8000) == 0) {
          if (maxRegister < regFieldValue) {
            maxRegister = regFieldValue;
          }
        }
        else if (maxFlaggedRegister < (regFieldValue & 0x7fff)) {
          maxFlaggedRegister = regFieldValue & 0x7fff;
        }
        if (*recFieldBytePtr34 != '\0') {
          fileCount3 = fileCount3 + 1 & 0xffff;
        }
        noKind2Yet = 1;
        fileCount1 = fileCount1 + 1 & 0xffff;
        break;
      case 5:
        fileCount2 = fileCount2 + 1 & 0xffff;
      }
      loopIndex = loopIndex + 1;
      recFieldBytePtr34 = recFieldBytePtr34 + 0x48;
      recFieldShortPtr1e = recFieldShortPtr1e + 0x24;
      recFieldShortPtr1c = recFieldShortPtr1c + 0x24;
      cursor4 = cursor4 + 0x24;
      recFieldShortPtr18 = recFieldShortPtr18 + 0x24;
      recFieldBytePtr20 = recFieldBytePtr20 + 0x48;
      cursor5 = cursor5 + 0x24;
      recFieldShortPtr10 = recFieldShortPtr10 + 0x24;
      recFieldShortPtre = recFieldShortPtre + 0x24;
      cursor6 = cursor6 + 0x24;
      recFieldBytePtr14 = recFieldBytePtr14 + 0x48;
      recFieldBytePtr19 = recFieldBytePtr19 + 0x48;
      recFieldShortPtrc = recFieldShortPtrc + 0x24;
      cursor2 = cursor2 + 0x24;
      recFieldShortPtr12 = recFieldShortPtr12 + 0x24;
      cursor3 = cursor3 + 0x24;
      recFieldShortPtr1a = recFieldShortPtr1a + 0x24;
      cursor = cursor + 0x48;
      recFieldShortPtr4 = recFieldShortPtr4 + 0x24;
      recFieldBytePtr9 = recFieldBytePtr9 + 0x48;
      recFieldShortPtr6 = recFieldShortPtr6 + 0x24;
      recFieldBytePtrb = recFieldBytePtrb + 0x48;
    } while (loopIndex <= instructionCount);
    if (kind1Count != 0) goto LAB_000c6350;
  }
  kind1Count = 1;
LAB_000c6350:
  if (fileCount0 == 0) {
    fileCount0 = 1;
    fileCount1 = 1;
  }
  if (noKind2Yet == 0) {
    fileCount1 = fileCount1 + 1 & 0xffff;
  }
  fileUseSum = (fileCount1 + fileCount4 & 0xffff) + fileCount3 & 0xffff;
  if (fileUseSum < kind2Count) {
    fileUseSum = kind2Count;
  }
  if (fileUseSum < fileCount2) {
    fileUseSum = fileCount2;
  }
  if (fileUseSum < kind1Count) {
    fileUseSum = kind1Count;
  }
  *(ushort *)((int)psnProgram + 0x22) = maxRegister;
  *(short *)((int)psnProgram + 0x26) = (short)fileUseSum;
  *(short *)((int)psnProgram + 0x1e) = (short)(fileCount1 + fileCount4);
  *(short *)(psnProgram + 6) = (short)kind1Count;
  *(short *)((int)psnProgram + 0x16) = (short)fileCount0;
  *(undefined2 *)(psnProgram + 10) = 0;
  *(short *)(psnProgram + 8) = (short)fileCount2;
  loopIndex2 = 0;
  remaining = 0x10;
  *(short *)(psnProgram + 7) = (short)fileCount1;
  *(short *)((int)psnProgram + 0x1a) = (short)kind2Count;
  *(undefined2 *)(psnProgram + 9) = (*(unsigned short *)((unsigned char *)&(maxFlaggedRegister) + 2));
  returnCursor = psnProgram;
  do {
    maxRegister = *(ushort *)((int)fileUseCounts + loopIndex2);
    if (0xff < maxRegister) {
      maxRegister = 0xff;
      *(undefined2 *)((int)fileUseCounts + loopIndex2) = 0xff;
    }
    *(char *)((int)returnCursor + 0x2a) = (char)maxRegister;
    loopIndex2 = loopIndex2 + 2;
    returnCursor = (undefined4 *)((int)returnCursor + 1);
    remaining = remaining + -1;
  } while (remaining != 0);
  *(undefined2 *)(psnProgram + 5) = 1;
  return;
}

/* psnReallocateTemps @ 0xc6470 (1284 bytes) */
int psnReallocateTemps(psnState, psnProgram, useSecondBank, passThroughR6, sourceUsage, passThroughR8, unusedArgR9, scanIndex)
  int psnState;
  int psnProgram;
  undefined2 *useSecondBank;
  uint *passThroughR6;
  uint *sourceUsage;
  undefined4 *passThroughR8;
  undefined4 unusedArgR9;
  uint scanIndex;
{
  bool notLastSlot;
  byte destMaskByte;
  byte sourceUseByteB;
  ushort instShort7;
  ushort instShort3;
  byte instByte10;
  uint instKind;
  bool pastLastEntry;
  byte srcSelectByte;
  ushort destRegBeforeAssign;
  ushort destRegCopy;
  uint lowComponentBit;
  uint workMask;
  int loopIndex;
  uint collectedEntry;
  byte sourceUseFlags;
  uint collectedCount;
  int psnProgramWord8;
  int loopIndex2;
  uint *lastVisitedInst;
  uint *inst;
  ushort zeroedOperandBlock [4];
  undefined4 zeroedOperandWord0;
  undefined4 zeroedOperandWord1;
  undefined2 *freeListBase;
  undefined2 freeListCount;
  ushort releaseOperandReg;
  undefined2 releaseOperandMask;
  ushort secondOperandReg;
  undefined2 secondOperandMask;
  undefined2 *tempTableBank0;
  undefined2 *tempTableBank1;
  undefined2 tempTableSplit;
  undefined4 tempTablePad;
  undefined4 zeroWordA;
  undefined4 zeroWordB;
  undefined4 zeroWordC;
  uint defOperand;
  undefined4 defOperandPad0;
  undefined4 defOperandPad1;
  undefined4 defOperandPad2;
  undefined4 defOperandPad3;
  undefined4 defOperandPad4;
  uint collectedRegs [519];
  
  workMask = 0xf;
  freeListBase = *(undefined2 **)(psnState + 0x1c);
  zeroedOperandBlock[1] = 0;
  zeroedOperandBlock[0] = 0;
  zeroedOperandBlock[3] = 0;
  zeroedOperandBlock[2] = 0;
  (*(unsigned short *)((unsigned char *)&(zeroedOperandWord0) + 2)) = 0;
  (*(unsigned short *)((unsigned char *)&(zeroedOperandWord0) + 0)) = 0;
  (*(unsigned short *)((unsigned char *)&(zeroedOperandWord1) + 2)) = 0;
  (*(unsigned short *)((unsigned char *)&(zeroedOperandWord1) + 0)) = 0;
  *freeListBase = 0;
  freeListBase[1] = 0xf;
  freeListCount = 1;
  tempTableSplit = SUB42((unsigned long)useSecondBank,0);
  tempTableBank0 = freeListBase + *(int *)(psnState + 0x30) * 2;
  _memset(tempTableBank0,0,*(int *)(psnState + 0x30) << 3);
  if (useSecondBank == (undefined2 *)0x0) {
    tempTableBank1 = useSecondBank;
  }
  else {
    tempTableBank1 = tempTableBank0 + *(int *)(psnState + 0x30) * 4;
    _memset(tempTableBank1,0,*(int *)(psnState + 0x30) * 8);
  }
  psnProgramWord8 = *(int *)(psnProgram + 8);
  if (psnProgramWord8 != 0) {
    collectedCount = 0;
    loopIndex2 = 0;
    lastVisitedInst = (uint *)0x0;
    inst = (uint *)(psnProgram + psnProgramWord8 * 0x48);
    do {
      instKind = *inst;
      if (instKind == 2) {
        releaseOperandMask = 0xf;
        releaseOperandReg = *(ushort *)(inst + 3);
        if (*(char *)((int)inst + 0x1a) == '\0') {
          workMask = 0;
          *(undefined2 *)(inst + 3) = 0;
          *(undefined1 *)((int)inst + 0x1f) = 0xf;
          *(undefined1 *)((int)inst + 0x19) = 0;
          *(undefined2 *)((int)inst + 0xe) = 0;
        }
        else {
          if (*(char *)((int)inst + 0x1a) == '\x02') {
            *(undefined2 *)(inst + 3) = 0;
          }
          else {
            ((int (*)())psnRaReleaseUse)(&releaseOperandReg,&tempTableBank0,&freeListBase);
            *(ushort *)(inst + 3) = releaseOperandReg;
          }
          defOperand = CONCAT22(*(undefined2 *)((int)inst + 0xe),
                                (ushort)*(byte *)((int)inst + 0x1f)) ^ 0xf;
          ((int (*)())psnRaAssignDefinition)(&defOperand,&tempTableBank0,&freeListBase,passThroughR6,sourceUsage,passThroughR8,workMask,scanIndex);
          workMask = (uint)(*(unsigned short *)((unsigned char *)&(defOperand) + 0));
          *(ushort *)((int)inst + 0xe) = (*(unsigned short *)((unsigned char *)&(defOperand) + 0));
        }
        if (((lastVisitedInst == (uint *)0x0) || (*lastVisitedInst != 2)) || (*(char *)(lastVisitedInst + 8) != '\0')) {
          collectedCount = 0;
        }
        sourceUsage = (uint *)(uint)*(byte *)((int)inst + 0x1a);
        if (sourceUsage != (uint *)0x0) {
          lowComponentBit = collectedCount;
          if (collectedCount == 0) {
            workMask = (uint)*(ushort *)((int)inst + 0xe);
          }
          else {
            instShort3 = *(ushort *)(inst + 3);
            passThroughR8 = (undefined4 *)(uint)instShort3;
            destRegCopy = *(ushort *)((int)inst + 0xe);
            workMask = (uint)destRegCopy;
            scanIndex = 0;
            passThroughR6 = collectedRegs;
            do {
              collectedEntry = passThroughR6[scanIndex];
              if ((instShort3 == collectedEntry) && (sourceUsage != (uint *)((int)((unsigned char *)0x0) + 2))) {
                lowComponentBit = 0;
                *(undefined1 *)(lastVisitedInst + 8) = 1;
              }
              if (collectedEntry == destRegCopy) {
                collectedCount = scanIndex;
              }
              scanIndex = scanIndex + 1;
            } while (scanIndex < lowComponentBit);
            pastLastEntry = collectedCount < lowComponentBit;
            collectedCount = lowComponentBit;
            if (pastLastEntry) goto LAB_000c6e10;
          }
          collectedCount = lowComponentBit + 1;
          collectedRegs[lowComponentBit] = workMask;
        }
        goto LAB_000c6e10;
      }
      if (instKind < 3) {
        if (instKind == 1) {
          releaseOperandReg = *(ushort *)((int)inst + 6);
          workMask = 0xf;
          releaseOperandMask = 0xf;
          secondOperandMask = 0xf;
          secondOperandReg = *(ushort *)(inst + 1);
          if (*(char *)((int)inst + 0xb) == '\0') {
            *(undefined2 *)((int)inst + 6) = 0;
            *(undefined1 *)((int)inst + 0xf) = 0xf;
            *(undefined1 *)((int)inst + 0xd) = 0;
            *(undefined1 *)((int)inst + 10) = 0;
          }
          else {
            ((int (*)())psnRaReleaseUse)(&releaseOperandReg,&tempTableBank0,&freeListBase);
            *(ushort *)((int)inst + 6) = releaseOperandReg;
            *(byte *)((int)inst + 0xf) = (byte)releaseOperandMask ^ 0xf;
          }
          if (*(char *)((int)inst + 9) == '\0') {
            *(ushort *)(inst + 1) = 0;
            *(undefined1 *)(inst + 3) = 0;
            *(undefined1 *)((int)inst + 0xe) = 0xf;
            *(undefined1 *)(inst + 2) = 0;
          }
          else {
            ((int (*)())psnRaReleaseUse)(&secondOperandReg,&tempTableBank0,&freeListBase);
            *(ushort *)(inst + 1) = secondOperandReg;
            *(byte *)((int)inst + 0xe) = (byte)secondOperandMask ^ 0xf;
          }
        }
        goto LAB_000c6e10;
      }
      if (4 < instKind) goto LAB_000c6e10;
      releaseOperandReg = *(ushort *)(inst + 3);
      secondOperandReg = *(ushort *)(inst + 6);
      secondOperandMask = 0;
      releaseOperandMask = (ushort)*(byte *)(inst + 5);
      if (*(char *)(inst + 8) != '\0') {
        secondOperandMask = 8;
      }
      ((int (*)())psnRaReleaseUse)(&releaseOperandReg,&tempTableBank0,&freeListBase);
      *(ushort *)(inst + 3) = releaseOperandReg;
      *(byte *)(inst + 5) = (byte)releaseOperandMask;
      ((int (*)())psnRaReleaseUse)(&secondOperandReg,&tempTableBank0,&freeListBase);
      workMask = 7;
      zeroWordC = 0;
      defOperand = 0;
      defOperandPad0 = 0;
      defOperandPad1 = 0;
      defOperandPad2 = 0;
      defOperandPad3 = 0;
      defOperandPad4 = 0;
      tempTablePad = 0;
      zeroWordA = 0;
      zeroWordB = 0;
      *(ushort *)(inst + 6) = secondOperandReg;
      *(byte *)(inst + 8) = (byte)(-(uint)secondOperandMask >> 0x1f);
      sourceUseFlags = *(byte *)(inst + 5) | *(byte *)((int)inst + 0x15);
      if (sourceUseFlags == 0) {
        workMask = 0;
      }
      srcSelectByte = *(byte *)((int)inst + 0x31);
      workMask = -(uint)(byte)(*(byte *)(inst + 8) | *(byte *)((int)inst + 0x21) |
                           *(byte *)((int)inst + 0x23)) >> 0x1c & 8 | workMask;
      if ((srcSelectByte < 10) && ((1 << ((int)(char)srcSelectByte & 0x3fU) & 0x3b1U) != 0)) {
        workMask = workMask & (sourceUseFlags | 8);
      }
      if (((srcSelectByte == 10) || (srcSelectByte == 2)) && ((workMask & 7) != 0)) {
        workMask = workMask | 8;
      }
      instByte10 = *(byte *)(inst + 0x10);
      if ((instByte10 == 1) && ((workMask & 8) != 0)) {
        workMask = workMask | 7;
      }
      switch(srcSelectByte) {
      case 0:
      case 7:
      case 8:
        ((int (*)())psnAccumulateRgbSelectRead)((uint)*(byte *)((int)inst + 0x2a),workMask,(uint)*(byte *)(inst + 0xc),
                     (uint)*(byte *)((int)inst + 0x3f),&defOperand,&tempTablePad);
        ((int (*)())psnAccumulateRgbSelectRead)((uint)*(byte *)((int)inst + 0x2b),workMask,(uint)*(byte *)(inst + 0xc),
                     (uint)*(byte *)((int)inst + 0x3f),&defOperand,&tempTablePad);
        sourceUseByteB = *(byte *)(inst + 0xb);
        goto code_r0x000c6a30;
      case 1:
      case 4:
      case 5:
        ((int (*)())psnAccumulateRgbSelectRead)((uint)*(byte *)((int)inst + 0x2a),workMask,(uint)*(byte *)(inst + 0xc),
                     (uint)*(byte *)((int)inst + 0x3f),&defOperand,&tempTablePad);
        sourceUseByteB = *(byte *)((int)inst + 0x2b);
code_r0x000c6a30:
        passThroughR8 = &tempTablePad;
        sourceUsage = &defOperand;
        passThroughR6 = (uint *)(uint)*(byte *)((int)inst + 0x3f);
        ((int (*)())psnAccumulateRgbSelectRead)((uint)sourceUseByteB,workMask,(uint)*(byte *)(inst + 0xc),passThroughR6,sourceUsage,passThroughR8);
        instByte10 = *(byte *)(inst + 0x10);
        break;
      case 2:
        sourceUsage = &defOperand;
        passThroughR8 = &tempTablePad;
        ((int (*)())psnAccumulateRgbSelectRead)((uint)*(byte *)((int)inst + 0x2a),workMask,(uint)*(byte *)(inst + 0xc),
                     (uint)*(byte *)((int)inst + 0x3f),sourceUsage,passThroughR8);
        ((int (*)())psnAccumulateRgbSelectRead)((uint)*(byte *)((int)inst + 0x2b),workMask,(uint)*(byte *)(inst + 0xc),
                     (uint)*(byte *)((int)inst + 0x3f),sourceUsage,passThroughR8);
        ((int (*)())psnAccumulateAlphaSelectRead)((uint)*(byte *)((int)inst + 0x39),workMask,(uint)*(byte *)(inst + 0xc),
                     (uint)*(byte *)((int)inst + 0x3f),sourceUsage,passThroughR8);
        passThroughR6 = (uint *)(uint)*(byte *)((int)inst + 0x3f);
        ((int (*)())psnAccumulateAlphaSelectRead)((uint)*(byte *)((int)inst + 0x3a),workMask,(uint)*(byte *)(inst + 0xc),
                     passThroughR6,sourceUsage,passThroughR8);
        instByte10 = *(byte *)(inst + 0x10);
        break;
      case 3:
        sourceUsage = &defOperand;
        passThroughR8 = &tempTablePad;
        ((int (*)())psnAccumulateRgbSelectRead)((uint)*(byte *)((int)inst + 0x2a),workMask & 3,(uint)*(byte *)(inst + 0xc),
                     (uint)*(byte *)((int)inst + 0x3f),sourceUsage,passThroughR8);
        ((int (*)())psnAccumulateRgbSelectRead)((uint)*(byte *)((int)inst + 0x2b),workMask & 3,(uint)*(byte *)(inst + 0xc),
                     (uint)*(byte *)((int)inst + 0x3f),sourceUsage,passThroughR8);
        passThroughR6 = (uint *)(uint)*(byte *)((int)inst + 0x3f);
        ((int (*)())psnAccumulateRgbSelectRead)((uint)*(byte *)(inst + 0xb),workMask & 4,(uint)*(byte *)(inst + 0xc),passThroughR6
                     ,sourceUsage,passThroughR8);
        instByte10 = *(byte *)(inst + 0x10);
        break;
      case 6:
        break;
      case 9:
        sourceUsage = &defOperand;
        passThroughR6 = (uint *)(uint)*(byte *)((int)inst + 0x3f);
        passThroughR8 = &tempTablePad;
        ((int (*)())psnAccumulateRgbSelectRead)((uint)*(byte *)((int)inst + 0x2a),workMask,(uint)*(byte *)(inst + 0xc),
                     passThroughR6,sourceUsage,passThroughR8);
        instByte10 = *(byte *)(inst + 0x10);
      }
      if (instByte10 < 0xc) {
        lowComponentBit = 1 << ((int)(char)instByte10 & 0x3fU);
        if ((lowComponentBit & 0x61) == 0) {
          if ((lowComponentBit & 0xc) == 0) {
            if ((lowComponentBit & 0xf80) != 0) {
              passThroughR6 = (uint *)(uint)*(byte *)((int)inst + 0x3f);
              passThroughR8 = &tempTablePad;
              sourceUsage = &defOperand;
              ((int (*)())psnAccumulateAlphaSelectRead)((uint)*(byte *)((int)inst + 0x39),workMask,(uint)*(byte *)(inst + 0xc)
                           ,passThroughR6,&defOperand,passThroughR8);
            }
            goto code_r0x000c6c50;
          }
          ((int (*)())psnAccumulateAlphaSelectRead)((uint)*(byte *)((int)inst + 0x39),workMask,(uint)*(byte *)(inst + 0xc),
                       (uint)*(byte *)((int)inst + 0x3f),&defOperand,&tempTablePad);
          destMaskByte = *(byte *)((int)inst + 0x3a);
        }
        else {
          ((int (*)())psnAccumulateAlphaSelectRead)((uint)*(byte *)((int)inst + 0x39),workMask,(uint)*(byte *)(inst + 0xc),
                       (uint)*(byte *)((int)inst + 0x3f),&defOperand,&tempTablePad);
          ((int (*)())psnAccumulateAlphaSelectRead)((uint)*(byte *)((int)inst + 0x3a),workMask,(uint)*(byte *)(inst + 0xc),
                       (uint)*(byte *)((int)inst + 0x3f),&defOperand,&tempTablePad);
          destMaskByte = *(byte *)((int)inst + 0x3b);
        }
        passThroughR8 = &tempTablePad;
        passThroughR6 = (uint *)(uint)*(byte *)((int)inst + 0x3f);
        sourceUsage = &defOperand;
        ((int (*)())psnAccumulateAlphaSelectRead)((uint)destMaskByte,workMask,(uint)*(byte *)(inst + 0xc),passThroughR6,&defOperand,passThroughR8);
      }
code_r0x000c6c50:
      destRegBeforeAssign = *(ushort *)((int)inst + 0xe);
      scanIndex = (uint)destRegBeforeAssign;
      defOperand = CONCAT22(destRegBeforeAssign,(*(unsigned short *)((unsigned char *)&(defOperand) + 2)));
      defOperandPad0 = CONCAT22(*(undefined2 *)(inst + 4),(*(unsigned short *)((unsigned char *)&(defOperandPad0) + 2)));
      defOperandPad1 = CONCAT22(*(undefined2 *)((int)inst + 0x12),(*(unsigned short *)((unsigned char *)&(defOperandPad1) + 2)));
      defOperandPad2 = CONCAT22(*(undefined2 *)((int)inst + 0x1a),(*(unsigned short *)((unsigned char *)&(defOperandPad2) + 2)));
      instShort7 = *(ushort *)(inst + 7);
      workMask = (uint)instShort7;
      defOperandPad3 = CONCAT22(instShort7,(*(unsigned short *)((unsigned char *)&(defOperandPad3) + 2)));
      zeroWordA = CONCAT22(*(undefined2 *)(inst + 4),(*(unsigned short *)((unsigned char *)&(zeroWordA) + 2)));
      zeroWordB = CONCAT22(*(undefined2 *)((int)inst + 0x1a),(*(unsigned short *)((unsigned char *)&(zeroWordB) + 2)));
      tempTablePad = CONCAT22(destRegBeforeAssign,(*(unsigned short *)((unsigned char *)&(tempTablePad) + 2)));
      zeroWordC = CONCAT22(instShort7,(*(unsigned short *)((unsigned char *)&(zeroWordC) + 2)));
      defOperandPad4 = CONCAT22(*(undefined2 *)((int)inst + 0x1e),(*(unsigned short *)((unsigned char *)&(defOperandPad4) + 2)));
      ((int (*)())psnRaAssignDefinition)(&defOperand,&tempTableBank0,&freeListBase,passThroughR6,sourceUsage,passThroughR8,workMask,scanIndex);
      *(ushort *)((int)inst + 0xe) = (*(unsigned short *)((unsigned char *)&(defOperand) + 0));
      ((int (*)())psnRaAssignDefinition)(&defOperandPad0,&tempTableBank0,&freeListBase,passThroughR6,sourceUsage,passThroughR8,workMask,scanIndex);
      *(undefined2 *)(inst + 4) = (*(unsigned short *)((unsigned char *)&(defOperandPad0) + 0));
      ((int (*)())psnRaAssignDefinition)(&defOperandPad1,&tempTableBank0,&freeListBase,passThroughR6,sourceUsage,passThroughR8,workMask,scanIndex);
      *(undefined2 *)((int)inst + 0x12) = (*(unsigned short *)((unsigned char *)&(defOperandPad1) + 0));
      ((int (*)())psnRaAssignDefinition)(&defOperandPad2,&tempTableBank0,&freeListBase,passThroughR6,sourceUsage,passThroughR8,workMask,scanIndex);
      *(undefined2 *)((int)inst + 0x1a) = (*(unsigned short *)((unsigned char *)&(defOperandPad2) + 0));
      ((int (*)())psnRaAssignDefinition)(&defOperandPad3,&tempTableBank0,&freeListBase,passThroughR6,sourceUsage,passThroughR8,workMask,scanIndex);
      *(undefined2 *)(inst + 7) = (*(unsigned short *)((unsigned char *)&(defOperandPad3) + 0));
      ((int (*)())psnRaAssignDefinition)(&defOperandPad4,&tempTableBank0,&freeListBase,passThroughR6,sourceUsage,passThroughR8,workMask,scanIndex);
      *(undefined1 *)(inst + 0xd) = 0;
      *(undefined2 *)((int)inst + 0x1e) = (*(unsigned short *)((unsigned char *)&(defOperandPad4) + 0));
      if ((lastVisitedInst != (uint *)0x0) && (*lastVisitedInst - 3 < 2)) {
        loopIndex = 0;
        passThroughR6 = (uint *)(zeroedOperandBlock + 4);
        passThroughR8 = (undefined4 *)(uint)*(ushort *)(inst + 3);
        scanIndex = (uint)*(ushort *)(inst + 6);
        sourceUsage = &zeroedOperandWord1;
        workMask = -(uint)*(byte *)(inst + 8) >> 0x1c & 8 | (uint)*(byte *)(inst + 5);
        do {
          if ((passThroughR8 == (undefined4 *)(uint)*(ushort *)(loopIndex + (int)passThroughR6)) &&
             ((workMask & *(ushort *)((int)zeroedOperandBlock + loopIndex)) != 0)) {
            *(undefined1 *)(inst + 0xd) = 1;
          }
          if ((scanIndex == *(ushort *)(loopIndex + (int)sourceUsage)) &&
             ((workMask & *(ushort *)((int)zeroedOperandBlock + loopIndex + 4)) != 0)) {
            *(undefined1 *)(inst + 0xd) = 1;
          }
          notLastSlot = loopIndex != 2;
          loopIndex = loopIndex + 2;
        } while (notLastSlot);
      }
      (*(unsigned short *)((unsigned char *)&(zeroedOperandWord0) + 0)) = *(undefined2 *)((int)inst + 0xe);
      (*(unsigned short *)((unsigned char *)&(zeroedOperandWord0) + 2)) = *(undefined2 *)(inst + 4);
      (*(unsigned short *)((unsigned char *)&(zeroedOperandWord1) + 0)) = *(undefined2 *)((int)inst + 0x1a);
      workMask = (uint)*(ushort *)(inst + 7);
      zeroedOperandBlock[0] = (*(unsigned short *)((unsigned char *)&(tempTablePad) + 2));
      zeroedOperandBlock[1] = (*(unsigned short *)((unsigned char *)&(zeroWordA) + 2));
      (*(unsigned short *)((unsigned char *)&(zeroedOperandWord1) + 2)) = *(ushort *)(inst + 7);
      zeroedOperandBlock[2] = (*(unsigned short *)((unsigned char *)&(zeroWordB) + 2));
      zeroedOperandBlock[3] = (*(unsigned short *)((unsigned char *)&(zeroWordC) + 2));
LAB_000c6e10:
      loopIndex2 = loopIndex2 + 1;
      lastVisitedInst = inst;
      inst = inst + -0x12;
    } while (psnProgramWord8 != loopIndex2);
  }
  ((int (*)())psnAnalyzeProgram)(psnProgram);
  return;
}

/* scCallbackAlloc @ 0xc6e40 (12 bytes) - issue #64 live-repro: a genuine, separate function Ghidra's
 * initial analysis never split out (no standard prologue - it's a 3-instruction tail-call right
 * after the preceding function's blr, only reachable via the PC-relative function-pointer table
 * scCreateForContext builds; never found by any direct bl/b xref). Confirmed live: scCreate calls
 * *(psnState+0x30) - previously transcribed as the raw literal (unsigned char*)0x000c6e40, which
 * pointed at these bytes as DATA instead of as this function's own real code - as
 * (arg, 0x44, useSecondBank), landing here with psnProgram=0x44 after the ABI drops the 3rd arg; this
 * confirmed-real code is or r3,r4,r4 / li r4,1 / b 0x1a3700 (the _calloc picsymbolstub), i.e. this
 * is the allocator half of an alloc/free callback pair with the very next function, scCallbackFree
 * (_free(psnProgram)). Otherwise unreachable without this fix (issue #64). */
int scCallbackAlloc(psnState, psnProgram)
  undefined4 psnState;
  size_t psnProgram;
{
  return _calloc(psnProgram,1);
}

/* scCallbackFree @ 0xc6e50 (40 bytes) */
int scCallbackFree(unusedArgR3, param_2)
  undefined4 unusedArgR3;
  undefined4 param_2;
{
  _free(param_2);
  return 0;
}

/* scCallbackGetFlagZero @ 0xc6e80 (16 bytes) */
int scCallbackGetFlagZero(unusedArgR3, unusedArgR4, param_3)
  undefined4 unusedArgR3;
  undefined4 unusedArgR4;
  undefined4 *param_3;
{
  *param_3 = 0;
  return 0;
}

/* scCallbackAppendFormatted @ 0xc6e90 (88 bytes) */
int scCallbackAppendFormatted(unusedArgR3, prefix, format, formatArg1, formatArg2, formatArg3, formatArg4, formatArg5)
  undefined4 unusedArgR3;
  undefined4 prefix;
  undefined4 format;
  undefined4 formatArg1;
  undefined4 formatArg2;
  undefined4 formatArg3;
  undefined4 formatArg4;
  undefined4 formatArg5;
{
  int length;
  undefined1 textBuffer [264];
  
  _strcpy(textBuffer,prefix);
  length = _strlen(textBuffer);
  return printf_LDBLStub_1a3428(textBuffer + length,0x100 - length,format,formatArg1,formatArg2,formatArg3,formatArg4,formatArg5);
}

/* scCallbackFopen @ 0xc6ef0 (88 bytes) */
int scCallbackFopen(unusedArgR3, path, mode)
  undefined4 unusedArgR3;
  undefined4 path;
  int mode;
{
  undefined4 file;
  
  if (mode == 2) {
    file = _fopen(path,"w");
    return file;
  }
  if (mode != 3) {
    if (mode == 1) {
      file = _fopen(path,"r");
      return file;
    }
    return 0;
  }
  file = _fopen(path,"r+");
  return file;
}

/* scCallbackFclose @ 0xc6f60 (44 bytes) */
int scCallbackFclose(unusedArgR3, file)
  undefined4 unusedArgR3;
  undefined4 file;
{
  int closeResult;
  
  closeResult = _fclose(file);
  return closeResult == 0;
}

/* scCallbackFwrite @ 0xc6f90 (40 bytes) */
int scCallbackFwrite(unusedArgR3, file, buffer, byteCount)
  undefined4 unusedArgR3;
  int file;
  int buffer;
  undefined4 byteCount;
{
  undefined4 written;
  
  if ((buffer != 0) && (file != 0)) {
    written = _fwrite(buffer,1,byteCount,file);
    return written;
  }
  return 0;
}

/* scCallbackFread @ 0xc6fc0 (40 bytes) */
int scCallbackFread(unusedArgR3, file, buffer, byteCount)
  undefined4 unusedArgR3;
  int file;
  int buffer;
  undefined4 byteCount;
{
  undefined4 readCount;
  
  if ((buffer != 0) && (file != 0)) {
    readCount = _fread(buffer,1,byteCount,file);
    return readCount;
  }
  return 0;
}

/* scCreateForContext @ 0xc6ff0 (464 bytes) */
int scCreateForContext(ctx, useDeviceId)
  int ctx;
  int useDeviceId;
{
  undefined *ctxPtr23d4;
  undefined4 compilerHandle;
  undefined4 createInfoWord0;
  undefined4 createInfoVersion;
  undefined4 createInfoWord2;
  /* issue #64 live-repro: scCreate (called below via &chipConfigKind) reads its first argument at
   * byte offsets up to +0x4c (*(ctx+0x30)/+0x34/+0x38/+0x40/+0x44/+0x48/+0x4c), i.e. it expects
   * chipConfigKind through freadCallback (and optionsVersion/compilerHandleOut/allocCallback above them) to be ONE contiguous
   * 0x54-byte buffer - confirmed directly by this function's own "_memset(&chipConfigKind,0,0x54)" a few
   * lines down, not a guess. Left as separate scalars (same defect class as auStack_c148 and
   * local_194 in _gldChoosePixelFormat, both fixed earlier this session), the -O0 rebuild does not
   * place them contiguously, so scCreate's offset reads miss into whatever real stack slot
   * happens to be there instead - confirmed live: corrupts far enough to zero this function's own
   * ctx, crashing on the *(ctx+0x186c)=compilerHandle store a few lines below. Merged into one
   * 0x54-byte buffer (offsets confirmed per each name's own hex value, e.g. 0x7c-0x30=0x4c). */
  unsigned char local_7c_buf[0x54];
#define optionsVersion (*(undefined4 *)(local_7c_buf + 0x28))
#define compilerHandleOut (*(undefined4 **)(local_7c_buf + 0x2c))
#define allocCallback (*(undefined **)(local_7c_buf + 0x30))
#define freeCallback (*(code **)(local_7c_buf + 0x34))
#define getFlagCallback (*(code **)(local_7c_buf + 0x38))
#define appendFormattedCallback (*(code **)(local_7c_buf + 0x3c))
#define fopenCallback (*(code **)(local_7c_buf + 0x40))
#define fcloseCallback (*(code **)(local_7c_buf + 0x44))
#define fwriteCallback (*(code **)(local_7c_buf + 0x48))
#define freadCallback (*(code **)(local_7c_buf + 0x4c))
#define chipConfigKind (*(undefined4 *)(local_7c_buf + 0x00))
#define chipRevision (*(undefined4 *)(local_7c_buf + 0x04))
  
  _memset(local_7c_buf,0,0x54);
  chipRevision = *(undefined4 *)(ctx + 0x23d8);
  createInfoWord2 = 0;
  createInfoWord0 = 0;
  if (useDeviceId == 0) {
    chipConfigKind = 0x2c;
  }
  else {
    ctxPtr23d4 = *(undefined **)(ctx + 0x23d4);
    if (((ctxPtr23d4 + -0x7240 < ((unsigned char *)0x10)) || (ctxPtr23d4 + -0x7100 < ((unsigned char *)0x10))) ||
       (((((ctxPtr23d4 != (undefined *)0x71c0 &&
           ((((ctxPtr23d4 != (undefined *)0x71c2 && (ctxPtr23d4 != (undefined *)0x71c6)) &&
             (ctxPtr23d4 != (undefined *)0x71ce)) &&
            ((ctxPtr23d4 != (undefined *)0x71d2 && (ctxPtr23d4 != (undefined *)0x71de)))))) &&
          (ctxPtr23d4 != (undefined *)0x71c4)) &&
         (((ctxPtr23d4 != (undefined *)0x71c5 && (ctxPtr23d4 != (undefined *)0x7140)) &&
          ((ctxPtr23d4 != (undefined *)0x7142 &&
           (((ctxPtr23d4 != ((unsigned char *)0x00007146) && (ctxPtr23d4 != ((unsigned char *)0x0000714e))) &&
            (ctxPtr23d4 != (undefined *)0x7152)))))))) &&
        (((ctxPtr23d4 != (undefined *)0x715e && (ctxPtr23d4 != ((unsigned char *)0x00007144))) &&
         ((ctxPtr23d4 != ((unsigned char *)0x00007145) && ((ctxPtr23d4 != ((unsigned char *)0x00007148) && (ctxPtr23d4 != ((unsigned char *)0x00007149))))))))))
       ) {
      chipConfigKind = 0x3c;
    }
    else {
      chipConfigKind = 0x3e;
    }
  }
  allocCallback = (undefined *)scCallbackAlloc;
  freeCallback = scCallbackFree;
  optionsVersion = 2;
  getFlagCallback = scCallbackGetFlagZero;
  appendFormattedCallback = scCallbackAppendFormatted;
  createInfoVersion = 0x7b;
  fopenCallback = scCallbackFopen;
  fcloseCallback = scCallbackFclose;
  fwriteCallback = scCallbackFwrite;
  freadCallback = scCallbackFread;
  compilerHandleOut = (undefined4 *)(ctx + 0x186c);
  compilerHandle = scCreate(&chipConfigKind,&createInfoWord0,0x10001);
  *(undefined4 *)(ctx + 0x186c) = compilerHandle;
  *(undefined4 *)(ctx + 0x1870) = createInfoVersion;
  return;
}
#undef optionsVersion
#undef compilerHandleOut
#undef allocCallback
#undef freeCallback
#undef getFlagCallback
#undef appendFormattedCallback
#undef fopenCallback
#undef fcloseCallback
#undef fwriteCallback
#undef freadCallback
#undef chipConfigKind
#undef chipRevision

/* ilFreeRecordList @ 0xc71e0 (76 bytes) */
int ilFreeRecordList(node)
  int node;
{
  if (node != 0) {
    ((int (*)())ilFreeRecordList)(*(undefined4 *)(node + 0x24));
    _free(node);
    return;
  }
  return;
}

/* ilSelectorOneToThreeOrZero @ 0xc7240 (44 bytes) */
int ilSelectorOneToThreeOrZero(selector)
  int selector;
{
  undefined1 slotCode;
  
  slotCode = 2;
  if ((selector != 2) && (slotCode = 3, selector != 3)) {
    slotCode = selector == 1;
  }
  return slotCode;
}

/* ilRecordInputSemantic @ 0xc7270 (24 bytes) */
int ilRecordInputSemantic(programRecord, inputIndex, semanticValue)
  int programRecord;
  int inputIndex;
  undefined4 semanticValue;
{
  int iVar1;
  
  iVar1 = inputIndex * 4 + programRecord;
  *(undefined4 *)(iVar1 + 0x2278) = 1;
  *(undefined4 *)(iVar1 + 0x2238) = semanticValue;
  return;
}

/* ilRecordDefinedConstantPrimary @ 0xc7290 (88 bytes) */
int ilRecordDefinedConstantPrimary(programRecord, constantIndex, values)
  int programRecord;
  uint constantIndex;
  undefined4 *values;
{
  undefined4 valuesWordc;
  int bitWordIndex;
  int constantSlot;
  uint definedBits;
  int bitWordPtr;
  
  bitWordIndex = ((int)constantIndex >> 5) + (uint)((int)constantIndex < 0 && (constantIndex & 0x1f) != 0);
  constantSlot = constantIndex * 0x10 + programRecord;
  bitWordPtr = bitWordIndex * 4 + programRecord;
  *(undefined4 *)(constantSlot + 0x1a8) = *values;
  definedBits = *(uint *)(bitWordPtr + 0x188);
  *(undefined4 *)(constantSlot + 0x1ac) = values[1];
  *(undefined4 *)(constantSlot + 0x1b0) = values[2];
  valuesWordc = values[3];
  *(uint *)(bitWordPtr + 0x188) = 1 << (constantIndex + bitWordIndex * -0x20 & 0x3f) | definedBits;
  *(undefined4 *)(constantSlot + 0x1b4) = valuesWordc;
  return;
}

/* ilRecordDefinedConstantSecondary @ 0xc72f0 (88 bytes) */
int ilRecordDefinedConstantSecondary(programRecord, constantIndex, values)
  int programRecord;
  uint constantIndex;
  undefined4 *values;
{
  int bitWordIndex;
  undefined4 valuesWordc;
  uint definedBits;
  int bitWordPtr;
  int constantSlot;
  
  bitWordIndex = ((int)constantIndex >> 5) + (uint)((int)constantIndex < 0 && (constantIndex & 0x1f) != 0);
  constantSlot = constantIndex * 0x10 + programRecord;
  *(undefined4 *)(((unsigned char *)0x000011c8) + constantSlot) = *values;
  bitWordPtr = bitWordIndex * 4 + programRecord;
  definedBits = *(uint *)(((unsigned char *)0x000011a8) + bitWordPtr);
  *(undefined4 *)((int)((unsigned char *)0x000011cc) + constantSlot) = values[1];
  *(undefined4 *)(((unsigned char *)0x000011d0U) + constantSlot) = values[2];
  valuesWordc = values[3];
  *(uint *)(((unsigned char *)0x000011a8) + bitWordPtr) = 1 << (constantIndex + bitWordIndex * -0x20 & 0x3f) | definedBits;
  *(undefined4 *)(((unsigned char *)0x000011d4) + constantSlot) = valuesWordc;
  return;
}

/* ilAllocLowestFreeBit8 @ 0xc7350 (72 bytes) */
int ilAllocLowestFreeBit8(programRecord, passThroughR4, passThroughR5, passThroughR6, passThroughR7, passThroughR8, passThroughR9, passThroughR10)
  int programRecord;
  undefined4 passThroughR4;
  undefined4 passThroughR5;
  undefined4 passThroughR6;
  undefined4 passThroughR7;
  undefined4 passThroughR8;
  undefined4 passThroughR9;
  undefined4 passThroughR10;
{
  uint uVar1;
  uint loopIndex;
  int remaining;
  
  loopIndex = 0;
  remaining = 8;
  do {
    uVar1 = 1 << (loopIndex & 0x3f);
    if ((uVar1 & *(uint *)(programRecord + 8)) == 0) {
      *(uint *)(programRecord + 8) = uVar1 | *(uint *)(programRecord + 8);
      return loopIndex;
    }
    loopIndex = loopIndex + 1;
    remaining = remaining + -1;
  } while (remaining != 0);
  return 0x11;
}

/* ilNextCounterValue @ 0xc73a0 (20 bytes) */
int ilNextCounterValue(programRecord)
  int programRecord;
{
  *(int *)(programRecord + 0x50) = *(int *)(programRecord + 0x50) + 1;
  return;
}

