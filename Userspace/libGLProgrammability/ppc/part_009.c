#include "decls.h"

/* TGenericLinker__MergeCompilers @ 0x97bb21dc (200 bytes) */
int TGenericLinker__MergeCompilers(this, param_2)
  unsigned char * this;
  int param_2;
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
  int iVar18;
  size_t sVar19;
  int iVar20;
  char *pcVar21;
  unsigned char * pPVar22;
  size_t sVar23;
  size_t sVar24;
  unsigned char * p_Var25;
  bool bVar26;
  bool bVar27;
  uint uVar28;
  byte *pbVar29;
  bool bVar30;
  int iVar31;
  undefined4 *puVar32;
  unsigned char * this_00;
  char *pcVar33;
  int iVar34;
  void *pvVar35;
  unsigned char * pTVar36;
  unsigned char * p_Var37;
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
  iVar3 = param_2 * 4;
  pvVar15 = _malloc(*(int *)(this + iVar3 + 0x20) << 2);
  pvVar16 = _malloc(*(int *)(this + iVar3 + 0x20) << 2);
  pcVar33 = DAT_a7b7bb0c;
  iVar13 = *(int *)(this + iVar3 + 0x20);
  local_60 = 0;
  if (10000 < iVar13) {
    pvVar35 = *(void **)(this + 0x84);
                    
    __ZN13TInfoSinkBase6appendEPKc(pvVar35,"ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(pvVar35,pcVar33);
    __ZN13TInfoSinkBase6appendEPKc(pvVar35,"\n");
  }
  bVar30 = 10000 >= iVar13;
  if (bVar30) {
    uVar17 = _PPStreamCreate();
    *(undefined4 *)(this + iVar3 + 0x30) = uVar17;
    pvVar35 = operator_new(0x54);
    __ZN16ParseSymbolTableC1Ej(pvVar35,0x80);
    *(void **)(this + iVar3 + 0x28) = pvVar35;
    *(undefined4 *)((int)pvVar35 + 0xc) = *(undefined4 *)(this + iVar3 + 0x30);
    if (param_2 == 0) {
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
    pTVar36 = this + iVar3;
    iVar13 = 0;
    iVar31 = 0;
    _memset(pvVar15,0,*(int *)(pTVar36 + 0x20) << 2);
    _memset(pvVar16,0,*(int *)(pTVar36 + 0x20) << 2);
    pTVar10 = pTVar36;
    pTVar11 = pTVar36;
    pTVar12 = pTVar36;
    if (0 < *(int *)(pTVar36 + 0x20)) {
      do {
        local_54 = pTVar12;
        local_58 = pTVar11;
        local_5c = pTVar10;
        iVar14 = iVar13 * 4;
        iVar34 = **(int **)(*(int *)(iVar14 + *(int *)(pTVar36 + 0x18)) + 0x20);
        while (iVar34 != 0) {
          iVar18 = _PPStreamChunkCreateFromChunk(iVar34);
          _PPStreamChunkListAddChunk(*(undefined4 *)(*(int *)(pTVar36 + 0x30) + 0x20),iVar18);
          if (*(int *)(iVar14 + (int)pvVar15) == 0) {
            *(int *)(iVar14 + (int)pvVar15) = iVar18;
          }
          uVar28 = *(uint *)(iVar18 + 0x10);
          *(uint *)(iVar18 + 0xc) =
               (*(uint *)(iVar18 + 0xc) & 0x3ffff) + iVar31 & 0x3ffff |
               *(uint *)(iVar18 + 0xc) & 0xfffc0000;
          if ((uVar28 & 0x3ffff) != 0) {
            *(uint *)(iVar18 + 0x10) = (uVar28 & 0x3ffff) + iVar31 & 0x3ffff | uVar28 & 0xfffc0000;
          }
          if (*(int *)(iVar18 + 0x40) != 0) {
            pcVar33 = (char *)(iVar18 + 0x44);
            sVar19 = _strlen(puVar4);
            iVar20 = _strncmp(pcVar33,puVar4,sVar19);
            if (iVar20 != 0) {
              sVar19 = _strlen(puVar5);
              iVar20 = _strncmp(pcVar33,puVar5,sVar19);
              if (iVar20 != 0) {
                sVar19 = _strlen(puVar6);
                iVar20 = _strncmp(pcVar33,puVar6,sVar19);
                if (iVar20 != 0) {
                  sVar19 = _strlen(puVar7);
                  iVar20 = _strncmp(pcVar33,puVar7,sVar19);
                  if (iVar20 != 0) {
                    sVar19 = _strlen(puVar8);
                    iVar20 = _strncmp(pcVar33,puVar8,sVar19);
                    if (iVar20 != 0) {
                      sVar19 = _strlen(puVar9);
                      iVar20 = _strncmp(pcVar33,puVar9,sVar19);
                      if (iVar20 != 0) goto code_r0x97bb257c;
                    }
                  }
                }
              }
            }
            _sprintf(local_70,"%04d",iVar13);
            pcVar21 = (char *)(iVar18 + 0x44);
            pcVar33 = local_70;
            iVar18 = 4;
            do {
              cVar1 = *pcVar33;
              pcVar33 = pcVar33 + 1;
              *pcVar21 = cVar1;
              pcVar21 = pcVar21 + 1;
              iVar18 = iVar18 + -1;
            } while (iVar18 != 0);
          }
code_r0x97bb257c:
          iVar34 = *(int *)(iVar34 + 8);
          *(int *)(iVar14 + (int)pvVar16) = *(int *)(iVar14 + (int)pvVar16) + 1;
        }
        pTVar10 = local_5c;
        pTVar11 = local_54;
        for (iVar34 = **(int **)(*(int *)(iVar14 + *(int *)(pTVar36 + 0x18)) + 0x24);
            local_5c = pTVar10, local_54 = pTVar11, iVar34 != 0; iVar34 = *(int *)(iVar34 + 8)) {
          iVar18 = _PPStreamChunkCreateFromChunk(iVar34);
          _PPStreamChunkListAddChunk(*(undefined4 *)(*(int *)(pTVar36 + 0x30) + 0x24),iVar18);
          *(int *)(iVar18 + 0xc) = *(int *)(iVar18 + 0xc) + iVar31;
          if (*(int *)(iVar18 + 0x10) != 0) {
            pcVar33 = (char *)(iVar18 + 0x14);
            sVar19 = _strlen(puVar4);
            iVar20 = _strncmp(pcVar33,puVar4,sVar19);
            if (iVar20 != 0) {
              sVar19 = _strlen(puVar5);
              iVar20 = _strncmp(pcVar33,puVar5,sVar19);
              if (iVar20 != 0) {
                sVar19 = _strlen(puVar6);
                iVar20 = _strncmp(pcVar33,puVar6,sVar19);
                if (iVar20 != 0) {
                  sVar19 = _strlen(puVar7);
                  iVar20 = _strncmp(pcVar33,puVar7,sVar19);
                  if (iVar20 != 0) {
                    sVar19 = _strlen(puVar8);
                    iVar20 = _strncmp(pcVar33,puVar8,sVar19);
                    if (iVar20 != 0) {
                      sVar19 = _strlen(puVar9);
                      iVar20 = _strncmp(pcVar33,puVar9,sVar19);
                      if (iVar20 != 0) goto code_r0x97bb26e0;
                    }
                  }
                }
              }
            }
            _sprintf(local_70,"%04d",iVar13);
            pcVar21 = (char *)(iVar18 + 0x14);
            pcVar33 = local_70;
            iVar18 = 4;
            do {
              cVar1 = *pcVar33;
              pcVar33 = pcVar33 + 1;
              *pcVar21 = cVar1;
              pcVar21 = pcVar21 + 1;
              iVar18 = iVar18 + -1;
            } while (iVar18 != 0);
          }
code_r0x97bb26e0:
          pTVar10 = local_5c;
          pTVar11 = local_54;
        }
        iVar18 = 0;
        this_00 = *(unsigned char **)(*(int *)(iVar14 + *(int *)(pTVar36 + 8)) + 0x6c);
        iVar34 = *(int *)(this_00 + 4);
        if (0 < iVar34) {
          do {
            iVar20 = 0;
            if (0 < *(int *)(*(int *)(pTVar10 + 0x38) + 4)) {
              do {
                pcVar33 = (char *)FunctionTable__getFunctionName
                                            (*(unsigned char **)(pTVar11 + 0x38),iVar20);
                pcVar21 = (char *)FunctionTable__getFunctionName(this_00,iVar18);
                iVar34 = _strcmp(pcVar33,pcVar21);
                if (iVar34 == 0) {
                  iVar34 = FunctionTable__getFirstOp(*(unsigned char **)(pTVar11 + 0x38),iVar20);
                  FunctionTable__setFirstOp
                            (*(unsigned char **)(pTVar11 + 0x38),iVar20,iVar34 + iVar31);
                  iVar34 = FunctionTable__getLastOp(*(unsigned char **)(pTVar11 + 0x38),iVar20);
                  FunctionTable__setLastOp
                            (*(unsigned char **)(pTVar11 + 0x38),iVar20,iVar34 + iVar31);
                }
                iVar20 = iVar20 + 1;
              } while (iVar20 < *(int *)(*(int *)(pTVar11 + 0x38) + 4));
              iVar34 = *(int *)(this_00 + 4);
            }
            iVar18 = iVar18 + 1;
          } while (iVar18 < iVar34);
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
    pcVar33 = UNK_a7b7bb10;
    if (local_60 == 0) {
      pvVar35 = *(void **)(this + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(pvVar35,"ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(pvVar35,pcVar33);
      bVar30 = false;
      __ZN13TInfoSinkBase6appendEPKc(pvVar35,"\n");
    }
  }
  if (bVar30) {
    iVar13 = 1;
    do {
      iVar31 = 0;
      if (0 < *(int *)(this + iVar3 + 0x20)) {
        do {
          iVar14 = iVar31 * 4;
          for (pPVar22 = (unsigned char *)
                         ParseSymbolTable__NextSymbol
                                   (*(unsigned char **)(iVar14 + *(int *)(this + iVar3 + 0x10)),
                                    (unsigned char *)0x0); pPVar22 != (unsigned char *)0x0;
              pPVar22 = (unsigned char *)
                        ParseSymbolTable__NextSymbol
                                  (*(unsigned char **)(iVar14 + *(int *)(this + iVar3 + 0x10)),
                                   pPVar22)) {
            if (iVar13 == *(int *)(pPVar22 + 0x54)) {
              puVar32 = (undefined4 *)0x0;
              if (*(int *)(pPVar22 + 0x38) == 0) {
                bVar26 = true;
code_r0x97bb2ab4:
                if (bVar26) goto code_r0x97bb2ab8;
              }
              else {
                puVar32 = (undefined4 *)
                          ParseSymbolTable__FindGlobalSymbolByName
                                    (*(unsigned char **)(this + iVar3 + 0x28),
                                     *(char **)(pPVar22 + 0x14));
                bVar26 = puVar32 == (undefined4 *)0x0;
                if (!bVar26) {
                  if (*(short *)(puVar32 + 0xb) == *(short *)(pPVar22 + 0x2c)) {
                    if (*(short *)((int)puVar32 + 0x2e) == *(short *)(pPVar22 + 0x2e))
                    goto code_r0x97bb2ab4;
                    pcVar21 = (char *)puVar32[5];
                    sVar19 = _strlen(UNK_a7b7bb18);
                    sVar23 = _strlen(pcVar21);
                    sVar24 = _strlen((char *)(&_shaderString)[param_2]);
                    pcVar33 = _malloc(sVar19 + sVar23 + sVar24 + 1);
                    _sprintf(pcVar33,UNK_a7b7bb18,pcVar21,(&_shaderString)[param_2]);
                    pvVar35 = *(void **)(this + 0x84);
                    
                  }
                  else {
                    pcVar21 = (char *)puVar32[5];
                    sVar19 = _strlen(UNK_a7b7bb14);
                    sVar23 = _strlen(pcVar21);
                    sVar24 = _strlen((char *)(&_shaderString)[param_2]);
                    pcVar33 = _malloc(sVar19 + sVar23 + sVar24 + 1);
                    _sprintf(pcVar33,UNK_a7b7bb14,pcVar21,(&_shaderString)[param_2]);
                    pvVar35 = *(void **)(this + 0x84);
                    
                  }
                  __ZN13TInfoSinkBase6appendEPKc(pvVar35,"ERROR: ");
                  __ZN13TInfoSinkBase6appendEPKc(pvVar35,pcVar33);
                  __ZN13TInfoSinkBase6appendEPKc(pvVar35,"\n");
                  _free(pcVar33);
                  bVar30 = false;
                  goto code_r0x97bb2ab4;
                }
code_r0x97bb2ab8:
                bVar26 = false;
                bVar27 = false;
                if ((iVar13 != 0) && (pbVar29 = *(byte **)pPVar22, pbVar29 != (byte *)0x0)) {
                  bVar2 = *pbVar29;
                  if (bVar2 != 2) {
                    if (bVar2 < 3) {
                      if ((bVar2 == 0) &&
                         (iVar34 = **(int **)(*(int *)(iVar14 + *(int *)(this + iVar3 + 0x18)) + 8),
                         iVar34 != 0)) {
                        bVar26 = false;
                        bVar27 = false;
                        do {
                          if (*(short *)(pbVar29 + 0x12) == *(short *)(iVar34 + 0xe)) {
                            bVar26 = true;
                          }
                          if (*(short *)(pbVar29 + 0x12) == *(short *)(iVar34 + 0x12)) {
                            bVar27 = true;
                          }
                          iVar34 = *(int *)(iVar34 + 8);
                        } while (iVar34 != 0);
                      }
                    }
                    else if ((bVar2 == 3) &&
                            (iVar34 = **(int **)(*(int *)(iVar14 + *(int *)(this + iVar3 + 0x18)) +
                                                0x14), iVar34 != 0)) {
                      bVar26 = false;
                      bVar27 = false;
                      do {
                        if (*(short *)(pbVar29 + 0x12) == *(short *)(iVar34 + 0xe)) {
                          bVar26 = true;
                        }
                        if (*(short *)(pbVar29 + 0x12) == *(short *)(iVar34 + 0x12)) {
                          bVar27 = true;
                        }
                        iVar34 = *(int *)(iVar34 + 8);
                      } while (iVar34 != 0);
                    }
                  }
                }
                puVar32 = (undefined4 *)
                          ParseSymbolTable__AddFromExternalSymbol
                                    (*(unsigned char **)(this + iVar3 + 0x28),pPVar22,bVar26,
                                     bVar27);
              }
              if ((bVar30 != true) || (puVar32 == (undefined4 *)0x0)) {
                if ((bVar30 == true) && (puVar32 == (undefined4 *)0x0)) {
                  pcVar21 = *(char **)(pPVar22 + 0x14);
                  sVar19 = _strlen(DAT_a7b7bbc0);
                  sVar23 = _strlen(pcVar21);
                  pcVar33 = _malloc(sVar19 + sVar23 + 1);
                  _sprintf(pcVar33,UNK_a7b7bb90,pcVar21);
                  pvVar35 = *(void **)(this + 0x84);
                    
                  __ZN13TInfoSinkBase6appendEPKc(pvVar35,"ERROR: ");
                  __ZN13TInfoSinkBase6appendEPKc(pvVar35,pcVar33);
                  __ZN13TInfoSinkBase6appendEPKc(pvVar35,"\n");
                  _free(pcVar33);
                  bVar30 = false;
                }
              }
              else {
                iVar34 = TGenericLinker__FindChunkDelta(this,*(unsigned char **)pPVar22,(unsigned char *)*puVar32)
                ;
                if (iVar34 != 0) {
                  iVar18 = ((int (*)())GetVec4sForType)(*(ushort *)(pPVar22 + 0x2c));
                  UpdateOperations(*(unsigned char **)(iVar14 + (int)pvVar15),
                                   (unsigned char *)
                                   **(undefined4 **)
                                     (*(int *)(iVar14 + *(int *)(this + iVar3 + 0x18)) + 0x20),
                                   *(int *)(iVar14 + (int)pvVar16),*(unsigned char **)pPVar22,
                                   iVar18,iVar34);
                }
              }
            }
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
          for (p_Var37 = (unsigned char *)
                         **(undefined4 **)(*(int *)(iVar31 + *(int *)(this + iVar3 + 0x18)) + 0x10);
              p_Var37 != (unsigned char *)0x0; p_Var37 = *(unsigned char **)(p_Var37 + 8)) {
            uVar28 = *(uint *)(p_Var37 + 0xc);
            if ((uVar28 & 0x1f0000) == 0x110000) {
              iVar14 = *(int *)(*(int *)(this + iVar3 + 0x28) + 0x24);
              *(int *)(*(int *)(this + iVar3 + 0x28) + 0x24) = iVar14 + 1;
              p_Var25 = (unsigned char *)_PPStreamChunkCreateFromChunk(p_Var37);
              _PPStreamChunkListAddChunk
                        (*(undefined4 *)(*(int *)(this + iVar3 + 0x30) + 0x10),p_Var25);
              *(short *)(p_Var25 + 0x12) = (short)iVar14;
              iVar14 = TGenericLinker__FindChunkDelta(this,p_Var37,p_Var25);
              UpdateOperations(*(unsigned char **)(iVar31 + (int)pvVar15),
                               (unsigned char *)
                               **(undefined4 **)
                                 (*(int *)(iVar31 + *(int *)(this + iVar3 + 0x18)) + 0x20),
                               *(int *)(iVar31 + (int)pvVar16),p_Var37,1,iVar14);
              *(undefined2 *)(p_Var25 + 0xe) =
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
          for (iVar34 = **(int **)(*(int *)(iVar31 * 4 + *(int *)(this + iVar3 + 0x18)) + 0xc);
              iVar34 != 0; iVar34 = *(int *)(iVar34 + 8)) {
            iVar14 = iVar14 + 1;
            if (iVar13 < iVar14) {
              uVar17 = _PPStreamChunkCreateFromChunk(iVar34);
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
                if (*(char *)(iVar14 + 0xf) == *(char *)(iVar31 + 0xf)) goto code_r0x97bb2f70;
                iVar14 = *(int *)(iVar14 + 8);
              } while (iVar14 != 0);
            }
            uVar17 = _PPStreamChunkCreateFromChunk(iVar31);
            _PPStreamChunkListAddChunk(*(undefined4 *)(*(int *)(this + iVar3 + 0x30) + 0x30),uVar17)
            ;
code_r0x97bb2f70: ;
          }
          iVar13 = iVar13 + 1;
        } while (iVar13 < *(int *)(this + iVar3 + 0x20));
      }
    }
  }
  if (bVar30 == false) {
    if (*(int *)(this + iVar3 + 0x30) != 0) {
      _PPStreamFree(*(int *)(this + iVar3 + 0x30));
    }
    pvVar15 = *(void **)(this + iVar3 + 0x28);
    *(undefined4 *)(this + iVar3 + 0x30) = 0;
    if (pvVar15 != (void *)0x0) {
      __ZN16ParseSymbolTableD1Ev(pvVar15);
      __ZdlPv(pvVar15);
    }
    *(undefined4 *)(this + iVar3 + 0x28) = 0;
  }
  return bVar30;
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
    ParseSymbolTable__ChangeChunk(param_3,p_Var5,p_Var3,true);
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
    ParseSymbolTable__ChangeChunk(param_3,p_Var5,p_Var3,true);
  }
  for (iVar6 = **(int **)(param_2 + 0x14); iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)) {
    uVar4 = _PPStreamChunkCreateFromChunk(iVar6);
    _PPStreamChunkListAddChunk(puVar2[5],uVar4);
  }
  for (p_Var5 = (unsigned char *)**(undefined4 **)(param_2 + 0x18); p_Var5 != (unsigned char *)0x0
      ; p_Var5 = *(unsigned char **)(p_Var5 + 8)) {
    p_Var3 = (unsigned char *)_PPStreamChunkCreateFromChunk(p_Var5);
    _PPStreamChunkListAddChunk(puVar2[6],p_Var3);
    ParseSymbolTable__ChangeChunk(param_3,p_Var5,p_Var3,true);
  }
  for (p_Var5 = (unsigned char *)**(undefined4 **)(param_2 + 0x1c); p_Var5 != (unsigned char *)0x0
      ; p_Var5 = *(unsigned char **)(p_Var5 + 8)) {
    p_Var3 = (unsigned char *)_PPStreamChunkCreateFromChunk(p_Var5);
    _PPStreamChunkListAddChunk(puVar2[7],p_Var3);
    ParseSymbolTable__ChangeChunk(param_3,p_Var5,p_Var3,true);
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
  void *pvVar15;
  int iVar16;
  
  iVar12 = 0;
code_r0x97bb33e4:
  iVar2 = iVar12 * 4;
code_r0x97bb33e8:
  bVar1 = false;
  iVar13 = 0;
  if ((*(int *)(this + iVar2 + 0x38) != 0) && (0 < *(int *)(*(int *)(this + iVar2 + 0x38) + 4))) {
code_r0x97bb3410:
    pcVar3 = (char *)FunctionTable__getFunctionName(*(unsigned char **)(this + iVar2 + 0x38),iVar13)
    ;
    iVar4 = _memcmp(pcVar3,"main(",6);
    iVar16 = iVar13;
    if (iVar4 != 0) {
      for (iVar4 = **(int **)(*(int *)(this + iVar2 + 0x30) + 0x20); iVar4 != 0;
          iVar4 = *(int *)(iVar4 + 8)) {
        if ((((*(uint *)(iVar4 + 0xc) & 0x3fc0000) == 0x1300000) && (*(int *)(iVar4 + 0x40) != 0))
           && (iVar5 = _strcmp((char *)(iVar4 + 0x44),pcVar3), iVar5 == 0)) goto LAB_97bb37a8;
      }
      for (iVar16 = **(int **)(*(int *)(this + iVar2 + 0x30) + 0x20); iVar16 != 0;
          iVar16 = *(int *)(iVar16 + 8)) {
        uVar14 = *(uint *)(iVar16 + 0xc);
        uVar6 = FunctionTable__getFirstOp(*(unsigned char **)(this + iVar2 + 0x38),iVar13);
        if ((uVar14 & 0x3ffff) == uVar6) {
          bVar1 = false;
          goto LAB_97bb361c;
        }
      }
      sVar7 = _strlen(DAT_a7b7baec);
      sVar8 = _strlen((char *)(&_shaderString)[iVar12]);
      sVar9 = _strlen(pcVar3);
      pcVar10 = _malloc(sVar7 + sVar8 + sVar9 + 9);
      uVar11 = FunctionTable__getFirstOp(*(unsigned char **)(this + iVar2 + 0x38),iVar13);
      _sprintf(pcVar10,DAT_a7b7baec,pcVar3,(&_shaderString)[iVar12],uVar11);
      pvVar15 = *(void **)(this + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(pvVar15,"INTERNAL ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(pvVar15,pcVar10);
      __ZN13TInfoSinkBase6appendEPKc(pvVar15,"\n");
      _free(pcVar10);
      goto code_r0x97bb3790;
    }
    goto LAB_97bb37a8;
  }
  goto LAB_97bb37d4;
  while( true ) {
    if ((*(uint *)(iVar16 + 0xc) & 0x3ffff) == 0) {
      sVar7 = _strlen(DAT_a7b7baf0);
      sVar8 = _strlen((char *)(&_shaderString)[iVar12]);
      sVar9 = _strlen(pcVar3);
      pcVar10 = _malloc(sVar7 + sVar8 + sVar9 + 1);
      _sprintf(pcVar10,DAT_a7b7baf0,pcVar3,(&_shaderString)[iVar12]);
      pvVar15 = *(void **)(this + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(pvVar15,"INTERNAL ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(pvVar15,pcVar10);
      __ZN13TInfoSinkBase6appendEPKc(pvVar15,"\n");
      _free(pcVar10);
    }
    else {
      _PPStreamRemoveLabelsAtOperationIndex
                (*(undefined4 *)(this + iVar2 + 0x30),*(uint *)(iVar16 + 0xc) & 0x3ffff);
      iVar4 = *(int *)(iVar16 + 8);
      bVar1 = iVar4 == 0;
      if (!bVar1) {
        *(uint *)(iVar4 + 0xc) =
             (*(uint *)(iVar16 + 0xc) >> 0x1a & 7) << 0x1a | *(uint *)(iVar4 + 0xc) & 0xe3ffffff;
      }
      _PPStreamChunkListRemoveChunk(*(undefined4 *)(*(int *)(this + iVar2 + 0x30) + 0x20),iVar16);
      iVar16 = iVar4;
    }
    if (bVar1) break;
LAB_97bb361c:
    uVar14 = *(uint *)(iVar16 + 0xc);
    uVar6 = FunctionTable__getLastOp(*(unsigned char **)(this + iVar2 + 0x38),iVar13);
    if ((uVar14 & 0x3ffff) == uVar6) {
      if (!bVar1) {
        iVar4 = *(int *)(iVar16 + 8);
        if (iVar4 != 0) {
          *(uint *)(iVar4 + 0xc) =
               (*(uint *)(iVar16 + 0xc) >> 0x1a & 7) << 0x1a | *(uint *)(iVar4 + 0xc) & 0xe3ffffff;
        }
        uVar14 = *(uint *)(iVar16 + 0xc);
        uVar6 = FunctionTable__getLastOp(*(unsigned char **)(this + iVar2 + 0x38),iVar13);
        if ((uVar14 & 0x3ffff) == uVar6) {
          _PPStreamChunkListRemoveChunk
                    (*(undefined4 *)(*(int *)(this + iVar2 + 0x30) + 0x20),iVar16);
        }
      }
      break;
    }
  }
code_r0x97bb3790:
  iVar16 = iVar13 + -1;
  bVar1 = true;
  FunctionTable__removeFunction(*(unsigned char **)(this + iVar2 + 0x38),iVar13);
LAB_97bb37a8:
  iVar13 = iVar16 + 1;
  if ((*(int *)(this + iVar2 + 0x38) == 0) ||
     (*(int *)(*(int *)(this + iVar2 + 0x38) + 4) <= iVar13)) goto code_r0x97bb37cc;
  goto code_r0x97bb3410;
code_r0x97bb37cc:
  if (!bVar1) goto LAB_97bb37d4;
  goto code_r0x97bb33e8;
LAB_97bb37d4:
  iVar12 = iVar12 + 1;
  if (1 < iVar12) {
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
            __ZN11ParseSymbolD1Ev(this_00);
            __ZdlPv(this_00);
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
  size_t sVar5;
  size_t sVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
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
        pcVar9 = *(char **)(pPVar2 + 0x14);
        if (*(unsigned char **)(this + 0x2c) == (unsigned char *)0x0) {
          sVar5 = _strlen(DAT_a7b7bae0);
          sVar6 = _strlen(pcVar9);
          pcVar7 = _malloc(sVar5 + sVar6 + 1);
          bVar1 = true;
          pcVar8 = DAT_a7b7bae0;
        }
        else {
          iVar4 = ParseSymbolTable__FindGlobalSymbolByName
                            (*(unsigned char **)(this + 0x2c),pcVar9);
          bVar1 = iVar4 == 0;
          if (!bVar1) goto joined_r0x97bb3b94;
          sVar5 = _strlen(DAT_a7b7bad8);
          sVar6 = _strlen(pcVar9);
          pcVar7 = _malloc(sVar5 + sVar6 + 1);
          pcVar8 = DAT_a7b7bad8;
        }
        _sprintf(pcVar7,pcVar8,pcVar9);
        if (bVar1) {
          this_00 = *(void **)(this + 0x84);
                    
          __ZN13TInfoSinkBase6appendEPKc(this_00,"WARNING: ");
          __ZN13TInfoSinkBase6appendEPKc(this_00,pcVar7);
          __ZN13TInfoSinkBase6appendEPKc(this_00,"\n");
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
  undefined4 uVar4;
  void *pvVar5;
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
            uVar4 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(*(int *)(pTVar10 + 0x30) + 4));
            local_9c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_9c) + 0)),(short)uVar4 + 1);
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
                pvVar5 = (void *)FunctionTable__getFunctionName
                                           (*(unsigned char **)(pTVar10 + 0x38),uVar12);
                iVar3 = _memcmp(pvVar5,"main(",6);
                if (iVar3 == 0) {
                  uVar6 = FunctionTable__getLastOp(*(unsigned char **)(pTVar10 + 0x38),uVar12);
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

/* TGenericLinker__OptimizeFunctionIO @ 0x97bb419c (696 bytes) */
int TGenericLinker__OptimizeFunctionIO(this)
  unsigned char * this;
{
  bool bVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  size_t sVar5;
  char *pcVar6;
  unsigned char * pPVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined4 uVar11;
  size_t sVar12;
  size_t sVar13;
  char *pcVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  unsigned char * p_Var19;
  void *this_00;
  unsigned char * p_Var20;
  int iVar21;
  int local_70;
  int local_6c;
  uint local_60;
  int local_5c;
  
  iVar15 = 0;
  do {
    iVar2 = iVar15 * 4;
    iVar21 = 0;
    if ((*(int *)(this + iVar2 + 0x38) != 0) && (0 < *(int *)(*(int *)(this + iVar2 + 0x38) + 4))) {
      do {
        iVar16 = 0;
        pcVar3 = (char *)FunctionTable__getFunctionName
                                   (*(unsigned char **)(this + iVar2 + 0x38),iVar21);
        iVar4 = _memcmp(pcVar3,"main(",6);
        if (iVar4 != 0) {
          for (; iVar4 = FunctionTable__getNumParams
                                   (*(unsigned char **)(this + iVar2 + 0x38),iVar21), iVar16 < iVar4
              ; iVar16 = iVar16 + 1) {
            sVar5 = _strlen(pcVar3);
            pcVar6 = _malloc(sVar5 + 9);
            _sprintf(pcVar6,"%s_%i",pcVar3,iVar16);
            for (pPVar7 = (unsigned char *)
                          ParseSymbolTable__FindNextParamSymbolByName
                                    (*(unsigned char **)(this + iVar2 + 0x28),(unsigned char *)0x0,
                                     pcVar6); pPVar7 != (unsigned char *)0x0;
                pPVar7 = (unsigned char *)
                         ParseSymbolTable__FindNextParamSymbolByName
                                   (*(unsigned char **)(this + iVar2 + 0x28),pPVar7,pcVar6)) {
              uVar17 = 0;
              uVar8 = ((int (*)())GetVec4sForType)(*(ushort *)(pPVar7 + 0x2c));
              iVar4 = *(int *)pPVar7;
              if (uVar8 != 0) {
                do {
                  local_60 = 0;
                  local_5c = 0;
                  local_70 = 0;
                  local_6c = 0;
                  p_Var20 = (unsigned char *)**(int **)(*(int *)(this + iVar2 + 0x30) + 0x20);
                  iVar9 = FunctionTable__getEmpty(*(unsigned char **)(this + iVar2 + 0x38),iVar21);
                  if (iVar9 == 0) {
                    for (; bVar1 = p_Var20 == (unsigned char *)0x0, !bVar1;
                        p_Var20 = *(unsigned char **)(p_Var20 + 8)) {
                      uVar18 = *(uint *)(p_Var20 + 0xc);
                      uVar10 = FunctionTable__getFirstOp
                                         (*(unsigned char **)(this + iVar2 + 0x38),iVar21);
                      if ((uVar18 & 0x3ffff) == uVar10) goto LAB_97bb43a0;
                    }
                    sVar5 = _strlen(DAT_a7b7baec);
                    sVar12 = _strlen((char *)(&_shaderString)[iVar15]);
                    sVar13 = _strlen(pcVar3);
                    pcVar14 = _malloc(sVar5 + sVar12 + sVar13 + 9);
                    uVar11 = FunctionTable__getFirstOp
                                       (*(unsigned char **)(this + iVar2 + 0x38),iVar21);
                    _sprintf(pcVar14,DAT_a7b7baec,pcVar3,(&_shaderString)[iVar15],uVar11);
                    this_00 = *(void **)(this + 0x84);
                    
                    __ZN13TInfoSinkBase6appendEPKc(this_00,"INTERNAL ERROR: ");
                    __ZN13TInfoSinkBase6appendEPKc(this_00,pcVar14);
                    __ZN13TInfoSinkBase6appendEPKc(this_00,"\n");
                    _free(pcVar14);
                  }
LAB_97bb44d0:
                  p_Var20 = (unsigned char *)
                            **(undefined4 **)(*(int *)(this + iVar2 + 0x30) + 0x20);
joined_r0x97bb44e4:
                  while (p_Var19 = p_Var20, p_Var19 != (unsigned char *)0x0) {
                    p_Var20 = *(unsigned char **)(p_Var19 + 8);
                    if ((*(uint *)(p_Var19 + 0xc) & 0x3fc0000) != 0) goto code_r0x97bb456c;
                    if (((*(uint *)(p_Var19 + 0x1c) & 0x3800000) == 0x800000) &&
                       ((uint)*(ushort *)(p_Var19 + 0x22) == *(ushort *)(iVar4 + 0x12) + uVar17))
                    goto code_r0x97bb4598;
                    if (((*(uint *)(p_Var19 + 0x14) & 0xe0000) == 0x20000) &&
                       ((uint)*(ushort *)(p_Var19 + 0x1a) == *(ushort *)(iVar4 + 0x12) + uVar17)) {
                      if (local_70 == 0 && local_6c == 0) goto code_r0x97bb45b4;
                      *(int *)(p_Var19 + 0x18) = local_6c;
                      *(int *)(p_Var19 + 0x14) = local_70;
                    }
                  }
                  uVar17 = uVar17 + 1;
                } while (uVar17 < uVar8);
              }
            }
            _free(pcVar6);
          }
          p_Var20 = (unsigned char *)**(undefined4 **)(*(int *)(this + iVar2 + 0x30) + 0x20);
          while (p_Var19 = p_Var20, p_Var19 != (unsigned char *)0x0) {
            p_Var20 = *(unsigned char **)(p_Var19 + 8);
            iVar4 = FunctionTable__getEmpty(*(unsigned char **)(this + iVar2 + 0x38),iVar21);
            if ((((iVar4 != 0) && ((*(uint *)(p_Var19 + 0xc) & 0x3fc0000) == 0x1300000)) &&
                (*(int *)(p_Var19 + 0x40) != 0)) &&
               (iVar4 = _strcmp((char *)(p_Var19 + 0x44),pcVar3), iVar4 == 0)) {
              FunctionTable__updateForRemovingChunk
                        (*(unsigned char **)(this + iVar2 + 0x38),p_Var19);
              _PPStreamRemoveOperation(*(undefined4 *)(this + iVar2 + 0x30),p_Var19);
            }
          }
        }
        iVar21 = iVar21 + 1;
      } while ((*(int *)(this + iVar2 + 0x38) != 0) &&
              (iVar21 < *(int *)(*(int *)(this + iVar2 + 0x38) + 4)));
    }
    iVar15 = iVar15 + 1;
    if (1 < iVar15) {
      return;
    }
  } while( true );
LAB_97bb43a0:
  if (((bVar1) ||
      (uVar18 = *(uint *)(p_Var20 + 0xc),
      uVar10 = FunctionTable__getLastOp(*(unsigned char **)(this + iVar2 + 0x38),iVar21),
      uVar10 < (uVar18 & 0x3ffff))) || ((*(uint *)(p_Var20 + 0xc) & 0x3ffff) == 0))
  goto LAB_97bb44d0;
  p_Var19 = *(unsigned char **)(p_Var20 + 8);
  if ((*(uint *)(p_Var20 + 0xc) & 0x3fc0000) == 0) {
    uVar10 = *(uint *)(p_Var20 + 0x1c);
    if (((uVar10 & 0x3800000) == 0x800000) &&
       ((uint)*(ushort *)(p_Var20 + 0x22) == *(ushort *)(iVar4 + 0x12) + uVar17)) {
      local_6c = *(int *)(p_Var20 + 0x18);
      local_70 = *(int *)(p_Var20 + 0x14);
      FunctionTable__updateForRemovingChunk(*(unsigned char **)(this + iVar2 + 0x38),p_Var20);
      uVar11 = *(undefined4 *)(this + iVar2 + 0x30);
    }
    else {
      if (((*(uint *)(p_Var20 + 0x14) & 0xe0000) != 0x20000) ||
         ((uint)*(ushort *)(p_Var20 + 0x1a) != *(ushort *)(iVar4 + 0x12) + uVar17))
      goto LAB_97bb4398;
      local_5c = *(int *)(p_Var20 + 0x20);
      FunctionTable__updateForRemovingChunk(*(unsigned char **)(this + iVar2 + 0x38),p_Var20);
      uVar11 = *(undefined4 *)(this + iVar2 + 0x30);
      local_60 = uVar10;
    }
    _PPStreamRemoveOperation(uVar11,p_Var20);
  }
LAB_97bb4398:
  bVar1 = p_Var19 == (unsigned char *)0x0;
  p_Var20 = p_Var19;
  goto LAB_97bb43a0;
code_r0x97bb456c:
  if ((((*(uint *)(p_Var19 + 0xc) & 0x3fc0000) == 0x1b40000) &&
      ((*(uint *)(p_Var19 + 0x1c) & 0x3800000) == 0x800000)) &&
     ((uint)*(ushort *)(p_Var19 + 0x22) == *(ushort *)(iVar4 + 0x12) + uVar17)) {
code_r0x97bb4598:
    if (local_60 == 0 && local_5c == 0) {
code_r0x97bb45b4:
      FunctionTable__updateForRemovingChunk(*(unsigned char **)(this + iVar2 + 0x38),p_Var19);
      _PPStreamRemoveOperation(*(undefined4 *)(this + iVar2 + 0x30),p_Var19);
    }
    else {
      *(int *)(p_Var19 + 0x20) = local_5c;
      *(uint *)(p_Var19 + 0x1c) = local_60;
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
    if ((iVar2 == 0) ||
       (iVar2 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4)), iVar2 == 0))
    {
      sVar5 = _strlen((char *)*puVar9);
      sVar4 = sVar4 + sVar5;
    }
    else {
      sVar5 = _strlen((char *)puVar9[-3]);
      sVar4 = sVar4 + sVar5;
      for (iVar2 = 0; iVar6 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4)),
          iVar2 < iVar6; iVar2 = iVar2 + 1) {
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
    if ((iVar3 == 0) ||
       (iVar3 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4)), iVar3 == 0))
    {
      _sprintf(pcVar7,(char *)*puVar9,pcVar7);
    }
    else {
      _sprintf(pcVar7,(char *)puVar9[-3],pcVar7);
      for (iVar3 = 0; iVar8 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4)),
          iVar3 < iVar8; iVar3 = iVar3 + 1) {
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
  
  pcVar1 = (char *)BindingTable__GetString(*(unsigned char **)(this + 4),3);
  if (*(int *)(this + 0x74) < 0) {
    sVar2 = _strlen(DAT_a7b7bb44);
    sVar3 = _strlen(pcVar1);
    pcVar4 = _malloc(sVar2 + sVar3 + 0x29);
    *pcVar4 = '\0';
    uVar5 = BindingTable__GetNumActiveAttributeBindings(*(unsigned char **)(this + 4));
    uVar6 = BindingTable__GetSizeActiveAttributes(*(unsigned char **)(this + 4));
    uVar7 = BindingTable__GetSizeActiveUserAttributes(*(unsigned char **)(this + 4));
    uVar8 = BindingTable__GetNumActiveUniformBindings(*(unsigned char **)(this + 4));
    uVar9 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4));
    _sprintf(pcVar4,DAT_a7b7bb44,uVar5,uVar6,uVar7,uVar8,uVar9,pcVar1);
  }
  else {
    sVar2 = _strlen(DAT_a7b7bb40);
    sVar3 = _strlen(pcVar1);
    pcVar4 = _malloc(sVar2 + sVar3 + 0x29);
    *pcVar4 = '\0';
    uVar5 = BindingTable__GetNumActiveAttributeBindings(*(unsigned char **)(this + 4));
    uVar6 = BindingTable__GetSizeActiveAttributes(*(unsigned char **)(this + 4));
    uVar7 = BindingTable__GetSizeActiveUserAttributes(*(unsigned char **)(this + 4));
    uVar8 = BindingTable__GetNumActiveUniformBindings(*(unsigned char **)(this + 4));
    uVar9 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4));
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
  int param_2;
  int param_3;
  undefined4 param_4;
{
  unsigned char * this;
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  size_t sVar4;
  char *pcVar5;
  undefined2 in_register_00000010;
  undefined3 in_register_00000014;
  void *pvVar6;
  
  this = operator_new(0x38);
  __ZN7BindingC1Ev(this);
  pcVar2 = DAT_a7b7bb84;
  if (this == (unsigned char *)0x0) {
    pvVar6 = *(void **)(param_1 + 0x84);
                    
    __ZN13TInfoSinkBase6appendEPKc(pvVar6,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(pvVar6,pcVar2);
    __ZN13TInfoSinkBase6appendEPKc(pvVar6,"\n");
  }
  else {
    Binding__SetName(this,(char *)CONCAT22(in_register_00000010,param_2));
    iVar1 = BindingTable__FindAttribBinding(*(unsigned char **)(param_1 + 4),this);
    if (iVar1 == 0) {
      Binding__SetClientRequest(this,false);
      Binding__SetOpenGLType(this,(ushort)CONCAT31(in_register_00000014,param_3));
      Binding__SetDecSize(this,1);
      Binding__SetActualSize(this,1);
      Binding__SetBuiltIn(this,(*(unsigned char *)((unsigned char *)&(param_4) + 3)));
      iVar1 = BindingTable__InsertAttribBinding(*(unsigned char **)(param_1 + 4),this);
      if (iVar1 != 0) {
        return iVar1;
      }
      pcVar2 = (char *)BindingTable__GetAttribBindingNameByLocation
                                 (*(unsigned char **)(param_1 + 4),0);
      sVar3 = _strlen(_linkErrorString);
      sVar4 = _strlen(pcVar2);
      pcVar5 = _malloc(sVar3 + sVar4 + 1);
      _sprintf(pcVar5,_linkErrorString,pcVar2);
      pvVar6 = *(void **)(param_1 + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(pvVar6,"ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(pvVar6,pcVar5);
      __ZN13TInfoSinkBase6appendEPKc(pvVar6,"\n");
      _free(pcVar5);
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
  size_t sVar3;
  size_t sVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  void *pvVar8;
  
  if (*(int *)(this + 0x28) == 0) {
    for (pBVar1 = (unsigned char *)
                  BindingTable__NextAttribRequestBinding
                            (*(unsigned char **)(this + 4),(unsigned char *)0x0); pBVar1 != (unsigned char *)0x0;
        pBVar1 = (unsigned char *)
                 BindingTable__NextAttribRequestBinding(*(unsigned char **)(this + 4),pBVar1)) {
      pcVar7 = *(char **)(pBVar1 + 8);
      sVar3 = _strlen(UNK_a7b7bac8);
      sVar4 = _strlen(pcVar7);
      pcVar5 = _malloc(sVar3 + sVar4 + 1);
      _sprintf(pcVar5,UNK_a7b7bac8,pcVar7);
      pvVar8 = *(void **)(this + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(pvVar8,"WARNING: ");
      __ZN13TInfoSinkBase6appendEPKc(pvVar8,pcVar5);
      __ZN13TInfoSinkBase6appendEPKc(pvVar8,"\n");
      _free(pcVar5);
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
        pcVar7 = *(char **)(pBVar1 + 8);
        sVar3 = _strlen(UNK_a7b7bac4);
        sVar4 = _strlen(pcVar7);
        pcVar5 = _malloc(sVar3 + sVar4 + 1);
        _sprintf(pcVar5,UNK_a7b7bac4,pcVar7);
        pvVar8 = *(void **)(this + 0x84);
                    
        __ZN13TInfoSinkBase6appendEPKc(pvVar8,"WARNING: ");
        __ZN13TInfoSinkBase6appendEPKc(pvVar8,pcVar5);
        __ZN13TInfoSinkBase6appendEPKc(pvVar8,"\n");
        _free(pcVar5);
      }
      else {
        Binding__SetOpenGLType(pBVar1,*(ushort *)(iVar2 + 0x2c));
        Binding__SetActualSize(pBVar1,1);
        Binding__SetDecSize(pBVar1,1);
        iVar6 = *(int *)(iVar2 + 0x34);
        if (iVar6 == 1) {
          pcVar7 = *(char **)(pBVar1 + 8);
          sVar3 = _strlen(DAT_a7b7bb68);
          sVar4 = _strlen(pcVar7);
          pcVar5 = _malloc(sVar3 + sVar4 + 1);
          _sprintf(pcVar5,DAT_a7b7bb68,pcVar7);
          pvVar8 = *(void **)(this + 0x84);
                    
          __ZN13TInfoSinkBase6appendEPKc(pvVar8,"INTERNAL ERROR: ");
          __ZN13TInfoSinkBase6appendEPKc(pvVar8,pcVar5);
          __ZN13TInfoSinkBase6appendEPKc(pvVar8,"\n");
          _free(pcVar5);
          iVar6 = *(int *)(iVar2 + 0x34);
        }
        Binding__SetBuiltIn(pBVar1,SUB41(iVar6,0));
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
  short sVar1;
  unsigned char * pPVar2;
  
  if (*(unsigned char **)(this + 0x28) != (unsigned char *)0x0) {
    for (pPVar2 = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        pPVar2 != (unsigned char *)0x0;
        pPVar2 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar2)) {
      if (((**(char **)pPVar2 == '\x02') && (*(short *)(pPVar2 + 0x2c) == -0x74a4)) &&
         (*(int *)(pPVar2 + 0x34) == 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)*(undefined4 *)(pPVar2 + 0x14),true,0);
      }
    }
    for (pPVar2 = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        pPVar2 != (unsigned char *)0x0;
        pPVar2 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar2)) {
      if (((**(char **)pPVar2 == '\x02') && (*(short *)(pPVar2 + 0x2c) == -0x74a5)) &&
         (*(int *)(pPVar2 + 0x34) == 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)*(undefined4 *)(pPVar2 + 0x14),true,0);
      }
    }
    for (pPVar2 = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        pPVar2 != (unsigned char *)0x0;
        pPVar2 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar2)) {
      if (((**(char **)pPVar2 == '\x02') && (*(short *)(pPVar2 + 0x2c) == -0x74a6)) &&
         (*(int *)(pPVar2 + 0x34) == 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)*(undefined4 *)(pPVar2 + 0x14),true,0);
      }
    }
    for (pPVar2 = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        pPVar2 != (unsigned char *)0x0;
        pPVar2 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar2)) {
      if ((((**(char **)pPVar2 == '\x02') && (sVar1 = *(short *)(pPVar2 + 0x2c), sVar1 != -0x74a4))
          && (sVar1 != -0x74a5)) && ((sVar1 != -0x74a6 && (*(int *)(pPVar2 + 0x34) == 0)))) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)*(undefined4 *)(pPVar2 + 0x14),SUB21(sVar1,0),0);
      }
    }
    for (pPVar2 = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        pPVar2 != (unsigned char *)0x0;
        pPVar2 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar2)) {
      if (((**(char **)pPVar2 == '\x02') && (*(short *)(pPVar2 + 0x2c) == -0x74a4)) &&
         (*(int *)(pPVar2 + 0x34) != 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)*(undefined4 *)(pPVar2 + 0x14),true,1);
      }
    }
    for (pPVar2 = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        pPVar2 != (unsigned char *)0x0;
        pPVar2 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar2)) {
      if (((**(char **)pPVar2 == '\x02') && (*(short *)(pPVar2 + 0x2c) == -0x74a5)) &&
         (*(int *)(pPVar2 + 0x34) != 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)*(undefined4 *)(pPVar2 + 0x14),true,1);
      }
    }
    for (pPVar2 = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        pPVar2 != (unsigned char *)0x0;
        pPVar2 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar2)) {
      if (((**(char **)pPVar2 == '\x02') && (*(short *)(pPVar2 + 0x2c) == -0x74a6)) &&
         (*(int *)(pPVar2 + 0x34) != 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)*(undefined4 *)(pPVar2 + 0x14),true,1);
      }
    }
    for (pPVar2 = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        pPVar2 != (unsigned char *)0x0;
        pPVar2 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar2)) {
      if (((**(char **)pPVar2 == '\x02') && (sVar1 = *(short *)(pPVar2 + 0x2c), sVar1 != -0x74a4))
         && ((sVar1 != -0x74a5 && ((sVar1 != -0x74a6 && (*(int *)(pPVar2 + 0x34) != 0)))))) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)*(undefined4 *)(pPVar2 + 0x14),SUB21(sVar1,0),1);
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
  size_t sVar4;
  size_t sVar5;
  int iVar6;
  ushort uVar8;
  uint uVar7;
  char *pcVar9;
  undefined4 uVar10;
  char *pcVar11;
  uint uVar12;
  void *this_01;
  
  uVar10 = 1;
  this_00 = (unsigned char *)BindingTable__NextAttribBinding(*(unsigned char **)(this + 4),(unsigned char *)0x0);
