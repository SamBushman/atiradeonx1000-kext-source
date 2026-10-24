#include "decls.h"

/* TGenericLinker__MergeCompilers @ 0x97bb21dc (200 bytes) */
int TGenericLinker__MergeCompilers(this, stage)
  unsigned char * this;
  int stage;
{
  bool symbolMissing;
  char labelDigit;
  byte chunkKind;
  int stageOffset;
  unsigned char * stageEntryCopy1;
  unsigned char * stageEntryCopy2;
  unsigned char * stageEntryCopy3;
  int objectIndexOrPhase;
  char *messageOrCharCursor;
  int objectOffsetOrTemp;
  int objectFirstChunk;
  int objectChunkCount;
  undefined4 stringLengthOrArg;
  int newChunkOrTemp;
  int compareResultOrIndex;
  char *labelDigitCursor;
  undefined4 uVar17;
  unsigned char * parseSymbol;
  unsigned char * newConstantChunk;
  uint chunkWord;
  byte *symbolChunk;
  bool success;
  int opIndexBaseOrObjectIndex;
  undefined4 *mergedSymbol;
  unsigned char * objectFunctionTable;
  int chunkLabelName;
  int chunkCursorOrTemp;
  void *infoSinkOrNewTable;
  unsigned char * stageEntry;
  unsigned char * constantChunk;
  char labelNumberText [16];
  int stageRequirementMet;
  unsigned char * stageEntrySave1;
  unsigned char * stageEntrySave2;
  unsigned char * stageEntrySave3;
  
  stageOffset = stage * 4;
  objectFirstChunk = _malloc(*(int *)(this + stageOffset + 0x20) << 2);
  objectChunkCount = _malloc(*(int *)(this + stageOffset + 0x20) << 2);
  messageOrCharCursor = DAT_a7b7bb0c;
  objectIndexOrPhase = *(int *)(this + stageOffset + 0x20);
  stageRequirementMet = 0;
  if (10000 < objectIndexOrPhase) {
    infoSinkOrNewTable = *(void **)(this + 0x84);
                    
    __ZN13TInfoSinkBase6appendEPKc(infoSinkOrNewTable,"ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(infoSinkOrNewTable,messageOrCharCursor);
    __ZN13TInfoSinkBase6appendEPKc(infoSinkOrNewTable,"\n");
  }
  success = 10000 >= objectIndexOrPhase;
  if (success) {
    stringLengthOrArg = _PPStreamCreate();
    *(undefined4 *)(this + stageOffset + 0x30) = stringLengthOrArg;
    infoSinkOrNewTable = operator_new(0x54);
    __ZN16ParseSymbolTableC1Ej(infoSinkOrNewTable,0x80);
    *(void **)(this + stageOffset + 0x28) = infoSinkOrNewTable;
    *(undefined4 *)((int)infoSinkOrNewTable + 0xc) = *(undefined4 *)(this + stageOffset + 0x30);
    if (stage == 0) {
      **(undefined4 **)(this + 0x30) = 0x8b31;
      stageRequirementMet = 0;
      *(undefined4 *)(*(int *)(this + 0x28) + 0x3c) = 0;
    }
    else {
      **(undefined4 **)(this + stageOffset + 0x30) = 0x8b30;
      stageRequirementMet = 1;
      *(undefined4 *)(*(int *)(this + stageOffset + 0x28) + 0x3c) = 1;
    }
  }
  if (success) {
    stageEntry = this + stageOffset;
    objectIndexOrPhase = 0;
    opIndexBaseOrObjectIndex = 0;
    _memset(objectFirstChunk,0,*(int *)(stageEntry + 0x20) << 2);
    _memset(objectChunkCount,0,*(int *)(stageEntry + 0x20) << 2);
    stageEntryCopy1 = stageEntry;
    stageEntryCopy2 = stageEntry;
    stageEntryCopy3 = stageEntry;
    if (0 < *(int *)(stageEntry + 0x20)) {
      do {
        stageEntrySave3 = stageEntryCopy3;
        stageEntrySave2 = stageEntryCopy2;
        stageEntrySave1 = stageEntryCopy1;
        objectOffsetOrTemp = objectIndexOrPhase * 4;
        chunkCursorOrTemp = **(int **)(*(int *)(objectOffsetOrTemp + *(int *)(stageEntry + 0x18)) + 0x20);
        while (chunkCursorOrTemp != 0) {
          newChunkOrTemp = _PPStreamChunkCreateFromChunk(chunkCursorOrTemp);
          _PPStreamChunkListAddChunk(*(undefined4 *)(*(int *)(stageEntry + 0x30) + 0x20),newChunkOrTemp);
          if (*(int *)(objectOffsetOrTemp + objectFirstChunk) == 0) {
            *(int *)(objectOffsetOrTemp + objectFirstChunk) = newChunkOrTemp;
          }
          chunkWord = *(uint *)(newChunkOrTemp + 0x10);
          *(uint *)(newChunkOrTemp + 0xc) =
               (*(uint *)(newChunkOrTemp + 0xc) & 0x3ffff) + opIndexBaseOrObjectIndex & 0x3ffff |
               *(uint *)(newChunkOrTemp + 0xc) & 0xfffc0000;
          if ((chunkWord & 0x3ffff) != 0) {
            *(uint *)(newChunkOrTemp + 0x10) = (chunkWord & 0x3ffff) + opIndexBaseOrObjectIndex & 0x3ffff | chunkWord & 0xfffc0000;
          }
          if (*(int *)(newChunkOrTemp + 0x40) != 0) {
            chunkLabelName = newChunkOrTemp + 0x44;
            stringLengthOrArg = _strlen("gl__WhileBody_");
            compareResultOrIndex = _strncmp(chunkLabelName,"gl__WhileBody_",stringLengthOrArg);
            if (compareResultOrIndex != 0) {
              stringLengthOrArg = _strlen("gl__WhileEnd_");
              compareResultOrIndex = _strncmp(chunkLabelName,"gl__WhileEnd_",stringLengthOrArg);
              if (compareResultOrIndex != 0) {
                stringLengthOrArg = _strlen("gl__WhileStart_");
                compareResultOrIndex = _strncmp(chunkLabelName,"gl__WhileStart_",stringLengthOrArg);
                if (compareResultOrIndex != 0) {
                  stringLengthOrArg = _strlen("gl__WhileEndIf_");
                  compareResultOrIndex = _strncmp(chunkLabelName,"gl__WhileEndIf_",stringLengthOrArg);
                  if (compareResultOrIndex != 0) {
                    stringLengthOrArg = _strlen("gl__IfElse");
                    compareResultOrIndex = _strncmp(chunkLabelName,"gl__IfElse",stringLengthOrArg);
                    if (compareResultOrIndex != 0) {
                      stringLengthOrArg = _strlen("gl__IfEnd_");
                      compareResultOrIndex = _strncmp(chunkLabelName,"gl__IfEnd_",stringLengthOrArg);
                      if (compareResultOrIndex != 0) goto code_r0x97bb257c;
                    }
                  }
                }
              }
            }
            _sprintf(labelNumberText,"%04d",objectIndexOrPhase);
            labelDigitCursor = (char *)(newChunkOrTemp + 0x44);
            messageOrCharCursor = labelNumberText;
            newChunkOrTemp = 4;
            do {
              labelDigit = *messageOrCharCursor;
              messageOrCharCursor = messageOrCharCursor + 1;
              *labelDigitCursor = labelDigit;
              labelDigitCursor = labelDigitCursor + 1;
              newChunkOrTemp = newChunkOrTemp + -1;
            } while (newChunkOrTemp != 0);
          }
code_r0x97bb257c:
          chunkCursorOrTemp = *(int *)(chunkCursorOrTemp + 8);
          *(int *)(objectOffsetOrTemp + objectChunkCount) = *(int *)(objectOffsetOrTemp + objectChunkCount) + 1;
        }
        stageEntryCopy1 = stageEntrySave1;
        stageEntryCopy2 = stageEntrySave3;
        for (chunkCursorOrTemp = **(int **)(*(int *)(objectOffsetOrTemp + *(int *)(stageEntry + 0x18)) + 0x24);
            stageEntrySave1 = stageEntryCopy1, stageEntrySave3 = stageEntryCopy2, chunkCursorOrTemp != 0; chunkCursorOrTemp = *(int *)(chunkCursorOrTemp + 8)) {
          newChunkOrTemp = _PPStreamChunkCreateFromChunk(chunkCursorOrTemp);
          _PPStreamChunkListAddChunk(*(undefined4 *)(*(int *)(stageEntry + 0x30) + 0x24),newChunkOrTemp);
          *(int *)(newChunkOrTemp + 0xc) = *(int *)(newChunkOrTemp + 0xc) + opIndexBaseOrObjectIndex;
          if (*(int *)(newChunkOrTemp + 0x10) != 0) {
            chunkLabelName = newChunkOrTemp + 0x14;
            stringLengthOrArg = _strlen("gl__WhileBody_");
            compareResultOrIndex = _strncmp(chunkLabelName,"gl__WhileBody_",stringLengthOrArg);
            if (compareResultOrIndex != 0) {
              stringLengthOrArg = _strlen("gl__WhileEnd_");
              compareResultOrIndex = _strncmp(chunkLabelName,"gl__WhileEnd_",stringLengthOrArg);
              if (compareResultOrIndex != 0) {
                stringLengthOrArg = _strlen("gl__WhileStart_");
                compareResultOrIndex = _strncmp(chunkLabelName,"gl__WhileStart_",stringLengthOrArg);
                if (compareResultOrIndex != 0) {
                  stringLengthOrArg = _strlen("gl__WhileEndIf_");
                  compareResultOrIndex = _strncmp(chunkLabelName,"gl__WhileEndIf_",stringLengthOrArg);
                  if (compareResultOrIndex != 0) {
                    stringLengthOrArg = _strlen("gl__IfElse");
                    compareResultOrIndex = _strncmp(chunkLabelName,"gl__IfElse",stringLengthOrArg);
                    if (compareResultOrIndex != 0) {
                      stringLengthOrArg = _strlen("gl__IfEnd_");
                      compareResultOrIndex = _strncmp(chunkLabelName,"gl__IfEnd_",stringLengthOrArg);
                      if (compareResultOrIndex != 0) goto code_r0x97bb26e0;
                    }
                  }
                }
              }
            }
            _sprintf(labelNumberText,"%04d",objectIndexOrPhase);
            labelDigitCursor = (char *)(newChunkOrTemp + 0x14);
            messageOrCharCursor = labelNumberText;
            newChunkOrTemp = 4;
            do {
              labelDigit = *messageOrCharCursor;
              messageOrCharCursor = messageOrCharCursor + 1;
              *labelDigitCursor = labelDigit;
              labelDigitCursor = labelDigitCursor + 1;
              newChunkOrTemp = newChunkOrTemp + -1;
            } while (newChunkOrTemp != 0);
          }
code_r0x97bb26e0:
          stageEntryCopy1 = stageEntrySave1;
          stageEntryCopy2 = stageEntrySave3;
        }
        newChunkOrTemp = 0;
        objectFunctionTable = *(unsigned char **)(*(int *)(objectOffsetOrTemp + *(int *)(stageEntry + 8)) + 0x6c);
        chunkCursorOrTemp = *(int *)(objectFunctionTable + 4);
        if (0 < chunkCursorOrTemp) {
          do {
            compareResultOrIndex = 0;
            if (0 < *(int *)(*(int *)(stageEntryCopy1 + 0x38) + 4)) {
              do {
                stringLengthOrArg = FunctionTable__getFunctionName(*(unsigned char **)(stageEntryCopy2 + 0x38),compareResultOrIndex);
                uVar17 = FunctionTable__getFunctionName(objectFunctionTable,newChunkOrTemp);
                chunkCursorOrTemp = _strcmp(stringLengthOrArg,uVar17);
                if (chunkCursorOrTemp == 0) {
                  chunkCursorOrTemp = FunctionTable__getFirstOp(*(unsigned char **)(stageEntryCopy2 + 0x38),compareResultOrIndex);
                  FunctionTable__setFirstOp
                            (*(unsigned char **)(stageEntryCopy2 + 0x38),compareResultOrIndex,chunkCursorOrTemp + opIndexBaseOrObjectIndex);
                  chunkCursorOrTemp = FunctionTable__getLastOp(*(unsigned char **)(stageEntryCopy2 + 0x38),compareResultOrIndex);
                  FunctionTable__setLastOp
                            (*(unsigned char **)(stageEntryCopy2 + 0x38),compareResultOrIndex,chunkCursorOrTemp + opIndexBaseOrObjectIndex);
                }
                compareResultOrIndex = compareResultOrIndex + 1;
              } while (compareResultOrIndex < *(int *)(*(int *)(stageEntryCopy2 + 0x38) + 4));
              chunkCursorOrTemp = *(int *)(objectFunctionTable + 4);
            }
            newChunkOrTemp = newChunkOrTemp + 1;
          } while (newChunkOrTemp < chunkCursorOrTemp);
        }
        opIndexBaseOrObjectIndex = opIndexBaseOrObjectIndex + *(int *)(objectOffsetOrTemp + objectChunkCount);
        if (*(int *)(*(int *)(objectOffsetOrTemp + *(int *)(stageEntrySave2 + 8)) + 0xa4) != 0) {
          stageRequirementMet = 1;
        }
        objectIndexOrPhase = objectIndexOrPhase + 1;
        stageEntryCopy1 = stageEntrySave1;
        stageEntryCopy2 = stageEntrySave2;
        stageEntryCopy3 = stageEntrySave3;
      } while (objectIndexOrPhase < *(int *)(stageEntrySave2 + 0x20));
    }
    messageOrCharCursor = UNK_a7b7bb10;
    if (stageRequirementMet == 0) {
      infoSinkOrNewTable = *(void **)(this + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(infoSinkOrNewTable,"ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(infoSinkOrNewTable,messageOrCharCursor);
      success = false;
      __ZN13TInfoSinkBase6appendEPKc(infoSinkOrNewTable,"\n");
    }
  }
  if (success) {
    objectIndexOrPhase = 1;
    do {
      opIndexBaseOrObjectIndex = 0;
      if (0 < *(int *)(this + stageOffset + 0x20)) {
        do {
          objectOffsetOrTemp = opIndexBaseOrObjectIndex * 4;
          for (parseSymbol = (unsigned char *)
                         ParseSymbolTable__NextSymbol
                                   (*(unsigned char **)(objectOffsetOrTemp + *(int *)(this + stageOffset + 0x10)),
                                    (unsigned char *)0x0); parseSymbol != (unsigned char *)0x0;
              parseSymbol = (unsigned char *)
                        ParseSymbolTable__NextSymbol
                                  (*(unsigned char **)(objectOffsetOrTemp + *(int *)(this + stageOffset + 0x10)),
                                   parseSymbol)) {
            if (objectIndexOrPhase == *(int *)(parseSymbol + 0x54)) {
              mergedSymbol = (undefined4 *)0x0;
              if (*(int *)(parseSymbol + 0x38) == 0) {
                symbolMissing = true;
code_r0x97bb2ab4:
                if (symbolMissing) goto code_r0x97bb2ab8;
              }
              else {
                mergedSymbol = (undefined4 *)
                          ParseSymbolTable__FindGlobalSymbolByName
                                    (*(unsigned char **)(this + stageOffset + 0x28),
                                     *(char **)(parseSymbol + 0x14));
                symbolMissing = mergedSymbol == (undefined4 *)0x0;
                if (!symbolMissing) {
                  if (*(short *)(mergedSymbol + 0xb) == *(short *)(parseSymbol + 0x2c)) {
                    if (*(short *)((int)mergedSymbol + 0x2e) == *(short *)(parseSymbol + 0x2e))
                    goto code_r0x97bb2ab4;
                    stringLengthOrArg = mergedSymbol[5];
                    chunkCursorOrTemp = _strlen(UNK_a7b7bb18);
                    newChunkOrTemp = _strlen(stringLengthOrArg);
                    compareResultOrIndex = _strlen((&_shaderString)[stage]);
                    messageOrCharCursor = (char *)_malloc(chunkCursorOrTemp + newChunkOrTemp + compareResultOrIndex + 1);
                    _sprintf(messageOrCharCursor,UNK_a7b7bb18,stringLengthOrArg,(&_shaderString)[stage]);
                    infoSinkOrNewTable = *(void **)(this + 0x84);
                    
                  }
                  else {
                    stringLengthOrArg = mergedSymbol[5];
                    chunkCursorOrTemp = _strlen(UNK_a7b7bb14);
                    newChunkOrTemp = _strlen(stringLengthOrArg);
                    compareResultOrIndex = _strlen((&_shaderString)[stage]);
                    messageOrCharCursor = (char *)_malloc(chunkCursorOrTemp + newChunkOrTemp + compareResultOrIndex + 1);
                    _sprintf(messageOrCharCursor,UNK_a7b7bb14,stringLengthOrArg,(&_shaderString)[stage]);
                    infoSinkOrNewTable = *(void **)(this + 0x84);
                    
                  }
                  __ZN13TInfoSinkBase6appendEPKc(infoSinkOrNewTable,"ERROR: ");
                  __ZN13TInfoSinkBase6appendEPKc(infoSinkOrNewTable,messageOrCharCursor);
                  __ZN13TInfoSinkBase6appendEPKc(infoSinkOrNewTable,"\n");
                  _free(messageOrCharCursor);
                  success = false;
                  goto code_r0x97bb2ab4;
                }
code_r0x97bb2ab8:
                stringLengthOrArg = 0;
                uVar17 = 0;
                if ((objectIndexOrPhase != 0) && (symbolChunk = *(byte **)parseSymbol, symbolChunk != (byte *)0x0)) {
                  chunkKind = *symbolChunk;
                  if (chunkKind != 2) {
                    if (chunkKind < 3) {
                      if ((chunkKind == 0) &&
                         (chunkCursorOrTemp = **(int **)(*(int *)(objectOffsetOrTemp + *(int *)(this + stageOffset + 0x18)) + 8),
                         chunkCursorOrTemp != 0)) {
                        do {
                          if (*(short *)(symbolChunk + 0x12) == *(short *)(chunkCursorOrTemp + 0xe)) {
                            stringLengthOrArg = 1;
                          }
                          if (*(short *)(symbolChunk + 0x12) == *(short *)(chunkCursorOrTemp + 0x12)) {
                            uVar17 = 1;
                          }
                          chunkCursorOrTemp = *(int *)(chunkCursorOrTemp + 8);
                        } while (chunkCursorOrTemp != 0);
                      }
                    }
                    else if ((chunkKind == 3) &&
                            (chunkCursorOrTemp = **(int **)(*(int *)(objectOffsetOrTemp + *(int *)(this + stageOffset + 0x18)) +
                                                0x14), chunkCursorOrTemp != 0)) {
                      do {
                        if (*(short *)(symbolChunk + 0x12) == *(short *)(chunkCursorOrTemp + 0xe)) {
                          stringLengthOrArg = 1;
                        }
                        if (*(short *)(symbolChunk + 0x12) == *(short *)(chunkCursorOrTemp + 0x12)) {
                          uVar17 = 1;
                        }
                        chunkCursorOrTemp = *(int *)(chunkCursorOrTemp + 8);
                      } while (chunkCursorOrTemp != 0);
                    }
                  }
                }
                mergedSymbol = (undefined4 *)
                          ParseSymbolTable__AddFromExternalSymbol
                                    (*(unsigned char **)(this + stageOffset + 0x28),parseSymbol,stringLengthOrArg,
                                     uVar17);
              }
              if ((success != true) || (mergedSymbol == (undefined4 *)0x0)) {
                if ((success == true) && (mergedSymbol == (undefined4 *)0x0)) {
                  stringLengthOrArg = *(undefined4 *)(parseSymbol + 0x14);
                  chunkCursorOrTemp = _strlen(DAT_a7b7bbc0);
                  newChunkOrTemp = _strlen(stringLengthOrArg);
                  messageOrCharCursor = (char *)_malloc(chunkCursorOrTemp + newChunkOrTemp + 1);
                  _sprintf(messageOrCharCursor,UNK_a7b7bb90,stringLengthOrArg);
                  infoSinkOrNewTable = *(void **)(this + 0x84);
                    
                  __ZN13TInfoSinkBase6appendEPKc(infoSinkOrNewTable,"ERROR: ");
                  __ZN13TInfoSinkBase6appendEPKc(infoSinkOrNewTable,messageOrCharCursor);
                  __ZN13TInfoSinkBase6appendEPKc(infoSinkOrNewTable,"\n");
                  _free(messageOrCharCursor);
                  success = false;
                }
              }
              else {
                chunkCursorOrTemp = TGenericLinker__FindChunkDelta(this,*(unsigned char **)parseSymbol,(unsigned char *)*mergedSymbol)
                ;
                if (chunkCursorOrTemp != 0) {
                  newChunkOrTemp = ((int (*)())GetVec4sForType)((uint)*(ushort *)(parseSymbol + 0x2c));
                  UpdateOperations(*(unsigned char **)(objectOffsetOrTemp + objectFirstChunk),
                                   (unsigned char *)
                                   **(undefined4 **)
                                     (*(int *)(objectOffsetOrTemp + *(int *)(this + stageOffset + 0x18)) + 0x20),
                                   *(int *)(objectOffsetOrTemp + objectChunkCount),*(unsigned char **)parseSymbol,newChunkOrTemp,
                                   chunkCursorOrTemp);
                }
              }
            }
          }
          opIndexBaseOrObjectIndex = opIndexBaseOrObjectIndex + 1;
        } while (opIndexBaseOrObjectIndex < *(int *)(this + stageOffset + 0x20));
      }
      objectIndexOrPhase = objectIndexOrPhase + -1;
    } while (-1 < objectIndexOrPhase);
    if (success == true) {
      objectIndexOrPhase = 0;
      if (0 < *(int *)(this + stageOffset + 0x20)) {
        do {
          opIndexBaseOrObjectIndex = objectIndexOrPhase * 4;
          for (constantChunk = (unsigned char *)
                         **(undefined4 **)(*(int *)(opIndexBaseOrObjectIndex + *(int *)(this + stageOffset + 0x18)) + 0x10);
              constantChunk != (unsigned char *)0x0; constantChunk = *(unsigned char **)(constantChunk + 8)) {
            chunkWord = *(uint *)(constantChunk + 0xc);
            if ((chunkWord & 0x1f0000) == 0x110000) {
              objectOffsetOrTemp = *(int *)(*(int *)(this + stageOffset + 0x28) + 0x24);
              *(int *)(*(int *)(this + stageOffset + 0x28) + 0x24) = objectOffsetOrTemp + 1;
              newConstantChunk = (unsigned char *)_PPStreamChunkCreateFromChunk(constantChunk);
              _PPStreamChunkListAddChunk
                        (*(undefined4 *)(*(int *)(this + stageOffset + 0x30) + 0x10),newConstantChunk);
              *(short *)(newConstantChunk + 0x12) = (short)objectOffsetOrTemp;
              objectOffsetOrTemp = TGenericLinker__FindChunkDelta(this,constantChunk,newConstantChunk);
              UpdateOperations(*(unsigned char **)(opIndexBaseOrObjectIndex + objectFirstChunk),
                               (unsigned char *)
                               **(undefined4 **)
                                 (*(int *)(opIndexBaseOrObjectIndex + *(int *)(this + stageOffset + 0x18)) + 0x20),
                               *(int *)(opIndexBaseOrObjectIndex + objectChunkCount),constantChunk,1,objectOffsetOrTemp);
              *(undefined2 *)(newConstantChunk + 0xe) =
                   *(undefined2 *)(*(int *)(*(int *)(this + stageOffset + 0x30) + 0x2c) + 10);
              objectOffsetOrTemp = _PPStreamChunkListChunkAtIndex
                                 (*(undefined4 *)
                                   (*(int *)(opIndexBaseOrObjectIndex + *(int *)(this + stageOffset + 0x18)) + 0x2c),
                                  chunkWord & 0xffff);
              _PPStreamAddConstant(*(undefined4 *)(this + stageOffset + 0x30),objectOffsetOrTemp + 0xc);
            }
          }
          objectIndexOrPhase = objectIndexOrPhase + 1;
        } while (objectIndexOrPhase < *(int *)(this + stageOffset + 0x20));
      }
      objectFirstChunk = 0;
      objectIndexOrPhase = 0;
      if (0 < *(int *)(this + stageOffset + 0x20)) {
        do {
          objectChunkCount = 0;
          for (opIndexBaseOrObjectIndex = **(int **)(*(int *)(objectFirstChunk * 4 + *(int *)(this + stageOffset + 0x18)) + 0xc);
              opIndexBaseOrObjectIndex != 0; opIndexBaseOrObjectIndex = *(int *)(opIndexBaseOrObjectIndex + 8)) {
            objectChunkCount = objectChunkCount + 1;
            if (objectIndexOrPhase < objectChunkCount) {
              stringLengthOrArg = _PPStreamChunkCreateFromChunk(opIndexBaseOrObjectIndex);
              _PPStreamChunkListAddChunk
                        (*(undefined4 *)(*(int *)(this + stageOffset + 0x30) + 0xc),stringLengthOrArg);
              objectIndexOrPhase = objectChunkCount;
            }
          }
          objectFirstChunk = objectFirstChunk + 1;
        } while (objectFirstChunk < *(int *)(this + stageOffset + 0x20));
      }
      objectIndexOrPhase = 0;
      if (0 < *(int *)(this + stageOffset + 0x20)) {
        do {
          for (objectFirstChunk = **(int **)(*(int *)(objectIndexOrPhase * 4 + *(int *)(this + stageOffset + 0x18)) + 0x30);
              objectFirstChunk != 0; objectFirstChunk = *(int *)(objectFirstChunk + 8)) {
            objectChunkCount = **(int **)(*(int *)(this + stageOffset + 0x30) + 0x30);
            if (objectChunkCount != 0) {
              do {
                if (*(char *)(objectChunkCount + 0xf) == *(char *)(objectFirstChunk + 0xf)) goto code_r0x97bb2f70;
                objectChunkCount = *(int *)(objectChunkCount + 8);
              } while (objectChunkCount != 0);
            }
            stringLengthOrArg = _PPStreamChunkCreateFromChunk(objectFirstChunk);
            _PPStreamChunkListAddChunk(*(undefined4 *)(*(int *)(this + stageOffset + 0x30) + 0x30),stringLengthOrArg)
            ;
code_r0x97bb2f70: ;
          }
          objectIndexOrPhase = objectIndexOrPhase + 1;
        } while (objectIndexOrPhase < *(int *)(this + stageOffset + 0x20));
      }
    }
  }
  if (success == false) {
    if (*(int *)(this + stageOffset + 0x30) != 0) {
      _PPStreamFree(*(int *)(this + stageOffset + 0x30));
    }
    infoSinkOrNewTable = *(void **)(this + stageOffset + 0x28);
    *(undefined4 *)(this + stageOffset + 0x30) = 0;
    if (infoSinkOrNewTable != (void *)0x0) {
      __ZN16ParseSymbolTableD1Ev(infoSinkOrNewTable);
      __ZdlPv(infoSinkOrNewTable);
    }
    *(undefined4 *)(this + stageOffset + 0x28) = 0;
  }
  return success;
}

/* TGenericLinker__CreateFromStreamWithSymbolTableUpdate @ 0x97bb2ff0 (820 bytes) */
int TGenericLinker__CreateFromStreamWithSymbolTableUpdate(this, _PPStream, parseSymbolTable)
  unsigned char * this;
  unsigned char * _PPStream;
  unsigned char * parseSymbolTable;
{
  int compareResult;
  char *errorText;
  undefined4 *newStream;
  unsigned char * symbolChunkCopy;
  undefined4 plainChunkCopy;
  unsigned char * symbolChunk;
  int plainChunk;
  void *infoSink;
  
  newStream = (undefined4 *)_PPStreamCreate();
  *newStream = *(undefined4 *)_PPStream;
  *(undefined4 **)(parseSymbolTable + 0xc) = newStream;
  for (symbolChunk = (unsigned char *)**(undefined4 **)(_PPStream + 4); symbolChunk != (unsigned char *)0x0;
      symbolChunk = *(unsigned char **)(symbolChunk + 8)) {
    symbolChunkCopy = (unsigned char *)_PPStreamChunkCreateFromChunk(symbolChunk);
    _PPStreamChunkListAddChunk(newStream[1],symbolChunkCopy);
    ParseSymbolTable__ChangeChunk(parseSymbolTable,symbolChunk,symbolChunkCopy,1);
  }
  for (plainChunk = **(int **)(_PPStream + 8); plainChunk != 0; plainChunk = *(int *)(plainChunk + 8)) {
    plainChunkCopy = _PPStreamChunkCreateFromChunk(plainChunk);
    _PPStreamChunkListAddChunk(newStream[2],plainChunkCopy);
  }
  for (plainChunk = **(int **)(_PPStream + 0xc); plainChunk != 0; plainChunk = *(int *)(plainChunk + 8)) {
    plainChunkCopy = _PPStreamChunkCreateFromChunk(plainChunk);
    _PPStreamChunkListAddChunk(newStream[3],plainChunkCopy);
  }
  for (symbolChunk = (unsigned char *)**(undefined4 **)(_PPStream + 0x10); symbolChunk != (unsigned char *)0x0
      ; symbolChunk = *(unsigned char **)(symbolChunk + 8)) {
    symbolChunkCopy = (unsigned char *)_PPStreamChunkCreateFromChunk(symbolChunk);
    _PPStreamChunkListAddChunk(newStream[4],symbolChunkCopy);
    ParseSymbolTable__ChangeChunk(parseSymbolTable,symbolChunk,symbolChunkCopy,1);
  }
  for (plainChunk = **(int **)(_PPStream + 0x14); plainChunk != 0; plainChunk = *(int *)(plainChunk + 8)) {
    plainChunkCopy = _PPStreamChunkCreateFromChunk(plainChunk);
    _PPStreamChunkListAddChunk(newStream[5],plainChunkCopy);
  }
  for (symbolChunk = (unsigned char *)**(undefined4 **)(_PPStream + 0x18); symbolChunk != (unsigned char *)0x0
      ; symbolChunk = *(unsigned char **)(symbolChunk + 8)) {
    symbolChunkCopy = (unsigned char *)_PPStreamChunkCreateFromChunk(symbolChunk);
    _PPStreamChunkListAddChunk(newStream[6],symbolChunkCopy);
    ParseSymbolTable__ChangeChunk(parseSymbolTable,symbolChunk,symbolChunkCopy,1);
  }
  for (symbolChunk = (unsigned char *)**(undefined4 **)(_PPStream + 0x1c); symbolChunk != (unsigned char *)0x0
      ; symbolChunk = *(unsigned char **)(symbolChunk + 8)) {
    symbolChunkCopy = (unsigned char *)_PPStreamChunkCreateFromChunk(symbolChunk);
    _PPStreamChunkListAddChunk(newStream[7],symbolChunkCopy);
    ParseSymbolTable__ChangeChunk(parseSymbolTable,symbolChunk,symbolChunkCopy,1);
  }
  for (plainChunk = **(int **)(_PPStream + 0x20); plainChunk != 0; plainChunk = *(int *)(plainChunk + 8)) {
    plainChunkCopy = _PPStreamChunkCreateFromChunk(plainChunk);
    _PPStreamChunkListAddChunk(newStream[8],plainChunkCopy);
  }
  for (plainChunk = **(int **)(_PPStream + 0x24); plainChunk != 0; plainChunk = *(int *)(plainChunk + 8)) {
    plainChunkCopy = _PPStreamChunkCreateFromChunk(plainChunk);
    _PPStreamChunkListAddChunk(newStream[9],plainChunkCopy);
  }
  for (plainChunk = **(int **)(_PPStream + 0x2c); plainChunk != 0; plainChunk = *(int *)(plainChunk + 8)) {
    plainChunkCopy = _PPStreamChunkCreateFromChunk(plainChunk);
    _PPStreamChunkListAddChunk(newStream[0xb],plainChunkCopy);
  }
  for (plainChunk = **(int **)(_PPStream + 0x28); plainChunk != 0; plainChunk = *(int *)(plainChunk + 8)) {
    plainChunkCopy = _PPStreamChunkCreateFromChunk(plainChunk);
    _PPStreamChunkListAddChunk(newStream[10],plainChunkCopy);
  }
  for (plainChunk = **(int **)(_PPStream + 0x30); plainChunk != 0; plainChunk = *(int *)(plainChunk + 8)) {
    plainChunkCopy = _PPStreamChunkCreateFromChunk(plainChunk);
    _PPStreamChunkListAddChunk(newStream[0xc],plainChunkCopy);
  }
  compareResult = _PPStreamCompare(_PPStream,newStream);
  errorText = DAT_a7b7bb88;
  if (compareResult == 1) {
    infoSink = *(void **)(this + 0x84);
                    
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(infoSink,errorText);
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
    _PPStreamFree(newStream);
    newStream = (undefined4 *)0x0;
  }
  return newStream;
}

/* TGenericLinker__RemoveUnreachableFunctions @ 0x97bb33bc (480 bytes) */
int TGenericLinker__RemoveUnreachableFunctions(this)
  unsigned char * this;
{
  int shaderStringLen;
  int nameLen;
  int nextChunk2;
  int opChunk;
  uint lastOp;
  int length;
  int compareResult;
  int functionName;
  int length2;
  bool removedAny;
  int stageOffset;
  int nextChunk;
  int callChunk;
  int callNameCompare;
  uint firstOp;
  int length3;
  char *allocation;
  int stage;
  int fnIdx;
  uint chunkHeader;
  void *infoSink;
  int fnIdxBase;
  
  stage = 0;
code_r0x97bb33e4:
  stageOffset = stage * 4;
code_r0x97bb33e8:
  removedAny = false;
  fnIdx = 0;
  if ((*(int *)(this + stageOffset + 0x38) != 0) && (0 < *(int *)(*(int *)(this + stageOffset + 0x38) + 4))) {
code_r0x97bb3410:
    functionName = FunctionTable__getFunctionName(*(unsigned char **)(this + stageOffset + 0x38),fnIdx);
    compareResult = _memcmp(functionName,"main(",6);
    fnIdxBase = fnIdx;
    if (compareResult != 0) {
      for (callChunk = **(int **)(*(int *)(this + stageOffset + 0x30) + 0x20); callChunk != 0;
          callChunk = *(int *)(callChunk + 8)) {
        if ((((*(uint *)(callChunk + 0xc) & 0x3fc0000) == 0x1300000) && (*(int *)(callChunk + 0x40) != 0))
           && (callNameCompare = _strcmp(callChunk + 0x44,functionName), callNameCompare == 0)) goto LAB_97bb37a8;
      }
      for (opChunk = **(int **)(*(int *)(this + stageOffset + 0x30) + 0x20); opChunk != 0;
          opChunk = *(int *)(opChunk + 8)) {
        chunkHeader = *(uint *)(opChunk + 0xc);
        firstOp = FunctionTable__getFirstOp(*(unsigned char **)(this + stageOffset + 0x38),fnIdx);
        if ((chunkHeader & 0x3ffff) == firstOp) {
          removedAny = false;
          goto LAB_97bb361c;
        }
      }
      length2 = _strlen(DAT_a7b7baec);
      length = _strlen((&_shaderString)[stage]);
      nameLen = _strlen(functionName);
      allocation = (char *)_malloc(length2 + length + nameLen + 9);
      FunctionTable__getFirstOp(*(unsigned char **)(this + stageOffset + 0x38),fnIdx);
      _sprintf(allocation,DAT_a7b7baec,functionName,(&_shaderString)[stage]);
      infoSink = *(void **)(this + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(infoSink,allocation);
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
      _free(allocation);
      goto code_r0x97bb3790;
    }
    goto LAB_97bb37a8;
  }
  goto LAB_97bb37d4;
  while( true ) {
    if ((*(uint *)(opChunk + 0xc) & 0x3ffff) == 0) {
      length = _strlen(DAT_a7b7baf0);
      shaderStringLen = _strlen((&_shaderString)[stage]);
      length3 = _strlen(functionName);
      allocation = (char *)_malloc(length + shaderStringLen + length3 + 1);
      _sprintf(allocation,DAT_a7b7baf0,functionName,(&_shaderString)[stage]);
      infoSink = *(void **)(this + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(infoSink,allocation);
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
      _free(allocation);
    }
    else {
      _PPStreamRemoveLabelsAtOperationIndex
                (*(undefined4 *)(this + stageOffset + 0x30),*(uint *)(opChunk + 0xc) & 0x3ffff);
      nextChunk2 = *(int *)(opChunk + 8);
      removedAny = nextChunk2 == 0;
      if (!removedAny) {
        *(uint *)(nextChunk2 + 0xc) =
             (*(uint *)(opChunk + 0xc) >> 0x1a & 7) << 0x1a | *(uint *)(nextChunk2 + 0xc) & 0xe3ffffff;
      }
      _PPStreamChunkListRemoveChunk(*(undefined4 *)(*(int *)(this + stageOffset + 0x30) + 0x20),opChunk);
      opChunk = nextChunk2;
    }
    if (removedAny) break;
LAB_97bb361c:
    chunkHeader = *(uint *)(opChunk + 0xc);
    lastOp = FunctionTable__getLastOp(*(unsigned char **)(this + stageOffset + 0x38),fnIdx);
    if ((chunkHeader & 0x3ffff) == lastOp) {
      if (!removedAny) {
        nextChunk = *(int *)(opChunk + 8);
        if (nextChunk != 0) {
          *(uint *)(nextChunk + 0xc) =
               (*(uint *)(opChunk + 0xc) >> 0x1a & 7) << 0x1a | *(uint *)(nextChunk + 0xc) & 0xe3ffffff;
        }
        chunkHeader = *(uint *)(opChunk + 0xc);
        lastOp = FunctionTable__getLastOp(*(unsigned char **)(this + stageOffset + 0x38),fnIdx);
        if ((chunkHeader & 0x3ffff) == lastOp) {
          _PPStreamChunkListRemoveChunk
                    (*(undefined4 *)(*(int *)(this + stageOffset + 0x30) + 0x20),opChunk);
        }
      }
      break;
    }
  }
code_r0x97bb3790:
  fnIdxBase = fnIdx + -1;
  removedAny = true;
  FunctionTable__removeFunction(*(unsigned char **)(this + stageOffset + 0x38),fnIdx);
LAB_97bb37a8:
  fnIdx = fnIdxBase + 1;
  if ((*(int *)(this + stageOffset + 0x38) == 0) ||
     (*(int *)(*(int *)(this + stageOffset + 0x38) + 4) <= fnIdx)) goto code_r0x97bb37cc;
  goto code_r0x97bb3410;
code_r0x97bb37cc:
  if (!removedAny) goto LAB_97bb37d4;
  goto code_r0x97bb33e8;
LAB_97bb37d4:
  stage = stage + 1;
  if (1 < stage) {
    return;
  }
  goto code_r0x97bb33e4;
}

/* TGenericLinker__RenumberLabels @ 0x97bb37fc (40 bytes) */
int TGenericLinker__RenumberLabels(this, chunk, oldLabel, newLabel)
  unsigned char * this;
  unsigned char * chunk;
  uint oldLabel;
  uint newLabel;
{
  if (chunk != (unsigned char *)0x0) {
    do {
      if (oldLabel == *(uint *)(chunk + 0xc)) {
        *(uint *)(chunk + 0xc) = newLabel;
      }
      chunk = *(unsigned char **)(chunk + 8);
    } while (chunk != (unsigned char *)0x0);
    return;
  }
  return;
}

/* TGenericLinker__RemoveUnusedRegisters @ 0x97bb3824 (820 bytes) */
int TGenericLinker__RemoveUnusedRegisters(this)
  unsigned char * this;
{
  int removeCount;
  int operandIndex;
  int slotIndex;
  uint destWord;
  bool operandClassMatches;
  bool unreferenced;
  unsigned char * symbol;
  uint operandCount;
  uint classBits;
  unsigned char * nextSymbol;
  int vec4Count;
  undefined4 chunkList;
  int operandPtr;
  byte chunkKind;
  int stageByteOffset;
  int stage;
  unsigned char * stageSlot;
  byte *chunk;
  int elementIndex;
  int opChunk;
  byte *nextChunk;
  int referenced;
  
  stage = 0;
  stageByteOffset = 0;
  stageSlot = this;
  do {
    if (*(unsigned char **)(stageSlot + 0x28) != (unsigned char *)0x0) {
      nextSymbol = (unsigned char *)
               ParseSymbolTable__NextSymbol
                         (*(unsigned char **)(stageSlot + 0x28),(unsigned char *)0x0);
      while (symbol = nextSymbol, symbol != (unsigned char *)0x0) {
        referenced = *(int *)(symbol + 0x54);
        chunk = *(byte **)symbol;
        opChunk = **(int **)(*(int *)(stageSlot + 0x30) + 0x20);
        if (opChunk == 0) {
          unreferenced = referenced == 0;
LAB_97bb3a3c:
          if (!unreferenced) goto LAB_97bb3b10;
          nextSymbol = (unsigned char *)
                   ParseSymbolTable__NextSymbol(*(unsigned char **)(stageSlot + 0x28),symbol);
          ParseSymbolTable__RemoveSymbol(*(unsigned char **)(stageSlot + 0x28),symbol);
          for (slotIndex = 0; removeCount = ((int (*)())GetVec4sForType)((uint)*(ushort *)(symbol + 0x2c)),
              slotIndex < removeCount; slotIndex = slotIndex + 1) {
            chunkKind = *chunk;
            nextChunk = *(byte **)(chunk + 8);
            if (chunkKind == 2) {
              chunkList = *(undefined4 *)(*(int *)(this + stageByteOffset + 0x30) + 0x18);
LAB_97bb3ad8:
              _PPStreamChunkListRemoveChunk(chunkList,chunk);
            }
            else {
              if (2 < chunkKind) {
                if (chunkKind == 3) {
                  chunkList = *(undefined4 *)(*(int *)(this + stageByteOffset + 0x30) + 0x10);
                }
                else {
                  if (chunkKind != 4) goto LAB_97bb3adc;
                  chunkList = *(undefined4 *)(*(int *)(this + stageByteOffset + 0x30) + 0x1c);
                }
                goto LAB_97bb3ad8;
              }
              if (chunkKind == 0) {
                chunkList = *(undefined4 *)(*(int *)(this + stageByteOffset + 0x30) + 4);
                goto LAB_97bb3ad8;
              }
            }
LAB_97bb3adc:
            chunk = nextChunk;
          }
          if (symbol != (unsigned char *)0x0) {
            __ZN11ParseSymbolD1Ev(symbol);
            __ZdlPv(symbol);
          }
        }
        else {
          unreferenced = referenced == 0;
          if (unreferenced) {
            do {
              elementIndex = 0;
              while ((vec4Count = ((int (*)())GetVec4sForType)((uint)*(ushort *)(symbol + 0x2c)), elementIndex < vec4Count &&
                     (unreferenced))) {
                operandIndex = 0;
                operandCount = *(uint *)(opChunk + 0xc) >> 0x1d;
                if (referenced < (int)operandCount) {
                  chunkKind = *chunk;
                  operandPtr = opChunk + 0x10;
                  do {
                    if (chunkKind == 2) {
                      if (*(int *)(symbol + 0x34) != 0) {
                        if ((*(uint *)(operandPtr + 0xc) & 0x3800000) != 0) goto LAB_97bb3954;
LAB_97bb393c:
                        if ((uint)*(ushort *)(operandPtr + 0x12) !=
                            (uint)*(ushort *)(chunk + 0x12) + elementIndex) goto LAB_97bb3954;
                      }
LAB_97bb3950:
                      referenced = 1;
                    }
                    else if (chunkKind < 3) {
                      if (chunkKind == 0) {
                        operandClassMatches = (*(uint *)(operandPtr + 0xc) >> 0x17 & 7) == 1;
                        goto LAB_97bb3938;
                      }
                    }
                    else {
                      if (chunkKind == 3) {
                        if (*(int *)(symbol + 0x34) == 0) goto LAB_97bb3950;
                        operandClassMatches = (*(uint *)(operandPtr + 0xc) >> 0x17 & 7) == 2;
                      }
                      else {
                        if (chunkKind != 4) goto LAB_97bb3954;
                        operandClassMatches = (*(uint *)(operandPtr + 0xc) >> 0x17 & 7) == 3;
                      }
LAB_97bb3938:
                      if (operandClassMatches) goto LAB_97bb393c;
                    }
LAB_97bb3954:
                    operandIndex = operandIndex + 1;
                    operandPtr = operandPtr + 8;
                  } while ((operandIndex < (int)operandCount) && (referenced == 0));
                }
                else {
                  chunkKind = *chunk;
                }
                if (chunkKind == 2) {
                  if (*(int *)(symbol + 0x34) != 0) {
                    if ((*(uint *)(opChunk + 0x14) & 0xe0000) != 0) goto LAB_97bb3a08;
LAB_97bb39f0:
                    if ((uint)*(ushort *)(opChunk + 0x1a) !=
                        (uint)*(ushort *)(chunk + 0x12) + elementIndex) goto LAB_97bb3a08;
                  }
LAB_97bb3a04:
                  referenced = 1;
                }
                else if (chunkKind < 3) {
                  if (chunkKind == 0) {
                    destWord = *(uint *)(opChunk + 0x14);
                    classBits = 0x20000;
                    goto LAB_97bb39e4;
                  }
                }
                else {
                  if (chunkKind == 3) {
                    if (*(int *)(symbol + 0x34) == 0) goto LAB_97bb3a04;
                    destWord = *(uint *)(opChunk + 0x14);
                    classBits = 0x40000;
                  }
                  else {
                    if (chunkKind != 4) goto LAB_97bb3a08;
                    destWord = *(uint *)(opChunk + 0x14);
                    classBits = 0x60000;
                  }
LAB_97bb39e4:
                  if ((destWord & 0xe0000) == classBits) goto LAB_97bb39f0;
                }
LAB_97bb3a08:
                unreferenced = referenced == 0;
                elementIndex = elementIndex + 1;
              }
              opChunk = *(int *)(opChunk + 8);
              if (opChunk == 0) goto LAB_97bb3a3c;
            } while (unreferenced);
          }
LAB_97bb3b10:
          nextSymbol = (unsigned char *)
                   ParseSymbolTable__NextSymbol(*(unsigned char **)(stageSlot + 0x28),symbol);
        }
      }
    }
    stage = stage + 1;
    stageByteOffset = stageByteOffset + 4;
    stageSlot = stageSlot + 4;
    if (1 < stage) {
      return;
    }
  } while( true );
}

/* TGenericLinker__RemoveExtraVertexOutputs @ 0x97bb3b58 (280 bytes) */
int TGenericLinker__RemoveExtraVertexOutputs(this)
  unsigned char * this;
{
  int fragmentSymbol;
  bool emitWarning;
  unsigned char * parseSymbol;
  unsigned char * nextSymbol;
  int formatLength;
  int nameLength;
  char *message;
  char *formatString;
  char *symbolName;
  void *infoSink;
  
  if (*(unsigned char **)(this + 0x28) != (unsigned char *)0x0) {
    nextSymbol = (unsigned char *)
             ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
joined_r0x97bb3b94:
    parseSymbol = nextSymbol;
    if (parseSymbol != (unsigned char *)0x0) {
      nextSymbol = (unsigned char *)
               ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),parseSymbol);
      if ((**(char **)parseSymbol == '\0') && (*(int *)(parseSymbol + 0x5c) != 0)) {
        symbolName = *(char **)(parseSymbol + 0x14);
        if (*(unsigned char **)(this + 0x2c) == (unsigned char *)0x0) {
          formatLength = _strlen(DAT_a7b7bae0);
          nameLength = _strlen(symbolName);
          message = (char *)_malloc(formatLength + nameLength + 1);
          emitWarning = true;
          formatString = DAT_a7b7bae0;
        }
        else {
          fragmentSymbol = ParseSymbolTable__FindGlobalSymbolByName
                            (*(unsigned char **)(this + 0x2c),symbolName);
          emitWarning = fragmentSymbol == 0;
          if (!emitWarning) goto joined_r0x97bb3b94;
          formatLength = _strlen(DAT_a7b7bad8);
          nameLength = _strlen(symbolName);
          message = (char *)_malloc(formatLength + nameLength + 1);
          formatString = DAT_a7b7bad8;
        }
        _sprintf(message,formatString,symbolName);
        if (emitWarning) {
          infoSink = *(void **)(this + 0x84);
                    
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
          __ZN13TInfoSinkBase6appendEPKc(infoSink,message);
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
          _free(message);
        }
      }
      goto joined_r0x97bb3b94;
    }
  }
  return;
}

/* TGenericLinker__FixOutputReads @ 0x97bb3d14 (1160 bytes) */
int TGenericLinker__FixOutputReads(this)
  unsigned char * this;
{
  int insertedOp;
  uint componentCount;
  uint chunkHeader;
  uint fnIdx;
  uint mainLastOp;
  uint chunkHeaderWord;
  int opChunk;
  bool mainReached;
  undefined4 functionName;
  int compareResult;
  ushort outputReg;
  bool outputIsRead;
  int operandCursor;
  undefined4 maxIndex;
  uint operandCount;
  int operandCursor2;
  int stageOffset;
  int stage;
  unsigned char * stageEntry;
  int outputSymbol;
  uint operandIdx;
  uint tempUsageFlags;
  undefined4 opChunkOrTempIndex;
  int tempUsageWord2;
  int tempUsageWord3;
  undefined4 opHeader;
  uint opFlags;
  uint opDest0;
  uint opDest1;
  uint opSrc0A;
  uint opSrc0B;
  undefined4 opSrc1A;
  undefined4 opSrc1B;
  undefined4 opSrc2A;
  undefined4 opSrc2B;
  undefined4 opAuxA;
  undefined4 opAuxB;
  undefined4 opLine;
  undefined4 opWord13;
  
  stage = 0;
  stageOffset = 0;
  stageEntry = this;
  do {
    if (*(int *)(stageEntry + 0x30) != 0) {
      for (outputSymbol = **(int **)(*(int *)(stageEntry + 0x30) + 0x1c); outputSymbol != 0;
          outputSymbol = *(int *)(outputSymbol + 8)) {
        outputIsRead = false;
        outputReg = *(ushort *)(outputSymbol + 0x12);
        opChunkOrTempIndex = **(int **)(*(int *)(stageEntry + 0x30) + 0x20);
        if (opChunkOrTempIndex != 0) {
          do {
            operandIdx = 0;
            operandCount = *(uint *)(opChunkOrTempIndex + 0xc) >> 0x1d;
            if (operandCount != 0) {
              operandCursor = opChunkOrTempIndex + 0x10;
              do {
                if ((((*(uint *)(operandCursor + 0xc) >> 0x17 & 7) == 3) &&
                    (*(ushort *)(operandCursor + 0x12) == outputReg)) ||
                   (((*(uint *)(opChunkOrTempIndex + 0xc) & 0x3fc0000) == 0x1b40000 &&
                    (((*(uint *)(opChunkOrTempIndex + 0x14) & 0xe0000) == 0x60000 &&
                     (*(ushort *)(opChunkOrTempIndex + 0x1a) == outputReg)))))) {
                  outputIsRead = true;
                  break;
                }
                if (outputIsRead) break;
                operandIdx = operandIdx + 1;
                operandCursor = operandCursor + 8;
              } while (operandIdx < operandCount);
            }
            opChunkOrTempIndex = *(int *)(opChunkOrTempIndex + 8);
          } while (opChunkOrTempIndex != 0);
          if (outputIsRead) {
            tempUsageFlags = 0;
            tempUsageWord2 = opChunkOrTempIndex;
            tempUsageWord3 = opChunkOrTempIndex;
            maxIndex = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(*(int *)(stageEntry + 0x30) + 4));
            opChunkOrTempIndex = CONCAT22((*(unsigned short *)((unsigned char *)&(opChunkOrTempIndex) + 0)),(short)maxIndex + 1);
            tempUsageFlags = (*(uint *)(outputSymbol + 0xc) >> 0x18 & 3) << 0x18 |
                       (*(uint *)(outputSymbol + 0xc) >> 0x1a & 7) << 0x1a |
                       *(uint *)(outputSymbol + 0xc) & 0xe0000000 | tempUsageFlags & 0xffffff;
            _PPStreamAddTempUsage(*(undefined4 *)(stageEntry + 0x30),&tempUsageFlags);
            for (opChunk = **(int **)(*(int *)(stageEntry + 0x30) + 0x20); opChunk != 0;
                opChunk = *(int *)(opChunk + 8)) {
              if (((*(uint *)(opChunk + 0x14) & 0xe0000) == 0x60000) &&
                 (*(ushort *)(opChunk + 0x1a) == outputReg)) {
                *(uint *)(opChunk + 0x14) = *(uint *)(opChunk + 0x14) & 0xfff1ffff | 0x20000;
                *(undefined2 *)(opChunk + 0x1a) = (*(unsigned short *)((unsigned char *)&(opChunkOrTempIndex) + 2));
              }
              chunkHeaderWord = *(uint *)(opChunk + 0xc);
              operandIdx = 0;
              if (chunkHeaderWord >> 0x1d != 0) {
                operandCursor2 = opChunk + 0x10;
                do {
                  if (((*(uint *)(operandCursor2 + 0xc) >> 0x17 & 7) == 3) &&
                     (*(ushort *)(operandCursor2 + 0x12) == outputReg)) {
                    *(uint *)(operandCursor2 + 0xc) = *(uint *)(operandCursor2 + 0xc) & 0xfc7fffff | 0x800000;
                    *(undefined2 *)(operandCursor2 + 0x12) = (*(unsigned short *)((unsigned char *)&(opChunkOrTempIndex) + 2));
                    chunkHeaderWord = *(uint *)(opChunk + 0xc);
                  }
                  operandIdx = operandIdx + 1;
                  operandCursor2 = operandCursor2 + 8;
                } while (operandIdx < chunkHeaderWord >> 0x1d);
              }
            }
            mainReached = false;
            mainLastOp = 0;
            fnIdx = 0;
            if ((*(int *)(stageEntry + 0x38) != 0) && (*(int *)(*(int *)(stageEntry + 0x38) + 4) != 0)) {
              do {
                functionName = FunctionTable__getFunctionName(*(unsigned char **)(stageEntry + 0x38),fnIdx);
                compareResult = _memcmp(functionName,"main(",6);
                if (compareResult == 0) {
                  mainLastOp = FunctionTable__getLastOp(*(unsigned char **)(stageEntry + 0x38),fnIdx);
                }
                fnIdx = fnIdx + 1;
              } while ((*(int *)(stageEntry + 0x38) != 0) &&
                      (fnIdx < *(uint *)(*(int *)(stageEntry + 0x38) + 4)));
            }
            for (opChunk = **(int **)(*(int *)(stageEntry + 0x30) + 0x20); opChunk != 0;
                opChunk = *(int *)(opChunk + 8)) {
              chunkHeader = *(uint *)(opChunk + 0xc);
              if ((chunkHeader & 0x3ffff) == 0) {
                mainReached = true;
              }
              if ((mainReached) && ((chunkHeader & 0x3fc0000) == 0x1340000)) {
                componentCount = tempUsageFlags >> 0x18 & 3;
                opDest0 = componentCount << 10 | 0x6c;
                opSrc1A = 0;
                opSrc1B = 0;
                opSrc2A = 0;
                opSrc2B = 0;
                opAuxA = 0;
                opAuxB = 0;
                opLine = *(undefined4 *)(opChunk + 0x3c);
                opHeader = 0x20000000;
                opWord13 = 0;
                if (componentCount == 1) {
LAB_97bb40ac:
                  opDest0 = opDest0 | 0x4000;
LAB_97bb40b4:
                  opDest0 = opDest0 | 0x2000;
                }
                else {
                  if (componentCount == 0) goto LAB_97bb40b4;
                  if (componentCount == 2) {
LAB_97bb40a4:
                    opDest0 = opDest0 | 0x8000;
                    goto LAB_97bb40ac;
                  }
                  if (componentCount == 3) {
                    opDest0 = 0x10c6c;
                    goto LAB_97bb40a4;
                  }
                }
                componentCount = tempUsageFlags >> 0x18 & 3;
                opFlags = (tempUsageFlags >> 0x1d & 3) << 0x12 |
                           componentCount << 0x1a | (tempUsageFlags >> 0x1a & 7) << 0x17;
                opDest0 = opDest0 | 0x60000;
                opSrc0A = componentCount << 0xc | 0x8d8000;
                opSrc0B = opChunkOrTempIndex & 0xffff;
                opDest1 = (uint)outputReg;
                insertedOp = _PPStreamInsertOperationAfterChunk
                                  (*(undefined4 *)(this + stageOffset + 0x30),&opHeader,0,0,
                                   *(undefined4 *)(opChunk + 4));
                _PPStreamChangeBranchTargets
                          (*(undefined4 *)(this + stageOffset + 0x30),*(uint *)(opChunk + 0xc) & 0x3ffff,
                           *(uint *)(insertedOp + 0xc) & 0x3ffff);
                chunkHeader = *(uint *)(opChunk + 0xc);
              }
              if (mainLastOp == (chunkHeader & 0x3ffff)) break;
            }
          }
        }
      }
    }
    stage = stage + 1;
    stageOffset = stageOffset + 4;
    stageEntry = stageEntry + 4;
    if (1 < stage) {
      return;
    }
  } while( true );
}

/* TGenericLinker__OptimizeFunctionIO @ 0x97bb419c (696 bytes) */
int TGenericLinker__OptimizeFunctionIO(this)
  unsigned char * this;
{
  unsigned char *opChunk;
  unsigned char *nextOp;
  uint srcOperandWord;
  uint lastOpIndex;
  int formatLength;
  int nameCompare;
  int functionIsEmpty;
  int paramChunk;
  int nameLength;
  int numParams;
  bool scanEnded;
  int stageByteOffset;
  int functionName;
  int mainCompare;
  char *paramName;
  unsigned char * paramSymbol;
  uint vec4Count;
  int isEmptyFunction;
  uint firstOpIndex;
  undefined4 ppStream;
  int shaderNameLength;
  int functionNameLength;
  char *message;
  int stage;
  int paramIndex;
  uint elementIndex;
  uint opHeader;
  unsigned char *bodyNextOp;
  void *infoSink;
  unsigned char *bodyOp;
  int functionIndex;
  int outDestWord0;
  int outDestWord1;
  uint inSourceWord0;
  int inSourceWord1;
  
  stage = 0;
  do {
    stageByteOffset = stage * 4;
    functionIndex = 0;
    if ((*(int *)(this + stageByteOffset + 0x38) != 0) && (0 < *(int *)(*(int *)(this + stageByteOffset + 0x38) + 4))) {
      do {
        paramIndex = 0;
        functionName = FunctionTable__getFunctionName(*(unsigned char **)(this + stageByteOffset + 0x38),functionIndex);
        mainCompare = _memcmp(functionName,"main(",6);
        if (mainCompare != 0) {
          for (; numParams = FunctionTable__getNumParams
                                   (*(unsigned char **)(this + stageByteOffset + 0x38),functionIndex), paramIndex < numParams
              ; paramIndex = paramIndex + 1) {
            nameLength = _strlen(functionName);
            paramName = (char *)_malloc(nameLength + 9);
            _sprintf(paramName,"%s_%i",functionName,paramIndex);
            for (paramSymbol = (unsigned char *)
                          ParseSymbolTable__FindNextParamSymbolByName
                                    (*(unsigned char **)(this + stageByteOffset + 0x28),(unsigned char *)0x0,
                                     paramName); paramSymbol != (unsigned char *)0x0;
                paramSymbol = (unsigned char *)
                         ParseSymbolTable__FindNextParamSymbolByName
                                   (*(unsigned char **)(this + stageByteOffset + 0x28),paramSymbol,paramName)) {
              elementIndex = 0;
              vec4Count = ((int (*)())GetVec4sForType)((uint)*(ushort *)(paramSymbol + 0x2c));
              paramChunk = *(int *)paramSymbol;
              if (vec4Count != 0) {
                do {
                  inSourceWord0 = 0;
                  inSourceWord1 = 0;
                  outDestWord0 = 0;
                  outDestWord1 = 0;
                  bodyOp = (unsigned char *)**(int **)(*(int *)(this + stageByteOffset + 0x30) + 0x20);
                  isEmptyFunction = FunctionTable__getEmpty(*(unsigned char **)(this + stageByteOffset + 0x38),functionIndex);
                  if (isEmptyFunction == 0) {
                    for (; scanEnded = bodyOp == (unsigned char *)0x0, !scanEnded;
                        bodyOp = *(unsigned char **)(bodyOp + 8)) {
                      opHeader = *(uint *)(bodyOp + 0xc);
                      firstOpIndex = FunctionTable__getFirstOp
                                        (*(unsigned char **)(this + stageByteOffset + 0x38),functionIndex);
                      if ((opHeader & 0x3ffff) == firstOpIndex) goto LAB_97bb43a0;
                    }
                    formatLength = _strlen(DAT_a7b7baec);
                    shaderNameLength = _strlen((&_shaderString)[stage]);
                    functionNameLength = _strlen(functionName);
                    message = (char *)_malloc(formatLength + shaderNameLength + functionNameLength + 9);
                    firstOpIndex = FunctionTable__getFirstOp(*(unsigned char **)(this + stageByteOffset + 0x38),functionIndex);
                    _sprintf(message,DAT_a7b7baec,functionName,(&_shaderString)[stage],firstOpIndex);
                    infoSink = *(void **)(this + 0x84);
                    
                    __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
                    __ZN13TInfoSinkBase6appendEPKc(infoSink,message);
                    __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
                    _free(message);
                  }
LAB_97bb44d0:
                  nextOp = (unsigned char *)
                            **(undefined4 **)(*(int *)(this + stageByteOffset + 0x30) + 0x20);
joined_r0x97bb44e4:
                  while (opChunk = nextOp, opChunk != (unsigned char *)0x0) {
                    nextOp = *(unsigned char **)(opChunk + 8);
                    if ((*(uint *)(opChunk + 0xc) & 0x3fc0000) != 0) goto code_r0x97bb456c;
                    if (((*(uint *)(opChunk + 0x1c) & 0x3800000) == 0x800000) &&
                       ((uint)*(ushort *)(opChunk + 0x22) == *(ushort *)(paramChunk + 0x12) + elementIndex))
                    goto code_r0x97bb4598;
                    if (((*(uint *)(opChunk + 0x14) & 0xe0000) == 0x20000) &&
                       ((uint)*(ushort *)(opChunk + 0x1a) == *(ushort *)(paramChunk + 0x12) + elementIndex)) {
                      if (outDestWord0 == 0 && outDestWord1 == 0) goto code_r0x97bb45b4;
                      *(int *)(opChunk + 0x18) = outDestWord1;
                      *(int *)(opChunk + 0x14) = outDestWord0;
                    }
                  }
                  elementIndex = elementIndex + 1;
                } while (elementIndex < vec4Count);
              }
            }
            _free(paramName);
          }
          nextOp = (unsigned char *)**(undefined4 **)(*(int *)(this + stageByteOffset + 0x30) + 0x20);
          while (opChunk = nextOp, opChunk != (unsigned char *)0x0) {
            nextOp = *(unsigned char **)(opChunk + 8);
            functionIsEmpty = FunctionTable__getEmpty(*(unsigned char **)(this + stageByteOffset + 0x38),functionIndex);
            if ((((functionIsEmpty != 0) && ((*(uint *)(opChunk + 0xc) & 0x3fc0000) == 0x1300000)) &&
                (*(int *)(opChunk + 0x40) != 0)) && (nameCompare = _strcmp(opChunk + 0x44,functionName), nameCompare == 0)
               ) {
              FunctionTable__updateForRemovingChunk
                        (*(unsigned char **)(this + stageByteOffset + 0x38),opChunk);
              _PPStreamRemoveOperation(*(undefined4 *)(this + stageByteOffset + 0x30),opChunk);
            }
          }
        }
        functionIndex = functionIndex + 1;
      } while ((*(int *)(this + stageByteOffset + 0x38) != 0) &&
              (functionIndex < *(int *)(*(int *)(this + stageByteOffset + 0x38) + 4)));
    }
    stage = stage + 1;
    if (1 < stage) {
      return;
    }
  } while( true );
LAB_97bb43a0:
  if (((scanEnded) ||
      (opHeader = *(uint *)(bodyOp + 0xc),
      lastOpIndex = FunctionTable__getLastOp(*(unsigned char **)(this + stageByteOffset + 0x38),functionIndex),
      lastOpIndex < (opHeader & 0x3ffff))) || ((*(uint *)(bodyOp + 0xc) & 0x3ffff) == 0))
  goto LAB_97bb44d0;
  bodyNextOp = *(unsigned char **)(bodyOp + 8);
  if ((*(uint *)(bodyOp + 0xc) & 0x3fc0000) == 0) {
    srcOperandWord = *(uint *)(bodyOp + 0x1c);
    if (((srcOperandWord & 0x3800000) == 0x800000) &&
       ((uint)*(ushort *)(bodyOp + 0x22) == *(ushort *)(paramChunk + 0x12) + elementIndex)) {
      outDestWord1 = *(int *)(bodyOp + 0x18);
      outDestWord0 = *(int *)(bodyOp + 0x14);
      FunctionTable__updateForRemovingChunk(*(unsigned char **)(this + stageByteOffset + 0x38),bodyOp);
      ppStream = *(undefined4 *)(this + stageByteOffset + 0x30);
    }
    else {
      if (((*(uint *)(bodyOp + 0x14) & 0xe0000) != 0x20000) ||
         ((uint)*(ushort *)(bodyOp + 0x1a) != *(ushort *)(paramChunk + 0x12) + elementIndex))
      goto LAB_97bb4398;
      inSourceWord1 = *(int *)(bodyOp + 0x20);
      FunctionTable__updateForRemovingChunk(*(unsigned char **)(this + stageByteOffset + 0x38),bodyOp);
      ppStream = *(undefined4 *)(this + stageByteOffset + 0x30);
      inSourceWord0 = srcOperandWord;
    }
    _PPStreamRemoveOperation(ppStream,bodyOp);
  }
LAB_97bb4398:
  scanEnded = bodyNextOp == (unsigned char *)0x0;
  bodyOp = bodyNextOp;
  goto LAB_97bb43a0;
code_r0x97bb456c:
  if ((((*(uint *)(opChunk + 0xc) & 0x3fc0000) == 0x1b40000) &&
      ((*(uint *)(opChunk + 0x1c) & 0x3800000) == 0x800000)) &&
     ((uint)*(ushort *)(opChunk + 0x22) == *(ushort *)(paramChunk + 0x12) + elementIndex)) {
code_r0x97bb4598:
    if (inSourceWord0 == 0 && inSourceWord1 == 0) {
code_r0x97bb45b4:
      FunctionTable__updateForRemovingChunk(*(unsigned char **)(this + stageByteOffset + 0x38),opChunk);
      _PPStreamRemoveOperation(*(undefined4 *)(this + stageByteOffset + 0x30),opChunk);
    }
    else {
      *(int *)(opChunk + 0x20) = inSourceWord1;
      *(uint *)(opChunk + 0x1c) = inSourceWord0;
    }
  }
  goto joined_r0x97bb44e4;
}

/* TGenericLinker__GetRemapTableString @ 0x97bb46f8 (412 bytes) */
int TGenericLinker__GetRemapTableString(this)
  unsigned char * this;
{
  int entryIndexPass2;
  int uniformCountPass2;
  int remapTablePass2;
  int stagesLeft;
  int tableByteOffset;
  int entryLength;
  int entryIndex;
  int lineLength;
  int uniformCount;
  int length;
  char *format;
  int remapTable;
  int totalLength;
  int uniformBound;
  char *text;
  int uniformBoundPass2;
  undefined4 *headerStrings;
  unsigned char * tableSlot;
  
  tableSlot = this + 0x40;
  length = _strlen(_linkUtilString);
  headerStrings = &DAT_a7b7bb38;
  totalLength = length + 2;
  do {
    remapTable = *(int *)tableSlot;
    tableSlot = tableSlot + 4;
    if ((remapTable == 0) ||
       (uniformCount = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4)), uniformCount == 0))
    {
      lineLength = _strlen(*headerStrings);
      totalLength = totalLength + lineLength;
    }
    else {
      lineLength = _strlen(headerStrings[-3]);
      totalLength = totalLength + lineLength;
      for (entryIndex = 0; uniformBound = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4)),
          entryIndex < uniformBound; entryIndex = entryIndex + 1) {
        entryLength = _strlen(DAT_a7b7bb34);
        totalLength = totalLength + entryLength + 0x10;
      }
    }
    headerStrings = headerStrings + 1;
  } while ((int)headerStrings < -0x584844c3);
  text = (char *)_malloc(totalLength);
  format = _linkUtilString;
  *text = '\0';
  _sprintf(text,format);
  headerStrings = &DAT_a7b7bb38;
  tableSlot = this + 0x40;
  tableByteOffset = 0;
  stagesLeft = 1;
  do {
    remapTablePass2 = *(int *)tableSlot;
    tableSlot = tableSlot + 4;
    if ((remapTablePass2 == 0) ||
       (uniformCountPass2 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4)), uniformCountPass2 == 0))
    {
      _sprintf(text,(char *)*headerStrings,text);
    }
    else {
      _sprintf(text,(char *)headerStrings[-3],text);
      for (entryIndexPass2 = 0; uniformBoundPass2 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4)),
          entryIndexPass2 < uniformBoundPass2; entryIndexPass2 = entryIndexPass2 + 1) {
        _sprintf(text,DAT_a7b7bb34,text,entryIndexPass2,
                 *(undefined4 *)(entryIndexPass2 * 4 + *(int *)(this + tableByteOffset + 0x40)));
      }
    }
    stagesLeft = stagesLeft + -1;
    tableByteOffset = tableByteOffset + 4;
    headerStrings = headerStrings + 1;
  } while (-1 < stagesLeft);
  return text;
}

