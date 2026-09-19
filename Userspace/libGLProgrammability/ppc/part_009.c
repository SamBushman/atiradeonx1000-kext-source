#include "decls.h"

/* TGenericLinker__MergeCompilers @ 0x97bb21dc (3076 bytes) */
int TGenericLinker__MergeCompilers(this, param_1)
  unsigned char * this;
  int param_1;
{
  char cVar1;
  byte bVar2;
  int iVar3;
  undefined *puVar4;
  undefined *puVar5;
  undefined *puVar6;
  undefined *puVar7;
  undefined *puVar8;
  undefined *puVar9;
  unsigned char * pTVar10;
  unsigned char * pTVar11;
  unsigned char * pTVar12;
  int iVar13;
  int iVar14;
  void *pvVar15;
  void *pvVar16;
  undefined4 uVar17;
  unsigned char * pPVar18;
  int iVar19;
  size_t sVar20;
  int iVar21;
  char *pcVar22;
  undefined4 *puVar23;
  size_t sVar24;
  size_t sVar25;
  unsigned char * p_Var26;
  bool bVar27;
  uint uVar28;
  byte *pbVar29;
  bool bVar30;
  int iVar31;
  undefined4 *puVar32;
  int iVar33;
  char *pcVar34;
  unsigned char * pTVar35;
  unsigned char * p_Var36;
  char local_70 [16];
  int local_60;
  unsigned char * local_5c;
  unsigned char * local_58;
  unsigned char * local_54;
  
  puVar9 = PTR_s_gl__IfEnd__a7b7d6dc;
  puVar8 = PTR_s_gl__IfElse_a7b7d6d8;
  puVar7 = PTR_s_gl__WhileEndIf__a7b7d6d4;
  puVar6 = PTR_s_gl__WhileStart__a7b7d6d0;
  puVar5 = PTR_s_gl__WhileEnd__a7b7d6cc;
  puVar4 = PTR_s_gl__WhileBody__a7b7d6c8;
  iVar3 = param_1 * 4;
  pvVar15 = _malloc(*(int *)(this + iVar3 + 0x20) << 2);
  pvVar16 = _malloc(*(int *)(this + iVar3 + 0x20) << 2);
  iVar13 = *(int *)(this + iVar3 + 0x20);
  local_60 = 0;
  if (10000 < iVar13) {
    pcVar34 = *(char **)(this + 0x84);
                    
    TInfoSinkBase__append(pcVar34);
    TInfoSinkBase__append(pcVar34);
    TInfoSinkBase__append(pcVar34);
  }
  bVar30 = 10000 >= iVar13;
  if (bVar30) {
    uVar17 = _PPStreamCreate();
    *(undefined4 *)(this + iVar3 + 0x30) = uVar17;
    pPVar18 = operator_new(0x54);
    ParseSymbolTable__ParseSymbolTable(pPVar18,0x80);
    *(unsigned char **)(this + iVar3 + 0x28) = pPVar18;
    *(undefined4 *)(pPVar18 + 0xc) = *(undefined4 *)(this + iVar3 + 0x30);
    if (param_1 == 0) {
      **(undefined4 **)(this + 0x30) = 0x8b31;
      local_60 = 0;
      *(undefined4 *)(*(int *)(this + 0x28) + 0x3c) = 0;
    }
    else {
      **(undefined4 **)(this + iVar3 + 0x30) = 0x8b30;
      local_60 = 1;
      *(undefined4 *)(*(int *)(this + iVar3 + 0x28) + 0x3c) = 1;
    }
  }
  if (bVar30) {
    pTVar35 = this + iVar3;
    iVar13 = 0;
    iVar31 = 0;
    _memset(pvVar15,0,*(int *)(pTVar35 + 0x20) << 2);
    _memset(pvVar16,0,*(int *)(pTVar35 + 0x20) << 2);
    pTVar10 = pTVar35;
    pTVar11 = pTVar35;
    pTVar12 = pTVar35;
    if (0 < *(int *)(pTVar35 + 0x20)) {
      do {
        local_54 = pTVar12;
        local_58 = pTVar11;
        local_5c = pTVar10;
        iVar14 = iVar13 * 4;
        iVar33 = **(int **)(*(int *)(iVar14 + *(int *)(pTVar35 + 0x18)) + 0x20);
        while (iVar33 != 0) {
          iVar19 = _PPStreamChunkCreateFromChunk(iVar33);
          _PPStreamChunkListAddChunk(*(undefined4 *)(*(int *)(pTVar35 + 0x30) + 0x20),iVar19);
          if (*(int *)(iVar14 + (int)pvVar15) == 0) {
            *(int *)(iVar14 + (int)pvVar15) = iVar19;
          }
          uVar28 = *(uint *)(iVar19 + 0x10);
          *(uint *)(iVar19 + 0xc) =
               (*(uint *)(iVar19 + 0xc) & 0x3ffff) + iVar31 & 0x3ffff |
               *(uint *)(iVar19 + 0xc) & 0xfffc0000;
          if ((uVar28 & 0x3ffff) != 0) {
            *(uint *)(iVar19 + 0x10) = (uVar28 & 0x3ffff) + iVar31 & 0x3ffff | uVar28 & 0xfffc0000;
          }
          if (*(int *)(iVar19 + 0x40) != 0) {
            pcVar34 = (char *)(iVar19 + 0x44);
            sVar20 = _strlen(puVar4);
            iVar21 = _strncmp(pcVar34,puVar4,sVar20);
            if (iVar21 != 0) {
              sVar20 = _strlen(puVar5);
              iVar21 = _strncmp(pcVar34,puVar5,sVar20);
              if (iVar21 != 0) {
                sVar20 = _strlen(puVar6);
                iVar21 = _strncmp(pcVar34,puVar6,sVar20);
                if (iVar21 != 0) {
                  sVar20 = _strlen(puVar7);
                  iVar21 = _strncmp(pcVar34,puVar7,sVar20);
                  if (iVar21 != 0) {
                    sVar20 = _strlen(puVar8);
                    iVar21 = _strncmp(pcVar34,puVar8,sVar20);
                    if (iVar21 != 0) {
                      sVar20 = _strlen(puVar9);
                      iVar21 = _strncmp(pcVar34,puVar9,sVar20);
                      if (iVar21 != 0) goto LAB_97bb257c;
                    }
                  }
                }
              }
            }
            _sprintf(local_70,"%04d",iVar13);
            pcVar22 = (char *)(iVar19 + 0x44);
            pcVar34 = local_70;
            iVar19 = 4;
            do {
              cVar1 = *pcVar34;
              pcVar34 = pcVar34 + 1;
              *pcVar22 = cVar1;
              pcVar22 = pcVar22 + 1;
              iVar19 = iVar19 + -1;
            } while (iVar19 != 0);
          }
LAB_97bb257c:
          iVar33 = *(int *)(iVar33 + 8);
          *(int *)(iVar14 + (int)pvVar16) = *(int *)(iVar14 + (int)pvVar16) + 1;
        }
        pTVar10 = local_5c;
        pTVar11 = local_54;
        for (iVar33 = **(int **)(*(int *)(iVar14 + *(int *)(pTVar35 + 0x18)) + 0x24);
            local_5c = pTVar10, local_54 = pTVar11, iVar33 != 0; iVar33 = *(int *)(iVar33 + 8)) {
          iVar19 = _PPStreamChunkCreateFromChunk(iVar33);
          _PPStreamChunkListAddChunk(*(undefined4 *)(*(int *)(pTVar35 + 0x30) + 0x24),iVar19);
          *(int *)(iVar19 + 0xc) = *(int *)(iVar19 + 0xc) + iVar31;
          if (*(int *)(iVar19 + 0x10) != 0) {
            pcVar34 = (char *)(iVar19 + 0x14);
            sVar20 = _strlen(puVar4);
            iVar21 = _strncmp(pcVar34,puVar4,sVar20);
            if (iVar21 != 0) {
              sVar20 = _strlen(puVar5);
              iVar21 = _strncmp(pcVar34,puVar5,sVar20);
              if (iVar21 != 0) {
                sVar20 = _strlen(puVar6);
                iVar21 = _strncmp(pcVar34,puVar6,sVar20);
                if (iVar21 != 0) {
                  sVar20 = _strlen(puVar7);
                  iVar21 = _strncmp(pcVar34,puVar7,sVar20);
                  if (iVar21 != 0) {
                    sVar20 = _strlen(puVar8);
                    iVar21 = _strncmp(pcVar34,puVar8,sVar20);
                    if (iVar21 != 0) {
                      sVar20 = _strlen(puVar9);
                      iVar21 = _strncmp(pcVar34,puVar9,sVar20);
                      if (iVar21 != 0) goto LAB_97bb26e0;
                    }
                  }
                }
              }
            }
            _sprintf(local_70,"%04d",iVar13);
            pcVar22 = (char *)(iVar19 + 0x14);
            pcVar34 = local_70;
            iVar19 = 4;
            do {
              cVar1 = *pcVar34;
              pcVar34 = pcVar34 + 1;
              *pcVar22 = cVar1;
              pcVar22 = pcVar22 + 1;
              iVar19 = iVar19 + -1;
            } while (iVar19 != 0);
          }
LAB_97bb26e0:
          pTVar10 = local_5c;
          pTVar11 = local_54;
        }
        iVar19 = 0;
        iVar21 = *(int *)(*(int *)(iVar14 + *(int *)(pTVar35 + 8)) + 0x6c);
        iVar33 = *(int *)(iVar21 + 4);
        if (0 < iVar33) {
          do {
            uVar28 = 0;
            if (0 < *(int *)(*(int *)(pTVar10 + 0x38) + 4)) {
              do {
                pcVar34 = (char *)FunctionTable__getFunctionName(*(int *)(pTVar11 + 0x38));
                pcVar22 = (char *)FunctionTable__getFunctionName(iVar21);
                iVar33 = _strcmp(pcVar34,pcVar22);
                if (iVar33 == 0) {
                  FunctionTable__getFirstOp(*(int *)(pTVar11 + 0x38));
                  FunctionTable__setFirstOp(*(int *)(pTVar11 + 0x38),uVar28);
                  FunctionTable__getLastOp(*(int *)(pTVar11 + 0x38));
                  FunctionTable__setLastOp(*(int *)(pTVar11 + 0x38),uVar28);
                }
                uVar28 = uVar28 + 1;
              } while ((int)uVar28 < *(int *)(*(int *)(pTVar11 + 0x38) + 4));
              iVar33 = *(int *)(iVar21 + 4);
            }
            iVar19 = iVar19 + 1;
          } while (iVar19 < iVar33);
        }
        iVar31 = iVar31 + *(int *)(iVar14 + (int)pvVar16);
        if (*(int *)(*(int *)(iVar14 + *(int *)(local_58 + 8)) + 0xa4) != 0) {
          local_60 = 1;
        }
        iVar13 = iVar13 + 1;
        pTVar10 = local_5c;
        pTVar11 = local_58;
        pTVar12 = local_54;
      } while (iVar13 < *(int *)(local_58 + 0x20));
    }
    if (local_60 == 0) {
      pcVar34 = *(char **)(this + 0x84);
                    
      TInfoSinkBase__append(pcVar34);
      TInfoSinkBase__append(pcVar34);
      bVar30 = false;
      TInfoSinkBase__append(pcVar34);
    }
  }
  if (bVar30) {
    iVar13 = 1;
    do {
      iVar31 = 0;
      if (0 < *(int *)(this + iVar3 + 0x20)) {
        do {
          iVar14 = iVar31 * 4;
          puVar23 = (undefined4 *)
                    ParseSymbolTable__NextSymbol
                              (*(unsigned char **)(iVar14 + *(int *)(this + iVar3 + 0x10)));
          while (puVar23 != (undefined4 *)0x0) {
            if (iVar13 == puVar23[0x15]) {
              puVar32 = (undefined4 *)0x0;
              if (puVar23[0xe] == 0) {
                bVar27 = true;
LAB_97bb2ab4:
                if (bVar27) goto LAB_97bb2ab8;
              }
              else {
                puVar32 = (undefined4 *)
                          ParseSymbolTable__FindGlobalSymbolByName(*(char **)(this + iVar3 + 0x28));
                bVar27 = puVar32 == (undefined4 *)0x0;
                if (!bVar27) {
                  if (*(short *)(puVar32 + 0xb) == *(short *)(puVar23 + 0xb)) {
                    if (*(short *)((int)puVar32 + 0x2e) == *(short *)((int)puVar23 + 0x2e))
                    goto LAB_97bb2ab4;
                    pcVar22 = (char *)puVar32[5];
                    sVar20 = _strlen(DAT_a7b7bb18);
                    sVar24 = _strlen(pcVar22);
                    sVar25 = _strlen((char *)(&_shaderString)[param_1]);
                    pcVar34 = _malloc(sVar20 + sVar24 + sVar25 + 1);
                    _sprintf(pcVar34,DAT_a7b7bb18,pcVar22,(&_shaderString)[param_1]);
                    pcVar22 = *(char **)(this + 0x84);
                    
                  }
                  else {
                    pcVar22 = (char *)puVar32[5];
                    sVar20 = _strlen(DAT_a7b7bb14);
                    sVar24 = _strlen(pcVar22);
                    sVar25 = _strlen((char *)(&_shaderString)[param_1]);
                    pcVar34 = _malloc(sVar20 + sVar24 + sVar25 + 1);
                    _sprintf(pcVar34,DAT_a7b7bb14,pcVar22,(&_shaderString)[param_1]);
                    pcVar22 = *(char **)(this + 0x84);
                    
                  }
                  TInfoSinkBase__append(pcVar22);
                  TInfoSinkBase__append(pcVar22);
                  TInfoSinkBase__append(pcVar22);
                  _free(pcVar34);
                  bVar30 = false;
                  goto LAB_97bb2ab4;
                }
LAB_97bb2ab8:
                bVar27 = false;
                if ((iVar13 != 0) && (pbVar29 = (byte *)*puVar23, pbVar29 != (byte *)0x0)) {
                  bVar2 = *pbVar29;
                  if (bVar2 != 2) {
                    if (bVar2 < 3) {
                      if ((bVar2 == 0) &&
                         (iVar33 = **(int **)(*(int *)(iVar14 + *(int *)(this + iVar3 + 0x18)) + 8),
                         iVar33 != 0)) {
                        bVar27 = false;
                        do {
                          if (*(short *)(pbVar29 + 0x12) == *(short *)(iVar33 + 0xe)) {
                            bVar27 = true;
                          }
                          iVar33 = *(int *)(iVar33 + 8);
                        } while (iVar33 != 0);
                      }
                    }
                    else if ((bVar2 == 3) &&
                            (iVar33 = **(int **)(*(int *)(iVar14 + *(int *)(this + iVar3 + 0x18)) +
                                                0x14), iVar33 != 0)) {
                      bVar27 = false;
                      do {
                        if (*(short *)(pbVar29 + 0x12) == *(short *)(iVar33 + 0xe)) {
                          bVar27 = true;
                        }
                        iVar33 = *(int *)(iVar33 + 8);
                      } while (iVar33 != 0);
                    }
                  }
                }
                puVar32 = (undefined4 *)
                          ParseSymbolTable__AddFromExternalSymbol
                                    (*(unsigned char **)(this + iVar3 + 0x28),SUB41(puVar23,0),bVar27)
                ;
              }
              if ((bVar30 != true) || (puVar32 == (undefined4 *)0x0)) {
                if ((bVar30 == true) && (puVar32 == (undefined4 *)0x0)) {
                  pcVar22 = (char *)puVar23[5];
                  sVar20 = _strlen(DAT_a7b7bbc0);
                  sVar24 = _strlen(pcVar22);
                  pcVar34 = _malloc(sVar20 + sVar24 + 1);
                  _sprintf(pcVar34,DAT_a7b7bb90,pcVar22);
                  pcVar22 = *(char **)(this + 0x84);
                    
                  TInfoSinkBase__append(pcVar22);
                  TInfoSinkBase__append(pcVar22);
                  TInfoSinkBase__append(pcVar22);
                  _free(pcVar34);
                  bVar30 = false;
                }
              }
              else {
                iVar33 = TGenericLinker__FindChunkDelta(this,(unsigned char *)*puVar23,(unsigned char *)*puVar32);
                if (iVar33 != 0) {
                  iVar19 = ((int (*)())GetVec4sForType)(*(ushort *)(puVar23 + 0xb));
                  UpdateOperations(*(unsigned char **)(iVar14 + (int)pvVar15),
                                   (unsigned char *)
                                   **(undefined4 **)
                                     (*(int *)(iVar14 + *(int *)(this + iVar3 + 0x18)) + 0x20),
                                   *(int *)(iVar14 + (int)pvVar16),(unsigned char *)*puVar23,iVar19
                                   ,iVar33);
                }
              }
            }
            puVar23 = (undefined4 *)
                      ParseSymbolTable__NextSymbol
                                (*(unsigned char **)(iVar14 + *(int *)(this + iVar3 + 0x10)));
          }
          iVar31 = iVar31 + 1;
        } while (iVar31 < *(int *)(this + iVar3 + 0x20));
      }
      iVar13 = iVar13 + -1;
    } while (-1 < iVar13);
    if (bVar30 == true) {
      iVar13 = 0;
      if (0 < *(int *)(this + iVar3 + 0x20)) {
        do {
          iVar31 = iVar13 * 4;
          for (p_Var36 = (unsigned char *)
                         **(undefined4 **)(*(int *)(iVar31 + *(int *)(this + iVar3 + 0x18)) + 0x10);
              p_Var36 != (unsigned char *)0x0; p_Var36 = *(unsigned char **)(p_Var36 + 8)) {
            uVar28 = *(uint *)(p_Var36 + 0xc);
            if ((uVar28 & 0x1f0000) == 0x110000) {
              iVar14 = *(int *)(*(int *)(this + iVar3 + 0x28) + 0x24);
              *(int *)(*(int *)(this + iVar3 + 0x28) + 0x24) = iVar14 + 1;
              p_Var26 = (unsigned char *)_PPStreamChunkCreateFromChunk(p_Var36);
              _PPStreamChunkListAddChunk
                        (*(undefined4 *)(*(int *)(this + iVar3 + 0x30) + 0x10),p_Var26);
              *(short *)(p_Var26 + 0x12) = (short)iVar14;
              iVar14 = TGenericLinker__FindChunkDelta(this,p_Var36,p_Var26);
              UpdateOperations(*(unsigned char **)(iVar31 + (int)pvVar15),
                               (unsigned char *)
                               **(undefined4 **)
                                 (*(int *)(iVar31 + *(int *)(this + iVar3 + 0x18)) + 0x20),
                               *(int *)(iVar31 + (int)pvVar16),p_Var36,1,iVar14);
              *(undefined2 *)(p_Var26 + 0xe) =
                   *(undefined2 *)(*(int *)(*(int *)(this + iVar3 + 0x30) + 0x2c) + 10);
              iVar14 = _PPStreamChunkListChunkAtIndex
                                 (*(undefined4 *)
                                   (*(int *)(iVar31 + *(int *)(this + iVar3 + 0x18)) + 0x2c),
                                  uVar28 & 0xffff);
              _PPStreamAddConstant(*(undefined4 *)(this + iVar3 + 0x30),iVar14 + 0xc);
            }
          }
          iVar13 = iVar13 + 1;
        } while (iVar13 < *(int *)(this + iVar3 + 0x20));
      }
      iVar31 = 0;
      iVar13 = 0;
      if (0 < *(int *)(this + iVar3 + 0x20)) {
        do {
          iVar14 = 0;
          for (iVar33 = **(int **)(*(int *)(iVar31 * 4 + *(int *)(this + iVar3 + 0x18)) + 0xc);
              iVar33 != 0; iVar33 = *(int *)(iVar33 + 8)) {
            iVar14 = iVar14 + 1;
            if (iVar13 < iVar14) {
              uVar17 = _PPStreamChunkCreateFromChunk(iVar33);
              _PPStreamChunkListAddChunk
                        (*(undefined4 *)(*(int *)(this + iVar3 + 0x30) + 0xc),uVar17);
              iVar13 = iVar14;
            }
          }
          iVar31 = iVar31 + 1;
        } while (iVar31 < *(int *)(this + iVar3 + 0x20));
      }
      iVar13 = 0;
      if (0 < *(int *)(this + iVar3 + 0x20)) {
        do {
          for (iVar31 = **(int **)(*(int *)(iVar13 * 4 + *(int *)(this + iVar3 + 0x18)) + 0x30);
              iVar31 != 0; iVar31 = *(int *)(iVar31 + 8)) {
            iVar14 = **(int **)(*(int *)(this + iVar3 + 0x30) + 0x30);
            if (iVar14 != 0) {
              do {
                if (*(char *)(iVar14 + 0xf) == *(char *)(iVar31 + 0xf)) goto LAB_97bb2f70;
                iVar14 = *(int *)(iVar14 + 8);
              } while (iVar14 != 0);
            }
            uVar17 = _PPStreamChunkCreateFromChunk(iVar31);
            _PPStreamChunkListAddChunk(*(undefined4 *)(*(int *)(this + iVar3 + 0x30) + 0x30),uVar17)
            ;
LAB_97bb2f70: ;
          }
          iVar13 = iVar13 + 1;
        } while (iVar13 < *(int *)(this + iVar3 + 0x20));
      }
    }
  }
  if (bVar30 == false) {
    if (*(int *)(this + iVar3 + 0x30) != 0) {
      _PPStreamFree();
    }
    pPVar18 = *(unsigned char **)(this + iVar3 + 0x28);
    *(undefined4 *)(this + iVar3 + 0x30) = 0;
    if (pPVar18 != (unsigned char *)0x0) {
      ParseSymbolTable___ParseSymbolTable(pPVar18);
      operator_delete(pPVar18);
    }
    *(undefined4 *)(this + iVar3 + 0x28) = 0;
  }
  return bVar30;
}

