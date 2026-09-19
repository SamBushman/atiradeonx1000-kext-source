#include "decls.h"

/* BindingTable__NextAttribBinding @ 0x97bb0ecc (24 bytes) */
int BindingTable__NextAttribBinding(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  undefined4 uVar1;
  
  if (param_1 != (unsigned char *)0x0) {
    uVar1 = Binding__GetNextBinding(param_1);
    return uVar1;
  }
  return *(undefined4 *)(this + 0xc);
}

/* BindingTable__FindAttribBinding @ 0x97bb0ee4 (116 bytes) */
int BindingTable__FindAttribBinding(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  Binding *this_00;
  
  iVar1 = Binding__GetHash(param_1,*(uint *)this);
  this_00 = *(Binding **)(iVar1 * 4 + *(int *)(this + 0x10));
  while ((this_00 != (unsigned char *)0x0 && (iVar1 = operator__(this_00,param_1), iVar1 != 1))) {
    this_00 = (unsigned char *)Binding__GetNextBindingInHash(this_00);
  }
  return this_00;
}

/* BindingTable__FindAttribBindingLocationByName @ 0x97bb0f58 (228 bytes) */
int BindingTable__FindAttribBindingLocationByName(this, param_1)
  unsigned char *this;
  char *param_1;
{
  Binding *this_00;
  int iVar1;
  undefined4 uVar2;
  Binding *this_01;
  
  if (param_1 != (char *)0x0) {
    this_00 = operator_new(0x38);
    Binding__Binding(this_00);
    if (this_00 != (unsigned char *)0x0) {
      Binding__SetName(this_00,param_1);
      iVar1 = Binding__GetHash(this_00,*(uint *)this);
      this_01 = *(Binding **)(iVar1 * 4 + *(int *)(this + 0x10));
      while ((this_01 != (unsigned char *)0x0 && (iVar1 = operator__(this_01,this_00), iVar1 != 1))) {
        this_01 = (unsigned char *)Binding__GetNextBindingInHash(this_01);
      }
      Binding___Binding(this_00);
      operator_delete(this_00);
      if (this_01 != (unsigned char *)0x0) {
        uVar2 = Binding__GetLocation(this_01);
        return uVar2;
      }
    }
  }
  return 0xffffffff;
}

/* BindingTable__GetAttribBindingNameByLocation @ 0x97bb103c (92 bytes) */
int BindingTable__GetAttribBindingNameByLocation(this, param_1)
  unsigned char *this;
  long param_1;
{
  int iVar1;
  Binding *this_00;
  
  this_00 = *(Binding **)(this + 0xc);
  while( true ) {
    if (this_00 == (unsigned char *)0x0) {
      return 0;
    }
    iVar1 = Binding__GetLocation(this_00);
    if (iVar1 == param_1) break;
    this_00 = (unsigned char *)Binding__GetNextBinding(this_00);
  }
  return *(undefined4 *)(this_00 + 8);
}

/* BindingTable__GetAttribBindingByIndex @ 0x97bb1098 (88 bytes) */
int BindingTable__GetAttribBindingByIndex(this, param_1)
  unsigned char *this;
  long param_1;
{
  int iVar1;
  Binding *this_00;
  
  this_00 = *(Binding **)(this + 0xc);
  while ((this_00 != (unsigned char *)0x0 && (iVar1 = Binding__GetActiveIndex(this_00), iVar1 != param_1))
        ) {
    this_00 = (unsigned char *)Binding__GetNextBinding(this_00);
  }
  return this_00;
}

/* BindingTable__InsertSingleUniform @ 0x97bb10f0 (452 bytes) */
int BindingTable__InsertSingleUniform(this, param_1, param_2)
  unsigned char *this;
  unsigned char *param_1;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  Binding *pBVar3;
  Binding *pBVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar1 = 0;
  if (param_1 != (unsigned char *)0x0) {
    iVar6 = 0;
    iVar7 = 0;
    pBVar3 = *(Binding **)(this + 0x14);
    if (*(Binding **)(this + 0x14) == (unsigned char *)0x0) {
      *(Binding **)(this + 0x14) = param_1;
    }
    else {
      do {
        pBVar4 = pBVar3;
        iVar2 = Binding__GetLocation(pBVar4);
        if (-1 < iVar2) {
          iVar7 = Binding__GetBindingSlots(pBVar4);
          iVar6 = iVar2;
        }
        pBVar3 = (unsigned char *)Binding__GetNextBinding(pBVar4);
      } while (pBVar3 != (unsigned char *)0x0);
      Binding__SetNextBinding(pBVar4,param_1);
    }
    Binding__SetLocation(param_1,iVar6 + iVar7);
    iVar6 = Binding__GetHash(param_1,*(uint *)this);
    pBVar3 = *(Binding **)(iVar6 * 4 + *(int *)(this + 0x18));
    if (pBVar3 == (unsigned char *)0x0) {
      *(Binding **)(iVar6 * 4 + *(int *)(this + 0x18)) = param_1;
    }
    else {
      do {
        pBVar4 = pBVar3;
        pBVar3 = (unsigned char *)Binding__GetNextBindingInHash(pBVar4);
      } while (pBVar3 != (unsigned char *)0x0);
      Binding__SetNextBindingInHash(pBVar4,param_1);
    }
    iVar6 = *(int *)(this + 0x20);
    *(int *)(this + 0x20) = iVar6 + 1;
    Binding__SetActiveIndex(param_1,iVar6);
    iVar6 = Binding__IsBuiltIn(param_1);
    if (iVar6 == 0) {
      iVar6 = Binding__GetBindingSlots(param_1);
      *(int *)(this + 0x24) = *(int *)(this + 0x24) + iVar6;
    }
    if (param_2 != 0) {
      param_1[0x35] = (Binding)0x1;
      iVar6 = Binding__GetBindingSlots(param_1);
      *(int *)(this + 0x30) = *(int *)(this + 0x30) + iVar6;
    }
    else {
      param_1[0x34] = (Binding)0x1;
      iVar6 = Binding__GetBindingSlots(param_1);
      *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + iVar6;
    }
    uVar5 = Binding__GetOpenGLType(param_1);
    if ((0x8b5c < uVar5) && (uVar5 < 0x8b65)) {
      if (param_2 != 0) {
        *(int *)(this + 0x44) = *(int *)(this + 0x44) + 1;
      }
      else {
        *(int *)(this + 0x40) = *(int *)(this + 0x40) + 1;
      }
    }
    if (*(int *)(this + 0x3c) < *(int *)(param_1 + 0x10) + 1) {
      *(int *)(this + 0x3c) = *(int *)(param_1 + 0x10) + 1;
    }
    uVar1 = 1;
  }
  return uVar1;
}

/* BindingTable__AddSingleUniformReference @ 0x97bb12b4 (184 bytes) */
int BindingTable__AddSingleUniformReference(this, param_1, param_2)
  unsigned char *this;
  unsigned char *param_1;
  int param_2;
{
  int iVar1;
  uint uVar2;
  
  if (param_2 != 0) {
    param_1[0x35] = (Binding)0x1;
    iVar1 = Binding__GetBindingSlots(param_1);
    *(int *)(this + 0x30) = *(int *)(this + 0x30) + iVar1;
  }
  else {
    param_1[0x34] = (Binding)0x1;
    iVar1 = Binding__GetBindingSlots(param_1);
    *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + iVar1;
  }
  uVar2 = Binding__GetOpenGLType(param_1);
  if ((0x8b5c < uVar2) && (uVar2 < 0x8b65)) {
    if (param_2 != 0) {
      *(int *)(this + 0x44) = *(int *)(this + 0x44) + 1;
    }
    else {
      *(int *)(this + 0x40) = *(int *)(this + 0x40) + 1;
    }
  }
  return;
}

/* BindingTable__InsertUniformArray @ 0x97bb136c (944 bytes) */
int BindingTable__InsertUniformArray(this, param_1, param_2, param_3, param_4, param_5)
  unsigned char *this;
  unsigned char *param_1;
  int param_2;
  int param_3;
  int param_4;
  ParseSymbolTable **param_5;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  Binding *this_00;
  ParseSymbolTable *pPVar5;
  int iVar6;
  int iVar7;
  Binding *pBVar8;
  Binding *pBVar9;
  uint uVar10;
  ulong uVar11;
  int iVar12;
  ParseSymbolTable **ppPVar13;
  char acStack_90 [32];
  char acStack_70 [32];
  undefined8 local_50;
  
  uVar2 = 0;
  if (param_1 != (unsigned char *)0x0) {
    local_50 = DAT_97c38f98;
    iVar3 = Binding__GetDecSize(param_1);
    while (iVar3 = iVar3 + -1, -1 < iVar3) {
      Binding__RemoveNameBackToChar(param_1,'[');
      _sprintf(acStack_90,"[%d]",iVar3);
      Binding__CatName(param_1,acStack_90);
      for (iVar12 = param_3; iVar12 < param_4; iVar12 = iVar12 + 1) {
        if (((param_5[iVar12] != (unsigned char *)0x0) &&
            (iVar4 = ParseSymbolTable__FindSymbolByName((char *)param_5[iVar12]), iVar4 != 0)) &&
           (*(int *)((int)&local_50 + iVar12 * 4) < iVar3)) {
          *(int *)((int)&local_50 + iVar12 * 4) = iVar3;
        }
      }
    }
    (*(unsigned int *)((unsigned char *)&(local_50) + 0)) = (int)((ulonglong)local_50 >> 0x20);
    iVar3 = (*(unsigned int *)((unsigned char *)&(local_50) + 4));
    if ((*(unsigned int *)((unsigned char *)&(local_50) + 4)) < (*(unsigned int *)((unsigned char *)&(local_50) + 0))) {
      iVar3 = (*(unsigned int *)((unsigned char *)&(local_50) + 0));
    }
    iVar12 = 0;
    Binding__RemoveNameBackToChar(param_1,'[');
    if (-1 < iVar3) {
      uVar11 = iVar3 + 1;
      do {
        bVar1 = true;
        this_00 = operator_new(0x38);
        Binding__Binding(this_00,param_1);
        _sprintf(acStack_70,"[%d]",iVar12);
        Binding__CatName(this_00,acStack_70);
        iVar4 = Binding__IsBuiltIn(param_1);
        if (iVar4 != 0) {
          bVar1 = false;
          if (param_3 < param_4) {
            ppPVar13 = param_5 + param_3;
            iVar4 = param_3;
            do {
              pPVar5 = *ppPVar13;
              ppPVar13 = ppPVar13 + 1;
              if ((pPVar5 != (unsigned char *)0x0) &&
                 (iVar6 = ParseSymbolTable__FindSymbolByName((char *)pPVar5), iVar6 != 0))
              goto LAB_97bb1538;
              iVar4 = iVar4 + 1;
            } while (iVar4 < param_4);
          }
          if (this_00 != (unsigned char *)0x0) {
            Binding___Binding(this_00);
            operator_delete(this_00);
          }
        }
        if (bVar1) {
LAB_97bb1538:
          iVar4 = 0;
          iVar6 = 0;
          pBVar8 = *(Binding **)(this + 0x14);
          if (*(Binding **)(this + 0x14) == (unsigned char *)0x0) {
            *(Binding **)(this + 0x14) = this_00;
          }
          else {
            do {
              pBVar9 = pBVar8;
              iVar7 = Binding__GetLocation(pBVar9);
              if (-1 < iVar7) {
                iVar6 = Binding__GetBindingSlots(pBVar9);
                iVar4 = iVar7;
              }
              pBVar8 = (unsigned char *)Binding__GetNextBinding(pBVar9);
            } while (pBVar8 != (unsigned char *)0x0);
            Binding__SetNextBinding(pBVar9,this_00);
          }
          Binding__SetLocation(this_00,iVar4 + iVar6);
          iVar4 = Binding__GetHash(this_00,*(uint *)this);
          pBVar8 = *(Binding **)(iVar4 * 4 + *(int *)(this + 0x18));
          if (pBVar8 == (unsigned char *)0x0) {
            *(Binding **)(iVar4 * 4 + *(int *)(this + 0x18)) = this_00;
          }
          else {
            do {
              pBVar9 = pBVar8;
              pBVar8 = (unsigned char *)Binding__GetNextBindingInHash(pBVar9);
            } while (pBVar8 != (unsigned char *)0x0);
            Binding__SetNextBindingInHash(pBVar9,this_00);
          }
          Binding__SetActualSize(this_00,uVar11);
          if (iVar12 == 0) {
            iVar4 = *(int *)(this + 0x20);
            *(int *)(this + 0x20) = iVar4 + 1;
            Binding__SetActiveIndex(this_00,iVar4);
          }
          iVar4 = Binding__IsBuiltIn(this_00);
          if (iVar4 == 0) {
            iVar4 = Binding__GetBindingSlots(this_00);
            *(int *)(this + 0x24) = *(int *)(this + 0x24) + iVar4;
          }
          if (iVar12 <= (*(unsigned int *)((unsigned char *)&(local_50) + 0))) {
            this_00[0x34] = (Binding)0x1;
            iVar4 = Binding__GetBindingSlots(this_00);
            *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + iVar4;
            uVar10 = Binding__GetOpenGLType(this_00);
            if ((0x8b5c < uVar10) && (uVar10 < 0x8b65)) {
              *(int *)(this + 0x40) = *(int *)(this + 0x40) + 1;
            }
          }
          if (iVar12 <= (*(unsigned int *)((unsigned char *)&(local_50) + 4))) {
            this_00[0x35] = (Binding)0x1;
            iVar4 = Binding__GetBindingSlots(param_1);
            *(int *)(this + 0x30) = *(int *)(this + 0x30) + iVar4;
            uVar10 = Binding__GetOpenGLType(this_00);
            if ((0x8b5c < uVar10) && (uVar10 < 0x8b65)) {
              *(int *)(this + 0x44) = *(int *)(this + 0x44) + 1;
            }
          }
          if (*(int *)(this + 0x3c) < *(int *)(this_00 + 0x10) + 1) {
            *(int *)(this + 0x3c) = *(int *)(this_00 + 0x10) + 1;
          }
        }
        iVar12 = iVar12 + 1;
        uVar11 = uVar11 - 1;
      } while (iVar12 <= iVar3);
    }
    Binding___Binding(param_1);
    operator_delete(param_1);
    uVar2 = 1;
  }
  return uVar2;
}

/* BindingTable__NextUniformBinding @ 0x97bb171c (24 bytes) */
int BindingTable__NextUniformBinding(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  undefined4 uVar1;
  
  if (param_1 != (unsigned char *)0x0) {
    uVar1 = Binding__GetNextBinding(param_1);
    return uVar1;
  }
  return *(undefined4 *)(this + 0x14);
}

/* BindingTable__FindUniformBinding @ 0x97bb1734 (116 bytes) */
int BindingTable__FindUniformBinding(this, param_1)
  unsigned char *this;
  unsigned char *param_1;
{
  int iVar1;
  Binding *this_00;
  
  iVar1 = Binding__GetHash(param_1,*(uint *)this);
  this_00 = *(Binding **)(iVar1 * 4 + *(int *)(this + 0x18));
  while ((this_00 != (unsigned char *)0x0 && (iVar1 = operator__(this_00,param_1), iVar1 != 1))) {
    this_00 = (unsigned char *)Binding__GetNextBindingInHash(this_00);
  }
  return this_00;
}

/* BindingTable__FindUniformBindingByName @ 0x97bb17a8 (116 bytes) */
int BindingTable__FindUniformBindingByName(this, param_1)
  unsigned char *this;
  char *param_1;
{
  Binding *this_00;
  
  if (param_1 != (char *)0x0) {
    this_00 = operator_new(0x38);
    Binding__Binding(this_00);
    if (this_00 != (unsigned char *)0x0) {
      Binding__SetName(this_00,param_1);
      ((int (*)())BindingTable__FindUniformBinding)(this,this_00);
      Binding___Binding(this_00);
      operator_delete(this_00);
    }
  }
  return 0;
}

/* BindingTable__FindClientUniformBindingLocationByName @ 0x97bb181c (264 bytes) */
int BindingTable__FindClientUniformBindingLocationByName(this, param_1)
  unsigned char *this;
  char *param_1;
{
  int iVar1;
  Binding *this_00;
  Binding *pBVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  if ((param_1 != (char *)0x0) && (iVar1 = _memcmp(param_1,"gl_",3), iVar1 != 0)) {
    this_00 = operator_new(0x38);
    Binding__Binding(this_00);
    if (this_00 != (unsigned char *)0x0) {
      Binding__SetName(this_00,param_1);
      pBVar2 = (unsigned char *)((int (*)())BindingTable__FindUniformBinding)(this,this_00);
      if (pBVar2 == (unsigned char *)0x0) {
        if (*(char *)(*(int *)(this_00 + 8) + *(int *)(this_00 + 0x10) + -1) != ']') {
          Binding__CatName(this_00,"[0]");
          pBVar2 = (unsigned char *)((int (*)())BindingTable__FindUniformBinding)(this,this_00);
          if (pBVar2 != (unsigned char *)0x0) {
            uVar3 = Binding__GetLocation(pBVar2);
          }
        }
      }
      else {
        uVar3 = Binding__GetLocation(pBVar2);
      }
      Binding___Binding(this_00);
      operator_delete(this_00);
    }
  }
  return uVar3;
}