joined_r0x97bb54f0:
  if (this_00 == (unsigned char *)0x0) {
    return uVar10;
  }
  iVar2 = Binding__IsBuiltIn(this_00);
  if (((iVar2 == 0) && (*(unsigned char **)(this + 0x28) != (unsigned char *)0x0)) &&
     (puVar3 = (undefined4 *)
               ParseSymbolTable__FindGlobalSymbolByName
                         (*(unsigned char **)(this + 0x28),*(char **)(this_00 + 8)),
     puVar3 != (undefined4 *)0x0)) {
    pcVar9 = (char *)*puVar3;
    if (*pcVar9 != '\x02') {
      pcVar11 = (char *)puVar3[5];
      sVar4 = _strlen(DAT_a7b7bb6c);
      sVar5 = _strlen(pcVar11);
      pcVar9 = _malloc(sVar4 + sVar5 + 1);
      _sprintf(pcVar9,DAT_a7b7bb6c,pcVar11);
      this_01 = *(void **)(this + 0x84);
                    
      __ZN13TInfoSinkBase6appendEPKc(this_01,"INTERNAL ERROR: ");
      __ZN13TInfoSinkBase6appendEPKc(this_01,pcVar9);
      __ZN13TInfoSinkBase6appendEPKc(this_01,"\n");
      _free(pcVar9);
      uVar10 = 0;
      pcVar9 = (char *)*puVar3;
    }
    if ((*pcVar9 == '\x02') && ((*(uint *)(pcVar9 + 0xc) & 0xf0000) == 0x90000)) {
      sVar1 = *(short *)(pcVar9 + 0x12);
      iVar6 = Binding__GetLocation(this_00);
      for (iVar2 = **(int **)(*(int *)(this + 0x30) + 0x18); iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)
          ) {
        uVar12 = 0;
        if (*(short *)(iVar2 + 0x12) == sVar1) goto code_r0x97bb567c;
      }
    }
  }
  goto LAB_97bb56a8;
