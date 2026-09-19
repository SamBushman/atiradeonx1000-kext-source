#include "decls.h"

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
#if 0   /* compile-failing as plain C: Ghidra text kept verbatim, see ledger status */
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
#endif

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
  
  iVar8 = 1;
  if (0 < param_2) {
    iVar8 = TGenericLinker__BuildSymbolTableList(this,param_1,param_2);
    if (iVar8 == 1) {
      iVar8 = TGenericLinker__BuildProcessingComponents((void **)this,(int)param_1);
      if (iVar8 == 1) {
        TGenericLinker__RemoveExtraVertexOutputs(this);
        TGenericLinker__FixOutputReads(this);
        iVar2 = TGenericLinker__AllocateTextureUnitsForVaryings(this);
        if (iVar2 == 0) {
          iVar8 = 0;
        }
        if (1 < *(int *)(this + 0x80)) {
          TGenericLinker__OptimizeFunctionIO(this);
          TGenericLinker__RemoveUnreachableFunctions(this);
          if (2 < *(int *)(this + 0x80)) {
            TGenericLinker__RemoveUnusedRegisters(this);
          }
        }
        pTVar9 = this;
        do {
          if (*(int *)(pTVar9 + 0x30) != 0) {
            TGenericLinker__CoalesceCommonUniforms(this);
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
                    
                    
              iVar8 = (*(code *)(((unsigned char *)0x97bb89b0) + (*(unsigned char *)0x97bb89b8)))();
              return iVar8;
            }
            iVar2 = iVar2 + 1;
          } while (iVar2 < 2);
          if (iVar8 == 1) {
            iVar2 = TGenericLinker__CollectClientAttributeBindings(this);
            if (iVar2 == 0) {
              iVar8 = 0;
            }
            iVar2 = TGenericLinker__CollectAttributeBindings(this);
            if (iVar2 == 0) {
              iVar8 = 0;
            }
            iVar2 = TGenericLinker__CollectUniformBindings(this);
            if (iVar2 == 0) {
              iVar8 = 0;
            }
            iVar2 = BindingTable__GetSizeActiveAttributes();
            if (0x10 < iVar2) {
              sVar4 = _strlen(DAT_a7b7bae8);
              pcVar6 = _malloc(sVar4 + 0x11);
              uVar7 = BindingTable__GetSizeActiveAttributes();
              _sprintf(pcVar6,DAT_a7b7bae8,0x10,uVar7);
                    
                    
              iVar8 = (*(code *)(((unsigned char *)0x97bb8ae4) + (*(unsigned char *)0x97bb8aec)))();
              return iVar8;
            }
            iVar2 = BindingTable__GetSizeActiveVertexUniforms();
            if (0x200 < iVar2) {
              sVar4 = _strlen(DAT_a7b7baec);
              pcVar6 = _malloc(sVar4 + 0x11);
              uVar7 = BindingTable__GetSizeActiveVertexUniforms();
              _sprintf(pcVar6,DAT_a7b7baec,0x200,uVar7);
                    
                    
              iVar8 = (*(code *)(((unsigned char *)0x97bb8bc8) + (*(unsigned char *)0x97bb8bd0)))();
              return iVar8;
            }
            iVar2 = BindingTable__GetSizeActiveFragmentUniforms();
            if (0x200 < iVar2) {
              sVar4 = _strlen(DAT_a7b7baf0);
              pcVar6 = _malloc(sVar4 + 0x11);
              uVar7 = BindingTable__GetSizeActiveFragmentUniforms();
              _sprintf(pcVar6,DAT_a7b7baf0,0x200,uVar7);
                    
                    
              iVar8 = (*(code *)(((unsigned char *)0x97bb8cac) + (*(unsigned char *)0x97bb8cb4)))();
              return iVar8;
            }
            iVar2 = BindingTable__GetNumActiveVertexSamplers();
            if (0 < iVar2) {
              sVar4 = _strlen(DAT_a7b7baf4);
              pcVar6 = _malloc(sVar4 + 0x11);
              uVar7 = BindingTable__GetNumActiveVertexSamplers();
              _sprintf(pcVar6,DAT_a7b7baf4,0,uVar7);
                    
                    
              iVar8 = (*(code *)(((unsigned char *)0x97bb8d90) + (*(unsigned char *)0x97bb8d98)))();
              return iVar8;
            }
            iVar2 = BindingTable__GetNumActiveFragmentSamplers();
            if (0x10 < iVar2) {
              sVar4 = _strlen(DAT_a7b7baf8);
              pcVar6 = _malloc(sVar4 + 0x11);
              uVar7 = BindingTable__GetNumActiveFragmentSamplers();
              _sprintf(pcVar6,DAT_a7b7baf8,0x10,uVar7);
                    
                    
              iVar8 = (*(code *)(((unsigned char *)0x97bb8e74) + (*(unsigned char *)0x97bb8e7c)))();
              return iVar8;
            }
            iVar2 = BindingTable__GetNumActiveVertexSamplers();
            iVar3 = BindingTable__GetNumActiveFragmentSamplers();
            if (0x10 < iVar2 + iVar3) {
              sVar4 = _strlen(DAT_a7b7bafc);
              pcVar6 = _malloc(sVar4 + 0x11);
              iVar8 = BindingTable__GetNumActiveVertexSamplers();
              iVar2 = BindingTable__GetNumActiveFragmentSamplers();
              _sprintf(pcVar6,DAT_a7b7bafc,0x10,iVar8 + iVar2);
                    
                    
              iVar8 = (*(code *)(((unsigned char *)0x97bb8f78) + (*(unsigned char *)0x97bb8f80)))();
              return iVar8;
            }
            if (iVar8 == 1) {
              iVar2 = TGenericLinker__RemapVertexAttributes(this);
              if (iVar2 == 0) {
                iVar8 = 0;
              }
              bVar1 = iVar8 == 1;
              iVar2 = TGenericLinker__BuildUniformRemapTables(this);
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
    iVar1 = TGenericLinker__GetFullTableString(this);
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

/* TemporaryAllocator__TemporaryAllocator_97bb9e90 @ 0x97bb9e90 (4 bytes) */
int TemporaryAllocator__TemporaryAllocator_97bb9e90(this)
  unsigned char * this;
{
  TemporaryAllocator(this);
  return;
}

/* TemporaryAllocator__TemporaryAllocator_97bb9e94 @ 0x97bb9e94 (32 bytes) */
int TemporaryAllocator__TemporaryAllocator_97bb9e94(this)
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

/* TemporaryAllocator___TemporaryAllocator @ 0x97bb9eb4 (8 bytes) */
int TemporaryAllocator___TemporaryAllocator(this)
  unsigned char * this;
{
  ~TemporaryAllocator(this);
  return;
}

/* TemporaryAllocator___TemporaryAllocator_97bb9ebc @ 0x97bb9ebc (8 bytes) */
int TemporaryAllocator___TemporaryAllocator_97bb9ebc(this)
  unsigned char * this;
{
  ~TemporaryAllocator(this);
  return;
}

/* TemporaryAllocator___TemporaryAllocator_97bb9ec4 @ 0x97bb9ec4 (72 bytes) */
int TemporaryAllocator___TemporaryAllocator_97bb9ec4(this)
  unsigned char * this;
{
  void *pvVar1;
  unsigned char * pTVar2;
  
  pTVar2 = this + 0x60;
  do {
    pvVar1 = *(void **)this;
    this = this + 4;
    if (pvVar1 != (void *)0x0) {
      _free(pvVar1);
    }
  } while (this <= pTVar2);
  return;
}

/* TemporaryAllocator__getTemporary @ 0x97bb9f0c (408 bytes) */
int TemporaryAllocator__getTemporary(this, param_1)
  unsigned char * this;
  int param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  void *pvVar6;
  undefined2 in_register_00000010;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  iVar9 = CONCAT22(in_register_00000010,param_1);
  uVar10 = 0;
  iVar2 = 0;
  if ((iVar9 != 0x1404) && (iVar2 = 1, iVar9 != 0x1406)) {
    if ((iVar9 + 0x74b0U & 0xffff) < 0x15) {
      iVar2 = iVar9 + -0x8b4e;
    }
    else {
      iVar2 = 0x17;
      if ((iVar9 != 0x7ffe) && (iVar2 = 0x18, iVar9 != 0x7fff)) {
        return 0;
      }
    }
  }
  iVar2 = iVar2 * 4;
  iVar9 = 0;
  if (*(uint *)(this + iVar2 + 100) != 0) {
    piVar4 = *(int **)(this + iVar2);
    iVar3 = *piVar4;
    while (iVar3 != 0) {
      uVar10 = uVar10 + 1;
      iVar9 = uVar10 * 4;
      if (*(uint *)(this + iVar2 + 100) <= uVar10) break;
      piVar4 = piVar4 + 1;
      iVar3 = *piVar4;
    }
  }
  if (*(uint *)(this + iVar2 + 100) <= uVar10) {
    pvVar6 = _malloc(*(uint *)(this + iVar2 + 100) * 4 + 0x40);
    iVar3 = *(int *)(this + iVar2 + 100);
    iVar7 = 0;
    if (iVar3 != 0) {
      iVar8 = *(int *)(this + iVar2);
      do {
        iVar1 = iVar7 * 4;
        iVar7 = iVar7 + 1;
        *(undefined4 *)(iVar1 + (int)pvVar6) = *(undefined4 *)(iVar1 + iVar8);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    _memset((void *)(*(int *)(this + iVar2 + 100) * 4 + (int)pvVar6),0,0x40);
    if (*(void **)(this + iVar2) != (void *)0x0) {
      _free(*(void **)(this + iVar2));
    }
    *(void **)(this + iVar2) = pvVar6;
    uVar5 = *(int *)(this + iVar2 + 100) + 0x10;
    *(uint *)(this + iVar2 + 100) = uVar5;
    if (uVar10 < uVar5) {
      iVar3 = *(int *)(iVar9 + (int)pvVar6);
      while (iVar3 != 0) {
        uVar10 = uVar10 + 1;
        iVar9 = uVar10 * 4;
        if (uVar5 <= uVar10) break;
        iVar3 = *(int *)(iVar9 + *(int *)(this + iVar2));
      }
    }
  }
  *(undefined4 *)(iVar9 + *(int *)(this + iVar2)) = 1;
  return uVar10;
}

/* TemporaryAllocator__releaseTemporary @ 0x97bba0a4 (100 bytes) */
int TemporaryAllocator__releaseTemporary(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  uint param_2;
{
  int iVar1;
  undefined2 in_register_00000010;
  int iVar2;
  
  iVar2 = CONCAT22(in_register_00000010,param_1);
  iVar1 = 0;
  if ((iVar2 != 0x1404) && (iVar1 = 1, iVar2 != 0x1406)) {
    if ((iVar2 + 0x74b0U & 0xffff) < 0x15) {
      iVar1 = iVar2 + -0x8b4e;
    }
    else {
      iVar1 = 0x17;
      if (iVar2 != 0x7ffe) {
        if (iVar2 != 0x7fff) {
          return;
        }
        iVar1 = 0x18;
      }
    }
  }
  *(undefined4 *)(param_2 * 4 + *(int *)(this + iVar1 * 4)) = 0;
  return;
}

/* ParseSymbol__ClearName @ 0x97bba108 (72 bytes) */
int ParseSymbol__ClearName(this)
  unsigned char * this;
{
  if (*(void **)(this + 0x14) != (void *)0x0) {
    _free(*(void **)(this + 0x14));
  }
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  return;
}

/* ParseSymbol__ClearDirectIndex @ 0x97bba150 (68 bytes) */
int ParseSymbol__ClearDirectIndex(this)
  unsigned char * this;
{
  if (*(void **)(this + 0x18) != (void *)0x0) {
    _free(*(void **)(this + 0x18));
  }
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  return;
}

/* ParseSymbol__ParseSymbol @ 0x97bba194 (4 bytes) */
int ParseSymbol__ParseSymbol(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 8) = 0;
  *(undefined2 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x44) = 1;
  *(undefined2 *)(this + 0x30) = 0;
  *(undefined2 *)(this + 0x2e) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 4) = 0;
  return;
}

/* ParseSymbol__ParseSymbol_97bba198 @ 0x97bba198 (4 bytes) */
int ParseSymbol__ParseSymbol_97bba198(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 8) = 0;
  *(undefined2 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x44) = 1;
  *(undefined2 *)(this + 0x30) = 0;
  *(undefined2 *)(this + 0x2e) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 4) = 0;
  return;
}

/* ParseSymbol__ParseSymbol_97bba19c @ 0x97bba19c (124 bytes) */
int ParseSymbol__ParseSymbol_97bba19c(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 8) = 0;
  *(undefined2 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x28) = 0xffffffff;
  *(undefined4 *)(this + 0x44) = 1;
  *(undefined2 *)(this + 0x30) = 0;
  *(undefined2 *)(this + 0x2e) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x60) = 0;
  *(undefined4 *)(this + 0x5c) = 0;
  *(undefined4 *)(this + 0x40) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  *(undefined4 *)(this + 0xc) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 0x48) = 0;
  *(undefined4 *)(this + 0x4c) = 0;
  *(undefined4 *)(this + 0x58) = 0;
  *(undefined4 *)(this + 0x54) = 0;
  *(undefined4 *)(this + 4) = 0;
  return;
}

