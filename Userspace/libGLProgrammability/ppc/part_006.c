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
    iVar2 = (**(code **)(*param_1 + 8))(param_1);
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
      piVar3 = (int *)(**(code **)(*piVar3 + 0x10))(piVar3);
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
  int *a0;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (a0 = (int *)(**(code **)(*param_1 + 8))(param_1), a0 != (int *)0x0)) {
    uVar1 = (**(code **)(*a0 + 0x1c))(a0);
  }
  return uVar1;
}

/* _ShGetShaderLocalParamRemapTable @ 0x97ba1dc0 (92 bytes) */
int _ShGetShaderLocalParamRemapTable(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  unsigned char * this;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(param_1), this != (unsigned char *)0x0
     )) {
    uVar1 = TGenericLinker__getShaderLocalParamRemapTable(this,param_2);
  }
  return uVar1;
}

/* _ShGetNumShaderLocalParams @ 0x97ba1e1c (92 bytes) */
int _ShGetNumShaderLocalParams(param_1, param_2)
  int *param_1;
  undefined4 param_2;
{
  unsigned char * this;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(param_1), this != (unsigned char *)0x0
     )) {
    uVar1 = TGenericLinker__getNumShaderLocalParams(this,param_2);
  }
  return uVar1;
}

/* _ShAttributeBindingRequest @ 0x97ba1e78 (104 bytes) */
int _ShAttributeBindingRequest(param_1, param_2, param_3)
  int *param_1;
  ulong param_2;
  char *param_3;
{
  unsigned char * this;
  
  if ((param_1 != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(param_1), this != (unsigned char *)0x0
     )) {
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
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(param_1), iVar1 != 0)) {
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
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(param_1), iVar1 != 0)) {
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
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(param_1), iVar1 != 0)) {
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
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(param_1), iVar1 != 0)) {
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
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(param_1), iVar1 != 0)) {
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
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(param_1), this != (unsigned char *)0x0
     )) {
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
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(param_1), this != (unsigned char *)0x0
     )) {
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
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(param_1), this != (unsigned char *)0x0
     )) {
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
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(param_1), iVar1 != 0)) {
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
  if ((param_1 != (int *)0x0) && (iVar1 = (**(code **)(*param_1 + 0xc))(param_1), iVar1 != 0)) {
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
  unsigned char * this;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(param_1), this != (unsigned char *)0x0
     )) {
    uVar1 = TGenericLinker__getPPStreamManager(this,param_2);
  }
  return uVar1;
}

/* _ShGetLinkerStats @ 0x97ba23a0 (84 bytes) */
int _ShGetLinkerStats(param_1)
  int *param_1;
{
  unsigned char * this;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(param_1), this != (unsigned char *)0x0
     )) {
    uVar1 = TGenericLinker__getStatsString(this);
  }
  return uVar1;
}

/* _ShGetCompilerStats @ 0x97ba23f4 (96 bytes) */
int _ShGetCompilerStats(param_1)
  int *param_1;
{
  int *a0;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (a0 = (int *)(**(code **)(*param_1 + 8))(param_1), a0 != (int *)0x0)) {
    uVar1 = (**(code **)(*a0 + 0x24))(a0);
  }
  return uVar1;
}

/* _ShGetLinkerPPStream @ 0x97ba2454 (84 bytes) */
int _ShGetLinkerPPStream(param_1)
  int *param_1;
{
  unsigned char * this;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(param_1), this != (unsigned char *)0x0
     )) {
    uVar1 = TGenericLinker__getPPStreamString(this);
  }
  return uVar1;
}

/* _ShGetCompilerPPStream @ 0x97ba24a8 (96 bytes) */
int _ShGetCompilerPPStream(param_1)
  int *param_1;
{
  int *a0;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (a0 = (int *)(**(code **)(*param_1 + 8))(param_1), a0 != (int *)0x0)) {
    uVar1 = (**(code **)(*a0 + 0x28))(a0);
  }
  return uVar1;
}

/* _ShGetLinkerShaderToProgramString @ 0x97ba2508 (84 bytes) */
int _ShGetLinkerShaderToProgramString(param_1)
  int *param_1;
{
  unsigned char * this;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(param_1), this != (unsigned char *)0x0
     )) {
    uVar1 = TGenericLinker__getShaderToProgramString(this);
  }
  return uVar1;
}

/* _ShGetCompilerShaderToProgramString @ 0x97ba255c (96 bytes) */
int _ShGetCompilerShaderToProgramString(param_1)
  int *param_1;
{
  int *a0;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (a0 = (int *)(**(code **)(*param_1 + 8))(param_1), a0 != (int *)0x0)) {
    uVar1 = (**(code **)(*a0 + 0x2c))(a0);
  }
  return uVar1;
}

/* _ShGetLinkerBindingTable @ 0x97ba25bc (84 bytes) */
int _ShGetLinkerBindingTable(param_1)
  int *param_1;
{
  unsigned char * this;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (this = (unsigned char *)(**(code **)(*param_1 + 0xc))(param_1), this != (unsigned char *)0x0
     )) {
    uVar1 = TGenericLinker__getTableString(this);
  }
  return uVar1;
}

/* _ShGetCompilerSymbolTable @ 0x97ba2610 (96 bytes) */
int _ShGetCompilerSymbolTable(param_1)
  int *param_1;
{
  int *a0;
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) &&
     (a0 = (int *)(**(code **)(*param_1 + 8))(param_1), a0 != (int *)0x0)) {
    uVar1 = (**(code **)(*a0 + 0x30))(a0);
  }
  return uVar1;
}

/* TType__buildMangledName @ 0x97ba2670 (688 bytes) */
int TType__buildMangledName(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  ulong uVar2;
  undefined4 a1;
  undefined4 uVar3;
  char *pcVar4;
  uint uVar5;
  char acStack_20 [16];
  
  iVar1 = (**(code **)(*(int *)this + 0x34))(this);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)this + 0x3c))(this,a1);
    if (iVar1 != 0) {
      uVar3 = 0x76;
      goto LAB_97ba26e0;
    }
  }
  else {
    uVar3 = 0x6d;
LAB_97ba26e0:
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(param_2,1,uVar3);
  }
  switch(*(uint *)(this + 0x24) >> 0x13 & 0x3f) {
  default:
    goto switchD_97ba270c_caseD_0;
  case 1:
    uVar3 = 0x66;
    goto LAB_97ba2778;
  case 2:
    uVar3 = 0x69;
    goto LAB_97ba2778;
  case 3:
    uVar3 = 0x62;
LAB_97ba2778:
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(param_2,1,uVar3);
    goto switchD_97ba270c_caseD_0;
  case 5:
    pcVar4 = "s1";
    uVar2 = _strlen("s1");
    break;
  case 6:
    pcVar4 = "s2";
    uVar2 = _strlen("s2");
    break;
  case 7:
    pcVar4 = "s3";
    uVar2 = _strlen("s3");
    break;
  case 8:
    pcVar4 = "sC";
    uVar2 = _strlen("sC");
    break;
  case 9:
    pcVar4 = "sS1";
    uVar2 = _strlen("sS1");
    break;
  case 10:
    pcVar4 = "sS2";
    uVar2 = _strlen("sS2");
    break;
  case 0xb:
    pcVar4 = "sR2";
    uVar2 = _strlen("sR2");
    break;
  case 0xc:
    pcVar4 = "sSR2";
    uVar2 = _strlen("sSR2");
    break;
  case 0xe:
    uVar2 = _strlen("struct-");
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm(param_2,"struct-",uVar2);
    if (*(unsigned char **)(this + 0x10) != (unsigned char *)0x0) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendERKS3_(param_2,*(unsigned char **)(this + 0x10))
      ;
    }
    for (uVar5 = 0;
        uVar5 < (uint)(*(int *)(*(int *)(this + 8) + 8) - *(int *)(*(int *)(this + 8) + 4) >> 3);
        uVar5 = uVar5 + 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(param_2,1,0x2d);
      ((int (*)())TType__buildMangledName)(*(unsigned char **)(*(int *)(*(int *)(this + 8) + 4) + uVar5 * 8),param_2);
    }
    goto switchD_97ba270c_caseD_0;
  }
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm(param_2,pcVar4,uVar2);
switchD_97ba270c_caseD_0:
  uVar3 = (**(code **)(*(int *)this + 0x2c))(this);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(param_2,1,(int)(char)((char)uVar3 + '0'))
  ;
  iVar1 = (**(code **)(*(int *)this + 0x38))(this);
  if (iVar1 != 0) {
    _sprintf(acStack_20,"%d",*(undefined4 *)(this + 4));
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(param_2,1,0x5b);
    uVar2 = _strlen(acStack_20);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEPKcm(param_2,acStack_20,uVar2);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(param_2,1,0x5d);
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
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int a6;
  int local_20 [4];
  
  a6 = *(int *)(this + 4);
  local_20[0] = *(int *)(a6 + 8);
  while (local_20[0] != a6) {
    (**(code **)(**(int **)(local_20[0] + 0x18) + 0x14))
              (*(int **)(local_20[0] + 0x18),param_2,in_r5,in_r6,in_r7,in_r8,a6);
    std___Rb_tree_base_iterator___M_increment((unsigned char *)local_20);
    a6 = *(int *)(this + 4);
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
    piVar3 = *(int **)(iVar4 + 4);
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 4))(piVar3);
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
  ((int (*)())__ZN17TSymbolTableLevelD4Ev)(this,0);
  return;
}

/* __ZN17TSymbolTableLevelD1Ev @ 0x97ba2d98 (8 bytes) */
int __ZN17TSymbolTableLevelD1Ev(this)
  void *this;
{
  ((int (*)())__ZN17TSymbolTableLevelD4Ev)(this,2);
  return;
}

/* __ZN17TSymbolTableLevelD4Ev @ 0x97ba2da0 (184 bytes) */
int __ZN17TSymbolTableLevelD4Ev(this, param_2)
  void *this;
  undefined4 param_2;
{
  int *a0;
  undefined4 extraout_r4;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int local_30 [4];
  int local_20;
  
  local_20 = *(int *)((int)this + 4);
  local_30[0] = *(int *)(local_20 + 8);
  if (local_30[0] != local_20) {
    do {
      a0 = *(int **)(local_30[0] + 0x18);
      if (a0 != (int *)0x0) {
        (**(code **)(*a0 + 4))(a0,param_2,in_r5,in_r6,in_r7,in_r8,local_20);
      }
      std___Rb_tree_base_iterator___M_increment((unsigned char *)local_30);
      local_20 = *(int *)((int)this + 4);
      param_2 = extraout_r4;
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
  unsigned char * this;
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
      iVar1 = (**(code **)(**(int **)(local_40[0] + 0x18) + 0xc))(*(int **)(local_40[0] + 0x18));
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
                ((unsigned char *)((int)this + 0xc),
                 *(undefined4 *)((int)this + 0x14),&local_60);
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
  undefined4 *in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int a6;
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
  a6 = puVar4[1];
  *(int *)(a6 + 0xc) = a6;
  local_80 = *(int *)(this + 4);
  local_90[0] = *(int *)(local_80 + 8);
  if (local_90[0] != local_80) {
    do {
      piVar6 = (int *)(**(code **)(**(int **)(local_90[0] + 0x18) + 0x18))
                                (*(int **)(local_90[0] + 0x18),param_2,in_r5,in_r6,in_r7,in_r8,a6);
      local_6c = 0;
      psVar7 = (unsigned char *)(**(code **)(*piVar6 + 8))(piVar6);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_50,psVar7);
      in_r5 = &local_50;
      local_48 = piVar6;
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_60,puVar4,&local_50);
      local_70 = local_60;
      piVar6 = (int *)(local_4c + -4);
      local_6c = local_5c;
      local_40[0] = local_50;
      do {
        iVar2 = *piVar6;
        a6 = iVar2 + -1;
        if (in_RESERVE != '\0') {
          iVar1 = storeWordConditionalIndexed(a6,0,piVar6);
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
  undefined4 *puVar4;
  uint uVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined4 *local_60;
  int local_5c;
  undefined4 local_30 [5];
  
  puVar2 = PTR__S_force_new_a7b7c0e8;
  local_60 = (undefined4 *)0x0;
  if (*(int *)PTR__S_force_new_a7b7c0e8 == 0) {
    iVar3 = _getenv("GLIBCPP_FORCE_NEW");
    if (iVar3 == 0) {
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
    _pthread_mutex_lock(PTR__S_node_allocator_lock_a7b7c0e0);
    puVar4 = *(undefined4 **)(puVar2 + 8);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)std____default_alloc_template_true_0____S_refill(0x18);
    }
    else {
      *(undefined4 *)(puVar2 + 8) = *puVar4;
    }
    if (puVar4 == (undefined4 *)0x0) {
      std____throw_bad_alloc();
    }
    _pthread_mutex_unlock(PTR__S_node_allocator_lock_a7b7c0e0);
  }
  else {
    puVar4 = operator_new(0x18);
  }
  local_5c = 0;
  *puVar4 = 0;
  puVar4[1] = 0;
  puVar4[2] = puVar4;
  puVar4[3] = puVar4;
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_2 + 0xc);
  local_60 = puVar4;
  for (uVar5 = 0; uVar5 < (uint)(*(int *)(param_2 + 4) - *(int *)param_2 >> 2); uVar5 = uVar5 + 1) {
    local_30[0] = ((int (*)())TSymbolTableLevel__clone)(*(unsigned char **)(*(int *)param_2 + uVar5 * 4),(unsigned char *)&local_60);
    puVar4 = *(undefined4 **)(this + 4);
    if (puVar4 == *(undefined4 **)(this + 8)) {
      std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                ((unsigned char *)this,puVar4,
                 local_30);
    }
    else {
      iVar3 = 0;
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = local_30[0];
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
  char *param_3;
  char *param_4;
  char *param_5;
  undefined4 param_6;
  undefined *param_7;
  uint param_8;
{
  short sVar1;
  uint uVar2;
  unsigned char * pTVar3;
  undefined4 *puVar4;
  undefined4 yy_outargs[0x14];
  undefined *puVar5;
  int iVar6;
  unsigned char * pTVar7;
  unsigned char * pTVar8;
  unsigned char * this;
  unsigned char * pcVar9;
  unsigned char * a0;
  unsigned char * psVar10;
  unsigned char * paVar11;
  unsigned char * pTVar12;
  void *pvVar13;
  unsigned char * pvVar14;
  unsigned char * pTVar15;
  undefined4 uVar16;
  unsigned char * pTVar17;
  undefined4 *puVar18;
  undefined4 *puVar19;
  unsigned char * pTVar20;
  int *a0_00;
  unsigned char * psVar21;
  unsigned char * pTVar22;
  void *pvVar23;
  unsigned char * this_00;
  undefined4 extraout_r4;
  undefined4 extraout_r4_00;
  undefined4 extraout_r4_01;
  undefined4 extraout_r4_02;
  undefined4 a1;
  undefined4 extraout_r4_03;
  undefined4 extraout_r4_04;
  undefined4 extraout_r4_05;
  undefined4 a1_00;
  undefined4 a1_01;
  undefined4 a1_02;
  undefined4 a1_03;
  undefined4 a1_04;
  undefined4 a1_05;
  undefined4 extraout_r4_06;
  undefined4 extraout_r4_07;
  undefined4 a1_06;
  undefined4 extraout_r4_08;
  undefined4 extraout_r4_09;
  int *extraout_r4_10;
  undefined4 a1_07;
  int *extraout_r4_11;
  unsigned char ** ppTVar24;
  undefined4 extraout_r4_12;
  undefined4 extraout_r4_13;
  undefined4 a1_08;
  undefined4 extraout_r4_14;
  undefined4 extraout_r4_15;
  undefined4 a1_09;
  undefined4 a1_10;
  undefined4 a1_11;
  uint *puVar25;
  undefined4 a1_12;
  int iVar26;
  undefined4 extraout_r4_16;
  undefined4 extraout_r4_17;
  undefined4 extraout_r4_18;
  unsigned char * pTVar27;
  uint uVar28;
  char *pcVar29;
  int iVar30;
  int a3;
  char *a4;
  unsigned char * pTVar31;
  int a4_00;
  unsigned char * pTVar32;
  unsigned char * pTVar33;
  int a5;
  unsigned char * pTVar34;
  undefined **ppuVar35;
  bool bVar37;
  int iVar36;
  int iVar38;
  int iVar39;
  code *pcVar40;
  unsigned char * pTVar41;
  unsigned char * pTVar42;
  int iVar43;
  int iVar44;
  unsigned char * pTVar45;
  unsigned char * pTVar46;
  unsigned char * pTVar47;
  int iVar48;
  undefined4 uVar49;
  int *piVar50;
  unsigned char * pvVar51;
  unsigned char * pTVar52;
  uint uVar53;
  int iVar54;
  int iVar55;
  unsigned char * pTVar56;
  uint uVar57;
  uint uVar58;
  unsigned char * pTVar59;
  int iVar60;
  int *piVar61;
  char *pcVar62;
  char in_RESERVE;
  byte in_cr0;
  ulonglong uVar63;
  undefined8 uVar64;
  unsigned char aTStack_2ca2 [2];
  unsigned char local_2ca0 [400];
  unsigned char aTStack_2b10 [8800];
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
  unsigned char * local_660;
  unsigned char * local_650 [4];
  uint local_640;
  uint local_630;
  uint local_620;
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
  uint local_2a0;
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
  undefined4 local_180;
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
  
  puVar4 = yy_outargs;
  pTVar56 = aTStack_2b10;
  pTVar41 = (unsigned char *)0xc8;
  iVar48 = 0;
  iVar43 = 0;
  iVar44 = -2;
  pTVar46 = aTStack_2ca2;
  local_60 = (unsigned char *)0x190;
  pTVar42 = pTVar56;
  pTVar45 = local_2ca0;
LAB_97ba3784:
  do {
    pTVar46 = pTVar46 + 2;
    *(short *)pTVar46 = (short)iVar48;
    pTVar3 = pTVar42;
    pTVar7 = pTVar45;
    if (pTVar45 + (int)local_60 + -2 <= pTVar46) {
      iVar55 = ((int)pTVar46 - (int)pTVar45 >> 1) + 1;
      if (9999 < (int)pTVar41) {
        yyerror("parser stack overflow",pTVar45,param_3,param_4,param_5,local_60,param_7,param_8);
        return 2;
      }
      pTVar41 = local_60;
      if (10000 < (int)local_60) {
        pTVar41 = (unsigned char *)0x2710;
      }
      local_60 = (unsigned char *)((int)pTVar41 * 2);
      iVar54 = iVar55 * 2;
      param_3 = (char *)(iVar55 * 0x2c);
      pTVar7 = (unsigned char *)__builtin_alloca((uint)local_60 + 0x40);
      _memcpy(pTVar7,pTVar45,iVar54);
      pTVar46 = pTVar7 + iVar54 + -2;
      pTVar3 = (unsigned char *)__builtin_alloca((int)pTVar41 * 0x2c + 0x40);
      pTVar56 = pTVar3 + (int)param_3;
      _memcpy(pTVar3,pTVar42,param_3);
      pTVar56 = pTVar56 + -0x2c;
      param_2 = extraout_r4;
      if (pTVar7 + (int)local_60 + -2 <= pTVar46) {
        return 1;
      }
    }
    uVar63 = CONCAT44(iVar44,param_2);
    iVar55 = iVar48 * 2;
    sVar1 = (&_yypact)[iVar48];
    pTVar33 = local_60;
    pTVar42 = pTVar3;
    pTVar45 = pTVar7;
    if (sVar1 == -0x8000) {
LAB_97ba3958:
      uVar57 = (uint)*(short *)(&_yydefact + iVar55);
      if (uVar57 != 0) goto LAB_97ba3970;
LAB_97bac03c:
      if (iVar43 == 0) {
        yyerror("parse error",param_2,param_3,param_4,param_5,pTVar33,param_7,param_8);
        param_2 = extraout_r4_17;
      }
LAB_97bac050:
      if (iVar43 == 3) {
        if (iVar44 == 0) {
          return 1;
        }
        iVar44 = -2;
      }
      iVar43 = 3;
      do {
        if (((*(short *)((int)&_yypact + iVar55) != -0x8000) &&
            (uVar57 = (int)*(short *)((int)&_yypact + iVar55) + 1, uVar57 < 0x4f0)) &&
           (param_7 = (undefined *)(uVar57 * 2), *(short *)(&_yycheck + (int)param_7) == 1)) {
          iVar48 = (int)*(short *)(&_yytable + (int)param_7);
          if (iVar48 < 0) {
            if (iVar48 != -0x8000) goto LAB_97bac0d0;
          }
          else if (iVar48 != 0) {
            if (iVar48 == 0x14d) {
              return 0;
            }
            pTVar56 = pTVar56 + 0x2c;
            param_3 = (char *)0x2c;
            _memcpy(pTVar56,aYStack_8b0,0x2c);
            param_2 = extraout_r4_18;
            goto LAB_97ba3784;
          }
        }
        if (pTVar46 == pTVar7) {
          return 1;
        }
        pTVar46 = pTVar46 + -2;
        pTVar56 = pTVar56 + -0x2c;
        iVar55 = (int)*(short *)pTVar46 << 1;
      } while( true );
    }
    if (iVar44 == -2) {
      uVar63 = ((int (*)())yylex)(aYStack_8b0,param_1);
    }
    iVar44 = (int)(uVar63 >> 0x20);
    param_2 = (undefined4)uVar63;
    if ((longlong)uVar63 < 0x100000000) {
      iVar48 = 0;
      iVar44 = 0;
    }
    else {
      iVar48 = 0xa9;
      if (uVar63 < 0x15d00000000) {
        iVar48 = (int)(char)(&_yytranslate)[iVar44];
      }
    }
    uVar57 = sVar1 + iVar48;
    if ((0x4ef < uVar57) ||
       (param_7 = (undefined *)(uVar57 * 2), *(short *)(&_yycheck + (int)param_7) != iVar48))
    goto LAB_97ba3958;
    iVar48 = (int)*(short *)(&_yytable + (int)param_7);
    if (iVar48 < 0) {
      if (iVar48 != -0x8000) break;
      goto LAB_97bac03c;
    }
    if (iVar48 == 0) goto LAB_97bac03c;
    if (iVar48 == 0x14d) {
      return 0;
    }
    if (iVar44 != 0) {
      iVar44 = -2;
    }
    pTVar56 = pTVar56 + 0x2c;
    param_3 = (char *)0x2c;
    _memcpy(pTVar56,aYStack_8b0,0x2c);
    param_2 = extraout_r4_00;
    if (iVar43 != 0) {
      iVar43 = iVar43 + -1;
    }
  } while( true );
LAB_97bac0d0:
  uVar57 = -iVar48;
LAB_97ba3970:
  local_6c = uVar57 * 2;
  iVar48 = (int)*(short *)(&_yyr2 + local_6c);
  if (0 < iVar48) {
    param_3 = (char *)0x2c;
    _memcpy(&local_880,pTVar56 + (1 - iVar48) * 0x2c,0x2c);
    param_2 = extraout_r4_01;
  }
  pTVar3 = local_878;
  pTVar31 = local_7f0;
  pTVar32 = local_750[0];
  if (0xd7 < uVar57) goto switchD_97ba39c8_caseD_0;
  pTVar34 = (unsigned char *)(uVar57 * 4);
  pTVar59 = (unsigned char *)param_4;
  switch(uVar57) {
  case 0:
    break;
  case 1:
    pTVar3 = *(unsigned char **)(pTVar56 + 8);
    if (pTVar3 == (unsigned char *)0x0) {
      uVar57 = *(uint *)(pTVar56 + 4);
      local_64 = (unsigned char *)0xa7b8374c;
      iVar55 = *(int *)(uVar57 + 4);
      a4 = "";
      pcVar62 = "undeclared identifier";
      *(unsigned char *)(iVar55 + *(int *)(iVar55 + -0xc)) = *DAT_a7b7ba88;
      pcVar29 = *(char **)(uVar57 + 4);
      TParseContext__error
                ((int)param_1,*(char **)pTVar56,"undeclared identifier",pcVar29,"",pTVar33,iVar55,
                 uVar57);
      TParseContext__recover(param_1);
      local_5c = (unsigned char *)0xa7b8374c;
      local_82c = (unsigned char *)((uint)local_82c & 0x1ff | 0x80800);
      local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      local_84c = pTVar3;
      local_848 = pTVar3;
      local_844 = pTVar3;
      local_840 = pTVar3;
      local_83c = pTVar3;
      local_838 = pTVar3;
      local_834 = pTVar3;
      local_830 = pTVar3;
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      uVar64 = TPoolAllocator__allocate(pTVar17,0x40);
      pTVar7 = (unsigned char *)((ulonglong)uVar64 >> 0x20);
      uVar57 = *(uint *)(pTVar56 + 4);
      puVar5 = PTR_vtable_a7b7c0b4 + 8;
      *(undefined ***)(pTVar7 + 0xc) = &PTR___ZN5TTypeD1Ev_a7b7d640;
      *(uint *)(pTVar7 + 4) = uVar57;
      *(undefined **)pTVar7 = puVar5;
      *(unsigned char **)(pTVar7 + 0x10) = local_84c;
      *(unsigned char **)(pTVar7 + 0x14) = local_848;
      *(unsigned char **)(pTVar7 + 0x18) = local_844;
      *(unsigned char **)(pTVar7 + 0x1c) = local_840;
      *(unsigned char **)(pTVar7 + 0x20) = local_83c;
      *(unsigned char **)(pTVar7 + 0x24) = local_838;
      *(unsigned char **)(pTVar7 + 0x28) = local_834;
      *(unsigned char **)(pTVar7 + 0x2c) = local_830;
      uVar2 = *(uint *)(pTVar7 + 0x30);
      uVar28 = (uint)local_82c & 0xfe000000;
      *(uint *)(pTVar7 + 0x30) = uVar28 | uVar2 & 0x1ffffff;
      uVar53 = ((uint)local_82c >> 0x13 & 0x3f) << 0x13;
      *(uint *)(pTVar7 + 0x30) = uVar53 | uVar28 | uVar2 & 0x7ffff;
      uVar57 = (uint)local_82c & 0x7f800;
      *(uint *)(pTVar7 + 0x30) = uVar57 | uVar53 | uVar28 | uVar2 & 0x7ff;
      uVar58 = ((uint)local_82c >> 10 & 1) << 10;
      *(uint *)(pTVar7 + 0x30) = uVar58 | uVar57 | uVar53 | uVar28 | uVar2 & 0x3ff;
      *(uint *)(pTVar7 + 0x30) =
           ((uint)local_82c >> 9 & 1) << 9 | uVar58 | uVar57 | uVar53 | uVar28 | uVar2 & 0x1ff;
      *(uint *)(pTVar7 + 0x34) = 0;
      *(uint *)(pTVar7 + 0x38) = 0;
      *(uint *)(pTVar7 + 0x3c) = 0;
      piVar61 = *(int **)((int)param_1 + 4);
      iVar55 = piVar61[3];
      piVar61[3] = iVar55 + 1U;
      *(uint *)(pTVar7 + 8) = iVar55 + 1U;
      uVar16 = *(undefined4 *)(*piVar61 + ((piVar61[1] - *piVar61 & 0xfffffffcU) - 4));
      local_81c = pTVar3;
      psVar21 = (unsigned char *)
                (**(code **)(*(uint *)pTVar7 + 8))
                          (pTVar7,(int)uVar64,pcVar62,pcVar29,a4,pTVar33,piVar61);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_800,psVar21);
      local_7f8 = pTVar7;
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_810,uVar16,&local_800);
      local_820 = local_810;
      pTVar3 = local_7fc + -4;
      local_81c = local_80c;
      local_7f0 = local_800;
      do {
        uVar57 = *(uint *)pTVar3;
        if (in_RESERVE != '\0') {
          uVar28 = storeWordConditionalIndexed(uVar57 - 1,0,pTVar3);
          *(uint *)pTVar3 = uVar28;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if ((int)uVar57 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(local_7fc + -0xc),&local_7f0);
      }
      local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      pTVar3 = pTVar7;
    }
    else {
      iVar55 = (**(code **)(*(unsigned char **)pTVar3 + 0x10))(pTVar3);
      if (iVar55 == 0) {
        uVar57 = *(uint *)(pTVar56 + 4);
        local_64 = (unsigned char *)0xa7b8374c;
        iVar55 = *(int *)(uVar57 + 4);
        *(unsigned char *)(iVar55 + *(int *)(iVar55 + -0xc)) = *DAT_a7b7ba88;
        TParseContext__error
                  ((int)param_1,*(char **)pTVar56,"variable expected",*(char **)(uVar57 + 4),"",
                   pTVar33,iVar55,uVar57);
        TParseContext__recover(param_1);
      }
    }
    param_4 = (char *)(pTVar3 + 0xc);
    iVar55 = (**(code **)(*(uint *)(pTVar3 + 0xc) + 0x24))(param_4);
    if (iVar55 != 2) {
      param_5 = *(char **)pTVar56;
      pTVar3 = (unsigned char *)
               TIntermediate__addSymbol
                         (*(unsigned char **)param_1,*(uint *)(pTVar3 + 8),*(unsigned char **)(pTVar3 + 4),
                          (unsigned char *)param_4,(int)param_5);
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
      break;
    }
    local_84c = *(unsigned char **)(pTVar3 + 0x10);
    local_844 = *(unsigned char **)(pTVar3 + 0x18);
    local_840 = *(unsigned char **)(pTVar3 + 0x1c);
    local_848 = *(unsigned char **)(pTVar3 + 0x14);
    local_83c = *(unsigned char **)(pTVar3 + 0x20);
    local_838 = *(unsigned char **)(pTVar3 + 0x24);
    param_5 = *(char **)(pTVar3 + 0x28);
    local_830 = *(unsigned char **)(pTVar3 + 0x2c);
    pcVar9 = *(unsigned char **)(pTVar3 + 0x38);
    local_82c = (unsigned char *)
                ((*(uint *)(pTVar3 + 0x30) >> 9 & 1) << 9 |
                (*(uint *)(pTVar3 + 0x30) >> 10 & 1) << 10 |
                *(uint *)(pTVar3 + 0x30) & 0x7f800 |
                (*(uint *)(pTVar3 + 0x30) >> 0x13 & 0x3f) << 0x13 |
                *(uint *)(pTVar3 + 0x30) & 0xfe000000 | (uint)local_82c & 0x1ff);
    local_834 = (unsigned char *)param_5;
LAB_97ba4158:
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    pTVar15 = *(unsigned char **)param_1;
    param_4 = *(char **)pTVar56;
    goto LAB_97ba7d0c;
  default:
    goto switchD_97ba39c8_caseD_2;
  case 3:
    uVar57 = (int)*(uint *)(pTVar56 + 4) >> 0x1f;
    iVar55 = (uVar57 ^ *(uint *)(pTVar56 + 4)) - uVar57;
    if (0xffff < iVar55) {
      param_5 = "";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," integer constant overflow","","",uVar57,iVar55,
                 param_8);
      TParseContext__recover(param_1);
    }
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pcVar9 = (unsigned char *)TPoolAllocator__allocate(pTVar17,4);
    *(uint *)pcVar9 = *(uint *)(pTVar56 + 4);
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
    *(uint *)pcVar9 = *(uint *)(pTVar56 + 4);
    uVar57 = (uint)local_82c & 0x7ff | 0x4080000;
    goto LAB_97ba41e8;
  case 5:
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pcVar9 = (unsigned char *)TPoolAllocator__allocate(pTVar17,4);
    *(uint *)pcVar9 = *(uint *)(pTVar56 + 4);
    local_5c = (unsigned char *)0xa7b8374c;
    uVar57 = (uint)local_82c & 0x1807ff | 0x4180000;
LAB_97ba41e8:
    local_82c = (unsigned char *)(uVar57 & 0xfffff9ff | 0x800);
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
    iVar55 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x54))
                       (*(int **)(pTVar56 + -0x7c),param_2,param_3,param_4,param_5,pTVar33);
    if (((iVar55 == 0) &&
        (iVar55 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x50))(*(int **)(pTVar56 + -0x7c)),
        iVar55 == 0)) &&
       (iVar55 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x58))(*(int **)(pTVar56 + -0x7c)),
       iVar55 == 0)) {
      iVar55 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x28))(*(int **)(pTVar56 + -0x7c));
      if (iVar55 == 0) {
        pcVar62 = *(char **)(pTVar56 + -0x58);
        param_4 = "expression";
      }
      else {
        local_64 = (unsigned char *)0xa7b8374c;
        piVar61 = (int *)(**(code **)(**(int **)(pTVar56 + -0x7c) + 0x28))
                                   (*(int **)(pTVar56 + -0x7c));
        iVar55 = (**(code **)(*piVar61 + 0x60))(piVar61);
        pTVar34 = *(unsigned char **)(iVar55 + 4);
        pTVar34[*(uint *)(pTVar34 + -0xc)] = **(unsigned char **)(local_64 + -0x7cc4);
        param_4 = *(char **)(iVar55 + 4);
        pcVar62 = *(char **)(pTVar56 + -0x58);
        pTVar33 = local_64;
      }
      param_3 = " left of \'[\' is not of type array, matrix, or vector ";
      param_5 = "";
      TParseContext__error
                ((int)param_1,pcVar62," left of \'[\' is not of type array, matrix, or vector ",
                 param_4,"",pTVar33,pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    bVar37 = false;
    (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x38))(&local_850,*(int **)(pTVar56 + -0x7c));
    if ((((uint)local_82c >> 0x19 == 2) &&
        (iVar55 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x54))(*(int **)(pTVar56 + -0x7c)),
        iVar55 == 0)) &&
       (iVar55 = (**(code **)(**(int **)(pTVar56 + -0x24) + 0x44))(*(int **)(pTVar56 + -0x24)),
       iVar55 == 2)) {
      bVar37 = true;
    }
    local_5c = (unsigned char *)0xa7b8374c;
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    if (bVar37) {
      iVar55 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x58))(*(int **)(pTVar56 + -0x7c));
      if (iVar55 == 0) {
        iVar55 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x50))(*(int **)(pTVar56 + -0x7c));
        uVar64 = CONCAT44(local_878,extraout_r4_02);
        if (iVar55 != 0) {
          iVar55 = (**(code **)(**(int **)(pTVar56 + -0x24) + 0x18))(*(int **)(pTVar56 + -0x24));
          param_3 = *(char **)(pTVar56 + -0x7c);
          param_4 = *(char **)(pTVar56 + -0x58);
          uVar64 = TParseContext__addConstMatrixNode
                             (param_1,**(int **)(iVar55 + 0x30),(unsigned char *)param_3,(int)param_4
                             );
        }
      }
      else {
        local_810 = (unsigned char *)0x1;
        iVar55 = (**(code **)(**(int **)(pTVar56 + -0x24) + 0x18))(*(int **)(pTVar56 + -0x24));
        local_820 = (unsigned char *)**(uint **)(iVar55 + 0x30);
        param_3 = *(char **)(pTVar56 + -0x7c);
        param_4 = *(char **)(pTVar56 + -0x58);
        uVar64 = TParseContext__addConstVectorNode
                           (param_1,(unsigned char *)&local_820,(unsigned char *)param_3,(int)param_4
                            ,param_5,pTVar33);
      }
    }
    else {
      iVar55 = (**(code **)(**(int **)(pTVar56 + -0x24) + 0x44))(*(int **)(pTVar56 + -0x24));
      if (iVar55 == 2) {
        bVar37 = false;
        iVar55 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x58))(*(int **)(pTVar56 + -0x7c));
        if ((iVar55 != 0) ||
           (iVar55 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x50))(*(int **)(pTVar56 + -0x7c)),
           iVar55 != 0)) {
          (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x38))(&local_7e0,*(int **)(pTVar56 + -0x7c));
          uVar57 = local_7bc << 0xd;
          uVar28 = local_7bc >> 0x13;
          iVar55 = (**(code **)(**(int **)(pTVar56 + -0x24) + 0x18))(*(int **)(pTVar56 + -0x24));
          uVar16 = extraout_r4_03;
          if (((int)(uVar57 | uVar28) >> 0x18 <= **(int **)(iVar55 + 0x30)) &&
             (iVar55 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x54))(*(int **)(pTVar56 + -0x7c))
             , uVar16 = extraout_r4_04, iVar55 == 0)) {
            bVar37 = true;
          }
          local_7e0 = local_5c + -0x610c;
          pTVar33 = local_5c;
          if (bVar37) {
            iVar55 = (**(code **)(**(int **)(pTVar56 + -0x24) + 0x18))
                               (*(int **)(pTVar56 + -0x24),uVar16,param_3,param_4,param_5,local_5c);
            pTVar33 = (unsigned char *)**(uint **)(iVar55 + 0x30);
            param_3 = "";
            param_4 = "[";
            param_5 = "field selection out of range \'%d\'";
            TParseContext__error
                      ((int)param_1,*(char **)(pTVar56 + -0x58),"","[",
                       "field selection out of range \'%d\'",pTVar33,pTVar34,param_8);
            TParseContext__recover(param_1);
            uVar64 = CONCAT44(local_878,extraout_r4_05);
            goto LAB_97ba47fc;
          }
        }
        iVar55 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x54))(*(int **)(pTVar56 + -0x7c));
        if (iVar55 != 0) {
          (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x38))(&local_7b0,*(int **)(pTVar56 + -0x7c));
          pTVar3 = local_5c + -0x610c;
          local_7b0 = pTVar3;
          if (local_7ac == (char *)0x0) {
            pTVar7 = local_5c;
            (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x38))
                      (&local_780,*(int **)(pTVar56 + -0x7c),param_3,param_4,param_5,local_5c);
            iVar55 = local_764;
            iVar54 = (**(code **)(**(int **)(pTVar56 + -0x24) + 0x18))(*(int **)(pTVar56 + -0x24));
            pTVar34 = (unsigned char *)(uint)(iVar55 <= **(int **)(iVar54 + 0x30));
            bVar37 = pTVar34 == (unsigned char *)0x0;
            if (bVar37) {
              local_780 = pTVar3;
              pTVar8 = (unsigned char *)
                       (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x28))
                                 (*(int **)(pTVar56 + -0x7c),a1_00,param_3,param_4,param_5,pTVar7);
              pTVar12 = (unsigned char *)(**(code **)(**(int **)(pTVar56 + -0x7c) + 0x3c))
                                           (*(int **)(pTVar56 + -0x7c));
              pTVar33 = *(unsigned char **)(pTVar56 + -0x58);
              iVar55 = 0;
            }
            else {
              local_780 = pTVar3;
              iVar55 = (**(code **)(**(int **)(pTVar56 + -0x24) + 0x18))
                                 (*(int **)(pTVar56 + -0x24),a1_00,param_3,param_4,param_5,pTVar7,
                                  pTVar34);
              piVar61 = *(int **)(iVar55 + 0x30);
              pTVar34 = (unsigned char *)**(undefined4 **)(pTVar56 + -0x7c);
              pTVar8 = (unsigned char *)
                       (**(code **)(pTVar34 + 0x28))
                                 (*(undefined4 **)(pTVar56 + -0x7c),a1_01,param_3,param_4,param_5,
                                  pTVar7,pTVar34);
              pTVar12 = (unsigned char *)(**(code **)(**(int **)(pTVar56 + -0x7c) + 0x3c))
                                           (*(int **)(pTVar56 + -0x7c));
              iVar55 = *piVar61;
              pTVar33 = *(unsigned char **)(pTVar56 + -0x58);
            }
            iVar55 = TParseContext__arraySetMaxSize
                               (param_1,pTVar8,pTVar12,iVar55,(uint)!bVar37,(int)pTVar33);
            if (iVar55 != 0) {
LAB_97ba475c:
              TParseContext__recover(param_1);
            }
          }
          else {
            pTVar33 = local_5c;
            iVar55 = (**(code **)(**(int **)(pTVar56 + -0x24) + 0x18))(*(int **)(pTVar56 + -0x24));
            piVar61 = *(int **)(iVar55 + 0x30);
            (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x38))(&local_780,*(int **)(pTVar56 + -0x7c))
            ;
            pTVar34 = (unsigned char *)(uint)(local_77c <= *piVar61);
            local_780 = pTVar3;
            if (pTVar34 != (unsigned char *)0x0) {
              iVar55 = (**(code **)(**(int **)(pTVar56 + -0x24) + 0x18))
                                 (*(int **)(pTVar56 + -0x24),a1_02,param_3,param_4,param_5,pTVar33,
                                  pTVar34);
              pTVar33 = (unsigned char *)**(uint **)(iVar55 + 0x30);
              TParseContext__error
                        ((int)param_1,*(char **)(pTVar56 + -0x58),"","[",
                         "array index out of range \'%d\'",pTVar33,pTVar34,param_8);
              goto LAB_97ba475c;
            }
          }
        }
        pTVar15 = *(unsigned char **)param_1;
        uVar16 = 0x2d;
      }
      else {
        iVar55 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x54))(*(int **)(pTVar56 + -0x7c),a1);
        if (iVar55 != 0) {
          (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x38))(&local_820,*(int **)(pTVar56 + -0x7c));
          local_820 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
          if (local_81c == (unsigned char *)0x0) {
            TParseContext__error
                      ((int)param_1,*(char **)(pTVar56 + -0x58),"","[",
                       "array must be redeclared with a size before being indexed with a variable",
                       pTVar33,pTVar34,param_8);
            TParseContext__recover(param_1);
          }
        }
        pTVar15 = *(unsigned char **)param_1;
        uVar16 = 0x2e;
      }
      param_3 = *(char **)(pTVar56 + -0x7c);
      param_4 = *(char **)(pTVar56 + -0x24);
      param_5 = *(char **)(pTVar56 + -0x58);
      uVar64 = TIntermediate__addIndex(pTVar15,uVar16,param_3,param_4,param_5);
    }