/* TGenericLinker__GetBindingTableString @ 0x97bb4894 (384 bytes) */
int TGenericLinker__GetBindingTableString(this)
  unsigned char * this;
{
  int sizeActiveAttributes;
  int numActiveAttributeBindings;
  undefined4 string;
  int length;
  int length2;
  char *p0;
  int r6In0;
  int r7In0;
  int r8In0;
  undefined4 numActiveAttributeBindings2;
  undefined4 sizeActiveAttributes2;
  undefined4 sizeActiveUserAttributes;
  undefined4 numActiveUniformBindings;
  undefined4 sizeActiveUserUniforms;
  int in_stack_ffffff88;
  
  string = BindingTable__GetString(*(unsigned char **)(this + 4),3);
  if (*(int *)(this + 0x74) < 0) {
    length = _strlen(DAT_a7b7bb44);
    length2 = _strlen(string);
    p0 = (char *)_malloc(length + length2 + 0x29);
    *p0 = '\0';
    numActiveAttributeBindings2 = BindingTable__GetNumActiveAttributeBindings(*(unsigned char **)(this + 4));
    sizeActiveAttributes2 = BindingTable__GetSizeActiveAttributes(*(unsigned char **)(this + 4));
    sizeActiveUserAttributes = BindingTable__GetSizeActiveUserAttributes(*(unsigned char **)(this + 4));
    numActiveUniformBindings = BindingTable__GetNumActiveUniformBindings(*(unsigned char **)(this + 4));
    sizeActiveUserUniforms = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4));
    _sprintf(p0,DAT_a7b7bb44,numActiveAttributeBindings2,sizeActiveAttributes2,sizeActiveUserAttributes,numActiveUniformBindings,sizeActiveUserUniforms,string);
  }
  else {
    length = _strlen(DAT_a7b7bb40);
    length2 = _strlen(string);
    p0 = (char *)_malloc(length + length2 + 0x29);
    *p0 = '\0';
    numActiveAttributeBindings = BindingTable__GetNumActiveAttributeBindings(*(unsigned char **)(this + 4));
    sizeActiveAttributes = BindingTable__GetSizeActiveAttributes(*(unsigned char **)(this + 4));
    r6In0 = BindingTable__GetSizeActiveUserAttributes(*(unsigned char **)(this + 4));
    r7In0 = BindingTable__GetNumActiveUniformBindings(*(unsigned char **)(this + 4));
    r8In0 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4));
    _sprintf(p0,DAT_a7b7bb40,*(int *)(this + 0x74),numActiveAttributeBindings,sizeActiveAttributes,r6In0,r7In0,r8In0,string);
  }
  _free(string);
  return p0;
}

