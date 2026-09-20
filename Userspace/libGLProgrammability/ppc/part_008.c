#include "decls.h"

/* Binding__GetLocation @ 0x97bb0460 (8 bytes) */
int Binding__GetLocation(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x14);
}

/* Binding__SetLocation @ 0x97bb0468 (8 bytes) */
int Binding__SetLocation(this, param_2)
  unsigned char * this;
  int param_2;
{
  *(int *)(this + 0x14) = param_2;
  return;
}

/* Binding__GetActiveIndex @ 0x97bb0470 (8 bytes) */
int Binding__GetActiveIndex(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x20);
}

/* Binding__SetActiveIndex @ 0x97bb0478 (8 bytes) */
int Binding__SetActiveIndex(this, param_2)
  unsigned char * this;
  int param_2;
{
  *(int *)(this + 0x20) = param_2;
  return;
}

/* Binding__SetOpenGLType @ 0x97bb0480 (8 bytes) */
int Binding__SetOpenGLType(this, param_2)
  unsigned char * this;
  int param_2;
{
  *(ushort *)(this + 0x24) = param_2;
  return;
}

/* Binding__GetOpenGLType @ 0x97bb0488 (8 bytes) */
int Binding__GetOpenGLType(this)
  unsigned char * this;
{
  return *(undefined2 *)(this + 0x24);
}

/* Binding__GetBindingBasicSize @ 0x97bb0490 (8 bytes) */
int Binding__GetBindingBasicSize(this)
  unsigned char * this;
{
  GetVec4sForType(*(ushort *)(this + 0x24));
  return;
}

/* Binding__GetBindingSlots @ 0x97bb0498 (8 bytes) */
int Binding__GetBindingSlots(this)
  unsigned char * this;
{
  GetVec4sForType(*(ushort *)(this + 0x24));
  return;
}

/* Binding__SetDecSize @ 0x97bb04a0 (8 bytes) */
int Binding__SetDecSize(this, param_2)
  unsigned char * this;
  ulong param_2;
{
  *(ulong *)(this + 0x18) = param_2;
  return;
}

/* Binding__SetActualSize @ 0x97bb04a8 (8 bytes) */
int Binding__SetActualSize(this, param_2)
  unsigned char * this;
  ulong param_2;
{
  *(ulong *)(this + 0x1c) = param_2;
  return;
}

/* Binding__GetDecSize @ 0x97bb04b0 (8 bytes) */
int Binding__GetDecSize(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x18);
}

/* Binding__GetActualSize @ 0x97bb04b8 (8 bytes) */
int Binding__GetActualSize(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x1c);
}

/* Binding__GetNextBinding @ 0x97bb04c0 (8 bytes) */
int Binding__GetNextBinding(this)
  unsigned char * this;
{
  return *(undefined4 *)this;
}

/* Binding__GetNextBindingInHash @ 0x97bb04c8 (8 bytes) */
int Binding__GetNextBindingInHash(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 4);
}

/* Binding__SetNextBinding @ 0x97bb04d0 (8 bytes) */
int Binding__SetNextBinding(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  *(unsigned char **)this = param_2;
  return;
}

/* Binding__SetNextBindingInHash @ 0x97bb04d8 (8 bytes) */
int Binding__SetNextBindingInHash(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  *(unsigned char **)(this + 4) = param_2;
  return;
}

/* Binding__GetString @ 0x97bb04e0 (256 bytes) */
int Binding__GetString(this)
  unsigned char * this;
{
  int iVar1;
  size_t sVar2;
  ushort uVar9;
  char *pcVar3;
  size_t sVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined8 local_30 [2];
  
  local_30[0] = _PTR_s__02d____02d____s____s__c__c_a7b7d6bc;
  iVar1 = Binding__IsClientRequest(this);
  sVar2 = _strlen(*(char **)((int)local_30 + iVar1 * 4));
  iVar1 = *(int *)(this + 0x10);
  uVar9 = ((int (*)())Binding__GetOpenGLType)(this);
  pcVar3 = (char *)GetGLStringForType(uVar9);
  sVar4 = _strlen(pcVar3);
  pcVar5 = _malloc(sVar2 + iVar1 + sVar4 + 0x15);
  pcVar3 = (char *)0x0;
  if (pcVar5 != (char *)0x0) {
    iVar1 = Binding__IsClientRequest(this);
    uVar6 = ((int (*)())Binding__GetActiveIndex)(this);
    uVar7 = ((int (*)())Binding__GetLocation)(this);
    uVar9 = ((int (*)())Binding__GetOpenGLType)(this);
    uVar12 = *(undefined4 *)(this + 8);
    uVar8 = GetGLStringForType(uVar9);
    uVar10 = 0x56;
    if (this[0x34] == 0x0) {
      uVar10 = 0x20;
    }
    uVar11 = 0x46;
    if (this[0x35] == 0x0) {
      uVar11 = 0x20;
    }
    _sprintf(pcVar5,*(char **)((int)local_30 + iVar1 * 4),uVar6,uVar7,uVar12,uVar8,uVar10,uVar11);
    pcVar3 = pcVar5;
  }
  return pcVar3;
}

/* __ZN12BindingTableC2Ej @ 0x97bb05e0 (4 bytes) */
int __ZN12BindingTableC2Ej(this, param_2)
  void *this;
  uint param_2;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  
  *(uint *)this = param_2;
  pvVar3 = operator_new__(param_2 << 2);
  uVar4 = 0;
  *(void **)((int)this + 8) = pvVar3;
  *(undefined4 *)((int)this + 4) = 0;
  uVar2 = 0;
  if (*(int *)this != 0) {
    do {
      iVar1 = uVar4 * 4;
      uVar4 = uVar4 + 1;
      *(undefined4 *)(iVar1 + *(int *)((int)this + 8)) = 0;
      uVar2 = *(uint *)this;
    } while (uVar4 < uVar2);
  }
  pvVar3 = operator_new__(uVar2 << 2);
  uVar4 = 0;
  *(void **)((int)this + 0x10) = pvVar3;
  *(undefined4 *)((int)this + 0xc) = 0;
  uVar2 = 0;
  if (*(int *)this != 0) {
    do {
      iVar1 = uVar4 * 4;
      uVar4 = uVar4 + 1;
      *(undefined4 *)(iVar1 + *(int *)((int)this + 0x10)) = 0;
      uVar2 = *(uint *)this;
    } while (uVar4 < uVar2);
  }
  pvVar3 = operator_new__(uVar2 << 2);
  uVar2 = 0;
  *(void **)((int)this + 0x18) = pvVar3;
  *(undefined4 *)((int)this + 0x14) = 0;
  if (*(int *)this != 0) {
    do {
      iVar1 = uVar2 * 4;
      uVar2 = uVar2 + 1;
      *(undefined4 *)(iVar1 + *(int *)((int)this + 0x18)) = 0;
    } while (uVar2 < *(uint *)this);
  }
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  return;
}

