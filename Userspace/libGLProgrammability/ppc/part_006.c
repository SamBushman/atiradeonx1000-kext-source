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
      __ZN13TInfoSinkBase6appendEPKc(piVar3,(char *)piVar3[2]);
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
int _ShAttributeBindingRequest(param_1, param_2, param_3)
  int *param_1;
  ulong param_2;
  char *param_3;
{
  unsigned char * this;
  
  if ((param_1 != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(), this != (unsigned char *)0x0)) {
    TGenericLinker__attributeBindingRequest(this,param_2,param_3);
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
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = 0;
    if (*(unsigned char **)(iVar1 + 4) != (unsigned char *)0x0) {
      uVar2 = BindingTable__GetNumActiveAttributeBindings(*(unsigned char **)(iVar1 + 4));
    }
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
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = 0;
    if (*(unsigned char **)(iVar1 + 4) != (unsigned char *)0x0) {
      uVar2 = BindingTable__GetNumActiveUniformBindings(*(unsigned char **)(iVar1 + 4));
    }
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
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = 0;
    if (*(unsigned char **)(iVar1 + 4) != (unsigned char *)0x0) {
      uVar2 = BindingTable__GetSizeActiveUserUniforms(*(unsigned char **)(iVar1 + 4));
    }
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
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = 0;
    if (*(unsigned char **)(iVar1 + 4) != (unsigned char *)0x0) {
      uVar2 = BindingTable__GetMaxAttributeLength(*(unsigned char **)(iVar1 + 4));
    }
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
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = 0;
    if (*(unsigned char **)(iVar1 + 4) != (unsigned char *)0x0) {
      uVar2 = BindingTable__GetMaxUniformLength(*(unsigned char **)(iVar1 + 4));
    }
  }
  return uVar2;
}

/* _ShGetActiveUniform @ 0x97ba20e8 (132 bytes) */
int _ShGetActiveUniform(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  ulong param_2;
  long param_3;
  long *param_4;
  long *param_5;
  ulong *param_6;
  char *param_7;
{
  unsigned char * this;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(), this != (unsigned char *)0x0)) {
    uVar1 = TGenericLinker__getActiveUniform(this,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}

/* _ShGetUniformTypeInfo @ 0x97ba216c (116 bytes) */
int _ShGetUniformTypeInfo(param_1, param_2, param_3, param_4, param_5)
  int *param_1;
  long param_2;
  long *param_3;
  ulong *param_4;
  uchar *param_5;
{
  unsigned char * this;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(), this != (unsigned char *)0x0)) {
    uVar1 = TGenericLinker__getUniformTypeInfo(this,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}

/* _ShGetActiveAttrib @ 0x97ba21e0 (132 bytes) */
int _ShGetActiveAttrib(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  ulong param_2;
  long param_3;
  long *param_4;
  long *param_5;
  ulong *param_6;
  char *param_7;
{
  unsigned char * this;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(), this != (unsigned char *)0x0)) {
    uVar1 = TGenericLinker__getActiveAttrib(this,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}

/* _ShGetAttribLocation @ 0x97ba2264 (112 bytes) */
int _ShGetAttribLocation(param_1, param_2)
  int *param_1;
  char *param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = 0xffffffff;
    if (*(unsigned char **)(iVar1 + 4) != (unsigned char *)0x0) {
      uVar2 = BindingTable__FindAttribBindingLocationByName(*(unsigned char **)(iVar1 + 4),param_2);
    }
  }
  return uVar2;
}

/* _ShGetUniformLocation @ 0x97ba22d4 (112 bytes) */
int _ShGetUniformLocation(param_1, param_2)
  int *param_1;
  char *param_2;
{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(), iVar1 != 0)) {
    uVar2 = 0xffffffff;
    if (*(unsigned char **)(iVar1 + 4) != (unsigned char *)0x0) {
      uVar2 = BindingTable__FindClientUniformBindingLocationByName
                        (*(unsigned char **)(iVar1 + 4),param_2);
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
  unsigned char * this;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(), this != (unsigned char *)0x0)) {
    uVar1 = TGenericLinker__getStatsString(this);
  }
  return uVar1;
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
  unsigned char * this;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(), this != (unsigned char *)0x0)) {
    uVar1 = TGenericLinker__getPPStreamString(this);
  }
  return uVar1;
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
  unsigned char * this;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(), this != (unsigned char *)0x0)) {
    uVar1 = TGenericLinker__getShaderToProgramString(this);
  }
  return uVar1;
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
  unsigned char * this;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(), this != (unsigned char *)0x0)) {
    uVar1 = TGenericLinker__getTableString(this);
  }
  return uVar1;
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
int TType__buildMangledName(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  ulong uVar2;
  char cVar4;
  size_t sVar3;
  char *pcVar5;
  uint uVar6;
  char acStack_20 [16];
  
  iVar1 = (**(code **)(*(int *)this + 0x34))();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)this + 0x3c))(this);
    if (iVar1 != 0) {
      cVar4 = 'v';
      goto LAB_97ba26e0;
    }
  }
  else {
    cVar4 = 'm';
LAB_97ba26e0:
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(param_2,1,cVar4);
  }
  switch(*(uint *)(this + 0x24) >> 0x13 & 0x3f) {
  default:
    goto switchD_97ba270c_caseD_0;
  case 1:
    cVar4 = 'f';
    goto LAB_97ba2778;
  case 2:
    cVar4 = 'i';
    goto LAB_97ba2778;
  case 3:
    cVar4 = 'b';
LAB_97ba2778:
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(param_2,1,cVar4);
    goto switchD_97ba270c_caseD_0;
  case 5:
    pcVar5 = "s1";
    uVar2 = _strlen("s1");
    break;
  case 6:
    pcVar5 = "s2";
    uVar2 = _strlen("s2");
    break;
  case 7:
    pcVar5 = "s3";
    uVar2 = _strlen("s3");
    break;
  case 8:
    pcVar5 = "sC";
    uVar2 = _strlen("sC");
    break;
  case 9:
    pcVar5 = "sS1";
    uVar2 = _strlen("sS1");
    break;
  case 10:
    pcVar5 = "sS2";
    uVar2 = _strlen("sS2");
    break;
  case 0xb:
    pcVar5 = "sR2";
    uVar2 = _strlen("sR2");
    break;
  case 0xc:
    pcVar5 = "sSR2";
    uVar2 = _strlen("sSR2");
    break;
  case 0xe:
    sVar3 = _strlen("struct-");
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm(param_2,"struct-",sVar3);
    if (*(unsigned char **)(this + 0x10) != (unsigned char *)0x0) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendERKS3_(param_2,*(unsigned char **)(this + 0x10))
      ;
    }
    for (uVar6 = 0;
        uVar6 < (uint)(*(int *)(*(int *)(this + 8) + 8) - *(int *)(*(int *)(this + 8) + 4) >> 3);
        uVar6 = uVar6 + 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(param_2,1,'-');
      ((int (*)())TType__buildMangledName)(*(unsigned char **)(*(int *)(*(int *)(this + 8) + 4) + uVar6 * 8),param_2);
    }
    goto switchD_97ba270c_caseD_0;
  }
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm(param_2,pcVar5,uVar2);
switchD_97ba270c_caseD_0:
  cVar4 = (**(code **)(*(int *)this + 0x2c))(this);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(param_2,1,cVar4 + '0');
  iVar1 = (**(code **)(*(int *)this + 0x38))(this);
  if (iVar1 != 0) {
    _sprintf(acStack_20,"%d",*(undefined4 *)(this + 4));
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(param_2,1,'[');
    sVar3 = _strlen(acStack_20);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm(param_2,acStack_20,sVar3);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(param_2,1,']');
  }
  return;
}

/* TVariable__dump @ 0x97ba295c (220 bytes) */
int TVariable__dump(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  char *pcVar1;
  int iVar2;
  int iVar3;
  unsigned char * this_00;
  
  iVar2 = *(int *)(this + 4);
  this_00 = param_2 + 8;
  iVar3 = *(int *)(iVar2 + 4);
  *(undefined1 *)(iVar3 + *(int *)(iVar3 + -0xc)) = *DAT_a7b7ba80;
  __ZN13TInfoSinkBase6appendEPKc(this_00,*(char **)(iVar2 + 4));
  __ZN13TInfoSinkBase6appendEPKc(this_00,": ");
  pcVar1 = (char *)getQualifierString(*(uint *)(this + 0x30) >> 0x19);
  __ZN13TInfoSinkBase6appendEPKc(this_00,pcVar1);
  __ZN13TInfoSinkBase6appendEPKc(this_00," ");
  pcVar1 = (char *)TType__getBasicString(*(uint *)(this + 0x30) >> 0x13 & 0x3f);
  __ZN13TInfoSinkBase6appendEPKc(this_00,pcVar1);
  if ((*(uint *)(this + 0x30) & 0x200) != 0) {
    __ZN13TInfoSinkBase6appendEPKc(this_00,"[0]");
  }
  __ZN13TInfoSinkBase6appendEPKc(this_00,"\n");
  return;
}

/* TFunction__dump @ 0x97ba2a38 (216 bytes) */
int TFunction__dump(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  undefined1 *puVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  unsigned char * this_00;
  
  puVar1 = DAT_a7b7ba80;
  iVar4 = *(int *)(this + 4);
  this_00 = param_2 + 8;
  iVar2 = *(int *)(iVar4 + 4);
  *(undefined1 *)(iVar2 + *(int *)(iVar2 + -0xc)) = *DAT_a7b7ba80;
  __ZN13TInfoSinkBase6appendEPKc(this_00,*(char **)(iVar4 + 4));
  __ZN13TInfoSinkBase6appendEPKc(this_00,": ");
  pcVar3 = (char *)TType__getBasicString(*(uint *)(this + 0x40) >> 0x13 & 0x3f);
  __ZN13TInfoSinkBase6appendEPKc(this_00,pcVar3);
  __ZN13TInfoSinkBase6appendEPKc(this_00," ");
  iVar2 = (**(code **)(*(int *)this + 8))(this);
  *(undefined1 *)(*(int *)(iVar2 + 4) + *(int *)(*(int *)(iVar2 + 4) + -0xc)) = *puVar1;
  __ZN13TInfoSinkBase6appendEPKc(this_00,*(char **)(iVar2 + 4));
  __ZN13TInfoSinkBase6appendEPKc(this_00,"\n");
  return;
}

/* TSymbolTableLevel__dump @ 0x97ba2b10 (112 bytes) */
int TSymbolTableLevel__dump(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  int local_20 [4];
  
  iVar1 = *(int *)(this + 4);
  local_20[0] = *(int *)(iVar1 + 8);
  while (local_20[0] != iVar1) {
    (**(code **)(**(int **)(local_20[0] + 0x18) + 0x14))(*(int **)(local_20[0] + 0x18),param_2);
    std___Rb_tree_base_iterator___M_increment((unsigned char *)local_20);
    iVar1 = *(int *)(this + 4);
  }
  return;
}

/* TSymbolTable__dump @ 0x97ba2b80 (268 bytes) */
int TSymbolTable__dump(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  unsigned char * this_00;
  int iVar4;
  char in_RESERVE;
  byte bVar5;
  undefined4 local_70;
  int local_6c;
  char acStack_60 [16];
  undefined4 local_50 [4];
  undefined4 local_40 [6];
  
  iVar4 = (*(int *)(this + 4) - *(int *)this >> 2) + -1;
  if (-1 < iVar4) {
    this_00 = param_2 + 8;
    do {
      bVar5 = (iVar4 == 0) << 1;
      __ZN13TInfoSinkBase6appendEPKc(this_00,"LEVEL ");
      _sprintf(acStack_60,"%d",iVar4);
      local_50[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (&local_70,acStack_60,(unsigned char *)local_50);
      __ZN13TInfoSinkBase6appendERKSbIcSt11char_traitsIcE14pool_allocatorIcEE
                (this_00,(unsigned char *)&local_70);
      piVar2 = (int *)(local_6c + -4);
      local_40[0] = local_70;
      do {
        iVar3 = *piVar2;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar3 + -1,0,piVar2);
          *piVar2 = iVar1;
          bVar5 = 2;
        }
      } while (!(bool)(bVar5 >> 1 & 1));
      if (iVar3 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(local_6c + -0xc),local_40);
      }
      __ZN13TInfoSinkBase6appendEPKc(this_00,"\n");
      ((int (*)())TSymbolTableLevel__dump)(*(unsigned char **)(*(int *)this + iVar4 * 4),param_2);
      iVar4 = iVar4 + -1;
    } while (-1 < iVar4);
  }
  return;
}

/* __ZN9TFunctionD2Ev @ 0x97ba2c8c (8 bytes) */
int __ZN9TFunctionD2Ev(this)
  void *this;
{
  ((int (*)())__ZN9TFunctionD4Ev)(this);
  return;
}

/* __ZN9TFunctionD1Ev @ 0x97ba2c94 (8 bytes) */
int __ZN9TFunctionD1Ev(this)
  void *this;
{
  ((int (*)())__ZN9TFunctionD4Ev)(this);
  return;
}

/* __ZN9TFunctionD0Ev @ 0x97ba2c9c (8 bytes) */
int __ZN9TFunctionD0Ev(this)
  void *this;
{
  ((int (*)())__ZN9TFunctionD4Ev)(this);
  return;
}

/* __ZN9TFunctionD4Ev @ 0x97ba2ca4 (236 bytes) */
int __ZN9TFunctionD4Ev(this)
  void *this;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_20 [5];
  
  iVar4 = *(int *)((int)this + 0x10);
  *(int *)this = DAT_a7b7ba7c + 8;
  iVar2 = *(int *)((int)this + 0x14);
  for (; iVar4 != iVar2; iVar4 = iVar4 + 8) {
    if (*(int **)(iVar4 + 4) != (int *)0x0) {
      (**(code **)(**(int **)(iVar4 + 4) + 4))();
      iVar2 = *(int *)((int)this + 0x14);
    }
  }
  iVar2 = *(int *)((int)this + 0x48);
  local_20[0] = *(undefined4 *)((int)this + 0x44);
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
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
              ((unsigned char *)(iVar2 + -0xc),local_20);
  }
  iVar2 = *(int *)((int)this + 0x10);
  *(undefined ***)((int)this + 0x1c) = &PTR___ZN5TTypeD1Ev_a7b7d590;
  for (; iVar2 != *(int *)((int)this + 0x14); iVar2 = iVar2 + 8) {
  }
  *(undefined ***)this = &PTR___ZN7TSymbolD1Ev_a7b7d568;
  return;
}

/* __ZN17TSymbolTableLevelD2Ev @ 0x97ba2d90 (8 bytes) */
int __ZN17TSymbolTableLevelD2Ev(this)
  void *this;
{
  ((int (*)())__ZN17TSymbolTableLevelD4Ev)(this);
  return;
}

/* __ZN17TSymbolTableLevelD1Ev @ 0x97ba2d98 (8 bytes) */
int __ZN17TSymbolTableLevelD1Ev(this)
  void *this;
{
  ((int (*)())__ZN17TSymbolTableLevelD4Ev)(this);
  return;
}

/* __ZN17TSymbolTableLevelD4Ev @ 0x97ba2da0 (184 bytes) */
int __ZN17TSymbolTableLevelD4Ev(this)
  void *this;
{
  int local_30 [4];
  int local_20;
  
  local_20 = *(int *)((int)this + 4);
  local_30[0] = *(int *)(local_20 + 8);
  if (local_30[0] != local_20) {
    do {
      if (*(int **)(local_30[0] + 0x18) != (int *)0x0) {
        (**(code **)(**(int **)(local_30[0] + 0x18) + 4))();
      }
      std___Rb_tree_base_iterator___M_increment((unsigned char *)local_30);
      local_20 = *(int *)((int)this + 4);
    } while (local_30[0] != local_20);
  }
  if (*(int *)((int)this + 8) != 0) {
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol_______M_erase(this,*(unsigned char **)(local_20 + 4));
    *(int *)(*(int *)((int)this + 4) + 8) = *(int *)((int)this + 4);
    *(undefined4 *)(*(int *)((int)this + 4) + 4) = 0;
    *(int *)(*(int *)((int)this + 4) + 0xc) = *(int *)((int)this + 4);
    *(undefined4 *)((int)this + 8) = 0;
  }
  return;
}

/* TSymbolTableLevel__relateToOperator @ 0x97ba2e58 (168 bytes) */
int TSymbolTableLevel__relateToOperator(this, param_2, param_3)
  int this;
  char *param_2;
  undefined4 param_3;
{
  int iVar1;
  int iVar2;
  int local_40 [4];
  int local_30;
  
  local_30 = *(int *)(this + 4);
  local_40[0] = *(int *)(local_30 + 8);
  if (local_40[0] != local_30) {
    do {
      iVar1 = (**(code **)(**(int **)(local_40[0] + 0x18) + 0xc))();
      if (iVar1 != 0) {
        iVar2 = *(int *)(local_40[0] + 0x18);
        iVar1 = __ZNKSbIcSt11char_traitsIcE14pool_allocatorIcEE7compareEPKc
                          (*(void **)(iVar2 + 4),param_2);
        if (iVar1 == 0) {
          *(undefined4 *)(iVar2 + 0x4c) = param_3;
        }
      }
      std___Rb_tree_base_iterator___M_increment((unsigned char *)local_40);
      local_30 = *(int *)(this + 4);
    } while (local_40[0] != local_30);
  }
  return;
}

/* __ZN7TSymbolC2ERKS_ @ 0x97ba2f00 (4 bytes) */
int __ZN7TSymbolC2ERKS_(this, param_2)
  void *this;
  unsigned char * param_2;
{
  undefined4 uVar1;
  void *pvVar2;
  unsigned char * this_00;
  void *this_01;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 auStack_30 [7];
  
  iVar3 = *(int *)(param_2 + 4);
  *(undefined ***)this = &PTR___ZN7TSymbolD1Ev_a7b7d568;
  iVar4 = *(int *)(iVar3 + 4);
  *(undefined1 *)(iVar4 + *(int *)(iVar4 + -0xc)) = *DAT_a7b7ba80;
  pcVar5 = *(char **)(iVar3 + 4);
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  this_01 = (void *)TPoolAllocator__allocate(this_00,8);
  pvVar2 = (void *)0x0;
  if (this_01 != (void *)0x0) {
    auStack_30[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (this_01,pcVar5,(unsigned char *)auStack_30);
    pvVar2 = this_01;
  }
  uVar1 = *(undefined4 *)(param_2 + 8);
  *(void **)((int)this + 4) = pvVar2;
  *(undefined4 *)((int)this + 8) = uVar1;
  return;
}

/* __ZN7TSymbolC1ERKS_ @ 0x97ba2f04 (4 bytes) */
int __ZN7TSymbolC1ERKS_(this, param_2)
  void *this;
  unsigned char * param_2;
{
  undefined4 uVar1;
  void *pvVar2;
  unsigned char * this_00;
  void *this_01;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 auStack_30 [7];
  
  iVar3 = *(int *)(param_2 + 4);
  *(undefined ***)this = &PTR___ZN7TSymbolD1Ev_a7b7d568;
  iVar4 = *(int *)(iVar3 + 4);
  *(undefined1 *)(iVar4 + *(int *)(iVar4 + -0xc)) = *DAT_a7b7ba80;
  pcVar5 = *(char **)(iVar3 + 4);
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  this_01 = (void *)TPoolAllocator__allocate(this_00,8);
  pvVar2 = (void *)0x0;
  if (this_01 != (void *)0x0) {
    auStack_30[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (this_01,pcVar5,(unsigned char *)auStack_30);
    pvVar2 = this_01;
  }
  uVar1 = *(undefined4 *)(param_2 + 8);
  *(void **)((int)this + 4) = pvVar2;
  *(undefined4 *)((int)this + 8) = uVar1;
  return;
}

/* __ZN7TSymbolC4ERKS_ @ 0x97ba2f08 (164 bytes) */
int __ZN7TSymbolC4ERKS_(this, param_2)
  void *this;
  unsigned char * param_2;
{
  undefined4 uVar1;
  void *pvVar2;
  unsigned char * this_00;
  void *this_01;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 local_30 [7];
  
  iVar3 = *(int *)(param_2 + 4);
  *(undefined ***)this = &PTR___ZN7TSymbolD1Ev_a7b7d568;
  iVar4 = *(int *)(iVar3 + 4);
  *(undefined1 *)(iVar4 + *(int *)(iVar4 + -0xc)) = *DAT_a7b7ba80;
  pcVar5 = *(char **)(iVar3 + 4);
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  this_01 = (void *)TPoolAllocator__allocate(this_00,8);
  pvVar2 = (void *)0x0;
  if (this_01 != (void *)0x0) {
    local_30[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(this_01,pcVar5,(unsigned char *)local_30);
    pvVar2 = this_01;
  }
  uVar1 = *(undefined4 *)(param_2 + 8);
  *(void **)((int)this + 4) = pvVar2;
  *(undefined4 *)((int)this + 8) = uVar1;
  return;
}

/* __ZN9TVariableC2ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE @ 0x97ba2fac (4 bytes) */
int __ZN9TVariableC2ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE(this, param_2, param_3)
  void *this;
  unsigned char * param_2;
  unsigned char * param_3;
{
  uint uVar1;
  int iVar2;
  unsigned char * this_00;
  undefined4 *puVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  ((int (*)())__ZN7TSymbolC2ERKS_)(this,(unsigned char *)param_2);
  *(int *)this = DAT_a7b7ba78 + 8;
  *(undefined ***)((int)this + 0xc) = &PTR___ZN5TTypeD1Ev_a7b7d590;
  TType__copyType((unsigned char *)((int)this + 0xc),(unsigned char *)(param_2 + 0xc),param_3);
  iVar2 = *(int *)(param_2 + 0x3c);
  uVar1 = *(uint *)(param_2 + 0x34);
  *(uint *)((int)this + 0x34) = uVar1;
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_2 + 0x38);
    *(undefined4 *)((int)this + 0x3c) = 0;
    uVar1 = 0;
    if (iVar2 == 0) goto LAB_97ba314c;
    uVar1 = *(uint *)(param_2 + 0x14);
    if (uVar1 == 0) {
      uVar1 = *(uint *)(param_2 + 0x30);
      if ((uVar1 & 0x400) == 0) {
        uVar1 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
      }
      else {
        iVar2 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
        uVar1 = iVar2 * iVar2;
      }
      if (uVar1 == 1) {
        this_00 = (unsigned char *)GetGlobalPoolAllocator();
        puVar3 = (undefined4 *)TPoolAllocator__allocate(this_00,4);
        *(undefined4 **)((int)this + 0x38) = puVar3;
        uVar1 = *(uint *)((int)this + 0x30) >> 0x13 & 0x3f;
        if (uVar1 == 2) {
LAB_97ba311c:
          *puVar3 = **(undefined4 **)(param_2 + 0x38);
          return;
        }
        if (uVar1 < 3) {
          if (uVar1 == 1) {
            *puVar3 = **(undefined4 **)(param_2 + 0x38);
            return;
          }
        }
        else if (uVar1 == 3) goto LAB_97ba311c;
        pcVar5 = "false && \"Unknown type\"";
        uVar4 = 0xb9;
      }
      else {
        pcVar5 = "copyOf.type.getInstanceSize() == 1";
        uVar4 = 0xb2;
      }
    }
    else {
      pcVar5 = "!copyOf.type.getStruct()";
      uVar4 = 0xb1;
    }
  }
  else {
    pcVar5 = "copyOf.arrayInformationType == 0";
    uVar4 = 0xad;
  }
  ___eprintf("%s:%u: failed assertion `%s\'\n",
             "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/SymbolTable.cpp"
             ,uVar4,pcVar5);
LAB_97ba314c:
  *(uint *)((int)this + 0x38) = uVar1;
  return;
}

/* __ZN9TVariableC1ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE @ 0x97ba2fb0 (4 bytes) */
int __ZN9TVariableC1ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE(this, param_2, param_3)
  void *this;
  unsigned char * param_2;
  unsigned char * param_3;
{
  uint uVar1;
  int iVar2;
  unsigned char * this_00;
  undefined4 *puVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  ((int (*)())__ZN7TSymbolC2ERKS_)(this,(unsigned char *)param_2);
  *(int *)this = DAT_a7b7ba78 + 8;
  *(undefined ***)((int)this + 0xc) = &PTR___ZN5TTypeD1Ev_a7b7d590;
  TType__copyType((unsigned char *)((int)this + 0xc),(unsigned char *)(param_2 + 0xc),param_3);
  iVar2 = *(int *)(param_2 + 0x3c);
  uVar1 = *(uint *)(param_2 + 0x34);
  *(uint *)((int)this + 0x34) = uVar1;
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_2 + 0x38);
    *(undefined4 *)((int)this + 0x3c) = 0;
    uVar1 = 0;
    if (iVar2 == 0) goto LAB_97ba314c;
    uVar1 = *(uint *)(param_2 + 0x14);
    if (uVar1 == 0) {
      uVar1 = *(uint *)(param_2 + 0x30);
      if ((uVar1 & 0x400) == 0) {
        uVar1 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
      }
      else {
        iVar2 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
        uVar1 = iVar2 * iVar2;
      }
      if (uVar1 == 1) {
        this_00 = (unsigned char *)GetGlobalPoolAllocator();
        puVar3 = (undefined4 *)TPoolAllocator__allocate(this_00,4);
        *(undefined4 **)((int)this + 0x38) = puVar3;
        uVar1 = *(uint *)((int)this + 0x30) >> 0x13 & 0x3f;
        if (uVar1 == 2) {
LAB_97ba311c:
          *puVar3 = **(undefined4 **)(param_2 + 0x38);
          return;
        }
        if (uVar1 < 3) {
          if (uVar1 == 1) {
            *puVar3 = **(undefined4 **)(param_2 + 0x38);
            return;
          }
        }
        else if (uVar1 == 3) goto LAB_97ba311c;
        pcVar5 = "false && \"Unknown type\"";
        uVar4 = 0xb9;
      }
      else {
        pcVar5 = "copyOf.type.getInstanceSize() == 1";
        uVar4 = 0xb2;
      }
    }
    else {
      pcVar5 = "!copyOf.type.getStruct()";
      uVar4 = 0xb1;
    }
  }
  else {
    pcVar5 = "copyOf.arrayInformationType == 0";
    uVar4 = 0xad;
  }
  ___eprintf("%s:%u: failed assertion `%s\'\n",
             "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/SymbolTable.cpp"
             ,uVar4,pcVar5);
LAB_97ba314c:
  *(uint *)((int)this + 0x38) = uVar1;
  return;
}

/* __ZN9TVariableC4ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE @ 0x97ba2fb4 (432 bytes) */
int __ZN9TVariableC4ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE(this, param_2, param_3)
  void *this;
  unsigned char * param_2;
  unsigned char * param_3;
{
  uint uVar1;
  int iVar2;
  unsigned char * this_00;
  undefined4 *puVar3;
  undefined4 uVar4;
  char *pcVar5;
  
  ((int (*)())__ZN7TSymbolC2ERKS_)(this,(unsigned char *)param_2);
  *(int *)this = DAT_a7b7ba78 + 8;
  *(undefined ***)((int)this + 0xc) = &PTR___ZN5TTypeD1Ev_a7b7d590;
  TType__copyType((unsigned char *)((int)this + 0xc),(unsigned char *)(param_2 + 0xc),param_3);
  iVar2 = *(int *)(param_2 + 0x3c);
  uVar1 = *(uint *)(param_2 + 0x34);
  *(uint *)((int)this + 0x34) = uVar1;
  if (iVar2 == 0) {
    iVar2 = *(int *)(param_2 + 0x38);
    *(undefined4 *)((int)this + 0x3c) = 0;
    uVar1 = 0;
    if (iVar2 == 0) goto LAB_97ba314c;
    uVar1 = *(uint *)(param_2 + 0x14);
    if (uVar1 == 0) {
      uVar1 = *(uint *)(param_2 + 0x30);
      if ((uVar1 & 0x400) == 0) {
        uVar1 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
      }
      else {
        iVar2 = (int)(uVar1 << 0xd | uVar1 >> 0x13) >> 0x18;
        uVar1 = iVar2 * iVar2;
      }
      if (uVar1 == 1) {
        this_00 = (unsigned char *)GetGlobalPoolAllocator();
        puVar3 = (undefined4 *)TPoolAllocator__allocate(this_00,4);
        *(undefined4 **)((int)this + 0x38) = puVar3;
        uVar1 = *(uint *)((int)this + 0x30) >> 0x13 & 0x3f;
        if (uVar1 == 2) {
LAB_97ba311c:
          *puVar3 = **(undefined4 **)(param_2 + 0x38);
          return;
        }
        if (uVar1 < 3) {
          if (uVar1 == 1) {
            *puVar3 = **(undefined4 **)(param_2 + 0x38);
            return;
          }
        }
        else if (uVar1 == 3) goto LAB_97ba311c;
        pcVar5 = "false && \"Unknown type\"";
        uVar4 = 0xb9;
      }
      else {
        pcVar5 = "copyOf.type.getInstanceSize() == 1";
        uVar4 = 0xb2;
      }
    }
    else {
      pcVar5 = "!copyOf.type.getStruct()";
      uVar4 = 0xb1;
    }
  }
  else {
    pcVar5 = "copyOf.arrayInformationType == 0";
    uVar4 = 0xad;
  }
  ___eprintf("%s:%u: failed assertion `%s\'\n",
             "/SourceCache/OpenGL/OpenGL-4.7.14/GLProgrammability/glslang/MachineIndependent/SymbolTable.cpp"
             ,uVar4,pcVar5);
LAB_97ba314c:
  *(uint *)((int)this + 0x38) = uVar1;
  return;
}

/* TVariable__clone @ 0x97ba3164 (76 bytes) */
int TVariable__clone(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  unsigned char * this_00;
  void *this_01;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  this_01 = (void *)TPoolAllocator__allocate(this_00,0x40);
  ((int (*)())__ZN9TVariableC1ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE)(this_01,this,param_2);
  return this_01;
}

