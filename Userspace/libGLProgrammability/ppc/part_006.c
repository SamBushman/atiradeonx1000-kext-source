#include "decls.h"

/* _ShGetInfoLog @ 0x97ba1c6c (244 bytes) */
int _ShGetInfoLog(param_1)
  int *param_1;
{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_1 != (int *)0x0) {
    iVar2 = (**(code **)(*param_1 + 8))();
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*param_1 + 0xc))(param_1);
      if (iVar2 == 0) {
        return 0;
      }
      iVar2 = (**(code **)(*param_1 + 0xc))(param_1);
      piVar3 = *(int **)(iVar2 + 0x84);
    }
    else {
      piVar3 = (int *)(**(code **)(*param_1 + 8))(param_1);
      piVar3 = (int *)(**(code **)(*piVar3 + 0x10))();
    }
    puVar1 = PTR__S_terminal_a7b7c0b8;
    if (piVar3 != (int *)0x0) {
      *(undefined *)(piVar3[2] + *(int *)(piVar3[2] + -0xc)) = *PTR__S_terminal_a7b7c0b8;
      TInfoSinkBase__append((char *)piVar3);
      *(undefined *)(*piVar3 + *(int *)(*piVar3 + -0xc)) = *puVar1;
      iVar4 = *piVar3;
    }
  }
  return iVar4;
}

/* _ShGetPPStream @ 0x97ba1d60 (96 bytes) */
int _ShGetPPStream(param_1)
  int *param_1;
{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 8))(), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x1c))();
  }
  return uVar2;
}

/* _ShGetShaderLocalParamRemapTable @ 0x97ba1dc0 (92 bytes) */
int _ShGetShaderLocalParamRemapTable(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = TGenericLinker__getShaderLocalParamRemapTable(iVar1,param_2);
  }
  return uVar2;
}

/* _ShGetNumShaderLocalParams @ 0x97ba1e1c (92 bytes) */
int _ShGetNumShaderLocalParams(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = TGenericLinker__getNumShaderLocalParams(iVar1,param_2);
  }
  return uVar2;
}

/* _ShAttributeBindingRequest @ 0x97ba1e78 (104 bytes) */
int _ShAttributeBindingRequest(param_1, param_2)
  int *param_1;
  char *param_2;
{
  ulong uVar1;
  
  if ((param_1 != (int *)0x0) && (uVar1 = (**(code **)(*param_1 + 0xc))(), uVar1 != 0)) {
    TGenericLinker__attributeBindingRequest(uVar1,param_2);
    return;
  }
  return;
}

/* _ShGetNumActiveAttributes @ 0x97ba1ee0 (104 bytes) */
int _ShGetNumActiveAttributes(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) &&
     (uVar2 = 0, *(int *)(iVar1 + 4) != 0)) {
    uVar2 = BindingTable__GetNumActiveAttributeBindings();
  }
  return uVar2;
}

/* _ShGetNumActiveUniforms @ 0x97ba1f48 (104 bytes) */
int _ShGetNumActiveUniforms(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) &&
     (uVar2 = 0, *(int *)(iVar1 + 4) != 0)) {
    uVar2 = BindingTable__GetNumActiveUniformBindings();
  }
  return uVar2;
}

/* _ShGetActiveUserUniformsSize @ 0x97ba1fb0 (104 bytes) */
int _ShGetActiveUserUniformsSize(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) &&
     (uVar2 = 0, *(int *)(iVar1 + 4) != 0)) {
    uVar2 = BindingTable__GetSizeActiveUserUniforms();
  }
  return uVar2;
}

/* _ShGetMaxAttributeLength @ 0x97ba2018 (104 bytes) */
int _ShGetMaxAttributeLength(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) &&
     (uVar2 = 0, *(int *)(iVar1 + 4) != 0)) {
    uVar2 = BindingTable__GetMaxAttributeLength();
  }
  return uVar2;
}

/* _ShGetMaxUniformLength @ 0x97ba2080 (104 bytes) */
int _ShGetMaxUniformLength(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) &&
     (uVar2 = 0, *(int *)(iVar1 + 4) != 0)) {
    uVar2 = BindingTable__GetMaxUniformLength();
  }
  return uVar2;
}

/* _ShGetActiveUniform @ 0x97ba20e8 (132 bytes) */
int _ShGetActiveUniform(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  long param_2;
  long *param_3;
  long *param_4;
  ulong *param_5;
  char *param_6;
{
  ulong uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (uVar1 = (**(code **)(*param_1 + 0xc))(), uVar1 != 0)) {
    uVar2 = TGenericLinker__getActiveUniform(uVar1,param_2,param_3,param_4,param_5,param_6);
  }
  return uVar2;
}

/* _ShGetUniformTypeInfo @ 0x97ba216c (116 bytes) */
int _ShGetUniformTypeInfo(param_1, param_2, param_3, param_4)
  int *param_1;
  long *param_2;
  ulong *param_3;
  uchar *param_4;
{
  long lVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (lVar1 = (**(code **)(*param_1 + 0xc))(), lVar1 != 0)) {
    uVar2 = TGenericLinker__getUniformTypeInfo(lVar1,param_2,param_3,param_4);
  }
  return uVar2;
}

/* _ShGetActiveAttrib @ 0x97ba21e0 (132 bytes) */
int _ShGetActiveAttrib(param_1, param_2, param_3, param_4, param_5, param_6)
  int *param_1;
  long param_2;
  long *param_3;
  long *param_4;
  ulong *param_5;
  char *param_6;
{
  ulong uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (uVar1 = (**(code **)(*param_1 + 0xc))(), uVar1 != 0)) {
    uVar2 = TGenericLinker__getActiveAttrib(uVar1,param_2,param_3,param_4,param_5,param_6);
  }
  return uVar2;
}

/* _ShGetAttribLocation @ 0x97ba2264 (112 bytes) */
int _ShGetAttribLocation(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = 0xffffffff;
    if (*(char **)(iVar1 + 4) != (char *)0x0) {
      uVar2 = BindingTable__FindAttribBindingLocationByName(*(char **)(iVar1 + 4));
    }
  }
  return uVar2;
}

/* _ShGetUniformLocation @ 0x97ba22d4 (112 bytes) */
int _ShGetUniformLocation(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = 0xffffffff;
    if (*(char **)(iVar1 + 4) != (char *)0x0) {
      uVar2 = BindingTable__FindClientUniformBindingLocationByName(*(char **)(iVar1 + 4));
    }
  }
  return uVar2;
}

/* _ShGetPPStreamManager @ 0x97ba2344 (92 bytes) */
int _ShGetPPStreamManager(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = TGenericLinker__getPPStreamManager(iVar1,param_2);
  }
  return uVar2;
}

/* _ShGetLinkerStats @ 0x97ba23a0 (84 bytes) */
int _ShGetLinkerStats(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = TGenericLinker__getStatsString();
  }
  return uVar2;
}

/* _ShGetCompilerStats @ 0x97ba23f4 (96 bytes) */
int _ShGetCompilerStats(param_1)
  int *param_1;
{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 8))(), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x24))();
  }
  return uVar2;
}

/* _ShGetLinkerPPStream @ 0x97ba2454 (84 bytes) */
int _ShGetLinkerPPStream(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = TGenericLinker__getPPStreamString();
  }
  return uVar2;
}

/* _ShGetCompilerPPStream @ 0x97ba24a8 (96 bytes) */
int _ShGetCompilerPPStream(param_1)
  int *param_1;
{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 8))(), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x28))();
  }
  return uVar2;
}

/* _ShGetLinkerShaderToProgramString @ 0x97ba2508 (84 bytes) */
int _ShGetLinkerShaderToProgramString(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = TGenericLinker__getShaderToProgramString();
  }
  return uVar2;
}

/* _ShGetCompilerShaderToProgramString @ 0x97ba255c (96 bytes) */
int _ShGetCompilerShaderToProgramString(param_1)
  int *param_1;
{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 8))(), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x2c))();
  }
  return uVar2;
}

/* _ShGetLinkerBindingTable @ 0x97ba25bc (84 bytes) */
int _ShGetLinkerBindingTable(param_1)
  int *param_1;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = TGenericLinker__getTableString();
  }
  return uVar2;
}

/* _ShGetCompilerSymbolTable @ 0x97ba2610 (96 bytes) */
int _ShGetCompilerSymbolTable(param_1)
  int *param_1;
{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (int *)0x0) &&
     (piVar1 = (int *)(**(code **)(*param_1 + 8))(), piVar1 != (int *)0x0)) {
    uVar2 = (**(code **)(*piVar1 + 0x30))();
  }
  return uVar2;
}

/* TType__buildMangledName @ 0x97ba2670 (688 bytes) */
int TType__buildMangledName(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  char *pcVar2;
  uint uVar3;
  char acStack_20 [16];
  
  iVar1 = (**(code **)(*(int *)this + 0x34))();
  if ((iVar1 != 0) || (iVar1 = (**(code **)(*(int *)this + 0x3c))(this), iVar1 != 0)) {
    std__string__append((ulong)param_1,'\x01');
  }
  switch(*(uint *)(this + 0x24) >> 0x13 & 0x3f) {
  default:
    goto switchD_97ba270c_caseD_0;
  case 1:
    goto LAB_97ba2778;
  case 2:
    goto LAB_97ba2778;
  case 3:
LAB_97ba2778:
    std__string__append((ulong)param_1,'\x01');
    goto switchD_97ba270c_caseD_0;
  case 5:
    pcVar2 = "s1";
    _strlen("s1");
    break;
  case 6:
    pcVar2 = "s2";
    _strlen("s2");
    break;
  case 7:
    pcVar2 = "s3";
    _strlen("s3");
    break;
  case 8:
    pcVar2 = "sC";
    _strlen("sC");
    break;
  case 9:
    pcVar2 = "sS1";
    _strlen("sS1");
    break;
  case 10:
    pcVar2 = "sS2";
    _strlen("sS2");
    break;
  case 0xb:
    pcVar2 = "sR2";
    _strlen("sR2");
    break;
  case 0xc:
    pcVar2 = "sSR2";
    _strlen("sSR2");
    break;
  case 0xe:
    _strlen("struct-");
    std__string__append((char *)param_1,0x97c29ef8);
    if (*(int *)(this + 0x10) != 0) {
      std__string__append(param_1);
    }
    for (uVar3 = 0;
        uVar3 < (uint)(*(int *)(*(int *)(this + 8) + 8) - *(int *)(*(int *)(this + 8) + 4) >> 3);
        uVar3 = uVar3 + 1) {
      std__string__append((ulong)param_1,'\x01');
      ((int (*)())TType__buildMangledName)(*(unsigned char **)(*(int *)(*(int *)(this + 8) + 4) + uVar3 * 8),param_1);
    }
    goto switchD_97ba270c_caseD_0;
  }
  std__string__append((char *)param_1,(ulong)pcVar2);
switchD_97ba270c_caseD_0:
  (**(code **)(*(int *)this + 0x2c))(this);
  std__string__append((ulong)param_1,'\x01');
  iVar1 = (**(code **)(*(int *)this + 0x38))(this);
  if (iVar1 != 0) {
    _sprintf(acStack_20,"%d",*(undefined4 *)(this + 4));
    std__string__append((ulong)param_1,'\x01');
    _strlen(acStack_20);
    std__string__append((char *)param_1,(ulong)acStack_20);
    std__string__append((ulong)param_1,'\x01');
  }
  return;
}

/* TVariable__dump @ 0x97ba295c (220 bytes) */
int TVariable__dump(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  unsigned char * pTVar1;
  
  pTVar1 = param_1 + 8;
  *(undefined1 *)
   (*(int *)(*(int *)(this + 4) + 4) + *(int *)(*(int *)(*(int *)(this + 4) + 4) + -0xc)) =
       *DAT_a7b7ba80;
  TInfoSinkBase__append((char *)pTVar1);
  TInfoSinkBase__append((char *)pTVar1);
  getQualifierString(*(uint *)(this + 0x30) >> 0x19);
  TInfoSinkBase__append((char *)pTVar1);
  TInfoSinkBase__append((char *)pTVar1);
  TType__getBasicString(*(uint *)(this + 0x30) >> 0x13 & 0x3f);
  TInfoSinkBase__append((char *)pTVar1);
  if ((*(uint *)(this + 0x30) & 0x200) != 0) {
    TInfoSinkBase__append((char *)pTVar1);
  }
  TInfoSinkBase__append((char *)pTVar1);
  return;
}

/* TFunction__dump @ 0x97ba2a38 (216 bytes) */
int TFunction__dump(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined1 *puVar1;
  int iVar2;
  unsigned char * pTVar3;
  
  puVar1 = DAT_a7b7ba80;
  pTVar3 = param_1 + 8;
  *(undefined1 *)
   (*(int *)(*(int *)(this + 4) + 4) + *(int *)(*(int *)(*(int *)(this + 4) + 4) + -0xc)) =
       *DAT_a7b7ba80;
  TInfoSinkBase__append((char *)pTVar3);
  TInfoSinkBase__append((char *)pTVar3);
  TType__getBasicString(*(uint *)(this + 0x40) >> 0x13 & 0x3f);
  TInfoSinkBase__append((char *)pTVar3);
  TInfoSinkBase__append((char *)pTVar3);
  iVar2 = (**(code **)(*(int *)this + 8))(this);
  *(undefined1 *)(*(int *)(iVar2 + 4) + *(int *)(*(int *)(iVar2 + 4) + -0xc)) = *puVar1;
  TInfoSinkBase__append((char *)pTVar3);
  TInfoSinkBase__append((char *)pTVar3);
  return;
}

/* TSymbolTableLevel__dump @ 0x97ba2b10 (112 bytes) */
int TSymbolTableLevel__dump(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(this + 4);
  iVar1 = *(int *)(iVar3 + 8);
  while (iVar1 != iVar3) {
    piVar2 = *(int **)(iVar1 + 0x18);
    (**(code **)(*piVar2 + 0x14))(piVar2,param_1);
    std___Rb_tree_base_iterator___M_increment();
    iVar3 = *(int *)(this + 4);
  }
  return;
}

/* TSymbolTable__dump @ 0x97ba2b80 (268 bytes) */
int TSymbolTable__dump(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  unsigned char * psVar4;
  int iVar5;
  char in_RESERVE;
  byte bVar6;
  undefined4 local_70;
  int local_6c;
  char acStack_60 [16];
  undefined4 local_50 [4];
  undefined4 local_40;
  
  iVar5 = (*(int *)(this + 4) - *(int *)this >> 2) + -1;
  if (-1 < iVar5) {
    psVar4 = (unsigned char *)(param_1 + 8);
    do {
      bVar6 = (iVar5 == 0) << 1;
      TInfoSinkBase__append((char *)psVar4);
      _sprintf(acStack_60,"%d",iVar5);
      local_50[0] = GetGlobalPoolAllocator();
      std__string__string((unsigned char *)&local_70,acStack_60,(unsigned char *)local_50);
      TInfoSinkBase__append(psVar4);
      piVar2 = (int *)(local_6c + -4);
      local_40 = local_70;
      do {
        iVar3 = *piVar2;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
          *piVar2 = iVar1;
          bVar6 = 2;
        }
      } while (!(bool)(bVar6 >> 1 & 1));
      if (iVar3 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(local_6c + -0xc));
      }
      TInfoSinkBase__append((char *)psVar4);
      ((int (*)())TSymbolTableLevel__dump)(*(unsigned char **)(*(int *)this + iVar5 * 4),param_1);
      iVar5 = iVar5 + -1;
    } while (-1 < iVar5);
  }
  return;
}

/* TFunction___TFunction @ 0x97ba2c8c (8 bytes) */
int TFunction___TFunction(this)
  unsigned char * this;
{
  ~TFunction(this);
  return;
}

/* TFunction___TFunction_97ba2c94 @ 0x97ba2c94 (8 bytes) */
int TFunction___TFunction_97ba2c94(this)
  unsigned char * this;
{
  ~TFunction(this);
  return;
}

/* TFunction___TFunction_97ba2c9c @ 0x97ba2c9c (8 bytes) */
int TFunction___TFunction_97ba2c9c(this)
  unsigned char * this;
{
  ~TFunction(this);
  return;
}

/* TFunction___TFunction_97ba2ca4 @ 0x97ba2ca4 (236 bytes) */
int TFunction___TFunction_97ba2ca4(this)
  unsigned char * this;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  
  iVar4 = *(int *)(this + 0x10);
  *(int *)this = DAT_a7b7ba7c + 8;
  iVar2 = *(int *)(this + 0x14);
  for (; iVar4 != iVar2; iVar4 = iVar4 + 8) {
    if (*(int **)(iVar4 + 4) != (int *)0x0) {
      (**(code **)(**(int **)(iVar4 + 4) + 4))();
      iVar2 = *(int *)(this + 0x14);
    }
  }
  iVar2 = *(int *)(this + 0x48);
  piVar3 = (int *)(iVar2 + -4);
  do {
    iVar4 = *piVar3;
    if (in_RESERVE != '\0') {
      iVar1 = storeWordConditionalIndexed(iVar4 + -1,0,piVar3);
      *piVar3 = iVar1;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  if (iVar4 < 1) {
    std__string___Rep___M_destroy((unsigned char *)(iVar2 + -0xc));
  }
  iVar2 = *(int *)(this + 0x10);
  *(undefined ***)(this + 0x1c) = &PTR__TType_a7b7d590;
  for (; iVar2 != *(int *)(this + 0x14); iVar2 = iVar2 + 8) {
  }
  *(undefined ***)this = &PTR__TSymbol_a7b7d568;
  return;
}

/* TSymbolTableLevel___TSymbolTableLevel @ 0x97ba2d90 (8 bytes) */
int TSymbolTableLevel___TSymbolTableLevel(this)
  unsigned char * this;
{
  ~TSymbolTableLevel(this);
  return;
}

/* TSymbolTableLevel___TSymbolTableLevel_97ba2d98 @ 0x97ba2d98 (8 bytes) */
int TSymbolTableLevel___TSymbolTableLevel_97ba2d98(this)
  unsigned char * this;
{
  ~TSymbolTableLevel(this);
  return;
}

/* TSymbolTableLevel___TSymbolTableLevel_97ba2da0 @ 0x97ba2da0 (184 bytes) */
int TSymbolTableLevel___TSymbolTableLevel_97ba2da0(this)
  unsigned char * this;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = *(int *)(this + 4);
  iVar2 = *(int *)(iVar1 + 8);
  while (iVar2 != iVar1) {
    piVar3 = *(int **)(iVar2 + 0x18);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 4))();
    }
    std___Rb_tree_base_iterator___M_increment();
    iVar1 = *(int *)(this + 4);
  }
  if (*(int *)(this + 8) != 0) {
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_erase((unsigned char *)this);
    *(int *)(*(int *)(this + 4) + 8) = *(int *)(this + 4);
    *(undefined4 *)(*(int *)(this + 4) + 4) = 0;
    *(int *)(*(int *)(this + 4) + 0xc) = *(int *)(this + 4);
    *(undefined4 *)(this + 8) = 0;
  }
  return;
}

/* TSymbolTableLevel__relateToOperator @ 0x97ba2e58 (168 bytes) */
int TSymbolTableLevel__relateToOperator(this, param_2, param_3)
  unsigned char * this;
  undefined4 param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(this + 4);
  iVar2 = *(int *)(iVar1 + 8);
  while (iVar2 != iVar1) {
    iVar1 = (**(code **)(**(int **)(iVar2 + 0x18) + 0xc))();
    if (iVar1 != 0) {
      iVar3 = *(int *)(iVar2 + 0x18);
      iVar1 = std__string__compare(*(char **)(iVar3 + 4));
      if (iVar1 == 0) {
        *(undefined4 *)(iVar3 + 0x4c) = param_3;
      }
    }
    std___Rb_tree_base_iterator___M_increment();
    iVar1 = *(int *)(this + 4);
  }
  return;
}

/* TSymbol__TSymbol @ 0x97ba2f00 (4 bytes) */
int TSymbol__TSymbol(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined4 uVar1;
  unsigned char * psVar2;
  ulong uVar3;
  unsigned char * this_00;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 auStack_30 [7];
  
  iVar4 = *(int *)(param_1 + 4);
  *(undefined ***)this = &PTR__TSymbol_a7b7d568;
  iVar5 = *(int *)(iVar4 + 4);
  *(undefined1 *)(iVar5 + *(int *)(iVar5 + -0xc)) = *DAT_a7b7ba80;
  pcVar6 = *(char **)(iVar4 + 4);
  uVar3 = GetGlobalPoolAllocator();
  this_00 = (unsigned char *)TPoolAllocator__allocate(uVar3);
  psVar2 = (unsigned char *)0x0;
  if (this_00 != (unsigned char *)0x0) {
    auStack_30[0] = GetGlobalPoolAllocator();
    std__string__string(this_00,pcVar6,(unsigned char *)auStack_30);
    psVar2 = this_00;
  }
  uVar1 = *(undefined4 *)(param_1 + 8);
  *(unsigned char **)(this + 4) = psVar2;
  *(undefined4 *)(this + 8) = uVar1;
  return;
}

/* TSymbol__TSymbol_97ba2f04 @ 0x97ba2f04 (4 bytes) */
int TSymbol__TSymbol_97ba2f04(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined4 uVar1;
  unsigned char * psVar2;
  ulong uVar3;
  unsigned char * this_00;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 auStack_30 [7];
  
  iVar4 = *(int *)(param_1 + 4);
  *(undefined ***)this = &PTR__TSymbol_a7b7d568;
  iVar5 = *(int *)(iVar4 + 4);
  *(undefined1 *)(iVar5 + *(int *)(iVar5 + -0xc)) = *DAT_a7b7ba80;
  pcVar6 = *(char **)(iVar4 + 4);
  uVar3 = GetGlobalPoolAllocator();
  this_00 = (unsigned char *)TPoolAllocator__allocate(uVar3);
  psVar2 = (unsigned char *)0x0;
  if (this_00 != (unsigned char *)0x0) {
    auStack_30[0] = GetGlobalPoolAllocator();
    std__string__string(this_00,pcVar6,(unsigned char *)auStack_30);
    psVar2 = this_00;
  }
  uVar1 = *(undefined4 *)(param_1 + 8);
  *(unsigned char **)(this + 4) = psVar2;
  *(undefined4 *)(this + 8) = uVar1;
  return;
}

/* TSymbol__TSymbol_97ba2f08 @ 0x97ba2f08 (164 bytes) */
int TSymbol__TSymbol_97ba2f08(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined4 uVar1;
  unsigned char * psVar2;
  ulong uVar3;
  unsigned char * this_00;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined4 local_30 [7];
  
  iVar4 = *(int *)(param_1 + 4);
  *(undefined ***)this = &PTR__TSymbol_a7b7d568;
  iVar5 = *(int *)(iVar4 + 4);
  *(undefined1 *)(iVar5 + *(int *)(iVar5 + -0xc)) = *DAT_a7b7ba80;
  pcVar6 = *(char **)(iVar4 + 4);
  uVar3 = GetGlobalPoolAllocator();
  this_00 = (unsigned char *)TPoolAllocator__allocate(uVar3);
  psVar2 = (unsigned char *)0x0;
  if (this_00 != (unsigned char *)0x0) {
    local_30[0] = GetGlobalPoolAllocator();
    std__string__string(this_00,pcVar6,(unsigned char *)local_30);
    psVar2 = this_00;
  }
  uVar1 = *(undefined4 *)(param_1 + 8);
  *(unsigned char **)(this + 4) = psVar2;
  *(undefined4 *)(this + 8) = uVar1;
  return;
}

/* TVariable__TVariable @ 0x97ba2fac (4 bytes) */
int TVariable__TVariable(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  ((int (*)())TSymbol__TSymbol)((unsigned char *)this,(unsigned char *)param_1);
  *(int *)this = DAT_a7b7ba78 + 8;
  *(undefined ***)(this + 0xc) = &PTR__TType_a7b7d590;
  TType__copyType((unsigned char *)(this + 0xc),(unsigned char *)(param_1 + 0xc));
  iVar2 = *(int *)(param_1 + 0x3c);
  uVar1 = *(uint *)(param_1 + 0x34);
  *(uint *)(this + 0x34) = uVar1;
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 0x38);
    *(undefined4 *)(this + 0x3c) = 0;
    uVar1 = 0;
    if (iVar2 == 0) goto LAB_97ba314c;
    uVar1 = *(uint *)(param_1 + 0x14);
    if (uVar1 == 0) {
      uVar1 = *(uint *)(param_1 + 0x30);
      if ((uVar1 & 0x400) == 0) {
        uVar1 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
      }
      else {
        iVar2 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
        uVar1 = iVar2 * iVar2;
      }
      if (uVar1 == 1) {
        uVar3 = GetGlobalPoolAllocator();
        puVar4 = (undefined4 *)TPoolAllocator__allocate(uVar3);
        *(undefined4 **)(this + 0x38) = puVar4;
        uVar1 = *(uint *)(this + 0x30) >> 0x13 & 0x3f;
        if (uVar1 == 2) {
LAB_97ba311c:
          *puVar4 = **(undefined4 **)(param_1 + 0x38);
          return;
        }
        if (uVar1 < 3) {
          if (uVar1 == 1) {
            *puVar4 = **(undefined4 **)(param_1 + 0x38);
            return;
          }
        }
        else if (uVar1 == 3) goto LAB_97ba311c;
        pcVar6 = "false && \"Unknown type\"";
        uVar5 = 0xb9;
      }
      else {
        pcVar6 = "copyOf.type.getInstanceSize() == 1";
        uVar5 = 0xb2;
      }
    }
    else {
      pcVar6 = "!copyOf.type.getStruct()";
      uVar5 = 0xb1;
    }
  }
  else {
    pcVar6 = "copyOf.arrayInformationType == 0";
    uVar5 = 0xad;
  }
  ___eprintf("%s:%u: failed assertion `%s\'\n",
             "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/SymbolTable.cpp"
             ,uVar5,pcVar6);
LAB_97ba314c:
  *(uint *)(this + 0x38) = uVar1;
  return;
}

/* TVariable__TVariable_97ba2fb0 @ 0x97ba2fb0 (4 bytes) */
int TVariable__TVariable_97ba2fb0(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  ((int (*)())TSymbol__TSymbol)((unsigned char *)this,(unsigned char *)param_1);
  *(int *)this = DAT_a7b7ba78 + 8;
  *(undefined ***)(this + 0xc) = &PTR__TType_a7b7d590;
  TType__copyType((unsigned char *)(this + 0xc),(unsigned char *)(param_1 + 0xc));
  iVar2 = *(int *)(param_1 + 0x3c);
  uVar1 = *(uint *)(param_1 + 0x34);
  *(uint *)(this + 0x34) = uVar1;
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 0x38);
    *(undefined4 *)(this + 0x3c) = 0;
    uVar1 = 0;
    if (iVar2 == 0) goto LAB_97ba314c;
    uVar1 = *(uint *)(param_1 + 0x14);
    if (uVar1 == 0) {
      uVar1 = *(uint *)(param_1 + 0x30);
      if ((uVar1 & 0x400) == 0) {
        uVar1 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
      }
      else {
        iVar2 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
        uVar1 = iVar2 * iVar2;
      }
      if (uVar1 == 1) {
        uVar3 = GetGlobalPoolAllocator();
        puVar4 = (undefined4 *)TPoolAllocator__allocate(uVar3);
        *(undefined4 **)(this + 0x38) = puVar4;
        uVar1 = *(uint *)(this + 0x30) >> 0x13 & 0x3f;
        if (uVar1 == 2) {
LAB_97ba311c:
          *puVar4 = **(undefined4 **)(param_1 + 0x38);
          return;
        }
        if (uVar1 < 3) {
          if (uVar1 == 1) {
            *puVar4 = **(undefined4 **)(param_1 + 0x38);
            return;
          }
        }
        else if (uVar1 == 3) goto LAB_97ba311c;
        pcVar6 = "false && \"Unknown type\"";
        uVar5 = 0xb9;
      }
      else {
        pcVar6 = "copyOf.type.getInstanceSize() == 1";
        uVar5 = 0xb2;
      }
    }
    else {
      pcVar6 = "!copyOf.type.getStruct()";
      uVar5 = 0xb1;
    }
  }
  else {
    pcVar6 = "copyOf.arrayInformationType == 0";
    uVar5 = 0xad;
  }
  ___eprintf("%s:%u: failed assertion `%s\'\n",
             "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/SymbolTable.cpp"
             ,uVar5,pcVar6);
LAB_97ba314c:
  *(uint *)(this + 0x38) = uVar1;
  return;
}

/* TVariable__TVariable_97ba2fb4 @ 0x97ba2fb4 (432 bytes) */
int TVariable__TVariable_97ba2fb4(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
{
  uint uVar1;
  int iVar2;
  ulong uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  ((int (*)())TSymbol__TSymbol)((unsigned char *)this,(unsigned char *)param_1);
  *(int *)this = DAT_a7b7ba78 + 8;
  *(undefined ***)(this + 0xc) = &PTR__TType_a7b7d590;
  TType__copyType((unsigned char *)(this + 0xc),(unsigned char *)(param_1 + 0xc));
  iVar2 = *(int *)(param_1 + 0x3c);
  uVar1 = *(uint *)(param_1 + 0x34);
  *(uint *)(this + 0x34) = uVar1;
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_1 + 0x38);
    *(undefined4 *)(this + 0x3c) = 0;
    uVar1 = 0;
    if (iVar2 == 0) goto LAB_97ba314c;
    uVar1 = *(uint *)(param_1 + 0x14);
    if (uVar1 == 0) {
      uVar1 = *(uint *)(param_1 + 0x30);
      if ((uVar1 & 0x400) == 0) {
        uVar1 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
      }
      else {
        iVar2 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
        uVar1 = iVar2 * iVar2;
      }
      if (uVar1 == 1) {
        uVar3 = GetGlobalPoolAllocator();
        puVar4 = (undefined4 *)TPoolAllocator__allocate(uVar3);
        *(undefined4 **)(this + 0x38) = puVar4;
        uVar1 = *(uint *)(this + 0x30) >> 0x13 & 0x3f;
        if (uVar1 == 2) {
LAB_97ba311c:
          *puVar4 = **(undefined4 **)(param_1 + 0x38);
          return;
        }
        if (uVar1 < 3) {
          if (uVar1 == 1) {
            *puVar4 = **(undefined4 **)(param_1 + 0x38);
            return;
          }
        }
        else if (uVar1 == 3) goto LAB_97ba311c;
        pcVar6 = "false && \"Unknown type\"";
        uVar5 = 0xb9;
      }
      else {
        pcVar6 = "copyOf.type.getInstanceSize() == 1";
        uVar5 = 0xb2;
      }
    }
    else {
      pcVar6 = "!copyOf.type.getStruct()";
      uVar5 = 0xb1;
    }
  }
  else {
    pcVar6 = "copyOf.arrayInformationType == 0";
    uVar5 = 0xad;
  }
  ___eprintf("%s:%u: failed assertion `%s\'\n",
             "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/SymbolTable.cpp"
             ,uVar5,pcVar6);
LAB_97ba314c:
  *(uint *)(this + 0x38) = uVar1;
  return;
}

/* TVariable__clone @ 0x97ba3164 (76 bytes) */
int TVariable__clone(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  ulong uVar1;
  unsigned char * this_00;
  
  uVar1 = GetGlobalPoolAllocator();
  this_00 = (unsigned char *)TPoolAllocator__allocate(uVar1);
  TVariable(this_00,this,param_1);
  return this_00;
}