/* TGenericLinker__GetFullTableString @ 0x97bb4a14 (152 bytes) */
int TGenericLinker__GetFullTableString(this)
  unsigned char * this;
{
  undefined4 remapTableString;
  undefined4 bindingTableString;
  int length;
  int length2;
  char *allocation;
  
  remapTableString = ((int (*)())TGenericLinker__GetRemapTableString)(this);
  bindingTableString = ((int (*)())TGenericLinker__GetBindingTableString)(this);
  length = _strlen(remapTableString);
  length2 = _strlen(bindingTableString);
  allocation = (char *)_malloc(length + length2 + 1);
  *allocation = '\0';
  _sprintf(allocation,"%s%s",bindingTableString,remapTableString);
  _free(bindingTableString);
  _free(remapTableString);
  return allocation;
}

/* TGenericLinker__ReportStats @ 0x97bb4aac (4 bytes) */
int TGenericLinker__ReportStats()
{
  return;
}

/* TGenericLinker__InsertClientAttribBinding @ 0x97bb4ab0 (92 bytes) */
int TGenericLinker__InsertClientAttribBinding(this, binding)
  unsigned char * this;
  unsigned char * binding;
{
  int findAttribBindingResult;
  undefined4 insertClientAttribBindingResult;
  
  findAttribBindingResult = BindingTable__FindAttribBinding(*(unsigned char **)(this + 4),binding);
  if (findAttribBindingResult == 0) {
    insertClientAttribBindingResult = BindingTable__InsertClientAttribBinding(*(unsigned char **)(this + 4),binding);
    return insertClientAttribBindingResult;
  }
  return 0;
}