/* __ZN12BindingTableC1Ej @ 0x97bb05e4 (4 bytes) */
int __ZN12BindingTableC1Ej(this, param_2)
  void *this;
  uint param_2;
{
  ((int (*)())__ZN12BindingTableC4Ej)(this,param_2);
  return;
}

/* __ZN12BindingTableC4Ej @ 0x97bb05e8 (288 bytes) */
int __ZN12BindingTableC4Ej(this, param_2)
  void *this;
  uint param_2;
{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  
  *(uint *)this = param_2;
  pvVar3 = operator_new__(param_2 << 2);
  uVar4 = 0;
  *(void **)((int)this + 8) = pvVar3;
  *(undefined4 *)((int)this + 4) = 0;
  uVar2 = 0;
  if (*(int *)this != 0) {
    do {
      iVar1 = uVar4 * 4;
      uVar4 = uVar4 + 1;
      *(undefined4 *)(iVar1 + *(int *)((int)this + 8)) = 0;
      uVar2 = *(uint *)this;
    } while (uVar4 < uVar2);
  }
  pvVar3 = operator_new__(uVar2 << 2);
  uVar4 = 0;
  *(void **)((int)this + 0x10) = pvVar3;
  *(undefined4 *)((int)this + 0xc) = 0;
  uVar2 = 0;
  if (*(int *)this != 0) {
    do {
      iVar1 = uVar4 * 4;
      uVar4 = uVar4 + 1;
      *(undefined4 *)(iVar1 + *(int *)((int)this + 0x10)) = 0;
      uVar2 = *(uint *)this;
    } while (uVar4 < uVar2);
  }
  pvVar3 = operator_new__(uVar2 << 2);
  uVar2 = 0;
  *(void **)((int)this + 0x18) = pvVar3;
  *(undefined4 *)((int)this + 0x14) = 0;
  if (*(int *)this != 0) {
    do {
      iVar1 = uVar2 * 4;
      uVar2 = uVar2 + 1;
      *(undefined4 *)(iVar1 + *(int *)((int)this + 0x18)) = 0;
    } while (uVar2 < *(uint *)this);
  }
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x1c) = 0;
  *(undefined4 *)((int)this + 0x20) = 0;
  *(undefined4 *)((int)this + 0x24) = 0;
  *(undefined4 *)((int)this + 0x28) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  return;
}

/* __ZN12BindingTableD2Ev @ 0x97bb0708 (8 bytes) */
int __ZN12BindingTableD2Ev(this)
  void *this;
{
  ((int (*)())__ZN12BindingTableD4Ev)(this);
  return;
}

/* __ZN12BindingTableD1Ev @ 0x97bb0710 (8 bytes) */
int __ZN12BindingTableD1Ev(this)
  void *this;
{
  ((int (*)())__ZN12BindingTableD4Ev)(this);
  return;
}

/* __ZN12BindingTableD4Ev @ 0x97bb0718 (148 bytes) */
int __ZN12BindingTableD4Ev(this)
  void *this;
{
  bool bVar1;
  unsigned char * pBVar2;
  unsigned char * this_00;
  
  this_00 = *(unsigned char **)((int)this + 4);
  bVar1 = this_00 == (unsigned char *)0x0;
  if (!bVar1) {
    while( true ) {
      pBVar2 = (unsigned char *)((int (*)())Binding__GetNextBinding)(this_00);
      if (!bVar1) {
        __ZN7BindingD1Ev(this_00);
        __ZdlPv(this_00);
      }
      if (pBVar2 == (unsigned char *)0x0) break;
      bVar1 = false;
      this_00 = pBVar2;
    }
  }
  ((int (*)())BindingTable__ClearInternalBindings)(this);
  __ZdlPv(*(void **)((int)this + 8));
  __ZdlPv(*(void **)((int)this + 0x10));
  __ZdlPv(*(void **)((int)this + 0x18));
  return;
}

/* BindingTable__ClearInternalBindings @ 0x97bb07ac (336 bytes) */
int BindingTable__ClearInternalBindings(this)
  unsigned char * this;
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  unsigned char * pBVar4;
  uint uVar5;
  unsigned char * pBVar6;
  
  pBVar6 = *(unsigned char **)(this + 0xc);
  *(undefined4 *)(this + 0x40) = 0;
  bVar1 = pBVar6 == (unsigned char *)0x0;
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x20) = 0;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x34) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  *(undefined4 *)(this + 0x30) = 0;
  *(undefined4 *)(this + 0x38) = 0;
  *(undefined4 *)(this + 0x3c) = 0;
  *(undefined4 *)(this + 0x44) = 0;
  if (!bVar1) {
    while( true ) {
      pBVar4 = (unsigned char *)((int (*)())Binding__GetNextBinding)(pBVar6);
      if (!bVar1) {
        __ZN7BindingD1Ev(pBVar6);
        __ZdlPv(pBVar6);
      }
      if (pBVar4 == (unsigned char *)0x0) break;
      bVar1 = false;
      pBVar6 = pBVar4;
    }
  }
  pBVar6 = *(unsigned char **)(this + 0x14);
  *(undefined4 *)(this + 0xc) = 0;
  bVar1 = pBVar6 == (unsigned char *)0x0;
  if (!bVar1) {
    while( true ) {
      pBVar4 = (unsigned char *)((int (*)())Binding__GetNextBinding)(pBVar6);
      if (!bVar1) {
        __ZN7BindingD1Ev(pBVar6);
        __ZdlPv(pBVar6);
      }
      if (pBVar4 == (unsigned char *)0x0) break;
      bVar1 = false;
      pBVar6 = pBVar4;
    }
  }
  uVar5 = 0;
  *(undefined4 *)(this + 0x14) = 0;
  uVar3 = 0;
  if (*(int *)this != 0) {
    do {
      iVar2 = uVar5 * 4;
      uVar5 = uVar5 + 1;
      *(undefined4 *)(iVar2 + *(int *)(this + 0x10)) = 0;
      uVar3 = *(uint *)this;
    } while (uVar5 < uVar3);
  }
  uVar5 = 0;
  if (uVar3 != 0) {
    do {
      iVar2 = uVar5 * 4;
      uVar5 = uVar5 + 1;
      *(undefined4 *)(iVar2 + *(int *)(this + 0x18)) = 0;
    } while (uVar5 < *(uint *)this);
  }
  return;
}

