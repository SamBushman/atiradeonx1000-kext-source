#include "decls.h"

/* TGenericLinker__MergeCompilers @ 0x97bb21dc (200 bytes) */
int TGenericLinker__MergeCompilers(this, param_2)
  unsigned char * this;
  int param_2;
{
  bool bVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  unsigned char * pTVar5;
  unsigned char * pTVar6;
  unsigned char * pTVar7;
  int iVar8;
  char *pcVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  char *pcVar16;
  undefined4 uVar17;
  unsigned char * pPVar18;
  unsigned char * p_Var19;
  uint uVar20;
  byte *pbVar21;
  bool bVar22;
  int iVar23;
  undefined4 *puVar24;
  unsigned char * this_00;
  int iVar25;
  int iVar26;
  void *pvVar27;
  unsigned char * pTVar28;
  unsigned char * p_Var29;
  char local_70 [16];
  int local_60;
  unsigned char * local_5c;
  unsigned char * local_58;
  unsigned char * local_54;
  
  iVar4 = param_2 * 4;
  iVar11 = _malloc(*(int *)(this + iVar4 + 0x20) << 2);
  iVar12 = _malloc(*(int *)(this + iVar4 + 0x20) << 2);
  pcVar9 = DAT_a7b7bb0c;
  iVar8 = *(int *)(this + iVar4 + 0x20);
  local_60 = 0;
  if (10000 < iVar8) {
    pvVar27 = *(void **)(this + 0x84);
                    
    __ZN13TInfoSinkBase6appendEPKc(pvVar27,"ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(pvVar27,pcVar9);
    __ZN13TInfoSinkBase6appendEPKc(pvVar27,"\n");
  }
  bVar22 = 10000 >= iVar8;
  if (bVar22) {
    uVar13 = _PPStreamCreate();
    *(undefined4 *)(this + iVar4 + 0x30) = uVar13;
    pvVar27 = operator_new(0x54);
    __ZN16ParseSymbolTableC1Ej(pvVar27,0x80);
    *(void **)(this + iVar4 + 0x28) = pvVar27;
    *(undefined4 *)((int)pvVar27 + 0xc) = *(undefined4 *)(this + iVar4 + 0x30);
    if (param_2 == 0) {
      **(undefined4 **)(this + 0x30) = 0x8b31;
      local_60 = 0;
      *(undefined4 *)(*(int *)(this + 0x28) + 0x3c) = 0;
    }
    else {
      **(undefined4 **)(this + iVar4 + 0x30) = 0x8b30;
      local_60 = 1;
      *(undefined4 *)(*(int *)(this + iVar4 + 0x28) + 0x3c) = 1;
    }
  }
  if (bVar22) {
    pTVar28 = this + iVar4;
    iVar8 = 0;
    iVar23 = 0;
    _memset(iVar11,0,*(int *)(pTVar28 + 0x20) << 2);
    _memset(iVar12,0,*(int *)(pTVar28 + 0x20) << 2);
    pTVar5 = pTVar28;
    pTVar6 = pTVar28;
    pTVar7 = pTVar28;
    if (0 < *(int *)(pTVar28 + 0x20)) {
      do {
        local_54 = pTVar7;
        local_58 = pTVar6;
        local_5c = pTVar5;
        iVar10 = iVar8 * 4;
        iVar26 = **(int **)(*(int *)(iVar10 + *(int *)(pTVar28 + 0x18)) + 0x20);
        while (iVar26 != 0) {
          iVar14 = _PPStreamChunkCreateFromChunk(iVar26);
          _PPStreamChunkListAddChunk(*(undefined4 *)(*(int *)(pTVar28 + 0x30) + 0x20),iVar14);
          if (*(int *)(iVar10 + iVar11) == 0) {
            *(int *)(iVar10 + iVar11) = iVar14;
          }
          uVar20 = *(uint *)(iVar14 + 0x10);
          *(uint *)(iVar14 + 0xc) =
               (*(uint *)(iVar14 + 0xc) & 0x3ffff) + iVar23 & 0x3ffff |
               *(uint *)(iVar14 + 0xc) & 0xfffc0000;
          if ((uVar20 & 0x3ffff) != 0) {
            *(uint *)(iVar14 + 0x10) = (uVar20 & 0x3ffff) + iVar23 & 0x3ffff | uVar20 & 0xfffc0000;
          }
          if (*(int *)(iVar14 + 0x40) != 0) {
            iVar25 = iVar14 + 0x44;
            uVar13 = _strlen("gl__WhileBody_");
            iVar15 = _strncmp(iVar25,"gl__WhileBody_",uVar13);
            if (iVar15 != 0) {
              uVar13 = _strlen("gl__WhileEnd_");
              iVar15 = _strncmp(iVar25,"gl__WhileEnd_",uVar13);
              if (iVar15 != 0) {
                uVar13 = _strlen("gl__WhileStart_");
                iVar15 = _strncmp(iVar25,"gl__WhileStart_",uVar13);
                if (iVar15 != 0) {
                  uVar13 = _strlen("gl__WhileEndIf_");
                  iVar15 = _strncmp(iVar25,"gl__WhileEndIf_",uVar13);
                  if (iVar15 != 0) {
                    uVar13 = _strlen("gl__IfElse");
                    iVar15 = _strncmp(iVar25,"gl__IfElse",uVar13);
                    if (iVar15 != 0) {
                      uVar13 = _strlen("gl__IfEnd_");
                      iVar15 = _strncmp(iVar25,"gl__IfEnd_",uVar13);
                      if (iVar15 != 0) goto code_r0x97bb257c;
                    }
                  }
                }
              }
            }
            _sprintf(local_70,"%04d",iVar8);
            pcVar16 = (char *)(iVar14 + 0x44);
            pcVar9 = local_70;
            iVar14 = 4;
            do {
              cVar2 = *pcVar9;
              pcVar9 = pcVar9 + 1;
              *pcVar16 = cVar2;
              pcVar16 = pcVar16 + 1;
              iVar14 = iVar14 + -1;
            } while (iVar14 != 0);
          }
code_r0x97bb257c:
          iVar26 = *(int *)(iVar26 + 8);
          *(int *)(iVar10 + iVar12) = *(int *)(iVar10 + iVar12) + 1;
        }
        pTVar5 = local_5c;
        pTVar6 = local_54;
        for (iVar26 = **(int **)(*(int *)(iVar10 + *(int *)(pTVar28 + 0x18)) + 0x24);
            local_5c = pTVar5, local_54 = pTVar6, iVar26 != 0; iVar26 = *(int *)(iVar26 + 8)) {
          iVar14 = _PPStreamChunkCreateFromChunk(iVar26);
          _PPStreamChunkListAddChunk(*(undefined4 *)(*(int *)(pTVar28 + 0x30) + 0x24),iVar14);
          *(int *)(iVar14 + 0xc) = *(int *)(iVar14 + 0xc) + iVar23;
          if (*(int *)(iVar14 + 0x10) != 0) {
            iVar25 = iVar14 + 0x14;
            uVar13 = _strlen("gl__WhileBody_");
            iVar15 = _strncmp(iVar25,"gl__WhileBody_",uVar13);
            if (iVar15 != 0) {
              uVar13 = _strlen("gl__WhileEnd_");
              iVar15 = _strncmp(iVar25,"gl__WhileEnd_",uVar13);
              if (iVar15 != 0) {
                uVar13 = _strlen("gl__WhileStart_");
                iVar15 = _strncmp(iVar25,"gl__WhileStart_",uVar13);
                if (iVar15 != 0) {
                  uVar13 = _strlen("gl__WhileEndIf_");
                  iVar15 = _strncmp(iVar25,"gl__WhileEndIf_",uVar13);
                  if (iVar15 != 0) {
                    uVar13 = _strlen("gl__IfElse");
                    iVar15 = _strncmp(iVar25,"gl__IfElse",uVar13);
                    if (iVar15 != 0) {
                      uVar13 = _strlen("gl__IfEnd_");
                      iVar15 = _strncmp(iVar25,"gl__IfEnd_",uVar13);
                      if (iVar15 != 0) goto code_r0x97bb26e0;
                    }
                  }
                }
              }
            }
            _sprintf(local_70,"%04d",iVar8);
            pcVar16 = (char *)(iVar14 + 0x14);
            pcVar9 = local_70;
            iVar14 = 4;
            do {
              cVar2 = *pcVar9;
              pcVar9 = pcVar9 + 1;
              *pcVar16 = cVar2;
              pcVar16 = pcVar16 + 1;
              iVar14 = iVar14 + -1;
            } while (iVar14 != 0);
          }
code_r0x97bb26e0:
          pTVar5 = local_5c;
          pTVar6 = local_54;
        }
        iVar14 = 0;
        this_00 = *(unsigned char **)(*(int *)(iVar10 + *(int *)(pTVar28 + 8)) + 0x6c);
        iVar26 = *(int *)(this_00 + 4);
        if (0 < iVar26) {
          do {
            iVar15 = 0;
            if (0 < *(int *)(*(int *)(pTVar5 + 0x38) + 4)) {
              do {
                uVar13 = FunctionTable__getFunctionName(*(unsigned char **)(pTVar6 + 0x38),iVar15);
                uVar17 = FunctionTable__getFunctionName(this_00,iVar14);
                iVar26 = _strcmp(uVar13,uVar17);
                if (iVar26 == 0) {
                  iVar26 = FunctionTable__getFirstOp(*(unsigned char **)(pTVar6 + 0x38),iVar15);
                  FunctionTable__setFirstOp
                            (*(unsigned char **)(pTVar6 + 0x38),iVar15,iVar26 + iVar23);
                  iVar26 = FunctionTable__getLastOp(*(unsigned char **)(pTVar6 + 0x38),iVar15);
                  FunctionTable__setLastOp
                            (*(unsigned char **)(pTVar6 + 0x38),iVar15,iVar26 + iVar23);
                }
                iVar15 = iVar15 + 1;
              } while (iVar15 < *(int *)(*(int *)(pTVar6 + 0x38) + 4));
              iVar26 = *(int *)(this_00 + 4);
            }
            iVar14 = iVar14 + 1;
          } while (iVar14 < iVar26);
        }
        iVar23 = iVar23 + *(int *)(iVar10 + iVar12);
        if (*(int *)(*(int *)(iVar10 + *(int *)(local_58 + 8)) + 0xa4) != 0) {
          local_60 = 1;
        }
        iVar8 = iVar8 + 1;
        pTVar5 = local_5c;
        pTVar6 = local_58;
        pTVar7 = local_54;
      } while (iVar8 < *(int *)(local_58 + 0x20));
    }
    pcVar9 = UNK_a7b7bb10;
    if (local_60 == 0) {
      pvVar27 = *(void **)(this + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(pvVar27,"ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(pvVar27,pcVar9);
      bVar22 = false;
      __ZN13TInfoSinkBase6appendEPKc(pvVar27,"\n");
    }
  }
  if (bVar22) {
    iVar8 = 1;
    do {
      iVar23 = 0;
      if (0 < *(int *)(this + iVar4 + 0x20)) {
        do {
          iVar10 = iVar23 * 4;
          for (pPVar18 = (unsigned char *)
                         ParseSymbolTable__NextSymbol
                                   (*(unsigned char **)(iVar10 + *(int *)(this + iVar4 + 0x10)),
                                    (unsigned char *)0x0); pPVar18 != (unsigned char *)0x0;
              pPVar18 = (unsigned char *)
                        ParseSymbolTable__NextSymbol
                                  (*(unsigned char **)(iVar10 + *(int *)(this + iVar4 + 0x10)),
                                   pPVar18)) {
            if (iVar8 == *(int *)(pPVar18 + 0x54)) {
              puVar24 = (undefined4 *)0x0;
              if (*(int *)(pPVar18 + 0x38) == 0) {
                bVar1 = true;
code_r0x97bb2ab4:
                if (bVar1) goto code_r0x97bb2ab8;
              }
              else {
                puVar24 = (undefined4 *)
                          ParseSymbolTable__FindGlobalSymbolByName
                                    (*(unsigned char **)(this + iVar4 + 0x28),
                                     *(char **)(pPVar18 + 0x14));
                bVar1 = puVar24 == (undefined4 *)0x0;
                if (!bVar1) {
                  if (*(short *)(puVar24 + 0xb) == *(short *)(pPVar18 + 0x2c)) {
                    if (*(short *)((int)puVar24 + 0x2e) == *(short *)(pPVar18 + 0x2e))
                    goto code_r0x97bb2ab4;
                    uVar13 = puVar24[5];
                    iVar26 = _strlen(UNK_a7b7bb18);
                    iVar14 = _strlen(uVar13);
                    iVar15 = _strlen((&_shaderString)[param_2]);
                    pcVar9 = (char *)_malloc(iVar26 + iVar14 + iVar15 + 1);
                    _sprintf(pcVar9,UNK_a7b7bb18,uVar13,(&_shaderString)[param_2]);
                    pvVar27 = *(void **)(this + 0x84);
                    
                  }
                  else {
                    uVar13 = puVar24[5];
                    iVar26 = _strlen(UNK_a7b7bb14);
                    iVar14 = _strlen(uVar13);
                    iVar15 = _strlen((&_shaderString)[param_2]);
                    pcVar9 = (char *)_malloc(iVar26 + iVar14 + iVar15 + 1);
                    _sprintf(pcVar9,UNK_a7b7bb14,uVar13,(&_shaderString)[param_2]);
                    pvVar27 = *(void **)(this + 0x84);
                    
                  }
                  __ZN13TInfoSinkBase6appendEPKc(pvVar27,"ERROR: ");
                  __ZN13TInfoSinkBase6appendEPKc(pvVar27,pcVar9);
                  __ZN13TInfoSinkBase6appendEPKc(pvVar27,"\n");
                  _free(pcVar9);
                  bVar22 = false;
                  goto code_r0x97bb2ab4;
                }
code_r0x97bb2ab8:
                uVar13 = 0;
                uVar17 = 0;
                if ((iVar8 != 0) && (pbVar21 = *(byte **)pPVar18, pbVar21 != (byte *)0x0)) {
                  bVar3 = *pbVar21;
                  if (bVar3 != 2) {
                    if (bVar3 < 3) {
                      if ((bVar3 == 0) &&
                         (iVar26 = **(int **)(*(int *)(iVar10 + *(int *)(this + iVar4 + 0x18)) + 8),
                         iVar26 != 0)) {
                        do {
                          if (*(short *)(pbVar21 + 0x12) == *(short *)(iVar26 + 0xe)) {
                            uVar13 = 1;
                          }
                          if (*(short *)(pbVar21 + 0x12) == *(short *)(iVar26 + 0x12)) {
                            uVar17 = 1;
                          }
                          iVar26 = *(int *)(iVar26 + 8);
                        } while (iVar26 != 0);
                      }
                    }
                    else if ((bVar3 == 3) &&
                            (iVar26 = **(int **)(*(int *)(iVar10 + *(int *)(this + iVar4 + 0x18)) +
                                                0x14), iVar26 != 0)) {
                      do {
                        if (*(short *)(pbVar21 + 0x12) == *(short *)(iVar26 + 0xe)) {
                          uVar13 = 1;
                        }
                        if (*(short *)(pbVar21 + 0x12) == *(short *)(iVar26 + 0x12)) {
                          uVar17 = 1;
                        }
                        iVar26 = *(int *)(iVar26 + 8);
                      } while (iVar26 != 0);
                    }
                  }
                }
                puVar24 = (undefined4 *)
                          ParseSymbolTable__AddFromExternalSymbol
                                    (*(unsigned char **)(this + iVar4 + 0x28),pPVar18,uVar13,
                                     uVar17);
              }
              if ((bVar22 != true) || (puVar24 == (undefined4 *)0x0)) {
                if ((bVar22 == true) && (puVar24 == (undefined4 *)0x0)) {
                  uVar13 = *(undefined4 *)(pPVar18 + 0x14);
                  iVar26 = _strlen(DAT_a7b7bbc0);
                  iVar14 = _strlen(uVar13);
                  pcVar9 = (char *)_malloc(iVar26 + iVar14 + 1);
                  _sprintf(pcVar9,UNK_a7b7bb90,uVar13);
                  pvVar27 = *(void **)(this + 0x84);
                    
                  __ZN13TInfoSinkBase6appendEPKc(pvVar27,"ERROR: ");
                  __ZN13TInfoSinkBase6appendEPKc(pvVar27,pcVar9);
                  __ZN13TInfoSinkBase6appendEPKc(pvVar27,"\n");
                  _free(pcVar9);
                  bVar22 = false;
                }
              }
              else {
                iVar26 = TGenericLinker__FindChunkDelta(this,*(unsigned char **)pPVar18,(unsigned char *)*puVar24)
                ;
                if (iVar26 != 0) {
                  iVar14 = ((int (*)())GetVec4sForType)((uint)*(ushort *)(pPVar18 + 0x2c));
                  UpdateOperations(*(unsigned char **)(iVar10 + iVar11),
                                   (unsigned char *)
                                   **(undefined4 **)
                                     (*(int *)(iVar10 + *(int *)(this + iVar4 + 0x18)) + 0x20),
                                   *(int *)(iVar10 + iVar12),*(unsigned char **)pPVar18,iVar14,
                                   iVar26);
                }
              }
            }
          }
          iVar23 = iVar23 + 1;
        } while (iVar23 < *(int *)(this + iVar4 + 0x20));
      }
      iVar8 = iVar8 + -1;
    } while (-1 < iVar8);
    if (bVar22 == true) {
      iVar8 = 0;
      if (0 < *(int *)(this + iVar4 + 0x20)) {
        do {
          iVar23 = iVar8 * 4;
          for (p_Var29 = (unsigned char *)
                         **(undefined4 **)(*(int *)(iVar23 + *(int *)(this + iVar4 + 0x18)) + 0x10);
              p_Var29 != (unsigned char *)0x0; p_Var29 = *(unsigned char **)(p_Var29 + 8)) {
            uVar20 = *(uint *)(p_Var29 + 0xc);
            if ((uVar20 & 0x1f0000) == 0x110000) {
              iVar10 = *(int *)(*(int *)(this + iVar4 + 0x28) + 0x24);
              *(int *)(*(int *)(this + iVar4 + 0x28) + 0x24) = iVar10 + 1;
              p_Var19 = (unsigned char *)_PPStreamChunkCreateFromChunk(p_Var29);
              _PPStreamChunkListAddChunk
                        (*(undefined4 *)(*(int *)(this + iVar4 + 0x30) + 0x10),p_Var19);
              *(short *)(p_Var19 + 0x12) = (short)iVar10;
              iVar10 = TGenericLinker__FindChunkDelta(this,p_Var29,p_Var19);
              UpdateOperations(*(unsigned char **)(iVar23 + iVar11),
                               (unsigned char *)
                               **(undefined4 **)
                                 (*(int *)(iVar23 + *(int *)(this + iVar4 + 0x18)) + 0x20),
                               *(int *)(iVar23 + iVar12),p_Var29,1,iVar10);
              *(undefined2 *)(p_Var19 + 0xe) =
                   *(undefined2 *)(*(int *)(*(int *)(this + iVar4 + 0x30) + 0x2c) + 10);
              iVar10 = _PPStreamChunkListChunkAtIndex
                                 (*(undefined4 *)
                                   (*(int *)(iVar23 + *(int *)(this + iVar4 + 0x18)) + 0x2c),
                                  uVar20 & 0xffff);
              _PPStreamAddConstant(*(undefined4 *)(this + iVar4 + 0x30),iVar10 + 0xc);
            }
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < *(int *)(this + iVar4 + 0x20));
      }
      iVar11 = 0;
      iVar8 = 0;
      if (0 < *(int *)(this + iVar4 + 0x20)) {
        do {
          iVar12 = 0;
          for (iVar23 = **(int **)(*(int *)(iVar11 * 4 + *(int *)(this + iVar4 + 0x18)) + 0xc);
              iVar23 != 0; iVar23 = *(int *)(iVar23 + 8)) {
            iVar12 = iVar12 + 1;
            if (iVar8 < iVar12) {
              uVar13 = _PPStreamChunkCreateFromChunk(iVar23);
              _PPStreamChunkListAddChunk
                        (*(undefined4 *)(*(int *)(this + iVar4 + 0x30) + 0xc),uVar13);
              iVar8 = iVar12;
            }
          }
          iVar11 = iVar11 + 1;
        } while (iVar11 < *(int *)(this + iVar4 + 0x20));
      }
      iVar8 = 0;
      if (0 < *(int *)(this + iVar4 + 0x20)) {
        do {
          for (iVar11 = **(int **)(*(int *)(iVar8 * 4 + *(int *)(this + iVar4 + 0x18)) + 0x30);
              iVar11 != 0; iVar11 = *(int *)(iVar11 + 8)) {
            iVar12 = **(int **)(*(int *)(this + iVar4 + 0x30) + 0x30);
            if (iVar12 != 0) {
              do {
                if (*(char *)(iVar12 + 0xf) == *(char *)(iVar11 + 0xf)) goto code_r0x97bb2f70;
                iVar12 = *(int *)(iVar12 + 8);
              } while (iVar12 != 0);
            }
            uVar13 = _PPStreamChunkCreateFromChunk(iVar11);
            _PPStreamChunkListAddChunk(*(undefined4 *)(*(int *)(this + iVar4 + 0x30) + 0x30),uVar13)
            ;
code_r0x97bb2f70: ;
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < *(int *)(this + iVar4 + 0x20));
      }
    }
  }
  if (bVar22 == false) {
    if (*(int *)(this + iVar4 + 0x30) != 0) {
      _PPStreamFree(*(int *)(this + iVar4 + 0x30));
    }
    pvVar27 = *(void **)(this + iVar4 + 0x28);
    *(undefined4 *)(this + iVar4 + 0x30) = 0;
    if (pvVar27 != (void *)0x0) {
      __ZN16ParseSymbolTableD1Ev(pvVar27);
      __ZdlPv(pvVar27);
    }
    *(undefined4 *)(this + iVar4 + 0x28) = 0;
  }
  return bVar22;
}

/* TGenericLinker__CreateFromStreamWithSymbolTableUpdate @ 0x97bb2ff0 (820 bytes) */
int TGenericLinker__CreateFromStreamWithSymbolTableUpdate(this, param_2, param_3)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
{
  char *pcVar1;
  undefined4 *puVar2;
  unsigned char * p_Var3;
  undefined4 uVar4;
  unsigned char * p_Var5;
  int iVar6;
  void *this_00;
  
  puVar2 = (undefined4 *)_PPStreamCreate();
  *puVar2 = *(undefined4 *)param_2;
  *(undefined4 **)(param_3 + 0xc) = puVar2;
  for (p_Var5 = (unsigned char *)**(undefined4 **)(param_2 + 4); p_Var5 != (unsigned char *)0x0;
      p_Var5 = *(unsigned char **)(p_Var5 + 8)) {
    p_Var3 = (unsigned char *)_PPStreamChunkCreateFromChunk(p_Var5);
    _PPStreamChunkListAddChunk(puVar2[1],p_Var3);
    ParseSymbolTable__ChangeChunk(param_3,p_Var5,p_Var3,1);
  }
  for (iVar6 = **(int **)(param_2 + 8); iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
    uVar4 = _PPStreamChunkCreateFromChunk(iVar6);
    _PPStreamChunkListAddChunk(puVar2[2],uVar4);
  }
  for (iVar6 = **(int **)(param_2 + 0xc); iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
    uVar4 = _PPStreamChunkCreateFromChunk(iVar6);
    _PPStreamChunkListAddChunk(puVar2[3],uVar4);
  }
  for (p_Var5 = (unsigned char *)**(undefined4 **)(param_2 + 0x10); p_Var5 != (unsigned char *)0x0
      ; p_Var5 = *(unsigned char **)(p_Var5 + 8)) {
    p_Var3 = (unsigned char *)_PPStreamChunkCreateFromChunk(p_Var5);
    _PPStreamChunkListAddChunk(puVar2[4],p_Var3);
    ParseSymbolTable__ChangeChunk(param_3,p_Var5,p_Var3,1);
  }
  for (iVar6 = **(int **)(param_2 + 0x14); iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
    uVar4 = _PPStreamChunkCreateFromChunk(iVar6);
    _PPStreamChunkListAddChunk(puVar2[5],uVar4);
  }
  for (p_Var5 = (unsigned char *)**(undefined4 **)(param_2 + 0x18); p_Var5 != (unsigned char *)0x0
      ; p_Var5 = *(unsigned char **)(p_Var5 + 8)) {
    p_Var3 = (unsigned char *)_PPStreamChunkCreateFromChunk(p_Var5);
    _PPStreamChunkListAddChunk(puVar2[6],p_Var3);
    ParseSymbolTable__ChangeChunk(param_3,p_Var5,p_Var3,1);
  }
  for (p_Var5 = (unsigned char *)**(undefined4 **)(param_2 + 0x1c); p_Var5 != (unsigned char *)0x0
      ; p_Var5 = *(unsigned char **)(p_Var5 + 8)) {
    p_Var3 = (unsigned char *)_PPStreamChunkCreateFromChunk(p_Var5);
    _PPStreamChunkListAddChunk(puVar2[7],p_Var3);
    ParseSymbolTable__ChangeChunk(param_3,p_Var5,p_Var3,1);
  }
  for (iVar6 = **(int **)(param_2 + 0x20); iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
    uVar4 = _PPStreamChunkCreateFromChunk(iVar6);
    _PPStreamChunkListAddChunk(puVar2[8],uVar4);
  }
  for (iVar6 = **(int **)(param_2 + 0x24); iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
    uVar4 = _PPStreamChunkCreateFromChunk(iVar6);
    _PPStreamChunkListAddChunk(puVar2[9],uVar4);
  }
  for (iVar6 = **(int **)(param_2 + 0x2c); iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
    uVar4 = _PPStreamChunkCreateFromChunk(iVar6);
    _PPStreamChunkListAddChunk(puVar2[0xb],uVar4);
  }
  for (iVar6 = **(int **)(param_2 + 0x28); iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
    uVar4 = _PPStreamChunkCreateFromChunk(iVar6);
    _PPStreamChunkListAddChunk(puVar2[10],uVar4);
  }
  for (iVar6 = **(int **)(param_2 + 0x30); iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
    uVar4 = _PPStreamChunkCreateFromChunk(iVar6);
    _PPStreamChunkListAddChunk(puVar2[0xc],uVar4);
  }
  iVar6 = _PPStreamCompare(param_2,puVar2);
  pcVar1 = DAT_a7b7bb88;
  if (iVar6 == 1) {
    this_00 = *(void **)(this + 0x84);
                    
    __ZN13TInfoSinkBase6appendEPKc(this_00,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(this_00,pcVar1);
    __ZN13TInfoSinkBase6appendEPKc(this_00,"\n");
    _PPStreamFree(puVar2);
    puVar2 = (undefined4 *)0x0;
  }
  return puVar2;
}

/* TGenericLinker__RemoveUnreachableFunctions @ 0x97bb33bc (480 bytes) */
int TGenericLinker__RemoveUnreachableFunctions(this)
  unsigned char * this;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  char *pcVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  void *pvVar13;
  int iVar14;
  
  iVar10 = 0;
code_r0x97bb33e4:
  iVar2 = iVar10 * 4;
code_r0x97bb33e8:
  bVar1 = false;
  iVar11 = 0;
  if ((*(int *)(this + iVar2 + 0x38) != 0) && (0 < *(int *)(*(int *)(this + iVar2 + 0x38) + 4))) {
code_r0x97bb3410:
    uVar3 = FunctionTable__getFunctionName(*(unsigned char **)(this + iVar2 + 0x38),iVar11);
    iVar4 = _memcmp(uVar3,"main(",6);
    iVar14 = iVar11;
    if (iVar4 != 0) {
      for (iVar4 = **(int **)(*(int *)(this + iVar2 + 0x30) + 0x20); iVar4 != 0;
          iVar4 = *(int *)(iVar4 + 8)) {
        if ((((*(uint *)(iVar4 + 0xc) & 0x3fc0000) == 0x1300000) && (*(int *)(iVar4 + 0x40) != 0))
           && (iVar5 = _strcmp(iVar4 + 0x44,uVar3), iVar5 == 0)) goto LAB_97bb37a8;
      }
      for (iVar14 = **(int **)(*(int *)(this + iVar2 + 0x30) + 0x20); iVar14 != 0;
          iVar14 = *(int *)(iVar14 + 8)) {
        uVar12 = *(uint *)(iVar14 + 0xc);
        uVar6 = FunctionTable__getFirstOp(*(unsigned char **)(this + iVar2 + 0x38),iVar11);
        if ((uVar12 & 0x3ffff) == uVar6) {
          bVar1 = false;
          goto LAB_97bb361c;
        }
      }
      iVar14 = _strlen(DAT_a7b7baec);
      iVar4 = _strlen((&_shaderString)[iVar10]);
      iVar5 = _strlen(uVar3);
      pcVar8 = (char *)_malloc(iVar14 + iVar4 + iVar5 + 9);
      uVar9 = FunctionTable__getFirstOp(*(unsigned char **)(this + iVar2 + 0x38),iVar11);
      _sprintf(pcVar8,DAT_a7b7baec,uVar3,(&_shaderString)[iVar10],uVar9);
      pvVar13 = *(void **)(this + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(pvVar13,"INTERNAL ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(pvVar13,pcVar8);
      __ZN13TInfoSinkBase6appendEPKc(pvVar13,"\n");
      _free(pcVar8);
      goto code_r0x97bb3790;
    }
    goto LAB_97bb37a8;
  }
  goto LAB_97bb37d4;
  while( true ) {
    if ((*(uint *)(iVar14 + 0xc) & 0x3ffff) == 0) {
      iVar4 = _strlen(DAT_a7b7baf0);
      iVar5 = _strlen((&_shaderString)[iVar10]);
      iVar7 = _strlen(uVar3);
      pcVar8 = (char *)_malloc(iVar4 + iVar5 + iVar7 + 1);
      _sprintf(pcVar8,DAT_a7b7baf0,uVar3,(&_shaderString)[iVar10]);
      pvVar13 = *(void **)(this + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(pvVar13,"INTERNAL ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(pvVar13,pcVar8);
      __ZN13TInfoSinkBase6appendEPKc(pvVar13,"\n");
      _free(pcVar8);
    }
    else {
      _PPStreamRemoveLabelsAtOperationIndex
                (*(undefined4 *)(this + iVar2 + 0x30),*(uint *)(iVar14 + 0xc) & 0x3ffff);
      iVar4 = *(int *)(iVar14 + 8);
      bVar1 = iVar4 == 0;
      if (!bVar1) {
        *(uint *)(iVar4 + 0xc) =
             (*(uint *)(iVar14 + 0xc) >> 0x1a & 7) << 0x1a | *(uint *)(iVar4 + 0xc) & 0xe3ffffff;
      }
      _PPStreamChunkListRemoveChunk(*(undefined4 *)(*(int *)(this + iVar2 + 0x30) + 0x20),iVar14);
      iVar14 = iVar4;
    }
    if (bVar1) break;
LAB_97bb361c:
    uVar12 = *(uint *)(iVar14 + 0xc);
    uVar6 = FunctionTable__getLastOp(*(unsigned char **)(this + iVar2 + 0x38),iVar11);
    if ((uVar12 & 0x3ffff) == uVar6) {
      if (!bVar1) {
        iVar4 = *(int *)(iVar14 + 8);
        if (iVar4 != 0) {
          *(uint *)(iVar4 + 0xc) =
               (*(uint *)(iVar14 + 0xc) >> 0x1a & 7) << 0x1a | *(uint *)(iVar4 + 0xc) & 0xe3ffffff;
        }
        uVar12 = *(uint *)(iVar14 + 0xc);
        uVar6 = FunctionTable__getLastOp(*(unsigned char **)(this + iVar2 + 0x38),iVar11);
        if ((uVar12 & 0x3ffff) == uVar6) {
          _PPStreamChunkListRemoveChunk
                    (*(undefined4 *)(*(int *)(this + iVar2 + 0x30) + 0x20),iVar14);
        }
      }
      break;
    }
  }
code_r0x97bb3790:
  iVar14 = iVar11 + -1;
  bVar1 = true;
  FunctionTable__removeFunction(*(unsigned char **)(this + iVar2 + 0x38),iVar11);
LAB_97bb37a8:
  iVar11 = iVar14 + 1;
  if ((*(int *)(this + iVar2 + 0x38) == 0) ||
     (*(int *)(*(int *)(this + iVar2 + 0x38) + 4) <= iVar11)) goto code_r0x97bb37cc;
  goto code_r0x97bb3410;
code_r0x97bb37cc:
  if (!bVar1) goto LAB_97bb37d4;
  goto code_r0x97bb33e8;
LAB_97bb37d4:
  iVar10 = iVar10 + 1;
  if (1 < iVar10) {
    return;
  }
  goto code_r0x97bb33e4;
}

/* TGenericLinker__RenumberLabels @ 0x97bb37fc (40 bytes) */
int TGenericLinker__RenumberLabels(this, param_2, param_3, param_4)
  unsigned char * this;
  unsigned char * param_2;
  uint param_3;
  uint param_4;
{
  if (param_2 != (unsigned char *)0x0) {
    do {
      if (param_3 == *(uint *)(param_2 + 0xc)) {
        *(uint *)(param_2 + 0xc) = param_4;
      }
      param_2 = *(unsigned char **)(param_2 + 8);
    } while (param_2 != (unsigned char *)0x0);
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
      pPVar4 = (unsigned char *)
               ParseSymbolTable__NextSymbol
                         (*(unsigned char **)(pTVar11 + 0x28),(unsigned char *)0x0);
      while (this_00 = pPVar4, this_00 != (unsigned char *)0x0) {
        iVar16 = *(int *)(this_00 + 0x54);
        pbVar12 = *(byte **)this_00;
        iVar14 = **(int **)(*(int *)(pTVar11 + 0x30) + 0x20);
        if (iVar14 == 0) {
          bVar1 = iVar16 == 0;
LAB_97bb3a3c:
          if (!bVar1) goto LAB_97bb3b10;
          pPVar4 = (unsigned char *)
                   ParseSymbolTable__NextSymbol(*(unsigned char **)(pTVar11 + 0x28),this_00);
          ParseSymbolTable__RemoveSymbol(*(unsigned char **)(pTVar11 + 0x28),this_00);
          for (iVar14 = 0; iVar16 = ((int (*)())GetVec4sForType)((uint)*(ushort *)(this_00 + 0x2c)),
              iVar14 < iVar16; iVar14 = iVar14 + 1) {
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
            __ZN11ParseSymbolD1Ev(this_00);
            __ZdlPv(this_00);
          }
        }
        else {
          bVar1 = iVar16 == 0;
          if (bVar1) {
            do {
              iVar13 = 0;
              while ((iVar5 = ((int (*)())GetVec4sForType)((uint)*(ushort *)(this_00 + 0x2c)), iVar13 < iVar5 &&
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
          pPVar4 = (unsigned char *)
                   ParseSymbolTable__NextSymbol(*(unsigned char **)(pTVar11 + 0x28),this_00);
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

/* TGenericLinker__RemoveExtraVertexOutputs @ 0x97bb3b58 (280 bytes) */
int TGenericLinker__RemoveExtraVertexOutputs(this)
  unsigned char * this;
{
  bool bVar1;
  unsigned char * pPVar2;
  unsigned char * pPVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  void *this_00;
  
  if (*(unsigned char **)(this + 0x28) != (unsigned char *)0x0) {
    pPVar3 = (unsigned char *)
             ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
joined_r0x97bb3b94:
    pPVar2 = pPVar3;
    if (pPVar2 != (unsigned char *)0x0) {
      pPVar3 = (unsigned char *)
               ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar2);
      if ((**(char **)pPVar2 == '\0') && (*(int *)(pPVar2 + 0x5c) != 0)) {
        pcVar8 = *(char **)(pPVar2 + 0x14);
        if (*(unsigned char **)(this + 0x2c) == (unsigned char *)0x0) {
          iVar4 = _strlen(DAT_a7b7bae0);
          iVar5 = _strlen(pcVar8);
          pcVar6 = (char *)_malloc(iVar4 + iVar5 + 1);
          bVar1 = true;
          pcVar7 = DAT_a7b7bae0;
        }
        else {
          iVar4 = ParseSymbolTable__FindGlobalSymbolByName
                            (*(unsigned char **)(this + 0x2c),pcVar8);
          bVar1 = iVar4 == 0;
          if (!bVar1) goto joined_r0x97bb3b94;
          iVar4 = _strlen(DAT_a7b7bad8);
          iVar5 = _strlen(pcVar8);
          pcVar6 = (char *)_malloc(iVar4 + iVar5 + 1);
          pcVar7 = DAT_a7b7bad8;
        }
        _sprintf(pcVar6,pcVar7,pcVar8);
        if (bVar1) {
          this_00 = *(void **)(this + 0x84);
                    
          __ZN13TInfoSinkBase6appendEPKc(this_00,"WARNING: ");
          __ZN13TInfoSinkBase6appendEPKc(this_00,pcVar6);
          __ZN13TInfoSinkBase6appendEPKc(this_00,"\n");
          _free(pcVar6);
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
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  unsigned char * pTVar9;
  int iVar10;
  uint uVar11;
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
  
  iVar8 = 0;
  iVar7 = 0;
  pTVar9 = this;
  do {
    if (*(int *)(pTVar9 + 0x30) != 0) {
      for (iVar10 = **(int **)(*(int *)(pTVar9 + 0x30) + 0x1c); iVar10 != 0;
          iVar10 = *(int *)(iVar10 + 8)) {
        bVar2 = false;
        uVar1 = *(ushort *)(iVar10 + 0x12);
        local_9c = **(int **)(*(int *)(pTVar9 + 0x30) + 0x20);
        if (local_9c != 0) {
          do {
            uVar11 = 0;
            uVar5 = *(uint *)(local_9c + 0xc) >> 0x1d;
            if (uVar5 != 0) {
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
                uVar11 = uVar11 + 1;
                iVar3 = iVar3 + 8;
              } while (uVar11 < uVar5);
            }
            local_9c = *(int *)(local_9c + 8);
          } while (local_9c != 0);
          if (bVar2) {
            local_a0 = 0;
            local_98 = local_9c;
            local_94 = local_9c;
            uVar4 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(*(int *)(pTVar9 + 0x30) + 4));
            local_9c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_9c) + 0)),(short)uVar4 + 1);
            local_a0 = (*(uint *)(iVar10 + 0xc) >> 0x18 & 3) << 0x18 |
                       (*(uint *)(iVar10 + 0xc) >> 0x1a & 7) << 0x1a |
                       *(uint *)(iVar10 + 0xc) & 0xe0000000 | local_a0 & 0xffffff;
            _PPStreamAddTempUsage(*(undefined4 *)(pTVar9 + 0x30),&local_a0);
            for (iVar3 = **(int **)(*(int *)(pTVar9 + 0x30) + 0x20); iVar3 != 0;
                iVar3 = *(int *)(iVar3 + 8)) {
              if (((*(uint *)(iVar3 + 0x14) & 0xe0000) == 0x60000) &&
                 (*(ushort *)(iVar3 + 0x1a) == uVar1)) {
                *(uint *)(iVar3 + 0x14) = *(uint *)(iVar3 + 0x14) & 0xfff1ffff | 0x20000;
                *(undefined2 *)(iVar3 + 0x1a) = (*(unsigned short *)((unsigned char *)&(local_9c) + 2));
              }
              uVar5 = *(uint *)(iVar3 + 0xc);
              uVar11 = 0;
              if (uVar5 >> 0x1d != 0) {
                iVar6 = iVar3 + 0x10;
                do {
                  if (((*(uint *)(iVar6 + 0xc) >> 0x17 & 7) == 3) &&
                     (*(ushort *)(iVar6 + 0x12) == uVar1)) {
                    *(uint *)(iVar6 + 0xc) = *(uint *)(iVar6 + 0xc) & 0xfc7fffff | 0x800000;
                    *(undefined2 *)(iVar6 + 0x12) = (*(unsigned short *)((unsigned char *)&(local_9c) + 2));
                    uVar5 = *(uint *)(iVar3 + 0xc);
                  }
                  uVar11 = uVar11 + 1;
                  iVar6 = iVar6 + 8;
                } while (uVar11 < uVar5 >> 0x1d);
              }
            }
            bVar2 = false;
            uVar5 = 0;
            uVar11 = 0;
            if ((*(int *)(pTVar9 + 0x38) != 0) && (*(int *)(*(int *)(pTVar9 + 0x38) + 4) != 0)) {
              do {
                uVar4 = FunctionTable__getFunctionName(*(unsigned char **)(pTVar9 + 0x38),uVar11);
                iVar3 = _memcmp(uVar4,"main(",6);
                if (iVar3 == 0) {
                  uVar5 = FunctionTable__getLastOp(*(unsigned char **)(pTVar9 + 0x38),uVar11);
                }
                uVar11 = uVar11 + 1;
              } while ((*(int *)(pTVar9 + 0x38) != 0) &&
                      (uVar11 < *(uint *)(*(int *)(pTVar9 + 0x38) + 4)));
            }
            for (iVar3 = **(int **)(*(int *)(pTVar9 + 0x30) + 0x20); iVar3 != 0;
                iVar3 = *(int *)(iVar3 + 8)) {
              uVar11 = *(uint *)(iVar3 + 0xc);
              if ((uVar11 & 0x3ffff) == 0) {
                bVar2 = true;
              }
              if ((bVar2) && ((uVar11 & 0x3fc0000) == 0x1340000)) {
                uVar11 = local_a0 >> 0x18 & 3;
                local_88 = uVar11 << 10 | 0x6c;
                local_78 = 0;
                local_74 = 0;
                local_70 = 0;
                local_6c = 0;
                local_68 = 0;
                local_64 = 0;
                local_60 = *(undefined4 *)(iVar3 + 0x3c);
                local_90 = 0x20000000;
                local_5c = 0;
                if (uVar11 == 1) {
LAB_97bb40ac:
                  local_88 = local_88 | 0x4000;
LAB_97bb40b4:
                  local_88 = local_88 | 0x2000;
                }
                else {
                  if (uVar11 == 0) goto LAB_97bb40b4;
                  if (uVar11 == 2) {
LAB_97bb40a4:
                    local_88 = local_88 | 0x8000;
                    goto LAB_97bb40ac;
                  }
                  if (uVar11 == 3) {
                    local_88 = 0x10c6c;
                    goto LAB_97bb40a4;
                  }
                }
                uVar11 = local_a0 >> 0x18 & 3;
                local_8c = (local_a0 >> 0x1d & 3) << 0x12 |
                           uVar11 << 0x1a | (local_a0 >> 0x1a & 7) << 0x17;
                local_88 = local_88 | 0x60000;
                local_80 = uVar11 << 0xc | 0x8d8000;
                local_7c = local_9c & 0xffff;
                local_84 = (uint)uVar1;
                iVar6 = _PPStreamInsertOperationAfterChunk
                                  (*(undefined4 *)(this + iVar7 + 0x30),&local_90,0,0,
                                   *(undefined4 *)(iVar3 + 4));
                _PPStreamChangeBranchTargets
                          (*(undefined4 *)(this + iVar7 + 0x30),*(uint *)(iVar3 + 0xc) & 0x3ffff,
                           *(uint *)(iVar6 + 0xc) & 0x3ffff);
                uVar11 = *(uint *)(iVar3 + 0xc);
              }
              if (uVar5 == (uVar11 & 0x3ffff)) break;
            }
          }
        }
      }
    }
    iVar8 = iVar8 + 1;
    iVar7 = iVar7 + 4;
    pTVar9 = pTVar9 + 4;
    if (1 < iVar8) {
      return;
    }
  } while( true );
}

/* TGenericLinker__OptimizeFunctionIO @ 0x97bb419c (696 bytes) */
int TGenericLinker__OptimizeFunctionIO(this)
  unsigned char * this;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  unsigned char * pPVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  char *pcVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  unsigned char * p_Var18;
  void *this_00;
  unsigned char * p_Var19;
  int iVar20;
  int local_70;
  int local_6c;
  uint local_60;
  int local_5c;
  
  iVar14 = 0;
  do {
    iVar2 = iVar14 * 4;
    iVar20 = 0;
    if ((*(int *)(this + iVar2 + 0x38) != 0) && (0 < *(int *)(*(int *)(this + iVar2 + 0x38) + 4))) {
      do {
        iVar15 = 0;
        uVar3 = FunctionTable__getFunctionName(*(unsigned char **)(this + iVar2 + 0x38),iVar20);
        iVar4 = _memcmp(uVar3,"main(",6);
        if (iVar4 != 0) {
          for (; iVar4 = FunctionTable__getNumParams
                                   (*(unsigned char **)(this + iVar2 + 0x38),iVar20), iVar15 < iVar4
              ; iVar15 = iVar15 + 1) {
            iVar4 = _strlen(uVar3);
            pcVar5 = (char *)_malloc(iVar4 + 9);
            _sprintf(pcVar5,"%s_%i",uVar3,iVar15);
            for (pPVar6 = (unsigned char *)
                          ParseSymbolTable__FindNextParamSymbolByName
                                    (*(unsigned char **)(this + iVar2 + 0x28),(unsigned char *)0x0,
                                     pcVar5); pPVar6 != (unsigned char *)0x0;
                pPVar6 = (unsigned char *)
                         ParseSymbolTable__FindNextParamSymbolByName
                                   (*(unsigned char **)(this + iVar2 + 0x28),pPVar6,pcVar5)) {
              uVar16 = 0;
              uVar7 = ((int (*)())GetVec4sForType)((uint)*(ushort *)(pPVar6 + 0x2c));
              iVar4 = *(int *)pPVar6;
              if (uVar7 != 0) {
                do {
                  local_60 = 0;
                  local_5c = 0;
                  local_70 = 0;
                  local_6c = 0;
                  p_Var19 = (unsigned char *)**(int **)(*(int *)(this + iVar2 + 0x30) + 0x20);
                  iVar8 = FunctionTable__getEmpty(*(unsigned char **)(this + iVar2 + 0x38),iVar20);
                  if (iVar8 == 0) {
                    for (; bVar1 = p_Var19 == (unsigned char *)0x0, !bVar1;
                        p_Var19 = *(unsigned char **)(p_Var19 + 8)) {
                      uVar17 = *(uint *)(p_Var19 + 0xc);
                      uVar9 = FunctionTable__getFirstOp
                                        (*(unsigned char **)(this + iVar2 + 0x38),iVar20);
                      if ((uVar17 & 0x3ffff) == uVar9) goto LAB_97bb43a0;
                    }
                    iVar8 = _strlen(DAT_a7b7baec);
                    iVar11 = _strlen((&_shaderString)[iVar14]);
                    iVar12 = _strlen(uVar3);
                    pcVar13 = (char *)_malloc(iVar8 + iVar11 + iVar12 + 9);
                    uVar10 = FunctionTable__getFirstOp
                                       (*(unsigned char **)(this + iVar2 + 0x38),iVar20);
                    _sprintf(pcVar13,DAT_a7b7baec,uVar3,(&_shaderString)[iVar14],uVar10);
                    this_00 = *(void **)(this + 0x84);
                    
                    __ZN13TInfoSinkBase6appendEPKc(this_00,"INTERNAL ERROR: ");
                    __ZN13TInfoSinkBase6appendEPKc(this_00,pcVar13);
                    __ZN13TInfoSinkBase6appendEPKc(this_00,"\n");
                    _free(pcVar13);
                  }
LAB_97bb44d0:
                  p_Var19 = (unsigned char *)
                            **(undefined4 **)(*(int *)(this + iVar2 + 0x30) + 0x20);
joined_r0x97bb44e4:
                  while (p_Var18 = p_Var19, p_Var18 != (unsigned char *)0x0) {
                    p_Var19 = *(unsigned char **)(p_Var18 + 8);
                    if ((*(uint *)(p_Var18 + 0xc) & 0x3fc0000) != 0) goto code_r0x97bb456c;
                    if (((*(uint *)(p_Var18 + 0x1c) & 0x3800000) == 0x800000) &&
                       ((uint)*(ushort *)(p_Var18 + 0x22) == *(ushort *)(iVar4 + 0x12) + uVar16))
                    goto code_r0x97bb4598;
                    if (((*(uint *)(p_Var18 + 0x14) & 0xe0000) == 0x20000) &&
                       ((uint)*(ushort *)(p_Var18 + 0x1a) == *(ushort *)(iVar4 + 0x12) + uVar16)) {
                      if (local_70 == 0 && local_6c == 0) goto code_r0x97bb45b4;
                      *(int *)(p_Var18 + 0x18) = local_6c;
                      *(int *)(p_Var18 + 0x14) = local_70;
                    }
                  }
                  uVar16 = uVar16 + 1;
                } while (uVar16 < uVar7);
              }
            }
            _free(pcVar5);
          }
          p_Var19 = (unsigned char *)**(undefined4 **)(*(int *)(this + iVar2 + 0x30) + 0x20);
          while (p_Var18 = p_Var19, p_Var18 != (unsigned char *)0x0) {
            p_Var19 = *(unsigned char **)(p_Var18 + 8);
            iVar4 = FunctionTable__getEmpty(*(unsigned char **)(this + iVar2 + 0x38),iVar20);
            if ((((iVar4 != 0) && ((*(uint *)(p_Var18 + 0xc) & 0x3fc0000) == 0x1300000)) &&
                (*(int *)(p_Var18 + 0x40) != 0)) &&
               (iVar4 = _strcmp(p_Var18 + 0x44,uVar3), iVar4 == 0)) {
              FunctionTable__updateForRemovingChunk
                        (*(unsigned char **)(this + iVar2 + 0x38),p_Var18);
              _PPStreamRemoveOperation(*(undefined4 *)(this + iVar2 + 0x30),p_Var18);
            }
          }
        }
        iVar20 = iVar20 + 1;
      } while ((*(int *)(this + iVar2 + 0x38) != 0) &&
              (iVar20 < *(int *)(*(int *)(this + iVar2 + 0x38) + 4)));
    }
    iVar14 = iVar14 + 1;
    if (1 < iVar14) {
      return;
    }
  } while( true );
LAB_97bb43a0:
  if (((bVar1) ||
      (uVar17 = *(uint *)(p_Var19 + 0xc),
      uVar9 = FunctionTable__getLastOp(*(unsigned char **)(this + iVar2 + 0x38),iVar20),
      uVar9 < (uVar17 & 0x3ffff))) || ((*(uint *)(p_Var19 + 0xc) & 0x3ffff) == 0))
  goto LAB_97bb44d0;
  p_Var18 = *(unsigned char **)(p_Var19 + 8);
  if ((*(uint *)(p_Var19 + 0xc) & 0x3fc0000) == 0) {
    uVar9 = *(uint *)(p_Var19 + 0x1c);
    if (((uVar9 & 0x3800000) == 0x800000) &&
       ((uint)*(ushort *)(p_Var19 + 0x22) == *(ushort *)(iVar4 + 0x12) + uVar16)) {
      local_6c = *(int *)(p_Var19 + 0x18);
      local_70 = *(int *)(p_Var19 + 0x14);
      FunctionTable__updateForRemovingChunk(*(unsigned char **)(this + iVar2 + 0x38),p_Var19);
      uVar10 = *(undefined4 *)(this + iVar2 + 0x30);
    }
    else {
      if (((*(uint *)(p_Var19 + 0x14) & 0xe0000) != 0x20000) ||
         ((uint)*(ushort *)(p_Var19 + 0x1a) != *(ushort *)(iVar4 + 0x12) + uVar16))
      goto LAB_97bb4398;
      local_5c = *(int *)(p_Var19 + 0x20);
      FunctionTable__updateForRemovingChunk(*(unsigned char **)(this + iVar2 + 0x38),p_Var19);
      uVar10 = *(undefined4 *)(this + iVar2 + 0x30);
      local_60 = uVar9;
    }
    _PPStreamRemoveOperation(uVar10,p_Var19);
  }
LAB_97bb4398:
  bVar1 = p_Var18 == (unsigned char *)0x0;
  p_Var19 = p_Var18;
  goto LAB_97bb43a0;
code_r0x97bb456c:
  if ((((*(uint *)(p_Var18 + 0xc) & 0x3fc0000) == 0x1b40000) &&
      ((*(uint *)(p_Var18 + 0x1c) & 0x3800000) == 0x800000)) &&
     ((uint)*(ushort *)(p_Var18 + 0x22) == *(ushort *)(iVar4 + 0x12) + uVar16)) {
code_r0x97bb4598:
    if (local_60 == 0 && local_5c == 0) {
code_r0x97bb45b4:
      FunctionTable__updateForRemovingChunk(*(unsigned char **)(this + iVar2 + 0x38),p_Var18);
      _PPStreamRemoveOperation(*(undefined4 *)(this + iVar2 + 0x30),p_Var18);
    }
    else {
      *(int *)(p_Var18 + 0x20) = local_5c;
      *(uint *)(p_Var18 + 0x1c) = local_60;
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
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 *puVar7;
  unsigned char * pTVar8;
  
  pTVar8 = this + 0x40;
  iVar3 = _strlen(_linkUtilString);
  puVar7 = &DAT_a7b7bb38;
  iVar3 = iVar3 + 2;
  do {
    iVar2 = *(int *)pTVar8;
    pTVar8 = pTVar8 + 4;
    if ((iVar2 == 0) ||
       (iVar2 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4)), iVar2 == 0))
    {
      iVar2 = _strlen(*puVar7);
      iVar3 = iVar3 + iVar2;
    }
    else {
      iVar2 = _strlen(puVar7[-3]);
      iVar3 = iVar3 + iVar2;
      for (iVar2 = 0; iVar4 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4)),
          iVar2 < iVar4; iVar2 = iVar2 + 1) {
        iVar4 = _strlen(DAT_a7b7bb34);
        iVar3 = iVar3 + iVar4 + 0x10;
      }
    }
    puVar7 = puVar7 + 1;
  } while ((int)puVar7 < -0x584844c3);
  pcVar5 = (char *)_malloc(iVar3);
  pcVar1 = _linkUtilString;
  *pcVar5 = '\0';
  _sprintf(pcVar5,pcVar1);
  puVar7 = &DAT_a7b7bb38;
  pTVar8 = this + 0x40;
  iVar3 = 0;
  iVar2 = 1;
  do {
    iVar4 = *(int *)pTVar8;
    pTVar8 = pTVar8 + 4;
    if ((iVar4 == 0) ||
       (iVar4 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4)), iVar4 == 0))
    {
      _sprintf(pcVar5,(char *)*puVar7,pcVar5);
    }
    else {
      _sprintf(pcVar5,(char *)puVar7[-3],pcVar5);
      for (iVar4 = 0; iVar6 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4)),
          iVar4 < iVar6; iVar4 = iVar4 + 1) {
        _sprintf(pcVar5,DAT_a7b7bb34,pcVar5,iVar4,
                 *(undefined4 *)(iVar4 * 4 + *(int *)(this + iVar3 + 0x40)));
      }
    }
    iVar2 = iVar2 + -1;
    iVar3 = iVar3 + 4;
    puVar7 = puVar7 + 1;
  } while (-1 < iVar2);
  return pcVar5;
}

/* TGenericLinker__GetBindingTableString @ 0x97bb4894 (384 bytes) */
int TGenericLinker__GetBindingTableString(this)
  unsigned char * this;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  
  uVar1 = BindingTable__GetString(*(unsigned char **)(this + 4),3);
  if (*(int *)(this + 0x74) < 0) {
    iVar2 = _strlen(DAT_a7b7bb44);
    iVar3 = _strlen(uVar1);
    pcVar4 = (char *)_malloc(iVar2 + iVar3 + 0x29);
    *pcVar4 = '\0';
    uVar5 = BindingTable__GetNumActiveAttributeBindings(*(unsigned char **)(this + 4));
    uVar6 = BindingTable__GetSizeActiveAttributes(*(unsigned char **)(this + 4));
    uVar7 = BindingTable__GetSizeActiveUserAttributes(*(unsigned char **)(this + 4));
    uVar8 = BindingTable__GetNumActiveUniformBindings(*(unsigned char **)(this + 4));
    uVar9 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4));
    _sprintf(pcVar4,DAT_a7b7bb44,uVar5,uVar6,uVar7,uVar8,uVar9,uVar1);
  }
  else {
    iVar2 = _strlen(DAT_a7b7bb40);
    iVar3 = _strlen(uVar1);
    pcVar4 = (char *)_malloc(iVar2 + iVar3 + 0x29);
    *pcVar4 = '\0';
    uVar5 = BindingTable__GetNumActiveAttributeBindings(*(unsigned char **)(this + 4));
    uVar6 = BindingTable__GetSizeActiveAttributes(*(unsigned char **)(this + 4));
    uVar7 = BindingTable__GetSizeActiveUserAttributes(*(unsigned char **)(this + 4));
    uVar8 = BindingTable__GetNumActiveUniformBindings(*(unsigned char **)(this + 4));
    uVar9 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4));
    _sprintf(pcVar4,DAT_a7b7bb40,*(undefined4 *)(this + 0x74),uVar5,uVar6,uVar7,uVar8,uVar9);
  }
  _free(uVar1);
  return pcVar4;
}

/* TGenericLinker__GetFullTableString @ 0x97bb4a14 (152 bytes) */
int TGenericLinker__GetFullTableString(this)
  unsigned char * this;
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  uVar1 = ((int (*)())TGenericLinker__GetRemapTableString)(this);
  uVar2 = ((int (*)())TGenericLinker__GetBindingTableString)(this);
  iVar3 = _strlen(uVar1);
  iVar4 = _strlen(uVar2);
  pcVar5 = (char *)_malloc(iVar3 + iVar4 + 1);
  *pcVar5 = '\0';
  _sprintf(pcVar5,"%s%s",uVar2,uVar1);
  _free(uVar2);
  _free(uVar1);
  return pcVar5;
}

/* TGenericLinker__ReportStats @ 0x97bb4aac (4 bytes) */
int TGenericLinker__ReportStats()
{
  return;
}

/* TGenericLinker__InsertClientAttribBinding @ 0x97bb4ab0 (92 bytes) */
int TGenericLinker__InsertClientAttribBinding(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = BindingTable__FindAttribBinding(*(unsigned char **)(param_1 + 4),param_2);
  if (iVar1 == 0) {
    uVar2 = BindingTable__InsertClientAttribBinding(*(unsigned char **)(param_1 + 4),param_2);
    return uVar2;
  }
  return 0;
}

/* TGenericLinker__AddAttribBinding @ 0x97bb4b0c (276 bytes) */
int TGenericLinker__AddAttribBinding(param_1, param_2, param_3, param_4)
  char *param_1;
  char *param_2;
  undefined4 param_3;
  undefined4 param_4;
{
  unsigned char * this;
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  void *pvVar5;
  
  this = operator_new(0x38);
  __ZN7BindingC1Ev(this);
  pcVar4 = DAT_a7b7bb84;
  if (this == (unsigned char *)0x0) {
    pvVar5 = *(void **)(param_1 + 0x84);
                    
    __ZN13TInfoSinkBase6appendEPKc(pvVar5,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(pvVar5,pcVar4);
    __ZN13TInfoSinkBase6appendEPKc(pvVar5,"\n");
  }
  else {
    Binding__SetName(this,param_2);
    iVar1 = BindingTable__FindAttribBinding(*(unsigned char **)(param_1 + 4),this);
    if (iVar1 == 0) {
      Binding__SetClientRequest(this,0);
      Binding__SetOpenGLType(this,(*(unsigned short *)((unsigned char *)&(param_3) + 2)));
      Binding__SetDecSize(this,1);
      Binding__SetActualSize(this,1);
      Binding__SetBuiltIn(this,param_4);
      iVar1 = BindingTable__InsertAttribBinding(*(unsigned char **)(param_1 + 4),this);
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar2 = BindingTable__GetAttribBindingNameByLocation(*(unsigned char **)(param_1 + 4),0);
      iVar1 = _strlen(_linkErrorString);
      iVar3 = _strlen(uVar2);
      pcVar4 = (char *)_malloc(iVar1 + iVar3 + 1);
      _sprintf(pcVar4,_linkErrorString,uVar2);
      pvVar5 = *(void **)(param_1 + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(pvVar5,"ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(pvVar5,pcVar4);
      __ZN13TInfoSinkBase6appendEPKc(pvVar5,"\n");
      _free(pcVar4);
      return 0;
    }
    __ZN7BindingD1Ev(this);
    __ZdlPv(this);
  }
  return 0;
}

/* TGenericLinker__CollectClientAttributeBindings @ 0x97bb4d6c (216 bytes) */
int TGenericLinker__CollectClientAttributeBindings(this)
  unsigned char * this;
{
  unsigned char * pBVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvVar7;
  
  if (*(int *)(this + 0x28) == 0) {
    for (pBVar1 = (unsigned char *)
                  BindingTable__NextAttribRequestBinding
                            (*(unsigned char **)(this + 4),(unsigned char *)0x0); pBVar1 != (unsigned char *)0x0;
        pBVar1 = (unsigned char *)
                 BindingTable__NextAttribRequestBinding(*(unsigned char **)(this + 4),pBVar1)) {
      uVar6 = *(undefined4 *)(pBVar1 + 8);
      iVar2 = _strlen(UNK_a7b7bac8);
      iVar5 = _strlen(uVar6);
      pcVar4 = (char *)_malloc(iVar2 + iVar5 + 1);
      _sprintf(pcVar4,UNK_a7b7bac8,uVar6);
      pvVar7 = *(void **)(this + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(pvVar7,"WARNING: ");
      __ZN13TInfoSinkBase6appendEPKc(pvVar7,pcVar4);
      __ZN13TInfoSinkBase6appendEPKc(pvVar7,"\n");
      _free(pcVar4);
    }
  }
  else {
    for (pBVar1 = (unsigned char *)
                  BindingTable__NextAttribRequestBinding
                            (*(unsigned char **)(this + 4),(unsigned char *)0x0); pBVar1 != (unsigned char *)0x0;
        pBVar1 = (unsigned char *)
                 BindingTable__NextAttribRequestBinding(*(unsigned char **)(this + 4),pBVar1)) {
      iVar2 = ParseSymbolTable__FindGlobalSymbolByName
                        (*(unsigned char **)(this + 0x28),*(char **)(pBVar1 + 8));
      if (iVar2 == 0) {
        uVar6 = *(undefined4 *)(pBVar1 + 8);
        iVar2 = _strlen(UNK_a7b7bac4);
        iVar5 = _strlen(uVar6);
        pcVar4 = (char *)_malloc(iVar2 + iVar5 + 1);
        _sprintf(pcVar4,UNK_a7b7bac4,uVar6);
        pvVar7 = *(void **)(this + 0x84);
                    
        __ZN13TInfoSinkBase6appendEPKc(pvVar7,"WARNING: ");
        __ZN13TInfoSinkBase6appendEPKc(pvVar7,pcVar4);
        __ZN13TInfoSinkBase6appendEPKc(pvVar7,"\n");
        _free(pcVar4);
      }
      else {
        Binding__SetOpenGLType(pBVar1,*(ushort *)(iVar2 + 0x2c));
        Binding__SetActualSize(pBVar1,1);
        Binding__SetDecSize(pBVar1,1);
        iVar5 = *(int *)(iVar2 + 0x34);
        if (iVar5 == 1) {
          uVar6 = *(undefined4 *)(pBVar1 + 8);
          iVar5 = _strlen(DAT_a7b7bb68);
          iVar3 = _strlen(uVar6);
          pcVar4 = (char *)_malloc(iVar5 + iVar3 + 1);
          _sprintf(pcVar4,DAT_a7b7bb68,uVar6);
          pvVar7 = *(void **)(this + 0x84);
                    
          __ZN13TInfoSinkBase6appendEPKc(pvVar7,"INTERNAL ERROR: ");
          __ZN13TInfoSinkBase6appendEPKc(pvVar7,pcVar4);
          __ZN13TInfoSinkBase6appendEPKc(pvVar7,"\n");
          _free(pcVar4);
          iVar5 = *(int *)(iVar2 + 0x34);
        }
        Binding__SetBuiltIn(pBVar1,iVar5);
        InsertClientAttribBinding((unsigned char *)this,pBVar1);
      }
    }
  }
  return 1;
}

/* TGenericLinker__CollectAttributeBindings @ 0x97bb50dc (996 bytes) */
int TGenericLinker__CollectAttributeBindings(this)
  unsigned char * this;
{
  unsigned char * pPVar1;
  uint uVar2;
  
  if (*(unsigned char **)(this + 0x28) != (unsigned char *)0x0) {
    for (pPVar1 = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        pPVar1 != (unsigned char *)0x0;
        pPVar1 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar1)) {
      if (((**(char **)pPVar1 == '\x02') && (*(short *)(pPVar1 + 0x2c) == -0x74a4)) &&
         (*(int *)(pPVar1 + 0x34) == 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,*(undefined4 *)(pPVar1 + 0x14),0x8b5c,0);
      }
    }
    for (pPVar1 = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        pPVar1 != (unsigned char *)0x0;
        pPVar1 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar1)) {
      if (((**(char **)pPVar1 == '\x02') && (*(short *)(pPVar1 + 0x2c) == -0x74a5)) &&
         (*(int *)(pPVar1 + 0x34) == 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,*(undefined4 *)(pPVar1 + 0x14),0x8b5b,0);
      }
    }
    for (pPVar1 = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        pPVar1 != (unsigned char *)0x0;
        pPVar1 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar1)) {
      if (((**(char **)pPVar1 == '\x02') && (*(short *)(pPVar1 + 0x2c) == -0x74a6)) &&
         (*(int *)(pPVar1 + 0x34) == 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,*(undefined4 *)(pPVar1 + 0x14),0x8b5a,0);
      }
    }
    for (pPVar1 = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        pPVar1 != (unsigned char *)0x0;
        pPVar1 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar1)) {
      if ((((**(char **)pPVar1 == '\x02') &&
           (uVar2 = (uint)*(ushort *)(pPVar1 + 0x2c), uVar2 != 0x8b5c)) && (uVar2 != 0x8b5b)) &&
         ((uVar2 != 0x8b5a && (*(int *)(pPVar1 + 0x34) == 0)))) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,*(undefined4 *)(pPVar1 + 0x14),uVar2,0);
      }
    }
    for (pPVar1 = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        pPVar1 != (unsigned char *)0x0;
        pPVar1 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar1)) {
      if (((**(char **)pPVar1 == '\x02') && (*(short *)(pPVar1 + 0x2c) == -0x74a4)) &&
         (*(int *)(pPVar1 + 0x34) != 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,*(undefined4 *)(pPVar1 + 0x14),0x8b5c,1);
      }
    }
    for (pPVar1 = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        pPVar1 != (unsigned char *)0x0;
        pPVar1 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar1)) {
      if (((**(char **)pPVar1 == '\x02') && (*(short *)(pPVar1 + 0x2c) == -0x74a5)) &&
         (*(int *)(pPVar1 + 0x34) != 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,*(undefined4 *)(pPVar1 + 0x14),0x8b5b,1);
      }
    }
    for (pPVar1 = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        pPVar1 != (unsigned char *)0x0;
        pPVar1 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar1)) {
      if (((**(char **)pPVar1 == '\x02') && (*(short *)(pPVar1 + 0x2c) == -0x74a6)) &&
         (*(int *)(pPVar1 + 0x34) != 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,*(undefined4 *)(pPVar1 + 0x14),0x8b5a,1);
      }
    }
    for (pPVar1 = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        pPVar1 != (unsigned char *)0x0;
        pPVar1 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar1)) {
      if (((**(char **)pPVar1 == '\x02') &&
          (uVar2 = (uint)*(ushort *)(pPVar1 + 0x2c), uVar2 != 0x8b5c)) &&
         ((uVar2 != 0x8b5b && ((uVar2 != 0x8b5a && (*(int *)(pPVar1 + 0x34) != 0)))))) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,*(undefined4 *)(pPVar1 + 0x14),uVar2,1);
      }
    }
  }
  return 1;
}