/* __ZN9TFunctionC2ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE @ 0x97ba31b0 (4 bytes) */
int __ZN9TFunctionC2ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE(this, param_2, param_3)
  void *this;
  unsigned char * param_2;
  unsigned char * param_3;
{
  undefined1 *puVar1;
  int *piVar2;
  void *pvVar3;
  undefined4 uVar4;
  unsigned char * pTVar5;
  void *this_00;
  unsigned char * this_01;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  char *pcVar12;
  unsigned char * pTVar13;
  char in_RESERVE;
  byte in_cr0;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 auStack_50 [4];
  
  ((int (*)())__ZN7TSymbolC2ERKS_)(this,(unsigned char *)param_2);
  *(int *)this = DAT_a7b7ba7c + 8;
  uVar4 = GetGlobalPoolAllocator();
  *(undefined4 *)((int)this + 0xc) = uVar4;
  iVar8 = DAT_a7b7ba74;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  piVar2 = (int *)(iVar8 + 8);
  *(undefined ***)((int)this + 0x1c) = &PTR___ZN5TTypeD1Ev_a7b7d590;
  do {
    if (in_RESERVE != '\0') {
      iVar6 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar6;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  uVar4 = GetGlobalPoolAllocator();
  *(undefined4 *)((int)this + 0x44) = uVar4;
  *(int *)((int)this + 0x48) = iVar8 + 0xc;
  puVar1 = DAT_a7b7ba80;
  for (uVar11 = 0; uVar11 < (uint)(*(int *)(param_2 + 0x14) - *(int *)(param_2 + 0x10) >> 3);
      uVar11 = uVar11 + 1) {
    puVar7 = *(undefined4 **)((int)this + 0x14);
    if (puVar7 == *(undefined4 **)((int)this + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((int)this + 0xc,*(undefined4 *)((int)this + 0x14),&uStack_60);
    }
    else {
      iVar8 = 0;
      if (puVar7 != (undefined4 *)0x0) {
        puVar7[1] = uStack_5c;
        *puVar7 = uStack_60;
        iVar8 = *(int *)((int)this + 0x14);
      }
      *(int *)((int)this + 0x14) = iVar8 + 8;
    }
    iVar6 = *(int *)(param_2 + 0x10);
    iVar10 = *(int *)(iVar6 + uVar11 * 8);
    iVar8 = *(int *)((int)this + 0x14);
    iVar9 = *(int *)(iVar10 + 4);
    *(undefined1 *)(iVar9 + *(int *)(iVar9 + -0xc)) = *puVar1;
    pcVar12 = *(char **)(iVar10 + 4);
    pTVar5 = (unsigned char *)GetGlobalPoolAllocator();
    this_00 = (void *)TPoolAllocator__allocate(pTVar5,8);
    pvVar3 = (void *)0x0;
    if (this_00 != (void *)0x0) {
      auStack_50[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (this_00,pcVar12,(unsigned char *)auStack_50);
      pvVar3 = this_00;
    }
    *(void **)(iVar8 + -8) = pvVar3;
    pTVar13 = *(unsigned char **)(iVar6 + uVar11 * 8 + 4);
    pTVar5 = (unsigned char *)GetGlobalPoolAllocator();
    this_01 = (unsigned char *)TPoolAllocator__allocate(pTVar5,0x28);
    *(undefined ***)this_01 = &PTR___ZN5TTypeD1Ev_a7b7d590;
    TType__copyType(this_01,pTVar13,param_3);
    *(unsigned char **)(iVar8 + -4) = this_01;
  }
  TType__copyType((unsigned char *)((int)this + 0x1c),(unsigned char *)(param_2 + 0x1c),param_3);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
            ((void *)((int)this + 0x44),(unsigned char *)(param_2 + 0x44));
  uVar4 = *(undefined4 *)(param_2 + 0x4c);
  *(undefined4 *)((int)this + 0x50) = *(undefined4 *)(param_2 + 0x50);
  *(undefined4 *)((int)this + 0x4c) = uVar4;
  return;
}

/* __ZN9TFunctionC1ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE @ 0x97ba31b4 (4 bytes) */
int __ZN9TFunctionC1ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE(this, param_2, param_3)
  void *this;
  unsigned char * param_2;
  unsigned char * param_3;
{
  undefined1 *puVar1;
  int *piVar2;
  void *pvVar3;
  undefined4 uVar4;
  unsigned char * pTVar5;
  void *this_00;
  unsigned char * this_01;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  char *pcVar12;
  unsigned char * pTVar13;
  char in_RESERVE;
  byte in_cr0;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 auStack_50 [4];
  
  ((int (*)())__ZN7TSymbolC2ERKS_)(this,(unsigned char *)param_2);
  *(int *)this = DAT_a7b7ba7c + 8;
  uVar4 = GetGlobalPoolAllocator();
  *(undefined4 *)((int)this + 0xc) = uVar4;
  iVar8 = DAT_a7b7ba74;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  piVar2 = (int *)(iVar8 + 8);
  *(undefined ***)((int)this + 0x1c) = &PTR___ZN5TTypeD1Ev_a7b7d590;
  do {
    if (in_RESERVE != '\0') {
      iVar6 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar6;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  uVar4 = GetGlobalPoolAllocator();
  *(undefined4 *)((int)this + 0x44) = uVar4;
  *(int *)((int)this + 0x48) = iVar8 + 0xc;
  puVar1 = DAT_a7b7ba80;
  for (uVar11 = 0; uVar11 < (uint)(*(int *)(param_2 + 0x14) - *(int *)(param_2 + 0x10) >> 3);
      uVar11 = uVar11 + 1) {
    puVar7 = *(undefined4 **)((int)this + 0x14);
    if (puVar7 == *(undefined4 **)((int)this + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((int)this + 0xc,*(undefined4 *)((int)this + 0x14),&uStack_60);
    }
    else {
      iVar8 = 0;
      if (puVar7 != (undefined4 *)0x0) {
        puVar7[1] = uStack_5c;
        *puVar7 = uStack_60;
        iVar8 = *(int *)((int)this + 0x14);
      }
      *(int *)((int)this + 0x14) = iVar8 + 8;
    }
    iVar6 = *(int *)(param_2 + 0x10);
    iVar10 = *(int *)(iVar6 + uVar11 * 8);
    iVar8 = *(int *)((int)this + 0x14);
    iVar9 = *(int *)(iVar10 + 4);
    *(undefined1 *)(iVar9 + *(int *)(iVar9 + -0xc)) = *puVar1;
    pcVar12 = *(char **)(iVar10 + 4);
    pTVar5 = (unsigned char *)GetGlobalPoolAllocator();
    this_00 = (void *)TPoolAllocator__allocate(pTVar5,8);
    pvVar3 = (void *)0x0;
    if (this_00 != (void *)0x0) {
      auStack_50[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (this_00,pcVar12,(unsigned char *)auStack_50);
      pvVar3 = this_00;
    }
    *(void **)(iVar8 + -8) = pvVar3;
    pTVar13 = *(unsigned char **)(iVar6 + uVar11 * 8 + 4);
    pTVar5 = (unsigned char *)GetGlobalPoolAllocator();
    this_01 = (unsigned char *)TPoolAllocator__allocate(pTVar5,0x28);
    *(undefined ***)this_01 = &PTR___ZN5TTypeD1Ev_a7b7d590;
    TType__copyType(this_01,pTVar13,param_3);
    *(unsigned char **)(iVar8 + -4) = this_01;
  }
  TType__copyType((unsigned char *)((int)this + 0x1c),(unsigned char *)(param_2 + 0x1c),param_3);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
            ((void *)((int)this + 0x44),(unsigned char *)(param_2 + 0x44));
  uVar4 = *(undefined4 *)(param_2 + 0x4c);
  *(undefined4 *)((int)this + 0x50) = *(undefined4 *)(param_2 + 0x50);
  *(undefined4 *)((int)this + 0x4c) = uVar4;
  return;
}

/* __ZN9TFunctionC4ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE @ 0x97ba31b8 (492 bytes) */
int __ZN9TFunctionC4ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE(this, param_2, param_3)
  void *this;
  unsigned char * param_2;
  unsigned char * param_3;
{
  undefined1 *puVar1;
  int *piVar2;
  void *pvVar3;
  undefined4 uVar4;
  unsigned char * pTVar5;
  void *this_00;
  unsigned char * this_01;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  char *pcVar12;
  unsigned char * pTVar13;
  char in_RESERVE;
  byte in_cr0;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_50 [4];
  
  ((int (*)())__ZN7TSymbolC2ERKS_)(this,(unsigned char *)param_2);
  *(int *)this = DAT_a7b7ba7c + 8;
  uVar4 = GetGlobalPoolAllocator();
  *(undefined4 *)((int)this + 0xc) = uVar4;
  iVar8 = DAT_a7b7ba74;
  *(undefined4 *)((int)this + 0x18) = 0;
  *(undefined4 *)((int)this + 0x10) = 0;
  *(undefined4 *)((int)this + 0x14) = 0;
  piVar2 = (int *)(iVar8 + 8);
  *(undefined ***)((int)this + 0x1c) = &PTR___ZN5TTypeD1Ev_a7b7d590;
  do {
    if (in_RESERVE != '\0') {
      iVar6 = storeWordConditionalIndexed(*piVar2 + 1,0,piVar2);
      *piVar2 = iVar6;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  uVar4 = GetGlobalPoolAllocator();
  *(undefined4 *)((int)this + 0x44) = uVar4;
  *(int *)((int)this + 0x48) = iVar8 + 0xc;
  puVar1 = DAT_a7b7ba80;
  for (uVar11 = 0; uVar11 < (uint)(*(int *)(param_2 + 0x14) - *(int *)(param_2 + 0x10) >> 3);
      uVar11 = uVar11 + 1) {
    puVar7 = *(undefined4 **)((int)this + 0x14);
    if (puVar7 == *(undefined4 **)((int)this + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((int)this + 0xc,*(undefined4 *)((int)this + 0x14),&local_60);
    }
    else {
      iVar8 = 0;
      if (puVar7 != (undefined4 *)0x0) {
        puVar7[1] = local_5c;
        *puVar7 = local_60;
        iVar8 = *(int *)((int)this + 0x14);
      }
      *(int *)((int)this + 0x14) = iVar8 + 8;
    }
    iVar6 = *(int *)(param_2 + 0x10);
    iVar10 = *(int *)(iVar6 + uVar11 * 8);
    iVar8 = *(int *)((int)this + 0x14);
    iVar9 = *(int *)(iVar10 + 4);
    *(undefined1 *)(iVar9 + *(int *)(iVar9 + -0xc)) = *puVar1;
    pcVar12 = *(char **)(iVar10 + 4);
    pTVar5 = (unsigned char *)GetGlobalPoolAllocator();
    this_00 = (void *)TPoolAllocator__allocate(pTVar5,8);
    pvVar3 = (void *)0x0;
    if (this_00 != (void *)0x0) {
      local_50[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (this_00,pcVar12,(unsigned char *)local_50);
      pvVar3 = this_00;
    }
    *(void **)(iVar8 + -8) = pvVar3;
    pTVar13 = *(unsigned char **)(iVar6 + uVar11 * 8 + 4);
    pTVar5 = (unsigned char *)GetGlobalPoolAllocator();
    this_01 = (unsigned char *)TPoolAllocator__allocate(pTVar5,0x28);
    *(undefined ***)this_01 = &PTR___ZN5TTypeD1Ev_a7b7d590;
    TType__copyType(this_01,pTVar13,param_3);
    *(unsigned char **)(iVar8 + -4) = this_01;
  }
  TType__copyType((unsigned char *)((int)this + 0x1c),(unsigned char *)(param_2 + 0x1c),param_3);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
            ((void *)((int)this + 0x44),(unsigned char *)(param_2 + 0x44));
  uVar4 = *(undefined4 *)(param_2 + 0x4c);
  *(undefined4 *)((int)this + 0x50) = *(undefined4 *)(param_2 + 0x50);
  *(undefined4 *)((int)this + 0x4c) = uVar4;
  return;
}

/* TFunction__clone @ 0x97ba33a4 (76 bytes) */
int TFunction__clone(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  unsigned char * this_00;
  void *this_01;
  
  this_00 = (unsigned char *)GetGlobalPoolAllocator();
  this_01 = (void *)TPoolAllocator__allocate(this_00,0x54);
  ((int (*)())__ZN9TFunctionC1ERKS_RSt3mapIP7TVectorI9TTypeLineES6_St4lessIS6_ESaISt4pairIKS6_S6_EEE)(this_01,this,param_2);
  return this_01;
}

/* TSymbolTableLevel__clone @ 0x97ba33f0 (352 bytes) */
int TSymbolTableLevel__clone(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  int iVar2;
  unsigned char * pTVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  unsigned char * psVar7;
  char in_RESERVE;
  byte in_cr0;
  int local_90 [4];
  int local_80;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_50;
  int local_4c;
  int *local_48;
  undefined4 local_40 [6];
  
  pTVar3 = (unsigned char *)GetGlobalPoolAllocator();
  puVar4 = (undefined4 *)TPoolAllocator__allocate(pTVar3,0x10);
  pTVar3 = (unsigned char *)GetGlobalPoolAllocator();
  puVar4[1] = 0;
  *puVar4 = pTVar3;
  puVar5 = (undefined4 *)TPoolAllocator__allocate(pTVar3,0x1c);
  puVar4[2] = 0;
  puVar4[1] = puVar5;
  *puVar5 = 0;
  *(undefined4 *)(puVar4[1] + 4) = 0;
  *(undefined4 *)(puVar4[1] + 8) = puVar4[1];
  *(undefined4 *)(puVar4[1] + 0xc) = puVar4[1];
  local_80 = *(int *)(this + 4);
  local_90[0] = *(int *)(local_80 + 8);
  if (local_90[0] != local_80) {
    do {
      piVar6 = (int *)(**(code **)(**(int **)(local_90[0] + 0x18) + 0x18))
                                (*(int **)(local_90[0] + 0x18),param_2);
      local_6c = 0;
      psVar7 = (unsigned char *)(**(code **)(*piVar6 + 8))();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_50,psVar7);
      local_48 = piVar6;
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_60,puVar4,&local_50);
      local_70 = local_60;
      piVar6 = (int *)(local_4c + -4);
      local_6c = local_5c;
      local_40[0] = local_50;
      do {
        iVar2 = *piVar6;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(iVar2 + -1,0,piVar6);
          *piVar6 = iVar1;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar2 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(local_4c + -0xc),local_40);
      }
      std___Rb_tree_base_iterator___M_increment((unsigned char *)local_90);
      local_80 = *(int *)(this + 4);
    } while (local_90[0] != local_80);
  }
  return puVar4;
}

/* TSymbolTable__copyTable @ 0x97ba3550 (492 bytes) */
int TSymbolTable__copyTable(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
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
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_2 + 0xc);
  local_60 = puVar5;
  for (uVar6 = 0; uVar6 < (uint)(*(int *)(param_2 + 4) - *(int *)param_2 >> 2); uVar6 = uVar6 + 1) {
    local_30[0] = ((int (*)())TSymbolTableLevel__clone)(*(unsigned char **)(*(int *)param_2 + uVar6 * 4),(unsigned char *)&local_60);
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
    std___Rb_tree_TVector_TTypeLine___std__pair_TVector_TTypeLine__const_TVector_TTypeLine____std___Select1st_std__pair_TVector_TTypeLine__const_TVector_TTypeLine_____std__less_TVector_TTypeLine____std__allocator_std__pair_TVector_TTypeLine__const_TVector_TTypeLine________M_erase((unsigned char
                *)&local_60,(unsigned char *)local_60[1]);
    local_60[2] = local_60;
    local_60[1] = 0;
    local_60[3] = local_60;
    local_5c = 0;
  }
  std____default_alloc_template_true_0___deallocate(local_60,0x18);
  return;
}

/* yyparse @ 0x97ba373c (34436 bytes) */
int yyparse(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  void *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  uint param_8;
{
  short sVar1;
  unsigned char * pTVar2;
  uint uVar3;
  unsigned char * pTVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  int iVar7;
  unsigned char * pTVar8;
  unsigned char * pcVar9;
  unsigned char * pTVar10;
  unsigned char * psVar11;
  unsigned char * paVar12;
  void *pvVar13;
  unsigned char * pTVar14;
  unsigned char * pTVar15;
  undefined4 uVar16;
  unsigned char * pTVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  unsigned char * pTVar20;
  int *piVar21;
  unsigned char * psVar22;
  unsigned char * pTVar23;
  void *pvVar24;
  unsigned char * this;
  unsigned char ** ppTVar25;
  uint *puVar26;
  undefined4 uVar27;
  int iVar28;
  unsigned char * pTVar29;
  unsigned char * pTVar30;
  char *pcVar31;
  int iVar32;
  char *pcVar33;
  int iVar34;
  bool bVar36;
  int iVar35;
  unsigned char * pTVar37;
  int iVar38;
  int iVar39;
  int iVar40;
  int iVar41;
  code *pcVar42;
  unsigned char * pTVar43;
  uint *puVar44;
  int iVar45;
  uint uVar46;
  unsigned char * pTVar47;
  unsigned char * pTVar48;
  uint *puVar49;
  unsigned char * pTVar50;
  uint uVar51;
  uint uVar52;
  int iVar53;
  int *piVar54;
  unsigned char * pTVar55;
  uint uVar56;
  int iVar57;
  int iVar58;
  uint uVar59;
  uint uVar60;
  uint uVar61;
  int iVar62;
  int *piVar63;
  char *pcVar64;
  char in_RESERVE;
  byte in_cr0;
  unsigned char aTStack_2ca2 [2];
  unsigned char local_2ca0 [400];
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
  unsigned char * local_7b0;
  char *local_7ac;
  unsigned char * local_780;
  int local_77c;
  int local_764;
  unsigned char * local_750 [4];
  unsigned char * local_740;
  undefined4 local_720 [4];
  unsigned char * local_710 [4];
  undefined4 local_700 [4];
  unsigned char * local_6f0 [4];
  unsigned char * local_6e0 [4];
  unsigned char * local_6d0 [4];
  unsigned char * local_6c0 [4];
  undefined4 local_6b0 [4];
  unsigned char * local_6a0 [4];
  undefined4 local_690 [4];
  unsigned char * local_680 [4];
  undefined4 local_670 [4];
  int local_660;
  unsigned char * local_650 [4];
  int local_640;
  int local_630;
  int local_620;
  unsigned char * local_610 [4];
  unsigned char * local_600 [4];
  unsigned char * local_5f0 [4];
  unsigned char * local_5e0 [4];
  unsigned char * local_5d0 [4];
  unsigned char * local_5c0 [4];
  unsigned char * local_5b0 [4];
  unsigned char * local_5a0 [4];
  unsigned char * local_590 [4];
  unsigned char * local_580 [4];
  unsigned char * local_570 [4];
  unsigned char * local_560 [4];
  unsigned char * local_550 [4];
  unsigned char * local_540 [4];
  unsigned char * local_530 [4];
  unsigned char * local_520 [4];
  unsigned char * local_510 [4];
  unsigned char * local_500 [4];
  unsigned char * local_4f0 [4];
  unsigned char * local_4e0 [4];
  unsigned char * local_4d0 [4];
  unsigned char * local_4c0 [4];
  unsigned char * local_4b0 [4];
  unsigned char * local_4a0 [4];
  unsigned char * local_490 [4];
  unsigned char * local_480 [4];
  unsigned char * local_470 [4];
  unsigned char * local_460 [4];
  unsigned char * local_450 [4];
  unsigned char * local_440 [4];
  unsigned char * local_430 [4];
  unsigned char * local_420 [4];
  unsigned char * local_410 [4];
  unsigned char * local_400 [4];
  unsigned char * local_3f0 [4];
  unsigned char * local_3e0 [4];
  unsigned char * local_3d0 [4];
  unsigned char * local_3c0 [4];
  unsigned char * local_3b0 [4];
  unsigned char * local_3a0 [4];
  unsigned char * local_390 [4];
  unsigned char * local_380 [4];
  unsigned char * local_370 [4];
  unsigned char * local_360 [4];
  unsigned char * local_350 [4];
  unsigned char * local_340 [4];
  unsigned char * local_330 [4];
  int local_320 [4];
  unsigned char * local_310;
  int local_30c;
  unsigned char * local_308;
  unsigned char * local_300 [4];
  undefined4 local_2f0 [4];
  unsigned char * local_2e0 [4];
  undefined4 local_2d0 [4];
  unsigned char * local_2c0 [4];
  undefined4 local_2b0 [4];
  int local_2a0;
  undefined4 local_290 [4];
  undefined4 local_280 [4];
  unsigned char * local_270 [4];
  undefined4 local_260 [4];
  undefined4 local_250 [4];
  undefined4 local_240 [4];
  unsigned char * local_230 [4];
  undefined4 local_220 [4];
  undefined4 local_210 [4];
  unsigned char * local_200 [4];
  unsigned char * local_1f0 [4];
  undefined4 local_1e0;
  int local_1dc;
  int *local_1d8;
  undefined4 local_1d0 [4];
  undefined4 local_1c0 [4];
  undefined4 local_1b0 [4];
  unsigned char * local_1a0 [4];
  unsigned char * local_190 [4];
  int local_180;
  unsigned char * local_170;
  undefined4 *local_160 [4];
  unsigned char * local_150;
  unsigned char * local_140;
  unsigned char * local_130;
  undefined4 local_120;
  undefined4 local_110;
  undefined4 local_100;
  undefined4 local_f0;
  int local_ec;
  int *local_e8;
  undefined4 local_e0 [4];
  undefined4 local_d0 [4];
  unsigned char * local_c0 [4];
  undefined4 local_b0 [4];
  unsigned char * local_a0 [4];
  uint local_90;
  uint local_8c;
  int local_88;
  int local_84;
  unsigned char * local_80;
  unsigned char * local_7c;
  uint local_78;
  uint local_74;
  unsigned char * pTStack_70;
  int local_6c;
  undefined *local_68;
  unsigned char * local_64;
  unsigned char * local_60;
  unsigned char * local_5c;
  int *local_58;
  int local_54;
  
  puVar5 = (undefined4 *)&STACKARG(0xffffd310);
  puVar49 = auStack_2b10;
  pTVar43 = (unsigned char *)0xc8;
  iVar53 = 0;
  iVar45 = 0;
  uVar46 = 0xfffffffe;
  pTVar48 = aTStack_2ca2;
  local_60 = (unsigned char *)0x190;
  puVar44 = puVar49;
  pTVar47 = local_2ca0;
LAB_97ba3784:
  do {
    pTVar48 = pTVar48 + 2;
    *(short *)pTVar48 = (short)iVar53;
    puVar26 = puVar44;
    pTVar4 = pTVar47;
    if (pTVar47 + (int)local_60 + -2 <= pTVar48) {
      iVar58 = ((int)pTVar48 - (int)pTVar47 >> 1) + 1;
      if (9999 < (int)pTVar43) {
        yyerror("parser stack overflow");
        return 2;
      }
      pTVar43 = local_60;
      if (10000 < (int)local_60) {
        pTVar43 = (unsigned char *)0x2710;
      }
      local_60 = (unsigned char *)((int)pTVar43 * 2);
      puVar18 = (undefined4 *)((int)puVar5 - ((uint)(local_60 + 0x1e) & 0xfffffff0));
      *puVar18 = *puVar5;
      pTVar4 = (unsigned char *)(puVar18 + 0x14);
      _memcpy(pTVar4,pTVar47,iVar58 * 2);
      pTVar48 = pTVar4 + (iVar58 * 2 - 2);
      puVar5 = (undefined4 *)((int)puVar18 - ((int)pTVar43 * 0x2c + 0x1eU & 0xfffffff0));
      *puVar5 = *puVar18;
      puVar26 = puVar5 + 0x14;
      _memcpy(puVar26,puVar44,iVar58 * 0x2c);
      puVar49 = puVar26 + iVar58 * 0xb + -0xb;
      if (pTVar4 + (int)local_60 + -2 <= pTVar48) {
        return 1;
      }
    }
    iVar58 = iVar53 * 2;
    sVar1 = (&_yypact)[iVar53];
    pTVar37 = local_60;
    puVar44 = puVar26;
    pTVar47 = pTVar4;
    if (sVar1 == -0x8000) {
LAB_97ba3958:
      uVar59 = (uint)*(short *)(&_yydefact + iVar58);
      if (uVar59 != 0) goto LAB_97ba3970;
LAB_97bac03c:
      if (iVar45 == 0) {
        yyerror("parse error");
      }
LAB_97bac050:
      if (iVar45 == 3) {
        if (uVar46 == 0) {
          return 1;
        }
        uVar46 = 0xfffffffe;
      }
      iVar45 = 3;
      do {
        if (((*(short *)((int)&_yypact + iVar58) != -0x8000) &&
            (uVar59 = (int)*(short *)((int)&_yypact + iVar58) + 1, uVar59 < 0x4f0)) &&
           (iVar53 = uVar59 * 2, *(short *)(&_yycheck + iVar53) == 1)) {
          iVar53 = (int)*(short *)(&_yytable + iVar53);
          if (iVar53 < 0) {
            if (iVar53 != -0x8000) goto LAB_97bac0d0;
          }
          else if (iVar53 != 0) {
            if (iVar53 == 0x14d) {
              return 0;
            }
            puVar49 = puVar49 + 0xb;
            _memcpy(puVar49,aYStack_8b0,0x2c);
            goto LAB_97ba3784;
          }
        }
        if (pTVar48 == pTVar4) {
          return 1;
        }
        pTVar48 = pTVar48 + -2;
        puVar49 = puVar49 + -0xb;
        iVar58 = (int)*(short *)pTVar48 << 1;
      } while( true );
    }
    if (uVar46 == 0xfffffffe) {
      uVar46 = ((int (*)())yylex)(aYStack_8b0,param_1);
    }
    if ((int)uVar46 < 1) {
      iVar53 = 0;
      uVar46 = 0;
    }
    else {
      iVar53 = 0xa9;
      if (uVar46 < 0x15d) {
        iVar53 = (int)(char)(&_yytranslate)[uVar46];
      }
    }
    uVar59 = sVar1 + iVar53;
    if ((0x4ef < uVar59) || (iVar57 = uVar59 * 2, *(short *)(&_yycheck + iVar57) != iVar53))
    goto LAB_97ba3958;
    iVar53 = (int)*(short *)(&_yytable + iVar57);
    if (iVar53 < 0) {
      if (iVar53 != -0x8000) break;
      goto LAB_97bac03c;
    }
    if (iVar53 == 0) goto LAB_97bac03c;
    if (iVar53 == 0x14d) {
      return 0;
    }
    if (uVar46 != 0) {
      uVar46 = 0xfffffffe;
    }
    puVar49 = puVar49 + 0xb;
    _memcpy(puVar49,aYStack_8b0,0x2c);
    if (iVar45 != 0) {
      iVar45 = iVar45 + -1;
    }
  } while( true );
LAB_97bac0d0:
  uVar59 = -iVar53;
LAB_97ba3970:
  local_6c = uVar59 * 2;
  iVar53 = (int)*(short *)(&_yyr2 + local_6c);
  if (0 < iVar53) {
    _memcpy(&local_880,puVar49 + (1 - iVar53) * 0xb,0x2c);
  }
  pTVar15 = local_878;
  pTVar50 = local_7f0;
  pTVar2 = local_750;
  if (0xd7 < uVar59) goto switchD_97ba39c8_caseD_0;
  iVar57 = uVar59 * 4;
  switch(uVar59) {
  case 0:
    break;
  case 1:
    pTVar4 = (unsigned char *)puVar49[2];
    if (pTVar4 == (unsigned char *)0x0) {
      uVar59 = puVar49[1];
      local_64 = (unsigned char *)0xa7b8374c;
      iVar58 = *(int *)(uVar59 + 4);
      *(unsigned char *)(iVar58 + *(int *)(iVar58 + -0xc)) = *DAT_a7b7ba88;
      TParseContext__error
                ((int)param_1,(char *)*puVar49,"undeclared identifier",*(char **)(uVar59 + 4),"",
                 pTVar37,iVar58,uVar59);
      TParseContext__recover(param_1);
      local_5c = (unsigned char *)0xa7b8374c;
      local_82c = (unsigned char *)((uint)local_82c & 0x1ff | 0x80800);
      local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      local_84c = pTVar4;
      local_848 = pTVar4;
      local_844 = pTVar4;
      local_840 = pTVar4;
      local_83c = pTVar4;
      local_838 = pTVar4;
      local_834 = pTVar4;
      local_830 = pTVar4;
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      pTVar37 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x40);
      uVar59 = puVar49[1];
      puVar6 = PTR_vtable_a7b7c0b4 + 8;
      *(undefined ***)(pTVar37 + 0xc) = &PTR___ZN5TTypeD1Ev_a7b7d640;
      *(uint *)(pTVar37 + 4) = uVar59;
      *(undefined **)pTVar37 = puVar6;
      *(unsigned char **)(pTVar37 + 0x10) = local_84c;
      *(unsigned char **)(pTVar37 + 0x14) = local_848;
      *(unsigned char **)(pTVar37 + 0x18) = local_844;
      *(unsigned char **)(pTVar37 + 0x1c) = local_840;
      *(unsigned char **)(pTVar37 + 0x20) = local_83c;
      *(unsigned char **)(pTVar37 + 0x24) = local_838;
      *(unsigned char **)(pTVar37 + 0x28) = local_834;
      *(unsigned char **)(pTVar37 + 0x2c) = local_830;
      uVar3 = *(uint *)(pTVar37 + 0x30);
      uVar52 = (uint)local_82c & 0xfe000000;
      *(uint *)(pTVar37 + 0x30) = uVar52 | uVar3 & 0x1ffffff;
      uVar56 = ((uint)local_82c >> 0x13 & 0x3f) << 0x13;
      *(uint *)(pTVar37 + 0x30) = uVar56 | uVar52 | uVar3 & 0x7ffff;
      uVar59 = (uint)local_82c & 0x7f800;
      *(uint *)(pTVar37 + 0x30) = uVar59 | uVar56 | uVar52 | uVar3 & 0x7ff;
      uVar61 = ((uint)local_82c >> 10 & 1) << 10;
      *(uint *)(pTVar37 + 0x30) = uVar61 | uVar59 | uVar56 | uVar52 | uVar3 & 0x3ff;
      *(uint *)(pTVar37 + 0x30) =
           ((uint)local_82c >> 9 & 1) << 9 | uVar61 | uVar59 | uVar56 | uVar52 | uVar3 & 0x1ff;
      *(int *)(pTVar37 + 0x34) = 0;
      *(int *)(pTVar37 + 0x38) = 0;
      *(int *)(pTVar37 + 0x3c) = 0;
      piVar63 = *(int **)((int)param_1 + 4);
      iVar58 = piVar63[3];
      piVar63[3] = iVar58 + 1;
      *(int *)(pTVar37 + 8) = iVar58 + 1;
      uVar16 = *(undefined4 *)(*piVar63 + ((piVar63[1] - *piVar63 & 0xfffffffcU) - 4));
      local_81c = pTVar4;
      psVar22 = (unsigned char *)(**(code **)(*(int *)pTVar37 + 8))();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_800,psVar22);
      local_7f8 = pTVar37;
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_810,uVar16,&local_800);
      local_820 = local_810;
      pTVar4 = local_7fc + -4;
      local_81c = local_80c;
      local_7f0 = local_800;
      do {
        iVar58 = *(int *)pTVar4;
        if (in_RESERVE != '\0') {
          iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
          *(int *)pTVar4 = iVar57;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar58 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(local_7fc + -0xc),&local_7f0);
      }
      local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      pTVar4 = pTVar37;
    }
    else {
      iVar58 = (**(code **)(*(int *)pTVar4 + 0x10))(pTVar4);
      if (iVar58 == 0) {
        uVar59 = puVar49[1];
        local_64 = (unsigned char *)0xa7b8374c;
        iVar58 = *(int *)(uVar59 + 4);
        *(unsigned char *)(iVar58 + *(int *)(iVar58 + -0xc)) = *DAT_a7b7ba88;
        TParseContext__error
                  ((int)param_1,(char *)*puVar49,"variable expected",*(char **)(uVar59 + 4),"",
                   pTVar37,iVar58,uVar59);
        TParseContext__recover(param_1);
      }
    }
    iVar58 = (**(code **)(*(int *)(pTVar4 + 0xc) + 0x24))(pTVar4 + 0xc);
    if (iVar58 != 2) {
      pTVar15 = (unsigned char *)TIntermediate__addSymbol
                                   (*(unsigned char **)param_1,*(int *)(pTVar4 + 8),
                                    *(unsigned char **)(pTVar4 + 4),pTVar4 + 0xc,*puVar49);
      pTVar50 = local_7f0;
      pTVar2 = local_750;
      break;
    }
    local_84c = *(unsigned char **)(pTVar4 + 0x10);
    local_844 = *(unsigned char **)(pTVar4 + 0x18);
    local_840 = *(unsigned char **)(pTVar4 + 0x1c);
    local_848 = *(unsigned char **)(pTVar4 + 0x14);
    local_83c = *(unsigned char **)(pTVar4 + 0x20);
    local_838 = *(unsigned char **)(pTVar4 + 0x24);
    local_834 = *(unsigned char **)(pTVar4 + 0x28);
    local_830 = *(unsigned char **)(pTVar4 + 0x2c);
    pcVar9 = *(unsigned char **)(pTVar4 + 0x38);
    local_82c = (unsigned char *)((*(uint *)(pTVar4 + 0x30) >> 9 & 1) << 9 |
                         (*(uint *)(pTVar4 + 0x30) >> 10 & 1) << 10 |
                         *(uint *)(pTVar4 + 0x30) & 0x7f800 |
                         (*(uint *)(pTVar4 + 0x30) >> 0x13 & 0x3f) << 0x13 |
                         *(uint *)(pTVar4 + 0x30) & 0xfe000000 | (uint)local_82c & 0x1ff);
LAB_97ba4158:
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    pTVar14 = *(unsigned char **)param_1;
    uVar59 = *puVar49;
    goto LAB_97ba7d0c;
  default:
    goto switchD_97ba39c8_caseD_2;
  case 3:
    uVar59 = (int)puVar49[1] >> 0x1f;
    iVar58 = (uVar59 ^ puVar49[1]) - uVar59;
    if (0xffff < iVar58) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," integer constant overflow","","",uVar59,iVar58,
                 param_8);
      TParseContext__recover(param_1);
    }
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pcVar9 = (unsigned char *)TPoolAllocator__allocate(pTVar17,4);
    *(uint *)pcVar9 = puVar49[1];
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
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pcVar9 = (unsigned char *)TPoolAllocator__allocate(pTVar17,4);
    *(uint *)pcVar9 = puVar49[1];
    uVar59 = (uint)local_82c & 0x7ff | 0x4080000;
    goto LAB_97ba41e8;
  case 5:
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pcVar9 = (unsigned char *)TPoolAllocator__allocate(pTVar17,4);
    *(uint *)pcVar9 = puVar49[1];
    local_5c = (unsigned char *)0xa7b8374c;
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
    iVar58 = (**(code **)(*(int *)puVar49[-0x1f] + 0x54))();
    if (((iVar58 == 0) && (iVar58 = (**(code **)(*(int *)puVar49[-0x1f] + 0x50))(), iVar58 == 0)) &&
       (iVar58 = (**(code **)(*(int *)puVar49[-0x1f] + 0x58))(), iVar58 == 0)) {
      iVar58 = (**(code **)(*(int *)puVar49[-0x1f] + 0x28))();
      if (iVar58 == 0) {
        pcVar64 = (char *)puVar49[-0x16];
        pcVar31 = "expression";
      }
      else {
        local_64 = (unsigned char *)0xa7b8374c;
        piVar63 = (int *)(**(code **)(*(int *)puVar49[-0x1f] + 0x28))();
        iVar58 = (**(code **)(*piVar63 + 0x60))();
        iVar57 = *(int *)(iVar58 + 4);
        *(undefined1 *)(iVar57 + *(int *)(iVar57 + -0xc)) = **(undefined1 **)(local_64 + -0x7cc4);
        pcVar31 = *(char **)(iVar58 + 4);
        pcVar64 = (char *)puVar49[-0x16];
        pTVar37 = local_64;
      }
      TParseContext__error
                ((int)param_1,pcVar64," left of \'[\' is not of type array, matrix, or vector ",
                 pcVar31,"",pTVar37,iVar57,param_8);
      TParseContext__recover(param_1);
    }
    bVar36 = false;
    (**(code **)(*(int *)puVar49[-0x1f] + 0x38))(&local_850);
    if ((((uint)local_82c >> 0x19 == 2) &&
        (iVar58 = (**(code **)(*(int *)puVar49[-0x1f] + 0x54))(), iVar58 == 0)) &&
       (iVar58 = (**(code **)(*(int *)puVar49[-9] + 0x44))(), iVar58 == 2)) {
      bVar36 = true;
    }
    local_5c = (unsigned char *)0xa7b8374c;
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    if (bVar36) {
      iVar58 = (**(code **)(*(int *)puVar49[-0x1f] + 0x58))();
      if (iVar58 == 0) {
        iVar58 = (**(code **)(*(int *)puVar49[-0x1f] + 0x50))();
        if (iVar58 != 0) {
          iVar58 = (**(code **)(*(int *)puVar49[-9] + 0x18))();
          local_878 = (unsigned char *)TParseContext__addConstMatrixNode
                                         (param_1,**(int **)(iVar58 + 0x30),
                                          (unsigned char *)puVar49[-0x1f],puVar49[-0x16]);
        }
      }
      else {
        local_810 = (unsigned char *)0x1;
        iVar58 = (**(code **)(*(int *)puVar49[-9] + 0x18))();
        local_820 = (unsigned char *)**(uint **)(iVar58 + 0x30);
        local_878 = (unsigned char *)TParseContext__addConstVectorNode
                                       (param_1,(unsigned char *)&local_820,
                                        (unsigned char *)puVar49[-0x1f],puVar49[-0x16]);
      }
    }
    else {
      iVar58 = (**(code **)(*(int *)puVar49[-9] + 0x44))();
      if (iVar58 == 2) {
        bVar36 = false;
        iVar58 = (**(code **)(*(int *)puVar49[-0x1f] + 0x58))();
        if ((iVar58 != 0) || (iVar58 = (**(code **)(*(int *)puVar49[-0x1f] + 0x50))(), iVar58 != 0))
        {
          (**(code **)(*(int *)puVar49[-0x1f] + 0x38))(&local_7e0);
          uVar59 = local_7bc << 0xd;
          uVar52 = local_7bc >> 0x13;
          iVar58 = (**(code **)(*(int *)puVar49[-9] + 0x18))();
          if (((int)(uVar59 | uVar52) >> 0x18 <= **(int **)(iVar58 + 0x30)) &&
             (iVar58 = (**(code **)(*(int *)puVar49[-0x1f] + 0x54))(), iVar58 == 0)) {
            bVar36 = true;
          }
          local_7e0 = local_5c + -0x610c;
          if (bVar36) {
            iVar58 = (**(code **)(*(int *)puVar49[-9] + 0x18))();
            TParseContext__error
                      ((int)param_1,(char *)puVar49[-0x16],"","[",
                       "field selection out of range \'%d\'",**(undefined4 **)(iVar58 + 0x30),iVar57
                       ,param_8);
            TParseContext__recover(param_1);
            goto LAB_97ba47fc;
          }
        }
        iVar58 = (**(code **)(*(int *)puVar49[-0x1f] + 0x54))();
        if (iVar58 != 0) {
          (**(code **)(*(int *)puVar49[-0x1f] + 0x38))(&local_7b0);
          pTVar4 = local_5c + -0x610c;
          local_7b0 = pTVar4;
          if (local_7ac == (char *)0x0) {
            (**(code **)(*(int *)puVar49[-0x1f] + 0x38))(&local_780);
            iVar58 = local_764;
            iVar57 = (**(code **)(*(int *)puVar49[-9] + 0x18))();
            bVar36 = **(int **)(iVar57 + 0x30) < iVar58;
            if (bVar36) {
              local_780 = pTVar4;
              pTVar8 = (unsigned char *)(**(code **)(*(int *)puVar49[-0x1f] + 0x28))();
              pTVar4 = (unsigned char *)(**(code **)(*(int *)puVar49[-0x1f] + 0x3c))();
              uVar59 = puVar49[-0x16];
              iVar58 = 0;
            }
            else {
              local_780 = pTVar4;
              iVar58 = (**(code **)(*(int *)puVar49[-9] + 0x18))();
              piVar63 = *(int **)(iVar58 + 0x30);
              pTVar8 = (unsigned char *)
                       (**(code **)(*(int *)puVar49[-0x1f] + 0x28))((int *)puVar49[-0x1f]);
              pTVar4 = (unsigned char *)(**(code **)(*(int *)puVar49[-0x1f] + 0x3c))();
              iVar58 = *piVar63;
              uVar59 = puVar49[-0x16];
            }
            iVar58 = TParseContext__arraySetMaxSize(param_1,pTVar8,pTVar4,iVar58,!bVar36,uVar59);
            if (iVar58 != 0) {
LAB_97ba475c:
              TParseContext__recover(param_1);
            }
          }
          else {
            iVar58 = (**(code **)(*(int *)puVar49[-9] + 0x18))();
            piVar63 = *(int **)(iVar58 + 0x30);
            (**(code **)(*(int *)puVar49[-0x1f] + 0x38))(&local_780);
            uVar59 = (uint)(local_77c <= *piVar63);
            local_780 = pTVar4;
            if (uVar59 != 0) {
              iVar58 = (**(code **)(*(int *)puVar49[-9] + 0x18))();
              TParseContext__error
                        ((int)param_1,(char *)puVar49[-0x16],"","[",
                         "array index out of range \'%d\'",**(undefined4 **)(iVar58 + 0x30),uVar59,
                         param_8);
              goto LAB_97ba475c;
            }
          }
        }
        uVar16 = *(undefined4 *)param_1;
        uVar27 = 0x2d;
      }
      else {
        iVar58 = (**(code **)(*(int *)puVar49[-0x1f] + 0x54))();
        if (iVar58 != 0) {
          (**(code **)(*(int *)puVar49[-0x1f] + 0x38))(&local_820);
          local_820 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
          if (local_81c == (unsigned char *)0x0) {
            TParseContext__error
                      ((int)param_1,(char *)puVar49[-0x16],"","[",
                       "array must be redeclared with a size before being indexed with a variable",
                       pTVar37,iVar57,param_8);
            TParseContext__recover(param_1);
          }
        }
        uVar16 = *(undefined4 *)param_1;
        uVar27 = 0x2e;
      }
      local_878 = (unsigned char *)TIntermediate__addIndex
                                     (uVar16,uVar27,puVar49[-0x1f],puVar49[-9],puVar49[-0x16]);
    }
LAB_97ba47fc:
    pTVar4 = local_878;
    if (local_878 == (unsigned char *)0x0) {
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      pcVar9 = (unsigned char *)TPoolAllocator__allocate(pTVar17,4);
      *(undefined4 *)pcVar9 = 0;
      local_850 = local_5c + -0x610c;
      local_82c = (unsigned char *)((uint)local_82c & 0x1ff | 0x4080800);
      local_84c = pTVar4;
      local_848 = pTVar4;
      local_844 = pTVar4;
      local_840 = pTVar4;
      local_83c = pTVar4;
      local_838 = pTVar4;
      local_834 = pTVar4;
      local_830 = pTVar4;
      pTVar14 = *(unsigned char **)param_1;
      uVar59 = puVar49[-0x16];
      goto LAB_97ba7d0c;
    }
    iVar58 = (**(code **)(*(int *)puVar49[-0x1f] + 0x54))();
    in_cr0 = (iVar58 == 0) << 1;
    if (iVar58 == 0) {
      iVar58 = (**(code **)(*(int *)puVar49[-0x1f] + 0x50))();
      if (iVar58 != 0) {
        (**(code **)(*(int *)puVar49[-0x1f] + 0x38))(&local_850);
        pTVar4 = local_5c + -0x610c;
        local_850 = pTVar4;
        if ((uint)local_82c >> 0x19 == 2) {
          uVar59 = (**(code **)(*(int *)puVar49[-0x1f] + 0x40))();
          uVar52 = (**(code **)(*(int *)puVar49[-0x1f] + 0x48))();
          local_7fc = (unsigned char *)((uVar52 & 0xff) << 0xb |
                               (uVar59 & 0x3f) << 0x13 | (uint)local_7fc & 0x1ff | 0x4000000);
          local_800 = (unsigned char *)0x0;
          goto LAB_97ba4bc0;
        }
      }
      pTVar4 = (unsigned char *)(**(code **)(*(int *)puVar49[-0x1f] + 0x50))();
      in_cr0 = (pTVar4 == (unsigned char *)0x0) << 1;
      if (pTVar4 != (unsigned char *)0x0) {
        uVar59 = (**(code **)(*(int *)puVar49[-0x1f] + 0x40))();
        uVar52 = (**(code **)(*(int *)puVar49[-0x1f] + 0x48))();
        local_800 = (unsigned char *)0x0;
        pTVar4 = local_5c + -0x610c;
        local_7fc = (unsigned char *)((uVar52 & 0xff) << 0xb |
                             (uVar59 & 0x3f) << 0x13 | (uint)local_7fc & 0x1ff);
        local_81c = (unsigned char *)0x0;
        local_818 = (unsigned char *)0x0;
        local_814 = (unsigned char *)0x0;
        local_810 = (unsigned char *)0x0;
        local_80c = (unsigned char *)0x0;
        local_808 = (unsigned char *)0x0;
        local_804 = (unsigned char *)0x0;
        local_820 = pTVar4;
        (**(code **)(*(int *)local_878 + 0x34))(local_878,&local_820);
        pTVar15 = local_878;
        local_820 = pTVar4;
        pTVar50 = local_7f0;
        pTVar2 = local_750;
        break;
      }
      iVar58 = (**(code **)(*(int *)puVar49[-0x1f] + 0x58))();
      if (iVar58 != 0) {
        (**(code **)(*(int *)puVar49[-0x1f] + 0x38))(&local_820);
        pTVar50 = local_5c + -0x610c;
        local_820 = pTVar50;
        if ((uint)local_7fc >> 0x19 == 2) {
          uVar59 = (**(code **)(*(int *)puVar49[-0x1f] + 0x40))();
          local_7cc = (uVar59 & 0x3f) << 0x13 | local_7cc & 0x9ff | 0x4000000 | 0x800;
          local_7f0 = pTVar50;
          local_7ec = pTVar4;
          local_7e8 = pTVar4;
          local_7e4 = pTVar4;
          local_7e0 = pTVar4;
          local_7dc = pTVar4;
          local_7d8 = pTVar4;
          local_7d4 = pTVar4;
          local_7d0 = pTVar4;
          (**(code **)(*(int *)local_878 + 0x34))(local_878,&local_7f0);
          pTVar15 = local_878;
          pTVar2 = local_750;
          break;
        }
      }
      iVar58 = (**(code **)(*(int *)puVar49[-0x1f] + 0x58))();
      if (iVar58 == 0) {
        (**(code **)(*(int *)puVar49[-0x1f] + 0x38))(&local_7f0);
        (**(code **)(*(int *)local_878 + 0x34))(local_878,&local_7f0);
        pTVar15 = local_878;
        pTVar50 = local_5c + -0x610c;
        pTVar2 = local_750;
      }
      else {
        uVar59 = (**(code **)(*(int *)puVar49[-0x1f] + 0x40))();
        pTVar50 = local_5c + -0x610c;
        local_7cc = (uVar59 & 0x3f) << 0x13 | local_7cc & 0x9ff | 0x800;
        local_7ec = (unsigned char *)0x0;
        local_7e8 = (unsigned char *)0x0;
        local_7e4 = (unsigned char *)0x0;
        local_7e0 = (unsigned char *)0x0;
        local_7dc = (unsigned char *)0x0;
        local_7d8 = (unsigned char *)0x0;
        local_7d4 = (unsigned char *)0x0;
        local_7d0 = (unsigned char *)0x0;
        local_7f0 = pTVar50;
        (**(code **)(*(int *)local_878 + 0x34))(local_878,&local_7f0);
        pTVar15 = local_878;
        pTVar2 = local_750;
      }
      break;
    }
    (**(code **)(*(int *)puVar49[-0x1f] + 0x38))(&local_850);
    pTVar37 = local_848;
    pTVar4 = local_5c + -0x610c;
    local_850 = pTVar4;
    if (local_848 == (unsigned char *)0x0) {
      uVar59 = (**(code **)(*(int *)puVar49[-0x1f] + 0x40))();
      uVar52 = (**(code **)(*(int *)puVar49[-0x1f] + 0x48))();
      uVar56 = (**(code **)(*(int *)puVar49[-0x1f] + 0x50))();
      local_7fc = (unsigned char *)((uVar56 & 1) << 10 |
                           (uVar52 & 0xff) << 0xb |
                           (uVar59 & 0x3f) << 0x13 | (uint)local_7fc & 0x1ff);
      local_800 = pTVar37;
LAB_97ba4bc0:
      local_820 = pTVar4;
      local_81c = local_800;
      local_818 = local_800;
      local_814 = local_800;
      local_810 = local_800;
      local_80c = local_800;
      local_808 = local_800;
      local_804 = local_800;
      (**(code **)(*(int *)local_878 + 0x34))(local_878,&local_820);
      pTVar15 = local_878;
      local_820 = pTVar4;
      pTVar50 = local_7f0;
      pTVar2 = local_750;
      break;
    }
    local_64 = (unsigned char *)0xa7b8374c;
    (**(code **)(*(int *)puVar49[-0x1f] + 0x38))(&local_7f0);
    pTVar37 = local_7e8;
    (**(code **)(*(int *)puVar49[-0x1f] + 0x38))(local_750);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_((unsigned char *)&local_7c0,local_740);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_7b0,(unsigned char *)&local_7c0);
    local_7fc = (unsigned char *)((uint)local_7fc & 0x9ff | 0x700800);
    local_800 = (unsigned char *)0x0;
    local_81c = (unsigned char *)0x0;
    local_818 = pTVar37;
    local_814 = (unsigned char *)0x0;
    local_80c = (unsigned char *)0x0;
    local_804 = (unsigned char *)0x0;
    local_820 = pTVar4;
    local_808 = (unsigned char *)TType__setStructSize((unsigned char *)&local_820,(unsigned char *)pTVar37);
    pcVar64 = local_7ac;
    local_7ac[*(int *)(local_7ac + -0xc)] = **(char **)(local_64 + -0x7cc4);
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar37 = (unsigned char *)TPoolAllocator__allocate(pTVar17,8);
    in_cr0 = (pTVar37 == (unsigned char *)0x0) << 1;
    pTVar4 = (unsigned char *)0x0;
    if (pTVar37 != (unsigned char *)0x0) {
      local_720[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (pTVar37,pcVar64,(unsigned char *)local_720);
      pTVar4 = pTVar37;
    }
    piVar63 = (int *)(local_7ac + -4);
    local_710[0] = local_7b0;
    do {
      iVar58 = *piVar63;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,piVar63);
        *piVar63 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    local_810 = pTVar4;
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_7ac + -0xc),local_710);
    }
    (**(code **)(*(int *)local_878 + 0x34))(local_878,(unsigned char *)&local_820);
    pTVar50 = local_5c + -0x610c;
    local_700[0] = local_7c0;
    piVar63 = (int *)(local_7bc - 4);
    do {
      iVar58 = *piVar63;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,piVar63);
        *piVar63 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    pTVar15 = local_878;
    local_820 = pTVar50;
    pTVar2 = pTVar50;
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_7bc - 0xc),local_700);
      pTVar15 = local_878;
    }
    break;
  case 10:
    iVar58 = (**(code **)(*(int *)puVar49[-0x14] + 0x54))();
    if (iVar58 != 0) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49,"cannot apply dot operator to an array",".","",
                 pTVar37,iVar57,param_8);
      TParseContext__recover(param_1);
    }
    pTVar4 = (unsigned char *)(**(code **)(*(int *)puVar49[-0x14] + 0x58))();
    in_cr0 = (pTVar4 == (unsigned char *)0x0) << 1;
    if (pTVar4 == (unsigned char *)0x0) {
      iVar58 = (**(code **)(*(int *)puVar49[-0x14] + 0x50))();
      if (iVar58 == 0) {
        iVar58 = (**(code **)(*(int *)puVar49[-0x14] + 0x40))();
        if (iVar58 != 0xe) {
          param_8 = puVar49[1];
          iVar57 = *(int *)(param_8 + 4);
          pcVar64 = " field selection requires structure, vector, or matrix on left hand side";
          goto LAB_97ba5784;
        }
        local_5c = (unsigned char *)0xa7b8374c;
        (**(code **)(*(int *)puVar49[-0x14] + 0x38))(&local_850);
        pTVar15 = local_848;
        local_850 = local_5c + -0x610c;
        pTVar37 = local_5c;
        if (local_848 == (unsigned char *)0x0) {
          pcVar31 = (char *)puVar49[-0xb];
          pcVar64 = "structure has no fields";
          pcVar33 = "Internal Error";
          goto LAB_97ba5548;
        }
        uVar59 = 0;
        goto LAB_97ba55dc;
      }
      iVar58 = (**(code **)(*(int *)puVar49[-0x14] + 0x48))();
      iVar58 = TParseContext__parseMatrixFields
                         (param_1,(unsigned char *)puVar49[1],iVar58,(unsigned char *)&local_850,*puVar49);
      if (iVar58 == 0) {
        local_850 = pTVar4;
        local_84c = pTVar4;
        local_848 = pTVar4;
        local_844 = pTVar4;
        TParseContext__recover(param_1);
      }
      pTVar15 = local_84c;
      if ((local_850 == (unsigned char *)0x0) && (local_84c == (unsigned char *)0x0)) {
        pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
        pcVar9 = (unsigned char *)TPoolAllocator__allocate(pTVar17,4);
        local_5c = (unsigned char *)0xa7b8374c;
        iVar58 = (**(code **)(*(int *)puVar49[-0x14] + 0x48))();
        pTVar4 = local_5c + -0x610c;
        *(unsigned char **)pcVar9 = local_848 + (int)local_844 * iVar58;
        local_81c = (unsigned char *)((uint)local_81c & 0x1ff | 0x4100800);
        local_83c = pTVar15;
        local_838 = pTVar15;
        local_834 = pTVar15;
        local_830 = pTVar15;
        local_82c = pTVar15;
        local_828 = pTVar15;
        local_824 = pTVar15;
        local_820 = pTVar15;
        local_840 = pTVar4;
        uVar16 = TIntermediate__addConstantUnion
                           (*(unsigned char **)param_1,pcVar9,(unsigned char *)&local_840,*puVar49);
        local_840 = pTVar4;
        local_878 = (unsigned char *)TIntermediate__addIndex
                                       (*(undefined4 *)param_1,0x2d,puVar49[-0x14],uVar16,
                                        puVar49[-0xb]);
        uVar59 = (**(code **)(*(int *)puVar49[-0x14] + 0x40))();
        local_81c = (unsigned char *)((uVar59 & 0x3f) << 0x13 | (uint)local_81c & 0x1ff | 0x800);
        local_83c = pTVar15;
        local_838 = pTVar15;
        local_834 = pTVar15;
        local_830 = pTVar15;
        local_82c = pTVar15;
        local_828 = pTVar15;
        local_824 = pTVar15;
        local_820 = pTVar15;
        local_840 = pTVar4;
        (**(code **)(*(int *)local_878 + 0x34))(local_878,(unsigned char *)&local_840);
        pTVar15 = local_878;
        local_840 = pTVar4;
        pTVar50 = local_7f0;
        pTVar2 = local_750;
      }
      else {
        TParseContext__error
                  ((int)param_1,(char *)puVar49[-0xb]," non-scalar fields not implemented yet",".",
                   "",pTVar37,iVar57,param_8);
        TParseContext__recover(param_1);
        pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
        pcVar9 = (unsigned char *)TPoolAllocator__allocate(pTVar17,4);
        *(undefined4 *)pcVar9 = 0;
        local_81c = (unsigned char *)((uint)local_81c & 0x9ff | 0x4100800);
        local_840 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
        local_83c = pTVar4;
        local_838 = pTVar4;
        local_834 = pTVar4;
        local_830 = pTVar4;
        local_82c = pTVar4;
        local_828 = pTVar4;
        local_824 = pTVar4;
        local_820 = pTVar4;
        uVar16 = TIntermediate__addConstantUnion
                           (*(unsigned char **)param_1,pcVar9,(unsigned char *)&local_840,*puVar49);
        local_840 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
        local_878 = (unsigned char *)TIntermediate__addIndex
                                       (*(undefined4 *)param_1,0x2d,puVar49[-0x14],uVar16,
                                        puVar49[-0xb]);
        uVar59 = (**(code **)(*(int *)puVar49[-0x14] + 0x40))();
        uVar52 = (**(code **)(*(int *)puVar49[-0x14] + 0x48))();
        local_81c = (unsigned char *)((uVar52 & 0xff) << 0xb |
                             (uVar59 & 0x3f) << 0x13 | (uint)local_81c & 0x1ff);
        local_840 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
        local_83c = pTVar4;
        local_838 = pTVar4;
        local_834 = pTVar4;
        local_830 = pTVar4;
        local_82c = pTVar4;
        local_828 = pTVar4;
        local_824 = pTVar4;
        local_820 = pTVar4;
        (**(code **)(*(int *)local_878 + 0x34))(local_878,(unsigned char *)&local_840);
        local_840 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
        pTVar15 = local_878;
        pTVar50 = local_7f0;
        pTVar2 = local_750;
      }
      break;
    }
    iVar58 = (**(code **)(*(int *)puVar49[-0x14] + 0x48))();
    pTVar4 = (unsigned char *)TParseContext__parseVectorFields
                                (param_1,(unsigned char *)puVar49[1],iVar58,(unsigned char *)&local_850,
                                 *puVar49);
    in_cr0 = (pTVar4 == (unsigned char *)0x0) << 1;
    if (pTVar4 == (unsigned char *)0x0) {
      local_840 = (unsigned char *)0x1;
      local_850 = pTVar4;
      TParseContext__recover(param_1);
    }
    local_5c = (unsigned char *)0xa7b8374c;
    (**(code **)(*(int *)puVar49[-0x14] + 0x38))(&local_830);
    pTVar4 = local_5c + -0x610c;
    local_830 = pTVar4;
    if ((uint)local_80c >> 0x19 == 2) {
      local_878 = (unsigned char *)TParseContext__addConstVectorNode
                                     (param_1,(unsigned char *)&local_850,
                                      (unsigned char *)puVar49[-0x14],*puVar49);
      if (local_878 == (unsigned char *)0x0) goto LAB_97ba5554;
      uVar59 = (**(code **)(*(int *)puVar49[-0x14] + 0x40))();
      local_7dc = (unsigned char *)((*(uint *)(*(int *)(puVar49[1] + 4) + -0xc) & 0xff) << 0xb |
                           (uVar59 & 0x3f) << 0x13 | (uint)local_7dc & 0x1ff | 0x4000000);
      pcVar42 = *(code **)(*(int *)local_878 + 0x34);
LAB_97ba50cc:
      local_7e0 = (unsigned char *)0x0;
      local_7e4 = (unsigned char *)0x0;
      local_7e8 = (unsigned char *)0x0;
      local_7ec = (unsigned char *)0x0;
      local_7f0 = (unsigned char *)0x0;
      local_7f4 = (unsigned char *)0x0;
      local_7f8 = (unsigned char *)0x0;
      local_7fc = (unsigned char *)0x0;
      local_800 = pTVar4;
      (*pcVar42)(local_878,&local_800);
      pTVar15 = local_878;
      local_800 = pTVar4;
      pTVar50 = local_7f0;
      pTVar2 = local_750;
      break;
    }
    if (local_840 == (unsigned char *)0x1) {
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      pcVar9 = (unsigned char *)TPoolAllocator__allocate(pTVar17,4);
      *(unsigned char **)pcVar9 = local_850;
      local_7dc = (unsigned char *)((uint)local_7dc & 0x1ff | 0x4100800);
      local_7fc = (unsigned char *)0x0;
      local_7f8 = (unsigned char *)0x0;
      local_7f4 = (unsigned char *)0x0;
      local_7f0 = (unsigned char *)0x0;
      local_7ec = (unsigned char *)0x0;
      local_7e8 = (unsigned char *)0x0;
      local_7e4 = (unsigned char *)0x0;
      local_7e0 = (unsigned char *)0x0;
      local_800 = pTVar4;
      uVar16 = TIntermediate__addConstantUnion
                         (*(unsigned char **)param_1,pcVar9,(unsigned char *)&local_800,*puVar49);
      local_800 = pTVar4;
      local_878 = (unsigned char *)TIntermediate__addIndex
                                     (*(undefined4 *)param_1,0x2d,puVar49[-0x14],uVar16,
                                      puVar49[-0xb]);
      uVar59 = (**(code **)(*(int *)puVar49[-0x14] + 0x40))();
      local_7dc = (unsigned char *)((uVar59 & 0x3f) << 0x13 | (uint)local_7dc & 0x1ff | 0x800);
      pcVar42 = *(code **)(*(int *)local_878 + 0x34);
      goto LAB_97ba50cc;
    }
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_800,(unsigned char *)puVar49[1]);
    uVar16 = TIntermediate__addSwizzle
                       (*(unsigned char **)param_1,(unsigned char *)&local_850,*puVar49);
    local_878 = (unsigned char *)TIntermediate__addIndex
                                   (*(undefined4 *)param_1,0x30,puVar49[-0x14],uVar16,puVar49[-0xb])
    ;
    iVar58 = *(int *)local_878;
    uVar59 = (**(code **)(*(int *)puVar49[-0x14] + 0x40))();
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
    local_7f0 = pTVar4;
    (**(code **)(iVar58 + 0x34))(local_878,&local_7f0);
    pTVar37 = local_7fc + -4;
    local_6f0[0] = local_800;
    paVar12 = (unsigned char *)(local_7fc + -0xc);
    do {
      iVar58 = *(int *)pTVar37;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar37);
        *(int *)pTVar37 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_6f0;
    local_7f0 = pTVar4;
    goto LAB_97ba869c;
  case 0xb:
    iVar58 = TParseContext__lValueErrorCheck(param_1,*puVar49,"++",(unsigned char *)puVar49[-9]);
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    local_878 = (unsigned char *)TIntermediate__addUnaryMath
                                   (*(undefined4 *)param_1,9,puVar49[-9],*puVar49,
                                    *(undefined4 *)((int)param_1 + 4));
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString(&local_850,puVar49[-9] + 8);
    TParseContext__unaryOpError(param_1,*puVar49,"++",&local_850);
    pTVar4 = local_84c + -4;
    local_6e0[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      ppTVar25 = local_6e0;
LAB_97ba5844:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_84c + -0xc),ppTVar25);
    }
    goto LAB_97ba5848;
  case 0xc:
    iVar58 = TParseContext__lValueErrorCheck(param_1,*puVar49,"--",(unsigned char *)puVar49[-9]);
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    local_878 = (unsigned char *)TIntermediate__addUnaryMath
                                   (*(undefined4 *)param_1,10,puVar49[-9],*puVar49,
                                    *(undefined4 *)((int)param_1 + 4));
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString(&local_850,puVar49[-9] + 8);
    TParseContext__unaryOpError(param_1,*puVar49,"--",&local_850);
    pTVar4 = local_84c + -4;
    local_6d0[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    ppTVar25 = local_6d0;
    if (iVar58 < 1) goto LAB_97ba5844;
LAB_97ba5848:
    TParseContext__recover(param_1);
switchD_97ba39c8_caseD_6:
    pTVar15 = (unsigned char *)puVar49[-9];
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0xd:
    iVar58 = TParseContext__integerErrorCheck(param_1,(unsigned char *)puVar49[2],"[]");
    goto LAB_97ba82e8;
  case 0xe:
    pTVar10 = (unsigned char *)puVar49[4];
    iVar57 = *(int *)(pTVar10 + 0x4c);
    if (iVar57 != 0) {
      local_5c = (unsigned char *)0xa7b8374c;
      local_830 = (unsigned char *)0x0;
      local_82c = (unsigned char *)((uint)local_82c & 0x9ff | 0x800);
      in_cr0 = (local_82c == (unsigned char *)0x0) << 1;
      local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      local_84c = (unsigned char *)0x0;
      local_848 = (unsigned char *)0x0;
      local_844 = (unsigned char *)0x0;
      local_840 = (unsigned char *)0x0;
      local_83c = (unsigned char *)0x0;
      local_838 = (unsigned char *)0x0;
      local_834 = (unsigned char *)0x0;
      iVar58 = TParseContext__constructorErrorCheck
                         (param_1,*puVar49,puVar49[2],pTVar10,iVar57,&local_850);
      if (iVar58 == 0) {
        local_878 = (unsigned char *)TParseContext__addConstructor
                                       (param_1,puVar49[2],&local_850,iVar57,pTVar10,*puVar49);
      }
      else {
        local_878 = (unsigned char *)0x0;
      }
      if (local_878 == (unsigned char *)0x0) {
        TParseContext__recover(param_1);
        local_878 = (unsigned char *)TIntermediate__setAggregateOperator
                                       (*(undefined4 *)param_1,0,iVar57,*puVar49);
      }
      (**(code **)(*(int *)local_878 + 0x34))(local_878,&local_850);
      local_850 = local_5c + -0x610c;
      goto LAB_97ba5e28;
    }
    pTVar15 = (unsigned char *)TParseContext__findFunction(param_1,*puVar49,pTVar10,(bool *)&local_88);
    in_cr0 = (pTVar15 == (unsigned char *)0x0) << 1;
    if (pTVar15 == (unsigned char *)0x0) {
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      pcVar9 = (unsigned char *)TPoolAllocator__allocate(pTVar17,4);
      *(undefined4 *)pcVar9 = 0;
      local_82c = (unsigned char *)((uint)local_82c & 0x1ff | 0x4080800);
      local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      local_84c = pTVar15;
      local_848 = pTVar15;
      local_844 = pTVar15;
      local_840 = pTVar15;
      local_83c = pTVar15;
      local_838 = pTVar15;
      local_834 = pTVar15;
      local_830 = pTVar15;
      local_878 = (unsigned char *)TIntermediate__addConstantUnion
                                     (*(unsigned char **)param_1,pcVar9,(unsigned char *)&local_850,*puVar49
                                     );
      local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      TParseContext__recover(param_1);
      goto LAB_97ba5e28;
    }
    iVar57 = *(int *)(pTVar15 + 0x4c);
    if ((local_88 == 0) || (iVar57 == 0)) {
      local_878 = (unsigned char *)TIntermediate__setAggregateOperator
                                     (*(undefined4 *)param_1,puVar49[2],2,*puVar49);
      (**(code **)(*(int *)local_878 + 0x34))(local_878,pTVar15 + 0x1c);
      if (local_88 == 0) {
        piVar63 = (int *)(**(code **)(*(int *)local_878 + 0x1c))();
        (**(code **)(*piVar63 + 0x70))();
      }
      piVar63 = (int *)(**(code **)(*(int *)local_878 + 0x1c))();
      iVar58 = *piVar63;
      uVar16 = (**(code **)(*(int *)pTVar15 + 8))(pTVar15);
      (**(code **)(iVar58 + 0x68))(piVar63,uVar16);
      piVar63 = (int *)(**(code **)(*(int *)local_878 + 0x1c))();
      iVar58 = (**(code **)(*piVar63 + 0x78))();
      for (iVar57 = 0; iVar57 < *(int *)(pTVar15 + 0x14) - *(int *)(pTVar15 + 0x10) >> 3;
          iVar57 = iVar57 + 1) {
        iVar62 = (**(code **)(**(int **)(*(int *)(pTVar15 + 0x10) + iVar57 * 8 + 4) + 0x24))();
        if (iVar62 - 10U < 2) {
          piVar63 = (int *)(**(code **)(*(int *)local_878 + 0x1c))();
          iVar7 = (**(code **)(*piVar63 + 100))();
          iVar28 = *(int *)(iVar7 + 4);
          pTVar30 = (unsigned char *)(**(code **)(**(int **)(iVar28 + iVar57 * 4) + 0x14))();
          iVar7 = (*(code *)**(undefined4 **)local_878)();
          iVar7 = TParseContext__lValueErrorCheck(param_1,iVar7,"assign",pTVar30);
          if (iVar7 != 0) {
            pcVar64 = (char *)(*(code *)**(undefined4 **)puVar49[2])();
            TParseContext__error
                      ((int)param_1,pcVar64,
                       "Constant value cannot be passed for \'out\' or \'inout\' parameters.",
                       "Error","",pTVar37,iVar28,param_8);
            TParseContext__recover(param_1);
          }
        }
        piVar63 = *(int **)(iVar58 + 8);
        local_84 = iVar62;
        if (piVar63 == *(int **)(iVar58 + 0xc)) {
          std__vector_int_pool_allocator_int_____M_insert_aux(iVar58,piVar63,&local_84);
        }
        else {
          iVar7 = 0;
          if (piVar63 != (int *)0x0) {
            *piVar63 = iVar62;
            iVar7 = *(int *)(iVar58 + 8);
          }
          *(int *)(iVar58 + 8) = iVar7 + 4;
        }
      }
    }
    else {
      if (*(int *)(pTVar15 + 0x14) - *(int *)(pTVar15 + 0x10) >> 3 == 1) {
        local_878 = (unsigned char *)TIntermediate__addUnaryMath
                                       (*(undefined4 *)param_1,iVar57,puVar49[2],0,
                                        *(undefined4 *)((int)param_1 + 4));
        if (local_878 != (unsigned char *)0x0) goto LAB_97ba5d80;
        local_64 = (unsigned char *)0xa7b8374c;
        TType__getCompleteString(&local_850,puVar49[2] + 8);
        pTVar37 = local_84c;
        local_84c[*(int *)(local_84c + -0xc)] = **(unsigned char **)(local_64 + -0x7cc4);
        pTVar15 = local_84c;
        pcVar64 = (char *)(*(code *)**(undefined4 **)puVar49[2])();
        TParseContext__error
                  ((int)param_1,pcVar64," wrong operand type","Internal Error",
                   "built in unary operator function.  Type: %s",pTVar37,pTVar15,param_8);
        pTVar15 = local_84c + -4;
        local_6c0[0] = local_850;
        do {
          iVar53 = *(int *)pTVar15;
          if (in_RESERVE != '\0') {
            iVar57 = storeWordConditionalIndexed(iVar53 + -1,0,pTVar15);
            *(int *)pTVar15 = iVar57;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
        if (iVar53 < 1) {
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                    ((unsigned char *)(local_84c + -0xc),local_6c0);
        }
        goto LAB_97bac050;
      }
      local_878 = (unsigned char *)TIntermediate__setAggregateOperator
                                     (*(undefined4 *)param_1,puVar49[2],iVar57,*puVar49);
    }
LAB_97ba5d80:
    (**(code **)(*(int *)local_878 + 0x34))(local_878,pTVar15 + 0x1c);
LAB_97ba5e28:
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (pTVar10 != (unsigned char *)0x0) {
      iVar58 = *(int *)pTVar10;
LAB_97ba86fc:
      (**(code **)(iVar58 + 4))(pTVar10);
      pTVar15 = local_878;
      pTVar50 = local_7f0;
      pTVar2 = local_750;
    }
    break;
  case 0xf:
  case 0x10:
    _memcpy(&local_880,puVar49 + -0xb,0x2c);
    local_880 = *puVar49;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x11:
    local_870 = (unsigned char *)puVar49[-7];
    goto LAB_97ba5e64;
  case 0x12:
    local_870 = (unsigned char *)puVar49[4];
LAB_97ba5e64:
    pTVar15 = (unsigned char *)0x0;
    break;
  case 0x13:
    local_840 = (unsigned char *)0x0;
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar4 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    (**(code **)(*(int *)puVar49[2] + 0x38))();
    local_850 = local_840;
    uVar59 = puVar49[-7];
    puVar26 = *(uint **)(uVar59 + 0x14);
    local_84c = pTVar4;
    local_83c = pTVar4;
    if (puVar26 == *(uint **)(uVar59 + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                (uVar59 + 0xc,*(undefined4 *)(uVar59 + 0x14),&local_850);
    }
    else {
      iVar58 = 0;
      if (puVar26 != (uint *)0x0) {
        puVar26[1] = (uint)pTVar4;
        *puVar26 = (uint)local_840;
        iVar58 = *(int *)(uVar59 + 0x14);
      }
      *(int *)(uVar59 + 0x14) = iVar58 + 8;
    }
    pTVar4 = local_84c;
    iVar58 = *(int *)(local_84c + 0x14);
    if (iVar58 == 0) {
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      psVar11 = (unsigned char *)TPoolAllocator__allocate(pTVar17,8);
      in_cr0 = (psVar11 == (unsigned char *)0x0) << 1;
      psVar22 = (unsigned char *)0x0;
      if (psVar11 != (unsigned char *)0x0) {
        local_6b0[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(psVar11,"",(unsigned char *)local_6b0)
        ;
        psVar22 = psVar11;
      }
      *(unsigned char **)(pTVar4 + 0x14) = psVar22;
      ((int (*)())TType__buildMangledName)(pTVar4,psVar22);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(*(void **)(pTVar4 + 0x14),1,';');
      iVar58 = *(int *)(pTVar4 + 0x14);
    }
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_
              ((unsigned char *)&local_840,(unsigned char *)(uVar59 + 0x44),iVar58);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
              ((unsigned char *)(uVar59 + 0x44),(unsigned char *)&local_840);
    pTVar4 = local_83c + -4;
    local_6a0[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_6a0);
    }
    local_870 = (unsigned char *)puVar49[-7];
    pTVar15 = (unsigned char *)puVar49[2];
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x14:
    local_840 = (unsigned char *)0x0;
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar4 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    (**(code **)(*(int *)puVar49[2] + 0x38))();
    local_850 = local_840;
    uVar59 = puVar49[-0x12];
    puVar26 = *(uint **)(uVar59 + 0x14);
    local_84c = pTVar4;
    local_83c = pTVar4;
    if (puVar26 == *(uint **)(uVar59 + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                (uVar59 + 0xc,*(undefined4 *)(uVar59 + 0x14),&local_850);
    }
    else {
      iVar58 = 0;
      if (puVar26 != (uint *)0x0) {
        puVar26[1] = (uint)pTVar4;
        *puVar26 = (uint)local_840;
        iVar58 = *(int *)(uVar59 + 0x14);
      }
      *(int *)(uVar59 + 0x14) = iVar58 + 8;
    }
    pTVar4 = local_84c;
    iVar58 = *(int *)(local_84c + 0x14);
    if (iVar58 == 0) {
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      psVar11 = (unsigned char *)TPoolAllocator__allocate(pTVar17,8);
      in_cr0 = (psVar11 == (unsigned char *)0x0) << 1;
      psVar22 = (unsigned char *)0x0;
      if (psVar11 != (unsigned char *)0x0) {
        local_690[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(psVar11,"",(unsigned char *)local_690)
        ;
        psVar22 = psVar11;
      }
      *(unsigned char **)(pTVar4 + 0x14) = psVar22;
      ((int (*)())TType__buildMangledName)(pTVar4,psVar22);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(*(void **)(pTVar4 + 0x14),1,';');
      iVar58 = *(int *)(pTVar4 + 0x14);
    }
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_
              ((unsigned char *)&local_840,(unsigned char *)(uVar59 + 0x44),iVar58);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
              ((unsigned char *)(uVar59 + 0x44),(unsigned char *)&local_840);
    pTVar4 = local_83c + -4;
    local_680[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_680);
    }
    local_870 = (unsigned char *)puVar49[-0x12];
    pTVar14 = *(unsigned char **)param_1;
    pTVar23 = (unsigned char *)puVar49[-0x14];
    pTVar20 = (unsigned char *)puVar49[2];
LAB_97ba97d4:
    uVar59 = puVar49[-0xb];
LAB_97ba97d8:
    pTVar15 = (unsigned char *)TIntermediate__growAggregate(pTVar14,pTVar23,pTVar20,uVar59);
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x15:
    local_870 = (unsigned char *)puVar49[-7];
    break;
  case 0x16:
    if (puVar49[1] != 0x75) {
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      pTVar4 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x54);
      uVar52 = puVar49[1];
      puVar6 = PTR_vtable_a7b7c0f4 + 8;
      *(int *)(pTVar4 + 4) = 0;
      *(undefined **)pTVar4 = puVar6;
      local_5c = (unsigned char *)0xa7b8374c;
      local_640 = GetGlobalPoolAllocator();
      *(int *)(pTVar4 + 0x18) = 0;
      *(int *)(pTVar4 + 0x10) = 0;
      *(int *)(pTVar4 + 0x14) = 0;
      *(unsigned char **)(pTVar4 + 0x1c) = local_5c + -0x610c;
      *(int *)(pTVar4 + 0xc) = local_640;
      iVar58 = DAT_a7b7ba84;
      *(int *)(pTVar4 + 0x20) = 0;
      uVar59 = *(uint *)(pTVar4 + 0x40) & 0x9ff | 0x800;
      in_cr0 = (uVar59 == 0) << 1;
      *(int *)(pTVar4 + 0x24) = 0;
      *(uint *)(pTVar4 + 0x40) = uVar59;
      piVar63 = (int *)(iVar58 + 8);
      *(int *)(pTVar4 + 0x28) = 0;
      *(int *)(pTVar4 + 0x2c) = 0;
      *(int *)(pTVar4 + 0x30) = 0;
      *(int *)(pTVar4 + 0x34) = 0;
      *(int *)(pTVar4 + 0x38) = 0;
      *(int *)(pTVar4 + 0x3c) = 0;
      do {
        if (in_RESERVE != '\0') {
          iVar57 = storeWordConditionalIndexed(*piVar63 + 1,0,piVar63);
          *piVar63 = iVar57;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1));
      local_630 = GetGlobalPoolAllocator();
      *(int *)(pTVar4 + 0x48) = iVar58 + 0xc;
      *(int *)(pTVar4 + 0x44) = local_630;
      *(uint *)(pTVar4 + 0x4c) = uVar52;
      *(int *)(pTVar4 + 0x50) = 0;
      pTVar15 = local_878;
      local_870 = pTVar4;
      pTVar50 = local_7f0;
      pTVar2 = local_750;
      break;
    }
    local_670[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              ((unsigned char *)&local_850,"",(unsigned char *)local_670);
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar37 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x54);
    uVar60 = puVar49[9];
    uVar51 = puVar49[1];
    *(undefined **)pTVar37 = PTR_vtable_a7b7c0f4 + 8;
    *(unsigned char **)(pTVar37 + 4) = (unsigned char *)&local_850;
    local_660 = GetGlobalPoolAllocator();
    *(int *)(pTVar37 + 0x18) = 0;
    *(int *)(pTVar37 + 0x10) = 0;
    *(int *)(pTVar37 + 0x14) = 0;
    local_5c = (unsigned char *)0xa7b8374c;
    *(int *)(pTVar37 + 0xc) = local_660;
    iVar35 = *(int *)(uVar60 + 8);
    iVar34 = *(int *)(uVar60 + 0xc);
    iVar32 = *(int *)(uVar60 + 0x10);
    iVar28 = *(int *)(uVar60 + 0x14);
    iVar7 = *(int *)(uVar60 + 0x18);
    iVar62 = *(int *)(uVar60 + 0x1c);
    iVar58 = *(int *)(uVar60 + 4);
    iVar57 = *(int *)(uVar60 + 0x20);
    *(undefined ***)(pTVar37 + 0x1c) = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(int *)(pTVar37 + 0x20) = iVar58;
    *(int *)(pTVar37 + 0x24) = iVar35;
    *(int *)(pTVar37 + 0x28) = iVar34;
    *(int *)(pTVar37 + 0x2c) = iVar32;
    *(int *)(pTVar37 + 0x30) = iVar28;
    *(int *)(pTVar37 + 0x34) = iVar7;
    *(int *)(pTVar37 + 0x38) = iVar62;
    *(int *)(pTVar37 + 0x3c) = iVar57;
    uVar3 = *(uint *)(pTVar37 + 0x40);
    uVar52 = *(uint *)(uVar60 + 0x24) & 0xfe000000;
    *(uint *)(pTVar37 + 0x40) = uVar52 | uVar3 & 0x1ffffff;
    uVar56 = (*(uint *)(uVar60 + 0x24) >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar37 + 0x40) = uVar56 | uVar52 | uVar3 & 0x7ffff;
    uVar59 = *(uint *)(uVar60 + 0x24) & 0x7f800;
    *(uint *)(pTVar37 + 0x40) = uVar59 | uVar56 | uVar52 | uVar3 & 0x7ff;
    uVar61 = (*(uint *)(uVar60 + 0x24) >> 10 & 1) << 10;
    *(uint *)(pTVar37 + 0x40) = uVar61 | uVar59 | uVar56 | uVar52 | uVar3 & 0x3ff;
    *(uint *)(pTVar37 + 0x40) =
         (*(uint *)(uVar60 + 0x24) >> 9 & 1) << 9 |
         uVar61 | uVar59 | uVar56 | uVar52 | uVar3 & 0x1ff;
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(pTVar37 + 0x44,(unsigned char *)&local_850);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(pTVar37 + 0x44,1,'(');
    *(uint *)(pTVar37 + 0x4c) = uVar51;
    *(int *)(pTVar37 + 0x50) = 0;
    pTVar4 = local_84c + -4;
    local_650[0] = local_850;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_650;
    local_870 = pTVar37;
    goto LAB_97ba869c;
  case 0x17:
    iVar58 = TParseContext__reservedErrorCheck(param_1,*puVar49,(unsigned char *)puVar49[1]);
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    local_82c = (unsigned char *)((uint)local_82c & 0x9ff | 0x800);
    in_cr0 = (local_82c == (unsigned char *)0x0) << 1;
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    local_84c = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_838 = (unsigned char *)0x0;
    local_834 = (unsigned char *)0x0;
    local_830 = (unsigned char *)0x0;
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar4 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x54);
    psVar22 = (unsigned char *)puVar49[1];
    *(undefined **)pTVar4 = PTR_vtable_a7b7c0f4 + 8;
    *(unsigned char **)(pTVar4 + 4) = psVar22;
    local_620 = GetGlobalPoolAllocator();
    *(int *)(pTVar4 + 0x18) = 0;
    *(int *)(pTVar4 + 0x10) = 0;
    *(int *)(pTVar4 + 0x14) = 0;
    *(int *)(pTVar4 + 0xc) = local_620;
    *(unsigned char **)(pTVar4 + 0x20) = local_84c;
    *(unsigned char **)(pTVar4 + 0x24) = local_848;
    *(unsigned char **)(pTVar4 + 0x28) = local_844;
    *(unsigned char **)(pTVar4 + 0x2c) = local_840;
    *(unsigned char **)(pTVar4 + 0x30) = local_83c;
    *(unsigned char **)(pTVar4 + 0x34) = local_838;
    *(undefined ***)(pTVar4 + 0x1c) = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(unsigned char **)(pTVar4 + 0x38) = local_834;
    *(unsigned char **)(pTVar4 + 0x3c) = local_830;
    uVar3 = *(uint *)(pTVar4 + 0x40);
    uVar52 = (uint)local_82c & 0xfe000000;
    *(uint *)(pTVar4 + 0x40) = uVar52 | uVar3 & 0x1ffffff;
    uVar56 = ((uint)local_82c >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar4 + 0x40) = uVar56 | uVar52 | uVar3 & 0x7ffff;
    uVar59 = (uint)local_82c & 0x7f800;
    *(uint *)(pTVar4 + 0x40) = uVar59 | uVar56 | uVar52 | uVar3 & 0x7ff;
    uVar61 = ((uint)local_82c >> 10 & 1) << 10;
    *(uint *)(pTVar4 + 0x40) = uVar61 | uVar59 | uVar56 | uVar52 | uVar3 & 0x3ff;
    *(uint *)(pTVar4 + 0x40) =
         ((uint)local_82c >> 9 & 1) << 9 | uVar61 | uVar59 | uVar56 | uVar52 | uVar3 & 0x1ff;
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(pTVar4 + 0x44,psVar22);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(pTVar4 + 0x44,1,'(');
    *(int *)(pTVar4 + 0x50) = 0;
    *(int *)(pTVar4 + 0x4c) = 0;
    pTVar15 = local_878;
    local_870 = pTVar4;
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x18:
    local_880 = *puVar49;
    local_87c = 0x68;
    break;
  case 0x19:
    local_880 = *puVar49;
    local_87c = 0x66;
    break;
  case 0x1a:
    local_880 = *puVar49;
    local_87c = 0x67;
    break;
  case 0x1b:
    local_880 = *puVar49;
    local_87c = 0x69;
    break;
  case 0x1c:
    local_880 = *puVar49;
    local_87c = 0x6a;
    break;
  case 0x1d:
    local_880 = *puVar49;
    local_87c = 0x6b;
    break;
  case 0x1e:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ","bvec2"
                 ,"","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *puVar49;
    local_87c = 0x6c;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x1f:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ","bvec3"
                 ,"","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *puVar49;
    local_87c = 0x6d;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x20:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ","bvec4"
                 ,"","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *puVar49;
    local_87c = 0x6e;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x21:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ","ivec2"
                 ,"","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *puVar49;
    local_87c = 0x6f;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x22:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ","ivec3"
                 ,"","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *puVar49;
    local_87c = 0x70;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x23:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ","ivec4"
                 ,"","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *puVar49;
    local_87c = 0x71;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x24:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ","mat2",
                 "","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *puVar49;
    local_87c = 0x72;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x25:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ","mat3",
                 "","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *puVar49;
    local_87c = 0x73;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x26:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ","mat4",
                 "","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *puVar49;
    local_87c = 0x74;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x27:
    local_85c = (unsigned char *)(puVar49[2] + 0xc);
    local_830 = (unsigned char *)0xe;
    local_824 = (unsigned char *)0x0;
    local_820 = (unsigned char *)0x0;
    local_86c = (unsigned char *)(uint)((uint)((*(int **)((int)param_1 + 4))[1] -
                                       **(int **)((int)param_1 + 4) >> 2) < 4);
    local_828 = (unsigned char *)0x1;
    local_858 = (unsigned char *)*puVar49;
    local_860 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_864 = (unsigned char *)0x0;
    local_87c = 0x75;
    local_870 = (unsigned char *)0xe;
    local_868 = (unsigned char *)0x1;
    local_850 = (unsigned char *)0xe;
    local_848 = (unsigned char *)0x1;
    local_880 = *puVar49;
    local_84c = local_86c;
    local_83c = local_85c;
    local_838 = local_858;
    local_82c = local_86c;
    local_81c = local_85c;
    local_818 = local_858;
    break;
  case 0x29:
    iVar58 = TParseContext__lValueErrorCheck(param_1,puVar49[-0xb],"++",(unsigned char *)puVar49[2]);
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    local_878 = (unsigned char *)TIntermediate__addUnaryMath
                                   (*(undefined4 *)param_1,0xb,puVar49[2],puVar49[-0xb],
                                    *(undefined4 *)((int)param_1 + 4));
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TParseContext__unaryOpError(param_1,puVar49[-0xb],"++",&local_850);
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_610[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_610;
    goto LAB_97ba82d4;
  case 0x2a:
    iVar58 = TParseContext__lValueErrorCheck(param_1,puVar49[-0xb],"--",(unsigned char *)puVar49[2]);
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    local_878 = (unsigned char *)TIntermediate__addUnaryMath
                                   (*(undefined4 *)param_1,0xc,puVar49[2],puVar49[-0xb],
                                    *(undefined4 *)((int)param_1 + 4));
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TParseContext__unaryOpError(param_1,puVar49[-0xb],"--",&local_850);
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_600[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      ppTVar25 = local_600;
      goto LAB_97ba69a8;
    }
    goto LAB_97ba82f0;
  case 0x2b:
    if (puVar49[-10] == 0) goto switchD_97ba39c8_caseD_2;
    local_878 = (unsigned char *)TIntermediate__addUnaryMath
                                   (*(undefined4 *)param_1,puVar49[-10],puVar49[2],puVar49[-0xb],
                                    *(undefined4 *)((int)param_1 + 4));
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    uVar59 = puVar49[-10];
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
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TParseContext__unaryOpError(param_1,puVar49[-0xb],pcVar64,&local_850);
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_5f0[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_5f0;
    goto LAB_97ba82d4;
  case 0x2c:
    local_880 = *puVar49;
    local_87c = 0;
    break;
  case 0x2d:
    local_880 = *puVar49;
    local_87c = 5;
    break;
  case 0x2e:
    local_880 = *puVar49;
    local_87c = 6;
    break;
  case 0x2f:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," reserved for future use ","~","","",iVar57,param_8)
      ;
      TParseContext__recover(param_1);
    }
    local_880 = *puVar49;
    local_87c = 8;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x31:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)puVar49[-0xb]," supported in vertex/fragment shaders only ",
                 "*","","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    local_878 = (unsigned char *)TIntermediate__addBinaryMath
                                   (*(undefined4 *)param_1,0x15,puVar49[-0x14],puVar49[2],
                                    puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],"*",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_5e0[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_5e0);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_5d0[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_5d0;
    goto LAB_97ba7a00;
  case 0x32:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)puVar49[-0xb]," supported in vertex/fragment shaders only ",
                 "/","","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    local_878 = (unsigned char *)TIntermediate__addBinaryMath
                                   (*(undefined4 *)param_1,0x16,puVar49[-0x14],puVar49[2],
                                    puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],"/",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_5c0[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_5c0);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_5b0[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_5b0;
    goto LAB_97ba7a00;
  case 0x33:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,(char *)puVar49[-0xb]," reserved for future use ","%","","",iVar57,
                 param_8);
      TParseContext__recover(param_1);
    }
    local_878 = (unsigned char *)TIntermediate__addBinaryMath
                                   (*(undefined4 *)param_1,0x17,puVar49[-0x14],puVar49[2],
                                    puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],"%",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_5a0[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_5a0);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_590[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_590;
    goto LAB_97ba7a00;
  case 0x35:
    local_878 = (unsigned char *)TIntermediate__addBinaryMath
                                   (*(undefined4 *)param_1,0x13,puVar49[-0x14],puVar49[2],
                                    puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],"+",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_580[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_580);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_570[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_570;
    goto LAB_97ba7a00;
  case 0x36:
    local_878 = (unsigned char *)TIntermediate__addBinaryMath
                                   (*(undefined4 *)param_1,0x14,puVar49[-0x14],puVar49[2],
                                    puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],"-",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_560[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_560);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_550[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_550;
    goto LAB_97ba7a00;
  case 0x38:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,(char *)puVar49[-0xb]," reserved for future use ","<<","","",iVar57,
                 param_8);
      TParseContext__recover(param_1);
    }
    local_878 = (unsigned char *)TIntermediate__addBinaryMath
                                   (*(undefined4 *)param_1,0x19,puVar49[-0x14],puVar49[2],
                                    puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],"<<",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_540[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_540);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_530[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_530;
    goto LAB_97ba7a00;
  case 0x39:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,(char *)puVar49[-0xb]," reserved for future use ",">>","","",iVar57,
                 param_8);
      TParseContext__recover(param_1);
    }
    local_878 = (unsigned char *)TIntermediate__addBinaryMath
                                   (*(undefined4 *)param_1,0x18,puVar49[-0x14],puVar49[2],
                                    puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],">>",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_520[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_520);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_510[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_510;
    goto LAB_97ba7a00;
  case 0x3b:
    pTVar15 = (unsigned char *)TIntermediate__addBinaryMath
                                 (*(undefined4 *)param_1,0x21,puVar49[-0x14],puVar49[2],
                                  puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (pTVar15 != (unsigned char *)0x0) break;
    local_878 = pTVar15;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],"<",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_500[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_500);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_4f0[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_4f0;
    goto LAB_97ba7bac;
  case 0x3c:
    pTVar15 = (unsigned char *)TIntermediate__addBinaryMath
                                 (*(undefined4 *)param_1,0x22,puVar49[-0x14],puVar49[2],
                                  puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (pTVar15 != (unsigned char *)0x0) break;
    local_878 = pTVar15;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],">",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_4e0[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_4e0);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_4d0[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_4d0;
    goto LAB_97ba7bac;
  case 0x3d:
    pTVar15 = (unsigned char *)TIntermediate__addBinaryMath
                                 (*(undefined4 *)param_1,0x23,puVar49[-0x14],puVar49[2],
                                  puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (pTVar15 != (unsigned char *)0x0) break;
    local_878 = pTVar15;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],"<=",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_4c0[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_4c0);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_4b0[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_4b0;
    goto LAB_97ba7bac;
  case 0x3e:
    pTVar15 = (unsigned char *)TIntermediate__addBinaryMath
                                 (*(undefined4 *)param_1,0x24,puVar49[-0x14],puVar49[2],
                                  puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (pTVar15 != (unsigned char *)0x0) break;
    local_878 = pTVar15;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],">=",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_4a0[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_4a0);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_490[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_490;
    goto LAB_97ba7bac;
  case 0x40:
    pTVar15 = (unsigned char *)TIntermediate__addBinaryMath
                                 (*(undefined4 *)param_1,0x1d,puVar49[-0x14],puVar49[2],
                                  puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (pTVar15 != (unsigned char *)0x0) break;
    local_878 = pTVar15;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],"==",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_480[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_480);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_470[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_470;
    goto LAB_97ba7bac;
  case 0x41:
    pTVar15 = (unsigned char *)TIntermediate__addBinaryMath
                                 (*(undefined4 *)param_1,0x1e,puVar49[-0x14],puVar49[2],
                                  puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (pTVar15 != (unsigned char *)0x0) break;
    local_878 = pTVar15;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],"!=",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_460[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_460);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_450[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_450;
    goto LAB_97ba7bac;
  case 0x43:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,(char *)puVar49[-0xb]," reserved for future use ","&","","",iVar57,
                 param_8);
      TParseContext__recover(param_1);
    }
    local_878 = (unsigned char *)TIntermediate__addBinaryMath
                                   (*(undefined4 *)param_1,0x1a,puVar49[-0x14],puVar49[2],
                                    puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],"&",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_440[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_440);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_430[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_430;
    goto LAB_97ba7a00;
  case 0x45:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,(char *)puVar49[-0xb]," reserved for future use ","^","","",iVar57,
                 param_8);
      TParseContext__recover(param_1);
    }
    local_878 = (unsigned char *)TIntermediate__addBinaryMath
                                   (*(undefined4 *)param_1,0x1c,puVar49[-0x14],puVar49[2],
                                    puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],"^",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_420[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_420);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_410[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_410;
    goto LAB_97ba7a00;
  case 0x47:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,(char *)puVar49[-0xb]," reserved for future use ","|","","",iVar57,
                 param_8);
      TParseContext__recover(param_1);
    }
    local_878 = (unsigned char *)TIntermediate__addBinaryMath
                                   (*(undefined4 *)param_1,0x1b,puVar49[-0x14],puVar49[2],
                                    puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],"|",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_400[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_400);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_3f0[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_3f0;
LAB_97ba7a00:
    if (!bVar36) {
LAB_97ba7f84:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(paVar12,ppTVar25);
    }
LAB_97ba5554:
    TParseContext__recover(param_1);
    pTVar15 = (unsigned char *)puVar49[-0x14];
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x49:
    pTVar15 = (unsigned char *)TIntermediate__addBinaryMath
                                 (*(undefined4 *)param_1,0x2c,puVar49[-0x14],puVar49[2],
                                  puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (pTVar15 != (unsigned char *)0x0) break;
    local_878 = pTVar15;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],"&&",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_3e0[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_3e0);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_3d0[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_3d0;
    goto LAB_97ba7bac;
  case 0x4b:
    pTVar15 = (unsigned char *)TIntermediate__addBinaryMath
                                 (*(undefined4 *)param_1,0x2b,puVar49[-0x14],puVar49[2],
                                  puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (pTVar15 != (unsigned char *)0x0) break;
    local_878 = pTVar15;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],"^^",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_3c0[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_3c0);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_3b0[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_3b0;
LAB_97ba7bac:
    if (!bVar36) {
LAB_97ba7c88:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(paVar12,ppTVar25);
    }
LAB_97ba7c8c:
    TParseContext__recover(param_1);
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pcVar9 = (unsigned char *)TPoolAllocator__allocate(pTVar17,4);
    *(unsigned char **)pcVar9 = pTVar15;
    local_82c = (unsigned char *)(((uint)pTVar15 & 1) << 9 |
                         ((uint)pTVar15 & 1) << 10 | (uint)local_82c & 0x1801ff | 0x4180800);
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    pTVar14 = *(unsigned char **)param_1;
    uVar59 = puVar49[-0xb];
    local_84c = pTVar15;
    local_848 = pTVar15;
    local_844 = pTVar15;
    local_840 = pTVar15;
    local_83c = pTVar15;
    local_838 = pTVar15;
    local_834 = pTVar15;
    local_830 = pTVar15;
LAB_97ba7d0c:
    pTVar4 = local_850;
    pTVar15 = (unsigned char *)TIntermediate__addConstantUnion(pTVar14,pcVar9,(unsigned char *)&local_850,uVar59);
    local_850 = pTVar4;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x4d:
    pTVar15 = (unsigned char *)TIntermediate__addBinaryMath
                                 (*(undefined4 *)param_1,0x2a,puVar49[-0x14],puVar49[2],
                                  puVar49[-0xb],*(undefined4 *)((int)param_1 + 4));
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (pTVar15 != (unsigned char *)0x0) break;
    local_878 = pTVar15;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],"||",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_3a0[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_3a0);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_390[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      ppTVar25 = local_390;
      goto LAB_97ba7c88;
    }
    goto LAB_97ba7c8c;
  case 0x4f:
    iVar58 = __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped
                       (param_1,puVar49[-0x21],(unsigned char *)puVar49[-0x2a]);
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    local_878 = (unsigned char *)__ZN13TIntermediate12addSelectionEP12TIntermTypedS1_S1_i
                                   (*(void **)param_1,(unsigned char *)puVar49[-0x2a],
                                    (unsigned char *)puVar49[-0x14],(unsigned char *)puVar49[2],
                                    puVar49[-0x21]);
    (**(code **)(*(int *)puVar49[-0x14] + 0x38))(&local_850);
    (**(code **)(*(int *)puVar49[2] + 0x38))(&local_820);
    bVar36 = false;
    if ((((uint)local_82c & 0x1fffe00) == ((uint)local_7fc & 0x1fffe00)) && (local_848 == local_818)
       ) {
      bVar36 = true;
    }
    local_5c = (unsigned char *)0xa7b8374c;
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    local_820 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    if (!bVar36) {
      local_878 = (unsigned char *)0x0;
    }
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0x21],":",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_380[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_380);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_370[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_370;
    goto LAB_97ba82d4;
  case 0x51:
    iVar58 = TParseContext__lValueErrorCheck
                       (param_1,puVar49[-0xb],"assign",(unsigned char *)puVar49[-0x14]);
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    local_878 = (unsigned char *)TIntermediate__addAssign
                                   (*(undefined4 *)param_1,puVar49[-10],puVar49[-0x14],puVar49[2],
                                    puVar49[-0xb]);
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__assignError(param_1,puVar49[-0xb],"assign",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_360[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_360);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_350[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (0 < iVar58) goto LAB_97ba5554;
    ppTVar25 = local_350;
    goto LAB_97ba7f84;
  case 0x52:
    local_880 = *puVar49;
    local_87c = 0x76;
    break;
  case 0x53:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ","*=",""
                 ,"",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *puVar49;
    local_87c = 0x79;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x54:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ","/=",""
                 ,"",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *puVar49;
    local_87c = 0x7e;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x55:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," reserved for future use ","%=","","",iVar57,param_8
                );
      TParseContext__recover(param_1);
    }
    local_880 = *puVar49;
    local_87c = 0x7f;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x56:
    local_880 = *puVar49;
    local_87c = 0x77;
    break;
  case 0x57:
    local_880 = *puVar49;
    local_87c = 0x78;
    break;
  case 0x58:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," reserved for future use ","<<=","","",iVar57,
                 param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *puVar49;
    local_87c = 0x83;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x59:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," reserved for future use ","<<=","","",iVar57,
                 param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *puVar49;
    local_87c = 0x84;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x5a:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," reserved for future use ","&=","","",iVar57,param_8
                );
      TParseContext__recover(param_1);
    }
    local_880 = *puVar49;
    local_87c = 0x80;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x5b:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," reserved for future use ","^=","","",iVar57,param_8
                );
      TParseContext__recover(param_1);
    }
    local_880 = *puVar49;
    local_87c = 0x82;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x5c:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," reserved for future use ","|=","","",iVar57,param_8
                );
      TParseContext__recover(param_1);
    }
    local_880 = *puVar49;
    local_87c = 0x81;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x5e:
    local_878 = (unsigned char *)TIntermediate__addComma
                                   (*(unsigned char **)param_1,(unsigned char *)puVar49[-0x14],
                                    (unsigned char *)puVar49[2],puVar49[-0xb]);
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (local_878 != (unsigned char *)0x0) break;
    TType__getCompleteString(&local_850,puVar49[2] + 8);
    TType__getCompleteString(&local_840,puVar49[-0x14] + 8);
    TParseContext__binaryOpError(param_1,puVar49[-0xb],",",&local_840,&local_850);
    pTVar4 = local_83c + -4;
    local_340[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_340);
    }
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_330[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_330;
LAB_97ba82d4:
    if (!bVar36) {
LAB_97ba69a8:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(paVar12,ppTVar25);
    }
LAB_97ba82f0:
    TParseContext__recover(param_1);
switchD_97ba39c8_caseD_2:
    pTVar15 = (unsigned char *)puVar49[2];
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x5f:
    iVar58 = TParseContext__constErrorCheck(param_1,(unsigned char *)puVar49[2]);
LAB_97ba82e8:
    if (iVar58 != 0) goto LAB_97ba82f0;
    goto switchD_97ba39c8_caseD_2;
  case 0x60:
  case 0xb0:
  case 0xb6:
  case 0xba:
  case 0xca:
    goto switchD_97ba39c8_caseD_60;
  case 0x61:
  case 0xb7:
    piVar63 = (int *)puVar49[-9];
    pTVar15 = (unsigned char *)0x0;
    if (piVar63 != (int *)0x0) {
      (**(code **)(*piVar63 + 0x60))(piVar63,1);
      pTVar15 = (unsigned char *)puVar49[-9];
      pTVar50 = local_7f0;
      pTVar2 = local_750;
    }
    break;
  case 0x62:
    piVar63 = *(int **)((int)param_1 + 4);
    uVar16 = (**(code **)(*(int *)puVar49[-7] + 8))();
    iVar58 = *piVar63;
    iVar57 = (piVar63[1] - iVar58 >> 2) + -1;
    goto LAB_97ba8338;
  case 99:
  case 100:
  case 0xa0:
    local_870 = (unsigned char *)puVar49[4];
    break;
  case 0x65:
    local_870 = (unsigned char *)puVar49[-7];
    iVar58 = (**(code **)(*(int *)puVar49[5] + 0x20))();
    if (iVar58 == 0) {
LAB_97ba86ec:
      pTVar10 = (unsigned char *)puVar49[5];
      pTVar15 = local_878;
      pTVar50 = local_7f0;
      pTVar2 = local_750;
      if (pTVar10 == (unsigned char *)0x0) break;
      iVar58 = *(int *)pTVar10;
      goto LAB_97ba86fc;
    }
    uVar59 = puVar49[-7];
    puVar26 = *(uint **)(uVar59 + 0x14);
    if (puVar26 == *(uint **)(uVar59 + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                (uVar59 + 0xc,*(undefined4 *)(uVar59 + 0x14),puVar49 + 4);
    }
    else {
      iVar58 = 0;
      if (puVar26 != (uint *)0x0) {
        uVar52 = puVar49[5];
        *puVar26 = puVar49[4];
        puVar26[1] = uVar52;
        iVar58 = *(int *)(uVar59 + 0x14);
      }
      *(int *)(uVar59 + 0x14) = iVar58 + 8;
    }
    pTVar4 = (unsigned char *)puVar49[5];
    iVar58 = *(int *)(pTVar4 + 0x14);
    if (iVar58 == 0) {
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      psVar11 = (unsigned char *)TPoolAllocator__allocate(pTVar17,8);
      in_cr0 = (psVar11 == (unsigned char *)0x0) << 1;
      psVar22 = (unsigned char *)0x0;
      if (psVar11 != (unsigned char *)0x0) {
        local_2f0[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(psVar11,"",(unsigned char *)local_2f0)
        ;
        psVar22 = psVar11;
      }
      *(unsigned char **)(pTVar4 + 0x14) = psVar22;
      ((int (*)())TType__buildMangledName)(pTVar4,psVar22);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(*(void **)(pTVar4 + 0x14),1,';');
      iVar58 = *(int *)(pTVar4 + 0x14);
    }
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_
              ((unsigned char *)&local_850,(unsigned char *)(uVar59 + 0x44),iVar58);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
              ((unsigned char *)(uVar59 + 0x44),(unsigned char *)&local_850);
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_2e0[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar36 = 0 < iVar58;
    ppTVar25 = local_2e0;
LAB_97ba869c:
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (!bVar36) {
LAB_97ba8824:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(paVar12,ppTVar25);
      pTVar15 = local_878;
      pTVar50 = local_7f0;
      pTVar2 = local_750;
    }
    break;
  case 0x66:
    iVar58 = (**(code **)(*(int *)puVar49[5] + 0x20))();
    if (iVar58 == 0) {
      TParseContext__error
                ((int)param_1,(char *)puVar49[-0xb],
                 "cannot be an argument type except for \'(void)\'","void","",pTVar37,iVar57,param_8
                );
      TParseContext__recover(param_1);
      goto LAB_97ba86ec;
    }
    local_870 = (unsigned char *)puVar49[-0x12];
    uVar59 = puVar49[-0x12];
    puVar26 = *(uint **)(uVar59 + 0x14);
    if (puVar26 == *(uint **)(uVar59 + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                (uVar59 + 0xc,*(undefined4 *)(uVar59 + 0x14),puVar49 + 4);
    }
    else {
      iVar58 = 0;
      if (puVar26 != (uint *)0x0) {
        uVar52 = puVar49[5];
        *puVar26 = puVar49[4];
        puVar26[1] = uVar52;
        iVar58 = *(int *)(uVar59 + 0x14);
      }
      *(int *)(uVar59 + 0x14) = iVar58 + 8;
    }
    pTVar4 = (unsigned char *)puVar49[5];
    iVar58 = *(int *)(pTVar4 + 0x14);
    if (iVar58 == 0) {
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      psVar11 = (unsigned char *)TPoolAllocator__allocate(pTVar17,8);
      in_cr0 = (psVar11 == (unsigned char *)0x0) << 1;
      psVar22 = (unsigned char *)0x0;
      if (psVar11 != (unsigned char *)0x0) {
        local_2d0[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(psVar11,"",(unsigned char *)local_2d0)
        ;
        psVar22 = psVar11;
      }
      *(unsigned char **)(pTVar4 + 0x14) = psVar22;
      ((int (*)())TType__buildMangledName)(pTVar4,psVar22);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(*(void **)(pTVar4 + 0x14),1,';');
      iVar58 = *(int *)(pTVar4 + 0x14);
    }
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_
              ((unsigned char *)&local_850,(unsigned char *)(uVar59 + 0x44),iVar58);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
              ((unsigned char *)(uVar59 + 0x44),(unsigned char *)&local_850);
    pTVar4 = local_84c + -4;
    paVar12 = (unsigned char *)(local_84c + -0xc);
    local_2c0[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (0 < iVar58) break;
    ppTVar25 = local_2c0;
    goto LAB_97ba8824;
  case 0x67:
    if (1 < puVar49[-0x11]) {
      pcVar64 = (char *)getQualifierString(puVar49[-0x11]);
      TParseContext__error
                ((int)param_1,(char *)puVar49[-0xb],"no qualifiers allowed for function return",
                 pcVar64,"",pTVar37,iVar57,param_8);
      TParseContext__recover(param_1);
    }
    iVar58 = TParseContext__structQualifierErrorCheck
                       (param_1,puVar49[-0xb],(unsigned char *)(puVar49 + -0x12));
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    local_820 = (unsigned char *)puVar49[-0x12];
    local_81c = (unsigned char *)puVar49[-0x11];
    local_818 = (unsigned char *)puVar49[-0x10];
    local_814 = (unsigned char *)puVar49[-0xf];
    local_80c = (unsigned char *)puVar49[-0xd];
    local_810 = (unsigned char *)puVar49[-0xe];
    local_5c = (unsigned char *)0xa7b8374c;
    local_808 = (unsigned char *)puVar49[-0xc];
    local_82c = (unsigned char *)(((uint)local_810 & 1) << 9 |
                         ((uint)local_814 & 1) << 10 |
                         ((uint)local_818 & 0xff) << 0xb |
                         ((uint)local_820 & 0x3f) << 0x13 |
                         (int)local_81c << 0x19 | (uint)local_82c & 0x1ff);
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    local_830 = (unsigned char *)0x0;
    local_84c = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_838 = (unsigned char *)0x0;
    local_834 = (unsigned char *)0x0;
    pTVar4 = local_840;
    local_800 = local_820;
    local_7fc = local_81c;
    local_7f8 = local_818;
    local_7f4 = local_814;
    local_7f0 = local_810;
    local_7ec = local_80c;
    local_7e8 = local_808;
    if (local_80c != (unsigned char *)0x0) {
      local_848 = *(unsigned char **)(local_80c + 8);
      local_64 = (unsigned char *)0xa7b8374c;
      local_838 = (unsigned char *)TType__setStructSize((unsigned char *)&local_850,*(unsigned char **)(local_80c + 8));
      iVar58 = (**(code **)(*(int *)local_7ec + 0x18))(local_7ec);
      *(undefined1 *)(*(int *)(iVar58 + 4) + *(int *)(*(int *)(iVar58 + 4) + -0xc)) =
           **(undefined1 **)(local_64 + -0x7cc4);
      pcVar64 = *(char **)(iVar58 + 4);
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      pTVar37 = (unsigned char *)TPoolAllocator__allocate(pTVar17,8);
      in_cr0 = (pTVar37 == (unsigned char *)0x0) << 1;
      pTVar4 = (unsigned char *)0x0;
      if (pTVar37 != (unsigned char *)0x0) {
        local_2b0[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (pTVar37,pcVar64,(unsigned char *)local_2b0);
        pTVar4 = pTVar37;
      }
    }
    local_840 = pTVar4;
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar4 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x54);
    psVar22 = (unsigned char *)puVar49[-10];
    *(undefined **)pTVar4 = PTR_vtable_a7b7c0f4 + 8;
    *(unsigned char **)(pTVar4 + 4) = psVar22;
    local_2a0 = GetGlobalPoolAllocator();
    *(int *)(pTVar4 + 0x18) = 0;
    *(int *)(pTVar4 + 0x10) = 0;
    *(int *)(pTVar4 + 0x14) = 0;
    *(int *)(pTVar4 + 0xc) = local_2a0;
    *(unsigned char **)(pTVar4 + 0x20) = local_84c;
    pTVar37 = local_5c + -0x610c;
    *(unsigned char **)(pTVar4 + 0x24) = local_848;
    *(unsigned char **)(pTVar4 + 0x28) = local_844;
    *(unsigned char **)(pTVar4 + 0x2c) = local_840;
    *(unsigned char **)(pTVar4 + 0x30) = local_83c;
    *(unsigned char **)(pTVar4 + 0x34) = local_838;
    *(unsigned char **)(pTVar4 + 0x1c) = pTVar37;
    *(unsigned char **)(pTVar4 + 0x38) = local_834;
    *(unsigned char **)(pTVar4 + 0x3c) = local_830;
    uVar3 = *(uint *)(pTVar4 + 0x40);
    uVar52 = (uint)local_82c & 0xfe000000;
    *(uint *)(pTVar4 + 0x40) = uVar52 | uVar3 & 0x1ffffff;
    uVar56 = ((uint)local_82c >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar4 + 0x40) = uVar56 | uVar52 | uVar3 & 0x7ffff;
    uVar59 = (uint)local_82c & 0x7f800;
    *(uint *)(pTVar4 + 0x40) = uVar59 | uVar56 | uVar52 | uVar3 & 0x7ff;
    uVar61 = ((uint)local_82c >> 10 & 1) << 10;
    *(uint *)(pTVar4 + 0x40) = uVar61 | uVar59 | uVar56 | uVar52 | uVar3 & 0x3ff;
    *(uint *)(pTVar4 + 0x40) =
         ((uint)local_82c >> 9 & 1) << 9 | uVar61 | uVar59 | uVar56 | uVar52 | uVar3 & 0x1ff;
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(pTVar4 + 0x44,psVar22);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(pTVar4 + 0x44,1,'(');
    *(int *)(pTVar4 + 0x50) = 0;
    *(int *)(pTVar4 + 0x4c) = 0;
    pTVar15 = local_878;
    local_870 = pTVar4;
    local_850 = pTVar37;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x68:
    if (puVar49[-7] == 0) {
      uVar59 = puVar49[1];
      local_64 = (unsigned char *)0xa7b8374c;
      iVar58 = *(int *)(uVar59 + 4);
      *(unsigned char *)(iVar58 + *(int *)(iVar58 + -0xc)) = *DAT_a7b7ba88;
      TParseContext__error
                ((int)param_1,(char *)*puVar49,"illegal use of type \'void\'",*(char **)(uVar59 + 4)
                 ,"",pTVar37,iVar58,uVar59);
      TParseContext__recover(param_1);
    }
    iVar58 = TParseContext__reservedErrorCheck(param_1,*puVar49,(unsigned char *)puVar49[1]);
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    local_840 = (unsigned char *)puVar49[1];
    local_5c = (unsigned char *)0xa7b8374c;
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar4 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    local_830 = (unsigned char *)puVar49[-7];
    local_82c = (unsigned char *)puVar49[-6];
    local_828 = (unsigned char *)puVar49[-5];
    local_824 = (unsigned char *)puVar49[-4];
    local_820 = (unsigned char *)puVar49[-3];
    local_81c = (unsigned char *)puVar49[-2];
    local_818 = (unsigned char *)puVar49[-1];
    *(unsigned char **)pTVar4 = local_5c + -0x610c;
    *(undefined4 *)(pTVar4 + 0x20) = 0;
    *(undefined4 *)(pTVar4 + 4) = 0;
    *(undefined4 *)(pTVar4 + 8) = 0;
    *(undefined4 *)(pTVar4 + 0xc) = 0;
    *(undefined4 *)(pTVar4 + 0x10) = 0;
    *(undefined4 *)(pTVar4 + 0x14) = 0;
    *(undefined4 *)(pTVar4 + 0x18) = 0;
    *(undefined4 *)(pTVar4 + 0x1c) = 0;
    uVar3 = *(uint *)(pTVar4 + 0x24);
    uVar59 = (int)local_82c << 0x19;
    *(uint *)(pTVar4 + 0x24) = uVar59 | uVar3 & 0x1ffffff;
    uVar52 = ((uint)local_830 & 0x3f) << 0x13;
    *(uint *)(pTVar4 + 0x24) = uVar52 | uVar59 | uVar3 & 0x7ffff;
    uVar56 = ((uint)local_828 & 0xff) << 0xb;
    *(uint *)(pTVar4 + 0x24) = uVar56 | uVar52 | uVar59 | uVar3 & 0x7ff;
    uVar61 = ((uint)local_824 & 1) << 10;
    *(uint *)(pTVar4 + 0x24) = uVar61 | uVar56 | uVar52 | uVar59 | uVar3 & 0x3ff;
    *(uint *)(pTVar4 + 0x24) =
         ((uint)local_820 & 1) << 9 | uVar61 | uVar56 | uVar52 | uVar59 | uVar3 & 0x1ff;
    local_810 = local_830;
    local_80c = local_82c;
    local_808 = local_828;
    local_804 = local_824;
    local_800 = local_820;
    local_7fc = local_81c;
    local_7f8 = local_818;
    if (local_81c != (unsigned char *)0x0) {
      local_64 = (unsigned char *)0xa7b8374c;
      *(int *)(pTVar4 + 8) = *(int *)(local_81c + 8);
      uVar16 = TType__setStructSize(pTVar4,*(unsigned char **)(local_81c + 8));
      *(undefined4 *)(pTVar4 + 0x18) = uVar16;
      iVar58 = (**(code **)(*(int *)local_7fc + 0x18))();
      *(undefined1 *)(*(int *)(iVar58 + 4) + *(int *)(*(int *)(iVar58 + 4) + -0xc)) =
           **(undefined1 **)(local_64 + -0x7cc4);
      pcVar64 = *(char **)(iVar58 + 4);
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      pvVar13 = (void *)TPoolAllocator__allocate(pTVar17,8);
      in_cr0 = (pvVar13 == (void *)0x0) << 1;
      pvVar24 = (void *)0x0;
      if (pvVar13 != (void *)0x0) {
        local_290[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (pvVar13,pcVar64,(unsigned char *)local_290);
        pvVar24 = pvVar13;
      }
      *(void **)(pTVar4 + 0x10) = pvVar24;
    }
    local_850 = local_840;
    local_880 = *puVar49;
    pTVar15 = local_878;
    local_870 = local_850;
    local_86c = pTVar4;
    local_84c = pTVar4;
    local_83c = pTVar4;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x69:
    local_5c = (unsigned char *)0xa7b8374c;
    if (puVar49[-0x24] != 0) {
      local_810 = (unsigned char *)puVar49[-0x28];
      local_80c = (unsigned char *)puVar49[-0x27];
      local_808 = (unsigned char *)puVar49[-0x26];
      local_804 = (unsigned char *)puVar49[-0x25];
      local_7fc = (unsigned char *)puVar49[-0x23];
      local_800 = (unsigned char *)puVar49[-0x24];
      local_7f8 = (unsigned char *)puVar49[-0x22];
      uVar16 = 0xa7b8374c;
      local_81c = (unsigned char *)(((uint)local_800 & 1) << 9 |
                           ((uint)local_804 & 1) << 10 |
                           ((uint)local_808 & 0xff) << 0xb |
                           ((uint)local_810 & 0x3f) << 0x13 |
                           (int)local_80c << 0x19 | (uint)local_81c & 0x1ff);
      local_840 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      local_820 = (unsigned char *)0x0;
      local_83c = (unsigned char *)0x0;
      local_838 = (unsigned char *)0x0;
      local_834 = (unsigned char *)0x0;
      local_830 = (unsigned char *)0x0;
      local_82c = (unsigned char *)0x0;
      local_828 = (unsigned char *)0x0;
      local_824 = (unsigned char *)0x0;
      local_64 = (unsigned char *)0xa7b8374c;
      pTVar4 = local_830;
      local_7f0 = local_810;
      local_7ec = local_80c;
      local_7e8 = local_808;
      local_7e4 = local_804;
      local_7e0 = local_800;
      local_7dc = local_7fc;
      local_7d8 = local_7f8;
      if (local_7fc != (unsigned char *)0x0) {
        local_838 = *(unsigned char **)(local_7fc + 8);
        local_828 = (unsigned char *)TType__setStructSize((unsigned char *)&local_840,*(unsigned char **)(local_7fc + 8));
        iVar58 = (**(code **)(*(int *)local_7dc + 0x18))(local_7dc);
        *(undefined1 *)(*(int *)(iVar58 + 4) + *(int *)(*(int *)(iVar58 + 4) + -0xc)) =
             **(undefined1 **)(local_64 + -0x7cc4);
        pcVar64 = *(char **)(iVar58 + 4);
        pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
        pTVar37 = (unsigned char *)TPoolAllocator__allocate(pTVar17,8);
        in_cr0 = (pTVar37 == (unsigned char *)0x0) << 1;
        pTVar4 = (unsigned char *)0x0;
        if (pTVar37 != (unsigned char *)0x0) {
          local_280[0] = GetGlobalPoolAllocator();
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                    (pTVar37,pcVar64,(unsigned char *)local_280);
          pTVar4 = pTVar37;
        }
      }
      local_830 = pTVar4;
      TType__getCompleteString(&local_850,(unsigned char *)&local_840);
      local_84c[*(int *)(local_84c + -0xc)] = **(unsigned char **)(local_64 + -0x7cc4);
      TParseContext__error
                ((int)param_1,(char *)puVar49[-0x16],"cannot declare arrays of this type",
                 (char *)local_84c,"",local_64,local_84c,uVar16);
      pTVar4 = local_84c + -4;
      local_270[0] = local_850;
      do {
        iVar58 = *(int *)pTVar4;
        if (in_RESERVE != '\0') {
          iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
          *(int *)pTVar4 = iVar57;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar58 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(local_84c + -0xc),local_270);
      }
      local_840 = local_5c + -0x610c;
      TParseContext__recover(param_1);
    }
    iVar58 = TParseContext__reservedErrorCheck(param_1,puVar49[-0x21],(unsigned char *)puVar49[-0x20]);
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    puVar49[-0x24] = 1;
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar4 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    local_850 = (unsigned char *)puVar49[-0x28];
    local_84c = (unsigned char *)puVar49[-0x27];
    local_848 = (unsigned char *)puVar49[-0x26];
    local_844 = (unsigned char *)puVar49[-0x25];
    local_840 = (unsigned char *)puVar49[-0x24];
    local_83c = (unsigned char *)puVar49[-0x23];
    local_838 = (unsigned char *)puVar49[-0x22];
    *(unsigned char **)pTVar4 = local_5c + -0x610c;
    *(undefined4 *)(pTVar4 + 0x20) = 0;
    *(undefined4 *)(pTVar4 + 4) = 0;
    *(undefined4 *)(pTVar4 + 8) = 0;
    *(undefined4 *)(pTVar4 + 0xc) = 0;
    *(undefined4 *)(pTVar4 + 0x10) = 0;
    *(undefined4 *)(pTVar4 + 0x14) = 0;
    *(undefined4 *)(pTVar4 + 0x18) = 0;
    *(undefined4 *)(pTVar4 + 0x1c) = 0;
    uVar3 = *(uint *)(pTVar4 + 0x24);
    uVar59 = (int)local_84c << 0x19;
    *(uint *)(pTVar4 + 0x24) = uVar59 | uVar3 & 0x1ffffff;
    uVar52 = ((uint)local_850 & 0x3f) << 0x13;
    *(uint *)(pTVar4 + 0x24) = uVar52 | uVar59 | uVar3 & 0x7ffff;
    uVar56 = ((uint)local_848 & 0xff) << 0xb;
    *(uint *)(pTVar4 + 0x24) = uVar56 | uVar52 | uVar59 | uVar3 & 0x7ff;
    uVar61 = ((uint)local_844 & 1) << 10;
    *(uint *)(pTVar4 + 0x24) = uVar61 | uVar56 | uVar52 | uVar59 | uVar3 & 0x3ff;
    *(uint *)(pTVar4 + 0x24) =
         ((uint)local_840 & 1) << 9 | uVar61 | uVar56 | uVar52 | uVar59 | uVar3 & 0x1ff;
    local_830 = local_850;
    local_82c = local_84c;
    local_828 = local_848;
    local_824 = local_844;
    local_820 = local_840;
    local_81c = local_83c;
    local_818 = local_838;
    if (local_83c != (unsigned char *)0x0) {
      local_64 = (unsigned char *)0xa7b8374c;
      *(int *)(pTVar4 + 8) = *(int *)(local_83c + 8);
      uVar16 = TType__setStructSize(pTVar4,*(unsigned char **)(local_83c + 8));
      *(undefined4 *)(pTVar4 + 0x18) = uVar16;
      iVar58 = (**(code **)(*(int *)local_81c + 0x18))();
      *(undefined1 *)(*(int *)(iVar58 + 4) + *(int *)(*(int *)(iVar58 + 4) + -0xc)) =
           **(undefined1 **)(local_64 + -0x7cc4);
      pcVar64 = *(char **)(iVar58 + 4);
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      pvVar13 = (void *)TPoolAllocator__allocate(pTVar17,8);
      in_cr0 = (pvVar13 == (void *)0x0) << 1;
      pvVar24 = (void *)0x0;
      if (pvVar13 != (void *)0x0) {
        local_260[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (pvVar13,pcVar64,(unsigned char *)local_260);
        pvVar24 = pvVar13;
      }
      *(void **)(pTVar4 + 0x10) = pvVar24;
    }
    iVar58 = (**(code **)(*(int *)puVar49[-9] + 0x18))();
    if (iVar58 != 0) {
      iVar58 = (**(code **)(*(int *)puVar49[-9] + 0x18))();
      uVar16 = **(undefined4 **)(iVar58 + 0x30);
      *(uint *)(pTVar4 + 0x24) = *(uint *)(pTVar4 + 0x24) | 0x200;
      *(undefined4 *)(pTVar4 + 4) = uVar16;
    }
    local_840 = (unsigned char *)puVar49[-0x20];
    local_880 = puVar49[-0x21];
    pTVar15 = local_878;
    local_870 = local_840;
    local_86c = pTVar4;
    local_850 = local_840;
    local_84c = pTVar4;
    local_83c = pTVar4;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x6a:
  case 0x6c:
    _memcpy(&local_880,puVar49,0x2c);
    uVar59 = *puVar49;
    uVar52 = puVar49[-0x11];
    uVar56 = puVar49[-7];
    goto LAB_97ba9130;
  case 0x6b:
  case 0x6d:
    _memcpy(&local_880,puVar49,0x2c);
    iVar58 = TParseContext__parameterSamplerErrorCheck(param_1,*puVar49,puVar49[-7],puVar49[5]);
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    uVar59 = *puVar49;
    uVar56 = puVar49[-7];
    uVar52 = 0;
LAB_97ba9130:
    iVar58 = TParseContext__paramErrorCheck(param_1,uVar59,uVar52,uVar56,local_86c);
LAB_97bab180:
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (iVar58 == 0) break;
LAB_97bab5f4:
    TParseContext__recover(param_1);
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
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
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar4 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    local_830 = (unsigned char *)puVar49[4];
    local_82c = (unsigned char *)puVar49[5];
    local_828 = (unsigned char *)puVar49[6];
    local_824 = (unsigned char *)puVar49[7];
    local_5c = (unsigned char *)0xa7b8374c;
    local_820 = (unsigned char *)puVar49[8];
    local_81c = (unsigned char *)puVar49[9];
    local_818 = (unsigned char *)puVar49[10];
    *(undefined ***)pTVar4 = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined4 *)(pTVar4 + 0x20) = 0;
    *(undefined4 *)(pTVar4 + 4) = 0;
    *(undefined4 *)(pTVar4 + 8) = 0;
    *(undefined4 *)(pTVar4 + 0xc) = 0;
    *(undefined4 *)(pTVar4 + 0x10) = 0;
    *(undefined4 *)(pTVar4 + 0x14) = 0;
    *(undefined4 *)(pTVar4 + 0x18) = 0;
    *(undefined4 *)(pTVar4 + 0x1c) = 0;
    uVar3 = *(uint *)(pTVar4 + 0x24);
    uVar59 = (int)local_82c << 0x19;
    *(uint *)(pTVar4 + 0x24) = uVar59 | uVar3 & 0x1ffffff;
    uVar52 = ((uint)local_830 & 0x3f) << 0x13;
    *(uint *)(pTVar4 + 0x24) = uVar52 | uVar59 | uVar3 & 0x7ffff;
    uVar56 = ((uint)local_828 & 0xff) << 0xb;
    *(uint *)(pTVar4 + 0x24) = uVar56 | uVar52 | uVar59 | uVar3 & 0x7ff;
    uVar61 = ((uint)local_824 & 1) << 10;
    *(uint *)(pTVar4 + 0x24) = uVar61 | uVar56 | uVar52 | uVar59 | uVar3 & 0x3ff;
    *(uint *)(pTVar4 + 0x24) =
         ((uint)local_820 & 1) << 9 | uVar61 | uVar56 | uVar52 | uVar59 | uVar3 & 0x1ff;
    local_810 = local_830;
    local_80c = local_82c;
    local_808 = local_828;
    local_804 = local_824;
    local_800 = local_820;
    local_7fc = local_81c;
    local_7f8 = local_818;
    if (local_81c != (unsigned char *)0x0) {
      local_64 = (unsigned char *)0xa7b8374c;
      *(int *)(pTVar4 + 8) = *(int *)(local_81c + 8);
      uVar16 = TType__setStructSize(pTVar4,*(unsigned char **)(local_81c + 8));
      *(undefined4 *)(pTVar4 + 0x18) = uVar16;
      iVar58 = (**(code **)(*(int *)local_7fc + 0x18))();
      *(undefined1 *)(*(int *)(iVar58 + 4) + *(int *)(*(int *)(iVar58 + 4) + -0xc)) =
           **(undefined1 **)(local_64 + -0x7cc4);
      pcVar64 = *(char **)(iVar58 + 4);
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      pvVar13 = (void *)TPoolAllocator__allocate(pTVar17,8);
      in_cr0 = (pvVar13 == (void *)0x0) << 1;
      pvVar24 = (void *)0x0;
      if (pvVar13 != (void *)0x0) {
        local_250[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (pvVar13,pcVar64,(unsigned char *)local_250);
        pvVar24 = pvVar13;
      }
      *(void **)(pTVar4 + 0x10) = pvVar24;
    }
    local_870 = local_840;
    local_850 = local_840;
    pTVar15 = local_878;
    local_86c = pTVar4;
    local_84c = pTVar4;
    local_83c = pTVar4;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x73:
    local_5c = (unsigned char *)0xa7b8374c;
    if (puVar49[-0x19] != 0) {
      local_810 = (unsigned char *)puVar49[-0x1d];
      local_80c = (unsigned char *)puVar49[-0x1c];
      local_808 = (unsigned char *)puVar49[-0x1b];
      local_804 = (unsigned char *)puVar49[-0x1a];
      local_7fc = (unsigned char *)puVar49[-0x18];
      local_800 = (unsigned char *)puVar49[-0x19];
      local_7f8 = (unsigned char *)puVar49[-0x17];
      uVar16 = 0xa7b8374c;
      local_81c = (unsigned char *)(((uint)local_800 & 1) << 9 |
                           ((uint)local_804 & 1) << 10 |
                           ((uint)local_808 & 0xff) << 0xb |
                           ((uint)local_810 & 0x3f) << 0x13 |
                           (int)local_80c << 0x19 | (uint)local_81c & 0x1ff);
      local_840 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      local_820 = (unsigned char *)0x0;
      local_83c = (unsigned char *)0x0;
      local_838 = (unsigned char *)0x0;
      local_834 = (unsigned char *)0x0;
      local_830 = (unsigned char *)0x0;
      local_82c = (unsigned char *)0x0;
      local_828 = (unsigned char *)0x0;
      local_824 = (unsigned char *)0x0;
      local_64 = (unsigned char *)0xa7b8374c;
      pTVar4 = local_830;
      local_7f0 = local_810;
      local_7ec = local_80c;
      local_7e8 = local_808;
      local_7e4 = local_804;
      local_7e0 = local_800;
      local_7dc = local_7fc;
      local_7d8 = local_7f8;
      if (local_7fc != (unsigned char *)0x0) {
        local_838 = *(unsigned char **)(local_7fc + 8);
        local_828 = (unsigned char *)TType__setStructSize((unsigned char *)&local_840,*(unsigned char **)(local_7fc + 8));
        iVar58 = (**(code **)(*(int *)local_7dc + 0x18))(local_7dc);
        *(undefined1 *)(*(int *)(iVar58 + 4) + *(int *)(*(int *)(iVar58 + 4) + -0xc)) =
             **(undefined1 **)(local_64 + -0x7cc4);
        pcVar64 = *(char **)(iVar58 + 4);
        pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
        pTVar37 = (unsigned char *)TPoolAllocator__allocate(pTVar17,8);
        in_cr0 = (pTVar37 == (unsigned char *)0x0) << 1;
        pTVar4 = (unsigned char *)0x0;
        if (pTVar37 != (unsigned char *)0x0) {
          local_240[0] = GetGlobalPoolAllocator();
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                    (pTVar37,pcVar64,(unsigned char *)local_240);
          pTVar4 = pTVar37;
        }
      }
      local_830 = pTVar4;
      TType__getCompleteString(&local_850,(unsigned char *)&local_840);
      local_84c[*(int *)(local_84c + -0xc)] = **(unsigned char **)(local_64 + -0x7cc4);
      TParseContext__error
                ((int)param_1,(char *)puVar49[-0x16],"cannot declare arrays of this type",
                 (char *)local_84c,"",local_64,local_84c,uVar16);
      pTVar4 = local_84c + -4;
      local_230[0] = local_850;
      do {
        iVar58 = *(int *)pTVar4;
        if (in_RESERVE != '\0') {
          iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
          *(int *)pTVar4 = iVar57;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if (iVar58 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(local_84c + -0xc),local_230);
      }
      local_840 = local_5c + -0x610c;
      TParseContext__recover(param_1);
    }
    puVar49[-0x19] = 1;
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar4 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    local_850 = (unsigned char *)puVar49[-0x1d];
    local_84c = (unsigned char *)puVar49[-0x1c];
    local_848 = (unsigned char *)puVar49[-0x1b];
    local_844 = (unsigned char *)puVar49[-0x1a];
    local_840 = (unsigned char *)puVar49[-0x19];
    local_83c = (unsigned char *)puVar49[-0x18];
    local_838 = (unsigned char *)puVar49[-0x17];
    *(unsigned char **)pTVar4 = local_5c + -0x610c;
    *(undefined4 *)(pTVar4 + 0x20) = 0;
    *(undefined4 *)(pTVar4 + 4) = 0;
    *(undefined4 *)(pTVar4 + 8) = 0;
    *(undefined4 *)(pTVar4 + 0xc) = 0;
    *(undefined4 *)(pTVar4 + 0x10) = 0;
    *(undefined4 *)(pTVar4 + 0x14) = 0;
    *(undefined4 *)(pTVar4 + 0x18) = 0;
    *(undefined4 *)(pTVar4 + 0x1c) = 0;
    uVar3 = *(uint *)(pTVar4 + 0x24);
    uVar59 = (int)local_84c << 0x19;
    *(uint *)(pTVar4 + 0x24) = uVar59 | uVar3 & 0x1ffffff;
    uVar52 = ((uint)local_850 & 0x3f) << 0x13;
    *(uint *)(pTVar4 + 0x24) = uVar52 | uVar59 | uVar3 & 0x7ffff;
    uVar56 = ((uint)local_848 & 0xff) << 0xb;
    *(uint *)(pTVar4 + 0x24) = uVar56 | uVar52 | uVar59 | uVar3 & 0x7ff;
    uVar61 = ((uint)local_844 & 1) << 10;
    *(uint *)(pTVar4 + 0x24) = uVar61 | uVar56 | uVar52 | uVar59 | uVar3 & 0x3ff;
    *(uint *)(pTVar4 + 0x24) =
         ((uint)local_840 & 1) << 9 | uVar61 | uVar56 | uVar52 | uVar59 | uVar3 & 0x1ff;
    local_830 = local_850;
    local_82c = local_84c;
    local_828 = local_848;
    local_824 = local_844;
    local_820 = local_840;
    local_81c = local_83c;
    local_818 = local_838;
    if (local_83c != (unsigned char *)0x0) {
      local_64 = (unsigned char *)0xa7b8374c;
      *(int *)(pTVar4 + 8) = *(int *)(local_83c + 8);
      uVar16 = TType__setStructSize(pTVar4,*(unsigned char **)(local_83c + 8));
      *(undefined4 *)(pTVar4 + 0x18) = uVar16;
      iVar58 = (**(code **)(*(int *)local_81c + 0x18))();
      *(undefined1 *)(*(int *)(iVar58 + 4) + *(int *)(*(int *)(iVar58 + 4) + -0xc)) =
           **(undefined1 **)(local_64 + -0x7cc4);
      pcVar64 = *(char **)(iVar58 + 4);
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      pvVar13 = (void *)TPoolAllocator__allocate(pTVar17,8);
      in_cr0 = (pvVar13 == (void *)0x0) << 1;
      pvVar24 = (void *)0x0;
      if (pvVar13 != (void *)0x0) {
        local_220[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (pvVar13,pcVar64,(unsigned char *)local_220);
        pvVar24 = pvVar13;
      }
      *(void **)(pTVar4 + 0x10) = pvVar24;
    }
    iVar58 = (**(code **)(*(int *)puVar49[-9] + 0x18))();
    if (iVar58 != 0) {
      iVar58 = (**(code **)(*(int *)puVar49[-9] + 0x18))();
      uVar16 = **(undefined4 **)(iVar58 + 0x30);
      *(uint *)(pTVar4 + 0x24) = *(uint *)(pTVar4 + 0x24) | 0x200;
      *(undefined4 *)(pTVar4 + 4) = uVar16;
    }
    local_850 = (unsigned char *)0x0;
    local_880 = puVar49[-0x16];
    pTVar15 = local_878;
    local_870 = local_850;
    local_86c = pTVar4;
    local_84c = pTVar4;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x74:
    _memcpy(&local_880,puVar49,0x2c);
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x75:
    _memcpy(&local_880,puVar49 + -0x16,0x2c);
    uVar59 = *puVar49;
    pTVar29 = (unsigned char *)(puVar49 + -0x12);
    goto LAB_97ba9874;
  case 0x76:
    _memcpy(&local_880,puVar49 + -0x2c,0x2c);
    iVar58 = TParseContext__structQualifierErrorCheck
                       (param_1,puVar49[-0x16],(unsigned char *)(puVar49 + -0x28));
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    uVar59 = puVar49[-0xb];
    uVar52 = puVar49[-0x15];
    uVar56 = 0;
    goto LAB_97ba99f8;
  case 0x77:
    _memcpy(&local_880,puVar49 + -0x37,0x2c);
    uVar59 = puVar49[-0x21];
    pTVar29 = (unsigned char *)(puVar49 + -0x33);
    goto LAB_97ba99a0;
  case 0x78:
    _memcpy(&local_880,puVar49 + -0x2c,0x2c);
    iVar58 = TParseContext__structQualifierErrorCheck
                       (param_1,puVar49[-0x16],(unsigned char *)(puVar49 + -0x28));
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    iVar58 = TParseContext__executeInitializer
                       (param_1,puVar49[-0x16],(unsigned char *)puVar49[-0x15],
                        (unsigned char *)(puVar49 + -0x28),(unsigned char *)puVar49[2],&local_80);
    if (iVar58 == 0) {
      if (local_80 != (unsigned char *)0x0) {
        pTVar14 = *(unsigned char **)param_1;
        pTVar23 = (unsigned char *)puVar49[-0x2a];
        pTVar20 = local_80;
        goto LAB_97ba97d4;
      }
      pTVar15 = (unsigned char *)puVar49[-0x2a];
      pTVar50 = local_7f0;
      pTVar2 = local_750;
      break;
    }
    goto LAB_97bab1f4;
  case 0x79:
    local_870 = (unsigned char *)puVar49[4];
    local_86c = (unsigned char *)puVar49[5];
    local_868 = (unsigned char *)puVar49[6];
    local_864 = (unsigned char *)puVar49[7];
    local_860 = (unsigned char *)puVar49[8];
    local_85c = (unsigned char *)puVar49[9];
    local_858 = (unsigned char *)puVar49[10];
    pTVar15 = (unsigned char *)0x0;
    break;
  case 0x7a:
    local_878 = (unsigned char *)0x0;
    pTVar29 = (unsigned char *)(puVar49 + -7);
    local_870 = (unsigned char *)puVar49[-7];
    local_86c = (unsigned char *)puVar49[-6];
    local_868 = (unsigned char *)puVar49[-5];
    local_864 = (unsigned char *)puVar49[-4];
    local_860 = (unsigned char *)puVar49[-3];
    local_85c = (unsigned char *)puVar49[-2];
    local_858 = (unsigned char *)puVar49[-1];
    uVar59 = *puVar49;
LAB_97ba9874:
    iVar58 = TParseContext__structQualifierErrorCheck(param_1,uVar59,pTVar29);
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    iVar58 = TParseContext__nonInitErrorCheck
                       (param_1,*puVar49,(unsigned char *)puVar49[1],(unsigned char *)&local_870);
    goto LAB_97bab180;
  case 0x7b:
    local_878 = (unsigned char *)0x0;
    local_870 = (unsigned char *)puVar49[-0x1d];
    local_86c = (unsigned char *)puVar49[-0x1c];
    local_868 = (unsigned char *)puVar49[-0x1b];
    local_864 = (unsigned char *)puVar49[-0x1a];
    local_860 = (unsigned char *)puVar49[-0x19];
    local_85c = (unsigned char *)puVar49[-0x18];
    local_858 = (unsigned char *)puVar49[-0x17];
    iVar58 = TParseContext__structQualifierErrorCheck
                       (param_1,puVar49[-0x16],(unsigned char *)(puVar49 + -0x1d));
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    uVar59 = puVar49[-0xb];
    uVar52 = puVar49[-0x15];
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
    pTVar29 = (unsigned char *)(puVar49 + -0x28);
    local_870 = (unsigned char *)puVar49[-0x28];
    local_86c = (unsigned char *)puVar49[-0x27];
    local_868 = (unsigned char *)puVar49[-0x26];
    local_864 = (unsigned char *)puVar49[-0x25];
    local_860 = (unsigned char *)puVar49[-0x24];
    local_85c = (unsigned char *)puVar49[-0x23];
    local_858 = (unsigned char *)puVar49[-0x22];
    uVar59 = puVar49[-0x21];
LAB_97ba99a0:
    iVar58 = TParseContext__structQualifierErrorCheck(param_1,uVar59,pTVar29);
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    uVar59 = puVar49[-0x16];
    uVar52 = puVar49[-0x20];
    uVar56 = puVar49[-9];
LAB_97ba99f8:
    puVar5[0x10] = uVar56;
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
    iVar58 = TParseContext__arrayErrorCheck
                       (param_1,uVar59,uVar52,local_850,local_84c,local_848,local_844,local_840);
    goto LAB_97bab180;
  case 0x7d:
    local_870 = (unsigned char *)puVar49[-0x1d];
    local_86c = (unsigned char *)puVar49[-0x1c];
    local_868 = (unsigned char *)puVar49[-0x1b];
    local_864 = (unsigned char *)puVar49[-0x1a];
    local_860 = (unsigned char *)puVar49[-0x19];
    local_85c = (unsigned char *)puVar49[-0x18];
    local_858 = (unsigned char *)puVar49[-0x17];
    iVar58 = TParseContext__structQualifierErrorCheck
                       (param_1,puVar49[-0x16],(unsigned char *)(puVar49 + -0x1d));
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    iVar58 = TParseContext__executeInitializer
                       (param_1,puVar49[-0x16],(unsigned char *)puVar49[-0x15],
                        (unsigned char *)(puVar49 + -0x1d),(unsigned char *)puVar49[2],&local_7c);
    if (iVar58 != 0) goto LAB_97bab1f4;
    if (local_7c != (unsigned char *)0x0) {
      pTVar14 = *(unsigned char **)param_1;
      uVar59 = puVar49[-0xb];
      pTVar20 = local_7c;
      goto LAB_97bab0ec;
    }
    goto switchD_97ba39c8_caseD_60;
  case 0x7e:
    local_868 = (unsigned char *)puVar49[6];
    local_864 = (unsigned char *)puVar49[7];
    local_860 = (unsigned char *)puVar49[8];
    local_85c = (unsigned char *)puVar49[9];
    local_858 = (unsigned char *)puVar49[10];
    local_870 = (unsigned char *)puVar49[4];
    local_86c = (unsigned char *)puVar49[5];
    break;
  case 0x7f:
    pTVar4 = (unsigned char *)puVar49[4];
    local_84c = (unsigned char *)puVar49[-6];
    pTVar15 = (unsigned char *)puVar49[6];
    local_844 = (unsigned char *)puVar49[7];
    local_820 = (unsigned char *)0x0;
    pTVar37 = (unsigned char *)puVar49[9];
    local_838 = (unsigned char *)0x0;
    local_818 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    uVar59 = puVar49[-6];
    local_850 = pTVar4;
    local_848 = pTVar15;
    local_83c = pTVar37;
    local_830 = pTVar4;
    local_82c = local_84c;
    local_828 = pTVar15;
    local_824 = local_844;
    local_81c = pTVar37;
    if ((uVar59 == 3) && (puVar49[4] - 2 < 2)) {
      pcVar64 = (char *)getQualifierString(3);
      TParseContext__error
                ((int)param_1,(char *)puVar49[10],"cannot be bool or int",pcVar64,"",pTVar4,pTVar37,
                 pTVar15);
      TParseContext__recover(param_1);
      uVar59 = puVar49[-6];
    }
    if ((uVar59 - 4 < 2) && (puVar49[4] - 2 < 2)) {
      pcVar64 = (char *)getQualifierString(uVar59);
      TParseContext__error
                ((int)param_1,(char *)puVar49[10],"cannot be bool or int",pcVar64,"",pTVar4,pTVar37,
                 pTVar15);
      TParseContext__recover(param_1);
    }
    goto LAB_97ba9d1c;
  case 0x80:
    puVar26 = &DAT_97c356fc;
    goto LAB_97ba9da4;
  case 0x81:
    if (*(int *)((int)param_1 + 0xc) != 0) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex shaders only ","attribute","",
                 "",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    iVar58 = TParseContext__globalErrorCheck
                       (param_1,*puVar49,
                        (uint)((*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4) >> 2)
                        < 4,"attribute");
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    puVar26 = &DAT_97c35718;
    goto LAB_97ba9da4;
  case 0x82:
    iVar58 = TParseContext__globalErrorCheck
                       (param_1,*puVar49,
                        (uint)((*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4) >> 2)
                        < 4,"varying");
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
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
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x83:
    iVar58 = TParseContext__globalErrorCheck
                       (param_1,*puVar49,
                        (uint)((*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4) >> 2)
                        < 4,"uniform");
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    puVar26 = &DAT_97c35750;
LAB_97ba9da4:
    local_858 = (unsigned char *)puVar26[6];
    local_868 = (unsigned char *)puVar26[2];
    local_864 = (unsigned char *)puVar26[3];
    local_860 = (unsigned char *)puVar26[4];
    local_85c = (unsigned char *)puVar26[5];
    pTVar15 = local_878;
    local_870 = (unsigned char *)*puVar26;
    local_86c = (unsigned char *)puVar26[1];
    local_850 = (unsigned char *)*puVar26;
    local_84c = (unsigned char *)puVar26[1];
    local_848 = local_868;
    local_844 = local_864;
    local_840 = local_860;
    local_83c = local_85c;
    local_838 = local_858;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x84:
    local_830 = (unsigned char *)0x0;
    local_828 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x0;
    local_82c = (unsigned char *)(uint)((uint)((*(int **)((int)param_1 + 4))[1] -
                                       **(int **)((int)param_1 + 4) >> 2) < 4);
    local_820 = (unsigned char *)0x0;
    local_81c = (unsigned char *)0x0;
    local_858 = (unsigned char *)*puVar49;
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
    iVar58 = piVar63[1] - *piVar63;
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
    iVar58 = piVar63[1] - *piVar63;
    local_818 = (unsigned char *)*puVar49;
    local_828 = local_830;
    goto LAB_97baa46c;
  case 0x8f:
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x2;
LAB_97ba9fa8:
    iVar58 = piVar63[1] - *piVar63;
    local_828 = (unsigned char *)0x3;
    goto LAB_97baa40c;
  case 0x90:
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x2;
LAB_97ba9fc8:
    iVar58 = piVar63[1] - *piVar63;
    local_828 = (unsigned char *)0x4;
    goto LAB_97baa40c;
  case 0x91:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ","mat2",
                 "","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    iVar58 = (*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4);
    local_868 = (unsigned char *)0x2;
    goto LAB_97baa0ec;
  case 0x92:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ","mat3",
                 "","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    iVar58 = (*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4);
    local_868 = (unsigned char *)0x3;
    goto LAB_97baa0ec;
  case 0x93:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ","mat4",
                 "","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    iVar58 = (*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4);
    local_868 = (unsigned char *)0x4;
LAB_97baa0ec:
    local_82c = (unsigned char *)(uint)((uint)(iVar58 >> 2) < 4);
    local_830 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x1;
    local_820 = (unsigned char *)0x0;
    local_81c = (unsigned char *)0x0;
    local_858 = (unsigned char *)*puVar49;
    local_864 = (unsigned char *)0x1;
    local_85c = (unsigned char *)0x0;
    local_850 = (unsigned char *)0x1;
    local_844 = (unsigned char *)0x1;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_870 = (unsigned char *)0x1;
    local_860 = (unsigned char *)0x0;
    pTVar15 = local_878;
    local_86c = local_82c;
    local_84c = local_82c;
    local_848 = local_868;
    local_838 = local_858;
    local_828 = local_868;
    local_818 = local_858;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x94:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ",
                 "sampler1D","","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x5;
    goto LAB_97baa3fc;
  case 0x95:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ",
                 "sampler2D","","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x6;
    goto LAB_97baa3fc;
  case 0x96:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ",
                 "sampler3D","","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x7;
    goto LAB_97baa3fc;
  case 0x97:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ",
                 "samplerCube","","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x8;
    goto LAB_97baa3fc;
  case 0x98:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ",
                 "sampler1DShadow","","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x9;
    goto LAB_97baa3fc;
  case 0x99:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ",
                 "sampler2DShadow","","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0xa;
    goto LAB_97baa3fc;
  case 0x9a:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ",
                 "sampler2DRect","","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    iVar58 = TParseContext__extensionErrorCheck(param_1,*puVar49,"GL_ARB_texture_rectangle");
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0xb;
    goto LAB_97baa3fc;
  case 0x9b:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)*puVar49," supported in vertex/fragment shaders only ",
                 "sampler2DRectShadow","","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    iVar58 = TParseContext__extensionErrorCheck(param_1,*puVar49,"GL_ARB_texture_rectangle");
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    piVar63 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0xc;
LAB_97baa3fc:
    iVar58 = piVar63[1] - *piVar63;
    local_828 = (unsigned char *)0x1;
LAB_97baa40c:
    local_818 = (unsigned char *)*puVar49;
LAB_97baa46c:
    local_82c = (unsigned char *)(uint)((uint)(iVar58 >> 2) < 4);
    local_81c = (unsigned char *)0x0;
    local_820 = (unsigned char *)0x0;
    local_824 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_85c = (unsigned char *)0x0;
    local_864 = (unsigned char *)0x0;
    local_860 = (unsigned char *)0x0;
    pTVar15 = local_878;
    local_870 = local_830;
    local_86c = local_82c;
    local_868 = local_828;
    local_858 = local_818;
    local_850 = local_830;
    local_84c = local_82c;
    local_848 = local_828;
    local_838 = local_818;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x9c:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,(char *)puVar49[10]," supported in vertex/fragment shaders only ",
                 "struct","","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    local_868 = (unsigned char *)puVar49[6];
    local_864 = (unsigned char *)puVar49[7];
    local_860 = (unsigned char *)puVar49[8];
    local_85c = (unsigned char *)puVar49[9];
    local_858 = (unsigned char *)puVar49[10];
    pTVar15 = local_878;
    local_870 = (unsigned char *)puVar49[4];
    local_86c = (unsigned char *)(uint)((uint)((*(int **)((int)param_1 + 4))[1] -
                                       **(int **)((int)param_1 + 4) >> 2) < 4);
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x9d:
    local_85c = (unsigned char *)(puVar49[2] + 0xc);
    local_830 = (unsigned char *)0xe;
    local_828 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x0;
    local_82c = (unsigned char *)(uint)((uint)((*(int **)((int)param_1 + 4))[1] -
                                       **(int **)((int)param_1 + 4) >> 2) < 4);
    local_820 = (unsigned char *)0x0;
    local_858 = (unsigned char *)*puVar49;
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
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar37 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    pTVar55 = (unsigned char *)puVar49[-7];
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_
              ((unsigned char *)&local_850,(unsigned char *)puVar49[-0x20]);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_((unsigned char *)&local_840,(unsigned char *)&local_850);
    local_5c = (unsigned char *)0xa7b8374c;
    *(undefined ***)pTVar37 = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined4 *)(pTVar37 + 0x20) = 0;
    *(uint *)(pTVar37 + 0x24) = *(uint *)(pTVar37 + 0x24) & 0x9ff | 0x700800;
    *(undefined4 *)(pTVar37 + 4) = 0;
    *(unsigned char **)(pTVar37 + 8) = pTVar55;
    *(undefined4 *)(pTVar37 + 0xc) = 0;
    *(undefined4 *)(pTVar37 + 0x14) = 0;
    *(undefined4 *)(pTVar37 + 0x1c) = 0;
    uVar16 = TType__setStructSize(pTVar37,pTVar55);
    pTVar4 = local_83c;
    local_64 = (unsigned char *)0xa7b8374c;
    *(undefined4 *)(pTVar37 + 0x18) = uVar16;
    local_83c[*(int *)(local_83c + -0xc)] = *DAT_a7b7ba88;
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pvVar13 = (void *)TPoolAllocator__allocate(pTVar17,8);
    in_cr0 = (pvVar13 == (void *)0x0) << 1;
    pvVar24 = (void *)0x0;
    if (pvVar13 != (void *)0x0) {
      local_210[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (pvVar13,(char *)pTVar4,(unsigned char *)local_210);
      pvVar24 = pvVar13;
    }
    *(void **)(pTVar37 + 0x10) = pvVar24;
    pTVar4 = local_83c + -4;
    local_200[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_200);
    }
    pTVar4 = local_84c + -4;
    local_1f0[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_84c + -0xc),local_1f0);
    }
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    piVar63 = (int *)TPoolAllocator__allocate(pTVar17,0x40);
    puVar6 = PTR_vtable_a7b7c0b4 + 8;
    piVar63[1] = puVar49[-0x20];
    *piVar63 = (int)puVar6;
    iVar35 = *(int *)(pTVar37 + 0xc);
    iVar34 = *(int *)(pTVar37 + 0x10);
    iVar32 = *(int *)(pTVar37 + 0x14);
    iVar28 = *(int *)(pTVar37 + 0x18);
    iVar7 = *(int *)(pTVar37 + 0x1c);
    iVar62 = *(int *)(pTVar37 + 0x20);
    iVar58 = *(int *)(pTVar37 + 4);
    iVar57 = *(int *)(pTVar37 + 8);
    piVar63[3] = (int)(local_5c + -0x610c);
    piVar63[6] = iVar35;
    piVar63[7] = iVar34;
    piVar63[8] = iVar32;
    piVar63[9] = iVar28;
    piVar63[10] = iVar7;
    piVar63[0xb] = iVar62;
    piVar63[4] = iVar58;
    piVar63[5] = iVar57;
    uVar3 = piVar63[0xc];
    uVar52 = *(uint *)(pTVar37 + 0x24) & 0xfe000000;
    piVar63[0xc] = uVar52 | uVar3 & 0x1ffffff;
    uVar56 = (*(uint *)(pTVar37 + 0x24) >> 0x13 & 0x3f) << 0x13;
    piVar63[0xc] = uVar56 | uVar52 | uVar3 & 0x7ffff;
    uVar59 = *(uint *)(pTVar37 + 0x24) & 0x7f800;
    piVar63[0xc] = uVar59 | uVar56 | uVar52 | uVar3 & 0x7ff;
    uVar61 = (*(uint *)(pTVar37 + 0x24) >> 10 & 1) << 10;
    piVar63[0xc] = uVar61 | uVar59 | uVar56 | uVar52 | uVar3 & 0x3ff;
    piVar63[0xc] = (*(uint *)(pTVar37 + 0x24) >> 9 & 1) << 9 |
                   uVar61 | uVar59 | uVar56 | uVar52 | uVar3 & 0x1ff;
    piVar63[0xd] = 1;
    piVar63[0xe] = 0;
    piVar63[0xf] = 0;
    piVar54 = *(int **)((int)param_1 + 4);
    iVar58 = piVar54[3];
    piVar54[3] = iVar58 + 1;
    piVar63[2] = iVar58 + 1;
    uVar16 = *(undefined4 *)(*piVar54 + ((piVar54[1] - *piVar54 & 0xfffffffcU) - 4));
    local_84c = (unsigned char *)0x0;
    psVar22 = (unsigned char *)(**(code **)(*piVar63 + 8))();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_1e0,psVar22);
    local_1d8 = piVar63;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_840,uVar16,&local_1e0);
    local_850 = local_840;
    piVar63 = (int *)(local_1dc + -4);
    local_84c = local_83c;
    local_1d0[0] = local_1e0;
    do {
      iVar58 = *piVar63;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,piVar63);
        *piVar63 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_1dc + -0xc),local_1d0);
    }
    if (local_84c == (unsigned char *)0x0) {
      uVar59 = puVar49[-0x20];
      iVar58 = *(int *)(uVar59 + 4);
      *(unsigned char *)(iVar58 + *(int *)(iVar58 + -0xc)) = *DAT_a7b7ba88;
      TParseContext__error
                ((int)param_1,(char *)puVar49[-0x21],"redefinition",*(char **)(uVar59 + 4),"struct",
                 iVar34,iVar58,uVar59);
      TParseContext__recover(param_1);
    }
    local_82c = (unsigned char *)0x0;
    local_830 = (unsigned char *)0xe;
    local_828 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x0;
    local_820 = (unsigned char *)0x0;
    local_858 = (unsigned char *)puVar49[-0x2c];
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
    pTVar15 = local_878;
    local_85c = pTVar37;
    local_83c = pTVar37;
    local_838 = local_858;
    local_81c = pTVar37;
    local_818 = local_858;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0x9f:
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar37 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    pTVar55 = (unsigned char *)puVar49[-7];
    local_1c0[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              ((unsigned char *)&local_850,"",(unsigned char *)local_1c0);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_840,(unsigned char *)&local_850);
    local_5c = (unsigned char *)0xa7b8374c;
    *(undefined ***)pTVar37 = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined4 *)(pTVar37 + 0x20) = 0;
    *(uint *)(pTVar37 + 0x24) = *(uint *)(pTVar37 + 0x24) & 0x9ff | 0x700800;
    *(undefined4 *)(pTVar37 + 4) = 0;
    *(unsigned char **)(pTVar37 + 8) = pTVar55;
    *(undefined4 *)(pTVar37 + 0xc) = 0;
    *(undefined4 *)(pTVar37 + 0x14) = 0;
    *(undefined4 *)(pTVar37 + 0x1c) = 0;
    uVar16 = TType__setStructSize(pTVar37,pTVar55);
    pTVar4 = local_83c;
    *(undefined4 *)(pTVar37 + 0x18) = uVar16;
    local_64 = (unsigned char *)0xa7b8374c;
    local_83c[*(int *)(local_83c + -0xc)] = *DAT_a7b7ba88;
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pvVar13 = (void *)TPoolAllocator__allocate(pTVar17,8);
    in_cr0 = (pvVar13 == (void *)0x0) << 1;
    pvVar24 = (void *)0x0;
    if (pvVar13 != (void *)0x0) {
      local_1b0[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (pvVar13,(char *)pTVar4,(unsigned char *)local_1b0);
      pvVar24 = pvVar13;
    }
    *(void **)(pTVar37 + 0x10) = pvVar24;
    pTVar4 = local_83c + -4;
    local_1a0[0] = local_840;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_1a0);
    }
    pTVar4 = local_84c + -4;
    local_190[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_84c + -0xc),local_190);
    }
    local_830 = (unsigned char *)0xe;
    local_82c = (unsigned char *)0x0;
    local_828 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x0;
    local_820 = (unsigned char *)0x0;
    local_858 = (unsigned char *)puVar49[-0x21];
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
    pTVar15 = local_878;
    local_85c = pTVar37;
    local_83c = pTVar37;
    local_838 = local_858;
    local_81c = pTVar37;
    local_818 = local_858;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0xa1:
    local_870 = (unsigned char *)puVar49[-7];
    for (uVar59 = 0; pTVar4 = DAT_a7b7ba88, pTVar15 = local_878, pTVar50 = local_7f0,
        pTVar2 = local_750[0],
        uVar59 < (uint)(*(int *)(puVar49[4] + 8) - *(int *)(puVar49[4] + 4) >> 3);
        uVar59 = uVar59 + 1) {
      uVar52 = 0;
      iVar58 = uVar59 * 8;
      while( true ) {
        puVar18 = *(undefined4 **)(local_870 + 8);
        if ((uint)((int)puVar18 - *(int *)(local_870 + 4) >> 3) <= uVar52) break;
        iVar57 = (**(code **)(**(int **)(*(int *)(local_870 + 4) + uVar52 * 8) + 0x1c))();
        iVar62 = (**(code **)(**(int **)(*(int *)(puVar49[4] + 4) + iVar58) + 0x1c))();
        uVar56 = *(uint *)(*(int *)(iVar57 + 4) + -0xc);
        local_78 = uVar56;
        uVar61 = *(uint *)(*(int *)(iVar62 + 4) + -0xc);
        local_74 = uVar61;
        puVar26 = &local_74;
        if (uVar56 <= uVar61) {
          puVar26 = &local_78;
        }
        iVar57 = _memcmp(*(void **)(iVar57 + 4),*(void **)(iVar62 + 4),*puVar26);
        in_cr0 = (iVar57 == 0) << 1;
        if (iVar57 == 0) {
          iVar57 = uVar56 - uVar61;
        }
        if (iVar57 == 0) {
          iVar57 = (**(code **)(**(int **)(*(int *)(puVar49[4] + 4) + iVar58) + 0x1c))();
          *(unsigned char *)(*(int *)(iVar57 + 4) + *(int *)(*(int *)(iVar57 + 4) + -0xc)) = *pTVar4;
          TParseContext__error
                    ((int)param_1,*(char **)(*(int *)(puVar49[4] + 4) + iVar58 + 4),
                     "duplicate field name in structure:","struct",*(undefined4 *)(iVar57 + 4),
                     pTVar37,puVar49[4],param_8);
          TParseContext__recover(param_1);
        }
        uVar52 = uVar52 + 1;
      }
      if (puVar18 == *(undefined4 **)(local_870 + 0xc)) {
        std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux(local_870,puVar18,*(int *)(puVar49[4] + 4) + iVar58);
      }
      else {
        if (puVar18 != (undefined4 *)0x0) {
          uVar16 = *(undefined4 *)(*(int *)(puVar49[4] + 4) + iVar58 + 4);
          *puVar18 = *(undefined4 *)(*(int *)(puVar49[4] + 4) + iVar58);
          puVar18[1] = uVar16;
        }
        *(int *)(local_870 + 8) = *(int *)(local_870 + 8) + 8;
      }
    }
    break;
  case 0xa2:
    local_870 = (unsigned char *)puVar49[-7];
    psVar22 = (unsigned char *)(**(code **)(*(int *)**(undefined4 **)(puVar49[-7] + 4) + 0x1c))();
    iVar58 = TParseContext__voidErrorCheck
                       (param_1,puVar49[-0xc],psVar22,(unsigned char *)(puVar49 + -0x12));
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    for (uVar59 = 0; pTVar15 = local_878, pTVar50 = local_7f0, pTVar2 = local_750[0],
        uVar59 < (uint)(*(int *)(local_870 + 8) - *(int *)(local_870 + 4) >> 3); uVar59 = uVar59 + 1
        ) {
      piVar63 = *(int **)(*(int *)(local_870 + 4) + uVar59 * 8);
      (**(code **)(*piVar63 + 0xc))
                (piVar63,puVar49[-0x12],puVar49[-0x10],puVar49[-0xf],puVar49[-0xd]);
      if ((int *)puVar49[-0xd] != (int *)0x0) {
        piVar63 = *(int **)(*(int *)(local_870 + 4) + uVar59 * 8);
        iVar58 = *piVar63;
        uVar16 = (**(code **)(*(int *)puVar49[-0xd] + 0x18))();
        (**(code **)(iVar58 + 0x10))(piVar63,uVar16);
      }
    }
    break;
  case 0xa3:
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar37 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x10);
    in_cr0 = (pTVar37 == (unsigned char *)0x0) << 1;
    pTVar4 = (unsigned char *)0x0;
    if (pTVar37 != (unsigned char *)0x0) {
      local_180 = GetGlobalPoolAllocator();
      *(int *)(pTVar37 + 0xc) = 0;
      *(int *)pTVar37 = local_180;
      *(int *)(pTVar37 + 4) = 0;
      *(int *)(pTVar37 + 8) = 0;
      pTVar4 = pTVar37;
    }
    goto LAB_97baadbc;
  case 0xa4:
    pTVar4 = local_870;
