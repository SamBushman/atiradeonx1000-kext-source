#include "decls.h"

/* TPPStreamCompiler___TPPStreamCompiler_97bc97dc @ 0x97bc97dc (8 bytes) */
int TPPStreamCompiler___TPPStreamCompiler_97bc97dc(this)
  unsigned char * this;
{
  ~TPPStreamCompiler(this);
  return;
}

/* TPPStreamCompiler___TPPStreamCompiler_97bc97e4 @ 0x97bc97e4 (8 bytes) */
int TPPStreamCompiler___TPPStreamCompiler_97bc97e4(this)
  unsigned char * this;
{
  ~TPPStreamCompiler(this);
  return;
}

/* TPPStreamCompiler___TPPStreamCompiler_97bc97ec @ 0x97bc97ec (536 bytes) */
int TPPStreamCompiler___TPPStreamCompiler_97bc97ec(this)
  unsigned char * this;
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint in_r4;
  unsigned char * this_00;
  unsigned char * this_01;
  unsigned char * this_02;
  unsigned char * this_03;
  char in_RESERVE;
  byte in_cr0;
  
  *(int *)this = DAT_a7b7bd98 + 8;
  ConstantAllocationList__clear((unsigned char *)(this + 0x44));
  while( true ) {
    iVar4 = size((unsigned char *)(this + 0x4c));
    if (iVar4 == 0) break;
    fetch((unsigned char *)(this + 0x4c));
  }
  while (iVar4 = ParseFunctionStack__empty((unsigned char *)(this + 0x58)), iVar4 == 0) {
    ParseFunctionStack__pop((unsigned char *)(this + 0x58));
  }
  this_00 = *(unsigned char **)(this + 0x6c);
  if (this_00 != (unsigned char *)0x0) {
    ((int (*)())FunctionTable___FunctionTable)(this_00);
    operator_delete(this_00);
  }
  this_01 = *(unsigned char **)(this + 0x68);
  if (this_01 != (unsigned char *)0x0) {
    ParseSymbolTable___ParseSymbolTable(this_01);
    operator_delete(this_01);
  }
  if (*(int *)(this + 0x70) != 0) {
    _PPStreamFree();
  }
  if (*(void **)(this + 0x78) != (void *)0x0) {
    _free(*(void **)(this + 0x78));
  }
  if (*(void **)(this + 0x7c) != (void *)0x0) {
    _free(*(void **)(this + 0x7c));
  }
  if (*(void **)(this + 0x80) != (void *)0x0) {
    _free(*(void **)(this + 0x80));
  }
  if (*(void **)(this + 0x84) != (void *)0x0) {
    _free(*(void **)(this + 0x84));
  }
  this_02 = *(unsigned char **)(this + 0x60);
  if (this_02 != (unsigned char *)0x0) {
    TemporaryAllocator___TemporaryAllocator(this_02);
    operator_delete(this_02);
  }
  *(undefined4 *)PTR_temporaryAllocator_a7b7c0fc = 0;
  this_03 = *(unsigned char **)(this + 100);
  if (this_03 != (unsigned char *)0x0) {
    AddressTempAllocator___AddressTempAllocator(this_03);
    operator_delete(this_03);
  }
  *(undefined4 *)PTR_addressTempAllocator_a7b7c0f8 = 0;
  if (*(void **)(this + 0x74) != (void *)0x0) {
    _free(*(void **)(this + 0x74));
  }
  iVar4 = *(int *)(this + 0xb8);
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
  iVar4 = *(int *)(this + 0xb0);
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
  ConstantAllocationList___ConstantAllocationList((unsigned char *)(this + 0x44));
  *(undefined ***)this = &PTR__TCompiler_a7b7d850;
  TPoolAllocator___TPoolAllocator((unsigned char *)(this + 0x10));
  *(undefined ***)this = &PTR__TShHandleBase_a7b7d898;
  if ((in_r4 & 1) != 0) {
    operator_delete(this);
  }
  return;
}

/* TPPStreamCompiler__error @ 0x97bc9a04 (304 bytes) */
int TPPStreamCompiler__error(param_1, param_2, param_3)
  int param_1;
  char *param_2;
  char *param_3;
{
  char *pcVar1;
  char *pcVar2;
  int in_r3;
  size_t sVar3;
  char *pcVar4;
  char *in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  size_t sVar5;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  char acStack_120 [264];
  
  sVar5 = 0;
  uStack00000028 = in_r7;
  uStack0000002c = in_r8;
  uStack00000030 = in_r9;
  uStack00000034 = in_r10;
  _vsprintf(acStack_120,in_r6,&STACKARG(0x28));
  if (param_3 != (char *)0x0) {
    sVar5 = _strlen(param_3);
  }
  sVar3 = _strlen(acStack_120);
  pcVar4 = _malloc(sVar3 + sVar5 + 0x28);
  pcVar1 = DAT_a7b7bd20;
  pcVar2 = DAT_a7b7bd24;
  if (param_2 != (char *)0x0) {
    pcVar1 = DAT_a7b7bd18;
    pcVar2 = DAT_a7b7bd1c;
  }
  if (param_3 == (char *)0x0) {
    _sprintf(pcVar4,pcVar2,*(undefined4 *)(in_r3 + 0x90),acStack_120);
  }
  else {
    _sprintf(pcVar4,pcVar1,*(undefined4 *)(in_r3 + 0x90),param_3,acStack_120);
  }
  TInfoSinkBase__append((char *)(in_r3 + 0xb0));
  TInfoSinkBase__append((char *)(in_r3 + 0xb0));
  _free(pcVar4);
  *(undefined4 *)(in_r3 + 0xa0) = 1;
  return;
}

/* TPPStreamCompiler__warning @ 0x97bc9b34 (296 bytes) */
int TPPStreamCompiler__warning(param_1, param_2, param_3)
  int param_1;
  char *param_2;
  char *param_3;
{
  char *pcVar1;
  char *pcVar2;
  int in_r3;
  size_t sVar3;
  char *pcVar4;
  char *in_r6;
  undefined4 in_r7;
  undefined4 in_r8;
  undefined4 in_r9;
  undefined4 in_r10;
  size_t sVar5;
  undefined4 uStack00000028;
  undefined4 uStack0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  char acStack_120 [268];
  
  uStack00000028 = in_r7;
  uStack0000002c = in_r8;
  uStack00000030 = in_r9;
  uStack00000034 = in_r10;
  _vsprintf(acStack_120,in_r6,&STACKARG(0x28));
  sVar5 = 0;
  if (param_3 != (char *)0x0) {
    sVar5 = _strlen(param_3);
  }
  sVar3 = _strlen(acStack_120);
  pcVar4 = _malloc(sVar3 + sVar5 + 0x28);
  pcVar1 = DAT_a7b7bd34;
  pcVar2 = DAT_a7b7bd38;
  if (param_2 != (char *)0x0) {
    pcVar1 = DAT_a7b7bd2c;
    pcVar2 = DAT_a7b7bd30;
  }
  if (param_3 == (char *)0x0) {
    _sprintf(pcVar4,pcVar2,*(undefined4 *)(in_r3 + 0x90),acStack_120);
  }
  else {
    _sprintf(pcVar4,pcVar1,*(undefined4 *)(in_r3 + 0x90),param_3,acStack_120);
  }
  TInfoSinkBase__append((char *)(in_r3 + 0xb0));
  TInfoSinkBase__append((char *)(in_r3 + 0xb0));
  _free(pcVar4);
  return;
}

/* TPPStreamCompiler__getSymbolTableString @ 0x97bc9c5c (196 bytes) */
int TPPStreamCompiler__getSymbolTableString(this, param_1)
  unsigned char * this;
  int param_1;
{
  char *pcVar1;
  size_t sVar2;
  char *pcVar3;
  char *pcVar4;
  
  if (*(int *)(this + 0x68) == 0) {
    return (char *)0x0;
  }
  pcVar1 = (char *)ParseSymbolTable__GetString(*(int *)(this + 0x68));
  sVar2 = _strlen(pcVar1);
  pcVar3 = _malloc(sVar2 + 0x17);
  *pcVar3 = '\0';
  pcVar4 = DAT_a7b7bd64;
  if (param_1 != 1) {
    if (param_1 < 2) {
      pcVar4 = DAT_a7b7bd60;
      if (param_1 != 0) goto LAB_97bc9d00;
    }
    else {
      pcVar4 = DAT_a7b7bd68;
      if (param_1 != 2) goto LAB_97bc9d00;
    }
  }
  _sprintf(pcVar3,pcVar4,pcVar1);
LAB_97bc9d00:
  _free(pcVar1);
  return pcVar3;
}