/* BindingTable__FindUniformBindingByLocation @ 0x97bb1924 (160 bytes) */
int BindingTable__FindUniformBindingByLocation(this, param_1)
  unsigned char *this;
  long param_1;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  Binding *this_00;
  
  this_00 = *(Binding **)(this + 0x14);
  while( true ) {
    if (this_00 == (unsigned char *)0x0) {
      return (unsigned char *)0x0;
    }
    iVar1 = Binding__GetLocation(this_00);
    if (iVar1 == param_1) break;
    if ((iVar1 < param_1) &&
       (iVar2 = Binding__GetBindingSlots(this_00), (uint)param_1 < (uint)(iVar1 + iVar2))) {
      uVar3 = Binding__GetBindingBasicSize(this_00);
      if (param_1 - iVar1 != ((uint)(param_1 - iVar1) / uVar3) * uVar3) {
        return (unsigned char *)0x0;
      }
      return this_00;
    }
    this_00 = (unsigned char *)Binding__GetNextBinding(this_00);
  }
  return this_00;
}

/* BindingTable__FindUniformBindingByIndex @ 0x97bb19c4 (88 bytes) */
int BindingTable__FindUniformBindingByIndex(this, param_1)
  unsigned char *this;
  long param_1;
{
  int iVar1;
  Binding *this_00;
  
  this_00 = *(Binding **)(this + 0x14);
  while ((this_00 != (unsigned char *)0x0 && (iVar1 = Binding__GetActiveIndex(this_00), iVar1 != param_1))
        ) {
    this_00 = (unsigned char *)Binding__GetNextBinding(this_00);
  }
  return this_00;
}

/* BindingTable__GetNumActiveAttributeBindings @ 0x97bb1a1c (8 bytes) */
int BindingTable__GetNumActiveAttributeBindings(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0x1c);
}

/* BindingTable__GetNumActiveUniformBindings @ 0x97bb1a24 (8 bytes) */
int BindingTable__GetNumActiveUniformBindings(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0x20);
}

/* BindingTable__GetSizeActiveUserUniforms @ 0x97bb1a2c (8 bytes) */
int BindingTable__GetSizeActiveUserUniforms(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0x24);
}

/* BindingTable__GetSizeActiveUserAttributes @ 0x97bb1a34 (8 bytes) */
int BindingTable__GetSizeActiveUserAttributes(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0x28);
}

/* BindingTable__GetSizeActiveVertexUniforms @ 0x97bb1a3c (8 bytes) */
int BindingTable__GetSizeActiveVertexUniforms(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0x2c);
}

/* BindingTable__GetSizeActiveFragmentUniforms @ 0x97bb1a44 (8 bytes) */
int BindingTable__GetSizeActiveFragmentUniforms(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0x30);
}

/* BindingTable__GetSizeActiveAttributes @ 0x97bb1a4c (8 bytes) */
int BindingTable__GetSizeActiveAttributes(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0x34);
}

/* BindingTable__GetMaxAttributeLength @ 0x97bb1a54 (8 bytes) */
int BindingTable__GetMaxAttributeLength(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0x38);
}

/* BindingTable__GetMaxUniformLength @ 0x97bb1a5c (8 bytes) */
int BindingTable__GetMaxUniformLength(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0x3c);
}

/* BindingTable__GetNumActiveVertexSamplers @ 0x97bb1a64 (8 bytes) */
int BindingTable__GetNumActiveVertexSamplers(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0x40);
}

/* BindingTable__GetNumActiveFragmentSamplers @ 0x97bb1a6c (8 bytes) */
int BindingTable__GetNumActiveFragmentSamplers(this)
  unsigned char *this;
{
  return *(undefined4 *)(this + 0x44);
}

/* BindingTable__GetString @ 0x97bb1a74 (1028 bytes) */
int BindingTable__GetString(this, param_1)
  unsigned char *this;
  int param_1;
{
  bool bVar1;
  char *pcVar2;
  size_t sVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  size_t sVar7;
  int iVar8;
  uint uVar9;
  Binding *this_00;
  
  this_00 = (unsigned char *)0x0;
  pcVar2 = _malloc(0x800);
  sVar7 = 0x800;
  iVar6 = 0;
  if (pcVar2 == (char *)0x0) {
    return (char *)0x0;
  }
  *pcVar2 = '\0';
  pcVar5 = pcVar2;
  if (2 < param_1) {
    if (param_1 == 3) {
      iVar6 = 0;
      do {
        pcVar4 = (char *)GetString(this,iVar6);
        pcVar2 = pcVar5;
        if (pcVar4 != (char *)0x0) {
          sVar7 = _strlen(pcVar4);
          sVar3 = _strlen(pcVar5);
          pcVar2 = _realloc(pcVar5,sVar7 + sVar3 + 1);
          if (pcVar2 == (char *)0x0) goto LAB_97bb1ddc;
          _sprintf(pcVar2,"%s%s",pcVar2,pcVar4);
          _free(pcVar4);
        }
        iVar6 = iVar6 + 1;
        pcVar5 = pcVar2;
        if (2 < iVar6) {
          return pcVar2;
        }
      } while( true );
    }
    iVar8 = 4;
    if (6 < param_1) {
      do {
        pcVar4 = (char *)GetString(this,iVar8);
        pcVar2 = pcVar5;
        if (pcVar4 != (char *)0x0) {
          sVar7 = _strlen(pcVar4);
          sVar3 = _strlen(pcVar5);
          pcVar2 = _realloc(pcVar5,sVar7 + sVar3 + 1);
          if (pcVar2 == (char *)0x0) goto LAB_97bb1ddc;
          _sprintf(pcVar2,"%s%s",pcVar2,pcVar4);
          _free(pcVar4);
        }
        iVar8 = iVar8 + 1;
        pcVar5 = pcVar2;
        if (6 < iVar8) {
          return pcVar2;
        }
      } while( true );
    }
    if (param_1 == 5) {
      if (**(int **)(this + 0x10) == 0) {
        pcVar5 = "\n No Attribute Bindings\n";
      }
      else {
        pcVar5 = "\n Attribute Bindings: [Index: (Location) \'Name\'- Type Shader]\n";
      }
    }
    else if (5 < param_1) {
      if (param_1 != 6) goto LAB_97bb1cf0;
      if (**(int **)(this + 0x18) == 0) {
        pcVar5 = "\n No Uniform Bindings\n";
      }
      else {
        pcVar5 = "\n Uniform Bindings: [Index: (Location) \'Name\'- Type Shader]\n";
      }
    }
    else {
      if (param_1 != 4) goto LAB_97bb1cf0;
      if (**(int **)(this + 8) == 0) {
        pcVar5 = "\n No Client Attribute Requests\n";
      }
      else {
        pcVar5 = "\n Client Attribute Requests: [Index: (Location) \'Name\'- Type Shader]\n";
      }
    }
    _sprintf(pcVar2,pcVar5);
LAB_97bb1cf0:
    uVar9 = 0;
    if (*(int *)this == 0) {
      return pcVar2;
    }
    do {
      if (param_1 == 5) {
        iVar8 = *(int *)(this + 0x10);
LAB_97bb1d30:
        this_00 = *(Binding **)(uVar9 * 4 + iVar8);
      }
      else if (5 < param_1) {
        if (param_1 == 6) {
          iVar8 = *(int *)(this + 0x18);
          goto LAB_97bb1d30;
        }
      }
      else if (param_1 == 4) {
        iVar8 = *(int *)(this + 8);
        goto LAB_97bb1d30;
      }
      if (this_00 != (unsigned char *)0x0) {
        _sprintf(pcVar2,"%s  --- Hash %d ---\n",pcVar2,uVar9);
        pcVar5 = pcVar2;
        do {
          pcVar2 = (char *)Binding__GetString(this_00);
          if (pcVar2 != (char *)0x0) {
            sVar3 = _strlen(pcVar2);
            iVar6 = iVar6 + sVar3;
            _sprintf(pcVar5,"%s   %s",pcVar5,pcVar2);
            _free(pcVar2);
          }
          pcVar2 = pcVar5;
          if (sVar7 < iVar6 + 0x300U) {
            sVar7 = sVar7 << 1;
            pcVar2 = _realloc(pcVar5,sVar7);
            if (pcVar2 == (char *)0x0) goto LAB_97bb1ddc;
          }
          this_00 = (unsigned char *)Binding__GetNextBindingInHash(this_00);
          pcVar5 = pcVar2;
        } while (this_00 != (unsigned char *)0x0);
      }
      uVar9 = uVar9 + 1;
      if (*(uint *)this <= uVar9) {
        return pcVar2;
      }
    } while( true );
  }
  if (param_1 == 1) {
    this_00 = *(Binding **)(this + 0xc);
    bVar1 = this_00 == (unsigned char *)0x0;
    if (bVar1) {
      pcVar4 = "\n No Attribute Bindings\n";
    }
    else {
      pcVar4 = "\n Attribute Bindings: [Index: (Location) \'Name\'- Type Shader]\n";
    }
  }
  else if (param_1 < 2) {
    bVar1 = true;
    if (param_1 != 0) goto LAB_97bb1b5c;
    this_00 = *(Binding **)(this + 4);
    bVar1 = this_00 == (unsigned char *)0x0;
    if (bVar1) {
      pcVar4 = "\n No Client Attribute Requests\n";
    }
    else {
      pcVar4 = "\n Client Attribute Requests: [Index: (Location) \'Name\'- Type Shader]\n";
    }
  }
  else {
    if (param_1 != 2) {
      bVar1 = true;
      goto LAB_97bb1b5c;
    }
    this_00 = *(Binding **)(this + 0x14);
    bVar1 = this_00 == (unsigned char *)0x0;
    if (bVar1) {
      pcVar4 = "\n No Uniform Bindings\n";
    }
    else {
      pcVar4 = "\n Uniform Bindings: [Index: (Location) \'Name\'- Type Shader]\n";
    }
  }
  _sprintf(pcVar2,pcVar4);
LAB_97bb1b5c:
  if (!bVar1) {
    do {
      pcVar2 = (char *)Binding__GetString(this_00);
      if (pcVar2 != (char *)0x0) {
        sVar3 = _strlen(pcVar2);
        iVar6 = iVar6 + sVar3;
        _sprintf(pcVar5,"%s  %s",pcVar5,pcVar2);
        _free(pcVar2);
      }
      pcVar2 = pcVar5;
      if (sVar7 < iVar6 + 0x300U) {
        sVar7 = sVar7 << 1;
        pcVar2 = _realloc(pcVar5,sVar7);
        if (pcVar2 == (char *)0x0) {
LAB_97bb1ddc:
          _free(pcVar5);
          return (char *)0x0;
        }
      }
      this_00 = (unsigned char *)Binding__GetNextBinding(this_00);
      pcVar5 = pcVar2;
    } while (this_00 != (unsigned char *)0x0);
  }
  return pcVar2;
}

/* ConstructLinker @ 0x97bb1e78 (64 bytes) */
int ConstructLinker(param_1)
  int param_1;
{
  TGenericLinker *this;
  
  this = operator_new(0x88);
  ((int (*)())TGenericLinker__TGenericLinker)(this,param_1);
  return this;
}

/* DeleteLinker @ 0x97bb1eb8 (24 bytes) */
int DeleteLinker(param_1)
  unsigned char *param_1;
{
  if (param_1 == (unsigned char *)0x0) {
    return;
  }
                    
                    
  (**(code **)(*(int *)param_1 + 4))();
  return;
}

/* UpdateOperations @ 0x97bb1ed0 (504 bytes) */
int UpdateOperations(param_1, param_2, param_3, param_4, param_5, param_6)
  unsigned char *param_1;
  unsigned char *param_2;
  int param_3;
  unsigned char *param_4;
  int param_5;
  int param_6;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  _PPStreamChunk *p_Var4;
  int iVar5;
  _PPStreamChunk *p_Var6;
  _PPStreamChunk *p_Var7;
  int iVar8;
  uint uVar9;
  _PPStreamChunk _Var10;
  int iVar11;
  
  iVar11 = 0;
  if (0 < param_5) {
    do {
      iVar5 = 0;
      iVar2 = 0;
      if (param_2 != (unsigned char *)0x0) {
        _Var10 = *param_4;
        p_Var4 = param_2;
        p_Var6 = param_1;
        do {
          uVar9 = *(uint *)(p_Var4 + 0xc);
          iVar8 = 0;
          if (uVar9 >> 0x1d != 0) {
            p_Var7 = p_Var4 + 0x10;
            do {
              if (_Var10 == (_PPStreamChunk)0x2) {
                if ((*(uint *)(p_Var7 + 0xc) & 0x3800000) == 0) goto LAB_97bb1f94;
              }
              else {
                if ((byte)_Var10 < 3) {
                  if (_Var10 != (_PPStreamChunk)0x0) goto LAB_97bb1fe8;
                  bVar1 = (*(uint *)(p_Var7 + 0xc) >> 0x17 & 7) == 1;
                }
                else if (_Var10 == (_PPStreamChunk)0x3) {
                  bVar1 = (*(uint *)(p_Var7 + 0xc) >> 0x17 & 7) == 2;
                }
                else {
                  if (_Var10 != (_PPStreamChunk)0x4) goto LAB_97bb1fe8;
                  bVar1 = (*(uint *)(p_Var7 + 0xc) >> 0x17 & 7) == 3;
                }
                if (bVar1) {
LAB_97bb1f94:
                  if ((uint)*(ushort *)(p_Var7 + 0x12) == (uint)*(ushort *)(param_4 + 0x12) + iVar11
                     ) {
                    iVar3 = iVar2;
                    if ((iVar2 != iVar5) && (iVar3 = iVar5, iVar2 < iVar5)) {
                      iVar2 = iVar5 - iVar2;
                      do {
                        p_Var6 = *(_PPStreamChunk **)(p_Var6 + 8);
                        iVar2 = iVar2 + -1;
                      } while (iVar2 != 0);
                    }
                    *(short *)(p_Var6 + iVar8 * 8 + 0x22) =
                         *(short *)(p_Var6 + iVar8 * 8 + 0x22) - (short)param_6;
                    uVar9 = *(uint *)(p_Var4 + 0xc);
                    _Var10 = *param_4;
                    iVar2 = iVar3;
                  }
                }
              }
LAB_97bb1fe8:
              iVar8 = iVar8 + 1;
              p_Var7 = p_Var7 + 8;
            } while (iVar8 < (int)(uVar9 >> 0x1d));
          }
          if (_Var10 == (_PPStreamChunk)0x2) {
            if ((*(uint *)(p_Var4 + 0x14) & 0xe0000) == 0) goto LAB_97bb2064;
          }
          else {
            if ((byte)_Var10 < 3) {
              if (_Var10 != (_PPStreamChunk)0x0) goto LAB_97bb20a4;
              bVar1 = (*(uint *)(p_Var4 + 0x14) & 0xe0000) == 0x20000;
            }
            else if (_Var10 == (_PPStreamChunk)0x3) {
              bVar1 = (*(uint *)(p_Var4 + 0x14) & 0xe0000) == 0x40000;
            }
            else {
              if (_Var10 != (_PPStreamChunk)0x4) goto LAB_97bb20a4;
              bVar1 = (*(uint *)(p_Var4 + 0x14) & 0xe0000) == 0x60000;
            }
            if (bVar1) {
LAB_97bb2064:
              if ((uint)*(ushort *)(p_Var4 + 0x1a) == (uint)*(ushort *)(param_4 + 0x12) + iVar11) {
                iVar8 = iVar2;
                if ((iVar2 != iVar5) && (iVar8 = iVar5, iVar2 < iVar5)) {
                  iVar2 = iVar5 - iVar2;
                  do {
                    p_Var6 = *(_PPStreamChunk **)(p_Var6 + 8);
                    iVar2 = iVar2 + -1;
                  } while (iVar2 != 0);
                }
                *(short *)(p_Var6 + 0x1a) = *(short *)(p_Var6 + 0x1a) - (short)param_6;
                iVar2 = iVar8;
              }
            }
          }
LAB_97bb20a4:
          p_Var4 = *(_PPStreamChunk **)(p_Var4 + 8);
          iVar5 = iVar5 + 1;
        } while (p_Var4 != (unsigned char *)0x0);
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < param_5);
  }
  return;
}