/* ParseSymbol___ParseSymbol @ 0x97bba218 (8 bytes) */
int ParseSymbol___ParseSymbol(this)
  unsigned char * this;
{
  ~ParseSymbol(this);
  return;
}

/* ParseSymbol___ParseSymbol_97bba220 @ 0x97bba220 (8 bytes) */
int ParseSymbol___ParseSymbol_97bba220(this)
  unsigned char * this;
{
  ~ParseSymbol(this);
  return;
}

/* ParseSymbol___ParseSymbol_97bba228 @ 0x97bba228 (116 bytes) */
int ParseSymbol___ParseSymbol_97bba228(this)
  unsigned char * this;
{
  if (*(void **)(this + 0x14) != (void *)0x0) {
    _free(*(void **)(this + 0x14));
  }
  if (*(void **)(this + 0x18) != (void *)0x0) {
    _free(*(void **)(this + 0x18));
  }
  if ((*(int *)(this + 0x44) != 0) && (*(void **)this != (void *)0x0)) {
    _free(*(void **)this);
    return;
  }
  return;
}

/* ParseSymbol__ParseSymbol_97bba29c @ 0x97bba29c (4 bytes) */
int ParseSymbol__ParseSymbol_97bba29c(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  unsigned char * pTVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  
  uVar2 = *(undefined2 *)(param_1 + 0x2c);
  uVar11 = *(undefined4 *)(param_1 + 0x28);
  uVar14 = 0;
  uVar1 = *(undefined2 *)(param_1 + 0x2e);
  pTVar5 = *(unsigned char **)(param_1 + 0xc);
  *(undefined2 *)(this + 0x30) = *(undefined2 *)(param_1 + 0x30);
  *(undefined2 *)(this + 0x2c) = uVar2;
  *(undefined4 *)(this + 0x28) = uVar11;
  *(undefined4 *)(this + 0x44) = 1;
  *(undefined2 *)(this + 0x2e) = uVar1;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  ((int (*)())ParseSymbol__SetParseTreeType)(this,pTVar5);
  uVar11 = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x48) = uVar11;
  ((int (*)())ParseSymbol__ResolveOpenGLType)(this);
  uVar11 = *(undefined4 *)(param_1 + 0x34);
  uVar10 = *(undefined4 *)(param_1 + 0x38);
  uVar13 = *(undefined4 *)(param_1 + 0x3c);
  uVar12 = *(undefined4 *)(param_1 + 0x60);
  uVar9 = *(undefined4 *)(param_1 + 0x5c);
  uVar8 = *(undefined4 *)(param_1 + 0x58);
  uVar7 = *(undefined4 *)(param_1 + 0x40);
  pcVar6 = *(char **)(param_1 + 0x14);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x34) = uVar11;
  *(undefined4 *)(this + 0x38) = uVar10;
  *(undefined4 *)(this + 0x3c) = uVar13;
  *(undefined4 *)(this + 0x60) = uVar12;
  *(undefined4 *)(this + 0x5c) = uVar9;
  *(undefined4 *)(this + 0x58) = uVar8;
  *(undefined4 *)(this + 0x40) = uVar7;
  SetName(this,pcVar6);
  *(undefined4 *)(this + 0x24) = 0;
  iVar3 = *(int *)(param_1 + 0x24);
  uVar11 = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x54) = uVar11;
  if (iVar3 != 0) {
    do {
      uVar4 = GetDirectIndex(param_1,uVar14);
      uVar14 = uVar14 + 1;
      AddDirectIndex(this,uVar4);
    } while (uVar14 < *(uint *)(param_1 + 0x24));
  }
  return;
}