/* TGenericLinker__CreateFromStreamWithSymbolTableUpdate @ 0x97bb2ff0 (844 bytes) */
int TGenericLinker__CreateFromStreamWithSymbolTableUpdate(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  unsigned char * p_Var3;
  int iVar4;
  char *pcVar5;
  
  puVar1 = (undefined4 *)_PPStreamCreate();
  *puVar1 = *(undefined4 *)param_1;
  *(undefined4 **)(param_2 + 0xc) = puVar1;
  for (p_Var3 = (unsigned char *)**(undefined4 **)(param_1 + 4); p_Var3 != (unsigned char *)0x0;
      p_Var3 = *(unsigned char **)(p_Var3 + 8)) {
    uVar2 = _PPStreamChunkCreateFromChunk(p_Var3);
    _PPStreamChunkListAddChunk(puVar1[1],uVar2);
    ParseSymbolTable__ChangeChunk((unsigned char *)param_2,p_Var3,SUB41(uVar2,0));
  }
  for (iVar4 = **(int **)(param_1 + 8); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar2 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar1[2],uVar2);
  }
  for (iVar4 = **(int **)(param_1 + 0xc); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar2 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar1[3],uVar2);
  }
  for (p_Var3 = (unsigned char *)**(undefined4 **)(param_1 + 0x10); p_Var3 != (unsigned char *)0x0
      ; p_Var3 = *(unsigned char **)(p_Var3 + 8)) {
    uVar2 = _PPStreamChunkCreateFromChunk(p_Var3);
    _PPStreamChunkListAddChunk(puVar1[4],uVar2);
    ParseSymbolTable__ChangeChunk((unsigned char *)param_2,p_Var3,SUB41(uVar2,0));
  }
  for (iVar4 = **(int **)(param_1 + 0x14); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar2 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar1[5],uVar2);
  }
  for (p_Var3 = (unsigned char *)**(undefined4 **)(param_1 + 0x18); p_Var3 != (unsigned char *)0x0
      ; p_Var3 = *(unsigned char **)(p_Var3 + 8)) {
    uVar2 = _PPStreamChunkCreateFromChunk(p_Var3);
    _PPStreamChunkListAddChunk(puVar1[6],uVar2);
    ParseSymbolTable__ChangeChunk((unsigned char *)param_2,p_Var3,SUB41(uVar2,0));
  }
  for (p_Var3 = (unsigned char *)**(undefined4 **)(param_1 + 0x1c); p_Var3 != (unsigned char *)0x0
      ; p_Var3 = *(unsigned char **)(p_Var3 + 8)) {
    uVar2 = _PPStreamChunkCreateFromChunk(p_Var3);
    _PPStreamChunkListAddChunk(puVar1[7],uVar2);
    ParseSymbolTable__ChangeChunk((unsigned char *)param_2,p_Var3,SUB41(uVar2,0));
  }
  for (iVar4 = **(int **)(param_1 + 0x20); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar2 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar1[8],uVar2);
  }
  for (iVar4 = **(int **)(param_1 + 0x24); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar2 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar1[9],uVar2);
  }
  for (iVar4 = **(int **)(param_1 + 0x2c); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar2 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar1[0xb],uVar2);
  }
  for (iVar4 = **(int **)(param_1 + 0x28); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar2 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar1[10],uVar2);
  }
  for (iVar4 = **(int **)(param_1 + 0x30); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar2 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar1[0xc],uVar2);
  }
  iVar4 = _PPStreamCompare(param_1,puVar1);
  if (iVar4 == 1) {
    pcVar5 = *(char **)(this + 0x84);
                    
    TInfoSinkBase__append(pcVar5);
    TInfoSinkBase__append(pcVar5);
    TInfoSinkBase__append(pcVar5);
    _PPStreamFree(puVar1);
    puVar1 = (undefined4 *)0x0;
  }
  return puVar1;
}

/* TGenericLinker__RemoveUnreachableFunctions @ 0x97bb33bc (840 bytes) */
int TGenericLinker__RemoveUnreachableFunctions(this)
  unsigned char * this;
{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  size_t sVar7;
  size_t sVar8;
  size_t sVar9;
  char *pcVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  char *pcVar15;
  
  iVar12 = 0;
LAB_97bb33e4:
  iVar2 = iVar12 * 4;
LAB_97bb33e8:
  bVar1 = false;
  iVar13 = 0;
  if ((*(int *)(this + iVar2 + 0x38) != 0) && (0 < *(int *)(*(int *)(this + iVar2 + 0x38) + 4))) {
LAB_97bb3410:
    pcVar3 = (char *)FunctionTable__getFunctionName(*(int *)(this + iVar2 + 0x38));
    iVar4 = _memcmp(pcVar3,"main(",6);
    if (iVar4 != 0) {
      for (iVar4 = **(int **)(*(int *)(this + iVar2 + 0x30) + 0x20); iVar4 != 0;
          iVar4 = *(int *)(iVar4 + 8)) {
        if ((((*(uint *)(iVar4 + 0xc) & 0x3fc0000) == 0x1300000) && (*(int *)(iVar4 + 0x40) != 0))
           && (iVar5 = _strcmp((char *)(iVar4 + 0x44),pcVar3), iVar5 == 0)) goto LAB_97bb37a8;
      }
      for (iVar4 = **(int **)(*(int *)(this + iVar2 + 0x30) + 0x20); iVar4 != 0;
          iVar4 = *(int *)(iVar4 + 8)) {
        uVar14 = *(uint *)(iVar4 + 0xc);
        uVar6 = FunctionTable__getFirstOp(*(int *)(this + iVar2 + 0x38));
        if ((uVar14 & 0x3ffff) == uVar6) {
          bVar1 = false;
          goto LAB_97bb361c;
        }
      }
      sVar7 = _strlen(DAT_a7b7baec);
      sVar8 = _strlen((char *)(&_shaderString)[iVar12]);
      sVar9 = _strlen(pcVar3);
      pcVar10 = _malloc(sVar7 + sVar8 + sVar9 + 9);
      uVar11 = FunctionTable__getFirstOp(*(int *)(this + iVar2 + 0x38));
      _sprintf(pcVar10,DAT_a7b7baec,pcVar3,(&_shaderString)[iVar12],uVar11);
      pcVar3 = *(char **)(this + 0x84);
                    
      TInfoSinkBase__append(pcVar3);
      TInfoSinkBase__append(pcVar3);
      TInfoSinkBase__append(pcVar3);
      _free(pcVar10);
      goto LAB_97bb3790;
    }
    goto LAB_97bb37a8;
  }
  goto LAB_97bb37d4;
  while( true ) {
    if ((*(uint *)(iVar4 + 0xc) & 0x3ffff) == 0) {
      sVar7 = _strlen(DAT_a7b7baf0);
      sVar8 = _strlen((char *)(&_shaderString)[iVar12]);
      sVar9 = _strlen(pcVar3);
      pcVar10 = _malloc(sVar7 + sVar8 + sVar9 + 1);
      _sprintf(pcVar10,DAT_a7b7baf0,pcVar3,(&_shaderString)[iVar12]);
      pcVar15 = *(char **)(this + 0x84);
                    
      TInfoSinkBase__append(pcVar15);
      TInfoSinkBase__append(pcVar15);
      TInfoSinkBase__append(pcVar15);
      _free(pcVar10);
    }
    else {
      _PPStreamRemoveLabelsAtOperationIndex
                (*(undefined4 *)(this + iVar2 + 0x30),*(uint *)(iVar4 + 0xc) & 0x3ffff);
      iVar5 = *(int *)(iVar4 + 8);
      bVar1 = iVar5 == 0;
      if (!bVar1) {
        *(uint *)(iVar5 + 0xc) =
             (*(uint *)(iVar4 + 0xc) >> 0x1a & 7) << 0x1a | *(uint *)(iVar5 + 0xc) & 0xe3ffffff;
      }
      _PPStreamChunkListRemoveChunk(*(undefined4 *)(*(int *)(this + iVar2 + 0x30) + 0x20),iVar4);
      iVar4 = iVar5;
    }
    if (bVar1) break;
LAB_97bb361c:
    uVar14 = *(uint *)(iVar4 + 0xc);
    uVar6 = FunctionTable__getLastOp(*(int *)(this + iVar2 + 0x38));
    if ((uVar14 & 0x3ffff) == uVar6) {
      if (!bVar1) {
        iVar5 = *(int *)(iVar4 + 8);
        if (iVar5 != 0) {
          *(uint *)(iVar5 + 0xc) =
               (*(uint *)(iVar4 + 0xc) >> 0x1a & 7) << 0x1a | *(uint *)(iVar5 + 0xc) & 0xe3ffffff;
        }
        uVar14 = *(uint *)(iVar4 + 0xc);
        uVar6 = FunctionTable__getLastOp(*(int *)(this + iVar2 + 0x38));
        if ((uVar14 & 0x3ffff) == uVar6) {
          _PPStreamChunkListRemoveChunk(*(undefined4 *)(*(int *)(this + iVar2 + 0x30) + 0x20),iVar4)
          ;
        }
      }
      break;
    }
  }
LAB_97bb3790:
  iVar13 = iVar13 + -1;
  bVar1 = true;
  FunctionTable__removeFunction(*(int *)(this + iVar2 + 0x38));
LAB_97bb37a8:
  iVar13 = iVar13 + 1;
  if ((*(int *)(this + iVar2 + 0x38) == 0) ||
     (*(int *)(*(int *)(this + iVar2 + 0x38) + 4) <= iVar13)) goto LAB_97bb37cc;
  goto LAB_97bb3410;
LAB_97bb37cc:
  if (!bVar1) goto LAB_97bb37d4;
  goto LAB_97bb33e8;
LAB_97bb37d4:
  iVar12 = iVar12 + 1;
  if (1 < iVar12) {
    return;
  }
  goto LAB_97bb33e4;
}

/* TGenericLinker__RenumberLabels @ 0x97bb37fc (40 bytes) */
int TGenericLinker__RenumberLabels(this, param_1, param_2, param_3)
  unsigned char * this;
  unsigned char * param_1;
  uint param_2;
  uint param_3;
{
  if (param_1 != (unsigned char *)0x0) {
    do {
      if (param_2 == *(uint *)(param_1 + 0xc)) {
        *(uint *)(param_1 + 0xc) = param_3;
      }
      param_1 = *(unsigned char **)(param_1 + 8);
    } while (param_1 != (unsigned char *)0x0);
    return;
  }
  return;
}

/* TGenericLinker__RemoveUnusedRegisters @ 0x97bb3824 (820 bytes) */
int TGenericLinker__RemoveUnusedRegisters(this)
  unsigned char * this;
{
  bool bVar1;
  unsigned char * this_00;
  uint uVar2;
  uint uVar3;
  unsigned char * pPVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  unsigned char * pTVar11;
  byte *pbVar12;
  int iVar13;
  int iVar14;
  byte *pbVar15;
  int iVar16;
  
  iVar10 = 0;
  iVar9 = 0;
  pTVar11 = this;
  do {
    if (*(unsigned char **)(pTVar11 + 0x28) != (unsigned char *)0x0) {
      pPVar4 = (unsigned char *)ParseSymbolTable__NextSymbol(*(unsigned char **)(pTVar11 + 0x28));
      while (this_00 = pPVar4, this_00 != (unsigned char *)0x0) {
        iVar16 = *(int *)(this_00 + 0x54);
        pbVar12 = *(byte **)this_00;
        iVar14 = **(int **)(*(int *)(pTVar11 + 0x30) + 0x20);
        if (iVar14 == 0) {
          bVar1 = iVar16 == 0;
LAB_97bb3a3c:
          if (!bVar1) goto LAB_97bb3b10;
          pPVar4 = (unsigned char *)ParseSymbolTable__NextSymbol(*(unsigned char **)(pTVar11 + 0x28));
          ParseSymbolTable__RemoveSymbol(*(unsigned char **)(pTVar11 + 0x28));
          for (iVar14 = 0; iVar16 = ((int (*)())GetVec4sForType)(*(ushort *)(this_00 + 0x2c)), iVar14 < iVar16;
              iVar14 = iVar14 + 1) {
            bVar8 = *pbVar12;
            pbVar15 = *(byte **)(pbVar12 + 8);
            if (bVar8 == 2) {
              uVar6 = *(undefined4 *)(*(int *)(this + iVar9 + 0x30) + 0x18);
LAB_97bb3ad8:
              _PPStreamChunkListRemoveChunk(uVar6,pbVar12);
            }
            else {
              if (2 < bVar8) {
                if (bVar8 == 3) {
                  uVar6 = *(undefined4 *)(*(int *)(this + iVar9 + 0x30) + 0x10);
                }
                else {
                  if (bVar8 != 4) goto LAB_97bb3adc;
                  uVar6 = *(undefined4 *)(*(int *)(this + iVar9 + 0x30) + 0x1c);
                }
                goto LAB_97bb3ad8;
              }
              if (bVar8 == 0) {
                uVar6 = *(undefined4 *)(*(int *)(this + iVar9 + 0x30) + 4);
                goto LAB_97bb3ad8;
              }
            }
LAB_97bb3adc:
            pbVar12 = pbVar15;
          }
          if (this_00 != (unsigned char *)0x0) {
            ParseSymbol___ParseSymbol(this_00);
            operator_delete(this_00);
          }
        }
        else {
          bVar1 = iVar16 == 0;
          if (bVar1) {
            do {
              iVar13 = 0;
              while ((iVar5 = ((int (*)())GetVec4sForType)(*(ushort *)(this_00 + 0x2c)), iVar13 < iVar5 &&
                     (bVar1))) {
                iVar5 = 0;
                uVar2 = *(uint *)(iVar14 + 0xc) >> 0x1d;
                if (iVar16 < (int)uVar2) {
                  bVar8 = *pbVar12;
                  iVar7 = iVar14 + 0x10;
                  do {
                    if (bVar8 == 2) {
                      if (*(int *)(this_00 + 0x34) != 0) {
                        if ((*(uint *)(iVar7 + 0xc) & 0x3800000) != 0) goto LAB_97bb3954;
LAB_97bb393c:
                        if ((uint)*(ushort *)(iVar7 + 0x12) !=
                            (uint)*(ushort *)(pbVar12 + 0x12) + iVar13) goto LAB_97bb3954;
                      }
LAB_97bb3950:
                      iVar16 = 1;
                    }
                    else if (bVar8 < 3) {
                      if (bVar8 == 0) {
                        bVar1 = (*(uint *)(iVar7 + 0xc) >> 0x17 & 7) == 1;
                        goto LAB_97bb3938;
                      }
                    }
                    else {
                      if (bVar8 == 3) {
                        if (*(int *)(this_00 + 0x34) == 0) goto LAB_97bb3950;
                        bVar1 = (*(uint *)(iVar7 + 0xc) >> 0x17 & 7) == 2;
                      }
                      else {
                        if (bVar8 != 4) goto LAB_97bb3954;
                        bVar1 = (*(uint *)(iVar7 + 0xc) >> 0x17 & 7) == 3;
                      }
LAB_97bb3938:
                      if (bVar1) goto LAB_97bb393c;
                    }
LAB_97bb3954:
                    iVar5 = iVar5 + 1;
                    iVar7 = iVar7 + 8;
                  } while ((iVar5 < (int)uVar2) && (iVar16 == 0));
                }
                else {
                  bVar8 = *pbVar12;
                }
                if (bVar8 == 2) {
                  if (*(int *)(this_00 + 0x34) != 0) {
                    if ((*(uint *)(iVar14 + 0x14) & 0xe0000) != 0) goto LAB_97bb3a08;
LAB_97bb39f0:
                    if ((uint)*(ushort *)(iVar14 + 0x1a) !=
                        (uint)*(ushort *)(pbVar12 + 0x12) + iVar13) goto LAB_97bb3a08;
                  }
LAB_97bb3a04:
                  iVar16 = 1;
                }
                else if (bVar8 < 3) {
                  if (bVar8 == 0) {
                    uVar2 = *(uint *)(iVar14 + 0x14);
                    uVar3 = 0x20000;
                    goto LAB_97bb39e4;
                  }
                }
                else {
                  if (bVar8 == 3) {
                    if (*(int *)(this_00 + 0x34) == 0) goto LAB_97bb3a04;
                    uVar2 = *(uint *)(iVar14 + 0x14);
                    uVar3 = 0x40000;
                  }
                  else {
                    if (bVar8 != 4) goto LAB_97bb3a08;
                    uVar2 = *(uint *)(iVar14 + 0x14);
                    uVar3 = 0x60000;
                  }
LAB_97bb39e4:
                  if ((uVar2 & 0xe0000) == uVar3) goto LAB_97bb39f0;
                }
LAB_97bb3a08:
                bVar1 = iVar16 == 0;
                iVar13 = iVar13 + 1;
              }
              iVar14 = *(int *)(iVar14 + 8);
              if (iVar14 == 0) goto LAB_97bb3a3c;
            } while (bVar1);
          }
LAB_97bb3b10:
          pPVar4 = (unsigned char *)ParseSymbolTable__NextSymbol(*(unsigned char **)(pTVar11 + 0x28));
        }
      }
    }
    iVar10 = iVar10 + 1;
    iVar9 = iVar9 + 4;
    pTVar11 = pTVar11 + 4;
    if (1 < iVar10) {
      return;
    }
  } while( true );
}

/* TGenericLinker__RemoveExtraVertexOutputs @ 0x97bb3b58 (320 bytes) */
int TGenericLinker__RemoveExtraVertexOutputs(this)
  unsigned char * this;
{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  size_t sVar5;
  size_t sVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  
  if (*(unsigned char **)(this + 0x28) != (unsigned char *)0x0) {
    puVar3 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
joined_r0x97bb3b94:
    puVar2 = puVar3;
    if (puVar2 != (undefined4 *)0x0) {
      puVar3 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
      if ((*(char *)*puVar2 == '\0') && (puVar2[0x17] != 0)) {
        pcVar9 = (char *)puVar2[5];
        if (*(char **)(this + 0x2c) == (char *)0x0) {
          sVar5 = _strlen(DAT_a7b7bae0);
          sVar6 = _strlen(pcVar9);
          pcVar7 = _malloc(sVar5 + sVar6 + 1);
          bVar1 = true;
          pcVar8 = DAT_a7b7bae0;
        }
        else {
          iVar4 = ParseSymbolTable__FindGlobalSymbolByName(*(char **)(this + 0x2c));
          bVar1 = iVar4 == 0;
          if (!bVar1) goto joined_r0x97bb3b94;
          sVar5 = _strlen(DAT_a7b7bad8);
          sVar6 = _strlen(pcVar9);
          pcVar7 = _malloc(sVar5 + sVar6 + 1);
          pcVar8 = DAT_a7b7bad8;
        }
        _sprintf(pcVar7,pcVar8,pcVar9);
        if (bVar1) {
          pcVar9 = *(char **)(this + 0x84);
                    
          TInfoSinkBase__append(pcVar9);
          TInfoSinkBase__append(pcVar9);
          TInfoSinkBase__append(pcVar9);
          _free(pcVar7);
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
  ushort uVar1;
  bool bVar2;
  int iVar3;
  short sVar5;
  void *pvVar4;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  unsigned char * pTVar10;
  int iVar11;
  uint uVar12;
  uint local_a0;
  undefined4 local_9c;
  int local_98;
  int local_94;
  undefined4 local_90;
  uint local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  
  iVar9 = 0;
  iVar8 = 0;
  pTVar10 = this;
  do {
    if (*(int *)(pTVar10 + 0x30) != 0) {
      for (iVar11 = **(int **)(*(int *)(pTVar10 + 0x30) + 0x1c); iVar11 != 0;
          iVar11 = *(int *)(iVar11 + 8)) {
        bVar2 = false;
        uVar1 = *(ushort *)(iVar11 + 0x12);
        local_9c = **(int **)(*(int *)(pTVar10 + 0x30) + 0x20);
        if (local_9c != 0) {
          do {
            uVar12 = 0;
            uVar6 = *(uint *)(local_9c + 0xc) >> 0x1d;
            if (uVar6 != 0) {
              iVar3 = local_9c + 0x10;
              do {
                if ((((*(uint *)(iVar3 + 0xc) >> 0x17 & 7) == 3) &&
                    (*(ushort *)(iVar3 + 0x12) == uVar1)) ||
                   (((*(uint *)(local_9c + 0xc) & 0x3fc0000) == 0x1b40000 &&
                    (((*(uint *)(local_9c + 0x14) & 0xe0000) == 0x60000 &&
                     (*(ushort *)(local_9c + 0x1a) == uVar1)))))) {
                  bVar2 = true;
                  break;
                }
                if (bVar2) break;
                uVar12 = uVar12 + 1;
                iVar3 = iVar3 + 8;
              } while (uVar12 < uVar6);
            }
            local_9c = *(int *)(local_9c + 8);
          } while (local_9c != 0);
          if (bVar2) {
            local_a0 = 0;
            local_98 = local_9c;
            local_94 = local_9c;
            sVar5 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(*(int *)(pTVar10 + 0x30) + 4));
            local_9c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_9c) + 0)),sVar5 + 1);
            local_a0 = (*(uint *)(iVar11 + 0xc) >> 0x18 & 3) << 0x18 |
                       (*(uint *)(iVar11 + 0xc) >> 0x1a & 7) << 0x1a |
                       *(uint *)(iVar11 + 0xc) & 0xe0000000 | local_a0 & 0xffffff;
            _PPStreamAddTempUsage(*(undefined4 *)(pTVar10 + 0x30),&local_a0);
            for (iVar3 = **(int **)(*(int *)(pTVar10 + 0x30) + 0x20); iVar3 != 0;
                iVar3 = *(int *)(iVar3 + 8)) {
              if (((*(uint *)(iVar3 + 0x14) & 0xe0000) == 0x60000) &&
                 (*(ushort *)(iVar3 + 0x1a) == uVar1)) {
                *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfff1ffff | 0x20000;
                *(undefined2 *)(iVar3 + 0x1a) = (*(unsigned short *)((unsigned char *)&(local_9c) + 2));
              }
              uVar6 = *(uint *)(iVar3 + 0xc);
              uVar12 = 0;
              if (uVar6 >> 0x1d != 0) {
                iVar7 = iVar3 + 0x10;
                do {
                  if (((*(uint *)(iVar7 + 0xc) >> 0x17 & 7) == 3) &&
                     (*(ushort *)(iVar7 + 0x12) == uVar1)) {
                    *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) & 0xfc7fffff | 0x800000;
                    *(undefined2 *)(iVar7 + 0x12) = (*(unsigned short *)((unsigned char *)&(local_9c) + 2));
                    uVar6 = *(uint *)(iVar3 + 0xc);
                  }
                  uVar12 = uVar12 + 1;
                  iVar7 = iVar7 + 8;
                } while (uVar12 < uVar6 >> 0x1d);
              }
            }
            bVar2 = false;
            uVar6 = 0;
            uVar12 = 0;
            if ((*(int *)(pTVar10 + 0x38) != 0) && (*(int *)(*(int *)(pTVar10 + 0x38) + 4) != 0)) {
              do {
                pvVar4 = (void *)FunctionTable__getFunctionName(*(int *)(pTVar10 + 0x38));
                iVar3 = _memcmp(pvVar4,"main(",6);
                if (iVar3 == 0) {
                  uVar6 = FunctionTable__getLastOp(*(int *)(pTVar10 + 0x38));
                }
                uVar12 = uVar12 + 1;
              } while ((*(int *)(pTVar10 + 0x38) != 0) &&
                      (uVar12 < *(uint *)(*(int *)(pTVar10 + 0x38) + 4)));
            }
            for (iVar3 = **(int **)(*(int *)(pTVar10 + 0x30) + 0x20); iVar3 != 0;
                iVar3 = *(int *)(iVar3 + 8)) {
              uVar12 = *(uint *)(iVar3 + 0xc);
              if ((uVar12 & 0x3ffff) == 0) {
                bVar2 = true;
              }
              if ((bVar2) && ((uVar12 & 0x3fc0000) == 0x1340000)) {
                uVar12 = local_a0 >> 0x18 & 3;
                local_88 = uVar12 << 10 | 0x6c;
                local_78 = 0;
                local_74 = 0;
                local_70 = 0;
                local_6c = 0;
                local_68 = 0;
                local_64 = 0;
                local_60 = *(undefined4 *)(iVar3 + 0x3c);
                local_90 = 0x20000000;
                local_5c = 0;
                if (uVar12 == 1) {
LAB_97bb40ac:
                  local_88 = local_88 | 0x4000;
LAB_97bb40b4:
                  local_88 = local_88 | 0x2000;
                }
                else {
                  if (uVar12 == 0) goto LAB_97bb40b4;
                  if (uVar12 == 2) {
LAB_97bb40a4:
                    local_88 = local_88 | 0x8000;
                    goto LAB_97bb40ac;
                  }
                  if (uVar12 == 3) {
                    local_88 = 0x10c6c;
                    goto LAB_97bb40a4;
                  }
                }
                uVar12 = local_a0 >> 0x18 & 3;
                local_8c = (local_a0 >> 0x1d & 3) << 0x12 |
                           uVar12 << 0x1a | (local_a0 >> 0x1a & 7) << 0x17;
                local_88 = local_88 | 0x60000;
                local_80 = uVar12 << 0xc | 0x8d8000;
                local_7c = local_9c & 0xffff;
                local_84 = (uint)uVar1;
                iVar7 = _PPStreamInsertOperationAfterChunk
                                  (*(undefined4 *)(this + iVar8 + 0x30),&local_90,0,0,
                                   *(undefined4 *)(iVar3 + 4));
                _PPStreamChangeBranchTargets
                          (*(undefined4 *)(this + iVar8 + 0x30),*(uint *)(iVar3 + 0xc) & 0x3ffff,
                           *(uint *)(iVar7 + 0xc) & 0x3ffff);
                uVar12 = *(uint *)(iVar3 + 0xc);
              }
              if (uVar6 == (uVar12 & 0x3ffff)) break;
            }
          }
        }
      }
    }
    iVar9 = iVar9 + 1;
    iVar8 = iVar8 + 4;
    pTVar10 = pTVar10 + 4;
    if (1 < iVar9) {
      return;
    }
  } while( true );
}

