#include "decls.h"

/* __ZN17TPPStreamCompilerD1Ev @ 0x97bc97dc (8 bytes) */
int __ZN17TPPStreamCompilerD1Ev(this)
  void *this;
{
  ((int (*)())__ZN17TPPStreamCompilerD4Ev)(this,2);
  return;
}

/* __ZN17TPPStreamCompilerD0Ev @ 0x97bc97e4 (8 bytes) */
int __ZN17TPPStreamCompilerD0Ev(this)
  void *this;
{
  ((int (*)())__ZN17TPPStreamCompilerD4Ev)(this,3);
  return;
}

/* __ZN17TPPStreamCompilerD4Ev @ 0x97bc97ec (536 bytes) */
int __ZN17TPPStreamCompilerD4Ev(this, param_2)
  void *this;
  uint param_2;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  char in_RESERVE;
  byte in_cr0;
  undefined1 auStack_30 [24];
  
  *(int *)this = DAT_a7b7bd98 + 8;
  ConstantAllocationList__clear((unsigned char *)((int)this + 0x44));
  while( true ) {
    iVar4 = size((unsigned char *)((int)this + 0x4c));
    if (iVar4 == 0) break;
    fetch((unsigned char *)((int)this + 0x4c));
  }
  while (iVar4 = ParseFunctionStack__empty((unsigned char *)((int)this + 0x58)), iVar4 == 0) {
    ParseFunctionStack__pop((unsigned char *)((int)this + 0x58));
  }
  pvVar5 = *(void **)((int)this + 0x6c);
  if (pvVar5 != (void *)0x0) {
    ((int (*)())__ZN13FunctionTableD1Ev)(pvVar5);
    __ZdlPv(pvVar5);
  }
  pvVar5 = *(void **)((int)this + 0x68);
  if (pvVar5 != (void *)0x0) {
    __ZN16ParseSymbolTableD1Ev(pvVar5);
    __ZdlPv(pvVar5);
  }
  if (*(int *)((int)this + 0x70) != 0) {
    _PPStreamFree(*(int *)((int)this + 0x70));
  }
  if (*(int *)((int)this + 0x78) != 0) {
    _free(*(int *)((int)this + 0x78));
  }
  if (*(int *)((int)this + 0x7c) != 0) {
    _free(*(int *)((int)this + 0x7c));
  }
  if (*(int *)((int)this + 0x80) != 0) {
    _free(*(int *)((int)this + 0x80));
  }
  if (*(int *)((int)this + 0x84) != 0) {
    _free(*(int *)((int)this + 0x84));
  }
  pvVar5 = *(void **)((int)this + 0x60);
  if (pvVar5 != (void *)0x0) {
    __ZN18TemporaryAllocatorD1Ev(pvVar5);
    __ZdlPv(pvVar5);
  }
  *(undefined4 *)PTR_temporaryAllocator_a7b7c0fc = 0;
  pvVar5 = *(void **)((int)this + 100);
  if (pvVar5 != (void *)0x0) {
    __ZN20AddressTempAllocatorD1Ev(pvVar5);
    __ZdlPv(pvVar5);
  }
  *(undefined4 *)PTR_addressTempAllocator_a7b7c0f8 = 0;
  if (*(int *)((int)this + 0x74) != 0) {
    _free(*(int *)((int)this + 0x74));
  }
  iVar4 = *(int *)((int)this + 0xb8);
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
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(iVar4 + -0xc),auStack_30);
  }
  iVar4 = *(int *)((int)this + 0xb0);
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
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(iVar4 + -0xc),auStack_30);
  }
  __ZN22ConstantAllocationListD1Ev((unsigned char *)((int)this + 0x44));
  *(undefined ***)this = &PTR___ZN9TCompilerD1Ev_a7b7d850;
  __ZN14TPoolAllocatorD1Ev((void *)((int)this + 0x10));
  *(undefined ***)this = &PTR___ZN13TShHandleBaseD1Ev_a7b7d898;
  if ((param_2 & 1) != 0) {
    __ZdlPv(this);
  }
  return;
}

/* TPPStreamCompiler__error @ 0x97bc9a04 (304 bytes) */
int TPPStreamCompiler__error(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  char *param_2;
  char *param_3;
  char *param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  char acStack_120 [264];
  
  iVar5 = 0;
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  _vsprintf(acStack_120,param_4,&STACKARG(0x28));
  if (param_3 != (char *)0x0) {
    iVar5 = _strlen(param_3);
  }
  iVar3 = _strlen(acStack_120);
  pcVar4 = (char *)_malloc(iVar3 + iVar5 + 0x28);
  pcVar1 = DAT_a7b7bd20;
  pcVar2 = DAT_a7b7bd24;
  if (param_2 != (char *)0x0) {
    pcVar1 = DAT_a7b7bd18;
    pcVar2 = DAT_a7b7bd1c;
  }
  if (param_3 == (char *)0x0) {
    _sprintf(pcVar4,pcVar2,*(undefined4 *)(param_1 + 0x90),acStack_120);
  }
  else {
    _sprintf(pcVar4,pcVar1,*(undefined4 *)(param_1 + 0x90),param_3,acStack_120);
  }
  __ZN13TInfoSinkBase6appendEPKc((void *)(param_1 + 0xb0),pcVar4);
  __ZN13TInfoSinkBase6appendEPKc((void *)(param_1 + 0xb0),"\n");
  _free(pcVar4);
  *(undefined4 *)(param_1 + 0xa0) = 1;
  return;
}

/* TPPStreamCompiler__warning @ 0x97bc9b34 (296 bytes) */
int TPPStreamCompiler__warning(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int param_1;
  char *param_2;
  char *param_3;
  char *param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  char acStack_120 [268];
  
  uStack00000028 = param_5;
  uStack0000002c = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  _vsprintf(acStack_120,param_4,&STACKARG(0x28));
  iVar5 = 0;
  if (param_3 != (char *)0x0) {
    iVar5 = _strlen(param_3);
  }
  iVar3 = _strlen(acStack_120);
  pcVar4 = (char *)_malloc(iVar3 + iVar5 + 0x28);
  pcVar1 = DAT_a7b7bd34;
  pcVar2 = DAT_a7b7bd38;
  if (param_2 != (char *)0x0) {
    pcVar1 = DAT_a7b7bd2c;
    pcVar2 = DAT_a7b7bd30;
  }
  if (param_3 == (char *)0x0) {
    _sprintf(pcVar4,pcVar2,*(undefined4 *)(param_1 + 0x90),acStack_120);
  }
  else {
    _sprintf(pcVar4,pcVar1,*(undefined4 *)(param_1 + 0x90),param_3,acStack_120);
  }
  __ZN13TInfoSinkBase6appendEPKc((void *)(param_1 + 0xb0),pcVar4);
  __ZN13TInfoSinkBase6appendEPKc((void *)(param_1 + 0xb0),"\n");
  _free(pcVar4);
  return;
}

/* TPPStreamCompiler__getSymbolTableString @ 0x97bc9c5c (196 bytes) */
int TPPStreamCompiler__getSymbolTableString(this, param_2)
  unsigned char * this;
  int param_2;
{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (*(unsigned char **)(this + 0x68) == (unsigned char *)0x0) {
    return (char *)0x0;
  }
  uVar1 = ParseSymbolTable__GetString(*(unsigned char **)(this + 0x68),param_2);
  iVar2 = _strlen(uVar1);
  pcVar3 = (char *)_malloc(iVar2 + 0x17);
  *pcVar3 = '\0';
  pcVar4 = DAT_a7b7bd64;
  if (param_2 != 1) {
    if (param_2 < 2) {
      pcVar4 = DAT_a7b7bd60;
      if (param_2 != 0) goto LAB_97bc9d00;
    }
    else {
      pcVar4 = DAT_a7b7bd68;
      if (param_2 != 2) goto LAB_97bc9d00;
    }
  }
  _sprintf(pcVar3,pcVar4,uVar1);
LAB_97bc9d00:
  _free(uVar1);
  return pcVar3;
}

/* TPPStreamCompiler__dumpSymbolTableInfo @ 0x97bc9d20 (220 bytes) */
int TPPStreamCompiler__dumpSymbolTableInfo(this, param_2)
  unsigned char * this;
  int param_2;
{
  char *pcVar1;
  
  pcVar1 = DAT_a7b7bd70;
  if (param_2 != 1) {
    if (param_2 < 2) {
      pcVar1 = DAT_a7b7bd6c;
      if (param_2 != 0) goto LAB_97bc9d98;
    }
    else {
      pcVar1 = DAT_a7b7bd74;
      if (param_2 != 2) goto LAB_97bc9d98;
    }
  }
  __ZN13TInfoSinkBase6appendEPKc(this + 0xb0,pcVar1);
LAB_97bc9d98:
  pcVar1 = (char *)ParseSymbolTable__GetString(*(unsigned char **)(this + 0x68),param_2);
  if (pcVar1 == (char *)0x0) {
    return;
  }
  __ZN13TInfoSinkBase6appendEPKc(this + 0xb0,pcVar1);
  __ZN13TInfoSinkBase6appendEPKc(this + 0xb0,DAT_a7b7bd78);
  _free(pcVar1);
  return;
}

/* TPPStreamCompiler__reportStats @ 0x97bc9dfc (4 bytes) */
int TPPStreamCompiler__reportStats()
{
  return;
}

/* TPPStreamCompiler__reset @ 0x97bc9e00 (324 bytes) */
int TPPStreamCompiler__reset(this)
  unsigned char * this;
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  
  *(undefined4 *)(this + 0xc) = 0;
  if (*(int *)(this + 0x78) != 0) {
    _free(*(int *)(this + 0x78));
  }
  *(undefined4 *)(this + 0x78) = 0;
  if (*(int *)(this + 0x7c) != 0) {
    _free(*(int *)(this + 0x7c));
  }
  *(undefined4 *)(this + 0x7c) = 0;
  if (*(int *)(this + 0x80) != 0) {
    _free(*(int *)(this + 0x80));
  }
  *(undefined4 *)(this + 0x80) = 0;
  if (*(int *)(this + 0x84) != 0) {
    _free(*(int *)(this + 0x84));
  }
  pvVar4 = *(void **)(this + 0x68);
  *(undefined4 *)(this + 0x84) = 0;
  if (pvVar4 != (void *)0x0) {
    __ZN16ParseSymbolTableD1Ev(pvVar4);
    __ZdlPv(pvVar4);
  }
  pvVar4 = operator_new(0x54);
  __ZN16ParseSymbolTableC1Ej(pvVar4,0x80);
  *(void **)(this + 0x68) = pvVar4;
  *(undefined4 *)((int)pvVar4 + 0x3c) = *(undefined4 *)(this + 8);
  pvVar4 = *(void **)(this + 0x6c);
  if (pvVar4 != (void *)0x0) {
    ((int (*)())__ZN13FunctionTableD1Ev)(pvVar4);
    __ZdlPv(pvVar4);
  }
  pvVar4 = operator_new(8);
  ((int (*)())__ZN13FunctionTableC1Ev)(pvVar4);
  *(void **)(this + 0x6c) = pvVar4;
  if (*(int *)(this + 0x70) != 0) {
    _PPStreamFree(*(int *)(this + 0x70));
  }
  uVar2 = _PPStreamCreate();
  *(undefined4 *)(this + 0x70) = uVar2;
  *(undefined4 *)(*(int *)(this + 0x68) + 0xc) = uVar2;
  iVar3 = *(int *)(this + 8);
  if (iVar3 == 0) {
    puVar1 = *(undefined4 **)(this + 0x70);
    uVar2 = 0x8b31;
  }
  else {
    if (iVar3 != 1) {
      return;
    }
    puVar1 = *(undefined4 **)(this + 0x70);
    uVar2 = 0x8b30;
  }
  *puVar1 = uVar2;
  *(int *)(this + 0xa4) = iVar3;
  return;
}

/* TPPStreamCompiler__compile @ 0x97bc9f44 (332 bytes) */
int TPPStreamCompiler__compile(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  uint uVar6;
  int local_20 [5];
  
  iVar2 = TPPStreamCompiler__parseIntermediateTree(this,param_2);
  *(int *)(this + 0xc) = iVar2;
  if (iVar2 != 0) {
    iVar3 = *(int *)(this + 0x70);
    uVar6 = 0;
    iVar2 = **(int **)(iVar3 + 0x20);
    if (iVar2 != 0) {
      do {
        uVar1 = *(uint *)(iVar2 + 0xc);
        *(uint *)(iVar2 + 0xc) = uVar6 << 0x1a | uVar1 & 0xe3ffffff;
        uVar6 = uVar1 >> 0x1d;
        iVar2 = *(int *)(iVar2 + 8);
      } while (iVar2 != 0);
      iVar3 = *(int *)(this + 0x70);
    }
    _PPStreamResolveBranches(iVar3);
    if (*(int *)(this + 0x74) != 0) {
      _free(*(int *)(this + 0x74));
    }
    *(undefined4 *)(this + 0x74) = 0;
    _PPStreamGetStream(*(undefined4 *)(this + 0x70),0,local_20);
    if (local_20[0] != 0) {
      uVar4 = _malloc(local_20[0] * 8 + 0xfU & 0xfffffff0);
      *(undefined4 *)(this + 0x74) = uVar4;
      _PPStreamGetStream(*(undefined4 *)(this + 0x70),uVar4,local_20);
    }
  }
  iVar2 = *(int *)(this + 0xc);
  if ((iVar2 != 0) && ((*(uint *)(this + 0xc0) & 0x10) != 0)) {
    ((int (*)())TPPStreamCompiler__dumpSymbolTableInfo)(this,2);
    iVar2 = *(int *)(this + 0xc);
  }
  if ((iVar2 != 0) && ((*(uint *)(this + 0xc0) & 2) != 0)) {
    __ZN13TInfoSinkBase6appendEPKc(this + 0xb0,DAT_a7b7bd80);
    pcVar5 = (char *)(**(code **)(*(int *)this + 0x28))(this);
    __ZN13TInfoSinkBase6appendEPKc(this + 0xb0,pcVar5);
    iVar2 = *(int *)(this + 0xc);
  }
  return iVar2;
}

/* TPPStreamCompiler__getStatsString @ 0x97bca090 (108 bytes) */
int TPPStreamCompiler__getStatsString(this)
  unsigned char * this;
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = DAT_a7b7bd84;
  iVar2 = *(int *)(this + 0x78);
  if (iVar2 == 0) {
    iVar2 = _strlen(DAT_a7b7bd84);
    uVar3 = _malloc(iVar2 * 4 + 4);
    *(undefined4 *)(this + 0x78) = uVar3;
    _strcpy(uVar3,uVar1);
    iVar2 = *(int *)(this + 0x78);
  }
  return iVar2;
}

/* TPPStreamCompiler__getPPStreamString @ 0x97bca0fc (144 bytes) */
int TPPStreamCompiler__getPPStreamString(this)
  unsigned char * this;
{
  undefined4 uVar1;
  undefined4 extraout_r3;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = DAT_a7b7bd88;
  if (*(int *)(this + 0x7c) == 0) {
    if ((*(int *)(this + 0xc) == 0) || (*(int *)(this + 0x74) == 0)) {
      iVar2 = _strlen(DAT_a7b7bd88);
      uVar3 = _malloc(iVar2 * 4 + 4);
      *(undefined4 *)(this + 0x7c) = uVar3;
      _strcpy(uVar3,uVar1);
    }
    else {
      ((double (*)())_glpPPDisassemble)(*(int *)(this + 0x74));
      *(undefined4 *)(this + 0x7c) = extraout_r3;
    }
  }
  return;
}

/* TPPStreamCompiler__getShaderToProgramString @ 0x97bca18c (148 bytes) */
int TPPStreamCompiler__getShaderToProgramString(this)
  unsigned char * this;
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(this + 0x80);
  if (iVar1 == 0) {
    if ((*(int *)(this + 0xc) == 0) || (*(int *)(this + 0x74) == 0)) {
      iVar1 = _strlen("No Shader Program generated.");
      uVar2 = _malloc(iVar1 * 4 + 4);
      *(undefined4 *)(this + 0x80) = uVar2;
      _strcpy(uVar2,"No Shader Program generated.");
      iVar1 = *(int *)(this + 0x80);
    }
    else {
      iVar1 = _glpPPShaderToProgramString(*(int *)(this + 0x74),0,0);
      *(int *)(this + 0x80) = iVar1;
    }
  }
  return iVar1;
}

/* TPPStreamCompiler__getTableString @ 0x97bca220 (72 bytes) */
int TPPStreamCompiler__getTableString(this)
  unsigned char * this;
{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x84);
  if (iVar1 == 0) {
    iVar1 = ((int (*)())TPPStreamCompiler__getSymbolTableString)(this,2);
    *(int *)(this + 0x84) = iVar1;
  }
  return iVar1;
}

/* ConstructCompiler @ 0x97bca268 (72 bytes) */
int ConstructCompiler(param_1, param_2)
  undefined4 param_1;
  undefined4 param_2;
{
  void *this;
  
  this = operator_new(200);
  __ZN17TPPStreamCompilerC1E11EShLanguagei(this,param_1,param_2);
  return this;
}

/* DeleteCompiler @ 0x97bca2b0 (24 bytes) */
int DeleteCompiler(param_1)
  unsigned char * param_1;
{
  if (param_1 == (unsigned char *)0x0) {
    return;
  }
                    
                    
  (**(code **)(*(int *)param_1 + 4))(param_1);
  return;
}