/* ParseSymbol__ParseSymbol_97bba2a0 @ 0x97bba2a0 (4 bytes) */
int ParseSymbol__ParseSymbol_97bba2a0(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  unsigned char * pTVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  
  uVar2 = *(undefined2 *)(param_1 + 0x2c);
  uVar11 = *(undefined4 *)(param_1 + 0x28);
  uVar14 = 0;
  uVar1 = *(undefined2 *)(param_1 + 0x2e);
  pTVar5 = *(unsigned char **)(param_1 + 0xc);
  *(undefined2 *)(this + 0x30) = *(undefined2 *)(param_1 + 0x30);
  *(undefined2 *)(this + 0x2c) = uVar2;
  *(undefined4 *)(this + 0x28) = uVar11;
  *(undefined4 *)(this + 0x44) = 1;
  *(undefined2 *)(this + 0x2e) = uVar1;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  ((int (*)())ParseSymbol__SetParseTreeType)(this,pTVar5);
  uVar11 = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x48) = uVar11;
  ((int (*)())ParseSymbol__ResolveOpenGLType)(this);
  uVar11 = *(undefined4 *)(param_1 + 0x34);
  uVar10 = *(undefined4 *)(param_1 + 0x38);
  uVar13 = *(undefined4 *)(param_1 + 0x3c);
  uVar12 = *(undefined4 *)(param_1 + 0x60);
  uVar9 = *(undefined4 *)(param_1 + 0x5c);
  uVar8 = *(undefined4 *)(param_1 + 0x58);
  uVar7 = *(undefined4 *)(param_1 + 0x40);
  pcVar6 = *(char **)(param_1 + 0x14);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x34) = uVar11;
  *(undefined4 *)(this + 0x38) = uVar10;
  *(undefined4 *)(this + 0x3c) = uVar13;
  *(undefined4 *)(this + 0x60) = uVar12;
  *(undefined4 *)(this + 0x5c) = uVar9;
  *(undefined4 *)(this + 0x58) = uVar8;
  *(undefined4 *)(this + 0x40) = uVar7;
  SetName(this,pcVar6);
  *(undefined4 *)(this + 0x24) = 0;
  iVar3 = *(int *)(param_1 + 0x24);
  uVar11 = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x54) = uVar11;
  if (iVar3 != 0) {
    do {
      uVar4 = GetDirectIndex(param_1,uVar14);
      uVar14 = uVar14 + 1;
      AddDirectIndex(this,uVar4);
    } while (uVar14 < *(uint *)(param_1 + 0x24));
  }
  return;
}