/* TGenericLinker__OptimizeFunctionIO @ 0x97bb419c (1248 bytes) */
int TGenericLinker__OptimizeFunctionIO(this)
  unsigned char * this;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int iVar5;
  size_t sVar6;
  char *pcVar7;
  int *piVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  size_t sVar12;
  size_t sVar13;
  char *pcVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  char *pcVar20;
  int iVar21;
  int local_70;
  int local_6c;
  uint local_60;
  int local_5c;
  
  iVar16 = 0;
  do {
    iVar2 = iVar16 * 4;
    iVar21 = 0;
    if ((*(int *)(this + iVar2 + 0x38) != 0) && (0 < *(int *)(*(int *)(this + iVar2 + 0x38) + 4))) {
      do {
        iVar17 = 0;
        pcVar4 = (char *)FunctionTable__getFunctionName(*(int *)(this + iVar2 + 0x38));
        iVar5 = _memcmp(pcVar4,"main(",6);
        if (iVar5 != 0) {
          for (; iVar5 = FunctionTable__getNumParams(*(int *)(this + iVar2 + 0x38)), iVar17 < iVar5;
              iVar17 = iVar17 + 1) {
            sVar6 = _strlen(pcVar4);
            pcVar7 = _malloc(sVar6 + 9);
            _sprintf(pcVar7,"%s_%i",pcVar4,iVar17);
            for (piVar8 = (int *)ParseSymbolTable__FindNextParamSymbolByName
                                           (*(unsigned char **)(this + iVar2 + 0x28),(char *)0x0);
                piVar8 != (int *)0x0;
                piVar8 = (int *)ParseSymbolTable__FindNextParamSymbolByName
                                          (*(unsigned char **)(this + iVar2 + 0x28),(char *)piVar8)) {
              uVar18 = 0;
              uVar9 = ((int (*)())GetVec4sForType)(*(ushort *)(piVar8 + 0xb));
              iVar5 = *piVar8;
              if (uVar9 != 0) {
                do {
                  local_60 = 0;
                  local_5c = 0;
                  local_70 = 0;
                  local_6c = 0;
                  iVar15 = **(int **)(*(int *)(this + iVar2 + 0x30) + 0x20);
                  iVar10 = FunctionTable__getEmpty(*(int *)(this + iVar2 + 0x38));
                  if (iVar10 == 0) {
                    for (; bVar1 = iVar15 == 0, !bVar1; iVar15 = *(int *)(iVar15 + 8)) {
                      uVar19 = *(uint *)(iVar15 + 0xc);
                      uVar3 = FunctionTable__getFirstOp(*(int *)(this + iVar2 + 0x38));
                      if ((uVar19 & 0x3ffff) == uVar3) goto LAB_97bb43a0;
                    }
                    sVar6 = _strlen(DAT_a7b7baec);
                    sVar12 = _strlen((char *)(&_shaderString)[iVar16]);
                    sVar13 = _strlen(pcVar4);
                    pcVar14 = _malloc(sVar6 + sVar12 + sVar13 + 9);
                    uVar11 = FunctionTable__getFirstOp(*(int *)(this + iVar2 + 0x38));
                    _sprintf(pcVar14,DAT_a7b7baec,pcVar4,(&_shaderString)[iVar16],uVar11);
                    pcVar20 = *(char **)(this + 0x84);
                    
                    TInfoSinkBase__append(pcVar20);
                    TInfoSinkBase__append(pcVar20);
                    TInfoSinkBase__append(pcVar20);
                    _free(pcVar14);
                  }
LAB_97bb44d0:
                  iVar15 = **(int **)(*(int *)(this + iVar2 + 0x30) + 0x20);
joined_r0x97bb44e4:
                  while (iVar10 = iVar15, iVar10 != 0) {
                    iVar15 = *(int *)(iVar10 + 8);
                    uVar3 = *(uint *)(iVar10 + 0xc) & 0x3fc0000;
                    if (uVar3 != 0) goto LAB_97bb456c;
                    if (((*(uint *)(iVar10 + 0x1c) & 0x3800000) == 0x800000) &&
                       ((uint)*(ushort *)(iVar10 + 0x22) == *(ushort *)(iVar5 + 0x12) + uVar18))
                    goto LAB_97bb4598;
                    if (((*(uint *)(iVar10 + 0x14) & 0xe0000) == 0x20000) &&
                       ((uint)*(ushort *)(iVar10 + 0x1a) == *(ushort *)(iVar5 + 0x12) + uVar18)) {
                      if (local_70 == 0 && local_6c == 0) goto LAB_97bb45b4;
                      *(int *)(iVar10 + 0x18) = local_6c;
                      *(int *)(iVar10 + 0x14) = local_70;
                    }
                  }
                  uVar18 = uVar18 + 1;
                } while (uVar18 < uVar9);
              }
            }
            _free(pcVar7);
          }
          iVar5 = **(int **)(*(int *)(this + iVar2 + 0x30) + 0x20);
          while (iVar17 = iVar5, iVar17 != 0) {
            iVar5 = *(int *)(iVar17 + 8);
            iVar15 = FunctionTable__getEmpty(*(int *)(this + iVar2 + 0x38));
            if ((((iVar15 != 0) && ((*(uint *)(iVar17 + 0xc) & 0x3fc0000) == 0x1300000)) &&
                (*(int *)(iVar17 + 0x40) != 0)) &&
               (iVar15 = _strcmp((char *)(iVar17 + 0x44),pcVar4), iVar15 == 0)) {
              FunctionTable__updateForRemovingChunk(*(unsigned char **)(this + iVar2 + 0x38));
              _PPStreamRemoveOperation(*(undefined4 *)(this + iVar2 + 0x30),iVar17);
            }
          }
        }
        iVar21 = iVar21 + 1;
      } while ((*(int *)(this + iVar2 + 0x38) != 0) &&
              (iVar21 < *(int *)(*(int *)(this + iVar2 + 0x38) + 4)));
    }
    iVar16 = iVar16 + 1;
    if (1 < iVar16) {
      return;
    }
  } while( true );
LAB_97bb43a0:
  if (((bVar1) ||
      (uVar19 = *(uint *)(iVar15 + 0xc),
      uVar3 = FunctionTable__getLastOp(*(int *)(this + iVar2 + 0x38)), uVar3 < (uVar19 & 0x3ffff)))
     || ((*(uint *)(iVar15 + 0xc) & 0x3ffff) == 0)) goto LAB_97bb44d0;
  iVar10 = *(int *)(iVar15 + 8);
  if ((*(uint *)(iVar15 + 0xc) & 0x3fc0000) == 0) {
    uVar3 = *(uint *)(iVar15 + 0x1c);
    if (((uVar3 & 0x3800000) == 0x800000) &&
       ((uint)*(ushort *)(iVar15 + 0x22) == *(ushort *)(iVar5 + 0x12) + uVar18)) {
      local_6c = *(int *)(iVar15 + 0x18);
      local_70 = *(int *)(iVar15 + 0x14);
      FunctionTable__updateForRemovingChunk(*(unsigned char **)(this + iVar2 + 0x38));
      uVar11 = *(undefined4 *)(this + iVar2 + 0x30);
    }
    else {
      if (((*(uint *)(iVar15 + 0x14) & 0xe0000) != 0x20000) ||
         ((uint)*(ushort *)(iVar15 + 0x1a) != *(ushort *)(iVar5 + 0x12) + uVar18))
      goto LAB_97bb4398;
      local_5c = *(int *)(iVar15 + 0x20);
      FunctionTable__updateForRemovingChunk(*(unsigned char **)(this + iVar2 + 0x38));
      uVar11 = *(undefined4 *)(this + iVar2 + 0x30);
      local_60 = uVar3;
    }
    _PPStreamRemoveOperation(uVar11,iVar15);
  }
LAB_97bb4398:
  bVar1 = iVar10 == 0;
  iVar15 = iVar10;
  goto LAB_97bb43a0;
LAB_97bb456c:
  if (((uVar3 == 0x1b40000) && ((*(uint *)(iVar10 + 0x1c) & 0x3800000) == 0x800000)) &&
     ((uint)*(ushort *)(iVar10 + 0x22) == *(ushort *)(iVar5 + 0x12) + uVar18)) {
LAB_97bb4598:
    if (local_60 == 0 && local_5c == 0) {
LAB_97bb45b4:
      FunctionTable__updateForRemovingChunk(*(unsigned char **)(this + iVar2 + 0x38));
      _PPStreamRemoveOperation(*(undefined4 *)(this + iVar2 + 0x30),iVar10);
    }
    else {
      *(int *)(iVar10 + 0x20) = local_5c;
      *(uint *)(iVar10 + 0x1c) = local_60;
    }
  }
  goto joined_r0x97bb44e4;
}

/* TGenericLinker__GetRemapTableString @ 0x97bb46f8 (412 bytes) */
int TGenericLinker__GetRemapTableString(this)
  unsigned char * this;
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  size_t sVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  undefined4 *puVar9;
  unsigned char * pTVar10;
  
  pTVar10 = this + 0x40;
  sVar4 = _strlen(_linkUtilString);
  puVar9 = &DAT_a7b7bb38;
  sVar4 = sVar4 + 2;
  do {
    iVar2 = *(int *)pTVar10;
    pTVar10 = pTVar10 + 4;
    if ((iVar2 == 0) || (iVar2 = BindingTable__GetSizeActiveUserUniforms(), iVar2 == 0)) {
      sVar5 = _strlen((char *)*puVar9);
      sVar4 = sVar4 + sVar5;
    }
    else {
      sVar5 = _strlen((char *)puVar9[-3]);
      sVar4 = sVar4 + sVar5;
      for (iVar2 = 0; iVar6 = BindingTable__GetSizeActiveUserUniforms(), iVar2 < iVar6;
          iVar2 = iVar2 + 1) {
        sVar5 = _strlen(DAT_a7b7bb34);
        sVar4 = sVar4 + sVar5 + 0x10;
      }
    }
    puVar9 = puVar9 + 1;
  } while ((int)puVar9 < -0x584844c3);
  pcVar7 = _malloc(sVar4);
  pcVar1 = _linkUtilString;
  *pcVar7 = '\0';
  _sprintf(pcVar7,pcVar1);
  puVar9 = &DAT_a7b7bb38;
  pTVar10 = this + 0x40;
  iVar2 = 0;
  iVar6 = 1;
  do {
    iVar3 = *(int *)pTVar10;
    pTVar10 = pTVar10 + 4;
    if ((iVar3 == 0) || (iVar3 = BindingTable__GetSizeActiveUserUniforms(), iVar3 == 0)) {
      _sprintf(pcVar7,(char *)*puVar9,pcVar7);
    }
    else {
      _sprintf(pcVar7,(char *)puVar9[-3],pcVar7);
      for (iVar3 = 0; iVar8 = BindingTable__GetSizeActiveUserUniforms(), iVar3 < iVar8;
          iVar3 = iVar3 + 1) {
        _sprintf(pcVar7,DAT_a7b7bb34,pcVar7,iVar3,
                 *(undefined4 *)(iVar3 * 4 + *(int *)(this + iVar2 + 0x40)));
      }
    }
    iVar6 = iVar6 + -1;
    iVar2 = iVar2 + 4;
    puVar9 = puVar9 + 1;
  } while (-1 < iVar6);
  return pcVar7;
}

/* TGenericLinker__GetBindingTableString @ 0x97bb4894 (384 bytes) */
int TGenericLinker__GetBindingTableString(this)
  unsigned char * this;
{
  char *pcVar1;
  size_t sVar2;
  size_t sVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  pcVar1 = (char *)BindingTable__GetString(*(int *)(this + 4));
  if (*(int *)(this + 0x74) < 0) {
    sVar2 = _strlen(DAT_a7b7bb44);
    sVar3 = _strlen(pcVar1);
    pcVar4 = _malloc(sVar2 + sVar3 + 0x29);
    *pcVar4 = '\0';
    uVar5 = BindingTable__GetNumActiveAttributeBindings();
    uVar6 = BindingTable__GetSizeActiveAttributes();
    uVar7 = BindingTable__GetSizeActiveUserAttributes();
    uVar8 = BindingTable__GetNumActiveUniformBindings();
    uVar9 = BindingTable__GetSizeActiveUserUniforms();
    _sprintf(pcVar4,DAT_a7b7bb44,uVar5,uVar6,uVar7,uVar8,uVar9,pcVar1);
  }
  else {
    sVar2 = _strlen(DAT_a7b7bb40);
    sVar3 = _strlen(pcVar1);
    pcVar4 = _malloc(sVar2 + sVar3 + 0x29);
    *pcVar4 = '\0';
    uVar5 = BindingTable__GetNumActiveAttributeBindings();
    uVar6 = BindingTable__GetSizeActiveAttributes();
    uVar7 = BindingTable__GetSizeActiveUserAttributes();
    uVar8 = BindingTable__GetNumActiveUniformBindings();
    uVar9 = BindingTable__GetSizeActiveUserUniforms();
    _sprintf(pcVar4,DAT_a7b7bb40,*(undefined4 *)(this + 0x74),uVar5,uVar6,uVar7,uVar8,uVar9);
  }
  _free(pcVar1);
  return pcVar4;
}

/* TGenericLinker__GetFullTableString @ 0x97bb4a14 (152 bytes) */
int TGenericLinker__GetFullTableString(this)
  unsigned char * this;
{
  char *pcVar1;
  char *pcVar2;
  size_t sVar3;
  size_t sVar4;
  char *pcVar5;
  
  pcVar1 = (char *)((int (*)())TGenericLinker__GetRemapTableString)(this);
  pcVar2 = (char *)((int (*)())TGenericLinker__GetBindingTableString)(this);
  sVar3 = _strlen(pcVar1);
  sVar4 = _strlen(pcVar2);
  pcVar5 = _malloc(sVar3 + sVar4 + 1);
  *pcVar5 = '\0';
  _sprintf(pcVar5,"%s%s",pcVar2,pcVar1);
  _free(pcVar2);
  _free(pcVar1);
  return pcVar5;
}

/* TGenericLinker__ReportStats @ 0x97bb4aac (4 bytes) */
int TGenericLinker__ReportStats()
{
  return;
}

/* TGenericLinker__InsertClientAttribBinding @ 0x97bb4ab0 (92 bytes) */
int TGenericLinker__InsertClientAttribBinding(param_1)
  unsigned char * param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = BindingTable__FindAttribBinding(*(unsigned char **)(param_1 + 4));
  if (iVar1 == 0) {
    uVar2 = BindingTable__InsertClientAttribBinding(*(unsigned char **)(param_1 + 4));
    return uVar2;
  }
  return 0;
}

/* TGenericLinker__AddAttribBinding @ 0x97bb4b0c (364 bytes) */
int TGenericLinker__AddAttribBinding(param_1, param_2, param_3)
  char *param_1;
  int param_2;
  int param_3;
{
  unsigned char * this;
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  size_t sVar4;
  char *pcVar5;
  
  this = operator_new(0x38);
  Binding__Binding(this);
  if (this == (unsigned char *)0x0) {
    pcVar2 = *(char **)(param_1 + 0x84);
                    
    TInfoSinkBase__append(pcVar2);
    TInfoSinkBase__append(pcVar2);
    TInfoSinkBase__append(pcVar2);
  }
  else {
    Binding__SetName((char *)this);
    iVar1 = BindingTable__FindAttribBinding(*(unsigned char **)(param_1 + 4));
    if (iVar1 == 0) {
      Binding__SetClientRequest(SUB41(this,0));
      Binding__SetOpenGLType((ushort)this);
      Binding__SetDecSize((ulong)this);
      Binding__SetActualSize((ulong)this);
      Binding__SetBuiltIn(SUB41(this,0));
      iVar1 = BindingTable__InsertAttribBinding(*(unsigned char **)(param_1 + 4));
      if (iVar1 != 0) {
        return iVar1;
      }
      pcVar2 = (char *)BindingTable__GetAttribBindingNameByLocation(*(long *)(param_1 + 4));
      sVar3 = _strlen(_linkErrorString);
      sVar4 = _strlen(pcVar2);
      pcVar5 = _malloc(sVar3 + sVar4 + 1);
      _sprintf(pcVar5,_linkErrorString,pcVar2);
      pcVar2 = *(char **)(param_1 + 0x84);
                    
      TInfoSinkBase__append(pcVar2);
      TInfoSinkBase__append(pcVar2);
      TInfoSinkBase__append(pcVar2);
      _free(pcVar5);
      return 0;
    }
    Binding___Binding(this);
    operator_delete(this);
  }
  return 0;
}

/* TGenericLinker__CollectClientAttributeBindings @ 0x97bb4d6c (484 bytes) */
int TGenericLinker__CollectClientAttributeBindings(this)
  unsigned char * this;
{
  ulong uVar1;
  int iVar2;
  size_t sVar3;
  size_t sVar4;
  char *pcVar5;
  char *pcVar6;
  
  if (*(int *)(this + 0x28) == 0) {
    iVar2 = BindingTable__NextAttribRequestBinding(*(unsigned char **)(this + 4));
    while (iVar2 != 0) {
      pcVar6 = *(char **)(iVar2 + 8);
      sVar3 = _strlen(DAT_a7b7bac8);
      sVar4 = _strlen(pcVar6);
      pcVar5 = _malloc(sVar3 + sVar4 + 1);
      _sprintf(pcVar5,DAT_a7b7bac8,pcVar6);
      pcVar6 = *(char **)(this + 0x84);
                    
      TInfoSinkBase__append(pcVar6);
      TInfoSinkBase__append(pcVar6);
      TInfoSinkBase__append(pcVar6);
      _free(pcVar5);
      iVar2 = BindingTable__NextAttribRequestBinding(*(unsigned char **)(this + 4));
    }
  }
  else {
    uVar1 = BindingTable__NextAttribRequestBinding(*(unsigned char **)(this + 4));
    while (uVar1 != 0) {
      iVar2 = ParseSymbolTable__FindGlobalSymbolByName(*(char **)(this + 0x28));
      if (iVar2 == 0) {
        pcVar6 = *(char **)(uVar1 + 8);
        sVar3 = _strlen(DAT_a7b7bac4);
        sVar4 = _strlen(pcVar6);
        pcVar5 = _malloc(sVar3 + sVar4 + 1);
        _sprintf(pcVar5,DAT_a7b7bac4,pcVar6);
        pcVar6 = *(char **)(this + 0x84);
                    
        TInfoSinkBase__append(pcVar6);
        TInfoSinkBase__append(pcVar6);
        TInfoSinkBase__append(pcVar6);
        _free(pcVar5);
      }
      else {
        Binding__SetOpenGLType((ushort)uVar1);
        Binding__SetActualSize(uVar1);
        Binding__SetDecSize(uVar1);
        if (*(int *)(iVar2 + 0x34) == 1) {
          pcVar6 = *(char **)(uVar1 + 8);
          sVar3 = _strlen(DAT_a7b7bb68);
          sVar4 = _strlen(pcVar6);
          pcVar5 = _malloc(sVar3 + sVar4 + 1);
          _sprintf(pcVar5,DAT_a7b7bb68,pcVar6);
          pcVar6 = *(char **)(this + 0x84);
                    
          TInfoSinkBase__append(pcVar6);
          TInfoSinkBase__append(pcVar6);
          TInfoSinkBase__append(pcVar6);
          _free(pcVar5);
        }
        Binding__SetBuiltIn(SUB41(uVar1,0));
        InsertClientAttribBinding((unsigned char *)this);
      }
      uVar1 = BindingTable__NextAttribRequestBinding(*(unsigned char **)(this + 4));
    }
  }
  return 1;
}