/* TGenericLinker__FindChunkDelta @ 0x97bb20c8 (156 bytes) */
int TGenericLinker__FindChunkDelta(this, param_1, param_2)
  unsigned char *this;
  unsigned char *param_1;
  unsigned char *param_2;
{
  bool bVar1;
  _PPStreamChunk _Var2;
  int iVar3;
  
  _Var2 = *param_1;
  if (_Var2 != *param_2) {
                    
                    
    iVar3 = (*(code *)(((unsigned char *)0x97bb211c) + (*(unsigned char *)0x97bb2128)))();
    return iVar3;
  }
  if (_Var2 != (_PPStreamChunk)0x2) {
    if ((byte)_Var2 < 3) {
      bVar1 = _Var2 == (_PPStreamChunk)0x0;
    }
    else {
      if (_Var2 == (_PPStreamChunk)0x3) goto LAB_97bb21b8;
      bVar1 = _Var2 == (_PPStreamChunk)0x4;
    }
    if (!bVar1) {
      return 0;
    }
  }
LAB_97bb21b8:
  return (uint)*(ushort *)(param_1 + 0x12) - (uint)*(ushort *)(param_2 + 0x12);
}

/* TGenericLinker__MergeCompilers @ 0x97bb21dc (3076 bytes) */
int TGenericLinker__MergeCompilers(this, param_1)
  unsigned char *this;
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
  TGenericLinker *pTVar10;
  TGenericLinker *pTVar11;
  TGenericLinker *pTVar12;
  int iVar13;
  void *pvVar14;
  void *pvVar15;
  undefined4 uVar16;
  ParseSymbolTable *this_00;
  int iVar17;
  size_t sVar18;
  int iVar19;
  char *pcVar20;
  undefined4 *puVar21;
  size_t sVar22;
  size_t sVar23;
  _PPStreamChunk *p_Var24;
  bool bVar25;
  uint uVar26;
  byte *pbVar27;
  int iVar28;
  int iVar29;
  undefined4 *puVar30;
  char *pcVar31;
  int iVar32;
  TGenericLinker *pTVar33;
  _PPStreamChunk *p_Var34;
  char local_70 [16];
  uint local_60;
  TGenericLinker *local_5c;
  TGenericLinker *local_58;
  TGenericLinker *local_54;
  
  puVar9 = PTR_s_gl__IfEnd__a7b7d6dc;
  puVar8 = PTR_s_gl__IfElse_a7b7d6d8;
  puVar7 = PTR_s_gl__WhileEndIf__a7b7d6d4;
  puVar6 = PTR_s_gl__WhileStart__a7b7d6d0;
  puVar5 = PTR_s_gl__WhileEnd__a7b7d6cc;
  puVar4 = PTR_s_gl__WhileBody__a7b7d6c8;
  iVar3 = param_1 * 4;
  pvVar14 = _malloc(*(int *)(this + iVar3 + 0x20) << 2);
  pvVar15 = _malloc(*(int *)(this + iVar3 + 0x20) << 2);
  local_60 = 0;
  if (10000 < *(int *)(this + iVar3 + 0x20)) {
                    
                    
    uVar16 = (*(code *)(((unsigned char *)0x97bb22a4) + (*(unsigned char *)0x97bb22ac)))();
    return uVar16;
  }
  uVar16 = _PPStreamCreate();
  *(undefined4 *)(this + iVar3 + 0x30) = uVar16;
  this_00 = operator_new(0x54);
  ParseSymbolTable__ParseSymbolTable(this_00,0x80);
  *(ParseSymbolTable **)(this + iVar3 + 0x28) = this_00;
  *(undefined4 *)(this_00 + 0xc) = *(undefined4 *)(this + iVar3 + 0x30);
  if (param_1 != 0) {
    **(undefined4 **)(this + iVar3 + 0x30) = 0x8b30;
    *(undefined4 *)(*(int *)(this + iVar3 + 0x28) + 0x3c) = 1;
  }
  else {
    **(undefined4 **)(this + 0x30) = 0x8b31;
    *(undefined4 *)(*(int *)(this + 0x28) + 0x3c) = 0;
  }
  local_60 = (uint)(param_1 != 0);
  pTVar33 = this + iVar3;
  iVar28 = 0;
  iVar29 = 0;
  _memset(pvVar14,0,*(int *)(pTVar33 + 0x20) << 2);
  _memset(pvVar15,0,*(int *)(pTVar33 + 0x20) << 2);
  pTVar10 = pTVar33;
  pTVar11 = pTVar33;
  pTVar12 = pTVar33;
  if (0 < *(int *)(pTVar33 + 0x20)) {
    do {
      local_54 = pTVar12;
      local_58 = pTVar11;
      local_5c = pTVar10;
      iVar13 = iVar28 * 4;
      iVar32 = **(int **)(*(int *)(iVar13 + *(int *)(pTVar33 + 0x18)) + 0x20);
      while (iVar32 != 0) {
        iVar17 = _PPStreamChunkCreateFromChunk(iVar32);
        _PPStreamChunkListAddChunk(*(undefined4 *)(*(int *)(pTVar33 + 0x30) + 0x20),iVar17);
        if (*(int *)(iVar13 + (int)pvVar14) == 0) {
          *(int *)(iVar13 + (int)pvVar14) = iVar17;
        }
        uVar26 = *(uint *)(iVar17 + 0x10);
        *(uint *)(iVar17 + 0xc) =
             (*(uint *)(iVar17 + 0xc) & 0x3ffff) + iVar29 & 0x3ffff |
             *(uint *)(iVar17 + 0xc) & 0xfffc0000;
        if ((uVar26 & 0x3ffff) != 0) {
          *(uint *)(iVar17 + 0x10) = (uVar26 & 0x3ffff) + iVar29 & 0x3ffff | uVar26 & 0xfffc0000;
        }
        if (*(int *)(iVar17 + 0x40) != 0) {
          pcVar31 = (char *)(iVar17 + 0x44);
          sVar18 = _strlen(puVar4);
          iVar19 = _strncmp(pcVar31,puVar4,sVar18);
          if (iVar19 != 0) {
            sVar18 = _strlen(puVar5);
            iVar19 = _strncmp(pcVar31,puVar5,sVar18);
            if (iVar19 != 0) {
              sVar18 = _strlen(puVar6);
              iVar19 = _strncmp(pcVar31,puVar6,sVar18);
              if (iVar19 != 0) {
                sVar18 = _strlen(puVar7);
                iVar19 = _strncmp(pcVar31,puVar7,sVar18);
                if (iVar19 != 0) {
                  sVar18 = _strlen(puVar8);
                  iVar19 = _strncmp(pcVar31,puVar8,sVar18);
                  if (iVar19 != 0) {
                    sVar18 = _strlen(puVar9);
                    iVar19 = _strncmp(pcVar31,puVar9,sVar18);
                    if (iVar19 != 0) goto LAB_97bb257c;
                  }
                }
              }
            }
          }
          _sprintf(local_70,"%04d",iVar28);
          pcVar20 = (char *)(iVar17 + 0x44);
          pcVar31 = local_70;
          iVar17 = 4;
          do {
            cVar1 = *pcVar31;
            pcVar31 = pcVar31 + 1;
            *pcVar20 = cVar1;
            pcVar20 = pcVar20 + 1;
            iVar17 = iVar17 + -1;
          } while (iVar17 != 0);
        }
LAB_97bb257c:
        iVar32 = *(int *)(iVar32 + 8);
        *(int *)(iVar13 + (int)pvVar15) = *(int *)(iVar13 + (int)pvVar15) + 1;
      }
      pTVar10 = local_5c;
      pTVar11 = local_54;
      for (iVar32 = **(int **)(*(int *)(iVar13 + *(int *)(pTVar33 + 0x18)) + 0x24);
          local_5c = pTVar10, local_54 = pTVar11, iVar32 != 0; iVar32 = *(int *)(iVar32 + 8)) {
        iVar17 = _PPStreamChunkCreateFromChunk(iVar32);
        _PPStreamChunkListAddChunk(*(undefined4 *)(*(int *)(pTVar33 + 0x30) + 0x24),iVar17);
        *(int *)(iVar17 + 0xc) = *(int *)(iVar17 + 0xc) + iVar29;
        if (*(int *)(iVar17 + 0x10) != 0) {
          pcVar31 = (char *)(iVar17 + 0x14);
          sVar18 = _strlen(puVar4);
          iVar19 = _strncmp(pcVar31,puVar4,sVar18);
          if (iVar19 != 0) {
            sVar18 = _strlen(puVar5);
            iVar19 = _strncmp(pcVar31,puVar5,sVar18);
            if (iVar19 != 0) {
              sVar18 = _strlen(puVar6);
              iVar19 = _strncmp(pcVar31,puVar6,sVar18);
              if (iVar19 != 0) {
                sVar18 = _strlen(puVar7);
                iVar19 = _strncmp(pcVar31,puVar7,sVar18);
                if (iVar19 != 0) {
                  sVar18 = _strlen(puVar8);
                  iVar19 = _strncmp(pcVar31,puVar8,sVar18);
                  if (iVar19 != 0) {
                    sVar18 = _strlen(puVar9);
                    iVar19 = _strncmp(pcVar31,puVar9,sVar18);
                    if (iVar19 != 0) goto LAB_97bb26e0;
                  }
                }
              }
            }
          }
          _sprintf(local_70,"%04d",iVar28);
          pcVar20 = (char *)(iVar17 + 0x14);
          pcVar31 = local_70;
          iVar17 = 4;
          do {
            cVar1 = *pcVar31;
            pcVar31 = pcVar31 + 1;
            *pcVar20 = cVar1;
            pcVar20 = pcVar20 + 1;
            iVar17 = iVar17 + -1;
          } while (iVar17 != 0);
        }
LAB_97bb26e0:
        pTVar10 = local_5c;
        pTVar11 = local_54;
      }
      iVar17 = 0;
      iVar19 = *(int *)(*(int *)(iVar13 + *(int *)(pTVar33 + 8)) + 0x6c);
      iVar32 = *(int *)(iVar19 + 4);
      if (0 < iVar32) {
        do {
          uVar26 = 0;
          if (0 < *(int *)(*(int *)(pTVar10 + 0x38) + 4)) {
            do {
              pcVar31 = (char *)FunctionTable__getFunctionName(*(int *)(pTVar11 + 0x38));
              pcVar20 = (char *)FunctionTable__getFunctionName(iVar19);
              iVar32 = _strcmp(pcVar31,pcVar20);
              if (iVar32 == 0) {
                FunctionTable__getFirstOp(*(int *)(pTVar11 + 0x38));
                FunctionTable__setFirstOp(*(int *)(pTVar11 + 0x38),uVar26);
                FunctionTable__getLastOp(*(int *)(pTVar11 + 0x38));
                FunctionTable__setLastOp(*(int *)(pTVar11 + 0x38),uVar26);
              }
              uVar26 = uVar26 + 1;
            } while ((int)uVar26 < *(int *)(*(int *)(pTVar11 + 0x38) + 4));
            iVar32 = *(int *)(iVar19 + 4);
          }
          iVar17 = iVar17 + 1;
        } while (iVar17 < iVar32);
      }
      iVar29 = iVar29 + *(int *)(iVar13 + (int)pvVar15);
      if (*(int *)(*(int *)(iVar13 + *(int *)(local_58 + 8)) + 0xa4) != 0) {
        local_60 = 1;
      }
      iVar28 = iVar28 + 1;
      pTVar10 = local_5c;
      pTVar11 = local_58;
      pTVar12 = local_54;
    } while (iVar28 < *(int *)(local_58 + 0x20));
  }
  if (local_60 == 0) {
                    
                    
    uVar16 = (*(code *)(((unsigned char *)0x97bb2824) + (*(unsigned char *)0x97bb282c)))();
    return uVar16;
  }
  iVar28 = 1;
  do {
    iVar29 = 0;
    if (0 < *(int *)(this + iVar3 + 0x20)) {
      do {
        iVar13 = iVar29 * 4;
        puVar21 = (undefined4 *)
                  ParseSymbolTable__NextSymbol
                            (*(ParseSymbol **)(iVar13 + *(int *)(this + iVar3 + 0x10)));
        while (puVar21 != (undefined4 *)0x0) {
          if (iVar28 == puVar21[0x15]) {
            puVar30 = (undefined4 *)0x0;
            if (puVar21[0xe] == 0) {
              bVar25 = true;
LAB_97bb2ab4:
              if (bVar25) goto LAB_97bb2ab8;
            }
            else {
              puVar30 = (undefined4 *)
                        ParseSymbolTable__FindGlobalSymbolByName(*(char **)(this + iVar3 + 0x28));
              bVar25 = puVar30 == (undefined4 *)0x0;
              if (!bVar25) {
                if (*(short *)(puVar30 + 0xb) != *(short *)(puVar21 + 0xb)) {
                  pcVar20 = (char *)puVar30[5];
                  sVar18 = _strlen(DAT_a7b7bb14);
                  sVar22 = _strlen(pcVar20);
                  sVar23 = _strlen((char *)(&_shaderString)[param_1]);
                  pcVar31 = _malloc(sVar18 + sVar22 + sVar23 + 1);
                  _sprintf(pcVar31,DAT_a7b7bb14,pcVar20,(&_shaderString)[param_1]);
                    
                    
                  uVar16 = (*(code *)(((unsigned char *)0x97bb2994) + (*(unsigned char *)0x97bb299c)))();
                  return uVar16;
                }
                if (*(short *)((int)puVar30 + 0x2e) != *(short *)((int)puVar21 + 0x2e)) {
                  pcVar20 = (char *)puVar30[5];
                  sVar18 = _strlen(DAT_a7b7bb18);
                  sVar22 = _strlen(pcVar20);
                  sVar23 = _strlen((char *)(&_shaderString)[param_1]);
                  pcVar31 = _malloc(sVar18 + sVar22 + sVar23 + 1);
                  _sprintf(pcVar31,DAT_a7b7bb18,pcVar20,(&_shaderString)[param_1]);
                    
                    
                  uVar16 = (*(code *)(((unsigned char *)0x97bb2a2c) + (*(unsigned char *)0x97bb2a34)))();
                  return uVar16;
                }
                goto LAB_97bb2ab4;
              }
LAB_97bb2ab8:
              bVar25 = false;
              if ((iVar28 != 0) && (pbVar27 = (byte *)*puVar21, pbVar27 != (byte *)0x0)) {
                bVar2 = *pbVar27;
                if (bVar2 != 2) {
                  if (bVar2 < 3) {
                    if ((bVar2 == 0) &&
                       (iVar32 = **(int **)(*(int *)(iVar13 + *(int *)(this + iVar3 + 0x18)) + 8),
                       iVar32 != 0)) {
                      bVar25 = false;
                      do {
                        if (*(short *)(pbVar27 + 0x12) == *(short *)(iVar32 + 0xe)) {
                          bVar25 = true;
                        }
                        iVar32 = *(int *)(iVar32 + 8);
                      } while (iVar32 != 0);
                    }
                  }
                  else if ((bVar2 == 3) &&
                          (iVar32 = **(int **)(*(int *)(iVar13 + *(int *)(this + iVar3 + 0x18)) +
                                              0x14), iVar32 != 0)) {
                    bVar25 = false;
                    do {
                      if (*(short *)(pbVar27 + 0x12) == *(short *)(iVar32 + 0xe)) {
                        bVar25 = true;
                      }
                      iVar32 = *(int *)(iVar32 + 8);
                    } while (iVar32 != 0);
                  }
                }
              }
              puVar30 = (undefined4 *)
                        ParseSymbolTable__AddFromExternalSymbol
                                  (*(ParseSymbol **)(this + iVar3 + 0x28),SUB41(puVar21,0),bVar25);
            }
            if (puVar30 == (undefined4 *)0x0) {
              pcVar20 = (char *)puVar21[5];
              sVar18 = _strlen(DAT_a7b7bbc0);
              sVar22 = _strlen(pcVar20);
              pcVar31 = _malloc(sVar18 + sVar22 + 1);
              _sprintf(pcVar31,DAT_a7b7bb90,pcVar20);
                    
                    
              uVar16 = (*(code *)(((unsigned char *)0x97bb2c78) + (*(unsigned char *)0x97bb2c80)))();
              return uVar16;
            }
            iVar32 = ((int (*)())TGenericLinker__FindChunkDelta)(this,(unsigned char *)*puVar21,(unsigned char *)*puVar30);
            if (iVar32 != 0) {
              iVar17 = GetVec4sForType(*(ushort *)(puVar21 + 0xb));
              ((int (*)())UpdateOperations)(*(_PPStreamChunk **)(iVar13 + (int)pvVar14),
                               (unsigned char *)
                               **(undefined4 **)
                                 (*(int *)(iVar13 + *(int *)(this + iVar3 + 0x18)) + 0x20),
                               *(int *)(iVar13 + (int)pvVar15),(unsigned char *)*puVar21,iVar17,
                               iVar32);
            }
          }
          puVar21 = (undefined4 *)
                    ParseSymbolTable__NextSymbol
                              (*(ParseSymbol **)(iVar13 + *(int *)(this + iVar3 + 0x10)));
        }
        iVar29 = iVar29 + 1;
      } while (iVar29 < *(int *)(this + iVar3 + 0x20));
    }
    iVar28 = iVar28 + -1;
  } while (-1 < iVar28);
  iVar28 = 0;
  if (0 < *(int *)(this + iVar3 + 0x20)) {
    do {
      iVar29 = iVar28 * 4;
      for (p_Var34 = (unsigned char *)
                     **(undefined4 **)(*(int *)(iVar29 + *(int *)(this + iVar3 + 0x18)) + 0x10);
          p_Var34 != (unsigned char *)0x0; p_Var34 = *(_PPStreamChunk **)(p_Var34 + 8)) {
        uVar26 = *(uint *)(p_Var34 + 0xc);
        if ((uVar26 & 0x1f0000) == 0x110000) {
          iVar13 = *(int *)(*(int *)(this + iVar3 + 0x28) + 0x24);
          *(int *)(*(int *)(this + iVar3 + 0x28) + 0x24) = iVar13 + 1;
          p_Var24 = (unsigned char *)_PPStreamChunkCreateFromChunk(p_Var34);
          _PPStreamChunkListAddChunk(*(undefined4 *)(*(int *)(this + iVar3 + 0x30) + 0x10),p_Var24);
          *(short *)(p_Var24 + 0x12) = (short)iVar13;
          iVar13 = ((int (*)())TGenericLinker__FindChunkDelta)(this,p_Var34,p_Var24);
          ((int (*)())UpdateOperations)(*(_PPStreamChunk **)(iVar29 + (int)pvVar14),
                           (unsigned char *)
                           **(undefined4 **)
                             (*(int *)(iVar29 + *(int *)(this + iVar3 + 0x18)) + 0x20),
                           *(int *)(iVar29 + (int)pvVar15),p_Var34,1,iVar13);
          *(undefined2 *)(p_Var24 + 0xe) =
               *(undefined2 *)(*(int *)(*(int *)(this + iVar3 + 0x30) + 0x2c) + 10);
          iVar13 = _PPStreamChunkListChunkAtIndex
                             (*(undefined4 *)
                               (*(int *)(iVar29 + *(int *)(this + iVar3 + 0x18)) + 0x2c),
                              uVar26 & 0xffff);
          _PPStreamAddConstant(*(undefined4 *)(this + iVar3 + 0x30),iVar13 + 0xc);
        }
      }
      iVar28 = iVar28 + 1;
    } while (iVar28 < *(int *)(this + iVar3 + 0x20));
  }
  iVar29 = 0;
  iVar28 = 0;
  if (0 < *(int *)(this + iVar3 + 0x20)) {
    do {
      iVar13 = 0;
      for (iVar32 = **(int **)(*(int *)(iVar29 * 4 + *(int *)(this + iVar3 + 0x18)) + 0xc);
          iVar32 != 0; iVar32 = *(int *)(iVar32 + 8)) {
        iVar13 = iVar13 + 1;
        if (iVar28 < iVar13) {
          uVar16 = _PPStreamChunkCreateFromChunk(iVar32);
          _PPStreamChunkListAddChunk(*(undefined4 *)(*(int *)(this + iVar3 + 0x30) + 0xc),uVar16);
          iVar28 = iVar13;
        }
      }
      iVar29 = iVar29 + 1;
    } while (iVar29 < *(int *)(this + iVar3 + 0x20));
  }
  iVar28 = 0;
  if (0 < *(int *)(this + iVar3 + 0x20)) {
    do {
      for (iVar29 = **(int **)(*(int *)(iVar28 * 4 + *(int *)(this + iVar3 + 0x18)) + 0x30);
          iVar29 != 0; iVar29 = *(int *)(iVar29 + 8)) {
        iVar13 = **(int **)(*(int *)(this + iVar3 + 0x30) + 0x30);
        if (iVar13 != 0) {
          do {
            if (*(char *)(iVar13 + 0xf) == *(char *)(iVar29 + 0xf)) goto LAB_97bb2f70;
            iVar13 = *(int *)(iVar13 + 8);
          } while (iVar13 != 0);
        }
        uVar16 = _PPStreamChunkCreateFromChunk(iVar29);
        _PPStreamChunkListAddChunk(*(undefined4 *)(*(int *)(this + iVar3 + 0x30) + 0x30),uVar16);
LAB_97bb2f70: ;
      }
      iVar28 = iVar28 + 1;
    } while (iVar28 < *(int *)(this + iVar3 + 0x20));
  }
  return 1;
}