/* TGenericLinker__RemapVertexAttributes @ 0x97bb54c0 (200 bytes) */
int TGenericLinker__RemapVertexAttributes(this)
  unsigned char * this;
{
  short sVar1;
  unsigned char * this_00;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  char *pcVar7;
  undefined4 uVar8;
  uint uVar9;
  void *this_01;
  
  uVar8 = 1;
  this_00 = (unsigned char *)BindingTable__NextAttribBinding(*(unsigned char **)(this + 4),(unsigned char *)0x0);
joined_r0x97bb54f0:
  if (this_00 == (unsigned char *)0x0) {
    return uVar8;
  }
  iVar2 = Binding__IsBuiltIn(this_00);
  if (((iVar2 == 0) && (*(unsigned char **)(this + 0x28) != (unsigned char *)0x0)) &&
     (puVar3 = (undefined4 *)
               ParseSymbolTable__FindGlobalSymbolByName
                         (*(unsigned char **)(this + 0x28),*(char **)(this_00 + 8)),
     puVar3 != (undefined4 *)0x0)) {
    pcVar7 = (char *)*puVar3;
    if (*pcVar7 != '\x02') {
      uVar8 = puVar3[5];
      iVar2 = _strlen(DAT_a7b7bb6c);
      iVar4 = _strlen(uVar8);
      pcVar7 = (char *)_malloc(iVar2 + iVar4 + 1);
      _sprintf(pcVar7,DAT_a7b7bb6c,uVar8);
      this_01 = *(void **)(this + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(this_01,"INTERNAL ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(this_01,pcVar7);
      __ZN13TInfoSinkBase6appendEPKc(this_01,"\n");
      _free(pcVar7);
      uVar8 = 0;
      pcVar7 = (char *)*puVar3;
    }
    if ((*pcVar7 == '\x02') && ((*(uint *)(pcVar7 + 0xc) & 0xf0000) == 0x90000)) {
      sVar1 = *(short *)(pcVar7 + 0x12);
      iVar4 = Binding__GetLocation(this_00);
      for (iVar2 = **(int **)(*(int *)(this + 0x30) + 0x18); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)
          ) {
        uVar9 = 0;
        if (*(short *)(iVar2 + 0x12) == sVar1) goto code_r0x97bb567c;
      }
    }
  }
  goto LAB_97bb56a8;
code_r0x97bb567c:
  while( true ) {
    uVar5 = Binding__GetOpenGLType(this_00);
    uVar6 = ((int (*)())GetVec4sForType)(uVar5);
    if ((uVar6 <= uVar9) || (iVar2 == 0)) break;
    uVar6 = iVar4 + uVar9;
    uVar9 = uVar9 + 1;
    *(uint *)(iVar2 + 0xc) = uVar6 & 0x1f | *(uint *)(iVar2 + 0xc) & 0xffffffe0;
    iVar2 = *(int *)(iVar2 + 8);
  }
LAB_97bb56a8:
  this_00 = (unsigned char *)BindingTable__NextAttribBinding(*(unsigned char **)(this + 4),this_00);
  goto joined_r0x97bb54f0;
}

/* TGenericLinker__AllocateTextureUnitsForVaryings @ 0x97bb56d4 (468 bytes) */
int TGenericLinker__AllocateTextureUnitsForVaryings(this)
  unsigned char * this;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  unsigned char * this_00;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  unsigned char * pPVar7;
  char *pcVar8;
  uint uVar9;
  int *piVar10;
  unsigned char * pFVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  undefined4 uVar15;
  char *pcVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  int *piVar20;
  uint uVar21;
  undefined4 uVar22;
  ushort uVar23;
  int iVar24;
  int iVar25;
  undefined4 uVar26;
  int iVar27;
  void *pvVar28;
  uint uVar29;
  uint local_e0 [14];
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
  uint *local_58;
  
  *(undefined4 *)(this + 0x74) = 0xffffffff;
  *(undefined4 *)(this + 0x78) = 0;
  uVar22 = 1;
  iVar27 = 0;
  iVar25 = 0;
  iVar24 = 0;
  if (*(unsigned char **)(this + 0x28) != (unsigned char *)0x0) {
    for (pPVar7 = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        pPVar7 != (unsigned char *)0x0;
        pPVar7 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar7)) {
      if ((**(char **)pPVar7 == '\x04') &&
         (uVar18 = *(uint *)(*(char **)pPVar7 + 0xc), (uVar18 & 0xf0000) == 0x60000)) {
        uVar18 = uVar18 & 0x1f;
        *(uint *)(this + 0x78) = *(uint *)(this + 0x78) | 1 << uVar18;
        if (*(int *)(this + 0x74) < (int)uVar18) {
          *(uint *)(this + 0x74) = uVar18;
        }
        iVar27 = iVar27 + 1;
      }
    }
  }
  this_00 = *(unsigned char **)(this + 0x2c);
  if (this_00 != (unsigned char *)0x0) {
    iVar25 = *(int *)(this_00 + 0x1c);
    iVar24 = *(int *)(this_00 + 0x20);
    for (pPVar7 = (unsigned char *)ParseSymbolTable__NextSymbol(this_00,(unsigned char *)0x0);
        pPVar7 != (unsigned char *)0x0;
        pPVar7 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x2c),pPVar7)) {
      if ((**(char **)pPVar7 == '\x02') &&
         (uVar18 = *(uint *)(*(char **)pPVar7 + 0xc), (uVar18 & 0xf0000) == 0x70000)) {
        uVar18 = uVar18 & 0x1f;
        if (*(int *)(this + 0x74) < (int)uVar18) {
          *(uint *)(this + 0x74) = uVar18;
        }
        if ((*(uint *)(this + 0x78) & 1 << uVar18) == 0) {
          iVar27 = iVar27 + 1;
        }
        *(uint *)(this + 0x78) = *(uint *)(this + 0x78) | 1 << uVar18;
      }
    }
  }
  if (iVar25 != 0) {
    if ((*(int *)(this + 0x28) == 0) || (*(int *)(this + 0x2c) == 0)) {
      if (*(unsigned char **)(this + 0x2c) != (unsigned char *)0x0) {
        for (pPVar7 = (unsigned char *)
                      ParseSymbolTable__NextSymbol
                                (*(unsigned char **)(this + 0x2c),(unsigned char *)0x0);
            pPVar7 != (unsigned char *)0x0;
            pPVar7 = (unsigned char *)
                     ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar7)) {
          if ((**(char **)pPVar7 == '\0') && (*(int *)(pPVar7 + 0x60) != 0)) {
            uVar22 = *(undefined4 *)(pPVar7 + 0x14);
            iVar27 = _strlen(UNK_a7b7badc);
            iVar24 = _strlen(uVar22);
            pcVar8 = (char *)_malloc(iVar27 + iVar24 + 1);
            _sprintf(pcVar8,UNK_a7b7badc,uVar22);
            pvVar28 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar28,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar28,pcVar8);
            __ZN13TInfoSinkBase6appendEPKc(pvVar28,"\n");
            uVar22 = 0;
            _free(pcVar8);
          }
        }
      }
    }
    else {
      iVar25 = 1;
      iVar24 = iVar27 * 4 + iVar24;
      if (iVar24 < 0x21) {
        iVar27 = _malloc(0x80);
        _memset(iVar27,0,0x80);
        for (pPVar7 = (unsigned char *)
                      ParseSymbolTable__NextSymbol
                                (*(unsigned char **)(this + 0x2c),(unsigned char *)0x0);
            pPVar7 != (unsigned char *)0x0;
            pPVar7 = (unsigned char *)
                     ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x2c),pPVar7)) {
          if ((**(char **)pPVar7 == '\x02') &&
             (uVar18 = *(uint *)(*(char **)pPVar7 + 0xc), (uVar18 & 0xf0000) == 0x70000)) {
            iVar24 = (uVar18 & 0x1f) * 0x10;
            iVar4 = -iVar25;
            iVar19 = iVar24 + iVar27;
            *(int *)(iVar27 + iVar24) = iVar4;
            iVar25 = iVar25 + 1;
            *(int *)(iVar19 + 0xc) = iVar4;
            *(int *)(iVar19 + 4) = iVar4;
            *(int *)(iVar19 + 8) = iVar4;
          }
        }
        for (pPVar7 = (unsigned char *)
                      ParseSymbolTable__NextSymbol
                                (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
            pPVar7 != (unsigned char *)0x0;
            pPVar7 = (unsigned char *)
                     ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar7)) {
          if ((**(char **)pPVar7 == '\x04') &&
             (uVar18 = *(uint *)(*(char **)pPVar7 + 0xc), (uVar18 & 0xf0000) == 0x60000)) {
            iVar24 = (uVar18 & 0x1f) * 0x10;
            iVar4 = -iVar25;
            iVar19 = iVar24 + iVar27;
            *(int *)(iVar27 + iVar24) = iVar4;
            iVar25 = iVar25 + 1;
            *(int *)(iVar19 + 0xc) = iVar4;
            *(int *)(iVar19 + 4) = iVar4;
            *(int *)(iVar19 + 8) = iVar4;
          }
        }
        uVar18 = 4;
        do {
          for (pPVar7 = (unsigned char *)
                        ParseSymbolTable__NextSymbol
                                  (*(unsigned char **)(this + 0x2c),(unsigned char *)0x0);
              pPVar7 != (unsigned char *)0x0;
              pPVar7 = (unsigned char *)
                       ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x2c),pPVar7)) {
            if (((**(char **)pPVar7 == '\0') && (*(int *)(pPVar7 + 0x60) != 0)) &&
               (uVar9 = ((int (*)())GetScalerWidthForType)((uint)*(ushort *)(pPVar7 + 0x2c)), uVar18 == uVar9)) {
              piVar10 = (int *)ParseSymbolTable__FindGlobalSymbolByName
                                         (*(unsigned char **)(this + 0x28),
                                          *(char **)(pPVar7 + 0x14));
              if (((piVar10 == (int *)0x0) ||
                  (uVar9 = (uint)*(ushort *)(pPVar7 + 0x2c), uVar9 != *(ushort *)(piVar10 + 0xb)))
                 || ((*(char *)*piVar10 != '\0' || (local_60 = 0, piVar10[0x17] == 0)))) {
                uVar22 = 0;
                if (piVar10 == (int *)0x0) {
code_r0x97bb689c:
                  uVar13 = *(undefined4 *)(pPVar7 + 0x14);
                  iVar24 = _strlen(UNK_a7b7bad4);
                  iVar4 = _strlen(uVar13);
                  pcVar8 = (char *)_malloc(iVar24 + iVar4 + 1);
                  _sprintf(pcVar8,UNK_a7b7bad4,uVar13);
                  pvVar28 = *(void **)(this + 0x84);
                    
override_jmp_97bb67f0_case_0:
                  pcVar16 = "ERROR: ";
                }
                else {
                  if (*(short *)(pPVar7 + 0x2c) != *(short *)(piVar10 + 0xb)) {
                    uVar26 = *(undefined4 *)(pPVar7 + 0x14);
                    iVar24 = _strlen(UNK_a7b7bad0);
                    iVar4 = _strlen(uVar26);
                    uVar13 = ((int (*)())GetShaderStringForType)((uint)*(ushort *)(piVar10 + 0xb));
                    iVar19 = _strlen(uVar13);
                    uVar13 = ((int (*)())GetShaderStringForType)((uint)*(ushort *)(pPVar7 + 0x2c));
                    iVar14 = _strlen(uVar13);
                    pcVar8 = (char *)_malloc(iVar24 + iVar4 + iVar19 + iVar14 + 1);
                    uVar13 = ((int (*)())GetShaderStringForType)((uint)*(ushort *)(pPVar7 + 0x2c));
                    uVar15 = ((int (*)())GetShaderStringForType)((uint)*(ushort *)(piVar10 + 0xb));
                    _sprintf(pcVar8,UNK_a7b7bad0,uVar26,uVar15,uVar13);
                    pvVar28 = *(void **)(this + 0x84);
                    
                    goto override_jmp_97bb67f0_case_0;
                  }
                  if ((*(char *)*piVar10 == '\0') && (piVar10[0x17] == 0)) goto code_r0x97bb689c;
                  uVar13 = *(undefined4 *)(pPVar7 + 0x14);
                  iVar24 = _strlen(UNK_a7b7bb70);
                  iVar4 = _strlen(uVar13);
                  pcVar8 = (char *)_malloc(iVar24 + iVar4 + 1);
                  _sprintf(pcVar8,UNK_a7b7bb70,uVar13);
                  pvVar28 = *(void **)(this + 0x84);
                  pcVar16 = "INTERNAL ERROR: ";
                    
                }
                __ZN13TInfoSinkBase6appendEPKc(pvVar28,pcVar16);
                __ZN13TInfoSinkBase6appendEPKc(pvVar28,pcVar8);
                __ZN13TInfoSinkBase6appendEPKc(pvVar28,"\n");
                _free(pcVar8);
              }
              else {
                while (uVar9 = ((int (*)())GetVec4sForType)(uVar9), local_60 < uVar9) {
                  local_e0[7] = 0xffffffff;
                  local_e0[3] = 0xffffffff;
                  local_e0[4] = 0xffffffff;
                  iVar24 = 0;
                  local_e0[5] = 0xffffffff;
                  local_e0[6] = 0xffffffff;
                  local_e0[0] = 0xffffffff;
                  local_e0[1] = 0xffffffff;
                  local_e0[2] = 0xffffffff;
                  do {
                    bVar1 = true;
                    if (uVar18 == 2) {
                      iVar4 = iVar24 << 2;
code_r0x97bb5b68:
                      if (*(int *)(iVar4 + iVar27 + 4) == 0) {
code_r0x97bb5b80:
                        if (*(int *)(iVar4 + iVar27) == 0) goto code_r0x97bb5b90;
                      }
code_r0x97bb5b8c:
                      bVar1 = false;
                    }
                    else {
                      if (2 < uVar18) {
                        if (uVar18 == 3) {
                          iVar4 = iVar24 << 2;
code_r0x97bb5b50:
                          if (*(int *)(iVar4 + iVar27 + 8) == 0) goto code_r0x97bb5b68;
                        }
                        else {
                          if (uVar18 != 4) goto code_r0x97bb5b90;
                          iVar4 = iVar24 * 4;
                          if (*(int *)(iVar4 + iVar27 + 0xc) == 0) goto code_r0x97bb5b50;
                        }
                        goto code_r0x97bb5b8c;
                      }
                      if (uVar18 == 1) {
                        iVar4 = iVar24 << 2;
                        goto code_r0x97bb5b80;
                      }
                    }
code_r0x97bb5b90:
                    bVar1 = !bVar1;
                    if ((!bVar1) && (uVar9 = 0, uVar18 != 0)) {
                      piVar20 = (int *)(iVar24 * 4 + iVar27);
                      puVar5 = local_e0;
                      uVar29 = uVar18;
                      do {
                        uVar2 = *(uint *)(this + 0x78);
                        puVar5[4] = uVar9;
                        uVar9 = uVar9 + 1;
                        *(uint *)(this + 0x78) = uVar2 | 1 << (iVar24 >> 2 & 0x3fU);
                        *puVar5 = iVar24 >> 2;
                        puVar5 = puVar5 + 1;
                        *piVar20 = iVar25;
                        piVar20 = piVar20 + 1;
                        uVar29 = uVar29 - 1;
                      } while (uVar29 != 0);
                    }
                    iVar24 = iVar24 + 4;
                  } while ((iVar24 < 0x20) && (bVar1));
                  iVar24 = 0;
                  if (bVar1) {
                    do {
                      uVar9 = 1;
                      if (-uVar18 == -4) {
code_r0x97bb5ccc:
                        if (!bVar1) goto code_r0x97bb5cd0;
                      }
                      else {
                        if (bVar1) {
                          do {
                            bVar1 = true;
                            if (uVar18 == 2) {
code_r0x97bb5c80:
                              if (*(int *)((iVar24 + uVar9) * 4 + iVar27 + 4) == 0) {
code_r0x97bb5c9c:
                                if (*(int *)(iVar27 + (iVar24 + uVar9) * 4) == 0)
                                goto code_r0x97bb5cb0;
                              }
code_r0x97bb5cac:
                              bVar1 = false;
                            }
                            else if (uVar18 < 3) {
                              if (uVar18 == 1) goto code_r0x97bb5c9c;
                            }
                            else if (uVar18 == 3) {
                              if (*(int *)((iVar24 + uVar9) * 4 + iVar27 + 8) == 0)
                              goto code_r0x97bb5c80;
                              goto code_r0x97bb5cac;
                            }
code_r0x97bb5cb0:
                            uVar9 = uVar9 + 1;
                            if (-uVar18 + 4 < uVar9) {
                              bVar1 = !bVar1;
                              goto code_r0x97bb5ccc;
                            }
                          } while (!bVar1);
                          bVar1 = false;
                        }
code_r0x97bb5cd0:
                        iVar4 = 0;
                        if (uVar18 != 0) {
                          piVar20 = (int *)((iVar24 + (uVar9 - 1)) * 4 + iVar27);
                          puVar5 = local_e0;
                          uVar29 = uVar18;
                          do {
                            uVar2 = *(uint *)(this + 0x78);
                            puVar5[4] = iVar4 + (uVar9 - 1);
                            iVar4 = iVar4 + 1;
                            *(uint *)(this + 0x78) = uVar2 | 1 << (iVar24 >> 2 & 0x3fU);
                            *puVar5 = iVar24 >> 2;
                            puVar5 = puVar5 + 1;
                            *piVar20 = iVar25;
                            piVar20 = piVar20 + 1;
                            uVar29 = uVar29 - 1;
                          } while (uVar29 != 0);
                        }
                      }
                      iVar24 = iVar24 + 4;
                    } while ((iVar24 < 0x20) && (bVar1));
                  }
                  uVar9 = 0;
                  if ((uVar18 != 0) && (bVar1)) {
                    do {
                      uVar29 = 0;
                      uVar2 = 0;
                      if (bVar1) {
                        do {
                          uVar17 = uVar29;
                          if (*(int *)(uVar2 * 4 + iVar27) == 0) {
                            uVar3 = ((int)uVar2 >> 2) + (uint)((int)uVar2 < 0 && (uVar2 & 3) != 0);
                            local_e0[uVar29] = uVar3;
                            uVar17 = uVar29 + 1;
                            *(uint *)(this + 0x78) = *(uint *)(this + 0x78) | 1 << (uVar3 & 0x3f);
                            local_e0[uVar29 + 4] = uVar2 + uVar3 * -4;
                            *(int *)(uVar2 * 4 + iVar27) = iVar25;
                          }
                          if (uVar17 == uVar18) {
                            bVar1 = false;
                          }
                          uVar2 = uVar2 + 1;
                        } while (((int)uVar2 < 0x20) && (uVar29 = uVar17, bVar1));
                      }
                      uVar9 = uVar9 + 1;
                    } while ((uVar9 < uVar18) && (bVar1));
                  }
                  pcVar8 = UNK_a7b7bacc;
                  iVar25 = iVar25 + 1;
                  if (bVar1) {
                    uVar22 = 0;
                    pvVar28 = *(void **)(this + 0x84);
                    
                    __ZN13TInfoSinkBase6appendEPKc(pvVar28,"ERROR: ");
                    __ZN13TInfoSinkBase6appendEPKc(pvVar28,pcVar8);
                    __ZN13TInfoSinkBase6appendEPKc(pvVar28,"\n");
                  }
                  else {
                    pFVar11 = *(unsigned char **)(this + 0x38);
                    local_5c = 0;
                    uVar9 = 0;
                    if ((pFVar11 != (unsigned char *)0x0) && (*(int *)(pFVar11 + 4) != 0)) {
                      while( true ) {
                        uVar13 = FunctionTable__getFunctionName(pFVar11,uVar9);
                        iVar24 = _memcmp(uVar13,"main(",6);
                        if (iVar24 == 0) break;
                        pFVar11 = *(unsigned char **)(this + 0x38);
                        uVar9 = uVar9 + 1;
                        if ((pFVar11 == (unsigned char *)0x0) || (*(uint *)(pFVar11 + 4) <= uVar9))
                        break;
                      }
                    }
                    for (iVar24 = **(int **)(*(int *)(this + 0x30) + 0x20); iVar24 != 0;
                        iVar24 = *(int *)(iVar24 + 8)) {
                      uVar29 = FunctionTable__getFirstOp(*(unsigned char **)(this + 0x38),uVar9);
                      if (uVar29 == (*(uint *)(iVar24 + 0xc) & 0x3ffff)) {
                        local_5c = 1;
                      }
                      if (((local_5c != 0) && ((*(uint *)(iVar24 + 0xc) & 0x3fc0000) == 0x1340000))
                         && (uVar29 = 0, uVar18 != 0)) {
                        iVar4 = 0;
                        local_58 = local_e0 + 8;
code_r0x97bb5ec0:
                        iVar14 = *(int *)(this + 0x30);
                        uVar2 = 0;
                        uVar17 = *(uint *)((int)local_e0 + iVar4);
                        for (iVar19 = **(int **)(iVar14 + 0x1c); iVar19 != 0;
                            iVar19 = *(int *)(iVar19 + 8)) {
                          if (((*(uint *)(iVar19 + 0xc) & 0xf0000) == 0x60000) &&
                             ((*(uint *)(iVar19 + 0xc) & 0x1f) == uVar17)) {
                            uVar23 = *(ushort *)(iVar19 + 0x12);
                            uVar3 = 3;
                            piVar20 = (int *)(uVar17 * 0x10 + iVar27 + 0xc);
                            goto code_r0x97bb5f28;
                          }
                        }
                        local_7c = 0;
                        local_80 = uVar17 & 0x1f | 0x4060000;
                        piVar20 = (int *)(uVar17 * 0x10 + iVar27 + 0xc);
                        uVar3 = 3;
                        do {
                          iVar19 = *piVar20;
                          piVar20 = piVar20 + -1;
                          if (iVar19 != 0) {
                            local_80 = (uVar3 & 3) << 0x18 | uVar17 & 0x1f | 0x4060000;
                            break;
                          }
                          uVar3 = uVar3 - 1;
                        } while (-1 < (int)uVar3);
                        uVar13 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(iVar14 + 0x1c));
                        uVar23 = (short)uVar13 + 1;
                        local_7c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_7c) + 0)),uVar23);
                        _PPStreamAddOutputBinding(*(undefined4 *)(this + 0x30),&local_80);
code_r0x97bb5fe4:
                        iVar14 = *(int *)(this + 0x30);
                        goto code_r0x97bb5fe8;
                      }
code_r0x97bb61d0:
                      uVar29 = FunctionTable__getLastOp(*(unsigned char **)(this + 0x38),uVar9);
                      if (uVar29 == (*(uint *)(iVar24 + 0xc) & 0x3ffff)) break;
                    }
                    pFVar11 = *(unsigned char **)(this + 0x3c);
                    uVar9 = 0;
                    if ((pFVar11 != (unsigned char *)0x0) && (*(int *)(pFVar11 + 4) != 0)) {
                      while( true ) {
                        uVar13 = FunctionTable__getFunctionName(pFVar11,uVar9);
                        iVar24 = _memcmp(uVar13,"main(",6);
                        if (iVar24 == 0) break;
                        pFVar11 = *(unsigned char **)(this + 0x3c);
                        uVar9 = uVar9 + 1;
                        if ((pFVar11 == (unsigned char *)0x0) || (*(uint *)(pFVar11 + 4) <= uVar9))
                        break;
                      }
                    }
                    for (iVar24 = **(int **)(*(int *)(this + 0x34) + 0x20); iVar24 != 0;
                        iVar24 = *(int *)(iVar24 + 8)) {
                      uVar29 = FunctionTable__getFirstOp(*(unsigned char **)(this + 0x3c),uVar9);
                      if (uVar29 == (*(uint *)(iVar24 + 0xc) & 0x3ffff)) {
                        uVar29 = 0;
                        if (uVar18 != 0) {
                          local_58 = local_e0 + 8;
                          iVar4 = 0;
                          goto code_r0x97bb62a8;
                        }
                        break;
                      }
                    }
                  }