/* TFunction__TFunction @ 0x97ba31b0 (4 bytes) */
int TFunction__TFunction(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
{
  undefined1 *puVar1;
  int *piVar2;
  unsigned char * psVar3;
  undefined4 uVar4;
  ulong uVar5;
  unsigned char * this_00;
  unsigned char * pTVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  char *pcVar13;
  unsigned char * pmVar14;
  char in_RESERVE;
  byte in_cr0;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 auStack_50 [4];
  
  ((int (*)())TSymbol__TSymbol)((unsigned char *)this,(unsigned char *)param_1);
  *(int *)this = DAT_a7b7ba7c + 8;
  uVar4 = GetGlobalPoolAllocator();
  *(undefined4 *)(this + 0xc) = uVar4;
  iVar9 = DAT_a7b7ba74;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  piVar2 = (int *)(iVar9 + 8);
  *(undefined ***)(this + 0x1c) = &PTR__TType_a7b7d590;
  do {
    if (in_RESERVE != '\0') {
      iVar7 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar7;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  uVar4 = GetGlobalPoolAllocator();
  *(undefined4 *)(this + 0x44) = uVar4;
  *(int *)(this + 0x48) = iVar9 + 0xc;
  puVar1 = DAT_a7b7ba80;
  for (uVar12 = 0; uVar12 < (uint)(*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10) >> 3);
      uVar12 = uVar12 + 1) {
    puVar8 = *(undefined4 **)(this + 0x14);
    if (puVar8 == *(undefined4 **)(this + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                (this + 0xc,*(undefined4 *)(this + 0x14),&uStack_60);
    }
    else {
      iVar9 = 0;
      if (puVar8 != (undefined4 *)0x0) {
        puVar8[1] = uStack_5c;
        *puVar8 = uStack_60;
        iVar9 = *(int *)(this + 0x14);
      }
      *(int *)(this + 0x14) = iVar9 + 8;
    }
    iVar7 = *(int *)(param_1 + 0x10);
    iVar11 = *(int *)(iVar7 + uVar12 * 8);
    iVar9 = *(int *)(this + 0x14);
    iVar10 = *(int *)(iVar11 + 4);
    *(undefined1 *)(iVar10 + *(int *)(iVar10 + -0xc)) = *puVar1;
    pcVar13 = *(char **)(iVar11 + 4);
    uVar5 = GetGlobalPoolAllocator();
    this_00 = (unsigned char *)TPoolAllocator__allocate(uVar5);
    psVar3 = (unsigned char *)0x0;
    if (this_00 != (unsigned char *)0x0) {
      auStack_50[0] = GetGlobalPoolAllocator();
      std__string__string(this_00,pcVar13,(unsigned char *)auStack_50);
      psVar3 = this_00;
    }
    *(unsigned char **)(iVar9 + -8) = psVar3;
    pmVar14 = *(unsigned char **)(iVar7 + uVar12 * 8 + 4);
    uVar5 = GetGlobalPoolAllocator();
    pTVar6 = (unsigned char *)TPoolAllocator__allocate(uVar5);
    *(undefined ***)pTVar6 = &PTR__TType_a7b7d590;
    TType__copyType(pTVar6,pmVar14);
    *(unsigned char **)(iVar9 + -4) = pTVar6;
  }
  TType__copyType((unsigned char *)(this + 0x1c),(unsigned char *)(param_1 + 0x1c));
  std__string__assign((unsigned char *)(this + 0x44));
  uVar4 = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x4c) = uVar4;
  return;
}

/* TFunction__TFunction_97ba31b4 @ 0x97ba31b4 (4 bytes) */
int TFunction__TFunction_97ba31b4(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
{
  undefined1 *puVar1;
  int *piVar2;
  unsigned char * psVar3;
  undefined4 uVar4;
  ulong uVar5;
  unsigned char * this_00;
  unsigned char * pTVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  char *pcVar13;
  unsigned char * pmVar14;
  char in_RESERVE;
  byte in_cr0;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 auStack_50 [4];
  
  ((int (*)())TSymbol__TSymbol)((unsigned char *)this,(unsigned char *)param_1);
  *(int *)this = DAT_a7b7ba7c + 8;
  uVar4 = GetGlobalPoolAllocator();
  *(undefined4 *)(this + 0xc) = uVar4;
  iVar9 = DAT_a7b7ba74;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  piVar2 = (int *)(iVar9 + 8);
  *(undefined ***)(this + 0x1c) = &PTR__TType_a7b7d590;
  do {
    if (in_RESERVE != '\0') {
      iVar7 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar7;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  uVar4 = GetGlobalPoolAllocator();
  *(undefined4 *)(this + 0x44) = uVar4;
  *(int *)(this + 0x48) = iVar9 + 0xc;
  puVar1 = DAT_a7b7ba80;
  for (uVar12 = 0; uVar12 < (uint)(*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10) >> 3);
      uVar12 = uVar12 + 1) {
    puVar8 = *(undefined4 **)(this + 0x14);
    if (puVar8 == *(undefined4 **)(this + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                (this + 0xc,*(undefined4 *)(this + 0x14),&uStack_60);
    }
    else {
      iVar9 = 0;
      if (puVar8 != (undefined4 *)0x0) {
        puVar8[1] = uStack_5c;
        *puVar8 = uStack_60;
        iVar9 = *(int *)(this + 0x14);
      }
      *(int *)(this + 0x14) = iVar9 + 8;
    }
    iVar7 = *(int *)(param_1 + 0x10);
    iVar11 = *(int *)(iVar7 + uVar12 * 8);
    iVar9 = *(int *)(this + 0x14);
    iVar10 = *(int *)(iVar11 + 4);
    *(undefined1 *)(iVar10 + *(int *)(iVar10 + -0xc)) = *puVar1;
    pcVar13 = *(char **)(iVar11 + 4);
    uVar5 = GetGlobalPoolAllocator();
    this_00 = (unsigned char *)TPoolAllocator__allocate(uVar5);
    psVar3 = (unsigned char *)0x0;
    if (this_00 != (unsigned char *)0x0) {
      auStack_50[0] = GetGlobalPoolAllocator();
      std__string__string(this_00,pcVar13,(unsigned char *)auStack_50);
      psVar3 = this_00;
    }
    *(unsigned char **)(iVar9 + -8) = psVar3;
    pmVar14 = *(unsigned char **)(iVar7 + uVar12 * 8 + 4);
    uVar5 = GetGlobalPoolAllocator();
    pTVar6 = (unsigned char *)TPoolAllocator__allocate(uVar5);
    *(undefined ***)pTVar6 = &PTR__TType_a7b7d590;
    TType__copyType(pTVar6,pmVar14);
    *(unsigned char **)(iVar9 + -4) = pTVar6;
  }
  TType__copyType((unsigned char *)(this + 0x1c),(unsigned char *)(param_1 + 0x1c));
  std__string__assign((unsigned char *)(this + 0x44));
  uVar4 = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x4c) = uVar4;
  return;
}

/* TFunction__TFunction_97ba31b8 @ 0x97ba31b8 (492 bytes) */
int TFunction__TFunction_97ba31b8(this, param_1, param_2)
  unsigned char * this;
  unsigned char * param_1;
  unsigned char * param_2;
{
  undefined1 *puVar1;
  int *piVar2;
  unsigned char * psVar3;
  undefined4 uVar4;
  ulong uVar5;
  unsigned char * this_00;
  unsigned char * pTVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  char *pcVar13;
  unsigned char * pmVar14;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_50 [4];
  
  ((int (*)())TSymbol__TSymbol)((unsigned char *)this,(unsigned char *)param_1);
  *(int *)this = DAT_a7b7ba7c + 8;
  uVar4 = GetGlobalPoolAllocator();
  *(undefined4 *)(this + 0xc) = uVar4;
  iVar9 = DAT_a7b7ba74;
  *(undefined4 *)(this + 0x18) = 0;
  *(undefined4 *)(this + 0x10) = 0;
  *(undefined4 *)(this + 0x14) = 0;
  piVar2 = (int *)(iVar9 + 8);
  *(undefined ***)(this + 0x1c) = &PTR__TType_a7b7d590;
  do {
    if (in_RESERVE != '\0') {
      iVar7 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar7;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  uVar4 = GetGlobalPoolAllocator();
  *(undefined4 *)(this + 0x44) = uVar4;
  *(int *)(this + 0x48) = iVar9 + 0xc;
  puVar1 = DAT_a7b7ba80;
  for (uVar12 = 0; uVar12 < (uint)(*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10) >> 3);
      uVar12 = uVar12 + 1) {
    puVar8 = *(undefined4 **)(this + 0x14);
    if (puVar8 == *(undefined4 **)(this + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                (this + 0xc,*(undefined4 *)(this + 0x14),&local_60);
    }
    else {
      iVar9 = 0;
      if (puVar8 != (undefined4 *)0x0) {
        puVar8[1] = local_5c;
        *puVar8 = local_60;
        iVar9 = *(int *)(this + 0x14);
      }
      *(int *)(this + 0x14) = iVar9 + 8;
    }
    iVar7 = *(int *)(param_1 + 0x10);
    iVar11 = *(int *)(iVar7 + uVar12 * 8);
    iVar9 = *(int *)(this + 0x14);
    iVar10 = *(int *)(iVar11 + 4);
    *(undefined1 *)(iVar10 + *(int *)(iVar10 + -0xc)) = *puVar1;
    pcVar13 = *(char **)(iVar11 + 4);
    uVar5 = GetGlobalPoolAllocator();
    this_00 = (unsigned char *)TPoolAllocator__allocate(uVar5);
    psVar3 = (unsigned char *)0x0;
    if (this_00 != (unsigned char *)0x0) {
      local_50[0] = GetGlobalPoolAllocator();
      std__string__string(this_00,pcVar13,(unsigned char *)local_50);
      psVar3 = this_00;
    }
    *(unsigned char **)(iVar9 + -8) = psVar3;
    pmVar14 = *(unsigned char **)(iVar7 + uVar12 * 8 + 4);
    uVar5 = GetGlobalPoolAllocator();
    pTVar6 = (unsigned char *)TPoolAllocator__allocate(uVar5);
    *(undefined ***)pTVar6 = &PTR__TType_a7b7d590;
    TType__copyType(pTVar6,pmVar14);
    *(unsigned char **)(iVar9 + -4) = pTVar6;
  }
  TType__copyType((unsigned char *)(this + 0x1c),(unsigned char *)(param_1 + 0x1c));
  std__string__assign((unsigned char *)(this + 0x44));
  uVar4 = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(this + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(this + 0x4c) = uVar4;
  return;
}

/* TFunction__clone @ 0x97ba33a4 (76 bytes) */
int TFunction__clone(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  ulong uVar1;
  unsigned char * this_00;
  
  uVar1 = GetGlobalPoolAllocator();
  this_00 = (unsigned char *)TPoolAllocator__allocate(uVar1);
  TFunction(this_00,this,param_1);
  return this_00;
}

/* TSymbolTableLevel__clone @ 0x97ba33f0 (352 bytes) */
int TSymbolTableLevel__clone(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  ulong uVar4;
  ulong *puVar5;
  undefined4 *puVar6;
  int *piVar7;
  unsigned char * psVar8;
  char in_RESERVE;
  byte in_cr0;
  unsigned char local_60 [16];
  undefined4 local_50;
  int local_4c;
  int *local_48;
  undefined4 local_40;
  
  uVar4 = GetGlobalPoolAllocator();
  puVar5 = (ulong *)TPoolAllocator__allocate(uVar4);
  uVar4 = GetGlobalPoolAllocator();
  puVar5[1] = 0;
  *puVar5 = uVar4;
  puVar6 = (undefined4 *)TPoolAllocator__allocate(uVar4);
  puVar5[2] = 0;
  puVar5[1] = (ulong)puVar6;
  *puVar6 = 0;
  *(undefined4 *)(puVar5[1] + 4) = 0;
  *(ulong *)(puVar5[1] + 8) = puVar5[1];
  *(ulong *)(puVar5[1] + 0xc) = puVar5[1];
  iVar2 = *(int *)(*(int *)(this + 4) + 8);
  if (iVar2 != *(int *)(this + 4)) {
    do {
      piVar7 = (int *)(**(code **)(**(int **)(iVar2 + 0x18) + 0x18))
                                (*(int **)(iVar2 + 0x18),param_1);
      psVar8 = (unsigned char *)(**(code **)(*piVar7 + 8))();
      std__string__string((unsigned char *)&local_50,psVar8);
      local_48 = piVar7;
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique(local_60);
      piVar7 = (int *)(local_4c + -4);
      local_40 = local_50;
      do {
        iVar3 = *piVar7;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar7);
          *piVar7 = iVar1;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar3 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(local_4c + -0xc));
      }
      std___Rb_tree_base_iterator___M_increment();
    } while (iVar2 != *(int *)(this + 4));
  }
  return puVar5;
}

/* TSymbolTable__copyTable @ 0x97ba3550 (492 bytes) */
int TSymbolTable__copyTable(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  undefined4 uVar1;
  undefined *puVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  uint uVar6;
  char in_RESERVE;
  byte in_cr0;
  undefined4 *local_60;
  int local_5c;
  undefined4 local_30 [5];
  
  puVar2 = PTR__S_force_new_a7b7c0e8;
  local_60 = (undefined4 *)0x0;
  if (*(int *)PTR__S_force_new_a7b7c0e8 == 0) {
    pcVar4 = _getenv("GLIBCPP_FORCE_NEW");
    if (pcVar4 == (char *)0x0) {
      do {
        if (in_RESERVE != '\0') {
          uVar1 = storeWordConditionalIndexed(*(int *)puVar2 + -1,0,puVar2);
          *(undefined4 *)puVar2 = uVar1;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
    }
    else {
      do {
        if (in_RESERVE != '\0') {
          uVar1 = storeWordConditionalIndexed(*(int *)puVar2 + 1,0,puVar2);
          *(undefined4 *)puVar2 = uVar1;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
    }
  }
  puVar2 = PTR__S_free_list_a7b7c0e4;
  if (*(int *)PTR__S_force_new_a7b7c0e8 < 1) {
    _pthread_mutex_lock((pthread_mutex_t *)PTR__S_node_allocator_lock_a7b7c0e0);
    puVar5 = *(undefined4 **)(puVar2 + 8);
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)std____default_alloc_template_true_0____S_refill(0x18);
    }
    else {
      *(undefined4 *)(puVar2 + 8) = *puVar5;
    }
    if (puVar5 == (undefined4 *)0x0) {
      std____throw_bad_alloc();
    }
    _pthread_mutex_unlock((pthread_mutex_t *)PTR__S_node_allocator_lock_a7b7c0e0);
  }
  else {
    puVar5 = operator_new(0x18);
  }
  local_5c = 0;
  *puVar5 = 0;
  puVar5[1] = 0;
  puVar5[2] = puVar5;
  puVar5[3] = puVar5;
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_1 + 0xc);
  local_60 = puVar5;
  for (uVar6 = 0; uVar6 < (uint)(*(int *)(param_1 + 4) - *(int *)param_1 >> 2); uVar6 = uVar6 + 1) {
    local_30[0] = ((int (*)())TSymbolTableLevel__clone)(*(unsigned char **)(*(int *)param_1 + uVar6 * 4),(unsigned char *)&local_60);
    puVar5 = *(undefined4 **)(this + 4);
    if (puVar5 == *(undefined4 **)(this + 8)) {
      std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                (this,puVar5,local_30);
    }
    else {
      iVar3 = 0;
      if (puVar5 != (undefined4 *)0x0) {
        *puVar5 = local_30[0];
        iVar3 = *(int *)(this + 4);
      }
      *(int *)(this + 4) = iVar3 + 4;
    }
  }
  if (local_5c != 0) {
    std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine________M_erase((unsigned char *)&local_60);
    local_60[2] = local_60;
    local_60[1] = 0;
    local_60[3] = local_60;
    local_5c = 0;
  }
  std____default_alloc_template_true_0___deallocate(local_60,0x18);
  return;
}

/* yyparse @ 0x97ba373c (34436 bytes) */
int yyparse(param_1)
  void *param_1;
{
  short sVar1;
  unsigned char * psVar2;
  uint uVar3;
  unsigned char * psVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined *puVar7;
  int iVar8;
  unsigned char * pTVar9;
  unsigned char * pTVar10;
  unsigned char * pTVar11;
  unsigned char * pcVar12;
  bool *pbVar13;
  unsigned char * paVar14;
  unsigned char * pTVar15;
  unsigned char * psVar16;
  unsigned char * pTVar17;
  unsigned char * psVar18;
  undefined4 uVar19;
  ulong uVar20;
  ulong *puVar21;
  undefined4 *puVar22;
  unsigned char * pTVar23;
  int *piVar24;
  unsigned char * pTVar25;
  unsigned char * pTVar26;
  uint *puVar27;
  unsigned char * pTVar28;
  unsigned char * pTVar29;
  undefined4 uVar30;
  int iVar31;
  unsigned char * pTVar32;
  char *pcVar33;
  int iVar34;
  undefined1 uVar37;
  char *pcVar35;
  int iVar36;
  int iVar38;
  bool bVar40;
  int iVar39;
  int iVar41;
  int iVar42;
  int iVar43;
  code *pcVar44;
  int iVar45;
  uint *puVar46;
  int iVar47;
  uint uVar48;
  short *psVar49;
  short *psVar50;
  short *psVar51;
  uint *puVar52;
  uint uVar53;
  uint uVar54;
  int iVar55;
  int *piVar56;
  uint uVar57;
  int iVar58;
  uint uVar59;
  uint uVar60;
  uint uVar61;
  int iVar62;
  int *piVar63;
  char *pcVar64;
  char in_RESERVE;
  byte in_cr0;
  short sStack_2ca2;
  short local_2ca0 [200];
  uint auStack_2b10 [2200];
  unsigned char aYStack_8b0 [48];
  uint local_880;
  undefined4 local_87c;
  unsigned char * local_878;
  uint local_874;
  unsigned char * local_870;
  unsigned char * local_86c;
  unsigned char * local_868;
  unsigned char * local_864;
  unsigned char * local_860;
  unsigned char * local_85c;
  unsigned char * local_858;
  unsigned char * local_850;
  unsigned char * local_84c;
  unsigned char * local_848;
  unsigned char * local_844;
  unsigned char * local_840;
  unsigned char * local_83c;
  unsigned char * local_838;
  unsigned char * local_834;
  unsigned char * local_830;
  unsigned char * local_82c;
  unsigned char * local_828;
  unsigned char * local_824;
  unsigned char * local_820;
  unsigned char * local_81c;
  unsigned char * local_818;
  unsigned char * local_814;
  unsigned char * local_810;
  unsigned char * local_80c;
  unsigned char * local_808;
  unsigned char * local_804;
  unsigned char * local_800;
  unsigned char * local_7fc;
  unsigned char * local_7f8;
  unsigned char * local_7f4;
  unsigned char * local_7f0;
  unsigned char * local_7ec;
  unsigned char * local_7e8;
  unsigned char * local_7e4;
  unsigned char * local_7e0;
  unsigned char * local_7dc;
  unsigned char * local_7d8;
  unsigned char * local_7d4;
  unsigned char * local_7d0;
  uint local_7cc;
  undefined4 local_7c0;
  uint local_7bc;
  int local_7b0;
  char *local_7ac;
  int local_780;
  int local_77c;
  int local_764;
  unsigned char * local_750 [4];
  unsigned char * local_740;
  undefined4 local_720 [4];
  int local_710;
  undefined4 local_700;
  unsigned char * local_6f0;
  unsigned char * local_6e0;
  unsigned char * local_6d0;
  unsigned char * local_6c0;
  undefined4 local_6b0 [4];
  unsigned char * local_6a0;
  undefined4 local_690 [4];
  unsigned char * local_680;
  undefined4 local_670 [4];
  int local_660;
  unsigned char * local_650;
  int local_640;
  int local_630;
  int local_620;
  unsigned char * local_610;
  unsigned char * local_600;
  unsigned char * local_5f0;
  unsigned char * local_5e0;
  unsigned char * local_5d0;
  unsigned char * local_5c0;
  unsigned char * local_5b0;
  unsigned char * local_5a0;
  unsigned char * local_590;
  unsigned char * local_580;
  unsigned char * local_570;
  unsigned char * local_560;
  unsigned char * local_550;
  unsigned char * local_540;
  unsigned char * local_530;
  unsigned char * local_520;
  unsigned char * local_510;
  unsigned char * local_500;
  unsigned char * local_4f0;
  unsigned char * local_4e0;
  unsigned char * local_4d0;
  unsigned char * local_4c0;
  unsigned char * local_4b0;
  unsigned char * local_4a0;
  unsigned char * local_490;
  unsigned char * local_480;
  unsigned char * local_470;
  unsigned char * local_460;
  unsigned char * local_450;
  unsigned char * local_440;
  unsigned char * local_430;
  unsigned char * local_420;
  unsigned char * local_410;
  unsigned char * local_400;
  unsigned char * local_3f0;
  unsigned char * local_3e0;
  unsigned char * local_3d0;
  unsigned char * local_3c0;
  unsigned char * local_3b0;
  unsigned char * local_3a0;
  unsigned char * local_390;
  unsigned char * local_380;
  unsigned char * local_370;
  unsigned char * local_360;
  unsigned char * local_350;
  unsigned char * local_340;
  unsigned char * local_330;
  int local_320 [4];
  undefined4 local_310;
  int local_30c;
  unsigned char * local_308;
  undefined4 local_300;
  undefined4 local_2f0 [4];
  unsigned char * local_2e0;
  undefined4 local_2d0 [4];
  unsigned char * local_2c0;
  undefined4 local_2b0 [4];
  int local_2a0;
  undefined4 local_290 [4];
  undefined4 local_280 [4];
  unsigned char * local_270;
  undefined4 local_260 [4];
  undefined4 local_250 [4];
  undefined4 local_240 [4];
  unsigned char * local_230;
  undefined4 local_220 [4];
  undefined4 local_210 [4];
  unsigned char * local_200;
  unsigned char * local_1f0;
  undefined4 local_1e0;
  int local_1dc;
  int *local_1d8;
  undefined4 local_1d0;
  undefined4 local_1c0 [4];
  undefined4 local_1b0 [4];
  unsigned char * local_1a0;
  unsigned char * local_190;
  int local_180;
  ulong local_170;
  ulong *local_160 [4];
  ulong local_150;
  ulong local_140;
  ulong local_130;
  undefined4 local_120;
  undefined4 local_110;
  undefined4 local_100;
  undefined4 local_f0;
  int local_ec;
  int *local_e8;
  undefined4 local_e0;
  undefined4 local_d0 [4];
  unsigned char * local_c0;
  undefined4 local_b0 [4];
  unsigned char * local_a0;
  uint local_90;
  uint local_8c;
  int local_88;
  int local_84;
  uint local_80;
  uint local_7c;
  uint local_78;
  uint local_74 [2];
  int local_6c;
  undefined *local_68;
  int local_64;
  int local_60;
  int local_5c;
  int *local_58;
  int local_54;
  
  puVar5 = (undefined4 *)&STACKARG(0xffffd310);
  puVar52 = auStack_2b10;
  iVar45 = 200;
  iVar55 = 0;
  iVar47 = 0;
  uVar48 = 0xfffffffe;
  psVar51 = &sStack_2ca2;
  local_60 = 400;
  puVar46 = puVar52;
  psVar49 = local_2ca0;
LAB_97ba3784:
  psVar51 = psVar51 + 1;
  *psVar51 = (short)iVar55;
  puVar27 = puVar46;
  psVar50 = psVar49;
  if ((short *)((int)psVar49 + local_60 + -2) <= psVar51) {
    iVar6 = (int)psVar51 - (int)psVar49 >> 1;
    iVar58 = iVar6 + 1;
    if (9999 < iVar45) {
      yyerror("parser stack overflow");
      return 2;
    }
    iVar45 = local_60;
    if (10000 < local_60) {
      iVar45 = 10000;
    }
    local_60 = iVar45 * 2;
    puVar22 = (undefined4 *)((int)puVar5 - (local_60 + 0x1eU & 0xfffffff0));
    *puVar22 = *puVar5;
    psVar50 = (short *)(puVar22 + 0x14);
    _memcpy(psVar50,psVar49,iVar58 * 2);
    psVar51 = psVar50 + iVar6;
    puVar5 = (undefined4 *)((int)puVar22 - (iVar45 * 0x2c + 0x1eU & 0xfffffff0));
    *puVar5 = *puVar22;
    puVar27 = puVar5 + 0x14;
    _memcpy(puVar27,puVar46,iVar58 * 0x2c);
    puVar52 = puVar27 + iVar58 * 0xb + -0xb;
    if ((short *)((int)psVar50 + local_60 + -2) <= psVar51) {
      return 1;
    }
  }
  iVar6 = iVar55 * 2;
  sVar1 = (&_yypact)[iVar55];
  puVar46 = puVar27;
  psVar49 = psVar50;
  if (sVar1 != -0x8000) {
    if (uVar48 == 0xfffffffe) {
      uVar48 = ((int (*)())yylex)(aYStack_8b0,param_1);
    }
    if ((int)uVar48 < 1) {
      iVar55 = 0;
      uVar48 = 0;
    }
    else {
      iVar55 = 0xa9;
      if (uVar48 < 0x15d) {
        iVar55 = (int)(char)(&_yytranslate)[uVar48];
      }
    }
    uVar59 = sVar1 + iVar55;
    if ((uVar59 < 0x4f0) && (iVar58 = uVar59 * 2, *(short *)(&_yycheck + iVar58) == iVar55)) {
      iVar55 = (int)*(short *)(&_yytable + iVar58);
      if (-1 < iVar55) {
        if (iVar55 == 0) goto LAB_97bac03c;
        if (iVar55 == 0x14d) {
          return 0;
        }
        if (uVar48 != 0) {
          uVar48 = 0xfffffffe;
        }
        puVar52 = puVar52 + 0xb;
        _memcpy(puVar52,aYStack_8b0,0x2c);
        if (iVar47 != 0) {
          iVar47 = iVar47 + -1;
        }
        goto LAB_97ba3784;
      }
      if (iVar55 != -0x8000) goto LAB_97bac0d0;
      goto LAB_97bac03c;
    }
  }
  iVar55 = (int)*(short *)(&_yydefact + iVar6);
  if (iVar55 != 0) goto LAB_97ba3970;
LAB_97bac03c:
  if (iVar47 == 0) {
    yyerror("parse error");
  }
LAB_97bac050:
  if (iVar47 == 3) {
    if (uVar48 == 0) {
      return 1;
    }
    uVar48 = 0xfffffffe;
  }
  iVar47 = 3;
  do {
    if (((*(short *)((int)&_yypact + iVar6) != -0x8000) &&
        (uVar59 = (int)*(short *)((int)&_yypact + iVar6) + 1, uVar59 < 0x4f0)) &&
       (iVar55 = uVar59 * 2, *(short *)(&_yycheck + iVar55) == 1)) {
      iVar55 = (int)*(short *)(&_yytable + iVar55);
      if (iVar55 < 0) {
        if (iVar55 != -0x8000) break;
      }
      else if (iVar55 != 0) {
        if (iVar55 == 0x14d) {
          return 0;
        }
        puVar52 = puVar52 + 0xb;
        _memcpy(puVar52,aYStack_8b0,0x2c);
        goto LAB_97ba3784;
      }
    }
    if (psVar51 == psVar50) {
      return 1;
    }
    psVar51 = psVar51 + -1;
    puVar52 = puVar52 + -0xb;
    iVar6 = (int)*psVar51 << 1;
  } while( true );
LAB_97bac0d0:
  iVar55 = -iVar55;
LAB_97ba3970:
  local_6c = iVar55 * 2;
  iVar58 = (int)*(short *)(&_yyr2 + local_6c);
  if (0 < iVar58) {
    _memcpy(&local_880,puVar52 + (1 - iVar58) * 0xb,0x2c);
  }
  psVar4 = local_878;
  psVar18 = local_7f0;
  psVar16 = local_750;
  switch(iVar55) {
  default:
    break;
  case 1:
    psVar4 = (unsigned char *)puVar52[2];
    if (psVar4 == (unsigned char *)0x0) {
      uVar59 = puVar52[1];
      local_64 = -0x5847c8b4;
      iVar55 = *(int *)(uVar59 + 4);
      *(unsigned char *)(iVar55 + *(int *)(iVar55 + -0xc)) = *DAT_a7b7ba88;
      TParseContext__error
                ((int)param_1,(char *)*puVar52,"undeclared identifier",*(char **)(uVar59 + 4),"");
      TParseContext__recover();
      local_5c = -0x5847c8b4;
      local_82c = (unsigned char *)((uint)local_82c & 0x1ff | 0x80800);
      local_850 = (unsigned char *)&PTR__TType_a7b7d640;
      local_84c = psVar4;
      local_848 = psVar4;
      local_844 = psVar4;
      local_840 = psVar4;
      local_83c = psVar4;
      local_838 = psVar4;
      local_834 = psVar4;
      local_830 = psVar4;
      uVar20 = GetGlobalPoolAllocator();
      psVar18 = (unsigned char *)TPoolAllocator__allocate(uVar20);
      uVar59 = puVar52[1];
      puVar7 = PTR_vtable_a7b7c0b4 + 8;
      *(undefined ***)(psVar18 + 0xc) = &PTR__TType_a7b7d640;
      *(uint *)(psVar18 + 4) = uVar59;
      *(undefined **)psVar18 = puVar7;
      *(unsigned char **)(psVar18 + 0x10) = local_84c;
      *(unsigned char **)(psVar18 + 0x14) = local_848;
      *(unsigned char **)(psVar18 + 0x18) = local_844;
      *(unsigned char **)(psVar18 + 0x1c) = local_840;
      *(unsigned char **)(psVar18 + 0x20) = local_83c;
      *(unsigned char **)(psVar18 + 0x24) = local_838;
      *(unsigned char **)(psVar18 + 0x28) = local_834;
      *(unsigned char **)(psVar18 + 0x2c) = local_830;
      uVar3 = *(uint *)(psVar18 + 0x30);
      uVar54 = (uint)local_82c & 0xfe000000;
      *(uint *)(psVar18 + 0x30) = uVar54 | uVar3 & 0x1ffffff;
      uVar57 = ((uint)local_82c >> 0x13 & 0x3f) << 0x13;
      *(uint *)(psVar18 + 0x30) = uVar57 | uVar54 | uVar3 & 0x7ffff;
      uVar59 = (uint)local_82c & 0x7f800;
      *(uint *)(psVar18 + 0x30) = uVar59 | uVar57 | uVar54 | uVar3 & 0x7ff;
      uVar61 = ((uint)local_82c >> 10 & 1) << 10;
      *(uint *)(psVar18 + 0x30) = uVar61 | uVar59 | uVar57 | uVar54 | uVar3 & 0x3ff;
      *(uint *)(psVar18 + 0x30) =
           ((uint)local_82c >> 9 & 1) << 9 | uVar61 | uVar59 | uVar57 | uVar54 | uVar3 & 0x1ff;
      *(int *)(psVar18 + 0x34) = 0;
      *(int *)(psVar18 + 0x38) = 0;
      *(int *)(psVar18 + 0x3c) = 0;
      iVar55 = *(int *)(*(int *)((int)param_1 + 4) + 0xc) + 1;
      *(int *)(*(int *)((int)param_1 + 4) + 0xc) = iVar55;
      *(int *)(psVar18 + 8) = iVar55;
      local_81c = psVar4;
      psVar4 = (unsigned char *)(**(code **)(*(int *)psVar18 + 8))();
      std__string__string((unsigned char *)&local_800,psVar4);
      local_7f8 = psVar18;
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_810);
      local_820 = local_810;
      psVar4 = local_7fc + -4;
      local_81c = local_80c;
      local_7f0 = local_800;
      do {
        iVar55 = *(int *)psVar4;
        if (in_RESERVE != '\0') {
          iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
          *(int *)psVar4 = iVar6;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar55 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(local_7fc + -0xc));
      }
      local_850 = (unsigned char *)&PTR__TType_a7b7d640;
      psVar4 = psVar18;
    }
    else {
      iVar55 = (**(code **)(*(int *)psVar4 + 0x10))(psVar4);
      if (iVar55 == 0) {
        uVar59 = puVar52[1];
        local_64 = -0x5847c8b4;
        iVar55 = *(int *)(uVar59 + 4);
        *(unsigned char *)(iVar55 + *(int *)(iVar55 + -0xc)) = *DAT_a7b7ba88;
        TParseContext__error
                  ((int)param_1,(char *)*puVar52,"variable expected",*(char **)(uVar59 + 4),"");
        TParseContext__recover();
      }
    }
    iVar55 = (**(code **)(*(int *)(psVar4 + 0xc) + 0x24))(psVar4 + 0xc);
    if (iVar55 != 2) {
      psVar4 = (unsigned char *)
               TIntermediate__addSymbol
                         (*(int *)param_1,*(unsigned char **)(psVar4 + 8),*(unsigned char **)(psVar4 + 4),
                          (int)(psVar4 + 0xc));
      psVar18 = local_7f0;
      psVar16 = local_750;
      break;
    }
    local_84c = *(unsigned char **)(psVar4 + 0x10);
    local_844 = *(unsigned char **)(psVar4 + 0x18);
    local_840 = *(unsigned char **)(psVar4 + 0x1c);
    local_848 = *(unsigned char **)(psVar4 + 0x14);
    local_83c = *(unsigned char **)(psVar4 + 0x20);
    local_838 = *(unsigned char **)(psVar4 + 0x24);
    local_834 = *(unsigned char **)(psVar4 + 0x28);
    local_830 = *(unsigned char **)(psVar4 + 0x2c);
    pTVar11 = *(unsigned char **)(psVar4 + 0x38);
    local_82c = (unsigned char *)
                ((*(uint *)(psVar4 + 0x30) >> 9 & 1) << 9 |
                (*(uint *)(psVar4 + 0x30) >> 10 & 1) << 10 |
                *(uint *)(psVar4 + 0x30) & 0x7f800 |
                (*(uint *)(psVar4 + 0x30) >> 0x13 & 0x3f) << 0x13 |
                *(uint *)(psVar4 + 0x30) & 0xfe000000 | (uint)local_82c & 0x1ff);
LAB_97ba4158:
    local_850 = (unsigned char *)&PTR__TType_a7b7d640;
    pcVar12 = *(unsigned char **)param_1;
    goto LAB_97ba7d0c;
  case 2:
  case 7:
  case 9:
  case 0x28:
  case 0x30:
  case 0x34:
  case 0x37:
  case 0x3a:
  case 0x3f:
  case 0x42:
  case 0x44:
  case 0x46:
  case 0x48:
  case 0x4a:
  case 0x4c:
  case 0x4e:
  case 0x50:
  case 0x5d:
  case 0xa7:
  case 0xa8:
  case 0xa9:
  case 0xaa:
  case 0xab:
  case 0xac:
  case 0xad:
  case 0xae:
  case 0xaf:
  case 0xb4:
  case 0xb5:
  case 199:
  case 200:
  case 0xc9:
  case 0xd4:
  case 0xd5:
    goto switchD_97ba39c8_caseD_2;
  case 3:
    uVar59 = (int)puVar52[1] >> 0x1f;
    if (0xffff < (int)((uVar59 ^ puVar52[1]) - uVar59)) {
      TParseContext__error((int)param_1,(char *)*puVar52," integer constant overflow","","");
      TParseContext__recover();
    }
    uVar20 = GetGlobalPoolAllocator();
    pTVar11 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    *(uint *)pTVar11 = puVar52[1];
    local_82c = (unsigned char *)((uint)local_82c & 0x9ff | 0x4100800);
    local_84c = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_838 = (unsigned char *)0x0;
    local_834 = (unsigned char *)0x0;
    local_830 = (unsigned char *)0x0;
    goto LAB_97ba4158;
  case 4:
    uVar20 = GetGlobalPoolAllocator();
    pTVar11 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    *(uint *)pTVar11 = puVar52[1];
    uVar59 = (uint)local_82c & 0x7ff | 0x4080000;
    goto LAB_97ba41e8;
  case 5:
    uVar20 = GetGlobalPoolAllocator();
    pTVar11 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    *(uint *)pTVar11 = puVar52[1];
    local_5c = -0x5847c8b4;
    uVar59 = (uint)local_82c & 0x1807ff | 0x4180000;
LAB_97ba41e8:
    local_82c = (unsigned char *)(uVar59 & 0xfffff9ff | 0x800);
    local_830 = (unsigned char *)0x0;
    local_84c = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_838 = (unsigned char *)0x0;
    local_834 = (unsigned char *)0x0;
    goto LAB_97ba4158;
  case 6:
  case 0xbb:
    goto switchD_97ba39c8_caseD_6;
  case 8:
    iVar55 = (**(code **)(*(int *)puVar52[-0x1f] + 0x54))();
    if (((iVar55 == 0) && (iVar55 = (**(code **)(*(int *)puVar52[-0x1f] + 0x50))(), iVar55 == 0)) &&
       (iVar55 = (**(code **)(*(int *)puVar52[-0x1f] + 0x58))(), iVar55 == 0)) {
      iVar55 = (**(code **)(*(int *)puVar52[-0x1f] + 0x28))();
      if (iVar55 == 0) {
        pcVar64 = (char *)puVar52[-0x16];
        pcVar33 = "expression";
      }
      else {
        local_64 = -0x5847c8b4;
        piVar63 = (int *)(**(code **)(*(int *)puVar52[-0x1f] + 0x28))();
        iVar55 = (**(code **)(*piVar63 + 0x60))();
        *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
             **(undefined1 **)(local_64 + -0x7cc4);
        pcVar33 = *(char **)(iVar55 + 4);
        pcVar64 = (char *)puVar52[-0x16];
      }
      TParseContext__error
                ((int)param_1,pcVar64," left of \'[\' is not of type array, matrix, or vector ",
                 pcVar33,"");
      TParseContext__recover();
    }
    bVar40 = false;
    (**(code **)(*(int *)puVar52[-0x1f] + 0x38))(&local_850);
    if ((((uint)local_82c >> 0x19 == 2) &&
        (iVar55 = (**(code **)(*(int *)puVar52[-0x1f] + 0x54))(), iVar55 == 0)) &&
       (iVar55 = (**(code **)(*(int *)puVar52[-9] + 0x44))(), iVar55 == 2)) {
      bVar40 = true;
    }
    local_5c = -0x5847c8b4;
    local_850 = (unsigned char *)&PTR__TType_a7b7d640;
    if (bVar40) {
      iVar55 = (**(code **)(*(int *)puVar52[-0x1f] + 0x58))();
      if (iVar55 == 0) {
        iVar55 = (**(code **)(*(int *)puVar52[-0x1f] + 0x50))();
        if (iVar55 != 0) {
          iVar55 = (**(code **)(*(int *)puVar52[-9] + 0x18))();
          local_878 = (unsigned char *)
                      TParseContext__addConstMatrixNode
                                ((int)param_1,(unsigned char *)**(undefined4 **)(iVar55 + 0x30),
                                 puVar52[-0x1f]);
        }
      }
      else {
        local_810 = (unsigned char *)0x1;
        iVar55 = (**(code **)(*(int *)puVar52[-9] + 0x18))();
        local_820 = (unsigned char *)**(uint **)(iVar55 + 0x30);
        local_878 = (unsigned char *)
                    TParseContext__addConstVectorNode
                              (param_1,(unsigned char *)&local_820,puVar52[-0x1f]);
      }
    }
    else {
      iVar55 = (**(code **)(*(int *)puVar52[-9] + 0x44))();
      if (iVar55 == 2) {
        bVar40 = false;
        iVar55 = (**(code **)(*(int *)puVar52[-0x1f] + 0x58))();
        if ((iVar55 != 0) || (iVar55 = (**(code **)(*(int *)puVar52[-0x1f] + 0x50))(), iVar55 != 0))
        {
          (**(code **)(*(int *)puVar52[-0x1f] + 0x38))(&local_7e0);
          uVar59 = local_7bc << 0xd;
          uVar54 = local_7bc >> 0x13;
          iVar55 = (**(code **)(*(int *)puVar52[-9] + 0x18))();
          if (((int)(uVar59 | uVar54) >> 0x18 <= **(int **)(iVar55 + 0x30)) &&
             (iVar55 = (**(code **)(*(int *)puVar52[-0x1f] + 0x54))(), iVar55 == 0)) {
            bVar40 = true;
          }
          local_7e0 = (unsigned char *)(local_5c - 0x610c);
          if (bVar40) {
            iVar55 = (**(code **)(*(int *)puVar52[-9] + 0x18))();
            TParseContext__error
                      ((int)param_1,(char *)puVar52[-0x16],"","[",
                       "field selection out of range \'%d\'",**(undefined4 **)(iVar55 + 0x30));
            TParseContext__recover();
            goto LAB_97ba47fc;
          }
        }
        iVar55 = (**(code **)(*(int *)puVar52[-0x1f] + 0x54))();
        if (iVar55 != 0) {
          (**(code **)(*(int *)puVar52[-0x1f] + 0x38))(&local_7b0);
          iVar55 = local_5c + -0x610c;
          local_7b0 = iVar55;
          if (local_7ac == (char *)0x0) {
            (**(code **)(*(int *)puVar52[-0x1f] + 0x38))(&local_780);
            iVar6 = local_764;
            iVar62 = (**(code **)(*(int *)puVar52[-9] + 0x18))();
            bVar40 = **(int **)(iVar62 + 0x30) < iVar6;
            if (bVar40) {
              local_780 = iVar55;
              pTVar11 = (unsigned char *)(**(code **)(*(int *)puVar52[-0x1f] + 0x28))();
              iVar55 = (**(code **)(*(int *)puVar52[-0x1f] + 0x3c))();
              uVar37 = false;
            }
            else {
              local_780 = iVar55;
              iVar55 = (**(code **)(*(int *)puVar52[-9] + 0x18))();
              puVar22 = *(undefined4 **)(iVar55 + 0x30);
              pTVar11 = (unsigned char *)(**(code **)(*(int *)puVar52[-0x1f] + 0x28))((int *)puVar52[-0x1f])
              ;
              iVar55 = (**(code **)(*(int *)puVar52[-0x1f] + 0x3c))();
              uVar37 = (undefined1)*puVar22;
            }
            iVar55 = TParseContext__arraySetMaxSize
                               (param_1,pTVar11,iVar55,(bool)uVar37,(uint)!bVar40);
            if (iVar55 != 0) {
LAB_97ba475c:
              TParseContext__recover();
            }
          }
          else {
            iVar6 = (**(code **)(*(int *)puVar52[-9] + 0x18))();
            piVar63 = *(int **)(iVar6 + 0x30);
            (**(code **)(*(int *)puVar52[-0x1f] + 0x38))(&local_780);
            local_780 = iVar55;
            if (local_77c <= *piVar63) {
              iVar55 = (**(code **)(*(int *)puVar52[-9] + 0x18))();
              TParseContext__error
                        ((int)param_1,(char *)puVar52[-0x16],"","[",
                         "array index out of range \'%d\'",**(undefined4 **)(iVar55 + 0x30));
              goto LAB_97ba475c;
            }
          }
        }
        uVar19 = *(undefined4 *)param_1;
        uVar30 = 0x2d;
      }
      else {
        iVar55 = (**(code **)(*(int *)puVar52[-0x1f] + 0x54))();
        if (iVar55 != 0) {
          (**(code **)(*(int *)puVar52[-0x1f] + 0x38))(&local_820);
          local_820 = (unsigned char *)&PTR__TType_a7b7d640;
          if (local_81c == (unsigned char *)0x0) {
            TParseContext__error
                      ((int)param_1,(char *)puVar52[-0x16],"","[",
                       "array must be redeclared with a size before being indexed with a variable");
            TParseContext__recover();
          }
        }
        uVar19 = *(undefined4 *)param_1;
        uVar30 = 0x2e;
      }
      local_878 = (unsigned char *)
                  TIntermediate__addIndex(uVar19,uVar30,puVar52[-0x1f],puVar52[-9],puVar52[-0x16]);
    }
LAB_97ba47fc:
    psVar4 = local_878;
    if (local_878 == (unsigned char *)0x0) {
      uVar20 = GetGlobalPoolAllocator();
      pTVar11 = (unsigned char *)TPoolAllocator__allocate(uVar20);
      *(undefined4 *)pTVar11 = 0;
      local_850 = (unsigned char *)(local_5c - 0x610c);
      local_82c = (unsigned char *)((uint)local_82c & 0x1ff | 0x4080800);
      local_84c = psVar4;
      local_848 = psVar4;
      local_844 = psVar4;
      local_840 = psVar4;
      local_83c = psVar4;
      local_838 = psVar4;
      local_834 = psVar4;
      local_830 = psVar4;
      pcVar12 = *(unsigned char **)param_1;
      goto LAB_97ba7d0c;
    }
    iVar55 = (**(code **)(*(int *)puVar52[-0x1f] + 0x54))();
    in_cr0 = (iVar55 == 0) << 1;
    if (iVar55 == 0) {
      iVar55 = (**(code **)(*(int *)puVar52[-0x1f] + 0x50))();
      if (iVar55 != 0) {
        (**(code **)(*(int *)puVar52[-0x1f] + 0x38))(&local_850);
        psVar18 = (unsigned char *)(local_5c - 0x610c);
        local_850 = psVar18;
        if ((uint)local_82c >> 0x19 == 2) {
          uVar59 = (**(code **)(*(int *)puVar52[-0x1f] + 0x40))();
          uVar54 = (**(code **)(*(int *)puVar52[-0x1f] + 0x48))();
          local_7fc = (unsigned char *)
                      ((uVar54 & 0xff) << 0xb |
                      (uVar59 & 0x3f) << 0x13 | (uint)local_7fc & 0x1ff | 0x4000000);
          local_800 = (unsigned char *)0x0;
          goto LAB_97ba4bc0;
        }
      }
      psVar4 = (unsigned char *)(**(code **)(*(int *)puVar52[-0x1f] + 0x50))();
      in_cr0 = (psVar4 == (unsigned char *)0x0) << 1;
      if (psVar4 != (unsigned char *)0x0) {
        uVar59 = (**(code **)(*(int *)puVar52[-0x1f] + 0x40))();
        uVar54 = (**(code **)(*(int *)puVar52[-0x1f] + 0x48))();
        local_800 = (unsigned char *)0x0;
        psVar18 = (unsigned char *)(local_5c - 0x610c);
        local_7fc = (unsigned char *)
                    ((uVar54 & 0xff) << 0xb | (uVar59 & 0x3f) << 0x13 | (uint)local_7fc & 0x1ff);
        local_81c = (unsigned char *)0x0;
        local_818 = (unsigned char *)0x0;
        local_814 = (unsigned char *)0x0;
        local_810 = (unsigned char *)0x0;
        local_80c = (unsigned char *)0x0;
        local_808 = (unsigned char *)0x0;
        local_804 = (unsigned char *)0x0;
        local_820 = psVar18;
        (**(code **)(*(int *)local_878 + 0x34))(local_878,&local_820);
        psVar4 = local_878;
        local_820 = psVar18;
        psVar18 = local_7f0;
        psVar16 = local_750;
        break;
      }
      iVar55 = (**(code **)(*(int *)puVar52[-0x1f] + 0x58))();
      if (iVar55 != 0) {
        (**(code **)(*(int *)puVar52[-0x1f] + 0x38))(&local_820);
        psVar18 = (unsigned char *)(local_5c - 0x610c);
        local_820 = psVar18;
        if ((uint)local_7fc >> 0x19 == 2) {
          uVar59 = (**(code **)(*(int *)puVar52[-0x1f] + 0x40))();
          local_7cc = (uVar59 & 0x3f) << 0x13 | local_7cc & 0x9ff | 0x4000000 | 0x800;
          local_7f0 = psVar18;
          local_7ec = psVar4;
          local_7e8 = psVar4;
          local_7e4 = psVar4;
          local_7e0 = psVar4;
          local_7dc = psVar4;
          local_7d8 = psVar4;
          local_7d4 = psVar4;
          local_7d0 = psVar4;
          (**(code **)(*(int *)local_878 + 0x34))(local_878,&local_7f0);
          psVar4 = local_878;
          psVar16 = local_750;
          break;
        }
      }
      iVar55 = (**(code **)(*(int *)puVar52[-0x1f] + 0x58))();
      if (iVar55 == 0) {
        (**(code **)(*(int *)puVar52[-0x1f] + 0x38))(&local_7f0);
        (**(code **)(*(int *)local_878 + 0x34))(local_878,&local_7f0);
        psVar4 = local_878;
        psVar18 = (unsigned char *)(local_5c - 0x610c);
        psVar16 = local_750;
      }
      else {
        uVar59 = (**(code **)(*(int *)puVar52[-0x1f] + 0x40))();
        psVar18 = (unsigned char *)(local_5c - 0x610c);
        local_7cc = (uVar59 & 0x3f) << 0x13 | local_7cc & 0x9ff | 0x800;
        local_7ec = (unsigned char *)0x0;
        local_7e8 = (unsigned char *)0x0;
        local_7e4 = (unsigned char *)0x0;
        local_7e0 = (unsigned char *)0x0;
        local_7dc = (unsigned char *)0x0;
        local_7d8 = (unsigned char *)0x0;
        local_7d4 = (unsigned char *)0x0;
        local_7d0 = (unsigned char *)0x0;
        local_7f0 = psVar18;
        (**(code **)(*(int *)local_878 + 0x34))(local_878,&local_7f0);
        psVar4 = local_878;
        psVar16 = local_750;
      }
      break;
    }
    (**(code **)(*(int *)puVar52[-0x1f] + 0x38))(&local_850);
    psVar4 = local_848;
    psVar18 = (unsigned char *)(local_5c - 0x610c);
    local_850 = psVar18;
    if (local_848 == (unsigned char *)0x0) {
      uVar59 = (**(code **)(*(int *)puVar52[-0x1f] + 0x40))();
      uVar54 = (**(code **)(*(int *)puVar52[-0x1f] + 0x48))();
      uVar57 = (**(code **)(*(int *)puVar52[-0x1f] + 0x50))();
      local_7fc = (unsigned char *)
                  ((uVar57 & 1) << 10 |
                  (uVar54 & 0xff) << 0xb | (uVar59 & 0x3f) << 0x13 | (uint)local_7fc & 0x1ff);
      local_800 = psVar4;
LAB_97ba4bc0:
      local_820 = psVar18;
      local_81c = local_800;
      local_818 = local_800;
      local_814 = local_800;
      local_810 = local_800;
      local_80c = local_800;
      local_808 = local_800;
      local_804 = local_800;
      (**(code **)(*(int *)local_878 + 0x34))(local_878,&local_820);
      psVar4 = local_878;
      local_820 = psVar18;
      psVar18 = local_7f0;
      psVar16 = local_750;
      break;
    }
    local_64 = -0x5847c8b4;
    (**(code **)(*(int *)puVar52[-0x1f] + 0x38))(&local_7f0);
    psVar4 = local_7e8;
    (**(code **)(*(int *)puVar52[-0x1f] + 0x38))(local_750);
    std__string__string((unsigned char *)&local_7c0,local_740);
    std__string__string((unsigned char *)&local_7b0,(unsigned char *)&local_7c0);
    local_7fc = (unsigned char *)((uint)local_7fc & 0x9ff | 0x700800);
    local_800 = (unsigned char *)0x0;
    local_81c = (unsigned char *)0x0;
    local_818 = psVar4;
    local_814 = (unsigned char *)0x0;
    local_80c = (unsigned char *)0x0;
    local_804 = (unsigned char *)0x0;
    local_820 = psVar18;
    local_808 = (unsigned char *)TType__setStructSize((unsigned char *)&local_820);
    pcVar64 = local_7ac;
    local_7ac[*(int *)(local_7ac + -0xc)] = **(char **)(local_64 + -0x7cc4);
    uVar20 = GetGlobalPoolAllocator();
    psVar18 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    in_cr0 = (psVar18 == (unsigned char *)0x0) << 1;
    psVar4 = (unsigned char *)0x0;
    if (psVar18 != (unsigned char *)0x0) {
      local_720[0] = GetGlobalPoolAllocator();
      std__string__string(psVar18,pcVar64,(unsigned char *)local_720);
      psVar4 = psVar18;
    }
    piVar63 = (int *)(local_7ac + -4);
    local_710 = local_7b0;
    do {
      iVar55 = *piVar63;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,piVar63);
        *piVar63 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    local_810 = psVar4;
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_7ac + -0xc));
    }
    (**(code **)(*(int *)local_878 + 0x34))(local_878,(unsigned char *)&local_820);
    psVar18 = (unsigned char *)(local_5c - 0x610c);
    local_700 = local_7c0;
    piVar63 = (int *)(local_7bc - 4);
    do {
      iVar55 = *piVar63;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,piVar63);
        *piVar63 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    psVar4 = local_878;
    local_820 = psVar18;
    psVar16 = psVar18;
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_7bc - 0xc));
      psVar4 = local_878;
    }
    break;
  case 10:
    iVar55 = (**(code **)(*(int *)puVar52[-0x14] + 0x54))();
    if (iVar55 != 0) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52,"cannot apply dot operator to an array",".","");
      TParseContext__recover();
    }
    psVar4 = (unsigned char *)(**(code **)(*(int *)puVar52[-0x14] + 0x58))();
    in_cr0 = (psVar4 == (unsigned char *)0x0) << 1;
    if (psVar4 == (unsigned char *)0x0) {
      iVar55 = (**(code **)(*(int *)puVar52[-0x14] + 0x50))();
      if (iVar55 == 0) {
        iVar55 = (**(code **)(*(int *)puVar52[-0x14] + 0x40))();
        if (iVar55 != 0xe) {
          uVar59 = puVar52[1];
          iVar55 = *(int *)(uVar59 + 4);
          pcVar64 = " field selection requires structure, vector, or matrix on left hand side";
          goto LAB_97ba5784;
        }
        local_5c = -0x5847c8b4;
        (**(code **)(*(int *)puVar52[-0x14] + 0x38))(&local_850);
        psVar18 = local_848;
        local_850 = (unsigned char *)(local_5c - 0x610c);
        if (local_848 != (unsigned char *)0x0) {
          uVar59 = 0;
          goto LAB_97ba55dc;
        }
        pcVar33 = (char *)puVar52[-0xb];
        pcVar64 = "structure has no fields";
        pcVar35 = "Internal Error";
        goto LAB_97ba5548;
      }
      pTVar10 = (unsigned char *)(**(code **)(*(int *)puVar52[-0x14] + 0x48))();
      iVar55 = TParseContext__parseMatrixFields(param_1,puVar52[1],pTVar10,(int)&local_850);
      if (iVar55 == 0) {
        local_850 = psVar4;
        local_84c = psVar4;
        local_848 = psVar4;
        local_844 = psVar4;
        TParseContext__recover();
      }
      psVar18 = local_84c;
      if ((local_850 == (unsigned char *)0x0) && (local_84c == (unsigned char *)0x0)) {
        uVar20 = GetGlobalPoolAllocator();
        pTVar11 = (unsigned char *)TPoolAllocator__allocate(uVar20);
        local_5c = -0x5847c8b4;
        iVar55 = (**(code **)(*(int *)puVar52[-0x14] + 0x48))();
        psVar16 = (unsigned char *)(local_5c - 0x610c);
        *(unsigned char **)pTVar11 = local_848 + (int)local_844 * iVar55;
        local_81c = (unsigned char *)((uint)local_81c & 0x1ff | 0x4100800);
        local_83c = psVar18;
        local_838 = psVar18;
        local_834 = psVar18;
        local_830 = psVar18;
        local_82c = psVar18;
        local_828 = psVar18;
        local_824 = psVar18;
        local_820 = psVar18;
        local_840 = psVar16;
        uVar19 = TIntermediate__addConstantUnion(*(unsigned char **)param_1,pTVar11,(int)&local_840);
        local_840 = psVar16;
        local_878 = (unsigned char *)
                    TIntermediate__addIndex
                              (*(undefined4 *)param_1,0x2d,puVar52[-0x14],uVar19,puVar52[-0xb]);
        uVar59 = (**(code **)(*(int *)puVar52[-0x14] + 0x40))();
        local_81c = (unsigned char *)((uVar59 & 0x3f) << 0x13 | (uint)local_81c & 0x1ff | 0x800);
        local_83c = psVar18;
        local_838 = psVar18;
        local_834 = psVar18;
        local_830 = psVar18;
        local_82c = psVar18;
        local_828 = psVar18;
        local_824 = psVar18;
        local_820 = psVar18;
        local_840 = psVar16;
        (**(code **)(*(int *)local_878 + 0x34))(local_878,&local_840);
        psVar4 = local_878;
        local_840 = psVar16;
        psVar18 = local_7f0;
        psVar16 = local_750;
      }
      else {
        TParseContext__error
                  ((int)param_1,(char *)puVar52[-0xb]," non-scalar fields not implemented yet",".",
                   "");
        TParseContext__recover();
        uVar20 = GetGlobalPoolAllocator();
        pTVar11 = (unsigned char *)TPoolAllocator__allocate(uVar20);
        *(undefined4 *)pTVar11 = 0;
        local_81c = (unsigned char *)((uint)local_81c & 0x9ff | 0x4100800);
        local_840 = (unsigned char *)&PTR__TType_a7b7d640;
        local_83c = psVar4;
        local_838 = psVar4;
        local_834 = psVar4;
        local_830 = psVar4;
        local_82c = psVar4;
        local_828 = psVar4;
        local_824 = psVar4;
        local_820 = psVar4;
        uVar19 = TIntermediate__addConstantUnion(*(unsigned char **)param_1,pTVar11,(int)&local_840);
        local_840 = (unsigned char *)&PTR__TType_a7b7d640;
        local_878 = (unsigned char *)
                    TIntermediate__addIndex
                              (*(undefined4 *)param_1,0x2d,puVar52[-0x14],uVar19,puVar52[-0xb]);
        uVar59 = (**(code **)(*(int *)puVar52[-0x14] + 0x40))();
        uVar54 = (**(code **)(*(int *)puVar52[-0x14] + 0x48))();
        local_81c = (unsigned char *)
                    ((uVar54 & 0xff) << 0xb | (uVar59 & 0x3f) << 0x13 | (uint)local_81c & 0x1ff);
        local_840 = (unsigned char *)&PTR__TType_a7b7d640;
        local_83c = psVar4;
        local_838 = psVar4;
        local_834 = psVar4;
        local_830 = psVar4;
        local_82c = psVar4;
        local_828 = psVar4;
        local_824 = psVar4;
        local_820 = psVar4;
        (**(code **)(*(int *)local_878 + 0x34))(local_878,&local_840);
        local_840 = (unsigned char *)&PTR__TType_a7b7d640;
        psVar4 = local_878;
        psVar18 = local_7f0;
        psVar16 = local_750;
      }
      break;
    }
    pTVar9 = (unsigned char *)(**(code **)(*(int *)puVar52[-0x14] + 0x48))();
    psVar4 = (unsigned char *)TParseContext__parseVectorFields(param_1,puVar52[1],pTVar9,(int)&local_850);
    in_cr0 = (psVar4 == (unsigned char *)0x0) << 1;
    if (psVar4 == (unsigned char *)0x0) {
      local_840 = (unsigned char *)0x1;
      local_850 = psVar4;
      TParseContext__recover();
    }
    local_5c = -0x5847c8b4;
    (**(code **)(*(int *)puVar52[-0x14] + 0x38))(&local_830);
    psVar18 = (unsigned char *)(local_5c - 0x610c);
    local_830 = psVar18;
    if ((uint)local_80c >> 0x19 == 2) {
      local_878 = (unsigned char *)
                  TParseContext__addConstVectorNode
                            (param_1,(unsigned char *)&local_850,puVar52[-0x14]);
      if (local_878 == (unsigned char *)0x0) goto LAB_97ba5554;
      uVar59 = (**(code **)(*(int *)puVar52[-0x14] + 0x40))();
      local_7dc = (unsigned char *)
                  ((*(uint *)(*(int *)(puVar52[1] + 4) + -0xc) & 0xff) << 0xb |
                  (uVar59 & 0x3f) << 0x13 | (uint)local_7dc & 0x1ff | 0x4000000);
      pcVar44 = *(code **)(*(int *)local_878 + 0x34);
LAB_97ba50cc:
      local_7e0 = (unsigned char *)0x0;
      local_7e4 = (unsigned char *)0x0;
      local_7e8 = (unsigned char *)0x0;
      local_7ec = (unsigned char *)0x0;
      local_7f0 = (unsigned char *)0x0;
      local_7f4 = (unsigned char *)0x0;
      local_7f8 = (unsigned char *)0x0;
      local_7fc = (unsigned char *)0x0;
      local_800 = psVar18;
      (*pcVar44)(local_878,&local_800);
      psVar4 = local_878;
      local_800 = psVar18;
      psVar18 = local_7f0;
      psVar16 = local_750;
      break;
    }
    if (local_840 == (unsigned char *)0x1) {
      uVar20 = GetGlobalPoolAllocator();
      pTVar11 = (unsigned char *)TPoolAllocator__allocate(uVar20);
      *(unsigned char **)pTVar11 = local_850;
      local_7dc = (unsigned char *)((uint)local_7dc & 0x1ff | 0x4100800);
      local_7fc = (unsigned char *)0x0;
      local_7f8 = (unsigned char *)0x0;
      local_7f4 = (unsigned char *)0x0;
      local_7f0 = (unsigned char *)0x0;
      local_7ec = (unsigned char *)0x0;
      local_7e8 = (unsigned char *)0x0;
      local_7e4 = (unsigned char *)0x0;
      local_7e0 = (unsigned char *)0x0;
      local_800 = psVar18;
      uVar19 = TIntermediate__addConstantUnion(*(unsigned char **)param_1,pTVar11,(int)&local_800);
      local_800 = psVar18;
      local_878 = (unsigned char *)
                  TIntermediate__addIndex
                            (*(undefined4 *)param_1,0x2d,puVar52[-0x14],uVar19,puVar52[-0xb]);
      uVar59 = (**(code **)(*(int *)puVar52[-0x14] + 0x40))();
      local_7dc = (unsigned char *)((uVar59 & 0x3f) << 0x13 | (uint)local_7dc & 0x1ff | 0x800);
      pcVar44 = *(code **)(*(int *)local_878 + 0x34);
      goto LAB_97ba50cc;
    }
    std__string__string((unsigned char *)&local_800,(unsigned char *)puVar52[1]);
    uVar19 = TIntermediate__addSwizzle(*(unsigned char **)param_1,(int)&local_850);
    local_878 = (unsigned char *)
                TIntermediate__addIndex
                          (*(undefined4 *)param_1,0x30,puVar52[-0x14],uVar19,puVar52[-0xb]);
    iVar55 = *(int *)local_878;
    uVar59 = (**(code **)(*(int *)puVar52[-0x14] + 0x40))();
    local_7cc = (*(uint *)(local_7fc + -0xc) & 0xff) << 0xb |
                (uVar59 & 0x3f) << 0x13 | local_7cc & 0x1ff;
    local_7d0 = (unsigned char *)0x0;
    local_7ec = (unsigned char *)0x0;
    local_7e8 = (unsigned char *)0x0;
    local_7e4 = (unsigned char *)0x0;
    local_7e0 = (unsigned char *)0x0;
    local_7dc = (unsigned char *)0x0;
    local_7d8 = (unsigned char *)0x0;
    local_7d4 = (unsigned char *)0x0;
    local_7f0 = psVar18;
    (**(code **)(iVar55 + 0x34))(local_878,&local_7f0);
    psVar4 = local_7fc + -4;
    local_6f0 = local_800;
    paVar14 = (unsigned char *)(local_7fc + -0xc);
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    local_7f0 = psVar18;
    goto LAB_97ba869c;
  case 0xb:
    iVar55 = TParseContext__lValueErrorCheck((int)param_1,(char *)*puVar52,(unsigned char *)"++");
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    local_878 = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(undefined4 *)param_1,9,puVar52[-9],*puVar52,
                           *(undefined4 *)((int)param_1 + 4));
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString();
    TParseContext__unaryOpError(param_1,*puVar52,"++",&local_850);
    psVar4 = local_84c + -4;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
      local_6e0 = local_850;
    } while (!(bool)(in_cr0 >> 1 & 1));
    goto joined_r0x97ba58fc;
  case 0xc:
    iVar55 = TParseContext__lValueErrorCheck((int)param_1,(char *)*puVar52,(unsigned char *)"--");
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    local_878 = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(undefined4 *)param_1,10,puVar52[-9],*puVar52,
                           *(undefined4 *)((int)param_1 + 4));
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString();
    TParseContext__unaryOpError(param_1,*puVar52,"--",&local_850);
    psVar4 = local_84c + -4;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
      local_6d0 = local_850;
    } while (!(bool)(in_cr0 >> 1 & 1));