/* ParseSymbol__ParseSymbol_97bba2a4 @ 0x97bba2a4 (296 bytes) */
int ParseSymbol__ParseSymbol_97bba2a4(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  unsigned char * pTVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  
  uVar2 = *(undefined2 *)(param_1 + 0x2c);
  uVar11 = *(undefined4 *)(param_1 + 0x28);
  uVar14 = 0;
  uVar1 = *(undefined2 *)(param_1 + 0x2e);
  pTVar5 = *(unsigned char **)(param_1 + 0xc);
  *(undefined2 *)(this + 0x30) = *(undefined2 *)(param_1 + 0x30);
  *(undefined2 *)(this + 0x2c) = uVar2;
  *(undefined4 *)(this + 0x28) = uVar11;
  *(undefined4 *)(this + 0x44) = 1;
  *(undefined2 *)(this + 0x2e) = uVar1;
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)this = 0;
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 0x50) = 0;
  ((int (*)())ParseSymbol__SetParseTreeType)(this,pTVar5);
  uVar11 = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(this + 0x48) = uVar11;
  ((int (*)())ParseSymbol__ResolveOpenGLType)(this);
  uVar11 = *(undefined4 *)(param_1 + 0x34);
  uVar10 = *(undefined4 *)(param_1 + 0x38);
  uVar13 = *(undefined4 *)(param_1 + 0x3c);
  uVar12 = *(undefined4 *)(param_1 + 0x60);
  uVar9 = *(undefined4 *)(param_1 + 0x5c);
  uVar8 = *(undefined4 *)(param_1 + 0x58);
  uVar7 = *(undefined4 *)(param_1 + 0x40);
  pcVar6 = *(char **)(param_1 + 0x14);
  *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x34) = uVar11;
  *(undefined4 *)(this + 0x38) = uVar10;
  *(undefined4 *)(this + 0x3c) = uVar13;
  *(undefined4 *)(this + 0x60) = uVar12;
  *(undefined4 *)(this + 0x5c) = uVar9;
  *(undefined4 *)(this + 0x58) = uVar8;
  *(undefined4 *)(this + 0x40) = uVar7;
  SetName(this,pcVar6);
  *(undefined4 *)(this + 0x24) = 0;
  iVar3 = *(int *)(param_1 + 0x24);
  uVar11 = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x54) = uVar11;
  if (iVar3 != 0) {
    do {
      uVar4 = GetDirectIndex(param_1,uVar14);
      uVar14 = uVar14 + 1;
      AddDirectIndex(this,uVar4);
    } while (uVar14 < *(uint *)(param_1 + 0x24));
  }
  return;
}