/* TGenericLinker__CollectAttributeBindings @ 0x97bb50dc (996 bytes) */
int TGenericLinker__CollectAttributeBindings(this)
  unsigned char * this;
{
  short sVar1;
  undefined4 *puVar2;
  
  if (*(unsigned char **)(this + 0x28) != (unsigned char *)0x0) {
    puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
    while (puVar2 != (undefined4 *)0x0) {
      if (((*(char *)*puVar2 == '\x02') && (*(short *)(puVar2 + 0xb) == -0x74a4)) &&
         (puVar2[0xd] == 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)puVar2[5],true);
      }
      puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
    }
    puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
    while (puVar2 != (undefined4 *)0x0) {
      if (((*(char *)*puVar2 == '\x02') && (*(short *)(puVar2 + 0xb) == -0x74a5)) &&
         (puVar2[0xd] == 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)puVar2[5],true);
      }
      puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
    }
    puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
    while (puVar2 != (undefined4 *)0x0) {
      if (((*(char *)*puVar2 == '\x02') && (*(short *)(puVar2 + 0xb) == -0x74a6)) &&
         (puVar2[0xd] == 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)puVar2[5],true);
      }
      puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
    }
    puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
    while (puVar2 != (undefined4 *)0x0) {
      if ((((*(char *)*puVar2 == '\x02') && (sVar1 = *(short *)(puVar2 + 0xb), sVar1 != -0x74a4)) &&
          (sVar1 != -0x74a5)) && ((sVar1 != -0x74a6 && (puVar2[0xd] == 0)))) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)puVar2[5],SUB21(sVar1,0));
      }
      puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
    }
    puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
    while (puVar2 != (undefined4 *)0x0) {
      if (((*(char *)*puVar2 == '\x02') && (*(short *)(puVar2 + 0xb) == -0x74a4)) &&
         (puVar2[0xd] != 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)puVar2[5],true);
      }
      puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
    }
    puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
    while (puVar2 != (undefined4 *)0x0) {
      if (((*(char *)*puVar2 == '\x02') && (*(short *)(puVar2 + 0xb) == -0x74a5)) &&
         (puVar2[0xd] != 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)puVar2[5],true);
      }
      puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
    }
    puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
    while (puVar2 != (undefined4 *)0x0) {
      if (((*(char *)*puVar2 == '\x02') && (*(short *)(puVar2 + 0xb) == -0x74a6)) &&
         (puVar2[0xd] != 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)puVar2[5],true);
      }
      puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
    }
    puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
    while (puVar2 != (undefined4 *)0x0) {
      if (((*(char *)*puVar2 == '\x02') && (sVar1 = *(short *)(puVar2 + 0xb), sVar1 != -0x74a4)) &&
         ((sVar1 != -0x74a5 && ((sVar1 != -0x74a6 && (puVar2[0xd] != 0)))))) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)puVar2[5],SUB21(sVar1,0));
      }
      puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
    }
  }
  return 1;
}

/* TGenericLinker__RemapVertexAttributes @ 0x97bb54c0 (400 bytes) */
int TGenericLinker__RemapVertexAttributes(this)
  unsigned char * this;
{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  size_t sVar4;
  size_t sVar5;
  int iVar6;
  ushort uVar8;
  uint uVar7;
  char *pcVar9;
  undefined4 uVar10;
  char *pcVar11;
  uint uVar12;
  
  uVar10 = 1;
  iVar2 = BindingTable__NextAttribBinding(*(unsigned char **)(this + 4));
joined_r0x97bb54f0:
  if (iVar2 == 0) {
    return uVar10;
  }
  iVar2 = Binding__IsBuiltIn();
  if (((iVar2 == 0) && (*(char **)(this + 0x28) != (char *)0x0)) &&
     (puVar3 = (undefined4 *)ParseSymbolTable__FindGlobalSymbolByName(*(char **)(this + 0x28)),
     puVar3 != (undefined4 *)0x0)) {
    pcVar9 = (char *)*puVar3;
    if (*pcVar9 != '\x02') {
      pcVar11 = (char *)puVar3[5];
      sVar4 = _strlen(DAT_a7b7bb6c);
      sVar5 = _strlen(pcVar11);
      pcVar9 = _malloc(sVar4 + sVar5 + 1);
      _sprintf(pcVar9,DAT_a7b7bb6c,pcVar11);
      pcVar11 = *(char **)(this + 0x84);
                    
      TInfoSinkBase__append(pcVar11);
      TInfoSinkBase__append(pcVar11);
      TInfoSinkBase__append(pcVar11);
      _free(pcVar9);
      uVar10 = 0;
      pcVar9 = (char *)*puVar3;
    }
    if ((*pcVar9 == '\x02') && ((*(uint *)(pcVar9 + 0xc) & 0xf0000) == 0x90000)) {
      sVar1 = *(short *)(pcVar9 + 0x12);
      iVar6 = Binding__GetLocation();
      for (iVar2 = **(int **)(*(int *)(this + 0x30) + 0x18); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)
          ) {
        uVar12 = 0;
        if (*(short *)(iVar2 + 0x12) == sVar1) goto LAB_97bb567c;
      }
    }
  }
  goto LAB_97bb56a8;
LAB_97bb567c:
  while( true ) {
    uVar8 = Binding__GetOpenGLType();
    uVar7 = ((int (*)())GetVec4sForType)(uVar8);
    if ((uVar7 <= uVar12) || (iVar2 == 0)) break;
    uVar7 = iVar6 + uVar12;
    uVar12 = uVar12 + 1;
    *(uint *)(iVar2 + 0xc) = uVar7 & 0x1f | *(uint *)(iVar2 + 0xc) & 0xffffffe0;
    iVar2 = *(int *)(iVar2 + 8);
  }
LAB_97bb56a8:
  iVar2 = BindingTable__NextAttribBinding(*(unsigned char **)(this + 4));
  goto joined_r0x97bb54f0;
}

/* TGenericLinker__AllocateTextureUnitsForVaryings @ 0x97bb56d4 (4688 bytes) */
int TGenericLinker__AllocateTextureUnitsForVaryings(this)
  unsigned char * this;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  unsigned char * pPVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  size_t sVar9;
  char *pcVar10;
  void *pvVar11;
  int *piVar12;
  uint uVar13;
  int *piVar14;
  void *pvVar15;
  int iVar16;
  short sVar23;
  int iVar17;
  size_t sVar18;
  size_t sVar19;
  size_t sVar20;
  undefined4 uVar21;
  undefined4 uVar22;
  uint uVar24;
  uint uVar25;
  int *piVar26;
  int iVar27;
  undefined4 uVar28;
  ushort uVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  char *pcVar33;
  uint uVar34;
  uint local_e0 [4];
  uint local_d0 [4];
  undefined4 local_c0;
  uint local_bc;
  uint local_b8;
  uint local_b4;
  uint local_b0;
  uint local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  uint local_80;
  undefined4 local_7c;
  uint local_70;
  undefined4 local_6c;
  uint local_60;
  int local_5c;
  undefined4 *local_58;
  
  *(undefined4 *)(this + 0x74) = 0xffffffff;
  *(undefined4 *)(this + 0x78) = 0;
  uVar28 = 1;
  iVar32 = 0;
  iVar31 = 0;
  iVar30 = 0;
  if (*(unsigned char **)(this + 0x28) != (unsigned char *)0x0) {
    puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
    while (puVar8 != (undefined4 *)0x0) {
      if ((*(char *)*puVar8 == '\x04') &&
         (uVar25 = *(uint *)((char *)*puVar8 + 0xc), (uVar25 & 0xf0000) == 0x60000)) {
        uVar25 = uVar25 & 0x1f;
        *(uint *)(this + 0x78) = *(uint *)(this + 0x78) | 1 << uVar25;
        if (*(int *)(this + 0x74) < (int)uVar25) {
          *(uint *)(this + 0x74) = uVar25;
        }
        iVar32 = iVar32 + 1;
      }
      puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
    }
  }
  pPVar5 = *(unsigned char **)(this + 0x2c);
  if (pPVar5 != (unsigned char *)0x0) {
    iVar31 = *(int *)(pPVar5 + 0x1c);
    iVar30 = *(int *)(pPVar5 + 0x20);
    puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(pPVar5);
    while (puVar8 != (undefined4 *)0x0) {
      if ((*(char *)*puVar8 == '\x02') &&
         (uVar25 = *(uint *)((char *)*puVar8 + 0xc), (uVar25 & 0xf0000) == 0x70000)) {
        uVar25 = uVar25 & 0x1f;
        if (*(int *)(this + 0x74) < (int)uVar25) {
          *(uint *)(this + 0x74) = uVar25;
        }
        if ((*(uint *)(this + 0x78) & 1 << uVar25) == 0) {
          iVar32 = iVar32 + 1;
        }
        *(uint *)(this + 0x78) = *(uint *)(this + 0x78) | 1 << uVar25;
      }
      puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x2c));
    }
  }
  if (iVar31 != 0) {
    if ((*(int *)(this + 0x28) == 0) || (*(int *)(this + 0x2c) == 0)) {
      if (*(unsigned char **)(this + 0x2c) != (unsigned char *)0x0) {
        puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x2c));
        while (puVar8 != (undefined4 *)0x0) {
          if ((*(char *)*puVar8 == '\0') && (puVar8[0x18] != 0)) {
            pcVar33 = (char *)puVar8[5];
            sVar9 = _strlen(DAT_a7b7badc);
            sVar18 = _strlen(pcVar33);
            pcVar10 = _malloc(sVar9 + sVar18 + 1);
            _sprintf(pcVar10,DAT_a7b7badc,pcVar33);
            pcVar33 = *(char **)(this + 0x84);
                    
            TInfoSinkBase__append(pcVar33);
            TInfoSinkBase__append(pcVar33);
            TInfoSinkBase__append(pcVar33);
            uVar28 = 0;
            _free(pcVar10);
          }
          puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
        }
      }
    }
    else {
      iVar31 = 1;
      iVar30 = iVar32 * 4 + iVar30;
      if (iVar30 < 0x21) {
        pvVar11 = _malloc(0x80);
        _memset(pvVar11,0,0x80);
        puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x2c));
        while (puVar8 != (undefined4 *)0x0) {
          if ((*(char *)*puVar8 == '\x02') &&
             (uVar25 = *(uint *)((char *)*puVar8 + 0xc), (uVar25 & 0xf0000) == 0x70000)) {
            iVar32 = (uVar25 & 0x1f) * 0x10;
            iVar30 = -iVar31;
            *(int *)((int)pvVar11 + iVar32) = iVar30;
            iVar31 = iVar31 + 1;
            *(int *)((int)pvVar11 + iVar32 + 0xc) = iVar30;
            *(int *)((int)pvVar11 + iVar32 + 4) = iVar30;
            *(int *)((int)pvVar11 + iVar32 + 8) = iVar30;
          }
          puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x2c));
        }
        puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
        while (puVar8 != (undefined4 *)0x0) {
          if ((*(char *)*puVar8 == '\x04') &&
             (uVar25 = *(uint *)((char *)*puVar8 + 0xc), (uVar25 & 0xf0000) == 0x60000)) {
            iVar32 = (uVar25 & 0x1f) * 0x10;
            iVar30 = -iVar31;
            *(int *)((int)pvVar11 + iVar32) = iVar30;
            iVar31 = iVar31 + 1;
            *(int *)((int)pvVar11 + iVar32 + 0xc) = iVar30;
            *(int *)((int)pvVar11 + iVar32 + 4) = iVar30;
            *(int *)((int)pvVar11 + iVar32 + 8) = iVar30;
          }
          puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28));
        }
        uVar25 = 4;
        do {
          piVar12 = (int *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x2c));
          while (piVar12 != (int *)0x0) {
            if (((*(char *)*piVar12 == '\0') && (piVar12[0x18] != 0)) &&
               (uVar13 = ((int (*)())GetScalerWidthForType)(*(ushort *)(piVar12 + 0xb)), uVar25 == uVar13)) {
              piVar14 = (int *)ParseSymbolTable__FindGlobalSymbolByName(*(char **)(this + 0x28));
              if (((piVar14 == (int *)0x0) ||
                  (uVar29 = *(ushort *)(piVar12 + 0xb), uVar29 != *(ushort *)(piVar14 + 0xb))) ||
                 ((*(char *)*piVar14 != '\0' || (local_60 = 0, piVar14[0x17] == 0)))) {
                uVar28 = 0;
                if (piVar14 == (int *)0x0) {
LAB_97bb689c:
                  pcVar33 = (char *)piVar12[5];
                  sVar9 = _strlen(DAT_a7b7bad4);
                  sVar18 = _strlen(pcVar33);
                  pcVar10 = _malloc(sVar9 + sVar18 + 1);
                  _sprintf(pcVar10,DAT_a7b7bad4,pcVar33);
                  pcVar33 = *(char **)(this + 0x84);
                    
                }
                else if (*(short *)(piVar12 + 0xb) == *(short *)(piVar14 + 0xb)) {
                  if ((*(char *)*piVar14 == '\0') && (piVar14[0x17] == 0)) goto LAB_97bb689c;
                  pcVar33 = (char *)piVar12[5];
                  sVar9 = _strlen(DAT_a7b7bb70);
                  sVar18 = _strlen(pcVar33);
                  pcVar10 = _malloc(sVar9 + sVar18 + 1);
                  _sprintf(pcVar10,DAT_a7b7bb70,pcVar33);
                  pcVar33 = *(char **)(this + 0x84);
                    
                }
                else {
                  pcVar33 = (char *)piVar12[5];
                  sVar9 = _strlen(DAT_a7b7bad0);
                  sVar18 = _strlen(pcVar33);
                  pcVar10 = (char *)((int (*)())GetShaderStringForType)(*(ushort *)(piVar14 + 0xb));
                  sVar19 = _strlen(pcVar10);
                  pcVar10 = (char *)((int (*)())GetShaderStringForType)(*(ushort *)(piVar12 + 0xb));
                  sVar20 = _strlen(pcVar10);
                  pcVar10 = _malloc(sVar9 + sVar18 + sVar19 + sVar20 + 1);
                  uVar21 = ((int (*)())GetShaderStringForType)(*(ushort *)(piVar12 + 0xb));
                  uVar22 = ((int (*)())GetShaderStringForType)(*(ushort *)(piVar14 + 0xb));
                  _sprintf(pcVar10,DAT_a7b7bad0,pcVar33,uVar22,uVar21);
                  pcVar33 = *(char **)(this + 0x84);
                    
                }
                TInfoSinkBase__append(pcVar33);
                TInfoSinkBase__append(pcVar33);
                TInfoSinkBase__append(pcVar33);
                _free(pcVar10);
              }
              else {
                while (uVar13 = ((int (*)())GetVec4sForType)(uVar29), local_60 < uVar13) {
                  local_d0[3] = DAT_97c38fac;
                  local_e0[3] = DAT_97c38fac;
                  local_d0[0] = DAT_97c38fa0;
                  iVar32 = 0;
                  local_d0[1] = DAT_97c38fa4;
                  local_d0[2] = DAT_97c38fa8;
                  local_e0[0] = DAT_97c38fa0;
                  local_e0[1] = DAT_97c38fa4;
                  local_e0[2] = DAT_97c38fa8;
                  do {
                    bVar1 = true;
                    if (uVar25 == 2) {
                      iVar30 = iVar32 << 2;
LAB_97bb5b68:
                      if (*(int *)((int)pvVar11 + iVar30 + 4) == 0) {
LAB_97bb5b80:
                        if (*(int *)(iVar30 + (int)pvVar11) == 0) goto LAB_97bb5b90;
                      }
LAB_97bb5b8c:
                      bVar1 = false;
                    }
                    else {
                      if (2 < uVar25) {
                        if (uVar25 == 3) {
                          iVar30 = iVar32 << 2;
LAB_97bb5b50:
                          if (*(int *)((int)pvVar11 + iVar30 + 8) == 0) goto LAB_97bb5b68;
                        }
                        else {
                          if (uVar25 != 4) goto LAB_97bb5b90;
                          iVar30 = iVar32 * 4;
                          if (*(int *)((int)pvVar11 + iVar30 + 0xc) == 0) goto LAB_97bb5b50;
                        }
                        goto LAB_97bb5b8c;
                      }
                      if (uVar25 == 1) {
                        iVar30 = iVar32 << 2;
                        goto LAB_97bb5b80;
                      }
                    }
LAB_97bb5b90:
                    bVar1 = !bVar1;
                    if ((!bVar1) && (uVar13 = 0, uVar25 != 0)) {
                      piVar26 = (int *)(iVar32 * 4 + (int)pvVar11);
                      puVar6 = local_e0;
                      uVar34 = uVar25;
                      do {
                        uVar2 = *(uint *)(this + 0x78);
                        puVar6[4] = uVar13;
                        uVar13 = uVar13 + 1;
                        *(uint *)(this + 0x78) = uVar2 | 1 << (iVar32 >> 2 & 0x3fU);
                        *puVar6 = iVar32 >> 2;
                        puVar6 = puVar6 + 1;
                        *piVar26 = iVar31;
                        piVar26 = piVar26 + 1;
                        uVar34 = uVar34 - 1;
                      } while (uVar34 != 0);
                    }
                    iVar32 = iVar32 + 4;
                  } while ((iVar32 < 0x20) && (bVar1));
                  iVar32 = 0;
                  if (bVar1) {
                    do {
                      uVar13 = 1;
                      if (-uVar25 == -4) {
LAB_97bb5ccc:
                        if (!bVar1) goto LAB_97bb5cd0;
                      }
                      else {
                        if (bVar1) {
                          do {
                            bVar1 = true;
                            if (uVar25 == 2) {
LAB_97bb5c80:
                              if (*(int *)((int)pvVar11 + (iVar32 + uVar13) * 4 + 4) == 0) {
LAB_97bb5c9c:
                                if (*(int *)((int)pvVar11 + (iVar32 + uVar13) * 4) == 0)
                                goto LAB_97bb5cb0;
                              }
LAB_97bb5cac:
                              bVar1 = false;
                            }
                            else if (uVar25 < 3) {
                              if (uVar25 == 1) goto LAB_97bb5c9c;
                            }
                            else if (uVar25 == 3) {
                              if (*(int *)((int)pvVar11 + (iVar32 + uVar13) * 4 + 8) == 0)
                              goto LAB_97bb5c80;
                              goto LAB_97bb5cac;
                            }
LAB_97bb5cb0:
                            uVar13 = uVar13 + 1;
                            if (-uVar25 + 4 < uVar13) {
                              bVar1 = !bVar1;
                              goto LAB_97bb5ccc;
                            }
                          } while (!bVar1);
                          bVar1 = false;
                        }
LAB_97bb5cd0:
                        iVar30 = 0;
                        if (uVar25 != 0) {
                          piVar26 = (int *)((iVar32 + (uVar13 - 1)) * 4 + (int)pvVar11);
                          puVar6 = local_e0;
                          uVar34 = uVar25;
                          do {
                            uVar2 = *(uint *)(this + 0x78);
                            puVar6[4] = iVar30 + (uVar13 - 1);
                            iVar30 = iVar30 + 1;
                            *(uint *)(this + 0x78) = uVar2 | 1 << (iVar32 >> 2 & 0x3fU);
                            *puVar6 = iVar32 >> 2;
                            puVar6 = puVar6 + 1;
                            *piVar26 = iVar31;
                            piVar26 = piVar26 + 1;
                            uVar34 = uVar34 - 1;
                          } while (uVar34 != 0);
                        }
                      }
                      iVar32 = iVar32 + 4;
                    } while ((iVar32 < 0x20) && (bVar1));
                  }
                  uVar13 = 0;
                  if ((uVar25 != 0) && (bVar1)) {
                    do {
                      uVar34 = 0;
                      uVar2 = 0;
                      if (bVar1) {
                        do {
                          uVar24 = uVar34;
                          if (*(int *)(uVar2 * 4 + (int)pvVar11) == 0) {
                            uVar3 = ((int)uVar2 >> 2) + (uint)((int)uVar2 < 0 && (uVar2 & 3) != 0);
                            local_e0[uVar34] = uVar3;
                            uVar24 = uVar34 + 1;
                            *(uint *)(this + 0x78) = *(uint *)(this + 0x78) | 1 << (uVar3 & 0x3f);
                            local_d0[uVar34] = uVar2 + uVar3 * -4;
                            *(int *)(uVar2 * 4 + (int)pvVar11) = iVar31;
                          }
                          if (uVar24 == uVar25) {
                            bVar1 = false;
                          }
                          uVar2 = uVar2 + 1;
                        } while (((int)uVar2 < 0x20) && (uVar34 = uVar24, bVar1));
                      }
                      uVar13 = uVar13 + 1;
                    } while ((uVar13 < uVar25) && (bVar1));
                  }
                  iVar31 = iVar31 + 1;
                  if (bVar1) {
                    uVar28 = 0;
                    pcVar10 = *(char **)(this + 0x84);
                    
                    TInfoSinkBase__append(pcVar10);
                    TInfoSinkBase__append(pcVar10);
                    TInfoSinkBase__append(pcVar10);
                  }
                  else {
                    iVar32 = *(int *)(this + 0x38);
                    local_5c = 0;
                    uVar13 = 0;
                    if ((iVar32 != 0) && (*(int *)(iVar32 + 4) != 0)) {
                      while( true ) {
                        pvVar15 = (void *)FunctionTable__getFunctionName(iVar32);
                        iVar32 = _memcmp(pvVar15,"main(",6);
                        if (iVar32 == 0) break;
                        iVar32 = *(int *)(this + 0x38);
                        uVar13 = uVar13 + 1;
                        if ((iVar32 == 0) || (*(uint *)(iVar32 + 4) <= uVar13)) break;
                      }
                    }
                    for (iVar32 = **(int **)(*(int *)(this + 0x30) + 0x20); iVar32 != 0;
                        iVar32 = *(int *)(iVar32 + 8)) {
                      uVar13 = FunctionTable__getFirstOp(*(int *)(this + 0x38));
                      if (uVar13 == (*(uint *)(iVar32 + 0xc) & 0x3ffff)) {
                        local_5c = 1;
                      }
                      if (((local_5c != 0) && ((*(uint *)(iVar32 + 0xc) & 0x3fc0000) == 0x1340000))
                         && (uVar13 = 0, uVar25 != 0)) {
                        iVar30 = 0;
                        local_58 = &local_c0;
LAB_97bb5ec0:
                        iVar16 = *(int *)(this + 0x30);
                        uVar34 = 0;
                        uVar2 = *(uint *)((int)local_e0 + iVar30);
                        for (iVar27 = **(int **)(iVar16 + 0x1c); iVar27 != 0;
                            iVar27 = *(int *)(iVar27 + 8)) {
                          if (((*(uint *)(iVar27 + 0xc) & 0xf0000) == 0x60000) &&
                             ((*(uint *)(iVar27 + 0xc) & 0x1f) == uVar2)) {
                            uVar29 = *(ushort *)(iVar27 + 0x12);
                            uVar24 = 3;
                            piVar26 = (int *)((int)pvVar11 + uVar2 * 0x10 + 0xc);
                            goto LAB_97bb5f28;
                          }
                        }
                        local_7c = 0;
                        local_80 = uVar2 & 0x1f | 0x4060000;
                        piVar26 = (int *)((int)pvVar11 + uVar2 * 0x10 + 0xc);
                        uVar24 = 3;
                        do {
                          iVar27 = *piVar26;
                          piVar26 = piVar26 + -1;
                          if (iVar27 != 0) {
                            local_80 = (uVar24 & 3) << 0x18 | uVar2 & 0x1f | 0x4060000;
                            break;
                          }
                          uVar24 = uVar24 - 1;
                        } while (-1 < (int)uVar24);
                        sVar23 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(iVar16 + 0x1c));
                        uVar29 = sVar23 + 1;
                        local_7c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_7c) + 0)),uVar29);
                        _PPStreamAddOutputBinding(*(undefined4 *)(this + 0x30),&local_80);
LAB_97bb5fe4:
                        iVar16 = *(int *)(this + 0x30);
                        goto LAB_97bb5fe8;
                      }
LAB_97bb61d0:
                      uVar13 = FunctionTable__getLastOp(*(int *)(this + 0x38));
                      if (uVar13 == (*(uint *)(iVar32 + 0xc) & 0x3ffff)) break;
                    }
                    iVar32 = *(int *)(this + 0x3c);
                    uVar13 = 0;
                    if ((iVar32 != 0) && (*(int *)(iVar32 + 4) != 0)) {
                      while( true ) {
                        pvVar15 = (void *)FunctionTable__getFunctionName(iVar32);
                        iVar32 = _memcmp(pvVar15,"main(",6);
                        if (iVar32 == 0) break;
                        iVar32 = *(int *)(this + 0x3c);
                        uVar13 = uVar13 + 1;
                        if ((iVar32 == 0) || (*(uint *)(iVar32 + 4) <= uVar13)) break;
                      }
                    }
                    for (iVar32 = **(int **)(*(int *)(this + 0x34) + 0x20); iVar32 != 0;
                        iVar32 = *(int *)(iVar32 + 8)) {
                      uVar34 = FunctionTable__getFirstOp(*(int *)(this + 0x3c));
                      if (uVar34 == (*(uint *)(iVar32 + 0xc) & 0x3ffff)) {
                        uVar34 = 0;
                        if (uVar25 != 0) {
                          local_58 = &local_c0;
                          iVar30 = 0;
                          goto LAB_97bb62a8;
                        }
                        break;
                      }
                    }
                  }