/* GetBuiltInInitialSwizzle @ 0x97bca2c8 (748 bytes) */
int GetBuiltInInitialSwizzle(param_1)
  unsigned char * param_1;
{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar3 = *(int *)(param_1 + 0x20);
  iVar7 = 0;
  iVar6 = 0;
  if (0 < iVar3) {
    iVar5 = 3;
    do {
      pcVar2 = (char *)(*(int *)(param_1 + 0x14) + iVar6);
      iVar6 = iVar6 + 1;
      iVar4 = *pcVar2 * iVar5;
      iVar5 = iVar5 + 2;
      iVar7 = iVar7 + iVar4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if (iVar7 == 0x18ec7) {
    return 3;
  }
  if (iVar7 < 0x18ec8) {
    if (iVar7 == 0x17e27) {
      return 3;
    }
    if (0x17e27 < iVar7) {
      if (iVar7 == 0x17ecc) {
        return 3;
      }
      if (iVar7 < 0x17ecd) {
        if (iVar7 == 0x17e69) {
          return 3;
        }
        if (iVar7 < 0x17e6a) {
          iVar3 = 0x17e48;
        }
        else {
          if (iVar7 == 0x17e8a) {
            return 3;
          }
          iVar3 = 0x17eab;
        }
      }
      else {
        if (iVar7 == 0x18e64) {
          return 3;
        }
        if (iVar7 < 0x18e65) {
          if (iVar7 == 0x17eed) {
            return 3;
          }
          iVar3 = 0x18e43;
        }
        else {
          if (iVar7 == 0x18e85) {
            return 3;
          }
          iVar3 = 0x18ea6;
        }
      }
LAB_97bca478:
      if (iVar7 == iVar3) {
        return 3;
      }
      return 0;
    }
    if (iVar7 == 0x71c3) {
      return 2;
    }
    if (iVar7 < 0x71c4) {
      if (iVar7 == 0x3f94) {
        return 3;
      }
      if (0x3f94 < iVar7) {
        if (iVar7 == 0x42d8) {
          return 1;
        }
        bVar1 = iVar7 == 0x7171;
        goto LAB_97bca520;
      }
      bVar1 = iVar7 == 0x2c25;
      goto LAB_97bca590;
    }
    if (iVar7 == 0x8837) {
      return 2;
    }
    if (0x8837 < iVar7) {
      if (iVar7 == 0x12304) {
        return 3;
      }
      iVar3 = 0x17e06;
      goto LAB_97bca478;
    }
    bVar1 = iVar7 == 0x7a53;
    goto LAB_97bca520;
  }
  if (iVar7 == 0x2043a) {
    return 1;
  }
  if (iVar7 < 0x2043b) {
    if (iVar7 == 0x20374) {
      return 1;
    }
    if (iVar7 < 0x20375) {
      if (iVar7 == 0x18f09) {
        return 3;
      }
      if (iVar7 < 0x18f0a) {
        iVar3 = 0x18ee8;
        goto LAB_97bca478;
      }
      if (iVar7 == 0x18f2a) {
        return 3;
      }
      iVar3 = 0x1f1a8;
    }
    else {
      if (iVar7 == 0x203d7) {
        return 1;
      }
      if (iVar7 < 0x203d8) {
        if (iVar7 == 0x20395) {
          return 1;
        }
        iVar3 = 0x203b6;
      }
      else {
        if (iVar7 == 0x203f8) {
          return 1;
        }
        iVar3 = 0x20419;
      }
    }
LAB_97bca51c:
    bVar1 = iVar7 == iVar3;
LAB_97bca520:
    if (bVar1) {
      return 1;
    }
    return 0;
  }
  if (iVar7 == 0x2614d) {
    return 2;
  }
  if (iVar7 < 0x2614e) {
    if (iVar7 == 0x24cb9) {
      return 2;
    }
    if (iVar7 < 0x24cba) {
      iVar3 = 0x2045b;
      goto LAB_97bca51c;
    }
    if (iVar7 == 0x2610b) {
      return 2;
    }
    iVar3 = 0x2612c;
  }
  else {
    if (iVar7 == 0x261b0) {
      return 2;
    }
    if (iVar7 < 0x261b1) {
      if (iVar7 == 0x2616e) {
        return 2;
      }
      iVar3 = 0x2618f;
    }
    else {
      if (iVar7 == 0x261d1) {
        return 2;
      }
      iVar3 = 0x261f2;
    }
  }
  bVar1 = iVar7 == iVar3;
LAB_97bca590:
  if (bVar1) {
    return 2;
  }
  return 0;
}

/* GetBuiltInChunkForSymbol @ 0x97bca5b4 (8452 bytes) */
int GetBuiltInChunkForSymbol(param_1, param_2)
  unsigned char * param_1;
  int param_2;
{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined1 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar12 = 0;
  iVar3 = *(int *)(param_1 + 0x20);
  iVar11 = 0;
  iVar10 = 0;
  if (0 < iVar3) {
    iVar7 = 3;
    do {
      pcVar2 = (char *)(*(int *)(param_1 + 0x14) + iVar10);
      iVar10 = iVar10 + 1;
      iVar4 = *pcVar2 * iVar7;
      iVar7 = iVar7 + 2;
      iVar11 = iVar11 + iVar4;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if (iVar11 == 0x10f9c) {
    iVar12 = _PPStreamChunkCreateWithType(3,0);
    uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fff9 | 0x50009;
    goto LAB_97bcc694;
  }
  if (iVar11 < 0x10f9d) {
    if (iVar11 == 0x81d5) goto LAB_97bcc54c;
    if (iVar11 < 0x81d6) {
      if (iVar11 == 0x5a70) {
LAB_97bcc4ac:
        iVar12 = _PPStreamChunkCreateWithType(3,0);
        iVar3 = 7;
        uVar6 = *(uint *)(iVar12 + 0xc);
LAB_97bcc53c:
        uVar6 = iVar3 << 0x10 | uVar6 & 0xffe0ff3f | 0x20;
LAB_97bcbb78:
        *(uint *)(iVar12 + 0xc) = uVar6;
        uVar6 = ParseSymbol__GetDirectIndex(param_1,0);
        uVar6 = uVar6 & 0x1f | *(uint *)(iVar12 + 0xc) & 0xffffffe0;
      }
      else if (iVar11 < 0x5a71) {
        if (iVar11 == 0x504e) {
          iVar12 = _PPStreamChunkCreateWithType(4,0);
          iVar3 = 9;
          uVar6 = *(uint *)(iVar12 + 0xc);
        }
        else {
          if (iVar11 < 0x504f) {
            if (iVar11 == 0x4209) {
LAB_97bcc5e0:
              uVar8 = 2;
LAB_97bcc64c:
              iVar12 = _PPStreamChunkCreateWithType(uVar8,0);
              iVar3 = 1;
            }
            else if (iVar11 < 0x420a) {
              if (iVar11 != 0x383f) {
                if (iVar11 < 0x3840) {
                  if (iVar11 == 0x280f) {
                    uVar8 = 2;
LAB_97bcc5ec:
                    iVar12 = _PPStreamChunkCreateWithType(uVar8,0);
                    iVar3 = 4;
                    goto LAB_97bcc658;
                  }
                  if (iVar11 < 0x2810) {
                    if (iVar11 != 0x2099) goto LAB_97bcc698;
                    uVar8 = 2;
                    goto LAB_97bcbba8;
                  }
                  if (iVar11 == 0x297a) goto LAB_97bcc5e0;
                  if (iVar11 != 0x2c25) goto LAB_97bcc698;
                }
                else if (iVar11 != 0x3f94) {
                  if (iVar11 < 0x3f95) {
                    if (iVar11 != 0x3bf9) goto LAB_97bcc698;
                    uVar8 = 4;
                    goto LAB_97bcc64c;
                  }
                  if (iVar11 == 0x41d9) {
                    iVar12 = _PPStreamChunkCreateWithType(3,0);
                    iVar3 = 0xb;
                    goto LAB_97bcc5c0;
                  }
                  if (iVar11 != 0x4203) goto LAB_97bcc698;
                  iVar12 = _PPStreamChunkCreateWithType(4,0);
                  iVar3 = 7;
                  goto LAB_97bcc658;
                }
LAB_97bcc5b0:
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                iVar3 = 0xc;
                goto LAB_97bcc5c0;
              }
LAB_97bcbce8:
              iVar12 = _PPStreamChunkCreateWithType(2,0);
              iVar3 = 5;
            }
            else {
              if (iVar11 == 0x4dd3) goto LAB_97bcc034;
              if (0x4dd3 < iVar11) {
                if (iVar11 != 0x4ee0) {
                  if (iVar11 < 0x4ee1) {
                    if ((iVar11 != 0x4eaa) && (iVar11 != 0x4ec5)) goto LAB_97bcc698;
                  }
                  else if (iVar11 != 0x4efb) {
                    if (iVar11 != 0x4fb4) goto LAB_97bcc698;
                    iVar12 = _PPStreamChunkCreateWithType(4,0);
                    iVar3 = 4;
                    uVar6 = *(uint *)(iVar12 + 0xc);
LAB_97bcbb08:
                    uVar6 = iVar3 << 0x10 | uVar6 & 0xfff0fffe;
                    goto LAB_97bcc694;
                  }
                }
                iVar12 = _PPStreamChunkCreateWithType(4,0);
                *(uint *)(iVar12 + 0xc) = *(uint *)(iVar12 + 0xc) & 0xfff0ffff | 0x40000;
                uVar6 = ParseSymbol__GetDirectIndex(param_1,0);
                uVar6 = (uVar6 & 7) << 1 | *(uint *)(iVar12 + 0xc) & 0xfffffff1;
                goto LAB_97bcc694;
              }
              if (iVar11 == 0x42d8) goto LAB_97bcc5b0;
              if (iVar11 < 0x42d9) {
                if (iVar11 != 0x425a) goto LAB_97bcc698;
                iVar12 = _PPStreamChunkCreateWithType(4,0);
                iVar3 = 4;
                uVar6 = *(uint *)(iVar12 + 0xc);
                goto LAB_97bcbb2c;
              }
              if (iVar11 == 0x42e3) {
                uVar8 = 4;
                goto LAB_97bcc5ec;
              }
              if (iVar11 != 0x4493) goto LAB_97bcc698;
              uVar8 = 4;
LAB_97bcc668:
              iVar12 = _PPStreamChunkCreateWithType(uVar8,0);
              iVar3 = 3;
            }
          }
          else {
            if (iVar11 != 0x58a1) {
              if (0x58a1 < iVar11) {
                if (iVar11 != 0x5a3e) {
                  if (iVar11 < 0x5a3f) {
                    if (iVar11 != 0x5a21) {
                      if (iVar11 < 0x5a22) {
                        bVar1 = iVar11 == 0x5a08;
LAB_97bca874:
                        if (!bVar1) goto LAB_97bcc698;
                      }
                      else if (iVar11 != 0x5a25) {
                        bVar1 = iVar11 == 0x5a3a;
                        goto LAB_97bca888;
                      }
                      goto LAB_97bcc4e4;
                    }
                  }
                  else {
                    if (iVar11 == 0x5a57) goto LAB_97bcc490;
                    if (iVar11 < 0x5a58) {
                      if (iVar11 != 0x5a42) {
                        bVar1 = iVar11 == 0x5a53;
                        goto LAB_97bca8e4;
                      }
                      goto LAB_97bcc4e4;
                    }
                    if (iVar11 != 0x5a5b) {
                      bVar1 = iVar11 == 0x5a5f;
                      goto LAB_97bca874;
                    }
                  }
                }
                goto LAB_97bcc4c8;
              }
              if (iVar11 != 0x5214) {
                if (iVar11 < 0x5215) {
                  if (iVar11 != 0x51c3) {
                    if (iVar11 < 0x51c4) {
                      bVar1 = iVar11 == 0x51a8;
                    }
                    else {
                      if (iVar11 == 0x51de) goto LAB_97bcbb38;
                      bVar1 = iVar11 == 0x51f9;
                    }
LAB_97bca770:
                    if (!bVar1) goto LAB_97bcc698;
                  }
                }
                else if (iVar11 != 0x524a) {
                  if (iVar11 < 0x524b) {
                    bVar1 = iVar11 == 0x522f;
                    goto LAB_97bca770;
                  }
                  if (iVar11 != 0x5265) {
                    if (iVar11 != 0x5811) goto LAB_97bcc698;
                    iVar12 = _PPStreamChunkCreateWithType(3,0);
                    iVar3 = 0x12;
                    goto LAB_97bcc5c0;
                  }
                }
              }
LAB_97bcbb38:
              if (param_2 == 0) {
                iVar12 = _PPStreamChunkCreateWithType(4,0);
                iVar3 = 6;
                uVar6 = *(uint *)(iVar12 + 0xc);
              }
              else {
                iVar12 = _PPStreamChunkCreateWithType(2,0);
                iVar3 = 7;
                uVar6 = *(uint *)(iVar12 + 0xc);
              }
              uVar6 = iVar3 << 0x10 | uVar6 & 0xfff0ffff;
              goto LAB_97bcbb78;
            }
            iVar12 = _PPStreamChunkCreateWithType(2,0);
            iVar3 = 0xb;
          }
LAB_97bcc658:
          uVar6 = *(uint *)(iVar12 + 0xc);
        }
        uVar6 = iVar3 << 0x10 | uVar6 & 0xfff0ffff;
      }
      else {
        if (iVar11 == 0x5b05) goto LAB_97bcc490;
        if (iVar11 < 0x5b06) {
          if (iVar11 != 0x5ab2) {
            if (iVar11 < 0x5ab3) {
              if (iVar11 == 0x5a91) {
LAB_97bcc490:
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                iVar3 = 7;
                uVar6 = *(uint *)(iVar12 + 0xc);
LAB_97bcc518:
                uVar6 = iVar3 << 0x10 | uVar6 & 0xffe0ff1f;
                goto LAB_97bcbb78;
              }
              if (iVar11 < 0x5a92) {
                if (iVar11 != 0x5a78) {
                  if (0x5a78 < iVar11) {
                    if (iVar11 != 0x5a7c) {
                      bVar1 = iVar11 == 0x5a8d;
                      goto LAB_97bca8e4;
                    }
                    goto LAB_97bcc4e4;
                  }
                  bVar1 = iVar11 == 0x5a74;
LAB_97bca888:
                  if (!bVar1) goto LAB_97bcc698;
                  goto LAB_97bcc490;
                }
              }
              else {
                if (iVar11 == 0x5a99) {
LAB_97bcc4e4:
                  iVar12 = _PPStreamChunkCreateWithType(3,0);
                  iVar3 = 7;
                  uVar6 = *(uint *)(iVar12 + 0xc);
                  goto LAB_97bcc58c;
                }
                if (0x5a99 < iVar11) {
                  if (iVar11 == 0x5aaa) goto LAB_97bcc4ac;
                  bVar1 = iVar11 == 0x5aae;
                  goto LAB_97bca888;
                }
                if (iVar11 != 0x5a95) goto LAB_97bcc698;
              }
            }
            else if (iVar11 != 0x5acf) {
              if (iVar11 < 0x5ad0) {
                if (iVar11 == 0x5ac2) goto LAB_97bcc5b0;
                if (iVar11 < 0x5ac3) {
                  bVar1 = iVar11 == 0x5ab6;
                  goto LAB_97bca874;
                }
                if (iVar11 == 0x5ac7) goto LAB_97bcc4ac;
                bVar1 = iVar11 == 0x5acb;
                goto LAB_97bca888;
              }
              if (iVar11 != 0x5ae8) {
                if (iVar11 < 0x5ae9) {
                  if (iVar11 == 0x5ad3) goto LAB_97bcc4e4;
                  bVar1 = iVar11 == 0x5ae4;
                }
                else {
                  if (iVar11 == 0x5aec) goto LAB_97bcc4c8;
                  bVar1 = iVar11 == 0x5b01;
                }
LAB_97bca8e4:
                if (!bVar1) goto LAB_97bcc698;
                goto LAB_97bcc4ac;
              }
              goto LAB_97bcc490;
            }
          }
LAB_97bcc4c8:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          iVar3 = 7;
          uVar6 = *(uint *)(iVar12 + 0xc);
          goto LAB_97bcc564;
        }
        if (iVar11 != 0x71c3) {
          if (0x71c3 < iVar11) {
            if (iVar11 == 0x7ab2) {
              iVar12 = _PPStreamChunkCreateWithType(2,0);
              uVar6 = *(uint *)(iVar12 + 0xc) & 0xfff0ffe3 | 0x70000;
              goto LAB_97bcc190;
            }
            if (iVar11 < 0x7ab3) {
              if (iVar11 == 0x7a53) goto LAB_97bcbff4;
              if (iVar11 < 0x7a54) {
                if (iVar11 != 0x7a49) goto LAB_97bcc698;
                iVar12 = _PPStreamChunkCreateWithType(2,0);
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xfff0ffe0 | 0x70000;
                goto LAB_97bcc694;
              }
              if (iVar11 == 0x7a6c) {
                iVar12 = _PPStreamChunkCreateWithType(2,0);
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xfff0ffe1 | 0x70000;
                goto LAB_97bcbb30;
              }
              if (iVar11 != 0x7a8f) goto LAB_97bcc698;
              iVar12 = _PPStreamChunkCreateWithType(2,0);
              uVar5 = *(uint *)(iVar12 + 0xc) & 0xfff0ffff | 0x70000;
              uVar6 = 2;
            }
            else if (iVar11 == 0x7b1b) {
              iVar12 = _PPStreamChunkCreateWithType(2,0);
              uVar5 = *(uint *)(iVar12 + 0xc) & 0xfff0ffff | 0x70000;
              uVar6 = 6;
            }
            else if (iVar11 < 0x7b1c) {
              if (iVar11 == 0x7ad5) {
                iVar12 = _PPStreamChunkCreateWithType(2,0);
                uVar5 = *(uint *)(iVar12 + 0xc) & 0xfff0ffff | 0x70000;
                uVar6 = 4;
              }
              else {
                if (iVar11 != 0x7af8) goto LAB_97bcc698;
                iVar12 = _PPStreamChunkCreateWithType(2,0);
                uVar5 = *(uint *)(iVar12 + 0xc) & 0xfff0ffff | 0x70000;
                uVar6 = 5;
              }
            }
            else {
              if (iVar11 != 0x7b3e) {
                iVar3 = 0x81b6;
                goto LAB_97bcab00;
              }
              iVar12 = _PPStreamChunkCreateWithType(2,0);
              uVar6 = 7;
              uVar5 = *(uint *)(iVar12 + 0xc) & 0xfff0ffff | 0x70000;
            }
            uVar6 = uVar6 | uVar5 & 0xffffffe0;
            goto LAB_97bcc694;
          }
          if (iVar11 != 0x5c79) {
            if (iVar11 < 0x5c7a) {
              if (iVar11 != 0x5c22) {
                if (iVar11 < 0x5c23) {
                  bVar1 = iVar11 == 0x5b1e;
                  goto LAB_97bca8e4;
                }
                if (iVar11 != 0x5c3f) {
                  bVar1 = iVar11 == 0x5c5c;
LAB_97bca914:
                  if (!bVar1) goto LAB_97bcc698;
                }
              }
            }
            else {
              if (iVar11 == 0x6349) {
                uVar8 = 4;
                if (param_2 != 0) goto LAB_97bcbce8;
LAB_97bcbba8:
                iVar12 = _PPStreamChunkCreateWithType(uVar8,0);
                iVar3 = 2;
                goto LAB_97bcc658;
              }
              if (0x6349 < iVar11) {
                if (iVar11 != 0x68de) {
                  bVar1 = iVar11 == 0x7171;
                  goto LAB_97bcb178;
                }
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe08fff | 0x108000;
                iVar3 = 3;
                goto LAB_97bcbe2c;
              }
              if (iVar11 != 0x5c96) {
                bVar1 = iVar11 == 0x5cb3;
                goto LAB_97bca914;
              }
            }
          }
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0xa0000;
          goto LAB_97bcc458;
        }
LAB_97bcc034:
        iVar12 = _PPStreamChunkCreateWithType(3,0);
        iVar3 = 0xd;
LAB_97bcc5c0:
        uVar6 = *(uint *)(iVar12 + 0xc);
LAB_97bcc00c:
        uVar6 = iVar3 << 0x10 | uVar6 & 0xffe0ffff;
      }
    }
    else if (iVar11 == 0xa562) {
      iVar12 = _PPStreamChunkCreateWithType(3,0);
      uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe008ff | 0x104100;
    }
    else {
      if (iVar11 < 0xa563) {
        if (iVar11 == 0x829f) {
LAB_97bcc524:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          iVar3 = 8;
          uVar6 = *(uint *)(iVar12 + 0xc);
          goto LAB_97bcc53c;
        }
        if (iVar11 < 0x82a0) {
          if (iVar11 != 0x823a) {
            if (0x823a < iVar11) {
              if (iVar11 != 0x8261) {
                if (iVar11 < 0x8262) {
                  if (iVar11 != 0x8242) {
                    if (0x8242 < iVar11) {
                      if (iVar11 != 0x8259) {
                        iVar3 = 0x825d;
                        goto LAB_97bcab50;
                      }
                      goto LAB_97bcc524;
                    }
                    if (iVar11 != 0x823e) goto LAB_97bcc698;
                    goto LAB_97bcc54c;
                  }
                }
                else {
                  if (iVar11 == 0x8280) goto LAB_97bcc500;
                  if (0x8280 < iVar11) {
                    if (iVar11 != 0x8284) {
                      iVar3 = 0x8288;
                      goto LAB_97bcab00;
                    }
                    goto LAB_97bcc54c;
                  }
                  if (iVar11 != 0x8265) {
                    iVar3 = 0x827c;
                    goto LAB_97bcaba4;
                  }
                }
LAB_97bcc574:
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                iVar3 = 8;
                uVar6 = *(uint *)(iVar12 + 0xc);
LAB_97bcc58c:
                uVar6 = iVar3 << 0x10 | uVar6 & 0xffe0ff7f | 0x60;
                goto LAB_97bcbb78;
              }
              goto LAB_97bcc54c;
            }
            if (iVar11 == 0x8213) goto LAB_97bcc524;
            if (iVar11 < 0x8214) {
              if (iVar11 != 0x81f4) {
                if (iVar11 < 0x81f5) {
                  iVar3 = 0x81d9;
                }
                else {
                  if (iVar11 == 0x81f8) goto LAB_97bcc54c;
                  iVar3 = 0x81fc;
                }
LAB_97bcab00:
                if (iVar11 != iVar3) goto LAB_97bcc698;
                goto LAB_97bcc574;
              }
            }
            else {
              if (iVar11 == 0x821b) goto LAB_97bcc54c;
              if (0x821b < iVar11) {
                if (iVar11 != 0x821f) {
                  iVar3 = 0x8236;
                  goto LAB_97bcaba4;
                }
                goto LAB_97bcc574;
              }
              iVar3 = 0x8217;
LAB_97bcab50:
              if (iVar11 != iVar3) goto LAB_97bcc698;
            }
          }
          goto LAB_97bcc500;
        }
        if (iVar11 == 0x8837) {
LAB_97bcbff4:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          iVar3 = 0xf;
          uVar6 = *(uint *)(iVar12 + 0xc);
          goto LAB_97bcc00c;
        }
        if (0x8837 < iVar11) {
          if (iVar11 != 0x9a2c) {
            if (iVar11 < 0x9a2d) {
              if (iVar11 == 0x92cd) {
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe07fff | 0x104000;
LAB_97bcbdf0:
                uVar6 = uVar6 & 0xffffcfff;
                goto LAB_97bcbdf4;
              }
              if (iVar11 < 0x92ce) {
                if (iVar11 != 0x89f6) goto LAB_97bcc698;
                goto LAB_97bcbff4;
              }
              if (iVar11 != 0x99e2) {
                iVar3 = 0x9a07;
                goto LAB_97bcac74;
              }
            }
            else if (iVar11 != 0x9a9b) {
              if (iVar11 < 0x9a9c) {
                if (iVar11 != 0x9a51) {
                  iVar3 = 0x9a76;
LAB_97bcac74:
                  if (iVar11 != iVar3) goto LAB_97bcc698;
                }
              }
              else if (iVar11 != 0x9ac0) {
                iVar3 = 0x9ae5;
                goto LAB_97bcac74;
              }
            }
          }
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe07fff | 0x104000;
LAB_97bcbe80:
          uVar6 = uVar6 & 0xffffcfff;
          goto LAB_97bcbe84;
        }
        if (iVar11 == 0x82c6) {
LAB_97bcc500:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          iVar3 = 8;
          uVar6 = *(uint *)(iVar12 + 0xc);
          goto LAB_97bcc518;
        }
        if (iVar11 < 0x82c7) {
          if (iVar11 != 0x82a7) {
            if (iVar11 < 0x82a8) {
              iVar3 = 0x82a3;
              goto LAB_97bcab50;
            }
            if (iVar11 == 0x82ab) goto LAB_97bcc574;
            iVar3 = 0x82c2;
LAB_97bcaba4:
            if (iVar11 != iVar3) goto LAB_97bcc698;
            goto LAB_97bcc524;
          }
        }
        else {
          if (iVar11 == 0x82e9) goto LAB_97bcc500;
          if (0x82e9 < iVar11) {
            if (iVar11 != 0x8308) {
              if (iVar11 != 0x840f) goto LAB_97bcc698;
              uVar8 = 2;
              goto LAB_97bcc668;
            }
            goto LAB_97bcc524;
          }
          if (iVar11 != 0x82ca) {
            iVar3 = 0x82e5;
            goto LAB_97bcaba4;
          }
        }
LAB_97bcc54c:
        iVar12 = _PPStreamChunkCreateWithType(3,0);
        iVar3 = 8;
        uVar6 = *(uint *)(iVar12 + 0xc);
LAB_97bcc564:
        uVar6 = iVar3 << 0x10 | uVar6 & 0xffe0ff1f | 0x40;
        goto LAB_97bcbb78;
      }
      if (iVar11 != 0xe1f0) {
        if (0xe1f0 < iVar11) {
          if (iVar11 != 0x1021f) {
            if (0x1021f < iVar11) {
              if (iVar11 != 0x1029a) {
                if (iVar11 < 0x1029b) {
                  if (iVar11 == 0x10240) goto LAB_97bcc1e8;
                  if (iVar11 < 0x10241) {
                    iVar3 = 0x10237;
                  }
                  else {
                    if (iVar11 == 0x10258) goto LAB_97bcc20c;
                    iVar3 = 0x10279;
                  }
LAB_97bcaf2c:
                  if (iVar11 != iVar3) goto LAB_97bcc698;
                }
                else if (iVar11 != 0x102fd) {
                  if (iVar11 < 0x102fe) {
                    if (iVar11 != 0x102bb) {
                      iVar3 = 0x102dc;
                      goto LAB_97bcaf2c;
                    }
                  }
                  else if (iVar11 != 0x1031e) {
                    if (iVar11 != 0x10f0d) goto LAB_97bcc698;
                    iVar12 = _PPStreamChunkCreateWithType(3,0);
                    uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fffe | 0x50000;
                    goto LAB_97bcc1b8;
                  }
                }
              }
LAB_97bcc20c:
              iVar12 = _PPStreamChunkCreateWithType(3,0);
              uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0f1ff | 0x30100;
              goto LAB_97bcc458;
            }
            if (iVar11 != 0x10159) {
              if (iVar11 < 0x1015a) {
                if (iVar11 == 0xf7d2) {
                  iVar12 = _PPStreamChunkCreateWithType(3,0);
                  uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fffe | 0x50000;
                  iVar3 = 1;
                  goto LAB_97bcc0cc;
                }
                if (iVar11 < 0xf7d3) {
                  if (iVar11 != 0xf700) goto LAB_97bcc698;
                  iVar12 = _PPStreamChunkCreateWithType(3,0);
                  uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fff0 | 0x50000;
                }
                else {
                  if (iVar11 == 0xf839) {
                    iVar12 = _PPStreamChunkCreateWithType(3,0);
                    uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x50001;
LAB_97bcc1b8:
                    iVar3 = 2;
                    goto LAB_97bcc0cc;
                  }
                  if (iVar11 != 0xf9fd) goto LAB_97bcc698;
                  iVar12 = _PPStreamChunkCreateWithType(3,0);
                  uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fff7 | 0x50007;
                }
                goto LAB_97bcc694;
              }
              if (iVar11 != 0x101bc) {
                if (iVar11 < 0x101bd) {
                  if (iVar11 != 0x1017a) {
                    iVar3 = 0x1019b;
LAB_97bcaea4:
                    if (iVar11 != iVar3) goto LAB_97bcc698;
                  }
                }
                else if (iVar11 != 0x101dd) {
                  iVar3 = 0x101fe;
                  goto LAB_97bcaea4;
                }
              }
            }
          }
LAB_97bcc1e8:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0f0ff | 0x30000;
          goto LAB_97bcc458;
        }
        if (iVar11 != 0xb938) {
          if (iVar11 < 0xb939) {
            if (iVar11 != 0xb86b) {
              if (iVar11 < 0xb86c) {
                if (iVar11 != 0xb7f0) {
                  if (iVar11 < 0xb7f1) {
                    iVar3 = 0xb7c7;
                  }
                  else {
                    if (iVar11 == 0xb819) goto LAB_97bcc470;
                    iVar3 = 0xb842;
                  }
LAB_97bcadb8:
                  if (iVar11 != iVar3) goto LAB_97bcc698;
                }
              }
              else if (iVar11 != 0xb8bd) {
                if (iVar11 < 0xb8be) {
                  iVar3 = 0xb894;
                }
                else {
                  if (iVar11 == 0xb8e6) goto LAB_97bcc470;
                  iVar3 = 0xb90f;
                }
                goto LAB_97bcadb8;
              }
            }
          }
          else if (iVar11 != 0xc13b) {
            if (0xc13b < iVar11) {
              if (iVar11 == 0xc310) {
                iVar12 = _PPStreamChunkCreateWithType(4,0);
                iVar3 = 5;
                uVar6 = *(uint *)(iVar12 + 0xc);
LAB_97bcbb2c:
                uVar6 = iVar3 << 0x10 | uVar6 & 0xfff0ffff;
LAB_97bcbb30:
                uVar6 = uVar6 | 1;
              }
              else {
                if (iVar11 < 0xc311) {
                  if (iVar11 != 0xc166) {
                    iVar3 = 0xc191;
                    goto LAB_97bcadb8;
                  }
                  goto LAB_97bcc470;
                }
                if (iVar11 == 0xd7ba) {
                  iVar12 = _PPStreamChunkCreateWithType(4,0);
                  iVar3 = 5;
                  uVar6 = *(uint *)(iVar12 + 0xc);
                  goto LAB_97bcbb08;
                }
                if (iVar11 != 0xe12a) goto LAB_97bcc698;
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fff1 | 0x50001;
              }
              goto LAB_97bcc694;
            }
            if (iVar11 != 0xc0ba) {
              if (iVar11 < 0xc0bb) {
                if (iVar11 != 0xbd41) goto LAB_97bcc698;
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                iVar3 = 6;
                goto LAB_97bcc5c0;
              }
              if (iVar11 != 0xc0e5) {
                iVar3 = 0xc110;
                goto LAB_97bcadb8;
              }
            }
          }
        }
LAB_97bcc470:
        iVar12 = _PPStreamChunkCreateWithType(3,0);
        uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x90000;
        goto LAB_97bcbb78;
      }
      iVar12 = _PPStreamChunkCreateWithType(3,0);
      uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fff3 | 0x50000;
LAB_97bcc190:
      uVar6 = uVar6 | 3;
    }
LAB_97bcc694:
    *(uint *)(iVar12 + 0xc) = uVar6;
    goto LAB_97bcc698;
  }
  if (iVar11 == 0x18b0a) goto LAB_97bcc36c;
  if (iVar11 < 0x18b0b) {
    if (iVar11 == 0x147c7) goto LAB_97bcc2a0;
    if (0x147c7 < iVar11) {
      if (iVar11 == 0x1705e) goto LAB_97bcc3e4;
      if (0x1705e < iVar11) {
        if (iVar11 != 0x17e27) {
          if (iVar11 < 0x17e28) {
            if (iVar11 != 0x170f7) {
              if (iVar11 < 0x170f8) {
                if (iVar11 == 0x17089) goto LAB_97bcc3e4;
                if (iVar11 < 0x1708a) {
                  iVar3 = 0x17076;
                }
                else {
                  if (iVar11 == 0x170a1) goto LAB_97bcc40c;
                  iVar3 = 0x170cc;
                }
LAB_97bcb448:
                if (iVar11 != iVar3) goto LAB_97bcc698;
              }
              else if (iVar11 != 0x17178) {
                if (iVar11 < 0x17179) {
                  if (iVar11 != 0x17122) {
                    iVar3 = 0x1714d;
                    goto LAB_97bcb448;
                  }
                }
                else if (iVar11 != 0x171a3) {
                  iVar3 = 0x17e06;
                  goto LAB_97bcba88;
                }
              }
            }
LAB_97bcc40c:
            iVar12 = _PPStreamChunkCreateWithType(3,0);
            uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fbff | 0x40300;
            goto LAB_97bcc458;
          }
          if (iVar11 != 0x17ecc) {
            if (0x17ecc < iVar11) {
              if (iVar11 != 0x18a83) {
                if (iVar11 < 0x18a84) {
                  if (iVar11 == 0x17eed) goto LAB_97bcc2ec;
                  iVar3 = 0x18a56;
                }
                else {
                  if (iVar11 == 0x18ab0) goto LAB_97bcc36c;
                  iVar3 = 0x18add;
                }
LAB_97bcb594:
                if (iVar11 != iVar3) goto LAB_97bcc698;
              }
LAB_97bcc36c:
              iVar12 = _PPStreamChunkCreateWithType(3,0);
              uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0f8ff | 0x40000;
              goto LAB_97bcc458;
            }
            if (iVar11 != 0x17e69) {
              if (iVar11 < 0x17e6a) {
                iVar3 = 0x17e48;
              }
              else {
                if (iVar11 == 0x17e8a) goto LAB_97bcc2ec;
                iVar3 = 0x17eab;
              }
LAB_97bcba88:
              if (iVar11 != iVar3) goto LAB_97bcc698;
            }
          }
        }
        goto LAB_97bcc2ec;
      }
      if (iVar11 != 0x14d24) {
        if (0x14d24 < iVar11) {
          if (iVar11 != 0x16f5c) {
            if (iVar11 < 0x16f5d) {
              if (iVar11 != 0x14d92) {
                if (0x14d92 < iVar11) {
                  if (iVar11 == 0x158fc) {
                    iVar12 = _PPStreamChunkCreateWithType(3,0);
                    uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe07fff | 0x104000;
LAB_97bcbe54:
                    uVar6 = uVar6 & 0xffffcfff;
LAB_97bcbfa8:
                    uVar6 = uVar6 & 0xfffff8ff;
                    goto LAB_97bcbfac;
                  }
                  if (iVar11 != 0x15dbb) goto LAB_97bcc698;
                  iVar12 = _PPStreamChunkCreateWithType(3,0);
                  uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe00fff | 0x100000;
                  goto LAB_97bcbe28;
                }
                iVar3 = 0x14d5b;
                goto LAB_97bcb334;
              }
              goto LAB_97bcbf0c;
            }
            if (iVar11 != 0x16fdd) {
              if (iVar11 < 0x16fde) {
                if (iVar11 != 0x16f87) {
                  iVar3 = 0x16fb2;
LAB_97bcb3ac:
                  if (iVar11 != iVar3) goto LAB_97bcc698;
                }
              }
              else if (iVar11 != 0x17008) {
                iVar3 = 0x17033;
                goto LAB_97bcb3ac;
              }
            }
          }
LAB_97bcc3e4:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0f9ff | 0x40100;
          goto LAB_97bcc458;
        }
        if (iVar11 != 0x14c11) {
          if (iVar11 < 0x14c12) {
            if (iVar11 != 0x14809) {
              if (iVar11 < 0x1480a) {
                iVar3 = 0x147e8;
              }
              else {
                if (iVar11 == 0x1482a) goto LAB_97bcc2a0;
                iVar3 = 0x1484b;
              }
LAB_97bcb2bc:
              if (iVar11 != iVar3) goto LAB_97bcc698;
            }
            goto LAB_97bcc2a0;
          }
          if (iVar11 != 0x14c7f) {
            if (iVar11 < 0x14c80) {
              iVar3 = 0x14c48;
            }
            else {
              if (iVar11 == 0x14cb6) goto LAB_97bcbf0c;
              iVar3 = 0x14ced;
            }
LAB_97bcb334:
            if (iVar11 != iVar3) goto LAB_97bcc698;
          }
        }
      }
LAB_97bcbf0c:
      iVar12 = _PPStreamChunkCreateWithType(3,0);
      uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe00fff | 0x100000;
LAB_97bcbe84:
      uVar6 = uVar6 & 0xfffff8ff | 0x400;
      goto LAB_97bcc458;
    }
    if (iVar11 == 0x11ea4) goto LAB_97bcc258;
    if (iVar11 < 0x11ea5) {
      if (iVar11 != 0x11b4b) {
        if (0x11b4b < iVar11) {
          if (iVar11 != 0x11d4e) {
            if (iVar11 < 0x11d4f) {
              if (iVar11 != 0x11cb5) {
                if (iVar11 < 0x11cb6) {
                  iVar3 = 0x11c82;
                }
                else {
                  if (iVar11 == 0x11ce8) goto LAB_97bcbe60;
                  iVar3 = 0x11d1b;
                }
LAB_97bcb0c4:
                if (iVar11 != iVar3) goto LAB_97bcc698;
              }
            }
            else if (iVar11 != 0x11de7) {
              if (0x11de7 < iVar11) {
                if (iVar11 != 0x11e62) {
                  iVar3 = 0x11e83;
                  goto LAB_97bcb14c;
                }
                goto LAB_97bcc258;
              }
              if (iVar11 != 0x11d81) {
                iVar3 = 0x11db4;
                goto LAB_97bcb0c4;
              }
            }
          }
LAB_97bcbe60:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x10c000;
          goto LAB_97bcbe80;
        }
        if (iVar11 != 0x11aa6) {
          if (iVar11 < 0x11aa7) {
            if (iVar11 == 0x1142d) {
              iVar12 = _PPStreamChunkCreateWithType(3,0);
              uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x10c000;
              goto LAB_97bcbdf0;
            }
            if (iVar11 < 0x1142e) {
              if (iVar11 != 0x110e1) goto LAB_97bcc698;
              iVar12 = _PPStreamChunkCreateWithType(3,0);
              uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fffe | 0x50000;
              iVar3 = 3;
              goto LAB_97bcc0cc;
            }
            if (iVar11 != 0x11a64) {
              iVar3 = 0x11a85;
              goto LAB_97bcb03c;
            }
          }
          else if (iVar11 != 0x11ae8) {
            if (iVar11 < 0x11ae9) {
              iVar3 = 0x11ac7;
            }
            else {
              if (iVar11 == 0x11b09) goto LAB_97bcc234;
              iVar3 = 0x11b2a;
            }
LAB_97bcb03c:
            if (iVar11 != iVar3) goto LAB_97bcc698;
          }
        }
      }
LAB_97bcc234:
      iVar12 = _PPStreamChunkCreateWithType(3,0);
      uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x30000;
      iVar3 = 2;
    }
    else {
      if (iVar11 != 0x14328) {
        if (iVar11 < 0x14329) {
          if (iVar11 != 0x11f49) {
            if (0x11f49 < iVar11) {
              if (iVar11 == 0x1275a) {
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fff8 | 0x50008;
                goto LAB_97bcc694;
              }
              if (iVar11 < 0x1275b) {
                bVar1 = iVar11 == 0x12304;
LAB_97bcb178:
                if (!bVar1) goto LAB_97bcc698;
                goto LAB_97bcc034;
              }
              if (iVar11 == 0x12c7a) {
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0cfff | 0x10c000;
                goto LAB_97bcbe28;
              }
              iVar3 = 0x14307;
              goto LAB_97bcb220;
            }
            if (iVar11 != 0x11ee6) {
              if (iVar11 < 0x11ee7) {
                iVar3 = 0x11ec5;
              }
              else {
                if (iVar11 == 0x11f07) goto LAB_97bcc258;
                iVar3 = 0x11f28;
              }
LAB_97bcb14c:
              if (iVar11 != iVar3) goto LAB_97bcc698;
            }
          }
LAB_97bcc258:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          iVar3 = 3;
          uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x30000;
          goto LAB_97bcc274;
        }
        if (iVar11 != 0x143ac) {
          if (0x143ac < iVar11) {
            if (iVar11 != 0x14764) {
              if (iVar11 < 0x14765) {
                if (iVar11 != 0x143cd) {
                  iVar3 = 0x143ee;
                  goto LAB_97bcb220;
                }
                goto LAB_97bcc27c;
              }
              if (iVar11 != 0x14785) {
                iVar3 = 0x147a6;
                goto LAB_97bcb2bc;
              }
            }
LAB_97bcc2a0:
            iVar12 = _PPStreamChunkCreateWithType(3,0);
            uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0f7ff | 0x30700;
            goto LAB_97bcc458;
          }
          if (iVar11 != 0x1436a) {
            if (iVar11 < 0x1436b) {
              iVar3 = 0x14349;
LAB_97bcb220:
              if (iVar11 != iVar3) goto LAB_97bcc698;
            }
            else if (iVar11 != 0x1438b) {
              if (iVar11 != 0x143a8) goto LAB_97bcc698;
              iVar12 = _PPStreamChunkCreateWithType(3,0);
              uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe00fff | 0x100000;
              goto LAB_97bcbdf4;
            }
          }
        }
      }
LAB_97bcc27c:
      iVar12 = _PPStreamChunkCreateWithType(3,0);
      uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x30000;
      iVar3 = 6;
    }
LAB_97bcc274:
    uVar6 = iVar3 << 8 | uVar6 & 0xfffff0ff;
  }
  else {
    if (iVar11 == 0x1aa90) goto LAB_97bcc3bc;
    if (0x1aa90 < iVar11) {
      if (iVar11 == 0x21945) {
        iVar12 = _PPStreamChunkCreateWithType(3,0);
        uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe08fff | 0x108000;
LAB_97bcbe28:
        iVar3 = 1;
LAB_97bcbe2c:
        uVar6 = iVar3 << 8 | uVar6 & 0xfffff8ff;
        goto LAB_97bcc694;
      }
      if (iVar11 < 0x21946) {
        if (iVar11 != 0x203d7) {
          if (iVar11 < 0x203d8) {
            if (iVar11 == 0x20368) goto LAB_97bcbfb8;
            if (iVar11 < 0x20369) {
              if (iVar11 == 0x1f97a) {
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe08fff | 0x108000;
LAB_97bcbdf4:
                uVar6 = uVar6 & 0xfffff8ff | 0x300;
LAB_97bcbfac:
                *(uint *)(iVar12 + 0xc) = uVar6;
                *(undefined1 *)(iVar12 + 0xf) = 0;
                goto LAB_97bcc698;
              }
              if (0x1f97a < iVar11) {
                if (iVar11 == 0x1ff52) {
                  iVar12 = _PPStreamChunkCreateWithType(3,0);
                  iVar3 = 5;
                  uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x50001;
                  goto LAB_97bcc0cc;
                }
                iVar3 = 0x20323;
                goto LAB_97bcb91c;
              }
              if (iVar11 != 0x1f1a8) goto LAB_97bcc698;
              goto LAB_97bcc048;
            }
            if (iVar11 != 0x20395) {
              if (iVar11 < 0x20396) {
                iVar3 = 0x20374;
              }
              else {
                if (iVar11 == 0x203ad) goto LAB_97bcbfb8;
                iVar3 = 0x203b6;
              }
              goto LAB_97bcba88;
            }
          }
          else if (iVar11 != 0x2043a) {
            if (iVar11 < 0x2043b) {
              if (iVar11 == 0x203f8) goto LAB_97bcc2ec;
              if (iVar11 < 0x203f9) {
                iVar3 = 0x203f2;
              }
              else {
                if (iVar11 == 0x20419) goto LAB_97bcc2ec;
                iVar3 = 0x20437;
              }
LAB_97bcb91c:
              if (iVar11 != iVar3) goto LAB_97bcc698;
            }
            else if (iVar11 != 0x204c1) {
              if (iVar11 < 0x204c2) {
                if (iVar11 != 0x2045b) {
                  iVar3 = 0x2047c;
                  goto LAB_97bcb91c;
                }
                goto LAB_97bcc2ec;
              }
              if (iVar11 != 0x20506) {
                if (iVar11 != 0x2138c) goto LAB_97bcc698;
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x10c000;
                goto LAB_97bcbe54;
              }
            }
LAB_97bcbfb8:
            iVar12 = _PPStreamChunkCreateWithType(3,0);
            uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe08fff | 0x108000;
            goto LAB_97bcbe84;
          }
        }
      }
      else {
        if (iVar11 == 0x24cb9) {
LAB_97bcc048:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          iVar3 = 0xe;
          goto LAB_97bcc5c0;
        }
        if (iVar11 < 0x24cba) {
          if (iVar11 != 0x2461d) {
            if (iVar11 < 0x2461e) {
              if (iVar11 == 0x23231) goto LAB_97bcc048;
              if (iVar11 < 0x23232) {
                if (iVar11 != 0x21eb8) goto LAB_97bcc698;
                iVar12 = _PPStreamChunkCreateWithType(3,0);
                iVar3 = 5;
                uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fffe | 0x50000;
LAB_97bcc0cc:
                uVar6 = iVar3 << 1 | uVar6 & 0xfffffff1;
                goto LAB_97bcc694;
              }
              if (iVar11 != 0x245db) {
                iVar3 = 0x245fc;
                goto LAB_97bcba88;
              }
            }
            else if (iVar11 != 0x24680) {
              if (iVar11 < 0x24681) {
                if (iVar11 != 0x2463e) {
                  iVar3 = 0x2465f;
                  goto LAB_97bcba88;
                }
              }
              else if (iVar11 != 0x246a1) {
                iVar3 = 0x246c2;
                goto LAB_97bcba88;
              }
            }
          }
        }
        else if (iVar11 != 0x2616e) {
          if (iVar11 < 0x2616f) {
            if (iVar11 != 0x2610b) {
              if (iVar11 < 0x2610c) {
                if (iVar11 == 0x254c3) {
                  iVar12 = _PPStreamChunkCreateWithType(3,0);
                  *(uint *)(iVar12 + 0xc) = *(uint *)(iVar12 + 0xc) & 0xffe008ff | 0x100000;
                  *(undefined1 *)(iVar12 + 0xf) = 0;
                }
                goto LAB_97bcc698;
              }
              if (iVar11 != 0x2612c) {
                iVar3 = 0x2614d;
                goto LAB_97bcba88;
              }
            }
          }
          else if (iVar11 != 0x261d1) {
            if (iVar11 < 0x261d2) {
              if (iVar11 != 0x2618f) {
                iVar3 = 0x261b0;
                goto LAB_97bcba88;
              }
            }
            else if (iVar11 != 0x261f2) {
              if (iVar11 != 0x343c5) goto LAB_97bcc698;
              iVar12 = _PPStreamChunkCreateWithType(3,0);
              uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe08fff | 0x108000;
              goto LAB_97bcbfa8;
            }
          }
        }
      }
LAB_97bcc2ec:
      iVar12 = _PPStreamChunkCreateWithType(3,0);
      uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x30000;
      iVar3 = 5;
      goto LAB_97bcc274;
    }
    if (iVar11 == 0x18e85) {
LAB_97bcc2c8:
      iVar12 = _PPStreamChunkCreateWithType(3,0);
      uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0ffff | 0x30000;
      iVar3 = 4;
      goto LAB_97bcc274;
    }
    if (0x18e85 < iVar11) {
      if (iVar11 != 0x19384) {
        if (0x19384 < iVar11) {
          if (iVar11 != 0x1a982) {
            if (iVar11 < 0x1a983) {
              if (iVar11 != 0x193c6) {
                if (iVar11 < 0x193c7) {
                  iVar3 = 0x193a5;
                  goto LAB_97bcb768;
                }
                if (iVar11 != 0x193e7) {
                  iVar3 = 0x1a955;
                  goto LAB_97bcb7d8;
                }
              }
              goto LAB_97bcc2c8;
            }
            if (iVar11 != 0x1aa09) {
              if (iVar11 < 0x1aa0a) {
                if (iVar11 != 0x1a9af) {
                  iVar3 = 0x1a9dc;
LAB_97bcb7d8:
                  if (iVar11 != iVar3) goto LAB_97bcc698;
                }
              }
              else if (iVar11 != 0x1aa36) {
                iVar3 = 0x1aa63;
                goto LAB_97bcb7d8;
              }
            }
          }
LAB_97bcc3bc:
          iVar12 = _PPStreamChunkCreateWithType(3,0);
          uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fcff | 0x40400;
          goto LAB_97bcc458;
        }
        if (iVar11 != 0x18f09) {
          if (iVar11 < 0x18f0a) {
            if (iVar11 != 0x18ea6) {
              if (iVar11 < 0x18ea7) {
                iVar3 = 0x18e8a;
                goto LAB_97bcb6c4;
              }
              if (iVar11 != 0x18ec7) {
                iVar3 = 0x18ee8;
                goto LAB_97bcb768;
              }
            }
          }
          else if (iVar11 != 0x19321) {
            if (iVar11 < 0x19322) {
              if (iVar11 != 0x18f2a) {
                iVar3 = 0x19300;
LAB_97bcb768:
                if (iVar11 != iVar3) goto LAB_97bcc698;
              }
            }
            else if (iVar11 != 0x19342) {
              iVar3 = 0x19363;
              goto LAB_97bcb768;
            }
          }
        }
      }
      goto LAB_97bcc2c8;
    }
    if (iVar11 != 0x18c8a) {
      if (0x18c8a < iVar11) {
        if (iVar11 != 0x18dde) {
          if (iVar11 < 0x18ddf) {
            if (iVar11 != 0x18d5d) {
              if (iVar11 < 0x18d5e) {
                iVar3 = 0x18cb7;
                goto LAB_97bcb60c;
              }
              if (iVar11 != 0x18d88) {
                iVar3 = 0x18db3;
LAB_97bcb6c4:
                if (iVar11 != iVar3) goto LAB_97bcc698;
              }
            }
          }
          else {
            if (iVar11 == 0x18e43) goto LAB_97bcc2c8;
            if (iVar11 < 0x18e44) {
              if (iVar11 != 0x18e09) {
                iVar3 = 0x18e34;
                goto LAB_97bcb6c4;
              }
            }
            else if (iVar11 != 0x18e5f) {
              iVar3 = 0x18e64;
              goto LAB_97bcb768;
            }
          }
        }
        iVar12 = _PPStreamChunkCreateWithType(3,0);
        uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0fdff | 0x40500;
        goto LAB_97bcc458;
      }
      if (iVar11 != 0x18ba9) {
        if (iVar11 < 0x18baa) {
          if (iVar11 == 0x18b64) goto LAB_97bcc36c;
          if (iVar11 < 0x18b65) {
            iVar3 = 0x18b37;
          }
          else {
            if (iVar11 == 0x18b7c) goto LAB_97bcc390;
            iVar3 = 0x18b91;
          }
          goto LAB_97bcb594;
        }
        if (iVar11 != 0x18c03) {
          if (iVar11 < 0x18c04) {
            iVar3 = 0x18bd6;
          }
          else {
            if (iVar11 == 0x18c30) goto LAB_97bcc390;
            iVar3 = 0x18c5d;
          }
LAB_97bcb60c:
          if (iVar11 != iVar3) goto LAB_97bcc698;
        }
      }
    }
LAB_97bcc390:
    iVar12 = _PPStreamChunkCreateWithType(3,0);
    uVar6 = *(uint *)(iVar12 + 0xc) & 0xffe0f8ff | 0x40200;
  }
LAB_97bcc458:
  *(uint *)(iVar12 + 0xc) = uVar6;
  uVar9 = ParseSymbol__GetDirectIndex(param_1,0);
  *(undefined1 *)(iVar12 + 0xf) = uVar9;
LAB_97bcc698:
  *(undefined4 *)(param_1 + 0x34) = 1;
  return iVar12;
}

/* GetChunkForSymbol @ 0x97bcc6b8 (592 bytes) */
int GetChunkForSymbol(param_1, param_2)
  unsigned char * param_1;
  int param_2;
{
  bool bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  
  iVar8 = *(int *)(param_1 + 0x14);
  if (((iVar8 == 0) || (iVar4 = _memcmp(iVar8,"gl_",3), iVar4 != 0)) ||
     (*(char *)(iVar8 + 3) == '_')) {
    uVar6 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))(*(int **)(param_1 + 0xc));
    switch(uVar6) {
    case 0:
    case 1:
    case 2:
    case 4:
    case 5:
    case 9:
    case 10:
    case 0xb:
    case 0xc:
      pbVar5 = (byte *)_PPStreamChunkCreateWithType(0,0);
      break;
    case 3:
      pbVar5 = (byte *)_PPStreamChunkCreateWithType(2,0);
      *(uint *)(pbVar5 + 0xc) = *(uint *)(pbVar5 + 0xc) & 0xfff0ffff | 0x90000;
      break;
    case 6:
      pbVar5 = (byte *)_PPStreamChunkCreateWithType(3,0);
      *(uint *)(pbVar5 + 0xc) = *(uint *)(pbVar5 + 0xc) & 0xffe0ffff | 0x10000;
      iVar8 = (**(code **)(**(int **)(param_1 + 0xc) + 0x20))(*(int **)(param_1 + 0xc));
      *(uint *)(pbVar5 + 0x10) =
           (uint)(iVar8 - 5U < 8) << 0x1f | *(uint *)(pbVar5 + 0x10) & 0x7fffffff;
      break;
    default:
      pbVar5 = (byte *)0x0;
    }
  }
  else {
    pbVar5 = (byte *)((int (*)())GetBuiltInChunkForSymbol)(param_1,param_2);
    *(undefined4 *)(param_1 + 0x38) = 1;
    *(undefined4 *)(param_1 + 0x28) = 0xffffffff;
  }
  if (pbVar5 == (byte *)0x0) goto LAB_97bcc8c4;
  bVar2 = *pbVar5;
  if (bVar2 == 2) {
LAB_97bcc864:
    uVar7 = GetPPStreamTypeForGLType((uint)*(ushort *)(param_1 + 0x2c));
    *(uint *)(pbVar5 + 0xc) = (uVar7 & 7) << 0x1a | *(uint *)(pbVar5 + 0xc) & 0xe3ffffff;
    iVar8 = GetScalerWidthForType((uint)*(ushort *)(param_1 + 0x2c));
    uVar7 = (iVar8 + -1) * 0x1000000 & 0x3000000U | *(uint *)(pbVar5 + 0xc) & 0x1cffffff;
LAB_97bcc8c0:
    *(uint *)(pbVar5 + 0xc) = uVar7;
  }
  else if (bVar2 < 3) {
    if (bVar2 == 0) {
      uVar7 = GetPPStreamTypeForGLType((uint)*(ushort *)(param_1 + 0x2c));
      *(uint *)(pbVar5 + 0xc) = (uVar7 & 7) << 0x1a | *(uint *)(pbVar5 + 0xc) & 0xe3ffffff;
      iVar8 = GetScalerWidthForType((uint)*(ushort *)(param_1 + 0x2c));
      uVar7 = (iVar8 + -1) * 0x1000000 & 0x3000000U | *(uint *)(pbVar5 + 0xc) & 0x1cffffff;
      goto LAB_97bcc8c0;
    }
  }
  else if ((bVar2 == 3) || (bVar2 == 4)) goto LAB_97bcc864;
LAB_97bcc8c4:
  if (*(int *)(param_1 + 0x34) == 0) {
    return pbVar5;
  }
  uVar7 = ((int (*)())GetBuiltInInitialSwizzle)(param_1);
  if (uVar7 == 0) {
    return pbVar5;
  }
  bVar2 = *pbVar5;
  if (bVar2 != 2) {
    if (bVar2 < 3) {
      bVar1 = bVar2 == 0;
    }
    else {
      if (bVar2 == 3) goto LAB_97bcc908;
      bVar1 = bVar2 == 4;
    }
    if (!bVar1) {
      return pbVar5;
    }
  }
LAB_97bcc908:
  uVar3 = *(uint *)(pbVar5 + 0xc) >> 0x18 & 3;
  if (uVar3 < uVar7) {
    uVar3 = uVar7;
  }
  *(uint *)(pbVar5 + 0xc) = (uVar3 & 3) << 0x18 | *(uint *)(pbVar5 + 0xc) & 0xfcffffff;
  return pbVar5;
}

/* __ZN13FunctionTableC2Ev @ 0x97bcc93c (4 bytes) */
int __ZN13FunctionTableC2Ev(this)
  void *this;
{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* __ZN13FunctionTableC1Ev @ 0x97bcc940 (4 bytes) */
int __ZN13FunctionTableC1Ev(this)
  void *this;
{
  ((int (*)())__ZN13FunctionTableC4Ev)(this);
  return;
}

/* __ZN13FunctionTableC4Ev @ 0x97bcc944 (16 bytes) */
int __ZN13FunctionTableC4Ev(this)
  void *this;
{
  *(undefined4 *)((int)this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* __ZN13FunctionTableD2Ev @ 0x97bcc954 (8 bytes) */
int __ZN13FunctionTableD2Ev(this)
  void *this;
{
  ((int (*)())__ZN13FunctionTableD4Ev)(this);
  return;
}

/* __ZN13FunctionTableD1Ev @ 0x97bcc95c (8 bytes) */
int __ZN13FunctionTableD1Ev(this)
  void *this;
{
  ((int (*)())__ZN13FunctionTableD4Ev)(this);
  return;
}

/* __ZN13FunctionTableD4Ev @ 0x97bcc964 (4 bytes) */
int __ZN13FunctionTableD4Ev(this)
  void *this;
{
  ((int (*)())FunctionTable__clear)(this);
  return;
}

/* FunctionTable__clear @ 0x97bcc968 (120 bytes) */
int FunctionTable__clear(this)
  unsigned char * this;
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(this + 4)) {
    iVar3 = 0;
    do {
      iVar2 = iVar2 + 1;
      puVar1 = (undefined4 *)(iVar3 + *(int *)this);
      iVar3 = iVar3 + 0x18;
      _free(*puVar1);
    } while (iVar2 < *(int *)(this + 4));
  }
  if (*(int *)this != 0) {
    _free(*(int *)this);
  }
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* FunctionTable__addFunction @ 0x97bcc9e0 (284 bytes) */
int FunctionTable__addFunction(this, param_2)
  unsigned char * this;
  char *param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  
  uVar10 = *(uint *)(this + 4);
  if ((uVar10 & 0xf) == 0) {
    iVar2 = _malloc(uVar10 * 0x18 + 0x180);
    _memset(iVar2,0,*(int *)(this + 4) * 0x18 + 0x180);
    uVar10 = *(uint *)(this + 4);
    iVar4 = 0;
    if ((int)uVar10 < 1) {
      iVar3 = *(int *)this;
    }
    else {
      iVar3 = *(int *)this;
      iVar5 = 0;
      do {
        iVar9 = iVar5 + iVar3;
        uVar7 = *(undefined4 *)(iVar9 + 4);
        iVar4 = iVar4 + 1;
        uVar8 = *(undefined4 *)(iVar9 + 8);
        iVar1 = iVar5 + iVar2;
        uVar6 = *(undefined4 *)(iVar9 + 0xc);
        *(undefined4 *)(iVar5 + iVar2) = *(undefined4 *)(iVar5 + iVar3);
        iVar5 = iVar5 + 0x18;
        *(undefined4 *)(iVar1 + 4) = uVar7;
        *(undefined4 *)(iVar1 + 8) = uVar8;
        *(undefined4 *)(iVar1 + 0xc) = uVar6;
        uVar6 = *(undefined4 *)(iVar9 + 0x10);
        *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar9 + 0x14);
        *(undefined4 *)(iVar1 + 0x10) = uVar6;
      } while (iVar4 < (int)uVar10);
    }
    if (iVar3 != 0) {
      _free(iVar3);
      uVar10 = *(uint *)(this + 4);
    }
    *(int *)this = iVar2;
  }
  iVar4 = *(int *)this;
  iVar2 = _strlen(param_2);
  uVar6 = _malloc(iVar2 + 1);
  *(undefined4 *)(uVar10 * 0x18 + iVar4) = uVar6;
  _strcpy(*(undefined4 *)(*(int *)(this + 4) * 0x18 + *(int *)this),param_2);
  iVar2 = *(int *)(this + 4);
  *(int *)(this + 4) = iVar2 + 1;
  return iVar2;
}

/* FunctionTable__removeFunction @ 0x97bccafc (168 bytes) */
int FunctionTable__removeFunction(this, param_2)
  unsigned char * this;
  int param_2;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = param_2 * 0x18;
  _free(*(undefined4 *)(iVar5 + *(int *)this));
  iVar1 = *(int *)(this + 4);
  if (param_2 < iVar1) {
    do {
      param_2 = param_2 + 1;
      iVar1 = iVar5 + *(int *)this;
      uVar4 = *(undefined4 *)(iVar1 + 0x1c);
      uVar3 = *(undefined4 *)(iVar1 + 0x20);
      uVar2 = *(undefined4 *)(iVar1 + 0x24);
      *(undefined4 *)(iVar5 + *(int *)this) = *(undefined4 *)(iVar1 + 0x18);
      iVar5 = iVar5 + 0x18;
      *(undefined4 *)(iVar1 + 4) = uVar4;
      *(undefined4 *)(iVar1 + 8) = uVar3;
      *(undefined4 *)(iVar1 + 0xc) = uVar2;
      *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar1 + 0x2c);
      *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(iVar1 + 0x28);
      iVar1 = *(int *)(this + 4);
    } while (param_2 < iVar1);
  }
  *(int *)(this + 4) = iVar1 + -1;
  return;
}