/* TPPStreamCompiler__dumpSymbolTableInfo @ 0x97bc9d20 (220 bytes) */
int TPPStreamCompiler__dumpSymbolTableInfo(this, param_1)
  unsigned char * this;
  int param_1;
{
  void *pvVar1;
  
  if (param_1 != 1) {
    if (param_1 < 2) {
      if (param_1 != 0) goto LAB_97bc9d98;
    }
    else if (param_1 != 2) goto LAB_97bc9d98;
  }
  TInfoSinkBase__append((char *)(this + 0xb0));
LAB_97bc9d98:
  pvVar1 = (void *)ParseSymbolTable__GetString(*(int *)(this + 0x68));
  if (pvVar1 == (void *)0x0) {
    return;
  }
  TInfoSinkBase__append((char *)(this + 0xb0));
  TInfoSinkBase__append((char *)(this + 0xb0));
  _free(pvVar1);
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
  unsigned char * pPVar4;
  unsigned char * pFVar5;
  
  *(undefined4 *)(this + 0xc) = 0;
  if (*(void **)(this + 0x78) != (void *)0x0) {
    _free(*(void **)(this + 0x78));
  }
  *(undefined4 *)(this + 0x78) = 0;
  if (*(void **)(this + 0x7c) != (void *)0x0) {
    _free(*(void **)(this + 0x7c));
  }
  *(undefined4 *)(this + 0x7c) = 0;
  if (*(void **)(this + 0x80) != (void *)0x0) {
    _free(*(void **)(this + 0x80));
  }
  *(undefined4 *)(this + 0x80) = 0;
  if (*(void **)(this + 0x84) != (void *)0x0) {
    _free(*(void **)(this + 0x84));
  }
  pPVar4 = *(unsigned char **)(this + 0x68);
  *(undefined4 *)(this + 0x84) = 0;
  if (pPVar4 != (unsigned char *)0x0) {
    ParseSymbolTable___ParseSymbolTable(pPVar4);
    operator_delete(pPVar4);
  }
  pPVar4 = operator_new(0x54);
  ParseSymbolTable__ParseSymbolTable(pPVar4,0x80);
  *(unsigned char **)(this + 0x68) = pPVar4;
  *(undefined4 *)(pPVar4 + 0x3c) = *(undefined4 *)(this + 8);
  pFVar5 = *(unsigned char **)(this + 0x6c);
  if (pFVar5 != (unsigned char *)0x0) {
    ((int (*)())FunctionTable___FunctionTable)(pFVar5);
    operator_delete(pFVar5);
  }
  pFVar5 = operator_new(8);
  ((int (*)())FunctionTable__FunctionTable)(pFVar5);
  *(unsigned char **)(this + 0x6c) = pFVar5;
  if (*(int *)(this + 0x70) != 0) {
    _PPStreamFree();
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
int TPPStreamCompiler__compile(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
{
  uint uVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  uint uVar5;
  int local_20 [5];
  
  iVar2 = TPPStreamCompiler__parseIntermediateTree(this,param_1);
  *(int *)(this + 0xc) = iVar2;
  if (iVar2 != 0) {
    iVar3 = *(int *)(this + 0x70);
    uVar5 = 0;
    iVar2 = **(int **)(iVar3 + 0x20);
    if (iVar2 != 0) {
      do {
        uVar1 = *(uint *)(iVar2 + 0xc);
        *(uint *)(iVar2 + 0xc) = uVar5 << 0x1a | uVar1 & 0xe3ffffff;
        uVar5 = uVar1 >> 0x1d;
        iVar2 = *(int *)(iVar2 + 8);
      } while (iVar2 != 0);
      iVar3 = *(int *)(this + 0x70);
    }
    _PPStreamResolveBranches(iVar3);
    if (*(void **)(this + 0x74) != (void *)0x0) {
      _free(*(void **)(this + 0x74));
    }
    *(undefined4 *)(this + 0x74) = 0;
    _PPStreamGetStream(*(undefined4 *)(this + 0x70),0,local_20);
    if (local_20[0] != 0) {
      pvVar4 = _malloc(local_20[0] * 8 + 0xfU & 0xfffffff0);
      *(void **)(this + 0x74) = pvVar4;
      _PPStreamGetStream(*(undefined4 *)(this + 0x70),pvVar4,local_20);
    }
  }
  iVar2 = *(int *)(this + 0xc);
  if ((iVar2 != 0) && ((*(uint *)(this + 0xc0) & 0x10) != 0)) {
    ((int (*)())TPPStreamCompiler__dumpSymbolTableInfo)(this,2);
    iVar2 = *(int *)(this + 0xc);
  }
  if ((iVar2 != 0) && ((*(uint *)(this + 0xc0) & 2) != 0)) {
    TInfoSinkBase__append((char *)(this + 0xb0));
    (**(code **)(*(int *)this + 0x28))(this);
    TInfoSinkBase__append((char *)(this + 0xb0));
    iVar2 = *(int *)(this + 0xc);
  }
  return iVar2;
}

/* TPPStreamCompiler__getStatsString @ 0x97bca090 (108 bytes) */
int TPPStreamCompiler__getStatsString(this)
  unsigned char * this;
{
  char *pcVar1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  
  pcVar1 = DAT_a7b7bd84;
  iVar2 = *(int *)(this + 0x78);
  if (iVar2 == 0) {
    sVar3 = _strlen(DAT_a7b7bd84);
    pcVar4 = _malloc(sVar3 * 4 + 4);
    *(char **)(this + 0x78) = pcVar4;
    _strcpy(pcVar4,pcVar1);
    iVar2 = *(int *)(this + 0x78);
  }
  return iVar2;
}

/* TPPStreamCompiler__getPPStreamString @ 0x97bca0fc (144 bytes) */
int TPPStreamCompiler__getPPStreamString(this)
  unsigned char * this;
{
  char *pcVar1;
  int iVar2;
  size_t sVar3;
  char *pcVar4;
  
  pcVar1 = DAT_a7b7bd88;
  iVar2 = *(int *)(this + 0x7c);
  if (iVar2 == 0) {
    if ((*(int *)(this + 0xc) == 0) || (*(int *)(this + 0x74) == 0)) {
      sVar3 = _strlen(DAT_a7b7bd88);
      pcVar4 = _malloc(sVar3 * 4 + 4);
      *(char **)(this + 0x7c) = pcVar4;
      _strcpy(pcVar4,pcVar1);
      iVar2 = *(int *)(this + 0x7c);
    }
    else {
      iVar2 = _glpPPDisassemble();
      *(int *)(this + 0x7c) = iVar2;
    }
  }
  return iVar2;
}

/* TPPStreamCompiler__getShaderToProgramString @ 0x97bca18c (148 bytes) */
int TPPStreamCompiler__getShaderToProgramString(this)
  unsigned char * this;
{
  int iVar1;
  size_t sVar2;
  char *pcVar3;
  
  iVar1 = *(int *)(this + 0x80);
  if (iVar1 == 0) {
    if ((*(int *)(this + 0xc) == 0) || (*(int *)(this + 0x74) == 0)) {
      sVar2 = _strlen("No Shader Program generated.");
      pcVar3 = _malloc(sVar2 * 4 + 4);
      *(char **)(this + 0x80) = pcVar3;
      _strcpy(pcVar3,"No Shader Program generated.");
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
  unsigned char * pTVar1;
  
  pTVar1 = operator_new(200);
  TPPStreamCompiler__TPPStreamCompiler(pTVar1,param_1,param_2);
  return pTVar1;
}

/* DeleteCompiler @ 0x97bca2b0 (24 bytes) */
int DeleteCompiler(param_1)
  unsigned char * param_1;
{
  if (param_1 == (unsigned char *)0x0) {
    return;
  }
                    
                    
  (**(code **)(*(int *)param_1 + 4))();
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
        uVar6 = ParseSymbol__GetDirectIndex((uint)param_1);
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
                uVar6 = ParseSymbol__GetDirectIndex((uint)param_1);
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
  uVar9 = ParseSymbol__GetDirectIndex((uint)param_1);
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
  void *pvVar8;
  
  pvVar8 = *(void **)(param_1 + 0x14);
  if (((pvVar8 == (void *)0x0) || (iVar4 = _memcmp(pvVar8,"gl_",3), iVar4 != 0)) ||
     (*(char *)((int)pvVar8 + 3) == '_')) {
    uVar6 = (**(code **)(**(int **)(param_1 + 0xc) + 0x24))();
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
      iVar4 = (**(code **)(**(int **)(param_1 + 0xc) + 0x20))();
      *(uint *)(pbVar5 + 0x10) =
           (uint)(iVar4 - 5U < 8) << 0x1f | *(uint *)(pbVar5 + 0x10) & 0x7fffffff;
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
    uVar7 = GetPPStreamTypeForGLType(*(ushort *)(param_1 + 0x2c));
    *(uint *)(pbVar5 + 0xc) = (uVar7 & 7) << 0x1a | *(uint *)(pbVar5 + 0xc) & 0xe3ffffff;
    iVar4 = GetScalerWidthForType(*(ushort *)(param_1 + 0x2c));
    uVar7 = (iVar4 + -1) * 0x1000000 & 0x3000000U | *(uint *)(pbVar5 + 0xc) & 0x1cffffff;
LAB_97bcc8c0:
    *(uint *)(pbVar5 + 0xc) = uVar7;
  }
  else if (bVar2 < 3) {
    if (bVar2 == 0) {
      uVar7 = GetPPStreamTypeForGLType(*(ushort *)(param_1 + 0x2c));
      *(uint *)(pbVar5 + 0xc) = (uVar7 & 7) << 0x1a | *(uint *)(pbVar5 + 0xc) & 0xe3ffffff;
      iVar4 = GetScalerWidthForType(*(ushort *)(param_1 + 0x2c));
      uVar7 = (iVar4 + -1) * 0x1000000 & 0x3000000U | *(uint *)(pbVar5 + 0xc) & 0x1cffffff;
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

/* FunctionTable__FunctionTable @ 0x97bcc93c (4 bytes) */
int FunctionTable__FunctionTable(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* FunctionTable__FunctionTable_97bcc940 @ 0x97bcc940 (4 bytes) */
int FunctionTable__FunctionTable_97bcc940(this)
  unsigned char * this;
{
  FunctionTable(this);
  return;
}

/* FunctionTable__FunctionTable_97bcc944 @ 0x97bcc944 (16 bytes) */
int FunctionTable__FunctionTable_97bcc944(this)
  unsigned char * this;
{
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* FunctionTable___FunctionTable @ 0x97bcc954 (8 bytes) */
int FunctionTable___FunctionTable(this)
  unsigned char * this;
{
  ~FunctionTable(this);
  return;
}

/* FunctionTable___FunctionTable_97bcc95c @ 0x97bcc95c (8 bytes) */
int FunctionTable___FunctionTable_97bcc95c(this)
  unsigned char * this;
{
  ~FunctionTable(this);
  return;
}

/* FunctionTable___FunctionTable_97bcc964 @ 0x97bcc964 (4 bytes) */
int FunctionTable___FunctionTable_97bcc964(this)
  unsigned char * this;
{
  clear(this);
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
      _free((void *)*puVar1);
    } while (iVar2 < *(int *)(this + 4));
  }
  if (*(void **)this != (void *)0x0) {
    _free(*(void **)this);
  }
  *(undefined4 *)(this + 4) = 0;
  *(undefined4 *)this = 0;
  return;
}

/* FunctionTable__addFunction @ 0x97bcc9e0 (284 bytes) */
int FunctionTable__addFunction(this, param_1)
  unsigned char * this;
  char *param_1;
{
  void *pvVar1;
  void *pvVar2;
  size_t sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  
  uVar9 = *(uint *)(this + 4);
  if ((uVar9 & 0xf) == 0) {
    pvVar1 = _malloc(uVar9 * 0x18 + 0x180);
    _memset(pvVar1,0,*(int *)(this + 4) * 0x18 + 0x180);
    uVar9 = *(uint *)(this + 4);
    iVar4 = 0;
    if ((int)uVar9 < 1) {
      pvVar2 = *(void **)this;
    }
    else {
      pvVar2 = *(void **)this;
      iVar5 = 0;
      do {
        uVar7 = *(undefined4 *)((int)pvVar2 + iVar5 + 4);
        iVar4 = iVar4 + 1;
        uVar8 = *(undefined4 *)((int)pvVar2 + iVar5 + 8);
        uVar6 = *(undefined4 *)((int)pvVar2 + iVar5 + 0xc);
        *(undefined4 *)(iVar5 + (int)pvVar1) = *(undefined4 *)(iVar5 + (int)pvVar2);
        *(undefined4 *)((int)pvVar1 + iVar5 + 4) = uVar7;
        *(undefined4 *)((int)pvVar1 + iVar5 + 8) = uVar8;
        *(undefined4 *)((int)pvVar1 + iVar5 + 0xc) = uVar6;
        uVar6 = *(undefined4 *)((int)pvVar2 + iVar5 + 0x10);
        *(undefined4 *)((int)pvVar1 + iVar5 + 0x14) = *(undefined4 *)((int)pvVar2 + iVar5 + 0x14);
        *(undefined4 *)((int)pvVar1 + iVar5 + 0x10) = uVar6;
        iVar5 = iVar5 + 0x18;
      } while (iVar4 < (int)uVar9);
    }
    if (pvVar2 != (void *)0x0) {
      _free(pvVar2);
      uVar9 = *(uint *)(this + 4);
    }
    *(void **)this = pvVar1;
  }
  iVar4 = *(int *)this;
  sVar3 = _strlen(param_1);
  pvVar1 = _malloc(sVar3 + 1);
  *(void **)(uVar9 * 0x18 + iVar4) = pvVar1;
  _strcpy(*(char **)(*(int *)(this + 4) * 0x18 + *(int *)this),param_1);
  *(int *)(this + 4) = *(int *)(this + 4) + 1;
  return;
}

/* FunctionTable__removeFunction @ 0x97bccafc (168 bytes) */
int FunctionTable__removeFunction(this, param_1)
  unsigned char * this;
  int param_1;
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = param_1 * 0x18;
  _free(*(void **)(iVar5 + *(int *)this));
  iVar1 = *(int *)(this + 4);
  if (param_1 < iVar1) {
    do {
      param_1 = param_1 + 1;
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
    } while (param_1 < iVar1);
  }
  *(int *)(this + 4) = iVar1 + -1;
  return;
}

/* FunctionTable__setReturnVal @ 0x97bccba4 (20 bytes) */
int FunctionTable__setReturnVal(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  int param_2;
{
  undefined3 in_register_00000014;
  
  *(uint *)(param_1 * 0x18 + *(int *)this + 4) = CONCAT31(in_register_00000014,param_2);
  return;
}

/* FunctionTable__setEmpty @ 0x97bccbb8 (20 bytes) */
int FunctionTable__setEmpty(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  int param_2;
{
  undefined3 in_register_00000014;
  
  *(uint *)(param_1 * 0x18 + *(int *)this + 8) = CONCAT31(in_register_00000014,param_2);
  return;
}

/* FunctionTable__setNumParams @ 0x97bccbcc (20 bytes) */
int FunctionTable__setNumParams(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  int param_2;
{
  *(int *)(param_1 * 0x18 + *(int *)this + 0xc) = param_2;
  return;
}

/* FunctionTable__setFirstOp @ 0x97bccbe0 (20 bytes) */
int FunctionTable__setFirstOp(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  uint param_2;
{
  *(uint *)(param_1 * 0x18 + *(int *)this + 0x10) = param_2;
  return;
}

/* FunctionTable__setLastOp @ 0x97bccbf4 (20 bytes) */
int FunctionTable__setLastOp(this, param_1, param_2)
  unsigned char * this;
  int param_1;
  uint param_2;
{
  *(uint *)(param_1 * 0x18 + *(int *)this + 0x14) = param_2;
  return;
}

/* FunctionTable__updateForRemovingChunk @ 0x97bccc08 (168 bytes) */
int FunctionTable__updateForRemovingChunk(this, param_1)
  unsigned char * this;
  unsigned char * param_1;
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
      uVar5 = *(uint *)(param_1 + 0xc);
      iVar4 = iVar2 + iVar3;
      if ((((uVar5 & 0x3ffff) == *(uint *)(iVar4 + 0x14)) && (*(int *)(param_1 + 4) != 0)) &&
         (*(int *)(iVar4 + 0x10) != 0)) {
        *(uint *)(iVar4 + 0x14) = *(uint *)(*(int *)(param_1 + 4) + 0xc) & 0x3ffff;
        uVar5 = *(uint *)(param_1 + 0xc);
        iVar3 = *(int *)this;
      }
      if ((((uVar5 & 0x3ffff) == *(uint *)(iVar2 + iVar3 + 0x10)) && (*(int *)(param_1 + 8) != 0))
         && ((uVar5 & 0x3ffff) != 0)) {
        *(uint *)(iVar2 + iVar3 + 0x10) = *(uint *)(*(int *)(param_1 + 8) + 0xc) & 0x3ffff;
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x18;
    } while (iVar1 < *(int *)(this + 4));
    return;
  }
  return;
}

/* FunctionTable__findFunction @ 0x97bcccb0 (132 bytes) */
int FunctionTable__findFunction(this, param_1)
  unsigned char * this;
  char *param_1;
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = *(int *)(this + 4);
  if (0 < iVar1) {
    iVar2 = 0;
    do {
      iVar1 = _strcmp(*(char **)(iVar2 + *(int *)this),param_1);
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
int FunctionTable__getFunctionName(this, param_1)
  unsigned char * this;
  int param_1;
{
  return *(undefined4 *)(param_1 * 0x18 + *(int *)this);
}

/* FunctionTable__getReturnVal @ 0x97bccd44 (20 bytes) */
int FunctionTable__getReturnVal(this, param_1)
  unsigned char * this;
  int param_1;
{
  return *(undefined4 *)(param_1 * 0x18 + *(int *)this + 4);
}

/* FunctionTable__getEmpty @ 0x97bccd58 (20 bytes) */
int FunctionTable__getEmpty(this, param_1)
  unsigned char * this;
  int param_1;
{
  return *(undefined4 *)(param_1 * 0x18 + *(int *)this + 8);
}

/* FunctionTable__getNumParams @ 0x97bccd6c (20 bytes) */
int FunctionTable__getNumParams(this, param_1)
  unsigned char * this;
  int param_1;
{
  return *(undefined4 *)(param_1 * 0x18 + *(int *)this + 0xc);
}

/* FunctionTable__getFirstOp @ 0x97bccd80 (20 bytes) */
int FunctionTable__getFirstOp(this, param_1)
  unsigned char * this;
  int param_1;
{
  return *(undefined4 *)(param_1 * 0x18 + *(int *)this + 0x10);
}

/* FunctionTable__getLastOp @ 0x97bccd94 (20 bytes) */
int FunctionTable__getLastOp(this, param_1)
  unsigned char * this;
  int param_1;
{
  return *(undefined4 *)(param_1 * 0x18 + *(int *)this + 0x14);
}

/* FunctionTable__dump @ 0x97bccda8 (4 bytes) */
int FunctionTable__dump()
{
  return;
}

/* _InterpreterCreate @ 0x97bccdac (60 bytes) */
int _InterpreterCreate()
{
  void *pvVar1;
  
  pvVar1 = _calloc(0xa70,1);
  ((int (*)())_InterpreterInit)();
  return pvVar1;
}

/* _InterpreterFree @ 0x97bccde8 (48 bytes) */
int _InterpreterFree(param_1)
  void *param_1;
{
  ((int (*)())_InterpreterShutdown)();
  _free(param_1);
  return;
}

/* _InterpreterInit @ 0x97bcce18 (72 bytes) */
int _InterpreterInit(param_1)
  void *param_1;
{
  undefined4 uVar1;
  
  _memset(param_1,0,0xa70);
  uVar1 = ((int (*)())_InterpreterTextureSamplerCreate)();
  *(undefined4 *)((int)param_1 + 0xa2c) = uVar1;
  _InterpreterNoiseGeneratorInitialise((int)param_1 + 4);
  _InterpreterRasterOpMachineInitialise((int)param_1 + 0xa24);
  return;
}

/* _InterpreterShutdown @ 0x97bcce60 (8 bytes) */
int _InterpreterShutdown(param_1)
  int param_1;
{
  _InterpreterTextureSamplerFree(*(undefined4 *)(param_1 + 0xa2c));
  return;
}

/* _InterpreterAttachEmulatorContext @ 0x97bcce68 (12 bytes) */
int _InterpreterAttachEmulatorContext(param_1, param_2)
  undefined4 *param_1;
  undefined4 param_2;
{
  *param_1 = param_2;
  _InterpreterRasterOpMachineAttachEmulatorContext(param_1 + 0x289);
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
int _InterpreterWriteDestination(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  int param_2;
  int param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  undefined4 param_8;
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
  uint in_stack_00000038;
  int in_stack_00000040;
  float *in_stack_00000044;
  char in_stack_0000004b;
  float local_50 [4];
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  
  pfVar5 = local_50;
  local_40 = in_stack_00000044[param_4 >> 0x18];
  local_3c = in_stack_00000044[param_4 >> 0x10 & 0xff];
  local_38 = in_stack_00000044[param_4 >> 8 & 0xff];
  local_34 = in_stack_00000044[param_4 & 0xff];
  iVar1 = *param_1;
  *in_stack_00000044 = local_40;
  in_stack_00000044[1] = local_3c;
  in_stack_00000044[2] = local_38;
  in_stack_00000044[3] = local_34;
  iVar2 = *(int *)(iVar1 + 0xd80);
  uStack0000002c = (ushort)((uint)param_6 >> 0x10);
  if (((*(int *)(iVar2 + 0x38) == 0x8804) || (*(int *)(iVar2 + 0x38) == 0x8b30)) &&
     (uStack0000002c == 1)) {
    piVar6 = param_1 + 0x292;
    piVar8 = (int *)(param_2 + in_stack_00000040 * 0x10);
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
        piVar8 = (int *)(iVar1 + (((uint)((param_2 + in_stack_00000040 * 0x10) - iVar1) >> 4) +
                                  param_1[0x290] + (int)sStack00000028 & *(uint *)(iVar2 + 0x88)) *
                                 0x10);
        goto LAB_97bcd680;
      }
    }
    piVar8 = (int *)(param_2 + in_stack_00000040 * 0x10);
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
  if ((((in_stack_00000038 & 0x1000000) != 0) &&
      (iVar1 = ((int (*)())_InterpreterTestCR)(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8),
      iVar1 != 0)) && (pfVar4 = (float *)((int)piVar6 + *piVar8), in_stack_0000004b != '\0')) {
    iVar1 = ___isnanf((double)*in_stack_00000044);
    uVar9 = 3;
    if ((iVar1 == 0) &&
       (uVar9 = DOUBLE_97c30a48 < (double)*in_stack_00000044,
       (double)*in_stack_00000044 < DOUBLE_97c30a48)) {
      uVar9 = 2;
    }
    *(undefined1 *)(param_1 + 0x291) = uVar9;
  }
  pfVar7 = pfVar5;
  if ((((in_stack_00000038 & 0x2000000) != 0) &&
      (iVar1 = ((int (*)())_InterpreterTestCR)(param_1,iStack0000001c,iStack00000020,uStack00000024,
                                  (*(short *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)),(*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x2c)),uStack00000030,uStack00000034),
      iVar1 != 0)) && (pfVar7 = (float *)((int)piVar6 + piVar8[1]), in_stack_0000004b != '\0')) {
    iVar1 = ___isnanf((double)in_stack_00000044[1]);
    uVar9 = 3;
    if ((iVar1 == 0) &&
       (uVar9 = DOUBLE_97c30a48 < (double)in_stack_00000044[1],
       (double)in_stack_00000044[1] < DOUBLE_97c30a48)) {
      uVar9 = 2;
    }
    *(undefined1 *)((int)param_1 + 0xa45) = uVar9;
  }
  pfVar3 = pfVar5;
  if ((((in_stack_00000038 & 0x4000000) != 0) &&
      (iVar1 = ((int (*)())_InterpreterTestCR)(param_1,iStack0000001c,iStack00000020,uStack00000024,
                                  (*(short *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)),(*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x2c)),uStack00000030,uStack00000034),
      iVar1 != 0)) && (pfVar3 = (float *)((int)piVar6 + piVar8[2]), in_stack_0000004b != '\0')) {
    iVar1 = ___isnanf((double)in_stack_00000044[2]);
    uVar9 = 3;
    if ((iVar1 == 0) &&
       (uVar9 = DOUBLE_97c30a48 < (double)in_stack_00000044[2],
       (double)in_stack_00000044[2] < DOUBLE_97c30a48)) {
      uVar9 = 2;
    }
    *(undefined1 *)((int)param_1 + 0xa46) = uVar9;
  }
  if ((((in_stack_00000038 & 0x8000000) != 0) &&
      (iVar1 = ((int (*)())_InterpreterTestCR)(param_1,iStack0000001c,iStack00000020,uStack00000024,
                                  (*(short *)(*(unsigned int *)__builtin_frame_address(0) + 0x28)),(*(unsigned int *)(*(unsigned int *)__builtin_frame_address(0) + 0x2c)),uStack00000030,uStack00000034),
      iVar1 != 0)) && (pfVar5 = (float *)((int)piVar6 + piVar8[3]), in_stack_0000004b != '\0')) {
    iVar1 = ___isnanf((double)in_stack_00000044[3]);
    uVar9 = 3;
    if ((iVar1 == 0) &&
       (uVar9 = DOUBLE_97c30a48 < (double)in_stack_00000044[3],
       (double)in_stack_00000044[3] < DOUBLE_97c30a48)) {
      uVar9 = 2;
    }
    *(undefined1 *)((int)param_1 + 0xa47) = uVar9;
  }
  *pfVar4 = *in_stack_00000044;
  *pfVar7 = in_stack_00000044[1];
  *pfVar3 = in_stack_00000044[2];
  *pfVar5 = in_stack_00000044[3];
  return;
}

/* _InterpreterLoadSource @ 0x97bcd924 (796 bytes) */
int _InterpreterLoadSource(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8)
  int *param_1;
  int *param_2;
  int param_3;
  uint param_4;
  undefined4 param_5;
  undefined4 param_6;
  undefined4 param_7;
  uint param_8;
{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  double dVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  byte bStack00000024;
  byte bStack00000025;
  byte bStack00000026;
  short sStack00000028;
  ushort uStack0000002c;
  char cStack0000002e;
  char cStack0000002f;
  int in_stack_00000040;
  float *in_stack_00000044;
  
  dVar5 = DOUBLE_97c30a58;
  iVar8 = *param_1;
  iVar6 = *(int *)(*(int *)(iVar8 + 0xd80) + 0x38);
  uStack0000002c = (ushort)((uint)param_6 >> 0x10);
  bStack00000026 = (byte)(param_4 >> 8);
  bStack00000025 = (byte)(param_4 >> 0x10);
  bStack00000024 = (byte)(param_4 >> 0x18);
  if (((iVar6 == 0x8804) || (iVar6 == 0x8b30)) && (uStack0000002c == 2)) {
    iVar6 = *(int *)(iVar8 + 0xda4);
    iVar8 = *(int *)(iVar8 + 0xda0);
    fVar1 = *(float *)(iVar6 + param_2[in_stack_00000040 * 4 + (uint)bStack00000024]) *
            (float)param_1[0x28c] +
            *(float *)(iVar8 + param_2[in_stack_00000040 * 4 + (uint)bStack00000024]);
    *in_stack_00000044 = fVar1;
    fVar2 = *(float *)(iVar6 + param_2[in_stack_00000040 * 4 + (uint)bStack00000025]) *
            (float)param_1[0x28c] +
            *(float *)(iVar8 + param_2[in_stack_00000040 * 4 + (uint)bStack00000025]);
    in_stack_00000044[1] = fVar2;
    fVar3 = *(float *)(iVar6 + param_2[in_stack_00000040 * 4 + (uint)bStack00000026]) *
            (float)param_1[0x28c] +
            *(float *)(iVar8 + param_2[in_stack_00000040 * 4 + (uint)bStack00000026]);
    in_stack_00000044[2] = fVar3;
    fVar4 = *(float *)(iVar6 + param_2[in_stack_00000040 * 4 + (param_4 & 0xff)]) *
            (float)param_1[0x28c] +
            *(float *)(iVar8 + param_2[in_stack_00000040 * 4 + (param_4 & 0xff)]);
    in_stack_00000044[3] = fVar4;
    if (*param_2 != 0) {
      *in_stack_00000044 = fVar1 * (float)param_1[0x28f];
      in_stack_00000044[1] = fVar2 * (float)param_1[0x28f];
      in_stack_00000044[2] = fVar3 * (float)param_1[0x28f];
      in_stack_00000044[3] = fVar4 * (float)param_1[0x28f];
    }
  }
  else {
    cStack0000002f = (char)param_6;
    if (cStack0000002f == '\0') {
      param_2 = param_2 + in_stack_00000040 * 4;
    }
    else {
      iVar7 = param_3 * 0xc + *(int *)(iVar8 + 0xd80);
      sStack00000028 = (short)((uint)param_5 >> 0x10);
      iVar6 = *(int *)(iVar7 + 0x80);
      param_2 = (int *)(iVar6 + (((uint)((int)param_2 + (in_stack_00000040 * 0x10 - iVar6)) >> 4) +
                                 param_1[0x290] + (int)sStack00000028 & *(uint *)(iVar7 + 0x88)) *
                                0x10);
    }
    iVar6 = *(int *)((uint)uStack0000002c * 4 + iVar8 + 0xd84);
    if (param_8 < 2) {
      *in_stack_00000044 = *(float *)(iVar6 + param_2[bStack00000024]);
      in_stack_00000044[1] = *(float *)(iVar6 + param_2[bStack00000025]);
      in_stack_00000044[2] = *(float *)(iVar6 + param_2[bStack00000026]);
      fVar1 = *(float *)(iVar6 + param_2[param_4 & 0xff]);
    }
    else {
      if (1 < param_8 - 3) goto LAB_97bcdbfc;
      *in_stack_00000044 =
           (float)((double)CONCAT44(0x43300000,
                                    *(uint *)(iVar6 + param_2[bStack00000024]) ^ 0x80000000) -
                  DOUBLE_97c30a58);
      in_stack_00000044[1] =
           (float)((double)CONCAT44(0x43300000,
                                    *(uint *)(iVar6 + param_2[bStack00000025]) ^ 0x80000000) - dVar5
                  );
      in_stack_00000044[2] =
           (float)((double)CONCAT44(0x43300000,
                                    *(uint *)(iVar6 + param_2[bStack00000026]) ^ 0x80000000) - dVar5
                  );
      fVar1 = (float)((double)CONCAT44(0x43300000,
                                       *(uint *)(iVar6 + param_2[param_4 & 0xff]) ^ 0x80000000) -
                     dVar5);
    }
    in_stack_00000044[3] = fVar1;
  }
LAB_97bcdbfc:
  cStack0000002e = (char)((uint)param_6 >> 8);
  if (cStack0000002e != '\0') {
    *in_stack_00000044 = -*in_stack_00000044;
    in_stack_00000044[1] = -in_stack_00000044[1];
    in_stack_00000044[2] = -in_stack_00000044[2];
    in_stack_00000044[3] = -in_stack_00000044[3];
  }
  return;
}

/* _InterpreterTestCR @ 0x97bcdc40 (240 bytes) */
int _InterpreterTestCR(param_1)
  int param_1;
{
  uint uVar1;
  uint uVar2;
  undefined4 in_stack_00000038;
  int in_stack_00000040;
  
  uVar1 = 0;
  uVar2 = (uint)*(byte *)((uint)*(byte *)((int)&STACKARG(0x38) + in_stack_00000040 + 2) + param_1 +
                         0xa44);
  switch((*(unsigned char *)((unsigned char *)&(in_stack_00000038) + 1))) {
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
int _InterpreterEmulateOp()
{
  float *pfVar1;
  float *pfVar2;
  bool bVar3;
  float fVar4;
  char cVar5;
  byte bVar6;
  char cVar7;
  float fVar8;
  uint uVar9;
  uint uVar10;
  byte *pbVar11;
  float *pfVar12;
  int *piVar13;
  int *piVar14;
  int *piVar15;
  undefined4 uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  int *piVar21;
  int iVar22;
  uint uVar23;
  int iVar24;
  uint uVar25;
  bool bVar26;
  int iVar27;
  double dVar28;
  double dVar29;
  double dVar30;
  double dVar31;
  double dVar32;
  undefined8 uVar33;
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
  
  uVar33 = FUN_97c1a258();
  piVar14 = (int *)((ulonglong)uVar33 >> 0x20);
  piVar15 = (int *)uVar33;
  iVar22 = *piVar14;
  piVar21 = piVar15 + 0x47;
  if (piVar15 == *(int **)(*(int *)(iVar22 + 0xd80) + 4)) {
    piVar21 = (int *)0x0;
  }
  iVar18 = piVar15[0xc];
  local_130[3] = 0.0;
  uVar23 = 1;
  local_130[0] = 0.0;
  local_130[1] = 0.0;
  bVar26 = true;
  local_130[2] = 0.0;
  iVar24 = *piVar15;
  cVar5 = *(char *)(piVar15 + 1);
  if (iVar18 != 0) {
    pbVar11 = (byte *)((int)piVar15 + 0x49);
    iVar27 = iVar18;
    do {
      if ((pbVar11[-1] != 0) && (uVar23 < *pbVar11)) {
        uVar23 = (uint)*pbVar11;
      }
      pbVar11 = pbVar11 + 0x24;
      iVar27 = iVar27 + -1;
    } while (iVar27 != 0);
  }
  if (iVar24 == 0x22) {
    cVar5 = *(char *)(piVar15 + 0x12);
    if ((cVar5 == '\0') && (*(char *)(piVar15 + 0x1b) == '\0')) {
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_130[0] = local_130[4] * local_130[8];
      local_130[1] = local_130[5] * local_130[9];
      local_130[2] = local_130[6] * local_130[10];
      iVar20 = piVar15[9];
      local_130[3] = local_130[7] * local_130[0xb];
      iVar22 = piVar15[3];
      iVar18 = piVar15[4];
      iVar24 = piVar15[5];
      iVar27 = piVar15[6];
      iVar17 = piVar15[7];
      iVar19 = piVar15[8];
    }
    else if ((cVar5 == '\0') ||
            ((*(char *)(piVar15 + 0x1b) == '\0' ||
             (*(char *)((int)piVar15 + 0x49) != *(char *)((int)piVar15 + 0x6d))))) {
      if ((cVar5 == '\0') || (*(byte *)((int)piVar15 + 0x6d) < 2)) {
        if ((*(char *)(piVar15 + 0x1b) == '\0') || (*(byte *)((int)piVar15 + 0x49) < 2)) {
          uVar25 = (uint)(cVar5 == '\0');
          if (uVar25 == 0) {
            iVar22 = 0x54;
          }
          else {
            iVar22 = 0x30;
          }
          ((int (*)())_InterpreterLoadSource)(piVar14,*(undefined4 *)((int)piVar15 + iVar22 + 4),
                     *(undefined4 *)((int)piVar15 + iVar22 + 8),
                     *(undefined4 *)((int)piVar15 + iVar22 + 0xc),
                     *(undefined4 *)((int)piVar15 + iVar22 + 0x10),
                     *(undefined4 *)((int)piVar15 + iVar22 + 0x14),
                     *(undefined4 *)((int)piVar15 + iVar22 + 0x18),
                     *(undefined4 *)((int)piVar15 + iVar22 + 0x1c));
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[uVar25 * 9 + 0xd],piVar15[uVar25 * 9 + 0xe],
                     piVar15[uVar25 * 9 + 0xf],piVar15[uVar25 * 9 + 0x10],piVar15[uVar25 * 9 + 0x11]
                     ,piVar15[uVar25 * 9 + 0x12],piVar15[uVar25 * 9 + 0x13]);
          if (uVar23 == 2) {
            local_130[0] = local_130[4] * local_130[8];
            local_130[1] = local_130[4] * local_130[9];
            ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                       piVar15[9]);
            ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[uVar25 * 9 + 0xd],piVar15[uVar25 * 9 + 0xe],
                       piVar15[uVar25 * 9 + 0xf],piVar15[uVar25 * 9 + 0x10],
                       piVar15[uVar25 * 9 + 0x11],piVar15[uVar25 * 9 + 0x12],
                       piVar15[uVar25 * 9 + 0x13]);
            local_130[0] = local_130[4] * local_130[8];
            iVar20 = piVar15[9];
            local_130[1] = local_130[4] * local_130[9];
            iVar22 = piVar15[3];
            iVar18 = piVar15[4];
            iVar24 = piVar15[5];
            iVar27 = piVar15[6];
            iVar17 = piVar15[7];
            iVar19 = piVar15[8];
          }
          else if (uVar23 == 3) {
            local_130[0] = local_130[4] * local_130[8];
            local_130[2] = local_130[4] * local_130[10];
            local_130[1] = local_130[4] * local_130[9];
            ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                       piVar15[9]);
            ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[uVar25 * 9 + 0xd],piVar15[uVar25 * 9 + 0xe],
                       piVar15[uVar25 * 9 + 0xf],piVar15[uVar25 * 9 + 0x10],
                       piVar15[uVar25 * 9 + 0x11],piVar15[uVar25 * 9 + 0x12],
                       piVar15[uVar25 * 9 + 0x13]);
            local_130[0] = local_130[4] * local_130[8];
            local_130[2] = local_130[4] * local_130[10];
            local_130[1] = local_130[4] * local_130[9];
            ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                       piVar15[9]);
            ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[uVar25 * 9 + 0xd],piVar15[uVar25 * 9 + 0xe],
                       piVar15[uVar25 * 9 + 0xf],piVar15[uVar25 * 9 + 0x10],
                       piVar15[uVar25 * 9 + 0x11],piVar15[uVar25 * 9 + 0x12],
                       piVar15[uVar25 * 9 + 0x13]);
            local_130[0] = local_130[4] * local_130[8];
            local_130[2] = local_130[4] * local_130[10];
            iVar20 = piVar15[9];
            local_130[1] = local_130[4] * local_130[9];
            iVar22 = piVar15[3];
            iVar18 = piVar15[4];
            iVar24 = piVar15[5];
            iVar27 = piVar15[6];
            iVar17 = piVar15[7];
            iVar19 = piVar15[8];
          }
          else {
            if (uVar23 != 4) {
              return piVar21;
            }
            local_130[0] = local_130[4] * local_130[8];
            local_130[3] = local_130[4] * local_130[0xb];
            local_130[1] = local_130[4] * local_130[9];
            local_130[2] = local_130[4] * local_130[10];
            ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                       piVar15[9]);
            ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[uVar25 * 9 + 0xd],piVar15[uVar25 * 9 + 0xe],
                       piVar15[uVar25 * 9 + 0xf],piVar15[uVar25 * 9 + 0x10],
                       piVar15[uVar25 * 9 + 0x11],piVar15[uVar25 * 9 + 0x12],
                       piVar15[uVar25 * 9 + 0x13]);
            local_130[0] = local_130[4] * local_130[8];
            local_130[3] = local_130[4] * local_130[0xb];
            local_130[1] = local_130[4] * local_130[9];
            local_130[2] = local_130[4] * local_130[10];
            ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                       piVar15[9]);
            ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[uVar25 * 9 + 0xd],piVar15[uVar25 * 9 + 0xe],
                       piVar15[uVar25 * 9 + 0xf],piVar15[uVar25 * 9 + 0x10],
                       piVar15[uVar25 * 9 + 0x11],piVar15[uVar25 * 9 + 0x12],
                       piVar15[uVar25 * 9 + 0x13]);
            local_130[0] = local_130[4] * local_130[8];
            local_130[3] = local_130[4] * local_130[0xb];
            local_130[1] = local_130[4] * local_130[9];
            local_130[2] = local_130[4] * local_130[10];
            ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                       piVar15[9]);
            ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[uVar25 * 9 + 0xd],piVar15[uVar25 * 9 + 0xe],
                       piVar15[uVar25 * 9 + 0xf],piVar15[uVar25 * 9 + 0x10],
                       piVar15[uVar25 * 9 + 0x11],piVar15[uVar25 * 9 + 0x12],
                       piVar15[uVar25 * 9 + 0x13]);
            local_130[0] = local_130[4] * local_130[8];
            local_130[3] = local_130[4] * local_130[0xb];
            local_130[1] = local_130[4] * local_130[9];
            iVar20 = piVar15[9];
            local_130[2] = local_130[4] * local_130[10];
            iVar22 = piVar15[3];
            iVar18 = piVar15[4];
            iVar24 = piVar15[5];
            iVar27 = piVar15[6];
            iVar17 = piVar15[7];
            iVar19 = piVar15[8];
          }
          goto LAB_97bd043c;
        }
        ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                   piVar15[0x12],piVar15[0x13]);
        ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                   piVar15[0x1b],piVar15[0x1c]);
        if (uVar23 == 2) {
          local_130[0] = local_130[4] * local_130[8] + local_130[5] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                     piVar15[0x1b],piVar15[0x1c]);
          local_130[1] = local_130[4] * local_130[8] + local_130[5] * local_130[9];
        }
        else if (uVar23 == 3) {
          local_130[0] = local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                     piVar15[0x1b],piVar15[0x1c]);
          local_130[1] = local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                     piVar15[0x1b],piVar15[0x1c]);
          local_130[2] = local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
        }
        else if (uVar23 == 4) {
          local_130[0] = local_130[7] * local_130[0xb] +
                         local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                     piVar15[0x1b],piVar15[0x1c]);
          local_130[1] = local_130[7] * local_130[0xb] +
                         local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                     piVar15[0x1b],piVar15[0x1c]);
          local_130[2] = local_130[7] * local_130[0xb] +
                         local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                     piVar15[0x1b],piVar15[0x1c]);
          local_130[3] = local_130[7] * local_130[0xb] +
                         local_130[6] * local_130[10] +
                         local_130[4] * local_130[8] + local_130[5] * local_130[9];
        }
      }
      else {
        ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                   piVar15[0x12],piVar15[0x13]);
        ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                   piVar15[0x1b],piVar15[0x1c]);
        if (uVar23 == 2) {
          local_130[0] = local_130[4] * local_130[8];
          local_130[1] = local_130[4] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                     piVar15[0x12],piVar15[0x13]);
          local_130[0] = local_130[5] * local_130[8] + local_130[0];
          local_130[1] = local_130[5] * local_130[9] + local_130[1];
        }
        else if (uVar23 == 3) {
          local_130[0] = local_130[4] * local_130[8];
          local_130[2] = local_130[4] * local_130[10];
          local_130[1] = local_130[4] * local_130[9];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                     piVar15[0x12],piVar15[0x13]);
          local_130[0] = local_130[5] * local_130[8] + local_130[0];
          local_130[2] = local_130[5] * local_130[10] + local_130[2];
          local_130[1] = local_130[5] * local_130[9] + local_130[1];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                     piVar15[0x12],piVar15[0x13]);
          local_130[0] = local_130[6] * local_130[8] + local_130[0];
          local_130[2] = local_130[6] * local_130[10] + local_130[2];
          local_130[1] = local_130[6] * local_130[9] + local_130[1];
        }
        else if (uVar23 == 4) {
          local_130[0] = local_130[4] * local_130[8];
          local_130[3] = local_130[4] * local_130[0xb];
          local_130[1] = local_130[4] * local_130[9];
          local_130[2] = local_130[4] * local_130[10];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                     piVar15[0x12],piVar15[0x13]);
          local_130[0] = local_130[5] * local_130[8] + local_130[0];
          local_130[3] = local_130[5] * local_130[0xb] + local_130[3];
          local_130[1] = local_130[5] * local_130[9] + local_130[1];
          local_130[2] = local_130[5] * local_130[10] + local_130[2];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                     piVar15[0x12],piVar15[0x13]);
          local_130[0] = local_130[6] * local_130[8] + local_130[0];
          local_130[3] = local_130[6] * local_130[0xb] + local_130[3];
          local_130[1] = local_130[6] * local_130[9] + local_130[1];
          local_130[2] = local_130[6] * local_130[10] + local_130[2];
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                     piVar15[0x12],piVar15[0x13]);
          local_130[0] = local_130[7] * local_130[8] + local_130[0];
          local_130[3] = local_130[7] * local_130[0xb] + local_130[3];
          local_130[1] = local_130[7] * local_130[9] + local_130[1];
          local_130[2] = local_130[7] * local_130[10] + local_130[2];
        }
      }
      iVar20 = piVar15[9];
      iVar22 = piVar15[3];
      iVar18 = piVar15[4];
      iVar24 = piVar15[5];
      iVar27 = piVar15[6];
      iVar17 = piVar15[7];
      iVar19 = piVar15[8];
    }
    else if (uVar23 == 2) {
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_f0 = local_130[4] * local_130[8];
      local_ec = local_130[5] * local_130[8];
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_f0 = local_130[4] * local_130[9] + local_f0;
      local_ec = local_130[5] * local_130[9] + local_ec;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_e0 = local_130[4] * local_130[9];
      local_dc = local_130[5] * local_130[9];
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_e0 = local_130[4] * local_130[8] + local_e0;
      local_dc = local_130[5] * local_130[8] + local_dc;
      ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                 piVar15[9]);
      iVar20 = piVar15[9];
      iVar22 = piVar15[3];
      iVar18 = piVar15[4];
      iVar24 = piVar15[5];
      iVar27 = piVar15[6];
      iVar17 = piVar15[7];
      iVar19 = piVar15[8];
    }
    else if (uVar23 == 3) {
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_f0 = local_130[4] * local_130[8];
      local_e8 = local_130[6] * local_130[8];
      local_ec = local_130[5] * local_130[8];
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_f0 = local_130[4] * local_130[9] + local_f0;
      local_e8 = local_130[6] * local_130[9] + local_e8;
      local_ec = local_130[5] * local_130[9] + local_ec;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_f0 = local_130[4] * local_130[10] + local_f0;
      local_e8 = local_130[6] * local_130[10] + local_e8;
      local_ec = local_130[5] * local_130[10] + local_ec;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_e0 = local_130[4] * local_130[10];
      local_d8 = local_130[6] * local_130[10];
      local_dc = local_130[5] * local_130[10];
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_e0 = local_130[4] * local_130[9] + local_e0;
      local_d8 = local_130[6] * local_130[9] + local_d8;
      local_dc = local_130[5] * local_130[9] + local_dc;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_e0 = local_130[4] * local_130[8] + local_e0;
      local_d8 = local_130[6] * local_130[8] + local_d8;
      local_dc = local_130[5] * local_130[8] + local_dc;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_d0 = local_130[4] * local_130[8];
      local_c8 = local_130[6] * local_130[8];
      local_cc = local_130[5] * local_130[8];
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_d0 = local_130[4] * local_130[9] + local_d0;
      local_c8 = local_130[6] * local_130[9] + local_c8;
      local_cc = local_130[5] * local_130[9] + local_cc;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_d0 = local_130[4] * local_130[10] + local_d0;
      local_c8 = local_130[6] * local_130[10] + local_c8;
      local_cc = local_130[5] * local_130[10] + local_cc;
      ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                 piVar15[9]);
      ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                 piVar15[9]);
      iVar20 = piVar15[9];
      iVar22 = piVar15[3];
      iVar18 = piVar15[4];
      iVar24 = piVar15[5];
      iVar27 = piVar15[6];
      iVar17 = piVar15[7];
      iVar19 = piVar15[8];
    }
    else {
      if (uVar23 != 4) {
        return piVar21;
      }
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_f0 = local_130[4] * local_130[8];
      local_e4 = local_130[7] * local_130[8];
      local_ec = local_130[5] * local_130[8];
      local_e8 = local_130[6] * local_130[8];
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_f0 = local_130[4] * local_130[9] + local_f0;
      local_e4 = local_130[7] * local_130[9] + local_e4;
      local_ec = local_130[5] * local_130[9] + local_ec;
      local_e8 = local_130[6] * local_130[9] + local_e8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_f0 = local_130[4] * local_130[10] + local_f0;
      local_e4 = local_130[7] * local_130[10] + local_e4;
      local_ec = local_130[5] * local_130[10] + local_ec;
      local_e8 = local_130[6] * local_130[10] + local_e8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_f0 = local_130[4] * local_130[0xb] + local_f0;
      local_e4 = local_130[7] * local_130[0xb] + local_e4;
      local_ec = local_130[5] * local_130[0xb] + local_ec;
      local_e8 = local_130[6] * local_130[0xb] + local_e8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_e0 = local_130[4] * local_130[0xb];
      local_d4 = local_130[7] * local_130[0xb];
      local_dc = local_130[5] * local_130[0xb];
      local_d8 = local_130[6] * local_130[0xb];
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_e0 = local_130[4] * local_130[10] + local_e0;
      local_d4 = local_130[7] * local_130[10] + local_d4;
      local_dc = local_130[5] * local_130[10] + local_dc;
      local_d8 = local_130[6] * local_130[10] + local_d8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_e0 = local_130[4] * local_130[9] + local_e0;
      local_d4 = local_130[7] * local_130[9] + local_d4;
      local_dc = local_130[5] * local_130[9] + local_dc;
      local_d8 = local_130[6] * local_130[9] + local_d8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_e0 = local_130[4] * local_130[8] + local_e0;
      local_d4 = local_130[7] * local_130[8] + local_d4;
      local_dc = local_130[5] * local_130[8] + local_dc;
      local_d8 = local_130[6] * local_130[8] + local_d8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_d0 = local_130[4] * local_130[8];
      local_c4 = local_130[7] * local_130[8];
      local_cc = local_130[5] * local_130[8];
      local_c8 = local_130[6] * local_130[8];
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_d0 = local_130[4] * local_130[9] + local_d0;
      local_c4 = local_130[7] * local_130[9] + local_c4;
      local_cc = local_130[5] * local_130[9] + local_cc;
      local_c8 = local_130[6] * local_130[9] + local_c8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_d0 = local_130[4] * local_130[10] + local_d0;
      local_c4 = local_130[7] * local_130[10] + local_c4;
      local_cc = local_130[5] * local_130[10] + local_cc;
      local_c8 = local_130[6] * local_130[10] + local_c8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_d0 = local_130[4] * local_130[0xb] + local_d0;
      local_c4 = local_130[7] * local_130[0xb] + local_c4;
      local_cc = local_130[5] * local_130[0xb] + local_cc;
      local_c8 = local_130[6] * local_130[0xb] + local_c8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                 piVar15[0x1b],piVar15[0x1c]);
      local_c0 = local_130[4] * local_130[0xb];
      local_b4 = local_130[7] * local_130[0xb];
      local_bc = local_130[5] * local_130[0xb];
      local_b8 = local_130[6] * local_130[0xb];
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_c0 = local_130[4] * local_130[10] + local_c0;
      local_b4 = local_130[7] * local_130[10] + local_b4;
      local_bc = local_130[5] * local_130[10] + local_bc;
      local_b8 = local_130[6] * local_130[10] + local_b8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_c0 = local_130[4] * local_130[9] + local_c0;
      local_b4 = local_130[7] * local_130[9] + local_b4;
      local_bc = local_130[5] * local_130[9] + local_bc;
      local_b8 = local_130[6] * local_130[9] + local_b8;
      ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                 piVar15[0x12],piVar15[0x13]);
      local_c0 = local_130[4] * local_130[8] + local_c0;
      local_b4 = local_130[7] * local_130[8] + local_b4;
      local_bc = local_130[5] * local_130[8] + local_bc;
      local_b8 = local_130[6] * local_130[8] + local_b8;
      ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                 piVar15[9]);
      ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                 piVar15[9]);
      ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                 piVar15[9]);
      iVar20 = piVar15[9];
      iVar22 = piVar15[3];
      iVar18 = piVar15[4];
      iVar24 = piVar15[5];
      iVar27 = piVar15[6];
      iVar17 = piVar15[7];
      iVar19 = piVar15[8];
    }
    goto LAB_97bd043c;
  }
  if ((iVar24 != 0x31) && (iVar24 != 0x36)) {
    uVar25 = 0;
    if (uVar23 == 0) {
      return piVar21;
    }
    do {
      if (((iVar18 != 0) &&
          (((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                      piVar15[0x12],piVar15[0x13]), 1 < (uint)piVar15[0xc])) &&
         (((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                     piVar15[0x1b],piVar15[0x1c]), 2 < (uint)piVar15[0xc])) {
        ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x1f],piVar15[0x20],piVar15[0x21],piVar15[0x22],piVar15[0x23],
                   piVar15[0x24],piVar15[0x25]);
      }
      fVar4 = TAllocation__guardBlockSize;
      dVar28 = DOUBLE_97c30a60;
      fVar8 = local_130[7];
      switch(iVar24) {
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
          local_130[1] = local_130[4];
          dVar28 = (double)_pow((double)local_130[5],(double)local_130[7]);
          local_130[2] = (float)dVar28;
        }
        goto LAB_97bd1cd8;
      case 2:
        local_130[0] = ABS(local_130[4]);
        local_130[1] = ABS(local_130[5]);
        local_130[2] = ABS(local_130[6]);
        local_130[3] = ABS(local_130[7]);
        break;
      case 3:
        dVar28 = (double)_ceil((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_ceil((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_ceil((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_ceil((double)local_130[7]);
        goto LAB_97bd2010;
      case 4:
        dVar30 = (double)local_130[4];
        dVar28 = (double)_floor(dVar30);
        dVar29 = (double)local_130[5];
        local_130[0] = (float)(dVar30 - dVar28);
        dVar28 = (double)_floor(dVar29);
        dVar30 = (double)local_130[6];
        local_130[1] = (float)(dVar29 - dVar28);
        dVar29 = (double)_floor(dVar30);
        dVar28 = (double)local_130[7];
        local_130[2] = (float)(dVar30 - dVar29);
        dVar29 = (double)_floor(dVar28);
        dVar28 = dVar28 - dVar29;
        goto LAB_97bd1440;
      case 5:
        dVar28 = (double)_floor((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_floor((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_floor((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_floor((double)local_130[7]);
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
          uVar9 = 0;
          if (local_130[7] == TAllocation__guardBlockSize) goto LAB_97bd0ac8;
        }
        uVar9 = 1;
        goto LAB_97bd0ac8;
      case 9:
        uVar9 = 0;
        if (((local_130[4] != TAllocation__guardBlockSize) &&
            (local_130[5] != TAllocation__guardBlockSize)) &&
           (local_130[6] != TAllocation__guardBlockSize)) goto LAB_97bd0ab8;
LAB_97bd0ac8:
        uStack_ac = uVar9 ^ 0x80000000;
        local_b0 = 0x43300000;
        dVar28 = (double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58;
LAB_97bd0cc8:
        local_130[0] = (float)dVar28;
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
        bVar6 = *(byte *)((int)piVar15 + 5);
        if (bVar6 == 2) {
          _InterpreterNoiseGeneratorCalculate2D(piVar14 + 1,local_130 + 4,local_130);
        }
        else if (bVar6 < 3) {
          if (bVar6 == 1) {
            _InterpreterNoiseGeneratorCalculate1D(piVar14 + 1,local_130 + 4,local_130);
          }
        }
        else if (bVar6 == 3) {
          _InterpreterNoiseGeneratorCalculate3D(piVar14 + 1,local_130 + 4,local_130);
        }
        else if (bVar6 == 4) {
          _InterpreterNoiseGeneratorCalculate4D(piVar14 + 1,local_130 + 4,local_130);
        }
        break;
      case 0xc:
        dVar28 = (double)_sqrt(ABS((double)local_130[4]));
        local_130[0] = (float)dVar28;
        dVar28 = (double)_sqrt(ABS((double)local_130[5]));
        local_130[1] = (float)dVar28;
        dVar28 = (double)_sqrt(ABS((double)local_130[6]));
        local_130[2] = (float)dVar28;
        dVar28 = (double)_sqrt(ABS((double)local_130[7]));
        goto LAB_97bd2010;
      case 0xd:
        if (*(int *)(*(int *)(iVar22 + 0xd80) + 0x38) - 0x8b30U < 2) {
          dVar29 = (double)_sqrt(ABS((double)local_130[4]));
          local_130[0] = (float)(dVar28 / dVar29);
          dVar29 = (double)_sqrt(ABS((double)local_130[5]));
          local_130[1] = (float)(dVar28 / dVar29);
          dVar29 = (double)_sqrt(ABS((double)local_130[6]));
          local_130[2] = (float)(dVar28 / dVar29);
          dVar29 = (double)_sqrt(ABS((double)local_130[7]));
          dVar28 = dVar28 / dVar29;
          goto LAB_97bd1440;
        }
        dVar28 = (double)_sqrt(ABS((double)local_130[7]));
        dVar28 = DOUBLE_97c30a60 / dVar28;
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
        if (1 < *(int *)(*(int *)(iVar22 + 0xd80) + 0x38) - 0x8b30U) {
          dVar28 = (double)_exp2((double)local_130[7]);
          goto LAB_97bd1d68;
        }
        dVar28 = (double)_exp2((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_exp2((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_exp2((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_exp2((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x11:
        dVar28 = (double)_floor((double)local_130[7]);
        dVar29 = (double)_exp2((double)(float)dVar28);
        local_130[0] = (float)dVar29;
        local_130[1] = (float)((double)local_130[7] - (double)(float)dVar28);
        dVar28 = (double)_exp2((double)local_130[7]);
        goto LAB_97bd0fd4;
      case 0x12:
        uVar9 = (uint)*(byte *)((int)piVar15 + 5);
        dVar28 = (double)TAllocation__guardBlockSize;
        if (uVar9 != 0) {
          pfVar12 = local_130 + 4;
          do {
            fVar4 = *pfVar12;
            pfVar12 = pfVar12 + 1;
            dVar28 = (double)(float)((double)fVar4 * (double)fVar4 + dVar28);
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
LAB_97bd1924:
        dVar28 = (double)_sqrt(dVar28);
LAB_97bd1d68:
        local_130[0] = (float)dVar28;
        local_130[1] = local_130[0];
        local_130[2] = local_130[0];
        local_130[3] = local_130[0];
        break;
      case 0x13:
        if (1 < *(int *)(*(int *)(iVar22 + 0xd80) + 0x38) - 0x8b30U) {
          dVar28 = (double)local_130[7];
          if ((double)local_130[7] < (double)TAllocation__guardBlockSize) {
            dVar28 = DOUBLE_97c30a48;
          }
          dVar28 = (double)_log2(dVar28);
          goto LAB_97bd1d68;
        }
        dVar28 = (double)local_130[4];
        if ((double)local_130[4] < (double)TAllocation__guardBlockSize) {
          dVar28 = DOUBLE_97c30a48;
        }
        dVar29 = (double)_log2(dVar28);
        dVar28 = (double)local_130[5];
        local_130[0] = (float)dVar29;
        if (dVar28 < (double)TAllocation__guardBlockSize) {
          dVar28 = DOUBLE_97c30a48;
        }
        dVar29 = (double)_log2(dVar28);
        dVar28 = (double)local_130[6];
        local_130[1] = (float)dVar29;
        if (dVar28 < (double)TAllocation__guardBlockSize) {
          dVar28 = DOUBLE_97c30a48;
        }
        dVar29 = (double)_log2(dVar28);
        dVar28 = (double)local_130[7];
        local_130[2] = (float)dVar29;
        if (dVar28 < (double)TAllocation__guardBlockSize) {
          dVar28 = DOUBLE_97c30a48;
        }
        dVar28 = (double)_log2(dVar28);
        goto LAB_97bd2010;
      case 0x14:
        dVar28 = ABS((double)local_130[7]);
        _log2(dVar28);
        dVar29 = (double)_floor();
        local_130[0] = (float)dVar29;
        dVar29 = (double)_exp2((double)local_130[0]);
        local_130[1] = (float)(dVar28 / dVar29);
        if (dVar28 < (double)TAllocation__guardBlockSize) {
          dVar28 = DOUBLE_97c30a48;
        }
        dVar28 = (double)_log2(dVar28);
LAB_97bd0fd4:
        local_130[2] = (float)dVar28;
        local_130[3] = 1.0;
        break;
      case 0x15:
        uVar9 = (uint)*(byte *)((int)piVar15 + 5);
        dVar28 = (double)TAllocation__guardBlockSize;
        if (uVar9 != 0) {
          pfVar12 = local_130 + 4;
          do {
            fVar4 = *pfVar12;
            pfVar12 = pfVar12 + 1;
            dVar28 = (double)(float)((double)fVar4 * (double)fVar4 + dVar28);
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        dVar28 = (double)_sqrt(dVar28);
        uVar9 = (uint)*(byte *)((int)piVar15 + 5);
        if (uVar9 != 0) {
          pfVar12 = local_130;
          do {
            *pfVar12 = pfVar12[4] / (float)dVar28;
            pfVar12 = pfVar12 + 1;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        break;
      case 0x16:
        fVar4 = FLOAT_97c3acd0;
        goto LAB_97bd109c;
      case 0x17:
        fVar4 = FLOAT_97c3acd4;
LAB_97bd109c:
        local_130[0] = local_130[4] * fVar4;
        local_130[1] = local_130[5] * fVar4;
        local_130[2] = local_130[6] * fVar4;
        local_130[3] = local_130[7] * fVar4;
        break;
      case 0x18:
        dVar28 = (double)_cos((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_sin((double)local_130[4]);
        local_130[1] = (float)dVar28;
        local_130[3] = 0.0;
        local_130[2] = 0.0;
        break;
      case 0x19:
        if (1 < *(int *)(*(int *)(iVar22 + 0xd80) + 0x38) - 0x8b30U) {
          dVar28 = (double)_sin((double)local_130[7]);
          goto LAB_97bd1d68;
        }
        dVar28 = (double)_sin((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_sin((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_sin((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_sin((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x1a:
        if (1 < *(int *)(*(int *)(iVar22 + 0xd80) + 0x38) - 0x8b30U) {
          dVar28 = (double)_cos((double)local_130[7]);
          goto LAB_97bd1d68;
        }
        dVar28 = (double)_cos((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_cos((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_cos((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_cos((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x1b:
        dVar28 = (double)_tan((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_tan((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_tan((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_tan((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x1c:
        dVar28 = (double)_asin((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_asin((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_asin((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_asin((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x1d:
        dVar28 = (double)_acos((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_acos((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_acos((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_acos((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x1e:
        if (piVar15[0xc] == 1) {
          dVar28 = (double)_atan((double)local_130[4]);
          local_130[0] = (float)dVar28;
          dVar28 = (double)_atan((double)local_130[5]);
          local_130[1] = (float)dVar28;
          dVar28 = (double)_atan((double)local_130[6]);
          local_130[2] = (float)dVar28;
          dVar28 = (double)_atan((double)local_130[7]);
          goto LAB_97bd2010;
        }
        dVar28 = (double)_atan2f((double)local_130[4],(double)local_130[8]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_atan2f((double)local_130[5],(double)local_130[9]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_atan2f((double)local_130[6],(double)local_130[10]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_atan2f((double)local_130[7],(double)local_130[0xb]);
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
        if (*(char *)((int)piVar15 + 0x6d) == '\x01') {
          dVar28 = (double)local_130[4];
          dVar32 = (double)local_130[8];
          dVar29 = (double)_floor((double)(float)(dVar28 / dVar32));
          dVar30 = (double)local_130[5];
          dVar31 = (double)local_130[8];
          local_130[0] = (float)-(dVar32 * dVar29 - dVar28);
          dVar28 = (double)_floor((double)(float)(dVar30 / dVar31));
          dVar29 = (double)local_130[6];
          dVar32 = (double)local_130[8];
          local_130[1] = (float)-(dVar31 * dVar28 - dVar30);
          dVar28 = (double)_floor((double)(float)(dVar29 / dVar32));
          fVar4 = local_130[8];
        }
        else {
          dVar28 = (double)local_130[4];
          dVar32 = (double)local_130[8];
          dVar29 = (double)_floor((double)(float)(dVar28 / dVar32));
          dVar30 = (double)local_130[5];
          dVar31 = (double)local_130[9];
          local_130[0] = (float)-(dVar32 * dVar29 - dVar28);
          dVar28 = (double)_floor((double)(float)(dVar30 / dVar31));
          dVar29 = (double)local_130[6];
          dVar32 = (double)local_130[10];
          local_130[1] = (float)-(dVar31 * dVar28 - dVar30);
          dVar28 = (double)_floor((double)(float)(dVar29 / dVar32));
          fVar4 = local_130[0xb];
        }
        dVar30 = (double)local_130[7];
        local_130[2] = (float)-(dVar32 * dVar28 - dVar29);
        dVar28 = (double)_floor((double)(float)(dVar30 / (double)fVar4));
        dVar28 = -((double)fVar4 * dVar28 - dVar30);
LAB_97bd1440:
        local_130[3] = (float)dVar28;
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
        uVar9 = 0;
        if ((local_130[4] != TAllocation__guardBlockSize) &&
           (local_130[8] != TAllocation__guardBlockSize)) {
          uVar9 = 1;
        }
        uVar10 = 0;
        local_130[0] = (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58);
        if ((local_130[5] != TAllocation__guardBlockSize) &&
           (local_130[9] != TAllocation__guardBlockSize)) {
          uVar10 = 1;
        }
        uVar9 = 0;
        local_130[1] = (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - DOUBLE_97c30a58);
        if ((local_130[6] != TAllocation__guardBlockSize) &&
           (local_130[10] != TAllocation__guardBlockSize)) {
          uVar9 = 1;
        }
        uVar10 = 0;
        local_130[2] = (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58);
        if (local_130[7] != TAllocation__guardBlockSize) {
LAB_97bd17d0:
          uVar10 = 0;
          if (local_130[0xb] != TAllocation__guardBlockSize) goto LAB_97bd17ec;
        }
        goto LAB_97bd17f0;
      case 0x25:
        uVar9 = 0;
        if ((local_130[4] != TAllocation__guardBlockSize) ||
           (local_130[8] != TAllocation__guardBlockSize)) {
          uVar9 = 1;
        }
        uVar10 = 0;
        local_130[0] = (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58);
        if ((local_130[5] != TAllocation__guardBlockSize) ||
           (local_130[9] != TAllocation__guardBlockSize)) {
          uVar10 = 1;
        }
        uVar9 = 0;
        local_130[1] = (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - DOUBLE_97c30a58);
        if ((local_130[6] != TAllocation__guardBlockSize) ||
           (local_130[10] != TAllocation__guardBlockSize)) {
          uVar9 = 1;
        }
        local_130[2] = (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58);
        if (local_130[7] == TAllocation__guardBlockSize) goto LAB_97bd17d0;
LAB_97bd17ec:
        uVar10 = 1;
        goto LAB_97bd17f0;
      case 0x26:
        uVar9 = 0;
        if (local_130[4] == TAllocation__guardBlockSize) {
          if (local_130[8] != TAllocation__guardBlockSize) {
LAB_97bd16cc:
            uVar9 = 1;
          }
        }
        else if (local_130[8] == TAllocation__guardBlockSize) goto LAB_97bd16cc;
        uVar10 = 0;
        local_130[0] = (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58);
        if (local_130[5] == TAllocation__guardBlockSize) {
          if (local_130[9] != TAllocation__guardBlockSize) {
LAB_97bd172c:
            uVar10 = 1;
          }
        }
        else if (local_130[9] == TAllocation__guardBlockSize) goto LAB_97bd172c;
        uVar9 = 0;
        local_130[1] = (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - DOUBLE_97c30a58);
        if (local_130[6] == TAllocation__guardBlockSize) {
          if (local_130[10] != TAllocation__guardBlockSize) {
LAB_97bd178c:
            uVar9 = 1;
          }
        }
        else if (local_130[10] == TAllocation__guardBlockSize) goto LAB_97bd178c;
        uVar10 = 0;
        local_130[2] = (float)((double)CONCAT44(0x43300000,uVar9 ^ 0x80000000) - DOUBLE_97c30a58);
        if (local_130[7] == TAllocation__guardBlockSize) goto LAB_97bd17d0;
        if (local_130[0xb] == TAllocation__guardBlockSize) goto LAB_97bd17ec;
LAB_97bd17f0:
        uStack_ac = uVar10 ^ 0x80000000;
        local_b0 = 0x43300000;
        local_130[3] = (float)((double)CONCAT44(0x43300000,uVar10 ^ 0x80000000) - DOUBLE_97c30a58);
        break;
      case 0x27:
        uVar9 = (uint)*(byte *)((int)piVar15 + 5);
        local_130[0] = TAllocation__guardBlockSize;
        local_130[1] = TAllocation__guardBlockSize;
        local_130[2] = TAllocation__guardBlockSize;
        local_130[3] = TAllocation__guardBlockSize;
        if (uVar9 != 0) {
          pfVar12 = local_130;
          do {
            pfVar1 = pfVar12 + 4;
            pfVar2 = pfVar12 + 8;
            pfVar12 = pfVar12 + 1;
            local_130[0] = *pfVar1 * *pfVar2 + local_130[0];
            uVar9 = uVar9 - 1;
            local_130[1] = local_130[0];
            local_130[2] = local_130[0];
            local_130[3] = local_130[0];
          } while (uVar9 != 0);
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
        if (*(int *)(*(int *)(iVar22 + 0xd80) + 0x38) - 0x8b30U < 2) {
          uVar9 = (uint)*(byte *)((int)piVar15 + 5);
          dVar28 = (double)TAllocation__guardBlockSize;
          if (uVar9 != 0) {
            pfVar12 = local_130;
            do {
              pfVar1 = pfVar12 + 4;
              pfVar2 = pfVar12 + 8;
              pfVar12 = pfVar12 + 1;
              dVar28 = (double)(float)((double)(*pfVar1 - *pfVar2) * (double)(*pfVar1 - *pfVar2) +
                                      dVar28);
              uVar9 = uVar9 - 1;
            } while (uVar9 != 0);
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
          local_130[3] = fVar8;
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
        local_130[0] = local_130[5] * local_130[10] - local_130[9] * local_130[6];
        local_130[2] = local_130[4] * local_130[9] - local_130[8] * local_130[5];
        local_130[1] = local_130[6] * local_130[8] - local_130[10] * local_130[4];
        goto LAB_97bd1ce0;
      case 0x2f:
        uVar9 = (uint)*(byte *)((int)piVar15 + 5);
        if (uVar9 != 0) {
          pfVar12 = local_130;
          do {
            pfVar1 = pfVar12 + 4;
            pfVar2 = pfVar12 + 8;
            pfVar12 = pfVar12 + 1;
            fVar4 = *pfVar1 * *pfVar2 + fVar4;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        fVar4 = fVar4 + fVar4;
        local_130[0] = -(fVar4 * local_130[8] - local_130[4]);
        local_130[1] = -(fVar4 * local_130[9] - local_130[5]);
        local_130[2] = -(fVar4 * local_130[10] - local_130[6]);
        local_130[3] = -(fVar4 * local_130[0xb] - local_130[7]);
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
        bVar3 = local_130[0xb] <= local_130[7];
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
        bVar3 = local_130[7] <= local_130[0xb];
LAB_97bd1c60:
        local_130[3] = 1.0;
        if (!bVar3) {
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
        if (1 < *(int *)(*(int *)(iVar22 + 0xd80) + 0x38) - 0x8b30U) {
          dVar28 = (double)_pow((double)local_130[7],(double)local_130[0xb]);
          goto LAB_97bd1d68;
        }
        dVar28 = (double)_pow((double)local_130[4],(double)local_130[8]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_pow((double)local_130[5],(double)local_130[9]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_pow((double)local_130[6],(double)local_130[10]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_pow((double)local_130[7],(double)local_130[0xb]);
        goto LAB_97bd2010;
      case 0x39:
        dVar28 = (double)local_130[8];
        if (DOUBLE_97c30a78 <= dVar28) {
          iVar18 = (int)(dVar28 - DOUBLE_97c30a78);
          local_a0 = (longlong)iVar18;
        }
        else {
          iVar18 = (int)local_130[8];
          local_a8 = (longlong)iVar18;
        }
        local_130[0] = local_130[iVar18 + 4];
        if (DOUBLE_97c30a78 <= dVar28) {
          iVar18 = (int)(dVar28 - DOUBLE_97c30a78);
          local_a8 = (longlong)iVar18;
        }
        else {
          iVar18 = (int)local_130[8];
          local_a0 = (longlong)iVar18;
        }
        local_130[1] = local_130[iVar18 + 4];
        if (DOUBLE_97c30a78 <= dVar28) {
          iVar18 = (int)(dVar28 - DOUBLE_97c30a78);
          local_a8 = (longlong)iVar18;
        }
        else {
          iVar18 = (int)local_130[8];
          local_a0 = (longlong)iVar18;
        }
        local_130[2] = local_130[iVar18 + 4];
        if (DOUBLE_97c30a78 <= dVar28) {
          iVar18 = (int)(dVar28 - DOUBLE_97c30a78);
          local_a8 = (longlong)iVar18;
        }
        else {
          iVar18 = (int)local_130[8];
          local_a0 = (longlong)iVar18;
        }
        local_130[3] = local_130[iVar18 + 4];
        break;
      case 0x3a:
        if (piVar15[9] == 1) {
          local_130[0] = local_130[4] / local_130[8];
          local_130[1] = local_130[5] / local_130[9];
          local_130[2] = local_130[6] / local_130[10];
          local_130[3] = local_130[7] / local_130[0xb];
        }
        else if (piVar15[9] == 3) {
          dVar28 = (double)_trunc((double)(local_130[4] / local_130[8]));
          local_130[0] = (float)dVar28;
          dVar28 = (double)_trunc((double)(local_130[5] / local_130[9]));
          local_130[1] = (float)dVar28;
          dVar28 = (double)_trunc((double)(local_130[6] / local_130[10]));
          fVar4 = local_130[7] / local_130[0xb];
          goto LAB_97bd200c;
        }
        break;
      case 0x3b:
        uVar9 = (uint)*(byte *)((int)piVar15 + 5);
        if (uVar9 != 0) {
          pfVar12 = local_130;
          do {
            pfVar1 = pfVar12 + 0xc;
            pfVar2 = pfVar12 + 8;
            pfVar12 = pfVar12 + 1;
            fVar4 = *pfVar1 * *pfVar2 + fVar4;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        if (fVar4 < TAllocation__guardBlockSize) goto switchD_97bd0598_caseD_0;
        local_130[0] = -local_130[4];
        local_130[1] = -local_130[5];
        local_130[2] = -local_130[6];
        local_130[3] = -local_130[7];
        break;
      case 0x3c:
        local_130[0] = local_130[4] * local_130[8] + (FLOAT_97c3acd8 - local_130[4]) * local_100[0];
        local_130[1] = local_130[5] * local_130[9] + (FLOAT_97c3acd8 - local_130[5]) * local_100[1];
        local_130[2] = local_130[6] * local_130[10] + (FLOAT_97c3acd8 - local_130[6]) * local_100[2]
        ;
        local_130[3] = local_130[7] * local_130[0xb] +
                       (FLOAT_97c3acd8 - local_130[7]) * local_100[3];
        break;
      case 0x3d:
        fVar4 = local_130[8];
        if (local_130[8] < local_130[4]) {
          fVar4 = local_130[4];
        }
        local_130[0] = local_100[0];
        if ((fVar4 < local_100[0]) && (local_130[0] = local_130[8], local_130[8] < local_130[4])) {
          local_130[0] = local_130[4];
        }
        fVar4 = local_130[9];
        if (local_130[9] < local_130[5]) {
          fVar4 = local_130[5];
        }
        local_130[1] = local_100[1];
        if ((fVar4 < local_100[1]) && (local_130[1] = local_130[9], local_130[9] < local_130[5])) {
          local_130[1] = local_130[5];
        }
        fVar4 = local_130[10];
        if (local_130[10] < local_130[6]) {
          fVar4 = local_130[6];
        }
        local_130[2] = local_100[2];
        if ((fVar4 < local_100[2]) && (local_130[2] = local_130[10], local_130[10] < local_130[6]))
        {
          local_130[2] = local_130[6];
        }
        fVar4 = local_130[0xb];
        if (local_130[0xb] < local_130[7]) {
          fVar4 = local_130[7];
        }
        local_130[3] = local_100[3];
        if ((fVar4 < local_100[3]) &&
           (fVar8 = local_130[0xb], local_130[3] = local_130[7], local_130[7] <= local_130[0xb]))
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
        dVar28 = (double)((local_100[0] - local_130[4]) / (local_130[8] - local_130[4]));
        if ((dVar28 <= DOUBLE_97c30a48) || (dVar28 < DOUBLE_97c30a60)) {
          if (dVar28 <= DOUBLE_97c30a48) {
            dVar28 = (double)TAllocation__guardBlockSize;
          }
        }
        else {
          dVar28 = (double)FLOAT_97c3acd8;
        }
        dVar29 = (double)((local_100[1] - local_130[5]) / (local_130[9] - local_130[5]));
        local_130[0] = (float)((double)(float)(dVar28 * dVar28) *
                              (DOUBLE_97c30a80 - (dVar28 + dVar28)));
        if ((dVar29 <= DOUBLE_97c30a48) || (dVar29 < DOUBLE_97c30a60)) {
          if (dVar29 <= DOUBLE_97c30a48) {
            dVar29 = (double)TAllocation__guardBlockSize;
          }
        }
        else {
          dVar29 = (double)FLOAT_97c3acd8;
        }
        dVar28 = (double)((local_100[2] - local_130[6]) / (local_130[10] - local_130[6]));
        local_130[1] = (float)((double)(float)(dVar29 * dVar29) *
                              (DOUBLE_97c30a80 - (dVar29 + dVar29)));
        if ((dVar28 <= DOUBLE_97c30a48) || (dVar28 < DOUBLE_97c30a60)) {
          if (dVar28 <= DOUBLE_97c30a48) {
            dVar28 = (double)TAllocation__guardBlockSize;
          }
        }
        else {
          dVar28 = (double)FLOAT_97c3acd8;
        }
        dVar29 = (double)((local_100[3] - local_130[7]) / (local_130[0xb] - local_130[7]));
        local_130[2] = (float)((double)(float)(dVar28 * dVar28) *
                              (DOUBLE_97c30a80 - (dVar28 + dVar28)));
        if ((dVar29 <= DOUBLE_97c30a48) || (dVar29 < DOUBLE_97c30a60)) {
          if (dVar29 <= DOUBLE_97c30a48) {
            dVar29 = (double)TAllocation__guardBlockSize;
          }
        }
        else {
          dVar29 = (double)FLOAT_97c3acd8;
        }
        local_130[3] = (float)((double)(float)(dVar29 * dVar29) *
                              (DOUBLE_97c30a80 - (dVar29 + dVar29)));
        break;
      case 0x41:
        cVar7 = *(char *)(piVar15 + 0x18);
        local_130[0] = local_130[4];
        if ((((cVar7 != '\0') && (local_130[0] = local_130[5], cVar7 != '\x01')) &&
            (local_130[0] = local_130[6], cVar7 != '\x02')) &&
           (local_130[0] = local_130[7], cVar7 != '\x03')) {
          fVar4 = local_130[4];
          if (((cVar7 == '\x04') || (fVar4 = local_130[5], cVar7 == '\x05')) ||
             ((fVar4 = local_130[6], cVar7 == '\x06' || (fVar4 = local_130[7], cVar7 == '\a')))) {
            local_130[0] = -fVar4;
          }
          else {
            local_130[0] = TAllocation__guardBlockSize;
            if (((cVar7 != '\t') && (local_130[0] = FLOAT_97c3acd8, cVar7 != '\b')) &&
               (local_130[0] = FLOAT_97c3acec, cVar7 != '\n')) {
              local_130[0] = TAllocation__guardBlockSize;
            }
          }
        }
        cVar7 = *(char *)((int)piVar15 + 0x61);
        local_130[1] = local_130[4];
        if ((((cVar7 != '\0') && (local_130[1] = local_130[5], cVar7 != '\x01')) &&
            (local_130[1] = local_130[6], cVar7 != '\x02')) &&
           (local_130[1] = local_130[7], cVar7 != '\x03')) {
          fVar4 = local_130[4];
          if (((cVar7 == '\x04') || (fVar4 = local_130[5], cVar7 == '\x05')) ||
             ((fVar4 = local_130[6], cVar7 == '\x06' || (fVar4 = local_130[7], cVar7 == '\a')))) {
            local_130[1] = -fVar4;
          }
          else {
            local_130[1] = TAllocation__guardBlockSize;
            if (((cVar7 != '\t') && (local_130[1] = FLOAT_97c3acd8, cVar7 != '\b')) &&
               (local_130[1] = FLOAT_97c3acec, cVar7 != '\n')) {
              local_130[1] = TAllocation__guardBlockSize;
            }
          }
        }
        cVar7 = *(char *)((int)piVar15 + 0x62);
        local_130[2] = local_130[4];
        if ((((cVar7 != '\0') && (local_130[2] = local_130[5], cVar7 != '\x01')) &&
            (local_130[2] = local_130[6], cVar7 != '\x02')) &&
           (local_130[2] = local_130[7], cVar7 != '\x03')) {
          fVar4 = local_130[4];
          if (((cVar7 == '\x04') || (fVar4 = local_130[5], cVar7 == '\x05')) ||
             ((fVar4 = local_130[6], cVar7 == '\x06' || (fVar4 = local_130[7], cVar7 == '\a')))) {
            local_130[2] = -fVar4;
          }
          else {
            local_130[2] = TAllocation__guardBlockSize;
            if (((cVar7 != '\t') && (local_130[2] = FLOAT_97c3acd8, cVar7 != '\b')) &&
               (local_130[2] = FLOAT_97c3acec, cVar7 != '\n')) {
              local_130[2] = TAllocation__guardBlockSize;
            }
          }
        }
        cVar7 = *(char *)((int)piVar15 + 99);
        local_130[3] = local_130[4];
        if ((((cVar7 != '\0') && (local_130[3] = local_130[5], cVar7 != '\x01')) &&
            (local_130[3] = local_130[6], cVar7 != '\x02')) &&
           (local_130[3] = local_130[7], cVar7 != '\x03')) {
          fVar4 = local_130[4];
          if (((cVar7 == '\x04') || (fVar4 = local_130[5], cVar7 == '\x05')) ||
             ((fVar4 = local_130[6], cVar7 == '\x06' || (fVar4 = local_130[7], cVar7 == '\a')))) {
            local_130[3] = -fVar4;
          }
          else {
            local_130[3] = TAllocation__guardBlockSize;
            if (((cVar7 != '\t') && (local_130[3] = FLOAT_97c3acd8, cVar7 != '\b')) &&
               (local_130[3] = FLOAT_97c3acec, cVar7 != '\n')) {
              local_130[3] = TAllocation__guardBlockSize;
            }
          }
        }
        break;
      case 0x42:
      case 0x43:
      case 0x44:
      case 0x45:
        ((int (*)())_InterpreterTextureSamplerAttachGLDContext)(piVar14[0x28b],*(undefined4 *)(iVar22 + 0xd9c));
        uVar16 = 0;
        if ((iVar24 == 0x43) || (iVar24 == 0x45)) {
          uVar16 = 1;
        }
        ((int (*)())_InterpreterTextureSamplerSetProjectionEnabled)(piVar14[0x28b],uVar16);
        ((int (*)())_InterpreterTextureSamplerSetLodBiasEnabled)(piVar14[0x28b],iVar24 == 0x44 || iVar24 - 0x44U == 1);
        ((void (*)())_InterpreterTextureSamplerAttachDerivatives)((double)(float)piVar14[0x28f],piVar14[0x28b],*(undefined4 *)(iVar22 + 0xda4));
        fVar8 = local_130[7];
        if (iVar24 - 0x44U < 2) {
          iVar18 = *(int *)(iVar22 + 0xd80);
          fVar4 = local_100[0];
          if (1 < *(int *)(iVar18 + 0x38) - 0x8b30U) {
            local_130[7] = 1.0;
            fVar4 = fVar8;
            goto LAB_97bd29a8;
          }
        }
        else {
LAB_97bd29a8:
          iVar18 = *(int *)(iVar22 + 0xd80);
        }
        dVar28 = (double)fVar4;
        if (*(int *)(iVar18 + 0x38) - 0x8b30U < 2) {
          if (DOUBLE_97c30a78 <= (double)local_130[8]) {
            uVar9 = (uint)((double)local_130[8] - DOUBLE_97c30a78);
            local_98 = (longlong)(int)uVar9;
            uVar9 = uVar9 ^ 0x80000000;
          }
          else {
            uVar9 = (uint)local_130[8];
            local_90 = (longlong)(int)uVar9;
          }
        }
        else {
          uVar9 = piVar15[0x43];
        }
        uVar10 = piVar15[0x44];
        if (uVar10 == 2) {
          _InterpreterTextureSamplerSampleTexelRECT(dVar28,piVar14[0x28b],uVar9);
        }
        else if (uVar10 < 3) {
          if (uVar10 == 1) {
            ((void (*)())_InterpreterTextureSamplerSampleTexel3D)(dVar28,piVar14[0x28b]);
          }
        }
        else if (uVar10 == 3) {
          ((void (*)())_InterpreterTextureSamplerSampleTexel2D)(dVar28,piVar14[0x28b]);
        }
        else if (uVar10 == 4) {
          ((void (*)())_InterpreterTextureSamplerSampleTexel1D)(dVar28,piVar14[0x28b]);
        }
        local_130[0] = local_80;
        local_130[1] = local_7c;
        local_130[2] = local_78;
        local_130[3] = local_74;
        break;
      case 0x48:
      case 0x49:
        dVar28 = (double)_floor((double)local_130[4]);
        if (DOUBLE_97c30a78 <= dVar28) {
          local_98 = (longlong)(int)(dVar28 - DOUBLE_97c30a78);
          uVar9 = (int)(dVar28 - DOUBLE_97c30a78) ^ 0x80000000;
        }
        else {
          uVar9 = (uint)dVar28;
          local_90 = (longlong)(int)uVar9;
        }
        piVar14[0x290] = uVar9;
        goto switchD_97bd0598_caseD_6;
      case 0x4b:
        iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],
                                    piVar15[8],piVar15[9]);
        if (((iVar18 != 0) ||
            (iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],
                                         piVar15[7],piVar15[8],piVar15[9]), iVar18 != 0)) ||
           ((iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],
                                         piVar15[7],piVar15[8],piVar15[9]), iVar18 != 0 ||
            (iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],
                                         piVar15[7],piVar15[8],piVar15[9]), iVar18 != 0))))
        goto switchD_97bd0598_caseD_54;
        goto switchD_97bd0598_caseD_6;
      case 0x4c:
        iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],
                                    piVar15[8],piVar15[9]);
        if ((((iVar18 == 0) &&
             (iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],
                                          piVar15[7],piVar15[8],piVar15[9]), iVar18 == 0)) &&
            (iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],
                                         piVar15[7],piVar15[8],piVar15[9]), iVar18 == 0)) &&
           (iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],
                                        piVar15[7],piVar15[8],piVar15[9]), iVar18 == 0))
        goto switchD_97bd0598_caseD_6;
        if ((uint *)piVar14[0x29b] + 1 <= piVar14 + 0x29b) {
          *(uint *)piVar14[0x29b] = (uint)piVar21;
          piVar14[0x29b] = piVar14[0x29b] + 4;
          goto switchD_97bd0598_caseD_54;
        }
        break;
      case 0x4d:
        iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],
                                    piVar15[8],piVar15[9]);
        if (((iVar18 != 0) ||
            (iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],
                                         piVar15[7],piVar15[8],piVar15[9]), iVar18 != 0)) ||
           ((iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],
                                         piVar15[7],piVar15[8],piVar15[9]), iVar18 != 0 ||
            (iVar18 = ((int (*)())_InterpreterTestCR)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],
                                         piVar15[7],piVar15[8],piVar15[9]), iVar18 != 0)))) {
          iVar18 = piVar14[0x29b];
          piVar21 = (int *)0x0;
          piVar13 = (int *)(iVar18 - 4);
          if (piVar14 + 0x297 <= piVar13) {
            piVar14[0x29b] = (int)piVar13;
            piVar21 = *(int **)(iVar18 + -4);
          }
        }
        goto switchD_97bd0598_caseD_6;
      case 0x4f:
        if ((((double)local_130[4] < DOUBLE_97c30a48) || ((double)local_130[5] < DOUBLE_97c30a48))
           || (((double)local_130[6] < DOUBLE_97c30a48 || ((double)local_130[7] < DOUBLE_97c30a48)))
           ) {
          piVar14[0x296] = 1;
        }
        goto switchD_97bd0598_caseD_6;
      case 0x54:
      case 0x58:
      case 0x6b:
switchD_97bd0598_caseD_54:
        piVar21 = (int *)((**(int **)(iVar22 + 0xd80) + piVar15[2] * 0x11c) - 0x11c);
        if ((int *)(*(int **)(iVar22 + 0xd80))[1] < piVar21) {
          piVar21 = (int *)0x0;
        }
switchD_97bd0598_caseD_6:
        bVar26 = false;
        break;
      case 0x55:
        if ((((local_130[4] == TAllocation__guardBlockSize) &&
             (local_130[5] == TAllocation__guardBlockSize)) &&
            (local_130[6] == TAllocation__guardBlockSize)) &&
           (local_130[7] == TAllocation__guardBlockSize)) goto switchD_97bd0598_caseD_54;
        break;
      case 0x68:
        uVar9 = (uint)*(byte *)((int)piVar15 + 5);
        if (uVar9 != 0) {
          pfVar12 = local_130;
          do {
            pfVar1 = pfVar12 + 4;
            pfVar2 = pfVar12 + 8;
            pfVar12 = pfVar12 + 1;
            fVar4 = *pfVar1 * *pfVar2 + fVar4;
            uVar9 = uVar9 - 1;
          } while (uVar9 != 0);
        }
        dVar28 = (double)(float)-((double)(local_100[0] * local_100[0]) *
                                  (DOUBLE_97c30a60 - (double)(fVar4 * fVar4)) - DOUBLE_97c30a60);
        if ((double)TAllocation__guardBlockSize <= dVar28) {
          fVar4 = local_100[0] * fVar4;
          dVar28 = (double)_sqrt(dVar28);
          fVar4 = (float)((double)fVar4 + dVar28);
          local_130[0] = local_100[0] * local_130[4] - fVar4 * local_130[8];
          local_130[1] = local_100[0] * local_130[5] - fVar4 * local_130[9];
          local_130[2] = local_100[0] * local_130[6] - fVar4 * local_130[10];
          local_130[3] = local_100[0] * local_130[7] - fVar4 * local_130[0xb];
        }
        else {
          local_130[3] = TAllocation__guardBlockSize;
          local_130[0] = TAllocation__guardBlockSize;
          local_130[1] = TAllocation__guardBlockSize;
          local_130[2] = TAllocation__guardBlockSize;
        }
        break;
      case 0x6c:
        if ((piVar15[9] == 3) && (piVar15[0x13] == 1)) {
          dVar28 = (double)_trunc((double)local_130[4]);
          local_130[0] = (float)dVar28;
          dVar28 = (double)_trunc((double)local_130[5]);
          local_130[1] = (float)dVar28;
          dVar28 = (double)_trunc((double)local_130[6]);
          fVar4 = local_130[7];
LAB_97bd200c:
          local_130[2] = (float)dVar28;
          dVar28 = (double)_trunc((double)fVar4);
          goto LAB_97bd2010;
        }
        if ((piVar15[9] != 4) || ((piVar15[0x13] != 1 && (piVar15[0x13] != 3))))
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
        dVar28 = (double)local_130[8];
        local_130[0] = local_100[0];
        local_130[1] = local_100[1];
        local_130[2] = local_100[2];
        local_130[3] = local_100[3];
        if (DOUBLE_97c30a78 <= dVar28) {
          iVar18 = (int)(dVar28 - DOUBLE_97c30a78);
          local_a8 = (longlong)iVar18;
        }
        else {
          iVar18 = (int)local_130[8];
          local_a0 = (longlong)iVar18;
        }
        if (DOUBLE_97c30a78 <= dVar28) {
          iVar27 = (int)(dVar28 - DOUBLE_97c30a78);
          local_90 = (longlong)iVar27;
        }
        else {
          iVar27 = (int)local_130[8];
          local_98 = (longlong)iVar27;
        }
        local_130[iVar18] = local_130[iVar27 + 4];
        break;
      case 0x6f:
        dVar28 = (double)_exp((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_exp((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_exp((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_exp((double)local_130[7]);
        goto LAB_97bd2010;
      case 0x70:
        dVar28 = (double)_log((double)local_130[4]);
        local_130[0] = (float)dVar28;
        dVar28 = (double)_log((double)local_130[5]);
        local_130[1] = (float)dVar28;
        dVar28 = (double)_log((double)local_130[6]);
        local_130[2] = (float)dVar28;
        dVar28 = (double)_log((double)local_130[7]);
LAB_97bd2010:
        dVar28 = (double)(float)dVar28;
LAB_97bd2014:
        local_130[3] = (float)dVar28;
      }
      if (cVar5 != '\0') {
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
      if (bVar26) {
        ((int (*)())_InterpreterWriteDestination)(piVar14,piVar15[3],piVar15[4],piVar15[5],piVar15[6],piVar15[7],piVar15[8],
                   piVar15[9]);
      }
      uVar25 = uVar25 + 1;
      if (uVar23 <= uVar25) {
        return piVar21;
      }
      iVar18 = piVar15[0xc];
    } while( true );
  }
  if (uVar23 < 2) {
    ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
               piVar15[0x12],piVar15[0x13]);
    ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
               piVar15[0x1b],piVar15[0x1c]);
    if (*(char *)((int)piVar15 + 0x21) == '\x01') {
      cVar5 = *(char *)((int)piVar15 + 5);
      if (cVar5 == '\x01') {
LAB_97bd0310:
        local_130[0] = 1.0;
        if (local_130[5] == local_130[9]) goto LAB_97bd0328;
      }
      else if (cVar5 == '\x02') {
        if (local_130[4] == local_130[8]) goto LAB_97bd0310;
      }
      else if (cVar5 == '\x03') {
        if ((local_130[4] == local_130[8]) &&
           (bVar26 = local_130[5] == local_130[9], local_130[5] = local_130[6],
           local_130[9] = local_130[10], bVar26)) goto LAB_97bd0310;
      }
      else {
        if (cVar5 != '\x04') goto LAB_97bd0328;
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
    if (uVar23 == 3) {
      pfVar12 = local_130;
      uVar23 = 0;
      do {
        ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                   piVar15[0x12],piVar15[0x13]);
        ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                   piVar15[0x1b],piVar15[0x1c]);
        if (((local_130[4] != local_130[8]) || (local_130[5] != local_130[9])) ||
           (fVar4 = FLOAT_97c3acd8, local_130[6] != local_130[10])) {
          fVar4 = TAllocation__guardBlockSize;
        }
        uVar23 = uVar23 + 1;
        *pfVar12 = fVar4;
        pfVar12 = pfVar12 + 1;
      } while (uVar23 < 3);
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
    else if (uVar23 < 4) {
      if (uVar23 == 2) {
        pfVar12 = local_130;
        uVar23 = 0;
        do {
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                     piVar15[0x12],piVar15[0x13]);
          ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                     piVar15[0x1b],piVar15[0x1c]);
          if ((local_130[4] != local_130[8]) ||
             (fVar4 = FLOAT_97c3acd8, local_130[5] != local_130[9])) {
            fVar4 = TAllocation__guardBlockSize;
          }
          uVar23 = uVar23 + 1;
          *pfVar12 = fVar4;
          pfVar12 = pfVar12 + 1;
        } while (uVar23 < 2);
        uStack_ac = 0;
        local_130[2] = local_130[1];
        if (local_130[0] != TAllocation__guardBlockSize) goto LAB_97bd0194;
        goto LAB_97bd01a0;
      }
    }
    else if (uVar23 == 4) {
      pfVar12 = local_130;
      uVar23 = 0;
      do {
        ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0xd],piVar15[0xe],piVar15[0xf],piVar15[0x10],piVar15[0x11],
                   piVar15[0x12],piVar15[0x13]);
        ((int (*)())_InterpreterLoadSource)(piVar14,piVar15[0x16],piVar15[0x17],piVar15[0x18],piVar15[0x19],piVar15[0x1a],
                   piVar15[0x1b],piVar15[0x1c]);
        if ((((local_130[4] != local_130[8]) || (local_130[5] != local_130[9])) ||
            (local_130[6] != local_130[10])) ||
           (fVar4 = FLOAT_97c3acd8, local_130[7] != local_130[0xb])) {
          fVar4 = TAllocation__guardBlockSize;
        }
        uVar23 = uVar23 + 1;
        *pfVar12 = fVar4;
        pfVar12 = pfVar12 + 1;
      } while (uVar23 < 4);
      uStack_ac = 0;
      if (((local_130[0] != TAllocation__guardBlockSize) &&
          (local_130[1] != TAllocation__guardBlockSize)) &&
         (bVar26 = local_130[2] != TAllocation__guardBlockSize, local_130[2] = local_130[3], bVar26)
         ) goto LAB_97bd0194;
      goto LAB_97bd01a0;
    }
LAB_97bd0328:
    local_130[3] = local_130[0];
    local_130[1] = local_130[0];
    local_130[2] = local_130[0];
  }
  if (iVar24 == 0x36) {
    local_130[0] = (float)(DOUBLE_97c30a60 - (double)local_130[0]);
    local_130[1] = (float)(DOUBLE_97c30a60 - (double)local_130[1]);
    local_130[2] = (float)(DOUBLE_97c30a60 - (double)local_130[2]);
    local_130[3] = (float)(DOUBLE_97c30a60 - (double)local_130[3]);
  }
  iVar20 = piVar15[9];
  iVar22 = piVar15[3];
  iVar18 = piVar15[4];
  iVar24 = piVar15[5];
  iVar27 = piVar15[6];
  iVar17 = piVar15[7];
  iVar19 = piVar15[8];
LAB_97bd043c:
  ((int (*)())_InterpreterWriteDestination)(piVar14,iVar22,iVar18,iVar24,iVar27,iVar17,iVar19,iVar20);
  return piVar21;
}

/* _InterpreterWriteFinalFragmentToBuffer @ 0x97bd3068 (376 bytes) */
int _InterpreterWriteFinalFragmentToBuffer(param_1)
  int *param_1;
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
int _InterpreterRun()
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
  int iVar17;
  uint uVar18;
  int iVar19;
  uint uVar20;
  uint uVar21;
  int iVar22;
  int iVar23;
  double dVar24;
  double dVar25;
  double dVar26;
  double dVar27;
  double dVar28;
  undefined8 uVar29;
  
  uVar29 = FUN_97c1a23c();
  dVar13 = DOUBLE_97c30a60;
  iVar17 = (int)((ulonglong)uVar29 >> 0x20);
  iVar22 = (int)uVar29;
  iVar19 = *(int *)(*(int *)(iVar17 + 0xd80) + 0x38);
  iVar23 = *(int *)(iVar17 + 0xdf0);
  iVar15 = *(int *)(iVar17 + 0xd9c);
  uVar21 = 0xff;
  uVar20 = 0;
  if ((iVar19 == 0x8804) || (iVar19 == 0x8b30)) {
    dVar28 = (double)*(float *)(*(int *)(iVar17 + 0xda0) + 0xc);
    dVar26 = (double)*(float *)(*(int *)(iVar17 + 0xda0) + 8);
    dVar27 = (double)*(float *)(*(int *)(iVar17 + 0xda4) + 0xc);
    dVar25 = (double)*(float *)(*(int *)(iVar17 + 0xda4) + 8);
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
  iVar15 = *(int *)(*(int *)(iVar17 + 0xd80) + 0x38);
  if ((iVar15 == 0x8804) || (iVar15 == 0x8b30)) {
    *(undefined4 *)(iVar23 + 0xa30) = 0;
    *(float *)(iVar23 + 0xa38) = (float)dVar26;
    *(float *)(iVar23 + 0xa3c) = (float)(dVar13 / dVar28);
  }
  *(undefined1 *)(iVar23 + 0xa47) = 0;
  *(undefined4 *)(iVar23 + 0xa68) = 0;
  *(int *)(iVar23 + 0xa6c) = iVar23 + 0xa5c;
  *(undefined1 *)(iVar23 + 0xa44) = 0;
  *(undefined1 *)(iVar23 + 0xa45) = 0;
  *(undefined1 *)(iVar23 + 0xa46) = 0;
  *(undefined4 *)(iVar23 + 0xa5c) = 0;
  *(undefined4 *)(iVar23 + 0xa60) = 0;
  *(undefined4 *)(iVar23 + 0xa64) = 0;
  fVar14 = TAllocation__guardBlockSize;
  dVar13 = DOUBLE_97c30a60;
  do {
    if (iVar22 == 0) {
      iVar22 = *(int *)(*(int *)(iVar17 + 0xd80) + 0x38);
      if ((iVar22 == 0x8804) || (iVar22 == 0x8b30)) {
        uVar20 = 0;
      }
      else {
        uVar20 = uVar21 << 8 | uVar20;
      }
      FUN_97c1a28c(uVar20);
      return;
    }
    iVar22 = iVar22 + -1;
    *(undefined4 *)(iVar23 + 0xa58) = 0;
    iVar15 = *(int *)(iVar17 + 0xd80);
    if (((*(uint *)(iVar15 + 0x3c) & 6) == 4) && ((*(uint *)(iVar15 + 0x34) & 0xa000) == 0)) {
      uVar18 = _InterpreterRasterOpMachine_DepthTest(iVar23 + 0xa24);
      *(uint *)(iVar23 + 0xa58) = *(uint *)(iVar23 + 0xa58) | uVar18;
      iVar15 = *(int *)(iVar17 + 0xd80);
    }
    iVar19 = *(int *)(iVar15 + 0x120);
    if ((iVar19 != 0) && (*(int *)(iVar23 + 0xa58) == 0)) {
      do {
        iVar19 = ((int (*)())_InterpreterEmulateOp)(iVar23,iVar19);
        if (iVar19 == 0) break;
      } while (*(int *)(iVar23 + 0xa58) == 0);
      iVar15 = *(int *)(iVar17 + 0xd80);
    }
    if ((*(int *)(iVar15 + 0x38) == 0x8804) || (*(int *)(iVar15 + 0x38) == 0x8b30)) {
      if (*(int *)(iVar23 + 0xa58) == 0) {
        ((int (*)())_InterpreterWriteFinalFragmentToBuffer)(iVar23);
        iVar15 = *(int *)(iVar17 + 0xd80);
      }
    }
    else {
      pfVar16 = *(float **)(iVar17 + 0xd88);
      uVar18 = 0;
      fVar2 = pfVar16[7];
      fVar3 = pfVar16[4];
      fVar12 = -fVar2;
      fVar4 = pfVar16[5];
      fVar5 = pfVar16[6];
      if (fVar3 < fVar12) {
        uVar18 = 0x10;
      }
      if (fVar2 <= fVar3) {
        uVar18 = uVar18 | 0x20;
      }
      if (fVar4 < fVar12) {
        uVar18 = uVar18 | 4;
      }
      if (fVar2 <= fVar4) {
        uVar18 = uVar18 | 8;
      }
      if (fVar5 < fVar12) {
        uVar18 = uVar18 | 1;
      }
      if (fVar2 < fVar5) {
        uVar18 = uVar18 | 2;
      }
      pfVar16[0x1f] = (float)(uVar18 | 0x1000000);
      if (uVar18 == 0) {
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
      iVar15 = *(int *)(iVar17 + 0xd80);
      uVar21 = uVar21 & uVar18;
      uVar20 = uVar20 | uVar18;
    }
    *(int *)(iVar17 + 0xd8c) = *(int *)(iVar17 + 0xd8c) + *(int *)(iVar15 + 0xbc);
    *(int *)(iVar17 + 0xd88) = *(int *)(iVar17 + 0xd88) + *(int *)(iVar15 + 0xb8);
    *(int *)(iVar17 + 0xda8) = *(int *)(iVar17 + 0xda8) + *(int *)(iVar15 + 0xd8);
    *(int *)(iVar17 + 0xdac) = *(int *)(iVar17 + 0xdac) + *(int *)(iVar15 + 0xdc);
    if ((*(int *)(iVar15 + 0x38) == 0x8804) || (*(int *)(iVar15 + 0x38) == 0x8b30)) {
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
  _calloc(0x2c,1);
  return;
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