/* TGenericLinker__CreateFromStreamWithSymbolTableUpdate @ 0x97bb2ff0 (844 bytes) */
int TGenericLinker__CreateFromStreamWithSymbolTableUpdate(this, param_1, param_2)
  unsigned char *this;
  unsigned char *param_1;
  unsigned char *param_2;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  _PPStreamChunk *p_Var3;
  int iVar4;
  
  puVar1 = (undefined4 *)_PPStreamCreate();
  *puVar1 = *(undefined4 *)param_1;
  *(undefined4 **)(param_2 + 0xc) = puVar1;
  for (p_Var3 = (unsigned char *)**(undefined4 **)(param_1 + 4); p_Var3 != (unsigned char *)0x0;
      p_Var3 = *(_PPStreamChunk **)(p_Var3 + 8)) {
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
      ; p_Var3 = *(_PPStreamChunk **)(p_Var3 + 8)) {
    uVar2 = _PPStreamChunkCreateFromChunk(p_Var3);
    _PPStreamChunkListAddChunk(puVar1[4],uVar2);
    ParseSymbolTable__ChangeChunk((unsigned char *)param_2,p_Var3,SUB41(uVar2,0));
  }
  for (iVar4 = **(int **)(param_1 + 0x14); iVar4 != 0; iVar4 = *(int *)(iVar4 + 8)) {
    uVar2 = _PPStreamChunkCreateFromChunk(iVar4);
    _PPStreamChunkListAddChunk(puVar1[5],uVar2);
  }
  for (p_Var3 = (unsigned char *)**(undefined4 **)(param_1 + 0x18); p_Var3 != (unsigned char *)0x0
      ; p_Var3 = *(_PPStreamChunk **)(p_Var3 + 8)) {
    uVar2 = _PPStreamChunkCreateFromChunk(p_Var3);
    _PPStreamChunkListAddChunk(puVar1[6],uVar2);
    ParseSymbolTable__ChangeChunk((unsigned char *)param_2,p_Var3,SUB41(uVar2,0));
  }
  for (p_Var3 = (unsigned char *)**(undefined4 **)(param_1 + 0x1c); p_Var3 != (unsigned char *)0x0
      ; p_Var3 = *(_PPStreamChunk **)(p_Var3 + 8)) {
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
  if (iVar4 != 1) {
    return puVar1;
  }
                    
                    
  puVar1 = (undefined4 *)(*(code *)(((unsigned char *)0x97bb3324) + (*(unsigned char *)0x97bb3330)))();
  return puVar1;
}

/* TGenericLinker__RemoveUnreachableFunctions @ 0x97bb33bc (840 bytes) */
int TGenericLinker__RemoveUnreachableFunctions(this)
  unsigned char *this;
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
  
  iVar12 = 0;
  do {
    iVar2 = iVar12 * 4;
    do {
      bVar1 = false;
      iVar13 = 0;
      if ((*(int *)(this + iVar2 + 0x38) == 0) || (*(int *)(*(int *)(this + iVar2 + 0x38) + 4) < 1))
      break;
      do {
        pcVar3 = (char *)FunctionTable__getFunctionName(*(int *)(this + iVar2 + 0x38));
        iVar4 = _memcmp(pcVar3,"main(",6);
        if (iVar4 != 0) {
          for (iVar4 = **(int **)(*(int *)(this + iVar2 + 0x30) + 0x20); iVar4 != 0;
              iVar4 = *(int *)(iVar4 + 8)) {
            if ((((*(uint *)(iVar4 + 0xc) & 0x3fc0000) == 0x1300000) &&
                (*(int *)(iVar4 + 0x40) != 0)) &&
               (iVar5 = _strcmp((char *)(iVar4 + 0x44),pcVar3), iVar5 == 0)) goto LAB_97bb37a8;
          }
          iVar4 = **(int **)(*(int *)(this + iVar2 + 0x30) + 0x20);
          while( true ) {
            if (iVar4 == 0) {
              sVar7 = _strlen(DAT_a7b7baec);
              sVar8 = _strlen((char *)(&_shaderString)[iVar12]);
              sVar9 = _strlen(pcVar3);
              pcVar10 = _malloc(sVar7 + sVar8 + sVar9 + 9);
              uVar11 = FunctionTable__getFirstOp(*(int *)(this + iVar2 + 0x38));
              _sprintf(pcVar10,DAT_a7b7baec,pcVar3,(&_shaderString)[iVar12],uVar11);
                    
                    
              (*(code *)(((unsigned char *)0x97bb3714) + (*(unsigned char *)0x97bb3720)))();
              return;
            }
            uVar14 = *(uint *)(iVar4 + 0xc);
            uVar6 = FunctionTable__getFirstOp(*(int *)(this + iVar2 + 0x38));
            if ((uVar14 & 0x3ffff) == uVar6) break;
            iVar4 = *(int *)(iVar4 + 8);
          }
          bVar1 = false;
          do {
            uVar14 = *(uint *)(iVar4 + 0xc);
            uVar6 = FunctionTable__getLastOp(*(int *)(this + iVar2 + 0x38));
            if ((uVar14 & 0x3ffff) == uVar6) {
              if (!bVar1) {
                iVar5 = *(int *)(iVar4 + 8);
                if (iVar5 != 0) {
                  *(uint *)(iVar5 + 0xc) =
                       (*(uint *)(iVar4 + 0xc) >> 0x1a & 7) << 0x1a |
                       *(uint *)(iVar5 + 0xc) & 0xe3ffffff;
                }
                uVar14 = *(uint *)(iVar4 + 0xc);
                uVar6 = FunctionTable__getLastOp(*(int *)(this + iVar2 + 0x38));
                if ((uVar14 & 0x3ffff) == uVar6) {
                  _PPStreamChunkListRemoveChunk
                            (*(undefined4 *)(*(int *)(this + iVar2 + 0x30) + 0x20),iVar4);
                }
              }
              break;
            }
            if ((*(uint *)(iVar4 + 0xc) & 0x3ffff) == 0) {
              sVar7 = _strlen(DAT_a7b7baf0);
              sVar8 = _strlen((char *)(&_shaderString)[iVar12]);
              sVar9 = _strlen(pcVar3);
              pcVar10 = _malloc(sVar7 + sVar8 + sVar9 + 1);
              _sprintf(pcVar10,DAT_a7b7baf0,pcVar3,(&_shaderString)[iVar12]);
                    
                    
              (*(code *)(((unsigned char *)0x97bb359c) + (*(unsigned char *)0x97bb35a8)))();
              return;
            }
            _PPStreamRemoveLabelsAtOperationIndex
                      (*(undefined4 *)(this + iVar2 + 0x30),*(uint *)(iVar4 + 0xc) & 0x3ffff);
            iVar5 = *(int *)(iVar4 + 8);
            bVar1 = iVar5 == 0;
            if (!bVar1) {
              *(uint *)(iVar5 + 0xc) =
                   (*(uint *)(iVar4 + 0xc) >> 0x1a & 7) << 0x1a |
                   *(uint *)(iVar5 + 0xc) & 0xe3ffffff;
            }
            _PPStreamChunkListRemoveChunk
                      (*(undefined4 *)(*(int *)(this + iVar2 + 0x30) + 0x20),iVar4);
            iVar4 = iVar5;
          } while (!bVar1);
          iVar13 = iVar13 + -1;
          bVar1 = true;
          FunctionTable__removeFunction(*(int *)(this + iVar2 + 0x38));
        }
LAB_97bb37a8:
        iVar13 = iVar13 + 1;
      } while ((*(int *)(this + iVar2 + 0x38) != 0) &&
              (iVar13 < *(int *)(*(int *)(this + iVar2 + 0x38) + 4)));
    } while (bVar1);
    iVar12 = iVar12 + 1;
    if (1 < iVar12) {
      return;
    }
  } while( true );
}

/* TGenericLinker__RenumberLabels @ 0x97bb37fc (40 bytes) */
int TGenericLinker__RenumberLabels(this, param_1, param_2, param_3)
  unsigned char *this;
  unsigned char *param_1;
  uint param_2;
  uint param_3;
{
  if (param_1 != (unsigned char *)0x0) {
    do {
      if (param_2 == *(uint *)(param_1 + 0xc)) {
        *(uint *)(param_1 + 0xc) = param_3;
      }
      param_1 = *(_PPStreamChunk **)(param_1 + 8);
    } while (param_1 != (unsigned char *)0x0);
    return;
  }
  return;
}