/* BindingTable__InsertAttribRequestBinding @ 0x97bb08fc (244 bytes) */
int BindingTable__InsertAttribRequestBinding(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  unsigned char * pBVar1;
  int iVar2;
  unsigned char * pBVar3;
  
  if (param_2 != (unsigned char *)0x0) {
    pBVar1 = (unsigned char *)((int (*)())BindingTable__FindAttribRequestBinding)(this,param_2);
    if (pBVar1 == (unsigned char *)0x0) {
      pBVar1 = *(unsigned char **)(this + 4);
      if (*(unsigned char **)(this + 4) == (unsigned char *)0x0) {
        *(unsigned char **)(this + 4) = param_2;
        iVar2 = Binding__GetHash(param_2,*(uint *)this);
        *(unsigned char **)(iVar2 * 4 + *(int *)(this + 8)) = param_2;
      }
      else {
        do {
          pBVar3 = pBVar1;
          pBVar1 = (unsigned char *)((int (*)())Binding__GetNextBinding)(pBVar3);
        } while (pBVar1 != (unsigned char *)0x0);
        ((int (*)())Binding__SetNextBinding)(pBVar3,param_2);
        iVar2 = Binding__GetHash(param_2,*(uint *)this);
        pBVar1 = *(unsigned char **)(iVar2 * 4 + *(int *)(this + 8));
        if (pBVar1 == (unsigned char *)0x0) {
          *(unsigned char **)(iVar2 * 4 + *(int *)(this + 8)) = param_2;
        }
        else {
          do {
            pBVar3 = pBVar1;
            pBVar1 = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(pBVar3);
          } while (pBVar1 != (unsigned char *)0x0);
          ((int (*)())Binding__SetNextBindingInHash)(pBVar3,param_2);
        }
      }
      return 1;
    }
    iVar2 = ((int (*)())Binding__GetLocation)(param_2);
    ((int (*)())Binding__SetLocation)(pBVar1,iVar2);
  }
  return 0;
}

/* BindingTable__NextAttribRequestBinding @ 0x97bb09f0 (24 bytes) */
int BindingTable__NextAttribRequestBinding(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  undefined4 uVar1;
  
  if (param_2 != (unsigned char *)0x0) {
    uVar1 = ((int (*)())Binding__GetNextBinding)(param_2);
    return uVar1;
  }
  return *(undefined4 *)(this + 4);
}

/* BindingTable__FindAttribRequestBinding @ 0x97bb0a08 (116 bytes) */
int BindingTable__FindAttribRequestBinding(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  unsigned char * this_00;
  
  iVar1 = Binding__GetHash(param_2,*(uint *)this);
  this_00 = *(unsigned char **)(iVar1 * 4 + *(int *)(this + 8));
  while ((this_00 != (unsigned char *)0x0 && (iVar1 = __ZeqRK7BindingS1_(this_00,param_2), iVar1 != 1))) {
    this_00 = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(this_00);
  }
  return this_00;
}

/* BindingTable__FindAttribRequestBindingLocationByName @ 0x97bb0a7c (228 bytes) */
int BindingTable__FindAttribRequestBindingLocationByName(this, param_2)
  unsigned char * this;
  char *param_2;
{
  unsigned char * this_00;
  int iVar1;
  undefined4 uVar2;
  unsigned char * this_01;
  
  if (param_2 != (char *)0x0) {
    this_00 = operator_new(0x38);
    __ZN7BindingC1Ev(this_00);
    if (this_00 != (unsigned char *)0x0) {
      Binding__SetName(this_00,param_2);
      iVar1 = Binding__GetHash(this_00,*(uint *)this);
      this_01 = *(unsigned char **)(iVar1 * 4 + *(int *)(this + 8));
      while ((this_01 != (unsigned char *)0x0 && (iVar1 = __ZeqRK7BindingS1_(this_01,this_00), iVar1 != 1)
             )) {
        this_01 = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(this_01);
      }
      __ZN7BindingD1Ev(this_00);
      __ZdlPv(this_00);
      if (this_01 != (unsigned char *)0x0) {
        uVar2 = ((int (*)())Binding__GetLocation)(this_01);
        return uVar2;
      }
    }
  }
  return 0xffffffff;
}

/* BindingTable__InsertClientAttribBinding @ 0x97bb0b60 (368 bytes) */
int BindingTable__InsertClientAttribBinding(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  unsigned char * this_00;
  int iVar1;
  int iVar2;
  unsigned char * pBVar3;
  unsigned char * pBVar4;
  unsigned char * this_01;
  
  if (param_2 == (unsigned char *)0x0) {
    return 0;
  }
  this_00 = operator_new(0x38);
  __ZN7BindingC1ERKS_(this_00,param_2);
  pBVar4 = *(unsigned char **)(this + 0xc);
  if (pBVar4 != (unsigned char *)0x0) {
    iVar1 = ((int (*)())Binding__GetLocation)(this_00);
    pBVar3 = (unsigned char *)0x0;
    this_01 = pBVar4;
    do {
      iVar2 = ((int (*)())Binding__GetLocation)(this_01);
      pBVar4 = this_01;
      if (iVar1 < iVar2) break;
      pBVar4 = (unsigned char *)((int (*)())Binding__GetNextBinding)(this_01);
      pBVar3 = this_01;
      this_01 = pBVar4;
    } while (pBVar4 != (unsigned char *)0x0);
    if (pBVar3 != (unsigned char *)0x0) {
      ((int (*)())Binding__SetNextBinding)(pBVar3,this_00);
      goto LAB_97bb0bf0;
    }
  }
  *(unsigned char **)(this + 0xc) = this_00;
LAB_97bb0bf0:
  ((int (*)())Binding__SetNextBinding)(this_00,pBVar4);
  iVar1 = Binding__GetHash(this_00,*(uint *)this);
  pBVar4 = *(unsigned char **)(iVar1 * 4 + *(int *)(this + 0x10));
  if (pBVar4 == (unsigned char *)0x0) {
    *(unsigned char **)(iVar1 * 4 + *(int *)(this + 0x10)) = this_00;
  }
  else {
    do {
      pBVar3 = pBVar4;
      pBVar4 = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(pBVar3);
    } while (pBVar4 != (unsigned char *)0x0);
    ((int (*)())Binding__SetNextBindingInHash)(pBVar3,this_00);
  }
  ((int (*)())Binding__SetNextBindingInHash)(this_00,(unsigned char *)0x0);
  iVar1 = *(int *)(this + 0x1c);
  *(int *)(this + 0x1c) = iVar1 + 1;
  ((int (*)())Binding__SetActiveIndex)(this_00,iVar1);
  iVar1 = Binding__IsBuiltIn(this_00);
  if (iVar1 == 0) {
    iVar1 = ((int (*)())Binding__GetBindingSlots)(this_00);
    *(int *)(this + 0x28) = *(int *)(this + 0x28) + iVar1;
  }
  iVar1 = ((int (*)())Binding__GetBindingSlots)(this_00);
  *(int *)(this + 0x34) = *(int *)(this + 0x34) + iVar1;
  if (*(int *)(this + 0x38) < *(int *)(this_00 + 0x10) + 1) {
    *(int *)(this + 0x38) = *(int *)(this_00 + 0x10) + 1;
  }
  return 1;
}