LAB_97baadbc:
    local_870 = pTVar4;
    puVar26 = *(uint **)(local_870 + 8);
    if (puVar26 == *(uint **)(local_870 + 0xc)) {
      std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux(local_870,puVar26,puVar49 + 4);
      pTVar15 = local_878;
      pTVar50 = local_7f0;
      pTVar2 = local_750;
    }
    else {
      iVar58 = 0;
      if (puVar26 != (uint *)0x0) {
        uVar59 = puVar49[5];
        *puVar26 = puVar49[4];
        puVar26[1] = uVar59;
        iVar58 = *(int *)(local_870 + 8);
      }
      *(int *)(local_870 + 8) = iVar58 + 8;
      pTVar15 = local_878;
      pTVar50 = local_7f0;
      pTVar2 = local_750;
    }
    break;
  case 0xa5:
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar4 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    *(undefined ***)pTVar4 = &PTR___ZN5TTypeD1Ev_a7b7d640;
    uVar59 = *(uint *)(pTVar4 + 0x24) & 0x9ff | 0x800;
    in_cr0 = (uVar59 == 0) << 1;
    *(int *)(pTVar4 + 0x20) = 0;
    *(uint *)(pTVar4 + 0x24) = uVar59;
    *(int *)(pTVar4 + 4) = 0;
    *(int *)(pTVar4 + 8) = 0;
    *(int *)(pTVar4 + 0xc) = 0;
    *(int *)(pTVar4 + 0x10) = 0;
    *(int *)(pTVar4 + 0x14) = 0;
    *(int *)(pTVar4 + 0x18) = 0;
    *(int *)(pTVar4 + 0x1c) = 0;
    local_86c = (unsigned char *)*puVar49;
    uVar59 = puVar49[1];
    pcVar42 = *(code **)(*(int *)pTVar4 + 0x14);
    local_870 = pTVar4;
    goto LAB_97baae6c;
  case 0xa6:
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    local_870 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    pTVar37 = (unsigned char *)0xa7b8374c;
    *(undefined ***)local_870 = &PTR___ZN5TTypeD1Ev_a7b7d640;
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
    local_86c = (unsigned char *)puVar49[-0x21];
    (**(code **)(*(int *)local_870 + 0x14))(local_870,puVar49[-0x20]);
    iVar58 = (**(code **)(*(int *)puVar49[-9] + 0x18))();
    if (iVar58 != 0) {
      piVar63 = (int *)(**(code **)(*(int *)puVar49[-9] + 0x18))();
      iVar58 = (**(code **)(*piVar63 + 0x40))();
      if ((iVar58 == 2) &&
         (iVar58 = (**(code **)(*(int *)puVar49[-9] + 0x18))(), pTVar4 = local_870,
         0 < **(int **)(iVar58 + 0x30))) {
        iVar58 = (**(code **)(*(int *)puVar49[-9] + 0x18))();
        iVar58 = **(int **)(iVar58 + 0x30);
        *(uint *)(pTVar4 + 0x24) = *(uint *)(pTVar4 + 0x24) | 0x200;
        *(int *)(pTVar4 + 4) = iVar58;
        pTVar15 = local_878;
        pTVar50 = local_7f0;
        pTVar2 = local_750;
        break;
      }
    }
    param_8 = puVar49[-0x20];
    local_64 = (unsigned char *)0xa7b8374c;
    piVar63 = *(int **)(param_8 + 4);
    pcVar31 = "structure field array size must be a positive integer";
    *(unsigned char *)((int)piVar63 + piVar63[-3]) = *DAT_a7b7ba88;
    pcVar33 = *(char **)(param_8 + 4);
    pcVar64 = (char *)puVar49[-0x16];
    goto LAB_97bab5e8;
  case 0xb1:
    iVar58 = *(int *)((int)param_1 + 4);
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    puVar18 = (undefined4 *)TPoolAllocator__allocate(pTVar17,0x10);
    local_170 = (unsigned char *)GetGlobalPoolAllocator();
    *puVar18 = local_170;
    puVar18[1] = 0;
    puVar19 = (undefined4 *)TPoolAllocator__allocate(local_170,0x1c);
    puVar18[2] = 0;
    puVar18[1] = puVar19;
    *puVar19 = 0;
    *(undefined4 *)(puVar18[1] + 4) = 0;
    *(undefined4 *)(puVar18[1] + 8) = puVar18[1];
    *(undefined4 *)(puVar18[1] + 0xc) = puVar18[1];
    piVar63 = *(int **)(iVar58 + 4);
    local_160[0] = puVar18;
    if (piVar63 == *(int **)(iVar58 + 8)) {
      std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                (iVar58,piVar63,local_160);
      pTVar15 = local_878;
      pTVar50 = local_7f0;
      pTVar2 = local_750;
    }
    else {
      iVar57 = 0;
      if (piVar63 != (int *)0x0) {
        *piVar63 = (int)puVar18;
        iVar57 = *(int *)(iVar58 + 4);
      }
      *(int *)(iVar58 + 4) = iVar57 + 4;
      pTVar15 = local_878;
      pTVar50 = local_7f0;
      pTVar2 = local_750;
    }
    break;
  case 0xb2:
    piVar63 = *(int **)((int)param_1 + 4);
    iVar58 = piVar63[1];
    pvVar24 = *(void **)(*piVar63 + ((iVar58 - *piVar63 & 0xfffffffcU) - 4));
    if (pvVar24 != (void *)0x0) {
      ((int (*)())__ZN17TSymbolTableLevelD1Ev)(pvVar24);
      iVar58 = piVar63[1];
    }
    piVar63[1] = iVar58 + -4;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0xb3:
    piVar63 = (int *)puVar49[-0x14];
    pTVar15 = (unsigned char *)0x0;
    if (piVar63 != (int *)0x0) {
      (**(code **)(*piVar63 + 0x60))(piVar63,1);
      pTVar15 = (unsigned char *)puVar49[-0x14];
      pTVar50 = local_7f0;
      pTVar2 = local_750;
    }
    break;
  case 0xb8:
    pTVar14 = *(unsigned char **)param_1;
    uVar59 = 0;
    pTVar20 = (unsigned char *)puVar49[2];