LAB_97ba47fc:
    local_878 = (unsigned char *)((ulonglong)uVar64 >> 0x20);
    pTVar3 = local_878;
    if (local_878 == (unsigned char *)0x0) {
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      pcVar9 = (unsigned char *)TPoolAllocator__allocate(pTVar17,4);
      *(undefined4 *)pcVar9 = 0;
      local_850 = local_5c + -0x610c;
      local_82c = (unsigned char *)((uint)local_82c & 0x1ff | 0x4080800);
      local_84c = pTVar3;
      local_848 = pTVar3;
      local_844 = pTVar3;
      local_840 = pTVar3;
      local_83c = pTVar3;
      local_838 = pTVar3;
      local_834 = pTVar3;
      local_830 = pTVar3;
      pTVar15 = *(unsigned char **)param_1;
      param_4 = *(char **)(pTVar56 + -0x58);
      goto LAB_97ba7d0c;
    }
    iVar55 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x54))
                       (*(int **)(pTVar56 + -0x7c),(int)uVar64,param_3,param_4,param_5,pTVar33,
                        pTVar34);
    in_cr0 = (iVar55 == 0) << 1;
    if (iVar55 == 0) {
      iVar55 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x50))(*(int **)(pTVar56 + -0x7c));
      if (iVar55 != 0) {
        (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x38))(&local_850,*(int **)(pTVar56 + -0x7c));
        pTVar7 = local_5c + -0x610c;
        pTVar33 = local_5c;
        local_850 = pTVar7;
        if ((uint)local_82c >> 0x19 == 2) {
          uVar57 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x40))
                             (*(int **)(pTVar56 + -0x7c),a1_03,param_3,param_4,param_5,local_5c);
          uVar28 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x48))(*(int **)(pTVar56 + -0x7c));
          local_7fc = (unsigned char *)
                      ((uVar28 & 0xff) << 0xb |
                      (uVar57 & 0x3f) << 0x13 | (uint)local_7fc & 0x1ff | 0x4000000);
          local_800 = (unsigned char *)0x0;
          goto LAB_97ba4bc0;
        }
      }
      pTVar3 = (unsigned char *)
               (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x50))(*(int **)(pTVar56 + -0x7c));
      in_cr0 = (pTVar3 == (unsigned char *)0x0) << 1;
      if (pTVar3 != (unsigned char *)0x0) {
        uVar57 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x40))(*(int **)(pTVar56 + -0x7c));
        uVar28 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x48))(*(int **)(pTVar56 + -0x7c));
        local_800 = (unsigned char *)0x0;
        pTVar7 = local_5c + -0x610c;
        local_7fc = (unsigned char *)
                    ((uVar28 & 0xff) << 0xb | (uVar57 & 0x3f) << 0x13 | (uint)local_7fc & 0x1ff);
        local_81c = (unsigned char *)0x0;
        local_818 = (unsigned char *)0x0;
        local_814 = (unsigned char *)0x0;
        local_810 = (unsigned char *)0x0;
        local_80c = (unsigned char *)0x0;
        local_808 = (unsigned char *)0x0;
        local_804 = (unsigned char *)0x0;
        local_820 = pTVar7;
        (**(code **)(*(unsigned char **)local_878 + 0x34))(local_878,&local_820);
        pTVar3 = local_878;
        local_820 = pTVar7;
        pTVar31 = local_7f0;
        pTVar32 = local_750[0];
        break;
      }
      iVar55 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x58))(*(int **)(pTVar56 + -0x7c));
      if (iVar55 != 0) {
        (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x38))(&local_820,*(int **)(pTVar56 + -0x7c));
        pTVar31 = local_5c + -0x610c;
        pTVar33 = local_5c;
        local_820 = pTVar31;
        if ((uint)local_7fc >> 0x19 == 2) {
          uVar57 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x40))
                             (*(int **)(pTVar56 + -0x7c),a1_04,param_3,param_4,param_5,local_5c);
          local_7cc = (uVar57 & 0x3f) << 0x13 | local_7cc & 0x9ff | 0x4000000 | 0x800;
          local_7f0 = pTVar31;
          local_7ec = pTVar3;
          local_7e8 = pTVar3;
          local_7e4 = pTVar3;
          local_7e0 = pTVar3;
          local_7dc = pTVar3;
          local_7d8 = pTVar3;
          local_7d4 = pTVar3;
          local_7d0 = pTVar3;
          (**(code **)(*(unsigned char **)local_878 + 0x34))(local_878,&local_7f0);
          pTVar3 = local_878;
          pTVar32 = local_750[0];
          break;
        }
      }
      iVar55 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x58))(*(int **)(pTVar56 + -0x7c));
      if (iVar55 == 0) {
        (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x38))(&local_7f0,*(int **)(pTVar56 + -0x7c));
        (**(code **)(*(unsigned char **)local_878 + 0x34))(local_878,&local_7f0);
        pTVar3 = local_878;
        pTVar31 = local_5c + -0x610c;
        pTVar32 = local_750[0];
      }
      else {
        uVar57 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x40))(*(int **)(pTVar56 + -0x7c));
        pTVar31 = local_5c + -0x610c;
        local_7cc = (uVar57 & 0x3f) << 0x13 | local_7cc & 0x9ff | 0x800;
        local_7ec = (unsigned char *)0x0;
        local_7e8 = (unsigned char *)0x0;
        local_7e4 = (unsigned char *)0x0;
        local_7e0 = (unsigned char *)0x0;
        local_7dc = (unsigned char *)0x0;
        local_7d8 = (unsigned char *)0x0;
        local_7d4 = (unsigned char *)0x0;
        local_7d0 = (unsigned char *)0x0;
        local_7f0 = pTVar31;
        (**(code **)(*(unsigned char **)local_878 + 0x34))
                  (local_878,&local_7f0,param_3,param_4,param_5,pTVar33,*(unsigned char **)local_878)
        ;
        pTVar3 = local_878;
        pTVar32 = local_750[0];
      }
      break;
    }
    (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x38))(&local_850,*(int **)(pTVar56 + -0x7c));
    pTVar3 = local_848;
    pTVar7 = local_5c + -0x610c;
    local_850 = pTVar7;
    if (local_848 == (unsigned char *)0x0) {
      uVar57 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x40))(*(int **)(pTVar56 + -0x7c));
      uVar28 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x48))(*(int **)(pTVar56 + -0x7c));
      uVar53 = (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x50))(*(int **)(pTVar56 + -0x7c));
      local_7fc = (unsigned char *)
                  ((uVar53 & 1) << 10 |
                  (uVar28 & 0xff) << 0xb | (uVar57 & 0x3f) << 0x13 | (uint)local_7fc & 0x1ff);
      local_800 = pTVar3;