/* TGenericLinker__AddAttribBinding @ 0x97bb4b0c (276 bytes) */
int TGenericLinker__AddAttribBinding(linker, attribName, glType, isBuiltIn)
  char *linker;
  char *attribName;
  undefined4 glType;
  undefined4 isBuiltIn;
{
  char *message;
  int formatLength;
  int insertResult;
  unsigned char * binding;
  int existingBinding;
  undefined4 locationZeroName;
  int nameLength;
  char *errorText;
  void *infoSink;
  
  binding = operator_new(0x38);
  __ZN7BindingC1Ev(binding);
  errorText = DAT_a7b7bb84;
  if (binding == (unsigned char *)0x0) {
    infoSink = *(void **)(linker + 0x84);
                    
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(infoSink,errorText);
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
  }
  else {
    Binding__SetName(binding,attribName);
    existingBinding = BindingTable__FindAttribBinding(*(unsigned char **)(linker + 4),binding);
    if (existingBinding == 0) {
      Binding__SetClientRequest(binding,0);
      Binding__SetOpenGLType(binding,(*(unsigned short *)((unsigned char *)&(glType) + 2)));
      Binding__SetDecSize(binding,1);
      Binding__SetActualSize(binding,1);
      Binding__SetBuiltIn(binding,isBuiltIn);
      insertResult = BindingTable__InsertAttribBinding(*(unsigned char **)(linker + 4),binding);
      if (insertResult != 0) {
        return insertResult;
      }
      locationZeroName = BindingTable__GetAttribBindingNameByLocation(*(unsigned char **)(linker + 4),0);
      formatLength = _strlen(_linkErrorString);
      nameLength = _strlen(locationZeroName);
      message = (char *)_malloc(formatLength + nameLength + 1);
      _sprintf(message,_linkErrorString,locationZeroName);
      infoSink = *(void **)(linker + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(infoSink,message);
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
      _free(message);
      return 0;
    }
    __ZN7BindingD1Ev(binding);
    __ZdlPv(binding);
  }
  return 0;
}

/* TGenericLinker__CollectClientAttributeBindings @ 0x97bb4d6c (216 bytes) */
int TGenericLinker__CollectClientAttributeBindings(this)
  unsigned char * this;
{
  int errorFormatLength;
  int builtInFlag;
  int symbol;
  unsigned char * binding;
  int formatLength;
  int errorNameLength;
  char *message;
  int nameLength;
  undefined4 bindingName;
  void *infoSink;
  
  if (*(int *)(this + 0x28) == 0) {
    for (binding = (unsigned char *)
                  BindingTable__NextAttribRequestBinding
                            (*(unsigned char **)(this + 4),(unsigned char *)0x0); binding != (unsigned char *)0x0;
        binding = (unsigned char *)
                 BindingTable__NextAttribRequestBinding(*(unsigned char **)(this + 4),binding)) {
      bindingName = *(undefined4 *)(binding + 8);
      formatLength = _strlen(UNK_a7b7bac8);
      nameLength = _strlen(bindingName);
      message = (char *)_malloc(formatLength + nameLength + 1);
      _sprintf(message,UNK_a7b7bac8,bindingName);
      infoSink = *(void **)(this + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
      __ZN13TInfoSinkBase6appendEPKc(infoSink,message);
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
      _free(message);
    }
  }
  else {
    for (binding = (unsigned char *)
                  BindingTable__NextAttribRequestBinding
                            (*(unsigned char **)(this + 4),(unsigned char *)0x0); binding != (unsigned char *)0x0;
        binding = (unsigned char *)
                 BindingTable__NextAttribRequestBinding(*(unsigned char **)(this + 4),binding)) {
      symbol = ParseSymbolTable__FindGlobalSymbolByName
                        (*(unsigned char **)(this + 0x28),*(char **)(binding + 8));
      if (symbol == 0) {
        bindingName = *(undefined4 *)(binding + 8);
        formatLength = _strlen(UNK_a7b7bac4);
        nameLength = _strlen(bindingName);
        message = (char *)_malloc(formatLength + nameLength + 1);
        _sprintf(message,UNK_a7b7bac4,bindingName);
        infoSink = *(void **)(this + 0x84);
                    
        __ZN13TInfoSinkBase6appendEPKc(infoSink,"WARNING: ");
        __ZN13TInfoSinkBase6appendEPKc(infoSink,message);
        __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
        _free(message);
      }
      else {
        Binding__SetOpenGLType(binding,*(ushort *)(symbol + 0x2c));
        Binding__SetActualSize(binding,1);
        Binding__SetDecSize(binding,1);
        builtInFlag = *(int *)(symbol + 0x34);
        if (builtInFlag == 1) {
          bindingName = *(undefined4 *)(binding + 8);
          errorFormatLength = _strlen(DAT_a7b7bb68);
          errorNameLength = _strlen(bindingName);
          message = (char *)_malloc(errorFormatLength + errorNameLength + 1);
          _sprintf(message,DAT_a7b7bb68,bindingName);
          infoSink = *(void **)(this + 0x84);
                    
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
          __ZN13TInfoSinkBase6appendEPKc(infoSink,message);
          __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
          _free(message);
          builtInFlag = *(int *)(symbol + 0x34);
        }
        Binding__SetBuiltIn(binding,builtInFlag);
        InsertClientAttribBinding((unsigned char *)this,binding);
      }
    }
  }
  return 1;
}

/* TGenericLinker__CollectAttributeBindings @ 0x97bb50dc (996 bytes) */
int TGenericLinker__CollectAttributeBindings(this)
  unsigned char * this;
{
  unsigned char * parseSymbol;
  uint glType;
  
  if (*(unsigned char **)(this + 0x28) != (unsigned char *)0x0) {
    for (parseSymbol = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        parseSymbol != (unsigned char *)0x0;
        parseSymbol = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),parseSymbol)) {
      if (((**(char **)parseSymbol == '\x02') && (*(short *)(parseSymbol + 0x2c) == -0x74a4)) &&
         (*(int *)(parseSymbol + 0x34) == 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,*(undefined4 *)(parseSymbol + 0x14),0x8b5c,0);
      }
    }
    for (parseSymbol = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        parseSymbol != (unsigned char *)0x0;
        parseSymbol = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),parseSymbol)) {
      if (((**(char **)parseSymbol == '\x02') && (*(short *)(parseSymbol + 0x2c) == -0x74a5)) &&
         (*(int *)(parseSymbol + 0x34) == 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,*(undefined4 *)(parseSymbol + 0x14),0x8b5b,0);
      }
    }
    for (parseSymbol = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        parseSymbol != (unsigned char *)0x0;
        parseSymbol = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),parseSymbol)) {
      if (((**(char **)parseSymbol == '\x02') && (*(short *)(parseSymbol + 0x2c) == -0x74a6)) &&
         (*(int *)(parseSymbol + 0x34) == 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,*(undefined4 *)(parseSymbol + 0x14),0x8b5a,0);
      }
    }
    for (parseSymbol = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        parseSymbol != (unsigned char *)0x0;
        parseSymbol = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),parseSymbol)) {
      if ((((**(char **)parseSymbol == '\x02') &&
           (glType = (uint)*(ushort *)(parseSymbol + 0x2c), glType != 0x8b5c)) && (glType != 0x8b5b)) &&
         ((glType != 0x8b5a && (*(int *)(parseSymbol + 0x34) == 0)))) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,*(undefined4 *)(parseSymbol + 0x14),glType,0);
      }
    }
    for (parseSymbol = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        parseSymbol != (unsigned char *)0x0;
        parseSymbol = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),parseSymbol)) {
      if (((**(char **)parseSymbol == '\x02') && (*(short *)(parseSymbol + 0x2c) == -0x74a4)) &&
         (*(int *)(parseSymbol + 0x34) != 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,*(undefined4 *)(parseSymbol + 0x14),0x8b5c,1);
      }
    }
    for (parseSymbol = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        parseSymbol != (unsigned char *)0x0;
        parseSymbol = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),parseSymbol)) {
      if (((**(char **)parseSymbol == '\x02') && (*(short *)(parseSymbol + 0x2c) == -0x74a5)) &&
         (*(int *)(parseSymbol + 0x34) != 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,*(undefined4 *)(parseSymbol + 0x14),0x8b5b,1);
      }
    }
    for (parseSymbol = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        parseSymbol != (unsigned char *)0x0;
        parseSymbol = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),parseSymbol)) {
      if (((**(char **)parseSymbol == '\x02') && (*(short *)(parseSymbol + 0x2c) == -0x74a6)) &&
         (*(int *)(parseSymbol + 0x34) != 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,*(undefined4 *)(parseSymbol + 0x14),0x8b5a,1);
      }
    }
    for (parseSymbol = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        parseSymbol != (unsigned char *)0x0;
        parseSymbol = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),parseSymbol)) {
      if (((**(char **)parseSymbol == '\x02') &&
          (glType = (uint)*(ushort *)(parseSymbol + 0x2c), glType != 0x8b5c)) &&
         ((glType != 0x8b5b && ((glType != 0x8b5a && (*(int *)(parseSymbol + 0x34) != 0)))))) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,*(undefined4 *)(parseSymbol + 0x14),glType,1);
      }
    }
  }
  return 1;
}

/* TGenericLinker__RemapVertexAttributes @ 0x97bb54c0 (200 bytes) */
int TGenericLinker__RemapVertexAttributes(this)
  unsigned char * this;
{
  undefined4 symbolName;
  char *message;
  uint registerValue;
  int attribLocation;
  int chunk;
  int formatLength;
  short inputIndex;
  unsigned char * binding;
  int isBuiltIn;
  undefined4 *symbol;
  int nameLength;
  undefined4 glType;
  uint vec4Count;
  char *symbolChunk;
  undefined4 status;
  uint elementIndex;
  void *infoSink;
  
  status = 1;
  binding = (unsigned char *)BindingTable__NextAttribBinding(*(unsigned char **)(this + 4),(unsigned char *)0x0);
joined_r0x97bb54f0:
  if (binding == (unsigned char *)0x0) {
    return status;
  }
  isBuiltIn = Binding__IsBuiltIn(binding);
  if (((isBuiltIn == 0) && (*(unsigned char **)(this + 0x28) != (unsigned char *)0x0)) &&
     (symbol = (undefined4 *)
               ParseSymbolTable__FindGlobalSymbolByName
                         (*(unsigned char **)(this + 0x28),*(char **)(binding + 8)),
     symbol != (undefined4 *)0x0)) {
    symbolChunk = (char *)*symbol;
    if (*symbolChunk != '\x02') {
      symbolName = symbol[5];
      formatLength = _strlen(DAT_a7b7bb6c);
      nameLength = _strlen(symbolName);
      message = (char *)_malloc(formatLength + nameLength + 1);
      _sprintf(message,DAT_a7b7bb6c,symbolName);
      infoSink = *(void **)(this + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(infoSink,message);
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
      _free(message);
      status = 0;
      symbolChunk = (char *)*symbol;
    }
    if ((*symbolChunk == '\x02') && ((*(uint *)(symbolChunk + 0xc) & 0xf0000) == 0x90000)) {
      inputIndex = *(short *)(symbolChunk + 0x12);
      attribLocation = Binding__GetLocation(binding);
      for (chunk = **(int **)(*(int *)(this + 0x30) + 0x18); chunk != 0; chunk = *(int *)(chunk + 8)
          ) {
        elementIndex = 0;
        if (*(short *)(chunk + 0x12) == inputIndex) goto code_r0x97bb567c;
      }
    }
  }
  goto LAB_97bb56a8;
code_r0x97bb567c:
  while( true ) {
    glType = Binding__GetOpenGLType(binding);
    vec4Count = ((int (*)())GetVec4sForType)(glType);
    if ((vec4Count <= elementIndex) || (chunk == 0)) break;
    registerValue = attribLocation + elementIndex;
    elementIndex = elementIndex + 1;
    *(uint *)(chunk + 0xc) = registerValue & 0x1f | *(uint *)(chunk + 0xc) & 0xffffffe0;
    chunk = *(int *)(chunk + 8);
  }
LAB_97bb56a8:
  binding = (unsigned char *)BindingTable__NextAttribBinding(*(unsigned char **)(this + 4),binding);
  goto joined_r0x97bb54f0;
}

/* TGenericLinker__AllocateTextureUnitsForVaryings @ 0x97bb56d4 (468 bytes) */
int TGenericLinker__AllocateTextureUnitsForVaryings(this)
  unsigned char * this;
{
  int ppStreamManager;
  uint loopIndex;
  uint firstOp;
  bool slotsFree;
  uint uVar2;
  uint uVar3;
  unsigned char * this_00;
  int iVar4;
  uint *slotPlanCursor;
  uint uVar6;
  unsigned char * parseSymbol;
  char *messageText;
  uint uVar9;
  int *vertexSymbol;
  unsigned char * functionTable;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  undefined4 uVar15;
  char *messagePrefix;
  uint uVar17;
  uint bindingIndexOrComponentCount;
  int iVar19;
  int *slotMapCursor;
  uint uVar21;
  undefined4 success;
  ushort bindingChunkIndex;
  int slotIndexOrTemp;
  int allocationIdOrCounter;
  undefined4 uVar26;
  int usedSetCountOrSlotMap;
  void *infoSink;
  uint uVar29;
  uint slotPlan [14];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  uint outputBindingWord;
  undefined4 outputBindingChunkIndex;
  uint local_70;
  undefined4 local_6c;
  uint vec4Index;
  int insideMain;
  uint *local_58;
  
  *(undefined4 *)(this + 0x74) = 0xffffffff;
  *(undefined4 *)(this + 0x78) = 0;
  success = 1;
  usedSetCountOrSlotMap = 0;
  allocationIdOrCounter = 0;
  slotIndexOrTemp = 0;
  if (*(unsigned char **)(this + 0x28) != (unsigned char *)0x0) {
    for (parseSymbol = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        parseSymbol != (unsigned char *)0x0;
        parseSymbol = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),parseSymbol)) {
      if ((**(char **)parseSymbol == '\x04') &&
         (bindingIndexOrComponentCount = *(uint *)(*(char **)parseSymbol + 0xc), (bindingIndexOrComponentCount & 0xf0000) == 0x60000)) {
        bindingIndexOrComponentCount = bindingIndexOrComponentCount & 0x1f;
        *(uint *)(this + 0x78) = *(uint *)(this + 0x78) | 1 << bindingIndexOrComponentCount;
        if (*(int *)(this + 0x74) < (int)bindingIndexOrComponentCount) {
          *(uint *)(this + 0x74) = bindingIndexOrComponentCount;
        }
        usedSetCountOrSlotMap = usedSetCountOrSlotMap + 1;
      }
    }
  }
  this_00 = *(unsigned char **)(this + 0x2c);
  if (this_00 != (unsigned char *)0x0) {
    allocationIdOrCounter = *(int *)(this_00 + 0x1c);
    slotIndexOrTemp = *(int *)(this_00 + 0x20);
    for (parseSymbol = (unsigned char *)ParseSymbolTable__NextSymbol(this_00,(unsigned char *)0x0);
        parseSymbol != (unsigned char *)0x0;
        parseSymbol = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x2c),parseSymbol)) {
      if ((**(char **)parseSymbol == '\x02') &&
         (bindingIndexOrComponentCount = *(uint *)(*(char **)parseSymbol + 0xc), (bindingIndexOrComponentCount & 0xf0000) == 0x70000)) {
        bindingIndexOrComponentCount = bindingIndexOrComponentCount & 0x1f;
        if (*(int *)(this + 0x74) < (int)bindingIndexOrComponentCount) {
          *(uint *)(this + 0x74) = bindingIndexOrComponentCount;
        }
        if ((*(uint *)(this + 0x78) & 1 << bindingIndexOrComponentCount) == 0) {
          usedSetCountOrSlotMap = usedSetCountOrSlotMap + 1;
        }
        *(uint *)(this + 0x78) = *(uint *)(this + 0x78) | 1 << bindingIndexOrComponentCount;
      }
    }
  }
  if (allocationIdOrCounter != 0) {
    if ((*(int *)(this + 0x28) == 0) || (*(int *)(this + 0x2c) == 0)) {
      if (*(unsigned char **)(this + 0x2c) != (unsigned char *)0x0) {
        for (parseSymbol = (unsigned char *)
                      ParseSymbolTable__NextSymbol
                                (*(unsigned char **)(this + 0x2c),(unsigned char *)0x0);
            parseSymbol != (unsigned char *)0x0;
            parseSymbol = (unsigned char *)
                     ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),parseSymbol)) {
          if ((**(char **)parseSymbol == '\0') && (*(int *)(parseSymbol + 0x60) != 0)) {
            success = *(undefined4 *)(parseSymbol + 0x14);
            usedSetCountOrSlotMap = _strlen(UNK_a7b7badc);
            slotIndexOrTemp = _strlen(success);
            messageText = (char *)_malloc(usedSetCountOrSlotMap + slotIndexOrTemp + 1);
            _sprintf(messageText,UNK_a7b7badc,success);
            infoSink = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(infoSink,messageText);
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
            success = 0;
            _free(messageText);
          }
        }
      }
    }
    else {
      allocationIdOrCounter = 1;
      slotIndexOrTemp = usedSetCountOrSlotMap * 4 + slotIndexOrTemp;
      if (slotIndexOrTemp < 0x21) {
        usedSetCountOrSlotMap = _malloc(0x80);
        _memset(usedSetCountOrSlotMap,0,0x80);
        for (parseSymbol = (unsigned char *)
                      ParseSymbolTable__NextSymbol
                                (*(unsigned char **)(this + 0x2c),(unsigned char *)0x0);
            parseSymbol != (unsigned char *)0x0;
            parseSymbol = (unsigned char *)
                     ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x2c),parseSymbol)) {
          if ((**(char **)parseSymbol == '\x02') &&
             (bindingIndexOrComponentCount = *(uint *)(*(char **)parseSymbol + 0xc), (bindingIndexOrComponentCount & 0xf0000) == 0x70000)) {
            slotIndexOrTemp = (bindingIndexOrComponentCount & 0x1f) * 0x10;
            iVar4 = -allocationIdOrCounter;
            iVar19 = slotIndexOrTemp + usedSetCountOrSlotMap;
            *(int *)(usedSetCountOrSlotMap + slotIndexOrTemp) = iVar4;
            allocationIdOrCounter = allocationIdOrCounter + 1;
            *(int *)(iVar19 + 0xc) = iVar4;
            *(int *)(iVar19 + 4) = iVar4;
            *(int *)(iVar19 + 8) = iVar4;
          }
        }
        for (parseSymbol = (unsigned char *)
                      ParseSymbolTable__NextSymbol
                                (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
            parseSymbol != (unsigned char *)0x0;
            parseSymbol = (unsigned char *)
                     ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),parseSymbol)) {
          if ((**(char **)parseSymbol == '\x04') &&
             (bindingIndexOrComponentCount = *(uint *)(*(char **)parseSymbol + 0xc), (bindingIndexOrComponentCount & 0xf0000) == 0x60000)) {
            slotIndexOrTemp = (bindingIndexOrComponentCount & 0x1f) * 0x10;
            iVar4 = -allocationIdOrCounter;
            iVar19 = slotIndexOrTemp + usedSetCountOrSlotMap;
            *(int *)(usedSetCountOrSlotMap + slotIndexOrTemp) = iVar4;
            allocationIdOrCounter = allocationIdOrCounter + 1;
            *(int *)(iVar19 + 0xc) = iVar4;
            *(int *)(iVar19 + 4) = iVar4;
            *(int *)(iVar19 + 8) = iVar4;
          }
        }
        bindingIndexOrComponentCount = 4;
        do {
          for (parseSymbol = (unsigned char *)
                        ParseSymbolTable__NextSymbol
                                  (*(unsigned char **)(this + 0x2c),(unsigned char *)0x0);
              parseSymbol != (unsigned char *)0x0;
              parseSymbol = (unsigned char *)
                       ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x2c),parseSymbol)) {
            if (((**(char **)parseSymbol == '\0') && (*(int *)(parseSymbol + 0x60) != 0)) &&
               (uVar9 = ((int (*)())GetScalerWidthForType)((uint)*(ushort *)(parseSymbol + 0x2c)), bindingIndexOrComponentCount == uVar9)) {
              vertexSymbol = (int *)ParseSymbolTable__FindGlobalSymbolByName
                                         (*(unsigned char **)(this + 0x28),
                                          *(char **)(parseSymbol + 0x14));
              if (((vertexSymbol == (int *)0x0) ||
                  (uVar9 = (uint)*(ushort *)(parseSymbol + 0x2c), uVar9 != *(ushort *)(vertexSymbol + 0xb)))
                 || ((*(char *)*vertexSymbol != '\0' || (vec4Index = 0, vertexSymbol[0x17] == 0)))) {
                success = 0;
                if (vertexSymbol == (int *)0x0) {
code_r0x97bb689c:
                  uVar13 = *(undefined4 *)(parseSymbol + 0x14);
                  slotIndexOrTemp = _strlen(UNK_a7b7bad4);
                  iVar4 = _strlen(uVar13);
                  messageText = (char *)_malloc(slotIndexOrTemp + iVar4 + 1);
                  _sprintf(messageText,UNK_a7b7bad4,uVar13);
                  infoSink = *(void **)(this + 0x84);
                    
override_jmp_97bb67f0_case_0:
                  messagePrefix = "ERROR: ";
                }
                else {
                  if (*(short *)(parseSymbol + 0x2c) != *(short *)(vertexSymbol + 0xb)) {
                    uVar26 = *(undefined4 *)(parseSymbol + 0x14);
                    slotIndexOrTemp = _strlen(UNK_a7b7bad0);
                    iVar4 = _strlen(uVar26);
                    uVar13 = ((int (*)())GetShaderStringForType)((uint)*(ushort *)(vertexSymbol + 0xb));
                    iVar19 = _strlen(uVar13);
                    uVar13 = ((int (*)())GetShaderStringForType)((uint)*(ushort *)(parseSymbol + 0x2c));
                    iVar14 = _strlen(uVar13);
                    messageText = (char *)_malloc(slotIndexOrTemp + iVar4 + iVar19 + iVar14 + 1);
                    uVar13 = ((int (*)())GetShaderStringForType)((uint)*(ushort *)(parseSymbol + 0x2c));
                    uVar15 = ((int (*)())GetShaderStringForType)((uint)*(ushort *)(vertexSymbol + 0xb));
                    _sprintf(messageText,UNK_a7b7bad0,uVar26,uVar15,uVar13);
                    infoSink = *(void **)(this + 0x84);
                    
                    goto override_jmp_97bb67f0_case_0;
                  }
                  if ((*(char *)*vertexSymbol == '\0') && (vertexSymbol[0x17] == 0)) goto code_r0x97bb689c;
                  uVar13 = *(undefined4 *)(parseSymbol + 0x14);
                  slotIndexOrTemp = _strlen(UNK_a7b7bb70);
                  iVar4 = _strlen(uVar13);
                  messageText = (char *)_malloc(slotIndexOrTemp + iVar4 + 1);
                  _sprintf(messageText,UNK_a7b7bb70,uVar13);
                  infoSink = *(void **)(this + 0x84);
                  messagePrefix = "INTERNAL ERROR: ";
                    
                }
                __ZN13TInfoSinkBase6appendEPKc(infoSink,messagePrefix);
                __ZN13TInfoSinkBase6appendEPKc(infoSink,messageText);
                __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
                _free(messageText);
              }
              else {
                while (uVar9 = ((int (*)())GetVec4sForType)(uVar9), vec4Index < uVar9) {
                  slotPlan[7] = 0xffffffff;
                  slotPlan[3] = 0xffffffff;
                  slotPlan[4] = 0xffffffff;
                  slotIndexOrTemp = 0;
                  slotPlan[5] = 0xffffffff;
                  slotPlan[6] = 0xffffffff;
                  slotPlan[0] = 0xffffffff;
                  slotPlan[1] = 0xffffffff;
                  slotPlan[2] = 0xffffffff;
                  do {
                    slotsFree = true;
                    if (bindingIndexOrComponentCount == 2) {
                      iVar4 = slotIndexOrTemp << 2;
code_r0x97bb5b68:
                      if (*(int *)(iVar4 + usedSetCountOrSlotMap + 4) == 0) {
code_r0x97bb5b80:
                        if (*(int *)(iVar4 + usedSetCountOrSlotMap) == 0) goto code_r0x97bb5b90;
                      }
code_r0x97bb5b8c:
                      slotsFree = false;
                    }
                    else {
                      if (2 < bindingIndexOrComponentCount) {
                        if (bindingIndexOrComponentCount == 3) {
                          iVar4 = slotIndexOrTemp << 2;
code_r0x97bb5b50:
                          if (*(int *)(iVar4 + usedSetCountOrSlotMap + 8) == 0) goto code_r0x97bb5b68;
                        }
                        else {
                          if (bindingIndexOrComponentCount != 4) goto code_r0x97bb5b90;
                          iVar4 = slotIndexOrTemp * 4;
                          if (*(int *)(iVar4 + usedSetCountOrSlotMap + 0xc) == 0) goto code_r0x97bb5b50;
                        }
                        goto code_r0x97bb5b8c;
                      }
                      if (bindingIndexOrComponentCount == 1) {
                        iVar4 = slotIndexOrTemp << 2;
                        goto code_r0x97bb5b80;
                      }
                    }
code_r0x97bb5b90:
                    slotsFree = !slotsFree;
                    if ((!slotsFree) && (uVar9 = 0, bindingIndexOrComponentCount != 0)) {
                      slotMapCursor = (int *)(slotIndexOrTemp * 4 + usedSetCountOrSlotMap);
                      slotPlanCursor = slotPlan;
                      uVar29 = bindingIndexOrComponentCount;
                      do {
                        uVar2 = *(uint *)(this + 0x78);
                        slotPlanCursor[4] = uVar9;
                        uVar9 = uVar9 + 1;
                        *(uint *)(this + 0x78) = uVar2 | 1 << (slotIndexOrTemp >> 2 & 0x3fU);
                        *slotPlanCursor = slotIndexOrTemp >> 2;
                        slotPlanCursor = slotPlanCursor + 1;
                        *slotMapCursor = allocationIdOrCounter;
                        slotMapCursor = slotMapCursor + 1;
                        uVar29 = uVar29 - 1;
                      } while (uVar29 != 0);
                    }
                    slotIndexOrTemp = slotIndexOrTemp + 4;
                  } while ((slotIndexOrTemp < 0x20) && (slotsFree));
                  slotIndexOrTemp = 0;
                  if (slotsFree) {
                    do {
                      uVar9 = 1;
                      if (-bindingIndexOrComponentCount == -4) {
code_r0x97bb5ccc:
                        if (!slotsFree) goto code_r0x97bb5cd0;
                      }
                      else {
                        if (slotsFree) {
                          do {
                            slotsFree = true;
                            if (bindingIndexOrComponentCount == 2) {
code_r0x97bb5c80:
                              if (*(int *)((slotIndexOrTemp + uVar9) * 4 + usedSetCountOrSlotMap + 4) == 0) {
code_r0x97bb5c9c:
                                if (*(int *)(usedSetCountOrSlotMap + (slotIndexOrTemp + uVar9) * 4) == 0)
                                goto code_r0x97bb5cb0;
                              }
code_r0x97bb5cac:
                              slotsFree = false;
                            }
                            else if (bindingIndexOrComponentCount < 3) {
                              if (bindingIndexOrComponentCount == 1) goto code_r0x97bb5c9c;
                            }
                            else if (bindingIndexOrComponentCount == 3) {
                              if (*(int *)((slotIndexOrTemp + uVar9) * 4 + usedSetCountOrSlotMap + 8) == 0)
                              goto code_r0x97bb5c80;
                              goto code_r0x97bb5cac;
                            }
code_r0x97bb5cb0:
                            uVar9 = uVar9 + 1;
                            if (-bindingIndexOrComponentCount + 4 < uVar9) {
                              slotsFree = !slotsFree;
                              goto code_r0x97bb5ccc;
                            }
                          } while (!slotsFree);
                          slotsFree = false;
                        }
code_r0x97bb5cd0:
                        iVar4 = 0;
                        if (bindingIndexOrComponentCount != 0) {
                          slotMapCursor = (int *)((slotIndexOrTemp + (uVar9 - 1)) * 4 + usedSetCountOrSlotMap);
                          slotPlanCursor = slotPlan;
                          uVar29 = bindingIndexOrComponentCount;
                          do {
                            uVar2 = *(uint *)(this + 0x78);
                            slotPlanCursor[4] = iVar4 + (uVar9 - 1);
                            iVar4 = iVar4 + 1;
                            *(uint *)(this + 0x78) = uVar2 | 1 << (slotIndexOrTemp >> 2 & 0x3fU);
                            *slotPlanCursor = slotIndexOrTemp >> 2;
                            slotPlanCursor = slotPlanCursor + 1;
                            *slotMapCursor = allocationIdOrCounter;
                            slotMapCursor = slotMapCursor + 1;
                            uVar29 = uVar29 - 1;
                          } while (uVar29 != 0);
                        }
                      }
                      slotIndexOrTemp = slotIndexOrTemp + 4;
                    } while ((slotIndexOrTemp < 0x20) && (slotsFree));
                  }
                  uVar9 = 0;
                  if ((bindingIndexOrComponentCount != 0) && (slotsFree)) {
                    do {
                      uVar29 = 0;
                      loopIndex = 0;
                      if (slotsFree) {
                        do {
                          uVar17 = uVar29;
                          if (*(int *)(loopIndex * 4 + usedSetCountOrSlotMap) == 0) {
                            uVar3 = ((int)loopIndex >> 2) + (uint)((int)loopIndex < 0 && (loopIndex & 3) != 0);
                            slotPlan[uVar29] = uVar3;
                            uVar17 = uVar29 + 1;
                            *(uint *)(this + 0x78) = *(uint *)(this + 0x78) | 1 << (uVar3 & 0x3f);
                            slotPlan[uVar29 + 4] = loopIndex + uVar3 * -4;
                            *(int *)(loopIndex * 4 + usedSetCountOrSlotMap) = allocationIdOrCounter;
                          }
                          if (uVar17 == bindingIndexOrComponentCount) {
                            slotsFree = false;
                          }
                          loopIndex = loopIndex + 1;
                        } while (((int)loopIndex < 0x20) && (uVar29 = uVar17, slotsFree));
                      }
                      uVar9 = uVar9 + 1;
                    } while ((uVar9 < bindingIndexOrComponentCount) && (slotsFree));
                  }
                  messageText = UNK_a7b7bacc;
                  allocationIdOrCounter = allocationIdOrCounter + 1;
                  if (slotsFree) {
                    success = 0;
                    infoSink = *(void **)(this + 0x84);
                    
                    __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
                    __ZN13TInfoSinkBase6appendEPKc(infoSink,messageText);
                    __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
                  }
                  else {
                    functionTable = *(unsigned char **)(this + 0x38);
                    insideMain = 0;
                    uVar9 = 0;
                    if ((functionTable != (unsigned char *)0x0) && (*(int *)(functionTable + 4) != 0)) {
                      while( true ) {
                        uVar13 = FunctionTable__getFunctionName(functionTable,uVar9);
                        slotIndexOrTemp = _memcmp(uVar13,"main(",6);
                        if (slotIndexOrTemp == 0) break;
                        functionTable = *(unsigned char **)(this + 0x38);
                        uVar9 = uVar9 + 1;
                        if ((functionTable == (unsigned char *)0x0) || (*(uint *)(functionTable + 4) <= uVar9))
                        break;
                      }
                    }
                    for (slotIndexOrTemp = **(int **)(*(int *)(this + 0x30) + 0x20); slotIndexOrTemp != 0;
                        slotIndexOrTemp = *(int *)(slotIndexOrTemp + 8)) {
                      uVar29 = FunctionTable__getFirstOp(*(unsigned char **)(this + 0x38),uVar9);
                      if (uVar29 == (*(uint *)(slotIndexOrTemp + 0xc) & 0x3ffff)) {
                        insideMain = 1;
                      }
                      if (((insideMain != 0) && ((*(uint *)(slotIndexOrTemp + 0xc) & 0x3fc0000) == 0x1340000))
                         && (uVar29 = 0, bindingIndexOrComponentCount != 0)) {
                        iVar4 = 0;
                        local_58 = slotPlan + 8;
code_r0x97bb5ec0:
                        ppStreamManager = *(int *)(this + 0x30);
                        loopIndex = 0;
                        uVar17 = *(uint *)((int)slotPlan + iVar4);
                        for (iVar19 = **(int **)(ppStreamManager + 0x1c); iVar19 != 0;
                            iVar19 = *(int *)(iVar19 + 8)) {
                          if (((*(uint *)(iVar19 + 0xc) & 0xf0000) == 0x60000) &&
                             ((*(uint *)(iVar19 + 0xc) & 0x1f) == uVar17)) {
                            bindingChunkIndex = *(ushort *)(iVar19 + 0x12);
                            uVar3 = 3;
                            slotMapCursor = (int *)(uVar17 * 0x10 + usedSetCountOrSlotMap + 0xc);
                            goto code_r0x97bb5f28;
                          }
                        }
                        outputBindingChunkIndex = 0;
                        outputBindingWord = uVar17 & 0x1f | 0x4060000;
                        slotMapCursor = (int *)(uVar17 * 0x10 + usedSetCountOrSlotMap + 0xc);
                        uVar3 = 3;
                        do {
                          iVar19 = *slotMapCursor;
                          slotMapCursor = slotMapCursor + -1;
                          if (iVar19 != 0) {
                            outputBindingWord = (uVar3 & 3) << 0x18 | uVar17 & 0x1f | 0x4060000;
                            break;
                          }
                          uVar3 = uVar3 - 1;
                        } while (-1 < (int)uVar3);
                        uVar13 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(ppStreamManager + 0x1c));
                        bindingChunkIndex = (short)uVar13 + 1;
                        outputBindingChunkIndex = CONCAT22((*(unsigned short *)((unsigned char *)&(outputBindingChunkIndex) + 0)),bindingChunkIndex);
                        _PPStreamAddOutputBinding(*(undefined4 *)(this + 0x30),&outputBindingWord);
code_r0x97bb5fe4:
                        ppStreamManager = *(int *)(this + 0x30);
                        goto code_r0x97bb5fe8;
                      }
code_r0x97bb61d0:
                      uVar29 = FunctionTable__getLastOp(*(unsigned char **)(this + 0x38),uVar9);
                      if (uVar29 == (*(uint *)(slotIndexOrTemp + 0xc) & 0x3ffff)) break;
                    }
                    functionTable = *(unsigned char **)(this + 0x3c);
                    uVar9 = 0;
                    if ((functionTable != (unsigned char *)0x0) && (*(int *)(functionTable + 4) != 0)) {
                      while( true ) {
                        uVar13 = FunctionTable__getFunctionName(functionTable,uVar9);
                        slotIndexOrTemp = _memcmp(uVar13,"main(",6);
                        if (slotIndexOrTemp == 0) break;
                        functionTable = *(unsigned char **)(this + 0x3c);
                        uVar9 = uVar9 + 1;
                        if ((functionTable == (unsigned char *)0x0) || (*(uint *)(functionTable + 4) <= uVar9))
                        break;
                      }
                    }
                    for (slotIndexOrTemp = **(int **)(*(int *)(this + 0x34) + 0x20); slotIndexOrTemp != 0;
                        slotIndexOrTemp = *(int *)(slotIndexOrTemp + 8)) {
                      uVar29 = FunctionTable__getFirstOp(*(unsigned char **)(this + 0x3c),uVar9);
                      if (uVar29 == (*(uint *)(slotIndexOrTemp + 0xc) & 0x3ffff)) {
                        uVar29 = 0;
                        if (bindingIndexOrComponentCount != 0) {
                          local_58 = slotPlan + 8;
                          iVar4 = 0;
                          goto code_r0x97bb62a8;
                        }
                        break;
                      }
                    }
                  }
code_r0x97bb6720:
                  uVar9 = (uint)*(ushort *)(parseSymbol + 0x2c);
                  vec4Index = vec4Index + 1;
                }
              }
            }
          }
          bindingIndexOrComponentCount = bindingIndexOrComponentCount - 1;
        } while (bindingIndexOrComponentCount != 0);
        slotIndexOrTemp = 0;
        *(undefined4 *)(this + 0x74) = 0xffffffff;
        allocationIdOrCounter = 8;
        do {
          iVar4 = slotIndexOrTemp * 4 + usedSetCountOrSlotMap;
          if ((((*(int *)(usedSetCountOrSlotMap + slotIndexOrTemp * 4) != 0) || (*(int *)(iVar4 + 4) != 0)) ||
              (*(int *)(iVar4 + 8) != 0)) || (*(int *)(iVar4 + 0xc) != 0)) {
            *(int *)(this + 0x74) = slotIndexOrTemp >> 2;
          }
          slotIndexOrTemp = slotIndexOrTemp + 4;
          allocationIdOrCounter = allocationIdOrCounter + -1;
        } while (allocationIdOrCounter != 0);
        if (usedSetCountOrSlotMap != 0) {
          _free(usedSetCountOrSlotMap);
        }
      }
      else {
        usedSetCountOrSlotMap = _strlen(DAT_a7b7bb00);
        messageText = (char *)_malloc(usedSetCountOrSlotMap + 0x11);
        _sprintf(messageText,DAT_a7b7bb00,0x20,slotIndexOrTemp);
        infoSink = *(void **)(this + 0x84);
                    
        __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
        __ZN13TInfoSinkBase6appendEPKc(infoSink,messageText);
        __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
        _free(messageText);
        success = 0;
      }
    }
  }
  return success;
  while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