/* BindingTable__InsertAttribBinding @ 0x97bb0cd0 (508 bytes) */
int BindingTable__InsertAttribBinding(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  unsigned char * pBVar5;
  unsigned char * pBVar6;
  unsigned char * this_00;
  
  uVar1 = 0;
  if (param_2 != (unsigned char *)0x0) {
    iVar3 = 0;
    iVar2 = Binding__IsBuiltIn(param_2);
    pBVar6 = *(unsigned char **)(this + 0xc);
    iVar4 = 1;
    if ((iVar2 != 0) && (iVar2 = _memcmp(*(void **)(param_2 + 8),"gl_Vertex",10), iVar2 == 0)) {
      if ((pBVar6 != (unsigned char *)0x0) && (iVar2 = ((int (*)())Binding__GetLocation)(pBVar6), iVar2 == 0)) {
        return 0;
      }
      iVar4 = 0;
    }
    pBVar5 = (unsigned char *)0x0;
    if (pBVar6 != (unsigned char *)0x0) {
      do {
        this_00 = pBVar6;
        iVar4 = iVar3 + iVar4;
        iVar2 = ((int (*)())Binding__GetLocation)(this_00);
        iVar3 = ((int (*)())Binding__GetBindingSlots)(param_2);
        pBVar6 = this_00;
        if (iVar4 + iVar3 <= iVar2) goto LAB_97bb0db4;
        iVar3 = ((int (*)())Binding__GetLocation)(this_00);
        iVar4 = ((int (*)())Binding__GetBindingSlots)(this_00);
        pBVar6 = (unsigned char *)((int (*)())Binding__GetNextBinding)(this_00);
        pBVar5 = this_00;
      } while (pBVar6 != (unsigned char *)0x0);
      iVar4 = iVar3 + iVar4;
    }
LAB_97bb0db4:
    if (pBVar5 == (unsigned char *)0x0) {
      *(unsigned char **)(this + 0xc) = param_2;
    }
    else {
      ((int (*)())Binding__SetNextBinding)(pBVar5,param_2);
    }
    ((int (*)())Binding__SetNextBinding)(param_2,pBVar6);
    ((int (*)())Binding__SetLocation)(param_2,iVar4);
    iVar2 = Binding__GetHash(param_2,*(uint *)this);
    pBVar6 = *(unsigned char **)(iVar2 * 4 + *(int *)(this + 0x10));
    if (pBVar6 == (unsigned char *)0x0) {
      *(unsigned char **)(iVar2 * 4 + *(int *)(this + 0x10)) = param_2;
    }
    else {
      do {
        pBVar5 = pBVar6;
        pBVar6 = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(pBVar5);
      } while (pBVar6 != (unsigned char *)0x0);
      ((int (*)())Binding__SetNextBindingInHash)(pBVar5,param_2);
    }
    ((int (*)())Binding__SetNextBindingInHash)(param_2,(unsigned char *)0x0);
    iVar2 = *(int *)(this + 0x1c);
    *(int *)(this + 0x1c) = iVar2 + 1;
    ((int (*)())Binding__SetActiveIndex)(param_2,iVar2);
    iVar2 = Binding__IsBuiltIn(param_2);
    if (iVar2 == 0) {
      iVar2 = ((int (*)())Binding__GetBindingSlots)(param_2);
      *(int *)(this + 0x28) = *(int *)(this + 0x28) + iVar2;
    }
    iVar2 = ((int (*)())Binding__GetBindingSlots)(param_2);
    *(int *)(this + 0x34) = *(int *)(this + 0x34) + iVar2;
    if (*(int *)(this + 0x38) < *(int *)(param_2 + 0x10) + 1) {
      *(int *)(this + 0x38) = *(int *)(param_2 + 0x10) + 1;
    }
    uVar1 = 1;
    param_2[0x34] = 0x1;
  }
  return uVar1;
}

/* BindingTable__NextAttribBinding @ 0x97bb0ecc (24 bytes) */
int BindingTable__NextAttribBinding(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  undefined4 uVar1;
  
  if (param_2 != (unsigned char *)0x0) {
    uVar1 = ((int (*)())Binding__GetNextBinding)(param_2);
    return uVar1;
  }
  return *(undefined4 *)(this + 0xc);
}

/* BindingTable__FindAttribBinding @ 0x97bb0ee4 (116 bytes) */
int BindingTable__FindAttribBinding(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  unsigned char * this_00;
  
  iVar1 = Binding__GetHash(param_2,*(uint *)this);
  this_00 = *(unsigned char **)(iVar1 * 4 + *(int *)(this + 0x10));
  while ((this_00 != (unsigned char *)0x0 && (iVar1 = __ZeqRK7BindingS1_(this_00,param_2), iVar1 != 1))) {
    this_00 = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(this_00);
  }
  return this_00;
}

/* BindingTable__FindAttribBindingLocationByName @ 0x97bb0f58 (228 bytes) */
int BindingTable__FindAttribBindingLocationByName(this, param_2)
  unsigned char * this;
  char *param_2;
{
  unsigned char * this_00;
  int iVar1;
  undefined4 uVar2;
  unsigned char * this_01;
  
  if (param_2 != (char *)0x0) {
    this_00 = operator_new(0x38);
    __ZN7BindingC1Ev(this_00);
    if (this_00 != (unsigned char *)0x0) {
      Binding__SetName(this_00,param_2);
      iVar1 = Binding__GetHash(this_00,*(uint *)this);
      this_01 = *(unsigned char **)(iVar1 * 4 + *(int *)(this + 0x10));
      while ((this_01 != (unsigned char *)0x0 && (iVar1 = __ZeqRK7BindingS1_(this_01,this_00), iVar1 != 1)
             )) {
        this_01 = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(this_01);
      }
      __ZN7BindingD1Ev(this_00);
      __ZdlPv(this_00);
      if (this_01 != (unsigned char *)0x0) {
        uVar2 = ((int (*)())Binding__GetLocation)(this_01);
        return uVar2;
      }
    }
  }
  return 0xffffffff;
}

/* BindingTable__GetAttribBindingNameByLocation @ 0x97bb103c (92 bytes) */
int BindingTable__GetAttribBindingNameByLocation(this, param_2)
  unsigned char * this;
  long param_2;
{
  int iVar1;
  unsigned char * this_00;
  
  this_00 = *(unsigned char **)(this + 0xc);
  while( true ) {
    if (this_00 == (unsigned char *)0x0) {
      return 0;
    }
    iVar1 = ((int (*)())Binding__GetLocation)(this_00);
    if (iVar1 == param_2) break;
    this_00 = (unsigned char *)((int (*)())Binding__GetNextBinding)(this_00);
  }
  return *(undefined4 *)(this_00 + 8);
}

/* BindingTable__GetAttribBindingByIndex @ 0x97bb1098 (88 bytes) */
int BindingTable__GetAttribBindingByIndex(this, param_2)
  unsigned char * this;
  long param_2;
{
  int iVar1;
  unsigned char * this_00;
  
  this_00 = *(unsigned char **)(this + 0xc);
  while ((this_00 != (unsigned char *)0x0 && (iVar1 = ((int (*)())Binding__GetActiveIndex)(this_00), iVar1 != param_2))
        ) {
    this_00 = (unsigned char *)((int (*)())Binding__GetNextBinding)(this_00);
  }
  return this_00;
}

