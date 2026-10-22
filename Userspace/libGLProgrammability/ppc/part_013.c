#include "decls.h"

/* __ZN17TPPStreamCompilerD1Ev @ 0x97bc97dc (8 bytes) */
int __ZN17TPPStreamCompilerD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN17TPPStreamCompilerD4Ev)(this,2);
}

/* __ZN17TPPStreamCompilerD0Ev @ 0x97bc97e4 (8 bytes) */
int __ZN17TPPStreamCompilerD0Ev(this)
  void *this;
{
  return ((int (*)())__ZN17TPPStreamCompilerD4Ev)(this,3);
}

/* __ZN17TPPStreamCompilerD4Ev @ 0x97bc97ec (536 bytes) */
int __ZN17TPPStreamCompilerD4Ev(this, param_2)
  void *this;
  uint param_2;
{
  int atomicStore;
  int *refCountPtr;
  int oldRefCount;
  int iVar4;
  void *pvVar5;
  char reservation;
  byte cr0Reg;
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
  refCountPtr = (int *)(iVar4 + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
    __ZNSs4_Rep10_M_destroyERKSaIcE((unsigned char *)(iVar4 + -0xc),auStack_30);
  }
  iVar4 = *(int *)((int)this + 0xb0);
  refCountPtr = (int *)(iVar4 + -4);
  do {
    oldRefCount = *refCountPtr;
    if (reservation != '\0') {
      atomicStore = storeWordConditionalIndexed(oldRefCount + -1,0,refCountPtr);
      *refCountPtr = atomicStore;
      cr0Reg = 2;
    }
  } while (!(bool)(cr0Reg >> 1 & 1));
  if (oldRefCount < 1) {
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
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char acStack_120 [264];
  
  iVar5 = 0;
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = param_5;
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = param_6;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = param_7;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = param_8;
  _vsprintf(acStack_120,param_4,&(*(unsigned int *)((unsigned char *)ghidra_home + 16)));
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
  unsigned int ghidra_home[8] = { param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char acStack_120 [268];
  
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = param_5;
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = param_6;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = param_7;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = param_8;
  _vsprintf(acStack_120,param_4,&(*(unsigned int *)((unsigned char *)ghidra_home + 16)));
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
  return _free(pcVar4);
}

/* TPPStreamCompiler__getSymbolTableString @ 0x97bc9c5c (196 bytes) */
int TPPStreamCompiler__getSymbolTableString(this, param_2)
  unsigned char * this;
  int param_2;
{
  undefined4 string;
  int length;
  char *allocation;
  char *pcVar4;
  
  if (*(unsigned char **)(this + 0x68) == (unsigned char *)0x0) {
    return (char *)0x0;
  }
  string = ParseSymbolTable__GetString(*(unsigned char **)(this + 0x68),param_2);
  length = _strlen(string);
  allocation = (char *)_malloc(length + 0x17);
  *allocation = '\0';
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
  _sprintf(allocation,pcVar4,string);
LAB_97bc9d00:
  _free(string);
  return allocation;
}

/* TPPStreamCompiler__dumpSymbolTableInfo @ 0x97bc9d20 (220 bytes) */
int TPPStreamCompiler__dumpSymbolTableInfo(this, param_2)
  unsigned char * this;
  int param_2;
{
  char *string;
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
  string = (char *)ParseSymbolTable__GetString(*(unsigned char **)(this + 0x68),param_2);
  if (string == (char *)0x0) {
    return;
  }
  __ZN13TInfoSinkBase6appendEPKc(this + 0xb0,string);
  __ZN13TInfoSinkBase6appendEPKc(this + 0xb0,DAT_a7b7bd78);
  _free(string);
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
  undefined4 ppStreamCreateResult;
  void *allocation;
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
  allocation = operator_new(0x54);
  __ZN16ParseSymbolTableC1Ej(allocation,0x80);
  *(void **)(this + 0x68) = allocation;
  *(undefined4 *)((int)allocation + 0x3c) = *(undefined4 *)(this + 8);
  pvVar4 = *(void **)(this + 0x6c);
  if (pvVar4 != (void *)0x0) {
    ((int (*)())__ZN13FunctionTableD1Ev)(pvVar4);
    __ZdlPv(pvVar4);
  }
  allocation = operator_new(8);
  ((int (*)())__ZN13FunctionTableC1Ev)(allocation);
  *(void **)(this + 0x6c) = allocation;
  if (*(int *)(this + 0x70) != 0) {
    _PPStreamFree(*(int *)(this + 0x70));
  }
  ppStreamCreateResult = _PPStreamCreate();
  *(undefined4 *)(this + 0x70) = ppStreamCreateResult;
  *(undefined4 *)(*(int *)(this + 0x68) + 0xc) = ppStreamCreateResult;
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
int TPPStreamCompiler__compile(this, intermNode)
  unsigned char * this;
  unsigned char * intermNode;
{
  int parseIntermediateTreeResult;
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 allocation;
  char *pPStreamString;
  uint uVar6;
  int local_20 [5];
  
  parseIntermediateTreeResult = TPPStreamCompiler__parseIntermediateTree(this,intermNode);
  *(int *)(this + 0xc) = parseIntermediateTreeResult;
  if (parseIntermediateTreeResult != 0) {
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
      allocation = _malloc(local_20[0] * 8 + 0xfU & 0xfffffff0);
      *(undefined4 *)(this + 0x74) = allocation;
      _PPStreamGetStream(*(undefined4 *)(this + 0x70),allocation,local_20);
    }
  }
  iVar2 = *(int *)(this + 0xc);
  if ((iVar2 != 0) && ((*(uint *)(this + 0xc0) & 0x10) != 0)) {
    ((int (*)())TPPStreamCompiler__dumpSymbolTableInfo)(this,2);
    iVar2 = *(int *)(this + 0xc);
  }
  if ((iVar2 != 0) && ((*(uint *)(this + 0xc0) & 2) != 0)) {
    __ZN13TInfoSinkBase6appendEPKc(this + 0xb0,DAT_a7b7bd80);
    pPStreamString = (char *)(**(code **)(*(int *)this + 0x28))(this);
    __ZN13TInfoSinkBase6appendEPKc(this + 0xb0,pPStreamString);
    iVar2 = *(int *)(this + 0xc);
  }
  return iVar2;
}

/* TPPStreamCompiler__getStatsString @ 0x97bca090 (108 bytes) */
int TPPStreamCompiler__getStatsString(this)
  unsigned char * this;
{
  int length;
  undefined4 uVar1;
  int iVar2;
  undefined4 allocation;
  
  uVar1 = DAT_a7b7bd84;
  iVar2 = *(int *)(this + 0x78);
  if (iVar2 == 0) {
    length = _strlen(DAT_a7b7bd84);
    allocation = _malloc(length * 4 + 4);
    *(undefined4 *)(this + 0x78) = allocation;
    _strcpy(allocation,uVar1);
    iVar2 = *(int *)(this + 0x78);
  }
  return iVar2;
}

/* TPPStreamCompiler__getPPStreamString @ 0x97bca0fc (144 bytes) */
int TPPStreamCompiler__getPPStreamString(this)
  unsigned char * this;
{
  undefined4 uVar1;
  void *pvVar2;
  int length;
  undefined4 allocation;
  
  uVar1 = DAT_a7b7bd88;
  pvVar2 = *(void **)(this + 0x7c);
  if (pvVar2 == (void *)0x0) {
    if ((*(int *)(this + 0xc) == 0) || (*(int *)(this + 0x74) == 0)) {
      length = _strlen(DAT_a7b7bd88);
      allocation = _malloc(length * 4 + 4);
      *(undefined4 *)(this + 0x7c) = allocation;
      _strcpy(allocation,uVar1);
      pvVar2 = *(void **)(this + 0x7c);
    }
    else {
      pvVar2 = _glpPPDisassemble(*(int *)(this + 0x74));
      *(void **)(this + 0x7c) = pvVar2;
    }
  }
  return pvVar2;
}

/* TPPStreamCompiler__getShaderToProgramString @ 0x97bca18c (148 bytes) */
int TPPStreamCompiler__getShaderToProgramString(this)
  unsigned char * this;
{
  int length;
  int iVar1;
  undefined4 allocation;
  
  iVar1 = *(int *)(this + 0x80);
  if (iVar1 == 0) {
    if ((*(int *)(this + 0xc) == 0) || (*(int *)(this + 0x74) == 0)) {
      length = _strlen("No Shader Program generated.");
      allocation = _malloc(length * 4 + 4);
      *(undefined4 *)(this + 0x80) = allocation;
      _strcpy(allocation,"No Shader Program generated.");
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
int ConstructCompiler(language, param_2)
  undefined4 language;
  undefined4 param_2;
{
  void *this;
  
  this = operator_new(200);
  __ZN17TPPStreamCompilerC1E11EShLanguagei(this,language,param_2);
  return this;
}

/* DeleteCompiler @ 0x97bca2b0 (24 bytes) */
int DeleteCompiler(compiler)
  unsigned char * compiler;
{
  if (compiler == (unsigned char *)0x0) {
    return;
  }
                    
                    
  (**(code **)(*(int *)compiler + 4))(compiler);
  return;
}

/* GetBuiltInInitialSwizzle @ 0x97bca2c8 (748 bytes) */
int GetBuiltInInitialSwizzle(parseSymbol)
  unsigned char * parseSymbol;
{
  int fieldValue;
  bool hashMatches;
  char *charPtr;
  int nameLength;
  int weightedChar;
  int charWeight;
  int charIndex;
  int nameHash;
  
  nameLength = *(int *)(parseSymbol + 0x20);
  nameHash = 0;
  charIndex = 0;
  if (0 < nameLength) {
    charWeight = 3;
    do {
      charPtr = (char *)(*(int *)(parseSymbol + 0x14) + charIndex);
      charIndex = charIndex + 1;
      weightedChar = *charPtr * charWeight;
      charWeight = charWeight + 2;
      nameHash = nameHash + weightedChar;
      nameLength = nameLength + -1;
    } while (nameLength != 0);
  }
  if (nameHash == 0x18ec7) {
    return 3;
  }
  if (nameHash < 0x18ec8) {
    if (nameHash == 0x17e27) {
      return 3;
    }
    if (0x17e27 < nameHash) {
      if (nameHash == 0x17ecc) {
        return 3;
      }
      if (nameHash < 0x17ecd) {
        if (nameHash == 0x17e69) {
          return 3;
        }
        if (nameHash < 0x17e6a) {
          fieldValue = 0x17e48;
        }
        else {
          if (nameHash == 0x17e8a) {
            return 3;
          }
          fieldValue = 0x17eab;
        }
      }
      else {
        if (nameHash == 0x18e64) {
          return 3;
        }
        if (nameHash < 0x18e65) {
          if (nameHash == 0x17eed) {
            return 3;
          }
          fieldValue = 0x18e43;
        }
        else {
          if (nameHash == 0x18e85) {
            return 3;
          }
          fieldValue = 0x18ea6;
        }
      }
LAB_97bca478:
      if (nameHash == fieldValue) {
        return 3;
      }
      return 0;
    }
    if (nameHash == 0x71c3) {
      return 2;
    }
    if (nameHash < 0x71c4) {
      if (nameHash == 0x3f94) {
        return 3;
      }
      if (0x3f94 < nameHash) {
        if (nameHash == 0x42d8) {
          return 1;
        }
        hashMatches = nameHash == 0x7171;
        goto LAB_97bca520;
      }
      hashMatches = nameHash == 0x2c25;
      goto LAB_97bca590;
    }
    if (nameHash == 0x8837) {
      return 2;
    }
    if (0x8837 < nameHash) {
      if (nameHash == 0x12304) {
        return 3;
      }
      fieldValue = 0x17e06;
      goto LAB_97bca478;
    }
    hashMatches = nameHash == 0x7a53;
    goto LAB_97bca520;
  }
  if (nameHash == 0x2043a) {
    return 1;
  }
  if (nameHash < 0x2043b) {
    if (nameHash == 0x20374) {
      return 1;
    }
    if (nameHash < 0x20375) {
      if (nameHash == 0x18f09) {
        return 3;
      }
      if (nameHash < 0x18f0a) {
        fieldValue = 0x18ee8;
        goto LAB_97bca478;
      }
      if (nameHash == 0x18f2a) {
        return 3;
      }
      fieldValue = 0x1f1a8;
    }
    else {
      if (nameHash == 0x203d7) {
        return 1;
      }
      if (nameHash < 0x203d8) {
        if (nameHash == 0x20395) {
          return 1;
        }
        fieldValue = 0x203b6;
      }
      else {
        if (nameHash == 0x203f8) {
          return 1;
        }
        fieldValue = 0x20419;
      }
    }
LAB_97bca51c:
    hashMatches = nameHash == fieldValue;
LAB_97bca520:
    if (hashMatches) {
      return 1;
    }
    return 0;
  }
  if (nameHash == 0x2614d) {
    return 2;
  }
  if (nameHash < 0x2614e) {
    if (nameHash == 0x24cb9) {
      return 2;
    }
    if (nameHash < 0x24cba) {
      fieldValue = 0x2045b;
      goto LAB_97bca51c;
    }
    if (nameHash == 0x2610b) {
      return 2;
    }
    fieldValue = 0x2612c;
  }
  else {
    if (nameHash == 0x261b0) {
      return 2;
    }
    if (nameHash < 0x261b1) {
      if (nameHash == 0x2616e) {
        return 2;
      }
      fieldValue = 0x2618f;
    }
    else {
      if (nameHash == 0x261d1) {
        return 2;
      }
      fieldValue = 0x261f2;
    }
  }
  hashMatches = nameHash == fieldValue;
LAB_97bca590:
  if (hashMatches) {
    return 2;
  }
  return 0;
}

/* GetBuiltInChunkForSymbol @ 0x97bca5b4 (8452 bytes) */
int GetBuiltInChunkForSymbol(parseSymbol, param_2)
  unsigned char * parseSymbol;
  int param_2;
{
  int fieldValue;
  uint directIndex;
  bool hashMatches;
  char *charPtr;
  int nameLength;
  int weightedChar;
  uint uVar5;
  uint chunkWord;
  int charWeight;
  undefined4 chunkType;
  undefined1 directIndex2;
  int charIndex;
  int nameHash;
  int chunk;
  
  chunk = 0;
  nameLength = *(int *)(parseSymbol + 0x20);
  nameHash = 0;
  charIndex = 0;
  if (0 < nameLength) {
    charWeight = 3;
    do {
      charPtr = (char *)(*(int *)(parseSymbol + 0x14) + charIndex);
      charIndex = charIndex + 1;
      weightedChar = *charPtr * charWeight;
      charWeight = charWeight + 2;
      nameHash = nameHash + weightedChar;
      nameLength = nameLength + -1;
    } while (nameLength != 0);
  }
  if (nameHash == 0x10f9c) {
    chunk = _PPStreamChunkCreateWithType(3,0);
    chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fff9 | 0x50009;
    goto LAB_97bcc694;
  }
  if (nameHash < 0x10f9d) {
    if (nameHash == 0x81d5) goto LAB_97bcc54c;
    if (nameHash < 0x81d6) {
      if (nameHash == 0x5a70) {
LAB_97bcc4ac:
        chunk = _PPStreamChunkCreateWithType(3,0);
        fieldValue = 7;
        chunkWord = *(uint *)(chunk + 0xc);
LAB_97bcc53c:
        chunkWord = fieldValue << 0x10 | chunkWord & 0xffe0ff3f | 0x20;
LAB_97bcbb78:
        *(uint *)(chunk + 0xc) = chunkWord;
        directIndex = ParseSymbol__GetDirectIndex(parseSymbol,0);
        chunkWord = directIndex & 0x1f | *(uint *)(chunk + 0xc) & 0xffffffe0;
      }
      else if (nameHash < 0x5a71) {
        if (nameHash == 0x504e) {
          chunk = _PPStreamChunkCreateWithType(4,0);
          fieldValue = 9;
          chunkWord = *(uint *)(chunk + 0xc);
        }
        else {
          if (nameHash < 0x504f) {
            if (nameHash == 0x4209) {
LAB_97bcc5e0:
              chunkType = 2;
LAB_97bcc64c:
              chunk = _PPStreamChunkCreateWithType(chunkType,0);
              fieldValue = 1;
            }
            else if (nameHash < 0x420a) {
              if (nameHash != 0x383f) {
                if (nameHash < 0x3840) {
                  if (nameHash == 0x280f) {
                    chunkType = 2;
LAB_97bcc5ec:
                    chunk = _PPStreamChunkCreateWithType(chunkType,0);
                    fieldValue = 4;
                    goto LAB_97bcc658;
                  }
                  if (nameHash < 0x2810) {
                    if (nameHash != 0x2099) goto LAB_97bcc698;
                    chunkType = 2;
                    goto LAB_97bcbba8;
                  }
                  if (nameHash == 0x297a) goto LAB_97bcc5e0;
                  if (nameHash != 0x2c25) goto LAB_97bcc698;
                }
                else if (nameHash != 0x3f94) {
                  if (nameHash < 0x3f95) {
                    if (nameHash != 0x3bf9) goto LAB_97bcc698;
                    chunkType = 4;
                    goto LAB_97bcc64c;
                  }
                  if (nameHash == 0x41d9) {
                    chunk = _PPStreamChunkCreateWithType(3,0);
                    fieldValue = 0xb;
                    goto LAB_97bcc5c0;
                  }
                  if (nameHash != 0x4203) goto LAB_97bcc698;
                  chunk = _PPStreamChunkCreateWithType(4,0);
                  fieldValue = 7;
                  goto LAB_97bcc658;
                }
LAB_97bcc5b0:
                chunk = _PPStreamChunkCreateWithType(3,0);
                fieldValue = 0xc;
                goto LAB_97bcc5c0;
              }
LAB_97bcbce8:
              chunk = _PPStreamChunkCreateWithType(2,0);
              fieldValue = 5;
            }
            else {
              if (nameHash == 0x4dd3) goto LAB_97bcc034;
              if (0x4dd3 < nameHash) {
                if (nameHash != 0x4ee0) {
                  if (nameHash < 0x4ee1) {
                    if ((nameHash != 0x4eaa) && (nameHash != 0x4ec5)) goto LAB_97bcc698;
                  }
                  else if (nameHash != 0x4efb) {
                    if (nameHash != 0x4fb4) goto LAB_97bcc698;
                    chunk = _PPStreamChunkCreateWithType(4,0);
                    fieldValue = 4;
                    chunkWord = *(uint *)(chunk + 0xc);
LAB_97bcbb08:
                    chunkWord = fieldValue << 0x10 | chunkWord & 0xfff0fffe;
                    goto LAB_97bcc694;
                  }
                }
                chunk = _PPStreamChunkCreateWithType(4,0);
                *(uint *)(chunk + 0xc) = *(uint *)(chunk + 0xc) & 0xfff0ffff | 0x40000;
                directIndex = ParseSymbol__GetDirectIndex(parseSymbol,0);
                chunkWord = (directIndex & 7) << 1 | *(uint *)(chunk + 0xc) & 0xfffffff1;
                goto LAB_97bcc694;
              }
              if (nameHash == 0x42d8) goto LAB_97bcc5b0;
              if (nameHash < 0x42d9) {
                if (nameHash != 0x425a) goto LAB_97bcc698;
                chunk = _PPStreamChunkCreateWithType(4,0);
                fieldValue = 4;
                chunkWord = *(uint *)(chunk + 0xc);
                goto LAB_97bcbb2c;
              }
              if (nameHash == 0x42e3) {
                chunkType = 4;
                goto LAB_97bcc5ec;
              }
              if (nameHash != 0x4493) goto LAB_97bcc698;
              chunkType = 4;
LAB_97bcc668:
              chunk = _PPStreamChunkCreateWithType(chunkType,0);
              fieldValue = 3;
            }
          }
          else {
            if (nameHash != 0x58a1) {
              if (0x58a1 < nameHash) {
                if (nameHash != 0x5a3e) {
                  if (nameHash < 0x5a3f) {
                    if (nameHash != 0x5a21) {
                      if (nameHash < 0x5a22) {
                        hashMatches = nameHash == 0x5a08;
LAB_97bca874:
                        if (!hashMatches) goto LAB_97bcc698;
                      }
                      else if (nameHash != 0x5a25) {
                        hashMatches = nameHash == 0x5a3a;
                        goto LAB_97bca888;
                      }
                      goto LAB_97bcc4e4;
                    }
                  }
                  else {
                    if (nameHash == 0x5a57) goto LAB_97bcc490;
                    if (nameHash < 0x5a58) {
                      if (nameHash != 0x5a42) {
                        hashMatches = nameHash == 0x5a53;
                        goto LAB_97bca8e4;
                      }
                      goto LAB_97bcc4e4;
                    }
                    if (nameHash != 0x5a5b) {
                      hashMatches = nameHash == 0x5a5f;
                      goto LAB_97bca874;
                    }
                  }
                }
                goto LAB_97bcc4c8;
              }
              if (nameHash != 0x5214) {
                if (nameHash < 0x5215) {
                  if (nameHash != 0x51c3) {
                    if (nameHash < 0x51c4) {
                      hashMatches = nameHash == 0x51a8;
                    }
                    else {
                      if (nameHash == 0x51de) goto LAB_97bcbb38;
                      hashMatches = nameHash == 0x51f9;
                    }
LAB_97bca770:
                    if (!hashMatches) goto LAB_97bcc698;
                  }
                }
                else if (nameHash != 0x524a) {
                  if (nameHash < 0x524b) {
                    hashMatches = nameHash == 0x522f;
                    goto LAB_97bca770;
                  }
                  if (nameHash != 0x5265) {
                    if (nameHash != 0x5811) goto LAB_97bcc698;
                    chunk = _PPStreamChunkCreateWithType(3,0);
                    fieldValue = 0x12;
                    goto LAB_97bcc5c0;
                  }
                }
              }
LAB_97bcbb38:
              if (param_2 == 0) {
                chunk = _PPStreamChunkCreateWithType(4,0);
                fieldValue = 6;
                chunkWord = *(uint *)(chunk + 0xc);
              }
              else {
                chunk = _PPStreamChunkCreateWithType(2,0);
                fieldValue = 7;
                chunkWord = *(uint *)(chunk + 0xc);
              }
              chunkWord = fieldValue << 0x10 | chunkWord & 0xfff0ffff;
              goto LAB_97bcbb78;
            }
            chunk = _PPStreamChunkCreateWithType(2,0);
            fieldValue = 0xb;
          }
LAB_97bcc658:
          chunkWord = *(uint *)(chunk + 0xc);
        }
        chunkWord = fieldValue << 0x10 | chunkWord & 0xfff0ffff;
      }
      else {
        if (nameHash == 0x5b05) goto LAB_97bcc490;
        if (nameHash < 0x5b06) {
          if (nameHash != 0x5ab2) {
            if (nameHash < 0x5ab3) {
              if (nameHash == 0x5a91) {
LAB_97bcc490:
                chunk = _PPStreamChunkCreateWithType(3,0);
                fieldValue = 7;
                chunkWord = *(uint *)(chunk + 0xc);
LAB_97bcc518:
                chunkWord = fieldValue << 0x10 | chunkWord & 0xffe0ff1f;
                goto LAB_97bcbb78;
              }
              if (nameHash < 0x5a92) {
                if (nameHash != 0x5a78) {
                  if (0x5a78 < nameHash) {
                    if (nameHash != 0x5a7c) {
                      hashMatches = nameHash == 0x5a8d;
                      goto LAB_97bca8e4;
                    }
                    goto LAB_97bcc4e4;
                  }
                  hashMatches = nameHash == 0x5a74;
LAB_97bca888:
                  if (!hashMatches) goto LAB_97bcc698;
                  goto LAB_97bcc490;
                }
              }
              else {
                if (nameHash == 0x5a99) {
LAB_97bcc4e4:
                  chunk = _PPStreamChunkCreateWithType(3,0);
                  fieldValue = 7;
                  chunkWord = *(uint *)(chunk + 0xc);
                  goto LAB_97bcc58c;
                }
                if (0x5a99 < nameHash) {
                  if (nameHash == 0x5aaa) goto LAB_97bcc4ac;
                  hashMatches = nameHash == 0x5aae;
                  goto LAB_97bca888;
                }
                if (nameHash != 0x5a95) goto LAB_97bcc698;
              }
            }
            else if (nameHash != 0x5acf) {
              if (nameHash < 0x5ad0) {
                if (nameHash == 0x5ac2) goto LAB_97bcc5b0;
                if (nameHash < 0x5ac3) {
                  hashMatches = nameHash == 0x5ab6;
                  goto LAB_97bca874;
                }
                if (nameHash == 0x5ac7) goto LAB_97bcc4ac;
                hashMatches = nameHash == 0x5acb;
                goto LAB_97bca888;
              }
              if (nameHash != 0x5ae8) {
                if (nameHash < 0x5ae9) {
                  if (nameHash == 0x5ad3) goto LAB_97bcc4e4;
                  hashMatches = nameHash == 0x5ae4;
                }
                else {
                  if (nameHash == 0x5aec) goto LAB_97bcc4c8;
                  hashMatches = nameHash == 0x5b01;
                }
LAB_97bca8e4:
                if (!hashMatches) goto LAB_97bcc698;
                goto LAB_97bcc4ac;
              }
              goto LAB_97bcc490;
            }
          }
LAB_97bcc4c8:
          chunk = _PPStreamChunkCreateWithType(3,0);
          fieldValue = 7;
          chunkWord = *(uint *)(chunk + 0xc);
          goto LAB_97bcc564;
        }
        if (nameHash != 0x71c3) {
          if (0x71c3 < nameHash) {
            if (nameHash == 0x7ab2) {
              chunk = _PPStreamChunkCreateWithType(2,0);
              chunkWord = *(uint *)(chunk + 0xc) & 0xfff0ffe3 | 0x70000;
              goto LAB_97bcc190;
            }
            if (nameHash < 0x7ab3) {
              if (nameHash == 0x7a53) goto LAB_97bcbff4;
              if (nameHash < 0x7a54) {
                if (nameHash != 0x7a49) goto LAB_97bcc698;
                chunk = _PPStreamChunkCreateWithType(2,0);
                chunkWord = *(uint *)(chunk + 0xc) & 0xfff0ffe0 | 0x70000;
                goto LAB_97bcc694;
              }
              if (nameHash == 0x7a6c) {
                chunk = _PPStreamChunkCreateWithType(2,0);
                chunkWord = *(uint *)(chunk + 0xc) & 0xfff0ffe1 | 0x70000;
                goto LAB_97bcbb30;
              }
              if (nameHash != 0x7a8f) goto LAB_97bcc698;
              chunk = _PPStreamChunkCreateWithType(2,0);
              uVar5 = *(uint *)(chunk + 0xc) & 0xfff0ffff | 0x70000;
              chunkWord = 2;
            }
            else if (nameHash == 0x7b1b) {
              chunk = _PPStreamChunkCreateWithType(2,0);
              uVar5 = *(uint *)(chunk + 0xc) & 0xfff0ffff | 0x70000;
              chunkWord = 6;
            }
            else if (nameHash < 0x7b1c) {
              if (nameHash == 0x7ad5) {
                chunk = _PPStreamChunkCreateWithType(2,0);
                uVar5 = *(uint *)(chunk + 0xc) & 0xfff0ffff | 0x70000;
                chunkWord = 4;
              }
              else {
                if (nameHash != 0x7af8) goto LAB_97bcc698;
                chunk = _PPStreamChunkCreateWithType(2,0);
                uVar5 = *(uint *)(chunk + 0xc) & 0xfff0ffff | 0x70000;
                chunkWord = 5;
              }
            }
            else {
              if (nameHash != 0x7b3e) {
                fieldValue = 0x81b6;
                goto LAB_97bcab00;
              }
              chunk = _PPStreamChunkCreateWithType(2,0);
              chunkWord = 7;
              uVar5 = *(uint *)(chunk + 0xc) & 0xfff0ffff | 0x70000;
            }
            chunkWord = chunkWord | uVar5 & 0xffffffe0;
            goto LAB_97bcc694;
          }
          if (nameHash != 0x5c79) {
            if (nameHash < 0x5c7a) {
              if (nameHash != 0x5c22) {
                if (nameHash < 0x5c23) {
                  hashMatches = nameHash == 0x5b1e;
                  goto LAB_97bca8e4;
                }
                if (nameHash != 0x5c3f) {
                  hashMatches = nameHash == 0x5c5c;
LAB_97bca914:
                  if (!hashMatches) goto LAB_97bcc698;
                }
              }
            }
            else {
              if (nameHash == 0x6349) {
                chunkType = 4;
                if (param_2 != 0) goto LAB_97bcbce8;
LAB_97bcbba8:
                chunk = _PPStreamChunkCreateWithType(chunkType,0);
                fieldValue = 2;
                goto LAB_97bcc658;
              }
              if (0x6349 < nameHash) {
                if (nameHash != 0x68de) {
                  hashMatches = nameHash == 0x7171;
                  goto LAB_97bcb178;
                }
                chunk = _PPStreamChunkCreateWithType(3,0);
                chunkWord = *(uint *)(chunk + 0xc) & 0xffe08fff | 0x108000;
                fieldValue = 3;
                goto LAB_97bcbe2c;
              }
              if (nameHash != 0x5c96) {
                hashMatches = nameHash == 0x5cb3;
                goto LAB_97bca914;
              }
            }
          }
          chunk = _PPStreamChunkCreateWithType(3,0);
          chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0xa0000;
          goto LAB_97bcc458;
        }
LAB_97bcc034:
        chunk = _PPStreamChunkCreateWithType(3,0);
        fieldValue = 0xd;
LAB_97bcc5c0:
        chunkWord = *(uint *)(chunk + 0xc);
LAB_97bcc00c:
        chunkWord = fieldValue << 0x10 | chunkWord & 0xffe0ffff;
      }
    }
    else if (nameHash == 0xa562) {
      chunk = _PPStreamChunkCreateWithType(3,0);
      chunkWord = *(uint *)(chunk + 0xc) & 0xffe008ff | 0x104100;
    }
    else {
      if (nameHash < 0xa563) {
        if (nameHash == 0x829f) {
LAB_97bcc524:
          chunk = _PPStreamChunkCreateWithType(3,0);
          fieldValue = 8;
          chunkWord = *(uint *)(chunk + 0xc);
          goto LAB_97bcc53c;
        }
        if (nameHash < 0x82a0) {
          if (nameHash != 0x823a) {
            if (0x823a < nameHash) {
              if (nameHash != 0x8261) {
                if (nameHash < 0x8262) {
                  if (nameHash != 0x8242) {
                    if (0x8242 < nameHash) {
                      if (nameHash != 0x8259) {
                        fieldValue = 0x825d;
                        goto LAB_97bcab50;
                      }
                      goto LAB_97bcc524;
                    }
                    if (nameHash != 0x823e) goto LAB_97bcc698;
                    goto LAB_97bcc54c;
                  }
                }
                else {
                  if (nameHash == 0x8280) goto LAB_97bcc500;
                  if (0x8280 < nameHash) {
                    if (nameHash != 0x8284) {
                      fieldValue = 0x8288;
                      goto LAB_97bcab00;
                    }
                    goto LAB_97bcc54c;
                  }
                  if (nameHash != 0x8265) {
                    fieldValue = 0x827c;
                    goto LAB_97bcaba4;
                  }
                }
LAB_97bcc574:
                chunk = _PPStreamChunkCreateWithType(3,0);
                fieldValue = 8;
                chunkWord = *(uint *)(chunk + 0xc);
LAB_97bcc58c:
                chunkWord = fieldValue << 0x10 | chunkWord & 0xffe0ff7f | 0x60;
                goto LAB_97bcbb78;
              }
              goto LAB_97bcc54c;
            }
            if (nameHash == 0x8213) goto LAB_97bcc524;
            if (nameHash < 0x8214) {
              if (nameHash != 0x81f4) {
                if (nameHash < 0x81f5) {
                  fieldValue = 0x81d9;
                }
                else {
                  if (nameHash == 0x81f8) goto LAB_97bcc54c;
                  fieldValue = 0x81fc;
                }
LAB_97bcab00:
                if (nameHash != fieldValue) goto LAB_97bcc698;
                goto LAB_97bcc574;
              }
            }
            else {
              if (nameHash == 0x821b) goto LAB_97bcc54c;
              if (0x821b < nameHash) {
                if (nameHash != 0x821f) {
                  fieldValue = 0x8236;
                  goto LAB_97bcaba4;
                }
                goto LAB_97bcc574;
              }
              fieldValue = 0x8217;
LAB_97bcab50:
              if (nameHash != fieldValue) goto LAB_97bcc698;
            }
          }
          goto LAB_97bcc500;
        }
        if (nameHash == 0x8837) {
LAB_97bcbff4:
          chunk = _PPStreamChunkCreateWithType(3,0);
          fieldValue = 0xf;
          chunkWord = *(uint *)(chunk + 0xc);
          goto LAB_97bcc00c;
        }
        if (0x8837 < nameHash) {
          if (nameHash != 0x9a2c) {
            if (nameHash < 0x9a2d) {
              if (nameHash == 0x92cd) {
                chunk = _PPStreamChunkCreateWithType(3,0);
                chunkWord = *(uint *)(chunk + 0xc) & 0xffe07fff | 0x104000;
LAB_97bcbdf0:
                chunkWord = chunkWord & 0xffffcfff;
                goto LAB_97bcbdf4;
              }
              if (nameHash < 0x92ce) {
                if (nameHash != 0x89f6) goto LAB_97bcc698;
                goto LAB_97bcbff4;
              }
              if (nameHash != 0x99e2) {
                fieldValue = 0x9a07;
                goto LAB_97bcac74;
              }
            }
            else if (nameHash != 0x9a9b) {
              if (nameHash < 0x9a9c) {
                if (nameHash != 0x9a51) {
                  fieldValue = 0x9a76;
LAB_97bcac74:
                  if (nameHash != fieldValue) goto LAB_97bcc698;
                }
              }
              else if (nameHash != 0x9ac0) {
                fieldValue = 0x9ae5;
                goto LAB_97bcac74;
              }
            }
          }
          chunk = _PPStreamChunkCreateWithType(3,0);
          chunkWord = *(uint *)(chunk + 0xc) & 0xffe07fff | 0x104000;
LAB_97bcbe80:
          chunkWord = chunkWord & 0xffffcfff;
          goto LAB_97bcbe84;
        }
        if (nameHash == 0x82c6) {
LAB_97bcc500:
          chunk = _PPStreamChunkCreateWithType(3,0);
          fieldValue = 8;
          chunkWord = *(uint *)(chunk + 0xc);
          goto LAB_97bcc518;
        }
        if (nameHash < 0x82c7) {
          if (nameHash != 0x82a7) {
            if (nameHash < 0x82a8) {
              fieldValue = 0x82a3;
              goto LAB_97bcab50;
            }
            if (nameHash == 0x82ab) goto LAB_97bcc574;
            fieldValue = 0x82c2;
LAB_97bcaba4:
            if (nameHash != fieldValue) goto LAB_97bcc698;
            goto LAB_97bcc524;
          }
        }
        else {
          if (nameHash == 0x82e9) goto LAB_97bcc500;
          if (0x82e9 < nameHash) {
            if (nameHash != 0x8308) {
              if (nameHash != 0x840f) goto LAB_97bcc698;
              chunkType = 2;
              goto LAB_97bcc668;
            }
            goto LAB_97bcc524;
          }
          if (nameHash != 0x82ca) {
            fieldValue = 0x82e5;
            goto LAB_97bcaba4;
          }
        }
LAB_97bcc54c:
        chunk = _PPStreamChunkCreateWithType(3,0);
        fieldValue = 8;
        chunkWord = *(uint *)(chunk + 0xc);
LAB_97bcc564:
        chunkWord = fieldValue << 0x10 | chunkWord & 0xffe0ff1f | 0x40;
        goto LAB_97bcbb78;
      }
      if (nameHash != 0xe1f0) {
        if (0xe1f0 < nameHash) {
          if (nameHash != 0x1021f) {
            if (0x1021f < nameHash) {
              if (nameHash != 0x1029a) {
                if (nameHash < 0x1029b) {
                  if (nameHash == 0x10240) goto LAB_97bcc1e8;
                  if (nameHash < 0x10241) {
                    fieldValue = 0x10237;
                  }
                  else {
                    if (nameHash == 0x10258) goto LAB_97bcc20c;
                    fieldValue = 0x10279;
                  }
LAB_97bcaf2c:
                  if (nameHash != fieldValue) goto LAB_97bcc698;
                }
                else if (nameHash != 0x102fd) {
                  if (nameHash < 0x102fe) {
                    if (nameHash != 0x102bb) {
                      fieldValue = 0x102dc;
                      goto LAB_97bcaf2c;
                    }
                  }
                  else if (nameHash != 0x1031e) {
                    if (nameHash != 0x10f0d) goto LAB_97bcc698;
                    chunk = _PPStreamChunkCreateWithType(3,0);
                    chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fffe | 0x50000;
                    goto LAB_97bcc1b8;
                  }
                }
              }
LAB_97bcc20c:
              chunk = _PPStreamChunkCreateWithType(3,0);
              chunkWord = *(uint *)(chunk + 0xc) & 0xffe0f1ff | 0x30100;
              goto LAB_97bcc458;
            }
            if (nameHash != 0x10159) {
              if (nameHash < 0x1015a) {
                if (nameHash == 0xf7d2) {
                  chunk = _PPStreamChunkCreateWithType(3,0);
                  chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fffe | 0x50000;
                  fieldValue = 1;
                  goto LAB_97bcc0cc;
                }
                if (nameHash < 0xf7d3) {
                  if (nameHash != 0xf700) goto LAB_97bcc698;
                  chunk = _PPStreamChunkCreateWithType(3,0);
                  chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fff0 | 0x50000;
                }
                else {
                  if (nameHash == 0xf839) {
                    chunk = _PPStreamChunkCreateWithType(3,0);
                    chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x50001;
LAB_97bcc1b8:
                    fieldValue = 2;
                    goto LAB_97bcc0cc;
                  }
                  if (nameHash != 0xf9fd) goto LAB_97bcc698;
                  chunk = _PPStreamChunkCreateWithType(3,0);
                  chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fff7 | 0x50007;
                }
                goto LAB_97bcc694;
              }
              if (nameHash != 0x101bc) {
                if (nameHash < 0x101bd) {
                  if (nameHash != 0x1017a) {
                    fieldValue = 0x1019b;
LAB_97bcaea4:
                    if (nameHash != fieldValue) goto LAB_97bcc698;
                  }
                }
                else if (nameHash != 0x101dd) {
                  fieldValue = 0x101fe;
                  goto LAB_97bcaea4;
                }
              }
            }
          }
LAB_97bcc1e8:
          chunk = _PPStreamChunkCreateWithType(3,0);
          chunkWord = *(uint *)(chunk + 0xc) & 0xffe0f0ff | 0x30000;
          goto LAB_97bcc458;
        }
        if (nameHash != 0xb938) {
          if (nameHash < 0xb939) {
            if (nameHash != 0xb86b) {
              if (nameHash < 0xb86c) {
                if (nameHash != 0xb7f0) {
                  if (nameHash < 0xb7f1) {
                    fieldValue = 0xb7c7;
                  }
                  else {
                    if (nameHash == 0xb819) goto LAB_97bcc470;
                    fieldValue = 0xb842;
                  }
LAB_97bcadb8:
                  if (nameHash != fieldValue) goto LAB_97bcc698;
                }
              }
              else if (nameHash != 0xb8bd) {
                if (nameHash < 0xb8be) {
                  fieldValue = 0xb894;
                }
                else {
                  if (nameHash == 0xb8e6) goto LAB_97bcc470;
                  fieldValue = 0xb90f;
                }
                goto LAB_97bcadb8;
              }
            }
          }
          else if (nameHash != 0xc13b) {
            if (0xc13b < nameHash) {
              if (nameHash == 0xc310) {
                chunk = _PPStreamChunkCreateWithType(4,0);
                fieldValue = 5;
                chunkWord = *(uint *)(chunk + 0xc);
LAB_97bcbb2c:
                chunkWord = fieldValue << 0x10 | chunkWord & 0xfff0ffff;
LAB_97bcbb30:
                chunkWord = chunkWord | 1;
              }
              else {
                if (nameHash < 0xc311) {
                  if (nameHash != 0xc166) {
                    fieldValue = 0xc191;
                    goto LAB_97bcadb8;
                  }
                  goto LAB_97bcc470;
                }
                if (nameHash == 0xd7ba) {
                  chunk = _PPStreamChunkCreateWithType(4,0);
                  fieldValue = 5;
                  chunkWord = *(uint *)(chunk + 0xc);
                  goto LAB_97bcbb08;
                }
                if (nameHash != 0xe12a) goto LAB_97bcc698;
                chunk = _PPStreamChunkCreateWithType(3,0);
                chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fff1 | 0x50001;
              }
              goto LAB_97bcc694;
            }
            if (nameHash != 0xc0ba) {
              if (nameHash < 0xc0bb) {
                if (nameHash != 0xbd41) goto LAB_97bcc698;
                chunk = _PPStreamChunkCreateWithType(3,0);
                fieldValue = 6;
                goto LAB_97bcc5c0;
              }
              if (nameHash != 0xc0e5) {
                fieldValue = 0xc110;
                goto LAB_97bcadb8;
              }
            }
          }
        }
LAB_97bcc470:
        chunk = _PPStreamChunkCreateWithType(3,0);
        chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x90000;
        goto LAB_97bcbb78;
      }
      chunk = _PPStreamChunkCreateWithType(3,0);
      chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fff3 | 0x50000;
LAB_97bcc190:
      chunkWord = chunkWord | 3;
    }
LAB_97bcc694:
    *(uint *)(chunk + 0xc) = chunkWord;
    goto LAB_97bcc698;
  }
  if (nameHash == 0x18b0a) goto LAB_97bcc36c;
  if (nameHash < 0x18b0b) {
    if (nameHash == 0x147c7) goto LAB_97bcc2a0;
    if (0x147c7 < nameHash) {
      if (nameHash == 0x1705e) goto LAB_97bcc3e4;
      if (0x1705e < nameHash) {
        if (nameHash != 0x17e27) {
          if (nameHash < 0x17e28) {
            if (nameHash != 0x170f7) {
              if (nameHash < 0x170f8) {
                if (nameHash == 0x17089) goto LAB_97bcc3e4;
                if (nameHash < 0x1708a) {
                  fieldValue = 0x17076;
                }
                else {
                  if (nameHash == 0x170a1) goto LAB_97bcc40c;
                  fieldValue = 0x170cc;
                }
LAB_97bcb448:
                if (nameHash != fieldValue) goto LAB_97bcc698;
              }
              else if (nameHash != 0x17178) {
                if (nameHash < 0x17179) {
                  if (nameHash != 0x17122) {
                    fieldValue = 0x1714d;
                    goto LAB_97bcb448;
                  }
                }
                else if (nameHash != 0x171a3) {
                  fieldValue = 0x17e06;
                  goto LAB_97bcba88;
                }
              }
            }
LAB_97bcc40c:
            chunk = _PPStreamChunkCreateWithType(3,0);
            chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fbff | 0x40300;
            goto LAB_97bcc458;
          }
          if (nameHash != 0x17ecc) {
            if (0x17ecc < nameHash) {
              if (nameHash != 0x18a83) {
                if (nameHash < 0x18a84) {
                  if (nameHash == 0x17eed) goto LAB_97bcc2ec;
                  fieldValue = 0x18a56;
                }
                else {
                  if (nameHash == 0x18ab0) goto LAB_97bcc36c;
                  fieldValue = 0x18add;
                }
LAB_97bcb594:
                if (nameHash != fieldValue) goto LAB_97bcc698;
              }
LAB_97bcc36c:
              chunk = _PPStreamChunkCreateWithType(3,0);
              chunkWord = *(uint *)(chunk + 0xc) & 0xffe0f8ff | 0x40000;
              goto LAB_97bcc458;
            }
            if (nameHash != 0x17e69) {
              if (nameHash < 0x17e6a) {
                fieldValue = 0x17e48;
              }
              else {
                if (nameHash == 0x17e8a) goto LAB_97bcc2ec;
                fieldValue = 0x17eab;
              }
LAB_97bcba88:
              if (nameHash != fieldValue) goto LAB_97bcc698;
            }
          }
        }
        goto LAB_97bcc2ec;
      }
      if (nameHash != 0x14d24) {
        if (0x14d24 < nameHash) {
          if (nameHash != 0x16f5c) {
            if (nameHash < 0x16f5d) {
              if (nameHash != 0x14d92) {
                if (0x14d92 < nameHash) {
                  if (nameHash == 0x158fc) {
                    chunk = _PPStreamChunkCreateWithType(3,0);
                    chunkWord = *(uint *)(chunk + 0xc) & 0xffe07fff | 0x104000;
LAB_97bcbe54:
                    chunkWord = chunkWord & 0xffffcfff;
LAB_97bcbfa8:
                    chunkWord = chunkWord & 0xfffff8ff;
                    goto LAB_97bcbfac;
                  }
                  if (nameHash != 0x15dbb) goto LAB_97bcc698;
                  chunk = _PPStreamChunkCreateWithType(3,0);
                  chunkWord = *(uint *)(chunk + 0xc) & 0xffe00fff | 0x100000;
                  goto LAB_97bcbe28;
                }
                fieldValue = 0x14d5b;
                goto LAB_97bcb334;
              }
              goto LAB_97bcbf0c;
            }
            if (nameHash != 0x16fdd) {
              if (nameHash < 0x16fde) {
                if (nameHash != 0x16f87) {
                  fieldValue = 0x16fb2;
LAB_97bcb3ac:
                  if (nameHash != fieldValue) goto LAB_97bcc698;
                }
              }
              else if (nameHash != 0x17008) {
                fieldValue = 0x17033;
                goto LAB_97bcb3ac;
              }
            }
          }
LAB_97bcc3e4:
          chunk = _PPStreamChunkCreateWithType(3,0);
          chunkWord = *(uint *)(chunk + 0xc) & 0xffe0f9ff | 0x40100;
          goto LAB_97bcc458;
        }
        if (nameHash != 0x14c11) {
          if (nameHash < 0x14c12) {
            if (nameHash != 0x14809) {
              if (nameHash < 0x1480a) {
                fieldValue = 0x147e8;
              }
              else {
                if (nameHash == 0x1482a) goto LAB_97bcc2a0;
                fieldValue = 0x1484b;
              }
LAB_97bcb2bc:
              if (nameHash != fieldValue) goto LAB_97bcc698;
            }
            goto LAB_97bcc2a0;
          }
          if (nameHash != 0x14c7f) {
            if (nameHash < 0x14c80) {
              fieldValue = 0x14c48;
            }
            else {
              if (nameHash == 0x14cb6) goto LAB_97bcbf0c;
              fieldValue = 0x14ced;
            }
LAB_97bcb334:
            if (nameHash != fieldValue) goto LAB_97bcc698;
          }
        }
      }
LAB_97bcbf0c:
      chunk = _PPStreamChunkCreateWithType(3,0);
      chunkWord = *(uint *)(chunk + 0xc) & 0xffe00fff | 0x100000;
LAB_97bcbe84:
      chunkWord = chunkWord & 0xfffff8ff | 0x400;
      goto LAB_97bcc458;
    }
    if (nameHash == 0x11ea4) goto LAB_97bcc258;
    if (nameHash < 0x11ea5) {
      if (nameHash != 0x11b4b) {
        if (0x11b4b < nameHash) {
          if (nameHash != 0x11d4e) {
            if (nameHash < 0x11d4f) {
              if (nameHash != 0x11cb5) {
                if (nameHash < 0x11cb6) {
                  fieldValue = 0x11c82;
                }
                else {
                  if (nameHash == 0x11ce8) goto LAB_97bcbe60;
                  fieldValue = 0x11d1b;
                }
LAB_97bcb0c4:
                if (nameHash != fieldValue) goto LAB_97bcc698;
              }
            }
            else if (nameHash != 0x11de7) {
              if (0x11de7 < nameHash) {
                if (nameHash != 0x11e62) {
                  fieldValue = 0x11e83;
                  goto LAB_97bcb14c;
                }
                goto LAB_97bcc258;
              }
              if (nameHash != 0x11d81) {
                fieldValue = 0x11db4;
                goto LAB_97bcb0c4;
              }
            }
          }
LAB_97bcbe60:
          chunk = _PPStreamChunkCreateWithType(3,0);
          chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x10c000;
          goto LAB_97bcbe80;
        }
        if (nameHash != 0x11aa6) {
          if (nameHash < 0x11aa7) {
            if (nameHash == 0x1142d) {
              chunk = _PPStreamChunkCreateWithType(3,0);
              chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x10c000;
              goto LAB_97bcbdf0;
            }
            if (nameHash < 0x1142e) {
              if (nameHash != 0x110e1) goto LAB_97bcc698;
              chunk = _PPStreamChunkCreateWithType(3,0);
              chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fffe | 0x50000;
              fieldValue = 3;
              goto LAB_97bcc0cc;
            }
            if (nameHash != 0x11a64) {
              fieldValue = 0x11a85;
              goto LAB_97bcb03c;
            }
          }
          else if (nameHash != 0x11ae8) {
            if (nameHash < 0x11ae9) {
              fieldValue = 0x11ac7;
            }
            else {
              if (nameHash == 0x11b09) goto LAB_97bcc234;
              fieldValue = 0x11b2a;
            }
LAB_97bcb03c:
            if (nameHash != fieldValue) goto LAB_97bcc698;
          }
        }
      }
LAB_97bcc234:
      chunk = _PPStreamChunkCreateWithType(3,0);
      chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x30000;
      fieldValue = 2;
    }
    else {
      if (nameHash != 0x14328) {
        if (nameHash < 0x14329) {
          if (nameHash != 0x11f49) {
            if (0x11f49 < nameHash) {
              if (nameHash == 0x1275a) {
                chunk = _PPStreamChunkCreateWithType(3,0);
                chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fff8 | 0x50008;
                goto LAB_97bcc694;
              }
              if (nameHash < 0x1275b) {
                hashMatches = nameHash == 0x12304;
LAB_97bcb178:
                if (!hashMatches) goto LAB_97bcc698;
                goto LAB_97bcc034;
              }
              if (nameHash == 0x12c7a) {
                chunk = _PPStreamChunkCreateWithType(3,0);
                chunkWord = *(uint *)(chunk + 0xc) & 0xffe0cfff | 0x10c000;
                goto LAB_97bcbe28;
              }
              fieldValue = 0x14307;
              goto LAB_97bcb220;
            }
            if (nameHash != 0x11ee6) {
              if (nameHash < 0x11ee7) {
                fieldValue = 0x11ec5;
              }
              else {
                if (nameHash == 0x11f07) goto LAB_97bcc258;
                fieldValue = 0x11f28;
              }
LAB_97bcb14c:
              if (nameHash != fieldValue) goto LAB_97bcc698;
            }
          }
LAB_97bcc258:
          chunk = _PPStreamChunkCreateWithType(3,0);
          fieldValue = 3;
          chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x30000;
          goto LAB_97bcc274;
        }
        if (nameHash != 0x143ac) {
          if (0x143ac < nameHash) {
            if (nameHash != 0x14764) {
              if (nameHash < 0x14765) {
                if (nameHash != 0x143cd) {
                  fieldValue = 0x143ee;
                  goto LAB_97bcb220;
                }
                goto LAB_97bcc27c;
              }
              if (nameHash != 0x14785) {
                fieldValue = 0x147a6;
                goto LAB_97bcb2bc;
              }
            }
LAB_97bcc2a0:
            chunk = _PPStreamChunkCreateWithType(3,0);
            chunkWord = *(uint *)(chunk + 0xc) & 0xffe0f7ff | 0x30700;
            goto LAB_97bcc458;
          }
          if (nameHash != 0x1436a) {
            if (nameHash < 0x1436b) {
              fieldValue = 0x14349;
LAB_97bcb220:
              if (nameHash != fieldValue) goto LAB_97bcc698;
            }
            else if (nameHash != 0x1438b) {
              if (nameHash != 0x143a8) goto LAB_97bcc698;
              chunk = _PPStreamChunkCreateWithType(3,0);
              chunkWord = *(uint *)(chunk + 0xc) & 0xffe00fff | 0x100000;
              goto LAB_97bcbdf4;
            }
          }
        }
      }
LAB_97bcc27c:
      chunk = _PPStreamChunkCreateWithType(3,0);
      chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x30000;
      fieldValue = 6;
    }
LAB_97bcc274:
    chunkWord = fieldValue << 8 | chunkWord & 0xfffff0ff;
  }
  else {
    if (nameHash == 0x1aa90) goto LAB_97bcc3bc;
    if (0x1aa90 < nameHash) {
      if (nameHash == 0x21945) {
        chunk = _PPStreamChunkCreateWithType(3,0);
        chunkWord = *(uint *)(chunk + 0xc) & 0xffe08fff | 0x108000;
LAB_97bcbe28:
        fieldValue = 1;
LAB_97bcbe2c:
        chunkWord = fieldValue << 8 | chunkWord & 0xfffff8ff;
        goto LAB_97bcc694;
      }
      if (nameHash < 0x21946) {
        if (nameHash != 0x203d7) {
          if (nameHash < 0x203d8) {
            if (nameHash == 0x20368) goto LAB_97bcbfb8;
            if (nameHash < 0x20369) {
              if (nameHash == 0x1f97a) {
                chunk = _PPStreamChunkCreateWithType(3,0);
                chunkWord = *(uint *)(chunk + 0xc) & 0xffe08fff | 0x108000;
LAB_97bcbdf4:
                chunkWord = chunkWord & 0xfffff8ff | 0x300;
LAB_97bcbfac:
                *(uint *)(chunk + 0xc) = chunkWord;
                *(undefined1 *)(chunk + 0xf) = 0;
                goto LAB_97bcc698;
              }
              if (0x1f97a < nameHash) {
                if (nameHash == 0x1ff52) {
                  chunk = _PPStreamChunkCreateWithType(3,0);
                  fieldValue = 5;
                  chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x50001;
                  goto LAB_97bcc0cc;
                }
                fieldValue = 0x20323;
                goto LAB_97bcb91c;
              }
              if (nameHash != 0x1f1a8) goto LAB_97bcc698;
              goto LAB_97bcc048;
            }
            if (nameHash != 0x20395) {
              if (nameHash < 0x20396) {
                fieldValue = 0x20374;
              }
              else {
                if (nameHash == 0x203ad) goto LAB_97bcbfb8;
                fieldValue = 0x203b6;
              }
              goto LAB_97bcba88;
            }
          }
          else if (nameHash != 0x2043a) {
            if (nameHash < 0x2043b) {
              if (nameHash == 0x203f8) goto LAB_97bcc2ec;
              if (nameHash < 0x203f9) {
                fieldValue = 0x203f2;
              }
              else {
                if (nameHash == 0x20419) goto LAB_97bcc2ec;
                fieldValue = 0x20437;
              }
LAB_97bcb91c:
              if (nameHash != fieldValue) goto LAB_97bcc698;
            }
            else if (nameHash != 0x204c1) {
              if (nameHash < 0x204c2) {
                if (nameHash != 0x2045b) {
                  fieldValue = 0x2047c;
                  goto LAB_97bcb91c;
                }
                goto LAB_97bcc2ec;
              }
              if (nameHash != 0x20506) {
                if (nameHash != 0x2138c) goto LAB_97bcc698;
                chunk = _PPStreamChunkCreateWithType(3,0);
                chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x10c000;
                goto LAB_97bcbe54;
              }
            }
LAB_97bcbfb8:
            chunk = _PPStreamChunkCreateWithType(3,0);
            chunkWord = *(uint *)(chunk + 0xc) & 0xffe08fff | 0x108000;
            goto LAB_97bcbe84;
          }
        }
      }
      else {
        if (nameHash == 0x24cb9) {
LAB_97bcc048:
          chunk = _PPStreamChunkCreateWithType(3,0);
          fieldValue = 0xe;
          goto LAB_97bcc5c0;
        }
        if (nameHash < 0x24cba) {
          if (nameHash != 0x2461d) {
            if (nameHash < 0x2461e) {
              if (nameHash == 0x23231) goto LAB_97bcc048;
              if (nameHash < 0x23232) {
                if (nameHash != 0x21eb8) goto LAB_97bcc698;
                chunk = _PPStreamChunkCreateWithType(3,0);
                fieldValue = 5;
                chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fffe | 0x50000;
LAB_97bcc0cc:
                chunkWord = fieldValue << 1 | chunkWord & 0xfffffff1;
                goto LAB_97bcc694;
              }
              if (nameHash != 0x245db) {
                fieldValue = 0x245fc;
                goto LAB_97bcba88;
              }
            }
            else if (nameHash != 0x24680) {
              if (nameHash < 0x24681) {
                if (nameHash != 0x2463e) {
                  fieldValue = 0x2465f;
                  goto LAB_97bcba88;
                }
              }
              else if (nameHash != 0x246a1) {
                fieldValue = 0x246c2;
                goto LAB_97bcba88;
              }
            }
          }
        }
        else if (nameHash != 0x2616e) {
          if (nameHash < 0x2616f) {
            if (nameHash != 0x2610b) {
              if (nameHash < 0x2610c) {
                if (nameHash == 0x254c3) {
                  chunk = _PPStreamChunkCreateWithType(3,0);
                  *(uint *)(chunk + 0xc) = *(uint *)(chunk + 0xc) & 0xffe008ff | 0x100000;
                  *(undefined1 *)(chunk + 0xf) = 0;
                }
                goto LAB_97bcc698;
              }
              if (nameHash != 0x2612c) {
                fieldValue = 0x2614d;
                goto LAB_97bcba88;
              }
            }
          }
          else if (nameHash != 0x261d1) {
            if (nameHash < 0x261d2) {
              if (nameHash != 0x2618f) {
                fieldValue = 0x261b0;
                goto LAB_97bcba88;
              }
            }
            else if (nameHash != 0x261f2) {
              if (nameHash != 0x343c5) goto LAB_97bcc698;
              chunk = _PPStreamChunkCreateWithType(3,0);
              chunkWord = *(uint *)(chunk + 0xc) & 0xffe08fff | 0x108000;
              goto LAB_97bcbfa8;
            }
          }
        }
      }
LAB_97bcc2ec:
      chunk = _PPStreamChunkCreateWithType(3,0);
      chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x30000;
      fieldValue = 5;
      goto LAB_97bcc274;
    }
    if (nameHash == 0x18e85) {
LAB_97bcc2c8:
      chunk = _PPStreamChunkCreateWithType(3,0);
      chunkWord = *(uint *)(chunk + 0xc) & 0xffe0ffff | 0x30000;
      fieldValue = 4;
      goto LAB_97bcc274;
    }
    if (0x18e85 < nameHash) {
      if (nameHash != 0x19384) {
        if (0x19384 < nameHash) {
          if (nameHash != 0x1a982) {
            if (nameHash < 0x1a983) {
              if (nameHash != 0x193c6) {
                if (nameHash < 0x193c7) {
                  fieldValue = 0x193a5;
                  goto LAB_97bcb768;
                }
                if (nameHash != 0x193e7) {
                  fieldValue = 0x1a955;
                  goto LAB_97bcb7d8;
                }
              }
              goto LAB_97bcc2c8;
            }
            if (nameHash != 0x1aa09) {
              if (nameHash < 0x1aa0a) {
                if (nameHash != 0x1a9af) {
                  fieldValue = 0x1a9dc;
LAB_97bcb7d8:
                  if (nameHash != fieldValue) goto LAB_97bcc698;
                }
              }
              else if (nameHash != 0x1aa36) {
                fieldValue = 0x1aa63;
                goto LAB_97bcb7d8;
              }
            }
          }
LAB_97bcc3bc:
          chunk = _PPStreamChunkCreateWithType(3,0);
          chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fcff | 0x40400;
          goto LAB_97bcc458;
        }
        if (nameHash != 0x18f09) {
          if (nameHash < 0x18f0a) {
            if (nameHash != 0x18ea6) {
              if (nameHash < 0x18ea7) {
                fieldValue = 0x18e8a;
                goto LAB_97bcb6c4;
              }
              if (nameHash != 0x18ec7) {
                fieldValue = 0x18ee8;
                goto LAB_97bcb768;
              }
            }
          }
          else if (nameHash != 0x19321) {
            if (nameHash < 0x19322) {
              if (nameHash != 0x18f2a) {
                fieldValue = 0x19300;
LAB_97bcb768:
                if (nameHash != fieldValue) goto LAB_97bcc698;
              }
            }
            else if (nameHash != 0x19342) {
              fieldValue = 0x19363;
              goto LAB_97bcb768;
            }
          }
        }
      }
      goto LAB_97bcc2c8;
    }
    if (nameHash != 0x18c8a) {
      if (0x18c8a < nameHash) {
        if (nameHash != 0x18dde) {
          if (nameHash < 0x18ddf) {
            if (nameHash != 0x18d5d) {
              if (nameHash < 0x18d5e) {
                fieldValue = 0x18cb7;
                goto LAB_97bcb60c;
              }
              if (nameHash != 0x18d88) {
                fieldValue = 0x18db3;
LAB_97bcb6c4:
                if (nameHash != fieldValue) goto LAB_97bcc698;
              }
            }
          }
          else {
            if (nameHash == 0x18e43) goto LAB_97bcc2c8;
            if (nameHash < 0x18e44) {
              if (nameHash != 0x18e09) {
                fieldValue = 0x18e34;
                goto LAB_97bcb6c4;
              }
            }
            else if (nameHash != 0x18e5f) {
              fieldValue = 0x18e64;
              goto LAB_97bcb768;
            }
          }
        }
        chunk = _PPStreamChunkCreateWithType(3,0);
        chunkWord = *(uint *)(chunk + 0xc) & 0xffe0fdff | 0x40500;
        goto LAB_97bcc458;
      }
      if (nameHash != 0x18ba9) {
        if (nameHash < 0x18baa) {
          if (nameHash == 0x18b64) goto LAB_97bcc36c;
          if (nameHash < 0x18b65) {
            fieldValue = 0x18b37;
          }
          else {
            if (nameHash == 0x18b7c) goto LAB_97bcc390;
            fieldValue = 0x18b91;
          }
          goto LAB_97bcb594;
        }
        if (nameHash != 0x18c03) {
          if (nameHash < 0x18c04) {
            fieldValue = 0x18bd6;
          }
          else {
            if (nameHash == 0x18c30) goto LAB_97bcc390;
            fieldValue = 0x18c5d;
          }
LAB_97bcb60c:
          if (nameHash != fieldValue) goto LAB_97bcc698;
        }
      }
    }
LAB_97bcc390:
    chunk = _PPStreamChunkCreateWithType(3,0);
    chunkWord = *(uint *)(chunk + 0xc) & 0xffe0f8ff | 0x40200;
  }
LAB_97bcc458:
  *(uint *)(chunk + 0xc) = chunkWord;
  directIndex2 = ParseSymbol__GetDirectIndex(parseSymbol,0);
  *(undefined1 *)(chunk + 0xf) = directIndex2;
LAB_97bcc698:
  *(undefined4 *)(parseSymbol + 0x34) = 1;
  return chunk;
}

/* GetChunkForSymbol @ 0x97bcc6b8 (592 bytes) */
int GetChunkForSymbol(parseSymbol, param_2)
  unsigned char * parseSymbol;
  int param_2;
{
  uint builtInInitialSwizzle;
  uint streamType;
  int scalerWidthForType;
  bool bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  
  iVar8 = *(int *)(parseSymbol + 0x14);
  if (((iVar8 == 0) || (iVar4 = _memcmp(iVar8,"gl_",3), iVar4 != 0)) ||
     (*(char *)(iVar8 + 3) == '_')) {
    uVar6 = (**(code **)(**(int **)(parseSymbol + 0xc) + 0x24))(*(int **)(parseSymbol + 0xc));
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
      iVar8 = (**(code **)(**(int **)(parseSymbol + 0xc) + 0x20))(*(int **)(parseSymbol + 0xc));
      *(uint *)(pbVar5 + 0x10) =
           (uint)(iVar8 - 5U < 8) << 0x1f | *(uint *)(pbVar5 + 0x10) & 0x7fffffff;
      break;
    default:
      pbVar5 = (byte *)0x0;
    }
  }
  else {
    pbVar5 = (byte *)((int (*)())GetBuiltInChunkForSymbol)(parseSymbol,param_2);
    *(undefined4 *)(parseSymbol + 0x38) = 1;
    *(undefined4 *)(parseSymbol + 0x28) = 0xffffffff;
  }
  if (pbVar5 == (byte *)0x0) goto LAB_97bcc8c4;
  bVar2 = *pbVar5;
  if (bVar2 == 2) {
LAB_97bcc864:
    streamType = GetPPStreamTypeForGLType((uint)*(ushort *)(parseSymbol + 0x2c));
    *(uint *)(pbVar5 + 0xc) = (streamType & 7) << 0x1a | *(uint *)(pbVar5 + 0xc) & 0xe3ffffff;
    scalerWidthForType = GetScalerWidthForType((uint)*(ushort *)(parseSymbol + 0x2c));
    uVar7 = (scalerWidthForType + -1) * 0x1000000 & 0x3000000U | *(uint *)(pbVar5 + 0xc) & 0x1cffffff;
LAB_97bcc8c0:
    *(uint *)(pbVar5 + 0xc) = uVar7;
  }
  else if (bVar2 < 3) {
    if (bVar2 == 0) {
      streamType = GetPPStreamTypeForGLType((uint)*(ushort *)(parseSymbol + 0x2c));
      *(uint *)(pbVar5 + 0xc) = (streamType & 7) << 0x1a | *(uint *)(pbVar5 + 0xc) & 0xe3ffffff;
      scalerWidthForType = GetScalerWidthForType((uint)*(ushort *)(parseSymbol + 0x2c));
      uVar7 = (scalerWidthForType + -1) * 0x1000000 & 0x3000000U | *(uint *)(pbVar5 + 0xc) & 0x1cffffff;
      goto LAB_97bcc8c0;
    }
  }
  else if ((bVar2 == 3) || (bVar2 == 4)) goto LAB_97bcc864;
LAB_97bcc8c4:
  if (*(int *)(parseSymbol + 0x34) == 0) {
    return pbVar5;
  }
  builtInInitialSwizzle = ((int (*)())GetBuiltInInitialSwizzle)(parseSymbol);
  if (builtInInitialSwizzle == 0) {
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
  if (uVar3 < builtInInitialSwizzle) {
    uVar3 = builtInInitialSwizzle;
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
  return ((int (*)())__ZN13FunctionTableC4Ev)(this);
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
  return ((int (*)())__ZN13FunctionTableD4Ev)(this);
}

/* __ZN13FunctionTableD1Ev @ 0x97bcc95c (8 bytes) */
int __ZN13FunctionTableD1Ev(this)
  void *this;
{
  return ((int (*)())__ZN13FunctionTableD4Ev)(this);
}

/* __ZN13FunctionTableD4Ev @ 0x97bcc964 (4 bytes) */
int __ZN13FunctionTableD4Ev(this)
  void *this;
{
  return ((int (*)())FunctionTable__clear)(this);
}

/* FunctionTable__clear @ 0x97bcc968 (120 bytes) */
int FunctionTable__clear(this)
  unsigned char * this;
{
  undefined4 *puVar1;
  int loopIndex;
  int iVar3;
  
  loopIndex = 0;
  if (0 < *(int *)(this + 4)) {
    iVar3 = 0;
    do {
      loopIndex = loopIndex + 1;
      puVar1 = (undefined4 *)(iVar3 + *(int *)this);
      iVar3 = iVar3 + 0x18;
      _free(*puVar1);
    } while (loopIndex < *(int *)(this + 4));
  }
  if (*(int *)this != 0) {
    _free(*(int *)this);
  }
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* FunctionTable__addFunction @ 0x97bcc9e0 (284 bytes) */
int FunctionTable__addFunction(this, str)
  unsigned char * this;
  char *str;
{
  int loopIndex;
  undefined4 allocation2;
  int length;
  int allocation;
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
    allocation = _malloc(uVar10 * 0x18 + 0x180);
    _memset(allocation,0,*(int *)(this + 4) * 0x18 + 0x180);
    uVar10 = *(uint *)(this + 4);
    loopIndex = 0;
    if ((int)uVar10 < 1) {
      iVar3 = *(int *)this;
    }
    else {
      iVar3 = *(int *)this;
      iVar5 = 0;
      do {
        iVar9 = iVar5 + iVar3;
        uVar7 = *(undefined4 *)(iVar9 + 4);
        loopIndex = loopIndex + 1;
        uVar8 = *(undefined4 *)(iVar9 + 8);
        iVar1 = iVar5 + allocation;
        uVar6 = *(undefined4 *)(iVar9 + 0xc);
        *(undefined4 *)(iVar5 + allocation) = *(undefined4 *)(iVar5 + iVar3);
        iVar5 = iVar5 + 0x18;
        *(undefined4 *)(iVar1 + 4) = uVar7;
        *(undefined4 *)(iVar1 + 8) = uVar8;
        *(undefined4 *)(iVar1 + 0xc) = uVar6;
        uVar6 = *(undefined4 *)(iVar9 + 0x10);
        *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(iVar9 + 0x14);
        *(undefined4 *)(iVar1 + 0x10) = uVar6;
      } while (loopIndex < (int)uVar10);
    }
    if (iVar3 != 0) {
      _free(iVar3);
      uVar10 = *(uint *)(this + 4);
    }
    *(int *)this = allocation;
  }
  iVar4 = *(int *)this;
  length = _strlen(str);
  allocation2 = _malloc(length + 1);
  *(undefined4 *)(uVar10 * 0x18 + iVar4) = allocation2;
  _strcpy(*(undefined4 *)(*(int *)(this + 4) * 0x18 + *(int *)this),str);
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
int FunctionTable__updateForRemovingChunk(this, _PPStreamChunk)
  unsigned char * this;
  unsigned char * _PPStreamChunk;
{
  int loopIndex;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  loopIndex = 0;
  if (0 < *(int *)(this + 4)) {
    iVar2 = 0;
    do {
      iVar3 = *(int *)this;
      uVar5 = *(uint *)(_PPStreamChunk + 0xc);
      iVar4 = iVar2 + iVar3;
      if ((((uVar5 & 0x3ffff) == *(uint *)(iVar4 + 0x14)) && (*(int *)(_PPStreamChunk + 4) != 0)) &&
         (*(int *)(iVar4 + 0x10) != 0)) {
        *(uint *)(iVar4 + 0x14) = *(uint *)(*(int *)(_PPStreamChunk + 4) + 0xc) & 0x3ffff;
        uVar5 = *(uint *)(_PPStreamChunk + 0xc);
        iVar3 = *(int *)this;
      }
      if ((((uVar5 & 0x3ffff) == *(uint *)(iVar2 + iVar3 + 0x10)) && (*(int *)(_PPStreamChunk + 8) != 0))
         && ((uVar5 & 0x3ffff) != 0)) {
        *(uint *)(iVar2 + iVar3 + 0x10) = *(uint *)(*(int *)(_PPStreamChunk + 8) + 0xc) & 0x3ffff;
      }
      loopIndex = loopIndex + 1;
      iVar2 = iVar2 + 0x18;
    } while (loopIndex < *(int *)(this + 4));
    return;
  }
  return;
}

/* FunctionTable__findFunction @ 0x97bcccb0 (132 bytes) */
int FunctionTable__findFunction(this, str, param_3, param_4, param_5, param_6)
  unsigned char * this;
  char *str;
  undefined4 param_3;
  undefined4 param_4;
  undefined4 param_5;
  undefined4 param_6;
{
  int compareResult;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = *(int *)(this + 4);
  if (0 < iVar1) {
    iVar2 = 0;
    do {
      compareResult = _strcmp(*(undefined4 *)(iVar2 + *(int *)this),str);
      if (compareResult == 0) {
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
  undefined4 allocation;
  
  allocation = _calloc(0xa70,1);
  ((int (*)())_InterpreterInit)(allocation);
  return allocation;
}

/* _InterpreterFree @ 0x97bccde8 (48 bytes) */
int _InterpreterFree(param_1)
  undefined4 param_1;
{
  ((int (*)())_InterpreterShutdown)(param_1);
  return _free(param_1);
}

/* _InterpreterInit @ 0x97bcce18 (72 bytes) */
int _InterpreterInit(param_1)
  int param_1;
{
  undefined4 interpreterTextureSamplerCreateResult;
  
  _memset(param_1,0,0xa70);
  interpreterTextureSamplerCreateResult = ((int (*)())_InterpreterTextureSamplerCreate)();
  *(undefined4 *)(param_1 + 0xa2c) = interpreterTextureSamplerCreateResult;
  _InterpreterNoiseGeneratorInitialise(param_1 + 4);
  return _InterpreterRasterOpMachineInitialise(param_1 + 0xa24);
}

/* _InterpreterShutdown @ 0x97bcce60 (8 bytes) */
int _InterpreterShutdown(param_1)
  int param_1;
{
  undefined4 interpreterTextureSamplerFreeResult;
  
  interpreterTextureSamplerFreeResult = _InterpreterTextureSamplerFree(*(undefined4 *)(param_1 + 0xa2c));
  return interpreterTextureSamplerFreeResult;
}

/* _InterpreterAttachEmulatorContext @ 0x97bcce68 (12 bytes) */
int _InterpreterAttachEmulatorContext(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  return _InterpreterRasterOpMachineAttachEmulatorContext(param_1 + 0x289,param_2);
}

/* _InterpreterPackPixel @ 0x97bcce74 (1208 bytes) */
int _InterpreterPackPixel(machine, color, pixelOut)
  int *machine;
  float *color;
  float *pixelOut;
{
  float greenOut;
  float redOut;
  float blueOut;
  float alphaClamp8;
  float blueClamp8;
  float greenClamp8;
  float greenClamp5;
  float blueClamp;
  float zeroConstC;
  float zeroConstB;
  float zeroConstA;
  float scale31;
  float roundOffset5;
  double alphaDouble;
  double blueDouble;
  double greenDouble;
  uint framebufferFormat;
  float floatValue;
  float greenScaled;
  float scale255;
  uint alphaBit;
  uint redInt;
  float roundOffset8;
  uint greenInt;
  float redScaled;
  uint blueInt;
  int emulator;
  bool notBelowZero;
  double redDouble;
  double convertThreshold;
  
  emulator = *machine;
  if (*(int *)(emulator + 0xd9c) != 0) {
    framebufferFormat = _PPEmulatorFramebufferFormat(emulator);
    if ((framebufferFormat & 0x8000000) == 0) {
      framebufferFormat = _PPEmulatorFramebufferFormat(emulator);
      roundOffset8 = FLOAT_97c3acc0;
      scale255 = FLOAT_97c3acbc;
      if ((framebufferFormat & 0x8000) == 0) {
        framebufferFormat = _PPEmulatorFramebufferFormat(emulator);
        scale31 = FLOAT_97c3acc4;
        roundOffset5 = FLOAT_97c3acc0;
        if ((framebufferFormat & 0x400) == 0) {
          return;
        }
        redScaled = *color * FLOAT_97c3acc4 + FLOAT_97c3acc0;
        greenScaled = color[1] * FLOAT_97c3acc4 + FLOAT_97c3acc0;
        notBelowZero = TAllocation__guardBlockSize <= redScaled;
        *color = redScaled;
        color[1] = greenScaled;
        color[2] = color[2] * scale31 + roundOffset5;
        zeroConstA = TAllocation__guardBlockSize;
        if (notBelowZero) {
          if (scale31 < redScaled) {
            redScaled = 31.0;
          }
        }
        else {
          redScaled = 0.0;
        }
        greenClamp5 = color[1];
        *color = redScaled;
        zeroConstC = TAllocation__guardBlockSize;
        if (zeroConstA <= greenClamp5) {
          if (FLOAT_97c3acc4 < greenClamp5) {
            greenClamp5 = 31.0;
          }
        }
        else {
          greenClamp5 = 0.0;
        }
        blueClamp = color[2];
        color[1] = greenClamp5;
        convertThreshold = DOUBLE_97c30a78;
        if (zeroConstC <= blueClamp) {
          if (FLOAT_97c3acc4 < blueClamp) {
            blueClamp = 31.0;
          }
        }
        else {
          blueClamp = 0.0;
        }
        redDouble = (double)*color;
        color[2] = blueClamp;
        if (convertThreshold <= redDouble) {
          redInt = (uint)(int)(redDouble - convertThreshold);
        }
        else {
          redInt = (uint)(int)*color;
        }
        greenDouble = (double)color[1];
        if (DOUBLE_97c30a78 <= greenDouble) {
          greenInt = (uint)(int)(greenDouble - DOUBLE_97c30a78);
        }
        else {
          greenInt = (uint)(int)color[1];
        }
        blueDouble = (double)color[2];
        if (DOUBLE_97c30a78 <= blueDouble) {
          blueInt = (uint)(int)(blueDouble - DOUBLE_97c30a78);
        }
        else {
          blueInt = (uint)(int)color[2];
        }
        if (FLOAT_97c3acc0 <= color[3]) {
          alphaBit = 0x8000;
        }
        else {
          alphaBit = 0;
        }
        floatValue = GH_U2F((unsigned int)((alphaBit | (redInt & 0x1f) << 10 | (greenInt & 0x1f) << 5 | blueInt & 0x1f)));
      }
      else {
        redScaled = *color * FLOAT_97c3acbc + FLOAT_97c3acc0;
        greenScaled = color[1] * FLOAT_97c3acbc + FLOAT_97c3acc0;
        notBelowZero = TAllocation__guardBlockSize <= redScaled;
        *color = redScaled;
        color[1] = greenScaled;
        color[3] = color[3] * scale255 + roundOffset8;
        color[2] = color[2] * scale255 + roundOffset8;
        zeroConstB = TAllocation__guardBlockSize;
        if (notBelowZero) {
          if (scale255 < redScaled) {
            redScaled = 255.0;
          }
        }
        else {
          redScaled = 0.0;
        }
        greenClamp8 = color[1];
        *color = redScaled;
        zeroConstC = TAllocation__guardBlockSize;
        if (zeroConstB <= greenClamp8) {
          if (FLOAT_97c3acbc < greenClamp8) {
            greenClamp8 = 255.0;
          }
        }
        else {
          greenClamp8 = 0.0;
        }
        blueClamp8 = color[2];
        color[1] = greenClamp8;
        zeroConstA = TAllocation__guardBlockSize;
        if (zeroConstC <= blueClamp8) {
          if (FLOAT_97c3acbc < blueClamp8) {
            blueClamp8 = 255.0;
          }
        }
        else {
          blueClamp8 = 0.0;
        }
        alphaClamp8 = color[3];
        color[2] = blueClamp8;
        convertThreshold = DOUBLE_97c30a78;
        if (zeroConstA <= alphaClamp8) {
          if (FLOAT_97c3acbc < alphaClamp8) {
            alphaClamp8 = 255.0;
          }
        }
        else {
          alphaClamp8 = 0.0;
        }
        redDouble = (double)*color;
        color[3] = alphaClamp8;
        if (convertThreshold <= redDouble) {
          redInt = (uint)(int)(redDouble - convertThreshold);
        }
        else {
          redInt = (uint)(int)*color;
        }
        greenDouble = (double)color[1];
        if (DOUBLE_97c30a78 <= greenDouble) {
          greenInt = (uint)(int)(greenDouble - DOUBLE_97c30a78);
        }
        else {
          greenInt = (uint)(int)color[1];
        }
        blueDouble = (double)color[2];
        if (DOUBLE_97c30a78 <= blueDouble) {
          blueInt = (uint)(int)(blueDouble - DOUBLE_97c30a78);
        }
        else {
          blueInt = (uint)(int)color[2];
        }
        alphaDouble = (double)color[3];
        if (DOUBLE_97c30a78 <= alphaDouble) {
          emulator = (int)(alphaDouble - DOUBLE_97c30a78);
        }
        else {
          emulator = (int)color[3];
        }
        floatValue = GH_U2F((unsigned int)((emulator << 0x18 | (redInt & 0xff) << 0x10 | (greenInt & 0xff) << 8 | blueInt & 0xff)))
        ;
      }
      *pixelOut = floatValue;
    }
    else {
      redOut = *color;
      greenOut = color[1];
      blueOut = color[2];
      pixelOut[3] = color[3];
      *pixelOut = redOut;
      pixelOut[1] = greenOut;
      pixelOut[2] = blueOut;
    }
  }
  return;
}

/* _InterpreterUnpackPixel @ 0x97bcd32c (428 bytes) */
int _InterpreterUnpackPixel(machine, color, pixelIn)
  int *machine;
  float *color;
  float *pixelIn;
{
  float channelScale;
  float alpha;
  float red;
  uint framebufferFormat;
  float green;
  float blue;
  int emulator;
  
  emulator = *machine;
  if (*(int *)(emulator + 0xd9c) != 0) {
    framebufferFormat = _PPEmulatorFramebufferFormat(emulator);
    if ((framebufferFormat & 0x8000000) == 0) {
      framebufferFormat = _PPEmulatorFramebufferFormat(emulator);
      if ((framebufferFormat & 0x8000) == 0) {
        framebufferFormat = _PPEmulatorFramebufferFormat(emulator);
        if ((framebufferFormat & 0x400) == 0) {
          return;
        }
        blue = *pixelIn;
        red = (float)((double)CONCAT44(0x43300000,(uint)GH_F2U(blue) >> 10 & 0x1f) - DOUBLE_97c30a68) -
                FLOAT_97c3acc0;
        green = (float)((double)CONCAT44(0x43300000,(uint)GH_F2U(blue) >> 5 & 0x1f) - DOUBLE_97c30a68) -
                FLOAT_97c3acc0;
        alpha = (float)((double)CONCAT44(0x43300000,(uint)GH_F2U(blue) >> 0xf & 1) - DOUBLE_97c30a68) -
                FLOAT_97c3acc0;
        blue = (float)((double)CONCAT44(0x43300000,(uint)GH_F2U(blue) & 0x1f) - DOUBLE_97c30a68) -
                FLOAT_97c3acc0;
        channelScale = FLOAT_97c3accc;
      }
      else {
        alpha = *pixelIn;
        red = (float)((double)CONCAT44(0x43300000,(uint)GH_F2U(alpha) >> 0x10 & 0xff) - DOUBLE_97c30a68);
        green = (float)((double)CONCAT44(0x43300000,(uint)GH_F2U(alpha) >> 8 & 0xff) - DOUBLE_97c30a68);
        blue = (float)((double)CONCAT44(0x43300000,(uint)GH_F2U(alpha) & 0xff) - DOUBLE_97c30a68);
        alpha = (float)((double)CONCAT44(0x43300000,(uint)GH_F2U(alpha) >> 0x18) - DOUBLE_97c30a68);
        channelScale = FLOAT_97c3acc8;
      }
      color[3] = alpha * channelScale;
      *color = red * channelScale;
      color[1] = green * channelScale;
      color[2] = blue * channelScale;
    }
    else {
      red = *pixelIn;
      green = pixelIn[1];
      blue = pixelIn[2];
      color[3] = pixelIn[3];
      *color = red;
      color[1] = green;
      color[2] = blue;
    }
  }
  return;
}

/* _InterpreterWriteDestination @ 0x97bcd4d8 (1100 bytes) */
int _InterpreterWriteDestination(machine, componentOffsets, bankIndex, swizzle, indexInfo, storageFlags, operandWord5, operandWord6, writeMaskFlags, conditionSwizzleZW, element, value, updateConditionCode)
  int *machine;
  int componentOffsets;
  int bankIndex;
  uint swizzle;
  undefined4 indexInfo;
  undefined4 storageFlags;
  undefined4 operandWord5;
  undefined4 operandWord6;
  uint writeMaskFlags;
  undefined4 conditionSwizzleZW;
  int element;
  float *value;
  undefined4 updateConditionCode;
{
  unsigned int ghidra_home[8] = { machine, componentOffsets, bankIndex, swizzle, indexInfo, storageFlags, operandWord5, operandWord6 };   /* r3..r10 as spilled at entry-sp + 0x18..0x34 (fix_home_slots) */
  int emulator;
  int programInfo;
  float *targetZ;
  float *targetX;
  float *componentTarget;
  int *storageBase;
  float *targetY;
  int *componentSlot;
  undefined1 conditionCode;
  float scratch [4];
  float swizzledX;
  float swizzledY;
  float swizzledZ;
  float swizzledW;
  
  componentTarget = scratch;
  swizzledX = value[swizzle >> 0x18];
  swizzledY = value[swizzle >> 0x10 & 0xff];
  swizzledZ = value[swizzle >> 8 & 0xff];
  swizzledW = value[swizzle & 0xff];
  emulator = *machine;
  *value = swizzledX;
  value[1] = swizzledY;
  value[2] = swizzledZ;
  value[3] = swizzledW;
  programInfo = *(int *)(emulator + 0xd80);
  (*(ushort *)((unsigned char *)ghidra_home + 20)) = (ushort)((uint)storageFlags >> 0x10);
  if (((*(int *)(programInfo + 0x38) == 0x8804) || (*(int *)(programInfo + 0x38) == 0x8b30)) &&
     ((*(ushort *)((unsigned char *)ghidra_home + 20)) == 1)) {
    storageBase = machine + 0x292;
    componentSlot = (int *)(componentOffsets + element * 0x10);
  }
  else {
    if (((*(int *)(programInfo + 0x38) == 0x8804) || (*(int *)(programInfo + 0x38) == 0x8b30)) &&
       ((*(ushort *)((unsigned char *)ghidra_home + 20)) == 9)) {
      storageBase = machine + 0x28c;
    }
    else {
      (*(char *)((unsigned char *)ghidra_home + 23)) = (char)storageFlags;
      storageBase = *(int **)((uint)(*(ushort *)((unsigned char *)ghidra_home + 20)) * 4 + emulator + 0xd84);
      if ((*(char *)((unsigned char *)ghidra_home + 23)) != '\0') {
        programInfo = bankIndex * 0xc + programInfo;
        (*(short *)((unsigned char *)ghidra_home + 16)) = (short)((uint)indexInfo >> 0x10);
        emulator = *(int *)(programInfo + 0x80);
        componentSlot = (int *)(emulator + (((uint)((componentOffsets + element * 0x10) - emulator) >> 4) +
                                  machine[0x290] + (int)(*(short *)((unsigned char *)ghidra_home + 16)) & *(uint *)(programInfo + 0x88)) *
                                 0x10);
        goto LAB_97bcd680;
      }
    }
    componentSlot = (int *)(componentOffsets + element * 0x10);
  }
LAB_97bcd680:
  targetX = componentTarget;
  (*(int *)((unsigned char *)ghidra_home + 4)) = componentOffsets;
  (*(int *)((unsigned char *)ghidra_home + 8)) = bankIndex;
  (*(uint *)((unsigned char *)ghidra_home + 12)) = swizzle;
  (*(unsigned int *)((unsigned char *)ghidra_home + 16)) = indexInfo;
  (*(unsigned int *)((unsigned char *)ghidra_home + 20)) = storageFlags;
  (*(unsigned int *)((unsigned char *)ghidra_home + 24)) = operandWord5;
  (*(unsigned int *)((unsigned char *)ghidra_home + 28)) = operandWord6;
  if ((((writeMaskFlags & 0x1000000) != 0) &&
      (emulator = ((int (*)())_InterpreterTestCR)(machine,componentOffsets,bankIndex,swizzle,indexInfo,storageFlags,operandWord5,operandWord6,
                                  writeMaskFlags,conditionSwizzleZW,0), emulator != 0)) &&
     (targetX = (float *)((int)storageBase + *componentSlot), (char)updateConditionCode != '\0')) {
    emulator = ___isnanf(emulator);
    conditionCode = 3;
    if ((emulator == 0) && (conditionCode = 0.0 < *value, *value < 0.0)) {
      conditionCode = 2;
    }
    *(undefined1 *)(machine + 0x291) = conditionCode;
  }
  targetY = componentTarget;
  if ((((writeMaskFlags & 0x2000000) != 0) &&
      (emulator = ((int (*)())_InterpreterTestCR)(machine,(*(int *)((unsigned char *)ghidra_home + 4)),(*(int *)((unsigned char *)ghidra_home + 8)),(*(uint *)((unsigned char *)ghidra_home + 12)),
                                  (*(short *)((unsigned char *)ghidra_home + 16)),(*(unsigned int *)((unsigned char *)ghidra_home + 20)),(*(unsigned int *)((unsigned char *)ghidra_home + 24)),(*(unsigned int *)((unsigned char *)ghidra_home + 28)),
                                  writeMaskFlags,conditionSwizzleZW,1), emulator != 0)) &&
     (targetY = (float *)((int)storageBase + componentSlot[1]), (char)updateConditionCode != '\0')) {
    emulator = ___isnanf(emulator);
    conditionCode = 3;
    if ((emulator == 0) && (conditionCode = 0.0 < value[1], value[1] < 0.0)) {
      conditionCode = 2;
    }
    *(undefined1 *)((int)machine + 0xa45) = conditionCode;
  }
  targetZ = componentTarget;
  if ((((writeMaskFlags & 0x4000000) != 0) &&
      (emulator = ((int (*)())_InterpreterTestCR)(machine,(*(int *)((unsigned char *)ghidra_home + 4)),(*(int *)((unsigned char *)ghidra_home + 8)),(*(uint *)((unsigned char *)ghidra_home + 12)),
                                  (*(short *)((unsigned char *)ghidra_home + 16)),(*(unsigned int *)((unsigned char *)ghidra_home + 20)),(*(unsigned int *)((unsigned char *)ghidra_home + 24)),(*(unsigned int *)((unsigned char *)ghidra_home + 28)),
                                  writeMaskFlags,conditionSwizzleZW,2), emulator != 0)) &&
     (targetZ = (float *)((int)storageBase + componentSlot[2]), (char)updateConditionCode != '\0')) {
    emulator = ___isnanf(emulator);
    conditionCode = 3;
    if ((emulator == 0) && (conditionCode = 0.0 < value[2], value[2] < 0.0)) {
      conditionCode = 2;
    }
    *(undefined1 *)((int)machine + 0xa46) = conditionCode;
  }
  if ((((writeMaskFlags & 0x8000000) != 0) &&
      (emulator = ((int (*)())_InterpreterTestCR)(machine,(*(int *)((unsigned char *)ghidra_home + 4)),(*(int *)((unsigned char *)ghidra_home + 8)),(*(uint *)((unsigned char *)ghidra_home + 12)),
                                  (*(short *)((unsigned char *)ghidra_home + 16)),(*(unsigned int *)((unsigned char *)ghidra_home + 20)),(*(unsigned int *)((unsigned char *)ghidra_home + 24)),(*(unsigned int *)((unsigned char *)ghidra_home + 28)),
                                  writeMaskFlags,conditionSwizzleZW,3), emulator != 0)) &&
     (componentTarget = (float *)((int)storageBase + componentSlot[3]), (char)updateConditionCode != '\0')) {
    emulator = ___isnanf(emulator);
    conditionCode = 3;
    if ((emulator == 0) && (conditionCode = 0.0 < value[3], value[3] < 0.0)) {
      conditionCode = 2;
    }
    *(undefined1 *)((int)machine + 0xa47) = conditionCode;
  }
  *targetX = *value;
  *targetY = value[1];
  *targetZ = value[2];
  *componentTarget = value[3];
  return;
}

/* _InterpreterLoadSource @ 0x97bcd924 (796 bytes) */
int _InterpreterLoadSource(machine, componentOffsets, bankIndex, swizzle, indexInfo, storageFlags, operandWord5, valueType, operandWord7, operandWord8, element, result)
  int *machine;
  int *componentOffsets;
  int bankIndex;
  uint swizzle;
  undefined4 indexInfo;
  undefined4 storageFlags;
  undefined4 operandWord5;
  uint valueType;
  undefined4 operandWord7;
  undefined4 operandWord8;
  int element;
  float *result;
{
  float x;
  float y;
  float z;
  float w;
  double intToFloatBias;
  int iVar6;
  int *componentSlot;
  int iVar8;
  int emulator;
  byte swizzleX;
  byte swizzleY;
  byte swizzleZ;
  short relativeOffset;
  ushort storageClass;
  char negate;
  char relativeAddressing;
  
  intToFloatBias = DOUBLE_97c30a58;
  emulator = *machine;
  iVar6 = *(int *)(*(int *)(emulator + 0xd80) + 0x38);
  storageClass = (ushort)((uint)storageFlags >> 0x10);
  swizzleZ = (byte)(swizzle >> 8);
  swizzleY = (byte)(swizzle >> 0x10);
  swizzleX = (byte)(swizzle >> 0x18);
  if (((iVar6 == 0x8804) || (iVar6 == 0x8b30)) && (storageClass == 2)) {
    iVar6 = *(int *)(emulator + 0xda4);
    emulator = *(int *)(emulator + 0xda0);
    x = *(float *)(iVar6 + componentOffsets[element * 4 + (uint)swizzleX]) * GH_U2F((unsigned int)(machine[0x28c]))
            + *(float *)(emulator + componentOffsets[element * 4 + (uint)swizzleX]);
    *result = x;
    y = *(float *)(iVar6 + componentOffsets[element * 4 + (uint)swizzleY]) * GH_U2F((unsigned int)(machine[0x28c]))
            + *(float *)(emulator + componentOffsets[element * 4 + (uint)swizzleY]);
    result[1] = y;
    z = *(float *)(iVar6 + componentOffsets[element * 4 + (uint)swizzleZ]) * GH_U2F((unsigned int)(machine[0x28c]))
            + *(float *)(emulator + componentOffsets[element * 4 + (uint)swizzleZ]);
    result[2] = z;
    w = *(float *)(iVar6 + componentOffsets[element * 4 + (swizzle & 0xff)]) * GH_U2F((unsigned int)(machine[0x28c])) +
            *(float *)(emulator + componentOffsets[element * 4 + (swizzle & 0xff)]);
    result[3] = w;
    if (*componentOffsets != 0) {
      *result = x * GH_U2F((unsigned int)(machine[0x28f]));
      result[1] = y * GH_U2F((unsigned int)(machine[0x28f]));
      result[2] = z * GH_U2F((unsigned int)(machine[0x28f]));
      result[3] = w * GH_U2F((unsigned int)(machine[0x28f]));
    }
  }
  else {
    relativeAddressing = (char)storageFlags;
    if (relativeAddressing == '\0') {
      componentSlot = componentOffsets + element * 4;
    }
    else {
      iVar8 = bankIndex * 0xc + *(int *)(emulator + 0xd80);
      relativeOffset = (short)((uint)indexInfo >> 0x10);
      iVar6 = *(int *)(iVar8 + 0x80);
      componentSlot = (int *)(iVar6 + (((uint)((int)componentOffsets + (element * 0x10 - iVar6)) >> 4) +
                                machine[0x290] + (int)relativeOffset & *(uint *)(iVar8 + 0x88)) *
                               0x10);
    }
    iVar6 = *(int *)((uint)storageClass * 4 + emulator + 0xd84);
    if (valueType < 2) {
      *result = *(float *)(iVar6 + componentSlot[swizzleX]);
      result[1] = *(float *)(iVar6 + componentSlot[swizzleY]);
      result[2] = *(float *)(iVar6 + componentSlot[swizzleZ]);
      x = *(float *)(iVar6 + componentSlot[swizzle & 0xff]);
    }
    else {
      if (1 < valueType - 3) goto LAB_97bcdbfc;
      *result = (float)((double)CONCAT44(0x43300000,
                                           *(uint *)(iVar6 + componentSlot[swizzleX]) ^ 0x80000000) -
                         DOUBLE_97c30a58);
      result[1] = (float)((double)CONCAT44(0x43300000,
                                             *(uint *)(iVar6 + componentSlot[swizzleY]) ^ 0x80000000)
                           - intToFloatBias);
      result[2] = (float)((double)CONCAT44(0x43300000,
                                             *(uint *)(iVar6 + componentSlot[swizzleZ]) ^ 0x80000000)
                           - intToFloatBias);
      x = (float)((double)CONCAT44(0x43300000,
                                       *(uint *)(iVar6 + componentSlot[swizzle & 0xff]) ^ 0x80000000) -
                     intToFloatBias);
    }
    result[3] = x;
  }
LAB_97bcdbfc:
  negate = (char)((uint)storageFlags >> 8);
  if (negate != '\0') {
    *result = -*result;
    result[1] = -result[1];
    result[2] = -result[2];
    result[3] = -result[3];
  }
  return;
}

/* _InterpreterTestCR @ 0x97bcdc40 (240 bytes) */
int _InterpreterTestCR(machine, operandWord0, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5, operandWord6, conditionWord, conditionSwizzleZW, component)
  int machine;
  undefined4 operandWord0;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
  undefined4 operandWord6;
  uint conditionWord;
  undefined4 conditionSwizzleZW;
  int component;
{
  uint passes;
  uint conditionCode;
  
  passes = 0;
  conditionCode = (uint)*(byte *)((uint)*(byte *)((int)&conditionWord + component + 2) + machine + 0xa44);
  switch(conditionWord >> 0x10 & 0xff) {
  case 0:
    passes = 1;
    break;
  case 1:
    passes = (uint)(conditionCode == 0);
    break;
  case 2:
    passes = (uint)(conditionCode < 2);
    break;
  case 3:
    passes = (uint)(conditionCode == 1);
    break;
  case 4:
    passes = 0;
    if ((conditionCode == 2) || (conditionCode == 0)) {
      passes = 1;
    }
    break;
  case 5:
    passes = (uint)(conditionCode == 2);
    break;
  case 6:
    passes = -conditionCode >> 0x1f;
    break;
  case 7:
    passes = 0;
  }
  return passes;
}

/* _InterpreterEmulateOp @ 0x97bcdd50 (20820 bytes) */
int * _InterpreterEmulateOp(int *machine,int *inst,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  uint textureTarget;
  float *srcElementPtr;
  uint destUpdatesCC;
  int sourceOffset;
  int destWriteMask;
  int intComponentI26;
  int destSwizzle;
  int destBankIndex;
  uint sourceElement2;
  int programInfo;
  int intComponentI14;
  int destOffsetTable;
  int sourceCount;
  double logValue;
  double expValue;
  double sqrtValue;
  double log2Value;
  double exp2Value;
  double mathAccumulator;
  double intAsDouble;
  double floorValue;
  double powValue;
  uint intComponent;
  uint dimension;
  uint boolBit;
  float *componentCursor;
  float degRadFactor;
  float squaredComponent;
  float operandComponent;
  int conditionResult;
  double exp2Result2;
  double floorResult2;
  double truncResult;
  double atanResult;
  double acosResult;
  double asinResult;
  double tanResult;
  double sinResult;
  double cosResult;
  double log2Result;
  double exp2Result;
  double sqrtResult;
  double floorResult;
  double ceilResult;
  double powResult;
  uint loopIndex;
  uint loopIndex2;
  float *pfVar1;
  bool bVar2;
  char saturate;
  byte bVar4;
  char swizzleSelect;
  float fVar6;
  float fVar7;
  uint boolBit8;
  byte *pbVar9;
  float *operandScratch;
  int *piVar11;
  float *in_r5_artifact;
  int destIndexInfo;
  int destStorageFlags;
  int iVar14;
  int destWord5;
  int destValueType;
  uint scalarSourceIndex;
  int *nextInst;
  int emulator;
  uint elementCount;
  int opcode;
  int destConditionSwizzleZW;
  float *srcAPtr;
  uint sourceElement;
  bool bVar25;
  int sourcesRemaining;
  double dVar27;
  double dVar28;
  double floorValue_29;
  double floorValue_30;
  double floorValue_31;
  double in_stack_fffffe78;
  double in_stack_fffffe80;
  double in_stack_fffffe88;
  double in_stack_fffffe90;
  double in_stack_fffffe98;
  undefined4 destElement;
  float opVec [12];
  float srcC [4];
  float prodC0R0;
  float prodC0R1;
  float prodC0R2;
  float prodC0R3;
  float prodC1R0;
  float prodC1R1;
  float prodC1R2;
  float prodC1R3;
  float prodC2R0;
  float prodC2R1;
  float prodC2R2;
  float prodC2R3;
  float prodC3R0;
  float prodC3R1;
  float prodC3R2;
  float prodC3R3;
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
  
  emulator = *machine;
  nextInst = inst + 0x47;
  if (inst == *(int **)(*(int *)(emulator + 0xd80) + 4)) {
    nextInst = (int *)0x0;
  }
  sourceCount = inst[0xc];
  opVec[3] = 0.0;
  elementCount = 1;
  opVec[0] = 0.0;
  opVec[1] = 0.0;
  bVar25 = true;
  opVec[2] = 0.0;
  opcode = *inst;
  saturate = *(char *)(inst + 1);
  if (sourceCount != 0) {
    pbVar9 = (byte *)((int)inst + 0x49);
    sourcesRemaining = sourceCount;
    do {
      if ((pbVar9[-1] != 0) && (elementCount < *pbVar9)) {
        elementCount = (uint)*pbVar9;
      }
      pbVar9 = pbVar9 + 0x24;
      sourcesRemaining = sourcesRemaining + -1;
    } while (sourcesRemaining != 0);
  }
  if (opcode == 0x22) {
    saturate = *(char *)(inst + 0x12);
    if ((saturate == '\0') && (*(char *)(inst + 0x1b) == '\0')) {
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,opVec + 4);
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],0,opVec + 8);
      operandScratch = opVec;
      opVec[0] = opVec[4] * opVec[8];
      opVec[1] = opVec[5] * opVec[9];
      opVec[2] = opVec[6] * opVec[10];
      destValueType = inst[9];
      opVec[3] = opVec[7] * opVec[0xb];
      destUpdatesCC = (uint)*(byte *)((int)inst + 6);
      destWriteMask = inst[10];
      destConditionSwizzleZW = inst[0xb];
      destOffsetTable = inst[3];
      destBankIndex = inst[4];
      destSwizzle = inst[5];
      destIndexInfo = inst[6];
      destStorageFlags = inst[7];
      destWord5 = inst[8];
      destElement = 0;
    }
    else if ((saturate == '\0') ||
            ((*(char *)(inst + 0x1b) == '\0' ||
             (*(char *)((int)inst + 0x49) != *(char *)((int)inst + 0x6d))))) {
      if ((saturate == '\0') || (*(byte *)((int)inst + 0x6d) < 2)) {
        if ((*(char *)(inst + 0x1b) == '\0') || (*(byte *)((int)inst + 0x49) < 2)) {
          scalarSourceIndex = (uint)(saturate == '\0');
          if (scalarSourceIndex == 0) {
            sourceOffset = 0x54;
          }
          else {
            sourceOffset = 0x30;
          }
          operandScratch = opVec + 8;
          ((int (*)())_InterpreterLoadSource)(machine,*(undefined4 *)((int)inst + sourceOffset + 4),
                     *(undefined4 *)((int)inst + sourceOffset + 8),
                     *(undefined4 *)((int)inst + sourceOffset + 0xc),
                     *(undefined4 *)((int)inst + sourceOffset + 0x10),
                     *(undefined4 *)((int)inst + sourceOffset + 0x14),
                     *(undefined4 *)((int)inst + sourceOffset + 0x18),
                     *(undefined4 *)((int)inst + sourceOffset + 0x1c),
                     *(undefined4 *)((int)inst + sourceOffset + 0x20),
                     *(undefined4 *)((int)inst + sourceOffset + 0x24),0,opVec + 4);
          ((int (*)())_InterpreterLoadSource)(machine,inst[scalarSourceIndex * 9 + 0xd],inst[scalarSourceIndex * 9 + 0xe],
                     inst[scalarSourceIndex * 9 + 0xf],inst[scalarSourceIndex * 9 + 0x10],inst[scalarSourceIndex * 9 + 0x11]
                     ,inst[scalarSourceIndex * 9 + 0x12],inst[scalarSourceIndex * 9 + 0x13],
                     inst[scalarSourceIndex * 9 + 0x14],inst[scalarSourceIndex * 9 + 0x15],0,operandScratch);
          if (elementCount == 2) {
            destElement = 1;
            opVec[0] = opVec[4] * opVec[8];
            opVec[1] = opVec[4] * opVec[9];
            ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                       inst[9],inst[10],inst[0xb],0,opVec,
                       (uint)*(byte *)((int)inst + 6));
            ((int (*)())_InterpreterLoadSource)(machine,inst[scalarSourceIndex * 9 + 0xd],inst[scalarSourceIndex * 9 + 0xe],
                       inst[scalarSourceIndex * 9 + 0xf],inst[scalarSourceIndex * 9 + 0x10],
                       inst[scalarSourceIndex * 9 + 0x11],inst[scalarSourceIndex * 9 + 0x12],
                       inst[scalarSourceIndex * 9 + 0x13],inst[scalarSourceIndex * 9 + 0x14],
                       inst[scalarSourceIndex * 9 + 0x15],1,operandScratch);
            opVec[0] = opVec[4] * opVec[8];
            destValueType = inst[9];
            opVec[1] = opVec[4] * opVec[9];
            bVar4 = *(byte *)((int)inst + 6);
            destWriteMask = inst[10];
            destConditionSwizzleZW = inst[0xb];
            destOffsetTable = inst[3];
            destBankIndex = inst[4];
            destSwizzle = inst[5];
            destIndexInfo = inst[6];
            destStorageFlags = inst[7];
            destWord5 = inst[8];
          }
          else if (elementCount == 3) {
            opVec[0] = opVec[4] * opVec[8];
            opVec[2] = opVec[4] * opVec[10];
            opVec[1] = opVec[4] * opVec[9];
            ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                       inst[9],inst[10],inst[0xb],0,opVec,
                       (uint)*(byte *)((int)inst + 6));
            ((int (*)())_InterpreterLoadSource)(machine,inst[scalarSourceIndex * 9 + 0xd],inst[scalarSourceIndex * 9 + 0xe],
                       inst[scalarSourceIndex * 9 + 0xf],inst[scalarSourceIndex * 9 + 0x10],
                       inst[scalarSourceIndex * 9 + 0x11],inst[scalarSourceIndex * 9 + 0x12],
                       inst[scalarSourceIndex * 9 + 0x13],inst[scalarSourceIndex * 9 + 0x14],
                       inst[scalarSourceIndex * 9 + 0x15],1,operandScratch);
            opVec[0] = opVec[4] * opVec[8];
            opVec[2] = opVec[4] * opVec[10];
            opVec[1] = opVec[4] * opVec[9];
            ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                       inst[9],inst[10],inst[0xb],1,opVec,
                       (uint)*(byte *)((int)inst + 6));
            ((int (*)())_InterpreterLoadSource)(machine,inst[scalarSourceIndex * 9 + 0xd],inst[scalarSourceIndex * 9 + 0xe],
                       inst[scalarSourceIndex * 9 + 0xf],inst[scalarSourceIndex * 9 + 0x10],
                       inst[scalarSourceIndex * 9 + 0x11],inst[scalarSourceIndex * 9 + 0x12],
                       inst[scalarSourceIndex * 9 + 0x13],inst[scalarSourceIndex * 9 + 0x14],
                       inst[scalarSourceIndex * 9 + 0x15],2,operandScratch);
            opVec[0] = opVec[4] * opVec[8];
            opVec[2] = opVec[4] * opVec[10];
            destValueType = inst[9];
            opVec[1] = opVec[4] * opVec[9];
            bVar4 = *(byte *)((int)inst + 6);
            destWriteMask = inst[10];
            destConditionSwizzleZW = inst[0xb];
            destOffsetTable = inst[3];
            destBankIndex = inst[4];
            destSwizzle = inst[5];
            destIndexInfo = inst[6];
            destStorageFlags = inst[7];
            destWord5 = inst[8];
            destElement = 2;
          }
          else {
            if (elementCount != 4) {
              return nextInst;
            }
            opVec[0] = opVec[4] * opVec[8];
            opVec[3] = opVec[4] * opVec[0xb];
            opVec[1] = opVec[4] * opVec[9];
            opVec[2] = opVec[4] * opVec[10];
            ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                       inst[9],inst[10],inst[0xb],0,opVec,
                       (uint)*(byte *)((int)inst + 6));
            ((int (*)())_InterpreterLoadSource)(machine,inst[scalarSourceIndex * 9 + 0xd],inst[scalarSourceIndex * 9 + 0xe],
                       inst[scalarSourceIndex * 9 + 0xf],inst[scalarSourceIndex * 9 + 0x10],
                       inst[scalarSourceIndex * 9 + 0x11],inst[scalarSourceIndex * 9 + 0x12],
                       inst[scalarSourceIndex * 9 + 0x13],inst[scalarSourceIndex * 9 + 0x14],
                       inst[scalarSourceIndex * 9 + 0x15],1,operandScratch);
            opVec[0] = opVec[4] * opVec[8];
            opVec[3] = opVec[4] * opVec[0xb];
            opVec[1] = opVec[4] * opVec[9];
            opVec[2] = opVec[4] * opVec[10];
            destElement = 3;
            ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                       inst[9],inst[10],inst[0xb],1,opVec,
                       (uint)*(byte *)((int)inst + 6));
            ((int (*)())_InterpreterLoadSource)(machine,inst[scalarSourceIndex * 9 + 0xd],inst[scalarSourceIndex * 9 + 0xe],
                       inst[scalarSourceIndex * 9 + 0xf],inst[scalarSourceIndex * 9 + 0x10],
                       inst[scalarSourceIndex * 9 + 0x11],inst[scalarSourceIndex * 9 + 0x12],
                       inst[scalarSourceIndex * 9 + 0x13],inst[scalarSourceIndex * 9 + 0x14],
                       inst[scalarSourceIndex * 9 + 0x15],2,operandScratch);
            opVec[0] = opVec[4] * opVec[8];
            opVec[3] = opVec[4] * opVec[0xb];
            opVec[1] = opVec[4] * opVec[9];
            opVec[2] = opVec[4] * opVec[10];
            ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                       inst[9],inst[10],inst[0xb],2,opVec,
                       (uint)*(byte *)((int)inst + 6));
            ((int (*)())_InterpreterLoadSource)(machine,inst[scalarSourceIndex * 9 + 0xd],inst[scalarSourceIndex * 9 + 0xe],
                       inst[scalarSourceIndex * 9 + 0xf],inst[scalarSourceIndex * 9 + 0x10],
                       inst[scalarSourceIndex * 9 + 0x11],inst[scalarSourceIndex * 9 + 0x12],
                       inst[scalarSourceIndex * 9 + 0x13],inst[scalarSourceIndex * 9 + 0x14],
                       inst[scalarSourceIndex * 9 + 0x15],3,operandScratch);
            opVec[0] = opVec[4] * opVec[8];
            opVec[3] = opVec[4] * opVec[0xb];
            opVec[1] = opVec[4] * opVec[9];
            destValueType = inst[9];
            opVec[2] = opVec[4] * opVec[10];
            bVar4 = *(byte *)((int)inst + 6);
            destWriteMask = inst[10];
            destConditionSwizzleZW = inst[0xb];
            destOffsetTable = inst[3];
            destBankIndex = inst[4];
            destSwizzle = inst[5];
            destIndexInfo = inst[6];
            destStorageFlags = inst[7];
            destWord5 = inst[8];
          }
          operandScratch = opVec;
          destUpdatesCC = (uint)bVar4;
          goto LAB_97bd043c;
        }
        operandScratch = opVec + 8;
        ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                   inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,opVec + 4);
        ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                   inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],0,operandScratch);
        if (elementCount == 2) {
          opVec[0] = opVec[4] * opVec[8] + opVec[5] * opVec[9];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                     inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],1,operandScratch);
          opVec[1] = opVec[4] * opVec[8] + opVec[5] * opVec[9];
        }
        else if (elementCount == 3) {
          opVec[0] = opVec[6] * opVec[10] +
                         opVec[4] * opVec[8] + opVec[5] * opVec[9];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                     inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],1,operandScratch);
          opVec[1] = opVec[6] * opVec[10] +
                         opVec[4] * opVec[8] + opVec[5] * opVec[9];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                     inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],2,operandScratch);
          opVec[2] = opVec[6] * opVec[10] +
                         opVec[4] * opVec[8] + opVec[5] * opVec[9];
        }
        else if (elementCount == 4) {
          opVec[0] = opVec[7] * opVec[0xb] +
                         opVec[6] * opVec[10] +
                         opVec[4] * opVec[8] + opVec[5] * opVec[9];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                     inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],1,operandScratch);
          opVec[1] = opVec[7] * opVec[0xb] +
                         opVec[6] * opVec[10] +
                         opVec[4] * opVec[8] + opVec[5] * opVec[9];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                     inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],2,operandScratch);
          opVec[2] = opVec[7] * opVec[0xb] +
                         opVec[6] * opVec[10] +
                         opVec[4] * opVec[8] + opVec[5] * opVec[9];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                     inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],3,operandScratch);
          opVec[3] = opVec[7] * opVec[0xb] +
                         opVec[6] * opVec[10] +
                         opVec[4] * opVec[8] + opVec[5] * opVec[9];
        }
      }
      else {
        operandScratch = opVec + 8;
        ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                   inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,operandScratch);
        ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                   inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],0,opVec + 4);
        if (elementCount == 2) {
          opVec[0] = opVec[4] * opVec[8];
          opVec[1] = opVec[4] * opVec[9];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                     inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,operandScratch);
          opVec[0] = opVec[5] * opVec[8] + opVec[0];
          opVec[1] = opVec[5] * opVec[9] + opVec[1];
        }
        else if (elementCount == 3) {
          opVec[0] = opVec[4] * opVec[8];
          opVec[2] = opVec[4] * opVec[10];
          opVec[1] = opVec[4] * opVec[9];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                     inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,operandScratch);
          opVec[0] = opVec[5] * opVec[8] + opVec[0];
          opVec[2] = opVec[5] * opVec[10] + opVec[2];
          opVec[1] = opVec[5] * opVec[9] + opVec[1];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                     inst[0x12],inst[0x13],inst[0x14],inst[0x15],2,operandScratch);
          opVec[0] = opVec[6] * opVec[8] + opVec[0];
          opVec[2] = opVec[6] * opVec[10] + opVec[2];
          opVec[1] = opVec[6] * opVec[9] + opVec[1];
        }
        else if (elementCount == 4) {
          opVec[0] = opVec[4] * opVec[8];
          opVec[3] = opVec[4] * opVec[0xb];
          opVec[1] = opVec[4] * opVec[9];
          opVec[2] = opVec[4] * opVec[10];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                     inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,operandScratch);
          opVec[0] = opVec[5] * opVec[8] + opVec[0];
          opVec[3] = opVec[5] * opVec[0xb] + opVec[3];
          opVec[1] = opVec[5] * opVec[9] + opVec[1];
          opVec[2] = opVec[5] * opVec[10] + opVec[2];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                     inst[0x12],inst[0x13],inst[0x14],inst[0x15],2,operandScratch);
          opVec[0] = opVec[6] * opVec[8] + opVec[0];
          opVec[3] = opVec[6] * opVec[0xb] + opVec[3];
          opVec[1] = opVec[6] * opVec[9] + opVec[1];
          opVec[2] = opVec[6] * opVec[10] + opVec[2];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                     inst[0x12],inst[0x13],inst[0x14],inst[0x15],3,operandScratch);
          opVec[0] = opVec[7] * opVec[8] + opVec[0];
          opVec[3] = opVec[7] * opVec[0xb] + opVec[3];
          opVec[1] = opVec[7] * opVec[9] + opVec[1];
          opVec[2] = opVec[7] * opVec[10] + opVec[2];
        }
      }
      destUpdatesCC = (uint)*(byte *)((int)inst + 6);
      destWriteMask = inst[10];
      operandScratch = opVec;
      destConditionSwizzleZW = inst[0xb];
      destValueType = inst[9];
      destOffsetTable = inst[3];
      destBankIndex = inst[4];
      destSwizzle = inst[5];
      destIndexInfo = inst[6];
      destStorageFlags = inst[7];
      destWord5 = inst[8];
      destElement = 0;
    }
    else if (elementCount == 2) {
      operandScratch = opVec + 4;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,operandScratch);
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],0,opVec + 8);
      prodC0R0 = opVec[4] * opVec[8];
      prodC0R1 = opVec[5] * opVec[8];
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,operandScratch);
      prodC0R0 = opVec[4] * opVec[9] + prodC0R0;
      prodC0R1 = opVec[5] * opVec[9] + prodC0R1;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],1,opVec + 8);
      prodC1R0 = opVec[4] * opVec[9];
      prodC1R1 = opVec[5] * opVec[9];
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,operandScratch);
      prodC1R0 = opVec[4] * opVec[8] + prodC1R0;
      prodC1R1 = opVec[5] * opVec[8] + prodC1R1;
      ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                 inst[9],inst[10],inst[0xb],0,&prodC0R0,(uint)*(byte *)((int)inst + 6));
      destValueType = inst[9];
      destUpdatesCC = (uint)*(byte *)((int)inst + 6);
      operandScratch = &prodC1R0;
      destWriteMask = inst[10];
      destConditionSwizzleZW = inst[0xb];
      destOffsetTable = inst[3];
      destBankIndex = inst[4];
      destSwizzle = inst[5];
      destIndexInfo = inst[6];
      destStorageFlags = inst[7];
      destWord5 = inst[8];
      destElement = 1;
    }
    else if (elementCount == 3) {
      srcAPtr = opVec + 4;
      operandScratch = opVec + 8;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,srcAPtr);
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],0,operandScratch);
      prodC0R0 = opVec[4] * opVec[8];
      prodC0R2 = opVec[6] * opVec[8];
      prodC0R1 = opVec[5] * opVec[8];
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,srcAPtr);
      prodC0R0 = opVec[4] * opVec[9] + prodC0R0;
      prodC0R2 = opVec[6] * opVec[9] + prodC0R2;
      prodC0R1 = opVec[5] * opVec[9] + prodC0R1;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],2,srcAPtr);
      prodC0R0 = opVec[4] * opVec[10] + prodC0R0;
      prodC0R2 = opVec[6] * opVec[10] + prodC0R2;
      prodC0R1 = opVec[5] * opVec[10] + prodC0R1;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],1,operandScratch);
      prodC1R0 = opVec[4] * opVec[10];
      prodC1R2 = opVec[6] * opVec[10];
      prodC1R1 = opVec[5] * opVec[10];
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,srcAPtr);
      prodC1R0 = opVec[4] * opVec[9] + prodC1R0;
      prodC1R2 = opVec[6] * opVec[9] + prodC1R2;
      prodC1R1 = opVec[5] * opVec[9] + prodC1R1;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,srcAPtr);
      prodC1R0 = opVec[4] * opVec[8] + prodC1R0;
      prodC1R2 = opVec[6] * opVec[8] + prodC1R2;
      prodC1R1 = opVec[5] * opVec[8] + prodC1R1;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],2,operandScratch);
      prodC2R0 = opVec[4] * opVec[8];
      prodC2R2 = opVec[6] * opVec[8];
      prodC2R1 = opVec[5] * opVec[8];
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,srcAPtr);
      prodC2R0 = opVec[4] * opVec[9] + prodC2R0;
      prodC2R2 = opVec[6] * opVec[9] + prodC2R2;
      prodC2R1 = opVec[5] * opVec[9] + prodC2R1;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],2,srcAPtr);
      prodC2R0 = opVec[4] * opVec[10] + prodC2R0;
      prodC2R2 = opVec[6] * opVec[10] + prodC2R2;
      prodC2R1 = opVec[5] * opVec[10] + prodC2R1;
      ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                 inst[9],inst[10],inst[0xb],0,&prodC0R0,(uint)*(byte *)((int)inst + 6));
      ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                 inst[9],inst[10],inst[0xb],1,&prodC1R0,(uint)*(byte *)((int)inst + 6));
      destValueType = inst[9];
      destUpdatesCC = (uint)*(byte *)((int)inst + 6);
      operandScratch = &prodC2R0;
      destWriteMask = inst[10];
      destConditionSwizzleZW = inst[0xb];
      destOffsetTable = inst[3];
      destBankIndex = inst[4];
      destSwizzle = inst[5];
      destIndexInfo = inst[6];
      destStorageFlags = inst[7];
      destWord5 = inst[8];
      destElement = 2;
    }
    else {
      if (elementCount != 4) {
        return nextInst;
      }
      srcAPtr = opVec + 4;
      operandScratch = opVec + 8;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,srcAPtr);
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],0,operandScratch);
      prodC0R0 = opVec[4] * opVec[8];
      prodC0R3 = opVec[7] * opVec[8];
      prodC0R1 = opVec[5] * opVec[8];
      prodC0R2 = opVec[6] * opVec[8];
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,srcAPtr);
      prodC0R0 = opVec[4] * opVec[9] + prodC0R0;
      prodC0R3 = opVec[7] * opVec[9] + prodC0R3;
      prodC0R1 = opVec[5] * opVec[9] + prodC0R1;
      prodC0R2 = opVec[6] * opVec[9] + prodC0R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],2,srcAPtr);
      prodC0R0 = opVec[4] * opVec[10] + prodC0R0;
      prodC0R3 = opVec[7] * opVec[10] + prodC0R3;
      prodC0R1 = opVec[5] * opVec[10] + prodC0R1;
      prodC0R2 = opVec[6] * opVec[10] + prodC0R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],3,srcAPtr);
      prodC0R0 = opVec[4] * opVec[0xb] + prodC0R0;
      prodC0R3 = opVec[7] * opVec[0xb] + prodC0R3;
      prodC0R1 = opVec[5] * opVec[0xb] + prodC0R1;
      prodC0R2 = opVec[6] * opVec[0xb] + prodC0R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],1,operandScratch);
      prodC1R0 = opVec[4] * opVec[0xb];
      prodC1R3 = opVec[7] * opVec[0xb];
      prodC1R1 = opVec[5] * opVec[0xb];
      prodC1R2 = opVec[6] * opVec[0xb];
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],2,srcAPtr);
      prodC1R0 = opVec[4] * opVec[10] + prodC1R0;
      prodC1R3 = opVec[7] * opVec[10] + prodC1R3;
      prodC1R1 = opVec[5] * opVec[10] + prodC1R1;
      prodC1R2 = opVec[6] * opVec[10] + prodC1R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,srcAPtr);
      prodC1R0 = opVec[4] * opVec[9] + prodC1R0;
      prodC1R3 = opVec[7] * opVec[9] + prodC1R3;
      prodC1R1 = opVec[5] * opVec[9] + prodC1R1;
      prodC1R2 = opVec[6] * opVec[9] + prodC1R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,srcAPtr);
      prodC1R0 = opVec[4] * opVec[8] + prodC1R0;
      prodC1R3 = opVec[7] * opVec[8] + prodC1R3;
      prodC1R1 = opVec[5] * opVec[8] + prodC1R1;
      prodC1R2 = opVec[6] * opVec[8] + prodC1R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],2,operandScratch);
      prodC2R0 = opVec[4] * opVec[8];
      prodC2R3 = opVec[7] * opVec[8];
      prodC2R1 = opVec[5] * opVec[8];
      prodC2R2 = opVec[6] * opVec[8];
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,srcAPtr);
      prodC2R0 = opVec[4] * opVec[9] + prodC2R0;
      prodC2R3 = opVec[7] * opVec[9] + prodC2R3;
      prodC2R1 = opVec[5] * opVec[9] + prodC2R1;
      prodC2R2 = opVec[6] * opVec[9] + prodC2R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],2,srcAPtr);
      prodC2R0 = opVec[4] * opVec[10] + prodC2R0;
      prodC2R3 = opVec[7] * opVec[10] + prodC2R3;
      prodC2R1 = opVec[5] * opVec[10] + prodC2R1;
      prodC2R2 = opVec[6] * opVec[10] + prodC2R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],3,srcAPtr);
      prodC2R0 = opVec[4] * opVec[0xb] + prodC2R0;
      prodC2R3 = opVec[7] * opVec[0xb] + prodC2R3;
      prodC2R1 = opVec[5] * opVec[0xb] + prodC2R1;
      prodC2R2 = opVec[6] * opVec[0xb] + prodC2R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                 inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],3,operandScratch);
      prodC3R0 = opVec[4] * opVec[0xb];
      prodC3R3 = opVec[7] * opVec[0xb];
      prodC3R1 = opVec[5] * opVec[0xb];
      prodC3R2 = opVec[6] * opVec[0xb];
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],2,srcAPtr);
      prodC3R0 = opVec[4] * opVec[10] + prodC3R0;
      prodC3R3 = opVec[7] * opVec[10] + prodC3R3;
      prodC3R1 = opVec[5] * opVec[10] + prodC3R1;
      prodC3R2 = opVec[6] * opVec[10] + prodC3R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],1,srcAPtr);
      prodC3R0 = opVec[4] * opVec[9] + prodC3R0;
      prodC3R3 = opVec[7] * opVec[9] + prodC3R3;
      prodC3R1 = opVec[5] * opVec[9] + prodC3R1;
      prodC3R2 = opVec[6] * opVec[9] + prodC3R2;
      ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                 inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,srcAPtr);
      prodC3R0 = opVec[4] * opVec[8] + prodC3R0;
      prodC3R3 = opVec[7] * opVec[8] + prodC3R3;
      prodC3R1 = opVec[5] * opVec[8] + prodC3R1;
      prodC3R2 = opVec[6] * opVec[8] + prodC3R2;
      ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                 inst[9],inst[10],inst[0xb],0,&prodC0R0,(uint)*(byte *)((int)inst + 6));
      ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                 inst[9],inst[10],inst[0xb],1,&prodC1R0,(uint)*(byte *)((int)inst + 6));
      ((int (*)())_InterpreterWriteDestination)(machine,inst[3],inst[4],inst[5],inst[6],inst[7],inst[8],
                 inst[9],inst[10],inst[0xb],2,&prodC2R0,(uint)*(byte *)((int)inst + 6));
      destValueType = inst[9];
      destUpdatesCC = (uint)*(byte *)((int)inst + 6);
      operandScratch = &prodC3R0;
      destWriteMask = inst[10];
      destConditionSwizzleZW = inst[0xb];
      destOffsetTable = inst[3];
      destBankIndex = inst[4];
      destSwizzle = inst[5];
      destIndexInfo = inst[6];
      destStorageFlags = inst[7];
      destWord5 = inst[8];
      destElement = 3;
    }
    goto LAB_97bd043c;
  }
  if ((opcode != 0x31) && (opcode != 0x36)) {
    loopIndex2 = 0;
    if (elementCount == 0) {
      return nextInst;
    }
    do {
      if (sourceCount != 0) {
        sourceElement = loopIndex2;
        if (*(char *)(inst + 0x12) == '\0') {
          sourceElement = 0;
        }
        in_r5_artifact = (float *)inst[0xe];
        ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],in_r5_artifact,inst[0xf],inst[0x10],inst[0x11],inst[0x12]
                   ,inst[0x13],inst[0x14],inst[0x15],sourceElement,opVec + 4);
        if (1 < (uint)inst[0xc]) {
          sourceElement = loopIndex2;
          if (*(char *)(inst + 0x1b) == '\0') {
            sourceElement = 0;
          }
          in_r5_artifact = (float *)inst[0x17];
          ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],in_r5_artifact,inst[0x18],inst[0x19],inst[0x1a],
                     inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],sourceElement,opVec + 8);
          if (2 < (uint)inst[0xc]) {
            sourceElement = loopIndex2;
            if (*(char *)(inst + 0x24) == '\0') {
              sourceElement = 0;
            }
            in_r5_artifact = (float *)inst[0x20];
            ((int (*)())_InterpreterLoadSource)(machine,inst[0x1f],in_r5_artifact,inst[0x21],inst[0x22],inst[0x23],
                       inst[0x24],inst[0x25],inst[0x26],inst[0x27],sourceElement,srcC);
          }
        }
      }
      operandComponent = opVec[7];
      switch(opcode) {
      case 0:
switchD_97bd0598_caseD_0:
        opVec[0] = opVec[4];
        opVec[1] = opVec[5];
        opVec[2] = opVec[6];
        opVec[3] = opVec[7];
        break;
      case 1:
        opVec[0] = 1.0;
        if (opVec[4] <= 0.0) {
          opVec[1] = 0.0;
          opVec[2] = 0.0;
        }
        else {
          local_70 = opVec[4];
          fparam_2 = (double)opVec[7];
          opVec[1] = opVec[4];
          powResult = _pow((double)opVec[5],fparam_2);
          opVec[2] = (float)powResult;
        }
        goto LAB_97bd1cd8;
      case 2:
        opVec[0] = ABS(opVec[4]);
        opVec[1] = ABS(opVec[5]);
        opVec[2] = ABS(opVec[6]);
        opVec[3] = ABS(opVec[7]);
        break;
      case 3:
        ceilResult = _ceil((double)opVec[4]);
        opVec[0] = (float)ceilResult;
        ceilResult = _ceil((double)opVec[5]);
        opVec[1] = (float)ceilResult;
        ceilResult = _ceil((double)opVec[6]);
        opVec[2] = (float)ceilResult;
        powValue = _ceil((double)opVec[7]);
        goto LAB_97bd2010;
      case 4:
        floorValue_29 = (double)opVec[4];
        floorResult = _floor(floorValue_29);
        dVar28 = (double)opVec[5];
        opVec[0] = (float)(floorValue_29 - floorResult);
        floorResult = _floor(dVar28);
        floorValue_29 = (double)opVec[6];
        opVec[1] = (float)(dVar28 - floorResult);
        floorResult2 = _floor(floorValue_29);
        floorValue = (double)opVec[7];
        opVec[2] = (float)(floorValue_29 - floorResult2);
        floorResult2 = _floor(floorValue);
        floorValue = floorValue - floorResult2;
        goto LAB_97bd1440;
      case 5:
        floorResult = _floor((double)opVec[4]);
        opVec[0] = (float)floorResult;
        floorResult = _floor((double)opVec[5]);
        opVec[1] = (float)floorResult;
        floorResult = _floor((double)opVec[6]);
        opVec[2] = (float)floorResult;
        powValue = _floor((double)opVec[7]);
        goto LAB_97bd2010;
      default:
        goto switchD_97bd0598_caseD_6;
      case 7:
        if (opVec[4] <= 0.0) {
          if (0.0 <= opVec[4]) {
            opVec[0] = 0.0;
          }
          else {
            opVec[0] = -1.0;
          }
        }
        else {
          opVec[0] = 1.0;
        }
        if (opVec[5] <= 0.0) {
          if (0.0 <= opVec[5]) {
            opVec[1] = 0.0;
          }
          else {
            opVec[1] = -1.0;
          }
        }
        else {
          opVec[1] = 1.0;
        }
        if (opVec[6] <= 0.0) {
          if (0.0 <= opVec[6]) {
            opVec[2] = 0.0;
          }
          else {
            opVec[2] = -1.0;
          }
        }
        else {
          opVec[2] = 1.0;
        }
        if (0.0 < opVec[7]) goto LAB_97bd1cd8;
        if (0.0 <= opVec[7]) goto LAB_97bd1ce0;
        opVec[3] = -1.0;
        break;
      case 8:
        if (((opVec[4] == 0.0) && (opVec[5] == 0.0)) && (opVec[6] == 0.0)) {
LAB_97bd0ab8:
          boolBit = 0;
          if (opVec[7] == 0.0) goto LAB_97bd0ac8;
        }
        boolBit = 1;
        goto LAB_97bd0ac8;
      case 9:
        boolBit = 0;
        if (((opVec[4] != 0.0) && (opVec[5] != 0.0)) && (opVec[6] != 0.0))
        goto LAB_97bd0ab8;
LAB_97bd0ac8:
        uStack_ac = boolBit ^ 0x80000000;
        local_b0 = 0x43300000;
        intAsDouble = (double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0;
LAB_97bd0cc8:
        opVec[0] = (float)intAsDouble;
        opVec[1] = opVec[0];
        opVec[2] = opVec[0];
        opVec[3] = opVec[0];
        break;
      case 10:
        opVec[0] = 1.0;
        if (opVec[4] != 0.0) {
          opVec[0] = 0.0;
        }
        opVec[1] = 1.0;
        if (opVec[5] != 0.0) {
          opVec[1] = 0.0;
        }
        opVec[2] = 1.0;
        if (opVec[6] != 0.0) {
          opVec[2] = 0.0;
        }
        opVec[3] = 1.0;
        if (opVec[7] != 0.0) goto LAB_97bd1ce0;
        break;
      case 0xb:
        bVar4 = *(byte *)((int)inst + 5);
        if (bVar4 == 2) {
          in_r5_artifact = opVec;
          _InterpreterNoiseGeneratorCalculate2D(machine + 1,opVec + 4,opVec);
        }
        else if (bVar4 < 3) {
          if (bVar4 == 1) {
            in_r5_artifact = opVec;
            _InterpreterNoiseGeneratorCalculate1D(machine + 1,opVec + 4,opVec);
          }
        }
        else if (bVar4 == 3) {
          in_r5_artifact = opVec;
          _InterpreterNoiseGeneratorCalculate3D(machine + 1,opVec + 4,opVec);
        }
        else if (bVar4 == 4) {
          in_r5_artifact = opVec;
          _InterpreterNoiseGeneratorCalculate4D(machine + 1,opVec + 4,opVec);
        }
        break;
      case 0xc:
        sqrtResult = _sqrt(ABS((double)opVec[4]));
        opVec[0] = (float)sqrtResult;
        sqrtResult = _sqrt(ABS((double)opVec[5]));
        opVec[1] = (float)sqrtResult;
        sqrtResult = _sqrt(ABS((double)opVec[6]));
        opVec[2] = (float)sqrtResult;
        powValue = _sqrt(ABS((double)opVec[7]));
        goto LAB_97bd2010;
      case 0xd:
        if (*(int *)(*(int *)(emulator + 0xd80) + 0x38) - 0x8b30U < 2) {
          sqrtResult = _sqrt(ABS((double)opVec[4]));
          opVec[0] = (float)(1.0 / sqrtResult);
          sqrtResult = _sqrt(ABS((double)opVec[5]));
          opVec[1] = (float)(1.0 / sqrtResult);
          sqrtResult = _sqrt(ABS((double)opVec[6]));
          opVec[2] = (float)(1.0 / sqrtResult);
          sqrtResult = _sqrt(ABS((double)opVec[7]));
          floorValue = 1.0 / sqrtResult;
          goto LAB_97bd1440;
        }
        sqrtResult = _sqrt(ABS((double)opVec[7]));
        intAsDouble = 1.0 / sqrtResult;
        goto LAB_97bd0cc8;
      case 0xe:
        opVec[0] = 1.0 / opVec[7];
        opVec[1] = opVec[0];
        opVec[2] = opVec[0];
        opVec[3] = opVec[0];
        break;
      case 0xf:
        if (opVec[7] <= 1.8446744e+19) {
          if (opVec[7] < 5.421011e-20) {
            opVec[0] = 1.8446744e+19;
            opVec[1] = opVec[0];
            opVec[2] = opVec[0];
            opVec[3] = opVec[0];
            if (opVec[7] < 0.0) {
              if (opVec[7] <= -5.421011e-20) {
                opVec[0] = -5.421011e-20;
                opVec[1] = opVec[0];
                opVec[2] = opVec[0];
                opVec[3] = opVec[0];
                if (-1.8446744e+19 <= opVec[7]) goto LAB_97bd0d80;
              }
              else {
                opVec[0] = -1.8446744e+19;
                opVec[1] = opVec[0];
                opVec[2] = opVec[0];
                opVec[3] = opVec[0];
              }
            }
          }
          else {
LAB_97bd0d80:
            opVec[0] = 1.0 / opVec[7];
            opVec[1] = opVec[0];
            opVec[2] = opVec[0];
            opVec[3] = opVec[0];
          }
        }
        else {
          opVec[0] = 5.421011e-20;
          opVec[1] = opVec[0];
          opVec[2] = opVec[0];
          opVec[3] = opVec[0];
        }
        break;
      case 0x10:
        if (1 < *(int *)(*(int *)(emulator + 0xd80) + 0x38) - 0x8b30U) {
          mathAccumulator = _exp2((double)opVec[7]);
          goto LAB_97bd1d68;
        }
        exp2Result = _exp2((double)opVec[4]);
        opVec[0] = (float)exp2Result;
        exp2Result = _exp2((double)opVec[5]);
        opVec[1] = (float)exp2Result;
        exp2Result = _exp2((double)opVec[6]);
        opVec[2] = (float)exp2Result;
        powValue = _exp2((double)opVec[7]);
        goto LAB_97bd2010;
      case 0x11:
        floorResult = _floor((double)opVec[7]);
        exp2Result2 = _exp2((double)(float)floorResult);
        opVec[0] = (float)exp2Result2;
        opVec[1] = (float)((double)opVec[7] - (double)(float)floorResult);
        exp2Value = _exp2((double)opVec[7]);
        goto LAB_97bd0fd4;
      case 0x12:
        dimension = (uint)*(byte *)((int)inst + 5);
        mathAccumulator = 0.0;
        if (dimension != 0) {
          componentCursor = opVec + 4;
          do {
            squaredComponent = *componentCursor;
            componentCursor = componentCursor + 1;
            mathAccumulator = (double)(float)((double)squaredComponent * (double)squaredComponent + mathAccumulator);
            dimension = dimension - 1;
          } while (dimension != 0);
        }
LAB_97bd1924:
        mathAccumulator = _sqrt(mathAccumulator);
LAB_97bd1d68:
        opVec[0] = (float)mathAccumulator;
        opVec[1] = opVec[0];
        opVec[2] = opVec[0];
        opVec[3] = opVec[0];
        break;
      case 0x13:
        if (1 < *(int *)(*(int *)(emulator + 0xd80) + 0x38) - 0x8b30U) {
          mathAccumulator = (double)opVec[7];
          if (mathAccumulator < 0.0) {
            mathAccumulator = 0.0;
          }
          mathAccumulator = _log2(mathAccumulator);
          goto LAB_97bd1d68;
        }
        log2Value = (double)opVec[4];
        if (log2Value < 0.0) {
          log2Value = 0.0;
        }
        log2Result = _log2(log2Value);
        dVar28 = (double)opVec[5];
        opVec[0] = (float)log2Result;
        if (dVar28 < 0.0) {
          dVar28 = 0.0;
        }
        log2Result = _log2(dVar28);
        dVar28 = (double)opVec[6];
        opVec[1] = (float)log2Result;
        if (dVar28 < 0.0) {
          dVar28 = 0.0;
        }
        log2Result = _log2(dVar28);
        dVar28 = (double)opVec[7];
        opVec[2] = (float)log2Result;
        if (dVar28 < 0.0) {
          dVar28 = 0.0;
        }
        powValue = _log2(dVar28);
        goto LAB_97bd2010;
      case 0x14:
        dVar28 = ABS((double)opVec[7]);
        log2Result = _log2(dVar28);
        floorResult = _floor(log2Result);
        opVec[0] = (float)floorResult;
        exp2Result = _exp2((double)opVec[0]);
        opVec[1] = (float)(dVar28 / exp2Result);
        if (dVar28 < 0.0) {
          dVar28 = 0.0;
        }
        exp2Value = _log2(dVar28);
LAB_97bd0fd4:
        opVec[2] = (float)exp2Value;
        opVec[3] = 1.0;
        break;
      case 0x15:
        dimension = (uint)*(byte *)((int)inst + 5);
        sqrtValue = 0.0;
        if (dimension != 0) {
          componentCursor = opVec + 4;
          do {
            squaredComponent = *componentCursor;
            componentCursor = componentCursor + 1;
            sqrtValue = (double)(float)((double)squaredComponent * (double)squaredComponent + sqrtValue);
            dimension = dimension - 1;
          } while (dimension != 0);
        }
        sqrtResult = _sqrt(sqrtValue);
        dimension = (uint)*(byte *)((int)inst + 5);
        if (dimension != 0) {
          componentCursor = opVec;
          do {
            *componentCursor = componentCursor[4] / (float)sqrtResult;
            componentCursor = componentCursor + 1;
            dimension = dimension - 1;
          } while (dimension != 0);
        }
        break;
      case 0x16:
        degRadFactor = 0.017453292;
        goto LAB_97bd109c;
      case 0x17:
        degRadFactor = 57.29578;
LAB_97bd109c:
        opVec[0] = opVec[4] * degRadFactor;
        opVec[1] = opVec[5] * degRadFactor;
        opVec[2] = opVec[6] * degRadFactor;
        opVec[3] = opVec[7] * degRadFactor;
        break;
      case 0x18:
        cosResult = _cos((double)opVec[4]);
        opVec[0] = (float)cosResult;
        sinResult = _sin((double)opVec[4]);
        opVec[1] = (float)sinResult;
        opVec[3] = 0.0;
        opVec[2] = 0.0;
        break;
      case 0x19:
        if (1 < *(int *)(*(int *)(emulator + 0xd80) + 0x38) - 0x8b30U) {
          mathAccumulator = _sin((double)opVec[7]);
          goto LAB_97bd1d68;
        }
        sinResult = _sin((double)opVec[4]);
        opVec[0] = (float)sinResult;
        sinResult = _sin((double)opVec[5]);
        opVec[1] = (float)sinResult;
        sinResult = _sin((double)opVec[6]);
        opVec[2] = (float)sinResult;
        powValue = _sin((double)opVec[7]);
        goto LAB_97bd2010;
      case 0x1a:
        if (1 < *(int *)(*(int *)(emulator + 0xd80) + 0x38) - 0x8b30U) {
          mathAccumulator = _cos((double)opVec[7]);
          goto LAB_97bd1d68;
        }
        cosResult = _cos((double)opVec[4]);
        opVec[0] = (float)cosResult;
        cosResult = _cos((double)opVec[5]);
        opVec[1] = (float)cosResult;
        cosResult = _cos((double)opVec[6]);
        opVec[2] = (float)cosResult;
        powValue = _cos((double)opVec[7]);
        goto LAB_97bd2010;
      case 0x1b:
        tanResult = _tan((double)opVec[4]);
        opVec[0] = (float)tanResult;
        tanResult = _tan((double)opVec[5]);
        opVec[1] = (float)tanResult;
        tanResult = _tan((double)opVec[6]);
        opVec[2] = (float)tanResult;
        powValue = _tan((double)opVec[7]);
        goto LAB_97bd2010;
      case 0x1c:
        asinResult = _asin((double)opVec[4]);
        opVec[0] = (float)asinResult;
        asinResult = _asin((double)opVec[5]);
        opVec[1] = (float)asinResult;
        asinResult = _asin((double)opVec[6]);
        opVec[2] = (float)asinResult;
        powValue = _asin((double)opVec[7]);
        goto LAB_97bd2010;
      case 0x1d:
        acosResult = _acos((double)opVec[4]);
        opVec[0] = (float)acosResult;
        acosResult = _acos((double)opVec[5]);
        opVec[1] = (float)acosResult;
        acosResult = _acos((double)opVec[6]);
        opVec[2] = (float)acosResult;
        powValue = _acos((double)opVec[7]);
        goto LAB_97bd2010;
      case 0x1e:
        if (inst[0xc] == 1) {
          atanResult = _atan((double)opVec[4]);
          opVec[0] = (float)atanResult;
          atanResult = _atan((double)opVec[5]);
          opVec[1] = (float)atanResult;
          atanResult = _atan((double)opVec[6]);
          opVec[2] = (float)atanResult;
          powValue = _atan((double)opVec[7]);
          goto LAB_97bd2010;
        }
        opVec[0] = _atan2f(opVec[4],opVec[8]);
        opVec[1] = _atan2f(opVec[5],opVec[9]);
        opVec[2] = _atan2f(opVec[6],opVec[10]);
        fparam_2 = (double)opVec[0xb];
        opVec[3] = _atan2f(opVec[7],opVec[0xb]);
        break;
      case 0x1f:
        opVec[0] = opVec[4] + opVec[8];
        opVec[1] = opVec[5] + opVec[9];
        opVec[2] = opVec[6] + opVec[10];
        opVec[3] = opVec[7] + opVec[0xb];
        break;
      case 0x20:
        opVec[0] = opVec[4] - opVec[8];
        opVec[1] = opVec[5] - opVec[9];
        opVec[2] = opVec[6] - opVec[10];
        opVec[3] = opVec[7] - opVec[0xb];
        break;
      case 0x21:
        if (*(char *)((int)inst + 0x6d) == '\x01') {
          floorValue = (double)opVec[4];
          floorValue_31 = (double)opVec[8];
          floorResult2 = _floor((double)(float)(floorValue / floorValue_31));
          floorValue_29 = (double)opVec[5];
          floorValue_30 = (double)opVec[8];
          opVec[0] = (float)-(floorValue_31 * floorResult2 - floorValue);
          floorResult = _floor((double)(float)(floorValue_29 / floorValue_30));
          dVar28 = (double)opVec[6];
          floorValue_31 = (double)opVec[8];
          opVec[1] = (float)-(floorValue_30 * floorResult - floorValue_29);
          floorResult = _floor((double)(float)(dVar28 / floorValue_31));
          operandComponent = opVec[8];
        }
        else {
          floorValue = (double)opVec[4];
          floorValue_31 = (double)opVec[8];
          floorResult2 = _floor((double)(float)(floorValue / floorValue_31));
          floorValue_29 = (double)opVec[5];
          floorValue_30 = (double)opVec[9];
          opVec[0] = (float)-(floorValue_31 * floorResult2 - floorValue);
          floorResult = _floor((double)(float)(floorValue_29 / floorValue_30));
          dVar28 = (double)opVec[6];
          floorValue_31 = (double)opVec[10];
          opVec[1] = (float)-(floorValue_30 * floorResult - floorValue_29);
          floorResult = _floor((double)(float)(dVar28 / floorValue_31));
          operandComponent = opVec[0xb];
        }
        floorValue_29 = (double)opVec[7];
        opVec[2] = (float)-(floorValue_31 * floorResult - dVar28);
        floorResult = _floor((double)(float)(floorValue_29 / (double)operandComponent));
        floorValue = -((double)operandComponent * floorResult - floorValue_29);
LAB_97bd1440:
        opVec[3] = (float)floorValue;
        break;
      case 0x22:
      case 0x31:
      case 0x36:
        break;
      case 0x23:
        opVec[0] = opVec[4] * opVec[8];
        opVec[1] = opVec[5] * opVec[9];
        opVec[2] = opVec[6] * opVec[10];
        opVec[3] = opVec[7] * opVec[0xb];
        break;
      case 0x24:
        boolBit = 0;
        if ((opVec[4] != 0.0) && (opVec[8] != 0.0)) {
          boolBit = 1;
        }
        boolBit8 = 0;
        opVec[0] = (float)((double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0
                              );
        if ((opVec[5] != 0.0) && (opVec[9] != 0.0)) {
          boolBit8 = 1;
        }
        boolBit = 0;
        opVec[1] = (float)((double)CONCAT44(0x43300000,boolBit8 ^ 0x80000000) - 4503601774854144.0)
        ;
        if ((opVec[6] != 0.0) && (opVec[10] != 0.0)) {
          boolBit = 1;
        }
        boolBit8 = 0;
        opVec[2] = (float)((double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0
                              );
        if (opVec[7] != 0.0) {
LAB_97bd17d0:
          boolBit8 = 0;
          if (opVec[0xb] != 0.0) goto LAB_97bd17ec;
        }
        goto LAB_97bd17f0;
      case 0x25:
        boolBit = 0;
        if ((opVec[4] != 0.0) || (opVec[8] != 0.0)) {
          boolBit = 1;
        }
        boolBit8 = 0;
        opVec[0] = (float)((double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0
                              );
        if ((opVec[5] != 0.0) || (opVec[9] != 0.0)) {
          boolBit8 = 1;
        }
        boolBit = 0;
        opVec[1] = (float)((double)CONCAT44(0x43300000,boolBit8 ^ 0x80000000) - 4503601774854144.0)
        ;
        if ((opVec[6] != 0.0) || (opVec[10] != 0.0)) {
          boolBit = 1;
        }
        opVec[2] = (float)((double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0
                              );
        if (opVec[7] == 0.0) goto LAB_97bd17d0;
LAB_97bd17ec:
        boolBit8 = 1;
        goto LAB_97bd17f0;
      case 0x26:
        boolBit = 0;
        if (opVec[4] == 0.0) {
          if (opVec[8] != 0.0) {
LAB_97bd16cc:
            boolBit = 1;
          }
        }
        else if (opVec[8] == 0.0) goto LAB_97bd16cc;
        boolBit8 = 0;
        opVec[0] = (float)((double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0
                              );
        if (opVec[5] == 0.0) {
          if (opVec[9] != 0.0) {
LAB_97bd172c:
            boolBit8 = 1;
          }
        }
        else if (opVec[9] == 0.0) goto LAB_97bd172c;
        boolBit = 0;
        opVec[1] = (float)((double)CONCAT44(0x43300000,boolBit8 ^ 0x80000000) - 4503601774854144.0)
        ;
        if (opVec[6] == 0.0) {
          if (opVec[10] != 0.0) {
LAB_97bd178c:
            boolBit = 1;
          }
        }
        else if (opVec[10] == 0.0) goto LAB_97bd178c;
        boolBit8 = 0;
        opVec[2] = (float)((double)CONCAT44(0x43300000,boolBit ^ 0x80000000) - 4503601774854144.0
                              );
        if (opVec[7] == 0.0) goto LAB_97bd17d0;
        if (opVec[0xb] == 0.0) goto LAB_97bd17ec;
LAB_97bd17f0:
        uStack_ac = boolBit8 ^ 0x80000000;
        local_b0 = 0x43300000;
        opVec[3] = (float)((double)CONCAT44(0x43300000,boolBit8 ^ 0x80000000) - 4503601774854144.0)
        ;
        break;
      case 0x27:
        dimension = (uint)*(byte *)((int)inst + 5);
        opVec[0] = 0.0;
        opVec[1] = opVec[0];
        opVec[2] = opVec[0];
        opVec[3] = opVec[0];
        if (dimension != 0) {
          componentCursor = opVec;
          do {
            srcElementPtr = componentCursor + 4;
            pfVar1 = componentCursor + 8;
            componentCursor = componentCursor + 1;
            opVec[0] = *srcElementPtr * *pfVar1 + opVec[0];
            dimension = dimension - 1;
            opVec[1] = opVec[0];
            opVec[2] = opVec[0];
            opVec[3] = opVec[0];
          } while (dimension != 0);
        }
        break;
      case 0x28:
        opVec[0] = opVec[6] * opVec[10] +
                       opVec[4] * opVec[8] + opVec[5] * opVec[9];
        opVec[1] = opVec[0];
        opVec[2] = opVec[0];
        opVec[3] = opVec[0];
        break;
      case 0x29:
        opVec[0] = opVec[7] * opVec[0xb] +
                       opVec[6] * opVec[10] +
                       opVec[4] * opVec[8] + opVec[5] * opVec[9];
        opVec[1] = opVec[0];
        opVec[2] = opVec[0];
        opVec[3] = opVec[0];
        break;
      case 0x2a:
        opVec[0] = opVec[6] * opVec[10] +
                       opVec[4] * opVec[8] + opVec[5] * opVec[9] + opVec[0xb];
        opVec[1] = opVec[0];
        opVec[2] = opVec[0];
        opVec[3] = opVec[0];
        break;
      case 0x2b:
        if (*(int *)(*(int *)(emulator + 0xd80) + 0x38) - 0x8b30U < 2) {
          dimension = (uint)*(byte *)((int)inst + 5);
          mathAccumulator = 0.0;
          if (dimension != 0) {
            componentCursor = opVec;
            do {
              srcElementPtr = componentCursor + 4;
              pfVar1 = componentCursor + 8;
              componentCursor = componentCursor + 1;
              mathAccumulator = (double)(float)((double)(*srcElementPtr - *pfVar1) * (double)(*srcElementPtr - *pfVar1) +
                                      mathAccumulator);
              dimension = dimension - 1;
            } while (dimension != 0);
          }
          goto LAB_97bd1924;
        }
        opVec[0] = 1.0;
        opVec[1] = opVec[5] * opVec[9];
        opVec[2] = opVec[6];
        opVec[3] = opVec[0xb];
        break;
      case 0x2c:
        opVec[0] = opVec[8];
        if (opVec[4] < opVec[8]) {
          opVec[0] = opVec[4];
        }
        opVec[1] = opVec[9];
        if (opVec[5] < opVec[9]) {
          opVec[1] = opVec[5];
        }
        opVec[2] = opVec[10];
        if (opVec[6] < opVec[10]) {
          opVec[2] = opVec[6];
        }
        opVec[3] = opVec[0xb];
        if (opVec[7] < opVec[0xb]) {
LAB_97bd2210:
          opVec[3] = operandComponent;
        }
        break;
      case 0x2d:
        opVec[0] = opVec[8];
        if (opVec[8] < opVec[4]) {
          opVec[0] = opVec[4];
        }
        opVec[1] = opVec[9];
        if (opVec[9] < opVec[5]) {
          opVec[1] = opVec[5];
        }
        opVec[2] = opVec[10];
        if (opVec[10] < opVec[6]) {
          opVec[2] = opVec[6];
        }
        opVec[3] = opVec[0xb];
        if (opVec[0xb] < opVec[7]) goto LAB_97bd2210;
        break;
      case 0x2e:
        fparam_6 = (double)opVec[10];
        fparam_7 = (double)opVec[9];
        fparam_8 = (double)opVec[8];
        opVec[0] = (float)((double)opVec[5] * fparam_6 -
                              (double)(float)(fparam_7 * (double)opVec[6]));
        opVec[2] = (float)((double)opVec[4] * fparam_7 -
                              (double)(float)(fparam_8 * (double)opVec[5]));
        opVec[1] = (float)((double)opVec[6] * fparam_8 -
                              (double)(float)(fparam_6 * (double)opVec[4]));
        goto LAB_97bd1ce0;
      case 0x2f:
        dimension = (uint)*(byte *)((int)inst + 5);
        fVar6 = 0.0;
        if (dimension != 0) {
          componentCursor = opVec;
          do {
            srcElementPtr = componentCursor + 4;
            pfVar1 = componentCursor + 8;
            componentCursor = componentCursor + 1;
            fVar6 = *srcElementPtr * *pfVar1 + fVar6;
            dimension = dimension - 1;
          } while (dimension != 0);
        }
        fVar6 = fVar6 + fVar6;
        opVec[0] = -(fVar6 * opVec[8] - opVec[4]);
        opVec[1] = -(fVar6 * opVec[9] - opVec[5]);
        opVec[2] = -(fVar6 * opVec[10] - opVec[6]);
        opVec[3] = -(fVar6 * opVec[0xb] - opVec[7]);
        break;
      case 0x30:
        opVec[0] = 1.0;
        opVec[1] = opVec[0];
        opVec[2] = opVec[0];
        opVec[3] = opVec[0];
        break;
      case 0x32:
        opVec[0] = 1.0;
        if (opVec[4] < opVec[8]) {
          opVec[0] = 0.0;
        }
        opVec[1] = 1.0;
        if (opVec[5] < opVec[9]) {
          opVec[1] = 0.0;
        }
        opVec[2] = 1.0;
        if (opVec[6] < opVec[10]) {
          opVec[2] = 0.0;
        }
        bVar2 = opVec[0xb] <= opVec[7];
        goto LAB_97bd1c60;
      case 0x33:
        if (opVec[4] <= opVec[8]) {
          opVec[0] = 0.0;
        }
        else {
          opVec[0] = 1.0;
        }
        if (opVec[5] <= opVec[9]) {
          opVec[1] = 0.0;
        }
        else {
          opVec[1] = 1.0;
        }
        if (opVec[6] <= opVec[10]) {
          opVec[2] = 0.0;
        }
        else {
          opVec[2] = 1.0;
        }
        if (opVec[7] <= opVec[0xb]) goto LAB_97bd1ce0;
        goto LAB_97bd1cd8;
      case 0x34:
        opVec[0] = 1.0;
        if (opVec[8] < opVec[4]) {
          opVec[0] = 0.0;
        }
        opVec[1] = 1.0;
        if (opVec[9] < opVec[5]) {
          opVec[1] = 0.0;
        }
        opVec[2] = 1.0;
        if (opVec[10] < opVec[6]) {
          opVec[2] = 0.0;
        }
        bVar2 = opVec[7] <= opVec[0xb];
LAB_97bd1c60:
        opVec[3] = 1.0;
        if (!bVar2) {
LAB_97bd1ce0:
          opVec[3] = 0.0;
        }
        break;
      case 0x35:
        if (opVec[8] <= opVec[4]) {
          opVec[0] = 0.0;
        }
        else {
          opVec[0] = 1.0;
        }
        if (opVec[9] <= opVec[5]) {
          opVec[1] = 0.0;
        }
        else {
          opVec[1] = 1.0;
        }
        if (opVec[10] <= opVec[6]) {
          opVec[2] = 0.0;
        }
        else {
          opVec[2] = 1.0;
        }
        if (opVec[0xb] <= opVec[7]) goto LAB_97bd1ce0;
LAB_97bd1cd8:
        opVec[3] = 1.0;
        break;
      case 0x37:
        opVec[0] = 0.0;
        opVec[1] = opVec[0];
        opVec[2] = opVec[0];
        opVec[3] = opVec[0];
        break;
      case 0x38:
        if (1 < *(int *)(*(int *)(emulator + 0xd80) + 0x38) - 0x8b30U) {
          fparam_2 = (double)opVec[0xb];
          mathAccumulator = _pow((double)opVec[7],fparam_2);
          goto LAB_97bd1d68;
        }
        powResult = _pow((double)opVec[4],(double)opVec[8]);
        opVec[0] = (float)powResult;
        powResult = _pow((double)opVec[5],(double)opVec[9]);
        opVec[1] = (float)powResult;
        powResult = _pow((double)opVec[6],(double)opVec[10]);
        fparam_2 = (double)opVec[0xb];
        opVec[2] = (float)powResult;
        powValue = _pow((double)opVec[7],fparam_2);
        goto LAB_97bd2010;
      case 0x39:
        if (2.1474836e+09 <= opVec[8]) {
          intComponentI14 = (int)(opVec[8] - 2.1474836e+09);
          local_a0 = (longlong)intComponentI14;
        }
        else {
          intComponentI14 = (int)opVec[8];
          local_a8 = (longlong)intComponentI14;
        }
        opVec[0] = opVec[intComponentI14 + 4];
        if (2.1474836e+09 <= opVec[8]) {
          intComponentI14 = (int)(opVec[8] - 2.1474836e+09);
          local_a8 = (longlong)intComponentI14;
        }
        else {
          intComponentI14 = (int)opVec[8];
          local_a0 = (longlong)intComponentI14;
        }
        opVec[1] = opVec[intComponentI14 + 4];
        if (2.1474836e+09 <= opVec[8]) {
          intComponentI14 = (int)(opVec[8] - 2.1474836e+09);
          local_a8 = (longlong)intComponentI14;
        }
        else {
          intComponentI14 = (int)opVec[8];
          local_a0 = (longlong)intComponentI14;
        }
        opVec[2] = opVec[intComponentI14 + 4];
        if (2.1474836e+09 <= opVec[8]) {
          intComponentI14 = (int)(opVec[8] - 2.1474836e+09);
          local_a8 = (longlong)intComponentI14;
        }
        else {
          intComponentI14 = (int)opVec[8];
          local_a0 = (longlong)intComponentI14;
        }
        opVec[3] = opVec[intComponentI14 + 4];
        break;
      case 0x3a:
        if (inst[9] == 1) {
          opVec[0] = opVec[4] / opVec[8];
          opVec[1] = opVec[5] / opVec[9];
          opVec[2] = opVec[6] / opVec[10];
          opVec[3] = opVec[7] / opVec[0xb];
        }
        else if (inst[9] == 3) {
          truncResult = _trunc((double)(opVec[4] / opVec[8]));
          opVec[0] = (float)truncResult;
          truncResult = _trunc((double)(opVec[5] / opVec[9]));
          opVec[1] = (float)truncResult;
          truncResult = _trunc((double)(opVec[6] / opVec[10]));
          operandComponent = opVec[7] / opVec[0xb];
          goto LAB_97bd200c;
        }
        break;
      case 0x3b:
        dimension = (uint)*(byte *)((int)inst + 5);
        fVar6 = 0.0;
        if (dimension != 0) {
          componentCursor = opVec;
          do {
            srcElementPtr = componentCursor + 0xc;
            pfVar1 = componentCursor + 8;
            componentCursor = componentCursor + 1;
            fVar6 = *srcElementPtr * *pfVar1 + fVar6;
            dimension = dimension - 1;
          } while (dimension != 0);
        }
        if (fVar6 < 0.0) goto switchD_97bd0598_caseD_0;
        opVec[0] = -opVec[4];
        opVec[1] = -opVec[5];
        opVec[2] = -opVec[6];
        opVec[3] = -opVec[7];
        break;
      case 0x3c:
        fparam_5 = (double)((float)(1.0 - (double)opVec[7]) * srcC[3]);
        opVec[0] = opVec[4] * opVec[8] + (1.0 - opVec[4]) * srcC[0];
        opVec[1] = opVec[5] * opVec[9] + (1.0 - opVec[5]) * srcC[1];
        fparam_8 = (double)opVec[1];
        opVec[2] = opVec[6] * opVec[10] + (1.0 - opVec[6]) * srcC[2];
        fparam_7 = (double)opVec[2];
        opVec[3] = (float)((double)opVec[7] * (double)opVec[0xb] + fparam_5);
        fparam_6 = (double)opVec[3];
        break;
      case 0x3d:
        operandComponent = opVec[8];
        if (opVec[8] < opVec[4]) {
          operandComponent = opVec[4];
        }
        opVec[0] = srcC[0];
        if ((operandComponent < srcC[0]) && (opVec[0] = opVec[8], opVec[8] < opVec[4])) {
          opVec[0] = opVec[4];
        }
        operandComponent = opVec[9];
        if (opVec[9] < opVec[5]) {
          operandComponent = opVec[5];
        }
        opVec[1] = srcC[1];
        if ((operandComponent < srcC[1]) && (opVec[1] = opVec[9], opVec[9] < opVec[5])) {
          opVec[1] = opVec[5];
        }
        operandComponent = opVec[10];
        if (opVec[10] < opVec[6]) {
          operandComponent = opVec[6];
        }
        opVec[2] = srcC[2];
        if ((operandComponent < srcC[2]) && (opVec[2] = opVec[10], opVec[10] < opVec[6]))
        {
          opVec[2] = opVec[6];
        }
        operandComponent = opVec[0xb];
        if (opVec[0xb] < opVec[7]) {
          operandComponent = opVec[7];
        }
        opVec[3] = srcC[3];
        if ((operandComponent < srcC[3]) &&
           (operandComponent = opVec[0xb], opVec[3] = opVec[7], opVec[7] <= opVec[0xb]))
        goto LAB_97bd2210;
        break;
      case 0x3e:
        opVec[0] = srcC[0];
        if (opVec[4] < 0.0) {
          opVec[0] = opVec[8];
        }
        opVec[1] = srcC[1];
        if (opVec[5] < 0.0) {
          opVec[1] = opVec[9];
        }
        opVec[2] = srcC[2];
        if (opVec[6] < 0.0) {
          opVec[2] = opVec[10];
        }
        opVec[3] = srcC[3];
        if (opVec[7] < 0.0) {
          opVec[3] = opVec[0xb];
        }
        break;
      case 0x3f:
        opVec[0] = opVec[4] * opVec[8] + srcC[0];
        opVec[1] = opVec[5] * opVec[9] + srcC[1];
        opVec[2] = opVec[6] * opVec[10] + srcC[2];
        opVec[3] = opVec[7] * opVec[0xb] + srcC[3];
        break;
      case 0x40:
        operandComponent = (srcC[0] - opVec[4]) / (opVec[8] - opVec[4]);
        if ((operandComponent <= 0.0) || (operandComponent < 1.0)) {
          if (operandComponent <= 0.0) {
            operandComponent = 0.0;
          }
        }
        else {
          operandComponent = 1.0;
        }
        fVar7 = (srcC[1] - opVec[5]) / (opVec[9] - opVec[5]);
        opVec[0] = operandComponent * operandComponent * (3.0 - (operandComponent + operandComponent));
        if ((fVar7 <= 0.0) || (fVar7 < 1.0)) {
          if (fVar7 <= 0.0) {
            fVar7 = 0.0;
          }
        }
        else {
          fVar7 = 1.0;
        }
        operandComponent = (srcC[2] - opVec[6]) / (opVec[10] - opVec[6]);
        opVec[1] = fVar7 * fVar7 * (3.0 - (fVar7 + fVar7));
        if ((operandComponent <= 0.0) || (operandComponent < 1.0)) {
          if (operandComponent <= 0.0) {
            operandComponent = 0.0;
          }
        }
        else {
          operandComponent = 1.0;
        }
        fVar7 = (srcC[3] - opVec[7]) / (opVec[0xb] - opVec[7]);
        opVec[2] = operandComponent * operandComponent * (3.0 - (operandComponent + operandComponent));
        if ((fVar7 <= 0.0) || (fVar7 < 1.0)) {
          if (fVar7 <= 0.0) {
            fVar7 = 0.0;
          }
        }
        else {
          fVar7 = 1.0;
        }
        opVec[3] = fVar7 * fVar7 * (3.0 - (fVar7 + fVar7));
        break;
      case 0x41:
        swizzleSelect = *(char *)(inst + 0x18);
        opVec[0] = opVec[4];
        if ((((swizzleSelect != '\0') && (opVec[0] = opVec[5], swizzleSelect != '\x01')) &&
            (opVec[0] = opVec[6], swizzleSelect != '\x02')) &&
           (opVec[0] = opVec[7], swizzleSelect != '\x03')) {
          operandComponent = opVec[4];
          if (((swizzleSelect == '\x04') || (operandComponent = opVec[5], swizzleSelect == '\x05')) ||
             ((operandComponent = opVec[6], swizzleSelect == '\x06' || (operandComponent = opVec[7], swizzleSelect == '\a')))) {
            opVec[0] = -operandComponent;
          }
          else {
            opVec[0] = 0.0;
            if (((swizzleSelect != '\t') && (opVec[0] = 1.0, swizzleSelect != '\b')) &&
               (opVec[0] = -1.0, swizzleSelect != '\n')) {
              opVec[0] = 0.0;
            }
          }
        }
        swizzleSelect = *(char *)((int)inst + 0x61);
        opVec[1] = opVec[4];
        if ((((swizzleSelect != '\0') && (opVec[1] = opVec[5], swizzleSelect != '\x01')) &&
            (opVec[1] = opVec[6], swizzleSelect != '\x02')) &&
           (opVec[1] = opVec[7], swizzleSelect != '\x03')) {
          operandComponent = opVec[4];
          if (((swizzleSelect == '\x04') || (operandComponent = opVec[5], swizzleSelect == '\x05')) ||
             ((operandComponent = opVec[6], swizzleSelect == '\x06' || (operandComponent = opVec[7], swizzleSelect == '\a')))) {
            opVec[1] = -operandComponent;
          }
          else {
            opVec[1] = 0.0;
            if (((swizzleSelect != '\t') && (opVec[1] = 1.0, swizzleSelect != '\b')) &&
               (opVec[1] = -1.0, swizzleSelect != '\n')) {
              opVec[1] = 0.0;
            }
          }
        }
        swizzleSelect = *(char *)((int)inst + 0x62);
        opVec[2] = opVec[4];
        if ((((swizzleSelect != '\0') && (opVec[2] = opVec[5], swizzleSelect != '\x01')) &&
            (opVec[2] = opVec[6], swizzleSelect != '\x02')) &&
           (opVec[2] = opVec[7], swizzleSelect != '\x03')) {
          operandComponent = opVec[4];
          if (((swizzleSelect == '\x04') || (operandComponent = opVec[5], swizzleSelect == '\x05')) ||
             ((operandComponent = opVec[6], swizzleSelect == '\x06' || (operandComponent = opVec[7], swizzleSelect == '\a')))) {
            opVec[2] = -operandComponent;
          }
          else {
            opVec[2] = 0.0;
            if (((swizzleSelect != '\t') && (opVec[2] = 1.0, swizzleSelect != '\b')) &&
               (opVec[2] = -1.0, swizzleSelect != '\n')) {
              opVec[2] = 0.0;
            }
          }
        }
        swizzleSelect = *(char *)((int)inst + 99);
        opVec[3] = opVec[4];
        if ((((swizzleSelect != '\0') && (opVec[3] = opVec[5], swizzleSelect != '\x01')) &&
            (opVec[3] = opVec[6], swizzleSelect != '\x02')) &&
           (opVec[3] = opVec[7], swizzleSelect != '\x03')) {
          operandComponent = opVec[4];
          if (((swizzleSelect == '\x04') || (operandComponent = opVec[5], swizzleSelect == '\x05')) ||
             ((operandComponent = opVec[6], swizzleSelect == '\x06' || (operandComponent = opVec[7], swizzleSelect == '\a')))) {
            opVec[3] = -operandComponent;
          }
          else {
            opVec[3] = 0.0;
            if (((swizzleSelect != '\t') && (opVec[3] = 1.0, swizzleSelect != '\b')) &&
               (opVec[3] = -1.0, swizzleSelect != '\n')) {
              opVec[3] = 0.0;
            }
          }
        }
        break;
      case 0x42:
      case 0x43:
      case 0x44:
      case 0x45:
        ((int (*)())_InterpreterTextureSamplerAttachGLDContext)(machine[0x28b],*(undefined4 *)(emulator + 0xd9c));
        destElement = 0;
        if ((opcode == 0x43) || (opcode == 0x45)) {
          destElement = 1;
        }
        ((int (*)())_InterpreterTextureSamplerSetProjectionEnabled)(machine[0x28b],destElement);
        ((int (*)())_InterpreterTextureSamplerSetLodBiasEnabled)(machine[0x28b],(uint)(opcode == 0x44 || opcode - 0x44U == 1));
        ((void (*)())_InterpreterTextureSamplerAttachDerivatives)(machine[0x28b],*(undefined4 *)(emulator + 0xda4),(double)GH_U2F((unsigned int)(machine[0x28f])));
        fVar7 = opVec[7];
        operandComponent = 0.0;
        if (opcode - 0x44U < 2) {
          programInfo = *(int *)(emulator + 0xd80);
          operandComponent = srcC[0];
          if (1 < *(int *)(programInfo + 0x38) - 0x8b30U) {
            opVec[7] = 1.0;
            operandComponent = fVar7;
            goto LAB_97bd29a8;
          }
        }
        else {
LAB_97bd29a8:
          programInfo = *(int *)(emulator + 0xd80);
        }
        dVar27 = (double)operandComponent;
        if (*(int *)(programInfo + 0x38) - 0x8b30U < 2) {
          if (2.1474836e+09 <= opVec[8]) {
            local_98 = (longlong)(int)(opVec[8] - 2.1474836e+09);
            intComponent = (int)(opVec[8] - 2.1474836e+09) ^ 0x80000000;
          }
          else {
            intComponent = (uint)(int)opVec[8];
            local_90 = (longlong)(int)intComponent;
          }
        }
        else {
          intComponent = inst[0x43];
        }
        textureTarget = inst[0x44];
        if (textureTarget == 2) {
          _InterpreterTextureSamplerSampleTexelRECT
                    (machine[0x28b],intComponent,in_r5_artifact,opVec + 4,&local_80);
        }
        else if (textureTarget < 3) {
          if (textureTarget == 1) {
            ((void (*)())_InterpreterTextureSamplerSampleTexel3D)(machine[0x28b],intComponent,in_r5_artifact,opVec + 4,&local_80,dVar27,fparam_2,fparam_3,
                       fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_fffffe78,
                       in_stack_fffffe80,in_stack_fffffe88,in_stack_fffffe90);
          }
        }
        else if (textureTarget == 3) {
          ((void (*)())_InterpreterTextureSamplerSampleTexel2D)(machine[0x28b],intComponent,in_r5_artifact,opVec + 4,&local_80,dVar27,fparam_2,fparam_3,
                     fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_fffffe78,
                     in_stack_fffffe80,in_stack_fffffe88,in_stack_fffffe90,in_stack_fffffe98);
        }
        else if (textureTarget == 4) {
          ((void (*)())_InterpreterTextureSamplerSampleTexel1D)(machine[0x28b],intComponent,in_r5_artifact,opVec + 4,&local_80,dVar27,fparam_2,fparam_3,
                     fparam_4,fparam_5,fparam_6,fparam_7,fparam_8,in_stack_fffffe78,
                     in_stack_fffffe80,in_stack_fffffe88,in_stack_fffffe90);
        }
        opVec[0] = local_80;
        opVec[1] = local_7c;
        opVec[2] = local_78;
        opVec[3] = local_74;
        break;
      case 0x48:
      case 0x49:
        floorResult = _floor((double)opVec[4]);
        if (2147483648.0 <= floorResult) {
          local_98 = (longlong)(int)(floorResult - 2147483648.0);
          intComponent = (int)(floorResult - 2147483648.0) ^ 0x80000000;
        }
        else {
          intComponent = (uint)(int)floorResult;
          local_90 = (longlong)(int)intComponent;
        }
        machine[0x290] = intComponent;
        goto switchD_97bd0598_caseD_6;
      case 0x4b:
        in_r5_artifact = (float *)inst[4];
        conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                    inst[8],inst[9],inst[10],inst[0xb],0);
        if (conditionResult == 0) {
          in_r5_artifact = (float *)inst[4];
          conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                      inst[8],inst[9],inst[10],inst[0xb],1);
          if (conditionResult == 0) {
            in_r5_artifact = (float *)inst[4];
            conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                        inst[8],inst[9],inst[10],inst[0xb],2);
            if (conditionResult == 0) {
              in_r5_artifact = (float *)inst[4];
              conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                          inst[8],inst[9],inst[10],inst[0xb],3);
              if (conditionResult == 0) goto switchD_97bd0598_caseD_6;
            }
          }
        }
      case 0x54:
      case 0x58:
      case 0x6b:
switchD_97bd0598_caseD_54:
        nextInst = (int *)((**(int **)(emulator + 0xd80) + inst[2] * 0x11c) - 0x11c);
        if ((int *)(*(int **)(emulator + 0xd80))[1] < nextInst) {
          nextInst = (int *)0x0;
        }
switchD_97bd0598_caseD_6:
        bVar25 = false;
        break;
      case 0x4c:
        in_r5_artifact = (float *)inst[4];
        conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                    inst[8],inst[9],inst[10],inst[0xb],0);
        if (conditionResult == 0) {
          in_r5_artifact = (float *)inst[4];
          conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                      inst[8],inst[9],inst[10],inst[0xb],1);
          if (conditionResult == 0) {
            in_r5_artifact = (float *)inst[4];
            conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                        inst[8],inst[9],inst[10],inst[0xb],2);
            if (conditionResult == 0) {
              in_r5_artifact = (float *)inst[4];
              conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                          inst[8],inst[9],inst[10],inst[0xb],3);
              if (conditionResult == 0) goto switchD_97bd0598_caseD_6;
            }
          }
        }
        if ((uint *)machine[0x29b] + 1 <= machine + 0x29b) {
          *(uint *)machine[0x29b] = (uint)nextInst;
          machine[0x29b] = machine[0x29b] + 4;
          goto switchD_97bd0598_caseD_54;
        }
        break;
      case 0x4d:
        in_r5_artifact = (float *)inst[4];
        conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                    inst[8],inst[9],inst[10],inst[0xb],0);
        if (conditionResult == 0) {
          in_r5_artifact = (float *)inst[4];
          conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                      inst[8],inst[9],inst[10],inst[0xb],1);
          if (conditionResult == 0) {
            in_r5_artifact = (float *)inst[4];
            conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                        inst[8],inst[9],inst[10],inst[0xb],2);
            if (conditionResult == 0) {
              in_r5_artifact = (float *)inst[4];
              conditionResult = ((int (*)())_InterpreterTestCR)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],
                                          inst[8],inst[9],inst[10],inst[0xb],3);
              if (conditionResult == 0) goto switchD_97bd0598_caseD_6;
            }
          }
        }
        iVar14 = machine[0x29b];
        nextInst = (int *)0x0;
        piVar11 = (int *)(iVar14 - 4);
        if (machine + 0x297 <= piVar11) {
          machine[0x29b] = (int)piVar11;
          nextInst = *(int **)(iVar14 + -4);
        }
        goto switchD_97bd0598_caseD_6;
      case 0x4f:
        if (((opVec[4] < 0.0) || (opVec[5] < 0.0)) ||
           ((opVec[6] < 0.0 || (opVec[7] < 0.0)))) {
          machine[0x296] = 1;
        }
        goto switchD_97bd0598_caseD_6;
      case 0x55:
        if ((((opVec[4] == 0.0) && (opVec[5] == 0.0)) && (opVec[6] == 0.0)) &&
           (opVec[7] == 0.0)) goto switchD_97bd0598_caseD_54;
        break;
      case 0x68:
        dimension = (uint)*(byte *)((int)inst + 5);
        operandComponent = 0.0;
        if (dimension != 0) {
          componentCursor = opVec;
          do {
            srcElementPtr = componentCursor + 4;
            pfVar1 = componentCursor + 8;
            componentCursor = componentCursor + 1;
            operandComponent = *srcElementPtr * *pfVar1 + operandComponent;
            dimension = dimension - 1;
          } while (dimension != 0);
        }
        sqrtValue = (double)-(srcC[0] * srcC[0] * (1.0 - operandComponent * operandComponent) - 1.0);
        if (0.0 <= sqrtValue) {
          operandComponent = srcC[0] * operandComponent;
          sqrtResult = _sqrt(sqrtValue);
          dVar28 = (double)srcC[0];
          operandComponent = (float)((double)operandComponent + sqrtResult);
          fparam_7 = (double)(operandComponent * opVec[0xb]);
          opVec[0] = (float)(dVar28 * (double)opVec[4] - (double)(operandComponent * opVec[8]));
          opVec[1] = (float)(dVar28 * (double)opVec[5] - (double)(operandComponent * opVec[9]));
          opVec[2] = (float)(dVar28 * (double)opVec[6] - (double)(operandComponent * opVec[10]));
          fparam_8 = (double)opVec[2];
          opVec[3] = (float)(dVar28 * (double)opVec[7] - fparam_7);
        }
        else {
          opVec[3] = 0.0;
          opVec[0] = 0.0;
          opVec[1] = 0.0;
          opVec[2] = 0.0;
        }
        break;
      case 0x6c:
        if ((inst[9] == 3) && (inst[0x13] == 1)) {
          truncResult = _trunc((double)opVec[4]);
          opVec[0] = (float)truncResult;
          truncResult = _trunc((double)opVec[5]);
          opVec[1] = (float)truncResult;
          truncResult = _trunc((double)opVec[6]);
          operandComponent = opVec[7];
LAB_97bd200c:
          opVec[2] = (float)truncResult;
          powValue = _trunc((double)operandComponent);
          goto LAB_97bd2010;
        }
        if ((inst[9] != 4) || ((inst[0x13] != 1 && (inst[0x13] != 3))))
        goto switchD_97bd0598_caseD_0;
        opVec[0] = 1.0;
        if (opVec[4] == 0.0) {
          opVec[0] = 0.0;
        }
        opVec[1] = 1.0;
        if (opVec[5] == 0.0) {
          opVec[1] = 0.0;
        }
        opVec[2] = 1.0;
        if (opVec[6] == 0.0) {
          opVec[2] = 0.0;
        }
        opVec[3] = 1.0;
        if (opVec[7] == 0.0) goto LAB_97bd1ce0;
        break;
      case 0x6d:
        opVec[0] = srcC[0];
        opVec[1] = srcC[1];
        opVec[2] = srcC[2];
        opVec[3] = srcC[3];
        if (2.1474836e+09 <= opVec[8]) {
          intComponentI14 = (int)(opVec[8] - 2.1474836e+09);
          local_a8 = (longlong)intComponentI14;
        }
        else {
          intComponentI14 = (int)opVec[8];
          local_a0 = (longlong)intComponentI14;
        }
        if (2.1474836e+09 <= opVec[8]) {
          intComponentI26 = (int)(opVec[8] - 2.1474836e+09);
          local_90 = (longlong)intComponentI26;
        }
        else {
          intComponentI26 = (int)opVec[8];
          local_98 = (longlong)intComponentI26;
        }
        opVec[intComponentI14] = opVec[intComponentI26 + 4];
        break;
      case 0x6f:
        expValue = _exp((double)opVec[4]);
        opVec[0] = (float)expValue;
        expValue = _exp((double)opVec[5]);
        opVec[1] = (float)expValue;
        expValue = _exp((double)opVec[6]);
        opVec[2] = (float)expValue;
        powValue = _exp((double)opVec[7]);
        goto LAB_97bd2010;
      case 0x70:
        logValue = _log((double)opVec[4]);
        opVec[0] = (float)logValue;
        logValue = _log((double)opVec[5]);
        opVec[1] = (float)logValue;
        logValue = _log((double)opVec[6]);
        opVec[2] = (float)logValue;
        powValue = _log((double)opVec[7]);