code_r0x97bb5f28:
    iVar12 = *slotMapCursor;
    slotMapCursor = slotMapCursor + -1;
    if (iVar12 != 0) {
      *(uint *)(iVar19 + 0xc) = (uVar3 & 3) << 0x18 | *(uint *)(iVar19 + 0xc) & 0xfcffffff;
      goto code_r0x97bb5fe4;
    }
  }
code_r0x97bb5fe8:
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  slotPlan[9] = 0;
  uVar3 = 0x60000;
  uVar21 = 0x800000;
  slotPlan[8] = 0x20000000;
  slotPlan[0xc] = 0x800000;
  slotPlan[10] = 0x60000;
  local_90 = *(undefined4 *)(slotIndexOrTemp + 0x3c);
  slotPlan[0xb] = (uint)bindingChunkIndex;
  local_8c = 0;
  slotPlan[0xd] = (uint)(ushort)(*(short *)(*vertexSymbol + 0x12) + (short)vec4Index);
  uVar6 = *(uint *)((int)slotPlan + iVar4);
  while ((uVar6 == uVar17 && (uVar29 < bindingIndexOrComponentCount))) {
    uVar6 = *(uint *)((int)slotPlan + iVar4 + 0x10);
    if (uVar6 == 1) {
      uVar3 = (loopIndex & 3) << 6 | uVar3 & 0xffffff3f | 0x4000;
code_r0x97bb60fc:
      uVar3 = (uVar6 & 3) << 10 | uVar3 & 0xfffff3ff;
      slotPlan[10] = uVar3;
    }
    else {
      if (1 < (int)uVar6) {
        if (uVar6 == 2) {
          uVar3 = (loopIndex & 3) << 4 | uVar3 & 0xffffffcf | 0x8000;
        }
        else {
          if (uVar6 != 3) goto code_r0x97bb6108;
          uVar3 = (loopIndex & 3) << 2 | uVar3 & 0xfffffff3 | 0x10000;
        }
        goto code_r0x97bb60fc;
      }
      if (uVar6 == 0) {
        uVar3 = (loopIndex & 3) << 8 | uVar3 & 0xfffffcff | 0x2000;
        goto code_r0x97bb60fc;
      }
    }
code_r0x97bb6108:
    if (loopIndex == 1) {
      uVar21 = (uVar29 & 3) << 0x13 | uVar21 & 0xffe7ffff;
code_r0x97bb6150:
      slotPlan[0xc] = uVar21;
    }
    else {
      if (1 < (int)loopIndex) {
        if (loopIndex == 2) {
          uVar21 = (uVar29 & 3) << 0x11 | uVar21 & 0xfff9ffff;
        }
        else {
          if (loopIndex != 3) goto code_r0x97bb6154;
          uVar21 = (uVar29 & 3) << 0xf | uVar21 & 0xfffe7fff;
        }
        goto code_r0x97bb6150;
      }
      if (loopIndex == 0) {
        uVar21 = (uVar29 & 3) << 0x15 | uVar21 & 0xff9fffff;
        goto code_r0x97bb6150;
      }
    }
code_r0x97bb6154:
    uVar29 = uVar29 + 1;
    loopIndex = loopIndex + 1;
    iVar4 = uVar29 * 4;
    uVar6 = slotPlan[uVar29];
  }
  slotPlan[0xc] = (loopIndex - 1) * 0x1000 & 0x3000 | uVar21;
  slotPlan[9] = (loopIndex - 1) * 0x4000000 & 0xc000000 | 0x800000;
  iVar19 = _PPStreamInsertOperationAfterChunk(ppStreamManager,local_58,0,0,*(undefined4 *)(slotIndexOrTemp + 4));
  _PPStreamChangeBranchTargets
            (*(undefined4 *)(this + 0x30),*(uint *)(slotIndexOrTemp + 0xc) & 0x3ffff,
             *(uint *)(iVar19 + 0xc) & 0x3ffff);
  if (bindingIndexOrComponentCount <= uVar29) goto code_r0x97bb61d0;
  goto code_r0x97bb5ec0;
code_r0x97bb62a8:
  loopIndex = 0;
  uVar17 = *(uint *)((int)slotPlan + iVar4);
  for (iVar19 = **(int **)(*(int *)(this + 0x34) + 0x18); iVar19 != 0; iVar19 = *(int *)(iVar19 + 8)
      ) {
    if (((*(uint *)(iVar19 + 0xc) & 0xf0000) == 0x70000) &&
       ((*(uint *)(iVar19 + 0xc) & 0x1f) == uVar17)) {
      bindingChunkIndex = *(ushort *)(iVar19 + 0x12);
      uVar3 = 3;
      slotMapCursor = (int *)(uVar17 * 0x10 + usedSetCountOrSlotMap + 0xc);
      goto code_r0x97bb630c;
    }
  }
  local_6c = 0;
  local_70 = uVar17 & 0x1f | 0x4070000;
  slotMapCursor = (int *)(uVar17 * 0x10 + usedSetCountOrSlotMap + 0xc);
  uVar3 = 3;
  do {
    iVar19 = *slotMapCursor;
    slotMapCursor = slotMapCursor + -1;
    if (iVar19 != 0) {
      local_70 = (uVar3 & 3) << 0x18 | uVar17 & 0x1f | 0x4070000;
      break;
    }
    uVar3 = uVar3 - 1;
  } while (-1 < (int)uVar3);
  uVar13 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(*(int *)(this + 0x34) + 0x18));
  bindingChunkIndex = (short)uVar13 + 1;
  local_6c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_6c) + 0)),bindingChunkIndex);
  _PPStreamAddAttribBinding(*(undefined4 *)(this + 0x34),&local_70);
  goto code_r0x97bb63d0;
  while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
code_r0x97bb630c:
    iVar14 = *slotMapCursor;
    slotMapCursor = slotMapCursor + -1;
    if (iVar14 != 0) {
      *(uint *)(iVar19 + 0xc) = (uVar3 & 3) << 0x18 | *(uint *)(iVar19 + 0xc) & 0xfcffffff;
      break;
    }
  }
code_r0x97bb63d0:
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  slotPlan[0xb] = 0;
  slotPlan[9] = 0;
  uVar21 = 0x20000;
  slotPlan[8] = 0x20000000;
  slotPlan[10] = 0x20000;
  local_90 = *(undefined4 *)(slotIndexOrTemp + 0x3c);
  local_8c = 0;
  uVar3 = 0;
  slotPlan[0xd] = (uint)bindingChunkIndex;
  slotPlan[0xc] = 0;
  uVar6 = *(uint *)((int)slotPlan + iVar4);
  slotPlan[0xb] = (uint)(ushort)(*(short *)(*(int *)parseSymbol + 0x12) + (short)vec4Index);
  while ((uVar6 == uVar17 && (uVar29 < bindingIndexOrComponentCount))) {
    if (loopIndex == 1) {
      uVar21 = (uVar29 & 3) << 6 | uVar21 & 0xffffff3f | 0x4000;
code_r0x97bb64dc:
      slotPlan[10] = uVar21;
    }
    else {
      if (1 < (int)loopIndex) {
        if (loopIndex == 2) {
          uVar21 = (uVar29 & 3) << 4 | uVar21 & 0xffffffcf | 0x8000;
        }
        else {
          if (loopIndex != 3) goto code_r0x97bb64e0;
          uVar21 = (uVar29 & 3) << 2 | uVar21 & 0xfffffff3 | 0x10000;
        }
        uVar21 = (loopIndex & 3) << 10 | uVar21 & 0xfffff3ff;
        goto code_r0x97bb64dc;
      }
      if (loopIndex == 0) {
        uVar21 = (uVar29 & 3) << 8 | uVar21 & 0xfffffcff | 0x2000;
        goto code_r0x97bb64dc;
      }
    }
code_r0x97bb64e0:
    if (loopIndex == 1) {
      uVar3 = (*(uint *)((int)slotPlan + iVar4 + 0x10) & 3) << 0x13 | uVar3 & 0xffe7ffff;
code_r0x97bb6544:
      slotPlan[0xc] = uVar3;
    }
    else {
      if (1 < (int)loopIndex) {
        if (loopIndex == 2) {
          uVar3 = (*(uint *)((int)slotPlan + iVar4 + 0x10) & 3) << 0x11 | uVar3 & 0xfff9ffff;
        }
        else {
          if (loopIndex != 3) goto code_r0x97bb6548;
          uVar3 = (*(uint *)((int)slotPlan + iVar4 + 0x10) & 3) << 0xf | uVar3 & 0xfffe7fff;
        }
        goto code_r0x97bb6544;
      }
      if (loopIndex == 0) {
        uVar3 = (*(uint *)((int)slotPlan + iVar4 + 0x10) & 3) << 0x15 | uVar3 & 0xff9fffff;
        goto code_r0x97bb6544;
      }
    }
code_r0x97bb6548:
    uVar29 = uVar29 + 1;
    loopIndex = loopIndex + 1;
    iVar4 = uVar29 * 4;
    uVar6 = slotPlan[uVar29];
  }
  iVar19 = loopIndex - 1;
  slotPlan[0xc] = iVar19 * 0x1000 & 0x3000U | uVar3;
  slotPlan[10] = iVar19 * 0x400 & 0xc00U | uVar21 & 0xfffff3ff;
  slotPlan[9] = iVar19 * 0x4000000 & 0xc000000U | 0x800000;
  firstOp = FunctionTable__getFirstOp(*(unsigned char **)(this + 0x3c),uVar9);
  if (firstOp == (*(uint *)(slotIndexOrTemp + 0xc) & 0x3ffff)) {
    iVar19 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(*(int *)(this + 0x34) + 0x20));
    *(uint *)(slotIndexOrTemp + 0xc) = iVar19 + 1U & 0x3ffff | *(uint *)(slotIndexOrTemp + 0xc) & 0xfffc0000;
    uVar13 = FunctionTable__getFirstOp(*(unsigned char **)(this + 0x3c),uVar9);
    _PPStreamChangeBranchTargets
              (*(undefined4 *)(this + 0x34),uVar13,*(uint *)(slotIndexOrTemp + 0xc) & 0x3ffff);
  }
  iVar19 = _PPStreamInsertOperationAfterChunk
                     (*(undefined4 *)(this + 0x34),local_58,0,1,*(undefined4 *)(slotIndexOrTemp + 4));
  if (iVar19 != 0) {
    FunctionTable__setFirstOp(*(unsigned char **)(this + 0x3c),uVar9,0);
    for (iVar14 = **(int **)(*(int *)(this + 0x34) + 0x24); slotIndexOrTemp = iVar19, iVar14 != 0;
        iVar14 = *(int *)(iVar14 + 8)) {
      iVar12 = _memcmp("main(",iVar14 + 0x14,6);
      if (iVar12 == 0) {
        *(undefined4 *)(iVar14 + 0xc) = 0;
        break;
      }
    }
  }
  if (bindingIndexOrComponentCount <= uVar29) goto code_r0x97bb6720;
  goto code_r0x97bb62a8;
}

/* TGenericLinker__CoalesceCommonUniforms @ 0x97bb6b48 (484 bytes) */
int TGenericLinker__CoalesceCommonUniforms(this)
  unsigned char * this;
{
  uint mergedWidth;
  unsigned char chunkKind;
  uint registerClass;
  unsigned char * symbol;
  unsigned char * otherSymbol;
  int existingArray;
  uint keepWidth;
  int stageByteOffset;
  int stage;
  unsigned char * otherChunk;
  unsigned char * stageSlot;
  unsigned char * chunk;
  undefined8 chunkKey;
  uint otherKeyHi;
  uint otherKeyLo;
  
  stage = 0;
  stageByteOffset = 0;
  stageSlot = this;
  do {
    if (*(unsigned char **)(stageSlot + 0x28) != (unsigned char *)0x0) {
      for (symbol = (unsigned char *)
                    ParseSymbolTable__NextSymbol
                              (*(unsigned char **)(stageSlot + 0x28),(unsigned char *)0x0);
          symbol != (unsigned char *)0x0;
          symbol = (unsigned char *)
                   ParseSymbolTable__NextSymbol(*(unsigned char **)(stageSlot + 0x28),symbol)) {
        chunk = *(unsigned char **)symbol;
        if ((chunk != (unsigned char *)0x0) && (*chunk == 0x3)) {
          (*(unsigned int *)((unsigned char *)&(chunkKey) + 0)) = (uint)(*(ulonglong *)(chunk + 0xc) >> 0x20);
          registerClass = ((*(unsigned int *)((unsigned char *)&(chunkKey) + 0)) & 0xfcffffff) >> 0x10 & 0x1f;
          chunkKey = *(ulonglong *)(chunk + 0xc) & 0xfcffffffffff0000;
          if ((2 < registerClass) &&
             ((registerClass < 0x13 &&
              (otherSymbol = (unsigned char *)
                         ParseSymbolTable__NextSymbol(*(unsigned char **)(stageSlot + 0x28),symbol),
              otherSymbol != (unsigned char *)0x0)))) {
            chunkKind = *chunk;
            while (chunkKind == 0x3) {
              otherChunk = *(unsigned char **)otherSymbol;
              if (((otherChunk != (unsigned char *)0x0) && (otherChunk != chunk)) &&
                 (*otherChunk == 0x3)) {
                otherKeyHi = (uint)((ulonglong)*(undefined8 *)(otherChunk + 0xc) >> 0x20);
                otherKeyLo = (uint)*(undefined8 *)(otherChunk + 0xc) & 0xffff0000;
                if ((((otherKeyHi & 0xfcffffff) == (*(unsigned int *)((unsigned char *)&(chunkKey) + 0))) && (otherKeyLo == (*(unsigned int *)((unsigned char *)&(chunkKey) + 4))))
                   && (existingArray = _PPStreamGetArray(*(undefined4 *)(this + stageByteOffset + 0x30),2,
                                                 (uint)*(ushort *)(otherChunk + 0x12)), existingArray == -1)) {
                  _PPStreamRenumberOperandIndices
                            (*(undefined4 *)(this + stageByteOffset + 0x30),otherChunk,
                             (uint)*(ushort *)(chunk + 0x12));
                  keepWidth = *(uint *)(chunk + 0xc) >> 0x18 & 3;
                  mergedWidth = *(uint *)(otherChunk + 0xc) >> 0x18 & 3;
                  if (mergedWidth < keepWidth) {
                    mergedWidth = keepWidth;
                  }
                  *(uint *)(chunk + 0xc) = mergedWidth << 0x18 | *(uint *)(chunk + 0xc) & 0xfcffffff;
                  _PPStreamChunkListRemoveChunk
                            (*(undefined4 *)(*(int *)(this + stageByteOffset + 0x30) + 0x10),otherChunk);
                  ParseSymbol__SetChunk(otherSymbol,chunk);
                  *(undefined4 *)(otherSymbol + 0x44) = 0;
                }
              }
              otherSymbol = (unsigned char *)
                        ParseSymbolTable__NextSymbol
                                  (*(unsigned char **)(this + stageByteOffset + 0x28),otherSymbol);
              if (otherSymbol == (unsigned char *)0x0) break;
              chunkKind = *chunk;
            }
          }
        }
      }
    }
    stage = stage + 1;
    stageByteOffset = stageByteOffset + 4;
    stageSlot = stageSlot + 4;
    if (1 < stage) {
      return 1;
    }
  } while( true );
}