code_r0x97bb567c:
  while( true ) {
    uVar8 = Binding__GetOpenGLType(this_00);
    uVar7 = ((int (*)())GetVec4sForType)(uVar8);
    if ((uVar7 <= uVar12) || (iVar2 == 0)) break;
    uVar7 = iVar6 + uVar12;
    uVar12 = uVar12 + 1;
    *(uint *)(iVar2 + 0xc) = uVar7 & 0x1f | *(uint *)(iVar2 + 0xc) & 0xffffffe0;
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
  uint *puVar4;
  uint uVar5;
  unsigned char * pPVar6;
  size_t sVar7;
  char *pcVar8;
  uint uVar9;
  int *piVar10;
  unsigned char * pFVar11;
  int iVar12;
  int iVar13;
  size_t sVar14;
  size_t sVar15;
  size_t sVar16;
  undefined4 uVar17;
  undefined4 uVar18;
  uint uVar19;
  uint uVar20;
  int *piVar21;
  int iVar22;
  uint uVar23;
  undefined4 uVar24;
  ushort uVar25;
  int iVar26;
  int iVar27;
  char *pcVar28;
  int iVar29;
  void *pvVar30;
  void *pvVar31;
  uint uVar32;
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
  uVar24 = 1;
  iVar29 = 0;
  iVar27 = 0;
  iVar26 = 0;
  if (*(unsigned char **)(this + 0x28) != (unsigned char *)0x0) {
    for (pPVar6 = (unsigned char *)
                  ParseSymbolTable__NextSymbol
                            (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
        pPVar6 != (unsigned char *)0x0;
        pPVar6 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar6)) {
      if ((**(char **)pPVar6 == '\x04') &&
         (uVar20 = *(uint *)(*(char **)pPVar6 + 0xc), (uVar20 & 0xf0000) == 0x60000)) {
        uVar20 = uVar20 & 0x1f;
        *(uint *)(this + 0x78) = *(uint *)(this + 0x78) | 1 << uVar20;
        if (*(int *)(this + 0x74) < (int)uVar20) {
          *(uint *)(this + 0x74) = uVar20;
        }
        iVar29 = iVar29 + 1;
      }
    }
  }
  this_00 = *(unsigned char **)(this + 0x2c);
  if (this_00 != (unsigned char *)0x0) {
    iVar27 = *(int *)(this_00 + 0x1c);
    iVar26 = *(int *)(this_00 + 0x20);
    for (pPVar6 = (unsigned char *)ParseSymbolTable__NextSymbol(this_00,(unsigned char *)0x0);
        pPVar6 != (unsigned char *)0x0;
        pPVar6 = (unsigned char *)
                 ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x2c),pPVar6)) {
      if ((**(char **)pPVar6 == '\x02') &&
         (uVar20 = *(uint *)(*(char **)pPVar6 + 0xc), (uVar20 & 0xf0000) == 0x70000)) {
        uVar20 = uVar20 & 0x1f;
        if (*(int *)(this + 0x74) < (int)uVar20) {
          *(uint *)(this + 0x74) = uVar20;
        }
        if ((*(uint *)(this + 0x78) & 1 << uVar20) == 0) {
          iVar29 = iVar29 + 1;
        }
        *(uint *)(this + 0x78) = *(uint *)(this + 0x78) | 1 << uVar20;
      }
    }
  }
  if (iVar27 != 0) {
    if ((*(int *)(this + 0x28) == 0) || (*(int *)(this + 0x2c) == 0)) {
      if (*(unsigned char **)(this + 0x2c) != (unsigned char *)0x0) {
        for (pPVar6 = (unsigned char *)
                      ParseSymbolTable__NextSymbol
                                (*(unsigned char **)(this + 0x2c),(unsigned char *)0x0);
            pPVar6 != (unsigned char *)0x0;
            pPVar6 = (unsigned char *)
                     ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar6)) {
          if ((**(char **)pPVar6 == '\0') && (*(int *)(pPVar6 + 0x60) != 0)) {
            pcVar28 = *(char **)(pPVar6 + 0x14);
            sVar7 = _strlen(UNK_a7b7badc);
            sVar14 = _strlen(pcVar28);
            pcVar8 = _malloc(sVar7 + sVar14 + 1);
            _sprintf(pcVar8,UNK_a7b7badc,pcVar28);
            pvVar31 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar31,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar31,pcVar8);
            __ZN13TInfoSinkBase6appendEPKc(pvVar31,"\n");
            uVar24 = 0;
            _free(pcVar8);
          }
        }
      }
    }
    else {
      iVar27 = 1;
      iVar26 = iVar29 * 4 + iVar26;
      if (iVar26 < 0x21) {
        pvVar31 = _malloc(0x80);
        _memset(pvVar31,0,0x80);
        for (pPVar6 = (unsigned char *)
                      ParseSymbolTable__NextSymbol
                                (*(unsigned char **)(this + 0x2c),(unsigned char *)0x0);
            pPVar6 != (unsigned char *)0x0;
            pPVar6 = (unsigned char *)
                     ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x2c),pPVar6)) {
          if ((**(char **)pPVar6 == '\x02') &&
             (uVar20 = *(uint *)(*(char **)pPVar6 + 0xc), (uVar20 & 0xf0000) == 0x70000)) {
            iVar29 = (uVar20 & 0x1f) * 0x10;
            iVar26 = -iVar27;
            *(int *)((int)pvVar31 + iVar29) = iVar26;
            iVar27 = iVar27 + 1;
            *(int *)((int)pvVar31 + iVar29 + 0xc) = iVar26;
            *(int *)((int)pvVar31 + iVar29 + 4) = iVar26;
            *(int *)((int)pvVar31 + iVar29 + 8) = iVar26;
          }
        }
        for (pPVar6 = (unsigned char *)
                      ParseSymbolTable__NextSymbol
                                (*(unsigned char **)(this + 0x28),(unsigned char *)0x0);
            pPVar6 != (unsigned char *)0x0;
            pPVar6 = (unsigned char *)
                     ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x28),pPVar6)) {
          if ((**(char **)pPVar6 == '\x04') &&
             (uVar20 = *(uint *)(*(char **)pPVar6 + 0xc), (uVar20 & 0xf0000) == 0x60000)) {
            iVar29 = (uVar20 & 0x1f) * 0x10;
            iVar26 = -iVar27;
            *(int *)((int)pvVar31 + iVar29) = iVar26;
            iVar27 = iVar27 + 1;
            *(int *)((int)pvVar31 + iVar29 + 0xc) = iVar26;
            *(int *)((int)pvVar31 + iVar29 + 4) = iVar26;
            *(int *)((int)pvVar31 + iVar29 + 8) = iVar26;
          }
        }
        uVar20 = 4;
        do {
          for (pPVar6 = (unsigned char *)
                        ParseSymbolTable__NextSymbol
                                  (*(unsigned char **)(this + 0x2c),(unsigned char *)0x0);
              pPVar6 != (unsigned char *)0x0;
              pPVar6 = (unsigned char *)
                       ParseSymbolTable__NextSymbol(*(unsigned char **)(this + 0x2c),pPVar6)) {
            if (((**(char **)pPVar6 == '\0') && (*(int *)(pPVar6 + 0x60) != 0)) &&
               (uVar9 = ((int (*)())GetScalerWidthForType)(*(ushort *)(pPVar6 + 0x2c)), uVar20 == uVar9)) {
              piVar10 = (int *)ParseSymbolTable__FindGlobalSymbolByName
                                         (*(unsigned char **)(this + 0x28),
                                          *(char **)(pPVar6 + 0x14));
              if (((piVar10 == (int *)0x0) ||
                  (uVar25 = *(ushort *)(pPVar6 + 0x2c), uVar25 != *(ushort *)(piVar10 + 0xb))) ||
                 ((*(char *)*piVar10 != '\0' || (local_60 = 0, piVar10[0x17] == 0)))) {
                uVar24 = 0;
                if (piVar10 == (int *)0x0) {
code_r0x97bb689c:
                  pcVar28 = *(char **)(pPVar6 + 0x14);
                  sVar7 = _strlen(UNK_a7b7bad4);
                  sVar14 = _strlen(pcVar28);
                  pcVar8 = _malloc(sVar7 + sVar14 + 1);
                  _sprintf(pcVar8,UNK_a7b7bad4,pcVar28);
                  pvVar30 = *(void **)(this + 0x84);
                    
override_jmp_97bb67f0_case_0:
                  pcVar28 = "ERROR: ";
                }
                else {
                  if (*(short *)(pPVar6 + 0x2c) != *(short *)(piVar10 + 0xb)) {
                    pcVar28 = *(char **)(pPVar6 + 0x14);
                    sVar7 = _strlen(UNK_a7b7bad0);
                    sVar14 = _strlen(pcVar28);
                    pcVar8 = (char *)((int (*)())GetShaderStringForType)(*(ushort *)(piVar10 + 0xb));
                    sVar15 = _strlen(pcVar8);
                    pcVar8 = (char *)((int (*)())GetShaderStringForType)(*(ushort *)(pPVar6 + 0x2c));
                    sVar16 = _strlen(pcVar8);
                    pcVar8 = _malloc(sVar7 + sVar14 + sVar15 + sVar16 + 1);
                    uVar17 = ((int (*)())GetShaderStringForType)(*(ushort *)(pPVar6 + 0x2c));
                    uVar18 = ((int (*)())GetShaderStringForType)(*(ushort *)(piVar10 + 0xb));
                    _sprintf(pcVar8,UNK_a7b7bad0,pcVar28,uVar18,uVar17);
                    pvVar30 = *(void **)(this + 0x84);
                    
                    goto override_jmp_97bb67f0_case_0;
                  }
                  if ((*(char *)*piVar10 == '\0') && (piVar10[0x17] == 0)) goto code_r0x97bb689c;
                  pcVar28 = *(char **)(pPVar6 + 0x14);
                  sVar7 = _strlen(UNK_a7b7bb70);
                  sVar14 = _strlen(pcVar28);
                  pcVar8 = _malloc(sVar7 + sVar14 + 1);
                  _sprintf(pcVar8,UNK_a7b7bb70,pcVar28);
                  pvVar30 = *(void **)(this + 0x84);
                  pcVar28 = "INTERNAL ERROR: ";
                    
                }
                __ZN13TInfoSinkBase6appendEPKc(pvVar30,pcVar28);
                __ZN13TInfoSinkBase6appendEPKc(pvVar30,pcVar8);
                __ZN13TInfoSinkBase6appendEPKc(pvVar30,"\n");
                _free(pcVar8);
              }
              else {
                while (uVar9 = ((int (*)())GetVec4sForType)(uVar25), local_60 < uVar9) {
                  local_d0[3] = UNK_97c38fac;
                  local_e0[3] = UNK_97c38fac;
                  local_d0[0] = UNK_97c38fa0;
                  iVar29 = 0;
                  local_d0[1] = UNK_97c38fa4;
                  local_d0[2] = UNK_97c38fa8;
                  local_e0[0] = UNK_97c38fa0;
                  local_e0[1] = UNK_97c38fa4;
                  local_e0[2] = UNK_97c38fa8;
                  do {
                    bVar1 = true;
                    if (uVar20 == 2) {
                      iVar26 = iVar29 << 2;
code_r0x97bb5b68:
                      if (*(int *)((int)pvVar31 + iVar26 + 4) == 0) {
code_r0x97bb5b80:
                        if (*(int *)(iVar26 + (int)pvVar31) == 0) goto code_r0x97bb5b90;
                      }
code_r0x97bb5b8c:
                      bVar1 = false;
                    }
                    else {
                      if (2 < uVar20) {
                        if (uVar20 == 3) {
                          iVar26 = iVar29 << 2;
code_r0x97bb5b50:
                          if (*(int *)((int)pvVar31 + iVar26 + 8) == 0) goto code_r0x97bb5b68;
                        }
                        else {
                          if (uVar20 != 4) goto code_r0x97bb5b90;
                          iVar26 = iVar29 * 4;
                          if (*(int *)((int)pvVar31 + iVar26 + 0xc) == 0) goto code_r0x97bb5b50;
                        }
                        goto code_r0x97bb5b8c;
                      }
                      if (uVar20 == 1) {
                        iVar26 = iVar29 << 2;
                        goto code_r0x97bb5b80;
                      }
                    }
code_r0x97bb5b90:
                    bVar1 = !bVar1;
                    if ((!bVar1) && (uVar9 = 0, uVar20 != 0)) {
                      piVar21 = (int *)(iVar29 * 4 + (int)pvVar31);
                      puVar4 = local_e0;
                      uVar32 = uVar20;
                      do {
                        uVar2 = *(uint *)(this + 0x78);
                        puVar4[4] = uVar9;
                        uVar9 = uVar9 + 1;
                        *(uint *)(this + 0x78) = uVar2 | 1 << (iVar29 >> 2 & 0x3fU);
                        *puVar4 = iVar29 >> 2;
                        puVar4 = puVar4 + 1;
                        *piVar21 = iVar27;
                        piVar21 = piVar21 + 1;
                        uVar32 = uVar32 - 1;
                      } while (uVar32 != 0);
                    }
                    iVar29 = iVar29 + 4;
                  } while ((iVar29 < 0x20) && (bVar1));
                  iVar29 = 0;
                  if (bVar1) {
                    do {
                      uVar9 = 1;
                      if (-uVar20 == -4) {
code_r0x97bb5ccc:
                        if (!bVar1) goto code_r0x97bb5cd0;
                      }
                      else {
                        if (bVar1) {
                          do {
                            bVar1 = true;
                            if (uVar20 == 2) {
code_r0x97bb5c80:
                              if (*(int *)((int)pvVar31 + (iVar29 + uVar9) * 4 + 4) == 0) {
code_r0x97bb5c9c:
                                if (*(int *)((int)pvVar31 + (iVar29 + uVar9) * 4) == 0)
                                goto code_r0x97bb5cb0;
                              }
code_r0x97bb5cac:
                              bVar1 = false;
                            }
                            else if (uVar20 < 3) {
                              if (uVar20 == 1) goto code_r0x97bb5c9c;
                            }
                            else if (uVar20 == 3) {
                              if (*(int *)((int)pvVar31 + (iVar29 + uVar9) * 4 + 8) == 0)
                              goto code_r0x97bb5c80;
                              goto code_r0x97bb5cac;
                            }
code_r0x97bb5cb0:
                            uVar9 = uVar9 + 1;
                            if (-uVar20 + 4 < uVar9) {
                              bVar1 = !bVar1;
                              goto code_r0x97bb5ccc;
                            }
                          } while (!bVar1);
                          bVar1 = false;
                        }
code_r0x97bb5cd0:
                        iVar26 = 0;
                        if (uVar20 != 0) {
                          piVar21 = (int *)((iVar29 + (uVar9 - 1)) * 4 + (int)pvVar31);
                          puVar4 = local_e0;
                          uVar32 = uVar20;
                          do {
                            uVar2 = *(uint *)(this + 0x78);
                            puVar4[4] = iVar26 + (uVar9 - 1);
                            iVar26 = iVar26 + 1;
                            *(uint *)(this + 0x78) = uVar2 | 1 << (iVar29 >> 2 & 0x3fU);
                            *puVar4 = iVar29 >> 2;
                            puVar4 = puVar4 + 1;
                            *piVar21 = iVar27;
                            piVar21 = piVar21 + 1;
                            uVar32 = uVar32 - 1;
                          } while (uVar32 != 0);
                        }
                      }
                      iVar29 = iVar29 + 4;
                    } while ((iVar29 < 0x20) && (bVar1));
                  }
                  uVar9 = 0;
                  if ((uVar20 != 0) && (bVar1)) {
                    do {
                      uVar32 = 0;
                      uVar2 = 0;
                      if (bVar1) {
                        do {
                          uVar19 = uVar32;
                          if (*(int *)(uVar2 * 4 + (int)pvVar31) == 0) {
                            uVar3 = ((int)uVar2 >> 2) + (uint)((int)uVar2 < 0 && (uVar2 & 3) != 0);
                            local_e0[uVar32] = uVar3;
                            uVar19 = uVar32 + 1;
                            *(uint *)(this + 0x78) = *(uint *)(this + 0x78) | 1 << (uVar3 & 0x3f);
                            local_d0[uVar32] = uVar2 + uVar3 * -4;
                            *(int *)(uVar2 * 4 + (int)pvVar31) = iVar27;
                          }
                          if (uVar19 == uVar20) {
                            bVar1 = false;
                          }
                          uVar2 = uVar2 + 1;
                        } while (((int)uVar2 < 0x20) && (uVar32 = uVar19, bVar1));
                      }
                      uVar9 = uVar9 + 1;
                    } while ((uVar9 < uVar20) && (bVar1));
                  }
                  pcVar8 = UNK_a7b7bacc;
                  iVar27 = iVar27 + 1;
                  if (bVar1) {
                    uVar24 = 0;
                    pvVar30 = *(void **)(this + 0x84);
                    
                    __ZN13TInfoSinkBase6appendEPKc(pvVar30,"ERROR: ");
                    __ZN13TInfoSinkBase6appendEPKc(pvVar30,pcVar8);
                    __ZN13TInfoSinkBase6appendEPKc(pvVar30,"\n");
                  }
                  else {
                    pFVar11 = *(unsigned char **)(this + 0x38);
                    local_5c = 0;
                    uVar9 = 0;
                    if ((pFVar11 != (unsigned char *)0x0) && (*(int *)(pFVar11 + 4) != 0)) {
                      while( true ) {
                        pvVar30 = (void *)FunctionTable__getFunctionName(pFVar11,uVar9);
                        iVar29 = _memcmp(pvVar30,"main(",6);
                        if (iVar29 == 0) break;
                        pFVar11 = *(unsigned char **)(this + 0x38);
                        uVar9 = uVar9 + 1;
                        if ((pFVar11 == (unsigned char *)0x0) || (*(uint *)(pFVar11 + 4) <= uVar9))
                        break;
                      }
                    }
                    for (iVar29 = **(int **)(*(int *)(this + 0x30) + 0x20); iVar29 != 0;
                        iVar29 = *(int *)(iVar29 + 8)) {
                      uVar32 = FunctionTable__getFirstOp(*(unsigned char **)(this + 0x38),uVar9);
                      if (uVar32 == (*(uint *)(iVar29 + 0xc) & 0x3ffff)) {
                        local_5c = 1;
                      }
                      if (((local_5c != 0) && ((*(uint *)(iVar29 + 0xc) & 0x3fc0000) == 0x1340000))
                         && (uVar32 = 0, uVar20 != 0)) {
                        iVar26 = 0;
                        local_58 = &local_c0;
code_r0x97bb5ec0:
                        iVar12 = *(int *)(this + 0x30);
                        uVar2 = 0;
                        uVar19 = *(uint *)((int)local_e0 + iVar26);
                        for (iVar22 = **(int **)(iVar12 + 0x1c); iVar22 != 0;
                            iVar22 = *(int *)(iVar22 + 8)) {
                          if (((*(uint *)(iVar22 + 0xc) & 0xf0000) == 0x60000) &&
                             ((*(uint *)(iVar22 + 0xc) & 0x1f) == uVar19)) {
                            uVar25 = *(ushort *)(iVar22 + 0x12);
                            uVar3 = 3;
                            piVar21 = (int *)((int)pvVar31 + uVar19 * 0x10 + 0xc);
                            goto code_r0x97bb5f28;
                          }
                        }
                        local_7c = 0;
                        local_80 = uVar19 & 0x1f | 0x4060000;
                        piVar21 = (int *)((int)pvVar31 + uVar19 * 0x10 + 0xc);
                        uVar3 = 3;
                        do {
                          iVar22 = *piVar21;
                          piVar21 = piVar21 + -1;
                          if (iVar22 != 0) {
                            local_80 = (uVar3 & 3) << 0x18 | uVar19 & 0x1f | 0x4060000;
                            break;
                          }
                          uVar3 = uVar3 - 1;
                        } while (-1 < (int)uVar3);
                        uVar17 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(iVar12 + 0x1c));
                        uVar25 = (short)uVar17 + 1;
                        local_7c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_7c) + 0)),uVar25);
                        _PPStreamAddOutputBinding(*(undefined4 *)(this + 0x30),&local_80);
code_r0x97bb5fe4:
                        iVar12 = *(int *)(this + 0x30);
                        goto code_r0x97bb5fe8;
                      }
code_r0x97bb61d0:
                      uVar32 = FunctionTable__getLastOp(*(unsigned char **)(this + 0x38),uVar9);
                      if (uVar32 == (*(uint *)(iVar29 + 0xc) & 0x3ffff)) break;
                    }
                    pFVar11 = *(unsigned char **)(this + 0x3c);
                    uVar9 = 0;
                    if ((pFVar11 != (unsigned char *)0x0) && (*(int *)(pFVar11 + 4) != 0)) {
                      while( true ) {
                        pvVar30 = (void *)FunctionTable__getFunctionName(pFVar11,uVar9);
                        iVar29 = _memcmp(pvVar30,"main(",6);
                        if (iVar29 == 0) break;
                        pFVar11 = *(unsigned char **)(this + 0x3c);
                        uVar9 = uVar9 + 1;
                        if ((pFVar11 == (unsigned char *)0x0) || (*(uint *)(pFVar11 + 4) <= uVar9))
                        break;
                      }
                    }
                    for (iVar29 = **(int **)(*(int *)(this + 0x34) + 0x20); iVar29 != 0;
                        iVar29 = *(int *)(iVar29 + 8)) {
                      uVar32 = FunctionTable__getFirstOp(*(unsigned char **)(this + 0x3c),uVar9);
                      if (uVar32 == (*(uint *)(iVar29 + 0xc) & 0x3ffff)) {
                        uVar32 = 0;
                        if (uVar20 != 0) {
                          local_58 = &local_c0;
                          iVar26 = 0;
                          goto code_r0x97bb62a8;
                        }
                        break;
                      }
                    }
                  }