LAB_97bab0ec:
    pTVar15 = (unsigned char *)TIntermediate__makeAggregate(pTVar14,pTVar20,uVar59);
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0xb9:
    pTVar14 = *(unsigned char **)param_1;
    uVar59 = 0;
    pTVar23 = (unsigned char *)puVar49[-9];
    pTVar20 = (unsigned char *)puVar49[2];
    goto LAB_97ba97d8;
  case 0xbc:
    iVar58 = __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped
                       (param_1,puVar49[-0x2c],(unsigned char *)puVar49[-0x14]);
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    local_850 = (unsigned char *)puVar49[2];
    local_84c = (unsigned char *)puVar49[3];
    pTVar15 = (unsigned char *)__ZN13TIntermediate12addSelectionEP12TIntermTyped15TIntermNodePairi
                                 (*(undefined4 *)param_1,puVar49[-0x14],local_850,local_84c,
                                  puVar49[-0x2c]);
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0xbd:
  case 0xcc:
    local_874 = puVar49[2];
    pTVar15 = (unsigned char *)puVar49[-0x14];
    break;
  case 0xbe:
    pTVar15 = (unsigned char *)puVar49[2];
    goto LAB_97bab424;
  case 0xbf:
    local_878 = (unsigned char *)puVar49[2];
    iVar58 = (*(code *)**(undefined4 **)puVar49[2])();
    iVar58 = __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped
                       (param_1,iVar58,(unsigned char *)puVar49[2]);
    goto LAB_97bab180;
  case 0xc0:
    pTVar29 = (unsigned char *)(puVar49 + -0x1d);
    iVar58 = TParseContext__structQualifierErrorCheck(param_1,puVar49[-0x16],pTVar29);
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    iVar58 = __ZN13TParseContext14boolErrorCheckEiRK11TPublicType(param_1,puVar49[-0x16],pTVar29);
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    iVar58 = TParseContext__executeInitializer
                       (param_1,puVar49[-0x16],(unsigned char *)puVar49[-0x15],pTVar29,
                        (unsigned char *)puVar49[2],&pTStack_70);
    if (iVar58 == 0) goto switchD_97ba39c8_caseD_2;