/* FunctionTable__setReturnVal @ 0x97bccba4 (20 bytes) */
int FunctionTable__setReturnVal(this, param_2, param_3)
  unsigned char * this;
  int param_2;
  undefined4 param_3;
{
  *(undefined4 *)(param_2 * 0x18 + *(int *)this + 4) = param_3;
  return;
}

/* FunctionTable__setEmpty @ 0x97bccbb8 (20 bytes) */
int FunctionTable__setEmpty(this, param_2, param_3)
  unsigned char * this;
  int param_2;
  undefined4 param_3;
{
  *(undefined4 *)(param_2 * 0x18 + *(int *)this + 8) = param_3;
  return;
}

/* FunctionTable__setNumParams @ 0x97bccbcc (20 bytes) */
int FunctionTable__setNumParams(this, param_2, param_3)
  unsigned char * this;
  int param_2;
  int param_3;
{
  *(int *)(param_2 * 0x18 + *(int *)this + 0xc) = param_3;
  return;
}

/* FunctionTable__setFirstOp @ 0x97bccbe0 (20 bytes) */
int FunctionTable__setFirstOp(this, param_2, param_3)
  unsigned char * this;
  int param_2;
  uint param_3;
{
  *(uint *)(param_2 * 0x18 + *(int *)this + 0x10) = param_3;
  return;
}

/* FunctionTable__setLastOp @ 0x97bccbf4 (20 bytes) */
int FunctionTable__setLastOp(this, param_2, param_3)
  unsigned char * this;
  int param_2;
  uint param_3;
{
  *(uint *)(param_2 * 0x18 + *(int *)this + 0x14) = param_3;
  return;
}

/* FunctionTable__updateForRemovingChunk @ 0x97bccc08 (168 bytes) */
int FunctionTable__updateForRemovingChunk(this, param_2)
  unsigned char * this;
  unsigned char * param_2;
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar1 = 0;
  if (0 < *(int *)(this + 4)) {
    iVar2 = 0;
    do {
      iVar3 = *(int *)this;
      uVar5 = *(uint *)(param_2 + 0xc);
      iVar4 = iVar2 + iVar3;
      if ((((uVar5 & 0x3ffff) == *(uint *)(iVar4 + 0x14)) && (*(int *)(param_2 + 4) != 0)) &&
         (*(int *)(iVar4 + 0x10) != 0)) {
        *(uint *)(iVar4 + 0x14) = *(uint *)(*(int *)(param_2 + 4) + 0xc) & 0x3ffff;
        uVar5 = *(uint *)(param_2 + 0xc);
        iVar3 = *(int *)this;
      }
      if ((((uVar5 & 0x3ffff) == *(uint *)(iVar2 + iVar3 + 0x10)) && (*(int *)(param_2 + 8) != 0))
         && ((uVar5 & 0x3ffff) != 0)) {
        *(uint *)(iVar2 + iVar3 + 0x10) = *(uint *)(*(int *)(param_2 + 8) + 0xc) & 0x3ffff;
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x18;
    } while (iVar1 < *(int *)(this + 4));
    return;
  }
  return;
}