LAB_97bd2010:
        opVec[3] = (float)powValue;
      }
      if (saturate != '\0') {
        if (0.0 <= opVec[0]) {
          if (opVec[0] <= 1.0) {
            local_70 = opVec[0];
          }
          else {
            opVec[0] = 1.0;
          }
        }
        else {
          opVec[0] = 0.0;
        }
        if (0.0 <= opVec[1]) {
          if (opVec[1] <= 1.0) {
            local_70 = opVec[1];
          }
          else {
            opVec[1] = 1.0;
          }
        }
        else {
          opVec[1] = 0.0;
        }
        if (0.0 <= opVec[2]) {
          if (opVec[2] <= 1.0) {
            local_70 = opVec[2];
          }
          else {
            opVec[2] = 1.0;
          }
        }
        else {
          opVec[2] = 0.0;
        }
        if (0.0 <= opVec[3]) {
          if (opVec[3] <= 1.0) {
            local_70 = opVec[3];
          }
          else {
            opVec[3] = 1.0;
          }
        }
        else {
          opVec[3] = 0.0;
        }
      }
      if (bVar25) {
        sourceElement = loopIndex2;
        if (*(char *)(inst + 8) == '\0') {
          sourceElement = 0;
        }
        in_r5_artifact = (float *)inst[4];
        ((int (*)())_InterpreterWriteDestination)(machine,inst[3],in_r5_artifact,inst[5],inst[6],inst[7],inst[8],inst[9],
                   inst[10],inst[0xb],sourceElement,opVec,(uint)*(byte *)((int)inst + 6));
      }
      loopIndex2 = loopIndex2 + 1;
      if (elementCount <= loopIndex2) {
        return nextInst;
      }
      sourceCount = inst[0xc];
    } while( true );
  }
  if (elementCount < 2) {
    ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
               inst[0x12],inst[0x13],inst[0x14],inst[0x15],0,opVec + 4);
    ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
               inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],0,opVec + 8);
    if (*(char *)((int)inst + 0x21) == '\x01') {
      saturate = *(char *)((int)inst + 5);
      if (saturate == '\x01') {
LAB_97bd0310:
        opVec[0] = 1.0;
        if (opVec[5] == opVec[9]) goto LAB_97bd0328;
      }
      else if (saturate == '\x02') {
        if (opVec[4] == opVec[8]) goto LAB_97bd0310;
      }
      else if (saturate == '\x03') {
        if ((opVec[4] == opVec[8]) &&
           (bVar25 = opVec[5] == opVec[9], opVec[5] = opVec[6],
           opVec[9] = opVec[10], bVar25)) goto LAB_97bd0310;
      }
      else {
        if (saturate != '\x04') goto LAB_97bd0328;
        if (((opVec[4] == opVec[8]) && (opVec[5] == opVec[9])) &&
           (opVec[5] = opVec[7], opVec[9] = opVec[0xb],
           opVec[6] == opVec[10])) goto LAB_97bd0310;
      }
      opVec[0] = 0.0;
      goto LAB_97bd0328;
    }
    opVec[0] = 1.0;
    if (opVec[4] != opVec[8]) {
      opVec[0] = 0.0;
    }
    opVec[1] = 1.0;
    if (opVec[5] != opVec[9]) {
      opVec[1] = 0.0;
    }
    opVec[2] = 1.0;
    if (opVec[6] != opVec[10]) {
      opVec[2] = 0.0;
    }
    opVec[3] = 1.0;
    if (opVec[7] != opVec[0xb]) {
      opVec[3] = 0.0;
    }
  }
  else {
    if (elementCount == 3) {
      componentCursor = opVec;
      loopIndex = 0;
      do {
        sourceElement2 = loopIndex;
        if (*(char *)(inst + 0x12) == '\0') {
          sourceElement2 = 0;
        }
        ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                   inst[0x12],inst[0x13],inst[0x14],inst[0x15],sourceElement2,opVec + 4);
        sourceElement2 = loopIndex;
        if (*(char *)(inst + 0x1b) == '\0') {
          sourceElement2 = 0;
        }
        ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                   inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],sourceElement2,opVec + 8);
        if (((opVec[4] != opVec[8]) || (opVec[5] != opVec[9])) ||
           (operandComponent = 1.0, opVec[6] != opVec[10])) {
          operandComponent = 0.0;
        }
        loopIndex = loopIndex + 1;
        *componentCursor = operandComponent;
        componentCursor = componentCursor + 1;
      } while (loopIndex < 3);
      uStack_ac = 0;
      operandComponent = opVec[2];
      fVar7 = opVec[1];
      if (opVec[0] != 0.0) goto joined_r0x97bd003c;