/* TGenericLinker__RemoveUnusedRegisters @ 0x97bb3824 (820 bytes) */
int TGenericLinker__RemoveUnusedRegisters(this)
  unsigned char *this;
{
  bool bVar1;
  ParseSymbol *this_00;
  uint uVar2;
  uint uVar3;
  ParseSymbol *pPVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  byte bVar8;
  int iVar9;
  int iVar10;
  TGenericLinker *pTVar11;
  byte *pbVar12;
  int iVar13;
  int iVar14;
  byte *pbVar15;
  int iVar16;
  
  iVar10 = 0;
  iVar9 = 0;
  pTVar11 = this;
  do {
    if (*(ParseSymbol **)(pTVar11 + 0x28) != (unsigned char *)0x0) {
      pPVar4 = (unsigned char *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(pTVar11 + 0x28));
      while (this_00 = pPVar4, this_00 != (unsigned char *)0x0) {
        iVar16 = *(int *)(this_00 + 0x54);
        pbVar12 = *(byte **)this_00;
        iVar14 = **(int **)(*(int *)(pTVar11 + 0x30) + 0x20);
        if (iVar14 == 0) {
          bVar1 = iVar16 == 0;
LAB_97bb3a3c:
          if (!bVar1) goto LAB_97bb3b10;
          pPVar4 = (unsigned char *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(pTVar11 + 0x28));
          ParseSymbolTable__RemoveSymbol(*(ParseSymbol **)(pTVar11 + 0x28));
          for (iVar14 = 0; iVar16 = GetVec4sForType(*(ushort *)(this_00 + 0x2c)), iVar14 < iVar16;
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
              while ((iVar5 = GetVec4sForType(*(ushort *)(this_00 + 0x2c)), iVar13 < iVar5 &&
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
          pPVar4 = (unsigned char *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(pTVar11 + 0x28));
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
  unsigned char *this;
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
  
  if (*(ParseSymbol **)(this + 0x28) == (unsigned char *)0x0) {
    return;
  }
  puVar3 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
joined_r0x97bb3b94:
  do {
    do {
      puVar2 = puVar3;
      if (puVar2 == (undefined4 *)0x0) {
        return;
      }
      puVar3 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
    } while ((*(char *)*puVar2 != '\0') || (puVar2[0x17] == 0));
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
                    
                    
      (*(code *)(((unsigned char *)0x97bb3c70) + (*(unsigned char *)0x97bb3c74)))();
      return;
    }
  } while( true );
}

/* TGenericLinker__FixOutputReads @ 0x97bb3d14 (1160 bytes) */
int TGenericLinker__FixOutputReads(this)
  unsigned char *this;
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
  TGenericLinker *pTVar10;
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
  unsigned char *this;
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
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  int local_70;
  int local_6c;
  uint local_60;
  int local_5c;
  
  iVar15 = 0;
  do {
    iVar2 = iVar15 * 4;
    iVar19 = 0;
    if ((*(int *)(this + iVar2 + 0x38) != 0) && (0 < *(int *)(*(int *)(this + iVar2 + 0x38) + 4))) {
      do {
        iVar16 = 0;
        pcVar4 = (char *)FunctionTable__getFunctionName(*(int *)(this + iVar2 + 0x38));
        iVar5 = _memcmp(pcVar4,"main(",6);
        if (iVar5 != 0) {
          for (; iVar5 = FunctionTable__getNumParams(*(int *)(this + iVar2 + 0x38)), iVar16 < iVar5;
              iVar16 = iVar16 + 1) {
            sVar6 = _strlen(pcVar4);
            pcVar7 = _malloc(sVar6 + 9);
            _sprintf(pcVar7,"%s_%i",pcVar4,iVar16);
            for (piVar8 = (int *)ParseSymbolTable__FindNextParamSymbolByName
                                           (*(ParseSymbol **)(this + iVar2 + 0x28),(char *)0x0);
                piVar8 != (int *)0x0;
                piVar8 = (int *)ParseSymbolTable__FindNextParamSymbolByName
                                          (*(ParseSymbol **)(this + iVar2 + 0x28),(char *)piVar8)) {
              uVar17 = 0;
              uVar9 = GetVec4sForType(*(ushort *)(piVar8 + 0xb));
              iVar5 = *piVar8;
              if (uVar9 != 0) {
                do {
                  local_60 = 0;
                  local_5c = 0;
                  local_70 = 0;
                  local_6c = 0;
                  iVar14 = **(int **)(*(int *)(this + iVar2 + 0x30) + 0x20);
                  iVar10 = FunctionTable__getEmpty(*(int *)(this + iVar2 + 0x38));
                  if (iVar10 == 0) {
                    while( true ) {
                      if (iVar14 == 0) {
                        sVar6 = _strlen(DAT_a7b7baec);
                        sVar12 = _strlen((char *)(&_shaderString)[iVar15]);
                        sVar13 = _strlen(pcVar4);
                        pcVar7 = _malloc(sVar6 + sVar12 + sVar13 + 9);
                        uVar11 = FunctionTable__getFirstOp(*(int *)(this + iVar2 + 0x38));
                        _sprintf(pcVar7,DAT_a7b7baec,pcVar4,(&_shaderString)[iVar15],uVar11);
                    
                    
                        (*(code *)(((unsigned char *)0x97bb4454) + (*(unsigned char *)0x97bb4460)))();
                        return;
                      }
                      uVar18 = *(uint *)(iVar14 + 0xc);
                      uVar3 = FunctionTable__getFirstOp(*(int *)(this + iVar2 + 0x38));
                      if ((uVar18 & 0x3ffff) == uVar3) break;
                      iVar14 = *(int *)(iVar14 + 8);
                    }
                    bVar1 = false;
                    while (((!bVar1 &&
                            (uVar18 = *(uint *)(iVar14 + 0xc),
                            uVar3 = FunctionTable__getLastOp(*(int *)(this + iVar2 + 0x38)),
                            (uVar18 & 0x3ffff) <= uVar3)) &&
                           ((*(uint *)(iVar14 + 0xc) & 0x3ffff) != 0))) {
                      iVar10 = *(int *)(iVar14 + 8);
                      if ((*(uint *)(iVar14 + 0xc) & 0x3fc0000) == 0) {
                        uVar3 = *(uint *)(iVar14 + 0x1c);
                        if (((uVar3 & 0x3800000) == 0x800000) &&
                           ((uint)*(ushort *)(iVar14 + 0x22) == *(ushort *)(iVar5 + 0x12) + uVar17))
                        {
                          local_6c = *(int *)(iVar14 + 0x18);
                          local_70 = *(int *)(iVar14 + 0x14);
                          FunctionTable__updateForRemovingChunk
                                    (*(_PPStreamChunk **)(this + iVar2 + 0x38));
                          uVar11 = *(undefined4 *)(this + iVar2 + 0x30);
                        }
                        else {
                          if (((*(uint *)(iVar14 + 0x14) & 0xe0000) != 0x20000) ||
                             ((uint)*(ushort *)(iVar14 + 0x1a) != *(ushort *)(iVar5 + 0x12) + uVar17
                             )) goto LAB_97bb4398;
                          local_5c = *(int *)(iVar14 + 0x20);
                          FunctionTable__updateForRemovingChunk
                                    (*(_PPStreamChunk **)(this + iVar2 + 0x38));
                          uVar11 = *(undefined4 *)(this + iVar2 + 0x30);
                          local_60 = uVar3;
                        }
                        _PPStreamRemoveOperation(uVar11,iVar14);
                      }
LAB_97bb4398:
                      bVar1 = iVar10 == 0;
                      iVar14 = iVar10;
                    }
                  }
                  iVar14 = **(int **)(*(int *)(this + iVar2 + 0x30) + 0x20);
joined_r0x97bb44e4:
                  while (iVar10 = iVar14, iVar10 != 0) {
                    iVar14 = *(int *)(iVar10 + 8);
                    uVar3 = *(uint *)(iVar10 + 0xc) & 0x3fc0000;
                    if (uVar3 != 0) goto LAB_97bb456c;
                    if (((*(uint *)(iVar10 + 0x1c) & 0x3800000) == 0x800000) &&
                       ((uint)*(ushort *)(iVar10 + 0x22) == *(ushort *)(iVar5 + 0x12) + uVar17))
                    goto LAB_97bb4598;
                    if (((*(uint *)(iVar10 + 0x14) & 0xe0000) == 0x20000) &&
                       ((uint)*(ushort *)(iVar10 + 0x1a) == *(ushort *)(iVar5 + 0x12) + uVar17)) {
                      if (local_70 == 0 && local_6c == 0) goto LAB_97bb45b4;
                      *(int *)(iVar10 + 0x18) = local_6c;
                      *(int *)(iVar10 + 0x14) = local_70;
                    }
                  }
                  uVar17 = uVar17 + 1;
                } while (uVar17 < uVar9);
              }
            }
            _free(pcVar7);
          }
          iVar5 = **(int **)(*(int *)(this + iVar2 + 0x30) + 0x20);
          while (iVar16 = iVar5, iVar16 != 0) {
            iVar5 = *(int *)(iVar16 + 8);
            iVar14 = FunctionTable__getEmpty(*(int *)(this + iVar2 + 0x38));
            if ((((iVar14 != 0) && ((*(uint *)(iVar16 + 0xc) & 0x3fc0000) == 0x1300000)) &&
                (*(int *)(iVar16 + 0x40) != 0)) &&
               (iVar14 = _strcmp((char *)(iVar16 + 0x44),pcVar4), iVar14 == 0)) {
              FunctionTable__updateForRemovingChunk(*(_PPStreamChunk **)(this + iVar2 + 0x38));
              _PPStreamRemoveOperation(*(undefined4 *)(this + iVar2 + 0x30),iVar16);
            }
          }
        }
        iVar19 = iVar19 + 1;
      } while ((*(int *)(this + iVar2 + 0x38) != 0) &&
              (iVar19 < *(int *)(*(int *)(this + iVar2 + 0x38) + 4)));
    }
    iVar15 = iVar15 + 1;
    if (1 < iVar15) {
      return;
    }
  } while( true );
LAB_97bb456c:
  if (((uVar3 == 0x1b40000) && ((*(uint *)(iVar10 + 0x1c) & 0x3800000) == 0x800000)) &&
     ((uint)*(ushort *)(iVar10 + 0x22) == *(ushort *)(iVar5 + 0x12) + uVar17)) {
LAB_97bb4598:
    if (local_60 == 0 && local_5c == 0) {
LAB_97bb45b4:
      FunctionTable__updateForRemovingChunk(*(_PPStreamChunk **)(this + iVar2 + 0x38));
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
  unsigned char *this;
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
  TGenericLinker *pTVar10;
  
  pTVar10 = this + 0x40;
  sVar4 = _strlen(_linkUtilString);
  puVar9 = &DAT_a7b7bb38;
  sVar4 = sVar4 + 2;
  do {
    iVar2 = *(int *)pTVar10;
    pTVar10 = pTVar10 + 4;
    if ((iVar2 == 0) || (iVar2 = ((int (*)())BindingTable__GetSizeActiveUserUniforms)(), iVar2 == 0)) {
      sVar5 = _strlen((char *)*puVar9);
      sVar4 = sVar4 + sVar5;
    }
    else {
      sVar5 = _strlen((char *)puVar9[-3]);
      sVar4 = sVar4 + sVar5;
      for (iVar2 = 0; iVar6 = ((int (*)())BindingTable__GetSizeActiveUserUniforms)(), iVar2 < iVar6;
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
    if ((iVar3 == 0) || (iVar3 = ((int (*)())BindingTable__GetSizeActiveUserUniforms)(), iVar3 == 0)) {
      _sprintf(pcVar7,(char *)*puVar9,pcVar7);
    }
    else {
      _sprintf(pcVar7,(char *)puVar9[-3],pcVar7);
      for (iVar3 = 0; iVar8 = ((int (*)())BindingTable__GetSizeActiveUserUniforms)(), iVar3 < iVar8;
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
  unsigned char *this;
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
  
  pcVar1 = (char *)((int (*)())BindingTable__GetString)(*(int *)(this + 4));
  if (*(int *)(this + 0x74) < 0) {
    sVar2 = _strlen(DAT_a7b7bb44);
    sVar3 = _strlen(pcVar1);
    pcVar4 = _malloc(sVar2 + sVar3 + 0x29);
    *pcVar4 = '\0';
    uVar5 = ((int (*)())BindingTable__GetNumActiveAttributeBindings)();
    uVar6 = ((int (*)())BindingTable__GetSizeActiveAttributes)();
    uVar7 = ((int (*)())BindingTable__GetSizeActiveUserAttributes)();
    uVar8 = ((int (*)())BindingTable__GetNumActiveUniformBindings)();
    uVar9 = ((int (*)())BindingTable__GetSizeActiveUserUniforms)();
    _sprintf(pcVar4,DAT_a7b7bb44,uVar5,uVar6,uVar7,uVar8,uVar9,pcVar1);
  }
  else {
    sVar2 = _strlen(DAT_a7b7bb40);
    sVar3 = _strlen(pcVar1);
    pcVar4 = _malloc(sVar2 + sVar3 + 0x29);
    *pcVar4 = '\0';
    uVar5 = ((int (*)())BindingTable__GetNumActiveAttributeBindings)();
    uVar6 = ((int (*)())BindingTable__GetSizeActiveAttributes)();
    uVar7 = ((int (*)())BindingTable__GetSizeActiveUserAttributes)();
    uVar8 = ((int (*)())BindingTable__GetNumActiveUniformBindings)();
    uVar9 = ((int (*)())BindingTable__GetSizeActiveUserUniforms)();
    _sprintf(pcVar4,DAT_a7b7bb40,*(undefined4 *)(this + 0x74),uVar5,uVar6,uVar7,uVar8,uVar9);
  }
  _free(pcVar1);
  return pcVar4;
}

/* TGenericLinker__GetFullTableString @ 0x97bb4a14 (152 bytes) */
int TGenericLinker__GetFullTableString(this)
  unsigned char *this;
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
  unsigned char *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ((int (*)())BindingTable__FindAttribBinding)(*(Binding **)(param_1 + 4));
  if (iVar1 == 0) {
    uVar2 = BindingTable__InsertClientAttribBinding(*(Binding **)(param_1 + 4));
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
  Binding *this;
  int iVar1;
  char *pcVar2;
  size_t sVar3;
  size_t sVar4;
  char *pcVar5;
  
  this = operator_new(0x38);
  Binding__Binding(this);
  if (this == (unsigned char *)0x0) {
                    
                    
    iVar1 = (*(code *)(((unsigned char *)0x97bb4cdc) + (*(unsigned char *)0x97bb4ce8)))();
    return iVar1;
  }
  Binding__SetName((char *)this);
  iVar1 = ((int (*)())BindingTable__FindAttribBinding)(*(Binding **)(param_1 + 4));
  if (iVar1 == 0) {
    Binding__SetClientRequest(SUB41(this,0));
    Binding__SetOpenGLType((ushort)this);
    Binding__SetDecSize((ulong)this);
    Binding__SetActualSize((ulong)this);
    Binding__SetBuiltIn(SUB41(this,0));
    iVar1 = BindingTable__InsertAttribBinding(*(Binding **)(param_1 + 4));
    if (iVar1 == 0) {
      pcVar2 = (char *)((int (*)())BindingTable__GetAttribBindingNameByLocation)(*(long *)(param_1 + 4));
      sVar3 = _strlen(_linkErrorString);
      sVar4 = _strlen(pcVar2);
      pcVar5 = _malloc(sVar3 + sVar4 + 1);
      _sprintf(pcVar5,_linkErrorString,pcVar2);
                    
                    
      iVar1 = (*(code *)(((unsigned char *)0x97bb4c20) + (*(unsigned char *)0x97bb4c28)))();
      return iVar1;
    }
  }
  else {
    Binding___Binding(this);
    operator_delete(this);
    iVar1 = 0;
  }
  return iVar1;
}

/* TGenericLinker__CollectClientAttributeBindings @ 0x97bb4d6c (484 bytes) */
int TGenericLinker__CollectClientAttributeBindings(this)
  unsigned char *this;
{
  ulong uVar1;
  int iVar2;
  size_t sVar3;
  size_t sVar4;
  char *pcVar5;
  undefined4 uVar6;
  char *pcVar7;
  
  if (*(int *)(this + 0x28) == 0) {
    iVar2 = BindingTable__NextAttribRequestBinding(*(Binding **)(this + 4));
    if (iVar2 != 0) {
      pcVar7 = *(char **)(iVar2 + 8);
      sVar3 = _strlen(DAT_a7b7bac8);
      sVar4 = _strlen(pcVar7);
      pcVar5 = _malloc(sVar3 + sVar4 + 1);
      _sprintf(pcVar5,DAT_a7b7bac8,pcVar7);
                    
                    
      uVar6 = (*(code *)(((unsigned char *)0x97bb5034) + (*(unsigned char *)0x97bb5038)))();
      return uVar6;
    }
  }
  else {
    uVar1 = BindingTable__NextAttribRequestBinding(*(Binding **)(this + 4));
    while (uVar1 != 0) {
      iVar2 = ParseSymbolTable__FindGlobalSymbolByName(*(char **)(this + 0x28));
      if (iVar2 == 0) {
        pcVar7 = *(char **)(uVar1 + 8);
        sVar3 = _strlen(DAT_a7b7bac4);
        sVar4 = _strlen(pcVar7);
        pcVar5 = _malloc(sVar3 + sVar4 + 1);
        _sprintf(pcVar5,DAT_a7b7bac4,pcVar7);
                    
                    
        uVar6 = (*(code *)(((unsigned char *)0x97bb4f34) + (*(unsigned char *)0x97bb4f38)))();
        return uVar6;
      }
      Binding__SetOpenGLType((ushort)uVar1);
      Binding__SetActualSize(uVar1);
      Binding__SetDecSize(uVar1);
      if (*(int *)(iVar2 + 0x34) == 1) {
        pcVar7 = *(char **)(uVar1 + 8);
        sVar3 = _strlen(DAT_a7b7bb68);
        sVar4 = _strlen(pcVar7);
        pcVar5 = _malloc(sVar3 + sVar4 + 1);
        _sprintf(pcVar5,DAT_a7b7bb68,pcVar7);
                    
                    
        uVar6 = (*(code *)(((unsigned char *)0x97bb4e44) + (*(unsigned char *)0x97bb4e50)))();
        return uVar6;
      }
      Binding__SetBuiltIn(SUB41(uVar1,0));
      InsertClientAttribBinding((unsigned char *)this);
      uVar1 = BindingTable__NextAttribRequestBinding(*(Binding **)(this + 4));
    }
  }
  return 1;
}

/* TGenericLinker__CollectAttributeBindings @ 0x97bb50dc (996 bytes) */
int TGenericLinker__CollectAttributeBindings(this)
  unsigned char *this;
{
  short sVar1;
  undefined4 *puVar2;
  
  if (*(ParseSymbol **)(this + 0x28) != (unsigned char *)0x0) {
    puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
    while (puVar2 != (undefined4 *)0x0) {
      if (((*(char *)*puVar2 == '\x02') && (*(short *)(puVar2 + 0xb) == -0x74a4)) &&
         (puVar2[0xd] == 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)puVar2[5],true);
      }
      puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
    }
    puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
    while (puVar2 != (undefined4 *)0x0) {
      if (((*(char *)*puVar2 == '\x02') && (*(short *)(puVar2 + 0xb) == -0x74a5)) &&
         (puVar2[0xd] == 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)puVar2[5],true);
      }
      puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
    }
    puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
    while (puVar2 != (undefined4 *)0x0) {
      if (((*(char *)*puVar2 == '\x02') && (*(short *)(puVar2 + 0xb) == -0x74a6)) &&
         (puVar2[0xd] == 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)puVar2[5],true);
      }
      puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
    }
    puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
    while (puVar2 != (undefined4 *)0x0) {
      if ((((*(char *)*puVar2 == '\x02') && (sVar1 = *(short *)(puVar2 + 0xb), sVar1 != -0x74a4)) &&
          (sVar1 != -0x74a5)) && ((sVar1 != -0x74a6 && (puVar2[0xd] == 0)))) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)puVar2[5],SUB21(sVar1,0));
      }
      puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
    }
    puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
    while (puVar2 != (undefined4 *)0x0) {
      if (((*(char *)*puVar2 == '\x02') && (*(short *)(puVar2 + 0xb) == -0x74a4)) &&
         (puVar2[0xd] != 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)puVar2[5],true);
      }
      puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
    }
    puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
    while (puVar2 != (undefined4 *)0x0) {
      if (((*(char *)*puVar2 == '\x02') && (*(short *)(puVar2 + 0xb) == -0x74a5)) &&
         (puVar2[0xd] != 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)puVar2[5],true);
      }
      puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
    }
    puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
    while (puVar2 != (undefined4 *)0x0) {
      if (((*(char *)*puVar2 == '\x02') && (*(short *)(puVar2 + 0xb) == -0x74a6)) &&
         (puVar2[0xd] != 0)) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)puVar2[5],true);
      }
      puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
    }
    puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
    while (puVar2 != (undefined4 *)0x0) {
      if (((*(char *)*puVar2 == '\x02') && (sVar1 = *(short *)(puVar2 + 0xb), sVar1 != -0x74a4)) &&
         ((sVar1 != -0x74a5 && ((sVar1 != -0x74a6 && (puVar2[0xd] != 0)))))) {
        ((int (*)())TGenericLinker__AddAttribBinding)((char *)this,(ushort)puVar2[5],SUB21(sVar1,0));
      }
      puVar2 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
    }
  }
  return 1;
}

/* TGenericLinker__RemapVertexAttributes @ 0x97bb54c0 (400 bytes) */
int TGenericLinker__RemapVertexAttributes(this)
  unsigned char *this;
{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  size_t sVar4;
  size_t sVar5;
  undefined4 uVar6;
  int iVar7;
  ushort uVar9;
  uint uVar8;
  char *pcVar10;
  char *pcVar11;
  uint uVar12;
  
  iVar2 = ((int (*)())BindingTable__NextAttribBinding)(*(Binding **)(this + 4));
joined_r0x97bb54f0:
  if (iVar2 == 0) {
    return 1;
  }
  iVar2 = Binding__IsBuiltIn();
  if (((iVar2 == 0) && (*(char **)(this + 0x28) != (char *)0x0)) &&
     (puVar3 = (undefined4 *)ParseSymbolTable__FindGlobalSymbolByName(*(char **)(this + 0x28)),
     puVar3 != (undefined4 *)0x0)) {
    pcVar10 = (char *)*puVar3;
    if (*pcVar10 != '\x02') {
      pcVar11 = (char *)puVar3[5];
      sVar4 = _strlen(DAT_a7b7bb6c);
      sVar5 = _strlen(pcVar11);
      pcVar10 = _malloc(sVar4 + sVar5 + 1);
      _sprintf(pcVar10,DAT_a7b7bb6c,pcVar11);
                    
                    
      uVar6 = (*(code *)(((unsigned char *)0x97bb5588) + (*(unsigned char *)0x97bb5594)))();
      return uVar6;
    }
    if ((*pcVar10 == '\x02') && ((*(uint *)(pcVar10 + 0xc) & 0xf0000) == 0x90000)) {
      sVar1 = *(short *)(pcVar10 + 0x12);
      iVar7 = Binding__GetLocation();
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
    uVar9 = Binding__GetOpenGLType();
    uVar8 = GetVec4sForType(uVar9);
    if ((uVar8 <= uVar12) || (iVar2 == 0)) break;
    uVar8 = iVar7 + uVar12;
    uVar12 = uVar12 + 1;
    *(uint *)(iVar2 + 0xc) = uVar8 & 0x1f | *(uint *)(iVar2 + 0xc) & 0xffffffe0;
    iVar2 = *(int *)(iVar2 + 8);
  }
LAB_97bb56a8:
  iVar2 = ((int (*)())BindingTable__NextAttribBinding)(*(Binding **)(this + 4));
  goto joined_r0x97bb54f0;
}

/* TGenericLinker__AllocateTextureUnitsForVaryings @ 0x97bb56d4 (4688 bytes) */
int TGenericLinker__AllocateTextureUnitsForVaryings(this)
  unsigned char *this;
{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ParseSymbol *pPVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  size_t sVar9;
  char *pcVar10;
  undefined4 uVar11;
  void *pvVar12;
  int *piVar13;
  uint uVar14;
  int *piVar15;
  void *pvVar16;
  int iVar17;
  short sVar23;
  int iVar18;
  size_t sVar19;
  size_t sVar20;
  size_t sVar21;
  undefined4 uVar22;
  uint uVar24;
  uint uVar25;
  int *piVar26;
  int iVar27;
  ushort uVar28;
  int iVar29;
  int iVar30;
  char *pcVar31;
  int iVar32;
  uint uVar33;
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
  iVar32 = 0;
  iVar30 = 0;
  iVar29 = 0;
  if (*(ParseSymbol **)(this + 0x28) != (unsigned char *)0x0) {
    puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
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
      puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
    }
  }
  pPVar5 = *(ParseSymbol **)(this + 0x2c);
  if (pPVar5 != (unsigned char *)0x0) {
    iVar30 = *(int *)(pPVar5 + 0x1c);
    iVar29 = *(int *)(pPVar5 + 0x20);
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
      puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x2c));
    }
  }
  if (iVar30 != 0) {
    if ((*(int *)(this + 0x28) == 0) || (*(int *)(this + 0x2c) == 0)) {
      if (*(ParseSymbol **)(this + 0x2c) != (unsigned char *)0x0) {
        puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x2c));
        while (puVar8 != (undefined4 *)0x0) {
          if ((*(char *)*puVar8 == '\0') && (puVar8[0x18] != 0)) {
            pcVar31 = (char *)puVar8[5];
            sVar9 = _strlen(DAT_a7b7badc);
            sVar19 = _strlen(pcVar31);
            pcVar10 = _malloc(sVar9 + sVar19 + 1);
            _sprintf(pcVar10,DAT_a7b7badc,pcVar31);
                    
                    
            uVar11 = (*(code *)(((unsigned char *)0x97bb6a94) + (*(unsigned char *)0x97bb6a9c)))();
            return uVar11;
          }
          puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
        }
      }
    }
    else {
      iVar30 = 1;
      iVar29 = iVar32 * 4 + iVar29;
      if (0x20 < iVar29) {
        sVar9 = _strlen(DAT_a7b7bb00);
        pcVar10 = _malloc(sVar9 + 0x11);
        _sprintf(pcVar10,DAT_a7b7bb00,0x20,iVar29);
                    
                    
        uVar11 = (*(code *)(((unsigned char *)0x97bb58a8) + (*(unsigned char *)0x97bb58b0)))();
        return uVar11;
      }
      pvVar12 = _malloc(0x80);
      _memset(pvVar12,0,0x80);
      puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x2c));
      while (puVar8 != (undefined4 *)0x0) {
        if ((*(char *)*puVar8 == '\x02') &&
           (uVar25 = *(uint *)((char *)*puVar8 + 0xc), (uVar25 & 0xf0000) == 0x70000)) {
          iVar32 = (uVar25 & 0x1f) * 0x10;
          iVar29 = -iVar30;
          *(int *)((int)pvVar12 + iVar32) = iVar29;
          iVar30 = iVar30 + 1;
          *(int *)((int)pvVar12 + iVar32 + 0xc) = iVar29;
          *(int *)((int)pvVar12 + iVar32 + 4) = iVar29;
          *(int *)((int)pvVar12 + iVar32 + 8) = iVar29;
        }
        puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x2c));
      }
      puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
      while (puVar8 != (undefined4 *)0x0) {
        if ((*(char *)*puVar8 == '\x04') &&
           (uVar25 = *(uint *)((char *)*puVar8 + 0xc), (uVar25 & 0xf0000) == 0x60000)) {
          iVar32 = (uVar25 & 0x1f) * 0x10;
          iVar29 = -iVar30;
          *(int *)((int)pvVar12 + iVar32) = iVar29;
          iVar30 = iVar30 + 1;
          *(int *)((int)pvVar12 + iVar32 + 0xc) = iVar29;
          *(int *)((int)pvVar12 + iVar32 + 4) = iVar29;
          *(int *)((int)pvVar12 + iVar32 + 8) = iVar29;
        }
        puVar8 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x28));
      }
      uVar25 = 4;
      do {
        piVar13 = (int *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x2c));
        while (piVar13 != (int *)0x0) {
          if (((*(char *)*piVar13 == '\0') && (piVar13[0x18] != 0)) &&
             (uVar14 = GetScalerWidthForType(*(ushort *)(piVar13 + 0xb)), uVar25 == uVar14)) {
            piVar15 = (int *)ParseSymbolTable__FindGlobalSymbolByName(*(char **)(this + 0x28));
            bVar1 = piVar15 == (int *)0x0;
            if (((bVar1) ||
                (uVar28 = *(ushort *)(piVar13 + 0xb), uVar28 != *(ushort *)(piVar15 + 0xb))) ||
               ((*(char *)*piVar15 != '\0' || (local_60 = 0, piVar15[0x17] == 0)))) {
              if (!bVar1) {
                if (*(short *)(piVar13 + 0xb) != *(short *)(piVar15 + 0xb)) {
                  pcVar31 = (char *)piVar13[5];
                  sVar9 = _strlen(DAT_a7b7bad0);
                  sVar19 = _strlen(pcVar31);
                  pcVar10 = (char *)GetShaderStringForType(*(ushort *)(piVar15 + 0xb));
                  sVar20 = _strlen(pcVar10);
                  pcVar10 = (char *)GetShaderStringForType(*(ushort *)(piVar13 + 0xb));
                  sVar21 = _strlen(pcVar10);
                  pcVar10 = _malloc(sVar9 + sVar19 + sVar20 + sVar21 + 1);
                  uVar11 = GetShaderStringForType(*(ushort *)(piVar13 + 0xb));
                  uVar22 = GetShaderStringForType(*(ushort *)(piVar15 + 0xb));
                  _sprintf(pcVar10,DAT_a7b7bad0,pcVar31,uVar22,uVar11);
                    
                    
                  uVar11 = (*(code *)(((unsigned char *)0x97bb67f4) + (*(unsigned char *)0x97bb67fc)))();
                  return uVar11;
                }
                if ((!bVar1) && ((*(char *)*piVar15 != '\0' || (piVar15[0x17] != 0)))) {
                  pcVar31 = (char *)piVar13[5];
                  sVar9 = _strlen(DAT_a7b7bb70);
                  sVar19 = _strlen(pcVar31);
                  pcVar10 = _malloc(sVar9 + sVar19 + 1);
                  _sprintf(pcVar10,DAT_a7b7bb70,pcVar31);
                    
                    
                  uVar11 = (*(code *)(((unsigned char *)0x97bb6884) + (*(unsigned char *)0x97bb6890)))();
                  return uVar11;
                }
              }
              pcVar31 = (char *)piVar13[5];
              sVar9 = _strlen(DAT_a7b7bad4);
              sVar19 = _strlen(pcVar31);
              pcVar10 = _malloc(sVar9 + sVar19 + 1);
              _sprintf(pcVar10,DAT_a7b7bad4,pcVar31);
                    
                    
              uVar11 = (*(code *)(((unsigned char *)0x97bb68f4) + (*(unsigned char *)0x97bb68fc)))();
              return uVar11;
            }
            while (uVar14 = GetVec4sForType(uVar28), local_60 < uVar14) {
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
                  iVar29 = iVar32 << 2;
LAB_97bb5b68:
                  if (*(int *)((int)pvVar12 + iVar29 + 4) == 0) {
LAB_97bb5b80:
                    if (*(int *)(iVar29 + (int)pvVar12) == 0) goto LAB_97bb5b90;
                  }
LAB_97bb5b8c:
                  bVar1 = false;
                }
                else {
                  if (2 < uVar25) {
                    if (uVar25 == 3) {
                      iVar29 = iVar32 << 2;
LAB_97bb5b50:
                      if (*(int *)((int)pvVar12 + iVar29 + 8) == 0) goto LAB_97bb5b68;
                    }
                    else {
                      if (uVar25 != 4) goto LAB_97bb5b90;
                      iVar29 = iVar32 * 4;
                      if (*(int *)((int)pvVar12 + iVar29 + 0xc) == 0) goto LAB_97bb5b50;
                    }
                    goto LAB_97bb5b8c;
                  }
                  if (uVar25 == 1) {
                    iVar29 = iVar32 << 2;
                    goto LAB_97bb5b80;
                  }
                }
LAB_97bb5b90:
                bVar1 = !bVar1;
                if ((!bVar1) && (uVar14 = 0, uVar25 != 0)) {
                  piVar26 = (int *)(iVar32 * 4 + (int)pvVar12);
                  puVar6 = local_e0;
                  uVar33 = uVar25;
                  do {
                    uVar2 = *(uint *)(this + 0x78);
                    puVar6[4] = uVar14;
                    uVar14 = uVar14 + 1;
                    *(uint *)(this + 0x78) = uVar2 | 1 << (iVar32 >> 2 & 0x3fU);
                    *puVar6 = iVar32 >> 2;
                    puVar6 = puVar6 + 1;
                    *piVar26 = iVar30;
                    piVar26 = piVar26 + 1;
                    uVar33 = uVar33 - 1;
                  } while (uVar33 != 0);
                }
                iVar32 = iVar32 + 4;
              } while ((iVar32 < 0x20) && (bVar1));
              iVar32 = 0;
              if (bVar1) {
                do {
                  uVar14 = 1;
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
                          if (*(int *)((int)pvVar12 + (iVar32 + uVar14) * 4 + 4) == 0) {
LAB_97bb5c9c:
                            if (*(int *)((int)pvVar12 + (iVar32 + uVar14) * 4) == 0)
                            goto LAB_97bb5cb0;
                          }
LAB_97bb5cac:
                          bVar1 = false;
                        }
                        else if (uVar25 < 3) {
                          if (uVar25 == 1) goto LAB_97bb5c9c;
                        }
                        else if (uVar25 == 3) {
                          if (*(int *)((int)pvVar12 + (iVar32 + uVar14) * 4 + 8) == 0)
                          goto LAB_97bb5c80;
                          goto LAB_97bb5cac;
                        }
LAB_97bb5cb0:
                        uVar14 = uVar14 + 1;
                        if (-uVar25 + 4 < uVar14) {
                          bVar1 = !bVar1;
                          goto LAB_97bb5ccc;
                        }
                      } while (!bVar1);
                      bVar1 = false;
                    }