LAB_97ba4bc0:
      local_820 = pTVar7;
      local_81c = local_800;
      local_818 = local_800;
      local_814 = local_800;
      local_810 = local_800;
      local_80c = local_800;
      local_808 = local_800;
      local_804 = local_800;
      (**(code **)(*(unsigned char **)local_878 + 0x34))(local_878,&local_820);
      pTVar3 = local_878;
      local_820 = pTVar7;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
      break;
    }
    local_64 = (unsigned char *)0xa7b8374c;
    (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x38))
              (&local_7f0,*(int **)(pTVar56 + -0x7c),param_3,param_4,param_5,local_5c,0xa7b8374c);
    pTVar3 = local_7e8;
    (**(code **)(**(int **)(pTVar56 + -0x7c) + 0x38))(local_750,*(int **)(pTVar56 + -0x7c));
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_((unsigned char *)&local_7c0,local_740);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_7b0,(unsigned char *)&local_7c0);
    local_7fc = (unsigned char *)((uint)local_7fc & 0x9ff | 0x700800);
    local_800 = (unsigned char *)0x0;
    local_81c = (unsigned char *)0x0;
    local_818 = pTVar3;
    local_814 = (unsigned char *)0x0;
    local_80c = (unsigned char *)0x0;
    local_804 = (unsigned char *)0x0;
    local_820 = pTVar7;
    local_808 = (unsigned char *)TType__setStructSize((unsigned char *)&local_820,(unsigned char *)pTVar3);
    pcVar62 = local_7ac;
    local_7ac[*(int *)(local_7ac + -0xc)] = **(char **)(local_64 + -0x7cc4);
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar7 = (unsigned char *)TPoolAllocator__allocate(pTVar17,8);
    in_cr0 = (pTVar7 == (unsigned char *)0x0) << 1;
    pTVar3 = (unsigned char *)0x0;
    if (pTVar7 != (unsigned char *)0x0) {
      local_720[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (pTVar7,pcVar62,(unsigned char *)local_720);
      pTVar3 = pTVar7;
    }
    piVar61 = (int *)(local_7ac + -4);
    local_710[0] = local_7b0;
    do {
      iVar55 = *piVar61;
      if (in_RESERVE != '\0') {
        iVar54 = storeWordConditionalIndexed(iVar55 + -1,0,piVar61);
        *piVar61 = iVar54;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    local_810 = pTVar3;
    if (iVar55 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_7ac + -0xc),local_710);
    }
    (**(code **)(*(unsigned char **)local_878 + 0x34))(local_878,(unsigned char *)&local_820);
    pTVar31 = local_5c + -0x610c;
    local_700[0] = local_7c0;
    piVar61 = (int *)(local_7bc - 4);
    do {
      iVar55 = *piVar61;
      if (in_RESERVE != '\0') {
        iVar54 = storeWordConditionalIndexed(iVar55 + -1,0,piVar61);
        *piVar61 = iVar54;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    pTVar3 = local_878;
    local_820 = pTVar31;
    pTVar32 = pTVar31;
    if (iVar55 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_7bc - 0xc),local_700);
      pTVar3 = local_878;
    }
    break;
  case 10:
    iVar55 = (**(code **)(**(int **)(pTVar56 + -0x50) + 0x54))
                       (*(int **)(pTVar56 + -0x50),param_2,param_3,param_4,param_5,pTVar33);
    if (iVar55 != 0) {
      param_3 = "cannot apply dot operator to an array";
      param_4 = ".";
      param_5 = "";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56,"cannot apply dot operator to an array",".","",
                 pTVar33,pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    pTVar3 = (unsigned char *)
             (**(code **)(**(int **)(pTVar56 + -0x50) + 0x58))(*(int **)(pTVar56 + -0x50));
    in_cr0 = (pTVar3 == (unsigned char *)0x0) << 1;
    if (pTVar3 == (unsigned char *)0x0) {
      iVar55 = (**(code **)(**(int **)(pTVar56 + -0x50) + 0x50))
                         (*(int **)(pTVar56 + -0x50),a1_05,param_3,param_4,param_5,pTVar33,pTVar34);
      if (iVar55 == 0) {
        iVar55 = (**(code **)(**(int **)(pTVar56 + -0x50) + 0x40))(*(int **)(pTVar56 + -0x50));
        if (iVar55 != 0xe) {
          param_8 = *(uint *)(pTVar56 + 4);
          pTVar34 = *(unsigned char **)(param_8 + 4);
          pcVar62 = " field selection requires structure, vector, or matrix on left hand side";
          goto LAB_97ba5784;
        }
        local_5c = (unsigned char *)0xa7b8374c;
        (**(code **)(**(int **)(pTVar56 + -0x50) + 0x38))(&local_850,*(int **)(pTVar56 + -0x50));
        pTVar7 = local_848;
        local_850 = local_5c + -0x610c;
        pTVar33 = local_5c;
        if (local_848 == (unsigned char *)0x0) {
          pcVar29 = *(char **)(pTVar56 + -0x2c);
          pcVar62 = "structure has no fields";
          param_4 = "Internal Error";
          goto LAB_97ba5548;
        }
        uVar57 = 0;
        uVar16 = extraout_r4_06;
        goto LAB_97ba55dc;
      }
      iVar55 = (**(code **)(**(int **)(pTVar56 + -0x50) + 0x48))(*(int **)(pTVar56 + -0x50));
      iVar55 = TParseContext__parseMatrixFields
                         (param_1,*(unsigned char **)(pTVar56 + 4),iVar55,(unsigned char *)&local_850,
                          *(uint *)pTVar56);
      if (iVar55 == 0) {
        local_850 = pTVar3;
        local_84c = pTVar3;
        local_848 = pTVar3;
        local_844 = pTVar3;
        TParseContext__recover(param_1);
      }
      pTVar7 = local_84c;
      if ((local_850 == (unsigned char *)0x0) && (local_84c == (unsigned char *)0x0)) {
        pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
        pcVar9 = (unsigned char *)TPoolAllocator__allocate(pTVar17,4);
        local_5c = (unsigned char *)0xa7b8374c;
        iVar55 = (**(code **)(**(int **)(pTVar56 + -0x50) + 0x48))(*(int **)(pTVar56 + -0x50));
        pTVar33 = local_5c + -0x610c;
        *(unsigned char **)pcVar9 = local_848 + (int)local_844 * iVar55;
        local_81c = (unsigned char *)((uint)local_81c & 0x1ff | 0x4100800);
        local_83c = pTVar7;
        local_838 = pTVar7;
        local_834 = pTVar7;
        local_830 = pTVar7;
        local_82c = pTVar7;
        local_828 = pTVar7;
        local_824 = pTVar7;
        local_820 = pTVar7;
        local_840 = pTVar33;
        param_4 = (char *)TIntermediate__addConstantUnion
                                    (*(unsigned char **)param_1,pcVar9,(unsigned char *)&local_840,
                                     *(uint *)pTVar56);
        param_5 = *(char **)(pTVar56 + -0x2c);
        local_840 = pTVar33;
        local_878 = (unsigned char *)
                    TIntermediate__addIndex
                              (*(unsigned char **)param_1,0x2d,*(uint *)(pTVar56 + -0x50),param_4,
                               param_5);
        uVar57 = (**(code **)(**(int **)(pTVar56 + -0x50) + 0x40))(*(int **)(pTVar56 + -0x50));
        local_81c = (unsigned char *)((uVar57 & 0x3f) << 0x13 | (uint)local_81c & 0x1ff | 0x800);
        local_83c = pTVar7;
        local_838 = pTVar7;
        local_834 = pTVar7;
        local_830 = pTVar7;
        local_82c = pTVar7;
        local_828 = pTVar7;
        local_824 = pTVar7;
        local_820 = pTVar7;
        local_840 = pTVar33;
        (**(code **)(*(uint *)local_878 + 0x34))(local_878,(unsigned char *)&local_840);
        pTVar3 = local_878;
        local_840 = pTVar33;
        pTVar31 = local_7f0;
        pTVar32 = local_750[0];
      }
      else {
        TParseContext__error
                  ((int)param_1,*(char **)(pTVar56 + -0x2c)," non-scalar fields not implemented yet"
                   ,".","",pTVar33,pTVar34,param_8);
        TParseContext__recover(param_1);
        pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
        pcVar9 = (unsigned char *)TPoolAllocator__allocate(pTVar17,4);
        *(undefined4 *)pcVar9 = 0;
        local_81c = (unsigned char *)((uint)local_81c & 0x9ff | 0x4100800);
        local_840 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
        local_83c = pTVar3;
        local_838 = pTVar3;
        local_834 = pTVar3;
        local_830 = pTVar3;
        local_82c = pTVar3;
        local_828 = pTVar3;
        local_824 = pTVar3;
        local_820 = pTVar3;
        param_4 = (char *)TIntermediate__addConstantUnion
                                    (*(unsigned char **)param_1,pcVar9,(unsigned char *)&local_840,
                                     *(uint *)pTVar56);
        local_840 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
        param_5 = *(char **)(pTVar56 + -0x2c);
        local_878 = (unsigned char *)
                    TIntermediate__addIndex
                              (*(unsigned char **)param_1,0x2d,*(uint *)(pTVar56 + -0x50),param_4,
                               param_5);
        uVar57 = (**(code **)(**(int **)(pTVar56 + -0x50) + 0x40))(*(int **)(pTVar56 + -0x50));
        uVar28 = (**(code **)(**(int **)(pTVar56 + -0x50) + 0x48))(*(int **)(pTVar56 + -0x50));
        local_81c = (unsigned char *)
                    ((uVar28 & 0xff) << 0xb | (uVar57 & 0x3f) << 0x13 | (uint)local_81c & 0x1ff);
        local_840 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
        local_83c = pTVar3;
        local_838 = pTVar3;
        local_834 = pTVar3;
        local_830 = pTVar3;
        local_82c = pTVar3;
        local_828 = pTVar3;
        local_824 = pTVar3;
        local_820 = pTVar3;
        (**(code **)(*(uint *)local_878 + 0x34))(local_878,(unsigned char *)&local_840);
        local_840 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
        pTVar3 = local_878;
        pTVar31 = local_7f0;
        pTVar32 = local_750[0];
      }
      break;
    }
    iVar55 = (**(code **)(**(int **)(pTVar56 + -0x50) + 0x48))(*(int **)(pTVar56 + -0x50));
    param_5 = *(char **)pTVar56;
    pTVar3 = (unsigned char *)
             TParseContext__parseVectorFields
                       (param_1,*(unsigned char **)(pTVar56 + 4),iVar55,(unsigned char *)&local_850,
                        (int)param_5);
    in_cr0 = (pTVar3 == (unsigned char *)0x0) << 1;
    if (pTVar3 == (unsigned char *)0x0) {
      local_840 = (unsigned char *)0x1;
      local_850 = pTVar3;
      TParseContext__recover(param_1);
    }
    local_5c = (unsigned char *)0xa7b8374c;
    (**(code **)(**(int **)(pTVar56 + -0x50) + 0x38))(&local_830,*(int **)(pTVar56 + -0x50));
    pTVar7 = local_5c + -0x610c;
    pTVar3 = local_5c;
    local_830 = pTVar7;
    if ((uint)local_80c >> 0x19 == 2) {
      pTVar33 = *(unsigned char **)(pTVar56 + -0x50);
      param_4 = *(char **)pTVar56;
      local_878 = (unsigned char *)
                  TParseContext__addConstVectorNode
                            (param_1,(unsigned char *)&local_850,pTVar33,(int)param_4,param_5,
                             local_5c);
      if (local_878 == (unsigned char *)0x0) goto LAB_97ba5554;
      uVar57 = (**(code **)(**(int **)(pTVar56 + -0x50) + 0x40))(*(int **)(pTVar56 + -0x50));
      local_7dc = (unsigned char *)
                  ((*(uint *)(*(int *)(*(uint *)(pTVar56 + 4) + 4) + -0xc) & 0xff) << 0xb |
                  (uVar57 & 0x3f) << 0x13 | (uint)local_7dc & 0x1ff | 0x4000000);
      pTVar32 = *(unsigned char **)(*(unsigned char **)local_878 + 0x34);
      pTVar31 = *(unsigned char **)local_878;
LAB_97ba50cc:
      local_7e0 = (unsigned char *)0x0;
      local_7e4 = (unsigned char *)0x0;
      local_7e8 = (unsigned char *)0x0;
      local_7ec = (unsigned char *)0x0;
      local_7f0 = (unsigned char *)0x0;
      local_7f4 = (unsigned char *)0x0;
      local_7f8 = (unsigned char *)0x0;
      local_7fc = (unsigned char *)0x0;
      local_800 = pTVar7;
      (*(code *)pTVar32)(local_878,&local_800,pTVar33,param_4,param_5,pTVar3,pTVar31);
      pTVar3 = local_878;
      local_800 = pTVar7;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
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
      local_800 = pTVar7;
      param_4 = (char *)TIntermediate__addConstantUnion
                                  (*(unsigned char **)param_1,pcVar9,(unsigned char *)&local_800,
                                   *(uint *)pTVar56);
      pTVar33 = *(unsigned char **)(pTVar56 + -0x50);
      param_5 = *(char **)(pTVar56 + -0x2c);
      local_800 = pTVar7;
      local_878 = (unsigned char *)
                  TIntermediate__addIndex(*(unsigned char **)param_1,0x2d,pTVar33,param_4,param_5);
      uVar57 = (**(code **)(**(int **)(pTVar56 + -0x50) + 0x40))(*(int **)(pTVar56 + -0x50));
      local_7dc = (unsigned char *)((uVar57 & 0x3f) << 0x13 | (uint)local_7dc & 0x1ff | 0x800);
      pTVar32 = *(unsigned char **)(*(unsigned char **)local_878 + 0x34);
      pTVar31 = local_878;
      goto LAB_97ba50cc;
    }
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_800,*(unsigned char **)(pTVar56 + 4));
    param_4 = (char *)TIntermediate__addSwizzle
                                (*(unsigned char **)param_1,(unsigned char *)&local_850,
                                 *(uint *)pTVar56);
    uVar28 = *(uint *)(pTVar56 + -0x50);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addIndex(*(unsigned char **)param_1,0x30,uVar28,param_4,param_5);
    pTVar33 = *(unsigned char **)local_878;
    uVar57 = (**(code **)(**(int **)(pTVar56 + -0x50) + 0x40))(*(int **)(pTVar56 + -0x50));
    local_7cc = (*(uint *)(local_7fc + -0xc) & 0xff) << 0xb |
                (uVar57 & 0x3f) << 0x13 | local_7cc & 0x1ff;
    local_7d0 = (unsigned char *)0x0;
    local_7ec = (unsigned char *)0x0;
    local_7e8 = (unsigned char *)0x0;
    local_7e4 = (unsigned char *)0x0;
    local_7e0 = (unsigned char *)0x0;
    local_7dc = (unsigned char *)0x0;
    local_7d8 = (unsigned char *)0x0;
    local_7d4 = (unsigned char *)0x0;
    local_7f0 = pTVar7;
    (**(code **)(pTVar33 + 0x34))
              (local_878,&local_7f0,uVar28,param_4,param_5,pTVar3,*(uint *)(local_7fc + -0xc));
    pTVar3 = local_7fc + -4;
    local_6f0[0] = local_800;
    paVar11 = (unsigned char *)(local_7fc + -0xc);
    do {
      uVar57 = *(uint *)pTVar3;
      if (in_RESERVE != '\0') {
        uVar28 = storeWordConditionalIndexed(uVar57 - 1,0,pTVar3);
        *(uint *)pTVar3 = uVar28;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)uVar57;
    ppTVar24 = local_6f0;
    local_7f0 = pTVar7;
    goto LAB_97ba869c;
  case 0xb:
    iVar55 = TParseContext__lValueErrorCheck
                       (param_1,*(uint *)pTVar56,"++",*(unsigned char **)(pTVar56 + -0x24),param_5,
                        pTVar33,pTVar34,param_8);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    param_4 = *(char **)pTVar56;
    param_5 = *(char **)((int)param_1 + 4);
    local_878 = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(unsigned char **)param_1,9,*(uint *)(pTVar56 + -0x24),param_4,param_5,
                           pTVar33,pTVar34);
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_4 = (char *)&local_850;
    TType__getCompleteString(param_4,*(uint *)(pTVar56 + -0x24) + 8);
    TParseContext__unaryOpError(param_1,*(uint *)pTVar56,"++",param_4);
    pTVar3 = local_84c + -4;
    local_6e0[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      ppTVar24 = local_6e0;
LAB_97ba5844:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_84c + -0xc),ppTVar24);
    }
    goto LAB_97ba5848;
  case 0xc:
    iVar55 = TParseContext__lValueErrorCheck
                       (param_1,*(uint *)pTVar56,"--",*(unsigned char **)(pTVar56 + -0x24),param_5,
                        pTVar33,pTVar34,param_8);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    param_4 = *(char **)pTVar56;
    param_5 = *(char **)((int)param_1 + 4);
    local_878 = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(unsigned char **)param_1,10,*(uint *)(pTVar56 + -0x24),param_4,param_5,
                           pTVar33,pTVar34);
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_4 = (char *)&local_850;
    TType__getCompleteString(param_4,*(uint *)(pTVar56 + -0x24) + 8);
    TParseContext__unaryOpError(param_1,*(uint *)pTVar56,"--",param_4);
    pTVar3 = local_84c + -4;
    local_6d0[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    ppTVar24 = local_6d0;
    if ((int)pTVar7 < 1) goto LAB_97ba5844;
LAB_97ba5848:
    TParseContext__recover(param_1);
switchD_97ba39c8_caseD_6:
    pTVar3 = *(unsigned char **)(pTVar56 + -0x24);
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xd:
    iVar55 = TParseContext__integerErrorCheck(param_1,*(unsigned char **)(pTVar56 + 8),"[]");
    goto LAB_97ba82e8;
  case 0xe:
    a0 = *(unsigned char **)(pTVar56 + 0x10);
    pTVar3 = *(unsigned char **)(a0 + 0x4c);
    if (pTVar3 != (unsigned char *)0x0) {
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
      param_4 = (char *)a0;
      param_5 = (char *)pTVar3;
      iVar55 = TParseContext__constructorErrorCheck
                         (param_1,*(uint *)pTVar56,*(unsigned char **)(pTVar56 + 8),a0,pTVar3,
                          (unsigned char *)&local_850);
      if (iVar55 == 0) {
        param_4 = (char *)pTVar3;
        param_5 = (char *)a0;
        local_878 = (unsigned char *)
                    TParseContext__addConstructor
                              (param_1,*(unsigned char **)(pTVar56 + 8),(unsigned char *)&local_850,pTVar3,a0,
                               *(uint *)pTVar56);
      }
      else {
        local_878 = (unsigned char *)0x0;
      }
      if (local_878 == (unsigned char *)0x0) {
        TParseContext__recover(param_1);
        param_4 = *(char **)pTVar56;
        local_878 = (unsigned char *)
                    TIntermediate__setAggregateOperator
                              (*(unsigned char **)param_1,(unsigned char *)0x0,pTVar3,param_4);
      }
      (**(code **)(*(unsigned char **)local_878 + 0x34))(local_878,(unsigned char *)&local_850);
      local_850 = local_5c + -0x610c;
      goto LAB_97ba5e28;
    }
    pTVar3 = (unsigned char *)
             TParseContext__findFunction
                       (param_1,*(uint *)pTVar56,a0,(bool *)&local_88,param_5,pTVar33);
    in_cr0 = (pTVar3 == (unsigned char *)0x0) << 1;
    if (pTVar3 == (unsigned char *)0x0) {
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      pcVar9 = (unsigned char *)TPoolAllocator__allocate(pTVar17,4);
      *(undefined4 *)pcVar9 = 0;
      local_82c = (unsigned char *)((uint)local_82c & 0x1ff | 0x4080800);
      local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      param_4 = *(char **)pTVar56;
      local_84c = pTVar3;
      local_848 = pTVar3;
      local_844 = pTVar3;
      local_840 = pTVar3;
      local_83c = pTVar3;
      local_838 = pTVar3;
      local_834 = pTVar3;
      local_830 = pTVar3;
      local_878 = (unsigned char *)
                  TIntermediate__addConstantUnion
                            (*(unsigned char **)param_1,pcVar9,(unsigned char *)&local_850,(int)param_4);
      local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      TParseContext__recover(param_1);
      goto LAB_97ba5e28;
    }
    uVar57 = *(uint *)(pTVar3 + 0x4c);
    if ((local_88 == 0) || (uVar57 == 0)) {
      pcVar62 = (char *)0x2;
      param_4 = *(char **)pTVar56;
      local_878 = (unsigned char *)
                  TIntermediate__setAggregateOperator
                            (*(unsigned char **)param_1,*(unsigned char **)(pTVar56 + 8),2,param_4);
      (**(code **)(*(unsigned char **)local_878 + 0x34))(local_878,pTVar3 + 0x1c);
      if (local_88 == 0) {
        piVar61 = (int *)(**(code **)(*(unsigned char **)local_878 + 0x1c))(local_878);
        (**(code **)(*piVar61 + 0x70))(piVar61);
      }
      piVar61 = (int *)(**(code **)(*(unsigned char **)local_878 + 0x1c))(local_878);
      iVar55 = *piVar61;
      uVar16 = (**(code **)(*(unsigned char **)pTVar3 + 8))(pTVar3);
      (**(code **)(iVar55 + 0x68))(piVar61,uVar16);
      piVar61 = (int *)(**(code **)(*(unsigned char **)local_878 + 0x1c))(local_878);
      this = (unsigned char *)(**(code **)(*piVar61 + 0x78))(piVar61);
      piVar61 = extraout_r4_10;
      for (iVar55 = 0; iVar55 < (int)(*(uint *)(pTVar3 + 0x14) - *(uint *)(pTVar3 + 0x10)) >> 3;
          iVar55 = iVar55 + 1) {
        piVar50 = *(int **)(*(uint *)(pTVar3 + 0x10) + iVar55 * 8 + 4);
        iVar54 = *piVar50;
        iVar54 = (**(code **)(iVar54 + 0x24))
                           (piVar50,piVar61,pcVar62,param_4,param_5,pTVar33,iVar54);
        if (iVar54 - 10U < 2) {
          piVar61 = (int *)(**(code **)(*(unsigned char **)local_878 + 0x1c))(local_878);
          iVar60 = (**(code **)(*piVar61 + 100))(piVar61);
          iVar6 = *(int *)(iVar60 + 4);
          piVar61 = *(int **)(iVar6 + iVar55 * 4);
          param_4 = (char *)(**(code **)(*piVar61 + 0x14))
                                      (piVar61,a1_07,pcVar62,param_4,param_5,pTVar33,iVar6);
          iVar60 = (**(code **)*(unsigned char **)local_878)(local_878);
          pcVar62 = "assign";
          iVar60 = TParseContext__lValueErrorCheck
                             (param_1,iVar60,"assign",(unsigned char *)param_4,param_5,pTVar33,iVar6,
                              param_8);
          if (iVar60 != 0) {
            pcVar29 = (char *)(**(code **)**(undefined4 **)(pTVar56 + 8))
                                        (*(undefined4 **)(pTVar56 + 8));
            pcVar62 = "Constant value cannot be passed for \'out\' or \'inout\' parameters.";
            param_4 = "Error";
            param_5 = "";
            TParseContext__error
                      ((int)param_1,pcVar29,
                       "Constant value cannot be passed for \'out\' or \'inout\' parameters.",
                       "Error","",pTVar33,iVar6,param_8);
            TParseContext__recover(param_1);
          }
        }
        piVar61 = *(int **)(this + 8);
        local_84 = iVar54;
        if (piVar61 == *(int **)(this + 0xc)) {
          pcVar62 = (char *)&local_84;
          std__vector_int_pool_allocator_int_____M_insert_aux(this,piVar61,pcVar62);
          piVar61 = extraout_r4_11;
        }
        else {
          iVar60 = 0;
          if (piVar61 != (int *)0x0) {
            *piVar61 = iVar54;
            iVar60 = *(int *)(this + 8);
          }
          *(int *)(this + 8) = iVar60 + 4;
        }
      }
    }
    else {
      if ((int)(*(uint *)(pTVar3 + 0x14) - *(uint *)(pTVar3 + 0x10)) >> 3 == 1) {
        uVar28 = *(uint *)(pTVar56 + 8);
        param_4 = (char *)0x0;
        param_5 = *(char **)((int)param_1 + 4);
        local_878 = (unsigned char *)
                    TIntermediate__addUnaryMath
                              (*(unsigned char **)param_1,uVar57,uVar28,0,param_5,pTVar33,
                               *(uint *)(pTVar3 + 0x10));
        if (local_878 != (unsigned char *)0x0) goto LAB_97ba5d80;
        local_64 = (unsigned char *)0xa7b8374c;
        TType__getCompleteString(&local_850,*(uint *)(pTVar56 + 8) + 8);
        pTVar33 = local_84c;
        local_84c[*(uint *)(local_84c + -0xc)] = **(unsigned char **)(local_64 + -0x7cc4);
        pTVar3 = local_84c;
        pcVar62 = (char *)(**(code **)**(undefined4 **)(pTVar56 + 8))
                                    (*(undefined4 **)(pTVar56 + 8),a1_06,uVar28,param_4,param_5,
                                     local_64,local_84c);
        param_3 = " wrong operand type";
        param_4 = "Internal Error";
        param_5 = "built in unary operator function.  Type: %s";
        TParseContext__error
                  ((int)param_1,pcVar62," wrong operand type","Internal Error",
                   "built in unary operator function.  Type: %s",pTVar33,pTVar3,param_8);
        pTVar3 = local_84c + -4;
        local_6c0[0] = local_850;
        do {
          uVar57 = *(uint *)pTVar3;
          if (in_RESERVE != '\0') {
            uVar28 = storeWordConditionalIndexed(uVar57 - 1,0,pTVar3);
            *(uint *)pTVar3 = uVar28;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
        param_2 = extraout_r4_08;
        if ((int)uVar57 < 1) {
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                    ((unsigned char *)(local_84c + -0xc),local_6c0);
          param_2 = extraout_r4_09;
        }
        goto LAB_97bac050;
      }
      param_4 = *(char **)pTVar56;
      local_878 = (unsigned char *)
                  TIntermediate__setAggregateOperator
                            (*(unsigned char **)param_1,*(unsigned char **)(pTVar56 + 8),uVar57,
                             param_4);
    }
LAB_97ba5d80:
    (**(code **)(*(unsigned char **)local_878 + 0x34))(local_878,pTVar3 + 0x1c);
LAB_97ba5e28:
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (a0 != (unsigned char *)0x0) {
      iVar55 = *(int *)a0;
LAB_97ba86fc:
      (**(code **)(iVar55 + 4))(a0);
      pTVar3 = local_878;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
    }
    break;
  case 0xf:
  case 0x10:
    _memcpy(&local_880,pTVar56 + -0x2c,0x2c);
    local_880 = *(uint *)pTVar56;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x11:
    local_870 = *(unsigned char **)(pTVar56 + -0x1c);
    goto LAB_97ba5e64;
  case 0x12:
    local_870 = *(unsigned char **)(pTVar56 + 0x10);
LAB_97ba5e64:
    pTVar3 = (unsigned char *)0x0;
    break;
  case 0x13:
    local_840 = (unsigned char *)0x0;
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar3 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    (**(code **)(**(int **)(pTVar56 + 8) + 0x38))(pTVar3,*(int **)(pTVar56 + 8));
    local_850 = local_840;
    uVar57 = *(uint *)(pTVar56 + -0x1c);
    puVar18 = *(undefined4 **)(uVar57 + 0x14);
    local_84c = pTVar3;
    local_83c = pTVar3;
    if (puVar18 == *(undefined4 **)(uVar57 + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((unsigned char *)(uVar57 + 0xc),
                 *(undefined4 *)(uVar57 + 0x14),&local_850);
    }
    else {
      iVar55 = 0;
      if (puVar18 != (undefined4 *)0x0) {
        puVar18[1] = pTVar3;
        *puVar18 = local_840;
        iVar55 = *(int *)(uVar57 + 0x14);
      }
      *(int *)(uVar57 + 0x14) = iVar55 + 8;
    }
    pTVar3 = local_84c;
    iVar55 = *(int *)(local_84c + 0x14);
    if (iVar55 == 0) {
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      psVar10 = (unsigned char *)TPoolAllocator__allocate(pTVar17,8);
      in_cr0 = (psVar10 == (unsigned char *)0x0) << 1;
      psVar21 = (unsigned char *)0x0;
      if (psVar10 != (unsigned char *)0x0) {
        local_6b0[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(psVar10,"",(unsigned char *)local_6b0)
        ;
        psVar21 = psVar10;
      }
      *(unsigned char **)(pTVar3 + 0x14) = psVar21;
      ((int (*)())TType__buildMangledName)((unsigned char *)pTVar3,psVar21);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(*(void **)(pTVar3 + 0x14),1,0x3b);
      iVar55 = *(int *)(pTVar3 + 0x14);
    }
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_
              ((unsigned char *)&local_840,(unsigned char *)(uVar57 + 0x44),iVar55);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
              ((unsigned char *)(uVar57 + 0x44),(unsigned char *)&local_840);
    pTVar3 = local_83c + -4;
    local_6a0[0] = local_840;
    do {
      uVar57 = *(uint *)pTVar3;
      if (in_RESERVE != '\0') {
        uVar28 = storeWordConditionalIndexed(uVar57 - 1,0,pTVar3);
        *(uint *)pTVar3 = uVar28;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)uVar57 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_6a0);
    }
    local_870 = *(unsigned char **)(pTVar56 + -0x1c);
    pTVar3 = *(unsigned char **)(pTVar56 + 8);
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x14:
    local_840 = (unsigned char *)0x0;
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar3 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    (**(code **)(**(int **)(pTVar56 + 8) + 0x38))(pTVar3,*(int **)(pTVar56 + 8));
    local_850 = local_840;
    uVar57 = *(uint *)(pTVar56 + -0x48);
    puVar18 = *(undefined4 **)(uVar57 + 0x14);
    local_84c = pTVar3;
    local_83c = pTVar3;
    if (puVar18 == *(undefined4 **)(uVar57 + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((unsigned char *)(uVar57 + 0xc),
                 *(undefined4 *)(uVar57 + 0x14),&local_850);
    }
    else {
      iVar55 = 0;
      if (puVar18 != (undefined4 *)0x0) {
        puVar18[1] = pTVar3;
        *puVar18 = local_840;
        iVar55 = *(int *)(uVar57 + 0x14);
      }
      *(int *)(uVar57 + 0x14) = iVar55 + 8;
    }
    pTVar3 = local_84c;
    iVar55 = *(int *)(local_84c + 0x14);
    if (iVar55 == 0) {
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      psVar10 = (unsigned char *)TPoolAllocator__allocate(pTVar17,8);
      in_cr0 = (psVar10 == (unsigned char *)0x0) << 1;
      psVar21 = (unsigned char *)0x0;
      if (psVar10 != (unsigned char *)0x0) {
        local_690[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(psVar10,"",(unsigned char *)local_690)
        ;
        psVar21 = psVar10;
      }
      *(unsigned char **)(pTVar3 + 0x14) = psVar21;
      ((int (*)())TType__buildMangledName)((unsigned char *)pTVar3,psVar21);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(*(void **)(pTVar3 + 0x14),1,0x3b);
      iVar55 = *(int *)(pTVar3 + 0x14);
    }
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_
              ((unsigned char *)&local_840,(unsigned char *)(uVar57 + 0x44),iVar55);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
              ((unsigned char *)(uVar57 + 0x44),(unsigned char *)&local_840);
    pTVar3 = local_83c + -4;
    local_680[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_680);
    }
    local_870 = *(unsigned char **)(pTVar56 + -0x48);
    pTVar15 = *(unsigned char **)param_1;
    pTVar22 = *(unsigned char **)(pTVar56 + -0x50);
    pTVar20 = *(unsigned char **)(pTVar56 + 8);
LAB_97ba97d4:
    param_4 = *(char **)(pTVar56 + -0x2c);
LAB_97ba97d8:
    pTVar3 = (unsigned char *)TIntermediate__growAggregate(pTVar15,pTVar22,pTVar20,(int)param_4);
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x15:
    local_870 = *(unsigned char **)(pTVar56 + -0x1c);
    break;
  case 0x16:
    if (*(uint *)(pTVar56 + 4) != 0x75) {
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      pTVar7 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x54);
      uVar28 = *(uint *)(pTVar56 + 4);
      puVar5 = PTR_vtable_a7b7c0f4 + 8;
      *(uint *)(pTVar7 + 4) = 0;
      *(undefined **)pTVar7 = puVar5;
      local_5c = (unsigned char *)0xa7b8374c;
      local_640 = GetGlobalPoolAllocator();
      *(uint *)(pTVar7 + 0x18) = 0;
      *(uint *)(pTVar7 + 0x10) = 0;
      *(uint *)(pTVar7 + 0x14) = 0;
      *(unsigned char **)(pTVar7 + 0x1c) = local_5c + -0x610c;
      *(uint *)(pTVar7 + 0xc) = local_640;
      iVar55 = DAT_a7b7ba84;
      *(uint *)(pTVar7 + 0x20) = 0;
      uVar57 = *(uint *)(pTVar7 + 0x40) & 0x9ff | 0x800;
      in_cr0 = (uVar57 == 0) << 1;
      *(uint *)(pTVar7 + 0x24) = 0;
      *(uint *)(pTVar7 + 0x40) = uVar57;
      piVar61 = (int *)(iVar55 + 8);
      *(uint *)(pTVar7 + 0x28) = 0;
      *(uint *)(pTVar7 + 0x2c) = 0;
      *(uint *)(pTVar7 + 0x30) = 0;
      *(uint *)(pTVar7 + 0x34) = 0;
      *(uint *)(pTVar7 + 0x38) = 0;
      *(uint *)(pTVar7 + 0x3c) = 0;
      do {
        if (in_RESERVE != '\0') {
          iVar54 = storeWordConditionalIndexed(*piVar61 + 1,0,piVar61);
          *piVar61 = iVar54;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1));
      local_630 = GetGlobalPoolAllocator();
      *(uint *)(pTVar7 + 0x48) = iVar55 + 0xc;
      *(uint *)(pTVar7 + 0x44) = local_630;
      *(uint *)(pTVar7 + 0x4c) = uVar28;
      *(uint *)(pTVar7 + 0x50) = 0;
      pTVar3 = local_878;
      local_870 = pTVar7;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
      break;
    }
    local_670[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              ((unsigned char *)&local_850,"",(unsigned char *)local_670);
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar7 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x54);
    uVar2 = *(uint *)(pTVar56 + 0x24);
    pTVar47 = *(unsigned char **)(pTVar56 + 4);
    *(unsigned char **)pTVar7 = (unsigned char *)(PTR_vtable_a7b7c0f4 + 8);
    *(unsigned char **)(pTVar7 + 4) = (unsigned char *)&local_850;
    local_660 = (unsigned char *)GetGlobalPoolAllocator();
    *(unsigned char **)(pTVar7 + 0x18) = (unsigned char *)0x0;
    *(unsigned char **)(pTVar7 + 0x10) = (unsigned char *)0x0;
    *(unsigned char **)(pTVar7 + 0x14) = (unsigned char *)0x0;
    local_5c = (unsigned char *)0xa7b8374c;
    *(unsigned char **)(pTVar7 + 0xc) = local_660;
    pTVar59 = *(unsigned char **)(uVar2 + 8);
    pTVar34 = *(unsigned char **)(uVar2 + 0xc);
    pTVar32 = *(unsigned char **)(uVar2 + 0x10);
    param_5 = *(char **)(uVar2 + 0x14);
    param_4 = *(char **)(uVar2 + 0x18);
    pTVar31 = *(unsigned char **)(uVar2 + 0x1c);
    pTVar3 = *(unsigned char **)(uVar2 + 4);
    pTVar33 = *(unsigned char **)(uVar2 + 0x20);
    *(undefined ***)(pTVar7 + 0x1c) = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(unsigned char **)(pTVar7 + 0x20) = pTVar3;
    *(unsigned char **)(pTVar7 + 0x24) = pTVar59;
    *(unsigned char **)(pTVar7 + 0x28) = pTVar34;
    *(unsigned char **)(pTVar7 + 0x2c) = pTVar32;
    *(char **)(pTVar7 + 0x30) = param_5;
    *(char **)(pTVar7 + 0x34) = param_4;
    *(unsigned char **)(pTVar7 + 0x38) = pTVar31;
    *(unsigned char **)(pTVar7 + 0x3c) = pTVar33;
    pTVar3 = *(unsigned char **)(pTVar7 + 0x40);
    uVar28 = *(uint *)(uVar2 + 0x24) & 0xfe000000;
    *(unsigned char **)(pTVar7 + 0x40) = (unsigned char *)(uVar28 | (uint)pTVar3 & 0x1ffffff);
    uVar53 = (*(uint *)(uVar2 + 0x24) >> 0x13 & 0x3f) << 0x13;
    *(unsigned char **)(pTVar7 + 0x40) = (unsigned char *)(uVar53 | uVar28 | (uint)pTVar3 & 0x7ffff);
    uVar57 = *(uint *)(uVar2 + 0x24) & 0x7f800;
    *(unsigned char **)(pTVar7 + 0x40) =
         (unsigned char *)(uVar57 | uVar53 | uVar28 | (uint)pTVar3 & 0x7ff);
    uVar58 = (*(uint *)(uVar2 + 0x24) >> 10 & 1) << 10;
    *(unsigned char **)(pTVar7 + 0x40) =
         (unsigned char *)(uVar58 | uVar57 | uVar53 | uVar28 | (uint)pTVar3 & 0x3ff);
    *(unsigned char **)(pTVar7 + 0x40) =
         (unsigned char *)
         ((*(uint *)(uVar2 + 0x24) >> 9 & 1) << 9 |
         uVar58 | uVar57 | uVar53 | uVar28 | (uint)pTVar3 & 0x1ff);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(pTVar7 + 0x44,(unsigned char *)&local_850);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(pTVar7 + 0x44,1,0x28);
    *(unsigned char **)(pTVar7 + 0x4c) = pTVar47;
    *(unsigned char **)(pTVar7 + 0x50) = (unsigned char *)0x0;
    pTVar3 = local_84c + -4;
    local_650[0] = local_850;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    do {
      pTVar33 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar31 = (unsigned char *)storeWordConditionalIndexed(pTVar33 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar31;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)pTVar33;
    ppTVar24 = local_650;
    local_870 = pTVar7;
    goto LAB_97ba869c;
  case 0x17:
    iVar55 = TParseContext__reservedErrorCheck(param_1,*(uint *)pTVar56,*(unsigned char **)(pTVar56 + 4));
    if (iVar55 != 0) {
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
    pTVar7 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x54);
    psVar21 = *(unsigned char **)(pTVar56 + 4);
    *(undefined **)pTVar7 = PTR_vtable_a7b7c0f4 + 8;
    *(unsigned char **)(pTVar7 + 4) = psVar21;
    local_620 = GetGlobalPoolAllocator();
    *(uint *)(pTVar7 + 0x18) = 0;
    *(uint *)(pTVar7 + 0x10) = 0;
    *(uint *)(pTVar7 + 0x14) = 0;
    *(uint *)(pTVar7 + 0xc) = local_620;
    *(unsigned char **)(pTVar7 + 0x20) = local_84c;
    *(unsigned char **)(pTVar7 + 0x24) = local_848;
    *(unsigned char **)(pTVar7 + 0x28) = local_844;
    *(unsigned char **)(pTVar7 + 0x2c) = local_840;
    *(unsigned char **)(pTVar7 + 0x30) = local_83c;
    *(unsigned char **)(pTVar7 + 0x34) = local_838;
    *(undefined ***)(pTVar7 + 0x1c) = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(unsigned char **)(pTVar7 + 0x38) = local_834;
    *(unsigned char **)(pTVar7 + 0x3c) = local_830;
    uVar2 = *(uint *)(pTVar7 + 0x40);
    uVar28 = (uint)local_82c & 0xfe000000;
    *(uint *)(pTVar7 + 0x40) = uVar28 | uVar2 & 0x1ffffff;
    uVar53 = ((uint)local_82c >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar7 + 0x40) = uVar53 | uVar28 | uVar2 & 0x7ffff;
    uVar57 = (uint)local_82c & 0x7f800;
    *(uint *)(pTVar7 + 0x40) = uVar57 | uVar53 | uVar28 | uVar2 & 0x7ff;
    uVar58 = ((uint)local_82c >> 10 & 1) << 10;
    *(uint *)(pTVar7 + 0x40) = uVar58 | uVar57 | uVar53 | uVar28 | uVar2 & 0x3ff;
    *(uint *)(pTVar7 + 0x40) =
         ((uint)local_82c >> 9 & 1) << 9 | uVar58 | uVar57 | uVar53 | uVar28 | uVar2 & 0x1ff;
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(pTVar7 + 0x44,psVar21);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(pTVar7 + 0x44,1,0x28);
    *(uint *)(pTVar7 + 0x50) = 0;
    *(uint *)(pTVar7 + 0x4c) = 0;
    pTVar3 = local_878;
    local_870 = pTVar7;
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x18:
    local_880 = *(uint *)pTVar56;
    local_87c = 0x68;
    break;
  case 0x19:
    local_880 = *(uint *)pTVar56;
    local_87c = 0x66;
    break;
  case 0x1a:
    local_880 = *(uint *)pTVar56;
    local_87c = 0x67;
    break;
  case 0x1b:
    local_880 = *(uint *)pTVar56;
    local_87c = 0x69;
    break;
  case 0x1c:
    local_880 = *(uint *)pTVar56;
    local_87c = 0x6a;
    break;
  case 0x1d:
    local_880 = *(uint *)pTVar56;
    local_87c = 0x6b;
    break;
  case 0x1e:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "bvec2";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ",
                 "bvec2","","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *(uint *)pTVar56;
    local_87c = 0x6c;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x1f:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "bvec3";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ",
                 "bvec3","","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *(uint *)pTVar56;
    local_87c = 0x6d;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x20:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "bvec4";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ",
                 "bvec4","","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *(uint *)pTVar56;
    local_87c = 0x6e;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x21:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "ivec2";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ",
                 "ivec2","","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *(uint *)pTVar56;
    local_87c = 0x6f;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x22:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "ivec3";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ",
                 "ivec3","","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *(uint *)pTVar56;
    local_87c = 0x70;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x23:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "ivec4";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ",
                 "ivec4","","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *(uint *)pTVar56;
    local_87c = 0x71;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x24:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "mat2";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ","mat2"
                 ,"","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *(uint *)pTVar56;
    local_87c = 0x72;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x25:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "mat3";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ","mat3"
                 ,"","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *(uint *)pTVar56;
    local_87c = 0x73;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x26:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "mat4";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ","mat4"
                 ,"","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *(uint *)pTVar56;
    local_87c = 0x74;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x27:
    local_85c = (unsigned char *)(*(uint *)(pTVar56 + 8) + 0xc);
    local_830 = (unsigned char *)0xe;
    local_824 = (unsigned char *)0x0;
    local_820 = (unsigned char *)0x0;
    local_86c = (unsigned char *)
                (uint)((uint)((*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4) >> 2)
                      < 4);
    local_828 = (unsigned char *)0x1;
    local_858 = *(unsigned char **)pTVar56;
    local_860 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_864 = (unsigned char *)0x0;
    local_87c = 0x75;
    local_870 = (unsigned char *)0xe;
    local_868 = (unsigned char *)0x1;
    local_850 = (unsigned char *)0xe;
    local_848 = (unsigned char *)0x1;
    local_880 = *(uint *)pTVar56;
    local_84c = local_86c;
    local_83c = local_85c;
    local_838 = local_858;
    local_82c = local_86c;
    local_81c = local_85c;
    local_818 = local_858;
    break;
  case 0x29:
    iVar55 = TParseContext__lValueErrorCheck
                       (param_1,*(uint *)(pTVar56 + -0x2c),"++",*(unsigned char **)(pTVar56 + 8),
                        param_5,pTVar33,pTVar34,param_8);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    param_4 = *(char **)(pTVar56 + -0x2c);
    param_5 = *(char **)((int)param_1 + 4);
    local_878 = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(unsigned char **)param_1,0xb,*(uint *)(pTVar56 + 8),param_4,param_5,
                           pTVar33,pTVar34);
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_4 = (char *)&local_850;
    TType__getCompleteString(param_4,*(uint *)(pTVar56 + 8) + 8);
    TParseContext__unaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),"++",param_4);
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_610[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)pTVar7;
    ppTVar24 = local_610;
    goto LAB_97ba82d4;
  case 0x2a:
    iVar55 = TParseContext__lValueErrorCheck
                       (param_1,*(uint *)(pTVar56 + -0x2c),"--",*(unsigned char **)(pTVar56 + 8),
                        param_5,pTVar33,pTVar34,param_8);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    param_4 = *(char **)(pTVar56 + -0x2c);
    param_5 = *(char **)((int)param_1 + 4);
    local_878 = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(unsigned char **)param_1,0xc,*(uint *)(pTVar56 + 8),param_4,param_5,
                           pTVar33,pTVar34);
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_4 = (char *)&local_850;
    TType__getCompleteString(param_4,*(uint *)(pTVar56 + 8) + 8);
    TParseContext__unaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),"--",param_4);
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_600[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      ppTVar24 = local_600;
      goto LAB_97ba69a8;
    }
    goto LAB_97ba82f0;
  case 0x2b:
    if (*(uint *)(pTVar56 + -0x28) == 0) goto switchD_97ba39c8_caseD_2;
    param_4 = *(char **)(pTVar56 + -0x2c);
    param_5 = *(char **)((int)param_1 + 4);
    local_878 = (unsigned char *)
                TIntermediate__addUnaryMath
                          (*(unsigned char **)param_1,*(uint *)(pTVar56 + -0x28),
                           *(uint *)(pTVar56 + 8),param_4,param_5,pTVar33,pTVar34);
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    uVar57 = *(uint *)(pTVar56 + -0x28);
    pcVar62 = "";
    if (uVar57 == 6) {
      pcVar62 = "!";
    }
    else if ((int)uVar57 < 7) {
      if (uVar57 == 5) {
        pcVar62 = "-";
      }
    }
    else if (uVar57 == 8) {
      pcVar62 = "~";
    }
    param_4 = (char *)&local_850;
    TType__getCompleteString(param_4,*(uint *)(pTVar56 + 8) + 8);
    TParseContext__unaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),pcVar62,param_4);
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_5f0[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)pTVar7;
    ppTVar24 = local_5f0;
    goto LAB_97ba82d4;
  case 0x2c:
    local_880 = *(uint *)pTVar56;
    local_87c = 0;
    break;
  case 0x2d:
    local_880 = *(uint *)pTVar56;
    local_87c = 5;
    break;
  case 0x2e:
    local_880 = *(uint *)pTVar56;
    local_87c = 6;
    break;
  case 0x2f:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      param_5 = "";
      param_4 = "~";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," reserved for future use ","~","","",pTVar34,
                 param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *(uint *)pTVar56;
    local_87c = 8;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x31:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + -0x2c),
                 " supported in vertex/fragment shaders only ","*","","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x15,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    param_4 = (char *)&local_840;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(param_4,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),"*",param_4,param_5);
    pTVar3 = local_83c + -4;
    local_5e0[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_5e0);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_5d0[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)pTVar7;
    ppTVar24 = local_5d0;
    goto LAB_97ba7a00;
  case 0x32:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + -0x2c),
                 " supported in vertex/fragment shaders only ","/","","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x16,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    param_4 = (char *)&local_840;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(param_4,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),"/",param_4,param_5);
    pTVar3 = local_83c + -4;
    local_5c0[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_5c0);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_5b0[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)pTVar7;
    ppTVar24 = local_5b0;
    goto LAB_97ba7a00;
  case 0x33:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + -0x2c)," reserved for future use ","%","","",
                 pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x17,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    param_4 = (char *)&local_840;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(param_4,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),"%",param_4,param_5);
    pTVar3 = local_83c + -4;
    local_5a0[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_5a0);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_590[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)pTVar7;
    ppTVar24 = local_590;
    goto LAB_97ba7a00;
  case 0x35:
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x13,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    param_4 = (char *)&local_840;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(param_4,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),"+",param_4,param_5);
    pTVar3 = local_83c + -4;
    local_580[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_580);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_570[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)pTVar7;
    ppTVar24 = local_570;
    goto LAB_97ba7a00;
  case 0x36:
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x14,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    param_4 = (char *)&local_840;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(param_4,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),"-",param_4,param_5);
    pTVar3 = local_83c + -4;
    local_560[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_560);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_550[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)pTVar7;
    ppTVar24 = local_550;
    goto LAB_97ba7a00;
  case 0x38:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + -0x2c)," reserved for future use ","<<","","",
                 pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x19,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    param_4 = (char *)&local_840;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(param_4,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),"<<",param_4,param_5);
    pTVar3 = local_83c + -4;
    local_540[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_540);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_530[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)pTVar7;
    ppTVar24 = local_530;
    goto LAB_97ba7a00;
  case 0x39:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + -0x2c)," reserved for future use ",">>","","",
                 pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x18,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    param_4 = (char *)&local_840;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(param_4,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),">>",param_4,param_5);
    pTVar3 = local_83c + -4;
    local_520[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_520);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_510[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)pTVar7;
    ppTVar24 = local_510;
    goto LAB_97ba7a00;
  case 0x3b:
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x21,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(&local_840,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),"<",&local_840,param_5);
    pTVar3 = local_83c + -4;
    local_500[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_500);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_4f0[0] = local_850;
    do {
      uVar57 = *(uint *)pTVar3;
      if (in_RESERVE != '\0') {
        uVar28 = storeWordConditionalIndexed(uVar57 - 1,0,pTVar3);
        *(uint *)pTVar3 = uVar28;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)uVar57;
    ppTVar24 = local_4f0;
    goto LAB_97ba7bac;
  case 0x3c:
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x22,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(&local_840,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),">",&local_840,param_5);
    pTVar3 = local_83c + -4;
    local_4e0[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_4e0);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_4d0[0] = local_850;
    do {
      uVar57 = *(uint *)pTVar3;
      if (in_RESERVE != '\0') {
        uVar28 = storeWordConditionalIndexed(uVar57 - 1,0,pTVar3);
        *(uint *)pTVar3 = uVar28;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)uVar57;
    ppTVar24 = local_4d0;
    goto LAB_97ba7bac;
  case 0x3d:
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x23,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(&local_840,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),"<=",&local_840,param_5);
    pTVar3 = local_83c + -4;
    local_4c0[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_4c0);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_4b0[0] = local_850;
    do {
      uVar57 = *(uint *)pTVar3;
      if (in_RESERVE != '\0') {
        uVar28 = storeWordConditionalIndexed(uVar57 - 1,0,pTVar3);
        *(uint *)pTVar3 = uVar28;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)uVar57;
    ppTVar24 = local_4b0;
    goto LAB_97ba7bac;
  case 0x3e:
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x24,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(&local_840,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),">=",&local_840,param_5);
    pTVar3 = local_83c + -4;
    local_4a0[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_4a0);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_490[0] = local_850;
    do {
      uVar57 = *(uint *)pTVar3;
      if (in_RESERVE != '\0') {
        uVar28 = storeWordConditionalIndexed(uVar57 - 1,0,pTVar3);
        *(uint *)pTVar3 = uVar28;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)uVar57;
    ppTVar24 = local_490;
    goto LAB_97ba7bac;
  case 0x40:
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x1d,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(&local_840,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),"==",&local_840,param_5);
    pTVar3 = local_83c + -4;
    local_480[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_480);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_470[0] = local_850;
    do {
      uVar57 = *(uint *)pTVar3;
      if (in_RESERVE != '\0') {
        uVar28 = storeWordConditionalIndexed(uVar57 - 1,0,pTVar3);
        *(uint *)pTVar3 = uVar28;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)uVar57;
    ppTVar24 = local_470;
    goto LAB_97ba7bac;
  case 0x41:
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x1e,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(&local_840,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),"!=",&local_840,param_5);
    pTVar3 = local_83c + -4;
    local_460[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_460);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_450[0] = local_850;
    do {
      uVar57 = *(uint *)pTVar3;
      if (in_RESERVE != '\0') {
        uVar28 = storeWordConditionalIndexed(uVar57 - 1,0,pTVar3);
        *(uint *)pTVar3 = uVar28;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)uVar57;
    ppTVar24 = local_450;
    goto LAB_97ba7bac;
  case 0x43:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + -0x2c)," reserved for future use ","&","","",
                 pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x1a,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    param_4 = (char *)&local_840;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(param_4,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),"&",param_4,param_5);
    pTVar3 = local_83c + -4;
    local_440[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_440);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_430[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)pTVar7;
    ppTVar24 = local_430;
    goto LAB_97ba7a00;
  case 0x45:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + -0x2c)," reserved for future use ","^","","",
                 pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x1c,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    param_4 = (char *)&local_840;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(param_4,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),"^",param_4,param_5);
    pTVar3 = local_83c + -4;
    local_420[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_420);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_410[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)pTVar7;
    ppTVar24 = local_410;
    goto LAB_97ba7a00;
  case 0x47:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + -0x2c)," reserved for future use ","|","","",
                 pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x1b,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    param_4 = (char *)&local_840;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(param_4,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),"|",param_4,param_5);
    pTVar3 = local_83c + -4;
    local_400[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_400);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_3f0[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)pTVar7;
    ppTVar24 = local_3f0;