code_r0x97bb6720:
                  uVar25 = *(ushort *)(pPVar6 + 0x2c);
                  local_60 = local_60 + 1;
                }
              }
            }
          }
          uVar20 = uVar20 - 1;
        } while (uVar20 != 0);
        iVar29 = 0;
        *(undefined4 *)(this + 0x74) = 0xffffffff;
        iVar26 = 8;
        do {
          iVar27 = iVar29 * 4;
          if ((((*(int *)((int)pvVar31 + iVar27) != 0) || (*(int *)((int)pvVar31 + iVar27 + 4) != 0)
               ) || (*(int *)((int)pvVar31 + iVar27 + 8) != 0)) ||
             (*(int *)((int)pvVar31 + iVar27 + 0xc) != 0)) {
            *(int *)(this + 0x74) = iVar29 >> 2;
          }
          iVar29 = iVar29 + 4;
          iVar26 = iVar26 + -1;
        } while (iVar26 != 0);
        if (pvVar31 != (void *)0x0) {
          _free(pvVar31);
        }
      }
      else {
        sVar7 = _strlen(DAT_a7b7bb00);
        pcVar8 = _malloc(sVar7 + 0x11);
        _sprintf(pcVar8,DAT_a7b7bb00,0x20,iVar26);
        pvVar31 = *(void **)(this + 0x84);
                    
        __ZN13TInfoSinkBase6appendEPKc(pvVar31,"ERROR: ");
        __ZN13TInfoSinkBase6appendEPKc(pvVar31,pcVar8);
        __ZN13TInfoSinkBase6appendEPKc(pvVar31,"\n");
        _free(pcVar8);
        uVar24 = 0;
      }
    }
  }
  return uVar24;
  while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