LAB_97bb5cd0:
                    iVar29 = 0;
                    if (uVar25 != 0) {
                      piVar26 = (int *)((iVar32 + (uVar14 - 1)) * 4 + (int)pvVar12);
                      puVar6 = local_e0;
                      uVar33 = uVar25;
                      do {
                        uVar2 = *(uint *)(this + 0x78);
                        puVar6[4] = iVar29 + (uVar14 - 1);
                        iVar29 = iVar29 + 1;
                        *(uint *)(this + 0x78) = uVar2 | 1 << (iVar32 >> 2 & 0x3fU);
                        *puVar6 = iVar32 >> 2;
                        puVar6 = puVar6 + 1;
                        *piVar26 = iVar30;
                        piVar26 = piVar26 + 1;
                        uVar33 = uVar33 - 1;
                      } while (uVar33 != 0);
                    }
                  }
                  iVar32 = iVar32 + 4;
                } while ((iVar32 < 0x20) && (bVar1));
              }
              uVar14 = 0;
              if ((uVar25 != 0) && (bVar1)) {
                do {
                  uVar33 = 0;
                  uVar2 = 0;
                  if (bVar1) {
                    do {
                      uVar24 = uVar33;
                      if (*(int *)(uVar2 * 4 + (int)pvVar12) == 0) {
                        uVar3 = ((int)uVar2 >> 2) + (uint)((int)uVar2 < 0 && (uVar2 & 3) != 0);
                        local_e0[uVar33] = uVar3;
                        uVar24 = uVar33 + 1;
                        *(uint *)(this + 0x78) = *(uint *)(this + 0x78) | 1 << (uVar3 & 0x3f);
                        local_d0[uVar33] = uVar2 + uVar3 * -4;
                        *(int *)(uVar2 * 4 + (int)pvVar12) = iVar30;
                      }
                      if (uVar24 == uVar25) {
                        bVar1 = false;
                      }
                      uVar2 = uVar2 + 1;
                    } while (((int)uVar2 < 0x20) && (uVar33 = uVar24, bVar1));
                  }
                  uVar14 = uVar14 + 1;
                } while ((uVar14 < uVar25) && (bVar1));
              }
              iVar30 = iVar30 + 1;
              if (bVar1) {
                    
                    
                uVar11 = (*(code *)(((unsigned char *)0x97bb66ac) + (*(unsigned char *)0x97bb66b4)))();
                return uVar11;
              }
              iVar32 = *(int *)(this + 0x38);
              local_5c = 0;
              uVar14 = 0;
              if ((iVar32 != 0) && (*(int *)(iVar32 + 4) != 0)) {
                while( true ) {
                  pvVar16 = (void *)FunctionTable__getFunctionName(iVar32);
                  iVar32 = _memcmp(pvVar16,"main(",6);
                  if (iVar32 == 0) break;
                  iVar32 = *(int *)(this + 0x38);
                  uVar14 = uVar14 + 1;
                  if ((iVar32 == 0) || (*(uint *)(iVar32 + 4) <= uVar14)) break;
                }
              }
              for (iVar32 = **(int **)(*(int *)(this + 0x30) + 0x20); iVar32 != 0;
                  iVar32 = *(int *)(iVar32 + 8)) {
                uVar14 = FunctionTable__getFirstOp(*(int *)(this + 0x38));
                if (uVar14 == (*(uint *)(iVar32 + 0xc) & 0x3ffff)) {
                  local_5c = 1;
                }
                if (((local_5c != 0) && ((*(uint *)(iVar32 + 0xc) & 0x3fc0000) == 0x1340000)) &&
                   (uVar14 = 0, uVar25 != 0)) {
                  iVar29 = 0;
                  local_58 = &local_c0;
LAB_97bb5ec0:
                  iVar17 = *(int *)(this + 0x30);
                  uVar33 = 0;
                  uVar2 = *(uint *)((int)local_e0 + iVar29);
                  for (iVar27 = **(int **)(iVar17 + 0x1c); iVar27 != 0;
                      iVar27 = *(int *)(iVar27 + 8)) {
                    if (((*(uint *)(iVar27 + 0xc) & 0xf0000) == 0x60000) &&
                       ((*(uint *)(iVar27 + 0xc) & 0x1f) == uVar2)) {
                      uVar28 = *(ushort *)(iVar27 + 0x12);
                      uVar24 = 3;
                      piVar26 = (int *)((int)pvVar12 + uVar2 * 0x10 + 0xc);
                      goto LAB_97bb5f28;
                    }
                  }
                  local_7c = 0;
                  local_80 = uVar2 & 0x1f | 0x4060000;
                  piVar26 = (int *)((int)pvVar12 + uVar2 * 0x10 + 0xc);
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
                  sVar23 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(iVar17 + 0x1c));
                  uVar28 = sVar23 + 1;
                  local_7c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_7c) + 0)),uVar28);
                  _PPStreamAddOutputBinding(*(undefined4 *)(this + 0x30),&local_80);