LAB_97ba7a00:
    if (!bVar37) {
LAB_97ba7f84:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(paVar11,ppTVar24);
    }
LAB_97ba5554:
    TParseContext__recover(param_1);
    pTVar3 = *(unsigned char **)(pTVar56 + -0x50);
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x49:
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x2c,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(&local_840,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),"&&",&local_840,param_5);
    pTVar3 = local_83c + -4;
    local_3e0[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_3e0);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_3d0[0] = local_850;
    do {
      uVar57 = *(uint *)pTVar3;
      if (in_RESERVE != '\0') {
        uVar28 = storeWordConditionalIndexed(uVar57 - 1,0,pTVar3);
        *(uint *)pTVar3 = uVar28;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)uVar57;
    ppTVar24 = local_3d0;
    goto LAB_97ba7bac;
  case 0x4b:
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x2b,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(&local_840,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),"^^",&local_840,param_5);
    pTVar3 = local_83c + -4;
    local_3c0[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_3c0);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_3b0[0] = local_850;
    do {
      uVar57 = *(uint *)pTVar3;
      if (in_RESERVE != '\0') {
        uVar28 = storeWordConditionalIndexed(uVar57 - 1,0,pTVar3);
        *(uint *)pTVar3 = uVar28;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)uVar57;
    ppTVar24 = local_3b0;
LAB_97ba7bac:
    if (!bVar37) {
LAB_97ba7c88:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(paVar11,ppTVar24);
    }
LAB_97ba7c8c:
    pTVar3 = (unsigned char *)0x0;
    TParseContext__recover(param_1);
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pcVar9 = (unsigned char *)TPoolAllocator__allocate(pTVar17,4);
    *(undefined4 *)pcVar9 = 0;
    local_82c = (unsigned char *)((uint)local_82c & 0x1801ff | 0x4180800);
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    pTVar15 = *(unsigned char **)param_1;
    param_4 = *(char **)(pTVar56 + -0x2c);
    local_84c = pTVar3;
    local_848 = pTVar3;
    local_844 = pTVar3;
    local_840 = pTVar3;
    local_83c = pTVar3;
    local_838 = pTVar3;
    local_834 = pTVar3;
    local_830 = pTVar3;
LAB_97ba7d0c:
    pTVar7 = local_850;
    pTVar3 = (unsigned char *)
             TIntermediate__addConstantUnion(pTVar15,pcVar9,(unsigned char *)&local_850,(int)param_4);
    local_850 = pTVar7;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x4d:
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addBinaryMath
                          (*(unsigned char **)param_1,0x2a,*(uint *)(pTVar56 + -0x50),param_4,
                           param_5,*(undefined4 *)((int)param_1 + 4));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(&local_840,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),"||",&local_840,param_5);
    pTVar3 = local_83c + -4;
    local_3a0[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_3a0);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_390[0] = local_850;
    do {
      uVar57 = *(uint *)pTVar3;
      if (in_RESERVE != '\0') {
        uVar28 = storeWordConditionalIndexed(uVar57 - 1,0,pTVar3);
        *(uint *)pTVar3 = uVar28;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)uVar57 < 1) {
      ppTVar24 = local_390;
      goto LAB_97ba7c88;
    }
    goto LAB_97ba7c8c;
  case 0x4f:
    iVar55 = __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped
                       (param_1,*(uint *)(pTVar56 + -0x84),*(unsigned char **)(pTVar56 + -0xa8),
                        param_4,param_5,pTVar33);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    pTVar7 = (unsigned char *)&local_850;
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x84);
    local_878 = (unsigned char *)
                __ZN13TIntermediate12addSelectionEP12TIntermTypedS1_S1_i
                          (*(void **)param_1,*(unsigned char **)(pTVar56 + -0xa8),
                           *(unsigned char **)(pTVar56 + -0x50),(unsigned char *)param_4,(int)param_5)
    ;
    (**(code **)(**(int **)(pTVar56 + -0x50) + 0x38))(pTVar7,*(int **)(pTVar56 + -0x50));
    (**(code **)(**(int **)(pTVar56 + 8) + 0x38))(&local_820,*(int **)(pTVar56 + 8));
    bVar37 = false;
    if ((((uint)local_82c & 0x1fffe00) == ((uint)local_7fc & 0x1fffe00)) && (local_848 == local_818)
       ) {
      bVar37 = true;
    }
    local_5c = (unsigned char *)0xa7b8374c;
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    local_820 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    if (!bVar37) {
      local_878 = (unsigned char *)0x0;
    }
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_4 = (char *)&local_840;
    TType__getCompleteString(pTVar7,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(param_4,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x84),":",param_4,pTVar7);
    pTVar3 = local_83c + -4;
    local_380[0] = local_840;
    do {
      pTVar33 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar31 = (unsigned char *)storeWordConditionalIndexed(pTVar33 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar31;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar33 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_380);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_370[0] = local_850;
    do {
      pTVar33 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar31 = (unsigned char *)storeWordConditionalIndexed(pTVar33 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar31;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)pTVar33;
    ppTVar24 = local_370;
    param_5 = (char *)pTVar7;
    goto LAB_97ba82d4;
  case 0x51:
    iVar55 = TParseContext__lValueErrorCheck
                       (param_1,*(uint *)(pTVar56 + -0x2c),"assign",
                        *(unsigned char **)(pTVar56 + -0x50),param_5,pTVar33,pTVar34,param_8);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    param_4 = *(char **)(pTVar56 + 8);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addAssign
                          (*(unsigned char **)param_1,*(uint *)(pTVar56 + -0x28),
                           *(uint *)(pTVar56 + -0x50),param_4,param_5);
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    param_4 = (char *)&local_840;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(param_4,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__assignError(param_1,*(uint *)(pTVar56 + -0x2c),"assign",param_4,param_5);
    pTVar3 = local_83c + -4;
    local_360[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_360);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_350[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (0 < (int)pTVar7) goto LAB_97ba5554;
    ppTVar24 = local_350;
    goto LAB_97ba7f84;
  case 0x52:
    local_880 = *(uint *)pTVar56;
    local_87c = 0x76;
    break;
  case 0x53:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "*=";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ","*=",
                 "","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *(uint *)pTVar56;
    local_87c = 0x79;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x54:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "/=";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ","/=",
                 "","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *(uint *)pTVar56;
    local_87c = 0x7e;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x55:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      param_5 = "";
      param_4 = "%=";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," reserved for future use ","%=","","",pTVar34,
                 param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *(uint *)pTVar56;
    local_87c = 0x7f;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x56:
    local_880 = *(uint *)pTVar56;
    local_87c = 0x77;
    break;
  case 0x57:
    local_880 = *(uint *)pTVar56;
    local_87c = 0x78;
    break;
  case 0x58:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      param_5 = "";
      param_4 = "<<=";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," reserved for future use ","<<=","","",pTVar34,
                 param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *(uint *)pTVar56;
    local_87c = 0x83;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x59:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      param_5 = "";
      param_4 = "<<=";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," reserved for future use ","<<=","","",pTVar34,
                 param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *(uint *)pTVar56;
    local_87c = 0x84;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x5a:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      param_5 = "";
      param_4 = "&=";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," reserved for future use ","&=","","",pTVar34,
                 param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *(uint *)pTVar56;
    local_87c = 0x80;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x5b:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      param_5 = "";
      param_4 = "^=";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," reserved for future use ","^=","","",pTVar34,
                 param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *(uint *)pTVar56;
    local_87c = 0x82;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x5c:
    if (1 < *(int *)((int)param_1 + 0xc) - 2U) {
      param_5 = "";
      param_4 = "|=";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," reserved for future use ","|=","","",pTVar34,
                 param_8);
      TParseContext__recover(param_1);
    }
    local_880 = *(uint *)pTVar56;
    local_87c = 0x81;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x5e:
    param_4 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TIntermediate__addComma
                          (*(unsigned char **)param_1,*(unsigned char **)(pTVar56 + -0x50),
                           *(unsigned char **)(pTVar56 + 8),(int)param_4);
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (local_878 != (unsigned char *)0x0) break;
    param_5 = (char *)&local_850;
    param_4 = (char *)&local_840;
    TType__getCompleteString(param_5,*(uint *)(pTVar56 + 8) + 8);
    TType__getCompleteString(param_4,*(uint *)(pTVar56 + -0x50) + 8);
    TParseContext__binaryOpError(param_1,*(uint *)(pTVar56 + -0x2c),",",param_4,param_5);
    pTVar3 = local_83c + -4;
    local_340[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_340);
    }
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_330[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)pTVar7;
    ppTVar24 = local_330;
LAB_97ba82d4:
    if (!bVar37) {
LAB_97ba69a8:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(paVar11,ppTVar24);
    }
LAB_97ba82f0:
    TParseContext__recover(param_1);
switchD_97ba39c8_caseD_2:
    pTVar3 = *(unsigned char **)(pTVar56 + 8);
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x5f:
    iVar55 = TParseContext__constErrorCheck(param_1,*(unsigned char **)(pTVar56 + 8));
LAB_97ba82e8:
    if (iVar55 != 0) goto LAB_97ba82f0;
    goto switchD_97ba39c8_caseD_2;
  case 0x60:
  case 0xb0:
  case 0xb6:
  case 0xba:
  case 0xca:
    goto switchD_97ba39c8_caseD_60;
  case 0x61:
  case 0xb7:
    piVar61 = *(int **)(pTVar56 + -0x24);
    pTVar3 = (unsigned char *)0x0;
    if (piVar61 != (int *)0x0) {
      (**(code **)(*piVar61 + 0x60))(piVar61,1);
      pTVar3 = *(unsigned char **)(pTVar56 + -0x24);
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
    }
    break;
  case 0x62:
    piVar61 = *(int **)((int)param_1 + 4);
    pcVar62 = (char *)(**(code **)(**(int **)(pTVar56 + -0x1c) + 8))(*(int **)(pTVar56 + -0x1c));
    iVar55 = *piVar61;
    iVar54 = (piVar61[1] - iVar55 >> 2) + -1;
    goto LAB_97ba8338;
  case 99:
  case 100:
  case 0xa0:
    local_870 = *(unsigned char **)(pTVar56 + 0x10);
    break;
  case 0x65:
    local_870 = *(unsigned char **)(pTVar56 + -0x1c);
    iVar55 = (**(code **)(**(int **)(pTVar56 + 0x14) + 0x20))
                       (*(int **)(pTVar56 + 0x14),param_2,param_3,param_4,param_5,pTVar33,pTVar34);
    if (iVar55 == 0) {
LAB_97ba86ec:
      a0 = *(unsigned char **)(pTVar56 + 0x14);
      pTVar3 = local_878;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
      if (a0 == (unsigned char *)0x0) break;
      iVar55 = *(int *)a0;
      goto LAB_97ba86fc;
    }
    uVar57 = *(uint *)(pTVar56 + -0x1c);
    puVar25 = *(uint **)(uVar57 + 0x14);
    if (puVar25 == *(uint **)(uVar57 + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((unsigned char *)(uVar57 + 0xc),
                 *(undefined4 *)(uVar57 + 0x14),pTVar56 + 0x10);
    }
    else {
      iVar55 = 0;
      if (puVar25 != (uint *)0x0) {
        uVar28 = *(uint *)(pTVar56 + 0x14);
        *puVar25 = *(uint *)(pTVar56 + 0x10);
        puVar25[1] = uVar28;
        iVar55 = *(int *)(uVar57 + 0x14);
      }
      *(int *)(uVar57 + 0x14) = iVar55 + 8;
    }
    pTVar12 = *(unsigned char **)(pTVar56 + 0x14);
    iVar55 = *(int *)(pTVar12 + 0x14);
    if (iVar55 == 0) {
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      psVar10 = (unsigned char *)TPoolAllocator__allocate(pTVar17,8);
      in_cr0 = (psVar10 == (unsigned char *)0x0) << 1;
      psVar21 = (unsigned char *)0x0;
      if (psVar10 != (unsigned char *)0x0) {
        local_2f0[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(psVar10,"",(unsigned char *)local_2f0)
        ;
        psVar21 = psVar10;
      }
      *(unsigned char **)(pTVar12 + 0x14) = psVar21;
      ((int (*)())TType__buildMangledName)(pTVar12,psVar21);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(*(void **)(pTVar12 + 0x14),1,0x3b);
      iVar55 = *(int *)(pTVar12 + 0x14);
    }
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_
              ((unsigned char *)&local_850,(unsigned char *)(uVar57 + 0x44),iVar55);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
              ((unsigned char *)(uVar57 + 0x44),(unsigned char *)&local_850);
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_2e0[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    bVar37 = 0 < (int)pTVar7;
    ppTVar24 = local_2e0;
LAB_97ba869c:
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (!bVar37) {
LAB_97ba8824:
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_(paVar11,ppTVar24);
      pTVar3 = local_878;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
    }
    break;
  case 0x66:
    iVar55 = (**(code **)(**(int **)(pTVar56 + 0x14) + 0x20))(*(int **)(pTVar56 + 0x14));
    if (iVar55 == 0) {
      param_4 = "void";
      param_5 = "";
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + -0x2c),
                 "cannot be an argument type except for \'(void)\'","void","",pTVar33,pTVar34,
                 param_8);
      TParseContext__recover(param_1);
      goto LAB_97ba86ec;
    }
    local_870 = *(unsigned char **)(pTVar56 + -0x48);
    uVar57 = *(uint *)(pTVar56 + -0x48);
    puVar25 = *(uint **)(uVar57 + 0x14);
    if (puVar25 == *(uint **)(uVar57 + 0x18)) {
      std__vector_TParameter_pool_allocator_TParameter_____M_insert_aux
                ((unsigned char *)(uVar57 + 0xc),
                 *(undefined4 *)(uVar57 + 0x14),pTVar56 + 0x10);
    }
    else {
      iVar55 = 0;
      if (puVar25 != (uint *)0x0) {
        uVar28 = *(uint *)(pTVar56 + 0x14);
        *puVar25 = *(uint *)(pTVar56 + 0x10);
        puVar25[1] = uVar28;
        iVar55 = *(int *)(uVar57 + 0x14);
      }
      *(int *)(uVar57 + 0x14) = iVar55 + 8;
    }
    pTVar12 = *(unsigned char **)(pTVar56 + 0x14);
    iVar55 = *(int *)(pTVar12 + 0x14);
    if (iVar55 == 0) {
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      psVar10 = (unsigned char *)TPoolAllocator__allocate(pTVar17,8);
      in_cr0 = (psVar10 == (unsigned char *)0x0) << 1;
      psVar21 = (unsigned char *)0x0;
      if (psVar10 != (unsigned char *)0x0) {
        local_2d0[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_(psVar10,"",(unsigned char *)local_2d0)
        ;
        psVar21 = psVar10;
      }
      *(unsigned char **)(pTVar12 + 0x14) = psVar21;
      ((int (*)())TType__buildMangledName)(pTVar12,psVar21);
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(*(void **)(pTVar12 + 0x14),1,0x3b);
      iVar55 = *(int *)(pTVar12 + 0x14);
    }
    __ZStplIcSt11char_traitsIcE14pool_allocatorIcEESbIT_T0_T1_ERKS7_S9_
              ((unsigned char *)&local_850,(unsigned char *)(uVar57 + 0x44),iVar55);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6assignERKS3_
              ((unsigned char *)(uVar57 + 0x44),(unsigned char *)&local_850);
    pTVar3 = local_84c + -4;
    paVar11 = (unsigned char *)(local_84c + -0xc);
    local_2c0[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (0 < (int)pTVar7) break;
    ppTVar24 = local_2c0;
    goto LAB_97ba8824;
  case 0x67:
    if (1 < *(uint *)(pTVar56 + -0x44)) {
      param_4 = (char *)getQualifierString(*(uint *)(pTVar56 + -0x44));
      param_5 = "";
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + -0x2c),
                 "no qualifiers allowed for function return",param_4,"",pTVar33,pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    iVar55 = TParseContext__structQualifierErrorCheck
                       (param_1,*(uint *)(pTVar56 + -0x2c),(unsigned char *)(pTVar56 + -0x48),param_4,
                        param_5,pTVar33,pTVar34);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    local_820 = *(unsigned char **)(pTVar56 + -0x48);
    local_81c = *(unsigned char **)(pTVar56 + -0x44);
    param_5 = *(char **)(pTVar56 + -0x40);
    param_4 = *(char **)(pTVar56 + -0x3c);
    local_80c = *(unsigned char **)(pTVar56 + -0x34);
    local_810 = *(unsigned char **)(pTVar56 + -0x38);
    local_5c = (unsigned char *)0xa7b8374c;
    pTVar7 = *(unsigned char **)(pTVar56 + -0x30);
    local_82c = (unsigned char *)
                (((uint)local_810 & 1) << 9 |
                ((uint)param_4 & 1) << 10 |
                ((uint)param_5 & 0xff) << 0xb |
                ((uint)local_820 & 0x3f) << 0x13 | (int)local_81c << 0x19 | (uint)local_82c & 0x1ff)
    ;
    local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
    local_830 = (unsigned char *)0x0;
    local_84c = (unsigned char *)0x0;
    local_848 = (unsigned char *)0x0;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_838 = (unsigned char *)0x0;
    local_834 = (unsigned char *)0x0;
    pTVar3 = local_840;
    local_818 = (unsigned char *)param_5;
    local_814 = (unsigned char *)param_4;
    local_808 = pTVar7;
    local_800 = local_820;
    local_7fc = local_81c;
    local_7f8 = (unsigned char *)param_5;
    local_7f4 = (unsigned char *)param_4;
    local_7f0 = local_810;
    local_7ec = local_80c;
    local_7e8 = pTVar7;
    if (local_80c != (unsigned char *)0x0) {
      local_848 = *(unsigned char **)(local_80c + 8);
      uVar16 = 0xa7b8374c;
      local_64 = (unsigned char *)0xa7b8374c;
      uVar64 = TType__setStructSize((unsigned char *)&local_850,*(unsigned char **)(local_80c + 8));
      local_838 = (unsigned char *)((ulonglong)uVar64 >> 0x20);
      iVar55 = (**(code **)(*(uint *)local_7ec + 0x18))
                         (local_7ec,(int)uVar64,pTVar7,param_4,param_5,uVar16,*(uint *)local_7ec);
      *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
           **(undefined1 **)(local_64 + -0x7cc4);
      pcVar62 = *(char **)(iVar55 + 4);
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      pTVar7 = (unsigned char *)TPoolAllocator__allocate(pTVar17,8);
      in_cr0 = (pTVar7 == (unsigned char *)0x0) << 1;
      pTVar3 = (unsigned char *)0x0;
      if (pTVar7 != (unsigned char *)0x0) {
        local_2b0[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (pTVar7,pcVar62,(unsigned char *)local_2b0);
        pTVar3 = pTVar7;
      }
    }
    local_840 = pTVar3;
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar7 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x54);
    psVar21 = *(unsigned char **)(pTVar56 + -0x28);
    *(undefined **)pTVar7 = PTR_vtable_a7b7c0f4 + 8;
    *(unsigned char **)(pTVar7 + 4) = psVar21;
    local_2a0 = GetGlobalPoolAllocator();
    *(uint *)(pTVar7 + 0x18) = 0;
    *(uint *)(pTVar7 + 0x10) = 0;
    *(uint *)(pTVar7 + 0x14) = 0;
    *(uint *)(pTVar7 + 0xc) = local_2a0;
    *(unsigned char **)(pTVar7 + 0x20) = local_84c;
    pTVar33 = local_5c + -0x610c;
    *(unsigned char **)(pTVar7 + 0x24) = local_848;
    *(unsigned char **)(pTVar7 + 0x28) = local_844;
    *(unsigned char **)(pTVar7 + 0x2c) = local_840;
    *(unsigned char **)(pTVar7 + 0x30) = local_83c;
    *(unsigned char **)(pTVar7 + 0x34) = local_838;
    *(unsigned char **)(pTVar7 + 0x1c) = pTVar33;
    *(unsigned char **)(pTVar7 + 0x38) = local_834;
    *(unsigned char **)(pTVar7 + 0x3c) = local_830;
    uVar2 = *(uint *)(pTVar7 + 0x40);
    uVar28 = (uint)local_82c & 0xfe000000;
    *(uint *)(pTVar7 + 0x40) = uVar28 | uVar2 & 0x1ffffff;
    uVar53 = ((uint)local_82c >> 0x13 & 0x3f) << 0x13;
    *(uint *)(pTVar7 + 0x40) = uVar53 | uVar28 | uVar2 & 0x7ffff;
    uVar57 = (uint)local_82c & 0x7f800;
    *(uint *)(pTVar7 + 0x40) = uVar57 | uVar53 | uVar28 | uVar2 & 0x7ff;
    uVar58 = ((uint)local_82c >> 10 & 1) << 10;
    *(uint *)(pTVar7 + 0x40) = uVar58 | uVar57 | uVar53 | uVar28 | uVar2 & 0x3ff;
    *(uint *)(pTVar7 + 0x40) =
         ((uint)local_82c >> 9 & 1) << 9 | uVar58 | uVar57 | uVar53 | uVar28 | uVar2 & 0x1ff;
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(pTVar7 + 0x44,psVar21);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE6appendEmc(pTVar7 + 0x44,1,0x28);
    *(uint *)(pTVar7 + 0x50) = 0;
    *(uint *)(pTVar7 + 0x4c) = 0;
    pTVar3 = local_878;
    local_870 = pTVar7;
    local_850 = pTVar33;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x68:
    if (*(uint *)(pTVar56 + -0x1c) == 0) {
      uVar57 = *(uint *)(pTVar56 + 4);
      local_64 = (unsigned char *)0xa7b8374c;
      iVar55 = *(int *)(uVar57 + 4);
      *(unsigned char *)(iVar55 + *(int *)(iVar55 + -0xc)) = *DAT_a7b7ba88;
      TParseContext__error
                ((int)param_1,*(char **)pTVar56,"illegal use of type \'void\'",
                 *(char **)(uVar57 + 4),"",pTVar33,iVar55,uVar57);
      TParseContext__recover(param_1);
    }
    iVar55 = TParseContext__reservedErrorCheck(param_1,*(uint *)pTVar56,*(unsigned char **)(pTVar56 + 4));
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    local_840 = *(unsigned char **)(pTVar56 + 4);
    local_5c = (unsigned char *)0xa7b8374c;
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar12 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    local_830 = *(unsigned char **)(pTVar56 + -0x1c);
    local_82c = *(unsigned char **)(pTVar56 + -0x18);
    local_828 = *(unsigned char **)(pTVar56 + -0x14);
    local_824 = *(unsigned char **)(pTVar56 + -0x10);
    param_5 = *(char **)(pTVar56 + -0xc);
    param_4 = *(char **)(pTVar56 + -8);
    local_818 = *(unsigned char **)(pTVar56 + -4);
    *(unsigned char **)pTVar12 = local_5c + -0x610c;
    *(undefined4 *)(pTVar12 + 0x20) = 0;
    *(undefined4 *)(pTVar12 + 4) = 0;
    *(undefined4 *)(pTVar12 + 8) = 0;
    *(undefined4 *)(pTVar12 + 0xc) = 0;
    *(undefined4 *)(pTVar12 + 0x10) = 0;
    *(undefined4 *)(pTVar12 + 0x14) = 0;
    *(undefined4 *)(pTVar12 + 0x18) = 0;
    *(undefined4 *)(pTVar12 + 0x1c) = 0;
    uVar2 = *(uint *)(pTVar12 + 0x24);
    uVar57 = (int)local_82c << 0x19;
    *(uint *)(pTVar12 + 0x24) = uVar57 | uVar2 & 0x1ffffff;
    uVar28 = ((uint)local_830 & 0x3f) << 0x13;
    *(uint *)(pTVar12 + 0x24) = uVar28 | uVar57 | uVar2 & 0x7ffff;
    uVar53 = ((uint)local_828 & 0xff) << 0xb;
    *(uint *)(pTVar12 + 0x24) = uVar53 | uVar28 | uVar57 | uVar2 & 0x7ff;
    uVar58 = ((uint)local_824 & 1) << 10;
    *(uint *)(pTVar12 + 0x24) = uVar58 | uVar53 | uVar28 | uVar57 | uVar2 & 0x3ff;
    *(uint *)(pTVar12 + 0x24) =
         ((uint)param_5 & 1) << 9 | uVar58 | uVar53 | uVar28 | uVar57 | uVar2 & 0x1ff;
    local_820 = (unsigned char *)param_5;
    local_81c = (unsigned char *)param_4;
    local_810 = local_830;
    local_80c = local_82c;
    local_808 = local_828;
    local_804 = local_824;
    local_800 = (unsigned char *)param_5;
    local_7fc = (unsigned char *)param_4;
    local_7f8 = local_818;
    if ((unsigned char *)param_4 != (unsigned char *)0x0) {
      local_64 = (unsigned char *)0xa7b8374c;
      *(uint *)(pTVar12 + 8) = *(uint *)(param_4 + 8);
      uVar16 = TType__setStructSize(pTVar12,*(unsigned char **)(param_4 + 8));
      *(undefined4 *)(pTVar12 + 0x18) = uVar16;
      iVar55 = (**(code **)(*(uint *)local_7fc + 0x18))(local_7fc);
      *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
           **(undefined1 **)(local_64 + -0x7cc4);
      pcVar62 = *(char **)(iVar55 + 4);
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      pvVar13 = (void *)TPoolAllocator__allocate(pTVar17,8);
      in_cr0 = (pvVar13 == (void *)0x0) << 1;
      pvVar23 = (void *)0x0;
      if (pvVar13 != (void *)0x0) {
        local_290[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (pvVar13,pcVar62,(unsigned char *)local_290);
        pvVar23 = pvVar13;
      }
      *(void **)(pTVar12 + 0x10) = pvVar23;
    }
    local_850 = local_840;
    local_880 = *(uint *)pTVar56;
    pTVar3 = local_878;
    local_870 = local_850;
    local_86c = (unsigned char *)pTVar12;
    local_84c = (unsigned char *)pTVar12;
    local_83c = (unsigned char *)pTVar12;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x69:
    local_5c = (unsigned char *)0xa7b8374c;
    if (*(uint *)(pTVar56 + -0x90) != 0) {
      local_810 = *(unsigned char **)(pTVar56 + -0xa0);
      pTVar32 = *(unsigned char **)(pTVar56 + -0x9c);
      pTVar31 = *(unsigned char **)(pTVar56 + -0x98);
      pTVar33 = *(unsigned char **)(pTVar56 + -0x94);
      local_7fc = *(unsigned char **)(pTVar56 + -0x8c);
      local_800 = *(unsigned char **)(pTVar56 + -0x90);
      pTVar7 = *(unsigned char **)(pTVar56 + -0x88);
      uVar16 = 0xa7b8374c;
      local_81c = (unsigned char *)
                  (((uint)local_800 & 1) << 9 |
                  ((uint)pTVar33 & 1) << 10 |
                  ((uint)pTVar31 & 0xff) << 0xb |
                  ((uint)local_810 & 0x3f) << 0x13 | (int)pTVar32 << 0x19 | (uint)local_81c & 0x1ff)
      ;
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
      pTVar3 = local_830;
      local_80c = pTVar32;
      local_808 = pTVar31;
      local_804 = pTVar33;
      local_7f8 = pTVar7;
      local_7f0 = local_810;
      local_7ec = pTVar32;
      local_7e8 = pTVar31;
      local_7e4 = pTVar33;
      local_7e0 = local_800;
      local_7dc = local_7fc;
      local_7d8 = pTVar7;
      if (local_7fc != (unsigned char *)0x0) {
        local_838 = *(unsigned char **)(local_7fc + 8);
        uVar64 = TType__setStructSize((unsigned char *)&local_840,*(unsigned char **)(local_7fc + 8));
        local_828 = (unsigned char *)((ulonglong)uVar64 >> 0x20);
        iVar55 = (**(code **)(*(uint *)local_7dc + 0x18))
                           (local_7dc,(int)uVar64,pTVar7,pTVar33,pTVar31,pTVar32,*(uint *)local_7dc)
        ;
        *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
             **(undefined1 **)(local_64 + -0x7cc4);
        pcVar62 = *(char **)(iVar55 + 4);
        pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
        pTVar7 = (unsigned char *)TPoolAllocator__allocate(pTVar17,8);
        in_cr0 = (pTVar7 == (unsigned char *)0x0) << 1;
        pTVar3 = (unsigned char *)0x0;
        if (pTVar7 != (unsigned char *)0x0) {
          local_280[0] = GetGlobalPoolAllocator();
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                    (pTVar7,pcVar62,(unsigned char *)local_280);
          pTVar3 = pTVar7;
        }
      }
      local_830 = pTVar3;
      TType__getCompleteString(&local_850,(unsigned char *)&local_840);
      local_84c[*(uint *)(local_84c + -0xc)] = **(unsigned char **)(local_64 + -0x7cc4);
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + -0x58),"cannot declare arrays of this type",
                 (char *)local_84c,"",local_64,local_84c,uVar16);
      pTVar3 = local_84c + -4;
      local_270[0] = local_850;
      do {
        uVar57 = *(uint *)pTVar3;
        if (in_RESERVE != '\0') {
          uVar28 = storeWordConditionalIndexed(uVar57 - 1,0,pTVar3);
          *(uint *)pTVar3 = uVar28;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if ((int)uVar57 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(local_84c + -0xc),local_270);
      }
      local_840 = local_5c + -0x610c;
      TParseContext__recover(param_1);
    }
    iVar55 = TParseContext__reservedErrorCheck
                       (param_1,*(uint *)(pTVar56 + -0x84),*(unsigned char **)(pTVar56 + -0x80));
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    *(uint *)(pTVar56 + -0x90) = 1;
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar12 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    local_850 = *(unsigned char **)(pTVar56 + -0xa0);
    local_84c = *(unsigned char **)(pTVar56 + -0x9c);
    local_848 = *(unsigned char **)(pTVar56 + -0x98);
    local_844 = *(unsigned char **)(pTVar56 + -0x94);
    param_5 = *(char **)(pTVar56 + -0x90);
    param_4 = *(char **)(pTVar56 + -0x8c);
    local_838 = *(unsigned char **)(pTVar56 + -0x88);
    *(unsigned char **)pTVar12 = local_5c + -0x610c;
    *(undefined4 *)(pTVar12 + 0x20) = 0;
    *(undefined4 *)(pTVar12 + 4) = 0;
    *(undefined4 *)(pTVar12 + 8) = 0;
    *(undefined4 *)(pTVar12 + 0xc) = 0;
    *(undefined4 *)(pTVar12 + 0x10) = 0;
    *(undefined4 *)(pTVar12 + 0x14) = 0;
    *(undefined4 *)(pTVar12 + 0x18) = 0;
    *(undefined4 *)(pTVar12 + 0x1c) = 0;
    uVar2 = *(uint *)(pTVar12 + 0x24);
    uVar57 = (int)local_84c << 0x19;
    *(uint *)(pTVar12 + 0x24) = uVar57 | uVar2 & 0x1ffffff;
    uVar28 = ((uint)local_850 & 0x3f) << 0x13;
    *(uint *)(pTVar12 + 0x24) = uVar28 | uVar57 | uVar2 & 0x7ffff;
    uVar53 = ((uint)local_848 & 0xff) << 0xb;
    *(uint *)(pTVar12 + 0x24) = uVar53 | uVar28 | uVar57 | uVar2 & 0x7ff;
    uVar58 = ((uint)local_844 & 1) << 10;
    *(uint *)(pTVar12 + 0x24) = uVar58 | uVar53 | uVar28 | uVar57 | uVar2 & 0x3ff;
    *(uint *)(pTVar12 + 0x24) =
         ((uint)param_5 & 1) << 9 | uVar58 | uVar53 | uVar28 | uVar57 | uVar2 & 0x1ff;
    local_840 = (unsigned char *)param_5;
    local_83c = (unsigned char *)param_4;
    local_830 = local_850;
    local_82c = local_84c;
    local_828 = local_848;
    local_824 = local_844;
    local_820 = (unsigned char *)param_5;
    local_81c = (unsigned char *)param_4;
    local_818 = local_838;
    if ((unsigned char *)param_4 != (unsigned char *)0x0) {
      local_64 = (unsigned char *)0xa7b8374c;
      *(uint *)(pTVar12 + 8) = *(uint *)(param_4 + 8);
      uVar16 = TType__setStructSize(pTVar12,*(unsigned char **)(param_4 + 8));
      *(undefined4 *)(pTVar12 + 0x18) = uVar16;
      iVar55 = (**(code **)(*(uint *)local_81c + 0x18))(local_81c);
      *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
           **(undefined1 **)(local_64 + -0x7cc4);
      pcVar62 = *(char **)(iVar55 + 4);
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      pvVar13 = (void *)TPoolAllocator__allocate(pTVar17,8);
      in_cr0 = (pvVar13 == (void *)0x0) << 1;
      pvVar23 = (void *)0x0;
      if (pvVar13 != (void *)0x0) {
        local_260[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (pvVar13,pcVar62,(unsigned char *)local_260);
        pvVar23 = pvVar13;
      }
      *(void **)(pTVar12 + 0x10) = pvVar23;
    }
    iVar55 = (**(code **)(**(int **)(pTVar56 + -0x24) + 0x18))(*(int **)(pTVar56 + -0x24));
    if (iVar55 != 0) {
      iVar55 = (**(code **)(**(int **)(pTVar56 + -0x24) + 0x18))(*(int **)(pTVar56 + -0x24));
      uVar16 = **(undefined4 **)(iVar55 + 0x30);
      *(uint *)(pTVar12 + 0x24) = *(uint *)(pTVar12 + 0x24) | 0x200;
      *(undefined4 *)(pTVar12 + 4) = uVar16;
    }
    local_840 = *(unsigned char **)(pTVar56 + -0x80);
    local_880 = *(uint *)(pTVar56 + -0x84);
    pTVar3 = local_878;
    local_870 = local_840;
    local_86c = (unsigned char *)pTVar12;
    local_850 = local_840;
    local_84c = (unsigned char *)pTVar12;
    local_83c = (unsigned char *)pTVar12;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x6a:
  case 0x6c:
    _memcpy(&local_880,pTVar56,0x2c);
    uVar57 = *(uint *)pTVar56;
    uVar28 = *(uint *)(pTVar56 + -0x44);
    param_4 = *(char **)(pTVar56 + -0x1c);
    goto LAB_97ba9130;
  case 0x6b:
  case 0x6d:
    _memcpy(&local_880,pTVar56,0x2c);
    iVar55 = TParseContext__parameterSamplerErrorCheck
                       (param_1,*(uint *)pTVar56,*(uint *)(pTVar56 + -0x1c),
                        *(uint *)(pTVar56 + 0x14));
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    uVar57 = *(uint *)pTVar56;
    param_4 = *(char **)(pTVar56 + -0x1c);
    uVar28 = 0;
LAB_97ba9130:
    param_5 = (char *)local_86c;
    iVar55 = TParseContext__paramErrorCheck(param_1,uVar57,uVar28,param_4,local_86c);
LAB_97bab180:
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (iVar55 == 0) break;
LAB_97bab5f4:
    TParseContext__recover(param_1);
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
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
    pTVar12 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    local_830 = *(unsigned char **)(pTVar56 + 0x10);
    local_82c = *(unsigned char **)(pTVar56 + 0x14);
    local_828 = *(unsigned char **)(pTVar56 + 0x18);
    local_824 = *(unsigned char **)(pTVar56 + 0x1c);
    local_5c = (unsigned char *)0xa7b8374c;
    local_820 = *(unsigned char **)(pTVar56 + 0x20);
    param_5 = *(char **)(pTVar56 + 0x24);
    param_4 = *(char **)(pTVar56 + 0x28);
    *(undefined ***)pTVar12 = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined4 *)(pTVar12 + 0x20) = 0;
    *(undefined4 *)(pTVar12 + 4) = 0;
    *(undefined4 *)(pTVar12 + 8) = 0;
    *(undefined4 *)(pTVar12 + 0xc) = 0;
    *(undefined4 *)(pTVar12 + 0x10) = 0;
    *(undefined4 *)(pTVar12 + 0x14) = 0;
    *(undefined4 *)(pTVar12 + 0x18) = 0;
    *(undefined4 *)(pTVar12 + 0x1c) = 0;
    uVar2 = *(uint *)(pTVar12 + 0x24);
    uVar57 = (int)local_82c << 0x19;
    *(uint *)(pTVar12 + 0x24) = uVar57 | uVar2 & 0x1ffffff;
    uVar28 = ((uint)local_830 & 0x3f) << 0x13;
    *(uint *)(pTVar12 + 0x24) = uVar28 | uVar57 | uVar2 & 0x7ffff;
    uVar53 = ((uint)local_828 & 0xff) << 0xb;
    *(uint *)(pTVar12 + 0x24) = uVar53 | uVar28 | uVar57 | uVar2 & 0x7ff;
    uVar58 = ((uint)local_824 & 1) << 10;
    *(uint *)(pTVar12 + 0x24) = uVar58 | uVar53 | uVar28 | uVar57 | uVar2 & 0x3ff;
    *(uint *)(pTVar12 + 0x24) =
         ((uint)local_820 & 1) << 9 | uVar58 | uVar53 | uVar28 | uVar57 | uVar2 & 0x1ff;
    local_81c = (unsigned char *)param_5;
    local_818 = (unsigned char *)param_4;
    local_810 = local_830;
    local_80c = local_82c;
    local_808 = local_828;
    local_804 = local_824;
    local_800 = local_820;
    local_7fc = (unsigned char *)param_5;
    local_7f8 = (unsigned char *)param_4;
    if ((unsigned char *)param_5 != (unsigned char *)0x0) {
      local_64 = (unsigned char *)0xa7b8374c;
      *(uint *)(pTVar12 + 8) = *(uint *)(param_5 + 8);
      uVar16 = TType__setStructSize(pTVar12,*(unsigned char **)(param_5 + 8));
      *(undefined4 *)(pTVar12 + 0x18) = uVar16;
      iVar55 = (**(code **)(*(uint *)local_7fc + 0x18))(local_7fc);
      *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
           **(undefined1 **)(local_64 + -0x7cc4);
      pcVar62 = *(char **)(iVar55 + 4);
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      pvVar13 = (void *)TPoolAllocator__allocate(pTVar17,8);
      in_cr0 = (pvVar13 == (void *)0x0) << 1;
      pvVar23 = (void *)0x0;
      if (pvVar13 != (void *)0x0) {
        local_250[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (pvVar13,pcVar62,(unsigned char *)local_250);
        pvVar23 = pvVar13;
      }
      *(void **)(pTVar12 + 0x10) = pvVar23;
    }
    local_870 = local_840;
    local_850 = local_840;
    pTVar3 = local_878;
    local_86c = (unsigned char *)pTVar12;
    local_84c = (unsigned char *)pTVar12;
    local_83c = (unsigned char *)pTVar12;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x73:
    local_5c = (unsigned char *)0xa7b8374c;
    if (*(uint *)(pTVar56 + -100) != 0) {
      local_810 = *(unsigned char **)(pTVar56 + -0x74);
      pTVar32 = *(unsigned char **)(pTVar56 + -0x70);
      pTVar31 = *(unsigned char **)(pTVar56 + -0x6c);
      pTVar33 = *(unsigned char **)(pTVar56 + -0x68);
      local_7fc = *(unsigned char **)(pTVar56 + -0x60);
      local_800 = *(unsigned char **)(pTVar56 + -100);
      pTVar7 = *(unsigned char **)(pTVar56 + -0x5c);
      uVar16 = 0xa7b8374c;
      local_81c = (unsigned char *)
                  (((uint)local_800 & 1) << 9 |
                  ((uint)pTVar33 & 1) << 10 |
                  ((uint)pTVar31 & 0xff) << 0xb |
                  ((uint)local_810 & 0x3f) << 0x13 | (int)pTVar32 << 0x19 | (uint)local_81c & 0x1ff)
      ;
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
      pTVar3 = local_830;
      local_80c = pTVar32;
      local_808 = pTVar31;
      local_804 = pTVar33;
      local_7f8 = pTVar7;
      local_7f0 = local_810;
      local_7ec = pTVar32;
      local_7e8 = pTVar31;
      local_7e4 = pTVar33;
      local_7e0 = local_800;
      local_7dc = local_7fc;
      local_7d8 = pTVar7;
      if (local_7fc != (unsigned char *)0x0) {
        local_838 = *(unsigned char **)(local_7fc + 8);
        uVar64 = TType__setStructSize((unsigned char *)&local_840,*(unsigned char **)(local_7fc + 8));
        local_828 = (unsigned char *)((ulonglong)uVar64 >> 0x20);
        iVar55 = (**(code **)(*(uint *)local_7dc + 0x18))
                           (local_7dc,(int)uVar64,pTVar7,pTVar33,pTVar31,pTVar32,*(uint *)local_7dc)
        ;
        *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
             **(undefined1 **)(local_64 + -0x7cc4);
        pcVar62 = *(char **)(iVar55 + 4);
        pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
        pTVar7 = (unsigned char *)TPoolAllocator__allocate(pTVar17,8);
        in_cr0 = (pTVar7 == (unsigned char *)0x0) << 1;
        pTVar3 = (unsigned char *)0x0;
        if (pTVar7 != (unsigned char *)0x0) {
          local_240[0] = GetGlobalPoolAllocator();
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                    (pTVar7,pcVar62,(unsigned char *)local_240);
          pTVar3 = pTVar7;
        }
      }
      local_830 = pTVar3;
      TType__getCompleteString(&local_850,(unsigned char *)&local_840);
      local_84c[*(uint *)(local_84c + -0xc)] = **(unsigned char **)(local_64 + -0x7cc4);
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + -0x58),"cannot declare arrays of this type",
                 (char *)local_84c,"",local_64,local_84c,uVar16);
      pTVar3 = local_84c + -4;
      local_230[0] = local_850;
      do {
        uVar57 = *(uint *)pTVar3;
        if (in_RESERVE != '\0') {
          uVar28 = storeWordConditionalIndexed(uVar57 - 1,0,pTVar3);
          *(uint *)pTVar3 = uVar28;
          in_cr0 = 2;
        }
      } while (!(bool)(in_cr0 >> 1 & 1));
      if ((int)uVar57 < 1) {
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                  ((unsigned char *)(local_84c + -0xc),local_230);
      }
      local_840 = local_5c + -0x610c;
      TParseContext__recover(param_1);
    }
    *(uint *)(pTVar56 + -100) = 1;
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar12 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    local_850 = *(unsigned char **)(pTVar56 + -0x74);
    local_84c = *(unsigned char **)(pTVar56 + -0x70);
    local_848 = *(unsigned char **)(pTVar56 + -0x6c);
    local_844 = *(unsigned char **)(pTVar56 + -0x68);
    param_5 = *(char **)(pTVar56 + -100);
    param_4 = *(char **)(pTVar56 + -0x60);
    local_838 = *(unsigned char **)(pTVar56 + -0x5c);
    *(unsigned char **)pTVar12 = local_5c + -0x610c;
    *(undefined4 *)(pTVar12 + 0x20) = 0;
    *(undefined4 *)(pTVar12 + 4) = 0;
    *(undefined4 *)(pTVar12 + 8) = 0;
    *(undefined4 *)(pTVar12 + 0xc) = 0;
    *(undefined4 *)(pTVar12 + 0x10) = 0;
    *(undefined4 *)(pTVar12 + 0x14) = 0;
    *(undefined4 *)(pTVar12 + 0x18) = 0;
    *(undefined4 *)(pTVar12 + 0x1c) = 0;
    uVar2 = *(uint *)(pTVar12 + 0x24);
    uVar57 = (int)local_84c << 0x19;
    *(uint *)(pTVar12 + 0x24) = uVar57 | uVar2 & 0x1ffffff;
    uVar28 = ((uint)local_850 & 0x3f) << 0x13;
    *(uint *)(pTVar12 + 0x24) = uVar28 | uVar57 | uVar2 & 0x7ffff;
    uVar53 = ((uint)local_848 & 0xff) << 0xb;
    *(uint *)(pTVar12 + 0x24) = uVar53 | uVar28 | uVar57 | uVar2 & 0x7ff;
    uVar58 = ((uint)local_844 & 1) << 10;
    *(uint *)(pTVar12 + 0x24) = uVar58 | uVar53 | uVar28 | uVar57 | uVar2 & 0x3ff;
    *(uint *)(pTVar12 + 0x24) =
         ((uint)param_5 & 1) << 9 | uVar58 | uVar53 | uVar28 | uVar57 | uVar2 & 0x1ff;
    local_840 = (unsigned char *)param_5;
    local_83c = (unsigned char *)param_4;
    local_830 = local_850;
    local_82c = local_84c;
    local_828 = local_848;
    local_824 = local_844;
    local_820 = (unsigned char *)param_5;
    local_81c = (unsigned char *)param_4;
    local_818 = local_838;
    if ((unsigned char *)param_4 != (unsigned char *)0x0) {
      local_64 = (unsigned char *)0xa7b8374c;
      *(uint *)(pTVar12 + 8) = *(uint *)(param_4 + 8);
      uVar16 = TType__setStructSize(pTVar12,*(unsigned char **)(param_4 + 8));
      *(undefined4 *)(pTVar12 + 0x18) = uVar16;
      iVar55 = (**(code **)(*(uint *)local_81c + 0x18))(local_81c);
      *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
           **(undefined1 **)(local_64 + -0x7cc4);
      pcVar62 = *(char **)(iVar55 + 4);
      pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
      pvVar13 = (void *)TPoolAllocator__allocate(pTVar17,8);
      in_cr0 = (pvVar13 == (void *)0x0) << 1;
      pvVar23 = (void *)0x0;
      if (pvVar13 != (void *)0x0) {
        local_220[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (pvVar13,pcVar62,(unsigned char *)local_220);
        pvVar23 = pvVar13;
      }
      *(void **)(pTVar12 + 0x10) = pvVar23;
    }
    iVar55 = (**(code **)(**(int **)(pTVar56 + -0x24) + 0x18))(*(int **)(pTVar56 + -0x24));
    if (iVar55 != 0) {
      iVar55 = (**(code **)(**(int **)(pTVar56 + -0x24) + 0x18))(*(int **)(pTVar56 + -0x24));
      uVar16 = **(undefined4 **)(iVar55 + 0x30);
      *(uint *)(pTVar12 + 0x24) = *(uint *)(pTVar12 + 0x24) | 0x200;
      *(undefined4 *)(pTVar12 + 4) = uVar16;
    }
    local_850 = (unsigned char *)0x0;
    local_880 = *(uint *)(pTVar56 + -0x58);
    pTVar3 = local_878;
    local_870 = local_850;
    local_86c = (unsigned char *)pTVar12;
    local_84c = (unsigned char *)pTVar12;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x74:
    _memcpy(&local_880,pTVar56,0x2c);
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x75:
    _memcpy(&local_880,pTVar56 + -0x58,0x2c);
    uVar57 = *(uint *)pTVar56;
    pTVar27 = (unsigned char *)(pTVar56 + -0x48);
    goto LAB_97ba9874;
  case 0x76:
    _memcpy(&local_880,pTVar56 + -0xb0,0x2c);
    iVar55 = TParseContext__structQualifierErrorCheck
                       (param_1,*(uint *)(pTVar56 + -0x58),(unsigned char *)(pTVar56 + -0xa0),param_4,
                        param_5,pTVar33,pTVar34);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    psVar21 = *(unsigned char **)(pTVar56 + -0x2c);
    uVar57 = *(uint *)(pTVar56 + -0x54);
    uVar28 = 0;
    goto LAB_97ba99f8;
  case 0x77:
    _memcpy(&local_880,pTVar56 + -0xdc,0x2c);
    uVar57 = *(uint *)(pTVar56 + -0x84);
    pTVar27 = (unsigned char *)(pTVar56 + -0xcc);
    goto LAB_97ba99a0;
  case 0x78:
    pTVar59 = pTVar56 + -0xa0;
    _memcpy(&local_880,pTVar56 + -0xb0,0x2c);
    iVar55 = TParseContext__structQualifierErrorCheck
                       (param_1,*(uint *)(pTVar56 + -0x58),(unsigned char *)pTVar59,param_4,param_5,
                        pTVar33,pTVar34);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    param_5 = *(char **)(pTVar56 + 8);
    iVar55 = TParseContext__executeInitializer
                       (param_1,*(uint *)(pTVar56 + -0x58),*(unsigned char **)(pTVar56 + -0x54),
                        (unsigned char *)pTVar59,(unsigned char *)param_5,&local_80);
    if (iVar55 == 0) {
      if (local_80 != (unsigned char *)0x0) {
        pTVar15 = *(unsigned char **)param_1;
        pTVar22 = *(unsigned char **)(pTVar56 + -0xa8);
        pTVar20 = local_80;
        goto LAB_97ba97d4;
      }
      param_4 = (char *)pTVar59;
      pTVar3 = *(unsigned char **)(pTVar56 + -0xa8);
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
      break;
    }
    goto LAB_97bab1f4;
  case 0x79:
    local_870 = *(unsigned char **)(pTVar56 + 0x10);
    local_86c = *(unsigned char **)(pTVar56 + 0x14);
    local_868 = *(unsigned char **)(pTVar56 + 0x18);
    local_864 = *(unsigned char **)(pTVar56 + 0x1c);
    local_860 = *(unsigned char **)(pTVar56 + 0x20);
    local_85c = *(unsigned char **)(pTVar56 + 0x24);
    local_858 = *(unsigned char **)(pTVar56 + 0x28);
    pTVar3 = (unsigned char *)0x0;
    break;
  case 0x7a:
    local_878 = (unsigned char *)0x0;
    pTVar27 = (unsigned char *)(pTVar56 + -0x1c);
    local_870 = *(unsigned char **)(pTVar56 + -0x1c);
    local_86c = *(unsigned char **)(pTVar56 + -0x18);
    local_868 = *(unsigned char **)(pTVar56 + -0x14);
    local_864 = *(unsigned char **)(pTVar56 + -0x10);
    local_860 = *(unsigned char **)(pTVar56 + -0xc);
    local_85c = *(unsigned char **)(pTVar56 + -8);
    pTVar34 = *(unsigned char **)(pTVar56 + -4);
    uVar57 = *(uint *)pTVar56;
    local_858 = pTVar34;
LAB_97ba9874:
    iVar55 = TParseContext__structQualifierErrorCheck
                       (param_1,uVar57,pTVar27,param_4,param_5,pTVar33,pTVar34);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    param_4 = (char *)&local_870;
    iVar55 = TParseContext__nonInitErrorCheck
                       (param_1,*(uint *)pTVar56,*(unsigned char **)(pTVar56 + 4),(unsigned char *)param_4);
    goto LAB_97bab180;
  case 0x7b:
    local_878 = (unsigned char *)0x0;
    local_870 = *(unsigned char **)(pTVar56 + -0x74);
    local_86c = *(unsigned char **)(pTVar56 + -0x70);
    local_868 = *(unsigned char **)(pTVar56 + -0x6c);
    local_864 = *(unsigned char **)(pTVar56 + -0x68);
    local_860 = *(unsigned char **)(pTVar56 + -100);
    local_85c = *(unsigned char **)(pTVar56 + -0x60);
    local_858 = *(unsigned char **)(pTVar56 + -0x5c);
    iVar55 = TParseContext__structQualifierErrorCheck
                       (param_1,*(uint *)(pTVar56 + -0x58),(unsigned char *)(pTVar56 + -0x74),param_4,
                        param_5,pTVar33,local_858);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    psVar21 = *(unsigned char **)(pTVar56 + -0x2c);
    uVar57 = *(uint *)(pTVar56 + -0x54);
    local_850 = local_870;
    local_84c = local_86c;
    local_848 = local_868;
    local_844 = local_864;
    local_840 = local_860;
    local_83c = local_85c;
    local_838 = local_858;
    puVar4[0x10] = 0;
    puVar4[0xf] = local_858;
    goto LAB_97ba9a08;
  case 0x7c:
    local_878 = (unsigned char *)0x0;
    pTVar27 = (unsigned char *)(pTVar56 + -0xa0);
    local_870 = *(unsigned char **)(pTVar56 + -0xa0);
    local_86c = *(unsigned char **)(pTVar56 + -0x9c);
    local_868 = *(unsigned char **)(pTVar56 + -0x98);
    local_864 = *(unsigned char **)(pTVar56 + -0x94);
    local_860 = *(unsigned char **)(pTVar56 + -0x90);
    local_85c = *(unsigned char **)(pTVar56 + -0x8c);
    pTVar34 = *(unsigned char **)(pTVar56 + -0x88);
    uVar57 = *(uint *)(pTVar56 + -0x84);
    local_858 = pTVar34;
LAB_97ba99a0:
    iVar55 = TParseContext__structQualifierErrorCheck
                       (param_1,uVar57,pTVar27,param_4,param_5,pTVar33,pTVar34);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    psVar21 = *(unsigned char **)(pTVar56 + -0x58);
    uVar57 = *(uint *)(pTVar56 + -0x80);
    uVar28 = *(uint *)(pTVar56 + -0x24);
LAB_97ba99f8:
    puVar4[0x10] = uVar28;
    puVar4[0xf] = local_858;
    local_850 = local_870;
    local_84c = local_86c;
    local_848 = local_868;
    local_844 = local_864;
    local_840 = local_860;
    local_83c = local_85c;
    local_838 = local_858;
LAB_97ba9a08:
    puVar4[0xe] = local_83c;
    param_4 = (char *)local_850;
    param_5 = (char *)local_84c;
    local_870 = local_850;
    local_86c = local_84c;
    local_868 = local_848;
    local_864 = local_844;
    local_860 = local_840;
    local_85c = local_83c;
    local_858 = local_838;
    iVar55 = TParseContext__arrayErrorCheck
                       ((int)param_1,psVar21,uVar57,local_850,local_84c,local_848,local_844,
                        local_840,puVar4[0xe],puVar4[0xf],puVar4[0x10]);
    goto LAB_97bab180;
  case 0x7d:
    local_870 = *(unsigned char **)(pTVar56 + -0x74);
    pTVar59 = pTVar56 + -0x74;
    local_86c = *(unsigned char **)(pTVar56 + -0x70);
    local_868 = *(unsigned char **)(pTVar56 + -0x6c);
    local_864 = *(unsigned char **)(pTVar56 + -0x68);
    local_860 = *(unsigned char **)(pTVar56 + -100);
    local_85c = *(unsigned char **)(pTVar56 + -0x60);
    local_858 = *(unsigned char **)(pTVar56 + -0x5c);
    iVar55 = TParseContext__structQualifierErrorCheck
                       (param_1,*(uint *)(pTVar56 + -0x58),(unsigned char *)pTVar59,param_4,param_5,
                        pTVar33,local_858);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    param_5 = *(char **)(pTVar56 + 8);
    iVar55 = TParseContext__executeInitializer
                       (param_1,*(uint *)(pTVar56 + -0x58),*(unsigned char **)(pTVar56 + -0x54),
                        (unsigned char *)pTVar59,(unsigned char *)param_5,&local_7c);
    if (iVar55 != 0) goto LAB_97bab1f4;
    if (local_7c != (unsigned char *)0x0) {
      pTVar15 = *(unsigned char **)param_1;
      uVar57 = *(uint *)(pTVar56 + -0x2c);
      pTVar20 = local_7c;
      param_4 = (char *)pTVar59;
      goto LAB_97bab0ec;
    }
    goto switchD_97ba39c8_caseD_60;
  case 0x7e:
    local_868 = *(unsigned char **)(pTVar56 + 0x18);
    local_864 = *(unsigned char **)(pTVar56 + 0x1c);
    local_860 = *(unsigned char **)(pTVar56 + 0x20);
    local_85c = *(unsigned char **)(pTVar56 + 0x24);
    local_858 = *(unsigned char **)(pTVar56 + 0x28);
    local_870 = *(unsigned char **)(pTVar56 + 0x10);
    local_86c = *(unsigned char **)(pTVar56 + 0x14);
    break;
  case 0x7f:
    pTVar3 = *(unsigned char **)(pTVar56 + 0x10);
    local_84c = *(unsigned char **)(pTVar56 + -0x18);
    pTVar33 = *(unsigned char **)(pTVar56 + 0x18);
    local_844 = *(unsigned char **)(pTVar56 + 0x1c);
    local_820 = (unsigned char *)0x0;
    pTVar7 = *(unsigned char **)(pTVar56 + 0x24);
    local_838 = (unsigned char *)0x0;
    local_818 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    uVar57 = *(uint *)(pTVar56 + -0x18);
    local_850 = pTVar3;
    local_848 = pTVar33;
    local_83c = pTVar7;
    local_830 = pTVar3;
    local_82c = local_84c;
    local_828 = pTVar33;
    local_824 = local_844;
    local_81c = pTVar7;
    if ((uVar57 == 3) && (*(uint *)(pTVar56 + 0x10) - 2 < 2)) {
      param_4 = (char *)getQualifierString(3);
      param_5 = "";
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + 0x28),"cannot be bool or int",param_4,"",pTVar3,
                 pTVar7,pTVar33);
      TParseContext__recover(param_1);
      uVar57 = *(uint *)(pTVar56 + -0x18);
    }
    if ((uVar57 - 4 < 2) && (*(uint *)(pTVar56 + 0x10) - 2 < 2)) {
      param_4 = (char *)getQualifierString(uVar57);
      param_5 = "";
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + 0x28),"cannot be bool or int",param_4,"",pTVar3,
                 pTVar7,pTVar33);
      TParseContext__recover(param_1);
    }
    goto LAB_97ba9d1c;
  case 0x80:
    puVar25 = &DAT_97c356fc;
    goto LAB_97ba9da4;
  case 0x81:
    if (*(int *)((int)param_1 + 0xc) != 0) {
      param_5 = "";
      pTVar33 = (unsigned char *)param_5;
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex shaders only ","attribute","",
                 "",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    iVar55 = TParseContext__globalErrorCheck
                       (param_1,*(uint *)pTVar56,
                        (uint)((uint)((*(int **)((int)param_1 + 4))[1] -
                                      **(int **)((int)param_1 + 4) >> 2) < 4),"attribute",param_5,
                        pTVar33);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    puVar25 = &DAT_97c35718;
    goto LAB_97ba9da4;
  case 0x82:
    iVar55 = TParseContext__globalErrorCheck
                       (param_1,*(uint *)pTVar56,
                        (uint)((uint)((*(int **)((int)param_1 + 4))[1] -
                                      **(int **)((int)param_1 + 4) >> 2) < 4),"varying",param_5,
                        pTVar33);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    param_4 = (char *)0x0;
    param_5 = (char *)0x0;
    local_850 = (unsigned char *)0x0;
    local_84c = (unsigned char *)0x4;
    local_848 = (unsigned char *)0x1;
    local_844 = (unsigned char *)0x0;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_838 = (unsigned char *)0x0;
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
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x83:
    iVar55 = TParseContext__globalErrorCheck
                       (param_1,*(uint *)pTVar56,
                        (uint)((uint)((*(int **)((int)param_1 + 4))[1] -
                                      **(int **)((int)param_1 + 4) >> 2) < 4),"uniform",param_5,
                        pTVar33);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    puVar25 = &DAT_97c35750;
LAB_97ba9da4:
    local_858 = (unsigned char *)puVar25[6];
    local_868 = (unsigned char *)puVar25[2];
    local_864 = (unsigned char *)puVar25[3];
    local_860 = (unsigned char *)puVar25[4];
    param_5 = (char *)puVar25[5];
    param_4 = (char *)local_858;
    pTVar3 = local_878;
    local_870 = (unsigned char *)*puVar25;
    local_86c = (unsigned char *)puVar25[1];
    local_85c = (unsigned char *)param_5;
    local_850 = (unsigned char *)*puVar25;
    local_84c = (unsigned char *)puVar25[1];
    local_848 = local_868;
    local_844 = local_864;
    local_840 = local_860;
    local_83c = (unsigned char *)param_5;
    local_838 = local_858;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
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
    local_858 = *(unsigned char **)pTVar56;
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
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x1;
    goto LAB_97ba9f0c;
  case 0x86:
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x2;
    goto LAB_97baa3fc;
  case 0x87:
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x3;
    goto LAB_97baa3fc;
  case 0x88:
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x1;
    goto LAB_97ba9eec;
  case 0x89:
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x1;
    goto LAB_97ba9fa8;
  case 0x8a:
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x1;
    goto LAB_97ba9fc8;
  case 0x8b:
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x3;
LAB_97ba9eec:
    iVar55 = piVar61[1] - *piVar61;
    local_828 = (unsigned char *)0x2;
    goto LAB_97baa40c;
  case 0x8c:
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x3;
    goto LAB_97ba9f0c;
  case 0x8d:
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x3;
    goto LAB_97ba9fc8;
  case 0x8e:
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x2;
LAB_97ba9f0c:
    iVar55 = piVar61[1] - *piVar61;
    local_818 = *(unsigned char **)pTVar56;
    local_828 = local_830;
    goto LAB_97baa46c;
  case 0x8f:
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x2;
LAB_97ba9fa8:
    iVar55 = piVar61[1] - *piVar61;
    local_828 = (unsigned char *)0x3;
    goto LAB_97baa40c;
  case 0x90:
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x2;
LAB_97ba9fc8:
    iVar55 = piVar61[1] - *piVar61;
    local_828 = (unsigned char *)0x4;
    goto LAB_97baa40c;
  case 0x91:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "mat2";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ","mat2"
                 ,"","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    iVar55 = (*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4);
    local_868 = (unsigned char *)0x2;
    goto LAB_97baa0ec;
  case 0x92:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "mat3";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ","mat3"
                 ,"","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    iVar55 = (*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4);
    local_868 = (unsigned char *)0x3;
    goto LAB_97baa0ec;
  case 0x93:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "mat4";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ","mat4"
                 ,"","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    iVar55 = (*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4);
    local_868 = (unsigned char *)0x4;
LAB_97baa0ec:
    local_82c = (unsigned char *)(uint)((uint)(iVar55 >> 2) < 4);
    local_830 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x1;
    local_820 = (unsigned char *)0x0;
    local_81c = (unsigned char *)0x0;
    local_858 = *(unsigned char **)pTVar56;
    local_864 = (unsigned char *)0x1;
    local_85c = (unsigned char *)0x0;
    local_850 = (unsigned char *)0x1;
    local_844 = (unsigned char *)0x1;
    local_840 = (unsigned char *)0x0;
    local_83c = (unsigned char *)0x0;
    local_870 = (unsigned char *)0x1;
    local_860 = (unsigned char *)0x0;
    pTVar3 = local_878;
    local_86c = local_82c;
    local_84c = local_82c;
    local_848 = local_868;
    local_838 = local_858;
    local_828 = local_868;
    local_818 = local_858;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x94:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "sampler1D";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ",
                 "sampler1D","","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x5;
    goto LAB_97baa3fc;
  case 0x95:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "sampler2D";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ",
                 "sampler2D","","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x6;
    goto LAB_97baa3fc;
  case 0x96:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "sampler3D";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ",
                 "sampler3D","","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x7;
    goto LAB_97baa3fc;
  case 0x97:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "samplerCube";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ",
                 "samplerCube","","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x8;
    goto LAB_97baa3fc;
  case 0x98:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "sampler1DShadow";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ",
                 "sampler1DShadow","","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0x9;
    goto LAB_97baa3fc;
  case 0x99:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "sampler2DShadow";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ",
                 "sampler2DShadow","","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0xa;
    goto LAB_97baa3fc;
  case 0x9a:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "sampler2DRect";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ",
                 "sampler2DRect","","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    iVar55 = TParseContext__extensionErrorCheck(param_1,*(uint *)pTVar56,"GL_ARB_texture_rectangle")
    ;
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0xb;
    goto LAB_97baa3fc;
  case 0x9b:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "sampler2DRectShadow";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56," supported in vertex/fragment shaders only ",
                 "sampler2DRectShadow","","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    iVar55 = TParseContext__extensionErrorCheck(param_1,*(uint *)pTVar56,"GL_ARB_texture_rectangle")
    ;
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    piVar61 = *(int **)((int)param_1 + 4);
    local_830 = (unsigned char *)0xc;
LAB_97baa3fc:
    iVar55 = piVar61[1] - *piVar61;
    local_828 = (unsigned char *)0x1;
LAB_97baa40c:
    local_818 = *(unsigned char **)pTVar56;
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
    pTVar3 = local_878;
    local_870 = local_830;
    local_86c = local_82c;
    local_868 = local_828;
    local_858 = local_818;
    local_850 = local_830;
    local_84c = local_82c;
    local_848 = local_828;
    local_838 = local_818;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x9c:
    if (1 < *(uint *)((int)param_1 + 0xc)) {
      param_5 = "";
      param_4 = "struct";
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + 0x28),
                 " supported in vertex/fragment shaders only ","struct","","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    local_868 = *(unsigned char **)(pTVar56 + 0x18);
    local_864 = *(unsigned char **)(pTVar56 + 0x1c);
    local_860 = *(unsigned char **)(pTVar56 + 0x20);
    local_85c = *(unsigned char **)(pTVar56 + 0x24);
    local_858 = *(unsigned char **)(pTVar56 + 0x28);
    pTVar3 = local_878;
    local_870 = *(unsigned char **)(pTVar56 + 0x10);
    local_86c = (unsigned char *)
                (uint)((uint)((*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4) >> 2)
                      < 4);
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x9d:
    local_85c = (unsigned char *)(*(uint *)(pTVar56 + 8) + 0xc);
    local_830 = (unsigned char *)0xe;
    local_828 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x0;
    local_82c = (unsigned char *)
                (uint)((uint)((*(int **)((int)param_1 + 4))[1] - **(int **)((int)param_1 + 4) >> 2)
                      < 4);
    local_820 = (unsigned char *)0x0;
    local_858 = *(unsigned char **)pTVar56;
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
    pTVar12 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    pTVar52 = *(unsigned char **)(pTVar56 + -0x1c);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_
              ((unsigned char *)&local_850,*(unsigned char **)(pTVar56 + -0x80));
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_((unsigned char *)&local_840,(unsigned char *)&local_850);
    local_5c = (unsigned char *)0xa7b8374c;
    *(undefined ***)pTVar12 = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined4 *)(pTVar12 + 0x20) = 0;
    *(uint *)(pTVar12 + 0x24) = *(uint *)(pTVar12 + 0x24) & 0x9ff | 0x700800;
    *(undefined4 *)(pTVar12 + 4) = 0;
    *(unsigned char **)(pTVar12 + 8) = pTVar52;
    *(undefined4 *)(pTVar12 + 0xc) = 0;
    *(undefined4 *)(pTVar12 + 0x14) = 0;
    *(undefined4 *)(pTVar12 + 0x1c) = 0;
    uVar16 = TType__setStructSize(pTVar12,pTVar52);
    pTVar3 = local_83c;
    local_64 = (unsigned char *)0xa7b8374c;
    *(undefined4 *)(pTVar12 + 0x18) = uVar16;
    local_83c[(int)*(unsigned char **)(local_83c + -0xc)] = *DAT_a7b7ba88;
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pvVar13 = (void *)TPoolAllocator__allocate(pTVar17,8);
    in_cr0 = (pvVar13 == (void *)0x0) << 1;
    pvVar23 = (void *)0x0;
    if (pvVar13 != (void *)0x0) {
      local_210[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (pvVar13,(char *)pTVar3,(unsigned char *)local_210);
      pvVar23 = pvVar13;
    }
    *(void **)(pTVar12 + 0x10) = pvVar23;
    pTVar3 = local_83c + -4;
    local_200[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_200);
    }
    pTVar3 = local_84c + -4;
    local_1f0[0] = local_850;
    do {
      uVar57 = *(uint *)pTVar3;
      if (in_RESERVE != '\0') {
        uVar28 = storeWordConditionalIndexed(uVar57 - 1,0,pTVar3);
        *(uint *)pTVar3 = uVar28;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)uVar57 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_84c + -0xc),local_1f0);
    }
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    piVar61 = (int *)TPoolAllocator__allocate(pTVar17,0x40);
    puVar5 = PTR_vtable_a7b7c0b4 + 8;
    piVar61[1] = *(uint *)(pTVar56 + -0x80);
    *piVar61 = (int)puVar5;
    iVar30 = *(int *)(pTVar12 + 0xc);
    iVar26 = *(int *)(pTVar12 + 0x10);
    param_5 = *(char **)(pTVar12 + 0x14);
    param_4 = *(char **)(pTVar12 + 0x18);
    iVar6 = *(int *)(pTVar12 + 0x1c);
    iVar60 = *(int *)(pTVar12 + 0x20);
    iVar55 = *(int *)(pTVar12 + 4);
    iVar54 = *(int *)(pTVar12 + 8);
    piVar61[3] = (int)(local_5c + -0x610c);
    piVar61[6] = iVar30;
    piVar61[7] = iVar26;
    piVar61[8] = (int)param_5;
    piVar61[9] = (int)param_4;
    piVar61[10] = iVar6;
    piVar61[0xb] = iVar60;
    piVar61[4] = iVar55;
    piVar61[5] = iVar54;
    uVar2 = piVar61[0xc];
    uVar28 = *(uint *)(pTVar12 + 0x24) & 0xfe000000;
    piVar61[0xc] = uVar28 | uVar2 & 0x1ffffff;
    uVar53 = (*(uint *)(pTVar12 + 0x24) >> 0x13 & 0x3f) << 0x13;
    piVar61[0xc] = uVar53 | uVar28 | uVar2 & 0x7ffff;
    uVar57 = *(uint *)(pTVar12 + 0x24) & 0x7f800;
    piVar61[0xc] = uVar57 | uVar53 | uVar28 | uVar2 & 0x7ff;
    uVar58 = (*(uint *)(pTVar12 + 0x24) >> 10 & 1) << 10;
    piVar61[0xc] = uVar58 | uVar57 | uVar53 | uVar28 | uVar2 & 0x3ff;
    piVar61[0xc] = (*(uint *)(pTVar12 + 0x24) >> 9 & 1) << 9 |
                   uVar58 | uVar57 | uVar53 | uVar28 | uVar2 & 0x1ff;
    piVar61[0xd] = 1;
    piVar61[0xe] = 0;
    piVar61[0xf] = 0;
    piVar50 = *(int **)((int)param_1 + 4);
    iVar55 = piVar50[3];
    piVar50[3] = iVar55 + 1;
    piVar61[2] = iVar55 + 1;
    uVar16 = *(undefined4 *)(*piVar50 + ((piVar50[1] - *piVar50 & 0xfffffffcU) - 4));
    local_84c = (unsigned char *)0x0;
    psVar21 = (unsigned char *)
              (**(code **)(*piVar61 + 8))(piVar61,iVar60,iVar6,param_4,param_5,iVar26,piVar50);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_1e0,psVar21);
    local_1d8 = piVar61;
    std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_840,uVar16,&local_1e0);
    local_850 = local_840;
    piVar61 = (int *)(local_1dc + -4);
    local_84c = local_83c;
    local_1d0[0] = local_1e0;
    do {
      iVar55 = *piVar61;
      if (in_RESERVE != '\0') {
        iVar54 = storeWordConditionalIndexed(iVar55 + -1,0,piVar61);
        *piVar61 = iVar54;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if (iVar55 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_1dc + -0xc),local_1d0);
    }
    if (local_84c == (unsigned char *)0x0) {
      uVar57 = *(uint *)(pTVar56 + -0x80);
      iVar55 = *(int *)(uVar57 + 4);
      param_5 = "struct";
      *(unsigned char *)(iVar55 + *(int *)(iVar55 + -0xc)) = *DAT_a7b7ba88;
      param_4 = *(char **)(uVar57 + 4);
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + -0x84),"redefinition",param_4,"struct",iVar26,
                 iVar55,uVar57);
      TParseContext__recover(param_1);
    }
    local_82c = (unsigned char *)0x0;
    local_830 = (unsigned char *)0xe;
    local_828 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x0;
    local_820 = (unsigned char *)0x0;
    local_858 = *(unsigned char **)(pTVar56 + -0xb0);
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
    pTVar3 = local_878;
    local_85c = (unsigned char *)pTVar12;
    local_83c = (unsigned char *)pTVar12;
    local_838 = local_858;
    local_81c = (unsigned char *)pTVar12;
    local_818 = local_858;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0x9f:
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar12 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    pTVar52 = *(unsigned char **)(pTVar56 + -0x1c);
    local_1c0[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              ((unsigned char *)&local_850,"",(unsigned char *)local_1c0);
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_840,(unsigned char *)&local_850);
    local_5c = (unsigned char *)0xa7b8374c;
    *(undefined ***)pTVar12 = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined4 *)(pTVar12 + 0x20) = 0;
    *(uint *)(pTVar12 + 0x24) = *(uint *)(pTVar12 + 0x24) & 0x9ff | 0x700800;
    *(undefined4 *)(pTVar12 + 4) = 0;
    *(unsigned char **)(pTVar12 + 8) = pTVar52;
    *(undefined4 *)(pTVar12 + 0xc) = 0;
    *(undefined4 *)(pTVar12 + 0x14) = 0;
    *(undefined4 *)(pTVar12 + 0x1c) = 0;
    uVar16 = TType__setStructSize(pTVar12,pTVar52);
    pTVar3 = local_83c;
    *(undefined4 *)(pTVar12 + 0x18) = uVar16;
    local_64 = (unsigned char *)0xa7b8374c;
    local_83c[(int)*(unsigned char **)(local_83c + -0xc)] = *DAT_a7b7ba88;
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pvVar13 = (void *)TPoolAllocator__allocate(pTVar17,8);
    in_cr0 = (pvVar13 == (void *)0x0) << 1;
    pvVar23 = (void *)0x0;
    if (pvVar13 != (void *)0x0) {
      local_1b0[0] = GetGlobalPoolAllocator();
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                (pvVar13,(char *)pTVar3,(unsigned char *)local_1b0);
      pvVar23 = pvVar13;
    }
    *(void **)(pTVar12 + 0x10) = pvVar23;
    pTVar3 = local_83c + -4;
    local_1a0[0] = local_840;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_83c + -0xc),local_1a0);
    }
    pTVar3 = local_84c + -4;
    local_190[0] = local_850;
    do {
      uVar57 = *(uint *)pTVar3;
      if (in_RESERVE != '\0') {
        uVar28 = storeWordConditionalIndexed(uVar57 - 1,0,pTVar3);
        *(uint *)pTVar3 = uVar28;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)uVar57 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_84c + -0xc),local_190);
    }
    local_830 = (unsigned char *)0xe;
    local_82c = (unsigned char *)0x0;
    local_828 = (unsigned char *)0x1;
    local_824 = (unsigned char *)0x0;
    local_820 = (unsigned char *)0x0;
    local_858 = *(unsigned char **)(pTVar56 + -0x84);
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
    pTVar3 = local_878;
    local_85c = (unsigned char *)pTVar12;
    local_83c = (unsigned char *)pTVar12;
    local_838 = local_858;
    local_81c = (unsigned char *)pTVar12;
    local_818 = local_858;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xa1:
    local_870 = *(unsigned char **)(pTVar56 + -0x1c);
    for (uVar57 = 0; pTVar7 = DAT_a7b7ba88, pTVar3 = local_878, pTVar31 = local_7f0,
        pTVar32 = local_750[0],
        uVar57 < (uint)(*(int *)(*(uint *)(pTVar56 + 0x10) + 8) -
                        *(int *)(*(uint *)(pTVar56 + 0x10) + 4) >> 3); uVar57 = uVar57 + 1) {
      uVar28 = 0;
      iVar55 = uVar57 * 8;
      while( true ) {
        puVar18 = *(undefined4 **)(local_870 + 8);
        if ((uint)((int)puVar18 - *(int *)(local_870 + 4) >> 3) <= uVar28) break;
        piVar61 = *(int **)(*(int *)(local_870 + 4) + uVar28 * 8);
        iVar54 = *piVar61;
        iVar54 = (**(code **)(iVar54 + 0x1c))
                           (piVar61,puVar18,param_3,param_4,param_5,pTVar33,iVar54);
        piVar61 = *(int **)(*(int *)(*(uint *)(pTVar56 + 0x10) + 4) + iVar55);
        iVar60 = (**(code **)(*piVar61 + 0x1c))
                           (piVar61,a1_09,param_3,param_4,param_5,pTVar33,
                            *(int *)(*(uint *)(pTVar56 + 0x10) + 4));
        uVar53 = *(uint *)(*(int *)(iVar54 + 4) + -0xc);
        local_78 = uVar53;
        uVar58 = *(uint *)(*(int *)(iVar60 + 4) + -0xc);
        local_74 = uVar58;
        puVar25 = &local_74;
        if (uVar53 <= uVar58) {
          puVar25 = &local_78;
        }
        param_3 = (char *)*puVar25;
        iVar54 = _memcmp(*(undefined4 *)(iVar54 + 4),*(undefined4 *)(iVar60 + 4),param_3);
        in_cr0 = (iVar54 == 0) << 1;
        if (iVar54 == 0) {
          iVar54 = uVar53 - uVar58;
        }
        if (iVar54 == 0) {
          piVar61 = *(int **)(*(int *)(*(uint *)(pTVar56 + 0x10) + 4) + iVar55);
          iVar54 = *piVar61;
          iVar54 = (**(code **)(iVar54 + 0x1c))
                             (piVar61,a1_10,param_3,param_4,param_5,pTVar33,iVar54);
          param_3 = "duplicate field name in structure:";
          param_4 = "struct";
          *(unsigned char *)(*(int *)(iVar54 + 4) + *(int *)(*(int *)(iVar54 + 4) + -0xc)) = *pTVar7;
          param_5 = *(char **)(iVar54 + 4);
          TParseContext__error
                    ((int)param_1,*(char **)(*(int *)(*(uint *)(pTVar56 + 0x10) + 4) + iVar55 + 4),
                     "duplicate field name in structure:","struct",param_5,pTVar33,
                     *(uint *)(pTVar56 + 0x10),param_8);
          TParseContext__recover(param_1);
        }
        uVar28 = uVar28 + 1;
      }
      param_3 = (char *)(*(int *)(*(uint *)(pTVar56 + 0x10) + 4) + iVar55);
      if (puVar18 == *(undefined4 **)(local_870 + 0xc)) {
        std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux
                  ((unsigned char *)local_870,puVar18,param_3);
      }
      else {
        if (puVar18 != (undefined4 *)0x0) {
          uVar16 = *(undefined4 *)(param_3 + 4);
          *puVar18 = *(undefined4 *)(*(int *)(*(uint *)(pTVar56 + 0x10) + 4) + iVar55);
          puVar18[1] = uVar16;
        }
        *(int *)(local_870 + 8) = *(int *)(local_870 + 8) + 8;
      }
    }
    break;
  case 0xa2:
    local_870 = *(unsigned char **)(pTVar56 + -0x1c);
    piVar61 = (int *)**(undefined4 **)(*(uint *)(pTVar56 + -0x1c) + 4);
    psVar21 = (unsigned char *)
              (**(code **)(*piVar61 + 0x1c))
                        (piVar61,param_2,param_3,param_4,param_5,pTVar33,
                         *(undefined4 **)(*(uint *)(pTVar56 + -0x1c) + 4));
    param_4 = (char *)(pTVar56 + -0x48);
    iVar55 = TParseContext__voidErrorCheck
                       (param_1,*(uint *)(pTVar56 + -0x30),psVar21,(unsigned char *)param_4);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    for (uVar57 = 0; pTVar3 = local_878, pTVar31 = local_7f0, pTVar32 = local_750[0],
        uVar57 < (uint)((int)(*(uint *)(local_870 + 8) - *(uint *)(local_870 + 4)) >> 3);
        uVar57 = uVar57 + 1) {
      piVar61 = *(int **)(*(uint *)(local_870 + 4) + uVar57 * 8);
      uVar28 = *(uint *)(pTVar56 + -0x40);
      param_4 = *(char **)(pTVar56 + -0x3c);
      param_5 = *(char **)(pTVar56 + -0x34);
      (**(code **)(*piVar61 + 0xc))(piVar61,*(uint *)(pTVar56 + -0x48),uVar28,param_4,param_5);
      piVar61 = *(int **)(pTVar56 + -0x34);
      if (piVar61 != (int *)0x0) {
        piVar50 = *(int **)(*(uint *)(local_870 + 4) + uVar57 * 8);
        iVar55 = *piVar50;
        uVar16 = (**(code **)(*piVar61 + 0x18))
                           (piVar61,a1_11,uVar28,param_4,param_5,pTVar33,*piVar61);
        (**(code **)(iVar55 + 0x10))(piVar50,uVar16);
      }
    }
    break;
  case 0xa3:
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pvVar14 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x10);
    in_cr0 = (pvVar14 == (unsigned char *)0x0) << 1;
    pTVar3 = (unsigned char *)(unsigned char *)0x0;
    if (pvVar14 != (unsigned char *)0x0) {
      local_180 = GetGlobalPoolAllocator();
      *(undefined4 *)(pvVar14 + 0xc) = 0;
      *(undefined4 *)pvVar14 = local_180;
      *(undefined4 *)(pvVar14 + 4) = 0;
      *(undefined4 *)(pvVar14 + 8) = 0;
      pTVar3 = (unsigned char *)pvVar14;
    }
    goto LAB_97baadbc;
  case 0xa4:
    pTVar3 = local_870;