code_r0x97bb6720:
                  uVar9 = (uint)*(ushort *)(pPVar7 + 0x2c);
                  local_60 = local_60 + 1;
                }
              }
            }
          }
          uVar18 = uVar18 - 1;
        } while (uVar18 != 0);
        iVar24 = 0;
        *(undefined4 *)(this + 0x74) = 0xffffffff;
        iVar25 = 8;
        do {
          iVar4 = iVar24 * 4 + iVar27;
          if ((((*(int *)(iVar27 + iVar24 * 4) != 0) || (*(int *)(iVar4 + 4) != 0)) ||
              (*(int *)(iVar4 + 8) != 0)) || (*(int *)(iVar4 + 0xc) != 0)) {
            *(int *)(this + 0x74) = iVar24 >> 2;
          }
          iVar24 = iVar24 + 4;
          iVar25 = iVar25 + -1;
        } while (iVar25 != 0);
        if (iVar27 != 0) {
          _free(iVar27);
        }
      }
      else {
        iVar27 = _strlen(DAT_a7b7bb00);
        pcVar8 = (char *)_malloc(iVar27 + 0x11);
        _sprintf(pcVar8,DAT_a7b7bb00,0x20,iVar24);
        pvVar28 = *(void **)(this + 0x84);
                    
        __ZN13TInfoSinkBase6appendEPKc(pvVar28,"ERROR: ");
        __ZN13TInfoSinkBase6appendEPKc(pvVar28,pcVar8);
        __ZN13TInfoSinkBase6appendEPKc(pvVar28,"\n");
        _free(pcVar8);
        uVar22 = 0;
      }
    }
  }
  return uVar22;
  while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