/* ParseSymbol__operator_ @ 0x97bba3cc (328 bytes) */
int ParseSymbol__operator_(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  unsigned char * pTVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  
  if (this != param_1) {
    uVar1 = *(undefined2 *)(param_1 + 0x30);
    uVar2 = *(undefined2 *)(param_1 + 0x2c);
    pcVar5 = *(char **)(param_1 + 0x14);
    *(undefined2 *)(this + 0x2e) = *(undefined2 *)(param_1 + 0x2e);
    *(undefined2 *)(this + 0x30) = uVar1;
    *(undefined2 *)(this + 0x2c) = uVar2;
    SetName(this,pcVar5);
    ClearDirectIndex(this);
    uVar14 = 0;
    if (*(int *)(param_1 + 0x24) != 0) {
      do {
        uVar4 = GetDirectIndex(param_1,uVar14);
        AddDirectIndex(this,uVar4);
        uVar14 = uVar14 + 1;
      } while (uVar14 < *(uint *)(param_1 + 0x24));
    }
    pTVar6 = *(unsigned char **)(param_1 + 0xc);
    *(undefined4 *)(this + 0x28) = *(undefined4 *)(param_1 + 0x28);
    ((int (*)())ParseSymbol__SetParseTreeType)(this,pTVar6);
    uVar3 = *(undefined4 *)(param_1 + 0x48);
    *(undefined4 *)(this + 0x10) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(this + 0x48) = uVar3;
    ((int (*)())ParseSymbol__ResolveOpenGLType)(this);
    uVar3 = *(undefined4 *)(param_1 + 0x54);
    uVar11 = *(undefined4 *)(param_1 + 0x34);
    uVar13 = *(undefined4 *)(param_1 + 0x38);
    uVar12 = *(undefined4 *)(param_1 + 0x3c);
    uVar10 = *(undefined4 *)(param_1 + 0x60);
    uVar9 = *(undefined4 *)(param_1 + 0x5c);
    uVar8 = *(undefined4 *)(param_1 + 0x58);
    uVar7 = *(undefined4 *)(param_1 + 0x40);
    *(undefined4 *)(this + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
    *(undefined4 *)(this + 0x34) = uVar11;
    *(undefined4 *)(this + 0x38) = uVar13;
    *(undefined4 *)(this + 0x3c) = uVar12;
    *(undefined4 *)(this + 0x60) = uVar10;
    *(undefined4 *)(this + 0x5c) = uVar9;
    *(undefined4 *)(this + 0x58) = uVar8;
    *(undefined4 *)(this + 0x40) = uVar7;
    *(undefined4 *)(this + 0x54) = uVar3;
    *(undefined4 *)(this + 8) = 0;
    *(undefined4 *)(this + 0x50) = 0;
    *(undefined4 *)(this + 4) = 0;
    if ((*(void **)this != (void *)0x0) && (*(int *)(this + 0x44) != 0)) {
      _free(*(void **)this);
    }
    *(undefined4 *)this = 0;
    *(undefined4 *)(this + 0x44) = 1;
  }
  return this;
}

/* operator___97bba514 @ 0x97bba514 (148 bytes) */
int operator___97bba514(param_1, param_2)
  unsigned char * param_1;
  unsigned char * param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((((*(int *)(param_1 + 0x28) == -1) || (*(int *)(param_2 + 0x28) == -1)) ||
      ((*(int *)(param_1 + 0x28) == *(int *)(param_2 + 0x28) &&
       (*(int *)(param_1 + 0x48) == *(int *)(param_2 + 0x48))))) &&
     (((*(int *)(param_1 + 0x1c) == *(int *)(param_2 + 0x1c) &&
       (*(size_t *)(param_1 + 0x20) == *(size_t *)(param_2 + 0x20))) &&
      (iVar1 = _strncmp(*(char **)(param_1 + 0x14),*(char **)(param_2 + 0x14),
                        *(size_t *)(param_1 + 0x20)), iVar1 == 0)))) {
    uVar2 = 1;
  }
  return uVar2;
}