LAB_97baadbc:
    local_870 = pTVar3;
    puVar25 = *(uint **)(local_870 + 8);
    if (puVar25 == *(uint **)(local_870 + 0xc)) {
      std__vector_TTypeLine_pool_allocator_TTypeLine_____M_insert_aux
                ((unsigned char *)local_870,puVar25,pTVar56 + 0x10);
      pTVar3 = local_878;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
    }
    else {
      iVar55 = 0;
      if (puVar25 != (uint *)0x0) {
        uVar57 = *(uint *)(pTVar56 + 0x14);
        *puVar25 = *(uint *)(pTVar56 + 0x10);
        puVar25[1] = uVar57;
        iVar55 = *(int *)(local_870 + 8);
      }
      *(int *)(local_870 + 8) = iVar55 + 8;
      pTVar3 = local_878;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
    }
    break;
  case 0xa5:
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pTVar33 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    pTVar3 = (unsigned char *)0xa7b8374c;
    ppuVar35 = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined ***)pTVar33 = &PTR___ZN5TTypeD1Ev_a7b7d640;
    pTVar7 = (unsigned char *)((uint)*(unsigned char **)(pTVar33 + 0x24) & 0x9ff | 0x800);
    in_cr0 = (pTVar7 == (unsigned char *)0x0) << 1;
    *(unsigned char **)(pTVar33 + 0x20) = (unsigned char *)0x0;
    *(unsigned char **)(pTVar33 + 0x24) = pTVar7;
    *(unsigned char **)(pTVar33 + 4) = (unsigned char *)0x0;
    *(unsigned char **)(pTVar33 + 8) = (unsigned char *)0x0;
    *(unsigned char **)(pTVar33 + 0xc) = (unsigned char *)0x0;
    *(unsigned char **)(pTVar33 + 0x10) = (unsigned char *)0x0;
    *(unsigned char **)(pTVar33 + 0x14) = (unsigned char *)0x0;
    *(unsigned char **)(pTVar33 + 0x18) = (unsigned char *)0x0;
    *(unsigned char **)(pTVar33 + 0x1c) = (unsigned char *)0x0;
    local_86c = *(unsigned char **)pTVar56;
    puVar5 = *(undefined **)(pTVar56 + 4);
    pcVar40 = *(code **)(*(unsigned char **)pTVar33 + 0x14);
    local_870 = pTVar33;
    goto LAB_97baae6c;
  case 0xa6:
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    local_870 = (unsigned char *)TPoolAllocator__allocate(pTVar17,0x28);
    pTVar33 = (unsigned char *)0xa7b8374c;
    ppuVar35 = &PTR___ZN5TTypeD1Ev_a7b7d640;
    *(undefined ***)local_870 = &PTR___ZN5TTypeD1Ev_a7b7d640;
    pTVar3 = (unsigned char *)((uint)*(unsigned char **)(local_870 + 0x24) & 0x9ff | 0x800);
    in_cr0 = (pTVar3 == (unsigned char *)0x0) << 1;
    *(unsigned char **)(local_870 + 0x20) = (unsigned char *)0x0;
    *(unsigned char **)(local_870 + 0x24) = pTVar3;
    *(unsigned char **)(local_870 + 4) = (unsigned char *)0x0;
    *(unsigned char **)(local_870 + 8) = (unsigned char *)0x0;
    *(unsigned char **)(local_870 + 0xc) = (unsigned char *)0x0;
    *(unsigned char **)(local_870 + 0x10) = (unsigned char *)0x0;
    *(unsigned char **)(local_870 + 0x14) = (unsigned char *)0x0;
    *(unsigned char **)(local_870 + 0x18) = (unsigned char *)0x0;
    *(unsigned char **)(local_870 + 0x1c) = (unsigned char *)0x0;
    local_86c = *(unsigned char **)(pTVar56 + -0x84);
    (**(code **)(*(unsigned char **)local_870 + 0x14))
              (local_870,*(uint *)(pTVar56 + -0x80),param_3,param_4,param_5,0xa7b8374c,
               &PTR___ZN5TTypeD1Ev_a7b7d640);
    iVar55 = (**(code **)(**(int **)(pTVar56 + -0x24) + 0x18))(*(int **)(pTVar56 + -0x24));
    if (iVar55 != 0) {
      piVar61 = (int *)(**(code **)(**(int **)(pTVar56 + -0x24) + 0x18))(*(int **)(pTVar56 + -0x24))
      ;
      iVar55 = (**(code **)(*piVar61 + 0x40))(piVar61);
      if ((iVar55 == 2) &&
         (iVar55 = (**(code **)(**(int **)(pTVar56 + -0x24) + 0x18))(*(int **)(pTVar56 + -0x24)),
         pTVar3 = local_870, 0 < **(int **)(iVar55 + 0x30))) {
        iVar55 = (**(code **)(**(int **)(pTVar56 + -0x24) + 0x18))
                           (*(int **)(pTVar56 + -0x24),a1_12,param_3,param_4,param_5,pTVar33,
                            ppuVar35,param_8);
        pTVar7 = (unsigned char *)**(uint **)(iVar55 + 0x30);
        *(unsigned char **)(pTVar3 + 0x24) =
             (unsigned char *)((uint)*(unsigned char **)(pTVar3 + 0x24) | 0x200);
        *(unsigned char **)(pTVar3 + 4) = pTVar7;
        pTVar3 = local_878;
        pTVar31 = local_7f0;
        pTVar32 = local_750[0];
        break;
      }
    }
    param_8 = *(uint *)(pTVar56 + -0x80);
    local_64 = (unsigned char *)0xa7b8374c;
    piVar61 = *(int **)(param_8 + 4);
    pcVar29 = "structure field array size must be a positive integer";
    *(unsigned char *)((int)piVar61 + piVar61[-3]) = *DAT_a7b7ba88;
    param_4 = *(char **)(param_8 + 4);
    pcVar62 = *(char **)(pTVar56 + -0x58);
    goto LAB_97bab5e8;
  case 0xb1:
    pvVar51 = *(unsigned char **)((int)param_1 + 4);
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
    piVar61 = *(int **)(pvVar51 + 4);
    local_160[0] = puVar18;
    if (piVar61 == *(int **)(pvVar51 + 8)) {
      std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                (pvVar51,piVar61,local_160);
      pTVar3 = local_878;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
    }
    else {
      iVar55 = 0;
      if (piVar61 != (int *)0x0) {
        *piVar61 = (int)puVar18;
        iVar55 = *(int *)(pvVar51 + 4);
      }
      *(int *)(pvVar51 + 4) = iVar55 + 4;
      pTVar3 = local_878;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
    }
    break;
  case 0xb2:
    piVar61 = *(int **)((int)param_1 + 4);
    iVar55 = piVar61[1];
    pvVar23 = *(void **)(*piVar61 + ((iVar55 - *piVar61 & 0xfffffffcU) - 4));
    if (pvVar23 != (void *)0x0) {
      ((int (*)())__ZN17TSymbolTableLevelD1Ev)(pvVar23);
      iVar55 = piVar61[1];
    }
    piVar61[1] = iVar55 + -4;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xb3:
    piVar61 = *(int **)(pTVar56 + -0x50);
    pTVar3 = (unsigned char *)0x0;
    if (piVar61 != (int *)0x0) {
      (**(code **)(*piVar61 + 0x60))(piVar61,1);
      pTVar3 = *(unsigned char **)(pTVar56 + -0x50);
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
    }
    break;
  case 0xb8:
    pTVar15 = *(unsigned char **)param_1;
    uVar57 = 0;
    pTVar20 = *(unsigned char **)(pTVar56 + 8);