joined_r0x97ba58fc:
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_84c + -0xc));
    }
    TParseContext__recover();
switchD_97ba39c8_caseD_6:
    psVar4 = (unsigned char *)puVar52[-9];
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0xd:
    iVar55 = TParseContext__integerErrorCheck(param_1,(char *)puVar52[2]);
    goto LAB_97ba82e8;
  case 0xe:
    pbVar13 = (bool *)puVar52[4];
    iVar55 = *(int *)(pbVar13 + 0x4c);
    if (iVar55 != 0) {
      local_5c = -0x5847c8b4;
      local_830 = (unsigned char *)0x0;
      local_82c = (unsigned char *)((uint)local_82c & 0x9ff | 0x800);
      in_cr0 = (local_82c == (unsigned char *)0x0) << 1;
      local_850 = (unsigned char *)&PTR__TType_a7b7d640;
      local_84c = (unsigned char *)0x0;
      local_848 = (unsigned char *)0x0;
      local_844 = (unsigned char *)0x0;
      local_840 = (unsigned char *)0x0;
      local_83c = (unsigned char *)0x0;
      local_838 = (unsigned char *)0x0;
      local_834 = (unsigned char *)0x0;
      iVar6 = TParseContext__constructorErrorCheck
                        (param_1,*puVar52,puVar52[2],pbVar13,iVar55,&local_850);
      if (iVar6 == 0) {
        local_878 = (unsigned char *)
                    TParseContext__addConstructor
                              (param_1,puVar52[2],&local_850,iVar55,pbVar13,*puVar52);
      }
      else {
        local_878 = (unsigned char *)0x0;
      }
      if (local_878 == (unsigned char *)0x0) {
        TParseContext__recover();
        local_878 = (unsigned char *)
                    TIntermediate__setAggregateOperator(*(undefined4 *)param_1,0,iVar55,*puVar52);
      }
      (**(code **)(*(int *)local_878 + 0x34))(local_878,&local_850);
      local_850 = (unsigned char *)(local_5c - 0x610c);
      goto LAB_97ba5e28;
    }
    psVar4 = (unsigned char *)TParseContext__findFunction((int)param_1,(unsigned char *)*puVar52,pbVar13);
    in_cr0 = (psVar4 == (unsigned char *)0x0) << 1;
    if (psVar4 == (unsigned char *)0x0) {
      uVar20 = GetGlobalPoolAllocator();
      pTVar11 = (unsigned char *)TPoolAllocator__allocate(uVar20);
      *(undefined4 *)pTVar11 = 0;
      local_82c = (unsigned char *)((uint)local_82c & 0x1ff | 0x4080800);
      local_850 = (unsigned char *)&PTR__TType_a7b7d640;
      local_84c = psVar4;
      local_848 = psVar4;
      local_844 = psVar4;
      local_840 = psVar4;
      local_83c = psVar4;
      local_838 = psVar4;
      local_834 = psVar4;
      local_830 = psVar4;
      local_878 = (unsigned char *)
                  TIntermediate__addConstantUnion(*(unsigned char **)param_1,pTVar11,(int)&local_850);
      local_850 = (unsigned char *)&PTR__TType_a7b7d640;
      TParseContext__recover();
      goto LAB_97ba5e28;
    }
    iVar55 = *(int *)(psVar4 + 0x4c);
    if ((local_88 == 0) || (iVar55 == 0)) {
      local_878 = (unsigned char *)
                  TIntermediate__setAggregateOperator(*(undefined4 *)param_1,puVar52[2],2,*puVar52);
      (**(code **)(*(int *)local_878 + 0x34))(local_878,psVar4 + 0x1c);
      if (local_88 == 0) {
        piVar63 = (int *)(**(code **)(*(int *)local_878 + 0x1c))();
        (**(code **)(*piVar63 + 0x70))();
      }
      piVar63 = (int *)(**(code **)(*(int *)local_878 + 0x1c))();
      iVar55 = *piVar63;
      uVar19 = (**(code **)(*(int *)psVar4 + 8))(psVar4);
      (**(code **)(iVar55 + 0x68))(piVar63,uVar19);
      piVar63 = (int *)(**(code **)(*(int *)local_878 + 0x1c))();
      iVar55 = (**(code **)(*piVar63 + 0x78))();
      for (iVar6 = 0; iVar6 < *(int *)(psVar4 + 0x14) - *(int *)(psVar4 + 0x10) >> 3;
          iVar6 = iVar6 + 1) {
        iVar62 = (**(code **)(**(int **)(*(int *)(psVar4 + 0x10) + iVar6 * 8 + 4) + 0x24))();
        if (iVar62 - 10U < 2) {
          piVar63 = (int *)(**(code **)(*(int *)local_878 + 0x1c))();
          iVar8 = (**(code **)(*piVar63 + 100))();
          (**(code **)(**(int **)(*(int *)(iVar8 + 4) + iVar6 * 4) + 0x14))();
          pcVar64 = (char *)(*(code *)**(undefined4 **)local_878)();
          iVar8 = TParseContext__lValueErrorCheck((int)param_1,pcVar64,(unsigned char *)"assign");
          if (iVar8 != 0) {
            pcVar64 = (char *)(*(code *)**(undefined4 **)puVar52[2])();
            TParseContext__error
                      ((int)param_1,pcVar64,
                       "Constant value cannot be passed for \'out\' or \'inout\' parameters.",
                       "Error","");
            TParseContext__recover();
          }
        }
        piVar63 = *(int **)(iVar55 + 8);
        local_84 = iVar62;
        if (piVar63 == *(int **)(iVar55 + 0xc)) {
          std__vector_int_pool_allocator_int_____M_insert_aux(iVar55,piVar63,&local_84);
        }
        else {
          iVar8 = 0;
          if (piVar63 != (int *)0x0) {
            *piVar63 = iVar62;
            iVar8 = *(int *)(iVar55 + 8);
          }
          *(int *)(iVar55 + 8) = iVar8 + 4;
        }
      }
    }
    else {
      if (*(int *)(psVar4 + 0x14) - *(int *)(psVar4 + 0x10) >> 3 == 1) {
        local_878 = (unsigned char *)
                    TIntermediate__addUnaryMath
                              (*(undefined4 *)param_1,iVar55,puVar52[2],0,
                               *(undefined4 *)((int)param_1 + 4));
        if (local_878 != (unsigned char *)0x0) goto LAB_97ba5d80;
        local_64 = -0x5847c8b4;
        TType__getCompleteString();
        psVar4 = local_84c;
        local_84c[*(int *)(local_84c + -0xc)] = **(unsigned char **)(local_64 + -0x7cc4);
        pcVar64 = (char *)(*(code *)**(undefined4 **)puVar52[2])();
        TParseContext__error
                  ((int)param_1,pcVar64," wrong operand type","Internal Error",
                   "built in unary operator function.  Type: %s",psVar4);
        psVar4 = local_84c + -4;
        local_6c0 = local_850;
        do {
          iVar55 = *(int *)psVar4;
          if (in_RESERVE != '\0') {
            iVar58 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
            *(int *)psVar4 = iVar58;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
        if (iVar55 < 1) {
          std__string___Rep___M_destroy((unsigned char *)(local_84c + -0xc));
        }
        goto LAB_97bac050;
      }
      local_878 = (unsigned char *)
                  TIntermediate__setAggregateOperator
                            (*(undefined4 *)param_1,puVar52[2],iVar55,*puVar52);
    }
LAB_97ba5d80:
    (**(code **)(*(int *)local_878 + 0x34))(local_878,psVar4 + 0x1c);
LAB_97ba5e28:
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (pbVar13 != (bool *)0x0) {
      iVar55 = *(int *)pbVar13;
LAB_97ba86fc:
      (**(code **)(iVar55 + 4))(pbVar13);
      psVar4 = local_878;
      psVar18 = local_7f0;
      psVar16 = local_750;
    }
    break;
  case 0xf:
  case 0x10:
    _memcpy(&local_880,puVar52 + -0xb,0x2c);
    local_880 = *puVar52;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x11:
    local_870 = (unsigned char *)puVar52[-7];
    goto LAB_97ba5e64;
  case 0x12:
    local_870 = (unsigned char *)puVar52[4];
LAB_97ba5e64:
    psVar4 = (unsigned char *)0x0;
    break;
  case 0x13:
    local_840 = (unsigned char *)0x0;
    uVar20 = GetGlobalPoolAllocator();
    psVar4 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    (**(code **)(*(int *)puVar52[2] + 0x38))();
    local_850 = local_840;
    uVar59 = puVar52[-7];
    puVar27 = *(uint **)(uVar59 + 0x14);
    local_84c = psVar4;
    local_83c = psVar4;
    if (puVar27 == *(uint **)(uVar59 + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                (uVar59 + 0xc,*(undefined4 *)(uVar59 + 0x14),&local_850);
    }
    else {
      iVar55 = 0;
      if (puVar27 != (uint *)0x0) {
        puVar27[1] = (uint)psVar4;
        *puVar27 = (uint)local_840;
        iVar55 = *(int *)(uVar59 + 0x14);
      }
      *(int *)(uVar59 + 0x14) = iVar55 + 8;
    }
    psVar4 = local_84c;
    if (*(int *)(local_84c + 0x14) == 0) {
      uVar20 = GetGlobalPoolAllocator();
      psVar16 = (unsigned char *)TPoolAllocator__allocate(uVar20);
      in_cr0 = (psVar16 == (unsigned char *)0x0) << 1;
      psVar18 = (unsigned char *)0x0;
      if (psVar16 != (unsigned char *)0x0) {
        local_6b0[0] = GetGlobalPoolAllocator();
        std__string__string(psVar16,"",(unsigned char *)local_6b0);
        psVar18 = psVar16;
      }
      *(unsigned char **)(psVar4 + 0x14) = psVar18;
      ((int (*)())TType__buildMangledName)(psVar4);
      std__string__append(*(ulong *)(psVar4 + 0x14),'\x01');
    }
    std__operator_((unsigned char *)&local_840,(unsigned char *)(uVar59 + 0x44));
    std__string__assign((unsigned char *)(uVar59 + 0x44));
    psVar4 = local_83c + -4;
    local_6a0 = local_840;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    local_870 = (unsigned char *)puVar52[-7];
    psVar4 = (unsigned char *)puVar52[2];
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x14:
    local_840 = (unsigned char *)0x0;
    uVar20 = GetGlobalPoolAllocator();
    psVar4 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    (**(code **)(*(int *)puVar52[2] + 0x38))();
    local_850 = local_840;
    uVar59 = puVar52[-0x12];
    puVar27 = *(uint **)(uVar59 + 0x14);
    local_84c = psVar4;
    local_83c = psVar4;
    if (puVar27 == *(uint **)(uVar59 + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                (uVar59 + 0xc,*(undefined4 *)(uVar59 + 0x14),&local_850);
    }
    else {
      iVar55 = 0;
      if (puVar27 != (uint *)0x0) {
        puVar27[1] = (uint)psVar4;
        *puVar27 = (uint)local_840;
        iVar55 = *(int *)(uVar59 + 0x14);
      }
      *(int *)(uVar59 + 0x14) = iVar55 + 8;
    }
    psVar4 = local_84c;
    if (*(int *)(local_84c + 0x14) == 0) {
      uVar20 = GetGlobalPoolAllocator();
      psVar16 = (unsigned char *)TPoolAllocator__allocate(uVar20);
      in_cr0 = (psVar16 == (unsigned char *)0x0) << 1;
      psVar18 = (unsigned char *)0x0;
      if (psVar16 != (unsigned char *)0x0) {
        local_690[0] = GetGlobalPoolAllocator();
        std__string__string(psVar16,"",(unsigned char *)local_690);
        psVar18 = psVar16;
      }
      *(unsigned char **)(psVar4 + 0x14) = psVar18;
      ((int (*)())TType__buildMangledName)(psVar4);
      std__string__append(*(ulong *)(psVar4 + 0x14),'\x01');
    }
    std__operator_((unsigned char *)&local_840,(unsigned char *)(uVar59 + 0x44));
    std__string__assign((unsigned char *)(uVar59 + 0x44));
    psVar4 = local_83c + -4;
    local_680 = local_840;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    local_870 = (unsigned char *)puVar52[-0x12];
    pTVar23 = *(unsigned char **)param_1;
    pTVar28 = (unsigned char *)puVar52[-0x14];
    uVar59 = puVar52[2];
LAB_97ba97d8:
    psVar4 = (unsigned char *)TIntermediate__growAggregate(pTVar23,pTVar28,uVar59);
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x15:
    local_870 = (unsigned char *)puVar52[-7];
    break;
  case 0x16:
    if (puVar52[1] != 0x75) {
      uVar20 = GetGlobalPoolAllocator();
      psVar18 = (unsigned char *)TPoolAllocator__allocate(uVar20);
      uVar54 = puVar52[1];
      puVar7 = PTR_vtable_a7b7c0f4 + 8;
      *(int *)(psVar18 + 4) = 0;
      *(undefined **)psVar18 = puVar7;
      local_5c = -0x5847c8b4;
      local_640 = GetGlobalPoolAllocator();
      *(int *)(psVar18 + 0x18) = 0;
      *(int *)(psVar18 + 0x10) = 0;
      *(int *)(psVar18 + 0x14) = 0;
      *(int *)(psVar18 + 0x1c) = local_5c + -0x610c;
      *(int *)(psVar18 + 0xc) = local_640;
      iVar55 = DAT_a7b7ba84;
      *(int *)(psVar18 + 0x20) = 0;
      uVar59 = *(uint *)(psVar18 + 0x40) & 0x9ff | 0x800;
      in_cr0 = (uVar59 == 0) << 1;
      *(int *)(psVar18 + 0x24) = 0;
      *(uint *)(psVar18 + 0x40) = uVar59;
      piVar63 = (int *)(iVar55 + 8);
      *(int *)(psVar18 + 0x28) = 0;
      *(int *)(psVar18 + 0x2c) = 0;
      *(int *)(psVar18 + 0x30) = 0;
      *(int *)(psVar18 + 0x34) = 0;
      *(int *)(psVar18 + 0x38) = 0;
      *(int *)(psVar18 + 0x3c) = 0;
      do {
        if (in_RESERVE != '\0') {
          iVar6 = storeWordConditionalIndexed(*piVar63 + 1,0,piVar63);
          *piVar63 = iVar6;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1));
      local_630 = GetGlobalPoolAllocator();
      *(int *)(psVar18 + 0x48) = iVar55 + 0xc;
      *(int *)(psVar18 + 0x44) = local_630;
      *(uint *)(psVar18 + 0x4c) = uVar54;
      *(int *)(psVar18 + 0x50) = 0;
      psVar4 = local_878;
      local_870 = psVar18;
      psVar18 = local_7f0;
      psVar16 = local_750;
      break;
    }
    local_670[0] = GetGlobalPoolAllocator();
    std__string__string((unsigned char *)&local_850,"",(unsigned char *)local_670);
    uVar20 = GetGlobalPoolAllocator();
    psVar18 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    uVar60 = puVar52[9];
    uVar53 = puVar52[1];
    *(undefined **)psVar18 = PTR_vtable_a7b7c0f4 + 8;
    *(unsigned char **)(psVar18 + 4) = (unsigned char *)&local_850;
    local_660 = GetGlobalPoolAllocator();
    *(int *)(psVar18 + 0x18) = 0;
    *(int *)(psVar18 + 0x10) = 0;
    *(int *)(psVar18 + 0x14) = 0;
    local_5c = -0x5847c8b4;
    *(int *)(psVar18 + 0xc) = local_660;
    iVar38 = *(int *)(uVar60 + 8);
    iVar36 = *(int *)(uVar60 + 0xc);
    iVar34 = *(int *)(uVar60 + 0x10);
    iVar31 = *(int *)(uVar60 + 0x14);
    iVar8 = *(int *)(uVar60 + 0x18);
    iVar62 = *(int *)(uVar60 + 0x1c);
    iVar55 = *(int *)(uVar60 + 4);
    iVar6 = *(int *)(uVar60 + 0x20);
    *(undefined ***)(psVar18 + 0x1c) = &PTR__TType_a7b7d640;
    *(int *)(psVar18 + 0x20) = iVar55;
    *(int *)(psVar18 + 0x24) = iVar38;
    *(int *)(psVar18 + 0x28) = iVar36;
    *(int *)(psVar18 + 0x2c) = iVar34;
    *(int *)(psVar18 + 0x30) = iVar31;
    *(int *)(psVar18 + 0x34) = iVar8;
    *(int *)(psVar18 + 0x38) = iVar62;
    *(int *)(psVar18 + 0x3c) = iVar6;
    uVar3 = *(uint *)(psVar18 + 0x40);
    uVar54 = *(uint *)(uVar60 + 0x24) & 0xfe000000;
    *(uint *)(psVar18 + 0x40) = uVar54 | uVar3 & 0x1ffffff;
    uVar57 = (*(uint *)(uVar60 + 0x24) >> 0x13 & 0x3f) << 0x13;
    *(uint *)(psVar18 + 0x40) = uVar57 | uVar54 | uVar3 & 0x7ffff;
    uVar59 = *(uint *)(uVar60 + 0x24) & 0x7f800;
    *(uint *)(psVar18 + 0x40) = uVar59 | uVar57 | uVar54 | uVar3 & 0x7ff;
    uVar61 = (*(uint *)(uVar60 + 0x24) >> 10 & 1) << 10;
    *(uint *)(psVar18 + 0x40) = uVar61 | uVar59 | uVar57 | uVar54 | uVar3 & 0x3ff;
    *(uint *)(psVar18 + 0x40) =
         (*(uint *)(uVar60 + 0x24) >> 9 & 1) << 9 |
         uVar61 | uVar59 | uVar57 | uVar54 | uVar3 & 0x1ff;
    std__string__string(psVar18 + 0x44,(unsigned char *)&local_850);
    std__string__append((ulong)(psVar18 + 0x44),'\x01');
    *(uint *)(psVar18 + 0x4c) = uVar53;
    *(int *)(psVar18 + 0x50) = 0;
    psVar4 = local_84c + -4;
    local_650 = local_850;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    local_870 = psVar18;
    goto LAB_97ba869c;
  case 0x17:
    iVar55 = TParseContext__reservedErrorCheck((int)param_1,(unsigned char *)*puVar52);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    local_82c = (unsigned char *)((uint)local_82c & 0x9ff | 0x800);
    in_cr0 = (local_82c == (unsigned char *)0x0) << 1;
    local_850 = (unsigned char *)&PTR__TType_a7b7d640;
    local_84c = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_838 = (unsigned char *)0x0;
    local_834 = (unsigned char *)0x0;
    local_830 = (unsigned char *)0x0;
    uVar20 = GetGlobalPoolAllocator();
    psVar18 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    psVar4 = (unsigned char *)puVar52[1];
    *(undefined **)psVar18 = PTR_vtable_a7b7c0f4 + 8;
    *(unsigned char **)(psVar18 + 4) = psVar4;
    local_620 = GetGlobalPoolAllocator();
    *(int *)(psVar18 + 0x18) = 0;
    *(int *)(psVar18 + 0x10) = 0;
    *(int *)(psVar18 + 0x14) = 0;
    *(int *)(psVar18 + 0xc) = local_620;
    *(unsigned char **)(psVar18 + 0x20) = local_84c;
    *(unsigned char **)(psVar18 + 0x24) = local_848;
    *(unsigned char **)(psVar18 + 0x28) = local_844;
    *(unsigned char **)(psVar18 + 0x2c) = local_840;
    *(unsigned char **)(psVar18 + 0x30) = local_83c;
    *(unsigned char **)(psVar18 + 0x34) = local_838;
    *(undefined ***)(psVar18 + 0x1c) = &PTR__TType_a7b7d640;
    *(unsigned char **)(psVar18 + 0x38) = local_834;
    *(unsigned char **)(psVar18 + 0x3c) = local_830;
    uVar3 = *(uint *)(psVar18 + 0x40);
    uVar54 = (uint)local_82c & 0xfe000000;
    *(uint *)(psVar18 + 0x40) = uVar54 | uVar3 & 0x1ffffff;
    uVar57 = ((uint)local_82c >> 0x13 & 0x3f) << 0x13;
    *(uint *)(psVar18 + 0x40) = uVar57 | uVar54 | uVar3 & 0x7ffff;
    uVar59 = (uint)local_82c & 0x7f800;
    *(uint *)(psVar18 + 0x40) = uVar59 | uVar57 | uVar54 | uVar3 & 0x7ff;
    uVar61 = ((uint)local_82c >> 10 & 1) << 10;
    *(uint *)(psVar18 + 0x40) = uVar61 | uVar59 | uVar57 | uVar54 | uVar3 & 0x3ff;
    *(uint *)(psVar18 + 0x40) =
         ((uint)local_82c >> 9 & 1) << 9 | uVar61 | uVar59 | uVar57 | uVar54 | uVar3 & 0x1ff;
    std__string__string(psVar18 + 0x44,psVar4);
    std__string__append((ulong)(psVar18 + 0x44),'\x01');
    *(int *)(psVar18 + 0x50) = 0;
    *(int *)(psVar18 + 0x4c) = 0;
    psVar4 = local_878;
    local_870 = psVar18;
    local_850 = (unsigned char *)&PTR__TType_a7b7d640;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x18:
    local_880 = *puVar52;
    local_87c = 0x68;
    break;
  case 0x19:
    local_880 = *puVar52;
    local_87c = 0x66;
    break;
  case 0x1a:
    local_880 = *puVar52;
    local_87c = 0x67;
    break;
  case 0x1b:
    local_880 = *puVar52;
    local_87c = 0x69;
    break;
  case 0x1c:
    local_880 = *puVar52;
    local_87c = 0x6a;
    break;
  case 0x1d:
    local_880 = *puVar52;
    local_87c = 0x6b;
    break;
  case 0x1e:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ","bvec2"
                 ,"","");
      TParseContext__recover();
    }
    local_880 = *puVar52;
    local_87c = 0x6c;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x1f:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ","bvec3"
                 ,"","");
      TParseContext__recover();
    }
    local_880 = *puVar52;
    local_87c = 0x6d;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x20:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ","bvec4"
                 ,"","");
      TParseContext__recover();
    }
    local_880 = *puVar52;
    local_87c = 0x6e;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x21:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ","ivec2"
                 ,"","");
      TParseContext__recover();
    }
    local_880 = *puVar52;
    local_87c = 0x6f;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x22:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ","ivec3"
                 ,"","");
      TParseContext__recover();
    }
    local_880 = *puVar52;
    local_87c = 0x70;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x23:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ","ivec4"
                 ,"","");
      TParseContext__recover();
    }
    local_880 = *puVar52;
    local_87c = 0x71;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x24:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ","mat2",
                 "","");
      TParseContext__recover();
    }
    local_880 = *puVar52;
    local_87c = 0x72;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x25:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ","mat3",
                 "","");
      TParseContext__recover();
    }
    local_880 = *puVar52;
    local_87c = 0x73;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x26:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ","mat4",
                 "","");
      TParseContext__recover();
    }
    local_880 = *puVar52;
    local_87c = 0x74;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x27:
    local_85c = (unsigned char *)(puVar52[2] + 0xc);
    local_830 = (unsigned char *)0xe;
    local_824 = (unsigned char *)0x0;
    local_820 = (unsigned char *)0x0;
    local_86c = (unsigned char *)
                (uint)((uint)((*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4) >> 2)
                      < 4);
    local_828 = (unsigned char *)0x1;
    local_858 = (unsigned char *)*puVar52;
    local_860 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_864 = (unsigned char *)0x0;
    local_87c = 0x75;
    local_870 = (unsigned char *)0xe;
    local_868 = (unsigned char *)0x1;
    local_850 = (unsigned char *)0xe;
    local_848 = (unsigned char *)0x1;
    local_880 = *puVar52;
    local_84c = local_86c;
    local_83c = local_85c;
    local_838 = local_858;
    local_82c = local_86c;
    local_81c = local_85c;
    local_818 = local_858;
    break;
  case 0x29:
    iVar55 = TParseContext__lValueErrorCheck
                       ((int)param_1,(char *)puVar52[-0xb],(unsigned char *)"++");
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    local_878 = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(undefined4 *)param_1,0xb,puVar52[2],puVar52[-0xb],
                           *(undefined4 *)((int)param_1 + 4));
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString();
    TParseContext__unaryOpError(param_1,puVar52[-0xb],"++",&local_850);
    psVar4 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_610 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba82d4;
  case 0x2a:
    iVar55 = TParseContext__lValueErrorCheck
                       ((int)param_1,(char *)puVar52[-0xb],(unsigned char *)"--");
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    local_878 = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(undefined4 *)param_1,0xc,puVar52[2],puVar52[-0xb],
                           *(undefined4 *)((int)param_1 + 4));
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString();
    TParseContext__unaryOpError(param_1,puVar52[-0xb],"--",&local_850);
    psVar4 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_600 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) goto LAB_97ba69a8;
    goto LAB_97ba82f0;
  case 0x2b:
    if (puVar52[-10] == 0) goto switchD_97ba39c8_caseD_2;
    local_878 = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(undefined4 *)param_1,puVar52[-10],puVar52[2],puVar52[-0xb],
                           *(undefined4 *)((int)param_1 + 4));
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    uVar59 = puVar52[-10];
    pcVar64 = "";
    if (uVar59 == 6) {
      pcVar64 = "!";
    }
    else if ((int)uVar59 < 7) {
      if (uVar59 == 5) {
        pcVar64 = "-";
      }
    }
    else if (uVar59 == 8) {
      pcVar64 = "~";
    }
    TType__getCompleteString();
    TParseContext__unaryOpError(param_1,puVar52[-0xb],pcVar64,&local_850);
    psVar4 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_5f0 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba82d4;
  case 0x2c:
    local_880 = *puVar52;
    local_87c = 0;
    break;
  case 0x2d:
    local_880 = *puVar52;
    local_87c = 5;
    break;
  case 0x2e:
    local_880 = *puVar52;
    local_87c = 6;
    break;
  case 0x2f:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error((int)param_1,(char *)*puVar52," reserved for future use ","~","","");
      TParseContext__recover();
    }
    local_880 = *puVar52;
    local_87c = 8;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x31:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)puVar52[-0xb]," supported in vertex/fragment shaders only ",
                 "*","","");
      TParseContext__recover();
    }
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(undefined4 *)param_1,0x15,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                           *(undefined4 *)((int)param_1 + 4));
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],"*",&local_840,&local_850);
    psVar4 = local_83c + -4;
    local_5e0 = local_840;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar4 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_5d0 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba7a00;
  case 0x32:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)puVar52[-0xb]," supported in vertex/fragment shaders only ",
                 "/","","");
      TParseContext__recover();
    }
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(undefined4 *)param_1,0x16,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                           *(undefined4 *)((int)param_1 + 4));
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],"/",&local_840,&local_850);
    psVar4 = local_83c + -4;
    local_5c0 = local_840;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar4 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_5b0 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba7a00;
  case 0x33:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error((int)param_1,(char *)puVar52[-0xb]," reserved for future use ","%","","")
      ;
      TParseContext__recover();
    }
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(undefined4 *)param_1,0x17,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                           *(undefined4 *)((int)param_1 + 4));
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],"%",&local_840,&local_850);
    psVar4 = local_83c + -4;
    local_5a0 = local_840;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar4 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_590 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba7a00;
  case 0x35:
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(undefined4 *)param_1,0x13,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                           *(undefined4 *)((int)param_1 + 4));
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],"+",&local_840,&local_850);
    psVar4 = local_83c + -4;
    local_580 = local_840;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar4 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_570 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba7a00;
  case 0x36:
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(undefined4 *)param_1,0x14,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                           *(undefined4 *)((int)param_1 + 4));
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],"-",&local_840,&local_850);
    psVar4 = local_83c + -4;
    local_560 = local_840;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar4 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_550 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba7a00;
  case 0x38:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,(char *)puVar52[-0xb]," reserved for future use ","<<","","");
      TParseContext__recover();
    }
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(undefined4 *)param_1,0x19,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                           *(undefined4 *)((int)param_1 + 4));
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],"<<",&local_840,&local_850);
    psVar4 = local_83c + -4;
    local_540 = local_840;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar4 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_530 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba7a00;
  case 0x39:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,(char *)puVar52[-0xb]," reserved for future use ",">>","","");
      TParseContext__recover();
    }
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(undefined4 *)param_1,0x18,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                           *(undefined4 *)((int)param_1 + 4));
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],">>",&local_840,&local_850);
    psVar4 = local_83c + -4;
    local_520 = local_840;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar4 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_510 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba7a00;
  case 0x3b:
    psVar4 = (unsigned char *)
             TIntermediate__addBinaryMath
                       (*(undefined4 *)param_1,0x21,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                        *(undefined4 *)((int)param_1 + 4));
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (psVar4 != (unsigned char *)0x0) break;
    local_878 = psVar4;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],"<",&local_840,&local_850);
    psVar18 = local_83c + -4;
    local_500 = local_840;
    do {
      iVar55 = *(int *)psVar18;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar18);
        *(int *)psVar18 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar18 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_4f0 = local_850;
    do {
      iVar55 = *(int *)psVar18;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar18);
        *(int *)psVar18 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba7bac;
  case 0x3c:
    psVar4 = (unsigned char *)
             TIntermediate__addBinaryMath
                       (*(undefined4 *)param_1,0x22,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                        *(undefined4 *)((int)param_1 + 4));
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (psVar4 != (unsigned char *)0x0) break;
    local_878 = psVar4;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],">",&local_840,&local_850);
    psVar18 = local_83c + -4;
    local_4e0 = local_840;
    do {
      iVar55 = *(int *)psVar18;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar18);
        *(int *)psVar18 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar18 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_4d0 = local_850;
    do {
      iVar55 = *(int *)psVar18;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar18);
        *(int *)psVar18 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba7bac;
  case 0x3d:
    psVar4 = (unsigned char *)
             TIntermediate__addBinaryMath
                       (*(undefined4 *)param_1,0x23,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                        *(undefined4 *)((int)param_1 + 4));
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (psVar4 != (unsigned char *)0x0) break;
    local_878 = psVar4;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],"<=",&local_840,&local_850);
    psVar18 = local_83c + -4;
    local_4c0 = local_840;
    do {
      iVar55 = *(int *)psVar18;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar18);
        *(int *)psVar18 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar18 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_4b0 = local_850;
    do {
      iVar55 = *(int *)psVar18;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar18);
        *(int *)psVar18 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba7bac;
  case 0x3e:
    psVar4 = (unsigned char *)
             TIntermediate__addBinaryMath
                       (*(undefined4 *)param_1,0x24,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                        *(undefined4 *)((int)param_1 + 4));
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (psVar4 != (unsigned char *)0x0) break;
    local_878 = psVar4;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],">=",&local_840,&local_850);
    psVar18 = local_83c + -4;
    local_4a0 = local_840;
    do {
      iVar55 = *(int *)psVar18;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar18);
        *(int *)psVar18 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar18 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_490 = local_850;
    do {
      iVar55 = *(int *)psVar18;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar18);
        *(int *)psVar18 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba7bac;
  case 0x40:
    psVar4 = (unsigned char *)
             TIntermediate__addBinaryMath
                       (*(undefined4 *)param_1,0x1d,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                        *(undefined4 *)((int)param_1 + 4));
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (psVar4 != (unsigned char *)0x0) break;
    local_878 = psVar4;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],"==",&local_840,&local_850);
    psVar18 = local_83c + -4;
    local_480 = local_840;
    do {
      iVar55 = *(int *)psVar18;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar18);
        *(int *)psVar18 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar18 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_470 = local_850;
    do {
      iVar55 = *(int *)psVar18;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar18);
        *(int *)psVar18 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba7bac;
  case 0x41:
    psVar4 = (unsigned char *)
             TIntermediate__addBinaryMath
                       (*(undefined4 *)param_1,0x1e,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                        *(undefined4 *)((int)param_1 + 4));
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (psVar4 != (unsigned char *)0x0) break;
    local_878 = psVar4;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],"!=",&local_840,&local_850);
    psVar18 = local_83c + -4;
    local_460 = local_840;
    do {
      iVar55 = *(int *)psVar18;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar18);
        *(int *)psVar18 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar18 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_450 = local_850;
    do {
      iVar55 = *(int *)psVar18;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar18);
        *(int *)psVar18 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba7bac;
  case 0x43:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error((int)param_1,(char *)puVar52[-0xb]," reserved for future use ","&","","")
      ;
      TParseContext__recover();
    }
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(undefined4 *)param_1,0x1a,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                           *(undefined4 *)((int)param_1 + 4));
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],"&",&local_840,&local_850);
    psVar4 = local_83c + -4;
    local_440 = local_840;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar4 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_430 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba7a00;
  case 0x45:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error((int)param_1,(char *)puVar52[-0xb]," reserved for future use ","^","","")
      ;
      TParseContext__recover();
    }
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(undefined4 *)param_1,0x1c,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                           *(undefined4 *)((int)param_1 + 4));
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],"^",&local_840,&local_850);
    psVar4 = local_83c + -4;
    local_420 = local_840;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar4 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_410 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba7a00;
  case 0x47:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error((int)param_1,(char *)puVar52[-0xb]," reserved for future use ","|","","")
      ;
      TParseContext__recover();
    }
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(undefined4 *)param_1,0x1b,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                           *(undefined4 *)((int)param_1 + 4));
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],"|",&local_840,&local_850);
    psVar4 = local_83c + -4;
    local_400 = local_840;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar4 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_3f0 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