LAB_97bab1f4:
    TParseContext__recover(param_1);
    pTVar15 = (unsigned char *)0x0;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0xc1:
    iVar58 = *(int *)((int)param_1 + 4);
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    puVar18 = (undefined4 *)TPoolAllocator__allocate(pTVar17,0x10);
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    local_150 = pTVar17;
    goto LAB_97bab2e8;
  case 0xc2:
    piVar63 = *(int **)((int)param_1 + 4);
    iVar58 = piVar63[1];
    pvVar24 = *(void **)(*piVar63 + ((iVar58 - *piVar63 & 0xfffffffcU) - 4));
    if (pvVar24 != (void *)0x0) {
      ((int (*)())__ZN17TSymbolTableLevelD1Ev)(pvVar24);
      iVar58 = piVar63[1];
    }
    piVar63[1] = iVar58 + -4;
    bVar36 = true;
    pTVar14 = *(unsigned char **)param_1;
    pTVar20 = (unsigned char *)puVar49[2];
    pTVar30 = (unsigned char *)puVar49[-0x14];
    uVar59 = puVar49[-0x37];
    goto LAB_97bab2b4;
  case 0xc3:
    goto switchD_97ba39c8_caseD_c3;
  case 0xc4:
    iVar58 = __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped
                       (param_1,*puVar49,(unsigned char *)puVar49[-0x14]);
    if (iVar58 != 0) {
      TParseContext__recover(param_1);
    }
    pTVar14 = *(unsigned char **)param_1;
    pTVar20 = (unsigned char *)puVar49[-0x35];
    bVar36 = false;
    pTVar30 = (unsigned char *)puVar49[-0x14];
    uVar59 = puVar49[-0x2c];