/* BindingTable__InsertSingleUniform @ 0x97bb10f0 (452 bytes) */
int BindingTable__InsertSingleUniform(this, param_2, param_3)
  unsigned char * this;
  unsigned char * param_2;
  int param_3;
{
  undefined4 uVar1;
  int iVar2;
  unsigned char * pBVar3;
  unsigned char * pBVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar1 = 0;
  if (param_2 != (unsigned char *)0x0) {
    iVar6 = 0;
    iVar7 = 0;
    pBVar3 = *(unsigned char **)(this + 0x14);
    if (*(unsigned char **)(this + 0x14) == (unsigned char *)0x0) {
      *(unsigned char **)(this + 0x14) = param_2;
    }
    else {
      do {
        pBVar4 = pBVar3;
        iVar2 = ((int (*)())Binding__GetLocation)(pBVar4);
        if (-1 < iVar2) {
          iVar7 = ((int (*)())Binding__GetBindingSlots)(pBVar4);
          iVar6 = iVar2;
        }
        pBVar3 = (unsigned char *)((int (*)())Binding__GetNextBinding)(pBVar4);
      } while (pBVar3 != (unsigned char *)0x0);
      ((int (*)())Binding__SetNextBinding)(pBVar4,param_2);
    }
    ((int (*)())Binding__SetLocation)(param_2,iVar6 + iVar7);
    iVar6 = Binding__GetHash(param_2,*(uint *)this);
    pBVar3 = *(unsigned char **)(iVar6 * 4 + *(int *)(this + 0x18));
    if (pBVar3 == (unsigned char *)0x0) {
      *(unsigned char **)(iVar6 * 4 + *(int *)(this + 0x18)) = param_2;
    }
    else {
      do {
        pBVar4 = pBVar3;
        pBVar3 = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(pBVar4);
      } while (pBVar3 != (unsigned char *)0x0);
      ((int (*)())Binding__SetNextBindingInHash)(pBVar4,param_2);
    }
    iVar6 = *(int *)(this + 0x20);
    *(int *)(this + 0x20) = iVar6 + 1;
    ((int (*)())Binding__SetActiveIndex)(param_2,iVar6);
    iVar6 = Binding__IsBuiltIn(param_2);
    if (iVar6 == 0) {
      iVar6 = ((int (*)())Binding__GetBindingSlots)(param_2);
      *(int *)(this + 0x24) = *(int *)(this + 0x24) + iVar6;
    }
    if (param_3 != 0) {
      param_2[0x35] = 0x1;
      iVar6 = ((int (*)())Binding__GetBindingSlots)(param_2);
      *(int *)(this + 0x30) = *(int *)(this + 0x30) + iVar6;
    }
    else {
      param_2[0x34] = 0x1;
      iVar6 = ((int (*)())Binding__GetBindingSlots)(param_2);
      *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + iVar6;
    }
    uVar5 = ((int (*)())Binding__GetOpenGLType)(param_2);
    if ((0x8b5c < uVar5) && (uVar5 < 0x8b65)) {
      if (param_3 != 0) {
        *(int *)(this + 0x44) = *(int *)(this + 0x44) + 1;
      }
      else {
        *(int *)(this + 0x40) = *(int *)(this + 0x40) + 1;
      }
    }
    if (*(int *)(this + 0x3c) < *(int *)(param_2 + 0x10) + 1) {
      *(int *)(this + 0x3c) = *(int *)(param_2 + 0x10) + 1;
    }
    uVar1 = 1;
  }
  return uVar1;
}

/* BindingTable__AddSingleUniformReference @ 0x97bb12b4 (184 bytes) */
int BindingTable__AddSingleUniformReference(this, param_2, param_3)
  unsigned char * this;
  unsigned char * param_2;
  int param_3;
{
  int iVar1;
  uint uVar2;
  
  if (param_3 != 0) {
    param_2[0x35] = 0x1;
    iVar1 = ((int (*)())Binding__GetBindingSlots)(param_2);
    *(int *)(this + 0x30) = *(int *)(this + 0x30) + iVar1;
  }
  else {
    param_2[0x34] = 0x1;
    iVar1 = ((int (*)())Binding__GetBindingSlots)(param_2);
    *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + iVar1;
  }
  uVar2 = ((int (*)())Binding__GetOpenGLType)(param_2);
  if ((0x8b5c < uVar2) && (uVar2 < 0x8b65)) {
    if (param_3 != 0) {
      *(int *)(this + 0x44) = *(int *)(this + 0x44) + 1;
    }
    else {
      *(int *)(this + 0x40) = *(int *)(this + 0x40) + 1;
    }
  }
  return;
}