/* TGenericLinker__BuildUniformRemapTables @ 0x97bb6d2c (372 bytes) */
int TGenericLinker__BuildUniformRemapTables(this)
  unsigned char * this;
{
  char *errorText;
  undefined4 symbolTypeName;
  undefined4 boundTypeName;
  undefined4 boundTypeNameAgain;
  int uniformCountNow;
  int boundTypeNameLength;
  int entryIndex;
  int nameLength;
  int fragmentMapped;
  int bindingLocation;
  int formatLength;
  int initIndex;
  int vertexMapped;
  int stageLoop;
  int isBuiltIn;
  bool typeSeen;
  unsigned char * binding;
  int uniformCount;
  undefined4 remapTable;
  int uniformCountBound;
  int *symbol;
  char *message;
  int symbolTypeNameLength;
  uint bindingSlots;
  uint boundType;
  undefined4 status;
  int stageIndex;
  unsigned char * stageSlot;
  int symbolName;
  int symbolNameCopy;
  uint slotIndex;
  uint registerIndex;
  void *infoSink;
  
  status = 1;
  binding = (unsigned char *)BindingTable__NextUniformBinding(*(unsigned char **)(this + 4),(unsigned char *)0x0)
  ;
  stageIndex = 0;
  stageSlot = this;
  do {
    uniformCount = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4));
    remapTable = _malloc(uniformCount * 4 + 0xfU & 0xfffffff0);
    *(undefined4 *)(stageSlot + 0x40) = remapTable;
    if (*(int *)(stageSlot + 0x28) == 0) {
      *(undefined4 *)(stageSlot + 0x48) = 0;
    }
    else {
      *(undefined4 *)(stageSlot + 0x48) = *(undefined4 *)(*(int *)(stageSlot + 0x28) + 0x28);
    }
    for (initIndex = 0; uniformCountBound = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4)),
        initIndex < uniformCountBound; initIndex = initIndex + 1) {
      *(undefined4 *)(initIndex * 4 + *(int *)(stageSlot + 0x40)) = 0xffffffff;
    }
    stageIndex = stageIndex + 1;
    stageSlot = stageSlot + 4;
  } while (stageIndex < 2);
  for (; binding != (unsigned char *)0x0;
      binding = (unsigned char *)BindingTable__NextUniformBinding(*(unsigned char **)(this + 4),binding)) {
    isBuiltIn = Binding__IsBuiltIn(binding);
    if (isBuiltIn == 0) {
      boundType = 0;
      typeSeen = false;
      stageLoop = 0;
      do {
        if ((*(unsigned char **)(this + stageLoop * 4 + 0x28) != (unsigned char *)0x0) &&
           (symbol = (int *)ParseSymbolTable__FindGlobalSymbolByName
                                      (*(unsigned char **)(this + stageLoop * 4 + 0x28),
                                       *(char **)(binding + 8)), symbol != (int *)0x0)) {
          if ((*(char *)*symbol != '\x03') ||
             ((*(uint *)((char *)*symbol + 0xc) & 0x1f0000) != 0x10000)) {
            symbolName = symbol[5];
            formatLength = _strlen(DAT_a7b7bb74);
            nameLength = _strlen(symbolName);
            message = (char *)_malloc(formatLength + nameLength + 1);
            _sprintf(message,DAT_a7b7bb74,symbolName);
            infoSink = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(infoSink,message);
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
            status = 0;
            _free(message);
          }
          if (typeSeen) {
            if (*(ushort *)(symbol + 0xb) != boundType) {
              symbolNameCopy = symbol[5];
              formatLength = _strlen(UNK_a7b7bae4);
              nameLength = _strlen(symbolNameCopy);
              boundTypeName = ((int (*)())GetShaderStringForType)(boundType);
              boundTypeNameLength = _strlen(boundTypeName);
              symbolTypeName = ((int (*)())GetShaderStringForType)((uint)*(ushort *)(symbol + 0xb));
              symbolTypeNameLength = _strlen(symbolTypeName);
              message = (char *)_malloc(formatLength + nameLength + boundTypeNameLength + symbolTypeNameLength + 1);
              symbolTypeName = ((int (*)())GetShaderStringForType)((uint)*(ushort *)(symbol + 0xb));
              boundTypeNameAgain = ((int (*)())GetShaderStringForType)(boundType);
              _sprintf(message,UNK_a7b7bae4,symbolNameCopy,boundTypeNameAgain,symbolTypeName);
              infoSink = *(void **)(this + 0x84);
                    
              __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
              __ZN13TInfoSinkBase6appendEPKc(infoSink,message);
              __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
              status = 0;
              _free(message);
            }
          }
          else {
            boundType = (uint)*(ushort *)(symbol + 0xb);
            typeSeen = true;
          }
          registerIndex = (uint)*(ushort *)(*symbol + 0xe);
          for (slotIndex = 0; bindingSlots = Binding__GetBindingSlots(binding), slotIndex < bindingSlots;
              slotIndex = slotIndex + 1) {
            bindingLocation = Binding__GetLocation(binding);
            *(uint *)((bindingLocation + slotIndex) * 4 + *(int *)(this + stageLoop * 4 + 0x40)) = registerIndex;
            registerIndex = registerIndex + 1;
          }
        }
        stageLoop = stageLoop + 1;
      } while (stageLoop < 2);
    }
  }
  vertexMapped = 0;
  fragmentMapped = 0;
  for (entryIndex = 0; uniformCountNow = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4)),
      errorText = UNK_a7b7bb04, entryIndex < uniformCountNow; entryIndex = entryIndex + 1) {
    if (*(int *)(entryIndex * 4 + *(int *)(this + 0x40)) != -1) {
      vertexMapped = vertexMapped + 1;
    }
    if (*(int *)(entryIndex * 4 + *(int *)(this + 0x44)) != -1) {
      fragmentMapped = fragmentMapped + 1;
    }
  }
  if (*(int *)(this + 0x48) != vertexMapped) {
    infoSink = *(void **)(this + 0x84);
                    
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(infoSink,errorText);
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
    status = 0;
  }
  errorText = UNK_a7b7bb08;
  if (*(int *)(this + 0x4c) != fragmentMapped) {
    infoSink = *(void **)(this + 0x84);
                    
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(infoSink,errorText);
    __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
    status = 0;
  }
  return status;
}

/* TGenericLinker__InsertUniformBindingFromSymbol @ 0x97bb727c (388 bytes) */
int TGenericLinker__InsertUniformBindingFromSymbol(this, parseSymbol, isFragment)
  unsigned char * this;
  unsigned char * parseSymbol;
  int isFragment;
{
  undefined4 uniformName;
  unsigned char * binding;
  unsigned char * existingBinding;
  int formatLength;
  int nameLength;
  char *message;
  undefined4 success;
  void *infoSink;
  
  success = 1;
  if ((**(char **)parseSymbol == '\x03') &&
     ((*(uint *)(*(char **)parseSymbol + 0xc) & 0x1f0000) != 0x110000)) {
    binding = operator_new(0x38);
    __ZN7BindingC1Ev(binding);
    if (binding == (unsigned char *)0x0) {
      uniformName = *(undefined4 *)(parseSymbol + 0x14);
      formatLength = _strlen(DAT_a7b7bb7c);
      nameLength = _strlen(uniformName);
      message = (char *)_malloc(formatLength + nameLength + 1);
      _sprintf(message,DAT_a7b7bb7c,uniformName);
      infoSink = *(void **)(this + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"INTERNAL ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(infoSink,message);
      __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
      _free(message);
      success = 0;
    }
    else {
      Binding__SetName(binding,*(char **)(parseSymbol + 0x14));
      existingBinding = (unsigned char *)BindingTable__FindUniformBinding(*(unsigned char **)(this + 4),binding);
      if (existingBinding == (unsigned char *)0x0) {
        Binding__SetClientRequest(binding,0);
        Binding__SetOpenGLType(binding,*(ushort *)(parseSymbol + 0x2c));
        Binding__SetDecSize(binding,(int)*(short *)(parseSymbol + 0x2e));
        Binding__SetActualSize(binding,1);
        Binding__SetBuiltIn(binding,*(undefined4 *)(parseSymbol + 0x34));
        if (*(short *)(parseSymbol + 0x2e) == 1) {
          BindingTable__InsertSingleUniform(*(unsigned char **)(this + 4),binding,isFragment);
        }
        else {
          BindingTable__InsertUniformArray
                    (*(unsigned char **)(this + 4),binding,(int)*(short *)(parseSymbol + 0x30),isFragment,2,
                     (unsigned char **)(this + 0x28));
        }
      }
      else {
        if (*(short *)(parseSymbol + 0x2e) == 1) {
          BindingTable__AddSingleUniformReference(*(unsigned char **)(this + 4),existingBinding,isFragment);
        }
        __ZN7BindingD1Ev(binding);
        __ZdlPv(binding);
      }
    }
  }
  return success;
}

/* TGenericLinker__CollectUniformBindings @ 0x97bb7498 (296 bytes) */
int TGenericLinker__CollectUniformBindings(this)
  unsigned char * this;
{
  unsigned char * symbolTable;
  unsigned char * parseSymbol;
  int insertOk;
  undefined4 success;
  unsigned char * stageSlot;
  int stage;
  unsigned char * tableSlot;
  
  success = 1;
  stage = 0;
  tableSlot = this + 0x28;
  stageSlot = this;
  do {
    symbolTable = *(unsigned char **)tableSlot;
    tableSlot = tableSlot + 4;
    if (symbolTable != (unsigned char *)0x0) {
      for (parseSymbol = (unsigned char *)ParseSymbolTable__NextSymbol(symbolTable,(unsigned char *)0x0);
          parseSymbol != (unsigned char *)0x0;
          parseSymbol = (unsigned char *)
                   ParseSymbolTable__NextSymbol(*(unsigned char **)(stageSlot + 0x28),parseSymbol)) {
        if ((*(int *)(parseSymbol + 0x34) == 0) &&
           (insertOk = ((int (*)())TGenericLinker__InsertUniformBindingFromSymbol)(this,parseSymbol,stage), insertOk == 0)) {
          success = 0;
        }
      }
    }
    stage = stage + 1;
    stageSlot = stageSlot + 4;
  } while (stage < 2);
  stage = 0;
  tableSlot = this + 0x28;
  stageSlot = this;
  do {
    symbolTable = *(unsigned char **)tableSlot;
    tableSlot = tableSlot + 4;
    if (symbolTable != (unsigned char *)0x0) {
      for (parseSymbol = (unsigned char *)ParseSymbolTable__NextSymbol(symbolTable,(unsigned char *)0x0);
          parseSymbol != (unsigned char *)0x0;
          parseSymbol = (unsigned char *)
                   ParseSymbolTable__NextSymbol(*(unsigned char **)(stageSlot + 0x28),parseSymbol)) {
        if ((*(int *)(parseSymbol + 0x34) != 0) &&
           (insertOk = ((int (*)())TGenericLinker__InsertUniformBindingFromSymbol)(this,parseSymbol,stage), insertOk == 0)) {
          success = 0;
        }
      }
    }
    stage = stage + 1;
    stageSlot = stageSlot + 4;
  } while (stage < 2);
  return success;
}

/* TGenericLinker__CreateFunctionTable @ 0x97bb75c0 (428 bytes) */
int TGenericLinker__CreateFunctionTable(this, stage)
  unsigned char * this;
  int stage;
{
  int calleeNameLen;
  int compareResult2;
  int shaderStringLen2;
  int scanFnIdx;
  int nameCopy;
  int duplicateNameLen;
  int msgFormatLen;
  int scanObjIdx;
  int earlierFnIdx;
  int calleeName;
  int mergedFnIdx;
  char *errorMessage;
  uint charIdx;
  uint lastOp;
  undefined4 calleeScanName;
  undefined4 otherFnName;
  undefined4 returnVal;
  bool calleeFound;
  int opChunk;
  unsigned char * scanFnTable;
  int stageOffset;
  bool isDuplicate;
  bool calleeMissing;
  bool errorFound;
  unsigned char * mergedTable;
  undefined4 emptyFlag;
  undefined4 thisFnName;
  int compareResult;
  uint nameLen;
  int msgFormatLen2;
  int shaderStringLen;
  int nameCopyLen;
  char *fnName;
  int objectIdx;
  int earlierObjIdx;
  int fnIdx;
  unsigned char * objectFnTable;
  unsigned char * earlierFnTable;
  int numParams;
  uint firstOp;
  void *infoSink;
  
  stageOffset = stage * 4;
  mergedTable = operator_new(8);
  errorFound = false;
  __ZN13FunctionTableC1Ev(mergedTable);
  objectIdx = 0;
  if (0 < *(int *)(this + stageOffset + 0x20)) {
    do {
      fnIdx = 0;
      objectFnTable = *(unsigned char **)(*(int *)(objectIdx * 4 + *(int *)(this + stageOffset + 8)) + 0x6c);
      if (0 < *(int *)(objectFnTable + 4)) {
        do {
          isDuplicate = false;
          earlierObjIdx = 0;
          if (objectIdx < 1) {
LAB_97bb7818:
            fnName = (char *)FunctionTable__getFunctionName(objectFnTable,fnIdx);
            mergedFnIdx = FunctionTable__addFunction(mergedTable,fnName);
            emptyFlag = FunctionTable__getEmpty(objectFnTable,fnIdx);
            FunctionTable__setEmpty(mergedTable,mergedFnIdx,emptyFlag);
            returnVal = FunctionTable__getReturnVal(objectFnTable,fnIdx);
            FunctionTable__setReturnVal(mergedTable,mergedFnIdx,returnVal);
            numParams = FunctionTable__getNumParams(objectFnTable,fnIdx);
            FunctionTable__setNumParams(mergedTable,mergedFnIdx,numParams);
            firstOp = FunctionTable__getFirstOp(objectFnTable,fnIdx);
            FunctionTable__setFirstOp(mergedTable,mergedFnIdx,firstOp);
            lastOp = FunctionTable__getLastOp(objectFnTable,fnIdx);
            FunctionTable__setLastOp(mergedTable,mergedFnIdx,lastOp);
          }
          else {
            do {
              earlierFnIdx = 0;
              earlierFnTable = *(unsigned char **)
                         (*(int *)(earlierObjIdx * 4 + *(int *)(this + stageOffset + 8)) + 0x6c);
              if (0 < *(int *)(earlierFnTable + 4)) {
                do {
                  otherFnName = FunctionTable__getFunctionName(earlierFnTable,earlierFnIdx);
                  thisFnName = FunctionTable__getFunctionName(objectFnTable,fnIdx);
                  compareResult = _strcmp(otherFnName,thisFnName);
                  if (compareResult == 0) {
                    otherFnName = FunctionTable__getFunctionName(earlierFnTable,earlierFnIdx);
                    duplicateNameLen = _strlen(otherFnName);
                    nameCopy = _malloc(duplicateNameLen + 1);
                    otherFnName = FunctionTable__getFunctionName(earlierFnTable,earlierFnIdx);
                    _strcpy(nameCopy,otherFnName);
                    for (charIdx = 0; nameLen = _strlen(nameCopy), charIdx < nameLen; charIdx = charIdx + 1) {
                      if (*(char *)(nameCopy + charIdx) == '(') {
                        *(undefined1 *)(nameCopy + charIdx) = 0;
                      }
                    }
                    msgFormatLen2 = _strlen(DAT_a7b7bb20);
                    shaderStringLen = _strlen((&_shaderString)[stage]);
                    nameCopyLen = _strlen(nameCopy);
                    errorMessage = (char *)_malloc(msgFormatLen2 + shaderStringLen + nameCopyLen + 1);
                    _sprintf(errorMessage,DAT_a7b7bb20,nameCopy,(&_shaderString)[stage]);
                    infoSink = *(void **)(this + 0x84);
                    
                    __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
                    __ZN13TInfoSinkBase6appendEPKc(infoSink,errorMessage);
                    __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
                    _free(errorMessage);
                    _free(nameCopy);
                    isDuplicate = true;
                  }
                  earlierFnIdx = earlierFnIdx + 1;
                } while (earlierFnIdx < *(int *)(earlierFnTable + 4));
              }
              earlierObjIdx = earlierObjIdx + 1;
            } while (earlierObjIdx < objectIdx);
            if (!isDuplicate) goto LAB_97bb7818;
          }
          fnIdx = fnIdx + 1;
          errorFound = (bool)(errorFound | isDuplicate);
        } while (fnIdx < *(int *)(objectFnTable + 4));
      }
      for (opChunk = **(int **)(*(int *)(objectIdx * 4 + *(int *)(this + stageOffset + 0x18)) + 0x20);
          opChunk != 0; opChunk = *(int *)(opChunk + 8)) {
        if ((*(uint *)(opChunk + 0xc) & 0x3fc0000) == 0x1300000) {
          calleeFound = false;
          scanObjIdx = 0;
          calleeName = _malloc(*(int *)(opChunk + 0x40) + 1);
          _strcpy(calleeName,opChunk + 0x44);
          if (*(int *)(this + stageOffset + 0x20) < 1) {
            calleeMissing = true;
          }
          else {
            do {
              scanFnIdx = 0;
              scanFnTable = *(unsigned char **)
                         (*(int *)(scanObjIdx * 4 + *(int *)(this + stageOffset + 8)) + 0x6c);
              if (0 < *(int *)(scanFnTable + 4)) {
                do {
                  calleeScanName = FunctionTable__getFunctionName(scanFnTable,scanFnIdx);
                  compareResult2 = _strcmp(calleeName,calleeScanName);
                  if (compareResult2 == 0) {
                    calleeFound = true;
                    break;
                  }
                  scanFnIdx = scanFnIdx + 1;
                } while (scanFnIdx < *(int *)(scanFnTable + 4));
              }
              calleeMissing = !calleeFound;
              if (!calleeMissing) goto code_r0x97bb7ad8;
              scanObjIdx = scanObjIdx + 1;
            } while (scanObjIdx < *(int *)(this + stageOffset + 0x20));
          }
          if (calleeMissing) {
            for (charIdx = 0; nameLen = _strlen(calleeName), charIdx < nameLen; charIdx = charIdx + 1) {
              if (*(char *)(calleeName + charIdx) == '(') {
                *(undefined1 *)(calleeName + charIdx) = 0;
              }
            }
            msgFormatLen = _strlen(UNK_a7b7bb24);
            shaderStringLen2 = _strlen((&_shaderString)[stage]);
            calleeNameLen = _strlen(calleeName);
            errorMessage = (char *)_malloc(msgFormatLen + shaderStringLen2 + calleeNameLen + 1);
            _sprintf(errorMessage,UNK_a7b7bb24,calleeName,(&_shaderString)[stage]);
            infoSink = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(infoSink,errorMessage);
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
            _free(errorMessage);
            errorFound = true;
          }
code_r0x97bb7ad8:
          _free(calleeName);
        }
      }
      objectIdx = objectIdx + 1;
    } while (objectIdx < *(int *)(this + stageOffset + 0x20));
    if (errorFound) goto code_r0x97bb7b18;
  }
  if (*(int *)(mergedTable + 4) != 0) {
    return mergedTable;
  }
code_r0x97bb7b18:
  if (mergedTable != (unsigned char *)0x0) {
    __ZN13FunctionTableD1Ev(mergedTable);
    __ZdlPv(mergedTable);
  }
  return (unsigned char *)0x0;
}

/* TGenericLinker__BuildSymbolTableList @ 0x97bb7b4c (352 bytes) */
int TGenericLinker__BuildSymbolTableList(this, param_2, param_3)
  unsigned char * this;
  void **param_2;
  int param_3;
{
  char *allocation;
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  size_t length;
  size_t length2;
  char *pcVar7;
  void **r4Out0;
  void **r4Out1;
  void **r4In0;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  unsigned char * pTVar8;
  undefined4 r10In0;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  void *pvVar13;
  int local_50 [2];
  undefined8 local_48;
  undefined8 local_40 [2];
  
  iVar10 = 0;
  pTVar8 = (unsigned char *)0x0;
  r10In0 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_48 = DAT_97c38fb0;
  iVar12 = 1;
  local_40[0] = DAT_97c38fb8;
  r4In0 = param_2;
  iVar11 = param_3;
  if (param_3 < 1) {
LAB_97bb7d6c:
    bVar1 = false;
    if (iVar12 == 1) {
      iVar11 = 0;
      do {
        if ((local_50[iVar11] == 0) && (0 < *(int *)(this + iVar11 * 4 + 0x20))) {
          length = _strlen(UNK_a7b7bab8);
          length2 = _strlen((char *)(&_shaderString)[iVar11]);
          allocation = _malloc(length + length2 + 1);
          _sprintf(allocation,UNK_a7b7bab8,(&_shaderString)[iVar11]);
          pvVar13 = *(void **)(this + 0x84);
                    
override_jmp_97bb7df4_case_0:
          __ZN13TInfoSinkBase6appendEPKc(pvVar13,"ERROR: ");
          __ZN13TInfoSinkBase6appendEPKc(pvVar13,allocation);
          __ZN13TInfoSinkBase6appendEPKc(pvVar13,"\n");
          _free(allocation);
          iVar12 = 0;
        }
        else if (1 < local_50[iVar11]) {
          length = _strlen(UNK_a7b7babc);
          length2 = _strlen((char *)(&_shaderString)[iVar11]);
          allocation = _malloc(length + length2 + 9);
          _sprintf(allocation,UNK_a7b7babc,local_50[iVar11],(&_shaderString)[iVar11]);
          pvVar13 = *(void **)(this + 0x84);
                    
          goto override_jmp_97bb7df4_case_0;
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < 2);
      bVar1 = iVar12 == 1;
      if (bVar1) {
        pTVar8 = this;
        do {
          pvVar13 = _malloc(*(int *)(pTVar8 + 0x20) << 2);
          *(void **)(pTVar8 + 8) = pvVar13;
          pvVar13 = _malloc(*(int *)(pTVar8 + 0x20) << 2);
          *(void **)(pTVar8 + 0x10) = pvVar13;
          pvVar13 = _malloc(*(int *)(pTVar8 + 0x20) << 2);
          *(void **)(pTVar8 + 0x18) = pvVar13;
          pTVar8 = pTVar8 + 4;
        } while ((int)pTVar8 <= (int)(this + 4));
      }
    }
  }
  else {
    do {
      piVar3 = param_2[iVar10];
      if (piVar3 == (int *)0x0) {
        pTVar8 = (unsigned char *)&_linkIntErrorString;
        pvVar13 = *(void **)(this + 0x84);
        pcVar7 = DAT_a7b7bb64;
                    
override_jmp_97bb7c58_case_0:
        __ZN13TInfoSinkBase6appendEPKc(pvVar13,"INTERNAL ERROR: ");
        __ZN13TInfoSinkBase6appendEPKc(pvVar13,pcVar7);
        __ZN13TInfoSinkBase6appendEPKc(pvVar13,"\n");
        iVar12 = 0;
        r4In0 = r4Out1;
      }
      else {
        iVar4 = (**(code **)(*piVar3 + 8))(piVar3,r4In0,iVar11,in_r6,in_r7,in_r8,pTVar8,r10In0);
        if (iVar4 == 0) {
          pTVar8 = (unsigned char *)&_linkIntErrorString;
          pvVar13 = *(void **)(this + 0x84);
          pcVar7 = DAT_a7b7bb64;
                    
          goto override_jmp_97bb7c58_case_0;
        }
        iVar2 = 0;
        if (*(int *)(iVar4 + 8) != 0) {
          if (*(int *)(iVar4 + 8) != 1) {
            pvVar13 = *(void **)(this + 0x84);
            pcVar7 = _linkIntErrorString;
                    
            goto override_jmp_97bb7c58_case_0;
          }
          iVar2 = 1;
        }
        if (*(int *)(iVar4 + 0xac) != 0) {
          local_50[iVar2] = local_50[iVar2] + 1;
          *(int *)((int)local_40 + iVar2 * 4 + -8) = iVar10;
        }
        pTVar8 = this + iVar2 * 4;
        *(int *)(pTVar8 + 0x20) = *(int *)(pTVar8 + 0x20) + 1;
        r4In0 = r4Out0;
      }
      iVar10 = iVar10 + 1;
      if (param_3 <= iVar10) goto LAB_97bb7d6c;
    } while (iVar12 == 1);
    bVar1 = false;
  }
  iVar11 = 0;
  if ((0 < param_3) && (bVar1)) {
    do {
      piVar3 = *param_2;
      param_2 = param_2 + 1;
      if ((piVar3 != (int *)0x0) && (iVar10 = (**(code **)(*piVar3 + 8))(piVar3), iVar10 != 0)) {
        iVar4 = (uint)(*(int *)(iVar10 + 8) != 0) * 4;
        if (*(int *)((int)local_40 + iVar4 + -8) == iVar11) {
          **(int **)(this + iVar4 + 8) = iVar10;
          **(undefined4 **)(this + iVar4 + 0x10) = *(undefined4 *)(iVar10 + 0x68);
          **(undefined4 **)(this + iVar4 + 0x18) = *(undefined4 *)(iVar10 + 0x70);
        }
        else {
          *(int *)(*(int *)((int)local_40 + iVar4) * 4 + *(int *)(this + iVar4 + 8)) = iVar10;
          *(undefined4 *)(*(int *)((int)local_40 + iVar4) * 4 + *(int *)(this + iVar4 + 0x10)) =
               *(undefined4 *)(iVar10 + 0x68);
          iVar2 = *(int *)((int)local_40 + iVar4);
          iVar9 = *(int *)(this + iVar4 + 0x18);
          *(int *)((int)local_40 + iVar4) = iVar2 + 1;
          *(undefined4 *)(iVar2 * 4 + iVar9) = *(undefined4 *)(iVar10 + 0x70);
        }
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < param_3);
  }
  return iVar12;
}

/* TGenericLinker__BuildProcessingComponents @ 0x97bb8054 (200 bytes) */
int TGenericLinker__BuildProcessingComponents(this, unusedArg)
  void **this;
  int unusedArg;
{
  void *createFromStreamWithSymbolTableUpdateResult;
  void *createFunctionTableResult;
  unsigned char * symbolTableCopy;
  undefined4 success;
  int stage;
  void **stageSlots;
  
  success = 1;
  stage = 0;
  stageSlots = this;
  do {
    if (0 < (int)stageSlots[8]) {
      createFunctionTableResult = (void *)((int (*)())TGenericLinker__CreateFunctionTable)((unsigned char *)this,stage);
      stageSlots[0xe] = createFunctionTableResult;
      if (createFunctionTableResult == (void *)0x0) {
        success = 0;
      }
      else if (stageSlots[8] == (void *)0x1) {
        symbolTableCopy = (unsigned char *)
                 ParseSymbolTable__CopySymbolTable
                           (*(unsigned char **)(*(int *)stageSlots[2] + 0x68));
        stageSlots[10] = symbolTableCopy;
        createFromStreamWithSymbolTableUpdateResult = (void *)((int (*)())TGenericLinker__CreateFromStreamWithSymbolTableUpdate)((unsigned char *)this,
                                    *(unsigned char **)(*(int *)stageSlots[2] + 0x70),symbolTableCopy);
        stageSlots[0xc] = createFromStreamWithSymbolTableUpdateResult;
      }
      else if (1 < (int)stageSlots[8]) {
        success = ((int (*)())TGenericLinker__MergeCompilers)((unsigned char *)this,stage);
      }
    }
    stage = stage + 1;
    stageSlots = stageSlots + 1;
  } while (stage < 2);
  return success;
}

/* __ZN14TGenericLinkerC2Ei @ 0x97bb811c (4 bytes) */
int __ZN14TGenericLinkerC2Ei(this, debugOptions)
  void *this;
  int debugOptions;
{
  int atomicStore;
  undefined *emptyRep;
  int *emptyRepRefCount;
  undefined4 *allocation;
  void *bindingTable;
  int lastStageSlot;
  char reservation;
  byte cr0Reg;
  
  *(int *)this = DAT_a7b7bba0 + 8;
  *(int *)((int)this + 0x7c) = debugOptions;
  allocation = operator_new(0x10);
  emptyRep = PTR__S_empty_rep_storage_a7b7c0f0;
  emptyRepRefCount = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
      *emptyRepRefCount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  allocation[1] = 4;
  *allocation = emptyRep + 0xc;
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
      *emptyRepRefCount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  allocation[2] = emptyRep + 0xc;
  allocation[3] = 4;
  *(undefined4 *)((int)this + 0x80) = 1;
  *(undefined4 **)((int)this + 0x84) = allocation;
  *(int *)((int)this + 0x7c) = debugOptions;
  bindingTable = operator_new(0x48);
  __ZN12BindingTableC1Ej(bindingTable,0x80);
  *(void **)((int)this + 4) = bindingTable;
  lastStageSlot = (int)this + 4;
  *(undefined4 *)((int)this + 0x5c) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 0x58) = 0;
  do {
    *(undefined4 *)((int)this + 8) = 0;
    *(undefined4 *)((int)this + 0x10) = 0;
    *(undefined4 *)((int)this + 0x18) = 0;
    *(undefined4 *)((int)this + 0x20) = 0;
    *(undefined4 *)((int)this + 0x28) = 0;
    *(undefined4 *)((int)this + 0x30) = 0;
    *(undefined4 *)((int)this + 0x38) = 0;
    *(undefined4 *)((int)this + 0x40) = 0;
    *(undefined4 *)((int)this + 0x48) = 0;
    this = (void *)((int)this + 4);
  } while ((int)this <= lastStageSlot);
  return;
}

/* __ZN14TGenericLinkerC1Ei @ 0x97bb8120 (4 bytes) */
int __ZN14TGenericLinkerC1Ei(this, debugOptions)
  void *this;
  int debugOptions;
{
  int atomicStore;
  undefined *emptyRep;
  int *emptyRepRefCount;
  undefined4 *allocation;
  void *bindingTable;
  int lastStageSlot;
  char reservation;
  byte cr0Reg;
  
  *(int *)this = DAT_a7b7bba0 + 8;
  *(int *)((int)this + 0x7c) = debugOptions;
  allocation = operator_new(0x10);
  emptyRep = PTR__S_empty_rep_storage_a7b7c0f0;
  emptyRepRefCount = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
      *emptyRepRefCount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  allocation[1] = 4;
  *allocation = emptyRep + 0xc;
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
      *emptyRepRefCount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  allocation[2] = emptyRep + 0xc;
  allocation[3] = 4;
  *(undefined4 *)((int)this + 0x80) = 1;
  *(undefined4 **)((int)this + 0x84) = allocation;
  *(int *)((int)this + 0x7c) = debugOptions;
  bindingTable = operator_new(0x48);
  __ZN12BindingTableC1Ej(bindingTable,0x80);
  *(void **)((int)this + 4) = bindingTable;
  lastStageSlot = (int)this + 4;
  *(undefined4 *)((int)this + 0x5c) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 0x58) = 0;
  do {
    *(undefined4 *)((int)this + 8) = 0;
    *(undefined4 *)((int)this + 0x10) = 0;
    *(undefined4 *)((int)this + 0x18) = 0;
    *(undefined4 *)((int)this + 0x20) = 0;
    *(undefined4 *)((int)this + 0x28) = 0;
    *(undefined4 *)((int)this + 0x30) = 0;
    *(undefined4 *)((int)this + 0x38) = 0;
    *(undefined4 *)((int)this + 0x40) = 0;
    *(undefined4 *)((int)this + 0x48) = 0;
    this = (void *)((int)this + 4);
  } while ((int)this <= lastStageSlot);
  return;
}

/* __ZN14TGenericLinkerC4Ei @ 0x97bb8124 (268 bytes) */
int __ZN14TGenericLinkerC4Ei(this, debugOptions)
  void *this;
  int debugOptions;
{
  int atomicStore;
  undefined *emptyRep;
  int *emptyRepRefCount;
  undefined4 *allocation;
  void *bindingTable;
  int lastStageSlot;
  char reservation;
  byte cr0Reg;
  
  *(int *)this = DAT_a7b7bba0 + 8;
  *(int *)((int)this + 0x7c) = debugOptions;
  allocation = operator_new(0x10);
  emptyRep = PTR__S_empty_rep_storage_a7b7c0f0;
  emptyRepRefCount = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
      *emptyRepRefCount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  allocation[1] = 4;
  *allocation = emptyRep + 0xc;
  do {
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(*emptyRepRefCount + 1,0,emptyRepRefCount);
      *emptyRepRefCount = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  allocation[2] = emptyRep + 0xc;
  allocation[3] = 4;
  *(undefined4 *)((int)this + 0x80) = 1;
  *(undefined4 **)((int)this + 0x84) = allocation;
  *(int *)((int)this + 0x7c) = debugOptions;
  bindingTable = operator_new(0x48);
  __ZN12BindingTableC1Ej(bindingTable,0x80);
  *(void **)((int)this + 4) = bindingTable;
  lastStageSlot = (int)this + 4;
  *(undefined4 *)((int)this + 0x5c) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 0x58) = 0;
  do {
    *(undefined4 *)((int)this + 8) = 0;
    *(undefined4 *)((int)this + 0x10) = 0;
    *(undefined4 *)((int)this + 0x18) = 0;
    *(undefined4 *)((int)this + 0x20) = 0;
    *(undefined4 *)((int)this + 0x28) = 0;
    *(undefined4 *)((int)this + 0x30) = 0;
    *(undefined4 *)((int)this + 0x38) = 0;
    *(undefined4 *)((int)this + 0x40) = 0;
    *(undefined4 *)((int)this + 0x48) = 0;
    this = (void *)((int)this + 4);
  } while ((int)this <= lastStageSlot);
  return;
}

/* __ZN14TGenericLinkerD2Ev @ 0x97bb8230 (8 bytes) */
int __ZN14TGenericLinkerD2Ev(this)
  void *this;
{
  return ((int (*)())__ZN14TGenericLinkerD4Ev)(this,0);
}

/* __ZN14TGenericLinkerD1Ev @ 0x97bb8238 (8 bytes) */
int __ZN14TGenericLinkerD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN14TGenericLinkerD4Ev)(this,2);
}