LAB_97ba7a00:
    if (!bVar40) {
LAB_97ba7f84:
      std__string___Rep___M_destroy(paVar14);
    }
LAB_97ba5554:
    TParseContext__recover();
    psVar4 = (unsigned char *)puVar52[-0x14];
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x49:
    psVar4 = (unsigned char *)
             TIntermediate__addBinaryMath
                       (*(undefined4 *)param_1,0x2c,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                        *(undefined4 *)((int)param_1 + 4));
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (psVar4 != (unsigned char *)0x0) break;
    local_878 = psVar4;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],"&&",&local_840,&local_850);
    psVar18 = local_83c + -4;
    local_3e0 = local_840;
    do {
      iVar55 = *(int *)psVar18;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar18);
        *(int *)psVar18 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar18 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_3d0 = local_850;
    do {
      iVar55 = *(int *)psVar18;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar18);
        *(int *)psVar18 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba7bac;
  case 0x4b:
    psVar4 = (unsigned char *)
             TIntermediate__addBinaryMath
                       (*(undefined4 *)param_1,0x2b,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                        *(undefined4 *)((int)param_1 + 4));
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (psVar4 != (unsigned char *)0x0) break;
    local_878 = psVar4;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],"^^",&local_840,&local_850);
    psVar18 = local_83c + -4;
    local_3c0 = local_840;
    do {
      iVar55 = *(int *)psVar18;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar18);
        *(int *)psVar18 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar18 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_3b0 = local_850;
    do {
      iVar55 = *(int *)psVar18;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar18);
        *(int *)psVar18 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
LAB_97ba7bac:
    if (!bVar40) {
LAB_97ba7c88:
      std__string___Rep___M_destroy(paVar14);
    }
LAB_97ba7c8c:
    TParseContext__recover();
    uVar20 = GetGlobalPoolAllocator();
    pTVar11 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    *(unsigned char **)pTVar11 = psVar4;
    local_82c = (unsigned char *)
                (((uint)psVar4 & 1) << 9 |
                ((uint)psVar4 & 1) << 10 | (uint)local_82c & 0x1801ff | 0x4180800);
    local_850 = (unsigned char *)&PTR__TType_a7b7d640;
    pcVar12 = *(unsigned char **)param_1;
    local_84c = psVar4;
    local_848 = psVar4;
    local_844 = psVar4;
    local_840 = psVar4;
    local_83c = psVar4;
    local_838 = psVar4;
    local_834 = psVar4;
    local_830 = psVar4;
LAB_97ba7d0c:
    psVar18 = local_850;
    psVar4 = (unsigned char *)TIntermediate__addConstantUnion(pcVar12,pTVar11,(int)&local_850);
    local_850 = psVar18;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x4d:
    psVar4 = (unsigned char *)
             TIntermediate__addBinaryMath
                       (*(undefined4 *)param_1,0x2a,puVar52[-0x14],puVar52[2],puVar52[-0xb],
                        *(undefined4 *)((int)param_1 + 4));
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (psVar4 != (unsigned char *)0x0) break;
    local_878 = psVar4;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],"||",&local_840,&local_850);
    psVar18 = local_83c + -4;
    local_3a0 = local_840;
    do {
      iVar55 = *(int *)psVar18;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar18);
        *(int *)psVar18 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar18 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_390 = local_850;
    do {
      iVar55 = *(int *)psVar18;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar18);
        *(int *)psVar18 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) goto LAB_97ba7c88;
    goto LAB_97ba7c8c;
  case 0x4f:
    iVar55 = TParseContext__boolErrorCheck((int)param_1,(unsigned char *)puVar52[-0x21]);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    local_878 = (unsigned char *)
                TIntermediate__addSelection
                          (*(unsigned char **)param_1,(unsigned char *)puVar52[-0x2a],
                           (unsigned char *)puVar52[-0x14],puVar52[2]);
    (**(code **)(*(int *)puVar52[-0x14] + 0x38))(&local_850);
    (**(code **)(*(int *)puVar52[2] + 0x38))(&local_820);
    bVar40 = false;
    if ((((uint)local_82c & 0x1fffe00) == ((uint)local_7fc & 0x1fffe00)) && (local_848 == local_818)
       ) {
      bVar40 = true;
    }
    local_5c = -0x5847c8b4;
    local_850 = (unsigned char *)&PTR__TType_a7b7d640;
    local_820 = (unsigned char *)&PTR__TType_a7b7d640;
    if (!bVar40) {
      local_878 = (unsigned char *)0x0;
    }
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0x21],":",&local_840,&local_850);
    psVar4 = local_83c + -4;
    local_380 = local_840;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar4 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_370 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
    goto LAB_97ba82d4;
  case 0x51:
    iVar55 = TParseContext__lValueErrorCheck
                       ((int)param_1,(char *)puVar52[-0xb],(unsigned char *)"assign");
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    local_878 = (unsigned char *)
                TIntermediate__addAssign
                          (*(undefined4 *)param_1,puVar52[-10],puVar52[-0x14],puVar52[2],
                           puVar52[-0xb]);
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__assignError(param_1,puVar52[-0xb],"assign",&local_840,&local_850);
    psVar4 = local_83c + -4;
    local_360 = local_840;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar4 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_350 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (0 < iVar55) goto LAB_97ba5554;
    goto LAB_97ba7f84;
  case 0x52:
    local_880 = *puVar52;
    local_87c = 0x76;
    break;
  case 0x53:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ","*=",""
                 ,"");
      TParseContext__recover();
    }
    local_880 = *puVar52;
    local_87c = 0x79;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x54:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ","/=",""
                 ,"");
      TParseContext__recover();
    }
    local_880 = *puVar52;
    local_87c = 0x7e;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x55:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error((int)param_1,(char *)*puVar52," reserved for future use ","%=","","");
      TParseContext__recover();
    }
    local_880 = *puVar52;
    local_87c = 0x7f;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x56:
    local_880 = *puVar52;
    local_87c = 0x77;
    break;
  case 0x57:
    local_880 = *puVar52;
    local_87c = 0x78;
    break;
  case 0x58:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error((int)param_1,(char *)*puVar52," reserved for future use ","<<=","","");
      TParseContext__recover();
    }
    local_880 = *puVar52;
    local_87c = 0x83;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x59:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error((int)param_1,(char *)*puVar52," reserved for future use ","<<=","","");
      TParseContext__recover();
    }
    local_880 = *puVar52;
    local_87c = 0x84;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x5a:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error((int)param_1,(char *)*puVar52," reserved for future use ","&=","","");
      TParseContext__recover();
    }
    local_880 = *puVar52;
    local_87c = 0x80;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x5b:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error((int)param_1,(char *)*puVar52," reserved for future use ","^=","","");
      TParseContext__recover();
    }
    local_880 = *puVar52;
    local_87c = 0x82;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x5c:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error((int)param_1,(char *)*puVar52," reserved for future use ","|=","","");
      TParseContext__recover();
    }
    local_880 = *puVar52;
    local_87c = 0x81;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x5e:
    local_878 = (unsigned char *)
                TIntermediate__addComma
                          (*(unsigned char **)param_1,(unsigned char *)puVar52[-0x14],puVar52[2]);
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString();
    TType__getCompleteString();
    TParseContext__binaryOpError(param_1,puVar52[-0xb],",",&local_840,&local_850);
    psVar4 = local_83c + -4;
    local_340 = local_840;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar4 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_330 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