code_r0x97bb5f28:
    iVar13 = *piVar21;
    piVar21 = piVar21 + -1;
    if (iVar13 != 0) {
      *(uint *)(iVar22 + 0xc) = (uVar3 & 3) << 0x18 | *(uint *)(iVar22 + 0xc) & 0xfcffffff;
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
  local_bc = 0;
  uVar3 = 0x60000;
  uVar23 = 0x800000;
  local_c0 = 0x20000000;
  local_b0 = 0x800000;
  local_b8 = 0x60000;
  local_90 = *(undefined4 *)(iVar29 + 0x3c);
  local_b4 = (uint)uVar25;
  local_8c = 0;
  local_ac = (uint)(ushort)(*(short *)(*piVar10 + 0x12) + (short)local_60);
  uVar5 = *(uint *)((int)local_e0 + iVar26);
  while ((uVar5 == uVar19 && (uVar32 < uVar20))) {
    uVar5 = *(uint *)((int)local_d0 + iVar26);
    if (uVar5 == 1) {
      uVar3 = (uVar2 & 3) << 6 | uVar3 & 0xffffff3f | 0x4000;
code_r0x97bb60fc:
      uVar3 = (uVar5 & 3) << 10 | uVar3 & 0xfffff3ff;
      local_b8 = uVar3;
    }
    else {
      if (1 < (int)uVar5) {
        if (uVar5 == 2) {
          uVar3 = (uVar2 & 3) << 4 | uVar3 & 0xffffffcf | 0x8000;
        }
        else {
          if (uVar5 != 3) goto code_r0x97bb6108;
          uVar3 = (uVar2 & 3) << 2 | uVar3 & 0xfffffff3 | 0x10000;
        }
        goto code_r0x97bb60fc;
      }
      if (uVar5 == 0) {
        uVar3 = (uVar2 & 3) << 8 | uVar3 & 0xfffffcff | 0x2000;
        goto code_r0x97bb60fc;
      }
    }
code_r0x97bb6108:
    if (uVar2 == 1) {
      uVar23 = (uVar32 & 3) << 0x13 | uVar23 & 0xffe7ffff;
code_r0x97bb6150:
      local_b0 = uVar23;
    }
    else {
      if (1 < (int)uVar2) {
        if (uVar2 == 2) {
          uVar23 = (uVar32 & 3) << 0x11 | uVar23 & 0xfff9ffff;
        }
        else {
          if (uVar2 != 3) goto code_r0x97bb6154;
          uVar23 = (uVar32 & 3) << 0xf | uVar23 & 0xfffe7fff;
        }
        goto code_r0x97bb6150;
      }
      if (uVar2 == 0) {
        uVar23 = (uVar32 & 3) << 0x15 | uVar23 & 0xff9fffff;
        goto code_r0x97bb6150;
      }
    }
code_r0x97bb6154:
    uVar32 = uVar32 + 1;
    uVar2 = uVar2 + 1;
    iVar26 = uVar32 * 4;
    uVar5 = local_e0[uVar32];
  }
  local_b0 = (uVar2 - 1) * 0x1000 & 0x3000 | uVar23;
  local_bc = (uVar2 - 1) * 0x4000000 & 0xc000000 | 0x800000;
  iVar22 = _PPStreamInsertOperationAfterChunk(iVar12,local_58,0,0,*(undefined4 *)(iVar29 + 4));
  _PPStreamChangeBranchTargets
            (*(undefined4 *)(this + 0x30),*(uint *)(iVar29 + 0xc) & 0x3ffff,
             *(uint *)(iVar22 + 0xc) & 0x3ffff);
  if (uVar20 <= uVar32) goto code_r0x97bb61d0;
  goto code_r0x97bb5ec0;
code_r0x97bb62a8:
  uVar2 = 0;
  uVar19 = *(uint *)((int)local_e0 + iVar26);
  for (iVar22 = **(int **)(*(int *)(this + 0x34) + 0x18); iVar22 != 0; iVar22 = *(int *)(iVar22 + 8)
      ) {
    if (((*(uint *)(iVar22 + 0xc) & 0xf0000) == 0x70000) &&
       ((*(uint *)(iVar22 + 0xc) & 0x1f) == uVar19)) {
      uVar25 = *(ushort *)(iVar22 + 0x12);
      uVar3 = 3;
      piVar21 = (int *)((int)pvVar31 + uVar19 * 0x10 + 0xc);
      goto code_r0x97bb630c;
    }
  }
  local_6c = 0;
  local_70 = uVar19 & 0x1f | 0x4070000;
  piVar21 = (int *)((int)pvVar31 + uVar19 * 0x10 + 0xc);
  uVar3 = 3;
  do {
    iVar22 = *piVar21;
    piVar21 = piVar21 + -1;
    if (iVar22 != 0) {
      local_70 = (uVar3 & 3) << 0x18 | uVar19 & 0x1f | 0x4070000;
      break;
    }
    uVar3 = uVar3 - 1;
  } while (-1 < (int)uVar3);
  uVar17 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(*(int *)(this + 0x34) + 0x18));
  uVar25 = (short)uVar17 + 1;
  local_6c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_6c) + 0)),uVar25);
  _PPStreamAddAttribBinding(*(undefined4 *)(this + 0x34),&local_70);
  goto code_r0x97bb63d0;
  while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