LAB_97bb6720:
                  uVar29 = *(ushort *)(piVar12 + 0xb);
                  local_60 = local_60 + 1;
                }
              }
            }
            piVar12 = (int *)ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x2c));
          }
          uVar25 = uVar25 - 1;
        } while (uVar25 != 0);
        iVar32 = 0;
        *(undefined4 *)(this + 0x74) = 0xffffffff;
        iVar30 = 8;
        do {
          iVar31 = iVar32 * 4;
          if ((((*(int *)((int)pvVar11 + iVar31) != 0) || (*(int *)((int)pvVar11 + iVar31 + 4) != 0)
               ) || (*(int *)((int)pvVar11 + iVar31 + 8) != 0)) ||
             (*(int *)((int)pvVar11 + iVar31 + 0xc) != 0)) {
            *(int *)(this + 0x74) = iVar32 >> 2;
          }
          iVar32 = iVar32 + 4;
          iVar30 = iVar30 + -1;
        } while (iVar30 != 0);
        if (pvVar11 != (void *)0x0) {
          _free(pvVar11);
        }
      }
      else {
        sVar9 = _strlen(DAT_a7b7bb00);
        pcVar10 = _malloc(sVar9 + 0x11);
        _sprintf(pcVar10,DAT_a7b7bb00,0x20,iVar30);
        pcVar33 = *(char **)(this + 0x84);
                    
        TInfoSinkBase__append(pcVar33);
        TInfoSinkBase__append(pcVar33);
        TInfoSinkBase__append(pcVar33);
        _free(pcVar10);
        uVar28 = 0;
      }
    }
  }
  return uVar28;
  while (uVar24 = uVar24 - 1, -1 < (int)uVar24) {
LAB_97bb5f28:
    iVar17 = *piVar26;
    piVar26 = piVar26 + -1;
    if (iVar17 != 0) {
      *(uint *)(iVar27 + 0xc) = (uVar24 & 3) << 0x18 | *(uint *)(iVar27 + 0xc) & 0xfcffffff;
      goto LAB_97bb5fe4;
    }
  }
LAB_97bb5fe8:
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  local_bc = 0;
  uVar24 = 0x60000;
  uVar3 = 0x800000;
  local_c0 = 0x20000000;
  local_b0 = 0x800000;
  local_b8 = 0x60000;
  local_90 = *(undefined4 *)(iVar32 + 0x3c);
  local_b4 = (uint)uVar29;
  local_8c = 0;
  local_ac = (uint)(ushort)(*(short *)(*piVar14 + 0x12) + (short)local_60);
  uVar7 = *(uint *)((int)local_e0 + iVar30);
  while ((uVar7 == uVar2 && (uVar13 < uVar25))) {
    uVar7 = *(uint *)((int)local_d0 + iVar30);
    if (uVar7 == 1) {
      uVar24 = (uVar34 & 3) << 6 | uVar24 & 0xffffff3f | 0x4000;
LAB_97bb60fc:
      uVar24 = (uVar7 & 3) << 10 | uVar24 & 0xfffff3ff;
      local_b8 = uVar24;
    }
    else {
      if (1 < (int)uVar7) {
        if (uVar7 == 2) {
          uVar24 = (uVar34 & 3) << 4 | uVar24 & 0xffffffcf | 0x8000;
        }
        else {
          if (uVar7 != 3) goto LAB_97bb6108;
          uVar24 = (uVar34 & 3) << 2 | uVar24 & 0xfffffff3 | 0x10000;
        }
        goto LAB_97bb60fc;
      }
      if (uVar7 == 0) {
        uVar24 = (uVar34 & 3) << 8 | uVar24 & 0xfffffcff | 0x2000;
        goto LAB_97bb60fc;
      }
    }
LAB_97bb6108:
    if (uVar34 == 1) {
      uVar3 = (uVar13 & 3) << 0x13 | uVar3 & 0xffe7ffff;
LAB_97bb6150:
      local_b0 = uVar3;
    }
    else {
      if (1 < (int)uVar34) {
        if (uVar34 == 2) {
          uVar3 = (uVar13 & 3) << 0x11 | uVar3 & 0xfff9ffff;
        }
        else {
          if (uVar34 != 3) goto LAB_97bb6154;
          uVar3 = (uVar13 & 3) << 0xf | uVar3 & 0xfffe7fff;
        }
        goto LAB_97bb6150;
      }
      if (uVar34 == 0) {
        uVar3 = (uVar13 & 3) << 0x15 | uVar3 & 0xff9fffff;
        goto LAB_97bb6150;
      }
    }
LAB_97bb6154:
    uVar13 = uVar13 + 1;
    uVar34 = uVar34 + 1;
    iVar30 = uVar13 * 4;
    uVar7 = local_e0[uVar13];
  }
  local_b0 = (uVar34 - 1) * 0x1000 & 0x3000 | uVar3;
  local_bc = (uVar34 - 1) * 0x4000000 & 0xc000000 | 0x800000;
  iVar27 = _PPStreamInsertOperationAfterChunk(iVar16,local_58,0,0,*(undefined4 *)(iVar32 + 4));
  _PPStreamChangeBranchTargets
            (*(undefined4 *)(this + 0x30),*(uint *)(iVar32 + 0xc) & 0x3ffff,
             *(uint *)(iVar27 + 0xc) & 0x3ffff);
  if (uVar25 <= uVar13) goto LAB_97bb61d0;
  goto LAB_97bb5ec0;
LAB_97bb62a8:
  uVar2 = 0;
  uVar24 = *(uint *)((int)local_e0 + iVar30);
  for (iVar27 = **(int **)(*(int *)(this + 0x34) + 0x18); iVar27 != 0; iVar27 = *(int *)(iVar27 + 8)
      ) {
    if (((*(uint *)(iVar27 + 0xc) & 0xf0000) == 0x70000) &&
       ((*(uint *)(iVar27 + 0xc) & 0x1f) == uVar24)) {
      uVar29 = *(ushort *)(iVar27 + 0x12);
      uVar3 = 3;
      piVar26 = (int *)((int)pvVar11 + uVar24 * 0x10 + 0xc);
      goto LAB_97bb630c;
    }
  }
  local_6c = 0;
  local_70 = uVar24 & 0x1f | 0x4070000;
  piVar26 = (int *)((int)pvVar11 + uVar24 * 0x10 + 0xc);
  uVar3 = 3;
  do {
    iVar27 = *piVar26;
    piVar26 = piVar26 + -1;
    if (iVar27 != 0) {
      local_70 = (uVar3 & 3) << 0x18 | uVar24 & 0x1f | 0x4070000;
      break;
    }
    uVar3 = uVar3 - 1;
  } while (-1 < (int)uVar3);
  sVar23 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(*(int *)(this + 0x34) + 0x18));
  uVar29 = sVar23 + 1;
  local_6c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_6c) + 0)),uVar29);
  _PPStreamAddAttribBinding(*(undefined4 *)(this + 0x34),&local_70);
  goto LAB_97bb63d0;
  while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
LAB_97bb630c:
    iVar16 = *piVar26;
    piVar26 = piVar26 + -1;
    if (iVar16 != 0) {
      *(uint *)(iVar27 + 0xc) = (uVar3 & 3) << 0x18 | *(uint *)(iVar27 + 0xc) & 0xfcffffff;
      break;
    }
  }
LAB_97bb63d0:
  local_a8 = 0;
  local_a4 = 0;
  local_a0 = 0;
  local_9c = 0;
  local_98 = 0;
  local_94 = 0;
  local_b4 = 0;
  local_bc = 0;
  uVar7 = 0x20000;
  local_c0 = 0x20000000;
  local_b8 = 0x20000;
  local_90 = *(undefined4 *)(iVar32 + 0x3c);
  local_8c = 0;
  uVar3 = 0;
  local_ac = (uint)uVar29;
  local_b0 = 0;
  uVar4 = *(uint *)((int)local_e0 + iVar30);
  local_b4 = (uint)(ushort)(*(short *)(*piVar12 + 0x12) + (short)local_60);
  while ((uVar4 == uVar24 && (uVar34 < uVar25))) {
    if (uVar2 == 1) {
      uVar7 = (uVar34 & 3) << 6 | uVar7 & 0xffffff3f | 0x4000;
LAB_97bb64dc:
      local_b8 = uVar7;
    }
    else {
      if (1 < (int)uVar2) {
        if (uVar2 == 2) {
          uVar7 = (uVar34 & 3) << 4 | uVar7 & 0xffffffcf | 0x8000;
        }
        else {
          if (uVar2 != 3) goto LAB_97bb64e0;
          uVar7 = (uVar34 & 3) << 2 | uVar7 & 0xfffffff3 | 0x10000;
        }
        uVar7 = (uVar2 & 3) << 10 | uVar7 & 0xfffff3ff;
        goto LAB_97bb64dc;
      }
      if (uVar2 == 0) {
        uVar7 = (uVar34 & 3) << 8 | uVar7 & 0xfffffcff | 0x2000;
        goto LAB_97bb64dc;
      }
    }
LAB_97bb64e0:
    if (uVar2 == 1) {
      uVar3 = (*(uint *)((int)local_d0 + iVar30) & 3) << 0x13 | uVar3 & 0xffe7ffff;
LAB_97bb6544:
      local_b0 = uVar3;
    }
    else {
      if (1 < (int)uVar2) {
        if (uVar2 == 2) {
          uVar3 = (*(uint *)((int)local_d0 + iVar30) & 3) << 0x11 | uVar3 & 0xfff9ffff;
        }
        else {
          if (uVar2 != 3) goto LAB_97bb6548;
          uVar3 = (*(uint *)((int)local_d0 + iVar30) & 3) << 0xf | uVar3 & 0xfffe7fff;
        }
        goto LAB_97bb6544;
      }
      if (uVar2 == 0) {
        uVar3 = (*(uint *)((int)local_d0 + iVar30) & 3) << 0x15 | uVar3 & 0xff9fffff;
        goto LAB_97bb6544;
      }
    }
LAB_97bb6548:
    uVar34 = uVar34 + 1;
    uVar2 = uVar2 + 1;
    iVar30 = uVar34 * 4;
    uVar4 = local_e0[uVar34];
  }
  iVar27 = uVar2 - 1;
  local_b0 = iVar27 * 0x1000 & 0x3000U | uVar3;
  local_b8 = iVar27 * 0x400 & 0xc00U | uVar7 & 0xfffff3ff;
  local_bc = iVar27 * 0x4000000 & 0xc000000U | 0x800000;
  uVar2 = FunctionTable__getFirstOp(*(int *)(this + 0x3c));
  if (uVar2 == (*(uint *)(iVar32 + 0xc) & 0x3ffff)) {
    iVar27 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(*(int *)(this + 0x34) + 0x20));
    *(uint *)(iVar32 + 0xc) = iVar27 + 1U & 0x3ffff | *(uint *)(iVar32 + 0xc) & 0xfffc0000;
    uVar21 = FunctionTable__getFirstOp(*(int *)(this + 0x3c));
    _PPStreamChangeBranchTargets
              (*(undefined4 *)(this + 0x34),uVar21,*(uint *)(iVar32 + 0xc) & 0x3ffff);
  }
  iVar27 = _PPStreamInsertOperationAfterChunk
                     (*(undefined4 *)(this + 0x34),local_58,0,1,*(undefined4 *)(iVar32 + 4));
  if (iVar27 != 0) {
    FunctionTable__setFirstOp(*(int *)(this + 0x3c),uVar13);
    for (iVar16 = **(int **)(*(int *)(this + 0x34) + 0x24); iVar32 = iVar27, iVar16 != 0;
        iVar16 = *(int *)(iVar16 + 8)) {
      iVar17 = _memcmp("main(",(void *)(iVar16 + 0x14),6);
      if (iVar17 == 0) {
        *(undefined4 *)(iVar16 + 0xc) = 0;
        break;
      }
    }
  }
  if (uVar25 <= uVar34) goto LAB_97bb6720;
  goto LAB_97bb62a8;
}

/* TGenericLinker__CoalesceCommonUniforms @ 0x97bb6b48 (484 bytes) */
int TGenericLinker__CoalesceCommonUniforms(this)
  unsigned char * this;
{
  char cVar1;
  uint uVar2;
  undefined4 *puVar3;
  unsigned char * p_Var4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  unsigned char * pTVar10;
  char *pcVar11;
  undefined8 local_70;
  uint local_60;
  uint uStack_5c;
  
  iVar8 = 0;
  iVar7 = 0;
  pTVar10 = this;
  do {
    if (*(unsigned char **)(pTVar10 + 0x28) != (unsigned char *)0x0) {
      puVar3 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(pTVar10 + 0x28));
      while (puVar3 != (undefined4 *)0x0) {
        pcVar11 = (char *)*puVar3;
        if ((pcVar11 != (char *)0x0) && (*pcVar11 == '\x03')) {
          (*(unsigned int *)((unsigned char *)&(local_70) + 0)) = (uint)(*(ulonglong *)(pcVar11 + 0xc) >> 0x20);
          uVar2 = ((*(unsigned int *)((unsigned char *)&(local_70) + 0)) & 0xfcffffff) >> 0x10 & 0x1f;
          local_70 = *(ulonglong *)(pcVar11 + 0xc) & 0xfcffffffffff0000;
          if ((2 < uVar2) &&
             ((uVar2 < 0x13 &&
              (p_Var4 = (unsigned char *)
                        ParseSymbolTable__NextSymbol(*(unsigned char **)(pTVar10 + 0x28)),
              p_Var4 != (unsigned char *)0x0)))) {
            cVar1 = *pcVar11;
            while (cVar1 == '\x03') {
              pcVar9 = *(char **)p_Var4;
              if (((pcVar9 != (char *)0x0) && (pcVar9 != pcVar11)) && (*pcVar9 == '\x03')) {
                local_60 = (uint)((ulonglong)*(undefined8 *)(pcVar9 + 0xc) >> 0x20);
                uStack_5c = (uint)*(undefined8 *)(pcVar9 + 0xc) & 0xffff0000;
                if ((((local_60 & 0xfcffffff) == (*(unsigned int *)((unsigned char *)&(local_70) + 0))) && (uStack_5c == (*(unsigned int *)((unsigned char *)&(local_70) + 4))))
                   && (iVar5 = _PPStreamGetArray(*(undefined4 *)(this + iVar7 + 0x30),2,
                                                 *(undefined2 *)(pcVar9 + 0x12)), iVar5 == -1)) {
                  _PPStreamRenumberOperandIndices
                            (*(undefined4 *)(this + iVar7 + 0x30),pcVar9,
                             *(undefined2 *)(pcVar11 + 0x12));
                  uVar6 = *(uint *)(pcVar11 + 0xc) >> 0x18 & 3;
                  uVar2 = *(uint *)(pcVar9 + 0xc) >> 0x18 & 3;
                  if (uVar2 < uVar6) {
                    uVar2 = uVar6;
                  }
                  *(uint *)(pcVar11 + 0xc) = uVar2 << 0x18 | *(uint *)(pcVar11 + 0xc) & 0xfcffffff;
                  _PPStreamChunkListRemoveChunk
                            (*(undefined4 *)(*(int *)(this + iVar7 + 0x30) + 0x10),pcVar9);
                  ParseSymbol__SetChunk(p_Var4);
                  *(undefined4 *)(p_Var4 + 0x44) = 0;
                }
              }
              p_Var4 = (unsigned char *)
                       ParseSymbolTable__NextSymbol(*(unsigned char **)(this + iVar7 + 0x28));
              if (p_Var4 == (unsigned char *)0x0) break;
              cVar1 = *pcVar11;
            }
          }
        }
        puVar3 = (undefined4 *)ParseSymbolTable__NextSymbol(*(unsigned char **)(pTVar10 + 0x28));
      }
    }
    iVar8 = iVar8 + 1;
    iVar7 = iVar7 + 4;
    pTVar10 = pTVar10 + 4;
    if (1 < iVar8) {
      return 1;
    }
  } while( true );
}