/* BindingTable__InsertUniformArray @ 0x97bb136c (944 bytes) */
int BindingTable__InsertUniformArray(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  unsigned char * param_2;
  int param_3;
  int param_4;
  int param_5;
  unsigned char ** param_6;
{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  unsigned char * this_00;
  unsigned char * this_01;
  int iVar5;
  int iVar6;
  unsigned char * pBVar7;
  unsigned char * pBVar8;
  uint uVar9;
  ulong uVar10;
  int iVar11;
  unsigned char ** ppPVar12;
  char acStack_90 [32];
  char acStack_70 [32];
  undefined8 local_50;
  
  uVar2 = 0;
  if (param_2 != (unsigned char *)0x0) {
    local_50 = DAT_97c38f98;
    iVar3 = ((int (*)())Binding__GetDecSize)(param_2);
    while (iVar3 = iVar3 + -1, -1 < iVar3) {
      Binding__RemoveNameBackToChar(param_2,'[');
      _sprintf(acStack_90,"[%d]",iVar3);
      Binding__CatName(param_2,acStack_90);
      for (iVar11 = param_4; iVar11 < param_5; iVar11 = iVar11 + 1) {
        if (((param_6[iVar11] != (unsigned char *)0x0) &&
            (iVar4 = ParseSymbolTable__FindSymbolByName(param_6[iVar11],*(char **)(param_2 + 8)),
            iVar4 != 0)) && (*(int *)((int)&local_50 + iVar11 * 4) < iVar3)) {
          *(int *)((int)&local_50 + iVar11 * 4) = iVar3;
        }
      }
    }
    (*(unsigned int *)((unsigned char *)&(local_50) + 0)) = (int)((ulonglong)local_50 >> 0x20);
    iVar3 = (*(unsigned int *)((unsigned char *)&(local_50) + 4));
    if ((*(unsigned int *)((unsigned char *)&(local_50) + 4)) < (*(unsigned int *)((unsigned char *)&(local_50) + 0))) {
      iVar3 = (*(unsigned int *)((unsigned char *)&(local_50) + 0));
    }
    iVar11 = 0;
    Binding__RemoveNameBackToChar(param_2,'[');
    if (-1 < iVar3) {
      uVar10 = iVar3 + 1;
      do {
        bVar1 = true;
        this_00 = operator_new(0x38);
        __ZN7BindingC1ERKS_(this_00,param_2);
        _sprintf(acStack_70,"[%d]",iVar11);
        Binding__CatName(this_00,acStack_70);
        iVar4 = Binding__IsBuiltIn(param_2);
        if (iVar4 != 0) {
          bVar1 = false;
          if (param_4 < param_5) {
            ppPVar12 = param_6 + param_4;
            iVar4 = param_4;
            do {
              this_01 = *ppPVar12;
              ppPVar12 = ppPVar12 + 1;
              if ((this_01 != (unsigned char *)0x0) &&
                 (iVar5 = ParseSymbolTable__FindSymbolByName(this_01,*(char **)(this_00 + 8)),
                 iVar5 != 0)) goto LAB_97bb1538;
              iVar4 = iVar4 + 1;
            } while (iVar4 < param_5);
          }
          if (this_00 != (unsigned char *)0x0) {
            __ZN7BindingD1Ev(this_00);
            __ZdlPv(this_00);
          }
        }
        if (bVar1) {
LAB_97bb1538:
          iVar4 = 0;
          iVar5 = 0;
          pBVar7 = *(unsigned char **)(this + 0x14);
          if (*(unsigned char **)(this + 0x14) == (unsigned char *)0x0) {
            *(unsigned char **)(this + 0x14) = this_00;
          }
          else {
            do {
              pBVar8 = pBVar7;
              iVar6 = ((int (*)())Binding__GetLocation)(pBVar8);
              if (-1 < iVar6) {
                iVar5 = ((int (*)())Binding__GetBindingSlots)(pBVar8);
                iVar4 = iVar6;
              }
              pBVar7 = (unsigned char *)((int (*)())Binding__GetNextBinding)(pBVar8);
            } while (pBVar7 != (unsigned char *)0x0);
            ((int (*)())Binding__SetNextBinding)(pBVar8,this_00);
          }
          ((int (*)())Binding__SetLocation)(this_00,iVar4 + iVar5);
          iVar4 = Binding__GetHash(this_00,*(uint *)this);
          pBVar7 = *(unsigned char **)(iVar4 * 4 + *(int *)(this + 0x18));
          if (pBVar7 == (unsigned char *)0x0) {
            *(unsigned char **)(iVar4 * 4 + *(int *)(this + 0x18)) = this_00;
          }
          else {
            do {
              pBVar8 = pBVar7;
              pBVar7 = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(pBVar8);
            } while (pBVar7 != (unsigned char *)0x0);
            ((int (*)())Binding__SetNextBindingInHash)(pBVar8,this_00);
          }
          ((int (*)())Binding__SetActualSize)(this_00,uVar10);
          if (iVar11 == 0) {
            iVar4 = *(int *)(this + 0x20);
            *(int *)(this + 0x20) = iVar4 + 1;
            ((int (*)())Binding__SetActiveIndex)(this_00,iVar4);
          }
          iVar4 = Binding__IsBuiltIn(this_00);
          if (iVar4 == 0) {
            iVar4 = ((int (*)())Binding__GetBindingSlots)(this_00);
            *(int *)(this + 0x24) = *(int *)(this + 0x24) + iVar4;
          }
          if (iVar11 <= (*(unsigned int *)((unsigned char *)&(local_50) + 0))) {
            this_00[0x34] = 0x1;
            iVar4 = ((int (*)())Binding__GetBindingSlots)(this_00);
            *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + iVar4;
            uVar9 = ((int (*)())Binding__GetOpenGLType)(this_00);
            if ((0x8b5c < uVar9) && (uVar9 < 0x8b65)) {
              *(int *)(this + 0x40) = *(int *)(this + 0x40) + 1;
            }
          }
          if (iVar11 <= (*(unsigned int *)((unsigned char *)&(local_50) + 4))) {
            this_00[0x35] = 0x1;
            iVar4 = ((int (*)())Binding__GetBindingSlots)(param_2);
            *(int *)(this + 0x30) = *(int *)(this + 0x30) + iVar4;
            uVar9 = ((int (*)())Binding__GetOpenGLType)(this_00);
            if ((0x8b5c < uVar9) && (uVar9 < 0x8b65)) {
              *(int *)(this + 0x44) = *(int *)(this + 0x44) + 1;
            }
          }
          if (*(int *)(this + 0x3c) < *(int *)(this_00 + 0x10) + 1) {
            *(int *)(this + 0x3c) = *(int *)(this_00 + 0x10) + 1;
          }
        }
        iVar11 = iVar11 + 1;
        uVar10 = uVar10 - 1;
      } while (iVar11 <= iVar3);
    }
    __ZN7BindingD1Ev(param_2);
    __ZdlPv(param_2);
    uVar2 = 1;
  }
  return uVar2;
}

/* BindingTable__NextUniformBinding @ 0x97bb171c (24 bytes) */
int BindingTable__NextUniformBinding(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  undefined4 uVar1;
  
  if (param_2 != (unsigned char *)0x0) {
    uVar1 = ((int (*)())Binding__GetNextBinding)(param_2);
    return uVar1;
  }
  return *(undefined4 *)(this + 0x14);
}

/* BindingTable__FindUniformBinding @ 0x97bb1734 (116 bytes) */
int BindingTable__FindUniformBinding(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  unsigned char * this_00;
  
  iVar1 = Binding__GetHash(param_2,*(uint *)this);
  this_00 = *(unsigned char **)(iVar1 * 4 + *(int *)(this + 0x18));
  while ((this_00 != (unsigned char *)0x0 && (iVar1 = __ZeqRK7BindingS1_(this_00,param_2), iVar1 != 1))) {
    this_00 = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(this_00);
  }
  return this_00;
}

/* BindingTable__FindUniformBindingByName @ 0x97bb17a8 (116 bytes) */
int BindingTable__FindUniformBindingByName(this, param_2)
  unsigned char * this;
  char *param_2;
{
  unsigned char * this_00;
  
  if (param_2 != (char *)0x0) {
    this_00 = operator_new(0x38);
    __ZN7BindingC1Ev(this_00);
    if (this_00 != (unsigned char *)0x0) {
      Binding__SetName(this_00,param_2);
      ((int (*)())BindingTable__FindUniformBinding)(this,this_00);
      __ZN7BindingD1Ev(this_00);
      __ZdlPv(this_00);
    }
  }
  return 0;
}

/* BindingTable__FindClientUniformBindingLocationByName @ 0x97bb181c (264 bytes) */
int BindingTable__FindClientUniformBindingLocationByName(this, param_2)
  unsigned char * this;
  char *param_2;
{
  int iVar1;
  unsigned char * this_00;
  unsigned char * pBVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  if ((param_2 != (char *)0x0) && (iVar1 = _memcmp(param_2,"gl_",3), iVar1 != 0)) {
    this_00 = operator_new(0x38);
    __ZN7BindingC1Ev(this_00);
    if (this_00 != (unsigned char *)0x0) {
      Binding__SetName(this_00,param_2);
      pBVar2 = (unsigned char *)((int (*)())BindingTable__FindUniformBinding)(this,this_00);
      if (pBVar2 == (unsigned char *)0x0) {
        if (*(char *)(*(int *)(this_00 + 8) + *(int *)(this_00 + 0x10) + -1) != ']') {
          Binding__CatName(this_00,"[0]");
          pBVar2 = (unsigned char *)((int (*)())BindingTable__FindUniformBinding)(this,this_00);
          if (pBVar2 != (unsigned char *)0x0) {
            uVar3 = ((int (*)())Binding__GetLocation)(pBVar2);
          }
        }
      }
      else {
        uVar3 = ((int (*)())Binding__GetLocation)(pBVar2);
      }
      __ZN7BindingD1Ev(this_00);
      __ZdlPv(this_00);
    }
  }
  return uVar3;
}

/* BindingTable__FindUniformBindingByLocation @ 0x97bb1924 (160 bytes) */
int BindingTable__FindUniformBindingByLocation(this, param_2)
  unsigned char * this;
  long param_2;
{
  int iVar1;
  int iVar2;
  uint uVar3;
  unsigned char * this_00;
  
  this_00 = *(unsigned char **)(this + 0x14);
  while( true ) {
    if (this_00 == (unsigned char *)0x0) {
      return (unsigned char *)0x0;
    }
    iVar1 = ((int (*)())Binding__GetLocation)(this_00);
    if (iVar1 == param_2) break;
    if ((iVar1 < param_2) &&
       (iVar2 = ((int (*)())Binding__GetBindingSlots)(this_00), (uint)param_2 < (uint)(iVar1 + iVar2))) {
      uVar3 = ((int (*)())Binding__GetBindingBasicSize)(this_00);
      if (param_2 - iVar1 != ((uint)(param_2 - iVar1) / uVar3) * uVar3) {
        return (unsigned char *)0x0;
      }
      return this_00;
    }
    this_00 = (unsigned char *)((int (*)())Binding__GetNextBinding)(this_00);
  }
  return this_00;
}

/* BindingTable__FindUniformBindingByIndex @ 0x97bb19c4 (88 bytes) */
int BindingTable__FindUniformBindingByIndex(this, param_2)
  unsigned char * this;
  long param_2;
{
  int iVar1;
  unsigned char * this_00;
  
  this_00 = *(unsigned char **)(this + 0x14);
  while ((this_00 != (unsigned char *)0x0 && (iVar1 = ((int (*)())Binding__GetActiveIndex)(this_00), iVar1 != param_2))
        ) {
    this_00 = (unsigned char *)((int (*)())Binding__GetNextBinding)(this_00);
  }
  return this_00;
}

/* BindingTable__GetNumActiveAttributeBindings @ 0x97bb1a1c (8 bytes) */
int BindingTable__GetNumActiveAttributeBindings(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x1c);
}