code_r0x97bb5f28:
    iVar12 = *piVar20;
    piVar20 = piVar20 + -1;
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
  local_e0[9] = 0;
  uVar3 = 0x60000;
  uVar21 = 0x800000;
  local_e0[8] = 0x20000000;
  local_e0[0xc] = 0x800000;
  local_e0[10] = 0x60000;
  local_90 = *(undefined4 *)(iVar24 + 0x3c);
  local_e0[0xb] = (uint)uVar23;
  local_8c = 0;
  local_e0[0xd] = (uint)(ushort)(*(short *)(*piVar10 + 0x12) + (short)local_60);
  uVar6 = *(uint *)((int)local_e0 + iVar4);
  while ((uVar6 == uVar17 && (uVar29 < uVar18))) {
    uVar6 = *(uint *)((int)local_e0 + iVar4 + 0x10);
    if (uVar6 == 1) {
      uVar3 = (uVar2 & 3) << 6 | uVar3 & 0xffffff3f | 0x4000;
code_r0x97bb60fc:
      uVar3 = (uVar6 & 3) << 10 | uVar3 & 0xfffff3ff;
      local_e0[10] = uVar3;
    }
    else {
      if (1 < (int)uVar6) {
        if (uVar6 == 2) {
          uVar3 = (uVar2 & 3) << 4 | uVar3 & 0xffffffcf | 0x8000;
        }
        else {
          if (uVar6 != 3) goto code_r0x97bb6108;
          uVar3 = (uVar2 & 3) << 2 | uVar3 & 0xfffffff3 | 0x10000;
        }
        goto code_r0x97bb60fc;
      }
      if (uVar6 == 0) {
        uVar3 = (uVar2 & 3) << 8 | uVar3 & 0xfffffcff | 0x2000;
        goto code_r0x97bb60fc;
      }
    }
code_r0x97bb6108:
    if (uVar2 == 1) {
      uVar21 = (uVar29 & 3) << 0x13 | uVar21 & 0xffe7ffff;
code_r0x97bb6150:
      local_e0[0xc] = uVar21;
    }
    else {
      if (1 < (int)uVar2) {
        if (uVar2 == 2) {
          uVar21 = (uVar29 & 3) << 0x11 | uVar21 & 0xfff9ffff;
        }
        else {
          if (uVar2 != 3) goto code_r0x97bb6154;
          uVar21 = (uVar29 & 3) << 0xf | uVar21 & 0xfffe7fff;
        }
        goto code_r0x97bb6150;
      }
      if (uVar2 == 0) {
        uVar21 = (uVar29 & 3) << 0x15 | uVar21 & 0xff9fffff;
        goto code_r0x97bb6150;
      }
    }
code_r0x97bb6154:
    uVar29 = uVar29 + 1;
    uVar2 = uVar2 + 1;
    iVar4 = uVar29 * 4;
    uVar6 = local_e0[uVar29];
  }
  local_e0[0xc] = (uVar2 - 1) * 0x1000 & 0x3000 | uVar21;
  local_e0[9] = (uVar2 - 1) * 0x4000000 & 0xc000000 | 0x800000;
  iVar19 = _PPStreamInsertOperationAfterChunk(iVar14,local_58,0,0,*(undefined4 *)(iVar24 + 4));
  _PPStreamChangeBranchTargets
            (*(undefined4 *)(this + 0x30),*(uint *)(iVar24 + 0xc) & 0x3ffff,
             *(uint *)(iVar19 + 0xc) & 0x3ffff);
  if (uVar18 <= uVar29) goto code_r0x97bb61d0;
  goto code_r0x97bb5ec0;