LAB_97bb5fe4:
                  iVar17 = *(int *)(this + 0x30);
                  goto LAB_97bb5fe8;
                }
LAB_97bb61d0:
                uVar14 = FunctionTable__getLastOp(*(int *)(this + 0x38));
                if (uVar14 == (*(uint *)(iVar32 + 0xc) & 0x3ffff)) break;
              }
              iVar32 = *(int *)(this + 0x3c);
              uVar14 = 0;
              if ((iVar32 != 0) && (*(int *)(iVar32 + 4) != 0)) {
                while( true ) {
                  pvVar16 = (void *)FunctionTable__getFunctionName(iVar32);
                  iVar32 = _memcmp(pvVar16,"main(",6);
                  if (iVar32 == 0) break;
                  iVar32 = *(int *)(this + 0x3c);
                  uVar14 = uVar14 + 1;
                  if ((iVar32 == 0) || (*(uint *)(iVar32 + 4) <= uVar14)) break;
                }
              }
              for (iVar32 = **(int **)(*(int *)(this + 0x34) + 0x20); iVar32 != 0;
                  iVar32 = *(int *)(iVar32 + 8)) {
                uVar33 = FunctionTable__getFirstOp(*(int *)(this + 0x3c));
                if (uVar33 == (*(uint *)(iVar32 + 0xc) & 0x3ffff)) {
                  uVar33 = 0;
                  if (uVar25 != 0) {
                    local_58 = &local_c0;
                    iVar29 = 0;
                    goto LAB_97bb62a8;
                  }
                  break;
                }
              }
LAB_97bb6720:
              uVar28 = *(ushort *)(piVar13 + 0xb);
              local_60 = local_60 + 1;
            }
          }
          piVar13 = (int *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + 0x2c));
        }
        uVar25 = uVar25 - 1;
      } while (uVar25 != 0);
      iVar32 = 0;
      *(undefined4 *)(this + 0x74) = 0xffffffff;
      iVar29 = 8;
      do {
        iVar30 = iVar32 * 4;
        if ((((*(int *)((int)pvVar12 + iVar30) != 0) || (*(int *)((int)pvVar12 + iVar30 + 4) != 0))
            || (*(int *)((int)pvVar12 + iVar30 + 8) != 0)) ||
           (*(int *)((int)pvVar12 + iVar30 + 0xc) != 0)) {
          *(int *)(this + 0x74) = iVar32 >> 2;
        }
        iVar32 = iVar32 + 4;
        iVar29 = iVar29 + -1;
      } while (iVar29 != 0);
      if (pvVar12 != (void *)0x0) {
        _free(pvVar12);
      }
    }
  }
  return 1;
  while (uVar24 = uVar24 - 1, -1 < (int)uVar24) {
LAB_97bb5f28:
    iVar18 = *piVar26;
    piVar26 = piVar26 + -1;
    if (iVar18 != 0) {
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
  local_b4 = (uint)uVar28;
  local_8c = 0;
  local_ac = (uint)(ushort)(*(short *)(*piVar15 + 0x12) + (short)local_60);
  uVar7 = *(uint *)((int)local_e0 + iVar29);
  while ((uVar7 == uVar2 && (uVar14 < uVar25))) {
    uVar7 = *(uint *)((int)local_d0 + iVar29);
    if (uVar7 == 1) {
      uVar24 = (uVar33 & 3) << 6 | uVar24 & 0xffffff3f | 0x4000;
LAB_97bb60fc:
      uVar24 = (uVar7 & 3) << 10 | uVar24 & 0xfffff3ff;
      local_b8 = uVar24;
    }
    else {
      if (1 < (int)uVar7) {
        if (uVar7 == 2) {
          uVar24 = (uVar33 & 3) << 4 | uVar24 & 0xffffffcf | 0x8000;
        }
        else {
          if (uVar7 != 3) goto LAB_97bb6108;
          uVar24 = (uVar33 & 3) << 2 | uVar24 & 0xfffffff3 | 0x10000;
        }
        goto LAB_97bb60fc;
      }
      if (uVar7 == 0) {
        uVar24 = (uVar33 & 3) << 8 | uVar24 & 0xfffffcff | 0x2000;
        goto LAB_97bb60fc;
      }
    }
LAB_97bb6108:
    if (uVar33 == 1) {
      uVar3 = (uVar14 & 3) << 0x13 | uVar3 & 0xffe7ffff;
LAB_97bb6150:
      local_b0 = uVar3;
    }
    else {
      if (1 < (int)uVar33) {
        if (uVar33 == 2) {
          uVar3 = (uVar14 & 3) << 0x11 | uVar3 & 0xfff9ffff;
        }
        else {
          if (uVar33 != 3) goto LAB_97bb6154;
          uVar3 = (uVar14 & 3) << 0xf | uVar3 & 0xfffe7fff;
        }
        goto LAB_97bb6150;
      }
      if (uVar33 == 0) {
        uVar3 = (uVar14 & 3) << 0x15 | uVar3 & 0xff9fffff;
        goto LAB_97bb6150;
      }
    }
LAB_97bb6154:
    uVar14 = uVar14 + 1;
    uVar33 = uVar33 + 1;
    iVar29 = uVar14 * 4;
    uVar7 = local_e0[uVar14];
  }
  local_b0 = (uVar33 - 1) * 0x1000 & 0x3000 | uVar3;
  local_bc = (uVar33 - 1) * 0x4000000 & 0xc000000 | 0x800000;
  iVar27 = _PPStreamInsertOperationAfterChunk(iVar17,local_58,0,0,*(undefined4 *)(iVar32 + 4));
  _PPStreamChangeBranchTargets
            (*(undefined4 *)(this + 0x30),*(uint *)(iVar32 + 0xc) & 0x3ffff,
             *(uint *)(iVar27 + 0xc) & 0x3ffff);
  if (uVar25 <= uVar14) goto LAB_97bb61d0;
  goto LAB_97bb5ec0;
LAB_97bb62a8:
  uVar2 = 0;
  uVar24 = *(uint *)((int)local_e0 + iVar29);
  for (iVar27 = **(int **)(*(int *)(this + 0x34) + 0x18); iVar27 != 0; iVar27 = *(int *)(iVar27 + 8)
      ) {
    if (((*(uint *)(iVar27 + 0xc) & 0xf0000) == 0x70000) &&
       ((*(uint *)(iVar27 + 0xc) & 0x1f) == uVar24)) {
      uVar28 = *(ushort *)(iVar27 + 0x12);
      uVar3 = 3;
      piVar26 = (int *)((int)pvVar12 + uVar24 * 0x10 + 0xc);
      goto LAB_97bb630c;
    }
  }
  local_6c = 0;
  local_70 = uVar24 & 0x1f | 0x4070000;
  piVar26 = (int *)((int)pvVar12 + uVar24 * 0x10 + 0xc);
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
  uVar28 = sVar23 + 1;
  local_6c = CONCAT22((*(unsigned short *)((unsigned char *)&(local_6c) + 0)),uVar28);
  _PPStreamAddAttribBinding(*(undefined4 *)(this + 0x34),&local_70);
  goto LAB_97bb63d0;
  while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
LAB_97bb630c:
    iVar17 = *piVar26;
    piVar26 = piVar26 + -1;
    if (iVar17 != 0) {
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
  local_ac = (uint)uVar28;
  local_b0 = 0;
  uVar4 = *(uint *)((int)local_e0 + iVar29);
  local_b4 = (uint)(ushort)(*(short *)(*piVar13 + 0x12) + (short)local_60);
  while ((uVar4 == uVar24 && (uVar33 < uVar25))) {
    if (uVar2 == 1) {
      uVar7 = (uVar33 & 3) << 6 | uVar7 & 0xffffff3f | 0x4000;
LAB_97bb64dc:
      local_b8 = uVar7;
    }
    else {
      if (1 < (int)uVar2) {
        if (uVar2 == 2) {
          uVar7 = (uVar33 & 3) << 4 | uVar7 & 0xffffffcf | 0x8000;
        }
        else {
          if (uVar2 != 3) goto LAB_97bb64e0;
          uVar7 = (uVar33 & 3) << 2 | uVar7 & 0xfffffff3 | 0x10000;
        }
        uVar7 = (uVar2 & 3) << 10 | uVar7 & 0xfffff3ff;
        goto LAB_97bb64dc;
      }
      if (uVar2 == 0) {
        uVar7 = (uVar33 & 3) << 8 | uVar7 & 0xfffffcff | 0x2000;
        goto LAB_97bb64dc;
      }
    }
LAB_97bb64e0:
    if (uVar2 == 1) {
      uVar3 = (*(uint *)((int)local_d0 + iVar29) & 3) << 0x13 | uVar3 & 0xffe7ffff;
LAB_97bb6544:
      local_b0 = uVar3;
    }
    else {
      if (1 < (int)uVar2) {
        if (uVar2 == 2) {
          uVar3 = (*(uint *)((int)local_d0 + iVar29) & 3) << 0x11 | uVar3 & 0xfff9ffff;
        }
        else {
          if (uVar2 != 3) goto LAB_97bb6548;
          uVar3 = (*(uint *)((int)local_d0 + iVar29) & 3) << 0xf | uVar3 & 0xfffe7fff;
        }
        goto LAB_97bb6544;
      }
      if (uVar2 == 0) {
        uVar3 = (*(uint *)((int)local_d0 + iVar29) & 3) << 0x15 | uVar3 & 0xff9fffff;
        goto LAB_97bb6544;
      }
    }
LAB_97bb6548:
    uVar33 = uVar33 + 1;
    uVar2 = uVar2 + 1;
    iVar29 = uVar33 * 4;
    uVar4 = local_e0[uVar33];
  }
  iVar27 = uVar2 - 1;
  local_b0 = iVar27 * 0x1000 & 0x3000U | uVar3;
  local_b8 = iVar27 * 0x400 & 0xc00U | uVar7 & 0xfffff3ff;
  local_bc = iVar27 * 0x4000000 & 0xc000000U | 0x800000;
  uVar2 = FunctionTable__getFirstOp(*(int *)(this + 0x3c));
  if (uVar2 == (*(uint *)(iVar32 + 0xc) & 0x3ffff)) {
    iVar27 = _PPStreamChunkListGetMaxIndex(*(undefined4 *)(*(int *)(this + 0x34) + 0x20));
    *(uint *)(iVar32 + 0xc) = iVar27 + 1U & 0x3ffff | *(uint *)(iVar32 + 0xc) & 0xfffc0000;
    uVar11 = FunctionTable__getFirstOp(*(int *)(this + 0x3c));
    _PPStreamChangeBranchTargets
              (*(undefined4 *)(this + 0x34),uVar11,*(uint *)(iVar32 + 0xc) & 0x3ffff);
  }
  iVar27 = _PPStreamInsertOperationAfterChunk
                     (*(undefined4 *)(this + 0x34),local_58,0,1,*(undefined4 *)(iVar32 + 4));
  if (iVar27 != 0) {
    FunctionTable__setFirstOp(*(int *)(this + 0x3c),uVar14);
    for (iVar17 = **(int **)(*(int *)(this + 0x34) + 0x24); iVar32 = iVar27, iVar17 != 0;
        iVar17 = *(int *)(iVar17 + 8)) {
      iVar18 = _memcmp("main(",(void *)(iVar17 + 0x14),6);
      if (iVar18 == 0) {
        *(undefined4 *)(iVar17 + 0xc) = 0;
        break;
      }
    }
  }
  if (uVar25 <= uVar33) goto LAB_97bb6720;
  goto LAB_97bb62a8;
}

/* TGenericLinker__CoalesceCommonUniforms @ 0x97bb6b48 (484 bytes) */
int TGenericLinker__CoalesceCommonUniforms(this)
  unsigned char *this;
{
  char cVar1;
  uint uVar2;
  undefined4 *puVar3;
  _PPStreamChunk *p_Var4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  TGenericLinker *pTVar10;
  char *pcVar11;
  undefined8 local_70;
  uint local_60;
  uint uStack_5c;
  
  iVar8 = 0;
  iVar7 = 0;
  pTVar10 = this;
  do {
    if (*(ParseSymbol **)(pTVar10 + 0x28) != (unsigned char *)0x0) {
      puVar3 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(pTVar10 + 0x28));
      while (puVar3 != (undefined4 *)0x0) {
        pcVar11 = (char *)*puVar3;
        if ((pcVar11 != (char *)0x0) && (*pcVar11 == '\x03')) {
          (*(unsigned int *)((unsigned char *)&(local_70) + 0)) = (uint)(*(ulonglong *)(pcVar11 + 0xc) >> 0x20);
          uVar2 = ((*(unsigned int *)((unsigned char *)&(local_70) + 0)) & 0xfcffffff) >> 0x10 & 0x1f;
          local_70 = *(ulonglong *)(pcVar11 + 0xc) & 0xfcffffffffff0000;
          if ((2 < uVar2) &&
             ((uVar2 < 0x13 &&
              (p_Var4 = (unsigned char *)
                        ParseSymbolTable__NextSymbol(*(ParseSymbol **)(pTVar10 + 0x28)),
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
                       ParseSymbolTable__NextSymbol(*(ParseSymbol **)(this + iVar7 + 0x28));
              if (p_Var4 == (unsigned char *)0x0) break;
              cVar1 = *pcVar11;
            }
          }
        }
        puVar3 = (undefined4 *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(pTVar10 + 0x28));
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
  unsigned char *this;
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
  undefined4 uVar10;
  size_t sVar11;
  size_t sVar12;
  undefined4 uVar13;
  uint uVar14;
  ushort uVar15;
  int iVar16;
  TGenericLinker *pTVar17;
  char *pcVar18;
  uint uVar19;
  uint uVar20;
  
  iVar2 = ((int (*)())BindingTable__NextUniformBinding)(*(Binding **)(this + 4));
  iVar16 = 0;
  pTVar17 = this;
  do {
    iVar3 = ((int (*)())BindingTable__GetSizeActiveUserUniforms)();
    pvVar4 = _malloc(iVar3 * 4 + 0xfU & 0xfffffff0);
    *(void **)(pTVar17 + 0x40) = pvVar4;
    if (*(int *)(pTVar17 + 0x28) == 0) {
      *(undefined4 *)(pTVar17 + 0x48) = 0;
    }
    else {
      *(undefined4 *)(pTVar17 + 0x48) = *(undefined4 *)(*(int *)(pTVar17 + 0x28) + 0x28);
    }
    for (iVar3 = 0; iVar5 = ((int (*)())BindingTable__GetSizeActiveUserUniforms)(), iVar3 < iVar5;
        iVar3 = iVar3 + 1) {
      *(undefined4 *)(iVar3 * 4 + *(int *)(pTVar17 + 0x40)) = 0xffffffff;
    }
    iVar16 = iVar16 + 1;
    pTVar17 = pTVar17 + 4;
  } while (iVar16 < 2);
  while (iVar2 != 0) {
    iVar2 = Binding__IsBuiltIn();
    if (iVar2 == 0) {
      uVar15 = 0;
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
                    
                    
            uVar10 = (*(code *)(((unsigned char *)0x97bb6ea0) + (*(unsigned char *)0x97bb6eac)))();
            return uVar10;
          }
          if (bVar1) {
            if (*(ushort *)(piVar6 + 0xb) != uVar15) {
              pcVar18 = (char *)piVar6[5];
              sVar7 = _strlen(DAT_a7b7bae4);
              sVar8 = _strlen(pcVar18);
              pcVar9 = (char *)GetShaderStringForType(uVar15);
              sVar11 = _strlen(pcVar9);
              pcVar9 = (char *)GetShaderStringForType(*(ushort *)(piVar6 + 0xb));
              sVar12 = _strlen(pcVar9);
              pcVar9 = _malloc(sVar7 + sVar8 + sVar11 + sVar12 + 1);
              uVar10 = GetShaderStringForType(*(ushort *)(piVar6 + 0xb));
              uVar13 = GetShaderStringForType(uVar15);
              _sprintf(pcVar9,DAT_a7b7bae4,pcVar18,uVar13,uVar10);
                    
                    
              uVar10 = (*(code *)(((unsigned char *)0x97bb6fd8) + (*(unsigned char *)0x97bb6fe0)))();
              return uVar10;
            }
          }
          else {
            uVar15 = *(ushort *)(piVar6 + 0xb);
            bVar1 = true;
          }
          uVar20 = (uint)*(ushort *)(*piVar6 + 0xe);
          for (uVar19 = 0; uVar14 = Binding__GetBindingSlots(), uVar19 < uVar14; uVar19 = uVar19 + 1
              ) {
            iVar16 = Binding__GetLocation();
            *(uint *)((iVar16 + uVar19) * 4 + *(int *)(this + iVar2 * 4 + 0x40)) = uVar20;
            uVar20 = uVar20 + 1;
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 2);
    }
    iVar2 = ((int (*)())BindingTable__NextUniformBinding)(*(Binding **)(this + 4));
  }
  iVar2 = 0;
  iVar16 = 0;
  for (iVar3 = 0; iVar5 = ((int (*)())BindingTable__GetSizeActiveUserUniforms)(), iVar3 < iVar5;
      iVar3 = iVar3 + 1) {
    if (*(int *)(iVar3 * 4 + *(int *)(this + 0x40)) != -1) {
      iVar2 = iVar2 + 1;
    }
    if (*(int *)(iVar3 * 4 + *(int *)(this + 0x44)) != -1) {
      iVar16 = iVar16 + 1;
    }
  }
  if (*(int *)(this + 0x48) != iVar2) {
                    
                    
    uVar10 = (*(code *)(((unsigned char *)0x97bb7140) + (*(unsigned char *)0x97bb714c)))();
    return uVar10;
  }
  if (*(int *)(this + 0x4c) != iVar16) {
                    
                    
    uVar10 = (*(code *)(((unsigned char *)0x97bb71ec) + (*(unsigned char *)0x97bb71f8)))();
    return uVar10;
  }
  return 1;
}

/* TGenericLinker__InsertUniformBindingFromSymbol @ 0x97bb727c (412 bytes) */
int TGenericLinker__InsertUniformBindingFromSymbol(this, param_1, param_2)
  unsigned char *this;
  unsigned char *param_1;
  int param_2;
{
  Binding *this_00;
  int iVar1;
  size_t sVar2;
  size_t sVar3;
  char *pcVar4;
  undefined4 uVar5;
  char *pcVar6;
  
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
                    
                    
      uVar5 = (*(code *)(((unsigned char *)0x97bb7400) + (*(unsigned char *)0x97bb740c)))();
      return uVar5;
    }
    Binding__SetName((char *)this_00);
    iVar1 = ((int (*)())BindingTable__FindUniformBinding)(*(Binding **)(this + 4));
    if (iVar1 == 0) {
      Binding__SetClientRequest(SUB41(this_00,0));
      Binding__SetOpenGLType((ushort)this_00);
      Binding__SetDecSize((ulong)this_00);
      Binding__SetActualSize((ulong)this_00);
      Binding__SetBuiltIn(SUB41(this_00,0));
      if (*(short *)(param_1 + 0x2e) == 1) {
        ((int (*)())BindingTable__InsertSingleUniform)(*(Binding **)(this + 4),(int)this_00);
      }
      else {
        ((int (*)())BindingTable__InsertUniformArray)(*(Binding **)(this + 4),(int)this_00,(int)*(short *)(param_1 + 0x30),param_2,
                   (ParseSymbolTable **)0x2);
      }
    }
    else {
      if (*(short *)(param_1 + 0x2e) == 1) {
        ((int (*)())BindingTable__AddSingleUniformReference)(*(Binding **)(this + 4),iVar1);
      }
      Binding___Binding(this_00);
      operator_delete(this_00);
    }
  }
  return 1;
}

/* TGenericLinker__CollectUniformBindings @ 0x97bb7498 (296 bytes) */
int TGenericLinker__CollectUniformBindings(this)
  unsigned char *this;
{
  ParseSymbol *pPVar1;
  int iVar2;
  undefined4 uVar3;
  TGenericLinker *pTVar4;
  int iVar5;
  TGenericLinker *pTVar6;
  
  uVar3 = 1;
  iVar5 = 0;
  pTVar6 = this + 0x28;
  pTVar4 = this;
  do {
    pPVar1 = *(ParseSymbol **)pTVar6;
    pTVar6 = pTVar6 + 4;
    if (pPVar1 != (unsigned char *)0x0) {
      pPVar1 = (unsigned char *)ParseSymbolTable__NextSymbol(pPVar1);
      while (pPVar1 != (unsigned char *)0x0) {
        if ((*(int *)(pPVar1 + 0x34) == 0) &&
           (iVar2 = ((int (*)())TGenericLinker__InsertUniformBindingFromSymbol)(this,pPVar1,iVar5), iVar2 == 0)) {
          uVar3 = 0;
        }
        pPVar1 = (unsigned char *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(pTVar4 + 0x28));
      }
    }
    iVar5 = iVar5 + 1;
    pTVar4 = pTVar4 + 4;
  } while (iVar5 < 2);
  iVar5 = 0;
  pTVar6 = this + 0x28;
  pTVar4 = this;
  do {
    pPVar1 = *(ParseSymbol **)pTVar6;
    pTVar6 = pTVar6 + 4;
    if (pPVar1 != (unsigned char *)0x0) {
      pPVar1 = (unsigned char *)ParseSymbolTable__NextSymbol(pPVar1);
      while (pPVar1 != (unsigned char *)0x0) {
        if ((*(int *)(pPVar1 + 0x34) != 0) &&
           (iVar2 = ((int (*)())TGenericLinker__InsertUniformBindingFromSymbol)(this,pPVar1,iVar5), iVar2 == 0)) {
          uVar3 = 0;
        }
        pPVar1 = (unsigned char *)ParseSymbolTable__NextSymbol(*(ParseSymbol **)(pTVar4 + 0x28));
      }
    }
    iVar5 = iVar5 + 1;
    pTVar4 = pTVar4 + 4;
  } while (iVar5 < 2);
  return uVar3;
}

/* TGenericLinker__CreateFunctionTable @ 0x97bb75c0 (1156 bytes) */
int TGenericLinker__CreateFunctionTable(this, param_1)
  unsigned char *this;
  int param_1;
{
  int iVar1;
  bool bVar2;
  bool bVar3;
  FunctionTable *pFVar4;
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
  
  iVar1 = param_1 * 4;
  pFVar4 = operator_new(8);
  FunctionTable__FunctionTable(pFVar4);
  iVar11 = 0;
  if (0 < *(int *)(this + iVar1 + 0x20)) {
    do {
      iVar13 = 0;
      iVar14 = *(int *)(*(int *)(iVar11 * 4 + *(int *)(this + iVar1 + 8)) + 0x6c);
      if (0 < *(int *)(iVar14 + 4)) {
        do {
          iVar12 = 0;
          if (0 < iVar11) {
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
                    
                    
                    pFVar4 = (unsigned char *)(*(code *)(((unsigned char *)0x97bb776c) + (*(unsigned char *)0x97bb7774)))();
                    return pFVar4;
                  }
                  iVar16 = iVar16 + 1;
                } while (iVar16 < *(int *)(iVar15 + 4));
              }
              iVar12 = iVar12 + 1;
            } while (iVar12 < iVar11);
          }
          FunctionTable__getFunctionName(iVar14);
          uVar17 = FunctionTable__addFunction((char *)pFVar4);
          FunctionTable__getEmpty(iVar14);
          FunctionTable__setEmpty((int)pFVar4,SUB41(uVar17,0));
          FunctionTable__getReturnVal(iVar14);
          FunctionTable__setReturnVal((int)pFVar4,SUB41(uVar17,0));
          FunctionTable__getNumParams(iVar14);
          FunctionTable__setNumParams((int)pFVar4,uVar17);
          FunctionTable__getFirstOp(iVar14);
          FunctionTable__setFirstOp((int)pFVar4,uVar17);
          FunctionTable__getLastOp(iVar14);
          FunctionTable__setLastOp((int)pFVar4,uVar17);
          iVar13 = iVar13 + 1;
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
                    
                    
            pFVar4 = (unsigned char *)(*(code *)(((unsigned char *)0x97bb7a58) + (*(unsigned char *)0x97bb7a60)))();
            return pFVar4;
          }
LAB_97bb7ad8:
          _free(pcVar5);
        }
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < *(int *)(this + iVar1 + 0x20));
  }
  if (*(int *)(pFVar4 + 4) == 0) {
    if (pFVar4 != (unsigned char *)0x0) {
      FunctionTable___FunctionTable(pFVar4);
      operator_delete(pFVar4);
    }
    pFVar4 = (unsigned char *)0x0;
  }
  return pFVar4;
}