LAB_97bab2b4:
    local_878 = (unsigned char *)TIntermediate__addLoop
                                   (pTVar14,pTVar20,pTVar30,(unsigned char *)0x0,bVar36,uVar59);
    iVar58 = *(int *)((int)param_1 + 0x20);
LAB_97bab40c:
    iVar58 = iVar58 + -1;
    goto LAB_97bab410;
  case 0xc5:
    iVar58 = *(int *)((int)param_1 + 4);
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    puVar18 = (undefined4 *)TPoolAllocator__allocate(pTVar17,0x10);
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    local_140 = pTVar17;
LAB_97bab2e8:
    *puVar18 = pTVar17;
    puVar18[1] = 0;
    puVar19 = (undefined4 *)TPoolAllocator__allocate(pTVar17,0x1c);
    puVar18[2] = 0;
    puVar18[1] = puVar19;
    *puVar19 = 0;
    *(undefined4 *)(puVar18[1] + 4) = 0;
    *(undefined4 *)(puVar18[1] + 8) = puVar18[1];
    *(undefined4 *)(puVar18[1] + 0xc) = puVar18[1];
    puVar19 = *(undefined4 **)(iVar58 + 4);
    local_160[0] = puVar18;
    if (puVar19 == *(undefined4 **)(iVar58 + 8)) {
      std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                (iVar58,puVar19,local_160);
    }
    else {
      iVar57 = 0;
      if (puVar19 != (undefined4 *)0x0) {
        *puVar19 = puVar18;
        iVar57 = *(int *)(iVar58 + 4);
      }
      *(int *)(iVar58 + 4) = iVar57 + 4;
    }