/* __ZN14TGenericLinkerD0Ev @ 0x97bb8240 (8 bytes) */
int __ZN14TGenericLinkerD0Ev(this)
  void *this;
{
  return ((int (*)())__ZN14TGenericLinkerD4Ev)(this,3);
}

/* __ZN14TGenericLinkerD4Ev @ 0x97bb8248 (244 bytes) */
int __ZN14TGenericLinkerD4Ev(this, deleteFlag)
  void *this;
  uint deleteFlag;
{
  int firstData;
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  int secondData;
  int *infoSinkData;
  void *bindingTable;
  char reservation;
  byte cr0Reg;
  undefined1 allocScratch [28];
  
  *(int *)this = DAT_a7b7bba0 + 8;
  ((int (*)())TGenericLinker__reset)(this);
  infoSinkData = *(int **)((int)this + 0x84);
  if (infoSinkData != (int *)0x0) {
    secondData = infoSinkData[2];
    refCountPtr = (int *)(secondData + -4);
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(secondData + -0xc),allocScratch);
    }
    firstData = *infoSinkData;
    refCountPtr = (int *)(firstData + -4);
    do {
      oldRefCount = *refCountPtr;
      if (reservation != '\0') {
        atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
        *refCountPtr = atomicStore;
        cr0Reg = 2;
      }
    } while (!(bool)(cr0Reg >> 1 & 1));
    if (oldRefCount < 1) {
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(firstData + -0xc),allocScratch);
    }
    __ZdlPv(infoSinkData);
  }
  bindingTable = *(void **)((int)this + 4);
  if (bindingTable != (void *)0x0) {
    __ZN12BindingTableD1Ev(bindingTable);
    __ZdlPv(bindingTable);
  }
  *(undefined ***)this = &PTR___ZN13TShHandleBaseD1Ev_a7b7d700;
  if ((deleteFlag & 1) != 0) {
    __ZdlPv(this);
  }
  return;
}

/* TGenericLinker__getShaderLocalParamRemapTable @ 0x97bb833c (40 bytes) */
int TGenericLinker__getShaderLocalParamRemapTable(this, language)
  unsigned char * this;
  int language;
{
  if (language == 0) {
    return *(undefined4 *)(this + 0x40);
  }
  if (language != 1) {
    return 0;
  }
  return *(undefined4 *)(this + 0x44);
}

/* TGenericLinker__getNumShaderLocalParams @ 0x97bb8364 (40 bytes) */
int TGenericLinker__getNumShaderLocalParams(this, language)
  unsigned char * this;
  int language;
{
  if (language == 0) {
    return *(undefined4 *)(this + 0x48);
  }
  if (language != 1) {
    return 0;
  }
  return *(undefined4 *)(this + 0x4c);
}

/* TGenericLinker__attributeBindingRequest @ 0x97bb838c (196 bytes) */
int TGenericLinker__attributeBindingRequest(this, location, str)
  unsigned char * this;
  ulong location;
  char *str;
{
  int compareResult;
  int insertAttribRequestBindingResult;
  unsigned char * binding;
  
  compareResult = _memcmp(str,"gl_",3);
  if (compareResult != 0) {
    binding = operator_new(0x38);
    __ZN7BindingC1Ev(binding);
    Binding__SetName(binding,str);
    Binding__SetLocation(binding,location);
    Binding__SetClientRequest(binding,1);
    insertAttribRequestBindingResult = BindingTable__InsertAttribRequestBinding(*(unsigned char **)(this + 4),binding);
    if ((insertAttribRequestBindingResult == 0) && (binding != (unsigned char *)0x0)) {
      __ZN7BindingD1Ev(binding);
      __ZdlPv(binding);
      return;
    }
  }
  return;
}

/* TGenericLinker__getActiveUniform @ 0x97bb8450 (192 bytes) */
int TGenericLinker__getActiveUniform(this, index, bufSize, lengthOut, sizeOut, typeOut, str)
  unsigned char * this;
  ulong index;
  long bufSize;
  long *lengthOut;
  long *sizeOut;
  ulong *typeOut;
  char *str;
{
  long activeSize;
  unsigned char * binding;
  undefined4 found;
  long nameLength;
  ulong glType;
  
  binding = (unsigned char *)BindingTable__FindUniformBindingByIndex(*(unsigned char **)(this + 4),index)
  ;
  found = 0;
  if (binding != (unsigned char *)0x0) {
    if (bufSize == 0) {
      if (lengthOut != (long *)0x0) {
        *lengthOut = 0;
      }
    }
    else {
      _strncpy(str,*(char **)(binding + 8),bufSize);
      str[bufSize + -1] = '\0';
      if (lengthOut != (long *)0x0) {
        nameLength = _strlen(str);
        *lengthOut = nameLength;
      }
    }
    if (sizeOut != (long *)0x0) {
      activeSize = Binding__GetActualSize(binding);
      *sizeOut = activeSize;
    }
    if (typeOut != (ulong *)0x0) {
      glType = Binding__GetOpenGLType(binding);
      *typeOut = glType;
    }
    found = 1;
  }
  return found;
}

/* TGenericLinker__getUniformTypeInfo @ 0x97bb8510 (172 bytes) */
int TGenericLinker__getUniformTypeInfo(this, location, remainingSizeOut, typeOut, flagsOut)
  unsigned char * this;
  long location;
  long *remainingSizeOut;
  ulong *typeOut;
  uchar *flagsOut;
{
  undefined4 found;
  unsigned char * binding;
  int activeSize;
  int bindingLocation;
  uint elementSlots;
  ulong glType;
  
  binding = (unsigned char *)
            BindingTable__FindUniformBindingByLocation(*(unsigned char **)(this + 4),location);
  found = 0;
  if (binding != (unsigned char *)0x0) {
    if (remainingSizeOut != (long *)0x0) {
      activeSize = Binding__GetActualSize(binding);
      bindingLocation = Binding__GetLocation(binding);
      elementSlots = Binding__GetBindingBasicSize(binding);
      *remainingSizeOut = activeSize - (uint)(location - bindingLocation) / elementSlots;
    }
    if (typeOut != (ulong *)0x0) {
      glType = Binding__GetOpenGLType(binding);
      *typeOut = glType;
    }
    if (flagsOut != (uchar *)0x0) {
      *flagsOut = (uchar)binding[0x34];
      *(unsigned char *)(flagsOut + 1) = binding[0x35];
    }
    found = 1;
  }
  return found;
}

/* TGenericLinker__getActiveAttrib @ 0x97bb85bc (188 bytes) */
int TGenericLinker__getActiveAttrib(this, index, bufSize, lengthOut, sizeOut, typeOut, str)
  unsigned char * this;
  ulong index;
  long bufSize;
  long *lengthOut;
  long *sizeOut;
  ulong *typeOut;
  char *str;
{
  unsigned char * binding;
  undefined4 found;
  long activeSize;
  ulong glType;
  
  binding = (unsigned char *)BindingTable__GetAttribBindingByIndex(*(unsigned char **)(this + 4),index);
  found = 0;
  if (binding != (unsigned char *)0x0) {
    if (bufSize == 0) {
      if (lengthOut != (long *)0x0) {
        *lengthOut = 0;
      }
    }
    else {
      _strncpy(str,*(char **)(binding + 8),bufSize);
      str[bufSize + -1] = '\0';
      if (lengthOut != (long *)0x0) {
        *lengthOut = *(long *)(binding + 0x10);
      }
    }
    if (sizeOut != (long *)0x0) {
      activeSize = Binding__GetActualSize(binding);
      *sizeOut = activeSize;
    }
    if (typeOut != (ulong *)0x0) {
      glType = Binding__GetOpenGLType(binding);
      *typeOut = glType;
    }
    found = 1;
  }
  return found;
}

/* TGenericLinker__getPPStreamManager @ 0x97bb8678 (40 bytes) */
int TGenericLinker__getPPStreamManager(this, language)
  unsigned char * this;
  int language;
{
  if (language == 0) {
    return *(undefined4 *)(this + 0x30);
  }
  if (language != 1) {
    return 0;
  }
  return *(undefined4 *)(this + 0x34);
}

/* TGenericLinker__reset @ 0x97bb86a0 (412 bytes) */
int TGenericLinker__reset(this)
  unsigned char * this;
{
  void *stageObject;
  unsigned char * stageSlot;
  
  if (*(int *)(this + 0x50) != 0) {
    _free(*(int *)(this + 0x50));
  }
  *(undefined4 *)(this + 0x50) = 0;
  if (*(int *)(this + 0x5c) != 0) {
    _free(*(int *)(this + 0x5c));
  }
  *(undefined4 *)(this + 0x5c) = 0;
  if (*(int *)(this + 0x54) != 0) {
    _free(*(int *)(this + 0x54));
  }
  *(undefined4 *)(this + 0x54) = 0;
  if (*(int *)(this + 0x58) != 0) {
    _free(*(int *)(this + 0x58));
  }
  *(undefined4 *)(this + 0x58) = 0;
  stageSlot = this;
  do {
    if (*(int *)(stageSlot + 0x30) != 0) {
      _PPStreamFree(*(int *)(stageSlot + 0x30));
    }
    stageObject = *(void **)(stageSlot + 0x28);
    *(undefined4 *)(stageSlot + 0x30) = 0;
    if (stageObject != (void *)0x0) {
      __ZN16ParseSymbolTableD1Ev(stageObject);
      __ZdlPv(stageObject);
    }
    stageObject = *(void **)(stageSlot + 0x38);
    *(undefined4 *)(stageSlot + 0x28) = 0;
    if (stageObject != (void *)0x0) {
      __ZN13FunctionTableD1Ev(stageObject);
      __ZdlPv(stageObject);
    }
    *(undefined4 *)(stageSlot + 0x38) = 0;
    stageSlot = stageSlot + 4;
  } while ((int)stageSlot <= (int)(this + 4));
  stageSlot = this;
  do {
    if (*(int *)(stageSlot + 8) != 0) {
      _free(*(int *)(stageSlot + 8));
    }
    *(undefined4 *)(stageSlot + 8) = 0;
    if (*(int *)(stageSlot + 0x10) != 0) {
      _free(*(int *)(stageSlot + 0x10));
    }
    *(undefined4 *)(stageSlot + 0x10) = 0;
    if (*(int *)(stageSlot + 0x18) != 0) {
      _free(*(int *)(stageSlot + 0x18));
    }
    *(undefined4 *)(stageSlot + 0x20) = 0;
    *(undefined4 *)(stageSlot + 0x18) = 0;
    stageSlot = stageSlot + 4;
  } while ((int)stageSlot <= (int)(this + 4));
  stageSlot = this;
  do {
    if (*(int *)(stageSlot + 0x40) != 0) {
      _free(*(int *)(stageSlot + 0x40));
    }
    *(undefined4 *)(stageSlot + 0x40) = 0;
    *(undefined4 *)(stageSlot + 0x48) = 0;
    stageSlot = stageSlot + 4;
  } while ((int)stageSlot <= (int)(this + 4));
  BindingTable__ClearInternalBindings(*(unsigned char **)(this + 4));
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x74) = 0xffffffff;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  return;
}