/* TGenericLinker__BuildSymbolTableList @ 0x97bb7b4c (968 bytes) */
int TGenericLinker__BuildSymbolTableList(this, param_1, param_2)
  unsigned char *this;
  void **param_1;
  int param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  size_t sVar4;
  size_t sVar5;
  char *pcVar6;
  undefined4 uVar7;
  void *pvVar8;
  int *piVar9;
  int iVar10;
  int iVar11;
  TGenericLinker *pTVar12;
  int local_50 [2];
  undefined8 local_48;
  undefined8 local_40 [2];
  
  iVar11 = 0;
  local_50[0] = 0;
  local_50[1] = 0;
  local_48 = DAT_97c38fb0;
  local_40[0] = DAT_97c38fb8;
  if (0 < param_2) {
    do {
      if (param_1[iVar11] == (int *)0x0) {
                    
                    
        uVar7 = (*(code *)(((unsigned char *)0x97bb7cdc) + (*(unsigned char *)0x97bb7ce8)))();
        return uVar7;
      }
      iVar3 = (**(code **)(*(int *)param_1[iVar11] + 8))();
      if (iVar3 == 0) {
                    
                    
        uVar7 = (*(code *)(((unsigned char *)0x97bb7c9c) + (*(unsigned char *)0x97bb7ca8)))();
        return uVar7;
      }
      iVar1 = 0;
      if (*(int *)(iVar3 + 8) != 0) {
        if (*(int *)(iVar3 + 8) != 1) {
                    
                    
          uVar7 = (*(code *)(((unsigned char *)0x97bb7c5c) + (*(unsigned char *)0x97bb7c68)))();
          return uVar7;
        }
        iVar1 = 1;
      }
      iVar2 = iVar1 * 4;
      if (*(int *)(iVar3 + 0xac) != 0) {
        local_50[iVar1] = local_50[iVar1] + 1;
        *(int *)((int)local_40 + iVar2 + -8) = iVar11;
      }
      *(int *)(this + iVar2 + 0x20) = *(int *)(this + iVar2 + 0x20) + 1;
      iVar11 = iVar11 + 1;
    } while (iVar11 < param_2);
  }
  iVar11 = 0;
  do {
    if ((local_50[iVar11] == 0) && (0 < *(int *)(this + iVar11 * 4 + 0x20))) {
      sVar4 = _strlen(DAT_a7b7bab8);
      sVar5 = _strlen((char *)(&_shaderString)[iVar11]);
      pcVar6 = _malloc(sVar4 + sVar5 + 1);
      _sprintf(pcVar6,DAT_a7b7bab8,(&_shaderString)[iVar11]);
                    
                    
      uVar7 = (*(code *)(((unsigned char *)0x97bb7df8) + (*(unsigned char *)0x97bb7e00)))();
      return uVar7;
    }
    if (1 < local_50[iVar11]) {
      sVar4 = _strlen(DAT_a7b7babc);
      sVar5 = _strlen((char *)(&_shaderString)[iVar11]);
      pcVar6 = _malloc(sVar4 + sVar5 + 9);
      _sprintf(pcVar6,DAT_a7b7babc,local_50[iVar11],(&_shaderString)[iVar11]);
                    
                    
      uVar7 = (*(code *)(((unsigned char *)0x97bb7e7c) + (*(unsigned char *)0x97bb7e84)))();
      return uVar7;
    }
    iVar11 = iVar11 + 1;
  } while (iVar11 < 2);
  pTVar12 = this;
  do {
    pvVar8 = _malloc(*(int *)(pTVar12 + 0x20) << 2);
    *(void **)(pTVar12 + 8) = pvVar8;
    pvVar8 = _malloc(*(int *)(pTVar12 + 0x20) << 2);
    *(void **)(pTVar12 + 0x10) = pvVar8;
    pvVar8 = _malloc(*(int *)(pTVar12 + 0x20) << 2);
    *(void **)(pTVar12 + 0x18) = pvVar8;
    pTVar12 = pTVar12 + 4;
  } while ((int)pTVar12 <= (int)(this + 4));
  iVar11 = 0;
  if (0 < param_2) {
    do {
      piVar9 = *param_1;
      param_1 = param_1 + 1;
      if ((piVar9 != (int *)0x0) && (iVar3 = (**(code **)(*piVar9 + 8))(), iVar3 != 0)) {
        iVar1 = (uint)(*(int *)(iVar3 + 8) != 0) * 4;
        if (*(int *)((int)local_40 + iVar1 + -8) == iVar11) {
          **(int **)(this + iVar1 + 8) = iVar3;
          **(undefined4 **)(this + iVar1 + 0x10) = *(undefined4 *)(iVar3 + 0x68);
          **(undefined4 **)(this + iVar1 + 0x18) = *(undefined4 *)(iVar3 + 0x70);
        }
        else {
          *(int *)(*(int *)((int)local_40 + iVar1) * 4 + *(int *)(this + iVar1 + 8)) = iVar3;
          *(undefined4 *)(*(int *)((int)local_40 + iVar1) * 4 + *(int *)(this + iVar1 + 0x10)) =
               *(undefined4 *)(iVar3 + 0x68);
          iVar2 = *(int *)((int)local_40 + iVar1);
          iVar10 = *(int *)(this + iVar1 + 0x18);
          *(int *)((int)local_40 + iVar1) = iVar2 + 1;
          *(undefined4 *)(iVar2 * 4 + iVar10) = *(undefined4 *)(iVar3 + 0x70);
        }
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < param_2);
  }
  return 1;
}

/* TGenericLinker__BuildProcessingComponents @ 0x97bb8054 (200 bytes) */
int TGenericLinker__BuildProcessingComponents(param_1, param_2)
  void **param_1;
  int param_2;
{
  void *pvVar1;
  ParseSymbolTable *pPVar2;
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
                                    *(_PPStream **)(*(int *)ppvVar5[2] + 0x70),pPVar2);
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
  unsigned char *this;
  int param_1;
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  BindingTable *this_00;
  TGenericLinker *pTVar5;
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
  *(BindingTable **)(this + 4) = this_00;
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
  unsigned char *this;
  int param_1;
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  BindingTable *this_00;
  TGenericLinker *pTVar5;
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
  *(BindingTable **)(this + 4) = this_00;
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
  unsigned char *this;
  int param_1;
{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  BindingTable *this_00;
  TGenericLinker *pTVar5;
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
  *(BindingTable **)(this + 4) = this_00;
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
  unsigned char *this;
{
  ~TGenericLinker(this);
  return;
}

/* TGenericLinker___TGenericLinker_97bb8238 @ 0x97bb8238 (8 bytes) */
int TGenericLinker___TGenericLinker_97bb8238(this)
  unsigned char *this;
{
  ~TGenericLinker(this);
  return;
}