/* BindingTable__GetNumActiveUniformBindings @ 0x97bb1a24 (8 bytes) */
int BindingTable__GetNumActiveUniformBindings(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x20);
}

/* BindingTable__GetSizeActiveUserUniforms @ 0x97bb1a2c (8 bytes) */
int BindingTable__GetSizeActiveUserUniforms(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x24);
}

/* BindingTable__GetSizeActiveUserAttributes @ 0x97bb1a34 (8 bytes) */
int BindingTable__GetSizeActiveUserAttributes(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x28);
}

/* BindingTable__GetSizeActiveVertexUniforms @ 0x97bb1a3c (8 bytes) */
int BindingTable__GetSizeActiveVertexUniforms(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x2c);
}

/* BindingTable__GetSizeActiveFragmentUniforms @ 0x97bb1a44 (8 bytes) */
int BindingTable__GetSizeActiveFragmentUniforms(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x30);
}

/* BindingTable__GetSizeActiveAttributes @ 0x97bb1a4c (8 bytes) */
int BindingTable__GetSizeActiveAttributes(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x34);
}

/* BindingTable__GetMaxAttributeLength @ 0x97bb1a54 (8 bytes) */
int BindingTable__GetMaxAttributeLength(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x38);
}

/* BindingTable__GetMaxUniformLength @ 0x97bb1a5c (8 bytes) */
int BindingTable__GetMaxUniformLength(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x3c);
}

/* BindingTable__GetNumActiveVertexSamplers @ 0x97bb1a64 (8 bytes) */
int BindingTable__GetNumActiveVertexSamplers(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x40);
}

/* BindingTable__GetNumActiveFragmentSamplers @ 0x97bb1a6c (8 bytes) */
int BindingTable__GetNumActiveFragmentSamplers(this)
  unsigned char * this;
{
  return *(undefined4 *)(this + 0x44);
}