/* ParseSymbol__ResolveOpenGLType @ 0x97bba5a8 (616 bytes) */
int ParseSymbol__ResolveOpenGLType(this)
  unsigned char * this;
{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  if (*(int **)(this + 0xc) == (int *)0x0) {
    return;
  }
  iVar5 = 0;
  iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x38))();
  if ((iVar3 != 0) && (*(int *)(this + 0x48) == 0)) {
    iVar5 = 1;
  }
  uVar2 = 0x7fff;
  *(int *)(this + 0x4c) = iVar5;
  if (iVar5 == 0) {
    uVar4 = (**(code **)(**(int **)(this + 0xc) + 0x20))();
    switch(uVar4) {
    default:
      goto switchD_97bba640_caseD_0;
    case 1:
      iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x34))();
      if (iVar3 == 0) {
        iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x2c))();
        if (iVar3 == 2) {
          uVar2 = 0x8b50;
        }
        else if (iVar3 < 3) {
          if (iVar3 != 1) {
            return;
          }
          uVar2 = 0x1406;
        }
        else {
          if (iVar3 != 3) {
            bVar1 = iVar3 == 4;
            uVar2 = 0x8b52;
            goto LAB_97bba7d4;
          }
          uVar2 = 0x8b51;
        }
      }
      else {
        iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x2c))();
        if (iVar3 == 3) {
          uVar2 = 0x8b5b;
        }
        else if (iVar3 < 4) {
          if (iVar3 != 2) {
            return;
          }
          uVar2 = 0x8b5a;
        }
        else {
          bVar1 = iVar3 == 4;
          uVar2 = 0x8b5c;
LAB_97bba7d4:
          if (!bVar1) {
            return;
          }
        }
      }
      break;
    case 2:
      iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x2c))();
      if (iVar3 == 2) {
        uVar2 = 0x8b53;
      }
      else if (iVar3 < 3) {
        if (iVar3 != 1) {
          return;
        }
        uVar2 = 0x1404;
      }
      else {
        if (iVar3 != 3) {
          bVar1 = iVar3 == 4;
          uVar2 = 0x8b55;
          goto LAB_97bba7d4;
        }
        uVar2 = 0x8b54;
      }
      break;
    case 3:
      iVar3 = (**(code **)(**(int **)(this + 0xc) + 0x2c))();
      if (iVar3 == 2) {
        uVar2 = 0x8b57;
      }
      else if (iVar3 < 3) {
        if (iVar3 != 1) {
          return;
        }
        uVar2 = 0x8b56;
      }
      else {
        if (iVar3 != 3) {
          bVar1 = iVar3 == 4;
          uVar2 = 0x8b59;
          goto LAB_97bba7d4;
        }
        uVar2 = 0x8b58;
      }
      break;
    case 5:
      uVar2 = 0x8b5d;
      break;
    case 6:
      uVar2 = 0x8b5e;
      break;
    case 7:
      uVar2 = 0x8b5f;
      break;
    case 8:
      uVar2 = 0x8b60;
      break;
    case 9:
      uVar2 = 0x8b61;
      break;
    case 10:
      uVar2 = 0x8b62;
      break;
    case 0xb:
      uVar2 = 0x8b63;
      break;
    case 0xc:
      uVar2 = 0x8b64;
      break;
    case 0xe:
      uVar2 = 0x7ffe;
    }
  }
  *(undefined2 *)(this + 0x2c) = uVar2;