/* TGenericLinker__link @ 0x97bb883c (372 bytes) */
int TGenericLinker__link(this, shaderObjects, numShaders)
  unsigned char * this;
  void **shaderObjects;
  int numShaders;
{
  unsigned char *streamSlot;
  int ppStream;
  int formatLength;
  int shaderNameLength;
  int numActiveVertexSamplers3;
  int numActiveFragmentSamplers3;
  int buildUniformRemapTablesResult;
  int remapVertexAttributesResult;
  int collectUniformBindingsResult;
  int collectAttributeBindingsResult;
  int collectClientAttributeBindingsResult;
  int allocateTextureUnitsForVaryingsResult;
  int loopIndex;
  undefined4 numActiveFragmentSamplers2;
  undefined4 numActiveVertexSamplers2;
  undefined4 sizeActiveFragmentUniforms2;
  undefined4 sizeActiveVertexUniforms2;
  int numActiveFragmentSamplers;
  int numActiveVertexSamplers;
  int sizeActiveFragmentUniforms;
  int sizeActiveVertexUniforms;
  int sizeActiveAttributes;
  bool attribsRemapped;
  int stagesLeft;
  int branchResolveResult;
  char *allocation;
  undefined4 sizeActiveAttributes2;
  int linkStatus;
  unsigned char *stageSlot;
  void *infoSink;
  
  linkStatus = 1;
  if (0 < numShaders) {
    linkStatus = ((int (*)())TGenericLinker__BuildSymbolTableList)(this,shaderObjects,numShaders);
    if ((linkStatus == 1) && (linkStatus = ((int (*)())TGenericLinker__BuildProcessingComponents)((void **)this,(int)shaderObjects), linkStatus == 1))
    {
      ((int (*)())TGenericLinker__RemoveExtraVertexOutputs)(this);
      ((int (*)())TGenericLinker__FixOutputReads)(this);
      allocateTextureUnitsForVaryingsResult = ((int (*)())TGenericLinker__AllocateTextureUnitsForVaryings)(this);
      if (allocateTextureUnitsForVaryingsResult == 0) {
        linkStatus = 0;
      }
      if (1 < *(int *)(this + 0x80)) {
        ((int (*)())TGenericLinker__OptimizeFunctionIO)(this);
        ((int (*)())TGenericLinker__RemoveUnreachableFunctions)(this);
        if (2 < *(int *)(this + 0x80)) {
          ((int (*)())TGenericLinker__RemoveUnusedRegisters)(this);
        }
      }
      stageSlot = this;
      do {
        if (*(int *)(stageSlot + 0x30) != 0) {
          ((int (*)())TGenericLinker__CoalesceCommonUniforms)(this);
          _PPStreamSortParamConstants(*(undefined4 *)(stageSlot + 0x30));
          _PPStreamPackIndices(*(undefined4 *)(stageSlot + 0x30));
        }
        stageSlot = stageSlot + 4;
      } while ((int)stageSlot <= (int)(this + 4));
      if (allocateTextureUnitsForVaryingsResult != 0) {
        loopIndex = 0;
        do {
          if ((*(int *)(this + loopIndex * 4 + 0x30) != 0) &&
             (branchResolveResult = _PPStreamResolveBranches(*(int *)(this + loopIndex * 4 + 0x30)), branchResolveResult != 0)) {
            formatLength = _strlen(DAT_a7b7bb1c);
            shaderNameLength = _strlen((&_shaderString)[loopIndex]);
            allocation = (char *)_malloc(formatLength + shaderNameLength + 1);
            _sprintf(allocation,DAT_a7b7bb1c,(&_shaderString)[loopIndex]);
            infoSink = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(infoSink,allocation);
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
            _free(allocation);
            linkStatus = 0;
          }
          loopIndex = loopIndex + 1;
        } while (loopIndex < 2);
        if (linkStatus == 1) {
          collectClientAttributeBindingsResult = ((int (*)())TGenericLinker__CollectClientAttributeBindings)(this);
          if (collectClientAttributeBindingsResult == 0) {
            linkStatus = 0;
          }
          collectAttributeBindingsResult = ((int (*)())TGenericLinker__CollectAttributeBindings)(this);
          if (collectAttributeBindingsResult == 0) {
            linkStatus = 0;
          }
          collectUniformBindingsResult = ((int (*)())TGenericLinker__CollectUniformBindings)(this);
          if (collectUniformBindingsResult == 0) {
            linkStatus = 0;
          }
          sizeActiveAttributes = BindingTable__GetSizeActiveAttributes(*(unsigned char **)(this + 4));
          if (0x10 < sizeActiveAttributes) {
            formatLength = _strlen(UNK_a7b7bae8);
            allocation = (char *)_malloc(formatLength + 0x11);
            sizeActiveAttributes2 = BindingTable__GetSizeActiveAttributes(*(unsigned char **)(this + 4));
            _sprintf(allocation,UNK_a7b7bae8,0x10,sizeActiveAttributes2);
            infoSink = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(infoSink,allocation);
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
            _free(allocation);
            linkStatus = 0;
          }
          sizeActiveVertexUniforms = BindingTable__GetSizeActiveVertexUniforms(*(unsigned char **)(this + 4));
          if (0x200 < sizeActiveVertexUniforms) {
            formatLength = _strlen(DAT_a7b7baec);
            allocation = (char *)_malloc(formatLength + 0x11);
            sizeActiveVertexUniforms2 = BindingTable__GetSizeActiveVertexUniforms(*(unsigned char **)(this + 4));
            _sprintf(allocation,DAT_a7b7baec,0x200,sizeActiveVertexUniforms2);
            infoSink = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(infoSink,allocation);
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
            _free(allocation);
            linkStatus = 0;
          }
          sizeActiveFragmentUniforms = BindingTable__GetSizeActiveFragmentUniforms(*(unsigned char **)(this + 4));
          if (0x200 < sizeActiveFragmentUniforms) {
            formatLength = _strlen(DAT_a7b7baf0);
            allocation = (char *)_malloc(formatLength + 0x11);
            sizeActiveFragmentUniforms2 = BindingTable__GetSizeActiveFragmentUniforms(*(unsigned char **)(this + 4));
            _sprintf(allocation,DAT_a7b7baf0,0x200,sizeActiveFragmentUniforms2);
            infoSink = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(infoSink,allocation);
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
            _free(allocation);
            linkStatus = 0;
          }
          numActiveVertexSamplers = BindingTable__GetNumActiveVertexSamplers(*(unsigned char **)(this + 4));
          if (0 < numActiveVertexSamplers) {
            formatLength = _strlen(UNK_a7b7baf4);
            allocation = (char *)_malloc(formatLength + 0x11);
            numActiveVertexSamplers2 = BindingTable__GetNumActiveVertexSamplers(*(unsigned char **)(this + 4));
            _sprintf(allocation,UNK_a7b7baf4,0,numActiveVertexSamplers2);
            infoSink = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(infoSink,allocation);
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
            _free(allocation);
            linkStatus = 0;
          }
          numActiveFragmentSamplers = BindingTable__GetNumActiveFragmentSamplers(*(unsigned char **)(this + 4));
          if (0x10 < numActiveFragmentSamplers) {
            formatLength = _strlen(UNK_a7b7baf8);
            allocation = (char *)_malloc(formatLength + 0x11);
            numActiveFragmentSamplers2 = BindingTable__GetNumActiveFragmentSamplers(*(unsigned char **)(this + 4));
            _sprintf(allocation,UNK_a7b7baf8,0x10,numActiveFragmentSamplers2);
            infoSink = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(infoSink,allocation);
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
            _free(allocation);
            linkStatus = 0;
          }
          numActiveVertexSamplers = BindingTable__GetNumActiveVertexSamplers(*(unsigned char **)(this + 4));
          numActiveFragmentSamplers3 = BindingTable__GetNumActiveFragmentSamplers(*(unsigned char **)(this + 4));
          if (0x10 < numActiveVertexSamplers + numActiveFragmentSamplers3) {
            formatLength = _strlen(UNK_a7b7bafc);
            allocation = (char *)_malloc(formatLength + 0x11);
            numActiveVertexSamplers3 = BindingTable__GetNumActiveVertexSamplers(*(unsigned char **)(this + 4));
            numActiveFragmentSamplers = BindingTable__GetNumActiveFragmentSamplers(*(unsigned char **)(this + 4));
            _sprintf(allocation,UNK_a7b7bafc,0x10,numActiveVertexSamplers3 + numActiveFragmentSamplers);
            infoSink = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(infoSink,allocation);
            __ZN13TInfoSinkBase6appendEPKc(infoSink,"\n");
            _free(allocation);
            linkStatus = 0;
          }
          if (linkStatus == 1) {
            remapVertexAttributesResult = ((int (*)())TGenericLinker__RemapVertexAttributes)(this);
            if (remapVertexAttributesResult == 0) {
              linkStatus = 0;
            }
            attribsRemapped = linkStatus == 1;
            buildUniformRemapTablesResult = ((int (*)())TGenericLinker__BuildUniformRemapTables)(this);
            if (buildUniformRemapTablesResult == 0) {
              linkStatus = 0;
            }
            if ((buildUniformRemapTablesResult != 0 && attribsRemapped) && (3 < *(int *)(this + 0x80))) {
              streamSlot = this + 0x30;
              stagesLeft = 1;
              do {
                ppStream = *(int *)streamSlot;
                streamSlot = streamSlot + 4;
                if (ppStream != 0) {
                  _glpPPShaderLinearizeStreamMgr(ppStream,0xfd);
                }
                stagesLeft = stagesLeft + -1;
              } while (-1 < stagesLeft);
            }
          }
        }
      }
    }
    if (linkStatus == 0) {
      reset(this);
    }
  }
  return linkStatus;
}

/* TGenericLinker__getStatsString @ 0x97bb9098 (104 bytes) */
int TGenericLinker__getStatsString(this)
  unsigned char * this;
{
  int length;
  int statsString;
  undefined4 allocation;
  
  statsString = *(int *)(this + 0x50);
  if (statsString == 0) {
    length = _strlen(DAT_a7b7bb5c);
    allocation = _malloc(length * 4 + 4);
    *(undefined4 *)(this + 0x50) = allocation;
    _strcpy(allocation,DAT_a7b7bb5c);
    statsString = *(int *)(this + 0x50);
  }
  return statsString;
}

/* TGenericLinker__getPPStreamString @ 0x97bb9100 (604 bytes) */
int TGenericLinker__getPPStreamString(this)
  unsigned char * this;
{
  bool noFragmentText;
  int totalLength;
  undefined4 allocation;
  int length;
  char *allocation2;
  void *vertexText;
  void *fragmentText;
  int streamSize [5];
  
  vertexText = (void *)0x0;
  fragmentText = (void *)0x0;
  if (*(int *)(this + 0x54) != 0) {
    _free(*(int *)(this + 0x54));
  }
  *(undefined4 *)(this + 0x54) = 0;
  totalLength = _strlen(DAT_a7b7bb4c);
  if (*(int *)(this + 0x30) == 0) {
    length = _strlen(DAT_a7b7bb58);
    vertexText = (void *)_malloc(length + 1);
    _strcpy(vertexText,DAT_a7b7bb58);
  }
  else {
    _PPStreamGetStream(*(int *)(this + 0x30),0,streamSize);
    if (streamSize[0] != 0) {
      allocation = _malloc(streamSize[0] * 8 + 0xfU & 0xfffffff0);
      _PPStreamGetStream(*(undefined4 *)(this + 0x30),allocation,streamSize);
      vertexText = _glpPPDisassemble(allocation);
      _free(allocation);
    }
  }
  if (vertexText != (void *)0x0) {
    length = _strlen(vertexText);
    totalLength = totalLength + length;
  }
  length = _strlen(DAT_a7b7bb48);
  totalLength = totalLength + length;
  if (*(int *)(this + 0x34) == 0) {
    length = _strlen(DAT_a7b7bb58);
    fragmentText = (void *)_malloc(length + 1);
    _strcpy(fragmentText,DAT_a7b7bb58);
  }
  else {
    _PPStreamGetStream(*(int *)(this + 0x34),0,streamSize);
    if (streamSize[0] != 0) {
      allocation = _malloc(streamSize[0] * 8 + 0xfU & 0xfffffff0);
      _PPStreamGetStream(*(undefined4 *)(this + 0x34),allocation,streamSize);
      fragmentText = _glpPPDisassemble(allocation);
      _free(allocation);
    }
  }
  noFragmentText = fragmentText == (void *)0x0;
  if (!noFragmentText) {
    length = _strlen(fragmentText);
    totalLength = totalLength + length;
  }
  allocation2 = (char *)_malloc(totalLength + 8);
  *(char **)(this + 0x54) = allocation2;
  _sprintf(allocation2,"%s\n",DAT_a7b7bb4c);
  if (vertexText == (void *)0x0) {
    _sprintf(*(char **)(this + 0x54),"%s\n\n%s\n",*(char **)(this + 0x54),DAT_a7b7bb48);
  }
  else {
    _sprintf(*(char **)(this + 0x54),"%s%s\n\n%s\n",*(char **)(this + 0x54),vertexText,DAT_a7b7bb48);
  }
  if (noFragmentText) {
    _sprintf(*(char **)(this + 0x54),"%s\n",*(char **)(this + 0x54));
  }
  else {
    _sprintf(*(char **)(this + 0x54),"%s%s\n",*(char **)(this + 0x54),fragmentText);
  }
  if (vertexText != (void *)0x0) {
    _free(vertexText);
  }
  if (!noFragmentText) {
    _free(fragmentText);
  }
  return *(undefined4 *)(this + 0x54);
}

/* TGenericLinker__getShaderToProgramString @ 0x97bb935c (768 bytes) */
int TGenericLinker__getShaderToProgramString(this)
  unsigned char * this;
{
  int length3;
  int length2;
  int length;
  bool noFragmentText;
  int totalLength;
  undefined4 allocation;
  int glpPPShaderLinearizeResult;
  char *allocation2;
  int vertexText;
  int fragmentText;
  int streamSize [4];
  
  vertexText = 0;
  fragmentText = 0;
  if (*(int *)(this + 0x58) != 0) {
    _free(*(int *)(this + 0x58));
  }
  *(undefined4 *)(this + 0x58) = 0;
  totalLength = _strlen(DAT_a7b7bb54);
  if (*(int *)(this + 0x30) == 0) {
    length2 = _strlen(DAT_a7b7bb58);
    vertexText = _malloc(length2 + 1);
    _strcpy(vertexText,DAT_a7b7bb58);
  }
  else {
    _PPStreamGetStream(*(int *)(this + 0x30),0,streamSize);
    if (streamSize[0] != 0) {
      allocation = _malloc(streamSize[0] * 8 + 0xfU & 0xfffffff0);
      _PPStreamGetStream(*(undefined4 *)(this + 0x30),allocation,streamSize);
      if (*(int *)(this + 0x80) < 4) {
        vertexText = _glpPPShaderToProgramString(allocation,0,0);
      }
      else {
        glpPPShaderLinearizeResult = _glpPPShaderLinearize(allocation,0xff);
        vertexText = 0;
        if (glpPPShaderLinearizeResult != 0) {
          vertexText = _glpPPShaderToProgramString(glpPPShaderLinearizeResult,0,0);
          _glpFreePPShaderLinearize(glpPPShaderLinearizeResult);
        }
      }
      _free(allocation);
    }
  }
  if (vertexText != 0) {
    length = _strlen(vertexText);
    totalLength = totalLength + length;
  }
  length = _strlen(DAT_a7b7bb50);
  totalLength = totalLength + length;
  if (*(int *)(this + 0x34) == 0) {
    length3 = _strlen(DAT_a7b7bb58);
    fragmentText = _malloc(length3 + 1);
    _strcpy(fragmentText,DAT_a7b7bb58);
  }
  else {
    _PPStreamGetStream(*(int *)(this + 0x34),0,streamSize);
    if (streamSize[0] != 0) {
      allocation = _malloc(streamSize[0] * 8 + 0xfU & 0xfffffff0);
      _PPStreamGetStream(*(undefined4 *)(this + 0x34),allocation,streamSize);
      if (*(int *)(this + 0x80) < 4) {
        fragmentText = _glpPPShaderToProgramString(allocation,0,0);
      }
      else {
        glpPPShaderLinearizeResult = _glpPPShaderLinearize(allocation,0xff);
        fragmentText = 0;
        if (glpPPShaderLinearizeResult != 0) {
          fragmentText = _glpPPShaderToProgramString(glpPPShaderLinearizeResult,0,0);
          _glpFreePPShaderLinearize(glpPPShaderLinearizeResult);
        }
      }
      _free(allocation);
    }
  }
  noFragmentText = fragmentText == 0;
  if (!noFragmentText) {
    length = _strlen(fragmentText);
    totalLength = totalLength + length;
  }
  allocation2 = (char *)_malloc(totalLength + 8);
  *(char **)(this + 0x58) = allocation2;
  _sprintf(allocation2,"%s\n",DAT_a7b7bb54);
  if (vertexText == 0) {
    _sprintf(*(char **)(this + 0x58),"%s\n\n",*(char **)(this + 0x58));
  }
  else {
    _sprintf(*(char **)(this + 0x58),"%s%s\n\n",*(char **)(this + 0x58),vertexText);
  }
  _sprintf(*(char **)(this + 0x58),"%s%s\n",*(char **)(this + 0x58),DAT_a7b7bb50);
  if (noFragmentText) {
    _sprintf(*(char **)(this + 0x58),"%s\n",*(char **)(this + 0x58));
  }
  else {
    _sprintf(*(char **)(this + 0x58),"%s%s\n",*(char **)(this + 0x58),fragmentText);
  }
  if (vertexText != 0) {
    _free(vertexText);
  }
  if (!noFragmentText) {
    _free(fragmentText);
  }
  return *(undefined4 *)(this + 0x58);
}

/* TGenericLinker__getTableString @ 0x97bb965c (68 bytes) */
int TGenericLinker__getTableString(this)
  unsigned char * this;
{
  int tableString;
  
  tableString = *(int *)(this + 0x5c);
  if (tableString == 0) {
    tableString = ((int (*)())TGenericLinker__GetFullTableString)(this);
    *(int *)(this + 0x5c) = tableString;
  }
  return tableString;
}

/* GetGLStringForType @ 0x97bb96a0 (168 bytes) */
int GetGLStringForType(glType)
  int glType;
{
  if (glType == 0x1404) {
    return _glTypeNameStrings;
  }
  if (glType == 0x1406) {
    return DAT_a7b7bc28;
  }
  if ((glType + 0x74b0U & 0xffff) < 0x15) {
    return *(undefined4 *)(glType * 4 + -0x584a7114);
  }
  if (glType == 0x7ffe) {
    return DAT_a7b7bc80;
  }
  if (glType == 0x7fff) {
    return DAT_a7b7bc84;
  }
  return DAT_a7b7bc88;
}

/* GetShaderStringForType @ 0x97bb9748 (168 bytes) */
int GetShaderStringForType(glType)
  int glType;
{
  if (glType == 0x1404) {
    return _shaderTypeNameStrings;
  }
  if (glType == 0x1406) {
    return DAT_a7b7bc90;
  }
  if ((glType + 0x74b0U & 0xffff) < 0x15) {
    return *(undefined4 *)(glType * 4 + -0x584a70ac);
  }
  if (glType == 0x7ffe) {
    return DAT_a7b7bce8;
  }
  if (glType == 0x7fff) {
    return DAT_a7b7bcec;
  }
  return DAT_a7b7bcf0;
}

/* GetVec4sForType @ 0x97bb97f0 (136 bytes) */
int GetVec4sForType(glType)
  int glType;
{
  if (glType == 0x8b5a) {
    return 2;
  }
  if (glType < 0x8b5b) {
    if (glType != 0x1406) {
      if (glType < 0x1407) {
        if (glType != 0x1404) {
          return 0;
        }
      }
      else if (glType < 0x8b50) {
        return 0;
      }
    }
  }
  else {
    if (glType == 0x8b5c) {
      return 4;
    }
    if (glType < 0x8b5c) {
      return 3;
    }
    if (0x8b64 < glType) {
      return 0;
    }
  }
  return 1;
}

/* GetPPStreamTypeForGLType @ 0x97bb9878 (164 bytes) */
int GetPPStreamTypeForGLType(glType)
  int glType;
{
  if (glType < 0x8b56) {
    if (glType < 0x8b53) {
      if (glType == 0x1406) {
        return 1;
      }
      if (glType < 0x1407) {
        if (glType == 0x1404) {
          return 3;
        }
      }
      else if (0x8b4f < glType) {
        return 1;
      }
      return 0;
    }
  }
  else {
    if (glType < 0x8b5d) {
      if (0x8b59 < glType) {
        return 1;
      }
      return 4;
    }
    if (0x8b64 < glType) {
      return 0;
    }
  }
  return 3;
}

/* GetScalerWidthForType @ 0x97bb991c (260 bytes) */
int GetScalerWidthForType(glType)
  int glType;
{
  if (glType == 0x8b56) {
    return 1;
  }
  if (0x8b56 < glType) {
    if (glType == 0x8b5a) {
      return 2;
    }
    if (glType < 0x8b5b) {
      if (glType != 0x8b58) {
        if (glType < 0x8b59) {
          return 2;
        }
        return 4;
      }
    }
    else {
      if (glType == 0x8b5c) {
        return 4;
      }
      if (0x8b5b < glType) {
        if (glType < 0x8b65) {
          return 1;
        }
        return 0;
      }
    }
    return 3;
  }
  if (glType == 0x8b51) {
    return 3;
  }
  if (glType < 0x8b52) {
    if (glType == 0x1406) {
      return 1;
    }
    if (glType < 0x1407) {
      if (glType == 0x1404) {
        return 1;
      }
    }
    else if (glType == 0x8b50) {
      return 2;
    }
    return 0;
  }
  if (glType == 0x8b53) {
    return 2;
  }
  if (glType < 0x8b53) {
    return 4;
  }
  if (glType == 0x8b54) {
    return 3;
  }
  if (glType == 0x8b55) {
    return 4;
  }
  return 0;
}

/* getOpenGLTypeFromTType @ 0x97bb9a20 (676 bytes) */
int getOpenGLTypeFromTType(type)
  unsigned char * type;
{
  int nominalSize;
  int isMatrix;
  int isArray;
  uint basicType;
  undefined4 r4In0;
  undefined4 r5Fwd;
  undefined4 r6Fwd;
  undefined4 r7Fwd;
  undefined4 r8Fwd;
  undefined4 glType;
  
  glType = 0x1400;
  isArray = (**(code **)(*(int *)type + 0x38))(type);
  if (isArray == 0) {
    basicType = (**(code **)(*(int *)type + 0x20))(type);
    if (basicType < 0x10) {
      switch(basicType) {
      case 1:
        isMatrix = (**(code **)(*(int *)type + 0x34))(type,r4In0,r5Fwd,r6Fwd,r7Fwd,r8Fwd,basicType * 4);
        if (isMatrix == 0) {
          nominalSize = (**(code **)(*(int *)type + 0x2c))(type);
          if (nominalSize == 2) {
            glType = 0x8b50;
          }
          else if (nominalSize < 3) {
            if (nominalSize == 1) {
              glType = 0x1406;
            }
          }
          else if (nominalSize == 3) {
            glType = 0x8b51;
          }
          else if (nominalSize == 4) {
            glType = 0x8b52;
          }
        }
        else {
          nominalSize = (**(code **)(*(int *)type + 0x2c))(type);
          if (nominalSize == 3) {
            glType = 0x8b5b;
          }
          else if (nominalSize < 4) {
            if (nominalSize == 2) {
              glType = 0x8b5a;
            }
          }
          else if (nominalSize == 4) {
            glType = 0x8b5c;
          }
        }
        break;
      case 2:
        nominalSize = (**(code **)(*(int *)type + 0x2c))(type);
        if (nominalSize == 2) {
          glType = 0x8b53;
        }
        else if (nominalSize < 3) {
          if (nominalSize == 1) {
            glType = 0x1404;
          }
        }
        else if (nominalSize == 3) {
          glType = 0x8b54;
        }
        else if (nominalSize == 4) {
          glType = 0x8b55;
        }
        break;
      case 3:
        nominalSize = (**(code **)(*(int *)type + 0x2c))(type);
        if (nominalSize == 2) {
          glType = 0x8b57;
        }
        else if (nominalSize < 3) {
          if (nominalSize == 1) {
            glType = 0x8b56;
          }
        }
        else if (nominalSize == 3) {
          glType = 0x8b58;
        }
        else if (nominalSize == 4) {
          glType = 0x8b59;
        }
        break;
      case 5:
        glType = 0x8b5d;
        break;
      case 6:
        glType = 0x8b5e;
        break;
      case 7:
        glType = 0x8b5f;
        break;
      case 8:
        glType = 0x8b60;
        break;
      case 9:
        glType = 0x8b61;
        break;
      case 10:
        glType = 0x8b62;
        break;
      case 0xb:
        glType = 0x8b63;
        break;
      case 0xc:
        glType = 0x8b64;
        break;
      case 0xe:
        glType = 0x7ffe;
      }
    }
  }
  else {
    glType = 0x7fff;
  }
  return glType;
}

/* __ZN20AddressTempAllocatorC2Ev @ 0x97bb9d04 (4 bytes) */
int __ZN20AddressTempAllocatorC2Ev(this)
  void *this;
{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* __ZN20AddressTempAllocatorC1Ev @ 0x97bb9d08 (4 bytes) */
int __ZN20AddressTempAllocatorC1Ev(this)
  void *this;
{
  return ((int (*)())__ZN20AddressTempAllocatorC4Ev)(this);
}

/* __ZN20AddressTempAllocatorC4Ev @ 0x97bb9d0c (16 bytes) */
int __ZN20AddressTempAllocatorC4Ev(this)
  void *this;
{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* __ZN20AddressTempAllocatorD2Ev @ 0x97bb9d1c (8 bytes) */
int __ZN20AddressTempAllocatorD2Ev(this)
  void *this;
{
  return ((int (*)())__ZN20AddressTempAllocatorD4Ev)(this);
}

/* __ZN20AddressTempAllocatorD1Ev @ 0x97bb9d24 (8 bytes) */
int __ZN20AddressTempAllocatorD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN20AddressTempAllocatorD4Ev)(this);
}

/* __ZN20AddressTempAllocatorD4Ev @ 0x97bb9d2c (16 bytes) */
int __ZN20AddressTempAllocatorD4Ev(this)
  void *this;
{
  if (*(int *)this == 0) {
    return;
  }
  return _free(*(int *)this);
}

/* AddressTempAllocator__getTemporary @ 0x97bb9d3c (316 bytes) */
int AddressTempAllocator__getTemporary(this)
  unsigned char * this;
{
  int oldCapacity;
  int copyOffset;
  int slotValue;
  uint capacity;
  int table;
  int *slotCursor;
  int oldTable;
  int copyIdx;
  int slotOffset;
  uint slot;
  int copyLeft;
  
  slot = 0;
  capacity = *(uint *)(this + 4);
  slotOffset = 0;
  if (capacity != 0) {
    slotCursor = *(int **)this;
    slotValue = *slotCursor;
    while (slotValue != 0) {
      slot = slot + 1;
      slotOffset = slot * 4;
      if (capacity <= slot) break;
      slotCursor = slotCursor + 1;
      slotValue = *slotCursor;
    }
  }
  if (capacity <= slot) {
    table = _malloc(capacity * 4 + 0x40);
    oldCapacity = *(int *)(this + 4);
    copyIdx = 0;
    if (oldCapacity != 0) {
      oldTable = *(int *)this;
      copyLeft = oldCapacity;
      do {
        copyOffset = copyIdx * 4;
        copyIdx = copyIdx + 1;
        *(undefined4 *)(copyOffset + table) = *(undefined4 *)(copyOffset + oldTable);
        copyLeft = copyLeft + -1;
      } while (copyLeft != 0);
    }
    _memset(oldCapacity * 4 + table,0,0x40);
    if (*(int *)this != 0) {
      _free(*(int *)this);
    }
    *(int *)this = table;
    capacity = *(int *)(this + 4) + 0x10;
    *(uint *)(this + 4) = capacity;
    if (slot < capacity) {
      if (*(int *)(slotOffset + table) != 0) {
        slotCursor = (int *)(slot * 4 + table);
        do {
          slot = slot + 1;
          slotOffset = slot * 4;
          if (capacity <= slot) break;
          slotCursor = slotCursor + 1;
        } while (*slotCursor != 0);
      }
      goto LAB_97bb9e58;
    }
  }
  table = *(int *)this;
LAB_97bb9e58:
  *(undefined4 *)(slotOffset + table) = 1;
  return slot;
}

/* AddressTempAllocator__releaseTemporary @ 0x97bb9e78 (20 bytes) */
int AddressTempAllocator__releaseTemporary(this, tempIndex)
  unsigned char * this;
  uint tempIndex;
{
  *(undefined4 *)(tempIndex * 4 + *(int *)this) = 0;
  return;
}

/* __ZN18TemporaryAllocatorC2Ev @ 0x97bb9e8c (4 bytes) */
int __ZN18TemporaryAllocatorC2Ev(this)
  void *this;
{
  int slotsLeft;
  
  slotsLeft = 0x19;
  do {
    *(undefined4 *)this = 0;
    *(undefined4 *)((int)this + 100) = 0;
    this = (void *)((int)this + 4);
    slotsLeft = slotsLeft + -1;
  } while (slotsLeft != 0);
  return;
}