LAB_97ba82d4:
    if (!bVar40) {
LAB_97ba69a8:
      std__string___Rep___M_destroy(paVar14);
    }
LAB_97ba82f0:
    TParseContext__recover();
switchD_97ba39c8_caseD_2:
    psVar4 = (unsigned char *)puVar52[2];
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x5f:
    iVar55 = TParseContext__constErrorCheck(param_1);
LAB_97ba82e8:
    if (iVar55 == 0) goto switchD_97ba39c8_caseD_2;
    goto LAB_97ba82f0;
  case 0x60:
  case 0xb0:
  case 0xb6:
  case 0xba:
  case 0xca:
    goto switchD_97ba39c8_caseD_60;
  case 0x61:
  case 0xb7:
    piVar63 = (int *)puVar52[-9];
    psVar4 = (unsigned char *)0x0;
    if (piVar63 != (int *)0x0) {
      (**(code **)(*piVar63 + 0x60))(piVar63,1);
      psVar4 = (unsigned char *)puVar52[-9];
      psVar18 = local_7f0;
      psVar16 = local_750;
    }
    break;
  case 0x62:
    piVar63 = *(int **)((int)param_1 + 4);
    (**(code **)(*(int *)puVar52[-7] + 8))();
    iVar55 = *piVar63;
    iVar6 = (piVar63[1] - iVar55 >> 2) + -1;
    goto LAB_97ba8338;
  case 99:
  case 100:
  case 0xa0:
    local_870 = (unsigned char *)puVar52[4];
    break;
  case 0x65:
    local_870 = (unsigned char *)puVar52[-7];
    iVar55 = (**(code **)(*(int *)puVar52[5] + 0x20))();
    if (iVar55 == 0) {
LAB_97ba86ec:
      pbVar13 = (bool *)puVar52[5];
      psVar4 = local_878;
      psVar18 = local_7f0;
      psVar16 = local_750;
      if (pbVar13 == (bool *)0x0) break;
      iVar55 = *(int *)pbVar13;
      goto LAB_97ba86fc;
    }
    uVar59 = puVar52[-7];
    puVar27 = *(uint **)(uVar59 + 0x14);
    if (puVar27 == *(uint **)(uVar59 + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                (uVar59 + 0xc,*(undefined4 *)(uVar59 + 0x14),puVar52 + 4);
    }
    else {
      iVar55 = 0;
      if (puVar27 != (uint *)0x0) {
        uVar54 = puVar52[5];
        *puVar27 = puVar52[4];
        puVar27[1] = uVar54;
        iVar55 = *(int *)(uVar59 + 0x14);
      }
      *(int *)(uVar59 + 0x14) = iVar55 + 8;
    }
    psVar4 = (unsigned char *)puVar52[5];
    if (*(int *)(psVar4 + 0x14) == 0) {
      uVar20 = GetGlobalPoolAllocator();
      psVar16 = (unsigned char *)TPoolAllocator__allocate(uVar20);
      in_cr0 = (psVar16 == (unsigned char *)0x0) << 1;
      psVar18 = (unsigned char *)0x0;
      if (psVar16 != (unsigned char *)0x0) {
        local_2f0[0] = GetGlobalPoolAllocator();
        std__string__string(psVar16,"",(unsigned char *)local_2f0);
        psVar18 = psVar16;
      }
      *(unsigned char **)(psVar4 + 0x14) = psVar18;
      ((int (*)())TType__buildMangledName)(psVar4);
      std__string__append(*(ulong *)(psVar4 + 0x14),'\x01');
    }
    std__operator_((unsigned char *)&local_850,(unsigned char *)(uVar59 + 0x44));
    std__string__assign((unsigned char *)(uVar59 + 0x44));
    psVar4 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_2e0 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar40 = 0 < iVar55;
LAB_97ba869c:
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (!bVar40) {
LAB_97ba8824:
      std__string___Rep___M_destroy(paVar14);
      psVar4 = local_878;
      psVar18 = local_7f0;
      psVar16 = local_750;
    }
    break;
  case 0x66:
    iVar55 = (**(code **)(*(int *)puVar52[5] + 0x20))();
    if (iVar55 == 0) {
      TParseContext__error
                ((int)param_1,(char *)puVar52[-0xb],
                 "cannot be an argument type except for \'(void)\'","void","");
      TParseContext__recover();
      goto LAB_97ba86ec;
    }
    local_870 = (unsigned char *)puVar52[-0x12];
    uVar59 = puVar52[-0x12];
    puVar27 = *(uint **)(uVar59 + 0x14);
    if (puVar27 == *(uint **)(uVar59 + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                (uVar59 + 0xc,*(undefined4 *)(uVar59 + 0x14),puVar52 + 4);
    }
    else {
      iVar55 = 0;
      if (puVar27 != (uint *)0x0) {
        uVar54 = puVar52[5];
        *puVar27 = puVar52[4];
        puVar27[1] = uVar54;
        iVar55 = *(int *)(uVar59 + 0x14);
      }
      *(int *)(uVar59 + 0x14) = iVar55 + 8;
    }
    psVar4 = (unsigned char *)puVar52[5];
    if (*(int *)(psVar4 + 0x14) == 0) {
      uVar20 = GetGlobalPoolAllocator();
      psVar16 = (unsigned char *)TPoolAllocator__allocate(uVar20);
      in_cr0 = (psVar16 == (unsigned char *)0x0) << 1;
      psVar18 = (unsigned char *)0x0;
      if (psVar16 != (unsigned char *)0x0) {
        local_2d0[0] = GetGlobalPoolAllocator();
        std__string__string(psVar16,"",(unsigned char *)local_2d0);
        psVar18 = psVar16;
      }
      *(unsigned char **)(psVar4 + 0x14) = psVar18;
      ((int (*)())TType__buildMangledName)(psVar4);
      std__string__append(*(ulong *)(psVar4 + 0x14),'\x01');
    }
    std__operator_((unsigned char *)&local_850,(unsigned char *)(uVar59 + 0x44));
    std__string__assign((unsigned char *)(uVar59 + 0x44));
    psVar4 = local_84c + -4;
    paVar14 = (unsigned char *)(local_84c + -0xc);
    local_2c0 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (0 < iVar55) break;
    goto LAB_97ba8824;
  case 0x67:
    if (1 < puVar52[-0x11]) {
      pcVar64 = (char *)getQualifierString();
      TParseContext__error
                ((int)param_1,(char *)puVar52[-0xb],"no qualifiers allowed for function return",
                 pcVar64,"");
      TParseContext__recover();
    }
    iVar55 = TParseContext__structQualifierErrorCheck((int)param_1,(unsigned char *)puVar52[-0xb]);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    local_820 = (unsigned char *)puVar52[-0x12];
    local_81c = (unsigned char *)puVar52[-0x11];
    local_818 = (unsigned char *)puVar52[-0x10];
    local_814 = (unsigned char *)puVar52[-0xf];
    local_80c = (unsigned char *)puVar52[-0xd];
    local_810 = (unsigned char *)puVar52[-0xe];
    local_5c = -0x5847c8b4;
    local_808 = (unsigned char *)puVar52[-0xc];
    local_82c = (unsigned char *)
                (((uint)local_810 & 1) << 9 |
                ((uint)local_814 & 1) << 10 |
                ((uint)local_818 & 0xff) << 0xb |
                ((uint)local_820 & 0x3f) << 0x13 | (int)local_81c << 0x19 | (uint)local_82c & 0x1ff)
    ;
    local_850 = (unsigned char *)&PTR__TType_a7b7d640;
    local_830 = (unsigned char *)0x0;
    local_84c = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_838 = (unsigned char *)0x0;
    local_834 = (unsigned char *)0x0;
    psVar4 = local_840;
    local_800 = local_820;
    local_7fc = local_81c;
    local_7f8 = local_818;
    local_7f4 = local_814;
    local_7f0 = local_810;
    local_7ec = local_80c;
    local_7e8 = local_808;
    if (local_80c != (unsigned char *)0x0) {
      local_848 = *(unsigned char **)(local_80c + 8);
      local_64 = -0x5847c8b4;
      local_838 = (unsigned char *)TType__setStructSize((unsigned char *)&local_850);
      iVar55 = (**(code **)(*(int *)local_7ec + 0x18))(local_7ec);
      *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
           **(undefined1 **)(local_64 + -0x7cc4);
      pcVar64 = *(char **)(iVar55 + 4);
      uVar20 = GetGlobalPoolAllocator();
      psVar18 = (unsigned char *)TPoolAllocator__allocate(uVar20);
      in_cr0 = (psVar18 == (unsigned char *)0x0) << 1;
      psVar4 = (unsigned char *)0x0;
      if (psVar18 != (unsigned char *)0x0) {
        local_2b0[0] = GetGlobalPoolAllocator();
        std__string__string(psVar18,pcVar64,(unsigned char *)local_2b0);
        psVar4 = psVar18;
      }
    }
    local_840 = psVar4;
    uVar20 = GetGlobalPoolAllocator();
    psVar18 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    psVar4 = (unsigned char *)puVar52[-10];
    *(undefined **)psVar18 = PTR_vtable_a7b7c0f4 + 8;
    *(unsigned char **)(psVar18 + 4) = psVar4;
    local_2a0 = GetGlobalPoolAllocator();
    *(int *)(psVar18 + 0x18) = 0;
    *(int *)(psVar18 + 0x10) = 0;
    *(int *)(psVar18 + 0x14) = 0;
    *(int *)(psVar18 + 0xc) = local_2a0;
    *(unsigned char **)(psVar18 + 0x20) = local_84c;
    psVar16 = (unsigned char *)(local_5c - 0x610c);
    *(unsigned char **)(psVar18 + 0x24) = local_848;
    *(unsigned char **)(psVar18 + 0x28) = local_844;
    *(unsigned char **)(psVar18 + 0x2c) = local_840;
    *(unsigned char **)(psVar18 + 0x30) = local_83c;
    *(unsigned char **)(psVar18 + 0x34) = local_838;
    *(unsigned char **)(psVar18 + 0x1c) = psVar16;
    *(unsigned char **)(psVar18 + 0x38) = local_834;
    *(unsigned char **)(psVar18 + 0x3c) = local_830;
    uVar3 = *(uint *)(psVar18 + 0x40);
    uVar54 = (uint)local_82c & 0xfe000000;
    *(uint *)(psVar18 + 0x40) = uVar54 | uVar3 & 0x1ffffff;
    uVar57 = ((uint)local_82c >> 0x13 & 0x3f) << 0x13;
    *(uint *)(psVar18 + 0x40) = uVar57 | uVar54 | uVar3 & 0x7ffff;
    uVar59 = (uint)local_82c & 0x7f800;
    *(uint *)(psVar18 + 0x40) = uVar59 | uVar57 | uVar54 | uVar3 & 0x7ff;
    uVar61 = ((uint)local_82c >> 10 & 1) << 10;
    *(uint *)(psVar18 + 0x40) = uVar61 | uVar59 | uVar57 | uVar54 | uVar3 & 0x3ff;
    *(uint *)(psVar18 + 0x40) =
         ((uint)local_82c >> 9 & 1) << 9 | uVar61 | uVar59 | uVar57 | uVar54 | uVar3 & 0x1ff;
    std__string__string(psVar18 + 0x44,psVar4);
    std__string__append((ulong)(psVar18 + 0x44),'\x01');
    *(int *)(psVar18 + 0x50) = 0;
    *(int *)(psVar18 + 0x4c) = 0;
    psVar4 = local_878;
    local_870 = psVar18;
    local_850 = psVar16;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x68:
    if (puVar52[-7] == 0) {
      uVar59 = puVar52[1];
      local_64 = -0x5847c8b4;
      iVar55 = *(int *)(uVar59 + 4);
      *(unsigned char *)(iVar55 + *(int *)(iVar55 + -0xc)) = *DAT_a7b7ba88;
      TParseContext__error
                ((int)param_1,(char *)*puVar52,"illegal use of type \'void\'",*(char **)(uVar59 + 4)
                 ,"");
      TParseContext__recover();
    }
    iVar55 = TParseContext__reservedErrorCheck((int)param_1,(unsigned char *)*puVar52);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    local_840 = (unsigned char *)puVar52[1];
    local_5c = -0x5847c8b4;
    uVar20 = GetGlobalPoolAllocator();
    pTVar15 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    local_830 = (unsigned char *)puVar52[-7];
    local_82c = (unsigned char *)puVar52[-6];
    local_828 = (unsigned char *)puVar52[-5];
    local_824 = (unsigned char *)puVar52[-4];
    local_820 = (unsigned char *)puVar52[-3];
    local_81c = (unsigned char *)puVar52[-2];
    local_818 = (unsigned char *)puVar52[-1];
    *(int *)pTVar15 = local_5c + -0x610c;
    *(undefined4 *)(pTVar15 + 0x20) = 0;
    *(undefined4 *)(pTVar15 + 4) = 0;
    *(undefined4 *)(pTVar15 + 8) = 0;
    *(undefined4 *)(pTVar15 + 0xc) = 0;
    *(undefined4 *)(pTVar15 + 0x10) = 0;
    *(undefined4 *)(pTVar15 + 0x14) = 0;
    *(undefined4 *)(pTVar15 + 0x18) = 0;
    *(undefined4 *)(pTVar15 + 0x1c) = 0;
    uVar3 = *(uint *)(pTVar15 + 0x24);
    uVar59 = (int)local_82c << 0x19;
    *(uint *)(pTVar15 + 0x24) = uVar59 | uVar3 & 0x1ffffff;
    uVar54 = ((uint)local_830 & 0x3f) << 0x13;
    *(uint *)(pTVar15 + 0x24) = uVar54 | uVar59 | uVar3 & 0x7ffff;
    uVar57 = ((uint)local_828 & 0xff) << 0xb;
    *(uint *)(pTVar15 + 0x24) = uVar57 | uVar54 | uVar59 | uVar3 & 0x7ff;
    uVar61 = ((uint)local_824 & 1) << 10;
    *(uint *)(pTVar15 + 0x24) = uVar61 | uVar57 | uVar54 | uVar59 | uVar3 & 0x3ff;
    *(uint *)(pTVar15 + 0x24) =
         ((uint)local_820 & 1) << 9 | uVar61 | uVar57 | uVar54 | uVar59 | uVar3 & 0x1ff;
    local_810 = local_830;
    local_80c = local_82c;
    local_808 = local_828;
    local_804 = local_824;
    local_800 = local_820;
    local_7fc = local_81c;
    local_7f8 = local_818;
    if (local_81c != (unsigned char *)0x0) {
      local_64 = -0x5847c8b4;
      *(int *)(pTVar15 + 8) = *(int *)(local_81c + 8);
      uVar19 = TType__setStructSize(pTVar15);
      *(undefined4 *)(pTVar15 + 0x18) = uVar19;
      iVar55 = (**(code **)(*(int *)local_7fc + 0x18))();
      *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
           **(undefined1 **)(local_64 + -0x7cc4);
      pcVar64 = *(char **)(iVar55 + 4);
      uVar20 = GetGlobalPoolAllocator();
      psVar18 = (unsigned char *)TPoolAllocator__allocate(uVar20);
      in_cr0 = (psVar18 == (unsigned char *)0x0) << 1;
      psVar4 = (unsigned char *)0x0;
      if (psVar18 != (unsigned char *)0x0) {
        local_290[0] = GetGlobalPoolAllocator();
        std__string__string(psVar18,pcVar64,(unsigned char *)local_290);
        psVar4 = psVar18;
      }
      *(unsigned char **)(pTVar15 + 0x10) = psVar4;
    }
    local_850 = local_840;
    local_880 = *puVar52;
    psVar4 = local_878;
    local_870 = local_850;
    local_86c = (unsigned char *)pTVar15;
    local_84c = (unsigned char *)pTVar15;
    local_83c = (unsigned char *)pTVar15;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x69:
    local_5c = -0x5847c8b4;
    if (puVar52[-0x24] != 0) {
      local_810 = (unsigned char *)puVar52[-0x28];
      local_80c = (unsigned char *)puVar52[-0x27];
      local_808 = (unsigned char *)puVar52[-0x26];
      local_804 = (unsigned char *)puVar52[-0x25];
      local_7fc = (unsigned char *)puVar52[-0x23];
      local_800 = (unsigned char *)puVar52[-0x24];
      local_7f8 = (unsigned char *)puVar52[-0x22];
      local_81c = (unsigned char *)
                  (((uint)local_800 & 1) << 9 |
                  ((uint)local_804 & 1) << 10 |
                  ((uint)local_808 & 0xff) << 0xb |
                  ((uint)local_810 & 0x3f) << 0x13 |
                  (int)local_80c << 0x19 | (uint)local_81c & 0x1ff);
      local_840 = (unsigned char *)&PTR__TType_a7b7d640;
      local_820 = (unsigned char *)0x0;
      local_83c = (unsigned char *)0x0;
      local_838 = (unsigned char *)0x0;
      local_834 = (unsigned char *)0x0;
      local_830 = (unsigned char *)0x0;
      local_82c = (unsigned char *)0x0;
      local_828 = (unsigned char *)0x0;
      local_824 = (unsigned char *)0x0;
      local_64 = -0x5847c8b4;
      psVar4 = local_830;
      local_7f0 = local_810;
      local_7ec = local_80c;
      local_7e8 = local_808;
      local_7e4 = local_804;
      local_7e0 = local_800;
      local_7dc = local_7fc;
      local_7d8 = local_7f8;
      if (local_7fc != (unsigned char *)0x0) {
        local_838 = *(unsigned char **)(local_7fc + 8);
        local_828 = (unsigned char *)TType__setStructSize((unsigned char *)&local_840);
        iVar55 = (**(code **)(*(int *)local_7dc + 0x18))(local_7dc);
        *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
             **(undefined1 **)(local_64 + -0x7cc4);
        pcVar64 = *(char **)(iVar55 + 4);
        uVar20 = GetGlobalPoolAllocator();
        psVar18 = (unsigned char *)TPoolAllocator__allocate(uVar20);
        in_cr0 = (psVar18 == (unsigned char *)0x0) << 1;
        psVar4 = (unsigned char *)0x0;
        if (psVar18 != (unsigned char *)0x0) {
          local_280[0] = GetGlobalPoolAllocator();
          std__string__string(psVar18,pcVar64,(unsigned char *)local_280);
          psVar4 = psVar18;
        }
      }
      local_830 = psVar4;
      TType__getCompleteString();
      local_84c[*(int *)(local_84c + -0xc)] = **(unsigned char **)(local_64 + -0x7cc4);
      TParseContext__error
                ((int)param_1,(char *)puVar52[-0x16],"cannot declare arrays of this type",
                 (char *)local_84c,"");
      psVar4 = local_84c + -4;
      local_270 = local_850;
      do {
        iVar55 = *(int *)psVar4;
        if (in_RESERVE != '\0') {
          iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
          *(int *)psVar4 = iVar6;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar55 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(local_84c + -0xc));
      }
      local_840 = (unsigned char *)(local_5c - 0x610c);
      TParseContext__recover();
    }
    iVar55 = TParseContext__reservedErrorCheck((int)param_1,(unsigned char *)puVar52[-0x21]);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    puVar52[-0x24] = 1;
    uVar20 = GetGlobalPoolAllocator();
    pTVar15 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    local_850 = (unsigned char *)puVar52[-0x28];
    local_84c = (unsigned char *)puVar52[-0x27];
    local_848 = (unsigned char *)puVar52[-0x26];
    local_844 = (unsigned char *)puVar52[-0x25];
    local_840 = (unsigned char *)puVar52[-0x24];
    local_83c = (unsigned char *)puVar52[-0x23];
    local_838 = (unsigned char *)puVar52[-0x22];
    *(int *)pTVar15 = local_5c + -0x610c;
    *(undefined4 *)(pTVar15 + 0x20) = 0;
    *(undefined4 *)(pTVar15 + 4) = 0;
    *(undefined4 *)(pTVar15 + 8) = 0;
    *(undefined4 *)(pTVar15 + 0xc) = 0;
    *(undefined4 *)(pTVar15 + 0x10) = 0;
    *(undefined4 *)(pTVar15 + 0x14) = 0;
    *(undefined4 *)(pTVar15 + 0x18) = 0;
    *(undefined4 *)(pTVar15 + 0x1c) = 0;
    uVar3 = *(uint *)(pTVar15 + 0x24);
    uVar59 = (int)local_84c << 0x19;
    *(uint *)(pTVar15 + 0x24) = uVar59 | uVar3 & 0x1ffffff;
    uVar54 = ((uint)local_850 & 0x3f) << 0x13;
    *(uint *)(pTVar15 + 0x24) = uVar54 | uVar59 | uVar3 & 0x7ffff;
    uVar57 = ((uint)local_848 & 0xff) << 0xb;
    *(uint *)(pTVar15 + 0x24) = uVar57 | uVar54 | uVar59 | uVar3 & 0x7ff;
    uVar61 = ((uint)local_844 & 1) << 10;
    *(uint *)(pTVar15 + 0x24) = uVar61 | uVar57 | uVar54 | uVar59 | uVar3 & 0x3ff;
    *(uint *)(pTVar15 + 0x24) =
         ((uint)local_840 & 1) << 9 | uVar61 | uVar57 | uVar54 | uVar59 | uVar3 & 0x1ff;
    local_830 = local_850;
    local_82c = local_84c;
    local_828 = local_848;
    local_824 = local_844;
    local_820 = local_840;
    local_81c = local_83c;
    local_818 = local_838;
    if (local_83c != (unsigned char *)0x0) {
      local_64 = -0x5847c8b4;
      *(int *)(pTVar15 + 8) = *(int *)(local_83c + 8);
      uVar19 = TType__setStructSize(pTVar15);
      *(undefined4 *)(pTVar15 + 0x18) = uVar19;
      iVar55 = (**(code **)(*(int *)local_81c + 0x18))();
      *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
           **(undefined1 **)(local_64 + -0x7cc4);
      pcVar64 = *(char **)(iVar55 + 4);
      uVar20 = GetGlobalPoolAllocator();
      psVar18 = (unsigned char *)TPoolAllocator__allocate(uVar20);
      in_cr0 = (psVar18 == (unsigned char *)0x0) << 1;
      psVar4 = (unsigned char *)0x0;
      if (psVar18 != (unsigned char *)0x0) {
        local_260[0] = GetGlobalPoolAllocator();
        std__string__string(psVar18,pcVar64,(unsigned char *)local_260);
        psVar4 = psVar18;
      }
      *(unsigned char **)(pTVar15 + 0x10) = psVar4;
    }
    iVar55 = (**(code **)(*(int *)puVar52[-9] + 0x18))();
    if (iVar55 != 0) {
      iVar55 = (**(code **)(*(int *)puVar52[-9] + 0x18))();
      uVar19 = **(undefined4 **)(iVar55 + 0x30);
      *(uint *)(pTVar15 + 0x24) = *(uint *)(pTVar15 + 0x24) | 0x200;
      *(undefined4 *)(pTVar15 + 4) = uVar19;
    }
    local_840 = (unsigned char *)puVar52[-0x20];
    local_880 = puVar52[-0x21];
    psVar4 = local_878;
    local_870 = local_840;
    local_86c = (unsigned char *)pTVar15;
    local_850 = local_840;
    local_84c = (unsigned char *)pTVar15;
    local_83c = (unsigned char *)pTVar15;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x6a:
  case 0x6c:
    _memcpy(&local_880,puVar52,0x2c);
    uVar59 = *puVar52;
    uVar54 = puVar52[-0x11];
    uVar57 = puVar52[-7];
    goto LAB_97ba9130;
  case 0x6b:
  case 0x6d:
    _memcpy(&local_880,puVar52,0x2c);
    iVar55 = TParseContext__parameterSamplerErrorCheck(param_1,*puVar52,puVar52[-7],puVar52[5]);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    uVar59 = *puVar52;
    uVar57 = puVar52[-7];
    uVar54 = 0;
LAB_97ba9130:
    iVar55 = TParseContext__paramErrorCheck(param_1,uVar59,uVar54,uVar57,local_86c);
LAB_97bab180:
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (iVar55 == 0) break;
LAB_97bab5f4:
    TParseContext__recover();
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x6e:
  case 0x6f:
    local_870 = (unsigned char *)0x9;
    break;
  case 0x70:
    local_870 = (unsigned char *)0xa;
    break;
  case 0x71:
    local_870 = (unsigned char *)0xb;
    break;
  case 0x72:
    local_840 = (unsigned char *)0x0;
    uVar20 = GetGlobalPoolAllocator();
    pTVar15 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    local_830 = (unsigned char *)puVar52[4];
    local_82c = (unsigned char *)puVar52[5];
    local_828 = (unsigned char *)puVar52[6];
    local_824 = (unsigned char *)puVar52[7];
    local_5c = -0x5847c8b4;
    local_820 = (unsigned char *)puVar52[8];
    local_81c = (unsigned char *)puVar52[9];
    local_818 = (unsigned char *)puVar52[10];
    *(undefined ***)pTVar15 = &PTR__TType_a7b7d640;
    *(undefined4 *)(pTVar15 + 0x20) = 0;
    *(undefined4 *)(pTVar15 + 4) = 0;
    *(undefined4 *)(pTVar15 + 8) = 0;
    *(undefined4 *)(pTVar15 + 0xc) = 0;
    *(undefined4 *)(pTVar15 + 0x10) = 0;
    *(undefined4 *)(pTVar15 + 0x14) = 0;
    *(undefined4 *)(pTVar15 + 0x18) = 0;
    *(undefined4 *)(pTVar15 + 0x1c) = 0;
    uVar3 = *(uint *)(pTVar15 + 0x24);
    uVar59 = (int)local_82c << 0x19;
    *(uint *)(pTVar15 + 0x24) = uVar59 | uVar3 & 0x1ffffff;
    uVar54 = ((uint)local_830 & 0x3f) << 0x13;
    *(uint *)(pTVar15 + 0x24) = uVar54 | uVar59 | uVar3 & 0x7ffff;
    uVar57 = ((uint)local_828 & 0xff) << 0xb;
    *(uint *)(pTVar15 + 0x24) = uVar57 | uVar54 | uVar59 | uVar3 & 0x7ff;
    uVar61 = ((uint)local_824 & 1) << 10;
    *(uint *)(pTVar15 + 0x24) = uVar61 | uVar57 | uVar54 | uVar59 | uVar3 & 0x3ff;
    *(uint *)(pTVar15 + 0x24) =
         ((uint)local_820 & 1) << 9 | uVar61 | uVar57 | uVar54 | uVar59 | uVar3 & 0x1ff;
    local_810 = local_830;
    local_80c = local_82c;
    local_808 = local_828;
    local_804 = local_824;
    local_800 = local_820;
    local_7fc = local_81c;
    local_7f8 = local_818;
    if (local_81c != (unsigned char *)0x0) {
      local_64 = -0x5847c8b4;
      *(int *)(pTVar15 + 8) = *(int *)(local_81c + 8);
      uVar19 = TType__setStructSize(pTVar15);
      *(undefined4 *)(pTVar15 + 0x18) = uVar19;
      iVar55 = (**(code **)(*(int *)local_7fc + 0x18))();
      *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
           **(undefined1 **)(local_64 + -0x7cc4);
      pcVar64 = *(char **)(iVar55 + 4);
      uVar20 = GetGlobalPoolAllocator();
      psVar18 = (unsigned char *)TPoolAllocator__allocate(uVar20);
      in_cr0 = (psVar18 == (unsigned char *)0x0) << 1;
      psVar4 = (unsigned char *)0x0;
      if (psVar18 != (unsigned char *)0x0) {
        local_250[0] = GetGlobalPoolAllocator();
        std__string__string(psVar18,pcVar64,(unsigned char *)local_250);
        psVar4 = psVar18;
      }
      *(unsigned char **)(pTVar15 + 0x10) = psVar4;
    }
    local_870 = local_840;
    local_850 = local_840;
    psVar4 = local_878;
    local_86c = (unsigned char *)pTVar15;
    local_84c = (unsigned char *)pTVar15;
    local_83c = (unsigned char *)pTVar15;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x73:
    local_5c = -0x5847c8b4;
    if (puVar52[-0x19] != 0) {
      local_810 = (unsigned char *)puVar52[-0x1d];
      local_80c = (unsigned char *)puVar52[-0x1c];
      local_808 = (unsigned char *)puVar52[-0x1b];
      local_804 = (unsigned char *)puVar52[-0x1a];
      local_7fc = (unsigned char *)puVar52[-0x18];
      local_800 = (unsigned char *)puVar52[-0x19];
      local_7f8 = (unsigned char *)puVar52[-0x17];
      local_81c = (unsigned char *)
                  (((uint)local_800 & 1) << 9 |
                  ((uint)local_804 & 1) << 10 |
                  ((uint)local_808 & 0xff) << 0xb |
                  ((uint)local_810 & 0x3f) << 0x13 |
                  (int)local_80c << 0x19 | (uint)local_81c & 0x1ff);
      local_840 = (unsigned char *)&PTR__TType_a7b7d640;
      local_820 = (unsigned char *)0x0;
      local_83c = (unsigned char *)0x0;
      local_838 = (unsigned char *)0x0;
      local_834 = (unsigned char *)0x0;
      local_830 = (unsigned char *)0x0;
      local_82c = (unsigned char *)0x0;
      local_828 = (unsigned char *)0x0;
      local_824 = (unsigned char *)0x0;
      local_64 = -0x5847c8b4;
      psVar4 = local_830;
      local_7f0 = local_810;
      local_7ec = local_80c;
      local_7e8 = local_808;
      local_7e4 = local_804;
      local_7e0 = local_800;
      local_7dc = local_7fc;
      local_7d8 = local_7f8;
      if (local_7fc != (unsigned char *)0x0) {
        local_838 = *(unsigned char **)(local_7fc + 8);
        local_828 = (unsigned char *)TType__setStructSize((unsigned char *)&local_840);
        iVar55 = (**(code **)(*(int *)local_7dc + 0x18))(local_7dc);
        *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
             **(undefined1 **)(local_64 + -0x7cc4);
        pcVar64 = *(char **)(iVar55 + 4);
        uVar20 = GetGlobalPoolAllocator();
        psVar18 = (unsigned char *)TPoolAllocator__allocate(uVar20);
        in_cr0 = (psVar18 == (unsigned char *)0x0) << 1;
        psVar4 = (unsigned char *)0x0;
        if (psVar18 != (unsigned char *)0x0) {
          local_240[0] = GetGlobalPoolAllocator();
          std__string__string(psVar18,pcVar64,(unsigned char *)local_240);
          psVar4 = psVar18;
        }
      }
      local_830 = psVar4;
      TType__getCompleteString();
      local_84c[*(int *)(local_84c + -0xc)] = **(unsigned char **)(local_64 + -0x7cc4);
      TParseContext__error
                ((int)param_1,(char *)puVar52[-0x16],"cannot declare arrays of this type",
                 (char *)local_84c,"");
      psVar4 = local_84c + -4;
      local_230 = local_850;
      do {
        iVar55 = *(int *)psVar4;
        if (in_RESERVE != '\0') {
          iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
          *(int *)psVar4 = iVar6;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar55 < 1) {
        std__string___Rep___M_destroy((unsigned char *)(local_84c + -0xc));
      }
      local_840 = (unsigned char *)(local_5c - 0x610c);
      TParseContext__recover();
    }
    puVar52[-0x19] = 1;
    uVar20 = GetGlobalPoolAllocator();
    pTVar15 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    local_850 = (unsigned char *)puVar52[-0x1d];
    local_84c = (unsigned char *)puVar52[-0x1c];
    local_848 = (unsigned char *)puVar52[-0x1b];
    local_844 = (unsigned char *)puVar52[-0x1a];
    local_840 = (unsigned char *)puVar52[-0x19];
    local_83c = (unsigned char *)puVar52[-0x18];
    local_838 = (unsigned char *)puVar52[-0x17];
    *(int *)pTVar15 = local_5c + -0x610c;
    *(undefined4 *)(pTVar15 + 0x20) = 0;
    *(undefined4 *)(pTVar15 + 4) = 0;
    *(undefined4 *)(pTVar15 + 8) = 0;
    *(undefined4 *)(pTVar15 + 0xc) = 0;
    *(undefined4 *)(pTVar15 + 0x10) = 0;
    *(undefined4 *)(pTVar15 + 0x14) = 0;
    *(undefined4 *)(pTVar15 + 0x18) = 0;
    *(undefined4 *)(pTVar15 + 0x1c) = 0;
    uVar3 = *(uint *)(pTVar15 + 0x24);
    uVar59 = (int)local_84c << 0x19;
    *(uint *)(pTVar15 + 0x24) = uVar59 | uVar3 & 0x1ffffff;
    uVar54 = ((uint)local_850 & 0x3f) << 0x13;
    *(uint *)(pTVar15 + 0x24) = uVar54 | uVar59 | uVar3 & 0x7ffff;
    uVar57 = ((uint)local_848 & 0xff) << 0xb;
    *(uint *)(pTVar15 + 0x24) = uVar57 | uVar54 | uVar59 | uVar3 & 0x7ff;
    uVar61 = ((uint)local_844 & 1) << 10;
    *(uint *)(pTVar15 + 0x24) = uVar61 | uVar57 | uVar54 | uVar59 | uVar3 & 0x3ff;
    *(uint *)(pTVar15 + 0x24) =
         ((uint)local_840 & 1) << 9 | uVar61 | uVar57 | uVar54 | uVar59 | uVar3 & 0x1ff;
    local_830 = local_850;
    local_82c = local_84c;
    local_828 = local_848;
    local_824 = local_844;
    local_820 = local_840;
    local_81c = local_83c;
    local_818 = local_838;
    if (local_83c != (unsigned char *)0x0) {
      local_64 = -0x5847c8b4;
      *(int *)(pTVar15 + 8) = *(int *)(local_83c + 8);
      uVar19 = TType__setStructSize(pTVar15);
      *(undefined4 *)(pTVar15 + 0x18) = uVar19;
      iVar55 = (**(code **)(*(int *)local_81c + 0x18))();
      *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
           **(undefined1 **)(local_64 + -0x7cc4);
      pcVar64 = *(char **)(iVar55 + 4);
      uVar20 = GetGlobalPoolAllocator();
      psVar18 = (unsigned char *)TPoolAllocator__allocate(uVar20);
      in_cr0 = (psVar18 == (unsigned char *)0x0) << 1;
      psVar4 = (unsigned char *)0x0;
      if (psVar18 != (unsigned char *)0x0) {
        local_220[0] = GetGlobalPoolAllocator();
        std__string__string(psVar18,pcVar64,(unsigned char *)local_220);
        psVar4 = psVar18;
      }
      *(unsigned char **)(pTVar15 + 0x10) = psVar4;
    }
    iVar55 = (**(code **)(*(int *)puVar52[-9] + 0x18))();
    if (iVar55 != 0) {
      iVar55 = (**(code **)(*(int *)puVar52[-9] + 0x18))();
      uVar19 = **(undefined4 **)(iVar55 + 0x30);
      *(uint *)(pTVar15 + 0x24) = *(uint *)(pTVar15 + 0x24) | 0x200;
      *(undefined4 *)(pTVar15 + 4) = uVar19;
    }
    local_850 = (unsigned char *)0x0;
    local_880 = puVar52[-0x16];
    psVar4 = local_878;
    local_870 = local_850;
    local_86c = (unsigned char *)pTVar15;
    local_84c = (unsigned char *)pTVar15;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x74:
    _memcpy(&local_880,puVar52,0x2c);
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x75:
    _memcpy(&local_880,puVar52 + -0x16,0x2c);
    pTVar17 = (unsigned char *)*puVar52;
    goto LAB_97ba9874;
  case 0x76:
    _memcpy(&local_880,puVar52 + -0x2c,0x2c);
    iVar55 = TParseContext__structQualifierErrorCheck((int)param_1,(unsigned char *)puVar52[-0x16]);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    uVar59 = puVar52[-0xb];
    uVar54 = puVar52[-0x15];
    uVar57 = 0;
    goto LAB_97ba99f8;
  case 0x77:
    _memcpy(&local_880,puVar52 + -0x37,0x2c);
    pTVar17 = (unsigned char *)puVar52[-0x21];
    goto LAB_97ba99a0;
  case 0x78:
    _memcpy(&local_880,puVar52 + -0x2c,0x2c);
    iVar55 = TParseContext__structQualifierErrorCheck((int)param_1,(unsigned char *)puVar52[-0x16]);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    iVar55 = TParseContext__executeInitializer
                       ((int)param_1,(unsigned char *)puVar52[-0x16],(unsigned char *)puVar52[-0x15],
                        (unsigned char *)(puVar52 + -0x28),(unsigned char **)puVar52[2]);
    if (iVar55 == 0) {
      if (local_80 == 0) {
        psVar4 = (unsigned char *)puVar52[-0x2a];
        psVar18 = local_7f0;
        psVar16 = local_750;
        break;
      }
      pTVar23 = *(unsigned char **)param_1;
      pTVar28 = (unsigned char *)puVar52[-0x2a];
      uVar59 = local_80;
      goto LAB_97ba97d8;
    }
    goto LAB_97bab1f4;
  case 0x79:
    local_870 = (unsigned char *)puVar52[4];
    local_86c = (unsigned char *)puVar52[5];
    local_868 = (unsigned char *)puVar52[6];
    local_864 = (unsigned char *)puVar52[7];
    local_860 = (unsigned char *)puVar52[8];
    local_85c = (unsigned char *)puVar52[9];
    local_858 = (unsigned char *)puVar52[10];
    psVar4 = (unsigned char *)0x0;
    break;
  case 0x7a:
    local_878 = (unsigned char *)0x0;
    local_870 = (unsigned char *)puVar52[-7];
    local_86c = (unsigned char *)puVar52[-6];
    local_868 = (unsigned char *)puVar52[-5];
    local_864 = (unsigned char *)puVar52[-4];
    local_860 = (unsigned char *)puVar52[-3];
    local_85c = (unsigned char *)puVar52[-2];
    local_858 = (unsigned char *)puVar52[-1];
    pTVar17 = (unsigned char *)*puVar52;
LAB_97ba9874:
    iVar55 = TParseContext__structQualifierErrorCheck((int)param_1,pTVar17);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    iVar55 = TParseContext__nonInitErrorCheck
                       ((int)param_1,(unsigned char *)*puVar52,(unsigned char *)puVar52[1]);
    goto LAB_97bab180;
  case 0x7b:
    local_878 = (unsigned char *)0x0;
    local_870 = (unsigned char *)puVar52[-0x1d];
    local_86c = (unsigned char *)puVar52[-0x1c];
    local_868 = (unsigned char *)puVar52[-0x1b];
    local_864 = (unsigned char *)puVar52[-0x1a];
    local_860 = (unsigned char *)puVar52[-0x19];
    local_85c = (unsigned char *)puVar52[-0x18];
    local_858 = (unsigned char *)puVar52[-0x17];
    iVar55 = TParseContext__structQualifierErrorCheck((int)param_1,(unsigned char *)puVar52[-0x16]);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    uVar59 = puVar52[-0xb];
    uVar54 = puVar52[-0x15];
    local_850 = local_870;
    local_84c = local_86c;
    local_848 = local_868;
    local_844 = local_864;
    local_840 = local_860;
    local_83c = local_85c;
    local_838 = local_858;
    puVar5[0x10] = 0;
    puVar5[0xf] = local_858;
    goto LAB_97ba9a08;
  case 0x7c:
    local_878 = (unsigned char *)0x0;
    local_870 = (unsigned char *)puVar52[-0x28];
    local_86c = (unsigned char *)puVar52[-0x27];
    local_868 = (unsigned char *)puVar52[-0x26];
    local_864 = (unsigned char *)puVar52[-0x25];
    local_860 = (unsigned char *)puVar52[-0x24];
    local_85c = (unsigned char *)puVar52[-0x23];
    local_858 = (unsigned char *)puVar52[-0x22];
    pTVar17 = (unsigned char *)puVar52[-0x21];
LAB_97ba99a0:
    iVar55 = TParseContext__structQualifierErrorCheck((int)param_1,pTVar17);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    uVar59 = puVar52[-0x16];
    uVar54 = puVar52[-0x20];
    uVar57 = puVar52[-9];
LAB_97ba99f8:
    puVar5[0x10] = uVar57;
    puVar5[0xf] = local_858;
    local_850 = local_870;
    local_84c = local_86c;
    local_848 = local_868;
    local_844 = local_864;
    local_840 = local_860;
    local_83c = local_85c;
    local_838 = local_858;
LAB_97ba9a08:
    puVar5[0xe] = local_83c;
    local_870 = local_850;
    local_86c = local_84c;
    local_868 = local_848;
    local_864 = local_844;
    local_860 = local_840;
    local_85c = local_83c;
    local_858 = local_838;
    iVar55 = TParseContext__arrayErrorCheck
                       (param_1,uVar59,uVar54,local_850,local_84c,local_848,local_844,local_840);
    goto LAB_97bab180;
  case 0x7d:
    local_870 = (unsigned char *)puVar52[-0x1d];
    local_86c = (unsigned char *)puVar52[-0x1c];
    local_868 = (unsigned char *)puVar52[-0x1b];
    local_864 = (unsigned char *)puVar52[-0x1a];
    local_860 = (unsigned char *)puVar52[-0x19];
    local_85c = (unsigned char *)puVar52[-0x18];
    local_858 = (unsigned char *)puVar52[-0x17];
    iVar55 = TParseContext__structQualifierErrorCheck((int)param_1,(unsigned char *)puVar52[-0x16]);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    iVar55 = TParseContext__executeInitializer
                       ((int)param_1,(unsigned char *)puVar52[-0x16],(unsigned char *)puVar52[-0x15],
                        (unsigned char *)(puVar52 + -0x1d),(unsigned char **)puVar52[2]);
    if (iVar55 != 0) goto LAB_97bab1f4;
    if (local_7c != 0) {
      pTVar23 = *(unsigned char **)param_1;
      uVar59 = local_7c;
      goto LAB_97bab0ec;
    }
    goto switchD_97ba39c8_caseD_60;
  case 0x7e:
    local_868 = (unsigned char *)puVar52[6];
    local_864 = (unsigned char *)puVar52[7];
    local_860 = (unsigned char *)puVar52[8];
    local_85c = (unsigned char *)puVar52[9];
    local_858 = (unsigned char *)puVar52[10];
    local_870 = (unsigned char *)puVar52[4];
    local_86c = (unsigned char *)puVar52[5];
    break;
  case 0x7f:
    local_850 = (unsigned char *)puVar52[4];
    local_84c = (unsigned char *)puVar52[-6];
    local_848 = (unsigned char *)puVar52[6];
    local_844 = (unsigned char *)puVar52[7];
    local_820 = (unsigned char *)0x0;
    local_83c = (unsigned char *)puVar52[9];
    local_838 = (unsigned char *)0x0;
    local_818 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    uVar59 = puVar52[-6];
    local_830 = local_850;
    local_82c = local_84c;
    local_828 = local_848;
    local_824 = local_844;
    local_81c = local_83c;
    if ((uVar59 == 3) && (puVar52[4] - 2 < 2)) {
      pcVar64 = (char *)getQualifierString(3);
      TParseContext__error((int)param_1,(char *)puVar52[10],"cannot be bool or int",pcVar64,"");
      TParseContext__recover();
      uVar59 = puVar52[-6];
    }
    if ((uVar59 - 4 < 2) && (puVar52[4] - 2 < 2)) {
      pcVar64 = (char *)getQualifierString();
      TParseContext__error((int)param_1,(char *)puVar52[10],"cannot be bool or int",pcVar64,"");
      TParseContext__recover();
    }
    goto LAB_97ba9d1c;
  case 0x80:
    puVar27 = &DAT_97c356fc;
    goto LAB_97ba9da4;
  case 0x81:
    if (*(int *)((int)param_1 + 0xc) != 0) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex shaders only ","attribute","",
                 "");
      TParseContext__recover();
    }
    iVar55 = TParseContext__globalErrorCheck
                       ((int)param_1,SUB41(*puVar52,0),
                        (char *)(uint)((uint)((*(int **)((int)param_1 + 4))[1] -
                                              **(int **)((int)param_1 + 4) >> 2) < 4));
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    puVar27 = &DAT_97c35718;
    goto LAB_97ba9da4;
  case 0x82:
    iVar55 = TParseContext__globalErrorCheck
                       ((int)param_1,SUB41(*puVar52,0),
                        (char *)(uint)((uint)((*(int **)((int)param_1 + 4))[1] -
                                              **(int **)((int)param_1 + 4) >> 2) < 4));
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    local_850 = DAT_97c35734;
    local_84c = DAT_97c35738;
    local_848 = DAT_97c3573c;
    local_844 = DAT_97c35740;
    local_840 = DAT_97c35744;
    local_83c = DAT_97c35748;
    local_838 = DAT_97c3574c;
    if (*(int *)((int)param_1 + 0xc) == 0) {
      local_84c = (unsigned char *)0x5;
    }
LAB_97ba9d1c:
    local_870 = local_850;
    local_86c = local_84c;
    local_868 = local_848;
    local_864 = local_844;
    local_860 = local_840;
    local_85c = local_83c;
    local_858 = local_838;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x83:
    iVar55 = TParseContext__globalErrorCheck
                       ((int)param_1,SUB41(*puVar52,0),
                        (char *)(uint)((uint)((*(int **)((int)param_1 + 4))[1] -
                                              **(int **)((int)param_1 + 4) >> 2) < 4));
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    puVar27 = &DAT_97c35750;
LAB_97ba9da4:
    local_858 = (unsigned char *)puVar27[6];
    local_868 = (unsigned char *)puVar27[2];
    local_864 = (unsigned char *)puVar27[3];
    local_860 = (unsigned char *)puVar27[4];
    local_85c = (unsigned char *)puVar27[5];
    psVar4 = local_878;
    local_870 = (unsigned char *)*puVar27;
    local_86c = (unsigned char *)puVar27[1];
    local_850 = (unsigned char *)*puVar27;
    local_84c = (unsigned char *)puVar27[1];
    local_848 = local_868;
    local_844 = local_864;
    local_840 = local_860;
    local_83c = local_85c;
    local_838 = local_858;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x84:
    local_830 = (unsigned char *)0x0;
    local_828 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x0;
    local_82c = (unsigned char *)
                (uint)((uint)((*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4) >> 2)
                      < 4);
    local_820 = (unsigned char *)0x0;
    local_81c = (unsigned char *)0x0;
    local_858 = (unsigned char *)*puVar52;
    local_868 = (unsigned char *)0x1;
    local_85c = (unsigned char *)0x0;
    local_850 = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x1;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_870 = (unsigned char *)0x0;
    local_864 = (unsigned char *)0x0;
    local_860 = (unsigned char *)0x0;
    local_86c = local_82c;
    local_84c = local_82c;
    local_838 = local_858;
    local_818 = local_858;
    break;
  case 0x85:
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x1;
    goto LAB_97ba9f0c;
  case 0x86:
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x2;
    goto LAB_97baa3fc;
  case 0x87:
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x3;
    goto LAB_97baa3fc;
  case 0x88:
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x1;
    goto LAB_97ba9eec;
  case 0x89:
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x1;
    goto LAB_97ba9fa8;
  case 0x8a:
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x1;
    goto LAB_97ba9fc8;
  case 0x8b:
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x3;
LAB_97ba9eec:
    iVar55 = piVar63[1] - *piVar63;
    local_828 = (unsigned char *)0x2;
    goto LAB_97baa40c;
  case 0x8c:
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x3;
    goto LAB_97ba9f0c;
  case 0x8d:
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x3;
    goto LAB_97ba9fc8;
  case 0x8e:
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x2;
LAB_97ba9f0c:
    iVar55 = piVar63[1] - *piVar63;
    local_818 = (unsigned char *)*puVar52;
    local_828 = local_830;
    goto LAB_97baa46c;
  case 0x8f:
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x2;
LAB_97ba9fa8:
    iVar55 = piVar63[1] - *piVar63;
    local_828 = (unsigned char *)0x3;
    goto LAB_97baa40c;
  case 0x90:
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x2;
LAB_97ba9fc8:
    iVar55 = piVar63[1] - *piVar63;
    local_828 = (unsigned char *)0x4;
    goto LAB_97baa40c;
  case 0x91:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ","mat2",
                 "","");
      TParseContext__recover();
    }
    iVar55 = (*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4);
    local_868 = (unsigned char *)0x2;
    goto LAB_97baa0ec;
  case 0x92:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ","mat3",
                 "","");
      TParseContext__recover();
    }
    iVar55 = (*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4);
    local_868 = (unsigned char *)0x3;
    goto LAB_97baa0ec;
  case 0x93:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ","mat4",
                 "","");
      TParseContext__recover();
    }
    iVar55 = (*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4);
    local_868 = (unsigned char *)0x4;