/* BindingTable__GetString @ 0x97bb1a74 (1028 bytes) */
int BindingTable__GetString(this, param_2)
  unsigned char * this;
  int param_2;
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
  unsigned char * this_00;
  
  this_00 = (unsigned char *)0x0;
  pcVar2 = _malloc(0x800);
  sVar7 = 0x800;
  iVar6 = 0;
  if (pcVar2 == (char *)0x0) {
    return (char *)0x0;
  }
  *pcVar2 = '\0';
  pcVar5 = pcVar2;
  if (2 < param_2) {
    if (param_2 == 3) {
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
    if (6 < param_2) {
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
    if (param_2 == 5) {
      if (**(int **)(this + 0x10) == 0) {
        pcVar5 = "\n No Attribute Bindings\n";
      }
      else {
        pcVar5 = "\n Attribute Bindings: [Index: (Location) \'Name\'- Type Shader]\n";
      }
    }
    else if (5 < param_2) {
      if (param_2 != 6) goto LAB_97bb1cf0;
      if (**(int **)(this + 0x18) == 0) {
        pcVar5 = "\n No Uniform Bindings\n";
      }
      else {
        pcVar5 = "\n Uniform Bindings: [Index: (Location) \'Name\'- Type Shader]\n";
      }
    }
    else {
      if (param_2 != 4) goto LAB_97bb1cf0;
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
      if (param_2 == 5) {
        iVar8 = *(int *)(this + 0x10);
LAB_97bb1d30:
        this_00 = *(unsigned char **)(uVar9 * 4 + iVar8);
      }
      else if (5 < param_2) {
        if (param_2 == 6) {
          iVar8 = *(int *)(this + 0x18);
          goto LAB_97bb1d30;
        }
      }
      else if (param_2 == 4) {
        iVar8 = *(int *)(this + 8);
        goto LAB_97bb1d30;
      }
      if (this_00 != (unsigned char *)0x0) {
        _sprintf(pcVar2,"%s  --- Hash %d ---\n",pcVar2,uVar9);
        pcVar5 = pcVar2;
        do {
          pcVar2 = (char *)((int (*)())Binding__GetString)(this_00);
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
          this_00 = (unsigned char *)((int (*)())Binding__GetNextBindingInHash)(this_00);
          pcVar5 = pcVar2;
        } while (this_00 != (unsigned char *)0x0);
      }
      uVar9 = uVar9 + 1;
      if (*(uint *)this <= uVar9) {
        return pcVar2;
      }
    } while( true );
  }
  if (param_2 == 1) {
    this_00 = *(unsigned char **)(this + 0xc);
    bVar1 = this_00 == (unsigned char *)0x0;
    if (bVar1) {
      pcVar4 = "\n No Attribute Bindings\n";
    }
    else {
      pcVar4 = "\n Attribute Bindings: [Index: (Location) \'Name\'- Type Shader]\n";
    }
  }
  else if (param_2 < 2) {
    bVar1 = true;
    if (param_2 != 0) goto LAB_97bb1b5c;
    this_00 = *(unsigned char **)(this + 4);
    bVar1 = this_00 == (unsigned char *)0x0;
    if (bVar1) {
      pcVar4 = "\n No Client Attribute Requests\n";
    }
    else {
      pcVar4 = "\n Client Attribute Requests: [Index: (Location) \'Name\'- Type Shader]\n";
    }
  }
  else {
    if (param_2 != 2) {
      bVar1 = true;
      goto LAB_97bb1b5c;
    }
    this_00 = *(unsigned char **)(this + 0x14);
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
      pcVar2 = (char *)((int (*)())Binding__GetString)(this_00);
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
      this_00 = (unsigned char *)((int (*)())Binding__GetNextBinding)(this_00);
      pcVar5 = pcVar2;
    } while (this_00 != (unsigned char *)0x0);
  }
  return pcVar2;
}

/* ConstructLinker @ 0x97bb1e78 (64 bytes) */
int ConstructLinker(param_1)
  int param_1;
{
  void *this;
  
  this = operator_new(0x88);
  __ZN14TGenericLinkerC1Ei(this,param_1);
  return this;
}

/* DeleteLinker @ 0x97bb1eb8 (24 bytes) */
int DeleteLinker(param_1)
  unsigned char * param_1;
{
  if (param_1 == (unsigned char *)0x0) {
    return;
  }
                    
                    
  (**(code **)(*(int *)param_1 + 4))();
  return;
}

/* UpdateOperations @ 0x97bb1ed0 (504 bytes) */
int UpdateOperations(param_1, param_2, param_3, param_4, param_5, param_6)
  unsigned char * param_1;
  unsigned char * param_2;
  int param_3;
  unsigned char * param_4;
  int param_5;
  int param_6;
{
  bool bVar1;
  int iVar2;
  int iVar3;
  unsigned char * p_Var4;
  int iVar5;
  unsigned char * p_Var6;
  unsigned char * p_Var7;
  int iVar8;
  uint uVar9;
  unsigned char _Var10;
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
              if (_Var10 == 0x2) {
                if ((*(uint *)(p_Var7 + 0xc) & 0x3800000) == 0) goto LAB_97bb1f94;
              }
              else {
                if ((byte)_Var10 < 3) {
                  if (_Var10 != 0x0) goto LAB_97bb1fe8;
                  bVar1 = (*(uint *)(p_Var7 + 0xc) >> 0x17 & 7) == 1;
                }
                else if (_Var10 == 0x3) {
                  bVar1 = (*(uint *)(p_Var7 + 0xc) >> 0x17 & 7) == 2;
                }
                else {
                  if (_Var10 != 0x4) goto LAB_97bb1fe8;
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
                        p_Var6 = *(unsigned char **)(p_Var6 + 8);
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
          if (_Var10 == 0x2) {
            if ((*(uint *)(p_Var4 + 0x14) & 0xe0000) == 0) goto LAB_97bb2064;
          }
          else {
            if ((byte)_Var10 < 3) {
              if (_Var10 != 0x0) goto LAB_97bb20a4;
              bVar1 = (*(uint *)(p_Var4 + 0x14) & 0xe0000) == 0x20000;
            }
            else if (_Var10 == 0x3) {
              bVar1 = (*(uint *)(p_Var4 + 0x14) & 0xe0000) == 0x40000;
            }
            else {
              if (_Var10 != 0x4) goto LAB_97bb20a4;
              bVar1 = (*(uint *)(p_Var4 + 0x14) & 0xe0000) == 0x60000;
            }
            if (bVar1) {
LAB_97bb2064:
              if ((uint)*(ushort *)(p_Var4 + 0x1a) == (uint)*(ushort *)(param_4 + 0x12) + iVar11) {
                iVar8 = iVar2;
                if ((iVar2 != iVar5) && (iVar8 = iVar5, iVar2 < iVar5)) {
                  iVar2 = iVar5 - iVar2;
                  do {
                    p_Var6 = *(unsigned char **)(p_Var6 + 8);
                    iVar2 = iVar2 + -1;
                  } while (iVar2 != 0);
                }
                *(short *)(p_Var6 + 0x1a) = *(short *)(p_Var6 + 0x1a) - (short)param_6;
                iVar2 = iVar8;
              }
            }
          }
LAB_97bb20a4:
          p_Var4 = *(unsigned char **)(p_Var4 + 8);
          iVar5 = iVar5 + 1;
        } while (p_Var4 != (unsigned char *)0x0);
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < param_5);
  }
  return;
}

/* TGenericLinker__FindChunkDelta @ 0x97bb20c8 (84 bytes) */
int TGenericLinker__FindChunkDelta(this, param_2, param_3)
  unsigned char * this;
  unsigned char * param_2;
  unsigned char * param_3;
{
  bool bVar1;
  unsigned char _Var2;
  char *pcVar3;
  void *this_00;
  
  pcVar3 = DAT_a7b7bb8c;
  _Var2 = *param_2;
  if (_Var2 != *param_3) {
    this_00 = *(void **)(this + 0x84);
                    
    __ZN13TInfoSinkBase6appendEPKc(this_00,"INTERNAL ERROR: ");
    __ZN13TInfoSinkBase6appendEPKc(this_00,pcVar3);
    __ZN13TInfoSinkBase6appendEPKc(this_00,"\n");
    return 0;
  }
  if (_Var2 != 0x2) {
    if ((byte)_Var2 < 3) {
      bVar1 = _Var2 == 0x0;
    }
    else {
      if (_Var2 == 0x3) goto LAB_97bb21b8;
      bVar1 = _Var2 == 0x4;
    }
    if (!bVar1) {
      return 0;
    }
  }
LAB_97bb21b8:
  return (uint)*(ushort *)(param_2 + 0x12) - (uint)*(ushort *)(param_3 + 0x12);
}