/* FunctionTable__findFunction @ 0x97bcccb0 (132 bytes) */
int FunctionTable__findFunction(this, param_2, param_3, param_4, param_5, param_6)
  unsigned char * this;
  char *param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = *(int *)(this + 4);
  if (0 < iVar1) {
    iVar2 = 0;
    do {
      iVar1 = _strcmp(*(undefined4 *)(iVar2 + *(int *)this),param_2);
      if (iVar1 == 0) {
        iVar1 = *(int *)(this + 4);
        break;
      }
      iVar1 = *(int *)(this + 4);
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x18;
    } while (iVar3 < iVar1);
  }
  if (iVar3 == iVar1) {
    iVar3 = -1;
  }
  return iVar3;
}

/* FunctionTable__getFunctionName @ 0x97bccd34 (16 bytes) */
int FunctionTable__getFunctionName(this, param_2)
  unsigned char * this;
  int param_2;
{
  return *(undefined4 *)(param_2 * 0x18 + *(int *)this);
}

/* FunctionTable__getReturnVal @ 0x97bccd44 (20 bytes) */
int FunctionTable__getReturnVal(this, param_2)
  unsigned char * this;
  int param_2;
{
  return *(undefined4 *)(param_2 * 0x18 + *(int *)this + 4);
}

/* FunctionTable__getEmpty @ 0x97bccd58 (20 bytes) */
int FunctionTable__getEmpty(this, param_2)
  unsigned char * this;
  int param_2;
{
  return *(undefined4 *)(param_2 * 0x18 + *(int *)this + 8);
}

/* FunctionTable__getNumParams @ 0x97bccd6c (20 bytes) */
int FunctionTable__getNumParams(this, param_2)
  unsigned char * this;
  int param_2;
{
  return *(undefined4 *)(param_2 * 0x18 + *(int *)this + 0xc);
}

/* FunctionTable__getFirstOp @ 0x97bccd80 (20 bytes) */
int FunctionTable__getFirstOp(this, param_2)
  unsigned char * this;
  int param_2;
{
  return *(undefined4 *)(param_2 * 0x18 + *(int *)this + 0x10);
}

/* FunctionTable__getLastOp @ 0x97bccd94 (20 bytes) */
int FunctionTable__getLastOp(this, param_2)
  unsigned char * this;
  int param_2;
{
  return *(undefined4 *)(param_2 * 0x18 + *(int *)this + 0x14);
}

/* FunctionTable__dump @ 0x97bccda8 (4 bytes) */
int FunctionTable__dump()
{
  return;
}

/* _InterpreterCreate @ 0x97bccdac (60 bytes) */
int _InterpreterCreate()
{
  undefined4 uVar1;
  
  uVar1 = _calloc(0xa70,1);
  ((int (*)())_InterpreterInit)(uVar1);
  return uVar1;
}

/* _InterpreterFree @ 0x97bccde8 (48 bytes) */
int _InterpreterFree(param_1)
  undefined4 param_1;
{
  ((int (*)())_InterpreterShutdown)(param_1);
  _free(param_1);
  return;
}

/* _InterpreterInit @ 0x97bcce18 (72 bytes) */
int _InterpreterInit(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  _memset(param_1,0,0xa70);
  uVar1 = ((int (*)())_InterpreterTextureSamplerCreate)();
  *(undefined4 *)(param_1 + 0xa2c) = uVar1;
  _InterpreterNoiseGeneratorInitialise(param_1 + 4);
  _InterpreterRasterOpMachineInitialise(param_1 + 0xa24);
  return;
}

/* _InterpreterShutdown @ 0x97bcce60 (8 bytes) */
int _InterpreterShutdown(param_1)
  int param_1;
{
  undefined4 uVar1;
  
  uVar1 = _InterpreterTextureSamplerFree(*(undefined4 *)(param_1 + 0xa2c));
  return uVar1;
}

/* _InterpreterAttachEmulatorContext @ 0x97bcce68 (12 bytes) */
int _InterpreterAttachEmulatorContext(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  _InterpreterRasterOpMachineAttachEmulatorContext(param_1 + 0x289,param_2);
  return;
}

/* _InterpreterPackPixel @ 0x97bcce74 (1208 bytes) */
int _InterpreterPackPixel(param_1, param_2, param_3)
  int *param_1;
  float *param_2;
  float *param_3;
{
  float fVar1;
  float fVar2;
  uint uVar3;
  uint uVar4;
  float fVar5;
  uint uVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  double dVar11;
  double dVar12;
  
  iVar9 = *param_1;
  if (*(int *)(iVar9 + 0xd9c) != 0) {
    uVar4 = _PPEmulatorFramebufferFormat(iVar9);
    if ((uVar4 & 0x8000000) == 0) {
      uVar4 = _PPEmulatorFramebufferFormat(iVar9);
      fVar5 = FLOAT_97c3acc0;
      fVar2 = FLOAT_97c3acbc;
      if ((uVar4 & 0x8000) == 0) {
        uVar4 = _PPEmulatorFramebufferFormat(iVar9);
        fVar5 = FLOAT_97c3acc4;
        fVar2 = FLOAT_97c3acc0;
        if ((uVar4 & 0x400) == 0) {
          return;
        }
        fVar7 = *param_2 * FLOAT_97c3acc4 + FLOAT_97c3acc0;
        fVar1 = param_2[1] * FLOAT_97c3acc4 + FLOAT_97c3acc0;
        bVar10 = TAllocation__guardBlockSize <= fVar7;
        *param_2 = fVar7;
        param_2[1] = fVar1;
        param_2[2] = param_2[2] * fVar5 + fVar2;
        fVar2 = TAllocation__guardBlockSize;
        if (bVar10) {
          if (fVar5 < fVar7) {
            fVar7 = 31.0;
          }
        }
        else {
          fVar7 = 0.0;
        }
        fVar5 = param_2[1];
        *param_2 = fVar7;
        fVar7 = TAllocation__guardBlockSize;
        if (fVar2 <= fVar5) {
          if (FLOAT_97c3acc4 < fVar5) {
            fVar5 = 31.0;
          }
        }
        else {
          fVar5 = 0.0;
        }
        fVar2 = param_2[2];
        param_2[1] = fVar5;
        dVar12 = DOUBLE_97c30a78;
        if (fVar7 <= fVar2) {
          if (FLOAT_97c3acc4 < fVar2) {
            fVar2 = 31.0;
          }
        }
        else {
          fVar2 = 0.0;
        }
        dVar11 = (double)*param_2;
        param_2[2] = fVar2;
        if (dVar12 <= dVar11) {
          uVar4 = (uint)(dVar11 - dVar12);
        }
        else {
          uVar4 = (uint)*param_2;
        }
        dVar12 = (double)param_2[1];
        if (DOUBLE_97c30a78 <= dVar12) {
          uVar6 = (uint)(dVar12 - DOUBLE_97c30a78);
        }
        else {
          uVar6 = (uint)param_2[1];
        }
        dVar12 = (double)param_2[2];
        if (DOUBLE_97c30a78 <= dVar12) {
          uVar8 = (uint)(dVar12 - DOUBLE_97c30a78);
        }
        else {
          uVar8 = (uint)param_2[2];
        }
        if (FLOAT_97c3acc0 <= param_2[3]) {
          uVar3 = 0x8000;
        }
        else {
          uVar3 = 0;
        }
        fVar2 = (float)(uVar3 | (uVar4 & 0x1f) << 10 | (uVar6 & 0x1f) << 5 | uVar8 & 0x1f);
      }
      else {
        fVar7 = *param_2 * FLOAT_97c3acbc + FLOAT_97c3acc0;
        fVar1 = param_2[1] * FLOAT_97c3acbc + FLOAT_97c3acc0;
        bVar10 = TAllocation__guardBlockSize <= fVar7;
        *param_2 = fVar7;
        param_2[1] = fVar1;
        param_2[3] = param_2[3] * fVar2 + fVar5;
        param_2[2] = param_2[2] * fVar2 + fVar5;
        fVar5 = TAllocation__guardBlockSize;
        if (bVar10) {
          if (fVar2 < fVar7) {
            fVar7 = 255.0;
          }
        }
        else {
          fVar7 = 0.0;
        }
        fVar2 = param_2[1];
        *param_2 = fVar7;
        fVar7 = TAllocation__guardBlockSize;
        if (fVar5 <= fVar2) {
          if (FLOAT_97c3acbc < fVar2) {
            fVar2 = 255.0;
          }
        }
        else {
          fVar2 = 0.0;
        }
        fVar5 = param_2[2];
        param_2[1] = fVar2;
        fVar2 = TAllocation__guardBlockSize;
        if (fVar7 <= fVar5) {
          if (FLOAT_97c3acbc < fVar5) {
            fVar5 = 255.0;
          }
        }
        else {
          fVar5 = 0.0;
        }
        fVar7 = param_2[3];
        param_2[2] = fVar5;
        dVar12 = DOUBLE_97c30a78;
        if (fVar2 <= fVar7) {
          if (FLOAT_97c3acbc < fVar7) {
            fVar7 = 255.0;
          }
        }
        else {
          fVar7 = 0.0;
        }
        dVar11 = (double)*param_2;
        param_2[3] = fVar7;
        if (dVar12 <= dVar11) {
          uVar4 = (uint)(dVar11 - dVar12);
        }
        else {
          uVar4 = (uint)*param_2;
        }
        dVar12 = (double)param_2[1];
        if (DOUBLE_97c30a78 <= dVar12) {
          uVar6 = (uint)(dVar12 - DOUBLE_97c30a78);
        }
        else {
          uVar6 = (uint)param_2[1];
        }
        dVar12 = (double)param_2[2];
        if (DOUBLE_97c30a78 <= dVar12) {
          uVar8 = (uint)(dVar12 - DOUBLE_97c30a78);
        }
        else {
          uVar8 = (uint)param_2[2];
        }
        dVar12 = (double)param_2[3];
        if (DOUBLE_97c30a78 <= dVar12) {
          iVar9 = (int)(dVar12 - DOUBLE_97c30a78);
        }
        else {
          iVar9 = (int)param_2[3];
        }
        fVar2 = (float)(iVar9 << 0x18 | (uVar4 & 0xff) << 0x10 | (uVar6 & 0xff) << 8 | uVar8 & 0xff)
        ;
      }
      *param_3 = fVar2;
    }
    else {
      fVar2 = *param_2;
      fVar5 = param_2[1];
      fVar7 = param_2[2];
      param_3[3] = param_2[3];
      *param_3 = fVar2;
      param_3[1] = fVar5;
      param_3[2] = fVar7;
    }
  }
  return;
}

/* _InterpreterUnpackPixel @ 0x97bcd32c (428 bytes) */
int _InterpreterUnpackPixel(param_1, param_2, param_3)
  int *param_1;
  float *param_2;
  float *param_3;
{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  
  iVar7 = *param_1;
  if (*(int *)(iVar7 + 0xd9c) != 0) {
    uVar4 = _PPEmulatorFramebufferFormat(iVar7);
    if ((uVar4 & 0x8000000) == 0) {
      uVar4 = _PPEmulatorFramebufferFormat(iVar7);
      if ((uVar4 & 0x8000) == 0) {
        uVar4 = _PPEmulatorFramebufferFormat(iVar7);
        if ((uVar4 & 0x400) == 0) {
          return;
        }
        fVar6 = *param_3;
        fVar3 = (float)((double)CONCAT44(0x43300000,(uint)fVar6 >> 10 & 0x1f) - DOUBLE_97c30a68) -
                FLOAT_97c3acc0;
        fVar5 = (float)((double)CONCAT44(0x43300000,(uint)fVar6 >> 5 & 0x1f) - DOUBLE_97c30a68) -
                FLOAT_97c3acc0;
        fVar2 = (float)((double)CONCAT44(0x43300000,(uint)fVar6 >> 0xf & 1) - DOUBLE_97c30a68) -
                FLOAT_97c3acc0;
        fVar6 = (float)((double)CONCAT44(0x43300000,(uint)fVar6 & 0x1f) - DOUBLE_97c30a68) -
                FLOAT_97c3acc0;
        fVar1 = FLOAT_97c3accc;
      }
      else {
        fVar2 = *param_3;
        fVar3 = (float)((double)CONCAT44(0x43300000,(uint)fVar2 >> 0x10 & 0xff) - DOUBLE_97c30a68);
        fVar5 = (float)((double)CONCAT44(0x43300000,(uint)fVar2 >> 8 & 0xff) - DOUBLE_97c30a68);
        fVar6 = (float)((double)CONCAT44(0x43300000,(uint)fVar2 & 0xff) - DOUBLE_97c30a68);
        fVar2 = (float)((double)CONCAT44(0x43300000,(uint)fVar2 >> 0x18) - DOUBLE_97c30a68);
        fVar1 = FLOAT_97c3acc8;
      }
      param_2[3] = fVar2 * fVar1;
      *param_2 = fVar3 * fVar1;
      param_2[1] = fVar5 * fVar1;
      param_2[2] = fVar6 * fVar1;
    }
    else {
      fVar3 = *param_3;
      fVar5 = param_3[1];
      fVar6 = param_3[2];
      param_2[3] = param_3[3];
      *param_2 = fVar3;
      param_2[1] = fVar5;
      param_2[2] = fVar6;
    }
  }
  return;
}

/* _InterpreterWriteDestination @ 0x97bcd4d8 (1100 bytes) */
int _InterpreterWriteDestination(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12, param_13)
  int *param_1;
  int param_2;
  int param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  uint param_9;
  undefined4 param_10;
  int param_11;
  float *param_12;
  undefined4 param_13;
{
  int iVar1;
  int iVar2;
  float *pfVar3;
  float *pfVar4;
  float *pfVar5;
  int *piVar6;
  float *pfVar7;
  int *piVar8;
  undefined1 uVar9;
  int iStack0000001c;
  int iStack00000020;
  uint uStack00000024;
  short sStack00000028;
  ushort uStack0000002c;
  char cStack0000002f;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  float local_50 [4];
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  
  pfVar5 = local_50;
  local_40 = param_12[param_4 >> 0x18];
  local_3c = param_12[param_4 >> 0x10 & 0xff];
  local_38 = param_12[param_4 >> 8 & 0xff];
  local_34 = param_12[param_4 & 0xff];
  iVar1 = *param_1;
  *param_12 = local_40;
  param_12[1] = local_3c;
  param_12[2] = local_38;
  param_12[3] = local_34;
  iVar2 = *(int *)(iVar1 + 0xd80);
  uStack0000002c = (ushort)((uint)param_6 >> 0x10);
  if (((*(int *)(iVar2 + 0x38) == 0x8804) || (*(int *)(iVar2 + 0x38) == 0x8b30)) &&
     (uStack0000002c == 1)) {
    piVar6 = param_1 + 0x292;
    piVar8 = (int *)(param_2 + param_11 * 0x10);
  }
  else {
    if (((*(int *)(iVar2 + 0x38) == 0x8804) || (*(int *)(iVar2 + 0x38) == 0x8b30)) &&
       (uStack0000002c == 9)) {
      piVar6 = param_1 + 0x28c;
    }
    else {
      cStack0000002f = (char)param_6;
      piVar6 = *(int **)((uint)uStack0000002c * 4 + iVar1 + 0xd84);
      if (cStack0000002f != '\0') {
        iVar2 = param_3 * 0xc + iVar2;
        sStack00000028 = (short)((uint)param_5 >> 0x10);
        iVar1 = *(int *)(iVar2 + 0x80);
        piVar8 = (int *)(iVar1 + (((uint)((param_2 + param_11 * 0x10) - iVar1) >> 4) +
                                  param_1[0x290] + (int)sStack00000028 & *(uint *)(iVar2 + 0x88)) *
                                 0x10);
        goto LAB_97bcd680;
      }
    }
    piVar8 = (int *)(param_2 + param_11 * 0x10);
  }
LAB_97bcd680:
  pfVar4 = pfVar5;
  iStack0000001c = param_2;
  iStack00000020 = param_3;
  uStack00000024 = param_4;
  (*(short *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)) = param_5;
  (*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x2c)) = param_6;
  uStack00000030 = param_7;
  uStack00000034 = param_8;
  if ((((param_9 & 0x1000000) != 0) &&
      (iVar1 = ((int (*)())_InterpreterTestCR)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                                  param_9,param_10,0), iVar1 != 0)) &&
     (pfVar4 = (float *)((int)piVar6 + *piVar8), (char)param_13 != '\0')) {
    iVar1 = ___isnanf(iVar1);
    uVar9 = 3;
    if ((iVar1 == 0) && (uVar9 = 0.0 < *param_12, *param_12 < 0.0)) {
      uVar9 = 2;
    }
    *(undefined1 *)(param_1 + 0x291) = uVar9;
  }
  pfVar7 = pfVar5;
  if ((((param_9 & 0x2000000) != 0) &&
      (iVar1 = ((int (*)())_InterpreterTestCR)(param_1,iStack0000001c,iStack00000020,uStack00000024,
                                  (*(short *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)),(*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x2c)),uStack00000030,uStack00000034,
                                  param_9,param_10,1), iVar1 != 0)) &&
     (pfVar7 = (float *)((int)piVar6 + piVar8[1]), (char)param_13 != '\0')) {
    iVar1 = ___isnanf(iVar1);
    uVar9 = 3;
    if ((iVar1 == 0) && (uVar9 = 0.0 < param_12[1], param_12[1] < 0.0)) {
      uVar9 = 2;
    }
    *(undefined1 *)((int)param_1 + 0xa45) = uVar9;
  }
  pfVar3 = pfVar5;
  if ((((param_9 & 0x4000000) != 0) &&
      (iVar1 = ((int (*)())_InterpreterTestCR)(param_1,iStack0000001c,iStack00000020,uStack00000024,
                                  (*(short *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)),(*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x2c)),uStack00000030,uStack00000034,
                                  param_9,param_10,2), iVar1 != 0)) &&
     (pfVar3 = (float *)((int)piVar6 + piVar8[2]), (char)param_13 != '\0')) {
    iVar1 = ___isnanf(iVar1);
    uVar9 = 3;
    if ((iVar1 == 0) && (uVar9 = 0.0 < param_12[2], param_12[2] < 0.0)) {
      uVar9 = 2;
    }
    *(undefined1 *)((int)param_1 + 0xa46) = uVar9;
  }
  if ((((param_9 & 0x8000000) != 0) &&
      (iVar1 = ((int (*)())_InterpreterTestCR)(param_1,iStack0000001c,iStack00000020,uStack00000024,
                                  (*(short *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)),(*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x2c)),uStack00000030,uStack00000034,
                                  param_9,param_10,3), iVar1 != 0)) &&
     (pfVar5 = (float *)((int)piVar6 + piVar8[3]), (char)param_13 != '\0')) {
    iVar1 = ___isnanf(iVar1);
    uVar9 = 3;
    if ((iVar1 == 0) && (uVar9 = 0.0 < param_12[3], param_12[3] < 0.0)) {
      uVar9 = 2;
    }
    *(undefined1 *)((int)param_1 + 0xa47) = uVar9;
  }
  *pfVar4 = *param_12;
  *pfVar7 = param_12[1];
  *pfVar3 = param_12[2];
  *pfVar5 = param_12[3];
  return;
}

/* _InterpreterLoadSource @ 0x97bcd924 (796 bytes) */
int _InterpreterLoadSource(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11, param_12)
  int *param_1;
  int *param_2;
  int param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  uint param_8;
  undefined4 param_9;
  undefined4 param_10;
  int param_11;
  float *param_12;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  byte bStack00000024;
  byte bStack00000025;
  byte bStack00000026;
  short sStack00000028;
  ushort uStack0000002c;
  char cStack0000002e;
  char cStack0000002f;
  
  dVar5 = DOUBLE_97c30a58;
  iVar9 = *param_1;
  iVar6 = *(int *)(*(int *)(iVar9 + 0xd80) + 0x38);
  uStack0000002c = (ushort)((uint)param_6 >> 0x10);
  bStack00000026 = (byte)(param_4 >> 8);
  bStack00000025 = (byte)(param_4 >> 0x10);
  bStack00000024 = (byte)(param_4 >> 0x18);
  if (((iVar6 == 0x8804) || (iVar6 == 0x8b30)) && (uStack0000002c == 2)) {
    iVar6 = *(int *)(iVar9 + 0xda4);
    iVar9 = *(int *)(iVar9 + 0xda0);
    fVar1 = *(float *)(iVar6 + param_2[param_11 * 4 + (uint)bStack00000024]) * (float)param_1[0x28c]
            + *(float *)(iVar9 + param_2[param_11 * 4 + (uint)bStack00000024]);
    *param_12 = fVar1;
    fVar2 = *(float *)(iVar6 + param_2[param_11 * 4 + (uint)bStack00000025]) * (float)param_1[0x28c]
            + *(float *)(iVar9 + param_2[param_11 * 4 + (uint)bStack00000025]);
    param_12[1] = fVar2;
    fVar3 = *(float *)(iVar6 + param_2[param_11 * 4 + (uint)bStack00000026]) * (float)param_1[0x28c]
            + *(float *)(iVar9 + param_2[param_11 * 4 + (uint)bStack00000026]);
    param_12[2] = fVar3;
    fVar4 = *(float *)(iVar6 + param_2[param_11 * 4 + (param_4 & 0xff)]) * (float)param_1[0x28c] +
            *(float *)(iVar9 + param_2[param_11 * 4 + (param_4 & 0xff)]);
    param_12[3] = fVar4;
    if (*param_2 != 0) {
      *param_12 = fVar1 * (float)param_1[0x28f];
      param_12[1] = fVar2 * (float)param_1[0x28f];
      param_12[2] = fVar3 * (float)param_1[0x28f];
      param_12[3] = fVar4 * (float)param_1[0x28f];
    }
  }
  else {
    cStack0000002f = (char)param_6;
    if (cStack0000002f == '\0') {
      piVar7 = param_2 + param_11 * 4;
    }
    else {
      iVar8 = param_3 * 0xc + *(int *)(iVar9 + 0xd80);
      sStack00000028 = (short)((uint)param_5 >> 0x10);
      iVar6 = *(int *)(iVar8 + 0x80);
      piVar7 = (int *)(iVar6 + (((uint)((int)param_2 + (param_11 * 0x10 - iVar6)) >> 4) +
                                param_1[0x290] + (int)sStack00000028 & *(uint *)(iVar8 + 0x88)) *
                               0x10);
    }
    iVar6 = *(int *)((uint)uStack0000002c * 4 + iVar9 + 0xd84);
    if (param_8 < 2) {
      *param_12 = *(float *)(iVar6 + piVar7[bStack00000024]);
      param_12[1] = *(float *)(iVar6 + piVar7[bStack00000025]);
      param_12[2] = *(float *)(iVar6 + piVar7[bStack00000026]);
      fVar1 = *(float *)(iVar6 + piVar7[param_4 & 0xff]);
    }
    else {
      if (1 < param_8 - 3) goto LAB_97bcdbfc;
      *param_12 = (float)((double)CONCAT44(0x43300000,
                                           *(uint *)(iVar6 + piVar7[bStack00000024]) ^ 0x80000000) -
                         DOUBLE_97c30a58);
      param_12[1] = (float)((double)CONCAT44(0x43300000,
                                             *(uint *)(iVar6 + piVar7[bStack00000025]) ^ 0x80000000)
                           - dVar5);
      param_12[2] = (float)((double)CONCAT44(0x43300000,
                                             *(uint *)(iVar6 + piVar7[bStack00000026]) ^ 0x80000000)
                           - dVar5);
      fVar1 = (float)((double)CONCAT44(0x43300000,
                                       *(uint *)(iVar6 + piVar7[param_4 & 0xff]) ^ 0x80000000) -
                     dVar5);
    }
    param_12[3] = fVar1;
  }
LAB_97bcdbfc:
  cStack0000002e = (char)((uint)param_6 >> 8);
  if (cStack0000002e != '\0') {
    *param_12 = -*param_12;
    param_12[1] = -param_12[1];
    param_12[2] = -param_12[2];
    param_12[3] = -param_12[3];
  }
  return;
}

/* _InterpreterTestCR @ 0x97bcdc40 (240 bytes) */
int _InterpreterTestCR(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11)
  int param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
  uint param_9;
  undefined4 param_10;
  int param_11;
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  uVar2 = (uint)*(byte *)((uint)*(byte *)((int)&param_9 + param_11 + 2) + param_1 + 0xa44);
  switch(param_9 >> 0x10 & 0xff) {
  case 0:
    uVar1 = 1;
    break;
  case 1:
    uVar1 = (uint)(uVar2 == 0);
    break;
  case 2:
    uVar1 = (uint)(uVar2 < 2);
    break;
  case 3:
    uVar1 = (uint)(uVar2 == 1);
    break;
  case 4:
    uVar1 = 0;
    if ((uVar2 == 2) || (uVar2 == 0)) {
      uVar1 = 1;
    }
    break;
  case 5:
    uVar1 = (uint)(uVar2 == 2);
    break;
  case 6:
    uVar1 = -uVar2 >> 0x1f;
    break;
  case 7:
    uVar1 = 0;
  }
  return uVar1;
}