LAB_97bab0ec:
    pTVar3 = (unsigned char *)TIntermediate__makeAggregate(pTVar15,pTVar20,uVar57);
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xb9:
    pTVar15 = *(unsigned char **)param_1;
    param_4 = (char *)0x0;
    pTVar22 = *(unsigned char **)(pTVar56 + -0x24);
    pTVar20 = *(unsigned char **)(pTVar56 + 8);
    goto LAB_97ba97d8;
  case 0xbc:
    iVar55 = __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped
                       (param_1,*(uint *)(pTVar56 + -0xb0),*(unsigned char **)(pTVar56 + -0x50),
                        param_4,param_5,pTVar33);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    local_850 = *(unsigned char **)(pTVar56 + 8);
    param_4 = *(char **)(pTVar56 + 0xc);
    param_5 = *(char **)(pTVar56 + -0xb0);
    local_84c = (unsigned char *)param_4;
    pTVar3 = (unsigned char *)
             __ZN13TIntermediate12addSelectionEP12TIntermTyped15TIntermNodePairi
                       (*(unsigned char **)param_1,*(uint *)(pTVar56 + -0x50),local_850,param_4,
                        param_5);
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xbd:
  case 0xcc:
    local_874 = *(uint *)(pTVar56 + 8);
    pTVar3 = *(unsigned char **)(pTVar56 + -0x50);
    break;
  case 0xbe:
    pTVar3 = *(unsigned char **)(pTVar56 + 8);
    goto LAB_97bab424;
  case 0xbf:
    local_878 = *(unsigned char **)(pTVar56 + 8);
    iVar55 = (**(code **)**(undefined4 **)(pTVar56 + 8))(*(undefined4 **)(pTVar56 + 8));
    iVar55 = __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped
                       (param_1,iVar55,*(unsigned char **)(pTVar56 + 8),param_4,param_5,pTVar33);
    goto LAB_97bab180;
  case 0xc0:
    pTVar59 = pTVar56 + -0x74;
    iVar55 = TParseContext__structQualifierErrorCheck
                       (param_1,*(uint *)(pTVar56 + -0x58),(unsigned char *)pTVar59,param_4,param_5,
                        pTVar33,pTVar34);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    iVar55 = __ZN13TParseContext14boolErrorCheckEiRK11TPublicType
                       (param_1,*(uint *)(pTVar56 + -0x58),(unsigned char *)pTVar59);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    param_5 = *(char **)(pTVar56 + 8);
    iVar55 = TParseContext__executeInitializer
                       (param_1,*(uint *)(pTVar56 + -0x58),*(unsigned char **)(pTVar56 + -0x54),
                        (unsigned char *)pTVar59,(unsigned char *)param_5,&pTStack_70);
    param_4 = (char *)pTVar59;
    if (iVar55 == 0) goto switchD_97ba39c8_caseD_2;