switchD_97ba39c8_caseD_c3:
    iVar58 = *(int *)((int)param_1 + 0x20) + 1;
LAB_97bab410:
    *(int *)((int)param_1 + 0x20) = iVar58;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0xc6:
    piVar63 = *(int **)((int)param_1 + 4);
    iVar58 = piVar63[1];
    pvVar24 = *(void **)(*piVar63 + ((iVar58 - *piVar63 & 0xfffffffcU) - 4));
    if (pvVar24 != (void *)0x0) {
      ((int (*)())__ZN17TSymbolTableLevelD1Ev)(pvVar24);
      iVar58 = piVar63[1];
    }
    piVar63[1] = iVar58 + -4;
    local_878 = (unsigned char *)TIntermediate__makeAggregate
                                   (*(unsigned char **)param_1,(unsigned char *)puVar49[-0x1f],
                                    puVar49[-0x37]);
    pTVar20 = (unsigned char *)
              TIntermediate__addLoop
                        (*(unsigned char **)param_1,(unsigned char *)puVar49[2],
                         (unsigned char *)puVar49[-0x14],(unsigned char *)puVar49[-0x13],true,
                         puVar49[-0x42]);
    local_878 = (unsigned char *)TIntermediate__growAggregate
                                   (*(unsigned char **)param_1,(unsigned char *)local_878,pTVar20,
                                    puVar49[-0x42]);
    piVar63 = (int *)(**(code **)(*(int *)local_878 + 0x1c))();
    (**(code **)(*piVar63 + 0x60))(piVar63,1);
    iVar58 = *(int *)((int)param_1 + 0x20);
    goto LAB_97bab40c;
  case 0xcb:
    pTVar15 = (unsigned char *)puVar49[-9];
LAB_97bab424:
    local_874 = 0;
    break;
  case 0xcd:
    if (*(int *)((int)param_1 + 0x20) < 1) {
      TParseContext__error
                ((int)param_1,(char *)puVar49[-0xb],"continue statement only allowed in loops","",""
                 ,pTVar37,iVar57,param_8);
      TParseContext__recover(param_1);
    }
    uVar16 = *(undefined4 *)param_1;
    uVar27 = 0x65;
    goto LAB_97bab644;
  case 0xce:
    if (*(int *)((int)param_1 + 0x20) < 1) {
      TParseContext__error
                ((int)param_1,(char *)puVar49[-0xb],"break statement only allowed in loops","","",
                 pTVar37,iVar57,param_8);
      TParseContext__recover(param_1);
    }
    uVar16 = *(undefined4 *)param_1;
    uVar27 = 100;
    goto LAB_97bab644;
  case 0xcf:
    local_878 = (unsigned char *)__ZN13TIntermediate9addBranchE9TOperatori
                                   (*(undefined4 *)param_1,99,puVar49[-0xb]);
    piVar63 = (int *)**(undefined4 **)((int)param_1 + 0x28);
    iVar58 = (*(code *)piVar63[8])(*(undefined4 **)((int)param_1 + 0x28));
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    if (iVar58 == 0) break;
    pcVar64 = (char *)puVar49[-0xb];
    pcVar31 = "non-void function must return a value";
    goto LAB_97bab5e4;
  case 0xd0:
    local_878 = (unsigned char *)__ZN13TIntermediate9addBranchE9TOperatorP12TIntermTypedi
                                   (*(undefined4 *)param_1,99,puVar49[-9],puVar49[-0x16]);
    piVar63 = *(int **)((int)param_1 + 0x28);
    *(undefined4 *)((int)param_1 + 0x2c) = 1;
    iVar58 = (**(code **)(*piVar63 + 0x20))(piVar63);
    if (iVar58 == 0) {
      pcVar64 = (char *)puVar49[-0x16];
      pcVar31 = "void function cannot return a value";
    }
    else {
      iVar58 = *(int *)((int)param_1 + 0x28);
      (**(code **)(*(int *)puVar49[-9] + 0x38))(&local_850);
      bVar36 = false;
      if (((*(uint *)(iVar58 + 0x24) & 0x1fffe00) == ((uint)local_82c & 0x1fffe00)) &&
         (*(unsigned char **)(iVar58 + 8) == local_848)) {
        bVar36 = true;
      }
      local_5c = (unsigned char *)0xa7b8374c;
      local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      pTVar15 = local_878;
      pTVar50 = local_7f0;
      pTVar2 = local_750;
      if (bVar36) break;
      pcVar64 = (char *)puVar49[-0x16];
      pcVar31 = "function return is not matching type:";
      piVar63 = (int *)0x0;
    }
LAB_97bab5e4:
    pcVar33 = "return";
LAB_97bab5e8:
    TParseContext__error((int)param_1,pcVar64,pcVar31,pcVar33,"",pTVar37,piVar63,param_8);
    goto LAB_97bab5f4;
  case 0xd1:
    if (*(int *)((int)param_1 + 0xc) != 1) {
      TParseContext__error
                ((int)param_1,(char *)puVar49[-0xb]," supported in fragment shaders only ","discard"
                 ,"","",iVar57,param_8);
      TParseContext__recover(param_1);
    }
    uVar16 = *(undefined4 *)param_1;
    uVar27 = 0x62;
LAB_97bab644:
    pTVar15 = (unsigned char *)__ZN13TIntermediate9addBranchE9TOperatori(uVar16,uVar27,puVar49[-0xb]);
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0xd2:
    pTVar15 = (unsigned char *)puVar49[2];
    goto LAB_97bab674;
  case 0xd3:
    pTVar15 = (unsigned char *)TIntermediate__growAggregate
                                 (*(unsigned char **)param_1,(unsigned char *)puVar49[-9],
                                  (unsigned char *)puVar49[2],0);