switchD_97bba640_caseD_0:
  return;
}

/* ParseSymbol__SetParseTreeType @ 0x97bba850 (120 bytes) */
int ParseSymbol__SetParseTreeType(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined2 uVar1;
  int iVar2;
  
  *(unsigned char **)(this + 0xc) = param_1;
  if (param_1 != (unsigned char *)0x0) {
    iVar2 = (**(code **)(*(int *)param_1 + 0x38))(param_1);
    uVar1 = 1;
    if (iVar2 != 0) {
      uVar1 = *(undefined2 *)(param_1 + 6);
    }
    *(undefined2 *)(this + 0x2e) = uVar1;
    ((int (*)())ParseSymbol__ResolveOpenGLType)(this);
    return;
  }
  return;
}

/* ParseSymbol__SetChunk @ 0x97bba8c8 (84 bytes) */
int ParseSymbol__SetChunk(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  if ((*(void **)this != (void *)0x0) && (*(int *)(this + 0x44) != 0)) {
    _free(*(void **)this);
  }
  *(unsigned char **)this = param_1;
  *(undefined4 *)(this + 0x44) = 1;
  return;
}

/* ParseSymbol__SetArrayPositionFromLastIndex @ 0x97bba91c (56 bytes) */
int ParseSymbol__SetArrayPositionFromLastIndex(this)
  unsigned char * this;
{
  undefined2 uVar1;
  
  uVar1 = GetDirectIndex(this,*(int *)(this + 0x24) - 1);
  *(undefined2 *)(this + 0x30) = uVar1;
  return;
}

/* ParseSymbol__CatName @ 0x97bba954 (208 bytes) */
int ParseSymbol__CatName(this, param_1)
  unsigned char * this;
  char *param_1;
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  char *pcVar5;
  int iVar6;
  
  if (param_1 != (char *)0x0) {
    sVar4 = _strlen(param_1);
    pcVar5 = _malloc(sVar4 + *(int *)(this + 0x20) + 1);
    if (*(char **)(this + 0x14) != (char *)0x0) {
      _strncpy(pcVar5,*(char **)(this + 0x14),*(int *)(this + 0x20) + 1);
    }
    _strncpy(pcVar5 + *(int *)(this + 0x20),param_1,sVar4 + 1);
    *(size_t *)(this + 0x20) = *(int *)(this + 0x20) + sVar4;
    _free(*(void **)(this + 0x14));
    iVar2 = *(int *)(this + 0x20);
    iVar6 = 0;
    *(undefined4 *)(this + 0x1c) = 0;
    *(char **)(this + 0x14) = pcVar5;
    if (iVar2 != 0) {
      iVar3 = 0;
      do {
        pcVar1 = pcVar5 + iVar6;
        iVar6 = iVar6 + 1;
        iVar3 = iVar3 + *pcVar1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      *(int *)(this + 0x1c) = iVar3;
    }
  }
  return;
}