LAB_97bab1f4:
    TParseContext__recover(param_1);
    param_4 = (char *)pTVar59;
    pTVar3 = (unsigned char *)0x0;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xc1:
    pvVar51 = *(unsigned char **)((int)param_1 + 4);
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    puVar18 = (undefined4 *)TPoolAllocator__allocate(pTVar17,0x10);
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    local_150 = pTVar17;
    goto LAB_97bab2e8;
  case 0xc2:
    piVar61 = *(int **)((int)param_1 + 4);
    iVar55 = piVar61[1];
    pvVar23 = *(void **)(*piVar61 + ((iVar55 - *piVar61 & 0xfffffffcU) - 4));
    if (pvVar23 != (void *)0x0) {
      ((int (*)())__ZN17TSymbolTableLevelD1Ev)(pvVar23);
      iVar55 = piVar61[1];
    }
    piVar61[1] = iVar55 + -4;
    param_5 = (char *)0x1;
    pTVar15 = *(unsigned char **)param_1;
    pTVar20 = *(unsigned char **)(pTVar56 + 8);
    pTVar3 = *(unsigned char **)(pTVar56 + -0x50);
    uVar57 = *(uint *)(pTVar56 + -0xdc);
    goto LAB_97bab2b4;
  case 0xc3:
    goto switchD_97ba39c8_caseD_c3;
  case 0xc4:
    iVar55 = __ZN13TParseContext14boolErrorCheckEiPK12TIntermTyped
                       (param_1,*(uint *)pTVar56,*(unsigned char **)(pTVar56 + -0x50),param_4,param_5
                        ,pTVar33);
    if (iVar55 != 0) {
      TParseContext__recover(param_1);
    }
    pTVar15 = *(unsigned char **)param_1;
    pTVar20 = *(unsigned char **)(pTVar56 + -0xd4);
    param_5 = (char *)0x0;
    pTVar3 = *(unsigned char **)(pTVar56 + -0x50);
    uVar57 = *(uint *)(pTVar56 + -0xb0);
LAB_97bab2b4:
    param_4 = (char *)0x0;
    local_878 = (unsigned char *)
                TIntermediate__addLoop(pTVar15,pTVar20,pTVar3,(unsigned char *)0x0,param_5,uVar57);
    iVar55 = *(int *)((int)param_1 + 0x20);
LAB_97bab40c:
    iVar55 = iVar55 + -1;
    goto LAB_97bab410;
  case 0xc5:
    pvVar51 = *(unsigned char **)((int)param_1 + 4);
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
    puVar19 = *(undefined4 **)(pvVar51 + 4);
    local_160[0] = puVar18;
    if (puVar19 == *(undefined4 **)(pvVar51 + 8)) {
      std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                (pvVar51,puVar19,local_160);
    }
    else {
      iVar55 = 0;
      if (puVar19 != (undefined4 *)0x0) {
        *puVar19 = puVar18;
        iVar55 = *(int *)(pvVar51 + 4);
      }
      *(int *)(pvVar51 + 4) = iVar55 + 4;
    }
switchD_97ba39c8_caseD_c3:
    iVar55 = *(int *)((int)param_1 + 0x20) + 1;
LAB_97bab410:
    *(int *)((int)param_1 + 0x20) = iVar55;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xc6:
    piVar61 = *(int **)((int)param_1 + 4);
    iVar55 = piVar61[1];
    pvVar23 = *(void **)(*piVar61 + ((iVar55 - *piVar61 & 0xfffffffcU) - 4));
    if (pvVar23 != (void *)0x0) {
      ((int (*)())__ZN17TSymbolTableLevelD1Ev)(pvVar23);
      iVar55 = piVar61[1];
    }
    piVar61[1] = iVar55 + -4;
    local_878 = (unsigned char *)
                TIntermediate__makeAggregate
                          (*(unsigned char **)param_1,*(unsigned char **)(pTVar56 + -0x7c),
                           *(uint *)(pTVar56 + -0xdc));
    param_5 = (char *)0x1;
    pTVar20 = (unsigned char *)
              TIntermediate__addLoop
                        (*(unsigned char **)param_1,*(unsigned char **)(pTVar56 + 8),
                         *(unsigned char **)(pTVar56 + -0x50),*(unsigned char **)(pTVar56 + -0x4c),1,
                         *(uint *)(pTVar56 + -0x108));
    param_4 = *(char **)(pTVar56 + -0x108);
    local_878 = (unsigned char *)
                TIntermediate__growAggregate
                          (*(unsigned char **)param_1,(unsigned char *)local_878,pTVar20,(int)param_4)
    ;
    piVar61 = (int *)(**(code **)(*(unsigned char **)local_878 + 0x1c))(local_878);
    (**(code **)(*piVar61 + 0x60))(piVar61,1);
    iVar55 = *(int *)((int)param_1 + 0x20);
    goto LAB_97bab40c;
  case 0xcb:
    pTVar3 = *(unsigned char **)(pTVar56 + -0x24);
LAB_97bab424:
    local_874 = 0;
    break;
  case 0xcd:
    if (*(int *)((int)param_1 + 0x20) < 1) {
      param_4 = "";
      param_5 = param_4;
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + -0x2c),"continue statement only allowed in loops"
                 ,"","",pTVar33,pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    pvVar23 = *(void **)param_1;
    uVar16 = 0x65;
    goto LAB_97bab644;
  case 0xce:
    if (*(int *)((int)param_1 + 0x20) < 1) {
      param_4 = "";
      param_5 = param_4;
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + -0x2c),"break statement only allowed in loops",""
                 ,"",pTVar33,pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    pvVar23 = *(void **)param_1;
    uVar16 = 100;
    goto LAB_97bab644;
  case 0xcf:
    uVar57 = *(uint *)(pTVar56 + -0x2c);
    uVar64 = __ZN13TIntermediate9addBranchE9TOperatori(*(void **)param_1,99,uVar57);
    local_878 = (unsigned char *)((ulonglong)uVar64 >> 0x20);
    piVar61 = (int *)**(undefined4 **)((int)param_1 + 0x28);
    iVar55 = (*(code *)piVar61[8])
                       (*(undefined4 **)((int)param_1 + 0x28),(int)uVar64,uVar57,param_4,param_5,
                        pTVar33,piVar61);
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    if (iVar55 == 0) break;
    pcVar62 = *(char **)(pTVar56 + -0x2c);
    pcVar29 = "non-void function must return a value";
    goto LAB_97bab5e4;
  case 0xd0:
    uVar57 = *(uint *)(pTVar56 + -0x24);
    param_4 = *(char **)(pTVar56 + -0x58);
    uVar64 = __ZN13TIntermediate9addBranchE9TOperatorP12TIntermTypedi
                       (*(void **)param_1,99,uVar57,param_4);
    local_878 = (unsigned char *)((ulonglong)uVar64 >> 0x20);
    piVar61 = *(int **)((int)param_1 + 0x28);
    *(undefined4 *)((int)param_1 + 0x2c) = 1;
    iVar55 = (**(code **)(*piVar61 + 0x20))
                       (piVar61,(int)uVar64,uVar57,param_4,param_5,pTVar33,piVar61);
    if (iVar55 == 0) {
      pcVar62 = *(char **)(pTVar56 + -0x58);
      pcVar29 = "void function cannot return a value";
    }
    else {
      iVar55 = *(int *)((int)param_1 + 0x28);
      (**(code **)(**(int **)(pTVar56 + -0x24) + 0x38))
                (&local_850,*(int **)(pTVar56 + -0x24),uVar57,param_4,param_5);
      bVar37 = false;
      if (((*(uint *)(iVar55 + 0x24) & 0x1fffe00) == ((uint)local_82c & 0x1fffe00)) &&
         (*(unsigned char **)(iVar55 + 8) == local_848)) {
        bVar37 = true;
      }
      local_5c = (unsigned char *)0xa7b8374c;
      local_850 = (unsigned char *)&PTR___ZN5TTypeD1Ev_a7b7d640;
      pTVar3 = local_878;
      pTVar31 = local_7f0;
      pTVar32 = local_750[0];
      if (bVar37) break;
      pcVar62 = *(char **)(pTVar56 + -0x58);
      pcVar29 = "function return is not matching type:";
      piVar61 = (int *)0x0;
    }
LAB_97bab5e4:
    param_4 = "return";
LAB_97bab5e8:
    param_5 = "";
    TParseContext__error((int)param_1,pcVar62,pcVar29,param_4,"",pTVar33,piVar61,param_8);
    goto LAB_97bab5f4;
  case 0xd1:
    if (*(int *)((int)param_1 + 0xc) != 1) {
      param_5 = "";
      param_4 = "discard";
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + -0x2c)," supported in fragment shaders only ",
                 "discard","","",pTVar34,param_8);
      TParseContext__recover(param_1);
    }
    pvVar23 = *(void **)param_1;
    uVar16 = 0x62;