LAB_97bab674:
    *(unsigned char **)((int)param_1 + 0x10) = pTVar15;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0xd6:
    piVar63 = (int *)puVar49[4];
    piVar54 = *(int **)((int)param_1 + 4);
    uVar16 = (**(code **)(*piVar63 + 8))(piVar63);
    iVar58 = *piVar54;
    iVar57 = (piVar54[1] - iVar58 >> 2) + -1;
    while( true ) {
      iVar62 = *(int *)(iVar58 + iVar57 * 4);
      iVar58 = 0;
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_320,iVar62,uVar16);
      if (local_320[0] != *(int *)(iVar62 + 4)) {
        iVar58 = *(int *)(local_320[0] + 0x18);
      }
      iVar57 = iVar57 + -1;
      if ((iVar58 != 0) || (iVar57 < 0)) break;
      iVar58 = *piVar54;
    }
    if (*(int *)(iVar58 + 0x50) != 0) {
      iVar62 = piVar63[1];
      local_64 = (unsigned char *)0xa7b8374c;
      iVar57 = *(int *)(iVar62 + 4);
      *(unsigned char *)(iVar57 + *(int *)(iVar57 + -0xc)) = *DAT_a7b7ba88;
      TParseContext__error
                ((int)param_1,(char *)*puVar49,"function already has a body",*(char **)(iVar62 + 4),
                 "",pTVar37,iVar57,iVar62);
      TParseContext__recover(param_1);
    }
    *(undefined4 *)(iVar58 + 0x50) = 1;
    iVar57 = __ZNKSbIcSt11char_traitsIcE14pool_allocatorIcEE7compareEPKc((void *)piVar63[1],"main");
    local_58 = piVar63 + 3;
    if (iVar57 == 0) {
      iVar57 = piVar63[5] - piVar63[4] >> 3;
      in_cr0 = (iVar57 == 0) << 1;
      if (0 < iVar57) {
        iVar62 = piVar63[1];
        iVar57 = *(int *)(iVar62 + 4);
        *(unsigned char *)(iVar57 + *(int *)(iVar57 + -0xc)) = *DAT_a7b7ba88;
        TParseContext__error
                  ((int)param_1,(char *)*puVar49,"function cannot take any parameter(s)",
                   *(char **)(iVar62 + 4),"",pTVar37,iVar57,iVar62);
        TParseContext__recover(param_1);
      }
      iVar57 = (**(code **)(piVar63[7] + 0x20))(piVar63 + 7);
      if (iVar57 != 0) {
        iVar62 = piVar63[1];
        local_64 = (unsigned char *)0xa7b8374c;
        iVar57 = *(int *)(iVar62 + 4);
        *(unsigned char *)(iVar57 + *(int *)(iVar57 + -0xc)) = *DAT_a7b7ba88;
        TParseContext__error
                  ((int)param_1,(char *)*puVar49,"function cannot return a value",
                   *(char **)(iVar62 + 4),"",pTVar37,iVar57,iVar62);
        TParseContext__recover(param_1);
      }
    }
    iVar57 = *(int *)((int)param_1 + 4);
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    puVar18 = (undefined4 *)TPoolAllocator__allocate(pTVar17,0x10);
    local_130 = (unsigned char *)GetGlobalPoolAllocator();
    *puVar18 = local_130;
    puVar18[1] = 0;
    puVar19 = (undefined4 *)TPoolAllocator__allocate(local_130,0x1c);
    puVar18[2] = 0;
    puVar18[1] = puVar19;
    *puVar19 = 0;
    *(undefined4 *)(puVar18[1] + 4) = 0;
    *(undefined4 *)(puVar18[1] + 8) = puVar18[1];
    *(undefined4 *)(puVar18[1] + 0xc) = puVar18[1];
    puVar19 = *(undefined4 **)(iVar57 + 4);
    local_160[0] = puVar18;
    if (puVar19 == *(undefined4 **)(iVar57 + 8)) {
      std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                (iVar57,puVar19,local_160);
    }
    else {
      iVar62 = 0;
      if (puVar19 != (undefined4 *)0x0) {
        *puVar19 = puVar18;
        iVar62 = *(int *)(iVar57 + 4);
      }
      *(int *)(iVar57 + 4) = iVar62 + 4;
    }
    *(int *)((int)param_1 + 0x28) = iVar58 + 0x1c;
    *(undefined4 *)((int)param_1 + 0x2c) = 0;
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar20 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x6c);
    local_5c = (unsigned char *)0xa7b8374c;
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    local_82c = (unsigned char *)((uint)local_82c & 0x1ff | 0x80800);
    local_84c = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_838 = (unsigned char *)0x0;
    local_834 = (unsigned char *)0x0;
    local_830 = (unsigned char *)0x0;
    *(undefined4 *)(pTVar20 + 4) = 0;
    *(undefined ***)pTVar20 = &PTR_getLine_a7b7d5d8;
    *(undefined4 *)(pTVar20 + 0xc) = 0;
    *(undefined4 *)(pTVar20 + 0x10) = 0;
    *(undefined4 *)(pTVar20 + 0x14) = 0;
    *(undefined4 *)(pTVar20 + 0x18) = 0;
    *(undefined4 *)(pTVar20 + 0x1c) = 0;
    *(undefined4 *)(pTVar20 + 0x20) = 0;
    *(undefined4 *)(pTVar20 + 0x24) = 0;
    *(undefined ***)(pTVar20 + 8) = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined4 *)(pTVar20 + 0x28) = 0;
    uVar59 = *(uint *)(pTVar20 + 0x2c);
    *(uint *)(pTVar20 + 0x2c) = uVar59 & 0x1ffffff;
    *(uint *)(pTVar20 + 0x2c) = uVar59 & 0x7ffff | 0x80000;
    *(uint *)(pTVar20 + 0x2c) = uVar59 & 0x7ff | 0x80800;
    *(uint *)(pTVar20 + 0x2c) = uVar59 & 0x3ff | 0x80800;
    puVar6 = PTR_vtable_a7b7c0d0;
    *(uint *)(pTVar20 + 0x2c) = uVar59 & 0x1ff | 0x80800;
    *(undefined **)pTVar20 = puVar6 + 8;
    *(undefined4 *)(pTVar20 + 0x30) = 0;
    local_120 = GetGlobalPoolAllocator();
    *(undefined4 *)(pTVar20 + 0x40) = 0;
    *(undefined4 *)(pTVar20 + 0x38) = 0;
    *(undefined4 *)(pTVar20 + 0x3c) = 0;
    *(undefined4 *)(pTVar20 + 0x34) = local_120;
    local_110 = GetGlobalPoolAllocator();
    *(undefined4 *)(pTVar20 + 0x44) = local_110;
    iVar58 = DAT_a7b7ba84;
    *(undefined4 *)(pTVar20 + 0x50) = 0;
    *(undefined4 *)(pTVar20 + 0x48) = 0;
    piVar54 = (int *)(iVar58 + 8);
    *(undefined4 *)(pTVar20 + 0x4c) = 0;
    do {
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(*piVar54 + 1,0,piVar54);
        *piVar54 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    local_100 = GetGlobalPoolAllocator();
    *(int *)(pTVar20 + 0x58) = iVar58 + 0xc;
    *(undefined4 *)(pTVar20 + 0x68) = 0;
    *(undefined4 *)(pTVar20 + 0x5c) = 0;
    *(undefined4 *)(pTVar20 + 0x54) = local_100;
    local_54 = -0x5847c8b4;
    local_68 = &TType__vtable;
    for (iVar58 = 0; iVar58 < local_58[2] - local_58[1] >> 3; iVar58 = iVar58 + 1) {
      iVar62 = piVar63[4];
      iVar57 = iVar58 * 8;
      if (*(int *)(iVar62 + iVar57) == 0) {
        local_d0[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (&local_850,"",(unsigned char *)local_d0);
        pTVar23 = (unsigned char *)
                  TIntermediate__addSymbol
                            (*(unsigned char **)param_1,0,(unsigned char *)&local_850,
                             *(unsigned char **)(iVar62 + iVar57 + 4),*puVar49);
        pTVar20 = (unsigned char *)
                  TIntermediate__growAggregate(*(unsigned char **)param_1,pTVar20,pTVar23,*puVar49);
        pTVar4 = local_84c + -4;
        local_c0[0] = local_850;
        do {
          iVar57 = *(int *)pTVar4;
          if (in_RESERVE != '\0') {
            iVar62 = storeWordConditionalIndexed(iVar57 + -1,0,pTVar4);
            *(int *)pTVar4 = iVar62;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
        if (iVar57 < 1) {
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                    ((unsigned char *)(local_84c + -0xc),local_c0);
        }
      }
      else {
        pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
        piVar21 = (int *)TPoolAllocator__allocate(pTVar17,0x40);
        puVar6 = PTR_vtable_a7b7c0b4 + 8;
        iVar39 = *(int *)(iVar62 + iVar57 + 4);
        piVar21[1] = *(int *)(iVar62 + iVar57);
        *piVar21 = (int)puVar6;
        iVar40 = *(int *)(iVar39 + 0xc);
        iVar38 = *(int *)(iVar39 + 0x10);
        iVar35 = *(int *)(iVar39 + 0x14);
        iVar34 = *(int *)(iVar39 + 0x18);
        iVar32 = *(int *)(iVar39 + 0x1c);
        iVar28 = *(int *)(iVar39 + 0x20);
        iVar7 = *(int *)(iVar39 + 4);
        iVar41 = *(int *)(iVar39 + 8);
        piVar21[3] = (int)(local_68 + 8);
        piVar21[6] = iVar40;
        piVar21[7] = iVar38;
        piVar21[8] = iVar35;
        piVar21[9] = iVar34;
        piVar21[10] = iVar32;
        piVar21[0xb] = iVar28;
        piVar21[5] = iVar41;
        piVar21[4] = iVar7;
        uVar3 = piVar21[0xc];
        uVar52 = *(uint *)(iVar39 + 0x24) & 0xfe000000;
        piVar21[0xc] = uVar52 | uVar3 & 0x1ffffff;
        uVar56 = (*(uint *)(iVar39 + 0x24) >> 0x13 & 0x3f) << 0x13;
        piVar21[0xc] = uVar56 | uVar52 | uVar3 & 0x7ffff;
        uVar59 = *(uint *)(iVar39 + 0x24) & 0x7f800;
        piVar21[0xc] = uVar59 | uVar56 | uVar52 | uVar3 & 0x7ff;
        uVar61 = (*(uint *)(iVar39 + 0x24) >> 10 & 1) << 10;
        piVar21[0xc] = uVar61 | uVar59 | uVar56 | uVar52 | uVar3 & 0x3ff;
        piVar21[0xc] = (*(uint *)(iVar39 + 0x24) >> 9 & 1) << 9 |
                       uVar61 | uVar59 | uVar56 | uVar52 | uVar3 & 0x1ff;
        piVar21[0xd] = 0;
        piVar21[0xe] = 0;
        piVar21[0xf] = 0;
        piVar54 = *(int **)((int)param_1 + 4);
        iVar7 = piVar54[3];
        piVar54[3] = iVar7 + 1;
        piVar21[2] = iVar7 + 1;
        uVar16 = *(undefined4 *)(*piVar54 + ((piVar54[1] - *piVar54 & 0xfffffffcU) - 4));
        local_84c = (unsigned char *)0x0;
        psVar22 = (unsigned char *)(**(code **)(*piVar21 + 8))();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_f0,psVar22);
        local_e8 = piVar21;
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_840,uVar16,&local_f0);
        local_850 = local_840;
        piVar54 = (int *)(local_ec + -4);
        local_84c = local_83c;
        local_e0[0] = local_f0;
        do {
          iVar7 = *piVar54;
          if (in_RESERVE != '\0') {
            iVar28 = storeWordConditionalIndexed(iVar7 + -1,0,piVar54);
            *piVar54 = iVar28;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
        if (iVar7 < 1) {
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                    ((unsigned char *)(local_ec + -0xc),local_e0);
        }
        if (local_84c == (unsigned char *)0x0) {
          iVar28 = piVar21[1];
          iVar7 = *(int *)(iVar28 + 4);
          *(undefined1 *)(iVar7 + *(int *)(iVar7 + -0xc)) = **(undefined1 **)(local_54 + -0x7cc4);
          TParseContext__error
                    ((int)param_1,(char *)*puVar49,"redefinition",*(char **)(iVar28 + 4),"",local_54
                     ,iVar7,iVar28);
          TParseContext__recover(param_1);
          (**(code **)(*piVar21 + 4))(piVar21);
        }
        *(undefined4 *)(iVar62 + iVar57) = 0;
        pTVar23 = (unsigned char *)
                  TIntermediate__addSymbol
                            (*(unsigned char **)param_1,piVar21[2],(unsigned char *)piVar21[1],
                             (unsigned char *)(piVar21 + 3),*puVar49);
        pTVar20 = (unsigned char *)
                  TIntermediate__growAggregate(*(unsigned char **)param_1,pTVar20,pTVar23,*puVar49);
      }
    }
    TIntermediate__setAggregateOperator(*(undefined4 *)param_1,pTVar20,4,*puVar49);
    puVar49[2] = (uint)pTVar20;
    *(undefined4 *)((int)param_1 + 0x20) = 0;
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
    break;
  case 0xd7:
    local_64 = (unsigned char *)0xa7b8374c;
    iVar58 = (**(code **)(**(int **)((int)param_1 + 0x28) + 0x20))();
    pTVar4 = DAT_a7b7ba88;
    if ((iVar58 != 0) && (local_64 = (unsigned char *)0xa7b8374c, *(int *)((int)param_1 + 0x2c) == 0)) {
      iVar58 = *(int *)(puVar49[-0x12] + 4);
      *(unsigned char *)(*(int *)(iVar58 + 4) + *(int *)(*(int *)(iVar58 + 4) + -0xc)) = *DAT_a7b7ba88;
      TParseContext__error
                ((int)param_1,(char *)puVar49[-0x16],"function does not return a value",
                 *(char **)(iVar58 + 4),"",0xa7b8374c,pTVar4,iVar58);
      TParseContext__recover(param_1);
    }
    piVar63 = *(int **)((int)param_1 + 4);
    iVar58 = piVar63[1];
    pvVar24 = *(void **)(*piVar63 + ((iVar58 - *piVar63 & 0xfffffffcU) - 4));
    if (pvVar24 != (void *)0x0) {
      ((int (*)())__ZN17TSymbolTableLevelD1Ev)(pvVar24);
      iVar58 = piVar63[1];
    }
    piVar63[1] = iVar58 + -4;
    local_878 = (unsigned char *)TIntermediate__growAggregate
                                   (*(unsigned char **)param_1,(unsigned char *)puVar49[-0x14],
                                    (unsigned char *)puVar49[2],0);
    TIntermediate__setAggregateOperator(*(undefined4 *)param_1,local_878,3,puVar49[-0x16]);
    iVar58 = (**(code **)(*(int *)puVar49[-0x12] + 8))();
    *(undefined1 *)(*(int *)(iVar58 + 4) + *(int *)(*(int *)(iVar58 + 4) + -0xc)) =
         **(undefined1 **)(local_64 + -0x7cc4);
    pcVar64 = *(char **)(iVar58 + 4);
    local_b0[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (&local_850,pcVar64,(unsigned char *)local_b0);
    piVar63 = (int *)(**(code **)(*(int *)local_878 + 0x1c))();
    (**(code **)(*piVar63 + 0x68))(piVar63,&local_850);
    pTVar4 = local_84c + -4;
    local_a0[0] = local_850;
    do {
      iVar58 = *(int *)pTVar4;
      if (in_RESERVE != '\0') {
        iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,pTVar4);
        *(int *)pTVar4 = iVar57;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar58 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_84c + -0xc),local_a0);
    }
    uVar59 = puVar49[-0x12];
    piVar63 = (int *)(**(code **)(*(int *)local_878 + 0x1c))();
    (**(code **)(*piVar63 + 0x34))(piVar63,uVar59 + 0x1c);
    iVar58 = (**(code **)(*(int *)local_878 + 0x1c))();
    *(undefined4 *)(iVar58 + 0x60) = *(undefined4 *)((int)param_1 + 0x40);
    iVar58 = (**(code **)(*(int *)local_878 + 0x1c))();
    *(undefined4 *)(iVar58 + 100) = *(undefined4 *)((int)param_1 + 0x44);
    this = (unsigned char *)(**(code **)(*(int *)local_878 + 0x1c))();
    TIntermAggregate__addToPragmaTable(this,(unsigned char *)((int)param_1 + 0x48));
    pTVar15 = local_878;
    pTVar50 = local_7f0;
    pTVar2 = local_750;
  }
switchD_97ba39c8_caseD_0:
  local_750[0] = pTVar2;
  local_7f0 = pTVar50;
  local_878 = pTVar15;
  pTVar48 = pTVar48 + iVar53 * -2;
  puVar49 = puVar49 + iVar53 * -0xb + 0xb;
  _memcpy(puVar49,&local_880,0x2c);
  param_8 = *(short *)(" !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^" +
                      local_6c + 0x40) * 2;
  uVar59 = (int)*(short *)(&DAT_97c36138 + param_8) + (int)*(short *)pTVar48;
  if ((uVar59 < 0x4f0) &&
     (iVar53 = uVar59 * 2, (int)*(short *)(&_yycheck + iVar53) == (int)*(short *)pTVar48)) {
    iVar53 = (int)*(short *)(&_yytable + iVar53);
  }
  else {
    iVar53 = (int)*(short *)(&DAT_97c35e08 + param_8);
  }
  goto LAB_97ba3784;
LAB_97ba8338:
  iVar62 = *(int *)(iVar58 + iVar57 * 4);
  iVar58 = 0;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_320,iVar62,uVar16);
  if (local_320[0] != *(int *)(iVar62 + 4)) {
    iVar58 = *(int *)(local_320[0] + 0x18);
  }
  iVar57 = iVar57 + -1;
  if (iVar58 == 0) {
    if (-1 < iVar57) goto LAB_97ba8334;
  }
  else {
    uVar59 = puVar49[-7];
    iVar62 = iVar58 + 0x1c;
    iVar57 = 0;
    if (((*(uint *)(iVar58 + 0x40) & 0x1fffe00) == (*(uint *)(uVar59 + 0x40) & 0x1fffe00)) &&
       (*(int *)(iVar58 + 0x24) == *(int *)(uVar59 + 0x24))) {
      iVar57 = 1;
    }
    if (iVar57 == 0) {
      pcVar64 = (char *)TType__getBasicString(*(uint *)(uVar59 + 0x40) >> 0x13 & 0x3f);
      TParseContext__error
                ((int)param_1,(char *)*puVar49,"overloaded functions must have the same return type"
                 ,pcVar64,"",iVar57,iVar62,uVar59);
      TParseContext__recover(param_1);
    }
    for (iVar62 = 0; iVar62 < *(int *)(iVar58 + 0x14) - *(int *)(iVar58 + 0x10) >> 3;
        iVar62 = iVar62 + 1) {
      iVar7 = iVar62 * 8;
      iVar28 = (**(code **)(**(int **)(*(int *)(iVar58 + 0x10) + iVar7 + 4) + 0x24))();
      iVar32 = (**(code **)(**(int **)(*(int *)(puVar49[-7] + 0x10) + iVar7 + 4) + 0x24))();
      if (iVar28 != iVar32) {
        iVar7 = *(int *)(*(int *)(puVar49[-7] + 0x10) + iVar7 + 4);
        pcVar64 = (char *)getQualifierString(*(uint *)(iVar7 + 0x24) >> 0x19);
        TParseContext__error
                  ((int)param_1,(char *)*puVar49,
                   "overloaded functions must have the same parameter qualifiers",pcVar64,"",iVar57,
                   iVar7,uVar59);
        TParseContext__recover(param_1);
      }
    }
  }
  goto LAB_97ba84b0;
LAB_97ba8334:
  iVar58 = *piVar63;
  goto LAB_97ba8338;
LAB_97ba84b0:
  pTVar4 = (unsigned char *)puVar49[-7];
  piVar63 = *(int **)((int)param_1 + 4);
  local_880 = *puVar49;
  iVar58 = piVar63[3];
  piVar63[3] = iVar58 + 1;
  *(int *)(pTVar4 + 8) = iVar58 + 1;
  uVar16 = *(undefined4 *)(*piVar63 + ((piVar63[1] - *piVar63 & 0xfffffffcU) - 4));
  local_84c = (unsigned char *)0x0;
  local_870 = pTVar4;
  psVar22 = (unsigned char *)(**(code **)(*(int *)pTVar4 + 8))(pTVar4);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_310,psVar22);
  local_308 = pTVar4;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_840,uVar16,&local_310);
  paVar12 = (unsigned char *)(local_30c + -0xc);
  local_850 = local_840;
  piVar63 = (int *)(local_30c + -4);
  local_84c = local_83c;
  local_300[0] = local_310;
  do {
    iVar58 = *piVar63;
    if (in_RESERVE != '\0') {
      iVar57 = storeWordConditionalIndexed(iVar58 + -1,0,piVar63);
      *piVar63 = iVar57;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  bVar36 = 0 < iVar58;
  ppTVar25 = local_300;
  goto LAB_97ba869c;
switchD_97ba39c8_caseD_60:
  pTVar15 = (unsigned char *)0x0;
  pTVar50 = local_7f0;
  pTVar2 = local_750;
  goto switchD_97ba39c8_caseD_0;
LAB_97ba55dc:
  if ((uint)(*(int *)(pTVar15 + 8) - *(int *)(pTVar15 + 4) >> 3) <= uVar59) goto LAB_97ba5740;
  iVar58 = (**(code **)(**(int **)(*(int *)(pTVar15 + 4) + uVar59 * 8) + 0x1c))();
  uVar52 = *(uint *)(*(int *)(iVar58 + 4) + -0xc);
  local_90 = uVar52;
  uVar56 = *(uint *)(*(int *)(puVar49[1] + 4) + -0xc);
  local_8c = uVar56;
  puVar26 = &local_8c;
  if (uVar52 <= uVar56) {
    puVar26 = &local_90;
  }
  iVar58 = _memcmp(*(void **)(iVar58 + 4),*(void **)(puVar49[1] + 4),*puVar26);
  in_cr0 = (iVar58 == 0) << 1;
  if (iVar58 == 0) {
    iVar58 = uVar52 - uVar56;
  }
  if (iVar58 != 0) {
    uVar59 = uVar59 + 1;
    goto LAB_97ba55dc;
  }
  (**(code **)(*(int *)puVar49[-0x14] + 0x38))(&local_850);
  pTVar4 = local_5c + -0x610c;
  local_850 = pTVar4;
  if ((uint)local_82c >> 0x19 == 2) {
    local_878 = (unsigned char *)TParseContext__addConstStruct
                                   (param_1,(unsigned char *)puVar49[1],(unsigned char *)puVar49[-0x14],
                                    puVar49[-0xb]);
    if (local_878 == (unsigned char *)0x0) goto LAB_97ba5554;
    (**(code **)(*(int *)local_878 + 0x34))
              (local_878,*(undefined4 *)(*(int *)(pTVar15 + 4) + uVar59 * 8));
    pTVar4 = (unsigned char *)(**(code **)(*(int *)local_878 + 0x3c))();
    uVar59 = 2;
    pcVar42 = *(code **)(*(int *)pTVar4 + 0x28);
  }
  else {
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pcVar9 = (unsigned char *)TPoolAllocator__allocate(pTVar17,4);
    *(uint *)pcVar9 = uVar59;
    local_81c = (unsigned char *)0x0;
    local_818 = (unsigned char *)0x0;
    local_7fc = (unsigned char *)((uint)local_7fc & 0x9ff | 0x4100800);
    local_814 = (unsigned char *)0x0;
    local_810 = (unsigned char *)0x0;
    local_80c = (unsigned char *)0x0;
    local_808 = (unsigned char *)0x0;
    local_804 = (unsigned char *)0x0;
    local_800 = (unsigned char *)0x0;
    local_820 = pTVar4;
    uVar16 = TIntermediate__addConstantUnion
                       (*(unsigned char **)param_1,pcVar9,(unsigned char *)&local_820,*puVar49);
    local_820 = pTVar4;
    pTVar4 = (unsigned char *)TIntermediate__addIndex
                                (*(undefined4 *)param_1,0x2f,puVar49[-0x14],uVar16,puVar49[-0xb]);
    uVar59 = *(uint *)(*(int *)(pTVar15 + 4) + uVar59 * 8);
    pcVar42 = *(code **)(*(int *)pTVar4 + 0x34);
    local_878 = pTVar4;
  }
LAB_97baae6c:
  (*pcVar42)(pTVar4,uVar59);
  pTVar15 = local_878;
  pTVar50 = local_7f0;
  pTVar2 = local_750;
  goto switchD_97ba39c8_caseD_0;
LAB_97ba5740:
  param_8 = puVar49[1];
  iVar57 = *(int *)(param_8 + 4);
  pcVar64 = " no such field in structure";
LAB_97ba5784:
  local_64 = (unsigned char *)0xa7b8374c;
  *(unsigned char *)(iVar57 + *(int *)(iVar57 + -0xc)) = *DAT_a7b7ba88;
  pcVar33 = *(char **)(param_8 + 4);
  pcVar31 = (char *)puVar49[-0xb];
LAB_97ba5548:
  TParseContext__error((int)param_1,pcVar31,pcVar64,pcVar33,"",pTVar37,iVar57,param_8);
  goto LAB_97ba5554;
}

/* yylex @ 0x97bac120 (4128 bytes) */
int yylex(param_1, param_2)
  unsigned char * param_1;
  void *param_2;
{
  int iVar1;
  byte *pbVar2;
  char *pcVar3;
  unsigned char * this;
  unsigned char * psVar4;
  long lVar5;
  unsigned char * pTVar6;
  void *this_00;
  undefined4 uVar7;
  int iVar8;
  uint uVar9;
  undefined *puVar10;
  byte *pbVar11;
  int iVar12;
  void *pvVar13;
  byte *pbVar14;
  double dVar15;
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
  pbVar11 = _yy_c_buf_p;
  iVar12 = _yy_start;
LAB_97bac214:
  puVar10 = &_yy_def;
  iVar8 = iVar12 << 1;
  do {
    uVar9 = (uint)(byte)(DAT_97c37983)[(uint)*_yy_c_buf_p * 4];
    if (*(short *)(&_yy_accept + iVar8) != 0) {
      _yy_last_accepting_cpos = _yy_c_buf_p;
      _yy_last_accepting_state = iVar12;
    }
    while (iVar1 = ((int)*(short *)(&_yy_base + iVar8) + uVar9) * 2,
          *(short *)(&_yy_chk + iVar1) != iVar12) {
      iVar12 = (int)*(short *)(&_yy_def + iVar8);
      iVar8 = iVar12 << 1;
      if (0x199 < iVar12) {
        uVar9 = (uint)(byte)(DAT_97c37d83)[uVar9 * 4];
      }
    }
    iVar12 = (int)*(short *)(&_yy_nxt + iVar1);
    _yy_c_buf_p = _yy_c_buf_p + 1;
    iVar8 = iVar12 * 2;
  } while (*(short *)(&_yy_base + iVar8) != 0x260);
LAB_97bac2e4:
  uVar9 = (uint)*(short *)(&_yy_accept + iVar8);
  pbVar14 = _yy_c_buf_p;
  if (uVar9 == 0) {
    uVar9 = (uint)*(short *)(&_yy_accept + _yy_last_accepting_state * 2);
    pbVar14 = _yy_last_accepting_cpos;
  }
  _yyleng = (int)pbVar14 - (int)pbVar11;
  _yy_hold_char = *pbVar14;
  _yytext = pbVar11;
  *pbVar14 = 0;
  _yy_c_buf_p = pbVar14;
LAB_97bac330:
  pcVar3 = _yylineno;
  pbVar2 = _yytext;
  if (0x93 < uVar9) {
    yy_fatal_error("fatal flex scanner internal error--no action found");
    goto switchD_97bac34c_caseD_1;
  }
  switch(uVar9) {
  case 0:
    *pbVar14 = _yy_hold_char;
    _yytext = pbVar11;
    iVar8 = _yy_last_accepting_state;
    _yy_c_buf_p = _yy_last_accepting_cpos;
LAB_97bad2c8:
    iVar8 = iVar8 << 1;
    pbVar11 = _yytext;
    goto LAB_97bac2e4;
  default:
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
    *(char **)param_1 = pcVar3;
    break;
  case 0x15:
    uVar7 = 0x12e;
    *(undefined4 *)(param_1 + 4) = 0;
    *(char **)param_1 = pcVar3;
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
    pbVar11 = _yytext;
    pTVar6 = (unsigned char *)GetGlobalPoolAllocator();
    this = (unsigned char *)TPoolAllocator__allocate(pTVar6,8);
    psVar4 = (unsigned char *)0x0;
    if (this != (unsigned char *)0x0) {
      local_70[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (this,(char *)pbVar11,(unsigned char *)local_70);
      psVar4 = this;
    }
    *(unsigned char **)(param_1 + 4) = psVar4;
    uVar7 = PaIdentOrType(psVar4,param_2,(unsigned char **)(param_1 + 8));
    break;
  case 0x57:
    *(char **)param_1 = _yylineno;
    lVar5 = _strtol((char *)_yytext,(char **)0x0,0);
    *(long *)(param_1 + 4) = lVar5;
    uVar7 = 0x12d;
    break;
  case 0x58:
    *(char **)param_1 = _yylineno;
    lVar5 = _strtol((char *)_yytext,(char **)0x0,0);
    *(long *)(param_1 + 4) = lVar5;
    uVar7 = 0x12d;
    break;
  case 0x59:
    *(char **)param_1 = _yylineno;
    TParseContext__error
              ((int)param_2,_yylineno,"Invalid Octal number.",(char *)_yytext,"","",uVar9 * 4,
               puVar10);
    TParseContext__recover(param_2);
    uVar7 = 0;
    break;
  case 0x5a:
    *(char **)param_1 = _yylineno;
    lVar5 = _strtol((char *)_yytext,(char **)0x0,0);
    *(long *)(param_1 + 4) = lVar5;
    uVar7 = 0x12d;
    break;
  case 0x5b:
    *(char **)param_1 = _yylineno;
    dVar15 = (double)((double (*)())_glp_strtod)(_yytext,0);
    uVar7 = 300;
    *(float *)(param_1 + 4) = (float)dVar15;
    break;
  case 0x5c:
    *(char **)param_1 = _yylineno;
    dVar15 = (double)((double (*)())_glp_strtod)(_yytext,0);
    uVar7 = 300;
    *(float *)(param_1 + 4) = (float)dVar15;
    break;
  case 0x5d:
    *(char **)param_1 = _yylineno;
    dVar15 = (double)((double (*)())_glp_strtod)(_yytext,0);
    uVar7 = 300;
    *(float *)(param_1 + 4) = (float)dVar15;
    break;
  case 0x5e:
    iVar12 = PaParseComment((int *)param_1,param_2);
    uVar7 = 0;
    if (iVar12 != 0) goto switchD_97bac34c_caseD_1;
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
    pbVar11 = _yytext;
    pTVar6 = (unsigned char *)GetGlobalPoolAllocator();
    this_00 = (void *)TPoolAllocator__allocate(pTVar6,8);
    pvVar13 = (void *)0x0;
    if (this_00 != (void *)0x0) {
      local_60[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (this_00,(char *)pbVar11,(unsigned char *)local_60);
      pvVar13 = this_00;
    }
    *(void **)(param_1 + 4) = pvVar13;
    uVar7 = 0x12f;
    break;
  case 0x8f:
    pvVar13 = *(void **)((int)param_2 + 8);
    __ZN13TInfoSinkBase6appendEPKc(pvVar13,"FLEX: Unknown char ");
    __ZN13TInfoSinkBase6appendEPKc(pvVar13,(char *)_yytext);
    __ZN13TInfoSinkBase6appendEPKc(pvVar13,"\n");
    uVar7 = 0;
    break;
  case 0x90:
    _fwrite(_yytext,_yyleng,1,_yyout);
    goto switchD_97bac34c_caseD_1;
  case 0x91:
    *pbVar14 = _yy_hold_char;
    if (*(int *)(_yy_current_buffer + 0x24) == 0) {
      _yy_n_chars = *(int *)(_yy_current_buffer + 0x10);
      *(unsigned char **)_yy_current_buffer = _yyin;
      *(int *)(_yy_current_buffer + 0x24) = 1;
    }
    if (_yy_c_buf_p <= (byte *)(*(int *)(_yy_current_buffer + 4) + _yy_n_chars)) {
      _yy_c_buf_p = _yytext + (int)(pbVar14 + (-1 - (int)pbVar2));
      iVar8 = ((int (*)())yy_get_previous_state)();
      iVar12 = ((int (*)())yy_try_NUL_trans)(iVar8);
      if (iVar12 == 0) goto LAB_97bad2c8;
      _yy_c_buf_p = _yy_c_buf_p + 1;
      pbVar11 = _yytext;
      goto LAB_97bac214;
    }
    iVar12 = ((int (*)())yy_get_next_buffer)();
    if (iVar12 == 1) goto LAB_97bad2f8;
    if (1 < iVar12) {
      if (iVar12 == 2) goto LAB_97bad344;
      goto switchD_97bac34c_caseD_1;
    }
    if (iVar12 != 0) goto switchD_97bac34c_caseD_1;
    _yy_c_buf_p = _yytext + (int)(pbVar14 + (-1 - (int)pbVar2));
    iVar12 = ((int (*)())yy_get_previous_state)();
    pbVar11 = _yytext;
    goto LAB_97bac214;
  case 0x92:
  case 0x93:
    *(undefined4 *)((int)param_2 + 0x60) = 1;
    yy_delete_buffer(_yy_current_buffer);
    uVar7 = 0;
  }
  return uVar7;
LAB_97bad2f8:
  uVar9 = _yy_start - 1;
  _yy_did_buffer_switch_on_eof = 0;
  _yy_c_buf_p = _yytext;
  uVar9 = ((int)uVar9 >> 1) + (uint)((int)uVar9 < 0 && (uVar9 & 1) != 0) + 0x92;
  goto LAB_97bac330;
LAB_97bad344:
  _yy_c_buf_p = (byte *)(*(int *)(_yy_current_buffer + 4) + _yy_n_chars);
  iVar8 = ((int (*)())yy_get_previous_state)();
  iVar8 = iVar8 << 1;
  pbVar11 = _yytext;
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
  return iVar2;
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
    yy_fatal_error("out of dynamic memory in yy_create_buffer()");
  }
  *(int *)(pyVar1 + 0xc) = param_2;
  iVar2 = yy_flex_alloc(param_2 + 2);
  *(int *)(pyVar1 + 4) = iVar2;
  if (iVar2 == 0) {
    yy_fatal_error("out of dynamic memory in yy_create_buffer()");
  }
  *(undefined4 *)(pyVar1 + 0x14) = 1;
  yy_init_buffer(pyVar1,param_1);
  return pyVar1;
}