/* _InterpreterEmulateOp @ 0x97bcdd50 (20820 bytes) */
int * _InterpreterEmulateOp(int *param_1,int *param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  float *pfVar1;
  bool bVar2;
  float fVar3;
  char cVar4;
  byte bVar5;
  char cVar6;
  float fVar7;
  uint uVar8;
  byte *pbVar9;
  float *pfVar10;
  int *piVar11;
  float *in_r5;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int *piVar18;
  int iVar19;
  uint uVar20;
  int iVar21;
  int iVar22;
  float *pfVar23;
  uint uVar24;
  bool bVar25;
  int iVar26;
  double dVar27;
  double extraout_f1;
  double extraout_f1_00;
  double extraout_f1_01;
  double extraout_f1_02;
  double extraout_f1_03;
  double extraout_f1_04;
  double extraout_f1_05;
  double extraout_f1_06;
  double extraout_f1_07;
  double extraout_f1_08;
  double extraout_f1_09;
  double extraout_f1_10;
  double dVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double in_stack_fffffe78;
  double in_stack_fffffe80;
  double in_stack_fffffe88;
  double in_stack_fffffe90;
  double in_stack_fffffe98;
  undefined4 uVar32;
  float local_130 [12];
  float local_100 [4];
  float local_f0;
  float local_ec;
  float local_e8;
  float local_e4;
  float local_e0;
  float local_dc;
  float local_d8;
  float local_d4;
  float local_d0;
  float local_cc;
  float local_c8;
  float local_c4;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  undefined4 local_b0;
  uint uStack_ac;
  longlong local_a8;
  longlong local_a0;
  longlong local_98;
  longlong local_90;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  
  iVar19 = *param_1;
  piVar18 = param_2 + 0x47;
  if (param_2 == *(int **)(*(int *)(iVar19 + 0xd80) + 4)) {
    piVar18 = (int *)0x0;
  }
  iVar14 = param_2[0xc];
  local_130[3] = 0.0;
  uVar20 = 1;
  local_130[0] = 0.0;
  local_130[1] = 0.0;
  bVar25 = true;
  local_130[2] = 0.0;
  iVar21 = *param_2;
  cVar4 = *(char *)(param_2 + 1);
  if (iVar14 != 0) {
    pbVar9 = (byte *)((int)param_2 + 0x49);
    iVar26 = iVar14;
    do {
      if ((pbVar9[-1] != 0) && (uVar20 < *pbVar9)) {
        uVar20 = (uint)*pbVar9;
      }
      pbVar9 = pbVar9 + 0x24;
      iVar26 = iVar26 + -1;
    } while (iVar26 != 0);
  }
  if (iVar21 == 0x22) {
    cVar4 = *(char *)(param_2 + 0x12);
    if ((cVar4 == '\0') && (*(char *)(param_2 + 0x1b) == '\0')) {
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],0,local_130 + 4);
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                 param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],0,local_130 + 8);
      pfVar10 = local_130;
      local_130[0] = local_130[4] * local_130[8];
      local_130[1] = local_130[5] * local_130[9];
      local_130[2] = local_130[6] * local_130[10];
      iVar16 = param_2[9];
      local_130[3] = local_130[7] * local_130[0xb];
      uVar20 = (uint)*(byte *)((int)param_2 + 6);
      iVar19 = param_2[10];
      iVar22 = param_2[0xb];
      iVar14 = param_2[3];
      iVar21 = param_2[4];
      iVar26 = param_2[5];
      iVar12 = param_2[6];
      iVar13 = param_2[7];
      iVar15 = param_2[8];
      uVar32 = 0;
    }
    else if ((cVar4 == '\0') ||
            ((*(char *)(param_2 + 0x1b) == '\0' ||
             (*(char *)((int)param_2 + 0x49) != *(char *)((int)param_2 + 0x6d))))) {
      if ((cVar4 == '\0') || (*(byte *)((int)param_2 + 0x6d) < 2)) {
        if ((*(char *)(param_2 + 0x1b) == '\0') || (*(byte *)((int)param_2 + 0x49) < 2)) {
          uVar17 = (uint)(cVar4 == '\0');
          if (uVar17 == 0) {
            iVar19 = 0x54;
          }
          else {
            iVar19 = 0x30;
          }
          pfVar10 = local_130 + 8;
          ((int (*)())_InterpreterLoadSource)(param_1,*(undefined4 *)((int)param_2 + iVar19 + 4),
                     *(undefined4 *)((int)param_2 + iVar19 + 8),
                     *(undefined4 *)((int)param_2 + iVar19 + 0xc),
                     *(undefined4 *)((int)param_2 + iVar19 + 0x10),
                     *(undefined4 *)((int)param_2 + iVar19 + 0x14),
                     *(undefined4 *)((int)param_2 + iVar19 + 0x18),
                     *(undefined4 *)((int)param_2 + iVar19 + 0x1c),
                     *(undefined4 *)((int)param_2 + iVar19 + 0x20),
                     *(undefined4 *)((int)param_2 + iVar19 + 0x24),0,local_130 + 4);
          ((int (*)())_InterpreterLoadSource)(param_1,param_2[uVar17 * 9 + 0xd],param_2[uVar17 * 9 + 0xe],
                     param_2[uVar17 * 9 + 0xf],param_2[uVar17 * 9 + 0x10],param_2[uVar17 * 9 + 0x11]
                     ,param_2[uVar17 * 9 + 0x12],param_2[uVar17 * 9 + 0x13],
                     param_2[uVar17 * 9 + 0x14],param_2[uVar17 * 9 + 0x15],0,pfVar10);
          if (uVar20 == 2) {
            uVar32 = 1;
            local_130[0] = local_130[4] * local_130[8];
            local_130[1] = local_130[4] * local_130[9];
            ((int (*)())_InterpreterWriteDestination)(param_1,param_2[3],param_2[4],param_2[5],param_2[6],param_2[7],param_2[8],
                       param_2[9],param_2[10],param_2[0xb],0,local_130,
                       (uint)*(byte *)((int)param_2 + 6));
            ((int (*)())_InterpreterLoadSource)(param_1,param_2[uVar17 * 9 + 0xd],param_2[uVar17 * 9 + 0xe],
                       param_2[uVar17 * 9 + 0xf],param_2[uVar17 * 9 + 0x10],
                       param_2[uVar17 * 9 + 0x11],param_2[uVar17 * 9 + 0x12],
                       param_2[uVar17 * 9 + 0x13],param_2[uVar17 * 9 + 0x14],
                       param_2[uVar17 * 9 + 0x15],1,pfVar10);
            local_130[0] = local_130[4] * local_130[8];
            iVar16 = param_2[9];
            local_130[1] = local_130[4] * local_130[9];
            bVar5 = *(byte *)((int)param_2 + 6);
            iVar19 = param_2[10];
            iVar22 = param_2[0xb];
            iVar14 = param_2[3];
            iVar21 = param_2[4];
            iVar26 = param_2[5];
            iVar12 = param_2[6];
            iVar13 = param_2[7];
            iVar15 = param_2[8];
          }
          else if (uVar20 == 3) {
            local_130[0] = local_130[4] * local_130[8];
            local_130[2] = local_130[4] * local_130[10];
            local_130[1] = local_130[4] * local_130[9];
            ((int (*)())_InterpreterWriteDestination)(param_1,param_2[3],param_2[4],param_2[5],param_2[6],param_2[7],param_2[8],
                       param_2[9],param_2[10],param_2[0xb],0,local_130,
                       (uint)*(byte *)((int)param_2 + 6));
            ((int (*)())_InterpreterLoadSource)(param_1,param_2[uVar17 * 9 + 0xd],param_2[uVar17 * 9 + 0xe],
                       param_2[uVar17 * 9 + 0xf],param_2[uVar17 * 9 + 0x10],
                       param_2[uVar17 * 9 + 0x11],param_2[uVar17 * 9 + 0x12],
                       param_2[uVar17 * 9 + 0x13],param_2[uVar17 * 9 + 0x14],
                       param_2[uVar17 * 9 + 0x15],1,pfVar10);
            local_130[0] = local_130[4] * local_130[8];
            local_130[2] = local_130[4] * local_130[10];
            local_130[1] = local_130[4] * local_130[9];
            ((int (*)())_InterpreterWriteDestination)(param_1,param_2[3],param_2[4],param_2[5],param_2[6],param_2[7],param_2[8],
                       param_2[9],param_2[10],param_2[0xb],1,local_130,
                       (uint)*(byte *)((int)param_2 + 6));
            ((int (*)())_InterpreterLoadSource)(param_1,param_2[uVar17 * 9 + 0xd],param_2[uVar17 * 9 + 0xe],
                       param_2[uVar17 * 9 + 0xf],param_2[uVar17 * 9 + 0x10],
                       param_2[uVar17 * 9 + 0x11],param_2[uVar17 * 9 + 0x12],
                       param_2[uVar17 * 9 + 0x13],param_2[uVar17 * 9 + 0x14],
                       param_2[uVar17 * 9 + 0x15],2,pfVar10);
            local_130[0] = local_130[4] * local_130[8];
            local_130[2] = local_130[4] * local_130[10];
            iVar16 = param_2[9];
            local_130[1] = local_130[4] * local_130[9];
            bVar5 = *(byte *)((int)param_2 + 6);
            iVar19 = param_2[10];
            iVar22 = param_2[0xb];
            iVar14 = param_2[3];
            iVar21 = param_2[4];
            iVar26 = param_2[5];
            iVar12 = param_2[6];
            iVar13 = param_2[7];
            iVar15 = param_2[8];
            uVar32 = 2;
          }
          else {
            if (uVar20 != 4) {
              return piVar18;
            }
            local_130[0] = local_130[4] * local_130[8];
            local_130[3] = local_130[4] * local_130[0xb];
            local_130[1] = local_130[4] * local_130[9];
            local_130[2] = local_130[4] * local_130[10];
            ((int (*)())_InterpreterWriteDestination)(param_1,param_2[3],param_2[4],param_2[5],param_2[6],param_2[7],param_2[8],
                       param_2[9],param_2[10],param_2[0xb],0,local_130,
                       (uint)*(byte *)((int)param_2 + 6));
            ((int (*)())_InterpreterLoadSource)(param_1,param_2[uVar17 * 9 + 0xd],param_2[uVar17 * 9 + 0xe],
                       param_2[uVar17 * 9 + 0xf],param_2[uVar17 * 9 + 0x10],
                       param_2[uVar17 * 9 + 0x11],param_2[uVar17 * 9 + 0x12],
                       param_2[uVar17 * 9 + 0x13],param_2[uVar17 * 9 + 0x14],
                       param_2[uVar17 * 9 + 0x15],1,pfVar10);
            local_130[0] = local_130[4] * local_130[8];
            local_130[3] = local_130[4] * local_130[0xb];
            local_130[1] = local_130[4] * local_130[9];
            local_130[2] = local_130[4] * local_130[10];
            uVar32 = 3;
            ((int (*)())_InterpreterWriteDestination)(param_1,param_2[3],param_2[4],param_2[5],param_2[6],param_2[7],param_2[8],
                       param_2[9],param_2[10],param_2[0xb],1,local_130,
                       (uint)*(byte *)((int)param_2 + 6));
            ((int (*)())_InterpreterLoadSource)(param_1,param_2[uVar17 * 9 + 0xd],param_2[uVar17 * 9 + 0xe],
                       param_2[uVar17 * 9 + 0xf],param_2[uVar17 * 9 + 0x10],
                       param_2[uVar17 * 9 + 0x11],param_2[uVar17 * 9 + 0x12],
                       param_2[uVar17 * 9 + 0x13],param_2[uVar17 * 9 + 0x14],
                       param_2[uVar17 * 9 + 0x15],2,pfVar10);
            local_130[0] = local_130[4] * local_130[8];
            local_130[3] = local_130[4] * local_130[0xb];
            local_130[1] = local_130[4] * local_130[9];
            local_130[2] = local_130[4] * local_130[10];
            ((int (*)())_InterpreterWriteDestination)(param_1,param_2[3],param_2[4],param_2[5],param_2[6],param_2[7],param_2[8],
                       param_2[9],param_2[10],param_2[0xb],2,local_130,
                       (uint)*(byte *)((int)param_2 + 6));
            ((int (*)())_InterpreterLoadSource)(param_1,param_2[uVar17 * 9 + 0xd],param_2[uVar17 * 9 + 0xe],
                       param_2[uVar17 * 9 + 0xf],param_2[uVar17 * 9 + 0x10],
                       param_2[uVar17 * 9 + 0x11],param_2[uVar17 * 9 + 0x12],
                       param_2[uVar17 * 9 + 0x13],param_2[uVar17 * 9 + 0x14],
                       param_2[uVar17 * 9 + 0x15],3,pfVar10);
            local_130[0] = local_130[4] * local_130[8];
            local_130[3] = local_130[4] * local_130[0xb];
            local_130[1] = local_130[4] * local_130[9];
            iVar16 = param_2[9];
            local_130[2] = local_130[4] * local_130[10];
            bVar5 = *(byte *)((int)param_2 + 6);
            iVar19 = param_2[10];
            iVar22 = param_2[0xb];
            iVar14 = param_2[3];
            iVar21 = param_2[4];
            iVar26 = param_2[5];
            iVar12 = param_2[6];
            iVar13 = param_2[7];
            iVar15 = param_2[8];
          }
          pfVar10 = local_130;
          uVar20 = (uint)bVar5;
          goto LAB_97bd043c;
        }
        pfVar10 = local_130 + 8;
        ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                   param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],0,local_130 + 4);
        ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                   param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],0,pfVar10);
        if (uVar20 == 2) {
          local_130[0] = local_130[4] * local_130[8] + local_130[5] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                     param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],1,pfVar10);
          local_130[1] = local_130[4] * local_130[8] + local_130[5] * local_130[9];
        }
        else if (uVar20 == 3) {
          local_130[0] = local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                     param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],1,pfVar10);
          local_130[1] = local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                     param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],2,pfVar10);
          local_130[2] = local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
        }
        else if (uVar20 == 4) {
          local_130[0] = local_130[7] * local_130[0xb] +
                         local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                     param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],1,pfVar10);
          local_130[1] = local_130[7] * local_130[0xb] +
                         local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                     param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],2,pfVar10);
          local_130[2] = local_130[7] * local_130[0xb] +
                         local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                     param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],3,pfVar10);
          local_130[3] = local_130[7] * local_130[0xb] +
                         local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
        }
      }
      else {
        pfVar10 = local_130 + 8;
        ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                   param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],0,pfVar10);
        ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                   param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],0,local_130 + 4);
        if (uVar20 == 2) {
          local_130[0] = local_130[4] * local_130[8];
          local_130[1] = local_130[4] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                     param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],1,pfVar10);
          local_130[0] = local_130[5] * local_130[8] + local_130[0];
          local_130[1] = local_130[5] * local_130[9] + local_130[1];
        }
        else if (uVar20 == 3) {
          local_130[0] = local_130[4] * local_130[8];
          local_130[2] = local_130[4] * local_130[10];
          local_130[1] = local_130[4] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                     param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],1,pfVar10);
          local_130[0] = local_130[5] * local_130[8] + local_130[0];
          local_130[2] = local_130[5] * local_130[10] + local_130[2];
          local_130[1] = local_130[5] * local_130[9] + local_130[1];
          ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                     param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],2,pfVar10);
          local_130[0] = local_130[6] * local_130[8] + local_130[0];
          local_130[2] = local_130[6] * local_130[10] + local_130[2];
          local_130[1] = local_130[6] * local_130[9] + local_130[1];
        }
        else if (uVar20 == 4) {
          local_130[0] = local_130[4] * local_130[8];
          local_130[3] = local_130[4] * local_130[0xb];
          local_130[1] = local_130[4] * local_130[9];
          local_130[2] = local_130[4] * local_130[10];
          ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                     param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],1,pfVar10);
          local_130[0] = local_130[5] * local_130[8] + local_130[0];
          local_130[3] = local_130[5] * local_130[0xb] + local_130[3];
          local_130[1] = local_130[5] * local_130[9] + local_130[1];
          local_130[2] = local_130[5] * local_130[10] + local_130[2];
          ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                     param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],2,pfVar10);
          local_130[0] = local_130[6] * local_130[8] + local_130[0];
          local_130[3] = local_130[6] * local_130[0xb] + local_130[3];
          local_130[1] = local_130[6] * local_130[9] + local_130[1];
          local_130[2] = local_130[6] * local_130[10] + local_130[2];
          ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                     param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],3,pfVar10);
          local_130[0] = local_130[7] * local_130[8] + local_130[0];
          local_130[3] = local_130[7] * local_130[0xb] + local_130[3];
          local_130[1] = local_130[7] * local_130[9] + local_130[1];
          local_130[2] = local_130[7] * local_130[10] + local_130[2];
        }
      }
      uVar20 = (uint)*(byte *)((int)param_2 + 6);
      iVar19 = param_2[10];
      pfVar10 = local_130;
      iVar22 = param_2[0xb];
      iVar16 = param_2[9];
      iVar14 = param_2[3];
      iVar21 = param_2[4];
      iVar26 = param_2[5];
      iVar12 = param_2[6];
      iVar13 = param_2[7];
      iVar15 = param_2[8];
      uVar32 = 0;
    }
    else if (uVar20 == 2) {
      pfVar10 = local_130 + 4;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],0,pfVar10);
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                 param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],0,local_130 + 8);
      local_f0 = local_130[4] * local_130[8];
      local_ec = local_130[5] * local_130[8];
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],1,pfVar10);
      local_f0 = local_130[4] * local_130[9] + local_f0;
      local_ec = local_130[5] * local_130[9] + local_ec;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                 param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],1,local_130 + 8);
      local_e0 = local_130[4] * local_130[9];
      local_dc = local_130[5] * local_130[9];
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],0,pfVar10);
      local_e0 = local_130[4] * local_130[8] + local_e0;
      local_dc = local_130[5] * local_130[8] + local_dc;
      ((int (*)())_InterpreterWriteDestination)(param_1,param_2[3],param_2[4],param_2[5],param_2[6],param_2[7],param_2[8],
                 param_2[9],param_2[10],param_2[0xb],0,&local_f0,(uint)*(byte *)((int)param_2 + 6));
      iVar16 = param_2[9];
      uVar20 = (uint)*(byte *)((int)param_2 + 6);
      pfVar10 = &local_e0;
      iVar19 = param_2[10];
      iVar22 = param_2[0xb];
      iVar14 = param_2[3];
      iVar21 = param_2[4];
      iVar26 = param_2[5];
      iVar12 = param_2[6];
      iVar13 = param_2[7];
      iVar15 = param_2[8];
      uVar32 = 1;
    }
    else if (uVar20 == 3) {
      pfVar23 = local_130 + 4;
      pfVar10 = local_130 + 8;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],0,pfVar23);
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                 param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],0,pfVar10);
      local_f0 = local_130[4] * local_130[8];
      local_e8 = local_130[6] * local_130[8];
      local_ec = local_130[5] * local_130[8];
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],1,pfVar23);
      local_f0 = local_130[4] * local_130[9] + local_f0;
      local_e8 = local_130[6] * local_130[9] + local_e8;
      local_ec = local_130[5] * local_130[9] + local_ec;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],2,pfVar23);
      local_f0 = local_130[4] * local_130[10] + local_f0;
      local_e8 = local_130[6] * local_130[10] + local_e8;
      local_ec = local_130[5] * local_130[10] + local_ec;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                 param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],1,pfVar10);
      local_e0 = local_130[4] * local_130[10];
      local_d8 = local_130[6] * local_130[10];
      local_dc = local_130[5] * local_130[10];
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],1,pfVar23);
      local_e0 = local_130[4] * local_130[9] + local_e0;
      local_d8 = local_130[6] * local_130[9] + local_d8;
      local_dc = local_130[5] * local_130[9] + local_dc;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],0,pfVar23);
      local_e0 = local_130[4] * local_130[8] + local_e0;
      local_d8 = local_130[6] * local_130[8] + local_d8;
      local_dc = local_130[5] * local_130[8] + local_dc;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                 param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],2,pfVar10);
      local_d0 = local_130[4] * local_130[8];
      local_c8 = local_130[6] * local_130[8];
      local_cc = local_130[5] * local_130[8];
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],1,pfVar23);
      local_d0 = local_130[4] * local_130[9] + local_d0;
      local_c8 = local_130[6] * local_130[9] + local_c8;
      local_cc = local_130[5] * local_130[9] + local_cc;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],2,pfVar23);
      local_d0 = local_130[4] * local_130[10] + local_d0;
      local_c8 = local_130[6] * local_130[10] + local_c8;
      local_cc = local_130[5] * local_130[10] + local_cc;
      ((int (*)())_InterpreterWriteDestination)(param_1,param_2[3],param_2[4],param_2[5],param_2[6],param_2[7],param_2[8],
                 param_2[9],param_2[10],param_2[0xb],0,&local_f0,(uint)*(byte *)((int)param_2 + 6));
      ((int (*)())_InterpreterWriteDestination)(param_1,param_2[3],param_2[4],param_2[5],param_2[6],param_2[7],param_2[8],
                 param_2[9],param_2[10],param_2[0xb],1,&local_e0,(uint)*(byte *)((int)param_2 + 6));
      iVar16 = param_2[9];
      uVar20 = (uint)*(byte *)((int)param_2 + 6);
      pfVar10 = &local_d0;
      iVar19 = param_2[10];
      iVar22 = param_2[0xb];
      iVar14 = param_2[3];
      iVar21 = param_2[4];
      iVar26 = param_2[5];
      iVar12 = param_2[6];
      iVar13 = param_2[7];
      iVar15 = param_2[8];
      uVar32 = 2;
    }
    else {
      if (uVar20 != 4) {
        return piVar18;
      }
      pfVar23 = local_130 + 4;
      pfVar10 = local_130 + 8;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],0,pfVar23);
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                 param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],0,pfVar10);
      local_f0 = local_130[4] * local_130[8];
      local_e4 = local_130[7] * local_130[8];
      local_ec = local_130[5] * local_130[8];
      local_e8 = local_130[6] * local_130[8];
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],1,pfVar23);
      local_f0 = local_130[4] * local_130[9] + local_f0;
      local_e4 = local_130[7] * local_130[9] + local_e4;
      local_ec = local_130[5] * local_130[9] + local_ec;
      local_e8 = local_130[6] * local_130[9] + local_e8;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],2,pfVar23);
      local_f0 = local_130[4] * local_130[10] + local_f0;
      local_e4 = local_130[7] * local_130[10] + local_e4;
      local_ec = local_130[5] * local_130[10] + local_ec;
      local_e8 = local_130[6] * local_130[10] + local_e8;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],3,pfVar23);
      local_f0 = local_130[4] * local_130[0xb] + local_f0;
      local_e4 = local_130[7] * local_130[0xb] + local_e4;
      local_ec = local_130[5] * local_130[0xb] + local_ec;
      local_e8 = local_130[6] * local_130[0xb] + local_e8;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                 param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],1,pfVar10);
      local_e0 = local_130[4] * local_130[0xb];
      local_d4 = local_130[7] * local_130[0xb];
      local_dc = local_130[5] * local_130[0xb];
      local_d8 = local_130[6] * local_130[0xb];
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],2,pfVar23);
      local_e0 = local_130[4] * local_130[10] + local_e0;
      local_d4 = local_130[7] * local_130[10] + local_d4;
      local_dc = local_130[5] * local_130[10] + local_dc;
      local_d8 = local_130[6] * local_130[10] + local_d8;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],1,pfVar23);
      local_e0 = local_130[4] * local_130[9] + local_e0;
      local_d4 = local_130[7] * local_130[9] + local_d4;
      local_dc = local_130[5] * local_130[9] + local_dc;
      local_d8 = local_130[6] * local_130[9] + local_d8;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],0,pfVar23);
      local_e0 = local_130[4] * local_130[8] + local_e0;
      local_d4 = local_130[7] * local_130[8] + local_d4;
      local_dc = local_130[5] * local_130[8] + local_dc;
      local_d8 = local_130[6] * local_130[8] + local_d8;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                 param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],2,pfVar10);
      local_d0 = local_130[4] * local_130[8];
      local_c4 = local_130[7] * local_130[8];
      local_cc = local_130[5] * local_130[8];
      local_c8 = local_130[6] * local_130[8];
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],1,pfVar23);
      local_d0 = local_130[4] * local_130[9] + local_d0;
      local_c4 = local_130[7] * local_130[9] + local_c4;
      local_cc = local_130[5] * local_130[9] + local_cc;
      local_c8 = local_130[6] * local_130[9] + local_c8;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],2,pfVar23);
      local_d0 = local_130[4] * local_130[10] + local_d0;
      local_c4 = local_130[7] * local_130[10] + local_c4;
      local_cc = local_130[5] * local_130[10] + local_cc;
      local_c8 = local_130[6] * local_130[10] + local_c8;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],3,pfVar23);
      local_d0 = local_130[4] * local_130[0xb] + local_d0;
      local_c4 = local_130[7] * local_130[0xb] + local_c4;
      local_cc = local_130[5] * local_130[0xb] + local_cc;
      local_c8 = local_130[6] * local_130[0xb] + local_c8;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                 param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],3,pfVar10);
      local_c0 = local_130[4] * local_130[0xb];
      local_b4 = local_130[7] * local_130[0xb];
      local_bc = local_130[5] * local_130[0xb];
      local_b8 = local_130[6] * local_130[0xb];
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],2,pfVar23);
      local_c0 = local_130[4] * local_130[10] + local_c0;
      local_b4 = local_130[7] * local_130[10] + local_b4;
      local_bc = local_130[5] * local_130[10] + local_bc;
      local_b8 = local_130[6] * local_130[10] + local_b8;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],1,pfVar23);
      local_c0 = local_130[4] * local_130[9] + local_c0;
      local_b4 = local_130[7] * local_130[9] + local_b4;
      local_bc = local_130[5] * local_130[9] + local_bc;
      local_b8 = local_130[6] * local_130[9] + local_b8;
      ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                 param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],0,pfVar23);
      local_c0 = local_130[4] * local_130[8] + local_c0;
      local_b4 = local_130[7] * local_130[8] + local_b4;
      local_bc = local_130[5] * local_130[8] + local_bc;
      local_b8 = local_130[6] * local_130[8] + local_b8;
      ((int (*)())_InterpreterWriteDestination)(param_1,param_2[3],param_2[4],param_2[5],param_2[6],param_2[7],param_2[8],
                 param_2[9],param_2[10],param_2[0xb],0,&local_f0,(uint)*(byte *)((int)param_2 + 6));
      ((int (*)())_InterpreterWriteDestination)(param_1,param_2[3],param_2[4],param_2[5],param_2[6],param_2[7],param_2[8],
                 param_2[9],param_2[10],param_2[0xb],1,&local_e0,(uint)*(byte *)((int)param_2 + 6));
      ((int (*)())_InterpreterWriteDestination)(param_1,param_2[3],param_2[4],param_2[5],param_2[6],param_2[7],param_2[8],
                 param_2[9],param_2[10],param_2[0xb],2,&local_d0,(uint)*(byte *)((int)param_2 + 6));
      iVar16 = param_2[9];
      uVar20 = (uint)*(byte *)((int)param_2 + 6);
      pfVar10 = &local_c0;
      iVar19 = param_2[10];
      iVar22 = param_2[0xb];
      iVar14 = param_2[3];
      iVar21 = param_2[4];
      iVar26 = param_2[5];
      iVar12 = param_2[6];
      iVar13 = param_2[7];
      iVar15 = param_2[8];
      uVar32 = 3;
    }
    goto LAB_97bd043c;
  }
  if ((iVar21 != 0x31) && (iVar21 != 0x36)) {
    uVar17 = 0;
    if (uVar20 == 0) {
      return piVar18;
    }
    do {
      if (iVar14 != 0) {
        uVar24 = uVar17;
        if (*(char *)(param_2 + 0x12) == '\0') {
          uVar24 = 0;
        }
        in_r5 = (float *)param_2[0xe];
        fparam_1 = (double)((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],in_r5,param_2[0xf],param_2[0x10],
                                      param_2[0x11],param_2[0x12],param_2[0x13],param_2[0x14],
                                      param_2[0x15],uVar24,local_130 + 4);
        if (1 < (uint)param_2[0xc]) {
          uVar24 = uVar17;
          if (*(char *)(param_2 + 0x1b) == '\0') {
            uVar24 = 0;
          }
          in_r5 = (float *)param_2[0x17];
          fparam_1 = (double)((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],in_r5,param_2[0x18],param_2[0x19],
                                        param_2[0x1a],param_2[0x1b],param_2[0x1c],param_2[0x1d],
                                        param_2[0x1e],uVar24,local_130 + 8);
          if (2 < (uint)param_2[0xc]) {
            uVar24 = uVar17;
            if (*(char *)(param_2 + 0x24) == '\0') {
              uVar24 = 0;
            }
            in_r5 = (float *)param_2[0x20];
            fparam_1 = (double)((int (*)())_InterpreterLoadSource)(param_1,param_2[0x1f],in_r5,param_2[0x21],param_2[0x22],
                                          param_2[0x23],param_2[0x24],param_2[0x25],param_2[0x26],
                                          param_2[0x27],uVar24,local_100);
          }
        }
      }
      fVar3 = TAllocation__guardBlockSize;
      dVar27 = DOUBLE_97c30a60;
      fVar7 = local_130[7];
      switch(iVar21) {
      case 0:
switchD_97bd0598_caseD_0:
        local_130[0] = local_130[4];
        local_130[1] = local_130[5];
        local_130[2] = local_130[6];
        local_130[3] = local_130[7];
        break;
      case 1:
        local_130[0] = 1.0;
        if (local_130[4] <= TAllocation__guardBlockSize) {
          local_130[1] = 0.0;
          local_130[2] = TAllocation__guardBlockSize;
        }
        else {
          local_70 = local_130[4];
          fparam_2 = (double)local_130[7];
          local_130[1] = local_130[4];
          dVar27 = _pow((double)local_130[5],fparam_2);
          local_130[2] = (float)dVar27;
        }
        fparam_1 = (double)local_130[2];
        goto LAB_97bd1cd8;
      case 2:
        local_130[0] = ABS(local_130[4]);
        local_130[1] = ABS(local_130[5]);
        local_130[2] = ABS(local_130[6]);
        local_130[3] = ABS(local_130[7]);
        break;
      case 3:
        dVar27 = _ceil((double)local_130[4]);
        local_130[0] = (float)dVar27;
        dVar27 = _ceil((double)local_130[5]);
        local_130[1] = (float)dVar27;
        dVar27 = _ceil((double)local_130[6]);
        local_130[2] = (float)dVar27;
        dVar27 = _ceil((double)local_130[7]);
        goto LAB_97bd2010;
      case 4:
        dVar29 = (double)local_130[4];
        dVar27 = _floor(dVar29);
        dVar28 = (double)local_130[5];
        local_130[0] = (float)(dVar29 - dVar27);
        dVar27 = _floor(dVar28);
        dVar29 = (double)local_130[6];
        local_130[1] = (float)(dVar28 - dVar27);
        dVar28 = _floor(dVar29);
        dVar27 = (double)local_130[7];
        local_130[2] = (float)(dVar29 - dVar28);
        fparam_1 = _floor(dVar27);
        dVar27 = dVar27 - fparam_1;
        goto LAB_97bd1440;
      case 5:
        dVar27 = _floor((double)local_130[4]);
        local_130[0] = (float)dVar27;
        dVar27 = _floor((double)local_130[5]);
        local_130[1] = (float)dVar27;
        dVar27 = _floor((double)local_130[6]);
        local_130[2] = (float)dVar27;
        dVar27 = _floor((double)local_130[7]);
        goto LAB_97bd2010;
      default:
        goto switchD_97bd0598_caseD_6;
      case 7:
        if (local_130[4] <= TAllocation__guardBlockSize) {
          if (TAllocation__guardBlockSize <= local_130[4]) {
            local_130[0] = 0.0;
          }
          else {
            local_130[0] = -1.0;
          }
        }
        else {
          local_130[0] = 1.0;
        }
        if (local_130[5] <= TAllocation__guardBlockSize) {
          if (TAllocation__guardBlockSize <= local_130[5]) {
            local_130[1] = 0.0;
          }
          else {
            local_130[1] = -1.0;
          }
        }
        else {
          local_130[1] = 1.0;
        }
        if (local_130[6] <= TAllocation__guardBlockSize) {
          if (TAllocation__guardBlockSize <= local_130[6]) {
            local_130[2] = 0.0;
          }
          else {
            local_130[2] = -1.0;
          }
        }
        else {
          local_130[2] = 1.0;
        }
        if (TAllocation__guardBlockSize < local_130[7]) goto LAB_97bd1cd8;
        if (TAllocation__guardBlockSize <= local_130[7]) goto LAB_97bd1ce0;
        local_130[3] = -1.0;
        break;
      case 8:
        if (((local_130[4] == TAllocation__guardBlockSize) &&
            (local_130[5] == TAllocation__guardBlockSize)) &&
           (local_130[6] == TAllocation__guardBlockSize)) {
LAB_97bd0ab8:
          uVar24 = 0;
          if (local_130[7] == TAllocation__guardBlockSize) goto LAB_97bd0ac8;
        }
        uVar24 = 1;
        goto LAB_97bd0ac8;
      case 9:
        uVar24 = 0;
        if (((local_130[4] != TAllocation__guardBlockSize) &&
            (local_130[5] != TAllocation__guardBlockSize)) &&
           (local_130[6] != TAllocation__guardBlockSize)) goto LAB_97bd0ab8;
LAB_97bd0ac8:
        uStack_ac = uVar24 ^ 0x80000000;
        local_b0 = 0x43300000;
        dVar27 = (double)CONCAT44(0x43300000,uVar24 ^ 0x80000000) - DOUBLE_97c30a58;
LAB_97bd0cc8:
        local_130[0] = (float)dVar27;
        local_130[1] = local_130[0];
        local_130[2] = local_130[0];
        local_130[3] = local_130[0];
        break;
      case 10:
        local_130[0] = 1.0;
        if (local_130[4] != TAllocation__guardBlockSize) {
          local_130[0] = 0.0;
        }
        local_130[1] = 1.0;
        if (local_130[5] != TAllocation__guardBlockSize) {
          local_130[1] = 0.0;
        }
        local_130[2] = 1.0;
        if (local_130[6] != TAllocation__guardBlockSize) {
          local_130[2] = 0.0;
        }
        local_130[3] = 1.0;
        if (local_130[7] != TAllocation__guardBlockSize) goto LAB_97bd1ce0;
        break;
      case 0xb:
        bVar5 = *(byte *)((int)param_2 + 5);
        if (bVar5 == 2) {
          in_r5 = local_130;
          fparam_1 = (double)_InterpreterNoiseGeneratorCalculate2D(param_1 + 1,local_130 + 4,in_r5);
        }
        else if (bVar5 < 3) {
          if (bVar5 == 1) {
            in_r5 = local_130;
            fparam_1 = (double)_InterpreterNoiseGeneratorCalculate1D
                                         (param_1 + 1,local_130 + 4,in_r5);
          }
        }
        else if (bVar5 == 3) {
          in_r5 = local_130;
          fparam_1 = (double)_InterpreterNoiseGeneratorCalculate3D(param_1 + 1,local_130 + 4,in_r5);
        }
        else if (bVar5 == 4) {
          in_r5 = local_130;
          fparam_1 = (double)_InterpreterNoiseGeneratorCalculate4D
                                       (fparam_1,param_1 + 1,local_130 + 4);
        }
        break;
      case 0xc:
        dVar27 = _sqrt(ABS((double)local_130[4]));
        local_130[0] = (float)dVar27;
        dVar27 = _sqrt(ABS((double)local_130[5]));
        local_130[1] = (float)dVar27;
        dVar27 = _sqrt(ABS((double)local_130[6]));
        local_130[2] = (float)dVar27;
        dVar27 = _sqrt(ABS((double)local_130[7]));
        goto LAB_97bd2010;
      case 0xd:
        if (*(int *)(*(int *)(iVar19 + 0xd80) + 0x38) - 0x8b30U < 2) {
          dVar28 = _sqrt(ABS((double)local_130[4]));
          local_130[0] = (float)(dVar27 / dVar28);
          dVar28 = _sqrt(ABS((double)local_130[5]));
          local_130[1] = (float)(dVar27 / dVar28);
          dVar28 = _sqrt(ABS((double)local_130[6]));
          local_130[2] = (float)(dVar27 / dVar28);
          fparam_1 = _sqrt(ABS((double)local_130[7]));
          dVar27 = dVar27 / fparam_1;
          goto LAB_97bd1440;
        }
        fparam_1 = _sqrt(ABS((double)local_130[7]));
        dVar27 = DOUBLE_97c30a60 / fparam_1;
        goto LAB_97bd0cc8;
      case 0xe:
        local_130[0] = FLOAT_97c3acd8 / local_130[7];
        local_130[1] = local_130[0];
        local_130[2] = local_130[0];
        local_130[3] = local_130[0];
        break;
      case 0xf:
        local_130[0] = FLOAT_97c3ace0;
        local_130[1] = FLOAT_97c3ace0;
        local_130[2] = FLOAT_97c3ace0;
        local_130[3] = FLOAT_97c3ace0;
        if ((local_130[7] <= FLOAT_97c3acdc) &&
           ((FLOAT_97c3ace0 <= local_130[7] ||
            (((local_130[0] = FLOAT_97c3acdc, local_130[1] = FLOAT_97c3acdc,
              local_130[2] = FLOAT_97c3acdc, local_130[3] = FLOAT_97c3acdc,
              local_130[7] < TAllocation__guardBlockSize &&
              (local_130[0] = FLOAT_97c3ace8, local_130[1] = FLOAT_97c3ace8,
              local_130[2] = FLOAT_97c3ace8, local_130[3] = FLOAT_97c3ace8,
              local_130[7] <= FLOAT_97c3ace4)) &&
             (local_130[0] = FLOAT_97c3ace4, local_130[1] = FLOAT_97c3ace4,
             local_130[2] = FLOAT_97c3ace4, local_130[3] = FLOAT_97c3ace4,
             FLOAT_97c3ace8 <= local_130[7])))))) {
          local_130[0] = FLOAT_97c3acd8 / local_130[7];
          local_130[1] = local_130[0];
          local_130[2] = local_130[0];
          local_130[3] = local_130[0];
        }
        break;
      case 0x10:
        if (1 < *(int *)(*(int *)(iVar19 + 0xd80) + 0x38) - 0x8b30U) {
          fparam_1 = _exp2((double)local_130[7]);
          goto LAB_97bd1d68;
        }
        dVar27 = _exp2((double)local_130[4]);
        local_130[0] = (float)dVar27;
        dVar27 = _exp2((double)local_130[5]);
        local_130[1] = (float)dVar27;
        dVar27 = _exp2((double)local_130[6]);
        local_130[2] = (float)dVar27;
        dVar27 = _exp2((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x11:
        dVar27 = _floor((double)local_130[7]);
        dVar28 = _exp2((double)(float)dVar27);
        local_130[0] = (float)dVar28;
        local_130[1] = (float)((double)local_130[7] - (double)(float)dVar27);
        dVar27 = _exp2((double)local_130[7]);
        goto LAB_97bd0fd4;
      case 0x12:
        uVar24 = (uint)*(byte *)((int)param_2 + 5);
        dVar27 = (double)TAllocation__guardBlockSize;
        if (uVar24 != 0) {
          pfVar10 = local_130 + 4;
          do {
            fVar3 = *pfVar10;
            pfVar10 = pfVar10 + 1;
            dVar27 = (double)(float)((double)fVar3 * (double)fVar3 + dVar27);
            uVar24 = uVar24 - 1;
          } while (uVar24 != 0);
        }
LAB_97bd1924:
        fparam_1 = _sqrt(dVar27);
LAB_97bd1d68:
        local_130[0] = (float)fparam_1;
        local_130[1] = local_130[0];
        local_130[2] = local_130[0];
        local_130[3] = local_130[0];
        break;
      case 0x13:
        if (1 < *(int *)(*(int *)(iVar19 + 0xd80) + 0x38) - 0x8b30U) {
          dVar27 = (double)local_130[7];
          if ((double)local_130[7] < (double)TAllocation__guardBlockSize) {
            dVar27 = DOUBLE_97c30a48;
          }
          fparam_1 = _log2(dVar27);
          goto LAB_97bd1d68;
        }
        dVar27 = (double)local_130[4];
        if ((double)local_130[4] < (double)TAllocation__guardBlockSize) {
          dVar27 = DOUBLE_97c30a48;
        }
        dVar28 = _log2(dVar27);
        dVar27 = (double)local_130[5];
        local_130[0] = (float)dVar28;
        if (dVar27 < (double)TAllocation__guardBlockSize) {
          dVar27 = DOUBLE_97c30a48;
        }
        dVar28 = _log2(dVar27);
        dVar27 = (double)local_130[6];
        local_130[1] = (float)dVar28;
        if (dVar27 < (double)TAllocation__guardBlockSize) {
          dVar27 = DOUBLE_97c30a48;
        }
        dVar28 = _log2(dVar27);
        dVar27 = (double)local_130[7];
        local_130[2] = (float)dVar28;
        if (dVar27 < (double)TAllocation__guardBlockSize) {
          dVar27 = DOUBLE_97c30a48;
        }
        dVar27 = _log2(dVar27);
        goto LAB_97bd2010;
      case 0x14:
        dVar27 = ABS((double)local_130[7]);
        dVar28 = _log2(dVar27);
        dVar28 = _floor(dVar28);
        local_130[0] = (float)dVar28;
        dVar28 = _exp2((double)local_130[0]);
        local_130[1] = (float)(dVar27 / dVar28);
        if (dVar27 < (double)TAllocation__guardBlockSize) {
          dVar27 = DOUBLE_97c30a48;
        }
        dVar27 = _log2(dVar27);
LAB_97bd0fd4:
        local_130[2] = (float)dVar27;
        fparam_1 = (double)local_130[2];
        local_130[3] = 1.0;
        break;
      case 0x15:
        uVar24 = (uint)*(byte *)((int)param_2 + 5);
        dVar27 = (double)TAllocation__guardBlockSize;
        if (uVar24 != 0) {
          pfVar10 = local_130 + 4;
          do {
            fVar3 = *pfVar10;
            pfVar10 = pfVar10 + 1;
            dVar27 = (double)(float)((double)fVar3 * (double)fVar3 + dVar27);
            uVar24 = uVar24 - 1;
          } while (uVar24 != 0);
        }
        fparam_1 = _sqrt(dVar27);
        uVar24 = (uint)*(byte *)((int)param_2 + 5);
        if (uVar24 != 0) {
          pfVar10 = local_130;
          do {
            *pfVar10 = pfVar10[4] / (float)fparam_1;
            pfVar10 = pfVar10 + 1;
            uVar24 = uVar24 - 1;
          } while (uVar24 != 0);
        }
        break;
      case 0x16:
        fVar3 = FLOAT_97c3acd0;
        goto LAB_97bd109c;
      case 0x17:
        fVar3 = FLOAT_97c3acd4;
LAB_97bd109c:
        local_130[0] = local_130[4] * fVar3;
        local_130[1] = local_130[5] * fVar3;
        local_130[2] = local_130[6] * fVar3;
        local_130[3] = local_130[7] * fVar3;
        break;
      case 0x18:
        dVar27 = _cos((double)local_130[4]);
        local_130[0] = (float)dVar27;
        dVar27 = _sin((double)local_130[4]);
        local_130[1] = (float)dVar27;
        fparam_1 = (double)local_130[1];
        local_130[3] = 0.0;
        local_130[2] = 0.0;
        break;
      case 0x19:
        if (1 < *(int *)(*(int *)(iVar19 + 0xd80) + 0x38) - 0x8b30U) {
          fparam_1 = _sin((double)local_130[7]);
          goto LAB_97bd1d68;
        }
        dVar27 = _sin((double)local_130[4]);
        local_130[0] = (float)dVar27;
        dVar27 = _sin((double)local_130[5]);
        local_130[1] = (float)dVar27;
        dVar27 = _sin((double)local_130[6]);
        local_130[2] = (float)dVar27;
        dVar27 = _sin((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x1a:
        if (1 < *(int *)(*(int *)(iVar19 + 0xd80) + 0x38) - 0x8b30U) {
          fparam_1 = _cos((double)local_130[7]);
          goto LAB_97bd1d68;
        }
        dVar27 = _cos((double)local_130[4]);
        local_130[0] = (float)dVar27;
        dVar27 = _cos((double)local_130[5]);
        local_130[1] = (float)dVar27;
        dVar27 = _cos((double)local_130[6]);
        local_130[2] = (float)dVar27;
        dVar27 = _cos((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x1b:
        dVar27 = _tan((double)local_130[4]);
        local_130[0] = (float)dVar27;
        dVar27 = _tan((double)local_130[5]);
        local_130[1] = (float)dVar27;
        dVar27 = _tan((double)local_130[6]);
        local_130[2] = (float)dVar27;
        dVar27 = _tan((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x1c:
        dVar27 = _asin((double)local_130[4]);
        local_130[0] = (float)dVar27;
        dVar27 = _asin((double)local_130[5]);
        local_130[1] = (float)dVar27;
        dVar27 = _asin((double)local_130[6]);
        local_130[2] = (float)dVar27;
        dVar27 = _asin((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x1d:
        dVar27 = _acos((double)local_130[4]);
        local_130[0] = (float)dVar27;
        dVar27 = _acos((double)local_130[5]);
        local_130[1] = (float)dVar27;
        dVar27 = _acos((double)local_130[6]);
        local_130[2] = (float)dVar27;
        dVar27 = _acos((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x1e:
        if (param_2[0xc] == 1) {
          dVar27 = _atan((double)local_130[4]);
          local_130[0] = (float)dVar27;
          dVar27 = _atan((double)local_130[5]);
          local_130[1] = (float)dVar27;
          dVar27 = _atan((double)local_130[6]);
          local_130[2] = (float)dVar27;
          dVar27 = _atan((double)local_130[7]);
          goto LAB_97bd2010;
        }
        local_130[0] = _atan2f(local_130[4],local_130[8]);
        local_130[1] = _atan2f(local_130[5],local_130[9]);
        local_130[2] = _atan2f(local_130[6],local_130[10]);
        fparam_2 = (double)local_130[0xb];
        local_130[3] = _atan2f(local_130[7],local_130[0xb]);
        goto LAB_97bd2014;
      case 0x1f:
        local_130[0] = local_130[4] + local_130[8];
        local_130[1] = local_130[5] + local_130[9];
        local_130[2] = local_130[6] + local_130[10];
        local_130[3] = local_130[7] + local_130[0xb];
        break;
      case 0x20:
        local_130[0] = local_130[4] - local_130[8];
        local_130[1] = local_130[5] - local_130[9];
        local_130[2] = local_130[6] - local_130[10];
        local_130[3] = local_130[7] - local_130[0xb];
        break;
      case 0x21:
        if (*(char *)((int)param_2 + 0x6d) == '\x01') {
          dVar27 = (double)local_130[4];
          dVar31 = (double)local_130[8];
          dVar28 = _floor((double)(float)(dVar27 / dVar31));
          dVar29 = (double)local_130[5];
          dVar30 = (double)local_130[8];
          local_130[0] = (float)-(dVar31 * dVar28 - dVar27);
          dVar27 = _floor((double)(float)(dVar29 / dVar30));
          dVar28 = (double)local_130[6];
          dVar31 = (double)local_130[8];
          local_130[1] = (float)-(dVar30 * dVar27 - dVar29);
          dVar27 = _floor((double)(float)(dVar28 / dVar31));
          fVar3 = local_130[8];
        }
        else {
          dVar27 = (double)local_130[4];
          dVar31 = (double)local_130[8];
          dVar28 = _floor((double)(float)(dVar27 / dVar31));
          dVar29 = (double)local_130[5];
          dVar30 = (double)local_130[9];
          local_130[0] = (float)-(dVar31 * dVar28 - dVar27);
          dVar27 = _floor((double)(float)(dVar29 / dVar30));
          dVar28 = (double)local_130[6];
          dVar31 = (double)local_130[10];
          local_130[1] = (float)-(dVar30 * dVar27 - dVar29);
          dVar27 = _floor((double)(float)(dVar28 / dVar31));
          fVar3 = local_130[0xb];
        }
        dVar29 = (double)local_130[7];
        local_130[2] = (float)-(dVar31 * dVar27 - dVar28);
        fparam_1 = _floor((double)(float)(dVar29 / (double)fVar3));
        dVar27 = -((double)fVar3 * fparam_1 - dVar29);
LAB_97bd1440:
        local_130[3] = (float)dVar27;
        break;
      case 0x22:
      case 0x31:
      case 0x36:
        break;
      case 0x23:
        local_130[0] = local_130[4] * local_130[8];
        local_130[1] = local_130[5] * local_130[9];
        local_130[2] = local_130[6] * local_130[10];
        local_130[3] = local_130[7] * local_130[0xb];
        break;
      case 0x24:
        uVar24 = 0;
        if ((local_130[4] != TAllocation__guardBlockSize) &&
           (local_130[8] != TAllocation__guardBlockSize)) {
          uVar24 = 1;
        }
        uVar8 = 0;
        local_130[0] = (float)((double)CONCAT44(0x43300000,uVar24 ^ 0x80000000) - DOUBLE_97c30a58);
        if ((local_130[5] != TAllocation__guardBlockSize) &&
           (local_130[9] != TAllocation__guardBlockSize)) {
          uVar8 = 1;
        }
        uVar24 = 0;
        local_130[1] = (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - DOUBLE_97c30a58);
        if ((local_130[6] != TAllocation__guardBlockSize) &&
           (local_130[10] != TAllocation__guardBlockSize)) {
          uVar24 = 1;
        }
        uVar8 = 0;
        local_130[2] = (float)((double)CONCAT44(0x43300000,uVar24 ^ 0x80000000) - DOUBLE_97c30a58);
        if (local_130[7] != TAllocation__guardBlockSize) {
LAB_97bd17d0:
          uVar8 = 0;
          if (local_130[0xb] != TAllocation__guardBlockSize) goto LAB_97bd17ec;
        }
        goto LAB_97bd17f0;
      case 0x25:
        uVar24 = 0;
        if ((local_130[4] != TAllocation__guardBlockSize) ||
           (local_130[8] != TAllocation__guardBlockSize)) {
          uVar24 = 1;
        }
        uVar8 = 0;
        local_130[0] = (float)((double)CONCAT44(0x43300000,uVar24 ^ 0x80000000) - DOUBLE_97c30a58);
        if ((local_130[5] != TAllocation__guardBlockSize) ||
           (local_130[9] != TAllocation__guardBlockSize)) {
          uVar8 = 1;
        }
        uVar24 = 0;
        local_130[1] = (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - DOUBLE_97c30a58);
        if ((local_130[6] != TAllocation__guardBlockSize) ||
           (local_130[10] != TAllocation__guardBlockSize)) {
          uVar24 = 1;
        }
        local_130[2] = (float)((double)CONCAT44(0x43300000,uVar24 ^ 0x80000000) - DOUBLE_97c30a58);
        if (local_130[7] == TAllocation__guardBlockSize) goto LAB_97bd17d0;
LAB_97bd17ec:
        uVar8 = 1;
        goto LAB_97bd17f0;
      case 0x26:
        uVar24 = 0;
        if (local_130[4] == TAllocation__guardBlockSize) {
          if (local_130[8] != TAllocation__guardBlockSize) {
LAB_97bd16cc:
            uVar24 = 1;
          }
        }
        else if (local_130[8] == TAllocation__guardBlockSize) goto LAB_97bd16cc;
        uVar8 = 0;
        local_130[0] = (float)((double)CONCAT44(0x43300000,uVar24 ^ 0x80000000) - DOUBLE_97c30a58);
        if (local_130[5] == TAllocation__guardBlockSize) {
          if (local_130[9] != TAllocation__guardBlockSize) {
LAB_97bd172c:
            uVar8 = 1;
          }
        }
        else if (local_130[9] == TAllocation__guardBlockSize) goto LAB_97bd172c;
        uVar24 = 0;
        local_130[1] = (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - DOUBLE_97c30a58);
        if (local_130[6] == TAllocation__guardBlockSize) {
          if (local_130[10] != TAllocation__guardBlockSize) {
LAB_97bd178c:
            uVar24 = 1;
          }
        }
        else if (local_130[10] == TAllocation__guardBlockSize) goto LAB_97bd178c;
        uVar8 = 0;
        local_130[2] = (float)((double)CONCAT44(0x43300000,uVar24 ^ 0x80000000) - DOUBLE_97c30a58);
        if (local_130[7] == TAllocation__guardBlockSize) goto LAB_97bd17d0;
        if (local_130[0xb] == TAllocation__guardBlockSize) goto LAB_97bd17ec;
LAB_97bd17f0:
        uStack_ac = uVar8 ^ 0x80000000;
        local_b0 = 0x43300000;
        local_130[3] = (float)((double)CONCAT44(0x43300000,uVar8 ^ 0x80000000) - DOUBLE_97c30a58);
        break;
      case 0x27:
        uVar24 = (uint)*(byte *)((int)param_2 + 5);
        local_130[0] = TAllocation__guardBlockSize;
        local_130[1] = TAllocation__guardBlockSize;
        local_130[2] = TAllocation__guardBlockSize;
        local_130[3] = TAllocation__guardBlockSize;
        if (uVar24 != 0) {
          pfVar10 = local_130;
          do {
            pfVar23 = pfVar10 + 4;
            pfVar1 = pfVar10 + 8;
            pfVar10 = pfVar10 + 1;
            local_130[0] = *pfVar23 * *pfVar1 + local_130[0];
            uVar24 = uVar24 - 1;
            local_130[1] = local_130[0];
            local_130[2] = local_130[0];
            local_130[3] = local_130[0];
          } while (uVar24 != 0);
        }
        break;
      case 0x28:
        local_130[0] = local_130[6] * local_130[10] +
                       local_130[4] * local_130[8] + local_130[5] * local_130[9];
        local_130[1] = local_130[0];
        local_130[2] = local_130[0];
        local_130[3] = local_130[0];
        break;
      case 0x29:
        local_130[0] = local_130[7] * local_130[0xb] +
                       local_130[6] * local_130[10] +
                       local_130[4] * local_130[8] + local_130[5] * local_130[9];
        local_130[1] = local_130[0];
        local_130[2] = local_130[0];
        local_130[3] = local_130[0];
        break;
      case 0x2a:
        local_130[0] = local_130[6] * local_130[10] +
                       local_130[4] * local_130[8] + local_130[5] * local_130[9] + local_130[0xb];
        local_130[1] = local_130[0];
        local_130[2] = local_130[0];
        local_130[3] = local_130[0];
        break;
      case 0x2b:
        if (*(int *)(*(int *)(iVar19 + 0xd80) + 0x38) - 0x8b30U < 2) {
          uVar24 = (uint)*(byte *)((int)param_2 + 5);
          dVar27 = (double)TAllocation__guardBlockSize;
          if (uVar24 != 0) {
            pfVar10 = local_130;
            do {
              pfVar23 = pfVar10 + 4;
              pfVar1 = pfVar10 + 8;
              pfVar10 = pfVar10 + 1;
              dVar27 = (double)(float)((double)(*pfVar23 - *pfVar1) * (double)(*pfVar23 - *pfVar1) +
                                      dVar27);
              uVar24 = uVar24 - 1;
            } while (uVar24 != 0);
          }
          goto LAB_97bd1924;
        }
        local_130[0] = 1.0;
        local_130[1] = local_130[5] * local_130[9];
        local_130[2] = local_130[6];
        local_130[3] = local_130[0xb];
        break;
      case 0x2c:
        local_130[0] = local_130[8];
        if (local_130[4] < local_130[8]) {
          local_130[0] = local_130[4];
        }
        local_130[1] = local_130[9];
        if (local_130[5] < local_130[9]) {
          local_130[1] = local_130[5];
        }
        local_130[2] = local_130[10];
        if (local_130[6] < local_130[10]) {
          local_130[2] = local_130[6];
        }
        local_130[3] = local_130[0xb];
        if (local_130[7] < local_130[0xb]) {
LAB_97bd2210:
          local_130[3] = fVar7;
        }
        break;
      case 0x2d:
        local_130[0] = local_130[8];
        if (local_130[8] < local_130[4]) {
          local_130[0] = local_130[4];
        }
        local_130[1] = local_130[9];
        if (local_130[9] < local_130[5]) {
          local_130[1] = local_130[5];
        }
        local_130[2] = local_130[10];
        if (local_130[10] < local_130[6]) {
          local_130[2] = local_130[6];
        }
        local_130[3] = local_130[0xb];
        if (local_130[0xb] < local_130[7]) goto LAB_97bd2210;
        break;
      case 0x2e:
        fparam_6 = (double)local_130[10];
        fparam_7 = (double)local_130[9];
        fparam_8 = (double)local_130[8];
        local_130[0] = (float)((double)local_130[5] * fparam_6 -
                              (double)(float)(fparam_7 * (double)local_130[6]));
        local_130[2] = (float)((double)local_130[4] * fparam_7 -
                              (double)(float)(fparam_8 * (double)local_130[5]));
        local_130[1] = (float)((double)local_130[6] * fparam_8 -
                              (double)(float)(fparam_6 * (double)local_130[4]));
        goto LAB_97bd1ce0;
      case 0x2f:
        uVar24 = (uint)*(byte *)((int)param_2 + 5);
        if (uVar24 != 0) {
          pfVar10 = local_130;
          do {
            pfVar23 = pfVar10 + 4;
            pfVar1 = pfVar10 + 8;
            pfVar10 = pfVar10 + 1;
            fVar3 = *pfVar23 * *pfVar1 + fVar3;
            uVar24 = uVar24 - 1;
          } while (uVar24 != 0);
        }
        fVar3 = fVar3 + fVar3;
        local_130[0] = -(fVar3 * local_130[8] - local_130[4]);
        local_130[1] = -(fVar3 * local_130[9] - local_130[5]);
        local_130[2] = -(fVar3 * local_130[10] - local_130[6]);
        local_130[3] = -(fVar3 * local_130[0xb] - local_130[7]);
        break;
      case 0x30:
        local_130[0] = FLOAT_97c3acd8;
        local_130[1] = FLOAT_97c3acd8;
        local_130[2] = FLOAT_97c3acd8;
        local_130[3] = FLOAT_97c3acd8;
        break;
      case 0x32:
        local_130[0] = 1.0;
        if (local_130[4] < local_130[8]) {
          local_130[0] = 0.0;
        }
        local_130[1] = 1.0;
        if (local_130[5] < local_130[9]) {
          local_130[1] = 0.0;
        }
        local_130[2] = 1.0;
        if (local_130[6] < local_130[10]) {
          local_130[2] = 0.0;
        }
        bVar2 = local_130[0xb] <= local_130[7];
        goto LAB_97bd1c60;
      case 0x33:
        if (local_130[4] <= local_130[8]) {
          local_130[0] = 0.0;
        }
        else {
          local_130[0] = 1.0;
        }
        if (local_130[5] <= local_130[9]) {
          local_130[1] = 0.0;
        }
        else {
          local_130[1] = 1.0;
        }
        if (local_130[6] <= local_130[10]) {
          local_130[2] = 0.0;
        }
        else {
          local_130[2] = 1.0;
        }
        if (local_130[7] <= local_130[0xb]) goto LAB_97bd1ce0;
        goto LAB_97bd1cd8;
      case 0x34:
        local_130[0] = 1.0;
        if (local_130[8] < local_130[4]) {
          local_130[0] = 0.0;
        }
        local_130[1] = 1.0;
        if (local_130[9] < local_130[5]) {
          local_130[1] = 0.0;
        }
        local_130[2] = 1.0;
        if (local_130[10] < local_130[6]) {
          local_130[2] = 0.0;
        }
        bVar2 = local_130[7] <= local_130[0xb];
LAB_97bd1c60:
        local_130[3] = 1.0;
        if (!bVar2) {
LAB_97bd1ce0:
          local_130[3] = 0.0;
        }
        break;
      case 0x35:
        if (local_130[8] <= local_130[4]) {
          local_130[0] = 0.0;
        }
        else {
          local_130[0] = 1.0;
        }
        if (local_130[9] <= local_130[5]) {
          local_130[1] = 0.0;
        }
        else {
          local_130[1] = 1.0;
        }
        if (local_130[10] <= local_130[6]) {
          local_130[2] = 0.0;
        }
        else {
          local_130[2] = 1.0;
        }
        if (local_130[0xb] <= local_130[7]) goto LAB_97bd1ce0;
LAB_97bd1cd8:
        local_130[3] = 1.0;
        break;
      case 0x37:
        local_130[0] = TAllocation__guardBlockSize;
        local_130[1] = TAllocation__guardBlockSize;
        local_130[2] = TAllocation__guardBlockSize;
        local_130[3] = TAllocation__guardBlockSize;
        break;
      case 0x38:
        if (1 < *(int *)(*(int *)(iVar19 + 0xd80) + 0x38) - 0x8b30U) {
          fparam_2 = (double)local_130[0xb];
          fparam_1 = _pow((double)local_130[7],fparam_2);
          goto LAB_97bd1d68;
        }
        dVar27 = _pow((double)local_130[4],(double)local_130[8]);
        local_130[0] = (float)dVar27;
        dVar27 = _pow((double)local_130[5],(double)local_130[9]);
        local_130[1] = (float)dVar27;
        dVar27 = _pow((double)local_130[6],(double)local_130[10]);
        fparam_2 = (double)local_130[0xb];
        local_130[2] = (float)dVar27;
        dVar27 = _pow((double)local_130[7],fparam_2);
        goto LAB_97bd2010;
      case 0x39:
        dVar27 = (double)local_130[8];
        if (DOUBLE_97c30a78 <= dVar27) {
          iVar14 = (int)(dVar27 - DOUBLE_97c30a78);
          local_a0 = (longlong)iVar14;
        }
        else {
          iVar14 = (int)local_130[8];
          local_a8 = (longlong)iVar14;
        }
        local_130[0] = local_130[iVar14 + 4];
        if (DOUBLE_97c30a78 <= dVar27) {
          iVar14 = (int)(dVar27 - DOUBLE_97c30a78);
          local_a8 = (longlong)iVar14;
        }
        else {
          iVar14 = (int)local_130[8];
          local_a0 = (longlong)iVar14;
        }
        local_130[1] = local_130[iVar14 + 4];
        if (DOUBLE_97c30a78 <= dVar27) {
          iVar14 = (int)(dVar27 - DOUBLE_97c30a78);
          local_a8 = (longlong)iVar14;
        }
        else {
          iVar14 = (int)local_130[8];
          local_a0 = (longlong)iVar14;
        }
        local_130[2] = local_130[iVar14 + 4];
        if (DOUBLE_97c30a78 <= dVar27) {
          iVar14 = (int)(dVar27 - DOUBLE_97c30a78);
          local_a8 = (longlong)iVar14;
        }
        else {
          iVar14 = (int)local_130[8];
          local_a0 = (longlong)iVar14;
        }
        local_130[3] = local_130[iVar14 + 4];
        break;
      case 0x3a:
        if (param_2[9] == 1) {
          local_130[0] = local_130[4] / local_130[8];
          local_130[1] = local_130[5] / local_130[9];
          local_130[2] = local_130[6] / local_130[10];
          local_130[3] = local_130[7] / local_130[0xb];
        }
        else if (param_2[9] == 3) {
          dVar27 = _trunc((double)(local_130[4] / local_130[8]));
          local_130[0] = (float)dVar27;
          dVar27 = _trunc((double)(local_130[5] / local_130[9]));
          local_130[1] = (float)dVar27;
          dVar27 = _trunc((double)(local_130[6] / local_130[10]));
          fVar3 = local_130[7] / local_130[0xb];
          goto LAB_97bd200c;
        }
        break;
      case 0x3b:
        uVar24 = (uint)*(byte *)((int)param_2 + 5);
        if (uVar24 != 0) {
          pfVar10 = local_130;
          do {
            pfVar23 = pfVar10 + 0xc;
            pfVar1 = pfVar10 + 8;
            pfVar10 = pfVar10 + 1;
            fVar3 = *pfVar23 * *pfVar1 + fVar3;
            uVar24 = uVar24 - 1;
          } while (uVar24 != 0);
        }
        if (fVar3 < TAllocation__guardBlockSize) goto switchD_97bd0598_caseD_0;
        local_130[0] = -local_130[4];
        local_130[1] = -local_130[5];
        local_130[2] = -local_130[6];
        local_130[3] = -local_130[7];
        break;
      case 0x3c:
        dVar27 = (double)FLOAT_97c3acd8;
        fparam_5 = (double)((float)(dVar27 - (double)local_130[7]) * local_100[3]);
        local_130[0] = (float)((double)local_130[4] * (double)local_130[8] +
                              (double)((float)(dVar27 - (double)local_130[4]) * local_100[0]));
        local_130[1] = (float)((double)local_130[5] * (double)local_130[9] +
                              (double)((float)(dVar27 - (double)local_130[5]) * local_100[1]));
        fparam_8 = (double)local_130[1];
        local_130[2] = (float)((double)local_130[6] * (double)local_130[10] +
                              (double)((float)(dVar27 - (double)local_130[6]) * local_100[2]));
        fparam_7 = (double)local_130[2];
        local_130[3] = (float)((double)local_130[7] * (double)local_130[0xb] + fparam_5);
        fparam_6 = (double)local_130[3];
        break;
      case 0x3d:
        fVar3 = local_130[8];
        if (local_130[8] < local_130[4]) {
          fVar3 = local_130[4];
        }
        local_130[0] = local_100[0];
        if ((fVar3 < local_100[0]) && (local_130[0] = local_130[8], local_130[8] < local_130[4])) {
          local_130[0] = local_130[4];
        }
        fVar3 = local_130[9];
        if (local_130[9] < local_130[5]) {
          fVar3 = local_130[5];
        }
        local_130[1] = local_100[1];
        if ((fVar3 < local_100[1]) && (local_130[1] = local_130[9], local_130[9] < local_130[5])) {
          local_130[1] = local_130[5];
        }
        fVar3 = local_130[10];
        if (local_130[10] < local_130[6]) {
          fVar3 = local_130[6];
        }
        local_130[2] = local_100[2];
        if ((fVar3 < local_100[2]) && (local_130[2] = local_130[10], local_130[10] < local_130[6]))
        {
          local_130[2] = local_130[6];
        }
        fVar3 = local_130[0xb];
        if (local_130[0xb] < local_130[7]) {
          fVar3 = local_130[7];
        }
        local_130[3] = local_100[3];
        if ((fVar3 < local_100[3]) &&
           (fVar7 = local_130[0xb], local_130[3] = local_130[7], local_130[7] <= local_130[0xb]))
        goto LAB_97bd2210;
        break;
      case 0x3e:
        local_130[0] = local_100[0];
        if ((double)local_130[4] < DOUBLE_97c30a48) {
          local_130[0] = local_130[8];
        }
        local_130[1] = local_100[1];
        if ((double)local_130[5] < DOUBLE_97c30a48) {
          local_130[1] = local_130[9];
        }
        local_130[2] = local_100[2];
        if ((double)local_130[6] < DOUBLE_97c30a48) {
          local_130[2] = local_130[10];
        }
        local_130[3] = local_100[3];
        if ((double)local_130[7] < DOUBLE_97c30a48) {
          local_130[3] = local_130[0xb];
        }
        break;
      case 0x3f:
        local_130[0] = local_130[4] * local_130[8] + local_100[0];
        local_130[1] = local_130[5] * local_130[9] + local_100[1];
        local_130[2] = local_130[6] * local_130[10] + local_100[2];
        local_130[3] = local_130[7] * local_130[0xb] + local_100[3];
        break;
      case 0x40:
        dVar27 = (double)((local_100[0] - local_130[4]) / (local_130[8] - local_130[4]));
        if ((dVar27 <= DOUBLE_97c30a48) || (dVar27 < DOUBLE_97c30a60)) {
          if (dVar27 <= DOUBLE_97c30a48) {
            dVar27 = (double)TAllocation__guardBlockSize;
          }
        }
        else {
          dVar27 = (double)FLOAT_97c3acd8;
        }
        dVar28 = (double)((local_100[1] - local_130[5]) / (local_130[9] - local_130[5]));
        local_130[0] = (float)((double)(float)(dVar27 * dVar27) *
                              (DOUBLE_97c30a80 - (dVar27 + dVar27)));
        if ((dVar28 <= DOUBLE_97c30a48) || (dVar28 < DOUBLE_97c30a60)) {
          if (dVar28 <= DOUBLE_97c30a48) {
            dVar28 = (double)TAllocation__guardBlockSize;
          }
        }
        else {
          dVar28 = (double)FLOAT_97c3acd8;
        }
        dVar27 = (double)((local_100[2] - local_130[6]) / (local_130[10] - local_130[6]));
        local_130[1] = (float)((double)(float)(dVar28 * dVar28) *
                              (DOUBLE_97c30a80 - (dVar28 + dVar28)));
        if ((dVar27 <= DOUBLE_97c30a48) || (dVar27 < DOUBLE_97c30a60)) {
          if (dVar27 <= DOUBLE_97c30a48) {
            dVar27 = (double)TAllocation__guardBlockSize;
          }
        }
        else {
          dVar27 = (double)FLOAT_97c3acd8;
        }
        dVar28 = (double)((local_100[3] - local_130[7]) / (local_130[0xb] - local_130[7]));
        local_130[2] = (float)((double)(float)(dVar27 * dVar27) *
                              (DOUBLE_97c30a80 - (dVar27 + dVar27)));
        if ((dVar28 <= DOUBLE_97c30a48) || (dVar28 < DOUBLE_97c30a60)) {
          if (dVar28 <= DOUBLE_97c30a48) {
            dVar28 = (double)TAllocation__guardBlockSize;
          }
        }
        else {
          dVar28 = (double)FLOAT_97c3acd8;
        }
        local_130[3] = (float)((double)(float)(dVar28 * dVar28) *
                              (DOUBLE_97c30a80 - (dVar28 + dVar28)));
        break;
      case 0x41:
        cVar6 = *(char *)(param_2 + 0x18);
        local_130[0] = local_130[4];
        if ((((cVar6 != '\0') && (local_130[0] = local_130[5], cVar6 != '\x01')) &&
            (local_130[0] = local_130[6], cVar6 != '\x02')) &&
           (local_130[0] = local_130[7], cVar6 != '\x03')) {
          fVar3 = local_130[4];
          if (((cVar6 == '\x04') || (fVar3 = local_130[5], cVar6 == '\x05')) ||
             ((fVar3 = local_130[6], cVar6 == '\x06' || (fVar3 = local_130[7], cVar6 == '\a')))) {
            local_130[0] = -fVar3;
          }
          else {
            local_130[0] = TAllocation__guardBlockSize;
            if (((cVar6 != '\t') && (local_130[0] = FLOAT_97c3acd8, cVar6 != '\b')) &&
               (local_130[0] = FLOAT_97c3acec, cVar6 != '\n')) {
              local_130[0] = TAllocation__guardBlockSize;
            }
          }
        }
        cVar6 = *(char *)((int)param_2 + 0x61);
        local_130[1] = local_130[4];
        if ((((cVar6 != '\0') && (local_130[1] = local_130[5], cVar6 != '\x01')) &&
            (local_130[1] = local_130[6], cVar6 != '\x02')) &&
           (local_130[1] = local_130[7], cVar6 != '\x03')) {
          fVar3 = local_130[4];
          if (((cVar6 == '\x04') || (fVar3 = local_130[5], cVar6 == '\x05')) ||
             ((fVar3 = local_130[6], cVar6 == '\x06' || (fVar3 = local_130[7], cVar6 == '\a')))) {
            local_130[1] = -fVar3;
          }
          else {
            local_130[1] = TAllocation__guardBlockSize;
            if (((cVar6 != '\t') && (local_130[1] = FLOAT_97c3acd8, cVar6 != '\b')) &&
               (local_130[1] = FLOAT_97c3acec, cVar6 != '\n')) {
              local_130[1] = TAllocation__guardBlockSize;
            }
          }
        }
        cVar6 = *(char *)((int)param_2 + 0x62);
        local_130[2] = local_130[4];
        if ((((cVar6 != '\0') && (local_130[2] = local_130[5], cVar6 != '\x01')) &&
            (local_130[2] = local_130[6], cVar6 != '\x02')) &&
           (local_130[2] = local_130[7], cVar6 != '\x03')) {
          fVar3 = local_130[4];
          if (((cVar6 == '\x04') || (fVar3 = local_130[5], cVar6 == '\x05')) ||
             ((fVar3 = local_130[6], cVar6 == '\x06' || (fVar3 = local_130[7], cVar6 == '\a')))) {
            local_130[2] = -fVar3;
          }
          else {
            local_130[2] = TAllocation__guardBlockSize;
            if (((cVar6 != '\t') && (local_130[2] = FLOAT_97c3acd8, cVar6 != '\b')) &&
               (local_130[2] = FLOAT_97c3acec, cVar6 != '\n')) {
              local_130[2] = TAllocation__guardBlockSize;
            }
          }
        }
        cVar6 = *(char *)((int)param_2 + 99);
        local_130[3] = local_130[4];
        if ((((cVar6 != '\0') && (local_130[3] = local_130[5], cVar6 != '\x01')) &&
            (local_130[3] = local_130[6], cVar6 != '\x02')) &&
           (local_130[3] = local_130[7], cVar6 != '\x03')) {
          fVar3 = local_130[4];
          if (((cVar6 == '\x04') || (fVar3 = local_130[5], cVar6 == '\x05')) ||
             ((fVar3 = local_130[6], cVar6 == '\x06' || (fVar3 = local_130[7], cVar6 == '\a')))) {
            local_130[3] = -fVar3;
          }
          else {
            local_130[3] = TAllocation__guardBlockSize;
            if (((cVar6 != '\t') && (local_130[3] = FLOAT_97c3acd8, cVar6 != '\b')) &&
               (local_130[3] = FLOAT_97c3acec, cVar6 != '\n')) {
              local_130[3] = TAllocation__guardBlockSize;
            }
          }
        }
        break;
      case 0x42:
      case 0x43:
      case 0x44:
      case 0x45:
        ((int (*)())_InterpreterTextureSamplerAttachGLDContext)(param_1[0x28b],*(undefined4 *)(iVar19 + 0xd9c));
        uVar32 = 0;
        if ((iVar21 == 0x43) || (iVar21 == 0x45)) {
          uVar32 = 1;
        }
        ((int (*)())_InterpreterTextureSamplerSetProjectionEnabled)(param_1[0x28b],uVar32);
        ((int (*)())_InterpreterTextureSamplerSetLodBiasEnabled)(param_1[0x28b],(uint)(iVar21 == 0x44 || iVar21 - 0x44U == 1));
        fparam_1 = (double)((double (*)())_InterpreterTextureSamplerAttachDerivatives)(param_1[0x28b],*(undefined4 *)(iVar19 + 0xda4),
                                      (double)(float)param_1[0x28f]);
        fVar7 = local_130[7];
        if (iVar21 - 0x44U < 2) {
          iVar14 = *(int *)(iVar19 + 0xd80);
          fVar3 = local_100[0];
          if (1 < *(int *)(iVar14 + 0x38) - 0x8b30U) {
            local_130[7] = 1.0;
            fVar3 = fVar7;
            goto LAB_97bd29a8;
          }
        }
        else {
LAB_97bd29a8:
          iVar14 = *(int *)(iVar19 + 0xd80);
        }
        dVar27 = (double)fVar3;
        if (*(int *)(iVar14 + 0x38) - 0x8b30U < 2) {
          if (DOUBLE_97c30a78 <= (double)local_130[8]) {
            uVar24 = (uint)((double)local_130[8] - DOUBLE_97c30a78);
            local_98 = (longlong)(int)uVar24;
            uVar24 = uVar24 ^ 0x80000000;
          }
          else {
            uVar24 = (uint)local_130[8];
            local_90 = (longlong)(int)uVar24;
          }
        }
        else {
          uVar24 = param_2[0x43];
        }
        uVar8 = param_2[0x44];
        if (uVar8 == 2) {
          fparam_1 = (double)_InterpreterTextureSamplerSampleTexelRECT(dVar27,param_1[0x28b]);
        }
        else if (uVar8 < 3) {
          if (uVar8 == 1) {
            fparam_1 = (double)((double (*)())_InterpreterTextureSamplerSampleTexel3D)(param_1[0x28b],uVar24,in_r5,local_130 + 4,&local_80,dVar27
                                          ,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                                          fparam_8,in_stack_fffffe78,in_stack_fffffe80,
                                          in_stack_fffffe88,in_stack_fffffe90);
          }
        }
        else if (uVar8 == 3) {
          fparam_1 = (double)((double (*)())_InterpreterTextureSamplerSampleTexel2D)(param_1[0x28b],uVar24,in_r5,local_130 + 4,&local_80,dVar27,
                                        fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                                        fparam_8,in_stack_fffffe78,in_stack_fffffe80,
                                        in_stack_fffffe88,in_stack_fffffe90,in_stack_fffffe98);
        }
        else if (uVar8 == 4) {
          fparam_1 = (double)((double (*)())_InterpreterTextureSamplerSampleTexel1D)(param_1[0x28b],uVar24,in_r5,local_130 + 4,&local_80,dVar27,
                                        fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,fparam_7,
                                        fparam_8,in_stack_fffffe78,in_stack_fffffe80,
                                        in_stack_fffffe88,in_stack_fffffe90);
        }
        local_130[0] = local_80;
        local_130[1] = local_7c;
        local_130[2] = local_78;
        local_130[3] = local_74;
        break;
      case 0x48:
      case 0x49:
        fparam_1 = _floor((double)local_130[4]);
        if (DOUBLE_97c30a78 <= fparam_1) {
          local_98 = (longlong)(int)(fparam_1 - DOUBLE_97c30a78);
          uVar24 = (int)(fparam_1 - DOUBLE_97c30a78) ^ 0x80000000;
        }
        else {
          uVar24 = (uint)fparam_1;
          local_90 = (longlong)(int)uVar24;
        }
        param_1[0x290] = uVar24;
        goto switchD_97bd0598_caseD_6;
      case 0x4b:
        in_r5 = (float *)param_2[4];
        iVar14 = ((int (*)())_InterpreterTestCR)(param_1,param_2[3],in_r5,param_2[5],param_2[6],param_2[7],
                                    param_2[8],param_2[9],param_2[10],param_2[0xb],0);
        fparam_1 = extraout_f1;
        if (iVar14 == 0) {
          in_r5 = (float *)param_2[4];
          iVar14 = ((int (*)())_InterpreterTestCR)(param_1,param_2[3],in_r5,param_2[5],param_2[6],param_2[7],
                                      param_2[8],param_2[9],param_2[10],param_2[0xb],1);
          fparam_1 = extraout_f1_00;
          if (iVar14 == 0) {
            in_r5 = (float *)param_2[4];
            iVar14 = ((int (*)())_InterpreterTestCR)(param_1,param_2[3],in_r5,param_2[5],param_2[6],param_2[7],
                                        param_2[8],param_2[9],param_2[10],param_2[0xb],2);
            fparam_1 = extraout_f1_01;
            if (iVar14 == 0) {
              in_r5 = (float *)param_2[4];
              iVar14 = ((int (*)())_InterpreterTestCR)(param_1,param_2[3],in_r5,param_2[5],param_2[6],param_2[7],
                                          param_2[8],param_2[9],param_2[10],param_2[0xb],3);
              fparam_1 = extraout_f1_02;
              if (iVar14 == 0) goto switchD_97bd0598_caseD_6;
            }
          }
        }
      case 0x54:
      case 0x58:
      case 0x6b:
switchD_97bd0598_caseD_54:
        piVar18 = (int *)((**(int **)(iVar19 + 0xd80) + param_2[2] * 0x11c) - 0x11c);
        if ((int *)(*(int **)(iVar19 + 0xd80))[1] < piVar18) {
          piVar18 = (int *)0x0;
        }
switchD_97bd0598_caseD_6:
        bVar25 = false;
        break;
      case 0x4c:
        in_r5 = (float *)param_2[4];
        iVar14 = ((int (*)())_InterpreterTestCR)(param_1,param_2[3],in_r5,param_2[5],param_2[6],param_2[7],
                                    param_2[8],param_2[9],param_2[10],param_2[0xb],0);
        fparam_1 = extraout_f1_03;
        if (iVar14 == 0) {
          in_r5 = (float *)param_2[4];
          iVar14 = ((int (*)())_InterpreterTestCR)(param_1,param_2[3],in_r5,param_2[5],param_2[6],param_2[7],
                                      param_2[8],param_2[9],param_2[10],param_2[0xb],1);
          fparam_1 = extraout_f1_04;
          if (iVar14 == 0) {
            in_r5 = (float *)param_2[4];
            iVar14 = ((int (*)())_InterpreterTestCR)(param_1,param_2[3],in_r5,param_2[5],param_2[6],param_2[7],
                                        param_2[8],param_2[9],param_2[10],param_2[0xb],2);
            fparam_1 = extraout_f1_05;
            if (iVar14 == 0) {
              in_r5 = (float *)param_2[4];
              iVar14 = ((int (*)())_InterpreterTestCR)(param_1,param_2[3],in_r5,param_2[5],param_2[6],param_2[7],
                                          param_2[8],param_2[9],param_2[10],param_2[0xb],3);
              fparam_1 = extraout_f1_06;
              if (iVar14 == 0) goto switchD_97bd0598_caseD_6;
            }
          }
        }
        if ((uint *)param_1[0x29b] + 1 <= param_1 + 0x29b) {
          *(uint *)param_1[0x29b] = (uint)piVar18;
          param_1[0x29b] = param_1[0x29b] + 4;
          goto switchD_97bd0598_caseD_54;
        }
        break;
      case 0x4d:
        in_r5 = (float *)param_2[4];
        iVar14 = ((int (*)())_InterpreterTestCR)(param_1,param_2[3],in_r5,param_2[5],param_2[6],param_2[7],
                                    param_2[8],param_2[9],param_2[10],param_2[0xb],0);
        fparam_1 = extraout_f1_07;
        if (iVar14 == 0) {
          in_r5 = (float *)param_2[4];
          iVar14 = ((int (*)())_InterpreterTestCR)(param_1,param_2[3],in_r5,param_2[5],param_2[6],param_2[7],
                                      param_2[8],param_2[9],param_2[10],param_2[0xb],1);
          fparam_1 = extraout_f1_08;
          if (iVar14 == 0) {
            in_r5 = (float *)param_2[4];
            iVar14 = ((int (*)())_InterpreterTestCR)(param_1,param_2[3],in_r5,param_2[5],param_2[6],param_2[7],
                                        param_2[8],param_2[9],param_2[10],param_2[0xb],2);
            fparam_1 = extraout_f1_09;
            if (iVar14 == 0) {
              in_r5 = (float *)param_2[4];
              iVar14 = ((int (*)())_InterpreterTestCR)(param_1,param_2[3],in_r5,param_2[5],param_2[6],param_2[7],
                                          param_2[8],param_2[9],param_2[10],param_2[0xb],3);
              fparam_1 = extraout_f1_10;
              if (iVar14 == 0) goto switchD_97bd0598_caseD_6;
            }
          }
        }
        iVar14 = param_1[0x29b];
        piVar18 = (int *)0x0;
        piVar11 = (int *)(iVar14 - 4);
        if (param_1 + 0x297 <= piVar11) {
          param_1[0x29b] = (int)piVar11;
          piVar18 = *(int **)(iVar14 + -4);
        }
        goto switchD_97bd0598_caseD_6;
      case 0x4f:
        if ((((double)local_130[4] < DOUBLE_97c30a48) || ((double)local_130[5] < DOUBLE_97c30a48))
           || (((double)local_130[6] < DOUBLE_97c30a48 || ((double)local_130[7] < DOUBLE_97c30a48)))
           ) {
          param_1[0x296] = 1;
        }
        goto switchD_97bd0598_caseD_6;
      case 0x55:
        if ((((local_130[4] == TAllocation__guardBlockSize) &&
             (local_130[5] == TAllocation__guardBlockSize)) &&
            (local_130[6] == TAllocation__guardBlockSize)) &&
           (local_130[7] == TAllocation__guardBlockSize)) goto switchD_97bd0598_caseD_54;
        break;
      case 0x68:
        uVar24 = (uint)*(byte *)((int)param_2 + 5);
        if (uVar24 != 0) {
          pfVar10 = local_130;
          do {
            pfVar23 = pfVar10 + 4;
            pfVar1 = pfVar10 + 8;
            pfVar10 = pfVar10 + 1;
            fVar3 = *pfVar23 * *pfVar1 + fVar3;
            uVar24 = uVar24 - 1;
          } while (uVar24 != 0);
        }
        dVar27 = (double)(float)-((double)(local_100[0] * local_100[0]) *
                                  (DOUBLE_97c30a60 - (double)(fVar3 * fVar3)) - DOUBLE_97c30a60);
        if ((double)TAllocation__guardBlockSize <= dVar27) {
          fVar3 = local_100[0] * fVar3;
          fparam_1 = _sqrt(dVar27);
          dVar27 = (double)local_100[0];
          fVar3 = (float)((double)fVar3 + fparam_1);
          fparam_7 = (double)(fVar3 * local_130[0xb]);
          local_130[0] = (float)(dVar27 * (double)local_130[4] - (double)(fVar3 * local_130[8]));
          local_130[1] = (float)(dVar27 * (double)local_130[5] - (double)(fVar3 * local_130[9]));
          local_130[2] = (float)(dVar27 * (double)local_130[6] - (double)(fVar3 * local_130[10]));
          fparam_8 = (double)local_130[2];
          local_130[3] = (float)(dVar27 * (double)local_130[7] - fparam_7);
        }
        else {
          local_130[3] = TAllocation__guardBlockSize;
          local_130[0] = TAllocation__guardBlockSize;
          local_130[1] = TAllocation__guardBlockSize;
          local_130[2] = TAllocation__guardBlockSize;
        }
        break;
      case 0x6c:
        if ((param_2[9] == 3) && (param_2[0x13] == 1)) {
          dVar27 = _trunc((double)local_130[4]);
          local_130[0] = (float)dVar27;
          dVar27 = _trunc((double)local_130[5]);
          local_130[1] = (float)dVar27;
          dVar27 = _trunc((double)local_130[6]);
          fVar3 = local_130[7];
LAB_97bd200c:
          local_130[2] = (float)dVar27;
          dVar27 = _trunc((double)fVar3);
          goto LAB_97bd2010;
        }
        if ((param_2[9] != 4) || ((param_2[0x13] != 1 && (param_2[0x13] != 3))))
        goto switchD_97bd0598_caseD_0;
        local_130[0] = 1.0;
        if (local_130[4] == TAllocation__guardBlockSize) {
          local_130[0] = 0.0;
        }
        local_130[1] = 1.0;
        if (local_130[5] == TAllocation__guardBlockSize) {
          local_130[1] = 0.0;
        }
        local_130[2] = 1.0;
        if (local_130[6] == TAllocation__guardBlockSize) {
          local_130[2] = 0.0;
        }
        local_130[3] = 1.0;
        if (local_130[7] == TAllocation__guardBlockSize) goto LAB_97bd1ce0;
        break;
      case 0x6d:
        dVar27 = (double)local_130[8];
        local_130[0] = local_100[0];
        local_130[1] = local_100[1];
        local_130[2] = local_100[2];
        local_130[3] = local_100[3];
        if (DOUBLE_97c30a78 <= dVar27) {
          iVar14 = (int)(dVar27 - DOUBLE_97c30a78);
          local_a8 = (longlong)iVar14;
        }
        else {
          iVar14 = (int)local_130[8];
          local_a0 = (longlong)iVar14;
        }
        if (DOUBLE_97c30a78 <= dVar27) {
          iVar26 = (int)(dVar27 - DOUBLE_97c30a78);
          local_90 = (longlong)iVar26;
        }
        else {
          iVar26 = (int)local_130[8];
          local_98 = (longlong)iVar26;
        }
        local_130[iVar14] = local_130[iVar26 + 4];
        break;
      case 0x6f:
        dVar27 = _exp((double)local_130[4]);
        local_130[0] = (float)dVar27;
        dVar27 = _exp((double)local_130[5]);
        local_130[1] = (float)dVar27;
        dVar27 = _exp((double)local_130[6]);
        local_130[2] = (float)dVar27;
        dVar27 = _exp((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x70:
        dVar27 = _log((double)local_130[4]);
        local_130[0] = (float)dVar27;
        dVar27 = _log((double)local_130[5]);
        local_130[1] = (float)dVar27;
        dVar27 = _log((double)local_130[6]);
        local_130[2] = (float)dVar27;
        dVar27 = _log((double)local_130[7]);
LAB_97bd2010:
        local_130[3] = (float)dVar27;
LAB_97bd2014:
        fparam_1 = (double)local_130[3];
      }
      if (cVar4 != '\0') {
        if (DOUBLE_97c30a48 <= (double)local_130[0]) {
          if ((double)local_130[0] <= DOUBLE_97c30a60) {
            local_70 = local_130[0];
          }
          else {
            local_130[0] = 1.0;
          }
        }
        else {
          local_130[0] = 0.0;
        }
        if (DOUBLE_97c30a48 <= (double)local_130[1]) {
          if ((double)local_130[1] <= DOUBLE_97c30a60) {
            local_70 = local_130[1];
          }
          else {
            local_130[1] = 1.0;
          }
        }
        else {
          local_130[1] = 0.0;
        }
        if (DOUBLE_97c30a48 <= (double)local_130[2]) {
          if ((double)local_130[2] <= DOUBLE_97c30a60) {
            local_70 = local_130[2];
          }
          else {
            local_130[2] = 1.0;
          }
        }
        else {
          local_130[2] = 0.0;
        }
        if (DOUBLE_97c30a48 <= (double)local_130[3]) {
          if ((double)local_130[3] <= DOUBLE_97c30a60) {
            local_70 = local_130[3];
          }
          else {
            local_130[3] = 1.0;
          }
        }
        else {
          local_130[3] = 0.0;
        }
      }
      if (bVar25) {
        uVar24 = uVar17;
        if (*(char *)(param_2 + 8) == '\0') {
          uVar24 = 0;
        }
        in_r5 = (float *)param_2[4];
        fparam_1 = (double)((int (*)())_InterpreterWriteDestination)(param_1,param_2[3],in_r5,param_2[5],param_2[6],param_2[7],
                                      param_2[8],param_2[9],param_2[10],param_2[0xb],uVar24,
                                      local_130,(uint)*(byte *)((int)param_2 + 6));
      }
      uVar17 = uVar17 + 1;
      if (uVar20 <= uVar17) {
        return piVar18;
      }
      iVar14 = param_2[0xc];
    } while( true );
  }
  if (uVar20 < 2) {
    ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
               param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],0,local_130 + 4);
    ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
               param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],0,local_130 + 8);
    if (*(char *)((int)param_2 + 0x21) == '\x01') {
      cVar4 = *(char *)((int)param_2 + 5);
      if (cVar4 == '\x01') {
LAB_97bd0310:
        local_130[0] = 1.0;
        if (local_130[5] == local_130[9]) goto LAB_97bd0328;
      }
      else if (cVar4 == '\x02') {
        if (local_130[4] == local_130[8]) goto LAB_97bd0310;
      }
      else if (cVar4 == '\x03') {
        if ((local_130[4] == local_130[8]) &&
           (bVar25 = local_130[5] == local_130[9], local_130[5] = local_130[6],
           local_130[9] = local_130[10], bVar25)) goto LAB_97bd0310;
      }
      else {
        if (cVar4 != '\x04') goto LAB_97bd0328;
        if (((local_130[4] == local_130[8]) && (local_130[5] == local_130[9])) &&
           (local_130[5] = local_130[7], local_130[9] = local_130[0xb],
           local_130[6] == local_130[10])) goto LAB_97bd0310;
      }
      local_130[0] = 0.0;
      goto LAB_97bd0328;
    }
    local_130[0] = 1.0;
    if (local_130[4] != local_130[8]) {
      local_130[0] = 0.0;
    }
    local_130[1] = 1.0;
    if (local_130[5] != local_130[9]) {
      local_130[1] = 0.0;
    }
    local_130[2] = 1.0;
    if (local_130[6] != local_130[10]) {
      local_130[2] = 0.0;
    }
    local_130[3] = 1.0;
    if (local_130[7] != local_130[0xb]) {
      local_130[3] = 0.0;
    }
  }
  else {
    if (uVar20 == 3) {
      pfVar10 = local_130;
      uVar20 = 0;
      do {
        uVar17 = uVar20;
        if (*(char *)(param_2 + 0x12) == '\0') {
          uVar17 = 0;
        }
        ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                   param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],uVar17,local_130 + 4);
        uVar17 = uVar20;
        if (*(char *)(param_2 + 0x1b) == '\0') {
          uVar17 = 0;
        }
        ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                   param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],uVar17,local_130 + 8);
        if (((local_130[4] != local_130[8]) || (local_130[5] != local_130[9])) ||
           (fVar3 = FLOAT_97c3acd8, local_130[6] != local_130[10])) {
          fVar3 = TAllocation__guardBlockSize;
        }
        uVar20 = uVar20 + 1;
        *pfVar10 = fVar3;
        pfVar10 = pfVar10 + 1;
      } while (uVar20 < 3);
      uStack_ac = 0;
      if ((local_130[0] != TAllocation__guardBlockSize) &&
         (local_130[1] != TAllocation__guardBlockSize)) {
LAB_97bd0194:
        uStack_ac = 0;
        if (local_130[2] != TAllocation__guardBlockSize) {
          uStack_ac = 1;
        }
      }
LAB_97bd01a0:
      uStack_ac = uStack_ac ^ 0x80000000;
      local_b0 = 0x43300000;
      local_130[0] = (float)((double)CONCAT44(0x43300000,uStack_ac) - DOUBLE_97c30a58);
    }
    else if (uVar20 < 4) {
      if (uVar20 == 2) {
        pfVar10 = local_130;
        uVar20 = 0;
        do {
          uVar17 = uVar20;
          if (*(char *)(param_2 + 0x12) == '\0') {
            uVar17 = 0;
          }
          ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                     param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],uVar17,local_130 + 4);
          uVar17 = uVar20;
          if (*(char *)(param_2 + 0x1b) == '\0') {
            uVar17 = 0;
          }
          ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                     param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],uVar17,local_130 + 8);
          if ((local_130[4] != local_130[8]) ||
             (fVar3 = FLOAT_97c3acd8, local_130[5] != local_130[9])) {
            fVar3 = TAllocation__guardBlockSize;
          }
          uVar20 = uVar20 + 1;
          *pfVar10 = fVar3;
          pfVar10 = pfVar10 + 1;
        } while (uVar20 < 2);
        uStack_ac = 0;
        local_130[2] = local_130[1];
        if (local_130[0] != TAllocation__guardBlockSize) goto LAB_97bd0194;
        goto LAB_97bd01a0;
      }
    }
    else if (uVar20 == 4) {
      pfVar10 = local_130;
      uVar20 = 0;
      do {
        uVar17 = uVar20;
        if (*(char *)(param_2 + 0x12) == '\0') {
          uVar17 = 0;
        }
        ((int (*)())_InterpreterLoadSource)(param_1,param_2[0xd],param_2[0xe],param_2[0xf],param_2[0x10],param_2[0x11],
                   param_2[0x12],param_2[0x13],param_2[0x14],param_2[0x15],uVar17,local_130 + 4);
        uVar17 = uVar20;
        if (*(char *)(param_2 + 0x1b) == '\0') {
          uVar17 = 0;
        }
        ((int (*)())_InterpreterLoadSource)(param_1,param_2[0x16],param_2[0x17],param_2[0x18],param_2[0x19],param_2[0x1a],
                   param_2[0x1b],param_2[0x1c],param_2[0x1d],param_2[0x1e],uVar17,local_130 + 8);
        if ((((local_130[4] != local_130[8]) || (local_130[5] != local_130[9])) ||
            (local_130[6] != local_130[10])) ||
           (fVar3 = FLOAT_97c3acd8, local_130[7] != local_130[0xb])) {
          fVar3 = TAllocation__guardBlockSize;
        }
        uVar20 = uVar20 + 1;
        *pfVar10 = fVar3;
        pfVar10 = pfVar10 + 1;
      } while (uVar20 < 4);
      uStack_ac = 0;
      if (((local_130[0] != TAllocation__guardBlockSize) &&
          (local_130[1] != TAllocation__guardBlockSize)) &&
         (bVar25 = local_130[2] != TAllocation__guardBlockSize, local_130[2] = local_130[3], bVar25)
         ) goto LAB_97bd0194;
      goto LAB_97bd01a0;
    }
LAB_97bd0328:
    local_130[3] = local_130[0];
    local_130[1] = local_130[0];
    local_130[2] = local_130[0];
  }
  pfVar10 = local_130;
  if (iVar21 == 0x36) {
    local_130[0] = (float)(DOUBLE_97c30a60 - (double)local_130[0]);
    local_130[1] = (float)(DOUBLE_97c30a60 - (double)local_130[1]);
    local_130[2] = (float)(DOUBLE_97c30a60 - (double)local_130[2]);
    local_130[3] = (float)(DOUBLE_97c30a60 - (double)local_130[3]);
  }
  iVar16 = param_2[9];
  uVar20 = (uint)*(byte *)((int)param_2 + 6);
  iVar19 = param_2[10];
  iVar22 = param_2[0xb];
  iVar14 = param_2[3];
  iVar21 = param_2[4];
  iVar26 = param_2[5];
  iVar12 = param_2[6];
  iVar13 = param_2[7];
  iVar15 = param_2[8];
  uVar32 = 0;
LAB_97bd043c:
  ((int (*)())_InterpreterWriteDestination)(param_1,iVar14,iVar21,iVar26,iVar12,iVar13,iVar15,iVar16,iVar19,iVar22,uVar32,pfVar10,
             uVar20);
  return piVar18;
}

/* _InterpreterWriteFinalFragmentToBuffer @ 0x97bd3068 (376 bytes) */
int _InterpreterWriteFinalFragmentToBuffer(param_1, param_2, param_3, param_4, param_5, param_6, param_7)
  int *param_1;
  undefined4 param_2;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined1 auStack_40 [16];
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  piVar3 = param_1 + 0x292;
  iVar2 = *param_1;
  iVar1 = *(int *)(iVar2 + 0xd80);
  if ((*(uint *)(iVar1 + 0x3c) & 1) != 0) {
    iVar1 = _InterpreterRasterOpMachine_AlphaTest(param_1 + 0x289,piVar3);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = *(int *)(iVar2 + 0xd80);
  }
  if ((*(uint *)(iVar1 + 0x3c) & 6) != 0) {
    iVar1 = _InterpreterRasterOpMachine_DepthAndStencilTest(param_1 + 0x289);
    if (iVar1 != 0) {
      return;
    }
    iVar1 = *(int *)(iVar2 + 0xd80);
  }
  if ((*(uint *)(iVar1 + 0x3c) & 0x68) != 0) {
    ((int (*)())_InterpreterUnpackPixel)(param_1,auStack_40,*(undefined4 *)(iVar2 + 0xd88));
    iVar1 = *(int *)(iVar2 + 0xd80);
  }
  if ((*(uint *)(iVar1 + 0x3c) & 8) != 0) {
    _InterpreterRasterOpMachine_Blending(param_1 + 0x289,piVar3,auStack_40,&local_30);
    param_1[0x292] = local_30;
    param_1[0x293] = local_2c;
    param_1[0x294] = local_28;
    param_1[0x295] = local_24;
    iVar1 = *(int *)(iVar2 + 0xd80);
  }
  if ((*(uint *)(iVar1 + 0x3c) & 0x20) != 0) {
    _InterpreterRasterOpMachine_LogicOp(param_1 + 0x289,piVar3,auStack_40,&local_30);
    param_1[0x292] = local_30;
    param_1[0x293] = local_2c;
    param_1[0x294] = local_28;
    param_1[0x295] = local_24;
    iVar1 = *(int *)(iVar2 + 0xd80);
  }
  if ((*(uint *)(iVar1 + 0x3c) & 0x40) == 0) {
    local_24 = param_1[0x295];
    local_30 = param_1[0x292];
    local_2c = param_1[0x293];
    local_28 = param_1[0x294];
  }
  else {
    _InterpreterRasterOpMachine_BufferMask(param_1 + 0x289,piVar3,auStack_40,&local_30);
  }
  ((int (*)())_InterpreterPackPixel)(param_1,&local_30,*(undefined4 *)(iVar2 + 0xd88));
  return;
}