code_r0x97bb62a8:
  uVar2 = 0;
  uVar17 = *(uint *)((int)local_e0 + iVar4);
  for (iVar19 = **(int **)(*(int *)(this + 0x34) + 0x18); iVar19 != 0; iVar19 = *(int *)(iVar19 + 8)
      ) {
    if (((*(uint *)(iVar19 + 0xc) & 0xf0000) == 0x70000) &&
       ((*(uint *)(iVar19 + 0xc) & 0x1f) == uVar17)) {
      uVar23 = *(ushort *)(iVar19 + 0x12);
      uVar3 = 3;
      piVar20 = (int *)(uVar17 * 0x10 + iVar27 + 0xc);
      goto code_r0x97bb630c;
    }
  }
  local_6c = 0;
  local_70 = uVar17 & 0x1f | 0x4070000;
  piVar20 = (int *)(uVar17 * 0x10 + iVar27 + 0xc);
  uVar3 = 3;
  do {
    iVar19 = *piVar20;
    piVar20 = piVar20 + -1;
    if (iVar19 != 0) {
      local_70 = (uVar3 & 3) << 0x18 | uVar17 & 0x1f | 0x4070000;
      break;
    }
    uVar3 = uVar3 - 1;
  } while (-1 < (int)uVar3);
  uVar13 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(*(int *)(this + 0x34) + 0x18));
  uVar23 = (short)uVar13 + 1;
  local_6c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_6c) + 0)),uVar23);
  _PPStreamAddAttribBinding(*(undefined4 *)(this + 0x34),&local_70);
  goto code_r0x97bb63d0;
  while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
code_r0x97bb630c:
    iVar14 = *piVar20;
    piVar20 = piVar20 + -1;
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
  local_e0[0xb] = 0;
  local_e0[9] = 0;
  uVar21 = 0x20000;
  local_e0[8] = 0x20000000;
  local_e0[10] = 0x20000;
  local_90 = *(undefined4 *)(iVar24 + 0x3c);
  local_8c = 0;
  uVar3 = 0;
  local_e0[0xd] = (uint)uVar23;
  local_e0[0xc] = 0;
  uVar6 = *(uint *)((int)local_e0 + iVar4);
  local_e0[0xb] = (uint)(ushort)(*(short *)(*(int *)pPVar7 + 0x12) + (short)local_60);
  while ((uVar6 == uVar17 && (uVar29 < uVar18))) {
    if (uVar2 == 1) {
      uVar21 = (uVar29 & 3) << 6 | uVar21 & 0xffffff3f | 0x4000;
code_r0x97bb64dc:
      local_e0[10] = uVar21;
    }
    else {
      if (1 < (int)uVar2) {
        if (uVar2 == 2) {
          uVar21 = (uVar29 & 3) << 4 | uVar21 & 0xffffffcf | 0x8000;
        }
        else {
          if (uVar2 != 3) goto code_r0x97bb64e0;
          uVar21 = (uVar29 & 3) << 2 | uVar21 & 0xfffffff3 | 0x10000;
        }
        uVar21 = (uVar2 & 3) << 10 | uVar21 & 0xfffff3ff;
        goto code_r0x97bb64dc;
      }
      if (uVar2 == 0) {
        uVar21 = (uVar29 & 3) << 8 | uVar21 & 0xfffffcff | 0x2000;
        goto code_r0x97bb64dc;
      }
    }
code_r0x97bb64e0:
    if (uVar2 == 1) {
      uVar3 = (*(uint *)((int)local_e0 + iVar4 + 0x10) & 3) << 0x13 | uVar3 & 0xffe7ffff;
code_r0x97bb6544:
      local_e0[0xc] = uVar3;
    }
    else {
      if (1 < (int)uVar2) {
        if (uVar2 == 2) {
          uVar3 = (*(uint *)((int)local_e0 + iVar4 + 0x10) & 3) << 0x11 | uVar3 & 0xfff9ffff;
        }
        else {
          if (uVar2 != 3) goto code_r0x97bb6548;
          uVar3 = (*(uint *)((int)local_e0 + iVar4 + 0x10) & 3) << 0xf | uVar3 & 0xfffe7fff;
        }
        goto code_r0x97bb6544;
      }
      if (uVar2 == 0) {
        uVar3 = (*(uint *)((int)local_e0 + iVar4 + 0x10) & 3) << 0x15 | uVar3 & 0xff9fffff;
        goto code_r0x97bb6544;
      }
    }
code_r0x97bb6548:
    uVar29 = uVar29 + 1;
    uVar2 = uVar2 + 1;
    iVar4 = uVar29 * 4;
    uVar6 = local_e0[uVar29];
  }
  iVar19 = uVar2 - 1;
  local_e0[0xc] = iVar19 * 0x1000 & 0x3000U | uVar3;
  local_e0[10] = iVar19 * 0x400 & 0xc00U | uVar21 & 0xfffff3ff;
  local_e0[9] = iVar19 * 0x4000000 & 0xc000000U | 0x800000;
  uVar2 = FunctionTable__getFirstOp(*(unsigned char **)(this + 0x3c),uVar9);
  if (uVar2 == (*(uint *)(iVar24 + 0xc) & 0x3ffff)) {
    iVar19 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(*(int *)(this + 0x34) + 0x20));
    *(uint *)(iVar24 + 0xc) = iVar19 + 1U & 0x3ffff | *(uint *)(iVar24 + 0xc) & 0xfffc0000;
    uVar13 = FunctionTable__getFirstOp(*(unsigned char **)(this + 0x3c),uVar9);
    _PPStreamChangeBranchTargets
              (*(undefined4 *)(this + 0x34),uVar13,*(uint *)(iVar24 + 0xc) & 0x3ffff);
  }
  iVar19 = _PPStreamInsertOperationAfterChunk
                     (*(undefined4 *)(this + 0x34),local_58,0,1,*(undefined4 *)(iVar24 + 4));
  if (iVar19 != 0) {
    FunctionTable__setFirstOp(*(unsigned char **)(this + 0x3c),uVar9,0);
    for (iVar14 = **(int **)(*(int *)(this + 0x34) + 0x24); iVar24 = iVar19, iVar14 != 0;
        iVar14 = *(int *)(iVar14 + 8)) {
      iVar12 = _memcmp("main(",iVar14 + 0x14,6);
      if (iVar12 == 0) {
        *(undefined4 *)(iVar14 + 0xc) = 0;
        break;
      }
    }
  }
  if (uVar18 <= uVar29) goto code_r0x97bb6720;
  goto code_r0x97bb62a8;
}