code_r0x97bb630c:
    iVar12 = *piVar21;
    piVar21 = piVar21 + -1;
    if (iVar12 != 0) {
      *(uint *)(iVar22 + 0xc) = (uVar3 & 3) << 0x18 | *(uint *)(iVar22 + 0xc) & 0xfcffffff;
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
  local_b4 = 0;
  local_bc = 0;
  uVar23 = 0x20000;
  local_c0 = 0x20000000;
  local_b8 = 0x20000;
  local_90 = *(undefined4 *)(iVar29 + 0x3c);
  local_8c = 0;
  uVar3 = 0;
  local_ac = (uint)uVar25;
  local_b0 = 0;
  uVar5 = *(uint *)((int)local_e0 + iVar26);
  local_b4 = (uint)(ushort)(*(short *)(*(int *)pPVar6 + 0x12) + (short)local_60);
  while ((uVar5 == uVar19 && (uVar32 < uVar20))) {
    if (uVar2 == 1) {
      uVar23 = (uVar32 & 3) << 6 | uVar23 & 0xffffff3f | 0x4000;
code_r0x97bb64dc:
      local_b8 = uVar23;
    }
    else {
      if (1 < (int)uVar2) {
        if (uVar2 == 2) {
          uVar23 = (uVar32 & 3) << 4 | uVar23 & 0xffffffcf | 0x8000;
        }
        else {
          if (uVar2 != 3) goto code_r0x97bb64e0;
          uVar23 = (uVar32 & 3) << 2 | uVar23 & 0xfffffff3 | 0x10000;
        }
        uVar23 = (uVar2 & 3) << 10 | uVar23 & 0xfffff3ff;
        goto code_r0x97bb64dc;
      }
      if (uVar2 == 0) {
        uVar23 = (uVar32 & 3) << 8 | uVar23 & 0xfffffcff | 0x2000;
        goto code_r0x97bb64dc;
      }
    }
code_r0x97bb64e0:
    if (uVar2 == 1) {
      uVar3 = (*(uint *)((int)local_d0 + iVar26) & 3) << 0x13 | uVar3 & 0xffe7ffff;
code_r0x97bb6544:
      local_b0 = uVar3;
    }
    else {
      if (1 < (int)uVar2) {
        if (uVar2 == 2) {
          uVar3 = (*(uint *)((int)local_d0 + iVar26) & 3) << 0x11 | uVar3 & 0xfff9ffff;
        }
        else {
          if (uVar2 != 3) goto code_r0x97bb6548;
          uVar3 = (*(uint *)((int)local_d0 + iVar26) & 3) << 0xf | uVar3 & 0xfffe7fff;
        }
        goto code_r0x97bb6544;
      }
      if (uVar2 == 0) {
        uVar3 = (*(uint *)((int)local_d0 + iVar26) & 3) << 0x15 | uVar3 & 0xff9fffff;
        goto code_r0x97bb6544;
      }
    }
code_r0x97bb6548:
    uVar32 = uVar32 + 1;
    uVar2 = uVar2 + 1;
    iVar26 = uVar32 * 4;
    uVar5 = local_e0[uVar32];
  }
  iVar22 = uVar2 - 1;
  local_b0 = iVar22 * 0x1000 & 0x3000U | uVar3;
  local_b8 = iVar22 * 0x400 & 0xc00U | uVar23 & 0xfffff3ff;
  local_bc = iVar22 * 0x4000000 & 0xc000000U | 0x800000;
  uVar2 = FunctionTable__getFirstOp(*(unsigned char **)(this + 0x3c),uVar9);
  if (uVar2 == (*(uint *)(iVar29 + 0xc) & 0x3ffff)) {
    iVar22 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(*(int *)(this + 0x34) + 0x20));
    *(uint *)(iVar29 + 0xc) = iVar22 + 1U & 0x3ffff | *(uint *)(iVar29 + 0xc) & 0xfffc0000;
    uVar17 = FunctionTable__getFirstOp(*(unsigned char **)(this + 0x3c),uVar9);
    _PPStreamChangeBranchTargets
              (*(undefined4 *)(this + 0x34),uVar17,*(uint *)(iVar29 + 0xc) & 0x3ffff);
  }
  iVar22 = _PPStreamInsertOperationAfterChunk
                     (*(undefined4 *)(this + 0x34),local_58,0,1,*(undefined4 *)(iVar29 + 4));
  if (iVar22 != 0) {
    FunctionTable__setFirstOp(*(unsigned char **)(this + 0x3c),uVar9,0);
    for (iVar12 = **(int **)(*(int *)(this + 0x34) + 0x24); iVar29 = iVar22, iVar12 != 0;
        iVar12 = *(int *)(iVar12 + 8)) {
      iVar13 = _memcmp("main(",(void *)(iVar12 + 0x14),6);
      if (iVar13 == 0) {
        *(undefined4 *)(iVar12 + 0xc) = 0;
        break;
      }
    }
  }
  if (uVar20 <= uVar32) goto code_r0x97bb6720;
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
  void *pvVar3;
  int iVar4;
  int *piVar5;
  size_t sVar6;
  size_t sVar7;
  char *pcVar8;
  size_t sVar9;
  size_t sVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  ushort uVar14;
  undefined4 uVar15;
  int iVar16;
  unsigned char * pTVar17;
  char *pcVar18;
  uint uVar19;
  uint uVar20;
  
  uVar15 = 1;
  this_00 = (unsigned char *)BindingTable__NextUniformBinding(*(unsigned char **)(this + 4),(unsigned char *)0x0)
  ;
  iVar16 = 0;
  pTVar17 = this;
  do {
    iVar2 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4));
    pvVar3 = _malloc(iVar2 * 4 + 0xfU & 0xfffffff0);
    *(void **)(pTVar17 + 0x40) = pvVar3;
    if (*(int *)(pTVar17 + 0x28) == 0) {
      *(undefined4 *)(pTVar17 + 0x48) = 0;
    }
    else {
      *(undefined4 *)(pTVar17 + 0x48) = *(undefined4 *)(*(int *)(pTVar17 + 0x28) + 0x28);
    }
    for (iVar2 = 0; iVar4 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4)),
        iVar2 < iVar4; iVar2 = iVar2 + 1) {
      *(undefined4 *)(iVar2 * 4 + *(int *)(pTVar17 + 0x40)) = 0xffffffff;
    }
    iVar16 = iVar16 + 1;
    pTVar17 = pTVar17 + 4;
  } while (iVar16 < 2);
  for (; this_00 != (unsigned char *)0x0;
      this_00 = (unsigned char *)BindingTable__NextUniformBinding(*(unsigned char **)(this + 4),this_00)) {
    iVar16 = Binding__IsBuiltIn(this_00);
    if (iVar16 == 0) {
      uVar14 = 0;
      bVar1 = false;
      iVar16 = 0;
      do {
        if ((*(unsigned char **)(this + iVar16 * 4 + 0x28) != (unsigned char *)0x0) &&
           (piVar5 = (int *)ParseSymbolTable__FindGlobalSymbolByName
                                      (*(unsigned char **)(this + iVar16 * 4 + 0x28),
                                       *(char **)(this_00 + 8)), piVar5 != (int *)0x0)) {
          if ((*(char *)*piVar5 != '\x03') ||
             ((*(uint *)((char *)*piVar5 + 0xc) & 0x1f0000) != 0x10000)) {
            pcVar18 = (char *)piVar5[5];
            sVar6 = _strlen(DAT_a7b7bb74);
            sVar7 = _strlen(pcVar18);
            pcVar8 = _malloc(sVar6 + sVar7 + 1);
            _sprintf(pcVar8,DAT_a7b7bb74,pcVar18);
            pvVar3 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar3,"INTERNAL ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar3,pcVar8);
            __ZN13TInfoSinkBase6appendEPKc(pvVar3,"\n");
            uVar15 = 0;
            _free(pcVar8);
          }
          if (bVar1) {
            if (*(ushort *)(piVar5 + 0xb) != uVar14) {
              pcVar18 = (char *)piVar5[5];
              sVar6 = _strlen(UNK_a7b7bae4);
              sVar7 = _strlen(pcVar18);
              pcVar8 = (char *)((int (*)())GetShaderStringForType)(uVar14);
              sVar9 = _strlen(pcVar8);
              pcVar8 = (char *)((int (*)())GetShaderStringForType)(*(ushort *)(piVar5 + 0xb));
              sVar10 = _strlen(pcVar8);
              pcVar8 = _malloc(sVar6 + sVar7 + sVar9 + sVar10 + 1);
              uVar15 = ((int (*)())GetShaderStringForType)(*(ushort *)(piVar5 + 0xb));
              uVar11 = ((int (*)())GetShaderStringForType)(uVar14);
              _sprintf(pcVar8,UNK_a7b7bae4,pcVar18,uVar11,uVar15);
              pvVar3 = *(void **)(this + 0x84);
                    
              __ZN13TInfoSinkBase6appendEPKc(pvVar3,"ERROR: ");
              __ZN13TInfoSinkBase6appendEPKc(pvVar3,pcVar8);
              __ZN13TInfoSinkBase6appendEPKc(pvVar3,"\n");
              uVar15 = 0;
              _free(pcVar8);
            }
          }
          else {
            uVar14 = *(ushort *)(piVar5 + 0xb);
            bVar1 = true;
          }
          uVar20 = (uint)*(ushort *)(*piVar5 + 0xe);
          for (uVar19 = 0; uVar12 = Binding__GetBindingSlots(this_00), uVar19 < uVar12;
              uVar19 = uVar19 + 1) {
            iVar2 = Binding__GetLocation(this_00);
            *(uint *)((iVar2 + uVar19) * 4 + *(int *)(this + iVar16 * 4 + 0x40)) = uVar20;
            uVar20 = uVar20 + 1;
          }
        }
        iVar16 = iVar16 + 1;
      } while (iVar16 < 2);
    }
  }
  iVar16 = 0;
  iVar2 = 0;
  for (iVar4 = 0; iVar13 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(this + 4)),
      pcVar8 = UNK_a7b7bb04, iVar4 < iVar13; iVar4 = iVar4 + 1) {
    if (*(int *)(iVar4 * 4 + *(int *)(this + 0x40)) != -1) {
      iVar16 = iVar16 + 1;
    }
    if (*(int *)(iVar4 * 4 + *(int *)(this + 0x44)) != -1) {
      iVar2 = iVar2 + 1;
    }
  }
  if (*(int *)(this + 0x48) != iVar16) {
    pvVar3 = *(void **)(this + 0x84);
                    
    __ZN13TInfoSinkBase6appendEPKc(pvVar3,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(pvVar3,pcVar8);
    __ZN13TInfoSinkBase6appendEPKc(pvVar3,"\n");
    uVar15 = 0;
  }
  pcVar8 = UNK_a7b7bb08;
  if (*(int *)(this + 0x4c) != iVar2) {
    pvVar3 = *(void **)(this + 0x84);
                    
    __ZN13TInfoSinkBase6appendEPKc(pvVar3,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(pvVar3,pcVar8);
    __ZN13TInfoSinkBase6appendEPKc(pvVar3,"\n");
    uVar15 = 0;
  }
  return uVar15;
}

/* TGenericLinker__InsertUniformBindingFromSymbol @ 0x97bb727c (388 bytes) */
int TGenericLinker__InsertUniformBindingFromSymbol(this, param_2, param_3)
  unsigned char * this;
  unsigned char * param_2;
  int param_3;
{
  unsigned char * this_00;
  unsigned char * pBVar1;
  size_t sVar2;
  size_t sVar3;
  char *pcVar4;
  undefined4 uVar5;
  char *pcVar6;
  void *this_01;
  
  uVar5 = 1;
  if ((**(char **)param_2 == '\x03') &&
     ((*(uint *)(*(char **)param_2 + 0xc) & 0x1f0000) != 0x110000)) {
    this_00 = operator_new(0x38);
    __ZN7BindingC1Ev(this_00);
    if (this_00 == (unsigned char *)0x0) {
      pcVar6 = *(char **)(param_2 + 0x14);
      sVar2 = _strlen(DAT_a7b7bb7c);
      sVar3 = _strlen(pcVar6);
      pcVar4 = _malloc(sVar2 + sVar3 + 1);
      _sprintf(pcVar4,DAT_a7b7bb7c,pcVar6);
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
        Binding__SetClientRequest(this_00,false);
        Binding__SetOpenGLType(this_00,*(ushort *)(param_2 + 0x2c));
        Binding__SetDecSize(this_00,(int)*(short *)(param_2 + 0x2e));
        Binding__SetActualSize(this_00,1);
        Binding__SetBuiltIn(this_00,SUB41(*(undefined4 *)(param_2 + 0x34),0));
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
  unsigned char * this_00;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  size_t sVar7;
  size_t sVar8;
  size_t sVar9;
  bool bVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  unsigned char * pFVar14;
  unsigned char * this_01;
  int iVar15;
  uint uVar16;
  void *pvVar17;
  
  iVar1 = param_2 * 4;
  this_00 = operator_new(8);
  bVar3 = false;
  __ZN13FunctionTableC1Ev(this_00);
  iVar11 = 0;
  if (0 < *(int *)(this + iVar1 + 0x20)) {
    do {
      iVar13 = 0;
      pFVar14 = *(unsigned char **)(*(int *)(iVar11 * 4 + *(int *)(this + iVar1 + 8)) + 0x6c);
      if (0 < *(int *)(pFVar14 + 4)) {
        do {
          bVar2 = false;
          iVar12 = 0;
          if (iVar11 < 1) {
LAB_97bb7818:
            pcVar4 = (char *)FunctionTable__getFunctionName(pFVar14,iVar13);
            iVar12 = FunctionTable__addFunction(this_00,pcVar4);
            bVar10 = (bool)FunctionTable__getEmpty(pFVar14,iVar13);
            FunctionTable__setEmpty(this_00,iVar12,bVar10);
            bVar10 = (bool)FunctionTable__getReturnVal(pFVar14,iVar13);
            FunctionTable__setReturnVal(this_00,iVar12,bVar10);
            iVar15 = FunctionTable__getNumParams(pFVar14,iVar13);
            FunctionTable__setNumParams(this_00,iVar12,iVar15);
            uVar16 = FunctionTable__getFirstOp(pFVar14,iVar13);
            FunctionTable__setFirstOp(this_00,iVar12,uVar16);
            uVar16 = FunctionTable__getLastOp(pFVar14,iVar13);
            FunctionTable__setLastOp(this_00,iVar12,uVar16);
          }
          else {
            do {
              iVar15 = 0;
              this_01 = *(unsigned char **)
                         (*(int *)(iVar12 * 4 + *(int *)(this + iVar1 + 8)) + 0x6c);
              if (0 < *(int *)(this_01 + 4)) {
                do {
                  pcVar4 = (char *)FunctionTable__getFunctionName(this_01,iVar15);
                  pcVar5 = (char *)FunctionTable__getFunctionName(pFVar14,iVar13);
                  iVar6 = _strcmp(pcVar4,pcVar5);
                  if (iVar6 == 0) {
                    pcVar4 = (char *)FunctionTable__getFunctionName(this_01,iVar15);
                    sVar7 = _strlen(pcVar4);
                    pcVar4 = _malloc(sVar7 + 1);
                    pcVar5 = (char *)FunctionTable__getFunctionName(this_01,iVar15);
                    _strcpy(pcVar4,pcVar5);
                    for (uVar16 = 0; sVar7 = _strlen(pcVar4), uVar16 < sVar7; uVar16 = uVar16 + 1) {
                      if (pcVar4[uVar16] == '(') {
                        pcVar4[uVar16] = '\0';
                      }
                    }
                    sVar7 = _strlen(DAT_a7b7bb20);
                    sVar8 = _strlen((char *)(&_shaderString)[param_2]);
                    sVar9 = _strlen(pcVar4);
                    pcVar5 = _malloc(sVar7 + sVar8 + sVar9 + 1);
                    _sprintf(pcVar5,DAT_a7b7bb20,pcVar4,(&_shaderString)[param_2]);
                    pvVar17 = *(void **)(this + 0x84);
                    
                    __ZN13TInfoSinkBase6appendEPKc(pvVar17,"ERROR: ");
                    __ZN13TInfoSinkBase6appendEPKc(pvVar17,pcVar5);
                    __ZN13TInfoSinkBase6appendEPKc(pvVar17,"\n");
                    _free(pcVar5);
                    _free(pcVar4);
                    bVar2 = true;
                  }
                  iVar15 = iVar15 + 1;
                } while (iVar15 < *(int *)(this_01 + 4));
              }
              iVar12 = iVar12 + 1;
            } while (iVar12 < iVar11);
            if (!bVar2) goto LAB_97bb7818;
          }
          iVar13 = iVar13 + 1;
          bVar3 = (bool)(bVar3 | bVar2);
        } while (iVar13 < *(int *)(pFVar14 + 4));
      }
      for (iVar13 = **(int **)(*(int *)(iVar11 * 4 + *(int *)(this + iVar1 + 0x18)) + 0x20);
          iVar13 != 0; iVar13 = *(int *)(iVar13 + 8)) {
        if ((*(uint *)(iVar13 + 0xc) & 0x3fc0000) == 0x1300000) {
          bVar2 = false;
          iVar12 = 0;
          pcVar4 = _malloc(*(int *)(iVar13 + 0x40) + 1);
          _strcpy(pcVar4,(char *)(iVar13 + 0x44));
          if (*(int *)(this + iVar1 + 0x20) < 1) {
            bVar10 = true;
          }
          else {
            do {
              iVar15 = 0;
              pFVar14 = *(unsigned char **)
                         (*(int *)(iVar12 * 4 + *(int *)(this + iVar1 + 8)) + 0x6c);
              if (0 < *(int *)(pFVar14 + 4)) {
                do {
                  pcVar5 = (char *)FunctionTable__getFunctionName(pFVar14,iVar15);
                  iVar6 = _strcmp(pcVar4,pcVar5);
                  if (iVar6 == 0) {
                    bVar2 = true;
                    break;
                  }
                  iVar15 = iVar15 + 1;
                } while (iVar15 < *(int *)(pFVar14 + 4));
              }
              bVar10 = !bVar2;
              if (!bVar10) goto code_r0x97bb7ad8;
              iVar12 = iVar12 + 1;
            } while (iVar12 < *(int *)(this + iVar1 + 0x20));
          }
          if (bVar10) {
            for (uVar16 = 0; sVar7 = _strlen(pcVar4), uVar16 < sVar7; uVar16 = uVar16 + 1) {
              if (pcVar4[uVar16] == '(') {
                pcVar4[uVar16] = '\0';
              }
            }
            sVar7 = _strlen(UNK_a7b7bb24);
            sVar8 = _strlen((char *)(&_shaderString)[param_2]);
            sVar9 = _strlen(pcVar4);
            pcVar5 = _malloc(sVar7 + sVar8 + sVar9 + 1);
            _sprintf(pcVar5,UNK_a7b7bb24,pcVar4,(&_shaderString)[param_2]);
            pvVar17 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar17,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar17,pcVar5);
            __ZN13TInfoSinkBase6appendEPKc(pvVar17,"\n");
            _free(pcVar5);
            bVar3 = true;
          }
code_r0x97bb7ad8:
          _free(pcVar4);
        }
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < *(int *)(this + iVar1 + 0x20));
    if (bVar3) goto code_r0x97bb7b18;
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
  int iVar3;
  int iVar4;
  size_t sVar5;
  size_t sVar6;
  char *pcVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  void *pvVar12;
  unsigned char * pTVar13;
  int local_50 [2];
  undefined8 local_48;
  undefined8 local_40 [2];
  
  iVar10 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_48 = DAT_97c38fb0;
  iVar11 = 1;
  local_40[0] = DAT_97c38fb8;
  if (param_3 < 1) {
LAB_97bb7d6c:
    bVar1 = false;
    if (iVar11 == 1) {
      iVar10 = 0;
      do {
        if ((local_50[iVar10] == 0) && (0 < *(int *)(this + iVar10 * 4 + 0x20))) {
          sVar5 = _strlen(UNK_a7b7bab8);
          sVar6 = _strlen((char *)(&_shaderString)[iVar10]);
          pcVar7 = _malloc(sVar5 + sVar6 + 1);
          _sprintf(pcVar7,UNK_a7b7bab8,(&_shaderString)[iVar10]);
          pvVar12 = *(void **)(this + 0x84);
                    
override_jmp_97bb7df4_case_0:
          __ZN13TInfoSinkBase6appendEPKc(pvVar12,"ERROR: ");
          __ZN13TInfoSinkBase6appendEPKc(pvVar12,pcVar7);
          __ZN13TInfoSinkBase6appendEPKc(pvVar12,"\n");
          _free(pcVar7);
          iVar11 = 0;
        }
        else if (1 < local_50[iVar10]) {
          sVar5 = _strlen(UNK_a7b7babc);
          sVar6 = _strlen((char *)(&_shaderString)[iVar10]);
          pcVar7 = _malloc(sVar5 + sVar6 + 9);
          _sprintf(pcVar7,UNK_a7b7babc,local_50[iVar10],(&_shaderString)[iVar10]);
          pvVar12 = *(void **)(this + 0x84);
                    
          goto override_jmp_97bb7df4_case_0;
        }
        iVar10 = iVar10 + 1;
      } while (iVar10 < 2);
      bVar1 = iVar11 == 1;
      if (bVar1) {
        pTVar13 = this;
        do {
          pvVar12 = _malloc(*(int *)(pTVar13 + 0x20) << 2);
          *(void **)(pTVar13 + 8) = pvVar12;
          pvVar12 = _malloc(*(int *)(pTVar13 + 0x20) << 2);
          *(void **)(pTVar13 + 0x10) = pvVar12;
          pvVar12 = _malloc(*(int *)(pTVar13 + 0x20) << 2);
          *(void **)(pTVar13 + 0x18) = pvVar12;
          pTVar13 = pTVar13 + 4;
        } while ((int)pTVar13 <= (int)(this + 4));
      }
    }
  }
  else {
    do {
      if (param_2[iVar10] == (int *)0x0) {
        pvVar12 = *(void **)(this + 0x84);
        pcVar7 = DAT_a7b7bb64;
                    
override_jmp_97bb7c58_case_0:
        __ZN13TInfoSinkBase6appendEPKc(pvVar12,"INTERNAL ERROR: ");
        __ZN13TInfoSinkBase6appendEPKc(pvVar12,pcVar7);
        __ZN13TInfoSinkBase6appendEPKc(pvVar12,"\n");
        iVar11 = 0;
      }
      else {
        iVar4 = (**(code **)(*(int *)param_2[iVar10] + 8))();
        if (iVar4 == 0) {
          pvVar12 = *(void **)(this + 0x84);
          pcVar7 = DAT_a7b7bb64;
                    
          goto override_jmp_97bb7c58_case_0;
        }
        iVar2 = 0;
        if (*(int *)(iVar4 + 8) != 0) {
          if (*(int *)(iVar4 + 8) != 1) {
            pvVar12 = *(void **)(this + 0x84);
            pcVar7 = _linkIntErrorString;
                    
            goto override_jmp_97bb7c58_case_0;
          }
          iVar2 = 1;
        }
        iVar3 = iVar2 * 4;
        if (*(int *)(iVar4 + 0xac) != 0) {
          local_50[iVar2] = local_50[iVar2] + 1;
          *(int *)((int)local_40 + iVar3 + -8) = iVar10;
        }
        *(int *)(this + iVar3 + 0x20) = *(int *)(this + iVar3 + 0x20) + 1;
      }
      iVar10 = iVar10 + 1;
      if (param_3 <= iVar10) goto LAB_97bb7d6c;
    } while (iVar11 == 1);
    bVar1 = false;
  }
  iVar10 = 0;
  if ((0 < param_3) && (bVar1)) {
    do {
      piVar8 = *param_2;
      param_2 = param_2 + 1;
      if ((piVar8 != (int *)0x0) && (iVar4 = (**(code **)(*piVar8 + 8))(), iVar4 != 0)) {
        iVar2 = (uint)(*(int *)(iVar4 + 8) != 0) * 4;
        if (*(int *)((int)local_40 + iVar2 + -8) == iVar10) {
          **(int **)(this + iVar2 + 8) = iVar4;
          **(undefined4 **)(this + iVar2 + 0x10) = *(undefined4 *)(iVar4 + 0x68);
          **(undefined4 **)(this + iVar2 + 0x18) = *(undefined4 *)(iVar4 + 0x70);
        }
        else {
          *(int *)(*(int *)((int)local_40 + iVar2) * 4 + *(int *)(this + iVar2 + 8)) = iVar4;
          *(undefined4 *)(*(int *)((int)local_40 + iVar2) * 4 + *(int *)(this + iVar2 + 0x10)) =
               *(undefined4 *)(iVar4 + 0x68);
          iVar3 = *(int *)((int)local_40 + iVar2);
          iVar9 = *(int *)(this + iVar2 + 0x18);
          *(int *)((int)local_40 + iVar2) = iVar3 + 1;
          *(undefined4 *)(iVar3 * 4 + iVar9) = *(undefined4 *)(iVar4 + 0x70);
        }
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < param_3);
  }
  return iVar11;
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
  ((int (*)())__ZN14TGenericLinkerD4Ev)(this);
  return;
}

/* __ZN14TGenericLinkerD1Ev @ 0x97bb8238 (8 bytes) */
int __ZN14TGenericLinkerD1Ev(this)
  void *this;
{
  ((int (*)())__ZN14TGenericLinkerD4Ev)(this);
  return;
}

/* __ZN14TGenericLinkerD0Ev @ 0x97bb8240 (8 bytes) */
int __ZN14TGenericLinkerD0Ev(this)
  void *this;
{
  ((int (*)())__ZN14TGenericLinkerD4Ev)(this);
  return;
}

/* __ZN14TGenericLinkerD4Ev @ 0x97bb8248 (244 bytes) */
int __ZN14TGenericLinkerD4Ev(this)
  void *this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint in_r4;
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
  if ((in_r4 & 1) != 0) {
    __ZdlPv(this);
  }
  return;
}

/* TGenericLinker__getShaderLocalParamRemapTable @ 0x97bb833c (40 bytes) */
int TGenericLinker__getShaderLocalParamRemapTable(this, param_2)
  int this;
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
  int this;
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
    Binding__SetClientRequest(this_00,true);
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
  size_t sVar2;
  long lVar3;
  ulong uVar4;
  
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
        sVar2 = _strlen(param_7);
        *param_4 = sVar2;
      }
    }
    if (param_5 != (long *)0x0) {
      lVar3 = Binding__GetActualSize(this_00);
      *param_5 = lVar3;
    }
    if (param_6 != (ulong *)0x0) {
      uVar4 = Binding__GetOpenGLType(this_00);
      *param_6 = uVar4;
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
  int this;
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
    if (*(void **)(pTVar2 + 8) != (void *)0x0) {
      _free(*(void **)(pTVar2 + 8));
    }
    *(undefined4 *)(pTVar2 + 8) = 0;
    if (*(void **)(pTVar2 + 0x10) != (void *)0x0) {
      _free(*(void **)(pTVar2 + 0x10));
    }
    *(undefined4 *)(pTVar2 + 0x10) = 0;
    if (*(void **)(pTVar2 + 0x18) != (void *)0x0) {
      _free(*(void **)(pTVar2 + 0x18));
    }
    *(undefined4 *)(pTVar2 + 0x20) = 0;
    *(undefined4 *)(pTVar2 + 0x18) = 0;
    pTVar2 = pTVar2 + 4;
  } while ((int)pTVar2 <= (int)(this + 4));
  pTVar2 = this;
  do {
    if (*(void **)(pTVar2 + 0x40) != (void *)0x0) {
      _free(*(void **)(pTVar2 + 0x40));
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
  size_t sVar4;
  size_t sVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  unsigned char * pTVar9;
  void *pvVar10;
  
  iVar8 = 1;
  if (0 < param_3) {
    iVar8 = ((int (*)())TGenericLinker__BuildSymbolTableList)(this,param_2,param_3);
    if ((iVar8 == 1) && (iVar8 = ((int (*)())TGenericLinker__BuildProcessingComponents)((void **)this,(int)param_2), iVar8 == 1))
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
             (iVar3 = _PPStreamResolveBranches(*(int *)(this + iVar2 * 4 + 0x30)), iVar3 != 0)) {
            sVar4 = _strlen(DAT_a7b7bb1c);
            sVar5 = _strlen((char *)(&_shaderString)[iVar2]);
            pcVar6 = _malloc(sVar4 + sVar5 + 1);
            _sprintf(pcVar6,DAT_a7b7bb1c,(&_shaderString)[iVar2]);
            pvVar10 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,pcVar6);
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,"\n");
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
          iVar2 = BindingTable__GetSizeActiveAttributes(*(unsigned char **)(this + 4));
          if (0x10 < iVar2) {
            sVar4 = _strlen(UNK_a7b7bae8);
            pcVar6 = _malloc(sVar4 + 0x11);
            uVar7 = BindingTable__GetSizeActiveAttributes(*(unsigned char **)(this + 4));
            _sprintf(pcVar6,UNK_a7b7bae8,0x10,uVar7);
            pvVar10 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,pcVar6);
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,"\n");
            _free(pcVar6);
            iVar8 = 0;
          }
          iVar2 = BindingTable__GetSizeActiveVertexUniforms(*(unsigned char **)(this + 4));
          if (0x200 < iVar2) {
            sVar4 = _strlen(DAT_a7b7baec);
            pcVar6 = _malloc(sVar4 + 0x11);
            uVar7 = BindingTable__GetSizeActiveVertexUniforms(*(unsigned char **)(this + 4));
            _sprintf(pcVar6,DAT_a7b7baec,0x200,uVar7);
            pvVar10 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,pcVar6);
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,"\n");
            _free(pcVar6);
            iVar8 = 0;
          }
          iVar2 = BindingTable__GetSizeActiveFragmentUniforms(*(unsigned char **)(this + 4));
          if (0x200 < iVar2) {
            sVar4 = _strlen(DAT_a7b7baf0);
            pcVar6 = _malloc(sVar4 + 0x11);
            uVar7 = BindingTable__GetSizeActiveFragmentUniforms(*(unsigned char **)(this + 4));
            _sprintf(pcVar6,DAT_a7b7baf0,0x200,uVar7);
            pvVar10 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,pcVar6);
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,"\n");
            _free(pcVar6);
            iVar8 = 0;
          }
          iVar2 = BindingTable__GetNumActiveVertexSamplers(*(unsigned char **)(this + 4));
          if (0 < iVar2) {
            sVar4 = _strlen(UNK_a7b7baf4);
            pcVar6 = _malloc(sVar4 + 0x11);
            uVar7 = BindingTable__GetNumActiveVertexSamplers(*(unsigned char **)(this + 4));
            _sprintf(pcVar6,UNK_a7b7baf4,0,uVar7);
            pvVar10 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,pcVar6);
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,"\n");
            _free(pcVar6);
            iVar8 = 0;
          }
          iVar2 = BindingTable__GetNumActiveFragmentSamplers(*(unsigned char **)(this + 4));
          if (0x10 < iVar2) {
            sVar4 = _strlen(UNK_a7b7baf8);
            pcVar6 = _malloc(sVar4 + 0x11);
            uVar7 = BindingTable__GetNumActiveFragmentSamplers(*(unsigned char **)(this + 4));
            _sprintf(pcVar6,UNK_a7b7baf8,0x10,uVar7);
            pvVar10 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,pcVar6);
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,"\n");
            _free(pcVar6);
            iVar8 = 0;
          }
          iVar2 = BindingTable__GetNumActiveVertexSamplers(*(unsigned char **)(this + 4));
          iVar3 = BindingTable__GetNumActiveFragmentSamplers(*(unsigned char **)(this + 4));
          if (0x10 < iVar2 + iVar3) {
            sVar4 = _strlen(UNK_a7b7bafc);
            pcVar6 = _malloc(sVar4 + 0x11);
            iVar8 = BindingTable__GetNumActiveVertexSamplers(*(unsigned char **)(this + 4));
            iVar2 = BindingTable__GetNumActiveFragmentSamplers(*(unsigned char **)(this + 4));
            _sprintf(pcVar6,UNK_a7b7bafc,0x10,iVar8 + iVar2);
            pvVar10 = *(void **)(this + 0x84);
                    
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,"ERROR: ");
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,pcVar6);
            __ZN13TInfoSinkBase6appendEPKc(pvVar10,"\n");
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
  char *extraout_r3;
  size_t sVar4;
  char *extraout_r3_00;
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
      ((double (*)())_glpPPDisassemble)(pvVar3);
      _free(pvVar3);
      pcVar7 = extraout_r3;
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
      ((double (*)())_glpPPDisassemble)(pvVar3);
      _free(pvVar3);
      pcVar8 = extraout_r3_00;
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

