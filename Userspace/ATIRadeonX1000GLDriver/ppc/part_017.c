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
  bool bVar1;
  char destEnableY;
  char destEnableZ;
  char destEnableW;
  bool bVar5;
  int remainingLater;
  char *laterFlagCursor;
  uint instCount;
  int laterInstPtr;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  int instEnd;
  byte bVar15;
  undefined4 *puVar14;
  uint instCountAtEntry;
  undefined4 *puVar17;
  int iVar18;
  undefined4 addInstWord48;
  int *laterDestSlot;
  undefined4 uVar21;
  int shaderWord20;
  undefined4 addInstWord50;
  undefined4 addInstWord38;
  undefined4 addInstWord2cMapped;
  int iVar26;
  undefined4 addInstWord4c_2;
  undefined4 addInstWord34;
  undefined4 addInstWord30_2;
  undefined4 addInstWord54;
  int symbolTable;
  uint sweepStep;
  uint scanIndex;
  int iVar34;
  int instEndOffset;
  uint uVar36;
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
      uVar36 = instCountAtEntry - sweepStep;
      instEnd = instEndOffset + laterInstPtr;
      destEnableY = *(char *)(instEnd + -0x61);
      destEnableZ = *(char *)(instEnd + -0x5d);
      destEnableW = *(char *)(instEnd + -0x59);
      bVar1 = *(char *)(instEnd + -0x65) == '\0';
      if ((((bVar1) && (destEnableY == '\0')) && (destEnableZ == '\0')) && (destEnableW == '\0')) {
LAB_000ba610:
        shiftCursorOffset = instEndOffset;
        if (uVar36 < instCount) {
          do {
            uVar36 = uVar36 + 1;
            shiftSrc = shiftCursorOffset + *(int *)(shader + 0x18);
            _memcpy(shiftSrc + -0x74,shiftSrc,0x74);
            instCount = *(uint *)(shader + 0x14);
            shiftCursorOffset = shiftCursorOffset + 0x74;
          } while (uVar36 < instCount);
        }
        instCount = instCount - 1;
        *(uint *)(shader + 0x14) = instCount;
      }
      else {
        iVar18 = *(int *)(instEnd + -0x70);
        if (iVar18 == 1) {
          if (uVar36 < instCount) {
            remaining = instCount - uVar36;
            laterDestSlot = (int *)(instEnd + 4);
            bVar12 = 0;
            bVar15 = 0;
            bVar11 = 0;
            bVar10 = 0;
            do {
              if ((*laterDestSlot == 1) && (laterDestSlot[1] == *(int *)(instEnd + -0x6c))) {
                bVar15 = bVar15 | *(byte *)((int)laterDestSlot + 0xb);
                bVar12 = bVar12 | *(byte *)((int)laterDestSlot + 0xf);
                bVar11 = bVar11 | *(byte *)((int)laterDestSlot + 0x13);
                bVar10 = bVar10 | *(byte *)((int)laterDestSlot + 0x17);
              }
              laterDestSlot = laterDestSlot + 0x1d;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          else {
            bVar15 = 0;
            bVar12 = 0;
            bVar11 = 0;
            bVar10 = 0;
          }
          if ((((bVar1) || (bVar15 != 0)) && ((destEnableY == '\0' || (bVar12 != 0)))) &&
             (((destEnableZ == '\0' || (bVar11 != 0)) && ((destEnableW == '\0' || (bVar10 != 0))))))
          goto LAB_000ba610;
        }
        else {
          if (*(int *)(instEnd + -0x74) == 0x87a2) {
            if (uVar36 < instCount) {
              remaining = instCount - uVar36;
              laterFlagCursor = (char *)(instEnd + 0x38);
              bVar5 = true;
              bVar12 = 0;
              bVar11 = 0;
              bVar10 = 0;
              bVar15 = 0;
              do {
                if (((*laterFlagCursor != '\0') || (laterFlagCursor[0x1c] != '\0')) || (laterFlagCursor[0x38] != '\0')) {
                  bVar5 = false;
                }
                if ((*(int *)(laterFlagCursor + -0x34) == 2) &&
                   (*(int *)(laterFlagCursor + -0x30) == *(int *)(instEnd + -0x6c))) {
                  bVar12 = bVar12 | laterFlagCursor[-0x29];
                  bVar11 = bVar11 | laterFlagCursor[-0x25];
                  bVar10 = bVar10 | laterFlagCursor[-0x21];
                  bVar15 = bVar15 | laterFlagCursor[-0x1d];
                }
                laterFlagCursor = laterFlagCursor + 0x74;
                remaining = remaining + -1;
              } while (remaining != 0);
            }
            else {
              bVar5 = true;
              bVar12 = 0;
              bVar11 = 0;
              bVar10 = 0;
              bVar15 = 0;
            }
            if (((((((bVar1) || (bVar12 != 0)) && ((destEnableY == '\0' || (bVar11 != 0)))) &&
                  ((destEnableZ == '\0' || (bVar10 != 0)))) && ((destEnableW == '\0' || (bVar15 != 0)))) &&
                (bVar5)) || (instCount <= uVar36)) goto LAB_000ba610;
            remaining = instCount - uVar36;
            laterFlagCursor = (char *)(instEnd + 0x38);
            bVar5 = true;
            do {
              if (((*laterFlagCursor != '\0') || (laterFlagCursor[0x1c] != '\0')) || (laterFlagCursor[0x38] != '\0')) {
                bVar5 = false;
              }
              laterFlagCursor = laterFlagCursor + 0x74;
              remaining = remaining + -1;
            } while (remaining != 0);
          }
          else {
            if (*(char *)(shader + 0x7b) == '\0') {
              if (iVar18 == 2) {
                iVar18 = *(int *)(instEnd + -0x6c);
                shaderWord20 = *(int *)(shader + 0x20);
                goto LAB_000ba1a0;
              }
            }
            else if (iVar18 == 2) {
              iVar18 = *(int *)(instEnd + -0x6c);
              shaderWord20 = *(int *)(shader + 0x20);
              if (*(int *)(iVar18 * 0x54 + shaderWord20 + 0x28) == 0x87c4) goto LAB_000ba664;
LAB_000ba1a0:
              if (*(int *)(iVar18 * 0x54 + shaderWord20 + 0x24) == 0x87c0) goto LAB_000ba664;
            }
            if (uVar36 < instCount) {
              bVar10 = 0;
              bVar11 = 0;
              bVar12 = 0;
              bVar15 = 0;
              bVar5 = true;
              iVar18 = instEndOffset;
              scanIndex = uVar36;
              while( true ) {
                laterInstPtr = iVar18 + laterInstPtr;
                if ((((*(int *)(laterInstPtr + 0x20) == 2) &&
                     (shaderWord20 = *(int *)(instEnd + -0x6c), *(int *)(laterInstPtr + 0x24) == shaderWord20)) ||
                    ((*(int *)(laterInstPtr + 0x3c) == 2 &&
                     (shaderWord20 = *(int *)(instEnd + -0x6c), *(int *)(laterInstPtr + 0x40) == shaderWord20)))) ||
                   ((*(int *)(laterInstPtr + 0x58) == 2 &&
                    (shaderWord20 = *(int *)(instEnd + -0x6c), *(int *)(laterInstPtr + 0x5c) == shaderWord20)))) {
                  extvsInstReadsTempComponents(symbolTable,laterInstPtr,shaderWord20,&readsX,&readsY,&readsZ,readsW);
                  if (((((bVar1) || ((readsX == '\0' || (bVar15 != 0)))) &&
                       ((destEnableY == '\0' || ((readsY == '\0' || (bVar12 != 0)))))) &&
                      ((destEnableZ == '\0' || ((readsZ == '\0' || (bVar11 != 0)))))) &&
                     ((destEnableW == '\0' || ((readsW[0] == '\0' || (bVar10 != 0)))))) {
                    instCount = *(uint *)(shader + 0x14);
                  }
                  else {
                    instCount = *(uint *)(shader + 0x14);
                    bVar5 = false;
                  }
                }
                if ((*(int *)(laterInstPtr + 4) == 2) && (*(int *)(laterInstPtr + 8) == *(int *)(instEnd + -0x6c)))
                {
                  bVar10 = bVar10 | *(byte *)(laterInstPtr + 0x1b);
                  bVar15 = bVar15 | *(byte *)(laterInstPtr + 0xf);
                  bVar12 = bVar12 | *(byte *)(laterInstPtr + 0x13);
                  bVar11 = bVar11 | *(byte *)(laterInstPtr + 0x17);
                }
                scanIndex = scanIndex + 1;
                iVar18 = iVar18 + 0x74;
                if (instCount <= scanIndex) break;
                laterInstPtr = *(int *)(shader + 0x18);
              }
            }
            else {
              bVar5 = true;
              bVar15 = 0;
              bVar12 = 0;
              bVar11 = 0;
              bVar10 = 0;
            }
            if (((((bVar1) || (bVar15 != 0)) && ((destEnableY == '\0' || (bVar12 != 0)))) &&
                ((((destEnableZ == '\0' || (bVar11 != 0)) && ((destEnableW == '\0' || (bVar10 != 0)))) &&
                 (bVar5)))) || (instCount <= uVar36)) goto LAB_000ba610;
            bVar5 = true;
            bVar11 = 0;
            bVar12 = 0;
            bVar15 = 0;
            bVar10 = 0;
            laterOffset = instEndOffset;
            scanIndex = uVar36;
            do {
              iVar18 = laterOffset + *(int *)(shader + 0x18);
              if ((((*(int *)(iVar18 + 0x20) == 2) &&
                   (shaderWord20 = *(int *)(instEnd + -0x6c), *(int *)(iVar18 + 0x24) == shaderWord20)) ||
                  ((*(int *)(iVar18 + 0x3c) == 2 &&
                   (shaderWord20 = *(int *)(instEnd + -0x6c), *(int *)(iVar18 + 0x40) == shaderWord20)))) ||
                 ((*(int *)(iVar18 + 0x58) == 2 &&
                  (shaderWord20 = *(int *)(instEnd + -0x6c), *(int *)(iVar18 + 0x5c) == shaderWord20)))) {
                extvsInstReadsTempComponents(symbolTable,iVar18,shaderWord20,&readsX,&readsY,&readsZ,readsW);
                if ((((bVar1) || ((readsX == '\0' || (bVar11 != 0)))) &&
                    (((destEnableY == '\0' || ((readsY == '\0' || (bVar12 != 0)))) &&
                     ((destEnableZ == '\0' || ((readsZ == '\0' || (bVar15 != 0)))))))) &&
                   ((destEnableW == '\0' || ((readsW[0] == '\0' || (bVar10 != 0)))))) {
                  instCount = *(uint *)(shader + 0x14);
                }
                else {
                  instCount = *(uint *)(shader + 0x14);
                  bVar5 = false;
                }
              }
              if ((*(int *)(iVar18 + 4) == 2) && (*(int *)(iVar18 + 8) == *(int *)(instEnd + -0x6c)))
              {
                bVar10 = bVar10 | *(byte *)(iVar18 + 0x1b);
                bVar11 = bVar11 | *(byte *)(iVar18 + 0xf);
                bVar12 = bVar12 | *(byte *)(iVar18 + 0x13);
                bVar15 = bVar15 | *(byte *)(iVar18 + 0x17);
              }
              scanIndex = scanIndex + 1;
              laterOffset = laterOffset + 0x74;
            } while (scanIndex < instCount);
          }
          if (bVar5) goto LAB_000ba610;
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
         ((mulInst[6] != 0 && (uVar36 = mulSearchIndex + 1, addSearchIndex = uVar36, uVar36 < instCount)))) {
        do {
          addInstOffset = addSearchIndex * 0x74;
          addInst = (undefined4 *)(instArray + addInstOffset);
          if (*(int *)(instArray + addInstOffset) == 0x8787) {
            iVar18 = addInst[8];
            if ((iVar18 != 2) || (shaderWord20 = mulInst[2], addInst[9] != shaderWord20)) {
              if ((addInst[0xf] != 2) || (shaderWord20 = mulInst[2], addInst[0x10] != shaderWord20))
              goto LAB_000ba7ec;
              iVar34 = 2;
              if (iVar18 == 2) goto LAB_000ba7dc;
            }
            else {
              iVar34 = addInst[0xf];
              if (iVar34 == 2) {
LAB_000ba7dc:
                if (addInst[9] == addInst[0x10]) goto LAB_000ba7ec;
              }
            }
            bVar1 = true;
            if (uVar36 < addSearchIndex) {
              remainingLater = addSearchIndex - uVar36;
              laterSrcSlot = (int *)(instArray + uVar36 * 0x74 + 0x20);
              do {
                if ((((*laterSrcSlot == 2) && (laterSrcSlot[1] == shaderWord20)) ||
                    ((laterSrcSlot[7] == 2 && (laterSrcSlot[8] == shaderWord20)))) ||
                   ((((laterSrcSlot[0xe] == 2 && (laterSrcSlot[0xf] == shaderWord20)) ||
                     ((iVar26 = laterSrcSlot[-7], iVar26 == 2 && (laterSrcSlot[-6] == shaderWord20)))) ||
                    (((iVar26 == mulInst[8] && (laterSrcSlot[-6] == mulInst[9])) ||
                     ((iVar26 == mulInst[0xf] && (laterSrcSlot[-6] == mulInst[0x10])))))))) {
                  bVar1 = false;
                }
                laterSrcSlot = laterSrcSlot + 0x1d;
                remainingLater = remainingLater + -1;
              } while (remainingLater != 0);
              if (bVar1) goto LAB_000ba8a8;
LAB_000ba754:
              bVar1 = true;
              remainingLater = addSearchIndex - uVar36;
              laterSrcSlot = (int *)(uVar36 * 0x74 + instArray + 0x20);
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
                      ((iVar26 = laterSrcSlot[-7], iVar18 == iVar26 && (laterSrcSlot[-6] == addInst[9]))))))))
                   || (((iVar26 == iVar34 && (laterSrcSlot[-6] == addInst[0x10])) ||
                       ((iVar26 == addInst[1] && (laterSrcSlot[-6] == addInst[2])))))) {
                  bVar1 = false;
                }
                laterSrcSlot = laterSrcSlot + 0x1d;
                remainingLater = remainingLater + -1;
              } while (remainingLater != 0);
              if (bVar1) {
LAB_000bc018:
                bVar1 = true;
                afterAddIndex = addSearchIndex + 1;
                if (afterAddIndex < instCount) {
                  remainingLater = instCount - afterAddIndex;
                  laterSrcSlot = (int *)(instArray + afterAddIndex * 0x74 + 0x20);
                  do {
                    if ((((*laterSrcSlot == 2) && (laterSrcSlot[1] == shaderWord20)) ||
                        ((laterSrcSlot[7] == 2 && (laterSrcSlot[8] == shaderWord20)))) ||
                       ((laterSrcSlot[0xe] == 2 && (laterSrcSlot[0xf] == shaderWord20)))) {
                      bVar1 = false;
                    }
                    laterSrcSlot = laterSrcSlot + 0x1d;
                    remainingLater = remainingLater + -1;
                  } while (remainingLater != 0);
                  if (!bVar1) goto LAB_000bd6dc;
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
                  mulInst[0x16] = iVar34;
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
                  mulInst[0x16] = iVar18;
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
                puVar14 = addInst + 0x11;
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
                *puVar14 = addInstWord28Mapped;
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
                puVar17 = mulInst + 10;
                switch(addInstWord28Mapped) {
                case 0x87d5:
                  addInstWord28Mapped = *puVar17;
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
                  addInstWord28Mapped = *puVar17;
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
                  addInstWord2cMapped = *puVar17;
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
                  addInstWord2cMapped = *puVar17;
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
                  addInstWord30Mapped = *puVar17;
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
                  addInstWord30Mapped = *puVar17;
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
                  addInstWord34Mapped = *puVar17;
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
                  addInstWord34Mapped = *puVar17;
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
                uVar21 = *puVar14;
                addInst[0xd] = addInstWord34Mapped;
                puVar17 = mulInst + 0x11;
                switch(uVar21) {
                case 0x87d5:
                  uVar21 = *puVar17;
                  break;
                case 0x87d6:
                  uVar21 = mulInst[0x12];
                  break;
                case 0x87d7:
                  uVar21 = mulInst[0x13];
                  break;
                case 0x87d8:
                  uVar21 = mulInst[0x14];
                  break;
                case 0x87d9:
                  uVar21 = *puVar17;
                  switch(uVar21) {
                  case 0x87d5:
switchD_000bcea8_caseD_87d5:
                    uVar21 = 0x87d9;
                    break;
                  case 0x87d6:
switchD_000bcea8_caseD_87d6:
                    uVar21 = 0x87da;
                    break;
                  case 0x87d7:
switchD_000bcea8_caseD_87d7:
                    uVar21 = 0x87db;
                    break;
                  case 0x87d8:
switchD_000bcea8_caseD_87d8:
                    uVar21 = 0x87dc;
                    break;
                  case 0x87d9:
switchD_000bcea8_caseD_87d9:
                    uVar21 = 0x87d5;
                    break;
                  case 0x87da:
switchD_000bcea8_caseD_87da:
                    uVar21 = 0x87d6;
                    break;
                  case 0x87db:
switchD_000bcea8_caseD_87db:
                    uVar21 = 0x87d7;
                    break;
                  case 0x87dc:
switchD_000bcea8_caseD_87dc:
                    uVar21 = 0x87d8;
                    break;
                  case 0x87de:
switchD_000bcea8_caseD_87de:
                    uVar21 = 0x87df;
                    break;
                  case 0x87df:
switchD_000bcea8_caseD_87df:
                    uVar21 = 0x87de;
                  }
                  break;
                case 0x87da:
                  uVar21 = mulInst[0x12];
                  switch(uVar21) {
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
                  uVar21 = mulInst[0x13];
                  switch(uVar21) {
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
                  uVar21 = mulInst[0x14];
                  switch(uVar21) {
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
                *puVar14 = uVar21;
                switch(addInstWord48Mapped) {
                case 0x87d5:
                  addInstWord48Mapped = *puVar17;
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
                  addInstWord48Mapped = *puVar17;
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
                  addInstWord4cMapped = *puVar17;
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
                  addInstWord4cMapped = *puVar17;
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
                  addInstWord50Mapped = *puVar17;
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
                  addInstWord50Mapped = *puVar17;
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
              bVar1 = true;
            }
            else {
LAB_000ba8a8:
              bVar1 = true;
              afterAddIndex = addSearchIndex + 1;
              if (afterAddIndex < instCount) {
                remainingLater = instCount - afterAddIndex;
                laterSrcSlot = (int *)(instArray + afterAddIndex * 0x74 + 0x20);
                do {
                  if (((*laterSrcSlot == 2) && (laterSrcSlot[1] == shaderWord20)) ||
                     (((laterSrcSlot[7] == 2 && (laterSrcSlot[8] == shaderWord20)) ||
                      ((laterSrcSlot[0xe] == 2 && (laterSrcSlot[0xf] == shaderWord20)))))) {
                    bVar1 = false;
                  }
                  laterSrcSlot = laterSrcSlot + 0x1d;
                  remainingLater = remainingLater + -1;
                } while (remainingLater != 0);
                if (!bVar1) {
                  if (uVar36 < addSearchIndex) goto LAB_000ba754;
                  goto LAB_000bc018;
                }
              }
              *addInst = 0x8788;
              if (addInst[9] == shaderWord20) {
                addInstWord28Mapped = addInst[10];
                addInst[0x16] = iVar34;
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
                addInst[0x16] = iVar18;
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
              puVar14 = addInst + 0x11;
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
              *puVar14 = addInstWord28Mapped;
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
              puVar17 = mulInst + 10;
              addInst[9] = mulInst[9];
              addInstWord28Mapped = addInst[10];
              switch(addInstWord28Mapped) {
              case 0x87d5:
                addInstWord28Mapped = *puVar17;
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
                addInstWord28Mapped = *puVar17;
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
                addInstWord2cMapped = *puVar17;
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
                addInstWord2cMapped = *puVar17;
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
                addInstWord30Mapped = *puVar17;
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
                addInstWord30Mapped = *puVar17;
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
                addInstWord34Mapped = *puVar17;
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
                addInstWord34Mapped = *puVar17;
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
              puVar17 = mulInst + 0x11;
              addInst[0x10] = mulInst[0x10];
              uVar21 = *puVar14;
              switch(uVar21) {
              case 0x87d5:
                uVar21 = *puVar17;
                break;
              case 0x87d6:
                uVar21 = mulInst[0x12];
                break;
              case 0x87d7:
                uVar21 = mulInst[0x13];
                break;
              case 0x87d8:
                uVar21 = mulInst[0x14];
                break;
              case 0x87d9:
                uVar21 = *puVar17;
                switch(uVar21) {
                case 0x87d5:
switchD_000bb718_caseD_87d5:
                  uVar21 = 0x87d9;
                  break;
                case 0x87d6:
switchD_000bb718_caseD_87d6:
                  uVar21 = 0x87da;
                  break;
                case 0x87d7:
switchD_000bb718_caseD_87d7:
                  uVar21 = 0x87db;
                  break;
                case 0x87d8:
switchD_000bb718_caseD_87d8:
                  uVar21 = 0x87dc;
                  break;
                case 0x87d9:
switchD_000bb718_caseD_87d9:
                  uVar21 = 0x87d5;
                  break;
                case 0x87da:
switchD_000bb718_caseD_87da:
                  uVar21 = 0x87d6;
                  break;
                case 0x87db:
switchD_000bb718_caseD_87db:
                  uVar21 = 0x87d7;
                  break;
                case 0x87dc:
switchD_000bb718_caseD_87dc:
                  uVar21 = 0x87d8;
                  break;
                case 0x87de:
switchD_000bb718_caseD_87de:
                  uVar21 = 0x87df;
                  break;
                case 0x87df:
switchD_000bb718_caseD_87df:
                  uVar21 = 0x87de;
                }
                break;
              case 0x87da:
                uVar21 = mulInst[0x12];
                switch(uVar21) {
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
                uVar21 = mulInst[0x13];
                switch(uVar21) {
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
                uVar21 = mulInst[0x14];
                switch(uVar21) {
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
              *puVar14 = uVar21;
              switch(addInstWord48Mapped) {
              case 0x87d5:
                addInstWord48Mapped = *puVar17;
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
                addInstWord48Mapped = *puVar17;
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
                addInstWord4cMapped = *puVar17;
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
                addInstWord4cMapped = *puVar17;
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
                addInstWord50Mapped = *puVar17;
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
                addInstWord50Mapped = *puVar17;
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
                bVar1 = true;
              }
              else {
                bVar1 = true;
                addSearchIndex = uVar36;
              }
            }
          }
          else {
LAB_000ba7ec:
            bVar1 = false;
            addSearchIndex = addSearchIndex + 1;
          }
          if ((instCount <= addSearchIndex) || (bVar1)) break;
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
              bVar1 = true;
              fusedPartnerIndex = 0;
              laterSrc1Slot = (int *)(followerIndex * 0x74 + instArray + 0x3c);
              do {
                if ((*laterSrc1Slot == 2) && (laterSrc1Slot[1] == *(int *)(matMulInst + 8))) {
                  if ((((laterSrc1Slot[-0xf] == 0x8798) && (laterSrc1Slot[-7] == 2)) &&
                      (iVar18 = *(int *)(shader + 0x20) + laterSrc1Slot[-6] * 0x54,
                      *(char *)(iVar18 + 0x44) != '\0')) &&
                     ((*(int *)(iVar18 + 0x48) == 0xba7 && (fusedPartnerIndex == 0)))) {
                    bVar5 = false;
                    fusedPartnerIndex = followerIndex;
                  }
                  else {
LAB_000bd88c:
                    bVar1 = false;
                    bVar5 = true;
                  }
                }
                else {
                  if (((laterSrc1Slot[-7] == 2) && (laterSrc1Slot[-6] == *(int *)(matMulInst + 8))) ||
                     ((laterSrc1Slot[7] == 2 && (laterSrc1Slot[8] == *(int *)(matMulInst + 8))))) goto LAB_000bd88c;
                  if ((laterSrc1Slot[-0xe] != 2) || (bVar5 = true, laterSrc1Slot[-0xd] != *(int *)(matMulInst + 8)))
                  {
                    bVar5 = false;
                  }
                }
                followerIndex = followerIndex + 1;
                followerCount = followerCount + -1;
              } while ((followerCount != 0) && (laterSrc1Slot = laterSrc1Slot + 0x1d, !bVar5));
              if (!bVar1) goto LAB_000bd970;
              partnerOffset = fusedPartnerIndex * 0x74;
            }
            else {
              fusedPartnerIndex = 0;
              partnerOffset = 0;
            }
            iVar18 = *(int *)(shader + 0x2c);
            if (iVar18 == 0) {
              iVar18 = extvsAppendSymbol(iStack00000018,symbolTable,
                                    *(undefined4 *)(*(int *)(((unsigned char *)0x0000116c) + iStack00000018) + 0x18)
                                   );
              instArray = *(int *)(shader + 0x18);
              *(int *)(shader + 0x2c) = iVar18;
            }
            partnerOffset = partnerOffset + instArray;
            *(int *)(matMulInst + 0x24) = iVar18;
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

/* FUN_000bd9a0 @ 0xbd9a0 (160 bytes) */
void FUN_000bd9a0(int glContext,undefined4 param_2,undefined4 param_3,undefined4 param_4,double fpPassThrough1)
{
  code *glContextPtr275c;
  int iVar2;
  undefined4 *puVar3;
  undefined4 r4AfterCall;
  undefined4 staleArgR7;
  undefined4 staleArgR8;
  int a6;
  
  if ((*(uint *)(glContext + 0x44) & 0x100000) == 0) {
    puVar3 = (undefined4 *)(**(code **)(glContext + 0x2758))(glContext,2);
    *(undefined4 **)(0x00002748 + glContext + 4) = puVar3;
    *puVar3 = 0x860;
    a6 = *(int *)(0x00002748 + glContext + 4);
    *(undefined4 *)(a6 + 4) = *(undefined4 *)(glContext + 0x1b78);
    iVar2 = *(int *)(0x00002748 + glContext + 4);
    glContextPtr275c = *(code **)(glContext + 0x275c);
    *(int *)(0x00002748 + glContext + 4) = iVar2 + 8;
    (*glContextPtr275c)(glContext,iVar2 + 8,param_3,param_4,staleArgR7,staleArgR8,a6);
    ffvpAnalyzeLightState(glContext);
    fpPassThrough1 = (double)ffvpBuildLightKey(glContext);
    param_2 = r4AfterCall;
  }
  ((void (*)())FUN_0004d620)(glContext,param_2,param_3,param_4,fpPassThrough1);
  return;
}

/* FUN_000bda40 @ 0xbda40 (1016 bytes) */
int FUN_000bda40(stream, unusedArgR4, dirtyBitsArg, scratchR6, dirtyWord3, dirtyWord1, unusedArgR9, dirtyWord4)
  int stream;
  undefined4 unusedArgR4;
  undefined4 dirtyBitsArg;
  undefined4 scratchR6;
  undefined4 dirtyWord3;
  undefined4 dirtyWord1;
  undefined4 unusedArgR9;
  undefined4 dirtyWord4;
{
  uint streamWord44;
  byte streamByte13b0;
  byte bVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  bool bVar5;
  uint uVar6;
  ushort uVar7;
  int iVar8;
  uint loopIndex2;
  int iVar10;
  uint streamWord8c;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int loopIndex;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  uint uVar24;
  
  streamWord44 = *(uint *)(stream + 0x44);
  if (((((streamWord44 & 0x2000) == 0) || ((*(byte *)(stream + 0x2e) & 1) != 0)) ||
      ((*(uint *)(stream + 0x38) & 0x8000) != 0)) || (*(short *)(stream + 0x42) != 0)) {
    streamByte13b0 = ((unsigned char *)0x000013b0)[stream];
    iVar16 = stream + 0x44;
    *(uint *)(stream + 0x8c) = *(uint *)(stream + 0x8c) & 0xf07fffff;
    *(uint *)(stream + 0x1874) = *(uint *)(stream + 0x1874) & 0xfdffffff;
    uVar24 = (uint)*(byte *)(stream + 0x2b);
    if ((uint)streamByte13b0 < (uint)*(byte *)(stream + 0x2b)) {
      uVar24 = (uint)streamByte13b0;
    }
    if ((streamWord44 & 0x20000) == 0) {
      *(undefined1 *)(stream + 0x1878) = 0;
      uVar21 = 0;
    }
    else {
      if ((streamWord44 & 0x2000) == 0) {
        bVar1 = ((unsigned char *)0x00001135)[stream];
      }
      else {
        bVar1 = ((unsigned char *)0x000011d3)[stream];
      }
      uVar21 = (uint)bVar1;
      *(byte *)(stream + 0x1878) = bVar1;
    }
    loopIndex = 0;
    if (uVar24 != 0) {
      loopIndex2 = 0;
      iVar8 = stream;
      iVar22 = stream;
      iVar23 = stream;
      while( true ) {
        uVar6 = *(uint *)(iVar16 + 4) & 0x1e0;
        if ((streamWord44 & 0x20000) == 0) {
          uVar14 = *(uint *)(iVar16 + 4) & 0x1f;
        }
        else {
          uVar14 = uVar21 & 1 << (loopIndex2 & 0x3f);
        }
        iVar10 = stream + 0x450 + loopIndex2 * 0xcc;
        if ((int)-uVar14 < 0) {
          iVar15 = loopIndex2 * 2 + stream;
          bVar5 = *(char *)(iVar23 + 0x2784) == '\0';
          *(uint *)(iVar8 + 0x150) = (uint)bVar5;
          uVar7 = (ushort)bVar5 << 0xe;
          uVar2 = *(ushort *)(iVar15 + 0x187c);
          *(ushort *)(iVar15 + 0x187c) = uVar2 & 0xbfff | uVar7;
          if (uVar6 == 0) {
            *(ushort *)(iVar15 + 0x187c) = uVar2 & 0x8003 | uVar7;
            uVar14 = *(uint *)(stream + 0x8c);
          }
          else {
            uVar19 = uVar6 >> 7 & 1;
            sVar3 = *(short *)(iVar10 + 0x60);
            uVar14 = uVar6 >> 5 & 1;
            uVar20 = uVar6 >> 6 & 1;
            if ((uVar19 == 0) || (uVar17 = 1, 1 < (ushort)(*(short *)(iVar10 + 0x84) + 0x7aefU))) {
              uVar17 = 0;
            }
            uVar12 = 0;
            if (uVar14 != 0) {
              uVar12 = *(uint *)(&DAT_001dbf70 +
                                (*(ushort *)(iVar22 + 0x48c) >> 2 & 4 |
                                *(ushort *)(iVar22 + 0x48c) & 3) * 4);
            }
            if (uVar20 != 0) {
              uVar12 = uVar12 | *(int *)(&DAT_001dbf70 +
                                        (*(ushort *)(iVar22 + 0x4b0) >> 2 & 4 |
                                        *(ushort *)(iVar22 + 0x4b0) & 3) * 4) << 3;
            }
            if (uVar19 != 0) {
              uVar12 = uVar12 | *(int *)(&DAT_001dbf70 +
                                        (*(ushort *)(iVar22 + 0x4d4) >> 2 & 4 |
                                        *(ushort *)(iVar22 + 0x4d4) & 3) * 4) << 6;
            }
            if (uVar6 >> 8 != 0) {
              uVar12 = uVar12 | *(int *)(&DAT_001dbf70 +
                                        (*(ushort *)(iVar22 + 0x4f8) >> 2 & 4 |
                                        *(ushort *)(iVar22 + 0x4f8) & 3) * 4) << 9;
            }
            iVar15 = loopIndex2 * 2 + stream;
            uVar17 = (((ushort)(*(short *)(iVar10 + 0x3c) + 0x7aefU) < 2 || sVar3 == -0x7aee) ||
                     sVar3 == -0x7aef) | uVar17;
            uVar4 = (uint)(*(short *)(iVar10 + 0x3c) == 0x2402 || sVar3 == 0x2402);
            uVar13 = uVar17 | uVar4;
            *(ushort *)(iVar15 + 0x187c) =
                 *(ushort *)(iVar15 + 0x187c) & 0xc003 | (ushort)(uVar12 << 2) & 0x3ffc;
            streamWord8c = *(uint *)(stream + 0x8c);
            uVar17 = (uVar17 | streamWord8c >> 0x1b & 1) << 0x1b;
            *(uint *)(stream + 0x1874) =
                 (uVar13 | *(uint *)(stream + 0x1874) >> 0x19 & 1) << 0x19 |
                 *(uint *)(stream + 0x1874) & 0xfdffffff;
            uVar12 = (uVar4 | (streamWord8c & 0xf7ffffff) >> 0x1a & 1) << 0x1a;
            *(uint *)(stream + 0x8c) = uVar12 | uVar17 | streamWord8c & 0xf3ffffff;
            uVar14 = ((streamWord8c & 0x2000000) >> 0x19 |
                     uVar13 | *(short *)(iVar10 + 0x3c) == 0x2400 & uVar14 |
                              *(short *)(iVar10 + 0x60) == 0x2400 & uVar20 |
                              *(short *)(iVar10 + 0x84) == 0x2400 & uVar19 |
                              (uint)(*(short *)(iVar10 + 0xa8) == 0x2400) & uVar6 >> 8) << 0x19 |
                     uVar12 | uVar17 | streamWord8c & 0xf1ffffff;
            *(uint *)(stream + 0x8c) = uVar14;
          }
          *(uint *)(stream + 0x8c) = uVar14 | 0x800000;
          iVar10 = loopIndex * 4;
          loopIndex = loopIndex + 1;
          *(uint *)(stream + 0x8c) =
               (uint)(0 < (int)loopIndex2) << 0x18 | uVar14 & 0xfeffffff | 0x800000;
          *(uint *)(iVar10 + stream + 0x98) = loopIndex2;
        }
        else {
          *(undefined4 *)(iVar8 + 0x150) = 0;
          iVar10 = loopIndex2 * 2 + stream;
          *(ushort *)(iVar10 + 0x187c) = *(ushort *)(iVar10 + 0x187c) & 0x8003;
        }
        loopIndex2 = loopIndex2 + 1;
        iVar16 = iVar16 + 4;
        iVar8 = iVar8 + 4;
        iVar22 = iVar22 + 0xcc;
        iVar23 = iVar23 + 1;
        uVar24 = uVar24 - 1;
        if (uVar24 == 0) break;
        streamWord44 = *(uint *)(stream + 0x44);
      }
    }
    *(int *)(stream + 0x94) = loopIndex;
  }
  return;
}

/* FUN_000bde70 @ 0xbde70 (1504 bytes) */
int FUN_000bde70(rsWords, programImage, outProgram, scCallbacks)
  uint *rsWords;
  uint *programImage;
  undefined4 *outProgram;
  undefined4 *scCallbacks;
{
  uint cursor4Word0;
  uint cursor5Word0;
  uint *cursor5;
  int *cursor3;
  int *cursor2;
  uint *puVar1;
  undefined4 *puVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ushort uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int *cursor;
  uint uVar13;
  int iVar14;
  uint *cursor4;
  int *piVar16;
  uint uVar17;
  uint uVar18;
  
  if (((scCallbacks == (undefined4 *)0x0) || (scCallbacks[0xd] != -0x54520ff3)) ||
     (outProgram == (undefined4 *)0x0)) {
    uVar8 = 0x80000005;
  }
  else {
    iVar14 = -(*programImage & 7);
    uVar18 = iVar14 + 3;
    uVar17 = (*rsWords & 0xf) + 1;
    if (uVar18 < 4) {
      uVar13 = uVar18;
      uVar6 = uVar18;
      if ((*programImage >> 3 & 1) != 0) goto LAB_000bdeec;
      while( true ) {
        uVar17 = uVar17 + (programImage[uVar6 + 2] >> 6 & 0x3f) + 1;
        uVar13 = uVar6 + 1;
        if (3 < uVar6 + 1) break;
LAB_000bdeec:
        uVar17 = uVar17 + (programImage[uVar13 + 2] >> 0x11 & 0x1f) + 1;
        uVar6 = uVar13;
      }
    }
    piVar16 = (int *)*outProgram;
    if (piVar16 == (int *)0x0) {
      piVar16 = (int *)(*(code *)*scCallbacks)(uVar17 * 0x48 + 0x48);
      *piVar16 = 0;
      piVar16[1] = uVar17 + 1;
      *outProgram = piVar16;
    }
    else if ((*piVar16 != 0) || ((uint)piVar16[1] <= uVar17)) {
      return 0x80000006;
    }
    *(undefined2 *)(piVar16 + 5) = 0;
    piVar16[2] = 0;
    *(byte *)((int)piVar16 + 0xd) = (byte)(*rsWords >> 5) & 7;
    uVar13 = 0;
    cursor4 = rsWords;
    cursor = piVar16;
    do {
      uVar4 = uVar13;
      cursor[0x12] = 1;
      uVar13 = uVar4 + 1;
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
    } while (uVar13 <= (*rsWords & 0xf));
    iVar9 = uVar4 + 2;
    uVar13 = *programImage >> 3 & 1;
    if (uVar18 < 4) {
      cursor5 = programImage + iVar14 + 5;
      do {
        cursor5Word0 = *cursor5;
        cursor5 = cursor5 + 1;
        uVar6 = cursor5Word0 & 0x3f;
        uVar10 = cursor5Word0 >> 0xc & 0x1f;
        if ((uVar13 != 0) && (uVar13 = uVar10 + (cursor5Word0 >> 0x11 & 0x1f), uVar10 <= uVar13)) {
          iVar14 = uVar10 << 2;
          cursor2 = piVar16 + iVar9 * 0x12;
          uVar11 = uVar10;
          do {
            *cursor2 = 2;
            bVar3 = uVar11 == uVar10;
            uVar11 = uVar11 + 1;
            iVar9 = iVar9 + 1;
            *(byte *)((int)cursor2 + 0x19) = (byte)(*(uint *)(iVar14 + programImage[7]) >> 0xb) & 0xf;
            uVar5 = *(uint *)(iVar14 + programImage[7]);
            *(bool *)(cursor2 + 8) = bVar3;
            *(undefined1 *)((int)cursor2 + 0x1f) = 0;
            *(byte *)((int)cursor2 + 0x1a) = (byte)(uVar5 >> 0xf) & 7;
            *(ushort *)((int)cursor2 + 0xe) = (ushort)*(undefined4 *)(iVar14 + programImage[7]) & 0x1f;
            puVar1 = (uint *)(iVar14 + programImage[7]);
            iVar14 = iVar14 + 4;
            *(ushort *)(cursor2 + 3) = (ushort)(*puVar1 >> 6) & 0x1f;
            cursor2 = cursor2 + 0x12;
          } while (uVar11 <= uVar13);
        }
        uVar13 = uVar6 + (cursor5Word0 >> 6 & 0x3f);
        if (uVar6 <= uVar13) {
          iVar14 = uVar6 << 2;
          cursor3 = piVar16 + iVar9 * 0x12;
          do {
            *cursor3 = 3;
            *(byte *)(cursor3 + 5) = (byte)(*(uint *)(programImage[8] + iVar14) >> 0x17) & 7;
            *(byte *)((int)cursor3 + 0x15) =
                 (byte)((uint)*(undefined4 *)(programImage[8] + iVar14) >> 0x1a) & 7;
            *(byte *)((int)cursor3 + 0x16) =
                 (byte)((uint)*(undefined4 *)(programImage[8] + iVar14) >> 0x1d) & 3;
            uVar4 = *(uint *)(programImage[8] + iVar14) & 0x3f;
            uVar7 = (ushort)uVar4;
            if (0x1f < uVar4) {
              uVar7 = uVar7 - 0x20 | 0x8000;
            }
            *(ushort *)((int)cursor3 + 0xe) = uVar7;
            uVar4 = *(uint *)(programImage[8] + iVar14) >> 6 & 0x3f;
            uVar7 = (ushort)uVar4;
            if (0x1f < uVar4) {
              uVar7 = uVar7 - 0x20 | 0x8000;
            }
            *(ushort *)(cursor3 + 4) = uVar7;
            uVar4 = *(uint *)(programImage[8] + iVar14) >> 0xc & 0x3f;
            uVar7 = (ushort)uVar4;
            if (0x1f < uVar4) {
              uVar7 = uVar7 - 0x20 | 0x8000;
            }
            *(ushort *)((int)cursor3 + 0x12) = uVar7;
            *(ushort *)(cursor3 + 3) =
                 (ushort)((uint)*(undefined4 *)(programImage[8] + iVar14) >> 0x12) & 0x1f;
            *(byte *)(cursor3 + 8) = (byte)(*(uint *)(programImage[9] + iVar14) >> 0x17) & 1;
            *(byte *)((int)cursor3 + 0x21) = *(byte *)(programImage[9] + iVar14) & 1;
            *(byte *)((int)cursor3 + 0x22) =
                 (byte)((uint)*(undefined4 *)(programImage[9] + iVar14) >> 0x19) & 3;
            *(byte *)((int)cursor3 + 0x23) =
                 (byte)((uint)*(undefined4 *)(programImage[9] + iVar14) >> 0x1b) & 1;
            uVar4 = *(uint *)(programImage[9] + iVar14) & 0x3f;
            uVar7 = (ushort)uVar4;
            if (0x1f < uVar4) {
              uVar7 = uVar7 - 0x20 | 0x8000;
            }
            *(ushort *)((int)cursor3 + 0x1a) = uVar7;
            uVar4 = *(uint *)(programImage[9] + iVar14) >> 6 & 0x3f;
            uVar7 = (ushort)uVar4;
            if (0x1f < uVar4) {
              uVar7 = uVar7 - 0x20 | 0x8000;
            }
            *(ushort *)(cursor3 + 7) = uVar7;
            uVar4 = *(uint *)(programImage[9] + iVar14) >> 0xc & 0x3f;
            uVar7 = (ushort)uVar4;
            if (0x1f < uVar4) {
              uVar7 = uVar7 - 0x20 | 0x8000;
            }
            *(ushort *)((int)cursor3 + 0x1e) = uVar7;
            uVar6 = uVar6 + 1;
            iVar9 = iVar9 + 1;
            *(ushort *)(cursor3 + 6) =
                 (ushort)((uint)*(undefined4 *)(programImage[9] + iVar14) >> 0x12) & 0x1f;
            *(byte *)((int)cursor3 + 0x2a) = (byte)*(undefined4 *)(programImage[0xb] + iVar14) & 0x1f;
            *(byte *)((int)cursor3 + 0x2d) = (byte)(*(uint *)(programImage[0xb] + iVar14) >> 5) & 3;
            *(byte *)((int)cursor3 + 0x2b) = (byte)(*(uint *)(programImage[0xb] + iVar14) >> 7) & 0x1f;
            *(byte *)((int)cursor3 + 0x2e) = (byte)(*(uint *)(programImage[0xb] + iVar14) >> 0xc) & 3;
            *(byte *)(cursor3 + 0xb) = (byte)(*(uint *)(programImage[0xb] + iVar14) >> 0xe) & 0x1f;
            *(byte *)((int)cursor3 + 0x2f) = (byte)(*(uint *)(programImage[0xb] + iVar14) >> 0x13) & 3;
            *(byte *)(cursor3 + 0xc) = (byte)(*(uint *)(programImage[0xb] + iVar14) >> 0x15) & 3;
            *(byte *)((int)cursor3 + 0x31) = (byte)(*(uint *)(programImage[0xb] + iVar14) >> 0x17) & 0xf;
            *(byte *)((int)cursor3 + 0x32) =
                 (byte)((uint)*(undefined4 *)(programImage[0xb] + iVar14) >> 0x1b) & 7;
            *(byte *)((int)cursor3 + 0x33) =
                 (byte)((uint)*(undefined4 *)(programImage[0xb] + iVar14) >> 0x1e) & 1;
            *(byte *)(cursor3 + 0xd) = (byte)((uint)*(undefined4 *)(programImage[0xb] + iVar14) >> 0x1f);
            *(byte *)((int)cursor3 + 0x39) = (byte)*(undefined4 *)(iVar14 + programImage[0xc]) & 0x1f;
            *(byte *)(cursor3 + 0xf) = (byte)(*(uint *)(iVar14 + programImage[0xc]) >> 5) & 3;
            *(byte *)((int)cursor3 + 0x3a) = (byte)(*(uint *)(iVar14 + programImage[0xc]) >> 7) & 0x1f;
            *(byte *)((int)cursor3 + 0x3d) = (byte)(*(uint *)(iVar14 + programImage[0xc]) >> 0xc) & 3;
            *(byte *)((int)cursor3 + 0x3b) = (byte)(*(uint *)(iVar14 + programImage[0xc]) >> 0xe) & 0x1f;
            *(byte *)((int)cursor3 + 0x3e) = (byte)(*(uint *)(iVar14 + programImage[0xc]) >> 0x13) & 3;
            *(byte *)((int)cursor3 + 0x3f) = (byte)(*(uint *)(iVar14 + programImage[0xc]) >> 0x15) & 3;
            *(byte *)(cursor3 + 0x10) = (byte)(*(uint *)(iVar14 + programImage[0xc]) >> 0x17) & 0xf;
            *(byte *)((int)cursor3 + 0x41) =
                 (byte)((uint)*(undefined4 *)(iVar14 + programImage[0xc]) >> 0x1b) & 7;
            puVar2 = (undefined4 *)(iVar14 + programImage[0xc]);
            iVar14 = iVar14 + 4;
            *(byte *)((int)cursor3 + 0x42) = (byte)((uint)*puVar2 >> 0x1e) & 1;
            cursor3 = cursor3 + 0x12;
          } while (uVar6 <= uVar13);
        }
        bVar3 = uVar18 != 3;
        uVar13 = 1;
        uVar18 = uVar18 + 1;
      } while (bVar3);
    }
    uVar8 = 0;
    piVar16[2] = uVar17;
  }
  return uVar8;
}

/* FUN_000be460 @ 0xbe460 (2472 bytes) */
int FUN_000be460(psnProgram, rsWords, programImage, unusedArgR6, unusedArgR7, unusedArgR8, unusedArgR9)
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
  ushort uVar1;
  ushort psnProgramShort22;
  int iVar3;
  bool bVar4;
  bool bVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint *puVar10;
  int *piVar11;
  uint loopIndex2;
  int iVar13;
  uint uVar14;
  int *piVar15;
  int *piVar16;
  uint uVar17;
  uint *cursor;
  byte bVar19;
  byte bVar20;
  uint psnProgramWord8;
  uint loopIndex3;
  uint uVar23;
  int iVar24;
  
  psnProgramShort16 = *(ushort *)(psnProgram + 0x16);
  psnProgramShort22 = *(ushort *)(psnProgram + 0x22);
  psnProgramWord8 = *(uint *)(psnProgram + 8);
  iVar24 = 4 - (uint)psnProgramShort16;
  if ((*(int *)(psnProgram + 0x48) == 1) && (psnProgramWord8 != 0)) {
    piVar15 = (int *)(psnProgram + 0x90);
    loopIndex2 = 1;
    piVar6 = piVar15;
    piVar16 = (int *)(psnProgram + 0x48);
    uVar9 = 0;
    do {
      piVar11 = piVar6;
      uVar17 = uVar9;
      if ((piVar16[2] & 0xff00ffU) != 0) {
        uVar17 = uVar9 + 1;
        rsWords[uVar9 + 1] = 0;
        bVar19 = *(byte *)(piVar16 + 2);
        rsWords[uVar9 + 1] = bVar19 & 0xf;
        uVar7 = (*(byte *)((int)piVar16 + 9) & 1) << 4 | bVar19 & 0xf;
        rsWords[uVar9 + 1] = uVar7;
        uVar7 = (*(byte *)((int)piVar16 + 10) & 0xf) << 0xc | uVar7;
        rsWords[uVar9 + 1] = uVar7;
        uVar7 = (*(byte *)((int)piVar16 + 0xb) & 3) << 0x10 | uVar7;
        rsWords[uVar9 + 1] = uVar7;
        uVar7 = (*(byte *)(piVar16 + 3) & 1) << 0x19 | uVar7;
        rsWords[uVar9 + 1] = uVar7;
        uVar7 = (uint)*(byte *)((int)piVar16 + 0xd) << 0x1b | uVar7;
        rsWords[uVar9 + 1] = uVar7;
        uVar7 = (*(ushort *)(piVar16 + 1) & 0x7f) << 5 | uVar7;
        rsWords[uVar9 + 1] = uVar7;
        rsWords[uVar9 + 1] = (*(ushort *)((int)piVar16 + 6) & 0x7f) << 0x12 | uVar7;
      }
      loopIndex2 = loopIndex2 + 1;
      if (*piVar15 != 1) break;
      piVar15 = piVar15 + 0x12;
      piVar6 = piVar11 + 0x12;
      piVar16 = piVar11;
      uVar9 = uVar17;
    } while (loopIndex2 <= psnProgramWord8);
    uVar9 = uVar17 & 0xff;
    if (uVar17 != 0) goto LAB_000be580;
  }
  else {
    loopIndex2 = 1;
  }
  uVar9 = 1;
  rsWords[1] = 0;
LAB_000be580:
  uVar9 = uVar9 - 1 & 0xf;
  *rsWords = uVar9;
  *rsWords = (*(byte *)(psnProgram + 0xd) & 7) << 5 | uVar9;
  programImage[1] = psnProgramShort22 & 0x7f;
  *programImage = psnProgramShort16 - 1 & 7;
  programImage[0xd] = 0;
  programImage[2] = 0;
  programImage[3] = 0;
  programImage[4] = 0;
  programImage[5] = 0;
  programImage[6] = 0;
  if (loopIndex2 <= psnProgramWord8) {
    bVar4 = false;
    uVar7 = 0;
    uVar17 = 0;
    loopIndex = 0;
    loopIndex3 = 0;
    puVar10 = (uint *)(psnProgram + loopIndex2 * 0x48);
    bVar20 = 0;
    bVar19 = 0;
    bVar5 = false;
    cursor = puVar10 + 0x1a;
    do {
      uVar8 = *puVar10;
      iVar13 = uVar7 + loopIndex;
      if (uVar8 == 2) {
        if (*(char *)((int)puVar10 + 0x1a) != '\0') {
          iVar3 = (uVar17 + loopIndex3) * 4;
          *(undefined4 *)(programImage[7] + iVar3) = 0;
          *(uint *)(iVar3 + programImage[7]) =
               *(byte *)((int)puVar10 + 0xf) & 0x1f | *(uint *)(iVar3 + programImage[7]) & 0xffffffe0;
          *(uint *)(iVar3 + programImage[7]) =
               (*(byte *)((int)puVar10 + 0xd) & 0x1f) << 6 |
               *(uint *)(iVar3 + programImage[7]) & 0xfffff83f;
          *(uint *)(iVar3 + programImage[7]) =
               (*(byte *)((int)puVar10 + 0x19) & 0xf) << 0xb |
               *(uint *)(iVar3 + programImage[7]) & 0xffff87ff;
          *(uint *)(iVar3 + programImage[7]) =
               (*(byte *)((int)puVar10 + 0x1a) & 7) << 0xf |
               *(uint *)(iVar3 + programImage[7]) & 0xfffc7fff;
          *(uint *)(iVar3 + programImage[7]) =
               (*(ushort *)((int)puVar10 + 0xe) & 0x20) << 0xe |
               *(uint *)(iVar3 + programImage[7]) & 0xfff7ffff;
          *(uint *)(iVar3 + programImage[7]) =
               (*(ushort *)(puVar10 + 3) & 0x20) << 0xf | *(uint *)(iVar3 + programImage[7]) & 0xffefffff
          ;
          if (!bVar5) {
            bVar5 = true;
            *programImage = *programImage | 8;
          }
          loopIndex3 = loopIndex3 + 1;
          bVar4 = false;
        }
      }
      else if ((1 < uVar8) && (uVar8 < 5)) {
        iVar3 = iVar13 * 4;
        *(undefined4 *)(programImage[8] + iVar3) = 0;
        uVar1 = *(ushort *)((int)puVar10 + 0xe);
        uVar8 = uVar1 & 0x1f;
        if ((uVar1 & 0x8000) != 0) {
          uVar8 = (uVar1 & 0x1f) + 0x20;
        }
        *(uint *)(iVar3 + programImage[8]) = uVar8 | *(uint *)(iVar3 + programImage[8]) & 0xffffffc0;
        uVar8 = *(ushort *)(puVar10 + 4) & 0x1f;
        if ((*(ushort *)(puVar10 + 4) & 0x8000) != 0) {
          uVar8 = uVar8 + 0x20;
        }
        *(uint *)(iVar3 + programImage[8]) = uVar8 << 6 | *(uint *)(iVar3 + programImage[8]) & 0xfffff03f;
        uVar8 = *(ushort *)((int)puVar10 + 0x12) & 0x1f;
        if ((*(ushort *)((int)puVar10 + 0x12) & 0x8000) != 0) {
          uVar8 = uVar8 + 0x20;
        }
        *(uint *)(iVar3 + programImage[8]) = uVar8 << 0xc | *(uint *)(iVar3 + programImage[8]) & 0xfffc0fff;
        *(uint *)(iVar3 + programImage[8]) =
             (*(byte *)((int)puVar10 + 0xd) & 0x1f) << 0x12 |
             *(uint *)(iVar3 + programImage[8]) & 0xff83ffff;
        *(uint *)(iVar3 + programImage[8]) =
             (*(byte *)(puVar10 + 5) & 7) << 0x17 | *(uint *)(iVar3 + programImage[8]) & 0xfc7fffff;
        *(uint *)(iVar3 + programImage[8]) =
             (*(byte *)((int)puVar10 + 0x15) & 7) << 0x1a |
             *(uint *)(iVar3 + programImage[8]) & 0xe3ffffff;
        *(uint *)(iVar3 + programImage[8]) =
             (*(byte *)((int)puVar10 + 0x16) & 3) << 0x1d |
             *(uint *)(iVar3 + programImage[8]) & 0x9fffffff;
        *(undefined4 *)(programImage[9] + iVar3) = 0;
        uVar8 = *(ushort *)((int)puVar10 + 0x1a) & 0x1f;
        if ((*(ushort *)((int)puVar10 + 0x1a) & 0x8000) != 0) {
          uVar8 = uVar8 + 0x20;
        }
        *(uint *)(iVar3 + programImage[9]) = uVar8 | *(uint *)(iVar3 + programImage[9]) & 0xffffffc0;
        uVar8 = *(ushort *)(puVar10 + 7) & 0x1f;
        if ((*(ushort *)(puVar10 + 7) & 0x8000) != 0) {
          uVar8 = uVar8 + 0x20;
        }
        *(uint *)(iVar3 + programImage[9]) = uVar8 << 6 | *(uint *)(iVar3 + programImage[9]) & 0xfffff03f;
        uVar8 = *(ushort *)((int)puVar10 + 0x1e) & 0x1f;
        if ((*(ushort *)((int)puVar10 + 0x1e) & 0x8000) != 0) {
          uVar8 = uVar8 + 0x20;
        }
        *(uint *)(iVar3 + programImage[9]) = uVar8 << 0xc | *(uint *)(iVar3 + programImage[9]) & 0xfffc0fff;
        *(uint *)(iVar3 + programImage[9]) =
             (*(byte *)((int)puVar10 + 0x19) & 0x1f) << 0x12 |
             *(uint *)(iVar3 + programImage[9]) & 0xff83ffff;
        *(uint *)(iVar3 + programImage[9]) =
             (*(byte *)(puVar10 + 8) & 1) << 0x17 | *(uint *)(iVar3 + programImage[9]) & 0xff7fffff;
        *(uint *)(iVar3 + programImage[9]) =
             (*(byte *)((int)puVar10 + 0x21) & 1) << 0x18 |
             *(uint *)(iVar3 + programImage[9]) & 0xfeffffff;
        *(uint *)(iVar3 + programImage[9]) =
             (*(byte *)((int)puVar10 + 0x22) & 3) << 0x19 |
             *(uint *)(iVar3 + programImage[9]) & 0xf9ffffff;
        *(uint *)(iVar3 + programImage[9]) =
             (*(byte *)((int)puVar10 + 0x23) & 1) << 0x1b |
             *(uint *)(iVar3 + programImage[9]) & 0xf7ffffff;
        if (programImage[10] != 0) {
          *(undefined4 *)(programImage[10] + iVar3) = 0;
          *(uint *)(iVar3 + programImage[10]) =
               *(ushort *)((int)puVar10 + 0xe) >> 5 & 1 |
               *(uint *)(iVar3 + programImage[10]) & 0xfffffffe;
          *(uint *)(iVar3 + programImage[10]) =
               *(ushort *)(puVar10 + 4) >> 4 & 2 | *(uint *)(iVar3 + programImage[10]) & 0xfffffffd;
          *(uint *)(iVar3 + programImage[10]) =
               *(ushort *)((int)puVar10 + 0x12) >> 3 & 4 |
               *(uint *)(iVar3 + programImage[10]) & 0xfffffffb;
          *(uint *)(iVar3 + programImage[10]) =
               *(ushort *)(puVar10 + 3) >> 2 & 8 | *(uint *)(iVar3 + programImage[10]) & 0xfffffff7;
          *(uint *)(iVar3 + programImage[10]) =
               *(ushort *)((int)puVar10 + 0x1a) >> 1 & 0x10 |
               *(uint *)(iVar3 + programImage[10]) & 0xffffffef;
          *(uint *)(iVar3 + programImage[10]) =
               *(ushort *)(puVar10 + 7) & 0x20 | *(uint *)(iVar3 + programImage[10]) & 0xffffffdf;
          *(uint *)(iVar3 + programImage[10]) =
               (*(ushort *)((int)puVar10 + 0x1e) & 0x20) << 1 |
               *(uint *)(iVar3 + programImage[10]) & 0xffffffbf;
          *(uint *)(iVar3 + programImage[10]) =
               (*(ushort *)(puVar10 + 6) & 0x20) << 2 | *(uint *)(iVar3 + programImage[10]) & 0xffffff7f;
        }
        loopIndex = loopIndex + 1;
        bVar4 = true;
        *(undefined4 *)(programImage[0xb] + iVar3) = 0;
        *(uint *)(iVar3 + programImage[0xb]) =
             *(byte *)((int)puVar10 + 0x2a) & 0x1f | *(uint *)(iVar3 + programImage[0xb]) & 0xffffffe0;
        *(uint *)(iVar3 + programImage[0xb]) =
             (*(byte *)((int)puVar10 + 0x2d) & 3) << 5 |
             *(uint *)(iVar3 + programImage[0xb]) & 0xffffff9f;
        *(uint *)(iVar3 + programImage[0xb]) =
             (*(byte *)((int)puVar10 + 0x2b) & 0x1f) << 7 |
             *(uint *)(iVar3 + programImage[0xb]) & 0xfffff07f;
        *(uint *)(iVar3 + programImage[0xb]) =
             (*(byte *)((int)puVar10 + 0x2e) & 3) << 0xc |
             *(uint *)(iVar3 + programImage[0xb]) & 0xffffcfff;
        *(uint *)(iVar3 + programImage[0xb]) =
             (*(byte *)(puVar10 + 0xb) & 0x1f) << 0xe | *(uint *)(iVar3 + programImage[0xb]) & 0xfff83fff
        ;
        *(uint *)(iVar3 + programImage[0xb]) =
             (*(byte *)((int)puVar10 + 0x2f) & 3) << 0x13 |
             *(uint *)(iVar3 + programImage[0xb]) & 0xffe7ffff;
        *(uint *)(iVar3 + programImage[0xb]) =
             (*(byte *)(puVar10 + 0xc) & 3) << 0x15 | *(uint *)(iVar3 + programImage[0xb]) & 0xff9fffff;
        *(uint *)(iVar3 + programImage[0xb]) =
             (*(byte *)((int)puVar10 + 0x31) & 0xf) << 0x17 |
             *(uint *)(iVar3 + programImage[0xb]) & 0xf87fffff;
        *(uint *)(iVar3 + programImage[0xb]) =
             (*(byte *)((int)puVar10 + 0x32) & 7) << 0x1b |
             *(uint *)(iVar3 + programImage[0xb]) & 0xc7ffffff;
        *(uint *)(iVar3 + programImage[0xb]) =
             (*(byte *)((int)puVar10 + 0x33) & 1) << 0x1e |
             *(uint *)(iVar3 + programImage[0xb]) & 0xbfffffff;
        *(uint *)(iVar3 + programImage[0xb]) =
             (uint)*(byte *)(puVar10 + 0xd) << 0x1f | *(uint *)(iVar3 + programImage[0xb]) & 0x7fffffff;
        *(undefined4 *)(programImage[0xc] + iVar3) = 0;
        *(uint *)(iVar3 + programImage[0xc]) =
             *(byte *)((int)puVar10 + 0x39) & 0x1f | *(uint *)(iVar3 + programImage[0xc]) & 0xffffffe0;
        *(uint *)(iVar3 + programImage[0xc]) =
             (*(byte *)(puVar10 + 0xf) & 3) << 5 | *(uint *)(iVar3 + programImage[0xc]) & 0xffffff9f;
        *(uint *)(iVar3 + programImage[0xc]) =
             (*(byte *)((int)puVar10 + 0x3a) & 0x1f) << 7 |
             *(uint *)(iVar3 + programImage[0xc]) & 0xfffff07f;
        *(uint *)(iVar3 + programImage[0xc]) =
             (*(byte *)((int)puVar10 + 0x3d) & 3) << 0xc |
             *(uint *)(iVar3 + programImage[0xc]) & 0xffffcfff;
        *(uint *)(iVar3 + programImage[0xc]) =
             (*(byte *)((int)puVar10 + 0x3b) & 0x1f) << 0xe |
             *(uint *)(iVar3 + programImage[0xc]) & 0xfff83fff;
        *(uint *)(iVar3 + programImage[0xc]) =
             (*(byte *)((int)puVar10 + 0x3e) & 3) << 0x13 |
             *(uint *)(iVar3 + programImage[0xc]) & 0xffe7ffff;
        *(uint *)(iVar3 + programImage[0xc]) =
             (*(byte *)((int)puVar10 + 0x3f) & 3) << 0x15 |
             *(uint *)(iVar3 + programImage[0xc]) & 0xff9fffff;
        *(uint *)(iVar3 + programImage[0xc]) =
             (*(byte *)(puVar10 + 0x10) & 0xf) << 0x17 |
             *(uint *)(iVar3 + programImage[0xc]) & 0xf87fffff;
        *(uint *)(iVar3 + programImage[0xc]) =
             (*(byte *)((int)puVar10 + 0x41) & 7) << 0x1b |
             *(uint *)(iVar3 + programImage[0xc]) & 0xc7ffffff;
        *(uint *)(iVar3 + programImage[0xc]) =
             (*(byte *)((int)puVar10 + 0x42) & 1) << 0x1e |
             *(uint *)(iVar3 + programImage[0xc]) & 0xbfffffff;
        bVar20 = bVar20 | *(byte *)((int)puVar10 + 0x23);
        bVar19 = bVar19 | *(byte *)((int)puVar10 + 0x15) | *(byte *)((int)puVar10 + 0x21);
      }
      if ((loopIndex2 == psnProgramWord8) || ((cursor[-8] == 2 && ((bVar4 || (*(char *)cursor != '\0')))))) {
        if (loopIndex3 == 0) {
          loopIndex3 = 1;
          uVar8 = 1;
          uVar23 = 0;
        }
        else {
          uVar8 = loopIndex3 & 0xff;
          uVar23 = loopIndex3 - 1;
        }
        uVar14 = loopIndex & 0xff;
        if (loopIndex == 0) {
          iVar13 = iVar13 * 4;
          *(undefined4 *)(programImage[8] + iVar13) = 0;
          *(undefined4 *)(programImage[9] + iVar13) = 0;
          if (programImage[10] != 0) {
            *(undefined4 *)(programImage[10] + iVar13) = 0;
          }
          uVar14 = 1;
          *(undefined4 *)(programImage[0xb] + iVar13) = 0;
          *(undefined4 *)(programImage[0xc] + iVar13) = 0;
          loopIndex = 1;
        }
        programImage[iVar24 + 2] =
             (uVar23 & 0x1e0) << 0x17 |
             (uVar17 & 0x1e0) << 0x13 |
             (uVar14 - 1) * 0x40 & 0xfc0 |
             (uVar8 - 1) * 0x20000 & 0x3e0000 |
             uVar7 & 0x3f | (uVar17 & 0x1f) << 0xc | programImage[iVar24 + 2] & 0xc00000;
        if (iVar24 == 1) {
          programImage[6] = (loopIndex - 1) * 0x200 & 0x38000 |
                       (uVar7 & 0x1c0) << 6 | programImage[6] & 0xfffc0fff;
        }
        else if (iVar24 == 0) {
          programImage[6] = (loopIndex - 1) * 8 & 0xe00 | uVar7 & 0x1c0 | programImage[6] & 0xfffff03f;
        }
        else if (iVar24 == 2) {
          programImage[6] = (loopIndex - 1) * 0x8000 & 0xe00000 |
                       (uVar7 & 0x1c0) << 0xc | programImage[6] & 0xff03ffff;
        }
        else if (iVar24 == 3) {
          programImage[6] = (loopIndex - 1) * 0x200000 & 0x38000000 |
                       (uVar7 & 0x1c0) << 0x12 | programImage[6] & 0xc0ffffff;
        }
        if (bVar19 != 0) {
          programImage[iVar24 + 2] = programImage[iVar24 + 2] | 0x400000;
        }
        if (bVar20 != 0) {
          programImage[iVar24 + 2] = programImage[iVar24 + 2] | 0x800000;
          programImage[0xd] = programImage[0xd] | 1;
        }
        if (bVar5) {
          uVar17 = uVar17 + loopIndex3;
        }
        uVar7 = uVar7 + loopIndex;
        iVar24 = iVar24 + 1;
        loopIndex = 0;
        loopIndex3 = 0;
        bVar20 = 0;
        bVar19 = 0;
        bVar5 = true;
      }
      loopIndex2 = loopIndex2 + 1;
      puVar10 = puVar10 + 0x12;
      cursor = cursor + 0x12;
    } while (loopIndex2 <= psnProgramWord8);
  }
  return;
}

/* FUN_000bee40 @ 0xbee40 (244 bytes) */
int FUN_000bee40(psnProgram, param_2, param_3, unusedArgR6, param_5, param_6, param_7)
  int psnProgram;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 unusedArgR6;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  undefined4 uVar1;
  
  ((int (*)())FUN_000c5e60)(psnProgram);
  if (*(ushort *)(psnProgram + 0x16) < 5) {
    if (*(ushort *)(psnProgram + 0x18) < 0x11) {
      if (*(ushort *)(psnProgram + 0x1a) < 0x21) {
        if (*(ushort *)(psnProgram + 0x1e) < 0x41) {
          if (*(short *)(psnProgram + 0x20) == 0) {
            if (*(ushort *)(psnProgram + 0x22) < 0x20) {
              if (*(ushort *)(psnProgram + 0x24) < 0x20) {
                ((int (*)())FUN_000be460)(psnProgram,param_2,param_3,0,param_5,param_6,param_7);
                uVar1 = 0;
              }
              else {
                uVar1 = 0x80000013;
              }
            }
            else {
              uVar1 = 0x80000012;
            }
          }
          else {
            uVar1 = 0x80000017;
          }
        }
        else {
          uVar1 = 0x80000016;
        }
      }
      else {
        uVar1 = 0x80000015;
      }
    }
    else {
      uVar1 = 0x80000014;
    }
  }
  else {
    uVar1 = 0x80000011;
  }
  return uVar1;
}

/* FUN_000bef40 @ 0xbef40 (1192 bytes) */
int FUN_000bef40(psnProgram, param_2, param_3, unusedArgR6, param_5)
  int psnProgram;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 unusedArgR6;
  dword *param_5;
{
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  dword dVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  char *pcVar10;
  ushort *puVar11;
  ushort *puVar12;
  dword *pdVar13;
  dword *pdVar14;
  int *piVar15;
  dword *pdVar16;
  char *pcVar17;
  uint loopIndex;
  dword *pdVar19;
  ushort *puVar20;
  uint psnProgramWord8;
  ushort *puVar22;
  ushort *puVar23;
  char *pcVar24;
  ushort *puVar25;
  char *pcVar26;
  dword *pdVar27;
  ushort *puVar28;
  ushort *puVar29;
  ushort *puVar30;
  int iVar31;
  int aiStack_148 [32];
  int aiStack_c8 [35];
  
  ((int (*)())FUN_000c5e60)(psnProgram);
  if (*(ushort *)(psnProgram + 0x16) < 5) {
    if (*(ushort *)(psnProgram + 0x18) < 0x11) {
      if (*(ushort *)(psnProgram + 0x1a) < 0x201) {
        if (*(ushort *)(psnProgram + 0x1e) < 0x201) {
          if (*(short *)(psnProgram + 0x20) == 0) {
            if (*(ushort *)(psnProgram + 0x22) < 0x40) {
              if (*(ushort *)(psnProgram + 0x24) < 0x40) {
                pdVar16 = &(*(GhidraMachOCommand *)0x0000001c).filesize;
                psnProgramWord8 = *(uint *)(psnProgram + 8);
                iVar7 = 0;
                iVar31 = 0x40;
                do {
                  *(undefined4 *)(iVar7 + (int)aiStack_148) = 0xffffffff;
                  iVar7 = iVar7 + 4;
                  iVar31 = iVar31 + -1;
                } while (iVar31 != 0);
                if ((psnProgramWord8 != 0) &&
                   (pdVar14 = (dword *)(psnProgram + 0x48), param_5 = pdVar14,
                   *(int *)(psnProgram + 0x48) == 1)) {
                  pdVar19 = (dword *)(psnProgram + 0x90);
                  loopIndex = 1;
                  bVar1 = false;
                  pdVar27 = pdVar19;
                  pdVar16 = pdVar14;
                  do {
                    pdVar13 = pdVar27;
                    if ((*(char *)((int)pdVar16 + 9) != '\0') &&
                       (uVar3 = *(ushort *)(pdVar16 + 1), aiStack_148[uVar3] = 0,
                       (uVar3 & 0x20) != 0)) {
                      bVar1 = true;
                    }
                    if ((*(char *)((int)pdVar16 + 0xb) != '\0') &&
                       (uVar3 = *(ushort *)((int)pdVar16 + 6), aiStack_148[uVar3] = 0,
                       (uVar3 & 0x20) != 0)) {
                      bVar1 = true;
                    }
                    loopIndex = loopIndex + 1;
                    if (psnProgramWord8 < loopIndex) break;
                    dVar4 = *pdVar19;
                    pdVar19 = pdVar19 + 0x12;
                    pdVar27 = pdVar13 + 0x12;
                    pdVar16 = pdVar13;
                  } while (dVar4 == 1);
                  if (bVar1) {
                    iVar7 = 0x20;
                    iVar31 = 0;
                    piVar15 = aiStack_c8;
                    do {
                      if (*piVar15 == 0) {
                        if (aiStack_148[iVar31] != -1) {
                          piVar8 = aiStack_148 + iVar31 + 1;
                          do {
                            iVar5 = *piVar8;
                            iVar31 = iVar31 + 1;
                            piVar8 = piVar8 + 1;
                          } while (iVar5 != -1);
                        }
                        *piVar15 = iVar31;
                        aiStack_148[iVar31] = iVar7;
                      }
                      bVar1 = iVar7 != 0x3f;
                      piVar15 = piVar15 + 1;
                      iVar7 = iVar7 + 1;
                    } while (bVar1);
                    pdVar19 = (dword *)(psnProgram + 0x56);
                    puVar28 = (ushort *)(psnProgram + 0x62);
                    param_5 = (dword *)(psnProgram + 0x54);
                    puVar22 = (ushort *)(psnProgram + 0x66);
                    puVar23 = (ushort *)(psnProgram + 0x4e);
                    pcVar24 = (char *)(psnProgram + 0x53);
                    puVar25 = (ushort *)(psnProgram + 0x4c);
                    pcVar26 = (char *)(psnProgram + 0x51);
                    puVar29 = (ushort *)(psnProgram + 100);
                    puVar20 = (ushort *)(psnProgram + 0x60);
                    pcVar10 = (char *)(psnProgram + 0x68);
                    puVar11 = (ushort *)(psnProgram + 0x5a);
                    puVar12 = (ushort *)(psnProgram + 0x58);
                    loopIndex = 1;
                    pcVar17 = (char *)(psnProgram + 0x5c);
                    pdVar16 = pdVar19;
                    pdVar27 = param_5;
                    puVar30 = puVar28;
                    do {
                      uVar6 = *pdVar14;
                      if (uVar6 != 2) {
                        if (uVar6 < 3) {
                          if (uVar6 == 1) {
                            if ((*pcVar26 != '\0') && (iVar7 = aiStack_148[*puVar25], iVar7 != -1))
                            {
                              *puVar25 = (ushort)iVar7;
                            }
                            if ((*pcVar24 != '\0') && (iVar7 = aiStack_148[*puVar23], iVar7 != -1))
                            {
                              *puVar23 = (ushort)iVar7;
                            }
                          }
                        }
                        else if (uVar6 < 5) {
                          if ((*pcVar17 != '\0') &&
                             (iVar7 = aiStack_148[*(ushort *)param_5], iVar7 != -1)) {
                            *(ushort *)param_5 = (ushort)iVar7;
                          }
                          if (((*(ushort *)pdVar19 & 0x8000) == 0) &&
                             (iVar7 = aiStack_148[*(ushort *)pdVar19], iVar7 != -1)) {
                            *(ushort *)pdVar19 = (ushort)iVar7;
                          }
                          if (((*puVar12 & 0x8000) == 0) &&
                             (iVar7 = aiStack_148[*puVar12], iVar7 != -1)) {
                            *puVar12 = (ushort)iVar7;
                          }
                          if (((*puVar11 & 0x8000) == 0) &&
                             (iVar7 = aiStack_148[*puVar11], iVar7 != -1)) {
                            *puVar11 = (ushort)iVar7;
                          }
                          if ((*pcVar10 != '\0') && (iVar7 = aiStack_148[*puVar20], iVar7 != -1)) {
                            *puVar20 = (ushort)iVar7;
                          }
                          if (((*puVar30 & 0x8000) == 0) &&
                             (iVar7 = aiStack_148[*puVar30], iVar7 != -1)) {
                            *puVar30 = (ushort)iVar7;
                          }
                          if (((*puVar29 & 0x8000) == 0) &&
                             (iVar7 = aiStack_148[*puVar29], iVar7 != -1)) {
                            *puVar29 = (ushort)iVar7;
                          }
                          if (((*puVar22 & 0x8000) == 0) &&
                             (iVar7 = aiStack_148[*puVar22], iVar7 != -1)) {
                            *puVar22 = (ushort)iVar7;
                          }
                        }
                        goto LAB_000bf33c;
                      }
                      bVar2 = *(byte *)puVar28;
                      if (bVar2 == 2) {
LAB_000bf224:
                        iVar7 = aiStack_148[*(ushort *)pdVar16];
                        if (iVar7 != -1) {
                          *(ushort *)pdVar16 = (ushort)iVar7;
                        }
                      }
                      else if (bVar2 < 3) {
                        if (bVar2 == 1) {
LAB_000bf20c:
                          iVar7 = aiStack_148[*(ushort *)pdVar27];
                          if (iVar7 != -1) {
                            *(ushort *)pdVar27 = (ushort)iVar7;
                          }
                          goto LAB_000bf224;
                        }
                      }
                      else if (bVar2 < 5) goto LAB_000bf20c;
LAB_000bf33c:
                      loopIndex = loopIndex + 1;
                      pdVar14 = pdVar14 + 0x12;
                      pdVar16 = pdVar16 + 0x12;
                      puVar22 = puVar22 + 0x24;
                      puVar23 = puVar23 + 0x24;
                      pcVar24 = pcVar24 + 0x48;
                      puVar25 = puVar25 + 0x24;
                      pcVar26 = pcVar26 + 0x48;
                      pdVar27 = pdVar27 + 0x12;
                      puVar28 = puVar28 + 0x24;
                      puVar29 = puVar29 + 0x24;
                      puVar30 = puVar30 + 0x24;
                      puVar20 = puVar20 + 0x24;
                      pcVar10 = pcVar10 + 0x48;
                      puVar11 = puVar11 + 0x24;
                      puVar12 = puVar12 + 0x24;
                      pdVar19 = pdVar19 + 0x12;
                      param_5 = param_5 + 0x12;
                      pcVar17 = pcVar17 + 0x48;
                    } while (loopIndex <= psnProgramWord8);
                  }
                }
                ((int (*)())FUN_000be460)(psnProgram,param_2,param_3,1,param_5,aiStack_148,pdVar16);
                uVar9 = 0;
              }
              else {
                uVar9 = 0x80000013;
              }
            }
            else {
              uVar9 = 0x80000012;
            }
          }
          else {
            uVar9 = 0x80000017;
          }
        }
        else {
          uVar9 = 0x80000016;
        }
      }
      else {
        uVar9 = 0x80000015;
      }
    }
    else {
      uVar9 = 0x80000014;
    }
  }
  else {
    uVar9 = 0x80000011;
  }
  return uVar9;
}

/* FUN_000bf400 @ 0xbf400 (1260 bytes) */
int FUN_000bf400(param_1, param_2, unusedArgR5, unusedArgR6, unusedArgR7, unusedArgR8, unusedArgR9)
  int param_1;
  uint param_2;
  undefined4 unusedArgR5;
  undefined4 unusedArgR6;
  undefined4 unusedArgR7;
  undefined4 unusedArgR8;
  undefined4 unusedArgR9;
{
  uint loopIndex3;
  uint loopIndex2;
  bool bVar1;
  byte bVar2;
  bool bVar3;
  uint uVar4;
  char cVar5;
  char cVar6;
  char cVar10;
  uint uVar7;
  int iVar8;
  int *piVar9;
  uint loopIndex;
  uint uVar12;
  uint uVar13;
  uint *puVar14;
  uint uVar15;
  undefined1 *puVar16;
  uint uVar17;
  uint uVar18;
  byte bVar19;
  
  if (param_2 <= (*(byte *)(param_1 + 0xf) & 0xf)) {
    return;
  }
  uVar12 = *(uint *)(param_1 + 8);
  if ((*(int *)(param_1 + 0x48) == 1) && (uVar12 != 0)) {
    piVar9 = (int *)(param_1 + 0x90);
    loopIndex = 1;
    do {
      loopIndex = loopIndex + 1;
      if (*piVar9 != 1) goto LAB_000bf474;
      piVar9 = piVar9 + 0x12;
    } while (loopIndex <= uVar12);
LAB_000bf44c:
    bVar19 = 0;
    uVar18 = 0;
    bVar3 = true;
  }
  else {
    loopIndex = 1;
LAB_000bf474:
    if (uVar12 < loopIndex) goto LAB_000bf44c;
    bVar19 = 0;
    bVar3 = true;
    puVar14 = (uint *)(param_1 + loopIndex * 0x48);
    uVar17 = 0;
    loopIndex3 = 0;
    bVar1 = false;
    uVar18 = 0;
    uVar15 = loopIndex;
    do {
      uVar4 = *puVar14;
      if (uVar4 < 5) {
        if (uVar4 < 3) {
          if ((uVar4 == 2) &&
             (bVar19 = bVar19 | *(byte *)(puVar14 + 1) | *(byte *)((int)puVar14 + 0x1b),
             *(char *)((int)puVar14 + 0x1a) != '\0')) {
            uVar18 = uVar18 | -(uint)(puVar14[7] & 0xffff00) >> 0x1f;
          }
        }
        else {
          bVar19 = bVar19 | *(byte *)(puVar14 + 1);
        }
      }
      else if ((uVar4 == 5) && (bVar19 = bVar19 | *(byte *)(puVar14 + 1), bVar3)) {
        if ((*(char *)((int)puVar14 + 0xe) != '\0') || (*(char *)((int)puVar14 + 0x11) != '\0')) {
          bVar1 = true;
        }
        uVar4 = puVar14[4] & 0xff00ff00;
        if ((uVar4 != 0) &&
           ((*(ushort *)(puVar14 + 3) < loopIndex3 || (*(char *)((int)puVar14 + 0x19) != '\0')))) {
          bVar1 = true;
        }
        cVar5 = *(char *)(puVar14 + 5);
        cVar6 = *(char *)((int)puVar14 + 0x15);
        cVar10 = cVar5;
        if ((uVar4 != 0) && (cVar10 = cVar6, uVar4 == 0x100ff00)) {
          cVar5 = cVar6;
        }
        cVar6 = cVar10;
        if ((cVar5 == '\x01') || (cVar6 = cVar5, cVar5 != '\0')) {
          if (cVar6 == '\x02') goto LAB_000bf5b4;
          if (cVar6 == '\x01') {
            uVar17 = uVar17 - *(byte *)((int)puVar14 + 0x13);
          }
        }
        else if (cVar10 == '\x02') {
LAB_000bf5b4:
          uVar17 = uVar17 + 1;
        }
        bVar3 = !bVar1;
        if (4 < uVar17) {
          bVar1 = true;
          bVar3 = false;
        }
      }
      uVar15 = uVar15 + 1;
      loopIndex3 = loopIndex3 + 1;
      puVar14 = puVar14 + 0x12;
    } while (uVar15 <= uVar12);
    if (loopIndex3 != 0) goto LAB_000bf45c;
  }
  loopIndex3 = 1;
LAB_000bf45c:
  if ((*(short *)(param_1 + 0x20) == 0) && (*(short *)(param_1 + 0x12) == 0)) {
    *(short *)(param_1 + 0x12) = (short)loopIndex3 + -1;
  }
  if (!bVar3) {
    *(undefined2 *)(param_1 + 0x28) = 1;
  }
  if ((*(short *)(param_1 + 0x28) != 0) && (*(short *)(param_1 + 0x22) == 0)) {
    *(undefined2 *)(param_1 + 0x22) = 1;
  }
  if (loopIndex <= uVar12) {
    bVar1 = bVar19 != 0;
    puVar14 = (uint *)(param_1 + loopIndex * 0x48);
    loopIndex2 = 0;
    puVar16 = (undefined1 *)((int)puVar14 + -3);
    uVar15 = 100000;
    uVar13 = loopIndex;
    do {
      uVar7 = *puVar14;
      uVar4 = uVar15;
      if (uVar7 < 5) {
        if (uVar7 < 3) {
          if (uVar7 == 2) {
            if (uVar18 == 0) {
              *(undefined1 *)((int)puVar14 + 0x1d) = 7;
              *(undefined1 *)((int)puVar14 + 0x1e) = 1;
              puVar14[5] = puVar14[5] & 0xffff | 0x1b1b0000;
            }
            bVar2 = *(byte *)((int)puVar14 + 0x1f);
            if (bVar2 != 0) {
              if ((bVar2 & 2) != 0) {
                puVar14[5] = puVar14[5] >> 2 & 0x300000 | puVar14[5] & 0xffcfffff;
              }
              if ((bVar2 & 4) != 0) {
                puVar14[5] = puVar14[5] >> 4 & 0xc0000 | puVar14[5] & 0xfff3ffff;
              }
              if ((bVar2 & 8) != 0) {
                puVar14[5] = puVar14[5] >> 6 & 0x30000 | puVar14[5] & 0xfffcffff;
              }
            }
            uVar4 = uVar13;
            if (((!bVar1) && (*(char *)(puVar14 + 8) != '\0')) && (uVar15 != 100000)) {
              iVar8 = param_1 + uVar15 * 0x48;
              *(undefined1 *)(iVar8 + 4) = 1;
              *(undefined1 *)(iVar8 + 0x1b) = 1;
              *(undefined1 *)(puVar14 + 1) = 1;
            }
          }
        }
        else {
          if (((*(char *)((int)puVar14 + 0x15) == '\0') && ((puVar14[8] & 0xff00ff) == 0)) &&
             (loopIndex2 != *(ushort *)(param_1 + 0x12))) {
            *puVar14 = 4;
          }
          if ((bVar1) || (uVar15 == 100000)) {
LAB_000bf860:
            uVar4 = 100000;
          }
          else {
            iVar8 = param_1 + uVar15 * 0x48;
            *(undefined1 *)(iVar8 + 4) = 1;
            *(undefined1 *)(iVar8 + 0x1b) = 1;
            *(undefined1 *)(puVar14 + 1) = 1;
            uVar4 = 100000;
          }
        }
      }
      else if (uVar7 == 5) {
        if ((!bVar1) && (uVar15 != 100000)) {
          iVar8 = param_1 + uVar15 * 0x48;
          *(undefined1 *)(iVar8 + 4) = 1;
          *(undefined1 *)(iVar8 + 0x1b) = 1;
          *(undefined1 *)(puVar14 + 1) = 1;
        }
        if ((((byte)(*(byte *)((int)puVar14 + 0x12) & 0xf0) ==
              (byte)(*(byte *)((int)puVar14 + 0x12) << 4)) || (loopIndex2 == 0)) ||
           (1 < *(int *)(puVar16 + -0x45) - 3U)) goto LAB_000bf860;
        *puVar16 = 1;
        uVar4 = 100000;
      }
      uVar13 = uVar13 + 1;
      loopIndex2 = loopIndex2 + 1;
      puVar14 = puVar14 + 0x12;
      puVar16 = puVar16 + 0x48;
      uVar15 = uVar4;
    } while (uVar13 <= uVar12);
    if (((loopIndex2 != 0) &&
        (iVar8 = (*(ushort *)(param_1 + 0x12) + loopIndex) * 0x48, *(int *)(param_1 + iVar8) == 3)) &&
       (bVar19 == 0)) {
      *(undefined1 *)(param_1 + iVar8 + 4) = 1;
    }
  }
  if (((uVar18 != 0) || (bVar19 != 0)) || (*(short *)(param_1 + 0x20) != 0)) {
    param_2 = param_2 | param_2 << 4;
  }
  *(char *)(param_1 + 0xf) = (char)param_2;
  return;
}

/* FUN_000bf910 @ 0xbf910 (796 bytes) */
int FUN_000bf910(swizzleCode, selectX, selectY, selectZ)
  uint *swizzleCode;
  undefined4 *selectX;
  undefined4 *selectY;
  undefined4 *selectZ;
{
  uint swizzleCodeWord0;
  undefined4 uVar2;
  
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
    uVar2 = 1;
    break;
  case 3:
    uVar2 = 2;
    break;
  case 4:
    *swizzleCode = 1;
    *selectX = 0;
    *selectY = 1;
    *selectZ = 2;
    return;
  case 5:
    uVar2 = 0;
    goto LAB_000bfac8;
  case 6:
    *swizzleCode = 1;
    *selectX = 1;
    *selectY = 1;
    *selectZ = 1;
    return;
  case 7:
    uVar2 = 2;
    goto LAB_000bfac8;
  case 8:
    *swizzleCode = 2;
    *selectX = 0;
    *selectY = 1;
    *selectZ = 2;
    return;
  case 9:
    uVar2 = 0;
    goto LAB_000bfae4;
  case 10:
    uVar2 = 1;
    goto LAB_000bfae4;
  case 0xb:
    *swizzleCode = 2;
    *selectX = 2;
    *selectY = 2;
    *selectZ = 2;
    return;
  case 0xc:
    uVar2 = 3;
    break;
  case 0xd:
    uVar2 = 3;
LAB_000bfac8:
    *swizzleCode = 1;
    *selectX = uVar2;
    *selectY = uVar2;
    *selectZ = uVar2;
    return;
  case 0xe:
    uVar2 = 3;
LAB_000bfae4:
    *swizzleCode = 2;
    *selectX = uVar2;
    *selectY = uVar2;
    *selectZ = uVar2;
    return;
  case 0xf:
    *swizzleCode = 3;
    *selectX = 0;
    *selectY = 1;
    *selectZ = 2;
    return;
  case 0x10:
    uVar2 = 0;
    goto LAB_000bfb34;
  case 0x11:
    uVar2 = 1;
    goto LAB_000bfb34;
  case 0x12:
    uVar2 = 2;
LAB_000bfb34:
    *swizzleCode = 3;
    *selectX = uVar2;
    *selectY = uVar2;
    *selectZ = uVar2;
    return;
  case 0x13:
    *swizzleCode = 3;
    *selectX = 3;
    *selectY = 3;
    *selectZ = 3;
    return;
  case 0x14:
    uVar2 = 4;
    break;
  case 0x15:
    uVar2 = 6;
    break;
  case 0x16:
    uVar2 = 5;
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
  *selectX = uVar2;
  *selectY = uVar2;
  *selectZ = uVar2;
  return;
}

/* FUN_000bfcc0 @ 0xbfcc0 (440 bytes) */
int FUN_000bfcc0(swizzleCode, channelSelect)
  uint *swizzleCode;
  undefined4 *channelSelect;
{
  uint uVar1;
  
  uVar1 = *swizzleCode;
  if ((uVar1 & 0x80) == 0) {
    switch(uVar1) {
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
  *swizzleCode = uVar1 & 0xffffff7f;
  return;
}

/* FUN_000bfed0 @ 0xbfed0 (2464 bytes) */
int FUN_000bfed0(psnProgram, rsWords, programImage)
  int psnProgram;
  uint *rsWords;
  uint *programImage;
{
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
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  byte bVar11;
  byte bVar12;
  byte bVar13;
  byte bVar14;
  byte bVar15;
  byte bVar16;
  ushort instShort3;
  ushort uVar18;
  ushort uVar19;
  ushort instShort7;
  ushort uVar21;
  ushort instShort3_2;
  ushort instShort6;
  ushort uVar24;
  bool bVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  uint uVar37;
  uint uVar38;
  int *nextScanInst;
  uint uVar40;
  uint uVar41;
  uint uVar42;
  uint uVar43;
  uint uVar44;
  undefined4 staleArgR6;
  undefined4 staleArgR7;
  int *piVar45;
  undefined4 staleArgR8;
  int *scanInst;
  uint uVar47;
  uint uVar48;
  int iVar49;
  uint uVar50;
  uint uVar51;
  int *prevScanInst;
  int iVar53;
  uint uVar54;
  uint uVar55;
  int iVar56;
  int iVar57;
  byte bVar58;
  uint loopIndex2;
  uint *outCursor;
  uint local_78;
  uint local_74;
  uint local_70;
  uint local_6c;
  uint *local_68;
  uint *local_64;
  uint *local_60;
  
  outCursor = programImage;
  ((int (*)())FUN_000c5e60)(psnProgram);
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
  ((int (*)())FUN_000bf400)(psnProgram,1,outCursor,staleArgR6,staleArgR7,staleArgR8,(uint)*(ushort *)(psnProgram + 0x20));
  psnProgramWord8 = *(uint *)(psnProgram + 8);
  if ((*(int *)(psnProgram + 0x48) == 1) && (psnProgramWord8 != 0)) {
    scanInst = (int *)(psnProgram + 0x90);
    loopIndex2 = 1;
    nextScanInst = scanInst;
    uVar43 = 0;
    prevScanInst = (int *)(psnProgram + 0x48);
    do {
      piVar45 = nextScanInst;
      uVar48 = uVar43;
      if ((prevScanInst[2] & 0xff00ffU) != 0) {
        uVar48 = uVar43 + 1;
        rsWords[uVar43 + 1] = 0;
        prevScanInstByte2 = *(byte *)(prevScanInst + 2);
        rsWords[uVar43 + 1] = prevScanInstByte2 & 0xf;
        uVar40 = (*(byte *)((int)prevScanInst + 9) & 1) << 4 | prevScanInstByte2 & 0xf;
        rsWords[uVar43 + 1] = uVar40;
        uVar40 = (*(byte *)((int)prevScanInst + 10) & 0xf) << 0xc | uVar40;
        rsWords[uVar43 + 1] = uVar40;
        uVar40 = (*(byte *)((int)prevScanInst + 0xb) & 3) << 0x10 | uVar40;
        rsWords[uVar43 + 1] = uVar40;
        uVar40 = (*(byte *)(prevScanInst + 3) & 1) << 0x19 | uVar40;
        rsWords[uVar43 + 1] = uVar40;
        uVar40 = (*(ushort *)(prevScanInst + 1) & 0x7f) << 5 | uVar40;
        rsWords[uVar43 + 1] = uVar40;
        rsWords[uVar43 + 1] = (*(ushort *)((int)prevScanInst + 6) & 0x7f) << 0x12 | uVar40;
      }
      loopIndex2 = loopIndex2 + 1;
      if (*scanInst != 1) break;
      scanInst = scanInst + 0x12;
      nextScanInst = piVar45 + 0x12;
      uVar43 = uVar48;
      prevScanInst = piVar45;
    } while (loopIndex2 <= psnProgramWord8);
    uVar43 = uVar48 & 0xff;
    if (uVar48 == 0) goto LAB_000c004c;
  }
  else {
    loopIndex2 = 1;
LAB_000c004c:
    uVar43 = 1;
    rsWords[1] = 0;
  }
  uVar43 = uVar43 - 1 & 0xf;
  *rsWords = uVar43;
  *rsWords = (*(byte *)(psnProgram + 0xd) & 7) << 5 | uVar43;
  if (psnProgramWord8 < loopIndex2) {
    iVar56 = 0;
    bVar58 = 0;
    iVar53 = 0;
    iVar49 = 1;
  }
  else {
    local_68 = &local_6c;
    local_60 = &local_70;
    bVar58 = 0;
    inst = (uint *)(loopIndex2 * 0x48 + psnProgram);
    local_64 = &local_74;
    bVar25 = true;
    loopIndex = 0;
    iVar56 = 0;
    do {
      iVar57 = iVar56;
      instWord0 = *inst;
      uVar48 = 0;
      if (instWord0 < 5) {
        if (instWord0 < 3) {
          if (instWord0 == 2) {
            uVar24 = *(ushort *)((int)inst + 0xe);
            instShort3 = *(ushort *)(inst + 3);
            bVar25 = true;
            instWord14 = inst[5];
            bVar1 = *(byte *)((int)inst + 6);
            bVar2 = *(byte *)((int)inst + 7);
            instByte2 = *(byte *)(inst + 2);
            bVar4 = *(byte *)((int)inst + 9);
            bVar5 = *(byte *)((int)inst + 0xb);
            bVar6 = *(byte *)((int)inst + 0x1d);
            bVar7 = *(byte *)((int)inst + 0x1e);
            instShort4_2 = *(ushort *)(inst + 4);
            uVar19 = *(ushort *)((int)inst + 0x12);
            instByte1_2 = *(byte *)(inst + 1);
            bVar9 = *(byte *)((int)inst + 5);
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
                 (instShort3 & 0x7f) << 0x10 | uVar24 >> 7 & 0x80 | uVar24 & 0x7f;
            uVar48 = (bVar7 & 1) << 0xe |
                     (bVar6 & 7) << 0xb |
                     (bVar5 & 1) << 10 |
                     (bVar4 & 1) << 7 |
                     (instByte2 & 1) << 0x16 |
                     (bVar2 & 7) << 0x19 |
                     (bVar1 & 1) << 6 | (bVar9 & 7) << 3 | (instByte1_2 & 1) << 2 | 3;
            *(uint *)(loopIndex + programImage[4] + 0xc) =
                 instWord14 << 0x1e |
                 (instWord14 & 0xc) << 0x1a |
                 (instWord14 & 0x30) << 0x16 |
                 (instWord14 & 0xc0) << 0x12 |
                 (instWord14 & 0x300) << 6 |
                 (instWord14 & 0xc00) << 2 |
                 instWord14 >> 2 & 0xc00 |
                 instWord14 >> 6 & 0x300 |
                 (uVar19 & 0x4000) << 9 |
                 (uVar19 & 0x7f) << 0x10 | instShort4_2 >> 7 & 0x80 | instShort4_2 & 0x7f;
            *(undefined4 *)(loopIndex + programImage[4] + 0x10) = 0;
            *(undefined4 *)(loopIndex + programImage[4] + 0x14) = 0;
          }
        }
        else {
          uVar24 = *(ushort *)((int)inst + 0xe);
          uVar40 = 0xffffff80;
          uVar48 = (*(byte *)(inst + 0x11) & 3) << 0x17 |
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
          if ((uVar24 & 0x2000) == 0) {
            uVar40 = 0;
          }
          instShort4 = *(ushort *)(inst + 4);
          uVar43 = 0xffffff80;
          if ((instShort4 & 0x2000) == 0) {
            uVar43 = 0;
          }
          uVar18 = *(ushort *)((int)inst + 0x12);
          uVar47 = 0xffffff80;
          if ((uVar18 & 0x2000) == 0) {
            uVar47 = 0;
          }
          uVar19 = *(ushort *)((int)inst + 0x1a);
          instBytec = *(byte *)(inst + 0xc);
          uVar50 = 0xffffff80;
          if ((uVar19 & 0x2000) == 0) {
            uVar50 = 0;
          }
          instShort7 = *(ushort *)(inst + 7);
          uVar54 = 0xffffff80;
          if ((instShort7 & 0x2000) == 0) {
            uVar54 = 0;
          }
          uVar21 = *(ushort *)((int)inst + 0x1e);
          uVar51 = 0xffffff80;
          if ((uVar21 & 0x2000) == 0) {
            uVar51 = 0;
          }
          local_6c = (uint)*(byte *)((int)inst + 0x2a);
          bVar2 = *(byte *)((int)inst + 0x3f);
          instWord24 = inst[9];
          local_70 = instWord24 >> 0x17 & 7;
          local_78 = instWord24 >> 0x1d;
          local_74 = instWord24 >> 0x1a & 7;
          ((int (*)())FUN_000bf910)(local_68,&local_78,local_64,local_60);
          uVar41 = local_6c & 3;
          uVar26 = local_78 & 7;
          uVar27 = local_74 & 7;
          instWord24_2 = inst[9];
          uVar28 = local_70 & 7;
          local_6c = instWord24_2 >> 7 & 7;
          local_74 = instWord24_2 >> 0xd & 7;
          local_78 = instWord24_2 >> 10 & 7;
          local_70 = (uint)*(byte *)((int)inst + 0x2b);
          ((int (*)())FUN_000bf910)(local_60,local_64,&local_78,local_68);
          bVar3 = *(byte *)((int)inst + 0x2d);
          bVar4 = *(byte *)((int)inst + 0x2e);
          bVar5 = *(byte *)((int)inst + 0x32);
          bVar6 = *(byte *)((int)inst + 0x16);
          bVar7 = *(byte *)((int)inst + 0x45);
          uVar44 = local_70 & 3;
          uVar29 = local_74 & 7;
          uVar30 = local_78 & 7;
          uVar31 = local_6c & 7;
          local_78 = (uint)*(byte *)((int)inst + 0x36);
          local_6c = (uint)*(byte *)((int)inst + 0x39);
          ((int (*)())FUN_000bfcc0)(local_68,&local_78);
          uVar32 = local_6c & 3;
          uVar33 = local_78 & 7;
          local_6c = (uint)*(byte *)((int)inst + 0x37);
          local_78 = (uint)*(byte *)((int)inst + 0x3a);
          ((int (*)())FUN_000bfcc0)(&local_78,local_68);
          instBytef = *(byte *)(inst + 0xf);
          bVar9 = *(byte *)((int)inst + 0x3d);
          instShort3_2 = *(ushort *)(inst + 3);
          bVar10 = *(byte *)((int)inst + 0x41);
          bVar11 = *(byte *)((int)inst + 0x22);
          instShort6 = *(ushort *)(inst + 6);
          uVar34 = local_78 & 3;
          bVar12 = *(byte *)((int)inst + 0x23);
          instByte10 = *(byte *)(inst + 0x10);
          uVar35 = local_6c & 7;
          bVar14 = *(byte *)((int)inst + 0x31);
          instWord28 = inst[10];
          local_78 = instWord28 >> 0x1d;
          local_70 = instWord28 >> 0x17 & 7;
          local_74 = instWord28 >> 0x1a & 7;
          local_6c = (uint)*(byte *)(inst + 0xb);
          ((int (*)())FUN_000bf910)(local_68,&local_78,local_64,local_60);
          uVar42 = local_6c & 3;
          uVar36 = local_78 & 7;
          uVar37 = local_74 & 7;
          local_78 = (uint)*(byte *)(inst + 0xe);
          uVar38 = local_70 & 7;
          local_70 = (uint)*(byte *)((int)inst + 0x3b);
          ((int (*)())FUN_000bfcc0)(local_60,&local_78);
          bVar25 = false;
          bVar15 = *(byte *)((int)inst + 0x2f);
          bVar16 = *(byte *)((int)inst + 0x3e);
          *(uint *)(loopIndex + programImage[4] + 4) =
               (uint)instBytec << 0x1e |
               (uVar18 & 0x4000) << 0xf |
               (uVar18 & 0x8000) << 0xd |
               (uVar47 & 0xff | uVar18 & 0x7f) << 0x14 |
               (instShort4 & 0x4000) << 5 |
               (instShort4 & 0x8000) << 3 |
               (uVar43 & 0xff | instShort4 & 0x7f) << 10 |
               uVar24 >> 5 & 0x200 | uVar24 >> 7 & 0x100 | uVar40 & 0xff | uVar24 & 0x7f;
          *(uint *)(loopIndex + programImage[4] + 8) =
               (uint)bVar2 << 0x1e |
               (uVar21 & 0x4000) << 0xf |
               (uVar21 & 0x8000) << 0xd |
               (uVar51 & 0xff | uVar21 & 0x7f) << 0x14 |
               (instShort7 & 0x4000) << 5 |
               (instShort7 & 0x8000) << 3 |
               (uVar54 & 0xff | instShort7 & 0x7f) << 10 |
               uVar19 >> 5 & 0x200 | uVar19 >> 7 & 0x100 | uVar50 & 0xff | uVar19 & 0x7f;
          *(uint *)(loopIndex + programImage[4] + 0xc) =
               (uint)bVar7 << 0x1f |
               (bVar6 & 3) << 0x1d |
               (bVar5 & 7) << 0x1a |
               (bVar4 & 3) << 0x18 |
               (bVar3 & 3) << 0xb |
               uVar31 << 0x15 |
               uVar30 << 0x12 |
               uVar29 << 0xf | uVar44 << 0xd | uVar28 << 8 | uVar27 << 5 | uVar26 << 2 | uVar41;
          *(uint *)(loopIndex + programImage[4] + 0x10) =
               instShort6 >> 3 & 0x800 |
               (instShort6 & 0x7f) << 4 |
               instByte10 & 0xf |
               (uint)bVar12 << 0x1f |
               (bVar11 & 3) << 0x1d |
               (bVar10 & 7) << 0x1a |
               (bVar9 & 3) << 0x18 |
               (instBytef & 3) << 0x11 | uVar35 << 0x15 | uVar34 << 0x13 | uVar33 << 0xe | uVar32 << 0xc
          ;
          *(uint *)(loopIndex + programImage[4] + 0x14) =
               (uint)bVar16 << 0x1e |
               (bVar15 & 3) << 0x17 |
               (local_78 & 7) << 0x1b |
               (local_70 & 3) << 0x19 |
               uVar38 << 0x14 |
               uVar37 << 0x11 |
               uVar36 << 0xe |
               uVar42 << 0xc | instShort3_2 >> 3 & 0x800 | (instShort3_2 & 0x7f) << 4 | bVar14 & 0xf;
          if (*inst == 3) {
            bVar58 = bVar58 | *(byte *)((int)inst + 0x23);
          }
        }
      }
      else if (instWord0 == 5) {
        bVar1 = *(byte *)((int)inst + 0xe);
        bVar2 = *(byte *)((int)inst + 0xf);
        bVar25 = false;
        instByte4 = *(byte *)(inst + 4);
        bVar4 = *(byte *)((int)inst + 0x11);
        bVar5 = *(byte *)((int)inst + 0x12);
        bVar6 = *(byte *)((int)inst + 0x13);
        instByte1 = *(byte *)(inst + 1);
        bVar8 = *(byte *)((int)inst + 5);
        bVar9 = *(byte *)((int)inst + 6);
        bVar10 = *(byte *)((int)inst + 0xb);
        bVar11 = *(byte *)((int)inst + 0x17);
        instShort3_3 = *(ushort *)(inst + 3);
        bVar12 = *(byte *)((int)inst + 0x19);
        bVar13 = *(byte *)((int)inst + 0x16);
        instByte5 = *(byte *)(inst + 5);
        instByte6 = *(byte *)(inst + 6);
        bVar16 = *(byte *)((int)inst + 0x15);
        *(undefined4 *)(programImage[4] + loopIndex + 4) = 0;
        uVar48 = (bVar10 & 1) << 10 | (bVar9 & 1) << 6 | (bVar8 & 7) << 3 | (instByte1 & 1) << 2 | 2;
        *(uint *)(programImage[4] + loopIndex + 8) =
             (bVar13 & 1) << 0x1c |
             (bVar16 & 3) << 0x1a |
             (instByte5 & 3) << 0x18 |
             (bVar6 & 0x1f) << 0x10 |
             (uint)bVar5 << 8 | (bVar4 & 3) << 6 | (instByte4 & 1) << 5 | (bVar2 & 1) << 4 | bVar1 & 7;
        *(uint *)(programImage[4] + loopIndex + 0xc) =
             (uint)bVar12 << 0x1f | (instShort3_3 & 0x1ff) << 0x10 | (instByte6 & 0x1f) << 8 | bVar11 & 0x1f;
        *(undefined4 *)(programImage[4] + loopIndex + 0x10) = 0;
        *(undefined4 *)(programImage[4] + loopIndex + 0x14) = 0;
      }
      loopIndex2 = loopIndex2 + 1;
      iVar56 = iVar57 + 1;
      inst = inst + 0x12;
      *(uint *)(programImage[4] + loopIndex) = uVar48;
      loopIndex = loopIndex + 0x18;
    } while (loopIndex2 <= psnProgramWord8);
    iVar49 = iVar56;
    if (!bVar25) goto LAB_000c07dc;
    iVar53 = iVar56 * 0x18;
    iVar49 = iVar57 + 2;
  }
  *(undefined4 *)(programImage[4] + iVar53) = 0;
  *(undefined4 *)(iVar53 + programImage[4] + 4) = 0;
  *(undefined4 *)(iVar53 + programImage[4] + 8) = 0;
  *(undefined4 *)(iVar53 + programImage[4] + 0xc) = 0;
  *(undefined4 *)(iVar53 + programImage[4] + 0x10) = 0;
  *(undefined4 *)(iVar53 + programImage[4] + 0x14) = 0;
  *(uint *)(iVar53 + programImage[4]) = *(uint *)(iVar53 + programImage[4]) & 0xfffffffc | 1;
  *(uint *)(iVar53 + programImage[4]) = *(uint *)(iVar53 + programImage[4]) | 4;
  if ((iVar56 != 0) && ((uint)*(ushort *)(psnProgram + 0x12) == iVar56 - 1U)) {
    *(short *)(psnProgram + 0x12) = (short)iVar56;
  }
LAB_000c07dc:
  programImage[2] = 0;
  programImage[3] = (iVar49 + -1) * 0x10000 & 0x1ff0000;
  uVar55 = *(ushort *)(psnProgram + 0x10) & 0x1ff;
  programImage[2] = uVar55;
  psnProgramShort12 = *(ushort *)(psnProgram + 0x12);
  programImage[1] = 0;
  programImage[2] = (psnProgramShort12 & 0x1ff) << 0x10 | uVar55;
  psnProgramShort28 = *(ushort *)(psnProgram + 0x28);
  *programImage = 0;
  programImage[1] = (uint)psnProgramShort28 << 0x1f;
  psnProgramShort22 = *(ushort *)(psnProgram + 0x22);
  programImage[5] = (uint)(bVar58 != 0);
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
  int iVar6;
  uint sourceModifierCopy;
  uint uVar8;
  ushort *propagateHalf;
  ushort source1Flags;
  uint uVar11;
  ushort uVar13;
  uint addressSlot;
  ushort sourceSwizzleWord;
  uint rgbOpTableOffset;
  ushort *sourceFlagsPtr;
  ushort *puVar17;
  int halfCounter3;
  ushort *puVar19;
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
  iVar6 = *(int *)(decoded + 0x48);
  if (entryMode != 1) {
    if (entryMode == 0) {
      rsWordPtr = iVar6 * 4 + wordsMode0;
      decoded[2] = (ushort)((uint)*(undefined4 *)(rsWordPtr + 4) >> 0x12) & 0x7f;
      decoded[0x40] = *(byte *)(rsWordPtr + 6) >> 4 | 0xc000;
      if ((*(ushort *)(rsWordPtr + 4) & 3) != 0) {
        decoded[10] = 0xf;
        decoded[3] = 0xf;
        uVar13 = *(ushort *)(rsWordPtr + 4) & 3;
        if ((uVar13 == 2) || (uVar13 == 3)) {
          decoded[0x1d] = uVar13;
        }
      }
      iVar6 = iVar6 * 4 + wordsMode0;
      *(undefined4 *)(decoded + 0x16) =
           *(undefined4 *)((*(uint *)(iVar6 + 4) >> 0x19 & 0x7c) + 0x1dc198);
      decoded[0x22] = (ushort)(*(uint *)(iVar6 + 4) >> 5) & 0x7f;
      decoded[0x43] = (ushort)*(undefined4 *)(iVar6 + 4) & 0xf | 0xa000;
      rsWord = *(uint *)(iVar6 + 4);
      if ((rsWord & 0x10) != 0) {
        decoded[0x2d] = 0xf;
        decoded[0x23] = 0xf;
        rsWord = *(uint *)(iVar6 + 4);
      }
      *(undefined4 *)(decoded + 0x36) = *(undefined4 *)((rsWord >> 0x17 & 4) + 0x1dc198);
      return;
    }
    if (entryMode != 2) {
      return;
    }
    groupCounter = 0;
    iVar6 = iVar6 * 4 + wordsMode2;
    alphaAddrWord = *(uint *)(iVar6 + 0x198);
    rgbAddrWord = *(uint *)(iVar6 + 0x98);
    uVar8 = *(uint *)(iVar6 + 0x398);
    rgbInstWord = *(uint *)(iVar6 + 0x298);
    decoded[0x40] = (ushort)rgbAddrWord & 0x3f;
    decoded[0x43] = (ushort)alphaAddrWord & 0x3f;
    decoded[0x41] = (ushort)(rgbAddrWord >> 6) & 0x3f;
    decoded[0x42] = (ushort)(rgbAddrWord >> 0xc) & 0x3f;
    decoded[0x44] = (ushort)(alphaAddrWord >> 6) & 0x3f;
    decoded[0x45] = (ushort)(alphaAddrWord >> 0xc) & 0x3f;
    addressSlotOffset = 0x80;
    do {
      puVar19 = (ushort *)((int)decoded + addressSlotOffset);
      slotCounter = 0;
      do {
        if (0x1f < *puVar19) {
          *puVar19 = *puVar19 - 0x20 | 0x8000;
        }
        loopContinue = slotCounter != 2;
        puVar19 = puVar19 + 1;
        slotCounter = slotCounter + 1;
      } while (loopContinue);
      loopContinue = groupCounter != 1;
      addressSlotOffset = addressSlotOffset + 6;
      groupCounter = groupCounter + 1;
    } while (loopContinue);
    groupSetupCounter = 0;
    puVar19 = decoded;
    puVar17 = decoded;
    do {
      puVar17[0x3a] = 1;
      puVar17[0x1a] = 1;
      defaultOperandWord2 = (*(unsigned int *)&DAT_001dbf94);
      loopContinue = groupSetupCounter != 2;
      puVar17 = puVar17 + 1;
      groupSetupCounter = groupSetupCounter + 1;
      *(undefined4 *)(puVar19 + 4) = (*(unsigned int *)&DAT_001dbf94);
      *(undefined4 *)(puVar19 + 0x24) = defaultOperandWord2;
      puVar19 = puVar19 + 2;
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
      puVar19 = decoded + 4;
      rgbSourcesLeft = rgbOpTableOffset;
      if (rgbOpTableOffset == 0) {
        rgbSourcesLeft = 1;
      }
      do {
        sourceIndex = sourceIndex + 1;
        *(undefined4 *)puVar19 = *(undefined4 *)(sourceSelectCode * 4 + 0x1dc0d8);
        puVar19[1] = (ushort)(sourceModifierCopy << 0xc) | puVar19[1];
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
        puVar19 = puVar19 + 2;
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
    alphaOpTableOffset = uVar8 >> 0x15 & 0x3c;
    decoded[0x34] = *(ushort *)(alphaOpTableOffset + 0x1dc098);
    alphaOpTableOffset = (uint)*(ushort *)(alphaOpTableOffset + 0x1dc09a);
    if ((rgbInstWord & 0x7800000) == 0x1000000) {
      if (alphaOpTableOffset < 2) {
        alphaOpTableOffset = 2;
      }
    }
    else if (alphaOpTableOffset == 0) {
LAB_000c1cec:
      decoded[0x35] = (ushort)(uVar8 >> 0x15) & 3;
      if ((uVar8 & 0x40000000) != 0) {
        *(uint *)(decoded + 0x38) = *(uint *)(decoded + 0x38) | 8;
      }
      *(undefined4 *)(decoded + 0x36) = *(undefined4 *)((uVar8 >> 0x19 & 0x1c) + 0x1dc198);
      ((int (*)())psnDecRecomputeSourceUsage)(decoded);
      selectsRewritten = false;
      groupNumber = 1;
      puVar19 = decoded;
      do {
        if ((puVar19[0x41] != 0xffff) && (puVar19[0x40] == puVar19[0x41])) {
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
        thirdSlotAddress = puVar19[0x42];
        if (thirdSlotAddress != 0xffff) {
          if (puVar19[0x40] == thirdSlotAddress) {
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
          else if (puVar19[0x41] == thirdSlotAddress) {
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
        puVar19 = puVar19 + 3;
        groupNumber = groupNumber + 1;
      } while (loopContinue2);
      if (selectsRewritten) {
        ((int (*)())psnDecRecomputeSourceUsage)(decoded);
        groupIndex = 0;
        puVar19 = decoded + 8;
        do {
          puVar17 = puVar19 + 2;
          slotIndex = 0;
          do {
            if (*puVar17 == 0 && puVar17[0x20] == 0) {
              puVar17[0x36] = 0xffff;
            }
            loopContinue = slotIndex != 2;
            puVar17 = puVar17 + 1;
            slotIndex = slotIndex + 1;
          } while (loopContinue);
          loopContinue = groupIndex != 1;
          puVar19 = puVar19 + 3;
          groupIndex = groupIndex + 1;
        } while (loopContinue);
      }
      entryChanged = false;
      uVar8 = 0;
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
              restrictMaskCopy = uVar8;
              do {
                sourceSwizzleOfSlot = *(ushort *)(sourceByteOffset + sourceSlots + 2);
                uVar8 = restrictMaskCopy;
                if ((sourceSwizzleOfSlot | 0xfffffff9) == 0xffffffff) {
                  swizzleMode = sourceSwizzleOfSlot & 0x300;
                  uVar8 = (writeAndOutputMaskInt & 3) << 1 | (int)(writeAndOutputMaskInt & 4) >> 2;
                  if (swizzleMode != 0x100) {
                    if (swizzleMode < 0x101) {
                      uVar8 = alphaOpTableOffset;
                      if ((sourceSwizzleOfSlot & 0x300) != 0) {
                        uVar8 = restrictMaskCopy;
                      }
                    }
                    else if (swizzleMode == 0x200) {
                      uVar8 = (writeAndOutputMaskInt & 1) << 2 | writeAndOutputMaskBits >> 1 & 3;
                    }
                    else {
                      uVar8 = restrictMaskCopy;
                      if (swizzleMode == 0x300) {
                        uVar8 = (writeAndOutputMaskInt & 2) << 1 | (int)(writeAndOutputMaskInt & 4) >> 1 | (writeAndOutputMaskInt & 1) << 3;
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
                  *(ushort *)(sourceByteOffset + sourceSlots + 2) = sourceSwizzleOfSlot & ~((ushort)uVar8 ^ 0xf | 0x300);
                }
                loopContinue2 = sourceByteOffset != 8;
                sourceByteOffset = sourceByteOffset + 4;
                restrictMaskCopy = uVar8;
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
          puVar19 = (ushort *)0x0;
          copyHalfNumber = 0;
          srcpSelectsUsed = 0;
          halfIndex = 0;
          do {
            puVar17 = decoded + halfIndex * 0x20;
            opcode = puVar17[0x14];
            uVar11 = *(uint *)(puVar17 + 0x18);
            puVar17[10] = 0;
            puVar17[0xb] = 0;
            puVar17[0x10] = 0;
            puVar17[0x11] = 0;
            puVar17[0xe] = 0;
            puVar17[0xf] = 0;
            puVar17[0x12] = 0;
            puVar17[0x13] = 0;
            puVar17[0xc] = 0;
            puVar17[0xd] = 0;
            *(uint *)(puVar17 + 0x18) = uVar11 & 0xffffff89;
            if (opcode == 2) {
              *(uint *)(puVar17 + 0x18) = uVar11 & 0xffffff89 | 0x52;
              puVar19 = puVar17;
            }
            nextHalfIndex = halfIndex + 1;
            if (opcode == 0xd) {
              copyHalfNumber = nextHalfIndex;
            }
            opcodeInSet1f1 = (1 << ((int)(short)opcode & 0x3fU) & 0x1f1U) != 0;
            uVar11 = 0;
            propagateHalf = puVar17;
            do {
              sourceSelect = puVar17[uVar11 * 2 + 4];
              sourceSwizzleWord = puVar17[uVar11 * 2 + 5];
              addressSlot = sourceSelect & 3;
              componentMode = sourceSwizzleWord & 0x300;
              componentSelect = sourceSwizzleWord & 0x1f;
              componentModeIs300 = componentMode == 0x300;
              if (componentModeIs300) {
                *(uint *)(puVar17 + 0x18) = *(uint *)(puVar17 + 0x18) | 0x10;
              }
              if ((opcode == 3) && ((componentSelect | 0xfffffff9) == 0xffffffff)) {
                slotComponentMask = (1 < uVar11) + 3;
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
                 (((sourceSwizzleWord & 0x300) != 0 || (((puVar17[3] | puVar17[1]) & 0xffef & ~componentSelect) != 0))))
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
                  *(uint *)(puVar17 + 0x18) = *(uint *)(puVar17 + 0x18) | 0x20;
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
              if ((halfIndex == 1) && (uVar11 == 2)) {
                puVar19 = (ushort *)0x0;
              }
              if ((sourceSelect & 0x100) != 0) {
                readComponents = componentSelect & 7;
                if ((readComponents | 0xfffffff9) == 0xffffffff) {
                  writeAndOutputMask = puVar17[3] | puVar17[1];
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
                puVar17[readSlot + 10] = readComponentBits | puVar17[readSlot + 10];
                if (puVar19 != (ushort *)0x0) {
                  puVar19[readSlot + 10] = readComponentBits | puVar19[readSlot + 10];
                }
                if (!slotIsNotSrcp) {
                  puVar17[readSlot + 0x10] = readComponentBits | puVar17[readSlot + 0x10];
                  puVar17[addressSlot + 10] = readComponentBits | puVar17[addressSlot + 10];
                  puVar17[addressSlot + 0x10] = readComponentBits | puVar17[addressSlot + 0x10];
                  if (puVar19 != (ushort *)0x0) {
                    previousReadMaskB = puVar19[addressSlot + 10];
                    puVar19[readSlot + 0x10] = readComponentBits | puVar19[readSlot + 0x10];
                    puVar19[addressSlot + 10] = readComponentBits | previousReadMaskB;
                    puVar19[addressSlot + 0x10] = readComponentBits | puVar19[addressSlot + 0x10];
                  }
                }
              }
              if ((sourceSelect & 0x200) != 0) {
                alphaReadComponentBits = (ushort)componentSelect & 8;
                if ((((componentModeIs300) && (opcode < 9)) && (opcodeInSet1f1)) &&
                   ((~(puVar17[3] | puVar17[1]) & 1) != 0)) {
                  alphaReadComponentBits = 0;
                }
                puVar17[readSlot + 0xd] = alphaReadComponentBits | puVar17[readSlot + 0xd];
                if (puVar19 != (ushort *)0x0) {
                  puVar19[readSlot + 0xd] = alphaReadComponentBits | puVar19[readSlot + 0xd];
                }
                if (!slotIsNotSrcp) {
                  puVar17[readSlot + 0x12] = alphaReadComponentBits | puVar17[readSlot + 0x12];
                  puVar17[addressSlot + 0xd] = alphaReadComponentBits | puVar17[addressSlot + 0xd];
                  puVar17[addressSlot + 0x12] = alphaReadComponentBits | puVar17[addressSlot + 0x12];
                  if (puVar19 != (ushort *)0x0) {
                    previousReadMask = puVar19[addressSlot + 0xd];
                    puVar19[readSlot + 0x12] = alphaReadComponentBits | puVar19[readSlot + 0x12];
                    puVar19[addressSlot + 0xd] = alphaReadComponentBits | previousReadMask;
                    puVar19[addressSlot + 0x12] = alphaReadComponentBits | puVar19[addressSlot + 0x12];
                  }
                }
              }
              loopContinue2 = uVar11 != 2;
              propagateHalf = propagateHalf + 1;
              uVar11 = uVar11 + 1;
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
          puVar19 = decoded;
          do {
            if ((puVar19[1] == 0 && puVar19[3] == 0) && ((*(uint *)(puVar19 + 0x18) & 1) == 0)) {
              *(uint *)(puVar19 + 0x18) = *(uint *)(puVar19 + 0x18) & 0xfffffffb;
            }
            loopContinue = halfCounter != 1;
            puVar19 = puVar19 + 0x20;
            halfCounter = halfCounter + 1;
          } while (loopContinue);
          halfIndexB = 0;
          puVar17 = decoded + 10;
          puVar19 = decoded;
          do {
            halfIndexB = halfIndexB + 1;
            if ((srcpSelectsUsed & halfIndexB * 0x100) == 0) {
              puVar17[0xb] = 0;
            }
            if ((puVar17[-9] == 0 && puVar17[-7] == 0) &&
               (uVar11 = *(uint *)(puVar17 + 0xe), (uVar11 & 1) == 0)) {
              puVar17[8] = 0;
              puVar17[9] = 0;
              puVar17[0] = 0;
              puVar17[1] = 0;
              puVar17[2] = 0;
              puVar17[3] = 0;
              puVar17[4] = 0;
              puVar17[5] = 0;
              *(uint *)(puVar17 + 0xe) = uVar11 & 0xfffffff7;
              puVar17[6] = 0;
              puVar17[7] = 0;
              puVar17[0xc] = 0x3f80;
              puVar17[0xd] = 0;
              if ((*(uint *)(puVar19 + 0x38) & 6) == 0) {
                puVar17[0x12] = 1;
                puVar17[0x11] = 1;
                puVar17[0x10] = 1;
                *(uint *)(puVar17 + 0xe) = uVar11 & 0xffffffe5;
                defaultOperandWord2 = (*(unsigned int *)&DAT_001dbf94);
                puVar17[10] = 0;
                *(undefined4 *)(puVar17 + -6) = defaultOperandWord2;
                *(undefined4 *)(puVar17 + -2) = defaultOperandWord2;
                *(undefined4 *)(puVar17 + -4) = defaultOperandWord2;
              }
            }
            puVar17 = puVar17 + 0x20;
            puVar19 = puVar19 + -0x20;
          } while (halfIndexB != 2);
          halfCounter2 = 0;
          puVar19 = decoded;
          do {
            if (((puVar19[1] != 0 || puVar19[3] != 0) || ((*(uint *)(puVar19 + 0x18) & 1) != 0)) &&
               ((decoded[0xd] != 0 || decoded[0xe] != 0) || decoded[0xf] != 0)) {
              *(uint *)(puVar19 + 0x18) = *(uint *)(puVar19 + 0x18) | 2;
            }
            loopContinue = halfCounter2 != 1;
            puVar19 = puVar19 + 0x20;
            decoded = decoded + 0x1d;
            halfCounter2 = halfCounter2 + 1;
          } while (loopContinue);
          return;
        }
      } while( true );
    }
    alphaSourceModifier = uVar8 >> 5 & 3;
LAB_000c1c40:
    iVar6 = 0;
    alphaSourceSelectCode = uVar8 & 0x1f;
    sourceModifier = alphaSourceModifier;
    puVar19 = decoded + 0x24;
    alphaSourcesLeft = alphaOpTableOffset;
    if (alphaOpTableOffset == 0) {
      alphaSourcesLeft = 1;
    }
    do {
      iVar6 = iVar6 + 1;
      *(undefined4 *)puVar19 = *(undefined4 *)(alphaSourceSelectCode * 4 + 0x1dc04c);
      puVar19[1] = (ushort)(sourceModifier << 0xc) | puVar19[1];
      alphaSourcesLeft = alphaSourcesLeft - 1;
      if (alphaSourcesLeft == 0) goto LAB_000c1cec;
      alphaSourceSelectCode = uVar8 >> 7 & 0x1f;
      sourceModifier = uVar8 >> 0xc & 3;
      if (iVar6 != 1) {
        if (iVar6 == 0) goto LAB_000c1c40;
        alphaSourceSelectCode = uVar8 >> 0xe & 0x1f;
        sourceModifier = uVar8 >> 0x13 & 3;
        if (iVar6 != 2) {
          alphaSourceSelectCode = 0;
          sourceModifier = 0;
        }
      }
      puVar19 = puVar19 + 2;
    } while( true );
  }
  programWordPtr = iVar6 * 4 + wordsMode2;
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
  texWord = *(uint *)(iVar6 * 4 + wordsMode2 + 0x18);
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
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  uint loopIndex3;
  uint uVar16;
  double dVar17;
  
  decodedProgramWord0 = *decodedProgram;
  if (decodedProgramWord0 != 0) {
    loopIndex3 = 0;
    do {
      decodedProgramWord8 = decodedProgram[2];
      iVar8 = loopIndex3 * 0xa0 + decodedProgramWord8;
      iVar5 = *(int *)(iVar8 + 0x8c);
      iVar6 = *(int *)(iVar8 + 0x90);
      uVar12 = (uint)*(ushort *)(iVar8 + 4);
      uVar2 = *(ushort *)(iVar8 + 0x44);
      if (iVar5 == 1) {
        iVar5 = iVar6 * 4 + programImage;
        uVar7 = *(uint *)(iVar5 + 0x18);
        uVar9 = (uVar12 & 0x1f) << 6;
        *(uint *)(iVar5 + 0x18) = uVar9 | uVar7 & 0xfffff83f;
        if ((*(short *)(iVar8 + 2) == 0 && *(short *)(iVar8 + 6) == 0) &&
           ((*(uint *)(iVar8 + 0x30) & 1) == 0)) {
          *(uint *)(iVar5 + 0x18) = uVar9 | uVar7 & 0xfffc783f;
        }
        iVar6 = iVar6 * 4 + programImage;
        uVar12 = *(uint *)(iVar6 + 0x18);
        uVar9 = *(ushort *)(iVar8 + 0x80) & 0x1f;
        *(uint *)(iVar6 + 0x18) = uVar9 | uVar12 & 0xffffffe0;
        uVar7 = (*(byte *)(iVar8 + 0x29) & 7) << 0xf;
        *(uint *)(iVar6 + 0x18) = uVar7 | uVar9 | uVar12 & 0xfffc7fe0;
        *(uint *)(iVar6 + 0x18) =
             (*(ushort *)(iVar8 + 0x28) & 0xf00) << 3 | uVar7 | uVar9 | uVar12 & 0xfff807e0;
        decodedProgramWord0 = *decodedProgram;
      }
      else if (iVar5 == 0) {
        iVar6 = iVar6 * 4;
        iVar5 = iVar6 + rsWords;
        uVar16 = *(uint *)(iVar5 + 4);
        uVar9 = (uVar12 & 0x7f) << 0x12;
        uVar7 = (uVar2 & 0x7f) << 5;
        *(uint *)(iVar5 + 4) = uVar7 | uVar9 | uVar16 & 0xfe03f01f;
        if ((*(short *)(iVar8 + 2) == 0 && *(short *)(iVar8 + 6) == 0) &&
           ((*(uint *)(iVar8 + 0x30) & 1) == 0)) {
          *(uint *)(iVar5 + 4) = uVar7 | uVar9 | uVar16 & 0xfe00f01f;
        }
        else {
          uVar2 = *(ushort *)(iVar8 + 0x3a);
          if ((uVar2 == 2) || (uVar2 == 3)) {
            *(uint *)(iVar6 + rsWords + 4) =
                 (uVar2 & 3) << 0x10 | *(uint *)(iVar6 + rsWords + 4) & 0xfffcffff;
          }
          else if (uVar2 == 0) {
            *(uint *)(iVar6 + rsWords + 4) = *(uint *)(iVar6 + rsWords + 4) & 0xfffcffff | 0x10000;
          }
        }
        if ((*(short *)(iVar8 + 0x42) != 0 || *(short *)(iVar8 + 0x46) != 0) ||
           (iVar5 = 0, (*(uint *)(iVar8 + 0x70) & 1) != 0)) {
          iVar5 = 1;
        }
        iVar10 = iVar6 + rsWords;
        uVar7 = *(uint *)(iVar10 + 4);
        uVar9 = iVar5 << 4;
        *(uint *)(iVar10 + 4) = uVar9 | uVar7 & 0xffffffef;
        if (*(ushort *)(iVar8 + 0x80) == 0xffff) {
          *(uint *)(iVar10 + 4) = uVar9 | uVar7 & 0xffff0fef;
        }
        else {
          *(uint *)(iVar10 + 4) =
               (*(ushort *)(iVar8 + 0x80) & 0xf) << 0xc | uVar9 | uVar7 & 0xffff0fef;
        }
        if (*(ushort *)(iVar8 + 0x86) == 0xffff) {
          *(uint *)(iVar6 + rsWords + 4) = *(uint *)(iVar6 + rsWords + 4) & 0xfffffff0;
        }
        else {
          *(uint *)(iVar6 + rsWords + 4) =
               *(ushort *)(iVar8 + 0x86) & 0xf | *(uint *)(iVar6 + rsWords + 4) & 0xfffffff0;
        }
        fVar4 = FLOAT_001aa0e8;
        iVar6 = iVar6 + rsWords;
        uVar7 = *(uint *)(iVar6 + 4);
        uVar9 = (uint)(*(float *)(iVar8 + 0x2c) != FLOAT_001aa0e8) << 0x1b;
        *(uint *)(iVar6 + 4) = uVar9 | uVar7 & 0x7ffffff;
        *(uint *)(iVar6 + 4) =
             (uint)(*(float *)(iVar8 + 0x6c) != fVar4) << 0x19 | uVar9 | uVar7 & 0x5ffffff;
        decodedProgramWord0 = *decodedProgram;
      }
      else if (iVar5 == 2) {
        iVar6 = iVar6 * 4;
        iVar10 = iVar6 + programImage;
        loopIndex2 = 0;
        *(uint *)(iVar10 + 0x98) = (uVar12 & 0x1f) << 0x12 | *(uint *)(iVar10 + 0x98) & 0xff83ffff;
        *(uint *)(iVar10 + 0x198) = (uVar2 & 0x1f) << 0x12 | *(uint *)(iVar10 + 0x198) & 0xff83ffff;
        uVar12 = *(uint *)(iVar10 + 0x98);
        uVar9 = (*(ushort *)(iVar8 + 2) & 7) << 0x1a;
        *(uint *)(iVar10 + 0x98) = uVar9 | uVar12 & 0xe3ffffff;
        *(uint *)(iVar10 + 0x98) =
             (*(ushort *)(loopIndex3 * 0xa0 + decodedProgramWord8) & 3) << 0x1d | uVar9 | uVar12 & 0x83ffffff;
        uVar12 = *(uint *)(iVar10 + 0x198);
        uVar9 = (*(ushort *)(iVar8 + 0x42) & 8) << 0x15;
        *(uint *)(iVar10 + 0x198) = uVar9 | uVar12 & 0xfeffffff;
        uVar7 = (*(ushort *)(iVar8 + 0x42) & 0x10) << 0x17;
        *(uint *)(iVar10 + 0x198) = uVar7 | uVar9 | uVar12 & 0xf6ffffff;
        *(uint *)(iVar10 + 0x198) =
             (*(ushort *)(iVar8 + 0x40) & 3) << 0x19 | uVar7 | uVar9 | uVar12 & 0xf0ffffff;
        *(uint *)(iVar10 + 0x98) =
             (*(ushort *)(iVar8 + 6) & 7) << 0x17 | *(uint *)(iVar10 + 0x98) & 0xfc7fffff;
        *(uint *)(iVar10 + 0x198) =
             (*(ushort *)(iVar8 + 0x46) & 8) << 0x14 | *(uint *)(iVar10 + 0x198) & 0xff7fffff;
        iVar5 = iVar8;
        do {
          uVar2 = *(ushort *)(iVar5 + 0x80);
          uVar9 = (uint)uVar2;
          uVar3 = *(ushort *)(iVar5 + 0x86);
          uVar7 = (uint)uVar3;
          if (uVar9 == 0xffff) {
            uVar9 = 0x20;
          }
          else if ((short)uVar2 < 0) {
            uVar9 = ((int)(short)uVar2 & 0x7fffU) + 0x20;
          }
          if (uVar7 == 0xffff) {
            uVar7 = 0x20;
          }
          else if ((short)uVar3 < 0) {
            uVar7 = ((int)(short)uVar3 & 0x7fffU) + 0x20;
          }
          if (loopIndex2 == 1) {
            *(uint *)(iVar10 + 0x98) = (uVar9 & 0x3f) << 6 | *(uint *)(iVar10 + 0x98) & 0xfffff03f;
            *(uint *)(iVar10 + 0x198) = (uVar7 & 0x3f) << 6 | *(uint *)(iVar10 + 0x198) & 0xfffff03f
            ;
          }
          else if (loopIndex2 == 0) {
            *(uint *)(iVar10 + 0x98) = uVar9 & 0x3f | *(uint *)(iVar10 + 0x98) & 0xffffffc0;
            *(uint *)(iVar10 + 0x198) = uVar7 & 0x3f | *(uint *)(iVar10 + 0x198) & 0xffffffc0;
          }
          else if (loopIndex2 == 2) {
            *(uint *)(iVar10 + 0x98) = (uVar9 & 0x3f) << 0xc | *(uint *)(iVar10 + 0x98) & 0xfffc0fff
            ;
            *(uint *)(iVar10 + 0x198) =
                 (uVar7 & 0x3f) << 0xc | *(uint *)(iVar10 + 0x198) & 0xfffc0fff;
          }
          bVar1 = loopIndex2 != 2;
          iVar5 = iVar5 + 2;
          loopIndex2 = loopIndex2 + 1;
        } while (bVar1);
        iVar5 = iVar6 + programImage;
        loopIndex = 0;
        do {
          uVar12 = 0;
          uVar9 = 0;
          uVar16 = 0;
          uVar7 = 0;
          loopIndex2 = 0;
          iVar14 = iVar8 + 8;
          do {
            uVar2 = *(ushort *)(loopIndex * 4 + iVar14 + 2);
            uVar11 = *(ushort *)(loopIndex * 4 + iVar14) & 3;
            if (loopIndex2 == 0) {
              uVar12 = 6;
              if (((uVar2 & 0x300) != 0x100) && (uVar12 = 5, (uVar2 & 0x300) != 0x200)) {
                uVar12 = uVar2 & 0x1f;
              }
              uVar9 = (uVar2 & 0x3000) >> 0xc;
              uVar12 = (uint)*(byte *)(uVar12 * 4 + 0x1dc000 + uVar11);
            }
            else if (loopIndex2 == 1) {
              uVar7 = (uVar2 & 0x3000) >> 0xc;
              uVar16 = (uint)*(byte *)((uVar2 & 0x1f) * 4 + 0x1dbfb4 + uVar11);
            }
            bVar1 = loopIndex2 != 1;
            iVar14 = iVar14 + 0x40;
            loopIndex2 = loopIndex2 + 1;
          } while (bVar1);
          if (loopIndex == 1) {
            *(uint *)(iVar5 + 0x298) =
                 uVar9 << 0xc | (uVar12 & 0x1f) << 7 | *(uint *)(iVar5 + 0x298) & 0xffffc07f;
            *(uint *)(iVar5 + 0x398) =
                 uVar7 << 0xc | (uVar16 & 0x1f) << 7 | *(uint *)(iVar5 + 0x398) & 0xffffc07f;
          }
          else if (loopIndex == 0) {
            *(uint *)(iVar5 + 0x298) =
                 uVar9 << 5 | uVar12 & 0x1f | *(uint *)(iVar5 + 0x298) & 0xffffff80;
            *(uint *)(iVar5 + 0x398) =
                 uVar7 << 5 | uVar16 & 0x1f | *(uint *)(iVar5 + 0x398) & 0xffffff80;
          }
          else if (loopIndex == 2) {
            *(uint *)(iVar5 + 0x298) =
                 uVar9 << 0x13 | (uVar12 & 0x1f) << 0xe | *(uint *)(iVar5 + 0x298) & 0xffe03fff;
            *(uint *)(iVar5 + 0x398) =
                 uVar7 << 0x13 | (uVar16 & 0x1f) << 0xe | *(uint *)(iVar5 + 0x398) & 0xffe03fff;
          }
          bVar1 = loopIndex != 2;
          loopIndex = loopIndex + 1;
        } while (bVar1);
        loopIndex = 0;
        iVar5 = iVar8;
        do {
          dVar17 = (double)*(float *)(iVar5 + 0x2c) * DOUBLE_001aa290;
          if (DOUBLE_001aa1e8 <= dVar17) {
            uVar9 = (int)(dVar17 - DOUBLE_001aa1e8) + 0x80000000;
          }
          else {
            uVar9 = (uint)(int)dVar17;
          }
          switch(uVar9) {
          case 1:
            uVar9 = 6;
            break;
          case 2:
            uVar9 = 5;
            break;
          case 4:
            uVar9 = 4;
            break;
          case 8:
            uVar9 = 0;
            break;
          case 0x10:
            uVar9 = 1;
            break;
          case 0x20:
            uVar9 = 2;
            break;
          case 0x40:
            uVar9 = 3;
          }
          if (loopIndex == 0) {
            iVar13 = iVar6 + programImage;
            uVar7 = *(uint *)(iVar13 + 0x298);
            uVar9 = (uVar9 & 7) << 0x1b;
            *(uint *)(iVar13 + 0x298) = uVar9 | uVar7 & 0xc7ffffff;
            *(uint *)(iVar13 + 0x298) =
                 (*(uint *)(iVar8 + 0x30) & 8) << 0x1b | uVar9 | uVar7 & 0x87ffffff;
          }
          else if (loopIndex == 1) {
            iVar13 = iVar6 + programImage;
            uVar7 = *(uint *)(iVar13 + 0x398);
            uVar9 = (uVar9 & 7) << 0x1b;
            *(uint *)(iVar13 + 0x398) = uVar9 | uVar7 & 0xc7ffffff;
            *(uint *)(iVar13 + 0x398) =
                 (*(uint *)(iVar8 + 0x70) & 8) << 0x1b | uVar9 | uVar7 & 0x87ffffff;
          }
          bVar1 = loopIndex != 1;
          iVar5 = iVar5 + 0x40;
          loopIndex = loopIndex + 1;
        } while (bVar1);
        iVar6 = iVar6 + programImage;
        loopIndex = 0;
        iVar5 = iVar8;
        do {
          uVar9 = (uint)*(byte *)((uint)*(ushort *)(iVar5 + 0x28) * 2 + 0x1dbf98 + loopIndex);
          if (loopIndex == 0) {
            uVar7 = *(uint *)(iVar6 + 0x298);
            uVar9 = (uVar9 & 0xf) << 0x17;
            *(uint *)(iVar6 + 0x298) = uVar9 | uVar7 & 0xf87fffff;
            *(uint *)(iVar6 + 0x298) =
                 (*(ushort *)(iVar8 + 0x2a) & 3) << 0x15 | uVar9 | uVar7 & 0xf81fffff;
          }
          else if (loopIndex == 1) {
            uVar7 = *(uint *)(iVar6 + 0x398);
            uVar9 = (uVar9 & 0xf) << 0x17;
            *(uint *)(iVar6 + 0x398) = uVar9 | uVar7 & 0xf87fffff;
            *(uint *)(iVar6 + 0x398) =
                 (*(ushort *)(iVar8 + 0x6a) & 3) << 0x15 | uVar9 | uVar7 & 0xf81fffff;
          }
          bVar1 = loopIndex != 1;
          iVar5 = iVar5 + 0x40;
          loopIndex = loopIndex + 1;
        } while (bVar1);
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
  undefined4 uVar7;
  int halfCounter;
  undefined2 *destMapEntry;
  int halfCounter2;
  uint uVar11;
  short targetIndex;
  ushort outputMask;
  ushort renderTarget;
  short *psVar12;
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
  short *psStack_60;
  undefined4 uStack_50;
  
  uVar11 = *(uint *)(psnState + 0x30);
  regMapTable = decodedProgram[3];
  targetLiveTable = (short *)(regMapTable + uVar11 * 4);
  psStack_60 = targetLiveTable + 8;
  if (rsWords == 0) {
    freeTempStack = (uint *)0x0;
  }
  else {
    freeTempStack = &uStack_68;
    uVar11 = 0x80;
  }
  targetIndex = 0;
  initCounter = 4;
  psVar12 = targetLiveTable;
  do {
    *psVar12 = targetIndex;
    psVar12[1] = 0xf;
    targetIndex = targetIndex + 1;
    psVar12 = psVar12 + 2;
    initCounter = initCounter + -1;
  } while (initCounter != 0);
  targetLiveTable[1] = targetLiveTable[1] | 0x10;
  _memset(regMapTable,0,*(int *)(psnState + 0x30) << 2);
  uStack_68 = 0;
  if (uVar11 != 0) {
    uStack_68 = uVar11 & 0xffff;
    freeListIndex = 0;
    freeEntryValue = uStack_68;
    do {
      freeEntryNext = freeEntryValue - 1;
      freeEntryValue = freeEntryNext & 0xffff;
      psStack_60[freeListIndex] = (short)freeEntryNext;
      uVar11 = uVar11 - 1;
      freeListIndex = freeListIndex + 1;
    } while (uVar11 != 0);
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
            ((uStack_50 = 0x3f800000, *(float *)(halfCursor + 0x2c) == 1.0 &&
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
              newTempRegister = psStack_60[uStack_68];
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
    uVar7 = 0xffffffff;
    groupUsageCursor = entry + 0x10;
    do {
      psVar12 = (short *)(groupUsageCursor + 4);
      halfCounter = 0;
      do {
        if (*psVar12 == 0 && psVar12[0x20] == 0) {
          psVar12[0x36] = -1;
        }
        else if ((psVar12[0x36] & 0x8000U) == 0) {
          psVar12[0x36] = *(short *)(regMapTable + (uint)(ushort)psVar12[0x36] * 4);
        }
        loopContinue = halfCounter != 2;
        psVar12 = psVar12 + 1;
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
      ((int (*)())psnDecCanonicalizeEntry)(entry,r4AfterCall,slotCounter,groupUsageBase,uVar7,groupCounter,psVar12,groupUsageCursor);
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
    uVar7 = 0x80000004;
  }
  else {
    if (rsWords != 0) {
      ((int (*)())psnDecEncodeHwWords)(decodedProgram,rsWords,programImage);
    }
    uVar7 = 0;
  }
  return uVar7;
}

/* psnMaskIsSingleComponent @ 0xc2e40 (48 bytes) */
int psnMaskIsSingleComponent(param_1)
  undefined4 param_1;
{
  ushort uVar1;
  
  uVar1 = (*(unsigned short *)((unsigned char *)&(param_1) + 2)) & 0xf;
  if (((1 < (ushort)(uVar1 - 1)) && (uVar1 != 4)) && (uVar1 != 8)) {
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
  uint uVar3;
  int halfCursor;
  undefined4 r4AfterCall;
  uint newSlotCode;
  int newSlotAddressPtr;
  int oldAddressOffset;
  int sourceCounter;
  ushort *sourceSwizzlePtr;
  int halfCounter;
  
  uVar3 = newComponentSelect >> 3 & 1;
  if ((newComponentSelect & 7) != 0) {
    uVar3 = 0;
  }
  newSlotCode = 2;
  if ((newSlot != 2) && (newSlotCode = 3, newSlot != 3)) {
    newSlotCode = (uint)(newSlot == 1);
  }
  halfCounter = 0;
  oldAddressOffset = (uint)(oldComponentSelect == 8) * 3;
  newSlotAddressPtr = (uVar3 * 3 + newSlot) * 2 + entry;
  halfCursor = entry;
  do {
    sourceSwizzlePtr = (ushort *)(halfCursor + 10);
    sourceCounter = 0;
    do {
      sourceSwizzle = *sourceSwizzlePtr;
      uVar3 = (uint)sourceSwizzle;
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
    ((int (*)())psnDecCanonicalizeEntry)(entry,r4AfterCall,newSlotCode,newSlotAddressPtr,oldAddressOffset,sourceCounter,sourceSwizzlePtr,uVar3);
  }
  return 1;
}

/* psnDecReplaceSourceAddress @ 0xc3240 (916 bytes) */
int psnDecReplaceSourceAddress(entry, param_2, param_3, param_4, oldAddressOffset, param_6, sourceSwizzlePtr, param_8)
  int entry;
  uint param_2;
  uint param_3;
  int param_4;
  uint oldAddressOffset;
  uint param_6;
  undefined4 sourceSwizzlePtr;
  int param_8;
{
  int loopIndex9;
  int loopIndex8;
  int loopIndex7;
  int loopIndex5;
  int loopIndex4;
  int loopIndex3;
  bool bVar1;
  bool bVar2;
  bool bVar3;
  ushort uVar4;
  ushort uVar5;
  ushort *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  undefined4 r4AfterCall;
  uint uVar11;
  int iVar12;
  uint loopIndex2;
  uint uVar14;
  int iVar15;
  int loopIndex6;
  undefined2 *puVar17;
  int iVar18;
  ushort *puVar19;
  uint uVar20;
  uint loopIndex;
  int aiStack_58 [11];
  
  uVar20 = (oldAddressOffset & 8) << 6;
  if ((oldAddressOffset & 7) == 0) {
    if ((oldAddressOffset & 8) == 0) {
      return 0;
    }
  }
  else {
    uVar20 = uVar20 | 0x100;
  }
  uVar11 = (uint)(param_4 == 8);
  uVar5 = (ushort)oldAddressOffset;
  if ((oldAddressOffset == 0x10) || (oldAddressOffset == 0x12)) {
    oldAddressOffset = oldAddressOffset & 0xffff;
    loopIndex5 = 0;
    puVar6 = (ushort *)(entry + uVar11 * 0x40 + 8);
    do {
      bVar1 = loopIndex5 != 2;
      puVar6[1] = uVar5;
      loopIndex5 = loopIndex5 + 1;
      *puVar6 = *puVar6 & 0xfcff;
      puVar6 = puVar6 + 2;
    } while (bVar1);
    sourceSwizzlePtr = 3;
    uVar14 = param_6;
  }
  else {
    uVar14 = 0;
    bVar2 = (uVar20 >> 8 & 1) != 0;
    bVar1 = uVar20 >> 9 != 0;
    puVar6 = (ushort *)(entry + uVar11 * 0x40 + 8);
    do {
      uVar10 = *puVar6 & 3;
      if (((uVar10 < 3) && ((puVar6[1] & 0x1f) == param_6)) &&
         (iVar15 = ((*puVar6 & 0x300) == 0x100 ^ 1) * 3,
         *(ushort *)((iVar15 + uVar10) * 2 + entry + 0x80) == param_2)) {
        loopIndex3 = 0;
        loopIndex8 = 0;
        do {
          puVar7 = (undefined4 *)((int)aiStack_58 + loopIndex8);
          loopIndex6 = 0;
          do {
            bVar3 = loopIndex6 != 2;
            *puVar7 = 0;
            loopIndex6 = loopIndex6 + 1;
            puVar7 = puVar7 + 1;
          } while (bVar3);
          bVar3 = loopIndex3 != 1;
          loopIndex8 = loopIndex8 + 0xc;
          loopIndex3 = loopIndex3 + 1;
        } while (bVar3);
        loopIndex = 0;
        iVar12 = entry;
        iVar18 = entry;
        do {
          puVar19 = (ushort *)(iVar18 + 8);
          loopIndex2 = 0;
          do {
            if ((uVar11 != loopIndex) || (uVar14 != loopIndex2)) {
              uVar4 = *puVar19;
              uVar8 = uVar4 & 3;
              if (uVar8 == 3) {
                if (((uVar4 & 0x100) != 0) &&
                   (aiStack_58[0] = 1, (ushort)(*(short *)(iVar12 + 0x2a) - 1U) < 2)) {
                  aiStack_58[1] = 1;
                }
                if (((uVar4 & 0x200) != 0) &&
                   (aiStack_58[3] = 1, (ushort)(*(short *)(iVar12 + 0x2a) - 1U) < 2)) {
                  aiStack_58[4] = 1;
                }
              }
              else {
                if ((uVar4 & 0x100) != 0) {
                  aiStack_58[uVar8] = 1;
                }
                if ((uVar4 & 0x200) != 0) {
                  aiStack_58[uVar8 + 3] = 1;
                }
              }
            }
            bVar3 = loopIndex2 != 2;
            puVar19 = puVar19 + 2;
            loopIndex2 = loopIndex2 + 1;
          } while (bVar3);
          bVar3 = loopIndex != 1;
          iVar18 = iVar18 + 0x40;
          iVar12 = iVar12 + 0x40;
          loopIndex = loopIndex + 1;
        } while (bVar3);
        loopIndex9 = 0;
        loopIndex4 = 0x80;
        param_4 = 0;
        do {
          piVar9 = (int *)((int)aiStack_58 + param_4);
          puVar17 = (undefined2 *)(entry + loopIndex4);
          loopIndex7 = 0;
          do {
            if (*piVar9 == 0) {
              *puVar17 = 0xffff;
            }
            bVar3 = loopIndex7 != 2;
            piVar9 = piVar9 + 1;
            puVar17 = puVar17 + 1;
            loopIndex7 = loopIndex7 + 1;
          } while (bVar3);
          bVar3 = loopIndex9 != 1;
          param_4 = param_4 + 0xc;
          loopIndex4 = loopIndex4 + 6;
          loopIndex9 = loopIndex9 + 1;
        } while (bVar3);
        param_8 = 0;
        sourceSwizzlePtr = 0xffff;
        iVar12 = entry;
        while ((((bVar2 && (*(ushort *)(iVar12 + 0x80) != 0xffff)) &&
                (param_3 != *(ushort *)(iVar12 + 0x80))) ||
               (((bVar1 && (*(ushort *)(iVar12 + 0x86) != 0xffff)) &&
                (param_3 != *(ushort *)(iVar12 + 0x86)))))) {
          bVar3 = param_8 == 2;
          iVar12 = iVar12 + 2;
          param_8 = param_8 + 1;
          if (bVar3) {
            *(short *)((iVar15 + uVar10) * 2 + entry + 0x80) = (short)param_2;
            return 0;
          }
        }
        if (bVar2) {
          *(short *)(param_8 * 2 + entry + 0x80) = (short)param_3;
        }
        if (bVar1) {
          *(short *)(param_8 * 2 + entry + 0x86) = (short)param_3;
        }
        puVar6[1] = puVar6[1] & 0xffe0 | uVar5;
        *puVar6 = (*puVar6 & 0xfffc | (ushort)param_8) & 0xfcff | (ushort)uVar20;
      }
      bVar3 = uVar14 != 2;
      puVar6 = puVar6 + 2;
      uVar14 = uVar14 + 1;
    } while (bVar3);
  }
  if (*(int *)(entry + 0x8c) == 2) {
    ((int (*)())psnDecRecomputeSourceUsage)(entry);
    ((int (*)())psnDecCanonicalizeEntry)(entry,r4AfterCall,uVar11,param_4,oldAddressOffset,uVar14,sourceSwizzlePtr,param_8);
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
  bool bVar1;
  ushort *puVar2;
  int loopIndex;
  
  loopIndex = 0;
  puVar2 = (ushort *)(entry + (uint)(halfSelector == 8) * 0x40 + 8);
  do {
    if ((*puVar2 & 3) == 3) {
      return 0;
    }
    bVar1 = loopIndex != 2;
    puVar2 = puVar2 + 2;
    loopIndex = loopIndex + 1;
  } while (bVar1);
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
int psnDecTryRebindAddressWithRollback(entry, param_2, param_3, param_4, param_5, param_6)
  int entry;
  uint param_2;
  undefined4 param_3;
  int param_4;
  uint param_5;
  uint param_6;
{
  uint loopIndex;
  bool bVar1;
  bool bVar2;
  bool bVar3;
  ushort uVar4;
  ushort uVar5;
  bool bVar6;
  undefined4 uVar7;
  short *psVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  undefined4 r4AfterCall;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  ushort *puVar16;
  int iVar17;
  ushort *puVar18;
  int iVar19;
  ushort *puVar20;
  ushort *puVar21;
  int iVar22;
  undefined4 auStack_108 [2];
  undefined1 auStack_100 [180];
  
  uVar10 = param_5;
  _memcpy(auStack_100,entry,0xa0);
  iVar17 = 0;
  uVar13 = 0xffffffff;
  iVar19 = entry + 0x10;
  do {
    psVar8 = (short *)(iVar19 + 4);
    iVar15 = 0;
    do {
      if ((*psVar8 == 0) && (psVar8[0x20] == 0)) {
        psVar8[0x36] = -1;
      }
      bVar1 = iVar15 != 2;
      psVar8 = psVar8 + 1;
      iVar15 = iVar15 + 1;
    } while (bVar1);
    bVar1 = iVar17 != 1;
    iVar19 = iVar19 + 6;
    iVar17 = iVar17 + 1;
  } while (bVar1);
  bVar1 = (param_6 & 7) != 0;
  if ((bVar1) && (*(ushort *)(entry + 0x80) != param_2)) {
    if ((*(ushort *)(entry + 0x82) == 0xffff) || (param_2 == *(ushort *)(entry + 0x82))) {
      ((int (*)())psnDecSwapAddressSlotsInSources)(entry,0,1,0,uVar10,0xffffffff,3);
    }
    else if ((*(ushort *)(entry + 0x84) == 0xffff) || (param_2 == *(ushort *)(entry + 0x84))) {
      ((int (*)())psnDecSwapAddressSlotsInSources)(entry,0,2,0,uVar10,0xffffffff,3);
    }
  }
  bVar2 = (param_6 >> 3 & 1) == 0;
  if (bVar2) {
    iVar17 = 0;
    goto LAB_000c3a40;
  }
  if (*(ushort *)(entry + 0x86) != param_2) {
    if ((*(ushort *)(entry + 0x88) == 0xffff) || (param_2 == *(ushort *)(entry + 0x88))) {
      iVar17 = 1;
      ((int (*)())psnDecSwapAddressSlotsInSources)(entry,0,1,1,uVar10,uVar13,iVar15);
      goto LAB_000c3a40;
    }
    if ((*(ushort *)(entry + 0x8a) == 0xffff) || (param_2 == *(ushort *)(entry + 0x8a))) {
      iVar17 = 1;
      ((int (*)())psnDecSwapAddressSlotsInSources)(entry,0,2,1,uVar10,uVar13,iVar15);
      goto LAB_000c3a40;
    }
  }
  iVar17 = 1;
LAB_000c3a40:
  iVar22 = 0;
  iVar15 = entry + 0x10;
  iVar19 = entry;
  do {
    puVar20 = (ushort *)(iVar19 + 10);
    puVar18 = (ushort *)(iVar15 + 4);
    iVar14 = 0;
    do {
      uVar4 = puVar20[-1];
      puVar16 = (ushort *)(uVar4 & 0x100);
      if ((uVar4 & 0x100) == 0) {
        if ((uVar4 & 0x200) != 0) {
          uVar5 = puVar18[3];
          puVar16 = (ushort *)((int)((unsigned char *)0x0) + 1);
          goto LAB_000c3ab0;
        }
      }
      else {
        uVar5 = *puVar18;
        puVar16 = (ushort *)0x0;
LAB_000c3ab0:
        if ((((uVar4 & 3) < 3) &&
            (iVar12 = (int)puVar16 * 3,
            *(ushort *)((iVar12 + (uVar4 & 3)) * 2 + entry + 0x80) == param_2)) &&
           ((*puVar20 & 0x1f & (uint)uVar5 & ~param_5) != 0)) {
          iVar9 = (int)puVar16 * 6 + entry;
          bVar6 = *(short *)(iVar9 + 0x82) == -1;
          uVar10 = (uint)bVar6;
          puVar16 = (ushort *)(int)(short)(ushort)bVar6;
          if (*(short *)(iVar9 + 0x84) == -1) {
            uVar10 = 2;
            puVar16 = (ushort *)((int)((unsigned char *)0x0) + 2);
          }
          *(short *)((iVar12 + uVar10) * 2 + entry + 0x80) = (short)param_2;
          puVar20[-1] = (ushort)puVar16 | puVar20[-1] & 0xfffc;
        }
      }
      bVar6 = iVar14 != 2;
      puVar20 = puVar20 + 2;
      puVar18 = puVar18 + 1;
      iVar14 = iVar14 + 1;
    } while (bVar6);
    bVar6 = iVar22 == 1;
    iVar19 = iVar19 + 0x40;
    iVar15 = iVar15 + 0x40;
    iVar22 = iVar22 + 1;
    if (bVar6) {
      bVar6 = false;
      iVar22 = 0;
      iVar15 = 0x80;
      do {
        puVar20 = (ushort *)(entry + iVar15);
        loopIndex = 0;
        do {
          uVar7 = _UNK_001aa7f8;
          uVar13 = _UNK_001aa7f4;
          if (*puVar20 == param_2) {
            iVar14 = 0;
            iVar19 = entry;
            do {
              puVar21 = (ushort *)(iVar19 + 8);
              iVar12 = 0;
              do {
                uVar4 = *puVar21;
                puVar18 = (ushort *)(uint)uVar4;
                auStack_108[0] = uVar13;
                auStack_108[1] = uVar7;
                puVar16 = (ushort *)auStack_108[iVar22];
                if ((uVar4 & 3) == loopIndex) {
                  if (((uint)puVar16 & uVar4 & 0x300) != 0) {
                    uVar5 = puVar21[1];
                    uVar11 = (uint)uVar5;
                    puVar16 = puVar21 + 1;
                    if ((uVar5 & param_5) != 0) {
                      if ((uVar5 & 0x2000) == 0) {
                        uVar11 = uVar5 ^ 0x1000;
                        puVar21[1] = (ushort)uVar11;
                      }
                      puVar18 = (ushort *)(uVar4 & 0xfffffffc | 3);
                      *puVar21 = (ushort)puVar18;
                      if ((param_4 != 7) || ((1 < (uVar11 & 0x1f) - 1 && ((uVar11 & 0x1f) != 4)))) {
                        puVar21[1] = (ushort)uVar11 | (ushort)param_6;
                      }
                      if ((param_6 & 1) == 0) {
                        *puVar16 = *puVar16 & 0xfffe;
                      }
                      if ((param_6 & 2) == 0) {
                        *puVar16 = *puVar16 & 0xfffd;
                      }
                      if ((param_6 & 4) == 0) {
                        *puVar16 = *puVar16 & 0xfffb;
                      }
                      if (bVar2) {
                        *puVar16 = *puVar16 & 0xfff7;
                      }
                      bVar6 = true;
                      *puVar21 = uVar4 & 0xfcfc | 3 | (ushort)auStack_108[iVar17];
                    }
                  }
                }
                bVar3 = iVar12 != 2;
                puVar21 = puVar21 + 2;
                iVar12 = iVar12 + 1;
              } while (bVar3);
              bVar3 = iVar14 != 1;
              iVar19 = iVar19 + 0x40;
              iVar14 = iVar14 + 1;
            } while (bVar3);
          }
          uVar13 = 3;
          bVar3 = loopIndex != 2;
          puVar20 = puVar20 + 1;
          loopIndex = loopIndex + 1;
        } while (bVar3);
        bVar3 = iVar22 != 1;
        iVar15 = iVar15 + 6;
        iVar22 = iVar22 + 1;
      } while (bVar3);
      if (bVar6) {
        if (bVar1) {
          *(undefined2 *)(entry + 0x80) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
        }
        if (!bVar2) {
          *(undefined2 *)(entry + 0x86) = (*(unsigned short *)((unsigned char *)&(param_3) + 2));
        }
        ((int (*)())psnDecRecomputeSourceUsage)(entry);
        ((int (*)())psnDecCanonicalizeEntry)(entry,r4AfterCall,iVar19,loopIndex,puVar20,uVar13,puVar16,puVar18);
      }
      else {
        _memcpy(entry,auStack_100,0xa0);
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
  int iVar10;
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
      iVar10 = ((int (*)())psnDecReadsRegMask)(decodedProgramWord8,(uint)rgbDestReg,(uint)rgbWriteMask,half);
      if ((((iVar10 != 0) ||
           (iVar10 = ((int (*)())psnDecReadsRegMask)(decodedProgramWord8,(uint)alphaDestReg,(uint)alphaWriteMask,half), iVar10 != 0)) ||
          (iVar10 = ((int (*)())psnDecDestMatchesRegMask)(decodedProgramWord8,(uint)rgbDestReg,(uint)rgbWriteMask,half,passThroughR7,passThroughR8,passThroughR9),
          iVar10 != 0)) ||
         (iVar10 = ((int (*)())psnDecDestMatchesRegMask)(decodedProgramWord8,(uint)alphaDestReg,(uint)alphaWriteMask,half,passThroughR7,passThroughR8,passThroughR9),
         iVar10 != 0)) break;
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
int psnDecTryMergeAddressSlots(entry, otherEntry, reverseRoles, param_4, unusedArgR7)
  int entry;
  int otherEntry;
  int reverseRoles;
  undefined4 param_4;
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
  uint uVar9;
  int sourceIndex;
  uint slotSearchIndex;
  int iVar12;
  int usageHalfBase;
  undefined2 *puVar14;
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
      uVar9 = destSelectWord & 0x100;
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
      puVar14 = (undefined2 *)(entry + 0x10);
      do {
        usageWordPtr = puVar14 + 2;
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
        puVar14 = puVar14 + 3;
        groupIndex = groupIndex + 1;
      } while (loopContinue);
      halfByteOffset = (uint)(reverseRoles != 0) * 0x40;
      sourceIndex = 0;
      iVar12 = halfByteOffset + 0x16;
      otherSelectPtr = (ushort *)(otherEntry + halfByteOffset + 8);
      usageHalfBase = entry + iVar12;
      slotSearchIndex = 2;
      do {
        otherSelect = (uint)*otherSelectPtr;
        if ((*otherSelectPtr & 0x100) != 0) {
          puVar14 = (undefined2 *)(entry + halfByteOffset + 0x14);
          slotSearchIndex = 0;
          param_4 = 0xffff;
          iVar12 = entry;
          do {
            uVar9 = 0;
            if (*(short *)(iVar12 + 0x80) == -1) {
              if ((otherSelect & 3) == 3) {
                return 0;
              }
              uVar9 = 1;
              *(undefined2 *)(iVar12 + 0x80) = *(undefined2 *)((otherSelect & 3) * 2 + otherEntry + 0x80);
              *puVar14 = 7;
              otherSelect = *otherSelectPtr & 0xfffc | slotSearchIndex;
              *otherSelectPtr = (ushort)otherSelect;
            }
            lastSlotReached = slotSearchIndex == 2;
            slotSearchIndex = slotSearchIndex + 1;
            if (lastSlotReached) {
              if (uVar9 == 0) {
                return 0;
              }
              break;
            }
            iVar12 = iVar12 + 2;
            puVar14 = puVar14 + 1;
          } while (uVar9 == 0);
        }
        if ((otherSelect & 0x200) != 0) {
          puVar14 = (undefined2 *)(usageHalfBase + 4);
          slotSearchIndex = 0;
          param_4 = 0xffff;
          iVar12 = entry;
          do {
            uVar9 = 0;
            if (*(short *)(iVar12 + 0x86) == -1) {
              if ((otherSelect & 3) == 3) {
                return 0;
              }
              uVar9 = 1;
              *(undefined2 *)(iVar12 + 0x86) = *(undefined2 *)((otherSelect & 3) * 2 + otherEntry + 0x86);
              *puVar14 = 8;
              otherSelect = *otherSelectPtr & 0xfffc | slotSearchIndex;
              *otherSelectPtr = (ushort)otherSelect;
            }
            lastSlotReached = slotSearchIndex == 2;
            slotSearchIndex = slotSearchIndex + 1;
            if (lastSlotReached) {
              if (uVar9 == 0) {
                return 0;
              }
              break;
            }
            iVar12 = iVar12 + 2;
            puVar14 = puVar14 + 1;
          } while (uVar9 == 0);
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
          ((int (*)())psnDecCanonicalizeEntry)(entry,r4AfterCall,halfSize,param_4,uVar9,slotSearchIndex,iVar12,puVar14);
          ((int (*)())psnDecRecomputeSourceUsage)(otherEntry);
          ((int (*)())psnDecCanonicalizeEntry)(otherEntry,r4AfterCall2,halfSize,param_4,uVar9,slotSearchIndex,iVar12,puVar14);
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
  ushort sourceModifier;
  uint alphaSourceCount;
  uint rgbSourceCount;
  uint alphaSourcesLeft;
  ushort *alphaSourceSlotPtr;
  ushort *alphaHalf;
  ushort *rgbSourceSlotPtr;
  bool loopContinue;
  byte bVar2;
  undefined4 defaultOperandWord2;
  uint recordKind;
  uint sourceSelectCode;
  ushort uVar6;
  undefined4 r4AfterCall;
  uint *puVar7;
  byte *pbVar8;
  ushort *recField0e;
  char *pcVar10;
  ushort *defaultSlotPtr;
  byte *pbVar12;
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
        bVar2 = *(byte *)recField1a;
        uVar6 = (ushort)bVar2;
        if (bVar2 == 2) {
          entry[10] = 0xf;
          uVar6 = *recField0e;
          entry[0x1d] = 1;
          entry[0x18] = 0;
          entry[0x19] = 1;
          entry[0x40] = uVar6;
          uVar6 = (ushort)*(byte *)recField1a;
        }
        else if (bVar2 < 3) {
          if (bVar2 == 1) {
LAB_000c46e8:
            entry[3] = 0xf;
            entry[2] = *(ushort *)recField0c;
            entry[10] = ~(ushort)*recField1f & 0xf;
            entry[0x40] = *recField0e;
            uVar6 = (ushort)*(byte *)recField1a;
          }
        }
        else if (bVar2 < 5) goto LAB_000c46e8;
        bVar2 = *recField19;
        entry[0x16] = 0x3f80;
        entry[0x17] = 0;
        entry[0x14] = (ushort)bVar2 << 8 | uVar6;
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
            uVar6 = *recField06;
            entry[10] = 0xf;
            entry[2] = uVar6;
            entry[0x40] = *recField0a | 0xc000;
            *(undefined4 *)(entry + 0x16) = *(undefined4 *)((uint)*recField0d * 4 + 0x1dc198);
            bVar2 = *recField0b;
            if ((bVar2 == 2) || (bVar2 == 3)) {
              entry[0x1d] = (ushort)bVar2;
            }
          }
          if (*recField09 == '\0') {
            entry[0x36] = 0x3f80;
            entry[0x37] = 0;
          }
          else {
            entry[0x23] = 0xf;
            uVar6 = *(ushort *)recField04;
            entry[0x2d] = 0xf;
            entry[0x22] = uVar6;
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
            puVar7 = (uint *)0x1dc04c;
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
        puVar7 = recField20;
        if (alphaSourceCount != 0) goto LAB_000c49a8;
LAB_000c4a74:
        entry[0x35] = (ushort)*recField3f;
        if (*recField42 == '\x01') {
          *(uint *)(entry + 0x38) = *(uint *)(entry + 0x38) | 8;
        }
        *(undefined4 *)(entry + 0x36) = *(undefined4 *)((uint)*recField41 * 4 + 0x1dc198);
        pbVar8 = recField3f;
        pcVar10 = recField42;
        pbVar12 = recField41;
        ((int (*)())psnDecRecomputeSourceUsage)(entry);
        ((int (*)())psnDecCanonicalizeEntry)(entry,r4AfterCall,puVar7,pbVar8,pcVar10,alphaHalf,pbVar12,slotCounter);
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
  ushort uVar6;
  float fVar7;
  int entryMode;
  short sVar9;
  undefined1 uVar12;
  short sVar11;
  uint uVar10;
  uint uVar13;
  uint uVar14;
  int loopIndex;
  int iVar16;
  int entry;
  uint uVar18;
  undefined1 uVar19;
  undefined4 headerWord1;
  uint loopIndex3;
  undefined1 uVar22;
  undefined1 uVar23;
  undefined4 *outRecord;
  undefined1 uStack_31;
  
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
           (uVar12 = 0, (*(uint *)(entry + 0x70) & 1) != 0)) {
          uVar12 = 1;
        }
        *(undefined1 *)((int)previousRecord + 0x51) = uVar12;
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
        fVar7 = FLOAT_001aa0e8;
        *(bool *)((int)previousRecord + 0x55) = *(float *)(entry + 0x2c) != FLOAT_001aa0e8;
        entryFloat6c = *(float *)(entry + 0x6c);
        *(undefined1 *)((int)previousRecord + 0x57) = 0;
        *(undefined1 *)((int)previousRecord + 0x56) = 0;
        *(bool *)(previousRecord + 0x15) = entryFloat6c != fVar7;
      }
      else if (entryMode == 2) {
        *(undefined2 *)(previousRecord + 0x15) = rgbDestReg;
        *(undefined2 *)(previousRecord + 0x18) = alphaDestReg;
        *outRecord = 3;
        *(char *)((int)previousRecord + 0x5d) = (char)*(undefined2 *)(entry + 2);
        *(char *)((int)previousRecord + 0x5e) = (char)*(undefined2 *)(loopIndex3 * 0xa0 + entryArray);
        *(byte *)((int)previousRecord + 0x69) = (byte)(*(ushort *)(entry + 0x42) >> 3) & 1;
        uVar6 = *(ushort *)(entry + 0x42) >> 4 & 1;
        *(char *)((int)previousRecord + 0x6b) = (char)uVar6;
        if (uVar6 != 0) {
          *outStatus = *outStatus | 1;
        }
        loopIndex = 0;
        *(char *)((int)previousRecord + 0x6a) = (char)*(undefined2 *)(entry + 0x40);
        *(char *)(previousRecord + 0x17) = (char)*(undefined2 *)(entry + 6);
        *(byte *)(previousRecord + 0x1a) = (byte)(*(ushort *)(entry + 0x46) >> 3) & 1;
        entryAlias = entry;
        do {
          sVar9 = *(short *)(entryAlias + 0x80);
          sVar11 = *(short *)(entryAlias + 0x86);
          if (sVar9 == -1) {
            sVar9 = -0x8000;
          }
          if (sVar11 == -1) {
            sVar11 = -0x8000;
          }
          if (loopIndex == 1) {
            *(short *)(previousRecord + 0x16) = sVar9;
            *(short *)(previousRecord + 0x19) = sVar11;
          }
          else if (loopIndex == 0) {
            *(short *)((int)previousRecord + 0x56) = sVar9;
            *(short *)((int)previousRecord + 0x62) = sVar11;
          }
          else if (loopIndex == 2) {
            *(short *)((int)previousRecord + 0x5a) = sVar9;
            *(short *)((int)previousRecord + 0x66) = sVar11;
          }
          loopContinue = loopIndex != 2;
          entryAlias = entryAlias + 2;
          loopIndex = loopIndex + 1;
        } while (loopContinue);
        loopIndex2 = 0;
        do {
          uVar22 = 0;
          uVar13 = 0;
          uVar12 = 0;
          uVar18 = 0;
          loopIndex = 0;
          iVar16 = entry + 8;
          do {
            uVar6 = *(ushort *)(loopIndex2 * 4 + iVar16 + 2);
            uVar14 = *(ushort *)(loopIndex2 * 4 + iVar16) & 3;
            if (loopIndex == 0) {
              uVar10 = 6;
              if (((uVar6 & 0x300) != 0x100) && (uVar10 = 5, (uVar6 & 0x300) != 0x200)) {
                uVar10 = uVar6 & 0x1f;
              }
              uVar13 = (uVar6 & 0x3000) >> 0xc;
              uVar22 = *(undefined1 *)(uVar10 * 4 + 0x1dc000 + uVar14);
            }
            else if (loopIndex == 1) {
              uVar18 = (uVar6 & 0x3000) >> 0xc;
              uVar12 = *(undefined1 *)((uVar6 & 0x1f) * 4 + 0x1dbfb4 + uVar14);
            }
            loopContinue = loopIndex != 1;
            iVar16 = iVar16 + 0x40;
            loopIndex = loopIndex + 1;
          } while (loopContinue);
          uVar23 = (undefined1)uVar13;
          uVar19 = (undefined1)uVar18;
          if (loopIndex2 == 1) {
            *(undefined1 *)((int)previousRecord + 0x73) = uVar22;
            *(undefined1 *)((int)previousRecord + 0x76) = uVar23;
            *(undefined1 *)((int)previousRecord + 0x82) = uVar12;
            *(undefined1 *)((int)previousRecord + 0x85) = uVar19;
          }
          else if (loopIndex2 == 0) {
            *(undefined1 *)((int)previousRecord + 0x72) = uVar22;
            *(undefined1 *)((int)previousRecord + 0x75) = uVar23;
            *(undefined1 *)((int)previousRecord + 0x81) = uVar12;
            *(undefined1 *)(previousRecord + 0x21) = uVar19;
          }
          else if (loopIndex2 == 2) {
            *(undefined1 *)(previousRecord + 0x1d) = uVar22;
            *(undefined1 *)((int)previousRecord + 0x77) = uVar23;
            *(undefined1 *)((int)previousRecord + 0x83) = uVar12;
            *(undefined1 *)((int)previousRecord + 0x86) = uVar19;
          }
          loopContinue = loopIndex2 != 2;
          loopIndex2 = loopIndex2 + 1;
        } while (loopContinue);
        loopIndex = 0;
        entryAlias = entry;
        do {
          uVar13 = (uint)(int)((double)*(float *)(entryAlias + 0x2c) * DOUBLE_001aa290);
          uStack_31 = (undefined1)uVar13;
          switch(uVar13 & 0xff) {
          case 1:
            uStack_31 = 6;
            break;
          case 2:
            uStack_31 = 5;
            break;
          case 4:
            uStack_31 = 4;
            break;
          case 8:
            uStack_31 = 0;
            break;
          case 0x10:
            uStack_31 = 1;
            break;
          case 0x20:
            uStack_31 = 2;
            break;
          case 0x40:
            uStack_31 = 3;
          }
          if (loopIndex == 0) {
            *(undefined1 *)((int)previousRecord + 0x7a) = uStack_31;
            *(byte *)((int)previousRecord + 0x7b) = (byte)(*(uint *)(entry + 0x30) >> 3) & 1;
          }
          else if (loopIndex == 1) {
            *(undefined1 *)((int)previousRecord + 0x89) = uStack_31;
            *(byte *)((int)previousRecord + 0x8a) = (byte)(*(uint *)(entry + 0x70) >> 3) & 1;
          }
          loopContinue = loopIndex != 1;
          entryAlias = entryAlias + 0x40;
          loopIndex = loopIndex + 1;
        } while (loopContinue);
        loopIndex = 0;
        entryAlias = entry;
        do {
          uVar22 = *(undefined1 *)((uint)*(ushort *)(entryAlias + 0x28) * 2 + 0x1dbf98 + loopIndex);
          if (loopIndex == 0) {
            *(undefined1 *)((int)previousRecord + 0x79) = uVar22;
            *(char *)(previousRecord + 0x1e) = (char)*(undefined2 *)(entry + 0x2a);
          }
          else if (loopIndex == 1) {
            *(undefined1 *)(previousRecord + 0x22) = uVar22;
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
  ushort uVar1;
  int iVar2;
  int iVar3;
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
    iVar2 = sourceUsage + 4;
    iVar3 = passThroughR8 + 4;
    goto code_r0x000c5714;
  case 0x13:
    *(ushort *)(sourceUsage + 0xe) = componentBits | *(ushort *)(sourceUsage + 0xe);
    *(ushort *)(passThroughR8 + 10) = componentBits | *(ushort *)(passThroughR8 + 10);
    if (1 < passThroughR6 - 1U) {
      return;
    }
    iVar2 = sourceUsage + 0x10;
    iVar3 = passThroughR8 + 0xc;
code_r0x000c5714:
    *(ushort *)(iVar2 + 2) = componentBits | *(ushort *)(iVar2 + 2);
    *(ushort *)(iVar3 + 2) = componentBits | *(ushort *)(iVar3 + 2);
    break;
  case 0x1d:
    *(ushort *)(sourceUsage + 2) = componentBits & 7 | *(ushort *)(sourceUsage + 2);
    *(ushort *)(sourceUsage + 0xe) = componentBits & 8 | *(ushort *)(sourceUsage + 0xe);
    break;
  case 0x1e:
    iVar2 = sourceUsage + 4;
    iVar3 = sourceUsage + 0x10;
    uVar1 = *(ushort *)(sourceUsage + 6);
    goto code_r0x000c5788;
  case 0x1f:
    iVar2 = sourceUsage + 8;
    iVar3 = sourceUsage + 0x14;
    uVar1 = *(ushort *)(sourceUsage + 10);
code_r0x000c5788:
    *(ushort *)(iVar2 + 2) = componentBits & 7 | uVar1;
    *(ushort *)(iVar3 + 2) = componentBits & 8 | *(ushort *)(iVar3 + 2);
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
  int iVar1;
  ushort uVar2;
  int iVar3;
  
  if ((writeMask & 8) == 0) {
    return;
  }
  uVar2 = 0;
  switch(selectCode) {
  case 0:
  case 3:
  case 6:
  case 0xc:
    uVar2 = 1;
    break;
  case 1:
  case 4:
  case 7:
  case 0xd:
    uVar2 = 2;
    break;
  case 2:
  case 5:
  case 8:
  case 0xe:
    uVar2 = 4;
    break;
  case 9:
  case 10:
  case 0xb:
  case 0xf:
    uVar2 = 8;
  }
  switch(selectCode) {
  case 0:
  case 1:
  case 2:
    *(ushort *)(sourceUsage + 2) = uVar2 | *(ushort *)(sourceUsage + 2);
    break;
  case 3:
  case 4:
  case 5:
    *(ushort *)(sourceUsage + 6) = uVar2 | *(ushort *)(sourceUsage + 6);
    break;
  case 6:
  case 7:
  case 8:
    *(ushort *)(sourceUsage + 10) = uVar2 | *(ushort *)(sourceUsage + 10);
    break;
  case 9:
    *(ushort *)(sourceUsage + 0xe) = uVar2 | *(ushort *)(sourceUsage + 0xe);
    break;
  case 10:
    *(ushort *)(sourceUsage + 0x12) = uVar2 | *(ushort *)(sourceUsage + 0x12);
    break;
  case 0xb:
    *(ushort *)(sourceUsage + 0x16) = uVar2 | *(ushort *)(sourceUsage + 0x16);
    break;
  case 0xc:
  case 0xd:
  case 0xe:
    *(ushort *)(sourceUsage + 2) = uVar2 | *(ushort *)(sourceUsage + 2);
    *(ushort *)(passThroughR8 + 2) = uVar2 | *(ushort *)(passThroughR8 + 2);
    if (1 < (ushort)((*(unsigned short *)((unsigned char *)&(passThroughR5) + 2)) - 1U)) {
      return;
    }
    iVar1 = sourceUsage + 4;
    iVar3 = passThroughR8 + 4;
    goto code_r0x000c5994;
  case 0xf:
    *(ushort *)(sourceUsage + 0xe) = uVar2 | *(ushort *)(sourceUsage + 0xe);
    *(ushort *)(passThroughR8 + 10) = uVar2 | *(ushort *)(passThroughR8 + 10);
    if (1 < (ushort)((*(unsigned short *)((unsigned char *)&(passThroughR6) + 2)) - 1U)) {
      return;
    }
    iVar1 = sourceUsage + 0x10;
    iVar3 = passThroughR8 + 0xc;
code_r0x000c5994:
    *(ushort *)(iVar1 + 2) = uVar2 | *(ushort *)(iVar1 + 2);
    *(ushort *)(iVar3 + 2) = uVar2 | *(ushort *)(iVar3 + 2);
  }
  return;
}

/* psnRaReleaseUse @ 0xc59c0 (580 bytes) */
int psnRaReleaseUse(operand, tempTable, freeList)
  ushort *operand;
  int *tempTable;
  int *freeList;
{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  ushort uVar8;
  int iVar7;
  uint uVar9;
  short sVar10;
  int iVar11;
  uint uVar12;
  
  uVar2 = operand[1];
  if (uVar2 == 0) {
    *operand = 0;
    return;
  }
  uVar1 = (uint)*operand;
  if (uVar1 < *(ushort *)(tempTable + 2)) {
    iVar6 = tempTable[1];
    uVar8 = (uVar2 == 8) + 7;
  }
  else {
    iVar6 = *tempTable;
    uVar8 = 0xf;
    uVar1 = uVar1 - *(ushort *)(tempTable + 2) & 0xffff;
  }
  iVar11 = iVar6 + uVar1 * 8;
  uVar2 = uVar2 & *(ushort *)(iVar11 + 4);
  operand[1] = uVar2;
  if (uVar2 == 0) {
    *operand = 0;
    return;
  }
  if (uVar8 == 8) {
    uVar2 = *(ushort *)(iVar11 + 2);
  }
  else {
    uVar2 = *(ushort *)(iVar6 + uVar1 * 8);
  }
  *operand = uVar2;
  uVar3 = *(ushort *)(iVar11 + 4) & ~operand[1];
  *(ushort *)(iVar11 + 4) = uVar3;
  uVar9 = (uint)*(ushort *)(freeList + 1);
  uVar2 = *operand;
  uVar1 = uVar9 - 1;
  if ((uVar8 & uVar3) != 0) {
    return;
  }
  if (uVar1 == 0) {
    iVar11 = *freeList;
    iVar6 = 0;
    uVar1 = 0;
  }
  else {
    iVar11 = *freeList;
    iVar6 = uVar1 * 4;
    if (uVar2 <= *(ushort *)(iVar6 + iVar11 + -4)) {
      puVar5 = (ushort *)(iVar6 + iVar11 + -8);
      uVar12 = uVar1;
      do {
        iVar6 = iVar6 + -4;
        uVar1 = uVar1 - 1;
        uVar12 = uVar12 - 1;
        if (uVar12 == 0) {
          iVar6 = uVar1 * 4;
          break;
        }
        uVar3 = *puVar5;
        puVar5 = puVar5 + -2;
      } while (uVar2 <= uVar3);
    }
  }
  if (*(ushort *)(iVar6 + iVar11) == uVar2) {
    *(ushort *)(iVar6 + iVar11 + 2) = uVar8 | *(ushort *)(iVar6 + iVar11 + 2);
    uVar2 = *(ushort *)(freeList + 1);
  }
  else {
    if (uVar1 < uVar9) {
      iVar4 = uVar9 - uVar1;
      iVar7 = uVar9 << 2;
      if (uVar9 - 1 < uVar1) {
        iVar4 = 1;
      }
      while( true ) {
        *(undefined4 *)(iVar7 + iVar11) = *(undefined4 *)(iVar7 + iVar11 + -4);
        iVar7 = iVar7 + -4;
        iVar4 = iVar4 + -1;
        if (iVar4 == 0) break;
        iVar11 = *freeList;
      }
      iVar11 = *freeList;
    }
    *(ushort *)(iVar6 + iVar11) = uVar2;
    *(ushort *)(iVar6 + *freeList + 2) = uVar8;
    uVar2 = *(short *)(freeList + 1) + 1;
    *(ushort *)(freeList + 1) = uVar2;
  }
  uVar1 = (uint)uVar2;
  iVar6 = *freeList;
  if (uVar1 - 1 == 0) {
    return;
  }
  iVar11 = (uVar1 - 2) * 4;
  sVar10 = *(short *)((uVar1 - 1) * 4 + iVar6) + -1;
  if (*(short *)(iVar6 + iVar11) != sVar10) {
    return;
  }
  if (*(short *)(iVar6 + iVar11 + 2) == 0xf) {
    iVar7 = uVar1 - 1;
    while( true ) {
      iVar11 = iVar11 + -4;
      uVar2 = uVar2 - 1;
      *(ushort *)(freeList + 1) = uVar2;
      iVar7 = iVar7 + -1;
      if (iVar7 == 0) {
        return;
      }
      sVar10 = sVar10 + -1;
      if (*(short *)(iVar11 + iVar6) != sVar10) break;
      if (*(short *)(iVar11 + iVar6 + 2) != 0xf) {
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
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  ushort *cursor;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  ushort uVar9;
  int iVar8;
  ushort *puVar10;
  
  uVar3 = (uint)*operand;
  if ((*operand & 0x8000) == 0) {
    uVar9 = operand[1];
    uVar2 = 0;
    if (uVar9 != 0) {
      if (uVar3 < *(ushort *)(tempTable + 2)) {
        iVar5 = tempTable[1];
        uVar2 = 8;
        if (uVar9 != 8) {
          uVar2 = 7;
          operand[1] = uVar9 & 0xfff7;
        }
      }
      else {
        iVar5 = *tempTable;
        uVar2 = 0xf;
        uVar3 = uVar3 - *(ushort *)(tempTable + 2) & 0xffff;
      }
      puVar7 = (ushort *)(iVar5 + uVar3 * 8);
      uVar9 = puVar7[2];
      if (uVar9 == 0) {
        *(undefined2 *)(iVar5 + uVar3 * 8) = 0xffff;
        puVar7[1] = 0xffff;
      }
      puVar7[2] = uVar9 | operand[1];
      if ((uVar2 & uVar9) == 0) {
        puVar10 = (ushort *)*freeList;
        uVar9 = puVar10[1];
        if ((uVar2 & ~uVar9) == 0) {
          uVar3 = 0;
          iVar5 = 0;
          uVar6 = 1;
        }
        else {
          cursor = puVar10 + 3;
          uVar3 = 0;
          do {
            uVar6 = uVar3;
            uVar9 = *cursor;
            uVar3 = uVar6 + 1;
            cursor = cursor + 2;
          } while ((uVar2 & ~uVar9) != 0);
          iVar5 = uVar3 * 4;
          uVar6 = uVar6 + 2;
          puVar10 = puVar10 + uVar3 * 2;
          uVar9 = puVar10[1];
        }
        uVar1 = *puVar10;
        puVar10[1] = uVar9 & ~uVar2;
        if (*(ushort *)(freeList + 1) == uVar6) {
          if (*(short *)(iVar5 + *freeList + 2) != 0) {
            *(short *)(freeList + 1) = (short)uVar6 + 1;
            uVar3 = uVar6;
          }
          *(ushort *)(*freeList + uVar3 * 4) = uVar1 + 1;
          *(undefined2 *)(uVar3 * 4 + *freeList + 2) = 0xf;
        }
        else {
          iVar8 = *freeList;
          if ((*(short *)(iVar8 + iVar5 + 2) == 0) &&
             (uVar6 = *(ushort *)(freeList + 1) - 1, *(short *)(freeList + 1) = (short)uVar6,
             uVar3 < (uVar6 & 0xffff))) {
            iVar5 = uVar3 << 2;
            while( true ) {
              uVar3 = uVar3 + 1;
              *(undefined4 *)(iVar5 + iVar8) = *(undefined4 *)(iVar5 + iVar8 + 4);
              iVar5 = iVar5 + 4;
              if (*(ushort *)(freeList + 1) <= uVar3) break;
              iVar8 = *freeList;
            }
          }
        }
        if ((uVar2 & 7) != 0) {
          *puVar7 = uVar1;
        }
        if ((uVar2 & 8) != 0) {
          puVar7[1] = uVar1;
        }
      }
      if (uVar2 == 8) {
        uVar2 = puVar7[1];
      }
      else {
        uVar2 = *puVar7;
      }
    }
    *operand = uVar2;
    return;
  }
  return;
}

/* FUN_000c5e60 @ 0xc5e60 (1524 bytes) */
int FUN_000c5e60(psnProgram)
  undefined4 *psnProgram;
{
  undefined4 *cursor7;
  int loopIndex2;
  uint loopIndex;
  uint uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  ushort *puVar10;
  ushort maxRegister;
  uint uVar12;
  ushort *puVar13;
  byte *pbVar14;
  ushort *puVar15;
  char *pcVar16;
  ushort *puVar17;
  ushort *puVar18;
  ushort *cursor2;
  ushort *cursor3;
  ushort *puVar21;
  ushort *cursor4;
  char *pcVar23;
  ushort *puVar24;
  ushort *cursor5;
  ushort *cursor6;
  char *pcVar27;
  char *cursor;
  uint kind1Count;
  int remaining;
  /* issue #64 live-repro (crash #8, past the ilRewriteForTextureState fixes): local_98/local_94/local_90/
   * local_8c/local_88/local_84/local_80/local_7c were 8 separately-declared 4-byte locals,
   * each initialized to the same value below, that a later loop (`*(short*)((int)&local_98 +
   * iVar8) = ...`, iVar8 running 0..30) treats as one contiguous 32-byte/16-ushort array -
   * the same Ghidra local-splitting defect class already fixed in FUN_000fd5c8,
   * FUN_000b6580's local_68 cluster, and this session's own FUN_000f4d80 local_2c cluster.
   * Only local_98's OWN 4 bytes are real storage; the walk past it (needed to reach what
   * should be local_94/local_90/.../local_7c) ran off local_98's real bounds into whatever
   * gcc actually placed next on the stack. Live-verified on real hardware via a hardware
   * watchpoint on the calling function's saved r30/r31 stack slot: this loop's clamping
   * store (`*(undefined2*)((int)&local_98+iVar8) = 0xff;`) was confirmed to be the exact
   * write corrupting that slot, which is what caused FUN_000b4400's r30 to read back as
   * 0xff00ff and crash on its next stack-relative access. Fixed by giving the cluster real,
   * guaranteed-contiguous storage as an array (local_7c is kept as its own separate variable
   * too, since it is independently used above for the early-return check; fileUseCounts[7] is
   * initialized to the same value alongside it so the walk's last slot still gets it). */
  uint fileUseCounts[8];
  uint local_7c;
  uint local_78;
  uint local_74;
  int noKind2Yet;
  uint local_6c;
  uint local_68;
  uint kind2Count;
  undefined4 maxFlaggedRegister;
  uint local_5c;
  uint local_58;
  
  local_7c = (uint)*(ushort *)(psnProgram + 5);
  if (local_7c != 0) {
    return;
  }
  local_58 = psnProgram[2];
  fileUseCounts[0] = local_7c;
  fileUseCounts[1] = local_7c;
  fileUseCounts[2] = local_7c;
  fileUseCounts[3] = local_7c;
  fileUseCounts[4] = local_7c;
  fileUseCounts[5] = local_7c;
  fileUseCounts[6] = local_7c;
  fileUseCounts[7] = local_7c;
  if (local_58 == 0) {
    local_5c = local_58;
    local_74 = local_58;
    local_6c = local_58;
    local_78 = local_58;
    noKind2Yet = 1;
    maxFlaggedRegister = 0;
    local_68 = local_58;
    kind2Count = local_58;
    maxRegister = 0;
  }
  else {
    puVar21 = (ushort *)((int)psnProgram + 0x62);
    kind1Count = 0;
    kind2Count = 0;
    noKind2Yet = 1;
    local_68 = 0;
    local_78 = 0;
    local_6c = 0;
    local_5c = 0;
    local_74 = 0;
    maxFlaggedRegister = 0;
    pcVar23 = (char *)(psnProgram + 0x1a);
    puVar24 = (ushort *)((int)psnProgram + 0x5a);
    puVar4 = (ushort *)(psnProgram + 0x16);
    puVar5 = (ushort *)((int)psnProgram + 0x56);
    puVar15 = (ushort *)(psnProgram + 0x15);
    pcVar16 = (char *)(psnProgram + 0x1f);
    puVar17 = (ushort *)((int)psnProgram + 0x66);
    puVar18 = (ushort *)(psnProgram + 0x19);
    puVar13 = (ushort *)(psnProgram + 0x18);
    pcVar27 = (char *)(psnProgram + 0x17);
    pbVar14 = (byte *)((int)psnProgram + 0x61);
    puVar10 = (ushort *)(psnProgram + 0x13);
    pcVar7 = (char *)((int)psnProgram + 0x51);
    puVar6 = (ushort *)((int)psnProgram + 0x4e);
    pcVar9 = (char *)((int)psnProgram + 0x53);
    loopIndex = 1;
    maxRegister = 0;
    cursor2 = puVar5;
    cursor3 = puVar4;
    cursor4 = puVar21;
    cursor5 = puVar24;
    cursor6 = puVar15;
    cursor = pcVar23;
    cursor7 = psnProgram;
    do {
      cursor7 = cursor7 + 0x12;
      switch(*cursor7) {
      case 1:
        if ((*pcVar9 != '\0') && (maxRegister < *puVar6)) {
          maxRegister = *puVar6;
        }
        if ((*pcVar7 != '\0') && (maxRegister < *puVar10)) {
          maxRegister = *puVar10;
        }
        kind1Count = kind1Count + 1 & 0xffff;
        break;
      case 2:
        if (noKind2Yet == 0) {
          if (*cursor != '\0') {
            local_5c = local_5c + 1 & 0xffff;
            local_78 = local_78 + 1 & 0xffff;
          }
        }
        else {
          local_5c = local_5c + 1 & 0xffff;
        }
        if (*(byte *)puVar21 < 8) {
          uVar1 = 1 << ((int)(char)*(byte *)puVar21 & 0x3fU);
          if ((uVar1 & 0xba) == 0) {
            if ((uVar1 & 4) == 0) {
              if ((uVar1 & 0x40) != 0) {
                uVar2 = *cursor3;
                if (*cursor3 <= maxRegister) {
                  uVar2 = maxRegister;
                }
                maxRegister = *puVar24;
                if (*puVar24 <= uVar2) {
                  maxRegister = uVar2;
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
            if (maxRegister < *puVar15) {
              maxRegister = *puVar15;
            }
            if (*pbVar14 < 0x10) {
              iVar8 = (uint)*pbVar14 * 2;
              *(short *)((int)fileUseCounts + iVar8) = *(short *)((int)fileUseCounts + iVar8) + 1;
            }
          }
        }
        noKind2Yet = 0;
        kind2Count = kind2Count + 1 & 0xffff;
        break;
      case 3:
      case 4:
        if (local_5c == 0) {
          local_5c = 1;
        }
        if ((*pcVar27 != '\0') && (maxRegister < *cursor6)) {
          maxRegister = *cursor6;
        }
        uVar2 = *puVar5;
        if ((uVar2 & 0x8000) == 0) {
          if (maxRegister < uVar2) {
            maxRegister = uVar2;
          }
        }
        else if (maxFlaggedRegister < (uVar2 & 0x7fff)) {
          maxFlaggedRegister = uVar2 & 0x7fff;
        }
        uVar2 = *puVar4;
        if ((uVar2 & 0x8000) == 0) {
          if (maxRegister < uVar2) {
            maxRegister = uVar2;
          }
        }
        else if (maxFlaggedRegister < (uVar2 & 0x7fff)) {
          maxFlaggedRegister = uVar2 & 0x7fff;
        }
        uVar2 = *cursor5;
        if ((uVar2 & 0x8000) == 0) {
          if (maxRegister < uVar2) {
            maxRegister = uVar2;
          }
        }
        else if (maxFlaggedRegister < (uVar2 & 0x7fff)) {
          maxFlaggedRegister = uVar2 & 0x7fff;
        }
        if ((*pcVar23 != '\0') && (maxRegister < *puVar13)) {
          maxRegister = *puVar13;
        }
        uVar2 = *cursor4;
        if ((uVar2 & 0x8000) == 0) {
          if (maxRegister < uVar2) {
            maxRegister = uVar2;
          }
        }
        else if (maxFlaggedRegister < (uVar2 & 0x7fff)) {
          maxFlaggedRegister = uVar2 & 0x7fff;
        }
        uVar2 = *puVar18;
        if ((uVar2 & 0x8000) == 0) {
          if (maxRegister < uVar2) {
            maxRegister = uVar2;
          }
        }
        else if (maxFlaggedRegister < (uVar2 & 0x7fff)) {
          maxFlaggedRegister = uVar2 & 0x7fff;
        }
        uVar2 = *puVar17;
        if ((uVar2 & 0x8000) == 0) {
          if (maxRegister < uVar2) {
            maxRegister = uVar2;
          }
        }
        else if (maxFlaggedRegister < (uVar2 & 0x7fff)) {
          maxFlaggedRegister = uVar2 & 0x7fff;
        }
        if (*pcVar16 != '\0') {
          local_74 = local_74 + 1 & 0xffff;
        }
        noKind2Yet = 1;
        local_68 = local_68 + 1 & 0xffff;
        break;
      case 5:
        local_6c = local_6c + 1 & 0xffff;
      }
      loopIndex = loopIndex + 1;
      pcVar16 = pcVar16 + 0x48;
      puVar17 = puVar17 + 0x24;
      puVar18 = puVar18 + 0x24;
      cursor4 = cursor4 + 0x24;
      puVar13 = puVar13 + 0x24;
      pcVar23 = pcVar23 + 0x48;
      cursor5 = cursor5 + 0x24;
      puVar4 = puVar4 + 0x24;
      puVar5 = puVar5 + 0x24;
      cursor6 = cursor6 + 0x24;
      pcVar27 = pcVar27 + 0x48;
      pbVar14 = pbVar14 + 0x48;
      puVar15 = puVar15 + 0x24;
      cursor2 = cursor2 + 0x24;
      puVar24 = puVar24 + 0x24;
      cursor3 = cursor3 + 0x24;
      puVar21 = puVar21 + 0x24;
      cursor = cursor + 0x48;
      puVar10 = puVar10 + 0x24;
      pcVar7 = pcVar7 + 0x48;
      puVar6 = puVar6 + 0x24;
      pcVar9 = pcVar9 + 0x48;
    } while (loopIndex <= local_58);
    if (kind1Count != 0) goto LAB_000c6350;
  }
  kind1Count = 1;
LAB_000c6350:
  if (local_5c == 0) {
    local_5c = 1;
    local_68 = 1;
  }
  if (noKind2Yet == 0) {
    local_68 = local_68 + 1 & 0xffff;
  }
  uVar12 = (local_68 + local_78 & 0xffff) + local_74 & 0xffff;
  if (uVar12 < kind2Count) {
    uVar12 = kind2Count;
  }
  if (uVar12 < local_6c) {
    uVar12 = local_6c;
  }
  if (uVar12 < kind1Count) {
    uVar12 = kind1Count;
  }
  *(ushort *)((int)psnProgram + 0x22) = maxRegister;
  *(short *)((int)psnProgram + 0x26) = (short)uVar12;
  *(short *)((int)psnProgram + 0x1e) = (short)(local_68 + local_78);
  *(short *)(psnProgram + 6) = (short)kind1Count;
  *(short *)((int)psnProgram + 0x16) = (short)local_5c;
  *(undefined2 *)(psnProgram + 10) = 0;
  *(short *)(psnProgram + 8) = (short)local_6c;
  loopIndex2 = 0;
  remaining = 0x10;
  *(short *)(psnProgram + 7) = (short)local_68;
  *(short *)((int)psnProgram + 0x1a) = (short)kind2Count;
  *(undefined2 *)(psnProgram + 9) = (*(unsigned short *)((unsigned char *)&(maxFlaggedRegister) + 2));
  puVar3 = psnProgram;
  do {
    maxRegister = *(ushort *)((int)fileUseCounts + loopIndex2);
    if (0xff < maxRegister) {
      maxRegister = 0xff;
      *(undefined2 *)((int)fileUseCounts + loopIndex2) = 0xff;
    }
    *(char *)((int)puVar3 + 0x2a) = (char)maxRegister;
    loopIndex2 = loopIndex2 + 2;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    remaining = remaining + -1;
  } while (remaining != 0);
  *(undefined2 *)(psnProgram + 5) = 1;
  return;
}

/* psnReallocateTemps @ 0xc6470 (1284 bytes) */
int psnReallocateTemps(psnState, psnProgram, param_3, passThroughR6, sourceUsage, passThroughR8, unusedArgR9, param_8)
  int psnState;
  int psnProgram;
  undefined2 *param_3;
  uint *passThroughR6;
  uint *sourceUsage;
  undefined4 *passThroughR8;
  undefined4 unusedArgR9;
  uint param_8;
{
  ushort instShort7;
  ushort instShort3;
  byte instByte10;
  uint instKind;
  bool bVar1;
  byte bVar2;
  ushort uVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  int loopIndex;
  uint uVar8;
  byte bVar9;
  uint collectedCount;
  int psnProgramWord8;
  int loopIndex2;
  uint *lastVisitedInst;
  uint *inst;
  ushort auStack_8b8 [4];
  undefined4 uStack_8b0;
  undefined4 uStack_8ac;
  undefined2 *puStack_8a8;
  undefined2 uStack_8a4;
  ushort uStack_8a0;
  undefined2 uStack_89e;
  ushort uStack_89c;
  undefined2 uStack_89a;
  undefined2 *puStack_898;
  undefined2 *puStack_894;
  undefined2 uStack_890;
  undefined4 uStack_88c;
  undefined4 uStack_888;
  undefined4 uStack_884;
  undefined4 uStack_880;
  uint uStack_87c;
  undefined4 uStack_878;
  undefined4 uStack_874;
  undefined4 uStack_870;
  undefined4 uStack_86c;
  undefined4 uStack_868;
  uint auStack_864 [519];
  
  uVar6 = 0xf;
  puStack_8a8 = *(undefined2 **)(psnState + 0x1c);
  auStack_8b8[1] = 0;
  auStack_8b8[0] = 0;
  auStack_8b8[3] = 0;
  auStack_8b8[2] = 0;
  (*(unsigned short *)((unsigned char *)&(uStack_8b0) + 2)) = 0;
  (*(unsigned short *)((unsigned char *)&(uStack_8b0) + 0)) = 0;
  (*(unsigned short *)((unsigned char *)&(uStack_8ac) + 2)) = 0;
  (*(unsigned short *)((unsigned char *)&(uStack_8ac) + 0)) = 0;
  *puStack_8a8 = 0;
  puStack_8a8[1] = 0xf;
  uStack_8a4 = 1;
  uStack_890 = SUB42((unsigned long)param_3,0);
  puStack_898 = puStack_8a8 + *(int *)(psnState + 0x30) * 2;
  _memset(puStack_898,0,*(int *)(psnState + 0x30) << 3);
  if (param_3 == (undefined2 *)0x0) {
    puStack_894 = param_3;
  }
  else {
    puStack_894 = puStack_898 + *(int *)(psnState + 0x30) * 4;
    _memset(puStack_894,0,*(int *)(psnState + 0x30) * 8);
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
        uStack_89e = 0xf;
        uStack_8a0 = *(ushort *)(inst + 3);
        if (*(char *)((int)inst + 0x1a) == '\0') {
          uVar6 = 0;
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
            ((int (*)())psnRaReleaseUse)(&uStack_8a0,&puStack_898,&puStack_8a8);
            *(ushort *)(inst + 3) = uStack_8a0;
          }
          uStack_87c = CONCAT22(*(undefined2 *)((int)inst + 0xe),
                                (ushort)*(byte *)((int)inst + 0x1f)) ^ 0xf;
          ((int (*)())psnRaAssignDefinition)(&uStack_87c,&puStack_898,&puStack_8a8,passThroughR6,sourceUsage,passThroughR8,uVar6,param_8);
          uVar6 = (uint)(*(unsigned short *)((unsigned char *)&(uStack_87c) + 0));
          *(ushort *)((int)inst + 0xe) = (*(unsigned short *)((unsigned char *)&(uStack_87c) + 0));
        }
        if (((lastVisitedInst == (uint *)0x0) || (*lastVisitedInst != 2)) || (*(char *)(lastVisitedInst + 8) != '\0')) {
          collectedCount = 0;
        }
        sourceUsage = (uint *)(uint)*(byte *)((int)inst + 0x1a);
        if (sourceUsage != (uint *)0x0) {
          uVar5 = collectedCount;
          if (collectedCount == 0) {
            uVar6 = (uint)*(ushort *)((int)inst + 0xe);
          }
          else {
            instShort3 = *(ushort *)(inst + 3);
            passThroughR8 = (undefined4 *)(uint)instShort3;
            uVar4 = *(ushort *)((int)inst + 0xe);
            uVar6 = (uint)uVar4;
            param_8 = 0;
            passThroughR6 = auStack_864;
            do {
              uVar8 = passThroughR6[param_8];
              if ((instShort3 == uVar8) && (sourceUsage != (uint *)((int)((unsigned char *)0x0) + 2))) {
                uVar5 = 0;
                *(undefined1 *)(lastVisitedInst + 8) = 1;
              }
              if (uVar8 == uVar4) {
                collectedCount = param_8;
              }
              param_8 = param_8 + 1;
            } while (param_8 < uVar5);
            bVar1 = collectedCount < uVar5;
            collectedCount = uVar5;
            if (bVar1) goto LAB_000c6e10;
          }
          collectedCount = uVar5 + 1;
          auStack_864[uVar5] = uVar6;
        }
        goto LAB_000c6e10;
      }
      if (instKind < 3) {
        if (instKind == 1) {
          uStack_8a0 = *(ushort *)((int)inst + 6);
          uVar6 = 0xf;
          uStack_89e = 0xf;
          uStack_89a = 0xf;
          uStack_89c = *(ushort *)(inst + 1);
          if (*(char *)((int)inst + 0xb) == '\0') {
            *(undefined2 *)((int)inst + 6) = 0;
            *(undefined1 *)((int)inst + 0xf) = 0xf;
            *(undefined1 *)((int)inst + 0xd) = 0;
            *(undefined1 *)((int)inst + 10) = 0;
          }
          else {
            ((int (*)())psnRaReleaseUse)(&uStack_8a0,&puStack_898,&puStack_8a8);
            *(ushort *)((int)inst + 6) = uStack_8a0;
            *(byte *)((int)inst + 0xf) = (byte)uStack_89e ^ 0xf;
          }
          if (*(char *)((int)inst + 9) == '\0') {
            *(ushort *)(inst + 1) = 0;
            *(undefined1 *)(inst + 3) = 0;
            *(undefined1 *)((int)inst + 0xe) = 0xf;
            *(undefined1 *)(inst + 2) = 0;
          }
          else {
            ((int (*)())psnRaReleaseUse)(&uStack_89c,&puStack_898,&puStack_8a8);
            *(ushort *)(inst + 1) = uStack_89c;
            *(byte *)((int)inst + 0xe) = (byte)uStack_89a ^ 0xf;
          }
        }
        goto LAB_000c6e10;
      }
      if (4 < instKind) goto LAB_000c6e10;
      uStack_8a0 = *(ushort *)(inst + 3);
      uStack_89c = *(ushort *)(inst + 6);
      uStack_89a = 0;
      uStack_89e = (ushort)*(byte *)(inst + 5);
      if (*(char *)(inst + 8) != '\0') {
        uStack_89a = 8;
      }
      ((int (*)())psnRaReleaseUse)(&uStack_8a0,&puStack_898,&puStack_8a8);
      *(ushort *)(inst + 3) = uStack_8a0;
      *(byte *)(inst + 5) = (byte)uStack_89e;
      ((int (*)())psnRaReleaseUse)(&uStack_89c,&puStack_898,&puStack_8a8);
      uVar6 = 7;
      uStack_880 = 0;
      uStack_87c = 0;
      uStack_878 = 0;
      uStack_874 = 0;
      uStack_870 = 0;
      uStack_86c = 0;
      uStack_868 = 0;
      uStack_88c = 0;
      uStack_888 = 0;
      uStack_884 = 0;
      *(ushort *)(inst + 6) = uStack_89c;
      *(byte *)(inst + 8) = (byte)(-(uint)uStack_89a >> 0x1f);
      bVar9 = *(byte *)(inst + 5) | *(byte *)((int)inst + 0x15);
      if (bVar9 == 0) {
        uVar6 = 0;
      }
      bVar2 = *(byte *)((int)inst + 0x31);
      uVar6 = -(uint)(byte)(*(byte *)(inst + 8) | *(byte *)((int)inst + 0x21) |
                           *(byte *)((int)inst + 0x23)) >> 0x1c & 8 | uVar6;
      if ((bVar2 < 10) && ((1 << ((int)(char)bVar2 & 0x3fU) & 0x3b1U) != 0)) {
        uVar6 = uVar6 & (bVar9 | 8);
      }
      if (((bVar2 == 10) || (bVar2 == 2)) && ((uVar6 & 7) != 0)) {
        uVar6 = uVar6 | 8;
      }
      instByte10 = *(byte *)(inst + 0x10);
      if ((instByte10 == 1) && ((uVar6 & 8) != 0)) {
        uVar6 = uVar6 | 7;
      }
      switch(bVar2) {
      case 0:
      case 7:
      case 8:
        ((int (*)())psnAccumulateRgbSelectRead)((uint)*(byte *)((int)inst + 0x2a),uVar6,(uint)*(byte *)(inst + 0xc),
                     (uint)*(byte *)((int)inst + 0x3f),&uStack_87c,&uStack_88c);
        ((int (*)())psnAccumulateRgbSelectRead)((uint)*(byte *)((int)inst + 0x2b),uVar6,(uint)*(byte *)(inst + 0xc),
                     (uint)*(byte *)((int)inst + 0x3f),&uStack_87c,&uStack_88c);
        bVar9 = *(byte *)(inst + 0xb);
        goto code_r0x000c6a30;
      case 1:
      case 4:
      case 5:
        ((int (*)())psnAccumulateRgbSelectRead)((uint)*(byte *)((int)inst + 0x2a),uVar6,(uint)*(byte *)(inst + 0xc),
                     (uint)*(byte *)((int)inst + 0x3f),&uStack_87c,&uStack_88c);
        bVar9 = *(byte *)((int)inst + 0x2b);
code_r0x000c6a30:
        passThroughR8 = &uStack_88c;
        sourceUsage = &uStack_87c;
        passThroughR6 = (uint *)(uint)*(byte *)((int)inst + 0x3f);
        ((int (*)())psnAccumulateRgbSelectRead)((uint)bVar9,uVar6,(uint)*(byte *)(inst + 0xc),passThroughR6,sourceUsage,passThroughR8);
        instByte10 = *(byte *)(inst + 0x10);
        break;
      case 2:
        sourceUsage = &uStack_87c;
        passThroughR8 = &uStack_88c;
        ((int (*)())psnAccumulateRgbSelectRead)((uint)*(byte *)((int)inst + 0x2a),uVar6,(uint)*(byte *)(inst + 0xc),
                     (uint)*(byte *)((int)inst + 0x3f),sourceUsage,passThroughR8);
        ((int (*)())psnAccumulateRgbSelectRead)((uint)*(byte *)((int)inst + 0x2b),uVar6,(uint)*(byte *)(inst + 0xc),
                     (uint)*(byte *)((int)inst + 0x3f),sourceUsage,passThroughR8);
        ((int (*)())psnAccumulateAlphaSelectRead)((uint)*(byte *)((int)inst + 0x39),uVar6,(uint)*(byte *)(inst + 0xc),
                     (uint)*(byte *)((int)inst + 0x3f),sourceUsage,passThroughR8);
        passThroughR6 = (uint *)(uint)*(byte *)((int)inst + 0x3f);
        ((int (*)())psnAccumulateAlphaSelectRead)((uint)*(byte *)((int)inst + 0x3a),uVar6,(uint)*(byte *)(inst + 0xc),
                     passThroughR6,sourceUsage,passThroughR8);
        instByte10 = *(byte *)(inst + 0x10);
        break;
      case 3:
        sourceUsage = &uStack_87c;
        passThroughR8 = &uStack_88c;
        ((int (*)())psnAccumulateRgbSelectRead)((uint)*(byte *)((int)inst + 0x2a),uVar6 & 3,(uint)*(byte *)(inst + 0xc),
                     (uint)*(byte *)((int)inst + 0x3f),sourceUsage,passThroughR8);
        ((int (*)())psnAccumulateRgbSelectRead)((uint)*(byte *)((int)inst + 0x2b),uVar6 & 3,(uint)*(byte *)(inst + 0xc),
                     (uint)*(byte *)((int)inst + 0x3f),sourceUsage,passThroughR8);
        passThroughR6 = (uint *)(uint)*(byte *)((int)inst + 0x3f);
        ((int (*)())psnAccumulateRgbSelectRead)((uint)*(byte *)(inst + 0xb),uVar6 & 4,(uint)*(byte *)(inst + 0xc),passThroughR6
                     ,sourceUsage,passThroughR8);
        instByte10 = *(byte *)(inst + 0x10);
        break;
      case 6:
        break;
      case 9:
        sourceUsage = &uStack_87c;
        passThroughR6 = (uint *)(uint)*(byte *)((int)inst + 0x3f);
        passThroughR8 = &uStack_88c;
        ((int (*)())psnAccumulateRgbSelectRead)((uint)*(byte *)((int)inst + 0x2a),uVar6,(uint)*(byte *)(inst + 0xc),
                     passThroughR6,sourceUsage,passThroughR8);
        instByte10 = *(byte *)(inst + 0x10);
      }
      if (instByte10 < 0xc) {
        uVar5 = 1 << ((int)(char)instByte10 & 0x3fU);
        if ((uVar5 & 0x61) == 0) {
          if ((uVar5 & 0xc) == 0) {
            if ((uVar5 & 0xf80) != 0) {
              passThroughR6 = (uint *)(uint)*(byte *)((int)inst + 0x3f);
              passThroughR8 = &uStack_88c;
              sourceUsage = &uStack_87c;
              ((int (*)())psnAccumulateAlphaSelectRead)((uint)*(byte *)((int)inst + 0x39),uVar6,(uint)*(byte *)(inst + 0xc)
                           ,passThroughR6,&uStack_87c,passThroughR8);
            }
            goto code_r0x000c6c50;
          }
          ((int (*)())psnAccumulateAlphaSelectRead)((uint)*(byte *)((int)inst + 0x39),uVar6,(uint)*(byte *)(inst + 0xc),
                       (uint)*(byte *)((int)inst + 0x3f),&uStack_87c,&uStack_88c);
          bVar9 = *(byte *)((int)inst + 0x3a);
        }
        else {
          ((int (*)())psnAccumulateAlphaSelectRead)((uint)*(byte *)((int)inst + 0x39),uVar6,(uint)*(byte *)(inst + 0xc),
                       (uint)*(byte *)((int)inst + 0x3f),&uStack_87c,&uStack_88c);
          ((int (*)())psnAccumulateAlphaSelectRead)((uint)*(byte *)((int)inst + 0x3a),uVar6,(uint)*(byte *)(inst + 0xc),
                       (uint)*(byte *)((int)inst + 0x3f),&uStack_87c,&uStack_88c);
          bVar9 = *(byte *)((int)inst + 0x3b);
        }
        passThroughR8 = &uStack_88c;
        passThroughR6 = (uint *)(uint)*(byte *)((int)inst + 0x3f);
        sourceUsage = &uStack_87c;
        ((int (*)())psnAccumulateAlphaSelectRead)((uint)bVar9,uVar6,(uint)*(byte *)(inst + 0xc),passThroughR6,&uStack_87c,passThroughR8);
      }
code_r0x000c6c50:
      uVar3 = *(ushort *)((int)inst + 0xe);
      param_8 = (uint)uVar3;
      uStack_87c = CONCAT22(uVar3,(*(unsigned short *)((unsigned char *)&(uStack_87c) + 2)));
      uStack_878 = CONCAT22(*(undefined2 *)(inst + 4),(*(unsigned short *)((unsigned char *)&(uStack_878) + 2)));
      uStack_874 = CONCAT22(*(undefined2 *)((int)inst + 0x12),(*(unsigned short *)((unsigned char *)&(uStack_874) + 2)));
      uStack_870 = CONCAT22(*(undefined2 *)((int)inst + 0x1a),(*(unsigned short *)((unsigned char *)&(uStack_870) + 2)));
      instShort7 = *(ushort *)(inst + 7);
      uVar6 = (uint)instShort7;
      uStack_86c = CONCAT22(instShort7,(*(unsigned short *)((unsigned char *)&(uStack_86c) + 2)));
      uStack_888 = CONCAT22(*(undefined2 *)(inst + 4),(*(unsigned short *)((unsigned char *)&(uStack_888) + 2)));
      uStack_884 = CONCAT22(*(undefined2 *)((int)inst + 0x1a),(*(unsigned short *)((unsigned char *)&(uStack_884) + 2)));
      uStack_88c = CONCAT22(uVar3,(*(unsigned short *)((unsigned char *)&(uStack_88c) + 2)));
      uStack_880 = CONCAT22(instShort7,(*(unsigned short *)((unsigned char *)&(uStack_880) + 2)));
      uStack_868 = CONCAT22(*(undefined2 *)((int)inst + 0x1e),(*(unsigned short *)((unsigned char *)&(uStack_868) + 2)));
      ((int (*)())psnRaAssignDefinition)(&uStack_87c,&puStack_898,&puStack_8a8,passThroughR6,sourceUsage,passThroughR8,uVar6,param_8);
      *(ushort *)((int)inst + 0xe) = (*(unsigned short *)((unsigned char *)&(uStack_87c) + 0));
      ((int (*)())psnRaAssignDefinition)(&uStack_878,&puStack_898,&puStack_8a8,passThroughR6,sourceUsage,passThroughR8,uVar6,param_8);
      *(undefined2 *)(inst + 4) = (*(unsigned short *)((unsigned char *)&(uStack_878) + 0));
      ((int (*)())psnRaAssignDefinition)(&uStack_874,&puStack_898,&puStack_8a8,passThroughR6,sourceUsage,passThroughR8,uVar6,param_8);
      *(undefined2 *)((int)inst + 0x12) = (*(unsigned short *)((unsigned char *)&(uStack_874) + 0));
      ((int (*)())psnRaAssignDefinition)(&uStack_870,&puStack_898,&puStack_8a8,passThroughR6,sourceUsage,passThroughR8,uVar6,param_8);
      *(undefined2 *)((int)inst + 0x1a) = (*(unsigned short *)((unsigned char *)&(uStack_870) + 0));
      ((int (*)())psnRaAssignDefinition)(&uStack_86c,&puStack_898,&puStack_8a8,passThroughR6,sourceUsage,passThroughR8,uVar6,param_8);
      *(undefined2 *)(inst + 7) = (*(unsigned short *)((unsigned char *)&(uStack_86c) + 0));
      ((int (*)())psnRaAssignDefinition)(&uStack_868,&puStack_898,&puStack_8a8,passThroughR6,sourceUsage,passThroughR8,uVar6,param_8);
      *(undefined1 *)(inst + 0xd) = 0;
      *(undefined2 *)((int)inst + 0x1e) = (*(unsigned short *)((unsigned char *)&(uStack_868) + 0));
      if ((lastVisitedInst != (uint *)0x0) && (*lastVisitedInst - 3 < 2)) {
        loopIndex = 0;
        passThroughR6 = (uint *)(auStack_8b8 + 4);
        passThroughR8 = (undefined4 *)(uint)*(ushort *)(inst + 3);
        param_8 = (uint)*(ushort *)(inst + 6);
        sourceUsage = &uStack_8ac;
        uVar6 = -(uint)*(byte *)(inst + 8) >> 0x1c & 8 | (uint)*(byte *)(inst + 5);
        do {
          if ((passThroughR8 == (undefined4 *)(uint)*(ushort *)(loopIndex + (int)passThroughR6)) &&
             ((uVar6 & *(ushort *)((int)auStack_8b8 + loopIndex)) != 0)) {
            *(undefined1 *)(inst + 0xd) = 1;
          }
          if ((param_8 == *(ushort *)(loopIndex + (int)sourceUsage)) &&
             ((uVar6 & *(ushort *)((int)auStack_8b8 + loopIndex + 4)) != 0)) {
            *(undefined1 *)(inst + 0xd) = 1;
          }
          bVar1 = loopIndex != 2;
          loopIndex = loopIndex + 2;
        } while (bVar1);
      }
      (*(unsigned short *)((unsigned char *)&(uStack_8b0) + 0)) = *(undefined2 *)((int)inst + 0xe);
      (*(unsigned short *)((unsigned char *)&(uStack_8b0) + 2)) = *(undefined2 *)(inst + 4);
      (*(unsigned short *)((unsigned char *)&(uStack_8ac) + 0)) = *(undefined2 *)((int)inst + 0x1a);
      uVar6 = (uint)*(ushort *)(inst + 7);
      auStack_8b8[0] = (*(unsigned short *)((unsigned char *)&(uStack_88c) + 2));
      auStack_8b8[1] = (*(unsigned short *)((unsigned char *)&(uStack_888) + 2));
      (*(unsigned short *)((unsigned char *)&(uStack_8ac) + 2)) = *(ushort *)(inst + 7);
      auStack_8b8[2] = (*(unsigned short *)((unsigned char *)&(uStack_884) + 2));
      auStack_8b8[3] = (*(unsigned short *)((unsigned char *)&(uStack_880) + 2));
LAB_000c6e10:
      loopIndex2 = loopIndex2 + 1;
      lastVisitedInst = inst;
      inst = inst + -0x12;
    } while (psnProgramWord8 != loopIndex2);
  }
  ((int (*)())FUN_000c5e60)(psnProgram);
  return;
}

/* FUN_000c6e40 @ 0xc6e40 (12 bytes) - issue #64 live-repro: a genuine, separate function Ghidra's
 * initial analysis never split out (no standard prologue - it's a 3-instruction tail-call right
 * after the preceding function's blr, only reachable via the PC-relative function-pointer table
 * FUN_000c6ff0 builds; never found by any direct bl/b xref). Confirmed live: FUN_000cd05c calls
 * *(psnState+0x30) - previously transcribed as the raw literal (unsigned char*)0x000c6e40, which
 * pointed at these bytes as DATA instead of as this function's own real code - as
 * (arg, 0x44, param_3), landing here with psnProgram=0x44 after the ABI drops the 3rd arg; this
 * confirmed-real code is or r3,r4,r4 / li r4,1 / b 0x1a3700 (the _calloc picsymbolstub), i.e. this
 * is the allocator half of an alloc/free callback pair with the very next function, scCallbackFree
 * (_free(psnProgram)). Otherwise unreachable without this fix (issue #64). */
int FUN_000c6e40(psnState, psnProgram)
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
  undefined1 auStack_118 [264];
  
  _strcpy(auStack_118,prefix);
  length = _strlen(auStack_118);
  return printf_LDBLStub_1a3428(auStack_118 + length,0x100 - length,format,formatArg1,formatArg2,formatArg3,formatArg4,formatArg5);
}

/* scCallbackFopen @ 0xc6ef0 (88 bytes) */
int scCallbackFopen(unusedArgR3, param_2, param_3)
  undefined4 unusedArgR3;
  undefined4 param_2;
  int param_3;
{
  undefined4 uVar1;
  
  if (param_3 == 2) {
    uVar1 = _fopen(param_2,"w");
    return uVar1;
  }
  if (param_3 != 3) {
    if (param_3 == 1) {
      uVar1 = _fopen(param_2,"r");
      return uVar1;
    }
    return 0;
  }
  uVar1 = _fopen(param_2,"r+");
  return uVar1;
}

/* scCallbackFclose @ 0xc6f60 (44 bytes) */
int scCallbackFclose(unusedArgR3, param_2)
  undefined4 unusedArgR3;
  undefined4 param_2;
{
  int iVar1;
  
  iVar1 = _fclose(param_2);
  return iVar1 == 0;
}

/* scCallbackFwrite @ 0xc6f90 (40 bytes) */
int scCallbackFwrite(unusedArgR3, param_2, param_3, param_4)
  undefined4 unusedArgR3;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  
  if ((param_3 != 0) && (param_2 != 0)) {
    uVar1 = _fwrite(param_3,1,param_4,param_2);
    return uVar1;
  }
  return 0;
}

/* scCallbackFread @ 0xc6fc0 (40 bytes) */
int scCallbackFread(unusedArgR3, param_2, param_3, param_4)
  undefined4 unusedArgR3;
  int param_2;
  int param_3;
  undefined4 param_4;
{
  undefined4 uVar1;
  
  if ((param_3 != 0) && (param_2 != 0)) {
    uVar1 = _fread(param_3,1,param_4,param_2);
    return uVar1;
  }
  return 0;
}

/* FUN_000c6ff0 @ 0xc6ff0 (464 bytes) */
int FUN_000c6ff0(ctx, param_2)
  int ctx;
  int param_2;
{
  undefined *ctxPtr23d4;
  undefined4 uVar2;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  /* issue #64 live-repro: FUN_000cd05c (called below via &local_7c) reads its first argument at
   * byte offsets up to +0x4c (*(ctx+0x30)/+0x34/+0x38/+0x40/+0x44/+0x48/+0x4c), i.e. it expects
   * local_7c through local_30 (and local_54/local_50/local_4c above them) to be ONE contiguous
   * 0x54-byte buffer - confirmed directly by this function's own "_memset(&local_7c,0,0x54)" a few
   * lines down, not a guess. Left as separate scalars (same defect class as auStack_c148 and
   * local_194 in _gldChoosePixelFormat, both fixed earlier this session), the -O0 rebuild does not
   * place them contiguously, so FUN_000cd05c's offset reads miss into whatever real stack slot
   * happens to be there instead - confirmed live: corrupts far enough to zero this function's own
   * ctx, crashing on the *(ctx+0x186c)=uVar2 store a few lines below. Merged into one
   * 0x54-byte buffer (offsets confirmed per each name's own hex value, e.g. 0x7c-0x30=0x4c). */
  unsigned char local_7c_buf[0x54];
#define local_54 (*(undefined4 *)(local_7c_buf + 0x28))
#define local_50 (*(undefined4 **)(local_7c_buf + 0x2c))
#define local_4c (*(undefined **)(local_7c_buf + 0x30))
#define local_48 (*(code **)(local_7c_buf + 0x34))
#define local_44 (*(code **)(local_7c_buf + 0x38))
#define local_40 (*(code **)(local_7c_buf + 0x3c))
#define local_3c (*(code **)(local_7c_buf + 0x40))
#define local_38 (*(code **)(local_7c_buf + 0x44))
#define local_34 (*(code **)(local_7c_buf + 0x48))
#define local_30 (*(code **)(local_7c_buf + 0x4c))
#define local_7c (*(undefined4 *)(local_7c_buf + 0x00))
#define local_78 (*(undefined4 *)(local_7c_buf + 0x04))
  
  _memset(local_7c_buf,0,0x54);
  local_78 = *(undefined4 *)(ctx + 0x23d8);
  local_80 = 0;
  local_88 = 0;
  if (param_2 == 0) {
    local_7c = 0x2c;
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
      local_7c = 0x3c;
    }
    else {
      local_7c = 0x3e;
    }
  }
  local_4c = (undefined *)FUN_000c6e40;
  local_48 = scCallbackFree;
  local_54 = 2;
  local_44 = scCallbackGetFlagZero;
  local_40 = scCallbackAppendFormatted;
  local_84 = 0x7b;
  local_3c = scCallbackFopen;
  local_38 = scCallbackFclose;
  local_34 = scCallbackFwrite;
  local_30 = scCallbackFread;
  local_50 = (undefined4 *)(ctx + 0x186c);
  uVar2 = FUN_000cd05c(&local_7c,&local_88,0x10001);
  *(undefined4 *)(ctx + 0x186c) = uVar2;
  *(undefined4 *)(ctx + 0x1870) = local_84;
  return;
}
#undef local_54
#undef local_50
#undef local_4c
#undef local_48
#undef local_44
#undef local_40
#undef local_3c
#undef local_38
#undef local_34
#undef local_30
#undef local_7c
#undef local_78

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
  undefined1 uVar1;
  
  uVar1 = 2;
  if ((selector != 2) && (uVar1 = 3, selector != 3)) {
    uVar1 = selector == 1;
  }
  return uVar1;
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
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = ((int)constantIndex >> 5) + (uint)((int)constantIndex < 0 && (constantIndex & 0x1f) != 0);
  iVar3 = constantIndex * 0x10 + programRecord;
  iVar5 = iVar2 * 4 + programRecord;
  *(undefined4 *)(iVar3 + 0x1a8) = *values;
  uVar4 = *(uint *)(iVar5 + 0x188);
  *(undefined4 *)(iVar3 + 0x1ac) = values[1];
  *(undefined4 *)(iVar3 + 0x1b0) = values[2];
  valuesWordc = values[3];
  *(uint *)(iVar5 + 0x188) = 1 << (constantIndex + iVar2 * -0x20 & 0x3f) | uVar4;
  *(undefined4 *)(iVar3 + 0x1b4) = valuesWordc;
  return;
}

/* ilRecordDefinedConstantSecondary @ 0xc72f0 (88 bytes) */
int ilRecordDefinedConstantSecondary(programRecord, constantIndex, values)
  int programRecord;
  uint constantIndex;
  undefined4 *values;
{
  int iVar1;
  undefined4 valuesWordc;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = ((int)constantIndex >> 5) + (uint)((int)constantIndex < 0 && (constantIndex & 0x1f) != 0);
  iVar5 = constantIndex * 0x10 + programRecord;
  *(undefined4 *)(((unsigned char *)0x000011c8) + iVar5) = *values;
  iVar4 = iVar1 * 4 + programRecord;
  uVar3 = *(uint *)(((unsigned char *)0x000011a8) + iVar4);
  *(undefined4 *)((int)((unsigned char *)0x000011cc) + iVar5) = values[1];
  *(undefined4 *)(((unsigned char *)0x000011d0U) + iVar5) = values[2];
  valuesWordc = values[3];
  *(uint *)(((unsigned char *)0x000011a8) + iVar4) = 1 << (constantIndex + iVar1 * -0x20 & 0x3f) | uVar3;
  *(undefined4 *)(((unsigned char *)0x000011d4) + iVar5) = valuesWordc;
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