LAB_97baa0ec:
    local_82c = (unsigned char *)(uint)((uint)(iVar55 >> 2) < 4);
    local_830 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x1;
    local_820 = (unsigned char *)0x0;
    local_81c = (unsigned char *)0x0;
    local_858 = (unsigned char *)*puVar52;
    local_864 = (unsigned char *)0x1;
    local_85c = (unsigned char *)0x0;
    local_850 = (unsigned char *)0x1;
    local_844 = (unsigned char *)0x1;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_870 = (unsigned char *)0x1;
    local_860 = (unsigned char *)0x0;
    psVar4 = local_878;
    local_86c = local_82c;
    local_84c = local_82c;
    local_848 = local_868;
    local_838 = local_858;
    local_828 = local_868;
    local_818 = local_858;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x94:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ",
                 "sampler1D","","");
      TParseContext__recover();
    }
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x5;
    goto LAB_97baa3fc;
  case 0x95:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ",
                 "sampler2D","","");
      TParseContext__recover();
    }
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x6;
    goto LAB_97baa3fc;
  case 0x96:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ",
                 "sampler3D","","");
      TParseContext__recover();
    }
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x7;
    goto LAB_97baa3fc;
  case 0x97:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ",
                 "samplerCube","","");
      TParseContext__recover();
    }
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x8;
    goto LAB_97baa3fc;
  case 0x98:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ",
                 "sampler1DShadow","","");
      TParseContext__recover();
    }
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x9;
    goto LAB_97baa3fc;
  case 0x99:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ",
                 "sampler2DShadow","","");
      TParseContext__recover();
    }
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0xa;
    goto LAB_97baa3fc;
  case 0x9a:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ",
                 "sampler2DRect","","");
      TParseContext__recover();
    }
    iVar55 = TParseContext__extensionErrorCheck((int)param_1,(char *)*puVar52);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0xb;
    goto LAB_97baa3fc;
  case 0x9b:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar52," supported in vertex/fragment shaders only ",
                 "sampler2DRectShadow","","");
      TParseContext__recover();
    }
    iVar55 = TParseContext__extensionErrorCheck((int)param_1,(char *)*puVar52);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0xc;
LAB_97baa3fc:
    iVar55 = piVar63[1] - *piVar63;
    local_828 = (unsigned char *)0x1;
LAB_97baa40c:
    local_818 = (unsigned char *)*puVar52;
LAB_97baa46c:
    local_82c = (unsigned char *)(uint)((uint)(iVar55 >> 2) < 4);
    local_81c = (unsigned char *)0x0;
    local_820 = (unsigned char *)0x0;
    local_824 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_85c = (unsigned char *)0x0;
    local_864 = (unsigned char *)0x0;
    local_860 = (unsigned char *)0x0;
    psVar4 = local_878;
    local_870 = local_830;
    local_86c = local_82c;
    local_868 = local_828;
    local_858 = local_818;
    local_850 = local_830;
    local_84c = local_82c;
    local_848 = local_828;
    local_838 = local_818;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x9c:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)puVar52[10]," supported in vertex/fragment shaders only ",
                 "struct","","");
      TParseContext__recover();
    }
    local_868 = (unsigned char *)puVar52[6];
    local_864 = (unsigned char *)puVar52[7];
    local_860 = (unsigned char *)puVar52[8];
    local_85c = (unsigned char *)puVar52[9];
    local_858 = (unsigned char *)puVar52[10];
    psVar4 = local_878;
    local_870 = (unsigned char *)puVar52[4];
    local_86c = (unsigned char *)
                (uint)((uint)((*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4) >> 2)
                      < 4);
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x9d:
    local_85c = (unsigned char *)(puVar52[2] + 0xc);
    local_830 = (unsigned char *)0xe;
    local_828 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x0;
    local_82c = (unsigned char *)
                (uint)((uint)((*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4) >> 2)
                      < 4);
    local_820 = (unsigned char *)0x0;
    local_858 = (unsigned char *)*puVar52;
    local_870 = (unsigned char *)0xe;
    local_868 = (unsigned char *)0x1;
    local_860 = (unsigned char *)0x0;
    local_850 = (unsigned char *)0xe;
    local_848 = (unsigned char *)0x1;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_864 = (unsigned char *)0x0;
    local_86c = local_82c;
    local_84c = local_82c;
    local_83c = local_85c;
    local_838 = local_858;
    local_81c = local_85c;
    local_818 = local_858;
    break;
  case 0x9e:
    uVar20 = GetGlobalPoolAllocator();
    pTVar15 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    uVar59 = puVar52[-7];
    std__string__string((unsigned char *)&local_850,(unsigned char *)puVar52[-0x20]);
    std__string__string((unsigned char *)&local_840,(unsigned char *)&local_850);
    local_5c = -0x5847c8b4;
    *(undefined ***)pTVar15 = &PTR__TType_a7b7d640;
    *(undefined4 *)(pTVar15 + 0x20) = 0;
    *(uint *)(pTVar15 + 0x24) = *(uint *)(pTVar15 + 0x24) & 0x9ff | 0x700800;
    *(undefined4 *)(pTVar15 + 4) = 0;
    *(uint *)(pTVar15 + 8) = uVar59;
    *(undefined4 *)(pTVar15 + 0xc) = 0;
    *(undefined4 *)(pTVar15 + 0x14) = 0;
    *(undefined4 *)(pTVar15 + 0x1c) = 0;
    uVar19 = TType__setStructSize(pTVar15);
    psVar4 = local_83c;
    local_64 = -0x5847c8b4;
    *(undefined4 *)(pTVar15 + 0x18) = uVar19;
    local_83c[*(int *)(local_83c + -0xc)] = *DAT_a7b7ba88;
    uVar20 = GetGlobalPoolAllocator();
    psVar16 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    in_cr0 = (psVar16 == (unsigned char *)0x0) << 1;
    psVar18 = (unsigned char *)0x0;
    if (psVar16 != (unsigned char *)0x0) {
      local_210[0] = GetGlobalPoolAllocator();
      std__string__string(psVar16,(char *)psVar4,(unsigned char *)local_210);
      psVar18 = psVar16;
    }
    *(unsigned char **)(pTVar15 + 0x10) = psVar18;
    psVar4 = local_83c + -4;
    local_200 = local_840;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar4 = local_84c + -4;
    local_1f0 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_84c + -0xc));
    }
    uVar20 = GetGlobalPoolAllocator();
    piVar63 = (int *)TPoolAllocator__allocate(uVar20);
    puVar7 = PTR_vtable_a7b7c0b4 + 8;
    piVar63[1] = puVar52[-0x20];
    *piVar63 = (int)puVar7;
    iVar38 = *(int *)(pTVar15 + 0xc);
    iVar36 = *(int *)(pTVar15 + 0x10);
    iVar34 = *(int *)(pTVar15 + 0x14);
    iVar31 = *(int *)(pTVar15 + 0x18);
    iVar8 = *(int *)(pTVar15 + 0x1c);
    iVar62 = *(int *)(pTVar15 + 0x20);
    iVar55 = *(int *)(pTVar15 + 4);
    iVar6 = *(int *)(pTVar15 + 8);
    piVar63[3] = local_5c + -0x610c;
    piVar63[6] = iVar38;
    piVar63[7] = iVar36;
    piVar63[8] = iVar34;
    piVar63[9] = iVar31;
    piVar63[10] = iVar8;
    piVar63[0xb] = iVar62;
    piVar63[4] = iVar55;
    piVar63[5] = iVar6;
    uVar3 = piVar63[0xc];
    uVar54 = *(uint *)(pTVar15 + 0x24) & 0xfe000000;
    piVar63[0xc] = uVar54 | uVar3 & 0x1ffffff;
    uVar57 = (*(uint *)(pTVar15 + 0x24) >> 0x13 & 0x3f) << 0x13;
    piVar63[0xc] = uVar57 | uVar54 | uVar3 & 0x7ffff;
    uVar59 = *(uint *)(pTVar15 + 0x24) & 0x7f800;
    piVar63[0xc] = uVar59 | uVar57 | uVar54 | uVar3 & 0x7ff;
    uVar61 = (*(uint *)(pTVar15 + 0x24) >> 10 & 1) << 10;
    piVar63[0xc] = uVar61 | uVar59 | uVar57 | uVar54 | uVar3 & 0x3ff;
    piVar63[0xc] = (*(uint *)(pTVar15 + 0x24) >> 9 & 1) << 9 |
                   uVar61 | uVar59 | uVar57 | uVar54 | uVar3 & 0x1ff;
    piVar63[0xd] = 1;
    piVar63[0xe] = 0;
    piVar63[0xf] = 0;
    iVar55 = *(int *)(*(int *)((int)param_1 + 4) + 0xc) + 1;
    *(int *)(*(int *)((int)param_1 + 4) + 0xc) = iVar55;
    piVar63[2] = iVar55;
    local_84c = (unsigned char *)0x0;
    psVar4 = (unsigned char *)(**(code **)(*piVar63 + 8))();
    std__string__string((unsigned char *)&local_1e0,psVar4);
    local_1d8 = piVar63;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_840);
    local_850 = local_840;
    piVar63 = (int *)(local_1dc + -4);
    local_84c = local_83c;
    local_1d0 = local_1e0;
    do {
      iVar55 = *piVar63;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,piVar63);
        *piVar63 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_1dc + -0xc));
    }
    if (local_84c == (unsigned char *)0x0) {
      uVar59 = puVar52[-0x20];
      iVar55 = *(int *)(uVar59 + 4);
      *(unsigned char *)(iVar55 + *(int *)(iVar55 + -0xc)) = *DAT_a7b7ba88;
      TParseContext__error
                ((int)param_1,(char *)puVar52[-0x21],"redefinition",*(char **)(uVar59 + 4),"struct")
      ;
      TParseContext__recover();
    }
    local_82c = (unsigned char *)0x0;
    local_830 = (unsigned char *)0xe;
    local_828 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x0;
    local_820 = (unsigned char *)0x0;
    local_858 = (unsigned char *)puVar52[-0x2c];
    local_870 = (unsigned char *)0xe;
    local_868 = (unsigned char *)0x1;
    local_860 = (unsigned char *)0x0;
    local_850 = (unsigned char *)0xe;
    local_84c = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x1;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_86c = (unsigned char *)0x0;
    local_864 = (unsigned char *)0x0;
    psVar4 = local_878;
    local_85c = (unsigned char *)pTVar15;
    local_83c = (unsigned char *)pTVar15;
    local_838 = local_858;
    local_81c = (unsigned char *)pTVar15;
    local_818 = local_858;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0x9f:
    uVar20 = GetGlobalPoolAllocator();
    pTVar15 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    uVar59 = puVar52[-7];
    local_1c0[0] = GetGlobalPoolAllocator();
    std__string__string((unsigned char *)&local_850,"",(unsigned char *)local_1c0);
    std__string__string((unsigned char *)&local_840,(unsigned char *)&local_850);
    local_5c = -0x5847c8b4;
    *(undefined ***)pTVar15 = &PTR__TType_a7b7d640;
    *(undefined4 *)(pTVar15 + 0x20) = 0;
    *(uint *)(pTVar15 + 0x24) = *(uint *)(pTVar15 + 0x24) & 0x9ff | 0x700800;
    *(undefined4 *)(pTVar15 + 4) = 0;
    *(uint *)(pTVar15 + 8) = uVar59;
    *(undefined4 *)(pTVar15 + 0xc) = 0;
    *(undefined4 *)(pTVar15 + 0x14) = 0;
    *(undefined4 *)(pTVar15 + 0x1c) = 0;
    uVar19 = TType__setStructSize(pTVar15);
    psVar4 = local_83c;
    *(undefined4 *)(pTVar15 + 0x18) = uVar19;
    local_64 = -0x5847c8b4;
    local_83c[*(int *)(local_83c + -0xc)] = *DAT_a7b7ba88;
    uVar20 = GetGlobalPoolAllocator();
    psVar16 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    in_cr0 = (psVar16 == (unsigned char *)0x0) << 1;
    psVar18 = (unsigned char *)0x0;
    if (psVar16 != (unsigned char *)0x0) {
      local_1b0[0] = GetGlobalPoolAllocator();
      std__string__string(psVar16,(char *)psVar4,(unsigned char *)local_1b0);
      psVar18 = psVar16;
    }
    *(unsigned char **)(pTVar15 + 0x10) = psVar18;
    psVar4 = local_83c + -4;
    local_1a0 = local_840;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_83c + -0xc));
    }
    psVar4 = local_84c + -4;
    local_190 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_84c + -0xc));
    }
    local_830 = (unsigned char *)0xe;
    local_82c = (unsigned char *)0x0;
    local_828 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x0;
    local_820 = (unsigned char *)0x0;
    local_858 = (unsigned char *)puVar52[-0x21];
    local_870 = (unsigned char *)0xe;
    local_868 = (unsigned char *)0x1;
    local_860 = (unsigned char *)0x0;
    local_850 = (unsigned char *)0xe;
    local_84c = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x1;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_86c = (unsigned char *)0x0;
    local_864 = (unsigned char *)0x0;
    psVar4 = local_878;
    local_85c = (unsigned char *)pTVar15;
    local_83c = (unsigned char *)pTVar15;
    local_838 = local_858;
    local_81c = (unsigned char *)pTVar15;
    local_818 = local_858;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0xa1:
    local_870 = (unsigned char *)puVar52[-7];
    for (uVar59 = 0; psVar2 = DAT_a7b7ba88, psVar4 = local_878, psVar18 = local_7f0,
        psVar16 = local_750[0],
        uVar59 < (uint)(*(int *)(puVar52[4] + 8) - *(int *)(puVar52[4] + 4) >> 3);
        uVar59 = uVar59 + 1) {
      uVar54 = 0;
      iVar55 = uVar59 * 8;
      while( true ) {
        puVar22 = *(undefined4 **)(local_870 + 8);
        if ((uint)((int)puVar22 - *(int *)(local_870 + 4) >> 3) <= uVar54) break;
        iVar6 = (**(code **)(**(int **)(*(int *)(local_870 + 4) + uVar54 * 8) + 0x1c))();
        iVar62 = (**(code **)(**(int **)(*(int *)(puVar52[4] + 4) + iVar55) + 0x1c))();
        uVar57 = *(uint *)(*(int *)(iVar6 + 4) + -0xc);
        local_78 = uVar57;
        uVar61 = *(uint *)(*(int *)(iVar62 + 4) + -0xc);
        local_74[0] = uVar61;
        puVar27 = local_74;
        if (uVar57 <= uVar61) {
          puVar27 = &local_78;
        }
        iVar6 = _memcmp(*(void **)(iVar6 + 4),*(void **)(iVar62 + 4),*puVar27);
        in_cr0 = (iVar6 == 0) << 1;
        if (iVar6 == 0) {
          iVar6 = uVar57 - uVar61;
        }
        if (iVar6 == 0) {
          iVar6 = (**(code **)(**(int **)(*(int *)(puVar52[4] + 4) + iVar55) + 0x1c))();
          *(unsigned char *)(*(int *)(iVar6 + 4) + *(int *)(*(int *)(iVar6 + 4) + -0xc)) = *psVar2;
          TParseContext__error
                    ((int)param_1,*(char **)(*(int *)(puVar52[4] + 4) + iVar55 + 4),
                     "duplicate field name in structure:","struct",*(undefined4 *)(iVar6 + 4));
          TParseContext__recover();
        }
        uVar54 = uVar54 + 1;
      }
      if (puVar22 == *(undefined4 **)(local_870 + 0xc)) {
        std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux();
      }
      else {
        if (puVar22 != (undefined4 *)0x0) {
          uVar19 = *(undefined4 *)(*(int *)(puVar52[4] + 4) + iVar55 + 4);
          *puVar22 = *(undefined4 *)(*(int *)(puVar52[4] + 4) + iVar55);
          puVar22[1] = uVar19;
        }
        *(int *)(local_870 + 8) = *(int *)(local_870 + 8) + 8;
      }
    }
    break;
  case 0xa2:
    local_870 = (unsigned char *)puVar52[-7];
    pTVar17 = (unsigned char *)(**(code **)(*(int *)**(undefined4 **)(puVar52[-7] + 4) + 0x1c))();
    iVar55 = TParseContext__voidErrorCheck((int)param_1,(unsigned char *)puVar52[-0xc],pTVar17);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    for (uVar59 = 0; psVar4 = local_878, psVar18 = local_7f0, psVar16 = local_750[0],
        uVar59 < (uint)(*(int *)(local_870 + 8) - *(int *)(local_870 + 4) >> 3); uVar59 = uVar59 + 1
        ) {
      piVar63 = *(int **)(*(int *)(local_870 + 4) + uVar59 * 8);
      (**(code **)(*piVar63 + 0xc))
                (piVar63,puVar52[-0x12],puVar52[-0x10],puVar52[-0xf],puVar52[-0xd]);
      if ((int *)puVar52[-0xd] != (int *)0x0) {
        piVar63 = *(int **)(*(int *)(local_870 + 4) + uVar59 * 8);
        iVar55 = *piVar63;
        uVar19 = (**(code **)(*(int *)puVar52[-0xd] + 0x18))();
        (**(code **)(iVar55 + 0x10))(piVar63,uVar19);
      }
    }
    break;
  case 0xa3:
    uVar20 = GetGlobalPoolAllocator();
    psVar18 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    in_cr0 = (psVar18 == (unsigned char *)0x0) << 1;
    psVar4 = (unsigned char *)0x0;
    if (psVar18 != (unsigned char *)0x0) {
      local_180 = GetGlobalPoolAllocator();
      *(int *)(psVar18 + 0xc) = 0;
      *(int *)psVar18 = local_180;
      *(int *)(psVar18 + 4) = 0;
      *(int *)(psVar18 + 8) = 0;
      psVar4 = psVar18;
    }
    goto LAB_97baadbc;
  case 0xa4:
    psVar4 = local_870;