/* ParseSymbol__SetName @ 0x97bbaa24 (156 bytes) */
int ParseSymbol__SetName(this, param_1)
  unsigned char * this;
  char *param_1;
{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  int iVar4;
  
  ClearName(this);
  if ((param_1 != (char *)0x0) && (sVar2 = _strlen(param_1), 0 < (int)sVar2)) {
    *(size_t *)(this + 0x20) = sVar2;
    pcVar3 = _malloc(sVar2 + 1);
    *(char **)(this + 0x14) = pcVar3;
    _strncpy(pcVar3,param_1,*(int *)(this + 0x20) + 1);
    iVar1 = *(int *)(this + 0x20);
    iVar4 = 0;
    if (iVar1 != 0) {
      do {
        pcVar3 = (char *)(*(int *)(this + 0x14) + iVar4);
        iVar4 = iVar4 + 1;
        *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + (int)*pcVar3;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return;
}

/* ParseSymbol__RemoveNameBackToChar @ 0x97bbaac0 (132 bytes) */
int ParseSymbol__RemoveNameBackToChar(this, param_1)
  unsigned char * this;
  int param_1;
{
  char *pcVar1;
  bool bVar2;
  undefined3 in_register_00000010;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(this + 0x20);
  bVar2 = false;
  if (-1 < iVar3) {
    do {
      if ((int)*(char *)(*(int *)(this + 0x14) + iVar3) == CONCAT31(in_register_00000010,param_1)) {
        bVar2 = true;
      }
      *(undefined1 *)(*(int *)(this + 0x14) + iVar3) = 0;
      iVar3 = iVar3 + -1;
    } while ((-1 < iVar3) && (!bVar2));
  }
  iVar3 = iVar3 + 1;
  iVar4 = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(int *)(this + 0x20) = iVar3;
  if (0 < iVar3) {
    do {
      pcVar1 = (char *)(*(int *)(this + 0x14) + iVar4);
      iVar4 = iVar4 + 1;
      *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + (int)*pcVar1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    return;
  }
  return;
}

/* ParseSymbol__ChangeArrayNameForArrayIndex @ 0x97bbab44 (424 bytes) */
int ParseSymbol__ChangeArrayNameForArrayIndex(param_1, param_2)
  uint param_1;
  uint param_2;
{
  char cVar1;
  uint uVar2;
  size_t sVar3;
  char *pcVar4;
  void *pvVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  char acStack_30 [28];
  
  _sprintf(acStack_30,"%u");
  sVar3 = _strlen(acStack_30);
  iVar9 = 0;
  pcVar4 = _malloc(*(int *)(param_1 + 0x20) + sVar3 + 1);
  uVar2 = 0;
  iVar8 = 0;
  if (param_2 != 0xffffffff) {
    pcVar6 = *(char **)(param_1 + 0x14);
    cVar1 = *pcVar6;
    while (cVar1 != '\0') {
      if (cVar1 == '[') {
        uVar2 = uVar2 + 1;
      }
      pcVar4[iVar9] = cVar1;
      iVar8 = iVar8 + 1;
      iVar9 = iVar9 + 1;
      if (param_2 + 1 <= uVar2) break;
      cVar1 = pcVar6[iVar8];
    }
  }
  pcVar4[iVar9] = '\0';
  _strcat(pcVar4,acStack_30);
  cVar1 = pcVar4[iVar9];
  while (cVar1 != '\0') {
    iVar9 = iVar9 + 1;
    cVar1 = pcVar4[iVar9];
  }
  iVar7 = *(int *)(param_1 + 0x14);
  cVar1 = *(char *)(iVar7 + iVar8);
  while ((cVar1 != '\0' && (cVar1 != ']'))) {
    iVar8 = iVar8 + 1;
    cVar1 = *(char *)(iVar7 + iVar8);
  }
  cVar1 = *(char *)(iVar7 + iVar8);
  while (cVar1 != '\0') {
    pcVar4[iVar9] = cVar1;
    iVar8 = iVar8 + 1;
    iVar9 = iVar9 + 1;
    cVar1 = *(char *)(iVar7 + iVar8);
  }
  pvVar5 = *(void **)(param_1 + 0x14);
  pcVar4[iVar9] = *(char *)(iVar7 + iVar8);
  if (pvVar5 != (void *)0x0) {
    _free(pvVar5);
  }
  *(int *)(param_1 + 0x20) = iVar9;
  iVar8 = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(char **)(param_1 + 0x14) = pcVar4;
  for (; iVar9 != 0; iVar9 = iVar9 + -1) {
    pcVar6 = pcVar4 + iVar8;
    iVar8 = iVar8 + 1;
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + (int)*pcVar6;
  }
  return;
}

/* ParseSymbol__RemoveArrayIndex @ 0x97bbacec (36 bytes) */
int ParseSymbol__RemoveArrayIndex(this)
  unsigned char * this;
{
  if (*(char *)(*(int *)(this + 0x14) + *(int *)(this + 0x20) + -1) != ']') {
    return;
  }
  RemoveNameBackToChar(this,'[');
  return;
}

/* ParseSymbol__TrimNameToBase @ 0x97bbad10 (156 bytes) */
int ParseSymbol__TrimNameToBase(this)
  unsigned char * this;
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  
  pcVar2 = *(char **)(this + 0x14);
  iVar3 = 0;
  cVar1 = *pcVar2;
  if ((cVar1 != '\0') && (cVar1 != '[')) {
    while (cVar1 != '.') {
      iVar3 = iVar3 + 1;
      cVar1 = pcVar2[iVar3];
      if ((cVar1 == '\0') || (cVar1 == '[')) break;
    }
  }
  pcVar2[iVar3] = '\0';
  *(int *)(this + 0x20) = iVar3;
  iVar4 = 0;
  *(undefined4 *)(this + 0x1c) = 0;
  if (iVar3 < 1) {
    return;
  }
  do {
    pcVar2 = (char *)(*(int *)(this + 0x14) + iVar4);
    iVar4 = iVar4 + 1;
    *(int *)(this + 0x1c) = *(int *)(this + 0x1c) + (int)*pcVar2;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}