/* _InterpreterRun @ 0x97bd31e0 (1020 bytes) */
void _InterpreterRun(int param_1,int param_2,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool bVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  double dVar13;
  float fVar14;
  int iVar15;
  float *pfVar16;
  uint uVar17;
  int iVar18;
  int extraout_r4;
  int extraout_r4_00;
  int extraout_r4_01;
  undefined4 in_r5;
  undefined4 in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  int iVar19;
  int iVar20;
  uint uVar21;
  uint uVar22;
  int iVar23;
  double dVar24;
  double extraout_f1;
  double extraout_f1_00;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  double in_stack_ffffff38;
  double in_stack_ffffff40;
  double in_stack_ffffff48;
  double in_stack_ffffff50;
  double in_stack_ffffff58;
  
  dVar13 = DOUBLE_97c30a60;
  iVar19 = *(int *)(*(int *)(param_1 + 0xd80) + 0x38);
  iVar23 = *(int *)(param_1 + 0xdf0);
  iVar15 = *(int *)(param_1 + 0xd9c);
  uVar22 = 0xff;
  uVar21 = 0;
  if ((iVar19 == 0x8804) || (iVar19 == 0x8b30)) {
    dVar28 = (double)*(float *)(*(int *)(param_1 + 0xda0) + 0xc);
    dVar26 = (double)*(float *)(*(int *)(param_1 + 0xda0) + 8);
    dVar27 = (double)*(float *)(*(int *)(param_1 + 0xda4) + 0xc);
    dVar25 = (double)*(float *)(*(int *)(param_1 + 0xda4) + 8);
    fVar6 = TAllocation__guardBlockSize;
    fVar7 = TAllocation__guardBlockSize;
    fVar8 = TAllocation__guardBlockSize;
    fVar9 = TAllocation__guardBlockSize;
    fVar10 = TAllocation__guardBlockSize;
    fVar11 = TAllocation__guardBlockSize;
  }
  else {
    dVar27 = (double)TAllocation__guardBlockSize;
    dVar25 = dVar27;
    dVar26 = dVar27;
    dVar28 = dVar27;
    fVar6 = *(float *)(iVar15 + 0x1b88);
    fVar7 = *(float *)(iVar15 + 0x1b78);
    fVar8 = *(float *)(iVar15 + 0x1b70);
    fVar9 = *(float *)(iVar15 + 0x1b80);
    fVar10 = *(float *)(iVar15 + 0x1b84);
    fVar11 = *(float *)(iVar15 + 0x1b74);
  }
  iVar15 = *(int *)(*(int *)(param_1 + 0xd80) + 0x38);
  if ((iVar15 == 0x8804) || (iVar15 == 0x8b30)) {
    *(undefined4 *)(iVar23 + 0xa30) = 0;
    *(float *)(iVar23 + 0xa38) = (float)dVar26;
    *(float *)(iVar23 + 0xa3c) = (float)(dVar13 / dVar28);
  }
  iVar15 = iVar23 + 0xa5c;
  *(undefined1 *)(iVar23 + 0xa47) = 0;
  *(undefined4 *)(iVar23 + 0xa68) = 0;
  *(int *)(iVar23 + 0xa6c) = iVar15;
  *(undefined1 *)(iVar23 + 0xa44) = 0;
  *(undefined1 *)(iVar23 + 0xa45) = 0;
  *(undefined1 *)(iVar23 + 0xa46) = 0;
  *(undefined4 *)(iVar23 + 0xa5c) = 0;
  *(undefined4 *)(iVar23 + 0xa60) = 0;
  *(undefined4 *)(iVar23 + 0xa64) = 0;
  fVar14 = TAllocation__guardBlockSize;
  dVar13 = DOUBLE_97c30a60;
  iVar19 = param_2;
  do {
    if (iVar19 == 0) {
      iVar15 = *(int *)(*(int *)(param_1 + 0xd80) + 0x38);
      if ((iVar15 == 0x8804) || (iVar15 == 0x8b30)) {
        uVar21 = 0;
      }
      else {
        uVar21 = uVar22 << 8 | uVar21;
      }
      FUN_97c1a28c(uVar21);
      return;
    }
    iVar19 = iVar19 + -1;
    *(undefined4 *)(iVar23 + 0xa58) = 0;
    iVar20 = *(int *)(param_1 + 0xd80);
    if (((*(uint *)(iVar20 + 0x3c) & 6) == 4) && ((*(uint *)(iVar20 + 0x34) & 0xa000) == 0)) {
      uVar17 = _InterpreterRasterOpMachine_DepthTest(iVar23 + 0xa24);
      *(uint *)(iVar23 + 0xa58) = *(uint *)(iVar23 + 0xa58) | uVar17;
      iVar20 = *(int *)(param_1 + 0xd80);
      param_2 = extraout_r4;
      fparam_1 = extraout_f1;
    }
    iVar18 = *(int *)(iVar20 + 0x120);
    if ((iVar18 != 0) && (*(int *)(iVar23 + 0xa58) == 0)) {
      do {
        iVar18 = ((int * (*)())_InterpreterEmulateOp)(iVar23,iVar18,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,
                            fparam_7,fparam_8,in_stack_ffffff38,in_stack_ffffff40,in_stack_ffffff48,
                            in_stack_ffffff50,in_stack_ffffff58);
        fparam_1 = extraout_f1_00;
        if (iVar18 == 0) break;
      } while (*(int *)(iVar23 + 0xa58) == 0);
      iVar20 = *(int *)(param_1 + 0xd80);
      param_2 = extraout_r4_00;
    }
    if ((*(int *)(iVar20 + 0x38) == 0x8804) || (*(int *)(iVar20 + 0x38) == 0x8b30)) {
      if (*(int *)(iVar23 + 0xa58) == 0) {
        fparam_1 = (double)((int (*)())_InterpreterWriteFinalFragmentToBuffer)(iVar23,param_2,in_r5,in_r6,in_r7,in_r8,iVar15);
        iVar20 = *(int *)(param_1 + 0xd80);
        param_2 = extraout_r4_01;
      }
    }
    else {
      pfVar16 = *(float **)(param_1 + 0xd88);
      uVar17 = 0;
      fVar2 = pfVar16[7];
      fVar3 = pfVar16[4];
      fVar12 = -fVar2;
      fVar4 = pfVar16[5];
      fVar5 = pfVar16[6];
      if (fVar3 < fVar12) {
        uVar17 = 0x10;
      }
      if (fVar2 <= fVar3) {
        uVar17 = uVar17 | 0x20;
      }
      if (fVar4 < fVar12) {
        uVar17 = uVar17 | 4;
      }
      if (fVar2 <= fVar4) {
        uVar17 = uVar17 | 8;
      }
      if (fVar5 < fVar12) {
        uVar17 = uVar17 | 1;
      }
      if (fVar2 < fVar5) {
        uVar17 = uVar17 | 2;
      }
      pfVar16[0x1f] = (float)(uVar17 | 0x1000000);
      if (uVar17 == 0) {
        if (fVar2 < fVar14) {
          bVar1 = fVar2 <= FLOAT_97c3acf4;
        }
        else {
          bVar1 = FLOAT_97c3acf0 <= fVar2;
        }
        if (bVar1) {
          fVar12 = FLOAT_97c3acd8 / fVar2;
        }
        else {
          fVar12 = FLOAT_97c3acfc;
          if (fVar14 <= fVar2) {
            fVar12 = FLOAT_97c3acf8;
          }
        }
        pfVar16[3] = fVar12;
        *pfVar16 = fVar3 * fVar12 * fVar8 + fVar9;
        pfVar16[1] = fVar4 * fVar12 * fVar11 + fVar10;
        pfVar16[2] = fVar5 * fVar12 * fVar7 + fVar6;
      }
      iVar20 = *(int *)(param_1 + 0xd80);
      uVar22 = uVar22 & uVar17;
      uVar21 = uVar21 | uVar17;
    }
    *(int *)(param_1 + 0xd8c) = *(int *)(param_1 + 0xd8c) + *(int *)(iVar20 + 0xbc);
    *(int *)(param_1 + 0xd88) = *(int *)(param_1 + 0xd88) + *(int *)(iVar20 + 0xb8);
    iVar15 = *(int *)(param_1 + 0xda8) + *(int *)(iVar20 + 0xd8);
    *(int *)(param_1 + 0xda8) = iVar15;
    *(int *)(param_1 + 0xdac) = *(int *)(param_1 + 0xdac) + *(int *)(iVar20 + 0xdc);
    if ((*(int *)(iVar20 + 0x38) == 0x8804) || (*(int *)(iVar20 + 0x38) == 0x8b30)) {
      fVar2 = (float)((double)*(float *)(iVar23 + 0xa30) + dVar13);
      dVar24 = (double)fVar2;
      *(float *)(iVar23 + 0xa30) = fVar2;
      *(float *)(iVar23 + 0xa38) = (float)(dVar25 * dVar24 + dVar26);
      *(float *)(iVar23 + 0xa3c) = (float)(dVar13 / (double)(float)(dVar27 * dVar24 + dVar28));
    }
  } while( true );
}