LAB_97bd01a0:
      uStack_ac = uStack_ac ^ 0x80000000;
      local_b0 = 0x43300000;
      opVec[0] = (float)((double)CONCAT44(0x43300000,uStack_ac) - 4503601774854144.0);
    }
    else if (elementCount < 4) {
      if (elementCount == 2) {
        componentCursor = opVec;
        loopIndex = 0;
        do {
          sourceElement2 = loopIndex;
          if (*(char *)(inst + 0x12) == '\0') {
            sourceElement2 = 0;
          }
          ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                     inst[0x12],inst[0x13],inst[0x14],inst[0x15],sourceElement2,opVec + 4);
          sourceElement2 = loopIndex;
          if (*(char *)(inst + 0x1b) == '\0') {
            sourceElement2 = 0;
          }
          ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                     inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],sourceElement2,opVec + 8);
          if ((opVec[4] != opVec[8]) || (operandComponent = 1.0, opVec[5] != opVec[9])) {
            operandComponent = 0.0;
          }
          loopIndex = loopIndex + 1;
          *componentCursor = operandComponent;
          componentCursor = componentCursor + 1;
          operandComponent = opVec[1];
          fVar7 = opVec[0];
        } while (loopIndex < 2);
joined_r0x97bd003c:
        uStack_ac = 0;
        if ((fVar7 != 0.0) && (uStack_ac = 0, operandComponent != 0.0)) {
          uStack_ac = 1;
        }
        goto LAB_97bd01a0;
      }
    }
    else if (elementCount == 4) {
      componentCursor = opVec;
      loopIndex = 0;
      do {
        sourceElement2 = loopIndex;
        if (*(char *)(inst + 0x12) == '\0') {
          sourceElement2 = 0;
        }
        ((int (*)())_InterpreterLoadSource)(machine,inst[0xd],inst[0xe],inst[0xf],inst[0x10],inst[0x11],
                   inst[0x12],inst[0x13],inst[0x14],inst[0x15],sourceElement2,opVec + 4);
        sourceElement2 = loopIndex;
        if (*(char *)(inst + 0x1b) == '\0') {
          sourceElement2 = 0;
        }
        ((int (*)())_InterpreterLoadSource)(machine,inst[0x16],inst[0x17],inst[0x18],inst[0x19],inst[0x1a],
                   inst[0x1b],inst[0x1c],inst[0x1d],inst[0x1e],sourceElement2,opVec + 8);
        if (((opVec[4] != opVec[8]) || (opVec[5] != opVec[9])) ||
           ((opVec[6] != opVec[10] || (operandComponent = 1.0, opVec[7] != opVec[0xb])))) {
          operandComponent = 0.0;
        }
        loopIndex = loopIndex + 1;
        *componentCursor = operandComponent;
        componentCursor = componentCursor + 1;
      } while (loopIndex < 4);
      uStack_ac = 0;
      if ((opVec[0] == 0.0) || (operandComponent = opVec[3], fVar7 = opVec[2], opVec[1] == 0.0)
         ) goto LAB_97bd01a0;
      goto joined_r0x97bd003c;
    }