LAB_97baadbc:
    local_870 = psVar4;
    puVar27 = *(uint **)(local_870 + 8);
    if (puVar27 == *(uint **)(local_870 + 0xc)) {
      std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux();
      psVar4 = local_878;
      psVar18 = local_7f0;
      psVar16 = local_750;
    }
    else {
      iVar55 = 0;
      if (puVar27 != (uint *)0x0) {
        uVar59 = puVar52[5];
        *puVar27 = puVar52[4];
        puVar27[1] = uVar59;
        iVar55 = *(int *)(local_870 + 8);
      }
      *(int *)(local_870 + 8) = iVar55 + 8;
      psVar4 = local_878;
      psVar18 = local_7f0;
      psVar16 = local_750;
    }
    break;
  case 0xa5:
    uVar20 = GetGlobalPoolAllocator();
    psVar4 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    *(undefined ***)psVar4 = &PTR__TType_a7b7d640;
    uVar59 = *(uint *)(psVar4 + 0x24) & 0x9ff | 0x800;
    in_cr0 = (uVar59 == 0) << 1;
    *(int *)(psVar4 + 0x20) = 0;
    *(uint *)(psVar4 + 0x24) = uVar59;
    *(int *)(psVar4 + 4) = 0;
    *(int *)(psVar4 + 8) = 0;
    *(int *)(psVar4 + 0xc) = 0;
    *(int *)(psVar4 + 0x10) = 0;
    *(int *)(psVar4 + 0x14) = 0;
    *(int *)(psVar4 + 0x18) = 0;
    *(int *)(psVar4 + 0x1c) = 0;
    local_86c = (unsigned char *)*puVar52;
    uVar59 = puVar52[1];
    pcVar44 = *(code **)(*(int *)psVar4 + 0x14);
    local_870 = psVar4;
    goto LAB_97baae6c;
  case 0xa6:
    uVar20 = GetGlobalPoolAllocator();
    local_870 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    *(undefined ***)local_870 = &PTR__TType_a7b7d640;
    uVar59 = *(uint *)(local_870 + 0x24) & 0x9ff | 0x800;
    in_cr0 = (uVar59 == 0) << 1;
    *(int *)(local_870 + 0x20) = 0;
    *(uint *)(local_870 + 0x24) = uVar59;
    *(int *)(local_870 + 4) = 0;
    *(int *)(local_870 + 8) = 0;
    *(int *)(local_870 + 0xc) = 0;
    *(int *)(local_870 + 0x10) = 0;
    *(int *)(local_870 + 0x14) = 0;
    *(int *)(local_870 + 0x18) = 0;
    *(int *)(local_870 + 0x1c) = 0;
    local_86c = (unsigned char *)puVar52[-0x21];
    (**(code **)(*(int *)local_870 + 0x14))(local_870,puVar52[-0x20]);
    iVar55 = (**(code **)(*(int *)puVar52[-9] + 0x18))();
    if (iVar55 != 0) {
      piVar63 = (int *)(**(code **)(*(int *)puVar52[-9] + 0x18))();
      iVar55 = (**(code **)(*piVar63 + 0x40))();
      if ((iVar55 == 2) &&
         (iVar55 = (**(code **)(*(int *)puVar52[-9] + 0x18))(), psVar4 = local_870,
         0 < **(int **)(iVar55 + 0x30))) {
        iVar55 = (**(code **)(*(int *)puVar52[-9] + 0x18))();
        iVar55 = **(int **)(iVar55 + 0x30);
        *(uint *)(psVar4 + 0x24) = *(uint *)(psVar4 + 0x24) | 0x200;
        *(int *)(psVar4 + 4) = iVar55;
        psVar4 = local_878;
        psVar18 = local_7f0;
        psVar16 = local_750;
        break;
      }
    }
    uVar59 = puVar52[-0x20];
    local_64 = -0x5847c8b4;
    iVar55 = *(int *)(uVar59 + 4);
    pcVar33 = "structure field array size must be a positive integer";
    *(unsigned char *)(iVar55 + *(int *)(iVar55 + -0xc)) = *DAT_a7b7ba88;
    pcVar35 = *(char **)(uVar59 + 4);
    pcVar64 = (char *)puVar52[-0x16];
    goto LAB_97bab5e8;
  case 0xb1:
    iVar55 = *(int *)((int)param_1 + 4);
    uVar20 = GetGlobalPoolAllocator();
    puVar21 = (ulong *)TPoolAllocator__allocate(uVar20);
    local_170 = GetGlobalPoolAllocator();
    *puVar21 = local_170;
    puVar21[1] = 0;
    puVar22 = (undefined4 *)TPoolAllocator__allocate(local_170);
    puVar21[2] = 0;
    puVar21[1] = (ulong)puVar22;
    *puVar22 = 0;
    *(undefined4 *)(puVar21[1] + 4) = 0;
    *(ulong *)(puVar21[1] + 8) = puVar21[1];
    *(ulong *)(puVar21[1] + 0xc) = puVar21[1];
    piVar63 = *(int **)(iVar55 + 4);
    local_160[0] = puVar21;
    if (piVar63 == *(int **)(iVar55 + 8)) {
      std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                (iVar55,piVar63,local_160);
      psVar4 = local_878;
      psVar18 = local_7f0;
      psVar16 = local_750;
    }
    else {
      iVar6 = 0;
      if (piVar63 != (int *)0x0) {
        *piVar63 = (int)puVar21;
        iVar6 = *(int *)(iVar55 + 4);
      }
      *(int *)(iVar55 + 4) = iVar6 + 4;
      psVar4 = local_878;
      psVar18 = local_7f0;
      psVar16 = local_750;
    }
    break;
  case 0xb2:
    piVar63 = *(int **)((int)param_1 + 4);
    iVar55 = piVar63[1];
    pTVar25 = *(unsigned char **)(*piVar63 + ((iVar55 - *piVar63 & 0xfffffffcU) - 4));
    if (pTVar25 != (unsigned char *)0x0) {
      ((int (*)())TSymbolTableLevel___TSymbolTableLevel)(pTVar25);
      iVar55 = piVar63[1];
    }
    piVar63[1] = iVar55 + -4;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0xb3:
    piVar63 = (int *)puVar52[-0x14];
    psVar4 = (unsigned char *)0x0;
    if (piVar63 != (int *)0x0) {
      (**(code **)(*piVar63 + 0x60))(piVar63,1);
      psVar4 = (unsigned char *)puVar52[-0x14];
      psVar18 = local_7f0;
      psVar16 = local_750;
    }
    break;
  case 0xb8:
    pTVar23 = *(unsigned char **)param_1;
    uVar59 = puVar52[2];
LAB_97bab0ec:
    psVar4 = (unsigned char *)TIntermediate__makeAggregate(pTVar23,uVar59);
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0xb9:
    pTVar23 = *(unsigned char **)param_1;
    pTVar28 = (unsigned char *)puVar52[-9];
    uVar59 = puVar52[2];
    goto LAB_97ba97d8;
  case 0xbc:
    iVar55 = TParseContext__boolErrorCheck((int)param_1,(unsigned char *)puVar52[-0x2c]);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    local_850 = (unsigned char *)puVar52[2];
    local_84c = (unsigned char *)puVar52[3];
    psVar4 = (unsigned char *)
             TIntermediate__addSelection
                       (*(undefined4 *)param_1,puVar52[-0x14],local_850,local_84c,puVar52[-0x2c]);
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0xbd:
  case 0xcc:
    local_874 = puVar52[2];
    psVar4 = (unsigned char *)puVar52[-0x14];
    break;
  case 0xbe:
    psVar4 = (unsigned char *)puVar52[2];
    goto LAB_97bab424;
  case 0xbf:
    local_878 = (unsigned char *)puVar52[2];
    pTVar29 = (unsigned char *)(*(code *)**(undefined4 **)puVar52[2])();
    iVar55 = TParseContext__boolErrorCheck((int)param_1,pTVar29);
    goto LAB_97bab180;
  case 0xc0:
    iVar55 = TParseContext__structQualifierErrorCheck((int)param_1,(unsigned char *)puVar52[-0x16]);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    iVar55 = TParseContext__boolErrorCheck((int)param_1,(unsigned char *)puVar52[-0x16]);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    iVar55 = TParseContext__executeInitializer
                       ((int)param_1,(unsigned char *)puVar52[-0x16],(unsigned char *)puVar52[-0x15],
                        (unsigned char *)(puVar52 + -0x1d),(unsigned char **)puVar52[2]);
    if (iVar55 == 0) goto switchD_97ba39c8_caseD_2;
LAB_97bab1f4:
    TParseContext__recover();
    psVar4 = (unsigned char *)0x0;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0xc1:
    iVar55 = *(int *)((int)param_1 + 4);
    uVar20 = GetGlobalPoolAllocator();
    puVar21 = (ulong *)TPoolAllocator__allocate(uVar20);
    uVar20 = GetGlobalPoolAllocator();
    local_150 = uVar20;
    goto LAB_97bab2e8;
  case 0xc2:
    piVar63 = *(int **)((int)param_1 + 4);
    iVar55 = piVar63[1];
    pTVar25 = *(unsigned char **)(*piVar63 + ((iVar55 - *piVar63 & 0xfffffffcU) - 4));
    if (pTVar25 != (unsigned char *)0x0) {
      ((int (*)())TSymbolTableLevel___TSymbolTableLevel)(pTVar25);
      iVar55 = piVar63[1];
    }
    piVar63[1] = iVar55 + -4;
    iVar55 = 1;
    pTVar23 = *(unsigned char **)param_1;
    pTVar29 = (unsigned char *)puVar52[2];
    pTVar32 = (unsigned char *)puVar52[-0x14];
    goto LAB_97bab2b4;
  case 0xc3:
    goto switchD_97ba39c8_caseD_c3;
  case 0xc4:
    iVar55 = TParseContext__boolErrorCheck((int)param_1,(unsigned char *)*puVar52);
    if (iVar55 != 0) {
      TParseContext__recover();
    }
    pTVar23 = *(unsigned char **)param_1;
    pTVar29 = (unsigned char *)puVar52[-0x35];
    iVar55 = 0;
    pTVar32 = (unsigned char *)puVar52[-0x14];
LAB_97bab2b4:
    local_878 = (unsigned char *)TIntermediate__addLoop(pTVar23,pTVar29,pTVar32,false,iVar55);
    iVar55 = *(int *)((int)param_1 + 0x20);
LAB_97bab40c:
    iVar55 = iVar55 + -1;
    goto LAB_97bab410;
  case 0xc5:
    iVar55 = *(int *)((int)param_1 + 4);
    uVar20 = GetGlobalPoolAllocator();
    puVar21 = (ulong *)TPoolAllocator__allocate(uVar20);
    uVar20 = GetGlobalPoolAllocator();
    local_140 = uVar20;
LAB_97bab2e8:
    *puVar21 = uVar20;
    puVar21[1] = 0;
    puVar22 = (undefined4 *)TPoolAllocator__allocate(uVar20);
    puVar21[2] = 0;
    puVar21[1] = (ulong)puVar22;
    *puVar22 = 0;
    *(undefined4 *)(puVar21[1] + 4) = 0;
    *(ulong *)(puVar21[1] + 8) = puVar21[1];
    *(ulong *)(puVar21[1] + 0xc) = puVar21[1];
    puVar22 = *(undefined4 **)(iVar55 + 4);
    local_160[0] = puVar21;
    if (puVar22 == *(undefined4 **)(iVar55 + 8)) {
      std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                (iVar55,puVar22,local_160);
    }
    else {
      iVar6 = 0;
      if (puVar22 != (undefined4 *)0x0) {
        *puVar22 = puVar21;
        iVar6 = *(int *)(iVar55 + 4);
      }
      *(int *)(iVar55 + 4) = iVar6 + 4;
    }
switchD_97ba39c8_caseD_c3:
    iVar55 = *(int *)((int)param_1 + 0x20) + 1;
LAB_97bab410:
    *(int *)((int)param_1 + 0x20) = iVar55;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0xc6:
    piVar63 = *(int **)((int)param_1 + 4);
    iVar55 = piVar63[1];
    pTVar25 = *(unsigned char **)(*piVar63 + ((iVar55 - *piVar63 & 0xfffffffcU) - 4));
    if (pTVar25 != (unsigned char *)0x0) {
      ((int (*)())TSymbolTableLevel___TSymbolTableLevel)(pTVar25);
      iVar55 = piVar63[1];
    }
    piVar63[1] = iVar55 + -4;
    local_878 = (unsigned char *)TIntermediate__makeAggregate(*(unsigned char **)param_1,puVar52[-0x1f]);
    iVar55 = TIntermediate__addLoop
                       (*(unsigned char **)param_1,(unsigned char *)puVar52[2],
                        (unsigned char *)puVar52[-0x14],SUB41(puVar52[-0x13],0),1);
    local_878 = (unsigned char *)
                TIntermediate__growAggregate
                          (*(unsigned char **)param_1,(unsigned char *)local_878,iVar55);
    piVar63 = (int *)(**(code **)(*(int *)local_878 + 0x1c))();
    (**(code **)(*piVar63 + 0x60))(piVar63,1);
    iVar55 = *(int *)((int)param_1 + 0x20);
    goto LAB_97bab40c;
  case 0xcb:
    psVar4 = (unsigned char *)puVar52[-9];
LAB_97bab424:
    local_874 = 0;
    break;
  case 0xcd:
    if (*(int *)((int)param_1 + 0x20) < 1) {
      TParseContext__error
                ((int)param_1,(char *)puVar52[-0xb],"continue statement only allowed in loops","",""
                );
      TParseContext__recover();
    }
    uVar19 = *(undefined4 *)param_1;
    uVar30 = 0x65;
    goto LAB_97bab644;
  case 0xce:
    if (*(int *)((int)param_1 + 0x20) < 1) {
      TParseContext__error
                ((int)param_1,(char *)puVar52[-0xb],"break statement only allowed in loops","","");
      TParseContext__recover();
    }
    uVar19 = *(undefined4 *)param_1;
    uVar30 = 100;
    goto LAB_97bab644;
  case 0xcf:
    local_878 = (unsigned char *)TIntermediate__addBranch(*(undefined4 *)param_1,99,puVar52[-0xb]);
    iVar55 = (**(code **)(**(int **)((int)param_1 + 0x28) + 0x20))(*(int **)((int)param_1 + 0x28));
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    if (iVar55 == 0) break;
    pcVar64 = (char *)puVar52[-0xb];
    pcVar33 = "non-void function must return a value";
    goto LAB_97bab5e4;
  case 0xd0:
    local_878 = (unsigned char *)
                TIntermediate__addBranch(*(undefined4 *)param_1,99,puVar52[-9],puVar52[-0x16]);
    *(undefined4 *)((int)param_1 + 0x2c) = 1;
    iVar55 = (**(code **)(**(int **)((int)param_1 + 0x28) + 0x20))(*(int **)((int)param_1 + 0x28));
    if (iVar55 == 0) {
      pcVar64 = (char *)puVar52[-0x16];
      pcVar33 = "void function cannot return a value";
    }
    else {
      iVar55 = *(int *)((int)param_1 + 0x28);
      (**(code **)(*(int *)puVar52[-9] + 0x38))(&local_850);
      bVar40 = false;
      if (((*(uint *)(iVar55 + 0x24) & 0x1fffe00) == ((uint)local_82c & 0x1fffe00)) &&
         (*(unsigned char **)(iVar55 + 8) == local_848)) {
        bVar40 = true;
      }
      local_5c = -0x5847c8b4;
      local_850 = (unsigned char *)&PTR__TType_a7b7d640;
      psVar4 = local_878;
      psVar18 = local_7f0;
      psVar16 = local_750;
      if (bVar40) break;
      pcVar64 = (char *)puVar52[-0x16];
      pcVar33 = "function return is not matching type:";
    }
LAB_97bab5e4:
    pcVar35 = "return";
LAB_97bab5e8:
    TParseContext__error((int)param_1,pcVar64,pcVar33,pcVar35,"");
    goto LAB_97bab5f4;
  case 0xd1:
    if (*(int *)((int)param_1 + 0xc) != 1) {
      TParseContext__error
                ((int)param_1,(char *)puVar52[-0xb]," supported in fragment shaders only ","discard"
                 ,"","");
      TParseContext__recover();
    }
    uVar19 = *(undefined4 *)param_1;
    uVar30 = 0x62;
LAB_97bab644:
    psVar4 = (unsigned char *)TIntermediate__addBranch(uVar19,uVar30,puVar52[-0xb]);
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0xd2:
    psVar4 = (unsigned char *)puVar52[2];
    goto LAB_97bab674;
  case 0xd3:
    psVar4 = (unsigned char *)
             TIntermediate__growAggregate
                       (*(unsigned char **)param_1,(unsigned char *)puVar52[-9],puVar52[2]);