LAB_97bab644:
    pTVar3 = (unsigned char *)
             __ZN13TIntermediate9addBranchE9TOperatori(pvVar23,uVar16,*(uint *)(pTVar56 + -0x2c));
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xd2:
    pTVar3 = *(unsigned char **)(pTVar56 + 8);
    goto LAB_97bab674;
  case 0xd3:
    param_4 = (char *)0x0;
    pTVar3 = (unsigned char *)
             TIntermediate__growAggregate
                       (*(unsigned char **)param_1,*(unsigned char **)(pTVar56 + -0x24),
                        *(unsigned char **)(pTVar56 + 8),0);
LAB_97bab674:
    *(unsigned char **)((int)param_1 + 0x10) = pTVar3;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xd6:
    piVar61 = *(int **)(pTVar56 + 0x10);
    piVar50 = *(int **)((int)param_1 + 4);
    uVar16 = (**(code **)(*piVar61 + 8))(piVar61);
    iVar55 = *piVar50;
    iVar54 = (piVar50[1] - iVar55 >> 2) + -1;
    while( true ) {
      iVar60 = *(int *)(iVar55 + iVar54 * 4);
      iVar55 = 0;
      std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_320,iVar60,uVar16);
      if (local_320[0] != *(int *)(iVar60 + 4)) {
        iVar55 = *(int *)(local_320[0] + 0x18);
      }
      iVar54 = iVar54 + -1;
      if ((iVar55 != 0) || (iVar54 < 0)) break;
      iVar55 = *piVar50;
    }
    if (*(int *)(iVar55 + 0x50) != 0) {
      iVar60 = piVar61[1];
      local_64 = (unsigned char *)0xa7b8374c;
      iVar54 = *(int *)(iVar60 + 4);
      param_5 = "";
      *(unsigned char *)(iVar54 + *(int *)(iVar54 + -0xc)) = *DAT_a7b7ba88;
      TParseContext__error
                ((int)param_1,*(char **)pTVar56,"function already has a body",*(char **)(iVar60 + 4)
                 ,"",pTVar33,iVar54,iVar60);
      TParseContext__recover(param_1);
    }
    *(undefined4 *)(iVar55 + 0x50) = 1;
    iVar54 = __ZNKSbIcSt11char_traitsIcE14pool_allocatorIcEE7compareEPKc((void *)piVar61[1],"main");
    local_58 = piVar61 + 3;
    if (iVar54 == 0) {
      iVar54 = piVar61[5] - piVar61[4] >> 3;
      in_cr0 = (iVar54 == 0) << 1;
      if (0 < iVar54) {
        iVar60 = piVar61[1];
        iVar54 = *(int *)(iVar60 + 4);
        param_5 = "";
        *(unsigned char *)(iVar54 + *(int *)(iVar54 + -0xc)) = *DAT_a7b7ba88;
        TParseContext__error
                  ((int)param_1,*(char **)pTVar56,"function cannot take any parameter(s)",
                   *(char **)(iVar60 + 4),"",pTVar33,iVar54,iVar60);
        TParseContext__recover(param_1);
      }
      iVar54 = (**(code **)(piVar61[7] + 0x20))(piVar61 + 7);
      if (iVar54 != 0) {
        iVar60 = piVar61[1];
        local_64 = (unsigned char *)0xa7b8374c;
        iVar54 = *(int *)(iVar60 + 4);
        param_5 = "";
        *(unsigned char *)(iVar54 + *(int *)(iVar54 + -0xc)) = *DAT_a7b7ba88;
        TParseContext__error
                  ((int)param_1,*(char **)pTVar56,"function cannot return a value",
                   *(char **)(iVar60 + 4),"",pTVar33,iVar54,iVar60);
        TParseContext__recover(param_1);
      }
    }
    pvVar51 = *(unsigned char **)((int)param_1 + 4);
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
    puVar19 = *(undefined4 **)(pvVar51 + 4);
    local_160[0] = puVar18;
    if (puVar19 == *(undefined4 **)(pvVar51 + 8)) {
      std__vector_TSymbolTableLevel__std__allocator_TSymbolTableLevel______M_insert_aux
                (pvVar51,puVar19,local_160);
    }
    else {
      iVar54 = 0;
      if (puVar19 != (undefined4 *)0x0) {
        *puVar19 = puVar18;
        iVar54 = *(int *)(pvVar51 + 4);
      }
      *(int *)(pvVar51 + 4) = iVar54 + 4;
    }
    *(int *)((int)param_1 + 0x28) = iVar55 + 0x1c;
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
    uVar57 = *(uint *)(pTVar20 + 0x2c);
    *(uint *)(pTVar20 + 0x2c) = uVar57 & 0x1ffffff;
    *(uint *)(pTVar20 + 0x2c) = uVar57 & 0x7ffff | 0x80000;
    *(uint *)(pTVar20 + 0x2c) = uVar57 & 0x7ff | 0x80800;
    *(uint *)(pTVar20 + 0x2c) = uVar57 & 0x3ff | 0x80800;
    puVar5 = PTR_vtable_a7b7c0d0;
    *(uint *)(pTVar20 + 0x2c) = uVar57 & 0x1ff | 0x80800;
    *(undefined **)pTVar20 = puVar5 + 8;
    *(undefined4 *)(pTVar20 + 0x30) = 0;
    local_120 = GetGlobalPoolAllocator();
    *(undefined4 *)(pTVar20 + 0x40) = 0;
    *(undefined4 *)(pTVar20 + 0x38) = 0;
    *(undefined4 *)(pTVar20 + 0x3c) = 0;
    *(undefined4 *)(pTVar20 + 0x34) = local_120;
    local_110 = GetGlobalPoolAllocator();
    *(undefined4 *)(pTVar20 + 0x44) = local_110;
    iVar55 = DAT_a7b7ba84;
    *(undefined4 *)(pTVar20 + 0x50) = 0;
    *(undefined4 *)(pTVar20 + 0x48) = 0;
    piVar50 = (int *)(iVar55 + 8);
    *(undefined4 *)(pTVar20 + 0x4c) = 0;
    do {
      if (in_RESERVE != '\0') {
        iVar54 = storeWordConditionalIndexed(*piVar50 + 1,0,piVar50);
        *piVar50 = iVar54;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    local_100 = GetGlobalPoolAllocator();
    *(int *)(pTVar20 + 0x58) = iVar55 + 0xc;
    *(undefined4 *)(pTVar20 + 0x68) = 0;
    *(undefined4 *)(pTVar20 + 0x5c) = 0;
    *(undefined4 *)(pTVar20 + 0x54) = local_100;
    local_54 = -0x5847c8b4;
    local_68 = &TType__vtable;
    for (iVar55 = 0; iVar55 < local_58[2] - local_58[1] >> 3; iVar55 = iVar55 + 1) {
      iVar60 = piVar61[4];
      iVar54 = iVar55 * 8;
      if (*(int *)(iVar60 + iVar54) == 0) {
        local_d0[0] = GetGlobalPoolAllocator();
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
                  (&local_850,"",(unsigned char *)local_d0);
        param_5 = *(char **)pTVar56;
        pTVar22 = (unsigned char *)
                  TIntermediate__addSymbol
                            (*(unsigned char **)param_1,0,(unsigned char *)&local_850,
                             *(unsigned char **)(iVar60 + iVar54 + 4),(int)param_5);
        pTVar20 = (unsigned char *)
                  TIntermediate__growAggregate
                            (*(unsigned char **)param_1,pTVar20,pTVar22,*(uint *)pTVar56);
        pTVar3 = local_84c + -4;
        local_c0[0] = local_850;
        do {
          uVar57 = *(uint *)pTVar3;
          if (in_RESERVE != '\0') {
            uVar28 = storeWordConditionalIndexed(uVar57 - 1,0,pTVar3);
            *(uint *)pTVar3 = uVar28;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
        if ((int)uVar57 < 1) {
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                    ((unsigned char *)(local_84c + -0xc),local_c0);
        }
      }
      else {
        pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
        a0_00 = (int *)TPoolAllocator__allocate(pTVar17,0x40);
        puVar5 = PTR_vtable_a7b7c0b4 + 8;
        iVar36 = *(int *)(iVar60 + iVar54 + 4);
        a0_00[1] = *(int *)(iVar60 + iVar54);
        *a0_00 = (int)puVar5;
        iVar38 = *(int *)(iVar36 + 0xc);
        a5 = *(int *)(iVar36 + 0x10);
        a4_00 = *(int *)(iVar36 + 0x14);
        a3 = *(int *)(iVar36 + 0x18);
        iVar30 = *(int *)(iVar36 + 0x1c);
        iVar26 = *(int *)(iVar36 + 0x20);
        iVar6 = *(int *)(iVar36 + 4);
        iVar39 = *(int *)(iVar36 + 8);
        a0_00[3] = (int)(local_68 + 8);
        a0_00[6] = iVar38;
        a0_00[7] = a5;
        a0_00[8] = a4_00;
        a0_00[9] = a3;
        a0_00[10] = iVar30;
        a0_00[0xb] = iVar26;
        a0_00[5] = iVar39;
        a0_00[4] = iVar6;
        uVar2 = a0_00[0xc];
        uVar28 = *(uint *)(iVar36 + 0x24) & 0xfe000000;
        a0_00[0xc] = uVar28 | uVar2 & 0x1ffffff;
        uVar53 = (*(uint *)(iVar36 + 0x24) >> 0x13 & 0x3f) << 0x13;
        a0_00[0xc] = uVar53 | uVar28 | uVar2 & 0x7ffff;
        uVar57 = *(uint *)(iVar36 + 0x24) & 0x7f800;
        a0_00[0xc] = uVar57 | uVar53 | uVar28 | uVar2 & 0x7ff;
        uVar58 = (*(uint *)(iVar36 + 0x24) >> 10 & 1) << 10;
        a0_00[0xc] = uVar58 | uVar57 | uVar53 | uVar28 | uVar2 & 0x3ff;
        a0_00[0xc] = (*(uint *)(iVar36 + 0x24) >> 9 & 1) << 9 |
                     uVar58 | uVar57 | uVar53 | uVar28 | uVar2 & 0x1ff;
        a0_00[0xd] = 0;
        a0_00[0xe] = 0;
        a0_00[0xf] = 0;
        piVar50 = *(int **)((int)param_1 + 4);
        iVar6 = piVar50[3];
        piVar50[3] = iVar6 + 1;
        a0_00[2] = iVar6 + 1;
        uVar16 = *(undefined4 *)(*piVar50 + ((piVar50[1] - *piVar50 & 0xfffffffcU) - 4));
        local_84c = (unsigned char *)0x0;
        psVar21 = (unsigned char *)(**(code **)(*a0_00 + 8))(a0_00,iVar26,iVar30,a3,a4_00,a5,piVar50);
        __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_f0,psVar21);
        local_e8 = a0_00;
        std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_840,uVar16,&local_f0);
        local_850 = local_840;
        piVar50 = (int *)(local_ec + -4);
        local_84c = local_83c;
        local_e0[0] = local_f0;
        do {
          iVar6 = *piVar50;
          if (in_RESERVE != '\0') {
            iVar26 = storeWordConditionalIndexed(iVar6 + -1,0,piVar50);
            *piVar50 = iVar26;
            in_cr0 = 2;
          }
        } while (!(bool)(in_cr0 >> 1 & 1));
        if (iVar6 < 1) {
          __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                    ((unsigned char *)(local_ec + -0xc),local_e0);
        }
        if (local_84c == (unsigned char *)0x0) {
          iVar26 = a0_00[1];
          iVar6 = *(int *)(iVar26 + 4);
          *(undefined1 *)(iVar6 + *(int *)(iVar6 + -0xc)) = **(undefined1 **)(local_54 + -0x7cc4);
          TParseContext__error
                    ((int)param_1,*(char **)pTVar56,"redefinition",*(char **)(iVar26 + 4),"",
                     local_54,iVar6,iVar26);
          TParseContext__recover(param_1);
          (**(code **)(*a0_00 + 4))(a0_00);
        }
        *(undefined4 *)(iVar60 + iVar54) = 0;
        param_5 = *(char **)pTVar56;
        pTVar22 = (unsigned char *)
                  TIntermediate__addSymbol
                            (*(unsigned char **)param_1,a0_00[2],(unsigned char *)a0_00[1],
                             (unsigned char *)(a0_00 + 3),(int)param_5);
        pTVar20 = (unsigned char *)
                  TIntermediate__growAggregate
                            (*(unsigned char **)param_1,pTVar20,pTVar22,*(uint *)pTVar56);
      }
    }
    param_4 = *(char **)pTVar56;
    TIntermediate__setAggregateOperator(*(unsigned char **)param_1,pTVar20,4,param_4);
    *(unsigned char **)(pTVar56 + 8) = pTVar20;
    *(undefined4 *)((int)param_1 + 0x20) = 0;
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
    break;
  case 0xd7:
    local_64 = (unsigned char *)0xa7b8374c;
    iVar55 = (**(code **)(**(int **)((int)param_1 + 0x28) + 0x20))(*(int **)((int)param_1 + 0x28));
    pTVar3 = DAT_a7b7ba88;
    if ((iVar55 != 0) && (local_64 = (unsigned char *)0xa7b8374c, *(int *)((int)param_1 + 0x2c) == 0)
       ) {
      iVar55 = *(int *)(*(uint *)(pTVar56 + -0x48) + 4);
      param_5 = "";
      *(unsigned char *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
           *DAT_a7b7ba88;
      TParseContext__error
                ((int)param_1,*(char **)(pTVar56 + -0x58),"function does not return a value",
                 *(char **)(iVar55 + 4),"",0xa7b8374c,pTVar3,iVar55);
      TParseContext__recover(param_1);
    }
    piVar61 = *(int **)((int)param_1 + 4);
    iVar55 = piVar61[1];
    pvVar23 = *(void **)(*piVar61 + ((iVar55 - *piVar61 & 0xfffffffcU) - 4));
    if (pvVar23 != (void *)0x0) {
      ((int (*)())__ZN17TSymbolTableLevelD1Ev)(pvVar23);
      iVar55 = piVar61[1];
    }
    piVar61[1] = iVar55 + -4;
    local_878 = (unsigned char *)
                TIntermediate__growAggregate
                          (*(unsigned char **)param_1,*(unsigned char **)(pTVar56 + -0x50),
                           *(unsigned char **)(pTVar56 + 8),0);
    param_4 = *(char **)(pTVar56 + -0x58);
    TIntermediate__setAggregateOperator
              (*(unsigned char **)param_1,(unsigned char *)local_878,3,param_4);
    iVar55 = (**(code **)(**(int **)(pTVar56 + -0x48) + 8))(*(int **)(pTVar56 + -0x48));
    *(undefined1 *)(*(int *)(iVar55 + 4) + *(int *)(*(int *)(iVar55 + 4) + -0xc)) =
         **(undefined1 **)(local_64 + -0x7cc4);
    pcVar62 = *(char **)(iVar55 + 4);
    local_b0[0] = GetGlobalPoolAllocator();
    __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1EPKcRKS2_
              (&local_850,pcVar62,(unsigned char *)local_b0);
    piVar61 = (int *)(**(code **)(*(uint *)local_878 + 0x1c))(local_878);
    (**(code **)(*piVar61 + 0x68))(piVar61,&local_850);
    pTVar3 = local_84c + -4;
    local_a0[0] = local_850;
    do {
      pTVar7 = *(unsigned char **)pTVar3;
      if (in_RESERVE != '\0') {
        pTVar33 = (unsigned char *)storeWordConditionalIndexed(pTVar7 + -1,0,pTVar3);
        *(unsigned char **)pTVar3 = pTVar33;
        in_cr0 = 2;
      }
    } while (!(bool)(in_cr0 >> 1 & 1));
    if ((int)pTVar7 < 1) {
      __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEE4_Rep10_M_destroyERKS2_
                ((unsigned char *)(local_84c + -0xc),local_a0);
    }
    uVar57 = *(uint *)(pTVar56 + -0x48);
    piVar61 = (int *)(**(code **)(*(uint *)local_878 + 0x1c))(local_878);
    (**(code **)(*piVar61 + 0x34))(piVar61,uVar57 + 0x1c);
    iVar55 = (**(code **)(*(uint *)local_878 + 0x1c))(local_878);
    *(undefined4 *)(iVar55 + 0x60) = *(undefined4 *)((int)param_1 + 0x40);
    iVar55 = (**(code **)(*(uint *)local_878 + 0x1c))(local_878);
    *(undefined4 *)(iVar55 + 100) = *(undefined4 *)((int)param_1 + 0x44);
    this_00 = (unsigned char *)(**(code **)(*(uint *)local_878 + 0x1c))(local_878);
    TIntermAggregate__addToPragmaTable(this_00,(unsigned char *)((int)param_1 + 0x48));
    pTVar3 = local_878;
    pTVar31 = local_7f0;
    pTVar32 = local_750[0];
  }
switchD_97ba39c8_caseD_0:
  local_750[0] = pTVar32;
  local_7f0 = pTVar31;
  local_878 = pTVar3;
  param_3 = (char *)0x2c;
  pTVar46 = pTVar46 + iVar48 * -2;
  pTVar56 = pTVar56 + iVar48 * -0x2c + 0x2c;
  _memcpy(pTVar56,&local_880,0x2c);
  param_8 = *(short *)(" !\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^" +
                      local_6c + 0x40) * 2;
  param_7 = &_yypgoto + param_8;
  uVar57 = (int)*(short *)(&DAT_97c36138 + param_8) + (int)*(short *)pTVar46;
  param_2 = extraout_r4_16;
  if ((uVar57 < 0x4f0) &&
     (param_7 = (undefined *)(uVar57 * 2),
     (int)*(short *)(&_yycheck + (int)param_7) == (int)*(short *)pTVar46)) {
    iVar48 = (int)*(short *)(&_yytable + (int)param_7);
  }
  else {
    iVar48 = (int)*(short *)(&DAT_97c35e08 + param_8);
  }
  goto LAB_97ba3784;
LAB_97ba8338:
  iVar60 = *(int *)(iVar55 + iVar54 * 4);
  iVar55 = 0;
  pcVar29 = pcVar62;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______find((unsigned char *)local_320,iVar60,pcVar62);
  if (local_320[0] != *(int *)(iVar60 + 4)) {
    iVar55 = *(int *)(local_320[0] + 0x18);
  }
  iVar54 = iVar54 + -1;
  uVar16 = extraout_r4_12;
  if (iVar55 == 0) {
    if (-1 < iVar54) goto LAB_97ba8334;
  }
  else {
    uVar57 = *(uint *)(pTVar56 + -0x1c);
    iVar54 = iVar55 + 0x1c;
    pTVar33 = (unsigned char *)0x0;
    if (((*(uint *)(iVar55 + 0x40) & 0x1fffe00) == (*(uint *)(uVar57 + 0x40) & 0x1fffe00)) &&
       (*(int *)(iVar55 + 0x24) == *(int *)(uVar57 + 0x24))) {
      pTVar33 = (unsigned char *)0x1;
    }
    if (pTVar33 == (unsigned char *)0x0) {
      param_4 = (char *)TType__getBasicString(*(uint *)(uVar57 + 0x40) >> 0x13 & 0x3f);
      pcVar29 = "overloaded functions must have the same return type";
      param_5 = "";
      TParseContext__error
                ((int)param_1,*(char **)pTVar56,
                 "overloaded functions must have the same return type",param_4,"",pTVar33,iVar54,
                 uVar57);
      TParseContext__recover(param_1);
      uVar16 = extraout_r4_13;
    }
    for (iVar54 = 0; iVar54 < *(int *)(iVar55 + 0x14) - *(int *)(iVar55 + 0x10) >> 3;
        iVar54 = iVar54 + 1) {
      iVar60 = iVar54 * 8;
      piVar61 = *(int **)(*(int *)(iVar55 + 0x10) + iVar60 + 4);
      iVar6 = *piVar61;
      iVar6 = (**(code **)(iVar6 + 0x24))(piVar61,uVar16,pcVar29,param_4,param_5,pTVar33,iVar6);
      piVar61 = *(int **)(*(int *)(*(uint *)(pTVar56 + -0x1c) + 0x10) + iVar60 + 4);
      iVar26 = *piVar61;
      iVar26 = (**(code **)(iVar26 + 0x24))(piVar61,a1_08,pcVar29,param_4,param_5,pTVar33,iVar26);
      uVar16 = extraout_r4_14;
      if (iVar6 != iVar26) {
        iVar60 = *(int *)(*(int *)(*(uint *)(pTVar56 + -0x1c) + 0x10) + iVar60 + 4);
        param_4 = (char *)getQualifierString(*(uint *)(iVar60 + 0x24) >> 0x19);
        pcVar29 = "overloaded functions must have the same parameter qualifiers";
        param_5 = "";
        TParseContext__error
                  ((int)param_1,*(char **)pTVar56,
                   "overloaded functions must have the same parameter qualifiers",param_4,"",pTVar33
                   ,iVar60,uVar57);
        TParseContext__recover(param_1);
        uVar16 = extraout_r4_15;
      }
    }
  }
  goto LAB_97ba84b0;
LAB_97ba8334:
  iVar55 = *piVar61;
  goto LAB_97ba8338;
LAB_97ba84b0:
  pTVar3 = *(unsigned char **)(pTVar56 + -0x1c);
  piVar61 = *(int **)((int)param_1 + 4);
  local_880 = *(uint *)pTVar56;
  iVar55 = piVar61[3];
  piVar61[3] = (int)(iVar55 + 1U);
  *(unsigned char **)(pTVar3 + 8) = (unsigned char *)(iVar55 + 1U);
  uVar49 = *(undefined4 *)(*piVar61 + ((piVar61[1] - *piVar61 & 0xfffffffcU) - 4));
  local_84c = (unsigned char *)0x0;
  local_870 = pTVar3;
  psVar21 = (unsigned char *)
            (**(code **)(*(unsigned char **)pTVar3 + 8))
                      (pTVar3,uVar16,pcVar29,param_4,param_5,pTVar33,piVar61);
  __ZNSbIcSt11char_traitsIcE14pool_allocatorIcEEC1ERKS3_(&local_310,psVar21);
  local_308 = pTVar3;
  std___Rb_tree_std__string_std__pair_std__string_const_TSymbol___std___Select1st_std__pair_std__string_const_TSymbol____std__less_std__string__pool_allocator_std__pair_std__string_const_TSymbol______insert_unique((unsigned char *)&local_840,uVar49,&local_310);
  paVar11 = (unsigned char *)(local_30c + -0xc);
  local_850 = local_840;
  piVar61 = (int *)(local_30c + -4);
  local_84c = local_83c;
  local_300[0] = local_310;
  do {
    iVar55 = *piVar61;
    if (in_RESERVE != '\0') {
      iVar54 = storeWordConditionalIndexed(iVar55 + -1,0,piVar61);
      *piVar61 = iVar54;
      in_cr0 = 2;
    }
  } while (!(bool)(in_cr0 >> 1 & 1));
  bVar37 = 0 < iVar55;
  ppTVar24 = local_300;
  goto LAB_97ba869c;
switchD_97ba39c8_caseD_60:
  param_4 = (char *)pTVar59;
  pTVar3 = (unsigned char *)0x0;
  pTVar31 = local_7f0;
  pTVar32 = local_750[0];
  goto switchD_97ba39c8_caseD_0;
LAB_97ba55dc:
  if ((uint)((int)(*(uint *)(pTVar7 + 8) - *(uint *)(pTVar7 + 4)) >> 3) <= uVar57)
  goto LAB_97ba5740;
  piVar61 = *(int **)(*(uint *)(pTVar7 + 4) + uVar57 * 8);
  iVar55 = *piVar61;
  iVar55 = (**(code **)(iVar55 + 0x1c))(piVar61,uVar16,param_3,param_4,param_5,pTVar33,iVar55);
  uVar28 = *(uint *)(*(int *)(iVar55 + 4) + -0xc);
  local_90 = uVar28;
  uVar53 = *(uint *)(*(int *)(*(uint *)(pTVar56 + 4) + 4) + -0xc);
  local_8c = uVar53;
  puVar25 = &local_8c;
  if (uVar28 <= uVar53) {
    puVar25 = &local_90;
  }
  param_3 = (char *)*puVar25;
  iVar55 = _memcmp(*(undefined4 *)(iVar55 + 4),*(undefined4 *)(*(uint *)(pTVar56 + 4) + 4),param_3);
  in_cr0 = (iVar55 == 0) << 1;
  if (iVar55 == 0) {
    iVar55 = uVar28 - uVar53;
  }
  if (iVar55 != 0) {
    uVar57 = uVar57 + 1;
    uVar16 = extraout_r4_07;
    goto LAB_97ba55dc;
  }
  (**(code **)(**(int **)(pTVar56 + -0x50) + 0x38))(&local_850,*(int **)(pTVar56 + -0x50));
  pTVar33 = local_5c + -0x610c;
  pTVar3 = local_5c;
  local_850 = pTVar33;
  if ((uint)local_82c >> 0x19 == 2) {
    param_3 = *(char **)(pTVar56 + -0x50);
    param_4 = *(char **)(pTVar56 + -0x2c);
    local_878 = (unsigned char *)
                TParseContext__addConstStruct
                          (param_1,*(unsigned char **)(pTVar56 + 4),(unsigned char *)param_3,(int)param_4,
                           param_5,local_5c);
    if (local_878 == (unsigned char *)0x0) goto LAB_97ba5554;
    ppuVar35 = *(undefined ***)(pTVar7 + 4);
    (**(code **)(*(int *)local_878 + 0x34))
              (local_878,ppuVar35[uVar57 * 2],param_3,param_4,param_5,pTVar3,ppuVar35);
    pTVar33 = (unsigned char *)(**(code **)(*(uint *)local_878 + 0x3c))(local_878);
    puVar5 = (undefined *)0x2;
    pcVar40 = *(code **)(*(unsigned char **)pTVar33 + 0x28);
  }
  else {
    pTVar17 = (unsigned char *)GetGlobalPoolAllocator();
    pcVar9 = (unsigned char *)TPoolAllocator__allocate(pTVar17,4);
    *(uint *)pcVar9 = uVar57;
    local_81c = (unsigned char *)0x0;
    local_818 = (unsigned char *)0x0;
    local_7fc = (unsigned char *)((uint)local_7fc & 0x9ff | 0x4100800);
    local_814 = (unsigned char *)0x0;
    local_810 = (unsigned char *)0x0;
    local_80c = (unsigned char *)0x0;
    local_808 = (unsigned char *)0x0;
    local_804 = (unsigned char *)0x0;
    local_800 = (unsigned char *)0x0;
    local_820 = pTVar33;
    param_4 = (char *)TIntermediate__addConstantUnion
                                (*(unsigned char **)param_1,pcVar9,(unsigned char *)&local_820,
                                 *(uint *)pTVar56);
    param_3 = *(char **)(pTVar56 + -0x50);
    param_5 = *(char **)(pTVar56 + -0x2c);
    local_820 = pTVar33;
    pTVar33 = (unsigned char *)
              TIntermediate__addIndex(*(unsigned char **)param_1,0x2f,param_3,param_4,param_5);
    ppuVar35 = *(undefined ***)(pTVar7 + 4);
    puVar5 = ppuVar35[uVar57 * 2];
    pcVar40 = *(code **)(*(unsigned char **)pTVar33 + 0x34);
    local_878 = pTVar33;
  }
LAB_97baae6c:
  (*pcVar40)(pTVar33,puVar5,param_3,param_4,param_5,pTVar3,ppuVar35);
  pTVar3 = local_878;
  pTVar31 = local_7f0;
  pTVar32 = local_750[0];
  goto switchD_97ba39c8_caseD_0;
LAB_97ba5740:
  param_8 = *(uint *)(pTVar56 + 4);
  pTVar34 = *(unsigned char **)(param_8 + 4);
  pcVar62 = " no such field in structure";
LAB_97ba5784:
  local_64 = (unsigned char *)0xa7b8374c;
  pTVar34[*(uint *)(pTVar34 + -0xc)] = *DAT_a7b7ba88;
  param_4 = *(char **)(param_8 + 4);
  pcVar29 = *(char **)(pTVar56 + -0x2c);
LAB_97ba5548:
  param_5 = "";
  TParseContext__error((int)param_1,pcVar29,pcVar62,param_4,"",pTVar33,pTVar34,param_8);
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
    if (_yyout == (undefined *)0x0) {
      _yyout = PTR_DAT_a7b7c0bc + 0x58;
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
  _yy_n_chars = (unsigned char *)*(unsigned int *)(_yy_current_buffer + 0x10);
  _yy_c_buf_p = (undefined1 *)*(unsigned int *)(_yy_current_buffer + 8);
  _yytext = _yy_c_buf_p;
  _yyin = *(void **)_yy_current_buffer;
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