/* TGenericLinker__BuildUniformRemapTables @ 0x97bb6d2c (864 bytes) */
int TGenericLinker__BuildUniformRemapTables(this)
  unsigned char * this;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  int *piVar6;
  size_t sVar7;
  size_t sVar8;
  char *pcVar9;
  size_t sVar10;
  size_t sVar11;
  undefined4 uVar12;
  uint uVar13;
  ushort uVar14;
  undefined4 uVar15;
  int iVar16;
  unsigned char * pTVar17;
  char *pcVar18;
  uint uVar19;
  uint uVar20;
  
  uVar15 = 1;
  iVar2 = BindingTable__NextUniformBinding(*(unsigned char **)(this + 4));
  iVar16 = 0;
  pTVar17 = this;
  do {
    iVar3 = BindingTable__GetSizeActiveUserUniforms();
    pvVar4 = _malloc(iVar3 * 4 + 0xfU & 0xfffffff0);
    *(void **)(pTVar17 + 0x40) = pvVar4;
    if (*(int *)(pTVar17 + 0x28) == 0) {
      *(undefined4 *)(pTVar17 + 0x48) = 0;
    }
    else {
      *(undefined4 *)(pTVar17 + 0x48) = *(undefined4 *)(*(int *)(pTVar17 + 0x28) + 0x28);
    }
    for (iVar3 = 0; iVar5 = BindingTable__GetSizeActiveUserUniforms(), iVar3 < iVar5;
        iVar3 = iVar3 + 1) {
      *(undefined4 *)(iVar3 * 4 + *(int *)(pTVar17 + 0x40)) = 0xffffffff;
    }
    iVar16 = iVar16 + 1;
    pTVar17 = pTVar17 + 4;
  } while (iVar16 < 2);
  while (iVar2 != 0) {
    iVar2 = Binding__IsBuiltIn();
    if (iVar2 == 0) {
      uVar14 = 0;
      bVar1 = false;
      iVar2 = 0;
      do {
        if ((*(char **)(this + iVar2 * 4 + 0x28) != (char *)0x0) &&
           (piVar6 = (int *)ParseSymbolTable__FindGlobalSymbolByName
                                      (*(char **)(this + iVar2 * 4 + 0x28)), piVar6 != (int *)0x0))
        {
          if ((*(char *)*piVar6 != '\x03') ||
             ((*(uint *)((char *)*piVar6 + 0xc) & 0x1f0000) != 0x10000)) {
            pcVar18 = (char *)piVar6[5];
            sVar7 = _strlen(DAT_a7b7bb74);
            sVar8 = _strlen(pcVar18);
            pcVar9 = _malloc(sVar7 + sVar8 + 1);
            _sprintf(pcVar9,DAT_a7b7bb74,pcVar18);
            pcVar18 = *(char **)(this + 0x84);
                    
            TInfoSinkBase__append(pcVar18);
            TInfoSinkBase__append(pcVar18);
            TInfoSinkBase__append(pcVar18);
            uVar15 = 0;
            _free(pcVar9);
          }
          if (bVar1) {
            if (*(ushort *)(piVar6 + 0xb) != uVar14) {
              pcVar18 = (char *)piVar6[5];
              sVar7 = _strlen(DAT_a7b7bae4);
              sVar8 = _strlen(pcVar18);
              pcVar9 = (char *)((int (*)())GetShaderStringForType)(uVar14);
              sVar10 = _strlen(pcVar9);
              pcVar9 = (char *)((int (*)())GetShaderStringForType)(*(ushort *)(piVar6 + 0xb));
              sVar11 = _strlen(pcVar9);
              pcVar9 = _malloc(sVar7 + sVar8 + sVar10 + sVar11 + 1);
              uVar15 = ((int (*)())GetShaderStringForType)(*(ushort *)(piVar6 + 0xb));
              uVar12 = ((int (*)())GetShaderStringForType)(uVar14);
              _sprintf(pcVar9,DAT_a7b7bae4,pcVar18,uVar12,uVar15);
              pcVar18 = *(char **)(this + 0x84);
                    
              TInfoSinkBase__append(pcVar18);
              TInfoSinkBase__append(pcVar18);
              TInfoSinkBase__append(pcVar18);
              uVar15 = 0;
              _free(pcVar9);
            }
          }
          else {
            uVar14 = *(ushort *)(piVar6 + 0xb);
            bVar1 = true;
          }
          uVar20 = (uint)*(ushort *)(*piVar6 + 0xe);
          for (uVar19 = 0; uVar13 = Binding__GetBindingSlots(), uVar19 < uVar13; uVar19 = uVar19 + 1
              ) {
            iVar16 = Binding__GetLocation();
            *(uint *)((iVar16 + uVar19) * 4 + *(int *)(this + iVar2 * 4 + 0x40)) = uVar20;
            uVar20 = uVar20 + 1;
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 2);
    }
    iVar2 = BindingTable__NextUniformBinding(*(unsigned char **)(this + 4));
  }
  iVar2 = 0;
  iVar16 = 0;
  for (iVar3 = 0; iVar5 = BindingTable__GetSizeActiveUserUniforms(), iVar3 < iVar5;
      iVar3 = iVar3 + 1) {
    if (*(int *)(iVar3 * 4 + *(int *)(this + 0x40)) != -1) {
      iVar2 = iVar2 + 1;
    }
    if (*(int *)(iVar3 * 4 + *(int *)(this + 0x44)) != -1) {
      iVar16 = iVar16 + 1;
    }
  }
  if (*(int *)(this + 0x48) != iVar2) {
    pcVar9 = *(char **)(this + 0x84);
                    
    TInfoSinkBase__append(pcVar9);
    TInfoSinkBase__append(pcVar9);
    TInfoSinkBase__append(pcVar9);
    uVar15 = 0;
  }
  if (*(int *)(this + 0x4c) != iVar16) {
    pcVar9 = *(char **)(this + 0x84);
                    
    TInfoSinkBase__append(pcVar9);
    TInfoSinkBase__append(pcVar9);
    TInfoSinkBase__append(pcVar9);
    uVar15 = 0;
  }
  return uVar15;
}

/* TGenericLinker__InsertUniformBindingFromSymbol @ 0x97bb727c (412 bytes) */
int TGenericLinker__InsertUniformBindingFromSymbol(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  int param_2;
{
  unsigned char * this_00;
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  char *pcVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  uVar5 = 1;
  if ((**(char **)param_1 == '\x03') &&
     ((*(uint *)(*(char **)param_1 + 0xc) & 0x1f0000) != 0x110000)) {
    this_00 = operator_new(0x38);
    Binding__Binding(this_00);
    if (this_00 == (unsigned char *)0x0) {
      pcVar6 = *(char **)(param_1 + 0x14);
      sVar2 = _strlen(DAT_a7b7bb7c);
      sVar3 = _strlen(pcVar6);
      pcVar4 = _malloc(sVar2 + sVar3 + 1);
      _sprintf(pcVar4,DAT_a7b7bb7c,pcVar6);
      pcVar6 = *(char **)(this + 0x84);
                    
      TInfoSinkBase__append(pcVar6);
      TInfoSinkBase__append(pcVar6);
      TInfoSinkBase__append(pcVar6);
      _free(pcVar4);
      uVar5 = 0;
    }
    else {
      Binding__SetName((char *)this_00);
      iVar1 = BindingTable__FindUniformBinding(*(unsigned char **)(this + 4));
      if (iVar1 == 0) {
        Binding__SetClientRequest(SUB41(this_00,0));
        Binding__SetOpenGLType((ushort)this_00);
        Binding__SetDecSize((ulong)this_00);
        Binding__SetActualSize((ulong)this_00);
        Binding__SetBuiltIn(SUB41(this_00,0));
        if (*(short *)(param_1 + 0x2e) == 1) {
          BindingTable__InsertSingleUniform(*(unsigned char **)(this + 4),(int)this_00);
        }
        else {
          BindingTable__InsertUniformArray
                    (*(unsigned char **)(this + 4),(int)this_00,(int)*(short *)(param_1 + 0x30),param_2,
                     (unsigned char **)0x2);
        }
      }
      else {
        if (*(short *)(param_1 + 0x2e) == 1) {
          BindingTable__AddSingleUniformReference(*(unsigned char **)(this + 4),iVar1);
        }
        Binding___Binding(this_00);
        operator_delete(this_00);
      }
    }
  }
  return uVar5;
}

/* TGenericLinker__CollectUniformBindings @ 0x97bb7498 (296 bytes) */
int TGenericLinker__CollectUniformBindings(this)
  unsigned char * this;
{
  unsigned char * pPVar1;
  int iVar2;
  undefined4 uVar3;
  unsigned char * pTVar4;
  int iVar5;
  unsigned char * pTVar6;
  
  uVar3 = 1;
  iVar5 = 0;
  pTVar6 = this + 0x28;
  pTVar4 = this;
  do {
    pPVar1 = *(unsigned char **)pTVar6;
    pTVar6 = pTVar6 + 4;
    if (pPVar1 != (unsigned char *)0x0) {
      pPVar1 = (unsigned char *)ParseSymbolTable__NextSymbol(pPVar1);
      while (pPVar1 != (unsigned char *)0x0) {
        if ((*(int *)(pPVar1 + 0x34) == 0) &&
           (iVar2 = ((int (*)())TGenericLinker__InsertUniformBindingFromSymbol)(this,pPVar1,iVar5), iVar2 == 0)) {
          uVar3 = 0;
        }
        pPVar1 = (unsigned char *)ParseSymbolTable__NextSymbol(*(unsigned char **)(pTVar4 + 0x28));
      }
    }
    iVar5 = iVar5 + 1;
    pTVar4 = pTVar4 + 4;
  } while (iVar5 < 2);
  iVar5 = 0;
  pTVar6 = this + 0x28;
  pTVar4 = this;
  do {
    pPVar1 = *(unsigned char **)pTVar6;
    pTVar6 = pTVar6 + 4;
    if (pPVar1 != (unsigned char *)0x0) {
      pPVar1 = (unsigned char *)ParseSymbolTable__NextSymbol(pPVar1);
      while (pPVar1 != (unsigned char *)0x0) {
        if ((*(int *)(pPVar1 + 0x34) != 0) &&
           (iVar2 = ((int (*)())TGenericLinker__InsertUniformBindingFromSymbol)(this,pPVar1,iVar5), iVar2 == 0)) {
          uVar3 = 0;
        }
        pPVar1 = (unsigned char *)ParseSymbolTable__NextSymbol(*(unsigned char **)(pTVar4 + 0x28));
      }
    }
    iVar5 = iVar5 + 1;
    pTVar4 = pTVar4 + 4;
  } while (iVar5 < 2);
  return uVar3;
}

/* TGenericLinker__CreateFunctionTable @ 0x97bb75c0 (1156 bytes) */
int TGenericLinker__CreateFunctionTable(this, param_1)
  unsigned char * this;
  int param_1;
{
  int iVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  unsigned char * this_00;
  char *pcVar5;
  char *pcVar6;
  int iVar7;
  size_t sVar8;
  size_t sVar9;
  size_t sVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  char *pcVar18;
  
  iVar1 = param_1 * 4;
  this_00 = operator_new(8);
  bVar4 = false;
  FunctionTable__FunctionTable(this_00);
  iVar11 = 0;
  if (0 < *(int *)(this + iVar1 + 0x20)) {
    do {
      iVar13 = 0;
      iVar14 = *(int *)(*(int *)(iVar11 * 4 + *(int *)(this + iVar1 + 8)) + 0x6c);
      if (0 < *(int *)(iVar14 + 4)) {
        do {
          bVar2 = false;
          iVar12 = 0;
          if (iVar11 < 1) {
LAB_97bb7818:
            FunctionTable__getFunctionName(iVar14);
            uVar17 = FunctionTable__addFunction((char *)this_00);
            FunctionTable__getEmpty(iVar14);
            FunctionTable__setEmpty((int)this_00,SUB41(uVar17,0));
            FunctionTable__getReturnVal(iVar14);
            FunctionTable__setReturnVal((int)this_00,SUB41(uVar17,0));
            FunctionTable__getNumParams(iVar14);
            FunctionTable__setNumParams((int)this_00,uVar17);
            FunctionTable__getFirstOp(iVar14);
            FunctionTable__setFirstOp((int)this_00,uVar17);
            FunctionTable__getLastOp(iVar14);
            FunctionTable__setLastOp((int)this_00,uVar17);
          }
          else {
            do {
              iVar16 = 0;
              iVar15 = *(int *)(*(int *)(iVar12 * 4 + *(int *)(this + iVar1 + 8)) + 0x6c);
              if (0 < *(int *)(iVar15 + 4)) {
                do {
                  pcVar5 = (char *)FunctionTable__getFunctionName(iVar15);
                  pcVar6 = (char *)FunctionTable__getFunctionName(iVar14);
                  iVar7 = _strcmp(pcVar5,pcVar6);
                  if (iVar7 == 0) {
                    pcVar5 = (char *)FunctionTable__getFunctionName(iVar15);
                    sVar8 = _strlen(pcVar5);
                    pcVar5 = _malloc(sVar8 + 1);
                    pcVar6 = (char *)FunctionTable__getFunctionName(iVar15);
                    _strcpy(pcVar5,pcVar6);
                    for (uVar17 = 0; sVar8 = _strlen(pcVar5), uVar17 < sVar8; uVar17 = uVar17 + 1) {
                      if (pcVar5[uVar17] == '(') {
                        pcVar5[uVar17] = '\0';
                      }
                    }
                    sVar8 = _strlen(DAT_a7b7bb20);
                    sVar9 = _strlen((char *)(&_shaderString)[param_1]);
                    sVar10 = _strlen(pcVar5);
                    pcVar6 = _malloc(sVar8 + sVar9 + sVar10 + 1);
                    _sprintf(pcVar6,DAT_a7b7bb20,pcVar5,(&_shaderString)[param_1]);
                    pcVar18 = *(char **)(this + 0x84);
                    
                    TInfoSinkBase__append(pcVar18);
                    TInfoSinkBase__append(pcVar18);
                    TInfoSinkBase__append(pcVar18);
                    _free(pcVar6);
                    _free(pcVar5);
                    bVar2 = true;
                  }
                  iVar16 = iVar16 + 1;
                } while (iVar16 < *(int *)(iVar15 + 4));
              }
              iVar12 = iVar12 + 1;
            } while (iVar12 < iVar11);
            if (!bVar2) goto LAB_97bb7818;
          }
          iVar13 = iVar13 + 1;
          bVar4 = (bool)(bVar4 | bVar2);
        } while (iVar13 < *(int *)(iVar14 + 4));
      }
      for (iVar13 = **(int **)(*(int *)(iVar11 * 4 + *(int *)(this + iVar1 + 0x18)) + 0x20);
          iVar13 != 0; iVar13 = *(int *)(iVar13 + 8)) {
        if ((*(uint *)(iVar13 + 0xc) & 0x3fc0000) == 0x1300000) {
          bVar2 = false;
          iVar14 = 0;
          pcVar5 = _malloc(*(int *)(iVar13 + 0x40) + 1);
          _strcpy(pcVar5,(char *)(iVar13 + 0x44));
          if (*(int *)(this + iVar1 + 0x20) < 1) {
            bVar3 = true;
          }
          else {
            do {
              iVar12 = 0;
              iVar15 = *(int *)(*(int *)(iVar14 * 4 + *(int *)(this + iVar1 + 8)) + 0x6c);
              if (0 < *(int *)(iVar15 + 4)) {
                do {
                  pcVar6 = (char *)FunctionTable__getFunctionName(iVar15);
                  iVar16 = _strcmp(pcVar5,pcVar6);
                  if (iVar16 == 0) {
                    bVar2 = true;
                    break;
                  }
                  iVar12 = iVar12 + 1;
                } while (iVar12 < *(int *)(iVar15 + 4));
              }
              bVar3 = !bVar2;
              if (!bVar3) goto LAB_97bb7ad8;
              iVar14 = iVar14 + 1;
            } while (iVar14 < *(int *)(this + iVar1 + 0x20));
          }
          if (bVar3) {
            for (uVar17 = 0; sVar8 = _strlen(pcVar5), uVar17 < sVar8; uVar17 = uVar17 + 1) {
              if (pcVar5[uVar17] == '(') {
                pcVar5[uVar17] = '\0';
              }
            }
            sVar8 = _strlen(DAT_a7b7bb24);
            sVar9 = _strlen((char *)(&_shaderString)[param_1]);
            sVar10 = _strlen(pcVar5);
            pcVar6 = _malloc(sVar8 + sVar9 + sVar10 + 1);
            _sprintf(pcVar6,DAT_a7b7bb24,pcVar5,(&_shaderString)[param_1]);
            pcVar18 = *(char **)(this + 0x84);
                    
            TInfoSinkBase__append(pcVar18);
            TInfoSinkBase__append(pcVar18);
            TInfoSinkBase__append(pcVar18);
            _free(pcVar6);
            bVar4 = true;
          }
LAB_97bb7ad8:
          _free(pcVar5);
        }
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < *(int *)(this + iVar1 + 0x20));
    if (bVar4) goto LAB_97bb7b18;
  }
  if (*(int *)(this_00 + 4) != 0) {
    return this_00;
  }
LAB_97bb7b18:
  if (this_00 != (unsigned char *)0x0) {
    FunctionTable___FunctionTable(this_00);
    operator_delete(this_00);
  }
  return (unsigned char *)0x0;
}

/* TGenericLinker__BuildSymbolTableList @ 0x97bb7b4c (968 bytes) */
int TGenericLinker__BuildSymbolTableList(this, param_1, param_2)
  unsigned char * this;
  void **param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  size_t sVar5;
  size_t sVar6;
  char *pcVar7;
  void *pvVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  unsigned char * pTVar14;
  int local_50 [2];
  undefined8 local_48;
  undefined8 local_40 [2];
  
  iVar11 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_48 = DAT_97c38fb0;
  iVar12 = 1;
  local_40[0] = DAT_97c38fb8;
  if (param_2 < 1) {
LAB_97bb7d6c:
    bVar1 = false;
    if (iVar12 == 1) {
      iVar11 = 0;
      do {
        if ((local_50[iVar11] == 0) && (0 < *(int *)(this + iVar11 * 4 + 0x20))) {
          sVar5 = _strlen(DAT_a7b7bab8);
          sVar6 = _strlen((char *)(&_shaderString)[iVar11]);
          pcVar7 = _malloc(sVar5 + sVar6 + 1);
          _sprintf(pcVar7,DAT_a7b7bab8,(&_shaderString)[iVar11]);
          pcVar13 = *(char **)(this + 0x84);
                    
override_jmp_97bb7df4_case_0:
          TInfoSinkBase__append(pcVar13);
          TInfoSinkBase__append(pcVar13);
          TInfoSinkBase__append(pcVar13);
          _free(pcVar7);
          iVar12 = 0;
        }
        else if (1 < local_50[iVar11]) {
          sVar5 = _strlen(DAT_a7b7babc);
          sVar6 = _strlen((char *)(&_shaderString)[iVar11]);
          pcVar7 = _malloc(sVar5 + sVar6 + 9);
          _sprintf(pcVar7,DAT_a7b7babc,local_50[iVar11],(&_shaderString)[iVar11]);
          pcVar13 = *(char **)(this + 0x84);
                    
          goto override_jmp_97bb7df4_case_0;
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < 2);
      bVar1 = iVar12 == 1;
      if (bVar1) {
        pTVar14 = this;
        do {
          pvVar8 = _malloc(*(int *)(pTVar14 + 0x20) << 2);
          *(void **)(pTVar14 + 8) = pvVar8;
          pvVar8 = _malloc(*(int *)(pTVar14 + 0x20) << 2);
          *(void **)(pTVar14 + 0x10) = pvVar8;
          pvVar8 = _malloc(*(int *)(pTVar14 + 0x20) << 2);
          *(void **)(pTVar14 + 0x18) = pvVar8;
          pTVar14 = pTVar14 + 4;
        } while ((int)pTVar14 <= (int)(this + 4));
      }
    }
  }
  else {
    do {
      if (param_1[iVar11] == (int *)0x0) {
        pcVar7 = *(char **)(this + 0x84);
                    
override_jmp_97bb7c58_case_0:
        TInfoSinkBase__append(pcVar7);
        TInfoSinkBase__append(pcVar7);
        TInfoSinkBase__append(pcVar7);
        iVar12 = 0;
      }
      else {
        iVar4 = (**(code **)(*(int *)param_1[iVar11] + 8))();
        if (iVar4 == 0) {
          pcVar7 = *(char **)(this + 0x84);
                    
          goto override_jmp_97bb7c58_case_0;
        }
        iVar2 = 0;
        if (*(int *)(iVar4 + 8) != 0) {
          if (*(int *)(iVar4 + 8) != 1) {
            pcVar7 = *(char **)(this + 0x84);
                    
            goto override_jmp_97bb7c58_case_0;
          }
          iVar2 = 1;
        }
        iVar3 = iVar2 * 4;
        if (*(int *)(iVar4 + 0xac) != 0) {
          local_50[iVar2] = local_50[iVar2] + 1;
          *(int *)((int)local_40 + iVar3 + -8) = iVar11;
        }
        *(int *)(this + iVar3 + 0x20) = *(int *)(this + iVar3 + 0x20) + 1;
      }
      iVar11 = iVar11 + 1;
      if (param_2 <= iVar11) goto LAB_97bb7d6c;
    } while (iVar12 == 1);
    bVar1 = false;
  }
  iVar11 = 0;
  if ((0 < param_2) && (bVar1)) {
    do {
      piVar9 = *param_1;
      param_1 = param_1 + 1;
      if ((piVar9 != (int *)0x0) && (iVar4 = (**(code **)(*piVar9 + 8))(), iVar4 != 0)) {
        iVar2 = (uint)(*(int *)(iVar4 + 8) != 0) * 4;
        if (*(int *)((int)local_40 + iVar2 + -8) == iVar11) {
          **(int **)(this + iVar2 + 8) = iVar4;
          **(undefined4 **)(this + iVar2 + 0x10) = *(undefined4 *)(iVar4 + 0x68);
          **(undefined4 **)(this + iVar2 + 0x18) = *(undefined4 *)(iVar4 + 0x70);
        }
        else {
          *(int *)(*(int *)((int)local_40 + iVar2) * 4 + *(int *)(this + iVar2 + 8)) = iVar4;
          *(undefined4 *)(*(int *)((int)local_40 + iVar2) * 4 + *(int *)(this + iVar2 + 0x10)) =
               *(undefined4 *)(iVar4 + 0x68);
          iVar3 = *(int *)((int)local_40 + iVar2);
          iVar10 = *(int *)(this + iVar2 + 0x18);
          *(int *)((int)local_40 + iVar2) = iVar3 + 1;
          *(undefined4 *)(iVar3 * 4 + iVar10) = *(undefined4 *)(iVar4 + 0x70);
        }
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < param_2);
  }
  return iVar12;
}

/* TGenericLinker__BuildProcessingComponents @ 0x97bb8054 (200 bytes) */
int TGenericLinker__BuildProcessingComponents(param_1, param_2)
  void **param_1;
  int param_2;
{
  void *pvVar1;
  unsigned char * pPVar2;
  undefined4 uVar3;
  int iVar4;
  void **ppvVar5;
  
  uVar3 = 1;
  iVar4 = 0;
  ppvVar5 = param_1;
  do {
    if (0 < (int)ppvVar5[8]) {
      pvVar1 = (void *)((int (*)())TGenericLinker__CreateFunctionTable)((unsigned char *)param_1,iVar4);
      ppvVar5[0xe] = pvVar1;
      if (pvVar1 == (void *)0x0) {
        uVar3 = 0;
      }
      else if (ppvVar5[8] == (void *)0x1) {
        pPVar2 = (unsigned char *)ParseSymbolTable__CopySymbolTable();
        ppvVar5[10] = pPVar2;
        pvVar1 = (void *)((int (*)())TGenericLinker__CreateFromStreamWithSymbolTableUpdate)((unsigned char *)param_1,
                                    *(unsigned char **)(*(int *)ppvVar5[2] + 0x70),pPVar2);
        ppvVar5[0xc] = pvVar1;
      }
      else if (1 < (int)ppvVar5[8]) {
        uVar3 = ((int (*)())TGenericLinker__MergeCompilers)((unsigned char *)param_1,iVar4);
      }
    }
    iVar4 = iVar4 + 1;
    ppvVar5 = ppvVar5 + 1;
  } while (iVar4 < 2);
  return uVar3;
}

/* TGenericLinker__TGenericLinker @ 0x97bb811c (4 bytes) */
int TGenericLinker__TGenericLinker(this, param_1)
  unsigned char * this;
  int param_1;
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  unsigned char * this_00;
  unsigned char * pTVar5;
  char in_RESERVE;
  byte in_cr0;
  
  *(int *)this = DAT_a7b7bba0 + 8;
  *(int *)(this + 0x7c) = param_1;
  puVar4 = operator_new(0x10);
  puVar2 = PTR__S_empty_rep_storage_a7b7c0f0;
  piVar3 = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  puVar4[1] = 4;
  *puVar4 = puVar2 + 0xc;
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  puVar4[2] = puVar2 + 0xc;
  puVar4[3] = 4;
  *(undefined4 *)(this + 0x80) = 1;
  *(undefined4 **)(this + 0x84) = puVar4;
  *(int *)(this + 0x7c) = param_1;
  this_00 = operator_new(0x48);
  BindingTable__BindingTable(this_00,0x80);
  *(unsigned char **)(this + 4) = this_00;
  pTVar5 = this + 4;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  do {
    *(undefined4 *)(this + 8) = 0;
    *(undefined4 *)(this + 0x10) = 0;
    *(undefined4 *)(this + 0x18) = 0;
    *(undefined4 *)(this + 0x20) = 0;
    *(undefined4 *)(this + 0x28) = 0;
    *(undefined4 *)(this + 0x30) = 0;
    *(undefined4 *)(this + 0x38) = 0;
    *(undefined4 *)(this + 0x40) = 0;
    *(undefined4 *)(this + 0x48) = 0;
    this = this + 4;
  } while ((int)this <= (int)pTVar5);
  return;
}

/* TGenericLinker__TGenericLinker_97bb8120 @ 0x97bb8120 (4 bytes) */
int TGenericLinker__TGenericLinker_97bb8120(this, param_1)
  unsigned char * this;
  int param_1;
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  unsigned char * this_00;
  unsigned char * pTVar5;
  char in_RESERVE;
  byte in_cr0;
  
  *(int *)this = DAT_a7b7bba0 + 8;
  *(int *)(this + 0x7c) = param_1;
  puVar4 = operator_new(0x10);
  puVar2 = PTR__S_empty_rep_storage_a7b7c0f0;
  piVar3 = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  puVar4[1] = 4;
  *puVar4 = puVar2 + 0xc;
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  puVar4[2] = puVar2 + 0xc;
  puVar4[3] = 4;
  *(undefined4 *)(this + 0x80) = 1;
  *(undefined4 **)(this + 0x84) = puVar4;
  *(int *)(this + 0x7c) = param_1;
  this_00 = operator_new(0x48);
  BindingTable__BindingTable(this_00,0x80);
  *(unsigned char **)(this + 4) = this_00;
  pTVar5 = this + 4;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  do {
    *(undefined4 *)(this + 8) = 0;
    *(undefined4 *)(this + 0x10) = 0;
    *(undefined4 *)(this + 0x18) = 0;
    *(undefined4 *)(this + 0x20) = 0;
    *(undefined4 *)(this + 0x28) = 0;
    *(undefined4 *)(this + 0x30) = 0;
    *(undefined4 *)(this + 0x38) = 0;
    *(undefined4 *)(this + 0x40) = 0;
    *(undefined4 *)(this + 0x48) = 0;
    this = this + 4;
  } while ((int)this <= (int)pTVar5);
  return;
}

/* TGenericLinker__TGenericLinker_97bb8124 @ 0x97bb8124 (268 bytes) */
int TGenericLinker__TGenericLinker_97bb8124(this, param_1)
  unsigned char * this;
  int param_1;
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  unsigned char * this_00;
  unsigned char * pTVar5;
  char in_RESERVE;
  byte in_cr0;
  
  *(int *)this = DAT_a7b7bba0 + 8;
  *(int *)(this + 0x7c) = param_1;
  puVar4 = operator_new(0x10);
  puVar2 = PTR__S_empty_rep_storage_a7b7c0f0;
  piVar3 = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  puVar4[1] = 4;
  *puVar4 = puVar2 + 0xc;
  do {
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(*piVar3 + 1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  puVar4[2] = puVar2 + 0xc;
  puVar4[3] = 4;
  *(undefined4 *)(this + 0x80) = 1;
  *(undefined4 **)(this + 0x84) = puVar4;
  *(int *)(this + 0x7c) = param_1;
  this_00 = operator_new(0x48);
  BindingTable__BindingTable(this_00,0x80);
  *(unsigned char **)(this + 4) = this_00;
  pTVar5 = this + 4;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  do {
    *(undefined4 *)(this + 8) = 0;
    *(undefined4 *)(this + 0x10) = 0;
    *(undefined4 *)(this + 0x18) = 0;
    *(undefined4 *)(this + 0x20) = 0;
    *(undefined4 *)(this + 0x28) = 0;
    *(undefined4 *)(this + 0x30) = 0;
    *(undefined4 *)(this + 0x38) = 0;
    *(undefined4 *)(this + 0x40) = 0;
    *(undefined4 *)(this + 0x48) = 0;
    this = this + 4;
  } while ((int)this <= (int)pTVar5);
  return;
}

/* TGenericLinker___TGenericLinker @ 0x97bb8230 (8 bytes) */
int TGenericLinker___TGenericLinker(this)
  unsigned char * this;
{
  ~TGenericLinker(this);
  return;
}

/* TGenericLinker___TGenericLinker_97bb8238 @ 0x97bb8238 (8 bytes) */
int TGenericLinker___TGenericLinker_97bb8238(this)
  unsigned char * this;
{
  ~TGenericLinker(this);
  return;
}

/* TGenericLinker___TGenericLinker_97bb8240 @ 0x97bb8240 (8 bytes) */
int TGenericLinker___TGenericLinker_97bb8240(this)
  unsigned char * this;
{
  ~TGenericLinker(this);
  return;
}

/* TGenericLinker___TGenericLinker_97bb8248 @ 0x97bb8248 (244 bytes) */
int TGenericLinker___TGenericLinker_97bb8248(this)
  unsigned char * this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint in_r4;
  int iVar4;
  int *piVar5;
  unsigned char * this_00;
  char in_RESERVE;
  byte in_cr0;
  
  *(int *)this = DAT_a7b7bba0 + 8;
  reset(this);
  piVar5 = *(int **)(this + 0x84);
  if (piVar5 != (int *)0x0) {
    iVar4 = piVar5[2];
    piVar2 = (int *)(iVar4 + -4);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(iVar4 + -0xc));
    }
    iVar4 = *piVar5;
    piVar2 = (int *)(iVar4 + -4);
    do {
      iVar3 = *piVar2;
      if (in_RESERVE != '\0') {
        iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
        *piVar2 = iVar1;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar3 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(iVar4 + -0xc));
    }
    operator_delete(piVar5);
  }
  this_00 = *(unsigned char **)(this + 4);
  if (this_00 != (unsigned char *)0x0) {
    BindingTable___BindingTable(this_00);
    operator_delete(this_00);
  }
  *(undefined ***)this = &PTR__TShHandleBase_a7b7d700;
  if ((in_r4 & 1) != 0) {
    operator_delete(this);
  }
  return;
}