LAB_97bd0328:
    opVec[3] = opVec[0];
    opVec[1] = opVec[0];
    opVec[2] = opVec[0];
  }
  operandScratch = opVec;
  if (opcode == 0x36) {
    opVec[0] = 1.0 - opVec[0];
    opVec[1] = 1.0 - opVec[1];
    opVec[3] = 1.0 - opVec[3];
    opVec[2] = 1.0 - opVec[2];
  }
  destValueType = inst[9];
  destUpdatesCC = (uint)*(byte *)((int)inst + 6);
  destWriteMask = inst[10];
  destConditionSwizzleZW = inst[0xb];
  destOffsetTable = inst[3];
  destBankIndex = inst[4];
  destSwizzle = inst[5];
  destIndexInfo = inst[6];
  destStorageFlags = inst[7];
  destWord5 = inst[8];
  destElement = 0;
LAB_97bd043c:
  ((int (*)())_InterpreterWriteDestination)(machine,destOffsetTable,destBankIndex,destSwizzle,destIndexInfo,destStorageFlags,destWord5,destValueType,destWriteMask,destConditionSwizzleZW,destElement,operandScratch,
             destUpdatesCC);
  return nextInst;
}

/* _InterpreterWriteFinalFragmentToBuffer @ 0x97bd3068 (376 bytes) */
int _InterpreterWriteFinalFragmentToBuffer(machine, operandWord1, operandWord2, operandWord3, operandWord4, operandWord5, viewportScaleBias)
  int *machine;
  undefined4 operandWord1;
  undefined4 operandWord2;
  undefined4 operandWord3;
  undefined4 operandWord4;
  undefined4 operandWord5;
  undefined4 viewportScaleBias;
{
  int programInfo;
  int emulator;
  int *fragmentColor;
  undefined1 destinationColor [16];
  int resultR;
  int resultG;
  int resultB;
  int resultA;
  
  fragmentColor = machine + 0x292;
  emulator = *machine;
  programInfo = *(int *)(emulator + 0xd80);
  if ((*(uint *)(programInfo + 0x3c) & 1) != 0) {
    programInfo = _InterpreterRasterOpMachine_AlphaTest(machine + 0x289,fragmentColor);
    if (programInfo != 0) {
      return;
    }
    programInfo = *(int *)(emulator + 0xd80);
  }
  if ((*(uint *)(programInfo + 0x3c) & 6) != 0) {
    programInfo = _InterpreterRasterOpMachine_DepthAndStencilTest(machine + 0x289);
    if (programInfo != 0) {
      return;
    }
    programInfo = *(int *)(emulator + 0xd80);
  }
  if ((*(uint *)(programInfo + 0x3c) & 0x68) != 0) {
    ((int (*)())_InterpreterUnpackPixel)(machine,destinationColor,*(undefined4 *)(emulator + 0xd88));
    programInfo = *(int *)(emulator + 0xd80);
  }
  if ((*(uint *)(programInfo + 0x3c) & 8) != 0) {
    _InterpreterRasterOpMachine_Blending(machine + 0x289,fragmentColor,destinationColor,&resultR);
    machine[0x292] = resultR;
    machine[0x293] = resultG;
    machine[0x294] = resultB;
    machine[0x295] = resultA;
    programInfo = *(int *)(emulator + 0xd80);
  }
  if ((*(uint *)(programInfo + 0x3c) & 0x20) != 0) {
    _InterpreterRasterOpMachine_LogicOp(machine + 0x289,fragmentColor,destinationColor,&resultR);
    machine[0x292] = resultR;
    machine[0x293] = resultG;
    machine[0x294] = resultB;
    machine[0x295] = resultA;
    programInfo = *(int *)(emulator + 0xd80);
  }
  if ((*(uint *)(programInfo + 0x3c) & 0x40) == 0) {
    resultA = machine[0x295];
    resultR = machine[0x292];
    resultG = machine[0x293];
    resultB = machine[0x294];
  }
  else {
    _InterpreterRasterOpMachine_BufferMask(machine + 0x289,fragmentColor,destinationColor,&resultR);
  }
  ((int (*)())_InterpreterPackPixel)(machine,&resultR,*(undefined4 *)(emulator + 0xd88));
  return;
}