LAB_97bab674:
    *(unsigned char **)((int)param_1 + 0x10) = psVar4;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0xd6:
    piVar63 = (int *)puVar52[4];
    piVar56 = *(int **)((int)param_1 + 4);
    (**(code **)(*piVar63 + 8))(piVar63);
    iVar55 = *piVar56;
    iVar6 = (piVar56[1] - iVar55 >> 2) + -1;
    while( true ) {
      iVar62 = *(int *)(iVar55 + iVar6 * 4);
      iVar55 = 0;
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_320);
      if (local_320[0] != *(int *)(iVar62 + 4)) {
        iVar55 = *(int *)(local_320[0] + 0x18);
      }
      iVar6 = iVar6 + -1;
      if ((iVar55 != 0) || (iVar6 < 0)) break;
      iVar55 = *piVar56;
    }
    if (*(int *)(iVar55 + 0x50) != 0) {
      iVar62 = piVar63[1];
      local_64 = -0x5847c8b4;
      iVar6 = *(int *)(iVar62 + 4);
      *(unsigned char *)(iVar6 + *(int *)(iVar6 + -0xc)) = *DAT_a7b7ba88;
      TParseContext__error
                ((int)param_1,(char *)*puVar52,"function already has a body",*(char **)(iVar62 + 4),
                 "");
      TParseContext__recover();
    }
    *(undefined4 *)(iVar55 + 0x50) = 1;
    iVar6 = std__string__compare((char *)piVar63[1]);
    local_58 = piVar63 + 3;
    if (iVar6 == 0) {
      iVar6 = piVar63[5] - piVar63[4] >> 3;
      in_cr0 = (iVar6 == 0) << 1;
      if (0 < iVar6) {
        iVar62 = piVar63[1];
        iVar6 = *(int *)(iVar62 + 4);
        *(unsigned char *)(iVar6 + *(int *)(iVar6 + -0xc)) = *DAT_a7b7ba88;
        TParseContext__error
                  ((int)param_1,(char *)*puVar52,"function cannot take any parameter(s)",
                   *(char **)(iVar62 + 4),"");
        TParseContext__recover();
      }
      iVar6 = (**(code **)(piVar63[7] + 0x20))(piVar63 + 7);
      if (iVar6 != 0) {
        iVar62 = piVar63[1];
        local_64 = -0x5847c8b4;
        iVar6 = *(int *)(iVar62 + 4);
        *(unsigned char *)(iVar6 + *(int *)(iVar6 + -0xc)) = *DAT_a7b7ba88;
        TParseContext__error
                  ((int)param_1,(char *)*puVar52,"function cannot return a value",
                   *(char **)(iVar62 + 4),"");
        TParseContext__recover();
      }
    }
    iVar6 = *(int *)((int)param_1 + 4);
    uVar20 = GetGlobalPoolAllocator();
    puVar21 = (ulong *)TPoolAllocator__allocate(uVar20);
    local_130 = GetGlobalPoolAllocator();
    *puVar21 = local_130;
    puVar21[1] = 0;
    puVar22 = (undefined4 *)TPoolAllocator__allocate(local_130);
    puVar21[2] = 0;
    puVar21[1] = (ulong)puVar22;
    *puVar22 = 0;
    *(undefined4 *)(puVar21[1] + 4) = 0;
    *(ulong *)(puVar21[1] + 8) = puVar21[1];
    *(ulong *)(puVar21[1] + 0xc) = puVar21[1];
    puVar22 = *(undefined4 **)(iVar6 + 4);
    local_160[0] = puVar21;
    if (puVar22 == *(undefined4 **)(iVar6 + 8)) {
      std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                (iVar6,puVar22,local_160);
    }
    else {
      iVar62 = 0;
      if (puVar22 != (undefined4 *)0x0) {
        *puVar22 = puVar21;
        iVar62 = *(int *)(iVar6 + 4);
      }
      *(int *)(iVar6 + 4) = iVar62 + 4;
    }
    *(int *)((int)param_1 + 0x28) = iVar55 + 0x1c;
    *(undefined4 *)((int)param_1 + 0x2c) = 0;
    uVar20 = GetGlobalPoolAllocator();
    pTVar23 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    local_5c = -0x5847c8b4;
    local_850 = (unsigned char *)&PTR__TType_a7b7d640;
    local_82c = (unsigned char *)((uint)local_82c & 0x1ff | 0x80800);
    local_84c = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_838 = (unsigned char *)0x0;
    local_834 = (unsigned char *)0x0;
    local_830 = (unsigned char *)0x0;
    *(undefined4 *)(pTVar23 + 4) = 0;
    *(undefined ***)pTVar23 = &PTR_getLine_a7b7d5d8;
    *(undefined4 *)(pTVar23 + 0xc) = 0;
    *(undefined4 *)(pTVar23 + 0x10) = 0;
    *(undefined4 *)(pTVar23 + 0x14) = 0;
    *(undefined4 *)(pTVar23 + 0x18) = 0;
    *(undefined4 *)(pTVar23 + 0x1c) = 0;
    *(undefined4 *)(pTVar23 + 0x20) = 0;
    *(undefined4 *)(pTVar23 + 0x24) = 0;
    *(undefined ***)(pTVar23 + 8) = &PTR__TType_a7b7d640;
    *(undefined4 *)(pTVar23 + 0x28) = 0;
    uVar59 = *(uint *)(pTVar23 + 0x2c);
    *(uint *)(pTVar23 + 0x2c) = uVar59 & 0x1ffffff;
    *(uint *)(pTVar23 + 0x2c) = uVar59 & 0x7ffff | 0x80000;
    *(uint *)(pTVar23 + 0x2c) = uVar59 & 0x7ff | 0x80800;
    *(uint *)(pTVar23 + 0x2c) = uVar59 & 0x3ff | 0x80800;
    puVar7 = PTR_vtable_a7b7c0d0;
    *(uint *)(pTVar23 + 0x2c) = uVar59 & 0x1ff | 0x80800;
    *(undefined **)pTVar23 = puVar7 + 8;
    *(undefined4 *)(pTVar23 + 0x30) = 0;
    local_120 = GetGlobalPoolAllocator();
    *(undefined4 *)(pTVar23 + 0x40) = 0;
    *(undefined4 *)(pTVar23 + 0x38) = 0;
    *(undefined4 *)(pTVar23 + 0x3c) = 0;
    *(undefined4 *)(pTVar23 + 0x34) = local_120;
    local_110 = GetGlobalPoolAllocator();
    *(undefined4 *)(pTVar23 + 0x44) = local_110;
    iVar55 = DAT_a7b7ba84;
    *(undefined4 *)(pTVar23 + 0x50) = 0;
    *(undefined4 *)(pTVar23 + 0x48) = 0;
    piVar56 = (int *)(iVar55 + 8);
    *(undefined4 *)(pTVar23 + 0x4c) = 0;
    do {
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(*piVar56 + 1,0,piVar56);
        *piVar56 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    local_100 = GetGlobalPoolAllocator();
    *(int *)(pTVar23 + 0x58) = iVar55 + 0xc;
    *(undefined4 *)(pTVar23 + 0x68) = 0;
    *(undefined4 *)(pTVar23 + 0x5c) = 0;
    *(undefined4 *)(pTVar23 + 0x54) = local_100;
    local_54 = -0x5847c8b4;
    local_68 = &TType__vtable;
    for (iVar55 = 0; iVar55 < local_58[2] - local_58[1] >> 3; iVar55 = iVar55 + 1) {
      iVar62 = piVar63[4];
      iVar6 = iVar55 * 8;
      if (*(int *)(iVar62 + iVar6) == 0) {
        local_d0[0] = GetGlobalPoolAllocator();
        std__string__string((unsigned char *)&local_850,"",(unsigned char *)local_d0);
        iVar6 = TIntermediate__addSymbol
                          (*(int *)param_1,(unsigned char *)0x0,(unsigned char *)&local_850,
                           *(int *)(iVar62 + iVar6 + 4));
        pTVar23 = (unsigned char *)
                  TIntermediate__growAggregate(*(unsigned char **)param_1,pTVar23,iVar6);
        psVar4 = local_84c + -4;
        local_c0 = local_850;
        do {
          iVar6 = *(int *)psVar4;
          if (in_RESERVE != '\0') {
            iVar62 = storeWordConditionalIndexed(iVar6 + -1,0,psVar4);
            *(int *)psVar4 = iVar62;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
        if (iVar6 < 1) {
          std__string___Rep___M_destroy((unsigned char *)(local_84c + -0xc));
        }
      }
      else {
        uVar20 = GetGlobalPoolAllocator();
        piVar24 = (int *)TPoolAllocator__allocate(uVar20);
        puVar7 = PTR_vtable_a7b7c0b4 + 8;
        iVar41 = *(int *)(iVar62 + iVar6 + 4);
        piVar24[1] = *(int *)(iVar62 + iVar6);
        *piVar24 = (int)puVar7;
        iVar42 = *(int *)(iVar41 + 0xc);
        iVar39 = *(int *)(iVar41 + 0x10);
        iVar38 = *(int *)(iVar41 + 0x14);
        iVar36 = *(int *)(iVar41 + 0x18);
        iVar34 = *(int *)(iVar41 + 0x1c);
        iVar31 = *(int *)(iVar41 + 0x20);
        iVar8 = *(int *)(iVar41 + 4);
        iVar43 = *(int *)(iVar41 + 8);
        piVar24[3] = (int)(local_68 + 8);
        piVar24[6] = iVar42;
        piVar24[7] = iVar39;
        piVar24[8] = iVar38;
        piVar24[9] = iVar36;
        piVar24[10] = iVar34;
        piVar24[0xb] = iVar31;
        piVar24[5] = iVar43;
        piVar24[4] = iVar8;
        uVar3 = piVar24[0xc];
        uVar54 = *(uint *)(iVar41 + 0x24) & 0xfe000000;
        piVar24[0xc] = uVar54 | uVar3 & 0x1ffffff;
        uVar57 = (*(uint *)(iVar41 + 0x24) >> 0x13 & 0x3f) << 0x13;
        piVar24[0xc] = uVar57 | uVar54 | uVar3 & 0x7ffff;
        uVar59 = *(uint *)(iVar41 + 0x24) & 0x7f800;
        piVar24[0xc] = uVar59 | uVar57 | uVar54 | uVar3 & 0x7ff;
        uVar61 = (*(uint *)(iVar41 + 0x24) >> 10 & 1) << 10;
        piVar24[0xc] = uVar61 | uVar59 | uVar57 | uVar54 | uVar3 & 0x3ff;
        piVar24[0xc] = (*(uint *)(iVar41 + 0x24) >> 9 & 1) << 9 |
                       uVar61 | uVar59 | uVar57 | uVar54 | uVar3 & 0x1ff;
        piVar24[0xd] = 0;
        piVar24[0xe] = 0;
        piVar24[0xf] = 0;
        iVar8 = *(int *)(*(int *)((int)param_1 + 4) + 0xc) + 1;
        *(int *)(*(int *)((int)param_1 + 4) + 0xc) = iVar8;
        piVar24[2] = iVar8;
        local_84c = (unsigned char *)0x0;
        psVar4 = (unsigned char *)(**(code **)(*piVar24 + 8))();
        std__string__string((unsigned char *)&local_f0,psVar4);
        local_e8 = piVar24;
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_840);
        local_850 = local_840;
        piVar56 = (int *)(local_ec + -4);
        local_84c = local_83c;
        local_e0 = local_f0;
        do {
          iVar8 = *piVar56;
          if (in_RESERVE != '\0') {
            iVar31 = storeWordConditionalIndexed(iVar8 + -1,0,piVar56);
            *piVar56 = iVar31;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
        if (iVar8 < 1) {
          std__string___Rep___M_destroy((unsigned char *)(local_ec + -0xc));
        }
        if (local_84c == (unsigned char *)0x0) {
          iVar31 = piVar24[1];
          iVar8 = *(int *)(iVar31 + 4);
          *(undefined1 *)(iVar8 + *(int *)(iVar8 + -0xc)) = **(undefined1 **)(local_54 + -0x7cc4);
          TParseContext__error
                    ((int)param_1,(char *)*puVar52,"redefinition",*(char **)(iVar31 + 4),"");
          TParseContext__recover();
          (**(code **)(*piVar24 + 4))(piVar24);
        }
        *(undefined4 *)(iVar62 + iVar6) = 0;
        iVar6 = TIntermediate__addSymbol
                          (*(int *)param_1,(unsigned char *)piVar24[2],(unsigned char *)piVar24[1],
                           (int)(piVar24 + 3));
        pTVar23 = (unsigned char *)
                  TIntermediate__growAggregate(*(unsigned char **)param_1,pTVar23,iVar6);
      }
    }
    TIntermediate__setAggregateOperator(*(undefined4 *)param_1,pTVar23,4,*puVar52);
    puVar52[2] = (uint)pTVar23;
    *(undefined4 *)((int)param_1 + 0x20) = 0;
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
    break;
  case 0xd7:
    local_64 = -0x5847c8b4;
    iVar55 = (**(code **)(**(int **)((int)param_1 + 0x28) + 0x20))();
    if ((iVar55 != 0) && (local_64 = -0x5847c8b4, *(int *)((int)param_1 + 0x2c) == 0)) {
      iVar6 = *(int *)(puVar52[-0x12] + 4);
      iVar55 = *(int *)(iVar6 + 4);
      *(unsigned char *)(iVar55 + *(int *)(iVar55 + -0xc)) = *DAT_a7b7ba88;
      TParseContext__error
                ((int)param_1,(char *)puVar52[-0x16],"function does not return a value",
                 *(char **)(iVar6 + 4),"");
      TParseContext__recover();
    }
    piVar63 = *(int **)((int)param_1 + 4);
    iVar55 = piVar63[1];
    pTVar25 = *(unsigned char **)(*piVar63 + ((iVar55 - *piVar63 & 0xfffffffcU) - 4));
    if (pTVar25 != (unsigned char *)0x0) {
      ((int (*)())TSymbolTableLevel___TSymbolTableLevel)(pTVar25);
      iVar55 = piVar63[1];
    }
    piVar63[1] = iVar55 + -4;
    local_878 = (unsigned char *)
                TIntermediate__growAggregate
                          (*(unsigned char **)param_1,(unsigned char *)puVar52[-0x14],puVar52[2]);
    TIntermediate__setAggregateOperator(*(undefined4 *)param_1,local_878,3,puVar52[-0x16]);
    iVar55 = (**(code **)(*(int *)puVar52[-0x12] + 8))();
    *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
         **(undefined1 **)(local_64 + -0x7cc4);
    pcVar64 = *(char **)(iVar55 + 4);
    local_b0[0] = GetGlobalPoolAllocator();
    std__string__string((unsigned char *)&local_850,pcVar64,(unsigned char *)local_b0);
    piVar63 = (int *)(**(code **)(*(int *)local_878 + 0x1c))();
    (**(code **)(*piVar63 + 0x68))(piVar63,(unsigned char *)&local_850);
    psVar4 = local_84c + -4;
    local_a0 = local_850;
    do {
      iVar55 = *(int *)psVar4;
      if (in_RESERVE != '\0') {
        iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,psVar4);
        *(int *)psVar4 = iVar6;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      std__string___Rep___M_destroy((unsigned char *)(local_84c + -0xc));
    }
    uVar59 = puVar52[-0x12];
    piVar63 = (int *)(**(code **)(*(int *)local_878 + 0x1c))();
    (**(code **)(*piVar63 + 0x34))(piVar63,uVar59 + 0x1c);
    iVar55 = (**(code **)(*(int *)local_878 + 0x1c))();
    *(undefined4 *)(iVar55 + 0x60) = *(undefined4 *)((int)param_1 + 0x40);
    iVar55 = (**(code **)(*(int *)local_878 + 0x1c))();
    *(undefined4 *)(iVar55 + 100) = *(undefined4 *)((int)param_1 + 0x44);
    pTVar26 = (unsigned char *)(**(code **)(*(int *)local_878 + 0x1c))();
    TIntermAggregate__addToPragmaTable(pTVar26);
    psVar4 = local_878;
    psVar18 = local_7f0;
    psVar16 = local_750;
  }
switchD_97ba39c8_caseD_0:
  local_750[0] = psVar16;
  local_7f0 = psVar18;
  local_878 = psVar4;
  psVar51 = psVar51 + -iVar58;
  puVar52 = puVar52 + iVar58 * -0xb + 0xb;
  _memcpy(puVar52,&local_880,0x2c);
  uVar59 = (int)*(short *)(&DAT_97c36138 +
                          *(short *)(
                                    " !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^"
                                    + local_6c + 0x40) * 2) + (int)*psVar51;
  if ((uVar59 < 0x4f0) &&
     (iVar55 = uVar59 * 2, (int)*(short *)(&_yycheck + iVar55) == (int)*psVar51)) {
    iVar55 = (int)*(short *)(&_yytable + iVar55);
  }
  else {
    iVar55 = (int)*(short *)(&DAT_97c35e08 +
                            *(short *)(
                                      " !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^"
                                      + local_6c + 0x40) * 2);
  }
  goto LAB_97ba3784;
LAB_97ba8338:
  iVar62 = *(int *)(iVar55 + iVar6 * 4);
  iVar55 = 0;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_320);
  if (local_320[0] != *(int *)(iVar62 + 4)) {
    iVar55 = *(int *)(local_320[0] + 0x18);
  }
  iVar6 = iVar6 + -1;
  if (iVar55 == 0) {
    if (-1 < iVar6) goto LAB_97ba8334;
  }
  else {
    uVar59 = puVar52[-7];
    bVar40 = false;
    if (((*(uint *)(iVar55 + 0x40) & 0x1fffe00) == (*(uint *)(uVar59 + 0x40) & 0x1fffe00)) &&
       (*(int *)(iVar55 + 0x24) == *(int *)(uVar59 + 0x24))) {
      bVar40 = true;
    }
    if (!bVar40) {
      pcVar64 = (char *)TType__getBasicString(*(uint *)(uVar59 + 0x40) >> 0x13 & 0x3f);
      TParseContext__error
                ((int)param_1,(char *)*puVar52,"overloaded functions must have the same return type"
                 ,pcVar64,"");
      TParseContext__recover();
    }
    for (iVar6 = 0; iVar6 < *(int *)(iVar55 + 0x14) - *(int *)(iVar55 + 0x10) >> 3;
        iVar6 = iVar6 + 1) {
      iVar62 = iVar6 * 8;
      iVar8 = (**(code **)(**(int **)(*(int *)(iVar55 + 0x10) + iVar62 + 4) + 0x24))();
      iVar31 = (**(code **)(**(int **)(*(int *)(puVar52[-7] + 0x10) + iVar62 + 4) + 0x24))();
      if (iVar8 != iVar31) {
        pcVar64 = (char *)getQualifierString(*(uint *)(*(int *)(*(int *)(puVar52[-7] + 0x10) +
                                                                iVar62 + 4) + 0x24) >> 0x19);
        TParseContext__error
                  ((int)param_1,(char *)*puVar52,
                   "overloaded functions must have the same parameter qualifiers",pcVar64,"");
        TParseContext__recover();
      }
    }
  }
  goto LAB_97ba84b0;
LAB_97ba8334:
  iVar55 = *piVar63;
  goto LAB_97ba8338;
LAB_97ba84b0:
  psVar18 = (unsigned char *)puVar52[-7];
  local_880 = *puVar52;
  iVar55 = *(int *)(*(int *)((int)param_1 + 4) + 0xc) + 1;
  *(int *)(*(int *)((int)param_1 + 4) + 0xc) = iVar55;
  *(int *)(psVar18 + 8) = iVar55;
  local_84c = (unsigned char *)0x0;
  local_870 = psVar18;
  psVar4 = (unsigned char *)(**(code **)(*(int *)psVar18 + 8))(psVar18);
  std__string__string((unsigned char *)&local_310,psVar4);
  local_308 = psVar18;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_840);
  paVar14 = (unsigned char *)(local_30c + -0xc);
  local_850 = local_840;
  piVar63 = (int *)(local_30c + -4);
  local_84c = local_83c;
  local_300 = local_310;
  do {
    iVar55 = *piVar63;
    if (in_RESERVE != '\0') {
      iVar6 = storeWordConditionalIndexed(iVar55 + -1,0,piVar63);
      *piVar63 = iVar6;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  bVar40 = 0 < iVar55;
  goto LAB_97ba869c;
switchD_97ba39c8_caseD_60:
  psVar4 = (unsigned char *)0x0;
  psVar18 = local_7f0;
  psVar16 = local_750;
  goto switchD_97ba39c8_caseD_0;
LAB_97ba55dc:
  if ((uint)(*(int *)(psVar18 + 8) - *(int *)(psVar18 + 4) >> 3) <= uVar59) goto LAB_97ba5740;
  iVar55 = (**(code **)(**(int **)(*(int *)(psVar18 + 4) + uVar59 * 8) + 0x1c))();
  uVar54 = *(uint *)(*(int *)(iVar55 + 4) + -0xc);
  local_90 = uVar54;
  uVar57 = *(uint *)(*(int *)(puVar52[1] + 4) + -0xc);
  local_8c = uVar57;
  puVar27 = &local_8c;
  if (uVar54 <= uVar57) {
    puVar27 = &local_90;
  }
  iVar55 = _memcmp(*(void **)(iVar55 + 4),*(void **)(puVar52[1] + 4),*puVar27);
  in_cr0 = (iVar55 == 0) << 1;
  if (iVar55 == 0) {
    iVar55 = uVar54 - uVar57;
  }
  if (iVar55 != 0) {
    uVar59 = uVar59 + 1;
    goto LAB_97ba55dc;
  }
  (**(code **)(*(int *)puVar52[-0x14] + 0x38))(&local_850);
  psVar4 = (unsigned char *)(local_5c - 0x610c);
  local_850 = psVar4;
  if ((uint)local_82c >> 0x19 == 2) {
    local_878 = (unsigned char *)
                TParseContext__addConstStruct(param_1,(unsigned char *)puVar52[1],puVar52[-0x14]);
    if (local_878 == (unsigned char *)0x0) goto LAB_97ba5554;
    (**(code **)(*(int *)local_878 + 0x34))
              (local_878,*(undefined4 *)(*(int *)(psVar18 + 4) + uVar59 * 8));
    psVar4 = (unsigned char *)(**(code **)(*(int *)local_878 + 0x3c))();
    uVar59 = 2;
    pcVar44 = *(code **)(*(int *)psVar4 + 0x28);
  }
  else {
    uVar20 = GetGlobalPoolAllocator();
    pTVar11 = (unsigned char *)TPoolAllocator__allocate(uVar20);
    *(uint *)pTVar11 = uVar59;
    local_81c = (unsigned char *)0x0;
    local_818 = (unsigned char *)0x0;
    local_7fc = (unsigned char *)((uint)local_7fc & 0x9ff | 0x4100800);
    local_814 = (unsigned char *)0x0;
    local_810 = (unsigned char *)0x0;
    local_80c = (unsigned char *)0x0;
    local_808 = (unsigned char *)0x0;
    local_804 = (unsigned char *)0x0;
    local_800 = (unsigned char *)0x0;
    local_820 = psVar4;
    uVar19 = TIntermediate__addConstantUnion(*(unsigned char **)param_1,pTVar11,(int)&local_820);
    local_820 = psVar4;
    psVar4 = (unsigned char *)
             TIntermediate__addIndex
                       (*(undefined4 *)param_1,0x2f,puVar52[-0x14],uVar19,puVar52[-0xb]);
    uVar59 = *(uint *)(*(int *)(psVar18 + 4) + uVar59 * 8);
    pcVar44 = *(code **)(*(int *)psVar4 + 0x34);
    local_878 = psVar4;
  }
LAB_97baae6c:
  (*pcVar44)(psVar4,uVar59);
  psVar4 = local_878;
  psVar18 = local_7f0;
  psVar16 = local_750;
  goto switchD_97ba39c8_caseD_0;
LAB_97ba5740:
  uVar59 = puVar52[1];
  iVar55 = *(int *)(uVar59 + 4);
  pcVar64 = " no such field in structure";
LAB_97ba5784:
  local_64 = -0x5847c8b4;
  *(unsigned char *)(iVar55 + *(int *)(iVar55 + -0xc)) = *DAT_a7b7ba88;
  pcVar35 = *(char **)(uVar59 + 4);
  pcVar33 = (char *)puVar52[-0xb];
LAB_97ba5548:
  TParseContext__error((int)param_1,pcVar33,pcVar64,pcVar35,"");
  goto LAB_97ba5554;
}

/* yylex @ 0x97bac120 (4128 bytes) */
int yylex(param_1, param_2)
  unsigned char * param_1;
  void *param_2;
{
  int iVar1;
  byte *pbVar2;
  unsigned char * psVar3;
  long lVar4;
  ulong uVar5;
  unsigned char * psVar6;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  int iVar11;
  char *pcVar12;
  byte *pbVar13;
  double dVar14;
  undefined4 local_70 [4];
  undefined4 local_60 [6];
  
  if (_yy_init != 0) {
    _yy_init = 0;
    if (_yy_start == 0) {
      _yy_start = 1;
    }
    if (_yyin == (unsigned char *)0x0) {
      _yyin = (unsigned char *)PTR_DAT_a7b7c0bc;
    }
    if (_yyout == (FILE *)0x0) {
      _yyout = (FILE *)(PTR_DAT_a7b7c0bc + 0x58);
    }
    if (_yy_current_buffer == (unsigned char *)0x0) {
      _yy_current_buffer = (unsigned char *)((int (*)())yy_create_buffer)(_yyin,0x4000);
    }
    ((int (*)())yy_load_buffer_state)();
  }
switchD_97bac34c_caseD_1:
  *_yy_c_buf_p = _yy_hold_char;
  pbVar10 = _yy_c_buf_p;
  iVar11 = _yy_start;
LAB_97bac214:
  iVar8 = iVar11 << 1;
  do {
    uVar9 = (uint)(byte)(DAT_97c37983)[(uint)*_yy_c_buf_p * 4];
    if (*(short *)(&_yy_accept + iVar8) != 0) {
      _yy_last_accepting_cpos = _yy_c_buf_p;
      _yy_last_accepting_state = iVar11;
    }
    while (iVar1 = ((int)*(short *)(&_yy_base + iVar8) + uVar9) * 2,
          *(short *)(&_yy_chk + iVar1) != iVar11) {
      iVar11 = (int)*(short *)(&_yy_def + iVar8);
      iVar8 = iVar11 << 1;
      if (0x199 < iVar11) {
        uVar9 = (uint)(byte)(DAT_97c37d83)[uVar9 * 4];
      }
    }
    iVar11 = (int)*(short *)(&_yy_nxt + iVar1);
    _yy_c_buf_p = _yy_c_buf_p + 1;
    iVar8 = iVar11 * 2;
  } while (*(short *)(&_yy_base + iVar8) != 0x260);
LAB_97bac2e4:
  iVar11 = (int)*(short *)(&_yy_accept + iVar8);
  pbVar13 = _yy_c_buf_p;
  if (iVar11 == 0) {
    iVar11 = (int)*(short *)(&_yy_accept + _yy_last_accepting_state * 2);
    pbVar13 = _yy_last_accepting_cpos;
  }
  _yyleng = (int)pbVar13 - (int)pbVar10;
  _yy_hold_char = *pbVar13;
  _yytext = pbVar10;
  *pbVar13 = 0;
  _yy_c_buf_p = pbVar13;
LAB_97bac330:
  pcVar12 = _yylineno;
  pbVar2 = _yytext;
  switch(iVar11) {
  case 0:
    goto switchD_97bac34c_caseD_0;
  case 1:
  case 0x8d:
  case 0x8e:
    goto switchD_97bac34c_caseD_1;
  case 2:
    uVar7 = 0x101;
    *(char **)param_1 = _yylineno;
    break;
  case 3:
    uVar7 = 0x102;
    *(char **)param_1 = _yylineno;
    break;
  case 4:
    uVar7 = 0x11d;
    *(char **)param_1 = _yylineno;
    break;
  case 5:
    uVar7 = 0x11e;
    *(char **)param_1 = _yylineno;
    break;
  case 6:
    uVar7 = 0x106;
    *(char **)param_1 = _yylineno;
    break;
  case 7:
    uVar7 = 0x107;
    *(char **)param_1 = _yylineno;
    break;
  case 8:
    uVar7 = 0x108;
    *(char **)param_1 = _yylineno;
    break;
  case 9:
    uVar7 = 0x10a;
    *(char **)param_1 = _yylineno;
    break;
  case 10:
    uVar7 = 0x121;
    *(char **)param_1 = _yylineno;
    break;
  case 0xb:
    uVar7 = 0x10b;
    *(char **)param_1 = _yylineno;
    break;
  case 0xc:
    uVar7 = 0x109;
    *(char **)param_1 = _yylineno;
    break;
  case 0xd:
    uVar7 = 0x11a;
    *(char **)param_1 = _yylineno;
    break;
  case 0xe:
    uVar7 = 0x11b;
    *(char **)param_1 = _yylineno;
    break;
  case 0xf:
    uVar7 = 0x11c;
    *(char **)param_1 = _yylineno;
    break;
  case 0x10:
    uVar7 = 0x104;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x11:
    uVar7 = 0x105;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x12:
    uVar7 = 0x120;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x13:
    uVar7 = 0x103;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x14:
    uVar7 = 0x12e;
    *(undefined4 *)(param_1 + 4) = 1;
    *(char **)param_1 = pcVar12;
    break;
  case 0x15:
    uVar7 = 0x12e;
    *(undefined4 *)(param_1 + 4) = 0;
    *(char **)param_1 = pcVar12;
    break;
  case 0x16:
    uVar7 = 0x10c;
    *(char **)param_1 = _yylineno;
    break;
  case 0x17:
    uVar7 = 0x10d;
    *(char **)param_1 = _yylineno;
    break;
  case 0x18:
    uVar7 = 0x117;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x19:
    uVar7 = 0x118;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x1a:
    uVar7 = 0x119;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x1b:
    uVar7 = 0x114;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x1c:
    uVar7 = 0x115;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x1d:
    uVar7 = 0x116;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x1e:
    uVar7 = 0x111;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x1f:
    uVar7 = 0x112;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x20:
    uVar7 = 0x113;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x21:
    uVar7 = 0x10e;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x22:
    uVar7 = 0x10f;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x23:
    uVar7 = 0x110;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x24:
    uVar7 = 0x122;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x25:
    uVar7 = 0x123;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x26:
    uVar7 = 0x124;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x27:
    uVar7 = 0x125;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x28:
    uVar7 = 0x126;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x29:
    uVar7 = 0x127;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x2a:
    uVar7 = 0x128;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x2b:
    uVar7 = 0x129;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 1;
    break;
  case 0x2c:
    uVar7 = 0x11f;
    *(char **)param_1 = _yylineno;
    break;
  case 0x2d:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x2e:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x2f:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x30:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x31:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x32:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x33:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x34:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x35:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x36:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x37:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x38:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x39:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x3a:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x3b:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x3c:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x3d:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x3e:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x3f:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x40:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x41:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x42:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x43:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x44:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x45:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x46:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x47:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x48:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x49:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x4a:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x4b:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x4c:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x4d:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x4e:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x4f:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x50:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x51:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x52:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x53:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x54:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x55:
    PaReservedWord();
    uVar7 = 0;
    break;
  case 0x56:
    *(char **)param_1 = _yylineno;
    pbVar10 = _yytext;
    uVar5 = GetGlobalPoolAllocator();
    psVar6 = (unsigned char *)TPoolAllocator__allocate(uVar5);
    psVar3 = (unsigned char *)0x0;
    if (psVar6 != (unsigned char *)0x0) {
      local_70[0] = GetGlobalPoolAllocator();
      std__string__string(psVar6,(char *)pbVar10,(unsigned char *)local_70);
      psVar3 = psVar6;
    }
    *(unsigned char **)(param_1 + 4) = psVar3;
    uVar7 = PaIdentOrType(psVar3,param_2,(unsigned char **)(param_1 + 8));
    break;
  case 0x57:
    *(char **)param_1 = _yylineno;
    lVar4 = _strtol((char *)_yytext,(char **)0x0,0);
    *(long *)(param_1 + 4) = lVar4;
    uVar7 = 0x12d;
    break;
  case 0x58:
    *(char **)param_1 = _yylineno;
    lVar4 = _strtol((char *)_yytext,(char **)0x0,0);
    *(long *)(param_1 + 4) = lVar4;
    uVar7 = 0x12d;
    break;
  case 0x59:
    *(char **)param_1 = _yylineno;
    TParseContext__error((int)param_2,_yylineno,"Invalid Octal number.",(char *)_yytext,"","");
    TParseContext__recover();
    uVar7 = 0;
    break;
  case 0x5a:
    *(char **)param_1 = _yylineno;
    lVar4 = _strtol((char *)_yytext,(char **)0x0,0);
    *(long *)(param_1 + 4) = lVar4;
    uVar7 = 0x12d;
    break;
  case 0x5b:
    *(char **)param_1 = _yylineno;
    dVar14 = (double)((double (*)())_glp_strtod)(_yytext,0);
    uVar7 = 300;
    *(float *)(param_1 + 4) = (float)dVar14;
    break;
  case 0x5c:
    *(char **)param_1 = _yylineno;
    dVar14 = (double)((double (*)())_glp_strtod)(_yytext,0);
    uVar7 = 300;
    *(float *)(param_1 + 4) = (float)dVar14;
    break;
  case 0x5d:
    *(char **)param_1 = _yylineno;
    dVar14 = (double)((double (*)())_glp_strtod)(_yytext,0);
    uVar7 = 300;
    *(float *)(param_1 + 4) = (float)dVar14;
    break;
  case 0x5e:
    iVar11 = PaParseComment((int *)param_1,param_2);
    uVar7 = 0;
    if (iVar11 != 0) goto switchD_97bac34c_caseD_1;
    break;
  case 0x5f:
    uVar7 = 0x13d;
    *(char **)param_1 = _yylineno;
    break;
  case 0x60:
    uVar7 = 0x144;
    *(char **)param_1 = _yylineno;
    break;
  case 0x61:
    uVar7 = 0x13b;
    *(char **)param_1 = _yylineno;
    break;
  case 0x62:
    uVar7 = 0x13c;
    *(char **)param_1 = _yylineno;
    break;
  case 99:
    uVar7 = 0x13e;
    *(char **)param_1 = _yylineno;
    break;
  case 100:
    uVar7 = 0x13f;
    *(char **)param_1 = _yylineno;
    break;
  case 0x65:
    uVar7 = 0x140;
    *(char **)param_1 = _yylineno;
    break;
  case 0x66:
    uVar7 = 0x141;
    *(char **)param_1 = _yylineno;
    break;
  case 0x67:
    uVar7 = 0x142;
    *(char **)param_1 = _yylineno;
    break;
  case 0x68:
    uVar7 = 0x143;
    *(char **)param_1 = _yylineno;
    break;
  case 0x69:
    uVar7 = 0x132;
    *(char **)param_1 = _yylineno;
    break;
  case 0x6a:
    uVar7 = 0x133;
    *(char **)param_1 = _yylineno;
    break;
  case 0x6b:
    uVar7 = 0x138;
    *(char **)param_1 = _yylineno;
    break;
  case 0x6c:
    uVar7 = 0x139;
    *(char **)param_1 = _yylineno;
    break;
  case 0x6d:
    uVar7 = 0x13a;
    *(char **)param_1 = _yylineno;
    break;
  case 0x6e:
    uVar7 = 0x134;
    *(char **)param_1 = _yylineno;
    break;
  case 0x6f:
    uVar7 = 0x135;
    *(char **)param_1 = _yylineno;
    break;
  case 0x70:
    uVar7 = 0x136;
    *(char **)param_1 = _yylineno;
    break;
  case 0x71:
    uVar7 = 0x137;
    *(char **)param_1 = _yylineno;
    break;
  case 0x72:
    uVar7 = 0x130;
    *(char **)param_1 = _yylineno;
    break;
  case 0x73:
    uVar7 = 0x131;
    *(char **)param_1 = _yylineno;
    break;
  case 0x74:
    uVar7 = 0x14f;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 0;
    break;
  case 0x75:
    uVar7 = 0x149;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 0;
    break;
  case 0x76:
    uVar7 = 0x14a;
    *(char **)param_1 = _yylineno;
    break;
  case 0x77:
    *(char **)param_1 = _yylineno;
    if (*(int *)((int)param_2 + 0x24) != 0) {
      *(undefined4 *)((int)param_2 + 0x1c) = 0;
    }
    uVar7 = 0x14c;
    break;
  case 0x78:
    uVar7 = 0x14d;
    *(char **)param_1 = _yylineno;
    break;
  case 0x79:
    uVar7 = 0x14e;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x1c) = 0;
    break;
  case 0x7a:
    uVar7 = 0x145;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x24) = 1;
    *(undefined4 *)((int)param_2 + 0x1c) = 0;
    break;
  case 0x7b:
    uVar7 = 0x146;
    *(char **)param_1 = _yylineno;
    *(undefined4 *)((int)param_2 + 0x24) = 0;
    break;
  case 0x7c:
    uVar7 = 0x147;
    *(char **)param_1 = _yylineno;
    break;
  case 0x7d:
    uVar7 = 0x148;
    *(char **)param_1 = _yylineno;
    break;
  case 0x7e:
    uVar7 = 0x14b;
    _yy_start = 3;
    break;
  case 0x7f:
    uVar7 = 0x150;
    *(char **)param_1 = _yylineno;
    break;
  case 0x80:
    uVar7 = 0x151;
    *(char **)param_1 = _yylineno;
    break;
  case 0x81:
    uVar7 = 0x152;
    *(char **)param_1 = _yylineno;
    break;
  case 0x82:
    uVar7 = 0x153;
    *(char **)param_1 = _yylineno;
    break;
  case 0x83:
    uVar7 = 0x154;
    *(char **)param_1 = _yylineno;
    break;
  case 0x84:
    uVar7 = 0x155;
    *(char **)param_1 = _yylineno;
    break;
  case 0x85:
    uVar7 = 0x156;
    *(char **)param_1 = _yylineno;
    break;
  case 0x86:
    uVar7 = 0x157;
    *(char **)param_1 = _yylineno;
    break;
  case 0x87:
    uVar7 = 0x158;
    *(char **)param_1 = _yylineno;
    break;
  case 0x88:
    uVar7 = 0x159;
    *(char **)param_1 = _yylineno;
    break;
  case 0x89:
    uVar7 = 0x15a;
    *(char **)param_1 = _yylineno;
    break;
  case 0x8a:
    uVar7 = 0x15b;
    *(char **)param_1 = _yylineno;
    break;
  case 0x8b:
    uVar7 = 0x15c;
    *(char **)param_1 = _yylineno;
    break;
  case 0x8c:
    _yy_start = 1;
    *(char **)param_1 = _yylineno;
    pbVar10 = _yytext;
    uVar5 = GetGlobalPoolAllocator();
    psVar6 = (unsigned char *)TPoolAllocator__allocate(uVar5);
    psVar3 = (unsigned char *)0x0;
    if (psVar6 != (unsigned char *)0x0) {
      local_60[0] = GetGlobalPoolAllocator();
      std__string__string(psVar6,(char *)pbVar10,(unsigned char *)local_60);
      psVar3 = psVar6;
    }
    *(unsigned char **)(param_1 + 4) = psVar3;
    uVar7 = 0x12f;
    break;
  case 0x8f:
    pcVar12 = *(char **)((int)param_2 + 8);
    TInfoSinkBase__append(pcVar12);
    TInfoSinkBase__append(pcVar12);
    TInfoSinkBase__append(pcVar12);
    uVar7 = 0;
    break;
  case 0x90:
    _fwrite(_yytext,_yyleng,1,_yyout);
    goto switchD_97bac34c_caseD_1;
  case 0x91:
    *pbVar13 = _yy_hold_char;
    if (*(int *)(_yy_current_buffer + 0x24) == 0) {
      _yy_n_chars = *(int *)(_yy_current_buffer + 0x10);
      *(unsigned char **)_yy_current_buffer = _yyin;
      *(int *)(_yy_current_buffer + 0x24) = 1;
    }
    if (_yy_c_buf_p <= (byte *)(*(int *)(_yy_current_buffer + 4) + _yy_n_chars)) {
      _yy_c_buf_p = _yytext + (int)(pbVar13 + (-1 - (int)pbVar2));
      iVar8 = ((int (*)())yy_get_previous_state)();
      iVar11 = ((int (*)())yy_try_NUL_trans)(iVar8);
      if (iVar11 == 0) goto LAB_97bad2c8;
      _yy_c_buf_p = _yy_c_buf_p + 1;
      pbVar10 = _yytext;
      goto LAB_97bac214;
    }
    iVar11 = ((int (*)())yy_get_next_buffer)();
    if (iVar11 == 1) goto LAB_97bad2f8;
    if (iVar11 < 2) {
      if (iVar11 != 0) goto switchD_97bac34c_caseD_1;
      _yy_c_buf_p = _yytext + (int)(pbVar13 + (-1 - (int)pbVar2));
      iVar11 = ((int (*)())yy_get_previous_state)();
      pbVar10 = _yytext;
      goto LAB_97bac214;
    }
    if (iVar11 != 2) goto switchD_97bac34c_caseD_1;
    _yy_c_buf_p = (byte *)(*(int *)(_yy_current_buffer + 4) + _yy_n_chars);
    iVar8 = ((int (*)())yy_get_previous_state)();
    iVar8 = iVar8 << 1;
    pbVar10 = _yytext;
    goto LAB_97bac2e4;
  case 0x92:
  case 0x93:
    *(undefined4 *)((int)param_2 + 0x60) = 1;
    yy_delete_buffer(_yy_current_buffer);
    uVar7 = 0;
    break;
  default:
    yy_fatal_error("fatal flex scanner internal error--no action found");
    goto switchD_97bac34c_caseD_1;
  }
  return uVar7;
LAB_97bad2f8:
  uVar9 = _yy_start - 1;
  _yy_did_buffer_switch_on_eof = 0;
  _yy_c_buf_p = _yytext;
  iVar11 = ((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0) + 0x92;
  goto LAB_97bac330;
switchD_97bac34c_caseD_0:
  *pbVar13 = _yy_hold_char;
  _yytext = pbVar10;
  iVar8 = _yy_last_accepting_state;
  _yy_c_buf_p = _yy_last_accepting_cpos;
LAB_97bad2c8:
  iVar8 = iVar8 << 1;
  pbVar10 = _yytext;
  goto LAB_97bac2e4;
}

/* yy_get_next_buffer @ 0x97bad390 (656 bytes) */
int yy_get_next_buffer()
{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  
  puVar9 = _yytext;
  puVar8 = *(undefined1 **)(_yy_current_buffer + 4);
  if (puVar8 + (int)(_yy_n_chars + 1) < _yy_c_buf_p) {
    yy_fatal_error("fatal flex scanner internal error--end of buffer missed");
  }
  if (*(int *)(_yy_current_buffer + 0x20) == 0) {
    iVar3 = 2 - (uint)((int)_yy_c_buf_p - (int)_yytext == 1);
  }
  else {
    puVar7 = _yy_c_buf_p + (-1 - (int)_yytext);
    puVar10 = puVar7;
    if (0 < (int)puVar7) {
      do {
        uVar1 = *puVar9;
        puVar9 = puVar9 + 1;
        *puVar8 = uVar1;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + -1;
      } while (puVar10 != (undefined1 *)0x0);
    }
    if (*(int *)(_yy_current_buffer + 0x24) == 2) {
      _yy_n_chars = (undefined1 *)0x0;
    }
    else {
      iVar3 = *(int *)(_yy_current_buffer + 0xc) - (int)puVar7;
      iVar2 = _yy_current_buffer;
      puVar9 = _yy_c_buf_p;
      while (iVar3 = iVar3 + -1, _yy_current_buffer = iVar2, _yy_c_buf_p = puVar9, iVar3 < 1) {
        pvVar4 = *(void **)(iVar2 + 4);
        if (*(int *)(iVar2 + 0x14) == 0) {
          *(undefined4 *)(iVar2 + 4) = 0;
        }
        else {
          uVar6 = *(uint *)(iVar2 + 0xc);
          iVar3 = uVar6 << 1;
          if (iVar3 < 1) {
            iVar3 = uVar6 + (uVar6 >> 3);
          }
          *(int *)(iVar2 + 0xc) = iVar3;
          uVar5 = yy_flex_realloc(pvVar4,*(int *)(iVar2 + 0xc) + 2);
          *(undefined4 *)(iVar2 + 4) = uVar5;
        }
        iVar3 = *(int *)(iVar2 + 4);
        if (iVar3 == 0) {
          yy_fatal_error("fatal error - scanner input buffer overflow");
          iVar3 = *(int *)(iVar2 + 4);
        }
        puVar9 = puVar9 + (iVar3 - (int)pvVar4);
        iVar2 = _yy_current_buffer;
        iVar3 = *(int *)(_yy_current_buffer + 0xc) - (int)puVar7;
      }
      if (0x2000 < iVar3) {
        iVar3 = 0x2000;
      }
      _yy_n_chars = (undefined1 *)_yylex_CPP(puVar7 + *(int *)(iVar2 + 4),iVar3);
      if (_yy_n_chars != (undefined1 *)0x0) {
        if (iVar3 <= (int)_yy_n_chars) {
          yy_fatal_error("input buffer overflow, can\'t enlarge buffer because scanner uses REJECT")
          ;
        }
        puVar7[(int)_yy_n_chars + *(int *)(_yy_current_buffer + 4)] = 0x20;
        _yy_n_chars = (undefined1 *)((int)_yy_n_chars + 1);
      }
    }
    *(undefined1 **)(_yy_current_buffer + 0x10) = _yy_n_chars;
    iVar3 = 0;
    if (_yy_n_chars == (undefined1 *)0x0) {
      if (puVar7 == (undefined1 *)0x0) {
        iVar3 = 1;
        ((int (*)())yyrestart)(_yyin);
      }
      else {
        iVar3 = 2;
        *(undefined4 *)(_yy_current_buffer + 0x24) = 2;
      }
    }
    _yy_n_chars = puVar7 + (int)_yy_n_chars;
    _yy_n_chars[*(int *)(_yy_current_buffer + 4)] = 0;
    _yy_n_chars[*(int *)(_yy_current_buffer + 4) + 1] = 0;
    _yytext = *(undefined1 **)(_yy_current_buffer + 4);
  }
  return iVar3;
}

/* yy_get_previous_state @ 0x97bad620 (280 bytes) */
int yy_get_previous_state()
{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = _yy_start;
  for (pbVar3 = _yytext; pbVar3 < _yy_c_buf_p; pbVar3 = pbVar3 + 1) {
    uVar5 = 1;
    if (*pbVar3 != 0) {
      uVar5 = (uint)(byte)(DAT_97c37983)[(uint)*pbVar3 * 4];
    }
    iVar4 = iVar2 * 2;
    if (*(short *)(&_yy_accept + iVar4) != 0) {
      _yy_last_accepting_cpos = pbVar3;
      _yy_last_accepting_state = iVar2;
    }
    while (iVar1 = ((int)*(short *)(&_yy_base + iVar4) + uVar5) * 2,
          *(short *)(&_yy_chk + iVar1) != iVar2) {
      iVar2 = (int)*(short *)(&_yy_def + iVar4);
      iVar4 = iVar2 << 1;
      if (0x199 < iVar2) {
        uVar5 = (uint)(byte)(DAT_97c37d83)[uVar5 * 4];
      }
    }
    iVar2 = (int)*(short *)(&_yy_nxt + iVar1);
  }
  return;
}

/* yy_try_NUL_trans @ 0x97bad738 (184 bytes) */
int yy_try_NUL_trans(param_1)
  int param_1;
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = param_1 * 2;
  uVar2 = 1;
  if (*(short *)(&_yy_accept + iVar3) != 0) {
    _yy_last_accepting_cpos = _yy_c_buf_p;
    _yy_last_accepting_state = param_1;
  }
  while (iVar1 = ((int)*(short *)(&_yy_base + iVar3) + uVar2) * 2,
        *(short *)(&_yy_chk + iVar1) != param_1) {
    param_1 = (int)*(short *)(&_yy_def + iVar3);
    iVar3 = param_1 << 1;
    if (0x199 < param_1) {
      uVar2 = (uint)(byte)(DAT_97c37d83)[uVar2 * 4];
    }
  }
  if (*(short *)(&_yy_nxt + iVar1) == 0x199) {
    return 0;
  }
  return (int)*(short *)(&_yy_nxt + iVar1);
}

/* yyinput @ 0x97bad7f0 (272 bytes) */
int yyinput()
{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  
  *_yy_c_buf_p = _yy_hold_char;
  pbVar1 = _yy_c_buf_p;
  iVar3 = _yytext;
  if (*_yy_c_buf_p == 0) {
    if (_yy_c_buf_p < (byte *)(*(int *)(_yy_current_buffer + 4) + _yy_n_chars)) {
      *_yy_c_buf_p = 0;
    }
    else {
      _yy_c_buf_p = _yy_c_buf_p + 1;
      iVar4 = ((int (*)())yy_get_next_buffer)();
      if (iVar4 == 1) {
        return 0xffffffff;
      }
      if (iVar4 < 2) {
        if (iVar4 == 0) {
          _yy_c_buf_p = pbVar1 + (_yytext - iVar3);
        }
      }
      else if (iVar4 == 2) {
        ((int (*)())yyrestart)(_yyin);
        return 0xffffffff;
      }
    }
  }
  bVar2 = *_yy_c_buf_p;
  *_yy_c_buf_p = 0;
  pbVar1 = _yy_c_buf_p + 1;
  _yy_c_buf_p = _yy_c_buf_p + 1;
  _yy_hold_char = *pbVar1;
  return (uint)bVar2;
}

/* yyrestart @ 0x97bad900 (104 bytes) */
int yyrestart(param_1)
  unsigned char * param_1;
{
  if (_yy_current_buffer == (unsigned char *)0x0) {
    _yy_current_buffer = (unsigned char *)((int (*)())yy_create_buffer)(_yyin,0x4000);
  }
  yy_init_buffer(_yy_current_buffer,param_1);
  ((int (*)())yy_load_buffer_state)();
  return;
}

/* yy_switch_to_buffer @ 0x97bad968 (148 bytes) */
int yy_switch_to_buffer(param_1)
  unsigned char * param_1;
{
  if (_yy_current_buffer != param_1) {
    if (_yy_current_buffer != (unsigned char *)0x0) {
      *_yy_c_buf_p = _yy_hold_char;
      *(undefined1 **)(_yy_current_buffer + 8) = _yy_c_buf_p;
      *(undefined4 *)(_yy_current_buffer + 0x10) = _yy_n_chars;
    }
    _yy_current_buffer = param_1;
    ((int (*)())yy_load_buffer_state)();
    _yy_did_buffer_switch_on_eof = 1;
  }
  return;
}

/* yy_load_buffer_state @ 0x97bad9fc (88 bytes) */
int yy_load_buffer_state()
{
  _yy_n_chars = _yy_current_buffer[4];
  _yy_c_buf_p = (undefined1 *)_yy_current_buffer[2];
  _yytext = _yy_c_buf_p;
  _yyin = *_yy_current_buffer;
  _yy_hold_char = *_yy_c_buf_p;
  return;
}

/* yy_create_buffer @ 0x97bada54 (140 bytes) */
int yy_create_buffer(param_1, param_2)
  unsigned char * param_1;
  int param_2;
{
  unsigned char * pyVar1;
  int iVar2;
  
  pyVar1 = (unsigned char *)yy_flex_alloc(0x28);
  if (pyVar1 == (unsigned char *)0x0) {
    yy_fatal_error("out of dynamic memory in ((int (*)())yy_create_buffer)()");
  }
  *(int *)(pyVar1 + 0xc) = param_2;
  iVar2 = yy_flex_alloc(param_2 + 2);
  *(int *)(pyVar1 + 4) = iVar2;
  if (iVar2 == 0) {
    yy_fatal_error("out of dynamic memory in ((int (*)())yy_create_buffer)()");
  }
  *(undefined4 *)(pyVar1 + 0x14) = 1;
  yy_init_buffer(pyVar1,param_1);
  return pyVar1;
}