/* TGenericLinker__getShaderLocalParamRemapTable @ 0x97bb833c (40 bytes) */
int TGenericLinker__getShaderLocalParamRemapTable(this, param_2)
  unsigned char * this;
  int param_2;
{
  if (param_2 == 0) {
    return *(undefined4 *)(this + 0x40);
  }
  if (param_2 != 1) {
    return 0;
  }
  return *(undefined4 *)(this + 0x44);
}

/* TGenericLinker__getNumShaderLocalParams @ 0x97bb8364 (40 bytes) */
int TGenericLinker__getNumShaderLocalParams(this, param_2)
  unsigned char * this;
  int param_2;
{
  if (param_2 == 0) {
    return *(undefined4 *)(this + 0x48);
  }
  if (param_2 != 1) {
    return 0;
  }
  return *(undefined4 *)(this + 0x4c);
}

/* TGenericLinker__attributeBindingRequest @ 0x97bb838c (196 bytes) */
int TGenericLinker__attributeBindingRequest(this, param_1, param_2)
  unsigned char * this;
  ulong param_1;
  char *param_2;
{
  int iVar1;
  unsigned char * this_00;
  
  iVar1 = _memcmp(param_2,"gl_",3);
  if (iVar1 != 0) {
    this_00 = operator_new(0x38);
    Binding__Binding(this_00);
    Binding__SetName((char *)this_00);
    Binding__SetLocation((int)this_00);
    Binding__SetClientRequest(SUB41(this_00,0));
    iVar1 = BindingTable__InsertAttribRequestBinding(*(unsigned char **)(this + 4));
    if ((iVar1 == 0) && (this_00 != (unsigned char *)0x0)) {
      Binding___Binding(this_00);
      operator_delete(this_00);
      return;
    }
  }
  return;
}

/* TGenericLinker__getActiveUniform @ 0x97bb8450 (192 bytes) */
int TGenericLinker__getActiveUniform(this, param_1, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  ulong param_1;
  long param_2;
  long *param_3;
  long *param_4;
  ulong *param_5;
  char *param_6;
{
  int iVar1;
  undefined4 uVar2;
  size_t sVar3;
  long lVar4;
  ulong uVar5;
  
  iVar1 = BindingTable__FindUniformBindingByIndex(*(long *)(this + 4));
  uVar2 = 0;
  if (iVar1 != 0) {
    if (param_2 == 0) {
      if (param_3 != (long *)0x0) {
        *param_3 = 0;
      }
    }
    else {
      _strncpy(param_6,*(char **)(iVar1 + 8),param_2);
      param_6[param_2 + -1] = '\0';
      if (param_3 != (long *)0x0) {
        sVar3 = _strlen(param_6);
        *param_3 = sVar3;
      }
    }
    if (param_4 != (long *)0x0) {
      lVar4 = Binding__GetActualSize();
      *param_4 = lVar4;
    }
    if (param_5 != (ulong *)0x0) {
      uVar5 = Binding__GetOpenGLType();
      *param_5 = uVar5;
    }
    uVar2 = 1;
  }
  return uVar2;
}

/* TGenericLinker__getUniformTypeInfo @ 0x97bb8510 (172 bytes) */
int TGenericLinker__getUniformTypeInfo(this, param_1, param_2, param_3, param_4)
  unsigned char * this;
  long param_1;
  long *param_2;
  ulong *param_3;
  uchar *param_4;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  ulong uVar6;
  
  iVar2 = BindingTable__FindUniformBindingByLocation(*(long *)(this + 4));
  uVar1 = 0;
  if (iVar2 != 0) {
    if (param_2 != (long *)0x0) {
      iVar3 = Binding__GetActualSize();
      iVar4 = Binding__GetLocation();
      uVar5 = Binding__GetBindingBasicSize();
      *param_2 = iVar3 - (uint)(param_1 - iVar4) / uVar5;
    }
    if (param_3 != (ulong *)0x0) {
      uVar6 = Binding__GetOpenGLType();
      *param_3 = uVar6;
    }
    if (param_4 != (uchar *)0x0) {
      *param_4 = *(uchar *)(iVar2 + 0x34);
      param_4[1] = *(uchar *)(iVar2 + 0x35);
    }
    uVar1 = 1;
  }
  return uVar1;
}

/* TGenericLinker__getActiveAttrib @ 0x97bb85bc (188 bytes) */
int TGenericLinker__getActiveAttrib(this, param_1, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  ulong param_1;
  long param_2;
  long *param_3;
  long *param_4;
  ulong *param_5;
  char *param_6;
{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  ulong uVar4;
  
  iVar1 = BindingTable__GetAttribBindingByIndex(*(long *)(this + 4));
  uVar2 = 0;
  if (iVar1 != 0) {
    if (param_2 == 0) {
      if (param_3 != (long *)0x0) {
        *param_3 = 0;
      }
    }
    else {
      _strncpy(param_6,*(char **)(iVar1 + 8),param_2);
      param_6[param_2 + -1] = '\0';
      if (param_3 != (long *)0x0) {
        *param_3 = *(long *)(iVar1 + 0x10);
      }
    }
    if (param_4 != (long *)0x0) {
      lVar3 = Binding__GetActualSize();
      *param_4 = lVar3;
    }
    if (param_5 != (ulong *)0x0) {
      uVar4 = Binding__GetOpenGLType();
      *param_5 = uVar4;
    }
    uVar2 = 1;
  }
  return uVar2;
}

/* TGenericLinker__getPPStreamManager @ 0x97bb8678 (40 bytes) */
int TGenericLinker__getPPStreamManager(this, param_2)
  unsigned char * this;
  int param_2;
{
  if (param_2 == 0) {
    return *(undefined4 *)(this + 0x30);
  }
  if (param_2 != 1) {
    return 0;
  }
  return *(undefined4 *)(this + 0x34);
}

/* TGenericLinker__reset @ 0x97bb86a0 (412 bytes) */
int TGenericLinker__reset(this)
  unsigned char * this;
{
  unsigned char * this_00;
  unsigned char * this_01;
  unsigned char * pTVar1;
  
  if (*(void **)(this + 0x50) != (void *)0x0) {
    _free(*(void **)(this + 0x50));
  }
  *(undefined4 *)(this + 0x50) = 0;
  if (*(void **)(this + 0x5c) != (void *)0x0) {
    _free(*(void **)(this + 0x5c));
  }
  *(undefined4 *)(this + 0x5c) = 0;
  if (*(void **)(this + 0x54) != (void *)0x0) {
    _free(*(void **)(this + 0x54));
  }
  *(undefined4 *)(this + 0x54) = 0;
  if (*(void **)(this + 0x58) != (void *)0x0) {
    _free(*(void **)(this + 0x58));
  }
  *(undefined4 *)(this + 0x58) = 0;
  pTVar1 = this;
  do {
    if (*(int *)(pTVar1 + 0x30) != 0) {
      _PPStreamFree();
    }
    this_00 = *(unsigned char **)(pTVar1 + 0x28);
    *(undefined4 *)(pTVar1 + 0x30) = 0;
    if (this_00 != (unsigned char *)0x0) {
      ParseSymbolTable___ParseSymbolTable(this_00);
      operator_delete(this_00);
    }
    this_01 = *(unsigned char **)(pTVar1 + 0x38);
    *(undefined4 *)(pTVar1 + 0x28) = 0;
    if (this_01 != (unsigned char *)0x0) {
      FunctionTable___FunctionTable(this_01);
      operator_delete(this_01);
    }
    *(undefined4 *)(pTVar1 + 0x38) = 0;
    pTVar1 = pTVar1 + 4;
  } while ((int)pTVar1 <= (int)(this + 4));
  pTVar1 = this;
  do {
    if (*(void **)(pTVar1 + 8) != (void *)0x0) {
      _free(*(void **)(pTVar1 + 8));
    }
    *(undefined4 *)(pTVar1 + 8) = 0;
    if (*(void **)(pTVar1 + 0x10) != (void *)0x0) {
      _free(*(void **)(pTVar1 + 0x10));
    }
    *(undefined4 *)(pTVar1 + 0x10) = 0;
    if (*(void **)(pTVar1 + 0x18) != (void *)0x0) {
      _free(*(void **)(pTVar1 + 0x18));
    }
    *(undefined4 *)(pTVar1 + 0x20) = 0;
    *(undefined4 *)(pTVar1 + 0x18) = 0;
    pTVar1 = pTVar1 + 4;
  } while ((int)pTVar1 <= (int)(this + 4));
  pTVar1 = this;
  do {
    if (*(void **)(pTVar1 + 0x40) != (void *)0x0) {
      _free(*(void **)(pTVar1 + 0x40));
    }
    *(undefined4 *)(pTVar1 + 0x40) = 0;
    *(undefined4 *)(pTVar1 + 0x48) = 0;
    pTVar1 = pTVar1 + 4;
  } while ((int)pTVar1 <= (int)(this + 4));
  BindingTable__ClearInternalBindings();
  *(undefined4 *)(this + 0x78) = 0;
  *(undefined4 *)(this + 0x74) = 0xffffffff;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 100) = 0;
  *(undefined4 *)(this + 0x68) = 0;
  *(undefined4 *)(this + 0x6c) = 0;
  *(undefined4 *)(this + 0x70) = 0;
  return;
}

/* TGenericLinker__link @ 0x97bb883c (1244 bytes) */
int TGenericLinker__link(this, param_1, param_2)
  unsigned char * this;
  void **param_1;
  int param_2;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  size_t sVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  unsigned char * pTVar9;
  char *pcVar10;
  
  iVar8 = 1;
  if (0 < param_2) {
    iVar8 = ((int (*)())TGenericLinker__BuildSymbolTableList)(this,param_1,param_2);
    if ((iVar8 == 1) && (iVar8 = ((int (*)())TGenericLinker__BuildProcessingComponents)((void **)this,(int)param_1), iVar8 == 1))
    {
      ((int (*)())TGenericLinker__RemoveExtraVertexOutputs)(this);
      ((int (*)())TGenericLinker__FixOutputReads)(this);
      iVar2 = ((int (*)())TGenericLinker__AllocateTextureUnitsForVaryings)(this);
      if (iVar2 == 0) {
        iVar8 = 0;
      }
      if (1 < *(int *)(this + 0x80)) {
        ((int (*)())TGenericLinker__OptimizeFunctionIO)(this);
        ((int (*)())TGenericLinker__RemoveUnreachableFunctions)(this);
        if (2 < *(int *)(this + 0x80)) {
          ((int (*)())TGenericLinker__RemoveUnusedRegisters)(this);
        }
      }
      pTVar9 = this;
      do {
        if (*(int *)(pTVar9 + 0x30) != 0) {
          ((int (*)())TGenericLinker__CoalesceCommonUniforms)(this);
          _PPStreamSortParamConstants(*(undefined4 *)(pTVar9 + 0x30));
          _PPStreamPackIndices(*(undefined4 *)(pTVar9 + 0x30));
        }
        pTVar9 = pTVar9 + 4;
      } while ((int)pTVar9 <= (int)(this + 4));
      if (iVar2 != 0) {
        iVar2 = 0;
        do {
          if ((*(int *)(this + iVar2 * 4 + 0x30) != 0) &&
             (iVar3 = _PPStreamResolveBranches(), iVar3 != 0)) {
            sVar4 = _strlen(DAT_a7b7bb1c);
            sVar5 = _strlen((char *)(&_shaderString)[iVar2]);
            pcVar6 = _malloc(sVar4 + sVar5 + 1);
            _sprintf(pcVar6,DAT_a7b7bb1c,(&_shaderString)[iVar2]);
            pcVar10 = *(char **)(this + 0x84);
                    
            TInfoSinkBase__append(pcVar10);
            TInfoSinkBase__append(pcVar10);
            TInfoSinkBase__append(pcVar10);
            _free(pcVar6);
            iVar8 = 0;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < 2);
        if (iVar8 == 1) {
          iVar2 = ((int (*)())TGenericLinker__CollectClientAttributeBindings)(this);
          if (iVar2 == 0) {
            iVar8 = 0;
          }
          iVar2 = ((int (*)())TGenericLinker__CollectAttributeBindings)(this);
          if (iVar2 == 0) {
            iVar8 = 0;
          }
          iVar2 = ((int (*)())TGenericLinker__CollectUniformBindings)(this);
          if (iVar2 == 0) {
            iVar8 = 0;
          }
          iVar2 = BindingTable__GetSizeActiveAttributes();
          if (0x10 < iVar2) {
            sVar4 = _strlen(DAT_a7b7bae8);
            pcVar6 = _malloc(sVar4 + 0x11);
            uVar7 = BindingTable__GetSizeActiveAttributes();
            _sprintf(pcVar6,DAT_a7b7bae8,0x10,uVar7);
            pcVar10 = *(char **)(this + 0x84);
                    
            TInfoSinkBase__append(pcVar10);
            TInfoSinkBase__append(pcVar10);
            TInfoSinkBase__append(pcVar10);
            _free(pcVar6);
            iVar8 = 0;
          }
          iVar2 = BindingTable__GetSizeActiveVertexUniforms();
          if (0x200 < iVar2) {
            sVar4 = _strlen(DAT_a7b7baec);
            pcVar6 = _malloc(sVar4 + 0x11);
            uVar7 = BindingTable__GetSizeActiveVertexUniforms();
            _sprintf(pcVar6,DAT_a7b7baec,0x200,uVar7);
            pcVar10 = *(char **)(this + 0x84);
                    
            TInfoSinkBase__append(pcVar10);
            TInfoSinkBase__append(pcVar10);
            TInfoSinkBase__append(pcVar10);
            _free(pcVar6);
            iVar8 = 0;
          }
          iVar2 = BindingTable__GetSizeActiveFragmentUniforms();
          if (0x200 < iVar2) {
            sVar4 = _strlen(DAT_a7b7baf0);
            pcVar6 = _malloc(sVar4 + 0x11);
            uVar7 = BindingTable__GetSizeActiveFragmentUniforms();
            _sprintf(pcVar6,DAT_a7b7baf0,0x200,uVar7);
            pcVar10 = *(char **)(this + 0x84);
                    
            TInfoSinkBase__append(pcVar10);
            TInfoSinkBase__append(pcVar10);
            TInfoSinkBase__append(pcVar10);
            _free(pcVar6);
            iVar8 = 0;
          }
          iVar2 = BindingTable__GetNumActiveVertexSamplers();
          if (0 < iVar2) {
            sVar4 = _strlen(DAT_a7b7baf4);
            pcVar6 = _malloc(sVar4 + 0x11);
            uVar7 = BindingTable__GetNumActiveVertexSamplers();
            _sprintf(pcVar6,DAT_a7b7baf4,0,uVar7);
            pcVar10 = *(char **)(this + 0x84);
                    
            TInfoSinkBase__append(pcVar10);
            TInfoSinkBase__append(pcVar10);
            TInfoSinkBase__append(pcVar10);
            _free(pcVar6);
            iVar8 = 0;
          }
          iVar2 = BindingTable__GetNumActiveFragmentSamplers();
          if (0x10 < iVar2) {
            sVar4 = _strlen(DAT_a7b7baf8);
            pcVar6 = _malloc(sVar4 + 0x11);
            uVar7 = BindingTable__GetNumActiveFragmentSamplers();
            _sprintf(pcVar6,DAT_a7b7baf8,0x10,uVar7);
            pcVar10 = *(char **)(this + 0x84);
                    
            TInfoSinkBase__append(pcVar10);
            TInfoSinkBase__append(pcVar10);
            TInfoSinkBase__append(pcVar10);
            _free(pcVar6);
            iVar8 = 0;
          }
          iVar2 = BindingTable__GetNumActiveVertexSamplers();
          iVar3 = BindingTable__GetNumActiveFragmentSamplers();
          if (0x10 < iVar2 + iVar3) {
            sVar4 = _strlen(DAT_a7b7bafc);
            pcVar6 = _malloc(sVar4 + 0x11);
            iVar8 = BindingTable__GetNumActiveVertexSamplers();
            iVar2 = BindingTable__GetNumActiveFragmentSamplers();
            _sprintf(pcVar6,DAT_a7b7bafc,0x10,iVar8 + iVar2);
            pcVar10 = *(char **)(this + 0x84);
                    
            TInfoSinkBase__append(pcVar10);
            TInfoSinkBase__append(pcVar10);
            TInfoSinkBase__append(pcVar10);
            _free(pcVar6);
            iVar8 = 0;
          }
          if (iVar8 == 1) {
            iVar2 = ((int (*)())TGenericLinker__RemapVertexAttributes)(this);
            if (iVar2 == 0) {
              iVar8 = 0;
            }
            bVar1 = iVar8 == 1;
            iVar2 = ((int (*)())TGenericLinker__BuildUniformRemapTables)(this);
            if (iVar2 == 0) {
              iVar8 = 0;
            }
            if ((iVar2 != 0 && bVar1) && (3 < *(int *)(this + 0x80))) {
              pTVar9 = this + 0x30;
              iVar2 = 1;
              do {
                iVar3 = *(int *)pTVar9;
                pTVar9 = pTVar9 + 4;
                if (iVar3 != 0) {
                  _glpPPShaderLinearizeStreamMgr(iVar3,0xfd);
                }
                iVar2 = iVar2 + -1;
              } while (-1 < iVar2);
            }
          }
        }
      }
    }
    if (iVar8 == 0) {
      reset(this);
    }
  }
  return iVar8;
}