/* TGenericLinker__CoalesceCommonUniforms @ 0x97bb6b48 (484 bytes) */
int TGenericLinker__CoalesceCommonUniforms(this)
  unsigned char * this;
{
  unsigned char _Var1;
  uint uVar2;
  unsigned char * pPVar3;
  unsigned char * this_00;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  unsigned char * p_Var8;
  unsigned char * pTVar9;
  unsigned char * p_Var10;
  undefined8 local_70;
  uint local_60;
  uint uStack_5c;
  
  iVar7 = 0;
  iVar6 = 0;
  pTVar9 = this;
  do {
    if (*(unsigned char **)(pTVar9 + 0x28) != (unsigned char *)0x0) {
      for (pPVar3 = (unsigned char *)
                    ParseSymbolTable__NextSymbol
                              (*(unsigned char **)(pTVar9 + 0x28),(unsigned char *)0x0);
          pPVar3 != (unsigned char *)0x0;
          pPVar3 = (unsigned char *)
                   ParseSymbolTable__NextSymbol(*(unsigned char **)(pTVar9 + 0x28),pPVar3)) {
        p_Var10 = *(unsigned char **)pPVar3;
        if ((p_Var10 != (unsigned char *)0x0) && (*p_Var10 == 0x3)) {
          (*(unsigned int *)((unsigned char *)&(local_70) + 0)) = (uint)(*(ulonglong *)(p_Var10 + 0xc) >> 0x20);
          uVar2 = ((*(unsigned int *)((unsigned char *)&(local_70) + 0)) & 0xfcffffff) >> 0x10 & 0x1f;
          local_70 = *(ulonglong *)(p_Var10 + 0xc) & 0xfcffffffffff0000;
          if ((2 < uVar2) &&
             ((uVar2 < 0x13 &&
              (this_00 = (unsigned char *)
                         ParseSymbolTable__NextSymbol(*(unsigned char **)(pTVar9 + 0x28),pPVar3),
              this_00 != (unsigned char *)0x0)))) {
            _Var1 = *p_Var10;
            while (_Var1 == 0x3) {
              p_Var8 = *(unsigned char **)this_00;
              if (((p_Var8 != (unsigned char *)0x0) && (p_Var8 != p_Var10)) &&
                 (*p_Var8 == 0x3)) {
                local_60 = (uint)((ulonglong)*(undefined8 *)(p_Var8 + 0xc) >> 0x20);
                uStack_5c = (uint)*(undefined8 *)(p_Var8 + 0xc) & 0xffff0000;
                if ((((local_60 & 0xfcffffff) == (*(unsigned int *)((unsigned char *)&(local_70) + 0))) && (uStack_5c == (*(unsigned int *)((unsigned char *)&(local_70) + 4))))
                   && (iVar4 = _PPStreamGetArray(*(undefined4 *)(this + iVar6 + 0x30),2,
                                                 (uint)*(ushort *)(p_Var8 + 0x12)), iVar4 == -1)) {
                  _PPStreamRenumberOperandIndices
                            (*(undefined4 *)(this + iVar6 + 0x30),p_Var8,
                             (uint)*(ushort *)(p_Var10 + 0x12));
                  uVar5 = *(uint *)(p_Var10 + 0xc) >> 0x18 & 3;
                  uVar2 = *(uint *)(p_Var8 + 0xc) >> 0x18 & 3;
                  if (uVar2 < uVar5) {
                    uVar2 = uVar5;
                  }
                  *(uint *)(p_Var10 + 0xc) = uVar2 << 0x18 | *(uint *)(p_Var10 + 0xc) & 0xfcffffff;
                  _PPStreamChunkListRemoveChunk
                            (*(undefined4 *)(*(int *)(this + iVar6 + 0x30) + 0x10),p_Var8);
                  ParseSymbol__SetChunk(this_00,p_Var10);
                  *(undefined4 *)(this_00 + 0x44) = 0;
                }
              }
              this_00 = (unsigned char *)
                        ParseSymbolTable__NextSymbol
                                  (*(unsigned char **)(this + iVar6 + 0x28),this_00);
              if (this_00 == (unsigned char *)0x0) break;
              _Var1 = *p_Var10;
            }
          }
        }
      }
    }
    iVar7 = iVar7 + 1;
    iVar6 = iVar6 + 4;
    pTVar9 = pTVar9 + 4;
    if (1 < iVar7) {
      return 1;
    }
  } while( true );
}