/* _InterpreterRun @ 0x97bd31e0 (1020 bytes) */
void _InterpreterRun(int emulator,int elementCount,double fparam_1,double fparam_2,double fparam_3,double fparam_4,double fparam_5,double fparam_6,double fparam_7,double fparam_8,double fparam_9,double fparam_10,double fparam_11,double fparam_12,double fparam_13)
{
  bool wSafeToDivide;
  float fVar2;
  float clipX;
  float clipY;
  float clipZ;
  float viewportZBias;
  float viewportZScale;
  float viewportXScale;
  float viewportXBias;
  float viewportYBias;
  float viewportYScale;
  float negW;
  double one;
  float zero;
  int iVar15;
  float *vertexOutput;
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
  uint clipOrMask;
  uint clipAndMask;
  int machine;
  double dVar24;
  double extraout_f1;
  double extraout_f1_00;
  double xScale;
  double xBias;
  double invWScale;
  double invWBias;
  double in_stack_ffffff38;
  double in_stack_ffffff40;
  double in_stack_ffffff48;
  double in_stack_ffffff50;
  double in_stack_ffffff58;
  
  one = DOUBLE_97c30a60;
  iVar19 = *(int *)(*(int *)(emulator + 0xd80) + 0x38);
  machine = *(int *)(emulator + 0xdf0);
  iVar15 = *(int *)(emulator + 0xd9c);
  clipAndMask = 0xff;
  clipOrMask = 0;
  if ((iVar19 == 0x8804) || (iVar19 == 0x8b30)) {
    invWBias = (double)*(float *)(*(int *)(emulator + 0xda0) + 0xc);
    xBias = (double)*(float *)(*(int *)(emulator + 0xda0) + 8);
    invWScale = (double)*(float *)(*(int *)(emulator + 0xda4) + 0xc);
    xScale = (double)*(float *)(*(int *)(emulator + 0xda4) + 8);
    viewportZBias = TAllocation__guardBlockSize;
    viewportZScale = TAllocation__guardBlockSize;
    viewportXScale = TAllocation__guardBlockSize;
    viewportXBias = TAllocation__guardBlockSize;
    viewportYBias = TAllocation__guardBlockSize;
    viewportYScale = TAllocation__guardBlockSize;
  }
  else {
    invWScale = (double)TAllocation__guardBlockSize;
    xScale = invWScale;
    xBias = invWScale;
    invWBias = invWScale;
    viewportZBias = *(float *)(iVar15 + 0x1b88);
    viewportZScale = *(float *)(iVar15 + 0x1b78);
    viewportXScale = *(float *)(iVar15 + 0x1b70);
    viewportXBias = *(float *)(iVar15 + 0x1b80);
    viewportYBias = *(float *)(iVar15 + 0x1b84);
    viewportYScale = *(float *)(iVar15 + 0x1b74);
  }
  iVar15 = *(int *)(*(int *)(emulator + 0xd80) + 0x38);
  if ((iVar15 == 0x8804) || (iVar15 == 0x8b30)) {
    *(undefined4 *)(machine + 0xa30) = 0;
    *(float *)(machine + 0xa38) = (float)xBias;
    *(float *)(machine + 0xa3c) = (float)(one / invWBias);
  }
  iVar15 = machine + 0xa5c;
  *(undefined1 *)(machine + 0xa47) = 0;
  *(undefined4 *)(machine + 0xa68) = 0;
  *(int *)(machine + 0xa6c) = iVar15;
  *(undefined1 *)(machine + 0xa44) = 0;
  *(undefined1 *)(machine + 0xa45) = 0;
  *(undefined1 *)(machine + 0xa46) = 0;
  *(undefined4 *)(machine + 0xa5c) = 0;
  *(undefined4 *)(machine + 0xa60) = 0;
  *(undefined4 *)(machine + 0xa64) = 0;
  zero = TAllocation__guardBlockSize;
  one = DOUBLE_97c30a60;
  iVar19 = elementCount;
  do {
    if (iVar19 == 0) {
      iVar15 = *(int *)(*(int *)(emulator + 0xd80) + 0x38);
      if ((iVar15 == 0x8804) || (iVar15 == 0x8b30)) {
        clipOrMask = 0;
      }
      else {
        clipOrMask = clipAndMask << 8 | clipOrMask;
      }
      FUN_97c1a28c(clipOrMask);
      return;
    }
    iVar19 = iVar19 + -1;
    *(undefined4 *)(machine + 0xa58) = 0;
    iVar20 = *(int *)(emulator + 0xd80);
    if (((*(uint *)(iVar20 + 0x3c) & 6) == 4) && ((*(uint *)(iVar20 + 0x34) & 0xa000) == 0)) {
      uVar17 = _InterpreterRasterOpMachine_DepthTest(machine + 0xa24);
      *(uint *)(machine + 0xa58) = *(uint *)(machine + 0xa58) | uVar17;
      iVar20 = *(int *)(emulator + 0xd80);
      elementCount = extraout_r4;
      fparam_1 = extraout_f1;
    }
    iVar18 = *(int *)(iVar20 + 0x120);
    if ((iVar18 != 0) && (*(int *)(machine + 0xa58) == 0)) {
      do {
        iVar18 = ((int * (*)())_InterpreterEmulateOp)(machine,iVar18,fparam_1,fparam_2,fparam_3,fparam_4,fparam_5,fparam_6,
                            fparam_7,fparam_8,in_stack_ffffff38,in_stack_ffffff40,in_stack_ffffff48,
                            in_stack_ffffff50,in_stack_ffffff58);
        fparam_1 = extraout_f1_00;
        if (iVar18 == 0) break;
      } while (*(int *)(machine + 0xa58) == 0);
      iVar20 = *(int *)(emulator + 0xd80);
      elementCount = extraout_r4_00;
    }
    if ((*(int *)(iVar20 + 0x38) == 0x8804) || (*(int *)(iVar20 + 0x38) == 0x8b30)) {
      if (*(int *)(machine + 0xa58) == 0) {
        fparam_1 = (double)((int (*)())_InterpreterWriteFinalFragmentToBuffer)(machine,elementCount,in_r5,in_r6,in_r7,in_r8,iVar15);
        iVar20 = *(int *)(emulator + 0xd80);
        elementCount = extraout_r4_01;
      }
    }
    else {
      vertexOutput = *(float **)(emulator + 0xd88);
      uVar17 = 0;
      fVar2 = vertexOutput[7];
      clipX = vertexOutput[4];
      negW = -fVar2;
      clipY = vertexOutput[5];
      clipZ = vertexOutput[6];
      if (clipX < negW) {
        uVar17 = 0x10;
      }
      if (fVar2 <= clipX) {
        uVar17 = uVar17 | 0x20;
      }
      if (clipY < negW) {
        uVar17 = uVar17 | 4;
      }
      if (fVar2 <= clipY) {
        uVar17 = uVar17 | 8;
      }
      if (clipZ < negW) {
        uVar17 = uVar17 | 1;
      }
      if (fVar2 < clipZ) {
        uVar17 = uVar17 | 2;
      }
      vertexOutput[0x1f] = GH_U2F((unsigned int)((uVar17 | 0x1000000)));
      if (uVar17 == 0) {
        if (fVar2 < zero) {
          wSafeToDivide = fVar2 <= FLOAT_97c3acf4;
        }
        else {
          wSafeToDivide = FLOAT_97c3acf0 <= fVar2;
        }
        if (wSafeToDivide) {
          negW = FLOAT_97c3acd8 / fVar2;
        }
        else {
          negW = FLOAT_97c3acfc;
          if (zero <= fVar2) {
            negW = FLOAT_97c3acf8;
          }
        }
        vertexOutput[3] = negW;
        *vertexOutput = clipX * negW * viewportXScale + viewportXBias;
        vertexOutput[1] = clipY * negW * viewportYScale + viewportYBias;
        vertexOutput[2] = clipZ * negW * viewportZScale + viewportZBias;
      }
      iVar20 = *(int *)(emulator + 0xd80);
      clipAndMask = clipAndMask & uVar17;
      clipOrMask = clipOrMask | uVar17;
    }
    *(int *)(emulator + 0xd8c) = *(int *)(emulator + 0xd8c) + *(int *)(iVar20 + 0xbc);
    *(int *)(emulator + 0xd88) = *(int *)(emulator + 0xd88) + *(int *)(iVar20 + 0xb8);
    iVar15 = *(int *)(emulator + 0xda8) + *(int *)(iVar20 + 0xd8);
    *(int *)(emulator + 0xda8) = iVar15;
    *(int *)(emulator + 0xdac) = *(int *)(emulator + 0xdac) + *(int *)(iVar20 + 0xdc);
    if ((*(int *)(iVar20 + 0x38) == 0x8804) || (*(int *)(iVar20 + 0x38) == 0x8b30)) {
      fVar2 = (float)((double)*(float *)(machine + 0xa30) + one);
      dVar24 = (double)fVar2;
      *(float *)(machine + 0xa30) = fVar2;
      *(float *)(machine + 0xa38) = (float)(xScale * dVar24 + xBias);
      *(float *)(machine + 0xa3c) = (float)(one / (double)(float)(invWScale * dVar24 + invWBias));
    }
  } while( true );
}

/* _InterpreterTextureSamplerCreate @ 0x97bd35dc (12 bytes) */
int _InterpreterTextureSamplerCreate()
{
  undefined4 allocation;
  
  allocation = _calloc(0x2c,1);
  return allocation;
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