/* _InterpreterTextureSamplerCreate @ 0x97bd35dc (12 bytes) */
int _InterpreterTextureSamplerCreate()
{
  undefined4 uVar1;
  
  uVar1 = _calloc(0x2c,1);
  return uVar1;
}

/* _InterpreterTextureSamplerInitialise @ 0x97bd35e8 (16 bytes) */
int _InterpreterTextureSamplerInitialise(param_1)
  int param_1;
{
  *(undefined4 *)(param_1 + 0x18) = 0xffffffff;
  *(undefined4 *)(param_1 + 0x14) = 0xffffffff;
  return;
}

/* _InterpreterTextureSamplerAttachGLDContext @ 0x97bd35fc (8 bytes) */
int _InterpreterTextureSamplerAttachGLDContext(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  return;
}

/* _InterpreterTextureSamplerSetProjectionEnabled @ 0x97bd3604 (8 bytes) */
int _InterpreterTextureSamplerSetProjectionEnabled(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return;
}

/* _InterpreterTextureSamplerSetLodBiasEnabled @ 0x97bd360c (8 bytes) */
int _InterpreterTextureSamplerSetLodBiasEnabled(param_1, param_2)
  int param_1;
  undefined4 param_2;
{
  *(undefined4 *)(param_1 + 0x24) = param_2;
  return;
}