/* TGenericLinker__BuildUniformRemapTables @ 0x97bb6d2c (372 bytes) */
int TGenericLinker__BuildUniformRemapTables(this)
  unsigned char * this;
{
  bool bVar1;
  unsigned char * this_00;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  int iVar11;
  unsigned char * pTVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  uint uVar16;
  void *pvVar17;
  
  uVar10 = 1;
  this_00 = (unsigned char *)BindingTable__NextUniformBinding(*(unsigned char **)(this + 4),(unsigned char *)0x0)
  ;
  iVar11 = 0;
  pTVar12 = this;
  do {
    iVar2 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4));
    uVar3 = _malloc(iVar2 * 4 + 0xfU & 0xfffffff0);
    *(undefined4 *)(pTVar12 + 0x40) = uVar3;
    if (*(int *)(pTVar12 + 0x28) == 0) {
      *(undefined4 *)(pTVar12 + 0x48) = 0;
    }
    else {
      *(undefined4 *)(pTVar12 + 0x48) = *(undefined4 *)(*(int *)(pTVar12 + 0x28) + 0x28);
    }
    for (iVar2 = 0; iVar4 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4)),
        iVar2 < iVar4; iVar2 = iVar2 + 1) {
      *(undefined4 *)(iVar2 * 4 + *(int *)(pTVar12 + 0x40)) = 0xffffffff;
    }
    iVar11 = iVar11 + 1;
    pTVar12 = pTVar12 + 4;
  } while (iVar11 < 2);
  for (; this_00 != (unsigned char *)0x0;
      this_00 = (unsigned char *)BindingTable__NextUniformBinding(*(unsigned char **)(this + 4),this_00)) {
    iVar11 = Binding__IsBuiltIn(this_00);
    if (iVar11 == 0) {
      uVar9 = 0;
      bVar1 = false;
      iVar11 = 0;
      do {
        if ((*(unsigned char **)(this + iVar11 * 4 + 0x28) != (unsigned char *)0x0) &&
           (piVar5 = (int *)ParseSymbolTable__FindGlobalSymbolByName
                                      (*(unsigned char **)(this + iVar11 * 4 + 0x28),
                                       *(char **)(this_00 + 8)), piVar5 != (int *)0x0)) {
          if ((*(char *)*piVar5 != '\x03') ||
             ((*(uint *)((char *)*piVar5 + 0xc) & 0x1f0000) != 0x10000)) {
            iVar13 = piVar5[5];
            iVar2 = _strlen(DAT_a7b7bb74);
            iVar4 = _strlen(iVar13);
            pcVar6 = (char *)_malloc(iVar2 + iVar4 + 1);
            _sprintf(pcVar6,DAT_a7b7bb74,iVar13);
            pvVar17 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar17,"INTERNAL ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar17,pcVar6);
            __ZN13TInfoSinkBase6appendEPKc(pvVar17,"\n");
            uVar10 = 0;
            _free(pcVar6);
          }
          if (bVar1) {
            if (*(ushort *)(piVar5 + 0xb) != uVar9) {
              iVar14 = piVar5[5];
              iVar2 = _strlen(UNK_a7b7bae4);
              iVar4 = _strlen(iVar14);
              uVar10 = ((int (*)())GetShaderStringForType)(uVar9);
              iVar13 = _strlen(uVar10);
              uVar10 = ((int (*)())GetShaderStringForType)((uint)*(ushort *)(piVar5 + 0xb));
              iVar7 = _strlen(uVar10);
              pcVar6 = (char *)_malloc(iVar2 + iVar4 + iVar13 + iVar7 + 1);
              uVar10 = ((int (*)())GetShaderStringForType)((uint)*(ushort *)(piVar5 + 0xb));
              uVar3 = ((int (*)())GetShaderStringForType)(uVar9);
              _sprintf(pcVar6,UNK_a7b7bae4,iVar14,uVar3,uVar10);
              pvVar17 = *(void **)(this + 0x84);
                    
              __ZN13TInfoSinkBase6appendEPKc(pvVar17,"ERROR: ");
              __ZN13TInfoSinkBase6appendEPKc(pvVar17,pcVar6);
              __ZN13TInfoSinkBase6appendEPKc(pvVar17,"\n");
              uVar10 = 0;
              _free(pcVar6);
            }
          }
          else {
            uVar9 = (uint)*(ushort *)(piVar5 + 0xb);
            bVar1 = true;
          }
          uVar16 = (uint)*(ushort *)(*piVar5 + 0xe);
          for (uVar15 = 0; uVar8 = Binding__GetBindingSlots(this_00), uVar15 < uVar8;
              uVar15 = uVar15 + 1) {
            iVar2 = Binding__GetLocation(this_00);
            *(uint *)((iVar2 + uVar15) * 4 + *(int *)(this + iVar11 * 4 + 0x40)) = uVar16;
            uVar16 = uVar16 + 1;
          }
        }
        iVar11 = iVar11 + 1;
      } while (iVar11 < 2);
    }
  }
  iVar11 = 0;
  iVar2 = 0;
  for (iVar4 = 0; iVar13 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4)),
      pcVar6 = UNK_a7b7bb04, iVar4 < iVar13; iVar4 = iVar4 + 1) {
    if (*(int *)(iVar4 * 4 + *(int *)(this + 0x40)) != -1) {
      iVar11 = iVar11 + 1;
    }
    if (*(int *)(iVar4 * 4 + *(int *)(this + 0x44)) != -1) {
      iVar2 = iVar2 + 1;
    }
  }
  if (*(int *)(this + 0x48) != iVar11) {
    pvVar17 = *(void **)(this + 0x84);
                    
    __ZN13TInfoSinkBase6appendEPKc(pvVar17,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(pvVar17,pcVar6);
    __ZN13TInfoSinkBase6appendEPKc(pvVar17,"\n");
    uVar10 = 0;
  }
  pcVar6 = UNK_a7b7bb08;
  if (*(int *)(this + 0x4c) != iVar2) {
    pvVar17 = *(void **)(this + 0x84);
                    
    __ZN13TInfoSinkBase6appendEPKc(pvVar17,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(pvVar17,pcVar6);
    __ZN13TInfoSinkBase6appendEPKc(pvVar17,"\n");
    uVar10 = 0;
  }
  return uVar10;
}

/* TGenericLinker__InsertUniformBindingFromSymbol @ 0x97bb727c (388 bytes) */
int TGenericLinker__InsertUniformBindingFromSymbol(this, param_2, param_3)
  unsigned char * this;
  unsigned char * param_2;
  int param_3;
{
  unsigned char * this_00;
  unsigned char * pBVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  void *this_01;
  
  uVar5 = 1;
  if ((**(char **)param_2 == '\x03') &&
     ((*(uint *)(*(char **)param_2 + 0xc) & 0x1f0000) != 0x110000)) {
    this_00 = operator_new(0x38);
    __ZN7BindingC1Ev(this_00);
    if (this_00 == (unsigned char *)0x0) {
      uVar5 = *(undefined4 *)(param_2 + 0x14);
      iVar2 = _strlen(DAT_a7b7bb7c);
      iVar3 = _strlen(uVar5);
      pcVar4 = (char *)_malloc(iVar2 + iVar3 + 1);
      _sprintf(pcVar4,DAT_a7b7bb7c,uVar5);
      this_01 = *(void **)(this + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(this_01,"INTERNAL ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(this_01,pcVar4);
      __ZN13TInfoSinkBase6appendEPKc(this_01,"\n");
      _free(pcVar4);
      uVar5 = 0;
    }
    else {
      Binding__SetName(this_00,*(char **)(param_2 + 0x14));
      pBVar1 = (unsigned char *)BindingTable__FindUniformBinding(*(unsigned char **)(this + 4),this_00);
      if (pBVar1 == (unsigned char *)0x0) {
        Binding__SetClientRequest(this_00,0);
        Binding__SetOpenGLType(this_00,*(ushort *)(param_2 + 0x2c));
        Binding__SetDecSize(this_00,(int)*(short *)(param_2 + 0x2e));
        Binding__SetActualSize(this_00,1);
        Binding__SetBuiltIn(this_00,*(undefined4 *)(param_2 + 0x34));
        if (*(short *)(param_2 + 0x2e) == 1) {
          BindingTable__InsertSingleUniform(*(unsigned char **)(this + 4),this_00,param_3);
        }
        else {
          BindingTable__InsertUniformArray
                    (*(unsigned char **)(this + 4),this_00,(int)*(short *)(param_2 + 0x30),param_3,2,
                     (unsigned char **)(this + 0x28));
        }
      }
      else {
        if (*(short *)(param_2 + 0x2e) == 1) {
          BindingTable__AddSingleUniformReference(*(unsigned char **)(this + 4),pBVar1,param_3);
        }
        __ZN7BindingD1Ev(this_00);
        __ZdlPv(this_00);
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
  unsigned char * pPVar2;
  int iVar3;
  undefined4 uVar4;
  unsigned char * pTVar5;
  int iVar6;
  unsigned char * pTVar7;
  
  uVar4 = 1;
  iVar6 = 0;
  pTVar7 = this + 0x28;
  pTVar5 = this;
  do {
    pPVar1 = *(unsigned char **)pTVar7;
    pTVar7 = pTVar7 + 4;
    if (pPVar1 != (unsigned char *)0x0) {
      for (pPVar2 = (unsigned char *)ParseSymbolTable__NextSymbol(pPVar1,(unsigned char *)0x0);
          pPVar2 != (unsigned char *)0x0;
          pPVar2 = (unsigned char *)
                   ParseSymbolTable__NextSymbol(*(unsigned char **)(pTVar5 + 0x28),pPVar2)) {
        if ((*(int *)(pPVar2 + 0x34) == 0) &&
           (iVar3 = ((int (*)())TGenericLinker__InsertUniformBindingFromSymbol)(this,pPVar2,iVar6), iVar3 == 0)) {
          uVar4 = 0;
        }
      }
    }
    iVar6 = iVar6 + 1;
    pTVar5 = pTVar5 + 4;
  } while (iVar6 < 2);
  iVar6 = 0;
  pTVar7 = this + 0x28;
  pTVar5 = this;
  do {
    pPVar1 = *(unsigned char **)pTVar7;
    pTVar7 = pTVar7 + 4;
    if (pPVar1 != (unsigned char *)0x0) {
      for (pPVar2 = (unsigned char *)ParseSymbolTable__NextSymbol(pPVar1,(unsigned char *)0x0);
          pPVar2 != (unsigned char *)0x0;
          pPVar2 = (unsigned char *)
                   ParseSymbolTable__NextSymbol(*(unsigned char **)(pTVar5 + 0x28),pPVar2)) {
        if ((*(int *)(pPVar2 + 0x34) != 0) &&
           (iVar3 = ((int (*)())TGenericLinker__InsertUniformBindingFromSymbol)(this,pPVar2,iVar6), iVar3 == 0)) {
          uVar4 = 0;
        }
      }
    }
    iVar6 = iVar6 + 1;
    pTVar5 = pTVar5 + 4;
  } while (iVar6 < 2);
  return uVar4;
}

/* TGenericLinker__CreateFunctionTable @ 0x97bb75c0 (428 bytes) */
int TGenericLinker__CreateFunctionTable(this, param_2)
  unsigned char * this;
  int param_2;
{
  int iVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  unsigned char * this_00;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  unsigned char * pFVar16;
  unsigned char * this_01;
  int iVar17;
  uint uVar18;
  void *pvVar19;
  
  iVar1 = param_2 * 4;
  this_00 = operator_new(8);
  bVar4 = false;
  __ZN13FunctionTableC1Ev(this_00);
  iVar13 = 0;
  if (0 < *(int *)(this + iVar1 + 0x20)) {
    do {
      iVar15 = 0;
      pFVar16 = *(unsigned char **)(*(int *)(iVar13 * 4 + *(int *)(this + iVar1 + 8)) + 0x6c);
      if (0 < *(int *)(pFVar16 + 4)) {
        do {
          bVar2 = false;
          iVar14 = 0;
          if (iVar13 < 1) {
LAB_97bb7818:
            pcVar12 = (char *)FunctionTable__getFunctionName(pFVar16,iVar15);
            iVar14 = FunctionTable__addFunction(this_00,pcVar12);
            uVar5 = FunctionTable__getEmpty(pFVar16,iVar15);
            FunctionTable__setEmpty(this_00,iVar14,uVar5);
            uVar5 = FunctionTable__getReturnVal(pFVar16,iVar15);
            FunctionTable__setReturnVal(this_00,iVar14,uVar5);
            iVar17 = FunctionTable__getNumParams(pFVar16,iVar15);
            FunctionTable__setNumParams(this_00,iVar14,iVar17);
            uVar18 = FunctionTable__getFirstOp(pFVar16,iVar15);
            FunctionTable__setFirstOp(this_00,iVar14,uVar18);
            uVar18 = FunctionTable__getLastOp(pFVar16,iVar15);
            FunctionTable__setLastOp(this_00,iVar14,uVar18);
          }
          else {
            do {
              iVar17 = 0;
              this_01 = *(unsigned char **)
                         (*(int *)(iVar14 * 4 + *(int *)(this + iVar1 + 8)) + 0x6c);
              if (0 < *(int *)(this_01 + 4)) {
                do {
                  uVar5 = FunctionTable__getFunctionName(this_01,iVar17);
                  uVar6 = FunctionTable__getFunctionName(pFVar16,iVar15);
                  iVar7 = _strcmp(uVar5,uVar6);
                  if (iVar7 == 0) {
                    uVar5 = FunctionTable__getFunctionName(this_01,iVar17);
                    iVar7 = _strlen(uVar5);
                    iVar7 = _malloc(iVar7 + 1);
                    uVar5 = FunctionTable__getFunctionName(this_01,iVar17);
                    _strcpy(iVar7,uVar5);
                    for (uVar18 = 0; uVar8 = _strlen(iVar7), uVar18 < uVar8; uVar18 = uVar18 + 1) {
                      if (*(char *)(iVar7 + uVar18) == '(') {
                        *(undefined1 *)(iVar7 + uVar18) = 0;
                      }
                    }
                    iVar9 = _strlen(DAT_a7b7bb20);
                    iVar10 = _strlen((&_shaderString)[param_2]);
                    iVar11 = _strlen(iVar7);
                    pcVar12 = (char *)_malloc(iVar9 + iVar10 + iVar11 + 1);
                    _sprintf(pcVar12,DAT_a7b7bb20,iVar7,(&_shaderString)[param_2]);
                    pvVar19 = *(void **)(this + 0x84);
                    
                    __ZN13TInfoSinkBase6appendEPKc(pvVar19,"ERROR: ");
                    __ZN13TInfoSinkBase6appendEPKc(pvVar19,pcVar12);
                    __ZN13TInfoSinkBase6appendEPKc(pvVar19,"\n");
                    _free(pcVar12);
                    _free(iVar7);
                    bVar2 = true;
                  }
                  iVar17 = iVar17 + 1;
                } while (iVar17 < *(int *)(this_01 + 4));
              }
              iVar14 = iVar14 + 1;
            } while (iVar14 < iVar13);
            if (!bVar2) goto LAB_97bb7818;
          }
          iVar15 = iVar15 + 1;
          bVar4 = (bool)(bVar4 | bVar2);
        } while (iVar15 < *(int *)(pFVar16 + 4));
      }
      for (iVar15 = **(int **)(*(int *)(iVar13 * 4 + *(int *)(this + iVar1 + 0x18)) + 0x20);
          iVar15 != 0; iVar15 = *(int *)(iVar15 + 8)) {
        if ((*(uint *)(iVar15 + 0xc) & 0x3fc0000) == 0x1300000) {
          bVar2 = false;
          iVar17 = 0;
          iVar14 = _malloc(*(int *)(iVar15 + 0x40) + 1);
          _strcpy(iVar14,iVar15 + 0x44);
          if (*(int *)(this + iVar1 + 0x20) < 1) {
            bVar3 = true;
          }
          else {
            do {
              iVar7 = 0;
              pFVar16 = *(unsigned char **)
                         (*(int *)(iVar17 * 4 + *(int *)(this + iVar1 + 8)) + 0x6c);
              if (0 < *(int *)(pFVar16 + 4)) {
                do {
                  uVar5 = FunctionTable__getFunctionName(pFVar16,iVar7);
                  iVar9 = _strcmp(iVar14,uVar5);
                  if (iVar9 == 0) {
                    bVar2 = true;
                    break;
                  }
                  iVar7 = iVar7 + 1;
                } while (iVar7 < *(int *)(pFVar16 + 4));
              }
              bVar3 = !bVar2;
              if (!bVar3) goto code_r0x97bb7ad8;
              iVar17 = iVar17 + 1;
            } while (iVar17 < *(int *)(this + iVar1 + 0x20));
          }
          if (bVar3) {
            for (uVar18 = 0; uVar8 = _strlen(iVar14), uVar18 < uVar8; uVar18 = uVar18 + 1) {
              if (*(char *)(iVar14 + uVar18) == '(') {
                *(undefined1 *)(iVar14 + uVar18) = 0;
              }
            }
            iVar17 = _strlen(UNK_a7b7bb24);
            iVar7 = _strlen((&_shaderString)[param_2]);
            iVar9 = _strlen(iVar14);
            pcVar12 = (char *)_malloc(iVar17 + iVar7 + iVar9 + 1);
            _sprintf(pcVar12,UNK_a7b7bb24,iVar14,(&_shaderString)[param_2]);
            pvVar19 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar19,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar19,pcVar12);
            __ZN13TInfoSinkBase6appendEPKc(pvVar19,"\n");
            _free(pcVar12);
            bVar4 = true;
          }
code_r0x97bb7ad8:
          _free(iVar14);
        }
      }
      iVar13 = iVar13 + 1;
    } while (iVar13 < *(int *)(this + iVar1 + 0x20));
    if (bVar4) goto code_r0x97bb7b18;
  }
  if (*(int *)(this_00 + 4) != 0) {
    return this_00;
  }
code_r0x97bb7b18:
  if (this_00 != (unsigned char *)0x0) {
    __ZN13FunctionTableD1Ev(this_00);
    __ZdlPv(this_00);
  }
  return (unsigned char *)0x0;
}

/* TGenericLinker__BuildSymbolTableList @ 0x97bb7b4c (352 bytes) */
int TGenericLinker__BuildSymbolTableList(this, param_2, param_3)
  unsigned char * this;
  void **param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  size_t sVar5;
  size_t sVar6;
  char *pcVar7;
  void **extraout_r4;
  void **extraout_r4_00;
  void **a1;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  unsigned char * pTVar8;
  undefined4 a7;
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
  a7 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_48 = DAT_97c38fb0;
  iVar12 = 1;
  local_40[0] = DAT_97c38fb8;
  a1 = param_2;
  iVar11 = param_3;
  if (param_3 < 1) {
LAB_97bb7d6c:
    bVar1 = false;
    if (iVar12 == 1) {
      iVar11 = 0;
      do {
        if ((local_50[iVar11] == 0) && (0 < *(int *)(this + iVar11 * 4 + 0x20))) {
          sVar5 = _strlen(UNK_a7b7bab8);
          sVar6 = _strlen((char *)(&_shaderString)[iVar11]);
          pcVar7 = _malloc(sVar5 + sVar6 + 1);
          _sprintf(pcVar7,UNK_a7b7bab8,(&_shaderString)[iVar11]);
          pvVar13 = *(void **)(this + 0x84);
                    
override_jmp_97bb7df4_case_0:
          __ZN13TInfoSinkBase6appendEPKc(pvVar13,"ERROR: ");
          __ZN13TInfoSinkBase6appendEPKc(pvVar13,pcVar7);
          __ZN13TInfoSinkBase6appendEPKc(pvVar13,"\n");
          _free(pcVar7);
          iVar12 = 0;
        }
        else if (1 < local_50[iVar11]) {
          sVar5 = _strlen(UNK_a7b7babc);
          sVar6 = _strlen((char *)(&_shaderString)[iVar11]);
          pcVar7 = _malloc(sVar5 + sVar6 + 9);
          _sprintf(pcVar7,UNK_a7b7babc,local_50[iVar11],(&_shaderString)[iVar11]);
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
        a1 = extraout_r4_00;
      }
      else {
        iVar4 = (**(code **)(*piVar3 + 8))(piVar3,a1,iVar11,in_r6,in_r7,in_r8,pTVar8,a7);
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
        a1 = extraout_r4;
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
        pPVar2 = (unsigned char *)
                 ParseSymbolTable__CopySymbolTable
                           (*(unsigned char **)(*(int *)ppvVar5[2] + 0x68));
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

/* __ZN14TGenericLinkerC2Ei @ 0x97bb811c (4 bytes) */
int __ZN14TGenericLinkerC2Ei(this, param_2)
  void *this;
  int param_2;
{
  undefined *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  void *this_00;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  
  *(int *)this = DAT_a7b7bba0 + 8;
  *(int *)((int)this + 0x7c) = param_2;
  puVar3 = operator_new(0x10);
  puVar1 = PTR__S_empty_rep_storage_a7b7c0f0;
  piVar2 = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar4 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar4;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  puVar3[1] = 4;
  *puVar3 = puVar1 + 0xc;
  do {
    if (in_RESERVE != '\0') {
      iVar4 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar4;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  puVar3[2] = puVar1 + 0xc;
  puVar3[3] = 4;
  *(undefined4 *)((int)this + 0x80) = 1;
  *(undefined4 **)((int)this + 0x84) = puVar3;
  *(int *)((int)this + 0x7c) = param_2;
  this_00 = operator_new(0x48);
  __ZN12BindingTableC1Ej(this_00,0x80);
  *(void **)((int)this + 4) = this_00;
  iVar4 = (int)this + 4;
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
  } while ((int)this <= iVar4);
  return;
}

/* __ZN14TGenericLinkerC1Ei @ 0x97bb8120 (4 bytes) */
int __ZN14TGenericLinkerC1Ei(this, param_2)
  void *this;
  int param_2;
{
  undefined *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  void *this_00;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  
  *(int *)this = DAT_a7b7bba0 + 8;
  *(int *)((int)this + 0x7c) = param_2;
  puVar3 = operator_new(0x10);
  puVar1 = PTR__S_empty_rep_storage_a7b7c0f0;
  piVar2 = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar4 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar4;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  puVar3[1] = 4;
  *puVar3 = puVar1 + 0xc;
  do {
    if (in_RESERVE != '\0') {
      iVar4 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar4;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  puVar3[2] = puVar1 + 0xc;
  puVar3[3] = 4;
  *(undefined4 *)((int)this + 0x80) = 1;
  *(undefined4 **)((int)this + 0x84) = puVar3;
  *(int *)((int)this + 0x7c) = param_2;
  this_00 = operator_new(0x48);
  __ZN12BindingTableC1Ej(this_00,0x80);
  *(void **)((int)this + 4) = this_00;
  iVar4 = (int)this + 4;
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
  } while ((int)this <= iVar4);
  return;
}

/* __ZN14TGenericLinkerC4Ei @ 0x97bb8124 (268 bytes) */
int __ZN14TGenericLinkerC4Ei(this, param_2)
  void *this;
  int param_2;
{
  undefined *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  void *this_00;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  
  *(int *)this = DAT_a7b7bba0 + 8;
  *(int *)((int)this + 0x7c) = param_2;
  puVar3 = operator_new(0x10);
  puVar1 = PTR__S_empty_rep_storage_a7b7c0f0;
  piVar2 = (int *)(PTR__S_empty_rep_storage_a7b7c0f0 + 8);
  do {
    if (in_RESERVE != '\0') {
      iVar4 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar4;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  puVar3[1] = 4;
  *puVar3 = puVar1 + 0xc;
  do {
    if (in_RESERVE != '\0') {
      iVar4 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar4;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  puVar3[2] = puVar1 + 0xc;
  puVar3[3] = 4;
  *(undefined4 *)((int)this + 0x80) = 1;
  *(undefined4 **)((int)this + 0x84) = puVar3;
  *(int *)((int)this + 0x7c) = param_2;
  this_00 = operator_new(0x48);
  __ZN12BindingTableC1Ej(this_00,0x80);
  *(void **)((int)this + 4) = this_00;
  iVar4 = (int)this + 4;
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
  } while ((int)this <= iVar4);
  return;
}

/* __ZN14TGenericLinkerD2Ev @ 0x97bb8230 (8 bytes) */
int __ZN14TGenericLinkerD2Ev(this)
  void *this;
{
  ((int (*)())__ZN14TGenericLinkerD4Ev)(this,0);
  return;
}

/* __ZN14TGenericLinkerD1Ev @ 0x97bb8238 (8 bytes) */
int __ZN14TGenericLinkerD1Ev(this)
  void *this;
{
  ((int (*)())__ZN14TGenericLinkerD4Ev)(this,2);
  return;
}

/* __ZN14TGenericLinkerD0Ev @ 0x97bb8240 (8 bytes) */
int __ZN14TGenericLinkerD0Ev(this)
  void *this;
{
  ((int (*)())__ZN14TGenericLinkerD4Ev)(this,3);
  return;
}

/* __ZN14TGenericLinkerD4Ev @ 0x97bb8248 (244 bytes) */
int __ZN14TGenericLinkerD4Ev(this, param_2)
  void *this;
  uint param_2;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  void *this_00;
  char in_RESERVE;
  byte in_cr0;
  
  *(int *)this = DAT_a7b7bba0 + 8;
  ((int (*)())TGenericLinker__reset)(this);
  piVar5 = *(int **)((int)this + 0x84);
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
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(iVar4 + -0xc));
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
      __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(iVar4 + -0xc));
    }
    __ZdlPv(piVar5);
  }
  this_00 = *(void **)((int)this + 4);
  if (this_00 != (void *)0x0) {
    __ZN12BindingTableD1Ev(this_00);
    __ZdlPv(this_00);
  }
  *(undefined ***)this = &PTR___ZN13TShHandleBaseD1Ev_a7b7d700;
  if ((param_2 & 1) != 0) {
    __ZdlPv(this);
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
int TGenericLinker__attributeBindingRequest(this, param_2, param_3)
  unsigned char * this;
  ulong param_2;
  char *param_3;
{
  int iVar1;
  unsigned char * this_00;
  
  iVar1 = _memcmp(param_3,"gl_",3);
  if (iVar1 != 0) {
    this_00 = operator_new(0x38);
    __ZN7BindingC1Ev(this_00);
    Binding__SetName(this_00,param_3);
    Binding__SetLocation(this_00,param_2);
    Binding__SetClientRequest(this_00,1);
    iVar1 = BindingTable__InsertAttribRequestBinding(*(unsigned char **)(this + 4),this_00);
    if ((iVar1 == 0) && (this_00 != (unsigned char *)0x0)) {
      __ZN7BindingD1Ev(this_00);
      __ZdlPv(this_00);
      return;
    }
  }
  return;
}

/* TGenericLinker__getActiveUniform @ 0x97bb8450 (192 bytes) */
int TGenericLinker__getActiveUniform(this, param_2, param_3, param_4, param_5, param_6, param_7)
  unsigned char * this;
  ulong param_2;
  long param_3;
  long *param_4;
  long *param_5;
  ulong *param_6;
  char *param_7;
{
  unsigned char * this_00;
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  
  this_00 = (unsigned char *)BindingTable__FindUniformBindingByIndex(*(unsigned char **)(this + 4),param_2)
  ;
  uVar1 = 0;
  if (this_00 != (unsigned char *)0x0) {
    if (param_3 == 0) {
      if (param_4 != (long *)0x0) {
        *param_4 = 0;
      }
    }
    else {
      _strncpy(param_7,*(char **)(this_00 + 8),param_3);
      param_7[param_3 + -1] = '\0';
      if (param_4 != (long *)0x0) {
        lVar2 = _strlen(param_7);
        *param_4 = lVar2;
      }
    }
    if (param_5 != (long *)0x0) {
      lVar2 = Binding__GetActualSize(this_00);
      *param_5 = lVar2;
    }
    if (param_6 != (ulong *)0x0) {
      uVar3 = Binding__GetOpenGLType(this_00);
      *param_6 = uVar3;
    }
    uVar1 = 1;
  }
  return uVar1;
}

/* TGenericLinker__getUniformTypeInfo @ 0x97bb8510 (172 bytes) */
int TGenericLinker__getUniformTypeInfo(this, param_2, param_3, param_4, param_5)
  unsigned char * this;
  long param_2;
  long *param_3;
  ulong *param_4;
  uchar *param_5;
{
  undefined4 uVar1;
  unsigned char * this_00;
  int iVar2;
  int iVar3;
  uint uVar4;
  ulong uVar5;
  
  this_00 = (unsigned char *)
            BindingTable__FindUniformBindingByLocation(*(unsigned char **)(this + 4),param_2);
  uVar1 = 0;
  if (this_00 != (unsigned char *)0x0) {
    if (param_3 != (long *)0x0) {
      iVar2 = Binding__GetActualSize(this_00);
      iVar3 = Binding__GetLocation(this_00);
      uVar4 = Binding__GetBindingBasicSize(this_00);
      *param_3 = iVar2 - (uint)(param_2 - iVar3) / uVar4;
    }
    if (param_4 != (ulong *)0x0) {
      uVar5 = Binding__GetOpenGLType(this_00);
      *param_4 = uVar5;
    }
    if (param_5 != (uchar *)0x0) {
      *param_5 = (uchar)this_00[0x34];
      *(unsigned char *)(param_5 + 1) = this_00[0x35];
    }
    uVar1 = 1;
  }
  return uVar1;
}

/* TGenericLinker__getActiveAttrib @ 0x97bb85bc (188 bytes) */
int TGenericLinker__getActiveAttrib(this, param_2, param_3, param_4, param_5, param_6, param_7)
  unsigned char * this;
  ulong param_2;
  long param_3;
  long *param_4;
  long *param_5;
  ulong *param_6;
  char *param_7;
{
  unsigned char * this_00;
  undefined4 uVar1;
  long lVar2;
  ulong uVar3;
  
  this_00 = (unsigned char *)BindingTable__GetAttribBindingByIndex(*(unsigned char **)(this + 4),param_2);
  uVar1 = 0;
  if (this_00 != (unsigned char *)0x0) {
    if (param_3 == 0) {
      if (param_4 != (long *)0x0) {
        *param_4 = 0;
      }
    }
    else {
      _strncpy(param_7,*(char **)(this_00 + 8),param_3);
      param_7[param_3 + -1] = '\0';
      if (param_4 != (long *)0x0) {
        *param_4 = *(long *)(this_00 + 0x10);
      }
    }
    if (param_5 != (long *)0x0) {
      lVar2 = Binding__GetActualSize(this_00);
      *param_5 = lVar2;
    }
    if (param_6 != (ulong *)0x0) {
      uVar3 = Binding__GetOpenGLType(this_00);
      *param_6 = uVar3;
    }
    uVar1 = 1;
  }
  return uVar1;
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
  void *pvVar1;
  unsigned char * pTVar2;
  
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
  pTVar2 = this;
  do {
    if (*(int *)(pTVar2 + 0x30) != 0) {
      _PPStreamFree(*(int *)(pTVar2 + 0x30));
    }
    pvVar1 = *(void **)(pTVar2 + 0x28);
    *(undefined4 *)(pTVar2 + 0x30) = 0;
    if (pvVar1 != (void *)0x0) {
      __ZN16ParseSymbolTableD1Ev(pvVar1);
      __ZdlPv(pvVar1);
    }
    pvVar1 = *(void **)(pTVar2 + 0x38);
    *(undefined4 *)(pTVar2 + 0x28) = 0;
    if (pvVar1 != (void *)0x0) {
      __ZN13FunctionTableD1Ev(pvVar1);
      __ZdlPv(pvVar1);
    }
    *(undefined4 *)(pTVar2 + 0x38) = 0;
    pTVar2 = pTVar2 + 4;
  } while ((int)pTVar2 <= (int)(this + 4));
  pTVar2 = this;
  do {
    if (*(int *)(pTVar2 + 8) != 0) {
      _free(*(int *)(pTVar2 + 8));
    }
    *(undefined4 *)(pTVar2 + 8) = 0;
    if (*(int *)(pTVar2 + 0x10) != 0) {
      _free(*(int *)(pTVar2 + 0x10));
    }
    *(undefined4 *)(pTVar2 + 0x10) = 0;
    if (*(int *)(pTVar2 + 0x18) != 0) {
      _free(*(int *)(pTVar2 + 0x18));
    }
    *(undefined4 *)(pTVar2 + 0x20) = 0;
    *(undefined4 *)(pTVar2 + 0x18) = 0;
    pTVar2 = pTVar2 + 4;
  } while ((int)pTVar2 <= (int)(this + 4));
  pTVar2 = this;
  do {
    if (*(int *)(pTVar2 + 0x40) != 0) {
      _free(*(int *)(pTVar2 + 0x40));
    }
    *(undefined4 *)(pTVar2 + 0x40) = 0;
    *(undefined4 *)(pTVar2 + 0x48) = 0;
    pTVar2 = pTVar2 + 4;
  } while ((int)pTVar2 <= (int)(this + 4));
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
int TGenericLinker__link(this, param_2, param_3)
  unsigned char * this;
  void **param_2;
  int param_3;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  unsigned char * pTVar7;
  void *pvVar8;
  
  iVar6 = 1;
  if (0 < param_3) {
    iVar6 = ((int (*)())TGenericLinker__BuildSymbolTableList)(this,param_2,param_3);
    if ((iVar6 == 1) && (iVar6 = ((int (*)())TGenericLinker__BuildProcessingComponents)((void **)this,(int)param_2), iVar6 == 1))
    {
      ((int (*)())TGenericLinker__RemoveExtraVertexOutputs)(this);
      ((int (*)())TGenericLinker__FixOutputReads)(this);
      iVar2 = ((int (*)())TGenericLinker__AllocateTextureUnitsForVaryings)(this);
      if (iVar2 == 0) {
        iVar6 = 0;
      }
      if (1 < *(int *)(this + 0x80)) {
        ((int (*)())TGenericLinker__OptimizeFunctionIO)(this);
        ((int (*)())TGenericLinker__RemoveUnreachableFunctions)(this);
        if (2 < *(int *)(this + 0x80)) {
          ((int (*)())TGenericLinker__RemoveUnusedRegisters)(this);
        }
      }
      pTVar7 = this;
      do {
        if (*(int *)(pTVar7 + 0x30) != 0) {
          ((int (*)())TGenericLinker__CoalesceCommonUniforms)(this);
          _PPStreamSortParamConstants(*(undefined4 *)(pTVar7 + 0x30));
          _PPStreamPackIndices(*(undefined4 *)(pTVar7 + 0x30));
        }
        pTVar7 = pTVar7 + 4;
      } while ((int)pTVar7 <= (int)(this + 4));
      if (iVar2 != 0) {
        iVar2 = 0;
        do {
          if ((*(int *)(this + iVar2 * 4 + 0x30) != 0) &&
             (iVar3 = _PPStreamResolveBranches(*(int *)(this + iVar2 * 4 + 0x30)), iVar3 != 0)) {
            iVar6 = _strlen(DAT_a7b7bb1c);
            iVar3 = _strlen((&_shaderString)[iVar2]);
            pcVar4 = (char *)_malloc(iVar6 + iVar3 + 1);
            _sprintf(pcVar4,DAT_a7b7bb1c,(&_shaderString)[iVar2]);
            pvVar8 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,pcVar4);
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,"\n");
            _free(pcVar4);
            iVar6 = 0;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < 2);
        if (iVar6 == 1) {
          iVar2 = ((int (*)())TGenericLinker__CollectClientAttributeBindings)(this);
          if (iVar2 == 0) {
            iVar6 = 0;
          }
          iVar2 = ((int (*)())TGenericLinker__CollectAttributeBindings)(this);
          if (iVar2 == 0) {
            iVar6 = 0;
          }
          iVar2 = ((int (*)())TGenericLinker__CollectUniformBindings)(this);
          if (iVar2 == 0) {
            iVar6 = 0;
          }
          iVar2 = BindingTable__GetSizeActiveAttributes(*(unsigned char **)(this + 4));
          if (0x10 < iVar2) {
            iVar6 = _strlen(UNK_a7b7bae8);
            pcVar4 = (char *)_malloc(iVar6 + 0x11);
            uVar5 = BindingTable__GetSizeActiveAttributes(*(unsigned char **)(this + 4));
            _sprintf(pcVar4,UNK_a7b7bae8,0x10,uVar5);
            pvVar8 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,pcVar4);
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,"\n");
            _free(pcVar4);
            iVar6 = 0;
          }
          iVar2 = BindingTable__GetSizeActiveVertexUniforms(*(unsigned char **)(this + 4));
          if (0x200 < iVar2) {
            iVar6 = _strlen(DAT_a7b7baec);
            pcVar4 = (char *)_malloc(iVar6 + 0x11);
            uVar5 = BindingTable__GetSizeActiveVertexUniforms(*(unsigned char **)(this + 4));
            _sprintf(pcVar4,DAT_a7b7baec,0x200,uVar5);
            pvVar8 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,pcVar4);
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,"\n");
            _free(pcVar4);
            iVar6 = 0;
          }
          iVar2 = BindingTable__GetSizeActiveFragmentUniforms(*(unsigned char **)(this + 4));
          if (0x200 < iVar2) {
            iVar6 = _strlen(DAT_a7b7baf0);
            pcVar4 = (char *)_malloc(iVar6 + 0x11);
            uVar5 = BindingTable__GetSizeActiveFragmentUniforms(*(unsigned char **)(this + 4));
            _sprintf(pcVar4,DAT_a7b7baf0,0x200,uVar5);
            pvVar8 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,pcVar4);
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,"\n");
            _free(pcVar4);
            iVar6 = 0;
          }
          iVar2 = BindingTable__GetNumActiveVertexSamplers(*(unsigned char **)(this + 4));
          if (0 < iVar2) {
            iVar6 = _strlen(UNK_a7b7baf4);
            pcVar4 = (char *)_malloc(iVar6 + 0x11);
            uVar5 = BindingTable__GetNumActiveVertexSamplers(*(unsigned char **)(this + 4));
            _sprintf(pcVar4,UNK_a7b7baf4,0,uVar5);
            pvVar8 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,pcVar4);
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,"\n");
            _free(pcVar4);
            iVar6 = 0;
          }
          iVar2 = BindingTable__GetNumActiveFragmentSamplers(*(unsigned char **)(this + 4));
          if (0x10 < iVar2) {
            iVar6 = _strlen(UNK_a7b7baf8);
            pcVar4 = (char *)_malloc(iVar6 + 0x11);
            uVar5 = BindingTable__GetNumActiveFragmentSamplers(*(unsigned char **)(this + 4));
            _sprintf(pcVar4,UNK_a7b7baf8,0x10,uVar5);
            pvVar8 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,pcVar4);
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,"\n");
            _free(pcVar4);
            iVar6 = 0;
          }
          iVar2 = BindingTable__GetNumActiveVertexSamplers(*(unsigned char **)(this + 4));
          iVar3 = BindingTable__GetNumActiveFragmentSamplers(*(unsigned char **)(this + 4));
          if (0x10 < iVar2 + iVar3) {
            iVar6 = _strlen(UNK_a7b7bafc);
            pcVar4 = (char *)_malloc(iVar6 + 0x11);
            iVar6 = BindingTable__GetNumActiveVertexSamplers(*(unsigned char **)(this + 4));
            iVar2 = BindingTable__GetNumActiveFragmentSamplers(*(unsigned char **)(this + 4));
            _sprintf(pcVar4,UNK_a7b7bafc,0x10,iVar6 + iVar2);
            pvVar8 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,pcVar4);
            __ZN13TInfoSinkBase6appendEPKc(pvVar8,"\n");
            _free(pcVar4);
            iVar6 = 0;
          }
          if (iVar6 == 1) {
            iVar2 = ((int (*)())TGenericLinker__RemapVertexAttributes)(this);
            if (iVar2 == 0) {
              iVar6 = 0;
            }
            bVar1 = iVar6 == 1;
            iVar2 = ((int (*)())TGenericLinker__BuildUniformRemapTables)(this);
            if (iVar2 == 0) {
              iVar6 = 0;
            }
            if ((iVar2 != 0 && bVar1) && (3 < *(int *)(this + 0x80))) {
              pTVar7 = this + 0x30;
              iVar2 = 1;
              do {
                iVar3 = *(int *)pTVar7;
                pTVar7 = pTVar7 + 4;
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
    if (iVar6 == 0) {
      reset(this);
    }
  }
  return iVar6;
}

/* TGenericLinker__getStatsString @ 0x97bb9098 (104 bytes) */
int TGenericLinker__getStatsString(this)
  unsigned char * this;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(this + 0x50);
  if (iVar1 == 0) {
    iVar1 = _strlen(DAT_a7b7bb5c);
    uVar2 = _malloc(iVar1 * 4 + 4);
    *(undefined4 *)(this + 0x50) = uVar2;
    _strcpy(uVar2,DAT_a7b7bb5c);
    iVar1 = *(int *)(this + 0x50);
  }
  return iVar1;
}

/* TGenericLinker__getPPStreamString @ 0x97bb9100 (604 bytes) */
int TGenericLinker__getPPStreamString(this)
  unsigned char * this;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int extraout_r3;
  int iVar4;
  int extraout_r3_00;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int local_30 [5];
  
  iVar6 = 0;
  iVar7 = 0;
  if (*(int *)(this + 0x54) != 0) {
    _free(*(int *)(this + 0x54));
  }
  *(undefined4 *)(this + 0x54) = 0;
  iVar2 = _strlen(DAT_a7b7bb4c);
  if (*(int *)(this + 0x30) == 0) {
    iVar6 = _strlen(DAT_a7b7bb58);
    iVar6 = _malloc(iVar6 + 1);
    _strcpy(iVar6,DAT_a7b7bb58);
  }
  else {
    _PPStreamGetStream(*(int *)(this + 0x30),0,local_30);
    if (local_30[0] != 0) {
      uVar3 = _malloc(local_30[0] * 8 + 0xfU & 0xfffffff0);
      _PPStreamGetStream(*(undefined4 *)(this + 0x30),uVar3,local_30);
      ((double (*)())_glpPPDisassemble)(uVar3);
      _free(uVar3);
      iVar6 = extraout_r3;
    }
  }
  if (iVar6 != 0) {
    iVar4 = _strlen(iVar6);
    iVar2 = iVar2 + iVar4;
  }
  iVar4 = _strlen(DAT_a7b7bb48);
  iVar2 = iVar2 + iVar4;
  if (*(int *)(this + 0x34) == 0) {
    iVar7 = _strlen(DAT_a7b7bb58);
    iVar7 = _malloc(iVar7 + 1);
    _strcpy(iVar7,DAT_a7b7bb58);
  }
  else {
    _PPStreamGetStream(*(int *)(this + 0x34),0,local_30);
    if (local_30[0] != 0) {
      uVar3 = _malloc(local_30[0] * 8 + 0xfU & 0xfffffff0);
      _PPStreamGetStream(*(undefined4 *)(this + 0x34),uVar3,local_30);
      ((double (*)())_glpPPDisassemble)(uVar3);
      _free(uVar3);
      iVar7 = extraout_r3_00;
    }
  }
  bVar1 = iVar7 == 0;
  if (!bVar1) {
    iVar4 = _strlen(iVar7);
    iVar2 = iVar2 + iVar4;
  }
  pcVar5 = (char *)_malloc(iVar2 + 8);
  *(char **)(this + 0x54) = pcVar5;
  _sprintf(pcVar5,"%s\n",DAT_a7b7bb4c);
  if (iVar6 == 0) {
    _sprintf(*(char **)(this + 0x54),"%s\n\n%s\n",*(char **)(this + 0x54),DAT_a7b7bb48);
  }
  else {
    _sprintf(*(char **)(this + 0x54),"%s%s\n\n%s\n",*(char **)(this + 0x54),iVar6,DAT_a7b7bb48);
  }
  if (bVar1) {
    _sprintf(*(char **)(this + 0x54),"%s\n",*(char **)(this + 0x54));
  }
  else {
    _sprintf(*(char **)(this + 0x54),"%s%s\n",*(char **)(this + 0x54),iVar7);
  }
  if (iVar6 != 0) {
    _free(iVar6);
  }
  if (!bVar1) {
    _free(iVar7);
  }
  return *(undefined4 *)(this + 0x54);
}

/* TGenericLinker__getShaderToProgramString @ 0x97bb935c (768 bytes) */
int TGenericLinker__getShaderToProgramString(this)
  unsigned char * this;
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int local_30 [4];
  
  iVar6 = 0;
  iVar7 = 0;
  if (*(int *)(this + 0x58) != 0) {
    _free(*(int *)(this + 0x58));
  }
  *(undefined4 *)(this + 0x58) = 0;
  iVar2 = _strlen(DAT_a7b7bb54);
  if (*(int *)(this + 0x30) == 0) {
    iVar6 = _strlen(DAT_a7b7bb58);
    iVar6 = _malloc(iVar6 + 1);
    _strcpy(iVar6,DAT_a7b7bb58);
  }
  else {
    _PPStreamGetStream(*(int *)(this + 0x30),0,local_30);
    if (local_30[0] != 0) {
      uVar3 = _malloc(local_30[0] * 8 + 0xfU & 0xfffffff0);
      _PPStreamGetStream(*(undefined4 *)(this + 0x30),uVar3,local_30);
      if (*(int *)(this + 0x80) < 4) {
        iVar6 = _glpPPShaderToProgramString(uVar3,0,0);
      }
      else {
        iVar4 = _glpPPShaderLinearize(uVar3,0xff);
        iVar6 = 0;
        if (iVar4 != 0) {
          iVar6 = _glpPPShaderToProgramString(iVar4,0,0);
          _glpFreePPShaderLinearize(iVar4);
        }
      }
      _free(uVar3);
    }
  }
  if (iVar6 != 0) {
    iVar4 = _strlen(iVar6);
    iVar2 = iVar2 + iVar4;
  }
  iVar4 = _strlen(DAT_a7b7bb50);
  iVar2 = iVar2 + iVar4;
  if (*(int *)(this + 0x34) == 0) {
    iVar7 = _strlen(DAT_a7b7bb58);
    iVar7 = _malloc(iVar7 + 1);
    _strcpy(iVar7,DAT_a7b7bb58);
  }
  else {
    _PPStreamGetStream(*(int *)(this + 0x34),0,local_30);
    if (local_30[0] != 0) {
      uVar3 = _malloc(local_30[0] * 8 + 0xfU & 0xfffffff0);
      _PPStreamGetStream(*(undefined4 *)(this + 0x34),uVar3,local_30);
      if (*(int *)(this + 0x80) < 4) {
        iVar7 = _glpPPShaderToProgramString(uVar3,0,0);
      }
      else {
        iVar4 = _glpPPShaderLinearize(uVar3,0xff);
        iVar7 = 0;
        if (iVar4 != 0) {
          iVar7 = _glpPPShaderToProgramString(iVar4,0,0);
          _glpFreePPShaderLinearize(iVar4);
        }
      }
      _free(uVar3);
    }
  }
  bVar1 = iVar7 == 0;
  if (!bVar1) {
    iVar4 = _strlen(iVar7);
    iVar2 = iVar2 + iVar4;
  }
  pcVar5 = (char *)_malloc(iVar2 + 8);
  *(char **)(this + 0x58) = pcVar5;
  _sprintf(pcVar5,"%s\n",DAT_a7b7bb54);
  if (iVar6 == 0) {
    _sprintf(*(char **)(this + 0x58),"%s\n\n",*(char **)(this + 0x58));
  }
  else {
    _sprintf(*(char **)(this + 0x58),"%s%s\n\n",*(char **)(this + 0x58),iVar6);
  }
  _sprintf(*(char **)(this + 0x58),"%s%s\n",*(char **)(this + 0x58),DAT_a7b7bb50);
  if (bVar1) {
    _sprintf(*(char **)(this + 0x58),"%s\n",*(char **)(this + 0x58));
  }
  else {
    _sprintf(*(char **)(this + 0x58),"%s%s\n",*(char **)(this + 0x58),iVar7);
  }
  if (iVar6 != 0) {
    _free(iVar6);
  }
  if (!bVar1) {
    _free(iVar7);
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
  if (param_1 == 0x1404) {
    return _glTypeNameStrings;
  }
  if (param_1 == 0x1406) {
    return DAT_a7b7bc28;
  }
  if ((param_1 + 0x74b0U & 0xffff) < 0x15) {
    return *(undefined4 *)(param_1 * 4 + -0x584a7114);
  }
  if (param_1 == 0x7ffe) {
    return DAT_a7b7bc80;
  }
  if (param_1 == 0x7fff) {
    return DAT_a7b7bc84;
  }
  return DAT_a7b7bc88;
}

/* GetShaderStringForType @ 0x97bb9748 (168 bytes) */
int GetShaderStringForType(param_1)
  int param_1;
{
  if (param_1 == 0x1404) {
    return _shaderTypeNameStrings;
  }
  if (param_1 == 0x1406) {
    return DAT_a7b7bc90;
  }
  if ((param_1 + 0x74b0U & 0xffff) < 0x15) {
    return *(undefined4 *)(param_1 * 4 + -0x584a70ac);
  }
  if (param_1 == 0x7ffe) {
    return DAT_a7b7bce8;
  }
  if (param_1 == 0x7fff) {
    return DAT_a7b7bcec;
  }
  return DAT_a7b7bcf0;
}

/* GetVec4sForType @ 0x97bb97f0 (136 bytes) */
int GetVec4sForType(param_1)
  int param_1;
{
  if (param_1 == 0x8b5a) {
    return 2;
  }
  if (param_1 < 0x8b5b) {
    if (param_1 != 0x1406) {
      if (param_1 < 0x1407) {
        if (param_1 != 0x1404) {
          return 0;
        }
      }
      else if (param_1 < 0x8b50) {
        return 0;
      }
    }
  }
  else {
    if (param_1 == 0x8b5c) {
      return 4;
    }
    if (param_1 < 0x8b5c) {
      return 3;
    }
    if (0x8b64 < param_1) {
      return 0;
    }
  }
  return 1;
}

/* GetPPStreamTypeForGLType @ 0x97bb9878 (164 bytes) */
int GetPPStreamTypeForGLType(param_1)
  int param_1;
{
  if (param_1 < 0x8b56) {
    if (param_1 < 0x8b53) {
      if (param_1 == 0x1406) {
        return 1;
      }
      if (param_1 < 0x1407) {
        if (param_1 == 0x1404) {
          return 3;
        }
      }
      else if (0x8b4f < param_1) {
        return 1;
      }
      return 0;
    }
  }
  else {
    if (param_1 < 0x8b5d) {
      if (0x8b59 < param_1) {
        return 1;
      }
      return 4;
    }
    if (0x8b64 < param_1) {
      return 0;
    }
  }
  return 3;
}

/* GetScalerWidthForType @ 0x97bb991c (260 bytes) */
int GetScalerWidthForType(param_1)
  int param_1;
{
  if (param_1 == 0x8b56) {
    return 1;
  }
  if (0x8b56 < param_1) {
    if (param_1 == 0x8b5a) {
      return 2;
    }
    if (param_1 < 0x8b5b) {
      if (param_1 != 0x8b58) {
        if (param_1 < 0x8b59) {
          return 2;
        }
        return 4;
      }
    }
    else {
      if (param_1 == 0x8b5c) {
        return 4;
      }
      if (0x8b5b < param_1) {
        if (param_1 < 0x8b65) {
          return 1;
        }
        return 0;
      }
    }
    return 3;
  }
  if (param_1 == 0x8b51) {
    return 3;
  }
  if (param_1 < 0x8b52) {
    if (param_1 == 0x1406) {
      return 1;
    }
    if (param_1 < 0x1407) {
      if (param_1 == 0x1404) {
        return 1;
      }
    }
    else if (param_1 == 0x8b50) {
      return 2;
    }
    return 0;
  }
  if (param_1 == 0x8b53) {
    return 2;
  }
  if (param_1 < 0x8b53) {
    return 4;
  }
  if (param_1 == 0x8b54) {
    return 3;
  }
  if (param_1 == 0x8b55) {
    return 4;
  }
  return 0;
}

/* getOpenGLTypeFromTType @ 0x97bb9a20 (676 bytes) */
int getOpenGLTypeFromTType(param_1)
  unsigned char * param_1;
{
  int iVar1;
  uint uVar2;
  undefined4 a1;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 uVar3;
  
  uVar3 = 0x1400;
  iVar1 = (**(code **)(*(int *)param_1 + 0x38))(param_1);
  if (iVar1 == 0) {
    uVar2 = (**(code **)(*(int *)param_1 + 0x20))(param_1);
    if (uVar2 < 0x10) {
      switch(uVar2) {
      case 1:
        iVar1 = (**(code **)(*(int *)param_1 + 0x34))(param_1,a1,in_r5,in_r6,in_r7,in_r8,uVar2 * 4);
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
  }
  else {
    uVar3 = 0x7fff;
  }
  return uVar3;
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
  ((int (*)())__ZN20AddressTempAllocatorC4Ev)(this);
  return;
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
  ((int (*)())__ZN20AddressTempAllocatorD4Ev)(this);
  return;
}

/* __ZN20AddressTempAllocatorD1Ev @ 0x97bb9d24 (8 bytes) */
int __ZN20AddressTempAllocatorD1Ev(this)
  void *this;
{
  ((int (*)())__ZN20AddressTempAllocatorD4Ev)(this);
  return;
}

/* __ZN20AddressTempAllocatorD4Ev @ 0x97bb9d2c (16 bytes) */
int __ZN20AddressTempAllocatorD4Ev(this)
  void *this;
{
  if (*(int *)this == 0) {
    return;
  }
  _free(*(int *)this);
  return;
}

/* AddressTempAllocator__getTemporary @ 0x97bb9d3c (316 bytes) */
int AddressTempAllocator__getTemporary(this)
  unsigned char * this;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
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
    iVar4 = _malloc(uVar3 * 4 + 0x40);
    iVar2 = *(int *)(this + 4);
    iVar7 = 0;
    if (iVar2 != 0) {
      iVar6 = *(int *)this;
      iVar10 = iVar2;
      do {
        iVar1 = iVar7 * 4;
        iVar7 = iVar7 + 1;
        *(undefined4 *)(iVar1 + iVar4) = *(undefined4 *)(iVar1 + iVar6);
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
    _memset(iVar2 * 4 + iVar4,0,0x40);
    if (*(int *)this != 0) {
      _free(*(int *)this);
    }
    *(int *)this = iVar4;
    uVar3 = *(int *)(this + 4) + 0x10;
    *(uint *)(this + 4) = uVar3;
    if (uVar9 < uVar3) {
      if (*(int *)(iVar8 + iVar4) != 0) {
        piVar5 = (int *)(uVar9 * 4 + iVar4);
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
  iVar4 = *(int *)this;
LAB_97bb9e58:
  *(undefined4 *)(iVar8 + iVar4) = 1;
  return uVar9;
}

/* AddressTempAllocator__releaseTemporary @ 0x97bb9e78 (20 bytes) */
int AddressTempAllocator__releaseTemporary(this, param_2)
  unsigned char * this;
  uint param_2;
{
  *(undefined4 *)(param_2 * 4 + *(int *)this) = 0;
  return;
}

/* __ZN18TemporaryAllocatorC2Ev @ 0x97bb9e8c (4 bytes) */
int __ZN18TemporaryAllocatorC2Ev(this)
  void *this;
{
  int iVar1;
  
  iVar1 = 0x19;
  do {
    *(undefined4 *)this = 0;
    *(undefined4 *)((int)this + 100) = 0;
    this = (void *)((int)this + 4);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}