/* TGenericLinker__getStatsString @ 0x97bb9098 (104 bytes) */
int TGenericLinker__getStatsString(this)
  unsigned char * this;
{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  
  iVar1 = *(int *)(this + 0x50);
  if (iVar1 == 0) {
    sVar2 = _strlen(DAT_a7b7bb5c);
    pcVar3 = _malloc(sVar2 * 4 + 4);
    *(char **)(this + 0x50) = pcVar3;
    _strcpy(pcVar3,DAT_a7b7bb5c);
    iVar1 = *(int *)(this + 0x50);
  }
  return iVar1;
}

/* TGenericLinker__getPPStreamString @ 0x97bb9100 (604 bytes) */
int TGenericLinker__getPPStreamString(this)
  unsigned char * this;
{
  bool bVar1;
  size_t sVar2;
  void *pvVar3;
  size_t sVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  int local_30 [5];
  
  pcVar7 = (char *)0x0;
  pcVar8 = (char *)0x0;
  if (*(void **)(this + 0x54) != (void *)0x0) {
    _free(*(void **)(this + 0x54));
  }
  *(undefined4 *)(this + 0x54) = 0;
  sVar2 = _strlen(DAT_a7b7bb4c);
  if (*(int *)(this + 0x30) == 0) {
    sVar4 = _strlen(DAT_a7b7bb58);
    pcVar7 = _malloc(sVar4 + 1);
    _strcpy(pcVar7,DAT_a7b7bb58);
  }
  else {
    _PPStreamGetStream(*(int *)(this + 0x30),0,local_30);
    if (local_30[0] != 0) {
      pvVar3 = _malloc(local_30[0] * 8 + 0xfU & 0xfffffff0);
      _PPStreamGetStream(*(undefined4 *)(this + 0x30),pvVar3,local_30);
      pcVar7 = (char *)_glpPPDisassemble(pvVar3);
      _free(pvVar3);
    }
  }
  if (pcVar7 != (char *)0x0) {
    sVar4 = _strlen(pcVar7);
    sVar2 = sVar2 + sVar4;
  }
  sVar4 = _strlen(DAT_a7b7bb48);
  iVar6 = sVar2 + sVar4;
  if (*(int *)(this + 0x34) == 0) {
    sVar2 = _strlen(DAT_a7b7bb58);
    pcVar8 = _malloc(sVar2 + 1);
    _strcpy(pcVar8,DAT_a7b7bb58);
  }
  else {
    _PPStreamGetStream(*(int *)(this + 0x34),0,local_30);
    if (local_30[0] != 0) {
      pvVar3 = _malloc(local_30[0] * 8 + 0xfU & 0xfffffff0);
      _PPStreamGetStream(*(undefined4 *)(this + 0x34),pvVar3,local_30);
      pcVar8 = (char *)_glpPPDisassemble(pvVar3);
      _free(pvVar3);
    }
  }
  bVar1 = pcVar8 == (char *)0x0;
  if (!bVar1) {
    sVar2 = _strlen(pcVar8);
    iVar6 = iVar6 + sVar2;
  }
  pcVar5 = _malloc(iVar6 + 8);
  *(char **)(this + 0x54) = pcVar5;
  _sprintf(pcVar5,"%s\n",DAT_a7b7bb4c);
  if (pcVar7 == (char *)0x0) {
    _sprintf(*(char **)(this + 0x54),"%s\n\n%s\n",*(char **)(this + 0x54),DAT_a7b7bb48);
  }
  else {
    _sprintf(*(char **)(this + 0x54),"%s%s\n\n%s\n",*(char **)(this + 0x54),pcVar7,DAT_a7b7bb48);
  }
  if (bVar1) {
    _sprintf(*(char **)(this + 0x54),"%s\n",*(char **)(this + 0x54));
  }
  else {
    _sprintf(*(char **)(this + 0x54),"%s%s\n",*(char **)(this + 0x54),pcVar8);
  }
  if (pcVar7 != (char *)0x0) {
    _free(pcVar7);
  }
  if (!bVar1) {
    _free(pcVar8);
  }
  return *(undefined4 *)(this + 0x54);
}

/* TGenericLinker__getShaderToProgramString @ 0x97bb935c (768 bytes) */
int TGenericLinker__getShaderToProgramString(this)
  unsigned char * this;
{
  bool bVar1;
  size_t sVar2;
  void *pvVar3;
  int iVar4;
  size_t sVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  int local_30 [4];
  
  pcVar8 = (char *)0x0;
  pcVar9 = (char *)0x0;
  if (*(void **)(this + 0x58) != (void *)0x0) {
    _free(*(void **)(this + 0x58));
  }
  *(undefined4 *)(this + 0x58) = 0;
  sVar2 = _strlen(DAT_a7b7bb54);
  if (*(int *)(this + 0x30) == 0) {
    sVar5 = _strlen(DAT_a7b7bb58);
    pcVar8 = _malloc(sVar5 + 1);
    _strcpy(pcVar8,DAT_a7b7bb58);
  }
  else {
    _PPStreamGetStream(*(int *)(this + 0x30),0,local_30);
    if (local_30[0] != 0) {
      pvVar3 = _malloc(local_30[0] * 8 + 0xfU & 0xfffffff0);
      _PPStreamGetStream(*(undefined4 *)(this + 0x30),pvVar3,local_30);
      if (*(int *)(this + 0x80) < 4) {
        pcVar8 = (char *)_glpPPShaderToProgramString(pvVar3,0,0);
      }
      else {
        iVar4 = _glpPPShaderLinearize(pvVar3,0xff);
        pcVar8 = (char *)0x0;
        if (iVar4 != 0) {
          pcVar8 = (char *)_glpPPShaderToProgramString(iVar4,0,0);
          _glpFreePPShaderLinearize(iVar4);
        }
      }
      _free(pvVar3);
    }
  }
  if (pcVar8 != (char *)0x0) {
    sVar5 = _strlen(pcVar8);
    sVar2 = sVar2 + sVar5;
  }
  sVar5 = _strlen(DAT_a7b7bb50);
  iVar4 = sVar2 + sVar5;
  if (*(int *)(this + 0x34) == 0) {
    sVar2 = _strlen(DAT_a7b7bb58);
    pcVar9 = _malloc(sVar2 + 1);
    _strcpy(pcVar9,DAT_a7b7bb58);
  }
  else {
    _PPStreamGetStream(*(int *)(this + 0x34),0,local_30);
    if (local_30[0] != 0) {
      pvVar3 = _malloc(local_30[0] * 8 + 0xfU & 0xfffffff0);
      _PPStreamGetStream(*(undefined4 *)(this + 0x34),pvVar3,local_30);
      if (*(int *)(this + 0x80) < 4) {
        pcVar9 = (char *)_glpPPShaderToProgramString(pvVar3,0,0);
      }
      else {
        iVar6 = _glpPPShaderLinearize(pvVar3,0xff);
        pcVar9 = (char *)0x0;
        if (iVar6 != 0) {
          pcVar9 = (char *)_glpPPShaderToProgramString(iVar6,0,0);
          _glpFreePPShaderLinearize(iVar6);
        }
      }
      _free(pvVar3);
    }
  }
  bVar1 = pcVar9 == (char *)0x0;
  if (!bVar1) {
    sVar2 = _strlen(pcVar9);
    iVar4 = iVar4 + sVar2;
  }
  pcVar7 = _malloc(iVar4 + 8);
  *(char **)(this + 0x58) = pcVar7;
  _sprintf(pcVar7,"%s\n",DAT_a7b7bb54);
  if (pcVar8 == (char *)0x0) {
    _sprintf(*(char **)(this + 0x58),"%s\n\n",*(char **)(this + 0x58));
  }
  else {
    _sprintf(*(char **)(this + 0x58),"%s%s\n\n",*(char **)(this + 0x58),pcVar8);
  }
  _sprintf(*(char **)(this + 0x58),"%s%s\n",*(char **)(this + 0x58),DAT_a7b7bb50);
  if (bVar1) {
    _sprintf(*(char **)(this + 0x58),"%s\n",*(char **)(this + 0x58));
  }
  else {
    _sprintf(*(char **)(this + 0x58),"%s%s\n",*(char **)(this + 0x58),pcVar9);
  }
  if (pcVar8 != (char *)0x0) {
    _free(pcVar8);
  }
  if (!bVar1) {
    _free(pcVar9);
  }
  return *(undefined4 *)(this + 0x58);
}

/* TGenericLinker__getTableString @ 0x97bb965c (68 bytes) */
int TGenericLinker__getTableString(this)
  unsigned char * this;
{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x5c);
  if (iVar1 == 0) {
    iVar1 = ((int (*)())TGenericLinker__GetFullTableString)(this);
    *(int *)(this + 0x5c) = iVar1;
  }
  return iVar1;
}

/* GetGLStringForType @ 0x97bb96a0 (168 bytes) */
int GetGLStringForType(param_1)
  int param_1;
{
  undefined2 in_register_0000000c;
  int iVar1;
  
  iVar1 = CONCAT22(in_register_0000000c,param_1);
  if (iVar1 == 0x1404) {
    return _glTypeNameStrings;
  }
  if (iVar1 == 0x1406) {
    return DAT_a7b7bc28;
  }
  if ((iVar1 + 0x74b0U & 0xffff) < 0x15) {
    return *(undefined4 *)(iVar1 * 4 + -0x584a7114);
  }
  if (iVar1 == 0x7ffe) {
    return DAT_a7b7bc80;
  }
  if (iVar1 == 0x7fff) {
    return DAT_a7b7bc84;
  }
  return DAT_a7b7bc88;
}

/* GetShaderStringForType @ 0x97bb9748 (168 bytes) */
int GetShaderStringForType(param_1)
  int param_1;
{
  undefined2 in_register_0000000c;
  int iVar1;
  
  iVar1 = CONCAT22(in_register_0000000c,param_1);
  if (iVar1 == 0x1404) {
    return _shaderTypeNameStrings;
  }
  if (iVar1 == 0x1406) {
    return DAT_a7b7bc90;
  }
  if ((iVar1 + 0x74b0U & 0xffff) < 0x15) {
    return *(undefined4 *)(iVar1 * 4 + -0x584a70ac);
  }
  if (iVar1 == 0x7ffe) {
    return DAT_a7b7bce8;
  }
  if (iVar1 == 0x7fff) {
    return DAT_a7b7bcec;
  }
  return DAT_a7b7bcf0;
}

/* GetVec4sForType @ 0x97bb97f0 (136 bytes) */
int GetVec4sForType(param_1)
  int param_1;
{
  undefined2 in_register_0000000c;
  int iVar1;
  
  iVar1 = CONCAT22(in_register_0000000c,param_1);
  if (iVar1 == 0x8b5a) {
    return 2;
  }
  if (iVar1 < 0x8b5b) {
    if (iVar1 != 0x1406) {
      if (iVar1 < 0x1407) {
        if (iVar1 != 0x1404) {
          return 0;
        }
      }
      else if (iVar1 < 0x8b50) {
        return 0;
      }
    }
  }
  else {
    if (iVar1 == 0x8b5c) {
      return 4;
    }
    if (iVar1 < 0x8b5c) {
      return 3;
    }
    if (0x8b64 < iVar1) {
      return 0;
    }
  }
  return 1;
}

/* GetPPStreamTypeForGLType @ 0x97bb9878 (164 bytes) */
int GetPPStreamTypeForGLType(param_1)
  int param_1;
{
  undefined2 in_register_0000000c;
  int iVar1;
  
  iVar1 = CONCAT22(in_register_0000000c,param_1);
  if (iVar1 < 0x8b56) {
    if (iVar1 < 0x8b53) {
      if (iVar1 == 0x1406) {
        return 1;
      }
      if (iVar1 < 0x1407) {
        if (iVar1 == 0x1404) {
          return 3;
        }
      }
      else if (0x8b4f < iVar1) {
        return 1;
      }
      return 0;
    }
  }
  else {
    if (iVar1 < 0x8b5d) {
      if (0x8b59 < iVar1) {
        return 1;
      }
      return 4;
    }
    if (0x8b64 < iVar1) {
      return 0;
    }
  }
  return 3;
}

/* GetScalerWidthForType @ 0x97bb991c (260 bytes) */
int GetScalerWidthForType(param_1)
  int param_1;
{
  undefined2 in_register_0000000c;
  int iVar1;
  
  iVar1 = CONCAT22(in_register_0000000c,param_1);
  if (iVar1 == 0x8b56) {
    return 1;
  }
  if (0x8b56 < iVar1) {
    if (iVar1 == 0x8b5a) {
      return 2;
    }
    if (iVar1 < 0x8b5b) {
      if (iVar1 != 0x8b58) {
        if (iVar1 < 0x8b59) {
          return 2;
        }
        return 4;
      }
    }
    else {
      if (iVar1 == 0x8b5c) {
        return 4;
      }
      if (0x8b5b < iVar1) {
        if (iVar1 < 0x8b65) {
          return 1;
        }
        return 0;
      }
    }
    return 3;
  }
  if (iVar1 == 0x8b51) {
    return 3;
  }
  if (iVar1 < 0x8b52) {
    if (iVar1 == 0x1406) {
      return 1;
    }
    if (iVar1 < 0x1407) {
      if (iVar1 == 0x1404) {
        return 1;
      }
    }
    else if (iVar1 == 0x8b50) {
      return 2;
    }
    return 0;
  }
  if (iVar1 == 0x8b53) {
    return 2;
  }
  if (iVar1 < 0x8b53) {
    return 4;
  }
  if (iVar1 == 0x8b54) {
    return 3;
  }
  if (iVar1 == 0x8b55) {
    return 4;
  }
  return 0;
}

/* getOpenGLTypeFromTType @ 0x97bb9a20 (676 bytes) */
int getOpenGLTypeFromTType(param_1)
  unsigned char * param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0x1400;
  iVar1 = (**(code **)(*(int *)param_1 + 0x38))();
  if (iVar1 == 0) {
    uVar2 = (**(code **)(*(int *)param_1 + 0x20))(param_1);
    switch(uVar2) {
    case 1:
      iVar1 = (**(code **)(*(int *)param_1 + 0x34))(param_1);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(*(int *)param_1 + 0x2c))(param_1);
        if (iVar1 == 2) {
          uVar3 = 0x8b50;
        }
        else if (iVar1 < 3) {
          if (iVar1 == 1) {
            uVar3 = 0x1406;
          }
        }
        else if (iVar1 == 3) {
          uVar3 = 0x8b51;
        }
        else if (iVar1 == 4) {
          uVar3 = 0x8b52;
        }
      }
      else {
        iVar1 = (**(code **)(*(int *)param_1 + 0x2c))(param_1);
        if (iVar1 == 3) {
          uVar3 = 0x8b5b;
        }
        else if (iVar1 < 4) {
          if (iVar1 == 2) {
            uVar3 = 0x8b5a;
          }
        }
        else if (iVar1 == 4) {
          uVar3 = 0x8b5c;
        }
      }
      break;
    case 2:
      iVar1 = (**(code **)(*(int *)param_1 + 0x2c))(param_1);
      if (iVar1 == 2) {
        uVar3 = 0x8b53;
      }
      else if (iVar1 < 3) {
        if (iVar1 == 1) {
          uVar3 = 0x1404;
        }
      }
      else if (iVar1 == 3) {
        uVar3 = 0x8b54;
      }
      else if (iVar1 == 4) {
        uVar3 = 0x8b55;
      }
      break;
    case 3:
      iVar1 = (**(code **)(*(int *)param_1 + 0x2c))(param_1);
      if (iVar1 == 2) {
        uVar3 = 0x8b57;
      }
      else if (iVar1 < 3) {
        if (iVar1 == 1) {
          uVar3 = 0x8b56;
        }
      }
      else if (iVar1 == 3) {
        uVar3 = 0x8b58;
      }
      else if (iVar1 == 4) {
        uVar3 = 0x8b59;
      }
      break;
    case 5:
      uVar3 = 0x8b5d;
      break;
    case 6:
      uVar3 = 0x8b5e;
      break;
    case 7:
      uVar3 = 0x8b5f;
      break;
    case 8:
      uVar3 = 0x8b60;
      break;
    case 9:
      uVar3 = 0x8b61;
      break;
    case 10:
      uVar3 = 0x8b62;
      break;
    case 0xb:
      uVar3 = 0x8b63;
      break;
    case 0xc:
      uVar3 = 0x8b64;
      break;
    case 0xe:
      uVar3 = 0x7ffe;
    }
  }
  else {
    uVar3 = 0x7fff;
  }
  return uVar3;
}

/* AddressTempAllocator__AddressTempAllocator @ 0x97bb9d04 (4 bytes) */
int AddressTempAllocator__AddressTempAllocator(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* AddressTempAllocator__AddressTempAllocator_97bb9d08 @ 0x97bb9d08 (4 bytes) */
int AddressTempAllocator__AddressTempAllocator_97bb9d08(this)
  unsigned char * this;
{
  AddressTempAllocator(this);
  return;
}

/* AddressTempAllocator__AddressTempAllocator_97bb9d0c @ 0x97bb9d0c (16 bytes) */
int AddressTempAllocator__AddressTempAllocator_97bb9d0c(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* AddressTempAllocator___AddressTempAllocator @ 0x97bb9d1c (8 bytes) */
int AddressTempAllocator___AddressTempAllocator(this)
  unsigned char * this;
{
  ~AddressTempAllocator(this);
  return;
}

/* AddressTempAllocator___AddressTempAllocator_97bb9d24 @ 0x97bb9d24 (8 bytes) */
int AddressTempAllocator___AddressTempAllocator_97bb9d24(this)
  unsigned char * this;
{
  ~AddressTempAllocator(this);
  return;
}

/* AddressTempAllocator___AddressTempAllocator_97bb9d2c @ 0x97bb9d2c (16 bytes) */
int AddressTempAllocator___AddressTempAllocator_97bb9d2c(this)
  unsigned char * this;
{
  if (*(void **)this == (void *)0x0) {
    return;
  }
  _free(*(void **)this);
  return;
}

/* AddressTempAllocator__getTemporary @ 0x97bb9d3c (316 bytes) */
int AddressTempAllocator__getTemporary(this)
  unsigned char * this;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  uVar9 = 0;
  uVar3 = *(uint *)(this + 4);
  iVar8 = 0;
  if (uVar3 != 0) {
    piVar5 = *(int **)this;
    iVar2 = *piVar5;
    while (iVar2 != 0) {
      uVar9 = uVar9 + 1;
      iVar8 = uVar9 * 4;
      if (uVar3 <= uVar9) break;
      piVar5 = piVar5 + 1;
      iVar2 = *piVar5;
    }
  }
  if (uVar3 <= uVar9) {
    pvVar4 = _malloc(uVar3 * 4 + 0x40);
    iVar2 = *(int *)(this + 4);
    iVar7 = 0;
    if (iVar2 != 0) {
      iVar6 = *(int *)this;
      iVar10 = iVar2;
      do {
        iVar1 = iVar7 * 4;
        iVar7 = iVar7 + 1;
        *(undefined4 *)(iVar1 + (int)pvVar4) = *(undefined4 *)(iVar1 + iVar6);
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    _memset((void *)(iVar2 * 4 + (int)pvVar4),0,0x40);
    if (*(void **)this != (void *)0x0) {
      _free(*(void **)this);
    }
    *(void **)this = pvVar4;
    uVar3 = *(int *)(this + 4) + 0x10;
    *(uint *)(this + 4) = uVar3;
    if (uVar9 < uVar3) {
      if (*(int *)(iVar8 + (int)pvVar4) != 0) {
        piVar5 = (int *)(uVar9 * 4 + (int)pvVar4);
        do {
          uVar9 = uVar9 + 1;
          iVar8 = uVar9 * 4;
          if (uVar3 <= uVar9) break;
          piVar5 = piVar5 + 1;
        } while (*piVar5 != 0);
      }
      goto LAB_97bb9e58;
    }
  }
  pvVar4 = *(void **)this;
LAB_97bb9e58:
  *(undefined4 *)(iVar8 + (int)pvVar4) = 1;
  return uVar9;
}

/* AddressTempAllocator__releaseTemporary @ 0x97bb9e78 (20 bytes) */
int AddressTempAllocator__releaseTemporary(this, param_1)
  unsigned char * this;
  uint param_1;
{
  *(undefined4 *)(param_1 * 4 + *(int *)this) = 0;
  return;
}

/* TemporaryAllocator__TemporaryAllocator @ 0x97bb9e8c (4 bytes) */
int TemporaryAllocator__TemporaryAllocator(this)
  unsigned char * this;
{
  int iVar1;
  
  iVar1 = 0x19;
  do {
    *(undefined4 *)this = 0;
    *(undefined4 *)(this + 100) = 0;
    this = this + 4;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

